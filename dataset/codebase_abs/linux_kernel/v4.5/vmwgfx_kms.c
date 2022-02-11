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
V_2 -> V_63 = V_37 + V_6 -> V_37 ;
V_2 -> V_64 = V_38 + V_6 -> V_38 ;
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
void F_32 ( struct V_53 * V_68 ,
struct V_58 * V_59 ,
struct V_69 * V_70 ,
T_6 * V_71 )
{
struct V_25 V_26 ;
unsigned long V_27 ;
unsigned long V_28 ;
T_7 * V_72 ;
unsigned V_73 ;
void * V_29 ;
bool V_30 ;
struct V_74 {
T_6 V_71 ;
T_8 V_75 ;
} * V_15 ;
int V_76 , V_31 ;
V_15 = F_33 ( V_71 , struct V_74 , V_71 ) ;
if ( ! V_68 -> V_60 . V_10 )
return;
if ( V_15 -> V_75 . V_77 . V_78 != 0 || V_15 -> V_75 . V_77 . V_79 != 0 ) {
F_11 ( L_5 ) ;
return;
}
if ( V_15 -> V_71 . V_80 < 64 ) {
F_11 ( L_6 ) ;
return;
}
V_72 = ( T_7 * ) & V_15 [ 1 ] ;
V_73 = ( V_15 -> V_71 . V_80 - sizeof( T_8 ) ) /
sizeof( T_7 ) ;
if ( V_15 -> V_75 . V_81 . V_82 . V_83 % V_32 ||
V_72 -> V_37 != 0 || V_72 -> V_38 != 0 || V_72 -> V_84 != 0 ||
V_72 -> V_85 != 0 || V_72 -> V_86 != 0 || V_72 -> V_87 != 0 ||
V_72 -> V_88 != 1 || V_73 != 1 ) {
F_11 ( L_7 ) ;
F_11 ( L_8 ,
V_72 -> V_85 , V_72 -> V_86 , V_72 -> V_87 ,
V_72 -> V_37 , V_72 -> V_38 , V_72 -> V_84 ,
V_72 -> V_89 , V_72 -> V_90 , V_72 -> V_88 , V_73 ,
V_15 -> V_75 . V_81 . V_82 . V_83 ) ;
return;
}
V_27 = V_15 -> V_75 . V_81 . V_82 . V_83 >> V_33 ;
V_28 = ( 64 * 64 * 4 ) >> V_33 ;
V_31 = F_14 ( V_70 , true , false , false , NULL ) ;
if ( F_10 ( V_31 != 0 ) ) {
F_11 ( L_2 ) ;
return;
}
V_31 = F_15 ( V_70 , V_27 , V_28 , & V_26 ) ;
if ( F_10 ( V_31 != 0 ) )
goto V_35;
V_29 = F_16 ( & V_26 , & V_30 ) ;
if ( V_72 -> V_89 == 64 && V_15 -> V_75 . V_81 . V_91 == 64 * 4 ) {
memcpy ( V_68 -> V_60 . V_10 , V_29 , 64 * 64 * 4 ) ;
} else {
for ( V_76 = 0 ; V_76 < V_72 -> V_90 ; V_76 ++ )
memcpy ( V_68 -> V_60 . V_10 + V_76 * 64 ,
V_29 + V_76 * V_15 -> V_75 . V_81 . V_91 ,
V_72 -> V_89 * 4 ) ;
}
V_68 -> V_60 . V_62 ++ ;
F_17 ( & V_26 ) ;
V_35:
F_18 ( V_70 ) ;
}
void F_34 ( struct V_8 * V_9 )
{
struct V_92 * V_52 = V_9 -> V_52 ;
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
struct V_92 * V_52 = V_9 -> V_52 ;
struct V_1 * V_2 ;
struct V_46 * V_6 ;
F_37 ( & V_52 -> V_93 . V_94 ) ;
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
F_39 ( & V_52 -> V_93 . V_94 ) ;
}
static void F_40 ( struct V_95 * V_96 )
{
struct V_97 * V_98 =
F_41 ( V_96 ) ;
F_42 ( V_96 ) ;
F_2 ( & V_98 -> V_54 ) ;
if ( V_98 -> V_34 . V_99 )
F_43 ( & V_98 -> V_34 . V_99 ) ;
F_44 ( V_98 ) ;
}
static int F_45 ( struct V_95 * V_96 ,
struct V_47 * V_48 ,
unsigned V_100 , unsigned V_101 ,
struct V_102 * V_103 ,
unsigned V_104 )
{
struct V_8 * V_9 = F_23 ( V_96 -> V_52 ) ;
struct V_97 * V_98 =
F_41 ( V_96 ) ;
struct V_102 V_105 ;
int V_31 , V_106 = 1 ;
if ( V_9 -> V_107 == V_108 )
return - V_19 ;
F_26 ( V_9 -> V_52 ) ;
V_31 = F_46 ( & V_9 -> V_109 , true ) ;
if ( F_10 ( V_31 != 0 ) ) {
F_29 ( V_9 -> V_52 ) ;
return V_31 ;
}
if ( ! V_104 ) {
V_104 = 1 ;
V_103 = & V_105 ;
V_105 . V_110 = V_105 . y1 = 0 ;
V_105 . V_111 = V_96 -> V_11 ;
V_105 . V_112 = V_96 -> V_12 ;
} else if ( V_100 & V_113 ) {
V_104 /= 2 ;
V_106 = 2 ;
}
if ( V_9 -> V_107 == V_114 )
V_31 = F_47 ( V_9 , & V_98 -> V_34 ,
V_103 , NULL , NULL , 0 , 0 ,
V_104 , V_106 , NULL ) ;
else
V_31 = F_48 ( V_9 , & V_98 -> V_34 ,
V_103 , NULL , NULL , 0 , 0 ,
V_104 , V_106 , NULL ) ;
F_49 ( V_9 , false ) ;
F_50 ( & V_9 -> V_109 ) ;
F_29 ( V_9 -> V_52 ) ;
return 0 ;
}
int F_51 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_115 * V_116 ,
struct V_117 T_9 * V_118 ,
struct V_119 * V_120 ,
T_3 V_104 )
{
switch ( V_9 -> V_107 ) {
case V_114 :
return F_52 ( V_9 , V_48 , V_116 ,
V_118 , V_120 , V_104 ) ;
case V_121 :
return F_53 ( V_9 , V_48 , V_116 ,
V_118 , NULL , V_120 , V_104 ,
1 , false , true ) ;
default:
F_54 ( true ,
L_9 ) ;
}
return - V_122 ;
}
static int F_55 ( struct V_8 * V_9 ,
struct V_53 * V_54 ,
struct V_115 * * V_57 ,
const struct V_123
* V_124 ,
bool V_125 )
{
struct V_92 * V_52 = V_9 -> V_52 ;
struct V_97 * V_98 ;
enum V_126 V_127 ;
int V_31 ;
if ( V_9 -> V_107 == V_108 )
return - V_122 ;
if ( F_10 ( ! V_54 -> V_128 ) )
return - V_19 ;
if ( F_10 ( V_54 -> V_129 [ 0 ] != 1 ||
V_54 -> V_130 != 1 ||
V_54 -> V_131 . V_11 < V_124 -> V_11 ||
V_54 -> V_131 . V_12 < V_124 -> V_12 ||
V_54 -> V_131 . V_132 != 1 ) ) {
F_11 ( L_10
L_11 ) ;
return - V_19 ;
}
switch ( V_124 -> V_132 ) {
case 32 :
V_127 = V_133 ;
break;
case 24 :
V_127 = V_134 ;
break;
case 16 :
V_127 = V_135 ;
break;
case 15 :
V_127 = V_136 ;
break;
default:
F_11 ( L_12 , V_124 -> V_132 ) ;
return - V_19 ;
}
if ( ! V_9 -> V_137 && V_127 != V_54 -> V_127 ) {
F_11 ( L_13 ) ;
return - V_19 ;
}
V_98 = F_56 ( sizeof( * V_98 ) , V_138 ) ;
if ( ! V_98 ) {
V_31 = - V_20 ;
goto V_139;
}
V_98 -> V_34 . V_34 . V_140 = V_124 -> V_141 ;
V_98 -> V_34 . V_34 . V_142 [ 0 ] = V_124 -> V_91 ;
V_98 -> V_34 . V_34 . V_132 = V_124 -> V_132 ;
V_98 -> V_34 . V_34 . V_11 = V_124 -> V_11 ;
V_98 -> V_34 . V_34 . V_12 = V_124 -> V_12 ;
V_98 -> V_54 = F_57 ( V_54 ) ;
V_98 -> V_34 . V_143 = V_124 -> V_49 ;
V_98 -> V_125 = V_125 ;
* V_57 = & V_98 -> V_34 ;
V_31 = F_58 ( V_52 , & V_98 -> V_34 . V_34 ,
& V_144 ) ;
if ( V_31 )
goto V_145;
return 0 ;
V_145:
F_2 ( & V_54 ) ;
F_44 ( V_98 ) ;
V_139:
return V_31 ;
}
static void F_59 ( struct V_95 * V_96 )
{
struct V_146 * V_147 =
F_60 ( V_96 ) ;
F_42 ( V_96 ) ;
F_3 ( & V_147 -> V_148 ) ;
if ( V_147 -> V_34 . V_99 )
F_43 ( & V_147 -> V_34 . V_99 ) ;
F_44 ( V_147 ) ;
}
static int F_61 ( struct V_95 * V_96 ,
struct V_47 * V_48 ,
unsigned V_100 , unsigned V_101 ,
struct V_102 * V_103 ,
unsigned V_104 )
{
struct V_8 * V_9 = F_23 ( V_96 -> V_52 ) ;
struct V_146 * V_147 =
F_60 ( V_96 ) ;
struct V_102 V_105 ;
int V_31 , V_149 = 1 ;
F_26 ( V_9 -> V_52 ) ;
V_31 = F_46 ( & V_9 -> V_109 , true ) ;
if ( F_10 ( V_31 != 0 ) ) {
F_29 ( V_9 -> V_52 ) ;
return V_31 ;
}
if ( ! V_104 ) {
V_104 = 1 ;
V_103 = & V_105 ;
V_105 . V_110 = V_105 . y1 = 0 ;
V_105 . V_111 = V_96 -> V_11 ;
V_105 . V_112 = V_96 -> V_12 ;
} else if ( V_100 & V_113 ) {
V_104 /= 2 ;
V_149 = 2 ;
}
switch ( V_9 -> V_107 ) {
case V_121 :
V_31 = F_53 ( V_9 , NULL , & V_147 -> V_34 , NULL ,
V_103 , NULL , V_104 , V_149 ,
true , true ) ;
break;
case V_114 :
V_31 = F_62 ( V_9 , & V_147 -> V_34 ,
V_103 , V_104 , V_149 ,
true ,
NULL ) ;
break;
case V_108 :
V_31 = F_63 ( V_9 , & V_147 -> V_34 , 0 , 0 ,
V_103 , V_104 , V_149 ) ;
break;
default:
V_31 = - V_19 ;
F_54 ( true , L_14 ) ;
break;
}
F_49 ( V_9 , false ) ;
F_50 ( & V_9 -> V_109 ) ;
F_29 ( V_9 -> V_52 ) ;
return V_31 ;
}
static int F_64 ( struct V_115 * V_116 )
{
struct V_8 * V_9 = F_23 ( V_116 -> V_34 . V_52 ) ;
struct V_23 * V_150 ;
int V_31 ;
V_150 = V_116 -> V_24 ? F_60 ( & V_116 -> V_34 ) -> V_148 :
F_41 ( & V_116 -> V_34 ) -> V_54 -> V_151 . V_152 ;
if ( ! V_150 )
return 0 ;
switch ( V_9 -> V_107 ) {
case V_108 :
F_65 ( V_9 ) ;
V_31 = F_66 ( V_9 , V_150 , false ) ;
F_67 ( V_9 ) ;
break;
case V_114 :
case V_121 :
if ( V_116 -> V_24 )
return F_68 ( V_9 , V_150 ,
false ) ;
return F_69 ( V_9 , V_150 ,
& V_153 , false ) ;
default:
return - V_19 ;
}
return V_31 ;
}
static int F_70 ( struct V_115 * V_116 )
{
struct V_8 * V_9 = F_23 ( V_116 -> V_34 . V_52 ) ;
struct V_23 * V_150 ;
V_150 = V_116 -> V_24 ? F_60 ( & V_116 -> V_34 ) -> V_148 :
F_41 ( & V_116 -> V_34 ) -> V_54 -> V_151 . V_152 ;
if ( F_71 ( ! V_150 ) )
return 0 ;
return F_72 ( V_9 , V_150 , false ) ;
}
static int F_73 ( struct V_92 * V_52 ,
const struct V_123 * V_124 ,
struct V_23 * V_154 ,
struct V_53 * * V_155 )
{
T_3 V_127 ;
struct V_156 V_157 ;
struct V_158 * V_151 ;
unsigned int V_159 ;
int V_31 ;
switch ( V_124 -> V_132 ) {
case 32 :
case 24 :
V_127 = V_134 ;
V_159 = 4 ;
break;
case 16 :
case 15 :
V_127 = V_135 ;
V_159 = 2 ;
break;
case 8 :
V_127 = V_160 ;
V_159 = 1 ;
break;
default:
F_11 ( L_15 , V_124 -> V_132 ) ;
return - V_19 ;
}
V_157 . V_11 = V_124 -> V_91 / V_159 ;
V_157 . V_12 = V_124 -> V_12 ;
V_157 . V_132 = 1 ;
V_31 = F_74 ( V_52 ,
0 ,
0 ,
V_127 ,
true ,
1 ,
0 ,
0 ,
V_157 ,
V_155 ) ;
if ( V_31 ) {
F_11 ( L_16 ) ;
return V_31 ;
}
V_151 = & ( * V_155 ) -> V_151 ;
F_37 ( & V_151 -> V_9 -> V_161 ) ;
( void ) F_75 ( V_151 , false , true ) ;
F_3 ( & V_151 -> V_152 ) ;
V_151 -> V_152 = F_76 ( V_154 ) ;
V_151 -> V_162 = 0 ;
F_77 ( V_151 , false , NULL , 0 ) ;
F_39 ( & V_151 -> V_9 -> V_161 ) ;
return 0 ;
}
static int F_78 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
struct V_115 * * V_57 ,
const struct V_123
* V_124 )
{
struct V_92 * V_52 = V_9 -> V_52 ;
struct V_146 * V_147 ;
unsigned int V_163 ;
int V_31 ;
V_163 = V_124 -> V_12 * V_124 -> V_91 ;
if ( F_10 ( V_163 > V_24 -> V_34 . V_164 * V_32 ) ) {
F_11 ( L_17
L_11 ) ;
return - V_19 ;
}
if ( V_9 -> V_107 == V_114 ) {
switch ( V_124 -> V_132 ) {
case 32 :
case 24 :
if ( V_124 -> V_141 == 32 )
break;
F_11 ( L_18 ,
V_124 -> V_132 , V_124 -> V_141 ) ;
return - V_19 ;
case 16 :
case 15 :
if ( V_124 -> V_141 == 16 )
break;
F_11 ( L_18 ,
V_124 -> V_132 , V_124 -> V_141 ) ;
return - V_19 ;
default:
F_11 ( L_12 , V_124 -> V_132 ) ;
return - V_19 ;
}
}
V_147 = F_56 ( sizeof( * V_147 ) , V_138 ) ;
if ( ! V_147 ) {
V_31 = - V_20 ;
goto V_139;
}
V_147 -> V_34 . V_34 . V_140 = V_124 -> V_141 ;
V_147 -> V_34 . V_34 . V_142 [ 0 ] = V_124 -> V_91 ;
V_147 -> V_34 . V_34 . V_132 = V_124 -> V_132 ;
V_147 -> V_34 . V_34 . V_11 = V_124 -> V_11 ;
V_147 -> V_34 . V_34 . V_12 = V_124 -> V_12 ;
V_147 -> V_34 . V_24 = true ;
V_147 -> V_148 = F_76 ( V_24 ) ;
V_147 -> V_34 . V_143 = V_124 -> V_49 ;
* V_57 = & V_147 -> V_34 ;
V_31 = F_58 ( V_52 , & V_147 -> V_34 . V_34 ,
& V_165 ) ;
if ( V_31 )
goto V_145;
return 0 ;
V_145:
F_3 ( & V_24 ) ;
F_44 ( V_147 ) ;
V_139:
return V_31 ;
}
struct V_115 *
F_79 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
struct V_53 * V_54 ,
bool V_166 ,
const struct V_123 * V_124 )
{
struct V_115 * V_116 = NULL ;
bool V_125 = false ;
int V_31 ;
if ( V_24 && V_166 &&
V_9 -> V_107 == V_121 ) {
V_31 = F_73 ( V_9 -> V_52 , V_124 ,
V_24 , & V_54 ) ;
if ( V_31 )
return F_80 ( V_31 ) ;
V_125 = true ;
}
if ( V_54 ) {
V_31 = F_55 ( V_9 , V_54 , & V_116 ,
V_124 ,
V_125 ) ;
if ( V_125 )
F_2 ( & V_54 ) ;
} else if ( V_24 ) {
V_31 = F_78 ( V_9 , V_24 , & V_116 ,
V_124 ) ;
} else {
F_81 () ;
}
if ( V_31 )
return F_80 ( V_31 ) ;
V_116 -> V_167 = F_64 ;
V_116 -> V_168 = F_70 ;
return V_116 ;
}
static struct V_95 * F_82 ( struct V_92 * V_52 ,
struct V_47 * V_48 ,
const struct V_169 * V_170 )
{
struct V_8 * V_9 = F_23 ( V_52 ) ;
struct V_58 * V_59 = F_27 ( V_48 ) -> V_59 ;
struct V_115 * V_116 = NULL ;
struct V_53 * V_54 = NULL ;
struct V_23 * V_70 = NULL ;
struct V_171 * V_99 ;
struct V_123 V_124 ;
int V_31 ;
V_124 . V_11 = V_170 -> V_11 ;
V_124 . V_12 = V_170 -> V_12 ;
V_124 . V_91 = V_170 -> V_142 [ 0 ] ;
V_124 . V_49 = V_170 -> V_172 [ 0 ] ;
F_83 ( V_170 -> V_173 , & V_124 . V_132 ,
& V_124 . V_141 ) ;
if ( ! F_84 ( V_9 ,
V_124 . V_91 ,
V_124 . V_12 ) ) {
F_11 ( L_19 ) ;
return F_80 ( - V_20 ) ;
}
V_99 = F_85 ( V_59 , V_124 . V_49 ) ;
if ( F_10 ( V_99 == NULL ) ) {
F_11 ( L_20 ) ;
return F_80 ( - V_174 ) ;
}
V_31 = F_28 ( V_9 , V_59 ,
V_124 . V_49 ,
& V_54 , & V_70 ) ;
if ( V_31 )
goto V_175;
V_116 = F_79 ( V_9 , V_70 , V_54 ,
! ( V_9 -> V_176 & V_177 ) ,
& V_124 ) ;
if ( F_86 ( V_116 ) ) {
V_31 = F_87 ( V_116 ) ;
goto V_175;
}
V_175:
if ( V_70 )
F_3 ( & V_70 ) ;
if ( V_54 )
F_2 ( & V_54 ) ;
if ( V_31 ) {
F_11 ( L_21 , V_31 ) ;
F_43 ( & V_99 ) ;
return F_80 ( V_31 ) ;
} else
V_116 -> V_99 = V_99 ;
return & V_116 -> V_34 ;
}
static int F_88 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_115 * V_116 ,
struct V_53 * V_54 ,
T_3 V_178 ,
T_4 V_179 , T_4 V_180 ,
struct V_119 * V_103 ,
T_3 V_104 )
{
return F_47 ( V_9 , V_116 , NULL , V_103 ,
& V_54 -> V_151 , V_179 , V_180 ,
V_104 , 1 , NULL ) ;
}
int F_89 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_115 * V_116 ,
struct V_53 * V_54 ,
T_3 V_178 ,
T_4 V_179 , T_4 V_180 ,
struct V_119 * V_103 ,
T_3 V_104 )
{
int V_31 ;
switch ( V_9 -> V_107 ) {
case V_121 :
V_31 = F_48 ( V_9 , V_116 , NULL , V_103 ,
& V_54 -> V_151 , V_179 , V_180 ,
V_104 , 1 , NULL ) ;
break;
case V_114 :
V_31 = F_88 ( V_9 , V_48 , V_116 , V_54 ,
V_178 , V_179 , V_180 , V_103 ,
V_104 ) ;
break;
default:
F_54 ( true ,
L_22 ) ;
V_31 = - V_122 ;
break;
}
if ( V_31 )
return V_31 ;
F_49 ( V_9 , false ) ;
return 0 ;
}
int F_90 ( struct V_8 * V_9 )
{
struct V_92 * V_52 = V_9 -> V_52 ;
int V_31 ;
F_91 ( V_52 ) ;
V_52 -> V_93 . V_181 = & V_182 ;
V_52 -> V_93 . V_183 = 1 ;
V_52 -> V_93 . V_184 = 1 ;
V_52 -> V_93 . V_185 = V_9 -> V_186 ;
V_52 -> V_93 . V_187 = V_9 -> V_188 ;
V_31 = F_92 ( V_9 ) ;
if ( V_31 ) {
V_31 = F_93 ( V_9 ) ;
if ( V_31 )
V_31 = F_94 ( V_9 ) ;
}
return V_31 ;
}
int F_95 ( struct V_8 * V_9 )
{
int V_31 ;
F_96 ( V_9 -> V_52 ) ;
if ( V_9 -> V_107 == V_114 )
V_31 = F_97 ( V_9 ) ;
else if ( V_9 -> V_107 == V_121 )
V_31 = F_98 ( V_9 ) ;
else
V_31 = F_99 ( V_9 ) ;
return V_31 ;
}
int F_100 ( struct V_92 * V_52 , void * V_189 ,
struct V_47 * V_48 )
{
struct V_190 * V_191 = V_189 ;
struct V_1 * V_2 ;
struct V_46 * V_6 ;
int V_31 = 0 ;
F_37 ( & V_52 -> V_93 . V_94 ) ;
if ( V_191 -> V_100 & V_192 ) {
F_38 (crtc, &dev->mode_config.crtc_list, head) {
V_2 = F_24 ( V_6 ) ;
V_2 -> V_55 = V_191 -> V_193 ;
V_2 -> V_56 = V_191 -> V_194 ;
}
F_39 ( & V_52 -> V_93 . V_94 ) ;
return 0 ;
}
V_6 = F_101 ( V_52 , V_191 -> V_195 ) ;
if ( ! V_6 ) {
V_31 = - V_174 ;
goto V_57;
}
V_2 = F_24 ( V_6 ) ;
V_2 -> V_55 = V_191 -> V_193 ;
V_2 -> V_56 = V_191 -> V_194 ;
V_57:
F_39 ( & V_52 -> V_93 . V_94 ) ;
return V_31 ;
}
int F_102 ( struct V_8 * F_23 ,
unsigned V_11 , unsigned V_12 , unsigned V_91 ,
unsigned V_141 , unsigned V_132 )
{
if ( F_23 -> V_176 & V_196 )
F_103 ( F_23 , V_197 , V_91 ) ;
else if ( F_104 ( F_23 ) )
F_20 ( V_91 , F_23 -> V_40 +
V_198 ) ;
F_103 ( F_23 , V_199 , V_11 ) ;
F_103 ( F_23 , V_200 , V_12 ) ;
F_103 ( F_23 , V_201 , V_141 ) ;
if ( F_105 ( F_23 , V_202 ) != V_132 ) {
F_11 ( L_23 ,
V_132 , V_141 , F_105 ( F_23 , V_202 ) ) ;
return - V_19 ;
}
return 0 ;
}
int F_106 ( struct V_8 * F_23 )
{
struct V_203 * V_204 ;
T_3 V_76 ;
F_23 -> V_205 = F_105 ( F_23 , V_199 ) ;
F_23 -> V_206 = F_105 ( F_23 , V_200 ) ;
F_23 -> V_207 = F_105 ( F_23 , V_201 ) ;
if ( F_23 -> V_176 & V_196 )
F_23 -> V_208 =
F_105 ( F_23 , V_197 ) ;
else if ( F_104 ( F_23 ) )
F_23 -> V_208 = F_21 ( F_23 -> V_40 +
V_198 ) ;
if ( ! ( F_23 -> V_176 & V_209 ) )
return 0 ;
F_23 -> V_210 = F_105 ( F_23 ,
V_211 ) ;
if ( F_23 -> V_210 == 0 )
F_23 -> V_210 = 1 ;
for ( V_76 = 0 ; V_76 < F_23 -> V_210 ; ++ V_76 ) {
V_204 = & F_23 -> V_212 [ V_76 ] ;
F_103 ( F_23 , V_213 , V_76 ) ;
V_204 -> V_214 = F_105 ( F_23 , V_215 ) ;
V_204 -> V_216 = F_105 ( F_23 , V_217 ) ;
V_204 -> V_218 = F_105 ( F_23 , V_219 ) ;
V_204 -> V_11 = F_105 ( F_23 , V_220 ) ;
V_204 -> V_12 = F_105 ( F_23 , V_221 ) ;
F_103 ( F_23 , V_213 , V_222 ) ;
if ( V_76 == 0 && F_23 -> V_210 == 1 &&
V_204 -> V_11 == 0 && V_204 -> V_12 == 0 ) {
V_204 -> V_11 = F_23 -> V_205 - V_204 -> V_216 ;
V_204 -> V_12 = F_23 -> V_206 - V_204 -> V_218 ;
}
}
return 0 ;
}
int F_107 ( struct V_8 * F_23 )
{
struct V_203 * V_204 ;
T_3 V_76 ;
F_103 ( F_23 , V_199 , F_23 -> V_205 ) ;
F_103 ( F_23 , V_200 , F_23 -> V_206 ) ;
F_103 ( F_23 , V_201 , F_23 -> V_207 ) ;
if ( F_23 -> V_176 & V_196 )
F_103 ( F_23 , V_197 ,
F_23 -> V_208 ) ;
else if ( F_104 ( F_23 ) )
F_20 ( F_23 -> V_208 ,
F_23 -> V_40 + V_198 ) ;
if ( ! ( F_23 -> V_176 & V_209 ) )
return 0 ;
for ( V_76 = 0 ; V_76 < F_23 -> V_210 ; ++ V_76 ) {
V_204 = & F_23 -> V_212 [ V_76 ] ;
F_103 ( F_23 , V_213 , V_76 ) ;
F_103 ( F_23 , V_215 , V_204 -> V_214 ) ;
F_103 ( F_23 , V_217 , V_204 -> V_216 ) ;
F_103 ( F_23 , V_219 , V_204 -> V_218 ) ;
F_103 ( F_23 , V_220 , V_204 -> V_11 ) ;
F_103 ( F_23 , V_221 , V_204 -> V_12 ) ;
F_103 ( F_23 , V_213 , V_222 ) ;
}
return 0 ;
}
bool F_84 ( struct V_8 * V_9 ,
T_3 V_91 ,
T_3 V_12 )
{
return ( ( V_223 ) V_91 * ( V_223 ) V_12 ) < ( V_223 )
( ( V_9 -> V_107 == V_121 ) ?
V_9 -> V_224 : V_9 -> V_225 ) ;
}
T_1 F_108 ( struct V_92 * V_52 , unsigned int V_226 )
{
return 0 ;
}
int F_109 ( struct V_92 * V_52 , unsigned int V_226 )
{
return - V_122 ;
}
void F_110 ( struct V_92 * V_52 , unsigned int V_226 )
{
}
static int F_111 ( struct V_8 * V_9 , unsigned V_227 ,
struct V_119 * V_228 )
{
struct V_92 * V_52 = V_9 -> V_52 ;
struct V_1 * V_2 ;
struct V_229 * V_230 ;
F_37 ( & V_52 -> V_93 . V_94 ) ;
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
V_2 = F_112 ( V_230 ) ;
if ( V_227 > V_2 -> V_231 ) {
V_2 -> V_232 = V_228 [ V_2 -> V_231 ] . V_89 ;
V_2 -> V_233 = V_228 [ V_2 -> V_231 ] . V_90 ;
V_2 -> V_234 = true ;
V_2 -> V_235 = V_228 [ V_2 -> V_231 ] . V_37 ;
V_2 -> V_236 = V_228 [ V_2 -> V_231 ] . V_38 ;
} else {
V_2 -> V_232 = 800 ;
V_2 -> V_233 = 600 ;
V_2 -> V_234 = false ;
}
V_230 -> V_237 = F_113 ( V_230 , true ) ;
}
F_39 ( & V_52 -> V_93 . V_94 ) ;
return 0 ;
}
void F_114 ( struct V_46 * V_6 ,
T_10 * V_238 , T_10 * V_239 , T_10 * V_240 ,
T_3 V_241 , T_3 V_80 )
{
struct V_8 * V_9 = F_23 ( V_6 -> V_52 ) ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_80 ; V_76 ++ ) {
F_115 ( L_24 , V_76 ,
V_238 [ V_76 ] , V_239 [ V_76 ] , V_240 [ V_76 ] ) ;
F_103 ( V_9 , V_242 + V_76 * 3 + 0 , V_238 [ V_76 ] >> 8 ) ;
F_103 ( V_9 , V_242 + V_76 * 3 + 1 , V_239 [ V_76 ] >> 8 ) ;
F_103 ( V_9 , V_242 + V_76 * 3 + 2 , V_240 [ V_76 ] >> 8 ) ;
}
}
int F_116 ( struct V_229 * V_5 , int V_243 )
{
return 0 ;
}
enum V_244
F_113 ( struct V_229 * V_5 , bool V_245 )
{
T_3 V_210 ;
struct V_92 * V_52 = V_5 -> V_52 ;
struct V_8 * V_9 = F_23 ( V_52 ) ;
struct V_1 * V_2 = F_112 ( V_5 ) ;
V_210 = F_105 ( V_9 , V_246 ) ;
return ( ( F_112 ( V_5 ) -> V_231 < V_210 &&
V_2 -> V_234 ) ?
V_247 : V_248 ) ;
}
void F_117 ( struct V_249 * V_243 )
{
V_243 -> V_250 = V_243 -> V_251 + 50 ;
V_243 -> V_252 = V_243 -> V_250 + 50 ;
V_243 -> V_253 = V_243 -> V_252 + 50 ;
V_243 -> V_254 = V_243 -> V_255 + 50 ;
V_243 -> V_256 = V_243 -> V_254 + 50 ;
V_243 -> V_257 = V_243 -> V_256 + 50 ;
V_243 -> clock = ( T_1 ) V_243 -> V_253 * ( T_1 ) V_243 -> V_257 / 100 * 6 ;
V_243 -> V_258 = F_118 ( V_243 ) ;
}
int F_119 ( struct V_229 * V_5 ,
T_3 V_185 , T_3 V_187 )
{
struct V_1 * V_2 = F_112 ( V_5 ) ;
struct V_92 * V_52 = V_5 -> V_52 ;
struct V_8 * V_9 = F_23 ( V_52 ) ;
struct V_249 * V_243 = NULL ;
struct V_249 * V_259 ;
struct V_249 V_260 = { F_120 ( L_25 ,
DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC)
} ;
int V_76 ;
T_1 V_261 = 2 ;
if ( V_9 -> V_107 == V_114 )
V_261 = 4 ;
if ( V_9 -> V_107 == V_121 ) {
V_185 = F_121 ( V_185 , V_9 -> V_262 ) ;
V_187 = F_121 ( V_187 , V_9 -> V_263 ) ;
}
V_243 = F_122 ( V_52 , & V_260 ) ;
if ( ! V_243 )
return 0 ;
V_243 -> V_251 = V_2 -> V_232 ;
V_243 -> V_255 = V_2 -> V_233 ;
F_117 ( V_243 ) ;
if ( F_84 ( V_9 ,
V_243 -> V_251 * V_261 ,
V_243 -> V_255 ) ) {
F_123 ( V_5 , V_243 ) ;
} else {
F_124 ( V_52 , V_243 ) ;
V_243 = NULL ;
}
if ( V_2 -> V_264 ) {
F_125 ( & V_2 -> V_264 -> V_265 ) ;
F_124 ( V_52 , V_2 -> V_264 ) ;
}
V_2 -> V_264 = V_243 ;
for ( V_76 = 0 ; V_266 [ V_76 ] . type != 0 ; V_76 ++ ) {
V_259 = & V_266 [ V_76 ] ;
if ( V_259 -> V_251 > V_185 ||
V_259 -> V_255 > V_187 )
continue;
if ( ! F_84 ( V_9 ,
V_259 -> V_251 * V_261 ,
V_259 -> V_255 ) )
continue;
V_243 = F_122 ( V_52 , V_259 ) ;
if ( ! V_243 )
return 0 ;
V_243 -> V_258 = F_118 ( V_243 ) ;
F_123 ( V_5 , V_243 ) ;
}
F_126 ( V_5 ) ;
F_127 ( & V_5 -> V_267 ) ;
return 1 ;
}
int F_128 ( struct V_229 * V_5 ,
struct V_268 * V_269 ,
T_11 V_270 )
{
return 0 ;
}
int F_129 ( struct V_92 * V_52 , void * V_189 ,
struct V_47 * V_48 )
{
struct V_8 * V_9 = F_23 ( V_52 ) ;
struct V_271 * V_191 =
(struct V_271 * ) V_189 ;
void T_9 * V_272 ;
struct V_119 * V_228 ;
unsigned V_273 ;
int V_31 ;
int V_76 ;
V_223 V_274 = 0 ;
struct V_275 * V_93 = & V_52 -> V_93 ;
struct V_119 V_276 = { 0 } ;
if ( ! V_191 -> V_277 ) {
struct V_119 V_278 = { 0 , 0 , 800 , 600 } ;
F_111 ( V_9 , 1 , & V_278 ) ;
return 0 ;
}
V_273 = V_191 -> V_277 * sizeof( struct V_119 ) ;
V_228 = F_130 ( V_191 -> V_277 , sizeof( struct V_119 ) ,
V_138 ) ;
if ( F_10 ( ! V_228 ) )
return - V_20 ;
V_272 = ( void T_9 * ) ( unsigned long ) V_191 -> V_228 ;
V_31 = F_131 ( V_228 , V_272 , V_273 ) ;
if ( F_10 ( V_31 != 0 ) ) {
F_11 ( L_26 ) ;
V_31 = - V_279 ;
goto V_280;
}
for ( V_76 = 0 ; V_76 < V_191 -> V_277 ; ++ V_76 ) {
if ( V_228 [ V_76 ] . V_37 < 0 ||
V_228 [ V_76 ] . V_38 < 0 ||
V_228 [ V_76 ] . V_37 + V_228 [ V_76 ] . V_89 > V_93 -> V_185 ||
V_228 [ V_76 ] . V_38 + V_228 [ V_76 ] . V_90 > V_93 -> V_187 ) {
F_11 ( L_27 ) ;
V_31 = - V_19 ;
goto V_280;
}
if ( V_228 [ V_76 ] . V_37 + V_228 [ V_76 ] . V_89 > V_276 . V_89 )
V_276 . V_89 = V_228 [ V_76 ] . V_37 + V_228 [ V_76 ] . V_89 ;
if ( V_228 [ V_76 ] . V_38 + V_228 [ V_76 ] . V_90 > V_276 . V_90 )
V_276 . V_90 = V_228 [ V_76 ] . V_38 + V_228 [ V_76 ] . V_90 ;
V_274 += ( V_223 ) V_228 [ V_76 ] . V_89 * ( V_223 ) V_228 [ V_76 ] . V_90 ;
}
if ( V_9 -> V_107 == V_121 ) {
V_223 V_281 = V_276 . V_89 * V_276 . V_90 * 4 ;
V_223 V_282 = V_274 * 4 ;
if ( V_281 > V_9 -> V_224 ) {
F_11 ( L_28 ) ;
V_31 = - V_19 ;
goto V_280;
}
if ( V_282 > V_9 -> V_224 ) {
F_11 ( L_29 ) ;
V_31 = - V_19 ;
goto V_280;
}
}
F_111 ( V_9 , V_191 -> V_277 , V_228 ) ;
V_280:
F_44 ( V_228 ) ;
return V_31 ;
}
int F_132 ( struct V_8 * V_9 ,
struct V_115 * V_96 ,
const struct V_102 * V_103 ,
const struct V_119 * V_120 ,
T_5 V_283 , T_5 V_284 ,
int V_104 ,
int V_149 ,
struct V_285 * V_286 )
{
struct V_1 * V_287 [ V_288 ] ;
struct V_46 * V_6 ;
T_1 V_289 = 0 ;
T_1 V_76 , V_290 ;
V_286 -> V_9 = V_9 ;
F_38 (crtc, &dev_priv->dev->mode_config.crtc_list, head) {
if ( V_6 -> V_214 -> V_291 != & V_96 -> V_34 )
continue;
V_287 [ V_289 ++ ] = F_24 ( V_6 ) ;
}
for ( V_290 = 0 ; V_290 < V_289 ; V_290 ++ ) {
struct V_1 * V_231 = V_287 [ V_290 ] ;
T_5 V_292 = V_231 -> V_6 . V_37 ;
T_5 V_293 = V_231 -> V_6 . V_38 ;
T_5 V_294 = V_231 -> V_6 . V_243 . V_251 ;
T_5 V_295 = V_231 -> V_6 . V_243 . V_255 ;
const struct V_102 * V_296 = V_103 ;
const struct V_119 * V_297 = V_120 ;
V_286 -> V_231 = V_231 ;
if ( V_286 -> V_298 > 0 ) {
V_286 -> V_15 = F_9 ( V_9 ,
V_286 -> V_298 ) ;
if ( ! V_286 -> V_15 ) {
F_11 ( L_30
L_31 ) ;
return - V_20 ;
}
memset ( V_286 -> V_15 , 0 , V_286 -> V_298 ) ;
}
V_286 -> V_299 = 0 ;
for ( V_76 = 0 ; V_76 < V_104 ; V_76 ++ , V_296 += V_149 ,
V_297 += V_149 ) {
T_5 V_300 ;
T_5 V_301 ;
if ( V_103 ) {
V_286 -> V_302 = ( T_5 ) V_296 -> V_110 ;
V_286 -> V_303 = ( T_5 ) V_296 -> y1 ;
V_286 -> V_304 = ( T_5 ) V_296 -> V_111 + V_283 -
V_292 ;
V_286 -> V_305 = ( T_5 ) V_296 -> V_112 + V_284 -
V_293 ;
} else {
V_286 -> V_302 = V_297 -> V_37 ;
V_286 -> V_303 = V_297 -> V_38 ;
V_286 -> V_304 = V_286 -> V_302 + V_297 -> V_89 +
V_283 - V_292 ;
V_286 -> V_305 = V_286 -> V_303 + V_297 -> V_90 +
V_284 - V_293 ;
}
V_286 -> V_306 = V_286 -> V_302 + V_283 - V_292 ;
V_286 -> V_307 = V_286 -> V_303 + V_284 - V_293 ;
if ( V_286 -> V_306 >= V_294 ||
V_286 -> V_307 >= V_295 ||
V_286 -> V_304 <= 0 || V_286 -> V_305 <= 0 )
continue;
V_286 -> V_304 = F_133 ( T_5 , V_286 -> V_304 ,
V_294 ) ;
V_286 -> V_305 = F_133 ( T_5 , V_286 -> V_305 ,
V_295 ) ;
V_300 = F_133 ( T_5 , V_286 -> V_306 , 0 ) ;
V_301 = F_133 ( T_5 , V_286 -> V_307 , 0 ) ;
V_286 -> V_306 -= V_300 ;
V_286 -> V_307 -= V_301 ;
V_286 -> V_302 -= V_300 ;
V_286 -> V_303 -= V_301 ;
V_286 -> V_308 ( V_286 ) ;
}
V_286 -> V_309 ( V_286 ) ;
}
return 0 ;
}
int F_134 ( struct V_8 * V_9 ,
struct V_23 * V_150 ,
bool V_310 ,
bool V_311 )
{
struct V_69 * V_70 = & V_150 -> V_34 ;
int V_31 ;
F_14 ( V_70 , false , false , V_310 , NULL ) ;
V_31 = F_135 ( V_9 , V_70 , V_310 ,
V_311 ) ;
if ( V_31 )
F_18 ( V_70 ) ;
return V_31 ;
}
void F_136 ( struct V_23 * V_150 )
{
if ( V_150 )
F_18 ( & V_150 -> V_34 ) ;
}
void F_137 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_23 * V_150 ,
struct V_312 * * V_313 ,
struct V_117 T_9 *
V_118 )
{
struct V_312 * V_314 ;
T_3 V_49 ;
int V_31 ;
V_31 = F_138 ( V_48 , V_9 , & V_314 ,
V_48 ? & V_49 : NULL ) ;
if ( V_150 )
F_139 ( & V_150 -> V_34 , V_314 ) ;
if ( V_48 )
F_140 ( V_9 , F_27 ( V_48 ) ,
V_31 , V_118 , V_314 ,
V_49 ) ;
if ( V_313 )
* V_313 = V_314 ;
else
F_141 ( & V_314 ) ;
F_136 ( V_150 ) ;
}
void F_142 ( struct V_158 * V_151 )
{
F_136 ( V_151 -> V_152 ) ;
F_77 ( V_151 , false , NULL , 0 ) ;
F_39 ( & V_151 -> V_9 -> V_161 ) ;
}
int F_143 ( struct V_158 * V_151 ,
bool V_310 )
{
int V_31 = 0 ;
if ( V_310 )
V_31 = F_144 ( & V_151 -> V_9 -> V_161 ) ;
else
F_37 ( & V_151 -> V_9 -> V_161 ) ;
if ( F_10 ( V_31 != 0 ) )
return - V_315 ;
V_31 = F_75 ( V_151 , V_310 , false ) ;
if ( V_31 )
goto V_316;
if ( V_151 -> V_152 ) {
V_31 = F_134 ( V_151 -> V_9 , V_151 -> V_152 ,
V_310 ,
V_151 -> V_9 -> V_317 ) ;
if ( V_31 )
goto V_318;
}
V_31 = F_145 ( V_151 ) ;
if ( V_31 )
goto V_319;
return 0 ;
V_319:
F_136 ( V_151 -> V_152 ) ;
V_318:
F_77 ( V_151 , false , NULL , 0 ) ;
V_316:
F_39 ( & V_151 -> V_9 -> V_161 ) ;
return V_31 ;
}
void F_146 ( struct V_158 * V_151 ,
struct V_312 * * V_313 )
{
if ( V_151 -> V_152 || V_313 )
F_137 ( V_151 -> V_9 , NULL , V_151 -> V_152 ,
V_313 , NULL ) ;
F_77 ( V_151 , false , NULL , 0 ) ;
F_39 ( & V_151 -> V_9 -> V_161 ) ;
}
int F_147 ( struct V_158 * V_151 ,
const struct V_102 * V_103 ,
unsigned V_104 ,
int V_149 )
{
struct V_8 * V_9 = V_151 -> V_9 ;
struct V_156 * V_80 = & F_148 ( V_151 ) -> V_131 ;
struct {
T_6 V_71 ;
T_12 V_320 ;
} * V_15 ;
T_13 * V_72 ;
T_14 V_321 = 0 ;
int V_76 ;
if ( ! V_103 )
return 0 ;
V_15 = F_9 ( V_9 , sizeof( * V_15 ) * V_104 ) ;
if ( ! V_15 ) {
F_11 ( L_32
L_33 ) ;
return - V_20 ;
}
for ( V_76 = 0 ; V_76 < V_104 ; ++ V_76 , V_103 += V_149 , ++ V_15 ) {
V_72 = & V_15 -> V_320 . V_72 ;
V_15 -> V_71 . V_22 = V_322 ;
V_15 -> V_71 . V_80 = sizeof( V_15 -> V_320 ) ;
V_15 -> V_320 . V_10 . V_178 = V_151 -> V_22 ;
V_15 -> V_320 . V_10 . V_78 = 0 ;
V_15 -> V_320 . V_10 . V_79 = 0 ;
if ( V_103 -> V_110 > V_80 -> V_11 || V_103 -> V_111 > V_80 -> V_11 ||
V_103 -> y1 > V_80 -> V_12 || V_103 -> V_112 > V_80 -> V_12 ) {
F_11 ( L_34 ) ;
return - V_19 ;
}
V_72 -> V_37 = V_103 -> V_110 ;
V_72 -> V_38 = V_103 -> y1 ;
V_72 -> V_84 = 0 ;
V_72 -> V_89 = V_103 -> V_111 - V_103 -> V_110 ;
V_72 -> V_90 = V_103 -> V_112 - V_103 -> y1 ;
V_72 -> V_88 = 1 ;
V_321 += sizeof( * V_15 ) ;
}
F_149 ( V_9 , V_321 ) ;
return 0 ;
}
int F_150 ( struct V_8 * V_9 ,
unsigned V_231 ,
T_1 V_185 ,
T_1 V_187 ,
struct V_229 * * V_323 ,
struct V_46 * * V_324 ,
struct V_249 * * V_325 )
{
struct V_229 * V_230 ;
struct V_1 * V_2 ;
struct V_249 * V_243 ;
int V_76 = 0 ;
F_38 (con, &dev_priv->dev->mode_config.connector_list,
head) {
if ( V_76 == V_231 )
break;
++ V_76 ;
}
if ( V_76 != V_231 ) {
F_11 ( L_35 ) ;
return - V_19 ;
}
if ( F_151 ( & V_230 -> V_267 ) )
( void ) F_119 ( V_230 , V_185 , V_187 ) ;
if ( F_151 ( & V_230 -> V_267 ) ) {
F_11 ( L_36 ) ;
return - V_19 ;
}
V_2 = F_112 ( V_230 ) ;
* V_323 = V_230 ;
* V_324 = & V_2 -> V_6 ;
F_38 (mode, &con->modes, head) {
if ( V_243 -> type & V_326 )
break;
}
if ( V_243 -> type & V_326 )
* V_325 = V_243 ;
else {
F_54 ( true , L_37 ) ;
* V_325 = F_152 ( & V_230 -> V_267 ,
struct V_249 ,
V_265 ) ;
}
return 0 ;
}
