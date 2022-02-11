int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_4 -> V_9 = F_2 ( V_2 -> V_10 , V_11 ,
& V_4 -> V_12 ) ;
if ( ! V_4 -> V_9 ) {
F_3 ( & V_8 -> V_13 , L_1 ) ;
return - V_14 ;
}
return 0 ;
}
void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_5 ( V_2 -> V_10 , V_4 -> V_9 , V_4 -> V_12 ) ;
}
static unsigned int F_6 ( enum V_15 V_16 )
{
unsigned int V_17 = 0 ;
switch ( V_16 ) {
case V_18 :
V_17 = V_19 ;
break;
case V_20 :
V_17 = V_21 ;
break;
}
return V_17 ;
}
static void F_7 ( struct V_22 * V_23 ,
struct V_3 * V_24 )
{
struct V_25 * V_26 = & V_23 -> V_26 ;
F_8 ( & V_26 -> V_27 , V_24 -> V_12 , V_24 -> V_28 ) ;
}
static void F_9 ( struct V_29 * V_30 , int V_31 ,
enum V_32 V_33 ,
enum V_34 V_35 , T_1 V_36 , T_2 V_37 ,
enum V_38 V_39 ,
enum V_40 V_40 ,
enum V_15 V_41 )
{
struct V_42 * V_43 ;
struct V_44 * V_45 ;
enum V_46 V_47 ;
struct V_48 * V_49 ;
T_3 V_50 ;
if ( V_40 == V_51 ) {
V_43 = & V_30 -> V_43 ;
V_43 -> V_52 . V_53 = 0 ;
V_49 = & V_43 -> V_49 ;
V_47 = V_54 ;
} else {
V_45 = & V_30 -> V_55 . V_45 ;
V_45 -> V_52 . V_53 = 0 ;
V_49 = & V_45 -> V_49 ;
V_47 = V_56 ;
}
V_49 -> V_57 = F_10 ( V_37 , V_58 ) |
F_10 ( V_36 , V_59 ) |
F_10 ( V_35 , V_60 ) |
F_10 ( V_33 , V_61 ) ;
F_11 ( V_30 ) -> V_62 =
F_12 ( V_41 , V_63 ) |
F_12 ( V_39 , V_64 ) |
F_12 ( V_40 , V_65 ) |
F_12 ( V_66 , V_67 ) |
F_12 ( V_68 , V_69 ) |
F_12 ( V_47 , V_70 ) |
F_12 ( V_31 , V_71 ) ;
V_50 = F_11 ( V_30 ) -> V_50 ;
V_50 = F_13 ( V_50 , V_72 ) ;
if ( ( V_36 == V_73 ) && ( V_35 == V_74 ) )
F_11 ( V_30 ) -> V_50 |=
F_14 ( 1 , V_72 ) ;
else
F_11 ( V_30 ) -> V_50 = V_50 ;
}
static void F_15 ( struct V_42 * V_43 ,
struct V_3 * V_75 )
{
F_8 ( & V_43 -> V_76 . V_27 , V_75 -> V_12 , V_75 -> V_28 ) ;
}
static void F_16 ( struct V_77 * V_30 ,
void * V_75 , T_3 V_78 )
{
struct V_44 * V_45 = & V_30 -> V_45 ;
V_45 -> V_76 . V_41 = V_78 ;
memcpy ( V_45 -> V_76 . V_79 , V_75 , V_78 ) ;
}
static void F_17 ( struct V_29 * V_30 ,
enum V_80 V_81 ,
struct V_3 * V_75 ,
struct V_3 * V_24 , int V_31 ,
enum V_32 V_33 ,
enum V_34 V_35 , T_1 V_36 , T_2 V_37 )
{
struct V_42 * V_43 = & V_30 -> V_43 ;
enum V_38 V_39 ;
switch ( V_81 ) {
case V_82 :
V_39 = V_83 ;
F_7 ( & V_43 -> V_23 , V_24 ) ;
break;
case V_84 :
V_39 = V_85 ;
V_43 -> V_23 . V_86 = 0 ;
break;
}
F_9 ( V_30 , V_31 , V_33 , V_35 , V_36 ,
V_37 , V_39 , V_51 ,
V_18 ) ;
F_15 ( V_43 , V_75 ) ;
}
static void F_18 ( struct V_29 * V_30 ,
enum V_80 V_81 ,
void * V_75 , T_2 V_78 ,
struct V_3 * V_24 , int V_31 ,
enum V_32 V_33 ,
enum V_34 V_35 , T_1 V_36 , T_2 V_37 )
{
struct V_77 * V_55 = & V_30 -> V_55 ;
enum V_38 V_39 ;
struct V_44 * V_45 ;
V_45 = & V_55 -> V_45 ;
switch ( V_81 ) {
case V_82 :
V_39 = V_83 ;
F_7 ( & V_45 -> V_23 , V_24 ) ;
break;
case V_84 :
V_39 = V_85 ;
V_45 -> V_23 . V_86 = 0 ;
break;
}
F_9 ( V_30 , V_31 , V_33 , V_35 , V_36 , V_37 ,
V_39 , V_87 , V_20 ) ;
F_16 ( V_55 , V_75 , V_78 ) ;
}
static void F_19 ( void * V_88 , void * V_89 )
{
memcpy ( V_88 + V_90 , V_89 + V_90 ,
V_91 - V_90 ) ;
F_20 () ;
* ( V_92 * ) V_88 = * ( V_92 * ) V_89 ;
}
static void F_21 ( T_3 * V_93 ,
enum V_94 V_95 , T_2 V_37 )
{
* V_93 = F_22 ( F_23 ( V_37 ) , V_96 ) |
F_22 ( V_97 , V_98 ) |
F_22 ( V_95 , V_99 ) |
F_22 ( V_100 , V_101 ) ;
}
static void F_24 ( struct V_102 * V_103 ,
enum V_94 V_95 , T_2 V_37 )
{
T_3 V_93 ;
F_21 ( & V_93 , V_95 , V_37 ) ;
V_93 = F_25 ( V_93 ) ;
F_20 () ;
F_26 ( V_93 , F_27 ( V_103 -> V_104 , V_37 ) ) ;
}
static int F_28 ( struct V_102 * V_103 ,
enum V_34 V_35 , T_1 V_36 ,
struct V_3 * V_75 ,
V_92 * V_105 )
{
struct V_29 * V_106 , V_107 ;
T_2 V_108 , V_109 ;
int V_110 , V_31 , V_111 ;
struct V_112 * V_113 = V_103 -> V_113 ;
struct V_114 * V_115 ;
struct V_23 V_116 ;
F_29 ( & V_103 -> V_117 ) ;
V_115 = F_30 ( V_113 , V_19 , & V_108 ) ;
if ( F_31 ( V_115 ) ) {
F_32 ( & V_103 -> V_117 ) ;
return - V_118 ;
}
V_106 = & V_115 -> V_107 ;
V_31 = V_103 -> V_31 ;
V_111 = F_33 ( V_19 , V_113 -> V_119 ) / V_113 -> V_119 ;
V_109 = V_108 + V_111 ;
if ( V_109 >= V_113 -> V_120 ) {
V_103 -> V_31 = ! V_103 -> V_31 ;
V_109 -= V_113 -> V_120 ;
}
V_103 -> V_110 [ V_108 ] = & V_110 ;
F_34 ( & V_116 ) ;
V_103 -> V_116 [ V_108 ] = & V_116 ;
F_17 ( & V_107 , V_84 , V_75 , NULL ,
V_31 , V_121 , V_35 , V_36 ,
V_108 ) ;
F_35 ( & V_107 , V_19 ) ;
F_19 ( V_106 , & V_107 ) ;
F_24 ( V_103 , V_122 , V_109 ) ;
F_32 ( & V_103 -> V_117 ) ;
if ( ! F_36 ( & V_116 , V_123 ) ) {
F_29 ( & V_103 -> V_117 ) ;
if ( V_103 -> V_110 [ V_108 ] == & V_110 )
V_103 -> V_110 [ V_108 ] = NULL ;
if ( V_103 -> V_116 [ V_108 ] == & V_116 )
V_103 -> V_116 [ V_108 ] = NULL ;
F_32 ( & V_103 -> V_117 ) ;
return - V_124 ;
}
F_37 () ;
if ( V_105 ) {
struct V_42 * V_43 = & V_106 -> V_43 ;
* V_105 = F_38 ( V_43 -> V_23 . V_86 ) ;
}
if ( V_110 != 0 )
return - V_125 ;
return 0 ;
}
static int F_39 ( struct V_102 * V_103 , void * V_75 ,
T_2 V_78 )
{
struct V_29 * V_106 , V_107 ;
T_2 V_108 , V_109 ;
struct V_112 * V_113 = V_103 -> V_113 ;
struct V_114 * V_115 ;
int V_31 , V_111 ;
F_40 ( & V_103 -> V_117 ) ;
V_115 = F_30 ( V_113 , V_21 , & V_108 ) ;
if ( F_31 ( V_115 ) ) {
F_41 ( & V_103 -> V_117 ) ;
return - V_118 ;
}
V_106 = & V_115 -> V_107 ;
V_31 = V_103 -> V_31 ;
V_111 = F_33 ( V_21 , V_113 -> V_119 ) / V_113 -> V_119 ;
V_109 = V_108 + V_111 ;
if ( V_109 >= V_113 -> V_120 ) {
V_103 -> V_31 = ! V_103 -> V_31 ;
V_109 -= V_113 -> V_120 ;
}
F_18 ( & V_107 , V_84 , V_75 ,
V_78 , NULL , V_31 , V_121 ,
V_74 , V_73 , V_108 ) ;
F_35 ( & V_107 , V_21 ) ;
F_19 ( V_106 , & V_107 ) ;
F_24 ( V_103 , V_122 , V_109 ) ;
F_41 ( & V_103 -> V_117 ) ;
return 0 ;
}
static int F_42 ( struct V_3 * V_75 )
{
if ( V_75 -> V_28 > V_126 )
return - V_127 ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 ,
enum V_34 V_35 , T_1 V_36 ,
struct V_3 * V_75 , V_92 * V_105 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_128 ;
V_128 = F_42 ( V_75 ) ;
if ( V_128 ) {
F_3 ( & V_8 -> V_13 , L_2 ) ;
return V_128 ;
}
return F_28 ( & V_2 -> V_103 [ V_122 ] ,
V_35 , V_36 , V_75 , V_105 ) ;
}
int F_44 ( struct V_1 * V_2 ,
enum V_129 V_130 , T_3 V_131 )
{
struct V_102 * V_103 = & V_2 -> V_103 [ V_122 ] ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_132 V_133 ;
int V_128 ;
V_133 . V_130 = V_130 ;
V_133 . V_131 = V_131 ;
V_128 = F_39 ( V_103 , & V_133 , sizeof( V_133 ) ) ;
if ( V_128 ) {
F_3 ( & V_8 -> V_13 , L_3 , V_131 ) ;
return V_128 ;
}
return 0 ;
}
static void F_45 ( struct V_102 * V_103 ,
struct V_29 * V_30 )
{
T_3 V_62 = F_46 ( F_11 ( V_30 ) -> V_62 ) ;
unsigned int V_15 , V_17 ;
struct V_48 * V_49 ;
V_15 = F_47 ( V_62 , V_63 ) ;
V_17 = F_6 ( V_15 ) ;
if ( V_17 == V_19 ) {
struct V_42 * V_43 = & V_30 -> V_43 ;
V_49 = & V_43 -> V_49 ;
} else {
struct V_77 * V_55 = & V_30 -> V_55 ;
struct V_44 * V_45 ;
V_45 = & V_55 -> V_45 ;
V_49 = & V_45 -> V_49 ;
}
V_49 -> V_57 = 0 ;
F_20 () ;
}
static int F_48 ( struct V_102 * V_103 ,
struct V_29 * V_30 )
{
struct V_77 * V_55 = & V_30 -> V_55 ;
struct V_44 * V_45 ;
struct V_48 * V_49 ;
T_3 V_57 ;
V_45 = & V_55 -> V_45 ;
V_49 = & V_45 -> V_49 ;
V_57 = F_46 ( V_49 -> V_57 ) ;
if ( ! F_49 ( V_57 ) )
return - V_118 ;
F_45 ( V_103 , V_30 ) ;
F_50 ( V_103 -> V_113 , V_21 ) ;
return 0 ;
}
static void F_51 ( struct V_102 * V_103 , T_2 V_37 ,
int V_110 )
{
if ( V_103 -> V_110 [ V_37 ] )
* V_103 -> V_110 [ V_37 ] = V_110 ;
}
static void F_52 ( struct V_102 * V_103 , T_2 V_134 ,
int V_110 )
{
T_2 V_37 = V_134 ;
F_40 ( & V_103 -> V_117 ) ;
F_51 ( V_103 , V_37 , V_110 ) ;
F_20 () ;
if ( V_103 -> V_116 [ V_37 ] )
F_53 ( V_103 -> V_116 [ V_37 ] ) ;
F_41 ( & V_103 -> V_117 ) ;
}
static int F_54 ( struct V_102 * V_103 , T_2 V_135 ,
struct V_29 * V_107 )
{
struct V_42 * V_43 = & V_107 -> V_43 ;
struct V_136 * V_52 = & V_43 -> V_52 ;
struct V_48 * V_49 = & V_43 -> V_49 ;
int V_110 ;
if ( ! F_49 ( F_46 ( V_49 -> V_57 ) ) )
return - V_118 ;
V_110 = F_55 ( F_46 ( V_52 -> V_53 ) , V_137 ) ;
F_52 ( V_103 , V_135 , V_110 ) ;
F_45 ( V_103 , V_107 ) ;
F_50 ( V_103 -> V_113 , V_19 ) ;
return 0 ;
}
static void F_56 ( void * V_138 , T_3 V_139 )
{
enum V_94 V_95 = F_57 ( V_139 , TYPE ) ;
struct V_1 * V_2 = (struct V_1 * ) V_138 ;
struct V_102 * V_103 = & V_2 -> V_103 [ V_95 ] ;
struct V_140 * V_141 ;
struct V_114 * V_115 ;
int V_128 , V_142 = 0 ;
T_3 V_50 ;
T_2 V_135 ;
while ( ( V_115 = F_58 ( V_103 -> V_113 , V_21 , & V_135 ) ) ) {
if ( F_31 ( V_115 ) )
break;
V_141 = F_11 ( & V_115 -> V_107 ) ;
V_50 = F_46 ( V_141 -> V_50 ) ;
if ( F_59 ( V_50 , V_72 ) ) {
V_142 = 0 ;
if ( F_48 ( V_103 , & V_115 -> V_107 ) )
break;
} else {
V_142 = 1 ;
V_115 = F_58 ( V_103 -> V_113 , V_19 , & V_135 ) ;
if ( F_31 ( V_115 ) )
break;
if ( F_54 ( V_103 , V_135 , & V_115 -> V_107 ) )
break;
}
}
if ( V_142 ) {
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_128 = F_44 ( V_2 , V_143 , V_95 ) ;
if ( V_128 )
F_3 ( & V_8 -> V_13 , L_4 ) ;
}
}
static void F_60 ( struct V_144 * V_145 ,
struct V_102 * V_103 ,
struct V_146 * V_147 )
{
struct V_148 * V_149 = & V_145 -> V_149 ;
V_92 V_150 , V_151 , V_152 ;
struct V_1 * V_2 = F_61 ( V_103 ) ;
struct V_112 * V_113 = V_103 -> V_113 ;
V_150 = F_62 ( * V_113 -> V_153 ) ;
V_152 = F_63 ( V_150 , V_113 -> V_154 ) ;
V_149 -> V_155 =
F_64 ( V_152 , V_156 ) |
F_64 ( V_157 , V_158 ) |
F_64 ( 1 , V_159 ) |
F_64 ( 1 , V_160 ) |
F_64 ( V_103 -> V_31 , V_161 ) ;
V_151 = V_147 -> V_162 ;
V_152 = F_63 ( V_151 , V_113 -> V_154 ) ;
V_149 -> V_163 =
F_65 ( V_152 , V_164 ) |
F_65 ( F_66 ( & V_113 -> V_134 ) , V_165 ) ;
V_145 -> V_166 = F_67 ( V_2 -> V_6 ) ;
V_145 -> V_95 = V_103 -> V_95 ;
}
static int F_68 ( struct V_102 * V_103 , struct V_112 * V_113 ,
enum V_94 V_130 , void T_4 * V_167 )
{
int V_128 ;
V_103 -> V_113 = V_113 ;
V_103 -> V_95 = V_130 ;
V_103 -> V_31 = 1 ;
F_69 ( & V_103 -> V_117 ) ;
V_103 -> V_116 = F_70 ( V_113 -> V_120 * sizeof( * V_103 -> V_116 ) ) ;
if ( ! V_103 -> V_116 )
return - V_14 ;
V_103 -> V_110 = F_70 ( V_113 -> V_120 * sizeof( * V_103 -> V_110 ) ) ;
if ( ! V_103 -> V_110 ) {
V_128 = - V_14 ;
goto V_168;
}
V_103 -> V_104 = V_167 + V_169 ;
return 0 ;
V_168:
F_71 ( V_103 -> V_116 ) ;
return V_128 ;
}
static void F_72 ( struct V_102 * V_103 )
{
F_71 ( V_103 -> V_110 ) ;
F_71 ( V_103 -> V_116 ) ;
}
static int F_73 ( struct V_170 * V_171 ,
struct V_1 * V_2 , void T_4 * * V_167 )
{
struct V_5 * V_6 = V_171 -> V_6 ;
enum V_94 type , V_95 ;
struct V_144 * V_172 ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_173 * V_174 ;
T_5 V_175 ;
int V_128 ;
if ( ! F_74 ( V_6 ) && ! F_75 ( V_6 ) ) {
F_3 ( & V_8 -> V_13 , L_5 ) ;
return - V_127 ;
}
V_175 = V_176 * sizeof( * V_172 ) ;
V_172 = F_76 ( & V_8 -> V_13 , V_175 , V_11 ) ;
if ( ! V_172 )
return - V_14 ;
V_174 = F_77 ( V_171 , struct V_173 , V_171 ) ;
V_95 = V_122 ;
for (; V_95 < V_176 ; V_95 ++ ) {
V_128 = F_68 ( & V_2 -> V_103 [ V_95 ] ,
& V_2 -> V_177 [ V_95 ] , V_95 ,
V_167 [ V_95 ] ) ;
if ( V_128 ) {
F_3 ( & V_8 -> V_13 , L_6 ) ;
goto V_178;
}
F_60 ( & V_172 [ V_95 ] ,
& V_2 -> V_103 [ V_95 ] ,
& V_2 -> V_147 ) ;
}
V_95 = V_122 ;
for (; V_95 < V_176 ; V_95 ++ ) {
V_128 = F_78 ( & V_174 -> V_179 , V_74 ,
V_180 ,
& V_172 [ V_95 ] ,
sizeof( V_172 [ V_95 ] ) ,
NULL , NULL , V_181 ) ;
if ( V_128 ) {
F_3 ( & V_8 -> V_13 , L_7 ,
V_95 ) ;
goto V_182;
}
}
F_79 ( & V_8 -> V_13 , V_172 ) ;
return 0 ;
V_182:
V_95 = V_176 ;
V_178:
for ( type = V_122 ; type < V_95 ; type ++ )
F_72 ( & V_2 -> V_103 [ type ] ) ;
F_79 ( & V_8 -> V_13 , V_172 ) ;
return V_128 ;
}
int F_80 ( struct V_1 * V_2 , struct V_5 * V_6 ,
void T_4 * * V_167 )
{
struct V_183 * V_184 = F_81 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_170 * V_171 ;
T_5 V_185 ;
T_2 V_186 ;
int V_128 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_10 = F_82 ( L_8 , V_8 ,
V_187 ,
V_187 , 0 ) ;
if ( ! V_2 -> V_10 )
return - V_14 ;
V_185 = V_176 * sizeof( struct V_112 ) ;
V_2 -> V_177 = F_76 ( & V_8 -> V_13 , V_185 , V_11 ) ;
if ( ! V_2 -> V_177 ) {
V_128 = - V_14 ;
goto V_188;
}
V_186 = V_19 ;
V_128 = F_83 ( & V_2 -> V_147 , V_2 -> V_177 , V_6 ,
V_176 , V_189 ,
V_190 , V_191 , V_186 ) ;
if ( V_128 ) {
F_3 ( & V_8 -> V_13 , L_9 ) ;
goto V_192;
}
V_171 = F_77 ( V_184 , struct V_170 , V_184 ) ;
V_128 = F_73 ( V_171 , V_2 , V_167 ) ;
if ( V_128 ) {
F_3 ( & V_8 -> V_13 , L_10 ) ;
goto V_193;
}
F_84 ( & V_184 -> V_194 , V_195 , V_2 ,
F_56 ) ;
return 0 ;
V_193:
F_85 ( & V_2 -> V_147 , V_2 -> V_177 ,
V_176 ) ;
V_192:
F_79 ( & V_8 -> V_13 , V_2 -> V_177 ) ;
V_188:
F_86 ( V_2 -> V_10 ) ;
return V_128 ;
}
void F_87 ( struct V_1 * V_2 )
{
struct V_183 * V_184 = F_81 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
enum V_94 V_95 ;
F_88 ( & V_184 -> V_194 , V_195 ) ;
V_95 = V_122 ;
for (; V_95 < V_176 ; V_95 ++ )
F_72 ( & V_2 -> V_103 [ V_95 ] ) ;
F_85 ( & V_2 -> V_147 , V_2 -> V_177 ,
V_176 ) ;
F_79 ( & V_8 -> V_13 , V_2 -> V_177 ) ;
F_86 ( V_2 -> V_10 ) ;
}
