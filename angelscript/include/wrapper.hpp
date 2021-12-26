#include "./angelscript.hpp"

extern asSFuncPtr __asFunctionPtr(void* pointer) {
    asSFuncPtr p(2);
#ifdef AS_64BIT_PTR
	// The size_t cast is to avoid a compiler warning with asFUNCTION(0)
	// on 64bit, as 0 is interpreted as a 32bit int value
    p.ptr.f.func = reinterpret_cast<asFUNCTION_t>(size_t(pointer));
#else
	// MSVC6 doesn't like the size_t cast above so I
	// solved this with a separate code for 32bit.
	p.ptr.f.func = reinterpret_cast<asFUNCTION_t>(pointer);
#endif
    return p;
}

extern int asIScriptEngine_AddRef(asIScriptEngine* engine) {
    return engine->AddRef();
}
extern int asIScriptEngine_Release(asIScriptEngine* engine) {
    return engine->Release();
}
extern int asIScriptEngine_ShutDownAndRelease(asIScriptEngine* engine) {
    return engine->ShutDownAndRelease();
}
extern int asIScriptEngine_SetEngineProperty(asIScriptEngine* engine, asEEngineProp property, asPWORD value)  {
    return engine->SetEngineProperty(property, value);
}
extern asPWORD asIScriptEngine_GetEngineProperty(asIScriptEngine* engine, asEEngineProp property) {
    return engine->GetEngineProperty(property);
}

// Compiler messages
extern int asIScriptEngine_SetMessageCallback(asIScriptEngine* engine, const asSFuncPtr callback, void *obj, asDWORD callConv) {
    return engine->SetMessageCallback(callback, obj, callConv);
}
extern int asIScriptEngine_ClearMessageCallback(asIScriptEngine* engine) {
    return engine->ClearMessageCallback();
}
extern int asIScriptEngine_WriteMessage(asIScriptEngine* engine, const char *section, int row, int col, asEMsgType type, const char *message) {
    return -engine->WriteMessage(section, row, col, type, message);
}

// TODO: implement JIT compiler
// JIT Compiler
// extern int SetJITCompiler(asIJITCompiler *compiler) ;
// extern asIJITCompiler *GetJITCompiler() const ;

// Global functions
extern int  asIScriptEngine_RegisterGlobalFunction(asIScriptEngine* engine, const char *declaration, const asSFuncPtr &funcPointer, asDWORD callConv, void *auxiliary) {
    return engine->RegisterGlobalFunction(declaration, funcPointer, callConv, auxiliary);
}
extern asUINT asIScriptEngine_GetGlobalFunctionCount(asIScriptEngine* engine)  {
    return engine->GetGlobalFunctionCount();
}
extern asIScriptFunction *asIScriptEngine_GetGlobalFunctionByIndex(asIScriptEngine* engine,asUINT index)  {
    return engine->GetGlobalFunctionByIndex(index);
}
extern asIScriptFunction *asIScriptEngine_GetGlobalFunctionByDecl(asIScriptEngine* engine, const char *declaration)   {
    return engine->GetGlobalFunctionByDecl(declaration);
}

// Global properties
extern int asIScriptEngine_RegisterGlobalProperty(asIScriptEngine* engine, const char *declaration, void *pointer) {
    return engine->RegisterGlobalProperty(declaration, pointer);
}
extern asUINT asIScriptEngine_GetGlobalPropertyCount(asIScriptEngine* engine) {
    return engine->GetGlobalPropertyCount();
}
extern int asIScriptEngine_GetGlobalPropertyByIndex(asIScriptEngine* engine, asUINT index, const char **name, const char **nameSpace, int *typeId, bool *isConst, const char **configGroup, void **pointer, asDWORD *accessMask) {
    return engine->GetGlobalPropertyByIndex(index, name, nameSpace, typeId, isConst, configGroup, pointer, accessMask);
}
extern int asIScriptEngine_GetGlobalPropertyIndexByName(asIScriptEngine* engine, const char *name) {
    return engine->GetGlobalPropertyIndexByName(name);
}
extern int asIScriptEngine_GetGlobalPropertyIndexByDecl(asIScriptEngine* engine, const char *decl) {
    return engine->GetGlobalPropertyIndexByDecl(decl);
}

