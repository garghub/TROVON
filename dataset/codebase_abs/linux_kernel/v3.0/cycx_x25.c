int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 V_5 ;
if ( V_3 -> V_6 != V_7 ) {
F_2 ( V_8 L_1 ,
V_2 -> V_9 , V_3 -> V_6 ) ;
return - V_10 ;
}
V_2 -> V_11 = V_2 -> V_12 . V_13 + V_14 ;
V_2 -> V_15 . V_16 . V_17 = 0 ;
F_3 ( & V_2 -> V_15 . V_16 . V_18 ) ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_19 = 0 ;
V_5 . clock = V_3 -> V_20 == V_21 ? 8 : 55 ;
V_5 . V_22 = F_4 ( V_3 -> V_23 ) ;
V_5 . V_24 = 7 ;
V_5 . V_25 = 2 ;
V_5 . V_26 = 5 ;
V_5 . V_27 = 1 ;
V_5 . V_28 = 1 ;
V_5 . V_29 = 0x02 ;
V_5 . V_30 = 10 ;
V_5 . V_31 = 29 ;
V_5 . V_32 = 180 ;
V_5 . V_33 = 180 ;
if ( ! V_3 -> V_34 || V_3 -> V_34 >= 512 )
V_2 -> V_35 . V_34 = 512 ;
else if ( V_3 -> V_34 >= 256 )
V_2 -> V_35 . V_34 = 256 ;
else if ( V_3 -> V_34 >= 128 )
V_2 -> V_35 . V_34 = 128 ;
else
V_2 -> V_35 . V_34 = 64 ;
V_5 . V_36 = F_5 ( V_2 -> V_35 . V_34 ) ;
if ( V_3 -> V_37 == V_38 ) {
V_5 . V_39 = 3 ;
V_5 . V_40 = 1 ;
} else {
V_5 . V_39 = 1 ;
V_5 . V_40 = 3 ;
}
if ( V_3 -> V_41 == V_42 )
V_5 . V_29 = 0 ;
if ( V_3 -> V_15 . V_43 . V_44 ) {
V_2 -> V_15 . V_16 . V_44 = F_6 (unsigned int, conf->u.x25.hi_pvc, 4095 ) ;
V_2 -> V_15 . V_16 . V_45 = F_6 (unsigned int, conf->u.x25.lo_pvc, card->u.x.hi_pvc) ;
}
if ( V_3 -> V_15 . V_43 . V_46 ) {
V_2 -> V_15 . V_16 . V_46 = F_6 (unsigned int, conf->u.x25.hi_svc, 4095 ) ;
V_2 -> V_15 . V_16 . V_47 = F_6 (unsigned int, conf->u.x25.lo_svc, card->u.x.hi_svc) ;
}
if ( V_2 -> V_15 . V_16 . V_45 == 255 )
V_5 . V_28 = 0 ;
else
V_5 . V_28 = V_2 -> V_15 . V_16 . V_44 - V_2 -> V_15 . V_16 . V_45 + 1 ;
V_5 . V_27 = V_2 -> V_15 . V_16 . V_46 - V_2 -> V_15 . V_16 . V_47 + 1 + V_5 . V_28 ;
if ( V_3 -> V_15 . V_43 . V_48 )
V_5 . V_25 = F_6 (unsigned int, conf->u.x25.hdlc_window, 7 ) ;
if ( V_3 -> V_15 . V_43 . V_49 )
V_5 . V_24 = F_6 (unsigned int, conf->u.x25.pkt_window, 7 ) ;
if ( V_3 -> V_15 . V_43 . V_30 )
V_5 . V_30 = F_6 (unsigned int, conf->u.x25.t1, 30 ) ;
if ( V_3 -> V_15 . V_43 . V_31 )
V_5 . V_31 = F_6 (unsigned int, conf->u.x25.t2, 30 ) ;
if ( V_3 -> V_15 . V_43 . V_50 )
V_5 . V_32 = F_6 (unsigned int, conf->u.x25.t11_t21, 30 ) ;
if ( V_3 -> V_15 . V_43 . V_51 )
V_5 . V_33 = F_6 (unsigned int, conf->u.x25.t13_t23, 30 ) ;
if ( V_3 -> V_15 . V_43 . V_26 )
V_5 . V_26 = F_6 (unsigned int, conf->u.x25.n2, 30 ) ;
if ( F_7 ( V_2 , & V_5 ) )
return - V_52 ;
V_2 -> V_35 . V_23 = V_3 -> V_23 ;
V_2 -> V_35 . V_41 = V_3 -> V_41 ;
V_2 -> V_35 . V_20 = V_3 -> V_20 ;
V_2 -> V_35 . V_37 = V_3 -> V_37 ;
V_2 -> V_53 = V_54 ;
V_2 -> V_55 = NULL ;
V_2 -> V_35 . V_56 = V_57 ;
V_2 -> V_35 . V_58 = V_59 ;
V_2 -> V_35 . V_60 = V_61 ;
V_2 -> V_35 . V_62 = V_63 ;
return 0 ;
}
static int V_57 ( struct V_64 * V_35 )
{
if ( ! V_35 || ! V_35 -> V_65 )
return - V_66 ;
if ( V_35 -> V_62 == V_67 )
return - V_68 ;
F_8 ( V_35 -> V_65 ) ;
return 0 ;
}
static int V_59 ( struct V_64 * V_35 , struct V_69 * V_70 ,
T_2 * V_3 )
{
struct V_1 * V_2 = V_35 -> V_65 ;
struct V_71 * V_72 ;
int V_73 = 0 ;
if ( ! V_3 -> V_74 [ 0 ] || strlen ( V_3 -> V_74 ) > V_75 ) {
F_2 ( V_8 L_2 ,
V_2 -> V_9 ) ;
return - V_10 ;
}
V_70 = F_9 ( sizeof( struct V_71 ) , V_3 -> V_74 ,
V_76 ) ;
if ( ! V_70 )
return - V_77 ;
V_72 = F_10 ( V_70 ) ;
strcpy ( V_72 -> V_74 , V_3 -> V_74 ) ;
V_72 -> V_2 = V_2 ;
V_72 -> V_19 = V_3 -> V_78 ;
V_72 -> V_79 = V_3 -> V_79 ? V_80 : V_81 ;
V_72 -> V_82 = NULL ;
V_72 -> V_83 = NULL ;
if ( V_3 -> V_84 [ 0 ] == '@' ) {
int V_85 = strlen ( V_3 -> V_83 ) ;
if ( V_85 ) {
if ( V_85 > V_86 ) {
F_2 ( V_87 L_3 ,
V_35 -> V_74 , V_72 -> V_74 ) ;
V_73 = - V_10 ;
goto error;
} else {
V_72 -> V_83 = F_11 ( V_85 + 1 , V_88 ) ;
if ( ! V_72 -> V_83 ) {
V_73 = - V_77 ;
goto error;
}
}
strncpy ( V_72 -> V_83 , V_3 -> V_83 ,
V_86 ) ;
}
V_72 -> V_89 = 1 ;
strncpy ( V_72 -> V_84 , & V_3 -> V_84 [ 1 ] , V_86 ) ;
F_12 ( & V_72 -> V_90 ) ;
V_72 -> V_90 . V_91 = V_92 ;
V_72 -> V_90 . V_93 = ( unsigned long ) V_70 ;
V_72 -> V_94 = V_3 -> V_95 ? V_3 -> V_95 : 90 ;
} else if ( isdigit ( V_3 -> V_84 [ 0 ] ) ) {
T_3 V_96 = F_13 ( V_3 -> V_84 , 0 ) ;
if ( V_96 >= V_2 -> V_15 . V_16 . V_45 && V_96 <= V_2 -> V_15 . V_16 . V_44 )
V_72 -> V_96 = V_96 ;
else {
F_2 ( V_87
L_4 ,
V_35 -> V_74 , V_96 , V_72 -> V_74 ) ;
V_73 = - V_10 ;
goto error;
}
} else {
F_2 ( V_87 L_5 ,
V_35 -> V_74 , V_72 -> V_74 ) ;
V_73 = - V_10 ;
goto error;
}
return 0 ;
error:
F_14 ( V_70 ) ;
return V_73 ;
}
static int V_61 ( struct V_64 * V_35 , struct V_69 * V_70 )
{
struct V_71 * V_72 = F_10 ( V_70 ) ;
if ( V_72 -> V_89 ) {
F_15 ( V_72 -> V_83 ) ;
if ( V_72 -> V_62 == V_97 )
F_16 ( & V_72 -> V_90 ) ;
}
return 0 ;
}
static void V_76 ( struct V_69 * V_70 )
{
V_70 -> V_98 = & V_99 ;
V_70 -> V_100 = & V_101 ;
V_70 -> V_34 = V_102 ;
V_70 -> type = V_103 ;
V_70 -> V_104 = 0 ;
V_70 -> V_105 = 0 ;
}
static int F_17 ( struct V_69 * V_70 )
{
struct V_71 * V_72 = F_10 ( V_70 ) ;
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_64 * V_35 = & V_2 -> V_35 ;
if ( ! V_72 -> V_89 )
* ( V_106 * ) V_70 -> V_107 = F_18 ( V_72 -> V_96 ) ;
V_70 -> V_108 = V_35 -> V_108 ;
V_70 -> V_109 = V_35 -> V_109 ;
V_70 -> V_110 = V_35 -> V_111 ;
V_70 -> V_112 = ( unsigned long ) V_35 -> V_113 ;
V_70 -> V_114 = ( unsigned long ) ( V_35 -> V_113 +
V_35 -> V_115 - 1 ) ;
V_70 -> V_29 |= V_116 ;
V_70 -> V_117 = 10 ;
F_19 ( V_70 , V_63 ) ;
return 0 ;
}
static int F_20 ( struct V_69 * V_70 )
{
if ( F_21 ( V_70 ) )
return - V_118 ;
F_22 ( V_70 ) ;
return 0 ;
}
static int F_23 ( struct V_69 * V_70 )
{
struct V_71 * V_72 = F_10 ( V_70 ) ;
F_24 ( V_70 ) ;
if ( V_72 -> V_62 == V_97 || V_72 -> V_62 == V_119 )
F_25 ( V_70 ) ;
return 0 ;
}
static int F_26 ( struct V_120 * V_121 ,
struct V_69 * V_70 , T_4 type ,
const void * V_122 , const void * V_123 ,
unsigned V_85 )
{
V_121 -> V_79 = F_18 ( type ) ;
return V_70 -> V_104 ;
}
static int F_27 ( struct V_120 * V_121 )
{
return 1 ;
}
static T_5 F_28 ( struct V_120 * V_121 ,
struct V_69 * V_70 )
{
struct V_71 * V_72 = F_10 ( V_70 ) ;
struct V_1 * V_2 = V_72 -> V_2 ;
if ( ! V_72 -> V_89 )
V_72 -> V_79 = F_29 ( V_121 -> V_79 ) ;
if ( V_2 -> V_35 . V_62 != V_97 )
++ V_72 -> V_124 . V_125 ;
else if ( V_72 -> V_89 && V_72 -> V_79 &&
V_72 -> V_79 != F_29 ( V_121 -> V_79 ) ) {
F_2 ( V_8
L_6 ,
V_2 -> V_9 , F_29 ( V_121 -> V_79 ) , V_70 -> V_74 ) ;
++ V_72 -> V_124 . V_126 ;
} else if ( V_72 -> V_79 == V_81 ) {
switch ( V_72 -> V_62 ) {
case V_63 :
if ( F_30 ( V_70 ) ) {
F_24 ( V_70 ) ;
return V_127 ;
}
case V_97 :
F_31 ( V_70 ) ;
V_70 -> V_128 = V_129 ;
F_24 ( V_70 ) ;
if ( F_32 ( V_70 , V_121 ) )
return V_127 ;
break;
default:
++ V_72 -> V_124 . V_125 ;
++ V_2 -> V_35 . V_130 . V_125 ;
}
} else {
switch ( V_121 -> V_93 [ 0 ] ) {
case V_131 :
break;
case V_132 :
F_30 ( V_70 ) ;
goto V_133;
case V_134 :
F_25 ( V_70 ) ;
goto V_133;
default:
F_2 ( V_8
L_7 ,
V_2 -> V_9 , V_121 -> V_93 [ 0 ] , V_70 -> V_74 ) ;
++ V_72 -> V_124 . V_126 ;
goto V_133;
}
F_33 ( V_121 , 1 ) ;
F_31 ( V_70 ) ;
V_70 -> V_128 = V_129 ;
F_24 ( V_70 ) ;
if ( F_32 ( V_70 , V_121 ) ) {
F_34 ( V_121 , 1 ) ;
return V_127 ;
}
}
V_133:
F_35 ( V_121 ) ;
return V_135 ;
}
static struct V_136 * F_36 ( struct V_69 * V_70 )
{
struct V_71 * V_72 = F_10 ( V_70 ) ;
return V_72 ? & V_72 -> V_124 : NULL ;
}
static void V_54 ( struct V_1 * V_2 )
{
struct V_137 V_138 ;
T_4 V_139 = 0 ;
V_2 -> V_140 = 1 ;
V_2 -> V_141 = 0 ;
F_37 ( & V_2 -> V_12 , V_142 , & V_138 , sizeof( V_138 ) ) ;
switch ( V_138 . V_143 ) {
case V_144 :
F_38 ( V_2 , & V_138 ) ;
break;
case V_145 :
F_39 ( V_2 , & V_138 ) ;
break;
case V_146 :
F_40 ( V_2 , & V_138 ) ;
break;
case V_147 :
F_41 ( V_2 , & V_138 ) ;
break;
case V_148 :
F_42 ( V_2 , & V_138 ) ;
break;
case V_149 :
F_43 ( V_2 , & V_138 ) ;
break;
case V_150 :
F_44 ( V_2 , & V_138 ) ;
break;
case V_151 :
F_45 ( V_2 , & V_138 ) ;
break;
case V_152 :
F_46 ( V_2 , V_97 ) ;
break;
case V_153 :
F_46 ( V_2 , V_63 ) ;
break;
default:
F_47 ( V_2 , & V_138 ) ;
break;
}
F_48 ( & V_2 -> V_12 , 0 , & V_139 , sizeof( V_139 ) ) ;
F_48 ( & V_2 -> V_12 , V_142 , & V_139 , sizeof( V_139 ) ) ;
V_2 -> V_140 = 0 ;
}
static void F_39 ( struct V_1 * V_2 , struct V_137 * V_138 )
{
struct V_69 * V_70 ;
struct V_64 * V_35 = & V_2 -> V_35 ;
T_6 V_96 ;
F_37 ( & V_2 -> V_12 , V_138 -> V_154 , & V_96 , sizeof( V_96 ) ) ;
V_70 = F_49 ( V_35 , V_96 ) ;
if ( V_70 ) {
V_2 -> V_141 = 1 ;
F_50 ( V_70 ) ;
} else
F_2 ( V_87 L_8 ,
V_2 -> V_9 , V_96 ) ;
}
static void F_38 ( struct V_1 * V_2 , struct V_137 * V_138 )
{
struct V_64 * V_35 = & V_2 -> V_35 ;
struct V_69 * V_70 ;
struct V_71 * V_72 ;
struct V_120 * V_121 ;
T_6 V_155 , V_96 ;
int V_36 = V_138 -> V_85 - 5 ;
F_37 ( & V_2 -> V_12 , V_138 -> V_154 , & V_96 , sizeof( V_96 ) ) ;
F_37 ( & V_2 -> V_12 , V_138 -> V_154 + 4 , & V_155 , sizeof( V_155 ) ) ;
V_155 &= 0x10 ;
V_70 = F_49 ( V_35 , V_96 ) ;
if ( ! V_70 ) {
F_2 ( V_8 L_9 ,
V_2 -> V_9 , V_96 ) ;
return;
}
V_72 = F_10 ( V_70 ) ;
F_31 ( V_70 ) ;
if ( V_72 -> V_156 ) {
if ( ! V_155 )
V_72 -> V_156 = 0 ;
else
return;
}
if ( ( V_121 = V_72 -> V_82 ) == NULL ) {
int V_157 = V_155 ? V_70 -> V_34 : V_36 ;
if ( ( V_121 = F_51 ( ( V_72 -> V_79 == V_80 ? 1 : 0 ) +
V_157 +
V_70 -> V_104 ) ) == NULL ) {
F_2 ( V_8 L_10 ,
V_2 -> V_9 ) ;
V_72 -> V_156 = 1 ;
++ V_72 -> V_124 . V_158 ;
return;
}
if ( V_72 -> V_79 == V_80 )
F_52 ( V_121 , 1 ) ;
V_121 -> V_70 = V_70 ;
V_121 -> V_79 = F_18 ( V_72 -> V_79 ) ;
V_72 -> V_82 = V_121 ;
}
if ( F_53 ( V_121 ) < V_36 ) {
F_54 ( V_121 ) ;
V_72 -> V_82 = NULL ;
if ( V_155 )
V_72 -> V_156 = 1 ;
F_2 ( V_8 L_11
L_12 , V_2 -> V_9 , V_70 -> V_74 ) ;
++ V_72 -> V_124 . V_159 ;
return;
}
F_37 ( & V_2 -> V_12 , V_138 -> V_154 + 5 , F_52 ( V_121 , V_36 ) , V_36 ) ;
if ( V_155 )
return;
V_72 -> V_82 = NULL ;
++ V_72 -> V_124 . V_160 ;
V_72 -> V_124 . V_161 += V_36 ;
F_55 ( V_121 ) ;
F_56 ( V_121 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_137 * V_138 )
{
struct V_64 * V_35 = & V_2 -> V_35 ;
struct V_69 * V_70 = NULL ;
struct V_71 * V_72 ;
T_6 V_162 [ 32 ] ,
V_163 [ 24 ] ,
V_164 [ 24 ] ;
T_6 V_96 , V_165 , V_166 ;
F_37 ( & V_2 -> V_12 , V_138 -> V_154 , & V_96 , sizeof( V_96 ) ) ;
F_37 ( & V_2 -> V_12 , V_138 -> V_154 + 5 , & V_165 , sizeof( V_165 ) ) ;
F_37 ( & V_2 -> V_12 , V_138 -> V_154 + 6 , V_162 , V_138 -> V_85 - 6 ) ;
V_166 = V_165 >> 4 ;
V_165 &= 0x0F ;
V_163 [ 0 ] = V_164 [ 0 ] = '\0' ;
if ( V_165 )
F_57 ( V_162 , V_163 , V_165 , 0 ) ;
if ( V_166 )
F_57 ( V_162 + ( V_165 >> 1 ) , V_164 , V_166 , V_165 & 1 ) ;
F_58 ( 1 , V_8 L_13 ,
V_167 , V_96 , V_163 , V_164 ) ;
V_70 = F_59 ( V_35 , V_164 ) ;
if ( ! V_70 ) {
F_2 ( V_8 L_14 ,
V_2 -> V_9 , V_164 ) ;
return;
}
V_72 = F_10 ( V_70 ) ;
V_72 -> V_96 = V_96 ;
F_60 ( V_2 , V_72 ) ;
F_19 ( V_70 , V_97 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_137 * V_138 )
{
struct V_64 * V_35 = & V_2 -> V_35 ;
struct V_69 * V_70 ;
struct V_71 * V_72 ;
T_6 V_96 , V_168 ;
F_37 ( & V_2 -> V_12 , V_138 -> V_154 , & V_96 , sizeof( V_96 ) ) ;
F_37 ( & V_2 -> V_12 , V_138 -> V_154 + 1 , & V_168 , sizeof( V_168 ) ) ;
F_58 ( 1 , V_8 L_15 ,
V_2 -> V_9 , V_167 , V_96 , V_168 ) ;
V_70 = F_49 ( V_35 , - V_168 ) ;
if ( ! V_70 ) {
F_61 ( -- V_168 , ( void * ) & V_2 -> V_15 . V_16 . V_17 ) ;
F_2 ( V_8 L_16
L_17 , V_2 -> V_9 , V_96 , V_168 ) ;
return;
}
F_61 ( -- V_168 , ( void * ) & V_2 -> V_15 . V_16 . V_17 ) ;
V_72 = F_10 ( V_70 ) ;
V_72 -> V_96 = V_96 ;
F_19 ( V_70 , V_97 ) ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_137 * V_138 )
{
struct V_64 * V_35 = & V_2 -> V_35 ;
struct V_69 * V_70 ;
T_6 V_96 ;
F_37 ( & V_2 -> V_12 , V_138 -> V_154 , & V_96 , sizeof( V_96 ) ) ;
F_58 ( 1 , V_8 L_18 ,
V_2 -> V_9 , V_167 , V_96 ) ;
V_70 = F_49 ( V_35 , V_96 ) ;
if ( ! V_70 ) {
F_2 ( V_8 L_19 ,
V_2 -> V_9 , V_96 ) ;
return;
}
F_19 ( V_70 , V_63 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_137 * V_138 )
{
struct V_64 * V_35 = & V_2 -> V_35 ;
struct V_69 * V_70 ;
T_6 V_96 ;
F_37 ( & V_2 -> V_12 , V_138 -> V_154 , & V_96 , sizeof( V_96 ) ) ;
F_58 ( 1 , V_8 L_20 , V_167 , V_96 ) ;
V_70 = F_49 ( V_35 , V_96 ) ;
if ( V_70 ) {
struct V_71 * V_72 = F_10 ( V_70 ) ;
F_62 ( V_2 , V_72 -> V_19 , V_96 ) ;
F_19 ( V_70 , V_63 ) ;
} else
F_62 ( V_2 , 0 , V_96 ) ;
}
static void F_40 ( struct V_1 * V_2 , struct V_137 * V_138 )
{
#if V_169
char V_170 [ 20 ] ;
T_4 V_171 , V_172 , V_19 , V_173 ;
T_6 V_174 , V_175 ;
F_37 ( & V_2 -> V_12 , V_138 -> V_154 , & V_173 , sizeof( V_173 ) ) ;
F_37 ( & V_2 -> V_12 , V_138 -> V_154 + 2 , & V_19 , sizeof( V_19 ) ) ;
F_37 ( & V_2 -> V_12 , V_138 -> V_154 + 4 , & V_171 , sizeof( V_171 ) ) ;
V_172 = V_171 < 20 ? V_171 : 20 ;
F_37 ( & V_2 -> V_12 , V_138 -> V_154 + 10 , & V_170 , V_172 ) ;
F_37 ( & V_2 -> V_12 , V_138 -> V_154 + 10 + V_172 , & V_174 , 1 ) ;
F_37 ( & V_2 -> V_12 , V_138 -> V_154 + 10 + V_172 + 1 , & V_175 , 1 ) ;
F_2 ( V_8 L_21 ) ;
F_2 ( V_8 L_22 , V_138 -> V_154 ) ;
F_2 ( V_8 L_23 , V_173 ) ;
F_2 ( V_8 L_24 , V_19 ) ;
F_2 ( V_8 L_25 , V_174 ) ;
F_2 ( V_8 L_26 , V_175 ) ;
F_2 ( V_8 L_27 , V_171 ) ;
F_63 ( L_28 , V_170 , V_172 ) ;
#endif
}
static void F_41 ( struct V_1 * V_2 ,
struct V_137 * V_138 )
{
F_37 ( & V_2 -> V_12 , V_138 -> V_154 , & V_2 -> V_15 . V_16 . V_130 ,
sizeof( V_2 -> V_15 . V_16 . V_130 ) ) ;
F_63 ( L_29 , ( unsigned char * ) & V_2 -> V_15 . V_16 . V_130 ,
sizeof( V_2 -> V_15 . V_16 . V_130 ) ) ;
F_64 ( & V_2 -> V_15 . V_16 . V_130 ) ;
F_65 ( & V_2 -> V_176 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_137 * V_138 )
{
F_2 ( V_8 L_30 ,
V_2 -> V_9 , V_138 -> V_143 ) ;
}
static void F_63 ( char * V_177 , unsigned char * V_178 , int V_85 )
{
unsigned char V_179 [ 1024 ] ,
* V_180 = V_179 ;
if ( V_85 >= ( sizeof( V_179 ) / 2 ) )
V_85 = ( sizeof( V_179 ) / 2 ) - 1 ;
while ( V_85 -- ) {
sprintf ( V_180 , L_31 , * V_178 ++ ) ;
V_180 += 2 ;
}
F_2 ( V_8 L_32 , V_177 , V_179 ) ;
}
static int F_66 ( struct V_1 * V_2 , int V_143 , int V_19 ,
void * V_181 , int V_182 , void * V_183 , int V_184 )
{
struct V_137 V_185 ;
unsigned long V_29 ;
T_7 V_84 = 0x1200 + 0x2E0 * V_19 + 0x1E2 ;
T_6 V_186 = V_187 ;
int V_73 = 0 ;
V_185 . V_143 = V_143 ;
V_185 . V_19 = V_19 ;
V_185 . V_85 = V_182 + V_184 ;
F_67 ( & V_2 -> V_15 . V_16 . V_18 , V_29 ) ;
F_48 ( & V_2 -> V_12 , V_14 , & V_185 , sizeof( V_185 ) - sizeof( V_185 . V_154 ) ) ;
if ( V_181 ) {
F_48 ( & V_2 -> V_12 , V_84 , V_181 , V_182 ) ;
if ( V_183 ) {
if ( V_184 > 254 ) {
T_7 V_188 = 0xA00 + 0x400 * V_19 ;
F_48 ( & V_2 -> V_12 , V_84 + V_182 , V_183 , 249 ) ;
F_48 ( & V_2 -> V_12 , V_188 , ( ( T_6 * ) V_183 ) + 249 ,
V_184 - 249 ) ;
} else
F_48 ( & V_2 -> V_12 , V_84 + V_182 , V_183 , V_184 ) ;
}
}
F_68 ( & V_2 -> V_12 ) ;
do {
V_73 = F_69 ( V_2 -> V_11 ) ;
} while ( V_186 -- && V_73 );
F_70 ( & V_2 -> V_15 . V_16 . V_18 , V_29 ) ;
return V_73 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_4 * V_3 )
{
struct {
T_4 V_189 ;
struct V_4 V_3 [ 2 ] ;
} V_190 ;
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
V_190 . V_189 = 2 ;
V_190 . V_3 [ 0 ] = * V_3 ;
V_190 . V_3 [ 1 ] = * V_3 ;
V_190 . V_3 [ 1 ] . V_19 = 1 ;
V_190 . V_3 [ 1 ] . V_22 = 5 ;
V_190 . V_3 [ 1 ] . clock = 8 ;
V_190 . V_3 [ 1 ] . V_29 = 0 ;
F_71 ( & V_190 . V_3 [ 0 ] ) ;
F_71 ( & V_190 . V_3 [ 1 ] ) ;
return F_66 ( V_2 , V_191 , 0 ,
& V_190 , sizeof( V_190 ) , NULL , 0 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_73 = F_66 ( V_2 , V_147 , 0 , NULL , 20 , NULL , 0 ) ;
if ( V_73 )
return V_73 ;
F_72 ( & V_2 -> V_176 ) ;
if ( F_73 ( V_192 ) )
return - V_193 ;
V_2 -> V_35 . V_130 . V_160 = V_2 -> V_15 . V_16 . V_130 . V_194 ;
V_2 -> V_35 . V_130 . V_195 = V_2 -> V_15 . V_16 . V_130 . V_195 ;
V_2 -> V_35 . V_130 . V_196 = V_2 -> V_15 . V_16 . V_130 . V_196 ;
V_2 -> V_35 . V_130 . V_159 = 0 ;
V_2 -> V_35 . V_130 . V_197 = 0 ;
V_2 -> V_35 . V_130 . V_198 = V_2 -> V_15 . V_16 . V_130 . V_199 ;
V_2 -> V_35 . V_130 . V_158 = 0 ;
V_2 -> V_35 . V_130 . V_200 = 0 ;
V_2 -> V_35 . V_130 . V_201 = V_2 -> V_15 . V_16 . V_130 . V_202 ;
V_2 -> V_35 . V_130 . V_203 = V_2 -> V_15 . V_16 . V_130 . V_204 ;
V_2 -> V_35 . V_130 . V_125 = 0 ;
V_2 -> V_35 . V_130 . V_205 = 0 ;
V_2 -> V_35 . V_130 . V_126 = 0 ;
F_74 ( & V_2 -> V_35 ) ;
return 0 ;
}
static int F_75 ( T_6 * V_206 , T_6 * V_162 , char * V_207 )
{
int V_208 = 0 ;
if ( * V_207 && * V_206 ) {
V_162 [ V_208 ] |= * V_206 ++ - '0' ;
* V_207 = 0 ;
++ V_208 ;
}
while ( * V_206 ) {
V_162 [ V_208 ] = ( * V_206 - '0' ) << 4 ;
if ( * ( V_206 + 1 ) )
V_162 [ V_208 ] |= * ( V_206 + 1 ) - '0' ;
else {
* V_207 = 1 ;
break;
}
++ V_208 ;
V_206 += 2 ;
}
return V_208 ;
}
static void F_57 ( T_6 * V_206 , T_6 * V_162 , T_6 V_85 , T_6 V_207 )
{
if ( V_207 ) {
* V_162 ++ = '0' + ( * V_206 ++ & 0x0F ) ;
-- V_85 ;
}
while ( V_85 ) {
* V_162 ++ = '0' + ( * V_206 >> 4 ) ;
if ( -- V_85 ) {
* V_162 ++ = '0' + ( * V_206 & 0x0F ) ;
-- V_85 ;
} else break;
++ V_206 ;
}
* V_162 = '\0' ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
int V_73 = 0 ,
V_85 ;
char V_162 [ 64 ] ,
V_207 = 0 ,
V_209 = V_72 -> V_83 ? strlen ( V_72 -> V_83 ) : 0 ,
V_210 = strlen ( V_72 -> V_84 ) ;
T_6 V_168 ;
if ( V_2 -> V_15 . V_16 . V_17 == ~ 0U ) {
F_2 ( V_8 L_33
L_34 , V_2 -> V_9 ) ;
return - V_211 ;
}
V_168 = F_77 ( V_2 -> V_15 . V_16 . V_17 ) ;
F_78 ( V_168 , ( void * ) & V_2 -> V_15 . V_16 . V_17 ) ;
++ V_168 ;
F_58 ( 1 , V_8 L_35 , V_2 -> V_9 , V_168 ) ;
memset ( V_162 , 0 , sizeof( V_162 ) ) ;
V_162 [ 1 ] = V_168 ;
V_162 [ 2 ] = 0x10 ;
V_162 [ 4 ] = 0x0B ;
V_85 = F_75 ( V_72 -> V_84 , V_162 + 6 , & V_207 ) ;
if ( V_72 -> V_83 )
V_85 += F_75 ( V_72 -> V_83 , V_162 + 6 + V_85 , & V_207 ) ;
if ( V_207 )
++ V_85 ;
V_162 [ 5 ] = V_209 << 4 | V_210 ;
V_162 [ 6 + V_85 + 1 ] = 0xCC ;
if ( ( V_73 = F_66 ( V_2 , V_212 , V_72 -> V_19 ,
& V_162 , 7 + V_85 + 1 , NULL , 0 ) ) != 0 )
F_61 ( -- V_168 , ( void * ) & V_2 -> V_15 . V_16 . V_17 ) ;
else
V_72 -> V_96 = - V_168 ;
return V_73 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
T_6 V_162 [ 8 ] ;
memset ( V_162 , 0 , sizeof( V_162 ) ) ;
V_162 [ 0 ] = V_162 [ 3 ] = V_72 -> V_96 ;
V_162 [ 2 ] = 0x10 ;
V_162 [ 4 ] = 0x0F ;
V_162 [ 7 ] = 0xCC ;
return F_66 ( V_2 , V_213 , V_72 -> V_19 , & V_162 , 8 , NULL , 0 ) ;
}
static int F_62 ( struct V_1 * V_2 , T_6 V_19 ,
T_6 V_96 )
{
char V_162 [ 5 ] ;
memset ( V_162 , 0 , sizeof( V_162 ) ) ;
V_162 [ 0 ] = V_162 [ 3 ] = V_96 ;
V_162 [ 2 ] = 0x10 ;
V_162 [ 4 ] = 0x17 ;
return F_66 ( V_2 , V_214 , V_19 , & V_162 , 5 , NULL , 0 ) ;
}
static int F_79 ( struct V_1 * V_2 , T_6 V_19 , T_6 V_96 , T_6 V_215 ,
T_6 V_216 )
{
T_6 V_162 [ 7 ] ;
memset ( V_162 , 0 , sizeof( V_162 ) ) ;
V_162 [ 0 ] = V_162 [ 3 ] = V_96 ;
V_162 [ 2 ] = 0x10 ;
V_162 [ 4 ] = 0x13 ;
V_162 [ 5 ] = V_215 ;
V_162 [ 6 ] = V_216 ;
return F_66 ( V_2 , V_217 , V_19 , V_162 , 7 , NULL , 0 ) ;
}
static int F_80 ( struct V_1 * V_2 , T_6 V_19 , T_6 V_96 , T_6 V_155 ,
int V_85 , void * V_154 )
{
T_6 V_162 [] = L_36 ;
V_162 [ 0 ] = V_162 [ 3 ] = V_96 ;
V_162 [ 4 ] = V_155 ;
return F_66 ( V_2 , V_218 , V_19 , & V_162 , 5 , V_154 , V_85 ) ;
}
static struct V_69 * F_49 ( struct V_64 * V_35 ,
T_3 V_96 )
{
struct V_69 * V_70 = V_35 -> V_70 ;
struct V_71 * V_72 ;
while ( V_70 ) {
V_72 = F_10 ( V_70 ) ;
if ( V_72 -> V_96 == V_96 )
break;
V_70 = V_72 -> V_219 ;
}
return V_70 ;
}
static struct V_69 *
F_59 ( struct V_64 * V_35 , char * V_220 )
{
struct V_69 * V_70 = V_35 -> V_70 ;
struct V_71 * V_72 ;
while ( V_70 ) {
V_72 = F_10 ( V_70 ) ;
if ( ! strcmp ( V_72 -> V_84 , V_220 ) )
break;
V_70 = V_72 -> V_219 ;
}
return V_70 ;
}
static int F_30 ( struct V_69 * V_70 )
{
struct V_71 * V_72 = F_10 ( V_70 ) ;
struct V_1 * V_2 = V_72 -> V_2 ;
if ( V_72 -> V_89 ) {
if ( ! V_72 -> V_84 [ 0 ] )
return - V_10 ;
F_58 ( 1 , V_8 L_37 ,
V_2 -> V_9 , V_72 -> V_84 ) ;
if ( F_76 ( V_2 , V_72 ) )
return - V_52 ;
F_19 ( V_70 , V_119 ) ;
return 1 ;
} else
F_19 ( V_70 , V_97 ) ;
return 0 ;
}
static void F_25 ( struct V_69 * V_70 )
{
struct V_71 * V_72 = F_10 ( V_70 ) ;
if ( V_72 -> V_89 ) {
F_79 ( V_72 -> V_2 , V_72 -> V_19 , V_72 -> V_96 , 0 , 0 ) ;
F_19 ( V_70 , V_221 ) ;
} else
F_19 ( V_70 , V_63 ) ;
}
static void V_92 ( unsigned long V_162 )
{
struct V_69 * V_70 = (struct V_69 * ) V_162 ;
struct V_71 * V_72 = F_10 ( V_70 ) ;
if ( V_72 -> V_62 == V_97 )
F_25 ( V_70 ) ;
else
F_2 ( V_87 L_38 ,
V_72 -> V_2 -> V_9 , V_167 , V_70 -> V_74 ) ;
}
static void F_19 ( struct V_69 * V_70 , T_6 V_62 )
{
struct V_71 * V_72 = F_10 ( V_70 ) ;
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned long V_29 ;
char * V_222 = NULL ;
F_67 ( & V_2 -> V_18 , V_29 ) ;
if ( V_72 -> V_62 != V_62 ) {
if ( V_72 -> V_89 && V_72 -> V_62 == V_97 )
F_16 ( & V_72 -> V_90 ) ;
switch ( V_62 ) {
case V_97 :
V_222 = L_39 ;
* ( V_106 * ) V_70 -> V_107 = F_18 ( V_72 -> V_96 ) ;
F_50 ( V_70 ) ;
F_31 ( V_70 ) ;
if ( V_72 -> V_79 == V_80 )
F_81 ( V_70 ,
V_132 ) ;
break;
case V_119 :
V_222 = L_40 ;
break;
case V_221 :
V_222 = L_41 ;
break;
case V_63 :
V_222 = L_42 ;
if ( V_72 -> V_89 ) {
* ( unsigned short * ) V_70 -> V_107 = 0 ;
V_72 -> V_96 = 0 ;
}
if ( V_72 -> V_79 == V_80 )
F_81 ( V_70 ,
V_134 ) ;
F_50 ( V_70 ) ;
break;
}
F_2 ( V_8 L_43 , V_2 -> V_9 ,
V_70 -> V_74 , V_222 ) ;
V_72 -> V_62 = V_62 ;
}
F_70 ( & V_2 -> V_18 , V_29 ) ;
}
static int F_32 ( struct V_69 * V_70 , struct V_120 * V_121 )
{
struct V_71 * V_72 = F_10 ( V_70 ) ;
struct V_1 * V_2 = V_72 -> V_2 ;
int V_155 = 0 ;
unsigned V_85 = V_121 -> V_85 ;
if ( V_121 -> V_85 > V_2 -> V_35 . V_34 ) {
V_85 = V_2 -> V_35 . V_34 ;
V_155 = 0x10 ;
}
if ( F_80 ( V_2 , V_72 -> V_19 , V_72 -> V_96 , V_155 , V_85 , V_121 -> V_93 ) )
return 1 ;
if ( V_155 ) {
F_33 ( V_121 , V_85 ) ;
return 1 ;
}
++ V_72 -> V_124 . V_201 ;
V_72 -> V_124 . V_223 += V_85 ;
return 0 ;
}
static void F_81 ( struct V_69 * V_70 , T_6 V_224 )
{
struct V_120 * V_121 ;
unsigned char * V_225 ;
if ( ( V_121 = F_51 ( 1 ) ) == NULL ) {
F_2 ( V_87 L_44 , V_167 ) ;
return;
}
V_225 = F_52 ( V_121 , 1 ) ;
* V_225 = V_224 ;
V_121 -> V_79 = F_82 ( V_121 , V_70 ) ;
F_56 ( V_121 ) ;
}
static T_6 F_4 ( T_7 V_23 )
{
T_6 V_226 = 0 ;
if ( V_23 >= 512000 ) V_226 = 8 ;
else if ( V_23 >= 256000 ) V_226 = 7 ;
else if ( V_23 >= 64000 ) V_226 = 6 ;
else if ( V_23 >= 38400 ) V_226 = 5 ;
else if ( V_23 >= 19200 ) V_226 = 4 ;
else if ( V_23 >= 9600 ) V_226 = 3 ;
else if ( V_23 >= 4800 ) V_226 = 2 ;
else if ( V_23 >= 2400 ) V_226 = 1 ;
return V_226 ;
}
static T_6 F_5 ( T_7 V_227 )
{
T_6 log = 0 ;
if ( ! V_227 )
return 0 ;
while ( V_227 > 1 ) {
V_227 >>= 1 ;
++ log ;
}
return log ;
}
static unsigned F_13 ( T_6 * V_228 , int V_85 )
{
unsigned V_229 = 0 ;
if ( ! V_85 )
V_85 = strlen ( V_228 ) ;
for (; V_85 && isdigit ( * V_228 ) ; ++ V_228 , -- V_85 )
V_229 = ( V_229 * 10 ) + ( * V_228 - ( unsigned ) '0' ) ;
return V_229 ;
}
static void F_31 ( struct V_69 * V_70 )
{
struct V_71 * V_72 = F_10 ( V_70 ) ;
if ( V_72 -> V_89 )
F_83 ( & V_72 -> V_90 , V_129 + V_72 -> V_94 * V_230 ) ;
}
static void F_71 ( struct V_4 * V_3 )
{
F_2 ( V_8 L_45 ) ;
F_2 ( V_8 L_46 ) ;
F_2 ( V_8 L_47 , V_3 -> V_19 ) ;
F_2 ( V_8 L_48 , V_3 -> V_22 ) ;
F_2 ( V_8 L_49 , V_3 -> clock == 8 ? L_50 : L_51 ) ;
F_2 ( V_8 L_52 , V_3 -> V_26 ) ;
F_2 ( V_8 L_53 , V_3 -> V_25 ) ;
F_2 ( V_8 L_54 , V_3 -> V_24 ) ;
F_2 ( V_8 L_55 , V_3 -> V_27 ) ;
F_2 ( V_8 L_56 , V_3 -> V_36 ) ;
F_2 ( V_8 L_57 , V_3 -> V_39 ) ;
F_2 ( V_8 L_58 , V_3 -> V_40 ) ;
F_2 ( V_8 L_59 , V_3 -> V_30 ) ;
F_2 ( V_8 L_60 , V_3 -> V_31 ) ;
F_2 ( V_8 L_61 , V_3 -> V_32 ) ;
F_2 ( V_8 L_62 , V_3 -> V_28 ) ;
F_2 ( V_8 L_63 , V_3 -> V_33 ) ;
F_2 ( V_8 L_64 , V_3 -> V_29 ) ;
}
static void F_64 ( struct V_231 * V_130 )
{
F_2 ( V_8 L_65 ) ;
F_2 ( V_8 L_66 ) ;
F_2 ( V_8 L_67 , V_130 -> V_196 ) ;
F_2 ( V_8 L_68 , V_130 -> V_195 ) ;
F_2 ( V_8 L_69 , V_130 -> V_202 ) ;
F_2 ( V_8 L_70 , V_130 -> V_194 ) ;
F_2 ( V_8 L_71 , V_130 -> V_232 ) ;
F_2 ( V_8 L_72 , V_130 -> V_233 ) ;
F_2 ( V_8 L_73 , V_130 -> V_234 ) ;
F_2 ( V_8 L_74 , V_130 -> V_235 ) ;
F_2 ( V_8 L_75 , V_130 -> V_204 ) ;
F_2 ( V_8 L_76 , V_130 -> V_199 ) ;
}
static void F_74 ( struct V_64 * V_35 )
{
struct V_69 * V_70 = V_35 -> V_70 ;
F_2 ( V_8 L_77 ) ;
F_2 ( V_8 L_78 ) ;
F_2 ( V_8 L_79 ) ;
while( V_70 ) {
struct V_71 * V_72 = F_10 ( V_70 ) ;
F_2 ( V_8 L_80 ,
V_72 -> V_74 , V_72 -> V_84 , F_84 ( V_70 ) ,
V_72 -> V_79 == V_81 ? L_81 : L_82 ) ;
V_70 = V_72 -> V_219 ;
}
}
