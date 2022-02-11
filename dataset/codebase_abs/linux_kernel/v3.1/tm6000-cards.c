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
}
return V_19 ;
}
int F_8 ( struct V_1 * V_2 )
{
int V_29 , V_19 ;
switch ( V_2 -> V_6 ) {
case V_7 :
case V_8 :
case V_9 :
case V_30 :
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_31 , 0x01 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_32 , 0x00 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_33 , 0x00 ) ;
F_4 ( 50 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_33 , 0x01 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_32 , 0x01 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_34 , 0x01 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_5 , 0x00 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_35 , 0x01 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_32 , 0x00 ) ;
F_4 ( 15 ) ;
break;
case V_11 :
case V_13 :
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_5 , 0x01 ) ;
F_4 ( 15 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_33 , 0x00 ) ;
F_4 ( 50 ) ;
F_2 ( V_2 , V_10 , V_2 -> V_4 . V_33 , 0x01 ) ;
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
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ ) {
V_19 = F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_23 , 0x00 ) ;
if ( V_19 < 0 ) {
F_9 ( V_36 L_1 , V_19 ) ;
return V_19 ;
}
F_4 ( 10 ) ;
V_19 = F_2 ( V_2 , V_10 ,
V_2 -> V_4 . V_23 , 0x01 ) ;
if ( V_19 < 0 ) {
F_9 ( V_36 L_1 , V_19 ) ;
return V_19 ;
}
}
} else {
F_9 ( V_36 L_2 ) ;
return - 1 ;
}
F_4 ( 50 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_37 V_38 ;
F_11 ( & V_2 -> V_39 , & V_2 -> V_40 ,
L_3 , V_2 -> V_41 , NULL ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . type = V_2 -> V_20 ;
V_38 . V_42 = V_2 -> V_41 ;
V_38 . V_43 = 0 ;
if ( V_2 -> V_44 . V_45 )
V_38 . V_43 |= ( V_46 | V_47 ) ;
switch ( V_2 -> V_20 ) {
case V_24 :
V_38 . V_48 = F_5 ;
break;
case V_21 :
V_38 . V_48 = F_3 ;
break;
}
F_12 ( & V_2 -> V_39 , 0 , V_49 , V_50 , & V_38 ) ;
switch ( V_2 -> V_20 ) {
case V_24 : {
struct V_51 V_52 ;
struct V_53 V_54 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_55 = V_56 ;
V_52 . V_49 = V_24 ;
V_52 . V_57 = & V_54 ;
switch ( V_2 -> V_6 ) {
case V_7 :
case V_8 :
case V_9 :
V_54 . V_58 = L_4 ;
break;
default:
if ( V_2 -> V_59 == V_60 )
V_54 . V_58 = L_5 ;
else
V_54 . V_58 = L_6 ;
}
F_9 ( V_61 L_7 ) ;
F_12 ( & V_2 -> V_39 , 0 , V_49 , V_62 ,
& V_52 ) ;
}
break;
case V_21 :
{
struct V_51 V_63 ;
struct V_64 V_54 = {
. V_65 = V_2 -> V_41 ,
. V_66 = 4570 ,
. V_67 = V_68 ,
} ;
V_63 . V_49 = V_21 ;
V_63 . V_57 = & V_54 ;
F_12 ( & V_2 -> V_39 , 0 , V_49 , V_62 ,
& V_63 ) ;
}
break;
default:
F_9 ( V_61 L_8 ) ;
break;
}
}
static int F_13 ( struct V_1 * V_2 )
{
int V_19 ;
V_2 -> V_59 = V_69 [ V_2 -> V_6 ] . type ;
V_2 -> V_20 = V_69 [ V_2 -> V_6 ] . V_20 ;
V_2 -> V_41 = V_69 [ V_2 -> V_6 ] . V_41 ;
V_2 -> V_4 = V_69 [ V_2 -> V_6 ] . V_4 ;
V_2 -> V_70 = V_69 [ V_2 -> V_6 ] . V_70 ;
V_2 -> V_71 = V_69 [ V_2 -> V_6 ] . V_71 ;
V_2 -> V_44 = V_69 [ V_2 -> V_6 ] . V_44 ;
V_2 -> V_72 [ 0 ] = V_69 [ V_2 -> V_6 ] . V_72 [ 0 ] ;
V_2 -> V_72 [ 1 ] = V_69 [ V_2 -> V_6 ] . V_72 [ 1 ] ;
V_2 -> V_72 [ 2 ] = V_69 [ V_2 -> V_6 ] . V_72 [ 2 ] ;
V_2 -> V_73 = V_69 [ V_2 -> V_6 ] . V_73 ;
V_19 = F_14 ( V_2 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_15 ( & V_2 -> V_74 -> V_2 , & V_2 -> V_39 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_29 , V_6 = - 1 ;
if ( ! V_2 -> V_75 )
return;
for ( V_29 = 0 ; V_29 < F_17 ( V_69 ) ; V_29 ++ ) {
if ( ! V_69 [ V_29 ] . V_76 )
continue;
if ( V_2 -> V_75 < V_69 [ V_29 ] . V_77 +
V_69 [ V_29 ] . V_76 )
continue;
if ( ! memcmp ( & V_2 -> V_78 [ V_69 [ V_29 ] . V_77 ] ,
V_69 [ V_29 ] . V_79 ,
V_69 [ V_29 ] . V_76 ) ) {
V_6 = V_29 ;
break;
}
}
if ( V_6 < 0 ) {
F_9 ( V_61 L_9 ) ;
return;
}
V_2 -> V_6 = V_6 ;
F_9 ( V_61 L_10 ,
V_69 [ V_6 ] . V_80 , V_6 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_81 V_82 ;
int V_19 = 0 ;
F_19 ( & V_2 -> V_83 ) ;
F_20 ( & V_2 -> V_83 ) ;
if ( ! F_21 ( V_2 -> V_6 ) ) {
V_19 = F_13 ( V_2 ) ;
if ( V_19 < 0 )
goto V_84;
V_19 = F_22 ( V_2 ) ;
if ( V_19 < 0 )
goto V_84;
} else {
V_19 = F_22 ( V_2 ) ;
if ( V_19 < 0 )
goto V_84;
F_16 ( V_2 ) ;
V_19 = F_13 ( V_2 ) ;
if ( V_19 < 0 )
goto V_84;
}
V_2 -> V_85 = 720 ;
V_2 -> V_86 = 480 ;
V_2 -> V_87 = V_88 ;
F_10 ( V_2 ) ;
F_12 ( & V_2 -> V_39 , 0 , V_89 , V_90 , V_2 -> V_87 ) ;
V_82 . V_49 = 0 ;
V_82 . type = V_91 ;
V_82 . V_92 = 3092 ;
V_2 -> V_93 = V_82 . V_92 ;
F_12 ( & V_2 -> V_39 , 0 , V_49 , V_94 , & V_82 ) ;
if ( V_2 -> V_44 . V_95 )
F_11 ( & V_2 -> V_39 , & V_2 -> V_40 ,
L_11 , V_96 , NULL ) ;
V_19 = F_23 ( V_2 ) ;
if ( V_19 < 0 )
goto V_84;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( & V_2 -> V_83 ) ;
return 0 ;
V_84:
F_27 ( & V_2 -> V_83 ) ;
return V_19 ;
}
static void F_28 ( struct V_97 * V_74 ,
struct V_98 * V_99 ,
char * V_100 ,
struct V_101 * V_102 ,
struct V_103 * V_104 )
{
T_2 V_105 = F_29 ( V_102 -> V_106 . V_107 ) ;
unsigned int V_108 = V_105 & 0x7ff ;
if ( V_74 -> V_109 == V_110 )
V_108 = V_108 * F_30 ( V_105 ) ;
if ( V_108 > V_104 -> V_111 ) {
V_104 -> V_112 = V_102 ;
V_104 -> V_111 = V_108 ;
V_104 -> V_113 = V_99 -> V_106 . V_113 ;
V_104 -> V_114 = V_99 -> V_106 . V_114 ;
F_9 ( V_61 L_12 ,
V_100 , V_102 -> V_106 . V_115 ,
V_108 ) ;
}
}
static int F_31 ( struct V_116 * V_117 ,
const struct V_118 * V_119 )
{
struct V_97 * V_120 ;
struct V_1 * V_2 = NULL ;
int V_29 , V_19 = 0 ;
int V_121 = 0 ;
char * V_109 ;
V_120 = F_32 ( F_33 ( V_117 ) ) ;
V_19 = F_34 ( V_120 , 0 , 1 ) ;
if ( V_19 < 0 )
goto V_84;
V_121 = F_35 ( & V_122 , V_123 ) ;
if ( V_121 >= V_123 ) {
F_9 ( V_36 L_13 , V_123 ) ;
F_36 ( V_120 ) ;
return - V_124 ;
}
V_2 = F_37 ( sizeof( * V_2 ) , V_125 ) ;
if ( V_2 == NULL ) {
F_9 ( V_36 L_14 L_15 ) ;
F_36 ( V_120 ) ;
return - V_124 ;
}
F_38 ( & V_2 -> V_126 ) ;
V_122 |= 1 << V_121 ;
snprintf ( V_2 -> V_80 , 29 , L_16 , V_121 ) ;
V_2 -> V_6 = V_119 -> V_127 ;
if ( ( V_128 [ V_121 ] >= 0 ) && ( V_128 [ V_121 ] < F_17 ( V_69 ) ) )
V_2 -> V_6 = V_128 [ V_121 ] ;
V_2 -> V_74 = V_120 ;
V_2 -> V_129 = V_121 ;
switch ( V_120 -> V_109 ) {
case V_130 :
V_109 = L_17 ;
break;
case V_131 :
case V_132 :
V_109 = L_18 ;
break;
case V_110 :
V_109 = L_19 ;
break;
default:
V_109 = L_20 ;
}
for ( V_29 = 0 ; V_29 < V_117 -> V_133 ; V_29 ++ ) {
int V_134 ;
for ( V_134 = 0 ; V_134 < V_117 -> V_135 [ V_29 ] . V_106 . V_136 ; V_134 ++ ) {
struct V_101 * V_137 ;
int V_138 ;
V_137 = & V_117 -> V_135 [ V_29 ] . V_139 [ V_134 ] ;
V_138 = ( ( V_137 -> V_106 . V_115 &
V_140 ) == V_141 ) ;
F_9 ( V_61 L_21 ,
V_29 ,
V_117 -> V_135 [ V_29 ] . V_106 . V_113 ,
V_117 -> V_135 [ V_29 ] . V_106 . V_142 ) ;
switch ( V_137 -> V_106 . V_143 ) {
case V_144 :
if ( ! V_138 ) {
F_28 ( V_120 ,
& V_117 -> V_135 [ V_29 ] ,
L_22 , V_137 ,
& V_2 -> V_145 ) ;
} else {
F_28 ( V_120 ,
& V_117 -> V_135 [ V_29 ] ,
L_23 , V_137 ,
& V_2 -> V_146 ) ;
}
break;
case V_147 :
if ( ! V_138 ) {
F_28 ( V_120 ,
& V_117 -> V_135 [ V_29 ] ,
L_24 , V_137 ,
& V_2 -> V_148 ) ;
} else {
F_28 ( V_120 ,
& V_117 -> V_135 [ V_29 ] ,
L_25 , V_137 ,
& V_2 -> V_149 ) ;
}
break;
case V_150 :
if ( ! V_138 ) {
F_28 ( V_120 ,
& V_117 -> V_135 [ V_29 ] ,
L_26 , V_137 ,
& V_2 -> V_151 ) ;
} else {
F_28 ( V_120 ,
& V_117 -> V_135 [ V_29 ] ,
L_27 , V_137 ,
& V_2 -> V_152 ) ;
}
break;
}
}
}
F_9 ( V_61 L_28 ,
V_109 ,
F_29 ( V_2 -> V_74 -> V_153 . V_154 ) ,
F_29 ( V_2 -> V_74 -> V_153 . V_155 ) ,
V_117 -> V_135 -> V_106 . V_113 ) ;
if ( ! V_2 -> V_148 . V_112 ) {
F_9 ( V_36 L_29 ) ;
V_19 = - V_156 ;
goto V_84;
}
F_39 ( V_117 , V_2 ) ;
F_9 ( V_61 L_30 , V_69 [ V_2 -> V_6 ] . V_80 ) ;
V_19 = F_18 ( V_2 ) ;
if ( V_19 < 0 )
goto V_84;
return 0 ;
V_84:
F_9 ( V_36 L_31 , V_19 ) ;
V_122 &= ~ ( 1 << V_121 ) ;
F_36 ( V_120 ) ;
F_40 ( V_2 ) ;
return V_19 ;
}
static void F_41 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = F_42 ( V_117 ) ;
F_39 ( V_117 , NULL ) ;
if ( ! V_2 )
return;
F_9 ( V_61 L_32 , V_2 -> V_80 ) ;
F_43 ( V_2 ) ;
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
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( & V_2 -> V_39 ) ;
V_2 -> V_3 |= V_157 ;
F_36 ( V_2 -> V_74 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
F_40 ( V_2 ) ;
}
static int T_3 F_49 ( void )
{
int V_158 ;
F_9 ( V_61 L_14 L_33 ,
( V_159 >> 16 ) & 0xff ,
( V_159 >> 8 ) & 0xff , V_159 & 0xff ) ;
V_158 = F_50 ( & V_160 ) ;
if ( V_158 )
F_9 ( V_36 L_14
L_34 , V_158 ) ;
return V_158 ;
}
static void T_4 F_51 ( void )
{
F_52 ( & V_160 ) ;
}
