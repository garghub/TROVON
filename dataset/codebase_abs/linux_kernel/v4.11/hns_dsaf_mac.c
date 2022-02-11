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
int F_18 ( struct V_2 * V_3 , T_1 V_85 , char * V_33 )
{
struct V_74 * V_86 ;
struct V_71 * V_21 ;
T_1 V_16 ;
V_21 = V_3 -> V_21 ;
if ( V_85 < V_87 ) {
V_86 = & V_3 -> V_76 [ V_85 ] ;
} else {
F_6 ( V_3 -> V_37 ,
L_6 ,
V_3 -> V_21 -> V_38 . V_39 , V_3 -> V_40 , V_85 ) ;
return - V_50 ;
}
if ( V_21 ) {
V_16 = F_10 ( V_21 , V_86 -> V_78 ,
V_3 -> V_40 , V_86 -> V_70 ) ;
if ( V_16 )
return V_16 ;
if ( memcmp ( V_86 -> V_70 , V_33 , sizeof( V_86 -> V_70 ) ) == 0 )
V_86 -> V_80 = 0 ;
}
return 0 ;
}
int F_19 ( struct V_2 * V_3 , int V_85 )
{
struct V_71 * V_21 = V_3 -> V_21 ;
T_2 V_42 ;
int V_16 = F_7 ( V_3 , V_85 , & V_42 ) ;
if ( V_16 )
return V_16 ;
return F_20 ( V_21 , V_3 -> V_40 , V_42 ) ;
}
static void F_21 ( struct V_88 * V_89 ,
struct V_2 * V_3 )
{
V_89 -> V_90 = ( void * ) V_3 -> V_90 ;
V_89 -> V_1 = F_1 ( V_3 ) ;
F_22 ( V_89 -> V_70 , V_3 -> V_76 [ 0 ] . V_70 ) ;
V_89 -> V_40 = V_3 -> V_40 ;
V_89 -> V_37 = V_3 -> V_37 ;
}
static int F_23 ( struct V_2 * V_3 ,
T_1 V_42 , T_3 V_78 , bool V_84 )
{
int V_16 ;
struct V_71 * V_21 = V_3 -> V_21 ;
T_2 V_70 [ V_91 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_72 V_73 ;
if ( V_3 -> V_92 == V_93 )
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
int F_24 ( struct V_2 * V_3 , T_1 V_41 , bool V_84 )
{
int V_16 ;
struct V_71 * V_21 = V_3 -> V_21 ;
T_2 V_42 ;
T_2 V_70 [ V_91 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_74 * V_94 ;
struct V_72 V_73 ;
if ( V_3 -> V_92 == V_93 )
return 0 ;
V_94 = & V_3 -> V_76 [ V_41 ] ;
if ( ! F_9 ( V_21 ) ) {
memcpy ( V_73 . V_70 , V_70 , sizeof( V_73 . V_70 ) ) ;
V_73 . V_77 = V_94 -> V_78 ;
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
void F_25 ( struct V_2 * V_3 )
{
struct V_14 * V_95 = F_3 ( V_3 ) ;
bool V_96 = F_26 ( V_3 -> V_21 -> V_97 ) ;
V_95 -> V_98 ( V_95 ) ;
if ( V_95 -> V_99 )
V_95 -> V_99 ( V_95 , V_3 -> V_100 ) ;
if ( V_95 -> V_101 )
V_95 -> V_101 ( V_95 , V_3 -> V_102 ) ;
if ( V_95 -> V_103 )
V_95 -> V_103 ( V_95 , 1 ) ;
if ( V_95 -> V_104 ) {
if ( V_3 -> V_92 == V_93 )
V_95 -> V_104 ( V_95 , ! V_96 , ! V_96 ) ;
else
V_95 -> V_104 ( V_95 , 0 , 1 ) ;
}
}
int F_27 ( struct V_2 * V_3 , T_1 V_105 )
{
struct V_14 * V_95 = F_3 ( V_3 ) ;
T_1 V_106 = V_3 -> V_21 -> V_106 ;
T_1 V_107 = V_105 + V_108 + V_109 + V_110 ;
T_1 V_100 = F_26 ( V_3 -> V_21 -> V_97 ) ?
V_111 : V_112 ;
if ( V_3 -> V_92 == V_93 )
V_100 = V_113 ;
if ( V_107 > V_114 * V_106 )
return - V_50 ;
if ( ! V_95 -> V_99 )
return - V_115 ;
if ( V_107 < ( V_116 + V_109 + V_110 ) )
V_107 = ( V_116 + V_109 + V_110 ) ;
V_95 -> V_99 ( V_95 , V_107 ) ;
V_3 -> V_100 = V_107 ;
return 0 ;
}
void F_28 ( struct V_2 * V_3 )
{
struct V_14 * V_117 = F_3 ( V_3 ) ;
if ( V_117 -> V_118 == V_119 ) {
V_117 -> V_120 += 1 ;
return;
}
if ( V_117 -> V_121 ) {
V_117 -> V_121 ( V_3 -> V_32 . V_33 , V_122 ) ;
V_117 -> V_118 = V_119 ;
}
}
void F_29 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_15 -> V_120 > 0 ) {
V_15 -> V_120 -= 1 ;
if ( V_15 -> V_120 > 0 )
return;
}
if ( V_15 -> V_123 )
V_15 -> V_123 ( V_3 -> V_32 . V_33 ,
V_122 ) ;
V_15 -> V_118 = 0 ;
V_3 -> V_24 = 0 ;
V_3 -> V_21 -> V_22 -> V_124 ( V_3 ) ;
}
void F_30 ( struct V_2 * V_3 , T_1 * V_25 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_15 -> V_125 )
V_15 -> V_125 ( V_15 , V_25 ) ;
else
* V_25 = 0 ;
}
void F_31 ( struct V_2 * V_3 , T_1 * V_126 , T_1 * V_127 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_15 -> V_128 ) {
V_15 -> V_128 ( V_15 , V_126 , V_127 ) ;
} else {
* V_126 = 0 ;
* V_127 = 0 ;
}
}
int F_32 ( struct V_2 * V_3 , T_2 V_84 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_3 -> V_7 == V_129 && V_84 ) {
F_6 ( V_3 -> V_37 , L_7 ) ;
return - V_130 ;
}
if ( V_15 -> V_103 )
V_15 -> V_103 ( V_15 , V_84 ) ;
return 0 ;
}
int F_33 ( struct V_2 * V_3 , T_1 V_126 , T_1 V_127 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
bool V_96 = F_26 ( V_3 -> V_21 -> V_97 ) ;
if ( V_3 -> V_92 == V_93 ) {
if ( V_96 && ( V_127 || V_126 ) ) {
F_6 ( V_3 -> V_37 , L_8 ) ;
return - V_50 ;
}
}
if ( V_15 -> V_104 )
V_15 -> V_104 ( V_15 , V_126 , V_127 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 )
{
int V_16 ;
struct V_88 V_89 ;
struct V_14 * V_95 ;
F_35 ( V_3 ) ;
memset ( & V_89 , 0 , sizeof( struct V_88 ) ) ;
F_21 ( & V_89 , V_3 ) ;
if ( F_36 ( V_89 . V_1 ) < V_10 )
V_95 = (struct V_14 * ) F_37 ( V_3 , & V_89 ) ;
else
V_95 = (struct V_14 * ) F_38 ( V_3 , & V_89 ) ;
if ( ! V_95 )
return - V_131 ;
V_3 -> V_32 . V_33 = ( void * ) V_95 ;
F_25 ( V_3 ) ;
F_5 ( V_3 , V_3 -> V_26 , ! V_3 -> V_34 ) ;
V_16 = F_23 ( V_3 , V_3 -> V_40 , 0 , true ) ;
if ( V_16 )
goto V_132;
return 0 ;
V_132:
V_95 -> V_133 ( V_3 -> V_32 . V_33 ) ;
V_3 -> V_32 . V_33 = NULL ;
return V_16 ;
}
static int
F_39 ( struct V_134 * V_37 , struct V_135 * V_136 )
{
T_1 V_70 ;
int V_16 ;
V_16 = F_40 ( V_136 , L_9 , & V_70 ) ;
if ( V_16 ) {
F_6 ( V_37 , L_10 , V_16 ) ;
return V_16 ;
}
if ( V_70 >= V_137 ) {
F_6 ( V_37 , L_11 , V_70 ) ;
return - V_50 ;
}
return V_70 ;
}
static int
F_41 ( struct V_138 * V_139 , struct V_2 * V_3 ,
T_1 V_70 )
{
struct V_140 * V_141 ;
const char * V_142 ;
bool V_143 ;
int V_144 ;
V_144 = F_42 ( V_3 -> V_145 ,
L_12 , & V_142 ) ;
if ( V_144 < 0 )
return V_144 ;
if ( ! strcmp ( V_142 , F_43 ( V_129 ) ) )
V_143 = 1 ;
else if ( ! strcmp ( V_142 , F_43 ( V_146 ) ) )
V_143 = 0 ;
else
return - V_147 ;
V_141 = F_44 ( V_139 , V_70 , V_143 ) ;
if ( ! V_141 || F_45 ( V_141 ) )
return - V_148 ;
V_141 -> V_149 = V_139 -> V_149 [ V_70 ] ;
V_144 = F_46 ( V_141 ) ;
if ( V_144 ) {
F_47 ( V_141 ) ;
return - V_31 ;
}
V_3 -> V_150 = V_141 ;
F_48 ( & V_139 -> V_37 , L_13 , V_70 ) ;
return 0 ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_151 args ;
struct V_152 * V_153 ;
struct V_138 * V_138 ;
int V_144 ;
int V_70 ;
if ( ! F_50 ( V_3 -> V_145 ) )
return;
V_144 = F_51 (
V_3 -> V_145 , L_14 , 0 , & args ) ;
if ( V_144 )
return;
V_70 = F_39 ( V_3 -> V_37 , V_3 -> V_145 ) ;
if ( V_70 < 0 )
return;
V_153 = F_52 ( F_53 ( args . V_154 ) ) ;
V_138 = F_54 ( V_153 ) ;
V_144 = F_41 ( V_138 , V_3 , V_70 ) ;
if ( ! V_144 )
F_48 ( V_3 -> V_37 , L_15 ,
V_3 -> V_40 , V_70 ) ;
}
static int F_55 ( struct V_2 * V_3 )
{
struct V_155 * V_156 ;
struct V_157 * V_158 ;
struct V_159 V_160 ;
const char * V_19 ;
T_1 V_161 ;
T_1 V_16 ;
V_3 -> V_24 = false ;
V_3 -> V_34 = false ;
V_3 -> V_19 = V_162 ;
V_3 -> V_26 = V_163 [ V_3 -> V_7 ] ;
V_3 -> V_4 = V_3 -> V_26 ;
if ( V_3 -> V_7 == V_146 ) {
V_3 -> V_164 = V_165 ;
V_3 -> V_164 |= V_166 ;
} else if ( V_3 -> V_7 == V_129 ) {
V_3 -> V_164 = V_167 ;
V_3 -> V_164 |= V_168 ;
}
V_3 -> V_100 = V_169 ;
V_3 -> V_102 = V_170 ;
V_3 -> V_171 = V_3 -> V_40 ;
V_3 -> V_172 = 0 ;
if ( ! V_3 -> V_145 ) {
V_156 = F_56 ( V_3 -> V_37 -> V_173 , L_16 ,
V_3 -> V_40 ) ;
V_3 -> V_150 = F_57 ( V_156 ) ;
if ( V_3 -> V_150 ) {
F_58 ( & V_3 -> V_150 -> V_139 . V_37 ) ;
F_48 ( V_3 -> V_37 , L_17 ,
V_3 -> V_40 , V_156 -> V_39 ) ;
}
F_59 ( V_156 ) ;
return 0 ;
}
if ( F_60 ( V_3 -> V_145 ) ) {
V_156 = F_56 ( F_61 ( V_3 -> V_145 ) ,
L_16 , 0 ) ;
V_3 -> V_150 = F_57 ( V_156 ) ;
if ( V_3 -> V_150 ) {
F_58 ( & V_3 -> V_150 -> V_139 . V_37 ) ;
F_48 ( V_3 -> V_37 , L_17 ,
V_3 -> V_40 , V_156 -> V_39 ) ;
}
F_59 ( V_156 ) ;
V_156 = F_56 ( F_61 ( V_3 -> V_145 ) ,
L_18 , 0 ) ;
V_158 = F_62 ( V_156 ) ;
F_59 ( V_156 ) ;
if ( F_63 ( V_158 ) ) {
F_6 ( V_3 -> V_37 , L_19 ) ;
return - V_50 ;
}
V_3 -> V_174 = V_158 ;
V_16 = F_40 ( V_3 -> V_145 ,
L_20 ,
& V_3 -> V_171 ) ;
if ( V_16 ) {
F_48 ( V_3 -> V_37 ,
L_21 ,
V_3 -> V_40 ) ;
}
V_16 = F_40 ( V_3 -> V_145 ,
L_22 ,
& V_3 -> V_172 ) ;
if ( V_16 ) {
F_48 ( V_3 -> V_37 ,
L_23 ,
V_3 -> V_40 ) ;
}
V_16 = F_64 (
F_61 ( V_3 -> V_145 ) , L_24 , 1 , 0 ,
& V_160 ) ;
if ( V_16 ) {
F_48 ( V_3 -> V_37 , L_25 ,
V_3 -> V_40 ) ;
V_3 -> V_175 = NULL ;
} else {
V_158 = F_62 ( V_160 . V_156 ) ;
if ( F_63 ( V_158 ) ) {
F_48 ( V_3 -> V_37 , L_26 ) ;
V_3 -> V_175 = NULL ;
} else {
V_3 -> V_175 = V_158 ;
V_3 -> V_176 = V_160 . args [ 0 ] ;
}
}
} else if ( F_65 ( V_3 -> V_145 ) ) {
F_49 ( V_3 ) ;
} else {
F_6 ( V_3 -> V_37 , L_27 ,
V_3 -> V_40 ) ;
}
if ( ! F_42 ( V_3 -> V_145 , L_28 ,
& V_19 ) ) {
for ( V_161 = 0 ; V_161 < F_66 ( V_177 ) ; V_161 ++ ) {
if ( ! strncmp ( V_177 [ V_161 ] . V_39 , V_19 ,
V_178 ) ) {
V_3 -> V_19 = V_177 [ V_161 ] . V_179 ;
break;
}
}
}
if ( F_67 ( V_3 -> V_145 , L_29 ,
V_3 -> V_180 , V_91 ) ) {
F_68 ( V_3 -> V_37 ,
L_30 ) ;
F_69 ( V_3 -> V_180 ) ;
}
return 0 ;
}
static int F_70 ( T_4 V_7 )
{
switch ( V_7 ) {
case V_146 :
return V_181 ;
case V_129 :
return V_182 ;
default:
return - V_50 ;
}
}
T_2 T_5 * F_71 ( struct V_71 * V_21 ,
struct V_2 * V_3 , T_1 V_183 )
{
T_2 T_5 * V_184 = V_21 -> V_185 ;
int V_40 = V_3 -> V_40 ;
if ( V_3 -> V_92 == V_186 )
return V_184 + 0x40000 + V_40 * 0x4000 -
V_183 * 0x20000 ;
else
return V_21 -> V_187 + 0x1000 ;
}
int F_72 ( struct V_71 * V_21 , struct V_2 * V_3 )
{
int V_16 ;
T_1 V_183 ;
V_3 -> V_21 = V_21 ;
V_3 -> V_37 = V_21 -> V_37 ;
V_3 -> V_188 = V_21 -> V_189 ;
V_3 -> V_190 = V_21 -> V_191 ;
V_3 -> V_17 = 0 ;
V_3 -> V_192 = 0 ;
V_3 -> V_193 = 0 ;
if ( ! F_9 ( V_21 ) )
V_3 -> V_92 = V_186 ;
else
V_3 -> V_92 = V_93 ;
V_3 -> V_7 = V_21 -> V_22 -> V_194 ( V_3 ) ;
V_16 = F_70 ( V_3 -> V_7 ) ;
if ( V_16 < 0 ) {
F_6 ( V_21 -> V_37 ,
L_31 ,
V_3 -> V_40 , V_16 ) ;
return V_16 ;
}
V_183 = ( T_1 ) V_16 ;
V_16 = F_55 ( V_3 ) ;
if ( V_16 )
return V_16 ;
V_3 -> V_21 -> V_22 -> V_124 ( V_3 ) ;
V_3 -> V_90 = F_71 ( V_21 , V_3 , V_183 ) ;
return 0 ;
}
static int F_73 ( struct V_71 * V_21 )
{
if ( F_9 ( V_21 ) )
return 1 ;
else
return V_49 ;
}
int F_74 ( struct V_71 * V_21 )
{
bool V_195 = false ;
int V_16 ;
T_1 V_196 ;
int V_197 = F_73 ( V_21 ) ;
struct V_2 * V_3 ;
struct V_135 * V_198 ;
F_75 (dsaf_dev->dev, child) {
V_16 = F_40 ( V_198 , L_32 , & V_196 ) ;
if ( V_16 ) {
F_6 ( V_21 -> V_37 ,
L_33 , V_16 ) ;
return V_16 ;
}
if ( V_196 >= V_197 ) {
F_6 ( V_21 -> V_37 ,
L_34 , V_196 ) ;
return - V_50 ;
}
V_3 = F_76 ( V_21 -> V_37 , sizeof( * V_3 ) ,
V_199 ) ;
if ( ! V_3 )
return - V_131 ;
V_3 -> V_145 = V_198 ;
V_3 -> V_40 = ( T_2 ) V_196 ;
V_21 -> V_3 [ V_196 ] = V_3 ;
V_195 = true ;
}
if ( ! V_195 ) {
for ( V_196 = 0 ; V_196 < V_197 ; V_196 ++ ) {
V_3 = F_76 ( V_21 -> V_37 , sizeof( * V_3 ) ,
V_199 ) ;
if ( ! V_3 )
return - V_131 ;
V_3 -> V_40 = V_196 ;
V_21 -> V_3 [ V_196 ] = V_3 ;
}
}
for ( V_196 = 0 ; V_196 < V_197 ; V_196 ++ ) {
V_3 = V_21 -> V_3 [ V_196 ] ;
if ( ! V_3 )
continue;
V_16 = F_72 ( V_21 , V_3 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_34 ( V_3 ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
void F_77 ( struct V_71 * V_21 )
{
int V_161 ;
int V_197 = F_73 ( V_21 ) ;
for ( V_161 = 0 ; V_161 < V_197 ; V_161 ++ ) {
V_21 -> V_22 -> V_124 ( V_21 -> V_3 [ V_161 ] ) ;
V_21 -> V_3 [ V_161 ] = NULL ;
}
}
int F_78 ( struct V_2 * V_3 ,
enum V_200 V_201 , int V_202 )
{
int V_16 ;
struct V_14 * V_95 = F_3 ( V_3 ) ;
if ( V_95 -> V_203 )
V_16 = V_95 -> V_203 ( V_95 , V_201 , V_202 ) ;
else
V_16 = - V_130 ;
return V_16 ;
}
void F_79 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
V_15 -> V_204 ( V_15 ) ;
}
void F_80 ( struct V_2 * V_3 , T_6 * V_205 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
V_15 -> V_206 ( V_15 , V_205 ) ;
}
void F_81 ( struct V_2 * V_3 ,
int V_207 , T_2 * V_205 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
V_15 -> V_208 ( V_207 , V_205 ) ;
}
int F_82 ( struct V_2 * V_3 , int V_207 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
return V_15 -> V_209 ( V_207 ) ;
}
void F_83 ( struct V_2 * V_3 , T_2 V_202 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
F_84 ( V_3 -> V_21 , V_3 -> V_40 , ! ! V_202 ) ;
if ( V_15 -> V_210 )
V_15 -> V_210 ( V_15 , V_202 ) ;
}
int F_85 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
return V_15 -> V_211 () ;
}
void F_86 ( struct V_2 * V_3 , void * V_205 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
V_15 -> V_212 ( V_15 , V_205 ) ;
}
void F_87 ( struct V_2 * V_3 )
{
int V_213 = 0 ;
int V_214 , V_215 ;
V_214 = V_3 -> V_192 - V_3 -> V_216 . V_217 ;
V_215 = V_3 -> V_193 - V_3 -> V_216 . V_218 ;
if ( V_214 || V_215 )
V_213 = 1 ;
else
V_213 = 0 ;
V_3 -> V_192 = V_3 -> V_216 . V_217 ;
V_3 -> V_193 = V_3 -> V_216 . V_218 ;
V_3 -> V_21 -> V_22 -> V_219 ( V_3 , ( int ) V_3 -> V_24 ,
V_3 -> V_26 , V_213 ) ;
}
int F_88 ( struct V_2 * V_3 ,
enum V_220 V_221 )
{
if ( ! V_3 || ! V_3 -> V_175 )
return 0 ;
return V_3 -> V_21 -> V_22 -> V_222 ( V_3 , V_221 ) ;
}
