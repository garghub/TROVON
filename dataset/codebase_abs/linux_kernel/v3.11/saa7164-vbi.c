static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
V_2 -> V_7 . V_8 = V_2 -> V_8 ;
V_2 -> V_7 . V_9 = V_2 -> V_9 ;
V_2 -> V_7 . V_10 =
( V_2 -> V_11 . V_12 & V_13 ) != 0 ;
F_3 ( V_2 ) ;
#if 0
saa7164_api_configure_dif(port, port->encodernorm.id);
#endif
#if 0
saa7164_api_set_audio_std(port);
#endif
F_2 ( V_5 , L_2 , V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_14 * V_15 , * V_16 , * V_17 , * V_18 , * V_19 , * V_20 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
F_5 ( & V_2 -> V_25 ) ;
F_2 ( V_5 , L_3 , V_6 , V_2 -> V_26 ) ;
F_6 (c, n, &port->dmaqueue.list) {
V_22 = F_7 ( V_15 , struct V_21 , V_27 ) ;
F_8 ( V_15 ) ;
F_9 ( V_22 ) ;
}
F_2 ( V_5 , L_4 , V_6 , V_2 -> V_26 ) ;
F_6 (p, q, &port->list_buf_used.list) {
V_24 = F_7 ( V_17 , struct V_23 , V_27 ) ;
F_8 ( V_17 ) ;
F_10 ( V_24 ) ;
}
F_2 ( V_5 , L_5 , V_6 , V_2 -> V_26 ) ;
F_6 (l, v, &port->list_buf_free.list) {
V_24 = F_7 ( V_19 , struct V_23 , V_27 ) ;
F_8 ( V_19 ) ;
F_10 ( V_24 ) ;
}
F_11 ( & V_2 -> V_25 ) ;
F_2 ( V_5 , L_6 , V_6 , V_2 -> V_26 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_28 * V_29 = & V_2 -> V_30 ;
int V_31 = - V_32 , V_33 ;
int V_34 = 0 ;
F_2 ( V_5 , L_1 , V_6 ) ;
V_29 -> V_35 = 1440 ;
V_29 -> V_36 = 12 ;
V_29 -> V_36 = 18 ;
V_29 -> V_37 = 1600 ;
V_29 -> V_37 = 1440 ;
V_29 -> V_38 = 2 +
( ( V_29 -> V_36 * V_29 -> V_37 ) / V_39 ) ;
V_29 -> V_40 = 8 ;
V_29 -> V_41 = 0 ;
V_29 -> V_42 = NULL ;
V_29 -> V_43 = NULL ;
V_29 -> V_44 = V_2 -> V_45 . V_46 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_45 . V_46 ; V_33 ++ ) {
V_22 = F_13 ( V_2 ,
V_29 -> V_36 *
V_29 -> V_37 ) ;
if ( ! V_22 ) {
F_14 ( V_47 L_7
L_8 ,
V_6 , V_31 ) ;
V_31 = - V_48 ;
goto V_49;
} else {
F_5 ( & V_2 -> V_25 ) ;
F_15 ( & V_22 -> V_27 , & V_2 -> V_50 . V_27 ) ;
F_11 ( & V_2 -> V_25 ) ;
}
}
V_34 = V_29 -> V_36 * V_29 -> V_37 ;
if ( V_51 < 16 )
V_51 = 16 ;
if ( V_51 > 512 )
V_51 = 512 ;
for ( V_33 = 0 ; V_33 < V_51 ; V_33 ++ ) {
V_24 = F_16 ( V_4 , V_34 ) ;
if ( V_24 ) {
F_5 ( & V_2 -> V_25 ) ;
F_15 ( & V_24 -> V_27 , & V_2 -> V_52 . V_27 ) ;
F_11 ( & V_2 -> V_25 ) ;
}
}
V_31 = 0 ;
V_49:
return V_31 ;
}
static int F_17 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_53 * V_53 , void * V_54 , T_1 V_12 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_33 ;
F_2 ( V_5 , L_9 , V_6 , ( V_58 ) V_12 ) ;
for ( V_33 = 0 ; V_33 < F_19 ( V_59 ) ; V_33 ++ ) {
if ( V_12 & V_59 [ V_33 ] . V_12 )
break;
}
if ( V_33 == F_19 ( V_59 ) )
return - V_60 ;
V_2 -> V_11 = V_59 [ V_33 ] ;
V_2 -> V_61 = V_12 ;
F_20 ( V_2 ) ;
F_2 ( V_5 , L_10 , V_6 , ( V_58 ) V_12 ) ;
return 0 ;
}
static int F_21 ( struct V_53 * V_53 , void * V_54 , T_1 * V_12 )
{
struct V_62 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
* V_12 = V_2 -> V_61 ;
return 0 ;
}
static int F_22 ( struct V_53 * V_53 , void * V_54 ,
struct V_63 * V_33 )
{
int V_16 ;
char * V_64 [] = { L_11 , L_12 , L_13 , L_14 ,
L_15 , L_16 , L_17 } ;
if ( V_33 -> V_65 >= 7 )
return - V_60 ;
strcpy ( V_33 -> V_66 , V_64 [ V_33 -> V_65 ] ) ;
if ( V_33 -> V_65 == 0 )
V_33 -> type = V_67 ;
else
V_33 -> type = V_68 ;
for ( V_16 = 0 ; V_16 < F_19 ( V_59 ) ; V_16 ++ )
V_33 -> V_61 |= V_59 [ V_16 ] . V_12 ;
return 0 ;
}
static int F_23 ( struct V_53 * V_53 , void * V_54 , unsigned int * V_33 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_24 ( V_2 ) != V_69 )
return - V_70 ;
* V_33 = ( V_2 -> V_71 - 1 ) ;
F_2 ( V_5 , L_18 , V_6 , * V_33 ) ;
return 0 ;
}
static int F_25 ( struct V_53 * V_53 , void * V_54 , unsigned int V_33 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_18 , V_6 , V_33 ) ;
if ( V_33 >= 7 )
return - V_60 ;
V_2 -> V_71 = V_33 + 1 ;
if ( F_26 ( V_2 ) != V_69 )
return - V_70 ;
return 0 ;
}
static int F_27 ( struct V_53 * V_53 , void * V_54 ,
struct V_72 * V_73 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( 0 != V_73 -> V_65 )
return - V_60 ;
strcpy ( V_73 -> V_66 , L_11 ) ;
V_73 -> type = V_74 ;
V_73 -> V_75 = V_76 | V_77 ;
F_2 ( V_5 , L_19 , V_73 -> type ) ;
return 0 ;
}
static int F_28 ( struct V_53 * V_53 , void * V_54 ,
const struct V_72 * V_73 )
{
return 0 ;
}
static int F_29 ( struct V_53 * V_53 , void * V_54 ,
struct V_78 * V_79 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
V_79 -> type = V_74 ;
V_79 -> V_80 = V_2 -> V_81 ;
return 0 ;
}
static int F_30 ( struct V_53 * V_53 , void * V_54 ,
const struct V_78 * V_79 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_1 * V_82 ;
struct V_83 * V_84 ;
struct V_85 V_29 = {
. V_86 = V_74 ,
. V_87 = V_88 ,
. V_61 = V_2 -> V_11 . V_12 ,
. V_80 = V_79 -> V_80
} ;
F_2 ( V_5 , L_20 , V_6 ,
V_79 -> V_80 , V_79 -> V_89 ) ;
if ( V_79 -> V_89 != 0 )
return - V_60 ;
if ( V_79 -> type != V_74 )
return - V_60 ;
V_2 -> V_81 = V_79 -> V_80 ;
if ( V_2 -> V_26 == V_90 )
V_82 = & V_4 -> V_91 [ V_92 ] ;
else
if ( V_2 -> V_26 == V_93 )
V_82 = & V_4 -> V_91 [ V_94 ] ;
else
F_31 () ;
V_84 = V_82 -> V_95 . V_96 ;
if ( V_84 && V_84 -> V_97 . V_98 . V_99 )
V_84 -> V_97 . V_98 . V_99 ( V_84 , & V_29 ) ;
else
F_14 ( V_47 L_21 , V_6 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_53 * V_53 , void * V_54 ,
struct V_100 * V_101 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_22 , V_6 ,
V_101 -> V_12 , V_101 -> V_102 ) ;
switch ( V_101 -> V_12 ) {
case V_103 :
V_101 -> V_102 = V_2 -> V_104 ;
break;
case V_105 :
V_101 -> V_102 = V_2 -> V_106 ;
break;
case V_107 :
V_101 -> V_102 = V_2 -> V_108 ;
break;
case V_109 :
V_101 -> V_102 = V_2 -> V_110 ;
break;
case V_111 :
V_101 -> V_102 = V_2 -> V_112 ;
break;
case V_113 :
V_101 -> V_102 = V_2 -> V_114 ;
break;
default:
return - V_60 ;
}
return 0 ;
}
static int F_33 ( struct V_53 * V_53 , void * V_54 ,
struct V_100 * V_101 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_115 = 0 ;
F_2 ( V_5 , L_22 , V_6 ,
V_101 -> V_12 , V_101 -> V_102 ) ;
switch ( V_101 -> V_12 ) {
case V_103 :
if ( ( V_101 -> V_102 >= 0 ) && ( V_101 -> V_102 <= 255 ) ) {
V_2 -> V_104 = V_101 -> V_102 ;
F_34 ( V_2 ,
V_116 ) ;
} else
V_115 = - V_60 ;
break;
case V_105 :
if ( ( V_101 -> V_102 >= 0 ) && ( V_101 -> V_102 <= 255 ) ) {
V_2 -> V_106 = V_101 -> V_102 ;
F_34 ( V_2 , V_117 ) ;
} else
V_115 = - V_60 ;
break;
case V_107 :
if ( ( V_101 -> V_102 >= 0 ) && ( V_101 -> V_102 <= 255 ) ) {
V_2 -> V_108 = V_101 -> V_102 ;
F_34 ( V_2 ,
V_118 ) ;
} else
V_115 = - V_60 ;
break;
case V_109 :
if ( ( V_101 -> V_102 >= 0 ) && ( V_101 -> V_102 <= 255 ) ) {
V_2 -> V_110 = V_101 -> V_102 ;
F_34 ( V_2 , V_119 ) ;
} else
V_115 = - V_60 ;
break;
case V_111 :
if ( ( V_101 -> V_102 >= 0 ) && ( V_101 -> V_102 <= 255 ) ) {
V_2 -> V_112 = V_101 -> V_102 ;
F_34 ( V_2 , V_120 ) ;
} else
V_115 = - V_60 ;
break;
case V_113 :
if ( ( V_101 -> V_102 >= - 83 ) && ( V_101 -> V_102 <= 24 ) ) {
V_2 -> V_114 = V_101 -> V_102 ;
F_35 ( V_2 , V_2 -> V_114 ) ;
} else
V_115 = - V_60 ;
break;
default:
V_115 = - V_60 ;
}
return V_115 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
struct V_123 * V_29 = & V_2 -> V_7 ;
switch ( V_122 -> V_12 ) {
case V_124 :
V_122 -> V_102 = V_29 -> V_125 ;
break;
case V_126 :
V_122 -> V_102 = V_29 -> V_127 ;
break;
case V_128 :
V_122 -> V_102 = V_29 -> V_129 ;
break;
case V_130 :
V_122 -> V_102 = V_29 -> V_131 ;
break;
case V_132 :
V_122 -> V_102 = V_29 -> V_133 ;
break;
default:
return - V_60 ;
}
return 0 ;
}
static int F_37 ( struct V_53 * V_53 , void * V_54 ,
struct V_134 * V_135 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
int V_33 , V_136 = 0 ;
if ( V_135 -> V_137 == V_138 ) {
for ( V_33 = 0 ; V_33 < V_135 -> V_139 ; V_33 ++ ) {
struct V_121 * V_122 = V_135 -> V_140 + V_33 ;
V_136 = F_36 ( V_2 , V_122 ) ;
if ( V_136 ) {
V_135 -> V_141 = V_33 ;
break;
}
}
return V_136 ;
}
return - V_60 ;
}
static int F_38 ( struct V_121 * V_122 , int V_142 )
{
int V_115 = - V_60 ;
switch ( V_122 -> V_12 ) {
case V_124 :
if ( ( V_122 -> V_102 == V_143 ) ||
( V_122 -> V_102 == V_144 ) )
V_115 = 0 ;
break;
case V_126 :
if ( ( V_122 -> V_102 >= 0 ) &&
( V_122 -> V_102 <= 1 ) )
V_115 = 0 ;
break;
case V_128 :
if ( ( V_122 -> V_102 >= V_145 ) &&
( V_122 -> V_102 <= V_146 ) )
V_115 = 0 ;
break;
case V_132 :
if ( ( V_122 -> V_102 >= 0 ) &&
( V_122 -> V_102 <= 255 ) )
V_115 = 0 ;
break;
case V_130 :
if ( ( V_122 -> V_102 >= 1 ) &&
( V_122 -> V_102 <= 3 ) )
V_115 = 0 ;
break;
default:
V_115 = - V_60 ;
}
return V_115 ;
}
static int F_39 ( struct V_53 * V_53 , void * V_54 ,
struct V_134 * V_135 )
{
int V_33 , V_136 = 0 ;
if ( V_135 -> V_137 == V_138 ) {
for ( V_33 = 0 ; V_33 < V_135 -> V_139 ; V_33 ++ ) {
struct V_121 * V_122 = V_135 -> V_140 + V_33 ;
V_136 = F_38 ( V_122 , 0 ) ;
if ( V_136 ) {
V_135 -> V_141 = V_33 ;
break;
}
}
return V_136 ;
}
return - V_60 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
struct V_123 * V_29 = & V_2 -> V_7 ;
int V_115 = 0 ;
switch ( V_122 -> V_12 ) {
case V_124 :
V_29 -> V_125 = V_122 -> V_102 ;
break;
case V_126 :
V_29 -> V_127 = V_122 -> V_102 ;
V_115 = F_41 ( V_2 , V_29 -> V_127 ) ;
if ( V_115 != V_69 ) {
F_14 ( V_47 L_23 , V_6 ,
V_115 ) ;
V_115 = - V_70 ;
}
break;
case V_128 :
V_29 -> V_129 = V_122 -> V_102 ;
V_115 = F_42 ( V_2 ) ;
if ( V_115 != V_69 ) {
F_14 ( V_47 L_23 , V_6 ,
V_115 ) ;
V_115 = - V_70 ;
}
break;
case V_130 :
V_29 -> V_131 = V_122 -> V_102 ;
break;
case V_132 :
V_29 -> V_133 = V_122 -> V_102 ;
break;
default:
return - V_60 ;
}
return V_115 ;
}
static int F_43 ( struct V_53 * V_53 , void * V_54 ,
struct V_134 * V_135 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
int V_33 , V_136 = 0 ;
if ( V_135 -> V_137 == V_138 ) {
for ( V_33 = 0 ; V_33 < V_135 -> V_139 ; V_33 ++ ) {
struct V_121 * V_122 = V_135 -> V_140 + V_33 ;
V_136 = F_38 ( V_122 , 0 ) ;
if ( V_136 ) {
V_135 -> V_141 = V_33 ;
break;
}
V_136 = F_40 ( V_2 , V_122 ) ;
if ( V_136 ) {
V_135 -> V_141 = V_33 ;
break;
}
}
return V_136 ;
}
return - V_60 ;
}
static int F_44 ( struct V_53 * V_53 , void * V_54 ,
struct V_147 * V_148 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
strcpy ( V_148 -> V_149 , V_4 -> V_66 ) ;
F_45 ( V_148 -> V_150 , V_151 [ V_4 -> V_152 ] . V_66 ,
sizeof( V_148 -> V_150 ) ) ;
sprintf ( V_148 -> V_153 , L_24 , F_46 ( V_4 -> V_154 ) ) ;
V_148 -> V_155 =
V_156 |
V_157 |
0 ;
V_148 -> V_155 |= V_158 ;
V_148 -> V_159 = 0 ;
return 0 ;
}
static int F_47 ( struct V_53 * V_53 , void * V_54 ,
struct V_160 * V_79 )
{
if ( V_79 -> V_65 != 0 )
return - V_60 ;
F_45 ( V_79 -> V_161 , L_25 , sizeof( V_79 -> V_161 ) ) ;
V_79 -> V_162 = V_163 ;
return 0 ;
}
static int F_48 ( struct V_53 * V_53 , void * V_54 ,
struct V_164 * V_79 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_79 -> V_165 . V_166 . V_162 = V_163 ;
V_79 -> V_165 . V_166 . V_167 = 0 ;
V_79 -> V_165 . V_166 . V_168 =
V_2 -> V_169 * V_2 -> V_170 ;
V_79 -> V_165 . V_166 . V_171 = 0 ;
V_79 -> V_165 . V_166 . V_8 = V_2 -> V_8 ;
V_79 -> V_165 . V_166 . V_9 = V_2 -> V_9 ;
F_2 ( V_5 , L_26 ,
V_2 -> V_8 , V_2 -> V_9 ) ;
return 0 ;
}
static int F_49 ( struct V_53 * V_53 , void * V_54 ,
struct V_164 * V_79 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_79 -> V_165 . V_166 . V_162 = V_163 ;
V_79 -> V_165 . V_166 . V_167 = 0 ;
V_79 -> V_165 . V_166 . V_168 =
V_2 -> V_169 * V_2 -> V_170 ;
V_79 -> V_165 . V_166 . V_171 = 0 ;
F_2 ( V_5 , L_27 ,
V_2 -> V_8 , V_2 -> V_9 ) ;
return 0 ;
}
static int F_50 ( struct V_53 * V_53 , void * V_54 ,
struct V_164 * V_79 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_79 -> V_165 . V_166 . V_162 = V_163 ;
V_79 -> V_165 . V_166 . V_167 = 0 ;
V_79 -> V_165 . V_166 . V_168 =
V_2 -> V_169 * V_2 -> V_170 ;
V_79 -> V_165 . V_166 . V_171 = 0 ;
F_2 ( V_5 , L_28 ,
V_79 -> V_165 . V_166 . V_8 , V_79 -> V_165 . V_166 . V_9 , V_79 -> V_165 . V_166 . V_172 ) ;
return 0 ;
}
static int F_51 ( struct V_123 * V_29 ,
struct V_173 * V_15 )
{
switch ( V_15 -> V_12 ) {
case V_103 :
return F_52 ( V_15 , 0x0 , 0xff , 1 , 127 ) ;
case V_105 :
return F_52 ( V_15 , 0x0 , 0xff , 1 , 66 ) ;
case V_107 :
return F_52 ( V_15 , 0x0 , 0xff , 1 , 62 ) ;
case V_109 :
return F_52 ( V_15 , 0x0 , 0xff , 1 , 128 ) ;
case V_111 :
return F_52 ( V_15 , 0x0 , 0x0f , 1 , 8 ) ;
case V_126 :
return F_52 ( V_15 , 0x0 , 0x01 , 1 , 0 ) ;
case V_113 :
return F_52 ( V_15 , - 83 , 24 , 1 , 20 ) ;
case V_124 :
return F_52 ( V_15 ,
V_143 ,
V_144 ,
1 , V_143 ) ;
case V_128 :
return F_52 ( V_15 ,
V_145 ,
V_146 ,
1 , V_174 ) ;
case V_132 :
return F_52 ( V_15 , 1 , 255 , 1 , 15 ) ;
case V_130 :
return F_52 ( V_15 ,
1 , 3 , 1 , 1 ) ;
default:
return - V_60 ;
}
}
static int F_53 ( struct V_53 * V_53 , void * V_54 ,
struct V_173 * V_15 )
{
struct V_55 * V_56 = V_54 ;
struct V_1 * V_2 = V_56 -> V_2 ;
int V_33 , V_175 ;
V_58 V_12 = V_15 -> V_12 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_175 = ! ! ( V_12 & V_176 ) ;
V_15 -> V_12 = V_12 & ~ V_176 ;
for ( V_33 = 0 ; V_33 < F_19 ( V_177 ) ; V_33 ++ ) {
if ( V_175 ) {
if ( V_15 -> V_12 < V_177 [ V_33 ] )
V_15 -> V_12 = V_177 [ V_33 ] ;
else
continue;
}
if ( V_15 -> V_12 == V_177 [ V_33 ] )
return F_51 ( & V_2 -> V_7 , V_15 ) ;
if ( V_15 -> V_12 < V_177 [ V_33 ] )
break;
}
return - V_60 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_115 ;
V_115 = F_55 ( V_2 , V_178 ) ;
if ( ( V_115 != V_69 ) && ( V_115 != V_179 ) ) {
F_14 ( V_47 L_29 ,
V_6 , V_115 ) ;
V_115 = - V_70 ;
} else {
F_2 ( V_5 , L_30 , V_6 ) ;
V_115 = 0 ;
}
return V_115 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_115 ;
V_115 = F_55 ( V_2 , V_180 ) ;
if ( ( V_115 != V_69 ) && ( V_115 != V_179 ) ) {
F_14 ( V_47 L_31 ,
V_6 , V_115 ) ;
V_115 = - V_70 ;
} else {
F_2 ( V_5 , L_32 , V_6 ) ;
V_115 = 0 ;
}
return V_115 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_115 ;
V_115 = F_55 ( V_2 , V_181 ) ;
if ( ( V_115 != V_69 ) && ( V_115 != V_179 ) ) {
F_14 ( V_47 L_33 ,
V_6 , V_115 ) ;
V_115 = - V_70 ;
} else {
F_2 ( V_5 , L_34 , V_6 ) ;
V_115 = 0 ;
}
return V_115 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_14 * V_15 , * V_16 ;
int V_115 ;
F_2 ( V_5 , L_35 , V_6 , V_2 -> V_26 ) ;
V_115 = F_57 ( V_2 ) ;
V_115 = F_56 ( V_2 ) ;
V_115 = F_54 ( V_2 ) ;
F_2 ( V_5 , L_36 , V_6 ,
V_2 -> V_26 ) ;
F_5 ( & V_2 -> V_25 ) ;
F_6 (c, n, &port->dmaqueue.list) {
V_22 = F_7 ( V_15 , struct V_21 , V_27 ) ;
V_22 -> V_182 = V_183 ;
V_22 -> V_184 = 0 ;
}
F_6 (c, n, &port->list_buf_used.list) {
V_24 = F_7 ( V_15 , struct V_23 , V_27 ) ;
V_24 -> V_184 = 0 ;
F_59 ( & V_24 -> V_27 , & V_2 -> V_52 . V_27 ) ;
}
F_11 ( & V_2 -> V_25 ) ;
F_4 ( V_2 ) ;
F_2 ( V_5 , L_37 , V_6 , V_2 -> V_26 ) ;
return V_115 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_31 , V_115 = 0 ;
F_2 ( V_5 , L_35 , V_6 , V_2 -> V_26 ) ;
V_2 -> V_185 = 0 ;
F_12 ( V_2 ) ;
#if 0
saa7164_api_set_encoder(port);
saa7164_api_get_encoder(port);
#endif
F_61 ( V_2 ) ;
if ( F_62 ( V_2 ) != V_69 ) {
F_14 ( V_47 L_38 , V_6 ) ;
V_115 = - V_70 ;
goto V_186;
}
V_31 = F_55 ( V_2 , V_180 ) ;
if ( ( V_31 != V_69 ) && ( V_31 != V_179 ) ) {
F_14 ( V_47 L_39 ,
V_6 , V_31 ) ;
V_115 = - V_70 ;
goto V_186;
} else
F_2 ( V_5 , L_40 , V_6 ) ;
V_31 = F_55 ( V_2 , V_181 ) ;
if ( ( V_31 != V_69 ) && ( V_31 != V_179 ) ) {
F_14 ( V_47 L_41 ,
V_6 , V_31 ) ;
V_31 = F_54 ( V_2 ) ;
if ( V_31 != V_69 ) {
F_14 ( V_47 L_42
L_43 , V_6 , V_31 ) ;
}
V_115 = - V_70 ;
goto V_186;
} else
F_2 ( V_5 , L_34 , V_6 ) ;
V_31 = F_55 ( V_2 , V_187 ) ;
if ( ( V_31 != V_69 ) && ( V_31 != V_179 ) ) {
F_14 ( V_47 L_44 ,
V_6 , V_31 ) ;
V_31 = F_56 ( V_2 ) ;
V_31 = F_54 ( V_2 ) ;
if ( V_31 != V_69 ) {
F_14 ( V_47 L_45
L_43 , V_6 , V_31 ) ;
}
V_115 = - V_70 ;
} else
F_2 ( V_5 , L_46 , V_6 ) ;
V_186:
return V_115 ;
}
static int F_63 ( struct V_53 * V_53 , void * V_54 ,
struct V_164 * V_79 )
{
V_79 -> V_165 . V_188 . V_189 = 1600 ;
V_79 -> V_165 . V_188 . V_189 = 1440 ;
V_79 -> V_165 . V_188 . V_190 = 27000000 ;
V_79 -> V_165 . V_188 . V_191 = V_192 ;
V_79 -> V_165 . V_188 . V_193 = 0 ;
V_79 -> V_165 . V_188 . V_182 = 0 ;
V_79 -> V_165 . V_188 . V_194 [ 0 ] = 10 ;
V_79 -> V_165 . V_188 . V_139 [ 0 ] = 18 ;
V_79 -> V_165 . V_188 . V_194 [ 1 ] = 263 + 10 + 1 ;
V_79 -> V_165 . V_188 . V_139 [ 1 ] = 18 ;
return 0 ;
}
static int F_64 ( struct V_53 * V_53 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_55 * V_56 ;
V_2 = (struct V_1 * ) F_65 ( F_66 ( V_53 ) ) ;
if ( ! V_2 )
return - V_32 ;
V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
V_56 = F_67 ( sizeof( * V_56 ) , V_195 ) ;
if ( NULL == V_56 )
return - V_48 ;
V_53 -> V_57 = V_56 ;
V_56 -> V_2 = V_2 ;
return 0 ;
}
static int F_68 ( struct V_53 * V_53 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
if ( F_69 ( & V_56 -> V_196 , 1 , 0 ) == 1 ) {
if ( F_70 ( & V_2 -> V_197 ) == 0 ) {
F_58 ( V_2 ) ;
}
}
V_53 -> V_57 = NULL ;
F_71 ( V_56 ) ;
return 0 ;
}
static struct
V_23 * F_72 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = NULL ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_58 V_198 ;
F_5 ( & V_2 -> V_25 ) ;
if ( ! F_73 ( & V_2 -> V_199 . V_27 ) ) {
V_24 = F_74 ( & V_2 -> V_199 . V_27 ,
struct V_23 , V_27 ) ;
if ( V_200 ) {
V_198 = F_75 ( 0 , V_24 -> V_201 , V_24 -> V_202 ) ;
if ( V_198 != V_24 -> V_198 ) {
F_14 ( V_47 L_47 ,
V_6 ,
V_24 , V_24 -> V_198 , V_198 ) ;
}
}
}
F_11 ( & V_2 -> V_25 ) ;
F_2 ( V_5 , L_48 , V_6 , V_24 ) ;
return V_24 ;
}
static T_2 F_76 ( struct V_53 * V_53 , char T_3 * V_203 ,
T_4 V_139 , T_5 * V_184 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_23 * V_24 = NULL ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_115 = 0 ;
int V_204 , V_205 ;
T_6 * V_17 ;
V_2 -> V_206 = V_2 -> V_207 ;
V_2 -> V_207 = F_77 ( V_208 ) ;
V_2 -> V_206 = V_2 -> V_207 -
V_2 -> V_206 ;
F_78 ( & V_2 -> V_209 ,
V_2 -> V_206 ) ;
if ( * V_184 ) {
F_14 ( V_47 L_49 , V_6 ) ;
return - V_210 ;
}
if ( F_69 ( & V_56 -> V_196 , 0 , 1 ) == 0 ) {
if ( F_79 ( & V_2 -> V_197 ) == 1 ) {
if ( F_17 ( V_2 ) < 0 ) {
F_14 ( V_47 L_50 , V_6 ) ;
return - V_60 ;
}
F_60 ( V_2 ) ;
F_80 ( 200 ) ;
}
}
if ( ( V_53 -> V_211 & V_212 ) == 0 ) {
if ( F_81 ( V_2 -> V_213 ,
F_72 ( V_2 ) ) ) {
F_14 ( V_47 L_51 , V_6 ) ;
return - V_214 ;
}
}
V_24 = F_72 ( V_2 ) ;
while ( ( V_139 > 0 ) && V_24 ) {
V_204 = V_24 -> V_202 - V_24 -> V_184 ;
V_205 = V_204 > V_139 ? V_139 : V_204 ;
V_17 = V_24 -> V_201 + V_24 -> V_184 ;
F_2 ( V_5 ,
L_52 ,
V_6 , ( int ) V_139 , V_205 , V_204 , V_24 , V_24 -> V_184 ) ;
if ( F_82 ( V_203 , V_17 , V_205 ) ) {
F_14 ( V_47 L_53 , V_6 ) ;
if ( ! V_115 ) {
F_14 ( V_47 L_54 , V_6 ) ;
V_115 = - V_215 ;
}
goto V_136;
}
V_24 -> V_184 += V_205 ;
V_139 -= V_205 ;
V_203 += V_205 ;
V_115 += V_205 ;
if ( V_24 -> V_184 > V_24 -> V_202 )
F_14 ( V_47 L_55 ) ;
if ( V_24 -> V_184 == V_24 -> V_202 ) {
V_24 -> V_184 = 0 ;
F_5 ( & V_2 -> V_25 ) ;
F_59 ( & V_24 -> V_27 , & V_2 -> V_52 . V_27 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ( V_53 -> V_211 & V_212 ) == 0 ) {
if ( F_81 ( V_2 -> V_213 ,
F_72 ( V_2 ) ) ) {
break;
}
}
V_24 = F_72 ( V_2 ) ;
}
}
V_136:
if ( ! V_115 && ! V_24 ) {
F_14 ( V_47 L_56 , V_6 ) ;
V_115 = - V_216 ;
}
return V_115 ;
}
static unsigned int F_83 ( struct V_53 * V_53 , T_7 * V_217 )
{
struct V_55 * V_56 = (struct V_55 * ) V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
unsigned int V_218 = 0 ;
V_2 -> V_219 = V_2 -> V_220 ;
V_2 -> V_220 = F_77 ( V_208 ) ;
V_2 -> V_219 = V_2 -> V_220 -
V_2 -> V_219 ;
F_78 ( & V_2 -> V_221 ,
V_2 -> V_219 ) ;
if ( ! F_84 ( V_2 -> V_222 ) )
return - V_70 ;
if ( F_69 ( & V_56 -> V_196 , 0 , 1 ) == 0 ) {
if ( F_79 ( & V_2 -> V_197 ) == 1 ) {
if ( F_17 ( V_2 ) < 0 )
return - V_60 ;
F_60 ( V_2 ) ;
F_80 ( 200 ) ;
}
}
if ( ( V_53 -> V_211 & V_212 ) == 0 ) {
if ( F_81 ( V_2 -> V_213 ,
F_72 ( V_2 ) ) ) {
return - V_214 ;
}
}
if ( ! F_73 ( & V_2 -> V_199 . V_27 ) )
V_218 |= V_223 | V_224 ;
return V_218 ;
}
static struct V_225 * F_85 (
struct V_1 * V_2 ,
struct V_226 * V_154 ,
struct V_225 * V_227 ,
char * type )
{
struct V_225 * V_228 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
V_228 = F_86 () ;
if ( NULL == V_228 )
return NULL ;
* V_228 = * V_227 ;
snprintf ( V_228 -> V_66 , sizeof( V_228 -> V_66 ) , L_57 , V_4 -> V_66 ,
type , V_151 [ V_4 -> V_152 ] . V_66 ) ;
V_228 -> V_229 = & V_4 -> V_229 ;
V_228 -> V_230 = V_231 ;
return V_228 ;
}
int F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_31 = - V_32 ;
F_2 ( V_5 , L_1 , V_6 ) ;
if ( V_2 -> type != V_232 )
F_31 () ;
if ( V_2 -> V_45 . V_233 == 0 ) {
F_14 ( V_47 L_7
L_58 ,
V_6 , V_31 ) ;
V_31 = - V_48 ;
goto V_49;
}
V_2 -> V_222 = F_85 ( V_2 ,
V_4 -> V_154 , & V_234 , L_59 ) ;
if ( ! V_2 -> V_222 ) {
F_14 ( V_235 L_60 ,
V_4 -> V_66 ) ;
V_31 = - V_48 ;
goto V_49;
}
V_2 -> V_61 = V_236 ;
F_88 ( V_2 -> V_222 , V_2 ) ;
V_31 = F_89 ( V_2 -> V_222 ,
V_237 , - 1 ) ;
if ( V_31 < 0 ) {
F_14 ( V_235 L_61 ,
V_4 -> V_66 ) ;
goto V_49;
}
F_14 ( V_235 L_62 ,
V_4 -> V_66 , V_2 -> V_222 -> V_238 ) ;
V_31 = 0 ;
V_49:
return V_31 ;
}
void F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_35 , V_6 , V_2 -> V_26 ) ;
if ( V_2 -> type != V_232 )
F_31 () ;
if ( V_2 -> V_222 ) {
if ( V_2 -> V_222 -> V_239 != - 1 )
F_91 ( V_2 -> V_222 ) ;
else
V_231 ( V_2 -> V_222 ) ;
V_2 -> V_222 = NULL ;
}
}
