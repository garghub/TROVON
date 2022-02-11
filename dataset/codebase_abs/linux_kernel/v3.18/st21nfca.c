static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 , V_5 ;
struct V_6 * V_7 , * V_8 ;
struct V_9 * V_10 ;
T_1 V_11 [] = { V_12 ,
V_13
} ;
T_1 V_14 [] = { V_15 ,
V_13 , 0
} ;
V_7 = F_2 ( V_16 , V_17 ) ;
if ( ! V_7 ) {
V_5 = - V_18 ;
goto V_19;
}
V_8 = F_2 ( V_16 , V_17 ) ;
if ( ! V_8 ) {
V_5 = - V_18 ;
goto V_20;
}
V_5 = F_3 ( V_2 , V_21 ,
V_22 , V_23 ) ;
if ( V_5 < 0 )
goto V_20;
V_5 = F_4 ( V_2 , V_22 ,
V_24 , V_11 , sizeof( V_11 ) ,
& V_7 ) ;
if ( V_5 < 0 )
goto V_20;
for ( V_3 = 0 ; V_3 < V_7 -> V_25 ; V_3 ++ ) {
V_14 [ 2 ] = V_7 -> V_26 [ V_3 ] ;
V_5 = F_4 ( V_2 , V_22 ,
V_24 , V_14 ,
sizeof( V_14 ) , & V_8 ) ;
if ( V_5 )
continue;
V_10 = (struct V_9 * ) V_8 -> V_26 ;
for ( V_4 = 0 ; ( V_4 < F_5 ( V_27 ) ) &&
( V_27 [ V_4 ] . V_28 != V_10 -> V_29 ) ;
V_4 ++ )
;
if ( V_4 < F_5 ( V_27 ) &&
V_27 [ V_4 ] . V_28 == V_10 -> V_29 &&
F_6 ( V_10 -> V_30 ) ) {
V_27 [ V_4 ] . V_31 = V_14 [ 2 ] ;
V_2 -> V_32 [ V_27 [ V_4 ] . V_28 ] =
V_27 [ V_4 ] . V_31 ;
}
}
if ( V_7 -> V_25 + 3 < F_5 ( V_27 ) ) {
for ( V_3 = V_7 -> V_25 + 3 ;
V_3 < F_5 ( V_27 ) ; V_3 ++ ) {
V_5 = F_3 ( V_2 ,
V_21 ,
V_27 [ V_3 ] . V_28 ,
V_27 [ V_3 ] . V_31 ) ;
if ( V_5 < 0 )
goto V_20;
}
}
memcpy ( V_2 -> V_33 . V_34 , V_27 , sizeof( V_27 ) ) ;
V_20:
F_7 ( V_8 ) ;
V_19:
F_7 ( V_7 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_35 * V_10 = F_9 ( V_2 ) ;
int V_5 ;
F_10 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_37 != V_38 ) {
V_5 = - V_39 ;
goto V_40;
}
V_5 = V_10 -> V_41 -> V_42 ( V_10 -> V_43 ) ;
if ( V_5 == 0 )
V_10 -> V_37 = V_44 ;
V_40:
F_11 ( & V_10 -> V_36 ) ;
return V_5 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_35 * V_10 = F_9 ( V_2 ) ;
F_10 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_37 == V_38 )
goto V_40;
V_10 -> V_41 -> V_45 ( V_10 -> V_43 ) ;
V_10 -> V_37 = V_38 ;
V_40:
F_11 ( & V_10 -> V_36 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_6 * V_46 ;
T_1 V_47 ;
int V_5 ;
V_47 = V_48 ;
V_5 = F_14 ( V_2 , V_49 ,
V_50 , & V_47 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_15 ( V_2 , V_22 ,
V_51 , & V_46 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_46 -> V_26 [ 0 ] == 0 ) {
F_7 ( V_46 ) ;
V_47 = 1 ;
V_5 = F_14 ( V_2 , V_22 ,
V_51 , & V_47 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_5 = F_16 ( V_2 , V_52 ,
V_53 , NULL , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_15 ( V_2 , V_54 ,
V_55 , & V_46 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_46 -> V_25 != V_56 ) {
F_7 ( V_46 ) ;
return - V_57 ;
}
F_17 ( V_58 , L_1 ,
V_59 , 16 , 1 ,
V_46 -> V_26 , V_56 , false ) ;
F_7 ( V_46 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_6 * V_46 )
{
struct V_35 * V_10 = F_9 ( V_2 ) ;
return V_10 -> V_41 -> V_60 ( V_10 -> V_43 , V_46 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
T_2 V_61 , T_2 V_62 )
{
int V_5 ;
T_2 V_63 ;
T_1 V_47 [ 19 ] ;
struct V_6 * V_64 ;
F_20 ( V_65 L_2 ,
V_66 , V_61 , V_62 ) ;
V_5 = F_16 ( V_2 , V_52 ,
V_53 , NULL , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_61 ) {
if ( ( V_67 & V_61 ) == 0 ) {
V_5 = F_21 ( V_2 ,
V_67 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( ( V_52 & V_61 ) == 0 ) {
V_5 = F_21 ( V_2 ,
V_52 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( ( V_68 & V_61 ) == 0 ) {
V_5 = F_21 ( V_2 ,
V_68 ) ;
if ( V_5 < 0 )
return V_5 ;
} else {
V_2 -> V_69 = F_22 ( V_2 -> V_70 ,
& V_2 -> V_71 ) ;
if ( V_2 -> V_69 == NULL || V_2 -> V_71 == 0 ) {
V_61 &= ~ V_72 ;
V_62 &= ~ V_72 ;
}
V_47 [ 0 ] = V_73 |
V_74 |
V_75 ;
V_5 = F_14 ( V_2 , V_68 ,
V_76 ,
V_47 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_63 = F_23 ( ( V_77 V_78 )
V_79 ) ;
V_5 = F_14 ( V_2 , V_68 ,
V_80 ,
( T_1 * ) & V_63 , 4 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( ( V_81 & V_61 ) == 0 ) {
V_5 = F_21 ( V_2 ,
V_81 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( ( V_82 & V_61 ) == 0 ) {
V_5 = F_21 ( V_2 ,
V_82 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_5 = F_16 ( V_2 , V_52 ,
V_83 , NULL , 0 ) ;
if ( V_5 < 0 )
F_16 ( V_2 , V_52 ,
V_53 , NULL , 0 ) ;
}
if ( V_62 & V_72 ) {
V_5 = F_15 ( V_2 , V_84 ,
V_85 ,
& V_64 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_64 -> V_25 > 0 &&
V_64 -> V_26 [ 0 ] !=
V_86 ) {
V_47 [ 0 ] = V_86 ;
V_5 = F_14 ( V_2 , V_84 ,
V_85 ,
V_47 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_47 [ 0 ] = 0x00 ;
V_47 [ 1 ] = 0x08 ;
V_5 = F_14 ( V_2 , V_84 ,
V_87 , V_47 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_47 [ 0 ] = 0x40 ;
V_5 = F_14 ( V_2 , V_84 ,
V_88 , V_47 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_14 ( V_2 , V_84 ,
V_89 , NULL , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_47 [ 0 ] = 0x00 ;
V_47 [ 1 ] = 0x00 ;
V_47 [ 2 ] = 0x01 ;
V_47 [ 3 ] = 0xfe ;
V_47 [ 4 ] = 'S' ;
V_47 [ 5 ] = 'T' ;
V_47 [ 6 ] = 'M' ;
V_47 [ 7 ] = 'i' ;
V_47 [ 8 ] = 'c' ;
V_47 [ 9 ] = 'r' ;
V_47 [ 18 ] = 0x01 ;
V_5 = F_14 ( V_2 , V_84 ,
V_90 , V_47 ,
19 ) ;
if ( V_5 < 0 )
return V_5 ;
V_47 [ 0 ] = 0x02 ;
V_5 = F_14 ( V_2 , V_84 ,
V_91 , V_47 , 1 ) ;
}
return V_5 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_22 ,
V_92 , NULL , 0 , NULL ) ;
}
static int F_25 ( struct V_1 * V_2 , T_3 * V_93 )
{
int V_5 ;
struct V_6 * V_94 = NULL ;
V_5 = F_15 ( V_2 , V_81 ,
V_95 , & V_94 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_94 -> V_25 != 2 ) {
V_5 = - V_96 ;
goto exit;
}
* V_93 = F_26 ( * ( V_97 * ) V_94 -> V_26 ) ;
exit:
F_7 ( V_94 ) ;
return V_5 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 * V_98 )
{
int V_5 ;
struct V_6 * V_99 = NULL ;
V_5 = F_15 ( V_2 , V_81 ,
V_100 , & V_99 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_99 -> V_25 != 1 ) {
V_5 = - V_96 ;
goto exit;
}
* V_98 = V_99 -> V_26 [ 0 ] ;
exit:
F_7 ( V_99 ) ;
return V_5 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 * V_28 ,
int * V_25 )
{
int V_5 ;
struct V_6 * V_101 = NULL ;
V_5 = F_15 ( V_2 , V_81 ,
V_102 , & V_101 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_101 -> V_25 == 0 || V_101 -> V_25 > V_103 ) {
V_5 = - V_96 ;
goto exit;
}
V_28 = V_101 -> V_26 ;
* V_25 = V_101 -> V_25 ;
exit:
F_7 ( V_101 ) ;
return V_5 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_104 * V_105 )
{
int V_5 ;
struct V_6 * V_106 = NULL ;
V_5 = F_15 ( V_2 , V_82 ,
V_107 ,
& V_106 ) ;
if ( V_5 < 0 )
goto exit;
F_30 ( V_106 , 2 ) ;
if ( V_106 -> V_25 == 0 ||
V_106 -> V_25 > V_108 ) {
V_5 = - V_96 ;
goto exit;
}
memcpy ( V_105 -> V_109 , V_106 -> V_26 , V_106 -> V_25 ) ;
V_105 -> V_110 = V_106 -> V_26 [ 1 ] ;
V_105 -> V_111 = 1 ;
exit:
F_7 ( V_106 ) ;
return V_5 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_104 * V_105 , T_1 V_112 ,
T_1 * V_69 , T_4 V_71 )
{
struct V_35 * V_10 = F_9 ( V_2 ) ;
V_10 -> V_113 . V_114 = V_105 -> V_114 ;
return F_32 ( V_2 , V_69 , V_71 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_35 * V_10 = F_9 ( V_2 ) ;
V_10 -> V_37 = V_44 ;
return F_4 ( V_2 , V_22 ,
V_92 , NULL , 0 , NULL ) ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_28 ,
struct V_104 * V_105 )
{
int V_5 , V_25 ;
T_3 V_93 ;
T_1 V_98 ;
T_1 V_115 [ V_103 ] ;
switch ( V_28 ) {
case V_68 :
V_105 -> V_116 = V_117 ;
break;
case V_81 :
V_5 = F_25 ( V_2 , & V_93 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_93 == 0x000c ) {
V_105 -> V_116 = V_118 ;
V_105 -> V_119 = 0x0c00 ;
} else {
V_5 = F_27 ( V_2 , & V_98 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_28 ( V_2 , V_115 , & V_25 ) ;
if ( V_5 < 0 )
return V_5 ;
V_105 -> V_116 =
F_35 ( V_98 ) ;
if ( V_105 -> V_116 == 0xffffffff )
return - V_96 ;
V_105 -> V_119 = V_93 ;
V_105 -> V_120 = V_98 ;
memcpy ( V_105 -> V_121 , V_115 , V_25 ) ;
V_105 -> V_122 = V_25 ;
}
break;
case V_82 :
V_105 -> V_116 = V_123 ;
V_5 = F_29 ( V_2 , V_105 ) ;
if ( V_5 < 0 )
return V_5 ;
break;
default:
return - V_96 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
T_1 V_28 ,
struct V_104 * V_105 )
{
int V_5 ;
struct V_6 * V_124 = NULL , * V_125 ;
if ( V_28 == V_68 ) {
V_5 = F_15 ( V_2 , V_68 ,
V_126 , & V_124 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_124 -> V_25 > V_127 ) {
V_5 = - V_96 ;
goto exit;
}
if ( V_124 -> V_25 > 0 ) {
memcpy ( V_105 -> V_128 , V_124 -> V_26 ,
V_124 -> V_25 ) ;
V_105 -> V_129 = V_124 -> V_25 ;
if ( V_105 -> V_128 [ 0 ] == 0x01 &&
V_105 -> V_128 [ 1 ] == 0xfe )
V_105 -> V_116 =
V_72 ;
else
V_105 -> V_116 =
V_117 ;
} else {
V_5 = F_15 ( V_2 , V_68 ,
V_130 ,
& V_125 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_125 -> V_25 > V_103 ) {
V_5 = - V_96 ;
goto exit;
}
memcpy ( V_105 -> V_128 , V_125 -> V_26 ,
V_125 -> V_25 ) ;
V_105 -> V_129 = V_125 -> V_25 ;
V_105 -> V_116 = V_72 ;
}
V_105 -> V_131 = V_68 ;
}
V_5 = 1 ;
exit:
F_7 ( V_124 ) ;
return V_5 ;
}
static void F_37 ( void * V_132 , struct V_6 * V_46 ,
int V_133 )
{
struct V_35 * V_10 = V_132 ;
switch ( V_10 -> V_134 ) {
case V_135 :
if ( V_133 == 0 )
F_38 ( V_46 , V_46 -> V_25 - 1 ) ;
V_10 -> V_136 ( V_10 -> V_137 , V_46 , V_133 ) ;
break;
default:
if ( V_133 == 0 )
F_7 ( V_46 ) ;
break;
}
}
static int F_39 ( struct V_1 * V_2 ,
struct V_104 * V_105 ,
struct V_6 * V_46 ,
T_5 V_138 , void * V_139 )
{
struct V_35 * V_10 = F_9 ( V_2 ) ;
F_20 ( V_65 L_3 , V_66 ,
V_105 -> V_131 , V_46 -> V_25 ) ;
switch ( V_105 -> V_131 ) {
case V_68 :
if ( V_105 -> V_116 == V_72 )
return F_40 ( V_2 , V_46 ) ;
* F_41 ( V_46 , 1 ) = 0x1a ;
return F_42 ( V_2 , V_105 -> V_131 ,
V_140 , V_46 -> V_26 ,
V_46 -> V_25 , V_138 , V_139 ) ;
case V_81 :
* F_41 ( V_46 , 1 ) = 0x1a ;
return F_42 ( V_2 , V_105 -> V_131 ,
V_140 , V_46 -> V_26 ,
V_46 -> V_25 , V_138 , V_139 ) ;
case V_82 :
V_10 -> V_134 = V_135 ;
V_10 -> V_136 = V_138 ;
V_10 -> V_137 = V_139 ;
* F_41 ( V_46 , 1 ) = 0x17 ;
return F_42 ( V_2 , V_105 -> V_131 ,
V_140 , V_46 -> V_26 ,
V_46 -> V_25 ,
F_37 ,
V_10 ) ;
break;
default:
return 1 ;
}
}
static int F_43 ( struct V_1 * V_2 , struct V_6 * V_46 )
{
return F_44 ( V_2 , V_46 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_104 * V_105 )
{
T_1 V_141 = 0x11 ;
switch ( V_105 -> V_131 ) {
case V_52 :
case V_67 :
return F_4 ( V_2 , V_105 -> V_131 ,
V_140 , & V_141 , 1 , NULL ) ;
case V_81 :
return F_4 ( V_2 , V_105 -> V_131 ,
V_142 ,
NULL , 0 , NULL ) ;
default:
return - V_143 ;
}
}
static int F_46 ( struct V_1 * V_2 , T_1 V_28 ,
T_1 V_144 , struct V_6 * V_46 )
{
int V_5 ;
struct V_35 * V_10 = F_9 ( V_2 ) ;
F_47 ( L_4 , V_144 ) ;
switch ( V_144 ) {
case V_145 :
if ( V_28 == V_84 )
V_10 -> V_113 . V_146 = 0 ;
break;
case V_147 :
break;
case V_148 :
break;
case V_149 :
break;
case V_150 :
if ( V_28 == V_84 ) {
V_5 = F_48 ( V_2 , V_46 , V_28 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
V_10 -> V_113 . V_146 = 0 ;
return 1 ;
default:
return 1 ;
}
F_7 ( V_46 ) ;
return 0 ;
}
int F_49 ( void * V_43 , struct V_151 * V_41 ,
char * V_152 , int V_153 , int V_154 ,
int V_155 , struct V_1 * * V_2 )
{
struct V_35 * V_10 ;
int V_5 = 0 ;
int V_156 ;
T_2 V_157 ;
struct V_158 V_33 ;
unsigned long V_159 = 0 ;
V_10 = F_50 ( sizeof( struct V_35 ) , V_17 ) ;
if ( ! V_10 ) {
V_5 = - V_18 ;
goto V_160;
}
V_10 -> V_41 = V_41 ;
V_10 -> V_43 = V_43 ;
V_10 -> V_37 = V_38 ;
F_51 ( & V_10 -> V_36 ) ;
V_33 . V_161 = F_5 ( V_27 ) ;
memcpy ( V_33 . V_34 , V_27 , sizeof( V_27 ) ) ;
V_156 = F_52 ( V_162 , V_163 ) ;
if ( V_156 >= V_163 )
return - V_164 ;
F_53 ( V_156 , V_162 ) ;
F_54 ( V_33 . V_165 , sizeof( V_33 . V_165 ) , L_5 ,
L_6 , V_156 ) ;
V_157 = V_118 |
V_166 |
V_117 |
V_167 |
V_168 |
V_123 |
V_72 ;
F_53 ( V_169 , & V_159 ) ;
V_10 -> V_2 =
F_55 ( & V_170 , & V_33 , V_159 ,
V_157 , V_152 ,
V_153 + V_171 ,
V_154 , V_155 ) ;
if ( ! V_10 -> V_2 ) {
F_56 ( L_7 ) ;
V_5 = - V_18 ;
goto V_160;
}
F_57 ( V_10 -> V_2 , V_10 ) ;
V_5 = F_58 ( V_10 -> V_2 ) ;
if ( V_5 )
goto V_172;
* V_2 = V_10 -> V_2 ;
F_59 ( V_10 -> V_2 ) ;
return 0 ;
V_172:
F_60 ( V_10 -> V_2 ) ;
V_160:
F_61 ( V_10 ) ;
return V_5 ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_35 * V_10 = F_9 ( V_2 ) ;
F_63 ( V_2 ) ;
F_64 ( V_2 ) ;
F_60 ( V_2 ) ;
F_61 ( V_10 ) ;
}
