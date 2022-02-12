ZSTD_customMem ZSTD_initStack(void *workspace, size_t workspaceSize)
{
ZSTD_customMem stackMem = {ZSTD_stackAlloc, ZSTD_stackFree, workspace};
ZSTD_stack *stack = (ZSTD_stack *)workspace;
if (!workspace || workspaceSize < sizeof(ZSTD_stack) || workspace != ZSTD_PTR_ALIGN(workspace)) {
ZSTD_customMem error = {NULL, NULL, NULL};
return error;
}
stack->ptr = workspace;
stack->end = (char *)workspace + workspaceSize;
stack_push(stack, sizeof(ZSTD_stack));
return stackMem;
}
void *ZSTD_stackAllocAll(void *opaque, size_t *size)
{
ZSTD_stack *stack = (ZSTD_stack *)opaque;
*size = (BYTE const *)stack->end - (BYTE *)ZSTD_PTR_ALIGN(stack->ptr);
return stack_push(stack, *size);
}
void *ZSTD_stackAlloc(void *opaque, size_t size)
{
ZSTD_stack *stack = (ZSTD_stack *)opaque;
return stack_push(stack, size);
}
void ZSTD_stackFree(void *opaque, void *address)
{
(void)opaque;
(void)address;
}
void *ZSTD_malloc(size_t size, ZSTD_customMem customMem) { return customMem.customAlloc(customMem.opaque, size); }
void ZSTD_free(void *ptr, ZSTD_customMem customMem)
{
if (ptr != NULL)
customMem.customFree(customMem.opaque, ptr);
}
