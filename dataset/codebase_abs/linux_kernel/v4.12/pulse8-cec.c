static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
switch ( V_3 -> V_4 [ 0 ] & 0x3f ) {
case V_5 :
F_3 ( V_3 -> V_6 , & V_3 -> V_7 ) ;
break;
case V_8 :
F_4 ( V_3 -> V_6 , V_9 ,
0 , 0 , 0 , 0 ) ;
break;
case V_10 :
F_4 ( V_3 -> V_6 , V_11 ,
0 , 1 , 0 , 0 ) ;
break;
case V_12 :
case V_13 :
case V_14 :
F_4 ( V_3 -> V_6 , V_15 ,
0 , 0 , 0 , 1 ) ;
break;
}
}
static T_1 F_5 ( struct V_16 * V_16 , unsigned char V_4 ,
unsigned int V_17 )
{
struct V_3 * V_3 = F_6 ( V_16 ) ;
if ( ! V_3 -> V_18 && V_4 != V_19 )
return V_20 ;
if ( V_4 == V_21 ) {
V_3 -> V_22 = true ;
return V_20 ;
}
if ( V_3 -> V_22 ) {
V_4 += V_23 ;
V_3 -> V_22 = false ;
} else if ( V_4 == V_24 ) {
struct V_25 * V_26 = & V_3 -> V_7 ;
if ( V_27 )
F_7 ( V_3 -> V_28 , L_1 ,
V_3 -> V_29 , V_3 -> V_30 ) ;
V_3 -> V_4 [ 0 ] = V_3 -> V_30 [ 0 ] ;
switch ( V_3 -> V_30 [ 0 ] & 0x3f ) {
case V_31 :
V_26 -> V_32 = 1 ;
V_26 -> V_26 [ 0 ] = V_3 -> V_30 [ 1 ] ;
break;
case V_5 :
if ( V_26 -> V_32 == V_33 )
break;
V_26 -> V_26 [ V_26 -> V_32 ++ ] = V_3 -> V_30 [ 1 ] ;
if ( V_3 -> V_30 [ 0 ] & V_34 )
F_8 ( & V_3 -> V_2 ) ;
break;
case V_8 :
case V_12 :
case V_10 :
case V_13 :
case V_14 :
F_8 ( & V_3 -> V_2 ) ;
break;
case V_35 :
case V_36 :
case V_37 :
case V_38 :
break;
case V_39 :
case V_40 :
default:
if ( V_3 -> V_29 == 0 )
break;
memcpy ( V_3 -> V_4 , V_3 -> V_30 , V_3 -> V_29 ) ;
V_3 -> V_32 = V_3 -> V_29 ;
F_9 ( & V_3 -> V_41 ) ;
break;
}
V_3 -> V_29 = 0 ;
V_3 -> V_18 = false ;
return V_20 ;
} else if ( V_4 == V_19 ) {
V_3 -> V_29 = 0 ;
V_3 -> V_18 = true ;
return V_20 ;
}
if ( V_3 -> V_29 >= V_42 ) {
F_10 ( V_3 -> V_28 ,
L_2 , V_3 -> V_29 ) ;
V_3 -> V_29 = 0 ;
}
V_3 -> V_30 [ V_3 -> V_29 ++ ] = V_4 ;
return V_20 ;
}
static void F_11 ( struct V_16 * V_16 )
{
struct V_3 * V_3 = F_6 ( V_16 ) ;
F_12 ( V_3 -> V_6 ) ;
F_13 ( & V_3 -> V_43 ) ;
F_7 ( & V_16 -> V_28 , L_3 ) ;
F_14 ( V_16 ) ;
F_15 ( V_16 , NULL ) ;
F_16 ( V_3 ) ;
}
static int F_17 ( struct V_16 * V_16 , const T_2 * V_44 , T_2 V_45 )
{
int V_46 = 0 ;
V_46 = F_18 ( V_16 , V_19 ) ;
if ( V_46 )
return V_46 ;
for (; ! V_46 && V_45 ; V_44 ++ , V_45 -- ) {
if ( * V_44 >= V_21 ) {
V_46 = F_18 ( V_16 , V_21 ) ;
if ( ! V_46 )
V_46 = F_18 ( V_16 , * V_44 - V_23 ) ;
} else {
V_46 = F_18 ( V_16 , * V_44 ) ;
}
}
if ( ! V_46 )
V_46 = F_18 ( V_16 , V_24 ) ;
return V_46 ;
}
static int F_19 ( struct V_3 * V_3 ,
const T_2 * V_47 , T_2 V_45 ,
T_2 V_48 , T_2 V_49 )
{
int V_46 ;
F_20 ( & V_3 -> V_41 ) ;
V_46 = F_17 ( V_3 -> V_16 , V_47 , V_45 ) ;
if ( V_46 )
return V_46 ;
if ( ! F_21 ( & V_3 -> V_41 , V_50 ) )
return - V_51 ;
if ( ( V_3 -> V_4 [ 0 ] & 0x3f ) == V_40 &&
V_47 [ 0 ] != V_52 &&
V_47 [ 0 ] != V_53 &&
V_47 [ 0 ] != V_54 )
return - V_55 ;
if ( V_48 &&
( ( V_3 -> V_4 [ 0 ] & 0x3f ) != V_48 || V_3 -> V_32 < V_49 + 1 ) ) {
F_7 ( V_3 -> V_28 , L_4 ,
V_3 -> V_4 [ 0 ] & 0x3f ) ;
return - V_56 ;
}
return 0 ;
}
static int F_22 ( struct V_3 * V_3 ,
const T_2 * V_47 , T_2 V_45 , T_2 V_48 , T_2 V_49 )
{
T_2 V_57 [ 2 ] ;
int V_46 ;
F_23 ( & V_3 -> V_58 ) ;
V_46 = F_19 ( V_3 , V_47 , V_45 , V_48 , V_49 ) ;
if ( V_46 == - V_55 ) {
V_57 [ 0 ] = V_52 ;
V_57 [ 1 ] = 1 ;
V_46 = F_19 ( V_3 , V_57 , 2 ,
V_39 , 1 ) ;
if ( V_46 )
goto V_59;
V_46 = F_19 ( V_3 , V_47 , V_45 ,
V_48 , V_49 ) ;
}
V_59:
F_24 ( & V_3 -> V_58 ) ;
return V_46 == - V_55 ? - V_56 : V_46 ;
}
static int F_25 ( struct V_3 * V_3 , struct V_16 * V_16 ,
struct V_60 * V_61 , T_3 * V_62 )
{
T_2 * V_4 = V_3 -> V_4 + 1 ;
T_2 V_47 [ 2 ] ;
int V_46 ;
struct V_63 V_63 ;
T_4 V_64 ;
V_3 -> V_65 = 0 ;
V_47 [ 0 ] = V_66 ;
V_46 = F_22 ( V_3 , V_47 , 1 , V_47 [ 0 ] , 2 ) ;
if ( V_46 )
return V_46 ;
V_3 -> V_65 = ( V_4 [ 0 ] << 8 ) | V_4 [ 1 ] ;
F_7 ( V_3 -> V_28 , L_5 , V_3 -> V_65 ) ;
if ( V_3 -> V_65 < 2 ) {
* V_62 = V_67 ;
return 0 ;
}
V_47 [ 0 ] = V_54 ;
V_46 = F_22 ( V_3 , V_47 , 1 , V_47 [ 0 ] , 4 ) ;
if ( V_46 )
return V_46 ;
V_64 = ( V_4 [ 0 ] << 24 ) | ( V_4 [ 1 ] << 16 ) | ( V_4 [ 2 ] << 8 ) | V_4 [ 3 ] ;
F_26 ( V_64 , 0 , & V_63 ) ;
F_7 ( V_3 -> V_28 , L_6 ,
V_63 . V_68 + 1900 , V_63 . V_69 + 1 , V_63 . V_70 ,
V_63 . V_71 , V_63 . V_72 , V_63 . V_73 ) ;
F_10 ( V_3 -> V_28 , L_7 ) ;
V_47 [ 0 ] = V_74 ;
V_46 = F_22 ( V_3 , V_47 , 1 , V_47 [ 0 ] , 1 ) ;
if ( V_46 )
return V_46 ;
V_3 -> V_75 = V_4 [ 0 ] ;
F_10 ( V_3 -> V_28 , L_8 ,
V_4 [ 0 ] ? L_9 : L_10 ) ;
V_47 [ 0 ] = V_76 ;
V_46 = F_22 ( V_3 , V_47 , 1 , V_47 [ 0 ] , 1 ) ;
if ( V_46 )
return V_46 ;
V_61 -> V_77 [ 0 ] = V_4 [ 0 ] ;
F_10 ( V_3 -> V_28 , L_11 , V_4 [ 0 ] ) ;
switch ( V_61 -> V_77 [ 0 ] ) {
case V_78 :
V_61 -> V_79 [ 0 ] = V_80 ;
V_61 -> V_81 [ 0 ] = V_82 ;
break;
case V_83 :
V_61 -> V_79 [ 0 ] = V_84 ;
V_61 -> V_81 [ 0 ] = V_85 ;
break;
case V_86 :
V_61 -> V_79 [ 0 ] = V_87 ;
V_61 -> V_81 [ 0 ] = V_88 ;
break;
case V_89 :
V_61 -> V_79 [ 0 ] = V_90 ;
V_61 -> V_81 [ 0 ] = V_91 ;
break;
case V_92 :
V_61 -> V_79 [ 0 ] = V_90 ;
V_61 -> V_81 [ 0 ] = V_93 ;
break;
case V_94 :
V_61 -> V_79 [ 0 ] = V_95 ;
V_61 -> V_81 [ 0 ] = V_96 ;
break;
case V_97 :
V_61 -> V_79 [ 0 ] = V_98 ;
V_61 -> V_81 [ 0 ] = V_96 ;
break;
default:
V_61 -> V_79 [ 0 ] = V_95 ;
V_61 -> V_81 [ 0 ] = V_96 ;
F_7 ( V_3 -> V_28 , L_12 ,
V_61 -> V_77 [ 0 ] ) ;
break;
}
V_47 [ 0 ] = V_99 ;
V_46 = F_22 ( V_3 , V_47 , 1 , V_47 [ 0 ] , 2 ) ;
if ( V_46 )
return V_46 ;
V_61 -> V_100 = ( V_4 [ 0 ] << 8 ) | V_4 [ 1 ] ;
F_10 ( V_3 -> V_28 , L_13 ,
V_61 -> V_100 ) ;
if ( V_61 -> V_100 )
V_61 -> V_101 = 1 ;
V_47 [ 0 ] = V_102 ;
V_46 = F_22 ( V_3 , V_47 , 1 , V_47 [ 0 ] , 1 ) ;
if ( V_46 )
return V_46 ;
* V_62 = ( V_4 [ 0 ] << 8 ) | V_4 [ 1 ] ;
F_10 ( V_3 -> V_28 , L_14 ,
F_27 ( * V_62 ) ) ;
V_47 [ 0 ] = V_103 ;
V_46 = F_22 ( V_3 , V_47 , 1 , V_47 [ 0 ] , 1 ) ;
if ( V_46 )
return V_46 ;
V_61 -> V_104 = V_4 [ 0 ] ;
F_10 ( V_3 -> V_28 , L_15 , V_61 -> V_104 ) ;
V_47 [ 0 ] = V_105 ;
V_46 = F_22 ( V_3 , V_47 , 1 , V_47 [ 0 ] , 0 ) ;
if ( V_46 )
return V_46 ;
strncpy ( V_61 -> V_106 , V_4 , 13 ) ;
F_10 ( V_3 -> V_28 , L_16 , V_61 -> V_106 ) ;
return 0 ;
}
static int F_28 ( struct V_3 * V_3 ,
struct V_60 * V_61 ,
T_3 V_62 )
{
int V_46 ;
V_46 = F_29 ( V_3 -> V_6 , V_61 , false ) ;
if ( V_46 )
return V_46 ;
F_30 ( V_3 -> V_6 , V_62 , false ) ;
return 0 ;
}
static int F_31 ( struct V_107 * V_6 , bool V_108 )
{
struct V_3 * V_3 = F_32 ( V_6 ) ;
T_2 V_47 [ 16 ] ;
int V_46 ;
V_47 [ 0 ] = V_52 ;
V_47 [ 1 ] = V_108 ;
V_46 = F_22 ( V_3 , V_47 , 2 ,
V_39 , 1 ) ;
return V_108 ? V_46 : 0 ;
}
static int F_33 ( struct V_107 * V_6 , T_2 V_109 )
{
struct V_3 * V_3 = F_32 ( V_6 ) ;
T_3 V_110 = 0 ;
T_3 V_62 = V_6 -> V_111 ;
T_2 V_47 [ 16 ] ;
int V_46 = 0 ;
F_23 ( & V_3 -> V_112 ) ;
if ( V_109 != V_113 )
V_110 = 1 << V_109 ;
V_47 [ 0 ] = V_114 ;
V_47 [ 1 ] = V_110 >> 8 ;
V_47 [ 2 ] = V_110 & 0xff ;
V_46 = F_22 ( V_3 , V_47 , 3 ,
V_39 , 0 ) ;
if ( ( V_46 && V_110 != 0 ) || V_3 -> V_115 )
goto V_59;
V_47 [ 0 ] = V_53 ;
V_47 [ 1 ] = V_109 == V_113 ? 0 : 1 ;
V_46 = F_22 ( V_3 , V_47 , 2 ,
V_39 , 0 ) ;
if ( V_46 )
goto V_59;
V_3 -> V_75 = V_47 [ 1 ] ;
if ( V_109 == V_113 )
goto V_59;
V_47 [ 0 ] = V_116 ;
V_47 [ 1 ] = V_6 -> V_61 . V_77 [ 0 ] ;
V_46 = F_22 ( V_3 , V_47 , 2 ,
V_39 , 0 ) ;
if ( V_46 )
goto V_59;
switch ( V_6 -> V_61 . V_77 [ 0 ] ) {
case V_78 :
V_110 = V_117 ;
break;
case V_83 :
V_110 = V_118 ;
break;
case V_86 :
V_110 = V_119 ;
break;
case V_89 :
V_110 = V_120 ;
break;
case V_92 :
V_110 = V_121 ;
break;
case V_94 :
V_110 = V_122 ;
break;
case V_97 :
V_110 = V_123 ;
break;
default:
V_110 = 0 ;
break;
}
V_47 [ 0 ] = V_124 ;
V_47 [ 1 ] = V_110 >> 8 ;
V_47 [ 2 ] = V_110 & 0xff ;
V_46 = F_22 ( V_3 , V_47 , 3 ,
V_39 , 0 ) ;
if ( V_46 )
goto V_59;
V_47 [ 0 ] = V_125 ;
V_47 [ 1 ] = V_109 ;
V_46 = F_22 ( V_3 , V_47 , 2 ,
V_39 , 0 ) ;
if ( V_46 )
goto V_59;
V_47 [ 0 ] = V_126 ;
V_47 [ 1 ] = V_62 >> 8 ;
V_47 [ 2 ] = V_62 & 0xff ;
V_46 = F_22 ( V_3 , V_47 , 3 ,
V_39 , 0 ) ;
if ( V_46 )
goto V_59;
V_47 [ 0 ] = V_127 ;
V_47 [ 1 ] = V_6 -> V_61 . V_104 ;
V_46 = F_22 ( V_3 , V_47 , 2 ,
V_39 , 0 ) ;
if ( V_46 )
goto V_59;
if ( V_6 -> V_61 . V_106 [ 0 ] ) {
T_5 V_128 = strlen ( V_6 -> V_61 . V_106 ) ;
char * V_129 = V_47 + 1 ;
V_47 [ 0 ] = V_130 ;
strncpy ( V_47 + 1 , V_6 -> V_61 . V_106 , 13 ) ;
if ( V_128 < 4 ) {
memset ( V_129 + V_128 , ' ' , 4 - V_128 ) ;
V_128 = 4 ;
V_129 [ V_128 ] = '\0' ;
strcpy ( V_6 -> V_61 . V_106 , V_129 ) ;
}
V_46 = F_22 ( V_3 , V_47 , 1 + V_128 ,
V_39 , 0 ) ;
if ( V_46 )
goto V_59;
}
V_59:
if ( V_3 -> V_115 )
V_3 -> V_115 = false ;
else
V_3 -> V_131 = true ;
F_24 ( & V_3 -> V_112 ) ;
return V_46 ;
}
static int F_34 ( struct V_107 * V_6 , T_2 V_132 ,
T_6 V_133 , struct V_25 * V_26 )
{
struct V_3 * V_3 = F_32 ( V_6 ) ;
T_2 V_47 [ 2 ] ;
unsigned int V_134 ;
int V_46 ;
V_47 [ 0 ] = V_135 ;
V_47 [ 1 ] = V_133 ;
V_46 = F_22 ( V_3 , V_47 , 2 ,
V_39 , 1 ) ;
V_47 [ 0 ] = V_136 ;
V_47 [ 1 ] = F_35 ( V_26 ) ;
if ( ! V_46 )
V_46 = F_22 ( V_3 , V_47 , 2 ,
V_39 , 1 ) ;
V_47 [ 0 ] = V_26 -> V_32 == 1 ? V_137 : V_138 ;
V_47 [ 1 ] = V_26 -> V_26 [ 0 ] ;
if ( ! V_46 )
V_46 = F_22 ( V_3 , V_47 , 2 ,
V_39 , 1 ) ;
if ( ! V_46 && V_26 -> V_32 > 1 ) {
V_47 [ 0 ] = V_26 -> V_32 == 2 ? V_137 :
V_138 ;
V_47 [ 1 ] = V_26 -> V_26 [ 1 ] ;
V_46 = F_22 ( V_3 , V_47 , 2 ,
V_39 , 1 ) ;
for ( V_134 = 0 ; ! V_46 && V_134 + 2 < V_26 -> V_32 ; V_134 ++ ) {
V_47 [ 0 ] = ( V_134 + 2 == V_26 -> V_32 - 1 ) ?
V_137 : V_138 ;
V_47 [ 1 ] = V_26 -> V_26 [ V_134 + 2 ] ;
V_46 = F_22 ( V_3 , V_47 , 2 ,
V_39 , 1 ) ;
}
}
return V_46 ;
}
static int F_36 ( struct V_107 * V_6 , struct V_25 * V_26 )
{
return - V_139 ;
}
static int F_37 ( struct V_16 * V_16 , struct V_140 * V_141 )
{
T_6 V_142 = V_143 | V_144 | V_145 |
V_146 | V_147 | V_148 ;
struct V_3 * V_3 ;
int V_46 = - V_149 ;
struct V_60 V_61 = {} ;
T_3 V_62 = V_67 ;
V_3 = F_38 ( sizeof( * V_3 ) , V_150 ) ;
if ( ! V_3 )
return - V_149 ;
V_3 -> V_16 = V_16 ;
V_3 -> V_6 = F_39 ( & V_151 , V_3 ,
L_17 , V_142 , 1 ) ;
V_46 = F_40 ( V_3 -> V_6 ) ;
if ( V_46 < 0 )
goto V_152;
V_3 -> V_28 = & V_16 -> V_28 ;
F_15 ( V_16 , V_3 ) ;
F_41 ( & V_3 -> V_2 , F_1 ) ;
F_42 ( & V_3 -> V_58 ) ;
F_42 ( & V_3 -> V_112 ) ;
V_3 -> V_131 = false ;
V_46 = F_43 ( V_16 , V_141 ) ;
if ( V_46 )
goto V_153;
V_46 = F_25 ( V_3 , V_16 , & V_61 , & V_62 ) ;
if ( V_46 )
goto V_154;
V_46 = F_44 ( V_3 -> V_6 , & V_16 -> V_28 ) ;
if ( V_46 < 0 )
goto V_154;
V_3 -> V_28 = & V_3 -> V_6 -> V_155 . V_28 ;
if ( V_156 && V_3 -> V_75 ) {
V_46 = F_28 ( V_3 , & V_61 , V_62 ) ;
if ( V_46 )
goto V_154;
V_3 -> V_115 = true ;
}
F_45 ( & V_3 -> V_43 ,
V_157 ) ;
F_46 ( & V_3 -> V_43 , V_158 ) ;
return 0 ;
V_154:
F_14 ( V_16 ) ;
V_153:
F_47 ( V_3 -> V_6 ) ;
F_15 ( V_16 , NULL ) ;
V_152:
F_16 ( V_3 ) ;
return V_46 ;
}
static void V_157 ( struct V_1 * V_2 )
{
struct V_3 * V_3 =
F_2 ( V_2 , struct V_3 , V_43 . V_2 ) ;
T_2 V_47 ;
F_46 ( & V_3 -> V_43 , V_158 ) ;
V_47 = V_159 ;
F_22 ( V_3 , & V_47 , 1 ,
V_39 , 0 ) ;
if ( V_3 -> V_65 < 2 )
return;
F_23 ( & V_3 -> V_112 ) ;
if ( V_3 -> V_131 && V_156 ) {
F_10 ( V_3 -> V_28 , L_18 ) ;
V_47 = V_160 ;
if ( F_22 ( V_3 , & V_47 , 1 ,
V_39 , 0 ) )
F_7 ( V_3 -> V_28 , L_19 ) ;
else
V_3 -> V_131 = false ;
}
F_24 ( & V_3 -> V_112 ) ;
}
