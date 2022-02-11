static void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_2 ( & V_7 ) )
return;
F_3 ( V_8 , L_1 ,
F_4 ( V_2 -> V_9 , V_10 ) ,
V_3 , V_5 -> V_11 ? : L_2 ,
F_4 ( V_2 -> V_9 , V_5 -> V_12 ) ) ;
}
void F_5 ( struct V_1 * V_2 , char * V_13 , enum V_14 V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_16 ;
if ( ! V_5 ) {
F_3 ( V_8 , L_3 ) ;
return;
}
V_16 = ! F_6 ( & V_5 -> V_17 ) ;
if ( V_16 ) {
F_7 ( V_8 , L_4 ,
F_4 ( V_2 -> V_9 , V_10 ) ,
V_13 , V_5 -> V_11 ? : L_2 ,
F_4 ( V_2 -> V_9 , V_5 -> V_12 ) ) ;
F_8 ( & V_5 -> V_17 ) ;
}
if ( V_18 & V_5 -> V_19 )
F_3 ( V_8 , L_5 ) ;
V_5 -> V_19 |= V_15 & V_18 ;
V_5 -> V_11 = V_13 ;
V_5 -> V_12 = V_10 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 ) {
F_3 ( V_8 , L_6 ) ;
return;
}
if ( ! ( V_18 & V_2 -> V_6 -> V_19 ) )
F_3 ( V_8 , L_7 ) ;
V_5 -> V_19 &= ~ V_18 ;
V_5 -> V_11 = NULL ;
V_5 -> V_12 = NULL ;
F_10 ( & V_5 -> V_17 ) ;
}
static void F_11 ( struct V_20 * V_20 , unsigned long V_21 )
{
F_12 ( 0 != ( V_21 & ~ V_22 ) ) ;
F_13 ( V_20 , V_21 ) ;
}
static unsigned long F_14 ( struct V_20 * V_20 )
{
return F_15 ( V_20 ) & V_22 ;
}
static void F_16 ( struct V_1 * V_2 , int V_23 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void * V_24 = & F_15 ( V_5 -> V_25 [ V_23 ] ) ;
F_17 ( V_5 -> V_26 , ! F_18 ( V_27 , V_24 ) ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_23 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void * V_24 = & F_15 ( V_5 -> V_25 [ V_23 ] ) ;
F_20 ( V_27 , V_24 ) ;
F_21 ( & V_2 -> V_6 -> V_26 ) ;
}
static void F_22 ( struct V_20 * V_20 )
{
F_23 ( V_28 , & F_15 ( V_20 ) ) ;
F_23 ( V_29 , & F_15 ( V_20 ) ) ;
}
static void F_24 ( struct V_20 * V_20 )
{
F_25 ( V_28 , & F_15 ( V_20 ) ) ;
}
void F_26 ( struct V_1 * V_2 , int V_23 )
{
struct V_20 * V_20 ;
if ( V_23 >= V_2 -> V_6 -> V_30 ) {
F_7 ( V_8 , L_8 ,
V_23 , ( int ) V_2 -> V_6 -> V_30 ) ;
return;
}
V_20 = V_2 -> V_6 -> V_25 [ V_23 ] ;
F_25 ( V_31 , & F_15 ( V_20 ) ) ;
}
static int F_27 ( struct V_20 * V_20 )
{
volatile const unsigned long * V_24 = & F_15 ( V_20 ) ;
return ( * V_24 & ( ( 1UL << V_28 ) | ( 1UL << V_29 ) ) ) == 0 ;
}
static void F_28 ( struct V_20 * V_20 )
{
F_25 ( V_32 , & F_15 ( V_20 ) ) ;
}
static void F_29 ( struct V_20 * V_20 )
{
F_23 ( V_32 , & F_15 ( V_20 ) ) ;
}
static void F_30 ( struct V_20 * V_20 )
{
F_25 ( V_29 , & F_15 ( V_20 ) ) ;
}
static int F_31 ( struct V_20 * V_20 )
{
return F_32 ( V_29 , & F_15 ( V_20 ) ) ;
}
static unsigned int F_33 ( struct V_4 * V_5 , unsigned long V_33 )
{
unsigned int V_23 = V_33 >> ( V_34 - V_35 + 3 ) ;
F_12 ( V_23 >= V_5 -> V_30 ) ;
return V_23 ;
}
static unsigned int F_34 ( struct V_4 * V_5 , T_1 V_36 )
{
unsigned int V_23 = V_36 >> ( V_34 + 3 ) ;
F_12 ( V_23 >= V_5 -> V_30 ) ;
return V_23 ;
}
static unsigned long * F_35 ( struct V_4 * V_5 , unsigned int V_21 )
{
struct V_20 * V_20 = V_5 -> V_25 [ V_21 ] ;
return ( unsigned long * ) F_36 ( V_20 ) ;
}
static unsigned long * F_37 ( struct V_4 * V_5 , unsigned int V_21 )
{
return F_35 ( V_5 , V_21 ) ;
}
static void F_38 ( unsigned long * V_37 )
{
F_39 ( V_37 ) ;
}
static void F_40 ( unsigned long * V_37 )
{
return F_38 ( V_37 ) ;
}
static void F_41 ( struct V_20 * * V_38 , unsigned long V_39 )
{
unsigned long V_40 ;
if ( ! V_38 )
return;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
if ( ! V_38 [ V_40 ] ) {
F_42 ( V_41 L_9
L_10 ,
V_40 , V_39 ) ;
continue;
}
F_43 ( V_38 [ V_40 ] ) ;
V_38 [ V_40 ] = NULL ;
}
}
static void F_44 ( void * V_42 , int V_43 )
{
if ( V_43 )
F_45 ( V_42 ) ;
else
F_46 ( V_42 ) ;
}
static struct V_20 * * F_47 ( struct V_4 * V_5 , unsigned long V_44 )
{
struct V_20 * * V_45 = V_5 -> V_25 ;
struct V_20 * * V_46 , * V_20 ;
unsigned int V_40 , V_47 , V_48 = 0 ;
unsigned long V_49 = V_5 -> V_30 ;
F_12 ( V_49 == 0 && V_45 != NULL ) ;
F_12 ( V_49 != 0 && V_45 == NULL ) ;
if ( V_49 == V_44 )
return V_45 ;
V_47 = sizeof( struct V_20 * ) * V_44 ;
V_46 = F_48 ( V_47 , V_50 ) ;
if ( ! V_46 ) {
V_46 = F_49 ( V_47 ,
V_50 | V_51 | V_52 ,
V_53 ) ;
if ( ! V_46 )
return NULL ;
V_48 = 1 ;
}
if ( V_44 >= V_49 ) {
for ( V_40 = 0 ; V_40 < V_49 ; V_40 ++ )
V_46 [ V_40 ] = V_45 [ V_40 ] ;
for (; V_40 < V_44 ; V_40 ++ ) {
V_20 = F_50 ( V_50 | V_51 ) ;
if ( ! V_20 ) {
F_41 ( V_46 + V_49 , V_40 - V_49 ) ;
F_44 ( V_46 , V_48 ) ;
return NULL ;
}
F_11 ( V_20 , V_40 ) ;
V_46 [ V_40 ] = V_20 ;
}
} else {
for ( V_40 = 0 ; V_40 < V_44 ; V_40 ++ )
V_46 [ V_40 ] = V_45 [ V_40 ] ;
}
if ( V_48 )
V_5 -> V_19 |= V_54 ;
else
V_5 -> V_19 &= ~ V_54 ;
return V_46 ;
}
int F_51 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_52 ( V_5 != NULL ) ;
V_5 = F_48 ( sizeof( struct V_4 ) , V_55 ) ;
if ( ! V_5 )
return - V_56 ;
F_53 ( & V_5 -> V_57 ) ;
F_54 ( & V_5 -> V_17 ) ;
F_55 ( & V_5 -> V_26 ) ;
V_2 -> V_6 = V_5 ;
return 0 ;
}
T_2 F_56 ( struct V_1 * V_2 )
{
if ( ! F_57 ( V_2 -> V_6 ) )
return 0 ;
return V_2 -> V_6 -> V_58 ;
}
void F_58 ( struct V_1 * V_2 )
{
if ( ! F_57 ( V_2 -> V_6 ) )
return;
F_41 ( V_2 -> V_6 -> V_25 , V_2 -> V_6 -> V_30 ) ;
F_44 ( V_2 -> V_6 -> V_25 , ( V_54 & V_2 -> V_6 -> V_19 ) ) ;
F_46 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
static int F_59 ( struct V_4 * V_5 )
{
unsigned long V_59 ;
unsigned long * V_37 , * V_60 ;
int V_61 ;
int V_62 = 0 ;
V_61 = ( V_5 -> V_63 & V_64 ) ;
V_59 = ( 1UL << ( V_61 & V_65 ) ) - 1 ;
V_59 = F_60 ( V_59 ) ;
V_37 = F_37 ( V_5 , V_5 -> V_30 - 1 ) ;
V_60 = V_37 + ( V_61 / V_66 ) ;
if ( V_59 ) {
V_62 = F_61 ( * V_60 & ~ V_59 ) ;
* V_60 &= V_59 ;
V_60 ++ ;
}
if ( V_66 == 32 && ( ( V_60 - V_37 ) & 1 ) == 1 ) {
V_62 += F_61 ( * V_60 ) ;
* V_60 = 0 ;
}
F_40 ( V_37 ) ;
return V_62 ;
}
static void F_62 ( struct V_4 * V_5 )
{
unsigned long V_59 ;
unsigned long * V_37 , * V_60 ;
int V_61 ;
V_61 = ( V_5 -> V_63 & V_64 ) ;
V_59 = ( 1UL << ( V_61 & V_65 ) ) - 1 ;
V_59 = F_60 ( V_59 ) ;
V_37 = F_37 ( V_5 , V_5 -> V_30 - 1 ) ;
V_60 = V_37 + ( V_61 / V_66 ) ;
if ( V_59 ) {
* V_60 |= ~ V_59 ;
V_60 ++ ;
}
if ( V_66 == 32 && ( ( V_60 - V_37 ) & 1 ) == 1 ) {
* V_60 = ~ 0UL ;
}
F_40 ( V_37 ) ;
}
static unsigned long F_63 ( struct V_4 * V_5 )
{
unsigned long * V_37 ;
unsigned long V_67 = 0 ;
unsigned long V_59 = ( 1UL << ( V_5 -> V_63 & V_65 ) ) - 1 ;
int V_21 , V_40 , V_68 ;
for ( V_21 = 0 ; V_21 < V_5 -> V_30 - 1 ; V_21 ++ ) {
V_37 = F_35 ( V_5 , V_21 ) ;
for ( V_40 = 0 ; V_40 < V_69 ; V_40 ++ )
V_67 += F_61 ( V_37 [ V_40 ] ) ;
F_38 ( V_37 ) ;
F_64 () ;
}
V_68 = ( ( V_5 -> V_63 - 1 ) & V_64 ) >> V_35 ;
V_37 = F_35 ( V_5 , V_21 ) ;
for ( V_40 = 0 ; V_40 < V_68 ; V_40 ++ )
V_67 += F_61 ( V_37 [ V_40 ] ) ;
V_37 [ V_68 ] &= F_60 ( V_59 ) ;
V_67 += F_61 ( V_37 [ V_68 ] ) ;
if ( V_66 == 32 && ( V_68 & 1 ) == 0 )
V_37 [ V_68 + 1 ] = 0 ;
F_38 ( V_37 ) ;
return V_67 ;
}
static void F_65 ( struct V_4 * V_5 , T_3 V_70 , int V_71 , T_3 V_72 )
{
unsigned long * V_37 , * V_60 ;
unsigned int V_21 ;
T_3 V_73 , V_74 ;
V_74 = V_70 + V_72 ;
if ( V_74 > V_5 -> V_75 ) {
F_42 ( V_41 L_11 ) ;
return;
}
while ( V_70 < V_74 ) {
V_73 = F_66 ( T_3 , F_67 ( V_70 + 1 , V_69 ) , V_74 ) - V_70 ;
V_21 = F_33 ( V_5 , V_70 ) ;
V_37 = F_37 ( V_5 , V_21 ) ;
V_60 = V_37 + F_68 ( V_70 ) ;
if ( V_60 + V_73 > V_37 + V_69 ) {
F_42 ( V_41 L_12 ,
V_37 , V_60 , ( int ) V_73 ) ;
} else
memset ( V_60 , V_71 , V_73 * sizeof( long ) ) ;
F_40 ( V_37 ) ;
F_24 ( V_5 -> V_25 [ V_21 ] ) ;
V_70 += V_73 ;
}
}
int F_69 ( struct V_1 * V_2 , T_2 V_76 , int V_77 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_67 , V_78 , V_79 , V_80 ;
unsigned long V_44 , V_49 , V_81 ;
struct V_20 * * V_82 , * * V_83 = NULL ;
int V_84 = 0 , V_85 ;
int V_86 ;
if ( ! F_57 ( V_5 ) )
return - V_56 ;
F_5 ( V_2 , L_13 , V_18 ) ;
F_70 ( V_8 , L_14 ,
( unsigned long long ) V_76 ) ;
if ( V_76 == V_5 -> V_58 )
goto V_87;
V_86 = ( V_54 & V_5 -> V_19 ) ;
if ( V_76 == 0 ) {
F_71 ( & V_5 -> V_57 ) ;
V_83 = V_5 -> V_25 ;
V_81 = V_5 -> V_30 ;
V_79 = V_5 -> V_75 ;
V_5 -> V_25 = NULL ;
V_5 -> V_30 =
V_5 -> V_88 =
V_5 -> V_63 =
V_5 -> V_75 =
V_5 -> V_58 = 0 ;
F_72 ( & V_5 -> V_57 ) ;
F_41 ( V_83 , V_81 ) ;
F_44 ( V_83 , V_86 ) ;
goto V_87;
}
V_67 = F_73 ( F_67 ( V_76 , V_89 ) ) ;
V_78 = F_67 ( V_67 , 64 ) >> V_35 ;
if ( F_74 ( V_2 ) ) {
T_1 V_90 = ( ( T_1 ) V_2 -> V_91 -> V_92 . V_93 - V_94 ) << 12 ;
F_75 ( V_2 ) ;
if ( V_67 > V_90 ) {
F_70 ( V_8 , L_15 , V_67 ) ;
F_70 ( V_8 , L_16 , V_90 ) ;
V_84 = - V_95 ;
goto V_87;
}
}
V_44 = F_67 ( V_78 * sizeof( long ) , V_96 ) >> V_34 ;
V_49 = V_5 -> V_30 ;
if ( V_44 == V_49 ) {
F_76 ( V_5 -> V_25 != NULL ) ;
V_82 = V_5 -> V_25 ;
} else {
if ( F_77 ( V_2 , V_97 ) )
V_82 = NULL ;
else
V_82 = F_47 ( V_5 , V_44 ) ;
}
if ( ! V_82 ) {
V_84 = - V_56 ;
goto V_87;
}
F_71 ( & V_5 -> V_57 ) ;
V_83 = V_5 -> V_25 ;
V_79 = V_5 -> V_75 ;
V_80 = V_5 -> V_63 ;
V_85 = V_67 > V_80 ;
if ( V_83 && V_85 && V_77 )
F_62 ( V_5 ) ;
V_5 -> V_25 = V_82 ;
V_5 -> V_30 = V_44 ;
V_5 -> V_63 = V_67 ;
V_5 -> V_75 = V_78 ;
V_5 -> V_58 = V_76 ;
if ( V_85 ) {
if ( V_77 ) {
F_65 ( V_5 , V_79 , 0xff , V_78 - V_79 ) ;
V_5 -> V_88 += V_67 - V_80 ;
} else
F_65 ( V_5 , V_79 , 0x00 , V_78 - V_79 ) ;
}
if ( V_44 < V_49 ) {
F_41 ( V_83 + V_44 , V_49 - V_44 ) ;
}
( void ) F_59 ( V_5 ) ;
F_72 ( & V_5 -> V_57 ) ;
if ( V_83 != V_82 )
F_44 ( V_83 , V_86 ) ;
if ( ! V_85 )
V_5 -> V_88 = F_63 ( V_5 ) ;
F_70 ( V_8 , L_17 , V_67 , V_78 , V_44 ) ;
V_87:
F_9 ( V_2 ) ;
return V_84 ;
}
unsigned long F_78 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_98 ;
unsigned long V_15 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
if ( ! F_57 ( V_5 -> V_25 ) )
return 0 ;
F_79 ( & V_5 -> V_57 , V_15 ) ;
V_98 = V_5 -> V_88 ;
F_80 ( & V_5 -> V_57 , V_15 ) ;
return V_98 ;
}
unsigned long F_81 ( struct V_1 * V_2 )
{
unsigned long V_98 ;
if ( ! F_82 ( V_2 , V_99 ) )
return 0 ;
V_98 = F_78 ( V_2 ) ;
F_75 ( V_2 ) ;
return V_98 ;
}
T_3 F_83 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
if ( ! F_57 ( V_5 -> V_25 ) )
return 0 ;
return V_5 -> V_75 ;
}
unsigned long F_84 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
return V_5 -> V_63 ;
}
void F_85 ( struct V_1 * V_2 , T_3 V_70 , T_3 V_39 ,
unsigned long * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_37 , * V_60 ;
unsigned long V_101 , V_67 ;
unsigned int V_21 ;
T_3 V_74 , V_73 ;
V_74 = V_70 + V_39 ;
if ( ! F_57 ( V_5 ) )
return;
if ( ! F_57 ( V_5 -> V_25 ) )
return;
if ( V_39 == 0 )
return;
F_52 ( V_70 >= V_5 -> V_75 ) ;
F_52 ( V_74 > V_5 -> V_75 ) ;
F_71 ( & V_5 -> V_57 ) ;
while ( V_70 < V_74 ) {
V_73 = F_66 ( T_3 , F_67 ( V_70 + 1 , V_69 ) , V_74 ) - V_70 ;
V_21 = F_33 ( V_5 , V_70 ) ;
V_37 = F_37 ( V_5 , V_21 ) ;
V_60 = V_37 + F_68 ( V_70 ) ;
V_70 += V_73 ;
while ( V_73 -- ) {
V_67 = F_61 ( * V_60 ) ;
V_101 = * V_60 | * V_100 ++ ;
* V_60 ++ = V_101 ;
V_5 -> V_88 += F_61 ( V_101 ) - V_67 ;
}
F_40 ( V_37 ) ;
F_24 ( V_5 -> V_25 [ V_21 ] ) ;
}
if ( V_74 == V_5 -> V_75 )
V_5 -> V_88 -= F_59 ( V_5 ) ;
F_72 ( & V_5 -> V_57 ) ;
}
void F_86 ( struct V_1 * V_2 , T_3 V_70 , T_3 V_39 ,
unsigned long * V_100 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_37 , * V_60 ;
T_3 V_74 , V_73 ;
V_74 = V_70 + V_39 ;
if ( ! F_57 ( V_5 ) )
return;
if ( ! F_57 ( V_5 -> V_25 ) )
return;
F_71 ( & V_5 -> V_57 ) ;
if ( ( V_70 >= V_5 -> V_75 ) ||
( V_74 > V_5 -> V_75 ) ||
( V_39 <= 0 ) )
F_3 ( V_8 , L_18 ,
( unsigned long ) V_70 ,
( unsigned long ) V_39 ,
( unsigned long ) V_5 -> V_75 ) ;
else {
while ( V_70 < V_74 ) {
V_73 = F_66 ( T_3 , F_67 ( V_70 + 1 , V_69 ) , V_74 ) - V_70 ;
V_37 = F_37 ( V_5 , F_33 ( V_5 , V_70 ) ) ;
V_60 = V_37 + F_68 ( V_70 ) ;
V_70 += V_73 ;
while ( V_73 -- )
* V_100 ++ = * V_60 ++ ;
F_40 ( V_37 ) ;
}
}
F_72 ( & V_5 -> V_57 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_57 ( V_5 ) )
return;
if ( ! F_57 ( V_5 -> V_25 ) )
return;
F_71 ( & V_5 -> V_57 ) ;
F_65 ( V_5 , 0 , 0xff , V_5 -> V_75 ) ;
( void ) F_59 ( V_5 ) ;
V_5 -> V_88 = V_5 -> V_63 ;
F_72 ( & V_5 -> V_57 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_57 ( V_5 ) )
return;
if ( ! F_57 ( V_5 -> V_25 ) )
return;
F_71 ( & V_5 -> V_57 ) ;
F_65 ( V_5 , 0 , 0 , V_5 -> V_75 ) ;
V_5 -> V_88 = 0 ;
F_72 ( & V_5 -> V_57 ) ;
}
static void F_89 ( struct V_102 * V_102 )
{
struct V_103 * V_104 = F_90 ( V_102 , struct V_103 , V_102 ) ;
F_75 ( V_104 -> V_2 ) ;
F_46 ( V_104 ) ;
}
static void F_91 ( struct V_105 * V_105 , int error )
{
struct V_103 * V_104 = V_105 -> V_106 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_21 = F_14 ( V_105 -> V_107 [ 0 ] . V_108 ) ;
int V_109 = F_92 ( V_105 , V_110 ) ;
if ( ! error && ! V_109 )
error = - V_111 ;
if ( ( V_104 -> V_15 & V_112 ) == 0 &&
! F_27 ( V_5 -> V_25 [ V_21 ] ) )
F_7 ( V_8 , L_19 , V_21 ) ;
if ( error ) {
V_104 -> error = error ;
F_28 ( V_5 -> V_25 [ V_21 ] ) ;
if ( F_2 ( & V_7 ) )
F_3 ( V_8 , L_20 ,
error , V_21 ) ;
} else {
F_29 ( V_5 -> V_25 [ V_21 ] ) ;
F_93 ( V_8 , L_21 , V_21 ) ;
}
F_19 ( V_2 , V_21 ) ;
if ( V_104 -> V_15 & V_112 )
F_94 ( V_105 -> V_107 [ 0 ] . V_108 , V_113 ) ;
F_95 ( V_105 ) ;
if ( F_96 ( & V_104 -> V_114 ) ) {
V_104 -> V_115 = 1 ;
F_21 ( & V_2 -> V_116 ) ;
F_97 ( & V_104 -> V_102 , & F_89 ) ;
}
}
static void F_98 ( struct V_103 * V_104 , int V_23 , int V_117 ) __must_hold( T_4 )
{
struct V_105 * V_105 = F_99 ( V_50 ) ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_20 * V_20 ;
unsigned int V_72 ;
T_2 V_118 =
V_2 -> V_91 -> V_92 . V_119 + V_2 -> V_91 -> V_92 . V_120 ;
V_118 += ( ( T_2 ) V_23 ) << ( V_34 - 9 ) ;
V_72 = F_66 (unsigned int, PAGE_SIZE,
(drbd_md_last_sector(mdev->ldev) - on_disk_sector + 1)<<9 ) ;
F_16 ( V_2 , V_23 ) ;
F_22 ( V_5 -> V_25 [ V_23 ] ) ;
if ( V_104 -> V_15 & V_112 ) {
V_20 = F_100 ( V_113 , V_51 | V_121 ) ;
F_101 ( V_20 , V_5 -> V_25 [ V_23 ] ) ;
F_11 ( V_20 , V_23 ) ;
} else
V_20 = V_5 -> V_25 [ V_23 ] ;
V_105 -> V_122 = V_2 -> V_91 -> V_123 ;
V_105 -> V_124 = V_118 ;
F_102 ( V_105 , V_20 , V_72 , 0 ) ;
V_105 -> V_106 = V_104 ;
V_105 -> V_125 = F_91 ;
if ( F_77 ( V_2 , ( V_117 & V_126 ) ? V_127 : V_128 ) ) {
V_105 -> V_129 |= V_117 ;
F_103 ( V_105 , - V_111 ) ;
} else {
F_104 ( V_117 , V_105 ) ;
F_105 ( V_72 >> 9 , & V_2 -> V_130 ) ;
}
}
static int F_106 ( struct V_1 * V_2 , int V_117 , unsigned V_15 , unsigned V_131 ) __must_hold( T_4 )
{
struct V_103 * V_104 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_132 , V_40 , V_133 = 0 ;
unsigned long V_134 ;
char V_135 [ 10 ] ;
int V_84 = 0 ;
V_104 = F_107 ( sizeof( struct V_103 ) , V_50 ) ;
if ( ! V_104 )
return - V_56 ;
* V_104 = (struct V_103 ) {
. V_2 = V_2 ,
. V_114 = F_108 ( 1 ) ,
. V_115 = 0 ,
. V_15 = V_15 ,
. error = 0 ,
. V_102 = { F_108 ( 2 ) } ,
} ;
if ( ! F_82 ( V_2 , V_136 ) ) {
F_3 ( V_8 , L_22 ) ;
F_46 ( V_104 ) ;
return - V_137 ;
}
if ( ! V_104 -> V_15 )
F_52 ( ! ( V_18 & V_5 -> V_19 ) ) ;
V_132 = V_5 -> V_30 ;
V_134 = V_138 ;
for ( V_40 = 0 ; V_40 < V_132 ; V_40 ++ ) {
if ( V_131 && V_40 == V_131 )
break;
if ( V_117 & V_126 ) {
if ( ( V_15 & V_139 ) &&
! F_109 ( V_31 ,
& F_15 ( V_5 -> V_25 [ V_40 ] ) ) )
continue;
if ( ! ( V_15 & V_140 ) &&
F_27 ( V_5 -> V_25 [ V_40 ] ) ) {
F_93 ( V_8 , L_23 , V_40 ) ;
continue;
}
if ( V_131 &&
! F_31 ( V_5 -> V_25 [ V_40 ] ) ) {
F_93 ( V_8 , L_24 , V_40 ) ;
continue;
}
}
F_110 ( & V_104 -> V_114 ) ;
F_98 ( V_104 , V_40 , V_117 ) ;
++ V_133 ;
F_64 () ;
}
if ( ! F_96 ( & V_104 -> V_114 ) )
F_111 ( V_2 , V_2 -> V_91 , & V_104 -> V_115 ) ;
else
F_97 ( & V_104 -> V_102 , & F_89 ) ;
if ( V_15 == 0 )
F_70 ( V_8 , L_25 ,
V_117 == V_126 ? L_26 : L_27 ,
V_133 , V_138 - V_134 ) ;
if ( V_104 -> error ) {
F_112 ( V_8 , L_28 ) ;
F_113 ( V_2 , 1 , V_141 ) ;
V_84 = - V_111 ;
}
if ( F_114 ( & V_104 -> V_114 ) )
V_84 = - V_111 ;
V_134 = V_138 ;
if ( V_117 == V_126 ) {
F_115 ( V_2 ) ;
} else {
V_5 -> V_88 = F_63 ( V_5 ) ;
F_70 ( V_8 , L_29 ,
V_138 - V_134 ) ;
}
V_134 = V_5 -> V_88 ;
if ( V_15 == 0 )
F_70 ( V_8 , L_30 ,
F_116 ( V_135 , V_134 << ( V_142 - 10 ) ) , V_134 ) ;
F_97 ( & V_104 -> V_102 , & F_89 ) ;
return V_84 ;
}
int F_117 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_106 ( V_2 , V_143 , 0 , 0 ) ;
}
int F_118 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_106 ( V_2 , V_126 , 0 , 0 ) ;
}
int F_119 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_106 ( V_2 , V_126 , V_140 , 0 ) ;
}
int F_120 ( struct V_1 * V_2 , unsigned V_144 ) __must_hold( T_4 )
{
return F_106 ( V_2 , V_126 , V_112 , V_144 ) ;
}
int F_121 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_106 ( V_2 , V_126 , V_112 , 0 ) ;
}
int F_122 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_106 ( V_2 , V_126 , V_139 | V_112 , 0 ) ;
}
int F_123 ( struct V_1 * V_2 , unsigned int V_21 ) __must_hold( T_4 )
{
struct V_103 * V_104 ;
int V_84 ;
if ( F_27 ( V_2 -> V_6 -> V_25 [ V_21 ] ) ) {
F_93 ( V_8 , L_31 , V_21 ) ;
return 0 ;
}
V_104 = F_107 ( sizeof( struct V_103 ) , V_50 ) ;
if ( ! V_104 )
return - V_56 ;
* V_104 = (struct V_103 ) {
. V_2 = V_2 ,
. V_114 = F_108 ( 1 ) ,
. V_115 = 0 ,
. V_15 = V_112 ,
. error = 0 ,
. V_102 = { F_108 ( 2 ) } ,
} ;
if ( ! F_82 ( V_2 , V_136 ) ) {
F_3 ( V_8 , L_32 ) ;
F_46 ( V_104 ) ;
return - V_137 ;
}
F_98 ( V_104 , V_21 , V_145 ) ;
F_111 ( V_2 , V_2 -> V_91 , & V_104 -> V_115 ) ;
if ( V_104 -> error )
F_113 ( V_2 , 1 , V_141 ) ;
V_2 -> V_146 ++ ;
V_84 = F_114 ( & V_104 -> V_114 ) ? - V_111 : V_104 -> error ;
F_97 ( & V_104 -> V_102 , & F_89 ) ;
return V_84 ;
}
static unsigned long F_124 ( struct V_1 * V_2 , unsigned long V_147 ,
const int V_148 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_37 ;
unsigned long V_149 ;
unsigned V_40 ;
if ( V_147 > V_5 -> V_63 ) {
F_3 ( V_8 , L_33 , V_147 , V_5 -> V_63 ) ;
V_147 = V_150 ;
} else {
while ( V_147 < V_5 -> V_63 ) {
V_149 = V_147 & ~ V_64 ;
V_37 = F_35 ( V_5 , F_34 ( V_5 , V_147 ) ) ;
if ( V_148 )
V_40 = F_125 ( V_37 ,
V_96 * 8 , V_147 & V_64 ) ;
else
V_40 = F_126 ( V_37 ,
V_96 * 8 , V_147 & V_64 ) ;
F_38 ( V_37 ) ;
if ( V_40 < V_96 * 8 ) {
V_147 = V_149 + V_40 ;
if ( V_147 >= V_5 -> V_63 )
break;
goto V_151;
}
V_147 = V_149 + V_96 * 8 ;
}
V_147 = V_150 ;
}
V_151:
return V_147 ;
}
static unsigned long F_127 ( struct V_1 * V_2 ,
unsigned long V_147 , const int V_148 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_40 = V_150 ;
if ( ! F_57 ( V_5 ) )
return V_40 ;
if ( ! F_57 ( V_5 -> V_25 ) )
return V_40 ;
F_71 ( & V_5 -> V_57 ) ;
if ( V_152 & V_5 -> V_19 )
F_128 ( V_2 ) ;
V_40 = F_124 ( V_2 , V_147 , V_148 ) ;
F_72 ( & V_5 -> V_57 ) ;
return V_40 ;
}
unsigned long F_129 ( struct V_1 * V_2 , unsigned long V_147 )
{
return F_127 ( V_2 , V_147 , 0 ) ;
}
unsigned long F_130 ( struct V_1 * V_2 , unsigned long V_147 )
{
return F_124 ( V_2 , V_147 , 0 ) ;
}
unsigned long F_131 ( struct V_1 * V_2 , unsigned long V_147 )
{
return F_124 ( V_2 , V_147 , 1 ) ;
}
static int F_132 ( struct V_1 * V_2 , const unsigned long V_98 ,
unsigned long V_153 , int V_154 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_37 = NULL ;
unsigned long V_36 ;
unsigned int V_155 = - 1U ;
int V_71 = 0 ;
int V_156 = 0 ;
if ( V_153 >= V_5 -> V_63 ) {
F_3 ( V_8 , L_34 ,
V_98 , V_153 , V_5 -> V_63 ) ;
V_153 = V_5 -> V_63 ? V_5 -> V_63 - 1 : 0 ;
}
for ( V_36 = V_98 ; V_36 <= V_153 ; V_36 ++ ) {
unsigned int V_23 = F_34 ( V_5 , V_36 ) ;
if ( V_23 != V_155 ) {
if ( V_37 )
F_38 ( V_37 ) ;
if ( V_71 < 0 )
F_30 ( V_5 -> V_25 [ V_155 ] ) ;
else if ( V_71 > 0 )
F_24 ( V_5 -> V_25 [ V_155 ] ) ;
V_156 += V_71 ;
V_71 = 0 ;
V_37 = F_35 ( V_5 , V_23 ) ;
V_155 = V_23 ;
}
if ( V_154 )
V_71 += ( 0 == F_133 ( V_36 & V_64 , V_37 ) ) ;
else
V_71 -= ( 0 != F_134 ( V_36 & V_64 , V_37 ) ) ;
}
if ( V_37 )
F_38 ( V_37 ) ;
if ( V_71 < 0 )
F_30 ( V_5 -> V_25 [ V_155 ] ) ;
else if ( V_71 > 0 )
F_24 ( V_5 -> V_25 [ V_155 ] ) ;
V_156 += V_71 ;
V_5 -> V_88 += V_156 ;
return V_156 ;
}
static int F_135 ( struct V_1 * V_2 , const unsigned long V_98 ,
const unsigned long V_153 , int V_154 )
{
unsigned long V_15 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_71 = 0 ;
if ( ! F_57 ( V_5 ) )
return 1 ;
if ( ! F_57 ( V_5 -> V_25 ) )
return 0 ;
F_79 ( & V_5 -> V_57 , V_15 ) ;
if ( ( V_154 ? V_157 : V_158 ) & V_5 -> V_19 )
F_128 ( V_2 ) ;
V_71 = F_132 ( V_2 , V_98 , V_153 , V_154 ) ;
F_80 ( & V_5 -> V_57 , V_15 ) ;
return V_71 ;
}
int F_136 ( struct V_1 * V_2 , const unsigned long V_98 , const unsigned long V_153 )
{
return F_135 ( V_2 , V_98 , V_153 , 1 ) ;
}
int F_137 ( struct V_1 * V_2 , const unsigned long V_98 , const unsigned long V_153 )
{
return - F_135 ( V_2 , V_98 , V_153 , 0 ) ;
}
static inline void F_138 ( struct V_4 * V_5 ,
int V_23 , int V_159 , int V_68 )
{
int V_40 ;
int V_67 ;
int V_160 = 0 ;
unsigned long * V_161 = F_36 ( V_5 -> V_25 [ V_23 ] ) ;
for ( V_40 = V_159 ; V_40 < V_68 ; V_40 ++ ) {
V_67 = F_61 ( V_161 [ V_40 ] ) ;
V_161 [ V_40 ] = ~ 0UL ;
V_160 += V_66 - V_67 ;
}
F_39 ( V_161 ) ;
if ( V_160 ) {
F_30 ( V_5 -> V_25 [ V_23 ] ) ;
V_5 -> V_88 += V_160 ;
}
}
void F_139 ( struct V_1 * V_2 , const unsigned long V_98 , const unsigned long V_153 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_162 = F_67 ( V_98 , V_66 ) ;
unsigned long V_163 = ( V_153 + 1 ) & ~ ( ( unsigned long ) V_66 - 1 ) ;
int V_164 ;
int V_165 ;
int V_23 ;
int V_159 ;
int V_68 ;
if ( V_153 - V_98 <= 3 * V_66 ) {
F_71 ( & V_5 -> V_57 ) ;
F_132 ( V_2 , V_98 , V_153 , 1 ) ;
F_72 ( & V_5 -> V_57 ) ;
return;
}
F_71 ( & V_5 -> V_57 ) ;
if ( V_162 )
F_132 ( V_2 , V_98 , V_162 - 1 , 1 ) ;
V_164 = V_162 >> ( 3 + V_34 ) ;
V_165 = V_163 >> ( 3 + V_34 ) ;
V_159 = F_68 ( V_162 >> V_35 ) ;
V_68 = V_69 ;
for ( V_23 = V_164 ; V_23 < V_165 ; V_23 ++ ) {
F_138 ( V_2 -> V_6 , V_23 , V_159 , V_68 ) ;
F_72 ( & V_5 -> V_57 ) ;
F_64 () ;
V_159 = 0 ;
F_71 ( & V_5 -> V_57 ) ;
}
V_68 = F_68 ( V_163 >> V_35 ) ;
if ( V_68 )
F_138 ( V_2 -> V_6 , V_165 , V_159 , V_68 ) ;
if ( V_163 <= V_153 )
F_132 ( V_2 , V_163 , V_153 , 1 ) ;
F_72 ( & V_5 -> V_57 ) ;
}
int F_140 ( struct V_1 * V_2 , const unsigned long V_36 )
{
unsigned long V_15 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_37 ;
int V_40 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
if ( ! F_57 ( V_5 -> V_25 ) )
return 0 ;
F_79 ( & V_5 -> V_57 , V_15 ) ;
if ( V_152 & V_5 -> V_19 )
F_128 ( V_2 ) ;
if ( V_36 < V_5 -> V_63 ) {
V_37 = F_37 ( V_5 , F_34 ( V_5 , V_36 ) ) ;
V_40 = F_141 ( V_36 & V_64 , V_37 ) ? 1 : 0 ;
F_40 ( V_37 ) ;
} else if ( V_36 == V_5 -> V_63 ) {
V_40 = - 1 ;
} else {
F_3 ( V_8 , L_35 , V_36 , V_5 -> V_63 ) ;
V_40 = 0 ;
}
F_80 ( & V_5 -> V_57 , V_15 ) ;
return V_40 ;
}
int F_142 ( struct V_1 * V_2 , const unsigned long V_98 , const unsigned long V_153 )
{
unsigned long V_15 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_37 = NULL ;
unsigned long V_36 ;
unsigned int V_23 = - 1U ;
int V_71 = 0 ;
if ( ! F_57 ( V_5 ) )
return 1 ;
if ( ! F_57 ( V_5 -> V_25 ) )
return 1 ;
F_79 ( & V_5 -> V_57 , V_15 ) ;
if ( V_152 & V_5 -> V_19 )
F_128 ( V_2 ) ;
for ( V_36 = V_98 ; V_36 <= V_153 ; V_36 ++ ) {
unsigned int V_21 = F_34 ( V_5 , V_36 ) ;
if ( V_23 != V_21 ) {
V_23 = V_21 ;
if ( V_37 )
F_40 ( V_37 ) ;
V_37 = F_37 ( V_5 , V_21 ) ;
}
if ( F_57 ( V_36 < V_5 -> V_63 ) )
V_71 += ( 0 != F_141 ( V_36 - ( V_23 << ( V_34 + 3 ) ) , V_37 ) ) ;
else
F_3 ( V_8 , L_36 , V_36 , V_5 -> V_63 ) ;
}
if ( V_37 )
F_40 ( V_37 ) ;
F_80 ( & V_5 -> V_57 , V_15 ) ;
return V_71 ;
}
int F_143 ( struct V_1 * V_2 , unsigned long V_166 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_133 , V_98 , V_153 ;
unsigned long V_15 ;
unsigned long * V_37 , * V_60 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
if ( ! F_57 ( V_5 -> V_25 ) )
return 0 ;
F_79 ( & V_5 -> V_57 , V_15 ) ;
if ( V_152 & V_5 -> V_19 )
F_128 ( V_2 ) ;
V_98 = F_144 ( V_166 ) ;
V_153 = F_145 ( ( T_3 ) F_144 ( V_166 + 1 ) , V_5 -> V_75 ) ;
V_133 = 0 ;
if ( V_98 < V_5 -> V_75 ) {
int V_167 = V_153 - V_98 ;
V_37 = F_37 ( V_5 , F_33 ( V_5 , V_98 ) ) ;
V_60 = V_37 + F_68 ( V_98 ) ;
while ( V_167 -- )
V_133 += F_61 ( * V_60 ++ ) ;
F_40 ( V_37 ) ;
} else {
F_3 ( V_8 , L_37 , V_98 ) ;
}
F_80 ( & V_5 -> V_57 , V_15 ) ;
return V_133 ;
}
