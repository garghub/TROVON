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
V_57 . V_61 = 80 ;
V_57 . V_62 = L_4 ;
break;
default:
if ( V_2 -> V_63 == V_64 )
V_57 . V_62 = L_5 ;
else
V_57 . V_62 = L_6 ;
}
F_9 ( V_65 L_7 ) ;
F_12 ( & V_2 -> V_42 , 0 , V_52 , V_66 ,
& V_55 ) ;
}
break;
case V_21 :
{
struct V_54 V_67 ;
struct V_68 V_57 = {
. V_69 = V_2 -> V_44 ,
. V_70 = 4570 ,
. V_71 = V_72 ,
} ;
V_67 . V_52 = V_21 ;
V_67 . V_60 = & V_57 ;
F_12 ( & V_2 -> V_42 , 0 , V_52 , V_66 ,
& V_67 ) ;
}
break;
default:
F_9 ( V_65 L_8 ) ;
break;
}
}
static int F_13 ( struct V_1 * V_2 )
{
int V_19 ;
V_2 -> V_63 = V_73 [ V_2 -> V_6 ] . type ;
V_2 -> V_20 = V_73 [ V_2 -> V_6 ] . V_20 ;
V_2 -> V_44 = V_73 [ V_2 -> V_6 ] . V_44 ;
V_2 -> V_4 = V_73 [ V_2 -> V_6 ] . V_4 ;
V_2 -> V_74 = V_73 [ V_2 -> V_6 ] . V_74 ;
V_2 -> V_75 = V_73 [ V_2 -> V_6 ] . V_75 ;
V_2 -> V_47 = V_73 [ V_2 -> V_6 ] . V_47 ;
V_2 -> V_76 [ 0 ] = V_73 [ V_2 -> V_6 ] . V_76 [ 0 ] ;
V_2 -> V_76 [ 1 ] = V_73 [ V_2 -> V_6 ] . V_76 [ 1 ] ;
V_2 -> V_76 [ 2 ] = V_73 [ V_2 -> V_6 ] . V_76 [ 2 ] ;
V_2 -> V_77 = V_73 [ V_2 -> V_6 ] . V_77 ;
switch ( V_2 -> V_6 ) {
case V_8 :
case V_7 :
V_2 -> V_78 |= V_79 ;
break;
default:
break;
}
V_19 = F_14 ( V_2 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_15 ( & V_2 -> V_80 -> V_2 , & V_2 -> V_42 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_38 , V_6 = - 1 ;
if ( ! V_2 -> V_81 )
return;
for ( V_38 = 0 ; V_38 < F_17 ( V_73 ) ; V_38 ++ ) {
if ( ! V_73 [ V_38 ] . V_82 )
continue;
if ( V_2 -> V_81 < V_73 [ V_38 ] . V_83 +
V_73 [ V_38 ] . V_82 )
continue;
if ( ! memcmp ( & V_2 -> V_84 [ V_73 [ V_38 ] . V_83 ] ,
V_73 [ V_38 ] . V_85 ,
V_73 [ V_38 ] . V_82 ) ) {
V_6 = V_38 ;
break;
}
}
if ( V_6 < 0 ) {
F_9 ( V_65 L_9 ) ;
return;
}
V_2 -> V_6 = V_6 ;
F_9 ( V_65 L_10 ,
V_73 [ V_6 ] . V_86 , V_6 ) ;
}
static void F_18 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = F_19 ( V_88 , struct V_1 ,
V_89 ) ;
F_20 ( L_11 ) ;
if ( V_2 -> V_47 . V_90 )
F_20 ( L_12 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_89 , F_18 ) ;
F_23 ( & V_2 -> V_89 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_25 ( & V_2 -> V_89 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_91 V_92 ;
int V_19 = 0 ;
F_27 ( & V_2 -> V_93 ) ;
F_28 ( & V_2 -> V_93 ) ;
if ( ! F_29 ( V_2 -> V_6 ) ) {
V_19 = F_13 ( V_2 ) ;
if ( V_19 < 0 )
goto V_94;
V_19 = F_30 ( V_2 ) ;
if ( V_19 < 0 )
goto V_94;
} else {
V_19 = F_30 ( V_2 ) ;
if ( V_19 < 0 )
goto V_94;
F_16 ( V_2 ) ;
V_19 = F_13 ( V_2 ) ;
if ( V_19 < 0 )
goto V_94;
}
V_2 -> V_95 = 720 ;
V_2 -> V_96 = 480 ;
V_2 -> V_97 = V_98 ;
F_10 ( V_2 ) ;
F_12 ( & V_2 -> V_42 , 0 , V_99 , V_100 , V_2 -> V_97 ) ;
V_92 . V_52 = 0 ;
V_92 . type = V_101 ;
V_92 . V_102 = 3092 ;
V_2 -> V_103 = V_92 . V_102 ;
F_12 ( & V_2 -> V_42 , 0 , V_52 , V_104 , & V_92 ) ;
if ( V_2 -> V_47 . V_105 )
F_11 ( & V_2 -> V_42 , & V_2 -> V_43 ,
L_13 , V_106 , NULL ) ;
V_19 = F_31 ( V_2 ) ;
if ( V_19 < 0 )
goto V_94;
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
F_21 ( V_2 ) ;
F_35 ( & V_2 -> V_93 ) ;
return 0 ;
V_94:
F_35 ( & V_2 -> V_93 ) ;
return V_19 ;
}
static void F_36 ( struct V_107 * V_80 ,
struct V_108 * V_109 ,
char * V_110 ,
struct V_111 * V_112 ,
struct V_113 * V_114 )
{
T_2 V_115 = F_37 ( V_112 -> V_116 . V_117 ) ;
unsigned int V_118 = V_115 & 0x7ff ;
if ( V_80 -> V_119 == V_120 )
V_118 = V_118 * F_38 ( V_115 ) ;
if ( V_118 > V_114 -> V_121 ) {
V_114 -> V_122 = V_112 ;
V_114 -> V_121 = V_118 ;
V_114 -> V_123 = V_109 -> V_116 . V_123 ;
V_114 -> V_124 = V_109 -> V_116 . V_124 ;
F_9 ( V_65 L_14 ,
V_110 , V_112 -> V_116 . V_125 ,
V_118 ) ;
}
}
static int F_39 ( struct V_126 * V_127 ,
const struct V_128 * V_129 )
{
struct V_107 * V_130 ;
struct V_1 * V_2 = NULL ;
int V_38 , V_19 = 0 ;
int V_131 = 0 ;
char * V_119 ;
V_130 = F_40 ( F_41 ( V_127 ) ) ;
V_19 = F_42 ( V_130 , 0 , 1 ) ;
if ( V_19 < 0 )
goto V_94;
V_131 = F_43 ( & V_132 , V_133 ) ;
if ( V_131 >= V_133 ) {
F_9 ( V_39 L_15 , V_133 ) ;
F_44 ( V_130 ) ;
return - V_134 ;
}
V_2 = F_45 ( sizeof( * V_2 ) , V_135 ) ;
if ( V_2 == NULL ) {
F_9 ( V_39 L_16 L_17 ) ;
F_44 ( V_130 ) ;
return - V_134 ;
}
F_46 ( & V_2 -> V_136 ) ;
F_27 ( & V_2 -> V_137 ) ;
F_47 ( V_131 , & V_132 ) ;
snprintf ( V_2 -> V_86 , 29 , L_18 , V_131 ) ;
V_2 -> V_6 = V_129 -> V_138 ;
if ( V_139 [ V_131 ] < F_17 ( V_73 ) )
V_2 -> V_6 = V_139 [ V_131 ] ;
V_2 -> V_80 = V_130 ;
V_2 -> V_140 = V_131 ;
switch ( V_130 -> V_119 ) {
case V_141 :
V_119 = L_19 ;
break;
case V_142 :
case V_143 :
V_119 = L_20 ;
break;
case V_120 :
V_119 = L_21 ;
break;
default:
V_119 = L_22 ;
}
for ( V_38 = 0 ; V_38 < V_127 -> V_144 ; V_38 ++ ) {
int V_145 ;
for ( V_145 = 0 ; V_145 < V_127 -> V_146 [ V_38 ] . V_116 . V_147 ; V_145 ++ ) {
struct V_111 * V_148 ;
int V_149 ;
V_148 = & V_127 -> V_146 [ V_38 ] . V_150 [ V_145 ] ;
V_149 = ( ( V_148 -> V_116 . V_125 &
V_151 ) == V_152 ) ;
F_9 ( V_65 L_23 ,
V_38 ,
V_127 -> V_146 [ V_38 ] . V_116 . V_123 ,
V_127 -> V_146 [ V_38 ] . V_116 . V_153 ) ;
switch ( V_148 -> V_116 . V_154 ) {
case V_155 :
if ( ! V_149 ) {
F_36 ( V_130 ,
& V_127 -> V_146 [ V_38 ] ,
L_24 , V_148 ,
& V_2 -> V_156 ) ;
} else {
F_36 ( V_130 ,
& V_127 -> V_146 [ V_38 ] ,
L_25 , V_148 ,
& V_2 -> V_157 ) ;
}
break;
case V_158 :
if ( ! V_149 ) {
F_36 ( V_130 ,
& V_127 -> V_146 [ V_38 ] ,
L_26 , V_148 ,
& V_2 -> V_159 ) ;
} else {
F_36 ( V_130 ,
& V_127 -> V_146 [ V_38 ] ,
L_27 , V_148 ,
& V_2 -> V_160 ) ;
}
break;
case V_161 :
if ( ! V_149 ) {
F_36 ( V_130 ,
& V_127 -> V_146 [ V_38 ] ,
L_28 , V_148 ,
& V_2 -> V_162 ) ;
} else {
F_36 ( V_130 ,
& V_127 -> V_146 [ V_38 ] ,
L_29 , V_148 ,
& V_2 -> V_163 ) ;
}
break;
}
}
}
F_9 ( V_65 L_30 ,
V_119 ,
F_37 ( V_2 -> V_80 -> V_164 . V_165 ) ,
F_37 ( V_2 -> V_80 -> V_164 . V_166 ) ,
V_127 -> V_146 -> V_116 . V_123 ) ;
if ( ! V_2 -> V_159 . V_122 ) {
F_9 ( V_39 L_31 ) ;
V_19 = - V_167 ;
goto V_94;
}
F_48 ( V_127 , V_2 ) ;
F_9 ( V_65 L_32 , V_73 [ V_2 -> V_6 ] . V_86 ) ;
V_19 = F_26 ( V_2 ) ;
if ( V_19 < 0 )
goto V_94;
return 0 ;
V_94:
F_9 ( V_39 L_33 , V_19 ) ;
F_49 ( V_131 , & V_132 ) ;
F_44 ( V_130 ) ;
F_50 ( V_2 ) ;
return V_19 ;
}
static void F_51 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = F_52 ( V_127 ) ;
F_48 ( V_127 , NULL ) ;
if ( ! V_2 )
return;
F_9 ( V_65 L_34 , V_2 -> V_86 ) ;
F_24 ( V_2 ) ;
F_53 ( V_2 ) ;
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
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
F_56 ( & V_2 -> V_42 ) ;
V_2 -> V_3 |= V_168 ;
F_44 ( V_2 -> V_80 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 ) ;
F_49 ( V_2 -> V_140 , & V_132 ) ;
F_50 ( V_2 ) ;
}
