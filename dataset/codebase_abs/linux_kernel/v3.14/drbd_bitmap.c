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
V_46 = F_48 ( V_47 , V_50 | V_51 ) ;
if ( ! V_46 ) {
V_46 = F_49 ( V_47 ,
V_50 | V_52 | V_53 ,
V_54 ) ;
if ( ! V_46 )
return NULL ;
V_48 = 1 ;
}
if ( V_44 >= V_49 ) {
for ( V_40 = 0 ; V_40 < V_49 ; V_40 ++ )
V_46 [ V_40 ] = V_45 [ V_40 ] ;
for (; V_40 < V_44 ; V_40 ++ ) {
V_20 = F_50 ( V_50 | V_52 ) ;
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
V_5 -> V_19 |= V_55 ;
else
V_5 -> V_19 &= ~ V_55 ;
return V_46 ;
}
int F_51 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_52 ( V_5 != NULL ) ;
V_5 = F_48 ( sizeof( struct V_4 ) , V_56 ) ;
if ( ! V_5 )
return - V_57 ;
F_53 ( & V_5 -> V_58 ) ;
F_54 ( & V_5 -> V_17 ) ;
F_55 ( & V_5 -> V_26 ) ;
V_2 -> V_6 = V_5 ;
return 0 ;
}
T_2 F_56 ( struct V_1 * V_2 )
{
if ( ! F_57 ( V_2 -> V_6 ) )
return 0 ;
return V_2 -> V_6 -> V_59 ;
}
void F_58 ( struct V_1 * V_2 )
{
if ( ! F_57 ( V_2 -> V_6 ) )
return;
F_41 ( V_2 -> V_6 -> V_25 , V_2 -> V_6 -> V_30 ) ;
F_44 ( V_2 -> V_6 -> V_25 , ( V_55 & V_2 -> V_6 -> V_19 ) ) ;
F_46 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
static int F_59 ( struct V_4 * V_5 )
{
unsigned long V_60 ;
unsigned long * V_37 , * V_61 ;
int V_62 ;
int V_63 = 0 ;
V_62 = ( V_5 -> V_64 & V_65 ) ;
V_60 = ( 1UL << ( V_62 & V_66 ) ) - 1 ;
V_60 = F_60 ( V_60 ) ;
V_37 = F_37 ( V_5 , V_5 -> V_30 - 1 ) ;
V_61 = V_37 + ( V_62 / V_67 ) ;
if ( V_60 ) {
V_63 = F_61 ( * V_61 & ~ V_60 ) ;
* V_61 &= V_60 ;
V_61 ++ ;
}
if ( V_67 == 32 && ( ( V_61 - V_37 ) & 1 ) == 1 ) {
V_63 += F_61 ( * V_61 ) ;
* V_61 = 0 ;
}
F_40 ( V_37 ) ;
return V_63 ;
}
static void F_62 ( struct V_4 * V_5 )
{
unsigned long V_60 ;
unsigned long * V_37 , * V_61 ;
int V_62 ;
V_62 = ( V_5 -> V_64 & V_65 ) ;
V_60 = ( 1UL << ( V_62 & V_66 ) ) - 1 ;
V_60 = F_60 ( V_60 ) ;
V_37 = F_37 ( V_5 , V_5 -> V_30 - 1 ) ;
V_61 = V_37 + ( V_62 / V_67 ) ;
if ( V_60 ) {
* V_61 |= ~ V_60 ;
V_61 ++ ;
}
if ( V_67 == 32 && ( ( V_61 - V_37 ) & 1 ) == 1 ) {
* V_61 = ~ 0UL ;
}
F_40 ( V_37 ) ;
}
static unsigned long F_63 ( struct V_4 * V_5 )
{
unsigned long * V_37 ;
unsigned long V_68 = 0 ;
unsigned long V_60 = ( 1UL << ( V_5 -> V_64 & V_66 ) ) - 1 ;
int V_21 , V_40 , V_69 ;
for ( V_21 = 0 ; V_21 < V_5 -> V_30 - 1 ; V_21 ++ ) {
V_37 = F_35 ( V_5 , V_21 ) ;
for ( V_40 = 0 ; V_40 < V_70 ; V_40 ++ )
V_68 += F_61 ( V_37 [ V_40 ] ) ;
F_38 ( V_37 ) ;
F_64 () ;
}
V_69 = ( ( V_5 -> V_64 - 1 ) & V_65 ) >> V_35 ;
V_37 = F_35 ( V_5 , V_21 ) ;
for ( V_40 = 0 ; V_40 < V_69 ; V_40 ++ )
V_68 += F_61 ( V_37 [ V_40 ] ) ;
V_37 [ V_69 ] &= F_60 ( V_60 ) ;
V_68 += F_61 ( V_37 [ V_69 ] ) ;
if ( V_67 == 32 && ( V_69 & 1 ) == 0 )
V_37 [ V_69 + 1 ] = 0 ;
F_38 ( V_37 ) ;
return V_68 ;
}
static void F_65 ( struct V_4 * V_5 , T_3 V_71 , int V_72 , T_3 V_73 )
{
unsigned long * V_37 , * V_61 ;
unsigned int V_21 ;
T_3 V_74 , V_75 ;
V_75 = V_71 + V_73 ;
if ( V_75 > V_5 -> V_76 ) {
F_42 ( V_41 L_11 ) ;
return;
}
while ( V_71 < V_75 ) {
V_74 = F_66 ( T_3 , F_67 ( V_71 + 1 , V_70 ) , V_75 ) - V_71 ;
V_21 = F_33 ( V_5 , V_71 ) ;
V_37 = F_37 ( V_5 , V_21 ) ;
V_61 = V_37 + F_68 ( V_71 ) ;
if ( V_61 + V_74 > V_37 + V_70 ) {
F_42 ( V_41 L_12 ,
V_37 , V_61 , ( int ) V_74 ) ;
} else
memset ( V_61 , V_72 , V_74 * sizeof( long ) ) ;
F_40 ( V_37 ) ;
F_24 ( V_5 -> V_25 [ V_21 ] ) ;
V_71 += V_74 ;
}
}
static T_1 F_69 ( struct V_77 * V_78 )
{
T_1 V_79 ;
if ( V_78 -> V_80 . V_81 == 8 )
V_79 = V_78 -> V_80 . V_82 - V_78 -> V_80 . V_83 ;
else
V_79 = V_78 -> V_80 . V_81 - V_78 -> V_80 . V_83 ;
return V_79 << ( 9 + 3 ) ;
}
int F_70 ( struct V_1 * V_2 , T_2 V_84 , int V_85 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_68 , V_86 , V_87 , V_88 ;
unsigned long V_44 , V_49 , V_89 ;
struct V_20 * * V_90 , * * V_91 = NULL ;
int V_92 = 0 , V_93 ;
int V_94 ;
if ( ! F_57 ( V_5 ) )
return - V_57 ;
F_5 ( V_2 , L_13 , V_18 ) ;
F_71 ( V_8 , L_14 ,
( unsigned long long ) V_84 ) ;
if ( V_84 == V_5 -> V_59 )
goto V_95;
V_94 = ( V_55 & V_5 -> V_19 ) ;
if ( V_84 == 0 ) {
F_72 ( & V_5 -> V_58 ) ;
V_91 = V_5 -> V_25 ;
V_89 = V_5 -> V_30 ;
V_87 = V_5 -> V_76 ;
V_5 -> V_25 = NULL ;
V_5 -> V_30 =
V_5 -> V_96 =
V_5 -> V_64 =
V_5 -> V_76 =
V_5 -> V_59 = 0 ;
F_73 ( & V_5 -> V_58 ) ;
F_41 ( V_91 , V_89 ) ;
F_44 ( V_91 , V_94 ) ;
goto V_95;
}
V_68 = F_74 ( F_67 ( V_84 , V_97 ) ) ;
V_86 = F_67 ( V_68 , 64 ) >> V_35 ;
if ( F_75 ( V_2 ) ) {
T_1 V_98 = F_69 ( V_2 -> V_78 ) ;
F_76 ( V_2 ) ;
if ( V_68 > V_98 ) {
F_71 ( V_8 , L_15 , V_68 ) ;
F_71 ( V_8 , L_16 , V_98 ) ;
V_92 = - V_99 ;
goto V_95;
}
}
V_44 = F_67 ( V_86 * sizeof( long ) , V_100 ) >> V_34 ;
V_49 = V_5 -> V_30 ;
if ( V_44 == V_49 ) {
F_77 ( V_5 -> V_25 != NULL ) ;
V_90 = V_5 -> V_25 ;
} else {
if ( F_78 ( V_2 , V_101 ) )
V_90 = NULL ;
else
V_90 = F_47 ( V_5 , V_44 ) ;
}
if ( ! V_90 ) {
V_92 = - V_57 ;
goto V_95;
}
F_72 ( & V_5 -> V_58 ) ;
V_91 = V_5 -> V_25 ;
V_87 = V_5 -> V_76 ;
V_88 = V_5 -> V_64 ;
V_93 = V_68 > V_88 ;
if ( V_91 && V_93 && V_85 )
F_62 ( V_5 ) ;
V_5 -> V_25 = V_90 ;
V_5 -> V_30 = V_44 ;
V_5 -> V_64 = V_68 ;
V_5 -> V_76 = V_86 ;
V_5 -> V_59 = V_84 ;
if ( V_93 ) {
if ( V_85 ) {
F_65 ( V_5 , V_87 , 0xff , V_86 - V_87 ) ;
V_5 -> V_96 += V_68 - V_88 ;
} else
F_65 ( V_5 , V_87 , 0x00 , V_86 - V_87 ) ;
}
if ( V_44 < V_49 ) {
F_41 ( V_91 + V_44 , V_49 - V_44 ) ;
}
( void ) F_59 ( V_5 ) ;
F_73 ( & V_5 -> V_58 ) ;
if ( V_91 != V_90 )
F_44 ( V_91 , V_94 ) ;
if ( ! V_93 )
V_5 -> V_96 = F_63 ( V_5 ) ;
F_71 ( V_8 , L_17 , V_68 , V_86 , V_44 ) ;
V_95:
F_9 ( V_2 ) ;
return V_92 ;
}
unsigned long F_79 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_102 ;
unsigned long V_15 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
if ( ! F_57 ( V_5 -> V_25 ) )
return 0 ;
F_80 ( & V_5 -> V_58 , V_15 ) ;
V_102 = V_5 -> V_96 ;
F_81 ( & V_5 -> V_58 , V_15 ) ;
return V_102 ;
}
unsigned long F_82 ( struct V_1 * V_2 )
{
unsigned long V_102 ;
if ( ! F_83 ( V_2 , V_103 ) )
return 0 ;
V_102 = F_79 ( V_2 ) ;
F_76 ( V_2 ) ;
return V_102 ;
}
T_3 F_84 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
if ( ! F_57 ( V_5 -> V_25 ) )
return 0 ;
return V_5 -> V_76 ;
}
unsigned long F_85 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
return V_5 -> V_64 ;
}
void F_86 ( struct V_1 * V_2 , T_3 V_71 , T_3 V_39 ,
unsigned long * V_104 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_37 , * V_61 ;
unsigned long V_105 , V_68 ;
unsigned int V_21 ;
T_3 V_75 , V_74 ;
V_75 = V_71 + V_39 ;
if ( ! F_57 ( V_5 ) )
return;
if ( ! F_57 ( V_5 -> V_25 ) )
return;
if ( V_39 == 0 )
return;
F_52 ( V_71 >= V_5 -> V_76 ) ;
F_52 ( V_75 > V_5 -> V_76 ) ;
F_72 ( & V_5 -> V_58 ) ;
while ( V_71 < V_75 ) {
V_74 = F_66 ( T_3 , F_67 ( V_71 + 1 , V_70 ) , V_75 ) - V_71 ;
V_21 = F_33 ( V_5 , V_71 ) ;
V_37 = F_37 ( V_5 , V_21 ) ;
V_61 = V_37 + F_68 ( V_71 ) ;
V_71 += V_74 ;
while ( V_74 -- ) {
V_68 = F_61 ( * V_61 ) ;
V_105 = * V_61 | * V_104 ++ ;
* V_61 ++ = V_105 ;
V_5 -> V_96 += F_61 ( V_105 ) - V_68 ;
}
F_40 ( V_37 ) ;
F_24 ( V_5 -> V_25 [ V_21 ] ) ;
}
if ( V_75 == V_5 -> V_76 )
V_5 -> V_96 -= F_59 ( V_5 ) ;
F_73 ( & V_5 -> V_58 ) ;
}
void F_87 ( struct V_1 * V_2 , T_3 V_71 , T_3 V_39 ,
unsigned long * V_104 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_37 , * V_61 ;
T_3 V_75 , V_74 ;
V_75 = V_71 + V_39 ;
if ( ! F_57 ( V_5 ) )
return;
if ( ! F_57 ( V_5 -> V_25 ) )
return;
F_72 ( & V_5 -> V_58 ) ;
if ( ( V_71 >= V_5 -> V_76 ) ||
( V_75 > V_5 -> V_76 ) ||
( V_39 <= 0 ) )
F_3 ( V_8 , L_18 ,
( unsigned long ) V_71 ,
( unsigned long ) V_39 ,
( unsigned long ) V_5 -> V_76 ) ;
else {
while ( V_71 < V_75 ) {
V_74 = F_66 ( T_3 , F_67 ( V_71 + 1 , V_70 ) , V_75 ) - V_71 ;
V_37 = F_37 ( V_5 , F_33 ( V_5 , V_71 ) ) ;
V_61 = V_37 + F_68 ( V_71 ) ;
V_71 += V_74 ;
while ( V_74 -- )
* V_104 ++ = * V_61 ++ ;
F_40 ( V_37 ) ;
}
}
F_73 ( & V_5 -> V_58 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_57 ( V_5 ) )
return;
if ( ! F_57 ( V_5 -> V_25 ) )
return;
F_72 ( & V_5 -> V_58 ) ;
F_65 ( V_5 , 0 , 0xff , V_5 -> V_76 ) ;
( void ) F_59 ( V_5 ) ;
V_5 -> V_96 = V_5 -> V_64 ;
F_73 ( & V_5 -> V_58 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_57 ( V_5 ) )
return;
if ( ! F_57 ( V_5 -> V_25 ) )
return;
F_72 ( & V_5 -> V_58 ) ;
F_65 ( V_5 , 0 , 0 , V_5 -> V_76 ) ;
V_5 -> V_96 = 0 ;
F_73 ( & V_5 -> V_58 ) ;
}
static void F_90 ( struct V_106 * V_106 )
{
struct V_107 * V_108 = F_91 ( V_106 , struct V_107 , V_106 ) ;
F_76 ( V_108 -> V_2 ) ;
F_46 ( V_108 ) ;
}
static void F_92 ( struct V_109 * V_109 , int error )
{
struct V_107 * V_108 = V_109 -> V_110 ;
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_21 = F_14 ( V_109 -> V_111 [ 0 ] . V_112 ) ;
int V_113 = F_93 ( V_109 , V_114 ) ;
if ( ! error && ! V_113 )
error = - V_115 ;
if ( ( V_108 -> V_15 & V_116 ) == 0 &&
! F_27 ( V_5 -> V_25 [ V_21 ] ) )
F_7 ( V_8 , L_19 , V_21 ) ;
if ( error ) {
V_108 -> error = error ;
F_28 ( V_5 -> V_25 [ V_21 ] ) ;
if ( F_2 ( & V_7 ) )
F_3 ( V_8 , L_20 ,
error , V_21 ) ;
} else {
F_29 ( V_5 -> V_25 [ V_21 ] ) ;
F_94 ( V_8 , L_21 , V_21 ) ;
}
F_19 ( V_2 , V_21 ) ;
if ( V_108 -> V_15 & V_116 )
F_95 ( V_109 -> V_111 [ 0 ] . V_112 , V_117 ) ;
F_96 ( V_109 ) ;
if ( F_97 ( & V_108 -> V_118 ) ) {
V_108 -> V_119 = 1 ;
F_21 ( & V_2 -> V_120 ) ;
F_98 ( & V_108 -> V_106 , & F_90 ) ;
}
}
static void F_99 ( struct V_107 * V_108 , int V_23 , int V_121 ) __must_hold( T_4 )
{
struct V_109 * V_109 = F_100 ( V_50 ) ;
struct V_1 * V_2 = V_108 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_20 * V_20 ;
unsigned int V_73 ;
T_2 V_122 =
V_2 -> V_78 -> V_80 . V_123 + V_2 -> V_78 -> V_80 . V_83 ;
V_122 += ( ( T_2 ) V_23 ) << ( V_34 - 9 ) ;
V_73 = F_66 (unsigned int, PAGE_SIZE,
(drbd_md_last_sector(mdev->ldev) - on_disk_sector + 1)<<9 ) ;
F_16 ( V_2 , V_23 ) ;
F_22 ( V_5 -> V_25 [ V_23 ] ) ;
if ( V_108 -> V_15 & V_116 ) {
V_20 = F_101 ( V_117 , V_52 | V_124 ) ;
F_102 ( V_20 , V_5 -> V_25 [ V_23 ] ) ;
F_11 ( V_20 , V_23 ) ;
} else
V_20 = V_5 -> V_25 [ V_23 ] ;
V_109 -> V_125 = V_2 -> V_78 -> V_126 ;
V_109 -> V_127 . V_128 = V_122 ;
F_103 ( V_109 , V_20 , V_73 , 0 ) ;
V_109 -> V_110 = V_108 ;
V_109 -> V_129 = F_92 ;
if ( F_78 ( V_2 , ( V_121 & V_130 ) ? V_131 : V_132 ) ) {
V_109 -> V_133 |= V_121 ;
F_104 ( V_109 , - V_115 ) ;
} else {
F_105 ( V_121 , V_109 ) ;
F_106 ( V_73 >> 9 , & V_2 -> V_134 ) ;
}
}
static int F_107 ( struct V_1 * V_2 , int V_121 , unsigned V_15 , unsigned V_135 ) __must_hold( T_4 )
{
struct V_107 * V_108 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_136 , V_40 , V_137 = 0 ;
unsigned long V_138 ;
char V_139 [ 10 ] ;
int V_92 = 0 ;
V_108 = F_108 ( sizeof( struct V_107 ) , V_50 ) ;
if ( ! V_108 )
return - V_57 ;
* V_108 = (struct V_107 ) {
. V_2 = V_2 ,
. V_118 = F_109 ( 1 ) ,
. V_119 = 0 ,
. V_15 = V_15 ,
. error = 0 ,
. V_106 = { F_109 ( 2 ) } ,
} ;
if ( ! F_83 ( V_2 , V_140 ) ) {
F_3 ( V_8 , L_22 ) ;
F_46 ( V_108 ) ;
return - V_141 ;
}
if ( ! V_108 -> V_15 )
F_52 ( ! ( V_18 & V_5 -> V_19 ) ) ;
V_136 = V_5 -> V_30 ;
V_138 = V_142 ;
for ( V_40 = 0 ; V_40 < V_136 ; V_40 ++ ) {
if ( V_135 && V_40 == V_135 )
break;
if ( V_121 & V_130 ) {
if ( ( V_15 & V_143 ) &&
! F_110 ( V_31 ,
& F_15 ( V_5 -> V_25 [ V_40 ] ) ) )
continue;
if ( ! ( V_15 & V_144 ) &&
F_27 ( V_5 -> V_25 [ V_40 ] ) ) {
F_94 ( V_8 , L_23 , V_40 ) ;
continue;
}
if ( V_135 &&
! F_31 ( V_5 -> V_25 [ V_40 ] ) ) {
F_94 ( V_8 , L_24 , V_40 ) ;
continue;
}
}
F_111 ( & V_108 -> V_118 ) ;
F_99 ( V_108 , V_40 , V_121 ) ;
++ V_137 ;
F_64 () ;
}
if ( ! F_97 ( & V_108 -> V_118 ) )
F_112 ( V_2 , V_2 -> V_78 , & V_108 -> V_119 ) ;
else
F_98 ( & V_108 -> V_106 , & F_90 ) ;
if ( V_15 == 0 )
F_71 ( V_8 , L_25 ,
V_121 == V_130 ? L_26 : L_27 ,
V_137 , V_142 - V_138 ) ;
if ( V_108 -> error ) {
F_113 ( V_8 , L_28 ) ;
F_114 ( V_2 , 1 , V_145 ) ;
V_92 = - V_115 ;
}
if ( F_115 ( & V_108 -> V_118 ) )
V_92 = - V_115 ;
V_138 = V_142 ;
if ( V_121 == V_130 ) {
F_116 ( V_2 ) ;
} else {
V_5 -> V_96 = F_63 ( V_5 ) ;
F_71 ( V_8 , L_29 ,
V_142 - V_138 ) ;
}
V_138 = V_5 -> V_96 ;
if ( V_15 == 0 )
F_71 ( V_8 , L_30 ,
F_117 ( V_139 , V_138 << ( V_146 - 10 ) ) , V_138 ) ;
F_98 ( & V_108 -> V_106 , & F_90 ) ;
return V_92 ;
}
int F_118 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_107 ( V_2 , V_147 , 0 , 0 ) ;
}
int F_119 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_107 ( V_2 , V_130 , 0 , 0 ) ;
}
int F_120 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_107 ( V_2 , V_130 , V_144 , 0 ) ;
}
int F_121 ( struct V_1 * V_2 , unsigned V_148 ) __must_hold( T_4 )
{
return F_107 ( V_2 , V_130 , V_116 , V_148 ) ;
}
int F_122 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_107 ( V_2 , V_130 , V_116 , 0 ) ;
}
int F_123 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_107 ( V_2 , V_130 , V_143 | V_116 , 0 ) ;
}
int F_124 ( struct V_1 * V_2 , unsigned int V_21 ) __must_hold( T_4 )
{
struct V_107 * V_108 ;
int V_92 ;
if ( F_27 ( V_2 -> V_6 -> V_25 [ V_21 ] ) ) {
F_94 ( V_8 , L_31 , V_21 ) ;
return 0 ;
}
V_108 = F_108 ( sizeof( struct V_107 ) , V_50 ) ;
if ( ! V_108 )
return - V_57 ;
* V_108 = (struct V_107 ) {
. V_2 = V_2 ,
. V_118 = F_109 ( 1 ) ,
. V_119 = 0 ,
. V_15 = V_116 ,
. error = 0 ,
. V_106 = { F_109 ( 2 ) } ,
} ;
if ( ! F_83 ( V_2 , V_140 ) ) {
F_3 ( V_8 , L_32 ) ;
F_46 ( V_108 ) ;
return - V_141 ;
}
F_99 ( V_108 , V_21 , V_149 ) ;
F_112 ( V_2 , V_2 -> V_78 , & V_108 -> V_119 ) ;
if ( V_108 -> error )
F_114 ( V_2 , 1 , V_145 ) ;
V_2 -> V_150 ++ ;
V_92 = F_115 ( & V_108 -> V_118 ) ? - V_115 : V_108 -> error ;
F_98 ( & V_108 -> V_106 , & F_90 ) ;
return V_92 ;
}
static unsigned long F_125 ( struct V_1 * V_2 , unsigned long V_151 ,
const int V_152 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_37 ;
unsigned long V_153 ;
unsigned V_40 ;
if ( V_151 > V_5 -> V_64 ) {
F_3 ( V_8 , L_33 , V_151 , V_5 -> V_64 ) ;
V_151 = V_154 ;
} else {
while ( V_151 < V_5 -> V_64 ) {
V_153 = V_151 & ~ V_65 ;
V_37 = F_35 ( V_5 , F_34 ( V_5 , V_151 ) ) ;
if ( V_152 )
V_40 = F_126 ( V_37 ,
V_100 * 8 , V_151 & V_65 ) ;
else
V_40 = F_127 ( V_37 ,
V_100 * 8 , V_151 & V_65 ) ;
F_38 ( V_37 ) ;
if ( V_40 < V_100 * 8 ) {
V_151 = V_153 + V_40 ;
if ( V_151 >= V_5 -> V_64 )
break;
goto V_155;
}
V_151 = V_153 + V_100 * 8 ;
}
V_151 = V_154 ;
}
V_155:
return V_151 ;
}
static unsigned long F_128 ( struct V_1 * V_2 ,
unsigned long V_151 , const int V_152 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_40 = V_154 ;
if ( ! F_57 ( V_5 ) )
return V_40 ;
if ( ! F_57 ( V_5 -> V_25 ) )
return V_40 ;
F_72 ( & V_5 -> V_58 ) ;
if ( V_156 & V_5 -> V_19 )
F_129 ( V_2 ) ;
V_40 = F_125 ( V_2 , V_151 , V_152 ) ;
F_73 ( & V_5 -> V_58 ) ;
return V_40 ;
}
unsigned long F_130 ( struct V_1 * V_2 , unsigned long V_151 )
{
return F_128 ( V_2 , V_151 , 0 ) ;
}
unsigned long F_131 ( struct V_1 * V_2 , unsigned long V_151 )
{
return F_125 ( V_2 , V_151 , 0 ) ;
}
unsigned long F_132 ( struct V_1 * V_2 , unsigned long V_151 )
{
return F_125 ( V_2 , V_151 , 1 ) ;
}
static int F_133 ( struct V_1 * V_2 , const unsigned long V_102 ,
unsigned long V_157 , int V_158 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_37 = NULL ;
unsigned long V_36 ;
unsigned int V_159 = - 1U ;
int V_72 = 0 ;
int V_160 = 0 ;
if ( V_157 >= V_5 -> V_64 ) {
F_3 ( V_8 , L_34 ,
V_102 , V_157 , V_5 -> V_64 ) ;
V_157 = V_5 -> V_64 ? V_5 -> V_64 - 1 : 0 ;
}
for ( V_36 = V_102 ; V_36 <= V_157 ; V_36 ++ ) {
unsigned int V_23 = F_34 ( V_5 , V_36 ) ;
if ( V_23 != V_159 ) {
if ( V_37 )
F_38 ( V_37 ) ;
if ( V_72 < 0 )
F_30 ( V_5 -> V_25 [ V_159 ] ) ;
else if ( V_72 > 0 )
F_24 ( V_5 -> V_25 [ V_159 ] ) ;
V_160 += V_72 ;
V_72 = 0 ;
V_37 = F_35 ( V_5 , V_23 ) ;
V_159 = V_23 ;
}
if ( V_158 )
V_72 += ( 0 == F_134 ( V_36 & V_65 , V_37 ) ) ;
else
V_72 -= ( 0 != F_135 ( V_36 & V_65 , V_37 ) ) ;
}
if ( V_37 )
F_38 ( V_37 ) ;
if ( V_72 < 0 )
F_30 ( V_5 -> V_25 [ V_159 ] ) ;
else if ( V_72 > 0 )
F_24 ( V_5 -> V_25 [ V_159 ] ) ;
V_160 += V_72 ;
V_5 -> V_96 += V_160 ;
return V_160 ;
}
static int F_136 ( struct V_1 * V_2 , const unsigned long V_102 ,
const unsigned long V_157 , int V_158 )
{
unsigned long V_15 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_72 = 0 ;
if ( ! F_57 ( V_5 ) )
return 1 ;
if ( ! F_57 ( V_5 -> V_25 ) )
return 0 ;
F_80 ( & V_5 -> V_58 , V_15 ) ;
if ( ( V_158 ? V_161 : V_162 ) & V_5 -> V_19 )
F_129 ( V_2 ) ;
V_72 = F_133 ( V_2 , V_102 , V_157 , V_158 ) ;
F_81 ( & V_5 -> V_58 , V_15 ) ;
return V_72 ;
}
int F_137 ( struct V_1 * V_2 , const unsigned long V_102 , const unsigned long V_157 )
{
return F_136 ( V_2 , V_102 , V_157 , 1 ) ;
}
int F_138 ( struct V_1 * V_2 , const unsigned long V_102 , const unsigned long V_157 )
{
return - F_136 ( V_2 , V_102 , V_157 , 0 ) ;
}
static inline void F_139 ( struct V_4 * V_5 ,
int V_23 , int V_163 , int V_69 )
{
int V_40 ;
int V_68 ;
int V_164 = 0 ;
unsigned long * V_165 = F_36 ( V_5 -> V_25 [ V_23 ] ) ;
for ( V_40 = V_163 ; V_40 < V_69 ; V_40 ++ ) {
V_68 = F_61 ( V_165 [ V_40 ] ) ;
V_165 [ V_40 ] = ~ 0UL ;
V_164 += V_67 - V_68 ;
}
F_39 ( V_165 ) ;
if ( V_164 ) {
F_30 ( V_5 -> V_25 [ V_23 ] ) ;
V_5 -> V_96 += V_164 ;
}
}
void F_140 ( struct V_1 * V_2 , const unsigned long V_102 , const unsigned long V_157 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_166 = F_67 ( V_102 , V_67 ) ;
unsigned long V_167 = ( V_157 + 1 ) & ~ ( ( unsigned long ) V_67 - 1 ) ;
int V_168 ;
int V_169 ;
int V_23 ;
int V_163 ;
int V_69 ;
if ( V_157 - V_102 <= 3 * V_67 ) {
F_72 ( & V_5 -> V_58 ) ;
F_133 ( V_2 , V_102 , V_157 , 1 ) ;
F_73 ( & V_5 -> V_58 ) ;
return;
}
F_72 ( & V_5 -> V_58 ) ;
if ( V_166 )
F_133 ( V_2 , V_102 , V_166 - 1 , 1 ) ;
V_168 = V_166 >> ( 3 + V_34 ) ;
V_169 = V_167 >> ( 3 + V_34 ) ;
V_163 = F_68 ( V_166 >> V_35 ) ;
V_69 = V_70 ;
for ( V_23 = V_168 ; V_23 < V_169 ; V_23 ++ ) {
F_139 ( V_2 -> V_6 , V_23 , V_163 , V_69 ) ;
F_73 ( & V_5 -> V_58 ) ;
F_64 () ;
V_163 = 0 ;
F_72 ( & V_5 -> V_58 ) ;
}
V_69 = F_68 ( V_167 >> V_35 ) ;
if ( V_69 )
F_139 ( V_2 -> V_6 , V_169 , V_163 , V_69 ) ;
if ( V_167 <= V_157 )
F_133 ( V_2 , V_167 , V_157 , 1 ) ;
F_73 ( & V_5 -> V_58 ) ;
}
int F_141 ( struct V_1 * V_2 , const unsigned long V_36 )
{
unsigned long V_15 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_37 ;
int V_40 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
if ( ! F_57 ( V_5 -> V_25 ) )
return 0 ;
F_80 ( & V_5 -> V_58 , V_15 ) ;
if ( V_156 & V_5 -> V_19 )
F_129 ( V_2 ) ;
if ( V_36 < V_5 -> V_64 ) {
V_37 = F_37 ( V_5 , F_34 ( V_5 , V_36 ) ) ;
V_40 = F_142 ( V_36 & V_65 , V_37 ) ? 1 : 0 ;
F_40 ( V_37 ) ;
} else if ( V_36 == V_5 -> V_64 ) {
V_40 = - 1 ;
} else {
F_3 ( V_8 , L_35 , V_36 , V_5 -> V_64 ) ;
V_40 = 0 ;
}
F_81 ( & V_5 -> V_58 , V_15 ) ;
return V_40 ;
}
int F_143 ( struct V_1 * V_2 , const unsigned long V_102 , const unsigned long V_157 )
{
unsigned long V_15 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_37 = NULL ;
unsigned long V_36 ;
unsigned int V_23 = - 1U ;
int V_72 = 0 ;
if ( ! F_57 ( V_5 ) )
return 1 ;
if ( ! F_57 ( V_5 -> V_25 ) )
return 1 ;
F_80 ( & V_5 -> V_58 , V_15 ) ;
if ( V_156 & V_5 -> V_19 )
F_129 ( V_2 ) ;
for ( V_36 = V_102 ; V_36 <= V_157 ; V_36 ++ ) {
unsigned int V_21 = F_34 ( V_5 , V_36 ) ;
if ( V_23 != V_21 ) {
V_23 = V_21 ;
if ( V_37 )
F_40 ( V_37 ) ;
V_37 = F_37 ( V_5 , V_21 ) ;
}
if ( F_57 ( V_36 < V_5 -> V_64 ) )
V_72 += ( 0 != F_142 ( V_36 - ( V_23 << ( V_34 + 3 ) ) , V_37 ) ) ;
else
F_3 ( V_8 , L_36 , V_36 , V_5 -> V_64 ) ;
}
if ( V_37 )
F_40 ( V_37 ) ;
F_81 ( & V_5 -> V_58 , V_15 ) ;
return V_72 ;
}
int F_144 ( struct V_1 * V_2 , unsigned long V_170 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_137 , V_102 , V_157 ;
unsigned long V_15 ;
unsigned long * V_37 , * V_61 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
if ( ! F_57 ( V_5 -> V_25 ) )
return 0 ;
F_80 ( & V_5 -> V_58 , V_15 ) ;
if ( V_156 & V_5 -> V_19 )
F_129 ( V_2 ) ;
V_102 = F_145 ( V_170 ) ;
V_157 = F_146 ( ( T_3 ) F_145 ( V_170 + 1 ) , V_5 -> V_76 ) ;
V_137 = 0 ;
if ( V_102 < V_5 -> V_76 ) {
int V_171 = V_157 - V_102 ;
V_37 = F_37 ( V_5 , F_33 ( V_5 , V_102 ) ) ;
V_61 = V_37 + F_68 ( V_102 ) ;
while ( V_171 -- )
V_137 += F_61 ( * V_61 ++ ) ;
F_40 ( V_37 ) ;
} else {
F_3 ( V_8 , L_37 , V_102 ) ;
}
F_81 ( & V_5 -> V_58 , V_15 ) ;
return V_137 ;
}
