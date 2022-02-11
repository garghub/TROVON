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
if ( F_30 ( V_7 -> error ) )
return - V_72 ;
V_70 = F_31 ( V_65 , 0 ) ;
if ( ! F_32 ( V_70 , 32 ) ) {
F_33 ( V_7 -> V_73 -> V_74 ,
L_1 ) ;
return - V_47 ;
}
F_34 ( V_65 , 0 , V_69 ) ;
V_67 -> V_68 = V_70 ;
return 0 ;
}
static void F_35 ( struct V_64 * V_65 )
{
struct V_52 * V_53 = F_23 ( V_65 -> V_55 ) ;
struct V_6 * V_7 = V_53 -> V_7 ;
struct V_66 * V_67 = F_27 ( V_65 , struct V_66 , V_65 ) ;
struct V_75 * V_76 = F_36 ( & V_7 -> V_7 . V_30 ) ;
unsigned long V_77 ;
bool V_78 ;
F_37 ( & V_7 -> V_79 , V_77 ) ;
if ( F_30 ( V_7 -> error ) ) {
F_38 ( V_65 , V_80 ) ;
F_39 ( & V_7 -> V_79 , V_77 ) ;
return;
}
V_78 = F_40 ( & V_7 -> V_81 ) ;
F_41 ( & V_67 -> V_82 , & V_7 -> V_81 ) ;
F_39 ( & V_7 -> V_79 , V_77 ) ;
if ( V_78 ) {
enum V_83 V_84 ;
unsigned int V_85 ;
if ( V_7 -> type == V_86 )
V_84 = V_87 ;
else
V_84 = V_88 ;
F_37 ( & V_76 -> V_89 , V_77 ) ;
V_76 -> V_84 |= V_84 ;
V_7 -> V_90 -> V_91 ( V_7 , V_67 ) ;
V_7 -> V_92 |= V_93 ;
V_85 = F_42 ( V_76 ) ;
if ( V_85 )
V_76 -> V_84 |= V_94 ;
F_39 ( & V_76 -> V_89 , V_77 ) ;
if ( V_85 )
F_43 ( V_76 ,
V_95 ) ;
}
}
struct V_66 * F_44 ( struct V_6 * V_7 )
{
struct V_75 * V_76 = F_36 ( & V_7 -> V_7 . V_30 ) ;
enum V_83 V_84 ;
struct V_66 * V_96 ;
unsigned long V_77 ;
struct V_97 V_98 ;
F_37 ( & V_7 -> V_79 , V_77 ) ;
if ( F_7 ( F_40 ( & V_7 -> V_81 ) ) ) {
F_39 ( & V_7 -> V_79 , V_77 ) ;
return NULL ;
}
V_96 = F_45 ( & V_7 -> V_81 , struct V_66 ,
V_82 ) ;
F_46 ( & V_96 -> V_82 ) ;
F_39 ( & V_7 -> V_79 , V_77 ) ;
F_47 ( & V_98 ) ;
V_96 -> V_65 . V_99 . V_100 . V_101 = V_98 . V_101 ;
V_96 -> V_65 . V_99 . V_100 . V_102 = V_98 . V_103 / V_104 ;
if ( V_7 == V_76 -> V_105 && ! V_76 -> V_106 )
V_96 -> V_65 . V_99 . V_107 =
F_48 ( & V_76 -> V_108 ) ;
else
V_96 -> V_65 . V_99 . V_107 = F_49 ( & V_76 -> V_108 ) ;
F_38 ( & V_96 -> V_65 , V_76 -> error ?
V_80 : V_109 ) ;
V_76 -> error = false ;
F_37 ( & V_7 -> V_79 , V_77 ) ;
if ( F_40 ( & V_7 -> V_81 ) ) {
F_39 ( & V_7 -> V_79 , V_77 ) ;
if ( V_7 -> type == V_86 )
V_84 = V_87
| V_94 ;
else
V_84 = V_88
| V_94 ;
F_37 ( & V_76 -> V_89 , V_77 ) ;
V_76 -> V_84 &= ~ V_84 ;
if ( V_7 -> V_76 . V_110 == V_111 )
V_7 -> V_92 |= V_112 ;
F_39 ( & V_76 -> V_89 , V_77 ) ;
return NULL ;
}
if ( V_7 -> type == V_86 && V_76 -> V_113 != NULL ) {
F_50 ( & V_76 -> V_89 ) ;
V_76 -> V_84 &= ~ V_94 ;
F_51 ( & V_76 -> V_89 ) ;
}
V_96 = F_45 ( & V_7 -> V_81 , struct V_66 ,
V_82 ) ;
F_39 ( & V_7 -> V_79 , V_77 ) ;
V_96 -> V_65 . V_84 = V_114 ;
return V_96 ;
}
void F_52 ( struct V_6 * V_7 )
{
unsigned long V_77 ;
F_37 ( & V_7 -> V_79 , V_77 ) ;
while ( ! F_40 ( & V_7 -> V_81 ) ) {
struct V_66 * V_96 ;
V_96 = F_45 ( & V_7 -> V_81 , struct V_66 ,
V_82 ) ;
F_46 ( & V_96 -> V_82 ) ;
F_38 ( & V_96 -> V_65 , V_80 ) ;
}
V_7 -> error = true ;
F_39 ( & V_7 -> V_79 , V_77 ) ;
}
static int
F_53 ( struct V_115 * V_115 , void * V_116 , struct V_117 * V_118 )
{
struct V_6 * V_7 = F_54 ( V_115 ) ;
F_55 ( V_118 -> V_119 , V_120 , sizeof( V_118 -> V_119 ) ) ;
F_55 ( V_118 -> V_121 , V_7 -> V_7 . V_122 , sizeof( V_118 -> V_121 ) ) ;
F_55 ( V_118 -> V_123 , L_2 , sizeof( V_118 -> V_123 ) ) ;
if ( V_7 -> type == V_86 )
V_118 -> V_124 = V_125 | V_126 ;
else
V_118 -> V_124 = V_127 | V_126 ;
V_118 -> V_128 = V_129 | V_126
| V_125 | V_127 ;
return 0 ;
}
static int
F_56 ( struct V_115 * V_115 , void * V_116 , struct V_130 * V_131 )
{
struct V_6 * V_7 = F_54 ( V_115 ) ;
struct V_8 V_42 ;
unsigned int V_32 = V_131 -> V_32 ;
unsigned int V_4 ;
int V_46 ;
if ( V_131 -> type != V_7 -> type )
return - V_47 ;
V_46 = F_19 ( V_7 , & V_42 ) ;
if ( V_46 < 0 )
return V_46 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; ++ V_4 ) {
const struct V_1 * V_132 = & V_5 [ V_4 ] ;
if ( V_42 . V_3 != V_132 -> V_3 )
continue;
if ( V_32 == 0 ) {
V_131 -> V_21 = V_132 -> V_21 ;
F_55 ( V_131 -> V_133 , V_132 -> V_133 ,
sizeof( V_131 -> V_133 ) ) ;
return 0 ;
}
V_32 -- ;
}
return - V_47 ;
}
static int
F_57 ( struct V_115 * V_115 , void * V_116 , struct V_57 * V_42 )
{
struct V_52 * V_53 = F_58 ( V_116 ) ;
struct V_6 * V_7 = F_54 ( V_115 ) ;
if ( V_42 -> type != V_7 -> type )
return - V_47 ;
F_13 ( & V_7 -> V_50 ) ;
* V_42 = V_53 -> V_42 ;
F_18 ( & V_7 -> V_50 ) ;
return 0 ;
}
static int
F_59 ( struct V_115 * V_115 , void * V_116 , struct V_57 * V_42 )
{
struct V_52 * V_53 = F_58 ( V_116 ) ;
struct V_6 * V_7 = F_54 ( V_115 ) ;
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
F_60 ( struct V_115 * V_115 , void * V_116 , struct V_57 * V_42 )
{
struct V_6 * V_7 = F_54 ( V_115 ) ;
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
F_61 ( struct V_115 * V_115 , void * V_116 , struct V_134 * V_135 )
{
struct V_6 * V_7 = F_54 ( V_115 ) ;
struct V_26 * V_45 ;
int V_46 ;
V_45 = F_8 ( V_7 , NULL ) ;
if ( V_45 == NULL )
return - V_47 ;
F_13 ( & V_7 -> V_50 ) ;
V_46 = F_20 ( V_45 , V_7 , V_135 , V_135 ) ;
F_18 ( & V_7 -> V_50 ) ;
return V_46 == - V_136 ? - V_137 : V_46 ;
}
static int
F_62 ( struct V_115 * V_115 , void * V_116 , struct V_138 * V_139 )
{
struct V_6 * V_7 = F_54 ( V_115 ) ;
struct V_43 V_42 ;
struct V_26 * V_45 ;
T_1 V_27 ;
int V_46 ;
V_45 = F_8 ( V_7 , & V_27 ) ;
if ( V_45 == NULL )
return - V_47 ;
V_46 = F_20 ( V_45 , V_7 , V_140 , V_139 ) ;
if ( V_46 != - V_136 )
return V_46 ;
V_42 . V_27 = V_27 ;
V_42 . V_48 = V_49 ;
V_46 = F_20 ( V_45 , V_27 , V_51 , NULL , & V_42 ) ;
if ( V_46 < 0 )
return V_46 == - V_136 ? - V_137 : V_46 ;
V_139 -> V_141 . V_142 = 0 ;
V_139 -> V_141 . V_143 = 0 ;
V_139 -> V_141 . V_15 = V_42 . V_42 . V_15 ;
V_139 -> V_141 . V_16 = V_42 . V_42 . V_16 ;
return 0 ;
}
static int
F_63 ( struct V_115 * V_115 , void * V_116 , const struct V_138 * V_139 )
{
struct V_6 * V_7 = F_54 ( V_115 ) ;
struct V_26 * V_45 ;
int V_46 ;
V_45 = F_8 ( V_7 , NULL ) ;
if ( V_45 == NULL )
return - V_47 ;
F_13 ( & V_7 -> V_50 ) ;
V_46 = F_20 ( V_45 , V_7 , V_144 , V_139 ) ;
F_18 ( & V_7 -> V_50 ) ;
return V_46 == - V_136 ? - V_137 : V_46 ;
}
static int
F_64 ( struct V_115 * V_115 , void * V_116 , struct V_145 * V_146 )
{
struct V_52 * V_53 = F_58 ( V_116 ) ;
struct V_6 * V_7 = F_54 ( V_115 ) ;
if ( V_7 -> type != V_147 ||
V_7 -> type != V_146 -> type )
return - V_47 ;
memset ( V_146 , 0 , sizeof( * V_146 ) ) ;
V_146 -> type = V_147 ;
V_146 -> V_148 . V_105 . V_149 = V_150 ;
V_146 -> V_148 . V_105 . V_151 = V_53 -> V_151 ;
return 0 ;
}
static int
F_65 ( struct V_115 * V_115 , void * V_116 , struct V_145 * V_146 )
{
struct V_52 * V_53 = F_58 ( V_116 ) ;
struct V_6 * V_7 = F_54 ( V_115 ) ;
if ( V_7 -> type != V_147 ||
V_7 -> type != V_146 -> type )
return - V_47 ;
if ( V_146 -> V_148 . V_105 . V_151 . V_152 == 0 )
V_146 -> V_148 . V_105 . V_151 . V_152 = 1 ;
V_53 -> V_151 = V_146 -> V_148 . V_105 . V_151 ;
return 0 ;
}
static int
F_66 ( struct V_115 * V_115 , void * V_116 , struct V_153 * V_154 )
{
struct V_52 * V_53 = F_58 ( V_116 ) ;
return F_67 ( & V_53 -> V_91 , V_154 ) ;
}
static int
F_68 ( struct V_115 * V_115 , void * V_116 , struct V_155 * V_156 )
{
struct V_52 * V_53 = F_58 ( V_116 ) ;
return F_69 ( & V_53 -> V_91 , V_156 ) ;
}
static int
F_70 ( struct V_115 * V_115 , void * V_116 , struct V_155 * V_156 )
{
struct V_52 * V_53 = F_58 ( V_116 ) ;
return F_71 ( & V_53 -> V_91 , V_156 ) ;
}
static int
F_72 ( struct V_115 * V_115 , void * V_116 , struct V_155 * V_156 )
{
struct V_52 * V_53 = F_58 ( V_116 ) ;
return F_73 ( & V_53 -> V_91 , V_156 , V_115 -> V_157 & V_158 ) ;
}
static int
F_74 ( struct V_115 * V_115 , void * V_116 , enum V_159 type )
{
struct V_52 * V_53 = F_58 ( V_116 ) ;
struct V_6 * V_7 = F_54 ( V_115 ) ;
struct V_33 V_34 ;
struct V_35 * V_30 ;
enum V_83 V_84 ;
struct V_75 * V_76 ;
struct V_6 * V_39 ;
unsigned long V_77 ;
int V_46 ;
if ( type != V_7 -> type )
return - V_47 ;
F_13 ( & V_7 -> V_160 ) ;
V_76 = V_7 -> V_7 . V_30 . V_76
? F_36 ( & V_7 -> V_7 . V_30 ) : & V_7 -> V_76 ;
V_76 -> V_161 = NULL ;
V_76 -> V_162 = 0 ;
V_76 -> V_163 = 0 ;
V_76 -> V_164 = 0 ;
if ( V_7 -> V_73 -> V_165 -> V_166 )
V_7 -> V_73 -> V_165 -> V_166 ( V_7 -> V_73 , true ) ;
V_46 = F_75 ( & V_7 -> V_7 . V_30 , & V_76 -> V_76 ) ;
if ( V_46 < 0 )
goto V_167;
V_30 = & V_7 -> V_7 . V_30 ;
F_14 ( & V_34 , V_30 ) ;
while ( ( V_30 = F_15 ( & V_34 ) ) )
V_76 -> V_164 |= 1 << V_30 -> V_168 ;
V_46 = F_21 ( V_7 , V_53 ) ;
if ( V_46 < 0 )
goto V_169;
V_7 -> V_170 = V_46 ;
V_7 -> V_171 = V_53 -> V_42 . V_44 . V_11 . V_13 ;
V_39 = F_12 ( V_7 ) ;
if ( V_7 -> type == V_86 ) {
V_84 = V_172 | V_173 ;
V_76 -> V_113 = V_39 ;
V_76 -> V_105 = V_7 ;
} else {
if ( V_39 == NULL ) {
V_46 = - V_174 ;
goto V_169;
}
V_84 = V_175 | V_176 ;
V_76 -> V_113 = V_7 ;
V_76 -> V_105 = V_39 ;
}
F_37 ( & V_76 -> V_89 , V_77 ) ;
V_76 -> V_84 &= ~ V_94 ;
V_76 -> V_84 |= V_84 ;
F_39 ( & V_76 -> V_89 , V_77 ) ;
if ( V_7 -> type == V_147 )
V_76 -> V_177 = V_53 -> V_151 ;
V_7 -> V_91 = & V_53 -> V_91 ;
F_76 ( & V_7 -> V_81 ) ;
F_77 ( & V_7 -> V_79 ) ;
V_7 -> error = false ;
F_78 ( & V_76 -> V_108 , - 1 ) ;
V_46 = F_79 ( & V_53 -> V_91 , type ) ;
if ( V_46 < 0 )
goto V_169;
if ( V_76 -> V_113 == NULL ) {
unsigned long V_77 ;
V_46 = F_43 ( V_76 ,
V_111 ) ;
if ( V_46 < 0 )
goto V_178;
F_37 ( & V_7 -> V_79 , V_77 ) ;
if ( F_40 ( & V_7 -> V_81 ) )
V_7 -> V_92 |= V_112 ;
F_39 ( & V_7 -> V_79 , V_77 ) ;
}
F_18 ( & V_7 -> V_160 ) ;
return 0 ;
V_178:
F_80 ( & V_53 -> V_91 , type ) ;
V_169:
F_81 ( & V_7 -> V_7 . V_30 ) ;
V_167:
if ( V_7 -> V_73 -> V_165 -> V_166 )
V_7 -> V_73 -> V_165 -> V_166 ( V_7 -> V_73 , false ) ;
V_7 -> V_91 = NULL ;
F_18 ( & V_7 -> V_160 ) ;
return V_46 ;
}
static int
F_82 ( struct V_115 * V_115 , void * V_116 , enum V_159 type )
{
struct V_52 * V_53 = F_58 ( V_116 ) ;
struct V_6 * V_7 = F_54 ( V_115 ) ;
struct V_75 * V_76 = F_36 ( & V_7 -> V_7 . V_30 ) ;
enum V_83 V_84 ;
unsigned long V_77 ;
if ( type != V_7 -> type )
return - V_47 ;
F_13 ( & V_7 -> V_160 ) ;
if ( ! F_83 ( & V_53 -> V_91 ) )
goto V_179;
if ( V_7 -> type == V_86 )
V_84 = V_172
| V_87 ;
else
V_84 = V_175
| V_88 ;
F_37 ( & V_76 -> V_89 , V_77 ) ;
V_76 -> V_84 &= ~ V_84 ;
F_39 ( & V_76 -> V_89 , V_77 ) ;
F_43 ( V_76 , V_180 ) ;
F_80 ( & V_53 -> V_91 , type ) ;
V_7 -> V_91 = NULL ;
if ( V_7 -> V_73 -> V_165 -> V_166 )
V_7 -> V_73 -> V_165 -> V_166 ( V_7 -> V_73 , false ) ;
F_81 ( & V_7 -> V_7 . V_30 ) ;
V_179:
F_18 ( & V_7 -> V_160 ) ;
return 0 ;
}
static int
F_84 ( struct V_115 * V_115 , void * V_116 , struct V_181 * V_113 )
{
if ( V_113 -> V_32 > 0 )
return - V_47 ;
F_55 ( V_113 -> V_122 , L_3 , sizeof( V_113 -> V_122 ) ) ;
V_113 -> type = V_182 ;
return 0 ;
}
static int
F_85 ( struct V_115 * V_115 , void * V_116 , unsigned int * V_113 )
{
* V_113 = 0 ;
return 0 ;
}
static int
F_86 ( struct V_115 * V_115 , void * V_116 , unsigned int V_113 )
{
return V_113 == 0 ? 0 : - V_47 ;
}
static int F_87 ( struct V_115 * V_115 )
{
struct V_6 * V_7 = F_54 ( V_115 ) ;
struct V_52 * V_183 ;
struct V_55 * V_184 ;
int V_46 = 0 ;
V_183 = F_88 ( sizeof( * V_183 ) , V_185 ) ;
if ( V_183 == NULL )
return - V_186 ;
F_89 ( & V_183 -> V_53 , & V_7 -> V_7 ) ;
F_90 ( & V_183 -> V_53 ) ;
if ( F_91 ( V_7 -> V_73 ) == NULL ) {
V_46 = - V_187 ;
goto V_179;
}
V_46 = F_92 ( & V_7 -> V_7 . V_30 , 1 ) ;
if ( V_46 < 0 ) {
F_93 ( V_7 -> V_73 ) ;
goto V_179;
}
V_7 -> V_62 = F_94 ( V_7 -> V_73 -> V_74 ) ;
if ( F_95 ( V_7 -> V_62 ) ) {
V_46 = F_96 ( V_7 -> V_62 ) ;
F_93 ( V_7 -> V_73 ) ;
goto V_179;
}
V_184 = & V_183 -> V_91 ;
V_184 -> type = V_7 -> type ;
V_184 -> V_188 = V_189 ;
V_184 -> V_190 = V_183 ;
V_184 -> V_90 = & V_191 ;
V_184 -> V_192 = & V_193 ;
V_184 -> V_194 = sizeof( struct V_66 ) ;
V_184 -> V_195 = V_196 ;
V_46 = F_97 ( V_184 ) ;
if ( V_46 ) {
F_93 ( V_7 -> V_73 ) ;
goto V_179;
}
memset ( & V_183 -> V_42 , 0 , sizeof( V_183 -> V_42 ) ) ;
V_183 -> V_42 . type = V_7 -> type ;
V_183 -> V_151 . V_152 = 1 ;
V_183 -> V_7 = V_7 ;
V_115 -> V_197 = & V_183 -> V_53 ;
V_179:
if ( V_46 < 0 ) {
F_98 ( & V_183 -> V_53 ) ;
F_99 ( V_183 ) ;
}
return V_46 ;
}
static int F_100 ( struct V_115 * V_115 )
{
struct V_6 * V_7 = F_54 ( V_115 ) ;
struct V_198 * V_53 = V_115 -> V_197 ;
struct V_52 * V_183 = F_58 ( V_53 ) ;
F_82 ( V_115 , V_53 , V_7 -> type ) ;
F_92 ( & V_7 -> V_7 . V_30 , 0 ) ;
F_101 ( & V_183 -> V_91 ) ;
F_98 ( V_53 ) ;
F_99 ( V_183 ) ;
V_115 -> V_197 = NULL ;
F_93 ( V_7 -> V_73 ) ;
return 0 ;
}
static unsigned int F_102 ( struct V_115 * V_115 , T_3 * V_199 )
{
struct V_52 * V_53 = F_58 ( V_115 -> V_197 ) ;
return F_103 ( & V_53 -> V_91 , V_115 , V_199 ) ;
}
static int F_104 ( struct V_115 * V_115 , struct V_200 * V_201 )
{
struct V_52 * V_53 = F_58 ( V_115 -> V_197 ) ;
return F_105 ( & V_53 -> V_91 , V_201 ) ;
}
int F_106 ( struct V_6 * V_7 , const char * V_122 )
{
const char * V_202 ;
int V_46 ;
switch ( V_7 -> type ) {
case V_86 :
V_202 = L_4 ;
V_7 -> V_27 . V_77 = V_203 ;
break;
case V_147 :
V_202 = L_5 ;
V_7 -> V_27 . V_77 = V_204 ;
break;
default:
return - V_47 ;
}
V_46 = F_107 ( & V_7 -> V_7 . V_30 , 1 , & V_7 -> V_27 , 0 ) ;
if ( V_46 < 0 )
return V_46 ;
F_108 ( & V_7 -> V_50 ) ;
F_78 ( & V_7 -> V_205 , 0 ) ;
F_77 ( & V_7 -> V_76 . V_89 ) ;
F_108 ( & V_7 -> V_160 ) ;
if ( V_7 -> V_90 == NULL )
V_7 -> V_90 = & V_206 ;
V_7 -> V_7 . V_207 = & V_208 ;
snprintf ( V_7 -> V_7 . V_122 , sizeof( V_7 -> V_7 . V_122 ) ,
L_6 , V_122 , V_202 ) ;
V_7 -> V_7 . V_209 = V_210 ;
V_7 -> V_7 . V_211 = V_212 ;
V_7 -> V_7 . V_213 = & V_214 ;
V_7 -> V_76 . V_110 = V_180 ;
F_109 ( & V_7 -> V_7 , V_7 ) ;
return 0 ;
}
void F_110 ( struct V_6 * V_7 )
{
F_111 ( & V_7 -> V_7 . V_30 ) ;
F_112 ( & V_7 -> V_160 ) ;
F_112 ( & V_7 -> V_50 ) ;
}
int F_113 ( struct V_6 * V_7 , struct V_215 * V_216 )
{
int V_46 ;
V_7 -> V_7 . V_217 = V_216 ;
V_46 = F_114 ( & V_7 -> V_7 , V_210 , - 1 ) ;
if ( V_46 < 0 )
F_115 ( V_7 -> V_73 -> V_74 ,
L_7 ,
V_218 , V_46 ) ;
return V_46 ;
}
void F_116 ( struct V_6 * V_7 )
{
F_117 ( & V_7 -> V_7 ) ;
}
