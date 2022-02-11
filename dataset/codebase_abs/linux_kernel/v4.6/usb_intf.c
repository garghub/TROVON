static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_4 ( V_5 , L_1 ) ;
if ( ! V_5 || ! F_5 ( V_5 ) ) {
F_4 ( V_5 , L_2 ) ;
return 0 ;
}
V_7 -> V_8 = true ;
F_6 ( V_7 ) ;
if ( V_5 -> V_9 -> V_10 )
V_5 -> V_9 -> V_10 ( V_5 ) ;
F_7 ( 10 ) ;
F_8 ( V_5 ) ;
return 0 ;
}
static void F_9 ( struct V_6 * V_7 )
{
if ( V_7 -> V_11 . V_12 )
V_7 -> V_11 . V_12 ( V_7 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_4 ( V_5 , L_3 ) ;
if ( ! V_5 || ! F_5 ( V_5 ) ) {
F_4 ( V_5 , L_4 ) ;
return 0 ;
}
F_11 ( V_5 ) ;
if ( V_5 -> V_9 -> V_13 )
V_5 -> V_9 -> V_13 ( V_5 ) ;
V_7 -> V_8 = false ;
F_9 ( V_7 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return 0 ;
}
static T_2 F_13 ( struct V_6 * V_7 )
{
T_2 V_14 = V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 = & V_7 -> V_11 ;
struct V_22 * V_23 = V_21 -> V_24 ;
V_21 -> V_7 = V_7 ;
V_7 -> V_25 = 6 ;
V_17 = & V_26 -> V_27 [ 0 ] ;
V_19 = & V_17 -> V_28 ;
V_21 -> V_29 = V_19 -> V_30 ;
if ( V_23 -> V_31 == V_32 ) {
V_21 -> V_33 = true ;
F_14 ( & V_23 -> V_34 , L_5 ,
V_21 -> V_29 ) ;
} else {
V_21 -> V_33 = false ;
F_14 ( & V_23 -> V_34 , L_6 ,
V_21 -> V_29 ) ;
}
if ( ( F_15 ( V_7 ) ) == V_35 )
V_14 = V_35 ;
return V_14 ;
}
static void F_16 ( struct V_6 * V_7 )
{
}
void F_6 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_36 ) {
}
if ( V_7 -> V_11 . V_37 )
V_7 -> V_11 . V_37 ( V_7 ) ;
F_17 ( V_7 ) ;
}
void F_18 ( struct V_6 * V_7 )
{
if ( V_7 -> V_38 ) {
V_7 -> V_39 = true ;
F_6 ( V_7 ) ;
F_19 ( V_7 ) ;
if ( ! V_7 -> V_36 ) {
V_7 -> V_40 = false ;
F_20 ( V_7 ) ;
}
if ( V_7 -> V_41 )
V_7 -> V_41 ( V_7 ) ;
V_7 -> V_38 = false ;
}
}
static void F_21 ( const struct V_42 * V_43 ,
struct V_6 * V_7 )
{
T_3 V_44 , V_45 ;
T_4 V_46 ;
int V_47 ;
int V_48 = F_22 ( V_49 ) ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
V_44 = V_49 [ V_47 ] . V_50 ;
V_45 = V_49 [ V_47 ] . V_51 ;
V_46 = V_49 [ V_47 ] . V_46 ;
if ( ( V_43 -> V_50 == V_44 ) && ( V_43 -> V_51 == V_45 ) &&
( V_46 & V_52 ) ) {
V_7 -> V_53 . V_54 = 0 ;
V_7 -> V_53 . V_55 = 0 ;
V_7 -> V_53 . V_56 = 0 ;
}
}
}
static int F_23 ( struct V_1 * V_2 ,
const struct V_42 * V_43 )
{
T_2 V_14 ;
struct V_6 * V_7 = NULL ;
struct V_20 * V_21 ;
struct V_4 * V_5 ;
struct V_22 * V_57 ;
V_57 = F_24 ( V_2 ) ;
F_25 ( V_57 ) ;
V_26 = V_2 ;
V_5 = F_26 () ;
if ( ! V_5 )
goto error;
V_7 = F_3 ( V_5 ) ;
F_21 ( V_43 , V_7 ) ;
V_21 = & V_7 -> V_11 ;
V_21 -> V_7 = V_7 ;
V_7 -> V_11 . V_24 = V_57 ;
V_7 -> V_2 = V_2 ;
F_27 ( V_2 , V_5 ) ;
F_28 ( V_5 , & V_2 -> V_34 ) ;
V_5 -> V_34 . type = & V_58 ;
V_7 -> V_59 = F_13 ;
V_7 -> V_41 = F_16 ;
V_7 -> V_60 . V_61 = V_62 ;
V_7 -> V_11 . V_12 = V_63 ;
V_7 -> V_11 . V_37 = V_64 ;
if ( ! V_7 -> V_59 ) {
goto error;
} else {
V_14 = V_7 -> V_59 ( V_7 ) ;
if ( V_14 != V_15 )
goto error;
}
V_14 = F_29 ( V_7 ) ;
if ( V_14 == V_35 )
goto error;
{
int V_47 , V_65 ;
T_5 V_66 [ 6 ] ;
T_5 V_67 , V_68 , V_69 ;
T_5 * V_70 = V_7 -> V_71 . V_72 ;
V_67 = F_30 ( V_7 , V_73 ) ;
F_14 ( & V_57 -> V_34 , L_7 ,
( V_67 & V_74 ) ? L_8 : L_9 ,
( V_67 & V_75 ) ? L_10 : L_11 ) ;
if ( V_67 & V_75 ) {
V_68 = true ;
V_67 = F_30 ( V_7 , V_76 + 3 ) ;
F_31 ( V_7 , V_76 + 3 , V_67 | 0x80 ) ;
F_32 ( 20 ) ;
F_31 ( V_7 , V_76 + 3 ,
( V_67 & ( ~ F_33 ( 7 ) ) ) ) ;
V_67 = ( T_5 ) ( ( F_34 ( V_7 , V_77 ) >> 15 ) &
0x1F ) ;
if ( V_67 == 0x3 )
V_7 -> V_53 . V_78 =
V_79 ;
else
V_7 -> V_53 . V_78 =
( V_67 >> 1 ) + 1 ;
switch ( V_7 -> V_53 . V_78 ) {
case V_80 :
case V_81 :
case V_79 :
break;
default:
V_7 -> V_53 . V_78 =
V_81 ;
break;
}
for ( V_47 = 0 , V_65 = 0 ; V_47 < 128 ; V_47 += 8 , V_65 ++ )
F_35 ( V_7 , V_65 ,
& V_70 [ V_47 ] ) ;
if ( ! V_82 || ! F_36 ( V_82 , V_66 ) ) {
F_37 ( V_66 , & V_70 [ 0x12 ] ) ;
}
V_69 = V_70 [ 0x52 ] ;
switch ( V_69 ) {
case V_83 :
V_7 -> V_71 . V_84 =
V_85 ;
break;
case V_86 :
V_7 -> V_71 . V_84 =
V_87 ;
break;
case V_88 :
V_7 -> V_71 . V_84 =
V_89 ;
break;
case V_90 :
V_7 -> V_71 . V_84 =
V_91 ;
break;
case V_92 :
V_7 -> V_71 . V_84 =
V_93 ;
break;
case V_94 :
V_7 -> V_71 . V_84 =
V_95 ;
break;
case V_96 :
V_7 -> V_71 . V_84 =
V_97 ;
break;
case V_98 :
V_7 -> V_71 . V_84 =
V_99 ;
break;
case V_100 :
break;
case V_101 :
V_7 -> V_71 . V_84 =
V_102 ;
break;
case V_103 :
V_7 -> V_71 . V_84 =
V_104 ;
break;
case V_105 :
V_7 -> V_71 . V_84 =
V_106 ;
break;
default:
V_7 -> V_71 . V_84 =
V_107 ;
break;
}
F_14 ( & V_57 -> V_34 , L_12 ,
V_7 -> V_71 . V_84 ) ;
switch ( V_7 -> V_71 . V_84 ) {
case V_107 :
case V_85 :
case V_87 :
V_7 -> V_108 . V_109 = V_110 ;
V_7 -> V_108 . V_111 = true ;
break;
case V_89 :
V_7 -> V_108 . V_109 = V_112 ;
V_7 -> V_108 . V_111 = true ;
break;
case V_91 :
case V_93 :
V_7 -> V_108 . V_109 = V_113 ;
V_7 -> V_108 . V_111 = true ;
break;
case V_95 :
V_7 -> V_108 . V_109 = V_114 ;
V_7 -> V_108 . V_111 = true ;
break;
case V_97 :
V_7 -> V_108 . V_109 = V_115 ;
V_7 -> V_108 . V_111 = true ;
break;
case V_99 :
V_7 -> V_108 . V_109 = V_116 ;
V_7 -> V_108 . V_111 = true ;
break;
default:
V_7 -> V_108 . V_109 = V_117 ;
V_7 -> V_108 . V_111 = false ;
break;
}
} else {
V_68 = false ;
}
if ( ( ( V_66 [ 0 ] == 0xff ) && ( V_66 [ 1 ] == 0xff ) &&
( V_66 [ 2 ] == 0xff ) && ( V_66 [ 3 ] == 0xff ) &&
( V_66 [ 4 ] == 0xff ) && ( V_66 [ 5 ] == 0xff ) ) ||
( ( V_66 [ 0 ] == 0x00 ) && ( V_66 [ 1 ] == 0x00 ) &&
( V_66 [ 2 ] == 0x00 ) && ( V_66 [ 3 ] == 0x00 ) &&
( V_66 [ 4 ] == 0x00 ) && ( V_66 [ 5 ] == 0x00 ) ) ||
( ! V_68 ) ) {
V_66 [ 0 ] = 0x00 ;
V_66 [ 1 ] = 0xe0 ;
V_66 [ 2 ] = 0x4c ;
V_66 [ 3 ] = 0x87 ;
V_66 [ 4 ] = 0x00 ;
V_66 [ 5 ] = 0x00 ;
}
if ( V_82 ) {
V_66 [ 0 ] &= 0xFE ;
F_14 ( & V_57 -> V_34 ,
L_13 , V_66 ) ;
} else
F_14 ( & V_57 -> V_34 ,
L_14 , V_66 ) ;
F_37 ( V_5 -> V_118 , V_66 ) ;
}
if ( F_38 ( V_7 ) )
goto error;
F_39 ( & V_7 -> V_119 ) ;
F_40 ( & V_7 -> V_120 ) ;
return 0 ;
error:
F_41 ( V_57 ) ;
F_27 ( V_2 , NULL ) ;
if ( V_7 && V_7 -> V_41 != NULL )
V_7 -> V_41 ( V_7 ) ;
if ( V_5 )
F_42 ( V_5 ) ;
return - V_121 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_22 * V_57 = F_24 ( V_2 ) ;
if ( V_5 ) {
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_27 ( V_2 , NULL ) ;
F_44 ( V_7 -> V_122 ) ;
F_45 ( & V_7 -> V_123 ) ;
if ( V_124 . V_125 )
V_7 -> V_36 = true ;
F_46 ( V_5 ) ;
F_47 () ;
F_48 ( 1 ) ;
F_49 ( V_7 ) ;
F_18 ( V_7 ) ;
F_50 ( V_7 ) ;
F_41 ( V_57 ) ;
}
if ( V_57 -> V_3 != V_126 )
F_51 ( V_57 ) ;
}
static int T_6 F_52 ( void )
{
V_124 . V_125 = true ;
return F_53 ( & V_124 . V_127 ) ;
}
static void T_7 F_54 ( void )
{
V_124 . V_125 = false ;
F_55 ( & V_124 . V_127 ) ;
}
