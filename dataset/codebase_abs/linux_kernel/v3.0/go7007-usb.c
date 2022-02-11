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
if ( F_6 ( V_2 , 0x0001 , 0x0001 ) < 0 )
return - 1 ;
F_7 ( 100 ) ;
if ( V_10 -> V_19 -> V_20 & V_21 ) {
#ifdef F_8
F_9 ( V_22 L_1 ) ;
#endif
if ( F_1 ( V_2 , 0x10 , 0 , 0 , NULL , 0 , 0 ) < 0 ||
F_1 ( V_2 , 0x10 , 0 , 0 , NULL , 0 , 0 ) < 0 )
return - 1 ;
if ( F_6 ( V_2 , 0x0001 , 0x0001 ) < 0 )
return - 1 ;
F_7 ( 100 ) ;
}
if ( F_10 ( V_2 , & V_17 , & V_18 ) < 0 ||
( V_17 & ~ 0x1 ) != 0x55aa ) {
F_9 ( V_23
L_2 ) ;
return - 1 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_24 , int V_25 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_26 , V_27 ;
T_1 V_28 ;
int V_12 = 500 ;
#ifdef F_8
F_9 ( V_22
L_3 , V_24 , V_25 ) ;
#endif
for ( V_26 = 0 ; V_26 < 100 ; ++ V_26 ) {
V_27 = F_2 ( V_10 -> V_13 ,
F_3 ( V_10 -> V_13 , 0 ) , 0x14 ,
V_14 | V_15 | V_16 ,
0 , V_29 , & V_28 ,
sizeof( V_28 ) , V_12 ) ;
if ( V_27 < 0 )
goto V_30;
F_12 ( & V_28 ) ;
if ( ! ( V_28 & 0x0010 ) )
break;
F_7 ( 10 ) ;
}
if ( V_26 == 100 ) {
F_9 ( V_23
L_4 ,
V_28 ) ;
return - 1 ;
}
V_27 = F_2 ( V_10 -> V_13 , F_4 ( V_10 -> V_13 , 0 ) , 0x12 ,
V_14 | V_15 , V_25 ,
V_31 , NULL , 0 , V_12 ) ;
if ( V_27 < 0 )
goto V_30;
V_27 = F_2 ( V_10 -> V_13 , F_4 ( V_10 -> V_13 , 0 ) ,
0x12 , V_14 | V_15 , V_24 ,
V_32 , NULL , 0 , V_12 ) ;
if ( V_27 < 0 )
goto V_30;
return 0 ;
V_30:
F_9 ( V_23 L_5 , V_27 ) ;
return V_27 ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_24 , int V_25 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_2 * V_33 ;
int V_27 ;
int V_12 = 500 ;
#ifdef F_8
F_9 ( V_22
L_3 , V_24 , V_25 ) ;
#endif
V_33 = F_14 ( 8 , V_34 ) ;
if ( V_33 == NULL )
return - V_35 ;
V_33 [ 0 ] = V_25 & 0xff ;
V_33 [ 1 ] = V_25 >> 8 ;
V_33 [ 2 ] = V_24 & 0xff ;
V_33 [ 3 ] = V_24 >> 8 ;
V_27 = F_2 ( V_10 -> V_13 , F_4 ( V_10 -> V_13 , 2 ) , 0x00 ,
V_14 | V_36 , 0x55aa ,
0xf0f0 , V_33 , 8 , V_12 ) ;
F_15 ( V_33 ) ;
if ( V_27 < 0 ) {
F_9 ( V_23 L_5 , V_27 ) ;
return V_27 ;
}
return 0 ;
}
static void F_16 ( struct V_37 * V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 -> V_38 ;
T_1 * V_39 = ( T_1 * ) V_37 -> V_6 ;
int V_40 = V_37 -> V_40 ;
if ( V_40 ) {
if ( V_40 != - V_41 &&
V_2 -> V_40 != V_42 ) {
F_9 ( V_23
L_6 ,
V_37 -> V_40 ) ;
} else {
F_17 ( & V_2 -> V_43 ) ;
return;
}
} else if ( V_37 -> V_44 != V_37 -> V_45 ) {
F_9 ( V_23 L_7 ) ;
} else {
V_2 -> V_46 = 1 ;
V_2 -> V_47 = F_18 ( V_39 [ 0 ] ) ;
V_2 -> V_48 = F_18 ( V_39 [ 1 ] ) ;
#ifdef F_8
F_9 ( V_22 L_8 ,
V_2 -> V_48 , V_2 -> V_47 ) ;
#endif
}
F_17 ( & V_2 -> V_43 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_27 ;
V_27 = F_20 ( V_10 -> V_49 , V_34 ) ;
if ( V_27 < 0 ) {
F_9 ( V_23
L_9 , V_27 ) ;
return V_27 ;
}
return 0 ;
}
static void F_21 ( struct V_37 * V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 -> V_38 ;
int V_27 , V_40 = V_37 -> V_40 ;
if ( ! V_2 -> V_50 ) {
F_22 ( & V_2 -> V_51 ) ;
return;
}
if ( V_40 ) {
F_9 ( V_23 L_10 ,
V_40 ) ;
return;
}
if ( V_37 -> V_44 != V_37 -> V_45 ) {
F_9 ( V_23 L_11 ) ;
return;
}
F_23 ( V_2 , V_37 -> V_6 , V_37 -> V_44 ) ;
V_27 = F_20 ( V_37 , V_52 ) ;
if ( V_27 < 0 )
F_9 ( V_23 L_10 , V_27 ) ;
}
static void F_24 ( struct V_37 * V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 -> V_38 ;
int V_27 , V_40 = V_37 -> V_40 ;
if ( ! V_2 -> V_50 )
return;
if ( V_40 ) {
F_9 ( V_23 L_12 ,
V_40 ) ;
return;
}
if ( V_37 -> V_44 != V_37 -> V_45 ) {
F_9 ( V_23 L_13 ) ;
return;
}
if ( V_2 -> V_53 != NULL )
V_2 -> V_53 ( V_2 , V_37 -> V_6 , V_37 -> V_44 ) ;
V_27 = F_20 ( V_37 , V_52 ) ;
if ( V_27 < 0 )
F_9 ( V_23 L_12 , V_27 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_26 , V_27 ;
for ( V_26 = 0 ; V_26 < 8 ; ++ V_26 ) {
V_27 = F_20 ( V_10 -> V_54 [ V_26 ] , V_34 ) ;
if ( V_27 < 0 ) {
F_9 ( V_23 L_14
L_15 , V_26 , V_27 ) ;
goto V_55;
}
}
if ( ! V_2 -> V_56 )
return 0 ;
for ( V_26 = 0 ; V_26 < 8 ; ++ V_26 ) {
V_27 = F_20 ( V_10 -> V_57 [ V_26 ] , V_34 ) ;
if ( V_27 < 0 ) {
F_9 ( V_23 L_16
L_15 , V_26 , V_27 ) ;
goto V_58;
}
}
return 0 ;
V_58:
for ( V_26 = 0 ; V_26 < 7 ; ++ V_26 )
F_26 ( V_10 -> V_57 [ V_26 ] ) ;
V_55:
for ( V_26 = 0 ; V_26 < 8 ; ++ V_26 )
F_26 ( V_10 -> V_54 [ V_26 ] ) ;
return - 1 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_26 ;
if ( V_2 -> V_40 == V_42 )
return 0 ;
for ( V_26 = 0 ; V_26 < 8 ; ++ V_26 )
F_26 ( V_10 -> V_54 [ V_26 ] ) ;
if ( V_2 -> V_56 )
for ( V_26 = 0 ; V_26 < 8 ; ++ V_26 )
F_26 ( V_10 -> V_57 [ V_26 ] ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , T_2 * V_25 , int V_59 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_60 , V_61 ;
int V_12 = 500 ;
#ifdef F_8
F_9 ( V_22 L_17 , V_59 ) ;
#endif
if ( V_10 -> V_19 -> V_20 & V_21 )
V_61 = F_29 ( V_10 -> V_13 , 2 ) ;
else
V_61 = F_29 ( V_10 -> V_13 , 3 ) ;
return F_30 ( V_10 -> V_13 , V_61 , V_25 , V_59 ,
& V_60 , V_12 ) ;
}
static int F_31 ( struct V_62 * V_63 ,
struct V_64 V_65 [] , int V_66 )
{
struct V_1 * V_2 = F_32 ( V_63 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
T_2 V_67 [ 16 ] ;
int V_68 , V_26 ;
int V_69 = - 1 ;
if ( V_2 -> V_40 == V_42 )
return - 1 ;
F_33 ( & V_10 -> V_70 ) ;
for ( V_26 = 0 ; V_26 < V_66 ; ++ V_26 ) {
if ( V_26 + 1 < V_66 && V_65 [ V_26 ] . V_24 == V_65 [ V_26 + 1 ] . V_24 &&
! ( V_65 [ V_26 ] . V_20 & V_71 ) &&
( V_65 [ V_26 + 1 ] . V_20 & V_71 ) ) {
#ifdef F_34
F_9 ( V_22 L_18
L_19 , V_65 [ V_26 ] . V_59 ,
V_65 [ V_26 + 1 ] . V_59 , V_65 [ V_26 ] . V_24 ) ;
#endif
V_67 [ 0 ] = 0x01 ;
V_67 [ 1 ] = V_65 [ V_26 ] . V_59 + 1 ;
V_67 [ 2 ] = V_65 [ V_26 ] . V_24 << 1 ;
memcpy ( & V_67 [ 3 ] , V_65 [ V_26 ] . V_67 , V_65 [ V_26 ] . V_59 ) ;
V_68 = V_65 [ V_26 ] . V_59 + 3 ;
V_67 [ V_68 ++ ] = V_65 [ ++ V_26 ] . V_59 ;
} else if ( V_65 [ V_26 ] . V_20 & V_71 ) {
#ifdef F_34
F_9 ( V_22 L_20
L_19 , V_65 [ V_26 ] . V_59 ,
V_65 [ V_26 ] . V_24 ) ;
#endif
V_67 [ 0 ] = 0x01 ;
V_67 [ 1 ] = 1 ;
V_67 [ 2 ] = V_65 [ V_26 ] . V_24 << 1 ;
V_67 [ 3 ] = V_65 [ V_26 ] . V_59 ;
V_68 = 4 ;
} else {
#ifdef F_34
F_9 ( V_22 L_21
L_19 , V_65 [ V_26 ] . V_59 ,
V_65 [ V_26 ] . V_24 ) ;
#endif
V_67 [ 0 ] = 0x00 ;
V_67 [ 1 ] = V_65 [ V_26 ] . V_59 + 1 ;
V_67 [ 2 ] = V_65 [ V_26 ] . V_24 << 1 ;
memcpy ( & V_67 [ 3 ] , V_65 [ V_26 ] . V_67 , V_65 [ V_26 ] . V_59 ) ;
V_68 = V_65 [ V_26 ] . V_59 + 3 ;
V_67 [ V_68 ++ ] = 0 ;
}
if ( F_1 ( V_2 , 0x24 , 0 , 0 ,
V_67 , V_68 , 0 ) < 0 )
goto V_72;
if ( V_65 [ V_26 ] . V_20 & V_71 ) {
memset ( V_67 , 0 , sizeof( V_67 ) ) ;
if ( F_1 ( V_2 , 0x25 , 0 , 0 , V_67 ,
V_65 [ V_26 ] . V_59 + 1 , 1 ) < 0 )
goto V_72;
memcpy ( V_65 [ V_26 ] . V_67 , V_67 + 1 , V_65 [ V_26 ] . V_59 ) ;
}
}
V_69 = 0 ;
V_72:
F_35 ( & V_10 -> V_70 ) ;
return V_69 ;
}
static T_3 F_36 ( struct V_62 * V_63 )
{
return ( V_73 ) & ~ V_74 ;
}
static int F_37 ( struct V_75 * V_76 ,
const struct V_77 * V_78 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_79 * V_19 ;
struct V_80 * V_13 = F_38 ( V_76 ) ;
char * V_81 ;
int V_82 , V_26 , V_83 ;
F_9 ( V_22 L_22 ) ;
switch ( V_78 -> V_84 ) {
case V_85 :
V_81 = L_23 ;
V_19 = & V_86 ;
break;
case V_87 :
V_81 = L_24 ;
V_19 = & V_88 ;
break;
case V_89 :
V_81 = L_25 ;
V_19 = & V_90 ;
break;
case V_91 :
V_81 = L_26 ;
V_19 = & V_92 ;
break;
case V_93 :
V_81 = L_27 ;
V_19 = & V_94 ;
break;
case V_95 :
V_81 = L_28 ;
V_19 = & V_94 ;
break;
case V_96 :
V_81 = L_29 ;
V_19 = & V_94 ;
break;
case V_97 :
V_81 = L_30 ;
V_19 = & V_86 ;
break;
case V_98 :
V_81 = L_31 ;
V_19 = & V_99 ;
break;
case V_100 :
F_9 ( V_23 L_32
L_33 ) ;
return 0 ;
V_81 = L_34 ;
V_19 = & V_101 ;
break;
case V_102 :
F_9 ( V_103 L_35 ) ;
V_81 = L_36 ;
V_19 = & V_104 ;
break;
default:
F_9 ( V_23 L_37 ,
( unsigned int ) V_78 -> V_84 ) ;
return 0 ;
}
V_10 = F_14 ( sizeof( struct V_9 ) , V_34 ) ;
if ( V_10 == NULL )
return - V_35 ;
V_10 -> V_49 = F_39 ( 0 , V_34 ) ;
if ( V_10 -> V_49 == NULL )
goto V_105;
V_10 -> V_49 -> V_6 = F_40 ( 2 * sizeof( T_1 ) , V_34 ) ;
if ( V_10 -> V_49 -> V_6 == NULL )
goto V_105;
V_2 = F_41 ( & V_19 -> V_106 , & V_76 -> V_107 ) ;
if ( V_2 == NULL )
goto V_105;
V_10 -> V_19 = V_19 ;
V_10 -> V_13 = V_13 ;
V_2 -> V_108 = V_78 -> V_84 ;
strncpy ( V_2 -> V_81 , V_81 , sizeof( V_2 -> V_81 ) ) ;
if ( V_19 -> V_20 & V_21 )
V_2 -> V_109 = & V_110 ;
else
V_2 -> V_109 = & V_111 ;
V_2 -> V_11 = V_10 ;
F_42 ( V_10 -> V_49 , V_10 -> V_13 ,
F_43 ( V_10 -> V_13 , 4 ) ,
V_10 -> V_49 -> V_6 , 2 * sizeof( T_1 ) ,
F_16 , V_2 , 8 ) ;
F_44 ( V_76 , & V_2 -> V_112 ) ;
if ( F_45 ( V_2 , V_2 -> V_113 -> V_20 &
V_114 ) < 0 )
goto V_115;
if ( V_19 -> V_20 & V_116 ) {
memcpy ( & V_2 -> V_62 , & V_117 ,
sizeof( V_117 ) ) ;
F_46 ( & V_10 -> V_70 ) ;
V_2 -> V_62 . V_107 . V_118 = V_2 -> V_107 ;
F_47 ( & V_2 -> V_62 , V_2 ) ;
if ( F_48 ( & V_2 -> V_62 ) < 0 ) {
F_9 ( V_23
L_38 ) ;
goto V_115;
}
V_2 -> V_119 = 1 ;
}
if ( ( V_2 -> V_108 == V_93 ||
V_2 -> V_108 == V_96 ) &&
V_2 -> V_119 ) {
union V_120 V_25 ;
F_49 ( & V_2 -> V_62 , 0x21 , V_121 ,
V_122 , 0x0A , V_123 , & V_25 ) ;
if ( V_25 . V_124 != 0x76 ) {
if ( V_125 ) {
V_2 -> V_108 = V_126 ;
V_10 -> V_19 = V_19 = & V_127 ;
V_2 -> V_113 = & V_19 -> V_106 ;
strncpy ( V_2 -> V_81 , L_39 ,
sizeof( V_2 -> V_81 ) ) ;
} else {
T_1 V_128 ;
F_50 ( V_2 , 0x3c82 , 0x0000 ) ;
F_50 ( V_2 , 0x3c80 , 0x00df ) ;
F_51 ( V_2 , 0x3c81 , & V_128 ) ;
V_128 &= 0x3 ;
V_2 -> V_108 = V_129 ;
V_10 -> V_19 = V_19 = & V_130 ;
V_2 -> V_113 = & V_19 -> V_106 ;
V_2 -> V_131 = V_128 ;
snprintf ( V_2 -> V_81 , sizeof( V_2 -> V_81 ) ,
L_40 ,
V_128 ) ;
}
}
}
if ( V_2 -> V_108 == V_98 ) {
T_2 V_25 [ 3 ] ;
if ( F_1 ( V_2 , 0x41 , 0 , 0 , V_25 , 3 , 1 ) < 0 ) {
F_9 ( V_23 L_41 ) ;
goto V_115;
}
switch ( V_25 [ 0 ] >> 6 ) {
case 1 :
V_2 -> V_108 = V_132 ;
V_2 -> V_133 = V_134 ;
strncpy ( V_2 -> V_81 , L_42 ,
sizeof( V_2 -> V_81 ) ) ;
break;
case 2 :
V_2 -> V_108 = V_135 ;
V_2 -> V_133 = V_136 ;
strncpy ( V_2 -> V_81 , L_43 ,
sizeof( V_2 -> V_81 ) ) ;
break;
case 3 :
V_2 -> V_108 = V_137 ;
V_2 -> V_133 = V_138 ;
strncpy ( V_2 -> V_81 , L_44 ,
sizeof( V_2 -> V_81 ) ) ;
break;
default:
F_9 ( V_22 L_45
L_46 ) ;
break;
}
if ( F_1 ( V_2 , 0x40 , 0x7f02 , 0 ,
NULL , 0 , 0 ) < 0 ) {
F_9 ( V_23 L_47 ) ;
goto V_115;
}
}
if ( ( V_19 -> V_20 & V_21 ) &&
V_13 -> V_139 != V_140 )
F_9 ( V_23 L_48
L_49
L_50
L_51
L_52 ) ;
if ( F_52 ( V_2 ) < 0 )
goto V_115;
if ( V_19 -> V_20 & V_21 ) {
V_83 = 1024 ;
V_82 = F_53 ( V_10 -> V_13 , 6 ) ;
} else {
V_83 = 512 ;
V_82 = F_53 ( V_10 -> V_13 , 1 ) ;
}
for ( V_26 = 0 ; V_26 < 8 ; ++ V_26 ) {
V_10 -> V_54 [ V_26 ] = F_39 ( 0 , V_34 ) ;
if ( V_10 -> V_54 [ V_26 ] == NULL )
goto V_115;
V_10 -> V_54 [ V_26 ] -> V_6 =
F_40 ( V_83 , V_34 ) ;
if ( V_10 -> V_54 [ V_26 ] -> V_6 == NULL )
goto V_115;
F_54 ( V_10 -> V_54 [ V_26 ] , V_10 -> V_13 , V_82 ,
V_10 -> V_54 [ V_26 ] -> V_6 , V_83 ,
F_21 , V_2 ) ;
}
if ( ( V_19 -> V_20 & V_21 ) && V_2 -> V_56 )
for ( V_26 = 0 ; V_26 < 8 ; ++ V_26 ) {
V_10 -> V_57 [ V_26 ] = F_39 ( 0 , V_34 ) ;
if ( V_10 -> V_57 [ V_26 ] == NULL )
goto V_115;
V_10 -> V_57 [ V_26 ] -> V_6 = F_40 ( 4096 ,
V_34 ) ;
if ( V_10 -> V_57 [ V_26 ] -> V_6 == NULL )
goto V_115;
F_54 ( V_10 -> V_57 [ V_26 ] , V_10 -> V_13 ,
F_53 ( V_10 -> V_13 , 8 ) ,
V_10 -> V_57 [ V_26 ] -> V_6 , 4096 ,
F_24 , V_2 ) ;
}
V_2 -> V_40 = V_141 ;
return 0 ;
V_115:
V_2 -> V_40 = V_42 ;
return 0 ;
V_105:
if ( V_10 -> V_49 ) {
F_15 ( V_10 -> V_49 -> V_6 ) ;
F_55 ( V_10 -> V_49 ) ;
}
F_15 ( V_10 ) ;
return - V_35 ;
}
static void F_56 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = F_57 ( F_58 ( V_76 ) ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_37 * V_142 , * V_143 ;
int V_26 ;
V_2 -> V_40 = V_42 ;
F_26 ( V_10 -> V_49 ) ;
for ( V_26 = 0 ; V_26 < 8 ; ++ V_26 ) {
V_142 = V_10 -> V_54 [ V_26 ] ;
if ( V_142 ) {
F_26 ( V_142 ) ;
F_15 ( V_142 -> V_6 ) ;
F_55 ( V_142 ) ;
}
V_143 = V_10 -> V_57 [ V_26 ] ;
if ( V_143 ) {
F_26 ( V_143 ) ;
F_15 ( V_143 -> V_6 ) ;
F_55 ( V_143 ) ;
}
}
F_15 ( V_10 -> V_49 -> V_6 ) ;
F_55 ( V_10 -> V_49 ) ;
F_15 ( V_2 -> V_11 ) ;
F_59 ( V_2 ) ;
}
static int T_4 F_60 ( void )
{
return F_61 ( & V_144 ) ;
}
static void T_5 F_62 ( void )
{
F_63 ( & V_144 ) ;
}
