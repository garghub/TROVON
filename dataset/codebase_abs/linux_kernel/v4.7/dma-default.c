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
T_2 * V_22 , T_3 V_11 , struct V_24 * V_25 )
{
void * V_23 ;
struct V_3 * V_3 = NULL ;
unsigned int V_26 = F_19 ( V_21 ) >> V_7 ;
if ( F_20 ( V_27 , V_25 ) )
return F_14 ( V_5 , V_21 , V_22 , V_11 ) ;
V_11 = F_10 ( V_5 , V_11 ) ;
if ( F_21 ( V_28 ) && F_22 ( V_11 ) )
V_3 = F_23 ( V_5 ,
V_26 , F_16 ( V_21 ) ) ;
if ( ! V_3 )
V_3 = F_24 ( V_11 , F_16 ( V_21 ) ) ;
if ( ! V_3 )
return NULL ;
V_23 = F_25 ( V_3 ) ;
memset ( V_23 , 0 , V_21 ) ;
* V_22 = F_17 ( V_5 , V_23 , V_21 ) ;
if ( ! F_8 ( V_5 ) ) {
F_26 ( ( unsigned long ) V_23 , V_21 ) ;
if ( ! V_29 )
V_23 = F_27 ( V_23 ) ;
}
return V_23 ;
}
static void F_28 ( struct V_4 * V_5 , T_4 V_21 ,
void * V_30 , T_2 V_22 )
{
F_29 ( V_5 , V_22 , V_21 , V_31 ) ;
F_30 ( ( unsigned long ) V_30 , F_16 ( V_21 ) ) ;
}
static void F_31 ( struct V_4 * V_5 , T_4 V_21 , void * V_30 ,
T_2 V_22 , struct V_24 * V_25 )
{
unsigned long V_32 = ( unsigned long ) V_30 ;
unsigned int V_26 = F_19 ( V_21 ) >> V_7 ;
struct V_3 * V_3 = NULL ;
if ( F_20 ( V_27 , V_25 ) ) {
F_28 ( V_5 , V_21 , V_30 , V_22 ) ;
return;
}
F_29 ( V_5 , V_22 , V_21 , V_31 ) ;
if ( ! F_8 ( V_5 ) && ! V_29 )
V_32 = F_32 ( V_32 ) ;
V_3 = F_33 ( ( void * ) V_32 ) ;
if ( ! F_34 ( V_5 , V_3 , V_26 ) )
F_35 ( V_3 , F_16 ( V_21 ) ) ;
}
static int F_36 ( struct V_4 * V_5 , struct V_33 * V_34 ,
void * V_35 , T_2 V_6 , T_4 V_21 ,
struct V_24 * V_25 )
{
unsigned long V_36 = ( V_34 -> V_37 - V_34 -> V_38 ) >> V_7 ;
unsigned long V_26 = F_19 ( V_21 ) >> V_7 ;
unsigned long V_32 = ( unsigned long ) V_35 ;
unsigned long V_39 = V_34 -> V_40 ;
unsigned long V_41 ;
int V_23 = - V_42 ;
if ( ! F_8 ( V_5 ) && ! V_29 )
V_32 = F_32 ( V_32 ) ;
V_41 = F_37 ( F_33 ( ( void * ) V_32 ) ) ;
if ( F_20 ( V_43 , V_25 ) )
V_34 -> V_44 = F_38 ( V_34 -> V_44 ) ;
else
V_34 -> V_44 = F_39 ( V_34 -> V_44 ) ;
if ( F_40 ( V_5 , V_34 , V_35 , V_21 , & V_23 ) )
return V_23 ;
if ( V_39 < V_26 && V_36 <= ( V_26 - V_39 ) ) {
V_23 = F_41 ( V_34 , V_34 -> V_38 ,
V_41 + V_39 ,
V_36 << V_7 ,
V_34 -> V_44 ) ;
}
return V_23 ;
}
static inline void F_42 ( void * V_32 , T_4 V_21 ,
enum V_45 V_46 )
{
switch ( V_46 ) {
case V_47 :
F_43 ( ( unsigned long ) V_32 , V_21 ) ;
break;
case V_48 :
F_44 ( ( unsigned long ) V_32 , V_21 ) ;
break;
case V_31 :
F_26 ( ( unsigned long ) V_32 , V_21 ) ;
break;
default:
F_45 () ;
}
}
static inline void F_46 ( struct V_3 * V_3 ,
unsigned long V_49 , T_4 V_21 , enum V_45 V_46 )
{
T_4 V_50 = V_21 ;
do {
T_4 V_51 = V_50 ;
if ( F_47 ( V_3 ) ) {
void * V_32 ;
if ( V_49 + V_51 > V_52 ) {
if ( V_49 >= V_52 ) {
V_3 += V_49 >> V_7 ;
V_49 &= ~ V_53 ;
}
V_51 = V_52 - V_49 ;
}
V_32 = F_48 ( V_3 ) ;
F_42 ( V_32 + V_49 , V_51 , V_46 ) ;
F_49 ( V_32 ) ;
} else
F_42 ( F_25 ( V_3 ) + V_49 ,
V_21 , V_46 ) ;
V_49 = 0 ;
V_3 ++ ;
V_50 -= V_51 ;
} while ( V_50 );
}
static void F_50 ( struct V_4 * V_5 , T_2 V_6 ,
T_4 V_21 , enum V_45 V_46 , struct V_24 * V_25 )
{
if ( F_7 ( V_5 ) )
F_46 ( F_4 ( V_5 , V_6 ) ,
V_6 & ~ V_53 , V_21 , V_46 ) ;
F_51 ( V_5 ) ;
F_29 ( V_5 , V_6 , V_21 , V_46 ) ;
}
static int F_52 ( struct V_4 * V_5 , struct V_54 * V_55 ,
int V_56 , enum V_45 V_46 , struct V_24 * V_25 )
{
int V_57 ;
struct V_54 * V_58 ;
F_53 (sglist, sg, nents, i) {
if ( ! F_8 ( V_5 ) )
F_46 ( F_54 ( V_58 ) , V_58 -> V_49 , V_58 -> V_59 ,
V_46 ) ;
#ifdef F_55
V_58 -> V_60 = V_58 -> V_59 ;
#endif
V_58 -> V_61 = F_56 ( V_5 , F_54 ( V_58 ) ) +
V_58 -> V_49 ;
}
return V_56 ;
}
static T_2 F_57 ( struct V_4 * V_5 , struct V_3 * V_3 ,
unsigned long V_49 , T_4 V_21 , enum V_45 V_46 ,
struct V_24 * V_25 )
{
if ( ! F_8 ( V_5 ) )
F_46 ( V_3 , V_49 , V_21 , V_46 ) ;
return F_56 ( V_5 , V_3 ) + V_49 ;
}
static void F_58 ( struct V_4 * V_5 , struct V_54 * V_55 ,
int V_62 , enum V_45 V_46 ,
struct V_24 * V_25 )
{
int V_57 ;
struct V_54 * V_58 ;
F_53 (sglist, sg, nhwentries, i) {
if ( ! F_8 ( V_5 ) &&
V_46 != V_47 )
F_46 ( F_54 ( V_58 ) , V_58 -> V_49 , V_58 -> V_59 ,
V_46 ) ;
F_29 ( V_5 , V_58 -> V_61 , V_58 -> V_59 , V_46 ) ;
}
}
static void F_59 ( struct V_4 * V_5 ,
T_2 V_22 , T_4 V_21 , enum V_45 V_46 )
{
if ( F_7 ( V_5 ) )
F_46 ( F_4 ( V_5 , V_22 ) ,
V_22 & ~ V_53 , V_21 , V_46 ) ;
F_51 ( V_5 ) ;
}
static void F_60 ( struct V_4 * V_5 ,
T_2 V_22 , T_4 V_21 , enum V_45 V_46 )
{
if ( ! F_8 ( V_5 ) )
F_46 ( F_4 ( V_5 , V_22 ) ,
V_22 & ~ V_53 , V_21 , V_46 ) ;
}
static void F_61 ( struct V_4 * V_5 ,
struct V_54 * V_55 , int V_63 ,
enum V_45 V_46 )
{
int V_57 ;
struct V_54 * V_58 ;
if ( F_7 ( V_5 ) ) {
F_53 (sglist, sg, nelems, i) {
F_46 ( F_54 ( V_58 ) , V_58 -> V_49 , V_58 -> V_59 ,
V_46 ) ;
}
}
F_51 ( V_5 ) ;
}
static void F_62 ( struct V_4 * V_5 ,
struct V_54 * V_55 , int V_63 ,
enum V_45 V_46 )
{
int V_57 ;
struct V_54 * V_58 ;
if ( ! F_8 ( V_5 ) ) {
F_53 (sglist, sg, nelems, i) {
F_46 ( F_54 ( V_58 ) , V_58 -> V_49 , V_58 -> V_59 ,
V_46 ) ;
}
}
}
int F_63 ( struct V_4 * V_5 , T_2 V_6 )
{
return 0 ;
}
int F_64 ( struct V_4 * V_5 , T_5 V_64 )
{
return F_65 ( V_5 , V_64 ) ;
}
void F_66 ( struct V_4 * V_5 , void * V_30 , T_4 V_21 ,
enum V_45 V_46 )
{
F_67 ( V_46 == V_65 ) ;
if ( ! F_8 ( V_5 ) )
F_42 ( V_30 , V_21 , V_46 ) ;
}
static int T_1 F_68 ( void )
{
F_69 ( V_66 ) ;
return 0 ;
}
