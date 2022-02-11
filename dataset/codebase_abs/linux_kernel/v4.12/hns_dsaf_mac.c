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
if ( V_3 -> V_19 == V_20 ) {
V_16 = V_3 -> V_21 -> V_22 -> V_23 ( V_3 ,
& V_17 ) ;
if ( ! V_16 )
* V_13 = * V_13 && V_17 ;
}
V_3 -> V_24 = * V_13 ;
}
int F_4 ( struct V_2 * V_3 ,
T_2 * V_25 , T_3 * V_26 , T_2 * V_27 )
{
struct V_14 * V_15 ;
struct V_28 V_29 ;
V_15 = F_3 ( V_3 ) ;
if ( ! V_15 -> V_30 )
return - V_31 ;
V_15 -> V_30 ( V_15 , & V_29 ) ;
if ( V_25 )
* V_25 = V_29 . V_25 ;
if ( V_26 )
* V_26 = V_29 . V_26 ;
if ( V_27 )
* V_27 = V_29 . V_27 ;
return 0 ;
}
void F_5 ( struct V_2 * V_3 , int V_26 , int V_27 )
{
int V_16 ;
struct V_14 * V_15 ;
V_15 = (struct V_14 * ) ( V_3 -> V_32 . V_33 ) ;
V_3 -> V_26 = V_26 ;
V_3 -> V_34 = ! V_27 ;
if ( V_15 -> V_35 ) {
V_16 = V_15 -> V_35 ( V_15 ,
(enum V_36 ) V_26 , V_27 ) ;
if ( V_16 ) {
F_6 ( V_3 -> V_37 ,
L_1 ,
V_3 -> V_21 -> V_38 . V_39 ,
V_3 -> V_40 , V_16 ) ;
return;
}
}
}
int F_7 ( struct V_2 * V_3 , T_2 V_41 , T_2 * V_42 )
{
int V_43 , V_44 ;
int V_45 ;
T_2 V_46 ;
if ( V_3 -> V_21 -> V_47 <= V_48 ) {
if ( V_3 -> V_40 != V_49 ) {
F_6 ( V_3 -> V_37 ,
L_2 ,
V_3 -> V_21 -> V_38 . V_39 ,
V_3 -> V_40 , V_41 ) ;
return - V_50 ;
}
} else if ( V_3 -> V_21 -> V_47 < V_51 ) {
if ( V_3 -> V_40 >= V_49 ) {
F_6 ( V_3 -> V_37 ,
L_3 ,
V_3 -> V_21 -> V_38 . V_39 ,
V_3 -> V_40 , V_41 ) ;
return - V_50 ;
}
} else {
F_6 ( V_3 -> V_37 , L_4 ,
V_3 -> V_21 -> V_38 . V_39 , V_3 -> V_40 ) ;
return - V_50 ;
}
if ( V_41 >= V_3 -> V_21 -> V_52 [ 0 ] -> V_53 ) {
F_6 ( V_3 -> V_37 , L_2 ,
V_3 -> V_21 -> V_38 . V_39 , V_3 -> V_40 , V_41 ) ;
return - V_50 ;
}
V_43 = V_3 -> V_21 -> V_52 [ 0 ] -> V_54 ;
V_44 = V_3 -> V_21 -> V_52 [ 0 ] -> V_53 ;
V_45 = V_41 * V_43 +
V_44 * V_43 * V_3 -> V_40 ;
switch ( V_3 -> V_21 -> V_47 ) {
case V_55 :
V_46 = 0 ;
break;
case V_56 :
V_46 = 0 ;
break;
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
case V_67 :
case V_68 :
V_46 = V_45 ;
break;
default:
F_6 ( V_3 -> V_37 , L_4 ,
V_3 -> V_21 -> V_38 . V_39 , V_3 -> V_40 ) ;
return - V_50 ;
}
V_46 += V_69 ;
* V_42 = V_46 ;
return 0 ;
}
int F_8 ( struct V_2 * V_3 ,
T_1 V_41 , char * V_70 )
{
int V_16 ;
struct V_14 * V_15 = F_3 ( V_3 ) ;
struct V_71 * V_21 = V_3 -> V_21 ;
struct V_72 V_73 ;
struct V_74 * V_75 ;
V_75 = & V_3 -> V_76 [ V_41 ] ;
if ( ! F_9 ( V_21 ) ) {
memcpy ( V_73 . V_70 , V_70 , sizeof( V_73 . V_70 ) ) ;
V_73 . V_77 = V_75 -> V_78 ;
V_73 . V_79 = V_3 -> V_40 ;
V_16 = F_7 ( V_3 , ( T_2 ) V_41 ,
& V_73 . V_42 ) ;
if ( V_16 )
return V_16 ;
if ( ( V_75 -> V_80 != 0 ) &&
( memcmp ( V_75 -> V_70 ,
V_70 , sizeof( V_73 . V_70 ) ) != 0 ) ) {
V_16 = F_10 ( V_21 ,
V_75 -> V_78 ,
V_3 -> V_40 ,
V_75 -> V_70 ) ;
if ( V_16 )
return V_16 ;
}
V_16 = F_11 ( V_21 , & V_73 ) ;
if ( V_16 )
return V_16 ;
}
if ( ( V_15 -> V_81 ) && ( V_41 == 0 ) )
V_15 -> V_81 ( V_3 -> V_32 . V_33 , V_70 ) ;
memcpy ( V_75 -> V_70 , V_70 , sizeof( V_75 -> V_70 ) ) ;
V_75 -> V_80 = 1 ;
return 0 ;
}
int F_12 ( struct V_2 * V_3 , T_2 V_82 ,
const unsigned char * V_70 )
{
struct V_71 * V_21 = V_3 -> V_21 ;
struct V_72 V_73 ;
int V_16 ;
if ( F_9 ( V_21 ) )
return - V_83 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
memcpy ( V_73 . V_70 , V_70 , sizeof( V_73 . V_70 ) ) ;
V_73 . V_79 = V_3 -> V_40 ;
V_16 = F_7 ( V_3 , V_82 , & V_73 . V_42 ) ;
if ( V_16 )
return V_16 ;
return F_11 ( V_21 , & V_73 ) ;
}
int F_13 ( struct V_2 * V_3 , T_2 V_82 ,
const unsigned char * V_70 )
{
struct V_71 * V_21 = V_3 -> V_21 ;
struct V_72 V_73 ;
int V_16 ;
if ( F_9 ( V_21 ) )
return - V_83 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
memcpy ( V_73 . V_70 , V_70 , sizeof( V_73 . V_70 ) ) ;
V_73 . V_79 = V_3 -> V_40 ;
V_16 = F_7 ( V_3 , V_82 , & V_73 . V_42 ) ;
if ( V_16 )
return V_16 ;
return F_14 ( V_21 , & V_73 ) ;
}
int F_15 ( struct V_2 * V_3 ,
T_1 V_42 , char * V_70 , bool V_84 )
{
int V_16 ;
struct V_71 * V_21 = V_3 -> V_21 ;
struct V_72 V_73 ;
if ( ! F_9 ( V_21 ) && V_70 ) {
memcpy ( V_73 . V_70 , V_70 , sizeof( V_73 . V_70 ) ) ;
V_73 . V_77 = 0 ;
V_73 . V_79 = V_3 -> V_40 ;
V_73 . V_42 = V_42 ;
if ( ! V_84 )
V_16 = F_16 ( V_21 , & V_73 ) ;
else
V_16 = F_17 ( V_21 , & V_73 ) ;
if ( V_16 ) {
F_6 ( V_21 -> V_37 ,
L_5 ,
V_3 -> V_21 -> V_38 . V_39 ,
V_3 -> V_40 , V_16 ) ;
return V_16 ;
}
}
return 0 ;
}
int F_18 ( struct V_2 * V_3 , int V_85 )
{
struct V_71 * V_21 = V_3 -> V_21 ;
T_2 V_42 ;
int V_16 = F_7 ( V_3 , V_85 , & V_42 ) ;
if ( V_16 )
return V_16 ;
return F_19 ( V_21 , V_3 -> V_40 , V_42 ) ;
}
static void F_20 ( struct V_86 * V_87 ,
struct V_2 * V_3 )
{
V_87 -> V_88 = ( void * ) V_3 -> V_88 ;
V_87 -> V_1 = F_1 ( V_3 ) ;
F_21 ( V_87 -> V_70 , V_3 -> V_76 [ 0 ] . V_70 ) ;
V_87 -> V_40 = V_3 -> V_40 ;
V_87 -> V_37 = V_3 -> V_37 ;
}
static int F_22 ( struct V_2 * V_3 ,
T_1 V_42 , T_3 V_78 , bool V_84 )
{
int V_16 ;
struct V_71 * V_21 = V_3 -> V_21 ;
T_2 V_70 [ V_89 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_72 V_73 ;
if ( V_3 -> V_90 == V_91 )
return 0 ;
if ( ! F_9 ( V_21 ) ) {
memcpy ( V_73 . V_70 , V_70 , sizeof( V_73 . V_70 ) ) ;
V_73 . V_77 = V_78 ;
V_73 . V_79 = V_3 -> V_40 ;
V_73 . V_42 = V_42 ;
if ( ! V_84 )
V_16 = F_16 ( V_21 , & V_73 ) ;
else
V_16 = F_17 ( V_21 , & V_73 ) ;
return V_16 ;
}
return 0 ;
}
int F_23 ( struct V_2 * V_3 , T_1 V_41 , bool V_84 )
{
int V_16 ;
struct V_71 * V_21 = V_3 -> V_21 ;
T_2 V_42 ;
T_2 V_70 [ V_89 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_74 * V_92 ;
struct V_72 V_73 ;
if ( V_3 -> V_90 == V_91 )
return 0 ;
V_92 = & V_3 -> V_76 [ V_41 ] ;
if ( ! F_9 ( V_21 ) ) {
memcpy ( V_73 . V_70 , V_70 , sizeof( V_73 . V_70 ) ) ;
V_73 . V_77 = V_92 -> V_78 ;
V_73 . V_79 = V_3 -> V_40 ;
V_16 = F_7 ( V_3 , V_41 , & V_42 ) ;
if ( V_16 )
return V_16 ;
V_73 . V_42 = V_42 ;
if ( ! V_84 )
V_16 = F_16 ( V_21 , & V_73 ) ;
else
V_16 = F_17 ( V_21 , & V_73 ) ;
return V_16 ;
}
return 0 ;
}
void F_24 ( struct V_2 * V_3 )
{
struct V_14 * V_93 = F_3 ( V_3 ) ;
bool V_94 = F_25 ( V_3 -> V_21 -> V_95 ) ;
V_93 -> V_96 ( V_93 ) ;
if ( V_93 -> V_97 )
V_93 -> V_97 ( V_93 , V_3 -> V_98 ) ;
if ( V_93 -> V_99 )
V_93 -> V_99 ( V_93 , V_3 -> V_100 ) ;
if ( V_93 -> V_101 )
V_93 -> V_101 ( V_93 , 1 ) ;
if ( V_93 -> V_102 ) {
if ( V_3 -> V_90 == V_91 )
V_93 -> V_102 ( V_93 , ! V_94 , ! V_94 ) ;
else
V_93 -> V_102 ( V_93 , 0 , 1 ) ;
}
}
int F_26 ( struct V_2 * V_3 , T_1 V_103 , T_1 V_104 )
{
struct V_14 * V_93 = F_3 ( V_3 ) ;
T_1 V_105 = V_103 + V_106 + V_107 + V_108 ;
T_1 V_98 = F_25 ( V_3 -> V_21 -> V_95 ) ?
V_109 : V_110 ;
if ( V_3 -> V_90 == V_91 )
V_98 = V_111 ;
if ( V_105 > V_112 * V_104 )
return - V_50 ;
if ( ! V_93 -> V_97 )
return - V_113 ;
if ( V_105 < ( V_114 + V_107 + V_108 ) )
V_105 = ( V_114 + V_107 + V_108 ) ;
V_93 -> V_97 ( V_93 , V_105 ) ;
V_3 -> V_98 = V_105 ;
return 0 ;
}
void F_27 ( struct V_2 * V_3 )
{
struct V_14 * V_115 = F_3 ( V_3 ) ;
if ( V_115 -> V_116 == V_117 ) {
V_115 -> V_118 += 1 ;
return;
}
if ( V_115 -> V_119 ) {
V_115 -> V_119 ( V_3 -> V_32 . V_33 , V_120 ) ;
V_115 -> V_116 = V_117 ;
}
}
void F_28 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_15 -> V_118 > 0 ) {
V_15 -> V_118 -= 1 ;
if ( V_15 -> V_118 > 0 )
return;
}
if ( V_15 -> V_121 )
V_15 -> V_121 ( V_3 -> V_32 . V_33 ,
V_120 ) ;
V_15 -> V_116 = 0 ;
V_3 -> V_24 = 0 ;
V_3 -> V_21 -> V_22 -> V_122 ( V_3 ) ;
}
void F_29 ( struct V_2 * V_3 , T_1 * V_25 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_15 -> V_123 )
V_15 -> V_123 ( V_15 , V_25 ) ;
else
* V_25 = 0 ;
}
void F_30 ( struct V_2 * V_3 , T_1 * V_124 , T_1 * V_125 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_15 -> V_126 ) {
V_15 -> V_126 ( V_15 , V_124 , V_125 ) ;
} else {
* V_124 = 0 ;
* V_125 = 0 ;
}
}
int F_31 ( struct V_2 * V_3 , T_2 V_84 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_3 -> V_7 == V_127 && V_84 ) {
F_6 ( V_3 -> V_37 , L_6 ) ;
return - V_128 ;
}
if ( V_15 -> V_101 )
V_15 -> V_101 ( V_15 , V_84 ) ;
return 0 ;
}
int F_32 ( struct V_2 * V_3 , T_1 V_124 , T_1 V_125 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
bool V_94 = F_25 ( V_3 -> V_21 -> V_95 ) ;
if ( V_3 -> V_90 == V_91 ) {
if ( V_94 && ( V_125 || V_124 ) ) {
F_6 ( V_3 -> V_37 , L_7 ) ;
return - V_50 ;
}
}
if ( V_15 -> V_102 )
V_15 -> V_102 ( V_15 , V_124 , V_125 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 )
{
int V_16 ;
struct V_86 V_87 ;
struct V_14 * V_93 ;
F_34 ( V_3 ) ;
memset ( & V_87 , 0 , sizeof( struct V_86 ) ) ;
F_20 ( & V_87 , V_3 ) ;
if ( F_35 ( V_87 . V_1 ) < V_10 )
V_93 = (struct V_14 * ) F_36 ( V_3 , & V_87 ) ;
else
V_93 = (struct V_14 * ) F_37 ( V_3 , & V_87 ) ;
if ( ! V_93 )
return - V_129 ;
V_3 -> V_32 . V_33 = ( void * ) V_93 ;
F_24 ( V_3 ) ;
F_5 ( V_3 , V_3 -> V_26 , ! V_3 -> V_34 ) ;
V_16 = F_22 ( V_3 , V_3 -> V_40 , 0 , true ) ;
if ( V_16 )
goto V_130;
return 0 ;
V_130:
V_93 -> V_131 ( V_3 -> V_32 . V_33 ) ;
V_3 -> V_32 . V_33 = NULL ;
return V_16 ;
}
static int
F_38 ( struct V_132 * V_37 , struct V_133 * V_134 )
{
T_1 V_70 ;
int V_16 ;
V_16 = F_39 ( V_134 , L_8 , & V_70 ) ;
if ( V_16 ) {
F_6 ( V_37 , L_9 , V_16 ) ;
return V_16 ;
}
if ( V_70 >= V_135 ) {
F_6 ( V_37 , L_10 , V_70 ) ;
return - V_50 ;
}
return V_70 ;
}
static int
F_40 ( struct V_136 * V_137 , struct V_2 * V_3 ,
T_1 V_70 )
{
struct V_138 * V_139 ;
const char * V_140 ;
bool V_141 ;
int V_142 ;
V_142 = F_41 ( V_3 -> V_143 ,
L_11 , & V_140 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( ! strcmp ( V_140 , F_42 ( V_127 ) ) )
V_141 = 1 ;
else if ( ! strcmp ( V_140 , F_42 ( V_144 ) ) )
V_141 = 0 ;
else
return - V_145 ;
V_139 = F_43 ( V_137 , V_70 , V_141 ) ;
if ( ! V_139 || F_44 ( V_139 ) )
return - V_146 ;
V_139 -> V_147 = V_137 -> V_147 [ V_70 ] ;
V_142 = F_45 ( V_139 ) ;
if ( V_142 ) {
F_46 ( V_139 ) ;
F_6 ( & V_137 -> V_37 , L_12 ,
V_70 ) ;
return - V_31 ;
}
V_3 -> V_148 = V_139 ;
F_47 ( & V_137 -> V_37 , L_13 , V_70 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_149 args ;
struct V_150 * V_151 ;
struct V_136 * V_136 ;
int V_142 ;
int V_70 ;
if ( ! F_49 ( V_3 -> V_143 ) )
return - V_31 ;
V_142 = F_50 (
V_3 -> V_143 , L_14 , 0 , & args ) ;
if ( V_142 )
return V_142 ;
V_70 = F_38 ( V_3 -> V_37 , V_3 -> V_143 ) ;
if ( V_70 < 0 )
return V_70 ;
V_151 = F_51 ( F_52 ( args . V_152 ) ) ;
if ( ! V_151 ) {
F_6 ( V_3 -> V_37 , L_15 ,
V_3 -> V_40 ) ;
return - V_50 ;
}
V_136 = F_53 ( V_151 ) ;
if ( ! V_136 ) {
F_6 ( V_3 -> V_37 ,
L_16 ,
V_3 -> V_40 ) ;
return - V_153 ;
}
V_142 = F_40 ( V_136 , V_3 , V_70 ) ;
if ( ! V_142 )
F_47 ( V_3 -> V_37 , L_17 ,
V_3 -> V_40 , V_70 ) ;
return V_142 ;
}
static int F_54 ( struct V_2 * V_3 )
{
struct V_154 * V_155 ;
struct V_156 * V_157 ;
struct V_158 V_159 ;
const char * V_19 ;
T_1 V_160 ;
T_1 V_16 ;
V_3 -> V_24 = false ;
V_3 -> V_34 = false ;
V_3 -> V_19 = V_161 ;
V_3 -> V_26 = V_162 [ V_3 -> V_7 ] ;
V_3 -> V_4 = V_3 -> V_26 ;
if ( V_3 -> V_7 == V_144 ) {
V_3 -> V_163 = V_164 ;
V_3 -> V_163 |= V_165 ;
} else if ( V_3 -> V_7 == V_127 ) {
V_3 -> V_163 = V_166 ;
V_3 -> V_163 |= V_167 ;
}
V_3 -> V_98 = V_168 ;
V_3 -> V_100 = V_169 ;
V_3 -> V_170 = V_3 -> V_40 ;
V_3 -> V_171 = 0 ;
if ( ! V_3 -> V_143 ) {
V_155 = F_55 ( V_3 -> V_37 -> V_172 , L_18 ,
V_3 -> V_40 ) ;
V_3 -> V_148 = F_56 ( V_155 ) ;
if ( V_3 -> V_148 ) {
F_57 ( & V_3 -> V_148 -> V_137 . V_37 ) ;
F_47 ( V_3 -> V_37 , L_19 ,
V_3 -> V_40 , V_155 -> V_39 ) ;
}
F_58 ( V_155 ) ;
return 0 ;
}
if ( F_59 ( V_3 -> V_143 ) ) {
V_155 = F_55 ( F_60 ( V_3 -> V_143 ) ,
L_18 , 0 ) ;
V_3 -> V_148 = F_56 ( V_155 ) ;
if ( V_3 -> V_148 ) {
F_57 ( & V_3 -> V_148 -> V_137 . V_37 ) ;
F_47 ( V_3 -> V_37 , L_19 ,
V_3 -> V_40 , V_155 -> V_39 ) ;
}
F_58 ( V_155 ) ;
V_155 = F_55 ( F_60 ( V_3 -> V_143 ) ,
L_20 , 0 ) ;
V_157 = F_61 ( V_155 ) ;
F_58 ( V_155 ) ;
if ( F_62 ( V_157 ) ) {
F_6 ( V_3 -> V_37 , L_21 ) ;
return - V_50 ;
}
V_3 -> V_173 = V_157 ;
V_16 = F_39 ( V_3 -> V_143 ,
L_22 ,
& V_3 -> V_170 ) ;
if ( V_16 ) {
F_47 ( V_3 -> V_37 ,
L_23 ,
V_3 -> V_40 ) ;
}
V_16 = F_39 ( V_3 -> V_143 ,
L_24 ,
& V_3 -> V_171 ) ;
if ( V_16 ) {
F_47 ( V_3 -> V_37 ,
L_25 ,
V_3 -> V_40 ) ;
}
V_16 = F_63 (
F_60 ( V_3 -> V_143 ) , L_26 , 1 , 0 ,
& V_159 ) ;
if ( V_16 ) {
F_47 ( V_3 -> V_37 , L_27 ,
V_3 -> V_40 ) ;
V_3 -> V_174 = NULL ;
} else {
V_157 = F_61 ( V_159 . V_155 ) ;
if ( F_62 ( V_157 ) ) {
F_47 ( V_3 -> V_37 , L_28 ) ;
V_3 -> V_174 = NULL ;
} else {
V_3 -> V_174 = V_157 ;
V_3 -> V_175 = V_159 . args [ 0 ] ;
}
}
} else if ( F_64 ( V_3 -> V_143 ) ) {
V_16 = F_48 ( V_3 ) ;
if ( V_16 == - V_153 )
return V_16 ;
} else {
F_6 ( V_3 -> V_37 , L_29 ,
V_3 -> V_40 ) ;
}
if ( ! F_41 ( V_3 -> V_143 , L_30 ,
& V_19 ) ) {
for ( V_160 = 0 ; V_160 < F_65 ( V_176 ) ; V_160 ++ ) {
if ( ! strncmp ( V_176 [ V_160 ] . V_39 , V_19 ,
V_177 ) ) {
V_3 -> V_19 = V_176 [ V_160 ] . V_178 ;
break;
}
}
}
if ( F_66 ( V_3 -> V_143 , L_31 ,
V_3 -> V_179 , V_89 ) ) {
F_67 ( V_3 -> V_37 ,
L_32 ) ;
F_68 ( V_3 -> V_179 ) ;
}
return 0 ;
}
static int F_69 ( T_4 V_7 )
{
switch ( V_7 ) {
case V_144 :
return V_180 ;
case V_127 :
return V_181 ;
default:
return - V_50 ;
}
}
T_2 T_5 * F_70 ( struct V_71 * V_21 ,
struct V_2 * V_3 , T_1 V_182 )
{
T_2 T_5 * V_183 = V_21 -> V_184 ;
int V_40 = V_3 -> V_40 ;
if ( V_3 -> V_90 == V_185 )
return V_183 + 0x40000 + V_40 * 0x4000 -
V_182 * 0x20000 ;
else
return V_21 -> V_186 + 0x1000 ;
}
int F_71 ( struct V_71 * V_21 , struct V_2 * V_3 )
{
int V_16 ;
T_1 V_182 ;
V_3 -> V_21 = V_21 ;
V_3 -> V_37 = V_21 -> V_37 ;
V_3 -> V_187 = V_21 -> V_188 ;
V_3 -> V_189 = V_21 -> V_190 ;
V_3 -> V_17 = 0 ;
V_3 -> V_191 = 0 ;
V_3 -> V_192 = 0 ;
if ( ! F_9 ( V_21 ) )
V_3 -> V_90 = V_185 ;
else
V_3 -> V_90 = V_91 ;
V_3 -> V_7 = V_21 -> V_22 -> V_193 ( V_3 ) ;
V_16 = F_69 ( V_3 -> V_7 ) ;
if ( V_16 < 0 ) {
F_6 ( V_21 -> V_37 ,
L_33 ,
V_3 -> V_40 , V_16 ) ;
return V_16 ;
}
V_182 = ( T_1 ) V_16 ;
V_16 = F_54 ( V_3 ) ;
if ( V_16 )
return V_16 ;
V_3 -> V_21 -> V_22 -> V_122 ( V_3 ) ;
V_3 -> V_88 = F_70 ( V_21 , V_3 , V_182 ) ;
return 0 ;
}
static int F_72 ( struct V_71 * V_21 )
{
if ( F_9 ( V_21 ) )
return 1 ;
else
return V_49 ;
}
int F_73 ( struct V_71 * V_21 )
{
bool V_194 = false ;
int V_16 ;
T_1 V_195 ;
int V_196 = F_72 ( V_21 ) ;
struct V_2 * V_3 ;
struct V_133 * V_197 ;
F_74 (dsaf_dev->dev, child) {
V_16 = F_39 ( V_197 , L_34 , & V_195 ) ;
if ( V_16 ) {
F_6 ( V_21 -> V_37 ,
L_35 , V_16 ) ;
return V_16 ;
}
if ( V_195 >= V_196 ) {
F_6 ( V_21 -> V_37 ,
L_36 , V_195 ) ;
return - V_50 ;
}
V_3 = F_75 ( V_21 -> V_37 , sizeof( * V_3 ) ,
V_198 ) ;
if ( ! V_3 )
return - V_129 ;
V_3 -> V_143 = V_197 ;
V_3 -> V_40 = ( T_2 ) V_195 ;
V_21 -> V_3 [ V_195 ] = V_3 ;
V_194 = true ;
}
if ( ! V_194 ) {
for ( V_195 = 0 ; V_195 < V_196 ; V_195 ++ ) {
V_3 = F_75 ( V_21 -> V_37 , sizeof( * V_3 ) ,
V_198 ) ;
if ( ! V_3 )
return - V_129 ;
V_3 -> V_40 = V_195 ;
V_21 -> V_3 [ V_195 ] = V_3 ;
}
}
for ( V_195 = 0 ; V_195 < V_196 ; V_195 ++ ) {
V_3 = V_21 -> V_3 [ V_195 ] ;
if ( ! V_3 )
continue;
V_16 = F_71 ( V_21 , V_3 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_33 ( V_3 ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
void F_76 ( struct V_71 * V_21 )
{
int V_160 ;
int V_196 = F_72 ( V_21 ) ;
for ( V_160 = 0 ; V_160 < V_196 ; V_160 ++ ) {
V_21 -> V_22 -> V_122 ( V_21 -> V_3 [ V_160 ] ) ;
V_21 -> V_3 [ V_160 ] = NULL ;
}
}
int F_77 ( struct V_2 * V_3 ,
enum V_199 V_200 , int V_201 )
{
int V_16 ;
struct V_14 * V_93 = F_3 ( V_3 ) ;
if ( V_93 -> V_202 )
V_16 = V_93 -> V_202 ( V_93 , V_200 , V_201 ) ;
else
V_16 = - V_128 ;
return V_16 ;
}
void F_78 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
V_15 -> V_203 ( V_15 ) ;
}
void F_79 ( struct V_2 * V_3 , T_6 * V_204 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
V_15 -> V_205 ( V_15 , V_204 ) ;
}
void F_80 ( struct V_2 * V_3 ,
int V_206 , T_2 * V_204 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
V_15 -> V_207 ( V_206 , V_204 ) ;
}
int F_81 ( struct V_2 * V_3 , int V_206 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
return V_15 -> V_208 ( V_206 ) ;
}
void F_82 ( struct V_2 * V_3 , T_2 V_201 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
F_83 ( V_3 -> V_21 , V_3 -> V_40 , ! ! V_201 ) ;
if ( V_15 -> V_209 )
V_15 -> V_209 ( V_15 , V_201 ) ;
}
int F_84 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
return V_15 -> V_210 () ;
}
void F_85 ( struct V_2 * V_3 , void * V_204 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
V_15 -> V_211 ( V_15 , V_204 ) ;
}
void F_86 ( struct V_2 * V_3 )
{
int V_212 = 0 ;
int V_213 , V_214 ;
V_213 = V_3 -> V_191 - V_3 -> V_215 . V_216 ;
V_214 = V_3 -> V_192 - V_3 -> V_215 . V_217 ;
if ( V_213 || V_214 )
V_212 = 1 ;
else
V_212 = 0 ;
V_3 -> V_191 = V_3 -> V_215 . V_216 ;
V_3 -> V_192 = V_3 -> V_215 . V_217 ;
V_3 -> V_21 -> V_22 -> V_218 ( V_3 , ( int ) V_3 -> V_24 ,
V_3 -> V_26 , V_212 ) ;
}
int F_87 ( struct V_2 * V_3 ,
enum V_219 V_220 )
{
if ( ! V_3 || ! V_3 -> V_174 )
return 0 ;
return V_3 -> V_21 -> V_22 -> V_221 ( V_3 , V_220 ) ;
}
