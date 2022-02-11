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
static bool F_42 ( struct V_63 * V_64 ,
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
F_43 ( struct V_5 * V_6 )
{
int V_12 ;
F_44 ( ! V_6 -> V_100 -> V_21 ) ;
if ( V_6 -> V_21 -> V_7 == 0 ) {
F_5 ( V_6 , L_12 , V_11 ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_6 -> V_21 -> V_7 ; ++ V_12 ) {
struct V_1 * V_2 = & V_6 -> V_21 -> V_26 [ V_12 ] ;
if ( V_2 -> V_30 > 8192 || V_2 -> V_28 > 8192 ||
V_2 -> V_3 > 8192 || V_2 -> V_4 > 8192 ) {
F_45 ( L_13 ,
V_12 , V_2 -> V_3 , V_2 -> V_4 ,
V_2 -> V_28 , V_2 -> V_30 ) ;
return;
}
}
F_46 ( V_6 ) ;
}
static void F_47 ( struct V_5 * V_6 ,
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
static void F_48 ( struct V_63 * V_64 )
{
struct V_5 * V_6 = V_64 -> V_38 -> V_52 ;
struct V_71 * V_102 = F_30 ( V_64 ) ;
struct V_54 * V_55 = & V_64 -> V_55 ;
F_49 ( L_15 ,
V_55 -> V_57 , V_55 -> V_58 ) ;
F_47 ( V_6 , V_102 -> V_44 , 0 , 0 ,
V_55 -> V_57 , V_55 -> V_58 , 0 ) ;
}
static void F_50 ( struct V_63 * V_64 ,
struct V_65 * V_103 )
{
F_49 ( L_16 ) ;
}
static void F_51 ( struct V_63 * V_64 ,
struct V_65 * V_103 )
{
struct V_71 * V_102 = F_30 ( V_64 ) ;
struct V_5 * V_6 = V_64 -> V_38 -> V_52 ;
F_47 ( V_6 , V_102 -> V_44 , 0 , 0 , 0 , 0 , 0 ) ;
F_43 ( V_6 ) ;
}
static int F_52 ( struct V_104 * V_105 ,
struct V_106 * V_69 )
{
struct V_5 * V_6 = V_105 -> V_38 -> V_52 ;
struct V_74 * V_92 ;
struct V_84 * V_107 ;
if ( ! V_69 -> V_64 || ! V_69 -> V_73 )
return 0 ;
V_92 = F_33 ( V_69 -> V_73 ) ;
V_107 = F_37 ( V_92 -> V_76 ) ;
if ( V_107 -> V_108 . V_109 * V_107 -> V_108 . V_4 > V_6 -> V_110 ) {
F_45 ( L_17 ) ;
return - V_111 ;
}
return 0 ;
}
static void F_53 ( struct V_104 * V_105 ,
struct V_106 * V_103 )
{
struct V_5 * V_6 = V_105 -> V_38 -> V_52 ;
struct V_74 * V_92 =
F_33 ( V_105 -> V_69 -> V_73 ) ;
struct V_74 * V_112 ;
struct V_84 * V_107 = F_37 ( V_92 -> V_76 ) ;
struct V_84 * V_113 ;
struct V_80 V_83 = {
. V_88 = 0 ,
. y1 = 0 ,
. V_89 = V_92 -> V_45 . V_3 ,
. V_90 = V_92 -> V_45 . V_4
} ;
if ( V_103 -> V_73 ) {
V_112 = F_33 ( V_103 -> V_73 ) ;
V_113 = F_37 ( V_112 -> V_76 ) ;
} else {
V_113 = NULL ;
}
if ( V_107 == V_113 )
return;
if ( V_113 && V_113 -> V_87 ) {
F_54 ( V_6 ) ;
V_113 -> V_87 = false ;
}
if ( ! V_107 -> V_87 ) {
F_55 ( V_6 , 0 , V_107 ) ;
V_107 -> V_87 = true ;
}
F_38 ( V_6 , V_92 , V_107 , 0 , 0 , & V_83 , 1 , 1 ) ;
}
static void F_56 ( struct V_104 * V_105 ,
struct V_106 * V_103 )
{
struct V_5 * V_6 = V_105 -> V_38 -> V_52 ;
if ( V_103 -> V_73 ) {
struct V_74 * V_92 =
F_33 ( V_103 -> V_73 ) ;
struct V_84 * V_107 = F_37 ( V_92 -> V_76 ) ;
if ( V_107 -> V_87 ) {
F_54 ( V_6 ) ;
V_107 -> V_87 = false ;
}
}
}
static int F_57 ( struct V_104 * V_105 ,
struct V_106 * V_69 )
{
return 0 ;
}
static void F_58 ( struct V_104 * V_105 ,
struct V_106 * V_103 )
{
struct V_37 * V_38 = V_105 -> V_38 ;
struct V_5 * V_6 = V_38 -> V_52 ;
struct V_72 * V_73 = V_105 -> V_69 -> V_73 ;
struct V_114 * V_115 ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
struct V_95 * V_76 ;
struct V_84 * V_120 , * V_121 = NULL ;
int V_98 ;
void * V_122 ;
int V_123 = 64 * 64 * 4 ;
V_98 = F_59 ( V_6 , sizeof( * V_117 ) ,
V_124 ,
& V_115 , NULL ) ;
if ( V_98 )
return;
if ( V_73 != V_103 -> V_73 ) {
V_76 = F_33 ( V_73 ) -> V_76 ;
V_121 = F_37 ( V_76 ) ;
V_98 = F_60 ( V_121 , & V_122 ) ;
if ( V_98 )
goto V_125;
V_98 = F_61 ( V_6 , V_115 ,
sizeof( struct V_118 ) + V_123 ,
& V_120 ) ;
if ( V_98 )
goto V_126;
V_98 = F_62 ( V_115 , true ) ;
if ( V_98 )
goto V_127;
V_98 = F_60 ( V_120 , ( void * * ) & V_119 ) ;
if ( V_98 )
goto V_128;
V_119 -> V_129 . V_130 = 0 ;
V_119 -> V_129 . type = V_131 ;
V_119 -> V_129 . V_3 = 64 ;
V_119 -> V_129 . V_4 = 64 ;
V_119 -> V_129 . V_132 = V_73 -> V_133 ;
V_119 -> V_129 . V_134 = V_73 -> V_135 ;
V_119 -> V_136 = V_123 ;
V_119 -> V_137 . V_138 = 0 ;
V_119 -> V_137 . V_139 = 0 ;
V_119 -> V_137 . V_136 = V_123 ;
memcpy ( V_119 -> V_137 . V_140 , V_122 , V_123 ) ;
F_63 ( V_120 ) ;
F_63 ( V_121 ) ;
V_117 = (struct V_116 * ) F_64 ( V_6 , V_115 ) ;
V_117 -> V_141 . V_142 . V_143 = 1 ;
V_117 -> V_141 . V_142 . V_144 = F_65 ( V_6 ,
V_120 , 0 ) ;
V_117 -> type = V_145 ;
} else {
V_98 = F_62 ( V_115 , true ) ;
if ( V_98 )
goto V_125;
V_117 = (struct V_116 * ) F_64 ( V_6 , V_115 ) ;
V_117 -> type = V_146 ;
}
V_117 -> V_141 . V_147 . V_28 = V_105 -> V_69 -> V_148 + V_73 -> V_133 ;
V_117 -> V_141 . V_147 . V_30 = V_105 -> V_69 -> V_149 + V_73 -> V_135 ;
F_66 ( V_6 , V_115 , & V_117 -> V_150 ) ;
F_67 ( V_6 , V_115 , V_151 , false ) ;
F_68 ( V_115 ) ;
return;
V_128:
F_69 ( V_115 ) ;
V_127:
F_70 ( & V_120 ) ;
V_126:
F_63 ( V_121 ) ;
V_125:
F_71 ( V_6 , V_115 ) ;
return;
}
static void F_72 ( struct V_104 * V_105 ,
struct V_106 * V_103 )
{
struct V_5 * V_6 = V_105 -> V_38 -> V_52 ;
struct V_114 * V_115 ;
struct V_116 * V_117 ;
int V_98 ;
V_98 = F_59 ( V_6 , sizeof( * V_117 ) ,
V_124 ,
& V_115 , NULL ) ;
if ( V_98 )
return;
V_98 = F_62 ( V_115 , true ) ;
if ( V_98 ) {
F_71 ( V_6 , V_115 ) ;
return;
}
V_117 = (struct V_116 * ) F_64 ( V_6 , V_115 ) ;
V_117 -> type = V_152 ;
F_66 ( V_6 , V_115 , & V_117 -> V_150 ) ;
F_67 ( V_6 , V_115 , V_151 , false ) ;
F_68 ( V_115 ) ;
}
static int F_73 ( struct V_104 * V_105 ,
struct V_106 * V_153 )
{
struct V_95 * V_76 ;
struct V_84 * V_121 ;
int V_98 ;
if ( ! V_153 -> V_73 )
return 0 ;
V_76 = F_33 ( V_153 -> V_73 ) -> V_76 ;
V_121 = F_37 ( V_76 ) ;
V_98 = F_74 ( V_121 , V_154 , NULL ) ;
if ( V_98 )
return V_98 ;
return 0 ;
}
static void F_75 ( struct V_104 * V_105 ,
struct V_106 * V_103 )
{
struct V_95 * V_76 ;
struct V_84 * V_121 ;
if ( ! V_103 -> V_73 ) {
return;
}
V_76 = F_33 ( V_103 -> V_73 ) -> V_76 ;
V_121 = F_37 ( V_76 ) ;
F_76 ( V_121 ) ;
}
static struct V_104 * F_77 ( struct V_5 * V_6 ,
unsigned int V_155 ,
enum V_156 type )
{
const struct V_157 * V_158 = NULL ;
struct V_104 * V_105 ;
const struct V_159 * V_97 ;
const T_1 * V_160 ;
int V_161 ;
int V_162 ;
if ( type == V_163 ) {
V_97 = & V_164 ;
V_160 = V_165 ;
V_161 = F_24 ( V_165 ) ;
V_158 = & V_166 ;
} else if ( type == V_167 ) {
V_97 = & V_168 ;
V_160 = V_169 ;
V_158 = & V_170 ;
V_161 = F_24 ( V_169 ) ;
} else {
return F_78 ( - V_111 ) ;
}
V_105 = F_4 ( sizeof( * V_105 ) , V_10 ) ;
if ( ! V_105 )
return F_78 ( - V_171 ) ;
V_162 = F_79 ( & V_6 -> V_39 , V_105 , V_155 ,
V_97 , V_160 , V_161 ,
NULL , type , NULL ) ;
if ( V_162 )
goto V_172;
F_80 ( V_105 , V_158 ) ;
return V_105 ;
V_172:
F_3 ( V_105 ) ;
return F_78 ( - V_111 ) ;
}
static int F_81 ( struct V_37 * V_38 , int V_173 )
{
struct V_71 * V_71 ;
struct V_104 * V_174 , * V_119 ;
struct V_5 * V_6 = V_38 -> V_52 ;
int V_175 ;
V_71 = F_4 ( sizeof( struct V_71 ) , V_10 ) ;
if ( ! V_71 )
return - V_171 ;
V_174 = F_77 ( V_6 , 1 << V_173 , V_163 ) ;
if ( F_82 ( V_174 ) ) {
V_175 = - V_171 ;
goto V_176;
}
V_119 = F_77 ( V_6 , 1 << V_173 , V_167 ) ;
if ( F_82 ( V_119 ) ) {
V_175 = - V_171 ;
goto V_177;
}
V_175 = F_83 ( V_38 , & V_71 -> V_45 , V_174 , V_119 ,
& V_178 , NULL ) ;
if ( V_175 )
goto V_179;
V_71 -> V_44 = V_173 ;
F_84 ( & V_71 -> V_45 , & V_180 ) ;
return 0 ;
V_179:
F_85 ( V_119 ) ;
F_3 ( V_119 ) ;
V_177:
F_85 ( V_174 ) ;
F_3 ( V_174 ) ;
V_176:
F_3 ( V_71 ) ;
return V_175 ;
}
static void F_86 ( struct V_181 * V_182 , int V_55 )
{
F_49 ( L_16 ) ;
}
static void F_87 ( struct V_181 * V_182 )
{
F_49 ( L_16 ) ;
}
static void F_88 ( struct V_5 * V_6 ,
struct V_181 * V_182 )
{
int V_12 ;
struct V_42 * V_43 = F_89 ( V_182 ) ;
struct V_1 * V_2 ;
struct V_54 * V_55 ;
F_44 ( ! V_182 ) ;
V_12 = V_43 -> V_44 ;
if ( ! V_6 -> V_21 ||
V_6 -> V_21 -> V_22 <= V_12 ) {
F_45 (
L_18 ,
V_6 -> V_21 ,
V_6 -> V_21 ?
V_6 -> V_21 -> V_22 : - 1 ) ;
return;
}
if ( ! V_182 -> V_64 ) {
F_45 ( L_19 , V_182 ) ;
return;
}
if ( V_12 != 0 )
F_49 ( L_20 ) ;
V_2 = & V_6 -> V_21 -> V_26 [ V_12 ] ;
V_2 -> V_35 = V_12 ;
if ( V_182 -> V_64 -> V_183 ) {
V_55 = & V_182 -> V_64 -> V_55 ;
V_2 -> V_3 = V_55 -> V_57 ;
V_2 -> V_4 = V_55 -> V_58 ;
V_2 -> V_28 = V_182 -> V_64 -> V_28 ;
V_2 -> V_30 = V_182 -> V_64 -> V_30 ;
if ( V_6 -> V_21 -> V_7 < V_12 + 1 )
V_6 -> V_21 -> V_7 = V_12 + 1 ;
} else {
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_28 = 0 ;
V_2 -> V_30 = 0 ;
}
F_8 ( L_21 ,
V_12 , V_2 -> V_28 , V_2 -> V_30 , V_2 -> V_3 , V_2 -> V_4 , V_6 -> V_21 -> V_7 ) ;
V_2 -> V_36 = 0 ;
F_43 ( V_6 ) ;
}
static void F_90 ( struct V_181 * V_182 )
{
struct V_5 * V_6 = V_182 -> V_38 -> V_52 ;
F_88 ( V_6 , V_182 ) ;
F_49 ( L_16 ) ;
}
static void F_91 ( struct V_181 * V_182 ,
struct V_54 * V_55 ,
struct V_54 * V_99 )
{
F_49 ( L_16 ) ;
}
static int F_92 ( struct V_40 * V_41 )
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
static int F_93 ( struct V_40 * V_41 ,
struct V_54 * V_55 )
{
struct V_37 * V_39 = V_41 -> V_38 ;
struct V_5 * V_6 = V_39 -> V_52 ;
int V_12 ;
if( V_6 -> V_59 == V_55 -> V_57 &&
V_6 -> V_60 == V_55 -> V_58 )
return V_184 ;
for ( V_12 = 0 ; V_12 < F_24 ( V_61 ) ; V_12 ++ ) {
if ( V_61 [ V_12 ] . V_62 == V_55 -> V_57 && V_61 [ V_12 ] . V_53 == V_55 -> V_58 )
return V_184 ;
}
return V_185 ;
}
static struct V_181 * F_94 ( struct V_40 * V_41 )
{
struct V_42 * V_42 =
F_11 ( V_41 ) ;
F_49 ( L_16 ) ;
return & V_42 -> V_186 ;
}
static enum V_187 F_95 (
struct V_40 * V_41 ,
bool V_188 )
{
struct V_42 * V_43 =
F_11 ( V_41 ) ;
struct V_37 * V_39 = V_41 -> V_38 ;
struct V_5 * V_6 = V_39 -> V_52 ;
bool V_189 = false ;
if ( ! V_6 -> V_8 ) {
if ( V_43 -> V_44 == 0 )
V_189 = true ;
} else
V_189 = V_6 -> V_8 -> V_7 > V_43 -> V_44 &&
F_1 ( & V_6 -> V_8 -> V_26 [ V_43 -> V_44 ] ) ;
F_49 ( L_22 , V_43 -> V_44 , V_189 ) ;
if ( ! V_189 )
F_47 ( V_6 , V_43 -> V_44 , 0 , 0 , 0 , 0 , 0 ) ;
return V_189 ? V_190
: V_191 ;
}
static int F_96 ( struct V_40 * V_41 ,
struct V_192 * V_193 ,
T_2 V_194 )
{
F_49 ( L_16 ) ;
return 0 ;
}
static void F_97 ( struct V_40 * V_41 )
{
struct V_42 * V_42 =
F_11 ( V_41 ) ;
F_98 ( V_41 ) ;
F_99 ( V_41 ) ;
F_3 ( V_42 ) ;
}
static void F_100 ( struct V_181 * V_182 )
{
F_101 ( V_182 ) ;
}
static int F_102 ( struct V_5 * V_6 )
{
if ( V_6 -> V_195 )
return 0 ;
V_6 -> V_195 =
F_103 ( & V_6 -> V_39 , V_196 ,
L_23 , 0 , 1 ) ;
return 0 ;
}
static int F_104 ( struct V_37 * V_38 , int V_197 )
{
struct V_5 * V_6 = V_38 -> V_52 ;
struct V_42 * V_42 ;
struct V_40 * V_41 ;
struct V_181 * V_182 ;
V_42 = F_4 ( sizeof( struct V_42 ) , V_10 ) ;
if ( ! V_42 )
return - V_171 ;
V_42 -> V_44 = V_197 ;
V_41 = & V_42 -> V_45 ;
V_182 = & V_42 -> V_186 ;
F_105 ( V_38 , & V_42 -> V_45 ,
& V_198 , V_199 ) ;
F_106 ( V_38 , & V_42 -> V_186 , & V_200 ,
V_201 , NULL ) ;
V_41 -> V_202 = V_203 ;
V_182 -> V_155 = 1 << V_197 ;
F_107 ( & V_42 -> V_45 ,
& V_42 -> V_186 ) ;
F_108 ( V_182 , & V_204 ) ;
F_109 ( V_41 , & V_205 ) ;
F_110 ( & V_41 -> V_45 ,
V_6 -> V_195 , 0 ) ;
F_110 ( & V_41 -> V_45 ,
V_38 -> V_46 . V_47 , 0 ) ;
F_110 ( & V_41 -> V_45 ,
V_38 -> V_46 . V_48 , 0 ) ;
return 0 ;
}
static struct V_72 *
F_111 ( struct V_37 * V_38 ,
struct V_77 * V_78 ,
const struct V_93 * V_94 )
{
struct V_95 * V_76 ;
struct V_74 * V_75 ;
int V_98 ;
V_76 = F_112 ( V_78 , V_94 -> V_206 [ 0 ] ) ;
if ( ! V_76 )
return NULL ;
V_75 = F_4 ( sizeof( * V_75 ) , V_10 ) ;
if ( V_75 == NULL )
return NULL ;
V_98 = F_39 ( V_38 , V_75 , V_94 , V_76 , & V_207 ) ;
if ( V_98 ) {
F_3 ( V_75 ) ;
F_34 ( V_76 ) ;
return NULL ;
}
return & V_75 -> V_45 ;
}
int F_113 ( struct V_5 * V_6 )
{
int V_98 ;
struct V_95 * V_208 ;
int V_22 = V_209 ;
int V_210 = sizeof( struct V_9 ) +
V_22 * sizeof( struct V_1 ) ;
V_98 = F_114 ( V_6 , V_210 , 0 ,
V_211 ,
false , false , NULL , & V_208 ) ;
if ( V_98 ) {
F_45 ( L_24 , V_11 , V_98 ) ;
return - V_171 ;
}
V_6 -> V_212 = F_37 ( V_208 ) ;
V_98 = F_74 ( V_6 -> V_212 , V_211 , NULL ) ;
if ( V_98 )
return V_98 ;
F_60 ( V_6 -> V_212 , NULL ) ;
V_6 -> V_21 = V_6 -> V_212 -> V_213 ;
V_6 -> V_100 -> V_21 =
F_65 ( V_6 , V_6 -> V_212 , 0 ) ;
memset ( V_6 -> V_21 , 0 , V_210 ) ;
V_6 -> V_21 -> V_22 = V_22 ;
return 0 ;
}
int F_115 ( struct V_5 * V_6 )
{
int V_98 ;
V_6 -> V_21 = NULL ;
V_6 -> V_100 -> V_21 = 0 ;
F_63 ( V_6 -> V_212 ) ;
V_98 = F_76 ( V_6 -> V_212 ) ;
if ( V_98 )
return V_98 ;
F_70 ( & V_6 -> V_212 ) ;
return 0 ;
}
int F_116 ( struct V_5 * V_6 )
{
int V_12 ;
int V_98 ;
F_117 ( & V_6 -> V_39 ) ;
V_98 = F_113 ( V_6 ) ;
if ( V_98 )
return V_98 ;
V_6 -> V_39 . V_46 . V_97 = ( void * ) & V_214 ;
V_6 -> V_39 . V_46 . V_215 = 0 ;
V_6 -> V_39 . V_46 . V_216 = 0 ;
V_6 -> V_39 . V_46 . V_217 = 8192 ;
V_6 -> V_39 . V_46 . V_218 = 8192 ;
V_6 -> V_39 . V_46 . V_219 = V_6 -> V_220 ;
F_118 ( & V_6 -> V_39 ) ;
F_102 ( V_6 ) ;
for ( V_12 = 0 ; V_12 < V_209 ; ++ V_12 ) {
F_81 ( & V_6 -> V_39 , V_12 ) ;
F_104 ( & V_6 -> V_39 , V_12 ) ;
}
F_13 ( V_6 ) ;
V_6 -> V_221 . V_222 = true ;
F_119 ( & V_6 -> V_39 ) ;
F_120 ( V_6 ) ;
return 0 ;
}
void F_121 ( struct V_5 * V_6 )
{
F_122 ( V_6 ) ;
F_115 ( V_6 ) ;
if ( V_6 -> V_221 . V_222 ) {
F_123 ( & V_6 -> V_39 ) ;
V_6 -> V_221 . V_222 = false ;
}
}
