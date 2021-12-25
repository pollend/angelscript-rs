#include "./angelscript.hpp"

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
extern int asIScriptEngine_SetMessageCallback(asIScriptEngine* engine, const asSFuncPtr &callback, void *obj, asDWORD callConv) {
    engine->SetMessageCallback(callback, obj, callConv);
}
extern int asIScriptEngine_ClearMessageCallback(asIScriptEngine* engine) {
    engine->ClearMessageCallback();
}
// extern int asIScriptEngine_WriteMessage(asIScriptEngine* engine, const char *section, int row, int col, asEMsgType type, const char *message) {

// }

// // JIT Compiler
// extern int SetJITCompiler(asIJITCompiler *compiler) = 0;
// extern asIJITCompiler *GetJITCompiler() const = 0;

// // Global functions
// extern int                RegisterGlobalFunction(const char *declaration, const asSFuncPtr &funcPointer, asDWORD callConv, void *auxiliary = 0) = 0;
// extern asUINT             GetGlobalFunctionCount() const = 0;
// extern asIScriptFunction *GetGlobalFunctionByIndex(asUINT index) const = 0;
// extern asIScriptFunction *GetGlobalFunctionByDecl(const char *declaration) const = 0;

// // Global properties
// extern int    RegisterGlobalProperty(const char *declaration, void *pointer) = 0;
// extern asUINT GetGlobalPropertyCount() const = 0;
// extern int    GetGlobalPropertyByIndex(asUINT index, const char **name, const char **nameSpace = 0, int *typeId = 0, bool *isConst = 0, const char **configGroup = 0, void **pointer = 0, asDWORD *accessMask = 0) const = 0;
// extern int    GetGlobalPropertyIndexByName(const char *name) const = 0;
// extern int    GetGlobalPropertyIndexByDecl(const char *decl) const = 0;

// // Object types
// extern int            RegisterObjectType(const char *obj, int byteSize, asDWORD flags) = 0;
// extern int            RegisterObjectProperty(const char *obj, const char *declaration, int byteOffset, int compositeOffset = 0, bool isCompositeIndirect = false) = 0;
// extern int            RegisterObjectMethod(const char *obj, const char *declaration, const asSFuncPtr &funcPointer, asDWORD callConv, void *auxiliary = 0, int compositeOffset = 0, bool isCompositeIndirect = false) = 0;
// extern int            RegisterObjectBehaviour(const char *obj, asEBehaviours behaviour, const char *declaration, const asSFuncPtr &funcPointer, asDWORD callConv, void *auxiliary = 0, int compositeOffset = 0, bool isCompositeIndirect = false) = 0;
// extern int            RegisterInterface(const char *name) = 0;
// extern int            RegisterInterfaceMethod(const char *intf, const char *declaration) = 0;
// extern asUINT         GetObjectTypeCount() const = 0;
// extern asITypeInfo   *GetObjectTypeByIndex(asUINT index) const = 0;

// // String factory
// extern int RegisterStringFactory(const char *datatype, asIStringFactory *factory) = 0;
// extern int GetStringFactoryReturnTypeId(asDWORD *flags = 0) const = 0;

// // Default array type
// extern int RegisterDefaultArrayType(const char *type) = 0;
// extern int GetDefaultArrayTypeId() const = 0;

// // Enums
// extern int          RegisterEnum(const char *type) = 0;
// extern int          RegisterEnumValue(const char *type, const char *name, int value) = 0;
// extern asUINT       GetEnumCount() const = 0;
// extern asITypeInfo *GetEnumByIndex(asUINT index) const = 0;

// // Funcdefs
// extern int          RegisterFuncdef(const char *decl) = 0;
// extern asUINT       GetFuncdefCount() const = 0;
// extern asITypeInfo *GetFuncdefByIndex(asUINT index) const = 0;

// // Typedefs
// extern int          RegisterTypedef(const char *type, const char *decl) = 0;
// extern asUINT       GetTypedefCount() const = 0;
// extern asITypeInfo *GetTypedefByIndex(asUINT index) const = 0;

// // Configuration groups
// extern int         BeginConfigGroup(const char *groupName) = 0;
// extern int         EndConfigGroup() = 0;
// extern int         RemoveConfigGroup(const char *groupName) = 0;
// extern asDWORD     SetDefaultAccessMask(asDWORD defaultMask) = 0;
// extern int         SetDefaultNamespace(const char *nameSpace) = 0;
// extern const char *GetDefaultNamespace() const = 0;

