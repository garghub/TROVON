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
static int F_7 ( struct V_2 * V_3 ,
T_2 V_39 , T_2 * V_40 )
{
T_2 V_41 ;
if ( V_3 -> V_19 -> V_42 <= V_43 ) {
if ( V_3 -> V_38 != V_44 ) {
F_6 ( V_3 -> V_35 ,
L_2 ,
V_3 -> V_19 -> V_36 . V_37 ,
V_3 -> V_38 , V_39 ) ;
return - V_45 ;
}
} else if ( V_3 -> V_19 -> V_42 < V_46 ) {
if ( V_3 -> V_38 >= V_44 ) {
F_6 ( V_3 -> V_35 ,
L_3 ,
V_3 -> V_19 -> V_36 . V_37 ,
V_3 -> V_38 , V_39 ) ;
return - V_45 ;
}
} else {
F_6 ( V_3 -> V_35 , L_4 ,
V_3 -> V_19 -> V_36 . V_37 , V_3 -> V_38 ) ;
return - V_45 ;
}
if ( V_39 >= V_3 -> V_19 -> V_47 [ 0 ] -> V_48 ) {
F_6 ( V_3 -> V_35 , L_2 ,
V_3 -> V_19 -> V_36 . V_37 , V_3 -> V_38 , V_39 ) ;
return - V_45 ;
}
switch ( V_3 -> V_19 -> V_42 ) {
case V_49 :
V_41 = 0 ;
break;
case V_50 :
V_41 = 0 ;
break;
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
V_41 = V_39 ;
break;
default:
F_6 ( V_3 -> V_35 , L_4 ,
V_3 -> V_19 -> V_36 . V_37 , V_3 -> V_38 ) ;
return - V_45 ;
}
V_41 += V_63 ;
* V_40 = V_41 ;
return 0 ;
}
int F_8 ( struct V_2 * V_3 ,
T_1 V_39 , char * V_64 )
{
int V_16 ;
struct V_14 * V_15 = F_3 ( V_3 ) ;
struct V_65 * V_19 = V_3 -> V_19 ;
struct V_66 V_67 ;
struct V_68 * V_69 ;
V_69 = & V_3 -> V_70 [ V_39 ] ;
if ( ! F_9 ( V_19 ) ) {
memcpy ( V_67 . V_64 , V_64 , sizeof( V_67 . V_64 ) ) ;
V_67 . V_71 = V_69 -> V_72 ;
V_67 . V_73 = V_3 -> V_38 ;
V_16 = F_7 ( V_3 , ( T_2 ) V_39 ,
& V_67 . V_40 ) ;
if ( V_16 )
return V_16 ;
if ( ( V_69 -> V_74 != 0 ) &&
( memcmp ( V_69 -> V_64 ,
V_64 , sizeof( V_67 . V_64 ) ) != 0 ) ) {
V_16 = F_10 ( V_19 ,
V_69 -> V_72 ,
V_3 -> V_38 ,
V_69 -> V_64 ) ;
if ( V_16 )
return V_16 ;
}
V_16 = F_11 ( V_19 , & V_67 ) ;
if ( V_16 )
return V_16 ;
}
if ( ( V_15 -> V_75 ) && ( V_39 == 0 ) )
V_15 -> V_75 ( V_3 -> V_30 . V_31 , V_64 ) ;
memcpy ( V_69 -> V_64 , V_64 , sizeof( V_69 -> V_64 ) ) ;
V_69 -> V_74 = 1 ;
return 0 ;
}
int F_12 ( struct V_2 * V_3 ,
T_1 V_40 , char * V_64 , bool V_76 )
{
int V_16 ;
struct V_65 * V_19 = V_3 -> V_19 ;
struct V_66 V_67 ;
if ( ! F_9 ( V_19 ) && V_64 ) {
memcpy ( V_67 . V_64 , V_64 , sizeof( V_67 . V_64 ) ) ;
V_67 . V_71 = 0 ;
V_67 . V_73 = V_3 -> V_38 ;
V_67 . V_40 = V_40 ;
if ( ! V_76 )
V_16 = F_13 ( V_19 , & V_67 ) ;
else
V_16 = F_14 ( V_19 , & V_67 ) ;
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
int F_15 ( struct V_2 * V_3 , T_1 V_77 , char * V_31 )
{
struct V_68 * V_78 ;
struct V_65 * V_19 ;
T_1 V_16 ;
V_19 = V_3 -> V_19 ;
if ( V_77 < V_79 ) {
V_78 = & V_3 -> V_70 [ V_77 ] ;
} else {
F_6 ( V_3 -> V_35 ,
L_6 ,
V_3 -> V_19 -> V_36 . V_37 , V_3 -> V_38 , V_77 ) ;
return - V_45 ;
}
if ( V_19 ) {
V_16 = F_10 ( V_19 , V_78 -> V_72 ,
V_3 -> V_38 , V_78 -> V_64 ) ;
if ( V_16 )
return V_16 ;
if ( memcmp ( V_78 -> V_64 , V_31 , sizeof( V_78 -> V_64 ) ) == 0 )
V_78 -> V_74 = 0 ;
}
return 0 ;
}
static void F_16 ( struct V_80 * V_81 ,
struct V_2 * V_3 )
{
V_81 -> V_82 = ( void * ) V_3 -> V_82 ;
V_81 -> V_1 = F_1 ( V_3 ) ;
memcpy ( V_81 -> V_64 , V_3 -> V_70 [ 0 ] . V_64 ,
V_83 ) ;
V_81 -> V_38 = V_3 -> V_38 ;
V_81 -> V_35 = V_3 -> V_35 ;
}
static int F_17 ( struct V_2 * V_3 ,
T_1 V_40 , T_3 V_72 , bool V_76 )
{
int V_16 ;
struct V_65 * V_19 = V_3 -> V_19 ;
T_2 V_64 [ V_83 ]
= { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_66 V_67 ;
if ( V_3 -> V_84 == V_85 )
return 0 ;
if ( ! F_9 ( V_19 ) ) {
memcpy ( V_67 . V_64 , V_64 , sizeof( V_67 . V_64 ) ) ;
V_67 . V_71 = V_72 ;
V_67 . V_73 = V_3 -> V_38 ;
V_67 . V_40 = V_40 ;
if ( ! V_76 )
V_16 = F_13 ( V_19 , & V_67 ) ;
else
V_16 = F_14 ( V_19 , & V_67 ) ;
return V_16 ;
}
return 0 ;
}
int F_18 ( struct V_2 * V_3 , T_1 V_39 , bool V_76 )
{
int V_16 ;
struct V_65 * V_19 = V_3 -> V_19 ;
T_2 V_40 ;
T_2 V_64 [ V_83 ]
= { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_68 * V_86 ;
struct V_66 V_67 ;
if ( V_3 -> V_84 == V_85 )
return 0 ;
V_86 = & V_3 -> V_70 [ V_39 ] ;
if ( ! F_9 ( V_19 ) ) {
memcpy ( V_67 . V_64 , V_64 , sizeof( V_67 . V_64 ) ) ;
V_67 . V_71 = V_86 -> V_72 ;
V_67 . V_73 = V_3 -> V_38 ;
V_16 = F_7 ( V_3 , V_39 , & V_40 ) ;
if ( V_16 )
return V_16 ;
V_67 . V_40 = V_40 ;
if ( ! V_76 )
V_16 = F_13 ( V_19 , & V_67 ) ;
else
V_16 = F_14 ( V_19 , & V_67 ) ;
return V_16 ;
}
return 0 ;
}
void F_19 ( struct V_2 * V_3 )
{
struct V_14 * V_87 = F_3 ( V_3 ) ;
bool V_88 = F_20 ( V_3 -> V_19 -> V_89 ) ;
V_87 -> V_90 ( V_87 ) ;
if ( V_87 -> V_91 )
V_87 -> V_91 ( V_87 , V_3 -> V_92 ) ;
if ( V_87 -> V_93 )
V_87 -> V_93 ( V_87 , V_3 -> V_94 ) ;
if ( V_87 -> V_95 )
V_87 -> V_95 ( V_87 , 1 ) ;
if ( V_87 -> V_96 ) {
if ( V_3 -> V_84 == V_85 )
V_87 -> V_96 ( V_87 , ! V_88 , ! V_88 ) ;
else
V_87 -> V_96 ( V_87 , 0 , 1 ) ;
}
}
int F_21 ( struct V_2 * V_3 , T_1 V_97 )
{
struct V_14 * V_87 = F_3 ( V_3 ) ;
T_1 V_98 = V_3 -> V_19 -> V_98 ;
T_1 V_99 = V_97 + V_100 + V_101 + V_102 ;
T_1 V_92 = F_20 ( V_3 -> V_19 -> V_89 ) ?
V_103 : V_104 ;
if ( V_3 -> V_84 == V_85 )
V_92 = V_105 ;
if ( ( V_97 < V_106 ) || ( V_99 > V_92 ) ||
( V_99 > V_107 * V_98 ) )
return - V_45 ;
if ( ! V_87 -> V_91 )
return - V_108 ;
if ( V_99 < ( V_109 + V_101 + V_102 ) )
V_99 = ( V_109 + V_101 + V_102 ) ;
V_87 -> V_91 ( V_87 , V_99 ) ;
V_3 -> V_92 = V_99 ;
return 0 ;
}
void F_22 ( struct V_2 * V_3 )
{
struct V_14 * V_110 = F_3 ( V_3 ) ;
if ( V_110 -> V_111 == V_112 ) {
V_110 -> V_113 += 1 ;
return;
}
if ( V_110 -> V_114 ) {
V_110 -> V_114 ( V_3 -> V_30 . V_31 , V_115 ) ;
V_110 -> V_111 = V_112 ;
}
}
void F_23 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_15 -> V_113 > 0 ) {
V_15 -> V_113 -= 1 ;
if ( V_15 -> V_113 > 0 )
return;
}
if ( V_15 -> V_116 )
V_15 -> V_116 ( V_3 -> V_30 . V_31 ,
V_115 ) ;
V_15 -> V_111 = 0 ;
V_3 -> V_22 = 0 ;
V_3 -> V_19 -> V_20 -> V_117 ( V_3 ) ;
}
void F_24 ( struct V_2 * V_3 , T_1 * V_23 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_15 -> V_118 )
V_15 -> V_118 ( V_15 , V_23 ) ;
else
* V_23 = 0 ;
}
void F_25 ( struct V_2 * V_3 , T_1 * V_119 , T_1 * V_120 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_15 -> V_121 ) {
V_15 -> V_121 ( V_15 , V_119 , V_120 ) ;
} else {
* V_119 = 0 ;
* V_120 = 0 ;
}
}
int F_26 ( struct V_2 * V_3 , T_2 V_76 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_3 -> V_7 == V_122 && V_76 ) {
F_6 ( V_3 -> V_35 , L_7 ) ;
return - V_123 ;
}
if ( V_15 -> V_95 )
V_15 -> V_95 ( V_15 , V_76 ) ;
return 0 ;
}
int F_27 ( struct V_2 * V_3 , T_1 V_119 , T_1 V_120 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
bool V_88 = F_20 ( V_3 -> V_19 -> V_89 ) ;
if ( V_3 -> V_84 == V_85 ) {
if ( V_88 && ( V_120 || V_119 ) ) {
F_6 ( V_3 -> V_35 , L_8 ) ;
return - V_45 ;
}
}
if ( V_15 -> V_96 )
V_15 -> V_96 ( V_15 , V_119 , V_120 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
int V_16 ;
struct V_80 V_81 ;
struct V_14 * V_87 ;
F_29 ( V_3 ) ;
memset ( & V_81 , 0 , sizeof( struct V_80 ) ) ;
F_16 ( & V_81 , V_3 ) ;
if ( F_30 ( V_81 . V_1 ) < V_10 )
V_87 = (struct V_14 * ) F_31 ( V_3 , & V_81 ) ;
else
V_87 = (struct V_14 * ) F_32 ( V_3 , & V_81 ) ;
if ( ! V_87 )
return - V_124 ;
V_3 -> V_30 . V_31 = ( void * ) V_87 ;
F_19 ( V_3 ) ;
F_5 ( V_3 , V_3 -> V_24 , ! V_3 -> V_32 ) ;
V_16 = F_17 ( V_3 , V_3 -> V_38 , 0 , true ) ;
if ( V_16 )
goto V_125;
return 0 ;
V_125:
V_87 -> V_126 ( V_3 -> V_30 . V_31 ) ;
V_3 -> V_30 . V_31 = NULL ;
return V_16 ;
}
static int
F_33 ( struct V_127 * V_35 , struct V_128 * V_129 )
{
T_1 V_64 ;
int V_16 ;
V_16 = F_34 ( V_129 , L_9 , & V_64 ) ;
if ( V_16 ) {
F_6 ( V_35 , L_10 , V_16 ) ;
return V_16 ;
}
if ( V_64 >= V_130 ) {
F_6 ( V_35 , L_11 , V_64 ) ;
return - V_45 ;
}
return V_64 ;
}
static int F_35 ( struct V_127 * V_35 , void * V_129 )
{
return V_35 -> V_129 == V_129 ;
}
static struct
V_131 * F_36 ( struct V_128 * V_129 )
{
struct V_127 * V_35 ;
V_35 = F_37 ( & V_132 , NULL ,
V_129 , F_35 ) ;
return V_35 ? F_38 ( V_35 ) : NULL ;
}
static int
F_39 ( struct V_133 * V_134 , struct V_2 * V_3 ,
T_1 V_64 )
{
struct V_135 * V_136 ;
const char * V_137 ;
bool V_138 ;
int V_139 ;
V_139 = F_40 ( V_3 -> V_140 ,
L_12 , & V_137 ) ;
if ( V_139 < 0 )
return V_139 ;
if ( ! strcmp ( V_137 , F_41 ( V_122 ) ) )
V_138 = 1 ;
else if ( ! strcmp ( V_137 , F_41 ( V_141 ) ) )
V_138 = 0 ;
else
return - V_142 ;
V_136 = F_42 ( V_134 , V_64 , V_138 ) ;
if ( ! V_136 || F_43 ( V_136 ) )
return - V_143 ;
if ( V_134 -> V_144 )
V_136 -> V_144 = V_134 -> V_144 [ V_64 ] ;
V_139 = F_44 ( V_136 ) ;
if ( V_139 ) {
F_45 ( V_136 ) ;
return - V_29 ;
}
V_3 -> V_145 = V_136 ;
F_46 ( & V_134 -> V_35 , L_13 , V_64 ) ;
return 0 ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_146 args ;
struct V_131 * V_147 ;
struct V_133 * V_133 ;
int V_139 ;
int V_64 ;
if ( ! F_48 ( V_3 -> V_140 ) )
return;
V_139 = F_49 (
V_3 -> V_140 , L_14 , 0 , & args ) ;
if ( V_139 )
return;
V_64 = F_33 ( V_3 -> V_35 , V_3 -> V_140 ) ;
if ( V_64 < 0 )
return;
V_147 = F_36 ( F_50 ( args . V_148 ) ) ;
V_133 = F_51 ( V_147 ) ;
V_139 = F_39 ( V_133 , V_3 , V_64 ) ;
if ( ! V_139 )
F_46 ( V_3 -> V_35 , L_15 ,
V_3 -> V_38 , V_64 ) ;
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_149 * V_150 ;
struct V_151 * V_152 ;
struct V_153 V_154 ;
const char * V_155 ;
T_1 V_156 ;
T_1 V_16 ;
V_3 -> V_22 = false ;
V_3 -> V_32 = false ;
V_3 -> V_155 = V_157 ;
V_3 -> V_24 = V_158 [ V_3 -> V_7 ] ;
V_3 -> V_4 = V_3 -> V_24 ;
if ( V_3 -> V_7 == V_141 ) {
V_3 -> V_159 = V_160 ;
V_3 -> V_159 |= V_161 ;
} else if ( V_3 -> V_7 == V_122 ) {
V_3 -> V_159 = V_162 ;
V_3 -> V_159 |= V_163 ;
}
V_3 -> V_92 = V_164 ;
V_3 -> V_94 = V_165 ;
V_3 -> V_166 = V_3 -> V_38 ;
V_3 -> V_167 = 0 ;
if ( ! V_3 -> V_140 ) {
V_150 = F_53 ( V_3 -> V_35 -> V_168 , L_16 ,
V_3 -> V_38 ) ;
V_3 -> V_145 = F_54 ( V_150 ) ;
if ( V_3 -> V_145 ) {
F_55 ( & V_3 -> V_145 -> V_134 . V_35 ) ;
F_46 ( V_3 -> V_35 , L_17 ,
V_3 -> V_38 , V_150 -> V_37 ) ;
}
F_56 ( V_150 ) ;
return 0 ;
}
if ( F_57 ( V_3 -> V_140 ) ) {
V_150 = F_53 ( F_58 ( V_3 -> V_140 ) ,
L_16 , 0 ) ;
V_3 -> V_145 = F_54 ( V_150 ) ;
if ( V_3 -> V_145 ) {
F_55 ( & V_3 -> V_145 -> V_134 . V_35 ) ;
F_46 ( V_3 -> V_35 , L_17 ,
V_3 -> V_38 , V_150 -> V_37 ) ;
}
F_56 ( V_150 ) ;
V_150 = F_53 ( F_58 ( V_3 -> V_140 ) ,
L_18 , 0 ) ;
V_152 = F_59 ( V_150 ) ;
F_56 ( V_150 ) ;
if ( F_60 ( V_152 ) ) {
F_6 ( V_3 -> V_35 , L_19 ) ;
return - V_45 ;
}
V_3 -> V_169 = V_152 ;
V_16 = F_34 ( V_3 -> V_140 ,
L_20 ,
& V_3 -> V_166 ) ;
if ( V_16 ) {
F_46 ( V_3 -> V_35 ,
L_21 ,
V_3 -> V_38 ) ;
}
V_16 = F_34 ( V_3 -> V_140 ,
L_22 ,
& V_3 -> V_167 ) ;
if ( V_16 ) {
F_46 ( V_3 -> V_35 ,
L_23 ,
V_3 -> V_38 ) ;
}
V_16 = F_61 (
F_58 ( V_3 -> V_140 ) , L_24 , 1 , 0 ,
& V_154 ) ;
if ( V_16 ) {
F_46 ( V_3 -> V_35 , L_25 ,
V_3 -> V_38 ) ;
V_3 -> V_170 = NULL ;
} else {
V_152 = F_59 ( V_154 . V_150 ) ;
if ( F_60 ( V_152 ) ) {
F_46 ( V_3 -> V_35 , L_26 ) ;
V_3 -> V_170 = NULL ;
} else {
V_3 -> V_170 = V_152 ;
V_3 -> V_171 = V_154 . args [ 0 ] ;
}
}
} else if ( F_62 ( V_3 -> V_140 ) ) {
F_47 ( V_3 ) ;
} else {
F_6 ( V_3 -> V_35 , L_27 ,
V_3 -> V_38 ) ;
}
if ( ! F_40 ( V_3 -> V_140 , L_28 ,
& V_155 ) ) {
for ( V_156 = 0 ; V_156 < F_63 ( V_172 ) ; V_156 ++ ) {
if ( ! strncmp ( V_172 [ V_156 ] . V_37 , V_155 ,
V_173 ) ) {
V_3 -> V_155 = V_172 [ V_156 ] . V_174 ;
break;
}
}
}
return 0 ;
}
static int F_64 ( T_4 V_7 )
{
switch ( V_7 ) {
case V_141 :
return V_175 ;
case V_122 :
return V_176 ;
default:
return - V_45 ;
}
}
T_2 T_5 * F_65 ( struct V_65 * V_19 ,
struct V_2 * V_3 , T_1 V_177 )
{
T_2 T_5 * V_178 = V_19 -> V_179 ;
int V_38 = V_3 -> V_38 ;
if ( V_3 -> V_84 == V_180 )
return V_178 + 0x40000 + V_38 * 0x4000 -
V_177 * 0x20000 ;
else
return V_19 -> V_181 + 0x1000 ;
}
int F_66 ( struct V_65 * V_19 , struct V_2 * V_3 )
{
int V_16 ;
T_1 V_177 ;
V_3 -> V_19 = V_19 ;
V_3 -> V_35 = V_19 -> V_35 ;
V_3 -> V_182 = V_19 -> V_183 ;
V_3 -> V_184 = V_19 -> V_185 ;
V_3 -> V_17 = 0 ;
V_3 -> V_186 = 0 ;
V_3 -> V_187 = 0 ;
if ( ! F_9 ( V_19 ) )
V_3 -> V_84 = V_180 ;
else
V_3 -> V_84 = V_85 ;
V_3 -> V_7 = V_19 -> V_20 -> V_188 ( V_3 ) ;
V_16 = F_64 ( V_3 -> V_7 ) ;
if ( V_16 < 0 ) {
F_6 ( V_19 -> V_35 ,
L_29 ,
V_3 -> V_38 , V_16 ) ;
return V_16 ;
}
V_177 = ( T_1 ) V_16 ;
V_16 = F_52 ( V_3 ) ;
if ( V_16 )
return V_16 ;
V_3 -> V_19 -> V_20 -> V_117 ( V_3 ) ;
V_3 -> V_82 = F_65 ( V_19 , V_3 , V_177 ) ;
return 0 ;
}
static int F_67 ( struct V_65 * V_19 )
{
if ( F_9 ( V_19 ) )
return 1 ;
else
return V_44 ;
}
int F_68 ( struct V_65 * V_19 )
{
bool V_189 = false ;
int V_16 ;
T_1 V_190 ;
int V_191 = F_67 ( V_19 ) ;
struct V_2 * V_3 ;
struct V_128 * V_192 ;
F_69 (dsaf_dev->dev, child) {
V_16 = F_34 ( V_192 , L_30 , & V_190 ) ;
if ( V_16 ) {
F_6 ( V_19 -> V_35 ,
L_31 , V_16 ) ;
return V_16 ;
}
if ( V_190 >= V_191 ) {
F_6 ( V_19 -> V_35 ,
L_32 , V_190 ) ;
return - V_45 ;
}
V_3 = F_70 ( V_19 -> V_35 , sizeof( * V_3 ) ,
V_193 ) ;
if ( ! V_3 )
return - V_124 ;
V_3 -> V_140 = V_192 ;
V_3 -> V_38 = ( T_2 ) V_190 ;
V_19 -> V_3 [ V_190 ] = V_3 ;
V_189 = true ;
}
if ( ! V_189 ) {
for ( V_190 = 0 ; V_190 < V_191 ; V_190 ++ ) {
V_3 = F_70 ( V_19 -> V_35 , sizeof( * V_3 ) ,
V_193 ) ;
if ( ! V_3 )
return - V_124 ;
V_3 -> V_38 = V_190 ;
V_19 -> V_3 [ V_190 ] = V_3 ;
}
}
for ( V_190 = 0 ; V_190 < V_191 ; V_190 ++ ) {
V_3 = V_19 -> V_3 [ V_190 ] ;
if ( ! V_3 )
continue;
V_16 = F_66 ( V_19 , V_3 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_28 ( V_3 ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
void F_71 ( struct V_65 * V_19 )
{
int V_156 ;
int V_191 = F_67 ( V_19 ) ;
for ( V_156 = 0 ; V_156 < V_191 ; V_156 ++ ) {
V_19 -> V_20 -> V_117 ( V_19 -> V_3 [ V_156 ] ) ;
V_19 -> V_3 [ V_156 ] = NULL ;
}
}
int F_72 ( struct V_2 * V_3 ,
enum V_194 V_195 , int V_196 )
{
int V_16 ;
struct V_14 * V_87 = F_3 ( V_3 ) ;
if ( V_87 -> V_197 )
V_16 = V_87 -> V_197 ( V_87 , V_195 , V_196 ) ;
else
V_16 = - V_123 ;
return V_16 ;
}
void F_73 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
V_15 -> V_198 ( V_15 ) ;
}
void F_74 ( struct V_2 * V_3 , T_6 * V_199 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
V_15 -> V_200 ( V_15 , V_199 ) ;
}
void F_75 ( struct V_2 * V_3 ,
int V_201 , T_2 * V_199 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
V_15 -> V_202 ( V_201 , V_199 ) ;
}
int F_76 ( struct V_2 * V_3 , int V_201 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
return V_15 -> V_203 ( V_201 ) ;
}
void F_77 ( struct V_2 * V_3 , T_2 V_196 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
if ( V_15 -> V_204 )
V_15 -> V_204 ( V_15 , V_196 ) ;
}
int F_78 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
return V_15 -> V_205 () ;
}
void F_79 ( struct V_2 * V_3 , void * V_199 )
{
struct V_14 * V_15 = F_3 ( V_3 ) ;
V_15 -> V_206 ( V_15 , V_199 ) ;
}
void F_80 ( struct V_2 * V_3 )
{
int V_207 = 0 ;
int V_208 , V_209 ;
V_208 = V_3 -> V_186 - V_3 -> V_210 . V_211 ;
V_209 = V_3 -> V_187 - V_3 -> V_210 . V_212 ;
if ( V_208 || V_209 )
V_207 = 1 ;
else
V_207 = 0 ;
V_3 -> V_186 = V_3 -> V_210 . V_211 ;
V_3 -> V_187 = V_3 -> V_210 . V_212 ;
V_3 -> V_19 -> V_20 -> V_213 ( V_3 , ( int ) V_3 -> V_22 ,
V_3 -> V_24 , V_207 ) ;
}
int F_81 ( struct V_2 * V_3 ,
enum V_214 V_215 )
{
if ( ! V_3 || ! V_3 -> V_170 )
return 0 ;
return V_3 -> V_19 -> V_20 -> V_216 ( V_3 , V_215 ) ;
}
