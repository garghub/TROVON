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
V_77 -> V_78 = F_43 ( V_17 , V_49 ) ;
if ( F_16 ( V_77 -> V_78 ) ) {
V_14 = F_36 ( V_77 -> V_78 ) ;
F_2 ( L_9 ,
V_14 ) ;
return F_36 ( V_77 -> V_78 ) ;
}
V_77 -> V_43 = F_44 ( V_24 , V_79 , V_49 ) ;
if ( F_16 ( V_77 -> V_43 ) ) {
V_14 = F_36 ( V_77 -> V_43 ) ;
F_2 ( L_10 , V_14 ) ;
goto V_80;
}
V_77 -> V_81 = 1 ;
return 0 ;
V_80:
F_45 ( V_77 -> V_78 ) ;
return V_14 ;
}
static void
F_46 ( struct V_76 * V_74 )
{
F_23 ( V_74 -> V_43 ) ;
F_45 ( V_74 -> V_78 ) ;
}
static int
F_47 ( struct V_17 * V_17 ,
struct V_75 * V_24 ,
struct V_54 * V_55 ,
unsigned int V_49 )
{
struct V_82 * V_83 = NULL ;
int V_14 ;
V_55 -> V_83 = F_33 ( sizeof( * V_55 -> V_83 ) , V_21 ) ;
if ( ! V_55 -> V_83 )
return - V_62 ;
V_83 = V_55 -> V_83 ;
V_14 = F_42 ( V_17 , V_24 , & V_83 -> V_74 , V_49 ) ;
if ( V_14 ) {
F_2 ( L_11 ) ;
goto V_84;
}
V_83 -> V_85 = F_44 ( V_24 , V_86 , 2 ) ;
if ( F_16 ( V_83 -> V_85 ) ) {
V_14 = F_36 ( V_83 -> V_85 ) ;
goto V_87;
}
V_83 -> V_88 = 1 ;
V_55 -> V_83 -> V_89 = 0 ;
return 0 ;
V_87:
F_46 ( & V_83 -> V_74 ) ;
V_84:
F_27 ( V_55 -> V_83 ) ;
return V_14 ;
}
static void
F_48 ( struct V_82 * V_83 )
{
F_46 ( & V_83 -> V_74 ) ;
F_23 ( V_83 -> V_85 ) ;
F_27 ( V_83 ) ;
}
static struct V_54 *
F_49 ( struct V_17 * V_17 ,
struct V_75 * V_24 ,
bool V_90 ,
unsigned int V_49 )
{
struct V_54 * V_55 ;
int V_14 ;
V_55 = F_33 ( sizeof( * V_55 ) , V_21 ) ;
if ( ! V_55 )
return F_50 ( - V_62 ) ;
V_14 = F_42 ( V_17 , V_24 , & V_55 -> V_74 , V_49 ) ;
if ( V_14 )
goto V_91;
if ( V_90 ) {
V_14 = F_47 ( V_17 , V_24 , V_55 , V_49 ) ;
if ( V_14 )
goto V_92;
}
return V_55 ;
V_92:
F_46 ( & V_55 -> V_74 ) ;
V_91:
F_27 ( V_55 ) ;
return F_50 ( V_14 ) ;
}
int F_51 ( struct V_47 * V_47 ,
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
V_55 = F_49 ( V_7 -> V_17 , V_7 -> V_24 ,
V_47 -> V_93 , V_49 ) ;
if ( F_16 ( V_55 ) ) {
V_14 = F_36 ( V_55 ) ;
goto V_94;
}
F_52 ( & V_55 -> V_60 , & V_51 -> V_60 ) ;
V_51 -> V_49 ++ ;
}
return 0 ;
V_94:
F_53 ( V_47 ) ;
return V_14 ;
}
void F_53 ( struct V_47 * V_47 )
{
struct V_50 * V_51 = & V_47 -> V_51 ;
struct V_54 * V_55 , * V_95 ;
int V_15 = 0 ;
if ( F_54 ( & V_51 -> V_60 ) )
return;
F_14 ( L_12 , V_47 ) ;
F_55 (desc, tmp, &fr_pool->list, list) {
F_40 ( & V_55 -> V_60 ) ;
F_46 ( & V_55 -> V_74 ) ;
if ( V_55 -> V_83 )
F_48 ( V_55 -> V_83 ) ;
F_27 ( V_55 ) ;
++ V_15 ;
}
if ( V_15 < V_51 -> V_49 )
F_56 ( L_13 ,
V_51 -> V_49 - V_15 ) ;
}
static int F_57 ( struct V_47 * V_47 )
{
struct V_96 * V_96 = F_58 ( V_47 , struct V_96 ,
V_47 ) ;
struct V_11 * V_7 ;
struct V_12 * V_13 ;
struct V_97 V_98 ;
int V_14 = - V_62 ;
int V_99 , V_100 = 0 ;
F_59 ( V_47 -> V_7 == NULL ) ;
V_7 = V_47 -> V_7 ;
V_13 = & V_7 -> V_13 ;
memset ( & V_98 , 0 , sizeof V_98 ) ;
F_60 ( & V_101 . V_102 ) ;
for ( V_99 = 0 ; V_99 < V_7 -> V_18 ; V_99 ++ ) {
if ( V_7 -> V_20 [ V_99 ] . V_103 <
V_7 -> V_20 [ V_100 ] . V_103 )
V_100 = V_99 ;
}
V_47 -> V_29 = & V_7 -> V_20 [ V_100 ] ;
V_47 -> V_29 -> V_103 ++ ;
F_61 ( & V_101 . V_102 ) ;
F_14 ( L_14 , V_100 , V_47 ) ;
V_98 . V_45 = F_4 ;
V_98 . V_104 = ( void * ) V_47 ;
V_98 . V_105 = V_47 -> V_29 -> V_32 ;
V_98 . V_106 = V_47 -> V_29 -> V_32 ;
V_98 . V_107 . V_108 = V_109 ;
V_98 . V_107 . V_110 = 2 ;
V_98 . V_107 . V_111 = 1 ;
V_98 . V_112 = V_113 ;
V_98 . V_114 = V_115 ;
if ( V_47 -> V_93 ) {
V_98 . V_107 . V_116 = V_117 + 1 ;
V_98 . V_118 |= V_119 ;
V_96 -> V_120 =
F_62 ( V_117 ) ;
} else {
if ( V_13 -> V_121 > V_122 ) {
V_98 . V_107 . V_116 = V_122 + 1 ;
V_96 -> V_120 =
F_62 ( V_122 ) ;
} else {
V_98 . V_107 . V_116 = V_13 -> V_121 ;
V_96 -> V_120 =
F_62 ( V_13 -> V_121 ) ;
F_63 ( L_15 ,
V_7 -> V_17 -> V_8 , V_13 -> V_121 ) ;
}
}
V_14 = F_64 ( V_47 -> V_123 , V_7 -> V_24 , & V_98 ) ;
if ( V_14 )
goto V_124;
V_47 -> V_125 = V_47 -> V_123 -> V_125 ;
F_14 ( L_16 ,
V_47 , V_47 -> V_123 ,
V_47 -> V_123 -> V_125 ) ;
return V_14 ;
V_124:
F_60 ( & V_101 . V_102 ) ;
V_47 -> V_29 -> V_103 -- ;
F_61 ( & V_101 . V_102 ) ;
F_2 ( L_17 , V_14 ) ;
return V_14 ;
}
static
struct V_11 * F_65 ( struct V_126 * V_123 )
{
struct V_11 * V_7 ;
F_60 ( & V_101 . V_127 ) ;
F_66 (device, &ig.device_list, ig_list)
if ( V_7 -> V_17 -> V_128 == V_123 -> V_7 -> V_128 )
goto V_129;
V_7 = F_33 ( sizeof *V_7 , V_21 ) ;
if ( V_7 == NULL )
goto V_130;
V_7 -> V_17 = V_123 -> V_7 ;
if ( F_6 ( V_7 ) ) {
F_27 ( V_7 ) ;
V_7 = NULL ;
goto V_130;
}
F_37 ( & V_7 -> V_131 , & V_101 . V_132 ) ;
V_129:
V_7 -> V_133 ++ ;
V_130:
F_61 ( & V_101 . V_127 ) ;
return V_7 ;
}
static void F_67 ( struct V_11 * V_7 )
{
F_60 ( & V_101 . V_127 ) ;
V_7 -> V_133 -- ;
F_14 ( L_18 , V_7 , V_7 -> V_133 ) ;
if ( ! V_7 -> V_133 ) {
F_28 ( V_7 ) ;
F_40 ( & V_7 -> V_131 ) ;
F_27 ( V_7 ) ;
}
F_61 ( & V_101 . V_127 ) ;
}
static int F_68 ( struct V_96 * V_96 ,
enum V_134 V_29 ,
enum V_134 V_135 )
{
int V_14 ;
V_14 = ( V_96 -> V_136 == V_29 ) ;
if ( V_14 )
V_96 -> V_136 = V_135 ;
return V_14 ;
}
void F_69 ( struct V_137 * V_138 )
{
struct V_96 * V_96 ;
V_96 = F_58 ( V_138 , struct V_96 , V_139 ) ;
F_70 ( & V_96 -> V_140 ) ;
F_70 ( & V_96 -> V_141 ) ;
F_60 ( & V_96 -> V_142 ) ;
V_96 -> V_136 = V_143 ;
F_61 ( & V_96 -> V_142 ) ;
F_71 ( V_96 ) ;
}
static void F_72 ( struct V_96 * V_96 ,
bool V_144 )
{
struct V_47 * V_47 = & V_96 -> V_47 ;
struct V_11 * V_7 = V_47 -> V_7 ;
F_14 ( L_19 ,
V_96 , V_47 -> V_123 , V_47 -> V_125 ) ;
if ( V_47 -> V_125 != NULL ) {
V_47 -> V_29 -> V_103 -- ;
F_73 ( V_47 -> V_123 ) ;
V_47 -> V_125 = NULL ;
}
if ( V_144 ) {
if ( V_96 -> V_145 )
F_74 ( V_96 ) ;
if ( V_7 != NULL ) {
F_67 ( V_7 ) ;
V_47 -> V_7 = NULL ;
}
}
}
void F_71 ( struct V_96 * V_96 )
{
struct V_47 * V_47 = & V_96 -> V_47 ;
F_60 ( & V_101 . V_102 ) ;
F_40 ( & V_96 -> V_146 ) ;
F_61 ( & V_101 . V_102 ) ;
F_60 ( & V_96 -> V_142 ) ;
if ( V_96 -> V_136 != V_143 ) {
F_56 ( L_20 ,
V_96 , V_96 -> V_136 ) ;
F_75 ( V_96 -> V_147 ) ;
V_96 -> V_136 = V_143 ;
}
F_72 ( V_96 , true ) ;
F_61 ( & V_96 -> V_142 ) ;
if ( V_47 -> V_123 != NULL ) {
F_76 ( V_47 -> V_123 ) ;
V_47 -> V_123 = NULL ;
}
F_27 ( V_96 ) ;
}
int F_77 ( struct V_96 * V_96 )
{
struct V_47 * V_47 = & V_96 -> V_47 ;
struct V_148 * V_149 ;
int V_94 = 0 ;
if ( ! F_68 ( V_96 , V_150 ,
V_151 ) )
return 0 ;
F_14 ( L_21 , V_96 , V_96 -> V_136 ) ;
if ( V_96 -> V_152 )
F_78 ( V_96 -> V_152 ) ;
if ( V_47 -> V_123 ) {
V_94 = F_79 ( V_47 -> V_123 ) ;
if ( V_94 )
F_2 ( L_22 ,
V_96 , V_94 ) ;
V_94 = F_80 ( V_47 -> V_125 , & V_47 -> V_153 , & V_149 ) ;
if ( V_94 ) {
F_2 ( L_23 , V_47 ) ;
return 1 ;
}
F_70 ( & V_47 -> V_154 ) ;
}
return 1 ;
}
static void F_81 ( struct V_126 * V_123 )
{
struct V_96 * V_96 ;
V_96 = (struct V_96 * ) V_123 -> V_3 ;
V_96 -> V_136 = V_151 ;
}
static void
F_82 ( struct V_96 * V_96 ,
unsigned int V_155 )
{
struct V_11 * V_7 = V_96 -> V_47 . V_7 ;
unsigned short V_156 , V_157 ;
V_156 = F_83 ( V_155 * 512 , V_158 ) ;
V_157 = F_10 ( unsigned , V_159 ,
V_7 -> V_13 . V_160 ) ;
if ( V_156 > V_157 ) {
V_156 = V_157 ;
V_96 -> V_161 = V_156 * V_158 / 512 ;
} else {
V_96 -> V_161 = V_155 ;
}
V_96 -> V_162 = V_156 ;
F_63 ( L_24 ,
V_96 , V_96 -> V_162 ,
V_96 -> V_161 ) ;
}
static void F_84 ( struct V_126 * V_123 )
{
struct V_11 * V_7 ;
struct V_96 * V_96 ;
struct V_47 * V_47 ;
int V_14 ;
V_96 = (struct V_96 * ) V_123 -> V_3 ;
if ( V_96 -> V_136 != V_163 )
return;
V_47 = & V_96 -> V_47 ;
V_7 = F_65 ( V_123 ) ;
if ( ! V_7 ) {
F_2 ( L_25 ) ;
F_81 ( V_123 ) ;
return;
}
V_47 -> V_7 = V_7 ;
if ( V_164 ) {
if ( ! ( V_7 -> V_13 . V_165 &
V_166 ) ) {
F_56 ( L_26
L_27 ,
V_47 -> V_7 -> V_17 -> V_8 ) ;
V_47 -> V_93 = false ;
} else {
V_47 -> V_93 = true ;
}
}
F_82 ( V_96 , V_167 ) ;
V_14 = F_85 ( V_123 , 1000 ) ;
if ( V_14 ) {
F_2 ( L_28 , V_14 ) ;
F_81 ( V_123 ) ;
return;
}
}
static void F_86 ( struct V_126 * V_123 )
{
struct V_168 V_169 ;
int V_14 ;
struct V_170 V_171 ;
struct V_96 * V_96 = (struct V_96 * ) V_123 -> V_3 ;
struct V_47 * V_47 = & V_96 -> V_47 ;
struct V_11 * V_7 = V_47 -> V_7 ;
if ( V_96 -> V_136 != V_163 )
return;
V_14 = F_57 ( V_47 ) ;
if ( V_14 )
goto V_172;
memset ( & V_169 , 0 , sizeof V_169 ) ;
V_169 . V_173 = V_7 -> V_13 . V_174 ;
V_169 . V_175 = 1 ;
V_169 . V_176 = 7 ;
V_169 . V_177 = 6 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_178 = ( V_179 |
V_180 ) ;
V_169 . V_181 = ( void * ) & V_171 ;
V_169 . V_182 = sizeof( struct V_170 ) ;
V_14 = F_87 ( V_123 , & V_169 ) ;
if ( V_14 ) {
F_2 ( L_29 , V_14 ) ;
goto V_172;
}
return;
V_172:
F_81 ( V_123 ) ;
}
static void F_88 ( struct V_126 * V_123 )
{
struct V_96 * V_96 ;
struct V_183 V_184 ;
struct V_97 V_98 ;
V_96 = (struct V_96 * ) V_123 -> V_3 ;
if ( V_96 -> V_136 != V_163 )
return;
( void ) F_89 ( V_123 -> V_125 , & V_184 , ~ 0 , & V_98 ) ;
F_14 ( L_30 , V_184 . V_185 , V_123 -> V_125 -> V_186 ) ;
V_96 -> V_136 = V_150 ;
F_90 ( & V_96 -> V_187 ) ;
}
static void F_91 ( struct V_126 * V_123 )
{
struct V_96 * V_96 = (struct V_96 * ) V_123 -> V_3 ;
if ( F_77 ( V_96 ) ) {
if ( V_96 -> V_152 )
F_92 ( V_96 -> V_152 ,
V_188 ) ;
else
F_2 ( L_31 ) ;
}
}
static void F_93 ( struct V_126 * V_123 ,
bool V_144 )
{
struct V_96 * V_96 = (struct V_96 * ) V_123 -> V_3 ;
F_91 ( V_123 ) ;
F_72 ( V_96 , V_144 ) ;
F_90 ( & V_96 -> V_141 ) ;
}
static int F_94 ( struct V_126 * V_123 , struct V_189 * V_4 )
{
struct V_96 * V_96 ;
int V_14 = 0 ;
V_96 = (struct V_96 * ) V_123 -> V_3 ;
F_14 ( L_32 ,
F_95 ( V_4 -> V_4 ) , V_4 -> V_4 ,
V_4 -> V_190 , V_123 -> V_3 , V_123 ) ;
F_60 ( & V_96 -> V_142 ) ;
switch ( V_4 -> V_4 ) {
case V_191 :
F_84 ( V_123 ) ;
break;
case V_192 :
F_86 ( V_123 ) ;
break;
case V_193 :
F_88 ( V_123 ) ;
break;
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
F_81 ( V_123 ) ;
break;
case V_199 :
case V_200 :
case V_201 :
F_93 ( V_123 , false ) ;
break;
case V_202 :
F_93 ( V_123 , true ) ;
if ( V_96 -> V_136 != V_143 ) {
V_96 -> V_47 . V_123 = NULL ;
V_14 = 1 ;
}
break;
default:
F_2 ( L_33 ,
F_95 ( V_4 -> V_4 ) , V_4 -> V_4 ) ;
break;
}
F_61 ( & V_96 -> V_142 ) ;
return V_14 ;
}
void F_96 ( struct V_96 * V_96 )
{
V_96 -> V_136 = V_203 ;
V_96 -> V_47 . V_204 = 0 ;
F_97 ( & V_96 -> V_47 . V_154 ) ;
F_97 ( & V_96 -> V_140 ) ;
F_97 ( & V_96 -> V_141 ) ;
F_97 ( & V_96 -> V_187 ) ;
F_31 ( & V_96 -> V_146 ) ;
F_98 ( & V_96 -> V_142 ) ;
}
int F_99 ( struct V_96 * V_96 ,
struct V_205 * V_206 ,
struct V_205 * V_207 ,
int V_208 )
{
struct V_47 * V_47 = & V_96 -> V_47 ;
int V_94 = 0 ;
F_60 ( & V_96 -> V_142 ) ;
sprintf ( V_96 -> V_8 , L_34 , V_207 ) ;
F_14 ( L_35 , V_96 -> V_8 ) ;
V_47 -> V_7 = NULL ;
V_96 -> V_136 = V_163 ;
V_47 -> V_153 . V_209 = V_210 ;
V_47 -> V_153 . V_211 = V_212 ;
V_47 -> V_123 = F_100 ( F_94 ,
( void * ) V_96 ,
V_213 , V_115 ) ;
if ( F_16 ( V_47 -> V_123 ) ) {
V_94 = F_36 ( V_47 -> V_123 ) ;
F_2 ( L_36 , V_94 ) ;
goto V_214;
}
V_94 = F_101 ( V_47 -> V_123 , V_206 , V_207 , 1000 ) ;
if ( V_94 ) {
F_2 ( L_37 , V_94 ) ;
goto V_215;
}
if ( ! V_208 ) {
F_102 ( & V_96 -> V_187 ) ;
if ( V_96 -> V_136 != V_150 ) {
V_94 = - V_216 ;
goto V_217;
}
}
F_61 ( & V_96 -> V_142 ) ;
F_60 ( & V_101 . V_102 ) ;
F_37 ( & V_96 -> V_146 , & V_101 . V_218 ) ;
F_61 ( & V_101 . V_102 ) ;
return 0 ;
V_214:
V_47 -> V_123 = NULL ;
V_215:
V_96 -> V_136 = V_143 ;
V_217:
F_61 ( & V_96 -> V_142 ) ;
F_71 ( V_96 ) ;
return V_94 ;
}
int F_103 ( struct V_96 * V_96 )
{
struct V_219 V_220 , * V_221 ;
struct V_47 * V_47 = & V_96 -> V_47 ;
struct V_222 V_223 ;
int V_224 ;
V_223 . V_225 = V_96 -> V_226 ;
V_223 . V_227 = V_228 ;
V_223 . V_229 = V_47 -> V_7 -> V_24 -> V_230 ;
V_220 . V_209 = ( V_231 ) V_96 -> V_232 ;
V_220 . V_233 = & V_223 ;
V_220 . V_234 = 1 ;
V_220 . V_235 = NULL ;
V_47 -> V_204 ++ ;
V_224 = F_104 ( V_47 -> V_125 , & V_220 , & V_221 ) ;
if ( V_224 ) {
F_2 ( L_38 , V_224 ) ;
V_47 -> V_204 -- ;
}
return V_224 ;
}
int F_105 ( struct V_96 * V_96 , int V_236 )
{
struct V_219 * V_220 , * V_221 ;
int V_15 , V_224 ;
struct V_47 * V_47 = & V_96 -> V_47 ;
unsigned int V_237 = V_96 -> V_238 ;
struct V_239 * V_240 ;
for ( V_220 = V_47 -> V_220 , V_15 = 0 ; V_15 < V_236 ; V_15 ++ , V_220 ++ ) {
V_240 = & V_96 -> V_145 [ V_237 ] ;
V_220 -> V_209 = ( V_231 ) V_240 ;
V_220 -> V_233 = & V_240 -> V_241 ;
V_220 -> V_234 = 1 ;
V_220 -> V_235 = V_220 + 1 ;
V_237 = ( V_237 + 1 ) & V_96 -> V_242 ;
}
V_220 -- ;
V_220 -> V_235 = NULL ;
V_47 -> V_204 += V_236 ;
V_224 = F_104 ( V_47 -> V_125 , V_47 -> V_220 , & V_221 ) ;
if ( V_224 ) {
F_2 ( L_38 , V_224 ) ;
V_47 -> V_204 -= V_236 ;
} else
V_96 -> V_238 = V_237 ;
return V_224 ;
}
int F_106 ( struct V_47 * V_47 , struct V_243 * V_244 ,
bool signal )
{
struct V_148 * V_149 , * V_245 = F_107 ( V_244 ) ;
int V_224 ;
F_108 ( V_47 -> V_7 -> V_17 ,
V_244 -> V_246 , V_247 ,
V_248 ) ;
V_245 -> V_235 = NULL ;
V_245 -> V_209 = ( V_231 ) V_244 ;
V_245 -> V_233 = V_244 -> V_249 ;
V_245 -> V_234 = V_244 -> V_234 ;
V_245 -> V_211 = V_212 ;
V_245 -> V_250 = signal ? V_251 : 0 ;
V_224 = F_80 ( V_47 -> V_125 , & V_244 -> V_252 [ 0 ] , & V_149 ) ;
if ( V_224 )
F_2 ( L_39 ,
V_224 , V_149 -> V_211 ) ;
return V_224 ;
}
static inline bool
F_109 ( struct V_96 * V_96 , void * V_209 )
{
void * V_253 = V_96 -> V_145 ;
int V_254 = V_96 -> V_255 * sizeof( * V_96 -> V_145 ) ;
if ( V_209 >= V_253 && V_209 < V_253 + V_254 )
return false ;
return true ;
}
static void
F_110 ( struct V_47 * V_47 ,
struct V_256 * V_257 )
{
void * V_209 = ( void * ) ( V_231 ) V_257 -> V_209 ;
struct V_96 * V_96 = F_58 ( V_47 , struct V_96 ,
V_47 ) ;
if ( V_257 -> V_190 != V_258 )
if ( V_96 -> V_152 )
F_92 ( V_96 -> V_152 ,
V_188 ) ;
if ( V_257 -> V_209 == V_259 )
return;
if ( F_109 ( V_96 , V_209 ) ) {
struct V_243 * V_55 = V_209 ;
if ( V_55 -> type == V_260 )
F_111 ( V_101 . V_261 , V_55 ) ;
} else {
V_47 -> V_204 -- ;
}
}
static void F_112 ( struct V_256 * V_257 )
{
struct V_47 * V_47 ;
struct V_243 * V_244 ;
struct V_239 * V_240 ;
V_47 = V_257 -> V_125 -> V_104 ;
if ( F_113 ( V_257 -> V_190 == V_262 ) ) {
if ( V_257 -> V_211 == V_263 ) {
V_240 = (struct V_239 * ) ( V_231 ) V_257 -> V_209 ;
F_114 ( V_240 , V_257 -> V_264 ,
V_47 ) ;
} else
if ( V_257 -> V_211 == V_265 ) {
V_244 = (struct V_243 * ) ( V_231 ) V_257 -> V_209 ;
F_115 ( V_244 , V_47 ) ;
} else {
F_2 ( L_40 , V_257 -> V_211 ) ;
}
} else {
if ( V_257 -> V_190 != V_258 )
F_2 ( L_41 ,
F_116 ( V_257 -> V_190 ) , V_257 -> V_190 ,
V_257 -> V_209 , V_257 -> V_266 ) ;
else
F_63 ( L_42 ,
F_116 ( V_257 -> V_190 ) , V_257 -> V_190 ,
V_257 -> V_209 ) ;
if ( V_257 -> V_209 == V_210 )
F_90 ( & V_47 -> V_154 ) ;
else
F_110 ( V_47 , V_257 ) ;
}
}
static void V_37 ( unsigned long V_267 )
{
struct V_28 * V_29 = (struct V_28 * ) V_267 ;
struct V_268 * V_32 = V_29 -> V_32 ;
struct V_256 * const V_269 = V_29 -> V_269 ;
int V_15 , V_270 , V_271 = 0 ;
while ( ( V_270 = F_117 ( V_32 , F_118 ( V_29 -> V_269 ) , V_269 ) ) > 0 ) {
for ( V_15 = 0 ; V_15 < V_270 ; V_15 ++ )
F_112 ( & V_269 [ V_15 ] ) ;
V_271 += V_270 ;
if ( V_271 >= V_272 )
break;
}
F_18 ( V_32 , V_35 ) ;
F_63 ( L_43 , V_271 ) ;
}
static void V_33 ( struct V_268 * V_32 , void * V_273 )
{
struct V_28 * V_29 = V_273 ;
F_119 ( & V_29 -> V_36 ) ;
}
T_1 F_120 ( struct V_274 * V_275 ,
enum V_276 V_277 , T_2 * V_278 )
{
struct V_279 * V_280 = & V_275 -> V_281 [ V_277 ] ;
struct V_54 * V_55 = V_280 -> V_282 ;
unsigned long V_283 = V_275 -> V_284 -> V_7 -> V_283 ;
struct V_285 V_286 ;
int V_14 ;
if ( V_55 && V_55 -> V_83 -> V_89 ) {
V_55 -> V_83 -> V_89 = 0 ;
V_14 = F_121 ( V_55 -> V_83 -> V_85 ,
V_287 , & V_286 ) ;
if ( V_14 ) {
F_122 ( L_44 , V_14 ) ;
goto V_94;
}
if ( V_286 . V_288 & V_287 ) {
T_2 V_289 = V_286 . V_290 . V_291 ;
F_123 ( V_289 , V_283 + 8 ) ;
* V_278 = F_124 ( V_275 -> V_284 ) + V_289 ;
F_122 ( L_45
L_46 ,
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
V_94:
return 0x1 ;
}
