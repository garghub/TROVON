static struct V_1 T_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
struct V_1 T_1 * V_8 ;
if ( F_2 ( V_3 -> V_6 ) )
V_8 = (struct V_1 T_1 * ) V_3 -> V_9 -> V_10 -> V_11 ;
else
V_8 = F_3 ( V_5 -> V_12 . V_13 ,
F_4 ( V_3 -> V_9 ) ) ;
return V_8 ;
}
static void F_5 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 )
{
if ( ! F_2 ( V_3 -> V_6 ) )
F_6 ( V_8 ) ;
}
static int F_7 ( struct V_2 * V_3 ,
struct V_14 * V_15 ,
void (* F_8)( struct V_2 * ) )
{
int V_16 ;
F_9 ( V_3 -> V_17 ) ;
F_10 ( & V_3 -> V_17 , V_15 ) ;
F_11 ( V_15 ) ;
V_3 -> V_18 = F_8 ;
V_16 = F_12 ( V_3 -> V_17 ) ;
if ( V_16 )
return V_16 ;
F_10 ( & V_3 -> V_17 , NULL ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_20 * V_21 = & V_5 -> V_21 [ V_22 ] ;
struct V_14 * V_15 ;
int V_16 ;
F_9 ( V_3 -> V_23 ) ;
F_9 ( F_14 ( V_6 ) && ! ( V_5 -> V_24 & V_25 ) ) ;
V_15 = F_15 ( V_21 , NULL ) ;
if ( F_16 ( V_15 ) )
return F_17 ( V_15 ) ;
V_16 = F_18 ( V_15 , 4 ) ;
if ( V_16 ) {
F_19 ( V_15 ) ;
return V_16 ;
}
V_3 -> V_23 = true ;
F_20 ( V_21 , V_26 | V_27 ) ;
F_20 ( V_21 , V_3 -> V_28 | V_29 ) ;
F_20 ( V_21 , V_30 | V_31 ) ;
F_20 ( V_21 , V_32 ) ;
F_21 ( V_21 ) ;
return F_7 ( V_3 , V_15 , NULL ) ;
}
static int F_22 ( struct V_2 * V_3 ,
bool V_33 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_20 * V_21 = & V_5 -> V_21 [ V_22 ] ;
struct V_14 * V_15 ;
T_2 V_28 = V_3 -> V_28 ;
T_2 V_34 ;
int V_16 ;
F_9 ( ! V_3 -> V_23 ) ;
if ( V_33 )
V_28 |= V_29 ;
V_34 = F_23 ( V_35 ) ;
if ( V_34 & ( 1 << 17 ) )
F_24 ( L_1 , V_34 ) ;
V_15 = F_15 ( V_21 , NULL ) ;
if ( F_16 ( V_15 ) )
return F_17 ( V_15 ) ;
V_16 = F_18 ( V_15 , 2 ) ;
if ( V_16 ) {
F_19 ( V_15 ) ;
return V_16 ;
}
F_20 ( V_21 , V_26 | V_36 ) ;
F_20 ( V_21 , V_28 ) ;
F_21 ( V_21 ) ;
F_9 ( V_3 -> V_17 ) ;
F_10 ( & V_3 -> V_17 , V_15 ) ;
F_11 ( V_15 ) ;
return 0 ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_37 * V_38 = V_3 -> V_39 ;
F_26 ( V_38 ) ;
F_27 ( & V_38 -> V_40 ) ;
V_3 -> V_39 = NULL ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_37 * V_38 = V_3 -> V_41 ;
if ( F_9 ( ! V_38 ) )
return;
F_26 ( V_38 ) ;
F_27 ( & V_38 -> V_40 ) ;
V_3 -> V_41 = NULL ;
V_3 -> V_42 -> V_3 = NULL ;
V_3 -> V_42 = NULL ;
V_3 -> V_23 = false ;
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_20 * V_21 = & V_5 -> V_21 [ V_22 ] ;
struct V_14 * V_15 ;
T_2 V_28 = V_3 -> V_28 ;
int V_16 ;
F_9 ( ! V_3 -> V_23 ) ;
V_28 |= V_29 ;
V_15 = F_15 ( V_21 , NULL ) ;
if ( F_16 ( V_15 ) )
return F_17 ( V_15 ) ;
V_16 = F_18 ( V_15 , 6 ) ;
if ( V_16 ) {
F_19 ( V_15 ) ;
return V_16 ;
}
F_20 ( V_21 , V_26 | V_36 ) ;
F_20 ( V_21 , V_28 ) ;
F_20 ( V_21 , V_30 | V_31 ) ;
if ( F_14 ( V_6 ) ) {
F_20 ( V_21 , V_32 ) ;
F_20 ( V_21 , V_32 ) ;
F_20 ( V_21 , V_32 ) ;
} else {
F_20 ( V_21 , V_26 | V_43 ) ;
F_20 ( V_21 , V_28 ) ;
F_20 ( V_21 , V_30 | V_31 ) ;
}
F_21 ( V_21 ) ;
return F_7 ( V_3 , V_15 , F_28 ) ;
}
static int F_30 ( struct V_2 * V_3 )
{
int V_16 ;
if ( V_3 -> V_17 == NULL )
return 0 ;
V_16 = F_12 ( V_3 -> V_17 ) ;
if ( V_16 )
return V_16 ;
if ( V_3 -> V_18 )
V_3 -> V_18 ( V_3 ) ;
F_10 ( & V_3 -> V_17 , NULL ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_20 * V_21 = & V_5 -> V_21 [ V_22 ] ;
int V_16 ;
F_9 ( ! F_32 ( & V_6 -> V_44 ) ) ;
if ( ! V_3 -> V_39 )
return 0 ;
if ( F_23 ( V_45 ) & V_46 ) {
struct V_14 * V_15 ;
V_15 = F_15 ( V_21 , NULL ) ;
if ( F_16 ( V_15 ) )
return F_17 ( V_15 ) ;
V_16 = F_18 ( V_15 , 2 ) ;
if ( V_16 ) {
F_19 ( V_15 ) ;
return V_16 ;
}
F_20 ( V_21 , V_30 | V_31 ) ;
F_20 ( V_21 , V_32 ) ;
F_21 ( V_21 ) ;
V_16 = F_7 ( V_3 , V_15 ,
F_25 ) ;
if ( V_16 )
return V_16 ;
}
F_25 ( V_3 ) ;
F_33 ( V_3 -> V_39 , NULL ,
F_34 ( V_3 -> V_42 -> V_47 ) ) ;
return 0 ;
}
void F_35 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
if ( ! V_3 )
return;
F_31 ( V_3 ) ;
V_3 -> V_17 = NULL ;
V_3 -> V_48 = 0 ;
V_3 -> V_49 = 0 ;
V_3 -> V_42 = NULL ;
V_3 -> V_23 = false ;
}
static int F_36 ( T_2 V_50 )
{
switch ( V_50 & V_51 ) {
case V_52 :
return 4 ;
case V_53 :
default:
return - V_54 ;
}
}
static int F_37 ( T_2 V_50 , short V_55 )
{
switch ( V_50 & V_51 ) {
case V_52 :
return V_55 << 1 ;
default:
return - V_54 ;
}
}
static int F_38 ( T_2 V_50 )
{
switch ( V_50 & V_51 ) {
case V_52 :
case V_56 :
return 2 ;
case V_53 :
case V_57 :
return 4 ;
default:
return - V_54 ;
}
}
static int F_39 ( T_2 V_50 )
{
switch ( V_50 & V_51 ) {
case V_56 :
case V_57 :
return 2 ;
case V_52 :
case V_53 :
return 1 ;
default:
return - V_54 ;
}
}
static T_2 F_40 ( struct V_19 * V_6 , T_2 V_58 , T_2 V_55 )
{
T_2 V_59 , V_60 , V_16 ;
if ( F_41 ( V_6 ) ) {
V_59 = 0x1f ;
V_60 = 5 ;
} else {
V_59 = 0x3f ;
V_60 = 6 ;
}
V_16 = ( ( V_58 + V_55 + V_59 ) >> V_60 ) - ( V_58 >> V_60 ) ;
if ( ! F_41 ( V_6 ) )
V_16 <<= 1 ;
V_16 -= 1 ;
return V_16 << 2 ;
}
static void F_42 ( struct V_1 T_1 * V_8 )
{
F_43 ( V_8 -> V_61 , V_62 , sizeof( V_62 ) ) ;
F_43 ( V_8 -> V_63 , V_64 ,
sizeof( V_64 ) ) ;
}
static bool F_44 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 ,
struct V_65 * V_66 )
{
T_2 V_67 , V_68 , V_69 , V_70 ;
#define F_45 12
#define F_46 0xfff
bool V_71 = false ;
int V_72 = F_38 ( V_66 -> V_50 ) ;
int V_73 = F_39 ( V_66 -> V_50 ) ;
if ( V_66 -> V_74 > 1 )
V_67 = ( ( V_66 -> V_75 - 1 ) << F_45 )
/ ( V_66 -> V_74 ) ;
else
V_67 = 1 << F_45 ;
if ( V_66 -> V_76 > 1 )
V_68 = ( ( V_66 -> V_77 - 1 ) << F_45 )
/ ( V_66 -> V_76 ) ;
else
V_68 = 1 << F_45 ;
V_69 = V_67 / V_72 ;
V_70 = V_68 / V_73 ;
V_67 = V_69 * V_72 ;
V_68 = V_70 * V_73 ;
if ( V_67 != V_3 -> V_48 || V_68 != V_3 -> V_49 )
V_71 = true ;
V_3 -> V_48 = V_67 ;
V_3 -> V_49 = V_68 ;
F_47 ( ( ( V_68 & F_46 ) << 20 ) |
( ( V_67 >> F_45 ) << 16 ) |
( ( V_67 & F_46 ) << 3 ) ,
& V_8 -> V_78 ) ;
F_47 ( ( ( V_70 & F_46 ) << 20 ) |
( ( V_69 >> F_45 ) << 16 ) |
( ( V_69 & F_46 ) << 3 ) ,
& V_8 -> V_79 ) ;
F_47 ( ( ( ( V_68 >> F_45 ) << 16 ) |
( ( V_70 >> F_45 ) << 0 ) ) ,
& V_8 -> V_80 ) ;
if ( V_71 )
F_42 ( V_8 ) ;
return V_71 ;
}
static void F_48 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 )
{
T_2 V_81 = V_3 -> V_82 ;
T_2 V_83 ;
V_83 = 0 ;
if ( V_3 -> V_84 )
V_83 |= V_85 ;
switch ( V_3 -> V_42 -> V_40 . V_86 -> V_87 -> V_88 ) {
case 8 :
V_81 = 0 ;
V_83 |= V_89 ;
break;
case 16 :
if ( V_3 -> V_42 -> V_40 . V_86 -> V_87 -> V_90 == 15 ) {
V_81 = F_49 ( V_81 ) ;
V_83 |= V_91 ;
} else {
V_81 = F_50 ( V_81 ) ;
V_83 |= V_92 ;
}
break;
case 24 :
case 32 :
V_83 |= V_93 ;
break;
}
F_47 ( V_81 , & V_8 -> V_94 ) ;
F_47 ( V_83 , & V_8 -> V_95 ) ;
}
static T_2 F_51 ( struct V_65 * V_66 )
{
T_2 V_96 = V_97 | V_98 | V_99 ;
if ( V_66 -> V_50 & V_100 ) {
switch ( V_66 -> V_50 & V_51 ) {
case V_52 :
V_96 |= V_101 ;
break;
case V_56 :
V_96 |= V_102 ;
break;
case V_53 :
case V_57 :
V_96 |= V_103 ;
break;
}
} else {
switch ( V_66 -> V_50 & V_51 ) {
case V_52 :
V_96 |= V_104 ;
break;
case V_53 :
V_96 |= V_105 ;
break;
}
switch ( V_66 -> V_50 & V_106 ) {
case V_107 :
break;
case V_108 :
V_96 |= V_109 ;
break;
case V_110 :
V_96 |= V_111 ;
break;
case V_112 :
V_96 |= V_113 ;
break;
}
}
return V_96 ;
}
static int F_52 ( struct V_2 * V_3 ,
struct V_37 * V_114 ,
struct V_65 * V_66 )
{
int V_16 , V_115 ;
struct V_1 T_1 * V_8 ;
bool V_71 = false ;
struct V_19 * V_6 = V_3 -> V_6 ;
T_2 V_116 , V_117 , V_118 , V_119 ;
enum V_47 V_47 = V_3 -> V_42 -> V_47 ;
F_9 ( ! F_32 ( & V_6 -> V_44 ) ) ;
F_9 ( ! F_53 ( & V_6 -> V_120 . V_121 ) ) ;
V_16 = F_31 ( V_3 ) ;
if ( V_16 != 0 )
return V_16 ;
V_16 = F_54 ( V_114 , 0 ,
& V_122 ) ;
if ( V_16 != 0 )
return V_16 ;
V_16 = F_55 ( V_114 ) ;
if ( V_16 )
goto V_123;
if ( ! V_3 -> V_23 ) {
T_2 V_124 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
V_16 = - V_125 ;
goto V_123;
}
V_124 = V_126 ;
if ( F_56 ( V_3 -> V_6 ) )
V_124 |= V_127 ;
V_124 |= V_47 == 0 ?
V_128 : V_129 ;
F_47 ( V_124 , & V_8 -> V_130 ) ;
F_5 ( V_3 , V_8 ) ;
V_16 = F_13 ( V_3 ) ;
if ( V_16 != 0 )
goto V_123;
}
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
V_16 = - V_125 ;
goto V_123;
}
F_47 ( ( V_66 -> V_131 << 16 ) | V_66 -> V_132 , & V_8 -> V_133 ) ;
F_47 ( ( V_66 -> V_76 << 16 ) | V_66 -> V_74 , & V_8 -> V_134 ) ;
if ( V_66 -> V_50 & V_135 )
V_115 = F_37 ( V_66 -> V_50 , V_66 -> V_136 ) ;
else
V_115 = V_66 -> V_136 ;
V_116 = V_66 -> V_136 ;
V_117 = F_40 ( V_3 -> V_6 , V_66 -> V_137 , V_115 ) ;
V_118 = V_66 -> V_138 ;
F_47 ( F_4 ( V_114 ) + V_66 -> V_137 , & V_8 -> V_139 ) ;
V_119 = V_66 -> V_140 ;
if ( V_66 -> V_50 & V_100 ) {
int V_72 = F_38 ( V_66 -> V_50 ) ;
int V_73 = F_39 ( V_66 -> V_50 ) ;
T_2 V_141 , V_142 ;
V_116 |= ( V_66 -> V_136 / V_72 ) << 16 ;
V_141 = F_40 ( V_3 -> V_6 , V_66 -> V_143 ,
V_66 -> V_136 / V_72 ) ;
V_142 = F_40 ( V_3 -> V_6 , V_66 -> V_144 ,
V_66 -> V_136 / V_72 ) ;
V_117 |= F_57 ( T_2 , V_141 , V_142 ) << 16 ;
V_118 |= ( V_66 -> V_138 / V_73 ) << 16 ;
F_47 ( F_4 ( V_114 ) + V_66 -> V_143 , & V_8 -> V_145 ) ;
F_47 ( F_4 ( V_114 ) + V_66 -> V_144 , & V_8 -> V_146 ) ;
V_119 |= V_66 -> V_147 << 16 ;
}
F_47 ( V_116 , & V_8 -> V_148 ) ;
F_47 ( V_117 , & V_8 -> V_149 ) ;
F_47 ( V_118 , & V_8 -> V_150 ) ;
F_47 ( V_119 , & V_8 -> V_151 ) ;
V_71 = F_44 ( V_3 , V_8 , V_66 ) ;
F_48 ( V_3 , V_8 ) ;
F_47 ( F_51 ( V_66 ) , & V_8 -> V_152 ) ;
F_5 ( V_3 , V_8 ) ;
V_16 = F_22 ( V_3 , V_71 ) ;
if ( V_16 )
goto V_123;
F_33 ( V_3 -> V_41 , V_114 ,
F_34 ( V_47 ) ) ;
V_3 -> V_39 = V_3 -> V_41 ;
V_3 -> V_41 = V_114 ;
F_58 ( V_6 ,
F_34 ( V_47 ) ) ;
return 0 ;
V_123:
F_26 ( V_114 ) ;
return V_16 ;
}
int F_59 ( struct V_2 * V_3 )
{
struct V_1 T_1 * V_8 ;
struct V_19 * V_6 = V_3 -> V_6 ;
int V_16 ;
F_9 ( ! F_32 ( & V_6 -> V_44 ) ) ;
F_9 ( ! F_53 ( & V_6 -> V_120 . V_121 ) ) ;
V_16 = F_30 ( V_3 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( ! V_3 -> V_23 )
return 0 ;
V_16 = F_31 ( V_3 ) ;
if ( V_16 != 0 )
return V_16 ;
V_8 = F_1 ( V_3 ) ;
F_47 ( 0 , & V_8 -> V_152 ) ;
F_5 ( V_3 , V_8 ) ;
V_16 = F_29 ( V_3 ) ;
if ( V_16 != 0 )
return V_16 ;
F_28 ( V_3 ) ;
return 0 ;
}
static int F_60 ( struct V_2 * V_3 ,
struct V_153 * V_42 )
{
if ( ! V_42 -> V_23 )
return - V_54 ;
if ( V_42 -> V_154 -> V_155 )
return - V_54 ;
return 0 ;
}
static void F_61 ( struct V_2 * V_3 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_7 ;
T_2 V_156 = F_23 ( V_157 ) ;
T_2 V_158 ;
if ( F_62 ( V_6 ) -> V_159 >= 4 ) {
V_158 = F_23 ( V_160 ) >> V_161 ;
} else {
if ( V_156 & V_162 )
V_158 = F_23 ( V_163 ) ;
else
V_158 = F_23 ( V_160 ) ;
V_158 >>= V_164 ;
}
V_3 -> V_165 = V_158 ;
}
static int F_63 ( struct V_2 * V_3 ,
struct V_166 * V_167 )
{
struct V_168 * V_169 = & V_3 -> V_42 -> V_40 . V_169 ;
if ( V_167 -> V_132 < V_169 -> V_170 &&
V_167 -> V_132 + V_167 -> V_171 <= V_169 -> V_170 &&
V_167 -> V_131 < V_169 -> V_172 &&
V_167 -> V_131 + V_167 -> V_173 <= V_169 -> V_172 )
return 0 ;
else
return - V_54 ;
}
static int F_64 ( struct V_65 * V_167 )
{
T_2 V_34 ;
V_34 = ( ( V_167 -> V_77 << 16 ) / V_167 -> V_76 ) >> 16 ;
if ( V_34 > 7 )
return - V_54 ;
V_34 = ( ( V_167 -> V_75 << 16 ) / V_167 -> V_74 ) >> 16 ;
if ( V_34 > 7 )
return - V_54 ;
return 0 ;
}
static int F_65 ( struct V_19 * V_6 ,
struct V_166 * V_167 ,
struct V_37 * V_114 )
{
int V_72 = F_38 ( V_167 -> V_83 ) ;
int V_73 = F_39 ( V_167 -> V_83 ) ;
T_2 V_174 ;
int V_90 ;
T_2 V_34 ;
if ( F_66 ( V_6 ) || F_14 ( V_6 ) ) {
if ( V_167 -> V_175 > V_176 ||
V_167 -> V_177 > V_178 )
return - V_54 ;
} else {
if ( V_167 -> V_175 > V_179 ||
V_167 -> V_177 > V_180 )
return - V_54 ;
}
if ( V_167 -> V_175 < V_181 * 4 ||
V_167 -> V_177 < V_182 * 4 )
return - V_54 ;
switch ( V_167 -> V_83 & V_183 ) {
case V_184 :
return - V_54 ;
case V_135 :
if ( V_73 != 1 )
return - V_54 ;
V_90 = F_36 ( V_167 -> V_83 ) ;
if ( V_90 < 0 )
return V_90 ;
V_167 -> V_147 = 0 ;
V_167 -> V_143 = 0 ;
V_167 -> V_144 = 0 ;
if ( V_167 -> V_137 % V_90 )
return - V_54 ;
break;
case V_100 :
if ( V_73 < 0 || V_72 < 0 )
return - V_54 ;
break;
default:
return - V_54 ;
}
if ( V_167 -> V_177 % V_72 )
return - V_54 ;
if ( F_14 ( V_6 ) || F_66 ( V_6 ) )
V_174 = 255 ;
else
V_174 = 63 ;
if ( V_167 -> V_140 & V_174 || V_167 -> V_147 & V_174 )
return - V_54 ;
if ( F_56 ( V_6 ) && V_167 -> V_140 < 512 )
return - V_54 ;
V_34 = ( V_167 -> V_83 & V_183 ) == V_100 ?
4096 : 8192 ;
if ( V_167 -> V_140 > V_34 || V_167 -> V_147 > 2 * 1024 )
return - V_54 ;
switch ( V_167 -> V_83 & V_183 ) {
case V_184 :
case V_135 :
if ( F_37 ( V_167 -> V_83 , V_167 -> V_177 ) > V_167 -> V_140 )
return - V_54 ;
V_34 = V_167 -> V_140 * V_167 -> V_175 ;
if ( V_167 -> V_137 + V_34 > V_114 -> V_40 . V_185 )
return - V_54 ;
break;
case V_100 :
if ( V_167 -> V_177 > V_167 -> V_140 )
return - V_54 ;
if ( V_167 -> V_177 / V_72 > V_167 -> V_147 )
return - V_54 ;
V_34 = V_167 -> V_140 * V_167 -> V_175 ;
if ( V_167 -> V_137 + V_34 > V_114 -> V_40 . V_185 )
return - V_54 ;
V_34 = V_167 -> V_147 * ( V_167 -> V_175 / V_73 ) ;
if ( V_167 -> V_143 + V_34 > V_114 -> V_40 . V_185 ||
V_167 -> V_144 + V_34 > V_114 -> V_40 . V_185 )
return - V_54 ;
break;
}
return 0 ;
}
static int F_67 ( struct V_19 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
T_2 V_156 ;
if ( F_62 ( V_6 ) -> V_159 <= 3 && ( F_14 ( V_6 ) || ! F_68 ( V_6 ) ) )
return - 1 ;
V_156 = F_23 ( V_157 ) ;
if ( ( V_156 & V_186 ) == 0 )
return - 1 ;
if ( F_56 ( V_6 ) )
return ( V_156 >> 29 ) & 0x3 ;
return 1 ;
}
int F_69 ( struct V_19 * V_6 , void * V_187 ,
struct V_188 * V_189 )
{
struct V_166 * V_190 = V_187 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 ;
struct V_191 * V_192 ;
struct V_153 * V_42 ;
struct V_37 * V_114 ;
struct V_65 * V_66 ;
int V_16 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_24 ( L_2 ) ;
return - V_193 ;
}
if ( ! ( V_190 -> V_83 & V_194 ) ) {
F_70 ( V_6 ) ;
F_71 ( & V_6 -> V_44 ) ;
V_16 = F_59 ( V_3 ) ;
F_72 ( & V_6 -> V_44 ) ;
F_73 ( V_6 ) ;
return V_16 ;
}
V_66 = F_74 ( sizeof( * V_66 ) , V_195 ) ;
if ( ! V_66 )
return - V_125 ;
V_192 = F_75 ( V_6 , V_190 -> V_196 ) ;
if ( ! V_192 ) {
V_16 = - V_197 ;
goto V_198;
}
V_42 = F_76 ( V_192 ) ;
V_114 = F_77 ( F_78 ( V_6 , V_189 ,
V_190 -> V_199 ) ) ;
if ( & V_114 -> V_40 == NULL ) {
V_16 = - V_197 ;
goto V_198;
}
F_70 ( V_6 ) ;
F_71 ( & V_6 -> V_44 ) ;
if ( V_114 -> V_200 ) {
F_79 ( L_3 ) ;
V_16 = - V_54 ;
goto V_201;
}
V_16 = F_30 ( V_3 ) ;
if ( V_16 != 0 )
goto V_201;
if ( V_3 -> V_42 != V_42 ) {
struct V_168 * V_169 = & V_42 -> V_40 . V_169 ;
V_16 = F_59 ( V_3 ) ;
if ( V_16 != 0 )
goto V_201;
V_16 = F_60 ( V_3 , V_42 ) ;
if ( V_16 != 0 )
goto V_201;
V_3 -> V_42 = V_42 ;
V_42 -> V_3 = V_3 ;
if ( V_169 -> V_170 > 1024 &&
F_67 ( V_6 ) == V_42 -> V_47 ) {
V_3 -> V_202 = true ;
F_61 ( V_3 ) ;
} else
V_3 -> V_202 = false ;
}
V_16 = F_63 ( V_3 , V_190 ) ;
if ( V_16 != 0 )
goto V_201;
if ( V_3 -> V_202 ) {
V_66 -> V_131 = ( ( ( ( T_2 ) V_190 -> V_131 ) << 12 ) /
V_3 -> V_165 ) ;
V_66 -> V_76 = ( ( ( ( T_2 ) V_190 -> V_173 ) << 12 ) /
V_3 -> V_165 ) + 1 ;
} else {
V_66 -> V_131 = V_190 -> V_131 ;
V_66 -> V_76 = V_190 -> V_173 ;
}
V_66 -> V_132 = V_190 -> V_132 ;
V_66 -> V_74 = V_190 -> V_171 ;
V_66 -> V_136 = V_190 -> V_177 ;
V_66 -> V_138 = V_190 -> V_175 ;
V_66 -> V_75 = V_190 -> V_203 ;
V_66 -> V_77 = V_190 -> V_204 ;
if ( V_66 -> V_77 > V_66 -> V_138 ||
V_66 -> V_75 > V_66 -> V_136 ) {
V_16 = - V_54 ;
goto V_201;
}
V_16 = F_65 ( V_6 , V_190 , V_114 ) ;
if ( V_16 != 0 )
goto V_201;
V_66 -> V_50 = V_190 -> V_83 & ~ V_205 ;
V_66 -> V_140 = V_190 -> V_140 ;
V_66 -> V_147 = V_190 -> V_147 ;
V_66 -> V_137 = V_190 -> V_137 ;
V_66 -> V_143 = V_190 -> V_143 ;
V_66 -> V_144 = V_190 -> V_144 ;
V_16 = F_64 ( V_66 ) ;
if ( V_16 != 0 )
goto V_201;
V_16 = F_52 ( V_3 , V_114 , V_66 ) ;
if ( V_16 != 0 )
goto V_201;
F_72 ( & V_6 -> V_44 ) ;
F_73 ( V_6 ) ;
F_80 ( V_66 ) ;
return 0 ;
V_201:
F_72 ( & V_6 -> V_44 ) ;
F_73 ( V_6 ) ;
F_81 ( & V_114 -> V_40 ) ;
V_198:
F_80 ( V_66 ) ;
return V_16 ;
}
static void F_82 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 )
{
F_47 ( ( V_3 -> V_206 << 18 ) | ( V_3 -> V_207 & 0xff ) ,
& V_8 -> V_208 ) ;
F_47 ( V_3 -> V_209 , & V_8 -> V_210 ) ;
}
static bool F_83 ( T_2 V_211 , T_2 V_212 )
{
int V_213 ;
if ( V_211 & 0xff000000 || V_212 & 0xff000000 )
return false ;
for ( V_213 = 0 ; V_213 < 3 ; V_213 ++ ) {
if ( ( ( V_211 >> V_213 * 8 ) & 0xff ) >= ( ( V_212 >> V_213 * 8 ) & 0xff ) )
return false ;
}
return true ;
}
static bool F_84 ( T_2 V_214 )
{
int V_213 ;
for ( V_213 = 0 ; V_213 < 3 ; V_213 ++ ) {
if ( ( ( V_214 >> V_213 * 8 ) & 0xff ) == 0x80 )
return false ;
}
return true ;
}
static int F_85 ( struct V_215 * V_216 )
{
if ( ! F_83 ( 0 , V_216 -> V_217 ) ||
! F_83 ( V_216 -> V_217 , V_216 -> V_211 ) ||
! F_83 ( V_216 -> V_211 , V_216 -> V_212 ) ||
! F_83 ( V_216 -> V_212 , V_216 -> V_218 ) ||
! F_83 ( V_216 -> V_218 , V_216 -> V_219 ) ||
! F_83 ( V_216 -> V_219 , V_216 -> V_214 ) ||
! F_83 ( V_216 -> V_214 , 0x00ffffff ) )
return - V_54 ;
if ( ! F_84 ( V_216 -> V_214 ) )
return - V_54 ;
return 0 ;
}
int F_86 ( struct V_19 * V_6 , void * V_187 ,
struct V_188 * V_189 )
{
struct V_215 * V_216 = V_187 ;
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 ;
struct V_1 T_1 * V_8 ;
int V_16 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_24 ( L_2 ) ;
return - V_193 ;
}
F_70 ( V_6 ) ;
F_71 ( & V_6 -> V_44 ) ;
V_16 = - V_54 ;
if ( ! ( V_216 -> V_83 & V_220 ) ) {
V_216 -> V_82 = V_3 -> V_82 ;
V_216 -> V_207 = V_3 -> V_207 ;
V_216 -> V_206 = V_3 -> V_206 ;
V_216 -> V_209 = V_3 -> V_209 ;
if ( ! F_41 ( V_6 ) ) {
V_216 -> V_217 = F_23 ( V_221 ) ;
V_216 -> V_211 = F_23 ( V_222 ) ;
V_216 -> V_212 = F_23 ( V_223 ) ;
V_216 -> V_218 = F_23 ( V_224 ) ;
V_216 -> V_219 = F_23 ( V_225 ) ;
V_216 -> V_214 = F_23 ( V_226 ) ;
}
} else {
if ( V_216 -> V_207 < - 128 || V_216 -> V_207 > 127 )
goto V_201;
if ( V_216 -> V_206 > 255 )
goto V_201;
if ( V_216 -> V_209 > 1023 )
goto V_201;
V_3 -> V_82 = V_216 -> V_82 ;
V_3 -> V_207 = V_216 -> V_207 ;
V_3 -> V_206 = V_216 -> V_206 ;
V_3 -> V_209 = V_216 -> V_209 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
V_16 = - V_125 ;
goto V_201;
}
F_82 ( V_3 , V_8 ) ;
F_5 ( V_3 , V_8 ) ;
if ( V_216 -> V_83 & V_227 ) {
if ( F_41 ( V_6 ) )
goto V_201;
if ( V_3 -> V_23 ) {
V_16 = - V_228 ;
goto V_201;
}
V_16 = F_85 ( V_216 ) ;
if ( V_16 )
goto V_201;
F_87 ( V_221 , V_216 -> V_217 ) ;
F_87 ( V_222 , V_216 -> V_211 ) ;
F_87 ( V_223 , V_216 -> V_212 ) ;
F_87 ( V_224 , V_216 -> V_218 ) ;
F_87 ( V_225 , V_216 -> V_219 ) ;
F_87 ( V_226 , V_216 -> V_214 ) ;
}
}
V_3 -> V_84 = ( V_216 -> V_83 & V_229 ) == 0 ;
V_16 = 0 ;
V_201:
F_72 ( & V_6 -> V_44 ) ;
F_73 ( V_6 ) ;
return V_16 ;
}
void F_88 ( struct V_19 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 ;
struct V_37 * V_9 ;
struct V_1 T_1 * V_8 ;
int V_16 ;
if ( ! F_89 ( V_6 ) )
return;
V_3 = F_90 ( sizeof( * V_3 ) , V_195 ) ;
if ( ! V_3 )
return;
F_71 ( & V_6 -> V_44 ) ;
if ( F_9 ( V_5 -> V_3 ) )
goto V_198;
V_3 -> V_6 = V_6 ;
V_9 = NULL ;
if ( ! F_2 ( V_6 ) )
V_9 = F_91 ( V_6 , V_230 ) ;
if ( V_9 == NULL )
V_9 = F_92 ( V_6 , V_230 ) ;
if ( V_9 == NULL )
goto V_198;
V_3 -> V_9 = V_9 ;
if ( F_2 ( V_6 ) ) {
V_16 = F_93 ( V_9 , V_230 ) ;
if ( V_16 ) {
F_94 ( L_4 ) ;
goto V_231;
}
V_3 -> V_28 = V_9 -> V_10 -> V_232 ;
} else {
V_16 = F_95 ( V_9 , V_230 , V_233 ) ;
if ( V_16 ) {
F_94 ( L_5 ) ;
goto V_231;
}
V_3 -> V_28 = F_4 ( V_9 ) ;
V_16 = F_96 ( V_9 , true ) ;
if ( V_16 ) {
F_94 ( L_6 ) ;
goto V_234;
}
}
V_3 -> V_82 = 0x0101fe ;
V_3 -> V_84 = true ;
V_3 -> V_207 = - 19 ;
V_3 -> V_206 = 75 ;
V_3 -> V_209 = 146 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 )
goto V_234;
F_97 ( V_8 , 0 , sizeof( struct V_1 ) ) ;
F_42 ( V_8 ) ;
F_82 ( V_3 , V_8 ) ;
F_5 ( V_3 , V_8 ) ;
V_5 -> V_3 = V_3 ;
F_72 ( & V_6 -> V_44 ) ;
F_98 ( L_7 ) ;
return;
V_234:
if ( ! F_2 ( V_6 ) )
F_26 ( V_9 ) ;
V_231:
F_27 ( & V_9 -> V_40 ) ;
V_198:
F_72 ( & V_6 -> V_44 ) ;
F_80 ( V_3 ) ;
return;
}
void F_99 ( struct V_19 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
if ( ! V_5 -> V_3 )
return;
F_9 ( V_5 -> V_3 -> V_23 ) ;
F_81 ( & V_5 -> V_3 -> V_9 -> V_40 ) ;
F_80 ( V_5 -> V_3 ) ;
}
static struct V_1 T_1 *
F_100 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
struct V_1 T_1 * V_8 ;
if ( F_2 ( V_3 -> V_6 ) )
V_8 = (struct V_1 T_1 * )
V_3 -> V_9 -> V_10 -> V_11 ;
else
V_8 = F_101 ( V_5 -> V_12 . V_13 ,
F_4 ( V_3 -> V_9 ) ) ;
return V_8 ;
}
static void F_102 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_8 )
{
if ( ! F_2 ( V_3 -> V_6 ) )
F_103 ( V_8 ) ;
}
struct V_235 *
F_104 ( struct V_19 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 ;
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_235 * error ;
struct V_1 T_1 * V_8 ;
if ( ! V_3 || ! V_3 -> V_23 )
return NULL ;
error = F_74 ( sizeof( * error ) , V_236 ) ;
if ( error == NULL )
return NULL ;
error -> V_237 = F_23 ( V_35 ) ;
error -> V_238 = F_23 ( V_45 ) ;
if ( F_2 ( V_3 -> V_6 ) )
error -> V_40 = ( V_239 long ) V_3 -> V_9 -> V_10 -> V_11 ;
else
error -> V_40 = F_4 ( V_3 -> V_9 ) ;
V_8 = F_100 ( V_3 ) ;
if ( ! V_8 )
goto V_240;
F_105 ( & error -> V_8 , V_8 , sizeof( struct V_1 ) ) ;
F_102 ( V_3 , V_8 ) ;
return error ;
V_240:
F_80 ( error ) ;
return NULL ;
}
void
F_106 ( struct V_241 * V_242 ,
struct V_235 * error )
{
F_107 ( V_242 , L_8 ,
error -> V_237 , error -> V_238 ) ;
F_107 ( V_242 , L_9 ,
error -> V_40 ) ;
#define F_108 ( T_3 ) i915_error_printf(m, " " #x ": 0x%08x\n", error->regs.x)
F_108 ( V_139 ) ;
F_108 ( V_243 ) ;
F_108 ( V_145 ) ;
F_108 ( V_146 ) ;
F_108 ( V_244 ) ;
F_108 ( V_245 ) ;
F_108 ( V_151 ) ;
F_108 ( V_246 ) ;
F_108 ( V_247 ) ;
F_108 ( V_248 ) ;
F_108 ( V_249 ) ;
F_108 ( V_133 ) ;
F_108 ( V_134 ) ;
F_108 ( V_148 ) ;
F_108 ( V_149 ) ;
F_108 ( V_150 ) ;
F_108 ( V_78 ) ;
F_108 ( V_79 ) ;
F_108 ( V_208 ) ;
F_108 ( V_210 ) ;
F_108 ( V_94 ) ;
F_108 ( V_95 ) ;
F_108 ( V_250 ) ;
F_108 ( V_251 ) ;
F_108 ( V_252 ) ;
F_108 ( V_130 ) ;
F_108 ( V_152 ) ;
F_108 ( V_253 ) ;
F_108 ( V_254 ) ;
F_108 ( V_255 ) ;
F_108 ( V_256 ) ;
F_108 ( V_257 ) ;
F_108 ( V_258 ) ;
F_108 ( V_259 ) ;
F_108 ( V_260 ) ;
F_108 ( V_261 ) ;
F_108 ( V_262 ) ;
F_108 ( V_263 ) ;
F_108 ( V_264 ) ;
F_108 ( V_265 ) ;
F_108 ( V_80 ) ;
#undef F_108
}
