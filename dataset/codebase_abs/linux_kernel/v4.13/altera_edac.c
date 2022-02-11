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
V_4 -> V_98 = V_99 ;
V_4 -> V_25 = F_27 ( & V_38 -> V_66 ) ;
V_4 -> V_100 = V_101 ;
V_4 -> F_27 = F_27 ( & V_38 -> V_66 ) ;
V_74 = * V_4 -> V_102 ;
V_74 -> V_103 = ( ( V_76 - 1 ) >> V_23 ) + 1 ;
V_74 -> V_104 = 8 ;
V_74 -> V_105 = V_106 ;
V_74 -> V_107 = V_108 ;
V_74 -> V_109 = V_110 ;
V_54 = F_42 ( V_4 ) ;
if ( V_54 < 0 )
goto V_111;
if ( V_75 > 0 ) {
V_54 = F_23 ( V_14 ) ;
if ( V_54 < 0 )
goto V_112;
V_54 = F_43 ( & V_38 -> V_66 , V_75 ,
F_1 ,
V_113 , F_27 ( & V_38 -> V_66 ) , V_4 ) ;
if ( V_54 < 0 ) {
F_44 ( V_4 , V_40 ,
L_22 , V_75 ) ;
V_54 = - V_60 ;
goto V_112;
}
V_54 = F_25 ( V_38 , V_114 ) ;
if ( V_54 < 0 )
goto V_112;
V_77 = V_113 ;
}
V_54 = F_43 ( & V_38 -> V_66 , V_1 , F_1 ,
V_77 , F_27 ( & V_38 -> V_66 ) , V_4 ) ;
if ( V_54 < 0 ) {
F_44 ( V_4 , V_40 ,
L_22 , V_1 ) ;
V_54 = - V_60 ;
goto V_112;
}
if ( F_24 ( V_6 -> V_14 , V_9 -> V_82 ,
V_9 -> V_83 , V_9 -> V_83 ) ) {
F_44 ( V_4 , V_40 ,
L_23 ) ;
V_54 = - V_60 ;
goto V_112;
}
F_15 ( V_4 ) ;
F_45 ( & V_38 -> V_66 , NULL ) ;
return 0 ;
V_112:
F_46 ( & V_38 -> V_66 ) ;
V_111:
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
static int F_51 ( struct V_115 * V_66 )
{
F_52 ( L_25 ) ;
return - V_116 ;
}
static int F_53 ( struct V_62 * V_38 )
{
F_54 ( V_38 -> V_66 . V_79 , V_117 ,
NULL , & V_38 -> V_66 ) ;
return 0 ;
}
static T_1 F_55 ( int V_1 , void * V_2 )
{
T_1 V_118 = V_29 ;
struct V_119 * V_120 = V_2 ;
struct V_121 * V_6 = V_120 -> V_7 ;
const struct V_122 * V_9 = V_6 -> V_10 ;
if ( V_1 == V_6 -> V_123 ) {
if ( V_9 -> V_124 )
F_56 ( V_9 -> V_124 , V_6 -> V_125 ) ;
F_57 ( V_120 , 0 , 0 , V_6 -> V_126 ) ;
V_118 = V_28 ;
} else if ( V_1 == V_6 -> V_127 ) {
if ( V_9 -> V_128 )
F_56 ( V_9 -> V_128 , V_6 -> V_125 ) ;
F_58 ( V_120 , 0 , 0 , V_6 -> V_126 ) ;
F_3 ( L_26 ) ;
V_118 = V_28 ;
} else {
F_59 ( 1 ) ;
}
return V_118 ;
}
static T_3 F_60 ( struct V_30 * V_30 ,
const char T_4 * V_129 ,
T_5 V_31 , T_6 * V_32 )
{
T_2 * V_34 , V_130 , V_131 ;
int V_132 = 0 ;
T_9 V_133 ;
unsigned long V_134 ;
struct V_119 * V_135 = V_30 -> V_33 ;
struct V_121 * V_6 = V_135 -> V_7 ;
const struct V_122 * V_9 = V_6 -> V_10 ;
void * V_136 = V_135 -> V_66 ;
if ( ! V_129 || F_61 ( V_133 , V_129 ) )
return - V_137 ;
if ( ! V_9 -> V_138 )
return - V_42 ;
V_34 = V_9 -> V_138 ( V_9 -> V_139 , & V_136 ) ;
if ( ! V_34 ) {
F_9 ( V_40 , V_140 ,
L_3 ) ;
return - V_42 ;
}
if ( V_133 == V_141 )
V_131 = V_9 -> V_45 ;
else
V_131 = V_9 -> V_44 ;
F_9 ( V_46 , V_140 ,
L_27 , V_131 ) ;
F_62 ( V_134 ) ;
for ( V_130 = 0 ; V_130 < ( V_9 -> V_139 / sizeof( * V_34 ) ) ; V_130 ++ ) {
F_14 () ;
if ( F_13 ( V_34 [ V_130 ] ) )
V_132 = - 1 ;
F_56 ( V_131 , ( V_6 -> V_125 + V_9 -> V_142 ) ) ;
F_56 ( V_9 -> V_143 , ( V_6 -> V_125 +
V_9 -> V_142 ) ) ;
V_34 [ V_130 ] = V_130 ;
}
F_12 () ;
F_63 ( V_134 ) ;
if ( V_132 )
F_9 ( V_40 , V_140 , L_28 ) ;
for ( V_130 = 0 ; V_130 < V_144 ; V_130 ++ )
if ( F_13 ( V_34 [ V_130 ] ) != V_130 )
F_9 ( V_40 , V_140 ,
L_29 ) ;
if ( V_9 -> V_145 )
V_9 -> V_145 ( V_34 , V_9 -> V_139 , V_136 ) ;
return V_31 ;
}
static void F_64 ( struct V_119 * V_135 ,
const struct V_122 * V_9 )
{
struct V_121 * V_6 = V_135 -> V_7 ;
if ( ! F_16 ( V_47 ) )
return;
V_6 -> V_146 = F_65 ( V_6 -> V_126 ) ;
if ( ! V_6 -> V_146 )
return;
if ( ! F_17 ( L_7 , V_49 ,
V_6 -> V_146 , V_135 ,
V_9 -> V_147 ) )
F_66 ( V_6 -> V_146 ) ;
}
static int F_67 ( struct V_62 * V_38 )
{
struct V_119 * V_120 ;
struct V_121 * V_6 ;
struct V_53 * V_148 ;
int V_54 = 0 ;
struct V_51 * V_52 = V_38 -> V_66 . V_79 ;
char * V_149 = ( char * ) V_52 -> V_150 ;
static int V_151 ;
if ( ! F_41 ( & V_38 -> V_66 , NULL , V_39 ) ) {
F_9 ( V_40 , V_140 ,
L_30 ) ;
return - V_42 ;
}
V_148 = F_68 ( V_38 , V_152 , 0 ) ;
if ( ! V_148 ) {
F_9 ( V_40 , V_140 ,
L_31 ) ;
V_54 = - V_60 ;
goto V_153;
}
if ( ! F_69 ( & V_38 -> V_66 , V_148 -> V_154 , F_21 ( V_148 ) ,
F_27 ( & V_38 -> V_66 ) ) ) {
F_9 ( V_40 , V_140 ,
L_32 , V_149 ) ;
V_54 = - V_67 ;
goto V_153;
}
V_120 = F_70 ( sizeof( * V_6 ) , V_149 ,
1 , V_149 , 1 , 0 , NULL , 0 ,
V_151 ++ ) ;
if ( ! V_120 ) {
F_9 ( V_40 , V_140 ,
L_33 , V_149 ) ;
V_54 = - V_42 ;
goto V_153;
}
V_6 = V_120 -> V_7 ;
V_120 -> V_66 = & V_38 -> V_66 ;
F_40 ( V_38 , V_120 ) ;
V_6 -> V_126 = V_149 ;
V_6 -> V_125 = F_71 ( & V_38 -> V_66 , V_148 -> V_154 , F_21 ( V_148 ) ) ;
if ( ! V_6 -> V_125 )
goto V_155;
V_6 -> V_10 = F_36 ( V_117 , V_52 ) -> V_10 ;
if ( V_6 -> V_10 -> V_156 ) {
V_54 = V_6 -> V_10 -> V_156 ( V_6 ) ;
if ( V_54 )
goto V_155;
}
V_6 -> V_123 = F_37 ( V_38 , 0 ) ;
V_54 = F_43 ( & V_38 -> V_66 , V_6 -> V_123 ,
F_55 ,
0 , F_27 ( & V_38 -> V_66 ) , V_120 ) ;
if ( V_54 )
goto V_155;
V_6 -> V_127 = F_37 ( V_38 , 1 ) ;
V_54 = F_43 ( & V_38 -> V_66 , V_6 -> V_127 ,
F_55 ,
0 , F_27 ( & V_38 -> V_66 ) , V_120 ) ;
if ( V_54 )
goto V_155;
V_120 -> V_96 = L_34 ;
V_120 -> F_27 = V_6 -> V_126 ;
V_54 = F_72 ( V_120 ) ;
if ( V_54 )
goto V_155;
F_64 ( V_120 , V_6 -> V_10 ) ;
F_45 ( & V_38 -> V_66 , NULL ) ;
return 0 ;
V_155:
F_73 ( V_120 ) ;
V_153:
F_47 ( & V_38 -> V_66 , NULL ) ;
F_9 ( V_40 , V_140 ,
L_35 , V_149 , V_54 ) ;
return V_54 ;
}
static int F_74 ( struct V_62 * V_38 )
{
struct V_119 * V_120 = F_50 ( V_38 ) ;
struct V_121 * V_6 = V_120 -> V_7 ;
F_66 ( V_6 -> V_146 ) ;
F_75 ( & V_38 -> V_66 ) ;
F_73 ( V_120 ) ;
return 0 ;
}
static int T_10
F_76 ( struct V_121 * V_115 )
{
void T_8 * V_125 = V_115 -> V_125 ;
const struct V_122 * V_157 = V_115 -> V_10 ;
if ( F_77 ( V_125 + V_157 -> V_158 ) & V_157 -> V_143 )
return 0 ;
F_9 ( V_40 , V_140 ,
L_36 ,
V_115 -> V_126 ) ;
return - V_60 ;
}
static T_1 T_10 F_78 ( int V_1 , void * V_2 )
{
struct V_121 * V_120 = V_2 ;
void T_8 * V_125 = V_120 -> V_125 ;
if ( V_1 == V_120 -> V_123 ) {
F_56 ( V_159 ,
V_125 + V_160 ) ;
F_57 ( V_120 -> V_161 , 0 , 0 , V_120 -> V_126 ) ;
return V_28 ;
} else if ( V_1 == V_120 -> V_127 ) {
F_56 ( V_162 ,
V_125 + V_160 ) ;
F_58 ( V_120 -> V_161 , 0 , 0 , V_120 -> V_126 ) ;
if ( V_120 -> V_10 -> F_3 )
F_3 ( L_26 ) ;
return V_28 ;
}
F_59 ( 1 ) ;
return V_29 ;
}
static inline int F_79 ( struct V_51 * V_52 )
{
int V_1 ;
const T_2 * V_163 = F_80 ( V_52 , L_37 , NULL ) ;
if ( ! V_163 )
return - V_60 ;
V_1 = F_81 ( V_163 ) ;
return V_1 ;
}
static inline void F_82 ( T_2 V_164 , void T_8 * V_165 )
{
T_2 V_166 = F_77 ( V_165 ) ;
V_166 |= V_164 ;
F_56 ( V_166 , V_165 ) ;
}
static inline void F_83 ( T_2 V_164 , void T_8 * V_165 )
{
T_2 V_166 = F_77 ( V_165 ) ;
V_166 &= ~ V_164 ;
F_56 ( V_166 , V_165 ) ;
}
static inline int F_84 ( T_2 V_164 , void T_8 * V_165 )
{
T_2 V_166 = F_77 ( V_165 ) ;
return ( V_166 & V_164 ) ? 1 : 0 ;
}
static int T_10 F_85 ( void T_8 * V_165 , int V_167 )
{
int V_168 = V_169 ;
T_2 V_170 , V_171 , V_172 ;
int V_55 = 0 ;
if ( V_167 ) {
V_170 = V_173 ;
V_171 = V_174 ;
V_172 = V_175 ;
} else {
V_170 = V_176 ;
V_171 = V_177 ;
V_172 = V_178 ;
}
F_82 ( V_170 , ( V_165 + V_179 ) ) ;
while ( V_168 -- ) {
if ( F_84 ( V_171 ,
( V_165 + V_180 ) ) )
break;
F_86 ( 1 ) ;
}
if ( V_168 < 0 )
V_55 = - V_67 ;
F_56 ( V_172 , ( V_165 + V_160 ) ) ;
return V_55 ;
}
static T_11 int T_10
F_87 ( struct V_51 * V_52 , T_2 V_181 ,
T_2 V_182 , bool V_183 )
{
int V_55 = 0 ;
void T_8 * V_184 ;
struct V_57 * V_185 ;
char * V_149 ;
struct V_51 * V_186 ;
V_149 = ( char * ) V_52 -> V_150 ;
V_186 = F_88 ( V_52 ) ;
V_185 = F_34 ( V_186 ,
L_38 ) ;
F_89 ( V_186 ) ;
if ( F_35 ( V_185 ) ) {
F_9 ( V_40 , V_140 ,
L_39 ) ;
return - V_60 ;
}
V_184 = F_90 ( V_52 , 0 ) ;
if ( ! V_184 ) {
F_9 ( V_40 , V_140 ,
L_40 , V_149 ) ;
return - V_60 ;
}
F_5 ( V_185 , V_187 , V_181 ) ;
F_56 ( V_188 ,
( V_184 + V_189 ) ) ;
F_83 ( V_182 ,
( V_184 + V_179 ) ) ;
F_12 () ;
V_55 = F_85 ( V_184 , 0 ) ;
if ( V_55 ) {
F_9 ( V_40 , V_140 ,
L_41 , V_149 ) ;
goto V_190;
}
if ( V_183 ) {
V_55 = F_85 ( V_184 , 1 ) ;
if ( V_55 ) {
F_9 ( V_40 , V_140 ,
L_42 ,
V_149 ) ;
goto V_190;
}
}
F_5 ( V_185 , V_191 ,
V_192 ) ;
F_82 ( V_182 , ( V_184 +
V_179 ) ) ;
F_56 ( V_188 ,
( V_184 + V_193 ) ) ;
F_5 ( V_185 , V_194 , V_181 ) ;
F_12 () ;
V_190:
F_30 ( V_184 ) ;
return V_55 ;
}
static int F_91 ( void )
{
return F_92 ( L_43 ) ;
}
static int T_11 T_10 F_93 ( char * V_195 )
{
int V_1 ;
struct V_51 * V_196 , * V_52 ;
if ( ! F_91 () )
return - V_60 ;
V_52 = F_94 ( NULL , NULL ,
L_44 ) ;
if ( ! V_52 ) {
F_9 ( V_40 , V_140 , L_45 ) ;
return - V_60 ;
}
F_95 (np, child) {
const struct V_69 * V_197 ;
const struct V_122 * V_157 ;
if ( ! F_96 ( V_196 ) )
continue;
if ( ! F_97 ( V_196 , V_195 ) )
continue;
if ( F_98 ( V_196 ) )
continue;
V_1 = F_79 ( V_196 ) ;
if ( V_1 < 0 )
continue;
V_197 = F_36 ( V_198 , V_196 ) ;
if ( F_99 ( V_197 ) )
continue;
V_157 = V_197 -> V_10 ;
if ( ! V_157 )
continue;
F_87 ( V_196 , F_100 ( V_1 ) ,
V_157 -> V_143 , 0 ) ;
}
F_89 ( V_52 ) ;
return 0 ;
}
static void * F_101 ( T_5 V_87 , void * * V_199 )
{
struct V_51 * V_52 ;
struct V_200 * V_201 ;
void * V_202 ;
V_52 = F_94 ( NULL , NULL , L_46 ) ;
if ( ! V_52 )
return NULL ;
V_201 = F_102 ( V_52 , L_47 , 0 ) ;
F_89 ( V_52 ) ;
if ( ! V_201 )
return NULL ;
V_202 = ( void * ) F_103 ( V_201 , V_87 ) ;
if ( ! V_202 )
return NULL ;
memset ( V_202 , 0 , V_87 ) ;
F_12 () ;
* V_199 = V_201 ;
return V_202 ;
}
static void F_104 ( void * V_203 , T_5 V_87 , void * V_199 )
{
F_105 ( (struct V_200 * ) V_199 , ( T_2 ) V_203 , V_87 ) ;
}
static void * F_106 ( T_5 V_87 , void * * V_199 )
{
struct V_115 * V_66 = * V_199 ;
void * V_34 = F_107 ( V_66 , V_87 , V_39 ) ;
if ( ! V_34 )
return NULL ;
F_12 () ;
F_108 () ;
return V_34 ;
}
static void F_109 ( void * V_203 , T_5 V_87 , void * V_199 )
{
struct V_115 * V_66 = V_199 ;
if ( V_66 && V_203 )
F_110 ( V_66 , V_203 ) ;
}
static int F_111 ( struct V_121 * V_115 )
{
void T_8 * V_125 = V_115 -> V_125 ;
const struct V_122 * V_157 = V_115 -> V_10 ;
if ( ( F_77 ( V_125 ) & V_157 -> V_143 ) ==
V_157 -> V_143 )
return 0 ;
F_9 ( V_40 , V_140 ,
L_48 ) ;
return - V_60 ;
}
static T_1 F_112 ( int V_1 , void * V_2 )
{
struct V_121 * V_120 = V_2 ;
if ( V_1 == V_120 -> V_123 ) {
F_5 ( V_120 -> V_204 -> V_185 ,
V_205 ,
V_206 ) ;
F_57 ( V_120 -> V_161 , 0 , 0 , V_120 -> V_126 ) ;
return V_28 ;
} else if ( V_1 == V_120 -> V_127 ) {
F_5 ( V_120 -> V_204 -> V_185 ,
V_205 ,
V_207 ) ;
F_58 ( V_120 -> V_161 , 0 , 0 , V_120 -> V_126 ) ;
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
static int F_118 ( struct V_121 * V_115 )
{
struct V_119 * V_120 ;
struct V_121 * V_208 ;
char * V_149 = L_54 ;
int V_209 , V_210 ;
struct V_51 * V_52 ;
const struct V_122 * V_157 = & V_211 ;
V_210 = F_76 ( V_115 ) ;
if ( V_210 )
return V_210 ;
V_52 = F_94 ( NULL , NULL , L_55 ) ;
if ( ! V_52 ) {
F_9 ( V_212 , V_140 , L_56 ) ;
return - V_60 ;
}
V_209 = F_119 () ;
V_120 = F_70 ( sizeof( * V_208 ) , V_149 , 1 ,
V_149 , 1 , 0 , NULL , 0 , V_209 ) ;
if ( ! V_120 ) {
F_9 ( V_40 , V_140 ,
L_57 ,
V_149 ) ;
return - V_42 ;
}
V_208 = V_120 -> V_7 ;
* V_208 = * V_115 ;
if ( ! F_41 ( & V_208 -> V_213 , F_118 , V_39 ) )
return - V_42 ;
V_208 -> V_126 = V_149 ;
V_208 -> V_209 = V_209 ;
V_208 -> V_161 = V_120 ;
V_208 -> V_10 = V_157 ;
V_120 -> V_66 = & V_208 -> V_213 ;
V_120 -> V_25 = L_34 ;
V_120 -> V_96 = V_149 ;
V_120 -> F_27 = V_149 ;
V_208 -> V_123 = F_120 ( V_52 , 2 ) ;
if ( ! V_208 -> V_123 ) {
F_9 ( V_40 , V_140 , L_58 ) ;
V_210 = - V_60 ;
goto V_214;
}
V_210 = F_43 ( & V_208 -> V_213 , V_208 -> V_123 ,
V_157 -> V_215 ,
V_216 | V_217 ,
V_149 , V_208 ) ;
if ( V_210 ) {
F_9 ( V_40 , V_140 , L_59 ) ;
goto V_214;
}
V_208 -> V_127 = F_120 ( V_52 , 3 ) ;
if ( ! V_208 -> V_127 ) {
F_9 ( V_40 , V_140 , L_60 ) ;
V_210 = - V_60 ;
goto V_214;
}
V_210 = F_43 ( & V_208 -> V_213 , V_208 -> V_127 ,
V_157 -> V_215 ,
V_216 | V_217 ,
V_149 , V_208 ) ;
if ( V_210 ) {
F_9 ( V_40 , V_140 , L_61 ) ;
goto V_214;
}
V_210 = F_72 ( V_120 ) ;
if ( V_210 ) {
F_9 ( V_40 , V_140 ,
L_62 ) ;
V_210 = - V_42 ;
goto V_214;
}
F_64 ( V_120 , V_157 ) ;
F_121 ( & V_208 -> V_218 , & V_208 -> V_204 -> V_219 ) ;
F_122 ( & V_208 -> V_213 , F_118 ) ;
return 0 ;
V_214:
F_73 ( V_120 ) ;
F_47 ( & V_208 -> V_213 , F_118 ) ;
F_9 ( V_40 , V_140 ,
L_35 , V_149 , V_210 ) ;
return V_210 ;
}
static T_1 F_123 ( int V_1 , void * V_2 )
{
struct V_121 * V_220 = V_2 ;
void T_8 * V_125 = V_220 -> V_125 ;
const struct V_122 * V_9 = V_220 -> V_10 ;
if ( V_1 == V_220 -> V_123 ) {
F_56 ( V_9 -> V_124 ,
V_125 + V_160 ) ;
F_57 ( V_220 -> V_161 , 0 , 0 , V_220 -> V_126 ) ;
return V_28 ;
} else if ( V_1 == V_220 -> V_127 ) {
F_56 ( V_9 -> V_128 ,
V_125 + V_160 ) ;
F_58 ( V_220 -> V_161 , 0 , 0 , V_220 -> V_126 ) ;
return V_28 ;
}
F_124 ( 1 , L_63 , V_1 ) ;
return V_29 ;
}
static int T_11 F_125 ( void )
{
int V_210 = - V_60 ;
struct V_51 * V_196 ;
if ( ! F_91 () )
return - V_60 ;
V_196 = F_94 ( NULL , NULL , L_55 ) ;
if ( ! V_196 ) {
F_9 ( V_212 , V_140 , L_56 ) ;
return - V_60 ;
}
if ( ! F_96 ( V_196 ) )
goto exit;
if ( F_98 ( V_196 ) )
goto exit;
V_210 = F_87 ( V_196 , V_221 ,
V_222 . V_143 , 1 ) ;
exit:
F_89 ( V_196 ) ;
return V_210 ;
}
static T_3 F_126 ( struct V_30 * V_30 ,
const char T_4 * V_129 ,
T_5 V_31 , T_6 * V_32 )
{
struct V_119 * V_135 = V_30 -> V_33 ;
struct V_121 * V_6 = V_135 -> V_7 ;
const struct V_122 * V_9 = V_6 -> V_10 ;
void T_8 * V_223 = ( V_6 -> V_125 + V_9 -> V_142 ) ;
unsigned long V_134 ;
T_9 V_133 ;
if ( ! V_129 || F_61 ( V_133 , V_129 ) )
return - V_137 ;
F_62 ( V_134 ) ;
if ( V_133 == V_141 )
F_56 ( V_9 -> V_45 , V_223 ) ;
else
F_56 ( V_9 -> V_44 , V_223 ) ;
F_12 () ;
F_63 ( V_134 ) ;
return V_31 ;
}
static void F_127 ( struct V_224 * V_225 )
{
int V_226 , V_227 , V_228 , V_229 ;
struct V_230 * V_204 = F_128 ( V_225 ) ;
struct V_231 * V_232 = F_129 ( V_225 ) ;
int V_1 = F_130 ( V_225 ) ;
V_226 = ( V_1 == V_204 -> V_127 ) ? 1 : 0 ;
V_228 = V_226 ? V_233 :
V_234 ;
F_131 ( V_232 , V_225 ) ;
F_2 ( V_204 -> V_185 , V_228 , & V_229 ) ;
F_132 (bit, (unsigned long *)&irq_status, 32 ) {
V_1 = F_133 ( V_204 -> V_235 , V_226 * 32 + V_227 ) ;
if ( V_1 )
F_134 ( V_1 ) ;
}
F_135 ( V_232 , V_225 ) ;
}
static int F_98 ( struct V_51 * V_52 )
{
struct V_51 * V_236 ;
int V_55 = 0 ;
V_236 = F_136 ( V_52 , L_64 , 0 ) ;
if ( V_236 && ! F_96 ( V_236 ) )
V_55 = - V_60 ;
F_89 ( V_236 ) ;
return V_55 ;
}
static int F_137 ( struct V_230 * V_204 ,
struct V_51 * V_52 )
{
struct V_119 * V_120 ;
struct V_121 * V_208 ;
char * V_149 = ( char * ) V_52 -> V_150 ;
struct V_53 V_54 ;
int V_209 ;
int V_210 = 0 ;
const struct V_122 * V_157 ;
const struct V_69 * V_197 =
F_36 ( V_198 , V_52 ) ;
if ( F_99 ( V_197 ) )
return - V_60 ;
V_157 = V_197 -> V_10 ;
if ( F_99 ( V_157 ) )
return - V_60 ;
if ( F_98 ( V_52 ) )
return - V_60 ;
if ( ! F_41 ( V_204 -> V_66 , F_137 , V_39 ) )
return - V_42 ;
V_210 = F_20 ( V_52 , 0 , & V_54 ) ;
if ( V_210 < 0 ) {
F_9 ( V_40 , V_140 ,
L_65 , V_149 ) ;
goto V_237;
}
V_209 = F_119 () ;
V_120 = F_70 ( sizeof( * V_208 ) , V_149 ,
1 , V_149 , 1 , 0 , NULL , 0 ,
V_209 ) ;
if ( ! V_120 ) {
F_9 ( V_40 , V_140 ,
L_33 , V_149 ) ;
V_210 = - V_42 ;
goto V_237;
}
V_208 = V_120 -> V_7 ;
V_120 -> V_66 = V_204 -> V_66 ;
V_208 -> V_126 = V_149 ;
V_208 -> V_209 = V_209 ;
V_208 -> V_204 = V_204 ;
V_208 -> V_161 = V_120 ;
V_208 -> V_10 = V_157 ;
V_208 -> V_213 = * V_204 -> V_66 ;
V_120 -> V_66 = & V_208 -> V_213 ;
V_120 -> V_25 = L_34 ;
V_120 -> V_96 = V_149 ;
V_120 -> F_27 = V_149 ;
V_208 -> V_125 = F_138 ( V_204 -> V_66 , & V_54 ) ;
if ( F_35 ( V_208 -> V_125 ) ) {
V_210 = F_139 ( V_208 -> V_125 ) ;
goto V_238;
}
if ( V_208 -> V_10 -> V_156 ) {
V_210 = V_208 -> V_10 -> V_156 ( V_208 ) ;
if ( V_210 )
goto V_238;
}
V_208 -> V_123 = F_120 ( V_52 , 0 ) ;
if ( ! V_208 -> V_123 ) {
F_9 ( V_40 , V_140 , L_66 ) ;
V_210 = - V_60 ;
goto V_238;
}
V_210 = F_43 ( V_204 -> V_66 , V_208 -> V_123 , V_157 -> V_215 ,
V_216 | V_217 ,
V_149 , V_208 ) ;
if ( V_210 ) {
F_9 ( V_40 , V_140 , L_67 ) ;
goto V_238;
}
V_208 -> V_127 = F_120 ( V_52 , 1 ) ;
if ( ! V_208 -> V_127 ) {
F_9 ( V_40 , V_140 , L_68 ) ;
V_210 = - V_60 ;
goto V_238;
}
V_210 = F_43 ( V_204 -> V_66 , V_208 -> V_127 , V_157 -> V_215 ,
V_216 | V_217 ,
V_149 , V_208 ) ;
if ( V_210 ) {
F_9 ( V_40 , V_140 , L_69 ) ;
goto V_238;
}
V_210 = F_72 ( V_120 ) ;
if ( V_210 ) {
F_140 ( V_204 -> V_66 , L_70 ) ;
V_210 = - V_42 ;
goto V_238;
}
F_64 ( V_120 , V_157 ) ;
F_121 ( & V_208 -> V_218 , & V_204 -> V_219 ) ;
F_122 ( V_204 -> V_66 , F_137 ) ;
return 0 ;
V_238:
F_73 ( V_120 ) ;
V_237:
F_47 ( V_204 -> V_66 , NULL ) ;
F_9 ( V_40 , V_140 ,
L_35 , V_149 , V_210 ) ;
return V_210 ;
}
static void F_141 ( struct V_239 * V_240 )
{
struct V_230 * V_204 = F_142 ( V_240 ) ;
F_5 ( V_204 -> V_185 , V_187 ,
F_100 ( V_240 -> V_241 ) ) ;
}
static void F_143 ( struct V_239 * V_240 )
{
struct V_230 * V_204 = F_142 ( V_240 ) ;
F_5 ( V_204 -> V_185 , V_194 ,
F_100 ( V_240 -> V_241 ) ) ;
}
static int F_144 ( struct V_242 * V_240 , unsigned int V_1 ,
T_12 V_241 )
{
struct V_230 * V_204 = V_240 -> V_243 ;
F_145 ( V_1 , & V_204 -> V_231 , V_244 ) ;
F_146 ( V_1 , V_204 ) ;
F_147 ( V_1 ) ;
return 0 ;
}
static int F_148 ( struct V_62 * V_38 )
{
struct V_230 * V_204 ;
struct V_51 * V_196 ;
V_204 = F_107 ( & V_38 -> V_66 , sizeof( * V_204 ) , V_39 ) ;
if ( ! V_204 )
return - V_42 ;
V_204 -> V_66 = & V_38 -> V_66 ;
F_40 ( V_38 , V_204 ) ;
F_149 ( & V_204 -> V_219 ) ;
V_204 -> V_185 = F_34 ( V_38 -> V_66 . V_79 ,
L_38 ) ;
if ( F_35 ( V_204 -> V_185 ) ) {
F_9 ( V_40 , V_140 ,
L_39 ) ;
return F_139 ( V_204 -> V_185 ) ;
}
V_204 -> V_231 . V_150 = V_38 -> V_66 . V_79 -> V_150 ;
V_204 -> V_231 . V_181 = F_141 ;
V_204 -> V_231 . V_245 = F_143 ;
V_204 -> V_235 = F_150 ( V_38 -> V_66 . V_79 , 64 ,
& V_246 , V_204 ) ;
if ( ! V_204 -> V_235 ) {
F_140 ( & V_38 -> V_66 , L_71 ) ;
return - V_42 ;
}
V_204 -> V_123 = F_37 ( V_38 , 0 ) ;
if ( V_204 -> V_123 < 0 ) {
F_140 ( & V_38 -> V_66 , L_67 ) ;
return V_204 -> V_123 ;
}
F_151 ( V_204 -> V_123 ,
F_127 ,
V_204 ) ;
V_204 -> V_127 = F_37 ( V_38 , 1 ) ;
if ( V_204 -> V_127 < 0 ) {
F_140 ( & V_38 -> V_66 , L_69 ) ;
return V_204 -> V_127 ;
}
F_151 ( V_204 -> V_127 ,
F_127 ,
V_204 ) ;
F_95 (pdev->dev.of_node, child) {
if ( ! F_96 ( V_196 ) )
continue;
if ( F_97 ( V_196 , L_72 ) ||
F_97 ( V_196 , L_73 ) ||
F_97 ( V_196 , L_49 ) ||
F_97 ( V_196 , L_50 ) ||
F_97 ( V_196 , L_51 ) ||
F_97 ( V_196 , L_52 ) ||
F_97 ( V_196 , L_53 ) ||
F_97 ( V_196 , L_55 ) )
F_137 ( V_204 , V_196 ) ;
else if ( F_97 ( V_196 , L_74 ) )
F_54 ( V_38 -> V_66 . V_79 ,
V_78 ,
NULL , & V_38 -> V_66 ) ;
}
return 0 ;
}
