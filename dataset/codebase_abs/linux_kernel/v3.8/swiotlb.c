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
unsigned char * V_10 , * V_11 ;
V_10 = F_9 ( V_12 ) ;
V_11 = F_9 ( V_13 ) ;
F_10 ( V_14 L_2 ,
( unsigned long long ) V_12 ,
( unsigned long long ) V_13 ,
V_8 >> 20 , V_10 , V_11 - 1 ) ;
}
void T_1 F_11 ( char * V_15 , unsigned long V_16 , int V_17 )
{
void * V_18 ;
unsigned long V_19 , V_8 ;
V_8 = V_16 << V_9 ;
V_2 = V_16 ;
V_12 = F_12 ( V_15 ) ;
V_13 = V_12 + V_8 ;
V_18 = F_13 ( F_14 ( V_20 ) ) ;
if ( ! V_18 )
F_15 ( L_3 ) ;
V_21 = F_12 ( V_18 ) ;
V_22 = F_16 ( F_14 ( V_2 * sizeof( int ) ) ) ;
for ( V_19 = 0 ; V_19 < V_2 ; V_19 ++ )
V_22 [ V_19 ] = V_3 - F_17 ( V_19 , V_3 ) ;
V_23 = 0 ;
V_24 = F_16 ( F_14 ( V_2 * sizeof( V_25 ) ) ) ;
if ( V_17 )
F_8 () ;
}
static void T_1
F_18 ( T_3 V_26 , int V_17 )
{
unsigned char * V_10 ;
unsigned long V_8 ;
if ( ! V_2 ) {
V_2 = ( V_26 >> V_9 ) ;
V_2 = F_3 ( V_2 , V_3 ) ;
}
V_8 = V_2 << V_9 ;
V_10 = F_13 ( F_14 ( V_8 ) ) ;
if ( ! V_10 )
F_15 ( L_4 ) ;
F_11 ( V_10 , V_2 , V_17 ) ;
}
void T_1
F_19 ( int V_17 )
{
F_18 ( 64 * ( 1 << 20 ) , V_17 ) ;
}
int
F_20 ( T_3 V_26 )
{
unsigned long V_8 , V_27 = V_2 ;
unsigned char * V_10 = NULL ;
unsigned int V_28 ;
int V_29 = 0 ;
if ( ! V_2 ) {
V_2 = ( V_26 >> V_9 ) ;
V_2 = F_3 ( V_2 , V_3 ) ;
}
V_28 = F_21 ( V_2 << V_9 ) ;
V_2 = V_30 << V_28 ;
V_8 = V_2 << V_9 ;
while ( ( V_30 << V_28 ) > V_31 ) {
V_10 = ( void * ) F_22 ( V_32 | V_33 ,
V_28 ) ;
if ( V_10 )
break;
V_28 -- ;
}
if ( ! V_10 ) {
V_2 = V_27 ;
return - V_34 ;
}
if ( V_28 != F_21 ( V_8 ) ) {
F_10 ( V_35 L_5
L_6 , ( V_36 << V_28 ) >> 20 ) ;
V_2 = V_30 << V_28 ;
}
V_29 = F_23 ( V_10 , V_2 ) ;
if ( V_29 )
F_24 ( ( unsigned long ) V_10 , V_28 ) ;
return V_29 ;
}
int
F_23 ( char * V_15 , unsigned long V_16 )
{
unsigned long V_19 , V_8 ;
unsigned char * V_18 ;
V_8 = V_16 << V_9 ;
V_2 = V_16 ;
V_12 = F_7 ( V_15 ) ;
V_13 = V_12 + V_8 ;
memset ( V_15 , 0 , V_8 ) ;
V_18 = ( void * ) F_22 ( V_32 ,
F_21 ( V_20 ) ) ;
if ( ! V_18 )
goto V_37;
V_21 = F_7 ( V_18 ) ;
V_22 = ( unsigned int * ) F_22 ( V_38 ,
F_21 ( V_2 * sizeof( int ) ) ) ;
if ( ! V_22 )
goto V_39;
for ( V_19 = 0 ; V_19 < V_2 ; V_19 ++ )
V_22 [ V_19 ] = V_3 - F_17 ( V_19 , V_3 ) ;
V_23 = 0 ;
V_24 = ( V_25 * )
F_22 ( V_38 ,
F_21 ( V_2 *
sizeof( V_25 ) ) ) ;
if ( ! V_24 )
goto V_40;
memset ( V_24 , 0 , V_2 * sizeof( V_25 ) ) ;
F_8 () ;
V_41 = 1 ;
return 0 ;
V_40:
F_24 ( ( unsigned long ) V_22 , F_21 ( V_2 *
sizeof( int ) ) ) ;
V_22 = NULL ;
V_39:
F_24 ( ( unsigned long ) V_18 ,
F_21 ( V_20 ) ) ;
V_21 = 0 ;
V_37:
V_13 = 0 ;
V_12 = 0 ;
V_2 = 0 ;
return - V_34 ;
}
void T_1 F_25 ( void )
{
if ( ! V_24 )
return;
if ( V_41 ) {
F_24 ( ( unsigned long ) F_9 ( V_21 ) ,
F_21 ( V_20 ) ) ;
F_24 ( ( unsigned long ) V_24 ,
F_21 ( V_2 * sizeof( V_25 ) ) ) ;
F_24 ( ( unsigned long ) V_22 , F_21 ( V_2 *
sizeof( int ) ) ) ;
F_24 ( ( unsigned long ) F_9 ( V_12 ) ,
F_21 ( V_2 << V_9 ) ) ;
} else {
F_26 ( V_21 ,
F_14 ( V_20 ) ) ;
F_26 ( F_12 ( V_24 ) ,
F_14 ( V_2 * sizeof( V_25 ) ) ) ;
F_26 ( F_12 ( V_22 ) ,
F_14 ( V_2 * sizeof( int ) ) ) ;
F_26 ( V_12 ,
F_14 ( V_2 << V_9 ) ) ;
}
V_2 = 0 ;
}
static int F_27 ( V_25 V_42 )
{
return V_42 >= V_12 && V_42 < V_13 ;
}
static void F_28 ( V_25 V_43 , V_25 V_44 ,
T_3 V_45 , enum V_46 V_47 )
{
unsigned long V_48 = F_29 ( V_43 ) ;
unsigned char * V_49 = F_9 ( V_44 ) ;
if ( F_30 ( F_31 ( V_48 ) ) ) {
unsigned int V_50 = V_43 & ~ V_51 ;
char * V_52 ;
unsigned int V_53 = 0 ;
unsigned long V_54 ;
while ( V_45 ) {
V_53 = F_32 ( T_3 , V_36 - V_50 , V_45 ) ;
F_33 ( V_54 ) ;
V_52 = F_34 ( F_31 ( V_48 ) ) ;
if ( V_47 == V_55 )
memcpy ( V_49 , V_52 + V_50 , V_53 ) ;
else
memcpy ( V_52 + V_50 , V_49 , V_53 ) ;
F_35 ( V_52 ) ;
F_36 ( V_54 ) ;
V_45 -= V_53 ;
V_48 ++ ;
V_49 += V_53 ;
V_50 = 0 ;
}
} else if ( V_47 == V_55 ) {
memcpy ( V_49 , F_9 ( V_43 ) , V_45 ) ;
} else {
memcpy ( F_9 ( V_43 ) , V_49 , V_45 ) ;
}
}
V_25 F_37 ( struct V_5 * V_6 ,
T_2 V_56 ,
V_25 V_43 , T_3 V_45 ,
enum V_46 V_47 )
{
unsigned long V_54 ;
V_25 V_44 ;
unsigned int V_57 , V_58 , V_59 , V_60 ;
int V_19 ;
unsigned long V_61 ;
unsigned long V_62 ;
unsigned long V_63 ;
V_61 = F_38 ( V_6 ) ;
V_56 &= V_61 ;
V_62 = F_3 ( V_56 , 1 << V_9 ) >> V_9 ;
V_63 = V_61 + 1
? F_3 ( V_61 + 1 , 1 << V_9 ) >> V_9
: 1UL << ( V_64 - V_9 ) ;
V_57 = F_3 ( V_45 , 1 << V_9 ) >> V_9 ;
if ( V_45 > V_36 )
V_58 = ( 1 << ( V_65 - V_9 ) ) ;
else
V_58 = 1 ;
F_39 ( ! V_57 ) ;
F_40 ( & V_66 , V_54 ) ;
V_59 = F_3 ( V_23 , V_58 ) ;
if ( V_59 >= V_2 )
V_59 = 0 ;
V_60 = V_59 ;
do {
while ( F_41 ( V_59 , V_57 , V_62 ,
V_63 ) ) {
V_59 += V_58 ;
if ( V_59 >= V_2 )
V_59 = 0 ;
if ( V_59 == V_60 )
goto V_67;
}
if ( V_22 [ V_59 ] >= V_57 ) {
int V_68 = 0 ;
for ( V_19 = V_59 ; V_19 < ( int ) ( V_59 + V_57 ) ; V_19 ++ )
V_22 [ V_19 ] = 0 ;
for ( V_19 = V_59 - 1 ; ( F_17 ( V_19 , V_3 ) != V_3 - 1 ) && V_22 [ V_19 ] ; V_19 -- )
V_22 [ V_19 ] = ++ V_68 ;
V_44 = V_12 + ( V_59 << V_9 ) ;
V_23 = ( ( V_59 + V_57 ) < V_2
? ( V_59 + V_57 ) : 0 ) ;
goto V_69;
}
V_59 += V_58 ;
if ( V_59 >= V_2 )
V_59 = 0 ;
} while ( V_59 != V_60 );
V_67:
F_42 ( & V_66 , V_54 ) ;
return V_70 ;
V_69:
F_42 ( & V_66 , V_54 ) ;
for ( V_19 = 0 ; V_19 < V_57 ; V_19 ++ )
V_24 [ V_59 + V_19 ] = V_43 + ( V_19 << V_9 ) ;
if ( V_47 == V_55 || V_47 == V_71 )
F_28 ( V_43 , V_44 , V_45 , V_55 ) ;
return V_44 ;
}
V_25 F_43 ( struct V_5 * V_6 , V_25 V_72 , T_3 V_45 ,
enum V_46 V_47 )
{
T_2 V_73 = F_6 ( V_6 , V_12 ) ;
return F_37 ( V_6 , V_73 , V_72 , V_45 , V_47 ) ;
}
void F_44 ( struct V_5 * V_6 , V_25 V_44 ,
T_3 V_45 , enum V_46 V_47 )
{
unsigned long V_54 ;
int V_19 , V_68 , V_57 = F_3 ( V_45 , 1 << V_9 ) >> V_9 ;
int V_59 = ( V_44 - V_12 ) >> V_9 ;
V_25 V_43 = V_24 [ V_59 ] ;
if ( V_43 && ( ( V_47 == V_74 ) || ( V_47 == V_71 ) ) )
F_28 ( V_43 , V_44 , V_45 , V_74 ) ;
F_40 ( & V_66 , V_54 ) ;
{
V_68 = ( ( V_59 + V_57 ) < F_3 ( V_59 + 1 , V_3 ) ?
V_22 [ V_59 + V_57 ] : 0 ) ;
for ( V_19 = V_59 + V_57 - 1 ; V_19 >= V_59 ; V_19 -- )
V_22 [ V_19 ] = ++ V_68 ;
for ( V_19 = V_59 - 1 ; ( F_17 ( V_19 , V_3 ) != V_3 - 1 ) && V_22 [ V_19 ] ; V_19 -- )
V_22 [ V_19 ] = ++ V_68 ;
}
F_42 ( & V_66 , V_54 ) ;
}
void F_45 ( struct V_5 * V_6 , V_25 V_44 ,
T_3 V_45 , enum V_46 V_47 ,
enum V_75 V_76 )
{
int V_59 = ( V_44 - V_12 ) >> V_9 ;
V_25 V_43 = V_24 [ V_59 ] ;
V_43 += ( unsigned long ) V_44 & ( ( 1 << V_9 ) - 1 ) ;
switch ( V_76 ) {
case V_77 :
if ( F_46 ( V_47 == V_74 || V_47 == V_71 ) )
F_28 ( V_43 , V_44 ,
V_45 , V_74 ) ;
else
F_39 ( V_47 != V_55 ) ;
break;
case V_78 :
if ( F_46 ( V_47 == V_55 || V_47 == V_71 ) )
F_28 ( V_43 , V_44 ,
V_45 , V_55 ) ;
else
F_39 ( V_47 != V_74 ) ;
break;
default:
F_47 () ;
}
}
void *
F_48 ( struct V_5 * V_6 , T_3 V_45 ,
T_2 * V_79 , T_4 V_54 )
{
T_2 V_80 ;
void * V_81 ;
int V_28 = F_21 ( V_45 ) ;
T_5 V_82 = F_49 ( 32 ) ;
if ( V_6 && V_6 -> V_83 )
V_82 = V_6 -> V_83 ;
V_81 = ( void * ) F_22 ( V_54 , V_28 ) ;
if ( V_81 ) {
V_80 = F_5 ( V_6 , V_81 ) ;
if ( V_80 + V_45 - 1 > V_82 ) {
F_24 ( ( unsigned long ) V_81 , V_28 ) ;
V_81 = NULL ;
}
}
if ( ! V_81 ) {
V_25 V_42 = F_43 ( V_6 , 0 , V_45 , V_74 ) ;
if ( V_42 == V_70 )
return NULL ;
V_81 = F_9 ( V_42 ) ;
V_80 = F_6 ( V_6 , V_42 ) ;
if ( V_80 + V_45 - 1 > V_82 ) {
F_10 ( L_7 ,
( unsigned long long ) V_82 ,
( unsigned long long ) V_80 ) ;
F_44 ( V_6 , V_42 ,
V_45 , V_55 ) ;
return NULL ;
}
}
* V_79 = V_80 ;
memset ( V_81 , 0 , V_45 ) ;
return V_81 ;
}
void
F_50 ( struct V_5 * V_6 , T_3 V_45 , void * V_49 ,
T_2 V_80 )
{
V_25 V_42 = F_51 ( V_6 , V_80 ) ;
F_52 ( F_53 () ) ;
if ( ! F_27 ( V_42 ) )
F_24 ( ( unsigned long ) V_49 , F_21 ( V_45 ) ) ;
else
F_44 ( V_6 , V_42 , V_45 , V_55 ) ;
}
static void
F_54 ( struct V_5 * V_84 , T_3 V_45 , enum V_46 V_47 ,
int V_85 )
{
F_10 ( V_86 L_8
L_9 , V_45 , V_84 ? F_55 ( V_84 ) : L_10 ) ;
if ( V_45 <= V_20 || ! V_85 )
return;
if ( V_47 == V_71 )
F_15 ( L_11 ) ;
if ( V_47 == V_74 )
F_15 ( L_12 ) ;
if ( V_47 == V_55 )
F_15 ( L_13 ) ;
}
T_2 F_56 ( struct V_5 * V_84 , struct V_87 * V_87 ,
unsigned long V_50 , T_3 V_45 ,
enum V_46 V_47 ,
struct V_88 * V_89 )
{
V_25 V_90 , V_72 = F_57 ( V_87 ) + V_50 ;
T_2 V_80 = F_6 ( V_84 , V_72 ) ;
F_39 ( V_47 == V_91 ) ;
if ( F_58 ( V_84 , V_80 , V_45 ) && ! V_4 )
return V_80 ;
V_90 = F_43 ( V_84 , V_72 , V_45 , V_47 ) ;
if ( V_90 == V_70 ) {
F_54 ( V_84 , V_45 , V_47 , 1 ) ;
return F_6 ( V_84 , V_21 ) ;
}
V_80 = F_6 ( V_84 , V_90 ) ;
if ( ! F_58 ( V_84 , V_80 , V_45 ) ) {
F_44 ( V_84 , V_90 , V_45 , V_47 ) ;
return F_6 ( V_84 , V_21 ) ;
}
return V_80 ;
}
static void F_59 ( struct V_5 * V_6 , T_2 V_80 ,
T_3 V_45 , enum V_46 V_47 )
{
V_25 V_42 = F_51 ( V_6 , V_80 ) ;
F_39 ( V_47 == V_91 ) ;
if ( F_27 ( V_42 ) ) {
F_44 ( V_6 , V_42 , V_45 , V_47 ) ;
return;
}
if ( V_47 != V_74 )
return;
F_60 ( F_9 ( V_42 ) , V_45 ) ;
}
void F_61 ( struct V_5 * V_6 , T_2 V_80 ,
T_3 V_45 , enum V_46 V_47 ,
struct V_88 * V_89 )
{
F_59 ( V_6 , V_80 , V_45 , V_47 ) ;
}
static void
F_62 ( struct V_5 * V_6 , T_2 V_80 ,
T_3 V_45 , enum V_46 V_47 ,
enum V_75 V_76 )
{
V_25 V_42 = F_51 ( V_6 , V_80 ) ;
F_39 ( V_47 == V_91 ) ;
if ( F_27 ( V_42 ) ) {
F_45 ( V_6 , V_42 , V_45 , V_47 , V_76 ) ;
return;
}
if ( V_47 != V_74 )
return;
F_60 ( F_9 ( V_42 ) , V_45 ) ;
}
void
F_63 ( struct V_5 * V_6 , T_2 V_80 ,
T_3 V_45 , enum V_46 V_47 )
{
F_62 ( V_6 , V_80 , V_45 , V_47 , V_77 ) ;
}
void
F_64 ( struct V_5 * V_6 , T_2 V_80 ,
T_3 V_45 , enum V_46 V_47 )
{
F_62 ( V_6 , V_80 , V_45 , V_47 , V_78 ) ;
}
int
F_65 ( struct V_5 * V_6 , struct V_92 * V_93 , int V_94 ,
enum V_46 V_47 , struct V_88 * V_89 )
{
struct V_92 * V_95 ;
int V_19 ;
F_39 ( V_47 == V_91 ) ;
F_66 (sgl, sg, nelems, i) {
V_25 V_42 = F_67 ( V_95 ) ;
T_2 V_80 = F_6 ( V_6 , V_42 ) ;
if ( V_4 ||
! F_58 ( V_6 , V_80 , V_95 -> V_96 ) ) {
V_25 V_90 = F_43 ( V_6 , F_67 ( V_95 ) ,
V_95 -> V_96 , V_47 ) ;
if ( V_90 == V_70 ) {
F_54 ( V_6 , V_95 -> V_96 , V_47 , 0 ) ;
F_68 ( V_6 , V_93 , V_19 , V_47 ,
V_89 ) ;
V_93 [ 0 ] . V_97 = 0 ;
return 0 ;
}
V_95 -> V_98 = F_6 ( V_6 , V_90 ) ;
} else
V_95 -> V_98 = V_80 ;
V_95 -> V_97 = V_95 -> V_96 ;
}
return V_94 ;
}
int
F_69 ( struct V_5 * V_6 , struct V_92 * V_93 , int V_94 ,
enum V_46 V_47 )
{
return F_65 ( V_6 , V_93 , V_94 , V_47 , NULL ) ;
}
void
F_68 ( struct V_5 * V_6 , struct V_92 * V_93 ,
int V_94 , enum V_46 V_47 , struct V_88 * V_89 )
{
struct V_92 * V_95 ;
int V_19 ;
F_39 ( V_47 == V_91 ) ;
F_66 (sgl, sg, nelems, i)
F_59 ( V_6 , V_95 -> V_98 , V_95 -> V_97 , V_47 ) ;
}
void
F_70 ( struct V_5 * V_6 , struct V_92 * V_93 , int V_94 ,
enum V_46 V_47 )
{
return F_68 ( V_6 , V_93 , V_94 , V_47 , NULL ) ;
}
static void
F_71 ( struct V_5 * V_6 , struct V_92 * V_93 ,
int V_94 , enum V_46 V_47 ,
enum V_75 V_76 )
{
struct V_92 * V_95 ;
int V_19 ;
F_66 (sgl, sg, nelems, i)
F_62 ( V_6 , V_95 -> V_98 ,
V_95 -> V_97 , V_47 , V_76 ) ;
}
void
F_72 ( struct V_5 * V_6 , struct V_92 * V_95 ,
int V_94 , enum V_46 V_47 )
{
F_71 ( V_6 , V_95 , V_94 , V_47 , V_77 ) ;
}
void
F_73 ( struct V_5 * V_6 , struct V_92 * V_95 ,
int V_94 , enum V_46 V_47 )
{
F_71 ( V_6 , V_95 , V_94 , V_47 , V_78 ) ;
}
int
F_74 ( struct V_5 * V_6 , T_2 V_99 )
{
return ( V_99 == F_6 ( V_6 , V_21 ) ) ;
}
int
F_75 ( struct V_5 * V_6 , T_5 V_61 )
{
return F_6 ( V_6 , V_13 - 1 ) <= V_61 ;
}
