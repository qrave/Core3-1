/*
 *	server/zone/objects/tangible/Instrument.cpp generated by engine3 IDL compiler 0.60
 */

#include "Instrument.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/objects/tangible/InstrumentObserver.h"

/*
 *	InstrumentStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6,RPC_NOTIFYLOADFROMDATABASE__,RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_,RPC_SPAWNINFOREIGNCELL__CREATUREOBJECT_,RPC_SPAWNINADMINCELL__CREATUREOBJECT_,RPC_SPAWNOUTSIDE__CREATUREOBJECT_,RPC_GETINSTRUMENTTYPE__,RPC_GETSPAWNERPLAYER__,RPC_SETSPAWNERPLAYER__CREATUREOBJECT_,RPC_ISBEINGUSED__,RPC_SETBEINGUSED__BOOL_};

Instrument::Instrument() : TangibleObject(DummyConstructorParameter::instance()) {
	InstrumentImplementation* _implementation = new InstrumentImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

Instrument::Instrument(DummyConstructorParameter* param) : TangibleObject(param) {
}

Instrument::~Instrument() {
}



void Instrument::initializeTransientMembers() {
	InstrumentImplementation* _implementation = static_cast<InstrumentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

void Instrument::notifyLoadFromDatabase() {
	InstrumentImplementation* _implementation = static_cast<InstrumentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYLOADFROMDATABASE__);

		method.executeWithVoidReturn();
	} else
		_implementation->notifyLoadFromDatabase();
}

void Instrument::loadTemplateData(SharedObjectTemplate* templateData) {
	InstrumentImplementation* _implementation = static_cast<InstrumentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->loadTemplateData(templateData);
}

void Instrument::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player) {
	InstrumentImplementation* _implementation = static_cast<InstrumentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillObjectMenuResponse(menuResponse, player);
}

int Instrument::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	InstrumentImplementation* _implementation = static_cast<InstrumentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->handleObjectMenuSelect(player, selectedID);
}

void Instrument::spawnInForeignCell(CreatureObject* spawner) {
	InstrumentImplementation* _implementation = static_cast<InstrumentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SPAWNINFOREIGNCELL__CREATUREOBJECT_);
		method.addObjectParameter(spawner);

		method.executeWithVoidReturn();
	} else
		_implementation->spawnInForeignCell(spawner);
}

void Instrument::spawnInAdminCell(CreatureObject* spawner) {
	InstrumentImplementation* _implementation = static_cast<InstrumentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SPAWNINADMINCELL__CREATUREOBJECT_);
		method.addObjectParameter(spawner);

		method.executeWithVoidReturn();
	} else
		_implementation->spawnInAdminCell(spawner);
}

void Instrument::spawnOutside(CreatureObject* spawner) {
	InstrumentImplementation* _implementation = static_cast<InstrumentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SPAWNOUTSIDE__CREATUREOBJECT_);
		method.addObjectParameter(spawner);

		method.executeWithVoidReturn();
	} else
		_implementation->spawnOutside(spawner);
}

int Instrument::getInstrumentType() {
	InstrumentImplementation* _implementation = static_cast<InstrumentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETINSTRUMENTTYPE__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getInstrumentType();
}

CreatureObject* Instrument::getSpawnerPlayer() {
	InstrumentImplementation* _implementation = static_cast<InstrumentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETSPAWNERPLAYER__);

		return static_cast<CreatureObject*>(method.executeWithObjectReturn());
	} else
		return _implementation->getSpawnerPlayer();
}

void Instrument::setSpawnerPlayer(CreatureObject* pla) {
	InstrumentImplementation* _implementation = static_cast<InstrumentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETSPAWNERPLAYER__CREATUREOBJECT_);
		method.addObjectParameter(pla);

		method.executeWithVoidReturn();
	} else
		_implementation->setSpawnerPlayer(pla);
}

bool Instrument::isBeingUsed() {
	InstrumentImplementation* _implementation = static_cast<InstrumentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISBEINGUSED__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isBeingUsed();
}

void Instrument::setBeingUsed(bool val) {
	InstrumentImplementation* _implementation = static_cast<InstrumentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETBEINGUSED__BOOL_);
		method.addBooleanParameter(val);

		method.executeWithVoidReturn();
	} else
		_implementation->setBeingUsed(val);
}

DistributedObjectServant* Instrument::_getImplementation() {

	_updated = true;
	return _impl;
}

void Instrument::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	InstrumentImplementation
 */

InstrumentImplementation::InstrumentImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}


InstrumentImplementation::~InstrumentImplementation() {
}


void InstrumentImplementation::finalize() {
}

