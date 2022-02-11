static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( L_1 ,
F_3 ( V_2 -> V_4 ) , V_2 -> V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( L_2 ,
F_3 ( V_2 -> V_4 ) , V_2 -> V_4 ) ;
}
static void F_5 ( struct V_5 * V_6 ,
struct V_1 * V_4 )
{
F_2 ( L_3 ,
F_3 ( V_4 -> V_4 ) , V_4 -> V_4 ,
V_4 -> V_7 -> V_8 , V_4 -> V_9 . V_10 ) ;
}
static int F_6 ( struct V_11 * V_7 )
{
struct V_12 * V_13 = & V_7 -> V_13 ;
int V_14 , V_15 , V_16 ;
V_14 = F_7 ( V_7 -> V_17 , V_13 ) ;
if ( V_14 ) {
F_8 ( L_4 , V_7 -> V_17 -> V_8 ) ;
return V_14 ;
}
V_14 = F_9 ( V_7 ) ;
if ( V_14 )
return V_14 ;
V_7 -> V_18 = F_10 ( int , F_11 () ,
V_7 -> V_17 -> V_19 ) ;
V_7 -> V_20 = F_12 ( V_7 -> V_18 , sizeof( * V_7 -> V_20 ) ,
V_21 ) ;
if ( ! V_7 -> V_20 )
goto V_22;
V_16 = F_13 ( V_23 , V_13 -> V_16 ) ;
F_14 ( L_5 ,
V_7 -> V_18 , V_7 -> V_17 -> V_8 ,
V_7 -> V_17 -> V_19 , V_16 ) ;
V_7 -> V_24 = F_15 ( V_7 -> V_17 ) ;
if ( F_16 ( V_7 -> V_24 ) )
goto V_25;
for ( V_15 = 0 ; V_15 < V_7 -> V_18 ; V_15 ++ ) {
struct V_26 V_27 = {} ;
struct V_28 * V_29 = & V_7 -> V_20 [ V_15 ] ;
V_29 -> V_7 = V_7 ;
V_27 . V_30 = V_16 ;
V_27 . V_31 = V_15 ;
V_29 -> V_32 = F_17 ( V_7 -> V_17 ,
V_33 ,
F_1 ,
( void * ) V_29 ,
& V_27 ) ;
if ( F_16 ( V_29 -> V_32 ) ) {
V_29 -> V_32 = NULL ;
goto V_34;
}
if ( F_18 ( V_29 -> V_32 , V_35 ) )
goto V_34;
F_19 ( & V_29 -> V_36 , V_37 ,
( unsigned long ) V_29 ) ;
}
if ( ! V_38 ) {
int V_39 = V_40 |
V_41 |
V_42 ;
V_7 -> V_43 = F_20 ( V_7 -> V_24 , V_39 ) ;
if ( F_16 ( V_7 -> V_43 ) )
goto V_44;
}
F_21 ( & V_7 -> V_45 , V_7 -> V_17 ,
F_5 ) ;
if ( F_22 ( & V_7 -> V_45 ) )
goto V_46;
return 0 ;
V_46:
if ( V_7 -> V_43 )
F_23 ( V_7 -> V_43 ) ;
V_44:
for ( V_15 = 0 ; V_15 < V_7 -> V_18 ; V_15 ++ )
F_24 ( & V_7 -> V_20 [ V_15 ] . V_36 ) ;
V_34:
for ( V_15 = 0 ; V_15 < V_7 -> V_18 ; V_15 ++ ) {
struct V_28 * V_29 = & V_7 -> V_20 [ V_15 ] ;
if ( V_29 -> V_32 )
F_25 ( V_29 -> V_32 ) ;
}
F_26 ( V_7 -> V_24 ) ;
V_25:
F_27 ( V_7 -> V_20 ) ;
V_22:
F_2 ( L_6 ) ;
return - 1 ;
}
static void F_28 ( struct V_11 * V_7 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_7 -> V_18 ; V_15 ++ ) {
struct V_28 * V_29 = & V_7 -> V_20 [ V_15 ] ;
F_24 ( & V_29 -> V_36 ) ;
F_25 ( V_29 -> V_32 ) ;
V_29 -> V_32 = NULL ;
}
( void ) F_29 ( & V_7 -> V_45 ) ;
if ( V_7 -> V_43 )
( void ) F_23 ( V_7 -> V_43 ) ;
F_26 ( V_7 -> V_24 ) ;
F_27 ( V_7 -> V_20 ) ;
V_7 -> V_20 = NULL ;
V_7 -> V_43 = NULL ;
V_7 -> V_24 = NULL ;
}
int F_30 ( struct V_47 * V_47 ,
unsigned V_48 ,
unsigned int V_49 )
{
struct V_11 * V_7 = V_47 -> V_7 ;
struct V_50 * V_51 = & V_47 -> V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
struct V_58 V_59 ;
int V_14 ;
F_31 ( & V_51 -> V_60 ) ;
F_32 ( & V_51 -> V_61 ) ;
V_55 = F_33 ( sizeof( * V_55 ) , V_21 ) ;
if ( ! V_55 )
return - V_62 ;
V_53 = F_34 ( sizeof( * V_53 ) + ( sizeof( V_63 ) * V_49 ) ,
V_21 ) ;
if ( ! V_53 ) {
V_14 = - V_62 ;
goto V_64;
}
V_53 -> V_65 = ( V_63 * ) ( V_53 + 1 ) ;
V_59 . V_66 = V_67 ;
V_59 . V_68 = V_49 ;
V_59 . V_69 = V_48 * 2 ;
V_59 . V_70 = V_48 ;
V_59 . V_71 = 0 ;
V_59 . V_72 = NULL ;
V_59 . V_39 = ( V_40 |
V_41 |
V_42 ) ;
V_57 = F_35 ( V_7 -> V_24 , & V_59 ) ;
if ( F_16 ( V_57 ) ) {
V_14 = F_36 ( V_57 ) ;
F_2 ( L_7 , V_14 ) ;
goto V_73;
}
V_55 -> V_74 . V_53 = V_53 ;
V_55 -> V_74 . V_57 = V_57 ;
F_37 ( & V_55 -> V_60 , & V_51 -> V_60 ) ;
return 0 ;
V_73:
F_27 ( V_53 ) ;
V_64:
F_27 ( V_55 ) ;
return V_14 ;
}
void F_38 ( struct V_47 * V_47 )
{
struct V_50 * V_51 = & V_47 -> V_51 ;
struct V_54 * V_55 ;
V_55 = F_39 ( & V_51 -> V_60 ,
struct V_54 , V_60 ) ;
F_40 ( & V_55 -> V_60 ) ;
F_14 ( L_8 ,
V_47 , V_55 -> V_74 . V_57 ) ;
F_41 ( V_55 -> V_74 . V_57 ) ;
F_27 ( V_55 -> V_74 . V_53 ) ;
F_27 ( V_55 ) ;
}
static int
F_42 ( struct V_17 * V_17 ,
struct V_75 * V_24 ,
struct V_76 * V_77 ,
unsigned int V_49 )
{
int V_14 ;
V_77 -> V_43 = F_43 ( V_24 , V_78 , V_49 ) ;
if ( F_16 ( V_77 -> V_43 ) ) {
V_14 = F_36 ( V_77 -> V_43 ) ;
F_2 ( L_9 , V_14 ) ;
return V_14 ;
}
V_77 -> V_79 = 1 ;
return 0 ;
}
static void
F_44 ( struct V_76 * V_74 )
{
F_23 ( V_74 -> V_43 ) ;
}
static int
F_45 ( struct V_17 * V_17 ,
struct V_75 * V_24 ,
struct V_54 * V_55 ,
unsigned int V_49 )
{
struct V_80 * V_81 = NULL ;
int V_14 ;
V_55 -> V_81 = F_33 ( sizeof( * V_55 -> V_81 ) , V_21 ) ;
if ( ! V_55 -> V_81 )
return - V_62 ;
V_81 = V_55 -> V_81 ;
V_14 = F_42 ( V_17 , V_24 , & V_81 -> V_74 , V_49 ) ;
if ( V_14 ) {
F_2 ( L_10 ) ;
goto V_82;
}
V_81 -> V_83 = F_43 ( V_24 , V_84 , 2 ) ;
if ( F_16 ( V_81 -> V_83 ) ) {
V_14 = F_36 ( V_81 -> V_83 ) ;
goto V_85;
}
V_81 -> V_86 = 1 ;
V_55 -> V_81 -> V_87 = 0 ;
return 0 ;
V_85:
F_44 ( & V_81 -> V_74 ) ;
V_82:
F_27 ( V_55 -> V_81 ) ;
return V_14 ;
}
static void
F_46 ( struct V_80 * V_81 )
{
F_44 ( & V_81 -> V_74 ) ;
F_23 ( V_81 -> V_83 ) ;
F_27 ( V_81 ) ;
}
static struct V_54 *
F_47 ( struct V_17 * V_17 ,
struct V_75 * V_24 ,
bool V_88 ,
unsigned int V_49 )
{
struct V_54 * V_55 ;
int V_14 ;
V_55 = F_33 ( sizeof( * V_55 ) , V_21 ) ;
if ( ! V_55 )
return F_48 ( - V_62 ) ;
V_14 = F_42 ( V_17 , V_24 , & V_55 -> V_74 , V_49 ) ;
if ( V_14 )
goto V_89;
if ( V_88 ) {
V_14 = F_45 ( V_17 , V_24 , V_55 , V_49 ) ;
if ( V_14 )
goto V_90;
}
return V_55 ;
V_90:
F_44 ( & V_55 -> V_74 ) ;
V_89:
F_27 ( V_55 ) ;
return F_48 ( V_14 ) ;
}
int F_49 ( struct V_47 * V_47 ,
unsigned V_48 ,
unsigned int V_49 )
{
struct V_11 * V_7 = V_47 -> V_7 ;
struct V_50 * V_51 = & V_47 -> V_51 ;
struct V_54 * V_55 ;
int V_15 , V_14 ;
F_31 ( & V_51 -> V_60 ) ;
F_32 ( & V_51 -> V_61 ) ;
V_51 -> V_49 = 0 ;
for ( V_15 = 0 ; V_15 < V_48 ; V_15 ++ ) {
V_55 = F_47 ( V_7 -> V_17 , V_7 -> V_24 ,
V_47 -> V_91 , V_49 ) ;
if ( F_16 ( V_55 ) ) {
V_14 = F_36 ( V_55 ) ;
goto V_92;
}
F_50 ( & V_55 -> V_60 , & V_51 -> V_60 ) ;
V_51 -> V_49 ++ ;
}
return 0 ;
V_92:
F_51 ( V_47 ) ;
return V_14 ;
}
void F_51 ( struct V_47 * V_47 )
{
struct V_50 * V_51 = & V_47 -> V_51 ;
struct V_54 * V_55 , * V_93 ;
int V_15 = 0 ;
if ( F_52 ( & V_51 -> V_60 ) )
return;
F_14 ( L_11 , V_47 ) ;
F_53 (desc, tmp, &fr_pool->list, list) {
F_40 ( & V_55 -> V_60 ) ;
F_44 ( & V_55 -> V_74 ) ;
if ( V_55 -> V_81 )
F_46 ( V_55 -> V_81 ) ;
F_27 ( V_55 ) ;
++ V_15 ;
}
if ( V_15 < V_51 -> V_49 )
F_54 ( L_12 ,
V_51 -> V_49 - V_15 ) ;
}
static int F_55 ( struct V_47 * V_47 )
{
struct V_94 * V_94 = F_56 ( V_47 , struct V_94 ,
V_47 ) ;
struct V_11 * V_7 ;
struct V_12 * V_13 ;
struct V_95 V_96 ;
int V_14 = - V_62 ;
int V_97 , V_98 = 0 ;
F_57 ( V_47 -> V_7 == NULL ) ;
V_7 = V_47 -> V_7 ;
V_13 = & V_7 -> V_13 ;
memset ( & V_96 , 0 , sizeof V_96 ) ;
F_58 ( & V_99 . V_100 ) ;
for ( V_97 = 0 ; V_97 < V_7 -> V_18 ; V_97 ++ ) {
if ( V_7 -> V_20 [ V_97 ] . V_101 <
V_7 -> V_20 [ V_98 ] . V_101 )
V_98 = V_97 ;
}
V_47 -> V_29 = & V_7 -> V_20 [ V_98 ] ;
V_47 -> V_29 -> V_101 ++ ;
F_59 ( & V_99 . V_100 ) ;
F_14 ( L_13 , V_98 , V_47 ) ;
V_96 . V_45 = F_4 ;
V_96 . V_102 = ( void * ) V_47 ;
V_96 . V_103 = V_47 -> V_29 -> V_32 ;
V_96 . V_104 = V_47 -> V_29 -> V_32 ;
V_96 . V_105 . V_106 = V_107 ;
V_96 . V_105 . V_108 = 2 ;
V_96 . V_105 . V_109 = 1 ;
V_96 . V_110 = V_111 ;
V_96 . V_112 = V_113 ;
if ( V_47 -> V_91 ) {
V_96 . V_105 . V_114 = V_115 + 1 ;
V_96 . V_116 |= V_117 ;
V_94 -> V_118 =
F_60 ( V_115 ) ;
} else {
if ( V_13 -> V_119 > V_120 ) {
V_96 . V_105 . V_114 = V_120 + 1 ;
V_94 -> V_118 =
F_60 ( V_120 ) ;
} else {
V_96 . V_105 . V_114 = V_13 -> V_119 ;
V_94 -> V_118 =
F_60 ( V_13 -> V_119 ) ;
F_61 ( L_14 ,
V_7 -> V_17 -> V_8 , V_13 -> V_119 ) ;
}
}
V_14 = F_62 ( V_47 -> V_121 , V_7 -> V_24 , & V_96 ) ;
if ( V_14 )
goto V_122;
V_47 -> V_123 = V_47 -> V_121 -> V_123 ;
F_14 ( L_15 ,
V_47 , V_47 -> V_121 ,
V_47 -> V_121 -> V_123 ) ;
return V_14 ;
V_122:
F_58 ( & V_99 . V_100 ) ;
V_47 -> V_29 -> V_101 -- ;
F_59 ( & V_99 . V_100 ) ;
F_2 ( L_16 , V_14 ) ;
return V_14 ;
}
static
struct V_11 * F_63 ( struct V_124 * V_121 )
{
struct V_11 * V_7 ;
F_58 ( & V_99 . V_125 ) ;
F_64 (device, &ig.device_list, ig_list)
if ( V_7 -> V_17 -> V_126 == V_121 -> V_7 -> V_126 )
goto V_127;
V_7 = F_33 ( sizeof *V_7 , V_21 ) ;
if ( V_7 == NULL )
goto V_128;
V_7 -> V_17 = V_121 -> V_7 ;
if ( F_6 ( V_7 ) ) {
F_27 ( V_7 ) ;
V_7 = NULL ;
goto V_128;
}
F_37 ( & V_7 -> V_129 , & V_99 . V_130 ) ;
V_127:
V_7 -> V_131 ++ ;
V_128:
F_59 ( & V_99 . V_125 ) ;
return V_7 ;
}
static void F_65 ( struct V_11 * V_7 )
{
F_58 ( & V_99 . V_125 ) ;
V_7 -> V_131 -- ;
F_14 ( L_17 , V_7 , V_7 -> V_131 ) ;
if ( ! V_7 -> V_131 ) {
F_28 ( V_7 ) ;
F_40 ( & V_7 -> V_129 ) ;
F_27 ( V_7 ) ;
}
F_59 ( & V_99 . V_125 ) ;
}
static int F_66 ( struct V_94 * V_94 ,
enum V_132 V_29 ,
enum V_132 V_133 )
{
int V_14 ;
V_14 = ( V_94 -> V_134 == V_29 ) ;
if ( V_14 )
V_94 -> V_134 = V_133 ;
return V_14 ;
}
void F_67 ( struct V_135 * V_136 )
{
struct V_94 * V_94 ;
V_94 = F_56 ( V_136 , struct V_94 , V_137 ) ;
F_68 ( & V_94 -> V_138 ) ;
F_68 ( & V_94 -> V_139 ) ;
F_58 ( & V_94 -> V_140 ) ;
V_94 -> V_134 = V_141 ;
F_59 ( & V_94 -> V_140 ) ;
F_69 ( V_94 ) ;
}
static void F_70 ( struct V_94 * V_94 ,
bool V_142 )
{
struct V_47 * V_47 = & V_94 -> V_47 ;
struct V_11 * V_7 = V_47 -> V_7 ;
F_14 ( L_18 ,
V_94 , V_47 -> V_121 , V_47 -> V_123 ) ;
if ( V_47 -> V_123 != NULL ) {
V_47 -> V_29 -> V_101 -- ;
F_71 ( V_47 -> V_121 ) ;
V_47 -> V_123 = NULL ;
}
if ( V_142 ) {
if ( V_94 -> V_143 )
F_72 ( V_94 ) ;
if ( V_7 != NULL ) {
F_65 ( V_7 ) ;
V_47 -> V_7 = NULL ;
}
}
}
void F_69 ( struct V_94 * V_94 )
{
struct V_47 * V_47 = & V_94 -> V_47 ;
F_58 ( & V_99 . V_100 ) ;
F_40 ( & V_94 -> V_144 ) ;
F_59 ( & V_99 . V_100 ) ;
F_58 ( & V_94 -> V_140 ) ;
if ( V_94 -> V_134 != V_141 ) {
F_54 ( L_19 ,
V_94 , V_94 -> V_134 ) ;
F_73 ( V_94 -> V_145 ) ;
V_94 -> V_134 = V_141 ;
}
F_70 ( V_94 , true ) ;
F_59 ( & V_94 -> V_140 ) ;
if ( V_47 -> V_121 != NULL ) {
F_74 ( V_47 -> V_121 ) ;
V_47 -> V_121 = NULL ;
}
F_27 ( V_94 ) ;
}
int F_75 ( struct V_94 * V_94 )
{
struct V_47 * V_47 = & V_94 -> V_47 ;
struct V_146 * V_147 ;
int V_92 = 0 ;
if ( ! F_66 ( V_94 , V_148 ,
V_149 ) )
return 0 ;
F_14 ( L_20 , V_94 , V_94 -> V_134 ) ;
if ( V_94 -> V_150 )
F_76 ( V_94 -> V_150 ) ;
if ( V_47 -> V_121 ) {
V_92 = F_77 ( V_47 -> V_121 ) ;
if ( V_92 )
F_2 ( L_21 ,
V_94 , V_92 ) ;
V_92 = F_78 ( V_47 -> V_123 , & V_47 -> V_151 , & V_147 ) ;
if ( V_92 ) {
F_2 ( L_22 , V_47 ) ;
return 1 ;
}
F_68 ( & V_47 -> V_152 ) ;
}
return 1 ;
}
static void F_79 ( struct V_124 * V_121 )
{
struct V_94 * V_94 ;
V_94 = (struct V_94 * ) V_121 -> V_3 ;
V_94 -> V_134 = V_149 ;
}
static void
F_80 ( struct V_94 * V_94 ,
unsigned int V_153 )
{
struct V_11 * V_7 = V_94 -> V_47 . V_7 ;
unsigned short V_154 , V_155 ;
V_154 = F_81 ( V_153 * 512 , V_156 ) ;
V_155 = F_10 ( unsigned , V_157 ,
V_7 -> V_13 . V_158 ) ;
if ( V_154 > V_155 ) {
V_154 = V_155 ;
V_94 -> V_159 = V_154 * V_156 / 512 ;
} else {
V_94 -> V_159 = V_153 ;
}
V_94 -> V_160 = V_154 ;
F_61 ( L_23 ,
V_94 , V_94 -> V_160 ,
V_94 -> V_159 ) ;
}
static void F_82 ( struct V_124 * V_121 )
{
struct V_11 * V_7 ;
struct V_94 * V_94 ;
struct V_47 * V_47 ;
int V_14 ;
V_94 = (struct V_94 * ) V_121 -> V_3 ;
if ( V_94 -> V_134 != V_161 )
return;
V_47 = & V_94 -> V_47 ;
V_7 = F_63 ( V_121 ) ;
if ( ! V_7 ) {
F_2 ( L_24 ) ;
F_79 ( V_121 ) ;
return;
}
V_47 -> V_7 = V_7 ;
if ( V_162 ) {
if ( ! ( V_7 -> V_13 . V_163 &
V_164 ) ) {
F_54 ( L_25
L_26 ,
V_47 -> V_7 -> V_17 -> V_8 ) ;
V_47 -> V_91 = false ;
} else {
V_47 -> V_91 = true ;
}
}
F_80 ( V_94 , V_165 ) ;
V_14 = F_83 ( V_121 , 1000 ) ;
if ( V_14 ) {
F_2 ( L_27 , V_14 ) ;
F_79 ( V_121 ) ;
return;
}
}
static void F_84 ( struct V_124 * V_121 )
{
struct V_166 V_167 ;
int V_14 ;
struct V_168 V_169 ;
struct V_94 * V_94 = (struct V_94 * ) V_121 -> V_3 ;
struct V_47 * V_47 = & V_94 -> V_47 ;
struct V_11 * V_7 = V_47 -> V_7 ;
if ( V_94 -> V_134 != V_161 )
return;
V_14 = F_55 ( V_47 ) ;
if ( V_14 )
goto V_170;
memset ( & V_167 , 0 , sizeof V_167 ) ;
V_167 . V_171 = V_7 -> V_13 . V_172 ;
V_167 . V_173 = 1 ;
V_167 . V_174 = 7 ;
V_167 . V_175 = 6 ;
memset ( & V_169 , 0 , sizeof( V_169 ) ) ;
V_169 . V_176 = ( V_177 |
V_178 ) ;
V_167 . V_179 = ( void * ) & V_169 ;
V_167 . V_180 = sizeof( struct V_168 ) ;
V_14 = F_85 ( V_121 , & V_167 ) ;
if ( V_14 ) {
F_2 ( L_28 , V_14 ) ;
goto V_170;
}
return;
V_170:
F_79 ( V_121 ) ;
}
static void F_86 ( struct V_124 * V_121 )
{
struct V_94 * V_94 ;
struct V_181 V_182 ;
struct V_95 V_96 ;
V_94 = (struct V_94 * ) V_121 -> V_3 ;
if ( V_94 -> V_134 != V_161 )
return;
( void ) F_87 ( V_121 -> V_123 , & V_182 , ~ 0 , & V_96 ) ;
F_14 ( L_29 , V_182 . V_183 , V_121 -> V_123 -> V_184 ) ;
V_94 -> V_134 = V_148 ;
F_88 ( & V_94 -> V_185 ) ;
}
static void F_89 ( struct V_124 * V_121 )
{
struct V_94 * V_94 = (struct V_94 * ) V_121 -> V_3 ;
if ( F_75 ( V_94 ) ) {
if ( V_94 -> V_150 )
F_90 ( V_94 -> V_150 ,
V_186 ) ;
else
F_2 ( L_30 ) ;
}
}
static void F_91 ( struct V_124 * V_121 ,
bool V_142 )
{
struct V_94 * V_94 = (struct V_94 * ) V_121 -> V_3 ;
F_89 ( V_121 ) ;
F_70 ( V_94 , V_142 ) ;
F_88 ( & V_94 -> V_139 ) ;
}
static int F_92 ( struct V_124 * V_121 , struct V_187 * V_4 )
{
struct V_94 * V_94 ;
int V_14 = 0 ;
V_94 = (struct V_94 * ) V_121 -> V_3 ;
F_14 ( L_31 ,
F_93 ( V_4 -> V_4 ) , V_4 -> V_4 ,
V_4 -> V_188 , V_121 -> V_3 , V_121 ) ;
F_58 ( & V_94 -> V_140 ) ;
switch ( V_4 -> V_4 ) {
case V_189 :
F_82 ( V_121 ) ;
break;
case V_190 :
F_84 ( V_121 ) ;
break;
case V_191 :
F_86 ( V_121 ) ;
break;
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
F_79 ( V_121 ) ;
break;
case V_197 :
case V_198 :
case V_199 :
F_91 ( V_121 , false ) ;
break;
case V_200 :
F_91 ( V_121 , true ) ;
if ( V_94 -> V_134 != V_141 ) {
V_94 -> V_47 . V_121 = NULL ;
V_14 = 1 ;
}
break;
default:
F_2 ( L_32 ,
F_93 ( V_4 -> V_4 ) , V_4 -> V_4 ) ;
break;
}
F_59 ( & V_94 -> V_140 ) ;
return V_14 ;
}
void F_94 ( struct V_94 * V_94 )
{
V_94 -> V_134 = V_201 ;
V_94 -> V_47 . V_202 = 0 ;
F_95 ( & V_94 -> V_47 . V_152 ) ;
F_95 ( & V_94 -> V_138 ) ;
F_95 ( & V_94 -> V_139 ) ;
F_95 ( & V_94 -> V_185 ) ;
F_31 ( & V_94 -> V_144 ) ;
F_96 ( & V_94 -> V_140 ) ;
}
int F_97 ( struct V_94 * V_94 ,
struct V_203 * V_204 ,
struct V_203 * V_205 ,
int V_206 )
{
struct V_47 * V_47 = & V_94 -> V_47 ;
int V_92 = 0 ;
F_58 ( & V_94 -> V_140 ) ;
sprintf ( V_94 -> V_8 , L_33 , V_205 ) ;
F_14 ( L_34 , V_94 -> V_8 ) ;
V_47 -> V_7 = NULL ;
V_94 -> V_134 = V_161 ;
V_47 -> V_151 . V_207 = V_208 ;
V_47 -> V_151 . V_209 = V_210 ;
V_47 -> V_121 = F_98 ( & V_211 , F_92 ,
( void * ) V_94 ,
V_212 , V_113 ) ;
if ( F_16 ( V_47 -> V_121 ) ) {
V_92 = F_36 ( V_47 -> V_121 ) ;
F_2 ( L_35 , V_92 ) ;
goto V_213;
}
V_92 = F_99 ( V_47 -> V_121 , V_204 , V_205 , 1000 ) ;
if ( V_92 ) {
F_2 ( L_36 , V_92 ) ;
goto V_214;
}
if ( ! V_206 ) {
F_100 ( & V_94 -> V_185 ) ;
if ( V_94 -> V_134 != V_148 ) {
V_92 = - V_215 ;
goto V_216;
}
}
F_59 ( & V_94 -> V_140 ) ;
F_58 ( & V_99 . V_100 ) ;
F_37 ( & V_94 -> V_144 , & V_99 . V_217 ) ;
F_59 ( & V_99 . V_100 ) ;
return 0 ;
V_213:
V_47 -> V_121 = NULL ;
V_214:
V_94 -> V_134 = V_141 ;
V_216:
F_59 ( & V_94 -> V_140 ) ;
F_69 ( V_94 ) ;
return V_92 ;
}
int F_101 ( struct V_94 * V_94 )
{
struct V_218 V_219 , * V_220 ;
struct V_47 * V_47 = & V_94 -> V_47 ;
struct V_221 V_222 ;
int V_223 ;
V_222 . V_224 = V_94 -> V_225 ;
V_222 . V_226 = V_227 ;
V_222 . V_228 = V_47 -> V_7 -> V_24 -> V_229 ;
V_219 . V_207 = ( V_230 ) V_94 -> V_231 ;
V_219 . V_232 = & V_222 ;
V_219 . V_233 = 1 ;
V_219 . V_234 = NULL ;
V_47 -> V_202 ++ ;
V_223 = F_102 ( V_47 -> V_123 , & V_219 , & V_220 ) ;
if ( V_223 ) {
F_2 ( L_37 , V_223 ) ;
V_47 -> V_202 -- ;
}
return V_223 ;
}
int F_103 ( struct V_94 * V_94 , int V_235 )
{
struct V_218 * V_219 , * V_220 ;
int V_15 , V_223 ;
struct V_47 * V_47 = & V_94 -> V_47 ;
unsigned int V_236 = V_94 -> V_237 ;
struct V_238 * V_239 ;
for ( V_219 = V_47 -> V_219 , V_15 = 0 ; V_15 < V_235 ; V_15 ++ , V_219 ++ ) {
V_239 = & V_94 -> V_143 [ V_236 ] ;
V_219 -> V_207 = ( V_230 ) V_239 ;
V_219 -> V_232 = & V_239 -> V_240 ;
V_219 -> V_233 = 1 ;
V_219 -> V_234 = V_219 + 1 ;
V_236 = ( V_236 + 1 ) & V_94 -> V_241 ;
}
V_219 -- ;
V_219 -> V_234 = NULL ;
V_47 -> V_202 += V_235 ;
V_223 = F_102 ( V_47 -> V_123 , V_47 -> V_219 , & V_220 ) ;
if ( V_223 ) {
F_2 ( L_37 , V_223 ) ;
V_47 -> V_202 -= V_235 ;
} else
V_94 -> V_237 = V_236 ;
return V_223 ;
}
int F_104 ( struct V_47 * V_47 , struct V_242 * V_243 ,
bool signal )
{
struct V_146 * V_147 , * V_244 = F_105 ( V_243 ) ;
int V_223 ;
F_106 ( V_47 -> V_7 -> V_17 ,
V_243 -> V_245 , V_246 ,
V_247 ) ;
V_244 -> V_234 = NULL ;
V_244 -> V_207 = ( V_230 ) V_243 ;
V_244 -> V_232 = V_243 -> V_248 ;
V_244 -> V_233 = V_243 -> V_233 ;
V_244 -> V_209 = V_210 ;
V_244 -> V_249 = signal ? V_250 : 0 ;
V_223 = F_78 ( V_47 -> V_123 , & V_243 -> V_251 [ 0 ] . V_252 , & V_147 ) ;
if ( V_223 )
F_2 ( L_38 ,
V_223 , V_147 -> V_209 ) ;
return V_223 ;
}
static inline bool
F_107 ( struct V_94 * V_94 , void * V_207 )
{
void * V_253 = V_94 -> V_143 ;
int V_254 = V_94 -> V_255 * sizeof( * V_94 -> V_143 ) ;
if ( V_207 >= V_253 && V_207 < V_253 + V_254 )
return false ;
return true ;
}
static void
F_108 ( struct V_47 * V_47 ,
struct V_256 * V_257 )
{
void * V_207 = ( void * ) ( V_230 ) V_257 -> V_207 ;
struct V_94 * V_94 = F_56 ( V_47 , struct V_94 ,
V_47 ) ;
if ( V_257 -> V_188 != V_258 )
if ( V_94 -> V_150 )
F_90 ( V_94 -> V_150 ,
V_186 ) ;
if ( V_257 -> V_207 == V_259 )
return;
if ( F_107 ( V_94 , V_207 ) ) {
struct V_242 * V_55 = V_207 ;
if ( V_55 -> type == V_260 )
F_109 ( V_99 . V_261 , V_55 ) ;
} else {
V_47 -> V_202 -- ;
}
}
static void F_110 ( struct V_256 * V_257 )
{
struct V_47 * V_47 ;
struct V_242 * V_243 ;
struct V_238 * V_239 ;
V_47 = V_257 -> V_123 -> V_102 ;
if ( F_111 ( V_257 -> V_188 == V_262 ) ) {
if ( V_257 -> V_209 == V_263 ) {
V_239 = (struct V_238 * ) ( V_230 ) V_257 -> V_207 ;
F_112 ( V_239 , V_257 -> V_264 ,
V_47 ) ;
} else
if ( V_257 -> V_209 == V_265 ) {
V_243 = (struct V_242 * ) ( V_230 ) V_257 -> V_207 ;
F_113 ( V_243 , V_47 ) ;
} else {
F_2 ( L_39 , V_257 -> V_209 ) ;
}
} else {
if ( V_257 -> V_188 != V_258 )
F_2 ( L_40 ,
F_114 ( V_257 -> V_188 ) , V_257 -> V_188 ,
V_257 -> V_207 , V_257 -> V_266 ) ;
else
F_61 ( L_41 ,
F_114 ( V_257 -> V_188 ) , V_257 -> V_188 ,
V_257 -> V_207 ) ;
if ( V_257 -> V_207 == V_208 )
F_88 ( & V_47 -> V_152 ) ;
else
F_108 ( V_47 , V_257 ) ;
}
}
static void V_37 ( unsigned long V_267 )
{
struct V_28 * V_29 = (struct V_28 * ) V_267 ;
struct V_268 * V_32 = V_29 -> V_32 ;
struct V_256 * const V_269 = V_29 -> V_269 ;
int V_15 , V_270 , V_271 = 0 ;
while ( ( V_270 = F_115 ( V_32 , F_116 ( V_29 -> V_269 ) , V_269 ) ) > 0 ) {
for ( V_15 = 0 ; V_15 < V_270 ; V_15 ++ )
F_110 ( & V_269 [ V_15 ] ) ;
V_271 += V_270 ;
if ( V_271 >= V_272 )
break;
}
F_18 ( V_32 , V_35 ) ;
F_61 ( L_42 , V_271 ) ;
}
static void V_33 ( struct V_268 * V_32 , void * V_273 )
{
struct V_28 * V_29 = V_273 ;
F_117 ( & V_29 -> V_36 ) ;
}
T_1 F_118 ( struct V_274 * V_275 ,
enum V_276 V_277 , T_2 * V_278 )
{
struct V_279 * V_280 = & V_275 -> V_281 [ V_277 ] ;
struct V_54 * V_55 = V_280 -> V_282 ;
unsigned long V_283 = V_275 -> V_284 -> V_7 -> V_283 ;
struct V_285 V_286 ;
int V_14 ;
if ( V_55 && V_55 -> V_81 -> V_87 ) {
V_55 -> V_81 -> V_87 = 0 ;
V_14 = F_119 ( V_55 -> V_81 -> V_83 ,
V_287 , & V_286 ) ;
if ( V_14 ) {
F_120 ( L_43 , V_14 ) ;
goto V_92;
}
if ( V_286 . V_288 & V_287 ) {
T_2 V_289 = V_286 . V_290 . V_291 ;
F_121 ( V_289 , V_283 + 8 ) ;
* V_278 = F_122 ( V_275 -> V_284 ) + V_289 ;
F_120 ( L_44
L_45 ,
V_286 . V_290 . V_292 ,
( unsigned long long ) * V_278 ,
V_286 . V_290 . V_293 ,
V_286 . V_290 . V_294 ) ;
switch ( V_286 . V_290 . V_292 ) {
case V_295 :
return 0x1 ;
case V_296 :
return 0x3 ;
case V_297 :
return 0x2 ;
}
}
}
return 0 ;
V_92:
return 0x1 ;
}
