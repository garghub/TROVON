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
F_5 ( V_6 -> V_14 , V_9 -> V_43 ,
( V_37 | V_9 -> V_45 ) ) ;
} else {
F_9 ( V_46 , V_41 ,
L_5 ) ;
F_5 ( V_6 -> V_14 , V_9 -> V_43 ,
( V_37 | V_9 -> V_44 ) ) ;
}
V_34 [ 0 ] = 0x5A5A5A5A ;
V_34 [ 1 ] = 0xA5A5A5A5 ;
F_5 ( V_6 -> V_14 , V_9 -> V_43 , V_37 ) ;
F_10 () ;
V_36 = F_11 ( V_34 [ 0 ] ) ;
V_37 = F_11 ( V_34 [ 1 ] ) ;
F_12 () ;
F_9 ( V_46 , V_41 , L_6 ,
V_36 , V_37 ) ;
F_8 ( V_4 -> V_38 , 16 , V_34 , V_35 ) ;
return V_31 ;
}
static void F_13 ( struct V_3 * V_4 )
{
if ( ! F_14 ( V_47 ) )
return;
if ( ! V_4 -> V_48 )
return;
F_15 ( L_7 , V_49 , V_4 -> V_48 , V_4 ,
& V_50 ) ;
}
static unsigned long F_16 ( void )
{
struct V_51 * V_52 = NULL ;
const unsigned int * V_36 , * V_53 ;
int V_54 , V_55 , V_56 ;
unsigned long V_57 , V_58 , V_59 = 0 ;
F_17 (np, L_8 ) {
V_56 = F_18 ( V_52 ) ;
V_55 = F_19 ( V_52 ) ;
V_36 = ( const unsigned int * ) F_20 ( V_52 , L_9 , & V_54 ) ;
V_53 = V_36 + ( V_54 / sizeof( T_2 ) ) ;
V_59 = 0 ;
do {
V_57 = F_21 ( V_36 , V_56 ) ;
V_36 += V_56 ;
V_58 = F_21 ( V_36 , V_55 ) ;
V_36 += V_55 ;
V_59 += V_58 ;
} while ( V_36 < V_53 );
}
F_22 ( 0 , L_10 , V_59 ) ;
return V_59 ;
}
static int F_23 ( struct V_60 * V_14 )
{
if ( F_24 ( V_14 , V_61 ,
V_62 , V_62 ) ) {
F_9 ( V_40 , V_41 ,
L_11 ) ;
return - V_63 ;
}
if ( F_5 ( V_14 , V_64 , 1 ) ) {
F_9 ( V_40 , V_41 ,
L_12 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_25 ( struct V_65 * V_38 , T_2 V_66 )
{
void T_8 * V_67 ;
int V_68 = 0 ;
if ( ! F_26 ( V_69 , sizeof( T_2 ) ,
F_27 ( & V_38 -> V_70 ) ) ) {
F_9 ( V_40 , V_41 ,
L_13 ) ;
return - V_71 ;
}
V_67 = F_28 ( V_69 , sizeof( T_2 ) ) ;
if ( ! V_67 ) {
F_9 ( V_40 , V_41 ,
L_14 ) ;
V_68 = - V_42 ;
goto V_72;
}
F_29 ( V_66 , V_67 ) ;
F_30 ( V_67 ) ;
V_72:
F_31 ( V_69 , sizeof( T_2 ) ) ;
return V_68 ;
}
static int F_32 ( struct V_65 * V_38 )
{
const struct V_73 * V_74 ;
struct V_75 V_76 [ 2 ] ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
const struct V_8 * V_9 ;
struct V_60 * V_14 ;
struct V_77 * V_78 ;
T_2 V_37 ;
int V_1 , V_79 , V_80 = 0 ;
unsigned long V_81 , V_82 = 0 ;
V_74 = F_33 ( V_83 , & V_38 -> V_70 ) ;
if ( ! V_74 )
return - V_63 ;
V_14 = F_34 ( V_38 -> V_70 . V_84 ,
L_15 ) ;
if ( F_35 ( V_14 ) ) {
F_9 ( V_40 , V_41 ,
L_16 ) ;
return - V_63 ;
}
V_9 = F_36 ( V_83 ,
V_38 -> V_70 . V_84 ) -> V_10 ;
if ( F_2 ( V_14 , V_9 -> V_85 , & V_37 ) ||
( ( V_37 & V_9 -> V_86 ) != V_9 -> V_86 ) ) {
F_9 ( V_40 , V_41 ,
L_17 , V_37 ) ;
return - V_63 ;
}
V_81 = F_16 () ;
if ( ! V_81 ) {
F_9 ( V_40 , V_41 , L_18 ) ;
return - V_63 ;
}
if ( F_24 ( V_14 , V_9 -> V_87 ,
V_9 -> V_88 , 0 ) ) {
F_9 ( V_40 , V_41 ,
L_19 ) ;
return - V_63 ;
}
if ( F_24 ( V_14 , V_9 -> V_89 ,
V_9 -> V_90 ,
V_9 -> V_90 ) ) {
F_9 ( V_40 , V_41 ,
L_20 ) ;
return - V_63 ;
}
if ( F_24 ( V_14 , V_9 -> V_89 ,
V_9 -> V_90 , 0 ) ) {
F_9 ( V_40 , V_41 ,
L_20 ) ;
return - V_63 ;
}
V_1 = F_37 ( V_38 , 0 ) ;
if ( V_1 < 0 ) {
F_9 ( V_40 , V_41 ,
L_21 , V_1 ) ;
return - V_63 ;
}
V_79 = F_37 ( V_38 , 1 ) ;
V_76 [ 0 ] . type = V_91 ;
V_76 [ 0 ] . V_58 = 1 ;
V_76 [ 0 ] . V_92 = true ;
V_76 [ 1 ] . type = V_93 ;
V_76 [ 1 ] . V_58 = 1 ;
V_76 [ 1 ] . V_92 = false ;
V_4 = F_38 ( 0 , F_39 ( V_76 ) , V_76 ,
sizeof( struct V_5 ) ) ;
if ( ! V_4 )
return - V_42 ;
V_4 -> V_38 = & V_38 -> V_70 ;
V_6 = V_4 -> V_7 ;
V_6 -> V_14 = V_14 ;
V_6 -> V_10 = V_9 ;
F_40 ( V_38 , V_4 ) ;
if ( ! F_41 ( & V_38 -> V_70 , NULL , V_39 ) ) {
F_9 ( V_40 , V_41 ,
L_22 ) ;
V_80 = - V_42 ;
goto free;
}
V_4 -> V_94 = V_95 ;
V_4 -> V_96 = V_97 | V_98 ;
V_4 -> V_99 = V_98 ;
V_4 -> V_100 = V_101 ;
V_4 -> V_102 = V_103 ;
V_4 -> V_25 = F_27 ( & V_38 -> V_70 ) ;
V_4 -> V_104 = V_105 ;
V_4 -> F_27 = F_27 ( & V_38 -> V_70 ) ;
V_78 = * V_4 -> V_106 ;
V_78 -> V_107 = ( ( V_81 - 1 ) >> V_23 ) + 1 ;
V_78 -> V_108 = 8 ;
V_78 -> V_109 = V_110 ;
V_78 -> V_111 = V_112 ;
V_78 -> V_113 = V_114 ;
V_80 = F_42 ( V_4 ) ;
if ( V_80 < 0 )
goto V_115;
if ( V_79 > 0 ) {
V_80 = F_23 ( V_14 ) ;
if ( V_80 < 0 )
goto V_116;
V_80 = F_43 ( & V_38 -> V_70 , V_79 ,
F_1 ,
V_117 , F_27 ( & V_38 -> V_70 ) , V_4 ) ;
if ( V_80 < 0 ) {
F_44 ( V_4 , V_40 ,
L_23 , V_79 ) ;
V_80 = - V_63 ;
goto V_116;
}
V_80 = F_25 ( V_38 , V_118 ) ;
if ( V_80 < 0 )
goto V_116;
V_82 = V_117 ;
}
V_80 = F_43 ( & V_38 -> V_70 , V_1 , F_1 ,
V_82 , F_27 ( & V_38 -> V_70 ) , V_4 ) ;
if ( V_80 < 0 ) {
F_44 ( V_4 , V_40 ,
L_23 , V_1 ) ;
V_80 = - V_63 ;
goto V_116;
}
if ( F_24 ( V_6 -> V_14 , V_9 -> V_87 ,
V_9 -> V_88 , V_9 -> V_88 ) ) {
F_44 ( V_4 , V_40 ,
L_24 ) ;
V_80 = - V_63 ;
goto V_116;
}
F_13 ( V_4 ) ;
F_45 ( & V_38 -> V_70 , NULL ) ;
return 0 ;
V_116:
F_46 ( & V_38 -> V_70 ) ;
V_115:
F_47 ( & V_38 -> V_70 , NULL ) ;
free:
F_48 ( V_4 ) ;
F_9 ( V_40 , V_41 ,
L_25 , V_80 ) ;
return V_80 ;
}
static int F_49 ( struct V_65 * V_38 )
{
struct V_3 * V_4 = F_50 ( V_38 ) ;
F_46 ( & V_38 -> V_70 ) ;
F_48 ( V_4 ) ;
F_40 ( V_38 , NULL ) ;
return 0 ;
}
static int F_51 ( struct V_119 * V_70 )
{
F_52 ( L_26 ) ;
return - V_120 ;
}
static int F_53 ( struct V_65 * V_38 )
{
F_54 ( V_38 -> V_70 . V_84 , V_121 ,
NULL , & V_38 -> V_70 ) ;
return 0 ;
}
static T_1 F_55 ( int V_1 , void * V_2 )
{
T_1 V_122 = V_29 ;
struct V_123 * V_124 = V_2 ;
struct V_125 * V_6 = V_124 -> V_7 ;
const struct V_126 * V_9 = V_6 -> V_10 ;
if ( V_1 == V_6 -> V_127 ) {
if ( V_9 -> V_128 )
F_56 ( V_9 -> V_128 , V_6 -> V_129 ) ;
F_57 ( V_124 , 0 , 0 , V_6 -> V_130 ) ;
V_122 = V_28 ;
} else if ( V_1 == V_6 -> V_131 ) {
if ( V_9 -> V_132 )
F_56 ( V_9 -> V_132 , V_6 -> V_129 ) ;
F_58 ( V_124 , 0 , 0 , V_6 -> V_130 ) ;
F_3 ( L_27 ) ;
V_122 = V_28 ;
} else {
F_59 ( 1 ) ;
}
return V_122 ;
}
static T_3 F_60 ( struct V_30 * V_30 ,
const char T_4 * V_133 ,
T_5 V_31 , T_6 * V_32 )
{
T_2 * V_34 , V_134 , V_135 ;
int V_136 = 0 ;
T_9 V_137 ;
unsigned long V_138 ;
struct V_123 * V_139 = V_30 -> V_33 ;
struct V_125 * V_6 = V_139 -> V_7 ;
const struct V_126 * V_9 = V_6 -> V_10 ;
void * V_140 = V_139 -> V_70 ;
if ( ! V_133 || F_61 ( V_137 , V_133 ) )
return - V_141 ;
if ( ! V_9 -> V_142 )
return - V_42 ;
V_34 = V_9 -> V_142 ( V_9 -> V_143 , & V_140 ) ;
if ( ! V_34 ) {
F_9 ( V_40 , V_144 ,
L_3 ) ;
return - V_42 ;
}
if ( V_137 == V_145 )
V_135 = V_9 -> V_45 ;
else
V_135 = V_9 -> V_44 ;
F_9 ( V_46 , V_144 ,
L_28 , V_135 ) ;
F_62 ( V_138 ) ;
for ( V_134 = 0 ; V_134 < ( V_9 -> V_143 / sizeof( * V_34 ) ) ; V_134 ++ ) {
F_12 () ;
if ( F_11 ( V_34 [ V_134 ] ) )
V_136 = - 1 ;
F_56 ( V_135 , ( V_6 -> V_129 + V_9 -> V_146 ) ) ;
F_56 ( V_9 -> V_147 , ( V_6 -> V_129 +
V_9 -> V_146 ) ) ;
V_34 [ V_134 ] = V_134 ;
}
F_10 () ;
F_63 ( V_138 ) ;
if ( V_136 )
F_9 ( V_40 , V_144 , L_29 ) ;
for ( V_134 = 0 ; V_134 < V_148 ; V_134 ++ )
if ( F_11 ( V_34 [ V_134 ] ) != V_134 )
F_9 ( V_40 , V_144 ,
L_30 ) ;
if ( V_9 -> V_149 )
V_9 -> V_149 ( V_34 , V_9 -> V_143 , V_140 ) ;
return V_31 ;
}
static void F_64 ( struct V_123 * V_139 ,
const struct V_126 * V_9 )
{
struct V_125 * V_6 = V_139 -> V_7 ;
if ( ! F_14 ( V_47 ) )
return;
V_6 -> V_150 = F_65 ( V_6 -> V_130 ) ;
if ( ! V_6 -> V_150 )
return;
if ( ! F_15 ( V_9 -> V_151 , V_49 ,
V_6 -> V_150 , V_139 ,
V_9 -> V_152 ) )
F_66 ( V_6 -> V_150 ) ;
}
static int F_67 ( struct V_65 * V_38 )
{
struct V_123 * V_124 ;
struct V_125 * V_6 ;
struct V_153 * V_154 ;
int V_80 = 0 ;
struct V_51 * V_52 = V_38 -> V_70 . V_84 ;
char * V_155 = ( char * ) V_52 -> V_156 ;
static int V_157 ;
if ( ! F_41 ( & V_38 -> V_70 , NULL , V_39 ) ) {
F_9 ( V_40 , V_144 ,
L_31 ) ;
return - V_42 ;
}
V_154 = F_68 ( V_38 , V_158 , 0 ) ;
if ( ! V_154 ) {
F_9 ( V_40 , V_144 ,
L_32 ) ;
V_80 = - V_63 ;
goto V_159;
}
if ( ! F_69 ( & V_38 -> V_70 , V_154 -> V_57 , F_70 ( V_154 ) ,
F_27 ( & V_38 -> V_70 ) ) ) {
F_9 ( V_40 , V_144 ,
L_33 , V_155 ) ;
V_80 = - V_71 ;
goto V_159;
}
V_124 = F_71 ( sizeof( * V_6 ) , V_155 ,
1 , V_155 , 1 , 0 , NULL , 0 ,
V_157 ++ ) ;
if ( ! V_124 ) {
F_9 ( V_40 , V_144 ,
L_34 , V_155 ) ;
V_80 = - V_42 ;
goto V_159;
}
V_6 = V_124 -> V_7 ;
V_124 -> V_70 = & V_38 -> V_70 ;
F_40 ( V_38 , V_124 ) ;
V_6 -> V_130 = V_155 ;
V_6 -> V_129 = F_72 ( & V_38 -> V_70 , V_154 -> V_57 , F_70 ( V_154 ) ) ;
if ( ! V_6 -> V_129 )
goto V_160;
V_6 -> V_10 = F_36 ( V_121 , V_52 ) -> V_10 ;
if ( V_6 -> V_10 -> V_161 ) {
V_80 = V_6 -> V_10 -> V_161 ( V_6 ) ;
if ( V_80 )
goto V_160;
}
V_6 -> V_127 = F_37 ( V_38 , 0 ) ;
V_80 = F_43 ( & V_38 -> V_70 , V_6 -> V_127 ,
F_55 ,
0 , F_27 ( & V_38 -> V_70 ) , V_124 ) ;
if ( V_80 )
goto V_160;
V_6 -> V_131 = F_37 ( V_38 , 1 ) ;
V_80 = F_43 ( & V_38 -> V_70 , V_6 -> V_131 ,
F_55 ,
0 , F_27 ( & V_38 -> V_70 ) , V_124 ) ;
if ( V_80 )
goto V_160;
V_124 -> V_100 = L_35 ;
V_124 -> F_27 = V_6 -> V_130 ;
V_80 = F_73 ( V_124 ) ;
if ( V_80 )
goto V_160;
F_64 ( V_124 , V_6 -> V_10 ) ;
F_45 ( & V_38 -> V_70 , NULL ) ;
return 0 ;
V_160:
F_74 ( V_124 ) ;
V_159:
F_47 ( & V_38 -> V_70 , NULL ) ;
F_9 ( V_40 , V_144 ,
L_36 , V_155 , V_80 ) ;
return V_80 ;
}
static int F_75 ( struct V_65 * V_38 )
{
struct V_123 * V_124 = F_50 ( V_38 ) ;
struct V_125 * V_6 = V_124 -> V_7 ;
F_66 ( V_6 -> V_150 ) ;
F_76 ( & V_38 -> V_70 ) ;
F_74 ( V_124 ) ;
return 0 ;
}
static int T_10
F_77 ( struct V_125 * V_119 )
{
void T_8 * V_129 = V_119 -> V_129 ;
const struct V_126 * V_162 = V_119 -> V_10 ;
if ( F_78 ( V_129 + V_162 -> V_163 ) & V_162 -> V_147 )
return 0 ;
F_9 ( V_40 , V_144 ,
L_37 ,
V_119 -> V_130 ) ;
return - V_63 ;
}
static T_1 T_10 F_79 ( int V_1 , void * V_2 )
{
struct V_125 * V_124 = V_2 ;
void T_8 * V_129 = V_124 -> V_129 ;
if ( V_1 == V_124 -> V_127 ) {
F_56 ( V_164 ,
V_129 + V_165 ) ;
F_57 ( V_124 -> V_166 , 0 , 0 , V_124 -> V_130 ) ;
return V_28 ;
} else if ( V_1 == V_124 -> V_131 ) {
F_56 ( V_167 ,
V_129 + V_165 ) ;
F_58 ( V_124 -> V_166 , 0 , 0 , V_124 -> V_130 ) ;
if ( V_124 -> V_10 -> F_3 )
F_3 ( L_27 ) ;
return V_28 ;
}
F_59 ( 1 ) ;
return V_29 ;
}
static inline int F_80 ( struct V_51 * V_52 )
{
int V_1 ;
const T_2 * V_168 = F_20 ( V_52 , L_38 , NULL ) ;
if ( ! V_168 )
return - V_63 ;
V_1 = F_81 ( V_168 ) ;
return V_1 ;
}
static inline void F_82 ( T_2 V_169 , void T_8 * V_170 )
{
T_2 V_171 = F_78 ( V_170 ) ;
V_171 |= V_169 ;
F_56 ( V_171 , V_170 ) ;
}
static inline void F_83 ( T_2 V_169 , void T_8 * V_170 )
{
T_2 V_171 = F_78 ( V_170 ) ;
V_171 &= ~ V_169 ;
F_56 ( V_171 , V_170 ) ;
}
static inline int F_84 ( T_2 V_169 , void T_8 * V_170 )
{
T_2 V_171 = F_78 ( V_170 ) ;
return ( V_171 & V_169 ) ? 1 : 0 ;
}
static int T_10 F_85 ( void T_8 * V_170 , int V_172 )
{
int V_173 = V_174 ;
T_2 V_175 , V_176 , V_177 ;
int V_68 = 0 ;
if ( V_172 ) {
V_175 = V_178 ;
V_176 = V_179 ;
V_177 = V_180 ;
} else {
V_175 = V_181 ;
V_176 = V_182 ;
V_177 = V_183 ;
}
F_82 ( V_175 , ( V_170 + V_184 ) ) ;
while ( V_173 -- ) {
if ( F_84 ( V_176 ,
( V_170 + V_185 ) ) )
break;
F_86 ( 1 ) ;
}
if ( V_173 < 0 )
V_68 = - V_71 ;
F_56 ( V_177 , ( V_170 + V_165 ) ) ;
return V_68 ;
}
static T_11 int T_10
F_87 ( struct V_51 * V_52 , T_2 V_186 ,
T_2 V_187 , bool V_188 )
{
int V_68 = 0 ;
void T_8 * V_189 ;
struct V_60 * V_190 ;
char * V_155 ;
struct V_51 * V_191 ;
V_155 = ( char * ) V_52 -> V_156 ;
V_191 = F_88 ( V_52 ) ;
V_190 = F_34 ( V_191 ,
L_39 ) ;
F_89 ( V_191 ) ;
if ( F_35 ( V_190 ) ) {
F_9 ( V_40 , V_144 ,
L_40 ) ;
return - V_63 ;
}
V_189 = F_90 ( V_52 , 0 ) ;
if ( ! V_189 ) {
F_9 ( V_40 , V_144 ,
L_41 , V_155 ) ;
return - V_63 ;
}
F_5 ( V_190 , V_192 , V_186 ) ;
F_56 ( V_193 ,
( V_189 + V_194 ) ) ;
F_83 ( V_187 ,
( V_189 + V_184 ) ) ;
F_10 () ;
V_68 = F_85 ( V_189 , 0 ) ;
if ( V_68 ) {
F_9 ( V_40 , V_144 ,
L_42 , V_155 ) ;
goto V_195;
}
if ( V_188 ) {
V_68 = F_85 ( V_189 , 1 ) ;
if ( V_68 ) {
F_9 ( V_40 , V_144 ,
L_43 ,
V_155 ) ;
goto V_195;
}
}
F_5 ( V_190 , V_196 ,
V_197 ) ;
F_82 ( V_187 , ( V_189 +
V_184 ) ) ;
F_56 ( V_193 ,
( V_189 + V_198 ) ) ;
F_5 ( V_190 , V_199 , V_186 ) ;
F_10 () ;
V_195:
F_30 ( V_189 ) ;
return V_68 ;
}
static int T_11 T_10 F_91 ( char * V_200 )
{
int V_1 ;
struct V_51 * V_201 , * V_52 = F_92 ( NULL , NULL ,
L_44 ) ;
if ( ! V_52 ) {
F_9 ( V_40 , V_144 , L_45 ) ;
return - V_63 ;
}
F_93 (np, child) {
const struct V_73 * V_202 ;
const struct V_126 * V_162 ;
if ( ! F_94 ( V_201 ) )
continue;
if ( ! F_95 ( V_201 , V_200 ) )
continue;
if ( F_96 ( V_201 ) )
continue;
V_1 = F_80 ( V_201 ) ;
if ( V_1 < 0 )
continue;
V_202 = F_36 ( V_203 , V_201 ) ;
if ( F_97 ( V_202 ) )
continue;
V_162 = V_202 -> V_10 ;
if ( ! V_162 )
continue;
F_87 ( V_201 , F_98 ( V_1 ) ,
V_162 -> V_147 , 0 ) ;
}
F_89 ( V_52 ) ;
return 0 ;
}
static void * F_99 ( T_5 V_58 , void * * V_204 )
{
struct V_51 * V_52 ;
struct V_205 * V_206 ;
void * V_207 ;
V_52 = F_92 ( NULL , NULL , L_46 ) ;
if ( ! V_52 )
return NULL ;
V_206 = F_100 ( V_52 , L_47 , 0 ) ;
F_89 ( V_52 ) ;
if ( ! V_206 )
return NULL ;
V_207 = ( void * ) F_101 ( V_206 , V_58 ) ;
if ( ! V_207 )
return NULL ;
memset ( V_207 , 0 , V_58 ) ;
F_10 () ;
* V_204 = V_206 ;
return V_207 ;
}
static void F_102 ( void * V_208 , T_5 V_58 , void * V_204 )
{
F_103 ( (struct V_205 * ) V_204 , ( T_2 ) V_208 , V_58 ) ;
}
static void * F_104 ( T_5 V_58 , void * * V_204 )
{
struct V_119 * V_70 = * V_204 ;
void * V_34 = F_105 ( V_70 , V_58 , V_39 ) ;
if ( ! V_34 )
return NULL ;
F_10 () ;
F_106 () ;
return V_34 ;
}
static void F_107 ( void * V_208 , T_5 V_58 , void * V_204 )
{
struct V_119 * V_70 = V_204 ;
if ( V_70 && V_208 )
F_108 ( V_70 , V_208 ) ;
}
static int F_109 ( struct V_125 * V_119 )
{
void T_8 * V_129 = V_119 -> V_129 ;
const struct V_126 * V_162 = V_119 -> V_10 ;
if ( ( F_78 ( V_129 ) & V_162 -> V_147 ) ==
V_162 -> V_147 )
return 0 ;
F_9 ( V_40 , V_144 ,
L_48 ) ;
return - V_63 ;
}
static T_1 F_110 ( int V_1 , void * V_2 )
{
struct V_125 * V_124 = V_2 ;
if ( V_1 == V_124 -> V_127 ) {
F_5 ( V_124 -> V_209 -> V_190 ,
V_210 ,
V_211 ) ;
F_57 ( V_124 -> V_166 , 0 , 0 , V_124 -> V_130 ) ;
return V_28 ;
} else if ( V_1 == V_124 -> V_131 ) {
F_5 ( V_124 -> V_209 -> V_190 ,
V_210 ,
V_212 ) ;
F_58 ( V_124 -> V_166 , 0 , 0 , V_124 -> V_130 ) ;
F_3 ( L_27 ) ;
return V_28 ;
}
F_59 ( 1 ) ;
return V_29 ;
}
static int T_11 F_111 ( void )
{
return F_91 ( L_49 ) ;
}
static T_3 F_112 ( struct V_30 * V_30 ,
const char T_4 * V_133 ,
T_5 V_31 , T_6 * V_32 )
{
struct V_123 * V_139 = V_30 -> V_33 ;
struct V_125 * V_6 = V_139 -> V_7 ;
const struct V_126 * V_9 = V_6 -> V_10 ;
void T_8 * V_213 = ( V_6 -> V_129 + V_9 -> V_146 ) ;
unsigned long V_138 ;
T_9 V_137 ;
if ( ! V_133 || F_61 ( V_137 , V_133 ) )
return - V_141 ;
F_62 ( V_138 ) ;
if ( V_137 == V_145 )
F_56 ( V_9 -> V_45 , V_213 ) ;
else
F_56 ( V_9 -> V_44 , V_213 ) ;
F_10 () ;
F_63 ( V_138 ) ;
return V_31 ;
}
static void F_113 ( struct V_214 * V_215 )
{
int V_216 , V_217 , V_218 , V_219 ;
struct V_220 * V_209 = F_114 ( V_215 ) ;
struct V_221 * V_222 = F_115 ( V_215 ) ;
int V_1 = F_116 ( V_215 ) ;
V_216 = ( V_1 == V_209 -> V_131 ) ? 1 : 0 ;
V_218 = V_216 ? V_223 :
V_224 ;
F_117 ( V_222 , V_215 ) ;
F_2 ( V_209 -> V_190 , V_218 , & V_219 ) ;
F_118 (bit, (unsigned long *)&irq_status, 32 ) {
V_1 = F_119 ( V_209 -> V_225 , V_216 * 32 + V_217 ) ;
if ( V_1 )
F_120 ( V_1 ) ;
}
F_121 ( V_222 , V_215 ) ;
}
static int F_96 ( struct V_51 * V_52 )
{
struct V_51 * V_226 ;
int V_68 = 0 ;
V_226 = F_122 ( V_52 , L_50 , 0 ) ;
if ( V_226 && ! F_94 ( V_226 ) )
V_68 = - V_63 ;
F_89 ( V_226 ) ;
return V_68 ;
}
static int F_123 ( struct V_220 * V_209 ,
struct V_51 * V_52 )
{
struct V_123 * V_124 ;
struct V_125 * V_227 ;
char * V_155 = ( char * ) V_52 -> V_156 ;
struct V_153 V_80 ;
int V_228 ;
int V_229 = 0 ;
const struct V_126 * V_162 ;
const struct V_73 * V_202 =
F_36 ( V_203 , V_52 ) ;
if ( F_97 ( V_202 ) )
return - V_63 ;
V_162 = V_202 -> V_10 ;
if ( F_97 ( V_162 ) )
return - V_63 ;
if ( F_96 ( V_52 ) )
return - V_63 ;
if ( ! F_41 ( V_209 -> V_70 , F_123 , V_39 ) )
return - V_42 ;
V_229 = F_124 ( V_52 , 0 , & V_80 ) ;
if ( V_229 < 0 ) {
F_9 ( V_40 , V_144 ,
L_51 , V_155 ) ;
goto V_230;
}
V_228 = F_125 () ;
V_124 = F_71 ( sizeof( * V_227 ) , V_155 ,
1 , V_155 , 1 , 0 , NULL , 0 ,
V_228 ) ;
if ( ! V_124 ) {
F_9 ( V_40 , V_144 ,
L_34 , V_155 ) ;
V_229 = - V_42 ;
goto V_230;
}
V_227 = V_124 -> V_7 ;
V_124 -> V_70 = V_209 -> V_70 ;
V_227 -> V_130 = V_155 ;
V_227 -> V_228 = V_228 ;
V_227 -> V_209 = V_209 ;
V_227 -> V_166 = V_124 ;
V_227 -> V_10 = V_162 ;
V_227 -> V_231 = * V_209 -> V_70 ;
V_124 -> V_70 = & V_227 -> V_231 ;
V_124 -> V_25 = L_35 ;
V_124 -> V_100 = V_155 ;
V_124 -> F_27 = V_155 ;
V_227 -> V_129 = F_126 ( V_209 -> V_70 , & V_80 ) ;
if ( F_35 ( V_227 -> V_129 ) ) {
V_229 = F_127 ( V_227 -> V_129 ) ;
goto V_232;
}
if ( V_227 -> V_10 -> V_161 ) {
V_229 = V_227 -> V_10 -> V_161 ( V_227 ) ;
if ( V_229 )
goto V_232;
}
V_227 -> V_127 = F_128 ( V_52 , 0 ) ;
if ( ! V_227 -> V_127 ) {
F_9 ( V_40 , V_144 , L_52 ) ;
V_229 = - V_63 ;
goto V_232;
}
V_229 = F_43 ( V_209 -> V_70 , V_227 -> V_127 ,
V_162 -> V_233 ,
V_117 , V_155 , V_227 ) ;
if ( V_229 ) {
F_9 ( V_40 , V_144 , L_53 ) ;
goto V_232;
}
V_227 -> V_131 = F_128 ( V_52 , 1 ) ;
if ( ! V_227 -> V_131 ) {
F_9 ( V_40 , V_144 , L_54 ) ;
V_229 = - V_63 ;
goto V_232;
}
V_229 = F_43 ( V_209 -> V_70 , V_227 -> V_131 ,
V_162 -> V_233 ,
V_117 , V_155 , V_227 ) ;
if ( V_229 ) {
F_9 ( V_40 , V_144 , L_53 ) ;
goto V_232;
}
V_229 = F_73 ( V_124 ) ;
if ( V_229 ) {
F_129 ( V_209 -> V_70 , L_55 ) ;
V_229 = - V_42 ;
goto V_232;
}
F_64 ( V_124 , V_162 ) ;
F_130 ( & V_227 -> V_234 , & V_209 -> V_235 ) ;
F_131 ( V_209 -> V_70 , F_123 ) ;
return 0 ;
V_232:
F_74 ( V_124 ) ;
V_230:
F_47 ( V_209 -> V_70 , NULL ) ;
F_9 ( V_40 , V_144 ,
L_36 , V_155 , V_229 ) ;
return V_229 ;
}
static void F_132 ( struct V_236 * V_237 )
{
struct V_220 * V_209 = F_133 ( V_237 ) ;
F_5 ( V_209 -> V_190 , V_192 ,
F_98 ( V_237 -> V_238 ) ) ;
}
static void F_134 ( struct V_236 * V_237 )
{
struct V_220 * V_209 = F_133 ( V_237 ) ;
F_5 ( V_209 -> V_190 , V_199 ,
F_98 ( V_237 -> V_238 ) ) ;
}
static int F_135 ( struct V_239 * V_237 , unsigned int V_1 ,
T_12 V_238 )
{
struct V_220 * V_209 = V_237 -> V_240 ;
F_136 ( V_1 , & V_209 -> V_221 , V_241 ) ;
F_137 ( V_1 , V_209 ) ;
F_138 ( V_1 ) ;
return 0 ;
}
static int F_139 ( struct V_65 * V_38 )
{
struct V_220 * V_209 ;
struct V_51 * V_201 ;
V_209 = F_105 ( & V_38 -> V_70 , sizeof( * V_209 ) , V_39 ) ;
if ( ! V_209 )
return - V_42 ;
V_209 -> V_70 = & V_38 -> V_70 ;
F_40 ( V_38 , V_209 ) ;
F_140 ( & V_209 -> V_235 ) ;
V_209 -> V_190 = F_34 ( V_38 -> V_70 . V_84 ,
L_39 ) ;
if ( F_35 ( V_209 -> V_190 ) ) {
F_9 ( V_40 , V_144 ,
L_40 ) ;
return F_127 ( V_209 -> V_190 ) ;
}
V_209 -> V_221 . V_156 = V_38 -> V_70 . V_84 -> V_156 ;
V_209 -> V_221 . V_186 = F_132 ;
V_209 -> V_221 . V_242 = F_134 ;
V_209 -> V_225 = F_141 ( V_38 -> V_70 . V_84 , 64 ,
& V_243 , V_209 ) ;
if ( ! V_209 -> V_225 ) {
F_129 ( & V_38 -> V_70 , L_56 ) ;
return - V_42 ;
}
V_209 -> V_127 = F_37 ( V_38 , 0 ) ;
if ( V_209 -> V_127 < 0 ) {
F_129 ( & V_38 -> V_70 , L_57 ) ;
return V_209 -> V_127 ;
}
F_142 ( V_209 -> V_127 ,
F_113 ,
V_209 ) ;
V_209 -> V_131 = F_37 ( V_38 , 1 ) ;
if ( V_209 -> V_131 < 0 ) {
F_129 ( & V_38 -> V_70 , L_53 ) ;
return V_209 -> V_131 ;
}
F_142 ( V_209 -> V_131 ,
F_113 ,
V_209 ) ;
F_93 (pdev->dev.of_node, child) {
if ( ! F_94 ( V_201 ) )
continue;
if ( F_95 ( V_201 , L_58 ) )
F_123 ( V_209 , V_201 ) ;
else if ( ( F_95 ( V_201 ,
L_59 ) ) ||
( F_95 ( V_201 ,
L_49 ) ) )
F_123 ( V_209 , V_201 ) ;
else if ( F_95 ( V_201 ,
L_60 ) )
F_54 ( V_38 -> V_70 . V_84 ,
V_83 ,
NULL , & V_38 -> V_70 ) ;
}
return 0 ;
}
