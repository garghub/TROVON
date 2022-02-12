void *WILC_MemoryAlloc(u32 u32Size, tstrWILC_MemoryAttrs *strAttrs,
char *pcFileName, u32 u32LineNo)
{
if (u32Size > 0)
return kmalloc(u32Size, GFP_ATOMIC);
else
return NULL;
}
