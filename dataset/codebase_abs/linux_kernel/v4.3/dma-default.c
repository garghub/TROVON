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
if ( V_5 -> V_18 < F_13 ( 32 ) )
V_12 = V_13 ;
else if ( V_5 -> V_18 < F_13 ( 64 ) )
V_12 = V_14 ;
else
#endif
#if F_12 ( V_16 ) && ! F_12 ( V_17 )
if ( V_5 -> V_18 < F_13 ( 64 ) )
V_12 = V_14 ;
else
#endif
#if F_12 ( V_17 ) && ! F_12 ( V_16 )
if ( V_5 -> V_18 < F_13 ( sizeof( V_19 ) * 8 ) )
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
if ( F_21 ( V_28 ) && ! ( V_11 & V_29 ) )
V_3 = F_22 ( V_5 ,
V_26 , F_16 ( V_21 ) ) ;
if ( ! V_3 )
V_3 = F_23 ( V_11 , F_16 ( V_21 ) ) ;
if ( ! V_3 )
return NULL ;
V_23 = F_24 ( V_3 ) ;
memset ( V_23 , 0 , V_21 ) ;
* V_22 = F_17 ( V_5 , V_23 , V_21 ) ;
if ( ! F_8 ( V_5 ) ) {
F_25 ( ( unsigned long ) V_23 , V_21 ) ;
if ( ! V_30 )
V_23 = F_26 ( V_23 ) ;
}
return V_23 ;
}
static void F_27 ( struct V_4 * V_5 , T_4 V_21 ,
void * V_31 , T_2 V_22 )
{
F_28 ( V_5 , V_22 , V_21 , V_32 ) ;
F_29 ( ( unsigned long ) V_31 , F_16 ( V_21 ) ) ;
}
static void F_30 ( struct V_4 * V_5 , T_4 V_21 , void * V_31 ,
T_2 V_22 , struct V_24 * V_25 )
{
unsigned long V_33 = ( unsigned long ) V_31 ;
unsigned int V_26 = F_19 ( V_21 ) >> V_7 ;
struct V_3 * V_3 = NULL ;
if ( F_20 ( V_27 , V_25 ) ) {
F_27 ( V_5 , V_21 , V_31 , V_22 ) ;
return;
}
F_28 ( V_5 , V_22 , V_21 , V_32 ) ;
if ( ! F_8 ( V_5 ) && ! V_30 )
V_33 = F_31 ( V_33 ) ;
V_3 = F_32 ( ( void * ) V_33 ) ;
if ( ! F_33 ( V_5 , V_3 , V_26 ) )
F_34 ( V_3 , F_16 ( V_21 ) ) ;
}
static int F_35 ( struct V_4 * V_5 , struct V_34 * V_35 ,
void * V_36 , T_2 V_6 , T_4 V_21 ,
struct V_24 * V_25 )
{
unsigned long V_37 = ( V_35 -> V_38 - V_35 -> V_39 ) >> V_7 ;
unsigned long V_26 = F_19 ( V_21 ) >> V_7 ;
unsigned long V_33 = ( unsigned long ) V_36 ;
unsigned long V_40 = V_35 -> V_41 ;
unsigned long V_42 ;
int V_23 = - V_43 ;
if ( ! F_8 ( V_5 ) && ! V_30 )
V_33 = F_31 ( V_33 ) ;
V_42 = F_36 ( F_32 ( ( void * ) V_33 ) ) ;
if ( F_20 ( V_44 , V_25 ) )
V_35 -> V_45 = F_37 ( V_35 -> V_45 ) ;
else
V_35 -> V_45 = F_38 ( V_35 -> V_45 ) ;
if ( F_39 ( V_5 , V_35 , V_36 , V_21 , & V_23 ) )
return V_23 ;
if ( V_40 < V_26 && V_37 <= ( V_26 - V_40 ) ) {
V_23 = F_40 ( V_35 , V_35 -> V_39 ,
V_42 + V_40 ,
V_37 << V_7 ,
V_35 -> V_45 ) ;
}
return V_23 ;
}
static inline void F_41 ( void * V_33 , T_4 V_21 ,
enum V_46 V_47 )
{
switch ( V_47 ) {
case V_48 :
F_42 ( ( unsigned long ) V_33 , V_21 ) ;
break;
case V_49 :
F_43 ( ( unsigned long ) V_33 , V_21 ) ;
break;
case V_32 :
F_25 ( ( unsigned long ) V_33 , V_21 ) ;
break;
default:
F_44 () ;
}
}
static inline void F_45 ( struct V_3 * V_3 ,
unsigned long V_50 , T_4 V_21 , enum V_46 V_47 )
{
T_4 V_51 = V_21 ;
do {
T_4 V_52 = V_51 ;
if ( F_46 ( V_3 ) ) {
void * V_33 ;
if ( V_50 + V_52 > V_53 ) {
if ( V_50 >= V_53 ) {
V_3 += V_50 >> V_7 ;
V_50 &= ~ V_54 ;
}
V_52 = V_53 - V_50 ;
}
V_33 = F_47 ( V_3 ) ;
F_41 ( V_33 + V_50 , V_52 , V_47 ) ;
F_48 ( V_33 ) ;
} else
F_41 ( F_24 ( V_3 ) + V_50 ,
V_21 , V_47 ) ;
V_50 = 0 ;
V_3 ++ ;
V_51 -= V_52 ;
} while ( V_51 );
}
static void F_49 ( struct V_4 * V_5 , T_2 V_6 ,
T_4 V_21 , enum V_46 V_47 , struct V_24 * V_25 )
{
if ( F_7 ( V_5 ) )
F_45 ( F_4 ( V_5 , V_6 ) ,
V_6 & ~ V_54 , V_21 , V_47 ) ;
F_50 ( V_5 ) ;
F_28 ( V_5 , V_6 , V_21 , V_47 ) ;
}
static int F_51 ( struct V_4 * V_5 , struct V_55 * V_56 ,
int V_57 , enum V_46 V_47 , struct V_24 * V_25 )
{
int V_58 ;
struct V_55 * V_59 ;
F_52 (sglist, sg, nents, i) {
if ( ! F_8 ( V_5 ) )
F_45 ( F_53 ( V_59 ) , V_59 -> V_50 , V_59 -> V_60 ,
V_47 ) ;
#ifdef F_54
V_59 -> V_61 = V_59 -> V_60 ;
#endif
V_59 -> V_62 = F_55 ( V_5 , F_53 ( V_59 ) ) +
V_59 -> V_50 ;
}
return V_57 ;
}
static T_2 F_56 ( struct V_4 * V_5 , struct V_3 * V_3 ,
unsigned long V_50 , T_4 V_21 , enum V_46 V_47 ,
struct V_24 * V_25 )
{
if ( ! F_8 ( V_5 ) )
F_45 ( V_3 , V_50 , V_21 , V_47 ) ;
return F_55 ( V_5 , V_3 ) + V_50 ;
}
static void F_57 ( struct V_4 * V_5 , struct V_55 * V_56 ,
int V_63 , enum V_46 V_47 ,
struct V_24 * V_25 )
{
int V_58 ;
struct V_55 * V_59 ;
F_52 (sglist, sg, nhwentries, i) {
if ( ! F_8 ( V_5 ) &&
V_47 != V_48 )
F_45 ( F_53 ( V_59 ) , V_59 -> V_50 , V_59 -> V_60 ,
V_47 ) ;
F_28 ( V_5 , V_59 -> V_62 , V_59 -> V_60 , V_47 ) ;
}
}
static void F_58 ( struct V_4 * V_5 ,
T_2 V_22 , T_4 V_21 , enum V_46 V_47 )
{
if ( F_7 ( V_5 ) )
F_45 ( F_4 ( V_5 , V_22 ) ,
V_22 & ~ V_54 , V_21 , V_47 ) ;
F_50 ( V_5 ) ;
}
static void F_59 ( struct V_4 * V_5 ,
T_2 V_22 , T_4 V_21 , enum V_46 V_47 )
{
if ( ! F_8 ( V_5 ) )
F_45 ( F_4 ( V_5 , V_22 ) ,
V_22 & ~ V_54 , V_21 , V_47 ) ;
}
static void F_60 ( struct V_4 * V_5 ,
struct V_55 * V_56 , int V_64 ,
enum V_46 V_47 )
{
int V_58 ;
struct V_55 * V_59 ;
if ( F_7 ( V_5 ) ) {
F_52 (sglist, sg, nelems, i) {
F_45 ( F_53 ( V_59 ) , V_59 -> V_50 , V_59 -> V_60 ,
V_47 ) ;
}
}
F_50 ( V_5 ) ;
}
static void F_61 ( struct V_4 * V_5 ,
struct V_55 * V_56 , int V_64 ,
enum V_46 V_47 )
{
int V_58 ;
struct V_55 * V_59 ;
if ( ! F_8 ( V_5 ) ) {
F_52 (sglist, sg, nelems, i) {
F_45 ( F_53 ( V_59 ) , V_59 -> V_50 , V_59 -> V_60 ,
V_47 ) ;
}
}
}
int F_62 ( struct V_4 * V_5 , T_2 V_6 )
{
return 0 ;
}
int F_63 ( struct V_4 * V_5 , T_5 V_65 )
{
return F_64 ( V_5 , V_65 ) ;
}
void F_65 ( struct V_4 * V_5 , void * V_31 , T_4 V_21 ,
enum V_46 V_47 )
{
F_66 ( V_47 == V_66 ) ;
if ( ! F_8 ( V_5 ) )
F_41 ( V_31 , V_21 , V_47 ) ;
}
static int T_1 F_67 ( void )
{
F_68 ( V_67 ) ;
return 0 ;
}
