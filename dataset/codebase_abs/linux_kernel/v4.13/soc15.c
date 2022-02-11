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
static T_1 F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 & V_10 )
return F_13 ( V_2 ) ;
else
return F_14 ( V_2 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_25 ) ;
switch ( V_2 -> V_26 ) {
case V_27 :
F_17 ( V_2 ,
V_28 ,
( const T_1 ) F_18 ( V_28 ) ) ;
break;
case V_29 :
F_17 ( V_2 ,
V_30 ,
( const T_1 ) F_18 ( V_30 ) ) ;
break;
default:
break;
}
F_19 ( & V_2 -> V_25 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 == V_27 )
return V_2 -> clock . V_31 . V_32 / 4 ;
else
return V_2 -> clock . V_31 . V_32 ;
}
void F_21 ( struct V_1 * V_2 ,
T_1 V_33 , T_1 V_34 , T_1 V_35 , T_1 V_36 )
{
T_1 V_37 = 0 ;
V_37 = F_22 ( V_37 , V_38 , V_39 , V_34 ) ;
V_37 = F_22 ( V_37 , V_38 , V_40 , V_33 ) ;
V_37 = F_22 ( V_37 , V_38 , V_41 , V_36 ) ;
V_37 = F_22 ( V_37 , V_38 , V_42 , V_35 ) ;
F_3 ( F_8 ( V_21 , 0 , V_43 ) , V_37 ) ;
}
static void F_23 ( struct V_1 * V_2 , bool V_44 )
{
}
static bool F_24 ( struct V_1 * V_2 )
{
return false ;
}
static bool F_25 ( struct V_1 * V_2 ,
T_2 * V_45 , T_1 V_46 )
{
T_1 * V_47 ;
T_1 V_48 , V_49 ;
if ( V_45 == NULL )
return false ;
if ( V_46 == 0 )
return false ;
if ( V_2 -> V_4 & V_10 )
return false ;
V_47 = ( T_1 * ) V_45 ;
V_49 = F_26 ( V_46 , 4 ) / 4 ;
F_3 ( F_8 ( V_50 , 0 , V_51 ) , 0 ) ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ )
V_47 [ V_48 ] = F_4 ( F_8 ( V_50 , 0 , V_52 ) ) ;
return true ;
}
static T_3 F_27 ( struct V_1 * V_2 , T_1 V_53 ,
T_1 V_54 , T_1 V_55 )
{
T_3 V_56 ;
F_16 ( & V_2 -> V_25 ) ;
if ( V_53 != 0xffffffff || V_54 != 0xffffffff )
F_28 ( V_2 , V_53 , V_54 , 0xffffffff ) ;
V_56 = F_4 ( V_55 ) ;
if ( V_53 != 0xffffffff || V_54 != 0xffffffff )
F_28 ( V_2 , 0xffffffff , 0xffffffff , 0xffffffff ) ;
F_19 ( & V_2 -> V_25 ) ;
return V_56 ;
}
static T_3 F_29 ( struct V_1 * V_2 ,
bool V_57 , T_1 V_53 ,
T_1 V_54 , T_1 V_55 )
{
if ( V_57 ) {
return F_27 ( V_2 , V_53 , V_54 , V_55 ) ;
} else {
switch ( V_55 ) {
case F_8 ( V_21 , 0 , V_58 ) :
return V_2 -> V_59 . V_60 . V_61 ;
default:
return F_4 ( V_55 ) ;
}
}
}
static int F_30 ( struct V_1 * V_2 , T_1 V_53 ,
T_1 V_54 , T_1 V_55 , T_1 * V_62 )
{
T_3 V_48 ;
* V_62 = 0 ;
for ( V_48 = 0 ; V_48 < F_18 ( V_63 ) ; V_48 ++ ) {
if ( V_55 != V_63 [ V_48 ] . V_55 )
continue;
* V_62 = F_29 ( V_2 ,
V_63 [ V_48 ] . V_64 ,
V_53 , V_54 , V_55 ) ;
return 0 ;
}
return - V_65 ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_1 V_48 ;
F_32 ( V_2 -> V_66 , L_1 ) ;
F_33 ( V_2 -> V_67 ) ;
F_34 ( V_2 ) ;
F_35 ( 100 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_68 ; V_48 ++ ) {
T_1 V_69 = ( V_2 -> V_4 & V_10 ) ?
F_13 ( V_2 ) :
F_14 ( V_2 ) ;
if ( V_69 != 0xffffffff )
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
static int F_38 ( struct V_1 * V_2 , T_1 V_70 , T_1 V_71 )
{
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , T_1 V_72 , T_1 V_73 )
{
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
if ( F_41 ( V_2 -> V_67 -> V_74 ) )
return;
if ( V_75 == 0 )
return;
if ( V_2 -> V_4 & V_10 )
return;
if ( ! ( V_2 -> V_76 . V_77 & ( V_78 |
V_79 ) ) )
return;
}
static void F_42 ( struct V_1 * V_2 )
{
if ( V_80 == 0 )
return;
}
static void F_43 ( struct V_1 * V_2 ,
bool V_81 )
{
if ( V_2 -> V_4 & V_10 ) {
F_44 ( V_2 , V_81 ) ;
} else {
F_45 ( V_2 , V_81 ) ;
F_46 ( V_2 , V_81 ) ;
}
}
int F_47 ( struct V_1 * V_2 )
{
F_48 ( V_2 ) ;
if ( F_49 ( V_2 ) )
V_2 -> V_82 . V_83 = & V_84 ;
switch ( V_2 -> V_26 ) {
case V_27 :
F_50 ( V_2 , & V_85 ) ;
F_50 ( V_2 , & V_86 ) ;
F_50 ( V_2 , & V_87 ) ;
if ( V_88 == 2 || V_88 == - 1 )
F_50 ( V_2 , & V_89 ) ;
if ( ! F_49 ( V_2 ) )
F_50 ( V_2 , & V_90 ) ;
if ( V_2 -> V_91 || F_49 ( V_2 ) )
F_50 ( V_2 , & V_92 ) ;
F_50 ( V_2 , & V_93 ) ;
F_50 ( V_2 , & V_94 ) ;
F_50 ( V_2 , & V_95 ) ;
F_50 ( V_2 , & V_96 ) ;
break;
case V_29 :
F_50 ( V_2 , & V_85 ) ;
F_50 ( V_2 , & V_86 ) ;
F_50 ( V_2 , & V_87 ) ;
F_50 ( V_2 , & V_97 ) ;
F_50 ( V_2 , & V_90 ) ;
if ( V_2 -> V_91 || F_49 ( V_2 ) )
F_50 ( V_2 , & V_92 ) ;
F_50 ( V_2 , & V_93 ) ;
F_50 ( V_2 , & V_94 ) ;
F_50 ( V_2 , & V_98 ) ;
break;
default:
return - V_65 ;
}
return 0 ;
}
static T_3 F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 & V_10 )
return F_52 ( V_2 ) ;
else
return F_53 ( V_2 ) ;
}
int F_54 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_55 ( void * V_99 )
{
bool V_100 = false ;
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
V_2 -> V_101 = NULL ;
V_2 -> V_102 = NULL ;
V_2 -> V_103 = & F_1 ;
V_2 -> V_104 = & F_6 ;
V_2 -> V_105 = & F_7 ;
V_2 -> V_106 = & F_9 ;
V_2 -> V_107 = & F_10 ;
V_2 -> V_108 = & F_11 ;
V_2 -> V_109 = & V_110 ;
if ( F_56 ( V_2 , V_111 ) &&
( V_112 & ( 1 << V_111 ) ) )
V_100 = true ;
switch( V_2 -> V_26 ) {
case V_27 :
F_57 ( V_2 ) ;
break;
case V_29 :
F_58 ( V_2 ) ;
break;
default:
return - V_65 ;
}
V_2 -> V_113 = F_51 ( V_2 ) ;
V_2 -> V_114 = 0xFF ;
switch ( V_2 -> V_26 ) {
case V_27 :
V_2 -> V_115 = V_116 |
V_117 |
V_118 |
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
V_134 ;
V_2 -> V_135 = 0 ;
V_2 -> V_114 = 0x1 ;
break;
case V_29 :
V_2 -> V_115 = V_116 |
V_117 |
V_118 |
V_119 |
V_120 |
V_121 |
V_122 |
V_123 |
V_124 |
V_125 |
V_136 |
V_126 |
V_127 |
V_128 |
V_129 |
V_133 |
V_134 |
V_131 |
V_132 ;
V_2 -> V_135 = V_137 |
V_138 ;
V_2 -> V_114 = 0x1 ;
break;
default:
return - V_65 ;
}
if ( F_49 ( V_2 ) ) {
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
}
V_2 -> V_139 . V_140 = F_61 ( V_2 , V_88 ) ;
F_62 ( V_2 ) ;
return 0 ;
}
static int F_63 ( void * V_99 )
{
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
if ( F_49 ( V_2 ) )
F_64 ( V_2 ) ;
return 0 ;
}
static int F_65 ( void * V_99 )
{
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
if ( F_49 ( V_2 ) )
F_66 ( V_2 ) ;
return 0 ;
}
static int F_67 ( void * V_99 )
{
return 0 ;
}
static int F_68 ( void * V_99 )
{
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
F_15 ( V_2 ) ;
F_40 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 , true ) ;
return 0 ;
}
static int F_69 ( void * V_99 )
{
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
F_43 ( V_2 , false ) ;
if ( F_49 ( V_2 ) )
F_70 ( V_2 ) ;
return 0 ;
}
static int F_71 ( void * V_99 )
{
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
return F_69 ( V_2 ) ;
}
static int F_72 ( void * V_99 )
{
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
return F_68 ( V_2 ) ;
}
static bool F_73 ( void * V_99 )
{
return true ;
}
static int F_74 ( void * V_99 )
{
return 0 ;
}
static int F_75 ( void * V_99 )
{
return 0 ;
}
static void F_76 ( struct V_1 * V_2 , bool V_81 )
{
T_3 V_141 , V_6 ;
V_141 = V_6 = F_4 ( F_8 ( V_142 , 0 , V_143 ) ) ;
if ( V_81 && ( V_2 -> V_115 & V_126 ) )
V_6 |= V_144 ;
else
V_6 &= ~ V_144 ;
if ( V_141 != V_6 )
F_3 ( F_8 ( V_142 , 0 , V_143 ) , V_6 ) ;
}
static void F_77 ( struct V_1 * V_2 , bool V_81 )
{
T_3 V_141 , V_6 ;
V_141 = V_6 = F_4 ( F_8 ( V_145 , 0 , V_146 ) ) ;
if ( V_81 && ( V_2 -> V_115 & V_127 ) )
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
if ( V_141 != V_6 )
F_3 ( F_8 ( V_145 , 0 , V_146 ) , V_6 ) ;
}
static void F_78 ( struct V_1 * V_2 , bool V_81 )
{
T_3 V_141 , V_6 ;
V_141 = V_6 = F_4 ( F_8 ( V_145 , 0 , V_147 ) ) ;
if ( V_81 && ( V_2 -> V_115 & V_128 ) )
V_6 |= 1 ;
else
V_6 &= ~ 1 ;
if ( V_141 != V_6 )
F_3 ( F_8 ( V_145 , 0 , V_147 ) , V_6 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
bool V_81 )
{
T_3 V_141 , V_6 ;
V_141 = V_6 = F_4 ( F_8 ( V_50 , 0 , V_148 ) ) ;
if ( V_81 && ( V_2 -> V_115 & V_129 ) )
V_6 &= ~ ( V_149 |
V_150 ) ;
else
V_6 |= V_149 |
V_150 ;
if ( V_141 != V_6 )
F_3 ( F_8 ( V_50 , 0 , V_148 ) , V_6 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
bool V_81 )
{
T_3 V_6 ;
V_6 = F_4 ( F_8 ( V_151 , 0 , V_152 ) ) ;
V_6 &= ~ V_153 ;
F_3 ( F_8 ( V_151 , 0 , V_152 ) , V_6 ) ;
if ( V_81 && ( V_2 -> V_115 & V_130 ) ) {
V_6 = F_4 ( F_8 ( V_151 , 0 , V_154 ) ) ;
V_6 &= ~ V_155 ;
V_6 |= V_156 ;
F_3 ( F_8 ( V_151 , 0 , V_154 ) , V_6 ) ;
} else {
V_6 = F_4 ( F_8 ( V_151 , 0 , V_154 ) ) ;
V_6 &= ~ V_155 ;
V_6 |= V_157 ;
F_3 ( F_8 ( V_151 , 0 , V_154 ) , V_6 ) ;
}
F_3 ( F_8 ( V_151 , 0 , V_152 ) ,
V_158 ) ;
}
static int F_81 ( void * V_99 ,
enum V_159 V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
if ( F_49 ( V_2 ) )
return 0 ;
switch ( V_2 -> V_26 ) {
case V_27 :
F_82 ( V_2 ,
V_44 == V_160 ? true : false ) ;
F_83 ( V_2 ,
V_44 == V_160 ? true : false ) ;
F_76 ( V_2 ,
V_44 == V_160 ? true : false ) ;
F_77 ( V_2 ,
V_44 == V_160 ? true : false ) ;
F_78 ( V_2 ,
V_44 == V_160 ? true : false ) ;
F_79 ( V_2 ,
V_44 == V_160 ? true : false ) ;
F_80 ( V_2 ,
V_44 == V_160 ? true : false ) ;
break;
case V_29 :
F_84 ( V_2 ,
V_44 == V_160 ? true : false ) ;
F_83 ( V_2 ,
V_44 == V_160 ? true : false ) ;
F_76 ( V_2 ,
V_44 == V_160 ? true : false ) ;
F_77 ( V_2 ,
V_44 == V_160 ? true : false ) ;
F_78 ( V_2 ,
V_44 == V_160 ? true : false ) ;
F_79 ( V_2 ,
V_44 == V_160 ? true : false ) ;
break;
default:
break;
}
return 0 ;
}
static void F_85 ( void * V_99 , T_1 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
int V_6 ;
if ( F_49 ( V_2 ) )
* V_4 = 0 ;
F_86 ( V_2 , V_4 ) ;
V_6 = F_4 ( F_8 ( V_142 , 0 , V_143 ) ) ;
if ( V_6 & V_144 )
* V_4 |= V_126 ;
V_6 = F_4 ( F_8 ( V_145 , 0 , V_146 ) ) ;
if ( ! ( V_6 & 0x01000000 ) )
* V_4 |= V_127 ;
V_6 = F_4 ( F_8 ( V_145 , 0 , V_147 ) ) ;
if ( V_6 & 0x1 )
* V_4 |= V_128 ;
V_6 = F_4 ( F_8 ( V_50 , 0 , V_148 ) ) ;
if ( ! ( V_6 & V_149 ) )
* V_4 |= V_129 ;
V_6 = F_4 ( F_8 ( V_151 , 0 , V_154 ) ) ;
if ( V_6 & V_156 )
* V_4 |= V_130 ;
}
static int F_87 ( void * V_99 ,
enum V_161 V_44 )
{
return 0 ;
}
