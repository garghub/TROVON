void F_1 ( struct V_1 * V_2 ,
int V_3 ,
struct V_4 V_5 ,
T_1 * V_6 ,
int * V_7 )
{
int V_8 , V_9 ;
for ( V_8 = 0 , V_9 = 0 ; V_8 < V_3 ; V_8 ++ ) {
int V_10 = F_2 ( int , V_5 . V_10 , V_2 [ V_8 ] . V_10 ) ;
int y1 = F_2 ( int , V_5 . y1 , V_2 [ V_8 ] . y1 ) ;
int V_11 = F_3 ( int , V_5 . V_11 , V_2 [ V_8 ] . V_11 ) ;
int V_12 = F_3 ( int , V_5 . V_12 , V_2 [ V_8 ] . V_12 ) ;
if ( V_10 >= V_11 )
continue;
if ( y1 >= V_12 )
continue;
V_6 [ V_9 ] . V_13 = V_10 ;
V_6 [ V_9 ] . V_14 = y1 ;
V_6 [ V_9 ] . V_15 = V_11 ;
V_6 [ V_9 ] . V_16 = V_12 ;
V_9 ++ ;
}
* V_7 = V_9 ;
}
void F_4 ( struct V_17 * V_18 )
{
if ( V_18 -> V_19 )
F_5 ( & V_18 -> V_19 ) ;
if ( V_18 -> V_20 )
F_6 ( & V_18 -> V_20 ) ;
F_7 ( & V_18 -> V_21 ) ;
F_8 ( & V_18 -> V_22 ) ;
F_9 ( & V_18 -> V_23 ) ;
}
int F_10 ( struct V_24 * V_25 ,
T_2 * V_26 , T_2 V_27 , T_2 V_28 ,
T_2 V_29 , T_2 V_30 )
{
struct {
T_2 V_31 ;
T_3 V_32 ;
} * V_31 ;
T_2 V_33 = V_27 * V_28 * 4 ;
T_2 V_34 = sizeof( * V_31 ) + V_33 ;
if ( ! V_26 )
return - V_35 ;
V_31 = F_11 ( V_25 , V_34 ) ;
if ( F_12 ( V_31 == NULL ) ) {
F_13 ( L_1 ) ;
return - V_36 ;
}
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
memcpy ( & V_31 [ 1 ] , V_26 , V_33 ) ;
V_31 -> V_31 = F_14 ( V_37 ) ;
V_31 -> V_32 . V_38 = F_14 ( 0 ) ;
V_31 -> V_32 . V_27 = F_14 ( V_27 ) ;
V_31 -> V_32 . V_28 = F_14 ( V_28 ) ;
V_31 -> V_32 . V_29 = F_14 ( V_29 ) ;
V_31 -> V_32 . V_30 = F_14 ( V_30 ) ;
F_15 ( V_25 , V_34 ) ;
return 0 ;
}
int F_16 ( struct V_24 * V_25 ,
struct V_39 * V_40 ,
T_2 V_27 , T_2 V_28 ,
T_2 V_29 , T_2 V_30 )
{
struct V_41 V_42 ;
unsigned long V_43 ;
unsigned long V_44 ;
void * V_45 ;
bool V_46 ;
int V_47 ;
V_43 = 0 ;
V_44 = ( V_27 * V_28 * 4 + V_48 - 1 ) >> V_49 ;
V_47 = F_17 ( & V_40 -> V_50 , true , false , false , 0 ) ;
if ( F_12 ( V_47 != 0 ) ) {
F_13 ( L_2 ) ;
return - V_35 ;
}
V_47 = F_18 ( & V_40 -> V_50 , V_43 , V_44 , & V_42 ) ;
if ( F_12 ( V_47 != 0 ) )
goto V_51;
V_45 = F_19 ( & V_42 , & V_46 ) ;
V_47 = F_10 ( V_25 , V_45 , V_27 , V_28 ,
V_29 , V_30 ) ;
F_20 ( & V_42 ) ;
V_51:
F_21 ( & V_40 -> V_50 ) ;
return V_47 ;
}
void F_22 ( struct V_24 * V_25 ,
bool V_52 , int V_53 , int V_54 )
{
T_4 T_5 * V_55 = V_25 -> V_56 ;
T_6 V_57 ;
F_23 ( V_52 ? 1 : 0 , V_55 + V_58 ) ;
F_23 ( V_53 , V_55 + V_59 ) ;
F_23 ( V_54 , V_55 + V_60 ) ;
V_57 = F_24 ( V_55 + V_61 ) ;
F_23 ( ++ V_57 , V_55 + V_61 ) ;
}
int F_25 ( struct V_62 * V_21 , struct V_63 * V_64 ,
T_6 V_65 , T_6 V_27 , T_6 V_28 )
{
struct V_24 * V_25 = F_26 ( V_21 -> V_66 ) ;
struct V_67 * V_68 = F_27 ( V_64 ) -> V_68 ;
struct V_17 * V_18 = F_28 ( V_21 ) ;
struct V_69 * V_70 = NULL ;
struct V_39 * V_40 = NULL ;
int V_47 ;
if ( V_65 && ( V_27 != 64 || V_28 != 64 ) )
return - V_35 ;
if ( V_65 ) {
V_47 = F_29 ( V_25 , V_68 ,
V_65 , & V_70 , & V_40 ) ;
if ( V_47 ) {
F_13 ( L_3 , V_47 ) ;
return - V_35 ;
}
}
if ( V_70 && ! V_70 -> V_71 . V_26 ) {
F_13 ( L_4 ) ;
F_5 ( & V_70 ) ;
return - V_35 ;
}
if ( V_18 -> V_19 ) {
V_18 -> V_19 -> V_71 . V_21 = NULL ;
F_5 ( & V_18 -> V_19 ) ;
}
if ( V_18 -> V_20 )
F_6 ( & V_18 -> V_20 ) ;
if ( V_70 ) {
V_18 -> V_19 = V_70 ;
V_18 -> V_19 -> V_71 . V_21 = V_21 ;
V_18 -> V_72 = V_18 -> V_19 -> V_71 . V_73 ;
F_10 ( V_25 , V_70 -> V_71 . V_26 ,
64 , 64 , V_18 -> V_74 , V_18 -> V_75 ) ;
} else if ( V_40 ) {
V_18 -> V_20 = V_40 ;
V_47 = F_16 ( V_25 , V_40 , V_27 , V_28 ,
V_18 -> V_74 , V_18 -> V_75 ) ;
} else {
F_22 ( V_25 , false , 0 , 0 ) ;
return 0 ;
}
F_22 ( V_25 , true ,
V_18 -> V_76 + V_18 -> V_74 ,
V_18 -> V_77 + V_18 -> V_75 ) ;
return 0 ;
}
int F_30 ( struct V_62 * V_21 , int V_53 , int V_54 )
{
struct V_24 * V_25 = F_26 ( V_21 -> V_66 ) ;
struct V_17 * V_18 = F_28 ( V_21 ) ;
bool V_78 = V_18 -> V_19 || V_18 -> V_20 ? true : false ;
V_18 -> V_76 = V_53 + V_21 -> V_53 ;
V_18 -> V_77 = V_54 + V_21 -> V_54 ;
F_22 ( V_25 , V_78 ,
V_18 -> V_76 + V_18 -> V_74 ,
V_18 -> V_77 + V_18 -> V_75 ) ;
return 0 ;
}
void F_31 ( struct V_69 * V_79 ,
struct V_67 * V_68 ,
struct V_80 * V_81 ,
T_7 * V_82 )
{
struct V_41 V_42 ;
unsigned long V_43 ;
unsigned long V_44 ;
T_8 * V_83 ;
unsigned V_84 ;
void * V_45 ;
bool V_46 ;
struct V_85 {
T_7 V_82 ;
T_9 V_86 ;
} * V_31 ;
int V_8 , V_47 ;
V_31 = F_32 ( V_82 , struct V_85 , V_82 ) ;
if ( ! V_79 -> V_71 . V_26 )
return;
if ( V_31 -> V_86 . V_87 . V_88 != 0 || V_31 -> V_86 . V_87 . V_89 != 0 ) {
F_13 ( L_5 ) ;
return;
}
if ( V_31 -> V_82 . V_90 < 64 ) {
F_13 ( L_6 ) ;
return;
}
V_83 = ( T_8 * ) & V_31 [ 1 ] ;
V_84 = ( V_31 -> V_82 . V_90 - sizeof( T_9 ) ) /
sizeof( T_8 ) ;
if ( V_31 -> V_86 . V_91 . V_92 . V_93 % V_48 ||
V_83 -> V_53 != 0 || V_83 -> V_54 != 0 || V_83 -> V_94 != 0 ||
V_83 -> V_95 != 0 || V_83 -> V_96 != 0 || V_83 -> V_97 != 0 ||
V_83 -> V_98 != 1 || V_84 != 1 ) {
F_13 ( L_7 ) ;
F_13 ( L_8 ,
V_83 -> V_95 , V_83 -> V_96 , V_83 -> V_97 ,
V_83 -> V_53 , V_83 -> V_54 , V_83 -> V_94 ,
V_83 -> V_99 , V_83 -> V_100 , V_83 -> V_98 , V_84 ,
V_31 -> V_86 . V_91 . V_92 . V_93 ) ;
return;
}
V_43 = V_31 -> V_86 . V_91 . V_92 . V_93 >> V_49 ;
V_44 = ( 64 * 64 * 4 ) >> V_49 ;
V_47 = F_17 ( V_81 , true , false , false , 0 ) ;
if ( F_12 ( V_47 != 0 ) ) {
F_13 ( L_2 ) ;
return;
}
V_47 = F_18 ( V_81 , V_43 , V_44 , & V_42 ) ;
if ( F_12 ( V_47 != 0 ) )
goto V_51;
V_45 = F_19 ( & V_42 , & V_46 ) ;
if ( V_83 -> V_99 == 64 && V_31 -> V_86 . V_91 . V_101 == 64 * 4 ) {
memcpy ( V_79 -> V_71 . V_26 , V_45 , 64 * 64 * 4 ) ;
} else {
for ( V_8 = 0 ; V_8 < V_83 -> V_100 ; V_8 ++ )
memcpy ( V_79 -> V_71 . V_26 + V_8 * 64 ,
V_45 + V_8 * V_31 -> V_86 . V_91 . V_101 ,
V_83 -> V_99 * 4 ) ;
}
V_79 -> V_71 . V_73 ++ ;
F_20 ( & V_42 ) ;
V_51:
F_21 ( V_81 ) ;
}
void F_33 ( struct V_24 * V_25 )
{
struct V_102 * V_66 = V_25 -> V_66 ;
struct V_17 * V_18 ;
struct V_62 * V_21 ;
F_34 ( & V_66 -> V_103 . V_104 ) ;
F_35 (crtc, &dev->mode_config.crtc_list, head) {
V_18 = F_28 ( V_21 ) ;
if ( ! V_18 -> V_19 ||
V_18 -> V_72 == V_18 -> V_19 -> V_71 . V_73 )
continue;
V_18 -> V_72 = V_18 -> V_19 -> V_71 . V_73 ;
F_10 ( V_25 ,
V_18 -> V_19 -> V_71 . V_26 ,
64 , 64 , V_18 -> V_74 , V_18 -> V_75 ) ;
}
F_36 ( & V_66 -> V_103 . V_104 ) ;
}
int F_37 ( struct V_105 * V_106 ,
struct V_63 * V_64 ,
unsigned int * V_65 )
{
if ( V_65 )
* V_65 = 0 ;
return 0 ;
}
void F_38 ( struct V_105 * V_107 )
{
struct V_108 * V_109 =
F_39 ( V_107 ) ;
struct V_110 * V_111 = V_110 ( V_109 -> V_112 ) ;
F_34 ( & V_111 -> V_113 ) ;
F_40 ( & V_109 -> V_114 ) ;
F_36 ( & V_111 -> V_113 ) ;
F_41 ( & V_109 -> V_112 ) ;
F_42 ( V_107 ) ;
F_5 ( & V_109 -> V_70 ) ;
F_43 ( & V_109 -> V_50 . V_115 ) ;
F_44 ( V_109 ) ;
}
static int F_45 ( struct V_24 * V_25 ,
struct V_63 * V_64 ,
struct V_116 * V_107 ,
unsigned V_117 , unsigned V_118 ,
struct V_1 * V_119 ,
unsigned V_120 , int V_121 )
{
struct V_17 * V_122 [ V_123 ] ;
struct V_1 * V_124 ;
struct V_1 * V_125 ;
struct V_62 * V_21 ;
T_10 V_126 ;
int V_8 , V_127 ;
int V_47 = 0 ;
int V_13 , V_15 , V_14 , V_16 ;
struct {
T_7 V_82 ;
T_11 V_128 ;
} * V_31 ;
T_1 * V_129 ;
V_127 = 0 ;
F_35 (crtc, &dev_priv->dev->mode_config.crtc_list,
head) {
if ( V_21 -> V_106 != & V_107 -> V_50 )
continue;
V_122 [ V_127 ++ ] = F_28 ( V_21 ) ;
}
F_46 ( ! V_119 || ! V_120 ) ;
V_125 = F_47 ( sizeof( * V_125 ) * V_120 , V_130 ) ;
if ( F_12 ( V_125 == NULL ) ) {
F_13 ( L_9 ) ;
return - V_36 ;
}
V_126 = sizeof( * V_31 ) + sizeof( T_1 ) * V_120 ;
V_31 = F_47 ( V_126 , V_130 ) ;
if ( F_12 ( V_31 == NULL ) ) {
F_13 ( L_10 ) ;
V_47 = - V_36 ;
goto V_131;
}
V_129 = ( T_1 * ) & V_31 [ 1 ] ;
V_13 = V_119 -> V_10 ;
V_15 = V_119 -> V_11 ;
V_14 = V_119 -> y1 ;
V_16 = V_119 -> V_12 ;
for ( V_8 = 1 , V_124 = V_119 + V_121 ;
V_8 < V_120 ; V_8 ++ , V_124 += V_121 ) {
V_13 = F_3 ( int , V_13 , ( int ) V_124 -> V_10 ) ;
V_15 = F_2 ( int , V_15 , ( int ) V_124 -> V_11 ) ;
V_14 = F_3 ( int , V_14 , ( int ) V_124 -> y1 ) ;
V_16 = F_2 ( int , V_16 , ( int ) V_124 -> V_12 ) ;
}
memset ( V_31 , 0 , V_126 ) ;
V_31 -> V_82 . V_38 = F_14 ( V_132 ) ;
V_31 -> V_82 . V_90 = F_14 ( V_126 - sizeof( V_31 -> V_82 ) ) ;
V_31 -> V_128 . V_133 . V_13 = V_13 ;
V_31 -> V_128 . V_133 . V_15 = V_15 ;
V_31 -> V_128 . V_133 . V_14 = V_14 ;
V_31 -> V_128 . V_133 . V_16 = V_16 ;
V_124 = V_119 ;
for ( V_8 = 0 ; V_8 < V_120 ; V_8 ++ , V_124 += V_121 ) {
V_125 [ V_8 ] . V_10 = V_124 -> V_10 - V_13 ;
V_125 [ V_8 ] . V_11 = V_124 -> V_11 - V_13 ;
V_125 [ V_8 ] . y1 = V_124 -> y1 - V_14 ;
V_125 [ V_8 ] . V_12 = V_124 -> V_12 - V_14 ;
}
for ( V_8 = 0 ; V_8 < V_127 ; V_8 ++ ) {
struct V_17 * V_134 = V_122 [ V_8 ] ;
struct V_4 V_5 ;
int V_135 ;
V_5 . V_10 = V_13 - V_134 -> V_21 . V_53 ;
V_5 . y1 = V_14 - V_134 -> V_21 . V_54 ;
V_5 . V_11 = V_15 - V_134 -> V_21 . V_53 ;
V_5 . V_12 = V_16 - V_134 -> V_21 . V_54 ;
if ( V_5 . V_10 >= V_134 -> V_21 . V_136 . V_137 ||
V_5 . y1 >= V_134 -> V_21 . V_136 . V_138 ||
V_5 . V_11 <= 0 || V_5 . V_12 <= 0 )
continue;
V_31 -> V_128 . V_139 . V_13 = V_5 . V_10 ;
V_31 -> V_128 . V_139 . V_15 = V_5 . V_11 ;
V_31 -> V_128 . V_139 . V_14 = V_5 . y1 ;
V_31 -> V_128 . V_139 . V_16 = V_5 . V_12 ;
V_5 . V_11 = V_134 -> V_21 . V_136 . V_137 - V_5 . V_10 ;
V_5 . V_12 = V_134 -> V_21 . V_136 . V_138 - V_5 . y1 ;
V_5 . V_10 = 0 - V_5 . V_10 ;
V_5 . y1 = 0 - V_5 . y1 ;
V_31 -> V_128 . V_140 . V_141 = F_14 ( V_107 -> V_142 ) ;
V_31 -> V_128 . V_143 = V_134 -> V_134 ;
F_1 ( V_125 , V_120 , V_5 , V_129 , & V_135 ) ;
if ( V_135 == 0 )
continue;
V_126 = sizeof( * V_31 ) + sizeof( T_1 ) * V_135 ;
V_31 -> V_82 . V_90 = F_14 ( V_126 - sizeof( V_31 -> V_82 ) ) ;
V_47 = F_48 ( V_64 , V_25 , NULL , V_31 ,
V_126 , 0 , NULL ) ;
if ( F_12 ( V_47 != 0 ) )
break;
}
F_44 ( V_31 ) ;
V_131:
F_44 ( V_125 ) ;
return V_47 ;
}
int F_49 ( struct V_105 * V_107 ,
struct V_63 * V_64 ,
unsigned V_117 , unsigned V_118 ,
struct V_1 * V_119 ,
unsigned V_120 )
{
struct V_24 * V_25 = F_26 ( V_107 -> V_66 ) ;
struct V_110 * V_111 = V_110 ( V_64 -> V_112 ) ;
struct V_108 * V_109 =
F_39 ( V_107 ) ;
struct V_1 V_144 ;
int V_47 , V_121 = 1 ;
if ( F_12 ( V_109 -> V_112 != V_64 -> V_112 ) )
return - V_35 ;
if ( ! V_25 -> V_145 )
return - V_35 ;
V_47 = F_50 ( & V_111 -> V_146 , true ) ;
if ( F_12 ( V_47 != 0 ) )
return V_47 ;
if ( ! V_120 ) {
V_120 = 1 ;
V_119 = & V_144 ;
V_144 . V_10 = V_144 . y1 = 0 ;
V_144 . V_11 = V_107 -> V_27 ;
V_144 . V_12 = V_107 -> V_28 ;
} else if ( V_117 & V_147 ) {
V_120 /= 2 ;
V_121 = 2 ;
}
V_47 = F_45 ( V_25 , V_64 , & V_109 -> V_50 ,
V_117 , V_118 ,
V_119 , V_120 , V_121 ) ;
F_51 ( & V_111 -> V_146 ) ;
return 0 ;
}
static int F_52 ( struct V_24 * V_25 ,
struct V_63 * V_64 ,
struct V_69 * V_70 ,
struct V_116 * * V_148 ,
const struct V_149
* V_150 )
{
struct V_102 * V_66 = V_25 -> V_66 ;
struct V_108 * V_109 ;
enum V_151 V_152 ;
struct V_110 * V_111 = V_110 ( V_64 -> V_112 ) ;
int V_47 ;
if ( ! V_25 -> V_145 )
return - V_153 ;
if ( F_12 ( ! V_70 -> V_154 ) )
return - V_35 ;
if ( F_12 ( V_70 -> V_155 [ 0 ] != 1 ||
V_70 -> V_156 != 1 ||
V_70 -> V_157 [ 0 ] . V_27 < V_150 -> V_27 ||
V_70 -> V_157 [ 0 ] . V_28 < V_150 -> V_28 ||
V_70 -> V_157 [ 0 ] . V_158 != 1 ) ) {
F_13 ( L_11
L_12 ) ;
return - V_35 ;
}
switch ( V_150 -> V_158 ) {
case 32 :
V_152 = V_159 ;
break;
case 24 :
V_152 = V_160 ;
break;
case 16 :
V_152 = V_161 ;
break;
case 15 :
V_152 = V_162 ;
break;
case 8 :
V_152 = V_163 ;
break;
default:
F_13 ( L_13 , V_150 -> V_158 ) ;
return - V_35 ;
}
if ( F_12 ( V_152 != V_70 -> V_152 ) ) {
F_13 ( L_14 ) ;
return - V_35 ;
}
V_109 = F_47 ( sizeof( * V_109 ) , V_130 ) ;
if ( ! V_109 ) {
V_47 = - V_36 ;
goto V_164;
}
V_47 = F_53 ( V_66 , & V_109 -> V_50 . V_50 ,
& V_165 ) ;
if ( V_47 )
goto V_166;
if ( ! F_54 ( V_70 ) ) {
F_13 ( L_15 , V_70 ) ;
goto V_167;
}
V_109 -> V_50 . V_50 . V_168 = V_150 -> V_169 ;
V_109 -> V_50 . V_50 . V_170 [ 0 ] = V_150 -> V_101 ;
V_109 -> V_50 . V_50 . V_158 = V_150 -> V_158 ;
V_109 -> V_50 . V_50 . V_27 = V_150 -> V_27 ;
V_109 -> V_50 . V_50 . V_28 = V_150 -> V_28 ;
V_109 -> V_70 = V_70 ;
V_109 -> V_50 . V_142 = V_150 -> V_65 ;
V_109 -> V_112 = F_55 ( V_64 -> V_112 ) ;
F_34 ( & V_111 -> V_113 ) ;
F_56 ( & V_109 -> V_114 , & V_111 -> V_171 ) ;
F_36 ( & V_111 -> V_113 ) ;
* V_148 = & V_109 -> V_50 ;
return 0 ;
V_167:
F_42 ( & V_109 -> V_50 . V_50 ) ;
V_166:
F_44 ( V_109 ) ;
V_164:
return V_47 ;
}
void F_57 ( struct V_105 * V_107 )
{
struct V_172 * V_173 =
F_58 ( V_107 ) ;
F_42 ( V_107 ) ;
F_6 ( & V_173 -> V_174 ) ;
F_43 ( & V_173 -> V_50 . V_115 ) ;
F_44 ( V_173 ) ;
}
static int F_59 ( struct V_24 * V_25 ,
struct V_116 * V_107 ,
unsigned V_117 , unsigned V_118 ,
struct V_1 * V_119 ,
unsigned V_120 , int V_175 )
{
T_10 V_126 ;
int V_8 ;
struct {
T_6 V_82 ;
T_12 V_128 ;
} * V_31 ;
V_126 = sizeof( * V_31 ) * V_120 ;
V_31 = F_11 ( V_25 , V_126 ) ;
if ( F_12 ( V_31 == NULL ) ) {
F_13 ( L_1 ) ;
return - V_36 ;
}
memset ( V_31 , 0 , V_126 ) ;
for ( V_8 = 0 ; V_8 < V_120 ; V_8 ++ , V_119 += V_175 ) {
V_31 [ V_8 ] . V_82 = F_14 ( V_176 ) ;
V_31 [ V_8 ] . V_128 . V_53 = F_14 ( V_119 -> V_10 ) ;
V_31 [ V_8 ] . V_128 . V_54 = F_14 ( V_119 -> y1 ) ;
V_31 [ V_8 ] . V_128 . V_27 = F_14 ( V_119 -> V_11 - V_119 -> V_10 ) ;
V_31 [ V_8 ] . V_128 . V_28 = F_14 ( V_119 -> V_12 - V_119 -> y1 ) ;
}
F_15 ( V_25 , V_126 ) ;
return 0 ;
}
static int F_60 ( struct V_63 * V_64 ,
struct V_24 * V_25 ,
struct V_116 * V_107 )
{
int V_158 = V_107 -> V_50 . V_158 ;
T_10 V_126 ;
int V_47 ;
struct {
T_6 V_82 ;
T_13 V_128 ;
} * V_31 ;
if ( V_158 == 32 )
V_158 = 24 ;
V_126 = sizeof( * V_31 ) ;
V_31 = F_61 ( V_126 , V_130 ) ;
if ( F_12 ( V_31 == NULL ) ) {
F_13 ( L_16 ) ;
return - V_36 ;
}
memset ( V_31 , 0 , V_126 ) ;
V_31 -> V_82 = V_177 ;
V_31 -> V_128 . V_152 . V_178 = V_107 -> V_50 . V_168 ;
V_31 -> V_128 . V_152 . V_179 = V_158 ;
V_31 -> V_128 . V_152 . V_180 = 0 ;
V_31 -> V_128 . V_181 = V_107 -> V_50 . V_170 [ 0 ] ;
V_31 -> V_128 . V_92 . V_182 = V_107 -> V_142 ;
V_31 -> V_128 . V_92 . V_93 = 0 ;
V_47 = F_48 ( V_64 , V_25 , NULL , V_31 ,
V_126 , 0 , NULL ) ;
F_44 ( V_31 ) ;
return V_47 ;
}
static int F_62 ( struct V_63 * V_64 ,
struct V_24 * V_25 ,
struct V_116 * V_107 ,
unsigned V_117 , unsigned V_118 ,
struct V_1 * V_119 ,
unsigned V_120 , int V_175 )
{
struct V_17 * V_122 [ V_123 ] ;
struct V_1 * V_124 ;
int V_8 , V_9 , V_127 , V_47 ;
struct V_62 * V_21 ;
T_10 V_126 ;
struct {
T_6 V_82 ;
T_14 V_128 ;
} * V_129 ;
V_47 = F_60 ( V_64 , V_25 , V_107 ) ;
if ( F_12 ( V_47 != 0 ) )
return V_47 ;
V_126 = sizeof( * V_129 ) * V_120 ;
V_129 = F_61 ( V_126 , V_130 ) ;
if ( F_12 ( V_129 == NULL ) ) {
F_13 ( L_16 ) ;
return - V_36 ;
}
V_127 = 0 ;
F_35 (crtc, &dev_priv->dev->mode_config.crtc_list, head) {
if ( V_21 -> V_106 != & V_107 -> V_50 )
continue;
V_122 [ V_127 ++ ] = F_28 ( V_21 ) ;
}
for ( V_9 = 0 ; V_9 < V_127 ; V_9 ++ ) {
struct V_17 * V_134 = V_122 [ V_9 ] ;
int V_183 = 0 ;
V_124 = V_119 ;
for ( V_8 = 0 ; V_8 < V_120 ; V_8 ++ , V_124 += V_175 ) {
int V_184 = V_124 -> V_10 - V_134 -> V_21 . V_53 ;
int V_185 = V_124 -> y1 - V_134 -> V_21 . V_54 ;
int V_186 = V_124 -> V_11 - V_134 -> V_21 . V_53 ;
int V_187 = V_124 -> V_12 - V_134 -> V_21 . V_54 ;
int V_188 , V_189 ;
if ( V_184 >= V_134 -> V_21 . V_136 . V_137 ||
V_185 >= V_134 -> V_21 . V_136 . V_138 ||
V_186 <= 0 || V_187 <= 0 )
continue;
V_186 = F_3 ( int , V_186 , V_134 -> V_21 . V_136 . V_137 ) ;
V_187 = F_3 ( int , V_187 , V_134 -> V_21 . V_136 . V_138 ) ;
V_188 = F_3 ( int , V_184 , 0 ) ;
V_189 = F_3 ( int , V_185 , 0 ) ;
V_129 [ V_183 ] . V_82 = V_190 ;
V_129 [ V_183 ] . V_128 . V_143 = V_134 -> V_134 ;
V_129 [ V_183 ] . V_128 . V_191 . V_53 = V_124 -> V_10 - V_188 ;
V_129 [ V_183 ] . V_128 . V_191 . V_54 = V_124 -> y1 - V_189 ;
V_129 [ V_183 ] . V_128 . V_139 . V_13 = V_184 - V_188 ;
V_129 [ V_183 ] . V_128 . V_139 . V_14 = V_185 - V_189 ;
V_129 [ V_183 ] . V_128 . V_139 . V_15 = V_186 ;
V_129 [ V_183 ] . V_128 . V_139 . V_16 = V_187 ;
V_183 ++ ;
}
if ( V_183 == 0 )
continue;
V_126 = sizeof( * V_129 ) * V_183 ;
V_47 = F_48 ( V_64 , V_25 , NULL , V_129 ,
V_126 , 0 , NULL ) ;
if ( F_12 ( V_47 != 0 ) )
break;
}
F_44 ( V_129 ) ;
return V_47 ;
}
int F_63 ( struct V_105 * V_107 ,
struct V_63 * V_64 ,
unsigned V_117 , unsigned V_118 ,
struct V_1 * V_119 ,
unsigned V_120 )
{
struct V_24 * V_25 = F_26 ( V_107 -> V_66 ) ;
struct V_110 * V_111 = V_110 ( V_64 -> V_112 ) ;
struct V_172 * V_173 =
F_58 ( V_107 ) ;
struct V_1 V_144 ;
int V_47 , V_175 = 1 ;
V_47 = F_50 ( & V_111 -> V_146 , true ) ;
if ( F_12 ( V_47 != 0 ) )
return V_47 ;
if ( ! V_120 ) {
V_120 = 1 ;
V_119 = & V_144 ;
V_144 . V_10 = V_144 . y1 = 0 ;
V_144 . V_11 = V_107 -> V_27 ;
V_144 . V_12 = V_107 -> V_28 ;
} else if ( V_117 & V_147 ) {
V_120 /= 2 ;
V_175 = 2 ;
}
if ( V_25 -> V_192 ) {
V_47 = F_59 ( V_25 , & V_173 -> V_50 ,
V_117 , V_118 ,
V_119 , V_120 , V_175 ) ;
} else {
V_47 = F_62 ( V_64 , V_25 , & V_173 -> V_50 ,
V_117 , V_118 ,
V_119 , V_120 , V_175 ) ;
}
F_51 ( & V_111 -> V_146 ) ;
return V_47 ;
}
static int F_64 ( struct V_116 * V_193 )
{
struct V_24 * V_25 = F_26 ( V_193 -> V_50 . V_66 ) ;
struct V_172 * V_173 =
F_58 ( & V_193 -> V_50 ) ;
int V_47 ;
F_46 ( V_25 -> V_145 ) ;
F_65 ( V_25 ) ;
V_47 = F_66 ( V_25 , V_173 -> V_174 , true , false ) ;
F_67 ( V_25 ) ;
F_68 ( V_47 != 0 ) ;
return 0 ;
}
static int F_69 ( struct V_116 * V_193 )
{
struct V_24 * V_25 = F_26 ( V_193 -> V_50 . V_66 ) ;
struct V_172 * V_173 =
F_58 ( & V_193 -> V_50 ) ;
if ( ! V_173 -> V_174 ) {
F_68 ( ! V_173 -> V_174 ) ;
return 0 ;
}
return F_70 ( V_25 , V_173 -> V_174 , false ) ;
}
static int F_71 ( struct V_24 * V_25 ,
struct V_39 * V_40 ,
struct V_116 * * V_148 ,
const struct V_149
* V_150 )
{
struct V_102 * V_66 = V_25 -> V_66 ;
struct V_172 * V_173 ;
unsigned int V_194 ;
int V_47 ;
V_194 = V_150 -> V_28 * V_150 -> V_101 ;
if ( F_12 ( V_194 > V_40 -> V_50 . V_195 * V_48 ) ) {
F_13 ( L_17
L_12 ) ;
return - V_35 ;
}
if ( V_25 -> V_145 ) {
switch ( V_150 -> V_158 ) {
case 32 :
case 24 :
if ( V_150 -> V_169 == 32 )
break;
F_13 ( L_18 ,
V_150 -> V_158 , V_150 -> V_169 ) ;
return - V_35 ;
case 16 :
case 15 :
if ( V_150 -> V_169 == 16 )
break;
F_13 ( L_18 ,
V_150 -> V_158 , V_150 -> V_169 ) ;
return - V_35 ;
default:
F_13 ( L_13 , V_150 -> V_158 ) ;
return - V_35 ;
}
}
V_173 = F_47 ( sizeof( * V_173 ) , V_130 ) ;
if ( ! V_173 ) {
V_47 = - V_36 ;
goto V_164;
}
V_47 = F_53 ( V_66 , & V_173 -> V_50 . V_50 ,
& V_196 ) ;
if ( V_47 )
goto V_166;
if ( ! F_72 ( V_40 ) ) {
F_13 ( L_19 , V_40 ) ;
goto V_167;
}
V_173 -> V_50 . V_50 . V_168 = V_150 -> V_169 ;
V_173 -> V_50 . V_50 . V_170 [ 0 ] = V_150 -> V_101 ;
V_173 -> V_50 . V_50 . V_158 = V_150 -> V_158 ;
V_173 -> V_50 . V_50 . V_27 = V_150 -> V_27 ;
V_173 -> V_50 . V_50 . V_28 = V_150 -> V_28 ;
if ( ! V_25 -> V_145 ) {
V_173 -> V_50 . V_197 = F_64 ;
V_173 -> V_50 . V_198 = F_69 ;
}
V_173 -> V_50 . V_40 = true ;
V_173 -> V_174 = V_40 ;
V_173 -> V_50 . V_142 = V_150 -> V_65 ;
* V_148 = & V_173 -> V_50 ;
return 0 ;
V_167:
F_42 ( & V_173 -> V_50 . V_50 ) ;
V_166:
F_44 ( V_173 ) ;
V_164:
return V_47 ;
}
static struct V_105 * F_73 ( struct V_102 * V_66 ,
struct V_63 * V_64 ,
struct V_199 * V_200 )
{
struct V_24 * V_25 = F_26 ( V_66 ) ;
struct V_67 * V_68 = F_27 ( V_64 ) -> V_68 ;
struct V_116 * V_193 = NULL ;
struct V_69 * V_70 = NULL ;
struct V_39 * V_81 = NULL ;
struct V_201 * V_115 ;
struct V_149 V_150 ;
int V_47 ;
V_150 . V_27 = V_200 -> V_27 ;
V_150 . V_28 = V_200 -> V_28 ;
V_150 . V_101 = V_200 -> V_170 [ 0 ] ;
V_150 . V_65 = V_200 -> V_202 [ 0 ] ;
F_74 ( V_200 -> V_203 , & V_150 . V_158 ,
& V_150 . V_169 ) ;
if ( ! F_75 ( V_25 ,
V_150 . V_101 ,
V_150 . V_28 ) ) {
F_13 ( L_20 ) ;
return F_76 ( - V_36 ) ;
}
V_115 = F_77 ( V_68 , V_150 . V_65 ) ;
if ( F_12 ( V_115 == NULL ) ) {
F_13 ( L_21 ) ;
return F_76 ( - V_204 ) ;
}
V_47 = F_29 ( V_25 , V_68 ,
V_150 . V_65 ,
& V_70 , & V_81 ) ;
if ( V_47 )
goto V_205;
if ( V_81 )
V_47 = F_71 ( V_25 , V_81 , & V_193 ,
& V_150 ) ;
else if ( V_70 )
V_47 = F_52 ( V_25 , V_64 ,
V_70 , & V_193 , & V_150 ) ;
else
F_78 () ;
V_205:
if ( V_81 )
F_6 ( & V_81 ) ;
if ( V_70 )
F_5 ( & V_70 ) ;
if ( V_47 ) {
F_13 ( L_22 , V_47 ) ;
F_43 ( & V_115 ) ;
return F_76 ( V_47 ) ;
} else
V_193 -> V_115 = V_115 ;
return & V_193 -> V_50 ;
}
int F_79 ( struct V_24 * V_25 ,
struct V_63 * V_64 ,
struct V_116 * V_193 ,
struct V_69 * V_70 ,
T_6 V_141 ,
T_15 V_206 , T_15 V_207 ,
struct V_208 * V_119 ,
T_6 V_120 )
{
struct V_17 * V_122 [ V_123 ] ;
struct V_1 * V_125 ;
struct V_62 * V_21 ;
T_10 V_126 ;
int V_8 , V_9 , V_127 ;
int V_47 = 0 ;
int V_13 , V_15 , V_14 , V_16 ;
struct {
T_7 V_82 ;
T_11 V_128 ;
} * V_31 ;
T_1 * V_129 ;
V_127 = 0 ;
F_35 (crtc, &dev_priv->dev->mode_config.crtc_list, head) {
if ( V_21 -> V_106 != & V_193 -> V_50 )
continue;
V_122 [ V_127 ++ ] = F_28 ( V_21 ) ;
}
F_46 ( V_70 == NULL ) ;
F_46 ( ! V_119 || ! V_120 ) ;
V_125 = F_47 ( sizeof( * V_125 ) * V_120 , V_130 ) ;
if ( F_12 ( V_125 == NULL ) ) {
F_13 ( L_9 ) ;
return - V_36 ;
}
V_126 = sizeof( * V_31 ) + sizeof( T_1 ) * V_120 ;
V_31 = F_61 ( V_126 , V_130 ) ;
if ( F_12 ( V_31 == NULL ) ) {
F_13 ( L_23 ) ;
V_47 = - V_36 ;
goto V_131;
}
V_13 = V_119 -> V_53 ;
V_15 = V_119 -> V_53 + V_119 -> V_99 ;
V_14 = V_119 -> V_54 ;
V_16 = V_119 -> V_54 + V_119 -> V_100 ;
for ( V_8 = 1 ; V_8 < V_120 ; V_8 ++ ) {
V_13 = F_3 ( int , V_13 , ( int ) V_119 [ V_8 ] . V_53 ) ;
V_15 = F_2 ( int , V_15 , ( int ) V_119 [ V_8 ] . V_53 + V_119 [ V_8 ] . V_99 ) ;
V_14 = F_3 ( int , V_14 , ( int ) V_119 [ V_8 ] . V_54 ) ;
V_16 = F_2 ( int , V_16 , ( int ) V_119 [ V_8 ] . V_54 + V_119 [ V_8 ] . V_100 ) ;
}
memset ( V_31 , 0 , V_126 ) ;
V_31 -> V_82 . V_38 = F_14 ( V_132 ) ;
V_129 = ( T_1 * ) & V_31 [ 1 ] ;
V_31 -> V_128 . V_133 . V_13 = V_13 ;
V_31 -> V_128 . V_133 . V_15 = V_15 ;
V_31 -> V_128 . V_133 . V_14 = V_14 ;
V_31 -> V_128 . V_133 . V_16 = V_16 ;
for ( V_8 = 0 ; V_8 < V_120 ; V_8 ++ ) {
V_125 [ V_8 ] . V_10 = V_119 [ V_8 ] . V_53 - V_13 ;
V_125 [ V_8 ] . V_11 = V_119 [ V_8 ] . V_53 + V_119 [ V_8 ] . V_99 - V_13 ;
V_125 [ V_8 ] . y1 = V_119 [ V_8 ] . V_54 - V_14 ;
V_125 [ V_8 ] . V_12 = V_119 [ V_8 ] . V_54 + V_119 [ V_8 ] . V_100 - V_14 ;
}
for ( V_9 = 0 ; V_9 < V_127 ; V_9 ++ ) {
struct V_17 * V_134 = V_122 [ V_9 ] ;
struct V_4 V_5 ;
int V_135 ;
V_5 . V_10 = V_13 + V_206 - V_134 -> V_21 . V_53 ;
V_5 . y1 = V_14 + V_207 - V_134 -> V_21 . V_54 ;
V_5 . V_11 = V_15 + V_206 - V_134 -> V_21 . V_53 ;
V_5 . V_12 = V_16 + V_207 - V_134 -> V_21 . V_54 ;
if ( V_5 . V_10 >= V_134 -> V_21 . V_136 . V_137 ||
V_5 . y1 >= V_134 -> V_21 . V_136 . V_138 ||
V_5 . V_11 <= 0 || V_5 . V_12 <= 0 )
continue;
V_31 -> V_128 . V_139 . V_13 = V_5 . V_10 ;
V_31 -> V_128 . V_139 . V_15 = V_5 . V_11 ;
V_31 -> V_128 . V_139 . V_14 = V_5 . y1 ;
V_31 -> V_128 . V_139 . V_16 = V_5 . V_12 ;
V_5 . V_11 = V_134 -> V_21 . V_136 . V_137 - V_5 . V_10 ;
V_5 . V_12 = V_134 -> V_21 . V_136 . V_138 - V_5 . y1 ;
V_5 . V_10 = 0 - V_5 . V_10 ;
V_5 . y1 = 0 - V_5 . y1 ;
V_31 -> V_128 . V_140 . V_141 = V_141 ;
V_31 -> V_128 . V_143 = V_134 -> V_134 ;
F_1 ( V_125 , V_120 , V_5 , V_129 , & V_135 ) ;
if ( V_135 == 0 )
continue;
V_126 = sizeof( * V_31 ) + sizeof( T_1 ) * V_135 ;
V_31 -> V_82 . V_90 = F_14 ( V_126 - sizeof( V_31 -> V_82 ) ) ;
V_47 = F_48 ( V_64 , V_25 , NULL , V_31 ,
V_126 , 0 , NULL ) ;
if ( F_12 ( V_47 != 0 ) )
break;
}
F_44 ( V_31 ) ;
V_131:
F_44 ( V_125 ) ;
return V_47 ;
}
int F_80 ( struct V_24 * V_25 ,
struct V_63 * V_64 ,
struct V_116 * V_193 ,
struct V_209 T_16 * V_210 ,
struct V_208 * V_119 ,
T_6 V_120 )
{
struct V_172 * V_173 =
F_58 ( & V_193 -> V_50 ) ;
struct V_39 * V_40 = V_173 -> V_174 ;
struct V_17 * V_122 [ V_123 ] ;
struct V_62 * V_21 ;
T_10 V_126 ;
int V_8 , V_9 , V_47 , V_127 , V_211 ;
struct {
T_6 V_82 ;
T_13 V_128 ;
} * V_31 ;
struct {
T_6 V_82 ;
T_17 V_128 ;
} * V_129 ;
V_127 = 0 ;
F_35 (crtc, &dev_priv->dev->mode_config.crtc_list, head) {
if ( V_21 -> V_106 != & V_193 -> V_50 )
continue;
V_122 [ V_127 ++ ] = F_28 ( V_21 ) ;
}
F_46 ( V_40 == NULL ) ;
F_46 ( ! V_119 || ! V_120 ) ;
V_126 = sizeof( * V_31 ) + sizeof( * V_129 ) * V_120 * V_127 ;
V_31 = F_61 ( V_126 , V_130 ) ;
if ( F_12 ( V_31 == NULL ) ) {
F_13 ( L_23 ) ;
return - V_36 ;
}
memset ( V_31 , 0 , V_126 ) ;
V_31 -> V_82 = V_177 ;
V_31 -> V_128 . V_152 . V_178 = V_193 -> V_50 . V_168 ;
V_31 -> V_128 . V_152 . V_179 = V_193 -> V_50 . V_158 ;
V_31 -> V_128 . V_152 . V_180 = 0 ;
V_31 -> V_128 . V_181 = V_193 -> V_50 . V_170 [ 0 ] ;
V_31 -> V_128 . V_92 . V_182 = V_193 -> V_142 ;
V_31 -> V_128 . V_92 . V_93 = 0 ;
V_129 = ( void * ) & V_31 [ 1 ] ;
V_211 = 0 ;
for ( V_8 = 0 ; V_8 < V_127 ; V_8 ++ ) {
struct V_208 * V_212 = V_119 ;
for ( V_9 = 0 ; V_9 < V_120 ; V_9 ++ , V_212 ++ ) {
int V_184 = V_212 -> V_53 - V_122 [ V_8 ] -> V_21 . V_53 ;
int V_186 = V_212 -> V_53 - V_122 [ V_8 ] -> V_21 . V_53 + V_212 -> V_99 ;
int V_185 = V_212 -> V_54 - V_122 [ V_8 ] -> V_21 . V_54 ;
int V_187 = V_212 -> V_54 - V_122 [ V_8 ] -> V_21 . V_54 + V_212 -> V_100 ;
int V_213 = V_212 -> V_53 ;
int V_214 = V_212 -> V_54 ;
if ( V_184 < 0 )
V_213 += - V_184 ;
if ( V_185 < 0 )
V_214 += - V_185 ;
V_184 = F_81 ( V_184 , 0 ) ;
V_185 = F_81 ( V_185 , 0 ) ;
V_186 = F_82 ( V_186 , V_122 [ V_8 ] -> V_21 . V_136 . V_137 ) ;
V_187 = F_82 ( V_187 , V_122 [ V_8 ] -> V_21 . V_136 . V_138 ) ;
if ( V_184 >= V_122 [ V_8 ] -> V_21 . V_136 . V_137 ||
V_185 >= V_122 [ V_8 ] -> V_21 . V_136 . V_138 ||
V_186 <= 0 || V_187 <= 0 )
continue;
V_129 [ V_211 ] . V_82 = V_215 ;
V_129 [ V_211 ] . V_128 . V_216 = V_122 [ V_8 ] -> V_134 ;
V_129 [ V_211 ] . V_128 . V_217 . V_53 = V_213 ;
V_129 [ V_211 ] . V_128 . V_217 . V_54 = V_214 ;
V_129 [ V_211 ] . V_128 . V_133 . V_13 = V_184 ;
V_129 [ V_211 ] . V_128 . V_133 . V_14 = V_185 ;
V_129 [ V_211 ] . V_128 . V_133 . V_15 = V_186 ;
V_129 [ V_211 ] . V_128 . V_133 . V_16 = V_187 ;
V_211 ++ ;
}
}
V_126 = sizeof( * V_31 ) + sizeof( * V_129 ) * V_211 ;
V_47 = F_48 ( V_64 , V_25 , NULL , V_31 , V_126 ,
0 , V_210 ) ;
F_44 ( V_31 ) ;
return V_47 ;
}
int F_83 ( struct V_24 * V_25 )
{
struct V_102 * V_66 = V_25 -> V_66 ;
int V_47 ;
F_84 ( V_66 ) ;
V_66 -> V_103 . V_218 = & V_219 ;
V_66 -> V_103 . V_220 = 1 ;
V_66 -> V_103 . V_221 = 1 ;
V_66 -> V_103 . V_222 = 8192 ;
V_66 -> V_103 . V_223 = 8192 ;
V_47 = F_85 ( V_25 ) ;
if ( V_47 )
( void ) F_86 ( V_25 ) ;
return 0 ;
}
int F_87 ( struct V_24 * V_25 )
{
F_88 ( V_25 -> V_66 ) ;
if ( V_25 -> V_145 )
F_89 ( V_25 ) ;
else
F_90 ( V_25 ) ;
return 0 ;
}
int F_91 ( struct V_102 * V_66 , void * V_224 ,
struct V_63 * V_64 )
{
struct V_225 * V_226 = V_224 ;
struct V_17 * V_18 ;
struct V_227 * V_228 ;
struct V_62 * V_21 ;
int V_47 = 0 ;
F_34 ( & V_66 -> V_103 . V_104 ) ;
if ( V_226 -> V_117 & V_229 ) {
F_35 (crtc, &dev->mode_config.crtc_list, head) {
V_18 = F_28 ( V_21 ) ;
V_18 -> V_74 = V_226 -> V_230 ;
V_18 -> V_75 = V_226 -> V_231 ;
}
F_36 ( & V_66 -> V_103 . V_104 ) ;
return 0 ;
}
V_228 = F_92 ( V_66 , V_226 -> V_232 , V_233 ) ;
if ( ! V_228 ) {
V_47 = - V_35 ;
goto V_148;
}
V_21 = F_93 ( V_228 ) ;
V_18 = F_28 ( V_21 ) ;
V_18 -> V_74 = V_226 -> V_230 ;
V_18 -> V_75 = V_226 -> V_231 ;
V_148:
F_36 ( & V_66 -> V_103 . V_104 ) ;
return V_47 ;
}
int F_94 ( struct V_24 * F_26 ,
unsigned V_27 , unsigned V_28 , unsigned V_101 ,
unsigned V_169 , unsigned V_158 )
{
if ( F_26 -> V_234 & V_235 )
F_95 ( F_26 , V_236 , V_101 ) ;
else if ( F_96 ( F_26 ) )
F_23 ( V_101 , F_26 -> V_56 + V_237 ) ;
F_95 ( F_26 , V_238 , V_27 ) ;
F_95 ( F_26 , V_239 , V_28 ) ;
F_95 ( F_26 , V_240 , V_169 ) ;
if ( F_97 ( F_26 , V_241 ) != V_158 ) {
F_13 ( L_24 ,
V_158 , V_169 , F_97 ( F_26 , V_241 ) ) ;
return - V_35 ;
}
return 0 ;
}
int F_98 ( struct V_24 * F_26 )
{
struct V_242 * V_243 ;
T_6 V_8 ;
F_26 -> V_244 = F_97 ( F_26 , V_238 ) ;
F_26 -> V_245 = F_97 ( F_26 , V_239 ) ;
F_26 -> V_246 = F_97 ( F_26 , V_240 ) ;
if ( F_26 -> V_234 & V_235 )
F_26 -> V_247 =
F_97 ( F_26 , V_236 ) ;
else if ( F_96 ( F_26 ) )
F_26 -> V_247 = F_24 ( F_26 -> V_56 +
V_237 ) ;
if ( ! ( F_26 -> V_234 & V_248 ) )
return 0 ;
F_26 -> V_249 = F_97 ( F_26 ,
V_250 ) ;
if ( F_26 -> V_249 == 0 )
F_26 -> V_249 = 1 ;
for ( V_8 = 0 ; V_8 < F_26 -> V_249 ; ++ V_8 ) {
V_243 = & F_26 -> V_251 [ V_8 ] ;
F_95 ( F_26 , V_252 , V_8 ) ;
V_243 -> V_253 = F_97 ( F_26 , V_254 ) ;
V_243 -> V_255 = F_97 ( F_26 , V_256 ) ;
V_243 -> V_257 = F_97 ( F_26 , V_258 ) ;
V_243 -> V_27 = F_97 ( F_26 , V_259 ) ;
V_243 -> V_28 = F_97 ( F_26 , V_260 ) ;
F_95 ( F_26 , V_252 , V_261 ) ;
if ( V_8 == 0 && F_26 -> V_249 == 1 &&
V_243 -> V_27 == 0 && V_243 -> V_28 == 0 ) {
V_243 -> V_27 = F_26 -> V_244 - V_243 -> V_255 ;
V_243 -> V_28 = F_26 -> V_245 - V_243 -> V_257 ;
}
}
return 0 ;
}
int F_99 ( struct V_24 * F_26 )
{
struct V_242 * V_243 ;
T_6 V_8 ;
F_95 ( F_26 , V_238 , F_26 -> V_244 ) ;
F_95 ( F_26 , V_239 , F_26 -> V_245 ) ;
F_95 ( F_26 , V_240 , F_26 -> V_246 ) ;
if ( F_26 -> V_234 & V_235 )
F_95 ( F_26 , V_236 ,
F_26 -> V_247 ) ;
else if ( F_96 ( F_26 ) )
F_23 ( F_26 -> V_247 ,
F_26 -> V_56 + V_237 ) ;
if ( ! ( F_26 -> V_234 & V_248 ) )
return 0 ;
for ( V_8 = 0 ; V_8 < F_26 -> V_249 ; ++ V_8 ) {
V_243 = & F_26 -> V_251 [ V_8 ] ;
F_95 ( F_26 , V_252 , V_8 ) ;
F_95 ( F_26 , V_254 , V_243 -> V_253 ) ;
F_95 ( F_26 , V_256 , V_243 -> V_255 ) ;
F_95 ( F_26 , V_258 , V_243 -> V_257 ) ;
F_95 ( F_26 , V_259 , V_243 -> V_27 ) ;
F_95 ( F_26 , V_260 , V_243 -> V_28 ) ;
F_95 ( F_26 , V_252 , V_261 ) ;
}
return 0 ;
}
bool F_75 ( struct V_24 * V_25 ,
T_6 V_101 ,
T_6 V_28 )
{
return ( ( V_262 ) V_101 * ( V_262 ) V_28 ) < ( V_262 ) V_25 -> V_263 ;
}
T_2 F_100 ( struct V_102 * V_66 , int V_21 )
{
return 0 ;
}
int F_101 ( struct V_102 * V_66 , int V_21 )
{
return - V_153 ;
}
void F_102 ( struct V_102 * V_66 , int V_21 )
{
}
int F_103 ( struct V_24 * V_25 , unsigned V_135 ,
struct V_208 * V_2 )
{
struct V_102 * V_66 = V_25 -> V_66 ;
struct V_17 * V_18 ;
struct V_264 * V_265 ;
F_34 ( & V_66 -> V_103 . V_104 ) ;
#if 0
{
unsigned int i;
DRM_INFO("%s: new layout ", __func__);
for (i = 0; i < num; i++)
DRM_INFO("(%i, %i %ux%u) ", rects[i].x, rects[i].y,
rects[i].w, rects[i].h);
DRM_INFO("\n");
}
#endif
F_35 (con, &dev->mode_config.connector_list, head) {
V_18 = F_104 ( V_265 ) ;
if ( V_135 > V_18 -> V_134 ) {
V_18 -> V_266 = V_2 [ V_18 -> V_134 ] . V_99 ;
V_18 -> V_267 = V_2 [ V_18 -> V_134 ] . V_100 ;
V_18 -> V_268 = true ;
V_18 -> V_269 = V_2 [ V_18 -> V_134 ] . V_53 ;
V_18 -> V_270 = V_2 [ V_18 -> V_134 ] . V_54 ;
} else {
V_18 -> V_266 = 800 ;
V_18 -> V_267 = 600 ;
V_18 -> V_268 = false ;
}
V_265 -> V_271 = F_105 ( V_265 , true ) ;
}
F_36 ( & V_66 -> V_103 . V_104 ) ;
return 0 ;
}
void F_106 ( struct V_62 * V_21 )
{
}
void F_107 ( struct V_62 * V_21 )
{
}
void F_108 ( struct V_62 * V_21 ,
T_18 * V_272 , T_18 * V_273 , T_18 * V_274 ,
T_6 V_275 , T_6 V_90 )
{
struct V_24 * V_25 = F_26 ( V_21 -> V_66 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_90 ; V_8 ++ ) {
F_109 ( L_25 , V_8 ,
V_272 [ V_8 ] , V_273 [ V_8 ] , V_274 [ V_8 ] ) ;
F_95 ( V_25 , V_276 + V_8 * 3 + 0 , V_272 [ V_8 ] >> 8 ) ;
F_95 ( V_25 , V_276 + V_8 * 3 + 1 , V_273 [ V_8 ] >> 8 ) ;
F_95 ( V_25 , V_276 + V_8 * 3 + 2 , V_274 [ V_8 ] >> 8 ) ;
}
}
void F_110 ( struct V_264 * V_23 , int V_136 )
{
}
void F_111 ( struct V_264 * V_23 )
{
}
void F_112 ( struct V_264 * V_23 )
{
}
enum V_277
F_105 ( struct V_264 * V_23 , bool V_278 )
{
T_6 V_249 ;
struct V_102 * V_66 = V_23 -> V_66 ;
struct V_24 * V_25 = F_26 ( V_66 ) ;
struct V_17 * V_18 = F_104 ( V_23 ) ;
F_34 ( & V_25 -> V_279 ) ;
V_249 = F_97 ( V_25 , V_280 ) ;
F_36 ( & V_25 -> V_279 ) ;
return ( ( F_104 ( V_23 ) -> V_134 < V_249 &&
V_18 -> V_268 ) ?
V_281 : V_282 ) ;
}
static void F_113 ( struct V_283 * V_136 )
{
V_136 -> V_284 = V_136 -> V_137 + 50 ;
V_136 -> V_285 = V_136 -> V_284 + 50 ;
V_136 -> V_286 = V_136 -> V_285 + 50 ;
V_136 -> V_287 = V_136 -> V_138 + 50 ;
V_136 -> V_288 = V_136 -> V_287 + 50 ;
V_136 -> V_289 = V_136 -> V_288 + 50 ;
V_136 -> clock = ( T_2 ) V_136 -> V_286 * ( T_2 ) V_136 -> V_289 / 100 * 6 ;
V_136 -> V_290 = F_114 ( V_136 ) ;
}
int F_115 ( struct V_264 * V_23 ,
T_6 V_222 , T_6 V_223 )
{
struct V_17 * V_18 = F_104 ( V_23 ) ;
struct V_102 * V_66 = V_23 -> V_66 ;
struct V_24 * V_25 = F_26 ( V_66 ) ;
struct V_283 * V_136 = NULL ;
struct V_283 * V_291 ;
struct V_283 V_292 = { F_116 ( L_26 ,
DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC)
} ;
int V_8 ;
{
V_136 = F_117 ( V_66 , & V_292 ) ;
if ( ! V_136 )
return 0 ;
V_136 -> V_137 = V_18 -> V_266 ;
V_136 -> V_138 = V_18 -> V_267 ;
F_113 ( V_136 ) ;
if ( F_75 ( V_25 , V_136 -> V_137 * 2 ,
V_136 -> V_138 ) ) {
F_118 ( V_23 , V_136 ) ;
} else {
F_119 ( V_66 , V_136 ) ;
V_136 = NULL ;
}
if ( V_18 -> V_293 ) {
F_120 ( & V_18 -> V_293 -> V_114 ) ;
F_119 ( V_66 , V_18 -> V_293 ) ;
}
V_18 -> V_293 = V_136 ;
}
for ( V_8 = 0 ; V_294 [ V_8 ] . type != 0 ; V_8 ++ ) {
V_291 = & V_294 [ V_8 ] ;
if ( V_291 -> V_137 > V_222 ||
V_291 -> V_138 > V_223 )
continue;
if ( ! F_75 ( V_25 , V_291 -> V_137 * 2 ,
V_291 -> V_138 ) )
continue;
V_136 = F_117 ( V_66 , V_291 ) ;
if ( ! V_136 )
return 0 ;
V_136 -> V_290 = F_114 ( V_136 ) ;
F_118 ( V_23 , V_136 ) ;
}
if ( V_18 -> V_293 )
F_121 ( & V_18 -> V_293 -> V_114 , & V_23 -> V_295 ) ;
F_122 ( V_23 ) ;
return 1 ;
}
int F_123 ( struct V_264 * V_23 ,
struct V_296 * V_297 ,
T_19 V_298 )
{
return 0 ;
}
int F_124 ( struct V_102 * V_66 , void * V_224 ,
struct V_63 * V_64 )
{
struct V_24 * V_25 = F_26 ( V_66 ) ;
struct V_299 * V_226 =
(struct V_299 * ) V_224 ;
struct V_110 * V_111 = V_110 ( V_64 -> V_112 ) ;
void T_16 * V_300 ;
struct V_208 * V_2 ;
unsigned V_301 ;
int V_47 ;
int V_8 ;
struct V_302 * V_103 = & V_66 -> V_103 ;
V_47 = F_50 ( & V_111 -> V_146 , true ) ;
if ( F_12 ( V_47 != 0 ) )
return V_47 ;
if ( ! V_226 -> V_303 ) {
struct V_208 V_304 = { 0 , 0 , 800 , 600 } ;
F_103 ( V_25 , 1 , & V_304 ) ;
goto V_305;
}
V_301 = V_226 -> V_303 * sizeof( struct V_208 ) ;
V_2 = F_125 ( V_226 -> V_303 , sizeof( struct V_208 ) ,
V_130 ) ;
if ( F_12 ( ! V_2 ) ) {
V_47 = - V_36 ;
goto V_305;
}
V_300 = ( void T_16 * ) ( unsigned long ) V_226 -> V_2 ;
V_47 = F_126 ( V_2 , V_300 , V_301 ) ;
if ( F_12 ( V_47 != 0 ) ) {
F_13 ( L_27 ) ;
V_47 = - V_306 ;
goto V_307;
}
for ( V_8 = 0 ; V_8 < V_226 -> V_303 ; ++ V_8 ) {
if ( V_2 [ V_8 ] . V_53 < 0 ||
V_2 [ V_8 ] . V_54 < 0 ||
V_2 [ V_8 ] . V_53 + V_2 [ V_8 ] . V_99 > V_103 -> V_222 ||
V_2 [ V_8 ] . V_54 + V_2 [ V_8 ] . V_100 > V_103 -> V_223 ) {
F_13 ( L_28 ) ;
V_47 = - V_35 ;
goto V_307;
}
}
F_103 ( V_25 , V_226 -> V_303 , V_2 ) ;
V_307:
F_44 ( V_2 ) ;
V_305:
F_51 ( & V_111 -> V_146 ) ;
return V_47 ;
}
