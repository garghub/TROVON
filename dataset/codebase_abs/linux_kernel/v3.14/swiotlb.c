static int T_1
F_1 ( char * V_1 )
{
if ( isdigit ( * V_1 ) ) {
V_2 = F_2 ( V_1 , & V_1 , 0 ) ;
V_2 = F_3 ( V_2 , V_3 ) ;
}
if ( * V_1 == ',' )
++ V_1 ;
if ( ! strcmp ( V_1 , L_1 ) )
V_4 = 1 ;
return 0 ;
}
unsigned long F_4 ( void )
{
return V_2 ;
}
unsigned long F_5 ( void )
{
unsigned long V_5 ;
V_5 = V_2 << V_6 ;
return V_5 ? V_5 : ( V_7 ) ;
}
static T_2 F_6 ( struct V_8 * V_9 ,
volatile void * V_10 )
{
return F_7 ( V_9 , F_8 ( V_10 ) ) ;
}
void F_9 ( void )
{
unsigned long V_11 = V_2 << V_6 ;
unsigned char * V_12 , * V_13 ;
if ( V_14 ) {
F_10 ( L_2 ) ;
return;
}
V_12 = F_11 ( V_15 ) ;
V_13 = F_11 ( V_16 ) ;
F_12 ( V_17 L_3 ,
( unsigned long long ) V_15 ,
( unsigned long long ) V_16 ,
V_11 >> 20 , V_12 , V_13 - 1 ) ;
}
int T_1 F_13 ( char * V_18 , unsigned long V_19 , int V_20 )
{
void * V_21 ;
unsigned long V_22 , V_11 ;
V_11 = V_19 << V_6 ;
V_2 = V_19 ;
V_15 = F_14 ( V_18 ) ;
V_16 = V_15 + V_11 ;
V_21 = F_15 (
F_16 ( V_23 ) ,
V_24 ) ;
if ( ! V_21 )
return - V_25 ;
V_26 = F_14 ( V_21 ) ;
V_27 = F_17 (
F_16 ( V_2 * sizeof( int ) ) ,
V_24 ) ;
for ( V_22 = 0 ; V_22 < V_2 ; V_22 ++ )
V_27 [ V_22 ] = V_3 - F_18 ( V_22 , V_3 ) ;
V_28 = 0 ;
V_29 = F_17 (
F_16 ( V_2 * sizeof( V_30 ) ) ,
V_24 ) ;
if ( V_20 )
F_9 () ;
return 0 ;
}
void T_1
F_19 ( int V_20 )
{
T_3 V_31 = V_7 ;
unsigned char * V_12 ;
unsigned long V_11 ;
if ( ! V_2 ) {
V_2 = ( V_31 >> V_6 ) ;
V_2 = F_3 ( V_2 , V_3 ) ;
}
V_11 = V_2 << V_6 ;
V_12 = F_15 ( F_16 ( V_11 ) , V_24 ) ;
if ( V_12 && ! F_13 ( V_12 , V_2 , V_20 ) )
return;
if ( V_15 )
F_20 ( V_15 ,
F_16 ( V_2 << V_6 ) ) ;
F_10 ( L_4 ) ;
V_14 = true ;
}
int
F_21 ( T_3 V_31 )
{
unsigned long V_11 , V_32 = V_2 ;
unsigned char * V_12 = NULL ;
unsigned int V_33 ;
int V_34 = 0 ;
if ( ! V_2 ) {
V_2 = ( V_31 >> V_6 ) ;
V_2 = F_3 ( V_2 , V_3 ) ;
}
V_33 = F_22 ( V_2 << V_6 ) ;
V_2 = V_35 << V_33 ;
V_11 = V_2 << V_6 ;
while ( ( V_35 << V_33 ) > V_36 ) {
V_12 = ( void * ) F_23 ( V_37 | V_38 ,
V_33 ) ;
if ( V_12 )
break;
V_33 -- ;
}
if ( ! V_12 ) {
V_2 = V_32 ;
return - V_25 ;
}
if ( V_33 != F_22 ( V_11 ) ) {
F_12 ( V_39 L_5
L_6 , ( V_24 << V_33 ) >> 20 ) ;
V_2 = V_35 << V_33 ;
}
V_34 = F_24 ( V_12 , V_2 ) ;
if ( V_34 )
F_25 ( ( unsigned long ) V_12 , V_33 ) ;
return V_34 ;
}
int
F_24 ( char * V_18 , unsigned long V_19 )
{
unsigned long V_22 , V_11 ;
unsigned char * V_21 ;
V_11 = V_19 << V_6 ;
V_2 = V_19 ;
V_15 = F_8 ( V_18 ) ;
V_16 = V_15 + V_11 ;
memset ( V_18 , 0 , V_11 ) ;
V_21 = ( void * ) F_23 ( V_37 ,
F_22 ( V_23 ) ) ;
if ( ! V_21 )
goto V_40;
V_26 = F_8 ( V_21 ) ;
V_27 = ( unsigned int * ) F_23 ( V_41 ,
F_22 ( V_2 * sizeof( int ) ) ) ;
if ( ! V_27 )
goto V_42;
for ( V_22 = 0 ; V_22 < V_2 ; V_22 ++ )
V_27 [ V_22 ] = V_3 - F_18 ( V_22 , V_3 ) ;
V_28 = 0 ;
V_29 = ( V_30 * )
F_23 ( V_41 ,
F_22 ( V_2 *
sizeof( V_30 ) ) ) ;
if ( ! V_29 )
goto V_43;
memset ( V_29 , 0 , V_2 * sizeof( V_30 ) ) ;
F_9 () ;
V_44 = 1 ;
return 0 ;
V_43:
F_25 ( ( unsigned long ) V_27 , F_22 ( V_2 *
sizeof( int ) ) ) ;
V_27 = NULL ;
V_42:
F_25 ( ( unsigned long ) V_21 ,
F_22 ( V_23 ) ) ;
V_26 = 0 ;
V_40:
V_16 = 0 ;
V_15 = 0 ;
V_2 = 0 ;
return - V_25 ;
}
void T_1 F_26 ( void )
{
if ( ! V_29 )
return;
if ( V_44 ) {
F_25 ( ( unsigned long ) F_11 ( V_26 ) ,
F_22 ( V_23 ) ) ;
F_25 ( ( unsigned long ) V_29 ,
F_22 ( V_2 * sizeof( V_30 ) ) ) ;
F_25 ( ( unsigned long ) V_27 , F_22 ( V_2 *
sizeof( int ) ) ) ;
F_25 ( ( unsigned long ) F_11 ( V_15 ) ,
F_22 ( V_2 << V_6 ) ) ;
} else {
F_27 ( V_26 ,
F_16 ( V_23 ) ) ;
F_27 ( F_14 ( V_29 ) ,
F_16 ( V_2 * sizeof( V_30 ) ) ) ;
F_27 ( F_14 ( V_27 ) ,
F_16 ( V_2 * sizeof( int ) ) ) ;
F_27 ( V_15 ,
F_16 ( V_2 << V_6 ) ) ;
}
V_2 = 0 ;
}
static int F_28 ( V_30 V_45 )
{
return V_45 >= V_15 && V_45 < V_16 ;
}
static void F_29 ( V_30 V_46 , V_30 V_47 ,
T_3 V_5 , enum V_48 V_49 )
{
unsigned long V_50 = F_30 ( V_46 ) ;
unsigned char * V_51 = F_11 ( V_47 ) ;
if ( F_31 ( F_32 ( V_50 ) ) ) {
unsigned int V_52 = V_46 & ~ V_53 ;
char * V_54 ;
unsigned int V_55 = 0 ;
unsigned long V_56 ;
while ( V_5 ) {
V_55 = F_33 ( T_3 , V_24 - V_52 , V_5 ) ;
F_34 ( V_56 ) ;
V_54 = F_35 ( F_32 ( V_50 ) ) ;
if ( V_49 == V_57 )
memcpy ( V_51 , V_54 + V_52 , V_55 ) ;
else
memcpy ( V_54 + V_52 , V_51 , V_55 ) ;
F_36 ( V_54 ) ;
F_37 ( V_56 ) ;
V_5 -= V_55 ;
V_50 ++ ;
V_51 += V_55 ;
V_52 = 0 ;
}
} else if ( V_49 == V_57 ) {
memcpy ( V_51 , F_11 ( V_46 ) , V_5 ) ;
} else {
memcpy ( F_11 ( V_46 ) , V_51 , V_5 ) ;
}
}
V_30 F_38 ( struct V_8 * V_9 ,
T_2 V_58 ,
V_30 V_46 , T_3 V_5 ,
enum V_48 V_49 )
{
unsigned long V_56 ;
V_30 V_47 ;
unsigned int V_59 , V_60 , V_61 , V_62 ;
int V_22 ;
unsigned long V_63 ;
unsigned long V_64 ;
unsigned long V_65 ;
if ( V_14 )
F_39 ( L_7 ) ;
V_63 = F_40 ( V_9 ) ;
V_58 &= V_63 ;
V_64 = F_3 ( V_58 , 1 << V_6 ) >> V_6 ;
V_65 = V_63 + 1
? F_3 ( V_63 + 1 , 1 << V_6 ) >> V_6
: 1UL << ( V_66 - V_6 ) ;
V_59 = F_3 ( V_5 , 1 << V_6 ) >> V_6 ;
if ( V_5 > V_24 )
V_60 = ( 1 << ( V_67 - V_6 ) ) ;
else
V_60 = 1 ;
F_41 ( ! V_59 ) ;
F_42 ( & V_68 , V_56 ) ;
V_61 = F_3 ( V_28 , V_60 ) ;
if ( V_61 >= V_2 )
V_61 = 0 ;
V_62 = V_61 ;
do {
while ( F_43 ( V_61 , V_59 , V_64 ,
V_65 ) ) {
V_61 += V_60 ;
if ( V_61 >= V_2 )
V_61 = 0 ;
if ( V_61 == V_62 )
goto V_69;
}
if ( V_27 [ V_61 ] >= V_59 ) {
int V_70 = 0 ;
for ( V_22 = V_61 ; V_22 < ( int ) ( V_61 + V_59 ) ; V_22 ++ )
V_27 [ V_22 ] = 0 ;
for ( V_22 = V_61 - 1 ; ( F_18 ( V_22 , V_3 ) != V_3 - 1 ) && V_27 [ V_22 ] ; V_22 -- )
V_27 [ V_22 ] = ++ V_70 ;
V_47 = V_15 + ( V_61 << V_6 ) ;
V_28 = ( ( V_61 + V_59 ) < V_2
? ( V_61 + V_59 ) : 0 ) ;
goto V_71;
}
V_61 += V_60 ;
if ( V_61 >= V_2 )
V_61 = 0 ;
} while ( V_61 != V_62 );
V_69:
F_44 ( & V_68 , V_56 ) ;
if ( F_45 () )
F_46 ( V_9 , L_8 , V_5 ) ;
return V_72 ;
V_71:
F_44 ( & V_68 , V_56 ) ;
for ( V_22 = 0 ; V_22 < V_59 ; V_22 ++ )
V_29 [ V_61 + V_22 ] = V_46 + ( V_22 << V_6 ) ;
if ( V_49 == V_57 || V_49 == V_73 )
F_29 ( V_46 , V_47 , V_5 , V_57 ) ;
return V_47 ;
}
V_30 F_47 ( struct V_8 * V_9 , V_30 V_74 , T_3 V_5 ,
enum V_48 V_49 )
{
T_2 V_75 = F_7 ( V_9 , V_15 ) ;
return F_38 ( V_9 , V_75 , V_74 , V_5 , V_49 ) ;
}
void F_48 ( struct V_8 * V_9 , V_30 V_47 ,
T_3 V_5 , enum V_48 V_49 )
{
unsigned long V_56 ;
int V_22 , V_70 , V_59 = F_3 ( V_5 , 1 << V_6 ) >> V_6 ;
int V_61 = ( V_47 - V_15 ) >> V_6 ;
V_30 V_46 = V_29 [ V_61 ] ;
if ( V_46 && ( ( V_49 == V_76 ) || ( V_49 == V_73 ) ) )
F_29 ( V_46 , V_47 , V_5 , V_76 ) ;
F_42 ( & V_68 , V_56 ) ;
{
V_70 = ( ( V_61 + V_59 ) < F_3 ( V_61 + 1 , V_3 ) ?
V_27 [ V_61 + V_59 ] : 0 ) ;
for ( V_22 = V_61 + V_59 - 1 ; V_22 >= V_61 ; V_22 -- )
V_27 [ V_22 ] = ++ V_70 ;
for ( V_22 = V_61 - 1 ; ( F_18 ( V_22 , V_3 ) != V_3 - 1 ) && V_27 [ V_22 ] ; V_22 -- )
V_27 [ V_22 ] = ++ V_70 ;
}
F_44 ( & V_68 , V_56 ) ;
}
void F_49 ( struct V_8 * V_9 , V_30 V_47 ,
T_3 V_5 , enum V_48 V_49 ,
enum V_77 V_78 )
{
int V_61 = ( V_47 - V_15 ) >> V_6 ;
V_30 V_46 = V_29 [ V_61 ] ;
V_46 += ( unsigned long ) V_47 & ( ( 1 << V_6 ) - 1 ) ;
switch ( V_78 ) {
case V_79 :
if ( F_50 ( V_49 == V_76 || V_49 == V_73 ) )
F_29 ( V_46 , V_47 ,
V_5 , V_76 ) ;
else
F_41 ( V_49 != V_57 ) ;
break;
case V_80 :
if ( F_50 ( V_49 == V_57 || V_49 == V_73 ) )
F_29 ( V_46 , V_47 ,
V_5 , V_57 ) ;
else
F_41 ( V_49 != V_76 ) ;
break;
default:
F_51 () ;
}
}
void *
F_52 ( struct V_8 * V_9 , T_3 V_5 ,
T_2 * V_81 , T_4 V_56 )
{
T_2 V_82 ;
void * V_83 ;
int V_33 = F_22 ( V_5 ) ;
T_5 V_84 = F_53 ( 32 ) ;
if ( V_9 && V_9 -> V_85 )
V_84 = V_9 -> V_85 ;
V_83 = ( void * ) F_23 ( V_56 , V_33 ) ;
if ( V_83 ) {
V_82 = F_6 ( V_9 , V_83 ) ;
if ( V_82 + V_5 - 1 > V_84 ) {
F_25 ( ( unsigned long ) V_83 , V_33 ) ;
V_83 = NULL ;
}
}
if ( ! V_83 ) {
V_30 V_45 = F_47 ( V_9 , 0 , V_5 , V_76 ) ;
if ( V_45 == V_72 )
return NULL ;
V_83 = F_11 ( V_45 ) ;
V_82 = F_7 ( V_9 , V_45 ) ;
if ( V_82 + V_5 - 1 > V_84 ) {
F_12 ( L_9 ,
( unsigned long long ) V_84 ,
( unsigned long long ) V_82 ) ;
F_48 ( V_9 , V_45 ,
V_5 , V_57 ) ;
return NULL ;
}
}
* V_81 = V_82 ;
memset ( V_83 , 0 , V_5 ) ;
return V_83 ;
}
void
F_54 ( struct V_8 * V_9 , T_3 V_5 , void * V_51 ,
T_2 V_82 )
{
V_30 V_45 = F_55 ( V_9 , V_82 ) ;
F_56 ( F_57 () ) ;
if ( ! F_28 ( V_45 ) )
F_25 ( ( unsigned long ) V_51 , F_22 ( V_5 ) ) ;
else
F_48 ( V_9 , V_45 , V_5 , V_57 ) ;
}
static void
F_58 ( struct V_8 * V_86 , T_3 V_5 , enum V_48 V_49 ,
int V_87 )
{
F_12 ( V_88 L_10
L_11 , V_5 , V_86 ? F_59 ( V_86 ) : L_12 ) ;
if ( V_5 <= V_23 || ! V_87 )
return;
if ( V_49 == V_73 )
F_39 ( L_13 ) ;
if ( V_49 == V_76 )
F_39 ( L_14 ) ;
if ( V_49 == V_57 )
F_39 ( L_15 ) ;
}
T_2 F_60 ( struct V_8 * V_86 , struct V_89 * V_89 ,
unsigned long V_52 , T_3 V_5 ,
enum V_48 V_49 ,
struct V_90 * V_91 )
{
V_30 V_92 , V_74 = F_61 ( V_89 ) + V_52 ;
T_2 V_82 = F_7 ( V_86 , V_74 ) ;
F_41 ( V_49 == V_93 ) ;
if ( F_62 ( V_86 , V_82 , V_5 ) && ! V_4 )
return V_82 ;
F_63 ( V_86 , V_82 , V_5 , V_4 ) ;
V_92 = F_47 ( V_86 , V_74 , V_5 , V_49 ) ;
if ( V_92 == V_72 ) {
F_58 ( V_86 , V_5 , V_49 , 1 ) ;
return F_7 ( V_86 , V_26 ) ;
}
V_82 = F_7 ( V_86 , V_92 ) ;
if ( ! F_62 ( V_86 , V_82 , V_5 ) ) {
F_48 ( V_86 , V_92 , V_5 , V_49 ) ;
return F_7 ( V_86 , V_26 ) ;
}
return V_82 ;
}
static void F_64 ( struct V_8 * V_9 , T_2 V_82 ,
T_3 V_5 , enum V_48 V_49 )
{
V_30 V_45 = F_55 ( V_9 , V_82 ) ;
F_41 ( V_49 == V_93 ) ;
if ( F_28 ( V_45 ) ) {
F_48 ( V_9 , V_45 , V_5 , V_49 ) ;
return;
}
if ( V_49 != V_76 )
return;
F_65 ( F_11 ( V_45 ) , V_5 ) ;
}
void F_66 ( struct V_8 * V_9 , T_2 V_82 ,
T_3 V_5 , enum V_48 V_49 ,
struct V_90 * V_91 )
{
F_64 ( V_9 , V_82 , V_5 , V_49 ) ;
}
static void
F_67 ( struct V_8 * V_9 , T_2 V_82 ,
T_3 V_5 , enum V_48 V_49 ,
enum V_77 V_78 )
{
V_30 V_45 = F_55 ( V_9 , V_82 ) ;
F_41 ( V_49 == V_93 ) ;
if ( F_28 ( V_45 ) ) {
F_49 ( V_9 , V_45 , V_5 , V_49 , V_78 ) ;
return;
}
if ( V_49 != V_76 )
return;
F_65 ( F_11 ( V_45 ) , V_5 ) ;
}
void
F_68 ( struct V_8 * V_9 , T_2 V_82 ,
T_3 V_5 , enum V_48 V_49 )
{
F_67 ( V_9 , V_82 , V_5 , V_49 , V_79 ) ;
}
void
F_69 ( struct V_8 * V_9 , T_2 V_82 ,
T_3 V_5 , enum V_48 V_49 )
{
F_67 ( V_9 , V_82 , V_5 , V_49 , V_80 ) ;
}
int
F_70 ( struct V_8 * V_9 , struct V_94 * V_95 , int V_96 ,
enum V_48 V_49 , struct V_90 * V_91 )
{
struct V_94 * V_97 ;
int V_22 ;
F_41 ( V_49 == V_93 ) ;
F_71 (sgl, sg, nelems, i) {
V_30 V_45 = F_72 ( V_97 ) ;
T_2 V_82 = F_7 ( V_9 , V_45 ) ;
if ( V_4 ||
! F_62 ( V_9 , V_82 , V_97 -> V_98 ) ) {
V_30 V_92 = F_47 ( V_9 , F_72 ( V_97 ) ,
V_97 -> V_98 , V_49 ) ;
if ( V_92 == V_72 ) {
F_58 ( V_9 , V_97 -> V_98 , V_49 , 0 ) ;
F_73 ( V_9 , V_95 , V_22 , V_49 ,
V_91 ) ;
F_74 ( V_95 ) = 0 ;
return 0 ;
}
V_97 -> V_99 = F_7 ( V_9 , V_92 ) ;
} else
V_97 -> V_99 = V_82 ;
F_74 ( V_97 ) = V_97 -> V_98 ;
}
return V_96 ;
}
int
F_75 ( struct V_8 * V_9 , struct V_94 * V_95 , int V_96 ,
enum V_48 V_49 )
{
return F_70 ( V_9 , V_95 , V_96 , V_49 , NULL ) ;
}
void
F_73 ( struct V_8 * V_9 , struct V_94 * V_95 ,
int V_96 , enum V_48 V_49 , struct V_90 * V_91 )
{
struct V_94 * V_97 ;
int V_22 ;
F_41 ( V_49 == V_93 ) ;
F_71 (sgl, sg, nelems, i)
F_64 ( V_9 , V_97 -> V_99 , F_74 ( V_97 ) , V_49 ) ;
}
void
F_76 ( struct V_8 * V_9 , struct V_94 * V_95 , int V_96 ,
enum V_48 V_49 )
{
return F_73 ( V_9 , V_95 , V_96 , V_49 , NULL ) ;
}
static void
F_77 ( struct V_8 * V_9 , struct V_94 * V_95 ,
int V_96 , enum V_48 V_49 ,
enum V_77 V_78 )
{
struct V_94 * V_97 ;
int V_22 ;
F_71 (sgl, sg, nelems, i)
F_67 ( V_9 , V_97 -> V_99 ,
F_74 ( V_97 ) , V_49 , V_78 ) ;
}
void
F_78 ( struct V_8 * V_9 , struct V_94 * V_97 ,
int V_96 , enum V_48 V_49 )
{
F_77 ( V_9 , V_97 , V_96 , V_49 , V_79 ) ;
}
void
F_79 ( struct V_8 * V_9 , struct V_94 * V_97 ,
int V_96 , enum V_48 V_49 )
{
F_77 ( V_9 , V_97 , V_96 , V_49 , V_80 ) ;
}
int
F_80 ( struct V_8 * V_9 , T_2 V_100 )
{
return ( V_100 == F_7 ( V_9 , V_26 ) ) ;
}
int
F_81 ( struct V_8 * V_9 , T_5 V_63 )
{
return F_7 ( V_9 , V_16 - 1 ) <= V_63 ;
}
