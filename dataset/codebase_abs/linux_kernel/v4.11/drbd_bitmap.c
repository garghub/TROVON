static void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_2 ( & V_7 ) )
return;
F_3 ( V_2 , L_1 ,
V_8 -> V_9 , F_4 ( V_8 ) ,
V_3 , V_5 -> V_10 ? : L_2 ,
V_5 -> V_11 -> V_9 , F_4 ( V_5 -> V_11 ) ) ;
}
void F_5 ( struct V_1 * V_2 , char * V_12 , enum V_13 V_14 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_15 ;
if ( ! V_5 ) {
F_3 ( V_2 , L_3 ) ;
return;
}
V_15 = ! F_6 ( & V_5 -> V_16 ) ;
if ( V_15 ) {
F_7 ( V_2 , L_4 ,
V_8 -> V_9 , F_4 ( V_8 ) ,
V_12 , V_5 -> V_10 ? : L_2 ,
V_5 -> V_11 -> V_9 , F_4 ( V_5 -> V_11 ) ) ;
F_8 ( & V_5 -> V_16 ) ;
}
if ( V_17 & V_5 -> V_18 )
F_3 ( V_2 , L_5 ) ;
V_5 -> V_18 |= V_14 & V_17 ;
V_5 -> V_10 = V_12 ;
V_5 -> V_11 = V_8 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 ) {
F_3 ( V_2 , L_6 ) ;
return;
}
if ( ! ( V_17 & V_2 -> V_6 -> V_18 ) )
F_3 ( V_2 , L_7 ) ;
V_5 -> V_18 &= ~ V_17 ;
V_5 -> V_10 = NULL ;
V_5 -> V_11 = NULL ;
F_10 ( & V_5 -> V_16 ) ;
}
static void F_11 ( struct V_19 * V_19 , unsigned long V_20 )
{
F_12 ( 0 != ( V_20 & ~ V_21 ) ) ;
F_13 ( V_19 , V_20 ) ;
}
static unsigned long F_14 ( struct V_19 * V_19 )
{
return F_15 ( V_19 ) & V_21 ;
}
static void F_16 ( struct V_1 * V_2 , int V_22 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void * V_23 = & F_15 ( V_5 -> V_24 [ V_22 ] ) ;
F_17 ( V_5 -> V_25 , ! F_18 ( V_26 , V_23 ) ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_22 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void * V_23 = & F_15 ( V_5 -> V_24 [ V_22 ] ) ;
F_20 ( V_26 , V_23 ) ;
F_21 ( & V_2 -> V_6 -> V_25 ) ;
}
static void F_22 ( struct V_19 * V_19 )
{
F_23 ( V_27 , & F_15 ( V_19 ) ) ;
F_23 ( V_28 , & F_15 ( V_19 ) ) ;
}
static void F_24 ( struct V_19 * V_19 )
{
F_25 ( V_27 , & F_15 ( V_19 ) ) ;
}
void F_26 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_29 = 0 ;
}
void F_27 ( struct V_1 * V_2 , int V_22 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_19 * V_19 ;
if ( V_22 >= V_2 -> V_6 -> V_30 ) {
F_7 ( V_2 , L_8 ,
V_22 , ( int ) V_2 -> V_6 -> V_30 ) ;
return;
}
V_19 = V_2 -> V_6 -> V_24 [ V_22 ] ;
F_12 ( V_5 -> V_29 >= F_28 ( V_5 -> V_31 ) ) ;
if ( ! F_18 ( V_32 , & F_15 ( V_19 ) ) )
V_5 -> V_31 [ V_5 -> V_29 ++ ] = V_22 ;
}
static int F_29 ( struct V_19 * V_19 )
{
volatile const unsigned long * V_23 = & F_15 ( V_19 ) ;
return ( * V_23 & ( ( 1UL << V_27 ) | ( 1UL << V_28 ) ) ) == 0 ;
}
static void F_30 ( struct V_19 * V_19 )
{
F_25 ( V_33 , & F_15 ( V_19 ) ) ;
}
static void F_31 ( struct V_19 * V_19 )
{
F_23 ( V_33 , & F_15 ( V_19 ) ) ;
}
static void F_32 ( struct V_19 * V_19 )
{
F_25 ( V_28 , & F_15 ( V_19 ) ) ;
}
static int F_33 ( struct V_19 * V_19 )
{
return F_34 ( V_28 , & F_15 ( V_19 ) ) ;
}
static unsigned int F_35 ( struct V_4 * V_5 , unsigned long V_34 )
{
unsigned int V_22 = V_34 >> ( V_35 - V_36 + 3 ) ;
F_12 ( V_22 >= V_5 -> V_30 ) ;
return V_22 ;
}
static unsigned int F_36 ( struct V_4 * V_5 , T_1 V_37 )
{
unsigned int V_22 = V_37 >> ( V_35 + 3 ) ;
F_12 ( V_22 >= V_5 -> V_30 ) ;
return V_22 ;
}
static unsigned long * F_37 ( struct V_4 * V_5 , unsigned int V_20 )
{
struct V_19 * V_19 = V_5 -> V_24 [ V_20 ] ;
return ( unsigned long * ) F_38 ( V_19 ) ;
}
static unsigned long * F_39 ( struct V_4 * V_5 , unsigned int V_20 )
{
return F_37 ( V_5 , V_20 ) ;
}
static void F_40 ( unsigned long * V_38 )
{
F_41 ( V_38 ) ;
}
static void F_42 ( unsigned long * V_38 )
{
return F_40 ( V_38 ) ;
}
static void F_43 ( struct V_19 * * V_39 , unsigned long V_40 )
{
unsigned long V_41 ;
if ( ! V_39 )
return;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ ) {
if ( ! V_39 [ V_41 ] ) {
F_44 ( L_9 ,
V_41 , V_40 ) ;
continue;
}
F_45 ( V_39 [ V_41 ] ) ;
V_39 [ V_41 ] = NULL ;
}
}
static inline void F_46 ( void * V_42 )
{
F_47 ( V_42 ) ;
}
static struct V_19 * * F_48 ( struct V_4 * V_5 , unsigned long V_43 )
{
struct V_19 * * V_44 = V_5 -> V_24 ;
struct V_19 * * V_45 , * V_19 ;
unsigned int V_41 , V_46 ;
unsigned long V_47 = V_5 -> V_30 ;
F_12 ( V_47 == 0 && V_44 != NULL ) ;
F_12 ( V_47 != 0 && V_44 == NULL ) ;
if ( V_47 == V_43 )
return V_44 ;
V_46 = sizeof( struct V_19 * ) * V_43 ;
V_45 = F_49 ( V_46 , V_48 | V_49 ) ;
if ( ! V_45 ) {
V_45 = F_50 ( V_46 ,
V_48 | V_50 | V_51 ,
V_52 ) ;
if ( ! V_45 )
return NULL ;
}
if ( V_43 >= V_47 ) {
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ )
V_45 [ V_41 ] = V_44 [ V_41 ] ;
for (; V_41 < V_43 ; V_41 ++ ) {
V_19 = F_51 ( V_48 | V_50 ) ;
if ( ! V_19 ) {
F_43 ( V_45 + V_47 , V_41 - V_47 ) ;
F_46 ( V_45 ) ;
return NULL ;
}
F_11 ( V_19 , V_41 ) ;
V_45 [ V_41 ] = V_19 ;
}
} else {
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ )
V_45 [ V_41 ] = V_44 [ V_41 ] ;
}
return V_45 ;
}
int F_52 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_53 ( V_5 != NULL ) ;
V_5 = F_49 ( sizeof( struct V_4 ) , V_53 ) ;
if ( ! V_5 )
return - V_54 ;
F_54 ( & V_5 -> V_55 ) ;
F_55 ( & V_5 -> V_16 ) ;
F_56 ( & V_5 -> V_25 ) ;
V_2 -> V_6 = V_5 ;
return 0 ;
}
T_2 F_57 ( struct V_1 * V_2 )
{
if ( ! F_58 ( V_2 -> V_6 ) )
return 0 ;
return V_2 -> V_6 -> V_56 ;
}
void F_59 ( struct V_1 * V_2 )
{
if ( ! F_58 ( V_2 -> V_6 ) )
return;
F_43 ( V_2 -> V_6 -> V_24 , V_2 -> V_6 -> V_30 ) ;
F_46 ( V_2 -> V_6 -> V_24 ) ;
F_60 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
static int F_61 ( struct V_4 * V_5 )
{
unsigned long V_57 ;
unsigned long * V_38 , * V_58 ;
int V_59 ;
int V_60 = 0 ;
V_59 = ( V_5 -> V_61 & V_62 ) ;
V_57 = ( 1UL << ( V_59 & V_63 ) ) - 1 ;
V_57 = F_62 ( V_57 ) ;
V_38 = F_39 ( V_5 , V_5 -> V_30 - 1 ) ;
V_58 = V_38 + ( V_59 / V_64 ) ;
if ( V_57 ) {
V_60 = F_63 ( * V_58 & ~ V_57 ) ;
* V_58 &= V_57 ;
V_58 ++ ;
}
if ( V_64 == 32 && ( ( V_58 - V_38 ) & 1 ) == 1 ) {
V_60 += F_63 ( * V_58 ) ;
* V_58 = 0 ;
}
F_42 ( V_38 ) ;
return V_60 ;
}
static void F_64 ( struct V_4 * V_5 )
{
unsigned long V_57 ;
unsigned long * V_38 , * V_58 ;
int V_59 ;
V_59 = ( V_5 -> V_61 & V_62 ) ;
V_57 = ( 1UL << ( V_59 & V_63 ) ) - 1 ;
V_57 = F_62 ( V_57 ) ;
V_38 = F_39 ( V_5 , V_5 -> V_30 - 1 ) ;
V_58 = V_38 + ( V_59 / V_64 ) ;
if ( V_57 ) {
* V_58 |= ~ V_57 ;
V_58 ++ ;
}
if ( V_64 == 32 && ( ( V_58 - V_38 ) & 1 ) == 1 ) {
* V_58 = ~ 0UL ;
}
F_42 ( V_38 ) ;
}
static unsigned long F_65 ( struct V_4 * V_5 )
{
unsigned long * V_38 ;
unsigned long V_65 = 0 ;
unsigned long V_57 = ( 1UL << ( V_5 -> V_61 & V_63 ) ) - 1 ;
int V_20 , V_66 ;
for ( V_20 = 0 ; V_20 < V_5 -> V_30 - 1 ; V_20 ++ ) {
V_38 = F_37 ( V_5 , V_20 ) ;
V_65 += F_66 ( V_38 , V_67 ) ;
F_40 ( V_38 ) ;
F_67 () ;
}
V_66 = ( ( V_5 -> V_61 - 1 ) & V_62 ) >> V_36 ;
V_38 = F_37 ( V_5 , V_20 ) ;
V_65 += F_66 ( V_38 , V_66 * V_64 ) ;
V_38 [ V_66 ] &= F_62 ( V_57 ) ;
V_65 += F_63 ( V_38 [ V_66 ] ) ;
if ( V_64 == 32 && ( V_66 & 1 ) == 0 )
V_38 [ V_66 + 1 ] = 0 ;
F_40 ( V_38 ) ;
return V_65 ;
}
static void F_68 ( struct V_4 * V_5 , T_3 V_68 , int V_69 , T_3 V_70 )
{
unsigned long * V_38 , * V_58 ;
unsigned int V_20 ;
T_3 V_71 , V_72 ;
V_72 = V_68 + V_70 ;
if ( V_72 > V_5 -> V_73 ) {
F_44 ( L_10 ) ;
return;
}
while ( V_68 < V_72 ) {
V_71 = F_69 ( T_3 , F_70 ( V_68 + 1 , V_74 ) , V_72 ) - V_68 ;
V_20 = F_35 ( V_5 , V_68 ) ;
V_38 = F_39 ( V_5 , V_20 ) ;
V_58 = V_38 + F_71 ( V_68 ) ;
if ( V_58 + V_71 > V_38 + V_74 ) {
F_44 ( L_11 ,
V_38 , V_58 , ( int ) V_71 ) ;
} else
memset ( V_58 , V_69 , V_71 * sizeof( long ) ) ;
F_42 ( V_38 ) ;
F_24 ( V_5 -> V_24 [ V_20 ] ) ;
V_68 += V_71 ;
}
}
static T_1 F_72 ( struct V_75 * V_76 )
{
T_1 V_77 ;
if ( V_76 -> V_78 . V_79 == 8 )
V_77 = V_76 -> V_78 . V_80 - V_76 -> V_78 . V_81 ;
else
V_77 = V_76 -> V_78 . V_79 - V_76 -> V_78 . V_81 ;
return V_77 << ( 9 + 3 ) ;
}
int F_73 ( struct V_1 * V_2 , T_2 V_82 , int V_83 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_65 , V_84 , V_85 , V_86 ;
unsigned long V_43 , V_47 , V_87 ;
struct V_19 * * V_88 , * * V_89 = NULL ;
int V_90 = 0 ;
bool V_91 ;
if ( ! F_58 ( V_5 ) )
return - V_54 ;
F_5 ( V_2 , L_12 , V_17 ) ;
F_74 ( V_2 , L_13 ,
( unsigned long long ) V_82 ) ;
if ( V_82 == V_5 -> V_56 )
goto V_92;
if ( V_82 == 0 ) {
F_75 ( & V_5 -> V_55 ) ;
V_89 = V_5 -> V_24 ;
V_87 = V_5 -> V_30 ;
V_85 = V_5 -> V_73 ;
V_5 -> V_24 = NULL ;
V_5 -> V_30 =
V_5 -> V_93 =
V_5 -> V_61 =
V_5 -> V_73 =
V_5 -> V_56 = 0 ;
F_76 ( & V_5 -> V_55 ) ;
F_43 ( V_89 , V_87 ) ;
F_46 ( V_89 ) ;
goto V_92;
}
V_65 = F_77 ( F_70 ( V_82 , V_94 ) ) ;
V_84 = F_70 ( V_65 , 64 ) >> V_36 ;
if ( F_78 ( V_2 ) ) {
T_1 V_95 = F_72 ( V_2 -> V_76 ) ;
F_79 ( V_2 ) ;
if ( V_65 > V_95 ) {
F_74 ( V_2 , L_14 , V_65 ) ;
F_74 ( V_2 , L_15 , V_95 ) ;
V_90 = - V_96 ;
goto V_92;
}
}
V_43 = F_70 ( V_84 * sizeof( long ) , V_97 ) >> V_35 ;
V_47 = V_5 -> V_30 ;
if ( V_43 == V_47 ) {
F_80 ( V_2 , V_5 -> V_24 != NULL ) ;
V_88 = V_5 -> V_24 ;
} else {
if ( F_81 ( V_2 , V_98 ) )
V_88 = NULL ;
else
V_88 = F_48 ( V_5 , V_43 ) ;
}
if ( ! V_88 ) {
V_90 = - V_54 ;
goto V_92;
}
F_75 ( & V_5 -> V_55 ) ;
V_89 = V_5 -> V_24 ;
V_85 = V_5 -> V_73 ;
V_86 = V_5 -> V_61 ;
V_91 = V_65 > V_86 ;
if ( V_89 && V_91 && V_83 )
F_64 ( V_5 ) ;
V_5 -> V_24 = V_88 ;
V_5 -> V_30 = V_43 ;
V_5 -> V_61 = V_65 ;
V_5 -> V_73 = V_84 ;
V_5 -> V_56 = V_82 ;
if ( V_91 ) {
if ( V_83 ) {
F_68 ( V_5 , V_85 , 0xff , V_84 - V_85 ) ;
V_5 -> V_93 += V_65 - V_86 ;
} else
F_68 ( V_5 , V_85 , 0x00 , V_84 - V_85 ) ;
}
if ( V_43 < V_47 ) {
F_43 ( V_89 + V_43 , V_47 - V_43 ) ;
}
( void ) F_61 ( V_5 ) ;
F_76 ( & V_5 -> V_55 ) ;
if ( V_89 != V_88 )
F_46 ( V_89 ) ;
if ( ! V_91 )
V_5 -> V_93 = F_65 ( V_5 ) ;
F_74 ( V_2 , L_16 , V_65 , V_84 , V_43 ) ;
V_92:
F_9 ( V_2 ) ;
return V_90 ;
}
unsigned long F_82 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_99 ;
unsigned long V_14 ;
if ( ! F_58 ( V_5 ) )
return 0 ;
if ( ! F_58 ( V_5 -> V_24 ) )
return 0 ;
F_83 ( & V_5 -> V_55 , V_14 ) ;
V_99 = V_5 -> V_93 ;
F_84 ( & V_5 -> V_55 , V_14 ) ;
return V_99 ;
}
unsigned long F_85 ( struct V_1 * V_2 )
{
unsigned long V_99 ;
if ( ! F_86 ( V_2 , V_100 ) )
return 0 ;
V_99 = F_82 ( V_2 ) ;
F_79 ( V_2 ) ;
return V_99 ;
}
T_3 F_87 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_58 ( V_5 ) )
return 0 ;
if ( ! F_58 ( V_5 -> V_24 ) )
return 0 ;
return V_5 -> V_73 ;
}
unsigned long F_88 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_58 ( V_5 ) )
return 0 ;
return V_5 -> V_61 ;
}
void F_89 ( struct V_1 * V_2 , T_3 V_68 , T_3 V_40 ,
unsigned long * V_101 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_38 , * V_58 ;
unsigned long V_102 , V_65 ;
unsigned int V_20 ;
T_3 V_72 , V_71 ;
V_72 = V_68 + V_40 ;
if ( ! F_58 ( V_5 ) )
return;
if ( ! F_58 ( V_5 -> V_24 ) )
return;
if ( V_40 == 0 )
return;
F_53 ( V_68 >= V_5 -> V_73 ) ;
F_53 ( V_72 > V_5 -> V_73 ) ;
F_75 ( & V_5 -> V_55 ) ;
while ( V_68 < V_72 ) {
V_71 = F_69 ( T_3 , F_70 ( V_68 + 1 , V_74 ) , V_72 ) - V_68 ;
V_20 = F_35 ( V_5 , V_68 ) ;
V_38 = F_39 ( V_5 , V_20 ) ;
V_58 = V_38 + F_71 ( V_68 ) ;
V_68 += V_71 ;
while ( V_71 -- ) {
V_65 = F_63 ( * V_58 ) ;
V_102 = * V_58 | * V_101 ++ ;
* V_58 ++ = V_102 ;
V_5 -> V_93 += F_63 ( V_102 ) - V_65 ;
}
F_42 ( V_38 ) ;
F_24 ( V_5 -> V_24 [ V_20 ] ) ;
}
if ( V_72 == V_5 -> V_73 )
V_5 -> V_93 -= F_61 ( V_5 ) ;
F_76 ( & V_5 -> V_55 ) ;
}
void F_90 ( struct V_1 * V_2 , T_3 V_68 , T_3 V_40 ,
unsigned long * V_101 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_38 , * V_58 ;
T_3 V_72 , V_71 ;
V_72 = V_68 + V_40 ;
if ( ! F_58 ( V_5 ) )
return;
if ( ! F_58 ( V_5 -> V_24 ) )
return;
F_75 ( & V_5 -> V_55 ) ;
if ( ( V_68 >= V_5 -> V_73 ) ||
( V_72 > V_5 -> V_73 ) ||
( V_40 <= 0 ) )
F_3 ( V_2 , L_17 ,
( unsigned long ) V_68 ,
( unsigned long ) V_40 ,
( unsigned long ) V_5 -> V_73 ) ;
else {
while ( V_68 < V_72 ) {
V_71 = F_69 ( T_3 , F_70 ( V_68 + 1 , V_74 ) , V_72 ) - V_68 ;
V_38 = F_39 ( V_5 , F_35 ( V_5 , V_68 ) ) ;
V_58 = V_38 + F_71 ( V_68 ) ;
V_68 += V_71 ;
while ( V_71 -- )
* V_101 ++ = * V_58 ++ ;
F_42 ( V_38 ) ;
}
}
F_76 ( & V_5 -> V_55 ) ;
}
void F_91 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_58 ( V_5 ) )
return;
if ( ! F_58 ( V_5 -> V_24 ) )
return;
F_75 ( & V_5 -> V_55 ) ;
F_68 ( V_5 , 0 , 0xff , V_5 -> V_73 ) ;
( void ) F_61 ( V_5 ) ;
V_5 -> V_93 = V_5 -> V_61 ;
F_76 ( & V_5 -> V_55 ) ;
}
void F_92 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_58 ( V_5 ) )
return;
if ( ! F_58 ( V_5 -> V_24 ) )
return;
F_75 ( & V_5 -> V_55 ) ;
F_68 ( V_5 , 0 , 0 , V_5 -> V_73 ) ;
V_5 -> V_93 = 0 ;
F_76 ( & V_5 -> V_55 ) ;
}
static void F_93 ( struct V_103 * V_103 )
{
struct V_104 * V_105 = F_94 ( V_103 , struct V_104 , V_103 ) ;
unsigned long V_14 ;
F_83 ( & V_105 -> V_2 -> V_106 -> V_107 , V_14 ) ;
F_95 ( & V_105 -> V_108 ) ;
F_84 ( & V_105 -> V_2 -> V_106 -> V_107 , V_14 ) ;
F_79 ( V_105 -> V_2 ) ;
F_60 ( V_105 ) ;
}
static void F_96 ( struct V_109 * V_109 )
{
struct V_104 * V_105 = V_109 -> V_110 ;
struct V_1 * V_2 = V_105 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_20 = F_14 ( V_109 -> V_111 [ 0 ] . V_112 ) ;
if ( ( V_105 -> V_14 & V_113 ) == 0 &&
! F_29 ( V_5 -> V_24 [ V_20 ] ) )
F_7 ( V_2 , L_18 , V_20 ) ;
if ( V_109 -> V_114 ) {
V_105 -> error = V_109 -> V_114 ;
F_30 ( V_5 -> V_24 [ V_20 ] ) ;
if ( F_2 ( & V_7 ) )
F_3 ( V_2 , L_19 ,
V_109 -> V_114 , V_20 ) ;
} else {
F_31 ( V_5 -> V_24 [ V_20 ] ) ;
F_97 ( V_2 , L_20 , V_20 ) ;
}
F_19 ( V_2 , V_20 ) ;
if ( V_105 -> V_14 & V_113 )
F_98 ( V_109 -> V_111 [ 0 ] . V_112 , V_115 ) ;
F_99 ( V_109 ) ;
if ( F_100 ( & V_105 -> V_116 ) ) {
V_105 -> V_117 = 1 ;
F_21 ( & V_2 -> V_118 ) ;
F_101 ( & V_105 -> V_103 , & F_93 ) ;
}
}
static void F_102 ( struct V_104 * V_105 , int V_22 ) __must_hold( T_4 )
{
struct V_109 * V_109 = F_103 ( V_48 ) ;
struct V_1 * V_2 = V_105 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_19 * V_19 ;
unsigned int V_70 ;
unsigned int V_119 = ( V_105 -> V_14 & V_120 ) ? V_121 : V_122 ;
T_2 V_123 =
V_2 -> V_76 -> V_78 . V_124 + V_2 -> V_76 -> V_78 . V_81 ;
V_123 += ( ( T_2 ) V_22 ) << ( V_35 - 9 ) ;
V_70 = F_69 (unsigned int, PAGE_SIZE,
(drbd_md_last_sector(device->ldev) - on_disk_sector + 1)<<9 ) ;
F_16 ( V_2 , V_22 ) ;
F_22 ( V_5 -> V_24 [ V_22 ] ) ;
if ( V_105 -> V_14 & V_113 ) {
V_19 = F_104 ( V_115 , V_50 | V_125 ) ;
F_105 ( V_19 , V_5 -> V_24 [ V_22 ] ) ;
F_11 ( V_19 , V_22 ) ;
} else
V_19 = V_5 -> V_24 [ V_22 ] ;
V_109 -> V_126 = V_2 -> V_76 -> V_127 ;
V_109 -> V_128 . V_129 = V_123 ;
F_106 ( V_109 , V_19 , V_70 , 0 ) ;
V_109 -> V_110 = V_105 ;
V_109 -> V_130 = F_96 ;
F_107 ( V_109 , V_119 , 0 ) ;
if ( F_81 ( V_2 , ( V_119 == V_122 ) ? V_131 : V_132 ) ) {
F_108 ( V_109 ) ;
} else {
F_109 ( V_109 ) ;
F_110 ( V_70 >> 9 , & V_2 -> V_133 ) ;
}
}
static int F_111 ( struct V_1 * V_2 , const unsigned int V_14 , unsigned V_134 ) __must_hold( T_4 )
{
struct V_104 * V_105 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_135 , V_41 , V_136 = 0 ;
unsigned long V_137 ;
char V_138 [ 10 ] ;
int V_90 = 0 ;
V_105 = F_112 ( sizeof( struct V_104 ) , V_48 ) ;
if ( ! V_105 )
return - V_54 ;
* V_105 = (struct V_104 ) {
. V_2 = V_2 ,
. V_139 = V_140 ,
. V_116 = F_113 ( 1 ) ,
. V_117 = 0 ,
. V_14 = V_14 ,
. error = 0 ,
. V_103 = F_114 ( 2 ) ,
} ;
if ( ! F_86 ( V_2 , V_141 ) ) {
F_3 ( V_2 , L_21 ) ;
F_60 ( V_105 ) ;
return - V_142 ;
}
if ( 0 == ( V_105 -> V_14 & ~ V_120 ) )
F_53 ( ! ( V_17 & V_5 -> V_18 ) ) ;
F_75 ( & V_2 -> V_106 -> V_107 ) ;
F_115 ( & V_105 -> V_108 , & V_2 -> V_143 ) ;
F_76 ( & V_2 -> V_106 -> V_107 ) ;
V_135 = V_5 -> V_30 ;
V_137 = V_140 ;
if ( V_14 & V_120 ) {
for ( V_41 = 0 ; V_41 < V_135 ; V_41 ++ ) {
F_116 ( & V_105 -> V_116 ) ;
F_102 ( V_105 , V_41 ) ;
++ V_136 ;
F_67 () ;
}
} else if ( V_14 & V_144 ) {
unsigned int V_145 ;
for ( V_145 = 0 ; V_145 < V_5 -> V_29 ; V_145 ++ ) {
V_41 = V_5 -> V_31 [ V_145 ] ;
if ( V_41 >= V_135 )
continue;
if ( ! F_117 ( V_32 ,
& F_15 ( V_5 -> V_24 [ V_41 ] ) ) )
continue;
if ( F_29 ( V_5 -> V_24 [ V_41 ] ) )
continue;
F_116 ( & V_105 -> V_116 ) ;
F_102 ( V_105 , V_41 ) ;
++ V_136 ;
}
} else {
for ( V_41 = 0 ; V_41 < V_135 ; V_41 ++ ) {
if ( V_134 && V_41 == V_134 )
break;
if ( ! ( V_14 & V_146 ) &&
F_29 ( V_5 -> V_24 [ V_41 ] ) ) {
F_97 ( V_2 , L_22 , V_41 ) ;
continue;
}
if ( V_134 &&
! F_33 ( V_5 -> V_24 [ V_41 ] ) ) {
F_97 ( V_2 , L_23 , V_41 ) ;
continue;
}
F_116 ( & V_105 -> V_116 ) ;
F_102 ( V_105 , V_41 ) ;
++ V_136 ;
F_67 () ;
}
}
if ( ! F_100 ( & V_105 -> V_116 ) )
F_118 ( V_2 , V_2 -> V_76 , & V_105 -> V_117 ) ;
else
F_101 ( & V_105 -> V_103 , & F_93 ) ;
if ( V_14 == 0 ) {
unsigned int V_147 = F_119 ( V_140 - V_137 ) ;
if ( V_147 > 5 ) {
F_74 ( V_2 , L_24 ,
( V_14 & V_120 ) ? L_25 : L_26 ,
V_136 , V_147 ) ;
}
}
if ( V_105 -> error ) {
F_120 ( V_2 , L_27 ) ;
F_121 ( V_2 , 1 , V_148 ) ;
V_90 = - V_149 ;
}
if ( F_122 ( & V_105 -> V_116 ) )
V_90 = - V_149 ;
V_137 = V_140 ;
if ( V_14 & V_120 ) {
V_5 -> V_93 = F_65 ( V_5 ) ;
F_74 ( V_2 , L_28 ,
V_140 - V_137 ) ;
}
V_137 = V_5 -> V_93 ;
if ( ( V_14 & ~ V_120 ) == 0 )
F_74 ( V_2 , L_29 ,
F_123 ( V_138 , V_137 << ( V_150 - 10 ) ) , V_137 ) ;
F_101 ( & V_105 -> V_103 , & F_93 ) ;
return V_90 ;
}
int F_124 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_111 ( V_2 , V_120 , 0 ) ;
}
int F_125 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_111 ( V_2 , 0 , 0 ) ;
}
int F_126 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_111 ( V_2 , V_146 , 0 ) ;
}
int F_127 ( struct V_1 * V_2 , unsigned V_151 ) __must_hold( T_4 )
{
return F_111 ( V_2 , V_113 , V_151 ) ;
}
int F_128 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_111 ( V_2 , V_113 , 0 ) ;
}
int F_129 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_111 ( V_2 , V_144 | V_113 , 0 ) ;
}
static unsigned long F_130 ( struct V_1 * V_2 , unsigned long V_152 ,
const int V_153 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_38 ;
unsigned long V_154 ;
unsigned V_41 ;
if ( V_152 > V_5 -> V_61 ) {
F_3 ( V_2 , L_30 , V_152 , V_5 -> V_61 ) ;
V_152 = V_155 ;
} else {
while ( V_152 < V_5 -> V_61 ) {
V_154 = V_152 & ~ V_62 ;
V_38 = F_37 ( V_5 , F_36 ( V_5 , V_152 ) ) ;
if ( V_153 )
V_41 = F_131 ( V_38 ,
V_97 * 8 , V_152 & V_62 ) ;
else
V_41 = F_132 ( V_38 ,
V_97 * 8 , V_152 & V_62 ) ;
F_40 ( V_38 ) ;
if ( V_41 < V_97 * 8 ) {
V_152 = V_154 + V_41 ;
if ( V_152 >= V_5 -> V_61 )
break;
goto V_156;
}
V_152 = V_154 + V_97 * 8 ;
}
V_152 = V_155 ;
}
V_156:
return V_152 ;
}
static unsigned long F_133 ( struct V_1 * V_2 ,
unsigned long V_152 , const int V_153 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_41 = V_155 ;
if ( ! F_58 ( V_5 ) )
return V_41 ;
if ( ! F_58 ( V_5 -> V_24 ) )
return V_41 ;
F_75 ( & V_5 -> V_55 ) ;
if ( V_157 & V_5 -> V_18 )
F_134 ( V_2 ) ;
V_41 = F_130 ( V_2 , V_152 , V_153 ) ;
F_76 ( & V_5 -> V_55 ) ;
return V_41 ;
}
unsigned long F_135 ( struct V_1 * V_2 , unsigned long V_152 )
{
return F_133 ( V_2 , V_152 , 0 ) ;
}
unsigned long F_136 ( struct V_1 * V_2 , unsigned long V_152 )
{
return F_130 ( V_2 , V_152 , 0 ) ;
}
unsigned long F_137 ( struct V_1 * V_2 , unsigned long V_152 )
{
return F_130 ( V_2 , V_152 , 1 ) ;
}
static int F_138 ( struct V_1 * V_2 , const unsigned long V_99 ,
unsigned long V_158 , int V_159 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_38 = NULL ;
unsigned long V_37 ;
unsigned int V_160 = - 1U ;
int V_69 = 0 ;
int V_161 = 0 ;
if ( V_158 >= V_5 -> V_61 ) {
F_3 ( V_2 , L_31 ,
V_99 , V_158 , V_5 -> V_61 ) ;
V_158 = V_5 -> V_61 ? V_5 -> V_61 - 1 : 0 ;
}
for ( V_37 = V_99 ; V_37 <= V_158 ; V_37 ++ ) {
unsigned int V_22 = F_36 ( V_5 , V_37 ) ;
if ( V_22 != V_160 ) {
if ( V_38 )
F_40 ( V_38 ) ;
if ( V_69 < 0 )
F_32 ( V_5 -> V_24 [ V_160 ] ) ;
else if ( V_69 > 0 )
F_24 ( V_5 -> V_24 [ V_160 ] ) ;
V_161 += V_69 ;
V_69 = 0 ;
V_38 = F_37 ( V_5 , V_22 ) ;
V_160 = V_22 ;
}
if ( V_159 )
V_69 += ( 0 == F_139 ( V_37 & V_62 , V_38 ) ) ;
else
V_69 -= ( 0 != F_140 ( V_37 & V_62 , V_38 ) ) ;
}
if ( V_38 )
F_40 ( V_38 ) ;
if ( V_69 < 0 )
F_32 ( V_5 -> V_24 [ V_160 ] ) ;
else if ( V_69 > 0 )
F_24 ( V_5 -> V_24 [ V_160 ] ) ;
V_161 += V_69 ;
V_5 -> V_93 += V_161 ;
return V_161 ;
}
static int F_141 ( struct V_1 * V_2 , const unsigned long V_99 ,
const unsigned long V_158 , int V_159 )
{
unsigned long V_14 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_69 = 0 ;
if ( ! F_58 ( V_5 ) )
return 1 ;
if ( ! F_58 ( V_5 -> V_24 ) )
return 0 ;
F_83 ( & V_5 -> V_55 , V_14 ) ;
if ( ( V_159 ? V_162 : V_163 ) & V_5 -> V_18 )
F_134 ( V_2 ) ;
V_69 = F_138 ( V_2 , V_99 , V_158 , V_159 ) ;
F_84 ( & V_5 -> V_55 , V_14 ) ;
return V_69 ;
}
int F_142 ( struct V_1 * V_2 , const unsigned long V_99 , const unsigned long V_158 )
{
return F_141 ( V_2 , V_99 , V_158 , 1 ) ;
}
int F_143 ( struct V_1 * V_2 , const unsigned long V_99 , const unsigned long V_158 )
{
return - F_141 ( V_2 , V_99 , V_158 , 0 ) ;
}
static inline void F_144 ( struct V_4 * V_5 ,
int V_22 , int V_164 , int V_66 )
{
int V_41 ;
int V_65 ;
int V_165 = 0 ;
unsigned long * V_166 = F_38 ( V_5 -> V_24 [ V_22 ] ) ;
for ( V_41 = V_164 ; V_41 < V_66 ; V_41 ++ ) {
V_65 = F_63 ( V_166 [ V_41 ] ) ;
V_166 [ V_41 ] = ~ 0UL ;
V_165 += V_64 - V_65 ;
}
F_41 ( V_166 ) ;
if ( V_165 ) {
F_32 ( V_5 -> V_24 [ V_22 ] ) ;
V_5 -> V_93 += V_165 ;
}
}
void F_145 ( struct V_1 * V_2 , const unsigned long V_99 , const unsigned long V_158 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_167 = F_70 ( V_99 , V_64 ) ;
unsigned long V_168 = ( V_158 + 1 ) & ~ ( ( unsigned long ) V_64 - 1 ) ;
int V_169 ;
int V_170 ;
int V_22 ;
int V_164 ;
int V_66 ;
if ( V_158 - V_99 <= 3 * V_64 ) {
F_75 ( & V_5 -> V_55 ) ;
F_138 ( V_2 , V_99 , V_158 , 1 ) ;
F_76 ( & V_5 -> V_55 ) ;
return;
}
F_75 ( & V_5 -> V_55 ) ;
if ( V_167 )
F_138 ( V_2 , V_99 , V_167 - 1 , 1 ) ;
V_169 = V_167 >> ( 3 + V_35 ) ;
V_170 = V_168 >> ( 3 + V_35 ) ;
V_164 = F_71 ( V_167 >> V_36 ) ;
V_66 = V_74 ;
for ( V_22 = V_169 ; V_22 < V_170 ; V_22 ++ ) {
F_144 ( V_2 -> V_6 , V_22 , V_164 , V_66 ) ;
F_76 ( & V_5 -> V_55 ) ;
F_67 () ;
V_164 = 0 ;
F_75 ( & V_5 -> V_55 ) ;
}
V_66 = F_71 ( V_168 >> V_36 ) ;
if ( V_66 )
F_144 ( V_2 -> V_6 , V_170 , V_164 , V_66 ) ;
if ( V_168 <= V_158 )
F_138 ( V_2 , V_168 , V_158 , 1 ) ;
F_76 ( & V_5 -> V_55 ) ;
}
int F_146 ( struct V_1 * V_2 , const unsigned long V_37 )
{
unsigned long V_14 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_38 ;
int V_41 ;
if ( ! F_58 ( V_5 ) )
return 0 ;
if ( ! F_58 ( V_5 -> V_24 ) )
return 0 ;
F_83 ( & V_5 -> V_55 , V_14 ) ;
if ( V_157 & V_5 -> V_18 )
F_134 ( V_2 ) ;
if ( V_37 < V_5 -> V_61 ) {
V_38 = F_39 ( V_5 , F_36 ( V_5 , V_37 ) ) ;
V_41 = F_147 ( V_37 & V_62 , V_38 ) ? 1 : 0 ;
F_42 ( V_38 ) ;
} else if ( V_37 == V_5 -> V_61 ) {
V_41 = - 1 ;
} else {
F_3 ( V_2 , L_32 , V_37 , V_5 -> V_61 ) ;
V_41 = 0 ;
}
F_84 ( & V_5 -> V_55 , V_14 ) ;
return V_41 ;
}
int F_148 ( struct V_1 * V_2 , const unsigned long V_99 , const unsigned long V_158 )
{
unsigned long V_14 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_38 = NULL ;
unsigned long V_37 ;
unsigned int V_22 = - 1U ;
int V_69 = 0 ;
if ( ! F_58 ( V_5 ) )
return 1 ;
if ( ! F_58 ( V_5 -> V_24 ) )
return 1 ;
F_83 ( & V_5 -> V_55 , V_14 ) ;
if ( V_157 & V_5 -> V_18 )
F_134 ( V_2 ) ;
for ( V_37 = V_99 ; V_37 <= V_158 ; V_37 ++ ) {
unsigned int V_20 = F_36 ( V_5 , V_37 ) ;
if ( V_22 != V_20 ) {
V_22 = V_20 ;
if ( V_38 )
F_42 ( V_38 ) ;
V_38 = F_39 ( V_5 , V_20 ) ;
}
if ( F_58 ( V_37 < V_5 -> V_61 ) )
V_69 += ( 0 != F_147 ( V_37 - ( V_22 << ( V_35 + 3 ) ) , V_38 ) ) ;
else
F_3 ( V_2 , L_33 , V_37 , V_5 -> V_61 ) ;
}
if ( V_38 )
F_42 ( V_38 ) ;
F_84 ( & V_5 -> V_55 , V_14 ) ;
return V_69 ;
}
int F_149 ( struct V_1 * V_2 , unsigned long V_171 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_136 , V_99 , V_158 ;
unsigned long V_14 ;
unsigned long * V_38 , * V_58 ;
if ( ! F_58 ( V_5 ) )
return 0 ;
if ( ! F_58 ( V_5 -> V_24 ) )
return 0 ;
F_83 ( & V_5 -> V_55 , V_14 ) ;
if ( V_157 & V_5 -> V_18 )
F_134 ( V_2 ) ;
V_99 = F_150 ( V_171 ) ;
V_158 = F_151 ( ( T_3 ) F_150 ( V_171 + 1 ) , V_5 -> V_73 ) ;
V_136 = 0 ;
if ( V_99 < V_5 -> V_73 ) {
int V_172 = V_158 - V_99 ;
V_38 = F_39 ( V_5 , F_35 ( V_5 , V_99 ) ) ;
V_58 = V_38 + F_71 ( V_99 ) ;
V_136 += F_66 ( V_58 , V_172 * V_64 ) ;
F_42 ( V_38 ) ;
} else {
F_3 ( V_2 , L_34 , V_99 ) ;
}
F_84 ( & V_5 -> V_55 , V_14 ) ;
return V_136 ;
}
