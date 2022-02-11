static inline void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
char * V_5 = L_1 ;
switch ( V_4 ) {
case - V_6 :
V_5 = L_2 ;
break;
case - V_7 :
V_5 = L_3 ;
break;
case - V_8 :
V_5 = L_4 ;
break;
case - V_9 :
V_5 = L_5 ;
break;
case - V_10 :
V_5 = L_6 ;
break;
case - V_11 :
V_5 = L_7 ;
break;
case - V_12 :
V_5 = L_8 ;
break;
case - V_13 :
V_5 = L_9 ;
break;
}
if ( V_3 < 0 ) {
F_2 ( 1 , L_10 , V_4 , V_5 ) ;
} else {
F_2 ( 1 , L_11 ,
V_3 , V_4 , V_5 ) ;
}
}
static inline int F_3 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
int V_15 ;
if ( ! V_2 )
return 0 ;
if ( ( V_2 -> V_16 & V_17 ) || ( V_2 -> V_16 & V_18 ) )
return 0 ;
if ( V_14 -> V_4 < 0 ) {
F_1 ( V_2 , - 1 , V_14 -> V_4 ) ;
if ( V_14 -> V_4 == - V_6 )
return 0 ;
}
for ( V_15 = 0 ; V_15 < V_14 -> V_19 ; V_15 ++ ) {
int V_4 = V_14 -> V_20 [ V_15 ] . V_4 ;
if ( V_4 < 0 ) {
F_1 ( V_2 , V_15 , V_4 ) ;
if ( V_14 -> V_20 [ V_15 ] . V_4 != - V_11 )
continue;
}
F_4 ( & V_2 -> V_21 -> V_22 , V_14 -> V_23 +
V_14 -> V_20 [ V_15 ] . V_24 ,
V_14 -> V_20 [ V_15 ] . V_25 ) ;
}
return 0 ;
}
static int F_5 ( struct V_26 * V_21 )
{
int V_27 ;
struct V_1 * V_2 = V_21 -> V_28 . V_29 ;
int V_30 ;
F_6 ( V_2 -> V_31 , 0 , 1 ) ;
V_27 = F_7 ( V_2 , V_32 ) ;
if ( V_27 < 0 )
return V_27 ;
V_30 = F_8 ( V_2 ) ;
return F_9 ( V_2 , V_33 ,
V_34 , V_30 ,
F_3 ) ;
}
static int F_10 ( struct V_26 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_28 . V_29 ;
F_11 ( V_2 ) ;
F_7 ( V_2 , V_35 ) ;
return 0 ;
}
static int F_12 ( struct V_36 * V_37 )
{
struct V_38 * V_22 = V_37 -> V_22 ;
struct V_26 * V_21 = V_22 -> V_29 ;
int V_27 , V_39 ;
if ( ! V_22 -> V_40 . V_41 )
return - V_42 ;
F_13 ( & V_21 -> V_43 ) ;
V_21 -> V_44 ++ ;
V_27 = V_21 -> V_44 ;
if ( V_21 -> V_44 == 1 ) {
V_39 = F_5 ( V_21 ) ;
if ( V_39 < 0 )
V_27 = V_39 ;
}
F_14 ( & V_21 -> V_43 ) ;
return V_27 ;
}
static int F_15 ( struct V_36 * V_37 )
{
struct V_38 * V_22 = V_37 -> V_22 ;
struct V_26 * V_21 = V_22 -> V_29 ;
int V_45 = 0 ;
F_13 ( & V_21 -> V_43 ) ;
V_21 -> V_44 -- ;
if ( 0 == V_21 -> V_44 )
V_45 = F_10 ( V_21 ) ;
F_14 ( & V_21 -> V_43 ) ;
return V_45 ;
}
static int F_16 ( struct V_46 * V_47 , int V_48 )
{
struct V_1 * V_2 = V_47 -> V_21 -> V_29 ;
if ( V_48 )
return F_7 ( V_2 , V_32 ) ;
else
return F_7 ( V_2 , V_35 ) ;
}
static int F_17 ( struct V_46 * V_47 )
{
static T_1 V_49 [] = { V_50 , 0x38 , 0x2c } ;
static T_1 V_51 [] = { V_52 , 0x80 } ;
static T_1 V_53 [] = { V_54 , 0x40 } ;
static T_1 V_55 [] = { V_56 , 0x28 , 0xa0 } ;
static T_1 V_57 [] = { V_58 , 0x31 , 0xb8 } ;
static T_1 V_59 [] = { V_60 , 0x00 , 0x4d } ;
static T_1 V_61 [] = { V_62 , 0x32 } ;
static T_1 V_63 [] = { V_64 , 0x64 , 0x00 } ;
static T_1 V_65 [] = { V_66 , 0x40 , 0x80 , 0x50 } ;
static T_1 V_67 [] = { V_68 , 0x01 } ;
F_18 ( V_47 , V_49 , sizeof( V_49 ) ) ;
F_19 ( 200 ) ;
F_18 ( V_47 , V_51 , sizeof( V_51 ) ) ;
F_18 ( V_47 , V_53 , sizeof( V_53 ) ) ;
F_18 ( V_47 , V_55 , sizeof( V_55 ) ) ;
F_18 ( V_47 , V_57 , sizeof( V_57 ) ) ;
F_18 ( V_47 , V_59 , sizeof( V_59 ) ) ;
F_18 ( V_47 , V_61 , sizeof( V_61 ) ) ;
F_18 ( V_47 , V_63 , sizeof( V_63 ) ) ;
F_18 ( V_47 , V_65 , sizeof( V_65 ) ) ;
F_18 ( V_47 , V_67 , sizeof( V_67 ) ) ;
return 0 ;
}
static int F_20 ( T_1 V_69 , struct V_1 * V_2 )
{
struct V_46 * V_47 ;
struct V_70 V_71 ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_72 = & V_2 -> V_72 ;
V_71 . V_73 = V_69 ;
if ( ! V_2 -> V_21 -> V_47 [ 0 ] ) {
F_21 ( L_12
L_13 ) ;
return - V_42 ;
}
V_47 = F_22 ( V_74 , V_2 -> V_21 -> V_47 [ 0 ] , & V_71 ) ;
if ( ! V_47 ) {
F_21 ( L_14 ) ;
F_23 ( V_2 -> V_21 -> V_47 [ 0 ] ) ;
V_2 -> V_21 -> V_47 [ 0 ] = NULL ;
return - V_42 ;
}
F_24 ( L_15 , V_2 -> V_75 ) ;
return 0 ;
}
static int F_25 ( struct V_26 * V_21 ,
struct V_76 * V_76 ,
struct V_1 * V_2 ,
struct V_77 * V_77 )
{
int V_78 ;
F_26 ( & V_21 -> V_43 ) ;
V_78 = F_27 ( & V_21 -> V_28 , V_2 -> V_75 , V_76 , V_77 ,
V_79 ) ;
if ( V_78 < 0 ) {
F_28 ( V_80 L_16 ,
V_2 -> V_75 , V_78 ) ;
goto V_81;
}
V_21 -> V_47 [ 0 ] -> V_82 . V_83 = F_16 ;
if ( V_21 -> V_47 [ 1 ] )
V_21 -> V_47 [ 1 ] -> V_82 . V_83 = F_16 ;
V_21 -> V_28 . V_29 = V_2 ;
V_78 = F_29 ( & V_21 -> V_28 , V_21 -> V_47 [ 0 ] ) ;
if ( V_78 < 0 ) {
F_28 ( V_80 L_17 ,
V_2 -> V_75 , V_78 ) ;
goto V_84;
}
if ( V_21 -> V_47 [ 1 ] ) {
V_78 = F_29 ( & V_21 -> V_28 , V_21 -> V_47 [ 1 ] ) ;
if ( V_78 < 0 ) {
F_28 ( V_80 L_18 ,
V_2 -> V_75 , V_78 ) ;
goto V_85;
}
}
V_21 -> V_22 . V_40 . V_86 =
V_87 | V_88 |
V_89 ;
V_21 -> V_22 . V_29 = V_21 ;
V_21 -> V_22 . V_90 = 256 ;
V_21 -> V_22 . V_91 = 256 ;
V_21 -> V_22 . F_12 = F_12 ;
V_21 -> V_22 . F_15 = F_15 ;
V_78 = F_30 ( & V_21 -> V_22 ) ;
if ( V_78 < 0 ) {
F_28 ( V_80 L_19 ,
V_2 -> V_75 , V_78 ) ;
goto V_92;
}
V_21 -> V_93 . V_90 = 256 ;
V_21 -> V_93 . V_22 = & V_21 -> V_22 . V_40 ;
V_21 -> V_93 . V_86 = 0 ;
V_78 = F_31 ( & V_21 -> V_93 , & V_21 -> V_28 ) ;
if ( V_78 < 0 ) {
F_28 ( V_80 L_20 ,
V_2 -> V_75 , V_78 ) ;
goto V_94;
}
V_21 -> V_95 . V_96 = V_97 ;
V_78 = V_21 -> V_22 . V_40 . V_98 ( & V_21 -> V_22 . V_40 , & V_21 -> V_95 ) ;
if ( V_78 < 0 ) {
F_28 ( V_80 L_21 ,
V_2 -> V_75 , V_78 ) ;
goto V_99;
}
V_21 -> V_100 . V_96 = V_101 ;
V_78 = V_21 -> V_22 . V_40 . V_98 ( & V_21 -> V_22 . V_40 , & V_21 -> V_100 ) ;
if ( V_78 < 0 ) {
F_28 ( V_80 L_22 ,
V_2 -> V_75 , V_78 ) ;
goto V_102;
}
V_78 = V_21 -> V_22 . V_40 . V_103 ( & V_21 -> V_22 . V_40 , & V_21 -> V_95 ) ;
if ( V_78 < 0 ) {
F_28 ( V_80 L_23 ,
V_2 -> V_75 , V_78 ) ;
goto V_104;
}
F_32 ( & V_21 -> V_28 , & V_21 -> V_105 , & V_21 -> V_22 . V_40 ) ;
return 0 ;
V_104:
V_21 -> V_22 . V_40 . V_106 ( & V_21 -> V_22 . V_40 , & V_21 -> V_100 ) ;
V_102:
V_21 -> V_22 . V_40 . V_106 ( & V_21 -> V_22 . V_40 , & V_21 -> V_95 ) ;
V_99:
F_33 ( & V_21 -> V_93 ) ;
V_94:
F_34 ( & V_21 -> V_22 ) ;
V_92:
if ( V_21 -> V_47 [ 1 ] )
F_35 ( V_21 -> V_47 [ 1 ] ) ;
F_35 ( V_21 -> V_47 [ 0 ] ) ;
V_85:
if ( V_21 -> V_47 [ 1 ] )
F_23 ( V_21 -> V_47 [ 1 ] ) ;
V_84:
F_23 ( V_21 -> V_47 [ 0 ] ) ;
F_36 ( & V_21 -> V_28 ) ;
V_81:
return V_78 ;
}
static void F_37 ( struct V_26 * V_21 )
{
F_38 ( & V_21 -> V_105 ) ;
V_21 -> V_22 . V_40 . V_106 ( & V_21 -> V_22 . V_40 , & V_21 -> V_100 ) ;
V_21 -> V_22 . V_40 . V_106 ( & V_21 -> V_22 . V_40 , & V_21 -> V_95 ) ;
F_33 ( & V_21 -> V_93 ) ;
F_34 ( & V_21 -> V_22 ) ;
if ( V_21 -> V_47 [ 1 ] )
F_35 ( V_21 -> V_47 [ 1 ] ) ;
F_35 ( V_21 -> V_47 [ 0 ] ) ;
if ( V_21 -> V_47 [ 1 ] )
F_23 ( V_21 -> V_47 [ 1 ] ) ;
F_23 ( V_21 -> V_47 [ 0 ] ) ;
F_36 ( & V_21 -> V_28 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_78 = 0 ;
struct V_26 * V_21 ;
if ( ! V_2 -> V_107 . V_108 ) {
F_28 ( V_109 L_24 ) ;
return 0 ;
}
V_21 = F_40 ( sizeof( struct V_26 ) , V_110 ) ;
if ( V_21 == NULL ) {
F_24 ( L_25 ) ;
return - V_111 ;
}
V_2 -> V_21 = V_21 ;
V_21 -> V_47 [ 0 ] = V_21 -> V_47 [ 1 ] = NULL ;
F_13 ( & V_2 -> V_43 ) ;
F_7 ( V_2 , V_32 ) ;
switch ( V_2 -> V_112 ) {
case V_113 :
V_21 -> V_47 [ 0 ] = F_22 ( V_114 ,
& V_115 , & V_2 -> V_72 ) ;
if ( ! V_21 -> V_47 [ 0 ] ) {
V_78 = - V_42 ;
goto V_116;
}
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_21 -> V_47 [ 0 ] = F_22 ( V_121 ,
& V_122 ,
& V_2 -> V_72 ) ;
if ( F_20 ( 0x61 , V_2 ) < 0 ) {
V_78 = - V_42 ;
goto V_116;
}
break;
case V_123 :
V_21 -> V_47 [ 0 ] = F_22 ( V_124 ,
& V_125 ,
& V_2 -> V_72 ) ;
if ( F_20 ( 0x61 , V_2 ) < 0 ) {
V_78 = - V_42 ;
goto V_116;
}
break;
case V_126 :
case V_127 :
case V_128 :
V_21 -> V_47 [ 0 ] = F_22 ( V_124 ,
& V_129 ,
& V_2 -> V_72 ) ;
if ( F_20 ( 0x61 , V_2 ) < 0 ) {
V_78 = - V_42 ;
goto V_116;
}
break;
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
V_21 -> V_47 [ 0 ] = F_22 ( V_124 ,
& V_129 ,
& V_2 -> V_72 ) ;
if ( V_21 -> V_47 [ 0 ] == NULL ) {
V_21 -> V_47 [ 0 ] = F_22 ( V_135 ,
& V_136 ,
& V_2 -> V_72 ) ;
}
if ( F_20 ( 0x61 , V_2 ) < 0 ) {
V_78 = - V_42 ;
goto V_116;
}
break;
case V_137 :
case V_138 :
V_21 -> V_47 [ 0 ] = F_22 ( V_139 ,
& V_140 ,
& V_2 -> V_72 ) ;
if ( F_20 ( 0x61 , V_2 ) < 0 ) {
V_78 = - V_42 ;
goto V_116;
}
break;
case V_141 :
V_21 -> V_47 [ 0 ] = F_22 ( V_121 ,
& V_122 ,
& V_2 -> V_72 ) ;
if ( V_21 -> V_47 [ 0 ] != NULL ) {
if ( ! F_22 ( V_142 , V_21 -> V_47 [ 0 ] ,
& V_2 -> V_72 , 0x61 , V_143 ) ) {
V_78 = - V_42 ;
goto V_116;
}
}
break;
case V_144 :
case V_145 :
V_21 -> V_47 [ 0 ] = F_22 ( V_146 , & V_147 , NULL ,
& V_2 -> V_72 , & V_2 -> V_31 -> V_2 ) ;
if ( F_20 ( 0x61 , V_2 ) < 0 ) {
V_78 = - V_42 ;
goto V_116;
}
break;
case V_148 :
V_21 -> V_47 [ 0 ] = F_22 ( V_149 ,
& V_150 ,
& V_2 -> V_72 , 0x48 ) ;
if ( V_21 -> V_47 [ 0 ] ) {
if ( ! F_22 ( V_142 , V_21 -> V_47 [ 0 ] ,
& V_2 -> V_72 , 0x60 , V_151 ) ) {
V_78 = - V_42 ;
goto V_116;
}
}
break;
case V_152 :
V_21 -> V_47 [ 0 ] = F_22 ( V_153 ,
& V_154 ,
& V_2 -> V_72 ) ;
if ( V_21 -> V_47 [ 0 ] != NULL )
F_22 ( V_155 , V_21 -> V_47 [ 0 ] , 0x60 ,
& V_2 -> V_72 , & V_156 ) ;
break;
case V_157 :
V_21 -> V_47 [ 0 ] = F_22 ( V_158 ,
& V_159 , & V_2 -> V_72 , NULL ) ;
if ( V_21 -> V_47 [ 0 ] ) {
struct V_160 * V_161 ;
V_161 = F_41 ( V_21 -> V_47 [ 0 ] ) ;
if ( ! F_22 ( V_155 , V_21 -> V_47 [ 0 ] , 0x60 ,
V_161 , & V_162 ) ) {
F_23 ( V_21 -> V_47 [ 0 ] ) ;
V_78 = - V_42 ;
goto V_116;
}
V_21 -> V_47 [ 1 ] = F_22 ( V_158 , NULL , NULL ,
V_21 -> V_47 [ 0 ] ) ;
V_21 -> V_47 [ 1 ] -> V_163 = 1 ;
if ( ! F_22 ( V_155 , V_21 -> V_47 [ 1 ] , 0x60 ,
V_161 , & V_162 ) ) {
F_23 ( V_21 -> V_47 [ 1 ] ) ;
}
}
break;
default:
F_21 ( L_26
L_27 ) ;
break;
}
if ( NULL == V_21 -> V_47 [ 0 ] ) {
F_21 ( L_28 ) ;
V_78 = - V_42 ;
goto V_116;
}
V_21 -> V_47 [ 0 ] -> V_164 = V_165 ;
V_78 = F_25 ( V_21 , V_166 , V_2 , & V_2 -> V_31 -> V_2 ) ;
if ( V_78 < 0 )
goto V_116;
F_24 ( L_29 ) ;
V_39:
F_7 ( V_2 , V_35 ) ;
F_14 ( & V_2 -> V_43 ) ;
return V_78 ;
V_116:
F_42 ( V_21 ) ;
V_2 -> V_21 = NULL ;
goto V_39;
}
static int F_43 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_107 . V_108 ) {
return 0 ;
}
if ( V_2 -> V_21 ) {
F_37 ( V_2 -> V_21 ) ;
F_42 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
}
return 0 ;
}
static int T_2 F_44 ( void )
{
return F_45 ( & V_167 ) ;
}
static void T_3 F_46 ( void )
{
F_47 ( & V_167 ) ;
}
