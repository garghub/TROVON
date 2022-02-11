static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 && V_2 -> V_4 ;
}
static void F_2 ( struct V_5 * V_6 , unsigned V_7 )
{
if ( V_6 -> V_8 &&
V_7 > V_6 -> V_8 -> V_7 ) {
F_3 ( V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
}
if ( ! V_6 -> V_8 ) {
V_6 -> V_8 = F_4 (
sizeof( struct V_9 ) +
sizeof( struct V_1 ) * V_7 , V_10 ) ;
if ( ! V_6 -> V_8 ) {
F_5 ( V_6 ,
L_1 ,
V_11 , V_7 ) ;
return;
}
}
V_6 -> V_8 -> V_7 = V_7 ;
}
static int F_6 ( struct V_5 * V_6 )
{
int V_12 ;
int V_13 ;
T_1 V_14 ;
int V_15 = V_16 ;
V_13 = V_6 -> V_17 -> V_8 . V_7 ;
V_14 = F_7 ( 0 , ( const V_18 * ) & V_6 -> V_17 -> V_8 ,
sizeof( V_6 -> V_17 -> V_8 ) ) ;
if ( V_14 != V_6 -> V_17 -> V_19 ) {
F_5 ( V_6 , L_2 , V_14 ,
sizeof( V_6 -> V_17 -> V_8 ) ,
V_6 -> V_17 -> V_19 ) ;
return V_20 ;
}
if ( ! V_13 ) {
F_8 ( L_3 ) ;
return V_15 ;
}
if ( V_13 > V_6 -> V_21 -> V_22 ) {
F_8 ( L_4 ,
V_6 -> V_21 -> V_22 , V_13 ) ;
V_13 = V_6 -> V_21 -> V_22 ;
} else {
V_13 = V_6 -> V_17 -> V_8 . V_7 ;
}
if ( V_6 -> V_8
&& ( V_13 != V_6 -> V_8 -> V_7 ) ) {
V_15 = V_23 ;
}
F_2 ( V_6 , V_13 ) ;
V_6 -> V_8 -> V_22 =
V_6 -> V_21 -> V_22 ;
for ( V_12 = 0 ; V_12 < V_6 -> V_8 -> V_7 ; ++ V_12 ) {
struct V_24 * V_25 =
& V_6 -> V_17 -> V_8 . V_26 [ V_12 ] ;
struct V_1 * V_27 =
& V_6 -> V_8 -> V_26 [ V_12 ] ;
if ( V_27 -> V_28 != V_25 -> V_29 ) {
V_27 -> V_28 = V_25 -> V_29 ;
V_15 = V_23 ;
}
if ( V_27 -> V_30 != V_25 -> V_31 ) {
V_27 -> V_30 = V_25 -> V_31 ;
V_15 = V_23 ;
}
if ( V_27 -> V_3 != V_25 -> V_32 - V_25 -> V_29 ) {
V_27 -> V_3 = V_25 -> V_32 - V_25 -> V_29 ;
V_15 = V_23 ;
}
if ( V_27 -> V_4 != V_25 -> V_33 - V_25 -> V_31 ) {
V_27 -> V_4 = V_25 -> V_33 - V_25 -> V_31 ;
V_15 = V_23 ;
}
if ( V_27 -> V_34 != 0 ) {
V_27 -> V_34 = 0 ;
V_15 = V_23 ;
}
if ( V_27 -> V_35 != V_12 ) {
V_27 -> V_35 = V_12 ;
V_15 = V_23 ;
}
if ( V_27 -> V_36 != 0 ) {
V_27 -> V_36 = 0 ;
V_15 = V_23 ;
}
F_8 ( L_5 , V_27 -> V_3 , V_27 -> V_4 ,
V_27 -> V_28 , V_27 -> V_30 ) ;
}
return V_15 ;
}
static void F_9 ( struct V_5 * V_6 )
{
struct V_37 * V_38 = & V_6 -> V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_1 * V_2 ;
F_10 (connector, &dev->mode_config.connector_list, head) {
V_43 = F_11 ( V_41 ) ;
V_2 = & V_6 -> V_8 -> V_26 [ V_43 -> V_44 ] ;
F_12 ( & V_41 -> V_45 ,
V_38 -> V_46 . V_47 , V_2 -> V_28 ) ;
F_12 ( & V_41 -> V_45 ,
V_38 -> V_46 . V_48 , V_2 -> V_30 ) ;
}
}
void F_13 ( struct V_5 * V_6 )
{
struct V_37 * V_38 = & V_6 -> V_39 ;
int V_15 , V_49 ;
for ( V_49 = 0 ; V_49 < 10 ; V_49 ++ ) {
V_15 = F_6 ( V_6 ) ;
if ( V_15 != V_20 )
break;
F_14 ( 5 ) ;
}
if ( V_15 == V_20 ) {
F_5 ( V_6 , L_6 ) ;
F_8 ( L_7 ) ;
return;
}
if ( V_15 == V_16 ) {
F_5 ( V_6 , L_8 ) ;
F_8 ( L_9 ) ;
return;
}
F_15 ( V_38 ) ;
F_9 ( V_6 ) ;
F_16 ( V_38 ) ;
if ( ! F_17 ( V_38 ) ) {
F_18 ( V_38 ) ;
}
}
static int F_19 ( struct V_40 * V_41 ,
unsigned * V_50 ,
unsigned * V_51 )
{
struct V_37 * V_38 = V_41 -> V_38 ;
struct V_5 * V_6 = V_38 -> V_52 ;
struct V_42 * V_43 = F_11 ( V_41 ) ;
int V_53 = V_43 -> V_44 ;
struct V_54 * V_55 = NULL ;
struct V_1 * V_2 ;
if ( ! V_6 -> V_21 )
return 0 ;
if ( V_53 >= V_6 -> V_21 -> V_22 )
return 0 ;
if ( ! V_6 -> V_8 )
return 0 ;
if ( V_53 >= V_6 -> V_8 -> V_7 )
return 0 ;
V_2 = & V_6 -> V_8 -> V_26 [ V_53 ] ;
F_8 ( L_10 , V_53 , V_2 -> V_3 , V_2 -> V_4 ) ;
V_55 = F_20 ( V_38 , V_2 -> V_3 , V_2 -> V_4 , 60 , false , false ,
false ) ;
V_55 -> type |= V_56 ;
V_55 -> V_57 = V_2 -> V_3 ;
V_55 -> V_58 = V_2 -> V_4 ;
F_21 ( V_55 ) ;
* V_50 = V_2 -> V_3 ;
* V_51 = V_2 -> V_4 ;
F_22 ( V_41 , V_55 ) ;
V_6 -> V_59 = V_55 -> V_57 ;
V_6 -> V_60 = V_55 -> V_58 ;
return 1 ;
}
static int F_23 ( struct V_40 * V_41 ,
unsigned V_50 ,
unsigned V_51 )
{
struct V_37 * V_38 = V_41 -> V_38 ;
struct V_54 * V_55 = NULL ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_24 ( V_61 ) ; V_12 ++ ) {
V_55 = F_20 ( V_38 , V_61 [ V_12 ] . V_62 , V_61 [ V_12 ] . V_53 ,
60 , false , false , false ) ;
if ( V_61 [ V_12 ] . V_62 == V_50 && V_61 [ V_12 ] . V_53 == V_51 )
V_55 -> type |= V_56 ;
F_22 ( V_41 , V_55 ) ;
}
return V_12 - 1 ;
}
static void F_25 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
struct V_37 * V_38 = V_64 -> V_38 ;
struct V_67 * V_68 ;
unsigned long V_36 ;
if ( V_64 -> V_69 && V_64 -> V_69 -> V_68 ) {
V_68 = V_64 -> V_69 -> V_68 ;
V_64 -> V_69 -> V_68 = NULL ;
F_26 ( & V_38 -> V_70 , V_36 ) ;
F_27 ( V_64 , V_68 ) ;
F_28 ( & V_38 -> V_70 , V_36 ) ;
}
}
static void F_29 ( struct V_63 * V_64 )
{
struct V_71 * V_71 = F_30 ( V_64 ) ;
F_31 ( V_64 ) ;
F_3 ( V_71 ) ;
}
void F_32 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = F_33 ( V_73 ) ;
F_34 ( V_75 -> V_76 ) ;
F_35 ( V_73 ) ;
F_3 ( V_75 ) ;
}
static int F_36 ( struct V_72 * V_73 ,
struct V_77 * V_78 ,
unsigned V_36 , unsigned V_79 ,
struct V_80 * V_81 ,
unsigned V_82 )
{
struct V_74 * V_75 = F_33 ( V_73 ) ;
struct V_5 * V_6 = V_75 -> V_45 . V_38 -> V_52 ;
struct V_80 V_83 ;
struct V_84 * V_85 ;
int V_86 = 1 ;
F_15 ( V_73 -> V_38 ) ;
V_85 = F_37 ( V_75 -> V_76 ) ;
if ( ! V_85 -> V_87 ) {
F_16 ( V_73 -> V_38 ) ;
return 0 ;
}
if ( ! V_82 ) {
V_82 = 1 ;
V_81 = & V_83 ;
V_83 . V_88 = V_83 . y1 = 0 ;
V_83 . V_89 = V_73 -> V_3 ;
V_83 . V_90 = V_73 -> V_4 ;
} else if ( V_36 & V_91 ) {
V_82 /= 2 ;
V_86 = 2 ;
}
F_38 ( V_6 , V_75 , V_85 , V_36 , V_79 ,
V_81 , V_82 , V_86 ) ;
F_16 ( V_73 -> V_38 ) ;
return 0 ;
}
int
F_39 ( struct V_37 * V_38 ,
struct V_74 * V_92 ,
const struct V_93 * V_94 ,
struct V_95 * V_76 ,
const struct V_96 * V_97 )
{
int V_98 ;
V_92 -> V_76 = V_76 ;
F_40 ( V_38 , & V_92 -> V_45 , V_94 ) ;
V_98 = F_41 ( V_38 , & V_92 -> V_45 , V_97 ) ;
if ( V_98 ) {
V_92 -> V_76 = NULL ;
return V_98 ;
}
return 0 ;
}
static void F_42 ( struct V_63 * V_64 , int V_55 )
{
}
static bool F_43 ( struct V_63 * V_64 ,
const struct V_54 * V_55 ,
struct V_54 * V_99 )
{
struct V_37 * V_38 = V_64 -> V_38 ;
struct V_5 * V_6 = V_38 -> V_52 ;
F_5 ( V_6 , L_11 ,
V_11 ,
V_55 -> V_57 , V_55 -> V_58 ,
V_99 -> V_57 ,
V_99 -> V_58 ) ;
return true ;
}
static void
F_44 ( struct V_5 * V_6 )
{
int V_12 ;
F_45 ( ! V_6 -> V_100 -> V_21 ) ;
if ( V_6 -> V_21 -> V_7 == 0 ) {
F_5 ( V_6 , L_12 , V_11 ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_6 -> V_21 -> V_7 ; ++ V_12 ) {
struct V_1 * V_2 = & V_6 -> V_21 -> V_26 [ V_12 ] ;
if ( V_2 -> V_30 > 8192 || V_2 -> V_28 > 8192 ||
V_2 -> V_3 > 8192 || V_2 -> V_4 > 8192 ) {
F_46 ( L_13 ,
V_12 , V_2 -> V_3 , V_2 -> V_4 ,
V_2 -> V_28 , V_2 -> V_30 ) ;
return;
}
}
F_47 ( V_6 ) ;
}
static void F_48 ( struct V_5 * V_6 ,
int V_44 ,
unsigned V_28 , unsigned V_30 ,
unsigned V_3 , unsigned V_4 ,
unsigned V_101 )
{
F_8 ( L_14 , V_44 , V_3 , V_4 , V_28 , V_30 ) ;
V_6 -> V_21 -> V_26 [ V_44 ] . V_28 = V_28 ;
V_6 -> V_21 -> V_26 [ V_44 ] . V_30 = V_30 ;
V_6 -> V_21 -> V_26 [ V_44 ] . V_3 = V_3 ;
V_6 -> V_21 -> V_26 [ V_44 ] . V_4 = V_4 ;
V_6 -> V_21 -> V_26 [ V_44 ] . V_34 = V_101 ;
}
void F_49 ( struct V_63 * V_64 )
{
struct V_5 * V_6 = V_64 -> V_38 -> V_52 ;
struct V_71 * V_102 = F_30 ( V_64 ) ;
struct V_54 * V_55 = & V_64 -> V_55 ;
F_50 ( L_15 ,
V_55 -> V_57 , V_55 -> V_58 ) ;
F_48 ( V_6 , V_102 -> V_44 , 0 , 0 ,
V_55 -> V_57 , V_55 -> V_58 , 0 ) ;
}
static void F_51 ( struct V_63 * V_64 )
{
F_50 ( L_16 ) ;
}
static void F_52 ( struct V_63 * V_64 )
{
struct V_71 * V_102 = F_30 ( V_64 ) ;
struct V_5 * V_6 = V_64 -> V_38 -> V_52 ;
F_48 ( V_6 , V_102 -> V_44 , 0 , 0 , 0 , 0 , 0 ) ;
F_44 ( V_6 ) ;
}
int F_53 ( struct V_103 * V_104 ,
struct V_105 * V_69 )
{
struct V_5 * V_6 = V_104 -> V_38 -> V_52 ;
struct V_74 * V_92 ;
struct V_84 * V_106 ;
if ( ! V_69 -> V_64 || ! V_69 -> V_73 )
return 0 ;
V_92 = F_33 ( V_69 -> V_73 ) ;
V_106 = F_37 ( V_92 -> V_76 ) ;
if ( V_106 -> V_107 . V_108 * V_106 -> V_107 . V_4 > V_6 -> V_109 ) {
F_46 ( L_17 ) ;
return - V_110 ;
}
return 0 ;
}
static void F_54 ( struct V_103 * V_104 ,
struct V_105 * V_111 )
{
struct V_5 * V_6 = V_104 -> V_38 -> V_52 ;
struct V_74 * V_92 =
F_33 ( V_104 -> V_69 -> V_73 ) ;
struct V_74 * V_112 ;
struct V_84 * V_106 = F_37 ( V_92 -> V_76 ) ;
struct V_84 * V_113 ;
struct V_80 V_83 = {
. V_88 = 0 ,
. y1 = 0 ,
. V_89 = V_92 -> V_45 . V_3 ,
. V_90 = V_92 -> V_45 . V_4
} ;
if ( ! V_111 -> V_73 ) {
F_5 ( V_6 ,
L_18 ,
V_106 -> V_107 . V_3 , V_106 -> V_107 . V_4 ,
V_106 -> V_107 . V_108 , V_106 -> V_107 . V_114 ) ;
F_55 ( V_6 , 0 , V_106 ) ;
V_106 -> V_87 = true ;
return;
} else {
V_112 = F_33 ( V_111 -> V_73 ) ;
V_113 = F_37 ( V_112 -> V_76 ) ;
V_113 -> V_87 = false ;
}
V_106 -> V_87 = true ;
F_38 ( V_6 , V_92 , V_106 , 0 , 0 , & V_83 , 1 , 1 ) ;
}
static void F_56 ( struct V_103 * V_104 ,
struct V_105 * V_111 )
{
struct V_5 * V_6 = V_104 -> V_38 -> V_52 ;
if ( V_111 -> V_73 )
{ struct V_74 * V_92 =
F_33 ( V_111 -> V_73 ) ;
struct V_84 * V_106 = F_37 ( V_92 -> V_76 ) ;
F_57 ( V_6 ) ;
V_106 -> V_87 = false ;
}
}
int F_58 ( struct V_103 * V_104 ,
struct V_105 * V_69 )
{
return 0 ;
}
static void F_59 ( struct V_103 * V_104 ,
struct V_105 * V_111 )
{
struct V_37 * V_38 = V_104 -> V_38 ;
struct V_5 * V_6 = V_38 -> V_52 ;
struct V_72 * V_73 = V_104 -> V_69 -> V_73 ;
struct V_115 * V_116 ;
struct V_117 * V_118 ;
struct V_119 * V_120 ;
struct V_95 * V_76 ;
struct V_84 * V_121 , * V_122 = NULL ;
int V_98 ;
void * V_123 ;
int V_124 = 64 * 64 * 4 ;
V_98 = F_60 ( V_6 , sizeof( * V_118 ) ,
V_125 ,
& V_116 , NULL ) ;
if ( V_98 )
return;
if ( V_73 != V_111 -> V_73 ) {
V_76 = F_33 ( V_73 ) -> V_76 ;
V_122 = F_37 ( V_76 ) ;
V_98 = F_61 ( V_122 , & V_123 ) ;
if ( V_98 )
goto V_126;
V_98 = F_62 ( V_6 , V_116 ,
sizeof( struct V_119 ) + V_124 ,
& V_121 ) ;
if ( V_98 )
goto V_127;
V_98 = F_63 ( V_116 , true ) ;
if ( V_98 )
goto V_128;
V_98 = F_61 ( V_121 , ( void * * ) & V_120 ) ;
if ( V_98 )
goto V_129;
V_120 -> V_130 . V_131 = 0 ;
V_120 -> V_130 . type = V_132 ;
V_120 -> V_130 . V_3 = 64 ;
V_120 -> V_130 . V_4 = 64 ;
V_120 -> V_130 . V_133 = V_73 -> V_134 ;
V_120 -> V_130 . V_135 = V_73 -> V_136 ;
V_120 -> V_137 = V_124 ;
V_120 -> V_138 . V_139 = 0 ;
V_120 -> V_138 . V_140 = 0 ;
V_120 -> V_138 . V_137 = V_124 ;
memcpy ( V_120 -> V_138 . V_141 , V_123 , V_124 ) ;
F_64 ( V_121 ) ;
F_64 ( V_122 ) ;
V_118 = (struct V_117 * ) F_65 ( V_6 , V_116 ) ;
V_118 -> V_142 . V_143 . V_144 = 1 ;
V_118 -> V_142 . V_143 . V_145 = F_66 ( V_6 ,
V_121 , 0 ) ;
V_118 -> type = V_146 ;
} else {
V_98 = F_63 ( V_116 , true ) ;
if ( V_98 )
goto V_126;
V_118 = (struct V_117 * ) F_65 ( V_6 , V_116 ) ;
V_118 -> type = V_147 ;
}
V_118 -> V_142 . V_148 . V_28 = V_104 -> V_69 -> V_149 + V_73 -> V_134 ;
V_118 -> V_142 . V_148 . V_30 = V_104 -> V_69 -> V_150 + V_73 -> V_136 ;
F_67 ( V_6 , V_116 , & V_118 -> V_151 ) ;
F_68 ( V_6 , V_116 , V_152 , false ) ;
F_69 ( V_116 ) ;
return;
V_129:
F_70 ( V_116 ) ;
V_128:
F_71 ( & V_121 ) ;
V_127:
F_64 ( V_122 ) ;
V_126:
F_72 ( V_6 , V_116 ) ;
return;
}
void F_73 ( struct V_103 * V_104 ,
struct V_105 * V_111 )
{
struct V_5 * V_6 = V_104 -> V_38 -> V_52 ;
struct V_115 * V_116 ;
struct V_117 * V_118 ;
int V_98 ;
V_98 = F_60 ( V_6 , sizeof( * V_118 ) ,
V_125 ,
& V_116 , NULL ) ;
if ( V_98 )
return;
V_98 = F_63 ( V_116 , true ) ;
if ( V_98 ) {
F_72 ( V_6 , V_116 ) ;
return;
}
V_118 = (struct V_117 * ) F_65 ( V_6 , V_116 ) ;
V_118 -> type = V_153 ;
F_67 ( V_6 , V_116 , & V_118 -> V_151 ) ;
F_68 ( V_6 , V_116 , V_152 , false ) ;
F_69 ( V_116 ) ;
}
int F_74 ( struct V_103 * V_104 ,
struct V_105 * V_154 )
{
struct V_95 * V_76 ;
struct V_84 * V_122 ;
int V_98 ;
if ( ! V_154 -> V_73 )
return 0 ;
V_76 = F_33 ( V_154 -> V_73 ) -> V_76 ;
V_122 = F_37 ( V_76 ) ;
V_98 = F_75 ( V_122 , V_155 , NULL ) ;
if ( V_98 )
return V_98 ;
return 0 ;
}
static void F_76 ( struct V_103 * V_104 ,
struct V_105 * V_111 )
{
struct V_95 * V_76 ;
struct V_84 * V_122 ;
if ( ! V_104 -> V_69 -> V_73 ) {
return;
}
V_76 = F_33 ( V_104 -> V_69 -> V_73 ) -> V_76 ;
V_122 = F_37 ( V_76 ) ;
F_77 ( V_122 ) ;
}
static struct V_103 * F_78 ( struct V_5 * V_6 ,
unsigned int V_156 ,
enum V_157 type )
{
const struct V_158 * V_159 = NULL ;
struct V_103 * V_104 ;
const struct V_160 * V_97 ;
const T_1 * V_161 ;
int V_162 ;
int V_163 ;
if ( type == V_164 ) {
V_97 = & V_165 ;
V_161 = V_166 ;
V_162 = F_24 ( V_166 ) ;
V_159 = & V_167 ;
} else if ( type == V_168 ) {
V_97 = & V_169 ;
V_161 = V_170 ;
V_159 = & V_171 ;
V_162 = F_24 ( V_170 ) ;
} else {
return F_79 ( - V_110 ) ;
}
V_104 = F_4 ( sizeof( * V_104 ) , V_10 ) ;
if ( ! V_104 )
return F_79 ( - V_172 ) ;
V_163 = F_80 ( & V_6 -> V_39 , V_104 , V_156 ,
V_97 , V_161 , V_162 ,
type , NULL ) ;
if ( V_163 )
goto V_173;
F_81 ( V_104 , V_159 ) ;
return V_104 ;
V_173:
F_3 ( V_104 ) ;
return F_79 ( - V_110 ) ;
}
static int F_82 ( struct V_37 * V_38 , int V_174 )
{
struct V_71 * V_71 ;
struct V_103 * V_175 , * V_120 ;
struct V_5 * V_6 = V_38 -> V_52 ;
int V_176 ;
V_71 = F_4 ( sizeof( struct V_71 ) , V_10 ) ;
if ( ! V_71 )
return - V_172 ;
V_175 = F_78 ( V_6 , 1 << V_174 , V_164 ) ;
if ( F_83 ( V_175 ) ) {
V_176 = - V_172 ;
goto V_177;
}
V_120 = F_78 ( V_6 , 1 << V_174 , V_168 ) ;
if ( F_83 ( V_120 ) ) {
V_176 = - V_172 ;
goto V_178;
}
V_176 = F_84 ( V_38 , & V_71 -> V_45 , V_175 , V_120 ,
& V_179 , NULL ) ;
if ( V_176 )
goto V_180;
V_71 -> V_44 = V_174 ;
F_85 ( & V_71 -> V_45 , & V_181 ) ;
return 0 ;
V_180:
F_86 ( V_120 ) ;
F_3 ( V_120 ) ;
V_178:
F_86 ( V_175 ) ;
F_3 ( V_175 ) ;
V_177:
F_3 ( V_71 ) ;
return V_176 ;
}
static void F_87 ( struct V_182 * V_183 , int V_55 )
{
F_50 ( L_16 ) ;
}
static void F_88 ( struct V_182 * V_183 )
{
F_50 ( L_16 ) ;
}
static void F_89 ( struct V_5 * V_6 ,
struct V_182 * V_183 )
{
int V_12 ;
struct V_42 * V_43 = F_90 ( V_183 ) ;
struct V_1 * V_2 ;
struct V_54 * V_55 ;
F_45 ( ! V_183 ) ;
V_12 = V_43 -> V_44 ;
if ( ! V_6 -> V_21 ||
V_6 -> V_21 -> V_22 <= V_12 ) {
F_46 (
L_19 ,
V_6 -> V_21 ,
V_6 -> V_21 ?
V_6 -> V_21 -> V_22 : - 1 ) ;
return;
}
if ( ! V_183 -> V_64 ) {
F_46 ( L_20 , V_183 ) ;
return;
}
if ( V_12 != 0 )
F_50 ( L_21 ) ;
V_2 = & V_6 -> V_21 -> V_26 [ V_12 ] ;
V_2 -> V_35 = V_12 ;
if ( V_183 -> V_64 -> V_184 ) {
V_55 = & V_183 -> V_64 -> V_55 ;
V_2 -> V_3 = V_55 -> V_57 ;
V_2 -> V_4 = V_55 -> V_58 ;
V_2 -> V_28 = V_183 -> V_64 -> V_28 ;
V_2 -> V_30 = V_183 -> V_64 -> V_30 ;
if ( V_6 -> V_21 -> V_7 < V_12 + 1 )
V_6 -> V_21 -> V_7 = V_12 + 1 ;
} else {
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_28 = 0 ;
V_2 -> V_30 = 0 ;
}
F_8 ( L_22 ,
V_12 , V_2 -> V_28 , V_2 -> V_30 , V_2 -> V_3 , V_2 -> V_4 , V_6 -> V_21 -> V_7 ) ;
V_2 -> V_36 = 0 ;
F_44 ( V_6 ) ;
}
static void F_91 ( struct V_182 * V_183 )
{
struct V_5 * V_6 = V_183 -> V_38 -> V_52 ;
F_89 ( V_6 , V_183 ) ;
F_50 ( L_16 ) ;
}
static void F_92 ( struct V_182 * V_183 ,
struct V_54 * V_55 ,
struct V_54 * V_99 )
{
F_50 ( L_16 ) ;
}
static int F_93 ( struct V_40 * V_41 )
{
unsigned V_50 = 1024 ;
unsigned V_51 = 768 ;
int V_98 = 0 ;
V_98 = F_19 ( V_41 , & V_50 , & V_51 ) ;
if ( V_98 < 0 )
return V_98 ;
V_98 += F_23 ( V_41 , V_50 , V_51 ) ;
return V_98 ;
}
static int F_94 ( struct V_40 * V_41 ,
struct V_54 * V_55 )
{
struct V_37 * V_39 = V_41 -> V_38 ;
struct V_5 * V_6 = V_39 -> V_52 ;
int V_12 ;
if( V_6 -> V_59 == V_55 -> V_57 &&
V_6 -> V_60 == V_55 -> V_58 )
return V_185 ;
for ( V_12 = 0 ; V_12 < F_24 ( V_61 ) ; V_12 ++ ) {
if ( V_61 [ V_12 ] . V_62 == V_55 -> V_57 && V_61 [ V_12 ] . V_53 == V_55 -> V_58 )
return V_185 ;
}
return V_186 ;
}
static struct V_182 * F_95 ( struct V_40 * V_41 )
{
struct V_42 * V_42 =
F_11 ( V_41 ) ;
F_50 ( L_16 ) ;
return & V_42 -> V_187 ;
}
static enum V_188 F_96 (
struct V_40 * V_41 ,
bool V_189 )
{
struct V_42 * V_43 =
F_11 ( V_41 ) ;
struct V_37 * V_39 = V_41 -> V_38 ;
struct V_5 * V_6 = V_39 -> V_52 ;
bool V_190 = false ;
if ( ! V_6 -> V_8 ) {
if ( V_43 -> V_44 == 0 )
V_190 = true ;
} else
V_190 = V_6 -> V_8 -> V_7 > V_43 -> V_44 &&
F_1 ( & V_6 -> V_8 -> V_26 [ V_43 -> V_44 ] ) ;
F_50 ( L_23 , V_43 -> V_44 , V_190 ) ;
if ( ! V_190 )
F_48 ( V_6 , V_43 -> V_44 , 0 , 0 , 0 , 0 , 0 ) ;
return V_190 ? V_191
: V_192 ;
}
static int F_97 ( struct V_40 * V_41 ,
struct V_193 * V_194 ,
T_2 V_195 )
{
F_50 ( L_16 ) ;
return 0 ;
}
static void F_98 ( struct V_40 * V_41 )
{
struct V_42 * V_42 =
F_11 ( V_41 ) ;
F_99 ( V_41 ) ;
F_100 ( V_41 ) ;
F_3 ( V_42 ) ;
}
static void F_101 ( struct V_182 * V_183 )
{
F_102 ( V_183 ) ;
}
static int F_103 ( struct V_5 * V_6 )
{
if ( V_6 -> V_196 )
return 0 ;
V_6 -> V_196 =
F_104 ( & V_6 -> V_39 , V_197 ,
L_24 , 0 , 1 ) ;
return 0 ;
}
static int F_105 ( struct V_37 * V_38 , int V_198 )
{
struct V_5 * V_6 = V_38 -> V_52 ;
struct V_42 * V_42 ;
struct V_40 * V_41 ;
struct V_182 * V_183 ;
V_42 = F_4 ( sizeof( struct V_42 ) , V_10 ) ;
if ( ! V_42 )
return - V_172 ;
V_42 -> V_44 = V_198 ;
V_41 = & V_42 -> V_45 ;
V_183 = & V_42 -> V_187 ;
F_106 ( V_38 , & V_42 -> V_45 ,
& V_199 , V_200 ) ;
F_107 ( V_38 , & V_42 -> V_187 , & V_201 ,
V_202 , NULL ) ;
V_41 -> V_203 = V_204 ;
V_183 -> V_156 = 1 << V_198 ;
F_108 ( & V_42 -> V_45 ,
& V_42 -> V_187 ) ;
F_109 ( V_183 , & V_205 ) ;
F_110 ( V_41 , & V_206 ) ;
F_111 ( & V_41 -> V_45 ,
V_6 -> V_196 , 0 ) ;
F_111 ( & V_41 -> V_45 ,
V_38 -> V_46 . V_47 , 0 ) ;
F_111 ( & V_41 -> V_45 ,
V_38 -> V_46 . V_48 , 0 ) ;
return 0 ;
}
static struct V_72 *
F_112 ( struct V_37 * V_38 ,
struct V_77 * V_78 ,
const struct V_93 * V_94 )
{
struct V_95 * V_76 ;
struct V_74 * V_75 ;
int V_98 ;
V_76 = F_113 ( V_78 , V_94 -> V_207 [ 0 ] ) ;
if ( ! V_76 )
return NULL ;
V_75 = F_4 ( sizeof( * V_75 ) , V_10 ) ;
if ( V_75 == NULL )
return NULL ;
V_98 = F_39 ( V_38 , V_75 , V_94 , V_76 , & V_208 ) ;
if ( V_98 ) {
F_3 ( V_75 ) ;
F_34 ( V_76 ) ;
return NULL ;
}
return & V_75 -> V_45 ;
}
int F_114 ( struct V_5 * V_6 )
{
int V_98 ;
struct V_95 * V_209 ;
int V_22 = V_210 ;
int V_211 = sizeof( struct V_9 ) +
V_22 * sizeof( struct V_1 ) ;
V_98 = F_115 ( V_6 , V_211 , 0 ,
V_212 ,
false , false , NULL , & V_209 ) ;
if ( V_98 ) {
F_46 ( L_25 , V_11 , V_98 ) ;
return - V_172 ;
}
V_6 -> V_213 = F_37 ( V_209 ) ;
V_98 = F_75 ( V_6 -> V_213 , V_212 , NULL ) ;
if ( V_98 )
return V_98 ;
F_61 ( V_6 -> V_213 , NULL ) ;
V_6 -> V_21 = V_6 -> V_213 -> V_214 ;
V_6 -> V_100 -> V_21 =
F_66 ( V_6 , V_6 -> V_213 , 0 ) ;
memset ( V_6 -> V_21 , 0 , V_211 ) ;
V_6 -> V_21 -> V_22 = V_22 ;
return 0 ;
}
int F_116 ( struct V_5 * V_6 )
{
int V_98 ;
V_6 -> V_21 = NULL ;
V_6 -> V_100 -> V_21 = 0 ;
F_64 ( V_6 -> V_213 ) ;
V_98 = F_77 ( V_6 -> V_213 ) ;
if ( V_98 )
return V_98 ;
F_71 ( & V_6 -> V_213 ) ;
return 0 ;
}
int F_117 ( struct V_5 * V_6 )
{
int V_12 ;
int V_98 ;
F_118 ( & V_6 -> V_39 ) ;
V_98 = F_114 ( V_6 ) ;
if ( V_98 )
return V_98 ;
V_6 -> V_39 . V_46 . V_97 = ( void * ) & V_215 ;
V_6 -> V_39 . V_46 . V_216 = 0 ;
V_6 -> V_39 . V_46 . V_217 = 0 ;
V_6 -> V_39 . V_46 . V_218 = 8192 ;
V_6 -> V_39 . V_46 . V_219 = 8192 ;
V_6 -> V_39 . V_46 . V_220 = V_6 -> V_221 ;
F_119 ( & V_6 -> V_39 ) ;
F_103 ( V_6 ) ;
for ( V_12 = 0 ; V_12 < V_210 ; ++ V_12 ) {
F_82 ( & V_6 -> V_39 , V_12 ) ;
F_105 ( & V_6 -> V_39 , V_12 ) ;
}
F_13 ( V_6 ) ;
V_6 -> V_222 . V_223 = true ;
F_120 ( & V_6 -> V_39 ) ;
F_121 ( V_6 ) ;
return 0 ;
}
void F_122 ( struct V_5 * V_6 )
{
F_123 ( V_6 ) ;
F_116 ( V_6 ) ;
if ( V_6 -> V_222 . V_223 ) {
F_124 ( & V_6 -> V_39 ) ;
V_6 -> V_222 . V_223 = false ;
}
}
