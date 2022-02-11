static inline T_1 F_1 ( void T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
return F_2 ( V_1 + ( V_2 << V_3 ) ) ;
}
static inline void F_3 ( void T_2 * V_1 , T_1 V_2 , T_1 V_3 , T_1 V_4 )
{
F_4 ( V_4 , V_1 + ( V_2 << V_3 ) ) ;
}
static inline T_1 F_5 ( struct V_5 * V_6 , T_1 V_2 )
{
struct V_7 * V_8 = F_6 ( V_6 -> V_9 ) ;
return F_1 ( V_6 -> V_10 , V_2 & V_8 -> V_11 ,
V_6 -> V_12 ) ;
}
static inline void F_7 ( struct V_5 * V_6 , T_1 V_2 , T_1 V_4 )
{
struct V_7 * V_8 = F_6 ( V_6 -> V_9 ) ;
F_3 ( V_6 -> V_10 , V_2 & V_8 -> V_11 , V_6 -> V_12 , V_4 ) ;
}
static inline T_1 F_8 ( struct V_5 * V_6 , T_1 V_2 )
{
return F_5 ( V_6 , ( V_6 -> line << 3 ) + V_2 ) ;
}
static inline void F_9 ( struct V_5 * V_6 , T_1 V_2 , T_1 V_4 )
{
F_7 ( V_6 , ( V_6 -> line << 3 ) + V_2 , V_4 ) ;
}
static int F_10 ( int V_13 , int V_14 , int * V_15 )
{
int V_16 = abs ( V_13 - V_14 ) ;
if ( ( * V_15 < 0 ) || ( * V_15 > V_16 ) ) {
* V_15 = V_16 ;
return 0 ;
}
return 1 ;
}
static int F_11 ( struct V_5 * V_6 , int V_17 )
{
struct V_7 * V_8 = F_6 ( V_6 -> V_9 ) ;
int V_18 , V_19 , V_20 = V_17 , V_15 = - 1 ;
T_1 V_21 , V_22 = 0 , V_23 = 0 , V_24 = 0 ;
for ( V_21 = 0 ; V_25 [ V_21 ] . V_17 && V_15 ; V_21 ++ ) {
if ( V_25 [ V_21 ] . V_24 && ! ( V_8 -> V_26 & V_27 ) )
continue;
V_18 = F_12 ( V_8 -> V_28 , V_25 [ V_21 ] . V_17 ) ;
V_19 = F_12 ( V_6 -> V_29 , V_18 ) ;
if ( ! F_10 ( V_17 , V_19 , & V_15 ) ) {
V_22 = V_25 [ V_21 ] . V_22 ;
V_23 = V_25 [ V_21 ] . V_23 ;
V_24 = V_25 [ V_21 ] . V_24 ;
V_20 = V_19 ;
}
}
if ( V_8 -> V_26 & V_27 ) {
V_24 |= V_30 | V_31 ;
F_9 ( V_6 , V_32 , V_33 ) ;
F_9 ( V_6 , V_34 , V_24 ) ;
}
F_9 ( V_6 , V_35 , V_22 | V_36 ) ;
F_9 ( V_6 , V_37 , ( V_23 << 4 ) | V_23 ) ;
if ( V_17 != V_20 )
F_13 ( V_6 -> V_9 , L_1 ,
V_17 , V_20 ) ;
return V_20 ;
}
static void F_14 ( struct V_5 * V_6 , int V_38 )
{
struct V_7 * V_8 = F_6 ( V_6 -> V_9 ) ;
V_8 -> V_39 |= V_38 << ( V_6 -> line * 4 ) ;
F_7 ( V_6 , V_40 , V_8 -> V_39 ) ;
}
static void F_15 ( struct V_5 * V_6 , int V_38 )
{
struct V_7 * V_8 = F_6 ( V_6 -> V_9 ) ;
V_8 -> V_39 &= ~ ( V_38 << ( V_6 -> line * 4 ) ) ;
F_7 ( V_6 , V_40 , V_8 -> V_39 ) ;
}
static void F_16 ( struct V_5 * V_6 , int V_41 , int V_42 )
{
T_1 V_43 ;
struct V_7 * V_8 = F_6 ( V_6 -> V_9 ) ;
if ( V_8 -> V_44 . V_45 [ V_6 -> line ] & F_17 ( V_41 ) ) {
V_43 = 1 << F_18 ( V_8 -> V_44 . V_45 [ V_6 -> line ] , V_41 ) ;
if ( V_42 )
F_7 ( V_6 , V_46 , V_43 ) ;
else
F_7 ( V_6 , V_47 , V_43 ) ;
}
}
static void F_19 ( struct V_5 * V_6 )
{
T_1 V_48 ;
unsigned int V_49 , V_50 ;
struct V_51 * V_52 = F_20 ( & V_6 -> V_42 -> V_6 ) ;
if ( ! V_52 )
return;
for (; ; ) {
V_48 = F_8 ( V_6 , V_53 ) ;
if ( ! ( V_48 & V_54 ) )
break;
V_48 &= V_55 | V_56 | V_57 | V_58 ;
V_49 = F_8 ( V_6 , V_59 ) ;
V_6 -> V_60 . V_61 ++ ;
V_50 = V_62 ;
if ( F_21 ( V_48 ) ) {
if ( V_48 & V_58 ) {
V_6 -> V_60 . V_63 ++ ;
if ( F_22 ( V_6 ) )
continue;
} else if ( V_48 & V_55 )
V_6 -> V_60 . V_64 ++ ;
else if ( V_48 & V_56 )
V_6 -> V_60 . V_65 ++ ;
else if ( V_48 & V_57 )
V_6 -> V_60 . V_66 ++ ;
V_48 &= V_6 -> V_67 ;
if ( V_48 & V_58 )
V_50 = V_68 ;
else if ( V_48 & V_55 )
V_50 = V_69 ;
else if ( V_48 & V_56 )
V_50 = V_70 ;
else if ( V_48 & V_57 )
V_50 = V_71 ;
}
if ( F_23 ( V_6 , V_49 ) )
continue;
if ( V_48 & V_6 -> V_72 )
continue;
F_24 ( V_6 , V_48 , V_57 , V_49 , V_50 ) ;
}
F_25 ( V_52 ) ;
F_26 ( V_52 ) ;
}
static void F_27 ( struct V_5 * V_6 )
{
T_1 V_48 ;
struct V_73 * V_74 = & V_6 -> V_42 -> V_74 ;
struct V_7 * V_8 = F_6 ( V_6 -> V_9 ) ;
if ( F_21 ( V_6 -> V_75 ) ) {
F_9 ( V_6 , V_76 , V_6 -> V_75 ) ;
V_6 -> V_60 . V_77 ++ ;
V_6 -> V_75 = 0 ;
return;
}
if ( F_28 ( V_74 ) || F_29 ( V_6 ) ) {
if ( F_8 ( V_6 , V_53 ) & V_78 ) {
F_15 ( V_6 , V_79 ) ;
if ( V_8 -> V_26 & V_80 )
F_16 ( V_6 , V_81 , 0 ) ;
}
return;
}
while ( ! F_28 ( V_74 ) ) {
V_48 = F_8 ( V_6 , V_53 ) ;
if ( ! ( V_48 & V_82 ) )
break;
F_9 ( V_6 , V_76 , V_74 -> V_83 [ V_74 -> V_84 ] ) ;
V_74 -> V_84 = ( V_74 -> V_84 + 1 ) & ( V_85 - 1 ) ;
V_6 -> V_60 . V_77 ++ ;
}
if ( F_30 ( V_74 ) < V_86 )
F_31 ( V_6 ) ;
}
static T_3 F_32 ( int V_87 , void * V_88 )
{
int V_21 ;
T_1 V_89 ;
struct V_7 * V_8 = (struct V_7 * ) V_88 ;
F_33 ( & V_8 -> V_90 ) ;
for (; ; ) {
V_89 = F_5 ( & V_8 -> V_6 [ 0 ] , V_91 ) ;
V_89 &= V_8 -> V_39 ;
if ( ! V_89 )
break;
F_13 ( V_8 -> V_6 [ 0 ] . V_9 , L_2 , V_89 ) ;
for ( V_21 = 0 ; V_21 < V_8 -> V_92 . V_93 ; V_21 ++ ) {
if ( V_89 & F_34 ( V_21 ) )
F_19 ( & V_8 -> V_6 [ V_21 ] ) ;
if ( V_89 & F_35 ( V_21 ) )
F_27 ( & V_8 -> V_6 [ V_21 ] ) ;
}
}
F_36 ( & V_8 -> V_90 ) ;
return V_94 ;
}
static void F_37 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 -> V_9 ) ;
F_33 ( & V_8 -> V_90 ) ;
if ( V_8 -> V_26 & V_80 )
F_16 ( V_6 , V_81 , 1 ) ;
F_14 ( V_6 , V_79 ) ;
F_36 ( & V_8 -> V_90 ) ;
}
static void F_38 ( struct V_5 * V_6 )
{
}
static void F_39 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 -> V_9 ) ;
F_33 ( & V_8 -> V_90 ) ;
F_9 ( V_6 , V_32 , V_95 ) ;
F_36 ( & V_8 -> V_90 ) ;
}
static unsigned int F_40 ( struct V_5 * V_6 )
{
T_1 V_96 ;
struct V_7 * V_8 = F_6 ( V_6 -> V_9 ) ;
F_33 ( & V_8 -> V_90 ) ;
V_96 = F_8 ( V_6 , V_53 ) ;
F_36 ( & V_8 -> V_90 ) ;
return ( V_96 & V_78 ) ? V_97 : 0 ;
}
static void F_41 ( struct V_5 * V_6 )
{
}
static void F_42 ( struct V_5 * V_6 , unsigned int V_98 )
{
struct V_7 * V_8 = F_6 ( V_6 -> V_9 ) ;
if ( ! ( V_8 -> V_26 & V_80 ) )
return;
F_33 ( & V_8 -> V_90 ) ;
F_16 ( V_6 , V_99 , V_98 & V_100 ) ;
F_16 ( V_6 , V_101 , V_98 & V_102 ) ;
F_36 ( & V_8 -> V_90 ) ;
}
static unsigned int F_43 ( struct V_5 * V_6 )
{
T_1 V_43 , V_103 ;
struct V_7 * V_8 = F_6 ( V_6 -> V_9 ) ;
unsigned int V_98 = V_104 | V_105 | V_106 ;
if ( ! ( V_8 -> V_26 & V_80 ) )
return V_98 ;
F_33 ( & V_8 -> V_90 ) ;
V_103 = ~ F_5 ( V_6 , V_107 ) ;
if ( V_8 -> V_44 . V_45 [ V_6 -> line ] & F_17 ( V_108 ) ) {
V_43 = 1 << F_44 ( V_8 -> V_44 . V_45 [ V_6 -> line ] ,
V_108 ) ;
V_98 &= ~ V_104 ;
V_98 |= ( V_103 & V_43 ) ? V_104 : 0 ;
}
if ( V_8 -> V_44 . V_45 [ V_6 -> line ] & F_17 ( V_109 ) ) {
V_43 = 1 << F_44 ( V_8 -> V_44 . V_45 [ V_6 -> line ] ,
V_109 ) ;
V_98 &= ~ V_105 ;
V_98 |= ( V_103 & V_43 ) ? V_105 : 0 ;
}
if ( V_8 -> V_44 . V_45 [ V_6 -> line ] & F_17 ( V_110 ) ) {
V_43 = 1 << F_44 ( V_8 -> V_44 . V_45 [ V_6 -> line ] ,
V_110 ) ;
V_98 &= ~ V_106 ;
V_98 |= ( V_103 & V_43 ) ? V_106 : 0 ;
}
if ( V_8 -> V_44 . V_45 [ V_6 -> line ] & F_17 ( V_111 ) ) {
V_43 = 1 << F_44 ( V_8 -> V_44 . V_45 [ V_6 -> line ] ,
V_111 ) ;
V_98 &= ~ V_112 ;
V_98 |= ( V_103 & V_43 ) ? V_112 : 0 ;
}
F_36 ( & V_8 -> V_90 ) ;
return V_98 ;
}
static void F_45 ( struct V_5 * V_6 , int V_113 )
{
struct V_7 * V_8 = F_6 ( V_6 -> V_9 ) ;
F_33 ( & V_8 -> V_90 ) ;
F_9 ( V_6 , V_32 , V_113 ?
V_114 : V_115 ) ;
F_36 ( & V_8 -> V_90 ) ;
}
static void F_46 ( struct V_5 * V_6 ,
struct V_116 * V_117 , struct V_116 * V_118 )
{
struct V_7 * V_8 = F_6 ( V_6 -> V_9 ) ;
T_1 V_119 , V_120 ;
int V_17 ;
F_33 ( & V_8 -> V_90 ) ;
V_117 -> V_121 &= ~ V_122 ;
F_9 ( V_6 , V_32 , V_123 |
V_95 | V_124 ) ;
F_9 ( V_6 , V_32 , V_125 ) ;
F_9 ( V_6 , V_32 , V_126 ) ;
F_9 ( V_6 , V_32 , V_127 ) ;
switch ( V_117 -> V_121 & V_128 ) {
case V_129 :
V_119 = V_130 ;
break;
case V_131 :
V_119 = V_132 ;
break;
case V_133 :
V_119 = V_134 ;
break;
case V_135 :
default:
V_119 = V_136 ;
break;
}
if ( V_117 -> V_121 & V_137 ) {
if ( V_117 -> V_121 & V_138 )
V_119 |= V_139 ;
} else
V_119 |= V_140 ;
V_120 = ( V_117 -> V_121 & V_141 ) ? V_142 : V_143 ;
F_9 ( V_6 , V_32 , V_144 ) ;
F_9 ( V_6 , V_34 , V_119 ) ;
F_9 ( V_6 , V_34 , V_120 ) ;
V_6 -> V_67 = V_57 ;
if ( V_117 -> V_145 & V_146 )
V_6 -> V_67 |= V_55 | V_56 ;
if ( V_117 -> V_145 & ( V_147 | V_148 ) )
V_6 -> V_67 |= V_58 ;
V_6 -> V_72 = 0 ;
if ( V_117 -> V_145 & V_149 )
V_6 -> V_72 |= V_58 ;
if ( ! ( V_117 -> V_121 & V_150 ) )
V_6 -> V_72 |= V_55 | V_57 | V_56 | V_58 ;
V_17 = F_47 ( V_6 , V_117 , V_118 , 50 ,
( V_8 -> V_26 & V_27 ) ?
230400 : 38400 ) ;
V_17 = F_11 ( V_6 , V_17 ) ;
F_48 ( V_6 , V_117 -> V_121 , V_17 ) ;
if ( F_49 ( V_117 ) )
F_50 ( V_117 , V_17 , V_17 ) ;
F_9 ( V_6 , V_32 , V_151 | V_152 ) ;
F_36 ( & V_8 -> V_90 ) ;
}
static int F_51 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 -> V_9 ) ;
F_33 ( & V_8 -> V_90 ) ;
if ( V_8 -> V_26 & V_80 ) {
F_7 ( V_6 , V_153 , 0 ) ;
}
F_9 ( V_6 , V_32 , V_123 ) ;
F_9 ( V_6 , V_32 , V_125 ) ;
F_9 ( V_6 , V_32 , V_126 ) ;
F_9 ( V_6 , V_32 , V_127 ) ;
F_9 ( V_6 , V_32 , V_151 | V_152 ) ;
F_14 ( V_6 , V_154 ) ;
F_36 ( & V_8 -> V_90 ) ;
return 0 ;
}
static void F_52 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 -> V_9 ) ;
F_33 ( & V_8 -> V_90 ) ;
F_15 ( V_6 , V_79 | V_154 ) ;
F_9 ( V_6 , V_32 , V_95 | V_124 ) ;
if ( V_8 -> V_26 & V_80 )
F_16 ( V_6 , V_81 , 0 ) ;
F_36 ( & V_8 -> V_90 ) ;
}
static const char * F_53 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 -> V_9 ) ;
return ( V_6 -> type == V_155 ) ? V_8 -> V_156 : NULL ;
}
static void F_54 ( struct V_5 * V_6 )
{
}
static int F_55 ( struct V_5 * V_6 )
{
return 0 ;
}
static void F_56 ( struct V_5 * V_6 , int V_26 )
{
if ( V_26 & V_157 )
V_6 -> type = V_155 ;
}
static int F_57 ( struct V_5 * V_6 , struct V_158 * V_8 )
{
if ( ( V_8 -> type == V_159 ) || ( V_8 -> type == V_155 ) )
return 0 ;
if ( V_8 -> V_87 == V_6 -> V_87 )
return 0 ;
return - V_160 ;
}
static void F_58 ( struct V_5 * V_6 , int V_161 )
{
int V_162 = 100000 ;
while ( V_162 -- ) {
if ( F_8 ( V_6 , V_53 ) & V_82 ) {
F_9 ( V_6 , V_76 , V_161 ) ;
break;
}
F_59 () ;
}
}
static void F_60 ( struct V_163 * V_164 , const char * V_161 , unsigned V_165 )
{
struct V_7 * V_8 = (struct V_7 * ) V_164 -> V_166 ;
struct V_5 * V_6 = & V_8 -> V_6 [ V_164 -> V_167 ] ;
F_33 ( & V_8 -> V_90 ) ;
F_61 ( V_6 , V_161 , V_165 , F_58 ) ;
F_36 ( & V_8 -> V_90 ) ;
}
static int F_62 ( struct V_163 * V_164 , char * V_168 )
{
struct V_7 * V_8 = (struct V_7 * ) V_164 -> V_166 ;
struct V_5 * V_6 = & V_8 -> V_6 [ ( V_164 -> V_167 > 0 ) ? V_164 -> V_167 : 0 ] ;
int V_17 = 9600 , V_169 = 8 , V_64 = 'n' , V_170 = 'n' ;
if ( V_168 )
F_63 ( V_168 , & V_17 , & V_64 , & V_169 , & V_170 ) ;
return F_64 ( V_6 , V_164 , V_17 , V_64 , V_169 , V_170 ) ;
}
static int F_65 ( struct V_171 * V_172 )
{
struct V_173 * V_174 = F_66 ( V_172 , V_175 , 0 ) ;
int V_176 = V_172 -> V_177 -> V_178 ;
struct V_179 * V_44 = F_67 ( & V_172 -> V_9 ) ;
int V_21 , V_180 , V_181 , V_182 , V_183 ;
struct V_7 * V_8 ;
void T_2 * V_10 ;
if ( ! V_174 ) {
F_68 ( & V_172 -> V_9 , L_3 ) ;
return - V_184 ;
}
F_69 ( & V_172 -> V_9 , V_185 ) ;
V_8 = F_70 ( & V_172 -> V_9 , sizeof( struct V_7 ) , V_186 ) ;
if ( ! V_8 ) {
F_68 ( & V_172 -> V_9 , L_4 ) ;
return - V_187 ;
}
F_71 ( V_172 , V_8 ) ;
F_72 ( & V_8 -> V_90 ) ;
switch ( V_176 ) {
case V_188 :
V_8 -> V_156 = L_5 ;
V_8 -> V_92 . V_93 = 2 ;
V_8 -> V_28 = 3686400 ;
V_8 -> V_11 = 0x0f ;
V_8 -> V_26 = V_80 ;
V_181 = 3 ;
V_182 = 1000000 ;
V_183 = 4000000 ;
break;
case V_189 :
V_8 -> V_156 = L_6 ;
V_8 -> V_92 . V_93 = 1 ;
V_8 -> V_28 = 3686400 ;
V_8 -> V_11 = 0x07 ;
V_8 -> V_26 = 0 ;
V_181 = 3 ;
V_182 = 1000000 ;
V_183 = 4000000 ;
break;
case V_190 :
V_8 -> V_156 = L_7 ;
V_8 -> V_92 . V_93 = 2 ;
V_8 -> V_28 = 3686400 ;
V_8 -> V_11 = 0x0f ;
V_8 -> V_26 = V_80 ;
V_181 = 3 ;
V_182 = 1000000 ;
V_183 = 4000000 ;
break;
case V_191 :
V_8 -> V_156 = L_8 ;
V_8 -> V_92 . V_93 = 1 ;
V_8 -> V_28 = 3686400 ;
V_8 -> V_11 = 0x0f ;
V_8 -> V_26 = V_80 | V_27 ;
V_181 = 16 ;
V_182 = 100000 ;
V_183 = 8000000 ;
break;
case V_192 :
V_8 -> V_156 = L_9 ;
V_8 -> V_92 . V_93 = 2 ;
V_8 -> V_28 = 3686400 ;
V_8 -> V_11 = 0x0f ;
V_8 -> V_26 = V_80 | V_27 ;
V_181 = 16 ;
V_182 = 100000 ;
V_183 = 8000000 ;
break;
case V_193 :
V_8 -> V_156 = L_10 ;
V_8 -> V_92 . V_93 = 2 ;
V_8 -> V_28 = 14745600 ;
V_8 -> V_11 = 0x7f ;
V_8 -> V_26 = V_80 | V_27 ;
V_181 = 256 ;
V_182 = 1000000 ;
V_183 = 50000000 ;
break;
case V_194 :
V_8 -> V_156 = L_11 ;
V_8 -> V_92 . V_93 = 2 ;
V_8 -> V_28 = 3686400 ;
V_8 -> V_11 = 0x0f ;
V_8 -> V_26 = V_80 ;
V_181 = 3 ;
V_182 = 1000000 ;
V_183 = 4000000 ;
break;
case V_195 :
V_8 -> V_156 = L_12 ;
V_8 -> V_92 . V_93 = 2 ;
V_8 -> V_28 = 3686400 ;
V_8 -> V_11 = 0x0f ;
V_8 -> V_26 = V_80 ;
V_181 = 3 ;
V_182 = 1000000 ;
V_183 = 4000000 ;
break;
default:
F_68 ( & V_172 -> V_9 , L_13 , V_176 ) ;
V_180 = - V_196 ;
goto V_197;
}
if ( ! V_44 ) {
F_73 ( & V_172 -> V_9 ,
L_14 ) ;
V_8 -> V_44 . V_198 = V_8 -> V_28 ;
} else
memcpy ( & V_8 -> V_44 , V_44 , sizeof( struct V_179 ) ) ;
V_8 -> V_87 = F_74 ( V_172 , 0 ) ;
if ( V_8 -> V_87 <= 0 ) {
F_68 ( & V_172 -> V_9 , L_15 ) ;
V_180 = - V_199 ;
goto V_197;
}
if ( ( V_8 -> V_44 . V_198 < V_182 ) ||
( V_8 -> V_44 . V_198 > V_183 ) ) {
F_68 ( & V_172 -> V_9 , L_16 ) ;
V_180 = - V_160 ;
goto V_197;
}
V_10 = F_75 ( & V_172 -> V_9 , V_174 ) ;
if ( ! V_10 ) {
F_68 ( & V_172 -> V_9 , L_17 ) ;
V_180 = - V_200 ;
goto V_197;
}
V_8 -> V_92 . V_201 = V_202 ;
V_8 -> V_92 . V_203 = L_18 ;
V_8 -> V_92 . V_204 = V_205 ;
V_8 -> V_92 . V_206 = V_207 ;
#ifdef F_76
V_8 -> V_92 . V_208 = & V_8 -> V_163 ;
V_8 -> V_92 . V_208 -> V_209 = V_210 ;
V_8 -> V_92 . V_208 -> V_211 = F_60 ;
V_8 -> V_92 . V_208 -> V_212 = F_62 ;
V_8 -> V_92 . V_208 -> V_26 = V_213 ;
V_8 -> V_92 . V_208 -> V_167 = - 1 ;
V_8 -> V_92 . V_208 -> V_166 = V_8 ;
strcpy ( V_8 -> V_92 . V_208 -> V_156 , L_18 ) ;
#endif
V_180 = F_77 ( & V_8 -> V_92 ) ;
if ( V_180 ) {
F_68 ( & V_172 -> V_9 , L_19 ) ;
goto V_197;
}
for ( V_21 = 0 ; V_21 < V_8 -> V_92 . V_93 ; V_21 ++ ) {
V_8 -> V_6 [ V_21 ] . line = V_21 ;
V_8 -> V_6 [ V_21 ] . V_9 = & V_172 -> V_9 ;
V_8 -> V_6 [ V_21 ] . V_87 = V_8 -> V_87 ;
V_8 -> V_6 [ V_21 ] . type = V_155 ;
V_8 -> V_6 [ V_21 ] . V_181 = V_181 ;
V_8 -> V_6 [ V_21 ] . V_26 = V_214 | V_215 ;
V_8 -> V_6 [ V_21 ] . V_216 = V_217 ;
V_8 -> V_6 [ V_21 ] . V_218 = V_174 -> V_219 ;
V_8 -> V_6 [ V_21 ] . V_10 = V_10 ;
V_8 -> V_6 [ V_21 ] . V_12 = V_8 -> V_44 . V_220 ;
V_8 -> V_6 [ V_21 ] . V_29 = V_8 -> V_44 . V_198 ;
V_8 -> V_6 [ V_21 ] . V_221 = & V_222 ;
F_78 ( & V_8 -> V_92 , & V_8 -> V_6 [ V_21 ] ) ;
if ( V_8 -> V_26 & V_80 )
F_16 ( & V_8 -> V_6 [ V_21 ] , V_81 , 0 ) ;
}
V_8 -> V_39 = 0 ;
F_7 ( & V_8 -> V_6 [ 0 ] , V_40 , 0 ) ;
if ( V_8 -> V_44 . V_223 )
V_8 -> V_44 . V_223 () ;
V_180 = F_79 ( & V_172 -> V_9 , V_8 -> V_87 , NULL , F_32 ,
V_224 | V_225 ,
V_203 ( & V_172 -> V_9 ) , V_8 ) ;
if ( ! V_180 )
return 0 ;
F_68 ( & V_172 -> V_9 , L_20 , V_8 -> V_87 ) ;
V_197:
F_71 ( V_172 , NULL ) ;
return V_180 ;
}
static int F_80 ( struct V_171 * V_172 )
{
int V_21 ;
struct V_7 * V_8 = F_81 ( V_172 ) ;
F_82 ( & V_172 -> V_9 , V_8 -> V_87 , V_8 ) ;
for ( V_21 = 0 ; V_21 < V_8 -> V_92 . V_93 ; V_21 ++ )
F_83 ( & V_8 -> V_92 , & V_8 -> V_6 [ V_21 ] ) ;
F_84 ( & V_8 -> V_92 ) ;
F_71 ( V_172 , NULL ) ;
if ( V_8 -> V_44 . exit )
V_8 -> V_44 . exit () ;
return 0 ;
}
