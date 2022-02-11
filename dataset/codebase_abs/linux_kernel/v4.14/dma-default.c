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
T_2 * V_25 , T_3 V_14 , unsigned long V_26 )
{
void * V_27 ;
struct V_5 * V_5 = NULL ;
unsigned int V_28 = F_15 ( V_24 ) >> V_9 ;
V_14 = F_10 ( V_7 , V_14 ) ;
if ( F_16 ( V_29 ) && F_17 ( V_14 ) )
V_5 = F_18 ( V_7 , V_28 , F_19 ( V_24 ) ,
V_14 ) ;
if ( ! V_5 )
V_5 = F_20 ( V_14 , F_19 ( V_24 ) ) ;
if ( ! V_5 )
return NULL ;
V_27 = F_21 ( V_5 ) ;
memset ( V_27 , 0 , V_24 ) ;
* V_25 = F_22 ( V_7 , V_27 , V_24 ) ;
if ( ! ( V_26 & V_30 ) &&
! F_8 ( V_7 ) ) {
F_23 ( ( unsigned long ) V_27 , V_24 ) ;
V_27 = F_24 ( V_27 ) ;
}
return V_27 ;
}
static void F_25 ( struct V_6 * V_7 , T_4 V_24 , void * V_31 ,
T_2 V_25 , unsigned long V_26 )
{
unsigned long V_32 = ( unsigned long ) V_31 ;
unsigned int V_28 = F_15 ( V_24 ) >> V_9 ;
struct V_5 * V_5 = NULL ;
F_26 ( V_7 , V_25 , V_24 , V_33 ) ;
if ( ! ( V_26 & V_30 ) && ! F_8 ( V_7 ) )
V_32 = F_27 ( V_32 ) ;
V_5 = F_28 ( ( void * ) V_32 ) ;
if ( ! F_29 ( V_7 , V_5 , V_28 ) )
F_30 ( V_5 , F_19 ( V_24 ) ) ;
}
static int F_31 ( struct V_6 * V_7 , struct V_34 * V_35 ,
void * V_36 , T_2 V_8 , T_4 V_24 ,
unsigned long V_26 )
{
unsigned long V_37 = ( V_35 -> V_38 - V_35 -> V_39 ) >> V_9 ;
unsigned long V_28 = F_15 ( V_24 ) >> V_9 ;
unsigned long V_32 = ( unsigned long ) V_36 ;
unsigned long V_40 = V_35 -> V_41 ;
unsigned long V_42 ;
int V_27 = - V_43 ;
if ( ! F_8 ( V_7 ) )
V_32 = F_27 ( V_32 ) ;
V_42 = F_32 ( F_28 ( ( void * ) V_32 ) ) ;
if ( V_26 & V_44 )
V_35 -> V_45 = F_33 ( V_35 -> V_45 ) ;
else
V_35 -> V_45 = F_34 ( V_35 -> V_45 ) ;
if ( F_35 ( V_7 , V_35 , V_36 , V_24 , & V_27 ) )
return V_27 ;
if ( V_40 < V_28 && V_37 <= ( V_28 - V_40 ) ) {
V_27 = F_36 ( V_35 , V_35 -> V_39 ,
V_42 + V_40 ,
V_37 << V_9 ,
V_35 -> V_45 ) ;
}
return V_27 ;
}
static inline void F_37 ( void * V_32 , T_4 V_24 ,
enum V_46 V_47 )
{
switch ( V_47 ) {
case V_48 :
F_38 ( ( unsigned long ) V_32 , V_24 ) ;
break;
case V_49 :
F_39 ( ( unsigned long ) V_32 , V_24 ) ;
break;
case V_33 :
F_23 ( ( unsigned long ) V_32 , V_24 ) ;
break;
default:
F_40 () ;
}
}
static inline void F_41 ( struct V_5 * V_5 ,
unsigned long V_50 , T_4 V_24 , enum V_46 V_47 )
{
T_4 V_51 = V_24 ;
do {
T_4 V_52 = V_51 ;
if ( F_42 ( V_5 ) ) {
void * V_32 ;
if ( V_50 + V_52 > V_53 ) {
if ( V_50 >= V_53 ) {
V_5 += V_50 >> V_9 ;
V_50 &= ~ V_54 ;
}
V_52 = V_53 - V_50 ;
}
V_32 = F_43 ( V_5 ) ;
F_37 ( V_32 + V_50 , V_52 , V_47 ) ;
F_44 ( V_32 ) ;
} else
F_37 ( F_21 ( V_5 ) + V_50 ,
V_24 , V_47 ) ;
V_50 = 0 ;
V_5 ++ ;
V_51 -= V_52 ;
} while ( V_51 );
}
static void F_45 ( struct V_6 * V_7 , T_2 V_8 ,
T_4 V_24 , enum V_46 V_47 , unsigned long V_26 )
{
if ( F_7 ( V_7 ) && ! ( V_26 & V_55 ) )
F_41 ( F_4 ( V_7 , V_8 ) ,
V_8 & ~ V_54 , V_24 , V_47 ) ;
F_46 ( V_7 ) ;
F_26 ( V_7 , V_8 , V_24 , V_47 ) ;
}
static int F_47 ( struct V_6 * V_7 , struct V_56 * V_57 ,
int V_58 , enum V_46 V_47 , unsigned long V_26 )
{
int V_59 ;
struct V_56 * V_60 ;
F_48 (sglist, sg, nents, i) {
if ( ! F_8 ( V_7 ) &&
! ( V_26 & V_55 ) )
F_41 ( F_49 ( V_60 ) , V_60 -> V_50 , V_60 -> V_61 ,
V_47 ) ;
#ifdef F_50
V_60 -> V_62 = V_60 -> V_61 ;
#endif
V_60 -> V_63 = F_51 ( V_7 , F_49 ( V_60 ) ) +
V_60 -> V_50 ;
}
return V_58 ;
}
static T_2 F_52 ( struct V_6 * V_7 , struct V_5 * V_5 ,
unsigned long V_50 , T_4 V_24 , enum V_46 V_47 ,
unsigned long V_26 )
{
if ( ! F_8 ( V_7 ) && ! ( V_26 & V_55 ) )
F_41 ( V_5 , V_50 , V_24 , V_47 ) ;
return F_51 ( V_7 , V_5 ) + V_50 ;
}
static void F_53 ( struct V_6 * V_7 , struct V_56 * V_57 ,
int V_64 , enum V_46 V_47 ,
unsigned long V_26 )
{
int V_59 ;
struct V_56 * V_60 ;
F_48 (sglist, sg, nhwentries, i) {
if ( ! F_8 ( V_7 ) &&
! ( V_26 & V_55 ) &&
V_47 != V_48 )
F_41 ( F_49 ( V_60 ) , V_60 -> V_50 , V_60 -> V_61 ,
V_47 ) ;
F_26 ( V_7 , V_60 -> V_63 , V_60 -> V_61 , V_47 ) ;
}
}
static void F_54 ( struct V_6 * V_7 ,
T_2 V_25 , T_4 V_24 , enum V_46 V_47 )
{
if ( F_7 ( V_7 ) )
F_41 ( F_4 ( V_7 , V_25 ) ,
V_25 & ~ V_54 , V_24 , V_47 ) ;
F_46 ( V_7 ) ;
}
static void F_55 ( struct V_6 * V_7 ,
T_2 V_25 , T_4 V_24 , enum V_46 V_47 )
{
if ( ! F_8 ( V_7 ) )
F_41 ( F_4 ( V_7 , V_25 ) ,
V_25 & ~ V_54 , V_24 , V_47 ) ;
}
static void F_56 ( struct V_6 * V_7 ,
struct V_56 * V_57 , int V_65 ,
enum V_46 V_47 )
{
int V_59 ;
struct V_56 * V_60 ;
if ( F_7 ( V_7 ) ) {
F_48 (sglist, sg, nelems, i) {
F_41 ( F_49 ( V_60 ) , V_60 -> V_50 , V_60 -> V_61 ,
V_47 ) ;
}
}
F_46 ( V_7 ) ;
}
static void F_57 ( struct V_6 * V_7 ,
struct V_56 * V_57 , int V_65 ,
enum V_46 V_47 )
{
int V_59 ;
struct V_56 * V_60 ;
if ( ! F_8 ( V_7 ) ) {
F_48 (sglist, sg, nelems, i) {
F_41 ( F_49 ( V_60 ) , V_60 -> V_50 , V_60 -> V_61 ,
V_47 ) ;
}
}
}
static int F_58 ( struct V_6 * V_7 , T_2 V_8 )
{
return 0 ;
}
static int F_59 ( struct V_6 * V_7 , T_5 V_66 )
{
return F_60 ( V_7 , V_66 ) ;
}
void F_61 ( struct V_6 * V_7 , void * V_31 , T_4 V_24 ,
enum V_46 V_47 )
{
F_62 ( V_47 == V_67 ) ;
if ( ! F_8 ( V_7 ) )
F_37 ( V_31 , V_24 , V_47 ) ;
}
static int T_1 F_63 ( void )
{
F_64 ( V_68 ) ;
return 0 ;
}