// Object types
extern int asIScriptEngine_RegisterObjectType(asIScriptEngine* engine, const char *obj, int byteSize, asDWORD flags) {
    return engine->RegisterObjectType(obj, byteSize, flags);
}
extern int asIScriptEngine_RegisterObjectProperty(asIScriptEngine* engine, const char *obj, const char *declaration, int byteOffset, int compositeOffset , bool isCompositeIndirect ) {
    return engine->RegisterObjectProperty(obj, declaration, byteOffset, compositeOffset, isCompositeIndirect);
}
extern int asIScriptEngine_RegisterObjectMethod(asIScriptEngine* engine, const char *obj, const char *declaration, const asSFuncPtr funcPointer, asDWORD callConv, void *auxiliary , int compositeOffset , bool isCompositeIndirect ) {
    return engine->RegisterObjectMethod(obj, declaration, funcPointer, callConv, auxiliary, compositeOffset, isCompositeIndirect);
}
extern int asIScriptEngine_RegisterObjectBehaviour(asIScriptEngine* engine, const char *obj, asEBehaviours behaviour, const char *declaration, const asSFuncPtr funcPointer, asDWORD callConv, void *auxiliary , int compositeOffset , bool isCompositeIndirect ) {
    return engine->RegisterObjectBehaviour(obj, behaviour, declaration, funcPointer, callConv, auxiliary, compositeOffset, isCompositeIndirect);
}
extern int asIScriptEngine_RegisterInterface(asIScriptEngine* engine, const char *name) {
    return engine->RegisterInterface(name);
}
extern int asIScriptEngine_RegisterInterfaceMethod(asIScriptEngine* engine, const char *intf, const char *declaration) {
    return engine->RegisterInterfaceMethod(intf, declaration);
}
extern asUINT asIScriptEngine_GetObjectTypeCount(asIScriptEngine* engine) {
    return engine->GetObjectTypeCount();
}
extern asITypeInfo *asIScriptEngine_GetObjectTypeByIndex(asIScriptEngine* engine, asUINT index) {
    return engine->GetObjectTypeByIndex(index);
}

// TODO: implemented string factory
// String factory
// extern int RegisterStringFactory(const char *datatype, asIStringFactory *factory) ;
// extern int GetStringFactoryReturnTypeId(asDWORD *flags ) const ;

// Default array type
extern int asIScriptEngine_RegisterDefaultArrayType(asIScriptEngine* engine, const char *type) {
    return engine->RegisterDefaultArrayType(type);
}
extern int asIScriptEngine_GetDefaultArrayTypeId(asIScriptEngine* engine) {
    return engine->GetDefaultArrayTypeId();
}

// Enums
extern int asIScriptEngine_RegisterEnum(asIScriptEngine* engine, const char *type)  {
    return engine->RegisterEnum(type);
}
extern int asIScriptEngine_RegisterEnumValue(asIScriptEngine* engine, const char *type, const char *name, int value) {
    return engine->RegisterEnumValue(type, name, value);
}
extern asUINT asIScriptEngine_GetEnumCount(asIScriptEngine* engine) {
    return engine->GetEnumCount();
}
extern asITypeInfo *asIScriptEngine_GetEnumByIndex(asIScriptEngine* engine, asUINT index)  {
    return engine->GetEnumByIndex(index);
}

// Funcdefs
extern int asIScriptEngine_RegisterFuncdef(asIScriptEngine* engine, const char *decl) {
    return engine->RegisterFuncdef(decl);
}  
extern asUINT asIScriptEngine_GetFuncdefCount(asIScriptEngine* engine) {
    return engine->GetFuncdefCount();
}
extern asITypeInfo *asIScriptEngine_GetFuncdefByIndex(asIScriptEngine* engine, asUINT index) {
    return engine->GetFuncdefByIndex(index);
}

// Typedefs
extern int asIScriptEngine_RegisterTypedef(asIScriptEngine* engine, const char *type, const char *decl) {
    return engine->RegisterTypedef(type, decl);
}
extern asUINT asIScriptEngine_GetTypedefCount(asIScriptEngine* engine) {
    return engine->GetTypedefCount();
}
extern asITypeInfo *asIScriptEngine_GetTypedefByIndex(asIScriptEngine* engine, asUINT index) {
    return engine->GetTypedefByIndex(index);
}

// Configuration groups
extern int asIScriptEngine_BeginConfigGroup(asIScriptEngine* engine, const char *groupName) {
    return engine->BeginConfigGroup(groupName);
}
extern int asIScriptEngine_EndConfigGroup(asIScriptEngine* engine) {
    return engine->EndConfigGroup();
}
extern int asIScriptEngine_RemoveConfigGroup(asIScriptEngine* engine, const char *groupName) {
    return engine->RemoveConfigGroup(groupName);
}
extern asDWORD asIScriptEngine_SetDefaultAccessMask(asIScriptEngine* engine, asDWORD defaultMask) {
    return engine->SetDefaultAccessMask(defaultMask);
}
extern int asIScriptEngine_SetDefaultNamespace(asIScriptEngine* engine, const char *nameSpace) {
    return engine->SetDefaultNamespace(nameSpace);
}
extern const char *asIScriptEngine_GetDefaultNamespace(asIScriptEngine* engine) {
    return engine->GetDefaultNamespace();
}

