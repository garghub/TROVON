static T_1 F_1 ( T_2 V_1 )
{
return F_2 ( F_3 ( V_1 ) ) . V_2 ;
}
static T_2 F_4 ( T_1 V_3 )
{
return F_5 ( F_6 ( V_3 ) ) . V_1 ;
}
static T_1 F_7 ( void * V_4 )
{
return F_1 ( F_8 ( V_4 ) ) ;
}
static int F_9 ( unsigned long V_5 ,
unsigned int V_6 ,
T_3 V_7 )
{
unsigned long V_8 ;
int V_9 ;
int V_10 ;
V_8 = F_10 ( V_5 ) ;
V_10 = ( V_6 + V_7 + V_11 - 1 ) >> V_12 ;
for ( V_9 = 1 ; V_9 < V_10 ; V_9 ++ ) {
if ( F_10 ( ++ V_5 ) != ++ V_8 )
return 0 ;
}
return 1 ;
}
static int F_11 ( T_2 V_13 , T_3 V_14 )
{
unsigned long V_5 = F_12 ( V_13 ) ;
unsigned int V_6 = V_13 & ~ V_15 ;
if ( V_6 + V_14 <= V_11 )
return 0 ;
if ( F_9 ( V_5 , V_6 , V_14 ) )
return 0 ;
return 1 ;
}
static int F_13 ( T_1 V_16 )
{
unsigned long V_17 = F_12 ( V_16 ) ;
unsigned long V_5 = F_14 ( V_17 ) ;
T_2 V_1 ;
if ( F_15 ( V_5 ) ) {
V_1 = F_16 ( V_5 ) ;
return V_1 >= F_8 ( V_18 ) &&
V_1 < F_8 ( V_19 ) ;
}
return 0 ;
}
static int
F_17 ( void * V_20 , T_3 V_14 , unsigned long V_21 )
{
int V_9 , V_22 ;
int V_23 ;
V_23 = F_18 ( V_24 << V_25 ) + V_12 ;
V_9 = 0 ;
do {
int V_26 = F_19 ( V_21 - V_9 , ( unsigned long ) V_24 ) ;
do {
V_22 = F_20 (
( unsigned long ) V_20 + ( V_9 << V_25 ) ,
F_18 ( V_26 << V_25 ) ,
V_23 ) ;
} while ( V_22 && V_23 ++ < V_27 );
if ( V_22 )
return V_22 ;
V_9 += V_26 ;
} while ( V_9 < V_21 );
return 0 ;
}
static unsigned long F_21 ( unsigned long V_28 )
{
if ( ! V_28 ) {
V_29 = ( 64 * 1024 * 1024 >> V_25 ) ;
V_29 = F_22 ( V_29 , V_24 ) ;
} else
V_29 = V_28 ;
return V_29 << V_25 ;
}
static const char * F_23 ( enum V_30 V_31 )
{
switch ( V_31 ) {
case V_32 :
return L_1 ;
case V_33 :
return L_2\
L_3\
L_4\
L_5 ;
default:
break;
}
return L_6 ;
}
int T_4 F_24 ( int V_34 , bool V_35 )
{
unsigned long V_36 , V_37 ;
int V_22 = - V_38 ;
enum V_30 V_39 = V_40 ;
unsigned int V_41 = 3 ;
V_29 = F_25 () ;
V_42:
V_36 = F_21 ( V_29 ) ;
V_37 = F_18 ( V_29 << V_25 ) ;
if ( V_35 )
V_18 = F_26 ( F_27 ( V_36 ) ) ;
else {
#define F_28 (1 << (PAGE_SHIFT - IO_TLB_SHIFT))
#define F_29 ((1<<20) >> IO_TLB_SHIFT)
while ( ( F_28 << V_37 ) > F_29 ) {
V_18 = ( void * ) F_30 ( V_43 , V_37 ) ;
if ( V_18 )
break;
V_37 -- ;
}
if ( V_37 != F_18 ( V_36 ) ) {
F_31 ( L_7 ,
( V_11 << V_37 ) >> 20 ) ;
V_29 = F_28 << V_37 ;
V_36 = V_29 << V_25 ;
}
}
if ( ! V_18 ) {
V_39 = V_32 ;
goto error;
}
V_19 = V_18 + V_36 ;
V_22 = F_17 ( V_18 ,
V_36 ,
V_29 ) ;
if ( V_22 ) {
if ( V_35 )
F_32 ( F_33 ( V_18 ) , F_27 ( V_36 ) ) ;
else {
F_34 ( ( unsigned long ) V_18 , V_37 ) ;
V_18 = NULL ;
}
V_39 = V_33 ;
goto error;
}
V_44 = F_7 ( V_18 ) ;
if ( V_35 ) {
if ( F_35 ( V_18 , V_29 ,
V_34 ) )
F_36 ( L_8 ) ;
V_22 = 0 ;
} else
V_22 = F_37 ( V_18 , V_29 ) ;
return V_22 ;
error:
if ( V_41 -- ) {
V_29 = F_38 ( 1024UL ,
( V_29 >> 1 ) ) ;
F_39 ( L_9 ,
( V_29 << V_25 ) >> 20 ) ;
goto V_42;
}
F_40 ( L_10 , F_23 ( V_39 ) , V_22 ) ;
if ( V_35 )
F_36 ( L_11 , F_23 ( V_39 ) , V_22 ) ;
else
F_34 ( ( unsigned long ) V_18 , V_37 ) ;
return V_22 ;
}
void *
F_41 ( struct V_45 * V_46 , T_3 V_14 ,
T_1 * V_47 , T_5 V_48 ,
struct V_49 * V_50 )
{
void * V_51 ;
int V_37 = F_18 ( V_14 ) ;
T_6 V_52 = F_42 ( 32 ) ;
unsigned long V_53 ;
T_2 V_54 ;
T_1 V_55 ;
V_48 &= ~ ( V_56 | V_57 ) ;
if ( F_43 ( V_46 , V_14 , V_47 , & V_51 ) )
return V_51 ;
V_53 = F_30 ( V_48 , V_37 ) ;
V_51 = ( void * ) V_53 ;
if ( ! V_51 )
return V_51 ;
if ( V_46 && V_46 -> V_58 )
V_52 = F_44 ( V_46 , V_48 ) ;
V_54 = F_8 ( V_51 ) ;
V_55 = F_1 ( V_54 ) ;
if ( ( ( V_55 + V_14 - 1 <= V_52 ) ) &&
! F_11 ( V_54 , V_14 ) )
* V_47 = V_55 ;
else {
if ( F_20 ( V_53 , V_37 ,
F_45 ( V_52 ) ) != 0 ) {
F_34 ( V_53 , V_37 ) ;
return NULL ;
}
* V_47 = F_46 ( V_51 ) . V_2 ;
}
memset ( V_51 , 0 , V_14 ) ;
return V_51 ;
}
void
F_47 ( struct V_45 * V_46 , T_3 V_14 , void * V_59 ,
T_1 V_55 , struct V_49 * V_50 )
{
int V_37 = F_18 ( V_14 ) ;
T_2 V_54 ;
T_6 V_52 = F_42 ( 32 ) ;
if ( F_48 ( V_46 , V_37 , V_59 ) )
return;
if ( V_46 && V_46 -> V_58 )
V_52 = V_46 -> V_58 ;
V_54 = F_8 ( V_59 ) ;
if ( ( ( V_55 + V_14 - 1 > V_52 ) ) ||
F_11 ( V_54 , V_14 ) )
F_49 ( ( unsigned long ) V_59 , V_37 ) ;
F_34 ( ( unsigned long ) V_59 , V_37 ) ;
}
T_1 F_50 ( struct V_45 * V_60 , struct V_61 * V_61 ,
unsigned long V_6 , T_3 V_14 ,
enum V_62 V_63 ,
struct V_49 * V_50 )
{
T_2 V_64 , V_54 = F_51 ( V_61 ) + V_6 ;
T_1 V_55 = F_1 ( V_54 ) ;
F_52 ( V_63 == V_65 ) ;
if ( F_53 ( V_60 , V_55 , V_14 ) &&
! F_11 ( V_54 , V_14 ) && ! V_66 )
return V_55 ;
V_64 = F_54 ( V_60 , V_44 , V_54 , V_14 , V_63 ) ;
if ( V_64 == V_67 )
return V_68 ;
V_55 = F_1 ( V_64 ) ;
if ( ! F_53 ( V_60 , V_55 , V_14 ) ) {
F_55 ( V_60 , V_64 , V_14 , V_63 ) ;
V_55 = 0 ;
}
return V_55 ;
}
static void F_56 ( struct V_45 * V_46 , T_1 V_55 ,
T_3 V_14 , enum V_62 V_63 )
{
T_2 V_1 = F_4 ( V_55 ) ;
F_52 ( V_63 == V_65 ) ;
if ( F_13 ( V_55 ) ) {
F_55 ( V_46 , V_1 , V_14 , V_63 ) ;
return;
}
if ( V_63 != V_69 )
return;
F_57 ( F_58 ( V_1 ) , V_14 ) ;
}
void F_59 ( struct V_45 * V_46 , T_1 V_55 ,
T_3 V_14 , enum V_62 V_63 ,
struct V_49 * V_50 )
{
F_56 ( V_46 , V_55 , V_14 , V_63 ) ;
}
static void
F_60 ( struct V_45 * V_46 , T_1 V_55 ,
T_3 V_14 , enum V_62 V_63 ,
enum V_70 V_71 )
{
T_2 V_1 = F_4 ( V_55 ) ;
F_52 ( V_63 == V_65 ) ;
if ( F_13 ( V_55 ) ) {
F_61 ( V_46 , V_1 , V_14 , V_63 , V_71 ) ;
return;
}
if ( V_63 != V_69 )
return;
F_57 ( F_58 ( V_1 ) , V_14 ) ;
}
void
F_62 ( struct V_45 * V_46 , T_1 V_55 ,
T_3 V_14 , enum V_62 V_63 )
{
F_60 ( V_46 , V_55 , V_14 , V_63 , V_72 ) ;
}
void
F_63 ( struct V_45 * V_46 , T_1 V_55 ,
T_3 V_14 , enum V_62 V_63 )
{
F_60 ( V_46 , V_55 , V_14 , V_63 , V_73 ) ;
}
int
F_64 ( struct V_45 * V_46 , struct V_74 * V_75 ,
int V_76 , enum V_62 V_63 ,
struct V_49 * V_50 )
{
struct V_74 * V_77 ;
int V_9 ;
F_52 ( V_63 == V_65 ) ;
F_65 (sgl, sg, nelems, i) {
T_2 V_1 = F_66 ( V_77 ) ;
T_1 V_55 = F_1 ( V_1 ) ;
if ( V_66 ||
! F_53 ( V_46 , V_55 , V_77 -> V_7 ) ||
F_11 ( V_1 , V_77 -> V_7 ) ) {
T_2 V_64 = F_54 ( V_46 ,
V_44 ,
F_66 ( V_77 ) ,
V_77 -> V_7 ,
V_63 ) ;
if ( V_64 == V_67 ) {
F_67 ( V_46 , V_75 , V_9 , V_63 ,
V_50 ) ;
V_75 [ 0 ] . V_78 = 0 ;
return V_68 ;
}
V_77 -> V_79 = F_1 ( V_64 ) ;
} else
V_77 -> V_79 = V_55 ;
V_77 -> V_78 = V_77 -> V_7 ;
}
return V_76 ;
}
void
F_67 ( struct V_45 * V_46 , struct V_74 * V_75 ,
int V_76 , enum V_62 V_63 ,
struct V_49 * V_50 )
{
struct V_74 * V_77 ;
int V_9 ;
F_52 ( V_63 == V_65 ) ;
F_65 (sgl, sg, nelems, i)
F_56 ( V_46 , V_77 -> V_79 , V_77 -> V_78 , V_63 ) ;
}
static void
F_68 ( struct V_45 * V_46 , struct V_74 * V_75 ,
int V_76 , enum V_62 V_63 ,
enum V_70 V_71 )
{
struct V_74 * V_77 ;
int V_9 ;
F_65 (sgl, sg, nelems, i)
F_60 ( V_46 , V_77 -> V_79 ,
V_77 -> V_78 , V_63 , V_71 ) ;
}
void
F_69 ( struct V_45 * V_46 , struct V_74 * V_77 ,
int V_76 , enum V_62 V_63 )
{
F_68 ( V_46 , V_77 , V_76 , V_63 , V_72 ) ;
}
void
F_70 ( struct V_45 * V_46 , struct V_74 * V_77 ,
int V_76 , enum V_62 V_63 )
{
F_68 ( V_46 , V_77 , V_76 , V_63 , V_73 ) ;
}
int
F_71 ( struct V_45 * V_46 , T_1 V_16 )
{
return ! V_16 ;
}
int
F_72 ( struct V_45 * V_46 , T_6 V_80 )
{
return F_7 ( V_19 - 1 ) <= V_80 ;
}