void InstrumentImplementation::_initializeImplementation() {
	_setClassHelper(InstrumentHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void InstrumentImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<Instrument*>(stub);
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* InstrumentImplementation::_getStub() {
	return _this;
}

InstrumentImplementation::operator const Instrument*() {
	return _this;
}

void InstrumentImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void InstrumentImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void InstrumentImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void InstrumentImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void InstrumentImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void InstrumentImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void InstrumentImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void InstrumentImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("Instrument");

}

void InstrumentImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(InstrumentImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool InstrumentImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TangibleObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "instrumentType") {
		TypeInfo<int >::parseFromBinaryStream(&instrumentType, stream);
		return true;
	}

	if (_name == "beingUsed") {
		TypeInfo<bool >::parseFromBinaryStream(&beingUsed, stream);
		return true;
	}

	if (_name == "spawnedObject") {
		TypeInfo<ManagedReference<SceneObject* > >::parseFromBinaryStream(&spawnedObject, stream);
		return true;
	}

	if (_name == "spawnerPlayer") {
		TypeInfo<ManagedWeakReference<CreatureObject* > >::parseFromBinaryStream(&spawnerPlayer, stream);
		return true;
	}


	return false;
}

void InstrumentImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = InstrumentImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int InstrumentImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "instrumentType";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&instrumentType, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "beingUsed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<bool >::toBinaryStream(&beingUsed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "spawnedObject";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<SceneObject* > >::toBinaryStream(&spawnedObject, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "spawnerPlayer";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedWeakReference<CreatureObject* > >::toBinaryStream(&spawnerPlayer, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 4 + TangibleObjectImplementation::writeObjectMembers(stream);
}

InstrumentImplementation::InstrumentImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/Instrument.idl():  		instrumentType = 0;
	instrumentType = 0;
	// server/zone/objects/tangible/Instrument.idl():  		beingUsed = false;
	beingUsed = false;
	// server/zone/objects/tangible/Instrument.idl():  		Logger.setLoggingName("Instrument");
	Logger::setLoggingName("Instrument");
}

void InstrumentImplementation::initializeTransientMembers() {
	// server/zone/objects/tangible/Instrument.idl():  		super.initializeTransientMembers();
	TangibleObjectImplementation::initializeTransientMembers();
	// server/zone/objects/tangible/Instrument.idl():  		Logger.setLoggingName("Instrument");
	Logger::setLoggingName("Instrument");
}

void InstrumentImplementation::notifyLoadFromDatabase() {
	// server/zone/objects/tangible/Instrument.idl():  		super.notifyLoadFromDatabase();
	TangibleObjectImplementation::notifyLoadFromDatabase();
	// server/zone/objects/tangible/Instrument.idl():  		beingUsed = false;
	beingUsed = false;
	// server/zone/objects/tangible/Instrument.idl():  	}
	if (spawnedObject != NULL){
	// server/zone/objects/tangible/Instrument.idl():  			spawnedObject.destroyObjectFromWorld(true);
	spawnedObject->destroyObjectFromWorld(true);
}
}

void InstrumentImplementation::loadTemplateData(SharedObjectTemplate* templateData) {
	// server/zone/objects/tangible/Instrument.idl():  		super.loadTemplateData(templateData);
	TangibleObjectImplementation::loadTemplateData(templateData);
	// server/zone/objects/tangible/Instrument.idl():  		InstrumentObjectTemplate 
	if (!templateData->isInstrumentObjectTemplate())	// server/zone/objects/tangible/Instrument.idl():  			return;
	return;
	// server/zone/objects/tangible/Instrument.idl():  		InstrumentObjectTemplate templ = (InstrumentObjectTemplate) templateData;
	InstrumentObjectTemplate* templ = (InstrumentObjectTemplate*) templateData;
	// server/zone/objects/tangible/Instrument.idl():  		instrumentType = templ.getInstrumentType();
	instrumentType = templ->getInstrumentType();
}

void InstrumentImplementation::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player) {
	// server/zone/objects/tangible/Instrument.idl():  		super.fillObjectMenuResponse(menuResponse, player);
	TangibleObjectImplementation::fillObjectMenuResponse(menuResponse, player);
	// server/zone/objects/tangible/Instrument.idl():  		if 
	if (instrumentType != OMNIBOX && instrumentType != NALARGON){
	// server/zone/objects/tangible/Instrument.idl():  			return;
	return;
}
	// server/zone/objects/tangible/Instrument.idl():  	}
	if (beingUsed){
	// server/zone/objects/tangible/Instrument.idl():  			return;
	return;
}

	else 	// server/zone/objects/tangible/Instrument.idl():  	}
	if (!isInQuadTree()){
	// server/zone/objects/tangible/Instrument.idl():  			menuResponse.addRadialMenuItem(69, 3, "@radial_performance:play_instrument");
	menuResponse->addRadialMenuItem(69, 3, "@radial_performance:play_instrument");
}
}

