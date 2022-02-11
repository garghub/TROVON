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
static int F_4 ( struct V_1 * V_14 )
{
int V_15 ;
V_15 = F_5 ( V_14 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_6 ( V_14 ,
V_16 |
V_17 ) ;
if ( V_15 )
return V_15 ;
return 0 ;
}
static bool
F_7 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
unsigned int V_22 ,
struct V_23 * V_24 )
{
if ( F_8 ( V_21 ) )
return false ;
if ( V_22 & V_25 && ! F_9 ( & V_21 -> V_26 -> V_27 ) )
return false ;
F_10 ( & V_21 -> V_28 , V_24 ) ;
return F_11 ( V_19 , & V_21 -> V_29 ) ;
}
int
F_12 ( struct V_30 * V_31 ,
T_1 V_32 , T_1 V_33 ,
unsigned V_34 ,
T_1 V_35 , T_1 V_36 ,
unsigned V_22 )
{
struct V_1 * V_2 = V_31 -> V_14 ;
struct V_18 V_19 ;
struct V_23 V_37 ;
struct V_23 * V_38 [] = {
& V_31 -> V_39 ,
& V_31 -> V_40 ,
NULL ,
} , * * V_41 ;
struct V_20 * V_21 , * V_42 ;
struct V_43 * V_29 ;
enum V_44 V_45 ;
int V_46 ;
F_13 ( & V_31 -> V_14 -> V_47 . V_48 ) ;
F_14 ( V_31 , V_32 , V_33 , V_22 ) ;
V_45 = V_49 ;
if ( V_22 & V_50 )
V_45 = V_51 ;
if ( V_22 & V_52 )
V_45 = V_53 ;
F_15 ( & V_19 , & V_31 -> V_54 ,
V_32 , V_33 , V_34 ,
V_35 , V_36 , V_45 ) ;
if ( ! ( V_22 & V_55 ) )
F_16 ( V_2 ) ;
else
V_38 [ 1 ] = NULL ;
V_56:
F_17 ( & V_37 ) ;
V_41 = V_38 ;
do {
F_18 (vma, *phase, vm_link)
if ( F_7 ( & V_19 , V_21 , V_22 , & V_37 ) )
goto V_57;
} while ( * ++ V_41 );
F_19 (vma, next, &eviction_list, evict_link) {
V_46 = F_20 ( & V_19 , & V_21 -> V_29 ) ;
F_21 ( V_46 ) ;
}
if ( ! F_22 ( V_31 ) || V_22 & V_55 )
return - V_58 ;
if ( F_1 ( V_2 ) ) {
return F_23 ( V_2 ) ? - V_59 : - V_58 ;
}
V_46 = F_4 ( V_2 ) ;
if ( V_46 )
return V_46 ;
goto V_56;
V_57:
F_19 (vma, next, &eviction_list, evict_link) {
if ( F_20 ( & V_19 , & V_21 -> V_29 ) )
F_24 ( V_21 ) ;
else
F_25 ( & V_21 -> V_28 ) ;
}
V_46 = 0 ;
F_19 (vma, next, &eviction_list, evict_link) {
F_26 ( V_21 ) ;
if ( V_46 == 0 )
V_46 = F_27 ( V_21 ) ;
}
while ( V_46 == 0 && ( V_29 = F_28 ( & V_19 ) ) ) {
V_21 = F_29 ( V_29 , struct V_20 , V_29 ) ;
V_46 = F_27 ( V_21 ) ;
}
return V_46 ;
}
int F_30 ( struct V_30 * V_31 ,
struct V_43 * V_60 ,
unsigned int V_22 )
{
F_31 ( V_37 ) ;
struct V_43 * V_29 ;
T_1 V_35 = V_60 -> V_35 ;
T_1 V_36 = V_35 + V_60 -> V_61 ;
struct V_20 * V_21 , * V_42 ;
bool V_62 ;
int V_46 = 0 ;
F_13 ( & V_31 -> V_14 -> V_47 . V_48 ) ;
F_32 ( ! F_33 ( V_35 , V_63 ) ) ;
F_32 ( ! F_33 ( V_36 , V_63 ) ) ;
F_34 ( V_31 , V_60 , V_22 ) ;
if ( ! ( V_22 & V_55 ) )
F_16 ( V_31 -> V_14 ) ;
V_62 = V_31 -> V_54 . V_64 ;
if ( V_62 ) {
if ( V_35 )
V_35 -= V_63 ;
V_36 += V_63 ;
}
F_32 ( V_35 >= V_36 ) ;
F_35 (node, &vm->mm, start, end) {
if ( V_29 -> V_65 == V_66 ) {
V_46 = - V_58 ;
break;
}
F_32 ( ! V_29 -> V_67 ) ;
V_21 = F_29 ( V_29 , F_36 ( * V_21 ) , V_29 ) ;
if ( V_62 ) {
if ( V_29 -> V_35 + V_29 -> V_61 == V_60 -> V_35 ) {
if ( V_29 -> V_65 == V_60 -> V_65 )
continue;
}
if ( V_29 -> V_35 == V_60 -> V_35 + V_60 -> V_61 ) {
if ( V_29 -> V_65 == V_60 -> V_65 )
continue;
}
}
if ( V_22 & V_55 &&
( F_8 ( V_21 ) || F_37 ( V_21 ) ) ) {
V_46 = - V_58 ;
break;
}
if ( F_8 ( V_21 ) ) {
V_46 = - V_58 ;
if ( V_21 -> V_68 &&
V_21 -> V_68 -> V_22 & V_69 )
V_46 = - V_70 ;
break;
}
F_24 ( V_21 ) ;
F_10 ( & V_21 -> V_28 , & V_37 ) ;
}
F_19 (vma, next, &eviction_list, evict_link) {
F_26 ( V_21 ) ;
if ( V_46 == 0 )
V_46 = F_27 ( V_21 ) ;
}
return V_46 ;
}
int F_38 ( struct V_30 * V_31 )
{
struct V_23 * V_38 [] = {
& V_31 -> V_39 ,
& V_31 -> V_40 ,
NULL
} , * * V_41 ;
struct V_23 V_37 ;
struct V_20 * V_21 , * V_42 ;
int V_46 ;
F_13 ( & V_31 -> V_14 -> V_47 . V_48 ) ;
F_39 ( V_31 ) ;
if ( F_22 ( V_31 ) ) {
V_46 = F_4 ( V_31 -> V_14 ) ;
if ( V_46 )
return V_46 ;
}
F_17 ( & V_37 ) ;
V_41 = V_38 ;
do {
F_18 (vma, *phase, vm_link) {
if ( F_8 ( V_21 ) )
continue;
F_24 ( V_21 ) ;
F_10 ( & V_21 -> V_28 , & V_37 ) ;
}
} while ( * ++ V_41 );
V_46 = 0 ;
F_19 (vma, next, &eviction_list, evict_link) {
F_26 ( V_21 ) ;
if ( V_46 == 0 )
V_46 = F_27 ( V_21 ) ;
}
return V_46 ;
}
