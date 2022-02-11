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
V_63 =
F_23 ( V_77 ) ;
V_5 = F_14 ( V_2 , V_68 ,
V_78 ,
( T_1 * ) & V_63 , 4 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( ( V_79 & V_61 ) == 0 ) {
V_5 = F_21 ( V_2 ,
V_79 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( ( V_80 & V_61 ) == 0 ) {
V_5 = F_21 ( V_2 ,
V_80 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_5 = F_16 ( V_2 , V_52 ,
V_81 , NULL , 0 ) ;
if ( V_5 < 0 )
F_16 ( V_2 , V_52 ,
V_53 , NULL , 0 ) ;
}
if ( V_62 & V_72 ) {
V_5 = F_15 ( V_2 , V_82 ,
V_83 ,
& V_64 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_64 -> V_25 > 0 &&
V_64 -> V_26 [ 0 ] !=
V_84 ) {
V_47 [ 0 ] = V_84 ;
V_5 = F_14 ( V_2 , V_82 ,
V_83 ,
V_47 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_47 [ 0 ] = 0x00 ;
V_47 [ 1 ] = 0x08 ;
V_5 = F_14 ( V_2 , V_82 ,
V_85 , V_47 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_47 [ 0 ] = 0x40 ;
V_5 = F_14 ( V_2 , V_82 ,
V_86 , V_47 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_14 ( V_2 , V_82 ,
V_87 , NULL , 0 ) ;
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
V_5 = F_14 ( V_2 , V_82 ,
V_88 , V_47 ,
19 ) ;
if ( V_5 < 0 )
return V_5 ;
V_47 [ 0 ] = 0x02 ;
V_5 = F_14 ( V_2 , V_82 ,
V_89 , V_47 , 1 ) ;
}
return V_5 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_22 ,
V_90 , NULL , 0 , NULL ) ;
}
static int F_25 ( struct V_1 * V_2 , T_3 * V_91 )
{
int V_5 ;
struct V_6 * V_92 = NULL ;
V_5 = F_15 ( V_2 , V_79 ,
V_93 , & V_92 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_92 -> V_25 != 2 ) {
V_5 = - V_94 ;
goto exit;
}
* V_91 = F_26 ( * ( V_95 * ) V_92 -> V_26 ) ;
exit:
F_7 ( V_92 ) ;
return V_5 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 * V_96 )
{
int V_5 ;
struct V_6 * V_97 = NULL ;
V_5 = F_15 ( V_2 , V_79 ,
V_98 , & V_97 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_97 -> V_25 != 1 ) {
V_5 = - V_94 ;
goto exit;
}
* V_96 = V_97 -> V_26 [ 0 ] ;
exit:
F_7 ( V_97 ) ;
return V_5 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 * V_28 ,
int * V_25 )
{
int V_5 ;
struct V_6 * V_99 = NULL ;
V_5 = F_15 ( V_2 , V_79 ,
V_100 , & V_99 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_99 -> V_25 == 0 || V_99 -> V_25 > V_101 ) {
V_5 = - V_94 ;
goto exit;
}
V_28 = V_99 -> V_26 ;
* V_25 = V_99 -> V_25 ;
exit:
F_7 ( V_99 ) ;
return V_5 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
int V_5 ;
struct V_6 * V_104 = NULL ;
V_5 = F_15 ( V_2 , V_80 ,
V_105 ,
& V_104 ) ;
if ( V_5 < 0 )
goto exit;
F_30 ( V_104 , 2 ) ;
if ( V_104 -> V_25 == 0 ||
V_104 -> V_25 > V_106 ) {
V_5 = - V_94 ;
goto exit;
}
memcpy ( V_103 -> V_107 , V_104 -> V_26 , V_104 -> V_25 ) ;
V_103 -> V_108 = V_104 -> V_26 [ 1 ] ;
V_103 -> V_109 = 1 ;
exit:
F_7 ( V_104 ) ;
return V_5 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_102 * V_103 , T_1 V_110 ,
T_1 * V_69 , T_4 V_71 )
{
struct V_35 * V_10 = F_9 ( V_2 ) ;
V_10 -> V_111 . V_112 = V_103 -> V_112 ;
return F_32 ( V_2 , V_69 , V_71 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_35 * V_10 = F_9 ( V_2 ) ;
V_10 -> V_37 = V_44 ;
return F_4 ( V_2 , V_22 ,
V_90 , NULL , 0 , NULL ) ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_28 ,
struct V_102 * V_103 )
{
int V_5 , V_25 ;
T_3 V_91 ;
T_1 V_96 ;
T_1 V_113 [ V_101 ] ;
switch ( V_28 ) {
case V_68 :
V_103 -> V_114 = V_115 ;
break;
case V_79 :
V_5 = F_25 ( V_2 , & V_91 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_91 == 0x000c ) {
V_103 -> V_114 = V_116 ;
V_103 -> V_117 = 0x0c00 ;
} else {
V_5 = F_27 ( V_2 , & V_96 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_28 ( V_2 , V_113 , & V_25 ) ;
if ( V_5 < 0 )
return V_5 ;
V_103 -> V_114 =
F_35 ( V_96 ) ;
if ( V_103 -> V_114 == 0xffffffff )
return - V_94 ;
V_103 -> V_117 = V_91 ;
V_103 -> V_118 = V_96 ;
memcpy ( V_103 -> V_119 , V_113 , V_25 ) ;
V_103 -> V_120 = V_25 ;
}
break;
case V_80 :
V_103 -> V_114 = V_121 ;
V_5 = F_29 ( V_2 , V_103 ) ;
if ( V_5 < 0 )
return V_5 ;
break;
default:
return - V_94 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
T_1 V_28 ,
struct V_102 * V_103 )
{
int V_5 ;
struct V_6 * V_122 = NULL , * V_123 ;
if ( V_28 == V_68 ) {
V_5 = F_15 ( V_2 , V_68 ,
V_124 , & V_122 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_122 -> V_25 > V_125 ) {
V_5 = - V_94 ;
goto exit;
}
if ( V_122 -> V_25 > 0 ) {
memcpy ( V_103 -> V_126 , V_122 -> V_26 ,
V_122 -> V_25 ) ;
V_103 -> V_127 = V_122 -> V_25 ;
if ( V_103 -> V_126 [ 0 ] == 0x01 &&
V_103 -> V_126 [ 1 ] == 0xfe )
V_103 -> V_114 =
V_72 ;
else
V_103 -> V_114 =
V_115 ;
} else {
V_5 = F_15 ( V_2 , V_68 ,
V_128 ,
& V_123 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_123 -> V_25 > V_101 ) {
V_5 = - V_94 ;
goto exit;
}
memcpy ( V_103 -> V_126 , V_123 -> V_26 ,
V_123 -> V_25 ) ;
V_103 -> V_127 = V_123 -> V_25 ;
V_103 -> V_114 = V_72 ;
}
V_103 -> V_129 = V_68 ;
}
V_5 = 1 ;
exit:
F_7 ( V_122 ) ;
return V_5 ;
}
static void F_37 ( void * V_130 , struct V_6 * V_46 ,
int V_131 )
{
struct V_35 * V_10 = V_130 ;
switch ( V_10 -> V_132 ) {
case V_133 :
if ( V_131 == 0 )
F_38 ( V_46 , V_46 -> V_25 - 1 ) ;
V_10 -> V_134 ( V_10 -> V_135 , V_46 , V_131 ) ;
break;
default:
if ( V_131 == 0 )
F_7 ( V_46 ) ;
break;
}
}
static int F_39 ( struct V_1 * V_2 ,
struct V_102 * V_103 ,
struct V_6 * V_46 ,
T_5 V_136 , void * V_137 )
{
struct V_35 * V_10 = F_9 ( V_2 ) ;
F_20 ( V_65 L_3 , V_66 ,
V_103 -> V_129 , V_46 -> V_25 ) ;
switch ( V_103 -> V_129 ) {
case V_68 :
if ( V_103 -> V_114 == V_72 )
return F_40 ( V_2 , V_46 ) ;
* F_41 ( V_46 , 1 ) = 0x1a ;
return F_42 ( V_2 , V_103 -> V_129 ,
V_138 , V_46 -> V_26 ,
V_46 -> V_25 , V_136 , V_137 ) ;
case V_79 :
* F_41 ( V_46 , 1 ) = 0x1a ;
return F_42 ( V_2 , V_103 -> V_129 ,
V_138 , V_46 -> V_26 ,
V_46 -> V_25 , V_136 , V_137 ) ;
case V_80 :
V_10 -> V_132 = V_133 ;
V_10 -> V_134 = V_136 ;
V_10 -> V_135 = V_137 ;
* F_41 ( V_46 , 1 ) = 0x17 ;
return F_42 ( V_2 , V_103 -> V_129 ,
V_138 , V_46 -> V_26 ,
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
struct V_102 * V_103 )
{
T_1 V_139 = 0x11 ;
switch ( V_103 -> V_129 ) {
case V_52 :
case V_67 :
return F_4 ( V_2 , V_103 -> V_129 ,
V_138 , & V_139 , 1 , NULL ) ;
case V_79 :
return F_4 ( V_2 , V_103 -> V_129 ,
V_140 ,
NULL , 0 , NULL ) ;
default:
return - V_141 ;
}
}
static int F_46 ( struct V_1 * V_2 , T_1 V_28 ,
T_1 V_142 , struct V_6 * V_46 )
{
int V_5 ;
struct V_35 * V_10 = F_9 ( V_2 ) ;
F_47 ( L_4 , V_142 ) ;
switch ( V_142 ) {
case V_143 :
if ( V_28 == V_82 )
V_10 -> V_111 . V_144 = 0 ;
break;
case V_145 :
break;
case V_146 :
break;
case V_147 :
break;
case V_148 :
if ( V_28 == V_82 ) {
V_5 = F_48 ( V_2 , V_46 , V_28 ) ;
if ( V_5 < 0 )
goto exit;
return 0 ;
} else {
V_10 -> V_111 . V_144 = 0 ;
return 1 ;
}
break;
default:
return 1 ;
}
F_7 ( V_46 ) ;
return 0 ;
exit:
return V_5 ;
}
int F_49 ( void * V_43 , struct V_149 * V_41 ,
char * V_150 , int V_151 , int V_152 ,
int V_153 , struct V_1 * * V_2 )
{
struct V_35 * V_10 ;
int V_5 = 0 ;
int V_154 ;
T_2 V_155 ;
struct V_156 V_33 ;
unsigned long V_157 = 0 ;
V_10 = F_50 ( sizeof( struct V_35 ) , V_17 ) ;
if ( ! V_10 ) {
V_5 = - V_18 ;
goto V_158;
}
V_10 -> V_41 = V_41 ;
V_10 -> V_43 = V_43 ;
V_10 -> V_37 = V_38 ;
F_51 ( & V_10 -> V_36 ) ;
V_33 . V_159 = F_5 ( V_27 ) ;
memcpy ( V_33 . V_34 , V_27 , sizeof( V_27 ) ) ;
V_154 = F_52 ( V_160 , V_161 ) ;
if ( V_154 >= V_161 )
goto V_158;
F_53 ( V_33 . V_162 , sizeof( V_33 . V_162 ) , L_5 ,
L_6 , V_154 ) ;
V_155 = V_116 |
V_163 |
V_115 |
V_164 |
V_165 |
V_121 |
V_72 ;
F_54 ( V_166 , & V_157 ) ;
V_10 -> V_2 =
F_55 ( & V_167 , & V_33 , V_157 ,
V_155 , V_150 ,
V_151 + V_168 ,
V_152 , V_153 ) ;
if ( ! V_10 -> V_2 ) {
F_56 ( L_7 ) ;
V_5 = - V_18 ;
goto V_158;
}
F_57 ( V_10 -> V_2 , V_10 ) ;
V_5 = F_58 ( V_10 -> V_2 ) ;
if ( V_5 )
goto V_169;
* V_2 = V_10 -> V_2 ;
F_59 ( V_10 -> V_2 ) ;
return 0 ;
V_169:
F_60 ( V_10 -> V_2 ) ;
V_158:
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