int InstrumentImplementation::getInstrumentType() {
	// server/zone/objects/tangible/Instrument.idl():  		return instrumentType;
	return instrumentType;
}

CreatureObject* InstrumentImplementation::getSpawnerPlayer() {
	// server/zone/objects/tangible/Instrument.idl():  		return spawnerPlayer;
	return spawnerPlayer;
}

void InstrumentImplementation::setSpawnerPlayer(CreatureObject* pla) {
	// server/zone/objects/tangible/Instrument.idl():  		spawnerPlayer = pla;
	spawnerPlayer = pla;
}

bool InstrumentImplementation::isBeingUsed() {
	// server/zone/objects/tangible/Instrument.idl():  		return beingUsed;
	return beingUsed;
}

void InstrumentImplementation::setBeingUsed(bool val) {
	// server/zone/objects/tangible/Instrument.idl():  		beingUsed = val;
	beingUsed = val;
}

/*
 *	InstrumentAdapter
 */

InstrumentAdapter::InstrumentAdapter(Instrument* obj) : TangibleObjectAdapter(obj) {
}

Packet* InstrumentAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		initializeTransientMembers();
		break;
	case RPC_NOTIFYLOADFROMDATABASE__:
		notifyLoadFromDatabase();
		break;
	case RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect(static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getByteParameter()));
		break;
	case RPC_SPAWNINFOREIGNCELL__CREATUREOBJECT_:
		spawnInForeignCell(static_cast<CreatureObject*>(inv->getObjectParameter()));
		break;
	case RPC_SPAWNINADMINCELL__CREATUREOBJECT_:
		spawnInAdminCell(static_cast<CreatureObject*>(inv->getObjectParameter()));
		break;
	case RPC_SPAWNOUTSIDE__CREATUREOBJECT_:
		spawnOutside(static_cast<CreatureObject*>(inv->getObjectParameter()));
		break;
	case RPC_GETINSTRUMENTTYPE__:
		resp->insertSignedInt(getInstrumentType());
		break;
	case RPC_GETSPAWNERPLAYER__:
		resp->insertLong(getSpawnerPlayer()->_getObjectID());
		break;
	case RPC_SETSPAWNERPLAYER__CREATUREOBJECT_:
		setSpawnerPlayer(static_cast<CreatureObject*>(inv->getObjectParameter()));
		break;
	case RPC_ISBEINGUSED__:
		resp->insertBoolean(isBeingUsed());
		break;
	case RPC_SETBEINGUSED__BOOL_:
		setBeingUsed(inv->getBooleanParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void InstrumentAdapter::initializeTransientMembers() {
	(static_cast<Instrument*>(stub))->initializeTransientMembers();
}

void InstrumentAdapter::notifyLoadFromDatabase() {
	(static_cast<Instrument*>(stub))->notifyLoadFromDatabase();
}

int InstrumentAdapter::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	return (static_cast<Instrument*>(stub))->handleObjectMenuSelect(player, selectedID);
}

void InstrumentAdapter::spawnInForeignCell(CreatureObject* spawner) {
	(static_cast<Instrument*>(stub))->spawnInForeignCell(spawner);
}

void InstrumentAdapter::spawnInAdminCell(CreatureObject* spawner) {
	(static_cast<Instrument*>(stub))->spawnInAdminCell(spawner);
}

void InstrumentAdapter::spawnOutside(CreatureObject* spawner) {
	(static_cast<Instrument*>(stub))->spawnOutside(spawner);
}

int InstrumentAdapter::getInstrumentType() {
	return (static_cast<Instrument*>(stub))->getInstrumentType();
}

CreatureObject* InstrumentAdapter::getSpawnerPlayer() {
	return (static_cast<Instrument*>(stub))->getSpawnerPlayer();
}

void InstrumentAdapter::setSpawnerPlayer(CreatureObject* pla) {
	(static_cast<Instrument*>(stub))->setSpawnerPlayer(pla);
}

bool InstrumentAdapter::isBeingUsed() {
	return (static_cast<Instrument*>(stub))->isBeingUsed();
}

void InstrumentAdapter::setBeingUsed(bool val) {
	(static_cast<Instrument*>(stub))->setBeingUsed(val);
}

/*
 *	InstrumentHelper
 */

InstrumentHelper* InstrumentHelper::staticInitializer = InstrumentHelper::instance();

InstrumentHelper::InstrumentHelper() {
	className = "Instrument";

	Core::getObjectBroker()->registerClass(className, this);
}

void InstrumentHelper::finalizeHelper() {
	InstrumentHelper::finalize();
}

DistributedObject* InstrumentHelper::instantiateObject() {
	return new Instrument(DummyConstructorParameter::instance());
}

DistributedObjectServant* InstrumentHelper::instantiateServant() {
	return new InstrumentImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* InstrumentHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new InstrumentAdapter(static_cast<Instrument*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

