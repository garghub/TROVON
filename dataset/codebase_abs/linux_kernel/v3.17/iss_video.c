const struct V_1 *
F_1 ( enum V_2 V_3 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; ++ V_4 ) {
if ( V_5 [ V_4 ] . V_3 == V_3 )
return & V_5 [ V_4 ] ;
}
return NULL ;
}
static unsigned int F_3 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_10 * V_11 )
{
unsigned int V_12 = V_11 -> V_13 ;
unsigned int V_14 ;
unsigned int V_4 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_15 = V_9 -> V_15 ;
V_11 -> V_16 = V_9 -> V_16 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) - 1 ; ++ V_4 ) {
if ( V_5 [ V_4 ] . V_3 == V_9 -> V_3 )
break;
}
V_14 = V_11 -> V_15 * F_4 ( V_5 [ V_4 ] . V_17 , 8 ) / 8 ;
if ( V_7 -> V_18 )
V_12 = F_5 ( V_12 , V_14 , V_7 -> V_18 ) ;
else
V_12 = V_14 ;
if ( ! V_7 -> V_19 || V_12 != V_14 )
V_12 = F_4 ( V_12 , V_7 -> V_20 ) ;
V_11 -> V_21 = V_5 [ V_4 ] . V_21 ;
V_11 -> V_13 = V_12 ;
V_11 -> V_22 = V_11 -> V_13 * V_11 -> V_16 ;
V_11 -> V_23 = V_9 -> V_23 ;
V_11 -> V_24 = V_9 -> V_24 ;
if ( V_11 -> V_21 == V_25 )
V_11 -> V_22 += ( V_11 -> V_13 * V_11 -> V_16 ) / 2 ;
return V_12 - V_14 ;
}
static void F_6 ( const struct V_10 * V_11 ,
struct V_8 * V_9 )
{
unsigned int V_4 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_15 = V_11 -> V_15 ;
V_9 -> V_16 = V_11 -> V_16 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; ++ V_4 ) {
if ( V_5 [ V_4 ] . V_21 == V_11 -> V_21 )
break;
}
if ( F_7 ( V_4 == F_2 ( V_5 ) ) )
return;
V_9 -> V_3 = V_5 [ V_4 ] . V_3 ;
V_9 -> V_23 = V_11 -> V_23 ;
V_9 -> V_24 = V_11 -> V_24 ;
}
static struct V_26 *
F_8 ( struct V_6 * V_7 , T_1 * V_27 )
{
struct V_28 * V_29 ;
V_29 = F_9 ( & V_7 -> V_27 ) ;
if ( V_29 == NULL ||
F_10 ( V_29 -> V_30 ) != V_31 )
return NULL ;
if ( V_27 )
* V_27 = V_29 -> V_32 ;
return F_11 ( V_29 -> V_30 ) ;
}
static struct V_6 *
F_12 ( struct V_6 * V_7 )
{
struct V_33 V_34 ;
struct V_35 * V_30 = & V_7 -> V_7 . V_30 ;
struct V_36 * V_37 = V_30 -> V_38 ;
struct V_6 * V_39 = NULL ;
F_13 ( & V_37 -> V_40 ) ;
F_14 ( & V_34 , V_30 ) ;
while ( ( V_30 = F_15 ( & V_34 ) ) ) {
if ( V_30 == & V_7 -> V_7 . V_30 )
continue;
if ( F_10 ( V_30 ) != V_41 )
continue;
V_39 = F_16 ( F_17 ( V_30 ) ) ;
if ( V_39 -> type != V_7 -> type )
break;
V_39 = NULL ;
}
F_18 ( & V_37 -> V_40 ) ;
return V_39 ;
}
static int
F_19 ( struct V_6 * V_7 ,
struct V_8 * V_42 )
{
struct V_43 V_44 ;
struct V_26 * V_45 ;
T_1 V_27 ;
int V_46 ;
V_45 = F_8 ( V_7 , & V_27 ) ;
if ( V_45 == NULL )
return - V_47 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_27 = V_27 ;
V_44 . V_48 = V_49 ;
F_13 ( & V_7 -> V_50 ) ;
V_46 = F_20 ( V_45 , V_27 , V_51 , NULL , & V_44 ) ;
F_18 ( & V_7 -> V_50 ) ;
if ( V_46 )
return V_46 ;
* V_42 = V_44 . V_42 ;
return 0 ;
}
static int
F_21 ( struct V_6 * V_7 , struct V_52 * V_53 )
{
struct V_8 V_42 ;
struct V_10 V_54 ;
int V_46 ;
V_46 = F_19 ( V_7 , & V_42 ) ;
if ( V_46 < 0 )
return V_46 ;
V_54 . V_13 = 0 ;
V_46 = F_3 ( V_7 , & V_42 , & V_54 ) ;
if ( V_53 -> V_42 . V_44 . V_11 . V_21 != V_54 . V_21 ||
V_53 -> V_42 . V_44 . V_11 . V_16 != V_54 . V_16 ||
V_53 -> V_42 . V_44 . V_11 . V_15 != V_54 . V_15 ||
V_53 -> V_42 . V_44 . V_11 . V_13 != V_54 . V_13 ||
V_53 -> V_42 . V_44 . V_11 . V_22 != V_54 . V_22 )
return - V_47 ;
return V_46 ;
}
static int F_22 ( struct V_55 * V_56 ,
const struct V_57 * V_44 ,
unsigned int * V_58 , unsigned int * V_59 ,
unsigned int V_60 [] , void * V_61 [] )
{
struct V_52 * V_53 = F_23 ( V_56 ) ;
struct V_6 * V_7 = V_53 -> V_7 ;
* V_59 = 1 ;
V_60 [ 0 ] = V_53 -> V_42 . V_44 . V_11 . V_22 ;
if ( V_60 [ 0 ] == 0 )
return - V_47 ;
V_61 [ 0 ] = V_7 -> V_62 ;
* V_58 = F_24 ( * V_58 , V_7 -> V_63 / F_25 ( V_60 [ 0 ] ) ) ;
return 0 ;
}
static void F_26 ( struct V_64 * V_65 )
{
struct V_66 * V_67 = F_27 ( V_65 , struct V_66 , V_65 ) ;
if ( V_67 -> V_68 )
V_67 -> V_68 = 0 ;
}
static int F_28 ( struct V_64 * V_65 )
{
struct V_52 * V_53 = F_23 ( V_65 -> V_55 ) ;
struct V_66 * V_67 = F_27 ( V_65 , struct V_66 , V_65 ) ;
struct V_6 * V_7 = V_53 -> V_7 ;
unsigned long V_69 = V_53 -> V_42 . V_44 . V_11 . V_22 ;
T_2 V_70 ;
if ( F_29 ( V_65 , 0 ) < V_69 )
return - V_71 ;
V_70 = F_30 ( V_65 , 0 ) ;
if ( ! F_31 ( V_70 , 32 ) ) {
F_32 ( V_7 -> V_72 -> V_73 ,
L_1 ) ;
return - V_47 ;
}
F_33 ( V_65 , 0 , V_69 ) ;
V_67 -> V_68 = V_70 ;
return 0 ;
}
static void F_34 ( struct V_64 * V_65 )
{
struct V_52 * V_53 = F_23 ( V_65 -> V_55 ) ;
struct V_6 * V_7 = V_53 -> V_7 ;
struct V_66 * V_67 = F_27 ( V_65 , struct V_66 , V_65 ) ;
struct V_74 * V_75 = F_35 ( & V_7 -> V_7 . V_30 ) ;
unsigned long V_76 ;
bool V_77 ;
F_36 ( & V_7 -> V_78 , V_76 ) ;
if ( F_37 ( V_7 -> error ) ) {
F_38 ( V_65 , V_79 ) ;
F_39 ( & V_7 -> V_78 , V_76 ) ;
return;
}
V_77 = F_40 ( & V_7 -> V_80 ) ;
F_41 ( & V_67 -> V_81 , & V_7 -> V_80 ) ;
F_39 ( & V_7 -> V_78 , V_76 ) ;
if ( V_77 ) {
enum V_82 V_83 ;
unsigned int V_84 ;
if ( V_7 -> type == V_85 )
V_83 = V_86 ;
else
V_83 = V_87 ;
F_36 ( & V_75 -> V_88 , V_76 ) ;
V_75 -> V_83 |= V_83 ;
V_7 -> V_89 -> V_90 ( V_7 , V_67 ) ;
V_7 -> V_91 |= V_92 ;
V_84 = F_42 ( V_75 ) ;
if ( V_84 )
V_75 -> V_83 |= V_93 ;
F_39 ( & V_75 -> V_88 , V_76 ) ;
if ( V_84 )
F_43 ( V_75 ,
V_94 ) ;
}
}
struct V_66 * F_44 ( struct V_6 * V_7 )
{
struct V_74 * V_75 = F_35 ( & V_7 -> V_7 . V_30 ) ;
enum V_82 V_83 ;
struct V_66 * V_95 ;
unsigned long V_76 ;
struct V_96 V_97 ;
F_36 ( & V_7 -> V_78 , V_76 ) ;
if ( F_7 ( F_40 ( & V_7 -> V_80 ) ) ) {
F_39 ( & V_7 -> V_78 , V_76 ) ;
return NULL ;
}
V_95 = F_45 ( & V_7 -> V_80 , struct V_66 ,
V_81 ) ;
F_46 ( & V_95 -> V_81 ) ;
F_39 ( & V_7 -> V_78 , V_76 ) ;
F_47 ( & V_97 ) ;
V_95 -> V_65 . V_98 . V_99 . V_100 = V_97 . V_100 ;
V_95 -> V_65 . V_98 . V_99 . V_101 = V_97 . V_102 / V_103 ;
if ( V_7 == V_75 -> V_104 && ! V_75 -> V_105 )
V_95 -> V_65 . V_98 . V_106 =
F_48 ( & V_75 -> V_107 ) ;
else
V_95 -> V_65 . V_98 . V_106 = F_49 ( & V_75 -> V_107 ) ;
F_38 ( & V_95 -> V_65 , V_75 -> error ?
V_79 : V_108 ) ;
V_75 -> error = false ;
F_36 ( & V_7 -> V_78 , V_76 ) ;
if ( F_40 ( & V_7 -> V_80 ) ) {
F_39 ( & V_7 -> V_78 , V_76 ) ;
if ( V_7 -> type == V_85 )
V_83 = V_86
| V_93 ;
else
V_83 = V_87
| V_93 ;
F_36 ( & V_75 -> V_88 , V_76 ) ;
V_75 -> V_83 &= ~ V_83 ;
if ( V_7 -> V_75 . V_109 == V_110 )
V_7 -> V_91 |= V_111 ;
F_39 ( & V_75 -> V_88 , V_76 ) ;
return NULL ;
}
if ( V_7 -> type == V_85 && V_75 -> V_112 != NULL ) {
F_50 ( & V_75 -> V_88 ) ;
V_75 -> V_83 &= ~ V_93 ;
F_51 ( & V_75 -> V_88 ) ;
}
V_95 = F_45 ( & V_7 -> V_80 , struct V_66 ,
V_81 ) ;
F_39 ( & V_7 -> V_78 , V_76 ) ;
V_95 -> V_65 . V_83 = V_113 ;
return V_95 ;
}
void F_52 ( struct V_6 * V_7 )
{
unsigned long V_76 ;
F_36 ( & V_7 -> V_78 , V_76 ) ;
while ( ! F_40 ( & V_7 -> V_80 ) ) {
struct V_66 * V_95 ;
V_95 = F_45 ( & V_7 -> V_80 , struct V_66 ,
V_81 ) ;
F_46 ( & V_95 -> V_81 ) ;
F_38 ( & V_95 -> V_65 , V_79 ) ;
}
F_53 ( V_7 -> V_90 ) ;
V_7 -> error = true ;
F_39 ( & V_7 -> V_78 , V_76 ) ;
}
static int
F_54 ( struct V_114 * V_114 , void * V_115 , struct V_116 * V_117 )
{
struct V_6 * V_7 = F_55 ( V_114 ) ;
F_56 ( V_117 -> V_118 , V_119 , sizeof( V_117 -> V_118 ) ) ;
F_56 ( V_117 -> V_120 , V_7 -> V_7 . V_121 , sizeof( V_117 -> V_120 ) ) ;
F_56 ( V_117 -> V_122 , L_2 , sizeof( V_117 -> V_122 ) ) ;
if ( V_7 -> type == V_85 )
V_117 -> V_123 = V_124 | V_125 ;
else
V_117 -> V_123 = V_126 | V_125 ;
V_117 -> V_127 = V_128 | V_125
| V_124 | V_126 ;
return 0 ;
}
static int
F_57 ( struct V_114 * V_114 , void * V_115 , struct V_129 * V_130 )
{
struct V_6 * V_7 = F_55 ( V_114 ) ;
struct V_8 V_42 ;
unsigned int V_32 = V_130 -> V_32 ;
unsigned int V_4 ;
int V_46 ;
if ( V_130 -> type != V_7 -> type )
return - V_47 ;
V_46 = F_19 ( V_7 , & V_42 ) ;
if ( V_46 < 0 )
return V_46 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; ++ V_4 ) {
const struct V_1 * V_131 = & V_5 [ V_4 ] ;
if ( V_42 . V_3 != V_131 -> V_3 )
continue;
if ( V_32 == 0 ) {
V_130 -> V_21 = V_131 -> V_21 ;
F_56 ( V_130 -> V_132 , V_131 -> V_132 ,
sizeof( V_130 -> V_132 ) ) ;
return 0 ;
}
V_32 -- ;
}
return - V_47 ;
}
static int
F_58 ( struct V_114 * V_114 , void * V_115 , struct V_57 * V_42 )
{
struct V_52 * V_53 = F_59 ( V_115 ) ;
struct V_6 * V_7 = F_55 ( V_114 ) ;
if ( V_42 -> type != V_7 -> type )
return - V_47 ;
F_13 ( & V_7 -> V_50 ) ;
* V_42 = V_53 -> V_42 ;
F_18 ( & V_7 -> V_50 ) ;
return 0 ;
}
static int
F_60 ( struct V_114 * V_114 , void * V_115 , struct V_57 * V_42 )
{
struct V_52 * V_53 = F_59 ( V_115 ) ;
struct V_6 * V_7 = F_55 ( V_114 ) ;
struct V_8 V_44 ;
if ( V_42 -> type != V_7 -> type )
return - V_47 ;
F_13 ( & V_7 -> V_50 ) ;
F_6 ( & V_42 -> V_44 . V_11 , & V_44 ) ;
F_3 ( V_7 , & V_44 , & V_42 -> V_44 . V_11 ) ;
V_53 -> V_42 = * V_42 ;
F_18 ( & V_7 -> V_50 ) ;
return 0 ;
}
static int
F_61 ( struct V_114 * V_114 , void * V_115 , struct V_57 * V_42 )
{
struct V_6 * V_7 = F_55 ( V_114 ) ;
struct V_43 V_44 ;
struct V_26 * V_45 ;
T_1 V_27 ;
int V_46 ;
if ( V_42 -> type != V_7 -> type )
return - V_47 ;
V_45 = F_8 ( V_7 , & V_27 ) ;
if ( V_45 == NULL )
return - V_47 ;
F_6 ( & V_42 -> V_44 . V_11 , & V_44 . V_42 ) ;
V_44 . V_27 = V_27 ;
V_44 . V_48 = V_49 ;
V_46 = F_20 ( V_45 , V_27 , V_51 , NULL , & V_44 ) ;
if ( V_46 )
return V_46 ;
F_3 ( V_7 , & V_44 . V_42 , & V_42 -> V_44 . V_11 ) ;
return 0 ;
}
static int
F_62 ( struct V_114 * V_114 , void * V_115 , struct V_133 * V_134 )
{
struct V_6 * V_7 = F_55 ( V_114 ) ;
struct V_26 * V_45 ;
int V_46 ;
V_45 = F_8 ( V_7 , NULL ) ;
if ( V_45 == NULL )
return - V_47 ;
F_13 ( & V_7 -> V_50 ) ;
V_46 = F_20 ( V_45 , V_7 , V_134 , V_134 ) ;
F_18 ( & V_7 -> V_50 ) ;
return V_46 == - V_135 ? - V_136 : V_46 ;
}
static int
F_63 ( struct V_114 * V_114 , void * V_115 , struct V_137 * V_138 )
{
struct V_6 * V_7 = F_55 ( V_114 ) ;
struct V_43 V_42 ;
struct V_26 * V_45 ;
T_1 V_27 ;
int V_46 ;
V_45 = F_8 ( V_7 , & V_27 ) ;
if ( V_45 == NULL )
return - V_47 ;
V_46 = F_20 ( V_45 , V_7 , V_139 , V_138 ) ;
if ( V_46 != - V_135 )
return V_46 ;
V_42 . V_27 = V_27 ;
V_42 . V_48 = V_49 ;
V_46 = F_20 ( V_45 , V_27 , V_51 , NULL , & V_42 ) ;
if ( V_46 < 0 )
return V_46 == - V_135 ? - V_136 : V_46 ;
V_138 -> V_140 . V_141 = 0 ;
V_138 -> V_140 . V_142 = 0 ;
V_138 -> V_140 . V_15 = V_42 . V_42 . V_15 ;
V_138 -> V_140 . V_16 = V_42 . V_42 . V_16 ;
return 0 ;
}
static int
F_64 ( struct V_114 * V_114 , void * V_115 , const struct V_137 * V_138 )
{
struct V_6 * V_7 = F_55 ( V_114 ) ;
struct V_26 * V_45 ;
int V_46 ;
V_45 = F_8 ( V_7 , NULL ) ;
if ( V_45 == NULL )
return - V_47 ;
F_13 ( & V_7 -> V_50 ) ;
V_46 = F_20 ( V_45 , V_7 , V_143 , V_138 ) ;
F_18 ( & V_7 -> V_50 ) ;
return V_46 == - V_135 ? - V_136 : V_46 ;
}
static int
F_65 ( struct V_114 * V_114 , void * V_115 , struct V_144 * V_145 )
{
struct V_52 * V_53 = F_59 ( V_115 ) ;
struct V_6 * V_7 = F_55 ( V_114 ) ;
if ( V_7 -> type != V_146 ||
V_7 -> type != V_145 -> type )
return - V_47 ;
memset ( V_145 , 0 , sizeof( * V_145 ) ) ;
V_145 -> type = V_146 ;
V_145 -> V_147 . V_104 . V_148 = V_149 ;
V_145 -> V_147 . V_104 . V_150 = V_53 -> V_150 ;
return 0 ;
}
static int
F_66 ( struct V_114 * V_114 , void * V_115 , struct V_144 * V_145 )
{
struct V_52 * V_53 = F_59 ( V_115 ) ;
struct V_6 * V_7 = F_55 ( V_114 ) ;
if ( V_7 -> type != V_146 ||
V_7 -> type != V_145 -> type )
return - V_47 ;
if ( V_145 -> V_147 . V_104 . V_150 . V_151 == 0 )
V_145 -> V_147 . V_104 . V_150 . V_151 = 1 ;
V_53 -> V_150 = V_145 -> V_147 . V_104 . V_150 ;
return 0 ;
}
static int
F_67 ( struct V_114 * V_114 , void * V_115 , struct V_152 * V_153 )
{
struct V_52 * V_53 = F_59 ( V_115 ) ;
return F_68 ( & V_53 -> V_90 , V_153 ) ;
}
static int
F_69 ( struct V_114 * V_114 , void * V_115 , struct V_154 * V_155 )
{
struct V_52 * V_53 = F_59 ( V_115 ) ;
return F_70 ( & V_53 -> V_90 , V_155 ) ;
}
static int
F_71 ( struct V_114 * V_114 , void * V_115 , struct V_154 * V_155 )
{
struct V_52 * V_53 = F_59 ( V_115 ) ;
return F_72 ( & V_53 -> V_90 , V_155 ) ;
}
static int
F_73 ( struct V_114 * V_114 , void * V_115 , struct V_154 * V_155 )
{
struct V_52 * V_53 = F_59 ( V_115 ) ;
return F_74 ( & V_53 -> V_90 , V_155 , V_114 -> V_156 & V_157 ) ;
}
static int
F_75 ( struct V_114 * V_114 , void * V_115 , enum V_158 type )
{
struct V_52 * V_53 = F_59 ( V_115 ) ;
struct V_6 * V_7 = F_55 ( V_114 ) ;
struct V_33 V_34 ;
struct V_35 * V_30 ;
enum V_82 V_83 ;
struct V_74 * V_75 ;
struct V_6 * V_39 ;
unsigned long V_76 ;
int V_46 ;
if ( type != V_7 -> type )
return - V_47 ;
F_13 ( & V_7 -> V_159 ) ;
V_75 = V_7 -> V_7 . V_30 . V_75
? F_35 ( & V_7 -> V_7 . V_30 ) : & V_7 -> V_75 ;
V_75 -> V_160 = NULL ;
V_75 -> V_161 = 0 ;
V_75 -> V_162 = 0 ;
V_75 -> V_163 = 0 ;
if ( V_7 -> V_72 -> V_164 -> V_165 )
V_7 -> V_72 -> V_164 -> V_165 ( V_7 -> V_72 , true ) ;
V_46 = F_76 ( & V_7 -> V_7 . V_30 , & V_75 -> V_75 ) ;
if ( V_46 < 0 )
goto V_166;
V_30 = & V_7 -> V_7 . V_30 ;
F_14 ( & V_34 , V_30 ) ;
while ( ( V_30 = F_15 ( & V_34 ) ) )
V_75 -> V_163 |= 1 << V_30 -> V_167 ;
V_46 = F_21 ( V_7 , V_53 ) ;
if ( V_46 < 0 )
goto V_168;
V_7 -> V_169 = V_46 ;
V_7 -> V_170 = V_53 -> V_42 . V_44 . V_11 . V_13 ;
V_39 = F_12 ( V_7 ) ;
if ( V_7 -> type == V_85 ) {
V_83 = V_171 | V_172 ;
V_75 -> V_112 = V_39 ;
V_75 -> V_104 = V_7 ;
} else {
if ( V_39 == NULL ) {
V_46 = - V_173 ;
goto V_168;
}
V_83 = V_174 | V_175 ;
V_75 -> V_112 = V_7 ;
V_75 -> V_104 = V_39 ;
}
F_36 ( & V_75 -> V_88 , V_76 ) ;
V_75 -> V_83 &= ~ V_93 ;
V_75 -> V_83 |= V_83 ;
F_39 ( & V_75 -> V_88 , V_76 ) ;
if ( V_7 -> type == V_146 )
V_75 -> V_176 = V_53 -> V_150 ;
V_7 -> V_90 = & V_53 -> V_90 ;
F_77 ( & V_7 -> V_80 ) ;
V_7 -> error = false ;
F_78 ( & V_75 -> V_107 , - 1 ) ;
V_46 = F_79 ( & V_53 -> V_90 , type ) ;
if ( V_46 < 0 )
goto V_168;
if ( V_75 -> V_112 == NULL ) {
unsigned long V_76 ;
V_46 = F_43 ( V_75 ,
V_110 ) ;
if ( V_46 < 0 )
goto V_177;
F_36 ( & V_7 -> V_78 , V_76 ) ;
if ( F_40 ( & V_7 -> V_80 ) )
V_7 -> V_91 |= V_111 ;
F_39 ( & V_7 -> V_78 , V_76 ) ;
}
F_18 ( & V_7 -> V_159 ) ;
return 0 ;
V_177:
F_80 ( & V_53 -> V_90 , type ) ;
V_168:
F_81 ( & V_7 -> V_7 . V_30 ) ;
V_166:
if ( V_7 -> V_72 -> V_164 -> V_165 )
V_7 -> V_72 -> V_164 -> V_165 ( V_7 -> V_72 , false ) ;
V_7 -> V_90 = NULL ;
F_18 ( & V_7 -> V_159 ) ;
return V_46 ;
}
static int
F_82 ( struct V_114 * V_114 , void * V_115 , enum V_158 type )
{
struct V_52 * V_53 = F_59 ( V_115 ) ;
struct V_6 * V_7 = F_55 ( V_114 ) ;
struct V_74 * V_75 = F_35 ( & V_7 -> V_7 . V_30 ) ;
enum V_82 V_83 ;
unsigned long V_76 ;
if ( type != V_7 -> type )
return - V_47 ;
F_13 ( & V_7 -> V_159 ) ;
if ( ! F_83 ( & V_53 -> V_90 ) )
goto V_178;
if ( V_7 -> type == V_85 )
V_83 = V_171
| V_86 ;
else
V_83 = V_174
| V_87 ;
F_36 ( & V_75 -> V_88 , V_76 ) ;
V_75 -> V_83 &= ~ V_83 ;
F_39 ( & V_75 -> V_88 , V_76 ) ;
F_43 ( V_75 , V_179 ) ;
F_80 ( & V_53 -> V_90 , type ) ;
V_7 -> V_90 = NULL ;
if ( V_7 -> V_72 -> V_164 -> V_165 )
V_7 -> V_72 -> V_164 -> V_165 ( V_7 -> V_72 , false ) ;
F_81 ( & V_7 -> V_7 . V_30 ) ;
V_178:
F_18 ( & V_7 -> V_159 ) ;
return 0 ;
}
static int
F_84 ( struct V_114 * V_114 , void * V_115 , struct V_180 * V_112 )
{
if ( V_112 -> V_32 > 0 )
return - V_47 ;
F_56 ( V_112 -> V_121 , L_3 , sizeof( V_112 -> V_121 ) ) ;
V_112 -> type = V_181 ;
return 0 ;
}
static int
F_85 ( struct V_114 * V_114 , void * V_115 , unsigned int * V_112 )
{
* V_112 = 0 ;
return 0 ;
}
static int
F_86 ( struct V_114 * V_114 , void * V_115 , unsigned int V_112 )
{
return V_112 == 0 ? 0 : - V_47 ;
}
static int F_87 ( struct V_114 * V_114 )
{
struct V_6 * V_7 = F_55 ( V_114 ) ;
struct V_52 * V_182 ;
struct V_55 * V_183 ;
int V_46 = 0 ;
V_182 = F_88 ( sizeof( * V_182 ) , V_184 ) ;
if ( V_182 == NULL )
return - V_185 ;
V_7 -> V_7 . V_186 = V_186 ;
F_89 ( & V_182 -> V_53 , & V_7 -> V_7 ) ;
F_90 ( & V_182 -> V_53 ) ;
if ( F_91 ( V_7 -> V_72 ) == NULL ) {
V_46 = - V_187 ;
goto V_178;
}
V_46 = F_92 ( & V_7 -> V_7 . V_30 , 1 ) ;
if ( V_46 < 0 ) {
F_93 ( V_7 -> V_72 ) ;
goto V_178;
}
V_7 -> V_62 = F_94 ( V_7 -> V_72 -> V_73 ) ;
if ( F_95 ( V_7 -> V_62 ) ) {
V_46 = F_96 ( V_7 -> V_62 ) ;
F_93 ( V_7 -> V_72 ) ;
goto V_178;
}
V_183 = & V_182 -> V_90 ;
V_183 -> type = V_7 -> type ;
V_183 -> V_188 = V_189 ;
V_183 -> V_190 = V_182 ;
V_183 -> V_89 = & V_191 ;
V_183 -> V_192 = & V_193 ;
V_183 -> V_194 = sizeof( struct V_66 ) ;
V_183 -> V_195 = V_196 ;
V_46 = F_97 ( V_183 ) ;
if ( V_46 ) {
F_93 ( V_7 -> V_72 ) ;
goto V_178;
}
memset ( & V_182 -> V_42 , 0 , sizeof( V_182 -> V_42 ) ) ;
V_182 -> V_42 . type = V_7 -> type ;
V_182 -> V_150 . V_151 = 1 ;
V_182 -> V_7 = V_7 ;
V_114 -> V_197 = & V_182 -> V_53 ;
V_178:
if ( V_46 < 0 ) {
F_98 ( & V_182 -> V_53 ) ;
F_99 ( V_182 ) ;
}
return V_46 ;
}
static int F_100 ( struct V_114 * V_114 )
{
struct V_6 * V_7 = F_55 ( V_114 ) ;
struct V_198 * V_53 = V_114 -> V_197 ;
struct V_52 * V_182 = F_59 ( V_53 ) ;
F_82 ( V_114 , V_53 , V_7 -> type ) ;
F_92 ( & V_7 -> V_7 . V_30 , 0 ) ;
F_101 ( & V_182 -> V_90 ) ;
F_98 ( V_53 ) ;
F_99 ( V_182 ) ;
V_114 -> V_197 = NULL ;
F_93 ( V_7 -> V_72 ) ;
return 0 ;
}
static unsigned int F_102 ( struct V_114 * V_114 , T_3 * V_199 )
{
struct V_52 * V_53 = F_59 ( V_114 -> V_197 ) ;
return F_103 ( & V_53 -> V_90 , V_114 , V_199 ) ;
}
static int F_104 ( struct V_114 * V_114 , struct V_200 * V_201 )
{
struct V_52 * V_53 = F_59 ( V_114 -> V_197 ) ;
return F_105 ( & V_53 -> V_90 , V_201 ) ;
}
int F_106 ( struct V_6 * V_7 , const char * V_121 )
{
const char * V_202 ;
int V_46 ;
switch ( V_7 -> type ) {
case V_85 :
V_202 = L_4 ;
V_7 -> V_27 . V_76 = V_203 ;
break;
case V_146 :
V_202 = L_5 ;
V_7 -> V_27 . V_76 = V_204 ;
break;
default:
return - V_47 ;
}
V_46 = F_107 ( & V_7 -> V_7 . V_30 , 1 , & V_7 -> V_27 , 0 ) ;
if ( V_46 < 0 )
return V_46 ;
F_108 ( & V_7 -> V_78 ) ;
F_109 ( & V_7 -> V_50 ) ;
F_78 ( & V_7 -> V_205 , 0 ) ;
F_108 ( & V_7 -> V_75 . V_88 ) ;
F_109 ( & V_7 -> V_159 ) ;
if ( V_7 -> V_89 == NULL )
V_7 -> V_89 = & V_206 ;
V_7 -> V_7 . V_207 = & V_208 ;
snprintf ( V_7 -> V_7 . V_121 , sizeof( V_7 -> V_7 . V_121 ) ,
L_6 , V_121 , V_202 ) ;
V_7 -> V_7 . V_209 = V_210 ;
V_7 -> V_7 . V_211 = V_212 ;
V_7 -> V_7 . V_213 = & V_214 ;
V_7 -> V_75 . V_109 = V_179 ;
F_110 ( & V_7 -> V_7 , V_7 ) ;
return 0 ;
}
void F_111 ( struct V_6 * V_7 )
{
F_112 ( & V_7 -> V_7 . V_30 ) ;
F_113 ( & V_7 -> V_159 ) ;
F_113 ( & V_7 -> V_50 ) ;
}
int F_114 ( struct V_6 * V_7 , struct V_215 * V_216 )
{
int V_46 ;
V_7 -> V_7 . V_217 = V_216 ;
V_46 = F_115 ( & V_7 -> V_7 , V_210 , - 1 ) ;
if ( V_46 < 0 )
F_116 ( V_7 -> V_72 -> V_73 ,
L_7 ,
V_218 , V_46 ) ;
return V_46 ;
}
void F_117 ( struct V_6 * V_7 )
{
F_118 ( & V_7 -> V_7 ) ;
}
