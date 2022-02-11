const struct V_1 * F_1 ( void )
{
return & V_2 ;
}
static bool F_2 ( struct V_3 * V_4 ,
const int V_5 )
{
return V_4 -> V_6 -> V_7 ( V_5 ) != V_8 ;
}
static void F_3 ( struct V_3 * V_4 ,
int V_5 , int * V_9 , T_1 * V_10 ,
T_2 * V_11 , T_3 * V_12 , T_3 * V_13 ,
T_1 * V_14 )
{
void T_4 * V_15 = V_4 -> V_16 +
V_4 -> V_6 -> V_17 ( V_5 ) ;
T_2 V_18 = F_4 ( V_15 + V_19 ) ;
T_2 V_20 = F_4 ( V_15 + V_21 ) ;
if ( ! ( V_20 & V_22 ) ) {
* V_9 = 0 ;
return;
}
* V_9 = 1 ;
* V_10 = ( ( T_1 ) V_18 & V_23 ) << 32 ;
* V_10 |= ( V_18 & V_24 ) ;
* V_11 = ( V_20 | ~ V_25 ) + 1 ;
if ( V_12 )
* V_12 = ( V_20 & V_26 ) >> V_27 ;
if ( V_13 )
* V_13 = ( V_20 & V_28 ) >> V_29 ;
if ( V_14 ) {
if ( F_2 ( V_4 , V_5 ) ) {
T_2 V_30 , V_31 ;
void T_4 * V_32 = V_4 -> V_16 +
V_4 -> V_6 -> V_7 ( V_5 ) ;
V_30 = F_4 ( V_32 + V_33 ) ;
V_31 = F_4 ( V_32 + V_34 ) ;
* V_14 = ( ( T_1 ) V_31 << 32 ) | V_30 ;
} else
* V_14 = 0 ;
}
}
static void F_5 ( struct V_3 * V_4 ,
int V_5 )
{
void T_4 * V_15 ;
V_15 = V_4 -> V_16 + V_4 -> V_6 -> V_17 ( V_5 ) ;
F_6 ( 0 , V_15 + V_19 ) ;
F_6 ( 0 , V_15 + V_21 ) ;
if ( F_2 ( V_4 , V_5 ) ) {
V_15 = V_4 -> V_16 + V_4 -> V_6 -> V_7 ( V_5 ) ;
F_6 ( 0 , V_15 + V_33 ) ;
F_6 ( 0 , V_15 + V_34 ) ;
}
}
static int F_7 ( struct V_3 * V_4 ,
const int V_5 )
{
void T_4 * V_15 = V_4 -> V_16 +
V_4 -> V_6 -> V_17 ( V_5 ) ;
T_2 V_35 = F_4 ( V_15 + V_21 ) ;
return ! ( V_35 & V_22 ) ;
}
static int F_8 ( struct V_3 * V_4 ,
T_5 V_10 , T_6 V_11 ,
T_3 V_12 , T_3 V_13 )
{
T_1 V_36 = ( T_1 ) V_10 + V_11 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 -> V_37 ; V_5 ++ ) {
T_1 V_38 , V_39 ;
T_2 V_40 ;
T_3 V_41 , V_42 ;
int V_9 ;
F_3 ( V_4 , V_5 ,
& V_9 , & V_38 , & V_40 ,
& V_41 , & V_42 , NULL ) ;
if ( ! V_9 )
continue;
V_39 = V_38 + V_40 ;
if ( ( T_1 ) V_10 < V_39 && V_36 > V_38 )
return 0 ;
}
return 1 ;
}
static int F_9 ( struct V_3 * V_4 ,
T_5 V_10 , T_6 V_11 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 -> V_37 ; V_5 ++ ) {
T_1 V_38 ;
T_2 V_40 ;
int V_9 ;
F_3 ( V_4 , V_5 ,
& V_9 , & V_38 , & V_40 ,
NULL , NULL , NULL ) ;
if ( ! V_9 )
continue;
if ( V_10 == V_38 && V_11 == V_40 )
return V_5 ;
}
return - V_43 ;
}
static int F_10 ( struct V_3 * V_4 ,
int V_5 , T_5 V_10 , T_6 V_11 ,
T_5 V_14 , T_3 V_12 ,
T_3 V_13 )
{
void T_4 * V_15 = V_4 -> V_16 +
V_4 -> V_6 -> V_17 ( V_5 ) ;
T_2 V_35 , V_44 ;
if ( ! F_11 ( V_11 ) ) {
F_12 ( true , L_1 , V_11 ) ;
return - V_45 ;
}
if ( ( V_10 & ( T_5 ) ( V_11 - 1 ) ) != 0 ) {
F_12 ( true , L_2 , & V_10 ,
V_11 ) ;
return - V_45 ;
}
V_35 = ( ( V_11 - 1 ) & V_25 ) |
( V_13 << V_29 ) |
( V_12 << V_27 ) |
V_22 ;
if ( V_4 -> V_46 )
V_35 |= V_47 ;
F_6 ( V_10 & V_24 , V_15 + V_19 ) ;
F_6 ( V_35 , V_15 + V_21 ) ;
if ( F_2 ( V_4 , V_5 ) ) {
void T_4 * V_32 = V_4 -> V_16 +
V_4 -> V_6 -> V_7 ( V_5 ) ;
if ( V_14 == V_8 )
V_44 = V_10 ;
else
V_44 = V_14 ;
F_6 ( V_44 & V_48 , V_32 + V_33 ) ;
F_6 ( 0 , V_32 + V_34 ) ;
}
return 0 ;
}
static int F_13 ( struct V_3 * V_4 ,
T_5 V_10 , T_6 V_11 ,
T_5 V_14 , T_3 V_12 ,
T_3 V_13 )
{
int V_5 ;
if ( V_14 == V_8 ) {
for ( V_5 = 0 ; V_5 < V_4 -> V_6 -> V_37 ; V_5 ++ ) {
if ( F_2 ( V_4 , V_5 ) )
continue;
if ( F_7 ( V_4 , V_5 ) )
return F_10 ( V_4 , V_5 , V_10 ,
V_11 , V_14 ,
V_12 , V_13 ) ;
}
}
for ( V_5 = 0 ; V_5 < V_4 -> V_6 -> V_37 ; V_5 ++ ) {
if ( ( V_14 != V_8 ) &&
! F_2 ( V_4 , V_5 ) )
continue;
if ( F_7 ( V_4 , V_5 ) )
return F_10 ( V_4 , V_5 , V_10 , V_11 ,
V_14 , V_12 , V_13 ) ;
}
return - V_49 ;
}
static int F_14 ( struct V_3 * V_4 ,
struct V_50 * V_51 , void * V_52 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
T_2 V_18 = F_4 ( V_4 -> V_54 + F_15 ( V_53 ) ) ;
T_2 V_55 = F_4 ( V_4 -> V_54 + F_16 ( V_53 ) ) ;
T_1 V_10 ;
T_2 V_11 ;
if ( ! ( V_55 & V_56 ) ) {
F_17 ( V_51 , L_3 , V_53 ) ;
continue;
}
V_10 = ( ( T_1 ) V_18 & V_57 ) << 32 ;
V_10 |= V_18 & V_58 ;
V_11 = ( V_55 | ~ V_59 ) ;
F_17 ( V_51 , L_4 ,
V_53 , ( unsigned long long ) V_10 ,
( unsigned long long ) V_10 + V_11 + 1 ,
( V_55 & V_60 ) >> V_61 ) ;
}
return 0 ;
}
static int F_18 ( struct V_3 * V_4 ,
struct V_50 * V_51 , void * V_52 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < 2 ; V_53 ++ ) {
T_2 V_62 = F_4 ( V_4 -> V_54 + F_19 ( V_53 ) ) ;
T_1 V_10 ;
T_2 V_11 ;
if ( ! ( V_62 & 1 ) ) {
F_17 ( V_51 , L_3 , V_53 ) ;
continue;
}
V_10 = V_62 & 0xff800000 ;
V_11 = 0x100000 << ( ( ( V_62 & 0x000f0000 ) >> 16 ) - 4 ) ;
F_17 ( V_51 , L_4 ,
V_53 , ( unsigned long long ) V_10 ,
( unsigned long long ) V_10 + V_11 , V_53 ) ;
}
return 0 ;
}
static int F_20 ( struct V_50 * V_51 , void * V_52 )
{
struct V_3 * V_4 = & V_63 ;
return V_4 -> V_6 -> V_64 ( V_4 , V_51 , V_52 ) ;
}
static int F_21 ( struct V_65 * V_65 , struct V_66 * V_66 )
{
return F_22 ( V_66 , F_20 , V_65 -> V_67 ) ;
}
static int F_23 ( struct V_50 * V_51 , void * V_52 )
{
struct V_3 * V_4 = & V_63 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 -> V_37 ; V_5 ++ ) {
T_1 V_38 , V_68 ;
T_2 V_40 ;
T_3 V_41 , V_42 ;
int V_9 ;
F_3 ( V_4 , V_5 ,
& V_9 , & V_38 , & V_40 ,
& V_41 , & V_42 , & V_68 ) ;
if ( ! V_9 ) {
F_17 ( V_51 , L_5 , V_5 ) ;
continue;
}
F_17 ( V_51 , L_6 ,
V_5 , ( unsigned long long ) V_38 ,
( unsigned long long ) ( V_38 + V_40 ) , V_41 , V_42 ) ;
if ( ! F_11 ( V_40 ) ||
( ( V_38 & ( T_1 ) ( V_40 - 1 ) ) != 0 ) )
F_24 ( V_51 , L_7 ) ;
if ( F_2 ( V_4 , V_5 ) ) {
F_17 ( V_51 , L_8 ,
( unsigned long long ) V_68 ) ;
} else
F_17 ( V_51 , L_9 ) ;
}
return 0 ;
}
static int F_25 ( struct V_65 * V_65 , struct V_66 * V_66 )
{
return F_22 ( V_66 , F_23 , V_65 -> V_67 ) ;
}
static unsigned int F_26 ( int V_5 )
{
return V_5 << 4 ;
}
static unsigned int F_27 ( int V_5 )
{
if ( V_5 < 8 )
return V_5 << 4 ;
else
return 0x90 + ( ( V_5 - 8 ) << 3 ) ;
}
static unsigned int F_28 ( int V_5 )
{
if ( V_5 < 8 )
return V_5 << 4 ;
else
return 0x900 + ( ( V_5 - 8 ) << 4 ) ;
}
static unsigned int F_29 ( int V_5 )
{
if ( V_5 < 2 )
return F_26 ( V_5 ) ;
else
return V_8 ;
}
static unsigned int F_30 ( int V_5 )
{
if ( V_5 < 4 )
return F_26 ( V_5 ) ;
else
return V_8 ;
}
static unsigned int F_31 ( int V_5 )
{
if ( V_5 < 8 )
return F_26 ( V_5 ) ;
else
return V_8 ;
}
static unsigned int F_32 ( int V_5 )
{
if ( V_5 < 8 )
return F_26 ( V_5 ) ;
else if ( V_5 == 13 )
return 0xF0 - V_33 ;
else
return V_8 ;
}
static void T_7
F_33 ( struct V_3 * V_4 )
{
int V_53 ;
int V_69 ;
V_2 . V_70 = V_71 ;
for ( V_53 = 0 , V_69 = 0 ; V_53 < 4 ; V_53 ++ ) {
T_2 V_10 = F_4 ( V_4 -> V_54 + F_15 ( V_53 ) ) ;
T_2 V_11 = F_4 ( V_4 -> V_54 + F_16 ( V_53 ) ) ;
if ( ( V_11 & V_56 ) &&
! ( V_10 & V_57 ) ) {
struct V_72 * V_73 ;
V_73 = & V_2 . V_69 [ V_69 ++ ] ;
V_73 -> V_74 = V_53 ;
V_73 -> V_75 = 0xf & ~ ( 1 << V_53 ) ;
if ( V_4 -> V_46 )
V_73 -> V_75 |= V_76 ;
V_73 -> V_10 = V_10 & V_58 ;
V_73 -> V_11 = ( V_11 | ~ V_59 ) + 1 ;
}
}
V_2 . V_77 = V_69 ;
}
static int
F_34 ( struct V_3 * V_4 ,
T_2 * V_78 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
T_2 V_10 = F_4 ( V_4 -> V_54 + F_15 ( V_53 ) ) ;
T_2 V_11 = F_4 ( V_4 -> V_54 + F_16 ( V_53 ) ) ;
F_6 ( V_4 -> V_79 + F_15 ( V_53 ) ,
V_78 ++ ) ;
F_6 ( V_10 , V_78 ++ ) ;
F_6 ( V_4 -> V_79 + F_16 ( V_53 ) ,
V_78 ++ ) ;
F_6 ( V_11 , V_78 ++ ) ;
}
return 16 ;
}
static void T_7
F_35 ( struct V_3 * V_4 )
{
int V_53 ;
int V_69 ;
V_2 . V_70 = V_71 ;
for ( V_53 = 0 , V_69 = 0 ; V_53 < 2 ; V_53 ++ ) {
T_2 V_62 = F_4 ( V_4 -> V_54 + F_19 ( V_53 ) ) ;
if ( V_62 & 1 ) {
struct V_72 * V_73 ;
V_73 = & V_2 . V_69 [ V_69 ++ ] ;
V_73 -> V_74 = V_53 ;
V_73 -> V_75 = 0 ;
V_73 -> V_10 = V_62 & 0xff800000 ;
V_73 -> V_11 = 0x100000 << ( ( ( V_62 & 0x000f0000 ) >> 16 ) - 4 ) ;
}
}
V_2 . V_77 = V_69 ;
}
static int
F_36 ( struct V_3 * V_4 ,
T_2 * V_78 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < 2 ; V_53 ++ ) {
T_2 V_62 = F_4 ( V_4 -> V_54 + F_19 ( V_53 ) ) ;
F_6 ( V_4 -> V_79 + F_19 ( V_53 ) ,
V_78 ++ ) ;
F_6 ( V_62 , V_78 ++ ) ;
}
return 4 ;
}
int F_37 ( T_2 * V_78 )
{
return V_63 . V_6 -> V_80 ( & V_63 , V_78 ) ;
}
int F_38 ( unsigned int V_12 ,
unsigned int V_81 ,
T_5 V_10 , T_6 V_11 ,
T_5 V_14 )
{
struct V_3 * V_82 = & V_63 ;
if ( ! F_8 ( V_82 , V_10 , V_11 , V_12 , V_81 ) ) {
F_39 ( L_10 ,
V_12 , V_81 ) ;
return - V_45 ;
}
return F_13 ( V_82 , V_10 , V_11 , V_14 , V_12 , V_81 ) ;
}
int F_40 ( unsigned int V_12 , unsigned int V_81 ,
T_5 V_10 , T_6 V_11 )
{
return F_38 ( V_12 , V_81 , V_10 ,
V_11 , V_8 ) ;
}
int F_41 ( T_5 V_10 , T_6 V_11 )
{
int V_5 ;
V_5 = F_9 ( & V_63 , V_10 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
F_5 ( & V_63 , V_5 ) ;
return 0 ;
}
void F_42 ( struct V_83 * V_84 )
{
if ( ! V_84 )
return;
* V_84 = V_63 . V_85 ;
}
void F_43 ( struct V_83 * V_84 )
{
if ( ! V_84 )
return;
* V_84 = V_63 . V_86 ;
}
static T_7 int F_44 ( void )
{
struct V_3 * V_82 = & V_63 ;
if ( ! V_82 -> V_16 )
return 0 ;
V_82 -> V_87 = F_45 ( L_11 , NULL ) ;
if ( V_82 -> V_87 ) {
V_82 -> V_88 = F_46 ( L_12 , V_89 ,
V_82 -> V_87 , NULL ,
& V_90 ) ;
V_82 -> V_91 = F_46 ( L_13 , V_89 ,
V_82 -> V_87 , NULL ,
& V_92 ) ;
}
return 0 ;
}
static int F_47 ( void )
{
struct V_3 * V_82 = & V_63 ;
int V_5 ;
if ( ! V_82 -> V_93 )
return - V_43 ;
for ( V_5 = 0 ; V_5 < V_82 -> V_6 -> V_37 ; V_5 ++ ) {
void T_4 * V_15 = V_82 -> V_16 +
V_82 -> V_6 -> V_17 ( V_5 ) ;
void T_4 * V_32 ;
V_82 -> V_94 [ V_5 ] . V_10 = F_4 ( V_15 + V_19 ) ;
V_82 -> V_94 [ V_5 ] . V_35 = F_4 ( V_15 + V_21 ) ;
if ( ! F_2 ( V_82 , V_5 ) )
continue;
V_32 = V_82 -> V_16 +
V_82 -> V_6 -> V_7 ( V_5 ) ;
V_82 -> V_94 [ V_5 ] . V_95 = F_4 ( V_32 + V_33 ) ;
V_82 -> V_94 [ V_5 ] . V_31 = F_4 ( V_32 + V_34 ) ;
}
V_82 -> V_96 = F_4 ( V_82 -> V_93 +
V_97 ) ;
V_82 -> V_98 = F_4 ( V_82 -> V_93 +
V_99 ) ;
return 0 ;
}
static void F_48 ( void )
{
struct V_3 * V_82 = & V_63 ;
int V_5 ;
F_6 ( V_82 -> V_96 ,
V_82 -> V_93 + V_97 ) ;
F_6 ( V_82 -> V_98 ,
V_82 -> V_93 + V_99 ) ;
for ( V_5 = 0 ; V_5 < V_82 -> V_6 -> V_37 ; V_5 ++ ) {
void T_4 * V_15 = V_82 -> V_16 +
V_82 -> V_6 -> V_17 ( V_5 ) ;
void T_4 * V_32 ;
F_6 ( V_82 -> V_94 [ V_5 ] . V_10 , V_15 + V_19 ) ;
F_6 ( V_82 -> V_94 [ V_5 ] . V_35 , V_15 + V_21 ) ;
if ( ! F_2 ( V_82 , V_5 ) )
continue;
V_32 = V_82 -> V_16 +
V_82 -> V_6 -> V_7 ( V_5 ) ;
F_6 ( V_82 -> V_94 [ V_5 ] . V_95 , V_32 + V_33 ) ;
F_6 ( V_82 -> V_94 [ V_5 ] . V_31 , V_32 + V_34 ) ;
}
}
static int T_7 F_49 ( struct V_3 * V_4 ,
T_5 V_100 ,
T_6 V_101 ,
T_5 V_79 ,
T_6 V_102 ,
T_5 V_103 ,
T_6 V_104 ,
bool V_105 )
{
int V_5 ;
V_4 -> V_16 = F_50 ( V_100 , V_101 ) ;
if ( ! V_4 -> V_16 )
return - V_49 ;
V_4 -> V_54 = F_50 ( V_79 , V_102 ) ;
if ( ! V_4 -> V_54 ) {
F_51 ( V_63 . V_16 ) ;
return - V_49 ;
}
V_4 -> V_79 = V_79 ;
if ( V_103 ) {
V_4 -> V_93 = F_50 ( V_103 ,
V_104 ) ;
if ( ! V_4 -> V_93 ) {
F_51 ( V_4 -> V_54 ) ;
F_51 ( V_4 -> V_16 ) ;
return - V_49 ;
}
} else
V_4 -> V_93 = NULL ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 -> V_37 ; V_5 ++ )
F_5 ( V_4 , V_5 ) ;
V_4 -> V_6 -> V_106 ( V_4 ) ;
if ( V_105 )
F_6 ( V_107 ,
V_4 -> V_16 + V_108 ) ;
F_52 ( & V_109 ) ;
return 0 ;
}
int T_7 F_53 ( const char * V_6 , T_5 V_100 ,
T_6 V_101 ,
T_5 V_79 ,
T_6 V_102 )
{
const struct V_110 * V_111 ;
for ( V_111 = V_112 ; V_111 -> V_113 [ 0 ] ; V_111 ++ )
if ( ! strcmp ( V_111 -> V_113 , V_6 ) )
break;
if ( ! V_111 -> V_113 [ 0 ] ) {
F_39 ( L_14 ) ;
return - V_43 ;
}
V_63 . V_6 = V_111 -> V_114 ;
return F_49 ( & V_63 ,
V_100 ,
V_101 ,
V_79 ,
V_102 , 0 , 0 , false ) ;
}
static int T_7 F_54 ( struct V_3 * V_4 ,
T_2 V_10 , T_2 V_11 ,
T_3 V_12 , T_3 V_13 )
{
if ( ! F_8 ( V_4 , V_10 , V_11 , V_12 , V_13 ) ) {
F_39 ( L_15 ,
V_12 , V_13 ) ;
return - V_115 ;
}
if ( F_13 ( V_4 , V_10 , V_11 , V_8 ,
V_12 , V_13 ) ) {
F_39 ( L_16 ,
V_12 , V_13 ) ;
return - V_49 ;
}
return 0 ;
}
static int T_7
F_55 ( struct V_116 * V_117 ,
int * V_118 , int * V_119 , int * V_120 ,
int * V_121 , const T_8 * * V_122 ,
const T_8 * * V_123 )
{
const T_8 * V_124 ;
int V_125 , V_126 ;
* V_122 = F_56 ( V_117 , L_17 , & V_125 ) ;
if ( * V_122 == NULL ) {
* V_118 = * V_119 = * V_120 = * V_121 = 0 ;
* V_122 = * V_123 = NULL ;
return 0 ;
}
* V_123 = * V_122 + V_125 / sizeof( T_8 ) ;
* V_118 = F_57 ( V_117 ) ;
V_124 = F_56 ( V_117 , L_18 , NULL ) ;
* V_119 = F_58 ( V_124 ) ;
V_124 = F_56 ( V_117 , L_19 , NULL ) ;
* V_120 = F_58 ( V_124 ) ;
* V_121 = * V_118 + * V_119 + * V_120 ;
V_126 = ( * V_121 ) * sizeof( T_8 ) ;
if ( V_125 % V_126 ) {
F_59 ( L_20 , V_117 -> V_127 ) ;
return - V_45 ;
}
return 0 ;
}
static int T_7 F_60 ( struct V_3 * V_4 ,
struct V_116 * V_128 )
{
int V_118 , V_119 , V_120 ;
int V_53 , V_129 , V_121 ;
const T_8 * V_130 , * V_122 , * V_123 ;
V_129 = F_55 ( V_128 , & V_118 , & V_119 ,
& V_120 , & V_121 ,
& V_122 , & V_123 ) ;
if ( V_129 < 0 )
return V_129 ;
for ( V_53 = 0 , V_130 = V_122 ; V_130 < V_123 ; V_130 += V_121 , V_53 ++ ) {
T_2 V_131 , V_10 , V_11 ;
T_3 V_12 , V_13 ;
V_131 = F_61 ( V_130 , 1 ) ;
if ( F_62 ( V_131 ) )
continue;
V_12 = F_63 ( V_131 ) ;
V_13 = F_64 ( V_131 ) ;
V_10 = F_61 ( V_130 + V_119 , V_118 ) ;
V_11 = F_61 ( V_130 + V_119 + V_118 ,
V_120 ) ;
V_129 = F_54 ( V_4 , V_10 , V_11 , V_12 , V_13 ) ;
if ( V_129 < 0 )
return V_129 ;
}
return 0 ;
}
static void T_7 F_65 ( struct V_116 * V_128 ,
struct V_83 * V_132 ,
struct V_83 * V_133 )
{
T_2 V_134 [ 2 ] ;
int V_129 ;
memset ( V_132 , 0 , sizeof( struct V_83 ) ) ;
V_132 -> V_36 = - 1 ;
memset ( V_133 , 0 , sizeof( struct V_83 ) ) ;
V_133 -> V_36 = - 1 ;
V_129 = F_66 ( V_128 , L_21 , V_134 , F_67 ( V_134 ) ) ;
if ( ! V_129 ) {
V_132 -> V_135 = V_134 [ 0 ] ;
V_132 -> V_36 = V_132 -> V_135 + V_134 [ 1 ] - 1 ;
V_132 -> V_136 = V_137 ;
}
V_129 = F_66 ( V_128 , L_22 , V_134 , F_67 ( V_134 ) ) ;
if ( ! V_129 ) {
V_133 -> V_135 = V_134 [ 0 ] ;
V_133 -> V_36 = V_133 -> V_135 + V_134 [ 1 ] - 1 ;
V_133 -> V_136 = V_138 ;
}
}
int T_7 F_68 ( bool V_105 )
{
struct V_83 V_139 , V_140 , V_141 ;
struct V_116 * V_128 , * V_142 ;
const struct V_110 * V_111 ;
const T_8 * V_124 ;
int V_129 ;
V_128 = F_69 ( NULL , V_112 , & V_111 ) ;
if ( ! V_128 ) {
F_39 ( L_14 ) ;
return - V_43 ;
}
V_63 . V_6 = V_111 -> V_114 ;
V_124 = F_56 ( V_128 , L_23 , NULL ) ;
if ( ! V_124 ) {
F_39 ( L_24 ) ;
return - V_45 ;
}
V_142 = F_70 ( F_58 ( V_124 ) ) ;
if ( ! V_142 ) {
F_39 ( L_25 ) ;
return - V_43 ;
}
if ( F_71 ( V_142 , 0 , & V_139 ) ) {
F_39 ( L_26 ) ;
return - V_45 ;
}
if ( F_71 ( V_142 , 1 , & V_140 ) ) {
F_39 ( L_27 ) ;
return - V_45 ;
}
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
if ( V_63 . V_6 -> V_143 ) {
if ( F_71 ( V_142 , 2 , & V_141 ) )
F_59 ( V_144 L_28 ) ;
}
V_63 . V_46 = V_105 ;
F_65 ( V_128 , & V_63 . V_85 ,
& V_63 . V_86 ) ;
V_129 = F_49 ( & V_63 ,
V_139 . V_135 ,
F_72 ( & V_139 ) ,
V_140 . V_135 ,
F_72 ( & V_140 ) ,
V_141 . V_135 ,
F_72 ( & V_141 ) ,
V_105 ) ;
if ( V_129 )
return V_129 ;
return F_60 ( & V_63 , V_128 ) ;
}
