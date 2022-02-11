static int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 , int V_5 , void * V_6 , int V_7 , int V_8 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 5000 ;
if ( V_8 ) {
return F_2 ( V_10 -> V_13 ,
F_3 ( V_10 -> V_13 , 0 ) , V_3 ,
V_14 | V_15 | V_16 ,
V_4 , V_5 , V_6 , V_7 , V_12 ) ;
} else {
return F_2 ( V_10 -> V_13 ,
F_4 ( V_10 -> V_13 , 0 ) , V_3 ,
V_14 | V_15 ,
V_4 , V_5 , V_6 , V_7 , V_12 ) ;
}
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_1 V_17 , V_18 ;
if ( V_2 -> V_19 == V_20 )
return - 1 ;
if ( F_6 ( V_2 , 0x0001 , 0x0001 ) < 0 )
return - 1 ;
F_7 ( 100 ) ;
if ( V_10 -> V_21 -> V_22 & V_23 ) {
F_8 ( L_1 ) ;
if ( F_1 ( V_2 , 0x10 , 0 , 0 , NULL , 0 , 0 ) < 0 ||
F_1 ( V_2 , 0x10 , 0 , 0 , NULL , 0 , 0 ) < 0 )
return - 1 ;
if ( F_6 ( V_2 , 0x0001 , 0x0001 ) < 0 )
return - 1 ;
F_7 ( 100 ) ;
}
if ( F_9 ( V_2 , & V_17 , & V_18 ) < 0 ||
( V_17 & ~ 0x1 ) != 0x55aa ) {
F_10 ( V_2 -> V_24 , L_2 ) ;
return - 1 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_25 , int V_26 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_27 , V_28 ;
T_1 V_29 = 0 ;
int V_12 = 500 ;
F_8 ( L_3 , V_25 , V_26 ) ;
for ( V_27 = 0 ; V_27 < 100 ; ++ V_27 ) {
V_28 = F_2 ( V_10 -> V_13 ,
F_3 ( V_10 -> V_13 , 0 ) , 0x14 ,
V_14 | V_15 | V_16 ,
0 , V_30 , V_2 -> V_31 ,
sizeof( V_29 ) , V_12 ) ;
if ( V_28 < 0 )
break;
V_29 = F_12 ( * ( ( V_32 * ) V_2 -> V_31 ) ) ;
if ( ! ( V_29 & 0x0010 ) )
break;
F_7 ( 10 ) ;
}
if ( V_28 < 0 )
goto V_33;
if ( V_27 == 100 ) {
F_10 ( V_2 -> V_24 , L_4 , V_29 ) ;
return - 1 ;
}
V_28 = F_2 ( V_10 -> V_13 , F_4 ( V_10 -> V_13 , 0 ) , 0x12 ,
V_14 | V_15 , V_26 ,
V_34 , NULL , 0 , V_12 ) ;
if ( V_28 < 0 )
goto V_33;
V_28 = F_2 ( V_10 -> V_13 , F_4 ( V_10 -> V_13 , 0 ) ,
0x12 , V_14 | V_15 , V_25 ,
V_35 , NULL , 0 , V_12 ) ;
if ( V_28 < 0 )
goto V_33;
return 0 ;
V_33:
F_10 ( V_2 -> V_24 , L_5 , V_28 ) ;
return V_28 ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_25 , int V_26 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_28 ;
int V_12 = 500 ;
F_8 ( L_3 , V_25 , V_26 ) ;
V_2 -> V_31 [ 0 ] = V_26 & 0xff ;
V_2 -> V_31 [ 1 ] = V_26 >> 8 ;
V_2 -> V_31 [ 2 ] = V_25 & 0xff ;
V_2 -> V_31 [ 3 ] = V_25 >> 8 ;
V_2 -> V_31 [ 4 ] = V_2 -> V_31 [ 5 ] = V_2 -> V_31 [ 6 ] = V_2 -> V_31 [ 7 ] = 0 ;
V_28 = F_2 ( V_10 -> V_13 , F_4 ( V_10 -> V_13 , 2 ) , 0x00 ,
V_14 | V_36 , 0x55aa ,
0xf0f0 , V_2 -> V_31 , 8 , V_12 ) ;
if ( V_28 < 0 ) {
F_10 ( V_2 -> V_24 , L_5 , V_28 ) ;
return V_28 ;
}
return 0 ;
}
static void F_14 ( struct V_37 * V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 -> V_38 ;
V_32 * V_39 = ( V_32 * ) V_37 -> V_6 ;
int V_19 = V_37 -> V_19 ;
if ( V_19 ) {
if ( V_19 != - V_40 &&
V_2 -> V_19 != V_20 ) {
F_10 ( V_2 -> V_24 , L_6 , V_37 -> V_19 ) ;
} else {
F_15 ( & V_2 -> V_41 ) ;
return;
}
} else if ( V_37 -> V_42 != V_37 -> V_43 ) {
F_10 ( V_2 -> V_24 , L_7 ) ;
} else {
V_2 -> V_44 = 1 ;
V_2 -> V_45 = F_16 ( V_39 [ 0 ] ) ;
V_2 -> V_46 = F_16 ( V_39 [ 1 ] ) ;
F_8 ( L_8 ,
V_2 -> V_46 , V_2 -> V_45 ) ;
}
F_15 ( & V_2 -> V_41 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_28 ;
V_28 = F_18 ( V_10 -> V_47 , V_48 ) ;
if ( V_28 < 0 ) {
F_10 ( V_2 -> V_24 , L_9 , V_28 ) ;
return V_28 ;
}
return 0 ;
}
static void F_19 ( struct V_37 * V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 -> V_38 ;
int V_28 , V_19 = V_37 -> V_19 ;
if ( ! F_20 ( & V_2 -> V_49 ) ) {
F_21 ( & V_2 -> V_50 ) ;
return;
}
if ( V_19 ) {
F_10 ( V_2 -> V_24 , L_10 , V_19 ) ;
return;
}
if ( V_37 -> V_42 != V_37 -> V_43 ) {
F_10 ( V_2 -> V_24 , L_11 ) ;
return;
}
F_22 ( V_2 , V_37 -> V_6 , V_37 -> V_42 ) ;
V_28 = F_18 ( V_37 , V_51 ) ;
if ( V_28 < 0 )
F_10 ( V_2 -> V_24 , L_10 , V_28 ) ;
}
static void F_23 ( struct V_37 * V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 -> V_38 ;
int V_28 , V_19 = V_37 -> V_19 ;
if ( ! F_20 ( & V_2 -> V_49 ) )
return;
if ( V_19 ) {
F_10 ( V_2 -> V_24 , L_12 ,
V_19 ) ;
return;
}
if ( V_37 -> V_42 != V_37 -> V_43 ) {
F_10 ( V_2 -> V_24 , L_13 ) ;
return;
}
if ( V_2 -> V_52 != NULL )
V_2 -> V_52 ( V_2 , V_37 -> V_6 , V_37 -> V_42 ) ;
V_28 = F_18 ( V_37 , V_51 ) ;
if ( V_28 < 0 )
F_10 ( V_2 -> V_24 , L_12 , V_28 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_27 , V_28 ;
for ( V_27 = 0 ; V_27 < 8 ; ++ V_27 ) {
V_28 = F_18 ( V_10 -> V_53 [ V_27 ] , V_48 ) ;
if ( V_28 < 0 ) {
F_10 ( V_2 -> V_24 , L_14 , V_27 , V_28 ) ;
goto V_54;
}
}
if ( ! V_2 -> V_55 )
return 0 ;
for ( V_27 = 0 ; V_27 < 8 ; ++ V_27 ) {
V_28 = F_18 ( V_10 -> V_56 [ V_27 ] , V_48 ) ;
if ( V_28 < 0 ) {
F_10 ( V_2 -> V_24 , L_15 , V_27 , V_28 ) ;
goto V_57;
}
}
return 0 ;
V_57:
for ( V_27 = 0 ; V_27 < 7 ; ++ V_27 )
F_25 ( V_10 -> V_56 [ V_27 ] ) ;
V_54:
for ( V_27 = 0 ; V_27 < 8 ; ++ V_27 )
F_25 ( V_10 -> V_53 [ V_27 ] ) ;
return - 1 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_27 ;
if ( V_2 -> V_19 == V_20 )
return 0 ;
for ( V_27 = 0 ; V_27 < 8 ; ++ V_27 )
F_25 ( V_10 -> V_53 [ V_27 ] ) ;
if ( V_2 -> V_55 )
for ( V_27 = 0 ; V_27 < 8 ; ++ V_27 )
F_25 ( V_10 -> V_56 [ V_27 ] ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , T_2 * V_26 , int V_58 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_59 , V_60 ;
int V_12 = 500 ;
F_8 ( L_16 , V_58 ) ;
if ( V_10 -> V_21 -> V_22 & V_23 )
V_60 = F_28 ( V_10 -> V_13 , 2 ) ;
else
V_60 = F_28 ( V_10 -> V_13 , 3 ) ;
return F_29 ( V_10 -> V_13 , V_60 , V_26 , V_58 ,
& V_59 , V_12 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_37 * V_61 , * V_62 ;
int V_27 ;
if ( V_10 -> V_47 ) {
F_25 ( V_10 -> V_47 ) ;
F_31 ( V_10 -> V_47 -> V_6 ) ;
F_32 ( V_10 -> V_47 ) ;
}
for ( V_27 = 0 ; V_27 < 8 ; ++ V_27 ) {
V_61 = V_10 -> V_53 [ V_27 ] ;
if ( V_61 ) {
F_25 ( V_61 ) ;
F_31 ( V_61 -> V_6 ) ;
F_32 ( V_61 ) ;
}
V_62 = V_10 -> V_56 [ V_27 ] ;
if ( V_62 ) {
F_25 ( V_62 ) ;
F_31 ( V_62 -> V_6 ) ;
F_32 ( V_62 ) ;
}
}
F_31 ( V_2 -> V_11 ) ;
}
static int F_33 ( struct V_63 * V_64 ,
struct V_65 V_66 [] , int V_67 )
{
struct V_1 * V_2 = F_34 ( V_64 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
T_2 * V_68 = V_2 -> V_31 ;
int V_69 , V_27 ;
int V_70 = - V_71 ;
if ( V_2 -> V_19 == V_20 )
return - V_72 ;
F_35 ( & V_10 -> V_73 ) ;
for ( V_27 = 0 ; V_27 < V_67 ; ++ V_27 ) {
if ( V_27 + 1 < V_67 && V_66 [ V_27 ] . V_25 == V_66 [ V_27 + 1 ] . V_25 &&
! ( V_66 [ V_27 ] . V_22 & V_74 ) &&
( V_66 [ V_27 + 1 ] . V_22 & V_74 ) ) {
#ifdef F_36
F_8 ( L_17 ,
V_66 [ V_27 ] . V_58 , V_66 [ V_27 + 1 ] . V_58 , V_66 [ V_27 ] . V_25 ) ;
#endif
V_68 [ 0 ] = 0x01 ;
V_68 [ 1 ] = V_66 [ V_27 ] . V_58 + 1 ;
V_68 [ 2 ] = V_66 [ V_27 ] . V_25 << 1 ;
memcpy ( & V_68 [ 3 ] , V_66 [ V_27 ] . V_68 , V_66 [ V_27 ] . V_58 ) ;
V_69 = V_66 [ V_27 ] . V_58 + 3 ;
V_68 [ V_69 ++ ] = V_66 [ ++ V_27 ] . V_58 ;
} else if ( V_66 [ V_27 ] . V_22 & V_74 ) {
#ifdef F_36
F_8 ( L_18 ,
V_66 [ V_27 ] . V_58 , V_66 [ V_27 ] . V_25 ) ;
#endif
V_68 [ 0 ] = 0x01 ;
V_68 [ 1 ] = 1 ;
V_68 [ 2 ] = V_66 [ V_27 ] . V_25 << 1 ;
V_68 [ 3 ] = V_66 [ V_27 ] . V_58 ;
V_69 = 4 ;
} else {
#ifdef F_36
F_8 ( L_19 ,
V_66 [ V_27 ] . V_58 , V_66 [ V_27 ] . V_25 ) ;
#endif
V_68 [ 0 ] = 0x00 ;
V_68 [ 1 ] = V_66 [ V_27 ] . V_58 + 1 ;
V_68 [ 2 ] = V_66 [ V_27 ] . V_25 << 1 ;
memcpy ( & V_68 [ 3 ] , V_66 [ V_27 ] . V_68 , V_66 [ V_27 ] . V_58 ) ;
V_69 = V_66 [ V_27 ] . V_58 + 3 ;
V_68 [ V_69 ++ ] = 0 ;
}
if ( F_1 ( V_2 , 0x24 , 0 , 0 ,
V_68 , V_69 , 0 ) < 0 )
goto V_75;
if ( V_66 [ V_27 ] . V_22 & V_74 ) {
memset ( V_68 , 0 , V_66 [ V_27 ] . V_58 + 1 ) ;
if ( F_1 ( V_2 , 0x25 , 0 , 0 , V_68 ,
V_66 [ V_27 ] . V_58 + 1 , 1 ) < 0 )
goto V_75;
memcpy ( V_66 [ V_27 ] . V_68 , V_68 + 1 , V_66 [ V_27 ] . V_58 ) ;
}
}
V_70 = V_67 ;
V_75:
F_37 ( & V_10 -> V_73 ) ;
return V_70 ;
}
static T_3 F_38 ( struct V_63 * V_64 )
{
return ( V_76 ) & ~ V_77 ;
}
static int F_39 ( struct V_78 * V_79 ,
const struct V_80 * V_81 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
const struct V_82 * V_21 ;
struct V_83 * V_13 = F_40 ( V_79 ) ;
unsigned V_84 ;
char * V_85 ;
int V_86 , V_27 , V_87 ;
F_8 ( L_20 ) ;
switch ( V_81 -> V_88 ) {
case V_89 :
V_85 = L_21 ;
V_21 = & V_90 ;
break;
case V_91 :
V_85 = L_22 ;
V_21 = & V_92 ;
break;
case V_93 :
V_85 = L_23 ;
V_21 = & V_94 ;
break;
case V_95 :
V_85 = L_24 ;
V_21 = & V_96 ;
break;
case V_97 :
V_85 = L_25 ;
V_21 = & V_98 ;
break;
case V_99 :
V_85 = L_26 ;
V_21 = & V_98 ;
break;
case V_100 :
V_85 = L_27 ;
V_21 = & V_98 ;
break;
case V_101 :
V_85 = L_28 ;
V_21 = & V_90 ;
break;
case V_102 :
V_85 = L_29 ;
V_21 = & V_103 ;
break;
case V_104 :
F_10 ( & V_79 -> V_24 , L_30 ) ;
return - V_72 ;
#if 0
name = "Lifeview TV Walker Ultra";
board = &board_lifeview_lr192;
#endif
break;
case V_105 :
F_41 ( & V_79 -> V_24 , L_31 ) ;
V_85 = L_32 ;
V_21 = & V_106 ;
break;
case V_107 :
V_85 = L_33 ;
V_21 = & V_108 ;
break;
default:
F_10 ( & V_79 -> V_24 , L_34 ,
( unsigned int ) V_81 -> V_88 ) ;
return - V_72 ;
}
V_2 = F_42 ( & V_21 -> V_109 , & V_79 -> V_24 ) ;
if ( V_2 == NULL )
return - V_110 ;
V_10 = F_43 ( sizeof( struct V_9 ) , V_48 ) ;
if ( V_10 == NULL ) {
F_31 ( V_2 ) ;
return - V_110 ;
}
V_10 -> V_21 = V_21 ;
V_10 -> V_13 = V_13 ;
F_44 ( V_13 , V_2 -> V_111 , sizeof( V_2 -> V_111 ) ) ;
V_2 -> V_112 = V_81 -> V_88 ;
strncpy ( V_2 -> V_85 , V_85 , sizeof( V_2 -> V_85 ) ) ;
if ( V_21 -> V_22 & V_23 )
V_2 -> V_113 = & V_114 ;
else
V_2 -> V_113 = & V_115 ;
V_2 -> V_11 = V_10 ;
V_10 -> V_47 = F_45 ( 0 , V_48 ) ;
if ( V_10 -> V_47 == NULL )
goto V_116;
V_10 -> V_47 -> V_6 = F_46 ( 2 * sizeof( T_1 ) , V_48 ) ;
if ( V_10 -> V_47 -> V_6 == NULL )
goto V_116;
if ( V_2 -> V_112 == V_105 )
F_47 ( V_10 -> V_47 , V_10 -> V_13 ,
F_48 ( V_10 -> V_13 , 4 ) ,
V_10 -> V_47 -> V_6 , 2 * sizeof( T_1 ) ,
F_14 , V_2 ) ;
else
F_49 ( V_10 -> V_47 , V_10 -> V_13 ,
F_50 ( V_10 -> V_13 , 4 ) ,
V_10 -> V_47 -> V_6 , 2 * sizeof( T_1 ) ,
F_14 , V_2 , 8 ) ;
F_51 ( V_79 , & V_2 -> V_117 ) ;
if ( F_52 ( V_2 , V_2 -> V_118 -> V_22 &
V_119 ) < 0 )
goto V_116;
if ( V_21 -> V_22 & V_120 ) {
memcpy ( & V_2 -> V_63 , & V_121 ,
sizeof( V_121 ) ) ;
F_53 ( & V_10 -> V_73 ) ;
V_2 -> V_63 . V_24 . V_122 = V_2 -> V_24 ;
F_54 ( & V_2 -> V_63 , V_2 ) ;
if ( F_55 ( & V_2 -> V_63 ) < 0 ) {
F_10 ( V_2 -> V_24 , L_35 ) ;
goto V_116;
}
V_2 -> V_123 = 1 ;
}
if ( ( V_2 -> V_112 == V_97 ||
V_2 -> V_112 == V_100 ) &&
V_2 -> V_123 ) {
union V_124 V_26 ;
F_56 ( & V_2 -> V_63 , 0x21 , V_125 ,
V_126 , 0x0A , V_127 , & V_26 ) ;
if ( V_26 . V_128 != 0x76 ) {
if ( V_129 ) {
V_2 -> V_112 = V_130 ;
V_10 -> V_21 = V_21 = & V_131 ;
V_2 -> V_118 = & V_21 -> V_109 ;
strncpy ( V_2 -> V_85 , L_36 ,
sizeof( V_2 -> V_85 ) ) ;
} else {
T_1 V_132 ;
F_57 ( V_2 , 0x3c81 , & V_132 ) ;
V_132 &= 0x3 ;
V_2 -> V_112 = V_133 ;
V_10 -> V_21 = V_21 = & V_134 ;
V_2 -> V_118 = & V_21 -> V_109 ;
V_2 -> V_135 = V_132 ;
snprintf ( V_2 -> V_85 , sizeof( V_2 -> V_85 ) ,
L_37 ,
V_132 ) ;
}
F_58 ( V_2 ) ;
}
}
V_84 = V_2 -> V_118 -> V_84 ;
if ( V_2 -> V_112 == V_102 ) {
if ( F_1 ( V_2 , 0x41 , 0 , 0 , V_2 -> V_31 , 3 ,
1 ) < 0 ) {
F_10 ( V_2 -> V_24 , L_38 ) ;
goto V_116;
}
switch ( V_2 -> V_31 [ 0 ] >> 6 ) {
case 1 :
V_2 -> V_136 = V_137 ;
V_2 -> V_138 = V_139 ;
strncpy ( V_2 -> V_85 , L_39 ,
sizeof( V_2 -> V_85 ) ) ;
break;
case 2 :
V_2 -> V_136 = V_140 ;
V_2 -> V_138 = V_141 ;
V_84 -= 2 ;
strncpy ( V_2 -> V_85 , L_40 ,
sizeof( V_2 -> V_85 ) ) ;
break;
case 3 :
V_2 -> V_136 = V_142 ;
V_84 -= 2 ;
strncpy ( V_2 -> V_85 , L_41 ,
sizeof( V_2 -> V_85 ) ) ;
break;
default:
F_8 ( L_42 ) ;
break;
}
if ( F_1 ( V_2 , 0x40 , 0x7f02 , 0 ,
NULL , 0 , 0 ) < 0 ) {
F_10 ( V_2 -> V_24 , L_43 ) ;
goto V_116;
}
}
if ( ( V_21 -> V_22 & V_23 ) &&
V_13 -> V_143 != V_144 )
F_10 ( V_2 -> V_24 , L_44 ) ;
if ( V_21 -> V_22 & V_23 ) {
V_87 = 1024 ;
V_86 = F_48 ( V_10 -> V_13 , 6 ) ;
} else {
V_87 = 512 ;
V_86 = F_48 ( V_10 -> V_13 , 1 ) ;
}
for ( V_27 = 0 ; V_27 < 8 ; ++ V_27 ) {
V_10 -> V_53 [ V_27 ] = F_45 ( 0 , V_48 ) ;
if ( V_10 -> V_53 [ V_27 ] == NULL )
goto V_116;
V_10 -> V_53 [ V_27 ] -> V_6 =
F_46 ( V_87 , V_48 ) ;
if ( V_10 -> V_53 [ V_27 ] -> V_6 == NULL )
goto V_116;
F_47 ( V_10 -> V_53 [ V_27 ] , V_10 -> V_13 , V_86 ,
V_10 -> V_53 [ V_27 ] -> V_6 , V_87 ,
F_19 , V_2 ) ;
}
if ( ( V_21 -> V_22 & V_23 ) &&
( V_21 -> V_109 . V_22 & V_145 ) ) {
for ( V_27 = 0 ; V_27 < 8 ; ++ V_27 ) {
V_10 -> V_56 [ V_27 ] = F_45 ( 0 , V_48 ) ;
if ( V_10 -> V_56 [ V_27 ] == NULL )
goto V_116;
V_10 -> V_56 [ V_27 ] -> V_6 = F_46 ( 4096 ,
V_48 ) ;
if ( V_10 -> V_56 [ V_27 ] -> V_6 == NULL )
goto V_116;
F_47 ( V_10 -> V_56 [ V_27 ] , V_10 -> V_13 ,
F_48 ( V_10 -> V_13 , 8 ) ,
V_10 -> V_56 [ V_27 ] -> V_6 , 4096 ,
F_23 , V_2 ) ;
}
}
if ( F_59 ( V_2 , V_84 ) < 0 )
goto V_116;
V_2 -> V_19 = V_146 ;
return 0 ;
V_116:
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
return - V_110 ;
}
static void F_60 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_61 ( F_62 ( V_79 ) ) ;
F_35 ( & V_2 -> V_147 ) ;
F_35 ( & V_2 -> V_148 ) ;
if ( V_2 -> V_55 )
F_63 ( V_2 ) ;
V_2 -> V_19 = V_20 ;
F_64 ( & V_2 -> V_117 ) ;
F_65 ( & V_2 -> V_149 ) ;
F_37 ( & V_2 -> V_148 ) ;
F_37 ( & V_2 -> V_147 ) ;
F_66 ( & V_2 -> V_117 ) ;
}
