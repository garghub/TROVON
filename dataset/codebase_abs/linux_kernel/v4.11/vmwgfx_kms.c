void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_2 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_4 )
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_5 ( & V_2 -> V_6 ) ;
F_6 ( & V_2 -> V_7 ) ;
F_7 ( & V_2 -> V_5 ) ;
}
int F_8 ( struct V_8 * V_9 ,
T_1 * V_10 , T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
struct {
T_1 V_15 ;
T_2 V_16 ;
} * V_15 ;
T_1 V_17 = V_11 * V_12 * 4 ;
T_1 V_18 = sizeof( * V_15 ) + V_17 ;
if ( ! V_10 )
return - V_19 ;
V_15 = F_9 ( V_9 , V_18 ) ;
if ( F_10 ( V_15 == NULL ) ) {
F_11 ( L_1 ) ;
return - V_20 ;
}
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
memcpy ( & V_15 [ 1 ] , V_10 , V_17 ) ;
V_15 -> V_15 = V_21 ;
V_15 -> V_16 . V_22 = 0 ;
V_15 -> V_16 . V_11 = V_11 ;
V_15 -> V_16 . V_12 = V_12 ;
V_15 -> V_16 . V_13 = V_13 ;
V_15 -> V_16 . V_14 = V_14 ;
F_12 ( V_9 , V_18 ) ;
return 0 ;
}
int F_13 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
struct V_25 V_26 ;
unsigned long V_27 ;
unsigned long V_28 ;
void * V_29 ;
bool V_30 ;
int V_31 ;
V_27 = 0 ;
V_28 = ( V_11 * V_12 * 4 + V_32 - 1 ) >> V_33 ;
V_31 = F_14 ( & V_24 -> V_34 , true , false , NULL ) ;
if ( F_10 ( V_31 != 0 ) ) {
F_11 ( L_2 ) ;
return - V_19 ;
}
V_31 = F_15 ( & V_24 -> V_34 , V_27 , V_28 , & V_26 ) ;
if ( F_10 ( V_31 != 0 ) )
goto V_35;
V_29 = F_16 ( & V_26 , & V_30 ) ;
V_31 = F_8 ( V_9 , V_29 , V_11 , V_12 ,
V_13 , V_14 ) ;
F_17 ( & V_26 ) ;
V_35:
F_18 ( & V_24 -> V_34 ) ;
return V_31 ;
}
void F_19 ( struct V_8 * V_9 ,
bool V_36 , int V_37 , int V_38 )
{
T_1 * V_39 = V_9 -> V_40 ;
T_3 V_41 ;
F_20 ( V_36 ? 1 : 0 , V_39 + V_42 ) ;
F_20 ( V_37 , V_39 + V_43 ) ;
F_20 ( V_38 , V_39 + V_44 ) ;
V_41 = F_21 ( V_39 + V_45 ) ;
F_20 ( ++ V_41 , V_39 + V_45 ) ;
}
int F_22 ( struct V_46 * V_6 , struct V_47 * V_48 ,
T_3 V_49 , T_3 V_11 , T_3 V_12 ,
T_4 V_50 , T_4 V_51 )
{
struct V_8 * V_9 = F_23 ( V_6 -> V_52 ) ;
struct V_1 * V_2 = F_24 ( V_6 ) ;
struct V_53 * V_54 = NULL ;
struct V_23 * V_24 = NULL ;
T_5 V_55 , V_56 ;
int V_31 ;
F_25 ( V_6 ) ;
F_26 ( V_9 -> V_52 ) ;
V_55 = V_50 + V_2 -> V_55 ;
V_56 = V_51 + V_2 -> V_56 ;
if ( V_49 && ( V_11 != 64 || V_12 != 64 ) ) {
V_31 = - V_19 ;
goto V_57;
}
if ( V_49 ) {
struct V_58 * V_59 = F_27 ( V_48 ) -> V_59 ;
V_31 = F_28 ( V_9 , V_59 ,
V_49 , & V_54 , & V_24 ) ;
if ( V_31 ) {
F_11 ( L_3 , V_31 ) ;
V_31 = - V_19 ;
goto V_57;
}
}
if ( V_54 && ! V_54 -> V_60 . V_10 ) {
F_11 ( L_4 ) ;
F_2 ( & V_54 ) ;
V_31 = - V_19 ;
goto V_57;
}
if ( V_2 -> V_3 ) {
V_2 -> V_3 -> V_60 . V_6 = NULL ;
F_2 ( & V_2 -> V_3 ) ;
}
if ( V_2 -> V_4 )
F_3 ( & V_2 -> V_4 ) ;
V_31 = 0 ;
if ( V_54 ) {
V_2 -> V_3 = V_54 ;
V_2 -> V_3 -> V_60 . V_6 = V_6 ;
V_2 -> V_61 = V_2 -> V_3 -> V_60 . V_62 ;
V_31 = F_8 ( V_9 , V_54 -> V_60 . V_10 ,
64 , 64 , V_55 , V_56 ) ;
} else if ( V_24 ) {
V_2 -> V_4 = V_24 ;
V_31 = F_13 ( V_9 , V_24 , V_11 , V_12 ,
V_55 , V_56 ) ;
} else {
F_19 ( V_9 , false , 0 , 0 ) ;
goto V_57;
}
if ( ! V_31 ) {
F_19 ( V_9 , true ,
V_2 -> V_63 + V_55 ,
V_2 -> V_64 + V_56 ) ;
V_2 -> V_65 = V_50 ;
V_2 -> V_66 = V_51 ;
}
V_57:
F_29 ( V_9 -> V_52 ) ;
F_30 ( V_6 , V_6 -> V_16 ) ;
return V_31 ;
}
int F_31 ( struct V_46 * V_6 , int V_37 , int V_38 )
{
struct V_8 * V_9 = F_23 ( V_6 -> V_52 ) ;
struct V_1 * V_2 = F_24 ( V_6 ) ;
bool V_67 = V_2 -> V_3 || V_2 -> V_4 ? true : false ;
V_2 -> V_63 = V_37 + V_2 -> V_68 ;
V_2 -> V_64 = V_38 + V_2 -> V_69 ;
F_25 ( V_6 ) ;
F_26 ( V_9 -> V_52 ) ;
F_19 ( V_9 , V_67 ,
V_2 -> V_63 + V_2 -> V_55 +
V_2 -> V_65 ,
V_2 -> V_64 + V_2 -> V_56 +
V_2 -> V_66 ) ;
F_29 ( V_9 -> V_52 ) ;
F_30 ( V_6 , V_6 -> V_16 ) ;
return 0 ;
}
void F_32 ( struct V_53 * V_70 ,
struct V_58 * V_59 ,
struct V_71 * V_72 ,
T_6 * V_73 )
{
struct V_25 V_26 ;
unsigned long V_27 ;
unsigned long V_28 ;
T_7 * V_74 ;
unsigned V_75 ;
void * V_29 ;
bool V_30 ;
struct V_76 {
T_6 V_73 ;
T_8 V_77 ;
} * V_15 ;
int V_78 , V_31 ;
V_15 = F_33 ( V_73 , struct V_76 , V_73 ) ;
if ( ! V_70 -> V_60 . V_10 )
return;
if ( V_15 -> V_77 . V_79 . V_80 != 0 || V_15 -> V_77 . V_79 . V_81 != 0 ) {
F_11 ( L_5 ) ;
return;
}
if ( V_15 -> V_73 . V_82 < 64 ) {
F_11 ( L_6 ) ;
return;
}
V_74 = ( T_7 * ) & V_15 [ 1 ] ;
V_75 = ( V_15 -> V_73 . V_82 - sizeof( T_8 ) ) /
sizeof( T_7 ) ;
if ( V_15 -> V_77 . V_83 . V_84 . V_85 % V_32 ||
V_74 -> V_37 != 0 || V_74 -> V_38 != 0 || V_74 -> V_86 != 0 ||
V_74 -> V_87 != 0 || V_74 -> V_88 != 0 || V_74 -> V_89 != 0 ||
V_74 -> V_90 != 1 || V_75 != 1 ) {
F_11 ( L_7 ) ;
F_11 ( L_8 ,
V_74 -> V_87 , V_74 -> V_88 , V_74 -> V_89 ,
V_74 -> V_37 , V_74 -> V_38 , V_74 -> V_86 ,
V_74 -> V_91 , V_74 -> V_92 , V_74 -> V_90 , V_75 ,
V_15 -> V_77 . V_83 . V_84 . V_85 ) ;
return;
}
V_27 = V_15 -> V_77 . V_83 . V_84 . V_85 >> V_33 ;
V_28 = ( 64 * 64 * 4 ) >> V_33 ;
V_31 = F_14 ( V_72 , true , false , NULL ) ;
if ( F_10 ( V_31 != 0 ) ) {
F_11 ( L_2 ) ;
return;
}
V_31 = F_15 ( V_72 , V_27 , V_28 , & V_26 ) ;
if ( F_10 ( V_31 != 0 ) )
goto V_35;
V_29 = F_16 ( & V_26 , & V_30 ) ;
if ( V_74 -> V_91 == 64 && V_15 -> V_77 . V_83 . V_93 == 64 * 4 ) {
memcpy ( V_70 -> V_60 . V_10 , V_29 , 64 * 64 * 4 ) ;
} else {
for ( V_78 = 0 ; V_78 < V_74 -> V_92 ; V_78 ++ )
memcpy ( V_70 -> V_60 . V_10 + V_78 * 64 ,
V_29 + V_78 * V_15 -> V_77 . V_83 . V_93 ,
V_74 -> V_91 * 4 ) ;
}
V_70 -> V_60 . V_62 ++ ;
F_17 ( & V_26 ) ;
V_35:
F_18 ( V_72 ) ;
}
void F_34 ( struct V_8 * V_9 )
{
struct V_94 * V_52 = V_9 -> V_52 ;
struct V_1 * V_2 ;
struct V_46 * V_6 ;
F_26 ( V_52 ) ;
F_35 (crtc, dev) {
V_2 = F_24 ( V_6 ) ;
V_2 -> V_55 = 0 ;
V_2 -> V_56 = 0 ;
}
F_29 ( V_52 ) ;
}
void F_36 ( struct V_8 * V_9 )
{
struct V_94 * V_52 = V_9 -> V_52 ;
struct V_1 * V_2 ;
struct V_46 * V_6 ;
F_37 ( & V_52 -> V_95 . V_96 ) ;
F_38 (crtc, &dev->mode_config.crtc_list, head) {
V_2 = F_24 ( V_6 ) ;
if ( ! V_2 -> V_3 ||
V_2 -> V_61 == V_2 -> V_3 -> V_60 . V_62 )
continue;
V_2 -> V_61 = V_2 -> V_3 -> V_60 . V_62 ;
F_8 ( V_9 ,
V_2 -> V_3 -> V_60 . V_10 ,
64 , 64 ,
V_2 -> V_55 + V_2 -> V_65 ,
V_2 -> V_56 + V_2 -> V_66 ) ;
}
F_39 ( & V_52 -> V_95 . V_96 ) ;
}
static void F_40 ( struct V_97 * V_98 )
{
struct V_99 * V_100 =
F_41 ( V_98 ) ;
F_42 ( V_98 ) ;
F_2 ( & V_100 -> V_54 ) ;
if ( V_100 -> V_34 . V_101 )
F_43 ( & V_100 -> V_34 . V_101 ) ;
F_44 ( V_100 ) ;
}
static int F_45 ( struct V_97 * V_98 ,
struct V_47 * V_48 ,
unsigned V_102 , unsigned V_103 ,
struct V_104 * V_105 ,
unsigned V_106 )
{
struct V_8 * V_9 = F_23 ( V_98 -> V_52 ) ;
struct V_99 * V_100 =
F_41 ( V_98 ) ;
struct V_104 V_107 ;
int V_31 , V_108 = 1 ;
if ( V_9 -> V_109 == V_110 )
return - V_19 ;
F_26 ( V_9 -> V_52 ) ;
V_31 = F_46 ( & V_9 -> V_111 , true ) ;
if ( F_10 ( V_31 != 0 ) ) {
F_29 ( V_9 -> V_52 ) ;
return V_31 ;
}
if ( ! V_106 ) {
V_106 = 1 ;
V_105 = & V_107 ;
V_107 . V_112 = V_107 . y1 = 0 ;
V_107 . V_113 = V_98 -> V_11 ;
V_107 . V_114 = V_98 -> V_12 ;
} else if ( V_102 & V_115 ) {
V_106 /= 2 ;
V_108 = 2 ;
}
if ( V_9 -> V_109 == V_116 )
V_31 = F_47 ( V_9 , & V_100 -> V_34 ,
V_105 , NULL , NULL , 0 , 0 ,
V_106 , V_108 , NULL ) ;
else
V_31 = F_48 ( V_9 , & V_100 -> V_34 ,
V_105 , NULL , NULL , 0 , 0 ,
V_106 , V_108 , NULL ) ;
F_49 ( V_9 , false ) ;
F_50 ( & V_9 -> V_111 ) ;
F_29 ( V_9 -> V_52 ) ;
return 0 ;
}
int F_51 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_117 * V_118 ,
struct V_119 T_9 * V_120 ,
struct V_121 * V_122 ,
T_3 V_106 )
{
switch ( V_9 -> V_109 ) {
case V_116 :
return F_52 ( V_9 , V_48 , V_118 ,
V_120 , V_122 , V_106 ) ;
case V_123 :
return F_53 ( V_9 , V_48 , V_118 ,
V_120 , NULL , V_122 , V_106 ,
1 , false , true ) ;
default:
F_54 ( true ,
L_9 ) ;
}
return - V_124 ;
}
static int F_55 ( struct V_8 * V_9 ,
struct V_53 * V_54 ,
struct V_117 * * V_57 ,
const struct V_125
* V_126 ,
bool V_127 )
{
struct V_94 * V_52 = V_9 -> V_52 ;
struct V_99 * V_100 ;
enum V_128 V_129 ;
int V_31 ;
struct V_130 V_131 ;
if ( V_9 -> V_109 == V_110 )
return - V_124 ;
if ( F_10 ( ! V_54 -> V_132 ) )
return - V_19 ;
if ( F_10 ( V_54 -> V_133 [ 0 ] != 1 ||
V_54 -> V_134 != 1 ||
V_54 -> V_135 . V_11 < V_126 -> V_11 ||
V_54 -> V_135 . V_12 < V_126 -> V_12 ||
V_54 -> V_135 . V_136 != 1 ) ) {
F_11 ( L_10
L_11 ) ;
return - V_19 ;
}
switch ( V_126 -> V_137 ) {
case V_138 :
V_129 = V_139 ;
break;
case V_140 :
V_129 = V_141 ;
break;
case V_142 :
V_129 = V_143 ;
break;
case V_144 :
V_129 = V_145 ;
break;
default:
F_11 ( L_12 ,
F_56 ( V_126 -> V_137 , & V_131 ) ) ;
return - V_19 ;
}
if ( ! V_9 -> V_146 && V_129 != V_54 -> V_129 ) {
F_11 ( L_13 ) ;
return - V_19 ;
}
V_100 = F_57 ( sizeof( * V_100 ) , V_147 ) ;
if ( ! V_100 ) {
V_31 = - V_20 ;
goto V_148;
}
F_58 ( V_52 , & V_100 -> V_34 . V_34 , V_126 ) ;
V_100 -> V_54 = F_59 ( V_54 ) ;
V_100 -> V_34 . V_149 = V_126 -> V_150 [ 0 ] ;
V_100 -> V_127 = V_127 ;
* V_57 = & V_100 -> V_34 ;
V_31 = F_60 ( V_52 , & V_100 -> V_34 . V_34 ,
& V_151 ) ;
if ( V_31 )
goto V_152;
return 0 ;
V_152:
F_2 ( & V_54 ) ;
F_44 ( V_100 ) ;
V_148:
return V_31 ;
}
static void F_61 ( struct V_97 * V_98 )
{
struct V_153 * V_154 =
F_62 ( V_98 ) ;
F_42 ( V_98 ) ;
F_3 ( & V_154 -> V_155 ) ;
if ( V_154 -> V_34 . V_101 )
F_43 ( & V_154 -> V_34 . V_101 ) ;
F_44 ( V_154 ) ;
}
static int F_63 ( struct V_97 * V_98 ,
struct V_47 * V_48 ,
unsigned V_102 , unsigned V_103 ,
struct V_104 * V_105 ,
unsigned V_106 )
{
struct V_8 * V_9 = F_23 ( V_98 -> V_52 ) ;
struct V_153 * V_154 =
F_62 ( V_98 ) ;
struct V_104 V_107 ;
int V_31 , V_156 = 1 ;
F_26 ( V_9 -> V_52 ) ;
V_31 = F_46 ( & V_9 -> V_111 , true ) ;
if ( F_10 ( V_31 != 0 ) ) {
F_29 ( V_9 -> V_52 ) ;
return V_31 ;
}
if ( ! V_106 ) {
V_106 = 1 ;
V_105 = & V_107 ;
V_107 . V_112 = V_107 . y1 = 0 ;
V_107 . V_113 = V_98 -> V_11 ;
V_107 . V_114 = V_98 -> V_12 ;
} else if ( V_102 & V_115 ) {
V_106 /= 2 ;
V_156 = 2 ;
}
switch ( V_9 -> V_109 ) {
case V_123 :
V_31 = F_53 ( V_9 , NULL , & V_154 -> V_34 , NULL ,
V_105 , NULL , V_106 , V_156 ,
true , true ) ;
break;
case V_116 :
V_31 = F_64 ( V_9 , & V_154 -> V_34 ,
V_105 , NULL , V_106 ,
V_156 , true , NULL ) ;
break;
case V_110 :
V_31 = F_65 ( V_9 , & V_154 -> V_34 , 0 , 0 ,
V_105 , V_106 , V_156 ) ;
break;
default:
V_31 = - V_19 ;
F_54 ( true , L_14 ) ;
break;
}
F_49 ( V_9 , false ) ;
F_50 ( & V_9 -> V_111 ) ;
F_29 ( V_9 -> V_52 ) ;
return V_31 ;
}
static int F_66 ( struct V_117 * V_118 )
{
struct V_8 * V_9 = F_23 ( V_118 -> V_34 . V_52 ) ;
struct V_23 * V_157 ;
int V_31 ;
V_157 = V_118 -> V_24 ? F_62 ( & V_118 -> V_34 ) -> V_155 :
F_41 ( & V_118 -> V_34 ) -> V_54 -> V_158 . V_159 ;
if ( ! V_157 )
return 0 ;
switch ( V_9 -> V_109 ) {
case V_110 :
F_67 ( V_9 ) ;
V_31 = F_68 ( V_9 , V_157 , false ) ;
F_69 ( V_9 ) ;
break;
case V_116 :
case V_123 :
if ( V_118 -> V_24 )
return F_70 ( V_9 , V_157 ,
false ) ;
return F_71 ( V_9 , V_157 ,
& V_160 , false ) ;
default:
return - V_19 ;
}
return V_31 ;
}
static int F_72 ( struct V_117 * V_118 )
{
struct V_8 * V_9 = F_23 ( V_118 -> V_34 . V_52 ) ;
struct V_23 * V_157 ;
V_157 = V_118 -> V_24 ? F_62 ( & V_118 -> V_34 ) -> V_155 :
F_41 ( & V_118 -> V_34 ) -> V_54 -> V_158 . V_159 ;
if ( F_73 ( ! V_157 ) )
return 0 ;
return F_74 ( V_9 , V_157 , false ) ;
}
static int F_75 ( struct V_94 * V_52 ,
const struct V_125 * V_126 ,
struct V_23 * V_161 ,
struct V_53 * * V_162 )
{
T_3 V_129 ;
struct V_163 V_164 = { 0 } ;
struct V_165 * V_158 ;
unsigned int V_166 ;
struct V_130 V_131 ;
int V_31 ;
switch ( V_126 -> V_137 ) {
case V_138 :
case V_140 :
V_129 = V_141 ;
V_166 = 4 ;
break;
case V_142 :
case V_144 :
V_129 = V_143 ;
V_166 = 2 ;
break;
case 8 :
V_129 = V_167 ;
V_166 = 1 ;
break;
default:
F_11 ( L_15 ,
F_56 ( V_126 -> V_137 , & V_131 ) ) ;
return - V_19 ;
}
V_164 . V_11 = V_126 -> V_168 [ 0 ] / V_166 ;
V_164 . V_12 = V_126 -> V_12 ;
V_164 . V_136 = 1 ;
V_31 = F_76 ( V_52 ,
0 ,
0 ,
V_129 ,
true ,
1 ,
0 ,
0 ,
V_164 ,
V_162 ) ;
if ( V_31 ) {
F_11 ( L_16 ) ;
return V_31 ;
}
V_158 = & ( * V_162 ) -> V_158 ;
F_37 ( & V_158 -> V_9 -> V_169 ) ;
( void ) F_77 ( V_158 , false , true ) ;
F_3 ( & V_158 -> V_159 ) ;
V_158 -> V_159 = F_78 ( V_161 ) ;
V_158 -> V_170 = 0 ;
F_79 ( V_158 , false , NULL , 0 ) ;
F_39 ( & V_158 -> V_9 -> V_169 ) ;
return 0 ;
}
static int F_80 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
struct V_117 * * V_57 ,
const struct V_125
* V_126 )
{
struct V_94 * V_52 = V_9 -> V_52 ;
struct V_153 * V_154 ;
unsigned int V_171 ;
struct V_130 V_131 ;
int V_31 ;
V_171 = V_126 -> V_12 * V_126 -> V_168 [ 0 ] ;
if ( F_10 ( V_171 > V_24 -> V_34 . V_172 * V_32 ) ) {
F_11 ( L_17
L_11 ) ;
return - V_19 ;
}
if ( V_9 -> V_109 == V_116 ) {
switch ( V_126 -> V_137 ) {
case V_140 :
case V_138 :
break;
case V_144 :
case V_142 :
break;
default:
F_11 ( L_12 ,
F_56 ( V_126 -> V_137 , & V_131 ) ) ;
return - V_19 ;
}
}
V_154 = F_57 ( sizeof( * V_154 ) , V_147 ) ;
if ( ! V_154 ) {
V_31 = - V_20 ;
goto V_148;
}
F_58 ( V_52 , & V_154 -> V_34 . V_34 , V_126 ) ;
V_154 -> V_34 . V_24 = true ;
V_154 -> V_155 = F_78 ( V_24 ) ;
V_154 -> V_34 . V_149 = V_126 -> V_150 [ 0 ] ;
* V_57 = & V_154 -> V_34 ;
V_31 = F_60 ( V_52 , & V_154 -> V_34 . V_34 ,
& V_173 ) ;
if ( V_31 )
goto V_152;
return 0 ;
V_152:
F_3 ( & V_24 ) ;
F_44 ( V_154 ) ;
V_148:
return V_31 ;
}
struct V_117 *
F_81 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
struct V_53 * V_54 ,
bool V_174 ,
const struct V_125 * V_126 )
{
struct V_117 * V_118 = NULL ;
bool V_127 = false ;
int V_31 ;
if ( V_24 && V_174 &&
V_9 -> V_109 == V_123 ) {
V_31 = F_75 ( V_9 -> V_52 , V_126 ,
V_24 , & V_54 ) ;
if ( V_31 )
return F_82 ( V_31 ) ;
V_127 = true ;
}
if ( V_54 ) {
V_31 = F_55 ( V_9 , V_54 , & V_118 ,
V_126 ,
V_127 ) ;
if ( V_127 )
F_2 ( & V_54 ) ;
} else if ( V_24 ) {
V_31 = F_80 ( V_9 , V_24 , & V_118 ,
V_126 ) ;
} else {
F_83 () ;
}
if ( V_31 )
return F_82 ( V_31 ) ;
V_118 -> V_175 = F_66 ;
V_118 -> V_176 = F_72 ;
return V_118 ;
}
static struct V_97 * F_84 ( struct V_94 * V_52 ,
struct V_47 * V_48 ,
const struct V_125 * V_126 )
{
struct V_8 * V_9 = F_23 ( V_52 ) ;
struct V_58 * V_59 = F_27 ( V_48 ) -> V_59 ;
struct V_117 * V_118 = NULL ;
struct V_53 * V_54 = NULL ;
struct V_23 * V_72 = NULL ;
struct V_177 * V_101 ;
int V_31 ;
if ( ! F_85 ( V_9 ,
V_126 -> V_168 [ 0 ] ,
V_126 -> V_12 ) ) {
F_11 ( L_18 ) ;
return F_82 ( - V_20 ) ;
}
V_101 = F_86 ( V_59 , V_126 -> V_150 [ 0 ] ) ;
if ( F_10 ( V_101 == NULL ) ) {
F_11 ( L_19 ) ;
return F_82 ( - V_178 ) ;
}
V_31 = F_28 ( V_9 , V_59 ,
V_126 -> V_150 [ 0 ] ,
& V_54 , & V_72 ) ;
if ( V_31 )
goto V_179;
V_118 = F_81 ( V_9 , V_72 , V_54 ,
! ( V_9 -> V_180 & V_181 ) ,
V_126 ) ;
if ( F_87 ( V_118 ) ) {
V_31 = F_88 ( V_118 ) ;
goto V_179;
}
V_179:
if ( V_72 )
F_3 ( & V_72 ) ;
if ( V_54 )
F_2 ( & V_54 ) ;
if ( V_31 ) {
F_11 ( L_20 , V_31 ) ;
F_43 ( & V_101 ) ;
return F_82 ( V_31 ) ;
} else
V_118 -> V_101 = V_101 ;
return & V_118 -> V_34 ;
}
static int F_89 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_117 * V_118 ,
struct V_53 * V_54 ,
T_3 V_182 ,
T_4 V_183 , T_4 V_184 ,
struct V_121 * V_105 ,
T_3 V_106 )
{
return F_47 ( V_9 , V_118 , NULL , V_105 ,
& V_54 -> V_158 , V_183 , V_184 ,
V_106 , 1 , NULL ) ;
}
int F_90 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_117 * V_118 ,
struct V_53 * V_54 ,
T_3 V_182 ,
T_4 V_183 , T_4 V_184 ,
struct V_121 * V_105 ,
T_3 V_106 )
{
int V_31 ;
switch ( V_9 -> V_109 ) {
case V_123 :
V_31 = F_48 ( V_9 , V_118 , NULL , V_105 ,
& V_54 -> V_158 , V_183 , V_184 ,
V_106 , 1 , NULL ) ;
break;
case V_116 :
V_31 = F_89 ( V_9 , V_48 , V_118 , V_54 ,
V_182 , V_183 , V_184 , V_105 ,
V_106 ) ;
break;
default:
F_54 ( true ,
L_21 ) ;
V_31 = - V_124 ;
break;
}
if ( V_31 )
return V_31 ;
F_49 ( V_9 , false ) ;
return 0 ;
}
static void
F_91 ( struct V_8 * V_9 )
{
if ( V_9 -> V_185 )
return;
V_9 -> V_185 =
F_92 ( V_9 -> V_52 ,
V_186 ,
L_22 , 0 , 1 ) ;
if ( ! V_9 -> V_185 )
return;
}
int F_93 ( struct V_8 * V_9 )
{
struct V_94 * V_52 = V_9 -> V_52 ;
int V_31 ;
F_94 ( V_52 ) ;
V_52 -> V_95 . V_187 = & V_188 ;
V_52 -> V_95 . V_189 = 1 ;
V_52 -> V_95 . V_190 = 1 ;
V_52 -> V_95 . V_191 = V_9 -> V_192 ;
V_52 -> V_95 . V_193 = V_9 -> V_194 ;
F_95 ( V_52 ) ;
F_91 ( V_9 ) ;
V_31 = F_96 ( V_9 ) ;
if ( V_31 ) {
V_31 = F_97 ( V_9 ) ;
if ( V_31 )
V_31 = F_98 ( V_9 ) ;
}
return V_31 ;
}
int F_99 ( struct V_8 * V_9 )
{
int V_31 ;
F_100 ( V_9 -> V_52 ) ;
if ( V_9 -> V_109 == V_116 )
V_31 = F_101 ( V_9 ) ;
else if ( V_9 -> V_109 == V_123 )
V_31 = F_102 ( V_9 ) ;
else
V_31 = F_103 ( V_9 ) ;
return V_31 ;
}
int F_104 ( struct V_94 * V_52 , void * V_195 ,
struct V_47 * V_48 )
{
struct V_196 * V_197 = V_195 ;
struct V_1 * V_2 ;
struct V_46 * V_6 ;
int V_31 = 0 ;
F_37 ( & V_52 -> V_95 . V_96 ) ;
if ( V_197 -> V_102 & V_198 ) {
F_38 (crtc, &dev->mode_config.crtc_list, head) {
V_2 = F_24 ( V_6 ) ;
V_2 -> V_55 = V_197 -> V_199 ;
V_2 -> V_56 = V_197 -> V_200 ;
}
F_39 ( & V_52 -> V_95 . V_96 ) ;
return 0 ;
}
V_6 = F_105 ( V_52 , V_197 -> V_201 ) ;
if ( ! V_6 ) {
V_31 = - V_178 ;
goto V_57;
}
V_2 = F_24 ( V_6 ) ;
V_2 -> V_55 = V_197 -> V_199 ;
V_2 -> V_56 = V_197 -> V_200 ;
V_57:
F_39 ( & V_52 -> V_95 . V_96 ) ;
return V_31 ;
}
int F_106 ( struct V_8 * F_23 ,
unsigned V_11 , unsigned V_12 , unsigned V_93 ,
unsigned V_202 , unsigned V_136 )
{
if ( F_23 -> V_180 & V_203 )
F_107 ( F_23 , V_204 , V_93 ) ;
else if ( F_108 ( F_23 ) )
F_20 ( V_93 , F_23 -> V_40 +
V_205 ) ;
F_107 ( F_23 , V_206 , V_11 ) ;
F_107 ( F_23 , V_207 , V_12 ) ;
F_107 ( F_23 , V_208 , V_202 ) ;
if ( F_109 ( F_23 , V_209 ) != V_136 ) {
F_11 ( L_23 ,
V_136 , V_202 , F_109 ( F_23 , V_209 ) ) ;
return - V_19 ;
}
return 0 ;
}
int F_110 ( struct V_8 * F_23 )
{
struct V_210 * V_211 ;
T_3 V_78 ;
F_23 -> V_212 = F_109 ( F_23 , V_206 ) ;
F_23 -> V_213 = F_109 ( F_23 , V_207 ) ;
F_23 -> V_214 = F_109 ( F_23 , V_208 ) ;
if ( F_23 -> V_180 & V_203 )
F_23 -> V_215 =
F_109 ( F_23 , V_204 ) ;
else if ( F_108 ( F_23 ) )
F_23 -> V_215 = F_21 ( F_23 -> V_40 +
V_205 ) ;
if ( ! ( F_23 -> V_180 & V_216 ) )
return 0 ;
F_23 -> V_217 = F_109 ( F_23 ,
V_218 ) ;
if ( F_23 -> V_217 == 0 )
F_23 -> V_217 = 1 ;
for ( V_78 = 0 ; V_78 < F_23 -> V_217 ; ++ V_78 ) {
V_211 = & F_23 -> V_219 [ V_78 ] ;
F_107 ( F_23 , V_220 , V_78 ) ;
V_211 -> V_221 = F_109 ( F_23 , V_222 ) ;
V_211 -> V_223 = F_109 ( F_23 , V_224 ) ;
V_211 -> V_225 = F_109 ( F_23 , V_226 ) ;
V_211 -> V_11 = F_109 ( F_23 , V_227 ) ;
V_211 -> V_12 = F_109 ( F_23 , V_228 ) ;
F_107 ( F_23 , V_220 , V_229 ) ;
if ( V_78 == 0 && F_23 -> V_217 == 1 &&
V_211 -> V_11 == 0 && V_211 -> V_12 == 0 ) {
V_211 -> V_11 = F_23 -> V_212 - V_211 -> V_223 ;
V_211 -> V_12 = F_23 -> V_213 - V_211 -> V_225 ;
}
}
return 0 ;
}
int F_111 ( struct V_8 * F_23 )
{
struct V_210 * V_211 ;
T_3 V_78 ;
F_107 ( F_23 , V_206 , F_23 -> V_212 ) ;
F_107 ( F_23 , V_207 , F_23 -> V_213 ) ;
F_107 ( F_23 , V_208 , F_23 -> V_214 ) ;
if ( F_23 -> V_180 & V_203 )
F_107 ( F_23 , V_204 ,
F_23 -> V_215 ) ;
else if ( F_108 ( F_23 ) )
F_20 ( F_23 -> V_215 ,
F_23 -> V_40 + V_205 ) ;
if ( ! ( F_23 -> V_180 & V_216 ) )
return 0 ;
for ( V_78 = 0 ; V_78 < F_23 -> V_217 ; ++ V_78 ) {
V_211 = & F_23 -> V_219 [ V_78 ] ;
F_107 ( F_23 , V_220 , V_78 ) ;
F_107 ( F_23 , V_222 , V_211 -> V_221 ) ;
F_107 ( F_23 , V_224 , V_211 -> V_223 ) ;
F_107 ( F_23 , V_226 , V_211 -> V_225 ) ;
F_107 ( F_23 , V_227 , V_211 -> V_11 ) ;
F_107 ( F_23 , V_228 , V_211 -> V_12 ) ;
F_107 ( F_23 , V_220 , V_229 ) ;
}
return 0 ;
}
bool F_85 ( struct V_8 * V_9 ,
T_3 V_93 ,
T_3 V_12 )
{
return ( ( V_230 ) V_93 * ( V_230 ) V_12 ) < ( V_230 )
( ( V_9 -> V_109 == V_123 ) ?
V_9 -> V_231 : V_9 -> V_232 ) ;
}
T_1 F_112 ( struct V_94 * V_52 , unsigned int V_233 )
{
return 0 ;
}
int F_113 ( struct V_94 * V_52 , unsigned int V_233 )
{
return - V_124 ;
}
void F_114 ( struct V_94 * V_52 , unsigned int V_233 )
{
}
static int F_115 ( struct V_8 * V_9 , unsigned V_234 ,
struct V_121 * V_235 )
{
struct V_94 * V_52 = V_9 -> V_52 ;
struct V_1 * V_2 ;
struct V_236 * V_237 ;
F_37 ( & V_52 -> V_95 . V_96 ) ;
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
V_2 = F_116 ( V_237 ) ;
if ( V_234 > V_2 -> V_238 ) {
V_2 -> V_239 = V_235 [ V_2 -> V_238 ] . V_91 ;
V_2 -> V_240 = V_235 [ V_2 -> V_238 ] . V_92 ;
V_2 -> V_241 = true ;
V_2 -> V_242 = V_235 [ V_2 -> V_238 ] . V_37 ;
V_2 -> V_243 = V_235 [ V_2 -> V_238 ] . V_38 ;
F_117
( & V_237 -> V_34 , V_52 -> V_95 . V_244 ,
V_2 -> V_242 ) ;
F_117
( & V_237 -> V_34 , V_52 -> V_95 . V_245 ,
V_2 -> V_243 ) ;
} else {
V_2 -> V_239 = 800 ;
V_2 -> V_240 = 600 ;
V_2 -> V_241 = false ;
F_117
( & V_237 -> V_34 , V_52 -> V_95 . V_244 ,
0 ) ;
F_117
( & V_237 -> V_34 , V_52 -> V_95 . V_245 ,
0 ) ;
}
V_237 -> V_246 = F_118 ( V_237 , true ) ;
}
F_39 ( & V_52 -> V_95 . V_96 ) ;
F_119 ( V_52 ) ;
return 0 ;
}
int F_120 ( struct V_46 * V_6 ,
T_10 * V_247 , T_10 * V_248 , T_10 * V_249 ,
T_3 V_82 )
{
struct V_8 * V_9 = F_23 ( V_6 -> V_52 ) ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_82 ; V_78 ++ ) {
F_121 ( L_24 , V_78 ,
V_247 [ V_78 ] , V_248 [ V_78 ] , V_249 [ V_78 ] ) ;
F_107 ( V_9 , V_250 + V_78 * 3 + 0 , V_247 [ V_78 ] >> 8 ) ;
F_107 ( V_9 , V_250 + V_78 * 3 + 1 , V_248 [ V_78 ] >> 8 ) ;
F_107 ( V_9 , V_250 + V_78 * 3 + 2 , V_249 [ V_78 ] >> 8 ) ;
}
return 0 ;
}
int F_122 ( struct V_236 * V_5 , int V_251 )
{
return 0 ;
}
enum V_252
F_118 ( struct V_236 * V_5 , bool V_253 )
{
T_3 V_217 ;
struct V_94 * V_52 = V_5 -> V_52 ;
struct V_8 * V_9 = F_23 ( V_52 ) ;
struct V_1 * V_2 = F_116 ( V_5 ) ;
V_217 = F_109 ( V_9 , V_254 ) ;
return ( ( F_116 ( V_5 ) -> V_238 < V_217 &&
V_2 -> V_241 ) ?
V_255 : V_256 ) ;
}
void F_123 ( struct V_257 * V_251 )
{
V_251 -> V_258 = V_251 -> V_259 + 50 ;
V_251 -> V_260 = V_251 -> V_258 + 50 ;
V_251 -> V_261 = V_251 -> V_260 + 50 ;
V_251 -> V_262 = V_251 -> V_263 + 50 ;
V_251 -> V_264 = V_251 -> V_262 + 50 ;
V_251 -> V_265 = V_251 -> V_264 + 50 ;
V_251 -> clock = ( T_1 ) V_251 -> V_261 * ( T_1 ) V_251 -> V_265 / 100 * 6 ;
V_251 -> V_266 = F_124 ( V_251 ) ;
}
int F_125 ( struct V_236 * V_5 ,
T_3 V_191 , T_3 V_193 )
{
struct V_1 * V_2 = F_116 ( V_5 ) ;
struct V_94 * V_52 = V_5 -> V_52 ;
struct V_8 * V_9 = F_23 ( V_52 ) ;
struct V_257 * V_251 = NULL ;
struct V_257 * V_267 ;
struct V_257 V_268 = { F_126 ( L_25 ,
DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC)
} ;
int V_78 ;
T_1 V_269 = 4 ;
if ( V_9 -> V_270 )
V_269 = 2 ;
if ( V_9 -> V_109 == V_123 ) {
V_191 = F_127 ( V_191 , V_9 -> V_271 ) ;
V_193 = F_127 ( V_193 , V_9 -> V_272 ) ;
}
V_251 = F_128 ( V_52 , & V_268 ) ;
if ( ! V_251 )
return 0 ;
V_251 -> V_259 = V_2 -> V_239 ;
V_251 -> V_263 = V_2 -> V_240 ;
F_123 ( V_251 ) ;
if ( F_85 ( V_9 ,
V_251 -> V_259 * V_269 ,
V_251 -> V_263 ) ) {
F_129 ( V_5 , V_251 ) ;
} else {
F_130 ( V_52 , V_251 ) ;
V_251 = NULL ;
}
if ( V_2 -> V_273 ) {
F_131 ( & V_2 -> V_273 -> V_274 ) ;
F_130 ( V_52 , V_2 -> V_273 ) ;
}
V_2 -> V_273 = V_251 ;
for ( V_78 = 0 ; V_275 [ V_78 ] . type != 0 ; V_78 ++ ) {
V_267 = & V_275 [ V_78 ] ;
if ( V_267 -> V_259 > V_191 ||
V_267 -> V_263 > V_193 )
continue;
if ( ! F_85 ( V_9 ,
V_267 -> V_259 * V_269 ,
V_267 -> V_263 ) )
continue;
V_251 = F_128 ( V_52 , V_267 ) ;
if ( ! V_251 )
return 0 ;
V_251 -> V_266 = F_124 ( V_251 ) ;
F_129 ( V_5 , V_251 ) ;
}
F_132 ( V_5 ) ;
F_133 ( & V_5 -> V_276 ) ;
return 1 ;
}
int F_134 ( struct V_236 * V_5 ,
struct V_277 * V_278 ,
T_11 V_279 )
{
struct V_1 * V_2 = F_116 ( V_5 ) ;
struct V_8 * V_9 = F_23 ( V_5 -> V_52 ) ;
if ( V_278 == V_9 -> V_280 )
V_2 -> V_281 = V_279 ;
return 0 ;
}
int F_135 ( struct V_94 * V_52 , void * V_195 ,
struct V_47 * V_48 )
{
struct V_8 * V_9 = F_23 ( V_52 ) ;
struct V_282 * V_197 =
(struct V_282 * ) V_195 ;
void T_9 * V_283 ;
struct V_121 * V_235 ;
unsigned V_284 ;
int V_31 ;
int V_78 ;
V_230 V_285 = 0 ;
struct V_286 * V_95 = & V_52 -> V_95 ;
struct V_121 V_287 = { 0 } ;
if ( ! V_197 -> V_288 ) {
struct V_121 V_289 = { 0 , 0 , 800 , 600 } ;
F_115 ( V_9 , 1 , & V_289 ) ;
return 0 ;
}
V_284 = V_197 -> V_288 * sizeof( struct V_121 ) ;
V_235 = F_136 ( V_197 -> V_288 , sizeof( struct V_121 ) ,
V_147 ) ;
if ( F_10 ( ! V_235 ) )
return - V_20 ;
V_283 = ( void T_9 * ) ( unsigned long ) V_197 -> V_235 ;
V_31 = F_137 ( V_235 , V_283 , V_284 ) ;
if ( F_10 ( V_31 != 0 ) ) {
F_11 ( L_26 ) ;
V_31 = - V_290 ;
goto V_291;
}
for ( V_78 = 0 ; V_78 < V_197 -> V_288 ; ++ V_78 ) {
if ( V_235 [ V_78 ] . V_37 < 0 ||
V_235 [ V_78 ] . V_38 < 0 ||
V_235 [ V_78 ] . V_37 + V_235 [ V_78 ] . V_91 > V_95 -> V_191 ||
V_235 [ V_78 ] . V_38 + V_235 [ V_78 ] . V_92 > V_95 -> V_193 ) {
F_11 ( L_27 ) ;
V_31 = - V_19 ;
goto V_291;
}
if ( V_235 [ V_78 ] . V_37 + V_235 [ V_78 ] . V_91 > V_287 . V_91 )
V_287 . V_91 = V_235 [ V_78 ] . V_37 + V_235 [ V_78 ] . V_91 ;
if ( V_235 [ V_78 ] . V_38 + V_235 [ V_78 ] . V_92 > V_287 . V_92 )
V_287 . V_92 = V_235 [ V_78 ] . V_38 + V_235 [ V_78 ] . V_92 ;
V_285 += ( V_230 ) V_235 [ V_78 ] . V_91 * ( V_230 ) V_235 [ V_78 ] . V_92 ;
}
if ( V_9 -> V_109 == V_123 ) {
V_230 V_292 = ( V_230 ) V_287 . V_91 * V_287 . V_92 * 4 ;
V_230 V_293 = V_285 * 4 ;
if ( V_292 > V_9 -> V_231 ) {
F_11 ( L_28 ) ;
V_31 = - V_19 ;
goto V_291;
}
if ( V_293 > V_9 -> V_231 ) {
F_11 ( L_29 ) ;
V_31 = - V_19 ;
goto V_291;
}
}
F_115 ( V_9 , V_197 -> V_288 , V_235 ) ;
V_291:
F_44 ( V_235 ) ;
return V_31 ;
}
int F_138 ( struct V_8 * V_9 ,
struct V_117 * V_98 ,
const struct V_104 * V_105 ,
const struct V_121 * V_122 ,
T_5 V_294 , T_5 V_295 ,
int V_106 ,
int V_156 ,
struct V_296 * V_297 )
{
struct V_1 * V_298 [ V_299 ] ;
struct V_46 * V_6 ;
T_1 V_300 = 0 ;
T_1 V_78 , V_301 ;
V_297 -> V_9 = V_9 ;
F_38 (crtc, &dev_priv->dev->mode_config.crtc_list, head) {
if ( V_6 -> V_221 -> V_302 != & V_98 -> V_34 )
continue;
V_298 [ V_300 ++ ] = F_24 ( V_6 ) ;
}
for ( V_301 = 0 ; V_301 < V_300 ; V_301 ++ ) {
struct V_1 * V_238 = V_298 [ V_301 ] ;
T_5 V_303 = V_238 -> V_6 . V_37 ;
T_5 V_304 = V_238 -> V_6 . V_38 ;
T_5 V_305 = V_238 -> V_6 . V_251 . V_259 ;
T_5 V_306 = V_238 -> V_6 . V_251 . V_263 ;
const struct V_104 * V_307 = V_105 ;
const struct V_121 * V_308 = V_122 ;
V_297 -> V_238 = V_238 ;
if ( V_297 -> V_309 > 0 ) {
V_297 -> V_15 = F_9 ( V_9 ,
V_297 -> V_309 ) ;
if ( ! V_297 -> V_15 ) {
F_11 ( L_30
L_31 ) ;
return - V_20 ;
}
memset ( V_297 -> V_15 , 0 , V_297 -> V_309 ) ;
}
V_297 -> V_310 = 0 ;
for ( V_78 = 0 ; V_78 < V_106 ; V_78 ++ , V_307 += V_156 ,
V_308 += V_156 ) {
T_5 V_311 ;
T_5 V_312 ;
if ( V_105 ) {
V_297 -> V_313 = ( T_5 ) V_307 -> V_112 ;
V_297 -> V_314 = ( T_5 ) V_307 -> y1 ;
V_297 -> V_315 = ( T_5 ) V_307 -> V_113 + V_294 -
V_303 ;
V_297 -> V_316 = ( T_5 ) V_307 -> V_114 + V_295 -
V_304 ;
} else {
V_297 -> V_313 = V_308 -> V_37 ;
V_297 -> V_314 = V_308 -> V_38 ;
V_297 -> V_315 = V_297 -> V_313 + V_308 -> V_91 +
V_294 - V_303 ;
V_297 -> V_316 = V_297 -> V_314 + V_308 -> V_92 +
V_295 - V_304 ;
}
V_297 -> V_317 = V_297 -> V_313 + V_294 - V_303 ;
V_297 -> V_318 = V_297 -> V_314 + V_295 - V_304 ;
if ( V_297 -> V_317 >= V_305 ||
V_297 -> V_318 >= V_306 ||
V_297 -> V_315 <= 0 || V_297 -> V_316 <= 0 )
continue;
V_297 -> V_315 = F_139 ( T_5 , V_297 -> V_315 ,
V_305 ) ;
V_297 -> V_316 = F_139 ( T_5 , V_297 -> V_316 ,
V_306 ) ;
V_311 = F_139 ( T_5 , V_297 -> V_317 , 0 ) ;
V_312 = F_139 ( T_5 , V_297 -> V_318 , 0 ) ;
V_297 -> V_317 -= V_311 ;
V_297 -> V_318 -= V_312 ;
V_297 -> V_313 -= V_311 ;
V_297 -> V_314 -= V_312 ;
V_297 -> V_319 ( V_297 ) ;
}
V_297 -> V_320 ( V_297 ) ;
}
return 0 ;
}
int F_140 ( struct V_8 * V_9 ,
struct V_23 * V_157 ,
bool V_321 ,
bool V_322 )
{
struct V_71 * V_72 = & V_157 -> V_34 ;
int V_31 ;
F_14 ( V_72 , false , false , NULL ) ;
V_31 = F_141 ( V_9 , V_72 , V_321 ,
V_322 ) ;
if ( V_31 )
F_18 ( V_72 ) ;
return V_31 ;
}
void F_142 ( struct V_23 * V_157 )
{
if ( V_157 )
F_18 ( & V_157 -> V_34 ) ;
}
void F_143 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_23 * V_157 ,
struct V_323 * * V_324 ,
struct V_119 T_9 *
V_120 )
{
struct V_323 * V_325 ;
T_3 V_49 ;
int V_31 ;
V_31 = F_144 ( V_48 , V_9 , & V_325 ,
V_48 ? & V_49 : NULL ) ;
if ( V_157 )
F_145 ( & V_157 -> V_34 , V_325 ) ;
if ( V_48 )
F_146 ( V_9 , F_27 ( V_48 ) ,
V_31 , V_120 , V_325 ,
V_49 ) ;
if ( V_324 )
* V_324 = V_325 ;
else
F_147 ( & V_325 ) ;
F_142 ( V_157 ) ;
}
void F_148 ( struct V_165 * V_158 )
{
F_142 ( V_158 -> V_159 ) ;
F_79 ( V_158 , false , NULL , 0 ) ;
F_39 ( & V_158 -> V_9 -> V_169 ) ;
}
int F_149 ( struct V_165 * V_158 ,
bool V_321 )
{
int V_31 = 0 ;
if ( V_321 )
V_31 = F_150 ( & V_158 -> V_9 -> V_169 ) ;
else
F_37 ( & V_158 -> V_9 -> V_169 ) ;
if ( F_10 ( V_31 != 0 ) )
return - V_326 ;
V_31 = F_77 ( V_158 , V_321 , false ) ;
if ( V_31 )
goto V_327;
if ( V_158 -> V_159 ) {
V_31 = F_140 ( V_158 -> V_9 , V_158 -> V_159 ,
V_321 ,
V_158 -> V_9 -> V_328 ) ;
if ( V_31 )
goto V_329;
}
V_31 = F_151 ( V_158 ) ;
if ( V_31 )
goto V_330;
return 0 ;
V_330:
F_142 ( V_158 -> V_159 ) ;
V_329:
F_79 ( V_158 , false , NULL , 0 ) ;
V_327:
F_39 ( & V_158 -> V_9 -> V_169 ) ;
return V_31 ;
}
void F_152 ( struct V_165 * V_158 ,
struct V_323 * * V_324 )
{
if ( V_158 -> V_159 || V_324 )
F_143 ( V_158 -> V_9 , NULL , V_158 -> V_159 ,
V_324 , NULL ) ;
F_79 ( V_158 , false , NULL , 0 ) ;
F_39 ( & V_158 -> V_9 -> V_169 ) ;
}
int F_153 ( struct V_165 * V_158 ,
const struct V_104 * V_105 ,
unsigned V_106 ,
int V_156 )
{
struct V_8 * V_9 = V_158 -> V_9 ;
struct V_163 * V_82 = & F_154 ( V_158 ) -> V_135 ;
struct {
T_6 V_73 ;
T_12 V_331 ;
} * V_15 ;
T_13 * V_74 ;
T_14 V_332 = 0 ;
int V_78 ;
if ( ! V_105 )
return 0 ;
V_15 = F_9 ( V_9 , sizeof( * V_15 ) * V_106 ) ;
if ( ! V_15 ) {
F_11 ( L_32
L_33 ) ;
return - V_20 ;
}
for ( V_78 = 0 ; V_78 < V_106 ; ++ V_78 , V_105 += V_156 , ++ V_15 ) {
V_74 = & V_15 -> V_331 . V_74 ;
V_15 -> V_73 . V_22 = V_333 ;
V_15 -> V_73 . V_82 = sizeof( V_15 -> V_331 ) ;
V_15 -> V_331 . V_10 . V_182 = V_158 -> V_22 ;
V_15 -> V_331 . V_10 . V_80 = 0 ;
V_15 -> V_331 . V_10 . V_81 = 0 ;
if ( V_105 -> V_112 > V_82 -> V_11 || V_105 -> V_113 > V_82 -> V_11 ||
V_105 -> y1 > V_82 -> V_12 || V_105 -> V_114 > V_82 -> V_12 ) {
F_11 ( L_34 ) ;
return - V_19 ;
}
V_74 -> V_37 = V_105 -> V_112 ;
V_74 -> V_38 = V_105 -> y1 ;
V_74 -> V_86 = 0 ;
V_74 -> V_91 = V_105 -> V_113 - V_105 -> V_112 ;
V_74 -> V_92 = V_105 -> V_114 - V_105 -> y1 ;
V_74 -> V_90 = 1 ;
V_332 += sizeof( * V_15 ) ;
}
F_155 ( V_9 , V_332 ) ;
return 0 ;
}
int F_156 ( struct V_8 * V_9 ,
unsigned V_238 ,
T_1 V_191 ,
T_1 V_193 ,
struct V_236 * * V_334 ,
struct V_46 * * V_335 ,
struct V_257 * * V_336 )
{
struct V_236 * V_237 ;
struct V_1 * V_2 ;
struct V_257 * V_251 ;
int V_78 = 0 ;
F_38 (con, &dev_priv->dev->mode_config.connector_list,
head) {
if ( V_78 == V_238 )
break;
++ V_78 ;
}
if ( V_78 != V_238 ) {
F_11 ( L_35 ) ;
return - V_19 ;
}
if ( F_157 ( & V_237 -> V_276 ) )
( void ) F_125 ( V_237 , V_191 , V_193 ) ;
if ( F_157 ( & V_237 -> V_276 ) ) {
F_11 ( L_36 ) ;
return - V_19 ;
}
V_2 = F_116 ( V_237 ) ;
* V_334 = V_237 ;
* V_335 = & V_2 -> V_6 ;
F_38 (mode, &con->modes, head) {
if ( V_251 -> type & V_337 )
break;
}
if ( V_251 -> type & V_337 )
* V_336 = V_251 ;
else {
F_54 ( true , L_37 ) ;
* V_336 = F_158 ( & V_237 -> V_276 ,
struct V_257 ,
V_274 ) ;
}
return 0 ;
}
void F_159 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
F_37 ( & V_9 -> V_338 ) ;
if ( V_2 -> V_339 ) {
if ( -- ( V_9 -> V_340 ) == 0 )
V_9 -> V_341 = NULL ;
V_2 -> V_339 = false ;
}
F_39 ( & V_9 -> V_338 ) ;
}
void F_160 ( struct V_8 * V_9 ,
struct V_1 * V_2 ,
struct V_117 * V_118 )
{
F_37 ( & V_9 -> V_338 ) ;
F_161 ( ! V_9 -> V_340 && V_9 -> V_341 ) ;
if ( ! V_2 -> V_339 && V_2 -> V_281 ) {
V_9 -> V_341 = V_118 ;
V_2 -> V_339 = true ;
V_9 -> V_340 ++ ;
}
F_39 ( & V_9 -> V_338 ) ;
}
bool F_162 ( struct V_8 * V_9 ,
struct V_46 * V_6 )
{
struct V_1 * V_2 = F_24 ( V_6 ) ;
bool V_31 ;
F_37 ( & V_9 -> V_338 ) ;
V_31 = ! V_2 -> V_281 || V_9 -> V_340 == 1 ;
F_39 ( & V_9 -> V_338 ) ;
return V_31 ;
}
void F_163 ( struct V_8 * V_9 ,
struct V_46 * V_6 )
{
struct V_1 * V_2 = F_24 ( V_6 ) ;
struct V_117 * V_118 ;
F_37 ( & V_9 -> V_338 ) ;
if ( ! V_2 -> V_281 )
goto V_327;
V_118 = F_164 ( V_6 -> V_221 -> V_302 ) ;
F_161 ( V_9 -> V_340 != 1 &&
V_9 -> V_341 != V_118 ) ;
V_9 -> V_341 = V_118 ;
V_327:
F_39 ( & V_9 -> V_338 ) ;
}
void
F_165 ( struct V_8 * V_9 ,
bool V_342 )
{
if ( V_9 -> V_280 )
return;
V_9 -> V_280 =
F_92 ( V_9 -> V_52 ,
V_342 ?
V_186 : 0 ,
L_38 , 0 , 1 ) ;
}
