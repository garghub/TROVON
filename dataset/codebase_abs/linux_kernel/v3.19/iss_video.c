const struct V_1 *
F_1 ( T_1 V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
if ( V_4 [ V_3 ] . V_2 == V_2 )
return & V_4 [ V_3 ] ;
}
return NULL ;
}
static unsigned int F_3 ( const struct V_5 * V_6 ,
const struct V_7 * V_8 ,
struct V_9 * V_10 )
{
unsigned int V_11 = V_10 -> V_12 ;
unsigned int V_13 ;
unsigned int V_3 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_14 = V_8 -> V_14 ;
V_10 -> V_15 = V_8 -> V_15 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) - 1 ; ++ V_3 ) {
if ( V_4 [ V_3 ] . V_2 == V_8 -> V_2 )
break;
}
V_13 = V_10 -> V_14 * F_4 ( V_4 [ V_3 ] . V_16 , 8 ) / 8 ;
if ( V_6 -> V_17 )
V_11 = F_5 ( V_11 , V_13 , V_6 -> V_17 ) ;
else
V_11 = V_13 ;
if ( ! V_6 -> V_18 || V_11 != V_13 )
V_11 = F_4 ( V_11 , V_6 -> V_19 ) ;
V_10 -> V_20 = V_4 [ V_3 ] . V_20 ;
V_10 -> V_12 = V_11 ;
V_10 -> V_21 = V_10 -> V_12 * V_10 -> V_15 ;
V_10 -> V_22 = V_8 -> V_22 ;
V_10 -> V_23 = V_8 -> V_23 ;
if ( V_10 -> V_20 == V_24 )
V_10 -> V_21 += ( V_10 -> V_12 * V_10 -> V_15 ) / 2 ;
return V_11 - V_13 ;
}
static void F_6 ( const struct V_9 * V_10 ,
struct V_7 * V_8 )
{
unsigned int V_3 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_14 = V_10 -> V_14 ;
V_8 -> V_15 = V_10 -> V_15 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
if ( V_4 [ V_3 ] . V_20 == V_10 -> V_20 )
break;
}
if ( F_7 ( V_3 == F_2 ( V_4 ) ) )
return;
V_8 -> V_2 = V_4 [ V_3 ] . V_2 ;
V_8 -> V_22 = V_10 -> V_22 ;
V_8 -> V_23 = V_10 -> V_23 ;
}
static struct V_25 *
F_8 ( struct V_5 * V_6 , T_1 * V_26 )
{
struct V_27 * V_28 ;
V_28 = F_9 ( & V_6 -> V_26 ) ;
if ( V_28 == NULL ||
F_10 ( V_28 -> V_29 ) != V_30 )
return NULL ;
if ( V_26 )
* V_26 = V_28 -> V_31 ;
return F_11 ( V_28 -> V_29 ) ;
}
static struct V_5 *
F_12 ( struct V_5 * V_6 )
{
struct V_32 V_33 ;
struct V_34 * V_29 = & V_6 -> V_6 . V_29 ;
struct V_35 * V_36 = V_29 -> V_37 ;
struct V_5 * V_38 = NULL ;
F_13 ( & V_36 -> V_39 ) ;
F_14 ( & V_33 , V_29 ) ;
while ( ( V_29 = F_15 ( & V_33 ) ) ) {
if ( V_29 == & V_6 -> V_6 . V_29 )
continue;
if ( F_10 ( V_29 ) != V_40 )
continue;
V_38 = F_16 ( F_17 ( V_29 ) ) ;
if ( V_38 -> type != V_6 -> type )
break;
V_38 = NULL ;
}
F_18 ( & V_36 -> V_39 ) ;
return V_38 ;
}
static int
F_19 ( struct V_5 * V_6 ,
struct V_7 * V_41 )
{
struct V_42 V_43 ;
struct V_25 * V_44 ;
T_1 V_26 ;
int V_45 ;
V_44 = F_8 ( V_6 , & V_26 ) ;
if ( V_44 == NULL )
return - V_46 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_26 = V_26 ;
V_43 . V_47 = V_48 ;
F_13 ( & V_6 -> V_49 ) ;
V_45 = F_20 ( V_44 , V_26 , V_50 , NULL , & V_43 ) ;
F_18 ( & V_6 -> V_49 ) ;
if ( V_45 )
return V_45 ;
* V_41 = V_43 . V_41 ;
return 0 ;
}
static int
F_21 ( struct V_5 * V_6 , struct V_51 * V_52 )
{
struct V_7 V_41 ;
struct V_9 V_53 ;
int V_45 ;
V_45 = F_19 ( V_6 , & V_41 ) ;
if ( V_45 < 0 )
return V_45 ;
V_53 . V_12 = 0 ;
V_45 = F_3 ( V_6 , & V_41 , & V_53 ) ;
if ( V_52 -> V_41 . V_43 . V_10 . V_20 != V_53 . V_20 ||
V_52 -> V_41 . V_43 . V_10 . V_15 != V_53 . V_15 ||
V_52 -> V_41 . V_43 . V_10 . V_14 != V_53 . V_14 ||
V_52 -> V_41 . V_43 . V_10 . V_12 != V_53 . V_12 ||
V_52 -> V_41 . V_43 . V_10 . V_21 != V_53 . V_21 )
return - V_46 ;
return V_45 ;
}
static int F_22 ( struct V_54 * V_55 ,
const struct V_56 * V_43 ,
unsigned int * V_57 , unsigned int * V_58 ,
unsigned int V_59 [] , void * V_60 [] )
{
struct V_51 * V_52 = F_23 ( V_55 ) ;
struct V_5 * V_6 = V_52 -> V_6 ;
* V_58 = 1 ;
V_59 [ 0 ] = V_52 -> V_41 . V_43 . V_10 . V_21 ;
if ( V_59 [ 0 ] == 0 )
return - V_46 ;
V_60 [ 0 ] = V_6 -> V_61 ;
* V_57 = F_24 ( * V_57 , V_6 -> V_62 / F_25 ( V_59 [ 0 ] ) ) ;
return 0 ;
}
static void F_26 ( struct V_63 * V_64 )
{
struct V_65 * V_66 = F_27 ( V_64 , struct V_65 , V_64 ) ;
if ( V_66 -> V_67 )
V_66 -> V_67 = 0 ;
}
static int F_28 ( struct V_63 * V_64 )
{
struct V_51 * V_52 = F_23 ( V_64 -> V_54 ) ;
struct V_65 * V_66 = F_27 ( V_64 , struct V_65 , V_64 ) ;
struct V_5 * V_6 = V_52 -> V_6 ;
unsigned long V_68 = V_52 -> V_41 . V_43 . V_10 . V_21 ;
T_2 V_69 ;
if ( F_29 ( V_64 , 0 ) < V_68 )
return - V_70 ;
V_69 = F_30 ( V_64 , 0 ) ;
if ( ! F_31 ( V_69 , 32 ) ) {
F_32 ( V_6 -> V_71 -> V_72 ,
L_1 ) ;
return - V_46 ;
}
F_33 ( V_64 , 0 , V_68 ) ;
V_66 -> V_67 = V_69 ;
return 0 ;
}
static void F_34 ( struct V_63 * V_64 )
{
struct V_51 * V_52 = F_23 ( V_64 -> V_54 ) ;
struct V_5 * V_6 = V_52 -> V_6 ;
struct V_65 * V_66 = F_27 ( V_64 , struct V_65 , V_64 ) ;
struct V_73 * V_74 = F_35 ( & V_6 -> V_6 . V_29 ) ;
unsigned long V_75 ;
bool V_76 ;
F_36 ( & V_6 -> V_77 , V_75 ) ;
if ( F_37 ( V_6 -> error ) ) {
F_38 ( V_64 , V_78 ) ;
F_39 ( & V_6 -> V_77 , V_75 ) ;
return;
}
V_76 = F_40 ( & V_6 -> V_79 ) ;
F_41 ( & V_66 -> V_80 , & V_6 -> V_79 ) ;
F_39 ( & V_6 -> V_77 , V_75 ) ;
if ( V_76 ) {
enum V_81 V_82 ;
unsigned int V_83 ;
if ( V_6 -> type == V_84 )
V_82 = V_85 ;
else
V_82 = V_86 ;
F_36 ( & V_74 -> V_87 , V_75 ) ;
V_74 -> V_82 |= V_82 ;
V_6 -> V_88 -> V_89 ( V_6 , V_66 ) ;
V_6 -> V_90 |= V_91 ;
V_83 = F_42 ( V_74 ) ;
if ( V_83 )
V_74 -> V_82 |= V_92 ;
F_39 ( & V_74 -> V_87 , V_75 ) ;
if ( V_83 )
F_43 ( V_74 ,
V_93 ) ;
}
}
struct V_65 * F_44 ( struct V_5 * V_6 )
{
struct V_73 * V_74 = F_35 ( & V_6 -> V_6 . V_29 ) ;
enum V_81 V_82 ;
struct V_65 * V_94 ;
unsigned long V_75 ;
struct V_95 V_96 ;
F_36 ( & V_6 -> V_77 , V_75 ) ;
if ( F_7 ( F_40 ( & V_6 -> V_79 ) ) ) {
F_39 ( & V_6 -> V_77 , V_75 ) ;
return NULL ;
}
V_94 = F_45 ( & V_6 -> V_79 , struct V_65 ,
V_80 ) ;
F_46 ( & V_94 -> V_80 ) ;
F_39 ( & V_6 -> V_77 , V_75 ) ;
F_47 ( & V_96 ) ;
V_94 -> V_64 . V_97 . V_98 . V_99 = V_96 . V_99 ;
V_94 -> V_64 . V_97 . V_98 . V_100 = V_96 . V_101 / V_102 ;
if ( V_6 == V_74 -> V_103 && ! V_74 -> V_104 )
V_94 -> V_64 . V_97 . V_105 =
F_48 ( & V_74 -> V_106 ) ;
else
V_94 -> V_64 . V_97 . V_105 = F_49 ( & V_74 -> V_106 ) ;
F_38 ( & V_94 -> V_64 , V_74 -> error ?
V_78 : V_107 ) ;
V_74 -> error = false ;
F_36 ( & V_6 -> V_77 , V_75 ) ;
if ( F_40 ( & V_6 -> V_79 ) ) {
F_39 ( & V_6 -> V_77 , V_75 ) ;
if ( V_6 -> type == V_84 )
V_82 = V_85
| V_92 ;
else
V_82 = V_86
| V_92 ;
F_36 ( & V_74 -> V_87 , V_75 ) ;
V_74 -> V_82 &= ~ V_82 ;
if ( V_6 -> V_74 . V_108 == V_109 )
V_6 -> V_90 |= V_110 ;
F_39 ( & V_74 -> V_87 , V_75 ) ;
return NULL ;
}
if ( V_6 -> type == V_84 && V_74 -> V_111 != NULL ) {
F_50 ( & V_74 -> V_87 ) ;
V_74 -> V_82 &= ~ V_92 ;
F_51 ( & V_74 -> V_87 ) ;
}
V_94 = F_45 ( & V_6 -> V_79 , struct V_65 ,
V_80 ) ;
F_39 ( & V_6 -> V_77 , V_75 ) ;
V_94 -> V_64 . V_82 = V_112 ;
return V_94 ;
}
void F_52 ( struct V_5 * V_6 )
{
unsigned long V_75 ;
F_36 ( & V_6 -> V_77 , V_75 ) ;
while ( ! F_40 ( & V_6 -> V_79 ) ) {
struct V_65 * V_94 ;
V_94 = F_45 ( & V_6 -> V_79 , struct V_65 ,
V_80 ) ;
F_46 ( & V_94 -> V_80 ) ;
F_38 ( & V_94 -> V_64 , V_78 ) ;
}
F_53 ( V_6 -> V_89 ) ;
V_6 -> error = true ;
F_39 ( & V_6 -> V_77 , V_75 ) ;
}
static int
F_54 ( struct V_113 * V_113 , void * V_114 , struct V_115 * V_116 )
{
struct V_5 * V_6 = F_55 ( V_113 ) ;
F_56 ( V_116 -> V_117 , V_118 , sizeof( V_116 -> V_117 ) ) ;
F_56 ( V_116 -> V_119 , V_6 -> V_6 . V_120 , sizeof( V_116 -> V_119 ) ) ;
F_56 ( V_116 -> V_121 , L_2 , sizeof( V_116 -> V_121 ) ) ;
if ( V_6 -> type == V_84 )
V_116 -> V_122 = V_123 | V_124 ;
else
V_116 -> V_122 = V_125 | V_124 ;
V_116 -> V_126 = V_127 | V_124
| V_123 | V_125 ;
return 0 ;
}
static int
F_57 ( struct V_113 * V_113 , void * V_114 , struct V_128 * V_129 )
{
struct V_5 * V_6 = F_55 ( V_113 ) ;
struct V_7 V_41 ;
unsigned int V_31 = V_129 -> V_31 ;
unsigned int V_3 ;
int V_45 ;
if ( V_129 -> type != V_6 -> type )
return - V_46 ;
V_45 = F_19 ( V_6 , & V_41 ) ;
if ( V_45 < 0 )
return V_45 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
const struct V_1 * V_130 = & V_4 [ V_3 ] ;
if ( V_41 . V_2 != V_130 -> V_2 )
continue;
if ( V_31 == 0 ) {
V_129 -> V_20 = V_130 -> V_20 ;
F_56 ( V_129 -> V_131 , V_130 -> V_131 ,
sizeof( V_129 -> V_131 ) ) ;
return 0 ;
}
V_31 -- ;
}
return - V_46 ;
}
static int
F_58 ( struct V_113 * V_113 , void * V_114 , struct V_56 * V_41 )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
struct V_5 * V_6 = F_55 ( V_113 ) ;
if ( V_41 -> type != V_6 -> type )
return - V_46 ;
F_13 ( & V_6 -> V_49 ) ;
* V_41 = V_52 -> V_41 ;
F_18 ( & V_6 -> V_49 ) ;
return 0 ;
}
static int
F_60 ( struct V_113 * V_113 , void * V_114 , struct V_56 * V_41 )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
struct V_5 * V_6 = F_55 ( V_113 ) ;
struct V_7 V_43 ;
if ( V_41 -> type != V_6 -> type )
return - V_46 ;
F_13 ( & V_6 -> V_49 ) ;
F_6 ( & V_41 -> V_43 . V_10 , & V_43 ) ;
F_3 ( V_6 , & V_43 , & V_41 -> V_43 . V_10 ) ;
V_52 -> V_41 = * V_41 ;
F_18 ( & V_6 -> V_49 ) ;
return 0 ;
}
static int
F_61 ( struct V_113 * V_113 , void * V_114 , struct V_56 * V_41 )
{
struct V_5 * V_6 = F_55 ( V_113 ) ;
struct V_42 V_43 ;
struct V_25 * V_44 ;
T_1 V_26 ;
int V_45 ;
if ( V_41 -> type != V_6 -> type )
return - V_46 ;
V_44 = F_8 ( V_6 , & V_26 ) ;
if ( V_44 == NULL )
return - V_46 ;
F_6 ( & V_41 -> V_43 . V_10 , & V_43 . V_41 ) ;
V_43 . V_26 = V_26 ;
V_43 . V_47 = V_48 ;
V_45 = F_20 ( V_44 , V_26 , V_50 , NULL , & V_43 ) ;
if ( V_45 )
return V_45 ;
F_3 ( V_6 , & V_43 . V_41 , & V_41 -> V_43 . V_10 ) ;
return 0 ;
}
static int
F_62 ( struct V_113 * V_113 , void * V_114 , struct V_132 * V_133 )
{
struct V_5 * V_6 = F_55 ( V_113 ) ;
struct V_25 * V_44 ;
int V_45 ;
V_44 = F_8 ( V_6 , NULL ) ;
if ( V_44 == NULL )
return - V_46 ;
F_13 ( & V_6 -> V_49 ) ;
V_45 = F_20 ( V_44 , V_6 , V_133 , V_133 ) ;
F_18 ( & V_6 -> V_49 ) ;
return V_45 == - V_134 ? - V_135 : V_45 ;
}
static int
F_63 ( struct V_113 * V_113 , void * V_114 , struct V_136 * V_137 )
{
struct V_5 * V_6 = F_55 ( V_113 ) ;
struct V_42 V_41 ;
struct V_25 * V_44 ;
T_1 V_26 ;
int V_45 ;
V_44 = F_8 ( V_6 , & V_26 ) ;
if ( V_44 == NULL )
return - V_46 ;
V_45 = F_20 ( V_44 , V_6 , V_138 , V_137 ) ;
if ( V_45 != - V_134 )
return V_45 ;
V_41 . V_26 = V_26 ;
V_41 . V_47 = V_48 ;
V_45 = F_20 ( V_44 , V_26 , V_50 , NULL , & V_41 ) ;
if ( V_45 < 0 )
return V_45 == - V_134 ? - V_135 : V_45 ;
V_137 -> V_139 . V_140 = 0 ;
V_137 -> V_139 . V_141 = 0 ;
V_137 -> V_139 . V_14 = V_41 . V_41 . V_14 ;
V_137 -> V_139 . V_15 = V_41 . V_41 . V_15 ;
return 0 ;
}
static int
F_64 ( struct V_113 * V_113 , void * V_114 , const struct V_136 * V_137 )
{
struct V_5 * V_6 = F_55 ( V_113 ) ;
struct V_25 * V_44 ;
int V_45 ;
V_44 = F_8 ( V_6 , NULL ) ;
if ( V_44 == NULL )
return - V_46 ;
F_13 ( & V_6 -> V_49 ) ;
V_45 = F_20 ( V_44 , V_6 , V_142 , V_137 ) ;
F_18 ( & V_6 -> V_49 ) ;
return V_45 == - V_134 ? - V_135 : V_45 ;
}
static int
F_65 ( struct V_113 * V_113 , void * V_114 , struct V_143 * V_144 )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
struct V_5 * V_6 = F_55 ( V_113 ) ;
if ( V_6 -> type != V_145 ||
V_6 -> type != V_144 -> type )
return - V_46 ;
memset ( V_144 , 0 , sizeof( * V_144 ) ) ;
V_144 -> type = V_145 ;
V_144 -> V_146 . V_103 . V_147 = V_148 ;
V_144 -> V_146 . V_103 . V_149 = V_52 -> V_149 ;
return 0 ;
}
static int
F_66 ( struct V_113 * V_113 , void * V_114 , struct V_143 * V_144 )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
struct V_5 * V_6 = F_55 ( V_113 ) ;
if ( V_6 -> type != V_145 ||
V_6 -> type != V_144 -> type )
return - V_46 ;
if ( V_144 -> V_146 . V_103 . V_149 . V_150 == 0 )
V_144 -> V_146 . V_103 . V_149 . V_150 = 1 ;
V_52 -> V_149 = V_144 -> V_146 . V_103 . V_149 ;
return 0 ;
}
static int
F_67 ( struct V_113 * V_113 , void * V_114 , struct V_151 * V_152 )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
return F_68 ( & V_52 -> V_89 , V_152 ) ;
}
static int
F_69 ( struct V_113 * V_113 , void * V_114 , struct V_153 * V_154 )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
return F_70 ( & V_52 -> V_89 , V_154 ) ;
}
static int
F_71 ( struct V_113 * V_113 , void * V_114 , struct V_153 * V_154 )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
return F_72 ( & V_52 -> V_89 , V_154 ) ;
}
static int
F_73 ( struct V_113 * V_113 , void * V_114 , struct V_153 * V_154 )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
return F_74 ( & V_52 -> V_89 , V_154 , V_113 -> V_155 & V_156 ) ;
}
static int
F_75 ( struct V_113 * V_113 , void * V_114 , enum V_157 type )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
struct V_5 * V_6 = F_55 ( V_113 ) ;
struct V_32 V_33 ;
struct V_34 * V_29 ;
enum V_81 V_82 ;
struct V_73 * V_74 ;
struct V_5 * V_38 ;
unsigned long V_75 ;
int V_45 ;
if ( type != V_6 -> type )
return - V_46 ;
F_13 ( & V_6 -> V_158 ) ;
V_74 = V_6 -> V_6 . V_29 . V_74
? F_35 ( & V_6 -> V_6 . V_29 ) : & V_6 -> V_74 ;
V_74 -> V_159 = NULL ;
V_74 -> V_160 = 0 ;
V_74 -> V_161 = 0 ;
V_74 -> V_162 = 0 ;
if ( V_6 -> V_71 -> V_163 -> V_164 )
V_6 -> V_71 -> V_163 -> V_164 ( V_6 -> V_71 , true ) ;
V_45 = F_76 ( & V_6 -> V_6 . V_29 , & V_74 -> V_74 ) ;
if ( V_45 < 0 )
goto V_165;
V_29 = & V_6 -> V_6 . V_29 ;
F_14 ( & V_33 , V_29 ) ;
while ( ( V_29 = F_15 ( & V_33 ) ) )
V_74 -> V_162 |= 1 << V_29 -> V_166 ;
V_45 = F_21 ( V_6 , V_52 ) ;
if ( V_45 < 0 )
goto V_167;
V_6 -> V_168 = V_45 ;
V_6 -> V_169 = V_52 -> V_41 . V_43 . V_10 . V_12 ;
V_38 = F_12 ( V_6 ) ;
if ( V_6 -> type == V_84 ) {
V_82 = V_170 | V_171 ;
V_74 -> V_111 = V_38 ;
V_74 -> V_103 = V_6 ;
} else {
if ( V_38 == NULL ) {
V_45 = - V_172 ;
goto V_167;
}
V_82 = V_173 | V_174 ;
V_74 -> V_111 = V_6 ;
V_74 -> V_103 = V_38 ;
}
F_36 ( & V_74 -> V_87 , V_75 ) ;
V_74 -> V_82 &= ~ V_92 ;
V_74 -> V_82 |= V_82 ;
F_39 ( & V_74 -> V_87 , V_75 ) ;
if ( V_6 -> type == V_145 )
V_74 -> V_175 = V_52 -> V_149 ;
V_6 -> V_89 = & V_52 -> V_89 ;
F_77 ( & V_6 -> V_79 ) ;
V_6 -> error = false ;
F_78 ( & V_74 -> V_106 , - 1 ) ;
V_45 = F_79 ( & V_52 -> V_89 , type ) ;
if ( V_45 < 0 )
goto V_167;
if ( V_74 -> V_111 == NULL ) {
unsigned long V_75 ;
V_45 = F_43 ( V_74 ,
V_109 ) ;
if ( V_45 < 0 )
goto V_176;
F_36 ( & V_6 -> V_77 , V_75 ) ;
if ( F_40 ( & V_6 -> V_79 ) )
V_6 -> V_90 |= V_110 ;
F_39 ( & V_6 -> V_77 , V_75 ) ;
}
F_18 ( & V_6 -> V_158 ) ;
return 0 ;
V_176:
F_80 ( & V_52 -> V_89 , type ) ;
V_167:
F_81 ( & V_6 -> V_6 . V_29 ) ;
V_165:
if ( V_6 -> V_71 -> V_163 -> V_164 )
V_6 -> V_71 -> V_163 -> V_164 ( V_6 -> V_71 , false ) ;
V_6 -> V_89 = NULL ;
F_18 ( & V_6 -> V_158 ) ;
return V_45 ;
}
static int
F_82 ( struct V_113 * V_113 , void * V_114 , enum V_157 type )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
struct V_5 * V_6 = F_55 ( V_113 ) ;
struct V_73 * V_74 = F_35 ( & V_6 -> V_6 . V_29 ) ;
enum V_81 V_82 ;
unsigned long V_75 ;
if ( type != V_6 -> type )
return - V_46 ;
F_13 ( & V_6 -> V_158 ) ;
if ( ! F_83 ( & V_52 -> V_89 ) )
goto V_177;
if ( V_6 -> type == V_84 )
V_82 = V_170
| V_85 ;
else
V_82 = V_173
| V_86 ;
F_36 ( & V_74 -> V_87 , V_75 ) ;
V_74 -> V_82 &= ~ V_82 ;
F_39 ( & V_74 -> V_87 , V_75 ) ;
F_43 ( V_74 , V_178 ) ;
F_80 ( & V_52 -> V_89 , type ) ;
V_6 -> V_89 = NULL ;
if ( V_6 -> V_71 -> V_163 -> V_164 )
V_6 -> V_71 -> V_163 -> V_164 ( V_6 -> V_71 , false ) ;
F_81 ( & V_6 -> V_6 . V_29 ) ;
V_177:
F_18 ( & V_6 -> V_158 ) ;
return 0 ;
}
static int
F_84 ( struct V_113 * V_113 , void * V_114 , struct V_179 * V_111 )
{
if ( V_111 -> V_31 > 0 )
return - V_46 ;
F_56 ( V_111 -> V_120 , L_3 , sizeof( V_111 -> V_120 ) ) ;
V_111 -> type = V_180 ;
return 0 ;
}
static int
F_85 ( struct V_113 * V_113 , void * V_114 , unsigned int * V_111 )
{
* V_111 = 0 ;
return 0 ;
}
static int
F_86 ( struct V_113 * V_113 , void * V_114 , unsigned int V_111 )
{
return V_111 == 0 ? 0 : - V_46 ;
}
static int F_87 ( struct V_113 * V_113 )
{
struct V_5 * V_6 = F_55 ( V_113 ) ;
struct V_51 * V_181 ;
struct V_54 * V_182 ;
int V_45 = 0 ;
V_181 = F_88 ( sizeof( * V_181 ) , V_183 ) ;
if ( V_181 == NULL )
return - V_184 ;
V_6 -> V_6 . V_185 = V_185 ;
F_89 ( & V_181 -> V_52 , & V_6 -> V_6 ) ;
F_90 ( & V_181 -> V_52 ) ;
if ( F_91 ( V_6 -> V_71 ) == NULL ) {
V_45 = - V_186 ;
goto V_177;
}
V_45 = F_92 ( & V_6 -> V_6 . V_29 , 1 ) ;
if ( V_45 < 0 ) {
F_93 ( V_6 -> V_71 ) ;
goto V_177;
}
V_6 -> V_61 = F_94 ( V_6 -> V_71 -> V_72 ) ;
if ( F_95 ( V_6 -> V_61 ) ) {
V_45 = F_96 ( V_6 -> V_61 ) ;
F_93 ( V_6 -> V_71 ) ;
goto V_177;
}
V_182 = & V_181 -> V_89 ;
V_182 -> type = V_6 -> type ;
V_182 -> V_187 = V_188 ;
V_182 -> V_189 = V_181 ;
V_182 -> V_88 = & V_190 ;
V_182 -> V_191 = & V_192 ;
V_182 -> V_193 = sizeof( struct V_65 ) ;
V_182 -> V_194 = V_195 ;
V_45 = F_97 ( V_182 ) ;
if ( V_45 ) {
F_93 ( V_6 -> V_71 ) ;
goto V_177;
}
memset ( & V_181 -> V_41 , 0 , sizeof( V_181 -> V_41 ) ) ;
V_181 -> V_41 . type = V_6 -> type ;
V_181 -> V_149 . V_150 = 1 ;
V_181 -> V_6 = V_6 ;
V_113 -> V_196 = & V_181 -> V_52 ;
V_177:
if ( V_45 < 0 ) {
F_98 ( & V_181 -> V_52 ) ;
F_99 ( V_181 ) ;
}
return V_45 ;
}
static int F_100 ( struct V_113 * V_113 )
{
struct V_5 * V_6 = F_55 ( V_113 ) ;
struct V_197 * V_52 = V_113 -> V_196 ;
struct V_51 * V_181 = F_59 ( V_52 ) ;
F_82 ( V_113 , V_52 , V_6 -> type ) ;
F_92 ( & V_6 -> V_6 . V_29 , 0 ) ;
F_101 ( & V_181 -> V_89 ) ;
F_98 ( V_52 ) ;
F_99 ( V_181 ) ;
V_113 -> V_196 = NULL ;
F_93 ( V_6 -> V_71 ) ;
return 0 ;
}
static unsigned int F_102 ( struct V_113 * V_113 , T_3 * V_198 )
{
struct V_51 * V_52 = F_59 ( V_113 -> V_196 ) ;
return F_103 ( & V_52 -> V_89 , V_113 , V_198 ) ;
}
static int F_104 ( struct V_113 * V_113 , struct V_199 * V_200 )
{
struct V_51 * V_52 = F_59 ( V_113 -> V_196 ) ;
return F_105 ( & V_52 -> V_89 , V_200 ) ;
}
int F_106 ( struct V_5 * V_6 , const char * V_120 )
{
const char * V_201 ;
int V_45 ;
switch ( V_6 -> type ) {
case V_84 :
V_201 = L_4 ;
V_6 -> V_26 . V_75 = V_202 ;
break;
case V_145 :
V_201 = L_5 ;
V_6 -> V_26 . V_75 = V_203 ;
break;
default:
return - V_46 ;
}
V_45 = F_107 ( & V_6 -> V_6 . V_29 , 1 , & V_6 -> V_26 , 0 ) ;
if ( V_45 < 0 )
return V_45 ;
F_108 ( & V_6 -> V_77 ) ;
F_109 ( & V_6 -> V_49 ) ;
F_78 ( & V_6 -> V_204 , 0 ) ;
F_108 ( & V_6 -> V_74 . V_87 ) ;
F_109 ( & V_6 -> V_158 ) ;
if ( V_6 -> V_88 == NULL )
V_6 -> V_88 = & V_205 ;
V_6 -> V_6 . V_206 = & V_207 ;
snprintf ( V_6 -> V_6 . V_120 , sizeof( V_6 -> V_6 . V_120 ) ,
L_6 , V_120 , V_201 ) ;
V_6 -> V_6 . V_208 = V_209 ;
V_6 -> V_6 . V_210 = V_211 ;
V_6 -> V_6 . V_212 = & V_213 ;
V_6 -> V_74 . V_108 = V_178 ;
F_110 ( & V_6 -> V_6 , V_6 ) ;
return 0 ;
}
void F_111 ( struct V_5 * V_6 )
{
F_112 ( & V_6 -> V_6 . V_29 ) ;
F_113 ( & V_6 -> V_158 ) ;
F_113 ( & V_6 -> V_49 ) ;
}
int F_114 ( struct V_5 * V_6 , struct V_214 * V_215 )
{
int V_45 ;
V_6 -> V_6 . V_216 = V_215 ;
V_45 = F_115 ( & V_6 -> V_6 , V_209 , - 1 ) ;
if ( V_45 < 0 )
F_116 ( V_6 -> V_71 -> V_72 ,
L_7 ,
V_217 , V_45 ) ;
return V_45 ;
}
void F_117 ( struct V_5 * V_6 )
{
F_118 ( & V_6 -> V_6 ) ;
}
