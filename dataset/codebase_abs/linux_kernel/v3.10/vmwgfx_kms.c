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
F_29 ( & V_21 -> V_71 ) ;
F_30 ( V_25 -> V_66 ) ;
if ( V_65 && ( V_27 != 64 || V_28 != 64 ) ) {
V_47 = - V_35 ;
goto V_72;
}
if ( V_65 ) {
V_47 = F_31 ( V_25 , V_68 ,
V_65 , & V_70 , & V_40 ) ;
if ( V_47 ) {
F_13 ( L_3 , V_47 ) ;
V_47 = - V_35 ;
goto V_72;
}
}
if ( V_70 && ! V_70 -> V_73 . V_26 ) {
F_13 ( L_4 ) ;
F_5 ( & V_70 ) ;
V_47 = - V_35 ;
goto V_72;
}
if ( V_18 -> V_19 ) {
V_18 -> V_19 -> V_73 . V_21 = NULL ;
F_5 ( & V_18 -> V_19 ) ;
}
if ( V_18 -> V_20 )
F_6 ( & V_18 -> V_20 ) ;
if ( V_70 ) {
V_18 -> V_19 = V_70 ;
V_18 -> V_19 -> V_73 . V_21 = V_21 ;
V_18 -> V_74 = V_18 -> V_19 -> V_73 . V_75 ;
F_10 ( V_25 , V_70 -> V_73 . V_26 ,
64 , 64 , V_18 -> V_76 , V_18 -> V_77 ) ;
} else if ( V_40 ) {
V_18 -> V_20 = V_40 ;
V_47 = F_16 ( V_25 , V_40 , V_27 , V_28 ,
V_18 -> V_76 , V_18 -> V_77 ) ;
} else {
F_22 ( V_25 , false , 0 , 0 ) ;
V_47 = 0 ;
goto V_72;
}
F_22 ( V_25 , true ,
V_18 -> V_78 + V_18 -> V_76 ,
V_18 -> V_79 + V_18 -> V_77 ) ;
V_47 = 0 ;
V_72:
F_32 ( V_25 -> V_66 ) ;
F_33 ( & V_21 -> V_71 ) ;
return V_47 ;
}
int F_34 ( struct V_62 * V_21 , int V_53 , int V_54 )
{
struct V_24 * V_25 = F_26 ( V_21 -> V_66 ) ;
struct V_17 * V_18 = F_28 ( V_21 ) ;
bool V_80 = V_18 -> V_19 || V_18 -> V_20 ? true : false ;
V_18 -> V_78 = V_53 + V_21 -> V_53 ;
V_18 -> V_79 = V_54 + V_21 -> V_54 ;
F_29 ( & V_21 -> V_71 ) ;
F_30 ( V_25 -> V_66 ) ;
F_22 ( V_25 , V_80 ,
V_18 -> V_78 + V_18 -> V_76 ,
V_18 -> V_79 + V_18 -> V_77 ) ;
F_32 ( V_25 -> V_66 ) ;
F_33 ( & V_21 -> V_71 ) ;
return 0 ;
}
void F_35 ( struct V_69 * V_81 ,
struct V_67 * V_68 ,
struct V_82 * V_83 ,
T_7 * V_84 )
{
struct V_41 V_42 ;
unsigned long V_43 ;
unsigned long V_44 ;
T_8 * V_85 ;
unsigned V_86 ;
void * V_45 ;
bool V_46 ;
struct V_87 {
T_7 V_84 ;
T_9 V_88 ;
} * V_31 ;
int V_8 , V_47 ;
V_31 = F_36 ( V_84 , struct V_87 , V_84 ) ;
if ( ! V_81 -> V_73 . V_26 )
return;
if ( V_31 -> V_88 . V_89 . V_90 != 0 || V_31 -> V_88 . V_89 . V_91 != 0 ) {
F_13 ( L_5 ) ;
return;
}
if ( V_31 -> V_84 . V_92 < 64 ) {
F_13 ( L_6 ) ;
return;
}
V_85 = ( T_8 * ) & V_31 [ 1 ] ;
V_86 = ( V_31 -> V_84 . V_92 - sizeof( T_9 ) ) /
sizeof( T_8 ) ;
if ( V_31 -> V_88 . V_93 . V_94 . V_95 % V_48 ||
V_85 -> V_53 != 0 || V_85 -> V_54 != 0 || V_85 -> V_96 != 0 ||
V_85 -> V_97 != 0 || V_85 -> V_98 != 0 || V_85 -> V_99 != 0 ||
V_85 -> V_100 != 1 || V_86 != 1 ) {
F_13 ( L_7 ) ;
F_13 ( L_8 ,
V_85 -> V_97 , V_85 -> V_98 , V_85 -> V_99 ,
V_85 -> V_53 , V_85 -> V_54 , V_85 -> V_96 ,
V_85 -> V_101 , V_85 -> V_102 , V_85 -> V_100 , V_86 ,
V_31 -> V_88 . V_93 . V_94 . V_95 ) ;
return;
}
V_43 = V_31 -> V_88 . V_93 . V_94 . V_95 >> V_49 ;
V_44 = ( 64 * 64 * 4 ) >> V_49 ;
V_47 = F_17 ( V_83 , true , false , false , 0 ) ;
if ( F_12 ( V_47 != 0 ) ) {
F_13 ( L_2 ) ;
return;
}
V_47 = F_18 ( V_83 , V_43 , V_44 , & V_42 ) ;
if ( F_12 ( V_47 != 0 ) )
goto V_51;
V_45 = F_19 ( & V_42 , & V_46 ) ;
if ( V_85 -> V_101 == 64 && V_31 -> V_88 . V_93 . V_103 == 64 * 4 ) {
memcpy ( V_81 -> V_73 . V_26 , V_45 , 64 * 64 * 4 ) ;
} else {
for ( V_8 = 0 ; V_8 < V_85 -> V_102 ; V_8 ++ )
memcpy ( V_81 -> V_73 . V_26 + V_8 * 64 ,
V_45 + V_8 * V_31 -> V_88 . V_93 . V_103 ,
V_85 -> V_101 * 4 ) ;
}
V_81 -> V_73 . V_75 ++ ;
F_20 ( & V_42 ) ;
V_51:
F_21 ( V_83 ) ;
}
void F_37 ( struct V_24 * V_25 )
{
struct V_104 * V_66 = V_25 -> V_66 ;
struct V_17 * V_18 ;
struct V_62 * V_21 ;
F_33 ( & V_66 -> V_105 . V_71 ) ;
F_38 (crtc, &dev->mode_config.crtc_list, head) {
V_18 = F_28 ( V_21 ) ;
if ( ! V_18 -> V_19 ||
V_18 -> V_74 == V_18 -> V_19 -> V_73 . V_75 )
continue;
V_18 -> V_74 = V_18 -> V_19 -> V_73 . V_75 ;
F_10 ( V_25 ,
V_18 -> V_19 -> V_73 . V_26 ,
64 , 64 , V_18 -> V_76 , V_18 -> V_77 ) ;
}
F_29 ( & V_66 -> V_105 . V_71 ) ;
}
void F_39 ( struct V_106 * V_107 )
{
struct V_108 * V_109 =
F_40 ( V_107 ) ;
struct V_110 * V_111 = V_110 ( V_109 -> V_112 ) ;
F_33 ( & V_111 -> V_113 ) ;
F_41 ( & V_109 -> V_114 ) ;
F_29 ( & V_111 -> V_113 ) ;
F_42 ( & V_109 -> V_112 ) ;
F_43 ( V_107 ) ;
F_5 ( & V_109 -> V_70 ) ;
F_44 ( & V_109 -> V_50 . V_115 ) ;
F_45 ( V_109 ) ;
}
static int F_46 ( struct V_24 * V_25 ,
struct V_63 * V_64 ,
struct V_116 * V_107 ,
unsigned V_117 , unsigned V_118 ,
struct V_1 * V_119 ,
unsigned V_120 , int V_121 ,
struct V_122 * * V_123 )
{
struct V_17 * V_124 [ V_125 ] ;
struct V_1 * V_126 ;
struct V_1 * V_127 ;
struct V_62 * V_21 ;
T_10 V_128 ;
int V_8 , V_129 ;
int V_47 = 0 ;
int V_13 , V_15 , V_14 , V_16 ;
struct {
T_7 V_84 ;
T_11 V_130 ;
} * V_31 ;
T_1 * V_131 ;
V_129 = 0 ;
F_38 (crtc, &dev_priv->dev->mode_config.crtc_list,
head) {
if ( V_21 -> V_132 != & V_107 -> V_50 )
continue;
V_124 [ V_129 ++ ] = F_28 ( V_21 ) ;
}
F_47 ( ! V_119 || ! V_120 ) ;
V_127 = F_48 ( sizeof( * V_127 ) * V_120 , V_133 ) ;
if ( F_12 ( V_127 == NULL ) ) {
F_13 ( L_9 ) ;
return - V_36 ;
}
V_128 = sizeof( * V_31 ) + sizeof( T_1 ) * V_120 ;
V_31 = F_48 ( V_128 , V_133 ) ;
if ( F_12 ( V_31 == NULL ) ) {
F_13 ( L_10 ) ;
V_47 = - V_36 ;
goto V_134;
}
V_131 = ( T_1 * ) & V_31 [ 1 ] ;
V_13 = V_119 -> V_10 ;
V_15 = V_119 -> V_11 ;
V_14 = V_119 -> y1 ;
V_16 = V_119 -> V_12 ;
for ( V_8 = 1 , V_126 = V_119 + V_121 ;
V_8 < V_120 ; V_8 ++ , V_126 += V_121 ) {
V_13 = F_3 ( int , V_13 , ( int ) V_126 -> V_10 ) ;
V_15 = F_2 ( int , V_15 , ( int ) V_126 -> V_11 ) ;
V_14 = F_3 ( int , V_14 , ( int ) V_126 -> y1 ) ;
V_16 = F_2 ( int , V_16 , ( int ) V_126 -> V_12 ) ;
}
V_31 -> V_84 . V_38 = F_14 ( V_135 ) ;
V_31 -> V_84 . V_92 = F_14 ( V_128 - sizeof( V_31 -> V_84 ) ) ;
V_31 -> V_130 . V_136 . V_13 = V_13 ;
V_31 -> V_130 . V_136 . V_15 = V_15 ;
V_31 -> V_130 . V_136 . V_14 = V_14 ;
V_31 -> V_130 . V_136 . V_16 = V_16 ;
V_126 = V_119 ;
for ( V_8 = 0 ; V_8 < V_120 ; V_8 ++ , V_126 += V_121 ) {
V_127 [ V_8 ] . V_10 = V_126 -> V_10 - V_13 ;
V_127 [ V_8 ] . V_11 = V_126 -> V_11 - V_13 ;
V_127 [ V_8 ] . y1 = V_126 -> y1 - V_14 ;
V_127 [ V_8 ] . V_12 = V_126 -> V_12 - V_14 ;
}
for ( V_8 = 0 ; V_8 < V_129 ; V_8 ++ ) {
struct V_17 * V_137 = V_124 [ V_8 ] ;
struct V_4 V_5 ;
int V_138 ;
V_5 . V_10 = V_13 - V_137 -> V_21 . V_53 ;
V_5 . y1 = V_14 - V_137 -> V_21 . V_54 ;
V_5 . V_11 = V_15 - V_137 -> V_21 . V_53 ;
V_5 . V_12 = V_16 - V_137 -> V_21 . V_54 ;
if ( V_5 . V_10 >= V_137 -> V_21 . V_139 . V_140 ||
V_5 . y1 >= V_137 -> V_21 . V_139 . V_141 ||
V_5 . V_11 <= 0 || V_5 . V_12 <= 0 )
continue;
V_31 -> V_130 . V_142 . V_13 = V_5 . V_10 ;
V_31 -> V_130 . V_142 . V_15 = V_5 . V_11 ;
V_31 -> V_130 . V_142 . V_14 = V_5 . y1 ;
V_31 -> V_130 . V_142 . V_16 = V_5 . V_12 ;
V_5 . V_11 = V_137 -> V_21 . V_139 . V_140 - V_5 . V_10 ;
V_5 . V_12 = V_137 -> V_21 . V_139 . V_141 - V_5 . y1 ;
V_5 . V_10 = 0 - V_5 . V_10 ;
V_5 . y1 = 0 - V_5 . y1 ;
V_31 -> V_130 . V_143 . V_144 = F_14 ( V_107 -> V_145 ) ;
V_31 -> V_130 . V_146 = V_137 -> V_137 ;
F_1 ( V_127 , V_120 , V_5 , V_131 , & V_138 ) ;
if ( V_138 == 0 )
continue;
if ( V_123 && * V_123 )
F_49 ( V_123 ) ;
V_128 = sizeof( * V_31 ) + sizeof( T_1 ) * V_138 ;
V_31 -> V_84 . V_92 = F_14 ( V_128 - sizeof( V_31 -> V_84 ) ) ;
V_47 = F_50 ( V_64 , V_25 , NULL , V_31 ,
V_128 , 0 , NULL , V_123 ) ;
if ( F_12 ( V_47 != 0 ) )
break;
}
F_45 ( V_31 ) ;
V_134:
F_45 ( V_127 ) ;
return V_47 ;
}
int F_51 ( struct V_106 * V_107 ,
struct V_63 * V_64 ,
unsigned V_117 , unsigned V_118 ,
struct V_1 * V_119 ,
unsigned V_120 )
{
struct V_24 * V_25 = F_26 ( V_107 -> V_66 ) ;
struct V_110 * V_111 = V_110 ( V_64 -> V_112 ) ;
struct V_108 * V_109 =
F_40 ( V_107 ) ;
struct V_1 V_147 ;
int V_47 , V_121 = 1 ;
if ( F_12 ( V_109 -> V_112 != V_64 -> V_112 ) )
return - V_35 ;
if ( ! V_25 -> V_148 )
return - V_35 ;
V_47 = F_52 ( & V_111 -> V_149 , true ) ;
if ( F_12 ( V_47 != 0 ) )
return V_47 ;
if ( ! V_120 ) {
V_120 = 1 ;
V_119 = & V_147 ;
V_147 . V_10 = V_147 . y1 = 0 ;
V_147 . V_11 = V_107 -> V_27 ;
V_147 . V_12 = V_107 -> V_28 ;
} else if ( V_117 & V_150 ) {
V_120 /= 2 ;
V_121 = 2 ;
}
V_47 = F_46 ( V_25 , V_64 , & V_109 -> V_50 ,
V_117 , V_118 ,
V_119 , V_120 , V_121 , NULL ) ;
F_53 ( & V_111 -> V_149 ) ;
return 0 ;
}
static int F_54 ( struct V_24 * V_25 ,
struct V_63 * V_64 ,
struct V_69 * V_70 ,
struct V_116 * * V_72 ,
const struct V_151
* V_152 )
{
struct V_104 * V_66 = V_25 -> V_66 ;
struct V_108 * V_109 ;
enum V_153 V_154 ;
struct V_110 * V_111 = V_110 ( V_64 -> V_112 ) ;
int V_47 ;
if ( ! V_25 -> V_148 )
return - V_155 ;
if ( F_12 ( ! V_70 -> V_156 ) )
return - V_35 ;
if ( F_12 ( V_70 -> V_157 [ 0 ] != 1 ||
V_70 -> V_158 != 1 ||
V_70 -> V_159 [ 0 ] . V_27 < V_152 -> V_27 ||
V_70 -> V_159 [ 0 ] . V_28 < V_152 -> V_28 ||
V_70 -> V_159 [ 0 ] . V_160 != 1 ) ) {
F_13 ( L_11
L_12 ) ;
return - V_35 ;
}
switch ( V_152 -> V_160 ) {
case 32 :
V_154 = V_161 ;
break;
case 24 :
V_154 = V_162 ;
break;
case 16 :
V_154 = V_163 ;
break;
case 15 :
V_154 = V_164 ;
break;
case 8 :
V_154 = V_165 ;
break;
default:
F_13 ( L_13 , V_152 -> V_160 ) ;
return - V_35 ;
}
if ( F_12 ( V_154 != V_70 -> V_154 ) ) {
F_13 ( L_14 ) ;
return - V_35 ;
}
V_109 = F_48 ( sizeof( * V_109 ) , V_133 ) ;
if ( ! V_109 ) {
V_47 = - V_36 ;
goto V_166;
}
if ( ! F_55 ( V_70 ) ) {
F_13 ( L_15 , V_70 ) ;
V_47 = - V_35 ;
goto V_167;
}
V_109 -> V_50 . V_50 . V_168 = V_152 -> V_169 ;
V_109 -> V_50 . V_50 . V_170 [ 0 ] = V_152 -> V_103 ;
V_109 -> V_50 . V_50 . V_160 = V_152 -> V_160 ;
V_109 -> V_50 . V_50 . V_27 = V_152 -> V_27 ;
V_109 -> V_50 . V_50 . V_28 = V_152 -> V_28 ;
V_109 -> V_70 = V_70 ;
V_109 -> V_50 . V_145 = V_152 -> V_65 ;
V_109 -> V_112 = F_56 ( V_64 -> V_112 ) ;
F_33 ( & V_111 -> V_113 ) ;
F_57 ( & V_109 -> V_114 , & V_111 -> V_171 ) ;
F_29 ( & V_111 -> V_113 ) ;
* V_72 = & V_109 -> V_50 ;
V_47 = F_58 ( V_66 , & V_109 -> V_50 . V_50 ,
& V_172 ) ;
if ( V_47 )
goto V_173;
return 0 ;
V_173:
F_5 ( & V_70 ) ;
V_167:
F_45 ( V_109 ) ;
V_166:
return V_47 ;
}
void F_59 ( struct V_106 * V_107 )
{
struct V_174 * V_175 =
F_60 ( V_107 ) ;
F_43 ( V_107 ) ;
F_6 ( & V_175 -> V_176 ) ;
F_44 ( & V_175 -> V_50 . V_115 ) ;
F_45 ( V_175 ) ;
}
static int F_61 ( struct V_24 * V_25 ,
struct V_116 * V_107 ,
unsigned V_117 , unsigned V_118 ,
struct V_1 * V_119 ,
unsigned V_120 , int V_177 )
{
T_10 V_128 ;
int V_8 ;
struct {
T_6 V_84 ;
T_12 V_130 ;
} * V_31 ;
V_128 = sizeof( * V_31 ) * V_120 ;
V_31 = F_11 ( V_25 , V_128 ) ;
if ( F_12 ( V_31 == NULL ) ) {
F_13 ( L_1 ) ;
return - V_36 ;
}
memset ( V_31 , 0 , V_128 ) ;
for ( V_8 = 0 ; V_8 < V_120 ; V_8 ++ , V_119 += V_177 ) {
V_31 [ V_8 ] . V_84 = F_14 ( V_178 ) ;
V_31 [ V_8 ] . V_130 . V_53 = F_14 ( V_119 -> V_10 ) ;
V_31 [ V_8 ] . V_130 . V_54 = F_14 ( V_119 -> y1 ) ;
V_31 [ V_8 ] . V_130 . V_27 = F_14 ( V_119 -> V_11 - V_119 -> V_10 ) ;
V_31 [ V_8 ] . V_130 . V_28 = F_14 ( V_119 -> V_12 - V_119 -> y1 ) ;
}
F_15 ( V_25 , V_128 ) ;
return 0 ;
}
static int F_62 ( struct V_63 * V_64 ,
struct V_24 * V_25 ,
struct V_116 * V_107 )
{
int V_160 = V_107 -> V_50 . V_160 ;
T_10 V_128 ;
int V_47 ;
struct {
T_6 V_84 ;
T_13 V_130 ;
} * V_31 ;
if ( V_160 == 32 )
V_160 = 24 ;
V_128 = sizeof( * V_31 ) ;
V_31 = F_63 ( V_128 , V_133 ) ;
if ( F_12 ( V_31 == NULL ) ) {
F_13 ( L_16 ) ;
return - V_36 ;
}
memset ( V_31 , 0 , V_128 ) ;
V_31 -> V_84 = V_179 ;
V_31 -> V_130 . V_154 . V_180 = V_107 -> V_50 . V_168 ;
V_31 -> V_130 . V_154 . V_181 = V_160 ;
V_31 -> V_130 . V_154 . V_182 = 0 ;
V_31 -> V_130 . V_183 = V_107 -> V_50 . V_170 [ 0 ] ;
V_31 -> V_130 . V_94 . V_184 = V_107 -> V_145 ;
V_31 -> V_130 . V_94 . V_95 = 0 ;
V_47 = F_50 ( V_64 , V_25 , NULL , V_31 ,
V_128 , 0 , NULL , NULL ) ;
F_45 ( V_31 ) ;
return V_47 ;
}
static int F_64 ( struct V_63 * V_64 ,
struct V_24 * V_25 ,
struct V_116 * V_107 ,
unsigned V_117 , unsigned V_118 ,
struct V_1 * V_119 ,
unsigned V_120 , int V_177 ,
struct V_122 * * V_123 )
{
struct V_17 * V_124 [ V_125 ] ;
struct V_1 * V_126 ;
int V_8 , V_9 , V_129 , V_47 ;
struct V_62 * V_21 ;
T_10 V_128 ;
struct {
T_6 V_84 ;
T_14 V_130 ;
} * V_131 ;
V_47 = F_62 ( V_64 , V_25 , V_107 ) ;
if ( F_12 ( V_47 != 0 ) )
return V_47 ;
V_128 = sizeof( * V_131 ) * V_120 ;
V_131 = F_63 ( V_128 , V_133 ) ;
if ( F_12 ( V_131 == NULL ) ) {
F_13 ( L_16 ) ;
return - V_36 ;
}
V_129 = 0 ;
F_38 (crtc, &dev_priv->dev->mode_config.crtc_list, head) {
if ( V_21 -> V_132 != & V_107 -> V_50 )
continue;
V_124 [ V_129 ++ ] = F_28 ( V_21 ) ;
}
for ( V_9 = 0 ; V_9 < V_129 ; V_9 ++ ) {
struct V_17 * V_137 = V_124 [ V_9 ] ;
int V_185 = 0 ;
V_126 = V_119 ;
for ( V_8 = 0 ; V_8 < V_120 ; V_8 ++ , V_126 += V_177 ) {
int V_186 = V_126 -> V_10 - V_137 -> V_21 . V_53 ;
int V_187 = V_126 -> y1 - V_137 -> V_21 . V_54 ;
int V_188 = V_126 -> V_11 - V_137 -> V_21 . V_53 ;
int V_189 = V_126 -> V_12 - V_137 -> V_21 . V_54 ;
int V_190 , V_191 ;
if ( V_186 >= V_137 -> V_21 . V_139 . V_140 ||
V_187 >= V_137 -> V_21 . V_139 . V_141 ||
V_188 <= 0 || V_189 <= 0 )
continue;
V_188 = F_3 ( int , V_188 , V_137 -> V_21 . V_139 . V_140 ) ;
V_189 = F_3 ( int , V_189 , V_137 -> V_21 . V_139 . V_141 ) ;
V_190 = F_3 ( int , V_186 , 0 ) ;
V_191 = F_3 ( int , V_187 , 0 ) ;
V_131 [ V_185 ] . V_84 = V_192 ;
V_131 [ V_185 ] . V_130 . V_146 = V_137 -> V_137 ;
V_131 [ V_185 ] . V_130 . V_193 . V_53 = V_126 -> V_10 - V_190 ;
V_131 [ V_185 ] . V_130 . V_193 . V_54 = V_126 -> y1 - V_191 ;
V_131 [ V_185 ] . V_130 . V_142 . V_13 = V_186 - V_190 ;
V_131 [ V_185 ] . V_130 . V_142 . V_14 = V_187 - V_191 ;
V_131 [ V_185 ] . V_130 . V_142 . V_15 = V_188 ;
V_131 [ V_185 ] . V_130 . V_142 . V_16 = V_189 ;
V_185 ++ ;
}
if ( V_185 == 0 )
continue;
if ( V_123 && * V_123 )
F_49 ( V_123 ) ;
V_128 = sizeof( * V_131 ) * V_185 ;
V_47 = F_50 ( V_64 , V_25 , NULL , V_131 ,
V_128 , 0 , NULL , V_123 ) ;
if ( F_12 ( V_47 != 0 ) )
break;
}
F_45 ( V_131 ) ;
return V_47 ;
}
int F_65 ( struct V_106 * V_107 ,
struct V_63 * V_64 ,
unsigned V_117 , unsigned V_118 ,
struct V_1 * V_119 ,
unsigned V_120 )
{
struct V_24 * V_25 = F_26 ( V_107 -> V_66 ) ;
struct V_110 * V_111 = V_110 ( V_64 -> V_112 ) ;
struct V_174 * V_175 =
F_60 ( V_107 ) ;
struct V_1 V_147 ;
int V_47 , V_177 = 1 ;
V_47 = F_52 ( & V_111 -> V_149 , true ) ;
if ( F_12 ( V_47 != 0 ) )
return V_47 ;
if ( ! V_120 ) {
V_120 = 1 ;
V_119 = & V_147 ;
V_147 . V_10 = V_147 . y1 = 0 ;
V_147 . V_11 = V_107 -> V_27 ;
V_147 . V_12 = V_107 -> V_28 ;
} else if ( V_117 & V_150 ) {
V_120 /= 2 ;
V_177 = 2 ;
}
if ( V_25 -> V_194 ) {
V_47 = F_61 ( V_25 , & V_175 -> V_50 ,
V_117 , V_118 ,
V_119 , V_120 , V_177 ) ;
} else {
V_47 = F_64 ( V_64 , V_25 , & V_175 -> V_50 ,
V_117 , V_118 ,
V_119 , V_120 , V_177 , NULL ) ;
}
F_53 ( & V_111 -> V_149 ) ;
return V_47 ;
}
static int F_66 ( struct V_116 * V_195 )
{
struct V_24 * V_25 = F_26 ( V_195 -> V_50 . V_66 ) ;
struct V_174 * V_175 =
F_60 ( & V_195 -> V_50 ) ;
int V_47 ;
F_47 ( V_25 -> V_148 ) ;
F_67 ( V_25 ) ;
V_47 = F_68 ( V_25 , V_175 -> V_176 , true , false ) ;
F_69 ( V_25 ) ;
F_70 ( V_47 != 0 ) ;
return 0 ;
}
static int F_71 ( struct V_116 * V_195 )
{
struct V_24 * V_25 = F_26 ( V_195 -> V_50 . V_66 ) ;
struct V_174 * V_175 =
F_60 ( & V_195 -> V_50 ) ;
if ( ! V_175 -> V_176 ) {
F_70 ( ! V_175 -> V_176 ) ;
return 0 ;
}
return F_72 ( V_25 , V_175 -> V_176 , false ) ;
}
static int F_73 ( struct V_24 * V_25 ,
struct V_39 * V_40 ,
struct V_116 * * V_72 ,
const struct V_151
* V_152 )
{
struct V_104 * V_66 = V_25 -> V_66 ;
struct V_174 * V_175 ;
unsigned int V_196 ;
int V_47 ;
V_196 = V_152 -> V_28 * V_152 -> V_103 ;
if ( F_12 ( V_196 > V_40 -> V_50 . V_197 * V_48 ) ) {
F_13 ( L_17
L_12 ) ;
return - V_35 ;
}
if ( V_25 -> V_148 ) {
switch ( V_152 -> V_160 ) {
case 32 :
case 24 :
if ( V_152 -> V_169 == 32 )
break;
F_13 ( L_18 ,
V_152 -> V_160 , V_152 -> V_169 ) ;
return - V_35 ;
case 16 :
case 15 :
if ( V_152 -> V_169 == 16 )
break;
F_13 ( L_18 ,
V_152 -> V_160 , V_152 -> V_169 ) ;
return - V_35 ;
default:
F_13 ( L_13 , V_152 -> V_160 ) ;
return - V_35 ;
}
}
V_175 = F_48 ( sizeof( * V_175 ) , V_133 ) ;
if ( ! V_175 ) {
V_47 = - V_36 ;
goto V_166;
}
if ( ! F_74 ( V_40 ) ) {
F_13 ( L_19 , V_40 ) ;
V_47 = - V_35 ;
goto V_167;
}
V_175 -> V_50 . V_50 . V_168 = V_152 -> V_169 ;
V_175 -> V_50 . V_50 . V_170 [ 0 ] = V_152 -> V_103 ;
V_175 -> V_50 . V_50 . V_160 = V_152 -> V_160 ;
V_175 -> V_50 . V_50 . V_27 = V_152 -> V_27 ;
V_175 -> V_50 . V_50 . V_28 = V_152 -> V_28 ;
if ( ! V_25 -> V_148 ) {
V_175 -> V_50 . V_198 = F_66 ;
V_175 -> V_50 . V_199 = F_71 ;
}
V_175 -> V_50 . V_40 = true ;
V_175 -> V_176 = V_40 ;
V_175 -> V_50 . V_145 = V_152 -> V_65 ;
* V_72 = & V_175 -> V_50 ;
V_47 = F_58 ( V_66 , & V_175 -> V_50 . V_50 ,
& V_200 ) ;
if ( V_47 )
goto V_173;
return 0 ;
V_173:
F_6 ( & V_40 ) ;
V_167:
F_45 ( V_175 ) ;
V_166:
return V_47 ;
}
static struct V_106 * F_75 ( struct V_104 * V_66 ,
struct V_63 * V_64 ,
struct V_201 * V_202 )
{
struct V_24 * V_25 = F_26 ( V_66 ) ;
struct V_67 * V_68 = F_27 ( V_64 ) -> V_68 ;
struct V_116 * V_195 = NULL ;
struct V_69 * V_70 = NULL ;
struct V_39 * V_83 = NULL ;
struct V_203 * V_115 ;
struct V_151 V_152 ;
int V_47 ;
V_152 . V_27 = V_202 -> V_27 ;
V_152 . V_28 = V_202 -> V_28 ;
V_152 . V_103 = V_202 -> V_170 [ 0 ] ;
V_152 . V_65 = V_202 -> V_204 [ 0 ] ;
F_76 ( V_202 -> V_205 , & V_152 . V_160 ,
& V_152 . V_169 ) ;
if ( ! F_77 ( V_25 ,
V_152 . V_103 ,
V_152 . V_28 ) ) {
F_13 ( L_20 ) ;
return F_78 ( - V_36 ) ;
}
V_115 = F_79 ( V_68 , V_152 . V_65 ) ;
if ( F_12 ( V_115 == NULL ) ) {
F_13 ( L_21 ) ;
return F_78 ( - V_206 ) ;
}
V_47 = F_31 ( V_25 , V_68 ,
V_152 . V_65 ,
& V_70 , & V_83 ) ;
if ( V_47 )
goto V_207;
if ( V_83 )
V_47 = F_73 ( V_25 , V_83 , & V_195 ,
& V_152 ) ;
else if ( V_70 )
V_47 = F_54 ( V_25 , V_64 ,
V_70 , & V_195 , & V_152 ) ;
else
F_80 () ;
V_207:
if ( V_83 )
F_6 ( & V_83 ) ;
if ( V_70 )
F_5 ( & V_70 ) ;
if ( V_47 ) {
F_13 ( L_22 , V_47 ) ;
F_44 ( & V_115 ) ;
return F_78 ( V_47 ) ;
} else
V_195 -> V_115 = V_115 ;
return & V_195 -> V_50 ;
}
int F_81 ( struct V_24 * V_25 ,
struct V_63 * V_64 ,
struct V_116 * V_195 ,
struct V_69 * V_70 ,
T_6 V_144 ,
T_15 V_208 , T_15 V_209 ,
struct V_210 * V_119 ,
T_6 V_120 )
{
struct V_17 * V_124 [ V_125 ] ;
struct V_1 * V_127 ;
struct V_62 * V_21 ;
T_10 V_128 ;
int V_8 , V_9 , V_129 ;
int V_47 = 0 ;
int V_13 , V_15 , V_14 , V_16 ;
struct {
T_7 V_84 ;
T_11 V_130 ;
} * V_31 ;
T_1 * V_131 ;
V_129 = 0 ;
F_38 (crtc, &dev_priv->dev->mode_config.crtc_list, head) {
if ( V_21 -> V_132 != & V_195 -> V_50 )
continue;
V_124 [ V_129 ++ ] = F_28 ( V_21 ) ;
}
F_47 ( V_70 == NULL ) ;
F_47 ( ! V_119 || ! V_120 ) ;
V_127 = F_48 ( sizeof( * V_127 ) * V_120 , V_133 ) ;
if ( F_12 ( V_127 == NULL ) ) {
F_13 ( L_9 ) ;
return - V_36 ;
}
V_128 = sizeof( * V_31 ) + sizeof( T_1 ) * V_120 ;
V_31 = F_63 ( V_128 , V_133 ) ;
if ( F_12 ( V_31 == NULL ) ) {
F_13 ( L_23 ) ;
V_47 = - V_36 ;
goto V_134;
}
V_13 = V_119 -> V_53 ;
V_15 = V_119 -> V_53 + V_119 -> V_101 ;
V_14 = V_119 -> V_54 ;
V_16 = V_119 -> V_54 + V_119 -> V_102 ;
for ( V_8 = 1 ; V_8 < V_120 ; V_8 ++ ) {
V_13 = F_3 ( int , V_13 , ( int ) V_119 [ V_8 ] . V_53 ) ;
V_15 = F_2 ( int , V_15 , ( int ) V_119 [ V_8 ] . V_53 + V_119 [ V_8 ] . V_101 ) ;
V_14 = F_3 ( int , V_14 , ( int ) V_119 [ V_8 ] . V_54 ) ;
V_16 = F_2 ( int , V_16 , ( int ) V_119 [ V_8 ] . V_54 + V_119 [ V_8 ] . V_102 ) ;
}
memset ( V_31 , 0 , V_128 ) ;
V_31 -> V_84 . V_38 = F_14 ( V_135 ) ;
V_131 = ( T_1 * ) & V_31 [ 1 ] ;
V_31 -> V_130 . V_136 . V_13 = V_13 ;
V_31 -> V_130 . V_136 . V_15 = V_15 ;
V_31 -> V_130 . V_136 . V_14 = V_14 ;
V_31 -> V_130 . V_136 . V_16 = V_16 ;
for ( V_8 = 0 ; V_8 < V_120 ; V_8 ++ ) {
V_127 [ V_8 ] . V_10 = V_119 [ V_8 ] . V_53 - V_13 ;
V_127 [ V_8 ] . V_11 = V_119 [ V_8 ] . V_53 + V_119 [ V_8 ] . V_101 - V_13 ;
V_127 [ V_8 ] . y1 = V_119 [ V_8 ] . V_54 - V_14 ;
V_127 [ V_8 ] . V_12 = V_119 [ V_8 ] . V_54 + V_119 [ V_8 ] . V_102 - V_14 ;
}
for ( V_9 = 0 ; V_9 < V_129 ; V_9 ++ ) {
struct V_17 * V_137 = V_124 [ V_9 ] ;
struct V_4 V_5 ;
int V_138 ;
V_5 . V_10 = V_13 + V_208 - V_137 -> V_21 . V_53 ;
V_5 . y1 = V_14 + V_209 - V_137 -> V_21 . V_54 ;
V_5 . V_11 = V_15 + V_208 - V_137 -> V_21 . V_53 ;
V_5 . V_12 = V_16 + V_209 - V_137 -> V_21 . V_54 ;
if ( V_5 . V_10 >= V_137 -> V_21 . V_139 . V_140 ||
V_5 . y1 >= V_137 -> V_21 . V_139 . V_141 ||
V_5 . V_11 <= 0 || V_5 . V_12 <= 0 )
continue;
V_31 -> V_130 . V_142 . V_13 = V_5 . V_10 ;
V_31 -> V_130 . V_142 . V_15 = V_5 . V_11 ;
V_31 -> V_130 . V_142 . V_14 = V_5 . y1 ;
V_31 -> V_130 . V_142 . V_16 = V_5 . V_12 ;
V_5 . V_11 = V_137 -> V_21 . V_139 . V_140 - V_5 . V_10 ;
V_5 . V_12 = V_137 -> V_21 . V_139 . V_141 - V_5 . y1 ;
V_5 . V_10 = 0 - V_5 . V_10 ;
V_5 . y1 = 0 - V_5 . y1 ;
V_31 -> V_130 . V_143 . V_144 = V_144 ;
V_31 -> V_130 . V_146 = V_137 -> V_137 ;
F_1 ( V_127 , V_120 , V_5 , V_131 , & V_138 ) ;
if ( V_138 == 0 )
continue;
V_128 = sizeof( * V_31 ) + sizeof( T_1 ) * V_138 ;
V_31 -> V_84 . V_92 = F_14 ( V_128 - sizeof( V_31 -> V_84 ) ) ;
V_47 = F_50 ( V_64 , V_25 , NULL , V_31 ,
V_128 , 0 , NULL , NULL ) ;
if ( F_12 ( V_47 != 0 ) )
break;
}
F_45 ( V_31 ) ;
V_134:
F_45 ( V_127 ) ;
return V_47 ;
}
int F_82 ( struct V_24 * V_25 ,
struct V_63 * V_64 ,
struct V_116 * V_195 ,
struct V_211 T_16 * V_212 ,
struct V_210 * V_119 ,
T_6 V_120 )
{
struct V_174 * V_175 =
F_60 ( & V_195 -> V_50 ) ;
struct V_39 * V_40 = V_175 -> V_176 ;
struct V_17 * V_124 [ V_125 ] ;
struct V_62 * V_21 ;
T_10 V_128 ;
int V_8 , V_9 , V_47 , V_129 , V_213 ;
struct {
T_6 V_84 ;
T_13 V_130 ;
} * V_31 ;
struct {
T_6 V_84 ;
T_17 V_130 ;
} * V_131 ;
V_129 = 0 ;
F_38 (crtc, &dev_priv->dev->mode_config.crtc_list, head) {
if ( V_21 -> V_132 != & V_195 -> V_50 )
continue;
V_124 [ V_129 ++ ] = F_28 ( V_21 ) ;
}
F_47 ( V_40 == NULL ) ;
F_47 ( ! V_119 || ! V_120 ) ;
V_128 = sizeof( * V_31 ) + sizeof( * V_131 ) * V_120 * V_129 ;
V_31 = F_63 ( V_128 , V_133 ) ;
if ( F_12 ( V_31 == NULL ) ) {
F_13 ( L_23 ) ;
return - V_36 ;
}
memset ( V_31 , 0 , V_128 ) ;
V_31 -> V_84 = V_179 ;
V_31 -> V_130 . V_154 . V_180 = V_195 -> V_50 . V_168 ;
V_31 -> V_130 . V_154 . V_181 = V_195 -> V_50 . V_160 ;
V_31 -> V_130 . V_154 . V_182 = 0 ;
V_31 -> V_130 . V_183 = V_195 -> V_50 . V_170 [ 0 ] ;
V_31 -> V_130 . V_94 . V_184 = V_195 -> V_145 ;
V_31 -> V_130 . V_94 . V_95 = 0 ;
V_131 = ( void * ) & V_31 [ 1 ] ;
V_213 = 0 ;
for ( V_8 = 0 ; V_8 < V_129 ; V_8 ++ ) {
struct V_210 * V_214 = V_119 ;
for ( V_9 = 0 ; V_9 < V_120 ; V_9 ++ , V_214 ++ ) {
int V_186 = V_214 -> V_53 - V_124 [ V_8 ] -> V_21 . V_53 ;
int V_188 = V_214 -> V_53 - V_124 [ V_8 ] -> V_21 . V_53 + V_214 -> V_101 ;
int V_187 = V_214 -> V_54 - V_124 [ V_8 ] -> V_21 . V_54 ;
int V_189 = V_214 -> V_54 - V_124 [ V_8 ] -> V_21 . V_54 + V_214 -> V_102 ;
int V_215 = V_214 -> V_53 ;
int V_216 = V_214 -> V_54 ;
if ( V_186 < 0 )
V_215 += - V_186 ;
if ( V_187 < 0 )
V_216 += - V_187 ;
V_186 = F_83 ( V_186 , 0 ) ;
V_187 = F_83 ( V_187 , 0 ) ;
V_188 = F_84 ( V_188 , V_124 [ V_8 ] -> V_21 . V_139 . V_140 ) ;
V_189 = F_84 ( V_189 , V_124 [ V_8 ] -> V_21 . V_139 . V_141 ) ;
if ( V_186 >= V_124 [ V_8 ] -> V_21 . V_139 . V_140 ||
V_187 >= V_124 [ V_8 ] -> V_21 . V_139 . V_141 ||
V_188 <= 0 || V_189 <= 0 )
continue;
V_131 [ V_213 ] . V_84 = V_217 ;
V_131 [ V_213 ] . V_130 . V_218 = V_124 [ V_8 ] -> V_137 ;
V_131 [ V_213 ] . V_130 . V_219 . V_53 = V_215 ;
V_131 [ V_213 ] . V_130 . V_219 . V_54 = V_216 ;
V_131 [ V_213 ] . V_130 . V_136 . V_13 = V_186 ;
V_131 [ V_213 ] . V_130 . V_136 . V_14 = V_187 ;
V_131 [ V_213 ] . V_130 . V_136 . V_15 = V_188 ;
V_131 [ V_213 ] . V_130 . V_136 . V_16 = V_189 ;
V_213 ++ ;
}
}
V_128 = sizeof( * V_31 ) + sizeof( * V_131 ) * V_213 ;
V_47 = F_50 ( V_64 , V_25 , NULL , V_31 , V_128 ,
0 , V_212 , NULL ) ;
F_45 ( V_31 ) ;
return V_47 ;
}
int F_85 ( struct V_24 * V_25 )
{
struct V_104 * V_66 = V_25 -> V_66 ;
int V_47 ;
F_86 ( V_66 ) ;
V_66 -> V_105 . V_220 = & V_221 ;
V_66 -> V_105 . V_222 = 1 ;
V_66 -> V_105 . V_223 = 1 ;
V_66 -> V_105 . V_224 = 8192 ;
V_66 -> V_105 . V_225 = 8192 ;
V_47 = F_87 ( V_25 ) ;
if ( V_47 )
( void ) F_88 ( V_25 ) ;
return 0 ;
}
int F_89 ( struct V_24 * V_25 )
{
F_90 ( V_25 -> V_66 ) ;
if ( V_25 -> V_148 )
F_91 ( V_25 ) ;
else
F_92 ( V_25 ) ;
return 0 ;
}
int F_93 ( struct V_104 * V_66 , void * V_226 ,
struct V_63 * V_64 )
{
struct V_227 * V_228 = V_226 ;
struct V_17 * V_18 ;
struct V_229 * V_230 ;
struct V_62 * V_21 ;
int V_47 = 0 ;
F_33 ( & V_66 -> V_105 . V_71 ) ;
if ( V_228 -> V_117 & V_231 ) {
F_38 (crtc, &dev->mode_config.crtc_list, head) {
V_18 = F_28 ( V_21 ) ;
V_18 -> V_76 = V_228 -> V_232 ;
V_18 -> V_77 = V_228 -> V_233 ;
}
F_29 ( & V_66 -> V_105 . V_71 ) ;
return 0 ;
}
V_230 = F_94 ( V_66 , V_228 -> V_234 , V_235 ) ;
if ( ! V_230 ) {
V_47 = - V_35 ;
goto V_72;
}
V_21 = F_95 ( V_230 ) ;
V_18 = F_28 ( V_21 ) ;
V_18 -> V_76 = V_228 -> V_232 ;
V_18 -> V_77 = V_228 -> V_233 ;
V_72:
F_29 ( & V_66 -> V_105 . V_71 ) ;
return V_47 ;
}
int F_96 ( struct V_24 * F_26 ,
unsigned V_27 , unsigned V_28 , unsigned V_103 ,
unsigned V_169 , unsigned V_160 )
{
if ( F_26 -> V_236 & V_237 )
F_97 ( F_26 , V_238 , V_103 ) ;
else if ( F_98 ( F_26 ) )
F_23 ( V_103 , F_26 -> V_56 + V_239 ) ;
F_97 ( F_26 , V_240 , V_27 ) ;
F_97 ( F_26 , V_241 , V_28 ) ;
F_97 ( F_26 , V_242 , V_169 ) ;
if ( F_99 ( F_26 , V_243 ) != V_160 ) {
F_13 ( L_24 ,
V_160 , V_169 , F_99 ( F_26 , V_243 ) ) ;
return - V_35 ;
}
return 0 ;
}
int F_100 ( struct V_24 * F_26 )
{
struct V_244 * V_245 ;
T_6 V_8 ;
F_26 -> V_246 = F_99 ( F_26 , V_240 ) ;
F_26 -> V_247 = F_99 ( F_26 , V_241 ) ;
F_26 -> V_248 = F_99 ( F_26 , V_242 ) ;
if ( F_26 -> V_236 & V_237 )
F_26 -> V_249 =
F_99 ( F_26 , V_238 ) ;
else if ( F_98 ( F_26 ) )
F_26 -> V_249 = F_24 ( F_26 -> V_56 +
V_239 ) ;
if ( ! ( F_26 -> V_236 & V_250 ) )
return 0 ;
F_26 -> V_251 = F_99 ( F_26 ,
V_252 ) ;
if ( F_26 -> V_251 == 0 )
F_26 -> V_251 = 1 ;
for ( V_8 = 0 ; V_8 < F_26 -> V_251 ; ++ V_8 ) {
V_245 = & F_26 -> V_253 [ V_8 ] ;
F_97 ( F_26 , V_254 , V_8 ) ;
V_245 -> V_255 = F_99 ( F_26 , V_256 ) ;
V_245 -> V_257 = F_99 ( F_26 , V_258 ) ;
V_245 -> V_259 = F_99 ( F_26 , V_260 ) ;
V_245 -> V_27 = F_99 ( F_26 , V_261 ) ;
V_245 -> V_28 = F_99 ( F_26 , V_262 ) ;
F_97 ( F_26 , V_254 , V_263 ) ;
if ( V_8 == 0 && F_26 -> V_251 == 1 &&
V_245 -> V_27 == 0 && V_245 -> V_28 == 0 ) {
V_245 -> V_27 = F_26 -> V_246 - V_245 -> V_257 ;
V_245 -> V_28 = F_26 -> V_247 - V_245 -> V_259 ;
}
}
return 0 ;
}
int F_101 ( struct V_24 * F_26 )
{
struct V_244 * V_245 ;
T_6 V_8 ;
F_97 ( F_26 , V_240 , F_26 -> V_246 ) ;
F_97 ( F_26 , V_241 , F_26 -> V_247 ) ;
F_97 ( F_26 , V_242 , F_26 -> V_248 ) ;
if ( F_26 -> V_236 & V_237 )
F_97 ( F_26 , V_238 ,
F_26 -> V_249 ) ;
else if ( F_98 ( F_26 ) )
F_23 ( F_26 -> V_249 ,
F_26 -> V_56 + V_239 ) ;
if ( ! ( F_26 -> V_236 & V_250 ) )
return 0 ;
for ( V_8 = 0 ; V_8 < F_26 -> V_251 ; ++ V_8 ) {
V_245 = & F_26 -> V_253 [ V_8 ] ;
F_97 ( F_26 , V_254 , V_8 ) ;
F_97 ( F_26 , V_256 , V_245 -> V_255 ) ;
F_97 ( F_26 , V_258 , V_245 -> V_257 ) ;
F_97 ( F_26 , V_260 , V_245 -> V_259 ) ;
F_97 ( F_26 , V_261 , V_245 -> V_27 ) ;
F_97 ( F_26 , V_262 , V_245 -> V_28 ) ;
F_97 ( F_26 , V_254 , V_263 ) ;
}
return 0 ;
}
bool F_77 ( struct V_24 * V_25 ,
T_6 V_103 ,
T_6 V_28 )
{
return ( ( V_264 ) V_103 * ( V_264 ) V_28 ) < ( V_264 ) V_25 -> V_265 ;
}
T_2 F_102 ( struct V_104 * V_66 , int V_21 )
{
return 0 ;
}
int F_103 ( struct V_104 * V_66 , int V_21 )
{
return - V_155 ;
}
void F_104 ( struct V_104 * V_66 , int V_21 )
{
}
int F_105 ( struct V_24 * V_25 , unsigned V_138 ,
struct V_210 * V_2 )
{
struct V_104 * V_66 = V_25 -> V_66 ;
struct V_17 * V_18 ;
struct V_266 * V_267 ;
F_33 ( & V_66 -> V_105 . V_71 ) ;
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
F_38 (con, &dev->mode_config.connector_list, head) {
V_18 = F_106 ( V_267 ) ;
if ( V_138 > V_18 -> V_137 ) {
V_18 -> V_268 = V_2 [ V_18 -> V_137 ] . V_101 ;
V_18 -> V_269 = V_2 [ V_18 -> V_137 ] . V_102 ;
V_18 -> V_270 = true ;
V_18 -> V_271 = V_2 [ V_18 -> V_137 ] . V_53 ;
V_18 -> V_272 = V_2 [ V_18 -> V_137 ] . V_54 ;
} else {
V_18 -> V_268 = 800 ;
V_18 -> V_269 = 600 ;
V_18 -> V_270 = false ;
}
V_267 -> V_273 = F_107 ( V_267 , true ) ;
}
F_29 ( & V_66 -> V_105 . V_71 ) ;
return 0 ;
}
int F_108 ( struct V_62 * V_21 ,
struct V_106 * V_132 ,
struct V_274 * V_275 )
{
struct V_24 * V_25 = F_26 ( V_21 -> V_66 ) ;
struct V_106 * V_276 = V_21 -> V_132 ;
struct V_116 * V_195 = F_109 ( V_132 ) ;
struct V_63 * V_64 ;
struct V_122 * V_277 = NULL ;
struct V_1 V_119 ;
int V_47 ;
if ( V_275 == NULL )
return - V_35 ;
if ( ! V_25 -> V_148 )
return - V_155 ;
V_64 = V_275 -> V_50 . V_64 ;
if ( ! F_110 ( V_25 , V_21 ) )
return - V_35 ;
V_21 -> V_132 = V_132 ;
V_119 . V_10 = V_119 . y1 = 0 ;
V_119 . V_11 = V_132 -> V_27 ;
V_119 . V_12 = V_132 -> V_28 ;
if ( V_195 -> V_40 )
V_47 = F_64 ( V_64 , V_25 , V_195 ,
0 , 0 , & V_119 , 1 , 1 , & V_277 ) ;
else
V_47 = F_46 ( V_25 , V_64 , V_195 ,
0 , 0 , & V_119 , 1 , 1 , & V_277 ) ;
if ( V_47 != 0 )
goto V_278;
if ( ! V_277 ) {
V_47 = - V_35 ;
goto V_278;
}
V_47 = F_111 ( V_64 , V_277 ,
& V_275 -> V_50 ,
& V_275 -> V_275 . V_279 ,
& V_275 -> V_275 . V_280 ,
true ) ;
F_49 ( & V_277 ) ;
if ( F_28 ( V_21 ) -> V_281 )
F_112 ( V_25 , V_21 ) ;
return V_47 ;
V_278:
V_21 -> V_132 = V_276 ;
return V_47 ;
}
void F_113 ( struct V_62 * V_21 )
{
}
void F_114 ( struct V_62 * V_21 )
{
}
void F_115 ( struct V_62 * V_21 ,
T_18 * V_282 , T_18 * V_283 , T_18 * V_284 ,
T_6 V_285 , T_6 V_92 )
{
struct V_24 * V_25 = F_26 ( V_21 -> V_66 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_92 ; V_8 ++ ) {
F_116 ( L_25 , V_8 ,
V_282 [ V_8 ] , V_283 [ V_8 ] , V_284 [ V_8 ] ) ;
F_97 ( V_25 , V_286 + V_8 * 3 + 0 , V_282 [ V_8 ] >> 8 ) ;
F_97 ( V_25 , V_286 + V_8 * 3 + 1 , V_283 [ V_8 ] >> 8 ) ;
F_97 ( V_25 , V_286 + V_8 * 3 + 2 , V_284 [ V_8 ] >> 8 ) ;
}
}
void F_117 ( struct V_266 * V_23 , int V_139 )
{
}
void F_118 ( struct V_266 * V_23 )
{
}
void F_119 ( struct V_266 * V_23 )
{
}
enum V_287
F_107 ( struct V_266 * V_23 , bool V_288 )
{
T_6 V_251 ;
struct V_104 * V_66 = V_23 -> V_66 ;
struct V_24 * V_25 = F_26 ( V_66 ) ;
struct V_17 * V_18 = F_106 ( V_23 ) ;
F_33 ( & V_25 -> V_289 ) ;
V_251 = F_99 ( V_25 , V_290 ) ;
F_29 ( & V_25 -> V_289 ) ;
return ( ( F_106 ( V_23 ) -> V_137 < V_251 &&
V_18 -> V_270 ) ?
V_291 : V_292 ) ;
}
static void F_120 ( struct V_293 * V_139 )
{
V_139 -> V_294 = V_139 -> V_140 + 50 ;
V_139 -> V_295 = V_139 -> V_294 + 50 ;
V_139 -> V_296 = V_139 -> V_295 + 50 ;
V_139 -> V_297 = V_139 -> V_141 + 50 ;
V_139 -> V_298 = V_139 -> V_297 + 50 ;
V_139 -> V_299 = V_139 -> V_298 + 50 ;
V_139 -> clock = ( T_2 ) V_139 -> V_296 * ( T_2 ) V_139 -> V_299 / 100 * 6 ;
V_139 -> V_300 = F_121 ( V_139 ) ;
}
int F_122 ( struct V_266 * V_23 ,
T_6 V_224 , T_6 V_225 )
{
struct V_17 * V_18 = F_106 ( V_23 ) ;
struct V_104 * V_66 = V_23 -> V_66 ;
struct V_24 * V_25 = F_26 ( V_66 ) ;
struct V_293 * V_139 = NULL ;
struct V_293 * V_301 ;
struct V_293 V_302 = { F_123 ( L_26 ,
DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC)
} ;
int V_8 ;
{
V_139 = F_124 ( V_66 , & V_302 ) ;
if ( ! V_139 )
return 0 ;
V_139 -> V_140 = V_18 -> V_268 ;
V_139 -> V_141 = V_18 -> V_269 ;
F_120 ( V_139 ) ;
if ( F_77 ( V_25 , V_139 -> V_140 * 2 ,
V_139 -> V_141 ) ) {
F_125 ( V_23 , V_139 ) ;
} else {
F_126 ( V_66 , V_139 ) ;
V_139 = NULL ;
}
if ( V_18 -> V_303 ) {
F_127 ( & V_18 -> V_303 -> V_114 ) ;
F_126 ( V_66 , V_18 -> V_303 ) ;
}
V_18 -> V_303 = V_139 ;
}
for ( V_8 = 0 ; V_304 [ V_8 ] . type != 0 ; V_8 ++ ) {
V_301 = & V_304 [ V_8 ] ;
if ( V_301 -> V_140 > V_224 ||
V_301 -> V_141 > V_225 )
continue;
if ( ! F_77 ( V_25 , V_301 -> V_140 * 2 ,
V_301 -> V_141 ) )
continue;
V_139 = F_124 ( V_66 , V_301 ) ;
if ( ! V_139 )
return 0 ;
V_139 -> V_300 = F_121 ( V_139 ) ;
F_125 ( V_23 , V_139 ) ;
}
if ( V_18 -> V_303 )
F_128 ( & V_18 -> V_303 -> V_114 , & V_23 -> V_305 ) ;
F_129 ( V_23 ) ;
return 1 ;
}
int F_130 ( struct V_266 * V_23 ,
struct V_306 * V_307 ,
T_19 V_308 )
{
return 0 ;
}
int F_131 ( struct V_104 * V_66 , void * V_226 ,
struct V_63 * V_64 )
{
struct V_24 * V_25 = F_26 ( V_66 ) ;
struct V_309 * V_228 =
(struct V_309 * ) V_226 ;
struct V_110 * V_111 = V_110 ( V_64 -> V_112 ) ;
void T_16 * V_310 ;
struct V_210 * V_2 ;
unsigned V_311 ;
int V_47 ;
int V_8 ;
struct V_312 * V_105 = & V_66 -> V_105 ;
V_47 = F_52 ( & V_111 -> V_149 , true ) ;
if ( F_12 ( V_47 != 0 ) )
return V_47 ;
if ( ! V_228 -> V_313 ) {
struct V_210 V_314 = { 0 , 0 , 800 , 600 } ;
F_105 ( V_25 , 1 , & V_314 ) ;
goto V_315;
}
V_311 = V_228 -> V_313 * sizeof( struct V_210 ) ;
V_2 = F_132 ( V_228 -> V_313 , sizeof( struct V_210 ) ,
V_133 ) ;
if ( F_12 ( ! V_2 ) ) {
V_47 = - V_36 ;
goto V_315;
}
V_310 = ( void T_16 * ) ( unsigned long ) V_228 -> V_2 ;
V_47 = F_133 ( V_2 , V_310 , V_311 ) ;
if ( F_12 ( V_47 != 0 ) ) {
F_13 ( L_27 ) ;
V_47 = - V_316 ;
goto V_317;
}
for ( V_8 = 0 ; V_8 < V_228 -> V_313 ; ++ V_8 ) {
if ( V_2 [ V_8 ] . V_53 < 0 ||
V_2 [ V_8 ] . V_54 < 0 ||
V_2 [ V_8 ] . V_53 + V_2 [ V_8 ] . V_101 > V_105 -> V_224 ||
V_2 [ V_8 ] . V_54 + V_2 [ V_8 ] . V_102 > V_105 -> V_225 ) {
F_13 ( L_28 ) ;
V_47 = - V_35 ;
goto V_317;
}
}
F_105 ( V_25 , V_228 -> V_313 , V_2 ) ;
V_317:
F_45 ( V_2 ) ;
V_315:
F_53 ( & V_111 -> V_149 ) ;
return V_47 ;
}
