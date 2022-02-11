static unsigned int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
return V_1 + F_2 ( V_2 ) ;
}
static int F_3 ( unsigned int V_3 ,
struct V_4 * V_5 )
{
return ( V_3 >= V_5 -> V_1 ) && ( V_3 < ( V_5 -> V_1 + V_5 -> V_6 ) ) ;
}
int F_4 ( struct V_7 * V_8 , unsigned int V_1 ,
unsigned int V_6 )
{
if ( ! V_8 )
return - 1 ;
V_8 -> V_1 = V_1 ;
V_8 -> V_2 = F_5 ( V_6 ) ;
V_8 -> V_6 = F_2 ( V_8 -> V_2 ) ;
F_6 ( & V_8 -> V_9 ) ;
F_7 ( & V_8 -> V_10 ) ;
V_8 -> V_11 = F_8 ( L_1 , sizeof( struct V_4 ) ,
0 , 0 , NULL ) ;
return V_8 -> V_11 != NULL ? 0 : - V_12 ;
}
void F_9 ( struct V_7 * V_8 )
{
struct V_4 * V_5 , * V_13 ;
struct V_14 V_15 ;
if ( ! V_8 )
return;
F_10 ( & V_8 -> V_10 ) ;
F_11 ( & V_8 -> V_9 , & V_15 ) ;
F_12 ( & V_8 -> V_10 ) ;
F_13 (node, tmp, &new_head, list) {
F_14 ( & V_5 -> V_16 ) ;
F_15 ( V_8 -> V_11 , V_5 ) ;
}
F_16 ( V_8 -> V_11 ) ;
}
static struct V_4 * F_17 ( unsigned int V_2 ,
struct V_7 * V_8 )
{
struct V_4 * V_5 ;
V_5 = F_18 ( V_8 -> V_11 , V_17 ) ;
if ( ! V_5 ) {
F_19 ( V_18 , L_2 ) ;
return NULL ;
}
F_6 ( & V_5 -> V_16 ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_6 = F_2 ( V_2 ) ;
V_5 -> V_8 = V_8 ;
return V_5 ;
}
struct V_4 * F_20 ( struct V_7 * V_8 , unsigned int V_2 )
{
struct V_14 * V_19 ;
struct V_4 * V_5 , * V_20 , * V_21 ;
unsigned int V_22 , V_23 ;
unsigned int V_3 ;
unsigned int V_6 ;
if ( ! V_8 )
return NULL ;
V_22 = V_8 -> V_1 ;
V_23 = F_1 ( V_8 -> V_1 , V_8 -> V_2 ) ;
V_6 = F_2 ( V_2 ) ;
V_3 = V_22 ;
V_19 = & V_8 -> V_9 ;
V_5 = F_17 ( V_2 , V_8 ) ;
if ( ! V_5 ) {
F_19 ( V_18 , L_3 ) ;
return NULL ;
}
F_10 ( & V_8 -> V_10 ) ;
F_21 (cur, head, list) {
V_3 = F_22 ( F_1 ( V_20 -> V_1 , V_20 -> V_2 ) + 1 ) ;
if ( F_23 ( & V_20 -> V_16 , V_19 ) ) {
if ( V_3 + V_6 > V_23 ) {
F_12 ( & V_8 -> V_10 ) ;
F_15 ( V_8 -> V_11 , V_5 ) ;
F_19 ( V_18 ,
L_4 ) ;
return NULL ;
}
break;
}
V_21 = F_24 ( V_20 -> V_16 . V_21 , struct V_4 , V_16 ) ;
if ( ( V_21 -> V_1 - V_3 ) > V_6 )
break;
}
V_5 -> V_1 = V_3 ;
V_5 -> V_8 = V_8 ;
F_25 ( & V_5 -> V_16 , & V_20 -> V_16 ) ;
F_12 ( & V_8 -> V_10 ) ;
return V_5 ;
}
void F_26 ( struct V_4 * V_5 )
{
struct V_7 * V_8 ;
if ( ! V_5 )
return;
V_8 = V_5 -> V_8 ;
F_10 ( & V_8 -> V_10 ) ;
F_14 ( & V_5 -> V_16 ) ;
F_12 ( & V_8 -> V_10 ) ;
F_15 ( V_8 -> V_11 , V_5 ) ;
}
struct V_4 * F_27 ( struct V_7 * V_8 , unsigned int V_3 )
{
struct V_4 * V_5 ;
if ( ! V_8 )
return NULL ;
F_10 ( & V_8 -> V_10 ) ;
F_21 (node, &vm->vm_node_list, list) {
if ( V_5 -> V_1 == V_3 ) {
F_12 ( & V_8 -> V_10 ) ;
return V_5 ;
}
}
F_12 ( & V_8 -> V_10 ) ;
return NULL ;
}
struct V_4 * F_28 ( struct V_7 * V_8 ,
unsigned int V_3 )
{
struct V_4 * V_5 ;
if ( ! V_8 )
return NULL ;
F_10 ( & V_8 -> V_10 ) ;
F_21 (node, &vm->vm_node_list, list) {
if ( F_3 ( V_3 , V_5 ) ) {
F_12 ( & V_8 -> V_10 ) ;
return V_5 ;
}
}
F_12 ( & V_8 -> V_10 ) ;
return NULL ;
}
