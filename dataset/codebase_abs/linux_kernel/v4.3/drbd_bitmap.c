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
void F_26 ( struct V_1 * V_2 , int V_22 )
{
struct V_19 * V_19 ;
if ( V_22 >= V_2 -> V_6 -> V_29 ) {
F_7 ( V_2 , L_8 ,
V_22 , ( int ) V_2 -> V_6 -> V_29 ) ;
return;
}
V_19 = V_2 -> V_6 -> V_24 [ V_22 ] ;
F_25 ( V_30 , & F_15 ( V_19 ) ) ;
}
static int F_27 ( struct V_19 * V_19 )
{
volatile const unsigned long * V_23 = & F_15 ( V_19 ) ;
return ( * V_23 & ( ( 1UL << V_27 ) | ( 1UL << V_28 ) ) ) == 0 ;
}
static void F_28 ( struct V_19 * V_19 )
{
F_25 ( V_31 , & F_15 ( V_19 ) ) ;
}
static void F_29 ( struct V_19 * V_19 )
{
F_23 ( V_31 , & F_15 ( V_19 ) ) ;
}
static void F_30 ( struct V_19 * V_19 )
{
F_25 ( V_28 , & F_15 ( V_19 ) ) ;
}
static int F_31 ( struct V_19 * V_19 )
{
return F_32 ( V_28 , & F_15 ( V_19 ) ) ;
}
static unsigned int F_33 ( struct V_4 * V_5 , unsigned long V_32 )
{
unsigned int V_22 = V_32 >> ( V_33 - V_34 + 3 ) ;
F_12 ( V_22 >= V_5 -> V_29 ) ;
return V_22 ;
}
static unsigned int F_34 ( struct V_4 * V_5 , T_1 V_35 )
{
unsigned int V_22 = V_35 >> ( V_33 + 3 ) ;
F_12 ( V_22 >= V_5 -> V_29 ) ;
return V_22 ;
}
static unsigned long * F_35 ( struct V_4 * V_5 , unsigned int V_20 )
{
struct V_19 * V_19 = V_5 -> V_24 [ V_20 ] ;
return ( unsigned long * ) F_36 ( V_19 ) ;
}
static unsigned long * F_37 ( struct V_4 * V_5 , unsigned int V_20 )
{
return F_35 ( V_5 , V_20 ) ;
}
static void F_38 ( unsigned long * V_36 )
{
F_39 ( V_36 ) ;
}
static void F_40 ( unsigned long * V_36 )
{
return F_38 ( V_36 ) ;
}
static void F_41 ( struct V_19 * * V_37 , unsigned long V_38 )
{
unsigned long V_39 ;
if ( ! V_37 )
return;
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ ) {
if ( ! V_37 [ V_39 ] ) {
F_42 ( L_9 ,
V_39 , V_38 ) ;
continue;
}
F_43 ( V_37 [ V_39 ] ) ;
V_37 [ V_39 ] = NULL ;
}
}
static void F_44 ( void * V_40 , int V_41 )
{
if ( V_41 )
F_45 ( V_40 ) ;
else
F_46 ( V_40 ) ;
}
static struct V_19 * * F_47 ( struct V_4 * V_5 , unsigned long V_42 )
{
struct V_19 * * V_43 = V_5 -> V_24 ;
struct V_19 * * V_44 , * V_19 ;
unsigned int V_39 , V_45 , V_46 = 0 ;
unsigned long V_47 = V_5 -> V_29 ;
F_12 ( V_47 == 0 && V_43 != NULL ) ;
F_12 ( V_47 != 0 && V_43 == NULL ) ;
if ( V_47 == V_42 )
return V_43 ;
V_45 = sizeof( struct V_19 * ) * V_42 ;
V_44 = F_48 ( V_45 , V_48 | V_49 ) ;
if ( ! V_44 ) {
V_44 = F_49 ( V_45 ,
V_48 | V_50 | V_51 ,
V_52 ) ;
if ( ! V_44 )
return NULL ;
V_46 = 1 ;
}
if ( V_42 >= V_47 ) {
for ( V_39 = 0 ; V_39 < V_47 ; V_39 ++ )
V_44 [ V_39 ] = V_43 [ V_39 ] ;
for (; V_39 < V_42 ; V_39 ++ ) {
V_19 = F_50 ( V_48 | V_50 ) ;
if ( ! V_19 ) {
F_41 ( V_44 + V_47 , V_39 - V_47 ) ;
F_44 ( V_44 , V_46 ) ;
return NULL ;
}
F_11 ( V_19 , V_39 ) ;
V_44 [ V_39 ] = V_19 ;
}
} else {
for ( V_39 = 0 ; V_39 < V_42 ; V_39 ++ )
V_44 [ V_39 ] = V_43 [ V_39 ] ;
}
if ( V_46 )
V_5 -> V_18 |= V_53 ;
else
V_5 -> V_18 &= ~ V_53 ;
return V_44 ;
}
int F_51 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_52 ( V_5 != NULL ) ;
V_5 = F_48 ( sizeof( struct V_4 ) , V_54 ) ;
if ( ! V_5 )
return - V_55 ;
F_53 ( & V_5 -> V_56 ) ;
F_54 ( & V_5 -> V_16 ) ;
F_55 ( & V_5 -> V_25 ) ;
V_2 -> V_6 = V_5 ;
return 0 ;
}
T_2 F_56 ( struct V_1 * V_2 )
{
if ( ! F_57 ( V_2 -> V_6 ) )
return 0 ;
return V_2 -> V_6 -> V_57 ;
}
void F_58 ( struct V_1 * V_2 )
{
if ( ! F_57 ( V_2 -> V_6 ) )
return;
F_41 ( V_2 -> V_6 -> V_24 , V_2 -> V_6 -> V_29 ) ;
F_44 ( V_2 -> V_6 -> V_24 , ( V_53 & V_2 -> V_6 -> V_18 ) ) ;
F_46 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
static int F_59 ( struct V_4 * V_5 )
{
unsigned long V_58 ;
unsigned long * V_36 , * V_59 ;
int V_60 ;
int V_61 = 0 ;
V_60 = ( V_5 -> V_62 & V_63 ) ;
V_58 = ( 1UL << ( V_60 & V_64 ) ) - 1 ;
V_58 = F_60 ( V_58 ) ;
V_36 = F_37 ( V_5 , V_5 -> V_29 - 1 ) ;
V_59 = V_36 + ( V_60 / V_65 ) ;
if ( V_58 ) {
V_61 = F_61 ( * V_59 & ~ V_58 ) ;
* V_59 &= V_58 ;
V_59 ++ ;
}
if ( V_65 == 32 && ( ( V_59 - V_36 ) & 1 ) == 1 ) {
V_61 += F_61 ( * V_59 ) ;
* V_59 = 0 ;
}
F_40 ( V_36 ) ;
return V_61 ;
}
static void F_62 ( struct V_4 * V_5 )
{
unsigned long V_58 ;
unsigned long * V_36 , * V_59 ;
int V_60 ;
V_60 = ( V_5 -> V_62 & V_63 ) ;
V_58 = ( 1UL << ( V_60 & V_64 ) ) - 1 ;
V_58 = F_60 ( V_58 ) ;
V_36 = F_37 ( V_5 , V_5 -> V_29 - 1 ) ;
V_59 = V_36 + ( V_60 / V_65 ) ;
if ( V_58 ) {
* V_59 |= ~ V_58 ;
V_59 ++ ;
}
if ( V_65 == 32 && ( ( V_59 - V_36 ) & 1 ) == 1 ) {
* V_59 = ~ 0UL ;
}
F_40 ( V_36 ) ;
}
static unsigned long F_63 ( struct V_4 * V_5 )
{
unsigned long * V_36 ;
unsigned long V_66 = 0 ;
unsigned long V_58 = ( 1UL << ( V_5 -> V_62 & V_64 ) ) - 1 ;
int V_20 , V_39 , V_67 ;
for ( V_20 = 0 ; V_20 < V_5 -> V_29 - 1 ; V_20 ++ ) {
V_36 = F_35 ( V_5 , V_20 ) ;
for ( V_39 = 0 ; V_39 < V_68 ; V_39 ++ )
V_66 += F_61 ( V_36 [ V_39 ] ) ;
F_38 ( V_36 ) ;
F_64 () ;
}
V_67 = ( ( V_5 -> V_62 - 1 ) & V_63 ) >> V_34 ;
V_36 = F_35 ( V_5 , V_20 ) ;
for ( V_39 = 0 ; V_39 < V_67 ; V_39 ++ )
V_66 += F_61 ( V_36 [ V_39 ] ) ;
V_36 [ V_67 ] &= F_60 ( V_58 ) ;
V_66 += F_61 ( V_36 [ V_67 ] ) ;
if ( V_65 == 32 && ( V_67 & 1 ) == 0 )
V_36 [ V_67 + 1 ] = 0 ;
F_38 ( V_36 ) ;
return V_66 ;
}
static void F_65 ( struct V_4 * V_5 , T_3 V_69 , int V_70 , T_3 V_71 )
{
unsigned long * V_36 , * V_59 ;
unsigned int V_20 ;
T_3 V_72 , V_73 ;
V_73 = V_69 + V_71 ;
if ( V_73 > V_5 -> V_74 ) {
F_42 ( L_10 ) ;
return;
}
while ( V_69 < V_73 ) {
V_72 = F_66 ( T_3 , F_67 ( V_69 + 1 , V_68 ) , V_73 ) - V_69 ;
V_20 = F_33 ( V_5 , V_69 ) ;
V_36 = F_37 ( V_5 , V_20 ) ;
V_59 = V_36 + F_68 ( V_69 ) ;
if ( V_59 + V_72 > V_36 + V_68 ) {
F_42 ( L_11 ,
V_36 , V_59 , ( int ) V_72 ) ;
} else
memset ( V_59 , V_70 , V_72 * sizeof( long ) ) ;
F_40 ( V_36 ) ;
F_24 ( V_5 -> V_24 [ V_20 ] ) ;
V_69 += V_72 ;
}
}
static T_1 F_69 ( struct V_75 * V_76 )
{
T_1 V_77 ;
if ( V_76 -> V_78 . V_79 == 8 )
V_77 = V_76 -> V_78 . V_80 - V_76 -> V_78 . V_81 ;
else
V_77 = V_76 -> V_78 . V_79 - V_76 -> V_78 . V_81 ;
return V_77 << ( 9 + 3 ) ;
}
int F_70 ( struct V_1 * V_2 , T_2 V_82 , int V_83 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_66 , V_84 , V_85 , V_86 ;
unsigned long V_42 , V_47 , V_87 ;
struct V_19 * * V_88 , * * V_89 = NULL ;
int V_90 = 0 , V_91 ;
int V_92 ;
if ( ! F_57 ( V_5 ) )
return - V_55 ;
F_5 ( V_2 , L_12 , V_17 ) ;
F_71 ( V_2 , L_13 ,
( unsigned long long ) V_82 ) ;
if ( V_82 == V_5 -> V_57 )
goto V_93;
V_92 = ( V_53 & V_5 -> V_18 ) ;
if ( V_82 == 0 ) {
F_72 ( & V_5 -> V_56 ) ;
V_89 = V_5 -> V_24 ;
V_87 = V_5 -> V_29 ;
V_85 = V_5 -> V_74 ;
V_5 -> V_24 = NULL ;
V_5 -> V_29 =
V_5 -> V_94 =
V_5 -> V_62 =
V_5 -> V_74 =
V_5 -> V_57 = 0 ;
F_73 ( & V_5 -> V_56 ) ;
F_41 ( V_89 , V_87 ) ;
F_44 ( V_89 , V_92 ) ;
goto V_93;
}
V_66 = F_74 ( F_67 ( V_82 , V_95 ) ) ;
V_84 = F_67 ( V_66 , 64 ) >> V_34 ;
if ( F_75 ( V_2 ) ) {
T_1 V_96 = F_69 ( V_2 -> V_76 ) ;
F_76 ( V_2 ) ;
if ( V_66 > V_96 ) {
F_71 ( V_2 , L_14 , V_66 ) ;
F_71 ( V_2 , L_15 , V_96 ) ;
V_90 = - V_97 ;
goto V_93;
}
}
V_42 = F_67 ( V_84 * sizeof( long ) , V_98 ) >> V_33 ;
V_47 = V_5 -> V_29 ;
if ( V_42 == V_47 ) {
F_77 ( V_2 , V_5 -> V_24 != NULL ) ;
V_88 = V_5 -> V_24 ;
} else {
if ( F_78 ( V_2 , V_99 ) )
V_88 = NULL ;
else
V_88 = F_47 ( V_5 , V_42 ) ;
}
if ( ! V_88 ) {
V_90 = - V_55 ;
goto V_93;
}
F_72 ( & V_5 -> V_56 ) ;
V_89 = V_5 -> V_24 ;
V_85 = V_5 -> V_74 ;
V_86 = V_5 -> V_62 ;
V_91 = V_66 > V_86 ;
if ( V_89 && V_91 && V_83 )
F_62 ( V_5 ) ;
V_5 -> V_24 = V_88 ;
V_5 -> V_29 = V_42 ;
V_5 -> V_62 = V_66 ;
V_5 -> V_74 = V_84 ;
V_5 -> V_57 = V_82 ;
if ( V_91 ) {
if ( V_83 ) {
F_65 ( V_5 , V_85 , 0xff , V_84 - V_85 ) ;
V_5 -> V_94 += V_66 - V_86 ;
} else
F_65 ( V_5 , V_85 , 0x00 , V_84 - V_85 ) ;
}
if ( V_42 < V_47 ) {
F_41 ( V_89 + V_42 , V_47 - V_42 ) ;
}
( void ) F_59 ( V_5 ) ;
F_73 ( & V_5 -> V_56 ) ;
if ( V_89 != V_88 )
F_44 ( V_89 , V_92 ) ;
if ( ! V_91 )
V_5 -> V_94 = F_63 ( V_5 ) ;
F_71 ( V_2 , L_16 , V_66 , V_84 , V_42 ) ;
V_93:
F_9 ( V_2 ) ;
return V_90 ;
}
unsigned long F_79 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_100 ;
unsigned long V_14 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
if ( ! F_57 ( V_5 -> V_24 ) )
return 0 ;
F_80 ( & V_5 -> V_56 , V_14 ) ;
V_100 = V_5 -> V_94 ;
F_81 ( & V_5 -> V_56 , V_14 ) ;
return V_100 ;
}
unsigned long F_82 ( struct V_1 * V_2 )
{
unsigned long V_100 ;
if ( ! F_83 ( V_2 , V_101 ) )
return 0 ;
V_100 = F_79 ( V_2 ) ;
F_76 ( V_2 ) ;
return V_100 ;
}
T_3 F_84 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
if ( ! F_57 ( V_5 -> V_24 ) )
return 0 ;
return V_5 -> V_74 ;
}
unsigned long F_85 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
return V_5 -> V_62 ;
}
void F_86 ( struct V_1 * V_2 , T_3 V_69 , T_3 V_38 ,
unsigned long * V_102 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 , * V_59 ;
unsigned long V_103 , V_66 ;
unsigned int V_20 ;
T_3 V_73 , V_72 ;
V_73 = V_69 + V_38 ;
if ( ! F_57 ( V_5 ) )
return;
if ( ! F_57 ( V_5 -> V_24 ) )
return;
if ( V_38 == 0 )
return;
F_52 ( V_69 >= V_5 -> V_74 ) ;
F_52 ( V_73 > V_5 -> V_74 ) ;
F_72 ( & V_5 -> V_56 ) ;
while ( V_69 < V_73 ) {
V_72 = F_66 ( T_3 , F_67 ( V_69 + 1 , V_68 ) , V_73 ) - V_69 ;
V_20 = F_33 ( V_5 , V_69 ) ;
V_36 = F_37 ( V_5 , V_20 ) ;
V_59 = V_36 + F_68 ( V_69 ) ;
V_69 += V_72 ;
while ( V_72 -- ) {
V_66 = F_61 ( * V_59 ) ;
V_103 = * V_59 | * V_102 ++ ;
* V_59 ++ = V_103 ;
V_5 -> V_94 += F_61 ( V_103 ) - V_66 ;
}
F_40 ( V_36 ) ;
F_24 ( V_5 -> V_24 [ V_20 ] ) ;
}
if ( V_73 == V_5 -> V_74 )
V_5 -> V_94 -= F_59 ( V_5 ) ;
F_73 ( & V_5 -> V_56 ) ;
}
void F_87 ( struct V_1 * V_2 , T_3 V_69 , T_3 V_38 ,
unsigned long * V_102 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 , * V_59 ;
T_3 V_73 , V_72 ;
V_73 = V_69 + V_38 ;
if ( ! F_57 ( V_5 ) )
return;
if ( ! F_57 ( V_5 -> V_24 ) )
return;
F_72 ( & V_5 -> V_56 ) ;
if ( ( V_69 >= V_5 -> V_74 ) ||
( V_73 > V_5 -> V_74 ) ||
( V_38 <= 0 ) )
F_3 ( V_2 , L_17 ,
( unsigned long ) V_69 ,
( unsigned long ) V_38 ,
( unsigned long ) V_5 -> V_74 ) ;
else {
while ( V_69 < V_73 ) {
V_72 = F_66 ( T_3 , F_67 ( V_69 + 1 , V_68 ) , V_73 ) - V_69 ;
V_36 = F_37 ( V_5 , F_33 ( V_5 , V_69 ) ) ;
V_59 = V_36 + F_68 ( V_69 ) ;
V_69 += V_72 ;
while ( V_72 -- )
* V_102 ++ = * V_59 ++ ;
F_40 ( V_36 ) ;
}
}
F_73 ( & V_5 -> V_56 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_57 ( V_5 ) )
return;
if ( ! F_57 ( V_5 -> V_24 ) )
return;
F_72 ( & V_5 -> V_56 ) ;
F_65 ( V_5 , 0 , 0xff , V_5 -> V_74 ) ;
( void ) F_59 ( V_5 ) ;
V_5 -> V_94 = V_5 -> V_62 ;
F_73 ( & V_5 -> V_56 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_57 ( V_5 ) )
return;
if ( ! F_57 ( V_5 -> V_24 ) )
return;
F_72 ( & V_5 -> V_56 ) ;
F_65 ( V_5 , 0 , 0 , V_5 -> V_74 ) ;
V_5 -> V_94 = 0 ;
F_73 ( & V_5 -> V_56 ) ;
}
static void F_90 ( struct V_104 * V_104 )
{
struct V_105 * V_106 = F_91 ( V_104 , struct V_105 , V_104 ) ;
unsigned long V_14 ;
F_80 ( & V_106 -> V_2 -> V_107 -> V_108 , V_14 ) ;
F_92 ( & V_106 -> V_109 ) ;
F_81 ( & V_106 -> V_2 -> V_107 -> V_108 , V_14 ) ;
F_76 ( V_106 -> V_2 ) ;
F_46 ( V_106 ) ;
}
static void F_93 ( struct V_110 * V_110 )
{
struct V_105 * V_106 = V_110 -> V_111 ;
struct V_1 * V_2 = V_106 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_20 = F_14 ( V_110 -> V_112 [ 0 ] . V_113 ) ;
if ( ( V_106 -> V_14 & V_114 ) == 0 &&
! F_27 ( V_5 -> V_24 [ V_20 ] ) )
F_7 ( V_2 , L_18 , V_20 ) ;
if ( V_110 -> V_115 ) {
V_106 -> error = V_110 -> V_115 ;
F_28 ( V_5 -> V_24 [ V_20 ] ) ;
if ( F_2 ( & V_7 ) )
F_3 ( V_2 , L_19 ,
V_110 -> V_115 , V_20 ) ;
} else {
F_29 ( V_5 -> V_24 [ V_20 ] ) ;
F_94 ( V_2 , L_20 , V_20 ) ;
}
F_19 ( V_2 , V_20 ) ;
if ( V_106 -> V_14 & V_114 )
F_95 ( V_110 -> V_112 [ 0 ] . V_113 , V_116 ) ;
F_96 ( V_110 ) ;
if ( F_97 ( & V_106 -> V_117 ) ) {
V_106 -> V_118 = 1 ;
F_21 ( & V_2 -> V_119 ) ;
F_98 ( & V_106 -> V_104 , & F_90 ) ;
}
}
static void F_99 ( struct V_105 * V_106 , int V_22 ) __must_hold( T_4 )
{
struct V_110 * V_110 = F_100 ( V_48 ) ;
struct V_1 * V_2 = V_106 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_19 * V_19 ;
unsigned int V_71 ;
unsigned int V_120 = ( V_106 -> V_14 & V_121 ) ? V_122 : V_123 ;
T_2 V_124 =
V_2 -> V_76 -> V_78 . V_125 + V_2 -> V_76 -> V_78 . V_81 ;
V_124 += ( ( T_2 ) V_22 ) << ( V_33 - 9 ) ;
V_71 = F_66 (unsigned int, PAGE_SIZE,
(drbd_md_last_sector(device->ldev) - on_disk_sector + 1)<<9 ) ;
F_16 ( V_2 , V_22 ) ;
F_22 ( V_5 -> V_24 [ V_22 ] ) ;
if ( V_106 -> V_14 & V_114 ) {
V_19 = F_101 ( V_116 , V_50 | V_126 ) ;
F_102 ( V_19 , V_5 -> V_24 [ V_22 ] ) ;
F_11 ( V_19 , V_22 ) ;
} else
V_19 = V_5 -> V_24 [ V_22 ] ;
V_110 -> V_127 = V_2 -> V_76 -> V_128 ;
V_110 -> V_129 . V_130 = V_124 ;
F_103 ( V_110 , V_19 , V_71 , 0 ) ;
V_110 -> V_111 = V_106 ;
V_110 -> V_131 = F_93 ;
if ( F_78 ( V_2 , ( V_120 & V_123 ) ? V_132 : V_133 ) ) {
V_110 -> V_134 |= V_120 ;
F_104 ( V_110 ) ;
} else {
F_105 ( V_120 , V_110 ) ;
F_106 ( V_71 >> 9 , & V_2 -> V_135 ) ;
}
}
static int F_107 ( struct V_1 * V_2 , const unsigned int V_14 , unsigned V_136 ) __must_hold( T_4 )
{
struct V_105 * V_106 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_137 , V_39 , V_138 = 0 ;
unsigned long V_139 ;
char V_140 [ 10 ] ;
int V_90 = 0 ;
V_106 = F_108 ( sizeof( struct V_105 ) , V_48 ) ;
if ( ! V_106 )
return - V_55 ;
* V_106 = (struct V_105 ) {
. V_2 = V_2 ,
. V_141 = V_142 ,
. V_117 = F_109 ( 1 ) ,
. V_118 = 0 ,
. V_14 = V_14 ,
. error = 0 ,
. V_104 = { F_109 ( 2 ) } ,
} ;
if ( ! F_83 ( V_2 , V_143 ) ) {
F_3 ( V_2 , L_21 ) ;
F_46 ( V_106 ) ;
return - V_144 ;
}
if ( 0 == ( V_106 -> V_14 & ~ V_121 ) )
F_52 ( ! ( V_17 & V_5 -> V_18 ) ) ;
F_72 ( & V_2 -> V_107 -> V_108 ) ;
F_110 ( & V_106 -> V_109 , & V_2 -> V_145 ) ;
F_73 ( & V_2 -> V_107 -> V_108 ) ;
V_137 = V_5 -> V_29 ;
V_139 = V_142 ;
for ( V_39 = 0 ; V_39 < V_137 ; V_39 ++ ) {
if ( V_136 && V_39 == V_136 )
break;
if ( ! ( V_14 & V_121 ) ) {
if ( ( V_14 & V_146 ) &&
! F_111 ( V_30 ,
& F_15 ( V_5 -> V_24 [ V_39 ] ) ) )
continue;
if ( ! ( V_14 & V_147 ) &&
F_27 ( V_5 -> V_24 [ V_39 ] ) ) {
F_94 ( V_2 , L_22 , V_39 ) ;
continue;
}
if ( V_136 &&
! F_31 ( V_5 -> V_24 [ V_39 ] ) ) {
F_94 ( V_2 , L_23 , V_39 ) ;
continue;
}
}
F_112 ( & V_106 -> V_117 ) ;
F_99 ( V_106 , V_39 ) ;
++ V_138 ;
F_64 () ;
}
if ( ! F_97 ( & V_106 -> V_117 ) )
F_113 ( V_2 , V_2 -> V_76 , & V_106 -> V_118 ) ;
else
F_98 ( & V_106 -> V_104 , & F_90 ) ;
if ( V_14 == 0 )
F_71 ( V_2 , L_24 ,
( V_14 & V_121 ) ? L_25 : L_26 ,
V_138 , V_142 - V_139 ) ;
if ( V_106 -> error ) {
F_114 ( V_2 , L_27 ) ;
F_115 ( V_2 , 1 , V_148 ) ;
V_90 = - V_149 ;
}
if ( F_116 ( & V_106 -> V_117 ) )
V_90 = - V_149 ;
V_139 = V_142 ;
if ( V_14 & V_121 ) {
V_5 -> V_94 = F_63 ( V_5 ) ;
F_71 ( V_2 , L_28 ,
V_142 - V_139 ) ;
}
V_139 = V_5 -> V_94 ;
if ( ( V_14 & ~ V_121 ) == 0 )
F_71 ( V_2 , L_29 ,
F_117 ( V_140 , V_139 << ( V_150 - 10 ) ) , V_139 ) ;
F_98 ( & V_106 -> V_104 , & F_90 ) ;
return V_90 ;
}
int F_118 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_107 ( V_2 , V_121 , 0 ) ;
}
int F_119 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_107 ( V_2 , 0 , 0 ) ;
}
int F_120 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_107 ( V_2 , V_147 , 0 ) ;
}
int F_121 ( struct V_1 * V_2 , unsigned V_151 ) __must_hold( T_4 )
{
return F_107 ( V_2 , V_114 , V_151 ) ;
}
int F_122 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_107 ( V_2 , V_114 , 0 ) ;
}
int F_123 ( struct V_1 * V_2 ) __must_hold( T_4 )
{
return F_107 ( V_2 , V_146 | V_114 , 0 ) ;
}
static unsigned long F_124 ( struct V_1 * V_2 , unsigned long V_152 ,
const int V_153 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 ;
unsigned long V_154 ;
unsigned V_39 ;
if ( V_152 > V_5 -> V_62 ) {
F_3 ( V_2 , L_30 , V_152 , V_5 -> V_62 ) ;
V_152 = V_155 ;
} else {
while ( V_152 < V_5 -> V_62 ) {
V_154 = V_152 & ~ V_63 ;
V_36 = F_35 ( V_5 , F_34 ( V_5 , V_152 ) ) ;
if ( V_153 )
V_39 = F_125 ( V_36 ,
V_98 * 8 , V_152 & V_63 ) ;
else
V_39 = F_126 ( V_36 ,
V_98 * 8 , V_152 & V_63 ) ;
F_38 ( V_36 ) ;
if ( V_39 < V_98 * 8 ) {
V_152 = V_154 + V_39 ;
if ( V_152 >= V_5 -> V_62 )
break;
goto V_156;
}
V_152 = V_154 + V_98 * 8 ;
}
V_152 = V_155 ;
}
V_156:
return V_152 ;
}
static unsigned long F_127 ( struct V_1 * V_2 ,
unsigned long V_152 , const int V_153 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_39 = V_155 ;
if ( ! F_57 ( V_5 ) )
return V_39 ;
if ( ! F_57 ( V_5 -> V_24 ) )
return V_39 ;
F_72 ( & V_5 -> V_56 ) ;
if ( V_157 & V_5 -> V_18 )
F_128 ( V_2 ) ;
V_39 = F_124 ( V_2 , V_152 , V_153 ) ;
F_73 ( & V_5 -> V_56 ) ;
return V_39 ;
}
unsigned long F_129 ( struct V_1 * V_2 , unsigned long V_152 )
{
return F_127 ( V_2 , V_152 , 0 ) ;
}
unsigned long F_130 ( struct V_1 * V_2 , unsigned long V_152 )
{
return F_124 ( V_2 , V_152 , 0 ) ;
}
unsigned long F_131 ( struct V_1 * V_2 , unsigned long V_152 )
{
return F_124 ( V_2 , V_152 , 1 ) ;
}
static int F_132 ( struct V_1 * V_2 , const unsigned long V_100 ,
unsigned long V_158 , int V_159 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 = NULL ;
unsigned long V_35 ;
unsigned int V_160 = - 1U ;
int V_70 = 0 ;
int V_161 = 0 ;
if ( V_158 >= V_5 -> V_62 ) {
F_3 ( V_2 , L_31 ,
V_100 , V_158 , V_5 -> V_62 ) ;
V_158 = V_5 -> V_62 ? V_5 -> V_62 - 1 : 0 ;
}
for ( V_35 = V_100 ; V_35 <= V_158 ; V_35 ++ ) {
unsigned int V_22 = F_34 ( V_5 , V_35 ) ;
if ( V_22 != V_160 ) {
if ( V_36 )
F_38 ( V_36 ) ;
if ( V_70 < 0 )
F_30 ( V_5 -> V_24 [ V_160 ] ) ;
else if ( V_70 > 0 )
F_24 ( V_5 -> V_24 [ V_160 ] ) ;
V_161 += V_70 ;
V_70 = 0 ;
V_36 = F_35 ( V_5 , V_22 ) ;
V_160 = V_22 ;
}
if ( V_159 )
V_70 += ( 0 == F_133 ( V_35 & V_63 , V_36 ) ) ;
else
V_70 -= ( 0 != F_134 ( V_35 & V_63 , V_36 ) ) ;
}
if ( V_36 )
F_38 ( V_36 ) ;
if ( V_70 < 0 )
F_30 ( V_5 -> V_24 [ V_160 ] ) ;
else if ( V_70 > 0 )
F_24 ( V_5 -> V_24 [ V_160 ] ) ;
V_161 += V_70 ;
V_5 -> V_94 += V_161 ;
return V_161 ;
}
static int F_135 ( struct V_1 * V_2 , const unsigned long V_100 ,
const unsigned long V_158 , int V_159 )
{
unsigned long V_14 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_70 = 0 ;
if ( ! F_57 ( V_5 ) )
return 1 ;
if ( ! F_57 ( V_5 -> V_24 ) )
return 0 ;
F_80 ( & V_5 -> V_56 , V_14 ) ;
if ( ( V_159 ? V_162 : V_163 ) & V_5 -> V_18 )
F_128 ( V_2 ) ;
V_70 = F_132 ( V_2 , V_100 , V_158 , V_159 ) ;
F_81 ( & V_5 -> V_56 , V_14 ) ;
return V_70 ;
}
int F_136 ( struct V_1 * V_2 , const unsigned long V_100 , const unsigned long V_158 )
{
return F_135 ( V_2 , V_100 , V_158 , 1 ) ;
}
int F_137 ( struct V_1 * V_2 , const unsigned long V_100 , const unsigned long V_158 )
{
return - F_135 ( V_2 , V_100 , V_158 , 0 ) ;
}
static inline void F_138 ( struct V_4 * V_5 ,
int V_22 , int V_164 , int V_67 )
{
int V_39 ;
int V_66 ;
int V_165 = 0 ;
unsigned long * V_166 = F_36 ( V_5 -> V_24 [ V_22 ] ) ;
for ( V_39 = V_164 ; V_39 < V_67 ; V_39 ++ ) {
V_66 = F_61 ( V_166 [ V_39 ] ) ;
V_166 [ V_39 ] = ~ 0UL ;
V_165 += V_65 - V_66 ;
}
F_39 ( V_166 ) ;
if ( V_165 ) {
F_30 ( V_5 -> V_24 [ V_22 ] ) ;
V_5 -> V_94 += V_165 ;
}
}
void F_139 ( struct V_1 * V_2 , const unsigned long V_100 , const unsigned long V_158 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_167 = F_67 ( V_100 , V_65 ) ;
unsigned long V_168 = ( V_158 + 1 ) & ~ ( ( unsigned long ) V_65 - 1 ) ;
int V_169 ;
int V_170 ;
int V_22 ;
int V_164 ;
int V_67 ;
if ( V_158 - V_100 <= 3 * V_65 ) {
F_72 ( & V_5 -> V_56 ) ;
F_132 ( V_2 , V_100 , V_158 , 1 ) ;
F_73 ( & V_5 -> V_56 ) ;
return;
}
F_72 ( & V_5 -> V_56 ) ;
if ( V_167 )
F_132 ( V_2 , V_100 , V_167 - 1 , 1 ) ;
V_169 = V_167 >> ( 3 + V_33 ) ;
V_170 = V_168 >> ( 3 + V_33 ) ;
V_164 = F_68 ( V_167 >> V_34 ) ;
V_67 = V_68 ;
for ( V_22 = V_169 ; V_22 < V_170 ; V_22 ++ ) {
F_138 ( V_2 -> V_6 , V_22 , V_164 , V_67 ) ;
F_73 ( & V_5 -> V_56 ) ;
F_64 () ;
V_164 = 0 ;
F_72 ( & V_5 -> V_56 ) ;
}
V_67 = F_68 ( V_168 >> V_34 ) ;
if ( V_67 )
F_138 ( V_2 -> V_6 , V_170 , V_164 , V_67 ) ;
if ( V_168 <= V_158 )
F_132 ( V_2 , V_168 , V_158 , 1 ) ;
F_73 ( & V_5 -> V_56 ) ;
}
int F_140 ( struct V_1 * V_2 , const unsigned long V_35 )
{
unsigned long V_14 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 ;
int V_39 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
if ( ! F_57 ( V_5 -> V_24 ) )
return 0 ;
F_80 ( & V_5 -> V_56 , V_14 ) ;
if ( V_157 & V_5 -> V_18 )
F_128 ( V_2 ) ;
if ( V_35 < V_5 -> V_62 ) {
V_36 = F_37 ( V_5 , F_34 ( V_5 , V_35 ) ) ;
V_39 = F_141 ( V_35 & V_63 , V_36 ) ? 1 : 0 ;
F_40 ( V_36 ) ;
} else if ( V_35 == V_5 -> V_62 ) {
V_39 = - 1 ;
} else {
F_3 ( V_2 , L_32 , V_35 , V_5 -> V_62 ) ;
V_39 = 0 ;
}
F_81 ( & V_5 -> V_56 , V_14 ) ;
return V_39 ;
}
int F_142 ( struct V_1 * V_2 , const unsigned long V_100 , const unsigned long V_158 )
{
unsigned long V_14 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long * V_36 = NULL ;
unsigned long V_35 ;
unsigned int V_22 = - 1U ;
int V_70 = 0 ;
if ( ! F_57 ( V_5 ) )
return 1 ;
if ( ! F_57 ( V_5 -> V_24 ) )
return 1 ;
F_80 ( & V_5 -> V_56 , V_14 ) ;
if ( V_157 & V_5 -> V_18 )
F_128 ( V_2 ) ;
for ( V_35 = V_100 ; V_35 <= V_158 ; V_35 ++ ) {
unsigned int V_20 = F_34 ( V_5 , V_35 ) ;
if ( V_22 != V_20 ) {
V_22 = V_20 ;
if ( V_36 )
F_40 ( V_36 ) ;
V_36 = F_37 ( V_5 , V_20 ) ;
}
if ( F_57 ( V_35 < V_5 -> V_62 ) )
V_70 += ( 0 != F_141 ( V_35 - ( V_22 << ( V_33 + 3 ) ) , V_36 ) ) ;
else
F_3 ( V_2 , L_33 , V_35 , V_5 -> V_62 ) ;
}
if ( V_36 )
F_40 ( V_36 ) ;
F_81 ( & V_5 -> V_56 , V_14 ) ;
return V_70 ;
}
int F_143 ( struct V_1 * V_2 , unsigned long V_171 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_138 , V_100 , V_158 ;
unsigned long V_14 ;
unsigned long * V_36 , * V_59 ;
if ( ! F_57 ( V_5 ) )
return 0 ;
if ( ! F_57 ( V_5 -> V_24 ) )
return 0 ;
F_80 ( & V_5 -> V_56 , V_14 ) ;
if ( V_157 & V_5 -> V_18 )
F_128 ( V_2 ) ;
V_100 = F_144 ( V_171 ) ;
V_158 = F_145 ( ( T_3 ) F_144 ( V_171 + 1 ) , V_5 -> V_74 ) ;
V_138 = 0 ;
if ( V_100 < V_5 -> V_74 ) {
int V_172 = V_158 - V_100 ;
V_36 = F_37 ( V_5 , F_33 ( V_5 , V_100 ) ) ;
V_59 = V_36 + F_68 ( V_100 ) ;
while ( V_172 -- )
V_138 += F_61 ( * V_59 ++ ) ;
F_40 ( V_36 ) ;
} else {
F_3 ( V_2 , L_34 , V_100 ) ;
}
F_81 ( & V_5 -> V_56 , V_14 ) ;
return V_138 ;
}
