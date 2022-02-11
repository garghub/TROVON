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
V_5 = F_2 ( V_2 , V_16 ,
V_17 ,
V_18 ) ;
if ( V_5 < 0 )
goto V_19;
V_5 = F_3 ( V_2 , V_17 ,
V_20 , V_11 , sizeof( V_11 ) ,
& V_7 ) ;
if ( V_5 < 0 )
goto V_19;
for ( V_3 = 0 ; V_3 < V_7 -> V_21 ; V_3 ++ ) {
V_14 [ 2 ] = V_7 -> V_22 [ V_3 ] ;
V_5 = F_3 ( V_2 , V_17 ,
V_20 , V_14 ,
sizeof( V_14 ) , & V_8 ) ;
if ( V_5 )
continue;
V_10 = (struct V_9 * ) V_8 -> V_22 ;
if ( V_10 -> V_23 == V_24 &&
V_10 -> V_25 != V_26 ) {
F_4 ( L_1 ,
V_10 -> V_25 ) ;
continue;
}
for ( V_4 = 0 ; ( V_4 < F_5 ( V_27 ) ) &&
( V_27 [ V_4 ] . V_28 != V_10 -> V_23 ) ; V_4 ++ )
;
if ( V_4 < F_5 ( V_27 ) &&
V_27 [ V_4 ] . V_28 == V_10 -> V_23 &&
F_6 ( V_10 -> V_29 ) ) {
V_27 [ V_4 ] . V_30 = V_14 [ 2 ] ;
V_2 -> V_31 [ V_27 [ V_4 ] . V_28 ] =
V_27 [ V_4 ] . V_30 ;
V_2 -> V_32 [ V_27 [ V_4 ] . V_30 ] . V_28 =
V_27 [ V_4 ] . V_28 ;
V_2 -> V_32 [ V_27 [ V_4 ] . V_30 ] . V_33 =
V_10 -> V_25 ;
}
}
if ( V_7 -> V_21 + 3 < F_5 ( V_27 ) ) {
for ( V_3 = V_7 -> V_21 + 3 ;
V_3 < F_5 ( V_27 ) - 2 ; V_3 ++ ) {
V_5 = F_2 ( V_2 ,
V_16 ,
V_27 [ V_3 ] . V_28 ,
V_27 [ V_3 ] . V_30 ) ;
if ( V_5 < 0 )
goto V_19;
}
}
memcpy ( V_2 -> V_34 . V_35 , V_27 , sizeof( V_27 ) ) ;
V_19:
F_7 ( V_8 ) ;
F_7 ( V_7 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_36 * V_10 = F_9 ( V_2 ) ;
int V_5 ;
F_10 ( & V_10 -> V_37 ) ;
if ( V_10 -> V_38 != V_39 ) {
V_5 = - V_40 ;
goto V_41;
}
V_5 = V_10 -> V_42 -> V_43 ( V_10 -> V_44 ) ;
if ( V_5 == 0 )
V_10 -> V_38 = V_45 ;
V_41:
F_11 ( & V_10 -> V_37 ) ;
return V_5 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_36 * V_10 = F_9 ( V_2 ) ;
F_10 ( & V_10 -> V_37 ) ;
if ( V_10 -> V_38 == V_39 )
goto V_41;
V_10 -> V_42 -> V_46 ( V_10 -> V_44 ) ;
V_10 -> V_38 = V_39 ;
V_41:
F_11 ( & V_10 -> V_37 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_36 * V_10 = F_9 ( V_2 ) ;
struct V_6 * V_47 ;
T_1 V_48 ;
T_1 V_49 [ 2 ] ;
int V_50 = 0 ;
int V_5 ;
if ( V_10 -> V_51 -> V_52 &&
V_10 -> V_51 -> V_53 ) {
V_49 [ V_50 ++ ] = V_54 ;
V_49 [ V_50 ++ ] = V_26 ;
} else if ( ! V_10 -> V_51 -> V_52 &&
V_10 -> V_51 -> V_53 ) {
V_49 [ V_50 ++ ] = V_54 ;
} else if ( V_10 -> V_51 -> V_52 &&
! V_10 -> V_51 -> V_53 ) {
V_49 [ V_50 ++ ] = V_26 ;
}
if ( V_50 ) {
V_5 = F_14 ( V_2 , V_55 ,
V_56 ,
( T_1 * ) & V_49 , V_50 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_5 = F_15 ( V_2 , V_17 ,
V_57 , & V_47 ) ;
if ( V_5 < 0 )
return V_5 ;
V_48 = V_47 -> V_22 [ 0 ] ;
F_7 ( V_47 ) ;
if ( V_48 == 0 ) {
V_48 = 1 ;
V_5 = F_14 ( V_2 , V_17 ,
V_57 , & V_48 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_5 = F_16 ( V_2 , V_58 ,
V_59 , NULL , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_15 ( V_2 , V_60 ,
V_61 , & V_47 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_47 -> V_21 != V_62 ) {
F_7 ( V_47 ) ;
return - V_63 ;
}
F_17 ( V_64 , L_2 ,
V_65 , 16 , 1 ,
V_47 -> V_22 , V_62 , false ) ;
F_7 ( V_47 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_6 * V_47 )
{
struct V_36 * V_10 = F_9 ( V_2 ) ;
return V_10 -> V_42 -> V_66 ( V_10 -> V_44 , V_47 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
T_2 V_67 , T_2 V_68 )
{
int V_5 ;
T_2 V_69 ;
T_1 V_48 [ 19 ] ;
struct V_6 * V_70 ;
F_20 ( V_71 L_3 ,
V_72 , V_67 , V_68 ) ;
V_5 = F_16 ( V_2 , V_58 ,
V_59 , NULL , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_67 ) {
if ( ( V_73 & V_67 ) == 0 ) {
V_5 = F_21 ( V_2 ,
V_73 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( ( V_58 & V_67 ) == 0 ) {
V_5 = F_21 ( V_2 ,
V_58 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( ( V_74 & V_67 ) == 0 ) {
V_5 = F_21 ( V_2 ,
V_74 ) ;
if ( V_5 < 0 )
return V_5 ;
} else {
V_2 -> V_75 = F_22 ( V_2 -> V_76 ,
& V_2 -> V_77 ) ;
if ( V_2 -> V_75 == NULL || V_2 -> V_77 == 0 ) {
V_67 &= ~ V_78 ;
V_68 &= ~ V_78 ;
}
V_48 [ 0 ] = V_79 |
V_80 |
V_81 ;
V_5 = F_14 ( V_2 , V_74 ,
V_82 ,
V_48 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_69 = F_23 ( ( V_83 V_84 )
V_85 ) ;
V_5 = F_14 ( V_2 , V_74 ,
V_86 ,
( T_1 * ) & V_69 , 4 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( ( V_87 & V_67 ) == 0 ) {
V_5 = F_21 ( V_2 ,
V_87 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( ( V_88 & V_67 ) == 0 ) {
V_5 = F_21 ( V_2 ,
V_88 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_5 = F_16 ( V_2 , V_58 ,
V_89 , NULL , 0 ) ;
if ( V_5 < 0 )
F_16 ( V_2 , V_58 ,
V_59 , NULL , 0 ) ;
}
if ( V_68 & V_78 ) {
V_5 = F_15 ( V_2 , V_90 ,
V_91 ,
& V_70 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_70 -> V_21 > 0 &&
V_70 -> V_22 [ 0 ] !=
V_92 ) {
V_48 [ 0 ] = V_92 ;
V_5 = F_14 ( V_2 , V_90 ,
V_91 ,
V_48 , 1 ) ;
if ( V_5 < 0 ) {
F_7 ( V_70 ) ;
return V_5 ;
}
}
F_7 ( V_70 ) ;
V_48 [ 0 ] = 0x00 ;
V_48 [ 1 ] = 0x08 ;
V_5 = F_14 ( V_2 , V_90 ,
V_93 , V_48 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_48 [ 0 ] = 0x40 ;
V_5 = F_14 ( V_2 , V_90 ,
V_94 , V_48 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_14 ( V_2 , V_90 ,
V_95 , NULL , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_48 [ 0 ] = 0x00 ;
V_48 [ 1 ] = 0x00 ;
V_48 [ 2 ] = 0x01 ;
V_48 [ 3 ] = 0xfe ;
V_48 [ 4 ] = 'S' ;
V_48 [ 5 ] = 'T' ;
V_48 [ 6 ] = 'M' ;
V_48 [ 7 ] = 'i' ;
V_48 [ 8 ] = 'c' ;
V_48 [ 9 ] = 'r' ;
V_48 [ 18 ] = 0x01 ;
V_5 = F_14 ( V_2 , V_90 ,
V_96 , V_48 ,
19 ) ;
if ( V_5 < 0 )
return V_5 ;
V_48 [ 0 ] = 0x02 ;
V_5 = F_14 ( V_2 , V_90 ,
V_97 , V_48 , 1 ) ;
}
return V_5 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_17 ,
V_98 , NULL , 0 , NULL ) ;
}
static int F_25 ( struct V_1 * V_2 , T_3 * V_99 )
{
int V_5 ;
struct V_6 * V_100 = NULL ;
V_5 = F_15 ( V_2 , V_87 ,
V_101 , & V_100 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_100 -> V_21 != 2 ) {
V_5 = - V_102 ;
goto exit;
}
* V_99 = F_26 ( * ( V_103 * ) V_100 -> V_22 ) ;
exit:
F_7 ( V_100 ) ;
return V_5 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 * V_104 )
{
int V_5 ;
struct V_6 * V_105 = NULL ;
V_5 = F_15 ( V_2 , V_87 ,
V_106 , & V_105 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_105 -> V_21 != 1 ) {
V_5 = - V_102 ;
goto exit;
}
* V_104 = V_105 -> V_22 [ 0 ] ;
exit:
F_7 ( V_105 ) ;
return V_5 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 * V_107 ,
int * V_21 )
{
int V_5 ;
struct V_6 * V_108 = NULL ;
V_5 = F_15 ( V_2 , V_87 ,
V_109 , & V_108 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_108 -> V_21 == 0 || V_108 -> V_21 > V_110 ) {
V_5 = - V_102 ;
goto exit;
}
memcpy ( V_107 , V_108 -> V_22 , V_108 -> V_21 ) ;
* V_21 = V_108 -> V_21 ;
exit:
F_7 ( V_108 ) ;
return V_5 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
int V_5 ;
struct V_6 * V_113 = NULL ;
V_5 = F_15 ( V_2 , V_88 ,
V_114 ,
& V_113 ) ;
if ( V_5 < 0 )
goto exit;
F_30 ( V_113 , 2 ) ;
if ( V_113 -> V_21 == 0 ||
V_113 -> V_21 > V_115 ) {
V_5 = - V_102 ;
goto exit;
}
memcpy ( V_112 -> V_116 , V_113 -> V_22 , V_113 -> V_21 ) ;
V_112 -> V_117 = V_113 -> V_22 [ 1 ] ;
V_112 -> V_118 = 1 ;
exit:
F_7 ( V_113 ) ;
return V_5 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_111 * V_112 , T_1 V_119 ,
T_1 * V_75 , T_4 V_77 )
{
struct V_36 * V_10 = F_9 ( V_2 ) ;
V_10 -> V_120 . V_121 = V_112 -> V_121 ;
return F_32 ( V_2 , V_75 , V_77 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_36 * V_10 = F_9 ( V_2 ) ;
V_10 -> V_38 = V_45 ;
return F_3 ( V_2 , V_17 ,
V_98 , NULL , 0 , NULL ) ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_28 ,
struct V_111 * V_112 )
{
int V_5 , V_21 ;
T_3 V_99 ;
T_1 V_104 ;
T_1 V_107 [ V_110 ] ;
switch ( V_28 ) {
case V_74 :
V_112 -> V_122 = V_123 ;
break;
case V_87 :
V_5 = F_25 ( V_2 , & V_99 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_99 == 0x000c ) {
V_112 -> V_122 = V_124 ;
V_112 -> V_125 = 0x0c00 ;
} else {
V_5 = F_27 ( V_2 , & V_104 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_28 ( V_2 , V_107 , & V_21 ) ;
if ( V_5 < 0 )
return V_5 ;
V_112 -> V_122 =
F_35 ( V_104 ) ;
if ( V_112 -> V_122 == 0xffffffff )
return - V_102 ;
V_112 -> V_125 = V_99 ;
V_112 -> V_126 = V_104 ;
memcpy ( V_112 -> V_127 , V_107 , V_21 ) ;
V_112 -> V_128 = V_21 ;
}
break;
case V_88 :
V_112 -> V_122 = V_129 ;
V_5 = F_29 ( V_2 , V_112 ) ;
if ( V_5 < 0 )
return V_5 ;
break;
default:
return - V_102 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
T_1 V_28 ,
struct V_111 * V_112 )
{
int V_5 ;
struct V_6 * V_130 = NULL ;
if ( V_28 == V_74 ) {
V_5 = F_15 ( V_2 , V_74 ,
V_131 , & V_130 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_130 -> V_21 > V_132 ) {
V_5 = - V_102 ;
goto exit;
}
if ( V_130 -> V_21 > 0 ) {
memcpy ( V_112 -> V_133 , V_130 -> V_22 ,
V_130 -> V_21 ) ;
V_112 -> V_134 = V_130 -> V_21 ;
if ( V_112 -> V_133 [ 0 ] == 0x01 &&
V_112 -> V_133 [ 1 ] == 0xfe )
V_112 -> V_122 =
V_78 ;
else
V_112 -> V_122 =
V_123 ;
} else {
F_7 ( V_130 ) ;
V_5 = F_15 ( V_2 , V_74 ,
V_135 ,
& V_130 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_130 -> V_21 > V_110 ) {
V_5 = - V_102 ;
goto exit;
}
memcpy ( V_112 -> V_133 , V_130 -> V_22 ,
V_130 -> V_21 ) ;
V_112 -> V_134 = V_130 -> V_21 ;
V_112 -> V_122 = V_78 ;
}
V_112 -> V_136 = V_74 ;
}
V_5 = 1 ;
exit:
F_7 ( V_130 ) ;
return V_5 ;
}
static void F_37 ( void * V_137 , struct V_6 * V_47 ,
int V_138 )
{
struct V_36 * V_10 = V_137 ;
switch ( V_10 -> V_139 ) {
case V_140 :
if ( V_138 == 0 )
F_38 ( V_47 , V_47 -> V_21 - 1 ) ;
V_10 -> V_141 ( V_10 -> V_142 , V_47 , V_138 ) ;
break;
default:
if ( V_138 == 0 )
F_7 ( V_47 ) ;
break;
}
}
static int F_39 ( struct V_1 * V_2 ,
struct V_111 * V_112 ,
struct V_6 * V_47 ,
T_5 V_143 , void * V_144 )
{
struct V_36 * V_10 = F_9 ( V_2 ) ;
F_20 ( V_71 L_4 , V_72 ,
V_112 -> V_136 , V_47 -> V_21 ) ;
switch ( V_112 -> V_136 ) {
case V_74 :
if ( V_112 -> V_122 == V_78 )
return F_40 ( V_2 , V_47 ) ;
* F_41 ( V_47 , 1 ) = 0x1a ;
return F_42 ( V_2 , V_112 -> V_136 ,
V_145 , V_47 -> V_22 ,
V_47 -> V_21 , V_143 , V_144 ) ;
case V_87 :
* F_41 ( V_47 , 1 ) = 0x1a ;
return F_42 ( V_2 , V_112 -> V_136 ,
V_145 , V_47 -> V_22 ,
V_47 -> V_21 , V_143 , V_144 ) ;
case V_88 :
V_10 -> V_139 = V_140 ;
V_10 -> V_141 = V_143 ;
V_10 -> V_142 = V_144 ;
* F_41 ( V_47 , 1 ) = 0x17 ;
return F_42 ( V_2 , V_112 -> V_136 ,
V_145 , V_47 -> V_22 ,
V_47 -> V_21 ,
F_37 ,
V_10 ) ;
break;
default:
return 1 ;
}
}
static int F_43 ( struct V_1 * V_2 , struct V_6 * V_47 )
{
return F_44 ( V_2 , V_47 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
T_1 V_146 = 0x11 ;
switch ( V_112 -> V_136 ) {
case V_58 :
case V_73 :
return F_3 ( V_2 , V_112 -> V_136 ,
V_145 , & V_146 , 1 , NULL ) ;
case V_87 :
return F_3 ( V_2 , V_112 -> V_136 ,
V_147 ,
NULL , 0 , NULL ) ;
default:
return - V_148 ;
}
}
static void F_46 ( struct V_1 * V_2 , T_1 V_30 , T_1 V_149 ,
struct V_6 * V_47 )
{
struct V_36 * V_10 = F_9 ( V_2 ) ;
T_1 V_28 = V_2 -> V_32 [ V_30 ] . V_28 ;
F_47 ( L_5 , V_149 ) ;
switch ( V_149 ) {
case V_150 :
if ( V_28 != V_24 &&
V_2 -> V_32 [ V_30 ] . V_33 != V_54 )
V_10 -> V_151 . V_152 ++ ;
if ( V_10 -> V_151 . V_152 == V_10 -> V_151 . V_153 ) {
F_48 ( & V_10 -> V_151 . V_154 ) ;
V_10 -> V_151 . V_155 = false ;
V_10 -> V_151 . V_152 = 0 ;
F_49 ( & V_10 -> V_151 . V_156 ) ;
}
break;
}
}
static int F_50 ( struct V_1 * V_2 , T_1 V_157 ,
struct V_6 * V_47 )
{
struct V_36 * V_10 = F_9 ( V_2 ) ;
F_47 ( L_6 , V_157 ) ;
switch ( V_157 ) {
case V_158 :
if ( V_10 -> V_151 . V_155 ) {
if ( ! F_51 ( V_47 ) ) {
F_48 ( & V_10 -> V_151 . V_154 ) ;
V_10 -> V_151 . V_155 = false ;
F_49 ( & V_10 -> V_151 . V_156 ) ;
} else {
F_52 ( & V_10 -> V_151 . V_154 ,
V_159 +
F_53 ( V_160 ) ) ;
}
}
break;
}
F_7 ( V_47 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , T_1 V_30 ,
T_1 V_157 , struct V_6 * V_47 )
{
T_1 V_28 = V_2 -> V_32 [ V_30 ] . V_28 ;
T_1 V_161 = V_2 -> V_32 [ V_30 ] . V_33 ;
F_47 ( L_7 , V_157 , V_28 ) ;
switch ( V_28 ) {
case V_55 :
return F_50 ( V_2 , V_157 , V_47 ) ;
case V_90 :
return F_55 ( V_2 , V_157 , V_47 ) ;
case V_162 :
return F_56 ( V_2 , V_161 ,
V_157 , V_47 ) ;
case V_24 :
return F_57 ( V_2 , V_157 , V_47 ) ;
default:
return 1 ;
}
}
int F_58 ( void * V_44 , struct V_163 * V_42 ,
char * V_164 , int V_165 , int V_166 ,
int V_167 , struct V_1 * * V_2 ,
struct V_168 * V_51 )
{
struct V_36 * V_10 ;
int V_5 = 0 ;
int V_169 ;
T_2 V_170 ;
struct V_171 V_34 ;
unsigned long V_172 = 0 ;
V_10 = F_59 ( sizeof( struct V_36 ) , V_173 ) ;
if ( ! V_10 ) {
V_5 = - V_174 ;
goto V_175;
}
V_10 -> V_42 = V_42 ;
V_10 -> V_44 = V_44 ;
V_10 -> V_38 = V_39 ;
F_60 ( & V_10 -> V_37 ) ;
V_34 . V_176 = F_5 ( V_27 ) ;
memcpy ( V_34 . V_35 , V_27 , sizeof( V_27 ) ) ;
V_169 = F_61 ( V_177 , V_178 ) ;
if ( V_169 >= V_178 )
return - V_179 ;
F_62 ( V_169 , V_177 ) ;
F_63 ( V_34 . V_180 , sizeof( V_34 . V_180 ) , L_8 ,
L_9 , V_169 ) ;
V_170 = V_124 |
V_181 |
V_123 |
V_182 |
V_183 |
V_129 |
V_78 ;
F_62 ( V_184 , & V_172 ) ;
V_10 -> V_2 =
F_64 ( & V_185 , & V_34 , V_172 ,
V_170 , V_164 ,
V_165 + V_186 ,
V_166 , V_167 ) ;
if ( ! V_10 -> V_2 ) {
F_4 ( L_10 ) ;
V_5 = - V_174 ;
goto V_175;
}
V_10 -> V_51 = V_51 ;
F_65 ( V_10 -> V_2 , V_10 ) ;
V_5 = F_66 ( V_10 -> V_2 ) ;
if ( V_5 )
goto V_187;
* V_2 = V_10 -> V_2 ;
F_67 ( V_10 -> V_2 ) ;
F_68 ( V_10 -> V_2 ) ;
return 0 ;
V_187:
F_69 ( V_10 -> V_2 ) ;
V_175:
F_70 ( V_10 ) ;
return V_5 ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_36 * V_10 = F_9 ( V_2 ) ;
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
F_69 ( V_2 ) ;
F_70 ( V_10 ) ;
}
