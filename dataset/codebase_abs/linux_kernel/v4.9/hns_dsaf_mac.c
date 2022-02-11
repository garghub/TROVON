static enum V_1 F_1 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_4 ) {
case V_5 :
return V_6 [ V_3 -> V_7 ] ;
case V_8 :
return V_9 [ V_3 -> V_7 ] ;
case V_10 :
return V_11 ;
default:
return V_12 ;
}
}
void F_2 ( struct V_2 * V_3 , T_1 * V_13 )
{
struct V_14 * V_15 ;
int V_16 , V_17 ;
V_15 = F_3 ( V_3 ) ;
if ( V_15 -> V_18 )
V_15 -> V_18 ( V_15 , V_13 ) ;
else
* V_13 = 0 ;
V_16 = V_3 -> V_19 -> V_20 -> V_21 ( V_3 , & V_17 ) ;
if ( ! V_16 )
* V_13 = * V_13 && V_17 ;
V_3 -> V_22 = * V_13 ;
}
int F_4 ( struct V_2 * V_3 ,
T_2 * V_23 , T_3 * V_24 , T_2 * V_25 )
{
struct V_14 * V_15 ;
struct V_26 V_27 ;
V_15 = F_3 ( V_3 ) ;
if ( ! V_15 -> V_28 )
return - V_29 ;
V_15 -> V_28 ( V_15 , & V_27 ) ;
if ( V_23 )
* V_23 = V_27 . V_23 ;
if ( V_24 )
* V_24 = V_27 . V_24 ;
if ( V_25 )
* V_25 = V_27 . V_25 ;
return 0 ;
}
void F_5 ( struct V_2 * V_3 , int V_24 , int V_25 )
{
int V_16 ;
struct V_14 * V_15 ;
V_15 = (struct V_14 * ) ( V_3 -> V_30 . V_31 ) ;
V_3 -> V_24 = V_24 ;
V_3 -> V_32 = ! V_25 ;
if ( V_15 -> V_33 ) {
V_16 = V_15 -> V_33 ( V_15 ,
(enum V_34 ) V_24 , V_25 ) ;
if ( V_16 ) {
F_6 ( V_3 -> V_35 ,
L_1 ,
V_3 -> V_19 -> V_36 . V_37 ,
V_3 -> V_38 , V_16 ) ;
return;
}
}
}
int F_7 ( struct V_2 * V_3 , T_2 V_39 , T_2 * V_40 )
{
int V_41 , V_42 ;
int V_43 ;
T_2 V_44 ;
if ( V_3 -> V_19 -> V_45 <= V_46 ) {
if ( V_3 -> V_38 != V_47 ) {
F_6 ( V_3 -> V_35 ,
L_2 ,
V_3 -> V_19 -> V_36 . V_37 ,
V_3 -> V_38 , V_39 ) ;
return - V_48 ;
}
} else if ( V_3 -> V_19 -> V_45 < V_49 ) {
if ( V_3 -> V_38 >= V_47 ) {
F_6 ( V_3 -> V_35 ,
L_3 ,
V_3 -> V_19 -> V_36 . V_37 ,
V_3 -> V_38 , V_39 ) ;
return - V_48 ;
}
} else {
F_6 ( V_3 -> V_35 , L_4 ,
V_3 -> V_19 -> V_36 . V_37 , V_3 -> V_38 ) ;
return - V_48 ;
}
if ( V_39 >= V_3 -> V_19 -> V_50 [ 0 ] -> V_51 ) {
F_6 ( V_3 -> V_35 , L_2 ,
V_3 -> V_19 -> V_36 . V_37 , V_3 -> V_38 , V_39 ) ;
return - V_48 ;
}
V_41 = V_3 -> V_19 -> V_50 [ 0 ] -> V_52 ;
V_42 = V_3 -> V_19 -> V_50 [ 0 ] -> V_51 ;
V_43 = V_39 * V_41 +
V_42 * V_41 * V_3 -> V_38 ;
switch ( V_3 -> V_19 -> V_45 ) {
case V_53 :
V_44 = 0 ;
break;
case V_54 :
V_44 = 0 ;
break;
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
V_44 = V_43 ;
break;
default:
F_6 ( V_3 -> V_35 , L_4 ,
V_3 -> V_19 -> V_36 . V_37 , V_3 -> V_38 ) ;
return - V_48 ;
}
V_44 += V_67 ;
* V_40 = V_44 ;
return 0 ;
}
int F_8 ( struct V_2 * V_3 ,
T_1 V_39 , char * V_68 )
{
int V_16 ;
struct V_14 * V_15 = F_3 ( V_3 ) ;
struct V_69 * V_19 = V_3 -> V_19 ;
struct V_70 V_71 ;
struct V_72 * V_73 ;
V_73 = & V_3 -> V_74 [ V_39 ] ;
if ( ! F_9 ( V_19 ) ) {
memcpy ( V_71 . V_68 , V_68 , sizeof( V_71 . V_68 ) ) ;
V_71 . V_75 = V_73 -> V_76 ;
V_71 . V_77 = V_3 -> V_38 ;
V_16 = F_7 ( V_3 , ( T_2 ) V_39 ,
& V_71 . V_40 ) ;
if ( V_16 )
return V_16 ;
if ( ( V_73 -> V_78 != 0 ) &&
( memcmp ( V_73 -> V_68 ,
V_68 , sizeof( V_71 . V_68 ) ) != 0 ) ) {
V_16 = F_10 ( V_19 ,
V_73 -> V_76 ,
V_3 -> V_38 ,
V_73 -> V_68 ) ;
if ( V_16 )
return V_16 ;
}
V_16 = F_11 ( V_19 , & V_71 ) ;
if ( V_16 )
return V_16 ;
}
if ( ( V_15 -> V_79 ) && ( V_39 == 0 ) )
V_15 -> V_79 ( V_3 -> V_30 . V_31 , V_68 ) ;
memcpy ( V_73 -> V_68 , V_68 , sizeof( V_73 -> V_68 ) ) ;
V_73 -> V_78 = 1 ;
return 0 ;
}
int F_12 ( struct V_2 * V_3 ,
T_1 V_40 , char * V_68 , bool V_80 )
{
int V_16 ;
struct V_69 * V_19 = V_3 -> V_19 ;
struct V_70 V_71 ;
if ( ! F_9 ( V_19 ) && V_68 ) {
memcpy ( V_71 . V_68 , V_68 , sizeof( V_71 . V_68 ) ) ;
V_71 . V_75 = 0 ;
V_71 . V_77 = V_3 -> V_38 ;
V_71 . V_40 = V_40 ;
if ( ! V_80 )
V_16 = F_13 ( V_19 , & V_71 ) ;
else
V_16 = F_14 ( V_19 , & V_71 ) ;
if ( V_16 ) {
F_6 ( V_19 -> V_35 ,
L_5 ,
V_3 -> V_19 -> V_36 . V_37 ,
V_3 -> V_38 , V_16 ) ;
return V_16 ;
}
}
return 0 ;
}
int F_15 ( struct V_2 * V_3 , T_1 V_81 , char * V_31 )
{
struct V_72 * V_82 ;
struct V_69 * V_19 ;
T_1 V_16 ;
V_19 = V_3 -> V_19 ;
if ( V_81 < V_83 ) {
V_82 = & V_3 -> V_74 [ V_81 ] ;
} else {
F_6 ( V_3 -> V_35 ,
L_6 ,
V_3 -> V_19 -> V_36 . V_37 , V_3 -> V_38 , V_81 ) ;
return - V_48 ;
}
if ( V_19 ) {
V_16 = F_10 ( V_19 , V_82 -> V_76 ,
V_3 -> V_38 , V_82 -> V_68 ) ;
if ( V_16 )
return V_16 ;
if ( memcmp ( V_82 -> V_68 , V_31 , sizeof( V_82 -> V_68 ) ) == 0 )
V_82 -> V_78 = 0 ;
}
return 0 ;
}
static void F_16 ( struct V_84 * V_85 ,
struct V_2 * V_3 )
{
V_85 -> V_86 = ( void * ) V_3 -> V_86 ;
V_85 -> V_1 = F_1 ( V_3 ) ;
memcpy ( V_85 -> V_68 , V_3 -> V_74 [ 0 ] . V_68 ,
V_87 ) ;
V_85 -> V_38 = V_3 -> V_38 ;
V_85 -> V_35 = V_3 -> V_35 ;
}
static int F_17 ( struct V_2 * V_3 ,
T_1 V_40 , T_3 V_76 , bool V_80 )
{
int V_16 ;
struct V_69 * V_19 = V_3 -> V_19 ;
T_2 V_68 [ V_87 ]
= { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_70 V_71 ;
if ( V_3 -> V_88 == V_89 )
return 0 ;
if ( ! F_9 ( V_19 ) ) {
memcpy ( V_71 . V_68 , V_68 , sizeof( V_71 . V_68 ) ) ;
V_71 . V_75 = V_76 ;
V_71 . V_77 = V_3 -> V_38 ;
V_71 . V_40 = V_40 ;
if ( ! V_80 )
V_16 = F_13 ( V_19 , & V_71 ) ;
else
V_16 = F_14 ( V_19 , & V_71 ) ;
return V_16 ;
}
return 0 ;
}
int F_18 ( struct V_2 * V_3 , T_1 V_39 , bool V_80 )
{
int V_16 ;
struct V_69 * V_19 = V_3 -> V_19 ;
T_2 V_40 ;
T_2 V_68 [ V_87 ]
= { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_72 * V_90 ;
struct V_70 V_71 ;
if ( V_3 -> V_88 == V_89 )
return 0 ;
V_90 = & V_3 -> V_74 [ V_39 ] ;
if ( ! F_9 ( V_19 ) ) {
memcpy ( V_71 . V_68 , V_68 , sizeof( V_71 . V_68 ) ) ;
V_71 . V_75 = V_90 -> V_76 ;
V_71 . V_77 = V_3 -> V_38 ;
V_16 = F_7 ( V_3 , V_39 , & V_40 ) ;
if ( V_16 )
return V_16 ;
V_71 . V_40 = V_40 ;
if ( ! V_80 )
V_16 = F_13 ( V_19 , & V_71 ) ;
else
V_16 = F_14 ( V_19 , & V_71 ) ;
return V_16 ;
}
return 0 ;
}
void F_19 ( struct V_2 * V_3 )
{
struct V_14 * V_91 = F_3 ( V_3 ) ;
bool V_92 = F_20 ( V_3 -> V_19 -> V_93 ) ;
V_91 -> V_94 ( V_91 ) ;
if ( V_91 -> V_95 )
V_91 -> V_95 ( V_91 , V_3 -> V_96 ) ;
if ( V_91 -> V_97 )
V_91 -> V_97 ( V_91 , V_3 -> V_98 ) ;
if ( V_91 -> V_99 )
V_91 -> V_99 ( V_91 , 1 ) ;
if ( V_91 -> V_100 ) {
if ( V_3 -> V_88 == V_89 )
V_91 -> V_100 ( V_91 , ! V_92 , ! V_92 ) ;
else
V_91 -> V_100 ( V_91 , 0 , 1 ) ;
}
}
int F_21 ( struct V_2 * V_3 , T_1 V_101 )
{
struct V_14 * V_91 = F_3 ( V_3 ) ;
T_1 V_102 = V_3 -> V_19 -> V_102 ;
T_1 V_103 = V_101 + V_104 + V_105 + V_106 ;
T_1 V_96 = F_20 ( V_3 -> V_19 -> V_93 ) ?
V_107 : V_108 ;
if ( V_3 -> V_88 == V_89 )
V_96 = V_109 ;
if ( ( V_101 < V_110 ) || ( V_103 > V_96 ) ||
( V_103 > V_111 * V_102 ) )
return - V_48 ;
if ( ! V_91 -> V_95 )
return - V_112 ;
if ( V_103 < ( V_113 + V_105 + V_106 ) )
V_103 = ( V_113 + V_105 + V_106 ) ;
V_91 -> V_95 ( V_91 , V_103 ) ;
V_3 -> V_96 = V_103 ;
return 0 ;
}
void F_22 ( struct V_2 * V_3 )
{
struct V_14 * V_114 = F_3 ( V_3 ) ;
if ( V_114 -> V_115 == V_116 ) {
V_114 -> V_117 += 1 ;
return;
}
if ( V_114 -> V_118 ) {
V_114 -> V_118 ( V_3 -> V_30 . V_31 , V_119 ) ;
V_114 -> V_115 = V_116 ;
}
}
void F_23 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_15 -> V_117 > 0 ) {
V_15 -> V_117 -= 1 ;
if ( V_15 -> V_117 > 0 )
return;
}
if ( V_15 -> V_120 )
V_15 -> V_120 ( V_3 -> V_30 . V_31 ,
V_119 ) ;
V_15 -> V_115 = 0 ;
V_3 -> V_22 = 0 ;
V_3 -> V_19 -> V_20 -> V_121 ( V_3 ) ;
}
void F_24 ( struct V_2 * V_3 , T_1 * V_23 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_15 -> V_122 )
V_15 -> V_122 ( V_15 , V_23 ) ;
else
* V_23 = 0 ;
}
void F_25 ( struct V_2 * V_3 , T_1 * V_123 , T_1 * V_124 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_15 -> V_125 ) {
V_15 -> V_125 ( V_15 , V_123 , V_124 ) ;
} else {
* V_123 = 0 ;
* V_124 = 0 ;
}
}
int F_26 ( struct V_2 * V_3 , T_2 V_80 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_3 -> V_7 == V_126 && V_80 ) {
F_6 ( V_3 -> V_35 , L_7 ) ;
return - V_127 ;
}
if ( V_15 -> V_99 )
V_15 -> V_99 ( V_15 , V_80 ) ;
return 0 ;
}
int F_27 ( struct V_2 * V_3 , T_1 V_123 , T_1 V_124 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
bool V_92 = F_20 ( V_3 -> V_19 -> V_93 ) ;
if ( V_3 -> V_88 == V_89 ) {
if ( V_92 && ( V_124 || V_123 ) ) {
F_6 ( V_3 -> V_35 , L_8 ) ;
return - V_48 ;
}
}
if ( V_15 -> V_100 )
V_15 -> V_100 ( V_15 , V_123 , V_124 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
int V_16 ;
struct V_84 V_85 ;
struct V_14 * V_91 ;
F_29 ( V_3 ) ;
memset ( & V_85 , 0 , sizeof( struct V_84 ) ) ;
F_16 ( & V_85 , V_3 ) ;
if ( F_30 ( V_85 . V_1 ) < V_10 )
V_91 = (struct V_14 * ) F_31 ( V_3 , & V_85 ) ;
else
V_91 = (struct V_14 * ) F_32 ( V_3 , & V_85 ) ;
if ( ! V_91 )
return - V_128 ;
V_3 -> V_30 . V_31 = ( void * ) V_91 ;
F_19 ( V_3 ) ;
F_5 ( V_3 , V_3 -> V_24 , ! V_3 -> V_32 ) ;
V_16 = F_17 ( V_3 , V_3 -> V_38 , 0 , true ) ;
if ( V_16 )
goto V_129;
return 0 ;
V_129:
V_91 -> V_130 ( V_3 -> V_30 . V_31 ) ;
V_3 -> V_30 . V_31 = NULL ;
return V_16 ;
}
static int
F_33 ( struct V_131 * V_35 , struct V_132 * V_133 )
{
T_1 V_68 ;
int V_16 ;
V_16 = F_34 ( V_133 , L_9 , & V_68 ) ;
if ( V_16 ) {
F_6 ( V_35 , L_10 , V_16 ) ;
return V_16 ;
}
if ( V_68 >= V_134 ) {
F_6 ( V_35 , L_11 , V_68 ) ;
return - V_48 ;
}
return V_68 ;
}
static int
F_35 ( struct V_135 * V_136 , struct V_2 * V_3 ,
T_1 V_68 )
{
struct V_137 * V_138 ;
const char * V_139 ;
bool V_140 ;
int V_141 ;
V_141 = F_36 ( V_3 -> V_142 ,
L_12 , & V_139 ) ;
if ( V_141 < 0 )
return V_141 ;
if ( ! strcmp ( V_139 , F_37 ( V_126 ) ) )
V_140 = 1 ;
else if ( ! strcmp ( V_139 , F_37 ( V_143 ) ) )
V_140 = 0 ;
else
return - V_144 ;
V_138 = F_38 ( V_136 , V_68 , V_140 ) ;
if ( ! V_138 || F_39 ( V_138 ) )
return - V_145 ;
V_138 -> V_146 = V_136 -> V_146 [ V_68 ] ;
V_141 = F_40 ( V_138 ) ;
if ( V_141 ) {
F_41 ( V_138 ) ;
return - V_29 ;
}
V_3 -> V_147 = V_138 ;
F_42 ( & V_136 -> V_35 , L_13 , V_68 ) ;
return 0 ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_148 args ;
struct V_149 * V_150 ;
struct V_135 * V_135 ;
int V_141 ;
int V_68 ;
if ( ! F_44 ( V_3 -> V_142 ) )
return;
V_141 = F_45 (
V_3 -> V_142 , L_14 , 0 , & args ) ;
if ( V_141 )
return;
V_68 = F_33 ( V_3 -> V_35 , V_3 -> V_142 ) ;
if ( V_68 < 0 )
return;
V_150 = F_46 ( F_47 ( args . V_151 ) ) ;
V_135 = F_48 ( V_150 ) ;
V_141 = F_35 ( V_135 , V_3 , V_68 ) ;
if ( ! V_141 )
F_42 ( V_3 -> V_35 , L_15 ,
V_3 -> V_38 , V_68 ) ;
}
static int F_49 ( struct V_2 * V_3 )
{
struct V_152 * V_153 ;
struct V_154 * V_155 ;
struct V_156 V_157 ;
const char * V_158 ;
T_1 V_159 ;
T_1 V_16 ;
V_3 -> V_22 = false ;
V_3 -> V_32 = false ;
V_3 -> V_158 = V_160 ;
V_3 -> V_24 = V_161 [ V_3 -> V_7 ] ;
V_3 -> V_4 = V_3 -> V_24 ;
if ( V_3 -> V_7 == V_143 ) {
V_3 -> V_162 = V_163 ;
V_3 -> V_162 |= V_164 ;
} else if ( V_3 -> V_7 == V_126 ) {
V_3 -> V_162 = V_165 ;
V_3 -> V_162 |= V_166 ;
}
V_3 -> V_96 = V_167 ;
V_3 -> V_98 = V_168 ;
V_3 -> V_169 = V_3 -> V_38 ;
V_3 -> V_170 = 0 ;
if ( ! V_3 -> V_142 ) {
V_153 = F_50 ( V_3 -> V_35 -> V_171 , L_16 ,
V_3 -> V_38 ) ;
V_3 -> V_147 = F_51 ( V_153 ) ;
if ( V_3 -> V_147 ) {
F_52 ( & V_3 -> V_147 -> V_136 . V_35 ) ;
F_42 ( V_3 -> V_35 , L_17 ,
V_3 -> V_38 , V_153 -> V_37 ) ;
}
F_53 ( V_153 ) ;
return 0 ;
}
if ( F_54 ( V_3 -> V_142 ) ) {
V_153 = F_50 ( F_55 ( V_3 -> V_142 ) ,
L_16 , 0 ) ;
V_3 -> V_147 = F_51 ( V_153 ) ;
if ( V_3 -> V_147 ) {
F_52 ( & V_3 -> V_147 -> V_136 . V_35 ) ;
F_42 ( V_3 -> V_35 , L_17 ,
V_3 -> V_38 , V_153 -> V_37 ) ;
}
F_53 ( V_153 ) ;
V_153 = F_50 ( F_55 ( V_3 -> V_142 ) ,
L_18 , 0 ) ;
V_155 = F_56 ( V_153 ) ;
F_53 ( V_153 ) ;
if ( F_57 ( V_155 ) ) {
F_6 ( V_3 -> V_35 , L_19 ) ;
return - V_48 ;
}
V_3 -> V_172 = V_155 ;
V_16 = F_34 ( V_3 -> V_142 ,
L_20 ,
& V_3 -> V_169 ) ;
if ( V_16 ) {
F_42 ( V_3 -> V_35 ,
L_21 ,
V_3 -> V_38 ) ;
}
V_16 = F_34 ( V_3 -> V_142 ,
L_22 ,
& V_3 -> V_170 ) ;
if ( V_16 ) {
F_42 ( V_3 -> V_35 ,
L_23 ,
V_3 -> V_38 ) ;
}
V_16 = F_58 (
F_55 ( V_3 -> V_142 ) , L_24 , 1 , 0 ,
& V_157 ) ;
if ( V_16 ) {
F_42 ( V_3 -> V_35 , L_25 ,
V_3 -> V_38 ) ;
V_3 -> V_173 = NULL ;
} else {
V_155 = F_56 ( V_157 . V_153 ) ;
if ( F_57 ( V_155 ) ) {
F_42 ( V_3 -> V_35 , L_26 ) ;
V_3 -> V_173 = NULL ;
} else {
V_3 -> V_173 = V_155 ;
V_3 -> V_174 = V_157 . args [ 0 ] ;
}
}
} else if ( F_59 ( V_3 -> V_142 ) ) {
F_43 ( V_3 ) ;
} else {
F_6 ( V_3 -> V_35 , L_27 ,
V_3 -> V_38 ) ;
}
if ( ! F_36 ( V_3 -> V_142 , L_28 ,
& V_158 ) ) {
for ( V_159 = 0 ; V_159 < F_60 ( V_175 ) ; V_159 ++ ) {
if ( ! strncmp ( V_175 [ V_159 ] . V_37 , V_158 ,
V_176 ) ) {
V_3 -> V_158 = V_175 [ V_159 ] . V_177 ;
break;
}
}
}
return 0 ;
}
static int F_61 ( T_4 V_7 )
{
switch ( V_7 ) {
case V_143 :
return V_178 ;
case V_126 :
return V_179 ;
default:
return - V_48 ;
}
}
T_2 T_5 * F_62 ( struct V_69 * V_19 ,
struct V_2 * V_3 , T_1 V_180 )
{
T_2 T_5 * V_181 = V_19 -> V_182 ;
int V_38 = V_3 -> V_38 ;
if ( V_3 -> V_88 == V_183 )
return V_181 + 0x40000 + V_38 * 0x4000 -
V_180 * 0x20000 ;
else
return V_19 -> V_184 + 0x1000 ;
}
int F_63 ( struct V_69 * V_19 , struct V_2 * V_3 )
{
int V_16 ;
T_1 V_180 ;
V_3 -> V_19 = V_19 ;
V_3 -> V_35 = V_19 -> V_35 ;
V_3 -> V_185 = V_19 -> V_186 ;
V_3 -> V_187 = V_19 -> V_188 ;
V_3 -> V_17 = 0 ;
V_3 -> V_189 = 0 ;
V_3 -> V_190 = 0 ;
if ( ! F_9 ( V_19 ) )
V_3 -> V_88 = V_183 ;
else
V_3 -> V_88 = V_89 ;
V_3 -> V_7 = V_19 -> V_20 -> V_191 ( V_3 ) ;
V_16 = F_61 ( V_3 -> V_7 ) ;
if ( V_16 < 0 ) {
F_6 ( V_19 -> V_35 ,
L_29 ,
V_3 -> V_38 , V_16 ) ;
return V_16 ;
}
V_180 = ( T_1 ) V_16 ;
V_16 = F_49 ( V_3 ) ;
if ( V_16 )
return V_16 ;
V_3 -> V_19 -> V_20 -> V_121 ( V_3 ) ;
V_3 -> V_86 = F_62 ( V_19 , V_3 , V_180 ) ;
return 0 ;
}
static int F_64 ( struct V_69 * V_19 )
{
if ( F_9 ( V_19 ) )
return 1 ;
else
return V_47 ;
}
int F_65 ( struct V_69 * V_19 )
{
bool V_192 = false ;
int V_16 ;
T_1 V_193 ;
int V_194 = F_64 ( V_19 ) ;
struct V_2 * V_3 ;
struct V_132 * V_195 ;
F_66 (dsaf_dev->dev, child) {
V_16 = F_34 ( V_195 , L_30 , & V_193 ) ;
if ( V_16 ) {
F_6 ( V_19 -> V_35 ,
L_31 , V_16 ) ;
return V_16 ;
}
if ( V_193 >= V_194 ) {
F_6 ( V_19 -> V_35 ,
L_32 , V_193 ) ;
return - V_48 ;
}
V_3 = F_67 ( V_19 -> V_35 , sizeof( * V_3 ) ,
V_196 ) ;
if ( ! V_3 )
return - V_128 ;
V_3 -> V_142 = V_195 ;
V_3 -> V_38 = ( T_2 ) V_193 ;
V_19 -> V_3 [ V_193 ] = V_3 ;
V_192 = true ;
}
if ( ! V_192 ) {
for ( V_193 = 0 ; V_193 < V_194 ; V_193 ++ ) {
V_3 = F_67 ( V_19 -> V_35 , sizeof( * V_3 ) ,
V_196 ) ;
if ( ! V_3 )
return - V_128 ;
V_3 -> V_38 = V_193 ;
V_19 -> V_3 [ V_193 ] = V_3 ;
}
}
for ( V_193 = 0 ; V_193 < V_194 ; V_193 ++ ) {
V_3 = V_19 -> V_3 [ V_193 ] ;
if ( ! V_3 )
continue;
V_16 = F_63 ( V_19 , V_3 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_28 ( V_3 ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
void F_68 ( struct V_69 * V_19 )
{
int V_159 ;
int V_194 = F_64 ( V_19 ) ;
for ( V_159 = 0 ; V_159 < V_194 ; V_159 ++ ) {
V_19 -> V_20 -> V_121 ( V_19 -> V_3 [ V_159 ] ) ;
V_19 -> V_3 [ V_159 ] = NULL ;
}
}
int F_69 ( struct V_2 * V_3 ,
enum V_197 V_198 , int V_199 )
{
int V_16 ;
struct V_14 * V_91 = F_3 ( V_3 ) ;
if ( V_91 -> V_200 )
V_16 = V_91 -> V_200 ( V_91 , V_198 , V_199 ) ;
else
V_16 = - V_127 ;
return V_16 ;
}
void F_70 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
V_15 -> V_201 ( V_15 ) ;
}
void F_71 ( struct V_2 * V_3 , T_6 * V_202 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
V_15 -> V_203 ( V_15 , V_202 ) ;
}
void F_72 ( struct V_2 * V_3 ,
int V_204 , T_2 * V_202 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
V_15 -> V_205 ( V_204 , V_202 ) ;
}
int F_73 ( struct V_2 * V_3 , int V_204 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
return V_15 -> V_206 ( V_204 ) ;
}
void F_74 ( struct V_2 * V_3 , T_2 V_199 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_15 -> V_207 )
V_15 -> V_207 ( V_15 , V_199 ) ;
}
int F_75 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
return V_15 -> V_208 () ;
}
void F_76 ( struct V_2 * V_3 , void * V_202 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
V_15 -> V_209 ( V_15 , V_202 ) ;
}
void F_77 ( struct V_2 * V_3 )
{
int V_210 = 0 ;
int V_211 , V_212 ;
V_211 = V_3 -> V_189 - V_3 -> V_213 . V_214 ;
V_212 = V_3 -> V_190 - V_3 -> V_213 . V_215 ;
if ( V_211 || V_212 )
V_210 = 1 ;
else
V_210 = 0 ;
V_3 -> V_189 = V_3 -> V_213 . V_214 ;
V_3 -> V_190 = V_3 -> V_213 . V_215 ;
V_3 -> V_19 -> V_20 -> V_216 ( V_3 , ( int ) V_3 -> V_22 ,
V_3 -> V_24 , V_210 ) ;
}
int F_78 ( struct V_2 * V_3 ,
enum V_217 V_218 )
{
if ( ! V_3 || ! V_3 -> V_173 )
return 0 ;
return V_3 -> V_19 -> V_20 -> V_219 ( V_3 , V_218 ) ;
}
