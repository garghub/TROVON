static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
enum V_7 V_8 ;
F_2 (engine, dev_priv, id) {
struct V_9 * V_10 ;
V_10 = & V_4 -> V_11 . V_12 . V_6 [ V_6 -> V_8 ] ;
if ( F_3 ( & V_10 -> V_13 ) )
return false ;
}
return true ;
}
static bool
F_4 ( struct V_14 * V_15 , unsigned int V_16 , struct V_17 * V_18 )
{
if ( F_5 ( V_15 ) )
return false ;
if ( F_6 ( ! F_7 ( & V_15 -> V_19 ) ) )
return false ;
if ( V_16 & V_20 && ! F_7 ( & V_15 -> V_21 -> V_22 ) )
return false ;
F_8 ( & V_15 -> V_19 , V_18 ) ;
return F_9 ( & V_15 -> V_23 ) ;
}
int
F_10 ( struct V_24 * V_25 ,
T_1 V_26 , T_1 V_27 ,
unsigned V_28 ,
T_1 V_29 , T_1 V_30 ,
unsigned V_16 )
{
struct V_1 * V_2 = F_11 ( V_25 -> V_31 ) ;
struct V_17 V_32 ;
struct V_17 * V_33 [] = {
& V_25 -> V_34 ,
& V_25 -> V_35 ,
NULL ,
} , * * V_36 ;
struct V_14 * V_15 , * V_37 ;
int V_38 ;
F_12 ( & V_25 -> V_31 -> V_39 ) ;
F_13 ( V_25 , V_26 , V_27 , V_16 ) ;
if ( V_29 != 0 || V_30 != V_25 -> V_40 ) {
F_14 ( & V_25 -> V_41 , V_26 ,
V_27 , V_28 ,
V_29 , V_30 ) ;
} else
F_15 ( & V_25 -> V_41 , V_26 , V_27 , V_28 ) ;
if ( V_16 & V_42 )
V_33 [ 1 ] = NULL ;
V_43:
F_16 ( & V_32 ) ;
V_36 = V_33 ;
do {
F_17 (vma, *phase, vm_link)
if ( F_4 ( V_15 , V_16 , & V_32 ) )
goto V_44;
} while ( * ++ V_36 );
F_18 (vma, next, &eviction_list, exec_list) {
V_38 = F_19 ( & V_15 -> V_23 ) ;
F_20 ( V_38 ) ;
F_16 ( & V_15 -> V_19 ) ;
}
if ( ! F_21 ( V_25 ) || V_16 & V_42 )
return - V_45 ;
if ( F_1 ( V_2 ) ) {
return F_22 ( V_25 -> V_31 ) ? - V_46 : - V_45 ;
}
V_38 = F_23 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_24 ( V_2 ,
V_47 |
V_48 ) ;
if ( V_38 )
return V_38 ;
F_25 ( V_2 ) ;
goto V_43;
V_44:
F_18 (vma, next, &eviction_list, exec_list) {
if ( F_19 ( & V_15 -> V_23 ) )
F_26 ( V_15 ) ;
else
F_27 ( & V_15 -> V_19 ) ;
}
V_38 = 0 ;
while ( ! F_7 ( & V_32 ) ) {
V_15 = F_28 ( & V_32 ,
struct V_14 ,
V_19 ) ;
F_27 ( & V_15 -> V_19 ) ;
F_29 ( V_15 ) ;
if ( V_38 == 0 )
V_38 = F_30 ( V_15 ) ;
}
return V_38 ;
}
int
F_31 ( struct V_14 * V_49 )
{
struct V_50 * V_23 , * V_37 ;
F_12 ( & V_49 -> V_25 -> V_31 -> V_39 ) ;
F_18 (node, next,
&target->vm->mm.head_node.node_list,
node_list) {
struct V_14 * V_15 ;
int V_38 ;
if ( V_23 -> V_29 + V_23 -> V_51 <= V_49 -> V_23 . V_29 )
continue;
if ( V_23 -> V_29 >= V_49 -> V_23 . V_29 + V_49 -> V_23 . V_51 )
break;
V_15 = F_32 ( V_23 , F_33 ( * V_15 ) , V_23 ) ;
if ( F_5 ( V_15 ) ) {
if ( ! V_15 -> V_52 || F_34 ( V_15 ) > 1 )
return - V_53 ;
if ( V_15 -> V_52 -> V_16 & V_54 )
return - V_55 ;
return - V_45 ;
}
V_38 = F_30 ( V_15 ) ;
if ( V_38 )
return V_38 ;
}
return 0 ;
}
int F_35 ( struct V_24 * V_25 , bool V_56 )
{
struct V_14 * V_15 , * V_37 ;
int V_38 ;
F_12 ( & V_25 -> V_31 -> V_39 ) ;
F_36 ( V_25 ) ;
if ( V_56 ) {
struct V_1 * V_2 = F_11 ( V_25 -> V_31 ) ;
if ( F_21 ( V_25 ) ) {
V_38 = F_23 ( V_2 ) ;
if ( V_38 )
return V_38 ;
}
V_38 = F_24 ( V_2 ,
V_47 |
V_48 ) ;
if ( V_38 )
return V_38 ;
F_25 ( V_2 ) ;
F_6 ( ! F_7 ( & V_25 -> V_35 ) ) ;
}
F_18 (vma, next, &vm->inactive_list, vm_link)
if ( ! F_5 ( V_15 ) )
F_6 ( F_30 ( V_15 ) ) ;
return 0 ;
}
