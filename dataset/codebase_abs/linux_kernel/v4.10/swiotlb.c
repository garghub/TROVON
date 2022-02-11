static int T_1
F_1 ( char * V_1 )
{
if ( isdigit ( * V_1 ) ) {
V_2 = F_2 ( V_1 , & V_1 , 0 ) ;
V_2 = F_3 ( V_2 , V_3 ) ;
}
if ( * V_1 == ',' )
++ V_1 ;
if ( ! strcmp ( V_1 , L_1 ) ) {
V_4 = V_5 ;
} else if ( ! strcmp ( V_1 , L_2 ) ) {
V_4 = V_6 ;
V_2 = 1 ;
}
return 0 ;
}
unsigned long F_4 ( void )
{
return V_2 ;
}
unsigned int F_5 ( void )
{
return V_7 ;
}
void F_6 ( unsigned int V_8 )
{
if ( V_4 == V_5 )
V_7 = 1 ;
else
V_7 = F_7 ( V_8 , V_9 ) ;
}
unsigned long F_8 ( void )
{
unsigned long V_10 ;
V_10 = V_2 << V_11 ;
return V_10 ? V_10 : ( V_12 ) ;
}
static T_2 F_9 ( struct V_13 * V_14 ,
volatile void * V_15 )
{
return F_10 ( V_14 , F_11 ( V_15 ) ) ;
}
void F_12 ( void )
{
unsigned long V_16 = V_2 << V_11 ;
unsigned char * V_17 , * V_18 ;
if ( V_19 ) {
F_13 ( L_3 ) ;
return;
}
V_17 = F_14 ( V_20 ) ;
V_18 = F_14 ( V_21 ) ;
F_15 ( V_22 L_4 ,
( unsigned long long ) V_20 ,
( unsigned long long ) V_21 ,
V_16 >> 20 , V_17 , V_18 - 1 ) ;
}
int T_1 F_16 ( char * V_23 , unsigned long V_24 , int V_25 )
{
void * V_26 ;
unsigned long V_27 , V_16 ;
V_16 = V_24 << V_11 ;
V_2 = V_24 ;
V_20 = F_17 ( V_23 ) ;
V_21 = V_20 + V_16 ;
V_26 = F_18 (
F_19 ( V_28 ) ,
V_9 ) ;
if ( ! V_26 )
return - V_29 ;
V_30 = F_17 ( V_26 ) ;
V_31 = F_20 (
F_19 ( V_2 * sizeof( int ) ) ,
V_9 ) ;
V_32 = F_20 (
F_19 ( V_2 * sizeof( V_33 ) ) ,
V_9 ) ;
for ( V_27 = 0 ; V_27 < V_2 ; V_27 ++ ) {
V_31 [ V_27 ] = V_3 - F_21 ( V_27 , V_3 ) ;
V_32 [ V_27 ] = V_34 ;
}
V_35 = 0 ;
if ( V_25 )
F_12 () ;
F_6 ( V_2 << V_11 ) ;
return 0 ;
}
void T_1
F_22 ( int V_25 )
{
T_3 V_36 = V_12 ;
unsigned char * V_17 ;
unsigned long V_16 ;
if ( ! V_2 ) {
V_2 = ( V_36 >> V_11 ) ;
V_2 = F_3 ( V_2 , V_3 ) ;
}
V_16 = V_2 << V_11 ;
V_17 = F_18 ( F_19 ( V_16 ) , V_9 ) ;
if ( V_17 && ! F_16 ( V_17 , V_2 , V_25 ) )
return;
if ( V_20 )
F_23 ( V_20 ,
F_19 ( V_2 << V_11 ) ) ;
F_13 ( L_5 ) ;
V_19 = true ;
}
int
F_24 ( T_3 V_36 )
{
unsigned long V_16 , V_37 = V_2 ;
unsigned char * V_17 = NULL ;
unsigned int V_38 ;
int V_39 = 0 ;
if ( ! V_2 ) {
V_2 = ( V_36 >> V_11 ) ;
V_2 = F_3 ( V_2 , V_3 ) ;
}
V_38 = F_25 ( V_2 << V_11 ) ;
V_2 = V_40 << V_38 ;
V_16 = V_2 << V_11 ;
while ( ( V_40 << V_38 ) > V_41 ) {
V_17 = ( void * ) F_26 ( V_42 | V_43 ,
V_38 ) ;
if ( V_17 )
break;
V_38 -- ;
}
if ( ! V_17 ) {
V_2 = V_37 ;
return - V_29 ;
}
if ( V_38 != F_25 ( V_16 ) ) {
F_15 ( V_44 L_6
L_7 , ( V_9 << V_38 ) >> 20 ) ;
V_2 = V_40 << V_38 ;
}
V_39 = F_27 ( V_17 , V_2 ) ;
if ( V_39 )
F_28 ( ( unsigned long ) V_17 , V_38 ) ;
return V_39 ;
}
int
F_27 ( char * V_23 , unsigned long V_24 )
{
unsigned long V_27 , V_16 ;
unsigned char * V_26 ;
V_16 = V_24 << V_11 ;
V_2 = V_24 ;
V_20 = F_11 ( V_23 ) ;
V_21 = V_20 + V_16 ;
memset ( V_23 , 0 , V_16 ) ;
V_26 = ( void * ) F_26 ( V_42 ,
F_25 ( V_28 ) ) ;
if ( ! V_26 )
goto V_45;
V_30 = F_11 ( V_26 ) ;
V_31 = ( unsigned int * ) F_26 ( V_46 ,
F_25 ( V_2 * sizeof( int ) ) ) ;
if ( ! V_31 )
goto V_47;
V_32 = ( V_33 * )
F_26 ( V_46 ,
F_25 ( V_2 *
sizeof( V_33 ) ) ) ;
if ( ! V_32 )
goto V_48;
for ( V_27 = 0 ; V_27 < V_2 ; V_27 ++ ) {
V_31 [ V_27 ] = V_3 - F_21 ( V_27 , V_3 ) ;
V_32 [ V_27 ] = V_34 ;
}
V_35 = 0 ;
F_12 () ;
V_49 = 1 ;
F_6 ( V_2 << V_11 ) ;
return 0 ;
V_48:
F_28 ( ( unsigned long ) V_31 , F_25 ( V_2 *
sizeof( int ) ) ) ;
V_31 = NULL ;
V_47:
F_28 ( ( unsigned long ) V_26 ,
F_25 ( V_28 ) ) ;
V_30 = 0 ;
V_45:
V_21 = 0 ;
V_20 = 0 ;
V_2 = 0 ;
V_7 = 0 ;
return - V_29 ;
}
void T_1 F_29 ( void )
{
if ( ! V_32 )
return;
if ( V_49 ) {
F_28 ( ( unsigned long ) F_14 ( V_30 ) ,
F_25 ( V_28 ) ) ;
F_28 ( ( unsigned long ) V_32 ,
F_25 ( V_2 * sizeof( V_33 ) ) ) ;
F_28 ( ( unsigned long ) V_31 , F_25 ( V_2 *
sizeof( int ) ) ) ;
F_28 ( ( unsigned long ) F_14 ( V_20 ) ,
F_25 ( V_2 << V_11 ) ) ;
} else {
F_30 ( V_30 ,
F_19 ( V_28 ) ) ;
F_30 ( F_17 ( V_32 ) ,
F_19 ( V_2 * sizeof( V_33 ) ) ) ;
F_30 ( F_17 ( V_31 ) ,
F_19 ( V_2 * sizeof( int ) ) ) ;
F_30 ( V_20 ,
F_19 ( V_2 << V_11 ) ) ;
}
V_2 = 0 ;
V_7 = 0 ;
}
int F_31 ( V_33 V_50 )
{
return V_50 >= V_20 && V_50 < V_21 ;
}
static void F_32 ( V_33 V_51 , V_33 V_52 ,
T_3 V_10 , enum V_53 V_54 )
{
unsigned long V_55 = F_33 ( V_51 ) ;
unsigned char * V_56 = F_14 ( V_52 ) ;
if ( F_34 ( F_35 ( V_55 ) ) ) {
unsigned int V_57 = V_51 & ~ V_58 ;
char * V_59 ;
unsigned int V_60 = 0 ;
unsigned long V_61 ;
while ( V_10 ) {
V_60 = F_36 ( T_3 , V_9 - V_57 , V_10 ) ;
F_37 ( V_61 ) ;
V_59 = F_38 ( F_35 ( V_55 ) ) ;
if ( V_54 == V_62 )
memcpy ( V_56 , V_59 + V_57 , V_60 ) ;
else
memcpy ( V_59 + V_57 , V_56 , V_60 ) ;
F_39 ( V_59 ) ;
F_40 ( V_61 ) ;
V_10 -= V_60 ;
V_55 ++ ;
V_56 += V_60 ;
V_57 = 0 ;
}
} else if ( V_54 == V_62 ) {
memcpy ( V_56 , F_14 ( V_51 ) , V_10 ) ;
} else {
memcpy ( F_14 ( V_51 ) , V_56 , V_10 ) ;
}
}
V_33 F_41 ( struct V_13 * V_14 ,
T_2 V_63 ,
V_33 V_51 , T_3 V_10 ,
enum V_53 V_54 ,
unsigned long V_64 )
{
unsigned long V_61 ;
V_33 V_52 ;
unsigned int V_65 , V_66 , V_67 , V_68 ;
int V_27 ;
unsigned long V_69 ;
unsigned long V_70 ;
unsigned long V_71 ;
if ( V_19 )
F_42 ( L_8 ) ;
V_69 = F_43 ( V_14 ) ;
V_63 &= V_69 ;
V_70 = F_3 ( V_63 , 1 << V_11 ) >> V_11 ;
V_71 = V_69 + 1
? F_3 ( V_69 + 1 , 1 << V_11 ) >> V_11
: 1UL << ( V_72 - V_11 ) ;
V_65 = F_3 ( V_10 , 1 << V_11 ) >> V_11 ;
if ( V_10 >= V_9 )
V_66 = ( 1 << ( V_73 - V_11 ) ) ;
else
V_66 = 1 ;
F_44 ( ! V_65 ) ;
F_45 ( & V_74 , V_61 ) ;
V_67 = F_3 ( V_35 , V_66 ) ;
if ( V_67 >= V_2 )
V_67 = 0 ;
V_68 = V_67 ;
do {
while ( F_46 ( V_67 , V_65 , V_70 ,
V_71 ) ) {
V_67 += V_66 ;
if ( V_67 >= V_2 )
V_67 = 0 ;
if ( V_67 == V_68 )
goto V_75;
}
if ( V_31 [ V_67 ] >= V_65 ) {
int V_76 = 0 ;
for ( V_27 = V_67 ; V_27 < ( int ) ( V_67 + V_65 ) ; V_27 ++ )
V_31 [ V_27 ] = 0 ;
for ( V_27 = V_67 - 1 ; ( F_21 ( V_27 , V_3 ) != V_3 - 1 ) && V_31 [ V_27 ] ; V_27 -- )
V_31 [ V_27 ] = ++ V_76 ;
V_52 = V_20 + ( V_67 << V_11 ) ;
V_35 = ( ( V_67 + V_65 ) < V_2
? ( V_67 + V_65 ) : 0 ) ;
goto V_77;
}
V_67 += V_66 ;
if ( V_67 >= V_2 )
V_67 = 0 ;
} while ( V_67 != V_68 );
V_75:
F_47 ( & V_74 , V_61 ) ;
if ( F_48 () )
F_49 ( V_14 , L_9 , V_10 ) ;
return V_78 ;
V_77:
F_47 ( & V_74 , V_61 ) ;
for ( V_27 = 0 ; V_27 < V_65 ; V_27 ++ )
V_32 [ V_67 + V_27 ] = V_51 + ( V_27 << V_11 ) ;
if ( ! ( V_64 & V_79 ) &&
( V_54 == V_62 || V_54 == V_80 ) )
F_32 ( V_51 , V_52 , V_10 , V_62 ) ;
return V_52 ;
}
static V_33
F_50 ( struct V_13 * V_14 , V_33 V_81 , T_3 V_10 ,
enum V_53 V_54 , unsigned long V_64 )
{
T_2 V_82 ;
if ( V_4 == V_6 ) {
F_51 ( V_14 , L_10 ,
& V_81 ) ;
return V_78 ;
}
V_82 = F_10 ( V_14 , V_20 ) ;
return F_41 ( V_14 , V_82 , V_81 , V_10 ,
V_54 , V_64 ) ;
}
void F_52 ( struct V_13 * V_14 , V_33 V_52 ,
T_3 V_10 , enum V_53 V_54 ,
unsigned long V_64 )
{
unsigned long V_61 ;
int V_27 , V_76 , V_65 = F_3 ( V_10 , 1 << V_11 ) >> V_11 ;
int V_67 = ( V_52 - V_20 ) >> V_11 ;
V_33 V_51 = V_32 [ V_67 ] ;
if ( V_51 != V_34 &&
! ( V_64 & V_79 ) &&
( ( V_54 == V_83 ) || ( V_54 == V_80 ) ) )
F_32 ( V_51 , V_52 , V_10 , V_83 ) ;
F_45 ( & V_74 , V_61 ) ;
{
V_76 = ( ( V_67 + V_65 ) < F_3 ( V_67 + 1 , V_3 ) ?
V_31 [ V_67 + V_65 ] : 0 ) ;
for ( V_27 = V_67 + V_65 - 1 ; V_27 >= V_67 ; V_27 -- ) {
V_31 [ V_27 ] = ++ V_76 ;
V_32 [ V_27 ] = V_34 ;
}
for ( V_27 = V_67 - 1 ; ( F_21 ( V_27 , V_3 ) != V_3 - 1 ) && V_31 [ V_27 ] ; V_27 -- )
V_31 [ V_27 ] = ++ V_76 ;
}
F_47 ( & V_74 , V_61 ) ;
}
void F_53 ( struct V_13 * V_14 , V_33 V_52 ,
T_3 V_10 , enum V_53 V_54 ,
enum V_84 V_85 )
{
int V_67 = ( V_52 - V_20 ) >> V_11 ;
V_33 V_51 = V_32 [ V_67 ] ;
if ( V_51 == V_34 )
return;
V_51 += ( unsigned long ) V_52 & ( ( 1 << V_11 ) - 1 ) ;
switch ( V_85 ) {
case V_86 :
if ( F_54 ( V_54 == V_83 || V_54 == V_80 ) )
F_32 ( V_51 , V_52 ,
V_10 , V_83 ) ;
else
F_44 ( V_54 != V_62 ) ;
break;
case V_87 :
if ( F_54 ( V_54 == V_62 || V_54 == V_80 ) )
F_32 ( V_51 , V_52 ,
V_10 , V_62 ) ;
else
F_44 ( V_54 != V_83 ) ;
break;
default:
F_55 () ;
}
}
void *
F_56 ( struct V_13 * V_14 , T_3 V_10 ,
T_2 * V_88 , T_4 V_61 )
{
T_2 V_89 ;
void * V_90 ;
int V_38 = F_25 ( V_10 ) ;
T_5 V_91 = F_57 ( 32 ) ;
if ( V_14 && V_14 -> V_92 )
V_91 = V_14 -> V_92 ;
V_90 = ( void * ) F_26 ( V_61 , V_38 ) ;
if ( V_90 ) {
V_89 = F_9 ( V_14 , V_90 ) ;
if ( V_89 + V_10 - 1 > V_91 ) {
F_28 ( ( unsigned long ) V_90 , V_38 ) ;
V_90 = NULL ;
}
}
if ( ! V_90 ) {
V_33 V_50 = F_50 ( V_14 , 0 , V_10 ,
V_83 , 0 ) ;
if ( V_50 == V_78 )
goto V_93;
V_90 = F_14 ( V_50 ) ;
V_89 = F_10 ( V_14 , V_50 ) ;
if ( V_89 + V_10 - 1 > V_91 ) {
F_15 ( L_11 ,
( unsigned long long ) V_91 ,
( unsigned long long ) V_89 ) ;
F_52 ( V_14 , V_50 ,
V_10 , V_62 ,
V_79 ) ;
goto V_93;
}
}
* V_88 = V_89 ;
memset ( V_90 , 0 , V_10 ) ;
return V_90 ;
V_93:
F_13 ( L_12 ,
F_58 ( V_14 ) , V_10 ) ;
F_59 () ;
return NULL ;
}
void
F_60 ( struct V_13 * V_14 , T_3 V_10 , void * V_56 ,
T_2 V_89 )
{
V_33 V_50 = F_61 ( V_14 , V_89 ) ;
F_62 ( F_63 () ) ;
if ( ! F_31 ( V_50 ) )
F_28 ( ( unsigned long ) V_56 , F_25 ( V_10 ) ) ;
else
F_52 ( V_14 , V_50 , V_10 , V_62 ,
V_79 ) ;
}
static void
F_64 ( struct V_13 * V_94 , T_3 V_10 , enum V_53 V_54 ,
int V_95 )
{
if ( V_4 == V_6 )
return;
F_65 ( V_94 , L_13 ,
V_10 ) ;
if ( V_10 <= V_28 || ! V_95 )
return;
if ( V_54 == V_80 )
F_42 ( L_14 ) ;
if ( V_54 == V_83 )
F_42 ( L_15 ) ;
if ( V_54 == V_62 )
F_42 ( L_16 ) ;
}
T_2 F_66 ( struct V_13 * V_94 , struct V_96 * V_96 ,
unsigned long V_57 , T_3 V_10 ,
enum V_53 V_54 ,
unsigned long V_64 )
{
V_33 V_97 , V_81 = F_67 ( V_96 ) + V_57 ;
T_2 V_89 = F_10 ( V_94 , V_81 ) ;
F_44 ( V_54 == V_98 ) ;
if ( F_68 ( V_94 , V_89 , V_10 ) && V_4 != V_5 )
return V_89 ;
F_69 ( V_94 , V_89 , V_10 , V_4 ) ;
V_97 = F_50 ( V_94 , V_81 , V_10 , V_54 , V_64 ) ;
if ( V_97 == V_78 ) {
F_64 ( V_94 , V_10 , V_54 , 1 ) ;
return F_10 ( V_94 , V_30 ) ;
}
V_89 = F_10 ( V_94 , V_97 ) ;
if ( F_68 ( V_94 , V_89 , V_10 ) )
return V_89 ;
V_64 |= V_79 ;
F_52 ( V_94 , V_97 , V_10 , V_54 , V_64 ) ;
return F_10 ( V_94 , V_30 ) ;
}
static void F_70 ( struct V_13 * V_14 , T_2 V_89 ,
T_3 V_10 , enum V_53 V_54 ,
unsigned long V_64 )
{
V_33 V_50 = F_61 ( V_14 , V_89 ) ;
F_44 ( V_54 == V_98 ) ;
if ( F_31 ( V_50 ) ) {
F_52 ( V_14 , V_50 , V_10 , V_54 , V_64 ) ;
return;
}
if ( V_54 != V_83 )
return;
F_71 ( F_14 ( V_50 ) , V_10 ) ;
}
void F_72 ( struct V_13 * V_14 , T_2 V_89 ,
T_3 V_10 , enum V_53 V_54 ,
unsigned long V_64 )
{
F_70 ( V_14 , V_89 , V_10 , V_54 , V_64 ) ;
}
static void
F_73 ( struct V_13 * V_14 , T_2 V_89 ,
T_3 V_10 , enum V_53 V_54 ,
enum V_84 V_85 )
{
V_33 V_50 = F_61 ( V_14 , V_89 ) ;
F_44 ( V_54 == V_98 ) ;
if ( F_31 ( V_50 ) ) {
F_53 ( V_14 , V_50 , V_10 , V_54 , V_85 ) ;
return;
}
if ( V_54 != V_83 )
return;
F_71 ( F_14 ( V_50 ) , V_10 ) ;
}
void
F_74 ( struct V_13 * V_14 , T_2 V_89 ,
T_3 V_10 , enum V_53 V_54 )
{
F_73 ( V_14 , V_89 , V_10 , V_54 , V_86 ) ;
}
void
F_75 ( struct V_13 * V_14 , T_2 V_89 ,
T_3 V_10 , enum V_53 V_54 )
{
F_73 ( V_14 , V_89 , V_10 , V_54 , V_87 ) ;
}
int
F_76 ( struct V_13 * V_14 , struct V_99 * V_100 , int V_101 ,
enum V_53 V_54 , unsigned long V_64 )
{
struct V_99 * V_102 ;
int V_27 ;
F_44 ( V_54 == V_98 ) ;
F_77 (sgl, sg, nelems, i) {
V_33 V_50 = F_78 ( V_102 ) ;
T_2 V_89 = F_10 ( V_14 , V_50 ) ;
if ( V_4 == V_5 ||
! F_68 ( V_14 , V_89 , V_102 -> V_103 ) ) {
V_33 V_97 = F_50 ( V_14 , F_78 ( V_102 ) ,
V_102 -> V_103 , V_54 , V_64 ) ;
if ( V_97 == V_78 ) {
F_64 ( V_14 , V_102 -> V_103 , V_54 , 0 ) ;
V_64 |= V_79 ;
F_79 ( V_14 , V_100 , V_27 , V_54 ,
V_64 ) ;
F_80 ( V_100 ) = 0 ;
return 0 ;
}
V_102 -> V_104 = F_10 ( V_14 , V_97 ) ;
} else
V_102 -> V_104 = V_89 ;
F_80 ( V_102 ) = V_102 -> V_103 ;
}
return V_101 ;
}
void
F_79 ( struct V_13 * V_14 , struct V_99 * V_100 ,
int V_101 , enum V_53 V_54 ,
unsigned long V_64 )
{
struct V_99 * V_102 ;
int V_27 ;
F_44 ( V_54 == V_98 ) ;
F_77 (sgl, sg, nelems, i)
F_70 ( V_14 , V_102 -> V_104 , F_80 ( V_102 ) , V_54 ,
V_64 ) ;
}
static void
F_81 ( struct V_13 * V_14 , struct V_99 * V_100 ,
int V_101 , enum V_53 V_54 ,
enum V_84 V_85 )
{
struct V_99 * V_102 ;
int V_27 ;
F_77 (sgl, sg, nelems, i)
F_73 ( V_14 , V_102 -> V_104 ,
F_80 ( V_102 ) , V_54 , V_85 ) ;
}
void
F_82 ( struct V_13 * V_14 , struct V_99 * V_102 ,
int V_101 , enum V_53 V_54 )
{
F_81 ( V_14 , V_102 , V_101 , V_54 , V_86 ) ;
}
void
F_83 ( struct V_13 * V_14 , struct V_99 * V_102 ,
int V_101 , enum V_53 V_54 )
{
F_81 ( V_14 , V_102 , V_101 , V_54 , V_87 ) ;
}
int
F_84 ( struct V_13 * V_14 , T_2 V_105 )
{
return ( V_105 == F_10 ( V_14 , V_30 ) ) ;
}
int
F_85 ( struct V_13 * V_14 , T_5 V_69 )
{
return F_10 ( V_14 , V_21 - 1 ) <= V_69 ;
}
