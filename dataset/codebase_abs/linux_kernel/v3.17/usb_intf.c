static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_5 , L_1 ) ;
if ( ! V_5 || ! F_4 ( V_5 ) ) {
F_3 ( V_5 , L_2 ) ;
return 0 ;
}
if ( V_5 -> V_6 -> V_7 )
V_5 -> V_6 -> V_7 ( V_5 ) ;
F_5 ( 10 ) ;
F_6 ( V_5 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_5 , L_3 ) ;
if ( ! V_5 || ! F_4 ( V_5 ) ) {
F_3 ( V_5 , L_4 ) ;
return 0 ;
}
F_8 ( V_5 ) ;
if ( V_5 -> V_6 -> V_8 )
V_5 -> V_6 -> V_8 ( V_5 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return 0 ;
}
static T_2 F_10 ( struct V_9 * V_10 )
{
T_2 V_11 = V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 = & V_10 -> V_25 ;
struct V_26 * V_27 = V_24 -> V_28 ;
V_24 -> V_10 = V_10 ;
V_10 -> V_29 = 6 ;
V_14 = & V_27 -> V_30 ;
V_16 = V_27 -> V_31 ;
V_18 = & V_16 -> V_32 ;
V_20 = & V_33 -> V_34 [ 0 ] ;
V_22 = & V_20 -> V_32 ;
V_24 -> V_35 = V_22 -> V_36 ;
if ( V_27 -> V_37 == V_38 ) {
V_24 -> V_39 = true ;
F_11 ( & V_27 -> V_40 , L_5 ,
V_24 -> V_35 ) ;
} else {
V_24 -> V_39 = false ;
F_11 ( & V_27 -> V_40 , L_6 ,
V_24 -> V_35 ) ;
}
if ( ( F_12 ( V_10 ) ) == V_41 )
V_11 = V_41 ;
return V_11 ;
}
static void F_13 ( struct V_9 * V_10 )
{
}
void F_14 ( struct V_9 * V_10 )
{
if ( V_10 -> V_42 == false ) {
}
if ( V_10 -> V_25 . V_43 != NULL )
V_10 -> V_25 . V_43 ( V_10 ) ;
F_15 ( V_10 ) ;
}
void F_16 ( struct V_9 * V_10 )
{
if ( V_10 -> V_44 == true ) {
V_10 -> V_45 = true ;
F_14 ( V_10 ) ;
F_17 ( V_10 ) ;
if ( V_10 -> V_42 == false ) {
V_10 -> V_46 = false ;
F_18 ( V_10 ) ;
}
if ( V_10 -> V_47 )
V_10 -> V_47 ( V_10 ) ;
V_10 -> V_44 = false ;
}
}
static void F_19 ( const struct V_48 * V_49 ,
struct V_9 * V_10 )
{
T_3 V_50 , V_51 ;
T_4 V_52 ;
int V_53 ;
int V_54 = sizeof( V_55 ) /
sizeof( struct V_56 ) ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
V_50 = V_55 [ V_53 ] . V_57 ;
V_51 = V_55 [ V_53 ] . V_58 ;
V_52 = V_55 [ V_53 ] . V_52 ;
if ( ( V_49 -> V_57 == V_50 ) && ( V_49 -> V_58 == V_51 ) &&
( V_52 & V_59 ) ) {
V_10 -> V_60 . V_61 = 0 ;
V_10 -> V_60 . V_62 = 0 ;
V_10 -> V_60 . V_63 = 0 ;
}
}
}
static int F_20 ( struct V_1 * V_2 ,
const struct V_48 * V_49 )
{
T_2 V_11 ;
struct V_9 * V_10 = NULL ;
struct V_23 * V_24 ;
struct V_4 * V_5 ;
struct V_26 * V_64 ;
F_21 ( V_65 L_7 ) ;
V_64 = F_22 ( V_2 ) ;
F_23 ( V_64 ) ;
V_33 = V_2 ;
V_5 = F_24 () ;
if ( ! V_5 )
goto error;
V_10 = F_25 ( V_5 ) ;
F_19 ( V_49 , V_10 ) ;
V_24 = & V_10 -> V_25 ;
V_24 -> V_10 = V_10 ;
V_10 -> V_25 . V_28 = V_64 ;
V_10 -> V_2 = V_2 ;
F_26 ( V_2 , V_5 ) ;
F_27 ( V_5 , & V_2 -> V_40 ) ;
V_5 -> V_40 . type = & V_66 ;
V_10 -> V_67 = & F_10 ;
V_10 -> V_47 = & F_13 ;
V_10 -> V_68 . V_69 = & V_70 ;
V_10 -> V_25 . V_71 = & V_72 ;
V_10 -> V_25 . V_43 = & V_73 ;
if ( V_10 -> V_67 == NULL )
goto error;
else {
V_11 = V_10 -> V_67 ( V_10 ) ;
if ( V_11 != V_12 )
goto error;
}
V_11 = F_28 ( V_10 ) ;
if ( V_11 == V_41 )
goto error;
{
int V_53 , V_74 ;
T_5 V_75 [ 6 ] ;
T_5 V_76 , V_77 , V_78 ;
T_5 * V_79 = V_10 -> V_80 . V_81 ;
V_76 = F_29 ( V_10 , V_82 ) ;
F_11 ( & V_64 -> V_40 , L_8 ,
( V_76 & V_83 ) ? L_9 : L_10 ,
( V_76 & V_84 ) ? L_11 : L_12 ) ;
if ( V_76 & V_84 ) {
V_77 = true ;
V_76 = F_29 ( V_10 , V_85 + 3 ) ;
F_30 ( V_10 , V_85 + 3 , V_76 | 0x80 ) ;
F_31 ( 20 ) ;
F_30 ( V_10 , V_85 + 3 ,
( V_76 & ( ~ F_32 ( 7 ) ) ) ) ;
V_76 = ( T_5 ) ( ( F_33 ( V_10 , V_86 ) >> 15 ) &
0x1F ) ;
if ( V_76 == 0x3 )
V_10 -> V_60 . V_87 =
V_88 ;
else
V_10 -> V_60 . V_87 =
( V_76 >> 1 ) + 1 ;
switch ( V_10 -> V_60 . V_87 ) {
case V_89 :
case V_90 :
case V_88 :
break;
default:
V_10 -> V_60 . V_87 =
V_90 ;
break;
}
for ( V_53 = 0 , V_74 = 0 ; V_53 < 128 ; V_53 += 8 , V_74 ++ )
F_34 ( V_10 , V_74 ,
& V_79 [ V_53 ] ) ;
if ( ! V_91 || ! F_35 ( V_91 , V_75 ) ) {
memcpy ( V_75 , & V_79 [ 0x12 ] , V_92 ) ;
}
V_78 = V_79 [ 0x52 ] ;
switch ( V_78 ) {
case V_93 :
V_10 -> V_80 . V_94 =
V_95 ;
break;
case V_96 :
V_10 -> V_80 . V_94 =
V_97 ;
break;
case V_98 :
V_10 -> V_80 . V_94 =
V_99 ;
break;
case V_100 :
V_10 -> V_80 . V_94 =
V_101 ;
break;
case V_102 :
V_10 -> V_80 . V_94 =
V_103 ;
break;
case V_104 :
V_10 -> V_80 . V_94 =
V_105 ;
break;
case V_106 :
V_10 -> V_80 . V_94 =
V_107 ;
break;
case V_108 :
V_10 -> V_80 . V_94 =
V_109 ;
break;
case V_110 :
break;
case V_111 :
V_10 -> V_80 . V_94 =
V_112 ;
break;
case V_113 :
V_10 -> V_80 . V_94 =
V_114 ;
break;
case V_115 :
V_10 -> V_80 . V_94 =
V_116 ;
break;
default:
V_10 -> V_80 . V_94 =
V_117 ;
break;
}
F_11 ( & V_64 -> V_40 , L_13 ,
V_10 -> V_80 . V_94 ) ;
switch ( V_10 -> V_80 . V_94 ) {
case V_117 :
case V_95 :
case V_97 :
V_10 -> V_118 . V_119 = V_120 ;
V_10 -> V_118 . V_121 = true ;
break;
case V_99 :
V_10 -> V_118 . V_119 = V_122 ;
V_10 -> V_118 . V_121 = true ;
break;
case V_101 :
case V_103 :
V_10 -> V_118 . V_119 = V_123 ;
V_10 -> V_118 . V_121 = true ;
break;
case V_105 :
V_10 -> V_118 . V_119 = V_124 ;
V_10 -> V_118 . V_121 = true ;
break;
case V_107 :
V_10 -> V_118 . V_119 = V_125 ;
V_10 -> V_118 . V_121 = true ;
break;
case V_109 :
V_10 -> V_118 . V_119 = V_126 ;
V_10 -> V_118 . V_121 = true ;
break;
default:
V_10 -> V_118 . V_119 = V_127 ;
V_10 -> V_118 . V_121 = false ;
break;
}
} else
V_77 = false ;
if ( ( ( V_75 [ 0 ] == 0xff ) && ( V_75 [ 1 ] == 0xff ) &&
( V_75 [ 2 ] == 0xff ) && ( V_75 [ 3 ] == 0xff ) &&
( V_75 [ 4 ] == 0xff ) && ( V_75 [ 5 ] == 0xff ) ) ||
( ( V_75 [ 0 ] == 0x00 ) && ( V_75 [ 1 ] == 0x00 ) &&
( V_75 [ 2 ] == 0x00 ) && ( V_75 [ 3 ] == 0x00 ) &&
( V_75 [ 4 ] == 0x00 ) && ( V_75 [ 5 ] == 0x00 ) ) ||
( V_77 == false ) ) {
V_75 [ 0 ] = 0x00 ;
V_75 [ 1 ] = 0xe0 ;
V_75 [ 2 ] = 0x4c ;
V_75 [ 3 ] = 0x87 ;
V_75 [ 4 ] = 0x00 ;
V_75 [ 5 ] = 0x00 ;
}
if ( V_91 ) {
V_75 [ 0 ] &= 0xFE ;
F_11 ( & V_64 -> V_40 , L_14 , V_75 ) ;
} else
F_11 ( & V_64 -> V_40 , L_15 , V_75 ) ;
memcpy ( V_5 -> V_128 , V_75 , V_92 ) ;
}
if ( F_36 ( V_10 ) )
goto error;
F_37 ( & V_10 -> V_129 ) ;
F_38 ( & V_10 -> V_130 ) ;
return 0 ;
error:
F_39 ( V_64 ) ;
F_26 ( V_2 , NULL ) ;
if ( V_10 && V_10 -> V_47 != NULL )
V_10 -> V_47 ( V_10 ) ;
if ( V_5 )
F_40 ( V_5 ) ;
return - V_131 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_26 * V_64 = F_22 ( V_2 ) ;
if ( V_5 ) {
struct V_9 * V_10 = F_25 ( V_5 ) ;
F_26 ( V_2 , NULL ) ;
F_42 ( V_10 -> V_132 ) ;
F_43 ( & V_10 -> V_133 ) ;
if ( V_134 . V_135 == true )
V_10 -> V_42 = true ;
F_44 ( V_5 ) ;
F_45 () ;
F_46 ( 1 ) ;
F_47 ( V_10 ) ;
F_16 ( V_10 ) ;
F_48 ( V_10 ) ;
F_39 ( V_64 ) ;
}
if ( V_64 -> V_3 != V_136 )
F_49 ( V_64 ) ;
return;
}
static int T_6 F_50 ( void )
{
V_134 . V_135 = true ;
return F_51 ( & V_134 . V_137 ) ;
}
static void T_7 F_52 ( void )
{
V_134 . V_135 = false ;
F_53 ( & V_134 . V_137 ) ;
}
