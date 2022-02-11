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
int V_31 ;
switch ( V_124 -> V_132 ) {
case 32 :
case 24 :
V_127 = V_134 ;
break;
case 16 :
case 15 :
V_127 = V_135 ;
break;
case 8 :
V_127 = V_159 ;
break;
default:
F_11 ( L_15 , V_124 -> V_132 ) ;
return - V_19 ;
}
V_157 . V_11 = V_124 -> V_11 ;
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
F_37 ( & V_151 -> V_9 -> V_160 ) ;
( void ) F_75 ( V_151 , false , true ) ;
F_3 ( & V_151 -> V_152 ) ;
V_151 -> V_152 = F_76 ( V_154 ) ;
V_151 -> V_161 = 0 ;
F_77 ( V_151 , false , NULL , 0 ) ;
F_39 ( & V_151 -> V_9 -> V_160 ) ;
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
unsigned int V_162 ;
int V_31 ;
V_162 = V_124 -> V_12 * V_124 -> V_91 ;
if ( F_10 ( V_162 > V_24 -> V_34 . V_163 * V_32 ) ) {
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
& V_164 ) ;
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
bool V_165 ,
const struct V_123 * V_124 )
{
struct V_115 * V_116 = NULL ;
bool V_125 = false ;
int V_31 ;
if ( V_24 && V_165 &&
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
V_116 -> V_166 = F_64 ;
V_116 -> V_167 = F_70 ;
return V_116 ;
}
static struct V_95 * F_82 ( struct V_92 * V_52 ,
struct V_47 * V_48 ,
struct V_168 * V_169 )
{
struct V_8 * V_9 = F_23 ( V_52 ) ;
struct V_58 * V_59 = F_27 ( V_48 ) -> V_59 ;
struct V_115 * V_116 = NULL ;
struct V_53 * V_54 = NULL ;
struct V_23 * V_70 = NULL ;
struct V_170 * V_99 ;
struct V_123 V_124 ;
int V_31 ;
V_124 . V_11 = V_169 -> V_11 ;
V_124 . V_12 = V_169 -> V_12 ;
V_124 . V_91 = V_169 -> V_142 [ 0 ] ;
V_124 . V_49 = V_169 -> V_171 [ 0 ] ;
F_83 ( V_169 -> V_172 , & V_124 . V_132 ,
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
return F_80 ( - V_173 ) ;
}
V_31 = F_28 ( V_9 , V_59 ,
V_124 . V_49 ,
& V_54 , & V_70 ) ;
if ( V_31 )
goto V_174;
V_116 = F_79 ( V_9 , V_70 , V_54 ,
! ( V_9 -> V_175 & V_176 ) ,
& V_124 ) ;
if ( F_86 ( V_116 ) ) {
V_31 = F_87 ( V_116 ) ;
goto V_174;
}
V_174:
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
T_3 V_177 ,
T_4 V_178 , T_4 V_179 ,
struct V_119 * V_103 ,
T_3 V_104 )
{
return F_47 ( V_9 , V_116 , NULL , V_103 ,
& V_54 -> V_151 , V_178 , V_179 ,
V_104 , 1 , NULL ) ;
}
int F_89 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_115 * V_116 ,
struct V_53 * V_54 ,
T_3 V_177 ,
T_4 V_178 , T_4 V_179 ,
struct V_119 * V_103 ,
T_3 V_104 )
{
int V_31 ;
switch ( V_9 -> V_107 ) {
case V_121 :
V_31 = F_48 ( V_9 , V_116 , NULL , V_103 ,
& V_54 -> V_151 , V_178 , V_179 ,
V_104 , 1 , NULL ) ;
break;
case V_114 :
V_31 = F_88 ( V_9 , V_48 , V_116 , V_54 ,
V_177 , V_178 , V_179 , V_103 ,
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
V_52 -> V_93 . V_180 = & V_181 ;
V_52 -> V_93 . V_182 = 1 ;
V_52 -> V_93 . V_183 = 1 ;
V_52 -> V_93 . V_184 = V_9 -> V_185 ;
V_52 -> V_93 . V_186 = V_9 -> V_187 ;
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
int F_100 ( struct V_92 * V_52 , void * V_188 ,
struct V_47 * V_48 )
{
struct V_189 * V_190 = V_188 ;
struct V_1 * V_2 ;
struct V_46 * V_6 ;
int V_31 = 0 ;
F_37 ( & V_52 -> V_93 . V_94 ) ;
if ( V_190 -> V_100 & V_191 ) {
F_38 (crtc, &dev->mode_config.crtc_list, head) {
V_2 = F_24 ( V_6 ) ;
V_2 -> V_55 = V_190 -> V_192 ;
V_2 -> V_56 = V_190 -> V_193 ;
}
F_39 ( & V_52 -> V_93 . V_94 ) ;
return 0 ;
}
V_6 = F_101 ( V_52 , V_190 -> V_194 ) ;
if ( ! V_6 ) {
V_31 = - V_173 ;
goto V_57;
}
V_2 = F_24 ( V_6 ) ;
V_2 -> V_55 = V_190 -> V_192 ;
V_2 -> V_56 = V_190 -> V_193 ;
V_57:
F_39 ( & V_52 -> V_93 . V_94 ) ;
return V_31 ;
}
int F_102 ( struct V_8 * F_23 ,
unsigned V_11 , unsigned V_12 , unsigned V_91 ,
unsigned V_141 , unsigned V_132 )
{
if ( F_23 -> V_175 & V_195 )
F_103 ( F_23 , V_196 , V_91 ) ;
else if ( F_104 ( F_23 ) )
F_20 ( V_91 , F_23 -> V_40 +
V_197 ) ;
F_103 ( F_23 , V_198 , V_11 ) ;
F_103 ( F_23 , V_199 , V_12 ) ;
F_103 ( F_23 , V_200 , V_141 ) ;
if ( F_105 ( F_23 , V_201 ) != V_132 ) {
F_11 ( L_23 ,
V_132 , V_141 , F_105 ( F_23 , V_201 ) ) ;
return - V_19 ;
}
return 0 ;
}
int F_106 ( struct V_8 * F_23 )
{
struct V_202 * V_203 ;
T_3 V_76 ;
F_23 -> V_204 = F_105 ( F_23 , V_198 ) ;
F_23 -> V_205 = F_105 ( F_23 , V_199 ) ;
F_23 -> V_206 = F_105 ( F_23 , V_200 ) ;
if ( F_23 -> V_175 & V_195 )
F_23 -> V_207 =
F_105 ( F_23 , V_196 ) ;
else if ( F_104 ( F_23 ) )
F_23 -> V_207 = F_21 ( F_23 -> V_40 +
V_197 ) ;
if ( ! ( F_23 -> V_175 & V_208 ) )
return 0 ;
F_23 -> V_209 = F_105 ( F_23 ,
V_210 ) ;
if ( F_23 -> V_209 == 0 )
F_23 -> V_209 = 1 ;
for ( V_76 = 0 ; V_76 < F_23 -> V_209 ; ++ V_76 ) {
V_203 = & F_23 -> V_211 [ V_76 ] ;
F_103 ( F_23 , V_212 , V_76 ) ;
V_203 -> V_213 = F_105 ( F_23 , V_214 ) ;
V_203 -> V_215 = F_105 ( F_23 , V_216 ) ;
V_203 -> V_217 = F_105 ( F_23 , V_218 ) ;
V_203 -> V_11 = F_105 ( F_23 , V_219 ) ;
V_203 -> V_12 = F_105 ( F_23 , V_220 ) ;
F_103 ( F_23 , V_212 , V_221 ) ;
if ( V_76 == 0 && F_23 -> V_209 == 1 &&
V_203 -> V_11 == 0 && V_203 -> V_12 == 0 ) {
V_203 -> V_11 = F_23 -> V_204 - V_203 -> V_215 ;
V_203 -> V_12 = F_23 -> V_205 - V_203 -> V_217 ;
}
}
return 0 ;
}
int F_107 ( struct V_8 * F_23 )
{
struct V_202 * V_203 ;
T_3 V_76 ;
F_103 ( F_23 , V_198 , F_23 -> V_204 ) ;
F_103 ( F_23 , V_199 , F_23 -> V_205 ) ;
F_103 ( F_23 , V_200 , F_23 -> V_206 ) ;
if ( F_23 -> V_175 & V_195 )
F_103 ( F_23 , V_196 ,
F_23 -> V_207 ) ;
else if ( F_104 ( F_23 ) )
F_20 ( F_23 -> V_207 ,
F_23 -> V_40 + V_197 ) ;
if ( ! ( F_23 -> V_175 & V_208 ) )
return 0 ;
for ( V_76 = 0 ; V_76 < F_23 -> V_209 ; ++ V_76 ) {
V_203 = & F_23 -> V_211 [ V_76 ] ;
F_103 ( F_23 , V_212 , V_76 ) ;
F_103 ( F_23 , V_214 , V_203 -> V_213 ) ;
F_103 ( F_23 , V_216 , V_203 -> V_215 ) ;
F_103 ( F_23 , V_218 , V_203 -> V_217 ) ;
F_103 ( F_23 , V_219 , V_203 -> V_11 ) ;
F_103 ( F_23 , V_220 , V_203 -> V_12 ) ;
F_103 ( F_23 , V_212 , V_221 ) ;
}
return 0 ;
}
bool F_84 ( struct V_8 * V_9 ,
T_3 V_91 ,
T_3 V_12 )
{
return ( ( V_222 ) V_91 * ( V_222 ) V_12 ) < ( V_222 )
( ( V_9 -> V_107 == V_121 ) ?
V_9 -> V_223 : V_9 -> V_224 ) ;
}
T_1 F_108 ( struct V_92 * V_52 , unsigned int V_225 )
{
return 0 ;
}
int F_109 ( struct V_92 * V_52 , unsigned int V_225 )
{
return - V_122 ;
}
void F_110 ( struct V_92 * V_52 , unsigned int V_225 )
{
}
static int F_111 ( struct V_8 * V_9 , unsigned V_226 ,
struct V_119 * V_227 )
{
struct V_92 * V_52 = V_9 -> V_52 ;
struct V_1 * V_2 ;
struct V_228 * V_229 ;
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
V_2 = F_112 ( V_229 ) ;
if ( V_226 > V_2 -> V_230 ) {
V_2 -> V_231 = V_227 [ V_2 -> V_230 ] . V_89 ;
V_2 -> V_232 = V_227 [ V_2 -> V_230 ] . V_90 ;
V_2 -> V_233 = true ;
V_2 -> V_234 = V_227 [ V_2 -> V_230 ] . V_37 ;
V_2 -> V_235 = V_227 [ V_2 -> V_230 ] . V_38 ;
} else {
V_2 -> V_231 = 800 ;
V_2 -> V_232 = 600 ;
V_2 -> V_233 = false ;
}
V_229 -> V_236 = F_113 ( V_229 , true ) ;
}
F_39 ( & V_52 -> V_93 . V_94 ) ;
return 0 ;
}
void F_114 ( struct V_46 * V_6 )
{
}
void F_115 ( struct V_46 * V_6 )
{
}
void F_116 ( struct V_46 * V_6 ,
T_10 * V_237 , T_10 * V_238 , T_10 * V_239 ,
T_3 V_240 , T_3 V_80 )
{
struct V_8 * V_9 = F_23 ( V_6 -> V_52 ) ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_80 ; V_76 ++ ) {
F_117 ( L_24 , V_76 ,
V_237 [ V_76 ] , V_238 [ V_76 ] , V_239 [ V_76 ] ) ;
F_103 ( V_9 , V_241 + V_76 * 3 + 0 , V_237 [ V_76 ] >> 8 ) ;
F_103 ( V_9 , V_241 + V_76 * 3 + 1 , V_238 [ V_76 ] >> 8 ) ;
F_103 ( V_9 , V_241 + V_76 * 3 + 2 , V_239 [ V_76 ] >> 8 ) ;
}
}
int F_118 ( struct V_228 * V_5 , int V_242 )
{
return 0 ;
}
void F_119 ( struct V_228 * V_5 )
{
}
void F_120 ( struct V_228 * V_5 )
{
}
enum V_243
F_113 ( struct V_228 * V_5 , bool V_244 )
{
T_3 V_209 ;
struct V_92 * V_52 = V_5 -> V_52 ;
struct V_8 * V_9 = F_23 ( V_52 ) ;
struct V_1 * V_2 = F_112 ( V_5 ) ;
V_209 = F_105 ( V_9 , V_245 ) ;
return ( ( F_112 ( V_5 ) -> V_230 < V_209 &&
V_2 -> V_233 ) ?
V_246 : V_247 ) ;
}
void F_121 ( struct V_248 * V_242 )
{
V_242 -> V_249 = V_242 -> V_250 + 50 ;
V_242 -> V_251 = V_242 -> V_249 + 50 ;
V_242 -> V_252 = V_242 -> V_251 + 50 ;
V_242 -> V_253 = V_242 -> V_254 + 50 ;
V_242 -> V_255 = V_242 -> V_253 + 50 ;
V_242 -> V_256 = V_242 -> V_255 + 50 ;
V_242 -> clock = ( T_1 ) V_242 -> V_252 * ( T_1 ) V_242 -> V_256 / 100 * 6 ;
V_242 -> V_257 = F_122 ( V_242 ) ;
}
int F_123 ( struct V_228 * V_5 ,
T_3 V_184 , T_3 V_186 )
{
struct V_1 * V_2 = F_112 ( V_5 ) ;
struct V_92 * V_52 = V_5 -> V_52 ;
struct V_8 * V_9 = F_23 ( V_52 ) ;
struct V_248 * V_242 = NULL ;
struct V_248 * V_258 ;
struct V_248 V_259 = { F_124 ( L_25 ,
DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC)
} ;
int V_76 ;
T_1 V_260 = 2 ;
if ( V_9 -> V_107 == V_114 )
V_260 = 4 ;
if ( V_9 -> V_107 == V_121 ) {
V_184 = F_125 ( V_184 , V_9 -> V_261 ) ;
V_186 = F_125 ( V_186 , V_9 -> V_262 ) ;
}
V_242 = F_126 ( V_52 , & V_259 ) ;
if ( ! V_242 )
return 0 ;
V_242 -> V_250 = V_2 -> V_231 ;
V_242 -> V_254 = V_2 -> V_232 ;
F_121 ( V_242 ) ;
if ( F_84 ( V_9 ,
V_242 -> V_250 * V_260 ,
V_242 -> V_254 ) ) {
F_127 ( V_5 , V_242 ) ;
} else {
F_128 ( V_52 , V_242 ) ;
V_242 = NULL ;
}
if ( V_2 -> V_263 ) {
F_129 ( & V_2 -> V_263 -> V_264 ) ;
F_128 ( V_52 , V_2 -> V_263 ) ;
}
V_2 -> V_263 = V_242 ;
for ( V_76 = 0 ; V_265 [ V_76 ] . type != 0 ; V_76 ++ ) {
V_258 = & V_265 [ V_76 ] ;
if ( V_258 -> V_250 > V_184 ||
V_258 -> V_254 > V_186 )
continue;
if ( ! F_84 ( V_9 ,
V_258 -> V_250 * V_260 ,
V_258 -> V_254 ) )
continue;
V_242 = F_126 ( V_52 , V_258 ) ;
if ( ! V_242 )
return 0 ;
V_242 -> V_257 = F_122 ( V_242 ) ;
F_127 ( V_5 , V_242 ) ;
}
F_130 ( V_5 , true ) ;
F_131 ( & V_5 -> V_266 ) ;
return 1 ;
}
int F_132 ( struct V_228 * V_5 ,
struct V_267 * V_268 ,
T_11 V_269 )
{
return 0 ;
}
int F_133 ( struct V_92 * V_52 , void * V_188 ,
struct V_47 * V_48 )
{
struct V_8 * V_9 = F_23 ( V_52 ) ;
struct V_270 * V_190 =
(struct V_270 * ) V_188 ;
void T_9 * V_271 ;
struct V_119 * V_227 ;
unsigned V_272 ;
int V_31 ;
int V_76 ;
V_222 V_273 = 0 ;
struct V_274 * V_93 = & V_52 -> V_93 ;
struct V_119 V_275 = { 0 } ;
if ( ! V_190 -> V_276 ) {
struct V_119 V_277 = { 0 , 0 , 800 , 600 } ;
F_111 ( V_9 , 1 , & V_277 ) ;
return 0 ;
}
V_272 = V_190 -> V_276 * sizeof( struct V_119 ) ;
V_227 = F_134 ( V_190 -> V_276 , sizeof( struct V_119 ) ,
V_138 ) ;
if ( F_10 ( ! V_227 ) )
return - V_20 ;
V_271 = ( void T_9 * ) ( unsigned long ) V_190 -> V_227 ;
V_31 = F_135 ( V_227 , V_271 , V_272 ) ;
if ( F_10 ( V_31 != 0 ) ) {
F_11 ( L_26 ) ;
V_31 = - V_278 ;
goto V_279;
}
for ( V_76 = 0 ; V_76 < V_190 -> V_276 ; ++ V_76 ) {
if ( V_227 [ V_76 ] . V_37 < 0 ||
V_227 [ V_76 ] . V_38 < 0 ||
V_227 [ V_76 ] . V_37 + V_227 [ V_76 ] . V_89 > V_93 -> V_184 ||
V_227 [ V_76 ] . V_38 + V_227 [ V_76 ] . V_90 > V_93 -> V_186 ) {
F_11 ( L_27 ) ;
V_31 = - V_19 ;
goto V_279;
}
if ( V_227 [ V_76 ] . V_37 + V_227 [ V_76 ] . V_89 > V_275 . V_89 )
V_275 . V_89 = V_227 [ V_76 ] . V_37 + V_227 [ V_76 ] . V_89 ;
if ( V_227 [ V_76 ] . V_38 + V_227 [ V_76 ] . V_90 > V_275 . V_90 )
V_275 . V_90 = V_227 [ V_76 ] . V_38 + V_227 [ V_76 ] . V_90 ;
V_273 += ( V_222 ) V_227 [ V_76 ] . V_89 * ( V_222 ) V_227 [ V_76 ] . V_90 ;
}
if ( V_9 -> V_107 == V_121 ) {
V_222 V_280 = V_275 . V_89 * V_275 . V_90 * 4 ;
V_222 V_281 = V_273 * 4 ;
if ( V_280 > V_9 -> V_223 ) {
F_11 ( L_28 ) ;
V_31 = - V_19 ;
goto V_279;
}
if ( V_281 > V_9 -> V_223 ) {
F_11 ( L_29 ) ;
V_31 = - V_19 ;
goto V_279;
}
}
F_111 ( V_9 , V_190 -> V_276 , V_227 ) ;
V_279:
F_44 ( V_227 ) ;
return V_31 ;
}
int F_136 ( struct V_8 * V_9 ,
struct V_115 * V_96 ,
const struct V_102 * V_103 ,
const struct V_119 * V_120 ,
T_5 V_282 , T_5 V_283 ,
int V_104 ,
int V_149 ,
struct V_284 * V_285 )
{
struct V_1 * V_286 [ V_287 ] ;
struct V_46 * V_6 ;
T_1 V_288 = 0 ;
T_1 V_76 , V_289 ;
V_285 -> V_9 = V_9 ;
F_38 (crtc, &dev_priv->dev->mode_config.crtc_list, head) {
if ( V_6 -> V_213 -> V_290 != & V_96 -> V_34 )
continue;
V_286 [ V_288 ++ ] = F_24 ( V_6 ) ;
}
for ( V_289 = 0 ; V_289 < V_288 ; V_289 ++ ) {
struct V_1 * V_230 = V_286 [ V_289 ] ;
T_5 V_291 = V_230 -> V_6 . V_37 ;
T_5 V_292 = V_230 -> V_6 . V_38 ;
T_5 V_293 = V_230 -> V_6 . V_242 . V_250 ;
T_5 V_294 = V_230 -> V_6 . V_242 . V_254 ;
const struct V_102 * V_295 = V_103 ;
const struct V_119 * V_296 = V_120 ;
V_285 -> V_230 = V_230 ;
if ( V_285 -> V_297 > 0 ) {
V_285 -> V_15 = F_9 ( V_9 ,
V_285 -> V_297 ) ;
if ( ! V_285 -> V_15 ) {
F_11 ( L_30
L_31 ) ;
return - V_20 ;
}
memset ( V_285 -> V_15 , 0 , V_285 -> V_297 ) ;
}
V_285 -> V_298 = 0 ;
for ( V_76 = 0 ; V_76 < V_104 ; V_76 ++ , V_295 += V_149 ,
V_296 += V_149 ) {
T_5 V_299 ;
T_5 V_300 ;
if ( V_103 ) {
V_285 -> V_301 = ( T_5 ) V_295 -> V_110 ;
V_285 -> V_302 = ( T_5 ) V_295 -> y1 ;
V_285 -> V_303 = ( T_5 ) V_295 -> V_111 + V_282 -
V_291 ;
V_285 -> V_304 = ( T_5 ) V_295 -> V_112 + V_283 -
V_292 ;
} else {
V_285 -> V_301 = V_296 -> V_37 ;
V_285 -> V_302 = V_296 -> V_38 ;
V_285 -> V_303 = V_285 -> V_301 + V_296 -> V_89 +
V_282 - V_291 ;
V_285 -> V_304 = V_285 -> V_302 + V_296 -> V_90 +
V_283 - V_292 ;
}
V_285 -> V_305 = V_285 -> V_301 + V_282 - V_291 ;
V_285 -> V_306 = V_285 -> V_302 + V_283 - V_292 ;
if ( V_285 -> V_305 >= V_293 ||
V_285 -> V_306 >= V_294 ||
V_285 -> V_303 <= 0 || V_285 -> V_304 <= 0 )
continue;
V_285 -> V_303 = F_137 ( T_5 , V_285 -> V_303 ,
V_293 ) ;
V_285 -> V_304 = F_137 ( T_5 , V_285 -> V_304 ,
V_294 ) ;
V_299 = F_137 ( T_5 , V_285 -> V_305 , 0 ) ;
V_300 = F_137 ( T_5 , V_285 -> V_306 , 0 ) ;
V_285 -> V_305 -= V_299 ;
V_285 -> V_306 -= V_300 ;
V_285 -> V_301 -= V_299 ;
V_285 -> V_302 -= V_300 ;
V_285 -> V_307 ( V_285 ) ;
}
V_285 -> V_308 ( V_285 ) ;
}
return 0 ;
}
int F_138 ( struct V_8 * V_9 ,
struct V_23 * V_150 ,
bool V_309 ,
bool V_310 )
{
struct V_69 * V_70 = & V_150 -> V_34 ;
int V_31 ;
F_14 ( V_70 , false , false , V_309 , NULL ) ;
V_31 = F_139 ( V_9 , V_70 , V_309 ,
V_310 ) ;
if ( V_31 )
F_18 ( V_70 ) ;
return V_31 ;
}
void F_140 ( struct V_23 * V_150 )
{
if ( V_150 )
F_18 ( & V_150 -> V_34 ) ;
}
void F_141 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_23 * V_150 ,
struct V_311 * * V_312 ,
struct V_117 T_9 *
V_118 )
{
struct V_311 * V_313 ;
T_3 V_49 ;
int V_31 ;
V_31 = F_142 ( V_48 , V_9 , & V_313 ,
V_48 ? & V_49 : NULL ) ;
if ( V_150 )
F_143 ( & V_150 -> V_34 , V_313 ) ;
if ( V_48 )
F_144 ( V_9 , F_27 ( V_48 ) ,
V_31 , V_118 , V_313 ,
V_49 ) ;
if ( V_312 )
* V_312 = V_313 ;
else
F_145 ( & V_313 ) ;
F_140 ( V_150 ) ;
}
void F_146 ( struct V_158 * V_151 )
{
F_140 ( V_151 -> V_152 ) ;
F_77 ( V_151 , false , NULL , 0 ) ;
F_39 ( & V_151 -> V_9 -> V_160 ) ;
}
int F_147 ( struct V_158 * V_151 ,
bool V_309 )
{
int V_31 = 0 ;
if ( V_309 )
V_31 = F_148 ( & V_151 -> V_9 -> V_160 ) ;
else
F_37 ( & V_151 -> V_9 -> V_160 ) ;
if ( F_10 ( V_31 != 0 ) )
return - V_314 ;
V_31 = F_75 ( V_151 , V_309 , false ) ;
if ( V_31 )
goto V_315;
if ( V_151 -> V_152 ) {
V_31 = F_138 ( V_151 -> V_9 , V_151 -> V_152 ,
V_309 ,
V_151 -> V_9 -> V_316 ) ;
if ( V_31 )
goto V_317;
}
V_31 = F_149 ( V_151 ) ;
if ( V_31 )
goto V_318;
return 0 ;
V_318:
F_140 ( V_151 -> V_152 ) ;
V_317:
F_77 ( V_151 , false , NULL , 0 ) ;
V_315:
F_39 ( & V_151 -> V_9 -> V_160 ) ;
return V_31 ;
}
void F_150 ( struct V_158 * V_151 ,
struct V_311 * * V_312 )
{
if ( V_151 -> V_152 || V_312 )
F_141 ( V_151 -> V_9 , NULL , V_151 -> V_152 ,
V_312 , NULL ) ;
F_77 ( V_151 , false , NULL , 0 ) ;
F_39 ( & V_151 -> V_9 -> V_160 ) ;
}
int F_151 ( struct V_158 * V_151 ,
const struct V_102 * V_103 ,
unsigned V_104 ,
int V_149 )
{
struct V_8 * V_9 = V_151 -> V_9 ;
struct V_156 * V_80 = & F_152 ( V_151 ) -> V_131 ;
struct {
T_6 V_71 ;
T_12 V_319 ;
} * V_15 ;
T_13 * V_72 ;
T_14 V_320 = 0 ;
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
V_72 = & V_15 -> V_319 . V_72 ;
V_15 -> V_71 . V_22 = V_321 ;
V_15 -> V_71 . V_80 = sizeof( V_15 -> V_319 ) ;
V_15 -> V_319 . V_10 . V_177 = V_151 -> V_22 ;
V_15 -> V_319 . V_10 . V_78 = 0 ;
V_15 -> V_319 . V_10 . V_79 = 0 ;
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
V_320 += sizeof( * V_15 ) ;
}
F_153 ( V_9 , V_320 ) ;
return 0 ;
}
int F_154 ( struct V_8 * V_9 ,
unsigned V_230 ,
T_1 V_184 ,
T_1 V_186 ,
struct V_228 * * V_322 ,
struct V_46 * * V_323 ,
struct V_248 * * V_324 )
{
struct V_228 * V_229 ;
struct V_1 * V_2 ;
struct V_248 * V_242 ;
int V_76 = 0 ;
F_38 (con, &dev_priv->dev->mode_config.connector_list,
head) {
if ( V_76 == V_230 )
break;
++ V_76 ;
}
if ( V_76 != V_230 ) {
F_11 ( L_35 ) ;
return - V_19 ;
}
if ( F_155 ( & V_229 -> V_266 ) )
( void ) F_123 ( V_229 , V_184 , V_186 ) ;
if ( F_155 ( & V_229 -> V_266 ) ) {
F_11 ( L_36 ) ;
return - V_19 ;
}
V_2 = F_112 ( V_229 ) ;
* V_322 = V_229 ;
* V_323 = & V_2 -> V_6 ;
F_38 (mode, &con->modes, head) {
if ( V_242 -> type & V_325 )
break;
}
if ( V_242 -> type & V_325 )
* V_324 = V_242 ;
else {
F_54 ( true , L_37 ) ;
* V_324 = F_156 ( & V_229 -> V_266 ,
struct V_248 ,
V_264 ) ;
}
return 0 ;
}