// // Script modules
// extern asIScriptModule *GetModule(const char *module, asEGMFlags flag = asGM_ONLY_IF_EXISTS) = 0;
// extern int              DiscardModule(const char *module) = 0;
// extern asUINT           GetModuleCount() const = 0;
// extern asIScriptModule *GetModuleByIndex(asUINT index) const = 0;

// // Script functions
// extern asIScriptFunction *GetFunctionById(int funcId) const = 0;

// // Type identification
// extern int            GetTypeIdByDecl(const char *decl) const = 0;
// extern const char    *GetTypeDeclaration(int typeId, bool includeNamespace = false) const = 0;
// extern int            GetSizeOfPrimitiveType(int typeId) const = 0;
// extern asITypeInfo   *GetTypeInfoById(int typeId) const = 0;
// extern asITypeInfo   *GetTypeInfoByName(const char *name) const = 0;
// extern asITypeInfo   *GetTypeInfoByDecl(const char *decl) const = 0;

// // Script execution
// extern asIScriptContext      *CreateContext() = 0;
// extern void                  *CreateScriptObject(const asITypeInfo *type) = 0;
// extern void                  *CreateScriptObjectCopy(void *obj, const asITypeInfo *type) = 0;
// extern void                  *CreateUninitializedScriptObject(const asITypeInfo *type) = 0;
// extern asIScriptFunction     *CreateDelegate(asIScriptFunction *func, void *obj) = 0;
// extern int                    AssignScriptObject(void *dstObj, void *srcObj, const asITypeInfo *type) = 0;
// extern void                   ReleaseScriptObject(void *obj, const asITypeInfo *type) = 0;
// extern void                   AddRefScriptObject(void *obj, const asITypeInfo *type) = 0;
// extern int                    RefCastObject(void *obj, asITypeInfo *fromType, asITypeInfo *toType, void **newPtr, bool useOnlyImplicitCast = false) = 0;
// extern asILockableSharedBool *GetWeakRefFlagOfScriptObject(void *obj, const asITypeInfo *type) const = 0;

// // Context pooling
// extern asIScriptContext      *RequestContext() = 0;
// extern void                   ReturnContext(asIScriptContext *ctx) = 0;
// extern int                    SetContextCallbacks(asREQUESTCONTEXTFUNC_t requestCtx, asRETURNCONTEXTFUNC_t returnCtx, void *param = 0) = 0;

// // String interpretation
// extern asETokenClass ParseToken(const char *string, size_t stringLength = 0, asUINT *tokenLength = 0) const = 0;

// // Garbage collection
// extern int  GarbageCollect(asDWORD flags = asGC_FULL_CYCLE, asUINT numIterations = 1) = 0;
// extern void GetGCStatistics(asUINT *currentSize, asUINT *totalDestroyed = 0, asUINT *totalDetected = 0, asUINT *newObjects = 0, asUINT *totalNewDestroyed = 0) const = 0;
// extern int  NotifyGarbageCollectorOfNewObject(void *obj, asITypeInfo *type) = 0;
// extern int  GetObjectInGC(asUINT idx, asUINT *seqNbr = 0, void **obj = 0, asITypeInfo **type = 0) = 0;
// extern void GCEnumCallback(void *reference) = 0;
// extern void ForwardGCEnumReferences(void *ref, asITypeInfo *type) = 0;
// extern void ForwardGCReleaseReferences(void *ref, asITypeInfo *type) = 0;
// extern void SetCircularRefDetectedCallback(asCIRCULARREFFUNC_t callback, void *param = 0) = 0;

// // User data
// extern void *SetUserData(void *data, asPWORD type = 0) = 0;
// extern void *GetUserData(asPWORD type = 0) const = 0;
// extern void  SetEngineUserDataCleanupCallback(asCLEANENGINEFUNC_t callback, asPWORD type = 0) = 0;
// extern void  SetModuleUserDataCleanupCallback(asCLEANMODULEFUNC_t callback, asPWORD type = 0) = 0;
// extern void  SetContextUserDataCleanupCallback(asCLEANCONTEXTFUNC_t callback, asPWORD type = 0) = 0;
// extern void  SetFunctionUserDataCleanupCallback(asCLEANFUNCTIONFUNC_t callback, asPWORD type = 0) = 0;
// extern void  SetTypeInfoUserDataCleanupCallback(asCLEANTYPEINFOFUNC_t callback, asPWORD type = 0) = 0;
// extern void  SetScriptObjectUserDataCleanupCallback(asCLEANSCRIPTOBJECTFUNC_t callback, asPWORD type = 0) = 0;

// // Exception handling
// extern int SetTranslateAppExceptionCallback(asSFuncPtr callback, void *param, int callConv) = 0;