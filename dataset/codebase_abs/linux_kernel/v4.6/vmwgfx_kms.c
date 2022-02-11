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
V_31 = F_14 ( & V_24 -> V_34 , true , false , false , NULL ) ;
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
V_31 = F_14 ( V_72 , true , false , false , NULL ) ;
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
if ( V_9 -> V_109 == V_110 )
return - V_124 ;
if ( F_10 ( ! V_54 -> V_130 ) )
return - V_19 ;
if ( F_10 ( V_54 -> V_131 [ 0 ] != 1 ||
V_54 -> V_132 != 1 ||
V_54 -> V_133 . V_11 < V_126 -> V_11 ||
V_54 -> V_133 . V_12 < V_126 -> V_12 ||
V_54 -> V_133 . V_134 != 1 ) ) {
F_11 ( L_10
L_11 ) ;
return - V_19 ;
}
switch ( V_126 -> V_134 ) {
case 32 :
V_129 = V_135 ;
break;
case 24 :
V_129 = V_136 ;
break;
case 16 :
V_129 = V_137 ;
break;
case 15 :
V_129 = V_138 ;
break;
default:
F_11 ( L_12 , V_126 -> V_134 ) ;
return - V_19 ;
}
if ( ! V_9 -> V_139 && V_129 != V_54 -> V_129 ) {
F_11 ( L_13 ) ;
return - V_19 ;
}
V_100 = F_56 ( sizeof( * V_100 ) , V_140 ) ;
if ( ! V_100 ) {
V_31 = - V_20 ;
goto V_141;
}
V_100 -> V_34 . V_34 . V_142 = V_126 -> V_143 ;
V_100 -> V_34 . V_34 . V_144 [ 0 ] = V_126 -> V_93 ;
V_100 -> V_34 . V_34 . V_134 = V_126 -> V_134 ;
V_100 -> V_34 . V_34 . V_11 = V_126 -> V_11 ;
V_100 -> V_34 . V_34 . V_12 = V_126 -> V_12 ;
V_100 -> V_54 = F_57 ( V_54 ) ;
V_100 -> V_34 . V_145 = V_126 -> V_49 ;
V_100 -> V_127 = V_127 ;
* V_57 = & V_100 -> V_34 ;
V_31 = F_58 ( V_52 , & V_100 -> V_34 . V_34 ,
& V_146 ) ;
if ( V_31 )
goto V_147;
return 0 ;
V_147:
F_2 ( & V_54 ) ;
F_44 ( V_100 ) ;
V_141:
return V_31 ;
}
static void F_59 ( struct V_97 * V_98 )
{
struct V_148 * V_149 =
F_60 ( V_98 ) ;
F_42 ( V_98 ) ;
F_3 ( & V_149 -> V_150 ) ;
if ( V_149 -> V_34 . V_101 )
F_43 ( & V_149 -> V_34 . V_101 ) ;
F_44 ( V_149 ) ;
}
static int F_61 ( struct V_97 * V_98 ,
struct V_47 * V_48 ,
unsigned V_102 , unsigned V_103 ,
struct V_104 * V_105 ,
unsigned V_106 )
{
struct V_8 * V_9 = F_23 ( V_98 -> V_52 ) ;
struct V_148 * V_149 =
F_60 ( V_98 ) ;
struct V_104 V_107 ;
int V_31 , V_151 = 1 ;
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
V_151 = 2 ;
}
switch ( V_9 -> V_109 ) {
case V_123 :
V_31 = F_53 ( V_9 , NULL , & V_149 -> V_34 , NULL ,
V_105 , NULL , V_106 , V_151 ,
true , true ) ;
break;
case V_116 :
V_31 = F_62 ( V_9 , & V_149 -> V_34 ,
V_105 , NULL , V_106 ,
V_151 , true , NULL ) ;
break;
case V_110 :
V_31 = F_63 ( V_9 , & V_149 -> V_34 , 0 , 0 ,
V_105 , V_106 , V_151 ) ;
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
static int F_64 ( struct V_117 * V_118 )
{
struct V_8 * V_9 = F_23 ( V_118 -> V_34 . V_52 ) ;
struct V_23 * V_152 ;
int V_31 ;
V_152 = V_118 -> V_24 ? F_60 ( & V_118 -> V_34 ) -> V_150 :
F_41 ( & V_118 -> V_34 ) -> V_54 -> V_153 . V_154 ;
if ( ! V_152 )
return 0 ;
switch ( V_9 -> V_109 ) {
case V_110 :
F_65 ( V_9 ) ;
V_31 = F_66 ( V_9 , V_152 , false ) ;
F_67 ( V_9 ) ;
break;
case V_116 :
case V_123 :
if ( V_118 -> V_24 )
return F_68 ( V_9 , V_152 ,
false ) ;
return F_69 ( V_9 , V_152 ,
& V_155 , false ) ;
default:
return - V_19 ;
}
return V_31 ;
}
static int F_70 ( struct V_117 * V_118 )
{
struct V_8 * V_9 = F_23 ( V_118 -> V_34 . V_52 ) ;
struct V_23 * V_152 ;
V_152 = V_118 -> V_24 ? F_60 ( & V_118 -> V_34 ) -> V_150 :
F_41 ( & V_118 -> V_34 ) -> V_54 -> V_153 . V_154 ;
if ( F_71 ( ! V_152 ) )
return 0 ;
return F_72 ( V_9 , V_152 , false ) ;
}
static int F_73 ( struct V_94 * V_52 ,
const struct V_125 * V_126 ,
struct V_23 * V_156 ,
struct V_53 * * V_157 )
{
T_3 V_129 ;
struct V_158 V_159 ;
struct V_160 * V_153 ;
unsigned int V_161 ;
int V_31 ;
switch ( V_126 -> V_134 ) {
case 32 :
case 24 :
V_129 = V_136 ;
V_161 = 4 ;
break;
case 16 :
case 15 :
V_129 = V_137 ;
V_161 = 2 ;
break;
case 8 :
V_129 = V_162 ;
V_161 = 1 ;
break;
default:
F_11 ( L_15 , V_126 -> V_134 ) ;
return - V_19 ;
}
V_159 . V_11 = V_126 -> V_93 / V_161 ;
V_159 . V_12 = V_126 -> V_12 ;
V_159 . V_134 = 1 ;
V_31 = F_74 ( V_52 ,
0 ,
0 ,
V_129 ,
true ,
1 ,
0 ,
0 ,
V_159 ,
V_157 ) ;
if ( V_31 ) {
F_11 ( L_16 ) ;
return V_31 ;
}
V_153 = & ( * V_157 ) -> V_153 ;
F_37 ( & V_153 -> V_9 -> V_163 ) ;
( void ) F_75 ( V_153 , false , true ) ;
F_3 ( & V_153 -> V_154 ) ;
V_153 -> V_154 = F_76 ( V_156 ) ;
V_153 -> V_164 = 0 ;
F_77 ( V_153 , false , NULL , 0 ) ;
F_39 ( & V_153 -> V_9 -> V_163 ) ;
return 0 ;
}
static int F_78 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
struct V_117 * * V_57 ,
const struct V_125
* V_126 )
{
struct V_94 * V_52 = V_9 -> V_52 ;
struct V_148 * V_149 ;
unsigned int V_165 ;
int V_31 ;
V_165 = V_126 -> V_12 * V_126 -> V_93 ;
if ( F_10 ( V_165 > V_24 -> V_34 . V_166 * V_32 ) ) {
F_11 ( L_17
L_11 ) ;
return - V_19 ;
}
if ( V_9 -> V_109 == V_116 ) {
switch ( V_126 -> V_134 ) {
case 32 :
case 24 :
if ( V_126 -> V_143 == 32 )
break;
F_11 ( L_18 ,
V_126 -> V_134 , V_126 -> V_143 ) ;
return - V_19 ;
case 16 :
case 15 :
if ( V_126 -> V_143 == 16 )
break;
F_11 ( L_18 ,
V_126 -> V_134 , V_126 -> V_143 ) ;
return - V_19 ;
default:
F_11 ( L_12 , V_126 -> V_134 ) ;
return - V_19 ;
}
}
V_149 = F_56 ( sizeof( * V_149 ) , V_140 ) ;
if ( ! V_149 ) {
V_31 = - V_20 ;
goto V_141;
}
V_149 -> V_34 . V_34 . V_142 = V_126 -> V_143 ;
V_149 -> V_34 . V_34 . V_144 [ 0 ] = V_126 -> V_93 ;
V_149 -> V_34 . V_34 . V_134 = V_126 -> V_134 ;
V_149 -> V_34 . V_34 . V_11 = V_126 -> V_11 ;
V_149 -> V_34 . V_34 . V_12 = V_126 -> V_12 ;
V_149 -> V_34 . V_24 = true ;
V_149 -> V_150 = F_76 ( V_24 ) ;
V_149 -> V_34 . V_145 = V_126 -> V_49 ;
* V_57 = & V_149 -> V_34 ;
V_31 = F_58 ( V_52 , & V_149 -> V_34 . V_34 ,
& V_167 ) ;
if ( V_31 )
goto V_147;
return 0 ;
V_147:
F_3 ( & V_24 ) ;
F_44 ( V_149 ) ;
V_141:
return V_31 ;
}
struct V_117 *
F_79 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
struct V_53 * V_54 ,
bool V_168 ,
const struct V_125 * V_126 )
{
struct V_117 * V_118 = NULL ;
bool V_127 = false ;
int V_31 ;
if ( V_24 && V_168 &&
V_9 -> V_109 == V_123 ) {
V_31 = F_73 ( V_9 -> V_52 , V_126 ,
V_24 , & V_54 ) ;
if ( V_31 )
return F_80 ( V_31 ) ;
V_127 = true ;
}
if ( V_54 ) {
V_31 = F_55 ( V_9 , V_54 , & V_118 ,
V_126 ,
V_127 ) ;
if ( V_127 )
F_2 ( & V_54 ) ;
} else if ( V_24 ) {
V_31 = F_78 ( V_9 , V_24 , & V_118 ,
V_126 ) ;
} else {
F_81 () ;
}
if ( V_31 )
return F_80 ( V_31 ) ;
V_118 -> V_169 = F_64 ;
V_118 -> V_170 = F_70 ;
return V_118 ;
}
static struct V_97 * F_82 ( struct V_94 * V_52 ,
struct V_47 * V_48 ,
const struct V_171 * V_172 )
{
struct V_8 * V_9 = F_23 ( V_52 ) ;
struct V_58 * V_59 = F_27 ( V_48 ) -> V_59 ;
struct V_117 * V_118 = NULL ;
struct V_53 * V_54 = NULL ;
struct V_23 * V_72 = NULL ;
struct V_173 * V_101 ;
struct V_125 V_126 ;
int V_31 ;
V_126 . V_11 = V_172 -> V_11 ;
V_126 . V_12 = V_172 -> V_12 ;
V_126 . V_93 = V_172 -> V_144 [ 0 ] ;
V_126 . V_49 = V_172 -> V_174 [ 0 ] ;
F_83 ( V_172 -> V_175 , & V_126 . V_134 ,
& V_126 . V_143 ) ;
if ( ! F_84 ( V_9 ,
V_126 . V_93 ,
V_126 . V_12 ) ) {
F_11 ( L_19 ) ;
return F_80 ( - V_20 ) ;
}
V_101 = F_85 ( V_59 , V_126 . V_49 ) ;
if ( F_10 ( V_101 == NULL ) ) {
F_11 ( L_20 ) ;
return F_80 ( - V_176 ) ;
}
V_31 = F_28 ( V_9 , V_59 ,
V_126 . V_49 ,
& V_54 , & V_72 ) ;
if ( V_31 )
goto V_177;
V_118 = F_79 ( V_9 , V_72 , V_54 ,
! ( V_9 -> V_178 & V_179 ) ,
& V_126 ) ;
if ( F_86 ( V_118 ) ) {
V_31 = F_87 ( V_118 ) ;
goto V_177;
}
V_177:
if ( V_72 )
F_3 ( & V_72 ) ;
if ( V_54 )
F_2 ( & V_54 ) ;
if ( V_31 ) {
F_11 ( L_21 , V_31 ) ;
F_43 ( & V_101 ) ;
return F_80 ( V_31 ) ;
} else
V_118 -> V_101 = V_101 ;
return & V_118 -> V_34 ;
}
static int F_88 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_117 * V_118 ,
struct V_53 * V_54 ,
T_3 V_180 ,
T_4 V_181 , T_4 V_182 ,
struct V_121 * V_105 ,
T_3 V_106 )
{
return F_47 ( V_9 , V_118 , NULL , V_105 ,
& V_54 -> V_153 , V_181 , V_182 ,
V_106 , 1 , NULL ) ;
}
int F_89 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_117 * V_118 ,
struct V_53 * V_54 ,
T_3 V_180 ,
T_4 V_181 , T_4 V_182 ,
struct V_121 * V_105 ,
T_3 V_106 )
{
int V_31 ;
switch ( V_9 -> V_109 ) {
case V_123 :
V_31 = F_48 ( V_9 , V_118 , NULL , V_105 ,
& V_54 -> V_153 , V_181 , V_182 ,
V_106 , 1 , NULL ) ;
break;
case V_116 :
V_31 = F_88 ( V_9 , V_48 , V_118 , V_54 ,
V_180 , V_181 , V_182 , V_105 ,
V_106 ) ;
break;
default:
F_54 ( true ,
L_22 ) ;
V_31 = - V_124 ;
break;
}
if ( V_31 )
return V_31 ;
F_49 ( V_9 , false ) ;
return 0 ;
}
static void
F_90 ( struct V_8 * V_9 )
{
if ( V_9 -> V_183 )
return;
V_9 -> V_183 =
F_91 ( V_9 -> V_52 ,
V_184 ,
L_23 , 0 , 1 ) ;
if ( ! V_9 -> V_183 )
return;
}
int F_92 ( struct V_8 * V_9 )
{
struct V_94 * V_52 = V_9 -> V_52 ;
int V_31 ;
F_93 ( V_52 ) ;
V_52 -> V_95 . V_185 = & V_186 ;
V_52 -> V_95 . V_187 = 1 ;
V_52 -> V_95 . V_188 = 1 ;
V_52 -> V_95 . V_189 = V_9 -> V_190 ;
V_52 -> V_95 . V_191 = V_9 -> V_192 ;
F_94 ( V_52 ) ;
F_90 ( V_9 ) ;
V_31 = F_95 ( V_9 ) ;
if ( V_31 ) {
V_31 = F_96 ( V_9 ) ;
if ( V_31 )
V_31 = F_97 ( V_9 ) ;
}
return V_31 ;
}
int F_98 ( struct V_8 * V_9 )
{
int V_31 ;
F_99 ( V_9 -> V_52 ) ;
if ( V_9 -> V_109 == V_116 )
V_31 = F_100 ( V_9 ) ;
else if ( V_9 -> V_109 == V_123 )
V_31 = F_101 ( V_9 ) ;
else
V_31 = F_102 ( V_9 ) ;
return V_31 ;
}
int F_103 ( struct V_94 * V_52 , void * V_193 ,
struct V_47 * V_48 )
{
struct V_194 * V_195 = V_193 ;
struct V_1 * V_2 ;
struct V_46 * V_6 ;
int V_31 = 0 ;
F_37 ( & V_52 -> V_95 . V_96 ) ;
if ( V_195 -> V_102 & V_196 ) {
F_38 (crtc, &dev->mode_config.crtc_list, head) {
V_2 = F_24 ( V_6 ) ;
V_2 -> V_55 = V_195 -> V_197 ;
V_2 -> V_56 = V_195 -> V_198 ;
}
F_39 ( & V_52 -> V_95 . V_96 ) ;
return 0 ;
}
V_6 = F_104 ( V_52 , V_195 -> V_199 ) ;
if ( ! V_6 ) {
V_31 = - V_176 ;
goto V_57;
}
V_2 = F_24 ( V_6 ) ;
V_2 -> V_55 = V_195 -> V_197 ;
V_2 -> V_56 = V_195 -> V_198 ;
V_57:
F_39 ( & V_52 -> V_95 . V_96 ) ;
return V_31 ;
}
int F_105 ( struct V_8 * F_23 ,
unsigned V_11 , unsigned V_12 , unsigned V_93 ,
unsigned V_143 , unsigned V_134 )
{
if ( F_23 -> V_178 & V_200 )
F_106 ( F_23 , V_201 , V_93 ) ;
else if ( F_107 ( F_23 ) )
F_20 ( V_93 , F_23 -> V_40 +
V_202 ) ;
F_106 ( F_23 , V_203 , V_11 ) ;
F_106 ( F_23 , V_204 , V_12 ) ;
F_106 ( F_23 , V_205 , V_143 ) ;
if ( F_108 ( F_23 , V_206 ) != V_134 ) {
F_11 ( L_24 ,
V_134 , V_143 , F_108 ( F_23 , V_206 ) ) ;
return - V_19 ;
}
return 0 ;
}
int F_109 ( struct V_8 * F_23 )
{
struct V_207 * V_208 ;
T_3 V_78 ;
F_23 -> V_209 = F_108 ( F_23 , V_203 ) ;
F_23 -> V_210 = F_108 ( F_23 , V_204 ) ;
F_23 -> V_211 = F_108 ( F_23 , V_205 ) ;
if ( F_23 -> V_178 & V_200 )
F_23 -> V_212 =
F_108 ( F_23 , V_201 ) ;
else if ( F_107 ( F_23 ) )
F_23 -> V_212 = F_21 ( F_23 -> V_40 +
V_202 ) ;
if ( ! ( F_23 -> V_178 & V_213 ) )
return 0 ;
F_23 -> V_214 = F_108 ( F_23 ,
V_215 ) ;
if ( F_23 -> V_214 == 0 )
F_23 -> V_214 = 1 ;
for ( V_78 = 0 ; V_78 < F_23 -> V_214 ; ++ V_78 ) {
V_208 = & F_23 -> V_216 [ V_78 ] ;
F_106 ( F_23 , V_217 , V_78 ) ;
V_208 -> V_218 = F_108 ( F_23 , V_219 ) ;
V_208 -> V_220 = F_108 ( F_23 , V_221 ) ;
V_208 -> V_222 = F_108 ( F_23 , V_223 ) ;
V_208 -> V_11 = F_108 ( F_23 , V_224 ) ;
V_208 -> V_12 = F_108 ( F_23 , V_225 ) ;
F_106 ( F_23 , V_217 , V_226 ) ;
if ( V_78 == 0 && F_23 -> V_214 == 1 &&
V_208 -> V_11 == 0 && V_208 -> V_12 == 0 ) {
V_208 -> V_11 = F_23 -> V_209 - V_208 -> V_220 ;
V_208 -> V_12 = F_23 -> V_210 - V_208 -> V_222 ;
}
}
return 0 ;
}
int F_110 ( struct V_8 * F_23 )
{
struct V_207 * V_208 ;
T_3 V_78 ;
F_106 ( F_23 , V_203 , F_23 -> V_209 ) ;
F_106 ( F_23 , V_204 , F_23 -> V_210 ) ;
F_106 ( F_23 , V_205 , F_23 -> V_211 ) ;
if ( F_23 -> V_178 & V_200 )
F_106 ( F_23 , V_201 ,
F_23 -> V_212 ) ;
else if ( F_107 ( F_23 ) )
F_20 ( F_23 -> V_212 ,
F_23 -> V_40 + V_202 ) ;
if ( ! ( F_23 -> V_178 & V_213 ) )
return 0 ;
for ( V_78 = 0 ; V_78 < F_23 -> V_214 ; ++ V_78 ) {
V_208 = & F_23 -> V_216 [ V_78 ] ;
F_106 ( F_23 , V_217 , V_78 ) ;
F_106 ( F_23 , V_219 , V_208 -> V_218 ) ;
F_106 ( F_23 , V_221 , V_208 -> V_220 ) ;
F_106 ( F_23 , V_223 , V_208 -> V_222 ) ;
F_106 ( F_23 , V_224 , V_208 -> V_11 ) ;
F_106 ( F_23 , V_225 , V_208 -> V_12 ) ;
F_106 ( F_23 , V_217 , V_226 ) ;
}
return 0 ;
}
bool F_84 ( struct V_8 * V_9 ,
T_3 V_93 ,
T_3 V_12 )
{
return ( ( V_227 ) V_93 * ( V_227 ) V_12 ) < ( V_227 )
( ( V_9 -> V_109 == V_123 ) ?
V_9 -> V_228 : V_9 -> V_229 ) ;
}
T_1 F_111 ( struct V_94 * V_52 , unsigned int V_230 )
{
return 0 ;
}
int F_112 ( struct V_94 * V_52 , unsigned int V_230 )
{
return - V_124 ;
}
void F_113 ( struct V_94 * V_52 , unsigned int V_230 )
{
}
static int F_114 ( struct V_8 * V_9 , unsigned V_231 ,
struct V_121 * V_232 )
{
struct V_94 * V_52 = V_9 -> V_52 ;
struct V_1 * V_2 ;
struct V_233 * V_234 ;
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
V_2 = F_115 ( V_234 ) ;
if ( V_231 > V_2 -> V_235 ) {
V_2 -> V_236 = V_232 [ V_2 -> V_235 ] . V_91 ;
V_2 -> V_237 = V_232 [ V_2 -> V_235 ] . V_92 ;
V_2 -> V_238 = true ;
V_2 -> V_239 = V_232 [ V_2 -> V_235 ] . V_37 ;
V_2 -> V_240 = V_232 [ V_2 -> V_235 ] . V_38 ;
F_116
( & V_234 -> V_34 , V_52 -> V_95 . V_241 ,
V_2 -> V_239 ) ;
F_116
( & V_234 -> V_34 , V_52 -> V_95 . V_242 ,
V_2 -> V_240 ) ;
} else {
V_2 -> V_236 = 800 ;
V_2 -> V_237 = 600 ;
V_2 -> V_238 = false ;
F_116
( & V_234 -> V_34 , V_52 -> V_95 . V_241 ,
0 ) ;
F_116
( & V_234 -> V_34 , V_52 -> V_95 . V_242 ,
0 ) ;
}
V_234 -> V_243 = F_117 ( V_234 , true ) ;
}
F_39 ( & V_52 -> V_95 . V_96 ) ;
F_118 ( V_52 ) ;
return 0 ;
}
void F_119 ( struct V_46 * V_6 ,
T_10 * V_244 , T_10 * V_245 , T_10 * V_246 ,
T_3 V_247 , T_3 V_82 )
{
struct V_8 * V_9 = F_23 ( V_6 -> V_52 ) ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_82 ; V_78 ++ ) {
F_120 ( L_25 , V_78 ,
V_244 [ V_78 ] , V_245 [ V_78 ] , V_246 [ V_78 ] ) ;
F_106 ( V_9 , V_248 + V_78 * 3 + 0 , V_244 [ V_78 ] >> 8 ) ;
F_106 ( V_9 , V_248 + V_78 * 3 + 1 , V_245 [ V_78 ] >> 8 ) ;
F_106 ( V_9 , V_248 + V_78 * 3 + 2 , V_246 [ V_78 ] >> 8 ) ;
}
}
int F_121 ( struct V_233 * V_5 , int V_249 )
{
return 0 ;
}
enum V_250
F_117 ( struct V_233 * V_5 , bool V_251 )
{
T_3 V_214 ;
struct V_94 * V_52 = V_5 -> V_52 ;
struct V_8 * V_9 = F_23 ( V_52 ) ;
struct V_1 * V_2 = F_115 ( V_5 ) ;
V_214 = F_108 ( V_9 , V_252 ) ;
return ( ( F_115 ( V_5 ) -> V_235 < V_214 &&
V_2 -> V_238 ) ?
V_253 : V_254 ) ;
}
void F_122 ( struct V_255 * V_249 )
{
V_249 -> V_256 = V_249 -> V_257 + 50 ;
V_249 -> V_258 = V_249 -> V_256 + 50 ;
V_249 -> V_259 = V_249 -> V_258 + 50 ;
V_249 -> V_260 = V_249 -> V_261 + 50 ;
V_249 -> V_262 = V_249 -> V_260 + 50 ;
V_249 -> V_263 = V_249 -> V_262 + 50 ;
V_249 -> clock = ( T_1 ) V_249 -> V_259 * ( T_1 ) V_249 -> V_263 / 100 * 6 ;
V_249 -> V_264 = F_123 ( V_249 ) ;
}
int F_124 ( struct V_233 * V_5 ,
T_3 V_189 , T_3 V_191 )
{
struct V_1 * V_2 = F_115 ( V_5 ) ;
struct V_94 * V_52 = V_5 -> V_52 ;
struct V_8 * V_9 = F_23 ( V_52 ) ;
struct V_255 * V_249 = NULL ;
struct V_255 * V_265 ;
struct V_255 V_266 = { F_125 ( L_26 ,
DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC)
} ;
int V_78 ;
T_1 V_267 = 2 ;
if ( V_9 -> V_109 == V_116 )
V_267 = 4 ;
if ( V_9 -> V_109 == V_123 ) {
V_189 = F_126 ( V_189 , V_9 -> V_268 ) ;
V_191 = F_126 ( V_191 , V_9 -> V_269 ) ;
}
V_249 = F_127 ( V_52 , & V_266 ) ;
if ( ! V_249 )
return 0 ;
V_249 -> V_257 = V_2 -> V_236 ;
V_249 -> V_261 = V_2 -> V_237 ;
F_122 ( V_249 ) ;
if ( F_84 ( V_9 ,
V_249 -> V_257 * V_267 ,
V_249 -> V_261 ) ) {
F_128 ( V_5 , V_249 ) ;
} else {
F_129 ( V_52 , V_249 ) ;
V_249 = NULL ;
}
if ( V_2 -> V_270 ) {
F_130 ( & V_2 -> V_270 -> V_271 ) ;
F_129 ( V_52 , V_2 -> V_270 ) ;
}
V_2 -> V_270 = V_249 ;
for ( V_78 = 0 ; V_272 [ V_78 ] . type != 0 ; V_78 ++ ) {
V_265 = & V_272 [ V_78 ] ;
if ( V_265 -> V_257 > V_189 ||
V_265 -> V_261 > V_191 )
continue;
if ( ! F_84 ( V_9 ,
V_265 -> V_257 * V_267 ,
V_265 -> V_261 ) )
continue;
V_249 = F_127 ( V_52 , V_265 ) ;
if ( ! V_249 )
return 0 ;
V_249 -> V_264 = F_123 ( V_249 ) ;
F_128 ( V_5 , V_249 ) ;
}
F_131 ( V_5 ) ;
F_132 ( & V_5 -> V_273 ) ;
return 1 ;
}
int F_133 ( struct V_233 * V_5 ,
struct V_274 * V_275 ,
T_11 V_276 )
{
struct V_1 * V_2 = F_115 ( V_5 ) ;
struct V_8 * V_9 = F_23 ( V_5 -> V_52 ) ;
if ( V_275 == V_9 -> V_277 )
V_2 -> V_278 = V_276 ;
return 0 ;
}
int F_134 ( struct V_94 * V_52 , void * V_193 ,
struct V_47 * V_48 )
{
struct V_8 * V_9 = F_23 ( V_52 ) ;
struct V_279 * V_195 =
(struct V_279 * ) V_193 ;
void T_9 * V_280 ;
struct V_121 * V_232 ;
unsigned V_281 ;
int V_31 ;
int V_78 ;
V_227 V_282 = 0 ;
struct V_283 * V_95 = & V_52 -> V_95 ;
struct V_121 V_284 = { 0 } ;
if ( ! V_195 -> V_285 ) {
struct V_121 V_286 = { 0 , 0 , 800 , 600 } ;
F_114 ( V_9 , 1 , & V_286 ) ;
return 0 ;
}
V_281 = V_195 -> V_285 * sizeof( struct V_121 ) ;
V_232 = F_135 ( V_195 -> V_285 , sizeof( struct V_121 ) ,
V_140 ) ;
if ( F_10 ( ! V_232 ) )
return - V_20 ;
V_280 = ( void T_9 * ) ( unsigned long ) V_195 -> V_232 ;
V_31 = F_136 ( V_232 , V_280 , V_281 ) ;
if ( F_10 ( V_31 != 0 ) ) {
F_11 ( L_27 ) ;
V_31 = - V_287 ;
goto V_288;
}
for ( V_78 = 0 ; V_78 < V_195 -> V_285 ; ++ V_78 ) {
if ( V_232 [ V_78 ] . V_37 < 0 ||
V_232 [ V_78 ] . V_38 < 0 ||
V_232 [ V_78 ] . V_37 + V_232 [ V_78 ] . V_91 > V_95 -> V_189 ||
V_232 [ V_78 ] . V_38 + V_232 [ V_78 ] . V_92 > V_95 -> V_191 ) {
F_11 ( L_28 ) ;
V_31 = - V_19 ;
goto V_288;
}
if ( V_232 [ V_78 ] . V_37 + V_232 [ V_78 ] . V_91 > V_284 . V_91 )
V_284 . V_91 = V_232 [ V_78 ] . V_37 + V_232 [ V_78 ] . V_91 ;
if ( V_232 [ V_78 ] . V_38 + V_232 [ V_78 ] . V_92 > V_284 . V_92 )
V_284 . V_92 = V_232 [ V_78 ] . V_38 + V_232 [ V_78 ] . V_92 ;
V_282 += ( V_227 ) V_232 [ V_78 ] . V_91 * ( V_227 ) V_232 [ V_78 ] . V_92 ;
}
if ( V_9 -> V_109 == V_123 ) {
V_227 V_289 = V_284 . V_91 * V_284 . V_92 * 4 ;
V_227 V_290 = V_282 * 4 ;
if ( V_289 > V_9 -> V_228 ) {
F_11 ( L_29 ) ;
V_31 = - V_19 ;
goto V_288;
}
if ( V_290 > V_9 -> V_228 ) {
F_11 ( L_30 ) ;
V_31 = - V_19 ;
goto V_288;
}
}
F_114 ( V_9 , V_195 -> V_285 , V_232 ) ;
V_288:
F_44 ( V_232 ) ;
return V_31 ;
}
int F_137 ( struct V_8 * V_9 ,
struct V_117 * V_98 ,
const struct V_104 * V_105 ,
const struct V_121 * V_122 ,
T_5 V_291 , T_5 V_292 ,
int V_106 ,
int V_151 ,
struct V_293 * V_294 )
{
struct V_1 * V_295 [ V_296 ] ;
struct V_46 * V_6 ;
T_1 V_297 = 0 ;
T_1 V_78 , V_298 ;
V_294 -> V_9 = V_9 ;
F_38 (crtc, &dev_priv->dev->mode_config.crtc_list, head) {
if ( V_6 -> V_218 -> V_299 != & V_98 -> V_34 )
continue;
V_295 [ V_297 ++ ] = F_24 ( V_6 ) ;
}
for ( V_298 = 0 ; V_298 < V_297 ; V_298 ++ ) {
struct V_1 * V_235 = V_295 [ V_298 ] ;
T_5 V_300 = V_235 -> V_6 . V_37 ;
T_5 V_301 = V_235 -> V_6 . V_38 ;
T_5 V_302 = V_235 -> V_6 . V_249 . V_257 ;
T_5 V_303 = V_235 -> V_6 . V_249 . V_261 ;
const struct V_104 * V_304 = V_105 ;
const struct V_121 * V_305 = V_122 ;
V_294 -> V_235 = V_235 ;
if ( V_294 -> V_306 > 0 ) {
V_294 -> V_15 = F_9 ( V_9 ,
V_294 -> V_306 ) ;
if ( ! V_294 -> V_15 ) {
F_11 ( L_31
L_32 ) ;
return - V_20 ;
}
memset ( V_294 -> V_15 , 0 , V_294 -> V_306 ) ;
}
V_294 -> V_307 = 0 ;
for ( V_78 = 0 ; V_78 < V_106 ; V_78 ++ , V_304 += V_151 ,
V_305 += V_151 ) {
T_5 V_308 ;
T_5 V_309 ;
if ( V_105 ) {
V_294 -> V_310 = ( T_5 ) V_304 -> V_112 ;
V_294 -> V_311 = ( T_5 ) V_304 -> y1 ;
V_294 -> V_312 = ( T_5 ) V_304 -> V_113 + V_291 -
V_300 ;
V_294 -> V_313 = ( T_5 ) V_304 -> V_114 + V_292 -
V_301 ;
} else {
V_294 -> V_310 = V_305 -> V_37 ;
V_294 -> V_311 = V_305 -> V_38 ;
V_294 -> V_312 = V_294 -> V_310 + V_305 -> V_91 +
V_291 - V_300 ;
V_294 -> V_313 = V_294 -> V_311 + V_305 -> V_92 +
V_292 - V_301 ;
}
V_294 -> V_314 = V_294 -> V_310 + V_291 - V_300 ;
V_294 -> V_315 = V_294 -> V_311 + V_292 - V_301 ;
if ( V_294 -> V_314 >= V_302 ||
V_294 -> V_315 >= V_303 ||
V_294 -> V_312 <= 0 || V_294 -> V_313 <= 0 )
continue;
V_294 -> V_312 = F_138 ( T_5 , V_294 -> V_312 ,
V_302 ) ;
V_294 -> V_313 = F_138 ( T_5 , V_294 -> V_313 ,
V_303 ) ;
V_308 = F_138 ( T_5 , V_294 -> V_314 , 0 ) ;
V_309 = F_138 ( T_5 , V_294 -> V_315 , 0 ) ;
V_294 -> V_314 -= V_308 ;
V_294 -> V_315 -= V_309 ;
V_294 -> V_310 -= V_308 ;
V_294 -> V_311 -= V_309 ;
V_294 -> V_316 ( V_294 ) ;
}
V_294 -> V_317 ( V_294 ) ;
}
return 0 ;
}
int F_139 ( struct V_8 * V_9 ,
struct V_23 * V_152 ,
bool V_318 ,
bool V_319 )
{
struct V_71 * V_72 = & V_152 -> V_34 ;
int V_31 ;
F_14 ( V_72 , false , false , V_318 , NULL ) ;
V_31 = F_140 ( V_9 , V_72 , V_318 ,
V_319 ) ;
if ( V_31 )
F_18 ( V_72 ) ;
return V_31 ;
}
void F_141 ( struct V_23 * V_152 )
{
if ( V_152 )
F_18 ( & V_152 -> V_34 ) ;
}
void F_142 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_23 * V_152 ,
struct V_320 * * V_321 ,
struct V_119 T_9 *
V_120 )
{
struct V_320 * V_322 ;
T_3 V_49 ;
int V_31 ;
V_31 = F_143 ( V_48 , V_9 , & V_322 ,
V_48 ? & V_49 : NULL ) ;
if ( V_152 )
F_144 ( & V_152 -> V_34 , V_322 ) ;
if ( V_48 )
F_145 ( V_9 , F_27 ( V_48 ) ,
V_31 , V_120 , V_322 ,
V_49 ) ;
if ( V_321 )
* V_321 = V_322 ;
else
F_146 ( & V_322 ) ;
F_141 ( V_152 ) ;
}
void F_147 ( struct V_160 * V_153 )
{
F_141 ( V_153 -> V_154 ) ;
F_77 ( V_153 , false , NULL , 0 ) ;
F_39 ( & V_153 -> V_9 -> V_163 ) ;
}
int F_148 ( struct V_160 * V_153 ,
bool V_318 )
{
int V_31 = 0 ;
if ( V_318 )
V_31 = F_149 ( & V_153 -> V_9 -> V_163 ) ;
else
F_37 ( & V_153 -> V_9 -> V_163 ) ;
if ( F_10 ( V_31 != 0 ) )
return - V_323 ;
V_31 = F_75 ( V_153 , V_318 , false ) ;
if ( V_31 )
goto V_324;
if ( V_153 -> V_154 ) {
V_31 = F_139 ( V_153 -> V_9 , V_153 -> V_154 ,
V_318 ,
V_153 -> V_9 -> V_325 ) ;
if ( V_31 )
goto V_326;
}
V_31 = F_150 ( V_153 ) ;
if ( V_31 )
goto V_327;
return 0 ;
V_327:
F_141 ( V_153 -> V_154 ) ;
V_326:
F_77 ( V_153 , false , NULL , 0 ) ;
V_324:
F_39 ( & V_153 -> V_9 -> V_163 ) ;
return V_31 ;
}
void F_151 ( struct V_160 * V_153 ,
struct V_320 * * V_321 )
{
if ( V_153 -> V_154 || V_321 )
F_142 ( V_153 -> V_9 , NULL , V_153 -> V_154 ,
V_321 , NULL ) ;
F_77 ( V_153 , false , NULL , 0 ) ;
F_39 ( & V_153 -> V_9 -> V_163 ) ;
}
int F_152 ( struct V_160 * V_153 ,
const struct V_104 * V_105 ,
unsigned V_106 ,
int V_151 )
{
struct V_8 * V_9 = V_153 -> V_9 ;
struct V_158 * V_82 = & F_153 ( V_153 ) -> V_133 ;
struct {
T_6 V_73 ;
T_12 V_328 ;
} * V_15 ;
T_13 * V_74 ;
T_14 V_329 = 0 ;
int V_78 ;
if ( ! V_105 )
return 0 ;
V_15 = F_9 ( V_9 , sizeof( * V_15 ) * V_106 ) ;
if ( ! V_15 ) {
F_11 ( L_33
L_34 ) ;
return - V_20 ;
}
for ( V_78 = 0 ; V_78 < V_106 ; ++ V_78 , V_105 += V_151 , ++ V_15 ) {
V_74 = & V_15 -> V_328 . V_74 ;
V_15 -> V_73 . V_22 = V_330 ;
V_15 -> V_73 . V_82 = sizeof( V_15 -> V_328 ) ;
V_15 -> V_328 . V_10 . V_180 = V_153 -> V_22 ;
V_15 -> V_328 . V_10 . V_80 = 0 ;
V_15 -> V_328 . V_10 . V_81 = 0 ;
if ( V_105 -> V_112 > V_82 -> V_11 || V_105 -> V_113 > V_82 -> V_11 ||
V_105 -> y1 > V_82 -> V_12 || V_105 -> V_114 > V_82 -> V_12 ) {
F_11 ( L_35 ) ;
return - V_19 ;
}
V_74 -> V_37 = V_105 -> V_112 ;
V_74 -> V_38 = V_105 -> y1 ;
V_74 -> V_86 = 0 ;
V_74 -> V_91 = V_105 -> V_113 - V_105 -> V_112 ;
V_74 -> V_92 = V_105 -> V_114 - V_105 -> y1 ;
V_74 -> V_90 = 1 ;
V_329 += sizeof( * V_15 ) ;
}
F_154 ( V_9 , V_329 ) ;
return 0 ;
}
int F_155 ( struct V_8 * V_9 ,
unsigned V_235 ,
T_1 V_189 ,
T_1 V_191 ,
struct V_233 * * V_331 ,
struct V_46 * * V_332 ,
struct V_255 * * V_333 )
{
struct V_233 * V_234 ;
struct V_1 * V_2 ;
struct V_255 * V_249 ;
int V_78 = 0 ;
F_38 (con, &dev_priv->dev->mode_config.connector_list,
head) {
if ( V_78 == V_235 )
break;
++ V_78 ;
}
if ( V_78 != V_235 ) {
F_11 ( L_36 ) ;
return - V_19 ;
}
if ( F_156 ( & V_234 -> V_273 ) )
( void ) F_124 ( V_234 , V_189 , V_191 ) ;
if ( F_156 ( & V_234 -> V_273 ) ) {
F_11 ( L_37 ) ;
return - V_19 ;
}
V_2 = F_115 ( V_234 ) ;
* V_331 = V_234 ;
* V_332 = & V_2 -> V_6 ;
F_38 (mode, &con->modes, head) {
if ( V_249 -> type & V_334 )
break;
}
if ( V_249 -> type & V_334 )
* V_333 = V_249 ;
else {
F_54 ( true , L_38 ) ;
* V_333 = F_157 ( & V_234 -> V_273 ,
struct V_255 ,
V_271 ) ;
}
return 0 ;
}
void F_158 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
F_159 ( & V_9 -> V_52 -> V_95 . V_96 ) ;
if ( V_2 -> V_335 ) {
if ( -- ( V_9 -> V_336 ) == 0 )
V_9 -> V_337 = NULL ;
V_2 -> V_335 = false ;
}
}
void F_160 ( struct V_8 * V_9 ,
struct V_1 * V_2 ,
struct V_117 * V_118 )
{
F_159 ( & V_9 -> V_52 -> V_95 . V_96 ) ;
F_161 ( ! V_9 -> V_336 && V_9 -> V_337 ) ;
if ( ! V_2 -> V_335 && V_2 -> V_278 ) {
V_9 -> V_337 = V_118 ;
V_2 -> V_335 = true ;
V_9 -> V_336 ++ ;
}
}
bool F_162 ( struct V_8 * V_9 ,
struct V_46 * V_6 )
{
struct V_1 * V_2 = F_24 ( V_6 ) ;
F_159 ( & V_9 -> V_52 -> V_95 . V_96 ) ;
if ( ! V_2 -> V_278 )
return true ;
if ( V_9 -> V_336 != 1 )
return false ;
return true ;
}
void F_163 ( struct V_8 * V_9 ,
struct V_46 * V_6 )
{
struct V_1 * V_2 = F_24 ( V_6 ) ;
struct V_117 * V_118 ;
F_159 ( & V_9 -> V_52 -> V_95 . V_96 ) ;
if ( ! V_2 -> V_278 )
return;
V_118 = F_164 ( V_6 -> V_218 -> V_299 ) ;
F_161 ( V_9 -> V_336 != 1 &&
V_9 -> V_337 != V_118 ) ;
V_9 -> V_337 = V_118 ;
}
void
F_165 ( struct V_8 * V_9 ,
bool V_338 )
{
if ( V_9 -> V_277 )
return;
V_9 -> V_277 =
F_91 ( V_9 -> V_52 ,
V_338 ?
V_184 : 0 ,
L_39 , 0 , 1 ) ;
}
