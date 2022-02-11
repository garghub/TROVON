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
if ( ! V_5 -> V_12 )
return NULL ;
V_10 = V_5 -> V_12 + F_1 ( * V_6 ) ;
F_4 (fmr, bucket, cache_node)
if ( V_8 == V_11 -> V_8 &&
V_7 == V_11 -> V_7 &&
! memcmp ( V_6 , V_11 -> V_6 ,
V_7 * sizeof *V_6 ) )
return V_11 ;
return NULL ;
}
static void F_5 ( struct V_4 * V_5 )
{
int V_13 ;
struct V_3 * V_11 ;
F_6 ( V_14 ) ;
F_6 ( V_15 ) ;
F_7 ( & V_5 -> V_16 ) ;
F_8 (fmr, &pool->dirty_list, list) {
F_9 ( & V_11 -> V_17 ) ;
V_11 -> V_18 = 0 ;
F_10 ( & V_11 -> V_11 -> V_19 , & V_15 ) ;
#ifdef F_11
if ( V_11 -> V_20 != 0 ) {
F_12 (KERN_WARNING PFX L_1 ,
fmr, fmr->ref_count) ;
}
#endif
}
F_13 ( & V_5 -> V_21 , & V_14 ) ;
V_5 -> V_22 = 0 ;
F_14 ( & V_5 -> V_16 ) ;
if ( F_15 ( & V_14 ) ) {
return;
}
V_13 = F_16 ( & V_15 ) ;
if ( V_13 )
F_12 (KERN_WARNING PFX L_2 , ret) ;
F_7 ( & V_5 -> V_16 ) ;
F_17 ( & V_14 , & V_5 -> V_23 ) ;
F_14 ( & V_5 -> V_16 ) ;
}
static int F_18 ( void * V_24 )
{
struct V_4 * V_5 = V_24 ;
do {
if ( F_19 ( & V_5 -> V_25 ) - F_19 ( & V_5 -> V_26 ) < 0 ) {
F_5 ( V_5 ) ;
F_20 ( & V_5 -> V_25 ) ;
F_21 ( & V_5 -> V_27 ) ;
if ( V_5 -> V_28 )
V_5 -> V_28 ( V_5 , V_5 -> V_29 ) ;
}
F_22 ( V_30 ) ;
if ( F_19 ( & V_5 -> V_25 ) - F_19 ( & V_5 -> V_26 ) >= 0 &&
! F_23 () )
F_24 () ;
F_25 ( V_31 ) ;
} while ( ! F_23 () );
return 0 ;
}
struct V_4 * F_26 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_36 * V_37 ;
struct V_4 * V_5 ;
int V_38 ;
int V_13 ;
int V_39 ;
if ( ! V_35 )
return F_27 ( - V_40 ) ;
V_37 = V_33 -> V_37 ;
if ( ! V_37 -> V_41 || ! V_37 -> V_42 ||
! V_37 -> V_43 || ! V_37 -> V_44 ) {
F_12 (KERN_INFO PFX L_3 ,
device->name) ;
return F_27 ( - V_45 ) ;
}
if ( ! V_37 -> V_46 . V_47 )
V_39 = V_48 ;
else
V_39 = V_37 -> V_46 . V_47 ;
V_5 = F_28 ( sizeof *V_5 , V_49 ) ;
if ( ! V_5 ) {
F_12 (KERN_WARNING PFX L_4 ) ;
return F_27 ( - V_50 ) ;
}
V_5 -> V_12 = NULL ;
V_5 -> V_28 = V_35 -> V_28 ;
V_5 -> V_29 = V_35 -> V_29 ;
F_29 ( & V_5 -> V_23 ) ;
F_29 ( & V_5 -> V_21 ) ;
if ( V_35 -> V_51 ) {
V_5 -> V_12 =
F_28 ( V_2 * sizeof * V_5 -> V_12 ,
V_49 ) ;
if ( ! V_5 -> V_12 ) {
F_12 (KERN_WARNING PFX L_5 ) ;
V_13 = - V_50 ;
goto V_52;
}
for ( V_38 = 0 ; V_38 < V_2 ; ++ V_38 )
F_30 ( V_5 -> V_12 + V_38 ) ;
}
V_5 -> V_53 = 0 ;
V_5 -> V_54 = V_35 -> V_55 ;
V_5 -> V_39 = V_39 ;
V_5 -> V_56 = V_35 -> V_56 ;
V_5 -> V_22 = 0 ;
F_31 ( & V_5 -> V_16 ) ;
F_32 ( & V_5 -> V_26 , 0 ) ;
F_32 ( & V_5 -> V_25 , 0 ) ;
F_33 ( & V_5 -> V_27 ) ;
V_5 -> V_57 = F_34 ( F_18 ,
V_5 ,
L_6 ,
V_37 -> V_58 ) ;
if ( F_35 ( V_5 -> V_57 ) ) {
F_12 (KERN_WARNING PFX L_7 ) ;
V_13 = F_36 ( V_5 -> V_57 ) ;
goto V_52;
}
{
struct V_3 * V_11 ;
struct V_59 V_60 = {
. V_54 = V_35 -> V_55 ,
. V_61 = V_5 -> V_39 ,
. V_62 = V_35 -> V_62
} ;
int V_63 = sizeof *V_11 ;
if ( V_5 -> V_12 )
V_63 += V_35 -> V_55 * sizeof ( T_2 ) ;
for ( V_38 = 0 ; V_38 < V_35 -> V_53 ; ++ V_38 ) {
V_11 = F_28 ( V_63 , V_49 ) ;
if ( ! V_11 ) {
F_12 (KERN_WARNING PFX L_8
L_9 , i) ;
goto V_64;
}
V_11 -> V_5 = V_5 ;
V_11 -> V_18 = 0 ;
V_11 -> V_20 = 0 ;
F_37 ( & V_11 -> V_17 ) ;
V_11 -> V_11 = F_38 ( V_33 , V_35 -> V_65 , & V_60 ) ;
if ( F_35 ( V_11 -> V_11 ) ) {
F_12 (KERN_WARNING PFX L_10
L_11 , i) ;
F_39 ( V_11 ) ;
goto V_64;
}
F_10 ( & V_11 -> V_19 , & V_5 -> V_23 ) ;
++ V_5 -> V_53 ;
}
}
return V_5 ;
V_52:
F_39 ( V_5 -> V_12 ) ;
F_39 ( V_5 ) ;
return F_27 ( V_13 ) ;
V_64:
F_40 ( V_5 ) ;
return F_27 ( - V_50 ) ;
}
void F_40 ( struct V_4 * V_5 )
{
struct V_3 * V_11 ;
struct V_3 * V_66 ;
F_6 ( V_15 ) ;
int V_38 ;
F_41 ( V_5 -> V_57 ) ;
F_5 ( V_5 ) ;
V_38 = 0 ;
F_42 (fmr, tmp, &pool->free_list, list) {
if ( V_11 -> V_18 ) {
F_29 ( & V_15 ) ;
F_10 ( & V_11 -> V_11 -> V_19 , & V_15 ) ;
F_16 ( & V_15 ) ;
}
F_43 ( V_11 -> V_11 ) ;
F_44 ( & V_11 -> V_19 ) ;
F_39 ( V_11 ) ;
++ V_38 ;
}
if ( V_38 < V_5 -> V_53 )
F_12 (KERN_WARNING PFX L_12 ,
pool->pool_size - i) ;
F_39 ( V_5 -> V_12 ) ;
F_39 ( V_5 ) ;
}
int F_45 ( struct V_4 * V_5 )
{
int V_67 ;
struct V_3 * V_11 , * V_68 ;
F_7 ( & V_5 -> V_16 ) ;
F_42 (fmr, next, &pool->free_list, list) {
if ( V_11 -> V_18 > 0 )
F_46 ( & V_11 -> V_19 , & V_5 -> V_21 ) ;
}
F_14 ( & V_5 -> V_16 ) ;
V_67 = F_47 ( & V_5 -> V_26 ) ;
F_48 ( V_5 -> V_57 ) ;
if ( F_49 ( V_5 -> V_27 ,
F_19 ( & V_5 -> V_25 ) - V_67 >= 0 ) )
return - V_69 ;
return 0 ;
}
struct V_3 * F_50 ( struct V_4 * V_70 ,
T_2 * V_6 ,
int V_71 ,
T_2 V_8 )
{
struct V_4 * V_5 = V_70 ;
struct V_3 * V_11 ;
unsigned long V_72 ;
int V_73 ;
if ( V_71 < 1 || V_71 > V_5 -> V_54 )
return F_27 ( - V_40 ) ;
F_51 ( & V_5 -> V_16 , V_72 ) ;
V_11 = F_3 ( V_5 ,
V_6 ,
V_71 ,
V_8 ) ;
if ( V_11 ) {
++ V_11 -> V_20 ;
if ( V_11 -> V_20 == 1 ) {
F_44 ( & V_11 -> V_19 ) ;
}
F_52 ( & V_5 -> V_16 , V_72 ) ;
return V_11 ;
}
if ( F_15 ( & V_5 -> V_23 ) ) {
F_52 ( & V_5 -> V_16 , V_72 ) ;
return F_27 ( - V_74 ) ;
}
V_11 = F_53 ( V_5 -> V_23 . V_68 , struct V_3 , V_19 ) ;
F_44 ( & V_11 -> V_19 ) ;
F_9 ( & V_11 -> V_17 ) ;
F_52 ( & V_5 -> V_16 , V_72 ) ;
V_73 = F_54 ( V_11 -> V_11 , V_6 , V_71 ,
V_8 ) ;
if ( V_73 ) {
F_51 ( & V_5 -> V_16 , V_72 ) ;
F_55 ( & V_11 -> V_19 , & V_5 -> V_23 ) ;
F_52 ( & V_5 -> V_16 , V_72 ) ;
F_12 (KERN_WARNING PFX L_13 , result) ;
return F_27 ( V_73 ) ;
}
++ V_11 -> V_18 ;
V_11 -> V_20 = 1 ;
if ( V_5 -> V_12 ) {
V_11 -> V_8 = V_8 ;
V_11 -> V_7 = V_71 ;
memcpy ( V_11 -> V_6 , V_6 , V_71 * sizeof( * V_6 ) ) ;
F_51 ( & V_5 -> V_16 , V_72 ) ;
F_56 ( & V_11 -> V_17 ,
V_5 -> V_12 + F_1 ( V_11 -> V_6 [ 0 ] ) ) ;
F_52 ( & V_5 -> V_16 , V_72 ) ;
}
return V_11 ;
}
int F_57 ( struct V_3 * V_11 )
{
struct V_4 * V_5 ;
unsigned long V_72 ;
V_5 = V_11 -> V_5 ;
F_51 ( & V_5 -> V_16 , V_72 ) ;
-- V_11 -> V_20 ;
if ( ! V_11 -> V_20 ) {
if ( V_11 -> V_18 < V_5 -> V_39 ) {
F_10 ( & V_11 -> V_19 , & V_5 -> V_23 ) ;
} else {
F_10 ( & V_11 -> V_19 , & V_5 -> V_21 ) ;
if ( ++ V_5 -> V_22 >= V_5 -> V_56 ) {
F_20 ( & V_5 -> V_26 ) ;
F_48 ( V_5 -> V_57 ) ;
}
}
}
#ifdef F_11
if ( V_11 -> V_20 < 0 )
F_12 (KERN_WARNING PFX L_14 ,
fmr, fmr->ref_count) ;
#endif
F_52 ( & V_5 -> V_16 , V_72 ) ;
return 0 ;
}
