static unsigned long F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
unsigned long V_4 = 0 ;
V_4 = V_2 -> V_5 ;
if ( ! V_4 )
V_4 = ( V_3 & V_6 ) ? F_2 ( 24 ) : F_2 ( 32 ) ;
return V_4 ;
}
static inline T_2 F_3 ( T_3 V_7 )
{
unsigned long V_8 = F_4 ( F_5 ( V_7 ) ) ;
T_2 V_9 = ( T_2 ) V_8 << V_10 ;
V_9 |= V_7 & ~ V_11 ;
return V_9 ;
}
static inline T_3 F_6 ( T_2 V_12 )
{
unsigned long V_13 = F_7 ( F_5 ( V_12 ) ) ;
T_2 V_9 = ( T_2 ) V_13 << V_10 ;
T_3 V_7 = V_9 ;
V_7 |= V_12 & ~ V_11 ;
return V_7 ;
}
static inline T_2 F_8 ( void * V_14 )
{
return F_3 ( F_9 ( V_14 ) ) ;
}
static int F_10 ( unsigned long V_13 ,
unsigned int V_15 ,
T_4 V_16 )
{
unsigned long V_17 ;
int V_18 ;
int V_19 ;
V_17 = F_4 ( V_13 ) ;
V_19 = ( V_15 + V_16 + V_20 - 1 ) >> V_10 ;
for ( V_18 = 1 ; V_18 < V_19 ; V_18 ++ ) {
if ( F_4 ( ++ V_13 ) != ++ V_17 )
return 0 ;
}
return 1 ;
}
static inline int F_11 ( T_3 V_21 , T_4 V_22 )
{
unsigned long V_13 = F_5 ( V_21 ) ;
unsigned int V_15 = V_21 & ~ V_11 ;
if ( V_15 + V_22 <= V_20 )
return 0 ;
if ( F_10 ( V_13 , V_15 , V_22 ) )
return 0 ;
return 1 ;
}
static int F_12 ( T_2 V_23 )
{
unsigned long V_8 = F_5 ( V_23 ) ;
unsigned long V_13 = F_13 ( V_8 ) ;
T_3 V_7 ;
if ( F_14 ( V_13 ) ) {
V_7 = F_15 ( V_13 ) ;
return V_7 >= F_9 ( V_24 ) &&
V_7 < F_9 ( V_25 ) ;
}
return 0 ;
}
static int
F_16 ( void * V_26 , T_4 V_22 , unsigned long V_27 )
{
int V_18 , V_28 ;
int V_29 ;
T_2 V_30 ;
T_3 V_21 = F_9 ( V_26 ) ;
V_29 = F_17 ( V_31 << V_32 ) + V_10 ;
V_18 = 0 ;
do {
int V_33 = F_18 ( V_27 - V_18 , ( unsigned long ) V_31 ) ;
do {
V_28 = F_19 (
V_21 + ( V_18 << V_32 ) ,
F_17 ( V_33 << V_32 ) ,
V_29 , & V_30 ) ;
} while ( V_28 && V_29 ++ < V_34 );
if ( V_28 )
return V_28 ;
V_18 += V_33 ;
} while ( V_18 < V_27 );
return 0 ;
}
static unsigned long F_20 ( unsigned long V_35 )
{
if ( ! V_35 ) {
V_36 = ( 64 * 1024 * 1024 >> V_32 ) ;
V_36 = F_21 ( V_36 , V_31 ) ;
} else
V_36 = V_35 ;
return V_36 << V_32 ;
}
static const char * F_22 ( enum V_37 V_38 )
{
switch ( V_38 ) {
case V_39 :
return L_1 ;
case V_40 :
return L_2\
L_3\
L_4\
L_5 ;
default:
break;
}
return L_6 ;
}
int T_5 F_23 ( int V_41 , bool V_42 )
{
unsigned long V_43 , V_44 ;
int V_28 = - V_45 ;
enum V_37 V_46 = V_47 ;
unsigned int V_48 = 3 ;
V_36 = F_24 () ;
V_49:
V_43 = F_20 ( V_36 ) ;
V_44 = F_17 ( V_36 << V_32 ) ;
if ( V_42 )
V_24 = F_25 ( F_26 ( V_43 ) ) ;
else {
#define F_27 (1 << (PAGE_SHIFT - IO_TLB_SHIFT))
#define F_28 ((1<<20) >> IO_TLB_SHIFT)
while ( ( F_27 << V_44 ) > F_28 ) {
V_24 = ( void * ) F_29 ( V_44 ) ;
if ( V_24 )
break;
V_44 -- ;
}
if ( V_44 != F_17 ( V_43 ) ) {
F_30 ( L_7 ,
( V_20 << V_44 ) >> 20 ) ;
V_36 = F_27 << V_44 ;
V_43 = V_36 << V_32 ;
}
}
if ( ! V_24 ) {
V_46 = V_39 ;
goto error;
}
V_25 = V_24 + V_43 ;
V_28 = F_16 ( V_24 ,
V_43 ,
V_36 ) ;
if ( V_28 ) {
if ( V_42 )
F_31 ( F_32 ( V_24 ) , F_26 ( V_43 ) ) ;
else {
F_33 ( ( unsigned long ) V_24 , V_44 ) ;
V_24 = NULL ;
}
V_46 = V_40 ;
goto error;
}
V_50 = F_8 ( V_24 ) ;
if ( V_42 ) {
if ( F_34 ( V_24 , V_36 ,
V_41 ) )
F_35 ( L_8 ) ;
V_28 = 0 ;
} else
V_28 = F_36 ( V_24 , V_36 ) ;
return V_28 ;
error:
if ( V_48 -- ) {
V_36 = F_37 ( 1024UL ,
( V_36 >> 1 ) ) ;
F_38 ( L_9 ,
( V_36 << V_32 ) >> 20 ) ;
goto V_49;
}
F_39 ( L_10 , F_22 ( V_46 ) , V_28 ) ;
if ( V_42 )
F_35 ( L_11 , F_22 ( V_46 ) , V_28 ) ;
else
F_33 ( ( unsigned long ) V_24 , V_44 ) ;
return V_28 ;
}
void *
F_40 ( struct V_1 * V_51 , T_4 V_22 ,
T_2 * V_30 , T_1 V_52 ,
struct V_53 * V_54 )
{
void * V_55 ;
int V_44 = F_17 ( V_22 ) ;
T_6 V_4 = F_2 ( 32 ) ;
T_3 V_56 ;
T_2 V_57 ;
V_52 &= ~ ( V_58 | V_59 ) ;
if ( F_41 ( V_51 , V_22 , V_30 , & V_55 ) )
return V_55 ;
V_55 = F_42 ( V_51 , V_22 , V_30 , V_52 , V_54 ) ;
if ( ! V_55 )
return V_55 ;
if ( V_51 && V_51 -> V_5 )
V_4 = F_1 ( V_51 , V_52 ) ;
V_56 = * V_30 ;
V_57 = F_3 ( V_56 ) ;
if ( ( ( V_57 + V_22 - 1 <= V_4 ) ) &&
! F_11 ( V_56 , V_22 ) )
* V_30 = V_57 ;
else {
if ( F_19 ( V_56 , V_44 ,
F_43 ( V_4 ) , V_30 ) != 0 ) {
F_44 ( V_51 , V_22 , V_55 , ( T_2 ) V_56 , V_54 ) ;
return NULL ;
}
}
memset ( V_55 , 0 , V_22 ) ;
return V_55 ;
}
void
F_45 ( struct V_1 * V_51 , T_4 V_22 , void * V_60 ,
T_2 V_57 , struct V_53 * V_54 )
{
int V_44 = F_17 ( V_22 ) ;
T_3 V_56 ;
T_6 V_4 = F_2 ( 32 ) ;
if ( F_46 ( V_51 , V_44 , V_60 ) )
return;
if ( V_51 && V_51 -> V_5 )
V_4 = V_51 -> V_5 ;
V_56 = F_6 ( V_57 ) ;
if ( ( ( V_57 + V_22 - 1 > V_4 ) ) ||
F_11 ( V_56 , V_22 ) )
F_47 ( V_56 , V_44 ) ;
F_44 ( V_51 , V_22 , V_60 , ( T_2 ) V_56 , V_54 ) ;
}
T_2 F_48 ( struct V_1 * V_2 , struct V_61 * V_61 ,
unsigned long V_15 , T_4 V_22 ,
enum V_62 V_63 ,
struct V_53 * V_54 )
{
T_3 V_64 , V_56 = F_49 ( V_61 ) + V_15 ;
T_2 V_57 = F_3 ( V_56 ) ;
F_50 ( V_63 == V_65 ) ;
if ( F_51 ( V_2 , V_57 , V_22 ) &&
! F_11 ( V_56 , V_22 ) &&
! F_52 ( V_2 , F_5 ( V_56 ) , F_5 ( V_57 ) ) &&
! V_66 ) {
F_53 ( V_2 , V_61 , V_57 , V_15 , V_22 , V_63 , V_54 ) ;
return V_57 ;
}
F_54 ( V_2 , V_57 , V_22 , V_66 ) ;
V_64 = F_55 ( V_2 , V_50 , V_56 , V_22 , V_63 ) ;
if ( V_64 == V_67 )
return V_68 ;
F_53 ( V_2 , F_56 ( V_64 >> V_10 ) ,
V_57 , V_64 & ~ V_11 , V_22 , V_63 , V_54 ) ;
V_57 = F_3 ( V_64 ) ;
if ( ! F_51 ( V_2 , V_57 , V_22 ) ) {
F_57 ( V_2 , V_64 , V_22 , V_63 ) ;
V_57 = 0 ;
}
return V_57 ;
}
static void F_58 ( struct V_1 * V_51 , T_2 V_57 ,
T_4 V_22 , enum V_62 V_63 ,
struct V_53 * V_54 )
{
T_3 V_7 = F_6 ( V_57 ) ;
F_50 ( V_63 == V_65 ) ;
F_59 ( V_51 , V_57 , V_22 , V_63 , V_54 ) ;
if ( F_12 ( V_57 ) ) {
F_57 ( V_51 , V_7 , V_22 , V_63 ) ;
return;
}
if ( V_63 != V_69 )
return;
F_60 ( F_61 ( V_7 ) , V_22 ) ;
}
void F_62 ( struct V_1 * V_51 , T_2 V_57 ,
T_4 V_22 , enum V_62 V_63 ,
struct V_53 * V_54 )
{
F_58 ( V_51 , V_57 , V_22 , V_63 , V_54 ) ;
}
static void
F_63 ( struct V_1 * V_51 , T_2 V_57 ,
T_4 V_22 , enum V_62 V_63 ,
enum V_70 V_71 )
{
T_3 V_7 = F_6 ( V_57 ) ;
F_50 ( V_63 == V_65 ) ;
if ( V_71 == V_72 )
F_64 ( V_51 , V_57 , V_22 , V_63 ) ;
if ( F_12 ( V_57 ) )
F_65 ( V_51 , V_7 , V_22 , V_63 , V_71 ) ;
if ( V_71 == V_73 )
F_66 ( V_51 , V_57 , V_22 , V_63 ) ;
if ( V_63 != V_69 )
return;
F_60 ( F_61 ( V_7 ) , V_22 ) ;
}
void
F_67 ( struct V_1 * V_51 , T_2 V_57 ,
T_4 V_22 , enum V_62 V_63 )
{
F_63 ( V_51 , V_57 , V_22 , V_63 , V_72 ) ;
}
void
F_68 ( struct V_1 * V_51 , T_2 V_57 ,
T_4 V_22 , enum V_62 V_63 )
{
F_63 ( V_51 , V_57 , V_22 , V_63 , V_73 ) ;
}
int
F_69 ( struct V_1 * V_51 , struct V_74 * V_75 ,
int V_76 , enum V_62 V_63 ,
struct V_53 * V_54 )
{
struct V_74 * V_77 ;
int V_18 ;
F_50 ( V_63 == V_65 ) ;
F_70 (sgl, sg, nelems, i) {
T_3 V_7 = F_71 ( V_77 ) ;
T_2 V_57 = F_3 ( V_7 ) ;
if ( V_66 ||
F_52 ( V_51 , F_5 ( V_7 ) , F_5 ( V_57 ) ) ||
! F_51 ( V_51 , V_57 , V_77 -> V_16 ) ||
F_11 ( V_7 , V_77 -> V_16 ) ) {
T_3 V_64 = F_55 ( V_51 ,
V_50 ,
F_71 ( V_77 ) ,
V_77 -> V_16 ,
V_63 ) ;
if ( V_64 == V_67 ) {
F_72 ( V_51 , L_12 ) ;
F_73 ( V_51 , V_75 , V_18 , V_63 ,
V_54 ) ;
F_74 ( V_75 ) = 0 ;
return 0 ;
}
F_53 ( V_51 , F_56 ( V_64 >> V_10 ) ,
V_57 ,
V_64 & ~ V_11 ,
V_77 -> V_16 ,
V_63 ,
V_54 ) ;
V_77 -> V_78 = F_3 ( V_64 ) ;
} else {
F_53 ( V_51 , F_56 ( V_7 >> V_10 ) ,
V_57 ,
V_7 & ~ V_11 ,
V_77 -> V_16 ,
V_63 ,
V_54 ) ;
V_77 -> V_78 = V_57 ;
}
F_74 ( V_77 ) = V_77 -> V_16 ;
}
return V_76 ;
}
void
F_73 ( struct V_1 * V_51 , struct V_74 * V_75 ,
int V_76 , enum V_62 V_63 ,
struct V_53 * V_54 )
{
struct V_74 * V_77 ;
int V_18 ;
F_50 ( V_63 == V_65 ) ;
F_70 (sgl, sg, nelems, i)
F_58 ( V_51 , V_77 -> V_78 , F_74 ( V_77 ) , V_63 , V_54 ) ;
}
static void
F_75 ( struct V_1 * V_51 , struct V_74 * V_75 ,
int V_76 , enum V_62 V_63 ,
enum V_70 V_71 )
{
struct V_74 * V_77 ;
int V_18 ;
F_70 (sgl, sg, nelems, i)
F_63 ( V_51 , V_77 -> V_78 ,
F_74 ( V_77 ) , V_63 , V_71 ) ;
}
void
F_76 ( struct V_1 * V_51 , struct V_74 * V_77 ,
int V_76 , enum V_62 V_63 )
{
F_75 ( V_51 , V_77 , V_76 , V_63 , V_72 ) ;
}
void
F_77 ( struct V_1 * V_51 , struct V_74 * V_77 ,
int V_76 , enum V_62 V_63 )
{
F_75 ( V_51 , V_77 , V_76 , V_63 , V_73 ) ;
}
int
F_78 ( struct V_1 * V_51 , T_2 V_23 )
{
return ! V_23 ;
}
int
F_79 ( struct V_1 * V_51 , T_6 V_79 )
{
return F_8 ( V_25 - 1 ) <= V_79 ;
}
int
F_80 ( struct V_1 * V_2 , T_6 V_4 )
{
if ( ! V_2 -> V_4 || ! F_79 ( V_2 , V_4 ) )
return - V_80 ;
* V_2 -> V_4 = V_4 ;
return 0 ;
}
