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
static inline bool F_7 ( struct V_6 * V_7 )
{
if ( F_8 ( V_7 ) )
return false ;
switch ( F_9 () ) {
case V_10 :
case V_11 :
case V_12 :
return true ;
default:
return V_13 ;
}
}
static T_3 F_10 ( const struct V_6 * V_7 , T_3 V_14 )
{
T_3 V_15 ;
V_14 &= ~ ( V_16 | V_17 | V_18 ) ;
#ifdef F_11
if ( V_7 == NULL )
V_15 = V_16 ;
else
#endif
#if F_12 ( V_19 ) && F_12 ( V_20 )
if ( V_7 == NULL || V_7 -> V_21 < F_13 ( 32 ) )
V_15 = V_16 ;
else if ( V_7 -> V_21 < F_13 ( 64 ) )
V_15 = V_17 ;
else
#endif
#if F_12 ( V_19 ) && ! F_12 ( V_20 )
if ( V_7 == NULL || V_7 -> V_21 < F_13 ( 64 ) )
V_15 = V_17 ;
else
#endif
#if F_12 ( V_20 ) && ! F_12 ( V_19 )
if ( V_7 == NULL ||
V_7 -> V_21 < F_13 ( sizeof( V_22 ) * 8 ) )
V_15 = V_16 ;
else
#endif
V_15 = 0 ;
V_14 |= V_23 ;
return V_14 | V_15 ;
}
static void * F_14 ( struct V_6 * V_7 , T_4 V_24 ,
T_2 * V_25 , T_3 V_14 )
{
void * V_26 ;
V_14 = F_10 ( V_7 , V_14 ) ;
V_26 = ( void * ) F_15 ( V_14 , F_16 ( V_24 ) ) ;
if ( V_26 != NULL ) {
memset ( V_26 , 0 , V_24 ) ;
* V_25 = F_17 ( V_7 , V_26 , V_24 ) ;
}
return V_26 ;
}
static void * F_18 ( struct V_6 * V_7 , T_4 V_24 ,
T_2 * V_25 , T_3 V_14 , unsigned long V_27 )
{
void * V_26 ;
struct V_5 * V_5 = NULL ;
unsigned int V_28 = F_19 ( V_24 ) >> V_9 ;
if ( V_27 & V_29 )
return F_14 ( V_7 , V_24 , V_25 , V_14 ) ;
V_14 = F_10 ( V_7 , V_14 ) ;
if ( F_20 ( V_30 ) && F_21 ( V_14 ) )
V_5 = F_22 ( V_7 , V_28 , F_16 ( V_24 ) ,
V_14 ) ;
if ( ! V_5 )
V_5 = F_23 ( V_14 , F_16 ( V_24 ) ) ;
if ( ! V_5 )
return NULL ;
V_26 = F_24 ( V_5 ) ;
memset ( V_26 , 0 , V_24 ) ;
* V_25 = F_17 ( V_7 , V_26 , V_24 ) ;
if ( ! F_8 ( V_7 ) ) {
F_25 ( ( unsigned long ) V_26 , V_24 ) ;
V_26 = F_26 ( V_26 ) ;
}
return V_26 ;
}
static void F_27 ( struct V_6 * V_7 , T_4 V_24 ,
void * V_31 , T_2 V_25 )
{
F_28 ( V_7 , V_25 , V_24 , V_32 ) ;
F_29 ( ( unsigned long ) V_31 , F_16 ( V_24 ) ) ;
}
static void F_30 ( struct V_6 * V_7 , T_4 V_24 , void * V_31 ,
T_2 V_25 , unsigned long V_27 )
{
unsigned long V_33 = ( unsigned long ) V_31 ;
unsigned int V_28 = F_19 ( V_24 ) >> V_9 ;
struct V_5 * V_5 = NULL ;
if ( V_27 & V_29 ) {
F_27 ( V_7 , V_24 , V_31 , V_25 ) ;
return;
}
F_28 ( V_7 , V_25 , V_24 , V_32 ) ;
if ( ! F_8 ( V_7 ) )
V_33 = F_31 ( V_33 ) ;
V_5 = F_32 ( ( void * ) V_33 ) ;
if ( ! F_33 ( V_7 , V_5 , V_28 ) )
F_34 ( V_5 , F_16 ( V_24 ) ) ;
}
static int F_35 ( struct V_6 * V_7 , struct V_34 * V_35 ,
void * V_36 , T_2 V_8 , T_4 V_24 ,
unsigned long V_27 )
{
unsigned long V_37 = ( V_35 -> V_38 - V_35 -> V_39 ) >> V_9 ;
unsigned long V_28 = F_19 ( V_24 ) >> V_9 ;
unsigned long V_33 = ( unsigned long ) V_36 ;
unsigned long V_40 = V_35 -> V_41 ;
unsigned long V_42 ;
int V_26 = - V_43 ;
if ( ! F_8 ( V_7 ) )
V_33 = F_31 ( V_33 ) ;
V_42 = F_36 ( F_32 ( ( void * ) V_33 ) ) ;
if ( V_27 & V_44 )
V_35 -> V_45 = F_37 ( V_35 -> V_45 ) ;
else
V_35 -> V_45 = F_38 ( V_35 -> V_45 ) ;
if ( F_39 ( V_7 , V_35 , V_36 , V_24 , & V_26 ) )
return V_26 ;
if ( V_40 < V_28 && V_37 <= ( V_28 - V_40 ) ) {
V_26 = F_40 ( V_35 , V_35 -> V_39 ,
V_42 + V_40 ,
V_37 << V_9 ,
V_35 -> V_45 ) ;
}
return V_26 ;
}
static inline void F_41 ( void * V_33 , T_4 V_24 ,
enum V_46 V_47 )
{
switch ( V_47 ) {
case V_48 :
F_42 ( ( unsigned long ) V_33 , V_24 ) ;
break;
case V_49 :
F_43 ( ( unsigned long ) V_33 , V_24 ) ;
break;
case V_32 :
F_25 ( ( unsigned long ) V_33 , V_24 ) ;
break;
default:
F_44 () ;
}
}
static inline void F_45 ( struct V_5 * V_5 ,
unsigned long V_50 , T_4 V_24 , enum V_46 V_47 )
{
T_4 V_51 = V_24 ;
do {
T_4 V_52 = V_51 ;
if ( F_46 ( V_5 ) ) {
void * V_33 ;
if ( V_50 + V_52 > V_53 ) {
if ( V_50 >= V_53 ) {
V_5 += V_50 >> V_9 ;
V_50 &= ~ V_54 ;
}
V_52 = V_53 - V_50 ;
}
V_33 = F_47 ( V_5 ) ;
F_41 ( V_33 + V_50 , V_52 , V_47 ) ;
F_48 ( V_33 ) ;
} else
F_41 ( F_24 ( V_5 ) + V_50 ,
V_24 , V_47 ) ;
V_50 = 0 ;
V_5 ++ ;
V_51 -= V_52 ;
} while ( V_51 );
}
static void F_49 ( struct V_6 * V_7 , T_2 V_8 ,
T_4 V_24 , enum V_46 V_47 , unsigned long V_27 )
{
if ( F_7 ( V_7 ) && ! ( V_27 & V_55 ) )
F_45 ( F_4 ( V_7 , V_8 ) ,
V_8 & ~ V_54 , V_24 , V_47 ) ;
F_50 ( V_7 ) ;
F_28 ( V_7 , V_8 , V_24 , V_47 ) ;
}
static int F_51 ( struct V_6 * V_7 , struct V_56 * V_57 ,
int V_58 , enum V_46 V_47 , unsigned long V_27 )
{
int V_59 ;
struct V_56 * V_60 ;
F_52 (sglist, sg, nents, i) {
if ( ! F_8 ( V_7 ) &&
! ( V_27 & V_55 ) )
F_45 ( F_53 ( V_60 ) , V_60 -> V_50 , V_60 -> V_61 ,
V_47 ) ;
#ifdef F_54
V_60 -> V_62 = V_60 -> V_61 ;
#endif
V_60 -> V_63 = F_55 ( V_7 , F_53 ( V_60 ) ) +
V_60 -> V_50 ;
}
return V_58 ;
}
static T_2 F_56 ( struct V_6 * V_7 , struct V_5 * V_5 ,
unsigned long V_50 , T_4 V_24 , enum V_46 V_47 ,
unsigned long V_27 )
{
if ( ! F_8 ( V_7 ) && ! ( V_27 & V_55 ) )
F_45 ( V_5 , V_50 , V_24 , V_47 ) ;
return F_55 ( V_7 , V_5 ) + V_50 ;
}
static void F_57 ( struct V_6 * V_7 , struct V_56 * V_57 ,
int V_64 , enum V_46 V_47 ,
unsigned long V_27 )
{
int V_59 ;
struct V_56 * V_60 ;
F_52 (sglist, sg, nhwentries, i) {
if ( ! F_8 ( V_7 ) &&
! ( V_27 & V_55 ) &&
V_47 != V_48 )
F_45 ( F_53 ( V_60 ) , V_60 -> V_50 , V_60 -> V_61 ,
V_47 ) ;
F_28 ( V_7 , V_60 -> V_63 , V_60 -> V_61 , V_47 ) ;
}
}
static void F_58 ( struct V_6 * V_7 ,
T_2 V_25 , T_4 V_24 , enum V_46 V_47 )
{
if ( F_7 ( V_7 ) )
F_45 ( F_4 ( V_7 , V_25 ) ,
V_25 & ~ V_54 , V_24 , V_47 ) ;
F_50 ( V_7 ) ;
}
static void F_59 ( struct V_6 * V_7 ,
T_2 V_25 , T_4 V_24 , enum V_46 V_47 )
{
if ( ! F_8 ( V_7 ) )
F_45 ( F_4 ( V_7 , V_25 ) ,
V_25 & ~ V_54 , V_24 , V_47 ) ;
}
static void F_60 ( struct V_6 * V_7 ,
struct V_56 * V_57 , int V_65 ,
enum V_46 V_47 )
{
int V_59 ;
struct V_56 * V_60 ;
if ( F_7 ( V_7 ) ) {
F_52 (sglist, sg, nelems, i) {
F_45 ( F_53 ( V_60 ) , V_60 -> V_50 , V_60 -> V_61 ,
V_47 ) ;
}
}
F_50 ( V_7 ) ;
}
static void F_61 ( struct V_6 * V_7 ,
struct V_56 * V_57 , int V_65 ,
enum V_46 V_47 )
{
int V_59 ;
struct V_56 * V_60 ;
if ( ! F_8 ( V_7 ) ) {
F_52 (sglist, sg, nelems, i) {
F_45 ( F_53 ( V_60 ) , V_60 -> V_50 , V_60 -> V_61 ,
V_47 ) ;
}
}
}
int F_62 ( struct V_6 * V_7 , T_2 V_8 )
{
return 0 ;
}
int F_63 ( struct V_6 * V_7 , T_5 V_66 )
{
return F_64 ( V_7 , V_66 ) ;
}
void F_65 ( struct V_6 * V_7 , void * V_31 , T_4 V_24 ,
enum V_46 V_47 )
{
F_66 ( V_47 == V_67 ) ;
if ( ! F_8 ( V_7 ) )
F_41 ( V_31 , V_24 , V_47 ) ;
}
static int T_1 F_67 ( void )
{
F_68 ( V_68 ) ;
return 0 ;
}
