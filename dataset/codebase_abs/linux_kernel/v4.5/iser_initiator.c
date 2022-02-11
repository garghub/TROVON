static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
int V_8 ;
struct V_9 * V_10 = & V_4 -> V_11 . V_12 ;
struct V_13 * V_14 = & V_4 -> V_15 [ V_16 ] ;
V_8 = F_2 ( V_4 ,
V_14 ,
V_16 ,
V_17 ) ;
if ( V_8 )
return V_8 ;
if ( F_3 ( V_4 -> V_18 ) ) {
struct V_13 * V_19 = & V_4 -> V_20 [ V_16 ] ;
V_8 = F_2 ( V_4 ,
V_19 ,
V_16 ,
V_17 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_4 ( V_4 , V_16 , false ) ;
if ( V_8 ) {
F_5 ( L_1 ) ;
return V_8 ;
}
V_7 = & V_4 -> V_21 [ V_16 ] ;
V_10 -> V_22 |= V_23 ;
V_10 -> V_24 = F_6 ( V_7 -> V_25 ) ;
V_10 -> V_26 = F_7 ( V_7 -> V_27 . V_28 ) ;
F_8 ( L_2 ,
V_2 -> V_29 , V_7 -> V_25 ,
( unsigned long long ) V_7 -> V_27 . V_28 ) ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 ,
unsigned int V_30 ,
unsigned int V_31 ,
unsigned int V_32 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
int V_8 ;
struct V_9 * V_10 = & V_4 -> V_11 . V_12 ;
struct V_13 * V_33 = & V_4 -> V_15 [ V_34 ] ;
struct V_35 * V_36 = & V_4 -> V_11 . V_37 [ 1 ] ;
V_8 = F_2 ( V_4 ,
V_33 ,
V_34 ,
V_38 ) ;
if ( V_8 )
return V_8 ;
if ( F_3 ( V_4 -> V_18 ) ) {
struct V_13 * V_39 = & V_4 -> V_20 [ V_34 ] ;
V_8 = F_2 ( V_4 ,
V_39 ,
V_34 ,
V_38 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_4 ( V_4 , V_34 ,
V_33 -> V_40 == V_30 ) ;
if ( V_8 != 0 ) {
F_5 ( L_3 ) ;
return V_8 ;
}
V_7 = & V_4 -> V_21 [ V_34 ] ;
if ( V_31 < V_32 ) {
V_10 -> V_22 |= V_41 ;
V_10 -> V_42 = F_6 ( V_7 -> V_25 ) ;
V_10 -> V_43 = F_7 ( V_7 -> V_27 . V_28 + V_31 ) ;
F_8 ( L_4
L_5 ,
V_2 -> V_29 , V_7 -> V_25 ,
( unsigned long long ) V_7 -> V_27 . V_28 , V_31 ) ;
}
if ( V_30 > 0 ) {
F_8 ( L_6 ,
V_2 -> V_29 , V_30 ) ;
V_36 -> V_28 = V_7 -> V_27 . V_28 ;
V_36 -> V_44 = V_30 ;
V_36 -> V_45 = V_7 -> V_27 . V_45 ;
V_4 -> V_11 . V_46 = 2 ;
}
return 0 ;
}
static void F_10 ( struct V_47 * V_47 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 = V_47 -> V_52 . V_51 ;
F_11 ( V_51 -> V_53 ,
V_49 -> V_54 , V_55 , V_38 ) ;
memset ( & V_49 -> V_12 , 0 , sizeof( struct V_9 ) ) ;
V_49 -> V_12 . V_22 = V_56 ;
V_49 -> V_46 = 1 ;
}
static void F_12 ( struct V_47 * V_47 )
{
struct V_50 * V_51 = V_47 -> V_52 . V_51 ;
struct V_57 * V_11 = & V_47 -> V_58 ;
if ( ! V_11 -> V_59 )
return;
F_13 ( V_51 -> V_53 , V_11 -> V_60 ,
V_61 , V_38 ) ;
F_13 ( V_51 -> V_53 , V_11 -> V_62 ,
V_63 , V_17 ) ;
F_14 ( V_11 -> V_59 ) ;
F_14 ( V_11 -> V_64 ) ;
V_11 -> V_59 = NULL ;
V_11 -> V_64 = NULL ;
}
static int F_15 ( struct V_47 * V_47 )
{
struct V_50 * V_51 = V_47 -> V_52 . V_51 ;
struct V_57 * V_11 = & V_47 -> V_58 ;
V_11 -> V_59 = F_16 ( V_61 , V_65 ) ;
if ( ! V_11 -> V_59 )
return - V_66 ;
V_11 -> V_60 = F_17 ( V_51 -> V_53 , V_11 -> V_59 ,
V_61 ,
V_38 ) ;
if ( F_18 ( V_51 -> V_53 ,
V_11 -> V_60 ) )
goto V_67;
V_11 -> V_64 = F_16 ( V_63 , V_65 ) ;
if ( ! V_11 -> V_64 )
goto V_68;
V_11 -> V_62 = F_17 ( V_51 -> V_53 , V_11 -> V_64 ,
V_63 ,
V_17 ) ;
if ( F_18 ( V_51 -> V_53 ,
V_11 -> V_62 ) )
goto V_69;
return 0 ;
V_69:
F_14 ( V_11 -> V_64 ) ;
V_68:
F_13 ( V_51 -> V_53 , V_11 -> V_60 ,
V_61 ,
V_38 ) ;
V_67:
F_14 ( V_11 -> V_59 ) ;
return - V_66 ;
}
int F_19 ( struct V_47 * V_47 ,
struct V_70 * V_71 )
{
int V_72 , V_73 ;
T_1 V_54 ;
struct V_74 * V_75 ;
struct V_35 * V_76 ;
struct V_52 * V_52 = & V_47 -> V_52 ;
struct V_50 * V_51 = V_52 -> V_51 ;
V_47 -> V_77 = V_71 -> V_78 ;
V_47 -> V_79 = V_71 -> V_78 - 1 ;
V_47 -> V_80 = V_47 -> V_77 >> 2 ;
if ( V_51 -> V_81 -> V_82 ( V_52 , V_71 -> V_83 ,
V_47 -> V_84 ) )
goto V_85;
if ( F_15 ( V_47 ) )
goto V_86;
V_47 -> V_87 = V_71 -> V_78 ;
V_47 -> V_88 = F_16 ( V_47 -> V_87 *
sizeof( struct V_74 ) , V_65 ) ;
if ( ! V_47 -> V_88 )
goto V_89;
V_75 = V_47 -> V_88 ;
for ( V_72 = 0 ; V_72 < V_47 -> V_77 ; V_72 ++ , V_75 ++ ) {
V_54 = F_17 ( V_51 -> V_53 , ( void * ) V_75 ,
V_90 , V_17 ) ;
if ( F_18 ( V_51 -> V_53 , V_54 ) )
goto V_91;
V_75 -> V_54 = V_54 ;
V_75 -> V_92 . V_93 = V_94 ;
V_76 = & V_75 -> V_76 ;
V_76 -> V_28 = V_75 -> V_54 ;
V_76 -> V_44 = V_90 ;
V_76 -> V_45 = V_51 -> V_95 -> V_96 ;
}
V_47 -> V_97 = 0 ;
return 0 ;
V_91:
V_75 = V_47 -> V_88 ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ , V_75 ++ )
F_13 ( V_51 -> V_53 , V_75 -> V_54 ,
V_90 , V_17 ) ;
F_14 ( V_47 -> V_88 ) ;
V_47 -> V_88 = NULL ;
V_89:
F_12 ( V_47 ) ;
V_86:
V_51 -> V_81 -> V_98 ( V_52 ) ;
V_85:
F_5 ( L_7 ) ;
return - V_66 ;
}
void F_20 ( struct V_47 * V_47 )
{
int V_72 ;
struct V_74 * V_75 ;
struct V_52 * V_52 = & V_47 -> V_52 ;
struct V_50 * V_51 = V_52 -> V_51 ;
if ( V_51 -> V_81 -> V_98 )
V_51 -> V_81 -> V_98 ( V_52 ) ;
V_75 = V_47 -> V_88 ;
for ( V_72 = 0 ; V_72 < V_47 -> V_77 ; V_72 ++ , V_75 ++ )
F_13 ( V_51 -> V_53 , V_75 -> V_54 ,
V_90 , V_17 ) ;
F_14 ( V_47 -> V_88 ) ;
V_47 -> V_88 = NULL ;
F_12 ( V_47 ) ;
}
static int F_21 ( struct V_99 * V_100 , struct V_101 * V_59 )
{
struct V_47 * V_47 = V_100 -> V_5 ;
struct V_52 * V_52 = & V_47 -> V_52 ;
struct V_70 * V_71 = V_100 -> V_71 ;
F_8 ( L_8 , V_59 -> V_102 , V_59 -> V_22 ) ;
if ( ( V_59 -> V_22 & V_103 ) != V_103 )
return 0 ;
F_22 ( V_52 -> V_104 != 1 ) ;
if ( V_71 -> V_105 ) {
F_23 ( L_9 ) ;
return 0 ;
} else
F_23 ( L_10 ,
V_47 -> V_80 ) ;
if ( F_24 ( V_47 , V_47 -> V_80 ) )
return - V_66 ;
return 0 ;
}
static inline bool F_25 ( T_2 V_106 )
{
return ( ( V_106 % V_107 ) == 0 ) ;
}
int F_26 ( struct V_99 * V_100 ,
struct V_1 * V_2 )
{
struct V_47 * V_47 = V_100 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_32 ;
int V_8 ;
struct V_13 * V_108 , * V_109 ;
struct V_110 * V_10 = (struct V_110 * ) V_2 -> V_10 ;
struct V_111 * V_18 = V_2 -> V_18 ;
struct V_48 * V_49 = & V_4 -> V_11 ;
T_2 V_106 = ++ V_47 -> V_52 . V_106 ;
V_32 = F_27 ( V_10 -> V_112 ) ;
V_49 -> type = V_113 ;
V_49 -> V_92 . V_93 = V_114 ;
F_10 ( V_47 , V_49 ) ;
if ( V_10 -> V_22 & V_115 ) {
V_108 = & V_4 -> V_15 [ V_16 ] ;
V_109 = & V_4 -> V_20 [ V_16 ] ;
} else {
V_108 = & V_4 -> V_15 [ V_34 ] ;
V_109 = & V_4 -> V_20 [ V_34 ] ;
}
if ( F_28 ( V_18 ) ) {
V_108 -> V_116 = F_29 ( V_18 ) ;
V_108 -> V_117 = F_28 ( V_18 ) ;
}
V_108 -> V_40 = F_30 ( V_18 ) ;
if ( F_3 ( V_18 ) ) {
V_109 -> V_116 = F_31 ( V_18 ) ;
V_109 -> V_117 = F_3 ( V_18 ) ;
V_109 -> V_40 = ( V_108 -> V_40 >>
F_32 ( V_18 -> V_51 -> V_118 ) ) * 8 ;
}
if ( V_10 -> V_22 & V_115 ) {
V_8 = F_1 ( V_2 ) ;
if ( V_8 )
goto V_119;
}
if ( V_10 -> V_22 & V_120 ) {
V_8 = F_9 ( V_2 ,
V_2 -> V_121 ,
V_2 -> V_121 +
V_2 -> V_122 . V_112 ,
V_32 ) ;
if ( V_8 )
goto V_119;
}
V_4 -> V_123 = V_124 ;
V_8 = F_33 ( & V_47 -> V_52 , V_49 ,
F_25 ( V_106 ) ) ;
if ( ! V_8 )
return 0 ;
V_119:
F_5 ( L_11 , V_100 , V_2 -> V_29 , V_8 ) ;
return V_8 ;
}
int F_34 ( struct V_99 * V_100 ,
struct V_1 * V_2 ,
struct V_125 * V_10 )
{
struct V_47 * V_47 = V_100 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_48 * V_49 = NULL ;
struct V_6 * V_7 ;
unsigned long V_126 ;
unsigned long V_127 ;
T_3 V_29 ;
int V_8 ;
struct V_35 * V_36 ;
V_29 = ( V_128 T_3 ) V_10 -> V_29 ;
V_127 = F_35 ( V_10 -> V_129 ) ;
V_126 = F_27 ( V_10 -> V_130 ) ;
F_8 ( L_12 ,
V_131 , ( int ) V_29 , ( int ) V_127 , ( int ) V_126 ) ;
V_49 = F_36 ( V_132 . V_133 , V_134 ) ;
if ( V_49 == NULL ) {
F_5 ( L_13 ) ;
return - V_66 ;
}
V_49 -> type = V_135 ;
V_49 -> V_92 . V_93 = V_136 ;
V_49 -> V_12 . V_22 = V_56 ;
memcpy ( & V_49 -> V_137 , V_10 , sizeof( struct V_101 ) ) ;
V_8 = F_37 ( V_2 , V_49 ) ;
if ( V_8 )
goto V_138;
V_7 = & V_4 -> V_21 [ V_34 ] ;
V_36 = & V_49 -> V_37 [ 1 ] ;
V_36 -> V_28 = V_7 -> V_27 . V_28 + V_126 ;
V_36 -> V_44 = V_127 ;
V_36 -> V_45 = V_7 -> V_27 . V_45 ;
V_49 -> V_46 = 2 ;
if ( V_126 + V_127 > V_4 -> V_15 [ V_34 ] . V_40 ) {
F_5 ( L_14
L_15 ,
V_126 , V_127 ,
V_4 -> V_15 [ V_34 ] . V_40 , V_29 ) ;
V_8 = - V_139 ;
goto V_138;
}
F_8 ( L_16 ,
V_29 , V_126 , V_127 ) ;
V_8 = F_33 ( & V_47 -> V_52 , V_49 , true ) ;
if ( ! V_8 )
return 0 ;
V_138:
F_38 ( V_132 . V_133 , V_49 ) ;
F_5 ( L_17 , V_100 , V_8 ) ;
return V_8 ;
}
int F_39 ( struct V_99 * V_100 ,
struct V_1 * V_2 )
{
struct V_47 * V_47 = V_100 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_48 * V_140 = & V_4 -> V_11 ;
unsigned long V_127 ;
int V_8 = 0 ;
struct V_50 * V_51 ;
V_140 -> type = V_141 ;
V_140 -> V_92 . V_93 = V_142 ;
F_10 ( V_47 , V_140 ) ;
V_51 = V_47 -> V_52 . V_51 ;
V_127 = F_35 ( V_2 -> V_10 -> V_129 ) ;
if ( V_127 > 0 ) {
struct V_57 * V_11 = & V_47 -> V_58 ;
struct V_35 * V_36 = & V_140 -> V_37 [ 1 ] ;
if ( V_2 != V_100 -> V_143 ) {
F_5 ( L_18 ) ;
goto V_144;
}
F_11 ( V_51 -> V_53 , V_11 -> V_60 ,
V_2 -> V_145 , V_38 ) ;
memcpy ( V_11 -> V_59 , V_2 -> V_15 , V_2 -> V_145 ) ;
F_40 ( V_51 -> V_53 , V_11 -> V_60 ,
V_2 -> V_145 , V_38 ) ;
V_36 -> V_28 = V_11 -> V_60 ;
V_36 -> V_44 = V_2 -> V_145 ;
V_36 -> V_45 = V_51 -> V_95 -> V_96 ;
V_140 -> V_46 = 2 ;
}
if ( V_2 == V_100 -> V_143 ) {
F_8 ( L_19 ,
V_2 -> V_10 -> V_102 , V_127 ) ;
V_8 = F_41 ( V_47 ) ;
if ( V_8 )
goto V_144;
V_8 = F_21 ( V_100 , V_2 -> V_10 ) ;
if ( V_8 )
goto V_144;
}
V_8 = F_33 ( & V_47 -> V_52 , V_140 , true ) ;
if ( ! V_8 )
return 0 ;
V_144:
F_5 ( L_17 , V_100 , V_8 ) ;
return V_8 ;
}
void F_42 ( struct V_146 * V_147 , struct V_148 * V_149 )
{
struct V_52 * V_52 = V_149 -> V_150 -> V_151 ;
struct V_47 * V_47 = F_43 ( V_52 ) ;
struct V_57 * V_11 = F_44 ( V_149 -> V_152 ) ;
struct V_101 * V_10 ;
char * V_15 ;
int V_44 ;
if ( F_45 ( V_149 -> V_123 != V_153 ) ) {
F_46 ( V_149 , L_20 ) ;
return;
}
F_11 ( V_52 -> V_51 -> V_53 ,
V_11 -> V_62 , V_63 ,
V_17 ) ;
V_10 = V_11 -> V_64 + sizeof( struct V_9 ) ;
V_15 = V_11 -> V_64 + V_55 ;
V_44 = V_149 -> V_154 - V_55 ;
F_8 ( L_21 , V_10 -> V_102 ,
V_10 -> V_29 , V_44 ) ;
F_47 ( V_47 -> V_99 , V_10 , V_15 , V_44 ) ;
F_40 ( V_52 -> V_51 -> V_53 ,
V_11 -> V_62 , V_63 ,
V_17 ) ;
V_52 -> V_104 -- ;
}
static inline void
F_48 ( struct V_155 * V_11 , T_4 V_25 )
{
if ( F_49 ( V_25 == V_11 -> V_156 . V_157 -> V_25 ) )
V_11 -> V_156 . V_158 = 0 ;
else if ( F_49 ( V_25 == V_11 -> V_159 -> V_160 -> V_25 ) )
V_11 -> V_159 -> V_161 = 0 ;
}
static int
F_50 ( struct V_47 * V_47 ,
struct V_148 * V_149 ,
struct V_101 * V_10 )
{
if ( V_149 -> V_162 & V_163 ) {
struct V_1 * V_2 ;
T_4 V_25 = V_149 -> V_164 . V_165 ;
F_8 ( L_22 ,
V_47 , V_25 ) ;
if ( F_45 ( ! V_47 -> V_166 ) ) {
F_5 ( L_23
L_24 , V_47 ) ;
return - V_167 ;
}
V_2 = F_51 ( V_47 -> V_99 , V_10 -> V_29 ) ;
if ( F_49 ( V_2 ) ) {
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_155 * V_11 ;
if ( V_4 -> V_168 [ V_16 ] ) {
V_11 = V_4 -> V_21 [ V_16 ] . V_169 ;
F_48 ( V_11 , V_25 ) ;
}
if ( V_4 -> V_168 [ V_34 ] ) {
V_11 = V_4 -> V_21 [ V_34 ] . V_169 ;
F_48 ( V_11 , V_25 ) ;
}
} else {
F_5 ( L_25 , V_10 -> V_29 ) ;
return - V_139 ;
}
}
return 0 ;
}
void V_94 ( struct V_146 * V_147 , struct V_148 * V_149 )
{
struct V_52 * V_52 = V_149 -> V_150 -> V_151 ;
struct V_47 * V_47 = F_43 ( V_52 ) ;
struct V_74 * V_11 = F_52 ( V_149 -> V_152 ) ;
struct V_101 * V_10 ;
int V_44 ;
int V_170 , V_171 , V_8 ;
if ( F_45 ( V_149 -> V_123 != V_153 ) ) {
F_46 ( V_149 , L_26 ) ;
return;
}
F_11 ( V_52 -> V_51 -> V_53 ,
V_11 -> V_54 , V_90 ,
V_17 ) ;
V_10 = & V_11 -> V_137 ;
V_44 = V_149 -> V_154 - V_55 ;
F_8 ( L_21 , V_10 -> V_102 ,
V_10 -> V_29 , V_44 ) ;
if ( F_50 ( V_47 , V_149 , V_10 ) ) {
F_53 ( V_47 -> V_99 ,
V_172 ) ;
return;
}
F_47 ( V_47 -> V_99 , V_10 , V_11 -> V_15 , V_44 ) ;
F_40 ( V_52 -> V_51 -> V_53 ,
V_11 -> V_54 , V_90 ,
V_17 ) ;
V_52 -> V_104 -- ;
V_170 = V_52 -> V_104 ;
if ( V_170 + V_47 -> V_80 <= V_47 -> V_77 ) {
V_171 = F_54 ( V_47 -> V_77 - V_170 ,
V_47 -> V_80 ) ;
V_8 = F_24 ( V_47 , V_171 ) ;
if ( V_8 )
F_5 ( L_27 , V_171 , V_8 ) ;
}
}
void V_114 ( struct V_146 * V_147 , struct V_148 * V_149 )
{
if ( F_45 ( V_149 -> V_123 != V_153 ) )
F_46 ( V_149 , L_28 ) ;
}
void V_142 ( struct V_146 * V_147 , struct V_148 * V_149 )
{
struct V_48 * V_11 = F_55 ( V_149 -> V_152 ) ;
struct V_1 * V_2 ;
if ( F_45 ( V_149 -> V_123 != V_153 ) ) {
F_46 ( V_149 , L_29 ) ;
return;
}
V_2 = ( void * ) V_11 - sizeof( struct V_1 ) ;
if ( V_2 -> V_10 -> V_29 == V_173 )
F_56 ( V_2 ) ;
}
void V_136 ( struct V_146 * V_147 , struct V_148 * V_149 )
{
struct V_48 * V_11 = F_55 ( V_149 -> V_152 ) ;
struct V_52 * V_52 = V_149 -> V_150 -> V_151 ;
struct V_50 * V_51 = V_52 -> V_51 ;
if ( F_45 ( V_149 -> V_123 != V_153 ) )
F_46 ( V_149 , L_30 ) ;
F_13 ( V_51 -> V_53 , V_11 -> V_54 ,
V_55 , V_38 ) ;
F_38 ( V_132 . V_133 , V_11 ) ;
}
void F_57 ( struct V_146 * V_147 , struct V_148 * V_149 )
{
struct V_52 * V_52 = V_149 -> V_150 -> V_151 ;
F_58 ( & V_52 -> V_174 ) ;
}
void F_59 ( struct V_3 * V_4 )
{
V_4 -> V_123 = V_175 ;
V_4 -> V_168 [ V_16 ] = 0 ;
V_4 -> V_168 [ V_34 ] = 0 ;
V_4 -> V_15 [ V_16 ] . V_40 = 0 ;
V_4 -> V_15 [ V_34 ] . V_40 = 0 ;
V_4 -> V_20 [ V_16 ] . V_40 = 0 ;
V_4 -> V_20 [ V_34 ] . V_40 = 0 ;
memset ( & V_4 -> V_21 [ V_16 ] , 0 ,
sizeof( struct V_6 ) ) ;
memset ( & V_4 -> V_21 [ V_34 ] , 0 ,
sizeof( struct V_6 ) ) ;
}
void F_60 ( struct V_3 * V_4 )
{
int V_176 = F_3 ( V_4 -> V_18 ) ;
if ( V_4 -> V_168 [ V_16 ] ) {
F_61 ( V_4 , V_16 ) ;
F_62 ( V_4 ,
& V_4 -> V_15 [ V_16 ] ,
V_17 ) ;
if ( V_176 )
F_62 ( V_4 ,
& V_4 -> V_20 [ V_16 ] ,
V_17 ) ;
}
if ( V_4 -> V_168 [ V_34 ] ) {
F_61 ( V_4 , V_34 ) ;
F_62 ( V_4 ,
& V_4 -> V_15 [ V_34 ] ,
V_38 ) ;
if ( V_176 )
F_62 ( V_4 ,
& V_4 -> V_20 [ V_34 ] ,
V_38 ) ;
}
}
