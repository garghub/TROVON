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
#ifdef F_8
F_9 ( V_24 L_1 ) ;
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
F_9 ( V_25
L_2 ) ;
return - 1 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_26 , int V_27 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_28 , V_29 ;
T_1 V_30 = 0 ;
int V_12 = 500 ;
#ifdef F_8
F_9 ( V_24
L_3 , V_26 , V_27 ) ;
#endif
for ( V_28 = 0 ; V_28 < 100 ; ++ V_28 ) {
V_29 = F_2 ( V_10 -> V_13 ,
F_3 ( V_10 -> V_13 , 0 ) , 0x14 ,
V_14 | V_15 | V_16 ,
0 , V_31 , V_2 -> V_32 ,
sizeof( V_30 ) , V_12 ) ;
if ( V_29 < 0 )
break;
V_30 = F_12 ( * ( ( T_1 * ) V_2 -> V_32 ) ) ;
if ( ! ( V_30 & 0x0010 ) )
break;
F_7 ( 10 ) ;
}
if ( V_29 < 0 )
goto V_33;
if ( V_28 == 100 ) {
F_9 ( V_25
L_4 ,
V_30 ) ;
return - 1 ;
}
V_29 = F_2 ( V_10 -> V_13 , F_4 ( V_10 -> V_13 , 0 ) , 0x12 ,
V_14 | V_15 , V_27 ,
V_34 , NULL , 0 , V_12 ) ;
if ( V_29 < 0 )
goto V_33;
V_29 = F_2 ( V_10 -> V_13 , F_4 ( V_10 -> V_13 , 0 ) ,
0x12 , V_14 | V_15 , V_26 ,
V_35 , NULL , 0 , V_12 ) ;
if ( V_29 < 0 )
goto V_33;
return 0 ;
V_33:
F_9 ( V_25 L_5 , V_29 ) ;
return V_29 ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_26 , int V_27 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_29 ;
int V_12 = 500 ;
#ifdef F_8
F_9 ( V_24
L_3 , V_26 , V_27 ) ;
#endif
V_2 -> V_32 [ 0 ] = V_27 & 0xff ;
V_2 -> V_32 [ 1 ] = V_27 >> 8 ;
V_2 -> V_32 [ 2 ] = V_26 & 0xff ;
V_2 -> V_32 [ 3 ] = V_26 >> 8 ;
V_2 -> V_32 [ 4 ] = V_2 -> V_32 [ 5 ] = V_2 -> V_32 [ 6 ] = V_2 -> V_32 [ 7 ] = 0 ;
V_29 = F_2 ( V_10 -> V_13 , F_4 ( V_10 -> V_13 , 2 ) , 0x00 ,
V_14 | V_36 , 0x55aa ,
0xf0f0 , V_2 -> V_32 , 8 , V_12 ) ;
if ( V_29 < 0 ) {
F_9 ( V_25 L_5 , V_29 ) ;
return V_29 ;
}
return 0 ;
}
static void F_14 ( struct V_37 * V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 -> V_38 ;
T_1 * V_39 = ( T_1 * ) V_37 -> V_6 ;
int V_19 = V_37 -> V_19 ;
if ( V_19 ) {
if ( V_19 != - V_40 &&
V_2 -> V_19 != V_20 ) {
F_9 ( V_25
L_6 ,
V_37 -> V_19 ) ;
} else {
F_15 ( & V_2 -> V_41 ) ;
return;
}
} else if ( V_37 -> V_42 != V_37 -> V_43 ) {
F_9 ( V_25 L_7 ) ;
} else {
V_2 -> V_44 = 1 ;
V_2 -> V_45 = F_16 ( V_39 [ 0 ] ) ;
V_2 -> V_46 = F_16 ( V_39 [ 1 ] ) ;
#ifdef F_8
F_9 ( V_24 L_8 ,
V_2 -> V_46 , V_2 -> V_45 ) ;
#endif
}
F_15 ( & V_2 -> V_41 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_29 ;
V_29 = F_18 ( V_10 -> V_47 , V_48 ) ;
if ( V_29 < 0 ) {
F_9 ( V_25
L_9 , V_29 ) ;
return V_29 ;
}
return 0 ;
}
static void F_19 ( struct V_37 * V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 -> V_38 ;
int V_29 , V_19 = V_37 -> V_19 ;
if ( ! F_20 ( & V_2 -> V_49 ) ) {
F_21 ( & V_2 -> V_50 ) ;
return;
}
if ( V_19 ) {
F_9 ( V_25 L_10 ,
V_19 ) ;
return;
}
if ( V_37 -> V_42 != V_37 -> V_43 ) {
F_9 ( V_25 L_11 ) ;
return;
}
F_22 ( V_2 , V_37 -> V_6 , V_37 -> V_42 ) ;
V_29 = F_18 ( V_37 , V_51 ) ;
if ( V_29 < 0 )
F_9 ( V_25 L_10 , V_29 ) ;
}
static void F_23 ( struct V_37 * V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 -> V_38 ;
int V_29 , V_19 = V_37 -> V_19 ;
if ( ! F_20 ( & V_2 -> V_49 ) )
return;
if ( V_19 ) {
F_9 ( V_25 L_12 ,
V_19 ) ;
return;
}
if ( V_37 -> V_42 != V_37 -> V_43 ) {
F_9 ( V_25 L_13 ) ;
return;
}
if ( V_2 -> V_52 != NULL )
V_2 -> V_52 ( V_2 , V_37 -> V_6 , V_37 -> V_42 ) ;
V_29 = F_18 ( V_37 , V_51 ) ;
if ( V_29 < 0 )
F_9 ( V_25 L_12 , V_29 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_28 , V_29 ;
for ( V_28 = 0 ; V_28 < 8 ; ++ V_28 ) {
V_29 = F_18 ( V_10 -> V_53 [ V_28 ] , V_48 ) ;
if ( V_29 < 0 ) {
F_9 ( V_25 L_14
L_15 , V_28 , V_29 ) ;
goto V_54;
}
}
if ( ! V_2 -> V_55 )
return 0 ;
for ( V_28 = 0 ; V_28 < 8 ; ++ V_28 ) {
V_29 = F_18 ( V_10 -> V_56 [ V_28 ] , V_48 ) ;
if ( V_29 < 0 ) {
F_9 ( V_25 L_16
L_15 , V_28 , V_29 ) ;
goto V_57;
}
}
return 0 ;
V_57:
for ( V_28 = 0 ; V_28 < 7 ; ++ V_28 )
F_25 ( V_10 -> V_56 [ V_28 ] ) ;
V_54:
for ( V_28 = 0 ; V_28 < 8 ; ++ V_28 )
F_25 ( V_10 -> V_53 [ V_28 ] ) ;
return - 1 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_28 ;
if ( V_2 -> V_19 == V_20 )
return 0 ;
for ( V_28 = 0 ; V_28 < 8 ; ++ V_28 )
F_25 ( V_10 -> V_53 [ V_28 ] ) ;
if ( V_2 -> V_55 )
for ( V_28 = 0 ; V_28 < 8 ; ++ V_28 )
F_25 ( V_10 -> V_56 [ V_28 ] ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , T_2 * V_27 , int V_58 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_59 , V_60 ;
int V_12 = 500 ;
#ifdef F_8
F_9 ( V_24 L_17 , V_58 ) ;
#endif
if ( V_10 -> V_21 -> V_22 & V_23 )
V_60 = F_28 ( V_10 -> V_13 , 2 ) ;
else
V_60 = F_28 ( V_10 -> V_13 , 3 ) ;
return F_29 ( V_10 -> V_13 , V_60 , V_27 , V_58 ,
& V_59 , V_12 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_37 * V_61 , * V_62 ;
int V_28 ;
if ( V_10 -> V_47 ) {
F_25 ( V_10 -> V_47 ) ;
F_31 ( V_10 -> V_47 -> V_6 ) ;
F_32 ( V_10 -> V_47 ) ;
}
for ( V_28 = 0 ; V_28 < 8 ; ++ V_28 ) {
V_61 = V_10 -> V_53 [ V_28 ] ;
if ( V_61 ) {
F_25 ( V_61 ) ;
F_31 ( V_61 -> V_6 ) ;
F_32 ( V_61 ) ;
}
V_62 = V_10 -> V_56 [ V_28 ] ;
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
T_2 * V_68 = V_2 -> V_32 ;
int V_69 , V_28 ;
int V_70 = - V_71 ;
if ( V_2 -> V_19 == V_20 )
return - V_72 ;
F_35 ( & V_10 -> V_73 ) ;
for ( V_28 = 0 ; V_28 < V_67 ; ++ V_28 ) {
if ( V_28 + 1 < V_67 && V_66 [ V_28 ] . V_26 == V_66 [ V_28 + 1 ] . V_26 &&
! ( V_66 [ V_28 ] . V_22 & V_74 ) &&
( V_66 [ V_28 + 1 ] . V_22 & V_74 ) ) {
#ifdef F_36
F_9 ( V_24 L_18
L_19 , V_66 [ V_28 ] . V_58 ,
V_66 [ V_28 + 1 ] . V_58 , V_66 [ V_28 ] . V_26 ) ;
#endif
V_68 [ 0 ] = 0x01 ;
V_68 [ 1 ] = V_66 [ V_28 ] . V_58 + 1 ;
V_68 [ 2 ] = V_66 [ V_28 ] . V_26 << 1 ;
memcpy ( & V_68 [ 3 ] , V_66 [ V_28 ] . V_68 , V_66 [ V_28 ] . V_58 ) ;
V_69 = V_66 [ V_28 ] . V_58 + 3 ;
V_68 [ V_69 ++ ] = V_66 [ ++ V_28 ] . V_58 ;
} else if ( V_66 [ V_28 ] . V_22 & V_74 ) {
#ifdef F_36
F_9 ( V_24 L_20
L_19 , V_66 [ V_28 ] . V_58 ,
V_66 [ V_28 ] . V_26 ) ;
#endif
V_68 [ 0 ] = 0x01 ;
V_68 [ 1 ] = 1 ;
V_68 [ 2 ] = V_66 [ V_28 ] . V_26 << 1 ;
V_68 [ 3 ] = V_66 [ V_28 ] . V_58 ;
V_69 = 4 ;
} else {
#ifdef F_36
F_9 ( V_24 L_21
L_19 , V_66 [ V_28 ] . V_58 ,
V_66 [ V_28 ] . V_26 ) ;
#endif
V_68 [ 0 ] = 0x00 ;
V_68 [ 1 ] = V_66 [ V_28 ] . V_58 + 1 ;
V_68 [ 2 ] = V_66 [ V_28 ] . V_26 << 1 ;
memcpy ( & V_68 [ 3 ] , V_66 [ V_28 ] . V_68 , V_66 [ V_28 ] . V_58 ) ;
V_69 = V_66 [ V_28 ] . V_58 + 3 ;
V_68 [ V_69 ++ ] = 0 ;
}
if ( F_1 ( V_2 , 0x24 , 0 , 0 ,
V_68 , V_69 , 0 ) < 0 )
goto V_75;
if ( V_66 [ V_28 ] . V_22 & V_74 ) {
memset ( V_68 , 0 , V_66 [ V_28 ] . V_58 + 1 ) ;
if ( F_1 ( V_2 , 0x25 , 0 , 0 , V_68 ,
V_66 [ V_28 ] . V_58 + 1 , 1 ) < 0 )
goto V_75;
memcpy ( V_66 [ V_28 ] . V_68 , V_68 + 1 , V_66 [ V_28 ] . V_58 ) ;
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
int V_86 , V_28 , V_87 ;
F_9 ( V_24 L_22 ) ;
switch ( V_81 -> V_88 ) {
case V_89 :
V_85 = L_23 ;
V_21 = & V_90 ;
break;
case V_91 :
V_85 = L_24 ;
V_21 = & V_92 ;
break;
case V_93 :
V_85 = L_25 ;
V_21 = & V_94 ;
break;
case V_95 :
V_85 = L_26 ;
V_21 = & V_96 ;
break;
case V_97 :
V_85 = L_27 ;
V_21 = & V_98 ;
break;
case V_99 :
V_85 = L_28 ;
V_21 = & V_98 ;
break;
case V_100 :
V_85 = L_29 ;
V_21 = & V_98 ;
break;
case V_101 :
V_85 = L_30 ;
V_21 = & V_90 ;
break;
case V_102 :
V_85 = L_31 ;
V_21 = & V_103 ;
break;
case V_104 :
F_9 ( V_25 L_32
L_33 ) ;
return - V_72 ;
V_85 = L_34 ;
V_21 = & V_105 ;
break;
case V_106 :
F_9 ( V_107 L_35 ) ;
V_85 = L_36 ;
V_21 = & V_108 ;
break;
case V_109 :
V_85 = L_37 ;
V_21 = & V_110 ;
break;
default:
F_9 ( V_25 L_38 ,
( unsigned int ) V_81 -> V_88 ) ;
return - V_72 ;
}
V_2 = F_41 ( & V_21 -> V_111 , & V_79 -> V_112 ) ;
if ( V_2 == NULL )
return - V_113 ;
V_10 = F_42 ( sizeof( struct V_9 ) , V_48 ) ;
if ( V_10 == NULL ) {
F_31 ( V_2 ) ;
return - V_113 ;
}
V_10 -> V_21 = V_21 ;
V_10 -> V_13 = V_13 ;
F_43 ( V_13 , V_2 -> V_114 , sizeof( V_2 -> V_114 ) ) ;
V_2 -> V_115 = V_81 -> V_88 ;
strncpy ( V_2 -> V_85 , V_85 , sizeof( V_2 -> V_85 ) ) ;
if ( V_21 -> V_22 & V_23 )
V_2 -> V_116 = & V_117 ;
else
V_2 -> V_116 = & V_118 ;
V_2 -> V_11 = V_10 ;
V_10 -> V_47 = F_44 ( 0 , V_48 ) ;
if ( V_10 -> V_47 == NULL )
goto V_119;
V_10 -> V_47 -> V_6 = F_45 ( 2 * sizeof( T_1 ) , V_48 ) ;
if ( V_10 -> V_47 -> V_6 == NULL )
goto V_119;
if ( V_2 -> V_115 == V_106 )
F_46 ( V_10 -> V_47 , V_10 -> V_13 ,
F_47 ( V_10 -> V_13 , 4 ) ,
V_10 -> V_47 -> V_6 , 2 * sizeof( T_1 ) ,
F_14 , V_2 ) ;
else
F_48 ( V_10 -> V_47 , V_10 -> V_13 ,
F_49 ( V_10 -> V_13 , 4 ) ,
V_10 -> V_47 -> V_6 , 2 * sizeof( T_1 ) ,
F_14 , V_2 , 8 ) ;
F_50 ( V_79 , & V_2 -> V_120 ) ;
if ( F_51 ( V_2 , V_2 -> V_121 -> V_22 &
V_122 ) < 0 )
goto V_119;
if ( V_21 -> V_22 & V_123 ) {
memcpy ( & V_2 -> V_63 , & V_124 ,
sizeof( V_124 ) ) ;
F_52 ( & V_10 -> V_73 ) ;
V_2 -> V_63 . V_112 . V_125 = V_2 -> V_112 ;
F_53 ( & V_2 -> V_63 , V_2 ) ;
if ( F_54 ( & V_2 -> V_63 ) < 0 ) {
F_9 ( V_25
L_39 ) ;
goto V_119;
}
V_2 -> V_126 = 1 ;
}
if ( ( V_2 -> V_115 == V_97 ||
V_2 -> V_115 == V_100 ) &&
V_2 -> V_126 ) {
union V_127 V_27 ;
F_55 ( & V_2 -> V_63 , 0x21 , V_128 ,
V_129 , 0x0A , V_130 , & V_27 ) ;
if ( V_27 . V_131 != 0x76 ) {
if ( V_132 ) {
V_2 -> V_115 = V_133 ;
V_10 -> V_21 = V_21 = & V_134 ;
V_2 -> V_121 = & V_21 -> V_111 ;
strncpy ( V_2 -> V_85 , L_40 ,
sizeof( V_2 -> V_85 ) ) ;
} else {
T_1 V_135 ;
F_56 ( V_2 , 0x3c81 , & V_135 ) ;
V_135 &= 0x3 ;
V_2 -> V_115 = V_136 ;
V_10 -> V_21 = V_21 = & V_137 ;
V_2 -> V_121 = & V_21 -> V_111 ;
V_2 -> V_138 = V_135 ;
snprintf ( V_2 -> V_85 , sizeof( V_2 -> V_85 ) ,
L_41 ,
V_135 ) ;
}
F_57 ( V_2 ) ;
}
}
V_84 = V_2 -> V_121 -> V_84 ;
if ( V_2 -> V_115 == V_102 ) {
if ( F_1 ( V_2 , 0x41 , 0 , 0 , V_2 -> V_32 , 3 , 1 ) < 0 ) {
F_9 ( V_25 L_42 ) ;
goto V_119;
}
switch ( V_2 -> V_32 [ 0 ] >> 6 ) {
case 1 :
V_2 -> V_139 = V_140 ;
V_2 -> V_141 = V_142 ;
strncpy ( V_2 -> V_85 , L_43 ,
sizeof( V_2 -> V_85 ) ) ;
break;
case 2 :
V_2 -> V_139 = V_143 ;
V_2 -> V_141 = V_144 ;
V_84 -= 2 ;
strncpy ( V_2 -> V_85 , L_44 ,
sizeof( V_2 -> V_85 ) ) ;
break;
case 3 :
V_2 -> V_139 = V_145 ;
V_84 -= 2 ;
strncpy ( V_2 -> V_85 , L_45 ,
sizeof( V_2 -> V_85 ) ) ;
break;
default:
F_9 ( V_24 L_46
L_47 ) ;
break;
}
if ( F_1 ( V_2 , 0x40 , 0x7f02 , 0 ,
NULL , 0 , 0 ) < 0 ) {
F_9 ( V_25 L_48 ) ;
goto V_119;
}
}
if ( ( V_21 -> V_22 & V_23 ) &&
V_13 -> V_146 != V_147 )
F_9 ( V_25 L_49
L_50
L_51
L_52
L_53 ) ;
if ( V_21 -> V_22 & V_23 ) {
V_87 = 1024 ;
V_86 = F_47 ( V_10 -> V_13 , 6 ) ;
} else {
V_87 = 512 ;
V_86 = F_47 ( V_10 -> V_13 , 1 ) ;
}
for ( V_28 = 0 ; V_28 < 8 ; ++ V_28 ) {
V_10 -> V_53 [ V_28 ] = F_44 ( 0 , V_48 ) ;
if ( V_10 -> V_53 [ V_28 ] == NULL )
goto V_119;
V_10 -> V_53 [ V_28 ] -> V_6 =
F_45 ( V_87 , V_48 ) ;
if ( V_10 -> V_53 [ V_28 ] -> V_6 == NULL )
goto V_119;
F_46 ( V_10 -> V_53 [ V_28 ] , V_10 -> V_13 , V_86 ,
V_10 -> V_53 [ V_28 ] -> V_6 , V_87 ,
F_19 , V_2 ) ;
}
if ( ( V_21 -> V_22 & V_23 ) &&
( V_21 -> V_22 & V_148 ) ) {
for ( V_28 = 0 ; V_28 < 8 ; ++ V_28 ) {
V_10 -> V_56 [ V_28 ] = F_44 ( 0 , V_48 ) ;
if ( V_10 -> V_56 [ V_28 ] == NULL )
goto V_119;
V_10 -> V_56 [ V_28 ] -> V_6 = F_45 ( 4096 ,
V_48 ) ;
if ( V_10 -> V_56 [ V_28 ] -> V_6 == NULL )
goto V_119;
F_46 ( V_10 -> V_56 [ V_28 ] , V_10 -> V_13 ,
F_47 ( V_10 -> V_13 , 8 ) ,
V_10 -> V_56 [ V_28 ] -> V_6 , 4096 ,
F_23 , V_2 ) ;
}
}
if ( F_58 ( V_2 , V_84 ) < 0 )
goto V_119;
V_2 -> V_19 = V_149 ;
return 0 ;
V_119:
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
return - V_113 ;
}
static void F_59 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_60 ( F_61 ( V_79 ) ) ;
F_35 ( & V_2 -> V_150 ) ;
F_35 ( & V_2 -> V_151 ) ;
if ( V_2 -> V_55 )
F_62 ( V_2 ) ;
V_2 -> V_19 = V_20 ;
F_63 ( & V_2 -> V_120 ) ;
F_64 ( & V_2 -> V_152 ) ;
F_37 ( & V_2 -> V_151 ) ;
F_37 ( & V_2 -> V_150 ) ;
F_65 ( & V_2 -> V_120 ) ;
}
