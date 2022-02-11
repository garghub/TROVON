static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 , V_5 , V_6 ;
T_1 V_7 ;
struct V_8 * V_9 ;
if ( V_2 -> V_4 & V_10 )
V_9 = & V_11 ;
else
V_9 = & V_12 ;
V_5 = V_9 -> V_13 ;
V_6 = V_9 -> V_14 ;
F_2 ( & V_2 -> V_15 , V_4 ) ;
F_3 ( V_5 , V_3 ) ;
( void ) F_4 ( V_5 ) ;
V_7 = F_4 ( V_6 ) ;
F_5 ( & V_2 -> V_15 , V_4 ) ;
return V_7 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_16 )
{
unsigned long V_4 , V_5 , V_6 ;
struct V_8 * V_9 ;
if ( V_2 -> V_4 & V_10 )
V_9 = & V_11 ;
else
V_9 = & V_12 ;
V_5 = V_9 -> V_13 ;
V_6 = V_9 -> V_14 ;
F_2 ( & V_2 -> V_15 , V_4 ) ;
F_3 ( V_5 , V_3 ) ;
( void ) F_4 ( V_5 ) ;
F_3 ( V_6 , V_16 ) ;
( void ) F_4 ( V_6 ) ;
F_5 ( & V_2 -> V_15 , V_4 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 , V_5 , V_6 ;
T_1 V_7 ;
V_5 = F_8 ( V_17 , 0 , V_18 ) ;
V_6 = F_8 ( V_17 , 0 , V_19 ) ;
F_2 ( & V_2 -> V_20 , V_4 ) ;
F_3 ( V_5 , ( ( V_3 ) & 0x1ff ) ) ;
V_7 = F_4 ( V_6 ) ;
F_5 ( & V_2 -> V_20 , V_4 ) ;
return V_7 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_16 )
{
unsigned long V_4 , V_5 , V_6 ;
V_5 = F_8 ( V_17 , 0 , V_18 ) ;
V_6 = F_8 ( V_17 , 0 , V_19 ) ;
F_2 ( & V_2 -> V_20 , V_4 ) ;
F_3 ( V_5 , ( ( V_3 ) & 0x1ff ) ) ;
F_3 ( V_6 , ( V_16 ) ) ;
F_5 ( & V_2 -> V_20 , V_4 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 , V_5 , V_6 ;
T_1 V_7 ;
V_5 = F_8 ( V_21 , 0 , V_22 ) ;
V_6 = F_8 ( V_21 , 0 , V_23 ) ;
F_2 ( & V_2 -> V_24 , V_4 ) ;
F_3 ( V_5 , ( V_3 ) ) ;
V_7 = F_4 ( V_6 ) ;
F_5 ( & V_2 -> V_24 , V_4 ) ;
return V_7 ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_16 )
{
unsigned long V_4 , V_5 , V_6 ;
V_5 = F_8 ( V_21 , 0 , V_22 ) ;
V_6 = F_8 ( V_21 , 0 , V_23 ) ;
F_2 ( & V_2 -> V_24 , V_4 ) ;
F_3 ( V_5 , ( V_3 ) ) ;
F_3 ( V_6 , ( V_16 ) ) ;
F_5 ( & V_2 -> V_24 , V_4 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_7 ;
F_2 ( & V_2 -> V_25 , V_4 ) ;
F_13 ( V_21 , 0 , V_26 , ( V_3 ) ) ;
V_7 = F_14 ( V_21 , 0 , V_27 ) ;
F_5 ( & V_2 -> V_25 , V_4 ) ;
return V_7 ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_16 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_25 , V_4 ) ;
F_13 ( V_21 , 0 , V_26 , ( V_3 ) ) ;
F_13 ( V_21 , 0 , V_27 , ( V_16 ) ) ;
F_5 ( & V_2 -> V_25 , V_4 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_7 ;
F_2 ( & V_2 -> V_28 , V_4 ) ;
F_13 ( V_21 , 0 , V_29 , ( V_3 ) ) ;
V_7 = F_14 ( V_21 , 0 , V_30 ) ;
F_5 ( & V_2 -> V_28 , V_4 ) ;
return V_7 ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_16 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_28 , V_4 ) ;
F_13 ( V_21 , 0 , V_29 , ( V_3 ) ) ;
F_13 ( V_21 , 0 , V_30 , ( V_16 ) ) ;
F_5 ( & V_2 -> V_28 , V_4 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 & V_10 )
return F_19 ( V_2 ) ;
else
return F_20 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_31 ) ;
switch ( V_2 -> V_32 ) {
case V_33 :
F_23 ( V_2 ,
V_34 ,
( const T_1 ) F_24 ( V_34 ) ) ;
break;
case V_35 :
F_23 ( V_2 ,
V_36 ,
( const T_1 ) F_24 ( V_36 ) ) ;
break;
default:
break;
}
F_25 ( & V_2 -> V_31 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_32 == V_33 )
return V_2 -> clock . V_37 . V_38 / 4 ;
else
return V_2 -> clock . V_37 . V_38 ;
}
void F_27 ( struct V_1 * V_2 ,
T_1 V_39 , T_1 V_40 , T_1 V_41 , T_1 V_42 )
{
T_1 V_43 = 0 ;
V_43 = F_28 ( V_43 , V_44 , V_45 , V_40 ) ;
V_43 = F_28 ( V_43 , V_44 , V_46 , V_39 ) ;
V_43 = F_28 ( V_43 , V_44 , V_47 , V_42 ) ;
V_43 = F_28 ( V_43 , V_44 , V_48 , V_41 ) ;
F_3 ( F_8 ( V_21 , 0 , V_49 ) , V_43 ) ;
}
static void F_29 ( struct V_1 * V_2 , bool V_50 )
{
}
static bool F_30 ( struct V_1 * V_2 )
{
return false ;
}
static bool F_31 ( struct V_1 * V_2 ,
T_2 * V_51 , T_1 V_52 )
{
T_1 * V_53 ;
T_1 V_54 , V_55 ;
if ( V_51 == NULL )
return false ;
if ( V_52 == 0 )
return false ;
if ( V_2 -> V_4 & V_10 )
return false ;
V_53 = ( T_1 * ) V_51 ;
V_55 = F_32 ( V_52 , 4 ) / 4 ;
F_3 ( F_8 ( V_56 , 0 , V_57 ) , 0 ) ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ )
V_53 [ V_54 ] = F_4 ( F_8 ( V_56 , 0 , V_58 ) ) ;
return true ;
}
static T_3 F_33 ( struct V_1 * V_2 , T_1 V_59 ,
T_1 V_60 , T_1 V_61 )
{
T_3 V_62 ;
F_22 ( & V_2 -> V_31 ) ;
if ( V_59 != 0xffffffff || V_60 != 0xffffffff )
F_34 ( V_2 , V_59 , V_60 , 0xffffffff ) ;
V_62 = F_4 ( V_61 ) ;
if ( V_59 != 0xffffffff || V_60 != 0xffffffff )
F_34 ( V_2 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_25 ( & V_2 -> V_31 ) ;
return V_62 ;
}
static T_3 F_35 ( struct V_1 * V_2 ,
bool V_63 , T_1 V_59 ,
T_1 V_60 , T_1 V_61 )
{
if ( V_63 ) {
return F_33 ( V_2 , V_59 , V_60 , V_61 ) ;
} else {
switch ( V_61 ) {
case F_8 ( V_21 , 0 , V_64 ) :
return V_2 -> V_65 . V_66 . V_67 ;
default:
return F_4 ( V_61 ) ;
}
}
}
static int F_36 ( struct V_1 * V_2 , T_1 V_59 ,
T_1 V_60 , T_1 V_61 , T_1 * V_68 )
{
T_3 V_54 ;
* V_68 = 0 ;
for ( V_54 = 0 ; V_54 < F_24 ( V_69 ) ; V_54 ++ ) {
if ( V_61 != V_69 [ V_54 ] . V_61 )
continue;
* V_68 = F_35 ( V_2 ,
V_69 [ V_54 ] . V_70 ,
V_59 , V_60 , V_61 ) ;
return 0 ;
}
return - V_71 ;
}
static void F_37 ( struct V_1 * V_2 )
{
T_1 V_54 ;
F_38 ( V_2 -> V_72 , L_1 ) ;
F_39 ( V_2 -> V_73 ) ;
F_40 ( V_2 ) ;
F_41 ( 100 ) ;
for ( V_54 = 0 ; V_54 < V_2 -> V_74 ; V_54 ++ ) {
T_1 V_75 = ( V_2 -> V_4 & V_10 ) ?
F_19 ( V_2 ) :
F_20 ( V_2 ) ;
if ( V_75 != 0xffffffff )
break;
F_41 ( 1 ) ;
}
}
static int F_42 ( struct V_1 * V_2 )
{
F_43 ( V_2 , true ) ;
F_37 ( V_2 ) ;
F_43 ( V_2 , false ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , T_1 V_76 , T_1 V_77 )
{
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , T_1 V_78 , T_1 V_79 )
{
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
if ( F_47 ( V_2 -> V_73 -> V_80 ) )
return;
if ( V_81 == 0 )
return;
if ( V_2 -> V_4 & V_10 )
return;
if ( ! ( V_2 -> V_82 . V_83 & ( V_84 |
V_85 ) ) )
return;
}
static void F_48 ( struct V_1 * V_2 )
{
if ( V_86 == 0 )
return;
}
static void F_49 ( struct V_1 * V_2 ,
bool V_87 )
{
if ( V_2 -> V_4 & V_10 ) {
F_50 ( V_2 , V_87 ) ;
} else {
F_51 ( V_2 , V_87 ) ;
F_52 ( V_2 , V_87 ) ;
}
}
int F_53 ( struct V_1 * V_2 )
{
F_54 ( V_2 ) ;
if ( F_55 ( V_2 ) )
V_2 -> V_88 . V_89 = & V_90 ;
switch ( V_2 -> V_32 ) {
case V_33 :
F_56 ( V_2 , & V_91 ) ;
F_56 ( V_2 , & V_92 ) ;
F_56 ( V_2 , & V_93 ) ;
if ( V_94 == 2 || V_94 == - 1 )
F_56 ( V_2 , & V_95 ) ;
if ( ! F_55 ( V_2 ) )
F_56 ( V_2 , & V_96 ) ;
if ( V_2 -> V_97 || F_55 ( V_2 ) )
F_56 ( V_2 , & V_98 ) ;
F_56 ( V_2 , & V_99 ) ;
F_56 ( V_2 , & V_100 ) ;
F_56 ( V_2 , & V_101 ) ;
F_56 ( V_2 , & V_102 ) ;
break;
case V_35 :
F_56 ( V_2 , & V_91 ) ;
F_56 ( V_2 , & V_92 ) ;
F_56 ( V_2 , & V_93 ) ;
F_56 ( V_2 , & V_103 ) ;
F_56 ( V_2 , & V_96 ) ;
if ( V_2 -> V_97 || F_55 ( V_2 ) )
F_56 ( V_2 , & V_98 ) ;
F_56 ( V_2 , & V_99 ) ;
F_56 ( V_2 , & V_100 ) ;
F_56 ( V_2 , & V_104 ) ;
break;
default:
return - V_71 ;
}
return 0 ;
}
static T_3 F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 & V_10 )
return F_58 ( V_2 ) ;
else
return F_59 ( V_2 ) ;
}
static int F_60 ( void * V_105 )
{
bool V_106 = false ;
struct V_1 * V_2 = (struct V_1 * ) V_105 ;
V_2 -> V_107 = NULL ;
V_2 -> V_108 = NULL ;
V_2 -> V_109 = & F_1 ;
V_2 -> V_110 = & F_6 ;
V_2 -> V_111 = & F_7 ;
V_2 -> V_112 = & F_9 ;
V_2 -> V_113 = & F_10 ;
V_2 -> V_114 = & F_11 ;
V_2 -> V_115 = & F_12 ;
V_2 -> V_116 = & F_15 ;
V_2 -> V_117 = & F_16 ;
V_2 -> V_118 = & F_17 ;
V_2 -> V_119 = & V_120 ;
if ( F_61 ( V_2 , V_121 ) &&
( V_122 & ( 1 << V_121 ) ) )
V_106 = true ;
switch( V_2 -> V_32 ) {
case V_33 :
F_62 ( V_2 ) ;
break;
case V_35 :
F_63 ( V_2 ) ;
break;
default:
return - V_71 ;
}
V_2 -> V_123 = F_57 ( V_2 ) ;
V_2 -> V_124 = 0xFF ;
switch ( V_2 -> V_32 ) {
case V_33 :
V_2 -> V_125 = V_126 |
V_127 |
V_128 |
V_129 |
V_130 |
V_131 |
V_132 |
V_133 |
V_134 |
V_135 |
V_136 |
V_137 |
V_138 |
V_139 |
V_140 |
V_141 |
V_142 |
V_143 |
V_144 ;
V_2 -> V_145 = 0 ;
V_2 -> V_124 = 0x1 ;
break;
case V_35 :
V_2 -> V_125 = V_126 |
V_127 |
V_128 |
V_129 |
V_130 |
V_131 |
V_132 |
V_133 |
V_134 |
V_135 |
V_146 |
V_136 |
V_137 |
V_138 |
V_139 |
V_143 |
V_144 |
V_141 |
V_142 ;
V_2 -> V_145 = V_147 |
V_148 ;
V_2 -> V_124 = 0x1 ;
break;
default:
return - V_71 ;
}
if ( F_55 ( V_2 ) ) {
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
}
V_2 -> V_149 . V_150 = F_66 ( V_2 , V_94 ) ;
F_67 ( V_2 ) ;
return 0 ;
}
static int F_68 ( void * V_105 )
{
struct V_1 * V_2 = (struct V_1 * ) V_105 ;
if ( F_55 ( V_2 ) )
F_69 ( V_2 ) ;
return 0 ;
}
static int F_70 ( void * V_105 )
{
struct V_1 * V_2 = (struct V_1 * ) V_105 ;
if ( F_55 ( V_2 ) )
F_71 ( V_2 ) ;
return 0 ;
}
static int F_72 ( void * V_105 )
{
return 0 ;
}
static int F_73 ( void * V_105 )
{
struct V_1 * V_2 = (struct V_1 * ) V_105 ;
F_21 ( V_2 ) ;
F_46 ( V_2 ) ;
F_48 ( V_2 ) ;
if ( ! ( V_2 -> V_4 & V_10 ) )
F_74 ( V_2 ) ;
F_49 ( V_2 , true ) ;
return 0 ;
}
static int F_75 ( void * V_105 )
{
struct V_1 * V_2 = (struct V_1 * ) V_105 ;
F_49 ( V_2 , false ) ;
if ( F_55 ( V_2 ) )
F_76 ( V_2 ) ;
return 0 ;
}
static int F_77 ( void * V_105 )
{
struct V_1 * V_2 = (struct V_1 * ) V_105 ;
return F_75 ( V_2 ) ;
}
static int F_78 ( void * V_105 )
{
struct V_1 * V_2 = (struct V_1 * ) V_105 ;
return F_73 ( V_2 ) ;
}
static bool F_79 ( void * V_105 )
{
return true ;
}
static int F_80 ( void * V_105 )
{
return 0 ;
}
static int F_81 ( void * V_105 )
{
return 0 ;
}
static void F_82 ( struct V_1 * V_2 , bool V_87 )
{
T_3 V_151 , V_6 ;
V_151 = V_6 = F_4 ( F_8 ( V_152 , 0 , V_153 ) ) ;
if ( V_87 && ( V_2 -> V_125 & V_136 ) )
V_6 |= V_154 ;
else
V_6 &= ~ V_154 ;
if ( V_151 != V_6 )
F_3 ( F_8 ( V_152 , 0 , V_153 ) , V_6 ) ;
}
static void F_83 ( struct V_1 * V_2 , bool V_87 )
{
T_3 V_151 , V_6 ;
V_151 = V_6 = F_4 ( F_8 ( V_155 , 0 , V_156 ) ) ;
if ( V_87 && ( V_2 -> V_125 & V_137 ) )
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
if ( V_151 != V_6 )
F_3 ( F_8 ( V_155 , 0 , V_156 ) , V_6 ) ;
}
static void F_84 ( struct V_1 * V_2 , bool V_87 )
{
T_3 V_151 , V_6 ;
V_151 = V_6 = F_4 ( F_8 ( V_155 , 0 , V_157 ) ) ;
if ( V_87 && ( V_2 -> V_125 & V_138 ) )
V_6 |= 1 ;
else
V_6 &= ~ 1 ;
if ( V_151 != V_6 )
F_3 ( F_8 ( V_155 , 0 , V_157 ) , V_6 ) ;
}
static void F_85 ( struct V_1 * V_2 ,
bool V_87 )
{
T_3 V_151 , V_6 ;
V_151 = V_6 = F_4 ( F_8 ( V_56 , 0 , V_158 ) ) ;
if ( V_87 && ( V_2 -> V_125 & V_139 ) )
V_6 &= ~ ( V_159 |
V_160 ) ;
else
V_6 |= V_159 |
V_160 ;
if ( V_151 != V_6 )
F_3 ( F_8 ( V_56 , 0 , V_158 ) , V_6 ) ;
}
static void F_86 ( struct V_1 * V_2 ,
bool V_87 )
{
T_3 V_6 ;
V_6 = F_4 ( F_8 ( V_161 , 0 , V_162 ) ) ;
V_6 &= ~ V_163 ;
F_3 ( F_8 ( V_161 , 0 , V_162 ) , V_6 ) ;
if ( V_87 && ( V_2 -> V_125 & V_140 ) ) {
V_6 = F_4 ( F_8 ( V_161 , 0 , V_164 ) ) ;
V_6 &= ~ V_165 ;
V_6 |= V_166 ;
F_3 ( F_8 ( V_161 , 0 , V_164 ) , V_6 ) ;
} else {
V_6 = F_4 ( F_8 ( V_161 , 0 , V_164 ) ) ;
V_6 &= ~ V_165 ;
V_6 |= V_167 ;
F_3 ( F_8 ( V_161 , 0 , V_164 ) , V_6 ) ;
}
F_3 ( F_8 ( V_161 , 0 , V_162 ) ,
V_168 ) ;
}
static int F_87 ( void * V_105 ,
enum V_169 V_50 )
{
struct V_1 * V_2 = (struct V_1 * ) V_105 ;
if ( F_55 ( V_2 ) )
return 0 ;
switch ( V_2 -> V_32 ) {
case V_33 :
F_88 ( V_2 ,
V_50 == V_170 ? true : false ) ;
F_89 ( V_2 ,
V_50 == V_170 ? true : false ) ;
F_82 ( V_2 ,
V_50 == V_170 ? true : false ) ;
F_83 ( V_2 ,
V_50 == V_170 ? true : false ) ;
F_84 ( V_2 ,
V_50 == V_170 ? true : false ) ;
F_85 ( V_2 ,
V_50 == V_170 ? true : false ) ;
F_86 ( V_2 ,
V_50 == V_170 ? true : false ) ;
break;
case V_35 :
F_90 ( V_2 ,
V_50 == V_170 ? true : false ) ;
F_89 ( V_2 ,
V_50 == V_170 ? true : false ) ;
F_82 ( V_2 ,
V_50 == V_170 ? true : false ) ;
F_83 ( V_2 ,
V_50 == V_170 ? true : false ) ;
F_84 ( V_2 ,
V_50 == V_170 ? true : false ) ;
F_85 ( V_2 ,
V_50 == V_170 ? true : false ) ;
break;
default:
break;
}
return 0 ;
}
static void F_91 ( void * V_105 , T_1 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_105 ;
int V_6 ;
if ( F_55 ( V_2 ) )
* V_4 = 0 ;
F_92 ( V_2 , V_4 ) ;
V_6 = F_4 ( F_8 ( V_152 , 0 , V_153 ) ) ;
if ( V_6 & V_154 )
* V_4 |= V_136 ;
V_6 = F_4 ( F_8 ( V_155 , 0 , V_156 ) ) ;
if ( ! ( V_6 & 0x01000000 ) )
* V_4 |= V_137 ;
V_6 = F_4 ( F_8 ( V_155 , 0 , V_157 ) ) ;
if ( V_6 & 0x1 )
* V_4 |= V_138 ;
V_6 = F_4 ( F_8 ( V_56 , 0 , V_158 ) ) ;
if ( ! ( V_6 & V_159 ) )
* V_4 |= V_139 ;
V_6 = F_4 ( F_8 ( V_161 , 0 , V_164 ) ) ;
if ( V_6 & V_166 )
* V_4 |= V_140 ;
}
static int F_93 ( void * V_105 ,
enum V_171 V_50 )
{
return 0 ;
}
