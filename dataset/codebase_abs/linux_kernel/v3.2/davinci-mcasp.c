static inline void F_1 ( void T_1 * V_1 , T_2 V_2 )
{
F_2 ( F_3 ( V_1 ) | V_2 , V_1 ) ;
}
static inline void F_4 ( void T_1 * V_1 , T_2 V_2 )
{
F_2 ( ( F_3 ( V_1 ) & ~ ( V_2 ) ) , V_1 ) ;
}
static inline void F_5 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
F_2 ( ( F_3 ( V_1 ) & ~ V_3 ) | V_2 , V_1 ) ;
}
static inline void F_6 ( void T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_2 , V_1 ) ;
}
static inline T_2 F_7 ( void T_1 * V_1 )
{
return ( unsigned int ) F_3 ( V_1 ) ;
}
static inline void F_8 ( void T_1 * V_4 , T_2 V_2 )
{
int V_5 = 0 ;
F_1 ( V_4 , V_2 ) ;
for ( V_5 = 0 ; V_5 < 1000 ; V_5 ++ ) {
if ( ( F_7 ( V_4 ) & V_2 ) == V_2 )
break;
}
if ( V_5 == 1000 && ( ( F_7 ( V_4 ) & V_2 ) != V_2 ) )
F_9 ( V_6 L_1 ) ;
}
static void F_10 ( struct V_7 * V_8 )
{
F_8 ( V_8 -> V_9 + V_10 , V_11 ) ;
F_8 ( V_8 -> V_9 + V_10 , V_12 ) ;
F_8 ( V_8 -> V_9 + V_10 , V_13 ) ;
F_6 ( V_8 -> V_9 + V_14 , 0 ) ;
F_8 ( V_8 -> V_9 + V_10 , V_15 ) ;
F_8 ( V_8 -> V_9 + V_10 , V_16 ) ;
F_6 ( V_8 -> V_9 + V_14 , 0 ) ;
F_8 ( V_8 -> V_9 + V_10 , V_15 ) ;
F_8 ( V_8 -> V_9 + V_10 , V_16 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
T_3 V_17 = 0 , V_5 ;
T_2 V_18 ;
F_8 ( V_8 -> V_9 + V_19 , V_20 ) ;
F_8 ( V_8 -> V_9 + V_19 , V_21 ) ;
F_8 ( V_8 -> V_9 + V_19 , V_22 ) ;
F_6 ( V_8 -> V_9 + V_23 , 0 ) ;
F_8 ( V_8 -> V_9 + V_19 , V_24 ) ;
F_8 ( V_8 -> V_9 + V_19 , V_25 ) ;
F_6 ( V_8 -> V_9 + V_23 , 0 ) ;
for ( V_5 = 0 ; V_5 < V_8 -> V_26 ; V_5 ++ ) {
if ( V_8 -> V_27 [ V_5 ] == V_28 ) {
V_17 = V_5 ;
break;
}
}
V_18 = 0 ;
while ( ! ( F_7 ( V_8 -> V_9 + F_12 ( V_17 ) ) &
V_29 ) && ( V_18 < 100000 ) )
V_18 ++ ;
F_6 ( V_8 -> V_9 + V_23 , 0 ) ;
}
static void F_13 ( struct V_7 * V_8 , int V_30 )
{
if ( V_30 == V_31 ) {
if ( V_8 -> V_32 )
F_1 ( V_8 -> V_9 + V_33 ,
V_34 ) ;
F_11 ( V_8 ) ;
} else {
if ( V_8 -> V_35 )
F_1 ( V_8 -> V_9 + V_36 ,
V_34 ) ;
F_10 ( V_8 ) ;
}
}
static void F_14 ( struct V_7 * V_8 )
{
F_6 ( V_8 -> V_9 + V_10 , 0 ) ;
F_6 ( V_8 -> V_9 + V_37 , 0xFFFFFFFF ) ;
}
static void F_15 ( struct V_7 * V_8 )
{
F_6 ( V_8 -> V_9 + V_19 , 0 ) ;
F_6 ( V_8 -> V_9 + V_38 , 0xFFFFFFFF ) ;
}
static void F_16 ( struct V_7 * V_8 , int V_30 )
{
if ( V_30 == V_31 ) {
if ( V_8 -> V_32 )
F_4 ( V_8 -> V_9 + V_33 ,
V_34 ) ;
F_15 ( V_8 ) ;
} else {
if ( V_8 -> V_35 )
F_4 ( V_8 -> V_9 + V_36 ,
V_34 ) ;
F_14 ( V_8 ) ;
}
}
static int F_17 ( struct V_39 * V_40 ,
unsigned int V_41 )
{
struct V_7 * V_8 = F_18 ( V_40 ) ;
void T_1 * V_9 = V_8 -> V_9 ;
switch ( V_41 & V_42 ) {
case V_43 :
F_1 ( V_9 + V_44 , V_45 ) ;
F_1 ( V_9 + V_46 , V_47 ) ;
F_1 ( V_9 + V_48 , V_49 ) ;
F_1 ( V_9 + V_50 , V_51 ) ;
F_1 ( V_9 + V_52 ,
V_53 | V_54 | V_55 ) ;
break;
case V_56 :
F_4 ( V_9 + V_44 , V_45 ) ;
F_1 ( V_9 + V_46 , V_47 ) ;
F_4 ( V_9 + V_48 , V_49 ) ;
F_1 ( V_9 + V_50 , V_51 ) ;
F_4 ( V_9 + V_52 ,
V_53 | V_57 ) ;
F_1 ( V_9 + V_52 ,
V_55 | V_58 ) ;
break;
case V_59 :
F_4 ( V_9 + V_44 , V_45 ) ;
F_4 ( V_9 + V_46 , V_47 ) ;
F_4 ( V_9 + V_48 , V_49 ) ;
F_4 ( V_9 + V_50 , V_51 ) ;
F_4 ( V_9 + V_52 ,
V_53 | V_54 | V_55 | V_57 | V_60 | V_58 ) ;
break;
default:
return - V_61 ;
}
switch ( V_41 & V_62 ) {
case V_63 :
F_4 ( V_9 + V_44 , V_64 ) ;
F_4 ( V_9 + V_46 , V_65 ) ;
F_1 ( V_9 + V_48 , V_66 ) ;
F_4 ( V_9 + V_50 , V_67 ) ;
break;
case V_68 :
F_1 ( V_9 + V_44 , V_64 ) ;
F_1 ( V_9 + V_46 , V_65 ) ;
F_4 ( V_9 + V_48 , V_66 ) ;
F_1 ( V_9 + V_50 , V_67 ) ;
break;
case V_69 :
F_4 ( V_9 + V_44 , V_64 ) ;
F_1 ( V_9 + V_46 , V_65 ) ;
F_1 ( V_9 + V_48 , V_66 ) ;
F_1 ( V_9 + V_50 , V_67 ) ;
break;
case V_70 :
F_1 ( V_9 + V_44 , V_64 ) ;
F_4 ( V_9 + V_46 , V_65 ) ;
F_4 ( V_9 + V_48 , V_66 ) ;
F_4 ( V_9 + V_50 , V_67 ) ;
break;
default:
return - V_61 ;
}
return 0 ;
}
static int F_19 ( struct V_7 * V_8 ,
int V_71 )
{
T_2 V_41 = 0 ;
T_2 V_3 , V_72 ;
switch ( V_71 ) {
case V_73 :
V_41 = 0x03 ;
V_72 = 6 ;
V_3 = 0x000000ff ;
break;
case V_74 :
V_41 = 0x05 ;
V_72 = 5 ;
V_3 = 0x00000fff ;
break;
case V_75 :
V_41 = 0x07 ;
V_72 = 4 ;
V_3 = 0x0000ffff ;
break;
case V_76 :
V_41 = 0x09 ;
V_72 = 3 ;
V_3 = 0x000fffff ;
break;
case V_77 :
V_41 = 0x0B ;
V_72 = 2 ;
V_3 = 0x00ffffff ;
break;
case V_78 :
V_41 = 0x0D ;
V_72 = 1 ;
V_3 = 0x0fffffff ;
break;
case V_79 :
V_41 = 0x0F ;
V_72 = 0 ;
V_3 = 0xffffffff ;
break;
default:
return - V_61 ;
}
F_5 ( V_8 -> V_9 + V_80 ,
F_20 ( V_41 ) , F_20 ( 0x0F ) ) ;
F_5 ( V_8 -> V_9 + V_81 ,
F_21 ( V_41 ) , F_21 ( 0x0F ) ) ;
F_5 ( V_8 -> V_9 + V_81 , F_22 ( V_72 ) ,
F_22 ( 7 ) ) ;
F_5 ( V_8 -> V_9 + V_80 , F_23 ( V_72 ) ,
F_23 ( 7 ) ) ;
F_6 ( V_8 -> V_9 + V_82 , V_3 ) ;
F_6 ( V_8 -> V_9 + V_83 , V_3 ) ;
return 0 ;
}
static void F_24 ( struct V_7 * V_8 , int V_30 )
{
int V_5 ;
T_3 V_84 = 0 ;
T_3 V_85 = 0 ;
F_1 ( V_8 -> V_9 + V_86 , V_87 ) ;
F_6 ( V_8 -> V_9 + V_88 , 0x00000000 ) ;
if ( V_30 == V_31 ) {
F_6 ( V_8 -> V_9 + V_38 , 0xFFFFFFFF ) ;
F_4 ( V_8 -> V_9 + V_89 ,
V_90 ) ;
} else {
F_6 ( V_8 -> V_9 + V_37 , 0xFFFFFFFF ) ;
F_4 ( V_8 -> V_9 + V_91 ,
V_92 ) ;
}
for ( V_5 = 0 ; V_5 < V_8 -> V_26 ; V_5 ++ ) {
F_1 ( V_8 -> V_9 + F_12 ( V_5 ) ,
V_8 -> V_27 [ V_5 ] ) ;
if ( V_8 -> V_27 [ V_5 ] == V_28 ) {
F_1 ( V_8 -> V_9 + V_52 ,
F_25 ( V_5 ) ) ;
V_84 ++ ;
} else if ( V_8 -> V_27 [ V_5 ] == V_93 ) {
F_4 ( V_8 -> V_9 + V_52 ,
F_25 ( V_5 ) ) ;
V_85 ++ ;
}
}
if ( V_8 -> V_32 && V_30 == V_31 ) {
if ( V_8 -> V_32 * V_84 > 64 )
V_8 -> V_32 = 1 ;
F_5 ( V_8 -> V_9 + V_33 , V_84 ,
V_94 ) ;
F_5 ( V_8 -> V_9 + V_33 ,
( ( V_8 -> V_32 * V_84 ) << 8 ) , V_95 ) ;
}
if ( V_8 -> V_35 && V_30 == V_96 ) {
if ( V_8 -> V_35 * V_85 > 64 )
V_8 -> V_35 = 1 ;
F_5 ( V_8 -> V_9 + V_36 , V_85 ,
V_94 ) ;
F_5 ( V_8 -> V_9 + V_36 ,
( ( V_8 -> V_35 * V_85 ) << 8 ) , V_95 ) ;
}
}
static void F_26 ( struct V_7 * V_8 , int V_30 )
{
int V_5 , V_97 ;
T_2 V_3 = 0 ;
V_97 = ( V_8 -> V_98 > 31 ) ? 32 : V_8 -> V_98 ;
for ( V_5 = 0 ; V_5 < V_97 ; V_5 ++ )
V_3 |= ( 1 << V_5 ) ;
F_4 ( V_8 -> V_9 + V_44 , V_99 ) ;
if ( V_30 == V_31 ) {
F_1 ( V_8 -> V_9 + V_100 ,
V_101 ) ;
F_6 ( V_8 -> V_9 + V_102 , V_3 ) ;
F_1 ( V_8 -> V_9 + V_81 , V_103 ) ;
if ( ( V_8 -> V_98 >= 2 ) && ( V_8 -> V_98 <= 32 ) )
F_5 ( V_8 -> V_9 + V_46 ,
F_27 ( V_8 -> V_98 ) , F_27 ( 0x1FF ) ) ;
else
F_9 ( V_6 L_2 ,
V_8 -> V_98 ) ;
F_4 ( V_8 -> V_9 + V_46 , V_104 ) ;
} else {
F_1 ( V_8 -> V_9 + V_80 , V_105 ) ;
F_1 ( V_8 -> V_9 + V_106 ,
V_107 ) ;
F_6 ( V_8 -> V_9 + V_108 , V_3 ) ;
if ( ( V_8 -> V_98 >= 2 ) && ( V_8 -> V_98 <= 32 ) )
F_5 ( V_8 -> V_9 + V_50 ,
F_28 ( V_8 -> V_98 ) , F_28 ( 0x1FF ) ) ;
else
F_9 ( V_6 L_3 ,
V_8 -> V_98 ) ;
F_4 ( V_8 -> V_9 + V_50 , V_109 ) ;
}
}
static void F_29 ( struct V_7 * V_8 )
{
F_1 ( V_8 -> V_9 + V_52 , V_55 ) ;
F_6 ( V_8 -> V_9 + V_82 , 0x00FFFFFF ) ;
F_1 ( V_8 -> V_9 + V_81 ,
F_22 ( 6 ) | F_21 ( 15 ) ) ;
F_6 ( V_8 -> V_9 + V_46 ,
V_47 | F_27 ( 0x180 ) ) ;
F_6 ( V_8 -> V_9 + V_102 , 0xFFFFFFFF ) ;
F_1 ( V_8 -> V_9 + V_44 ,
V_45 | V_99 ) ;
F_4 ( V_8 -> V_9 + V_89 , V_90 ) ;
F_1 ( V_8 -> V_9 + V_100 , F_30 ( 3 ) ) ;
F_1 ( V_8 -> V_9 + V_110 , V_111 ) ;
}
static int F_31 ( struct V_112 * V_113 ,
struct V_114 * V_115 ,
struct V_39 * V_40 )
{
struct V_7 * V_8 = F_18 ( V_40 ) ;
struct V_116 * V_117 =
& V_8 -> V_117 [ V_113 -> V_30 ] ;
int V_118 ;
T_3 V_119 ;
F_24 ( V_8 , V_113 -> V_30 ) ;
if ( V_113 -> V_30 == V_31 )
V_119 = V_8 -> V_32 ;
else
V_119 = V_8 -> V_35 ;
if ( V_8 -> V_120 == V_121 )
F_29 ( V_8 ) ;
else
F_26 ( V_8 , V_113 -> V_30 ) ;
switch ( F_32 ( V_115 ) ) {
case V_122 :
case V_123 :
V_117 -> V_124 = 1 ;
V_118 = V_73 ;
break;
case V_125 :
case V_126 :
V_117 -> V_124 = 2 ;
V_118 = V_75 ;
break;
case V_127 :
case V_128 :
V_117 -> V_124 = 4 ;
V_118 = V_79 ;
break;
default:
F_9 ( V_129 L_4 ) ;
return - V_61 ;
}
if ( V_8 -> V_130 == V_131 && ! V_119 )
V_117 -> V_132 = 4 ;
else
V_117 -> V_132 = V_117 -> V_124 ;
V_117 -> V_119 = V_119 ;
F_19 ( V_8 , V_118 ) ;
return 0 ;
}
static int F_33 ( struct V_112 * V_113 ,
int V_133 , struct V_39 * V_40 )
{
struct V_7 * V_8 = F_18 ( V_40 ) ;
int V_134 = 0 ;
switch ( V_133 ) {
case V_135 :
case V_136 :
case V_137 :
if ( ! V_8 -> V_138 ) {
F_34 ( V_8 -> V_139 ) ;
V_8 -> V_138 = 1 ;
}
F_13 ( V_8 , V_113 -> V_30 ) ;
break;
case V_140 :
F_16 ( V_8 , V_113 -> V_30 ) ;
if ( V_8 -> V_138 ) {
F_35 ( V_8 -> V_139 ) ;
V_8 -> V_138 = 0 ;
}
break;
case V_141 :
case V_142 :
F_16 ( V_8 , V_113 -> V_30 ) ;
break;
default:
V_134 = - V_61 ;
}
return V_134 ;
}
static int F_36 ( struct V_112 * V_113 ,
struct V_39 * V_143 )
{
struct V_7 * V_8 = F_18 ( V_143 ) ;
F_37 ( V_143 , V_113 , V_8 -> V_117 ) ;
return 0 ;
}
static int F_38 ( struct V_144 * V_145 )
{
struct V_116 * V_146 ;
struct V_147 * V_148 , * V_149 , * V_150 ;
struct V_151 * V_152 ;
struct V_7 * V_8 ;
int V_134 = 0 ;
V_8 = F_39 ( sizeof( struct V_7 ) , V_153 ) ;
if ( ! V_8 )
return - V_154 ;
V_148 = F_40 ( V_145 , V_155 , 0 ) ;
if ( ! V_148 ) {
F_41 ( & V_145 -> V_8 , L_5 ) ;
V_134 = - V_156 ;
goto V_157;
}
V_149 = F_42 ( V_148 -> V_158 ,
F_43 ( V_148 ) , V_145 -> V_159 ) ;
if ( ! V_149 ) {
F_41 ( & V_145 -> V_8 , L_6 ) ;
V_134 = - V_160 ;
goto V_157;
}
V_152 = V_145 -> V_8 . V_161 ;
V_8 -> V_139 = F_44 ( & V_145 -> V_8 , NULL ) ;
if ( F_45 ( V_8 -> V_139 ) ) {
V_134 = - V_156 ;
goto V_162;
}
F_34 ( V_8 -> V_139 ) ;
V_8 -> V_138 = 1 ;
V_8 -> V_9 = F_46 ( V_148 -> V_158 , F_43 ( V_148 ) ) ;
if ( ! V_8 -> V_9 ) {
F_41 ( & V_145 -> V_8 , L_7 ) ;
V_134 = - V_154 ;
goto V_163;
}
V_8 -> V_120 = V_152 -> V_120 ;
V_8 -> V_98 = V_152 -> V_98 ;
V_8 -> V_26 = V_152 -> V_26 ;
V_8 -> V_27 = V_152 -> V_27 ;
V_8 -> V_164 = V_152 -> V_164 ;
V_8 -> V_130 = V_152 -> V_130 ;
V_8 -> V_32 = V_152 -> V_32 ;
V_8 -> V_35 = V_152 -> V_35 ;
V_146 = & V_8 -> V_117 [ V_31 ] ;
V_146 -> V_165 = V_152 -> V_165 ;
V_146 -> V_166 = V_152 -> V_166 ;
V_146 -> V_167 = V_152 -> V_168 ;
V_146 -> V_169 = ( V_170 ) ( V_152 -> V_171 +
V_148 -> V_158 ) ;
V_150 = F_40 ( V_145 , V_172 , 0 ) ;
if ( ! V_150 ) {
F_41 ( & V_145 -> V_8 , L_8 ) ;
V_134 = - V_156 ;
goto V_173;
}
V_146 -> V_174 = V_150 -> V_158 ;
V_146 = & V_8 -> V_117 [ V_96 ] ;
V_146 -> V_165 = V_152 -> V_165 ;
V_146 -> V_166 = V_152 -> V_166 ;
V_146 -> V_167 = V_152 -> V_175 ;
V_146 -> V_169 = ( V_170 ) ( V_152 -> V_176 +
V_148 -> V_158 ) ;
V_150 = F_40 ( V_145 , V_172 , 1 ) ;
if ( ! V_150 ) {
F_41 ( & V_145 -> V_8 , L_8 ) ;
V_134 = - V_156 ;
goto V_173;
}
V_146 -> V_174 = V_150 -> V_158 ;
F_47 ( & V_145 -> V_8 , V_8 ) ;
V_134 = F_48 ( & V_145 -> V_8 , & V_177 [ V_152 -> V_120 ] ) ;
if ( V_134 != 0 )
goto V_173;
return 0 ;
V_173:
F_49 ( V_8 -> V_9 ) ;
V_163:
F_35 ( V_8 -> V_139 ) ;
F_50 ( V_8 -> V_139 ) ;
V_162:
F_51 ( V_148 -> V_158 , F_43 ( V_148 ) ) ;
V_157:
F_52 ( V_8 ) ;
return V_134 ;
}
static int F_53 ( struct V_144 * V_145 )
{
struct V_7 * V_8 = F_54 ( & V_145 -> V_8 ) ;
struct V_147 * V_148 ;
F_55 ( & V_145 -> V_8 ) ;
F_35 ( V_8 -> V_139 ) ;
F_50 ( V_8 -> V_139 ) ;
V_8 -> V_139 = NULL ;
V_148 = F_40 ( V_145 , V_155 , 0 ) ;
F_51 ( V_148 -> V_158 , F_43 ( V_148 ) ) ;
F_52 ( V_8 ) ;
return 0 ;
}
static int T_4 F_56 ( void )
{
return F_57 ( & V_178 ) ;
}
static void T_5 F_58 ( void )
{
F_59 ( & V_178 ) ;
}
