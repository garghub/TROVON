static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_5 . V_6 )
return 0 ;
F_2 (engine, dev_priv) {
struct V_7 * V_8 ;
int V_9 ;
if ( V_4 -> V_10 == NULL )
continue;
if ( V_4 -> V_10 == V_2 -> V_11 )
continue;
V_8 = F_3 ( V_4 , V_2 -> V_11 ) ;
if ( F_4 ( V_8 ) )
return F_5 ( V_8 ) ;
V_9 = F_6 ( V_8 ) ;
F_7 ( V_8 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static bool
F_8 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
if ( V_13 -> V_16 )
return false ;
if ( F_9 ( ! F_10 ( & V_13 -> V_17 ) ) )
return false ;
F_11 ( & V_13 -> V_17 , V_15 ) ;
return F_12 ( & V_13 -> V_18 ) ;
}
int
F_13 ( struct V_19 * V_20 , struct V_21 * V_22 ,
int V_23 , unsigned V_24 , unsigned V_25 ,
unsigned long V_26 , unsigned long V_27 ,
unsigned V_28 )
{
struct V_14 V_29 , V_30 ;
struct V_12 * V_13 ;
int V_9 = 0 ;
int V_31 = 0 ;
F_14 ( V_20 , V_23 , V_24 , V_28 ) ;
F_15 ( & V_30 ) ;
if ( V_26 != 0 || V_27 != V_22 -> V_32 ) {
F_16 ( & V_22 -> V_33 , V_23 ,
V_24 , V_25 ,
V_26 , V_27 ) ;
} else
F_17 ( & V_22 -> V_33 , V_23 , V_24 , V_25 ) ;
V_34:
F_18 (vma, &vm->inactive_list, vm_link) {
if ( F_8 ( V_13 , & V_30 ) )
goto V_35;
}
if ( V_28 & V_36 )
goto V_37;
F_18 (vma, &vm->active_list, vm_link) {
if ( F_8 ( V_13 , & V_30 ) )
goto V_35;
}
V_37:
while ( ! F_10 ( & V_30 ) ) {
V_13 = F_19 ( & V_30 ,
struct V_12 ,
V_17 ) ;
V_9 = F_20 ( & V_13 -> V_18 ) ;
F_21 ( V_9 ) ;
F_22 ( & V_13 -> V_17 ) ;
}
if ( V_28 & V_36 )
return - V_38 ;
if ( V_31 ++ == 0 ) {
struct V_1 * V_2 = F_23 ( V_20 ) ;
if ( F_24 ( V_22 ) ) {
V_9 = F_1 ( V_2 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_25 ( V_2 ) ;
if ( V_9 )
return V_9 ;
F_26 ( V_2 ) ;
goto V_34;
}
return F_27 ( V_20 ) ? - V_39 : - V_38 ;
V_35:
F_15 ( & V_29 ) ;
while ( ! F_10 ( & V_30 ) ) {
V_13 = F_19 ( & V_30 ,
struct V_12 ,
V_17 ) ;
if ( F_20 ( & V_13 -> V_18 ) ) {
F_28 ( & V_13 -> V_17 , & V_29 ) ;
F_29 ( & V_13 -> V_40 -> V_41 ) ;
continue;
}
F_22 ( & V_13 -> V_17 ) ;
}
while ( ! F_10 ( & V_29 ) ) {
struct V_42 * V_40 ;
V_13 = F_19 ( & V_29 ,
struct V_12 ,
V_17 ) ;
V_40 = & V_13 -> V_40 -> V_41 ;
F_22 ( & V_13 -> V_17 ) ;
if ( V_9 == 0 )
V_9 = F_30 ( V_13 ) ;
F_31 ( V_40 ) ;
}
return V_9 ;
}
int
F_32 ( struct V_12 * V_43 )
{
struct V_44 * V_18 , * V_45 ;
F_33 (node, next,
&target->vm->mm.head_node.node_list,
node_list) {
struct V_12 * V_13 ;
int V_9 ;
if ( V_18 -> V_26 + V_18 -> V_46 <= V_43 -> V_18 . V_26 )
continue;
if ( V_18 -> V_26 >= V_43 -> V_18 . V_26 + V_43 -> V_18 . V_46 )
break;
V_13 = F_34 ( V_18 , F_35 ( * V_13 ) , V_18 ) ;
if ( V_13 -> V_16 ) {
if ( ! V_13 -> V_47 || ( V_13 -> V_16 > 1 ) )
return - V_48 ;
if ( V_13 -> V_47 -> V_28 & V_49 )
return - V_50 ;
return - V_38 ;
}
V_9 = F_30 ( V_13 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
int F_36 ( struct V_21 * V_22 , bool V_51 )
{
struct V_12 * V_13 , * V_45 ;
int V_9 ;
F_9 ( ! F_37 ( & V_22 -> V_20 -> V_52 ) ) ;
F_38 ( V_22 ) ;
if ( V_51 ) {
struct V_1 * V_2 = F_23 ( V_22 -> V_20 ) ;
if ( F_24 ( V_22 ) ) {
V_9 = F_1 ( V_2 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_25 ( V_2 ) ;
if ( V_9 )
return V_9 ;
F_26 ( V_2 ) ;
F_9 ( ! F_10 ( & V_22 -> V_53 ) ) ;
}
F_33 (vma, next, &vm->inactive_list, vm_link)
if ( V_13 -> V_16 == 0 )
F_9 ( F_30 ( V_13 ) ) ;
return 0 ;
}
