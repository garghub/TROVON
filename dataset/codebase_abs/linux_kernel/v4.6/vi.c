static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_7 , V_3 ) ;
( void ) F_4 ( V_7 ) ;
V_5 = F_4 ( V_8 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
return V_5 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_7 , V_3 ) ;
( void ) F_4 ( V_7 ) ;
F_3 ( V_8 , V_9 ) ;
( void ) F_4 ( V_8 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_11 , ( V_3 ) ) ;
V_5 = F_4 ( V_12 ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_11 , ( V_3 ) ) ;
F_3 ( V_12 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_13 , ( V_3 ) ) ;
V_5 = F_4 ( V_14 ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
return V_5 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_13 , ( V_3 ) ) ;
F_3 ( V_14 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_15 , V_4 ) ;
F_3 ( V_16 , ( ( V_3 ) & 0x1ff ) ) ;
V_5 = F_4 ( V_17 ) ;
F_5 ( & V_2 -> V_15 , V_4 ) ;
return V_5 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_15 , V_4 ) ;
F_3 ( V_16 , ( ( V_3 ) & 0x1ff ) ) ;
F_3 ( V_17 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_15 , V_4 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_18 , V_4 ) ;
F_3 ( V_19 , ( V_3 ) ) ;
V_5 = F_4 ( V_20 ) ;
F_5 ( & V_2 -> V_18 , V_4 ) ;
return V_5 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_18 , V_4 ) ;
F_3 ( V_19 , ( V_3 ) ) ;
F_3 ( V_20 , ( V_9 ) ) ;
F_5 ( & V_2 -> V_18 , V_4 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_21 ) ;
switch ( V_2 -> V_22 ) {
case V_23 :
F_17 ( V_2 ,
V_24 ,
( const T_1 ) F_18 ( V_24 ) ) ;
break;
case V_25 :
F_17 ( V_2 ,
V_26 ,
( const T_1 ) F_18 ( V_26 ) ) ;
break;
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
case V_31 :
F_17 ( V_2 ,
V_32 ,
( const T_1 ) F_18 ( V_32 ) ) ;
break;
default:
break;
}
F_19 ( & V_2 -> V_21 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 )
{
T_1 V_33 = V_2 -> clock . V_34 . V_35 ;
T_1 V_36 ;
if ( V_2 -> V_4 & V_37 )
return V_33 ;
V_36 = F_21 ( V_38 ) ;
if ( F_22 ( V_36 , V_39 , V_40 ) )
return 1000 ;
V_36 = F_21 ( V_41 ) ;
if ( F_22 ( V_36 , V_42 , V_43 ) )
return V_33 / 4 ;
return V_33 ;
}
void F_23 ( struct V_1 * V_2 ,
T_1 V_44 , T_1 V_45 , T_1 V_46 , T_1 V_47 )
{
T_1 V_48 = 0 ;
V_48 = F_24 ( V_48 , V_49 , V_50 , V_45 ) ;
V_48 = F_24 ( V_48 , V_49 , V_51 , V_44 ) ;
V_48 = F_24 ( V_48 , V_49 , V_52 , V_47 ) ;
V_48 = F_24 ( V_48 , V_49 , V_53 , V_46 ) ;
F_3 ( V_54 , V_48 ) ;
}
static void F_25 ( struct V_1 * V_2 , bool V_55 )
{
}
static bool F_26 ( struct V_1 * V_2 )
{
T_1 V_56 ;
T_1 V_57 = 0 ;
T_1 V_58 = 0 ;
T_1 V_59 = 0 ;
T_1 V_60 ;
bool V_5 ;
V_56 = F_4 ( V_61 ) ;
if ( V_2 -> V_62 . V_63 ) {
V_57 = F_4 ( V_64 ) ;
V_58 = F_4 ( V_65 ) ;
V_59 = F_4 ( V_66 ) ;
}
V_60 = F_21 ( V_67 ) ;
F_3 ( V_61 , ( V_56 & ~ V_68 ) ) ;
if ( V_2 -> V_62 . V_63 ) {
F_3 ( V_64 ,
( V_57 & ~ ( V_69 |
V_70 ) ) ) ;
F_3 ( V_65 ,
( V_58 & ~ ( V_71 |
V_72 ) ) ) ;
F_3 ( V_66 ,
( V_59 & ~ V_73 ) ) ;
}
F_27 ( V_67 , V_60 | V_74 ) ;
V_5 = F_28 ( V_2 ) ;
F_3 ( V_61 , V_56 ) ;
if ( V_2 -> V_62 . V_63 ) {
F_3 ( V_64 , V_57 ) ;
F_3 ( V_65 , V_58 ) ;
F_3 ( V_66 , V_59 ) ;
}
F_27 ( V_67 , V_60 ) ;
return V_5 ;
}
static bool F_29 ( struct V_1 * V_2 ,
T_2 * V_75 , T_1 V_76 )
{
T_1 * V_77 ;
unsigned long V_4 ;
T_1 V_78 , V_79 ;
if ( V_75 == NULL )
return false ;
if ( V_76 == 0 )
return false ;
if ( V_2 -> V_4 & V_37 )
return false ;
V_77 = ( T_1 * ) V_75 ;
V_79 = F_30 ( V_76 , 4 ) / 4 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( V_11 , V_80 ) ;
F_3 ( V_12 , 0 ) ;
F_3 ( V_11 , V_81 ) ;
for ( V_78 = 0 ; V_78 < V_79 ; V_78 ++ )
V_77 [ V_78 ] = F_4 ( V_12 ) ;
F_5 ( & V_2 -> V_10 , V_4 ) ;
return true ;
}
static T_3 F_31 ( struct V_1 * V_2 , T_1 V_82 ,
T_1 V_83 , T_1 V_84 )
{
T_3 V_85 ;
F_16 ( & V_2 -> V_21 ) ;
if ( V_82 != 0xffffffff || V_83 != 0xffffffff )
F_32 ( V_2 , V_82 , V_83 ) ;
V_85 = F_4 ( V_84 ) ;
if ( V_82 != 0xffffffff || V_83 != 0xffffffff )
F_32 ( V_2 , 0xffffffff , 0xffffffff ) ;
F_19 ( & V_2 -> V_21 ) ;
return V_85 ;
}
static int F_33 ( struct V_1 * V_2 , T_1 V_82 ,
T_1 V_83 , T_1 V_84 , T_1 * V_86 )
{
struct V_87 * V_88 = NULL ;
struct V_87 * V_89 ;
T_3 V_90 , V_78 ;
* V_86 = 0 ;
switch ( V_2 -> V_22 ) {
case V_23 :
V_88 = V_91 ;
V_90 = F_18 ( V_91 ) ;
break;
case V_25 :
case V_27 :
case V_29 :
case V_31 :
V_88 = V_92 ;
V_90 = F_18 ( V_92 ) ;
break;
default:
return - V_93 ;
}
if ( V_88 ) {
for ( V_78 = 0 ; V_78 < V_90 ; V_78 ++ ) {
V_89 = V_88 + V_78 ;
if ( V_84 != V_89 -> V_84 )
continue;
if ( ! V_89 -> V_94 )
* V_86 = V_89 -> V_95 ?
F_31 ( V_2 , V_82 ,
V_83 , V_84 ) :
F_4 ( V_84 ) ;
return 0 ;
}
}
for ( V_78 = 0 ; V_78 < F_18 ( V_96 ) ; V_78 ++ ) {
if ( V_84 != V_96 [ V_78 ] . V_84 )
continue;
if ( ! V_96 [ V_78 ] . V_94 )
* V_86 = V_96 [ V_78 ] . V_95 ?
F_31 ( V_2 , V_82 ,
V_83 , V_84 ) :
F_4 ( V_84 ) ;
return 0 ;
}
return - V_93 ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_78 ;
F_35 ( V_2 -> V_97 , L_1 ) ;
F_36 ( V_2 -> V_98 ) ;
F_37 ( V_2 ) ;
F_38 ( 100 ) ;
for ( V_78 = 0 ; V_78 < V_2 -> V_99 ; V_78 ++ ) {
if ( F_4 ( V_100 ) != 0xffffffff )
break;
F_38 ( 1 ) ;
}
}
static void F_39 ( struct V_1 * V_2 , bool V_101 )
{
T_1 V_36 = F_4 ( V_102 ) ;
if ( V_101 )
V_36 |= V_103 ;
else
V_36 &= ~ V_103 ;
F_3 ( V_102 , V_36 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_39 ( V_2 , true ) ;
F_34 ( V_2 ) ;
F_39 ( V_2 , false ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , T_1 clock ,
T_1 V_104 , T_1 V_105 )
{
int V_5 , V_78 ;
struct V_106 V_107 ;
T_3 V_36 ;
V_5 = F_42 ( V_2 ,
V_108 ,
clock , false , & V_107 ) ;
if ( V_5 )
return V_5 ;
V_36 = F_21 ( V_104 ) ;
V_36 &= ~ ( V_109 |
V_110 ) ;
V_36 |= V_107 . V_111 ;
F_27 ( V_104 , V_36 ) ;
for ( V_78 = 0 ; V_78 < 100 ; V_78 ++ ) {
if ( F_21 ( V_105 ) & V_112 )
break;
F_43 ( 10 ) ;
}
if ( V_78 == 100 )
return - V_113 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , T_1 V_114 , T_1 V_115 )
{
int V_5 ;
V_5 = F_41 ( V_2 , V_114 , V_116 , V_117 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_41 ( V_2 , V_115 , V_118 , V_119 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , T_1 V_120 , T_1 V_121 )
{
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
if ( F_47 ( V_2 -> V_98 -> V_122 ) )
return;
if ( V_123 == 0 )
return;
if ( V_2 -> V_4 & V_37 )
return;
if ( ! ( V_2 -> V_124 . V_125 & ( V_126 |
V_127 ) ) )
return;
}
static void F_48 ( struct V_1 * V_2 )
{
if ( V_128 == 0 )
return;
}
static void F_49 ( struct V_1 * V_2 ,
bool V_129 )
{
T_1 V_36 ;
if ( V_2 -> V_4 & V_37 )
return;
V_36 = F_4 ( V_130 ) ;
if ( V_129 )
V_36 = F_24 ( V_36 , V_131 , V_131 , 1 ) ;
else
V_36 = F_24 ( V_36 , V_131 , V_131 , 0 ) ;
F_3 ( V_130 , V_36 ) ;
}
int F_50 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_22 ) {
case V_23 :
V_2 -> V_132 = V_133 ;
V_2 -> V_134 = F_18 ( V_133 ) ;
break;
case V_25 :
V_2 -> V_132 = V_135 ;
V_2 -> V_134 = F_18 ( V_135 ) ;
break;
case V_27 :
V_2 -> V_132 = V_136 ;
V_2 -> V_134 = F_18 ( V_136 ) ;
break;
case V_29 :
case V_31 :
V_2 -> V_132 = V_137 ;
V_2 -> V_134 = F_18 ( V_137 ) ;
break;
default:
return - V_93 ;
}
return 0 ;
}
static T_3 F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 & V_37 )
return ( F_21 ( V_138 ) & V_139 )
>> V_140 ;
else
return ( F_4 ( V_141 ) & V_142 )
>> V_143 ;
}
static int F_52 ( void * V_144 )
{
bool V_145 = false ;
struct V_1 * V_2 = (struct V_1 * ) V_144 ;
if ( V_2 -> V_4 & V_37 ) {
V_2 -> V_146 = & F_9 ;
V_2 -> V_147 = & F_10 ;
} else {
V_2 -> V_146 = & F_7 ;
V_2 -> V_147 = & F_8 ;
}
V_2 -> V_148 = & F_1 ;
V_2 -> V_149 = & F_6 ;
V_2 -> V_150 = & F_11 ;
V_2 -> V_151 = & F_12 ;
V_2 -> V_152 = & F_13 ;
V_2 -> V_153 = & F_14 ;
V_2 -> V_154 = & V_155 ;
if ( F_53 ( V_2 , V_156 ) &&
( V_157 & ( 1 << V_156 ) ) )
V_145 = true ;
V_2 -> V_158 = F_51 ( V_2 ) ;
V_2 -> V_159 = 0xFF ;
switch ( V_2 -> V_22 ) {
case V_23 :
V_2 -> V_160 = 0 ;
V_2 -> V_161 = 0 ;
V_2 -> V_159 = 0x1 ;
break;
case V_25 :
V_2 -> V_160 = 0 ;
V_2 -> V_161 = 0 ;
V_2 -> V_159 = V_2 -> V_158 + 0x3c ;
break;
case V_27 :
V_2 -> V_160 = 0 ;
V_2 -> V_161 = 0 ;
V_2 -> V_159 = V_2 -> V_158 + 0x14 ;
break;
case V_29 :
case V_31 :
V_2 -> V_160 = 0 ;
V_2 -> V_161 = 0 ;
V_2 -> V_159 = V_2 -> V_158 + 0x1 ;
break;
default:
return - V_93 ;
}
if ( V_162 && V_145 )
V_2 -> V_163 . V_164 = true ;
F_54 ( V_2 ) ;
return 0 ;
}
static int F_55 ( void * V_144 )
{
return 0 ;
}
static int F_56 ( void * V_144 )
{
return 0 ;
}
static int F_57 ( void * V_144 )
{
struct V_1 * V_2 = (struct V_1 * ) V_144 ;
F_15 ( V_2 ) ;
F_46 ( V_2 ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 , true ) ;
return 0 ;
}
static int F_58 ( void * V_144 )
{
struct V_1 * V_2 = (struct V_1 * ) V_144 ;
F_49 ( V_2 , false ) ;
return 0 ;
}
static int F_59 ( void * V_144 )
{
struct V_1 * V_2 = (struct V_1 * ) V_144 ;
return F_58 ( V_2 ) ;
}
static int F_60 ( void * V_144 )
{
struct V_1 * V_2 = (struct V_1 * ) V_144 ;
return F_57 ( V_2 ) ;
}
static bool F_61 ( void * V_144 )
{
return true ;
}
static int F_62 ( void * V_144 )
{
return 0 ;
}
static void F_63 ( void * V_144 )
{
return;
}
static int F_64 ( void * V_144 )
{
return 0 ;
}
static void F_65 ( struct V_1 * V_2 ,
bool V_129 )
{
T_3 V_165 , V_166 ;
V_165 = V_166 = F_66 ( V_167 ) ;
if ( V_129 )
V_166 |= V_168 |
V_169 |
V_170 ;
else
V_166 &= ~ ( V_168 |
V_169 |
V_170 ) ;
if ( V_165 != V_166 )
F_67 ( V_167 , V_166 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
bool V_129 )
{
T_3 V_165 , V_166 ;
V_165 = V_166 = F_4 ( V_171 ) ;
if ( V_129 )
V_166 &= ~ V_172 ;
else
V_166 |= V_172 ;
if ( V_165 != V_166 )
F_3 ( V_171 , V_166 ) ;
}
static void F_69 ( struct V_1 * V_2 ,
bool V_129 )
{
T_3 V_165 , V_166 ;
V_165 = V_166 = F_4 ( V_173 ) ;
if ( V_129 )
V_166 |= V_174 ;
else
V_166 &= ~ V_174 ;
if ( V_165 != V_166 )
F_3 ( V_173 , V_166 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
bool V_129 )
{
T_3 V_165 , V_166 ;
V_165 = V_166 = F_21 ( V_175 ) ;
if ( V_129 )
V_166 &= ~ ( V_176 |
V_177 ) ;
else
V_166 |= V_176 |
V_177 ;
if ( V_165 != V_166 )
F_27 ( V_175 , V_166 ) ;
}
static int F_71 ( void * V_144 ,
enum V_178 V_55 )
{
struct V_1 * V_2 = (struct V_1 * ) V_144 ;
switch ( V_2 -> V_22 ) {
case V_25 :
F_65 ( V_2 ,
V_55 == V_179 ? true : false ) ;
F_68 ( V_2 ,
V_55 == V_179 ? true : false ) ;
F_69 ( V_2 ,
V_55 == V_179 ? true : false ) ;
F_70 ( V_2 ,
V_55 == V_179 ? true : false ) ;
break;
default:
break;
}
return 0 ;
}
static int F_72 ( void * V_144 ,
enum V_180 V_55 )
{
return 0 ;
}
