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
return 1 ;
}
unsigned long F_4 ( void )
{
return V_2 ;
}
static T_2 F_5 ( struct V_5 * V_6 ,
volatile void * V_7 )
{
return F_6 ( V_6 , F_7 ( V_7 ) ) ;
}
void F_8 ( void )
{
unsigned long V_8 = V_2 << V_9 ;
T_3 V_10 , V_11 ;
V_10 = F_7 ( V_12 ) ;
V_11 = F_7 ( V_13 ) ;
F_9 ( V_14 L_2 ,
( unsigned long long ) V_10 , ( unsigned long long ) V_11 - 1 ,
V_8 >> 20 , V_12 , V_13 - 1 ) ;
}
void T_1 F_10 ( char * V_15 , unsigned long V_16 , int V_17 )
{
unsigned long V_18 , V_8 ;
V_8 = V_16 << V_9 ;
V_2 = V_16 ;
V_12 = V_15 ;
V_13 = V_12 + V_8 ;
V_19 = F_11 ( F_12 ( V_2 * sizeof( int ) ) ) ;
for ( V_18 = 0 ; V_18 < V_2 ; V_18 ++ )
V_19 [ V_18 ] = V_3 - F_13 ( V_18 , V_3 ) ;
V_20 = 0 ;
V_21 = F_11 ( F_12 ( V_2 * sizeof( T_3 ) ) ) ;
V_22 = F_14 ( F_12 ( V_23 ) ) ;
if ( ! V_22 )
F_15 ( L_3 ) ;
if ( V_17 )
F_8 () ;
}
void T_1
F_16 ( T_4 V_24 , int V_17 )
{
unsigned long V_8 ;
if ( ! V_2 ) {
V_2 = ( V_24 >> V_9 ) ;
V_2 = F_3 ( V_2 , V_3 ) ;
}
V_8 = V_2 << V_9 ;
V_12 = F_14 ( F_12 ( V_8 ) ) ;
if ( ! V_12 )
F_15 ( L_4 ) ;
F_10 ( V_12 , V_2 , V_17 ) ;
}
void T_1
F_17 ( int V_17 )
{
F_16 ( 64 * ( 1 << 20 ) , V_17 ) ;
}
int
F_18 ( T_4 V_24 )
{
unsigned long V_18 , V_8 , V_25 = V_2 ;
unsigned int V_26 ;
if ( ! V_2 ) {
V_2 = ( V_24 >> V_9 ) ;
V_2 = F_3 ( V_2 , V_3 ) ;
}
V_26 = F_19 ( V_2 << V_9 ) ;
V_2 = V_27 << V_26 ;
V_8 = V_2 << V_9 ;
while ( ( V_27 << V_26 ) > V_28 ) {
V_12 = ( void * ) F_20 ( V_29 | V_30 ,
V_26 ) ;
if ( V_12 )
break;
V_26 -- ;
}
if ( ! V_12 )
goto V_31;
if ( V_26 != F_19 ( V_8 ) ) {
F_9 ( V_32 L_5
L_6 , ( V_33 << V_26 ) >> 20 ) ;
V_2 = V_27 << V_26 ;
V_8 = V_2 << V_9 ;
}
V_13 = V_12 + V_8 ;
memset ( V_12 , 0 , V_8 ) ;
V_19 = ( unsigned int * ) F_20 ( V_34 ,
F_19 ( V_2 * sizeof( int ) ) ) ;
if ( ! V_19 )
goto V_35;
for ( V_18 = 0 ; V_18 < V_2 ; V_18 ++ )
V_19 [ V_18 ] = V_3 - F_13 ( V_18 , V_3 ) ;
V_20 = 0 ;
V_21 = ( T_3 * )
F_20 ( V_34 ,
F_19 ( V_2 *
sizeof( T_3 ) ) ) ;
if ( ! V_21 )
goto V_36;
memset ( V_21 , 0 , V_2 * sizeof( T_3 ) ) ;
V_22 = ( void * ) F_20 ( V_29 ,
F_19 ( V_23 ) ) ;
if ( ! V_22 )
goto V_37;
F_8 () ;
V_38 = 1 ;
return 0 ;
V_37:
F_21 ( ( unsigned long ) V_21 ,
F_19 ( V_2 * sizeof( T_3 ) ) ) ;
V_21 = NULL ;
V_36:
F_21 ( ( unsigned long ) V_19 , F_19 ( V_2 *
sizeof( int ) ) ) ;
V_19 = NULL ;
V_35:
V_13 = NULL ;
F_21 ( ( unsigned long ) V_12 , V_26 ) ;
V_12 = NULL ;
V_31:
V_2 = V_25 ;
return - V_39 ;
}
void T_1 F_22 ( void )
{
if ( ! V_22 )
return;
if ( V_38 ) {
F_21 ( ( unsigned long ) V_22 ,
F_19 ( V_23 ) ) ;
F_21 ( ( unsigned long ) V_21 ,
F_19 ( V_2 * sizeof( T_3 ) ) ) ;
F_21 ( ( unsigned long ) V_19 , F_19 ( V_2 *
sizeof( int ) ) ) ;
F_21 ( ( unsigned long ) V_12 ,
F_19 ( V_2 << V_9 ) ) ;
} else {
F_23 ( F_24 ( V_22 ) ,
F_12 ( V_23 ) ) ;
F_23 ( F_24 ( V_21 ) ,
F_12 ( V_2 * sizeof( T_3 ) ) ) ;
F_23 ( F_24 ( V_19 ) ,
F_12 ( V_2 * sizeof( int ) ) ) ;
F_23 ( F_24 ( V_12 ) ,
F_12 ( V_2 << V_9 ) ) ;
}
V_2 = 0 ;
}
static int F_25 ( T_3 V_40 )
{
return V_40 >= F_7 ( V_12 ) &&
V_40 < F_7 ( V_13 ) ;
}
void F_26 ( T_3 V_41 , char * V_42 , T_4 V_43 ,
enum V_44 V_45 )
{
unsigned long V_46 = F_27 ( V_41 ) ;
if ( F_28 ( F_29 ( V_46 ) ) ) {
unsigned int V_47 = V_41 & ~ V_48 ;
char * V_49 ;
unsigned int V_50 = 0 ;
unsigned long V_51 ;
while ( V_43 ) {
V_50 = F_30 ( T_4 , V_33 - V_47 , V_43 ) ;
F_31 ( V_51 ) ;
V_49 = F_32 ( F_29 ( V_46 ) ) ;
if ( V_45 == V_52 )
memcpy ( V_42 , V_49 + V_47 , V_50 ) ;
else
memcpy ( V_49 + V_47 , V_42 , V_50 ) ;
F_33 ( V_49 ) ;
F_34 ( V_51 ) ;
V_43 -= V_50 ;
V_46 ++ ;
V_42 += V_50 ;
V_47 = 0 ;
}
} else {
if ( V_45 == V_52 )
memcpy ( V_42 , F_35 ( V_41 ) , V_43 ) ;
else
memcpy ( F_35 ( V_41 ) , V_42 , V_43 ) ;
}
}
void * F_36 ( struct V_5 * V_6 , T_2 V_53 ,
T_3 V_41 , T_4 V_43 ,
enum V_44 V_45 )
{
unsigned long V_51 ;
char * V_42 ;
unsigned int V_54 , V_55 , V_56 , V_57 ;
int V_18 ;
unsigned long V_58 ;
unsigned long V_59 ;
unsigned long V_60 ;
V_58 = F_37 ( V_6 ) ;
V_53 &= V_58 ;
V_59 = F_3 ( V_53 , 1 << V_9 ) >> V_9 ;
V_60 = V_58 + 1
? F_3 ( V_58 + 1 , 1 << V_9 ) >> V_9
: 1UL << ( V_61 - V_9 ) ;
V_54 = F_3 ( V_43 , 1 << V_9 ) >> V_9 ;
if ( V_43 > V_33 )
V_55 = ( 1 << ( V_62 - V_9 ) ) ;
else
V_55 = 1 ;
F_38 ( ! V_54 ) ;
F_39 ( & V_63 , V_51 ) ;
V_56 = F_3 ( V_20 , V_55 ) ;
if ( V_56 >= V_2 )
V_56 = 0 ;
V_57 = V_56 ;
do {
while ( F_40 ( V_56 , V_54 , V_59 ,
V_60 ) ) {
V_56 += V_55 ;
if ( V_56 >= V_2 )
V_56 = 0 ;
if ( V_56 == V_57 )
goto V_64;
}
if ( V_19 [ V_56 ] >= V_54 ) {
int V_65 = 0 ;
for ( V_18 = V_56 ; V_18 < ( int ) ( V_56 + V_54 ) ; V_18 ++ )
V_19 [ V_18 ] = 0 ;
for ( V_18 = V_56 - 1 ; ( F_13 ( V_18 , V_3 ) != V_3 - 1 ) && V_19 [ V_18 ] ; V_18 -- )
V_19 [ V_18 ] = ++ V_65 ;
V_42 = V_12 + ( V_56 << V_9 ) ;
V_20 = ( ( V_56 + V_54 ) < V_2
? ( V_56 + V_54 ) : 0 ) ;
goto V_66;
}
V_56 += V_55 ;
if ( V_56 >= V_2 )
V_56 = 0 ;
} while ( V_56 != V_57 );
V_64:
F_41 ( & V_63 , V_51 ) ;
return NULL ;
V_66:
F_41 ( & V_63 , V_51 ) ;
for ( V_18 = 0 ; V_18 < V_54 ; V_18 ++ )
V_21 [ V_56 + V_18 ] = V_41 + ( V_18 << V_9 ) ;
if ( V_45 == V_52 || V_45 == V_67 )
F_26 ( V_41 , V_42 , V_43 , V_52 ) ;
return V_42 ;
}
static void *
F_42 ( struct V_5 * V_6 , T_3 V_41 , T_4 V_43 ,
enum V_44 V_45 )
{
T_2 V_68 = F_5 ( V_6 , V_12 ) ;
return F_36 ( V_6 , V_68 , V_41 , V_43 , V_45 ) ;
}
void
F_43 ( struct V_5 * V_6 , char * V_42 , T_4 V_43 ,
enum V_44 V_45 )
{
unsigned long V_51 ;
int V_18 , V_65 , V_54 = F_3 ( V_43 , 1 << V_9 ) >> V_9 ;
int V_56 = ( V_42 - V_12 ) >> V_9 ;
T_3 V_41 = V_21 [ V_56 ] ;
if ( V_41 && ( ( V_45 == V_69 ) || ( V_45 == V_67 ) ) )
F_26 ( V_41 , V_42 , V_43 , V_69 ) ;
F_39 ( & V_63 , V_51 ) ;
{
V_65 = ( ( V_56 + V_54 ) < F_3 ( V_56 + 1 , V_3 ) ?
V_19 [ V_56 + V_54 ] : 0 ) ;
for ( V_18 = V_56 + V_54 - 1 ; V_18 >= V_56 ; V_18 -- )
V_19 [ V_18 ] = ++ V_65 ;
for ( V_18 = V_56 - 1 ; ( F_13 ( V_18 , V_3 ) != V_3 - 1 ) && V_19 [ V_18 ] ; V_18 -- )
V_19 [ V_18 ] = ++ V_65 ;
}
F_41 ( & V_63 , V_51 ) ;
}
void
F_44 ( struct V_5 * V_6 , char * V_42 , T_4 V_43 ,
enum V_44 V_45 ,
enum V_70 V_71 )
{
int V_56 = ( V_42 - V_12 ) >> V_9 ;
T_3 V_41 = V_21 [ V_56 ] ;
V_41 += ( ( unsigned long ) V_42 & ( ( 1 << V_9 ) - 1 ) ) ;
switch ( V_71 ) {
case V_72 :
if ( F_45 ( V_45 == V_69 || V_45 == V_67 ) )
F_26 ( V_41 , V_42 , V_43 , V_69 ) ;
else
F_38 ( V_45 != V_52 ) ;
break;
case V_73 :
if ( F_45 ( V_45 == V_52 || V_45 == V_67 ) )
F_26 ( V_41 , V_42 , V_43 , V_52 ) ;
else
F_38 ( V_45 != V_69 ) ;
break;
default:
F_46 () ;
}
}
void *
F_47 ( struct V_5 * V_6 , T_4 V_43 ,
T_2 * V_74 , T_5 V_51 )
{
T_2 V_75 ;
void * V_76 ;
int V_26 = F_19 ( V_43 ) ;
T_6 V_77 = F_48 ( 32 ) ;
if ( V_6 && V_6 -> V_78 )
V_77 = V_6 -> V_78 ;
V_76 = ( void * ) F_20 ( V_51 , V_26 ) ;
if ( V_76 && F_5 ( V_6 , V_76 ) + V_43 - 1 > V_77 ) {
F_21 ( ( unsigned long ) V_76 , V_26 ) ;
V_76 = NULL ;
}
if ( ! V_76 ) {
V_76 = F_42 ( V_6 , 0 , V_43 , V_69 ) ;
if ( ! V_76 )
return NULL ;
}
memset ( V_76 , 0 , V_43 ) ;
V_75 = F_5 ( V_6 , V_76 ) ;
if ( V_75 + V_43 - 1 > V_77 ) {
F_9 ( L_7 ,
( unsigned long long ) V_77 ,
( unsigned long long ) V_75 ) ;
F_43 ( V_6 , V_76 , V_43 , V_52 ) ;
return NULL ;
}
* V_74 = V_75 ;
return V_76 ;
}
void
F_49 ( struct V_5 * V_6 , T_4 V_43 , void * V_79 ,
T_2 V_75 )
{
T_3 V_40 = F_50 ( V_6 , V_75 ) ;
F_51 ( F_52 () ) ;
if ( ! F_25 ( V_40 ) )
F_21 ( ( unsigned long ) V_79 , F_19 ( V_43 ) ) ;
else
F_43 ( V_6 , V_79 , V_43 , V_52 ) ;
}
static void
F_53 ( struct V_5 * V_80 , T_4 V_43 , enum V_44 V_45 ,
int V_81 )
{
F_9 ( V_82 L_8
L_9 , V_43 , V_80 ? F_54 ( V_80 ) : L_10 ) ;
if ( V_43 <= V_23 || ! V_81 )
return;
if ( V_45 == V_67 )
F_15 ( L_11 ) ;
if ( V_45 == V_69 )
F_15 ( L_12 ) ;
if ( V_45 == V_52 )
F_15 ( L_13 ) ;
}
T_2 F_55 ( struct V_5 * V_80 , struct V_83 * V_83 ,
unsigned long V_47 , T_4 V_43 ,
enum V_44 V_45 ,
struct V_84 * V_85 )
{
T_3 V_41 = F_56 ( V_83 ) + V_47 ;
T_2 V_75 = F_6 ( V_80 , V_41 ) ;
void * V_86 ;
F_38 ( V_45 == V_87 ) ;
if ( F_57 ( V_80 , V_75 , V_43 ) && ! V_4 )
return V_75 ;
V_86 = F_42 ( V_80 , V_41 , V_43 , V_45 ) ;
if ( ! V_86 ) {
F_53 ( V_80 , V_43 , V_45 , 1 ) ;
V_86 = V_22 ;
}
V_75 = F_5 ( V_80 , V_86 ) ;
if ( ! F_57 ( V_80 , V_75 , V_43 ) ) {
F_43 ( V_80 , V_86 , V_43 , V_45 ) ;
V_75 = F_5 ( V_80 , V_22 ) ;
}
return V_75 ;
}
static void F_58 ( struct V_5 * V_6 , T_2 V_75 ,
T_4 V_43 , enum V_44 V_45 )
{
T_3 V_40 = F_50 ( V_6 , V_75 ) ;
F_38 ( V_45 == V_87 ) ;
if ( F_25 ( V_40 ) ) {
F_43 ( V_6 , F_35 ( V_40 ) , V_43 , V_45 ) ;
return;
}
if ( V_45 != V_69 )
return;
F_59 ( F_35 ( V_40 ) , V_43 ) ;
}
void F_60 ( struct V_5 * V_6 , T_2 V_75 ,
T_4 V_43 , enum V_44 V_45 ,
struct V_84 * V_85 )
{
F_58 ( V_6 , V_75 , V_43 , V_45 ) ;
}
static void
F_61 ( struct V_5 * V_6 , T_2 V_75 ,
T_4 V_43 , enum V_44 V_45 ,
enum V_70 V_71 )
{
T_3 V_40 = F_50 ( V_6 , V_75 ) ;
F_38 ( V_45 == V_87 ) ;
if ( F_25 ( V_40 ) ) {
F_44 ( V_6 , F_35 ( V_40 ) , V_43 , V_45 ,
V_71 ) ;
return;
}
if ( V_45 != V_69 )
return;
F_59 ( F_35 ( V_40 ) , V_43 ) ;
}
void
F_62 ( struct V_5 * V_6 , T_2 V_75 ,
T_4 V_43 , enum V_44 V_45 )
{
F_61 ( V_6 , V_75 , V_43 , V_45 , V_72 ) ;
}
void
F_63 ( struct V_5 * V_6 , T_2 V_75 ,
T_4 V_43 , enum V_44 V_45 )
{
F_61 ( V_6 , V_75 , V_43 , V_45 , V_73 ) ;
}
int
F_64 ( struct V_5 * V_6 , struct V_88 * V_89 , int V_90 ,
enum V_44 V_45 , struct V_84 * V_85 )
{
struct V_88 * V_91 ;
int V_18 ;
F_38 ( V_45 == V_87 ) ;
F_65 (sgl, sg, nelems, i) {
T_3 V_40 = F_66 ( V_91 ) ;
T_2 V_75 = F_6 ( V_6 , V_40 ) ;
if ( V_4 ||
! F_57 ( V_6 , V_75 , V_91 -> V_92 ) ) {
void * V_86 = F_42 ( V_6 , F_66 ( V_91 ) ,
V_91 -> V_92 , V_45 ) ;
if ( ! V_86 ) {
F_53 ( V_6 , V_91 -> V_92 , V_45 , 0 ) ;
F_67 ( V_6 , V_89 , V_18 , V_45 ,
V_85 ) ;
V_89 [ 0 ] . V_93 = 0 ;
return 0 ;
}
V_91 -> V_94 = F_5 ( V_6 , V_86 ) ;
} else
V_91 -> V_94 = V_75 ;
V_91 -> V_93 = V_91 -> V_92 ;
}
return V_90 ;
}
int
F_68 ( struct V_5 * V_6 , struct V_88 * V_89 , int V_90 ,
enum V_44 V_45 )
{
return F_64 ( V_6 , V_89 , V_90 , V_45 , NULL ) ;
}
void
F_67 ( struct V_5 * V_6 , struct V_88 * V_89 ,
int V_90 , enum V_44 V_45 , struct V_84 * V_85 )
{
struct V_88 * V_91 ;
int V_18 ;
F_38 ( V_45 == V_87 ) ;
F_65 (sgl, sg, nelems, i)
F_58 ( V_6 , V_91 -> V_94 , V_91 -> V_93 , V_45 ) ;
}
void
F_69 ( struct V_5 * V_6 , struct V_88 * V_89 , int V_90 ,
enum V_44 V_45 )
{
return F_67 ( V_6 , V_89 , V_90 , V_45 , NULL ) ;
}
static void
F_70 ( struct V_5 * V_6 , struct V_88 * V_89 ,
int V_90 , enum V_44 V_45 ,
enum V_70 V_71 )
{
struct V_88 * V_91 ;
int V_18 ;
F_65 (sgl, sg, nelems, i)
F_61 ( V_6 , V_91 -> V_94 ,
V_91 -> V_93 , V_45 , V_71 ) ;
}
void
F_71 ( struct V_5 * V_6 , struct V_88 * V_91 ,
int V_90 , enum V_44 V_45 )
{
F_70 ( V_6 , V_91 , V_90 , V_45 , V_72 ) ;
}
void
F_72 ( struct V_5 * V_6 , struct V_88 * V_91 ,
int V_90 , enum V_44 V_45 )
{
F_70 ( V_6 , V_91 , V_90 , V_45 , V_73 ) ;
}
int
F_73 ( struct V_5 * V_6 , T_2 V_42 )
{
return ( V_42 == F_5 ( V_6 , V_22 ) ) ;
}
int
F_74 ( struct V_5 * V_6 , T_6 V_58 )
{
return F_5 ( V_6 , V_13 - 1 ) <= V_58 ;
}
