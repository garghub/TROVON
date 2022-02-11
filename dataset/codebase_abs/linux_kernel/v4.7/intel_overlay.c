static struct V_1 T_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
struct V_7 * V_8 = & V_5 -> V_8 ;
struct V_1 T_1 * V_9 ;
if ( F_3 ( V_3 -> V_6 ) )
V_9 = (struct V_1 T_1 * ) V_3 -> V_10 -> V_11 -> V_12 ;
else
V_9 = F_4 ( V_8 -> V_13 ,
F_5 ( V_3 -> V_10 ) ) ;
return V_9 ;
}
static void F_6 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_9 )
{
if ( ! F_3 ( V_3 -> V_6 ) )
F_7 ( V_9 ) ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_14 * V_15 ,
void (* F_9)( struct V_2 * ) )
{
int V_16 ;
F_10 ( V_3 -> V_17 ) ;
F_11 ( & V_3 -> V_17 , V_15 ) ;
F_12 ( V_15 ) ;
V_3 -> V_18 = F_9 ;
V_16 = F_13 ( V_3 -> V_17 ) ;
if ( V_16 )
return V_16 ;
F_11 ( & V_3 -> V_17 , NULL ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_20 ;
struct V_21 * V_22 = & V_5 -> V_22 [ V_23 ] ;
struct V_14 * V_15 ;
int V_16 ;
F_10 ( V_3 -> V_24 ) ;
F_10 ( F_15 ( V_6 ) && ! ( V_5 -> V_25 & V_26 ) ) ;
V_15 = F_16 ( V_22 , NULL ) ;
if ( F_17 ( V_15 ) )
return F_18 ( V_15 ) ;
V_16 = F_19 ( V_15 , 4 ) ;
if ( V_16 ) {
F_20 ( V_15 ) ;
return V_16 ;
}
V_3 -> V_24 = true ;
F_21 ( V_22 , V_27 | V_28 ) ;
F_21 ( V_22 , V_3 -> V_29 | V_30 ) ;
F_21 ( V_22 , V_31 | V_32 ) ;
F_21 ( V_22 , V_33 ) ;
F_22 ( V_22 ) ;
return F_8 ( V_3 , V_15 , NULL ) ;
}
static int F_23 ( struct V_2 * V_3 ,
bool V_34 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_20 ;
struct V_21 * V_22 = & V_5 -> V_22 [ V_23 ] ;
struct V_14 * V_15 ;
T_2 V_29 = V_3 -> V_29 ;
T_2 V_35 ;
int V_16 ;
F_10 ( ! V_3 -> V_24 ) ;
if ( V_34 )
V_29 |= V_30 ;
V_35 = F_24 ( V_36 ) ;
if ( V_35 & ( 1 << 17 ) )
F_25 ( L_1 , V_35 ) ;
V_15 = F_16 ( V_22 , NULL ) ;
if ( F_17 ( V_15 ) )
return F_18 ( V_15 ) ;
V_16 = F_19 ( V_15 , 2 ) ;
if ( V_16 ) {
F_20 ( V_15 ) ;
return V_16 ;
}
F_21 ( V_22 , V_27 | V_37 ) ;
F_21 ( V_22 , V_29 ) ;
F_22 ( V_22 ) ;
F_10 ( V_3 -> V_17 ) ;
F_11 ( & V_3 -> V_17 , V_15 ) ;
F_12 ( V_15 ) ;
return 0 ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_38 * V_39 = V_3 -> V_40 ;
F_27 ( V_39 ) ;
F_28 ( & V_39 -> V_41 ) ;
V_3 -> V_40 = NULL ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_38 * V_39 = V_3 -> V_42 ;
if ( F_10 ( ! V_39 ) )
return;
F_27 ( V_39 ) ;
F_28 ( & V_39 -> V_41 ) ;
V_3 -> V_42 = NULL ;
V_3 -> V_43 -> V_3 = NULL ;
V_3 -> V_43 = NULL ;
V_3 -> V_24 = false ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_20 ;
struct V_21 * V_22 = & V_5 -> V_22 [ V_23 ] ;
struct V_14 * V_15 ;
T_2 V_29 = V_3 -> V_29 ;
int V_16 ;
F_10 ( ! V_3 -> V_24 ) ;
V_29 |= V_30 ;
V_15 = F_16 ( V_22 , NULL ) ;
if ( F_17 ( V_15 ) )
return F_18 ( V_15 ) ;
V_16 = F_19 ( V_15 , 6 ) ;
if ( V_16 ) {
F_20 ( V_15 ) ;
return V_16 ;
}
F_21 ( V_22 , V_27 | V_37 ) ;
F_21 ( V_22 , V_29 ) ;
F_21 ( V_22 , V_31 | V_32 ) ;
if ( F_15 ( V_6 ) ) {
F_21 ( V_22 , V_33 ) ;
F_21 ( V_22 , V_33 ) ;
F_21 ( V_22 , V_33 ) ;
} else {
F_21 ( V_22 , V_27 | V_44 ) ;
F_21 ( V_22 , V_29 ) ;
F_21 ( V_22 ,
V_31 | V_32 ) ;
}
F_22 ( V_22 ) ;
return F_8 ( V_3 , V_15 , F_29 ) ;
}
static int F_31 ( struct V_2 * V_3 )
{
int V_16 ;
if ( V_3 -> V_17 == NULL )
return 0 ;
V_16 = F_13 ( V_3 -> V_17 ) ;
if ( V_16 )
return V_16 ;
if ( V_3 -> V_18 )
V_3 -> V_18 ( V_3 ) ;
F_11 ( & V_3 -> V_17 , NULL ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_20 ;
struct V_21 * V_22 = & V_5 -> V_22 [ V_23 ] ;
int V_16 ;
F_10 ( ! F_33 ( & V_6 -> V_45 ) ) ;
if ( ! V_3 -> V_40 )
return 0 ;
if ( F_24 ( V_46 ) & V_47 ) {
struct V_14 * V_15 ;
V_15 = F_16 ( V_22 , NULL ) ;
if ( F_17 ( V_15 ) )
return F_18 ( V_15 ) ;
V_16 = F_19 ( V_15 , 2 ) ;
if ( V_16 ) {
F_20 ( V_15 ) ;
return V_16 ;
}
F_21 ( V_22 ,
V_31 | V_32 ) ;
F_21 ( V_22 , V_33 ) ;
F_22 ( V_22 ) ;
V_16 = F_8 ( V_3 , V_15 ,
F_26 ) ;
if ( V_16 )
return V_16 ;
}
F_26 ( V_3 ) ;
F_34 ( V_3 -> V_40 , NULL ,
F_35 ( V_3 -> V_43 -> V_48 ) ) ;
return 0 ;
}
void F_36 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
if ( ! V_3 )
return;
F_32 ( V_3 ) ;
V_3 -> V_17 = NULL ;
V_3 -> V_49 = 0 ;
V_3 -> V_50 = 0 ;
V_3 -> V_43 = NULL ;
V_3 -> V_24 = false ;
}
static int F_37 ( T_2 V_51 )
{
switch ( V_51 & V_52 ) {
case V_53 :
return 4 ;
case V_54 :
default:
return - V_55 ;
}
}
static int F_38 ( T_2 V_51 , short V_56 )
{
switch ( V_51 & V_52 ) {
case V_53 :
return V_56 << 1 ;
default:
return - V_55 ;
}
}
static int F_39 ( T_2 V_51 )
{
switch ( V_51 & V_52 ) {
case V_53 :
case V_57 :
return 2 ;
case V_54 :
case V_58 :
return 4 ;
default:
return - V_55 ;
}
}
static int F_40 ( T_2 V_51 )
{
switch ( V_51 & V_52 ) {
case V_57 :
case V_58 :
return 2 ;
case V_53 :
case V_54 :
return 1 ;
default:
return - V_55 ;
}
}
static T_2 F_41 ( struct V_19 * V_6 , T_2 V_59 , T_2 V_56 )
{
T_2 V_60 , V_61 , V_16 ;
if ( F_42 ( V_6 ) ) {
V_60 = 0x1f ;
V_61 = 5 ;
} else {
V_60 = 0x3f ;
V_61 = 6 ;
}
V_16 = ( ( V_59 + V_56 + V_60 ) >> V_61 ) - ( V_59 >> V_61 ) ;
if ( ! F_42 ( V_6 ) )
V_16 <<= 1 ;
V_16 -= 1 ;
return V_16 << 2 ;
}
static void F_43 ( struct V_1 T_1 * V_9 )
{
F_44 ( V_9 -> V_62 , V_63 , sizeof( V_63 ) ) ;
F_44 ( V_9 -> V_64 , V_65 ,
sizeof( V_65 ) ) ;
}
static bool F_45 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_9 ,
struct V_66 * V_67 )
{
T_2 V_68 , V_69 , V_70 , V_71 ;
#define F_46 12
#define F_47 0xfff
bool V_72 = false ;
int V_73 = F_39 ( V_67 -> V_51 ) ;
int V_74 = F_40 ( V_67 -> V_51 ) ;
if ( V_67 -> V_75 > 1 )
V_68 = ( ( V_67 -> V_76 - 1 ) << F_46 )
/ ( V_67 -> V_75 ) ;
else
V_68 = 1 << F_46 ;
if ( V_67 -> V_77 > 1 )
V_69 = ( ( V_67 -> V_78 - 1 ) << F_46 )
/ ( V_67 -> V_77 ) ;
else
V_69 = 1 << F_46 ;
V_70 = V_68 / V_73 ;
V_71 = V_69 / V_74 ;
V_68 = V_70 * V_73 ;
V_69 = V_71 * V_74 ;
if ( V_68 != V_3 -> V_49 || V_69 != V_3 -> V_50 )
V_72 = true ;
V_3 -> V_49 = V_68 ;
V_3 -> V_50 = V_69 ;
F_48 ( ( ( V_69 & F_47 ) << 20 ) |
( ( V_68 >> F_46 ) << 16 ) |
( ( V_68 & F_47 ) << 3 ) ,
& V_9 -> V_79 ) ;
F_48 ( ( ( V_71 & F_47 ) << 20 ) |
( ( V_70 >> F_46 ) << 16 ) |
( ( V_70 & F_47 ) << 3 ) ,
& V_9 -> V_80 ) ;
F_48 ( ( ( ( V_69 >> F_46 ) << 16 ) |
( ( V_71 >> F_46 ) << 0 ) ) ,
& V_9 -> V_81 ) ;
if ( V_72 )
F_43 ( V_9 ) ;
return V_72 ;
}
static void F_49 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_9 )
{
T_2 V_82 = V_3 -> V_83 ;
T_2 V_84 ;
V_84 = 0 ;
if ( V_3 -> V_85 )
V_84 |= V_86 ;
switch ( V_3 -> V_43 -> V_41 . V_87 -> V_88 -> V_89 ) {
case 8 :
V_82 = 0 ;
V_84 |= V_90 ;
break;
case 16 :
if ( V_3 -> V_43 -> V_41 . V_87 -> V_88 -> V_91 == 15 ) {
V_82 = F_50 ( V_82 ) ;
V_84 |= V_92 ;
} else {
V_82 = F_51 ( V_82 ) ;
V_84 |= V_93 ;
}
break;
case 24 :
case 32 :
V_84 |= V_94 ;
break;
}
F_48 ( V_82 , & V_9 -> V_95 ) ;
F_48 ( V_84 , & V_9 -> V_96 ) ;
}
static T_2 F_52 ( struct V_66 * V_67 )
{
T_2 V_97 = V_98 | V_99 | V_100 ;
if ( V_67 -> V_51 & V_101 ) {
switch ( V_67 -> V_51 & V_52 ) {
case V_53 :
V_97 |= V_102 ;
break;
case V_57 :
V_97 |= V_103 ;
break;
case V_54 :
case V_58 :
V_97 |= V_104 ;
break;
}
} else {
switch ( V_67 -> V_51 & V_52 ) {
case V_53 :
V_97 |= V_105 ;
break;
case V_54 :
V_97 |= V_106 ;
break;
}
switch ( V_67 -> V_51 & V_107 ) {
case V_108 :
break;
case V_109 :
V_97 |= V_110 ;
break;
case V_111 :
V_97 |= V_112 ;
break;
case V_113 :
V_97 |= V_114 ;
break;
}
}
return V_97 ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_38 * V_115 ,
struct V_66 * V_67 )
{
int V_16 , V_116 ;
struct V_1 T_1 * V_9 ;
bool V_72 = false ;
struct V_19 * V_6 = V_3 -> V_6 ;
T_2 V_117 , V_118 , V_119 , V_120 ;
enum V_48 V_48 = V_3 -> V_43 -> V_48 ;
F_10 ( ! F_33 ( & V_6 -> V_45 ) ) ;
F_10 ( ! F_54 ( & V_6 -> V_121 . V_122 ) ) ;
V_16 = F_32 ( V_3 ) ;
if ( V_16 != 0 )
return V_16 ;
V_16 = F_55 ( V_115 , 0 ,
& V_123 ) ;
if ( V_16 != 0 )
return V_16 ;
V_16 = F_56 ( V_115 ) ;
if ( V_16 )
goto V_124;
if ( ! V_3 -> V_24 ) {
T_2 V_125 ;
V_9 = F_1 ( V_3 ) ;
if ( ! V_9 ) {
V_16 = - V_126 ;
goto V_124;
}
V_125 = V_127 ;
if ( F_57 ( V_3 -> V_6 ) )
V_125 |= V_128 ;
V_125 |= V_48 == 0 ?
V_129 : V_130 ;
F_48 ( V_125 , & V_9 -> V_131 ) ;
F_6 ( V_3 , V_9 ) ;
V_16 = F_14 ( V_3 ) ;
if ( V_16 != 0 )
goto V_124;
}
V_9 = F_1 ( V_3 ) ;
if ( ! V_9 ) {
V_16 = - V_126 ;
goto V_124;
}
F_48 ( ( V_67 -> V_132 << 16 ) | V_67 -> V_133 , & V_9 -> V_134 ) ;
F_48 ( ( V_67 -> V_77 << 16 ) | V_67 -> V_75 , & V_9 -> V_135 ) ;
if ( V_67 -> V_51 & V_136 )
V_116 = F_38 ( V_67 -> V_51 , V_67 -> V_137 ) ;
else
V_116 = V_67 -> V_137 ;
V_117 = V_67 -> V_137 ;
V_118 = F_41 ( V_3 -> V_6 , V_67 -> V_138 , V_116 ) ;
V_119 = V_67 -> V_139 ;
F_48 ( F_5 ( V_115 ) + V_67 -> V_138 , & V_9 -> V_140 ) ;
V_120 = V_67 -> V_141 ;
if ( V_67 -> V_51 & V_101 ) {
int V_73 = F_39 ( V_67 -> V_51 ) ;
int V_74 = F_40 ( V_67 -> V_51 ) ;
T_2 V_142 , V_143 ;
V_117 |= ( V_67 -> V_137 / V_73 ) << 16 ;
V_142 = F_41 ( V_3 -> V_6 , V_67 -> V_144 ,
V_67 -> V_137 / V_73 ) ;
V_143 = F_41 ( V_3 -> V_6 , V_67 -> V_145 ,
V_67 -> V_137 / V_73 ) ;
V_118 |= F_58 ( T_2 , V_142 , V_143 ) << 16 ;
V_119 |= ( V_67 -> V_139 / V_74 ) << 16 ;
F_48 ( F_5 ( V_115 ) + V_67 -> V_144 , & V_9 -> V_146 ) ;
F_48 ( F_5 ( V_115 ) + V_67 -> V_145 , & V_9 -> V_147 ) ;
V_120 |= V_67 -> V_148 << 16 ;
}
F_48 ( V_117 , & V_9 -> V_149 ) ;
F_48 ( V_118 , & V_9 -> V_150 ) ;
F_48 ( V_119 , & V_9 -> V_151 ) ;
F_48 ( V_120 , & V_9 -> V_152 ) ;
V_72 = F_45 ( V_3 , V_9 , V_67 ) ;
F_49 ( V_3 , V_9 ) ;
F_48 ( F_52 ( V_67 ) , & V_9 -> V_153 ) ;
F_6 ( V_3 , V_9 ) ;
V_16 = F_23 ( V_3 , V_72 ) ;
if ( V_16 )
goto V_124;
F_34 ( V_3 -> V_42 , V_115 ,
F_35 ( V_48 ) ) ;
V_3 -> V_40 = V_3 -> V_42 ;
V_3 -> V_42 = V_115 ;
F_59 ( V_6 ,
F_35 ( V_48 ) ) ;
return 0 ;
V_124:
F_27 ( V_115 ) ;
return V_16 ;
}
int F_60 ( struct V_2 * V_3 )
{
struct V_1 T_1 * V_9 ;
struct V_19 * V_6 = V_3 -> V_6 ;
int V_16 ;
F_10 ( ! F_33 ( & V_6 -> V_45 ) ) ;
F_10 ( ! F_54 ( & V_6 -> V_121 . V_122 ) ) ;
V_16 = F_31 ( V_3 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( ! V_3 -> V_24 )
return 0 ;
V_16 = F_32 ( V_3 ) ;
if ( V_16 != 0 )
return V_16 ;
V_9 = F_1 ( V_3 ) ;
F_48 ( 0 , & V_9 -> V_153 ) ;
F_6 ( V_3 , V_9 ) ;
V_16 = F_30 ( V_3 ) ;
if ( V_16 != 0 )
return V_16 ;
F_29 ( V_3 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 ,
struct V_154 * V_43 )
{
if ( ! V_43 -> V_24 )
return - V_55 ;
if ( V_43 -> V_155 -> V_156 )
return - V_55 ;
return 0 ;
}
static void F_62 ( struct V_2 * V_3 )
{
struct V_19 * V_6 = V_3 -> V_6 ;
struct V_4 * V_5 = V_6 -> V_20 ;
T_2 V_157 = F_24 ( V_158 ) ;
T_2 V_159 ;
if ( F_63 ( V_6 ) -> V_160 >= 4 ) {
V_159 = F_24 ( V_161 ) >> V_162 ;
} else {
if ( V_157 & V_163 )
V_159 = F_24 ( V_164 ) ;
else
V_159 = F_24 ( V_161 ) ;
V_159 >>= V_165 ;
}
V_3 -> V_166 = V_159 ;
}
static int F_64 ( struct V_2 * V_3 ,
struct V_167 * V_168 )
{
struct V_169 * V_170 = & V_3 -> V_43 -> V_41 . V_170 ;
if ( V_168 -> V_133 < V_170 -> V_171 &&
V_168 -> V_133 + V_168 -> V_172 <= V_170 -> V_171 &&
V_168 -> V_132 < V_170 -> V_173 &&
V_168 -> V_132 + V_168 -> V_174 <= V_170 -> V_173 )
return 0 ;
else
return - V_55 ;
}
static int F_65 ( struct V_66 * V_168 )
{
T_2 V_35 ;
V_35 = ( ( V_168 -> V_78 << 16 ) / V_168 -> V_77 ) >> 16 ;
if ( V_35 > 7 )
return - V_55 ;
V_35 = ( ( V_168 -> V_76 << 16 ) / V_168 -> V_75 ) >> 16 ;
if ( V_35 > 7 )
return - V_55 ;
return 0 ;
}
static int F_66 ( struct V_19 * V_6 ,
struct V_167 * V_168 ,
struct V_38 * V_115 )
{
int V_73 = F_39 ( V_168 -> V_84 ) ;
int V_74 = F_40 ( V_168 -> V_84 ) ;
T_2 V_175 ;
int V_91 ;
T_2 V_35 ;
if ( F_67 ( V_6 ) || F_15 ( V_6 ) ) {
if ( V_168 -> V_176 > V_177 ||
V_168 -> V_178 > V_179 )
return - V_55 ;
} else {
if ( V_168 -> V_176 > V_180 ||
V_168 -> V_178 > V_181 )
return - V_55 ;
}
if ( V_168 -> V_176 < V_182 * 4 ||
V_168 -> V_178 < V_183 * 4 )
return - V_55 ;
switch ( V_168 -> V_84 & V_184 ) {
case V_185 :
return - V_55 ;
case V_136 :
if ( V_74 != 1 )
return - V_55 ;
V_91 = F_37 ( V_168 -> V_84 ) ;
if ( V_91 < 0 )
return V_91 ;
V_168 -> V_148 = 0 ;
V_168 -> V_144 = 0 ;
V_168 -> V_145 = 0 ;
if ( V_168 -> V_138 % V_91 )
return - V_55 ;
break;
case V_101 :
if ( V_74 < 0 || V_73 < 0 )
return - V_55 ;
break;
default:
return - V_55 ;
}
if ( V_168 -> V_178 % V_73 )
return - V_55 ;
if ( F_15 ( V_6 ) || F_67 ( V_6 ) )
V_175 = 255 ;
else
V_175 = 63 ;
if ( V_168 -> V_141 & V_175 || V_168 -> V_148 & V_175 )
return - V_55 ;
if ( F_57 ( V_6 ) && V_168 -> V_141 < 512 )
return - V_55 ;
V_35 = ( V_168 -> V_84 & V_184 ) == V_101 ?
4096 : 8192 ;
if ( V_168 -> V_141 > V_35 || V_168 -> V_148 > 2 * 1024 )
return - V_55 ;
switch ( V_168 -> V_84 & V_184 ) {
case V_185 :
case V_136 :
if ( F_38 ( V_168 -> V_84 , V_168 -> V_178 ) > V_168 -> V_141 )
return - V_55 ;
V_35 = V_168 -> V_141 * V_168 -> V_176 ;
if ( V_168 -> V_138 + V_35 > V_115 -> V_41 . V_186 )
return - V_55 ;
break;
case V_101 :
if ( V_168 -> V_178 > V_168 -> V_141 )
return - V_55 ;
if ( V_168 -> V_178 / V_73 > V_168 -> V_148 )
return - V_55 ;
V_35 = V_168 -> V_141 * V_168 -> V_176 ;
if ( V_168 -> V_138 + V_35 > V_115 -> V_41 . V_186 )
return - V_55 ;
V_35 = V_168 -> V_148 * ( V_168 -> V_176 / V_74 ) ;
if ( V_168 -> V_144 + V_35 > V_115 -> V_41 . V_186 ||
V_168 -> V_145 + V_35 > V_115 -> V_41 . V_186 )
return - V_55 ;
break;
}
return 0 ;
}
static int F_68 ( struct V_19 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_20 ;
T_2 V_157 ;
if ( F_63 ( V_6 ) -> V_160 <= 3 && ( F_15 ( V_6 ) || ! F_69 ( V_6 ) ) )
return - 1 ;
V_157 = F_24 ( V_158 ) ;
if ( ( V_157 & V_187 ) == 0 )
return - 1 ;
if ( F_57 ( V_6 ) )
return ( V_157 >> 29 ) & 0x3 ;
return 1 ;
}
int F_70 ( struct V_19 * V_6 , void * V_188 ,
struct V_189 * V_190 )
{
struct V_167 * V_191 = V_188 ;
struct V_4 * V_5 = V_6 -> V_20 ;
struct V_2 * V_3 ;
struct V_192 * V_193 ;
struct V_154 * V_43 ;
struct V_38 * V_115 ;
struct V_66 * V_67 ;
int V_16 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_25 ( L_2 ) ;
return - V_194 ;
}
if ( ! ( V_191 -> V_84 & V_195 ) ) {
F_71 ( V_6 ) ;
F_72 ( & V_6 -> V_45 ) ;
V_16 = F_60 ( V_3 ) ;
F_73 ( & V_6 -> V_45 ) ;
F_74 ( V_6 ) ;
return V_16 ;
}
V_67 = F_75 ( sizeof( * V_67 ) , V_196 ) ;
if ( ! V_67 )
return - V_126 ;
V_193 = F_76 ( V_6 , V_191 -> V_197 ) ;
if ( ! V_193 ) {
V_16 = - V_198 ;
goto V_199;
}
V_43 = F_77 ( V_193 ) ;
V_115 = F_78 ( F_79 ( V_190 ,
V_191 -> V_200 ) ) ;
if ( & V_115 -> V_41 == NULL ) {
V_16 = - V_198 ;
goto V_199;
}
F_71 ( V_6 ) ;
F_72 ( & V_6 -> V_45 ) ;
if ( V_115 -> V_201 ) {
F_80 ( L_3 ) ;
V_16 = - V_55 ;
goto V_202;
}
V_16 = F_31 ( V_3 ) ;
if ( V_16 != 0 )
goto V_202;
if ( V_3 -> V_43 != V_43 ) {
struct V_169 * V_170 = & V_43 -> V_41 . V_170 ;
V_16 = F_60 ( V_3 ) ;
if ( V_16 != 0 )
goto V_202;
V_16 = F_61 ( V_3 , V_43 ) ;
if ( V_16 != 0 )
goto V_202;
V_3 -> V_43 = V_43 ;
V_43 -> V_3 = V_3 ;
if ( V_170 -> V_171 > 1024 &&
F_68 ( V_6 ) == V_43 -> V_48 ) {
V_3 -> V_203 = true ;
F_62 ( V_3 ) ;
} else
V_3 -> V_203 = false ;
}
V_16 = F_64 ( V_3 , V_191 ) ;
if ( V_16 != 0 )
goto V_202;
if ( V_3 -> V_203 ) {
V_67 -> V_132 = ( ( ( ( T_2 ) V_191 -> V_132 ) << 12 ) /
V_3 -> V_166 ) ;
V_67 -> V_77 = ( ( ( ( T_2 ) V_191 -> V_174 ) << 12 ) /
V_3 -> V_166 ) + 1 ;
} else {
V_67 -> V_132 = V_191 -> V_132 ;
V_67 -> V_77 = V_191 -> V_174 ;
}
V_67 -> V_133 = V_191 -> V_133 ;
V_67 -> V_75 = V_191 -> V_172 ;
V_67 -> V_137 = V_191 -> V_178 ;
V_67 -> V_139 = V_191 -> V_176 ;
V_67 -> V_76 = V_191 -> V_204 ;
V_67 -> V_78 = V_191 -> V_205 ;
if ( V_67 -> V_78 > V_67 -> V_139 ||
V_67 -> V_76 > V_67 -> V_137 ) {
V_16 = - V_55 ;
goto V_202;
}
V_16 = F_66 ( V_6 , V_191 , V_115 ) ;
if ( V_16 != 0 )
goto V_202;
V_67 -> V_51 = V_191 -> V_84 & ~ V_206 ;
V_67 -> V_141 = V_191 -> V_141 ;
V_67 -> V_148 = V_191 -> V_148 ;
V_67 -> V_138 = V_191 -> V_138 ;
V_67 -> V_144 = V_191 -> V_144 ;
V_67 -> V_145 = V_191 -> V_145 ;
V_16 = F_65 ( V_67 ) ;
if ( V_16 != 0 )
goto V_202;
V_16 = F_53 ( V_3 , V_115 , V_67 ) ;
if ( V_16 != 0 )
goto V_202;
F_73 ( & V_6 -> V_45 ) ;
F_74 ( V_6 ) ;
F_81 ( V_67 ) ;
return 0 ;
V_202:
F_73 ( & V_6 -> V_45 ) ;
F_74 ( V_6 ) ;
F_82 ( & V_115 -> V_41 ) ;
V_199:
F_81 ( V_67 ) ;
return V_16 ;
}
static void F_83 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_9 )
{
F_48 ( ( V_3 -> V_207 << 18 ) | ( V_3 -> V_208 & 0xff ) ,
& V_9 -> V_209 ) ;
F_48 ( V_3 -> V_210 , & V_9 -> V_211 ) ;
}
static bool F_84 ( T_2 V_212 , T_2 V_213 )
{
int V_214 ;
if ( V_212 & 0xff000000 || V_213 & 0xff000000 )
return false ;
for ( V_214 = 0 ; V_214 < 3 ; V_214 ++ ) {
if ( ( ( V_212 >> V_214 * 8 ) & 0xff ) >= ( ( V_213 >> V_214 * 8 ) & 0xff ) )
return false ;
}
return true ;
}
static bool F_85 ( T_2 V_215 )
{
int V_214 ;
for ( V_214 = 0 ; V_214 < 3 ; V_214 ++ ) {
if ( ( ( V_215 >> V_214 * 8 ) & 0xff ) == 0x80 )
return false ;
}
return true ;
}
static int F_86 ( struct V_216 * V_217 )
{
if ( ! F_84 ( 0 , V_217 -> V_218 ) ||
! F_84 ( V_217 -> V_218 , V_217 -> V_212 ) ||
! F_84 ( V_217 -> V_212 , V_217 -> V_213 ) ||
! F_84 ( V_217 -> V_213 , V_217 -> V_219 ) ||
! F_84 ( V_217 -> V_219 , V_217 -> V_220 ) ||
! F_84 ( V_217 -> V_220 , V_217 -> V_215 ) ||
! F_84 ( V_217 -> V_215 , 0x00ffffff ) )
return - V_55 ;
if ( ! F_85 ( V_217 -> V_215 ) )
return - V_55 ;
return 0 ;
}
int F_87 ( struct V_19 * V_6 , void * V_188 ,
struct V_189 * V_190 )
{
struct V_216 * V_217 = V_188 ;
struct V_4 * V_5 = V_6 -> V_20 ;
struct V_2 * V_3 ;
struct V_1 T_1 * V_9 ;
int V_16 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 ) {
F_25 ( L_2 ) ;
return - V_194 ;
}
F_71 ( V_6 ) ;
F_72 ( & V_6 -> V_45 ) ;
V_16 = - V_55 ;
if ( ! ( V_217 -> V_84 & V_221 ) ) {
V_217 -> V_83 = V_3 -> V_83 ;
V_217 -> V_208 = V_3 -> V_208 ;
V_217 -> V_207 = V_3 -> V_207 ;
V_217 -> V_210 = V_3 -> V_210 ;
if ( ! F_42 ( V_6 ) ) {
V_217 -> V_218 = F_24 ( V_222 ) ;
V_217 -> V_212 = F_24 ( V_223 ) ;
V_217 -> V_213 = F_24 ( V_224 ) ;
V_217 -> V_219 = F_24 ( V_225 ) ;
V_217 -> V_220 = F_24 ( V_226 ) ;
V_217 -> V_215 = F_24 ( V_227 ) ;
}
} else {
if ( V_217 -> V_208 < - 128 || V_217 -> V_208 > 127 )
goto V_202;
if ( V_217 -> V_207 > 255 )
goto V_202;
if ( V_217 -> V_210 > 1023 )
goto V_202;
V_3 -> V_83 = V_217 -> V_83 ;
V_3 -> V_208 = V_217 -> V_208 ;
V_3 -> V_207 = V_217 -> V_207 ;
V_3 -> V_210 = V_217 -> V_210 ;
V_9 = F_1 ( V_3 ) ;
if ( ! V_9 ) {
V_16 = - V_126 ;
goto V_202;
}
F_83 ( V_3 , V_9 ) ;
F_6 ( V_3 , V_9 ) ;
if ( V_217 -> V_84 & V_228 ) {
if ( F_42 ( V_6 ) )
goto V_202;
if ( V_3 -> V_24 ) {
V_16 = - V_229 ;
goto V_202;
}
V_16 = F_86 ( V_217 ) ;
if ( V_16 )
goto V_202;
F_88 ( V_222 , V_217 -> V_218 ) ;
F_88 ( V_223 , V_217 -> V_212 ) ;
F_88 ( V_224 , V_217 -> V_213 ) ;
F_88 ( V_225 , V_217 -> V_219 ) ;
F_88 ( V_226 , V_217 -> V_220 ) ;
F_88 ( V_227 , V_217 -> V_215 ) ;
}
}
V_3 -> V_85 = ( V_217 -> V_84 & V_230 ) == 0 ;
V_16 = 0 ;
V_202:
F_73 ( & V_6 -> V_45 ) ;
F_74 ( V_6 ) ;
return V_16 ;
}
void F_89 ( struct V_19 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_20 ;
struct V_2 * V_3 ;
struct V_38 * V_10 ;
struct V_1 T_1 * V_9 ;
int V_16 ;
if ( ! F_90 ( V_6 ) )
return;
V_3 = F_91 ( sizeof( * V_3 ) , V_196 ) ;
if ( ! V_3 )
return;
F_72 ( & V_6 -> V_45 ) ;
if ( F_10 ( V_5 -> V_3 ) )
goto V_199;
V_3 -> V_6 = V_6 ;
V_10 = NULL ;
if ( ! F_3 ( V_6 ) )
V_10 = F_92 ( V_6 , V_231 ) ;
if ( V_10 == NULL )
V_10 = F_93 ( V_6 , V_231 ) ;
if ( V_10 == NULL )
goto V_199;
V_3 -> V_10 = V_10 ;
if ( F_3 ( V_6 ) ) {
V_16 = F_94 ( V_10 , V_231 ) ;
if ( V_16 ) {
F_95 ( L_4 ) ;
goto V_232;
}
V_3 -> V_29 = V_10 -> V_11 -> V_233 ;
} else {
V_16 = F_96 ( V_10 , V_231 , V_234 ) ;
if ( V_16 ) {
F_95 ( L_5 ) ;
goto V_232;
}
V_3 -> V_29 = F_5 ( V_10 ) ;
V_16 = F_97 ( V_10 , true ) ;
if ( V_16 ) {
F_95 ( L_6 ) ;
goto V_235;
}
}
V_3 -> V_83 = 0x0101fe ;
V_3 -> V_85 = true ;
V_3 -> V_208 = - 19 ;
V_3 -> V_207 = 75 ;
V_3 -> V_210 = 146 ;
V_9 = F_1 ( V_3 ) ;
if ( ! V_9 )
goto V_235;
F_98 ( V_9 , 0 , sizeof( struct V_1 ) ) ;
F_43 ( V_9 ) ;
F_83 ( V_3 , V_9 ) ;
F_6 ( V_3 , V_9 ) ;
V_5 -> V_3 = V_3 ;
F_73 ( & V_6 -> V_45 ) ;
F_99 ( L_7 ) ;
return;
V_235:
if ( ! F_3 ( V_6 ) )
F_27 ( V_10 ) ;
V_232:
F_28 ( & V_10 -> V_41 ) ;
V_199:
F_73 ( & V_6 -> V_45 ) ;
F_81 ( V_3 ) ;
return;
}
void F_100 ( struct V_19 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_20 ;
if ( ! V_5 -> V_3 )
return;
F_10 ( V_5 -> V_3 -> V_24 ) ;
F_82 ( & V_5 -> V_3 -> V_10 -> V_41 ) ;
F_81 ( V_5 -> V_3 ) ;
}
static struct V_1 T_1 *
F_101 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 -> V_6 ) ;
struct V_7 * V_8 = & V_5 -> V_8 ;
struct V_1 T_1 * V_9 ;
if ( F_3 ( V_3 -> V_6 ) )
V_9 = (struct V_1 T_1 * )
V_3 -> V_10 -> V_11 -> V_12 ;
else
V_9 = F_102 ( V_8 -> V_13 ,
F_5 ( V_3 -> V_10 ) ) ;
return V_9 ;
}
static void F_103 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_9 )
{
if ( ! F_3 ( V_3 -> V_6 ) )
F_104 ( V_9 ) ;
}
struct V_236 *
F_105 ( struct V_19 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_20 ;
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_236 * error ;
struct V_1 T_1 * V_9 ;
if ( ! V_3 || ! V_3 -> V_24 )
return NULL ;
error = F_75 ( sizeof( * error ) , V_237 ) ;
if ( error == NULL )
return NULL ;
error -> V_238 = F_24 ( V_36 ) ;
error -> V_239 = F_24 ( V_46 ) ;
if ( F_3 ( V_3 -> V_6 ) )
error -> V_41 = ( V_240 long ) V_3 -> V_10 -> V_11 -> V_12 ;
else
error -> V_41 = F_5 ( V_3 -> V_10 ) ;
V_9 = F_101 ( V_3 ) ;
if ( ! V_9 )
goto V_241;
F_106 ( & error -> V_9 , V_9 , sizeof( struct V_1 ) ) ;
F_103 ( V_3 , V_9 ) ;
return error ;
V_241:
F_81 ( error ) ;
return NULL ;
}
void
F_107 ( struct V_242 * V_243 ,
struct V_236 * error )
{
F_108 ( V_243 , L_8 ,
error -> V_238 , error -> V_239 ) ;
F_108 ( V_243 , L_9 ,
error -> V_41 ) ;
#define F_109 ( T_3 ) i915_error_printf(m, " " #x ": 0x%08x\n", error->regs.x)
F_109 ( V_140 ) ;
F_109 ( V_244 ) ;
F_109 ( V_146 ) ;
F_109 ( V_147 ) ;
F_109 ( V_245 ) ;
F_109 ( V_246 ) ;
F_109 ( V_152 ) ;
F_109 ( V_247 ) ;
F_109 ( V_248 ) ;
F_109 ( V_249 ) ;
F_109 ( V_250 ) ;
F_109 ( V_134 ) ;
F_109 ( V_135 ) ;
F_109 ( V_149 ) ;
F_109 ( V_150 ) ;
F_109 ( V_151 ) ;
F_109 ( V_79 ) ;
F_109 ( V_80 ) ;
F_109 ( V_209 ) ;
F_109 ( V_211 ) ;
F_109 ( V_95 ) ;
F_109 ( V_96 ) ;
F_109 ( V_251 ) ;
F_109 ( V_252 ) ;
F_109 ( V_253 ) ;
F_109 ( V_131 ) ;
F_109 ( V_153 ) ;
F_109 ( V_254 ) ;
F_109 ( V_255 ) ;
F_109 ( V_256 ) ;
F_109 ( V_257 ) ;
F_109 ( V_258 ) ;
F_109 ( V_259 ) ;
F_109 ( V_260 ) ;
F_109 ( V_261 ) ;
F_109 ( V_262 ) ;
F_109 ( V_263 ) ;
F_109 ( V_264 ) ;
F_109 ( V_265 ) ;
F_109 ( V_266 ) ;
F_109 ( V_81 ) ;
#undef F_109
}
