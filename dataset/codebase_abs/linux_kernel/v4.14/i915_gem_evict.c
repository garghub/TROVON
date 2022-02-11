static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
enum V_5 V_6 ;
if ( V_2 -> V_7 . V_8 )
return false ;
F_2 (engine, i915, id) {
if ( V_4 -> V_9 != V_2 -> V_10 )
return false ;
}
return true ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_4 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_5 ( V_2 ,
V_12 |
V_13 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static bool
F_6 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int V_18 ,
struct V_19 * V_20 )
{
if ( F_7 ( V_17 ) )
return false ;
if ( V_18 & V_21 && ! F_8 ( & V_17 -> V_22 -> V_23 ) )
return false ;
F_9 ( & V_17 -> V_24 , V_20 ) ;
return F_10 ( V_15 , & V_17 -> V_25 ) ;
}
int
F_11 ( struct V_26 * V_27 ,
T_1 V_28 , T_1 V_29 ,
unsigned V_30 ,
T_1 V_31 , T_1 V_32 ,
unsigned V_18 )
{
struct V_1 * V_33 = V_27 -> V_2 ;
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
F_12 ( & V_27 -> V_2 -> V_44 . V_45 ) ;
F_13 ( V_27 , V_28 , V_29 , V_18 ) ;
V_42 = V_46 ;
if ( V_18 & V_47 )
V_42 = V_48 ;
if ( V_18 & V_49 )
V_42 = V_50 ;
F_14 ( & V_15 , & V_27 -> V_51 ,
V_28 , V_29 , V_30 ,
V_31 , V_32 , V_42 ) ;
if ( ! ( V_18 & V_52 ) )
F_15 ( V_33 ) ;
else
V_35 [ 1 ] = NULL ;
V_53:
F_16 ( & V_34 ) ;
V_38 = V_35 ;
do {
F_17 (vma, *phase, vm_link)
if ( F_6 ( & V_15 , V_17 , V_18 , & V_34 ) )
goto V_54;
} while ( * ++ V_38 );
F_18 (vma, next, &eviction_list, evict_link) {
V_43 = F_19 ( & V_15 , & V_17 -> V_25 ) ;
F_20 ( V_43 ) ;
}
if ( ! F_21 ( V_27 ) || V_18 & V_52 )
return - V_55 ;
if ( ! F_1 ( V_33 ) ) {
V_43 = F_3 ( V_33 ) ;
if ( V_43 )
return V_43 ;
goto V_53;
}
return F_22 ( V_33 ) ? - V_56 : - V_55 ;
V_54:
F_18 (vma, next, &eviction_list, evict_link) {
if ( F_19 ( & V_15 , & V_17 -> V_25 ) )
F_23 ( V_17 ) ;
else
F_24 ( & V_17 -> V_24 ) ;
}
V_43 = 0 ;
F_18 (vma, next, &eviction_list, evict_link) {
F_25 ( V_17 ) ;
if ( V_43 == 0 )
V_43 = F_26 ( V_17 ) ;
}
while ( V_43 == 0 && ( V_25 = F_27 ( & V_15 ) ) ) {
V_17 = F_28 ( V_25 , struct V_16 , V_25 ) ;
V_43 = F_26 ( V_17 ) ;
}
return V_43 ;
}
int F_29 ( struct V_26 * V_27 ,
struct V_40 * V_57 ,
unsigned int V_18 )
{
F_30 ( V_34 ) ;
struct V_40 * V_25 ;
T_1 V_31 = V_57 -> V_31 ;
T_1 V_32 = V_31 + V_57 -> V_58 ;
struct V_16 * V_17 , * V_39 ;
bool V_59 ;
int V_43 = 0 ;
F_12 ( & V_27 -> V_2 -> V_44 . V_45 ) ;
F_31 ( ! F_32 ( V_31 , V_60 ) ) ;
F_31 ( ! F_32 ( V_32 , V_60 ) ) ;
F_33 ( V_27 , V_57 , V_18 ) ;
if ( ! ( V_18 & V_52 ) )
F_15 ( V_27 -> V_2 ) ;
V_59 = V_27 -> V_51 . V_61 ;
if ( V_59 ) {
if ( V_31 )
V_31 -= V_60 ;
V_32 += V_60 ;
}
F_31 ( V_31 >= V_32 ) ;
F_34 (node, &vm->mm, start, end) {
if ( V_25 -> V_62 == V_63 ) {
V_43 = - V_55 ;
break;
}
F_31 ( ! V_25 -> V_64 ) ;
V_17 = F_28 ( V_25 , F_35 ( * V_17 ) , V_25 ) ;
if ( V_59 ) {
if ( V_25 -> V_31 + V_25 -> V_58 == V_57 -> V_31 ) {
if ( V_25 -> V_62 == V_57 -> V_62 )
continue;
}
if ( V_25 -> V_31 == V_57 -> V_31 + V_57 -> V_58 ) {
if ( V_25 -> V_62 == V_57 -> V_62 )
continue;
}
}
if ( V_18 & V_52 &&
( F_7 ( V_17 ) || F_36 ( V_17 ) ) ) {
V_43 = - V_55 ;
break;
}
if ( F_7 ( V_17 ) ) {
V_43 = - V_55 ;
if ( V_17 -> V_65 &&
* V_17 -> V_65 & V_66 )
V_43 = - V_67 ;
break;
}
F_23 ( V_17 ) ;
F_9 ( & V_17 -> V_24 , & V_34 ) ;
}
F_18 (vma, next, &eviction_list, evict_link) {
F_25 ( V_17 ) ;
if ( V_43 == 0 )
V_43 = F_26 ( V_17 ) ;
}
return V_43 ;
}
int F_37 ( struct V_26 * V_27 )
{
struct V_19 * V_35 [] = {
& V_27 -> V_36 ,
& V_27 -> V_37 ,
NULL
} , * * V_38 ;
struct V_19 V_34 ;
struct V_16 * V_17 , * V_39 ;
int V_43 ;
F_12 ( & V_27 -> V_2 -> V_44 . V_45 ) ;
F_38 ( V_27 ) ;
if ( F_21 ( V_27 ) ) {
V_43 = F_3 ( V_27 -> V_2 ) ;
if ( V_43 )
return V_43 ;
}
F_16 ( & V_34 ) ;
V_38 = V_35 ;
do {
F_17 (vma, *phase, vm_link) {
if ( F_7 ( V_17 ) )
continue;
F_23 ( V_17 ) ;
F_9 ( & V_17 -> V_24 , & V_34 ) ;
}
} while ( * ++ V_38 );
V_43 = 0 ;
F_18 (vma, next, &eviction_list, evict_link) {
F_25 ( V_17 ) ;
if ( V_43 == 0 )
V_43 = F_26 ( V_17 ) ;
}
return V_43 ;
}
