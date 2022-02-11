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
static int F_18 ( struct V_53 * V_53 , void * V_54 , T_1 * V_12 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_33 ;
F_2 ( V_5 , L_9 , V_6 , ( V_58 ) * V_12 ) ;
for ( V_33 = 0 ; V_33 < F_19 ( V_59 ) ; V_33 ++ ) {
if ( * V_12 & V_59 [ V_33 ] . V_12 )
break;
}
if ( V_33 == F_19 ( V_59 ) )
return - V_60 ;
V_2 -> V_11 = V_59 [ V_33 ] ;
F_20 ( V_2 ) ;
F_2 ( V_5 , L_10 , V_6 , ( V_58 ) * V_12 ) ;
return 0 ;
}
static int F_21 ( struct V_53 * V_53 , void * V_54 ,
struct V_61 * V_33 )
{
int V_16 ;
char * V_62 [] = { L_11 , L_12 , L_13 , L_14 ,
L_15 , L_16 , L_17 } ;
if ( V_33 -> V_63 >= 7 )
return - V_60 ;
strcpy ( V_33 -> V_64 , V_62 [ V_33 -> V_63 ] ) ;
if ( V_33 -> V_63 == 0 )
V_33 -> type = V_65 ;
else
V_33 -> type = V_66 ;
for ( V_16 = 0 ; V_16 < F_19 ( V_59 ) ; V_16 ++ )
V_33 -> V_67 |= V_59 [ V_16 ] . V_12 ;
return 0 ;
}
static int F_22 ( struct V_53 * V_53 , void * V_54 , unsigned int * V_33 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_23 ( V_2 ) != V_68 )
return - V_69 ;
* V_33 = ( V_2 -> V_70 - 1 ) ;
F_2 ( V_5 , L_18 , V_6 , * V_33 ) ;
return 0 ;
}
static int F_24 ( struct V_53 * V_53 , void * V_54 , unsigned int V_33 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_18 , V_6 , V_33 ) ;
if ( V_33 >= 7 )
return - V_60 ;
V_2 -> V_70 = V_33 + 1 ;
if ( F_25 ( V_2 ) != V_68 )
return - V_69 ;
return 0 ;
}
static int F_26 ( struct V_53 * V_53 , void * V_54 ,
struct V_71 * V_72 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( 0 != V_72 -> V_63 )
return - V_60 ;
strcpy ( V_72 -> V_64 , L_11 ) ;
V_72 -> type = V_73 ;
V_72 -> V_74 = V_75 | V_76 ;
F_2 ( V_5 , L_19 , V_72 -> type ) ;
return 0 ;
}
static int F_27 ( struct V_53 * V_53 , void * V_54 ,
struct V_71 * V_72 )
{
return 0 ;
}
static int F_28 ( struct V_53 * V_53 , void * V_54 ,
struct V_77 * V_78 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
V_78 -> type = V_73 ;
V_78 -> V_79 = V_2 -> V_80 ;
return 0 ;
}
static int F_29 ( struct V_53 * V_53 , void * V_54 ,
struct V_77 * V_78 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_1 * V_81 ;
struct V_82 * V_83 ;
struct V_84 V_29 = {
. V_85 = V_73 ,
. V_86 = V_87 ,
. V_67 = V_2 -> V_11 . V_12 ,
. V_79 = V_78 -> V_79
} ;
F_2 ( V_5 , L_20 , V_6 ,
V_78 -> V_79 , V_78 -> V_88 ) ;
if ( V_78 -> V_88 != 0 )
return - V_60 ;
if ( V_78 -> type != V_73 )
return - V_60 ;
V_2 -> V_80 = V_78 -> V_79 ;
if ( V_2 -> V_26 == V_89 )
V_81 = & V_4 -> V_90 [ V_91 ] ;
else
if ( V_2 -> V_26 == V_92 )
V_81 = & V_4 -> V_90 [ V_93 ] ;
else
F_30 () ;
V_83 = V_81 -> V_94 . V_95 ;
if ( V_83 && V_83 -> V_96 . V_97 . V_98 )
V_83 -> V_96 . V_97 . V_98 ( V_83 , & V_29 ) ;
else
F_14 ( V_47 L_21 , V_6 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
static int F_31 ( struct V_53 * V_53 , void * V_54 ,
struct V_99 * V_100 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_22 , V_6 ,
V_100 -> V_12 , V_100 -> V_101 ) ;
switch ( V_100 -> V_12 ) {
case V_102 :
V_100 -> V_101 = V_2 -> V_103 ;
break;
case V_104 :
V_100 -> V_101 = V_2 -> V_105 ;
break;
case V_106 :
V_100 -> V_101 = V_2 -> V_107 ;
break;
case V_108 :
V_100 -> V_101 = V_2 -> V_109 ;
break;
case V_110 :
V_100 -> V_101 = V_2 -> V_111 ;
break;
case V_112 :
V_100 -> V_101 = V_2 -> V_113 ;
break;
default:
return - V_60 ;
}
return 0 ;
}
static int F_32 ( struct V_53 * V_53 , void * V_54 ,
struct V_99 * V_100 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_114 = 0 ;
F_2 ( V_5 , L_22 , V_6 ,
V_100 -> V_12 , V_100 -> V_101 ) ;
switch ( V_100 -> V_12 ) {
case V_102 :
if ( ( V_100 -> V_101 >= 0 ) && ( V_100 -> V_101 <= 255 ) ) {
V_2 -> V_103 = V_100 -> V_101 ;
F_33 ( V_2 ,
V_115 ) ;
} else
V_114 = - V_60 ;
break;
case V_104 :
if ( ( V_100 -> V_101 >= 0 ) && ( V_100 -> V_101 <= 255 ) ) {
V_2 -> V_105 = V_100 -> V_101 ;
F_33 ( V_2 , V_116 ) ;
} else
V_114 = - V_60 ;
break;
case V_106 :
if ( ( V_100 -> V_101 >= 0 ) && ( V_100 -> V_101 <= 255 ) ) {
V_2 -> V_107 = V_100 -> V_101 ;
F_33 ( V_2 ,
V_117 ) ;
} else
V_114 = - V_60 ;
break;
case V_108 :
if ( ( V_100 -> V_101 >= 0 ) && ( V_100 -> V_101 <= 255 ) ) {
V_2 -> V_109 = V_100 -> V_101 ;
F_33 ( V_2 , V_118 ) ;
} else
V_114 = - V_60 ;
break;
case V_110 :
if ( ( V_100 -> V_101 >= 0 ) && ( V_100 -> V_101 <= 255 ) ) {
V_2 -> V_111 = V_100 -> V_101 ;
F_33 ( V_2 , V_119 ) ;
} else
V_114 = - V_60 ;
break;
case V_112 :
if ( ( V_100 -> V_101 >= - 83 ) && ( V_100 -> V_101 <= 24 ) ) {
V_2 -> V_113 = V_100 -> V_101 ;
F_34 ( V_2 , V_2 -> V_113 ) ;
} else
V_114 = - V_60 ;
break;
default:
V_114 = - V_60 ;
}
return V_114 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
struct V_122 * V_29 = & V_2 -> V_7 ;
switch ( V_121 -> V_12 ) {
case V_123 :
V_121 -> V_101 = V_29 -> V_124 ;
break;
case V_125 :
V_121 -> V_101 = V_29 -> V_126 ;
break;
case V_127 :
V_121 -> V_101 = V_29 -> V_128 ;
break;
case V_129 :
V_121 -> V_101 = V_29 -> V_130 ;
break;
case V_131 :
V_121 -> V_101 = V_29 -> V_132 ;
break;
default:
return - V_60 ;
}
return 0 ;
}
static int F_36 ( struct V_53 * V_53 , void * V_54 ,
struct V_133 * V_134 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
int V_33 , V_135 = 0 ;
if ( V_134 -> V_136 == V_137 ) {
for ( V_33 = 0 ; V_33 < V_134 -> V_138 ; V_33 ++ ) {
struct V_120 * V_121 = V_134 -> V_139 + V_33 ;
V_135 = F_35 ( V_2 , V_121 ) ;
if ( V_135 ) {
V_134 -> V_140 = V_33 ;
break;
}
}
return V_135 ;
}
return - V_60 ;
}
static int F_37 ( struct V_120 * V_121 , int V_141 )
{
int V_114 = - V_60 ;
switch ( V_121 -> V_12 ) {
case V_123 :
if ( ( V_121 -> V_101 == V_142 ) ||
( V_121 -> V_101 == V_143 ) )
V_114 = 0 ;
break;
case V_125 :
if ( ( V_121 -> V_101 >= 0 ) &&
( V_121 -> V_101 <= 1 ) )
V_114 = 0 ;
break;
case V_127 :
if ( ( V_121 -> V_101 >= V_144 ) &&
( V_121 -> V_101 <= V_145 ) )
V_114 = 0 ;
break;
case V_131 :
if ( ( V_121 -> V_101 >= 0 ) &&
( V_121 -> V_101 <= 255 ) )
V_114 = 0 ;
break;
case V_129 :
if ( ( V_121 -> V_101 >= 1 ) &&
( V_121 -> V_101 <= 3 ) )
V_114 = 0 ;
break;
default:
V_114 = - V_60 ;
}
return V_114 ;
}
static int F_38 ( struct V_53 * V_53 , void * V_54 ,
struct V_133 * V_134 )
{
int V_33 , V_135 = 0 ;
if ( V_134 -> V_136 == V_137 ) {
for ( V_33 = 0 ; V_33 < V_134 -> V_138 ; V_33 ++ ) {
struct V_120 * V_121 = V_134 -> V_139 + V_33 ;
V_135 = F_37 ( V_121 , 0 ) ;
if ( V_135 ) {
V_134 -> V_140 = V_33 ;
break;
}
}
return V_135 ;
}
return - V_60 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
struct V_122 * V_29 = & V_2 -> V_7 ;
int V_114 = 0 ;
switch ( V_121 -> V_12 ) {
case V_123 :
V_29 -> V_124 = V_121 -> V_101 ;
break;
case V_125 :
V_29 -> V_126 = V_121 -> V_101 ;
V_114 = F_40 ( V_2 , V_29 -> V_126 ) ;
if ( V_114 != V_68 ) {
F_14 ( V_47 L_23 , V_6 ,
V_114 ) ;
V_114 = - V_69 ;
}
break;
case V_127 :
V_29 -> V_128 = V_121 -> V_101 ;
V_114 = F_41 ( V_2 ) ;
if ( V_114 != V_68 ) {
F_14 ( V_47 L_23 , V_6 ,
V_114 ) ;
V_114 = - V_69 ;
}
break;
case V_129 :
V_29 -> V_130 = V_121 -> V_101 ;
break;
case V_131 :
V_29 -> V_132 = V_121 -> V_101 ;
break;
default:
return - V_60 ;
}
return V_114 ;
}
static int F_42 ( struct V_53 * V_53 , void * V_54 ,
struct V_133 * V_134 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
int V_33 , V_135 = 0 ;
if ( V_134 -> V_136 == V_137 ) {
for ( V_33 = 0 ; V_33 < V_134 -> V_138 ; V_33 ++ ) {
struct V_120 * V_121 = V_134 -> V_139 + V_33 ;
V_135 = F_37 ( V_121 , 0 ) ;
if ( V_135 ) {
V_134 -> V_140 = V_33 ;
break;
}
V_135 = F_39 ( V_2 , V_121 ) ;
if ( V_135 ) {
V_134 -> V_140 = V_33 ;
break;
}
}
return V_135 ;
}
return - V_60 ;
}
static int F_43 ( struct V_53 * V_53 , void * V_54 ,
struct V_146 * V_147 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
strcpy ( V_147 -> V_148 , V_4 -> V_64 ) ;
F_44 ( V_147 -> V_149 , V_150 [ V_4 -> V_151 ] . V_64 ,
sizeof( V_147 -> V_149 ) ) ;
sprintf ( V_147 -> V_152 , L_24 , F_45 ( V_4 -> V_153 ) ) ;
V_147 -> V_154 =
V_155 |
V_156 |
0 ;
V_147 -> V_154 |= V_157 ;
V_147 -> V_158 = 0 ;
return 0 ;
}
static int F_46 ( struct V_53 * V_53 , void * V_54 ,
struct V_159 * V_78 )
{
if ( V_78 -> V_63 != 0 )
return - V_60 ;
F_44 ( V_78 -> V_160 , L_25 , sizeof( V_78 -> V_160 ) ) ;
V_78 -> V_161 = V_162 ;
return 0 ;
}
static int F_47 ( struct V_53 * V_53 , void * V_54 ,
struct V_163 * V_78 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_78 -> V_164 . V_165 . V_161 = V_162 ;
V_78 -> V_164 . V_165 . V_166 = 0 ;
V_78 -> V_164 . V_165 . V_167 =
V_2 -> V_168 * V_2 -> V_169 ;
V_78 -> V_164 . V_165 . V_170 = 0 ;
V_78 -> V_164 . V_165 . V_8 = V_2 -> V_8 ;
V_78 -> V_164 . V_165 . V_9 = V_2 -> V_9 ;
F_2 ( V_5 , L_26 ,
V_2 -> V_8 , V_2 -> V_9 ) ;
return 0 ;
}
static int F_48 ( struct V_53 * V_53 , void * V_54 ,
struct V_163 * V_78 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_78 -> V_164 . V_165 . V_161 = V_162 ;
V_78 -> V_164 . V_165 . V_166 = 0 ;
V_78 -> V_164 . V_165 . V_167 =
V_2 -> V_168 * V_2 -> V_169 ;
V_78 -> V_164 . V_165 . V_170 = 0 ;
F_2 ( V_5 , L_27 ,
V_2 -> V_8 , V_2 -> V_9 ) ;
return 0 ;
}
static int F_49 ( struct V_53 * V_53 , void * V_54 ,
struct V_163 * V_78 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_78 -> V_164 . V_165 . V_161 = V_162 ;
V_78 -> V_164 . V_165 . V_166 = 0 ;
V_78 -> V_164 . V_165 . V_167 =
V_2 -> V_168 * V_2 -> V_169 ;
V_78 -> V_164 . V_165 . V_170 = 0 ;
F_2 ( V_5 , L_28 ,
V_78 -> V_164 . V_165 . V_8 , V_78 -> V_164 . V_165 . V_9 , V_78 -> V_164 . V_165 . V_171 ) ;
return 0 ;
}
static int F_50 ( struct V_122 * V_29 ,
struct V_172 * V_15 )
{
switch ( V_15 -> V_12 ) {
case V_102 :
return F_51 ( V_15 , 0x0 , 0xff , 1 , 127 ) ;
case V_104 :
return F_51 ( V_15 , 0x0 , 0xff , 1 , 66 ) ;
case V_106 :
return F_51 ( V_15 , 0x0 , 0xff , 1 , 62 ) ;
case V_108 :
return F_51 ( V_15 , 0x0 , 0xff , 1 , 128 ) ;
case V_110 :
return F_51 ( V_15 , 0x0 , 0x0f , 1 , 8 ) ;
case V_125 :
return F_51 ( V_15 , 0x0 , 0x01 , 1 , 0 ) ;
case V_112 :
return F_51 ( V_15 , - 83 , 24 , 1 , 20 ) ;
case V_123 :
return F_51 ( V_15 ,
V_142 ,
V_143 ,
1 , V_142 ) ;
case V_127 :
return F_51 ( V_15 ,
V_144 ,
V_145 ,
1 , V_173 ) ;
case V_131 :
return F_51 ( V_15 , 1 , 255 , 1 , 15 ) ;
case V_129 :
return F_51 ( V_15 ,
1 , 3 , 1 , 1 ) ;
default:
return - V_60 ;
}
}
static int F_52 ( struct V_53 * V_53 , void * V_54 ,
struct V_172 * V_15 )
{
struct V_55 * V_56 = V_54 ;
struct V_1 * V_2 = V_56 -> V_2 ;
int V_33 , V_174 ;
V_58 V_12 = V_15 -> V_12 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_174 = ! ! ( V_12 & V_175 ) ;
V_15 -> V_12 = V_12 & ~ V_175 ;
for ( V_33 = 0 ; V_33 < F_19 ( V_176 ) ; V_33 ++ ) {
if ( V_174 ) {
if ( V_15 -> V_12 < V_176 [ V_33 ] )
V_15 -> V_12 = V_176 [ V_33 ] ;
else
continue;
}
if ( V_15 -> V_12 == V_176 [ V_33 ] )
return F_50 ( & V_2 -> V_7 , V_15 ) ;
if ( V_15 -> V_12 < V_176 [ V_33 ] )
break;
}
return - V_60 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_114 ;
V_114 = F_54 ( V_2 , V_177 ) ;
if ( ( V_114 != V_68 ) && ( V_114 != V_178 ) ) {
F_14 ( V_47 L_29 ,
V_6 , V_114 ) ;
V_114 = - V_69 ;
} else {
F_2 ( V_5 , L_30 , V_6 ) ;
V_114 = 0 ;
}
return V_114 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_114 ;
V_114 = F_54 ( V_2 , V_179 ) ;
if ( ( V_114 != V_68 ) && ( V_114 != V_178 ) ) {
F_14 ( V_47 L_31 ,
V_6 , V_114 ) ;
V_114 = - V_69 ;
} else {
F_2 ( V_5 , L_32 , V_6 ) ;
V_114 = 0 ;
}
return V_114 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_114 ;
V_114 = F_54 ( V_2 , V_180 ) ;
if ( ( V_114 != V_68 ) && ( V_114 != V_178 ) ) {
F_14 ( V_47 L_33 ,
V_6 , V_114 ) ;
V_114 = - V_69 ;
} else {
F_2 ( V_5 , L_34 , V_6 ) ;
V_114 = 0 ;
}
return V_114 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_14 * V_15 , * V_16 ;
int V_114 ;
F_2 ( V_5 , L_35 , V_6 , V_2 -> V_26 ) ;
V_114 = F_56 ( V_2 ) ;
V_114 = F_55 ( V_2 ) ;
V_114 = F_53 ( V_2 ) ;
F_2 ( V_5 , L_36 , V_6 ,
V_2 -> V_26 ) ;
F_5 ( & V_2 -> V_25 ) ;
F_6 (c, n, &port->dmaqueue.list) {
V_22 = F_7 ( V_15 , struct V_21 , V_27 ) ;
V_22 -> V_181 = V_182 ;
V_22 -> V_183 = 0 ;
}
F_6 (c, n, &port->list_buf_used.list) {
V_24 = F_7 ( V_15 , struct V_23 , V_27 ) ;
V_24 -> V_183 = 0 ;
F_58 ( & V_24 -> V_27 , & V_2 -> V_52 . V_27 ) ;
}
F_11 ( & V_2 -> V_25 ) ;
F_4 ( V_2 ) ;
F_2 ( V_5 , L_37 , V_6 , V_2 -> V_26 ) ;
return V_114 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_31 , V_114 = 0 ;
F_2 ( V_5 , L_35 , V_6 , V_2 -> V_26 ) ;
V_2 -> V_184 = 0 ;
F_12 ( V_2 ) ;
#if 0
saa7164_api_set_encoder(port);
saa7164_api_get_encoder(port);
#endif
F_60 ( V_2 ) ;
if ( F_61 ( V_2 ) != V_68 ) {
F_14 ( V_47 L_38 , V_6 ) ;
V_114 = - V_69 ;
goto V_185;
}
V_31 = F_54 ( V_2 , V_179 ) ;
if ( ( V_31 != V_68 ) && ( V_31 != V_178 ) ) {
F_14 ( V_47 L_39 ,
V_6 , V_31 ) ;
V_114 = - V_69 ;
goto V_185;
} else
F_2 ( V_5 , L_40 , V_6 ) ;
V_31 = F_54 ( V_2 , V_180 ) ;
if ( ( V_31 != V_68 ) && ( V_31 != V_178 ) ) {
F_14 ( V_47 L_41 ,
V_6 , V_31 ) ;
V_31 = F_53 ( V_2 ) ;
if ( V_31 != V_68 ) {
F_14 ( V_47 L_42
L_43 , V_6 , V_31 ) ;
}
V_114 = - V_69 ;
goto V_185;
} else
F_2 ( V_5 , L_34 , V_6 ) ;
V_31 = F_54 ( V_2 , V_186 ) ;
if ( ( V_31 != V_68 ) && ( V_31 != V_178 ) ) {
F_14 ( V_47 L_44 ,
V_6 , V_31 ) ;
V_31 = F_55 ( V_2 ) ;
V_31 = F_53 ( V_2 ) ;
if ( V_31 != V_68 ) {
F_14 ( V_47 L_45
L_43 , V_6 , V_31 ) ;
}
V_114 = - V_69 ;
} else
F_2 ( V_5 , L_46 , V_6 ) ;
V_185:
return V_114 ;
}
int F_62 ( struct V_53 * V_53 , void * V_54 , struct V_163 * V_78 )
{
V_78 -> V_164 . V_187 . V_188 = 1600 ;
V_78 -> V_164 . V_187 . V_188 = 1440 ;
V_78 -> V_164 . V_187 . V_189 = 27000000 ;
V_78 -> V_164 . V_187 . V_190 = V_191 ;
V_78 -> V_164 . V_187 . V_192 = 0 ;
V_78 -> V_164 . V_187 . V_181 = 0 ;
V_78 -> V_164 . V_187 . V_193 [ 0 ] = 10 ;
V_78 -> V_164 . V_187 . V_138 [ 0 ] = 18 ;
V_78 -> V_164 . V_187 . V_193 [ 1 ] = 263 + 10 + 1 ;
V_78 -> V_164 . V_187 . V_138 [ 1 ] = 18 ;
return 0 ;
}
static int F_63 ( struct V_53 * V_53 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_55 * V_56 ;
V_2 = (struct V_1 * ) F_64 ( F_65 ( V_53 ) ) ;
if ( ! V_2 )
return - V_32 ;
V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
V_56 = F_66 ( sizeof( * V_56 ) , V_194 ) ;
if ( NULL == V_56 )
return - V_48 ;
V_53 -> V_57 = V_56 ;
V_56 -> V_2 = V_2 ;
return 0 ;
}
static int F_67 ( struct V_53 * V_53 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
if ( F_68 ( & V_56 -> V_195 , 1 , 0 ) == 1 ) {
if ( F_69 ( & V_2 -> V_196 ) == 0 ) {
F_57 ( V_2 ) ;
}
}
V_53 -> V_57 = NULL ;
F_70 ( V_56 ) ;
return 0 ;
}
struct V_23 * F_71 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = NULL ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_58 V_197 ;
F_5 ( & V_2 -> V_25 ) ;
if ( ! F_72 ( & V_2 -> V_198 . V_27 ) ) {
V_24 = F_73 ( & V_2 -> V_198 . V_27 ,
struct V_23 , V_27 ) ;
if ( V_199 ) {
V_197 = F_74 ( 0 , V_24 -> V_200 , V_24 -> V_201 ) ;
if ( V_197 != V_24 -> V_197 ) {
F_14 ( V_47 L_47 ,
V_6 ,
V_24 , V_24 -> V_197 , V_197 ) ;
}
}
}
F_11 ( & V_2 -> V_25 ) ;
F_2 ( V_5 , L_48 , V_6 , V_24 ) ;
return V_24 ;
}
static T_2 F_75 ( struct V_53 * V_53 , char T_3 * V_202 ,
T_4 V_138 , T_5 * V_183 )
{
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_23 * V_24 = NULL ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_114 = 0 ;
int V_203 , V_204 ;
T_6 * V_17 ;
V_2 -> V_205 = V_2 -> V_206 ;
V_2 -> V_206 = F_76 ( V_207 ) ;
V_2 -> V_205 = V_2 -> V_206 -
V_2 -> V_205 ;
F_77 ( & V_2 -> V_208 ,
V_2 -> V_205 ) ;
if ( * V_183 ) {
F_14 ( V_47 L_49 , V_6 ) ;
return - V_209 ;
}
if ( F_68 ( & V_56 -> V_195 , 0 , 1 ) == 0 ) {
if ( F_78 ( & V_2 -> V_196 ) == 1 ) {
if ( F_17 ( V_2 ) < 0 ) {
F_14 ( V_47 L_50 , V_6 ) ;
return - V_60 ;
}
F_59 ( V_2 ) ;
F_79 ( 200 ) ;
}
}
if ( ( V_53 -> V_210 & V_211 ) == 0 ) {
if ( F_80 ( V_2 -> V_212 ,
F_71 ( V_2 ) ) ) {
F_14 ( V_47 L_51 , V_6 ) ;
return - V_213 ;
}
}
V_24 = F_71 ( V_2 ) ;
while ( ( V_138 > 0 ) && V_24 ) {
V_203 = V_24 -> V_201 - V_24 -> V_183 ;
V_204 = V_203 > V_138 ? V_138 : V_203 ;
V_17 = V_24 -> V_200 + V_24 -> V_183 ;
F_2 ( V_5 ,
L_52 ,
V_6 , ( int ) V_138 , V_204 , V_203 , V_24 , V_24 -> V_183 ) ;
if ( F_81 ( V_202 , V_17 , V_204 ) ) {
F_14 ( V_47 L_53 , V_6 ) ;
if ( ! V_114 ) {
F_14 ( V_47 L_54 , V_6 ) ;
V_114 = - V_214 ;
}
goto V_135;
}
V_24 -> V_183 += V_204 ;
V_138 -= V_204 ;
V_202 += V_204 ;
V_114 += V_204 ;
if ( V_24 -> V_183 > V_24 -> V_201 )
F_14 ( V_47 L_55 ) ;
if ( V_24 -> V_183 == V_24 -> V_201 ) {
V_24 -> V_183 = 0 ;
F_5 ( & V_2 -> V_25 ) ;
F_58 ( & V_24 -> V_27 , & V_2 -> V_52 . V_27 ) ;
F_11 ( & V_2 -> V_25 ) ;
if ( ( V_53 -> V_210 & V_211 ) == 0 ) {
if ( F_80 ( V_2 -> V_212 ,
F_71 ( V_2 ) ) ) {
break;
}
}
V_24 = F_71 ( V_2 ) ;
}
}
V_135:
if ( ! V_114 && ! V_24 ) {
F_14 ( V_47 L_56 , V_6 ) ;
V_114 = - V_215 ;
}
return V_114 ;
}
static unsigned int F_82 ( struct V_53 * V_53 , T_7 * V_216 )
{
struct V_55 * V_56 = (struct V_55 * ) V_53 -> V_57 ;
struct V_1 * V_2 = V_56 -> V_2 ;
unsigned int V_217 = 0 ;
V_2 -> V_218 = V_2 -> V_219 ;
V_2 -> V_219 = F_76 ( V_207 ) ;
V_2 -> V_218 = V_2 -> V_219 -
V_2 -> V_218 ;
F_77 ( & V_2 -> V_220 ,
V_2 -> V_218 ) ;
if ( ! F_83 ( V_2 -> V_221 ) )
return - V_69 ;
if ( F_68 ( & V_56 -> V_195 , 0 , 1 ) == 0 ) {
if ( F_78 ( & V_2 -> V_196 ) == 1 ) {
if ( F_17 ( V_2 ) < 0 )
return - V_60 ;
F_59 ( V_2 ) ;
F_79 ( 200 ) ;
}
}
if ( ( V_53 -> V_210 & V_211 ) == 0 ) {
if ( F_80 ( V_2 -> V_212 ,
F_71 ( V_2 ) ) ) {
return - V_213 ;
}
}
if ( ! F_72 ( & V_2 -> V_198 . V_27 ) )
V_217 |= V_222 | V_223 ;
return V_217 ;
}
static struct V_224 * F_84 (
struct V_1 * V_2 ,
struct V_225 * V_153 ,
struct V_224 * V_226 ,
char * type )
{
struct V_224 * V_227 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_1 , V_6 ) ;
V_227 = F_85 () ;
if ( NULL == V_227 )
return NULL ;
* V_227 = * V_226 ;
snprintf ( V_227 -> V_64 , sizeof( V_227 -> V_64 ) , L_57 , V_4 -> V_64 ,
type , V_150 [ V_4 -> V_151 ] . V_64 ) ;
V_227 -> V_228 = & V_153 -> V_4 ;
V_227 -> V_229 = V_230 ;
return V_227 ;
}
int F_86 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_31 = - V_32 ;
F_2 ( V_5 , L_1 , V_6 ) ;
if ( V_2 -> type != V_231 )
F_30 () ;
if ( V_2 -> V_45 . V_232 == 0 ) {
F_14 ( V_47 L_7
L_58 ,
V_6 , V_31 ) ;
V_31 = - V_48 ;
goto V_49;
}
V_2 -> V_221 = F_84 ( V_2 ,
V_4 -> V_153 , & V_233 , L_59 ) ;
if ( ! V_2 -> V_221 ) {
F_14 ( V_234 L_60 ,
V_4 -> V_64 ) ;
V_31 = - V_48 ;
goto V_49;
}
F_87 ( V_2 -> V_221 , V_2 ) ;
V_31 = F_88 ( V_2 -> V_221 ,
V_235 , - 1 ) ;
if ( V_31 < 0 ) {
F_14 ( V_234 L_61 ,
V_4 -> V_64 ) ;
goto V_49;
}
F_14 ( V_234 L_62 ,
V_4 -> V_64 , V_2 -> V_221 -> V_236 ) ;
V_31 = 0 ;
V_49:
return V_31 ;
}
void F_89 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , L_35 , V_6 , V_2 -> V_26 ) ;
if ( V_2 -> type != V_231 )
F_30 () ;
if ( V_2 -> V_221 ) {
if ( V_2 -> V_221 -> V_237 != - 1 )
F_90 ( V_2 -> V_221 ) ;
else
V_230 ( V_2 -> V_221 ) ;
V_2 -> V_221 = NULL ;
}
}
