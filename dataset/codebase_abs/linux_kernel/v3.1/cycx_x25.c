int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 V_5 ;
if ( V_3 -> V_6 != V_7 ) {
F_2 ( L_1 ,
V_2 -> V_8 , V_3 -> V_6 ) ;
return - V_9 ;
}
V_2 -> V_10 = V_2 -> V_11 . V_12 + V_13 ;
V_2 -> V_14 . V_15 . V_16 = 0 ;
F_3 ( & V_2 -> V_14 . V_15 . V_17 ) ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_18 = 0 ;
V_5 . clock = V_3 -> V_19 == V_20 ? 8 : 55 ;
V_5 . V_21 = F_4 ( V_3 -> V_22 ) ;
V_5 . V_23 = 7 ;
V_5 . V_24 = 2 ;
V_5 . V_25 = 5 ;
V_5 . V_26 = 1 ;
V_5 . V_27 = 1 ;
V_5 . V_28 = 0x02 ;
V_5 . V_29 = 10 ;
V_5 . V_30 = 29 ;
V_5 . V_31 = 180 ;
V_5 . V_32 = 180 ;
if ( ! V_3 -> V_33 || V_3 -> V_33 >= 512 )
V_2 -> V_34 . V_33 = 512 ;
else if ( V_3 -> V_33 >= 256 )
V_2 -> V_34 . V_33 = 256 ;
else if ( V_3 -> V_33 >= 128 )
V_2 -> V_34 . V_33 = 128 ;
else
V_2 -> V_34 . V_33 = 64 ;
V_5 . V_35 = F_5 ( V_2 -> V_34 . V_33 ) ;
if ( V_3 -> V_36 == V_37 ) {
V_5 . V_38 = 3 ;
V_5 . V_39 = 1 ;
} else {
V_5 . V_38 = 1 ;
V_5 . V_39 = 3 ;
}
if ( V_3 -> V_40 == V_41 )
V_5 . V_28 = 0 ;
if ( V_3 -> V_14 . V_42 . V_43 ) {
V_2 -> V_14 . V_15 . V_43 = F_6 (unsigned int, conf->u.x25.hi_pvc, 4095 ) ;
V_2 -> V_14 . V_15 . V_44 = F_6 (unsigned int, conf->u.x25.lo_pvc, card->u.x.hi_pvc) ;
}
if ( V_3 -> V_14 . V_42 . V_45 ) {
V_2 -> V_14 . V_15 . V_45 = F_6 (unsigned int, conf->u.x25.hi_svc, 4095 ) ;
V_2 -> V_14 . V_15 . V_46 = F_6 (unsigned int, conf->u.x25.lo_svc, card->u.x.hi_svc) ;
}
if ( V_2 -> V_14 . V_15 . V_44 == 255 )
V_5 . V_27 = 0 ;
else
V_5 . V_27 = V_2 -> V_14 . V_15 . V_43 - V_2 -> V_14 . V_15 . V_44 + 1 ;
V_5 . V_26 = V_2 -> V_14 . V_15 . V_45 - V_2 -> V_14 . V_15 . V_46 + 1 + V_5 . V_27 ;
if ( V_3 -> V_14 . V_42 . V_47 )
V_5 . V_24 = F_6 (unsigned int, conf->u.x25.hdlc_window, 7 ) ;
if ( V_3 -> V_14 . V_42 . V_48 )
V_5 . V_23 = F_6 (unsigned int, conf->u.x25.pkt_window, 7 ) ;
if ( V_3 -> V_14 . V_42 . V_29 )
V_5 . V_29 = F_6 (unsigned int, conf->u.x25.t1, 30 ) ;
if ( V_3 -> V_14 . V_42 . V_30 )
V_5 . V_30 = F_6 (unsigned int, conf->u.x25.t2, 30 ) ;
if ( V_3 -> V_14 . V_42 . V_49 )
V_5 . V_31 = F_6 (unsigned int, conf->u.x25.t11_t21, 30 ) ;
if ( V_3 -> V_14 . V_42 . V_50 )
V_5 . V_32 = F_6 (unsigned int, conf->u.x25.t13_t23, 30 ) ;
if ( V_3 -> V_14 . V_42 . V_25 )
V_5 . V_25 = F_6 (unsigned int, conf->u.x25.n2, 30 ) ;
if ( F_7 ( V_2 , & V_5 ) )
return - V_51 ;
V_2 -> V_34 . V_22 = V_3 -> V_22 ;
V_2 -> V_34 . V_40 = V_3 -> V_40 ;
V_2 -> V_34 . V_19 = V_3 -> V_19 ;
V_2 -> V_34 . V_36 = V_3 -> V_36 ;
V_2 -> V_52 = V_53 ;
V_2 -> V_54 = NULL ;
V_2 -> V_34 . V_55 = V_56 ;
V_2 -> V_34 . V_57 = V_58 ;
V_2 -> V_34 . V_59 = V_60 ;
V_2 -> V_34 . V_61 = V_62 ;
return 0 ;
}
static int V_56 ( struct V_63 * V_34 )
{
if ( ! V_34 || ! V_34 -> V_64 )
return - V_65 ;
if ( V_34 -> V_61 == V_66 )
return - V_67 ;
F_8 ( V_34 -> V_64 ) ;
return 0 ;
}
static int V_58 ( struct V_63 * V_34 , struct V_68 * V_69 ,
T_2 * V_3 )
{
struct V_1 * V_2 = V_34 -> V_64 ;
struct V_70 * V_71 ;
int V_72 = 0 ;
if ( ! V_3 -> V_73 [ 0 ] || strlen ( V_3 -> V_73 ) > V_74 ) {
F_2 ( L_2 , V_2 -> V_8 ) ;
return - V_9 ;
}
V_69 = F_9 ( sizeof( struct V_70 ) , V_3 -> V_73 ,
V_75 ) ;
if ( ! V_69 )
return - V_76 ;
V_71 = F_10 ( V_69 ) ;
strcpy ( V_71 -> V_73 , V_3 -> V_73 ) ;
V_71 -> V_2 = V_2 ;
V_71 -> V_18 = V_3 -> V_77 ;
V_71 -> V_78 = V_3 -> V_78 ? V_79 : V_80 ;
V_71 -> V_81 = NULL ;
V_71 -> V_82 = NULL ;
if ( V_3 -> V_83 [ 0 ] == '@' ) {
int V_84 = strlen ( V_3 -> V_82 ) ;
if ( V_84 ) {
if ( V_84 > V_85 ) {
F_11 ( L_3 ,
V_34 -> V_73 , V_71 -> V_73 ) ;
V_72 = - V_9 ;
goto error;
} else {
V_71 -> V_82 = F_12 ( V_84 + 1 , V_86 ) ;
if ( ! V_71 -> V_82 ) {
V_72 = - V_76 ;
goto error;
}
}
strncpy ( V_71 -> V_82 , V_3 -> V_82 ,
V_85 ) ;
}
V_71 -> V_87 = 1 ;
strncpy ( V_71 -> V_83 , & V_3 -> V_83 [ 1 ] , V_85 ) ;
F_13 ( & V_71 -> V_88 ) ;
V_71 -> V_88 . V_89 = V_90 ;
V_71 -> V_88 . V_91 = ( unsigned long ) V_69 ;
V_71 -> V_92 = V_3 -> V_93 ? V_3 -> V_93 : 90 ;
} else if ( isdigit ( V_3 -> V_83 [ 0 ] ) ) {
T_3 V_94 = F_14 ( V_3 -> V_83 , 0 ) ;
if ( V_94 >= V_2 -> V_14 . V_15 . V_44 && V_94 <= V_2 -> V_14 . V_15 . V_43 )
V_71 -> V_94 = V_94 ;
else {
F_11 ( L_4 ,
V_34 -> V_73 , V_94 , V_71 -> V_73 ) ;
V_72 = - V_9 ;
goto error;
}
} else {
F_11 ( L_5 ,
V_34 -> V_73 , V_71 -> V_73 ) ;
V_72 = - V_9 ;
goto error;
}
return 0 ;
error:
F_15 ( V_69 ) ;
return V_72 ;
}
static int V_60 ( struct V_63 * V_34 , struct V_68 * V_69 )
{
struct V_70 * V_71 = F_10 ( V_69 ) ;
if ( V_71 -> V_87 ) {
F_16 ( V_71 -> V_82 ) ;
if ( V_71 -> V_61 == V_95 )
F_17 ( & V_71 -> V_88 ) ;
}
return 0 ;
}
static void V_75 ( struct V_68 * V_69 )
{
V_69 -> V_96 = & V_97 ;
V_69 -> V_98 = & V_99 ;
V_69 -> V_33 = V_100 ;
V_69 -> type = V_101 ;
V_69 -> V_102 = 0 ;
V_69 -> V_103 = 0 ;
}
static int F_18 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = F_10 ( V_69 ) ;
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_63 * V_34 = & V_2 -> V_34 ;
if ( ! V_71 -> V_87 )
* ( V_104 * ) V_69 -> V_105 = F_19 ( V_71 -> V_94 ) ;
V_69 -> V_106 = V_34 -> V_106 ;
V_69 -> V_107 = V_34 -> V_107 ;
V_69 -> V_108 = V_34 -> V_109 ;
V_69 -> V_110 = ( unsigned long ) V_34 -> V_111 ;
V_69 -> V_112 = ( unsigned long ) ( V_34 -> V_111 +
V_34 -> V_113 - 1 ) ;
V_69 -> V_28 |= V_114 ;
V_69 -> V_115 = 10 ;
F_20 ( V_69 , V_62 ) ;
return 0 ;
}
static int F_21 ( struct V_68 * V_69 )
{
if ( F_22 ( V_69 ) )
return - V_116 ;
F_23 ( V_69 ) ;
return 0 ;
}
static int F_24 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = F_10 ( V_69 ) ;
F_25 ( V_69 ) ;
if ( V_71 -> V_61 == V_95 || V_71 -> V_61 == V_117 )
F_26 ( V_69 ) ;
return 0 ;
}
static int F_27 ( struct V_118 * V_119 ,
struct V_68 * V_69 , T_4 type ,
const void * V_120 , const void * V_121 ,
unsigned V_84 )
{
V_119 -> V_78 = F_19 ( type ) ;
return V_69 -> V_102 ;
}
static int F_28 ( struct V_118 * V_119 )
{
return 1 ;
}
static T_5 F_29 ( struct V_118 * V_119 ,
struct V_68 * V_69 )
{
struct V_70 * V_71 = F_10 ( V_69 ) ;
struct V_1 * V_2 = V_71 -> V_2 ;
if ( ! V_71 -> V_87 )
V_71 -> V_78 = F_30 ( V_119 -> V_78 ) ;
if ( V_2 -> V_34 . V_61 != V_95 )
++ V_71 -> V_122 . V_123 ;
else if ( V_71 -> V_87 && V_71 -> V_78 &&
V_71 -> V_78 != F_30 ( V_119 -> V_78 ) ) {
F_2 ( L_6 ,
V_2 -> V_8 , F_30 ( V_119 -> V_78 ) , V_69 -> V_73 ) ;
++ V_71 -> V_122 . V_124 ;
} else if ( V_71 -> V_78 == V_80 ) {
switch ( V_71 -> V_61 ) {
case V_62 :
if ( F_31 ( V_69 ) ) {
F_25 ( V_69 ) ;
return V_125 ;
}
case V_95 :
F_32 ( V_69 ) ;
V_69 -> V_126 = V_127 ;
F_25 ( V_69 ) ;
if ( F_33 ( V_69 , V_119 ) )
return V_125 ;
break;
default:
++ V_71 -> V_122 . V_123 ;
++ V_2 -> V_34 . V_128 . V_123 ;
}
} else {
switch ( V_119 -> V_91 [ 0 ] ) {
case V_129 :
break;
case V_130 :
F_31 ( V_69 ) ;
goto V_131;
case V_132 :
F_26 ( V_69 ) ;
goto V_131;
default:
F_2 ( L_7 ,
V_2 -> V_8 , V_119 -> V_91 [ 0 ] , V_69 -> V_73 ) ;
++ V_71 -> V_122 . V_124 ;
goto V_131;
}
F_34 ( V_119 , 1 ) ;
F_32 ( V_69 ) ;
V_69 -> V_126 = V_127 ;
F_25 ( V_69 ) ;
if ( F_33 ( V_69 , V_119 ) ) {
F_35 ( V_119 , 1 ) ;
return V_125 ;
}
}
V_131:
F_36 ( V_119 ) ;
return V_133 ;
}
static struct V_134 * F_37 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = F_10 ( V_69 ) ;
return V_71 ? & V_71 -> V_122 : NULL ;
}
static void V_53 ( struct V_1 * V_2 )
{
struct V_135 V_136 ;
T_4 V_137 = 0 ;
V_2 -> V_138 = 1 ;
V_2 -> V_139 = 0 ;
F_38 ( & V_2 -> V_11 , V_140 , & V_136 , sizeof( V_136 ) ) ;
switch ( V_136 . V_141 ) {
case V_142 :
F_39 ( V_2 , & V_136 ) ;
break;
case V_143 :
F_40 ( V_2 , & V_136 ) ;
break;
case V_144 :
F_41 ( V_2 , & V_136 ) ;
break;
case V_145 :
F_42 ( V_2 , & V_136 ) ;
break;
case V_146 :
F_43 ( V_2 , & V_136 ) ;
break;
case V_147 :
F_44 ( V_2 , & V_136 ) ;
break;
case V_148 :
F_45 ( V_2 , & V_136 ) ;
break;
case V_149 :
F_46 ( V_2 , & V_136 ) ;
break;
case V_150 :
F_47 ( V_2 , V_95 ) ;
break;
case V_151 :
F_47 ( V_2 , V_62 ) ;
break;
default:
F_48 ( V_2 , & V_136 ) ;
break;
}
F_49 ( & V_2 -> V_11 , 0 , & V_137 , sizeof( V_137 ) ) ;
F_49 ( & V_2 -> V_11 , V_140 , & V_137 , sizeof( V_137 ) ) ;
V_2 -> V_138 = 0 ;
}
static void F_40 ( struct V_1 * V_2 , struct V_135 * V_136 )
{
struct V_68 * V_69 ;
struct V_63 * V_34 = & V_2 -> V_34 ;
T_6 V_94 ;
F_38 ( & V_2 -> V_11 , V_136 -> V_152 , & V_94 , sizeof( V_94 ) ) ;
V_69 = F_50 ( V_34 , V_94 ) ;
if ( V_69 ) {
V_2 -> V_139 = 1 ;
F_51 ( V_69 ) ;
} else
F_11 ( L_8 , V_2 -> V_8 , V_94 ) ;
}
static void F_39 ( struct V_1 * V_2 , struct V_135 * V_136 )
{
struct V_63 * V_34 = & V_2 -> V_34 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
struct V_118 * V_119 ;
T_6 V_153 , V_94 ;
int V_35 = V_136 -> V_84 - 5 ;
F_38 ( & V_2 -> V_11 , V_136 -> V_152 , & V_94 , sizeof( V_94 ) ) ;
F_38 ( & V_2 -> V_11 , V_136 -> V_152 + 4 , & V_153 , sizeof( V_153 ) ) ;
V_153 &= 0x10 ;
V_69 = F_50 ( V_34 , V_94 ) ;
if ( ! V_69 ) {
F_2 ( L_9 ,
V_2 -> V_8 , V_94 ) ;
return;
}
V_71 = F_10 ( V_69 ) ;
F_32 ( V_69 ) ;
if ( V_71 -> V_154 ) {
if ( ! V_153 )
V_71 -> V_154 = 0 ;
else
return;
}
if ( ( V_119 = V_71 -> V_81 ) == NULL ) {
int V_155 = V_153 ? V_69 -> V_33 : V_35 ;
if ( ( V_119 = F_52 ( ( V_71 -> V_78 == V_79 ? 1 : 0 ) +
V_155 +
V_69 -> V_102 ) ) == NULL ) {
F_2 ( L_10 ,
V_2 -> V_8 ) ;
V_71 -> V_154 = 1 ;
++ V_71 -> V_122 . V_156 ;
return;
}
if ( V_71 -> V_78 == V_79 )
F_53 ( V_119 , 1 ) ;
V_119 -> V_69 = V_69 ;
V_119 -> V_78 = F_19 ( V_71 -> V_78 ) ;
V_71 -> V_81 = V_119 ;
}
if ( F_54 ( V_119 ) < V_35 ) {
F_55 ( V_119 ) ;
V_71 -> V_81 = NULL ;
if ( V_153 )
V_71 -> V_154 = 1 ;
F_2 ( L_11 ,
V_2 -> V_8 , V_69 -> V_73 ) ;
++ V_71 -> V_122 . V_157 ;
return;
}
F_38 ( & V_2 -> V_11 , V_136 -> V_152 + 5 , F_53 ( V_119 , V_35 ) , V_35 ) ;
if ( V_153 )
return;
V_71 -> V_81 = NULL ;
++ V_71 -> V_122 . V_158 ;
V_71 -> V_122 . V_159 += V_35 ;
F_56 ( V_119 ) ;
F_57 ( V_119 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
struct V_63 * V_34 = & V_2 -> V_34 ;
struct V_68 * V_69 = NULL ;
struct V_70 * V_71 ;
T_6 V_160 [ 32 ] ,
V_161 [ 24 ] ,
V_162 [ 24 ] ;
T_6 V_94 , V_163 , V_164 ;
F_38 ( & V_2 -> V_11 , V_136 -> V_152 , & V_94 , sizeof( V_94 ) ) ;
F_38 ( & V_2 -> V_11 , V_136 -> V_152 + 5 , & V_163 , sizeof( V_163 ) ) ;
F_38 ( & V_2 -> V_11 , V_136 -> V_152 + 6 , V_160 , V_136 -> V_84 - 6 ) ;
V_164 = V_163 >> 4 ;
V_163 &= 0x0F ;
V_161 [ 0 ] = V_162 [ 0 ] = '\0' ;
if ( V_163 )
F_58 ( V_160 , V_161 , V_163 , 0 ) ;
if ( V_164 )
F_58 ( V_160 + ( V_163 >> 1 ) , V_162 , V_164 , V_163 & 1 ) ;
F_59 ( 1 , V_165 L_12 ,
V_166 , V_94 , V_161 , V_162 ) ;
V_69 = F_60 ( V_34 , V_162 ) ;
if ( ! V_69 ) {
F_2 ( L_13 ,
V_2 -> V_8 , V_162 ) ;
return;
}
V_71 = F_10 ( V_69 ) ;
V_71 -> V_94 = V_94 ;
F_61 ( V_2 , V_71 ) ;
F_20 ( V_69 , V_95 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
struct V_63 * V_34 = & V_2 -> V_34 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
T_6 V_94 , V_167 ;
F_38 ( & V_2 -> V_11 , V_136 -> V_152 , & V_94 , sizeof( V_94 ) ) ;
F_38 ( & V_2 -> V_11 , V_136 -> V_152 + 1 , & V_167 , sizeof( V_167 ) ) ;
F_59 ( 1 , V_165 L_14 ,
V_2 -> V_8 , V_166 , V_94 , V_167 ) ;
V_69 = F_50 ( V_34 , - V_167 ) ;
if ( ! V_69 ) {
F_62 ( -- V_167 , ( void * ) & V_2 -> V_14 . V_15 . V_16 ) ;
F_2 ( L_15 ,
V_2 -> V_8 , V_94 , V_167 ) ;
return;
}
F_62 ( -- V_167 , ( void * ) & V_2 -> V_14 . V_15 . V_16 ) ;
V_71 = F_10 ( V_69 ) ;
V_71 -> V_94 = V_94 ;
F_20 ( V_69 , V_95 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
struct V_63 * V_34 = & V_2 -> V_34 ;
struct V_68 * V_69 ;
T_6 V_94 ;
F_38 ( & V_2 -> V_11 , V_136 -> V_152 , & V_94 , sizeof( V_94 ) ) ;
F_59 ( 1 , V_165 L_16 ,
V_2 -> V_8 , V_166 , V_94 ) ;
V_69 = F_50 ( V_34 , V_94 ) ;
if ( ! V_69 ) {
F_2 ( L_17 ,
V_2 -> V_8 , V_94 ) ;
return;
}
F_20 ( V_69 , V_62 ) ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
struct V_63 * V_34 = & V_2 -> V_34 ;
struct V_68 * V_69 ;
T_6 V_94 ;
F_38 ( & V_2 -> V_11 , V_136 -> V_152 , & V_94 , sizeof( V_94 ) ) ;
F_59 ( 1 , V_165 L_18 , V_166 , V_94 ) ;
V_69 = F_50 ( V_34 , V_94 ) ;
if ( V_69 ) {
struct V_70 * V_71 = F_10 ( V_69 ) ;
F_63 ( V_2 , V_71 -> V_18 , V_94 ) ;
F_20 ( V_69 , V_62 ) ;
} else
F_63 ( V_2 , 0 , V_94 ) ;
}
static void F_41 ( struct V_1 * V_2 , struct V_135 * V_136 )
{
#if V_168
char V_169 [ 20 ] ;
T_4 V_170 , V_171 , V_18 , V_172 ;
T_6 V_173 , V_174 ;
F_38 ( & V_2 -> V_11 , V_136 -> V_152 , & V_172 , sizeof( V_172 ) ) ;
F_38 ( & V_2 -> V_11 , V_136 -> V_152 + 2 , & V_18 , sizeof( V_18 ) ) ;
F_38 ( & V_2 -> V_11 , V_136 -> V_152 + 4 , & V_170 , sizeof( V_170 ) ) ;
V_171 = V_170 < 20 ? V_170 : 20 ;
F_38 ( & V_2 -> V_11 , V_136 -> V_152 + 10 , & V_169 , V_171 ) ;
F_38 ( & V_2 -> V_11 , V_136 -> V_152 + 10 + V_171 , & V_173 , 1 ) ;
F_38 ( & V_2 -> V_11 , V_136 -> V_152 + 10 + V_171 + 1 , & V_174 , 1 ) ;
F_2 ( L_19 ) ;
F_2 ( L_20 , V_136 -> V_152 ) ;
F_2 ( L_21 , V_172 ) ;
F_2 ( L_22 , V_18 ) ;
F_2 ( L_23 , V_173 ) ;
F_2 ( L_24 , V_174 ) ;
F_2 ( L_25 , V_170 ) ;
F_64 ( L_26 , V_169 , V_171 ) ;
#endif
}
static void F_42 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
F_38 ( & V_2 -> V_11 , V_136 -> V_152 , & V_2 -> V_14 . V_15 . V_128 ,
sizeof( V_2 -> V_14 . V_15 . V_128 ) ) ;
F_64 ( L_27 , ( unsigned char * ) & V_2 -> V_14 . V_15 . V_128 ,
sizeof( V_2 -> V_14 . V_15 . V_128 ) ) ;
F_65 ( & V_2 -> V_14 . V_15 . V_128 ) ;
F_66 ( & V_2 -> V_175 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
F_2 ( L_28 ,
V_2 -> V_8 , V_136 -> V_141 ) ;
}
static void F_64 ( char * V_176 , unsigned char * V_177 , int V_84 )
{
F_67 ( V_165 , V_176 , V_178 , 16 , 1 ,
V_177 , V_84 , true ) ;
}
static int F_68 ( struct V_1 * V_2 , int V_141 , int V_18 ,
void * V_179 , int V_180 , void * V_181 , int V_182 )
{
struct V_135 V_183 ;
unsigned long V_28 ;
T_7 V_83 = 0x1200 + 0x2E0 * V_18 + 0x1E2 ;
T_6 V_184 = V_185 ;
int V_72 = 0 ;
V_183 . V_141 = V_141 ;
V_183 . V_18 = V_18 ;
V_183 . V_84 = V_180 + V_182 ;
F_69 ( & V_2 -> V_14 . V_15 . V_17 , V_28 ) ;
F_49 ( & V_2 -> V_11 , V_13 , & V_183 , sizeof( V_183 ) - sizeof( V_183 . V_152 ) ) ;
if ( V_179 ) {
F_49 ( & V_2 -> V_11 , V_83 , V_179 , V_180 ) ;
if ( V_181 ) {
if ( V_182 > 254 ) {
T_7 V_186 = 0xA00 + 0x400 * V_18 ;
F_49 ( & V_2 -> V_11 , V_83 + V_180 , V_181 , 249 ) ;
F_49 ( & V_2 -> V_11 , V_186 , ( ( T_6 * ) V_181 ) + 249 ,
V_182 - 249 ) ;
} else
F_49 ( & V_2 -> V_11 , V_83 + V_180 , V_181 , V_182 ) ;
}
}
F_70 ( & V_2 -> V_11 ) ;
do {
V_72 = F_71 ( V_2 -> V_10 ) ;
} while ( V_184 -- && V_72 );
F_72 ( & V_2 -> V_14 . V_15 . V_17 , V_28 ) ;
return V_72 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_4 * V_3 )
{
struct {
T_4 V_187 ;
struct V_4 V_3 [ 2 ] ;
} V_188 ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
V_188 . V_187 = 2 ;
V_188 . V_3 [ 0 ] = * V_3 ;
V_188 . V_3 [ 1 ] = * V_3 ;
V_188 . V_3 [ 1 ] . V_18 = 1 ;
V_188 . V_3 [ 1 ] . V_21 = 5 ;
V_188 . V_3 [ 1 ] . clock = 8 ;
V_188 . V_3 [ 1 ] . V_28 = 0 ;
F_73 ( & V_188 . V_3 [ 0 ] ) ;
F_73 ( & V_188 . V_3 [ 1 ] ) ;
return F_68 ( V_2 , V_189 , 0 ,
& V_188 , sizeof( V_188 ) , NULL , 0 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_72 = F_68 ( V_2 , V_145 , 0 , NULL , 20 , NULL , 0 ) ;
if ( V_72 )
return V_72 ;
F_74 ( & V_2 -> V_175 ) ;
if ( F_75 ( V_190 ) )
return - V_191 ;
V_2 -> V_34 . V_128 . V_158 = V_2 -> V_14 . V_15 . V_128 . V_192 ;
V_2 -> V_34 . V_128 . V_193 = V_2 -> V_14 . V_15 . V_128 . V_193 ;
V_2 -> V_34 . V_128 . V_194 = V_2 -> V_14 . V_15 . V_128 . V_194 ;
V_2 -> V_34 . V_128 . V_157 = 0 ;
V_2 -> V_34 . V_128 . V_195 = 0 ;
V_2 -> V_34 . V_128 . V_196 = V_2 -> V_14 . V_15 . V_128 . V_197 ;
V_2 -> V_34 . V_128 . V_156 = 0 ;
V_2 -> V_34 . V_128 . V_198 = 0 ;
V_2 -> V_34 . V_128 . V_199 = V_2 -> V_14 . V_15 . V_128 . V_200 ;
V_2 -> V_34 . V_128 . V_201 = V_2 -> V_14 . V_15 . V_128 . V_202 ;
V_2 -> V_34 . V_128 . V_123 = 0 ;
V_2 -> V_34 . V_128 . V_203 = 0 ;
V_2 -> V_34 . V_128 . V_124 = 0 ;
F_76 ( & V_2 -> V_34 ) ;
return 0 ;
}
static int F_77 ( T_6 * V_204 , T_6 * V_160 , char * V_205 )
{
int V_206 = 0 ;
if ( * V_205 && * V_204 ) {
V_160 [ V_206 ] |= * V_204 ++ - '0' ;
* V_205 = 0 ;
++ V_206 ;
}
while ( * V_204 ) {
V_160 [ V_206 ] = ( * V_204 - '0' ) << 4 ;
if ( * ( V_204 + 1 ) )
V_160 [ V_206 ] |= * ( V_204 + 1 ) - '0' ;
else {
* V_205 = 1 ;
break;
}
++ V_206 ;
V_204 += 2 ;
}
return V_206 ;
}
static void F_58 ( T_6 * V_204 , T_6 * V_160 , T_6 V_84 , T_6 V_205 )
{
if ( V_205 ) {
* V_160 ++ = '0' + ( * V_204 ++ & 0x0F ) ;
-- V_84 ;
}
while ( V_84 ) {
* V_160 ++ = '0' + ( * V_204 >> 4 ) ;
if ( -- V_84 ) {
* V_160 ++ = '0' + ( * V_204 & 0x0F ) ;
-- V_84 ;
} else break;
++ V_204 ;
}
* V_160 = '\0' ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
int V_72 = 0 ,
V_84 ;
char V_160 [ 64 ] ,
V_205 = 0 ,
V_207 = V_71 -> V_82 ? strlen ( V_71 -> V_82 ) : 0 ,
V_208 = strlen ( V_71 -> V_83 ) ;
T_6 V_167 ;
if ( V_2 -> V_14 . V_15 . V_16 == ~ 0U ) {
F_2 ( L_29 ,
V_2 -> V_8 ) ;
return - V_209 ;
}
V_167 = F_79 ( V_2 -> V_14 . V_15 . V_16 ) ;
F_80 ( V_167 , ( void * ) & V_2 -> V_14 . V_15 . V_16 ) ;
++ V_167 ;
F_59 ( 1 , V_165 L_30 , V_2 -> V_8 , V_167 ) ;
memset ( V_160 , 0 , sizeof( V_160 ) ) ;
V_160 [ 1 ] = V_167 ;
V_160 [ 2 ] = 0x10 ;
V_160 [ 4 ] = 0x0B ;
V_84 = F_77 ( V_71 -> V_83 , V_160 + 6 , & V_205 ) ;
if ( V_71 -> V_82 )
V_84 += F_77 ( V_71 -> V_82 , V_160 + 6 + V_84 , & V_205 ) ;
if ( V_205 )
++ V_84 ;
V_160 [ 5 ] = V_207 << 4 | V_208 ;
V_160 [ 6 + V_84 + 1 ] = 0xCC ;
if ( ( V_72 = F_68 ( V_2 , V_210 , V_71 -> V_18 ,
& V_160 , 7 + V_84 + 1 , NULL , 0 ) ) != 0 )
F_62 ( -- V_167 , ( void * ) & V_2 -> V_14 . V_15 . V_16 ) ;
else
V_71 -> V_94 = - V_167 ;
return V_72 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
T_6 V_160 [ 8 ] ;
memset ( V_160 , 0 , sizeof( V_160 ) ) ;
V_160 [ 0 ] = V_160 [ 3 ] = V_71 -> V_94 ;
V_160 [ 2 ] = 0x10 ;
V_160 [ 4 ] = 0x0F ;
V_160 [ 7 ] = 0xCC ;
return F_68 ( V_2 , V_211 , V_71 -> V_18 , & V_160 , 8 , NULL , 0 ) ;
}
static int F_63 ( struct V_1 * V_2 , T_6 V_18 ,
T_6 V_94 )
{
char V_160 [ 5 ] ;
memset ( V_160 , 0 , sizeof( V_160 ) ) ;
V_160 [ 0 ] = V_160 [ 3 ] = V_94 ;
V_160 [ 2 ] = 0x10 ;
V_160 [ 4 ] = 0x17 ;
return F_68 ( V_2 , V_212 , V_18 , & V_160 , 5 , NULL , 0 ) ;
}
static int F_81 ( struct V_1 * V_2 , T_6 V_18 , T_6 V_94 , T_6 V_213 ,
T_6 V_214 )
{
T_6 V_160 [ 7 ] ;
memset ( V_160 , 0 , sizeof( V_160 ) ) ;
V_160 [ 0 ] = V_160 [ 3 ] = V_94 ;
V_160 [ 2 ] = 0x10 ;
V_160 [ 4 ] = 0x13 ;
V_160 [ 5 ] = V_213 ;
V_160 [ 6 ] = V_214 ;
return F_68 ( V_2 , V_215 , V_18 , V_160 , 7 , NULL , 0 ) ;
}
static int F_82 ( struct V_1 * V_2 , T_6 V_18 , T_6 V_94 , T_6 V_153 ,
int V_84 , void * V_152 )
{
T_6 V_160 [] = L_31 ;
V_160 [ 0 ] = V_160 [ 3 ] = V_94 ;
V_160 [ 4 ] = V_153 ;
return F_68 ( V_2 , V_216 , V_18 , & V_160 , 5 , V_152 , V_84 ) ;
}
static struct V_68 * F_50 ( struct V_63 * V_34 ,
T_3 V_94 )
{
struct V_68 * V_69 = V_34 -> V_69 ;
struct V_70 * V_71 ;
while ( V_69 ) {
V_71 = F_10 ( V_69 ) ;
if ( V_71 -> V_94 == V_94 )
break;
V_69 = V_71 -> V_217 ;
}
return V_69 ;
}
static struct V_68 *
F_60 ( struct V_63 * V_34 , char * V_218 )
{
struct V_68 * V_69 = V_34 -> V_69 ;
struct V_70 * V_71 ;
while ( V_69 ) {
V_71 = F_10 ( V_69 ) ;
if ( ! strcmp ( V_71 -> V_83 , V_218 ) )
break;
V_69 = V_71 -> V_217 ;
}
return V_69 ;
}
static int F_31 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = F_10 ( V_69 ) ;
struct V_1 * V_2 = V_71 -> V_2 ;
if ( V_71 -> V_87 ) {
if ( ! V_71 -> V_83 [ 0 ] )
return - V_9 ;
F_59 ( 1 , V_165 L_32 ,
V_2 -> V_8 , V_71 -> V_83 ) ;
if ( F_78 ( V_2 , V_71 ) )
return - V_51 ;
F_20 ( V_69 , V_117 ) ;
return 1 ;
} else
F_20 ( V_69 , V_95 ) ;
return 0 ;
}
static void F_26 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = F_10 ( V_69 ) ;
if ( V_71 -> V_87 ) {
F_81 ( V_71 -> V_2 , V_71 -> V_18 , V_71 -> V_94 , 0 , 0 ) ;
F_20 ( V_69 , V_219 ) ;
} else
F_20 ( V_69 , V_62 ) ;
}
static void V_90 ( unsigned long V_160 )
{
struct V_68 * V_69 = (struct V_68 * ) V_160 ;
struct V_70 * V_71 = F_10 ( V_69 ) ;
if ( V_71 -> V_61 == V_95 )
F_26 ( V_69 ) ;
else
F_11 ( L_33 ,
V_71 -> V_2 -> V_8 , V_166 , V_69 -> V_73 ) ;
}
static void F_20 ( struct V_68 * V_69 , T_6 V_61 )
{
struct V_70 * V_71 = F_10 ( V_69 ) ;
struct V_1 * V_2 = V_71 -> V_2 ;
unsigned long V_28 ;
char * V_220 = NULL ;
F_69 ( & V_2 -> V_17 , V_28 ) ;
if ( V_71 -> V_61 != V_61 ) {
if ( V_71 -> V_87 && V_71 -> V_61 == V_95 )
F_17 ( & V_71 -> V_88 ) ;
switch ( V_61 ) {
case V_95 :
V_220 = L_34 ;
* ( V_104 * ) V_69 -> V_105 = F_19 ( V_71 -> V_94 ) ;
F_51 ( V_69 ) ;
F_32 ( V_69 ) ;
if ( V_71 -> V_78 == V_79 )
F_83 ( V_69 ,
V_130 ) ;
break;
case V_117 :
V_220 = L_35 ;
break;
case V_219 :
V_220 = L_36 ;
break;
case V_62 :
V_220 = L_37 ;
if ( V_71 -> V_87 ) {
* ( unsigned short * ) V_69 -> V_105 = 0 ;
V_71 -> V_94 = 0 ;
}
if ( V_71 -> V_78 == V_79 )
F_83 ( V_69 ,
V_132 ) ;
F_51 ( V_69 ) ;
break;
}
F_2 ( L_38 ,
V_2 -> V_8 , V_69 -> V_73 , V_220 ) ;
V_71 -> V_61 = V_61 ;
}
F_72 ( & V_2 -> V_17 , V_28 ) ;
}
static int F_33 ( struct V_68 * V_69 , struct V_118 * V_119 )
{
struct V_70 * V_71 = F_10 ( V_69 ) ;
struct V_1 * V_2 = V_71 -> V_2 ;
int V_153 = 0 ;
unsigned V_84 = V_119 -> V_84 ;
if ( V_119 -> V_84 > V_2 -> V_34 . V_33 ) {
V_84 = V_2 -> V_34 . V_33 ;
V_153 = 0x10 ;
}
if ( F_82 ( V_2 , V_71 -> V_18 , V_71 -> V_94 , V_153 , V_84 , V_119 -> V_91 ) )
return 1 ;
if ( V_153 ) {
F_34 ( V_119 , V_84 ) ;
return 1 ;
}
++ V_71 -> V_122 . V_199 ;
V_71 -> V_122 . V_221 += V_84 ;
return 0 ;
}
static void F_83 ( struct V_68 * V_69 , T_6 V_222 )
{
struct V_118 * V_119 ;
unsigned char * V_223 ;
if ( ( V_119 = F_52 ( 1 ) ) == NULL ) {
F_11 ( L_39 , V_166 ) ;
return;
}
V_223 = F_53 ( V_119 , 1 ) ;
* V_223 = V_222 ;
V_119 -> V_78 = F_84 ( V_119 , V_69 ) ;
F_57 ( V_119 ) ;
}
static T_6 F_4 ( T_7 V_22 )
{
T_6 V_224 = 0 ;
if ( V_22 >= 512000 ) V_224 = 8 ;
else if ( V_22 >= 256000 ) V_224 = 7 ;
else if ( V_22 >= 64000 ) V_224 = 6 ;
else if ( V_22 >= 38400 ) V_224 = 5 ;
else if ( V_22 >= 19200 ) V_224 = 4 ;
else if ( V_22 >= 9600 ) V_224 = 3 ;
else if ( V_22 >= 4800 ) V_224 = 2 ;
else if ( V_22 >= 2400 ) V_224 = 1 ;
return V_224 ;
}
static T_6 F_5 ( T_7 V_225 )
{
T_6 log = 0 ;
if ( ! V_225 )
return 0 ;
while ( V_225 > 1 ) {
V_225 >>= 1 ;
++ log ;
}
return log ;
}
static unsigned F_14 ( T_6 * V_226 , int V_84 )
{
unsigned V_227 = 0 ;
if ( ! V_84 )
V_84 = strlen ( V_226 ) ;
for (; V_84 && isdigit ( * V_226 ) ; ++ V_226 , -- V_84 )
V_227 = ( V_227 * 10 ) + ( * V_226 - ( unsigned ) '0' ) ;
return V_227 ;
}
static void F_32 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = F_10 ( V_69 ) ;
if ( V_71 -> V_87 )
F_85 ( & V_71 -> V_88 , V_127 + V_71 -> V_92 * V_228 ) ;
}
static void F_73 ( struct V_4 * V_3 )
{
F_2 ( L_40 ) ;
F_2 ( L_41 ) ;
F_2 ( L_42 , V_3 -> V_18 ) ;
F_2 ( L_43 , V_3 -> V_21 ) ;
F_2 ( L_44 , V_3 -> clock == 8 ? L_45 : L_46 ) ;
F_2 ( L_47 , V_3 -> V_25 ) ;
F_2 ( L_48 , V_3 -> V_24 ) ;
F_2 ( L_49 , V_3 -> V_23 ) ;
F_2 ( L_50 , V_3 -> V_26 ) ;
F_2 ( L_51 , V_3 -> V_35 ) ;
F_2 ( L_52 , V_3 -> V_38 ) ;
F_2 ( L_53 , V_3 -> V_39 ) ;
F_2 ( L_54 , V_3 -> V_29 ) ;
F_2 ( L_55 , V_3 -> V_30 ) ;
F_2 ( L_56 , V_3 -> V_31 ) ;
F_2 ( L_57 , V_3 -> V_27 ) ;
F_2 ( L_58 , V_3 -> V_32 ) ;
F_2 ( L_59 , V_3 -> V_28 ) ;
}
static void F_65 ( struct V_229 * V_128 )
{
F_2 ( L_60 ) ;
F_2 ( L_61 ) ;
F_2 ( L_62 , V_128 -> V_194 ) ;
F_2 ( L_63 , V_128 -> V_193 ) ;
F_2 ( L_64 , V_128 -> V_200 ) ;
F_2 ( L_65 , V_128 -> V_192 ) ;
F_2 ( L_66 , V_128 -> V_230 ) ;
F_2 ( L_67 , V_128 -> V_231 ) ;
F_2 ( L_68 , V_128 -> V_232 ) ;
F_2 ( L_69 , V_128 -> V_233 ) ;
F_2 ( L_70 , V_128 -> V_202 ) ;
F_2 ( L_71 , V_128 -> V_197 ) ;
}
static void F_76 ( struct V_63 * V_34 )
{
struct V_68 * V_69 = V_34 -> V_69 ;
F_2 ( L_72 ) ;
F_2 ( L_73 ) ;
F_2 ( L_74 ) ;
while( V_69 ) {
struct V_70 * V_71 = F_10 ( V_69 ) ;
F_2 ( L_75 ,
V_71 -> V_73 , V_71 -> V_83 , F_86 ( V_69 ) ,
V_71 -> V_78 == V_80 ? L_76 : L_77 ) ;
V_69 = V_71 -> V_217 ;
}
}
