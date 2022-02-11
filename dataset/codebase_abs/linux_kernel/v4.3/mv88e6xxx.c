static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
int V_5 ;
F_2 ( & V_2 -> V_6 , V_7 ) ;
V_5 = V_2 -> V_8 ( V_2 , V_3 , V_4 ) ;
F_3 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_4 ,
T_2 V_9 )
{
int V_5 ;
F_2 ( & V_2 -> V_6 , V_7 ) ;
V_5 = V_2 -> V_10 ( V_2 , V_3 , V_4 , V_9 ) ;
F_3 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , int V_11 )
{
int V_5 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
V_5 = F_1 ( V_2 , V_11 , V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ( V_5 & V_14 ) == 0 )
return 0 ;
}
return - V_15 ;
}
int F_6 ( struct V_1 * V_2 , int V_11 , int V_3 , int V_16 )
{
int V_5 ;
if ( V_11 == 0 )
return F_1 ( V_2 , V_3 , V_16 ) ;
V_5 = F_5 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_4 ( V_2 , V_11 , V_13 ,
V_17 | ( V_3 << 5 ) | V_16 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_5 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_2 , V_11 , V_18 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_5 & 0xffff ;
}
static int F_7 ( struct V_19 * V_20 , int V_3 , int V_16 )
{
struct V_1 * V_2 = F_8 ( V_20 -> V_21 ) ;
int V_5 ;
if ( V_2 == NULL )
return - V_22 ;
V_5 = F_6 ( V_2 , V_20 -> V_23 -> V_11 , V_3 , V_16 ) ;
if ( V_5 < 0 )
return V_5 ;
F_9 ( V_20 -> V_21 , L_1 ,
V_3 , V_16 , V_5 ) ;
return V_5 ;
}
int F_10 ( struct V_19 * V_20 , int V_3 , int V_16 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_7 ( V_20 , V_3 , V_16 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int F_13 ( struct V_1 * V_2 , int V_11 , int V_3 ,
int V_16 , T_2 V_9 )
{
int V_5 ;
if ( V_11 == 0 )
return F_4 ( V_2 , V_3 , V_16 , V_9 ) ;
V_5 = F_5 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_4 ( V_2 , V_11 , V_18 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_4 ( V_2 , V_11 , V_13 ,
V_27 | ( V_3 << 5 ) | V_16 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_5 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_14 ( struct V_19 * V_20 , int V_3 , int V_16 ,
T_2 V_9 )
{
struct V_1 * V_2 = F_8 ( V_20 -> V_21 ) ;
if ( V_2 == NULL )
return - V_22 ;
F_9 ( V_20 -> V_21 , L_2 ,
V_3 , V_16 , V_9 ) ;
return F_13 ( V_2 , V_20 -> V_23 -> V_11 , V_3 , V_16 , V_9 ) ;
}
int F_15 ( struct V_19 * V_20 , int V_3 , int V_16 , T_2 V_9 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_14 ( V_20 , V_3 , V_16 , V_9 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int F_16 ( struct V_19 * V_20 , T_3 * V_3 )
{
F_17 ( V_28 , V_29 , ( V_3 [ 0 ] << 8 ) | V_3 [ 1 ] ) ;
F_17 ( V_28 , V_30 , ( V_3 [ 2 ] << 8 ) | V_3 [ 3 ] ) ;
F_17 ( V_28 , V_31 , ( V_3 [ 4 ] << 8 ) | V_3 [ 5 ] ) ;
return 0 ;
}
int F_18 ( struct V_19 * V_20 , T_3 * V_3 )
{
int V_12 ;
int V_5 ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ ) {
int V_32 ;
F_17 ( V_33 , V_34 ,
V_35 | ( V_12 << 8 ) | V_3 [ V_12 ] ) ;
for ( V_32 = 0 ; V_32 < 16 ; V_32 ++ ) {
V_5 = F_19 ( V_33 , V_34 ) ;
if ( ( V_5 & V_35 ) == 0 )
break;
}
if ( V_32 == 16 )
return - V_15 ;
}
return 0 ;
}
static int F_20 ( struct V_19 * V_20 , int V_3 , int V_4 )
{
if ( V_3 >= 0 )
return F_7 ( V_20 , V_3 , V_4 ) ;
return 0xffff ;
}
static int F_21 ( struct V_19 * V_20 , int V_3 , int V_4 ,
T_2 V_9 )
{
if ( V_3 >= 0 )
return F_14 ( V_20 , V_3 , V_4 , V_9 ) ;
return 0 ;
}
static int F_22 ( struct V_19 * V_20 )
{
int V_5 ;
unsigned long V_36 ;
V_5 = F_19 ( V_28 , V_37 ) ;
F_17 ( V_28 , V_37 ,
V_5 & ~ V_38 ) ;
V_36 = V_39 + 1 * V_40 ;
while ( F_23 ( V_39 , V_36 ) ) {
V_5 = F_19 ( V_28 , V_41 ) ;
F_24 ( 1000 , 2000 ) ;
if ( ( V_5 & V_42 ) !=
V_43 )
return 0 ;
}
return - V_15 ;
}
static int F_25 ( struct V_19 * V_20 )
{
int V_5 ;
unsigned long V_36 ;
V_5 = F_19 ( V_28 , V_37 ) ;
F_17 ( V_28 , V_37 , V_5 | V_38 ) ;
V_36 = V_39 + 1 * V_40 ;
while ( F_23 ( V_39 , V_36 ) ) {
V_5 = F_19 ( V_28 , V_41 ) ;
F_24 ( 1000 , 2000 ) ;
if ( ( V_5 & V_42 ) ==
V_43 )
return 0 ;
}
return - V_15 ;
}
static void F_26 ( struct V_44 * V_45 )
{
struct V_24 * V_25 ;
V_25 = F_27 ( V_45 , struct V_24 , V_46 ) ;
if ( F_28 ( & V_25 -> V_47 ) ) {
struct V_19 * V_20 = ( (struct V_19 * ) V_25 ) - 1 ;
if ( F_25 ( V_20 ) == 0 )
V_25 -> V_48 = 0 ;
F_3 ( & V_25 -> V_47 ) ;
}
}
static void F_29 ( unsigned long V_49 )
{
struct V_24 * V_25 = ( void * ) V_49 ;
F_30 ( & V_25 -> V_46 ) ;
}
static int F_31 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
F_12 ( & V_25 -> V_47 ) ;
if ( ! V_25 -> V_48 ) {
V_5 = F_22 ( V_20 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_25 -> V_47 ) ;
return V_5 ;
}
V_25 -> V_48 = 1 ;
} else {
F_32 ( & V_25 -> V_50 ) ;
V_5 = 0 ;
}
return V_5 ;
}
static void F_33 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
F_34 ( & V_25 -> V_50 , V_39 + F_35 ( 10 ) ) ;
F_3 ( & V_25 -> V_47 ) ;
}
void F_36 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
F_37 ( & V_25 -> V_47 ) ;
F_38 ( & V_25 -> V_46 , F_26 ) ;
F_39 ( & V_25 -> V_50 ) ;
V_25 -> V_50 . V_51 = ( unsigned long ) V_25 ;
V_25 -> V_50 . V_52 = F_29 ;
}
int F_40 ( struct V_19 * V_20 , int V_3 , int V_4 )
{
int V_5 ;
V_5 = F_31 ( V_20 ) ;
if ( V_5 >= 0 ) {
V_5 = F_10 ( V_20 , V_3 , V_4 ) ;
F_33 ( V_20 ) ;
}
return V_5 ;
}
int F_41 ( struct V_19 * V_20 , int V_3 ,
int V_4 , T_2 V_9 )
{
int V_5 ;
V_5 = F_31 ( V_20 ) ;
if ( V_5 >= 0 ) {
V_5 = F_15 ( V_20 , V_3 , V_4 , V_9 ) ;
F_33 ( V_20 ) ;
}
return V_5 ;
}
void F_42 ( struct V_19 * V_20 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ ) {
struct V_54 * V_55 ;
int V_56 ( V_57 ) ;
int V_58 ;
int V_59 ;
int V_60 ;
int V_61 ;
int V_62 ;
V_55 = V_20 -> V_63 [ V_12 ] ;
if ( V_55 == NULL )
continue;
V_58 = F_10 ( V_20 , F_43 ( V_12 ) , V_64 ) ;
if ( V_58 < 0 || V_58 & V_65 )
continue;
V_59 = 0 ;
if ( V_55 -> V_66 & V_67 ) {
V_57 = F_10 ( V_20 , F_43 ( V_12 ) ,
V_68 ) ;
if ( V_57 < 0 )
continue;
V_59 = ! ! ( V_57 & V_69 ) ;
}
if ( ! V_59 ) {
if ( F_44 ( V_55 ) ) {
F_45 ( V_55 , L_3 ) ;
F_46 ( V_55 ) ;
}
continue;
}
switch ( V_57 & V_70 ) {
case V_71 :
V_60 = 10 ;
break;
case V_72 :
V_60 = 100 ;
break;
case V_73 :
V_60 = 1000 ;
break;
default:
V_60 = - 1 ;
break;
}
V_61 = ( V_57 & V_74 ) ? 1 : 0 ;
V_62 = ( V_57 & V_75 ) ? 1 : 0 ;
if ( ! F_44 ( V_55 ) ) {
F_45 ( V_55 ,
L_4 ,
V_60 ,
V_61 ? L_5 : L_6 ,
V_62 ? L_7 : L_8 ) ;
F_47 ( V_55 ) ;
}
}
}
static bool F_48 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
switch ( V_25 -> V_76 ) {
case V_77 :
case V_78 :
case V_79 :
case V_80 :
return true ;
}
return false ;
}
static bool F_49 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
switch ( V_25 -> V_76 ) {
case V_81 :
case V_82 :
return true ;
}
return false ;
}
static bool F_50 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
switch ( V_25 -> V_76 ) {
case V_83 :
case V_84 :
case V_85 :
case V_86 :
return true ;
}
return false ;
}
static bool F_51 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
switch ( V_25 -> V_76 ) {
case V_87 :
case V_88 :
case V_89 :
return true ;
}
return false ;
}
static bool F_52 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
switch ( V_25 -> V_76 ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
return true ;
}
return false ;
}
static bool F_53 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
switch ( V_25 -> V_76 ) {
case V_98 :
case V_99 :
return true ;
}
return false ;
}
static bool F_54 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
switch ( V_25 -> V_76 ) {
case V_100 :
case V_101 :
case V_102 :
case V_103 :
return true ;
}
return false ;
}
static bool F_55 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
switch ( V_25 -> V_76 ) {
case V_104 :
case V_105 :
case V_106 :
case V_107 :
return true ;
}
return false ;
}
void F_56 ( struct V_19 * V_20 , int V_108 ,
struct V_109 * V_110 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
T_1 V_5 , V_16 ;
if ( ! F_57 ( V_110 ) )
return;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_7 ( V_20 , F_43 ( V_108 ) , V_64 ) ;
if ( V_5 < 0 )
goto V_111;
V_16 = V_5 & ~ ( V_112 |
V_65 |
V_113 |
V_114 |
V_115 ) ;
V_16 |= V_65 ;
if ( V_110 -> V_59 )
V_16 |= V_112 ;
if ( F_48 ( V_20 ) && V_110 -> V_60 > V_116 )
goto V_111;
switch ( V_110 -> V_60 ) {
case V_117 :
V_16 |= V_118 ;
break;
case V_116 :
V_16 |= V_119 ;
break;
case V_120 :
V_16 |= V_121 ;
break;
default:
F_58 ( L_9 ) ;
goto V_111;
}
V_16 |= V_114 ;
if ( V_110 -> V_61 == V_122 )
V_16 |= V_113 ;
if ( ( F_55 ( V_20 ) || F_54 ( V_20 ) ) &&
( V_108 >= V_25 -> V_123 - 2 ) ) {
if ( V_110 -> V_124 == V_125 )
V_16 |= V_126 ;
if ( V_110 -> V_124 == V_127 )
V_16 |= V_128 ;
if ( V_110 -> V_124 == V_129 )
V_16 |= ( V_126 |
V_128 ) ;
}
F_14 ( V_20 , F_43 ( V_108 ) , V_64 , V_16 ) ;
V_111:
F_3 ( & V_25 -> V_26 ) ;
}
static int F_59 ( struct V_19 * V_20 )
{
int V_5 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
V_5 = F_7 ( V_20 , V_28 , V_130 ) ;
if ( ( V_5 & V_131 ) == 0 )
return 0 ;
}
return - V_15 ;
}
static int F_60 ( struct V_19 * V_20 , int V_108 )
{
int V_5 ;
if ( F_53 ( V_20 ) || F_55 ( V_20 ) )
V_108 = ( V_108 + 1 ) << 5 ;
V_5 = F_14 ( V_20 , V_28 , V_130 ,
V_132 |
V_133 | V_108 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_59 ( V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static void F_61 ( struct V_19 * V_20 , int V_134 , T_1 * V_9 )
{
T_1 V_135 ;
int V_5 ;
* V_9 = 0 ;
V_5 = F_14 ( V_20 , V_28 , V_130 ,
V_136 |
V_133 | V_134 ) ;
if ( V_5 < 0 )
return;
V_5 = F_59 ( V_20 ) ;
if ( V_5 < 0 )
return;
V_5 = F_7 ( V_20 , V_28 , V_137 ) ;
if ( V_5 < 0 )
return;
V_135 = V_5 << 16 ;
V_5 = F_7 ( V_20 , V_28 , V_138 ) ;
if ( V_5 < 0 )
return;
* V_9 = V_135 | V_5 ;
}
static bool F_62 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
switch ( V_25 -> V_76 ) {
case V_82 : case V_88 :
case V_89 : case V_100 :
case V_104 : case V_105 :
case V_94 : case V_95 :
case V_107 :
return true ;
default:
return false ;
}
}
static void F_63 ( struct V_19 * V_20 ,
int V_139 ,
struct V_140 * V_141 ,
int V_108 , T_4 * V_51 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_139 ; V_12 ++ ) {
memcpy ( V_51 + V_12 * V_142 ,
V_141 [ V_12 ] . string , V_142 ) ;
}
}
static T_5 F_64 ( struct V_19 * V_20 ,
int V_134 ,
struct V_140 * V_141 ,
int V_108 )
{
struct V_140 * V_143 = V_141 + V_134 ;
T_1 V_144 ;
T_1 V_145 = 0 ;
int V_5 ;
T_6 V_146 ;
if ( V_143 -> V_16 >= 0x100 ) {
V_5 = F_7 ( V_20 , F_43 ( V_108 ) ,
V_143 -> V_16 - 0x100 ) ;
if ( V_5 < 0 )
return V_147 ;
V_144 = V_5 ;
if ( V_143 -> V_148 == 4 ) {
V_5 = F_7 ( V_20 , F_43 ( V_108 ) ,
V_143 -> V_16 - 0x100 + 1 ) ;
if ( V_5 < 0 )
return V_147 ;
V_145 = V_5 ;
}
} else {
F_61 ( V_20 , V_143 -> V_16 , & V_144 ) ;
if ( V_143 -> V_148 == 8 )
F_61 ( V_20 , V_143 -> V_16 + 1 , & V_145 ) ;
}
V_146 = ( ( ( T_6 ) V_145 ) << 16 ) | V_144 ;
return V_146 ;
}
static void F_65 ( struct V_19 * V_20 ,
int V_139 ,
struct V_140 * V_141 ,
int V_108 , T_5 * V_51 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
int V_12 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_60 ( V_20 , V_108 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_25 -> V_26 ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_139 ; V_12 ++ )
V_51 [ V_12 ] = F_64 ( V_20 , V_12 , V_141 , V_108 ) ;
F_3 ( & V_25 -> V_26 ) ;
}
void
F_66 ( struct V_19 * V_20 , int V_108 , T_4 * V_51 )
{
if ( F_62 ( V_20 ) )
F_63 ( V_20 , F_67 ( V_149 ) ,
V_149 , V_108 , V_51 ) ;
else
F_63 ( V_20 , F_67 ( V_149 ) - 3 ,
V_149 , V_108 , V_51 ) ;
}
int F_68 ( struct V_19 * V_20 )
{
if ( F_62 ( V_20 ) )
return F_67 ( V_149 ) ;
return F_67 ( V_149 ) - 3 ;
}
void
F_69 ( struct V_19 * V_20 ,
int V_108 , T_5 * V_51 )
{
if ( F_62 ( V_20 ) )
F_65 (
V_20 , F_67 ( V_149 ) ,
V_149 , V_108 , V_51 ) ;
else
F_65 (
V_20 , F_67 ( V_149 ) - 3 ,
V_149 , V_108 , V_51 ) ;
}
int F_70 ( struct V_19 * V_20 , int V_108 )
{
return 32 * sizeof( T_2 ) ;
}
void F_71 ( struct V_19 * V_20 , int V_108 ,
struct V_150 * V_151 , void * V_152 )
{
T_2 * V_153 = V_152 ;
int V_12 ;
V_151 -> V_154 = 0 ;
memset ( V_153 , 0xff , 32 * sizeof( T_2 ) ) ;
for ( V_12 = 0 ; V_12 < 32 ; V_12 ++ ) {
int V_5 ;
V_5 = F_10 ( V_20 , F_43 ( V_108 ) , V_12 ) ;
if ( V_5 >= 0 )
V_153 [ V_12 ] = V_5 ;
}
}
static int F_72 ( struct V_19 * V_20 , int V_16 , int V_155 ,
T_2 V_156 )
{
unsigned long V_36 = V_39 + V_40 / 10 ;
while ( F_23 ( V_39 , V_36 ) ) {
int V_5 ;
V_5 = F_7 ( V_20 , V_16 , V_155 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ! ( V_5 & V_156 ) )
return 0 ;
F_24 ( 1000 , 2000 ) ;
}
return - V_15 ;
}
static int F_73 ( struct V_19 * V_20 , int V_16 , int V_155 , T_2 V_156 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_72 ( V_20 , V_16 , V_155 , V_156 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
static int F_74 ( struct V_19 * V_20 )
{
return F_72 ( V_20 , V_33 , V_157 ,
V_158 ) ;
}
int F_75 ( struct V_19 * V_20 )
{
return F_73 ( V_20 , V_33 , V_159 ,
V_160 ) ;
}
int F_76 ( struct V_19 * V_20 )
{
return F_73 ( V_20 , V_33 , V_159 ,
V_161 ) ;
}
static int F_77 ( struct V_19 * V_20 )
{
return F_72 ( V_20 , V_28 , V_162 ,
V_163 ) ;
}
static int F_78 ( struct V_19 * V_20 )
{
return F_72 ( V_20 , V_33 , V_164 ,
V_165 ) ;
}
static int F_79 ( struct V_19 * V_20 , int V_3 ,
int V_4 )
{
int V_5 ;
V_5 = F_14 ( V_20 , V_33 , V_157 ,
V_166 | ( V_3 << 5 ) |
V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_74 ( V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_7 ( V_20 , V_33 , V_167 ) ;
}
static int F_80 ( struct V_19 * V_20 , int V_3 ,
int V_4 , T_2 V_9 )
{
int V_5 ;
V_5 = F_14 ( V_20 , V_33 , V_167 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_14 ( V_20 , V_33 , V_157 ,
V_168 | ( V_3 << 5 ) |
V_4 ) ;
return F_74 ( V_20 ) ;
}
int F_81 ( struct V_19 * V_20 , int V_108 , struct V_169 * V_170 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_16 ;
F_12 ( & V_25 -> V_26 ) ;
V_16 = F_79 ( V_20 , V_108 , 16 ) ;
if ( V_16 < 0 )
goto V_111;
V_170 -> V_171 = ! ! ( V_16 & 0x0200 ) ;
V_170 -> V_172 = ! ! ( V_16 & 0x0100 ) ;
V_16 = F_7 ( V_20 , F_43 ( V_108 ) , V_68 ) ;
if ( V_16 < 0 )
goto V_111;
V_170 -> V_173 = ! ! ( V_16 & V_174 ) ;
V_16 = 0 ;
V_111:
F_3 ( & V_25 -> V_26 ) ;
return V_16 ;
}
int F_82 ( struct V_19 * V_20 , int V_108 ,
struct V_109 * V_110 , struct V_169 * V_170 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_16 ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_79 ( V_20 , V_108 , 16 ) ;
if ( V_5 < 0 )
goto V_111;
V_16 = V_5 & ~ 0x0300 ;
if ( V_170 -> V_171 )
V_16 |= 0x0200 ;
if ( V_170 -> V_172 )
V_16 |= 0x0100 ;
V_5 = F_80 ( V_20 , V_108 , 16 , V_16 ) ;
V_111:
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
static int F_83 ( struct V_19 * V_20 , int V_175 , T_2 V_176 )
{
int V_5 ;
V_5 = F_14 ( V_20 , V_28 , V_177 , V_175 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_14 ( V_20 , V_28 , V_162 , V_176 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_77 ( V_20 ) ;
}
static int F_84 ( struct V_19 * V_20 , int V_175 )
{
int V_5 ;
V_5 = F_77 ( V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_83 ( V_20 , V_175 , V_178 ) ;
}
static int F_85 ( struct V_19 * V_20 , int V_108 , T_3 V_179 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_16 , V_5 = 0 ;
T_3 V_180 ;
F_12 ( & V_25 -> V_26 ) ;
V_16 = F_7 ( V_20 , F_43 ( V_108 ) , V_181 ) ;
if ( V_16 < 0 ) {
V_5 = V_16 ;
goto abort;
}
V_180 = V_16 & V_182 ;
if ( V_180 != V_179 ) {
if ( V_180 >= V_183 &&
V_179 <= V_184 ) {
V_5 = F_84 ( V_20 , V_25 -> V_175 [ V_108 ] ) ;
if ( V_5 )
goto abort;
}
V_16 = ( V_16 & ~ V_182 ) | V_179 ;
V_5 = F_14 ( V_20 , F_43 ( V_108 ) , V_181 ,
V_16 ) ;
}
abort:
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
static int F_86 ( struct V_19 * V_20 , int V_108 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
T_3 V_175 = V_25 -> V_175 [ V_108 ] ;
T_2 V_16 = V_175 << 12 ;
if ( F_87 ( V_20 , V_108 ) )
V_16 |= V_20 -> V_185 ;
else
V_16 |= ( V_25 -> V_186 [ V_175 ] |
( 1 << F_88 ( V_20 ) ) ) & ~ ( 1 << V_108 ) ;
return F_14 ( V_20 , F_43 ( V_108 ) , V_187 , V_16 ) ;
}
static int F_89 ( struct V_19 * V_20 , int V_175 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_108 ;
T_1 V_156 ;
int V_5 ;
V_156 = V_20 -> V_185 ;
while ( V_156 ) {
V_108 = F_90 ( V_156 ) ;
V_156 &= ~ ( 1 << V_108 ) ;
if ( V_25 -> V_175 [ V_108 ] != V_175 )
continue;
V_5 = F_86 ( V_20 , V_108 ) ;
if ( V_5 )
return V_5 ;
}
return F_84 ( V_20 , V_175 ) ;
}
int F_91 ( struct V_19 * V_20 , int V_108 , T_1 V_188 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 = 0 ;
T_1 V_189 ;
int V_175 ;
V_175 = V_25 -> V_175 [ V_108 ] ;
V_189 = V_188 & ~ ( 1 << V_108 ) ;
if ( V_189 )
V_175 = V_25 -> V_175 [ F_90 ( V_189 ) ] ;
V_189 = V_25 -> V_186 [ V_175 ] | ( 1 << V_108 ) ;
if ( V_189 != V_188 ) {
F_92 ( V_20 -> V_63 [ V_108 ] ,
L_10 ,
V_175 , V_188 , V_189 ) ;
return - V_22 ;
}
F_12 ( & V_25 -> V_26 ) ;
V_25 -> V_186 [ V_175 ] = V_188 ;
if ( V_175 != V_25 -> V_175 [ V_108 ] ) {
F_93 ( V_25 -> V_175 [ V_108 ] , V_25 -> V_190 ) ;
V_25 -> V_175 [ V_108 ] = V_175 ;
V_5 = F_89 ( V_20 , V_175 ) ;
}
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int F_94 ( struct V_19 * V_20 , int V_108 , T_1 V_188 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
T_3 V_175 , V_191 ;
int V_5 ;
V_175 = V_25 -> V_175 [ V_108 ] ;
if ( V_25 -> V_186 [ V_175 ] != V_188 ) {
F_92 ( V_20 -> V_63 [ V_108 ] ,
L_11 ,
V_175 , V_188 , V_25 -> V_186 [ V_175 ] ) ;
return - V_22 ;
}
if ( V_188 == ( 1 << V_108 ) )
return 0 ;
F_12 ( & V_25 -> V_26 ) ;
V_191 = F_95 ( V_25 -> V_190 , V_192 , 1 ) ;
if ( F_96 ( V_191 > V_25 -> V_123 ) ) {
F_92 ( V_20 -> V_63 [ V_108 ] , L_12 ,
V_25 -> V_123 ) ;
V_5 = - V_193 ;
goto V_194;
}
V_25 -> V_175 [ V_108 ] = V_191 ;
F_97 ( V_191 , V_25 -> V_190 ) ;
V_25 -> V_186 [ V_175 ] &= ~ ( 1 << V_108 ) ;
V_25 -> V_186 [ V_191 ] = 1 << V_108 ;
V_5 = F_89 ( V_20 , V_175 ) ;
if ( ! V_5 )
V_5 = F_89 ( V_20 , V_191 ) ;
V_194:
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int F_98 ( struct V_19 * V_20 , int V_108 , T_3 V_179 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_195 ;
switch ( V_179 ) {
case V_196 :
V_195 = V_197 ;
break;
case V_198 :
case V_199 :
V_195 = V_184 ;
break;
case V_200 :
V_195 = V_183 ;
break;
case V_201 :
default:
V_195 = V_202 ;
break;
}
F_99 ( V_20 -> V_63 [ V_108 ] , L_13 , V_179 , V_195 ) ;
V_25 -> V_203 [ V_108 ] = V_195 ;
F_97 ( V_108 , & V_25 -> V_204 ) ;
F_30 ( & V_25 -> V_205 ) ;
return 0 ;
}
int F_100 ( struct V_19 * V_20 , int V_108 , T_2 * V_206 )
{
int V_5 ;
V_5 = F_10 ( V_20 , F_43 ( V_108 ) , V_207 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_206 = V_5 & V_208 ;
return 0 ;
}
int F_101 ( struct V_19 * V_20 , int V_108 , T_2 V_206 )
{
return F_15 ( V_20 , F_43 ( V_108 ) , V_207 ,
V_206 & V_208 ) ;
}
static int F_102 ( struct V_19 * V_20 )
{
return F_72 ( V_20 , V_28 , V_209 ,
V_210 ) ;
}
static int F_103 ( struct V_19 * V_20 , T_2 V_211 )
{
int V_5 ;
V_5 = F_14 ( V_20 , V_28 , V_209 , V_211 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_102 ( V_20 ) ;
}
static int F_104 ( struct V_19 * V_20 )
{
int V_5 ;
V_5 = F_102 ( V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_103 ( V_20 , V_212 ) ;
}
static int F_105 ( struct V_19 * V_20 ,
struct V_213 * V_214 ,
unsigned int V_215 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
T_2 V_151 [ 3 ] ;
int V_12 ;
int V_5 ;
for ( V_12 = 0 ; V_12 < 3 ; ++ V_12 ) {
V_5 = F_7 ( V_20 , V_28 ,
V_216 + V_12 ) ;
if ( V_5 < 0 )
return V_5 ;
V_151 [ V_12 ] = V_5 ;
}
for ( V_12 = 0 ; V_12 < V_25 -> V_123 ; ++ V_12 ) {
unsigned int V_217 = ( V_12 % 4 ) * 4 + V_215 ;
T_2 V_16 = V_151 [ V_12 / 4 ] ;
V_214 -> V_51 [ V_12 ] = ( V_16 >> V_217 ) & V_218 ;
}
return 0 ;
}
static int F_106 ( struct V_19 * V_20 ,
struct V_213 * V_214 ,
unsigned int V_215 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
T_2 V_151 [ 3 ] = { 0 } ;
int V_12 ;
int V_5 ;
for ( V_12 = 0 ; V_12 < V_25 -> V_123 ; ++ V_12 ) {
unsigned int V_217 = ( V_12 % 4 ) * 4 + V_215 ;
T_3 V_51 = V_214 -> V_51 [ V_12 ] ;
V_151 [ V_12 / 4 ] |= ( V_51 & V_218 ) << V_217 ;
}
for ( V_12 = 0 ; V_12 < 3 ; ++ V_12 ) {
V_5 = F_14 ( V_20 , V_28 ,
V_216 + V_12 , V_151 [ V_12 ] ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static int F_107 ( struct V_19 * V_20 , T_2 V_219 ,
struct V_213 * V_214 )
{
struct V_213 V_220 = { 0 } ;
int V_5 ;
V_5 = F_102 ( V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_14 ( V_20 , V_28 , V_221 ,
V_219 & V_222 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_103 ( V_20 , V_223 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_7 ( V_20 , V_28 , V_221 ) ;
if ( V_5 < 0 )
return V_5 ;
V_220 . V_219 = V_5 & V_222 ;
V_220 . V_224 = ! ! ( V_5 & V_225 ) ;
if ( V_220 . V_224 ) {
V_5 = F_105 ( V_20 , & V_220 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( F_50 ( V_20 ) || F_51 ( V_20 ) ||
F_54 ( V_20 ) || F_55 ( V_20 ) ) {
V_5 = F_7 ( V_20 , V_28 ,
V_226 ) ;
if ( V_5 < 0 )
return V_5 ;
V_220 . V_175 = V_5 & V_227 ;
V_5 = F_7 ( V_20 , V_28 ,
V_228 ) ;
if ( V_5 < 0 )
return V_5 ;
V_220 . V_229 = V_5 & V_230 ;
}
}
* V_214 = V_220 ;
return 0 ;
}
static int F_108 ( struct V_19 * V_20 ,
struct V_213 * V_214 )
{
T_2 V_16 = 0 ;
int V_5 ;
V_5 = F_102 ( V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ! V_214 -> V_224 )
goto V_231;
V_5 = F_106 ( V_20 , V_214 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( F_50 ( V_20 ) || F_51 ( V_20 ) ||
F_54 ( V_20 ) || F_55 ( V_20 ) ) {
V_16 = V_214 -> V_229 & V_230 ;
V_5 = F_14 ( V_20 , V_28 , V_228 , V_16 ) ;
if ( V_5 < 0 )
return V_5 ;
V_16 = V_214 -> V_175 & V_227 ;
V_5 = F_14 ( V_20 , V_28 , V_226 , V_16 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_16 = V_225 ;
V_231:
V_16 |= V_214 -> V_219 & V_222 ;
V_5 = F_14 ( V_20 , V_28 , V_221 , V_16 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_103 ( V_20 , V_232 ) ;
}
static int F_109 ( struct V_19 * V_20 , T_3 V_229 ,
struct V_213 * V_214 )
{
struct V_213 V_220 = { 0 } ;
int V_5 ;
V_5 = F_102 ( V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_14 ( V_20 , V_28 , V_228 ,
V_229 & V_230 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_103 ( V_20 , V_233 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_7 ( V_20 , V_28 , V_228 ) ;
if ( V_5 < 0 )
return V_5 ;
V_220 . V_229 = V_5 & V_230 ;
V_5 = F_7 ( V_20 , V_28 , V_221 ) ;
if ( V_5 < 0 )
return V_5 ;
V_220 . V_224 = ! ! ( V_5 & V_225 ) ;
if ( V_220 . V_224 ) {
V_5 = F_105 ( V_20 , & V_220 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
}
* V_214 = V_220 ;
return 0 ;
}
static int F_110 ( struct V_19 * V_20 ,
struct V_213 * V_214 )
{
T_2 V_16 = 0 ;
int V_5 ;
V_5 = F_102 ( V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ! V_214 -> V_224 )
goto V_231;
V_5 = F_106 ( V_20 , V_214 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_16 = V_225 ;
V_231:
V_5 = F_14 ( V_20 , V_28 , V_221 , V_16 ) ;
if ( V_5 < 0 )
return V_5 ;
V_16 = V_214 -> V_229 & V_230 ;
V_5 = F_14 ( V_20 , V_28 , V_228 , V_16 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_103 ( V_20 , V_234 ) ;
}
static int F_111 ( struct V_19 * V_20 , T_2 V_219 ,
struct V_213 * V_214 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
struct V_213 V_235 = {
. V_224 = true ,
. V_219 = V_219 ,
} ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_25 -> V_123 ; ++ V_12 )
V_235 . V_51 [ V_12 ] = F_87 ( V_20 , V_12 ) ?
V_236 :
V_237 ;
if ( F_50 ( V_20 ) || F_51 ( V_20 ) ||
F_54 ( V_20 ) || F_55 ( V_20 ) ) {
struct V_213 V_238 ;
int V_239 ;
V_235 . V_229 = 0 ;
V_239 = F_109 ( V_20 , V_230 , & V_238 ) ;
if ( V_239 )
return V_239 ;
if ( V_238 . V_229 != V_235 . V_229 || ! V_238 . V_224 ) {
memset ( & V_238 , 0 , sizeof( V_238 ) ) ;
V_238 . V_224 = true ;
V_238 . V_229 = V_235 . V_229 ;
V_239 = F_110 ( V_20 , & V_238 ) ;
if ( V_239 )
return V_239 ;
}
V_235 . V_175 = F_95 ( V_25 -> V_190 , V_192 ,
V_25 -> V_123 + 1 ) ;
if ( F_96 ( V_235 . V_175 == V_192 ) ) {
F_112 ( L_14 , V_219 ) ;
return - V_193 ;
}
V_239 = F_84 ( V_20 , V_235 . V_175 ) ;
if ( V_239 )
return V_239 ;
F_97 ( V_235 . V_175 , V_25 -> V_190 ) ;
}
* V_214 = V_235 ;
return 0 ;
}
int F_113 ( struct V_19 * V_20 , int V_108 , T_2 V_219 ,
bool V_240 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
struct V_213 V_235 ;
int V_239 ;
F_12 ( & V_25 -> V_26 ) ;
V_239 = F_107 ( V_20 , V_219 - 1 , & V_235 ) ;
if ( V_239 )
goto V_194;
if ( V_235 . V_219 != V_219 || ! V_235 . V_224 ) {
V_239 = F_111 ( V_20 , V_219 , & V_235 ) ;
if ( V_239 )
goto V_194;
}
V_235 . V_51 [ V_108 ] = V_240 ?
V_241 :
V_236 ;
V_239 = F_108 ( V_20 , & V_235 ) ;
V_194:
F_3 ( & V_25 -> V_26 ) ;
return V_239 ;
}
int F_114 ( struct V_19 * V_20 , int V_108 , T_2 V_219 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
struct V_213 V_235 ;
bool V_242 = false ;
int V_12 , V_239 ;
F_12 ( & V_25 -> V_26 ) ;
V_239 = F_107 ( V_20 , V_219 - 1 , & V_235 ) ;
if ( V_239 )
goto V_194;
if ( V_235 . V_219 != V_219 || ! V_235 . V_224 ||
V_235 . V_51 [ V_108 ] == V_237 ) {
V_239 = - V_243 ;
goto V_194;
}
V_235 . V_51 [ V_108 ] = V_237 ;
for ( V_12 = 0 ; V_12 < V_25 -> V_123 ; ++ V_12 ) {
if ( F_87 ( V_20 , V_12 ) )
continue;
if ( V_235 . V_51 [ V_12 ] != V_237 ) {
V_242 = true ;
break;
}
}
V_235 . V_224 = V_242 ;
V_239 = F_108 ( V_20 , & V_235 ) ;
if ( V_239 )
goto V_194;
if ( ! V_242 )
F_93 ( V_235 . V_175 , V_25 -> V_190 ) ;
V_194:
F_3 ( & V_25 -> V_26 ) ;
return V_239 ;
}
static int F_115 ( struct V_19 * V_20 , int V_108 , T_2 V_219 ,
struct V_213 * V_214 )
{
int V_239 ;
do {
if ( V_219 == 4095 )
return - V_243 ;
V_239 = F_107 ( V_20 , V_219 , V_214 ) ;
if ( V_239 )
return V_239 ;
if ( ! V_214 -> V_224 )
return - V_243 ;
V_219 = V_214 -> V_219 ;
} while ( V_214 -> V_51 [ V_108 ] != V_236 &&
V_214 -> V_51 [ V_108 ] != V_241 );
return 0 ;
}
int F_116 ( struct V_19 * V_20 , T_2 * V_219 ,
unsigned long * V_63 , unsigned long * V_240 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
struct V_213 V_220 ;
int V_108 ;
int V_239 ;
if ( * V_219 == 4095 )
return - V_243 ;
F_12 ( & V_25 -> V_26 ) ;
V_239 = F_107 ( V_20 , * V_219 , & V_220 ) ;
F_3 ( & V_25 -> V_26 ) ;
if ( V_239 )
return V_239 ;
if ( ! V_220 . V_224 )
return - V_243 ;
* V_219 = V_220 . V_219 ;
for ( V_108 = 0 ; V_108 < V_25 -> V_123 ; ++ V_108 ) {
F_93 ( V_108 , V_63 ) ;
F_93 ( V_108 , V_240 ) ;
if ( F_87 ( V_20 , V_108 ) )
continue;
if ( V_220 . V_51 [ V_108 ] == V_236 ||
V_220 . V_51 [ V_108 ] == V_241 )
F_97 ( V_108 , V_63 ) ;
if ( V_220 . V_51 [ V_108 ] == V_241 )
F_97 ( V_108 , V_240 ) ;
}
return 0 ;
}
static int F_117 ( struct V_19 * V_20 ,
const unsigned char * V_3 )
{
int V_12 , V_5 ;
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ ) {
V_5 = F_14 (
V_20 , V_28 , V_244 + V_12 ,
( V_3 [ V_12 * 2 ] << 8 ) | V_3 [ V_12 * 2 + 1 ] ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static int F_118 ( struct V_19 * V_20 , unsigned char * V_3 )
{
int V_12 , V_5 ;
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ ) {
V_5 = F_7 ( V_20 , V_28 ,
V_244 + V_12 ) ;
if ( V_5 < 0 )
return V_5 ;
V_3 [ V_12 * 2 ] = V_5 >> 8 ;
V_3 [ V_12 * 2 + 1 ] = V_5 & 0xff ;
}
return 0 ;
}
static int F_119 ( struct V_19 * V_20 ,
struct V_245 * V_214 )
{
T_2 V_16 = 0 ;
int V_5 ;
V_5 = F_77 ( V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_117 ( V_20 , V_214 -> V_246 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_214 -> V_179 != V_247 ) {
unsigned int V_156 , V_217 ;
if ( V_214 -> V_248 ) {
V_16 |= V_249 ;
V_156 = V_250 ;
V_217 = V_251 ;
} else {
V_156 = V_252 ;
V_217 = V_253 ;
}
V_16 |= ( V_214 -> V_254 << V_217 ) & V_156 ;
}
V_16 |= V_214 -> V_179 & V_255 ;
V_5 = F_14 ( V_20 , V_28 , V_256 , V_16 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_83 ( V_20 , V_214 -> V_175 , V_257 ) ;
}
static int F_120 ( struct V_19 * V_20 , int V_108 , T_2 V_219 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
struct V_213 V_235 ;
int V_239 ;
if ( V_219 == 0 )
return V_25 -> V_175 [ V_108 ] ;
V_239 = F_115 ( V_20 , V_108 , V_219 - 1 , & V_235 ) ;
if ( V_239 )
return V_239 ;
if ( V_235 . V_219 == V_219 )
return V_235 . V_175 ;
return - V_243 ;
}
static int F_121 ( struct V_19 * V_20 , int V_108 ,
const unsigned char * V_3 , T_2 V_219 ,
T_3 V_179 )
{
struct V_245 V_214 = { 0 } ;
int V_5 ;
V_5 = F_120 ( V_20 , V_108 , V_219 ) ;
if ( V_5 < 0 )
return V_5 ;
V_214 . V_175 = V_5 ;
V_214 . V_179 = V_179 ;
F_122 ( V_214 . V_246 , V_3 ) ;
if ( V_179 != V_247 ) {
V_214 . V_248 = false ;
V_214 . V_254 = F_123 ( V_108 ) ;
}
return F_119 ( V_20 , & V_214 ) ;
}
int F_124 ( struct V_19 * V_20 , int V_108 ,
const unsigned char * V_3 , T_2 V_219 )
{
int V_179 = F_125 ( V_3 ) ?
V_258 :
V_259 ;
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_121 ( V_20 , V_108 , V_3 , V_219 , V_179 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int F_126 ( struct V_19 * V_20 , int V_108 ,
const unsigned char * V_3 , T_2 V_219 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_121 ( V_20 , V_108 , V_3 , V_219 ,
V_247 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
static int F_127 ( struct V_19 * V_20 , T_2 V_175 ,
const unsigned char * V_3 ,
struct V_245 * V_214 )
{
struct V_245 V_220 = { 0 } ;
int V_5 ;
V_220 . V_175 = V_175 ;
V_5 = F_77 ( V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_117 ( V_20 , V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_83 ( V_20 , V_175 , V_260 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_118 ( V_20 , V_220 . V_246 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_7 ( V_20 , V_28 , V_256 ) ;
if ( V_5 < 0 )
return V_5 ;
V_220 . V_179 = V_5 & V_255 ;
if ( V_220 . V_179 != V_247 ) {
unsigned int V_156 , V_217 ;
if ( V_5 & V_249 ) {
V_220 . V_248 = true ;
V_156 = V_250 ;
V_217 = V_251 ;
} else {
V_220 . V_248 = false ;
V_156 = V_252 ;
V_217 = V_253 ;
}
V_220 . V_254 = ( V_5 & V_156 ) >> V_217 ;
}
* V_214 = V_220 ;
return 0 ;
}
int F_128 ( struct V_19 * V_20 , int V_108 ,
unsigned char * V_3 , T_2 * V_219 , bool * V_261 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
struct V_245 V_220 ;
T_2 V_175 ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_120 ( V_20 , V_108 , * V_219 ) ;
if ( V_5 < 0 )
goto V_194;
V_175 = V_5 ;
do {
if ( F_129 ( V_3 ) ) {
struct V_213 V_262 ;
V_5 = F_115 ( V_20 , V_108 , * V_219 , & V_262 ) ;
if ( V_5 < 0 )
goto V_194;
* V_219 = V_262 . V_219 ;
V_175 = V_262 . V_175 ;
}
V_5 = F_127 ( V_20 , V_175 , V_3 , & V_220 ) ;
if ( V_5 < 0 )
goto V_194;
F_122 ( V_3 , V_220 . V_246 ) ;
if ( V_220 . V_179 == V_247 )
continue;
} while ( V_220 . V_248 || ( V_220 . V_254 & F_123 ( V_108 ) ) == 0 );
* V_261 = V_220 . V_179 == ( F_125 ( V_3 ) ?
V_258 :
V_259 ) ;
V_194:
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
static void F_130 ( struct V_44 * V_263 )
{
struct V_24 * V_25 ;
struct V_19 * V_20 ;
int V_108 ;
V_25 = F_27 ( V_263 , struct V_24 , V_205 ) ;
V_20 = ( (struct V_19 * ) V_25 ) - 1 ;
while ( V_25 -> V_204 ) {
V_108 = F_90 ( V_25 -> V_204 ) ;
F_93 ( V_108 , & V_25 -> V_204 ) ;
F_85 ( V_20 , V_108 , V_25 -> V_203 [ V_108 ] ) ;
}
}
static int F_131 ( struct V_19 * V_20 , int V_108 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 , V_175 ;
T_2 V_16 ;
F_12 ( & V_25 -> V_26 ) ;
if ( F_55 ( V_20 ) || F_54 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ||
F_52 ( V_20 ) || F_49 ( V_20 ) ||
F_48 ( V_20 ) || F_53 ( V_20 ) ) {
V_16 = F_7 ( V_20 , F_43 ( V_108 ) , V_64 ) ;
if ( F_87 ( V_20 , V_108 ) || F_132 ( V_20 , V_108 ) ) {
V_16 &= ~ V_115 ;
V_16 |= V_65 |
V_112 |
V_113 |
V_114 ;
if ( F_48 ( V_20 ) )
V_16 |= V_119 ;
else
V_16 |= V_118 ;
} else {
V_16 |= V_115 ;
}
V_5 = F_14 ( V_20 , F_43 ( V_108 ) ,
V_64 , V_16 ) ;
if ( V_5 )
goto abort;
}
V_16 = 0 ;
if ( F_55 ( V_20 ) || F_54 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ||
F_49 ( V_20 ) || F_48 ( V_20 ) ||
F_52 ( V_20 ) || F_53 ( V_20 ) )
V_16 = V_264 |
V_265 | V_266 |
V_202 ;
if ( F_87 ( V_20 , V_108 ) ) {
if ( F_49 ( V_20 ) || F_52 ( V_20 ) )
V_16 |= V_267 ;
if ( F_55 ( V_20 ) || F_54 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ||
F_53 ( V_20 ) ) {
if ( V_20 -> V_268 -> V_269 == V_270 )
V_16 |= V_271 ;
else
V_16 |= V_272 ;
V_16 |= V_273 |
V_274 ;
}
if ( F_55 ( V_20 ) || F_54 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ||
F_49 ( V_20 ) || F_48 ( V_20 ) ||
F_52 ( V_20 ) || F_53 ( V_20 ) ) {
if ( V_20 -> V_268 -> V_269 == V_270 )
V_16 |= V_275 ;
}
}
if ( F_132 ( V_20 , V_108 ) ) {
if ( F_49 ( V_20 ) || F_52 ( V_20 ) )
V_16 |= V_267 ;
if ( F_55 ( V_20 ) || F_54 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ||
F_53 ( V_20 ) ) {
V_16 |= V_272 ;
}
if ( V_108 == F_88 ( V_20 ) )
V_16 |= V_273 |
V_274 ;
}
if ( V_16 ) {
V_5 = F_14 ( V_20 , F_43 ( V_108 ) ,
V_181 , V_16 ) ;
if ( V_5 )
goto abort;
}
V_16 = 0 ;
if ( F_55 ( V_20 ) || F_54 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ||
F_49 ( V_20 ) || F_53 ( V_20 ) )
V_16 = V_276 ;
if ( F_55 ( V_20 ) || F_54 ( V_20 ) ||
F_51 ( V_20 ) || F_53 ( V_20 ) )
V_16 |= V_277 ;
if ( F_49 ( V_20 ) || F_52 ( V_20 ) ) {
V_16 |= F_88 ( V_20 ) ;
if ( V_108 == F_88 ( V_20 ) )
V_16 |= V_278 ;
}
V_16 |= V_279 ;
if ( V_16 ) {
V_5 = F_14 ( V_20 , F_43 ( V_108 ) ,
V_280 , V_16 ) ;
if ( V_5 )
goto abort;
}
V_5 = F_14 ( V_20 , F_43 ( V_108 ) , V_281 ,
1 << V_108 ) ;
if ( V_5 )
goto abort;
V_5 = F_14 ( V_20 , F_43 ( V_108 ) , V_282 ,
0x0000 ) ;
if ( V_5 )
goto abort;
if ( F_55 ( V_20 ) || F_54 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ||
F_53 ( V_20 ) ) {
V_5 = F_14 ( V_20 , F_43 ( V_108 ) ,
V_283 , 0x0000 ) ;
if ( V_5 )
goto abort;
V_5 = F_14 ( V_20 , F_43 ( V_108 ) ,
V_284 , 0x0000 ) ;
V_5 = F_14 ( V_20 , F_43 ( V_108 ) ,
V_285 , 0x0000 ) ;
if ( V_5 )
goto abort;
V_5 = F_14 ( V_20 , F_43 ( V_108 ) ,
V_286 , V_287 ) ;
if ( V_5 )
goto abort;
V_5 = F_14 ( V_20 , F_43 ( V_108 ) ,
V_288 , 0x3210 ) ;
if ( V_5 )
goto abort;
V_5 = F_14 ( V_20 , F_43 ( V_108 ) ,
V_289 , 0x7654 ) ;
if ( V_5 )
goto abort;
}
if ( F_55 ( V_20 ) || F_54 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ||
F_52 ( V_20 ) || F_49 ( V_20 ) ||
F_53 ( V_20 ) ) {
V_5 = F_14 ( V_20 , F_43 ( V_108 ) ,
V_290 , 0x0001 ) ;
if ( V_5 )
goto abort;
}
V_5 = F_14 ( V_20 , F_43 ( V_108 ) , V_291 , 0x0000 ) ;
if ( V_5 )
goto abort;
V_175 = V_108 + 1 ;
V_25 -> V_175 [ V_108 ] = V_175 ;
F_97 ( V_175 , V_25 -> V_190 ) ;
if ( ! F_87 ( V_20 , V_108 ) )
V_25 -> V_186 [ V_175 ] = 1 << V_108 ;
V_5 = F_86 ( V_20 , V_108 ) ;
if ( V_5 )
goto abort;
V_5 = F_14 ( V_20 , F_43 ( V_108 ) , V_207 ,
0x0000 ) ;
abort:
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int F_133 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_25 -> V_123 ; V_12 ++ ) {
V_5 = F_131 ( V_20 , V_12 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static int F_134 ( struct V_292 * V_143 , void * V_153 )
{
struct V_19 * V_20 = V_143 -> V_293 ;
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_16 , V_108 ;
F_135 ( V_143 , L_15 ) ;
for ( V_108 = 0 ; V_108 < V_25 -> V_123 ; V_108 ++ )
F_136 ( V_143 , L_16 , V_108 ) ;
F_135 ( V_143 , L_17 ) ;
for ( V_16 = 0 ; V_16 < 32 ; V_16 ++ ) {
F_136 ( V_143 , L_18 , V_16 ) ;
F_136 ( V_143 , L_19 ,
F_10 ( V_20 , V_28 , V_16 ) ,
F_10 ( V_20 , V_33 , V_16 ) ) ;
for ( V_108 = 0 ; V_108 < V_25 -> V_123 ; V_108 ++ )
F_136 ( V_143 , L_20 ,
F_10 ( V_20 , F_43 ( V_108 ) , V_16 ) ) ;
F_135 ( V_143 , L_17 ) ;
}
return 0 ;
}
static int F_137 ( struct V_294 * V_294 , struct V_295 * V_295 )
{
return F_138 ( V_295 , F_134 , V_294 -> V_296 ) ;
}
static void F_139 ( struct V_292 * V_143 )
{
F_135 ( V_143 , L_21 ) ;
}
static void F_140 ( struct V_292 * V_143 , int V_297 ,
unsigned char * V_3 , int V_51 )
{
bool V_248 = ! ! ( V_51 & V_249 ) ;
int V_298 = ( ( V_51 & V_252 ) >>
V_253 ) ;
int V_179 = V_51 & V_255 ;
F_136 ( V_143 , L_22 ,
V_297 , ( V_248 ? L_23 : L_24 ) , & V_298 , V_179 , V_3 ) ;
}
static int F_141 ( struct V_292 * V_143 , struct V_19 * V_20 ,
int V_297 )
{
unsigned char V_299 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
unsigned char V_3 [ 6 ] ;
int V_5 , V_51 , V_179 ;
V_5 = F_117 ( V_20 , V_299 ) ;
if ( V_5 < 0 )
return V_5 ;
do {
V_5 = F_83 ( V_20 , V_297 , V_260 ) ;
if ( V_5 < 0 )
return V_5 ;
V_51 = F_7 ( V_20 , V_28 , V_256 ) ;
if ( V_51 < 0 )
return V_51 ;
V_179 = V_51 & V_255 ;
if ( V_179 == V_247 )
break;
V_5 = F_118 ( V_20 , V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
F_140 ( V_143 , V_297 , V_3 , V_51 ) ;
} while ( V_179 != V_247 );
return 0 ;
}
static int F_142 ( struct V_292 * V_143 , void * V_153 )
{
struct V_19 * V_20 = V_143 -> V_293 ;
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_297 ;
F_139 ( V_143 ) ;
for ( V_297 = 0 ; V_297 < 255 ; V_297 ++ ) {
F_12 ( & V_25 -> V_26 ) ;
F_141 ( V_143 , V_20 , V_297 ) ;
F_3 ( & V_25 -> V_26 ) ;
}
return 0 ;
}
static int F_143 ( struct V_294 * V_294 , struct V_295 * V_295 )
{
return F_138 ( V_295 , F_142 , V_294 -> V_296 ) ;
}
static void F_144 ( struct V_292 * V_143 ,
struct V_24 * V_25 )
{
int V_108 ;
F_135 ( V_143 , L_25 ) ;
for ( V_108 = 0 ; V_108 < V_25 -> V_123 ; V_108 ++ )
F_136 ( V_143 , L_26 , V_108 ) ;
F_135 ( V_143 , L_17 ) ;
}
static int F_145 ( struct V_292 * V_143 , void * V_153 )
{
struct V_19 * V_20 = V_143 -> V_293 ;
struct V_24 * V_25 = F_11 ( V_20 ) ;
struct V_140 * V_141 = V_149 ;
int V_108 , V_134 , V_300 ;
T_5 V_146 ;
if ( F_62 ( V_20 ) )
V_300 = F_67 ( V_149 ) ;
else
V_300 = F_67 ( V_149 ) - 3 ;
F_144 ( V_143 , V_25 ) ;
F_12 ( & V_25 -> V_26 ) ;
for ( V_134 = 0 ; V_134 < V_300 ; V_134 ++ ) {
F_136 ( V_143 , L_27 , V_141 [ V_134 ] . string ) ;
for ( V_108 = 0 ; V_108 < V_25 -> V_123 ; V_108 ++ ) {
F_60 ( V_20 , V_108 ) ;
V_146 = F_64 ( V_20 , V_134 , V_141 ,
V_108 ) ;
F_136 ( V_143 , L_28 , V_146 ) ;
}
F_135 ( V_143 , L_17 ) ;
}
F_3 ( & V_25 -> V_26 ) ;
return 0 ;
}
static int F_146 ( struct V_294 * V_294 , struct V_295 * V_295 )
{
return F_138 ( V_295 , F_145 , V_294 -> V_296 ) ;
}
static int F_147 ( struct V_292 * V_143 , void * V_153 )
{
struct V_19 * V_20 = V_143 -> V_293 ;
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_301 , V_5 ;
F_135 ( V_143 , L_29 ) ;
F_12 ( & V_25 -> V_26 ) ;
for ( V_301 = 0 ; V_301 < 32 ; V_301 ++ ) {
V_5 = F_14 (
V_20 , V_33 , V_302 ,
V_301 << V_303 ) ;
if ( V_5 < 0 )
goto V_111;
V_5 = F_7 ( V_20 , V_33 ,
V_302 ) ;
F_136 ( V_143 , L_30 , V_301 ,
V_5 & V_304 ) ;
}
V_111:
F_3 ( & V_25 -> V_26 ) ;
return 0 ;
}
static int F_148 ( struct V_294 * V_294 , struct V_295 * V_295 )
{
return F_138 ( V_295 , F_147 , V_294 -> V_296 ) ;
}
static int F_149 ( struct V_292 * V_143 , void * V_153 )
{
struct V_19 * V_20 = V_143 -> V_293 ;
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_16 , V_5 ;
F_135 ( V_143 , L_31 ) ;
F_12 ( & V_25 -> V_26 ) ;
for ( V_16 = 0 ; V_16 < 0x80 ; V_16 ++ ) {
V_5 = F_14 (
V_20 , V_33 , V_164 ,
V_16 << V_305 ) ;
if ( V_5 < 0 )
goto V_111;
V_5 = F_78 ( V_20 ) ;
if ( V_5 < 0 )
goto V_111;
V_5 = F_7 ( V_20 , V_33 ,
V_164 ) ;
F_136 ( V_143 , L_32 , V_16 ,
V_5 & V_306 ) ;
}
V_111:
F_3 ( & V_25 -> V_26 ) ;
return 0 ;
}
static int F_150 ( struct V_294 * V_294 , struct V_295 * V_295 )
{
return F_138 ( V_295 , F_149 , V_294 -> V_296 ) ;
}
int F_151 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
char * V_307 ;
F_37 ( & V_25 -> V_26 ) ;
V_25 -> V_76 = F_19 ( F_43 ( 0 ) , V_308 ) & 0xfff0 ;
F_38 ( & V_25 -> V_205 , F_130 ) ;
V_307 = F_152 ( V_309 , L_33 , V_20 -> V_310 ) ;
V_25 -> V_311 = F_153 ( V_307 , NULL ) ;
F_154 ( V_307 ) ;
F_155 ( L_34 , V_312 , V_25 -> V_311 , V_20 ,
& V_313 ) ;
F_155 ( L_35 , V_312 , V_25 -> V_311 , V_20 ,
& V_314 ) ;
F_155 ( L_36 , V_312 , V_25 -> V_311 , V_20 ,
& V_315 ) ;
F_155 ( L_37 , V_312 , V_25 -> V_311 , V_20 ,
& V_316 ) ;
F_155 ( L_38 , V_312 , V_25 -> V_311 , V_20 ,
& V_317 ) ;
return 0 ;
}
int F_156 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
int V_12 ;
F_17 ( V_28 , V_318 ,
0x0140 | V_319 ) ;
F_17 ( V_28 , V_320 , 0x0000 ) ;
F_17 ( V_28 , V_321 , 0x0000 ) ;
F_17 ( V_28 , V_322 , 0x5555 ) ;
F_17 ( V_28 , V_323 , 0x5555 ) ;
F_17 ( V_28 , V_324 , 0xaaaa ) ;
F_17 ( V_28 , V_325 , 0xaaaa ) ;
F_17 ( V_28 , V_326 , 0xffff ) ;
F_17 ( V_28 , V_327 , 0xffff ) ;
F_17 ( V_28 , V_328 , 0xfa41 ) ;
F_17 ( V_33 , V_329 , 0xffff ) ;
F_17 ( V_33 , V_330 ,
0x7 | V_331 | 0x70 |
V_332 ) ;
for ( V_12 = 0 ; V_12 < 32 ; V_12 ++ ) {
int V_333 = 0x1f ;
if ( V_20 -> V_23 -> V_334 &&
V_12 != V_20 -> V_310 && V_12 < V_20 -> V_268 -> V_23 -> V_335 )
V_333 = V_20 -> V_23 -> V_334 [ V_12 ] & 0x1f ;
F_17 ( V_33 , V_302 ,
V_336 |
( V_12 << V_303 ) |
V_333 ) ;
}
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ )
F_17 ( V_33 , V_337 ,
0x8000 | ( V_12 << V_338 ) |
( ( 1 << V_25 -> V_123 ) - 1 ) ) ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ )
F_17 ( V_33 , V_339 ,
V_340 |
( V_12 << V_341 ) ) ;
if ( F_55 ( V_20 ) || F_54 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ||
F_53 ( V_20 ) ) {
F_17 ( V_33 , V_342 , 0xffff ) ;
F_17 ( V_33 , V_343 , 0x9000 ) ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ )
F_17 ( V_33 , V_344 ,
0x8000 | ( V_12 << 8 ) ) ;
}
if ( F_55 ( V_20 ) || F_54 ( V_20 ) ||
F_51 ( V_20 ) || F_50 ( V_20 ) ||
F_52 ( V_20 ) || F_49 ( V_20 ) ||
F_53 ( V_20 ) ) {
for ( V_12 = 0 ; V_12 < V_25 -> V_123 ; V_12 ++ )
F_17 ( V_33 , V_345 ,
0x9000 | ( V_12 << 8 ) ) ;
}
F_17 ( V_28 , V_130 , V_346 ) ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_59 ( V_20 ) ;
if ( V_5 < 0 )
goto V_194;
V_5 = F_104 ( V_20 ) ;
V_194:
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int F_157 ( struct V_19 * V_20 , bool V_347 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
T_2 V_348 = ( V_347 ? 0x8800 : 0xc800 ) ;
unsigned long V_36 ;
int V_5 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_25 -> V_123 ; V_12 ++ ) {
V_5 = F_19 ( F_43 ( V_12 ) , V_181 ) ;
F_17 ( F_43 ( V_12 ) , V_181 , V_5 & 0xfffc ) ;
}
F_24 ( 2000 , 4000 ) ;
if ( V_347 )
F_17 ( V_28 , 0x04 , 0xc000 ) ;
else
F_17 ( V_28 , 0x04 , 0xc400 ) ;
V_36 = V_39 + 1 * V_40 ;
while ( F_23 ( V_39 , V_36 ) ) {
V_5 = F_19 ( V_28 , 0x00 ) ;
if ( ( V_5 & V_348 ) == V_348 )
break;
F_24 ( 1000 , 2000 ) ;
}
if ( F_158 ( V_39 , V_36 ) )
return - V_15 ;
return 0 ;
}
int F_159 ( struct V_19 * V_20 , int V_108 , int V_349 , int V_16 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_80 ( V_20 , V_108 , 0x16 , V_349 ) ;
if ( V_5 < 0 )
goto error;
V_5 = F_79 ( V_20 , V_108 , V_16 ) ;
error:
F_80 ( V_20 , V_108 , 0x16 , 0x0 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int F_160 ( struct V_19 * V_20 , int V_108 , int V_349 ,
int V_16 , int V_9 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_80 ( V_20 , V_108 , 0x16 , V_349 ) ;
if ( V_5 < 0 )
goto error;
V_5 = F_80 ( V_20 , V_108 , V_16 , V_9 ) ;
error:
F_80 ( V_20 , V_108 , 0x16 , 0x0 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
static int F_161 ( struct V_19 * V_20 , int V_108 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
if ( V_108 >= 0 && V_108 < V_25 -> V_123 )
return V_108 ;
return - V_22 ;
}
int
F_162 ( struct V_19 * V_20 , int V_108 , int V_4 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_3 = F_161 ( V_20 , V_108 ) ;
int V_5 ;
if ( V_3 < 0 )
return V_3 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_20 ( V_20 , V_3 , V_4 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int
F_163 ( struct V_19 * V_20 , int V_108 , int V_4 , T_2 V_9 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_3 = F_161 ( V_20 , V_108 ) ;
int V_5 ;
if ( V_3 < 0 )
return V_3 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_21 ( V_20 , V_3 , V_4 , V_9 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int
F_164 ( struct V_19 * V_20 , int V_108 , int V_4 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_3 = F_161 ( V_20 , V_108 ) ;
int V_5 ;
if ( V_3 < 0 )
return V_3 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_79 ( V_20 , V_3 , V_4 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
int
F_165 ( struct V_19 * V_20 , int V_108 , int V_4 ,
T_2 V_9 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_3 = F_161 ( V_20 , V_108 ) ;
int V_5 ;
if ( V_3 < 0 )
return V_3 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_80 ( V_20 , V_3 , V_4 , V_9 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
static int F_166 ( struct V_19 * V_20 , int * V_350 )
{
struct V_24 * V_25 = F_11 ( V_20 ) ;
int V_5 ;
int V_9 ;
* V_350 = 0 ;
F_12 ( & V_25 -> V_26 ) ;
V_5 = F_21 ( V_20 , 0x0 , 0x16 , 0x6 ) ;
if ( V_5 < 0 )
goto error;
V_5 = F_20 ( V_20 , 0x0 , 0x1a ) ;
if ( V_5 < 0 )
goto error;
V_5 = F_21 ( V_20 , 0x0 , 0x1a , V_5 | ( 1 << 5 ) ) ;
if ( V_5 < 0 )
goto error;
F_24 ( 10000 , 12000 ) ;
V_9 = F_20 ( V_20 , 0x0 , 0x1a ) ;
if ( V_9 < 0 ) {
V_5 = V_9 ;
goto error;
}
V_5 = F_21 ( V_20 , 0x0 , 0x1a , V_5 & ~ ( 1 << 5 ) ) ;
if ( V_5 < 0 )
goto error;
* V_350 = ( ( V_9 & 0x1f ) - 5 ) * 5 ;
error:
F_21 ( V_20 , 0x0 , 0x16 , 0x0 ) ;
F_3 ( & V_25 -> V_26 ) ;
return V_5 ;
}
static int F_167 ( struct V_19 * V_20 , int * V_350 )
{
int V_351 = F_53 ( V_20 ) ? 3 : 0 ;
int V_5 ;
* V_350 = 0 ;
V_5 = F_159 ( V_20 , V_351 , 6 , 27 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_350 = ( V_5 & 0xff ) - 25 ;
return 0 ;
}
int F_168 ( struct V_19 * V_20 , int * V_350 )
{
if ( F_53 ( V_20 ) || F_55 ( V_20 ) )
return F_167 ( V_20 , V_350 ) ;
return F_166 ( V_20 , V_350 ) ;
}
int F_169 ( struct V_19 * V_20 , int * V_350 )
{
int V_351 = F_53 ( V_20 ) ? 3 : 0 ;
int V_5 ;
if ( ! F_53 ( V_20 ) && ! F_55 ( V_20 ) )
return - V_352 ;
* V_350 = 0 ;
V_5 = F_159 ( V_20 , V_351 , 6 , 26 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_350 = ( ( ( V_5 >> 8 ) & 0x1f ) * 5 ) - 25 ;
return 0 ;
}
int F_170 ( struct V_19 * V_20 , int V_350 )
{
int V_351 = F_53 ( V_20 ) ? 3 : 0 ;
int V_5 ;
if ( ! F_53 ( V_20 ) && ! F_55 ( V_20 ) )
return - V_352 ;
V_5 = F_159 ( V_20 , V_351 , 6 , 26 ) ;
if ( V_5 < 0 )
return V_5 ;
V_350 = F_171 ( F_172 ( V_350 , 5 ) + 5 , 0 , 0x1f ) ;
return F_160 ( V_20 , V_351 , 6 , 26 ,
( V_5 & 0xe0ff ) | ( V_350 << 8 ) ) ;
}
int F_173 ( struct V_19 * V_20 , bool * V_353 )
{
int V_351 = F_53 ( V_20 ) ? 3 : 0 ;
int V_5 ;
if ( ! F_53 ( V_20 ) && ! F_55 ( V_20 ) )
return - V_352 ;
* V_353 = false ;
V_5 = F_159 ( V_20 , V_351 , 6 , 26 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_353 = ! ! ( V_5 & 0x40 ) ;
return 0 ;
}
static int T_7 F_174 ( void )
{
#if F_175 ( V_354 )
F_176 ( & V_355 ) ;
#endif
#if F_175 ( V_356 )
F_176 ( & V_357 ) ;
#endif
#if F_175 ( V_358 )
F_176 ( & V_359 ) ;
#endif
#if F_175 ( V_360 )
F_176 ( & V_361 ) ;
#endif
return 0 ;
}
static void T_8 F_177 ( void )
{
#if F_175 ( V_360 )
F_178 ( & V_361 ) ;
#endif
#if F_175 ( V_358 )
F_178 ( & V_359 ) ;
#endif
#if F_175 ( V_356 )
F_178 ( & V_357 ) ;
#endif
#if F_175 ( V_354 )
F_178 ( & V_355 ) ;
#endif
}
