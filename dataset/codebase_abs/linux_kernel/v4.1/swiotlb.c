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
V_28 = F_17 (
F_16 ( V_2 * sizeof( V_29 ) ) ,
V_24 ) ;
for ( V_22 = 0 ; V_22 < V_2 ; V_22 ++ ) {
V_27 [ V_22 ] = V_3 - F_18 ( V_22 , V_3 ) ;
V_28 [ V_22 ] = V_30 ;
}
V_31 = 0 ;
if ( V_20 )
F_9 () ;
return 0 ;
}
void T_1
F_19 ( int V_20 )
{
T_3 V_32 = V_7 ;
unsigned char * V_12 ;
unsigned long V_11 ;
if ( ! V_2 ) {
V_2 = ( V_32 >> V_6 ) ;
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
F_21 ( T_3 V_32 )
{
unsigned long V_11 , V_33 = V_2 ;
unsigned char * V_12 = NULL ;
unsigned int V_34 ;
int V_35 = 0 ;
if ( ! V_2 ) {
V_2 = ( V_32 >> V_6 ) ;
V_2 = F_3 ( V_2 , V_3 ) ;
}
V_34 = F_22 ( V_2 << V_6 ) ;
V_2 = V_36 << V_34 ;
V_11 = V_2 << V_6 ;
while ( ( V_36 << V_34 ) > V_37 ) {
V_12 = ( void * ) F_23 ( V_38 | V_39 ,
V_34 ) ;
if ( V_12 )
break;
V_34 -- ;
}
if ( ! V_12 ) {
V_2 = V_33 ;
return - V_25 ;
}
if ( V_34 != F_22 ( V_11 ) ) {
F_12 ( V_40 L_5
L_6 , ( V_24 << V_34 ) >> 20 ) ;
V_2 = V_36 << V_34 ;
}
V_35 = F_24 ( V_12 , V_2 ) ;
if ( V_35 )
F_25 ( ( unsigned long ) V_12 , V_34 ) ;
return V_35 ;
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
V_21 = ( void * ) F_23 ( V_38 ,
F_22 ( V_23 ) ) ;
if ( ! V_21 )
goto V_41;
V_26 = F_8 ( V_21 ) ;
V_27 = ( unsigned int * ) F_23 ( V_42 ,
F_22 ( V_2 * sizeof( int ) ) ) ;
if ( ! V_27 )
goto V_43;
V_28 = ( V_29 * )
F_23 ( V_42 ,
F_22 ( V_2 *
sizeof( V_29 ) ) ) ;
if ( ! V_28 )
goto V_44;
for ( V_22 = 0 ; V_22 < V_2 ; V_22 ++ ) {
V_27 [ V_22 ] = V_3 - F_18 ( V_22 , V_3 ) ;
V_28 [ V_22 ] = V_30 ;
}
V_31 = 0 ;
F_9 () ;
V_45 = 1 ;
return 0 ;
V_44:
F_25 ( ( unsigned long ) V_27 , F_22 ( V_2 *
sizeof( int ) ) ) ;
V_27 = NULL ;
V_43:
F_25 ( ( unsigned long ) V_21 ,
F_22 ( V_23 ) ) ;
V_26 = 0 ;
V_41:
V_16 = 0 ;
V_15 = 0 ;
V_2 = 0 ;
return - V_25 ;
}
void T_1 F_26 ( void )
{
if ( ! V_28 )
return;
if ( V_45 ) {
F_25 ( ( unsigned long ) F_11 ( V_26 ) ,
F_22 ( V_23 ) ) ;
F_25 ( ( unsigned long ) V_28 ,
F_22 ( V_2 * sizeof( V_29 ) ) ) ;
F_25 ( ( unsigned long ) V_27 , F_22 ( V_2 *
sizeof( int ) ) ) ;
F_25 ( ( unsigned long ) F_11 ( V_15 ) ,
F_22 ( V_2 << V_6 ) ) ;
} else {
F_27 ( V_26 ,
F_16 ( V_23 ) ) ;
F_27 ( F_14 ( V_28 ) ,
F_16 ( V_2 * sizeof( V_29 ) ) ) ;
F_27 ( F_14 ( V_27 ) ,
F_16 ( V_2 * sizeof( int ) ) ) ;
F_27 ( V_15 ,
F_16 ( V_2 << V_6 ) ) ;
}
V_2 = 0 ;
}
int F_28 ( V_29 V_46 )
{
return V_46 >= V_15 && V_46 < V_16 ;
}
static void F_29 ( V_29 V_47 , V_29 V_48 ,
T_3 V_5 , enum V_49 V_50 )
{
unsigned long V_51 = F_30 ( V_47 ) ;
unsigned char * V_52 = F_11 ( V_48 ) ;
if ( F_31 ( F_32 ( V_51 ) ) ) {
unsigned int V_53 = V_47 & ~ V_54 ;
char * V_55 ;
unsigned int V_56 = 0 ;
unsigned long V_57 ;
while ( V_5 ) {
V_56 = F_33 ( T_3 , V_24 - V_53 , V_5 ) ;
F_34 ( V_57 ) ;
V_55 = F_35 ( F_32 ( V_51 ) ) ;
if ( V_50 == V_58 )
memcpy ( V_52 , V_55 + V_53 , V_56 ) ;
else
memcpy ( V_55 + V_53 , V_52 , V_56 ) ;
F_36 ( V_55 ) ;
F_37 ( V_57 ) ;
V_5 -= V_56 ;
V_51 ++ ;
V_52 += V_56 ;
V_53 = 0 ;
}
} else if ( V_50 == V_58 ) {
memcpy ( V_52 , F_11 ( V_47 ) , V_5 ) ;
} else {
memcpy ( F_11 ( V_47 ) , V_52 , V_5 ) ;
}
}
V_29 F_38 ( struct V_8 * V_9 ,
T_2 V_59 ,
V_29 V_47 , T_3 V_5 ,
enum V_49 V_50 )
{
unsigned long V_57 ;
V_29 V_48 ;
unsigned int V_60 , V_61 , V_62 , V_63 ;
int V_22 ;
unsigned long V_64 ;
unsigned long V_65 ;
unsigned long V_66 ;
if ( V_14 )
F_39 ( L_7 ) ;
V_64 = F_40 ( V_9 ) ;
V_59 &= V_64 ;
V_65 = F_3 ( V_59 , 1 << V_6 ) >> V_6 ;
V_66 = V_64 + 1
? F_3 ( V_64 + 1 , 1 << V_6 ) >> V_6
: 1UL << ( V_67 - V_6 ) ;
V_60 = F_3 ( V_5 , 1 << V_6 ) >> V_6 ;
if ( V_5 > V_24 )
V_61 = ( 1 << ( V_68 - V_6 ) ) ;
else
V_61 = 1 ;
F_41 ( ! V_60 ) ;
F_42 ( & V_69 , V_57 ) ;
V_62 = F_3 ( V_31 , V_61 ) ;
if ( V_62 >= V_2 )
V_62 = 0 ;
V_63 = V_62 ;
do {
while ( F_43 ( V_62 , V_60 , V_65 ,
V_66 ) ) {
V_62 += V_61 ;
if ( V_62 >= V_2 )
V_62 = 0 ;
if ( V_62 == V_63 )
goto V_70;
}
if ( V_27 [ V_62 ] >= V_60 ) {
int V_71 = 0 ;
for ( V_22 = V_62 ; V_22 < ( int ) ( V_62 + V_60 ) ; V_22 ++ )
V_27 [ V_22 ] = 0 ;
for ( V_22 = V_62 - 1 ; ( F_18 ( V_22 , V_3 ) != V_3 - 1 ) && V_27 [ V_22 ] ; V_22 -- )
V_27 [ V_22 ] = ++ V_71 ;
V_48 = V_15 + ( V_62 << V_6 ) ;
V_31 = ( ( V_62 + V_60 ) < V_2
? ( V_62 + V_60 ) : 0 ) ;
goto V_72;
}
V_62 += V_61 ;
if ( V_62 >= V_2 )
V_62 = 0 ;
} while ( V_62 != V_63 );
V_70:
F_44 ( & V_69 , V_57 ) ;
if ( F_45 () )
F_46 ( V_9 , L_8 , V_5 ) ;
return V_73 ;
V_72:
F_44 ( & V_69 , V_57 ) ;
for ( V_22 = 0 ; V_22 < V_60 ; V_22 ++ )
V_28 [ V_62 + V_22 ] = V_47 + ( V_22 << V_6 ) ;
if ( V_50 == V_58 || V_50 == V_74 )
F_29 ( V_47 , V_48 , V_5 , V_58 ) ;
return V_48 ;
}
static V_29
F_47 ( struct V_8 * V_9 , V_29 V_75 , T_3 V_5 ,
enum V_49 V_50 )
{
T_2 V_76 = F_7 ( V_9 , V_15 ) ;
return F_38 ( V_9 , V_76 , V_75 , V_5 , V_50 ) ;
}
void F_48 ( struct V_8 * V_9 , V_29 V_48 ,
T_3 V_5 , enum V_49 V_50 )
{
unsigned long V_57 ;
int V_22 , V_71 , V_60 = F_3 ( V_5 , 1 << V_6 ) >> V_6 ;
int V_62 = ( V_48 - V_15 ) >> V_6 ;
V_29 V_47 = V_28 [ V_62 ] ;
if ( V_47 != V_30 &&
( ( V_50 == V_77 ) || ( V_50 == V_74 ) ) )
F_29 ( V_47 , V_48 , V_5 , V_77 ) ;
F_42 ( & V_69 , V_57 ) ;
{
V_71 = ( ( V_62 + V_60 ) < F_3 ( V_62 + 1 , V_3 ) ?
V_27 [ V_62 + V_60 ] : 0 ) ;
for ( V_22 = V_62 + V_60 - 1 ; V_22 >= V_62 ; V_22 -- ) {
V_27 [ V_22 ] = ++ V_71 ;
V_28 [ V_22 ] = V_30 ;
}
for ( V_22 = V_62 - 1 ; ( F_18 ( V_22 , V_3 ) != V_3 - 1 ) && V_27 [ V_22 ] ; V_22 -- )
V_27 [ V_22 ] = ++ V_71 ;
}
F_44 ( & V_69 , V_57 ) ;
}
void F_49 ( struct V_8 * V_9 , V_29 V_48 ,
T_3 V_5 , enum V_49 V_50 ,
enum V_78 V_79 )
{
int V_62 = ( V_48 - V_15 ) >> V_6 ;
V_29 V_47 = V_28 [ V_62 ] ;
if ( V_47 == V_30 )
return;
V_47 += ( unsigned long ) V_48 & ( ( 1 << V_6 ) - 1 ) ;
switch ( V_79 ) {
case V_80 :
if ( F_50 ( V_50 == V_77 || V_50 == V_74 ) )
F_29 ( V_47 , V_48 ,
V_5 , V_77 ) ;
else
F_41 ( V_50 != V_58 ) ;
break;
case V_81 :
if ( F_50 ( V_50 == V_58 || V_50 == V_74 ) )
F_29 ( V_47 , V_48 ,
V_5 , V_58 ) ;
else
F_41 ( V_50 != V_77 ) ;
break;
default:
F_51 () ;
}
}
void *
F_52 ( struct V_8 * V_9 , T_3 V_5 ,
T_2 * V_82 , T_4 V_57 )
{
T_2 V_83 ;
void * V_84 ;
int V_34 = F_22 ( V_5 ) ;
T_5 V_85 = F_53 ( 32 ) ;
if ( V_9 && V_9 -> V_86 )
V_85 = V_9 -> V_86 ;
V_84 = ( void * ) F_23 ( V_57 , V_34 ) ;
if ( V_84 ) {
V_83 = F_6 ( V_9 , V_84 ) ;
if ( V_83 + V_5 - 1 > V_85 ) {
F_25 ( ( unsigned long ) V_84 , V_34 ) ;
V_84 = NULL ;
}
}
if ( ! V_84 ) {
V_29 V_46 = F_47 ( V_9 , 0 , V_5 , V_77 ) ;
if ( V_46 == V_73 )
return NULL ;
V_84 = F_11 ( V_46 ) ;
V_83 = F_7 ( V_9 , V_46 ) ;
if ( V_83 + V_5 - 1 > V_85 ) {
F_12 ( L_9 ,
( unsigned long long ) V_85 ,
( unsigned long long ) V_83 ) ;
F_48 ( V_9 , V_46 ,
V_5 , V_58 ) ;
return NULL ;
}
}
* V_82 = V_83 ;
memset ( V_84 , 0 , V_5 ) ;
return V_84 ;
}
void
F_54 ( struct V_8 * V_9 , T_3 V_5 , void * V_52 ,
T_2 V_83 )
{
V_29 V_46 = F_55 ( V_9 , V_83 ) ;
F_56 ( F_57 () ) ;
if ( ! F_28 ( V_46 ) )
F_25 ( ( unsigned long ) V_52 , F_22 ( V_5 ) ) ;
else
F_48 ( V_9 , V_46 , V_5 , V_58 ) ;
}
static void
F_58 ( struct V_8 * V_87 , T_3 V_5 , enum V_49 V_50 ,
int V_88 )
{
F_12 ( V_89 L_10
L_11 , V_5 , V_87 ? F_59 ( V_87 ) : L_12 ) ;
if ( V_5 <= V_23 || ! V_88 )
return;
if ( V_50 == V_74 )
F_39 ( L_13 ) ;
if ( V_50 == V_77 )
F_39 ( L_14 ) ;
if ( V_50 == V_58 )
F_39 ( L_15 ) ;
}
T_2 F_60 ( struct V_8 * V_87 , struct V_90 * V_90 ,
unsigned long V_53 , T_3 V_5 ,
enum V_49 V_50 ,
struct V_91 * V_92 )
{
V_29 V_93 , V_75 = F_61 ( V_90 ) + V_53 ;
T_2 V_83 = F_7 ( V_87 , V_75 ) ;
F_41 ( V_50 == V_94 ) ;
if ( F_62 ( V_87 , V_83 , V_5 ) && ! V_4 )
return V_83 ;
F_63 ( V_87 , V_83 , V_5 , V_4 ) ;
V_93 = F_47 ( V_87 , V_75 , V_5 , V_50 ) ;
if ( V_93 == V_73 ) {
F_58 ( V_87 , V_5 , V_50 , 1 ) ;
return F_7 ( V_87 , V_26 ) ;
}
V_83 = F_7 ( V_87 , V_93 ) ;
if ( ! F_62 ( V_87 , V_83 , V_5 ) ) {
F_48 ( V_87 , V_93 , V_5 , V_50 ) ;
return F_7 ( V_87 , V_26 ) ;
}
return V_83 ;
}
static void F_64 ( struct V_8 * V_9 , T_2 V_83 ,
T_3 V_5 , enum V_49 V_50 )
{
V_29 V_46 = F_55 ( V_9 , V_83 ) ;
F_41 ( V_50 == V_94 ) ;
if ( F_28 ( V_46 ) ) {
F_48 ( V_9 , V_46 , V_5 , V_50 ) ;
return;
}
if ( V_50 != V_77 )
return;
F_65 ( F_11 ( V_46 ) , V_5 ) ;
}
void F_66 ( struct V_8 * V_9 , T_2 V_83 ,
T_3 V_5 , enum V_49 V_50 ,
struct V_91 * V_92 )
{
F_64 ( V_9 , V_83 , V_5 , V_50 ) ;
}
static void
F_67 ( struct V_8 * V_9 , T_2 V_83 ,
T_3 V_5 , enum V_49 V_50 ,
enum V_78 V_79 )
{
V_29 V_46 = F_55 ( V_9 , V_83 ) ;
F_41 ( V_50 == V_94 ) ;
if ( F_28 ( V_46 ) ) {
F_49 ( V_9 , V_46 , V_5 , V_50 , V_79 ) ;
return;
}
if ( V_50 != V_77 )
return;
F_65 ( F_11 ( V_46 ) , V_5 ) ;
}
void
F_68 ( struct V_8 * V_9 , T_2 V_83 ,
T_3 V_5 , enum V_49 V_50 )
{
F_67 ( V_9 , V_83 , V_5 , V_50 , V_80 ) ;
}
void
F_69 ( struct V_8 * V_9 , T_2 V_83 ,
T_3 V_5 , enum V_49 V_50 )
{
F_67 ( V_9 , V_83 , V_5 , V_50 , V_81 ) ;
}
int
F_70 ( struct V_8 * V_9 , struct V_95 * V_96 , int V_97 ,
enum V_49 V_50 , struct V_91 * V_92 )
{
struct V_95 * V_98 ;
int V_22 ;
F_41 ( V_50 == V_94 ) ;
F_71 (sgl, sg, nelems, i) {
V_29 V_46 = F_72 ( V_98 ) ;
T_2 V_83 = F_7 ( V_9 , V_46 ) ;
if ( V_4 ||
! F_62 ( V_9 , V_83 , V_98 -> V_99 ) ) {
V_29 V_93 = F_47 ( V_9 , F_72 ( V_98 ) ,
V_98 -> V_99 , V_50 ) ;
if ( V_93 == V_73 ) {
F_58 ( V_9 , V_98 -> V_99 , V_50 , 0 ) ;
F_73 ( V_9 , V_96 , V_22 , V_50 ,
V_92 ) ;
F_74 ( V_96 ) = 0 ;
return 0 ;
}
V_98 -> V_100 = F_7 ( V_9 , V_93 ) ;
} else
V_98 -> V_100 = V_83 ;
F_74 ( V_98 ) = V_98 -> V_99 ;
}
return V_97 ;
}
int
F_75 ( struct V_8 * V_9 , struct V_95 * V_96 , int V_97 ,
enum V_49 V_50 )
{
return F_70 ( V_9 , V_96 , V_97 , V_50 , NULL ) ;
}
void
F_73 ( struct V_8 * V_9 , struct V_95 * V_96 ,
int V_97 , enum V_49 V_50 , struct V_91 * V_92 )
{
struct V_95 * V_98 ;
int V_22 ;
F_41 ( V_50 == V_94 ) ;
F_71 (sgl, sg, nelems, i)
F_64 ( V_9 , V_98 -> V_100 , F_74 ( V_98 ) , V_50 ) ;
}
void
F_76 ( struct V_8 * V_9 , struct V_95 * V_96 , int V_97 ,
enum V_49 V_50 )
{
return F_73 ( V_9 , V_96 , V_97 , V_50 , NULL ) ;
}
static void
F_77 ( struct V_8 * V_9 , struct V_95 * V_96 ,
int V_97 , enum V_49 V_50 ,
enum V_78 V_79 )
{
struct V_95 * V_98 ;
int V_22 ;
F_71 (sgl, sg, nelems, i)
F_67 ( V_9 , V_98 -> V_100 ,
F_74 ( V_98 ) , V_50 , V_79 ) ;
}
void
F_78 ( struct V_8 * V_9 , struct V_95 * V_98 ,
int V_97 , enum V_49 V_50 )
{
F_77 ( V_9 , V_98 , V_97 , V_50 , V_80 ) ;
}
void
F_79 ( struct V_8 * V_9 , struct V_95 * V_98 ,
int V_97 , enum V_49 V_50 )
{
F_77 ( V_9 , V_98 , V_97 , V_50 , V_81 ) ;
}
int
F_80 ( struct V_8 * V_9 , T_2 V_101 )
{
return ( V_101 == F_7 ( V_9 , V_26 ) ) ;
}
int
F_81 ( struct V_8 * V_9 , T_5 V_64 )
{
return F_7 ( V_9 , V_16 - 1 ) <= V_64 ;
}
