static int T_1 F_1 ( char * V_1 )
{
V_2 = V_3 ;
F_2 ( L_1 ) ;
return 0 ;
}
static int T_1 F_3 ( char * V_1 )
{
V_2 = V_4 ;
F_2 ( L_2 ) ;
return 0 ;
}
static inline struct V_5 * F_4 ( struct V_6 * V_7 ,
T_2 V_8 )
{
return F_5 (
F_6 ( V_7 , V_8 ) >> V_9 ) ;
}
static inline int F_7 ( struct V_6 * V_7 )
{
return ! F_8 ( V_7 ) &&
( F_9 () == V_10 ||
F_9 () == V_11 ||
F_9 () == V_12 ) ;
}
static T_3 F_10 ( const struct V_6 * V_7 , T_3 V_13 )
{
T_3 V_14 ;
V_13 &= ~ ( V_15 | V_16 | V_17 ) ;
#ifdef F_11
if ( V_7 == NULL )
V_14 = V_15 ;
else
#endif
#if F_12 ( V_18 ) && F_12 ( V_19 )
if ( V_7 == NULL || V_7 -> V_20 < F_13 ( 32 ) )
V_14 = V_15 ;
else if ( V_7 -> V_20 < F_13 ( 64 ) )
V_14 = V_16 ;
else
#endif
#if F_12 ( V_18 ) && ! F_12 ( V_19 )
if ( V_7 == NULL || V_7 -> V_20 < F_13 ( 64 ) )
V_14 = V_16 ;
else
#endif
#if F_12 ( V_19 ) && ! F_12 ( V_18 )
if ( V_7 == NULL ||
V_7 -> V_20 < F_13 ( sizeof( V_21 ) * 8 ) )
V_14 = V_15 ;
else
#endif
V_14 = 0 ;
V_13 |= V_22 ;
return V_13 | V_14 ;
}
static void * F_14 ( struct V_6 * V_7 , T_4 V_23 ,
T_2 * V_24 , T_3 V_13 )
{
void * V_25 ;
V_13 = F_10 ( V_7 , V_13 ) ;
V_25 = ( void * ) F_15 ( V_13 , F_16 ( V_23 ) ) ;
if ( V_25 != NULL ) {
memset ( V_25 , 0 , V_23 ) ;
* V_24 = F_17 ( V_7 , V_25 , V_23 ) ;
}
return V_25 ;
}
static void * F_18 ( struct V_6 * V_7 , T_4 V_23 ,
T_2 * V_24 , T_3 V_13 , unsigned long V_26 )
{
void * V_25 ;
struct V_5 * V_5 = NULL ;
unsigned int V_27 = F_19 ( V_23 ) >> V_9 ;
if ( V_26 & V_28 )
return F_14 ( V_7 , V_23 , V_24 , V_13 ) ;
V_13 = F_10 ( V_7 , V_13 ) ;
if ( F_20 ( V_29 ) && F_21 ( V_13 ) )
V_5 = F_22 ( V_7 ,
V_27 , F_16 ( V_23 ) ) ;
if ( ! V_5 )
V_5 = F_23 ( V_13 , F_16 ( V_23 ) ) ;
if ( ! V_5 )
return NULL ;
V_25 = F_24 ( V_5 ) ;
memset ( V_25 , 0 , V_23 ) ;
* V_24 = F_17 ( V_7 , V_25 , V_23 ) ;
if ( ! F_8 ( V_7 ) ) {
F_25 ( ( unsigned long ) V_25 , V_23 ) ;
V_25 = F_26 ( V_25 ) ;
}
return V_25 ;
}
static void F_27 ( struct V_6 * V_7 , T_4 V_23 ,
void * V_30 , T_2 V_24 )
{
F_28 ( V_7 , V_24 , V_23 , V_31 ) ;
F_29 ( ( unsigned long ) V_30 , F_16 ( V_23 ) ) ;
}
static void F_30 ( struct V_6 * V_7 , T_4 V_23 , void * V_30 ,
T_2 V_24 , unsigned long V_26 )
{
unsigned long V_32 = ( unsigned long ) V_30 ;
unsigned int V_27 = F_19 ( V_23 ) >> V_9 ;
struct V_5 * V_5 = NULL ;
if ( V_26 & V_28 ) {
F_27 ( V_7 , V_23 , V_30 , V_24 ) ;
return;
}
F_28 ( V_7 , V_24 , V_23 , V_31 ) ;
if ( ! F_8 ( V_7 ) )
V_32 = F_31 ( V_32 ) ;
V_5 = F_32 ( ( void * ) V_32 ) ;
if ( ! F_33 ( V_7 , V_5 , V_27 ) )
F_34 ( V_5 , F_16 ( V_23 ) ) ;
}
static int F_35 ( struct V_6 * V_7 , struct V_33 * V_34 ,
void * V_35 , T_2 V_8 , T_4 V_23 ,
unsigned long V_26 )
{
unsigned long V_36 = ( V_34 -> V_37 - V_34 -> V_38 ) >> V_9 ;
unsigned long V_27 = F_19 ( V_23 ) >> V_9 ;
unsigned long V_32 = ( unsigned long ) V_35 ;
unsigned long V_39 = V_34 -> V_40 ;
unsigned long V_41 ;
int V_25 = - V_42 ;
if ( ! F_8 ( V_7 ) )
V_32 = F_31 ( V_32 ) ;
V_41 = F_36 ( F_32 ( ( void * ) V_32 ) ) ;
if ( V_26 & V_43 )
V_34 -> V_44 = F_37 ( V_34 -> V_44 ) ;
else
V_34 -> V_44 = F_38 ( V_34 -> V_44 ) ;
if ( F_39 ( V_7 , V_34 , V_35 , V_23 , & V_25 ) )
return V_25 ;
if ( V_39 < V_27 && V_36 <= ( V_27 - V_39 ) ) {
V_25 = F_40 ( V_34 , V_34 -> V_38 ,
V_41 + V_39 ,
V_36 << V_9 ,
V_34 -> V_44 ) ;
}
return V_25 ;
}
static inline void F_41 ( void * V_32 , T_4 V_23 ,
enum V_45 V_46 )
{
switch ( V_46 ) {
case V_47 :
F_42 ( ( unsigned long ) V_32 , V_23 ) ;
break;
case V_48 :
F_43 ( ( unsigned long ) V_32 , V_23 ) ;
break;
case V_31 :
F_25 ( ( unsigned long ) V_32 , V_23 ) ;
break;
default:
F_44 () ;
}
}
static inline void F_45 ( struct V_5 * V_5 ,
unsigned long V_49 , T_4 V_23 , enum V_45 V_46 )
{
T_4 V_50 = V_23 ;
do {
T_4 V_51 = V_50 ;
if ( F_46 ( V_5 ) ) {
void * V_32 ;
if ( V_49 + V_51 > V_52 ) {
if ( V_49 >= V_52 ) {
V_5 += V_49 >> V_9 ;
V_49 &= ~ V_53 ;
}
V_51 = V_52 - V_49 ;
}
V_32 = F_47 ( V_5 ) ;
F_41 ( V_32 + V_49 , V_51 , V_46 ) ;
F_48 ( V_32 ) ;
} else
F_41 ( F_24 ( V_5 ) + V_49 ,
V_23 , V_46 ) ;
V_49 = 0 ;
V_5 ++ ;
V_50 -= V_51 ;
} while ( V_50 );
}
static void F_49 ( struct V_6 * V_7 , T_2 V_8 ,
T_4 V_23 , enum V_45 V_46 , unsigned long V_26 )
{
if ( F_7 ( V_7 ) && ! ( V_26 & V_54 ) )
F_45 ( F_4 ( V_7 , V_8 ) ,
V_8 & ~ V_53 , V_23 , V_46 ) ;
F_50 ( V_7 ) ;
F_28 ( V_7 , V_8 , V_23 , V_46 ) ;
}
static int F_51 ( struct V_6 * V_7 , struct V_55 * V_56 ,
int V_57 , enum V_45 V_46 , unsigned long V_26 )
{
int V_58 ;
struct V_55 * V_59 ;
F_52 (sglist, sg, nents, i) {
if ( ! F_8 ( V_7 ) &&
! ( V_26 & V_54 ) )
F_45 ( F_53 ( V_59 ) , V_59 -> V_49 , V_59 -> V_60 ,
V_46 ) ;
#ifdef F_54
V_59 -> V_61 = V_59 -> V_60 ;
#endif
V_59 -> V_62 = F_55 ( V_7 , F_53 ( V_59 ) ) +
V_59 -> V_49 ;
}
return V_57 ;
}
static T_2 F_56 ( struct V_6 * V_7 , struct V_5 * V_5 ,
unsigned long V_49 , T_4 V_23 , enum V_45 V_46 ,
unsigned long V_26 )
{
if ( ! F_8 ( V_7 ) && ! ( V_26 & V_54 ) )
F_45 ( V_5 , V_49 , V_23 , V_46 ) ;
return F_55 ( V_7 , V_5 ) + V_49 ;
}
static void F_57 ( struct V_6 * V_7 , struct V_55 * V_56 ,
int V_63 , enum V_45 V_46 ,
unsigned long V_26 )
{
int V_58 ;
struct V_55 * V_59 ;
F_52 (sglist, sg, nhwentries, i) {
if ( ! F_8 ( V_7 ) &&
! ( V_26 & V_54 ) &&
V_46 != V_47 )
F_45 ( F_53 ( V_59 ) , V_59 -> V_49 , V_59 -> V_60 ,
V_46 ) ;
F_28 ( V_7 , V_59 -> V_62 , V_59 -> V_60 , V_46 ) ;
}
}
static void F_58 ( struct V_6 * V_7 ,
T_2 V_24 , T_4 V_23 , enum V_45 V_46 )
{
if ( F_7 ( V_7 ) )
F_45 ( F_4 ( V_7 , V_24 ) ,
V_24 & ~ V_53 , V_23 , V_46 ) ;
F_50 ( V_7 ) ;
}
static void F_59 ( struct V_6 * V_7 ,
T_2 V_24 , T_4 V_23 , enum V_45 V_46 )
{
if ( ! F_8 ( V_7 ) )
F_45 ( F_4 ( V_7 , V_24 ) ,
V_24 & ~ V_53 , V_23 , V_46 ) ;
}
static void F_60 ( struct V_6 * V_7 ,
struct V_55 * V_56 , int V_64 ,
enum V_45 V_46 )
{
int V_58 ;
struct V_55 * V_59 ;
if ( F_7 ( V_7 ) ) {
F_52 (sglist, sg, nelems, i) {
F_45 ( F_53 ( V_59 ) , V_59 -> V_49 , V_59 -> V_60 ,
V_46 ) ;
}
}
F_50 ( V_7 ) ;
}
static void F_61 ( struct V_6 * V_7 ,
struct V_55 * V_56 , int V_64 ,
enum V_45 V_46 )
{
int V_58 ;
struct V_55 * V_59 ;
if ( ! F_8 ( V_7 ) ) {
F_52 (sglist, sg, nelems, i) {
F_45 ( F_53 ( V_59 ) , V_59 -> V_49 , V_59 -> V_60 ,
V_46 ) ;
}
}
}
int F_62 ( struct V_6 * V_7 , T_2 V_8 )
{
return 0 ;
}
int F_63 ( struct V_6 * V_7 , T_5 V_65 )
{
return F_64 ( V_7 , V_65 ) ;
}
void F_65 ( struct V_6 * V_7 , void * V_30 , T_4 V_23 ,
enum V_45 V_46 )
{
F_66 ( V_46 == V_66 ) ;
if ( ! F_8 ( V_7 ) )
F_41 ( V_30 , V_23 , V_46 ) ;
}
static int T_1 F_67 ( void )
{
F_68 ( V_67 ) ;
return 0 ;
}
