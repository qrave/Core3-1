/*
 *	server/zone/objects/tangible/terminal/Terminal.cpp generated by engine3 IDL compiler 0.60
 */

#include "Terminal.h"

/*
 *	TerminalStub
 */

Terminal::Terminal(LuaObject* templateData) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new TerminalImplementation(templateData);
	_impl->_setStub(this);
}

Terminal::Terminal(DummyConstructorParameter* param) : TangibleObject(param) {
}

Terminal::~Terminal() {
}

void Terminal::initializeTransientMembers() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((TerminalImplementation*) _impl)->initializeTransientMembers();
}

/*
 *	TerminalImplementation
 */

TerminalImplementation::TerminalImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}

TerminalImplementation::~TerminalImplementation() {
}

void TerminalImplementation::_initializeImplementation() {
	_setClassHelper(TerminalHelper::instance());

	_serializationHelperMethod();
}

void TerminalImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (Terminal*) stub;
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* TerminalImplementation::_getStub() {
	return _this;
}

TerminalImplementation::operator const Terminal*() {
	return _this;
}

void TerminalImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void TerminalImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void TerminalImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void TerminalImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void TerminalImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void TerminalImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void TerminalImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void TerminalImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("Terminal");

}

TerminalImplementation::TerminalImplementation(LuaObject* templateData) : TangibleObjectImplementation(templateData) {
	_initializeImplementation();
	// server/zone/objects/tangible/terminal/Terminal.idl(55):  Logger.setLoggingName("Terminal");
	Logger::setLoggingName("Terminal");
}

/*
 *	TerminalAdapter
 */

TerminalAdapter::TerminalAdapter(TerminalImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* TerminalAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	default:
		return NULL;
	}

	return resp;
}

void TerminalAdapter::initializeTransientMembers() {
	((TerminalImplementation*) impl)->initializeTransientMembers();
}

/*
 *	TerminalHelper
 */

TerminalHelper* TerminalHelper::staticInitializer = TerminalHelper::instance();

TerminalHelper::TerminalHelper() {
	className = "Terminal";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void TerminalHelper::finalizeHelper() {
	TerminalHelper::finalize();
}

DistributedObject* TerminalHelper::instantiateObject() {
	return new Terminal(DummyConstructorParameter::instance());
}

DistributedObjectServant* TerminalHelper::instantiateServant() {
	return new TerminalImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* TerminalHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new TerminalAdapter((TerminalImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

