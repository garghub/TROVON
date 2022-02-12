pcomponent * __init
ArcGetPeer(pcomponent *Current)
{
if (Current == PROM_NULL_COMPONENT)
return PROM_NULL_COMPONENT;
return (pcomponent *) ARC_CALL1(next_component, Current);
}
pcomponent * __init
ArcGetChild(pcomponent *Current)
{
return (pcomponent *) ARC_CALL1(child_component, Current);
}
pcomponent * __init
ArcGetParent(pcomponent *Current)
{
if (Current == PROM_NULL_COMPONENT)
return PROM_NULL_COMPONENT;
return (pcomponent *) ARC_CALL1(parent_component, Current);
}
LONG __init
ArcGetConfigurationData(VOID *Buffer, pcomponent *Current)
{
return ARC_CALL2(component_data, Buffer, Current);
}
pcomponent * __init
ArcAddChild(pcomponent *Current, pcomponent *Template, VOID *ConfigurationData)
{
return (pcomponent *)
ARC_CALL3(child_add, Current, Template, ConfigurationData);
}
LONG __init
ArcDeleteComponent(pcomponent *ComponentToDelete)
{
return ARC_CALL1(comp_del, ComponentToDelete);
}
pcomponent * __init
ArcGetComponent(CHAR *Path)
{
return (pcomponent *)ARC_CALL1(component_by_path, Path);
}
static void __init
dump_component(pcomponent *p)
{
printk("[%p]:class<%s>type<%s>flags<%s>ver<%d>rev<%d>",
p, classes[p->class], types[p->type],
iflags[p->iflags], p->vers, p->rev);
printk("key<%08lx>\n\tamask<%08lx>cdsize<%d>ilen<%d>iname<%s>\n",
p->key, p->amask, (int)p->cdsize, (int)p->ilen, p->iname);
}
static void __init
traverse(pcomponent *p, int op)
{
dump_component(p);
if(ArcGetChild(p))
traverse(ArcGetChild(p), 1);
if(ArcGetPeer(p) && op)
traverse(ArcGetPeer(p), 1);
}
void __init
prom_testtree(void)
{
pcomponent *p;
p = ArcGetChild(PROM_NULL_COMPONENT);
dump_component(p);
p = ArcGetChild(p);
while(p) {
dump_component(p);
p = ArcGetPeer(p);
}
}
