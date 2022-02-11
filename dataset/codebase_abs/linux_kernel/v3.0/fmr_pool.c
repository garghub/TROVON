static inline T_1 F_1 ( T_2 V_1 )
{
return F_2 ( ( T_1 ) V_1 , ( T_1 ) ( V_1 >> 32 ) , 0 ) &
( V_2 - 1 ) ;
}
static inline struct V_3 * F_3 ( struct V_4 * V_5 ,
T_2 * V_6 ,
int V_7 ,
T_2 V_8 )
{
struct V_9 * V_10 ;
struct V_3 * V_11 ;
struct V_12 * V_13 ;
if ( ! V_5 -> V_14 )
return NULL ;
V_10 = V_5 -> V_14 + F_1 ( * V_6 ) ;
F_4 (fmr, pos, bucket, cache_node)
if ( V_8 == V_11 -> V_8 &&
V_7 == V_11 -> V_7 &&
! memcmp ( V_6 , V_11 -> V_6 ,
V_7 * sizeof *V_6 ) )
return V_11 ;
return NULL ;
}
static void F_5 ( struct V_4 * V_5 )
{
int V_15 ;
struct V_3 * V_11 ;
F_6 ( V_16 ) ;
F_6 ( V_17 ) ;
F_7 ( & V_5 -> V_18 ) ;
F_8 (fmr, &pool->dirty_list, list) {
F_9 ( & V_11 -> V_19 ) ;
V_11 -> V_20 = 0 ;
F_10 ( & V_11 -> V_11 -> V_21 , & V_17 ) ;
#ifdef F_11
if ( V_11 -> V_22 != 0 ) {
F_12 (KERN_WARNING PFX L_1 ,
fmr, fmr->ref_count) ;
}
#endif
}
F_13 ( & V_5 -> V_23 , & V_16 ) ;
V_5 -> V_24 = 0 ;
F_14 ( & V_5 -> V_18 ) ;
if ( F_15 ( & V_16 ) ) {
return;
}
V_15 = F_16 ( & V_17 ) ;
if ( V_15 )
F_12 (KERN_WARNING PFX L_2 , ret) ;
F_7 ( & V_5 -> V_18 ) ;
F_17 ( & V_16 , & V_5 -> V_25 ) ;
F_14 ( & V_5 -> V_18 ) ;
}
static int F_18 ( void * V_26 )
{
struct V_4 * V_5 = V_26 ;
do {
if ( F_19 ( & V_5 -> V_27 ) - F_19 ( & V_5 -> V_28 ) < 0 ) {
F_5 ( V_5 ) ;
F_20 ( & V_5 -> V_27 ) ;
F_21 ( & V_5 -> V_29 ) ;
if ( V_5 -> V_30 )
V_5 -> V_30 ( V_5 , V_5 -> V_31 ) ;
}
F_22 ( V_32 ) ;
if ( F_19 ( & V_5 -> V_27 ) - F_19 ( & V_5 -> V_28 ) >= 0 &&
! F_23 () )
F_24 () ;
F_25 ( V_33 ) ;
} while ( ! F_23 () );
return 0 ;
}
struct V_4 * F_26 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 ;
struct V_4 * V_5 ;
struct V_40 * V_41 ;
int V_42 ;
int V_15 ;
int V_43 ;
if ( ! V_37 )
return F_27 ( - V_44 ) ;
V_39 = V_35 -> V_39 ;
if ( ! V_39 -> V_45 || ! V_39 -> V_46 ||
! V_39 -> V_47 || ! V_39 -> V_48 ) {
F_12 (KERN_INFO PFX L_3 ,
device->name) ;
return F_27 ( - V_49 ) ;
}
V_41 = F_28 ( sizeof *V_41 , V_50 ) ;
if ( ! V_41 ) {
F_12 (KERN_WARNING PFX L_4 ) ;
return F_27 ( - V_51 ) ;
}
V_15 = F_29 ( V_39 , V_41 ) ;
if ( V_15 ) {
F_12 (KERN_WARNING PFX L_5 , ret) ;
F_30 ( V_41 ) ;
return F_27 ( V_15 ) ;
}
if ( ! V_41 -> V_52 )
V_43 = V_53 ;
else
V_43 = V_41 -> V_52 ;
F_30 ( V_41 ) ;
V_5 = F_28 ( sizeof *V_5 , V_50 ) ;
if ( ! V_5 ) {
F_12 (KERN_WARNING PFX L_6 ) ;
return F_27 ( - V_51 ) ;
}
V_5 -> V_14 = NULL ;
V_5 -> V_30 = V_37 -> V_30 ;
V_5 -> V_31 = V_37 -> V_31 ;
F_31 ( & V_5 -> V_25 ) ;
F_31 ( & V_5 -> V_23 ) ;
if ( V_37 -> V_54 ) {
V_5 -> V_14 =
F_28 ( V_2 * sizeof * V_5 -> V_14 ,
V_50 ) ;
if ( ! V_5 -> V_14 ) {
F_12 (KERN_WARNING PFX L_7 ) ;
V_15 = - V_51 ;
goto V_55;
}
for ( V_42 = 0 ; V_42 < V_2 ; ++ V_42 )
F_32 ( V_5 -> V_14 + V_42 ) ;
}
V_5 -> V_56 = 0 ;
V_5 -> V_57 = V_37 -> V_58 ;
V_5 -> V_43 = V_43 ;
V_5 -> V_59 = V_37 -> V_59 ;
V_5 -> V_24 = 0 ;
F_33 ( & V_5 -> V_18 ) ;
F_34 ( & V_5 -> V_28 , 0 ) ;
F_34 ( & V_5 -> V_27 , 0 ) ;
F_35 ( & V_5 -> V_29 ) ;
V_5 -> V_60 = F_36 ( F_18 ,
V_5 ,
L_8 ,
V_39 -> V_61 ) ;
if ( F_37 ( V_5 -> V_60 ) ) {
F_12 (KERN_WARNING PFX L_9 ) ;
V_15 = F_38 ( V_5 -> V_60 ) ;
goto V_55;
}
{
struct V_3 * V_11 ;
struct V_62 V_63 = {
. V_57 = V_37 -> V_58 ,
. V_64 = V_5 -> V_43 ,
. V_65 = V_37 -> V_65
} ;
int V_66 = sizeof *V_11 ;
if ( V_5 -> V_14 )
V_66 += V_37 -> V_58 * sizeof ( T_2 ) ;
for ( V_42 = 0 ; V_42 < V_37 -> V_56 ; ++ V_42 ) {
V_11 = F_28 ( V_66 , V_50 ) ;
if ( ! V_11 ) {
F_12 (KERN_WARNING PFX L_10
L_11 , i) ;
goto V_67;
}
V_11 -> V_5 = V_5 ;
V_11 -> V_20 = 0 ;
V_11 -> V_22 = 0 ;
F_39 ( & V_11 -> V_19 ) ;
V_11 -> V_11 = F_40 ( V_35 , V_37 -> V_68 , & V_63 ) ;
if ( F_37 ( V_11 -> V_11 ) ) {
F_12 (KERN_WARNING PFX L_12
L_13 , i) ;
F_30 ( V_11 ) ;
goto V_67;
}
F_10 ( & V_11 -> V_21 , & V_5 -> V_25 ) ;
++ V_5 -> V_56 ;
}
}
return V_5 ;
V_55:
F_30 ( V_5 -> V_14 ) ;
F_30 ( V_5 ) ;
return F_27 ( V_15 ) ;
V_67:
F_41 ( V_5 ) ;
return F_27 ( - V_51 ) ;
}
void F_41 ( struct V_4 * V_5 )
{
struct V_3 * V_11 ;
struct V_3 * V_69 ;
F_6 ( V_17 ) ;
int V_42 ;
F_42 ( V_5 -> V_60 ) ;
F_5 ( V_5 ) ;
V_42 = 0 ;
F_43 (fmr, tmp, &pool->free_list, list) {
if ( V_11 -> V_20 ) {
F_31 ( & V_17 ) ;
F_10 ( & V_11 -> V_11 -> V_21 , & V_17 ) ;
F_16 ( & V_17 ) ;
}
F_44 ( V_11 -> V_11 ) ;
F_45 ( & V_11 -> V_21 ) ;
F_30 ( V_11 ) ;
++ V_42 ;
}
if ( V_42 < V_5 -> V_56 )
F_12 (KERN_WARNING PFX L_14 ,
pool->pool_size - i) ;
F_30 ( V_5 -> V_14 ) ;
F_30 ( V_5 ) ;
}
int F_46 ( struct V_4 * V_5 )
{
int V_70 ;
struct V_3 * V_11 , * V_71 ;
F_7 ( & V_5 -> V_18 ) ;
F_43 (fmr, next, &pool->free_list, list) {
if ( V_11 -> V_20 > 0 )
F_47 ( & V_11 -> V_21 , & V_5 -> V_23 ) ;
}
F_14 ( & V_5 -> V_18 ) ;
V_70 = F_48 ( & V_5 -> V_28 ) ;
F_49 ( V_5 -> V_60 ) ;
if ( F_50 ( V_5 -> V_29 ,
F_19 ( & V_5 -> V_27 ) - V_70 >= 0 ) )
return - V_72 ;
return 0 ;
}
struct V_3 * F_51 ( struct V_4 * V_73 ,
T_2 * V_6 ,
int V_74 ,
T_2 V_8 )
{
struct V_4 * V_5 = V_73 ;
struct V_3 * V_11 ;
unsigned long V_75 ;
int V_76 ;
if ( V_74 < 1 || V_74 > V_5 -> V_57 )
return F_27 ( - V_44 ) ;
F_52 ( & V_5 -> V_18 , V_75 ) ;
V_11 = F_3 ( V_5 ,
V_6 ,
V_74 ,
V_8 ) ;
if ( V_11 ) {
++ V_11 -> V_22 ;
if ( V_11 -> V_22 == 1 ) {
F_45 ( & V_11 -> V_21 ) ;
}
F_53 ( & V_5 -> V_18 , V_75 ) ;
return V_11 ;
}
if ( F_15 ( & V_5 -> V_25 ) ) {
F_53 ( & V_5 -> V_18 , V_75 ) ;
return F_27 ( - V_77 ) ;
}
V_11 = F_54 ( V_5 -> V_25 . V_71 , struct V_3 , V_21 ) ;
F_45 ( & V_11 -> V_21 ) ;
F_9 ( & V_11 -> V_19 ) ;
F_53 ( & V_5 -> V_18 , V_75 ) ;
V_76 = F_55 ( V_11 -> V_11 , V_6 , V_74 ,
V_8 ) ;
if ( V_76 ) {
F_52 ( & V_5 -> V_18 , V_75 ) ;
F_56 ( & V_11 -> V_21 , & V_5 -> V_25 ) ;
F_53 ( & V_5 -> V_18 , V_75 ) ;
F_12 (KERN_WARNING PFX L_15 , result) ;
return F_27 ( V_76 ) ;
}
++ V_11 -> V_20 ;
V_11 -> V_22 = 1 ;
if ( V_5 -> V_14 ) {
V_11 -> V_8 = V_8 ;
V_11 -> V_7 = V_74 ;
memcpy ( V_11 -> V_6 , V_6 , V_74 * sizeof( * V_6 ) ) ;
F_52 ( & V_5 -> V_18 , V_75 ) ;
F_57 ( & V_11 -> V_19 ,
V_5 -> V_14 + F_1 ( V_11 -> V_6 [ 0 ] ) ) ;
F_53 ( & V_5 -> V_18 , V_75 ) ;
}
return V_11 ;
}
int F_58 ( struct V_3 * V_11 )
{
struct V_4 * V_5 ;
unsigned long V_75 ;
V_5 = V_11 -> V_5 ;
F_52 ( & V_5 -> V_18 , V_75 ) ;
-- V_11 -> V_22 ;
if ( ! V_11 -> V_22 ) {
if ( V_11 -> V_20 < V_5 -> V_43 ) {
F_10 ( & V_11 -> V_21 , & V_5 -> V_25 ) ;
} else {
F_10 ( & V_11 -> V_21 , & V_5 -> V_23 ) ;
if ( ++ V_5 -> V_24 >= V_5 -> V_59 ) {
F_20 ( & V_5 -> V_28 ) ;
F_49 ( V_5 -> V_60 ) ;
}
}
}
#ifdef F_11
if ( V_11 -> V_22 < 0 )
F_12 (KERN_WARNING PFX L_16 ,
fmr, fmr->ref_count) ;
#endif
F_53 ( & V_5 -> V_18 , V_75 ) ;
return 0 ;
}