// Script modules
extern asIScriptModule *asIScriptEngine_GetModule(asIScriptEngine* engine, const char *module, asEGMFlags flag) {
    return engine->GetModule(module, flag);
}
extern int asIScriptEngine_DiscardModule(asIScriptEngine* engine, const char *module) {
    return engine->DiscardModule(module);
}
extern asUINT asIScriptEngine_GetModuleCount(asIScriptEngine* engine) {
    return engine->GetModuleCount();
}
extern asIScriptModule *asIScriptEngine_GetModuleByIndex(asIScriptEngine* engine, asUINT index) {
    return engine->GetModuleByIndex(index);
}

// Script functions
extern asIScriptFunction *asIScriptEngine_GetFunctionById(asIScriptEngine* engine, int funcId) {
    return engine->GetFunctionById(funcId);
}

// Type identification
extern int asIScriptEngine_GetTypeIdByDecl(asIScriptEngine* engine, const char *decl) {
    return engine->GetTypeIdByDecl(decl);
}
extern const char *asIScriptEngine_GetTypeDeclaration(asIScriptEngine* engine, int typeId, bool includeNamespace) {
    return engine->GetTypeDeclaration(typeId, includeNamespace);
}
extern int asIScriptEngine_GetSizeOfPrimitiveType(asIScriptEngine* engine, int typeId) {
    return engine->GetSizeOfPrimitiveType(typeId);
}
extern asITypeInfo *asIScriptEngine_GetTypeInfoById(asIScriptEngine* engine, int typeId) {
    return engine->GetTypeInfoById(typeId);
}
extern asITypeInfo *asIScriptEngine_GetTypeInfoByName(asIScriptEngine* engine, const char *name) {
    return engine->GetTypeInfoByName(name);
}
extern asITypeInfo *asIScriptEngine_GetTypeInfoByDecl(asIScriptEngine* engine, const char *decl) {
    return engine->GetTypeInfoByDecl(decl);
}

// Script execution
extern asIScriptContext *asIScriptEngine_CreateContext(asIScriptEngine* engine) {
    return engine->CreateContext();
}
extern void *asIScriptEngine_CreateScriptObject(asIScriptEngine* engine, const asITypeInfo *type) {
    return engine->CreateScriptObject(type);
}
extern void *asIScriptEngine_CreateScriptObjectCopy(asIScriptEngine* engine, void *obj, const asITypeInfo *type) {
    return engine->CreateScriptObjectCopy(obj, type);
}
extern void *asIScriptEngine_CreateUninitializedScriptObject(asIScriptEngine* engine, const asITypeInfo *type) {
    return engine->CreateUninitializedScriptObject(type);
}
extern asIScriptFunction *asIScriptEngine_CreateDelegate(asIScriptEngine* engine, asIScriptFunction *func, void *obj) {
    return engine->CreateDelegate(func, obj);
}
extern int asIScriptEngine_AssignScriptObject(asIScriptEngine* engine, void *dstObj, void *srcObj, const asITypeInfo *type) {
    return engine->AssignScriptObject(dstObj, srcObj, type);
}
extern void asIScriptEngine_ReleaseScriptObject(asIScriptEngine* engine, void *obj, const asITypeInfo *type) {
    return engine->ReleaseScriptObject(obj, type);
}
extern void asIScriptEngine_AddRefScriptObject(asIScriptEngine* engine, void *obj, const asITypeInfo *type) {
    return engine->AddRefScriptObject(obj, type);
}
extern int asIScriptEngine_RefCastObject(asIScriptEngine* engine, void *obj, asITypeInfo *fromType, asITypeInfo *toType, void **newPtr, bool useOnlyImplicitCast) {
    return engine->RefCastObject(obj, fromType, toType, newPtr, useOnlyImplicitCast);
}
extern asILockableSharedBool *asIScriptEngine_GetWeakRefFlagOfScriptObject(asIScriptEngine* engine, void *obj, const asITypeInfo *type) {
    return engine->GetWeakRefFlagOfScriptObject(obj, type);
}

