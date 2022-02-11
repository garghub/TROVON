static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
F_2 ( L_1 ) ;
return 0 ;
}
static int T_1 F_3 ( char * V_1 )
{
V_2 = 0 ;
F_2 ( L_2 ) ;
return 0 ;
}
static inline struct V_3 * F_4 ( struct V_4 * V_5 ,
T_2 V_6 )
{
return F_5 (
F_6 ( V_5 , V_6 ) >> V_7 ) ;
}
static inline int F_7 ( struct V_4 * V_5 )
{
return ! F_8 ( V_5 ) &&
( F_9 () == V_8 ||
F_9 () == V_9 ||
F_9 () == V_10 ) ;
}
static T_3 F_10 ( const struct V_4 * V_5 , T_3 V_11 )
{
T_3 V_12 ;
V_11 &= ~ ( V_13 | V_14 | V_15 ) ;
#ifdef F_11
if ( V_5 == NULL )
V_12 = V_13 ;
else
#endif
#if F_12 ( V_16 ) && F_12 ( V_17 )
if ( V_5 == NULL || V_5 -> V_18 < F_13 ( 32 ) )
V_12 = V_13 ;
else if ( V_5 -> V_18 < F_13 ( 64 ) )
V_12 = V_14 ;
else
#endif
#if F_12 ( V_16 ) && ! F_12 ( V_17 )
if ( V_5 == NULL || V_5 -> V_18 < F_13 ( 64 ) )
V_12 = V_14 ;
else
#endif
#if F_12 ( V_17 ) && ! F_12 ( V_16 )
if ( V_5 == NULL ||
V_5 -> V_18 < F_13 ( sizeof( V_19 ) * 8 ) )
V_12 = V_13 ;
else
#endif
V_12 = 0 ;
V_11 |= V_20 ;
return V_11 | V_12 ;
}
static void * F_14 ( struct V_4 * V_5 , T_4 V_21 ,
T_2 * V_22 , T_3 V_11 )
{
void * V_23 ;
V_11 = F_10 ( V_5 , V_11 ) ;
V_23 = ( void * ) F_15 ( V_11 , F_16 ( V_21 ) ) ;
if ( V_23 != NULL ) {
memset ( V_23 , 0 , V_21 ) ;
* V_22 = F_17 ( V_5 , V_23 , V_21 ) ;
}
return V_23 ;
}
static void * F_18 ( struct V_4 * V_5 , T_4 V_21 ,
T_2 * V_22 , T_3 V_11 , unsigned long V_24 )
{
void * V_23 ;
struct V_3 * V_3 = NULL ;
unsigned int V_25 = F_19 ( V_21 ) >> V_7 ;
if ( V_24 & V_26 )
return F_14 ( V_5 , V_21 , V_22 , V_11 ) ;
V_11 = F_10 ( V_5 , V_11 ) ;
if ( F_20 ( V_27 ) && F_21 ( V_11 ) )
V_3 = F_22 ( V_5 ,
V_25 , F_16 ( V_21 ) ) ;
if ( ! V_3 )
V_3 = F_23 ( V_11 , F_16 ( V_21 ) ) ;
if ( ! V_3 )
return NULL ;
V_23 = F_24 ( V_3 ) ;
memset ( V_23 , 0 , V_21 ) ;
* V_22 = F_17 ( V_5 , V_23 , V_21 ) ;
if ( ! F_8 ( V_5 ) ) {
F_25 ( ( unsigned long ) V_23 , V_21 ) ;
if ( ! V_28 )
V_23 = F_26 ( V_23 ) ;
}
return V_23 ;
}
static void F_27 ( struct V_4 * V_5 , T_4 V_21 ,
void * V_29 , T_2 V_22 )
{
F_28 ( V_5 , V_22 , V_21 , V_30 ) ;
F_29 ( ( unsigned long ) V_29 , F_16 ( V_21 ) ) ;
}
static void F_30 ( struct V_4 * V_5 , T_4 V_21 , void * V_29 ,
T_2 V_22 , unsigned long V_24 )
{
unsigned long V_31 = ( unsigned long ) V_29 ;
unsigned int V_25 = F_19 ( V_21 ) >> V_7 ;
struct V_3 * V_3 = NULL ;
if ( V_24 & V_26 ) {
F_27 ( V_5 , V_21 , V_29 , V_22 ) ;
return;
}
F_28 ( V_5 , V_22 , V_21 , V_30 ) ;
if ( ! F_8 ( V_5 ) && ! V_28 )
V_31 = F_31 ( V_31 ) ;
V_3 = F_32 ( ( void * ) V_31 ) ;
if ( ! F_33 ( V_5 , V_3 , V_25 ) )
F_34 ( V_3 , F_16 ( V_21 ) ) ;
}
static int F_35 ( struct V_4 * V_5 , struct V_32 * V_33 ,
void * V_34 , T_2 V_6 , T_4 V_21 ,
unsigned long V_24 )
{
unsigned long V_35 = ( V_33 -> V_36 - V_33 -> V_37 ) >> V_7 ;
unsigned long V_25 = F_19 ( V_21 ) >> V_7 ;
unsigned long V_31 = ( unsigned long ) V_34 ;
unsigned long V_38 = V_33 -> V_39 ;
unsigned long V_40 ;
int V_23 = - V_41 ;
if ( ! F_8 ( V_5 ) && ! V_28 )
V_31 = F_31 ( V_31 ) ;
V_40 = F_36 ( F_32 ( ( void * ) V_31 ) ) ;
if ( V_24 & V_42 )
V_33 -> V_43 = F_37 ( V_33 -> V_43 ) ;
else
V_33 -> V_43 = F_38 ( V_33 -> V_43 ) ;
if ( F_39 ( V_5 , V_33 , V_34 , V_21 , & V_23 ) )
return V_23 ;
if ( V_38 < V_25 && V_35 <= ( V_25 - V_38 ) ) {
V_23 = F_40 ( V_33 , V_33 -> V_37 ,
V_40 + V_38 ,
V_35 << V_7 ,
V_33 -> V_43 ) ;
}
return V_23 ;
}
static inline void F_41 ( void * V_31 , T_4 V_21 ,
enum V_44 V_45 )
{
switch ( V_45 ) {
case V_46 :
F_42 ( ( unsigned long ) V_31 , V_21 ) ;
break;
case V_47 :
F_43 ( ( unsigned long ) V_31 , V_21 ) ;
break;
case V_30 :
F_25 ( ( unsigned long ) V_31 , V_21 ) ;
break;
default:
F_44 () ;
}
}
static inline void F_45 ( struct V_3 * V_3 ,
unsigned long V_48 , T_4 V_21 , enum V_44 V_45 )
{
T_4 V_49 = V_21 ;
do {
T_4 V_50 = V_49 ;
if ( F_46 ( V_3 ) ) {
void * V_31 ;
if ( V_48 + V_50 > V_51 ) {
if ( V_48 >= V_51 ) {
V_3 += V_48 >> V_7 ;
V_48 &= ~ V_52 ;
}
V_50 = V_51 - V_48 ;
}
V_31 = F_47 ( V_3 ) ;
F_41 ( V_31 + V_48 , V_50 , V_45 ) ;
F_48 ( V_31 ) ;
} else
F_41 ( F_24 ( V_3 ) + V_48 ,
V_21 , V_45 ) ;
V_48 = 0 ;
V_3 ++ ;
V_49 -= V_50 ;
} while ( V_49 );
}
static void F_49 ( struct V_4 * V_5 , T_2 V_6 ,
T_4 V_21 , enum V_44 V_45 , unsigned long V_24 )
{
if ( F_7 ( V_5 ) )
F_45 ( F_4 ( V_5 , V_6 ) ,
V_6 & ~ V_52 , V_21 , V_45 ) ;
F_50 ( V_5 ) ;
F_28 ( V_5 , V_6 , V_21 , V_45 ) ;
}
static int F_51 ( struct V_4 * V_5 , struct V_53 * V_54 ,
int V_55 , enum V_44 V_45 , unsigned long V_24 )
{
int V_56 ;
struct V_53 * V_57 ;
F_52 (sglist, sg, nents, i) {
if ( ! F_8 ( V_5 ) )
F_45 ( F_53 ( V_57 ) , V_57 -> V_48 , V_57 -> V_58 ,
V_45 ) ;
#ifdef F_54
V_57 -> V_59 = V_57 -> V_58 ;
#endif
V_57 -> V_60 = F_55 ( V_5 , F_53 ( V_57 ) ) +
V_57 -> V_48 ;
}
return V_55 ;
}
static T_2 F_56 ( struct V_4 * V_5 , struct V_3 * V_3 ,
unsigned long V_48 , T_4 V_21 , enum V_44 V_45 ,
unsigned long V_24 )
{
if ( ! F_8 ( V_5 ) )
F_45 ( V_3 , V_48 , V_21 , V_45 ) ;
return F_55 ( V_5 , V_3 ) + V_48 ;
}
static void F_57 ( struct V_4 * V_5 , struct V_53 * V_54 ,
int V_61 , enum V_44 V_45 ,
unsigned long V_24 )
{
int V_56 ;
struct V_53 * V_57 ;
F_52 (sglist, sg, nhwentries, i) {
if ( ! F_8 ( V_5 ) &&
V_45 != V_46 )
F_45 ( F_53 ( V_57 ) , V_57 -> V_48 , V_57 -> V_58 ,
V_45 ) ;
F_28 ( V_5 , V_57 -> V_60 , V_57 -> V_58 , V_45 ) ;
}
}
static void F_58 ( struct V_4 * V_5 ,
T_2 V_22 , T_4 V_21 , enum V_44 V_45 )
{
if ( F_7 ( V_5 ) )
F_45 ( F_4 ( V_5 , V_22 ) ,
V_22 & ~ V_52 , V_21 , V_45 ) ;
F_50 ( V_5 ) ;
}
static void F_59 ( struct V_4 * V_5 ,
T_2 V_22 , T_4 V_21 , enum V_44 V_45 )
{
if ( ! F_8 ( V_5 ) )
F_45 ( F_4 ( V_5 , V_22 ) ,
V_22 & ~ V_52 , V_21 , V_45 ) ;
}
static void F_60 ( struct V_4 * V_5 ,
struct V_53 * V_54 , int V_62 ,
enum V_44 V_45 )
{
int V_56 ;
struct V_53 * V_57 ;
if ( F_7 ( V_5 ) ) {
F_52 (sglist, sg, nelems, i) {
F_45 ( F_53 ( V_57 ) , V_57 -> V_48 , V_57 -> V_58 ,
V_45 ) ;
}
}
F_50 ( V_5 ) ;
}
static void F_61 ( struct V_4 * V_5 ,
struct V_53 * V_54 , int V_62 ,
enum V_44 V_45 )
{
int V_56 ;
struct V_53 * V_57 ;
if ( ! F_8 ( V_5 ) ) {
F_52 (sglist, sg, nelems, i) {
F_45 ( F_53 ( V_57 ) , V_57 -> V_48 , V_57 -> V_58 ,
V_45 ) ;
}
}
}
int F_62 ( struct V_4 * V_5 , T_2 V_6 )
{
return 0 ;
}
int F_63 ( struct V_4 * V_5 , T_5 V_63 )
{
return F_64 ( V_5 , V_63 ) ;
}
void F_65 ( struct V_4 * V_5 , void * V_29 , T_4 V_21 ,
enum V_44 V_45 )
{
F_66 ( V_45 == V_64 ) ;
if ( ! F_8 ( V_5 ) )
F_41 ( V_29 , V_21 , V_45 ) ;
}
static int T_1 F_67 ( void )
{
F_68 ( V_65 ) ;
return 0 ;
}
