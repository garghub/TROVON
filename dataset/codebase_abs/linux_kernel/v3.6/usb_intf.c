static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_6 L_1 ) ;
if ( ! V_5 || ! F_4 ( V_5 ) ) {
F_3 ( V_6 L_2 ) ;
return 0 ;
}
if ( V_5 -> V_7 -> V_8 )
V_5 -> V_7 -> V_8 ( V_5 ) ;
F_5 ( 10 ) ;
F_6 ( V_5 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_6 L_3 ) ;
if ( ! V_5 || ! F_4 ( V_5 ) ) {
F_3 ( V_6 L_4 ) ;
return 0 ;
}
F_8 ( V_5 ) ;
if ( V_5 -> V_7 -> V_9 )
V_5 -> V_7 -> V_9 ( V_5 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return 0 ;
}
static T_2 F_10 ( struct V_10 * V_11 )
{
T_2 V_12 = V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 = & V_11 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 ;
V_25 -> V_11 = V_11 ;
V_11 -> V_30 = 6 ;
V_15 = & V_28 -> V_31 ;
V_17 = V_28 -> V_32 ;
V_19 = & V_17 -> V_33 ;
V_21 = & V_34 -> V_35 [ 0 ] ;
V_23 = & V_21 -> V_33 ;
V_25 -> V_36 = V_23 -> V_37 ;
if ( V_28 -> V_38 == V_39 ) {
V_25 -> V_40 = true ;
F_3 ( V_6 L_5 ,
V_25 -> V_36 ) ;
} else {
V_25 -> V_40 = false ;
F_3 ( V_6 L_6 ,
V_25 -> V_36 ) ;
}
if ( ( F_11 ( V_11 ) ) == V_41 )
V_12 = V_41 ;
return V_12 ;
}
static void F_12 ( struct V_10 * V_11 )
{
}
void F_13 ( struct V_10 * V_11 )
{
if ( V_11 -> V_42 == false ) {
}
if ( V_11 -> V_26 . V_43 != NULL )
V_11 -> V_26 . V_43 ( V_11 ) ;
F_14 ( V_11 ) ;
}
void F_15 ( struct V_10 * V_11 )
{
if ( V_11 -> V_44 == true ) {
V_11 -> V_45 = true ;
F_13 ( V_11 ) ;
F_16 ( V_11 ) ;
if ( V_11 -> V_42 == false ) {
V_11 -> V_46 = false ;
F_17 ( V_11 ) ;
}
if ( V_11 -> V_47 )
V_11 -> V_47 ( V_11 ) ;
V_11 -> V_44 = false ;
}
}
static void F_18 ( const struct V_48 * V_49 ,
struct V_10 * V_11 )
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
V_11 -> V_60 . V_61 = 0 ;
V_11 -> V_60 . V_62 = 0 ;
V_11 -> V_60 . V_63 = 0 ;
}
}
}
static T_5 F_19 ( T_5 V_64 , T_5 V_65 )
{
return ( F_20 ( V_64 ) << 4 ) | F_20 ( V_65 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_48 * V_49 )
{
T_2 V_12 ;
struct V_10 * V_11 = NULL ;
struct V_24 * V_25 ;
struct V_4 * V_5 ;
struct V_27 * V_66 ;
F_3 ( V_6 L_7 ) ;
V_66 = F_22 ( V_2 ) ;
F_23 ( V_66 ) ;
V_34 = V_2 ;
V_5 = F_24 () ;
if ( ! V_5 )
goto error;
V_11 = F_25 ( V_5 ) ;
F_18 ( V_49 , V_11 ) ;
V_25 = & V_11 -> V_26 ;
V_25 -> V_11 = V_11 ;
V_11 -> V_26 . V_29 = V_66 ;
V_11 -> V_2 = V_2 ;
F_26 ( V_2 , V_5 ) ;
F_27 ( V_5 , & V_2 -> V_67 ) ;
V_11 -> V_68 = & F_10 ;
V_11 -> V_47 = & F_12 ;
V_11 -> V_69 . V_70 = & V_71 ;
V_11 -> V_26 . V_72 = & V_73 ;
V_11 -> V_26 . V_43 = & V_74 ;
if ( V_11 -> V_68 == NULL )
goto error;
else {
V_12 = V_11 -> V_68 ( V_11 ) ;
if ( V_12 != V_13 )
goto error;
}
V_12 = F_28 ( V_11 ) ;
if ( V_12 == V_41 )
goto error;
{
int V_53 , V_75 ;
T_5 V_76 [ 6 ] ;
T_5 V_77 , V_78 , V_79 ;
T_5 * V_80 = V_11 -> V_81 . V_82 ;
V_77 = F_29 ( V_11 , V_83 ) ;
F_3 ( V_6 L_8 ,
( V_77 & V_84 ) ? L_9 : L_10 ,
( V_77 & V_85 ) ? L_11 : L_12 ) ;
if ( V_77 & V_85 ) {
V_78 = true ;
V_77 = F_29 ( V_11 , V_86 + 3 ) ;
F_30 ( V_11 , V_86 + 3 , V_77 | 0x80 ) ;
F_31 ( 20 ) ;
F_30 ( V_11 , V_86 + 3 ,
( V_77 & ( ~ F_32 ( 7 ) ) ) ) ;
V_77 = ( T_5 ) ( ( F_33 ( V_11 , V_87 ) >> 15 ) &
0x1F ) ;
if ( V_77 == 0x3 )
V_11 -> V_60 . V_88 =
V_89 ;
else
V_11 -> V_60 . V_88 =
( V_77 >> 1 ) + 1 ;
switch ( V_11 -> V_60 . V_88 ) {
case V_90 :
case V_91 :
case V_89 :
break;
default:
V_11 -> V_60 . V_88 =
V_91 ;
break;
}
for ( V_53 = 0 , V_75 = 0 ; V_53 < 128 ; V_53 += 8 , V_75 ++ )
F_34 ( V_11 , V_75 ,
& V_80 [ V_53 ] ) ;
if ( V_92 ) {
int V_93 , V_94 ;
for ( V_93 = 0 , V_94 = 0 ; V_93 < V_95 ;
V_93 ++ , V_94 += 3 )
V_76 [ V_93 ] =
F_19 ( V_92 [ V_94 ] ,
V_92 [ V_94 + 1 ] ) ;
} else {
memcpy ( V_76 , & V_80 [ 0x12 ] , V_95 ) ;
}
V_79 = V_80 [ 0x52 ] ;
switch ( V_79 ) {
case V_96 :
V_11 -> V_81 . V_97 =
V_98 ;
break;
case V_99 :
V_11 -> V_81 . V_97 =
V_100 ;
break;
case V_101 :
V_11 -> V_81 . V_97 =
V_102 ;
break;
case V_103 :
V_11 -> V_81 . V_97 =
V_104 ;
break;
case V_105 :
V_11 -> V_81 . V_97 =
V_106 ;
break;
case V_107 :
V_11 -> V_81 . V_97 =
V_108 ;
break;
case V_109 :
V_11 -> V_81 . V_97 =
V_110 ;
break;
case V_111 :
V_11 -> V_81 . V_97 =
V_112 ;
break;
case V_113 :
break;
case V_114 :
V_11 -> V_81 . V_97 =
V_115 ;
break;
case V_116 :
V_11 -> V_81 . V_97 =
V_117 ;
break;
case V_118 :
V_11 -> V_81 . V_97 =
V_119 ;
break;
default:
V_11 -> V_81 . V_97 =
V_120 ;
break;
}
F_3 ( V_6 L_13 ,
V_11 -> V_81 . V_97 ) ;
switch ( V_11 -> V_81 . V_97 ) {
case V_120 :
case V_98 :
case V_100 :
V_11 -> V_121 . V_122 = V_123 ;
V_11 -> V_121 . V_124 = true ;
break;
case V_102 :
V_11 -> V_121 . V_122 = V_125 ;
V_11 -> V_121 . V_124 = true ;
break;
case V_104 :
case V_106 :
V_11 -> V_121 . V_122 = V_126 ;
V_11 -> V_121 . V_124 = true ;
break;
case V_108 :
V_11 -> V_121 . V_122 = V_127 ;
V_11 -> V_121 . V_124 = true ;
break;
case V_110 :
V_11 -> V_121 . V_122 = V_128 ;
V_11 -> V_121 . V_124 = true ;
break;
case V_112 :
V_11 -> V_121 . V_122 = V_129 ;
V_11 -> V_121 . V_124 = true ;
break;
default:
V_11 -> V_121 . V_122 = V_130 ;
V_11 -> V_121 . V_124 = false ;
break;
}
} else
V_78 = false ;
if ( ( ( V_76 [ 0 ] == 0xff ) && ( V_76 [ 1 ] == 0xff ) &&
( V_76 [ 2 ] == 0xff ) && ( V_76 [ 3 ] == 0xff ) &&
( V_76 [ 4 ] == 0xff ) && ( V_76 [ 5 ] == 0xff ) ) ||
( ( V_76 [ 0 ] == 0x00 ) && ( V_76 [ 1 ] == 0x00 ) &&
( V_76 [ 2 ] == 0x00 ) && ( V_76 [ 3 ] == 0x00 ) &&
( V_76 [ 4 ] == 0x00 ) && ( V_76 [ 5 ] == 0x00 ) ) ||
( V_78 == false ) ) {
V_76 [ 0 ] = 0x00 ;
V_76 [ 1 ] = 0xe0 ;
V_76 [ 2 ] = 0x4c ;
V_76 [ 3 ] = 0x87 ;
V_76 [ 4 ] = 0x00 ;
V_76 [ 5 ] = 0x00 ;
}
if ( V_92 ) {
V_76 [ 0 ] &= 0xFE ;
F_3 ( V_6 L_14
L_15 , V_76 ) ;
} else
F_3 ( V_6 L_16
L_15 , V_76 ) ;
memcpy ( V_5 -> V_131 , V_76 , V_95 ) ;
}
if ( F_35 ( V_11 ) )
goto error;
F_36 ( & V_11 -> V_132 ) ;
F_37 ( & V_11 -> V_133 ) ;
return 0 ;
error:
F_38 ( V_66 ) ;
F_26 ( V_2 , NULL ) ;
if ( V_11 -> V_47 != NULL )
V_11 -> V_47 ( V_11 ) ;
if ( V_5 )
F_39 ( V_5 ) ;
return - V_134 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_25 ( V_5 ) ;
struct V_27 * V_66 = F_22 ( V_2 ) ;
F_26 ( V_2 , NULL ) ;
if ( V_11 -> V_135 )
F_41 ( V_11 -> V_136 ) ;
F_42 ( & V_11 -> V_137 ) ;
if ( V_138 . V_139 == true )
V_11 -> V_42 = true ;
if ( V_5 != NULL ) {
F_43 ( V_5 ) ;
}
F_44 () ;
F_45 ( 1 ) ;
if ( V_11 -> V_135 )
F_46 ( V_11 ) ;
F_15 ( V_11 ) ;
F_47 ( V_11 ) ;
F_26 ( V_2 , NULL ) ;
F_38 ( V_66 ) ;
if ( V_66 -> V_3 != V_140 )
F_48 ( V_66 ) ;
return;
}
static int T_6 F_49 ( void )
{
V_138 . V_139 = true ;
return F_50 ( & V_138 . V_141 ) ;
}
static void T_7 F_51 ( void )
{
V_138 . V_139 = false ;
F_52 ( & V_138 . V_141 ) ;
F_3 ( V_6 L_17 ) ;
}
