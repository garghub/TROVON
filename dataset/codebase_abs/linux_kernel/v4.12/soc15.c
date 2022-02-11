static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 , V_5 , V_6 ;
T_1 V_7 ;
struct V_8 * V_9 ;
if ( V_2 -> V_10 == V_11 )
V_9 = & V_12 ;
else
F_2 () ;
V_5 = V_9 -> V_13 ;
V_6 = V_9 -> V_14 ;
F_3 ( & V_2 -> V_15 , V_4 ) ;
F_4 ( V_5 , V_3 ) ;
( void ) F_5 ( V_5 ) ;
V_7 = F_5 ( V_6 ) ;
F_6 ( & V_2 -> V_15 , V_4 ) ;
return V_7 ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_16 )
{
unsigned long V_4 , V_5 , V_6 ;
struct V_8 * V_9 ;
if ( V_2 -> V_10 == V_11 )
V_9 = & V_12 ;
else
F_2 () ;
V_5 = V_9 -> V_13 ;
V_6 = V_9 -> V_14 ;
F_3 ( & V_2 -> V_15 , V_4 ) ;
F_4 ( V_5 , V_3 ) ;
( void ) F_5 ( V_5 ) ;
F_4 ( V_6 , V_16 ) ;
( void ) F_5 ( V_6 ) ;
F_6 ( & V_2 -> V_15 , V_4 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 , V_5 , V_6 ;
T_1 V_7 ;
V_5 = F_9 ( V_17 , 0 , V_18 ) ;
V_6 = F_9 ( V_17 , 0 , V_19 ) ;
F_3 ( & V_2 -> V_20 , V_4 ) ;
F_4 ( V_5 , ( ( V_3 ) & 0x1ff ) ) ;
V_7 = F_5 ( V_6 ) ;
F_6 ( & V_2 -> V_20 , V_4 ) ;
return V_7 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_16 )
{
unsigned long V_4 , V_5 , V_6 ;
V_5 = F_9 ( V_17 , 0 , V_18 ) ;
V_6 = F_9 ( V_17 , 0 , V_19 ) ;
F_3 ( & V_2 -> V_20 , V_4 ) ;
F_4 ( V_5 , ( ( V_3 ) & 0x1ff ) ) ;
F_4 ( V_6 , ( V_16 ) ) ;
F_6 ( & V_2 -> V_20 , V_4 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 , V_5 , V_6 ;
T_1 V_7 ;
V_5 = F_9 ( V_21 , 0 , V_22 ) ;
V_6 = F_9 ( V_21 , 0 , V_23 ) ;
F_3 ( & V_2 -> V_24 , V_4 ) ;
F_4 ( V_5 , ( V_3 ) ) ;
V_7 = F_5 ( V_6 ) ;
F_6 ( & V_2 -> V_24 , V_4 ) ;
return V_7 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_16 )
{
unsigned long V_4 , V_5 , V_6 ;
V_5 = F_9 ( V_21 , 0 , V_22 ) ;
V_6 = F_9 ( V_21 , 0 , V_23 ) ;
F_3 ( & V_2 -> V_24 , V_4 ) ;
F_4 ( V_5 , ( V_3 ) ) ;
F_4 ( V_6 , ( V_16 ) ) ;
F_6 ( & V_2 -> V_24 , V_4 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
return F_14 ( V_2 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_25 ) ;
switch ( V_2 -> V_10 ) {
case V_11 :
F_17 ( V_2 ,
V_26 ,
( const T_1 ) F_18 ( V_26 ) ) ;
break;
default:
break;
}
F_19 ( & V_2 -> V_25 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 == V_11 )
return V_2 -> clock . V_27 . V_28 / 4 ;
else
return V_2 -> clock . V_27 . V_28 ;
}
void F_21 ( struct V_1 * V_2 ,
T_1 V_29 , T_1 V_30 , T_1 V_31 , T_1 V_32 )
{
T_1 V_33 = 0 ;
V_33 = F_22 ( V_33 , V_34 , V_35 , V_30 ) ;
V_33 = F_22 ( V_33 , V_34 , V_36 , V_29 ) ;
V_33 = F_22 ( V_33 , V_34 , V_37 , V_32 ) ;
V_33 = F_22 ( V_33 , V_34 , V_38 , V_31 ) ;
F_4 ( F_9 ( V_21 , 0 , V_39 ) , V_33 ) ;
}
static void F_23 ( struct V_1 * V_2 , bool V_40 )
{
}
static bool F_24 ( struct V_1 * V_2 )
{
return false ;
}
static bool F_25 ( struct V_1 * V_2 ,
T_2 * V_41 , T_1 V_42 )
{
T_1 * V_43 ;
T_1 V_44 , V_45 ;
if ( V_41 == NULL )
return false ;
if ( V_42 == 0 )
return false ;
if ( V_2 -> V_4 & V_46 )
return false ;
V_43 = ( T_1 * ) V_41 ;
V_45 = F_26 ( V_42 , 4 ) / 4 ;
F_4 ( F_9 ( V_47 , 0 , V_48 ) , 0 ) ;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ )
V_43 [ V_44 ] = F_5 ( F_9 ( V_47 , 0 , V_49 ) ) ;
return true ;
}
static T_3 F_27 ( struct V_1 * V_2 , T_1 V_50 ,
T_1 V_51 , T_1 V_52 )
{
T_3 V_53 ;
F_16 ( & V_2 -> V_25 ) ;
if ( V_50 != 0xffffffff || V_51 != 0xffffffff )
F_28 ( V_2 , V_50 , V_51 , 0xffffffff ) ;
V_53 = F_5 ( V_52 ) ;
if ( V_50 != 0xffffffff || V_51 != 0xffffffff )
F_28 ( V_2 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_19 ( & V_2 -> V_25 ) ;
return V_53 ;
}
static T_3 F_29 ( struct V_1 * V_2 ,
bool V_54 , T_1 V_50 ,
T_1 V_51 , T_1 V_52 )
{
if ( V_54 ) {
return F_27 ( V_2 , V_50 , V_51 , V_52 ) ;
} else {
switch ( V_52 ) {
case F_9 ( V_21 , 0 , V_55 ) :
return V_2 -> V_56 . V_57 . V_58 ;
default:
return F_5 ( V_52 ) ;
}
}
}
static int F_30 ( struct V_1 * V_2 , T_1 V_50 ,
T_1 V_51 , T_1 V_52 , T_1 * V_59 )
{
struct V_60 * V_61 = NULL ;
struct V_60 * V_62 ;
T_3 V_63 , V_44 ;
* V_59 = 0 ;
switch ( V_2 -> V_10 ) {
case V_11 :
V_61 = V_64 ;
V_63 = F_18 ( V_64 ) ;
break;
default:
return - V_65 ;
}
if ( V_61 ) {
for ( V_44 = 0 ; V_44 < V_63 ; V_44 ++ ) {
V_62 = V_61 + V_44 ;
if ( V_52 != V_62 -> V_52 )
continue;
if ( ! V_62 -> V_66 )
* V_59 = F_29 ( V_2 ,
V_62 -> V_67 ,
V_50 , V_51 , V_52 ) ;
return 0 ;
}
}
for ( V_44 = 0 ; V_44 < F_18 ( V_68 ) ; V_44 ++ ) {
if ( V_52 != V_68 [ V_44 ] . V_52 )
continue;
if ( ! V_68 [ V_44 ] . V_66 )
* V_59 = F_29 ( V_2 ,
V_68 [ V_44 ] . V_67 ,
V_50 , V_51 , V_52 ) ;
return 0 ;
}
return - V_65 ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_1 V_44 ;
F_32 ( V_2 -> V_69 , L_1 ) ;
F_33 ( V_2 -> V_70 ) ;
F_34 ( V_2 ) ;
F_35 ( 100 ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_71 ; V_44 ++ ) {
if ( F_14 ( V_2 ) != 0xffffffff )
break;
F_35 ( 1 ) ;
}
}
static int F_36 ( struct V_1 * V_2 )
{
F_37 ( V_2 , true ) ;
F_31 ( V_2 ) ;
F_37 ( V_2 , false ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , T_1 V_72 , T_1 V_73 )
{
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , T_1 V_74 , T_1 V_75 )
{
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
if ( F_41 ( V_2 -> V_70 -> V_76 ) )
return;
if ( V_77 == 0 )
return;
if ( V_2 -> V_4 & V_46 )
return;
if ( ! ( V_2 -> V_78 . V_79 & ( V_80 |
V_81 ) ) )
return;
}
static void F_42 ( struct V_1 * V_2 )
{
if ( V_82 == 0 )
return;
}
static void F_43 ( struct V_1 * V_2 ,
bool V_83 )
{
F_44 ( V_2 , V_83 ) ;
F_45 ( V_2 , V_83 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 ) ;
if ( F_48 ( V_2 ) )
V_2 -> V_84 . V_85 = & V_86 ;
switch ( V_2 -> V_10 ) {
case V_11 :
F_49 ( V_2 , & V_87 ) ;
F_49 ( V_2 , & V_88 ) ;
F_49 ( V_2 , & V_89 ) ;
F_49 ( V_2 , & V_90 ) ;
F_49 ( V_2 , & V_91 ) ;
if ( V_92 == 2 || V_92 == - 1 )
F_49 ( V_2 , & V_93 ) ;
if ( ! F_48 ( V_2 ) )
F_49 ( V_2 , & V_94 ) ;
if ( V_2 -> V_95 || F_48 ( V_2 ) )
F_49 ( V_2 , & V_96 ) ;
F_49 ( V_2 , & V_97 ) ;
F_49 ( V_2 , & V_98 ) ;
F_49 ( V_2 , & V_99 ) ;
F_49 ( V_2 , & V_100 ) ;
break;
default:
return - V_65 ;
}
return 0 ;
}
static T_3 F_50 ( struct V_1 * V_2 )
{
return F_51 ( V_2 ) ;
}
int F_52 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_53 ( void * V_101 )
{
bool V_102 = false ;
struct V_1 * V_2 = (struct V_1 * ) V_101 ;
V_2 -> V_103 = NULL ;
V_2 -> V_104 = NULL ;
V_2 -> V_105 = & F_1 ;
V_2 -> V_106 = & F_7 ;
V_2 -> V_107 = & F_8 ;
V_2 -> V_108 = & F_10 ;
V_2 -> V_109 = & F_11 ;
V_2 -> V_110 = & F_12 ;
V_2 -> V_111 = & V_112 ;
if ( F_54 ( V_2 , V_113 ) &&
( V_114 & ( 1 << V_113 ) ) )
V_102 = true ;
if ( F_48 ( V_2 ) ) {
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
}
switch( V_2 -> V_10 ) {
case V_11 :
F_57 ( V_2 ) ;
break;
default:
return - V_65 ;
}
V_2 -> V_115 = F_50 ( V_2 ) ;
V_2 -> V_116 = 0xFF ;
switch ( V_2 -> V_10 ) {
case V_11 :
V_2 -> V_117 = V_118 |
V_119 |
V_120 |
V_121 |
V_122 |
V_123 |
V_124 |
V_125 |
V_126 |
V_127 |
V_128 |
V_129 |
V_130 |
V_131 |
V_132 |
V_133 |
V_134 |
V_135 |
V_136 ;
V_2 -> V_137 = 0 ;
V_2 -> V_116 = 0x1 ;
break;
default:
return - V_65 ;
}
V_2 -> V_138 . V_139 = F_58 ( V_2 , V_92 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
static int F_60 ( void * V_101 )
{
struct V_1 * V_2 = (struct V_1 * ) V_101 ;
if ( F_48 ( V_2 ) )
F_61 ( V_2 ) ;
return 0 ;
}
static int F_62 ( void * V_101 )
{
struct V_1 * V_2 = (struct V_1 * ) V_101 ;
if ( F_48 ( V_2 ) )
F_63 ( V_2 ) ;
return 0 ;
}
static int F_64 ( void * V_101 )
{
return 0 ;
}
static int F_65 ( void * V_101 )
{
struct V_1 * V_2 = (struct V_1 * ) V_101 ;
F_15 ( V_2 ) ;
F_40 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 , true ) ;
return 0 ;
}
static int F_66 ( void * V_101 )
{
struct V_1 * V_2 = (struct V_1 * ) V_101 ;
F_43 ( V_2 , false ) ;
if ( F_48 ( V_2 ) )
F_67 ( V_2 ) ;
return 0 ;
}
static int F_68 ( void * V_101 )
{
struct V_1 * V_2 = (struct V_1 * ) V_101 ;
return F_66 ( V_2 ) ;
}
static int F_69 ( void * V_101 )
{
struct V_1 * V_2 = (struct V_1 * ) V_101 ;
return F_65 ( V_2 ) ;
}
static bool F_70 ( void * V_101 )
{
return true ;
}
static int F_71 ( void * V_101 )
{
return 0 ;
}
static int F_72 ( void * V_101 )
{
return 0 ;
}
static void F_73 ( struct V_1 * V_2 , bool V_83 )
{
T_3 V_140 , V_6 ;
V_140 = V_6 = F_5 ( F_9 ( V_141 , 0 , V_142 ) ) ;
if ( V_83 && ( V_2 -> V_117 & V_128 ) )
V_6 |= V_143 ;
else
V_6 &= ~ V_143 ;
if ( V_140 != V_6 )
F_4 ( F_9 ( V_141 , 0 , V_142 ) , V_6 ) ;
}
static void F_74 ( struct V_1 * V_2 , bool V_83 )
{
T_3 V_140 , V_6 ;
V_140 = V_6 = F_5 ( F_9 ( V_144 , 0 , V_145 ) ) ;
if ( V_83 && ( V_2 -> V_117 & V_129 ) )
V_6 &= ~ ( 0x01000000 |
0x02000000 |
0x04000000 |
0x08000000 |
0x10000000 |
0x20000000 |
0x40000000 |
0x80000000 ) ;
else
V_6 |= ( 0x01000000 |
0x02000000 |
0x04000000 |
0x08000000 |
0x10000000 |
0x20000000 |
0x40000000 |
0x80000000 ) ;
if ( V_140 != V_6 )
F_4 ( F_9 ( V_144 , 0 , V_145 ) , V_6 ) ;
}
static void F_75 ( struct V_1 * V_2 , bool V_83 )
{
T_3 V_140 , V_6 ;
V_140 = V_6 = F_5 ( F_9 ( V_144 , 0 , V_146 ) ) ;
if ( V_83 && ( V_2 -> V_117 & V_130 ) )
V_6 |= 1 ;
else
V_6 &= ~ 1 ;
if ( V_140 != V_6 )
F_4 ( F_9 ( V_144 , 0 , V_146 ) , V_6 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
bool V_83 )
{
T_3 V_140 , V_6 ;
V_140 = V_6 = F_5 ( F_9 ( V_47 , 0 , V_147 ) ) ;
if ( V_83 && ( V_2 -> V_117 & V_131 ) )
V_6 &= ~ ( V_148 |
V_149 ) ;
else
V_6 |= V_148 |
V_149 ;
if ( V_140 != V_6 )
F_4 ( F_9 ( V_47 , 0 , V_147 ) , V_6 ) ;
}
static void F_77 ( struct V_1 * V_2 ,
bool V_83 )
{
T_3 V_6 ;
V_6 = F_5 ( F_9 ( V_150 , 0 , V_151 ) ) ;
V_6 &= ~ V_152 ;
F_4 ( F_9 ( V_150 , 0 , V_151 ) , V_6 ) ;
if ( V_83 && ( V_2 -> V_117 & V_132 ) ) {
V_6 = F_5 ( F_9 ( V_150 , 0 , V_153 ) ) ;
V_6 &= ~ V_154 ;
V_6 |= V_155 ;
F_4 ( F_9 ( V_150 , 0 , V_153 ) , V_6 ) ;
} else {
V_6 = F_5 ( F_9 ( V_150 , 0 , V_153 ) ) ;
V_6 &= ~ V_154 ;
V_6 |= V_156 ;
F_4 ( F_9 ( V_150 , 0 , V_153 ) , V_6 ) ;
}
F_4 ( F_9 ( V_150 , 0 , V_151 ) ,
V_157 ) ;
}
static int F_78 ( void * V_101 ,
enum V_158 V_40 )
{
struct V_1 * V_2 = (struct V_1 * ) V_101 ;
if ( F_48 ( V_2 ) )
return 0 ;
switch ( V_2 -> V_10 ) {
case V_11 :
F_79 ( V_2 ,
V_40 == V_159 ? true : false ) ;
F_80 ( V_2 ,
V_40 == V_159 ? true : false ) ;
F_73 ( V_2 ,
V_40 == V_159 ? true : false ) ;
F_74 ( V_2 ,
V_40 == V_159 ? true : false ) ;
F_75 ( V_2 ,
V_40 == V_159 ? true : false ) ;
F_76 ( V_2 ,
V_40 == V_159 ? true : false ) ;
F_77 ( V_2 ,
V_40 == V_159 ? true : false ) ;
break;
default:
break;
}
return 0 ;
}
static void F_81 ( void * V_101 , T_1 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_101 ;
int V_6 ;
if ( F_48 ( V_2 ) )
* V_4 = 0 ;
F_82 ( V_2 , V_4 ) ;
V_6 = F_5 ( F_9 ( V_141 , 0 , V_142 ) ) ;
if ( V_6 & V_143 )
* V_4 |= V_128 ;
V_6 = F_5 ( F_9 ( V_144 , 0 , V_145 ) ) ;
if ( ! ( V_6 & 0x01000000 ) )
* V_4 |= V_129 ;
V_6 = F_5 ( F_9 ( V_144 , 0 , V_146 ) ) ;
if ( V_6 & 0x1 )
* V_4 |= V_130 ;
V_6 = F_5 ( F_9 ( V_47 , 0 , V_147 ) ) ;
if ( ! ( V_6 & V_148 ) )
* V_4 |= V_131 ;
V_6 = F_5 ( F_9 ( V_150 , 0 , V_153 ) ) ;
if ( V_6 & V_155 )
* V_4 |= V_132 ;
}
static int F_83 ( void * V_101 ,
enum V_160 V_40 )
{
return 0 ;
}
