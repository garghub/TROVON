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
void __weak F_9 ( void * V_13 , unsigned long V_10 ) { }
static T_2 F_10 ( struct V_14 * V_15 ,
T_3 V_16 )
{
return F_11 ( F_12 ( V_15 , V_16 ) ) ;
}
static T_2 F_13 ( struct V_14 * V_15 ,
volatile void * V_16 )
{
return F_12 ( V_15 , F_14 ( V_16 ) ) ;
}
void F_15 ( void )
{
unsigned long V_17 = V_2 << V_11 ;
unsigned char * V_18 , * V_19 ;
if ( V_20 ) {
F_16 ( L_3 ) ;
return;
}
V_18 = F_17 ( V_21 ) ;
V_19 = F_17 ( V_22 ) ;
F_18 ( V_23 L_4 ,
( unsigned long long ) V_21 ,
( unsigned long long ) V_22 ,
V_17 >> 20 , V_18 , V_19 - 1 ) ;
}
void T_1 F_19 ( void )
{
void * V_13 ;
unsigned long V_17 ;
if ( V_20 || V_24 )
return;
V_13 = F_17 ( V_21 ) ;
V_17 = F_20 ( V_2 << V_11 ) ;
F_9 ( V_13 , V_17 ) ;
memset ( V_13 , 0 , V_17 ) ;
V_13 = F_17 ( V_25 ) ;
V_17 = F_20 ( V_26 ) ;
F_9 ( V_13 , V_17 ) ;
memset ( V_13 , 0 , V_17 ) ;
}
int T_1 F_21 ( char * V_27 , unsigned long V_28 , int V_29 )
{
void * V_30 ;
unsigned long V_31 , V_17 ;
V_17 = V_28 << V_11 ;
V_2 = V_28 ;
V_21 = F_22 ( V_27 ) ;
V_22 = V_21 + V_17 ;
V_30 = F_23 (
F_20 ( V_26 ) ,
V_9 ) ;
if ( ! V_30 )
return - V_32 ;
V_25 = F_22 ( V_30 ) ;
V_33 = F_24 (
F_20 ( V_2 * sizeof( int ) ) ,
V_9 ) ;
V_34 = F_24 (
F_20 ( V_2 * sizeof( T_3 ) ) ,
V_9 ) ;
for ( V_31 = 0 ; V_31 < V_2 ; V_31 ++ ) {
V_33 [ V_31 ] = V_3 - F_25 ( V_31 , V_3 ) ;
V_34 [ V_31 ] = V_35 ;
}
V_36 = 0 ;
if ( V_29 )
F_15 () ;
F_6 ( V_2 << V_11 ) ;
return 0 ;
}
void T_1
F_26 ( int V_29 )
{
T_4 V_37 = V_12 ;
unsigned char * V_18 ;
unsigned long V_17 ;
if ( ! V_2 ) {
V_2 = ( V_37 >> V_11 ) ;
V_2 = F_3 ( V_2 , V_3 ) ;
}
V_17 = V_2 << V_11 ;
V_18 = F_23 ( F_20 ( V_17 ) , V_9 ) ;
if ( V_18 && ! F_21 ( V_18 , V_2 , V_29 ) )
return;
if ( V_21 )
F_27 ( V_21 ,
F_20 ( V_2 << V_11 ) ) ;
F_16 ( L_5 ) ;
V_20 = true ;
}
int
F_28 ( T_4 V_37 )
{
unsigned long V_17 , V_38 = V_2 ;
unsigned char * V_18 = NULL ;
unsigned int V_39 ;
int V_40 = 0 ;
if ( ! V_2 ) {
V_2 = ( V_37 >> V_11 ) ;
V_2 = F_3 ( V_2 , V_3 ) ;
}
V_39 = F_29 ( V_2 << V_11 ) ;
V_2 = V_41 << V_39 ;
V_17 = V_2 << V_11 ;
while ( ( V_41 << V_39 ) > V_42 ) {
V_18 = ( void * ) F_30 ( V_43 | V_44 ,
V_39 ) ;
if ( V_18 )
break;
V_39 -- ;
}
if ( ! V_18 ) {
V_2 = V_38 ;
return - V_32 ;
}
if ( V_39 != F_29 ( V_17 ) ) {
F_18 ( V_45 L_6
L_7 , ( V_9 << V_39 ) >> 20 ) ;
V_2 = V_41 << V_39 ;
}
V_40 = F_31 ( V_18 , V_2 ) ;
if ( V_40 )
F_32 ( ( unsigned long ) V_18 , V_39 ) ;
return V_40 ;
}
int
F_31 ( char * V_27 , unsigned long V_28 )
{
unsigned long V_31 , V_17 ;
unsigned char * V_30 ;
V_17 = V_28 << V_11 ;
V_2 = V_28 ;
V_21 = F_14 ( V_27 ) ;
V_22 = V_21 + V_17 ;
F_9 ( V_27 , V_17 ) ;
memset ( V_27 , 0 , V_17 ) ;
V_30 = ( void * ) F_30 ( V_43 ,
F_29 ( V_26 ) ) ;
if ( ! V_30 )
goto V_46;
F_9 ( V_30 , V_26 ) ;
memset ( V_30 , 0 , V_26 ) ;
V_25 = F_14 ( V_30 ) ;
V_33 = ( unsigned int * ) F_30 ( V_47 ,
F_29 ( V_2 * sizeof( int ) ) ) ;
if ( ! V_33 )
goto V_48;
V_34 = ( T_3 * )
F_30 ( V_47 ,
F_29 ( V_2 *
sizeof( T_3 ) ) ) ;
if ( ! V_34 )
goto V_49;
for ( V_31 = 0 ; V_31 < V_2 ; V_31 ++ ) {
V_33 [ V_31 ] = V_3 - F_25 ( V_31 , V_3 ) ;
V_34 [ V_31 ] = V_35 ;
}
V_36 = 0 ;
F_15 () ;
V_24 = 1 ;
F_6 ( V_2 << V_11 ) ;
return 0 ;
V_49:
F_32 ( ( unsigned long ) V_33 , F_29 ( V_2 *
sizeof( int ) ) ) ;
V_33 = NULL ;
V_48:
F_32 ( ( unsigned long ) V_30 ,
F_29 ( V_26 ) ) ;
V_25 = 0 ;
V_46:
V_22 = 0 ;
V_21 = 0 ;
V_2 = 0 ;
V_7 = 0 ;
return - V_32 ;
}
void T_1 F_33 ( void )
{
if ( ! V_34 )
return;
if ( V_24 ) {
F_32 ( ( unsigned long ) F_17 ( V_25 ) ,
F_29 ( V_26 ) ) ;
F_32 ( ( unsigned long ) V_34 ,
F_29 ( V_2 * sizeof( T_3 ) ) ) ;
F_32 ( ( unsigned long ) V_33 , F_29 ( V_2 *
sizeof( int ) ) ) ;
F_32 ( ( unsigned long ) F_17 ( V_21 ) ,
F_29 ( V_2 << V_11 ) ) ;
} else {
F_34 ( V_25 ,
F_20 ( V_26 ) ) ;
F_34 ( F_22 ( V_34 ) ,
F_20 ( V_2 * sizeof( T_3 ) ) ) ;
F_34 ( F_22 ( V_33 ) ,
F_20 ( V_2 * sizeof( int ) ) ) ;
F_34 ( V_21 ,
F_20 ( V_2 << V_11 ) ) ;
}
V_2 = 0 ;
V_7 = 0 ;
}
int F_35 ( T_3 V_50 )
{
return V_50 >= V_21 && V_50 < V_22 ;
}
static void F_36 ( T_3 V_51 , T_3 V_52 ,
T_4 V_10 , enum V_53 V_54 )
{
unsigned long V_55 = F_37 ( V_51 ) ;
unsigned char * V_13 = F_17 ( V_52 ) ;
if ( F_38 ( F_39 ( V_55 ) ) ) {
unsigned int V_56 = V_51 & ~ V_57 ;
char * V_58 ;
unsigned int V_59 = 0 ;
unsigned long V_60 ;
while ( V_10 ) {
V_59 = F_40 ( T_4 , V_9 - V_56 , V_10 ) ;
F_41 ( V_60 ) ;
V_58 = F_42 ( F_39 ( V_55 ) ) ;
if ( V_54 == V_61 )
memcpy ( V_13 , V_58 + V_56 , V_59 ) ;
else
memcpy ( V_58 + V_56 , V_13 , V_59 ) ;
F_43 ( V_58 ) ;
F_44 ( V_60 ) ;
V_10 -= V_59 ;
V_55 ++ ;
V_13 += V_59 ;
V_56 = 0 ;
}
} else if ( V_54 == V_61 ) {
memcpy ( V_13 , F_17 ( V_51 ) , V_10 ) ;
} else {
memcpy ( F_17 ( V_51 ) , V_13 , V_10 ) ;
}
}
T_3 F_45 ( struct V_14 * V_15 ,
T_2 V_62 ,
T_3 V_51 , T_4 V_10 ,
enum V_53 V_54 ,
unsigned long V_63 )
{
unsigned long V_60 ;
T_3 V_52 ;
unsigned int V_64 , V_65 , V_66 , V_67 ;
int V_31 ;
unsigned long V_68 ;
unsigned long V_69 ;
unsigned long V_70 ;
if ( V_20 )
F_46 ( L_8 ) ;
if ( F_47 () )
F_48 ( L_9 ) ;
V_68 = F_49 ( V_15 ) ;
V_62 &= V_68 ;
V_69 = F_3 ( V_62 , 1 << V_11 ) >> V_11 ;
V_70 = V_68 + 1
? F_3 ( V_68 + 1 , 1 << V_11 ) >> V_11
: 1UL << ( V_71 - V_11 ) ;
V_64 = F_3 ( V_10 , 1 << V_11 ) >> V_11 ;
if ( V_10 >= V_9 )
V_65 = ( 1 << ( V_72 - V_11 ) ) ;
else
V_65 = 1 ;
F_50 ( ! V_64 ) ;
F_51 ( & V_73 , V_60 ) ;
V_66 = F_3 ( V_36 , V_65 ) ;
if ( V_66 >= V_2 )
V_66 = 0 ;
V_67 = V_66 ;
do {
while ( F_52 ( V_66 , V_64 , V_69 ,
V_70 ) ) {
V_66 += V_65 ;
if ( V_66 >= V_2 )
V_66 = 0 ;
if ( V_66 == V_67 )
goto V_74;
}
if ( V_33 [ V_66 ] >= V_64 ) {
int V_75 = 0 ;
for ( V_31 = V_66 ; V_31 < ( int ) ( V_66 + V_64 ) ; V_31 ++ )
V_33 [ V_31 ] = 0 ;
for ( V_31 = V_66 - 1 ; ( F_25 ( V_31 , V_3 ) != V_3 - 1 ) && V_33 [ V_31 ] ; V_31 -- )
V_33 [ V_31 ] = ++ V_75 ;
V_52 = V_21 + ( V_66 << V_11 ) ;
V_36 = ( ( V_66 + V_64 ) < V_2
? ( V_66 + V_64 ) : 0 ) ;
goto V_76;
}
V_66 += V_65 ;
if ( V_66 >= V_2 )
V_66 = 0 ;
} while ( V_66 != V_67 );
V_74:
F_53 ( & V_73 , V_60 ) ;
if ( F_54 () )
F_55 ( V_15 , L_10 , V_10 ) ;
return V_77 ;
V_76:
F_53 ( & V_73 , V_60 ) ;
for ( V_31 = 0 ; V_31 < V_64 ; V_31 ++ )
V_34 [ V_66 + V_31 ] = V_51 + ( V_31 << V_11 ) ;
if ( ! ( V_63 & V_78 ) &&
( V_54 == V_61 || V_54 == V_79 ) )
F_36 ( V_51 , V_52 , V_10 , V_61 ) ;
return V_52 ;
}
static T_3
F_56 ( struct V_14 * V_15 , T_3 V_80 , T_4 V_10 ,
enum V_53 V_54 , unsigned long V_63 )
{
T_2 V_81 ;
if ( V_4 == V_6 ) {
F_57 ( V_15 , L_11 ,
& V_80 ) ;
return V_77 ;
}
V_81 = F_10 ( V_15 , V_21 ) ;
return F_45 ( V_15 , V_81 , V_80 , V_10 ,
V_54 , V_63 ) ;
}
void F_58 ( struct V_14 * V_15 , T_3 V_52 ,
T_4 V_10 , enum V_53 V_54 ,
unsigned long V_63 )
{
unsigned long V_60 ;
int V_31 , V_75 , V_64 = F_3 ( V_10 , 1 << V_11 ) >> V_11 ;
int V_66 = ( V_52 - V_21 ) >> V_11 ;
T_3 V_51 = V_34 [ V_66 ] ;
if ( V_51 != V_35 &&
! ( V_63 & V_78 ) &&
( ( V_54 == V_82 ) || ( V_54 == V_79 ) ) )
F_36 ( V_51 , V_52 , V_10 , V_82 ) ;
F_51 ( & V_73 , V_60 ) ;
{
V_75 = ( ( V_66 + V_64 ) < F_3 ( V_66 + 1 , V_3 ) ?
V_33 [ V_66 + V_64 ] : 0 ) ;
for ( V_31 = V_66 + V_64 - 1 ; V_31 >= V_66 ; V_31 -- ) {
V_33 [ V_31 ] = ++ V_75 ;
V_34 [ V_31 ] = V_35 ;
}
for ( V_31 = V_66 - 1 ; ( F_25 ( V_31 , V_3 ) != V_3 - 1 ) && V_33 [ V_31 ] ; V_31 -- )
V_33 [ V_31 ] = ++ V_75 ;
}
F_53 ( & V_73 , V_60 ) ;
}
void F_59 ( struct V_14 * V_15 , T_3 V_52 ,
T_4 V_10 , enum V_53 V_54 ,
enum V_83 V_84 )
{
int V_66 = ( V_52 - V_21 ) >> V_11 ;
T_3 V_51 = V_34 [ V_66 ] ;
if ( V_51 == V_35 )
return;
V_51 += ( unsigned long ) V_52 & ( ( 1 << V_11 ) - 1 ) ;
switch ( V_84 ) {
case V_85 :
if ( F_60 ( V_54 == V_82 || V_54 == V_79 ) )
F_36 ( V_51 , V_52 ,
V_10 , V_82 ) ;
else
F_50 ( V_54 != V_61 ) ;
break;
case V_86 :
if ( F_60 ( V_54 == V_61 || V_54 == V_79 ) )
F_36 ( V_51 , V_52 ,
V_10 , V_61 ) ;
else
F_50 ( V_54 != V_82 ) ;
break;
default:
F_61 () ;
}
}
void *
F_62 ( struct V_14 * V_15 , T_4 V_10 ,
T_2 * V_87 , T_5 V_60 )
{
T_2 V_88 ;
void * V_89 ;
int V_39 = F_29 ( V_10 ) ;
T_6 V_90 = F_63 ( 32 ) ;
if ( V_15 && V_15 -> V_91 )
V_90 = V_15 -> V_91 ;
V_89 = ( void * ) F_30 ( V_60 , V_39 ) ;
if ( V_89 ) {
V_88 = F_13 ( V_15 , V_89 ) ;
if ( V_88 + V_10 - 1 > V_90 ) {
F_32 ( ( unsigned long ) V_89 , V_39 ) ;
V_89 = NULL ;
}
}
if ( ! V_89 ) {
T_3 V_50 = F_56 ( V_15 , 0 , V_10 ,
V_82 , 0 ) ;
if ( V_50 == V_77 )
goto V_92;
V_89 = F_17 ( V_50 ) ;
V_88 = F_10 ( V_15 , V_50 ) ;
if ( V_88 + V_10 - 1 > V_90 ) {
F_18 ( L_12 ,
( unsigned long long ) V_90 ,
( unsigned long long ) V_88 ) ;
F_58 ( V_15 , V_50 ,
V_10 , V_61 ,
V_78 ) ;
goto V_92;
}
}
* V_87 = V_88 ;
memset ( V_89 , 0 , V_10 ) ;
return V_89 ;
V_92:
F_16 ( L_13 ,
F_64 ( V_15 ) , V_10 ) ;
F_65 () ;
return NULL ;
}
void
F_66 ( struct V_14 * V_15 , T_4 V_10 , void * V_13 ,
T_2 V_88 )
{
T_3 V_50 = F_67 ( V_15 , V_88 ) ;
F_68 ( F_69 () ) ;
if ( ! F_35 ( V_50 ) )
F_32 ( ( unsigned long ) V_13 , F_29 ( V_10 ) ) ;
else
F_58 ( V_15 , V_50 , V_10 , V_61 ,
V_78 ) ;
}
static void
F_70 ( struct V_14 * V_93 , T_4 V_10 , enum V_53 V_54 ,
int V_94 )
{
if ( V_4 == V_6 )
return;
F_71 ( V_93 , L_14 ,
V_10 ) ;
if ( V_10 <= V_26 || ! V_94 )
return;
if ( V_54 == V_79 )
F_46 ( L_15 ) ;
if ( V_54 == V_82 )
F_46 ( L_16 ) ;
if ( V_54 == V_61 )
F_46 ( L_17 ) ;
}
T_2 F_72 ( struct V_14 * V_93 , struct V_95 * V_95 ,
unsigned long V_56 , T_4 V_10 ,
enum V_53 V_54 ,
unsigned long V_63 )
{
T_3 V_96 , V_80 = F_73 ( V_95 ) + V_56 ;
T_2 V_88 = F_12 ( V_93 , V_80 ) ;
F_50 ( V_54 == V_97 ) ;
if ( F_74 ( V_93 , V_88 , V_10 ) && V_4 != V_5 )
return V_88 ;
F_75 ( V_93 , V_88 , V_10 , V_4 ) ;
V_96 = F_56 ( V_93 , V_80 , V_10 , V_54 , V_63 ) ;
if ( V_96 == V_77 ) {
F_70 ( V_93 , V_10 , V_54 , 1 ) ;
return F_10 ( V_93 , V_25 ) ;
}
V_88 = F_10 ( V_93 , V_96 ) ;
if ( F_74 ( V_93 , V_88 , V_10 ) )
return V_88 ;
V_63 |= V_78 ;
F_58 ( V_93 , V_96 , V_10 , V_54 , V_63 ) ;
return F_10 ( V_93 , V_25 ) ;
}
static void F_76 ( struct V_14 * V_15 , T_2 V_88 ,
T_4 V_10 , enum V_53 V_54 ,
unsigned long V_63 )
{
T_3 V_50 = F_67 ( V_15 , V_88 ) ;
F_50 ( V_54 == V_97 ) ;
if ( F_35 ( V_50 ) ) {
F_58 ( V_15 , V_50 , V_10 , V_54 , V_63 ) ;
return;
}
if ( V_54 != V_82 )
return;
F_77 ( F_17 ( V_50 ) , V_10 ) ;
}
void F_78 ( struct V_14 * V_15 , T_2 V_88 ,
T_4 V_10 , enum V_53 V_54 ,
unsigned long V_63 )
{
F_76 ( V_15 , V_88 , V_10 , V_54 , V_63 ) ;
}
static void
F_79 ( struct V_14 * V_15 , T_2 V_88 ,
T_4 V_10 , enum V_53 V_54 ,
enum V_83 V_84 )
{
T_3 V_50 = F_67 ( V_15 , V_88 ) ;
F_50 ( V_54 == V_97 ) ;
if ( F_35 ( V_50 ) ) {
F_59 ( V_15 , V_50 , V_10 , V_54 , V_84 ) ;
return;
}
if ( V_54 != V_82 )
return;
F_77 ( F_17 ( V_50 ) , V_10 ) ;
}
void
F_80 ( struct V_14 * V_15 , T_2 V_88 ,
T_4 V_10 , enum V_53 V_54 )
{
F_79 ( V_15 , V_88 , V_10 , V_54 , V_85 ) ;
}
void
F_81 ( struct V_14 * V_15 , T_2 V_88 ,
T_4 V_10 , enum V_53 V_54 )
{
F_79 ( V_15 , V_88 , V_10 , V_54 , V_86 ) ;
}
int
F_82 ( struct V_14 * V_15 , struct V_98 * V_99 , int V_100 ,
enum V_53 V_54 , unsigned long V_63 )
{
struct V_98 * V_101 ;
int V_31 ;
F_50 ( V_54 == V_97 ) ;
F_83 (sgl, sg, nelems, i) {
T_3 V_50 = F_84 ( V_101 ) ;
T_2 V_88 = F_12 ( V_15 , V_50 ) ;
if ( V_4 == V_5 ||
! F_74 ( V_15 , V_88 , V_101 -> V_102 ) ) {
T_3 V_96 = F_56 ( V_15 , F_84 ( V_101 ) ,
V_101 -> V_102 , V_54 , V_63 ) ;
if ( V_96 == V_77 ) {
F_70 ( V_15 , V_101 -> V_102 , V_54 , 0 ) ;
V_63 |= V_78 ;
F_85 ( V_15 , V_99 , V_31 , V_54 ,
V_63 ) ;
F_86 ( V_99 ) = 0 ;
return 0 ;
}
V_101 -> V_103 = F_10 ( V_15 , V_96 ) ;
} else
V_101 -> V_103 = V_88 ;
F_86 ( V_101 ) = V_101 -> V_102 ;
}
return V_100 ;
}
void
F_85 ( struct V_14 * V_15 , struct V_98 * V_99 ,
int V_100 , enum V_53 V_54 ,
unsigned long V_63 )
{
struct V_98 * V_101 ;
int V_31 ;
F_50 ( V_54 == V_97 ) ;
F_83 (sgl, sg, nelems, i)
F_76 ( V_15 , V_101 -> V_103 , F_86 ( V_101 ) , V_54 ,
V_63 ) ;
}
static void
F_87 ( struct V_14 * V_15 , struct V_98 * V_99 ,
int V_100 , enum V_53 V_54 ,
enum V_83 V_84 )
{
struct V_98 * V_101 ;
int V_31 ;
F_83 (sgl, sg, nelems, i)
F_79 ( V_15 , V_101 -> V_103 ,
F_86 ( V_101 ) , V_54 , V_84 ) ;
}
void
F_88 ( struct V_14 * V_15 , struct V_98 * V_101 ,
int V_100 , enum V_53 V_54 )
{
F_87 ( V_15 , V_101 , V_100 , V_54 , V_85 ) ;
}
void
F_89 ( struct V_14 * V_15 , struct V_98 * V_101 ,
int V_100 , enum V_53 V_54 )
{
F_87 ( V_15 , V_101 , V_100 , V_54 , V_86 ) ;
}
int
F_90 ( struct V_14 * V_15 , T_2 V_104 )
{
return ( V_104 == F_10 ( V_15 , V_25 ) ) ;
}
int
F_91 ( struct V_14 * V_15 , T_6 V_68 )
{
return F_10 ( V_15 , V_22 - 1 ) <= V_68 ;
}
