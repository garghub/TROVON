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
F_20 ( V_63 L_2 ,
V_64 , V_61 , V_62 ) ;
V_5 = F_16 ( V_2 , V_52 ,
V_53 , NULL , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_61 ) {
if ( ( V_65 & V_61 ) == 0 ) {
V_5 = F_21 ( V_2 ,
V_65 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( ( V_52 & V_61 ) == 0 ) {
V_5 = F_21 ( V_2 ,
V_52 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( ( V_66 & V_61 ) == 0 ) {
V_5 = F_21 ( V_2 ,
V_66 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( ( V_67 & V_61 ) == 0 ) {
V_5 = F_21 ( V_2 ,
V_67 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( ( V_68 & V_61 ) == 0 ) {
V_5 = F_21 ( V_2 ,
V_68 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_5 = F_16 ( V_2 , V_52 ,
V_69 , NULL , 0 ) ;
if ( V_5 < 0 )
F_16 ( V_2 , V_52 ,
V_53 , NULL , 0 ) ;
}
return V_5 ;
}
static int F_22 ( struct V_1 * V_2 , T_3 * V_70 )
{
int V_5 ;
struct V_6 * V_71 = NULL ;
V_5 = F_15 ( V_2 , V_67 ,
V_72 , & V_71 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_71 -> V_25 != 2 ) {
V_5 = - V_73 ;
goto exit;
}
* V_70 = F_23 ( * ( V_74 * ) V_71 -> V_26 ) ;
exit:
F_7 ( V_71 ) ;
return V_5 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 * V_75 )
{
int V_5 ;
struct V_6 * V_76 = NULL ;
V_5 = F_15 ( V_2 , V_67 ,
V_77 , & V_76 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_76 -> V_25 != 1 ) {
V_5 = - V_73 ;
goto exit;
}
* V_75 = V_76 -> V_26 [ 0 ] ;
exit:
F_7 ( V_76 ) ;
return V_5 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 * V_28 ,
int * V_25 )
{
int V_5 ;
struct V_6 * V_78 = NULL ;
V_5 = F_15 ( V_2 , V_67 ,
V_79 , & V_78 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_78 -> V_25 == 0 || V_78 -> V_25 > V_80 ) {
V_5 = - V_73 ;
goto exit;
}
V_28 = V_78 -> V_26 ;
* V_25 = V_78 -> V_25 ;
exit:
F_7 ( V_78 ) ;
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_81 * V_82 )
{
int V_5 ;
struct V_6 * V_83 = NULL ;
V_5 = F_15 ( V_2 , V_68 ,
V_84 ,
& V_83 ) ;
if ( V_5 < 0 )
goto exit;
F_27 ( V_83 , 2 ) ;
if ( V_83 -> V_25 == 0 ||
V_83 -> V_25 > V_85 ) {
V_5 = - V_73 ;
goto exit;
}
memcpy ( V_82 -> V_86 , V_83 -> V_26 , V_83 -> V_25 ) ;
V_82 -> V_87 = V_83 -> V_26 [ 1 ] ;
V_82 -> V_88 = 1 ;
exit:
F_7 ( V_83 ) ;
return V_5 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_28 ,
struct V_81 * V_82 )
{
int V_5 , V_25 ;
T_3 V_70 ;
T_1 V_75 ;
T_1 V_89 [ V_80 ] ;
switch ( V_28 ) {
case V_66 :
V_82 -> V_90 = V_91 ;
break;
case V_67 :
V_5 = F_22 ( V_2 , & V_70 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_70 == 0x000c ) {
V_82 -> V_90 = V_92 ;
V_82 -> V_93 = 0x0c00 ;
} else {
V_5 = F_24 ( V_2 , & V_75 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_25 ( V_2 , V_89 , & V_25 ) ;
if ( V_5 < 0 )
return V_5 ;
V_82 -> V_90 =
F_29 ( V_75 ) ;
if ( V_82 -> V_90 == 0xffffffff )
return - V_73 ;
V_82 -> V_93 = V_70 ;
V_82 -> V_94 = V_75 ;
memcpy ( V_82 -> V_95 , V_89 , V_25 ) ;
V_82 -> V_96 = V_25 ;
}
break;
case V_68 :
V_82 -> V_90 = V_97 ;
V_5 = F_26 ( V_2 , V_82 ) ;
if ( V_5 < 0 )
return V_5 ;
break;
default:
return - V_73 ;
}
return 0 ;
}
static void F_30 ( void * V_98 , struct V_6 * V_46 ,
int V_99 )
{
struct V_35 * V_10 = V_98 ;
switch ( V_10 -> V_100 ) {
case V_101 :
if ( V_99 == 0 )
F_31 ( V_46 , V_46 -> V_25 - 1 ) ;
V_10 -> V_102 ( V_10 -> V_103 , V_46 , V_99 ) ;
break;
default:
if ( V_99 == 0 )
F_7 ( V_46 ) ;
break;
}
}
static int F_32 ( struct V_1 * V_2 ,
struct V_81 * V_82 ,
struct V_6 * V_46 ,
T_4 V_104 , void * V_105 )
{
struct V_35 * V_10 = F_9 ( V_2 ) ;
F_20 ( V_63 L_3 , V_64 ,
V_82 -> V_106 , V_46 -> V_25 ) ;
switch ( V_82 -> V_106 ) {
case V_66 :
* F_33 ( V_46 , 1 ) = 0x1a ;
return F_34 ( V_2 , V_82 -> V_106 ,
V_107 , V_46 -> V_26 ,
V_46 -> V_25 , V_104 , V_105 ) ;
case V_67 :
* F_33 ( V_46 , 1 ) = 0x1a ;
return F_34 ( V_2 , V_82 -> V_106 ,
V_107 , V_46 -> V_26 ,
V_46 -> V_25 , V_104 , V_105 ) ;
case V_68 :
V_10 -> V_100 = V_101 ;
V_10 -> V_102 = V_104 ;
V_10 -> V_103 = V_105 ;
* F_33 ( V_46 , 1 ) = 0x17 ;
return F_34 ( V_2 , V_82 -> V_106 ,
V_107 , V_46 -> V_26 ,
V_46 -> V_25 ,
F_30 ,
V_10 ) ;
break;
default:
return 1 ;
}
}
static int F_35 ( struct V_1 * V_2 ,
struct V_81 * V_82 )
{
T_1 V_108 = 0x11 ;
switch ( V_82 -> V_106 ) {
case V_52 :
case V_65 :
return F_4 ( V_2 , V_82 -> V_106 ,
V_107 , & V_108 , 1 , NULL ) ;
case V_67 :
return F_4 ( V_2 , V_82 -> V_106 ,
V_109 ,
NULL , 0 , NULL ) ;
default:
return - V_110 ;
}
}
int F_36 ( void * V_43 , struct V_111 * V_41 ,
char * V_112 , int V_113 , int V_114 ,
int V_115 , struct V_1 * * V_2 )
{
struct V_35 * V_10 ;
int V_5 = 0 ;
int V_116 ;
T_2 V_117 ;
struct V_118 V_33 ;
unsigned long V_119 = 0 ;
V_10 = F_37 ( sizeof( struct V_35 ) , V_17 ) ;
if ( ! V_10 ) {
V_5 = - V_18 ;
goto V_120;
}
V_10 -> V_41 = V_41 ;
V_10 -> V_43 = V_43 ;
V_10 -> V_37 = V_38 ;
F_38 ( & V_10 -> V_36 ) ;
V_33 . V_121 = F_5 ( V_27 ) ;
memcpy ( V_33 . V_34 , V_27 , sizeof( V_27 ) ) ;
V_116 = F_39 ( V_122 , V_123 ) ;
if ( V_116 >= V_123 )
goto V_120;
F_40 ( V_33 . V_124 , sizeof( V_33 . V_124 ) , L_4 ,
L_5 , V_116 ) ;
V_117 = V_92 |
V_125 |
V_91 |
V_126 |
V_127 |
V_97 ;
F_41 ( V_128 , & V_119 ) ;
V_10 -> V_2 =
F_42 ( & V_129 , & V_33 , V_119 ,
V_117 , V_112 ,
V_113 + V_130 ,
V_114 , V_115 ) ;
if ( ! V_10 -> V_2 ) {
F_43 ( L_6 ) ;
V_5 = - V_18 ;
goto V_120;
}
F_44 ( V_10 -> V_2 , V_10 ) ;
V_5 = F_45 ( V_10 -> V_2 ) ;
if ( V_5 )
goto V_131;
* V_2 = V_10 -> V_2 ;
return 0 ;
V_131:
F_46 ( V_10 -> V_2 ) ;
V_120:
F_47 ( V_10 ) ;
return V_5 ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_35 * V_10 = F_9 ( V_2 ) ;
F_49 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_10 ) ;
}
