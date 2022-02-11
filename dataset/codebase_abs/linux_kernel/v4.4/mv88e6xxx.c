static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_3 ( ! F_4 ( & V_4 -> V_5 ) ) ) {
F_5 ( V_2 -> V_6 , L_1 ) ;
F_6 () ;
}
}
static int F_7 ( struct V_7 * V_8 , int V_9 )
{
int V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ ) {
V_10 = F_8 ( V_8 , V_9 , V_12 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ( V_10 & V_13 ) == 0 )
return 0 ;
}
return - V_14 ;
}
static int F_9 ( struct V_7 * V_8 , int V_9 , int V_15 ,
int V_16 )
{
int V_10 ;
if ( V_9 == 0 )
return F_8 ( V_8 , V_15 , V_16 ) ;
V_10 = F_7 ( V_8 , V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_10 ( V_8 , V_9 , V_12 ,
V_17 | ( V_15 << 5 ) | V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_7 ( V_8 , V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_8 ( V_8 , V_9 , V_18 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_10 & 0xffff ;
}
static int F_11 ( struct V_1 * V_2 , int V_15 , int V_16 )
{
struct V_7 * V_8 = F_12 ( V_2 -> V_6 ) ;
int V_10 ;
F_1 ( V_2 ) ;
if ( V_8 == NULL )
return - V_19 ;
V_10 = F_9 ( V_8 , V_2 -> V_20 -> V_9 , V_15 , V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
F_13 ( V_2 -> V_6 , L_2 ,
V_15 , V_16 , V_10 ) ;
return V_10 ;
}
int F_14 ( struct V_1 * V_2 , int V_15 , int V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_11 ( V_2 , V_15 , V_16 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
static int F_17 ( struct V_7 * V_8 , int V_9 , int V_15 ,
int V_16 , T_1 V_21 )
{
int V_10 ;
if ( V_9 == 0 )
return F_10 ( V_8 , V_15 , V_16 , V_21 ) ;
V_10 = F_7 ( V_8 , V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_10 ( V_8 , V_9 , V_18 , V_21 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_10 ( V_8 , V_9 , V_12 ,
V_22 | ( V_15 << 5 ) | V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_7 ( V_8 , V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_15 , int V_16 ,
T_1 V_21 )
{
struct V_7 * V_8 = F_12 ( V_2 -> V_6 ) ;
F_1 ( V_2 ) ;
if ( V_8 == NULL )
return - V_19 ;
F_13 ( V_2 -> V_6 , L_3 ,
V_15 , V_16 , V_21 ) ;
return F_17 ( V_8 , V_2 -> V_20 -> V_9 , V_15 , V_16 , V_21 ) ;
}
int F_19 ( struct V_1 * V_2 , int V_15 , int V_16 , T_1 V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_18 ( V_2 , V_15 , V_16 , V_21 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
int F_20 ( struct V_1 * V_2 , T_2 * V_15 )
{
F_21 ( V_23 , V_24 , ( V_15 [ 0 ] << 8 ) | V_15 [ 1 ] ) ;
F_21 ( V_23 , V_25 , ( V_15 [ 2 ] << 8 ) | V_15 [ 3 ] ) ;
F_21 ( V_23 , V_26 , ( V_15 [ 4 ] << 8 ) | V_15 [ 5 ] ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , T_2 * V_15 )
{
int V_11 ;
int V_10 ;
for ( V_11 = 0 ; V_11 < 6 ; V_11 ++ ) {
int V_27 ;
F_21 ( V_28 , V_29 ,
V_30 | ( V_11 << 8 ) | V_15 [ V_11 ] ) ;
for ( V_27 = 0 ; V_27 < 16 ; V_27 ++ ) {
V_10 = F_23 ( V_28 , V_29 ) ;
if ( ( V_10 & V_30 ) == 0 )
break;
}
if ( V_27 == 16 )
return - V_14 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_15 , int V_31 )
{
if ( V_15 >= 0 )
return F_11 ( V_2 , V_15 , V_31 ) ;
return 0xffff ;
}
static int F_25 ( struct V_1 * V_2 , int V_15 , int V_31 ,
T_1 V_21 )
{
if ( V_15 >= 0 )
return F_18 ( V_2 , V_15 , V_31 , V_21 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_10 ;
unsigned long V_32 ;
V_10 = F_23 ( V_23 , V_33 ) ;
F_21 ( V_23 , V_33 ,
V_10 & ~ V_34 ) ;
V_32 = V_35 + 1 * V_36 ;
while ( F_27 ( V_35 , V_32 ) ) {
V_10 = F_23 ( V_23 , V_37 ) ;
F_28 ( 1000 , 2000 ) ;
if ( ( V_10 & V_38 ) !=
V_39 )
return 0 ;
}
return - V_14 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_10 ;
unsigned long V_32 ;
V_10 = F_23 ( V_23 , V_33 ) ;
F_21 ( V_23 , V_33 , V_10 | V_34 ) ;
V_32 = V_35 + 1 * V_36 ;
while ( F_27 ( V_35 , V_32 ) ) {
V_10 = F_23 ( V_23 , V_37 ) ;
F_28 ( 1000 , 2000 ) ;
if ( ( V_10 & V_38 ) ==
V_39 )
return 0 ;
}
return - V_14 ;
}
static void F_30 ( struct V_40 * V_41 )
{
struct V_3 * V_4 ;
V_4 = F_31 ( V_41 , struct V_3 , V_42 ) ;
if ( F_32 ( & V_4 -> V_43 ) ) {
struct V_1 * V_2 = ( (struct V_1 * ) V_4 ) - 1 ;
if ( F_29 ( V_2 ) == 0 )
V_4 -> V_44 = 0 ;
F_16 ( & V_4 -> V_43 ) ;
}
}
static void F_33 ( unsigned long V_45 )
{
struct V_3 * V_4 = ( void * ) V_45 ;
F_34 ( & V_4 -> V_42 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
F_15 ( & V_4 -> V_43 ) ;
if ( ! V_4 -> V_44 ) {
V_10 = F_26 ( V_2 ) ;
if ( V_10 < 0 ) {
F_16 ( & V_4 -> V_43 ) ;
return V_10 ;
}
V_4 -> V_44 = 1 ;
} else {
F_36 ( & V_4 -> V_46 ) ;
V_10 = 0 ;
}
return V_10 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_38 ( & V_4 -> V_46 , V_35 + F_39 ( 10 ) ) ;
F_16 ( & V_4 -> V_43 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_41 ( & V_4 -> V_43 ) ;
F_42 ( & V_4 -> V_42 , F_30 ) ;
F_43 ( & V_4 -> V_46 ) ;
V_4 -> V_46 . V_47 = ( unsigned long ) V_4 ;
V_4 -> V_46 . V_48 = F_33 ;
}
int F_44 ( struct V_1 * V_2 , int V_15 , int V_31 )
{
int V_10 ;
V_10 = F_35 ( V_2 ) ;
if ( V_10 >= 0 ) {
V_10 = F_14 ( V_2 , V_15 , V_31 ) ;
F_37 ( V_2 ) ;
}
return V_10 ;
}
int F_45 ( struct V_1 * V_2 , int V_15 ,
int V_31 , T_1 V_21 )
{
int V_10 ;
V_10 = F_35 ( V_2 ) ;
if ( V_10 >= 0 ) {
V_10 = F_19 ( V_2 , V_15 , V_31 , V_21 ) ;
F_37 ( V_2 ) ;
}
return V_10 ;
}
static bool F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_49 ) {
case V_50 :
case V_51 :
case V_52 :
case V_53 :
return true ;
}
return false ;
}
static bool F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_49 ) {
case V_54 :
case V_55 :
return true ;
}
return false ;
}
static bool F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_49 ) {
case V_56 :
case V_57 :
case V_58 :
case V_59 :
return true ;
}
return false ;
}
static bool F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_49 ) {
case V_60 :
case V_61 :
case V_62 :
return true ;
}
return false ;
}
static bool F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_49 ) {
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
return true ;
}
return false ;
}
static bool F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_49 ) {
case V_71 :
case V_72 :
return true ;
}
return false ;
}
static bool F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_49 ) {
case V_73 :
case V_74 :
case V_75 :
case V_76 :
return true ;
}
return false ;
}
static bool F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_49 ) {
case V_77 :
case V_78 :
case V_79 :
case V_80 :
return true ;
}
return false ;
}
void F_54 ( struct V_1 * V_2 , int V_81 ,
struct V_82 * V_83 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_16 ;
int V_10 ;
if ( ! F_55 ( V_83 ) )
return;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_11 ( V_2 , F_56 ( V_81 ) , V_84 ) ;
if ( V_10 < 0 )
goto V_85;
V_16 = V_10 & ~ ( V_86 |
V_87 |
V_88 |
V_89 |
V_90 ) ;
V_16 |= V_87 ;
if ( V_83 -> V_91 )
V_16 |= V_86 ;
if ( F_46 ( V_2 ) && V_83 -> V_92 > V_93 )
goto V_85;
switch ( V_83 -> V_92 ) {
case V_94 :
V_16 |= V_95 ;
break;
case V_93 :
V_16 |= V_96 ;
break;
case V_97 :
V_16 |= V_98 ;
break;
default:
F_57 ( L_4 ) ;
goto V_85;
}
V_16 |= V_89 ;
if ( V_83 -> V_99 == V_100 )
V_16 |= V_88 ;
if ( ( F_53 ( V_2 ) || F_52 ( V_2 ) ) &&
( V_81 >= V_4 -> V_101 - 2 ) ) {
if ( V_83 -> V_102 == V_103 )
V_16 |= V_104 ;
if ( V_83 -> V_102 == V_105 )
V_16 |= V_106 ;
if ( V_83 -> V_102 == V_107 )
V_16 |= ( V_104 |
V_106 ) ;
}
F_18 ( V_2 , F_56 ( V_81 ) , V_84 , V_16 ) ;
V_85:
F_16 ( & V_4 -> V_5 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 10 ; V_11 ++ ) {
V_10 = F_11 ( V_2 , V_23 , V_108 ) ;
if ( ( V_10 & V_109 ) == 0 )
return 0 ;
}
return - V_14 ;
}
static int F_59 ( struct V_1 * V_2 , int V_81 )
{
int V_10 ;
if ( F_51 ( V_2 ) || F_53 ( V_2 ) )
V_81 = ( V_81 + 1 ) << 5 ;
V_10 = F_18 ( V_2 , V_23 , V_108 ,
V_110 |
V_111 | V_81 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_58 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 , int V_112 , T_3 * V_21 )
{
T_3 V_113 ;
int V_10 ;
* V_21 = 0 ;
V_10 = F_18 ( V_2 , V_23 , V_108 ,
V_114 |
V_111 | V_112 ) ;
if ( V_10 < 0 )
return;
V_10 = F_58 ( V_2 ) ;
if ( V_10 < 0 )
return;
V_10 = F_11 ( V_2 , V_23 , V_115 ) ;
if ( V_10 < 0 )
return;
V_113 = V_10 << 16 ;
V_10 = F_11 ( V_2 , V_23 , V_116 ) ;
if ( V_10 < 0 )
return;
* V_21 = V_113 | V_10 ;
}
static bool F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_49 ) {
case V_55 : case V_61 :
case V_62 : case V_73 :
case V_77 : case V_78 :
case V_67 : case V_68 :
case V_80 :
return true ;
default:
return false ;
}
}
static void F_62 ( struct V_1 * V_2 ,
int V_117 ,
struct V_118 * V_119 ,
int V_81 , T_4 * V_47 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_117 ; V_11 ++ ) {
memcpy ( V_47 + V_11 * V_120 ,
V_119 [ V_11 ] . string , V_120 ) ;
}
}
static T_5 F_63 ( struct V_1 * V_2 ,
int V_112 ,
struct V_118 * V_119 ,
int V_81 )
{
struct V_118 * V_121 = V_119 + V_112 ;
T_3 V_122 ;
T_3 V_123 = 0 ;
int V_10 ;
T_6 V_124 ;
if ( V_121 -> V_16 >= 0x100 ) {
V_10 = F_11 ( V_2 , F_56 ( V_81 ) ,
V_121 -> V_16 - 0x100 ) ;
if ( V_10 < 0 )
return V_125 ;
V_122 = V_10 ;
if ( V_121 -> V_126 == 4 ) {
V_10 = F_11 ( V_2 , F_56 ( V_81 ) ,
V_121 -> V_16 - 0x100 + 1 ) ;
if ( V_10 < 0 )
return V_125 ;
V_123 = V_10 ;
}
} else {
F_60 ( V_2 , V_121 -> V_16 , & V_122 ) ;
if ( V_121 -> V_126 == 8 )
F_60 ( V_2 , V_121 -> V_16 + 1 , & V_123 ) ;
}
V_124 = ( ( ( T_6 ) V_123 ) << 16 ) | V_122 ;
return V_124 ;
}
static void F_64 ( struct V_1 * V_2 ,
int V_117 ,
struct V_118 * V_119 ,
int V_81 , T_5 * V_47 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
int V_11 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_59 ( V_2 , V_81 ) ;
if ( V_10 < 0 ) {
F_16 ( & V_4 -> V_5 ) ;
return;
}
for ( V_11 = 0 ; V_11 < V_117 ; V_11 ++ )
V_47 [ V_11 ] = F_63 ( V_2 , V_11 , V_119 , V_81 ) ;
F_16 ( & V_4 -> V_5 ) ;
}
void
F_65 ( struct V_1 * V_2 , int V_81 , T_4 * V_47 )
{
if ( F_61 ( V_2 ) )
F_62 ( V_2 , F_66 ( V_127 ) ,
V_127 , V_81 , V_47 ) ;
else
F_62 ( V_2 , F_66 ( V_127 ) - 3 ,
V_127 , V_81 , V_47 ) ;
}
int F_67 ( struct V_1 * V_2 )
{
if ( F_61 ( V_2 ) )
return F_66 ( V_127 ) ;
return F_66 ( V_127 ) - 3 ;
}
void
F_68 ( struct V_1 * V_2 ,
int V_81 , T_5 * V_47 )
{
if ( F_61 ( V_2 ) )
F_64 (
V_2 , F_66 ( V_127 ) ,
V_127 , V_81 , V_47 ) ;
else
F_64 (
V_2 , F_66 ( V_127 ) - 3 ,
V_127 , V_81 , V_47 ) ;
}
int F_69 ( struct V_1 * V_2 , int V_81 )
{
return 32 * sizeof( T_1 ) ;
}
void F_70 ( struct V_1 * V_2 , int V_81 ,
struct V_128 * V_129 , void * V_130 )
{
T_1 * V_131 = V_130 ;
int V_11 ;
V_129 -> V_132 = 0 ;
memset ( V_131 , 0xff , 32 * sizeof( T_1 ) ) ;
for ( V_11 = 0 ; V_11 < 32 ; V_11 ++ ) {
int V_10 ;
V_10 = F_14 ( V_2 , F_56 ( V_81 ) , V_11 ) ;
if ( V_10 >= 0 )
V_131 [ V_11 ] = V_10 ;
}
}
static int F_71 ( struct V_1 * V_2 , int V_16 , int V_133 ,
T_1 V_134 )
{
unsigned long V_32 = V_35 + V_36 / 10 ;
while ( F_27 ( V_35 , V_32 ) ) {
int V_10 ;
V_10 = F_11 ( V_2 , V_16 , V_133 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! ( V_10 & V_134 ) )
return 0 ;
F_28 ( 1000 , 2000 ) ;
}
return - V_14 ;
}
static int F_72 ( struct V_1 * V_2 , int V_16 , int V_133 , T_1 V_134 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_71 ( V_2 , V_16 , V_133 , V_134 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
static int F_73 ( struct V_1 * V_2 )
{
return F_71 ( V_2 , V_28 , V_135 ,
V_136 ) ;
}
int F_74 ( struct V_1 * V_2 )
{
return F_72 ( V_2 , V_28 , V_137 ,
V_138 ) ;
}
int F_75 ( struct V_1 * V_2 )
{
return F_72 ( V_2 , V_28 , V_137 ,
V_139 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
return F_71 ( V_2 , V_23 , V_140 ,
V_141 ) ;
}
static int F_77 ( struct V_1 * V_2 , int V_15 ,
int V_31 )
{
int V_10 ;
V_10 = F_18 ( V_2 , V_28 , V_135 ,
V_142 | ( V_15 << 5 ) |
V_31 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_73 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_11 ( V_2 , V_28 , V_143 ) ;
}
static int F_78 ( struct V_1 * V_2 , int V_15 ,
int V_31 , T_1 V_21 )
{
int V_10 ;
V_10 = F_18 ( V_2 , V_28 , V_143 , V_21 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_18 ( V_2 , V_28 , V_135 ,
V_144 | ( V_15 << 5 ) |
V_31 ) ;
return F_73 ( V_2 ) ;
}
int F_79 ( struct V_1 * V_2 , int V_81 , struct V_145 * V_146 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_16 ;
F_15 ( & V_4 -> V_5 ) ;
V_16 = F_77 ( V_2 , V_81 , 16 ) ;
if ( V_16 < 0 )
goto V_85;
V_146 -> V_147 = ! ! ( V_16 & 0x0200 ) ;
V_146 -> V_148 = ! ! ( V_16 & 0x0100 ) ;
V_16 = F_11 ( V_2 , F_56 ( V_81 ) , V_149 ) ;
if ( V_16 < 0 )
goto V_85;
V_146 -> V_150 = ! ! ( V_16 & V_151 ) ;
V_16 = 0 ;
V_85:
F_16 ( & V_4 -> V_5 ) ;
return V_16 ;
}
int F_80 ( struct V_1 * V_2 , int V_81 ,
struct V_82 * V_83 , struct V_145 * V_146 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_16 ;
int V_10 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_77 ( V_2 , V_81 , 16 ) ;
if ( V_10 < 0 )
goto V_85;
V_16 = V_10 & ~ 0x0300 ;
if ( V_146 -> V_147 )
V_16 |= 0x0200 ;
if ( V_146 -> V_148 )
V_16 |= 0x0100 ;
V_10 = F_78 ( V_2 , V_81 , 16 , V_16 ) ;
V_85:
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
static int F_81 ( struct V_1 * V_2 , T_1 V_152 )
{
int V_10 ;
V_10 = F_18 ( V_2 , V_23 , V_140 , V_152 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_76 ( V_2 ) ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
T_1 V_47 = V_154 -> V_155 & V_156 ;
if ( V_154 -> V_155 != V_157 ) {
unsigned int V_134 , V_158 ;
if ( V_154 -> V_159 ) {
V_47 |= V_160 ;
V_134 = V_161 ;
V_158 = V_162 ;
} else {
V_134 = V_163 ;
V_158 = V_164 ;
}
V_47 |= ( V_154 -> V_165 << V_158 ) & V_134 ;
}
return F_18 ( V_2 , V_23 , V_166 , V_47 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_153 * V_154 ,
bool V_167 )
{
int V_168 ;
int V_169 ;
V_169 = F_76 ( V_2 ) ;
if ( V_169 )
return V_169 ;
V_169 = F_82 ( V_2 , V_154 ) ;
if ( V_169 )
return V_169 ;
if ( V_154 -> V_170 ) {
V_169 = F_18 ( V_2 , V_23 , V_171 ,
V_154 -> V_170 ) ;
if ( V_169 )
return V_169 ;
V_168 = V_167 ? V_172 :
V_173 ;
} else {
V_168 = V_167 ? V_174 :
V_175 ;
}
return F_81 ( V_2 , V_168 ) ;
}
static int F_84 ( struct V_1 * V_2 , T_1 V_170 , bool V_167 )
{
struct V_153 V_154 = {
. V_170 = V_170 ,
. V_155 = 0 ,
} ;
return F_83 ( V_2 , & V_154 , V_167 ) ;
}
static int F_85 ( struct V_1 * V_2 , T_1 V_170 , int V_176 ,
int V_177 , bool V_167 )
{
struct V_153 V_154 = {
. V_159 = false ,
. V_170 = V_170 ,
} ;
V_154 . V_155 = V_156 ;
V_154 . V_165 = ( V_177 & 0x0f ) << 4 ;
V_154 . V_165 |= V_176 & 0x0f ;
return F_83 ( V_2 , & V_154 , V_167 ) ;
}
static int F_86 ( struct V_1 * V_2 , T_1 V_170 , int V_81 ,
bool V_167 )
{
return F_85 ( V_2 , V_170 , V_81 , 0x0f , V_167 ) ;
}
static int F_87 ( struct V_1 * V_2 , int V_81 , T_2 V_155 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_16 , V_10 = 0 ;
T_2 V_178 ;
F_15 ( & V_4 -> V_5 ) ;
V_16 = F_11 ( V_2 , F_56 ( V_81 ) , V_179 ) ;
if ( V_16 < 0 ) {
V_10 = V_16 ;
goto abort;
}
V_178 = V_16 & V_180 ;
if ( V_178 != V_155 ) {
if ( V_178 >= V_181 &&
V_155 <= V_182 ) {
V_10 = F_86 ( V_2 , 0 , V_81 , false ) ;
if ( V_10 )
goto abort;
}
V_16 = ( V_16 & ~ V_180 ) | V_155 ;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) , V_179 ,
V_16 ) ;
}
abort:
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
static int F_88 ( struct V_1 * V_2 , int V_81 ,
T_1 V_183 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const T_1 V_134 = ( 1 << V_4 -> V_101 ) - 1 ;
int V_16 ;
V_16 = F_11 ( V_2 , F_56 ( V_81 ) , V_184 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 &= ~ V_134 ;
V_16 |= V_183 & V_134 ;
return F_18 ( V_2 , F_56 ( V_81 ) , V_184 , V_16 ) ;
}
int F_89 ( struct V_1 * V_2 , int V_81 , T_2 V_155 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_185 ;
switch ( V_155 ) {
case V_186 :
V_185 = V_187 ;
break;
case V_188 :
case V_189 :
V_185 = V_182 ;
break;
case V_190 :
V_185 = V_181 ;
break;
case V_191 :
default:
V_185 = V_192 ;
break;
}
F_90 ( V_2 -> V_193 [ V_81 ] , L_5 , V_155 , V_185 ) ;
V_4 -> V_194 [ V_81 ] = V_185 ;
F_91 ( V_81 , & V_4 -> V_195 ) ;
F_34 ( & V_4 -> V_196 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , int V_81 , T_1 * V_197 )
{
int V_10 ;
V_10 = F_11 ( V_2 , F_56 ( V_81 ) , V_198 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_197 = V_10 & V_199 ;
return 0 ;
}
int F_93 ( struct V_1 * V_2 , int V_81 , T_1 * V_197 )
{
int V_10 ;
V_10 = F_14 ( V_2 , F_56 ( V_81 ) , V_198 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_197 = V_10 & V_199 ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 , int V_81 , T_1 V_197 )
{
return F_18 ( V_2 , F_56 ( V_81 ) , V_198 ,
V_197 & V_199 ) ;
}
static int F_95 ( struct V_1 * V_2 )
{
return F_71 ( V_2 , V_23 , V_200 ,
V_201 ) ;
}
static int F_96 ( struct V_1 * V_2 , T_1 V_168 )
{
int V_10 ;
V_10 = F_18 ( V_2 , V_23 , V_200 , V_168 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_95 ( V_2 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_95 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_96 ( V_2 , V_202 ) ;
}
static int F_98 ( struct V_1 * V_2 ,
struct V_203 * V_154 ,
unsigned int V_204 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_129 [ 3 ] ;
int V_11 ;
int V_10 ;
for ( V_11 = 0 ; V_11 < 3 ; ++ V_11 ) {
V_10 = F_11 ( V_2 , V_23 ,
V_205 + V_11 ) ;
if ( V_10 < 0 )
return V_10 ;
V_129 [ V_11 ] = V_10 ;
}
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; ++ V_11 ) {
unsigned int V_158 = ( V_11 % 4 ) * 4 + V_204 ;
T_1 V_16 = V_129 [ V_11 / 4 ] ;
V_154 -> V_47 [ V_11 ] = ( V_16 >> V_158 ) & V_206 ;
}
return 0 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_203 * V_154 ,
unsigned int V_204 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_129 [ 3 ] = { 0 } ;
int V_11 ;
int V_10 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; ++ V_11 ) {
unsigned int V_158 = ( V_11 % 4 ) * 4 + V_204 ;
T_2 V_47 = V_154 -> V_47 [ V_11 ] ;
V_129 [ V_11 / 4 ] |= ( V_47 & V_206 ) << V_158 ;
}
for ( V_11 = 0 ; V_11 < 3 ; ++ V_11 ) {
V_10 = F_18 ( V_2 , V_23 ,
V_205 + V_11 , V_129 [ V_11 ] ) ;
if ( V_10 < 0 )
return V_10 ;
}
return 0 ;
}
static int F_100 ( struct V_1 * V_2 , T_1 V_207 )
{
return F_18 ( V_2 , V_23 , V_208 ,
V_207 & V_209 ) ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_203 * V_154 )
{
struct V_203 V_210 = { 0 } ;
int V_10 ;
V_10 = F_95 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_96 ( V_2 , V_211 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_11 ( V_2 , V_23 , V_208 ) ;
if ( V_10 < 0 )
return V_10 ;
V_210 . V_207 = V_10 & V_209 ;
V_210 . V_212 = ! ! ( V_10 & V_213 ) ;
if ( V_210 . V_212 ) {
V_10 = F_98 ( V_2 , & V_210 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( F_48 ( V_2 ) || F_49 ( V_2 ) ||
F_52 ( V_2 ) || F_53 ( V_2 ) ) {
V_10 = F_11 ( V_2 , V_23 ,
V_214 ) ;
if ( V_10 < 0 )
return V_10 ;
V_210 . V_170 = V_10 & V_215 ;
V_10 = F_11 ( V_2 , V_23 ,
V_216 ) ;
if ( V_10 < 0 )
return V_10 ;
V_210 . V_217 = V_10 & V_218 ;
}
}
* V_154 = V_210 ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_203 * V_154 )
{
T_1 V_16 = 0 ;
int V_10 ;
V_10 = F_95 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! V_154 -> V_212 )
goto V_219;
V_10 = F_99 ( V_2 , V_154 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( F_48 ( V_2 ) || F_49 ( V_2 ) ||
F_52 ( V_2 ) || F_53 ( V_2 ) ) {
V_16 = V_154 -> V_217 & V_218 ;
V_10 = F_18 ( V_2 , V_23 , V_216 , V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
V_16 = V_154 -> V_170 & V_215 ;
V_10 = F_18 ( V_2 , V_23 , V_214 , V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
}
V_16 = V_213 ;
V_219:
V_16 |= V_154 -> V_207 & V_209 ;
V_10 = F_18 ( V_2 , V_23 , V_208 , V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_96 ( V_2 , V_220 ) ;
}
static int F_103 ( struct V_1 * V_2 , T_2 V_217 ,
struct V_203 * V_154 )
{
struct V_203 V_210 = { 0 } ;
int V_10 ;
V_10 = F_95 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_18 ( V_2 , V_23 , V_216 ,
V_217 & V_218 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_96 ( V_2 , V_221 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_11 ( V_2 , V_23 , V_216 ) ;
if ( V_10 < 0 )
return V_10 ;
V_210 . V_217 = V_10 & V_218 ;
V_10 = F_11 ( V_2 , V_23 , V_208 ) ;
if ( V_10 < 0 )
return V_10 ;
V_210 . V_212 = ! ! ( V_10 & V_213 ) ;
if ( V_210 . V_212 ) {
V_10 = F_98 ( V_2 , & V_210 , 2 ) ;
if ( V_10 < 0 )
return V_10 ;
}
* V_154 = V_210 ;
return 0 ;
}
static int F_104 ( struct V_1 * V_2 ,
struct V_203 * V_154 )
{
T_1 V_16 = 0 ;
int V_10 ;
V_10 = F_95 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! V_154 -> V_212 )
goto V_219;
V_10 = F_99 ( V_2 , V_154 , 2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_16 = V_213 ;
V_219:
V_10 = F_18 ( V_2 , V_23 , V_208 , V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
V_16 = V_154 -> V_217 & V_218 ;
V_10 = F_18 ( V_2 , V_23 , V_216 , V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_96 ( V_2 , V_222 ) ;
}
static int F_105 ( struct V_1 * V_2 , T_1 V_207 ,
struct V_203 * V_154 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_203 V_223 = {
. V_212 = true ,
. V_207 = V_207 ,
. V_170 = V_207 ,
} ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; ++ V_11 )
V_223 . V_47 [ V_11 ] = F_106 ( V_2 , V_11 ) || F_107 ( V_2 , V_11 )
? V_224
: V_225 ;
if ( F_48 ( V_2 ) || F_49 ( V_2 ) ||
F_52 ( V_2 ) || F_53 ( V_2 ) ) {
struct V_203 V_226 ;
int V_169 ;
V_223 . V_217 = 0 ;
V_169 = F_103 ( V_2 , V_218 , & V_226 ) ;
if ( V_169 )
return V_169 ;
if ( V_226 . V_217 != V_223 . V_217 || ! V_226 . V_212 ) {
memset ( & V_226 , 0 , sizeof( V_226 ) ) ;
V_226 . V_212 = true ;
V_226 . V_217 = V_223 . V_217 ;
V_169 = F_104 ( V_2 , & V_226 ) ;
if ( V_169 )
return V_169 ;
}
V_169 = F_84 ( V_2 , V_223 . V_170 , true ) ;
if ( V_169 )
return V_169 ;
}
* V_154 = V_223 ;
return 0 ;
}
int F_108 ( struct V_1 * V_2 , int V_81 ,
const struct V_227 * V_223 ,
struct V_228 * V_229 )
{
if ( V_223 -> V_230 >= 4000 )
return - V_231 ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 , int V_81 , T_1 V_207 ,
bool V_232 )
{
struct V_203 V_223 ;
int V_169 ;
V_169 = F_100 ( V_2 , V_207 - 1 ) ;
if ( V_169 )
return V_169 ;
V_169 = F_101 ( V_2 , & V_223 ) ;
if ( V_169 )
return V_169 ;
if ( V_223 . V_207 != V_207 || ! V_223 . V_212 ) {
V_169 = F_105 ( V_2 , V_207 , & V_223 ) ;
if ( V_169 )
return V_169 ;
}
V_223 . V_47 [ V_81 ] = V_232 ?
V_233 :
V_234 ;
return F_102 ( V_2 , & V_223 ) ;
}
int F_110 ( struct V_1 * V_2 , int V_81 ,
const struct V_227 * V_223 ,
struct V_228 * V_229 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_232 = V_223 -> V_235 & V_236 ;
bool V_197 = V_223 -> V_235 & V_237 ;
T_1 V_207 ;
int V_169 = 0 ;
F_15 ( & V_4 -> V_5 ) ;
for ( V_207 = V_223 -> V_238 ; V_207 <= V_223 -> V_230 ; ++ V_207 ) {
V_169 = F_109 ( V_2 , V_81 , V_207 , V_232 ) ;
if ( V_169 )
goto V_239;
}
if ( V_197 )
V_169 = F_94 ( V_2 , V_81 , V_207 ) ;
V_239:
F_16 ( & V_4 -> V_5 ) ;
return V_169 ;
}
static int F_111 ( struct V_1 * V_2 , int V_81 , T_1 V_207 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_203 V_223 ;
int V_11 , V_169 ;
V_169 = F_100 ( V_2 , V_207 - 1 ) ;
if ( V_169 )
return V_169 ;
V_169 = F_101 ( V_2 , & V_223 ) ;
if ( V_169 )
return V_169 ;
if ( V_223 . V_207 != V_207 || ! V_223 . V_212 ||
V_223 . V_47 [ V_81 ] == V_225 )
return - V_240 ;
V_223 . V_47 [ V_81 ] = V_225 ;
V_223 . V_212 = false ;
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; ++ V_11 ) {
if ( F_106 ( V_2 , V_11 ) || F_107 ( V_2 , V_11 ) )
continue;
if ( V_223 . V_47 [ V_11 ] != V_225 ) {
V_223 . V_212 = true ;
break;
}
}
V_169 = F_102 ( V_2 , & V_223 ) ;
if ( V_169 )
return V_169 ;
return F_86 ( V_2 , V_223 . V_170 , V_81 , false ) ;
}
int F_112 ( struct V_1 * V_2 , int V_81 ,
const struct V_227 * V_223 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_197 , V_207 ;
int V_169 = 0 ;
F_15 ( & V_4 -> V_5 ) ;
V_169 = F_92 ( V_2 , V_81 , & V_197 ) ;
if ( V_169 )
goto V_239;
for ( V_207 = V_223 -> V_238 ; V_207 <= V_223 -> V_230 ; ++ V_207 ) {
V_169 = F_111 ( V_2 , V_81 , V_207 ) ;
if ( V_169 )
goto V_239;
if ( V_207 == V_197 ) {
V_169 = F_94 ( V_2 , V_81 , 0 ) ;
if ( V_169 )
goto V_239;
}
}
V_239:
F_16 ( & V_4 -> V_5 ) ;
return V_169 ;
}
int F_113 ( struct V_1 * V_2 , T_1 * V_207 ,
unsigned long * V_193 , unsigned long * V_232 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_203 V_210 ;
int V_81 ;
int V_169 ;
if ( * V_207 == 4095 )
return - V_240 ;
F_15 ( & V_4 -> V_5 ) ;
V_169 = F_100 ( V_2 , * V_207 ) ;
if ( V_169 )
goto V_239;
V_169 = F_101 ( V_2 , & V_210 ) ;
V_239:
F_16 ( & V_4 -> V_5 ) ;
if ( V_169 )
return V_169 ;
if ( ! V_210 . V_212 )
return - V_240 ;
* V_207 = V_210 . V_207 ;
for ( V_81 = 0 ; V_81 < V_4 -> V_101 ; ++ V_81 ) {
F_114 ( V_81 , V_193 ) ;
F_114 ( V_81 , V_232 ) ;
if ( F_106 ( V_2 , V_81 ) || F_107 ( V_2 , V_81 ) )
continue;
if ( V_210 . V_47 [ V_81 ] == V_234 ||
V_210 . V_47 [ V_81 ] == V_233 )
F_91 ( V_81 , V_193 ) ;
if ( V_210 . V_47 [ V_81 ] == V_233 )
F_91 ( V_81 , V_232 ) ;
}
return 0 ;
}
static int F_115 ( struct V_1 * V_2 ,
const unsigned char * V_15 )
{
int V_11 , V_10 ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
V_10 = F_18 (
V_2 , V_23 , V_241 + V_11 ,
( V_15 [ V_11 * 2 ] << 8 ) | V_15 [ V_11 * 2 + 1 ] ) ;
if ( V_10 < 0 )
return V_10 ;
}
return 0 ;
}
static int F_116 ( struct V_1 * V_2 , unsigned char * V_15 )
{
int V_11 , V_10 ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
V_10 = F_11 ( V_2 , V_23 ,
V_241 + V_11 ) ;
if ( V_10 < 0 )
return V_10 ;
V_15 [ V_11 * 2 ] = V_10 >> 8 ;
V_15 [ V_11 * 2 + 1 ] = V_10 & 0xff ;
}
return 0 ;
}
static int F_117 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
int V_10 ;
V_10 = F_76 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_115 ( V_2 , V_154 -> V_242 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_82 ( V_2 , V_154 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_18 ( V_2 , V_23 , V_171 , V_154 -> V_170 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_81 ( V_2 , V_243 ) ;
}
static int F_118 ( struct V_1 * V_2 , int V_81 ,
const unsigned char * V_15 , T_1 V_207 ,
T_2 V_155 )
{
struct V_153 V_154 = { 0 } ;
V_154 . V_170 = V_207 ;
V_154 . V_155 = V_155 ;
F_119 ( V_154 . V_242 , V_15 ) ;
if ( V_155 != V_157 ) {
V_154 . V_159 = false ;
V_154 . V_165 = F_120 ( V_81 ) ;
}
return F_117 ( V_2 , & V_154 ) ;
}
int F_121 ( struct V_1 * V_2 , int V_81 ,
const struct V_244 * V_245 ,
struct V_228 * V_229 )
{
if ( V_245 -> V_207 == 0 )
return - V_231 ;
return 0 ;
}
int F_122 ( struct V_1 * V_2 , int V_81 ,
const struct V_244 * V_245 ,
struct V_228 * V_229 )
{
int V_155 = F_123 ( V_245 -> V_15 ) ?
V_246 :
V_247 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_118 ( V_2 , V_81 , V_245 -> V_15 , V_245 -> V_207 , V_155 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
int F_124 ( struct V_1 * V_2 , int V_81 ,
const struct V_244 * V_245 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_118 ( V_2 , V_81 , V_245 -> V_15 , V_245 -> V_207 ,
V_157 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
static int F_125 ( struct V_1 * V_2 , T_1 V_170 ,
struct V_153 * V_154 )
{
struct V_153 V_210 = { 0 } ;
int V_10 ;
V_210 . V_170 = V_170 ;
V_10 = F_76 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_18 ( V_2 , V_23 , V_171 , V_170 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_81 ( V_2 , V_248 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_116 ( V_2 , V_210 . V_242 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_11 ( V_2 , V_23 , V_166 ) ;
if ( V_10 < 0 )
return V_10 ;
V_210 . V_155 = V_10 & V_156 ;
if ( V_210 . V_155 != V_157 ) {
unsigned int V_134 , V_158 ;
if ( V_10 & V_160 ) {
V_210 . V_159 = true ;
V_134 = V_161 ;
V_158 = V_162 ;
} else {
V_210 . V_159 = false ;
V_134 = V_163 ;
V_158 = V_164 ;
}
V_210 . V_165 = ( V_10 & V_134 ) >> V_158 ;
}
* V_154 = V_210 ;
return 0 ;
}
int F_126 ( struct V_1 * V_2 , int V_81 ,
struct V_244 * V_245 ,
int (* F_127)( struct V_249 * V_250 ) )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_203 V_223 = {
. V_207 = V_209 ,
} ;
int V_169 ;
F_15 ( & V_4 -> V_5 ) ;
V_169 = F_100 ( V_2 , V_223 . V_207 ) ;
if ( V_169 )
goto V_239;
do {
struct V_153 V_15 = {
. V_242 = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ,
} ;
V_169 = F_101 ( V_2 , & V_223 ) ;
if ( V_169 )
goto V_239;
if ( ! V_223 . V_212 )
break;
V_169 = F_115 ( V_2 , V_15 . V_242 ) ;
if ( V_169 )
goto V_239;
do {
V_169 = F_125 ( V_2 , V_223 . V_170 , & V_15 ) ;
if ( V_169 )
goto V_239;
if ( V_15 . V_155 == V_157 )
break;
if ( ! V_15 . V_159 && V_15 . V_165 & F_120 ( V_81 ) ) {
bool V_251 = V_15 . V_155 ==
( F_123 ( V_15 . V_242 ) ?
V_246 :
V_247 ) ;
V_245 -> V_207 = V_223 . V_207 ;
F_119 ( V_245 -> V_15 , V_15 . V_242 ) ;
V_245 -> V_252 = V_251 ? V_253 :
V_254 ;
V_169 = F_127 ( & V_245 -> V_250 ) ;
if ( V_169 )
goto V_239;
}
} while ( ! F_128 ( V_15 . V_242 ) );
} while ( V_223 . V_207 < V_209 );
V_239:
F_16 ( & V_4 -> V_5 ) ;
return V_169 ;
}
int F_129 ( struct V_1 * V_2 , int V_81 , T_3 V_255 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const T_1 V_197 = 4000 + V_2 -> V_256 * V_257 + V_81 ;
int V_169 ;
F_15 ( & V_4 -> V_5 ) ;
V_169 = F_111 ( V_2 , V_81 , V_197 ) ;
if ( ! V_169 )
V_169 = F_94 ( V_2 , V_81 , 0 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_169 ;
}
int F_130 ( struct V_1 * V_2 , int V_81 , T_3 V_255 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const T_1 V_197 = 4000 + V_2 -> V_256 * V_257 + V_81 ;
int V_169 ;
F_15 ( & V_4 -> V_5 ) ;
V_169 = F_109 ( V_2 , V_81 , V_197 , true ) ;
if ( ! V_169 )
V_169 = F_94 ( V_2 , V_81 , V_197 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_169 ;
}
static void F_131 ( struct V_40 * V_258 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_81 ;
V_4 = F_31 ( V_258 , struct V_3 , V_196 ) ;
V_2 = ( (struct V_1 * ) V_4 ) - 1 ;
while ( V_4 -> V_195 ) {
V_81 = F_132 ( V_4 -> V_195 ) ;
F_114 ( V_81 , & V_4 -> V_195 ) ;
F_87 ( V_2 , V_81 , V_4 -> V_194 [ V_81 ] ) ;
}
}
static int F_133 ( struct V_1 * V_2 , int V_81 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
T_1 V_16 ;
F_15 ( & V_4 -> V_5 ) ;
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_50 ( V_2 ) || F_47 ( V_2 ) ||
F_46 ( V_2 ) || F_51 ( V_2 ) ) {
V_16 = F_11 ( V_2 , F_56 ( V_81 ) , V_84 ) ;
if ( F_106 ( V_2 , V_81 ) || F_107 ( V_2 , V_81 ) ) {
V_16 &= ~ V_90 ;
V_16 |= V_87 |
V_86 |
V_88 |
V_89 ;
if ( F_46 ( V_2 ) )
V_16 |= V_96 ;
else
V_16 |= V_95 ;
} else {
V_16 |= V_90 ;
}
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_84 , V_16 ) ;
if ( V_10 )
goto abort;
}
V_16 = 0 ;
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_47 ( V_2 ) || F_46 ( V_2 ) ||
F_50 ( V_2 ) || F_51 ( V_2 ) )
V_16 = V_259 |
V_260 | V_261 |
V_192 ;
if ( F_106 ( V_2 , V_81 ) ) {
if ( F_47 ( V_2 ) || F_50 ( V_2 ) )
V_16 |= V_262 ;
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_51 ( V_2 ) ) {
if ( V_2 -> V_263 -> V_264 == V_265 )
V_16 |= V_266 ;
else
V_16 |= V_267 ;
V_16 |= V_268 |
V_269 ;
}
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_47 ( V_2 ) || F_46 ( V_2 ) ||
F_50 ( V_2 ) || F_51 ( V_2 ) ) {
if ( V_2 -> V_263 -> V_264 == V_265 )
V_16 |= V_270 ;
}
}
if ( F_107 ( V_2 , V_81 ) ) {
if ( F_47 ( V_2 ) || F_50 ( V_2 ) )
V_16 |= V_262 ;
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_51 ( V_2 ) ) {
V_16 |= V_267 ;
}
if ( V_81 == F_134 ( V_2 ) )
V_16 |= V_268 |
V_269 ;
}
if ( V_16 ) {
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_179 , V_16 ) ;
if ( V_10 )
goto abort;
}
V_16 = 0 ;
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_47 ( V_2 ) || F_51 ( V_2 ) )
V_16 = V_271 ;
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_51 ( V_2 ) )
V_16 |= V_272 ;
if ( F_47 ( V_2 ) || F_50 ( V_2 ) ) {
V_16 |= F_134 ( V_2 ) ;
if ( V_81 == F_134 ( V_2 ) )
V_16 |= V_273 ;
}
V_16 |= V_274 ;
if ( V_16 ) {
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_275 , V_16 ) ;
if ( V_10 )
goto abort;
}
V_16 = 1 << V_81 ;
if ( F_106 ( V_2 , V_81 ) || F_107 ( V_2 , V_81 ) )
V_16 = V_276 ;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) , V_277 , V_16 ) ;
if ( V_10 )
goto abort;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) , V_278 ,
0x0000 ) ;
if ( V_10 )
goto abort;
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_51 ( V_2 ) ) {
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_279 , 0x0000 ) ;
if ( V_10 )
goto abort;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_280 , 0x0000 ) ;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_281 , 0x0000 ) ;
if ( V_10 )
goto abort;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_282 , V_283 ) ;
if ( V_10 )
goto abort;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_284 , 0x3210 ) ;
if ( V_10 )
goto abort;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_285 , 0x7654 ) ;
if ( V_10 )
goto abort;
}
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_50 ( V_2 ) || F_47 ( V_2 ) ||
F_51 ( V_2 ) ) {
V_10 = F_18 ( V_2 , F_56 ( V_81 ) ,
V_286 , 0x0001 ) ;
if ( V_10 )
goto abort;
}
V_10 = F_18 ( V_2 , F_56 ( V_81 ) , V_287 , 0x0000 ) ;
if ( V_10 )
goto abort;
V_16 = F_120 ( V_4 -> V_101 ) - 1 ;
V_10 = F_88 ( V_2 , V_81 , V_16 & ~ V_81 ) ;
if ( V_10 )
goto abort;
V_10 = F_18 ( V_2 , F_56 ( V_81 ) , V_198 ,
0x0000 ) ;
abort:
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
int F_135 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; V_11 ++ ) {
V_10 = F_133 ( V_2 , V_11 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( F_106 ( V_2 , V_11 ) || F_107 ( V_2 , V_11 ) )
continue;
V_10 = F_130 ( V_2 , V_11 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
}
return 0 ;
}
int F_136 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_41 ( & V_4 -> V_5 ) ;
V_4 -> V_49 = F_23 ( F_56 ( 0 ) , V_288 ) & 0xfff0 ;
F_42 ( & V_4 -> V_196 , F_131 ) ;
return 0 ;
}
int F_137 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
int V_11 ;
F_21 ( V_23 , V_289 ,
0x0140 | V_290 ) ;
F_21 ( V_23 , V_291 , 0x0000 ) ;
F_21 ( V_23 , V_292 , 0x0000 ) ;
F_21 ( V_23 , V_293 , 0x5555 ) ;
F_21 ( V_23 , V_294 , 0x5555 ) ;
F_21 ( V_23 , V_295 , 0xaaaa ) ;
F_21 ( V_23 , V_296 , 0xaaaa ) ;
F_21 ( V_23 , V_297 , 0xffff ) ;
F_21 ( V_23 , V_298 , 0xffff ) ;
F_21 ( V_23 , V_299 , 0xfa41 ) ;
F_21 ( V_28 , V_300 , 0xffff ) ;
F_21 ( V_28 , V_301 ,
0x7 | V_302 | 0x70 |
V_303 ) ;
for ( V_11 = 0 ; V_11 < 32 ; V_11 ++ ) {
int V_304 = 0x1f ;
if ( V_2 -> V_20 -> V_305 &&
V_11 != V_2 -> V_256 && V_11 < V_2 -> V_263 -> V_20 -> V_306 )
V_304 = V_2 -> V_20 -> V_305 [ V_11 ] & 0x1f ;
F_21 ( V_28 , V_307 ,
V_308 |
( V_11 << V_309 ) |
V_304 ) ;
}
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ )
F_21 ( V_28 , V_310 ,
0x8000 | ( V_11 << V_311 ) |
( ( 1 << V_4 -> V_101 ) - 1 ) ) ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
F_21 ( V_28 , V_312 ,
V_313 |
( V_11 << V_314 ) ) ;
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_51 ( V_2 ) ) {
F_21 ( V_28 , V_315 , 0xffff ) ;
F_21 ( V_28 , V_316 , 0x9000 ) ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
F_21 ( V_28 , V_317 ,
0x8000 | ( V_11 << 8 ) ) ;
}
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ||
F_49 ( V_2 ) || F_48 ( V_2 ) ||
F_50 ( V_2 ) || F_47 ( V_2 ) ||
F_51 ( V_2 ) ) {
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; V_11 ++ )
F_21 ( V_28 , V_318 ,
0x9000 | ( V_11 << 8 ) ) ;
}
F_21 ( V_23 , V_108 , V_319 ) ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_58 ( V_2 ) ;
if ( V_10 < 0 )
goto V_239;
V_10 = F_84 ( V_2 , 0 , true ) ;
if ( V_10 < 0 )
goto V_239;
V_10 = F_97 ( V_2 ) ;
V_239:
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
int F_138 ( struct V_1 * V_2 , bool V_320 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_321 = ( V_320 ? 0x8800 : 0xc800 ) ;
unsigned long V_32 ;
int V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_101 ; V_11 ++ ) {
V_10 = F_23 ( F_56 ( V_11 ) , V_179 ) ;
F_21 ( F_56 ( V_11 ) , V_179 , V_10 & 0xfffc ) ;
}
F_28 ( 2000 , 4000 ) ;
if ( V_320 )
F_21 ( V_23 , 0x04 , 0xc000 ) ;
else
F_21 ( V_23 , 0x04 , 0xc400 ) ;
V_32 = V_35 + 1 * V_36 ;
while ( F_27 ( V_35 , V_32 ) ) {
V_10 = F_23 ( V_23 , 0x00 ) ;
if ( ( V_10 & V_321 ) == V_321 )
break;
F_28 ( 1000 , 2000 ) ;
}
if ( F_139 ( V_35 , V_32 ) )
return - V_14 ;
return 0 ;
}
int F_140 ( struct V_1 * V_2 , int V_81 , int V_322 , int V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_78 ( V_2 , V_81 , 0x16 , V_322 ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_77 ( V_2 , V_81 , V_16 ) ;
error:
F_78 ( V_2 , V_81 , 0x16 , 0x0 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
int F_141 ( struct V_1 * V_2 , int V_81 , int V_322 ,
int V_16 , int V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_78 ( V_2 , V_81 , 0x16 , V_322 ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_78 ( V_2 , V_81 , V_16 , V_21 ) ;
error:
F_78 ( V_2 , V_81 , 0x16 , 0x0 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
static int F_142 ( struct V_1 * V_2 , int V_81 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_81 >= 0 && V_81 < V_4 -> V_101 )
return V_81 ;
return - V_19 ;
}
int
F_143 ( struct V_1 * V_2 , int V_81 , int V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 = F_142 ( V_2 , V_81 ) ;
int V_10 ;
if ( V_15 < 0 )
return V_15 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_24 ( V_2 , V_15 , V_31 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
int
F_144 ( struct V_1 * V_2 , int V_81 , int V_31 , T_1 V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 = F_142 ( V_2 , V_81 ) ;
int V_10 ;
if ( V_15 < 0 )
return V_15 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_25 ( V_2 , V_15 , V_31 , V_21 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
int
F_145 ( struct V_1 * V_2 , int V_81 , int V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 = F_142 ( V_2 , V_81 ) ;
int V_10 ;
if ( V_15 < 0 )
return V_15 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_77 ( V_2 , V_15 , V_31 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
int
F_146 ( struct V_1 * V_2 , int V_81 , int V_31 ,
T_1 V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 = F_142 ( V_2 , V_81 ) ;
int V_10 ;
if ( V_15 < 0 )
return V_15 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_78 ( V_2 , V_15 , V_31 , V_21 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
static int F_147 ( struct V_1 * V_2 , int * V_323 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
int V_21 ;
* V_323 = 0 ;
F_15 ( & V_4 -> V_5 ) ;
V_10 = F_25 ( V_2 , 0x0 , 0x16 , 0x6 ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_24 ( V_2 , 0x0 , 0x1a ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_25 ( V_2 , 0x0 , 0x1a , V_10 | ( 1 << 5 ) ) ;
if ( V_10 < 0 )
goto error;
F_28 ( 10000 , 12000 ) ;
V_21 = F_24 ( V_2 , 0x0 , 0x1a ) ;
if ( V_21 < 0 ) {
V_10 = V_21 ;
goto error;
}
V_10 = F_25 ( V_2 , 0x0 , 0x1a , V_10 & ~ ( 1 << 5 ) ) ;
if ( V_10 < 0 )
goto error;
* V_323 = ( ( V_21 & 0x1f ) - 5 ) * 5 ;
error:
F_25 ( V_2 , 0x0 , 0x16 , 0x0 ) ;
F_16 ( & V_4 -> V_5 ) ;
return V_10 ;
}
static int F_148 ( struct V_1 * V_2 , int * V_323 )
{
int V_324 = F_51 ( V_2 ) ? 3 : 0 ;
int V_10 ;
* V_323 = 0 ;
V_10 = F_140 ( V_2 , V_324 , 6 , 27 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_323 = ( V_10 & 0xff ) - 25 ;
return 0 ;
}
int F_149 ( struct V_1 * V_2 , int * V_323 )
{
if ( F_51 ( V_2 ) || F_53 ( V_2 ) )
return F_148 ( V_2 , V_323 ) ;
return F_147 ( V_2 , V_323 ) ;
}
int F_150 ( struct V_1 * V_2 , int * V_323 )
{
int V_324 = F_51 ( V_2 ) ? 3 : 0 ;
int V_10 ;
if ( ! F_51 ( V_2 ) && ! F_53 ( V_2 ) )
return - V_231 ;
* V_323 = 0 ;
V_10 = F_140 ( V_2 , V_324 , 6 , 26 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_323 = ( ( ( V_10 >> 8 ) & 0x1f ) * 5 ) - 25 ;
return 0 ;
}
int F_151 ( struct V_1 * V_2 , int V_323 )
{
int V_324 = F_51 ( V_2 ) ? 3 : 0 ;
int V_10 ;
if ( ! F_51 ( V_2 ) && ! F_53 ( V_2 ) )
return - V_231 ;
V_10 = F_140 ( V_2 , V_324 , 6 , 26 ) ;
if ( V_10 < 0 )
return V_10 ;
V_323 = F_152 ( F_153 ( V_323 , 5 ) + 5 , 0 , 0x1f ) ;
return F_141 ( V_2 , V_324 , 6 , 26 ,
( V_10 & 0xe0ff ) | ( V_323 << 8 ) ) ;
}
int F_154 ( struct V_1 * V_2 , bool * V_325 )
{
int V_324 = F_51 ( V_2 ) ? 3 : 0 ;
int V_10 ;
if ( ! F_51 ( V_2 ) && ! F_53 ( V_2 ) )
return - V_231 ;
* V_325 = false ;
V_10 = F_140 ( V_2 , V_324 , 6 , 26 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_325 = ! ! ( V_10 & 0x40 ) ;
return 0 ;
}
char * F_155 ( struct V_326 * V_327 , int V_9 ,
const struct V_328 * V_329 ,
unsigned int V_330 )
{
struct V_7 * V_8 = F_12 ( V_327 ) ;
int V_11 , V_10 ;
if ( ! V_8 )
return NULL ;
V_10 = F_9 ( V_8 , V_9 , F_56 ( 0 ) , V_288 ) ;
if ( V_10 < 0 )
return NULL ;
for ( V_11 = 0 ; V_11 < V_330 ; ++ V_11 )
if ( V_329 [ V_11 ] . V_49 == V_10 )
return V_329 [ V_11 ] . V_331 ;
for ( V_11 = 0 ; V_11 < V_330 ; ++ V_11 ) {
if ( V_329 [ V_11 ] . V_49 == ( V_10 & V_332 ) ) {
F_156 ( V_327 , L_6 ,
V_10 & V_333 ,
V_10 & V_332 ) ;
return V_329 [ V_11 ] . V_331 ;
}
}
return NULL ;
}
static int T_7 F_157 ( void )
{
#if F_158 ( V_334 )
F_159 ( & V_335 ) ;
#endif
#if F_158 ( V_336 )
F_159 ( & V_337 ) ;
#endif
#if F_158 ( V_338 )
F_159 ( & V_339 ) ;
#endif
#if F_158 ( V_340 )
F_159 ( & V_341 ) ;
#endif
return 0 ;
}
static void T_8 F_160 ( void )
{
#if F_158 ( V_340 )
F_161 ( & V_341 ) ;
#endif
#if F_158 ( V_338 )
F_161 ( & V_339 ) ;
#endif
#if F_158 ( V_336 )
F_161 ( & V_337 ) ;
#endif
#if F_158 ( V_334 )
F_161 ( & V_335 ) ;
#endif
}
