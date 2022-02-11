static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , void * V_5 , T_2 V_6 )
{
return F_2 ( V_2 -> V_7 , F_3 ( V_2 -> V_7 , 0 ) ,
V_3 ,
V_8 | V_9 | V_10 ,
0x00 , V_4 , V_5 , V_6 , 1000 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_11 ;
T_1 V_5 [ 24 ] ;
V_11 = F_1 ( V_2 , V_12 , 0x00 , V_5 , 12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_1 ( V_2 , V_12 , 0x01 , V_5 , 12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_1 ( V_2 , V_12 , 0x02 , V_5 , 12 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_1 ( V_2 , V_13 , 0x00 , V_5 , 24 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_1 ( V_2 , V_14 , 0x00 , V_5 , 5 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_1 ( V_2 , V_12 , 0x03 , V_5 , 12 ) ;
return V_11 ;
}
static void F_5 ( struct V_15 * V_16 )
{
struct V_1 * V_17 = V_16 -> V_18 ;
F_6 ( V_17 -> V_2 , L_1 ) ;
F_4 ( V_17 ) ;
}
static void F_7 ( struct V_15 * V_16 )
{
struct V_1 * V_17 = V_16 -> V_18 ;
F_6 ( V_17 -> V_2 , L_2 ) ;
}
static void F_8 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
int V_23 , V_24 , V_25 ;
int V_26 = F_9 ( V_20 -> V_26 ) ;
int V_27 = F_9 ( V_20 -> V_27 ) ;
int V_28 = F_9 ( V_20 -> V_28 ) ;
int V_29 = F_9 ( V_20 -> V_29 ) ;
int V_30 = F_9 ( V_20 -> V_30 ) ;
int V_31 = F_9 ( V_20 -> V_31 ) ;
int V_32 = F_10 ( V_22 , V_20 -> V_33 ) ;
if ( V_32 < 0 || V_32 >= V_34 )
return;
F_11 ( V_22 , V_32 ) ;
F_12 ( V_22 , V_35 , 1 ) ;
V_23 = ( V_26 > V_27 ) ;
V_24 = F_13 ( V_26 , V_27 ) ;
V_25 = F_14 ( V_26 , V_27 ) ;
F_15 ( V_22 , V_36 , V_28 ) ;
F_15 ( V_22 , V_37 , V_29 ) ;
F_15 ( V_22 , V_38 , V_30 ) ;
F_15 ( V_22 , V_39 , V_31 ) ;
F_15 ( V_22 , V_40 , V_23 ) ;
F_15 ( V_22 , V_41 , V_24 ) ;
F_15 ( V_22 , V_42 , V_25 ) ;
}
static void F_16 ( struct V_15 * V_16 )
{
struct V_1 * V_17 = V_16 -> V_18 ;
struct V_21 * V_22 = V_16 -> V_22 ;
int V_11 , V_43 , V_44 , V_45 , V_46 ;
T_3 V_47 ( V_48 ) ;
struct V_49 * V_50 = & V_17 -> V_51 -> V_50 ;
struct V_19 * V_52 = & V_17 -> V_51 -> V_53 [ 0 ] ;
F_6 ( V_17 -> V_2 , L_3 ) ;
V_44 = - 1 ;
do {
V_11 = F_17 ( V_17 -> V_7 ,
F_18 ( V_17 -> V_7 , V_17 -> V_54 ) ,
V_17 -> V_51 , V_17 -> V_55 ,
& V_43 , 1000 ) ;
F_6 ( V_17 -> V_2 , L_4 , V_43 ) ;
if ( V_11 < 0 ) {
F_19 ( V_17 -> V_2 , L_5 ) ;
return;
}
V_11 = V_43 - sizeof( struct V_49 ) ;
if ( V_11 % sizeof( struct V_19 ) != 0 ) {
F_19 ( V_17 -> V_2 , L_6 ) ;
return;
}
if ( V_44 == - 1 ) {
V_44 = F_9 ( V_50 -> V_56 ) ;
F_6 ( V_17 -> V_2 , L_7 , V_44 ) ;
V_48 = F_20 ( V_50 -> V_48 ) ;
}
if ( V_48 != V_50 -> V_48 )
F_6 ( V_17 -> V_2 , L_8 ) ;
V_45 = V_11 / sizeof( struct V_19 ) ;
F_6 ( V_17 -> V_2 , L_9 , V_45 ) ;
if ( V_45 > V_44 )
V_45 = V_44 ;
for ( V_46 = 0 ; V_46 < V_45 ; V_46 ++ ) {
V_44 -- ;
F_6 ( V_17 -> V_2 , L_10 ) ;
F_8 ( & ( V_52 [ V_46 ] ) , V_22 ) ;
}
} while ( V_44 > 0 );
F_21 ( V_22 ) ;
F_22 ( V_22 ) ;
F_23 ( V_17 ) ;
}
static void F_23 ( struct V_1 * V_17 )
{
struct V_57 * V_58 = ( void * ) ( V_17 -> V_51 ) ;
struct V_59 * V_60 ;
struct V_61 V_62 ;
struct V_63 * V_64 ;
int V_11 , V_43 ;
if ( ! F_24 ( & V_17 -> V_65 ) )
return;
F_25 ( & V_17 -> V_66 ) ;
if ( F_26 ( & V_17 -> V_67 ) ) {
F_6 ( V_17 -> V_2 , L_11 ) ;
F_27 ( & V_17 -> V_66 ) ;
return;
}
V_60 = F_28 ( V_17 -> V_67 . V_68 , struct V_59 , V_69 ) ;
F_29 ( & V_60 -> V_69 ) ;
F_27 ( & V_17 -> V_66 ) ;
F_6 ( V_17 -> V_2 , L_12 ) ;
V_11 = F_17 ( V_17 -> V_7 ,
F_18 ( V_17 -> V_7 , V_70 ) ,
V_17 -> V_51 , V_17 -> V_55 ,
& V_43 , 1000 ) ;
if ( V_11 < 0 ) {
F_19 ( V_17 -> V_2 , L_5 ) ;
goto V_71;
}
if ( V_43 != sizeof( struct V_57 ) ) {
F_19 ( V_17 -> V_2 , L_13 ,
V_43 , sizeof( struct V_57 ) ) ;
goto V_71;
}
if ( F_20 ( V_58 -> V_72 ) != V_73 ) {
F_19 ( V_17 -> V_2 , L_14 ) ;
goto V_71;
}
if ( F_20 ( V_58 -> V_6 ) != V_74 . V_75 ) {
F_19 ( V_17 -> V_2 , L_15 ) ;
goto V_71;
}
F_6 ( V_17 -> V_2 , L_16 ) ;
V_64 = F_30 ( & V_60 -> V_76 . V_77 , 0 ) ;
V_11 = F_31 ( & V_62 , V_17 -> V_7 ,
F_18 ( V_17 -> V_7 , V_70 ) , 0 ,
V_64 -> V_78 , V_64 -> V_79 , V_74 . V_75 , 0 ) ;
if ( V_11 < 0 ) {
F_19 ( V_17 -> V_2 , L_17 , V_11 ) ;
goto V_71;
}
F_32 ( & V_62 ) ;
if ( V_62 . V_80 < 0 ) {
F_19 ( V_17 -> V_2 , L_18 , V_62 . V_80 ) ;
goto V_71;
}
F_6 ( V_17 -> V_2 , L_19 ) ;
if ( V_17 -> V_81 == - 1 )
goto V_71;
V_60 -> V_76 . V_77 . V_82 = F_33 () ;
V_60 -> V_76 . V_81 = V_17 -> V_81 ++ ;
V_60 -> V_76 . V_83 = V_84 ;
F_34 ( & V_60 -> V_76 . V_77 , V_85 ) ;
F_6 ( V_17 -> V_2 , L_20 ) ;
return;
V_71:
F_34 ( & V_60 -> V_76 . V_77 , V_86 ) ;
}
static void F_35 ( struct V_21 * V_21 )
{
F_36 ( V_87 , V_21 -> V_88 ) ;
F_36 ( V_89 , V_21 -> V_88 ) ;
F_37 ( V_21 , V_36 ,
0 , V_90 , 0 , 0 ) ;
F_37 ( V_21 , V_37 ,
0 , V_91 , 0 , 0 ) ;
F_37 ( V_21 , V_38 ,
0 , V_90 , 0 , 0 ) ;
F_37 ( V_21 , V_39 ,
0 , V_91 , 0 , 0 ) ;
F_37 ( V_21 , V_41 ,
0 , V_90 , 0 , 0 ) ;
F_37 ( V_21 , V_42 ,
0 , V_91 , 0 , 0 ) ;
F_37 ( V_21 , V_40 , 0 , 1 , 0 , 0 ) ;
F_38 ( V_21 , V_34 ,
V_92 | V_93 ) ;
}
static int F_39 ( struct V_94 * V_95 ,
const struct V_96 * V_97 )
{
struct V_98 * V_7 = F_40 ( V_95 ) ;
struct V_1 * V_17 ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
struct V_15 * V_103 ;
int error ;
V_100 = & V_95 -> V_104 [ 0 ] ;
if ( V_100 -> V_105 . V_106 != 0xFF )
return - V_107 ;
V_102 = & V_100 -> V_102 [ 4 ] . V_105 ;
if ( V_102 -> V_108 != V_109 )
return - V_107 ;
V_17 = F_41 ( sizeof( struct V_1 ) , V_110 ) ;
if ( ! V_17 )
return - V_111 ;
V_103 = F_42 () ;
if ( ! V_103 ) {
error = - V_111 ;
goto V_112;
}
F_43 ( & V_17 -> V_67 ) ;
F_44 ( & V_17 -> V_66 ) ;
F_45 ( & V_17 -> V_113 ) ;
V_103 -> V_18 = V_17 ;
V_103 -> V_114 = V_115 ;
V_103 -> V_116 = F_5 ;
V_103 -> V_117 = F_16 ;
V_103 -> V_118 = F_7 ;
F_35 ( V_103 -> V_22 ) ;
V_103 -> V_22 -> V_119 = V_120 ;
F_46 ( V_7 , & V_103 -> V_22 -> V_97 ) ;
F_47 ( V_7 , V_17 -> V_121 , sizeof( V_17 -> V_121 ) ) ;
F_48 ( V_17 -> V_121 , L_21 , sizeof( V_17 -> V_121 ) ) ;
V_103 -> V_22 -> V_121 = V_17 -> V_121 ;
V_103 -> V_22 -> V_2 . V_122 = & V_95 -> V_2 ;
V_17 -> V_7 = V_7 ;
V_17 -> V_2 = & V_95 -> V_2 ;
V_17 -> V_22 = V_103 ;
V_17 -> V_55 = F_49 ( V_102 ) ;
V_17 -> V_54 = V_102 -> V_108 ;
V_17 -> V_51 = F_50 ( V_17 -> V_55 , V_110 ) ;
if ( ! V_17 -> V_51 ) {
F_19 ( & V_95 -> V_2 , L_22 ) ;
error = - V_111 ;
goto V_123;
}
error = F_51 ( V_103 ) ;
if ( error ) {
F_19 ( & V_95 -> V_2 ,
L_23 ) ;
goto V_124;
}
snprintf ( V_17 -> V_125 . V_119 , sizeof( V_17 -> V_125 . V_119 ) , L_24 , V_120 ) ;
error = F_52 ( V_17 -> V_2 , & V_17 -> V_125 ) ;
if ( error ) {
F_19 ( & V_95 -> V_2 ,
L_25 ) ;
goto V_126;
}
V_17 -> V_65 = V_127 ;
V_17 -> V_65 . V_128 = V_17 ;
V_17 -> V_65 . V_113 = & V_17 -> V_113 ;
error = F_53 ( & V_17 -> V_65 ) ;
if ( error )
goto V_126;
V_17 -> V_129 = F_54 ( V_17 -> V_2 ) ;
if ( F_55 ( V_17 -> V_129 ) ) {
F_19 ( V_17 -> V_2 , L_26 ) ;
error = F_56 ( V_17 -> V_129 ) ;
goto V_126;
}
V_17 -> V_130 = V_131 ;
V_17 -> V_130 . V_132 = & V_17 -> V_125 ;
V_17 -> V_130 . V_113 = & V_17 -> V_113 ;
V_17 -> V_130 . V_65 = & V_17 -> V_65 ;
F_57 ( & V_17 -> V_130 , V_17 ) ;
error = F_58 ( & V_17 -> V_130 , V_133 , - 1 ) ;
if ( error ) {
F_19 ( & V_95 -> V_2 ,
L_27 ) ;
goto V_134;
}
F_59 ( V_95 , V_17 ) ;
F_6 ( & V_95 -> V_2 , L_28 , V_135 ) ;
return 0 ;
V_134:
F_60 ( & V_17 -> V_130 ) ;
V_126:
F_61 ( & V_17 -> V_125 ) ;
V_124:
F_62 ( V_17 -> V_51 ) ;
V_123:
F_63 ( V_17 -> V_22 ) ;
V_112:
F_62 ( V_17 ) ;
return error ;
}
static void F_64 ( struct V_94 * V_95 )
{
struct V_1 * V_17 = F_65 ( V_95 ) ;
F_60 ( & V_17 -> V_130 ) ;
F_61 ( & V_17 -> V_125 ) ;
F_66 ( V_17 -> V_129 ) ;
F_67 ( V_17 -> V_22 ) ;
F_63 ( V_17 -> V_22 ) ;
F_62 ( V_17 -> V_51 ) ;
F_62 ( V_17 ) ;
F_59 ( V_95 , NULL ) ;
F_6 ( & V_95 -> V_2 , L_29 , V_135 ) ;
}
static int F_68 ( struct V_136 * V_137 ,
unsigned int * V_138 , unsigned int * V_139 ,
unsigned int V_140 [] , void * V_141 [] )
{
struct V_1 * V_17 = F_69 ( V_137 ) ;
if ( V_137 -> V_142 + * V_138 < 3 )
* V_138 = 3 - V_137 -> V_142 ;
V_141 [ 0 ] = V_17 -> V_129 ;
if ( * V_139 )
return V_140 [ 0 ] < V_74 . V_75 ? - V_143 : 0 ;
* V_139 = 1 ;
V_140 [ 0 ] = V_74 . V_75 ;
return 0 ;
}
static int F_70 ( struct V_144 * V_76 )
{
struct V_1 * V_17 = F_69 ( V_76 -> V_136 ) ;
unsigned long V_6 = V_74 . V_75 ;
if ( F_71 ( V_76 , 0 ) < V_6 ) {
F_19 ( & V_17 -> V_7 -> V_2 , L_30 ,
F_71 ( V_76 , 0 ) , V_6 ) ;
return - V_143 ;
}
F_72 ( V_76 , 0 , V_6 ) ;
return 0 ;
}
static void F_73 ( struct V_144 * V_76 )
{
struct V_1 * V_17 = F_69 ( V_76 -> V_136 ) ;
struct V_59 * V_145 = (struct V_59 * ) V_76 ;
F_25 ( & V_17 -> V_66 ) ;
F_74 ( & V_145 -> V_69 , & V_17 -> V_67 ) ;
F_27 ( & V_17 -> V_66 ) ;
}
static void F_75 ( struct V_1 * V_17 ,
enum V_146 V_147 )
{
struct V_59 * V_145 , * V_148 ;
F_25 ( & V_17 -> V_66 ) ;
F_76 (buf, node, &sur40->buf_list, list) {
F_34 ( & V_145 -> V_76 . V_77 , V_147 ) ;
F_29 ( & V_145 -> V_69 ) ;
}
F_27 ( & V_17 -> V_66 ) ;
}
static int F_77 ( struct V_136 * V_149 , unsigned int V_56 )
{
struct V_1 * V_17 = F_69 ( V_149 ) ;
V_17 -> V_81 = 0 ;
return 0 ;
}
static void F_78 ( struct V_136 * V_149 )
{
struct V_1 * V_17 = F_69 ( V_149 ) ;
V_17 -> V_81 = - 1 ;
F_75 ( V_17 , V_86 ) ;
}
static int F_79 ( struct V_150 * V_150 , void * V_151 ,
struct V_152 * V_153 )
{
struct V_1 * V_17 = F_80 ( V_150 ) ;
F_81 ( V_153 -> V_154 , V_155 , sizeof( V_153 -> V_154 ) ) ;
F_81 ( V_153 -> V_156 , V_120 , sizeof( V_153 -> V_156 ) ) ;
F_47 ( V_17 -> V_7 , V_153 -> V_157 , sizeof( V_153 -> V_157 ) ) ;
V_153 -> V_158 = V_159 |
V_160 |
V_161 ;
V_153 -> V_162 = V_153 -> V_158 | V_163 ;
return 0 ;
}
static int F_82 ( struct V_150 * V_150 , void * V_151 ,
struct V_164 * V_46 )
{
if ( V_46 -> V_4 != 0 )
return - V_143 ;
V_46 -> type = V_165 ;
V_46 -> V_166 = V_167 ;
F_81 ( V_46 -> V_119 , L_31 , sizeof( V_46 -> V_119 ) ) ;
V_46 -> V_162 = 0 ;
return 0 ;
}
static int F_83 ( struct V_150 * V_150 , void * V_151 , unsigned int V_46 )
{
return ( V_46 == 0 ) ? 0 : - V_143 ;
}
static int F_84 ( struct V_150 * V_150 , void * V_151 , unsigned int * V_46 )
{
* V_46 = 0 ;
return 0 ;
}
static int F_85 ( struct V_150 * V_150 , void * V_151 ,
struct V_168 * V_169 )
{
V_169 -> V_170 . V_171 = V_74 ;
return 0 ;
}
static int F_86 ( struct V_150 * V_150 , void * V_151 ,
struct V_172 * V_169 )
{
if ( V_169 -> V_4 != 0 )
return - V_143 ;
F_81 ( V_169 -> V_173 , L_32 , sizeof( V_169 -> V_173 ) ) ;
V_169 -> V_174 = V_175 ;
V_169 -> V_176 = 0 ;
return 0 ;
}
static int F_87 ( struct V_150 * V_150 , void * V_151 ,
struct V_177 * V_169 )
{
if ( ( V_169 -> V_4 != 0 ) || ( V_169 -> V_178 != V_175 ) )
return - V_143 ;
V_169 -> type = V_179 ;
V_169 -> V_180 . V_181 = V_74 . V_181 ;
V_169 -> V_180 . V_182 = V_74 . V_182 ;
return 0 ;
}
static int F_88 ( struct V_150 * V_150 , void * V_151 ,
struct V_183 * V_169 )
{
if ( ( V_169 -> V_4 > 1 ) || ( V_169 -> V_178 != V_175 )
|| ( V_169 -> V_181 != V_74 . V_181 )
|| ( V_169 -> V_182 != V_74 . V_182 ) )
return - V_143 ;
V_169 -> type = V_184 ;
V_169 -> V_180 . V_185 = 60 / ( V_169 -> V_4 + 1 ) ;
V_169 -> V_180 . V_186 = 1 ;
return 0 ;
}
