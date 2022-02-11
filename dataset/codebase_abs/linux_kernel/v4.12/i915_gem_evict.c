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
F_4 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int V_18 ,
struct V_19 * V_20 )
{
if ( F_5 ( V_17 ) )
return false ;
if ( F_6 ( ! F_7 ( & V_17 -> V_21 ) ) )
return false ;
if ( V_18 & V_22 && ! F_7 ( & V_17 -> V_23 -> V_24 ) )
return false ;
F_8 ( & V_17 -> V_21 , V_20 ) ;
return F_9 ( V_15 , & V_17 -> V_25 ) ;
}
int
F_10 ( struct V_26 * V_27 ,
T_1 V_28 , T_1 V_29 ,
unsigned V_30 ,
T_1 V_31 , T_1 V_32 ,
unsigned V_18 )
{
struct V_1 * V_2 = V_27 -> V_33 ;
struct V_14 V_15 ;
struct V_19 V_34 ;
struct V_19 * V_35 [] = {
& V_27 -> V_36 ,
& V_27 -> V_37 ,
NULL ,
} , * * V_38 ;
struct V_16 * V_17 , * V_39 ;
struct V_40 * V_25 ;
enum V_41 V_42 ;
int V_43 ;
F_11 ( & V_27 -> V_33 -> V_44 . V_45 ) ;
F_12 ( V_27 , V_28 , V_29 , V_18 ) ;
V_42 = V_46 ;
if ( V_18 & V_47 )
V_42 = V_48 ;
if ( V_18 & V_49 )
V_42 = V_50 ;
F_13 ( & V_15 , & V_27 -> V_51 ,
V_28 , V_29 , V_30 ,
V_31 , V_32 , V_42 ) ;
if ( ! ( V_18 & V_52 ) )
F_14 ( V_2 ) ;
else
V_35 [ 1 ] = NULL ;
V_53:
F_15 ( & V_34 ) ;
V_38 = V_35 ;
do {
F_16 (vma, *phase, vm_link)
if ( F_4 ( & V_15 , V_17 , V_18 , & V_34 ) )
goto V_54;
} while ( * ++ V_38 );
F_17 (vma, next, &eviction_list, exec_list) {
V_43 = F_18 ( & V_15 , & V_17 -> V_25 ) ;
F_19 ( V_43 ) ;
F_15 ( & V_17 -> V_21 ) ;
}
if ( ! F_20 ( V_27 ) || V_18 & V_52 )
return - V_55 ;
if ( F_1 ( V_2 ) ) {
return F_21 ( V_2 ) ? - V_56 : - V_55 ;
}
V_43 = F_22 ( V_2 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_23 ( V_2 ,
V_57 |
V_58 ) ;
if ( V_43 )
return V_43 ;
goto V_53;
V_54:
F_17 (vma, next, &eviction_list, exec_list) {
if ( F_18 ( & V_15 , & V_17 -> V_25 ) )
F_24 ( V_17 ) ;
else
F_25 ( & V_17 -> V_21 ) ;
}
V_43 = 0 ;
while ( ! F_7 ( & V_34 ) ) {
V_17 = F_26 ( & V_34 ,
struct V_16 ,
V_21 ) ;
F_25 ( & V_17 -> V_21 ) ;
F_27 ( V_17 ) ;
if ( V_43 == 0 )
V_43 = F_28 ( V_17 ) ;
}
while ( V_43 == 0 && ( V_25 = F_29 ( & V_15 ) ) ) {
V_17 = F_30 ( V_25 , struct V_16 , V_25 ) ;
V_43 = F_28 ( V_17 ) ;
}
return V_43 ;
}
int F_31 ( struct V_26 * V_27 ,
struct V_40 * V_59 ,
unsigned int V_18 )
{
F_32 ( V_34 ) ;
struct V_40 * V_25 ;
T_1 V_31 = V_59 -> V_31 ;
T_1 V_32 = V_31 + V_59 -> V_60 ;
struct V_16 * V_17 , * V_39 ;
bool V_61 ;
int V_43 = 0 ;
F_11 ( & V_27 -> V_33 -> V_44 . V_45 ) ;
F_33 ( ! F_34 ( V_31 , V_62 ) ) ;
F_33 ( ! F_34 ( V_32 , V_62 ) ) ;
F_35 ( V_27 , V_59 , V_18 ) ;
if ( ! ( V_18 & V_52 ) )
F_14 ( V_27 -> V_33 ) ;
V_61 = V_27 -> V_51 . V_63 ;
if ( V_61 ) {
if ( V_31 )
V_31 -= V_62 ;
V_32 += V_62 ;
}
F_33 ( V_31 >= V_32 ) ;
F_36 (node, &vm->mm, start, end) {
if ( V_25 -> V_64 == V_65 ) {
V_43 = - V_55 ;
break;
}
F_33 ( ! V_25 -> V_66 ) ;
V_17 = F_30 ( V_25 , F_37 ( * V_17 ) , V_25 ) ;
if ( V_61 ) {
if ( V_25 -> V_31 + V_25 -> V_60 == V_59 -> V_31 ) {
if ( V_25 -> V_64 == V_59 -> V_64 )
continue;
}
if ( V_25 -> V_31 == V_59 -> V_31 + V_59 -> V_60 ) {
if ( V_25 -> V_64 == V_59 -> V_64 )
continue;
}
}
if ( V_18 & V_52 &&
( F_5 ( V_17 ) || F_38 ( V_17 ) ) ) {
V_43 = - V_55 ;
break;
}
if ( F_5 ( V_17 ) || ! F_7 ( & V_17 -> V_21 ) ) {
V_43 = - V_55 ;
if ( V_17 -> V_67 &&
V_17 -> V_67 -> V_18 & V_68 )
V_43 = - V_69 ;
break;
}
F_24 ( V_17 ) ;
F_8 ( & V_17 -> V_21 , & V_34 ) ;
}
F_17 (vma, next, &eviction_list, exec_list) {
F_25 ( & V_17 -> V_21 ) ;
F_27 ( V_17 ) ;
if ( V_43 == 0 )
V_43 = F_28 ( V_17 ) ;
}
return V_43 ;
}
int F_39 ( struct V_26 * V_27 , bool V_70 )
{
struct V_16 * V_17 , * V_39 ;
int V_43 ;
F_11 ( & V_27 -> V_33 -> V_44 . V_45 ) ;
F_40 ( V_27 ) ;
if ( V_70 ) {
struct V_1 * V_2 = V_27 -> V_33 ;
if ( F_20 ( V_27 ) ) {
V_43 = F_22 ( V_2 ) ;
if ( V_43 )
return V_43 ;
}
V_43 = F_23 ( V_2 ,
V_57 |
V_58 ) ;
if ( V_43 )
return V_43 ;
F_6 ( ! F_7 ( & V_27 -> V_37 ) ) ;
}
F_17 (vma, next, &vm->inactive_list, vm_link)
if ( ! F_5 ( V_17 ) )
F_6 ( F_28 ( V_17 ) ) ;
return 0 ;
}
