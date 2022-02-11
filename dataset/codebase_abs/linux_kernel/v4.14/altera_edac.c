static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 = V_6 -> V_10 ;
T_2 V_11 , V_12 = 1 , V_13 ;
F_2 ( V_6 -> V_14 , V_9 -> V_15 , & V_11 ) ;
if ( V_11 & V_9 -> V_16 ) {
F_2 ( V_6 -> V_14 , V_9 -> V_17 ,
& V_13 ) ;
if ( V_9 -> V_18 )
F_2 ( V_6 -> V_14 , V_9 -> V_18 ,
& V_12 ) ;
F_3 ( L_1 ,
V_12 , V_13 ) ;
}
if ( V_11 & V_9 -> V_19 ) {
F_2 ( V_6 -> V_14 , V_9 -> V_20 ,
& V_13 ) ;
if ( V_9 -> V_18 )
F_2 ( V_6 -> V_14 , V_9 -> V_21 ,
& V_12 ) ;
F_4 ( V_22 , V_4 , V_12 ,
V_13 >> V_23 ,
V_13 & ~ V_24 , 0 ,
0 , 0 , - 1 , V_4 -> V_25 , L_2 ) ;
F_5 ( V_6 -> V_14 , V_9 -> V_26 ,
V_9 -> V_27 ) ;
return V_28 ;
}
return V_29 ;
}
static T_3 F_6 ( struct V_30 * V_30 ,
const char T_4 * V_10 ,
T_5 V_31 , T_6 * V_32 )
{
struct V_3 * V_4 = V_30 -> V_33 ;
struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 = V_6 -> V_10 ;
T_2 * V_34 ;
T_7 V_35 ;
T_2 V_36 , V_37 ;
V_34 = F_7 ( V_4 -> V_38 , 16 , & V_35 , V_39 ) ;
if ( ! V_34 ) {
F_8 ( V_4 -> V_38 , 16 , V_34 , V_35 ) ;
F_9 ( V_40 , V_41 ,
L_3 ) ;
return - V_42 ;
}
F_2 ( V_6 -> V_14 , V_9 -> V_43 ,
& V_37 ) ;
V_37 &= ~ ( V_9 -> V_44 | V_9 -> V_45 ) ;
if ( V_31 == 3 ) {
F_9 ( V_46 , V_41 ,
L_4 ) ;
F_10 () ;
F_5 ( V_6 -> V_14 , V_9 -> V_43 ,
( V_37 | V_9 -> V_45 ) ) ;
F_11 () ;
} else {
F_9 ( V_46 , V_41 ,
L_5 ) ;
F_10 () ;
F_5 ( V_6 -> V_14 , V_9 -> V_43 ,
( V_37 | V_9 -> V_44 ) ) ;
F_11 () ;
}
V_34 [ 0 ] = 0x5A5A5A5A ;
V_34 [ 1 ] = 0xA5A5A5A5 ;
F_5 ( V_6 -> V_14 , V_9 -> V_43 , V_37 ) ;
F_12 () ;
V_36 = F_13 ( V_34 [ 0 ] ) ;
V_37 = F_13 ( V_34 [ 1 ] ) ;
F_14 () ;
F_9 ( V_46 , V_41 , L_6 ,
V_36 , V_37 ) ;
F_8 ( V_4 -> V_38 , 16 , V_34 , V_35 ) ;
return V_31 ;
}
static void F_15 ( struct V_3 * V_4 )
{
if ( ! F_16 ( V_47 ) )
return;
if ( ! V_4 -> V_48 )
return;
F_17 ( L_7 , V_49 , V_4 -> V_48 , V_4 ,
& V_50 ) ;
}
static unsigned long F_18 ( void )
{
struct V_51 * V_52 = NULL ;
struct V_53 V_54 ;
int V_55 ;
unsigned long V_56 = 0 ;
F_19 (np, L_8 ) {
V_55 = F_20 ( V_52 , 0 , & V_54 ) ;
if ( V_55 )
continue;
V_56 += F_21 ( & V_54 ) ;
}
F_22 ( 0 , L_9 , V_56 ) ;
return V_56 ;
}
static int F_23 ( struct V_57 * V_14 )
{
if ( F_24 ( V_14 , V_58 ,
V_59 , V_59 ) ) {
F_9 ( V_40 , V_41 ,
L_10 ) ;
return - V_60 ;
}
if ( F_5 ( V_14 , V_61 , 1 ) ) {
F_9 ( V_40 , V_41 ,
L_11 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_25 ( struct V_62 * V_38 , T_2 V_63 )
{
void T_8 * V_64 ;
int V_55 = 0 ;
if ( ! F_26 ( V_65 , sizeof( T_2 ) ,
F_27 ( & V_38 -> V_66 ) ) ) {
F_9 ( V_40 , V_41 ,
L_12 ) ;
return - V_67 ;
}
V_64 = F_28 ( V_65 , sizeof( T_2 ) ) ;
if ( ! V_64 ) {
F_9 ( V_40 , V_41 ,
L_13 ) ;
V_55 = - V_42 ;
goto V_68;
}
F_29 ( V_63 , V_64 ) ;
F_30 ( V_64 ) ;
V_68:
F_31 ( V_65 , sizeof( T_2 ) ) ;
return V_55 ;
}
static int F_32 ( struct V_62 * V_38 )
{
const struct V_69 * V_70 ;
struct V_71 V_72 [ 2 ] ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
const struct V_8 * V_9 ;
struct V_57 * V_14 ;
struct V_73 * V_74 ;
T_2 V_37 ;
int V_1 , V_75 , V_54 = 0 ;
unsigned long V_76 , V_77 = 0 ;
V_70 = F_33 ( V_78 , & V_38 -> V_66 ) ;
if ( ! V_70 )
return - V_60 ;
V_14 = F_34 ( V_38 -> V_66 . V_79 ,
L_14 ) ;
if ( F_35 ( V_14 ) ) {
F_9 ( V_40 , V_41 ,
L_15 ) ;
return - V_60 ;
}
V_9 = F_36 ( V_78 ,
V_38 -> V_66 . V_79 ) -> V_10 ;
if ( F_2 ( V_14 , V_9 -> V_80 , & V_37 ) ||
( ( V_37 & V_9 -> V_81 ) != V_9 -> V_81 ) ) {
F_9 ( V_40 , V_41 ,
L_16 , V_37 ) ;
return - V_60 ;
}
V_76 = F_18 () ;
if ( ! V_76 ) {
F_9 ( V_40 , V_41 , L_17 ) ;
return - V_60 ;
}
if ( F_24 ( V_14 , V_9 -> V_82 ,
V_9 -> V_83 , 0 ) ) {
F_9 ( V_40 , V_41 ,
L_18 ) ;
return - V_60 ;
}
if ( F_24 ( V_14 , V_9 -> V_84 ,
V_9 -> V_85 ,
V_9 -> V_85 ) ) {
F_9 ( V_40 , V_41 ,
L_19 ) ;
return - V_60 ;
}
if ( F_24 ( V_14 , V_9 -> V_84 ,
V_9 -> V_85 , 0 ) ) {
F_9 ( V_40 , V_41 ,
L_19 ) ;
return - V_60 ;
}
V_1 = F_37 ( V_38 , 0 ) ;
if ( V_1 < 0 ) {
F_9 ( V_40 , V_41 ,
L_20 , V_1 ) ;
return - V_60 ;
}
V_75 = F_37 ( V_38 , 1 ) ;
V_72 [ 0 ] . type = V_86 ;
V_72 [ 0 ] . V_87 = 1 ;
V_72 [ 0 ] . V_88 = true ;
V_72 [ 1 ] . type = V_89 ;
V_72 [ 1 ] . V_87 = 1 ;
V_72 [ 1 ] . V_88 = false ;
V_4 = F_38 ( 0 , F_39 ( V_72 ) , V_72 ,
sizeof( struct V_5 ) ) ;
if ( ! V_4 )
return - V_42 ;
V_4 -> V_38 = & V_38 -> V_66 ;
V_6 = V_4 -> V_7 ;
V_6 -> V_14 = V_14 ;
V_6 -> V_10 = V_9 ;
F_40 ( V_38 , V_4 ) ;
if ( ! F_41 ( & V_38 -> V_66 , NULL , V_39 ) ) {
F_9 ( V_40 , V_41 ,
L_21 ) ;
V_54 = - V_42 ;
goto free;
}
V_4 -> V_90 = V_91 ;
V_4 -> V_92 = V_93 | V_94 ;
V_4 -> V_95 = V_94 ;
V_4 -> V_96 = V_97 ;
V_4 -> V_25 = F_27 ( & V_38 -> V_66 ) ;
V_4 -> V_98 = V_99 ;
V_4 -> F_27 = F_27 ( & V_38 -> V_66 ) ;
V_74 = * V_4 -> V_100 ;
V_74 -> V_101 = ( ( V_76 - 1 ) >> V_23 ) + 1 ;
V_74 -> V_102 = 8 ;
V_74 -> V_103 = V_104 ;
V_74 -> V_105 = V_106 ;
V_74 -> V_107 = V_108 ;
V_54 = F_42 ( V_4 ) ;
if ( V_54 < 0 )
goto V_109;
if ( V_75 > 0 ) {
V_54 = F_23 ( V_14 ) ;
if ( V_54 < 0 )
goto V_110;
V_54 = F_43 ( & V_38 -> V_66 , V_75 ,
F_1 ,
V_111 , F_27 ( & V_38 -> V_66 ) , V_4 ) ;
if ( V_54 < 0 ) {
F_44 ( V_4 , V_40 ,
L_22 , V_75 ) ;
V_54 = - V_60 ;
goto V_110;
}
V_54 = F_25 ( V_38 , V_112 ) ;
if ( V_54 < 0 )
goto V_110;
V_77 = V_111 ;
}
V_54 = F_43 ( & V_38 -> V_66 , V_1 , F_1 ,
V_77 , F_27 ( & V_38 -> V_66 ) , V_4 ) ;
if ( V_54 < 0 ) {
F_44 ( V_4 , V_40 ,
L_22 , V_1 ) ;
V_54 = - V_60 ;
goto V_110;
}
if ( F_24 ( V_6 -> V_14 , V_9 -> V_82 ,
V_9 -> V_83 , V_9 -> V_83 ) ) {
F_44 ( V_4 , V_40 ,
L_23 ) ;
V_54 = - V_60 ;
goto V_110;
}
F_15 ( V_4 ) ;
F_45 ( & V_38 -> V_66 , NULL ) ;
return 0 ;
V_110:
F_46 ( & V_38 -> V_66 ) ;
V_109:
F_47 ( & V_38 -> V_66 , NULL ) ;
free:
F_48 ( V_4 ) ;
F_9 ( V_40 , V_41 ,
L_24 , V_54 ) ;
return V_54 ;
}
static int F_49 ( struct V_62 * V_38 )
{
struct V_3 * V_4 = F_50 ( V_38 ) ;
F_46 ( & V_38 -> V_66 ) ;
F_48 ( V_4 ) ;
F_40 ( V_38 , NULL ) ;
return 0 ;
}
static int F_51 ( struct V_113 * V_66 )
{
F_52 ( L_25 ) ;
return - V_114 ;
}
static int F_53 ( struct V_62 * V_38 )
{
F_54 ( V_38 -> V_66 . V_79 , V_115 ,
NULL , & V_38 -> V_66 ) ;
return 0 ;
}
static T_1 F_55 ( int V_1 , void * V_2 )
{
T_1 V_116 = V_29 ;
struct V_117 * V_118 = V_2 ;
struct V_119 * V_6 = V_118 -> V_7 ;
const struct V_120 * V_9 = V_6 -> V_10 ;
if ( V_1 == V_6 -> V_121 ) {
if ( V_9 -> V_122 )
F_56 ( V_9 -> V_122 , V_6 -> V_123 ) ;
F_57 ( V_118 , 0 , 0 , V_6 -> V_124 ) ;
V_116 = V_28 ;
} else if ( V_1 == V_6 -> V_125 ) {
if ( V_9 -> V_126 )
F_56 ( V_9 -> V_126 , V_6 -> V_123 ) ;
F_58 ( V_118 , 0 , 0 , V_6 -> V_124 ) ;
F_3 ( L_26 ) ;
V_116 = V_28 ;
} else {
F_59 ( 1 ) ;
}
return V_116 ;
}
static T_3 F_60 ( struct V_30 * V_30 ,
const char T_4 * V_127 ,
T_5 V_31 , T_6 * V_32 )
{
T_2 * V_34 , V_128 , V_129 ;
int V_130 = 0 ;
T_9 V_131 ;
unsigned long V_132 ;
struct V_117 * V_133 = V_30 -> V_33 ;
struct V_119 * V_6 = V_133 -> V_7 ;
const struct V_120 * V_9 = V_6 -> V_10 ;
void * V_134 = V_133 -> V_66 ;
if ( ! V_127 || F_61 ( V_131 , V_127 ) )
return - V_135 ;
if ( ! V_9 -> V_136 )
return - V_42 ;
V_34 = V_9 -> V_136 ( V_9 -> V_137 , & V_134 ) ;
if ( ! V_34 ) {
F_9 ( V_40 , V_138 ,
L_3 ) ;
return - V_42 ;
}
if ( V_131 == V_139 )
V_129 = V_9 -> V_45 ;
else
V_129 = V_9 -> V_44 ;
F_9 ( V_46 , V_138 ,
L_27 , V_129 ) ;
F_62 ( V_132 ) ;
for ( V_128 = 0 ; V_128 < ( V_9 -> V_137 / sizeof( * V_34 ) ) ; V_128 ++ ) {
F_14 () ;
if ( F_13 ( V_34 [ V_128 ] ) )
V_130 = - 1 ;
F_56 ( V_129 , ( V_6 -> V_123 + V_9 -> V_140 ) ) ;
F_56 ( V_9 -> V_141 , ( V_6 -> V_123 +
V_9 -> V_140 ) ) ;
V_34 [ V_128 ] = V_128 ;
}
F_12 () ;
F_63 ( V_132 ) ;
if ( V_130 )
F_9 ( V_40 , V_138 , L_28 ) ;
for ( V_128 = 0 ; V_128 < V_142 ; V_128 ++ )
if ( F_13 ( V_34 [ V_128 ] ) != V_128 )
F_9 ( V_40 , V_138 ,
L_29 ) ;
if ( V_9 -> V_143 )
V_9 -> V_143 ( V_34 , V_9 -> V_137 , V_134 ) ;
return V_31 ;
}
static void F_64 ( struct V_117 * V_133 ,
const struct V_120 * V_9 )
{
struct V_119 * V_6 = V_133 -> V_7 ;
if ( ! F_16 ( V_47 ) )
return;
V_6 -> V_144 = F_65 ( V_6 -> V_124 ) ;
if ( ! V_6 -> V_144 )
return;
if ( ! F_17 ( L_7 , V_49 ,
V_6 -> V_144 , V_133 ,
V_9 -> V_145 ) )
F_66 ( V_6 -> V_144 ) ;
}
static int F_67 ( struct V_62 * V_38 )
{
struct V_117 * V_118 ;
struct V_119 * V_6 ;
struct V_53 * V_146 ;
int V_54 = 0 ;
struct V_51 * V_52 = V_38 -> V_66 . V_79 ;
char * V_147 = ( char * ) V_52 -> V_148 ;
static int V_149 ;
if ( ! F_41 ( & V_38 -> V_66 , NULL , V_39 ) ) {
F_9 ( V_40 , V_138 ,
L_30 ) ;
return - V_42 ;
}
V_146 = F_68 ( V_38 , V_150 , 0 ) ;
if ( ! V_146 ) {
F_9 ( V_40 , V_138 ,
L_31 ) ;
V_54 = - V_60 ;
goto V_151;
}
if ( ! F_69 ( & V_38 -> V_66 , V_146 -> V_152 , F_21 ( V_146 ) ,
F_27 ( & V_38 -> V_66 ) ) ) {
F_9 ( V_40 , V_138 ,
L_32 , V_147 ) ;
V_54 = - V_67 ;
goto V_151;
}
V_118 = F_70 ( sizeof( * V_6 ) , V_147 ,
1 , V_147 , 1 , 0 , NULL , 0 ,
V_149 ++ ) ;
if ( ! V_118 ) {
F_9 ( V_40 , V_138 ,
L_33 , V_147 ) ;
V_54 = - V_42 ;
goto V_151;
}
V_6 = V_118 -> V_7 ;
V_118 -> V_66 = & V_38 -> V_66 ;
F_40 ( V_38 , V_118 ) ;
V_6 -> V_124 = V_147 ;
V_6 -> V_123 = F_71 ( & V_38 -> V_66 , V_146 -> V_152 , F_21 ( V_146 ) ) ;
if ( ! V_6 -> V_123 ) {
V_54 = - V_42 ;
goto V_153;
}
V_6 -> V_10 = F_36 ( V_115 , V_52 ) -> V_10 ;
if ( V_6 -> V_10 -> V_154 ) {
V_54 = V_6 -> V_10 -> V_154 ( V_6 ) ;
if ( V_54 )
goto V_153;
}
V_6 -> V_121 = F_37 ( V_38 , 0 ) ;
V_54 = F_43 ( & V_38 -> V_66 , V_6 -> V_121 ,
F_55 ,
0 , F_27 ( & V_38 -> V_66 ) , V_118 ) ;
if ( V_54 )
goto V_153;
V_6 -> V_125 = F_37 ( V_38 , 1 ) ;
V_54 = F_43 ( & V_38 -> V_66 , V_6 -> V_125 ,
F_55 ,
0 , F_27 ( & V_38 -> V_66 ) , V_118 ) ;
if ( V_54 )
goto V_153;
V_118 -> V_96 = L_34 ;
V_118 -> F_27 = V_6 -> V_124 ;
V_54 = F_72 ( V_118 ) ;
if ( V_54 )
goto V_153;
F_64 ( V_118 , V_6 -> V_10 ) ;
F_45 ( & V_38 -> V_66 , NULL ) ;
return 0 ;
V_153:
F_73 ( V_118 ) ;
V_151:
F_47 ( & V_38 -> V_66 , NULL ) ;
F_9 ( V_40 , V_138 ,
L_35 , V_147 , V_54 ) ;
return V_54 ;
}
static int F_74 ( struct V_62 * V_38 )
{
struct V_117 * V_118 = F_50 ( V_38 ) ;
struct V_119 * V_6 = V_118 -> V_7 ;
F_66 ( V_6 -> V_144 ) ;
F_75 ( & V_38 -> V_66 ) ;
F_73 ( V_118 ) ;
return 0 ;
}
static int T_10
F_76 ( struct V_119 * V_113 )
{
void T_8 * V_123 = V_113 -> V_123 ;
const struct V_120 * V_155 = V_113 -> V_10 ;
if ( F_77 ( V_123 + V_155 -> V_156 ) & V_155 -> V_141 )
return 0 ;
F_9 ( V_40 , V_138 ,
L_36 ,
V_113 -> V_124 ) ;
return - V_60 ;
}
static T_1 T_10 F_78 ( int V_1 , void * V_2 )
{
struct V_119 * V_118 = V_2 ;
void T_8 * V_123 = V_118 -> V_123 ;
if ( V_1 == V_118 -> V_121 ) {
F_56 ( V_157 ,
V_123 + V_158 ) ;
F_57 ( V_118 -> V_159 , 0 , 0 , V_118 -> V_124 ) ;
return V_28 ;
} else if ( V_1 == V_118 -> V_125 ) {
F_56 ( V_160 ,
V_123 + V_158 ) ;
F_58 ( V_118 -> V_159 , 0 , 0 , V_118 -> V_124 ) ;
if ( V_118 -> V_10 -> F_3 )
F_3 ( L_26 ) ;
return V_28 ;
}
F_59 ( 1 ) ;
return V_29 ;
}
static inline int F_79 ( struct V_51 * V_52 )
{
int V_1 ;
const T_2 * V_161 = F_80 ( V_52 , L_37 , NULL ) ;
if ( ! V_161 )
return - V_60 ;
V_1 = F_81 ( V_161 ) ;
return V_1 ;
}
static inline void F_82 ( T_2 V_162 , void T_8 * V_163 )
{
T_2 V_164 = F_77 ( V_163 ) ;
V_164 |= V_162 ;
F_56 ( V_164 , V_163 ) ;
}
static inline void F_83 ( T_2 V_162 , void T_8 * V_163 )
{
T_2 V_164 = F_77 ( V_163 ) ;
V_164 &= ~ V_162 ;
F_56 ( V_164 , V_163 ) ;
}
static inline int F_84 ( T_2 V_162 , void T_8 * V_163 )
{
T_2 V_164 = F_77 ( V_163 ) ;
return ( V_164 & V_162 ) ? 1 : 0 ;
}
static int T_10 F_85 ( void T_8 * V_163 , int V_165 )
{
int V_166 = V_167 ;
T_2 V_168 , V_169 , V_170 ;
int V_55 = 0 ;
if ( V_165 ) {
V_168 = V_171 ;
V_169 = V_172 ;
V_170 = V_173 ;
} else {
V_168 = V_174 ;
V_169 = V_175 ;
V_170 = V_176 ;
}
F_82 ( V_168 , ( V_163 + V_177 ) ) ;
while ( V_166 -- ) {
if ( F_84 ( V_169 ,
( V_163 + V_178 ) ) )
break;
F_86 ( 1 ) ;
}
if ( V_166 < 0 )
V_55 = - V_67 ;
F_56 ( V_170 , ( V_163 + V_158 ) ) ;
return V_55 ;
}
static T_11 int T_10
F_87 ( struct V_51 * V_52 , T_2 V_179 ,
T_2 V_180 , bool V_181 )
{
int V_55 = 0 ;
void T_8 * V_182 ;
struct V_57 * V_183 ;
char * V_147 ;
struct V_51 * V_184 ;
V_147 = ( char * ) V_52 -> V_148 ;
V_184 = F_88 ( V_52 ) ;
V_183 = F_34 ( V_184 ,
L_38 ) ;
F_89 ( V_184 ) ;
if ( F_35 ( V_183 ) ) {
F_9 ( V_40 , V_138 ,
L_39 ) ;
return - V_60 ;
}
V_182 = F_90 ( V_52 , 0 ) ;
if ( ! V_182 ) {
F_9 ( V_40 , V_138 ,
L_40 , V_147 ) ;
return - V_60 ;
}
F_5 ( V_183 , V_185 , V_179 ) ;
F_56 ( V_186 ,
( V_182 + V_187 ) ) ;
F_83 ( V_180 ,
( V_182 + V_177 ) ) ;
F_12 () ;
V_55 = F_85 ( V_182 , 0 ) ;
if ( V_55 ) {
F_9 ( V_40 , V_138 ,
L_41 , V_147 ) ;
goto V_188;
}
if ( V_181 ) {
V_55 = F_85 ( V_182 , 1 ) ;
if ( V_55 ) {
F_9 ( V_40 , V_138 ,
L_42 ,
V_147 ) ;
goto V_188;
}
}
F_5 ( V_183 , V_189 ,
V_190 ) ;
F_82 ( V_180 , ( V_182 +
V_177 ) ) ;
F_56 ( V_186 ,
( V_182 + V_191 ) ) ;
F_5 ( V_183 , V_192 , V_179 ) ;
F_12 () ;
V_188:
F_30 ( V_182 ) ;
return V_55 ;
}
static int F_91 ( void )
{
return F_92 ( L_43 ) ;
}
static int T_11 T_10 F_93 ( char * V_193 )
{
int V_1 ;
struct V_51 * V_194 , * V_52 ;
if ( ! F_91 () )
return - V_60 ;
V_52 = F_94 ( NULL , NULL ,
L_44 ) ;
if ( ! V_52 ) {
F_9 ( V_40 , V_138 , L_45 ) ;
return - V_60 ;
}
F_95 (np, child) {
const struct V_69 * V_195 ;
const struct V_120 * V_155 ;
if ( ! F_96 ( V_194 ) )
continue;
if ( ! F_97 ( V_194 , V_193 ) )
continue;
if ( F_98 ( V_194 ) )
continue;
V_1 = F_79 ( V_194 ) ;
if ( V_1 < 0 )
continue;
V_195 = F_36 ( V_196 , V_194 ) ;
if ( F_99 ( V_195 ) )
continue;
V_155 = V_195 -> V_10 ;
if ( ! V_155 )
continue;
F_87 ( V_194 , F_100 ( V_1 ) ,
V_155 -> V_141 , 0 ) ;
}
F_89 ( V_52 ) ;
return 0 ;
}
static void * F_101 ( T_5 V_87 , void * * V_197 )
{
struct V_51 * V_52 ;
struct V_198 * V_199 ;
void * V_200 ;
V_52 = F_94 ( NULL , NULL , L_46 ) ;
if ( ! V_52 )
return NULL ;
V_199 = F_102 ( V_52 , L_47 , 0 ) ;
F_89 ( V_52 ) ;
if ( ! V_199 )
return NULL ;
V_200 = ( void * ) F_103 ( V_199 , V_87 ) ;
if ( ! V_200 )
return NULL ;
memset ( V_200 , 0 , V_87 ) ;
F_12 () ;
* V_197 = V_199 ;
return V_200 ;
}
static void F_104 ( void * V_201 , T_5 V_87 , void * V_197 )
{
F_105 ( (struct V_198 * ) V_197 , ( T_2 ) V_201 , V_87 ) ;
}
static void * F_106 ( T_5 V_87 , void * * V_197 )
{
struct V_113 * V_66 = * V_197 ;
void * V_34 = F_107 ( V_66 , V_87 , V_39 ) ;
if ( ! V_34 )
return NULL ;
F_12 () ;
F_108 () ;
return V_34 ;
}
static void F_109 ( void * V_201 , T_5 V_87 , void * V_197 )
{
struct V_113 * V_66 = V_197 ;
if ( V_66 && V_201 )
F_110 ( V_66 , V_201 ) ;
}
static int F_111 ( struct V_119 * V_113 )
{
void T_8 * V_123 = V_113 -> V_123 ;
const struct V_120 * V_155 = V_113 -> V_10 ;
if ( ( F_77 ( V_123 ) & V_155 -> V_141 ) ==
V_155 -> V_141 )
return 0 ;
F_9 ( V_40 , V_138 ,
L_48 ) ;
return - V_60 ;
}
static T_1 F_112 ( int V_1 , void * V_2 )
{
struct V_119 * V_118 = V_2 ;
if ( V_1 == V_118 -> V_121 ) {
F_5 ( V_118 -> V_202 -> V_183 ,
V_203 ,
V_204 ) ;
F_57 ( V_118 -> V_159 , 0 , 0 , V_118 -> V_124 ) ;
return V_28 ;
} else if ( V_1 == V_118 -> V_125 ) {
F_5 ( V_118 -> V_202 -> V_183 ,
V_203 ,
V_205 ) ;
F_58 ( V_118 -> V_159 , 0 , 0 , V_118 -> V_124 ) ;
F_3 ( L_26 ) ;
return V_28 ;
}
F_59 ( 1 ) ;
return V_29 ;
}
static int T_11 F_113 ( void )
{
return F_93 ( L_49 ) ;
}
static int T_11 F_114 ( void )
{
return F_93 ( L_50 ) ;
}
static int T_11 F_115 ( void )
{
return F_93 ( L_51 ) ;
}
static int T_11 F_116 ( void )
{
return F_93 ( L_52 ) ;
}
static int T_11 F_117 ( void )
{
return F_93 ( L_53 ) ;
}
static int F_118 ( struct V_119 * V_113 )
{
struct V_117 * V_118 ;
struct V_119 * V_206 ;
char * V_147 = L_54 ;
int V_207 , V_208 ;
struct V_51 * V_52 ;
const struct V_120 * V_155 = & V_209 ;
V_208 = F_76 ( V_113 ) ;
if ( V_208 )
return V_208 ;
V_52 = F_94 ( NULL , NULL , L_55 ) ;
if ( ! V_52 ) {
F_9 ( V_210 , V_138 , L_56 ) ;
return - V_60 ;
}
V_207 = F_119 () ;
V_118 = F_70 ( sizeof( * V_206 ) , V_147 , 1 ,
V_147 , 1 , 0 , NULL , 0 , V_207 ) ;
if ( ! V_118 ) {
F_9 ( V_40 , V_138 ,
L_57 ,
V_147 ) ;
return - V_42 ;
}
V_206 = V_118 -> V_7 ;
* V_206 = * V_113 ;
if ( ! F_41 ( & V_206 -> V_211 , F_118 , V_39 ) )
return - V_42 ;
V_206 -> V_124 = V_147 ;
V_206 -> V_207 = V_207 ;
V_206 -> V_159 = V_118 ;
V_206 -> V_10 = V_155 ;
V_118 -> V_66 = & V_206 -> V_211 ;
V_118 -> V_25 = L_34 ;
V_118 -> V_96 = V_147 ;
V_118 -> F_27 = V_147 ;
V_206 -> V_121 = F_120 ( V_52 , 2 ) ;
if ( ! V_206 -> V_121 ) {
F_9 ( V_40 , V_138 , L_58 ) ;
V_208 = - V_60 ;
goto V_212;
}
V_208 = F_43 ( & V_206 -> V_211 , V_206 -> V_121 ,
V_155 -> V_213 ,
V_214 | V_215 ,
V_147 , V_206 ) ;
if ( V_208 ) {
F_9 ( V_40 , V_138 , L_59 ) ;
goto V_212;
}
V_206 -> V_125 = F_120 ( V_52 , 3 ) ;
if ( ! V_206 -> V_125 ) {
F_9 ( V_40 , V_138 , L_60 ) ;
V_208 = - V_60 ;
goto V_212;
}
V_208 = F_43 ( & V_206 -> V_211 , V_206 -> V_125 ,
V_155 -> V_213 ,
V_214 | V_215 ,
V_147 , V_206 ) ;
if ( V_208 ) {
F_9 ( V_40 , V_138 , L_61 ) ;
goto V_212;
}
V_208 = F_72 ( V_118 ) ;
if ( V_208 ) {
F_9 ( V_40 , V_138 ,
L_62 ) ;
V_208 = - V_42 ;
goto V_212;
}
F_64 ( V_118 , V_155 ) ;
F_121 ( & V_206 -> V_216 , & V_206 -> V_202 -> V_217 ) ;
F_122 ( & V_206 -> V_211 , F_118 ) ;
return 0 ;
V_212:
F_73 ( V_118 ) ;
F_47 ( & V_206 -> V_211 , F_118 ) ;
F_9 ( V_40 , V_138 ,
L_35 , V_147 , V_208 ) ;
return V_208 ;
}
static T_1 F_123 ( int V_1 , void * V_2 )
{
struct V_119 * V_218 = V_2 ;
void T_8 * V_123 = V_218 -> V_123 ;
const struct V_120 * V_9 = V_218 -> V_10 ;
if ( V_1 == V_218 -> V_121 ) {
F_56 ( V_9 -> V_122 ,
V_123 + V_158 ) ;
F_57 ( V_218 -> V_159 , 0 , 0 , V_218 -> V_124 ) ;
return V_28 ;
} else if ( V_1 == V_218 -> V_125 ) {
F_56 ( V_9 -> V_126 ,
V_123 + V_158 ) ;
F_58 ( V_218 -> V_159 , 0 , 0 , V_218 -> V_124 ) ;
return V_28 ;
}
F_124 ( 1 , L_63 , V_1 ) ;
return V_29 ;
}
static int T_11 F_125 ( void )
{
int V_208 = - V_60 ;
struct V_51 * V_194 ;
if ( ! F_91 () )
return - V_60 ;
V_194 = F_94 ( NULL , NULL , L_55 ) ;
if ( ! V_194 ) {
F_9 ( V_210 , V_138 , L_56 ) ;
return - V_60 ;
}
if ( ! F_96 ( V_194 ) )
goto exit;
if ( F_98 ( V_194 ) )
goto exit;
V_208 = F_87 ( V_194 , V_219 ,
V_220 . V_141 , 1 ) ;
exit:
F_89 ( V_194 ) ;
return V_208 ;
}
static T_3 F_126 ( struct V_30 * V_30 ,
const char T_4 * V_127 ,
T_5 V_31 , T_6 * V_32 )
{
struct V_117 * V_133 = V_30 -> V_33 ;
struct V_119 * V_6 = V_133 -> V_7 ;
const struct V_120 * V_9 = V_6 -> V_10 ;
void T_8 * V_221 = ( V_6 -> V_123 + V_9 -> V_140 ) ;
unsigned long V_132 ;
T_9 V_131 ;
if ( ! V_127 || F_61 ( V_131 , V_127 ) )
return - V_135 ;
F_62 ( V_132 ) ;
if ( V_131 == V_139 )
F_56 ( V_9 -> V_45 , V_221 ) ;
else
F_56 ( V_9 -> V_44 , V_221 ) ;
F_12 () ;
F_63 ( V_132 ) ;
return V_31 ;
}
static void F_127 ( struct V_222 * V_223 )
{
int V_224 , V_225 , V_226 , V_227 ;
struct V_228 * V_202 = F_128 ( V_223 ) ;
struct V_229 * V_230 = F_129 ( V_223 ) ;
int V_1 = F_130 ( V_223 ) ;
V_224 = ( V_1 == V_202 -> V_125 ) ? 1 : 0 ;
V_226 = V_224 ? V_231 :
V_232 ;
F_131 ( V_230 , V_223 ) ;
F_2 ( V_202 -> V_183 , V_226 , & V_227 ) ;
F_132 (bit, (unsigned long *)&irq_status, 32 ) {
V_1 = F_133 ( V_202 -> V_233 , V_224 * 32 + V_225 ) ;
if ( V_1 )
F_134 ( V_1 ) ;
}
F_135 ( V_230 , V_223 ) ;
}
static int F_98 ( struct V_51 * V_52 )
{
struct V_51 * V_234 ;
int V_55 = 0 ;
V_234 = F_136 ( V_52 , L_64 , 0 ) ;
if ( V_234 && ! F_96 ( V_234 ) )
V_55 = - V_60 ;
F_89 ( V_234 ) ;
return V_55 ;
}
static int F_137 ( struct V_228 * V_202 ,
struct V_51 * V_52 )
{
struct V_117 * V_118 ;
struct V_119 * V_206 ;
char * V_147 = ( char * ) V_52 -> V_148 ;
struct V_53 V_54 ;
int V_207 ;
int V_208 = 0 ;
const struct V_120 * V_155 ;
const struct V_69 * V_195 =
F_36 ( V_196 , V_52 ) ;
if ( F_99 ( V_195 ) )
return - V_60 ;
V_155 = V_195 -> V_10 ;
if ( F_99 ( V_155 ) )
return - V_60 ;
if ( F_98 ( V_52 ) )
return - V_60 ;
if ( ! F_41 ( V_202 -> V_66 , F_137 , V_39 ) )
return - V_42 ;
V_208 = F_20 ( V_52 , 0 , & V_54 ) ;
if ( V_208 < 0 ) {
F_9 ( V_40 , V_138 ,
L_65 , V_147 ) ;
goto V_235;
}
V_207 = F_119 () ;
V_118 = F_70 ( sizeof( * V_206 ) , V_147 ,
1 , V_147 , 1 , 0 , NULL , 0 ,
V_207 ) ;
if ( ! V_118 ) {
F_9 ( V_40 , V_138 ,
L_33 , V_147 ) ;
V_208 = - V_42 ;
goto V_235;
}
V_206 = V_118 -> V_7 ;
V_118 -> V_66 = V_202 -> V_66 ;
V_206 -> V_124 = V_147 ;
V_206 -> V_207 = V_207 ;
V_206 -> V_202 = V_202 ;
V_206 -> V_159 = V_118 ;
V_206 -> V_10 = V_155 ;
V_206 -> V_211 = * V_202 -> V_66 ;
V_118 -> V_66 = & V_206 -> V_211 ;
V_118 -> V_25 = L_34 ;
V_118 -> V_96 = V_147 ;
V_118 -> F_27 = V_147 ;
V_206 -> V_123 = F_138 ( V_202 -> V_66 , & V_54 ) ;
if ( F_35 ( V_206 -> V_123 ) ) {
V_208 = F_139 ( V_206 -> V_123 ) ;
goto V_236;
}
if ( V_206 -> V_10 -> V_154 ) {
V_208 = V_206 -> V_10 -> V_154 ( V_206 ) ;
if ( V_208 )
goto V_236;
}
V_206 -> V_121 = F_120 ( V_52 , 0 ) ;
if ( ! V_206 -> V_121 ) {
F_9 ( V_40 , V_138 , L_66 ) ;
V_208 = - V_60 ;
goto V_236;
}
V_208 = F_43 ( V_202 -> V_66 , V_206 -> V_121 , V_155 -> V_213 ,
V_214 | V_215 ,
V_147 , V_206 ) ;
if ( V_208 ) {
F_9 ( V_40 , V_138 , L_67 ) ;
goto V_236;
}
V_206 -> V_125 = F_120 ( V_52 , 1 ) ;
if ( ! V_206 -> V_125 ) {
F_9 ( V_40 , V_138 , L_68 ) ;
V_208 = - V_60 ;
goto V_236;
}
V_208 = F_43 ( V_202 -> V_66 , V_206 -> V_125 , V_155 -> V_213 ,
V_214 | V_215 ,
V_147 , V_206 ) ;
if ( V_208 ) {
F_9 ( V_40 , V_138 , L_69 ) ;
goto V_236;
}
V_208 = F_72 ( V_118 ) ;
if ( V_208 ) {
F_140 ( V_202 -> V_66 , L_70 ) ;
V_208 = - V_42 ;
goto V_236;
}
F_64 ( V_118 , V_155 ) ;
F_121 ( & V_206 -> V_216 , & V_202 -> V_217 ) ;
F_122 ( V_202 -> V_66 , F_137 ) ;
return 0 ;
V_236:
F_73 ( V_118 ) ;
V_235:
F_47 ( V_202 -> V_66 , NULL ) ;
F_9 ( V_40 , V_138 ,
L_35 , V_147 , V_208 ) ;
return V_208 ;
}
static void F_141 ( struct V_237 * V_238 )
{
struct V_228 * V_202 = F_142 ( V_238 ) ;
F_5 ( V_202 -> V_183 , V_185 ,
F_100 ( V_238 -> V_239 ) ) ;
}
static void F_143 ( struct V_237 * V_238 )
{
struct V_228 * V_202 = F_142 ( V_238 ) ;
F_5 ( V_202 -> V_183 , V_192 ,
F_100 ( V_238 -> V_239 ) ) ;
}
static int F_144 ( struct V_240 * V_238 , unsigned int V_1 ,
T_12 V_239 )
{
struct V_228 * V_202 = V_238 -> V_241 ;
F_145 ( V_1 , & V_202 -> V_229 , V_242 ) ;
F_146 ( V_1 , V_202 ) ;
F_147 ( V_1 ) ;
return 0 ;
}
static int F_148 ( struct V_62 * V_38 )
{
struct V_228 * V_202 ;
struct V_51 * V_194 ;
V_202 = F_107 ( & V_38 -> V_66 , sizeof( * V_202 ) , V_39 ) ;
if ( ! V_202 )
return - V_42 ;
V_202 -> V_66 = & V_38 -> V_66 ;
F_40 ( V_38 , V_202 ) ;
F_149 ( & V_202 -> V_217 ) ;
V_202 -> V_183 = F_34 ( V_38 -> V_66 . V_79 ,
L_38 ) ;
if ( F_35 ( V_202 -> V_183 ) ) {
F_9 ( V_40 , V_138 ,
L_39 ) ;
return F_139 ( V_202 -> V_183 ) ;
}
V_202 -> V_229 . V_148 = V_38 -> V_66 . V_79 -> V_148 ;
V_202 -> V_229 . V_179 = F_141 ;
V_202 -> V_229 . V_243 = F_143 ;
V_202 -> V_233 = F_150 ( V_38 -> V_66 . V_79 , 64 ,
& V_244 , V_202 ) ;
if ( ! V_202 -> V_233 ) {
F_140 ( & V_38 -> V_66 , L_71 ) ;
return - V_42 ;
}
V_202 -> V_121 = F_37 ( V_38 , 0 ) ;
if ( V_202 -> V_121 < 0 ) {
F_140 ( & V_38 -> V_66 , L_67 ) ;
return V_202 -> V_121 ;
}
F_151 ( V_202 -> V_121 ,
F_127 ,
V_202 ) ;
V_202 -> V_125 = F_37 ( V_38 , 1 ) ;
if ( V_202 -> V_125 < 0 ) {
F_140 ( & V_38 -> V_66 , L_69 ) ;
return V_202 -> V_125 ;
}
F_151 ( V_202 -> V_125 ,
F_127 ,
V_202 ) ;
F_95 (pdev->dev.of_node, child) {
if ( ! F_96 ( V_194 ) )
continue;
if ( F_97 ( V_194 , L_72 ) ||
F_97 ( V_194 , L_73 ) ||
F_97 ( V_194 , L_49 ) ||
F_97 ( V_194 , L_50 ) ||
F_97 ( V_194 , L_51 ) ||
F_97 ( V_194 , L_52 ) ||
F_97 ( V_194 , L_53 ) ||
F_97 ( V_194 , L_55 ) )
F_137 ( V_202 , V_194 ) ;
else if ( F_97 ( V_194 , L_74 ) )
F_54 ( V_38 -> V_66 . V_79 ,
V_78 ,
NULL , & V_38 -> V_66 ) ;
}
return 0 ;
}
