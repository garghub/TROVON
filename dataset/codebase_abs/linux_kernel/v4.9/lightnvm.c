static inline void F_1 ( void )
{
F_2 ( sizeof( struct V_1 ) != 64 ) ;
F_2 ( sizeof( struct V_2 ) != 64 ) ;
F_2 ( sizeof( struct V_3 ) != 64 ) ;
F_2 ( sizeof( struct V_4 ) != 64 ) ;
F_2 ( sizeof( struct V_5 ) != 64 ) ;
F_2 ( sizeof( struct V_6 ) != 64 ) ;
F_2 ( sizeof( struct V_7 ) != 64 ) ;
F_2 ( sizeof( struct V_8 ) != 960 ) ;
F_2 ( sizeof( struct V_9 ) != 128 ) ;
F_2 ( sizeof( struct V_10 ) != 4096 ) ;
F_2 ( sizeof( struct V_11 ) != 512 ) ;
}
static int F_3 ( struct V_12 * V_12 , struct V_10 * V_10 )
{
struct V_8 * V_13 ;
struct V_14 * V_15 ;
int V_16 , V_17 ;
V_17 = F_4 ( V_18 , 4 , V_12 -> V_19 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
V_13 = & V_10 -> V_20 [ V_16 ] ;
V_15 = & V_12 -> V_20 [ V_16 ] ;
V_15 -> V_21 = V_13 -> V_21 ;
V_15 -> V_22 = V_13 -> V_22 ;
V_15 -> V_23 = V_13 -> V_23 ;
V_15 -> V_24 = V_13 -> V_24 ;
V_15 -> V_25 = V_13 -> V_25 ;
V_15 -> V_26 = F_5 ( V_13 -> V_26 ) ;
V_15 -> V_27 = F_5 ( V_13 -> V_27 ) ;
V_15 -> V_28 = F_5 ( V_13 -> V_28 ) ;
V_15 -> V_29 = F_5 ( V_13 -> V_29 ) ;
V_15 -> V_30 = F_5 ( V_13 -> V_30 ) ;
V_15 -> V_31 = F_6 ( V_13 -> V_31 ) ;
V_15 -> V_32 = F_6 ( V_13 -> V_32 ) ;
V_15 -> V_33 = F_6 ( V_13 -> V_33 ) ;
V_15 -> V_34 = F_6 ( V_13 -> V_34 ) ;
V_15 -> V_35 = F_6 ( V_13 -> V_35 ) ;
V_15 -> V_36 = F_6 ( V_13 -> V_36 ) ;
V_15 -> V_37 = F_6 ( V_13 -> V_37 ) ;
V_15 -> V_38 = F_6 ( V_13 -> V_38 ) ;
V_15 -> V_39 = F_5 ( V_13 -> V_39 ) ;
if ( V_15 -> V_22 == V_40 ) {
memcpy ( V_15 -> V_41 . V_42 , V_13 -> V_41 . V_42 , 8 ) ;
V_15 -> V_41 . V_43 . V_44 =
F_5 ( V_13 -> V_41 . V_43 . V_44 ) ;
if ( V_15 -> V_41 . V_43 . V_44 > V_45 ) {
F_7 ( L_1 ) ;
return - V_46 ;
}
memcpy ( V_15 -> V_41 . V_43 . V_47 , V_13 -> V_41 . V_43 . V_47 ,
V_15 -> V_41 . V_43 . V_44 ) ;
}
}
return 0 ;
}
static int V_1 ( struct V_48 * V_49 , struct V_12 * V_12 )
{
struct V_50 * V_51 = V_49 -> V_52 -> V_53 ;
struct V_10 * V_10 ;
struct V_54 V_55 = {} ;
int V_56 ;
V_55 . V_57 . V_58 = V_59 ;
V_55 . V_57 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 . V_57 . V_62 = 0 ;
V_10 = F_9 ( sizeof( struct V_10 ) , V_63 ) ;
if ( ! V_10 )
return - V_64 ;
V_56 = F_10 ( V_51 -> V_65 -> V_66 , (struct V_67 * ) & V_55 ,
V_10 , sizeof( struct V_10 ) ) ;
if ( V_56 ) {
V_56 = - V_68 ;
goto V_69;
}
V_12 -> V_70 = V_10 -> V_70 ;
V_12 -> V_71 = V_10 -> V_71 ;
V_12 -> V_19 = V_10 -> V_19 ;
V_12 -> V_72 = F_6 ( V_10 -> V_72 ) ;
V_12 -> V_73 = F_6 ( V_10 -> V_73 ) ;
memcpy ( & V_12 -> V_74 , & V_10 -> V_74 ,
sizeof( struct V_9 ) ) ;
V_56 = F_3 ( V_12 , V_10 ) ;
V_69:
F_11 ( V_10 ) ;
return V_56 ;
}
static int F_12 ( struct V_48 * V_49 , T_1 V_75 , V_18 V_76 ,
T_2 * V_77 , void * V_78 )
{
struct V_50 * V_51 = V_49 -> V_52 -> V_53 ;
struct V_54 V_55 = {} ;
V_18 V_79 = F_13 ( V_51 -> V_65 -> V_66 ) << 9 ;
V_18 V_80 = V_79 / sizeof( T_1 ) ;
T_1 V_81 = V_75 ;
void * V_82 ;
int V_56 = 0 ;
V_55 . V_83 . V_58 = V_84 ;
V_55 . V_83 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_82 = F_9 ( V_79 , V_63 ) ;
if ( ! V_82 )
return - V_64 ;
while ( V_76 ) {
V_18 V_85 = F_14 ( V_80 , V_76 ) ;
V_55 . V_83 . V_75 = F_15 ( V_81 ) ;
V_55 . V_83 . V_76 = F_8 ( V_85 ) ;
V_56 = F_10 ( V_51 -> V_65 -> V_66 ,
(struct V_67 * ) & V_55 , V_82 , V_79 ) ;
if ( V_56 ) {
F_16 ( V_51 -> V_65 -> V_86 ,
L_2 , V_56 ) ;
V_56 = - V_68 ;
goto V_69;
}
if ( V_77 ( V_81 , V_85 , V_82 , V_78 ) ) {
V_56 = - V_87 ;
goto V_69;
}
V_81 += V_85 ;
V_76 -= V_85 ;
}
V_69:
F_11 ( V_82 ) ;
return V_56 ;
}
static int F_17 ( struct V_48 * V_49 , struct V_88 V_89 ,
T_3 * V_90 )
{
struct V_91 * V_52 = V_49 -> V_52 ;
struct V_50 * V_51 = V_52 -> V_53 ;
struct V_92 * V_65 = V_51 -> V_65 ;
struct V_54 V_55 = {} ;
struct V_11 * V_93 ;
int V_94 = V_49 -> V_95 * V_49 -> V_96 ;
int V_97 = sizeof( struct V_11 ) + V_94 ;
int V_56 = 0 ;
V_55 . V_98 . V_58 = V_99 ;
V_55 . V_98 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 . V_98 . V_100 = F_15 ( V_89 . V_89 ) ;
V_93 = F_18 ( V_97 , V_63 ) ;
if ( ! V_93 )
return - V_64 ;
V_56 = F_10 ( V_65 -> V_66 , (struct V_67 * ) & V_55 ,
V_93 , V_97 ) ;
if ( V_56 ) {
F_16 ( V_65 -> V_86 , L_3 , V_56 ) ;
V_56 = - V_68 ;
goto V_69;
}
if ( V_93 -> V_101 [ 0 ] != 'B' || V_93 -> V_101 [ 1 ] != 'B' ||
V_93 -> V_101 [ 2 ] != 'L' || V_93 -> V_101 [ 3 ] != 'T' ) {
F_16 ( V_65 -> V_86 , L_4 ) ;
V_56 = - V_46 ;
goto V_69;
}
if ( F_5 ( V_93 -> V_102 ) != 1 ) {
V_56 = - V_46 ;
F_16 ( V_65 -> V_86 , L_5 ) ;
goto V_69;
}
if ( F_6 ( V_93 -> V_103 ) != V_94 ) {
V_56 = - V_46 ;
F_16 ( V_65 -> V_86 ,
L_6 ,
F_6 ( V_93 -> V_103 ) , V_94 ) ;
goto V_69;
}
memcpy ( V_90 , V_93 -> V_104 , V_49 -> V_95 * V_49 -> V_96 ) ;
V_69:
F_11 ( V_93 ) ;
return V_56 ;
}
static int F_19 ( struct V_48 * V_49 , struct V_88 * V_105 ,
int V_106 , int type )
{
struct V_50 * V_51 = V_49 -> V_52 -> V_53 ;
struct V_54 V_55 = {} ;
int V_56 = 0 ;
V_55 . V_107 . V_58 = V_108 ;
V_55 . V_107 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 . V_107 . V_100 = F_15 ( V_105 -> V_89 ) ;
V_55 . V_107 . V_76 = F_20 ( V_106 - 1 ) ;
V_55 . V_107 . V_109 = type ;
V_56 = F_10 ( V_51 -> V_65 -> V_66 , (struct V_67 * ) & V_55 ,
NULL , 0 ) ;
if ( V_56 )
F_16 ( V_51 -> V_65 -> V_86 , L_7 ,
V_56 ) ;
return V_56 ;
}
static inline void F_21 ( struct V_110 * V_111 , struct V_112 * V_113 ,
struct V_50 * V_51 , struct V_54 * V_55 )
{
V_55 -> V_114 . V_58 = V_113 -> V_58 ;
V_55 -> V_114 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 -> V_114 . V_100 = F_15 ( V_113 -> V_88 . V_89 ) ;
V_55 -> V_114 . V_115 = F_15 ( V_113 -> V_116 ) ;
V_55 -> V_114 . V_117 = F_20 ( V_113 -> V_118 ) ;
V_55 -> V_114 . V_119 = F_20 ( V_113 -> V_106 - 1 ) ;
if ( V_113 -> V_58 == V_120 || V_113 -> V_58 == V_121 )
V_55 -> V_122 . V_75 = F_15 ( F_22 ( V_51 ,
V_113 -> V_123 -> V_124 . V_125 ) ) ;
}
static void F_23 ( struct V_110 * V_111 , int error )
{
struct V_112 * V_113 = V_111 -> V_126 ;
struct V_127 * V_128 = V_111 -> V_129 ;
if ( V_128 )
V_113 -> V_130 = F_24 ( V_128 -> V_131 ) ;
F_25 ( V_113 , error ) ;
F_11 ( V_111 -> V_132 ) ;
F_26 ( V_111 ) ;
}
static int F_27 ( struct V_48 * V_133 , struct V_112 * V_113 )
{
struct V_91 * V_52 = V_133 -> V_52 ;
struct V_50 * V_51 = V_52 -> V_53 ;
struct V_110 * V_111 ;
struct V_123 * V_123 = V_113 -> V_123 ;
struct V_54 * V_132 ;
V_111 = F_28 ( V_52 , F_29 ( V_123 ) , 0 ) ;
if ( F_30 ( V_111 ) )
return - V_64 ;
V_132 = F_18 ( sizeof( struct V_54 ) +
sizeof( struct V_127 ) , V_63 ) ;
if ( ! V_132 ) {
F_26 ( V_111 ) ;
return - V_64 ;
}
V_111 -> V_134 = V_135 ;
V_111 -> V_136 = F_31 ( V_123 ) ;
if ( F_32 ( V_123 ) )
V_111 -> V_137 = F_33 ( V_52 , V_123 ) ;
V_111 -> V_138 = V_123 -> V_124 . V_139 ;
V_111 -> V_123 = V_111 -> V_140 = V_123 ;
F_21 ( V_111 , V_113 , V_51 , V_132 ) ;
V_111 -> V_132 = ( unsigned char * ) V_132 ;
V_111 -> V_141 = sizeof( struct V_54 ) ;
V_111 -> V_129 = V_132 + 1 ;
V_111 -> V_126 = V_113 ;
F_34 ( V_52 , NULL , V_111 , 0 , F_23 ) ;
return 0 ;
}
static int F_35 ( struct V_48 * V_133 , struct V_112 * V_113 )
{
struct V_91 * V_52 = V_133 -> V_52 ;
struct V_50 * V_51 = V_52 -> V_53 ;
struct V_54 V_55 = {} ;
V_55 . V_142 . V_58 = V_143 ;
V_55 . V_142 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 . V_142 . V_100 = F_15 ( V_113 -> V_88 . V_89 ) ;
V_55 . V_142 . V_119 = F_20 ( V_113 -> V_106 - 1 ) ;
return F_10 ( V_52 , (struct V_67 * ) & V_55 , NULL , 0 ) ;
}
static void * F_36 ( struct V_48 * V_49 , char * V_144 )
{
struct V_50 * V_51 = V_49 -> V_52 -> V_53 ;
return F_37 ( V_144 , V_51 -> V_65 -> V_133 , V_145 , V_145 , 0 ) ;
}
static void F_38 ( void * V_146 )
{
struct V_147 * V_147 = V_146 ;
F_39 ( V_147 ) ;
}
static void * F_40 ( struct V_48 * V_133 , void * V_146 ,
T_4 V_148 , T_5 * V_149 )
{
return F_41 ( V_146 , V_148 , V_149 ) ;
}
static void F_42 ( void * V_146 , void * V_150 ,
T_5 V_149 )
{
F_43 ( V_146 , V_150 , V_149 ) ;
}
int F_44 ( struct V_50 * V_51 , char * V_151 , int V_152 ,
const struct V_153 * V_154 )
{
struct V_91 * V_52 = V_51 -> V_155 ;
struct V_48 * V_133 ;
int V_56 ;
V_133 = F_45 ( V_152 ) ;
if ( ! V_133 )
return - V_64 ;
V_133 -> V_52 = V_52 ;
memcpy ( V_133 -> V_144 , V_151 , V_156 ) ;
V_133 -> V_157 = & V_158 ;
V_133 -> V_159 = V_51 -> V_65 -> V_86 ;
V_133 -> V_160 = V_51 ;
V_51 -> V_161 = V_133 ;
V_56 = F_46 ( V_133 ) ;
V_51 -> V_162 = F_47 ( V_133 -> V_163 ) ;
if ( F_48 ( & V_133 -> V_133 . V_164 , V_154 ) )
F_49 ( L_8 ,
V_151 ) ;
return V_56 ;
}
void F_50 ( struct V_50 * V_51 )
{
F_51 ( V_51 -> V_161 ) ;
}
int F_52 ( struct V_50 * V_51 , struct V_165 * V_42 )
{
struct V_92 * V_65 = V_51 -> V_65 ;
struct V_166 * V_167 = F_53 ( V_65 -> V_133 ) ;
if ( V_167 -> V_168 == V_169 &&
V_167 -> V_86 == V_170 &&
V_42 -> V_171 [ 0 ] == 0x1 )
return 1 ;
if ( V_167 -> V_168 == V_169 &&
V_167 -> V_86 == V_172 &&
V_42 -> V_171 [ 0 ] == 0x1 )
return 1 ;
return 0 ;
}
