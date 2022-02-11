static bool
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 (engine, dev_priv) {
if ( F_3 ( V_4 ) )
return false ;
}
return true ;
}
static bool
F_4 ( struct V_5 * V_6 , unsigned int V_7 , struct V_8 * V_9 )
{
if ( F_5 ( V_6 ) )
return false ;
if ( F_6 ( ! F_7 ( & V_6 -> V_10 ) ) )
return false ;
if ( V_7 & V_11 && V_6 -> V_12 -> V_13 )
return false ;
F_8 ( & V_6 -> V_10 , V_9 ) ;
return F_9 ( & V_6 -> V_14 ) ;
}
int
F_10 ( struct V_15 * V_16 ,
T_1 V_17 , T_1 V_18 ,
unsigned V_19 ,
T_1 V_20 , T_1 V_21 ,
unsigned V_7 )
{
struct V_1 * V_2 = F_11 ( V_16 -> V_22 ) ;
struct V_8 V_23 ;
struct V_8 * V_24 [] = {
& V_16 -> V_25 ,
& V_16 -> V_26 ,
NULL ,
} , * * V_27 ;
struct V_5 * V_6 , * V_28 ;
int V_29 ;
F_12 ( V_16 , V_17 , V_18 , V_7 ) ;
if ( V_20 != 0 || V_21 != V_16 -> V_30 ) {
F_13 ( & V_16 -> V_31 , V_17 ,
V_18 , V_19 ,
V_20 , V_21 ) ;
} else
F_14 ( & V_16 -> V_31 , V_17 , V_18 , V_19 ) ;
if ( V_7 & V_32 )
V_24 [ 1 ] = NULL ;
V_33:
F_15 ( & V_23 ) ;
V_27 = V_24 ;
do {
F_16 (vma, *phase, vm_link)
if ( F_4 ( V_6 , V_7 , & V_23 ) )
goto V_34;
} while ( * ++ V_27 );
F_17 (vma, next, &eviction_list, exec_list) {
V_29 = F_18 ( & V_6 -> V_14 ) ;
F_19 ( V_29 ) ;
F_15 ( & V_6 -> V_10 ) ;
}
if ( ! F_20 ( V_16 ) || V_7 & V_32 )
return - V_35 ;
if ( F_1 ( V_2 ) ) {
return F_21 ( V_16 -> V_22 ) ? - V_36 : - V_35 ;
}
V_29 = F_22 ( V_2 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_23 ( V_2 ,
V_37 |
V_38 ) ;
if ( V_29 )
return V_29 ;
F_24 ( V_2 ) ;
goto V_33;
V_34:
F_17 (vma, next, &eviction_list, exec_list) {
if ( F_18 ( & V_6 -> V_14 ) )
F_25 ( V_6 ) ;
else
F_26 ( & V_6 -> V_10 ) ;
}
while ( ! F_7 ( & V_23 ) ) {
V_6 = F_27 ( & V_23 ,
struct V_5 ,
V_10 ) ;
F_26 ( & V_6 -> V_10 ) ;
F_28 ( V_6 ) ;
if ( V_29 == 0 )
V_29 = F_29 ( V_6 ) ;
}
return V_29 ;
}
int
F_30 ( struct V_5 * V_39 )
{
struct V_40 * V_14 , * V_28 ;
F_17 (node, next,
&target->vm->mm.head_node.node_list,
node_list) {
struct V_5 * V_6 ;
int V_29 ;
if ( V_14 -> V_20 + V_14 -> V_41 <= V_39 -> V_14 . V_20 )
continue;
if ( V_14 -> V_20 >= V_39 -> V_14 . V_20 + V_39 -> V_14 . V_41 )
break;
V_6 = F_31 ( V_14 , F_32 ( * V_6 ) , V_14 ) ;
if ( F_5 ( V_6 ) ) {
if ( ! V_6 -> V_42 || F_33 ( V_6 ) > 1 )
return - V_43 ;
if ( V_6 -> V_42 -> V_7 & V_44 )
return - V_45 ;
return - V_35 ;
}
V_29 = F_29 ( V_6 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
int F_34 ( struct V_15 * V_16 , bool V_46 )
{
struct V_5 * V_6 , * V_28 ;
int V_29 ;
F_6 ( ! F_35 ( & V_16 -> V_22 -> V_47 ) ) ;
F_36 ( V_16 ) ;
if ( V_46 ) {
struct V_1 * V_2 = F_11 ( V_16 -> V_22 ) ;
if ( F_20 ( V_16 ) ) {
V_29 = F_22 ( V_2 ) ;
if ( V_29 )
return V_29 ;
}
V_29 = F_23 ( V_2 ,
V_37 |
V_38 ) ;
if ( V_29 )
return V_29 ;
F_24 ( V_2 ) ;
F_6 ( ! F_7 ( & V_16 -> V_26 ) ) ;
}
F_17 (vma, next, &vm->inactive_list, vm_link)
if ( ! F_5 ( V_6 ) )
F_6 ( F_29 ( V_6 ) ) ;
return 0 ;
}
