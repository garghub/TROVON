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
T_3 V_7 = F_14 ( V_13 ) ;
if ( F_15 ( F_16 ( V_7 ) ) ) {
return V_7 >= F_9 ( V_24 ) &&
V_7 < F_9 ( V_25 ) ;
}
return 0 ;
}
static int
F_17 ( void * V_26 , T_4 V_22 , unsigned long V_27 )
{
int V_18 , V_28 ;
int V_29 ;
T_2 V_30 ;
T_3 V_21 = F_9 ( V_26 ) ;
V_29 = F_18 ( V_31 << V_32 ) + V_33 ;
V_18 = 0 ;
do {
int V_34 = F_19 ( V_27 - V_18 , ( unsigned long ) V_31 ) ;
do {
V_28 = F_20 (
V_21 + ( V_18 << V_32 ) ,
F_18 ( V_34 << V_32 ) ,
V_29 , & V_30 ) ;
} while ( V_28 && V_29 ++ < V_35 );
if ( V_28 )
return V_28 ;
V_18 += V_34 ;
} while ( V_18 < V_27 );
return 0 ;
}
static unsigned long F_21 ( unsigned long V_36 )
{
if ( ! V_36 ) {
V_37 = ( 64 * 1024 * 1024 >> V_32 ) ;
V_37 = F_22 ( V_37 , V_31 ) ;
} else
V_37 = V_36 ;
return V_37 << V_32 ;
}
static const char * F_23 ( enum V_38 V_39 )
{
switch ( V_39 ) {
case V_40 :
return L_1 ;
case V_41 :
return L_2\
L_3\
L_4\
L_5 ;
default:
break;
}
return L_6 ;
}
int T_5 F_24 ( int V_42 , bool V_43 )
{
unsigned long V_44 , V_45 ;
int V_28 = - V_46 ;
enum V_38 V_47 = V_48 ;
unsigned int V_49 = 3 ;
V_37 = F_25 () ;
V_50:
V_44 = F_21 ( V_37 ) ;
V_45 = F_18 ( V_37 << V_32 ) ;
if ( V_43 )
V_24 = F_26 ( F_27 ( V_44 ) ) ;
else {
#define F_28 (1 << (PAGE_SHIFT - IO_TLB_SHIFT))
#define F_29 ((1<<20) >> IO_TLB_SHIFT)
while ( ( F_28 << V_45 ) > F_29 ) {
V_24 = ( void * ) F_30 ( V_45 ) ;
if ( V_24 )
break;
V_45 -- ;
}
if ( V_45 != F_18 ( V_44 ) ) {
F_31 ( L_7 ,
( V_51 << V_45 ) >> 20 ) ;
V_37 = F_28 << V_45 ;
V_44 = V_37 << V_32 ;
}
}
if ( ! V_24 ) {
V_47 = V_40 ;
goto error;
}
V_25 = V_24 + V_44 ;
V_28 = F_17 ( V_24 ,
V_44 ,
V_37 ) ;
if ( V_28 ) {
if ( V_43 )
F_32 ( F_33 ( V_24 ) , F_27 ( V_44 ) ) ;
else {
F_34 ( ( unsigned long ) V_24 , V_45 ) ;
V_24 = NULL ;
}
V_47 = V_41 ;
goto error;
}
V_52 = F_8 ( V_24 ) ;
if ( V_43 ) {
if ( F_35 ( V_24 , V_37 ,
V_42 ) )
F_36 ( L_8 ) ;
V_28 = 0 ;
} else
V_28 = F_37 ( V_24 , V_37 ) ;
if ( ! V_28 )
F_38 ( V_51 ) ;
return V_28 ;
error:
if ( V_49 -- ) {
V_37 = F_39 ( 1024UL ,
( V_37 >> 1 ) ) ;
F_40 ( L_9 ,
( V_37 << V_32 ) >> 20 ) ;
goto V_50;
}
F_41 ( L_10 , F_23 ( V_47 ) , V_28 ) ;
if ( V_43 )
F_36 ( L_11 , F_23 ( V_47 ) , V_28 ) ;
else
F_34 ( ( unsigned long ) V_24 , V_45 ) ;
return V_28 ;
}
static void *
F_42 ( struct V_1 * V_53 , T_4 V_22 ,
T_2 * V_30 , T_1 V_54 ,
unsigned long V_55 )
{
void * V_56 ;
int V_45 = F_18 ( V_22 ) ;
T_6 V_4 = F_2 ( 32 ) ;
T_3 V_57 ;
T_2 V_58 ;
V_54 &= ~ ( V_59 | V_60 ) ;
V_56 = F_43 ( V_53 , V_22 , V_30 , V_54 , V_55 ) ;
if ( ! V_56 )
return V_56 ;
if ( V_53 && V_53 -> V_5 )
V_4 = F_1 ( V_53 , V_54 ) ;
V_57 = * V_30 ;
V_58 = F_3 ( V_57 ) ;
if ( ( ( V_58 + V_22 - 1 <= V_4 ) ) &&
! F_11 ( V_57 , V_22 ) )
* V_30 = V_58 ;
else {
if ( F_20 ( V_57 , V_45 ,
F_44 ( V_4 ) , V_30 ) != 0 ) {
F_45 ( V_53 , V_22 , V_56 , ( T_2 ) V_57 , V_55 ) ;
return NULL ;
}
}
memset ( V_56 , 0 , V_22 ) ;
return V_56 ;
}
static void
F_46 ( struct V_1 * V_53 , T_4 V_22 , void * V_61 ,
T_2 V_58 , unsigned long V_55 )
{
int V_45 = F_18 ( V_22 ) ;
T_3 V_57 ;
T_6 V_4 = F_2 ( 32 ) ;
if ( V_53 && V_53 -> V_5 )
V_4 = V_53 -> V_5 ;
V_57 = F_6 ( V_58 ) ;
if ( ( ( V_58 + V_22 - 1 > V_4 ) ) ||
F_11 ( V_57 , V_22 ) )
F_47 ( V_57 , V_45 ) ;
F_45 ( V_53 , V_22 , V_61 , ( T_2 ) V_57 , V_55 ) ;
}
static T_2 F_48 ( struct V_1 * V_2 , struct V_62 * V_62 ,
unsigned long V_15 , T_4 V_22 ,
enum V_63 V_64 ,
unsigned long V_55 )
{
T_3 V_65 , V_57 = F_49 ( V_62 ) + V_15 ;
T_2 V_58 = F_3 ( V_57 ) ;
F_50 ( V_64 == V_66 ) ;
if ( F_51 ( V_2 , V_58 , V_22 ) &&
! F_11 ( V_57 , V_22 ) &&
! F_52 ( V_2 , V_57 , V_58 ) &&
( V_67 != V_68 ) ) {
F_53 ( V_2 , V_62 , V_58 , V_15 , V_22 , V_64 , V_55 ) ;
return V_58 ;
}
F_54 ( V_2 , V_58 , V_22 , V_67 ) ;
V_65 = F_55 ( V_2 , V_52 , V_57 , V_22 , V_64 ,
V_55 ) ;
if ( V_65 == V_69 )
return V_70 ;
V_58 = F_3 ( V_65 ) ;
F_53 ( V_2 , F_56 ( V_65 >> V_33 ) ,
V_58 , V_65 & ~ V_71 , V_22 , V_64 , V_55 ) ;
if ( F_51 ( V_2 , V_58 , V_22 ) )
return V_58 ;
V_55 |= V_72 ;
F_57 ( V_2 , V_65 , V_22 , V_64 , V_55 ) ;
return V_70 ;
}
static void F_58 ( struct V_1 * V_53 , T_2 V_58 ,
T_4 V_22 , enum V_63 V_64 ,
unsigned long V_55 )
{
T_3 V_7 = F_6 ( V_58 ) ;
F_50 ( V_64 == V_66 ) ;
F_59 ( V_53 , V_58 , V_22 , V_64 , V_55 ) ;
if ( F_12 ( V_58 ) ) {
F_57 ( V_53 , V_7 , V_22 , V_64 , V_55 ) ;
return;
}
if ( V_64 != V_73 )
return;
F_60 ( F_61 ( V_7 ) , V_22 ) ;
}
static void F_62 ( struct V_1 * V_53 , T_2 V_58 ,
T_4 V_22 , enum V_63 V_64 ,
unsigned long V_55 )
{
F_58 ( V_53 , V_58 , V_22 , V_64 , V_55 ) ;
}
static void
F_63 ( struct V_1 * V_53 , T_2 V_58 ,
T_4 V_22 , enum V_63 V_64 ,
enum V_74 V_75 )
{
T_3 V_7 = F_6 ( V_58 ) ;
F_50 ( V_64 == V_66 ) ;
if ( V_75 == V_76 )
F_64 ( V_53 , V_58 , V_22 , V_64 ) ;
if ( F_12 ( V_58 ) )
F_65 ( V_53 , V_7 , V_22 , V_64 , V_75 ) ;
if ( V_75 == V_77 )
F_66 ( V_53 , V_58 , V_22 , V_64 ) ;
if ( V_64 != V_73 )
return;
F_60 ( F_61 ( V_7 ) , V_22 ) ;
}
void
F_67 ( struct V_1 * V_53 , T_2 V_58 ,
T_4 V_22 , enum V_63 V_64 )
{
F_63 ( V_53 , V_58 , V_22 , V_64 , V_76 ) ;
}
void
F_68 ( struct V_1 * V_53 , T_2 V_58 ,
T_4 V_22 , enum V_63 V_64 )
{
F_63 ( V_53 , V_58 , V_22 , V_64 , V_77 ) ;
}
static void
F_69 ( struct V_1 * V_53 , struct V_78 * V_79 ,
int V_80 , enum V_63 V_64 ,
unsigned long V_55 )
{
struct V_78 * V_81 ;
int V_18 ;
F_50 ( V_64 == V_66 ) ;
F_70 (sgl, sg, nelems, i)
F_58 ( V_53 , V_81 -> V_82 , F_71 ( V_81 ) , V_64 , V_55 ) ;
}
static int
F_72 ( struct V_1 * V_53 , struct V_78 * V_79 ,
int V_80 , enum V_63 V_64 ,
unsigned long V_55 )
{
struct V_78 * V_81 ;
int V_18 ;
F_50 ( V_64 == V_66 ) ;
F_70 (sgl, sg, nelems, i) {
T_3 V_7 = F_73 ( V_81 ) ;
T_2 V_58 = F_3 ( V_7 ) ;
if ( V_67 == V_68 ||
F_52 ( V_53 , V_7 , V_58 ) ||
! F_51 ( V_53 , V_58 , V_81 -> V_16 ) ||
F_11 ( V_7 , V_81 -> V_16 ) ) {
T_3 V_65 = F_55 ( V_53 ,
V_52 ,
F_73 ( V_81 ) ,
V_81 -> V_16 ,
V_64 , V_55 ) ;
if ( V_65 == V_69 ) {
F_74 ( V_53 , L_12 ) ;
V_55 |= V_72 ;
F_69 ( V_53 , V_79 , V_18 , V_64 ,
V_55 ) ;
F_71 ( V_79 ) = 0 ;
return 0 ;
}
V_58 = F_3 ( V_65 ) ;
F_53 ( V_53 , F_56 ( V_65 >> V_33 ) ,
V_58 ,
V_65 & ~ V_71 ,
V_81 -> V_16 ,
V_64 ,
V_55 ) ;
V_81 -> V_82 = V_58 ;
} else {
F_53 ( V_53 , F_56 ( V_7 >> V_33 ) ,
V_58 ,
V_7 & ~ V_71 ,
V_81 -> V_16 ,
V_64 ,
V_55 ) ;
V_81 -> V_82 = V_58 ;
}
F_71 ( V_81 ) = V_81 -> V_16 ;
}
return V_80 ;
}
static void
F_75 ( struct V_1 * V_53 , struct V_78 * V_79 ,
int V_80 , enum V_63 V_64 ,
enum V_74 V_75 )
{
struct V_78 * V_81 ;
int V_18 ;
F_70 (sgl, sg, nelems, i)
F_63 ( V_53 , V_81 -> V_82 ,
F_71 ( V_81 ) , V_64 , V_75 ) ;
}
static void
F_76 ( struct V_1 * V_53 , struct V_78 * V_81 ,
int V_80 , enum V_63 V_64 )
{
F_75 ( V_53 , V_81 , V_80 , V_64 , V_76 ) ;
}
static void
F_77 ( struct V_1 * V_53 , struct V_78 * V_81 ,
int V_80 , enum V_63 V_64 )
{
F_75 ( V_53 , V_81 , V_80 , V_64 , V_77 ) ;
}
static int
F_78 ( struct V_1 * V_53 , T_6 V_83 )
{
return F_8 ( V_25 - 1 ) <= V_83 ;
}
static int
F_79 ( struct V_1 * V_2 , struct V_84 * V_85 ,
void * V_86 , T_2 V_23 , T_4 V_22 ,
unsigned long V_55 )
{
#if F_80 ( V_87 ) || F_80 ( V_88 )
if ( F_81 ( V_2 ) -> V_89 )
return F_81 ( V_2 ) -> V_89 ( V_2 , V_85 , V_86 ,
V_23 , V_22 , V_55 ) ;
#endif
return F_82 ( V_2 , V_85 , V_86 , V_23 , V_22 ) ;
}
static int
F_83 ( struct V_1 * V_2 , struct V_90 * V_91 ,
void * V_86 , T_2 V_92 , T_4 V_22 ,
unsigned long V_55 )
{
#if F_80 ( V_87 ) || F_80 ( V_88 )
if ( F_81 ( V_2 ) -> V_93 ) {
#if 0
unsigned long bfn = PHYS_PFN(dma_to_phys(dev, handle));
BUG_ON (!page_is_ram(bfn));
#endif
return F_81 ( V_2 ) -> V_93 ( V_2 , V_91 , V_86 ,
V_92 , V_22 , V_55 ) ;
}
#endif
return F_84 ( V_2 , V_91 , V_86 , V_92 , V_22 ) ;
}
static int F_85 ( struct V_1 * V_2 , T_2 V_23 )
{
return V_23 == V_70 ;
}
