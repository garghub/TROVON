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
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) - 1 ; ++ V_3 ) {
if ( V_4 [ V_3 ] . V_20 == V_10 -> V_20 )
break;
}
V_8 -> V_2 = V_4 [ V_3 ] . V_2 ;
V_8 -> V_22 = V_10 -> V_22 ;
V_8 -> V_23 = V_10 -> V_23 ;
}
static struct V_25 *
F_7 ( struct V_5 * V_6 , T_1 * V_26 )
{
struct V_27 * V_28 ;
V_28 = F_8 ( & V_6 -> V_26 ) ;
if ( ! V_28 ||
F_9 ( V_28 -> V_29 ) != V_30 )
return NULL ;
if ( V_26 )
* V_26 = V_28 -> V_31 ;
return F_10 ( V_28 -> V_29 ) ;
}
static struct V_5 *
F_11 ( struct V_5 * V_6 )
{
struct V_32 V_33 ;
struct V_34 * V_29 = & V_6 -> V_6 . V_29 ;
struct V_35 * V_36 = V_29 -> V_37 ;
struct V_5 * V_38 = NULL ;
F_12 ( & V_36 -> V_39 ) ;
F_13 ( & V_33 , V_29 ) ;
while ( ( V_29 = F_14 ( & V_33 ) ) ) {
if ( V_29 == & V_6 -> V_6 . V_29 )
continue;
if ( F_9 ( V_29 ) != V_40 )
continue;
V_38 = F_15 ( F_16 ( V_29 ) ) ;
if ( V_38 -> type != V_6 -> type )
break;
V_38 = NULL ;
}
F_17 ( & V_36 -> V_39 ) ;
return V_38 ;
}
static int
F_18 ( struct V_5 * V_6 ,
struct V_7 * V_41 )
{
struct V_42 V_43 ;
struct V_25 * V_44 ;
T_1 V_26 ;
int V_45 ;
V_44 = F_7 ( V_6 , & V_26 ) ;
if ( ! V_44 )
return - V_46 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_26 = V_26 ;
V_43 . V_47 = V_48 ;
F_12 ( & V_6 -> V_49 ) ;
V_45 = F_19 ( V_44 , V_26 , V_50 , NULL , & V_43 ) ;
F_17 ( & V_6 -> V_49 ) ;
if ( V_45 )
return V_45 ;
* V_41 = V_43 . V_41 ;
return 0 ;
}
static int
F_20 ( struct V_5 * V_6 , struct V_51 * V_52 )
{
struct V_7 V_41 ;
struct V_9 V_53 ;
int V_45 ;
V_45 = F_18 ( V_6 , & V_41 ) ;
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
static int F_21 ( struct V_54 * V_55 ,
const void * V_56 ,
unsigned int * V_57 , unsigned int * V_58 ,
unsigned int V_59 [] , void * V_60 [] )
{
struct V_51 * V_52 = F_22 ( V_55 ) ;
struct V_5 * V_6 = V_52 -> V_6 ;
* V_58 = 1 ;
V_59 [ 0 ] = V_52 -> V_41 . V_43 . V_10 . V_21 ;
if ( V_59 [ 0 ] == 0 )
return - V_46 ;
V_60 [ 0 ] = V_6 -> V_61 ;
* V_57 = F_23 ( * V_57 , V_6 -> V_62 / F_24 ( V_59 [ 0 ] ) ) ;
return 0 ;
}
static void F_25 ( struct V_63 * V_64 )
{
struct V_65 * V_66 = F_26 ( V_64 ) ;
struct V_67 * V_68 = F_27 ( V_66 , struct V_67 , V_64 ) ;
if ( V_68 -> V_69 )
V_68 -> V_69 = 0 ;
}
static int F_28 ( struct V_63 * V_64 )
{
struct V_65 * V_66 = F_26 ( V_64 ) ;
struct V_51 * V_52 = F_22 ( V_64 -> V_54 ) ;
struct V_67 * V_68 = F_27 ( V_66 , struct V_67 , V_64 ) ;
struct V_5 * V_6 = V_52 -> V_6 ;
unsigned long V_70 = V_52 -> V_41 . V_43 . V_10 . V_21 ;
T_2 V_71 ;
if ( F_29 ( V_64 , 0 ) < V_70 )
return - V_72 ;
V_71 = F_30 ( V_64 , 0 ) ;
if ( ! F_31 ( V_71 , 32 ) ) {
F_32 ( V_6 -> V_73 -> V_74 ,
L_1 ) ;
return - V_46 ;
}
F_33 ( V_64 , 0 , V_70 ) ;
V_68 -> V_69 = V_71 ;
return 0 ;
}
static void F_34 ( struct V_63 * V_64 )
{
struct V_65 * V_66 = F_26 ( V_64 ) ;
struct V_51 * V_52 = F_22 ( V_64 -> V_54 ) ;
struct V_5 * V_6 = V_52 -> V_6 ;
struct V_67 * V_68 = F_27 ( V_66 , struct V_67 , V_64 ) ;
struct V_75 * V_76 = F_35 ( & V_6 -> V_6 . V_29 ) ;
unsigned long V_77 ;
bool V_78 ;
F_36 ( & V_6 -> V_79 , V_77 ) ;
if ( F_37 ( V_6 -> error ) ) {
F_38 ( V_64 , V_80 ) ;
F_39 ( & V_6 -> V_79 , V_77 ) ;
return;
}
V_78 = F_40 ( & V_6 -> V_81 ) ;
F_41 ( & V_68 -> V_82 , & V_6 -> V_81 ) ;
F_39 ( & V_6 -> V_79 , V_77 ) ;
if ( V_78 ) {
enum V_83 V_84 ;
unsigned int V_85 ;
if ( V_6 -> type == V_86 )
V_84 = V_87 ;
else
V_84 = V_88 ;
F_36 ( & V_76 -> V_89 , V_77 ) ;
V_76 -> V_84 |= V_84 ;
V_6 -> V_90 -> V_91 ( V_6 , V_68 ) ;
V_6 -> V_92 |= V_93 ;
V_85 = F_42 ( V_76 ) ;
if ( V_85 )
V_76 -> V_84 |= V_94 ;
F_39 ( & V_76 -> V_89 , V_77 ) ;
if ( V_85 )
F_43 ( V_76 ,
V_95 ) ;
}
}
struct V_67 * F_44 ( struct V_5 * V_6 )
{
struct V_75 * V_76 = F_35 ( & V_6 -> V_6 . V_29 ) ;
enum V_83 V_84 ;
struct V_67 * V_96 ;
unsigned long V_77 ;
F_36 ( & V_6 -> V_79 , V_77 ) ;
if ( F_45 ( F_40 ( & V_6 -> V_81 ) ) ) {
F_39 ( & V_6 -> V_79 , V_77 ) ;
return NULL ;
}
V_96 = F_46 ( & V_6 -> V_81 , struct V_67 ,
V_82 ) ;
F_47 ( & V_96 -> V_82 ) ;
F_39 ( & V_6 -> V_79 , V_77 ) ;
F_48 ( & V_96 -> V_64 . V_97 ) ;
if ( V_6 == V_76 -> V_98 && ! V_76 -> V_99 )
V_96 -> V_64 . V_100 =
F_49 ( & V_76 -> V_101 ) ;
else
V_96 -> V_64 . V_100 = F_50 ( & V_76 -> V_101 ) ;
F_38 ( & V_96 -> V_64 . V_102 , V_76 -> error ?
V_80 : V_103 ) ;
V_76 -> error = false ;
F_36 ( & V_6 -> V_79 , V_77 ) ;
if ( F_40 ( & V_6 -> V_81 ) ) {
F_39 ( & V_6 -> V_79 , V_77 ) ;
if ( V_6 -> type == V_86 )
V_84 = V_87
| V_94 ;
else
V_84 = V_88
| V_94 ;
F_36 ( & V_76 -> V_89 , V_77 ) ;
V_76 -> V_84 &= ~ V_84 ;
if ( V_6 -> V_76 . V_104 == V_105 )
V_6 -> V_92 |= V_106 ;
F_39 ( & V_76 -> V_89 , V_77 ) ;
return NULL ;
}
if ( V_6 -> type == V_86 && V_76 -> V_107 ) {
F_51 ( & V_76 -> V_89 ) ;
V_76 -> V_84 &= ~ V_94 ;
F_52 ( & V_76 -> V_89 ) ;
}
V_96 = F_46 ( & V_6 -> V_81 , struct V_67 ,
V_82 ) ;
F_39 ( & V_6 -> V_79 , V_77 ) ;
V_96 -> V_64 . V_102 . V_84 = V_108 ;
return V_96 ;
}
void F_53 ( struct V_5 * V_6 )
{
unsigned long V_77 ;
F_36 ( & V_6 -> V_79 , V_77 ) ;
while ( ! F_40 ( & V_6 -> V_81 ) ) {
struct V_67 * V_96 ;
V_96 = F_46 ( & V_6 -> V_81 , struct V_67 ,
V_82 ) ;
F_47 ( & V_96 -> V_82 ) ;
F_38 ( & V_96 -> V_64 . V_102 , V_80 ) ;
}
F_54 ( V_6 -> V_91 ) ;
V_6 -> error = true ;
F_39 ( & V_6 -> V_79 , V_77 ) ;
}
static int
F_55 ( struct V_109 * V_109 , void * V_110 , struct V_111 * V_112 )
{
struct V_5 * V_6 = F_56 ( V_109 ) ;
F_57 ( V_112 -> V_113 , V_114 , sizeof( V_112 -> V_113 ) ) ;
F_57 ( V_112 -> V_115 , V_6 -> V_6 . V_116 , sizeof( V_112 -> V_115 ) ) ;
F_57 ( V_112 -> V_117 , L_2 , sizeof( V_112 -> V_117 ) ) ;
if ( V_6 -> type == V_86 )
V_112 -> V_118 = V_119 | V_120 ;
else
V_112 -> V_118 = V_121 | V_120 ;
V_112 -> V_122 = V_123 | V_120
| V_119 | V_121 ;
return 0 ;
}
static int
F_58 ( struct V_109 * V_109 , void * V_110 , struct V_124 * V_125 )
{
struct V_5 * V_6 = F_56 ( V_109 ) ;
struct V_7 V_41 ;
unsigned int V_31 = V_125 -> V_31 ;
unsigned int V_3 ;
int V_45 ;
if ( V_125 -> type != V_6 -> type )
return - V_46 ;
V_45 = F_18 ( V_6 , & V_41 ) ;
if ( V_45 < 0 )
return V_45 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
const struct V_1 * V_126 = & V_4 [ V_3 ] ;
if ( V_41 . V_2 != V_126 -> V_2 )
continue;
if ( V_31 == 0 ) {
V_125 -> V_20 = V_126 -> V_20 ;
F_57 ( V_125 -> V_127 , V_126 -> V_127 ,
sizeof( V_125 -> V_127 ) ) ;
return 0 ;
}
V_31 -- ;
}
return - V_46 ;
}
static int
F_59 ( struct V_109 * V_109 , void * V_110 , struct V_128 * V_41 )
{
struct V_51 * V_52 = F_60 ( V_110 ) ;
struct V_5 * V_6 = F_56 ( V_109 ) ;
if ( V_41 -> type != V_6 -> type )
return - V_46 ;
F_12 ( & V_6 -> V_49 ) ;
* V_41 = V_52 -> V_41 ;
F_17 ( & V_6 -> V_49 ) ;
return 0 ;
}
static int
F_61 ( struct V_109 * V_109 , void * V_110 , struct V_128 * V_41 )
{
struct V_51 * V_52 = F_60 ( V_110 ) ;
struct V_5 * V_6 = F_56 ( V_109 ) ;
struct V_7 V_43 ;
if ( V_41 -> type != V_6 -> type )
return - V_46 ;
F_12 ( & V_6 -> V_49 ) ;
F_6 ( & V_41 -> V_43 . V_10 , & V_43 ) ;
F_3 ( V_6 , & V_43 , & V_41 -> V_43 . V_10 ) ;
V_52 -> V_41 = * V_41 ;
F_17 ( & V_6 -> V_49 ) ;
return 0 ;
}
static int
F_62 ( struct V_109 * V_109 , void * V_110 , struct V_128 * V_41 )
{
struct V_5 * V_6 = F_56 ( V_109 ) ;
struct V_42 V_43 ;
struct V_25 * V_44 ;
T_1 V_26 ;
int V_45 ;
if ( V_41 -> type != V_6 -> type )
return - V_46 ;
V_44 = F_7 ( V_6 , & V_26 ) ;
if ( ! V_44 )
return - V_46 ;
F_6 ( & V_41 -> V_43 . V_10 , & V_43 . V_41 ) ;
V_43 . V_26 = V_26 ;
V_43 . V_47 = V_48 ;
V_45 = F_19 ( V_44 , V_26 , V_50 , NULL , & V_43 ) ;
if ( V_45 )
return V_45 ;
F_3 ( V_6 , & V_43 . V_41 , & V_41 -> V_43 . V_10 ) ;
return 0 ;
}
static int
F_63 ( struct V_109 * V_109 , void * V_110 , struct V_129 * V_130 )
{
struct V_51 * V_52 = F_60 ( V_110 ) ;
struct V_5 * V_6 = F_56 ( V_109 ) ;
if ( V_6 -> type != V_131 ||
V_6 -> type != V_130 -> type )
return - V_46 ;
memset ( V_130 , 0 , sizeof( * V_130 ) ) ;
V_130 -> type = V_131 ;
V_130 -> V_132 . V_98 . V_133 = V_134 ;
V_130 -> V_132 . V_98 . V_135 = V_52 -> V_135 ;
return 0 ;
}
static int
F_64 ( struct V_109 * V_109 , void * V_110 , struct V_129 * V_130 )
{
struct V_51 * V_52 = F_60 ( V_110 ) ;
struct V_5 * V_6 = F_56 ( V_109 ) ;
if ( V_6 -> type != V_131 ||
V_6 -> type != V_130 -> type )
return - V_46 ;
if ( V_130 -> V_132 . V_98 . V_135 . V_136 == 0 )
V_130 -> V_132 . V_98 . V_135 . V_136 = 1 ;
V_52 -> V_135 = V_130 -> V_132 . V_98 . V_135 ;
return 0 ;
}
static int
F_65 ( struct V_109 * V_109 , void * V_110 , struct V_137 * V_138 )
{
struct V_51 * V_52 = F_60 ( V_110 ) ;
return F_66 ( & V_52 -> V_91 , V_138 ) ;
}
static int
F_67 ( struct V_109 * V_109 , void * V_110 , struct V_139 * V_140 )
{
struct V_51 * V_52 = F_60 ( V_110 ) ;
return F_68 ( & V_52 -> V_91 , V_140 ) ;
}
static int
F_69 ( struct V_109 * V_109 , void * V_110 , struct V_139 * V_140 )
{
struct V_51 * V_52 = F_60 ( V_110 ) ;
return F_70 ( & V_52 -> V_91 , V_140 ) ;
}
static int
F_71 ( struct V_109 * V_109 , void * V_110 , struct V_141 * V_142 )
{
struct V_51 * V_52 = F_60 ( V_110 ) ;
return F_72 ( & V_52 -> V_91 , V_142 ) ;
}
static int
F_73 ( struct V_109 * V_109 , void * V_110 , struct V_139 * V_140 )
{
struct V_51 * V_52 = F_60 ( V_110 ) ;
return F_74 ( & V_52 -> V_91 , V_140 , V_109 -> V_143 & V_144 ) ;
}
static int
F_75 ( struct V_109 * V_109 , void * V_110 , enum V_145 type )
{
struct V_51 * V_52 = F_60 ( V_110 ) ;
struct V_5 * V_6 = F_56 ( V_109 ) ;
struct V_32 V_33 ;
struct V_34 * V_29 ;
enum V_83 V_84 ;
struct V_75 * V_76 ;
struct V_5 * V_38 ;
unsigned long V_77 ;
int V_45 ;
if ( type != V_6 -> type )
return - V_46 ;
F_12 ( & V_6 -> V_146 ) ;
V_76 = V_6 -> V_6 . V_29 . V_76
? F_35 ( & V_6 -> V_6 . V_29 ) : & V_6 -> V_76 ;
V_76 -> V_147 = NULL ;
V_76 -> V_148 = 0 ;
V_76 -> V_149 = 0 ;
V_76 -> V_150 = 0 ;
if ( V_6 -> V_73 -> V_151 -> V_152 )
V_6 -> V_73 -> V_151 -> V_152 ( V_6 -> V_73 , true ) ;
V_45 = F_76 ( & V_6 -> V_6 . V_29 , & V_76 -> V_76 ) ;
if ( V_45 < 0 )
goto V_153;
V_29 = & V_6 -> V_6 . V_29 ;
F_13 ( & V_33 , V_29 ) ;
while ( ( V_29 = F_14 ( & V_33 ) ) )
V_76 -> V_150 |= 1 << V_29 -> V_154 ;
V_45 = F_20 ( V_6 , V_52 ) ;
if ( V_45 < 0 )
goto V_155;
V_6 -> V_156 = V_45 ;
V_6 -> V_157 = V_52 -> V_41 . V_43 . V_10 . V_12 ;
V_38 = F_11 ( V_6 ) ;
if ( V_6 -> type == V_86 ) {
V_84 = V_158 | V_159 ;
V_76 -> V_107 = V_38 ;
V_76 -> V_98 = V_6 ;
} else {
if ( ! V_38 ) {
V_45 = - V_160 ;
goto V_155;
}
V_84 = V_161 | V_162 ;
V_76 -> V_107 = V_6 ;
V_76 -> V_98 = V_38 ;
}
F_36 ( & V_76 -> V_89 , V_77 ) ;
V_76 -> V_84 &= ~ V_94 ;
V_76 -> V_84 |= V_84 ;
F_39 ( & V_76 -> V_89 , V_77 ) ;
if ( V_6 -> type == V_131 )
V_76 -> V_163 = V_52 -> V_135 ;
V_6 -> V_91 = & V_52 -> V_91 ;
F_77 ( & V_6 -> V_81 ) ;
V_6 -> error = false ;
F_78 ( & V_76 -> V_101 , - 1 ) ;
V_45 = F_79 ( & V_52 -> V_91 , type ) ;
if ( V_45 < 0 )
goto V_155;
if ( ! V_76 -> V_107 ) {
unsigned long V_77 ;
V_45 = F_43 ( V_76 ,
V_105 ) ;
if ( V_45 < 0 )
goto V_164;
F_36 ( & V_6 -> V_79 , V_77 ) ;
if ( F_40 ( & V_6 -> V_81 ) )
V_6 -> V_92 |= V_106 ;
F_39 ( & V_6 -> V_79 , V_77 ) ;
}
F_17 ( & V_6 -> V_146 ) ;
return 0 ;
V_164:
F_80 ( & V_52 -> V_91 , type ) ;
V_155:
F_81 ( & V_6 -> V_6 . V_29 ) ;
V_153:
if ( V_6 -> V_73 -> V_151 -> V_152 )
V_6 -> V_73 -> V_151 -> V_152 ( V_6 -> V_73 , false ) ;
V_6 -> V_91 = NULL ;
F_17 ( & V_6 -> V_146 ) ;
return V_45 ;
}
static int
F_82 ( struct V_109 * V_109 , void * V_110 , enum V_145 type )
{
struct V_51 * V_52 = F_60 ( V_110 ) ;
struct V_5 * V_6 = F_56 ( V_109 ) ;
struct V_75 * V_76 = F_35 ( & V_6 -> V_6 . V_29 ) ;
enum V_83 V_84 ;
unsigned long V_77 ;
if ( type != V_6 -> type )
return - V_46 ;
F_12 ( & V_6 -> V_146 ) ;
if ( ! F_83 ( & V_52 -> V_91 ) )
goto V_165;
if ( V_6 -> type == V_86 )
V_84 = V_158
| V_87 ;
else
V_84 = V_161
| V_88 ;
F_36 ( & V_76 -> V_89 , V_77 ) ;
V_76 -> V_84 &= ~ V_84 ;
F_39 ( & V_76 -> V_89 , V_77 ) ;
F_43 ( V_76 , V_166 ) ;
F_80 ( & V_52 -> V_91 , type ) ;
V_6 -> V_91 = NULL ;
if ( V_6 -> V_73 -> V_151 -> V_152 )
V_6 -> V_73 -> V_151 -> V_152 ( V_6 -> V_73 , false ) ;
F_81 ( & V_6 -> V_6 . V_29 ) ;
V_165:
F_17 ( & V_6 -> V_146 ) ;
return 0 ;
}
static int
F_84 ( struct V_109 * V_109 , void * V_110 , struct V_167 * V_107 )
{
if ( V_107 -> V_31 > 0 )
return - V_46 ;
F_57 ( V_107 -> V_116 , L_3 , sizeof( V_107 -> V_116 ) ) ;
V_107 -> type = V_168 ;
return 0 ;
}
static int
F_85 ( struct V_109 * V_109 , void * V_110 , unsigned int * V_107 )
{
* V_107 = 0 ;
return 0 ;
}
static int
F_86 ( struct V_109 * V_109 , void * V_110 , unsigned int V_107 )
{
return V_107 == 0 ? 0 : - V_46 ;
}
static int F_87 ( struct V_109 * V_109 )
{
struct V_5 * V_6 = F_56 ( V_109 ) ;
struct V_51 * V_169 ;
struct V_54 * V_170 ;
int V_45 = 0 ;
V_169 = F_88 ( sizeof( * V_169 ) , V_171 ) ;
if ( ! V_169 )
return - V_172 ;
F_89 ( & V_169 -> V_52 , & V_6 -> V_6 ) ;
F_90 ( & V_169 -> V_52 ) ;
if ( ! F_91 ( V_6 -> V_73 ) ) {
V_45 = - V_173 ;
goto V_165;
}
V_45 = F_92 ( & V_6 -> V_6 . V_29 , 1 ) ;
if ( V_45 < 0 ) {
F_93 ( V_6 -> V_73 ) ;
goto V_165;
}
V_6 -> V_61 = F_94 ( V_6 -> V_73 -> V_74 ) ;
if ( F_95 ( V_6 -> V_61 ) ) {
V_45 = F_96 ( V_6 -> V_61 ) ;
F_93 ( V_6 -> V_73 ) ;
goto V_165;
}
V_170 = & V_169 -> V_91 ;
V_170 -> type = V_6 -> type ;
V_170 -> V_174 = V_175 | V_176 ;
V_170 -> V_177 = V_169 ;
V_170 -> V_90 = & V_178 ;
V_170 -> V_179 = & V_180 ;
V_170 -> V_181 = sizeof( struct V_67 ) ;
V_170 -> V_182 = V_183 ;
V_45 = F_97 ( V_170 ) ;
if ( V_45 ) {
F_93 ( V_6 -> V_73 ) ;
goto V_165;
}
memset ( & V_169 -> V_41 , 0 , sizeof( V_169 -> V_41 ) ) ;
V_169 -> V_41 . type = V_6 -> type ;
V_169 -> V_135 . V_136 = 1 ;
V_169 -> V_6 = V_6 ;
V_109 -> V_184 = & V_169 -> V_52 ;
V_165:
if ( V_45 < 0 ) {
F_98 ( & V_169 -> V_52 ) ;
F_99 ( V_169 ) ;
}
return V_45 ;
}
static int F_100 ( struct V_109 * V_109 )
{
struct V_5 * V_6 = F_56 ( V_109 ) ;
struct V_185 * V_52 = V_109 -> V_184 ;
struct V_51 * V_169 = F_60 ( V_52 ) ;
F_82 ( V_109 , V_52 , V_6 -> type ) ;
F_92 ( & V_6 -> V_6 . V_29 , 0 ) ;
F_101 ( & V_169 -> V_91 ) ;
F_98 ( V_52 ) ;
F_99 ( V_169 ) ;
V_109 -> V_184 = NULL ;
F_93 ( V_6 -> V_73 ) ;
return 0 ;
}
static unsigned int F_102 ( struct V_109 * V_109 , T_3 * V_186 )
{
struct V_51 * V_52 = F_60 ( V_109 -> V_184 ) ;
return F_103 ( & V_52 -> V_91 , V_109 , V_186 ) ;
}
static int F_104 ( struct V_109 * V_109 , struct V_187 * V_188 )
{
struct V_51 * V_52 = F_60 ( V_109 -> V_184 ) ;
return F_105 ( & V_52 -> V_91 , V_188 ) ;
}
int F_106 ( struct V_5 * V_6 , const char * V_116 )
{
const char * V_189 ;
int V_45 ;
switch ( V_6 -> type ) {
case V_86 :
V_189 = L_4 ;
V_6 -> V_26 . V_77 = V_190 ;
break;
case V_131 :
V_189 = L_5 ;
V_6 -> V_26 . V_77 = V_191 ;
break;
default:
return - V_46 ;
}
V_45 = F_107 ( & V_6 -> V_6 . V_29 , 1 , & V_6 -> V_26 , 0 ) ;
if ( V_45 < 0 )
return V_45 ;
F_108 ( & V_6 -> V_79 ) ;
F_109 ( & V_6 -> V_49 ) ;
F_78 ( & V_6 -> V_192 , 0 ) ;
F_108 ( & V_6 -> V_76 . V_89 ) ;
F_109 ( & V_6 -> V_146 ) ;
if ( ! V_6 -> V_90 )
V_6 -> V_90 = & V_193 ;
V_6 -> V_6 . V_194 = & V_195 ;
snprintf ( V_6 -> V_6 . V_116 , sizeof( V_6 -> V_6 . V_116 ) ,
L_6 , V_116 , V_189 ) ;
V_6 -> V_6 . V_196 = V_197 ;
V_6 -> V_6 . V_198 = V_199 ;
V_6 -> V_6 . V_200 = & V_201 ;
V_6 -> V_76 . V_104 = V_166 ;
F_110 ( & V_6 -> V_6 , V_6 ) ;
return 0 ;
}
void F_111 ( struct V_5 * V_6 )
{
F_112 ( & V_6 -> V_6 . V_29 ) ;
F_113 ( & V_6 -> V_146 ) ;
F_113 ( & V_6 -> V_49 ) ;
}
int F_114 ( struct V_5 * V_6 , struct V_202 * V_203 )
{
int V_45 ;
V_6 -> V_6 . V_204 = V_203 ;
V_45 = F_115 ( & V_6 -> V_6 , V_197 , - 1 ) ;
if ( V_45 < 0 )
F_116 ( V_6 -> V_73 -> V_74 ,
L_7 , V_45 ) ;
return V_45 ;
}
void F_117 ( struct V_5 * V_6 )
{
F_118 ( & V_6 -> V_6 ) ;
}
