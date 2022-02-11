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
F_8 ( V_7 != V_9 ) ;
V_7 |= V_12 & ~ V_11 ;
return V_7 ;
}
static inline T_2 F_9 ( void * V_14 )
{
return F_3 ( F_10 ( V_14 ) ) ;
}
static int F_11 ( unsigned long V_13 ,
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
static inline int F_12 ( T_3 V_21 , T_4 V_22 )
{
unsigned long V_13 = F_5 ( V_21 ) ;
unsigned int V_15 = V_21 & ~ V_11 ;
if ( V_15 + V_22 <= V_20 )
return 0 ;
if ( F_11 ( V_13 , V_15 , V_22 ) )
return 0 ;
return 1 ;
}
static int F_13 ( T_2 V_23 )
{
unsigned long V_8 = F_5 ( V_23 ) ;
unsigned long V_13 = F_14 ( V_8 ) ;
T_3 V_7 ;
if ( F_15 ( V_13 ) ) {
V_7 = F_16 ( V_13 ) ;
return V_7 >= F_10 ( V_24 ) &&
V_7 < F_10 ( V_25 ) ;
}
return 0 ;
}
static int
F_17 ( void * V_26 , T_4 V_22 , unsigned long V_27 )
{
int V_18 , V_28 ;
int V_29 ;
T_2 V_30 ;
T_3 V_21 = F_10 ( V_26 ) ;
V_29 = F_18 ( V_31 << V_32 ) + V_10 ;
V_18 = 0 ;
do {
int V_33 = F_19 ( V_27 - V_18 , ( unsigned long ) V_31 ) ;
do {
V_28 = F_20 (
V_21 + ( V_18 << V_32 ) ,
F_18 ( V_33 << V_32 ) ,
V_29 , & V_30 ) ;
} while ( V_28 && V_29 ++ < V_34 );
if ( V_28 )
return V_28 ;
V_18 += V_33 ;
} while ( V_18 < V_27 );
return 0 ;
}
static unsigned long F_21 ( unsigned long V_35 )
{
if ( ! V_35 ) {
V_36 = ( 64 * 1024 * 1024 >> V_32 ) ;
V_36 = F_22 ( V_36 , V_31 ) ;
} else
V_36 = V_35 ;
return V_36 << V_32 ;
}
static const char * F_23 ( enum V_37 V_38 )
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
int T_5 F_24 ( int V_41 , bool V_42 )
{
unsigned long V_43 , V_44 ;
int V_28 = - V_45 ;
enum V_37 V_46 = V_47 ;
unsigned int V_48 = 3 ;
V_36 = F_25 () ;
V_49:
V_43 = F_21 ( V_36 ) ;
V_44 = F_18 ( V_36 << V_32 ) ;
if ( V_42 )
V_24 = F_26 ( F_27 ( V_43 ) ) ;
else {
#define F_28 (1 << (PAGE_SHIFT - IO_TLB_SHIFT))
#define F_29 ((1<<20) >> IO_TLB_SHIFT)
while ( ( F_28 << V_44 ) > F_29 ) {
V_24 = ( void * ) F_30 ( V_50 , V_44 ) ;
if ( V_24 )
break;
V_44 -- ;
}
if ( V_44 != F_18 ( V_43 ) ) {
F_31 ( L_7 ,
( V_20 << V_44 ) >> 20 ) ;
V_36 = F_28 << V_44 ;
V_43 = V_36 << V_32 ;
}
}
if ( ! V_24 ) {
V_46 = V_39 ;
goto error;
}
V_25 = V_24 + V_43 ;
V_28 = F_17 ( V_24 ,
V_43 ,
V_36 ) ;
if ( V_28 ) {
if ( V_42 )
F_32 ( F_33 ( V_24 ) , F_27 ( V_43 ) ) ;
else {
F_34 ( ( unsigned long ) V_24 , V_44 ) ;
V_24 = NULL ;
}
V_46 = V_40 ;
goto error;
}
V_51 = F_9 ( V_24 ) ;
if ( V_42 ) {
if ( F_35 ( V_24 , V_36 ,
V_41 ) )
F_36 ( L_8 ) ;
V_28 = 0 ;
} else
V_28 = F_37 ( V_24 , V_36 ) ;
return V_28 ;
error:
if ( V_48 -- ) {
V_36 = F_38 ( 1024UL ,
( V_36 >> 1 ) ) ;
F_39 ( L_9 ,
( V_36 << V_32 ) >> 20 ) ;
goto V_49;
}
F_40 ( L_10 , F_23 ( V_46 ) , V_28 ) ;
if ( V_42 )
F_36 ( L_11 , F_23 ( V_46 ) , V_28 ) ;
else
F_34 ( ( unsigned long ) V_24 , V_44 ) ;
return V_28 ;
}
void *
F_41 ( struct V_1 * V_52 , T_4 V_22 ,
T_2 * V_30 , T_1 V_53 ,
struct V_54 * V_55 )
{
void * V_56 ;
int V_44 = F_18 ( V_22 ) ;
T_6 V_4 = F_2 ( 32 ) ;
T_3 V_57 ;
T_2 V_58 ;
V_53 &= ~ ( V_59 | V_60 ) ;
if ( F_42 ( V_52 , V_22 , V_30 , & V_56 ) )
return V_56 ;
V_56 = F_43 ( V_52 , V_22 , V_30 , V_53 , V_55 ) ;
if ( ! V_56 )
return V_56 ;
if ( V_52 && V_52 -> V_5 )
V_4 = F_1 ( V_52 , V_53 ) ;
V_57 = * V_30 ;
V_58 = F_3 ( V_57 ) ;
if ( ( ( V_58 + V_22 - 1 <= V_4 ) ) &&
! F_12 ( V_57 , V_22 ) )
* V_30 = V_58 ;
else {
if ( F_20 ( V_57 , V_44 ,
F_44 ( V_4 ) , V_30 ) != 0 ) {
F_45 ( V_52 , V_22 , V_56 , ( T_2 ) V_57 , V_55 ) ;
return NULL ;
}
}
memset ( V_56 , 0 , V_22 ) ;
return V_56 ;
}
void
F_46 ( struct V_1 * V_52 , T_4 V_22 , void * V_61 ,
T_2 V_58 , struct V_54 * V_55 )
{
int V_44 = F_18 ( V_22 ) ;
T_3 V_57 ;
T_6 V_4 = F_2 ( 32 ) ;
if ( F_47 ( V_52 , V_44 , V_61 ) )
return;
if ( V_52 && V_52 -> V_5 )
V_4 = V_52 -> V_5 ;
V_57 = F_6 ( V_58 ) ;
if ( ( ( V_58 + V_22 - 1 > V_4 ) ) ||
F_12 ( V_57 , V_22 ) )
F_48 ( V_57 , V_44 ) ;
F_45 ( V_52 , V_22 , V_61 , ( T_2 ) V_57 , V_55 ) ;
}
T_2 F_49 ( struct V_1 * V_2 , struct V_62 * V_62 ,
unsigned long V_15 , T_4 V_22 ,
enum V_63 V_64 ,
struct V_54 * V_55 )
{
T_3 V_65 , V_57 = F_50 ( V_62 ) + V_15 ;
T_2 V_58 = F_3 ( V_57 ) ;
F_8 ( V_64 == V_66 ) ;
if ( F_51 ( V_2 , V_58 , V_22 ) &&
! F_12 ( V_57 , V_22 ) && ! V_67 ) {
F_52 ( V_2 , V_62 , V_15 , V_22 , V_64 , V_55 ) ;
return V_58 ;
}
F_53 ( V_2 , V_58 , V_22 , V_67 ) ;
V_65 = F_54 ( V_2 , V_51 , V_57 , V_22 , V_64 ) ;
if ( V_65 == V_68 )
return V_69 ;
F_52 ( V_2 , F_55 ( V_65 >> V_10 ) ,
V_65 & ~ V_11 , V_22 , V_64 , V_55 ) ;
V_58 = F_3 ( V_65 ) ;
if ( ! F_51 ( V_2 , V_58 , V_22 ) ) {
F_56 ( V_2 , V_65 , V_22 , V_64 ) ;
V_58 = 0 ;
}
return V_58 ;
}
static void F_57 ( struct V_1 * V_52 , T_2 V_58 ,
T_4 V_22 , enum V_63 V_64 ,
struct V_54 * V_55 )
{
T_3 V_7 = F_6 ( V_58 ) ;
F_8 ( V_64 == V_66 ) ;
F_58 ( V_52 , V_7 , V_22 , V_64 , V_55 ) ;
if ( F_13 ( V_58 ) ) {
F_56 ( V_52 , V_7 , V_22 , V_64 ) ;
return;
}
if ( V_64 != V_70 )
return;
F_59 ( F_60 ( V_7 ) , V_22 ) ;
}
void F_61 ( struct V_1 * V_52 , T_2 V_58 ,
T_4 V_22 , enum V_63 V_64 ,
struct V_54 * V_55 )
{
F_57 ( V_52 , V_58 , V_22 , V_64 , V_55 ) ;
}
static void
F_62 ( struct V_1 * V_52 , T_2 V_58 ,
T_4 V_22 , enum V_63 V_64 ,
enum V_71 V_72 )
{
T_3 V_7 = F_6 ( V_58 ) ;
F_8 ( V_64 == V_66 ) ;
if ( V_72 == V_73 )
F_63 ( V_52 , V_7 , V_22 , V_64 ) ;
if ( F_13 ( V_58 ) )
F_64 ( V_52 , V_7 , V_22 , V_64 , V_72 ) ;
if ( V_72 == V_74 )
F_63 ( V_52 , V_7 , V_22 , V_64 ) ;
if ( V_64 != V_70 )
return;
F_59 ( F_60 ( V_7 ) , V_22 ) ;
}
void
F_65 ( struct V_1 * V_52 , T_2 V_58 ,
T_4 V_22 , enum V_63 V_64 )
{
F_62 ( V_52 , V_58 , V_22 , V_64 , V_73 ) ;
}
void
F_66 ( struct V_1 * V_52 , T_2 V_58 ,
T_4 V_22 , enum V_63 V_64 )
{
F_62 ( V_52 , V_58 , V_22 , V_64 , V_74 ) ;
}
int
F_67 ( struct V_1 * V_52 , struct V_75 * V_76 ,
int V_77 , enum V_63 V_64 ,
struct V_54 * V_55 )
{
struct V_75 * V_78 ;
int V_18 ;
F_8 ( V_64 == V_66 ) ;
F_68 (sgl, sg, nelems, i) {
T_3 V_7 = F_69 ( V_78 ) ;
T_2 V_58 = F_3 ( V_7 ) ;
if ( V_67 ||
! F_51 ( V_52 , V_58 , V_78 -> V_16 ) ||
F_12 ( V_7 , V_78 -> V_16 ) ) {
T_3 V_65 = F_54 ( V_52 ,
V_51 ,
F_69 ( V_78 ) ,
V_78 -> V_16 ,
V_64 ) ;
if ( V_65 == V_68 ) {
F_70 ( V_52 , L_12 ) ;
F_71 ( V_52 , V_76 , V_18 , V_64 ,
V_55 ) ;
F_72 ( V_76 ) = 0 ;
return 0 ;
}
F_52 ( V_52 , F_55 ( V_65 >> V_10 ) ,
V_65 & ~ V_11 ,
V_78 -> V_16 ,
V_64 ,
V_55 ) ;
V_78 -> V_79 = F_3 ( V_65 ) ;
} else {
F_52 ( V_52 , F_55 ( V_7 >> V_10 ) ,
V_7 & ~ V_11 ,
V_78 -> V_16 ,
V_64 ,
V_55 ) ;
V_78 -> V_79 = V_58 ;
}
F_72 ( V_78 ) = V_78 -> V_16 ;
}
return V_77 ;
}
void
F_71 ( struct V_1 * V_52 , struct V_75 * V_76 ,
int V_77 , enum V_63 V_64 ,
struct V_54 * V_55 )
{
struct V_75 * V_78 ;
int V_18 ;
F_8 ( V_64 == V_66 ) ;
F_68 (sgl, sg, nelems, i)
F_57 ( V_52 , V_78 -> V_79 , F_72 ( V_78 ) , V_64 , V_55 ) ;
}
static void
F_73 ( struct V_1 * V_52 , struct V_75 * V_76 ,
int V_77 , enum V_63 V_64 ,
enum V_71 V_72 )
{
struct V_75 * V_78 ;
int V_18 ;
F_68 (sgl, sg, nelems, i)
F_62 ( V_52 , V_78 -> V_79 ,
F_72 ( V_78 ) , V_64 , V_72 ) ;
}
void
F_74 ( struct V_1 * V_52 , struct V_75 * V_78 ,
int V_77 , enum V_63 V_64 )
{
F_73 ( V_52 , V_78 , V_77 , V_64 , V_73 ) ;
}
void
F_75 ( struct V_1 * V_52 , struct V_75 * V_78 ,
int V_77 , enum V_63 V_64 )
{
F_73 ( V_52 , V_78 , V_77 , V_64 , V_74 ) ;
}
int
F_76 ( struct V_1 * V_52 , T_2 V_23 )
{
return ! V_23 ;
}
int
F_77 ( struct V_1 * V_52 , T_6 V_80 )
{
return F_9 ( V_25 - 1 ) <= V_80 ;
}
int
F_78 ( struct V_1 * V_2 , T_6 V_4 )
{
if ( ! V_2 -> V_4 || ! F_77 ( V_2 , V_4 ) )
return - V_81 ;
* V_2 -> V_4 = V_4 ;
return 0 ;
}