// Context pooling
extern asIScriptContext *asIScriptEngine_RequestContext(asIScriptEngine* engine) {
    return engine->RequestContext();
}
extern void asIScriptEngine_ReturnContext(asIScriptEngine* engine, asIScriptContext *ctx) {
    return engine->ReturnContext(ctx);
}
extern int asIScriptEngine_SetContextCallbacks(asIScriptEngine* engine, asREQUESTCONTEXTFUNC_t requestCtx, asRETURNCONTEXTFUNC_t returnCtx, void *param) {
    return engine->SetContextCallbacks(requestCtx, returnCtx, param);
}

// String interpretation
extern asETokenClass asIScriptEngine_ParseToken(asIScriptEngine* engine, const char *string, size_t stringLength , asUINT *tokenLength ) {
    return engine->ParseToken(string, stringLength, tokenLength);
}

// Garbage collection
extern int  asIScriptEngine_GarbageCollect(asIScriptEngine* engine, asDWORD flags, asUINT numIterations) {
    return engine->GarbageCollect(flags, numIterations);
}
extern void asIScriptEngine_GetGCStatistics(asIScriptEngine* engine, asUINT *currentSize, asUINT *totalDestroyed , asUINT *totalDetected , asUINT *newObjects , asUINT *totalNewDestroyed ) {
    return engine->GetGCStatistics(currentSize, totalDestroyed, totalDetected, newObjects, totalNewDestroyed);
}
extern int  asIScriptEngine_NotifyGarbageCollectorOfNewObject(asIScriptEngine* engine, void *obj, asITypeInfo *type) {
    return engine->NotifyGarbageCollectorOfNewObject(obj, type);
}
extern int  asIScriptEngine_GetObjectInGC(asIScriptEngine* engine, asUINT idx, asUINT *seqNbr , void **obj , asITypeInfo **type ) {
    return engine->GetObjectInGC(idx, seqNbr, obj, type);    
}
extern void asIScriptEngine_GCEnumCallback(asIScriptEngine* engine, void *reference) {
    return engine->GCEnumCallback(reference);    
}
extern void asIScriptEngine_ForwardGCEnumReferences(asIScriptEngine* engine, void *ref, asITypeInfo *type) {
    return engine->ForwardGCEnumReferences(ref, type);    
}
extern void asIScriptEngine_ForwardGCReleaseReferences(asIScriptEngine* engine, void *ref, asITypeInfo *type) {
    return engine->ForwardGCReleaseReferences(ref, type);    
}
extern void asIScriptEngine_SetCircularRefDetectedCallback(asIScriptEngine* engine, asCIRCULARREFFUNC_t callback, void *param ) {
    return engine->SetCircularRefDetectedCallback(callback, param);    
}

// User data
extern void *asIScriptEngine_SetUserData(asIScriptEngine* engine, void *data, asPWORD type ) {
    return engine->SetUserData(data, type);
}
extern void *asIScriptEngine_GetUserData(asIScriptEngine* engine, asPWORD type ) {
    return engine->GetUserData(type);
}
extern void  asIScriptEngine_SetEngineUserDataCleanupCallback(asIScriptEngine* engine, asCLEANENGINEFUNC_t callback, asPWORD type ) {
    engine->SetEngineUserDataCleanupCallback(callback, type);
}
extern void  asIScriptEngine_SetModuleUserDataCleanupCallback(asIScriptEngine* engine, asCLEANMODULEFUNC_t callback, asPWORD type ) {
    engine->SetModuleUserDataCleanupCallback(callback, type);
}
extern void  asIScriptEngine_SetContextUserDataCleanupCallback(asIScriptEngine* engine, asCLEANCONTEXTFUNC_t callback, asPWORD type ) {
    engine->SetContextUserDataCleanupCallback(callback, type);
}
extern void  asIScriptEngine_SetFunctionUserDataCleanupCallback(asIScriptEngine* engine, asCLEANFUNCTIONFUNC_t callback, asPWORD type ) {
    engine->SetFunctionUserDataCleanupCallback(callback, type);
}
extern void  asIScriptEngine_SetTypeInfoUserDataCleanupCallback(asIScriptEngine* engine, asCLEANTYPEINFOFUNC_t callback, asPWORD type ) {
    engine->SetTypeInfoUserDataCleanupCallback(callback, type);
}
extern void  asIScriptEngine_SetScriptObjectUserDataCleanupCallback(asIScriptEngine* engine, asCLEANSCRIPTOBJECTFUNC_t callback, asPWORD type ) {
    engine->SetScriptObjectUserDataCleanupCallback(callback, type);
}

// Exception handling
extern int asIScriptEngine_SetTranslateAppExceptionCallback(asIScriptEngine* engine, asSFuncPtr callback, void *param, int callConv) {
    return engine->SetTranslateAppExceptionCallback(callback, param, callConv);
}