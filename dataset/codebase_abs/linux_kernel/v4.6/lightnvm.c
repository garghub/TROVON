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
F_16 ( V_51 -> V_65 -> V_86 , L_2 ,
V_56 ) ;
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
static void F_17 ( struct V_48 * V_49 ,
int V_88 , T_3 * V_89 ,
int V_90 , T_3 * V_91 )
{
int V_92 , V_93 , V_94 , V_95 ;
for ( V_92 = 0 ; V_92 < V_88 ; V_92 ++ ) {
V_93 = V_92 * V_49 -> V_96 ;
V_95 = V_91 [ V_93 ] ;
for ( V_94 = 0 ; V_94 < V_49 -> V_96 ; V_94 ++ ) {
if ( V_91 [ V_93 + V_94 ] &
( V_97 | V_98 ) ) {
V_95 = V_91 [ V_93 + V_94 ] ;
break;
}
}
V_89 [ V_92 ] = V_95 ;
}
}
static int F_18 ( struct V_48 * V_49 , struct V_99 V_100 ,
int V_88 , T_4 * V_101 ,
void * V_78 )
{
struct V_102 * V_52 = V_49 -> V_52 ;
struct V_50 * V_51 = V_52 -> V_53 ;
struct V_103 * V_65 = V_51 -> V_65 ;
struct V_54 V_55 = {} ;
struct V_11 * V_104 ;
T_3 * V_89 = NULL ;
int V_90 = V_88 * V_49 -> V_96 ;
int V_105 = sizeof( struct V_11 ) + V_90 ;
int V_56 = 0 ;
V_55 . V_106 . V_58 = V_107 ;
V_55 . V_106 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 . V_106 . V_108 = F_15 ( V_100 . V_100 ) ;
V_104 = F_19 ( V_105 , V_63 ) ;
if ( ! V_104 )
return - V_64 ;
V_89 = F_19 ( V_88 , V_63 ) ;
if ( ! V_89 ) {
V_56 = - V_64 ;
goto V_69;
}
V_56 = F_10 ( V_65 -> V_66 , (struct V_67 * ) & V_55 ,
V_104 , V_105 ) ;
if ( V_56 ) {
F_16 ( V_65 -> V_86 , L_3 , V_56 ) ;
V_56 = - V_68 ;
goto V_69;
}
if ( V_104 -> V_109 [ 0 ] != 'B' || V_104 -> V_109 [ 1 ] != 'B' ||
V_104 -> V_109 [ 2 ] != 'L' || V_104 -> V_109 [ 3 ] != 'T' ) {
F_16 ( V_65 -> V_86 , L_4 ) ;
V_56 = - V_46 ;
goto V_69;
}
if ( F_5 ( V_104 -> V_110 ) != 1 ) {
V_56 = - V_46 ;
F_16 ( V_65 -> V_86 , L_5 ) ;
goto V_69;
}
if ( F_6 ( V_104 -> V_111 ) != V_90 ) {
V_56 = - V_46 ;
F_16 ( V_65 -> V_86 , L_6 ,
F_6 ( V_104 -> V_111 ) , V_90 ) ;
goto V_69;
}
F_17 ( V_49 , V_88 , V_89 ,
V_90 , V_104 -> V_92 ) ;
V_100 = F_20 ( V_49 , V_100 ) ;
V_56 = V_101 ( V_100 , V_88 , V_89 , V_78 ) ;
V_69:
F_11 ( V_89 ) ;
F_11 ( V_104 ) ;
return V_56 ;
}
static int F_21 ( struct V_48 * V_49 , struct V_112 * V_113 ,
int type )
{
struct V_50 * V_51 = V_49 -> V_52 -> V_53 ;
struct V_54 V_55 = {} ;
int V_56 = 0 ;
V_55 . V_114 . V_58 = V_115 ;
V_55 . V_114 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 . V_114 . V_108 = F_15 ( V_113 -> V_99 . V_100 ) ;
V_55 . V_114 . V_76 = F_22 ( V_113 -> V_116 - 1 ) ;
V_55 . V_114 . V_117 = type ;
V_56 = F_10 ( V_51 -> V_65 -> V_66 , (struct V_67 * ) & V_55 ,
NULL , 0 ) ;
if ( V_56 )
F_16 ( V_51 -> V_65 -> V_86 , L_7 , V_56 ) ;
return V_56 ;
}
static inline void F_23 ( struct V_118 * V_119 , struct V_112 * V_113 ,
struct V_50 * V_51 , struct V_54 * V_55 )
{
V_55 -> V_120 . V_58 = V_113 -> V_58 ;
V_55 -> V_120 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 -> V_120 . V_108 = F_15 ( V_113 -> V_99 . V_100 ) ;
V_55 -> V_120 . V_121 = F_22 ( V_113 -> V_122 ) ;
V_55 -> V_120 . V_123 = F_22 ( V_113 -> V_116 - 1 ) ;
if ( V_113 -> V_58 == V_124 || V_113 -> V_58 == V_125 )
V_55 -> V_126 . V_75 = F_15 ( F_24 ( V_51 ,
V_113 -> V_127 -> V_128 . V_129 ) ) ;
}
static void F_25 ( struct V_118 * V_119 , int error )
{
struct V_112 * V_113 = V_119 -> V_130 ;
struct V_131 * V_132 = V_119 -> V_133 ;
if ( V_132 )
V_113 -> V_134 = F_26 ( V_132 -> V_135 ) ;
F_27 ( V_113 , error ) ;
F_11 ( V_119 -> V_136 ) ;
F_28 ( V_119 ) ;
}
static int F_29 ( struct V_48 * V_86 , struct V_112 * V_113 )
{
struct V_102 * V_52 = V_86 -> V_52 ;
struct V_50 * V_51 = V_52 -> V_53 ;
struct V_118 * V_119 ;
struct V_127 * V_127 = V_113 -> V_127 ;
struct V_54 * V_136 ;
V_119 = F_30 ( V_52 , F_31 ( V_127 ) , 0 ) ;
if ( F_32 ( V_119 ) )
return - V_64 ;
V_136 = F_19 ( sizeof( struct V_54 ) +
sizeof( struct V_131 ) , V_63 ) ;
if ( ! V_136 ) {
F_28 ( V_119 ) ;
return - V_64 ;
}
V_119 -> V_137 = V_138 ;
V_119 -> V_139 = F_33 ( V_127 ) ;
if ( F_34 ( V_127 ) )
V_119 -> V_140 = F_35 ( V_52 , V_127 ) ;
V_119 -> V_141 = V_127 -> V_128 . V_142 ;
V_119 -> V_127 = V_119 -> V_143 = V_127 ;
F_23 ( V_119 , V_113 , V_51 , V_136 ) ;
V_119 -> V_136 = ( unsigned char * ) V_136 ;
V_119 -> V_144 = sizeof( struct V_54 ) ;
V_119 -> V_133 = V_136 + 1 ;
V_119 -> V_130 = V_113 ;
F_36 ( V_52 , NULL , V_119 , 0 , F_25 ) ;
return 0 ;
}
static int F_37 ( struct V_48 * V_86 , struct V_112 * V_113 )
{
struct V_102 * V_52 = V_86 -> V_52 ;
struct V_50 * V_51 = V_52 -> V_53 ;
struct V_54 V_55 = {} ;
V_55 . V_145 . V_58 = V_146 ;
V_55 . V_145 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 . V_145 . V_108 = F_15 ( V_113 -> V_99 . V_100 ) ;
V_55 . V_145 . V_123 = F_22 ( V_113 -> V_116 - 1 ) ;
return F_10 ( V_52 , (struct V_67 * ) & V_55 , NULL , 0 ) ;
}
static void * F_38 ( struct V_48 * V_49 , char * V_147 )
{
struct V_50 * V_51 = V_49 -> V_52 -> V_53 ;
return F_39 ( V_147 , V_51 -> V_65 -> V_86 , V_148 , V_148 , 0 ) ;
}
static void F_40 ( void * V_149 )
{
struct V_150 * V_150 = V_149 ;
F_41 ( V_150 ) ;
}
static void * F_42 ( struct V_48 * V_86 , void * V_149 ,
T_5 V_151 , T_6 * V_152 )
{
return F_43 ( V_149 , V_151 , V_152 ) ;
}
static void F_44 ( void * V_149 , void * V_153 ,
T_6 V_152 )
{
F_45 ( V_149 , V_153 , V_152 ) ;
}
int F_46 ( struct V_102 * V_52 , char * V_154 )
{
return F_47 ( V_52 , V_154 , & V_155 ) ;
}
void F_48 ( struct V_102 * V_52 , char * V_154 )
{
F_49 ( V_154 ) ;
}
int F_50 ( struct V_50 * V_51 , struct V_156 * V_42 )
{
struct V_103 * V_65 = V_51 -> V_65 ;
struct V_157 * V_158 = F_51 ( V_65 -> V_86 ) ;
if ( V_158 -> V_159 == V_160 &&
V_158 -> V_161 == V_162 &&
V_42 -> V_163 [ 0 ] == 0x1 )
return 1 ;
if ( V_158 -> V_159 == V_160 &&
V_158 -> V_161 == V_164 &&
V_42 -> V_163 [ 0 ] == 0x1 )
return 1 ;
return 0 ;
}
