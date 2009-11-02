/*
 *	server/zone/managers/objectcontroller/ObjectController.cpp generated by engine3 IDL compiler 0.60
 */

#include "ObjectController.h"

#include "server/zone/managers/objectcontroller/command/CommandList.h"

#include "server/zone/managers/objectcontroller/command/CommandConfigManager.h"

#include "server/zone/objects/creature/commands/QueueCommand.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/ZoneProcessServerImplementation.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/creature/CreatureObject.h"

/*
 *	ObjectControllerStub
 */

ObjectController::ObjectController(ZoneProcessServerImplementation* server) : ManagedObject(DummyConstructorParameter::instance()) {
	_impl = new ObjectControllerImplementation(server);
	_impl->_setStub(this);
}

ObjectController::ObjectController(DummyConstructorParameter* param) : ManagedObject(param) {
}

ObjectController::~ObjectController() {
}

bool ObjectController::transferObject(SceneObject* objectToTransfer, SceneObject* destinationObject, int containmentType, bool notifyClient) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(objectToTransfer);
		method.addObjectParameter(destinationObject);
		method.addSignedIntParameter(containmentType);
		method.addBooleanParameter(notifyClient);

		return method.executeWithBooleanReturn();
	} else
		return ((ObjectControllerImplementation*) _impl)->transferObject(objectToTransfer, destinationObject, containmentType, notifyClient);
}

void ObjectController::enqueueCommand(CreatureObject* object, unsigned int actionCRC, unsigned int actionCount, unsigned long long targetID, UnicodeString& arguments) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(object);
		method.addUnsignedIntParameter(actionCRC);
		method.addUnsignedIntParameter(actionCount);
		method.addUnsignedLongParameter(targetID);
		method.addUnicodeParameter(arguments);

		method.executeWithVoidReturn();
	} else
		((ObjectControllerImplementation*) _impl)->enqueueCommand(object, actionCRC, actionCount, targetID, arguments);
}

void ObjectController::addQueueCommand(QueueCommand* command) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((ObjectControllerImplementation*) _impl)->addQueueCommand(command);
}

QueueCommand* ObjectController::getQueueCommand(const String& name) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((ObjectControllerImplementation*) _impl)->getQueueCommand(name);
}

QueueCommand* ObjectController::getQueueCommand(unsigned int crc) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((ObjectControllerImplementation*) _impl)->getQueueCommand(crc);
}

/*
 *	ObjectControllerImplementation
 */

ObjectControllerImplementation::ObjectControllerImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}

ObjectControllerImplementation::~ObjectControllerImplementation() {
}

void ObjectControllerImplementation::_initializeImplementation() {
	_setClassHelper(ObjectControllerHelper::instance());

	_serializationHelperMethod();
}

void ObjectControllerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ObjectController*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ObjectControllerImplementation::_getStub() {
	return _this;
}

ObjectControllerImplementation::operator const ObjectController*() {
	return _this;
}

void ObjectControllerImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void ObjectControllerImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void ObjectControllerImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void ObjectControllerImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void ObjectControllerImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void ObjectControllerImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void ObjectControllerImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void ObjectControllerImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("ObjectController");

}

/*
 *	ObjectControllerAdapter
 */

ObjectControllerAdapter::ObjectControllerAdapter(ObjectControllerImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* ObjectControllerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertBoolean(transferObject((SceneObject*) inv->getObjectParameter(), (SceneObject*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getBooleanParameter()));
		break;
	case 7:
		enqueueCommand((CreatureObject*) inv->getObjectParameter(), inv->getUnsignedIntParameter(), inv->getUnsignedIntParameter(), inv->getUnsignedLongParameter(), inv->getUnicodeParameter(_param4_enqueueCommand__CreatureObject_int_int_long_UnicodeString_));
		break;
	default:
		return NULL;
	}

	return resp;
}

bool ObjectControllerAdapter::transferObject(SceneObject* objectToTransfer, SceneObject* destinationObject, int containmentType, bool notifyClient) {
	return ((ObjectControllerImplementation*) impl)->transferObject(objectToTransfer, destinationObject, containmentType, notifyClient);
}

void ObjectControllerAdapter::enqueueCommand(CreatureObject* object, unsigned int actionCRC, unsigned int actionCount, unsigned long long targetID, UnicodeString& arguments) {
	((ObjectControllerImplementation*) impl)->enqueueCommand(object, actionCRC, actionCount, targetID, arguments);
}

/*
 *	ObjectControllerHelper
 */

ObjectControllerHelper* ObjectControllerHelper::staticInitializer = ObjectControllerHelper::instance();

ObjectControllerHelper::ObjectControllerHelper() {
	className = "ObjectController";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ObjectControllerHelper::finalizeHelper() {
	ObjectControllerHelper::finalize();
}

DistributedObject* ObjectControllerHelper::instantiateObject() {
	return new ObjectController(DummyConstructorParameter::instance());
}

DistributedObjectServant* ObjectControllerHelper::instantiateServant() {
	return new ObjectControllerImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ObjectControllerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ObjectControllerAdapter((ObjectControllerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

