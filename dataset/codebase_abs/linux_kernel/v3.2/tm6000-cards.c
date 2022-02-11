void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ! V_2 -> V_4 . V_5 )
return;
if ( V_3 ) {
switch ( V_2 -> V_6 ) {
case V_7 :
case V_8 :
case V_9 :
F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_5 , 0x00 ) ;
break;
case V_11 :
case V_12 :
case V_13 :
case V_14 :
F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_5 , 0x01 ) ;
break;
}
}
else {
switch ( V_2 -> V_6 ) {
case V_7 :
case V_8 :
case V_9 :
F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_5 , 0x01 ) ;
break;
case V_11 :
case V_12 :
case V_13 :
case V_14 :
F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_5 , 0x00 ) ;
break;
}
}
}
int F_3 ( void * V_15 , int V_16 , int V_17 , int V_18 )
{
int V_19 = 0 ;
struct V_1 * V_2 = V_15 ;
if ( V_2 -> V_20 != V_21 )
return 0 ;
switch ( V_17 ) {
case V_22 :
F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_23 , 0x01 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_23 , 0x00 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_23 , 0x01 ) ;
break;
}
return V_19 ;
}
int F_5 ( void * V_15 , int V_16 , int V_17 , int V_18 )
{
int V_19 = 0 ;
struct V_1 * V_2 = V_15 ;
if ( V_2 -> V_20 != V_24 )
return 0 ;
switch ( V_17 ) {
case V_25 :
F_6 ( V_2 , 0 ) ;
F_2 ( V_2 , V_26 ,
0x02 , V_18 ) ;
F_4 ( 10 ) ;
V_19 = F_7 ( V_2 , 10 ) ;
break;
case V_27 :
switch ( V_18 ) {
case 0 :
switch ( V_2 -> V_6 ) {
case V_28 :
F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_23 , 0x01 ) ;
F_2 ( V_2 , V_10 ,
0x300 , 0x01 ) ;
F_4 ( 10 ) ;
F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_23 , 0x00 ) ;
F_2 ( V_2 , V_10 ,
0x300 , 0x00 ) ;
F_4 ( 10 ) ;
F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_23 , 0x01 ) ;
F_2 ( V_2 , V_10 ,
0x300 , 0x01 ) ;
break;
case V_7 :
case V_8 :
case V_9 :
F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_23 , 0x01 ) ;
F_4 ( 60 ) ;
F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_23 , 0x00 ) ;
F_4 ( 75 ) ;
F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_23 , 0x01 ) ;
F_4 ( 60 ) ;
break;
default:
F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_23 , 0x00 ) ;
F_4 ( 130 ) ;
F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_23 , 0x01 ) ;
F_4 ( 130 ) ;
break;
}
F_6 ( V_2 , 1 ) ;
break;
case 1 :
F_2 ( V_2 , V_26 ,
0x02 , 0x01 ) ;
F_4 ( 10 ) ;
break;
case 2 :
V_19 = F_7 ( V_2 , 100 ) ;
break;
}
break;
case V_29 :
F_2 ( V_2 , V_30 , 0 , 0 ) ;
F_2 ( V_2 , V_31 , 0 , 0 ) ;
break;
}
return V_19 ;
}
int F_8 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_6 ) {
case V_7 :
case V_8 :
case V_9 :
case V_32 :
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_33 , 0x01 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_34 , 0x00 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_35 , 0x00 ) ;
F_4 ( 50 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_35 , 0x01 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_34 , 0x01 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_36 , 0x01 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_5 , 0x00 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_37 , 0x01 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_34 , 0x00 ) ;
F_4 ( 15 ) ;
break;
case V_11 :
case V_13 :
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_5 , 0x01 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_35 , 0x00 ) ;
F_4 ( 50 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_35 , 0x01 ) ;
F_4 ( 15 ) ;
break;
case V_12 :
case V_14 :
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_5 , 0x01 ) ;
F_4 ( 15 ) ;
break;
default:
break;
}
if ( V_2 -> V_4 . V_23 ) {
int V_19 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < 2 ; V_38 ++ ) {
V_19 = F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_23 , 0x00 ) ;
if ( V_19 < 0 ) {
F_9 ( V_39 L_1 , V_19 ) ;
return V_19 ;
}
F_4 ( 10 ) ;
V_19 = F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_23 , 0x01 ) ;
if ( V_19 < 0 ) {
F_9 ( V_39 L_1 , V_19 ) ;
return V_19 ;
}
}
} else {
F_9 ( V_39 L_2 ) ;
return - 1 ;
}
F_4 ( 50 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_40 V_41 ;
F_11 ( & V_2 -> V_42 , & V_2 -> V_43 ,
L_3 , V_2 -> V_44 , NULL ) ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . type = V_2 -> V_20 ;
V_41 . V_45 = V_2 -> V_44 ;
V_41 . V_46 = 0 ;
if ( V_2 -> V_47 . V_48 )
V_41 . V_46 |= ( V_49 | V_50 ) ;
switch ( V_2 -> V_20 ) {
case V_24 :
V_41 . V_51 = F_5 ;
break;
case V_21 :
V_41 . V_51 = F_3 ;
break;
}
F_12 ( & V_2 -> V_42 , 0 , V_52 , V_53 , & V_41 ) ;
switch ( V_2 -> V_20 ) {
case V_24 : {
struct V_54 V_55 ;
struct V_56 V_57 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_58 = V_59 ;
V_55 . V_52 = V_24 ;
V_55 . V_60 = & V_57 ;
switch ( V_2 -> V_6 ) {
case V_7 :
case V_8 :
case V_9 :
V_57 . V_61 = L_4 ;
break;
default:
if ( V_2 -> V_62 == V_63 )
V_57 . V_61 = L_5 ;
else
V_57 . V_61 = L_6 ;
}
F_9 ( V_64 L_7 ) ;
F_12 ( & V_2 -> V_42 , 0 , V_52 , V_65 ,
& V_55 ) ;
}
break;
case V_21 :
{
struct V_54 V_66 ;
struct V_67 V_57 = {
. V_68 = V_2 -> V_44 ,
. V_69 = 4570 ,
. V_70 = V_71 ,
} ;
V_66 . V_52 = V_21 ;
V_66 . V_60 = & V_57 ;
F_12 ( & V_2 -> V_42 , 0 , V_52 , V_65 ,
& V_66 ) ;
}
break;
default:
F_9 ( V_64 L_8 ) ;
break;
}
}
static int F_13 ( struct V_1 * V_2 )
{
int V_19 ;
V_2 -> V_62 = V_72 [ V_2 -> V_6 ] . type ;
V_2 -> V_20 = V_72 [ V_2 -> V_6 ] . V_20 ;
V_2 -> V_44 = V_72 [ V_2 -> V_6 ] . V_44 ;
V_2 -> V_4 = V_72 [ V_2 -> V_6 ] . V_4 ;
V_2 -> V_73 = V_72 [ V_2 -> V_6 ] . V_73 ;
V_2 -> V_74 = V_72 [ V_2 -> V_6 ] . V_74 ;
V_2 -> V_47 = V_72 [ V_2 -> V_6 ] . V_47 ;
V_2 -> V_75 [ 0 ] = V_72 [ V_2 -> V_6 ] . V_75 [ 0 ] ;
V_2 -> V_75 [ 1 ] = V_72 [ V_2 -> V_6 ] . V_75 [ 1 ] ;
V_2 -> V_75 [ 2 ] = V_72 [ V_2 -> V_6 ] . V_75 [ 2 ] ;
V_2 -> V_76 = V_72 [ V_2 -> V_6 ] . V_76 ;
switch ( V_2 -> V_6 ) {
case V_8 :
V_2 -> V_77 |= V_78 ;
break;
default:
break;
}
V_19 = F_14 ( V_2 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_15 ( & V_2 -> V_79 -> V_2 , & V_2 -> V_42 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_38 , V_6 = - 1 ;
if ( ! V_2 -> V_80 )
return;
for ( V_38 = 0 ; V_38 < F_17 ( V_72 ) ; V_38 ++ ) {
if ( ! V_72 [ V_38 ] . V_81 )
continue;
if ( V_2 -> V_80 < V_72 [ V_38 ] . V_82 +
V_72 [ V_38 ] . V_81 )
continue;
if ( ! memcmp ( & V_2 -> V_83 [ V_72 [ V_38 ] . V_82 ] ,
V_72 [ V_38 ] . V_84 ,
V_72 [ V_38 ] . V_81 ) ) {
V_6 = V_38 ;
break;
}
}
if ( V_6 < 0 ) {
F_9 ( V_64 L_9 ) ;
return;
}
V_2 -> V_6 = V_6 ;
F_9 ( V_64 L_10 ,
V_72 [ V_6 ] . V_85 , V_6 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_86 V_87 ;
int V_19 = 0 ;
F_19 ( & V_2 -> V_88 ) ;
F_20 ( & V_2 -> V_88 ) ;
if ( ! F_21 ( V_2 -> V_6 ) ) {
V_19 = F_13 ( V_2 ) ;
if ( V_19 < 0 )
goto V_89;
V_19 = F_22 ( V_2 ) ;
if ( V_19 < 0 )
goto V_89;
} else {
V_19 = F_22 ( V_2 ) ;
if ( V_19 < 0 )
goto V_89;
F_16 ( V_2 ) ;
V_19 = F_13 ( V_2 ) ;
if ( V_19 < 0 )
goto V_89;
}
V_2 -> V_90 = 720 ;
V_2 -> V_91 = 480 ;
V_2 -> V_92 = V_93 ;
F_10 ( V_2 ) ;
F_12 ( & V_2 -> V_42 , 0 , V_94 , V_95 , V_2 -> V_92 ) ;
V_87 . V_52 = 0 ;
V_87 . type = V_96 ;
V_87 . V_97 = 3092 ;
V_2 -> V_98 = V_87 . V_97 ;
F_12 ( & V_2 -> V_42 , 0 , V_52 , V_99 , & V_87 ) ;
if ( V_2 -> V_47 . V_100 )
F_11 ( & V_2 -> V_42 , & V_2 -> V_43 ,
L_11 , V_101 , NULL ) ;
V_19 = F_23 ( V_2 ) ;
if ( V_19 < 0 )
goto V_89;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( & V_2 -> V_88 ) ;
return 0 ;
V_89:
F_27 ( & V_2 -> V_88 ) ;
return V_19 ;
}
static void F_28 ( struct V_102 * V_79 ,
struct V_103 * V_104 ,
char * V_105 ,
struct V_106 * V_107 ,
struct V_108 * V_109 )
{
T_2 V_110 = F_29 ( V_107 -> V_111 . V_112 ) ;
unsigned int V_113 = V_110 & 0x7ff ;
if ( V_79 -> V_114 == V_115 )
V_113 = V_113 * F_30 ( V_110 ) ;
if ( V_113 > V_109 -> V_116 ) {
V_109 -> V_117 = V_107 ;
V_109 -> V_116 = V_113 ;
V_109 -> V_118 = V_104 -> V_111 . V_118 ;
V_109 -> V_119 = V_104 -> V_111 . V_119 ;
F_9 ( V_64 L_12 ,
V_105 , V_107 -> V_111 . V_120 ,
V_113 ) ;
}
}
static int F_31 ( struct V_121 * V_122 ,
const struct V_123 * V_124 )
{
struct V_102 * V_125 ;
struct V_1 * V_2 = NULL ;
int V_38 , V_19 = 0 ;
int V_126 = 0 ;
char * V_114 ;
V_125 = F_32 ( F_33 ( V_122 ) ) ;
V_19 = F_34 ( V_125 , 0 , 1 ) ;
if ( V_19 < 0 )
goto V_89;
V_126 = F_35 ( & V_127 , V_128 ) ;
if ( V_126 >= V_128 ) {
F_9 ( V_39 L_13 , V_128 ) ;
F_36 ( V_125 ) ;
return - V_129 ;
}
V_2 = F_37 ( sizeof( * V_2 ) , V_130 ) ;
if ( V_2 == NULL ) {
F_9 ( V_39 L_14 L_15 ) ;
F_36 ( V_125 ) ;
return - V_129 ;
}
F_38 ( & V_2 -> V_131 ) ;
F_19 ( & V_2 -> V_132 ) ;
F_39 ( V_126 , & V_127 ) ;
snprintf ( V_2 -> V_85 , 29 , L_16 , V_126 ) ;
V_2 -> V_6 = V_124 -> V_133 ;
if ( V_134 [ V_126 ] < F_17 ( V_72 ) )
V_2 -> V_6 = V_134 [ V_126 ] ;
V_2 -> V_79 = V_125 ;
V_2 -> V_135 = V_126 ;
switch ( V_125 -> V_114 ) {
case V_136 :
V_114 = L_17 ;
break;
case V_137 :
case V_138 :
V_114 = L_18 ;
break;
case V_115 :
V_114 = L_19 ;
break;
default:
V_114 = L_20 ;
}
for ( V_38 = 0 ; V_38 < V_122 -> V_139 ; V_38 ++ ) {
int V_140 ;
for ( V_140 = 0 ; V_140 < V_122 -> V_141 [ V_38 ] . V_111 . V_142 ; V_140 ++ ) {
struct V_106 * V_143 ;
int V_144 ;
V_143 = & V_122 -> V_141 [ V_38 ] . V_145 [ V_140 ] ;
V_144 = ( ( V_143 -> V_111 . V_120 &
V_146 ) == V_147 ) ;
F_9 ( V_64 L_21 ,
V_38 ,
V_122 -> V_141 [ V_38 ] . V_111 . V_118 ,
V_122 -> V_141 [ V_38 ] . V_111 . V_148 ) ;
switch ( V_143 -> V_111 . V_149 ) {
case V_150 :
if ( ! V_144 ) {
F_28 ( V_125 ,
& V_122 -> V_141 [ V_38 ] ,
L_22 , V_143 ,
& V_2 -> V_151 ) ;
} else {
F_28 ( V_125 ,
& V_122 -> V_141 [ V_38 ] ,
L_23 , V_143 ,
& V_2 -> V_152 ) ;
}
break;
case V_153 :
if ( ! V_144 ) {
F_28 ( V_125 ,
& V_122 -> V_141 [ V_38 ] ,
L_24 , V_143 ,
& V_2 -> V_154 ) ;
} else {
F_28 ( V_125 ,
& V_122 -> V_141 [ V_38 ] ,
L_25 , V_143 ,
& V_2 -> V_155 ) ;
}
break;
case V_156 :
if ( ! V_144 ) {
F_28 ( V_125 ,
& V_122 -> V_141 [ V_38 ] ,
L_26 , V_143 ,
& V_2 -> V_157 ) ;
} else {
F_28 ( V_125 ,
& V_122 -> V_141 [ V_38 ] ,
L_27 , V_143 ,
& V_2 -> V_158 ) ;
}
break;
}
}
}
F_9 ( V_64 L_28 ,
V_114 ,
F_29 ( V_2 -> V_79 -> V_159 . V_160 ) ,
F_29 ( V_2 -> V_79 -> V_159 . V_161 ) ,
V_122 -> V_141 -> V_111 . V_118 ) ;
if ( ! V_2 -> V_154 . V_117 ) {
F_9 ( V_39 L_29 ) ;
V_19 = - V_162 ;
goto V_89;
}
F_40 ( V_122 , V_2 ) ;
F_9 ( V_64 L_30 , V_72 [ V_2 -> V_6 ] . V_85 ) ;
V_19 = F_18 ( V_2 ) ;
if ( V_19 < 0 )
goto V_89;
return 0 ;
V_89:
F_9 ( V_39 L_31 , V_19 ) ;
F_41 ( V_126 , & V_127 ) ;
F_36 ( V_125 ) ;
F_42 ( V_2 ) ;
return V_19 ;
}
static void F_43 ( struct V_121 * V_122 )
{
struct V_1 * V_2 = F_44 ( V_122 ) ;
F_40 ( V_122 , NULL ) ;
if ( ! V_2 )
return;
F_9 ( V_64 L_32 , V_2 -> V_85 ) ;
F_45 ( V_2 ) ;
if ( V_2 -> V_4 . V_5 ) {
switch ( V_2 -> V_6 ) {
case V_7 :
case V_8 :
case V_9 :
F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_5 , 0x01 ) ;
F_4 ( 15 ) ;
break;
case V_11 :
case V_12 :
case V_13 :
case V_14 :
F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_5 , 0x00 ) ;
F_4 ( 15 ) ;
break;
}
}
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_48 ( & V_2 -> V_42 ) ;
V_2 -> V_3 |= V_163 ;
F_36 ( V_2 -> V_79 ) ;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
F_41 ( V_2 -> V_135 , & V_127 ) ;
F_42 ( V_2 ) ;
}
static int T_3 F_51 ( void )
{
int V_164 ;
F_9 ( V_64 L_14 L_33 ,
( V_165 >> 16 ) & 0xff ,
( V_165 >> 8 ) & 0xff , V_165 & 0xff ) ;
V_164 = F_52 ( & V_166 ) ;
if ( V_164 )
F_9 ( V_39 L_14
L_34 , V_164 ) ;
return V_164 ;
}
static void T_4 F_53 ( void )
{
F_54 ( & V_166 ) ;
}
