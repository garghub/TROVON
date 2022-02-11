static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
switch ( V_2 -> V_5 ) {
case V_6 :
F_2 ( V_2 , V_4 ) ;
break;
default:
V_4 -> error = V_7 ;
break;
}
}
static void F_3 ( struct V_8 * V_9 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
switch ( V_2 -> V_5 ) {
case V_13 :
if ( V_9 -> V_14 ) {
T_1 V_15 ;
V_15 = F_4 ( V_9 , V_2 ) ;
if ( V_15 ) {
if ( V_15 >= V_16 ) {
V_4 -> error =
V_17 ;
V_4 -> V_18 = V_15 ;
} else {
V_4 -> error = V_15 ;
}
break;
}
if ( F_5 ( V_11 -> V_19 , V_2 , V_4 ) )
break;
}
F_6 ( V_9 , V_2 , V_4 ) ;
break;
case V_20 :
F_6 ( V_9 , V_2 , V_4 ) ;
F_7 ( V_11 -> V_19 , V_2 , V_4 ) ;
break;
case V_21 :
default:
F_6 ( V_9 , V_2 , V_4 ) ;
break;
}
}
static void F_8 ( struct V_8 * V_9 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
switch ( V_2 -> V_5 ) {
case V_22 :
F_9 ( V_9 , V_2 , V_4 ) ;
break;
case V_23 :
F_10 ( V_9 , V_2 , V_4 ) ;
break;
default:
F_6 ( V_9 , V_2 , V_4 ) ;
break;
}
}
static void F_11 ( struct V_8 * V_9 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
switch ( V_2 -> V_5 ) {
case V_24 :
case V_25 :
V_4 -> error = V_7 ;
break;
default:
F_6 ( V_9 , V_2 , V_4 ) ;
return;
}
}
static void F_12 ( struct V_8 * V_9 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
switch ( V_2 -> V_5 ) {
case V_26 :
case V_27 :
V_4 -> error = V_7 ;
break;
default:
F_6 ( V_9 , V_2 , V_4 ) ;
return;
}
}
void F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = NULL ;
if ( V_2 -> V_28 != V_29 ) {
V_9 = F_14 ( V_2 -> V_30 ) ;
if ( ! V_9 ) {
F_15 ( V_4 , V_2 -> V_28 , V_2 -> V_5 ,
V_31 ) ;
F_16 ( V_32 , L_1 ,
V_2 -> V_30 ) ;
return;
}
if ( V_9 -> V_33 >= 10 ) {
F_15 ( V_4 , V_2 -> V_28 , V_2 -> V_5 ,
V_34 ) ;
F_16 ( V_32 , L_2 ,
V_2 -> V_30 ) ;
return;
}
}
if ( V_2 -> V_5 != V_6 )
F_15 ( V_4 , V_2 -> V_28 , V_2 -> V_5 ,
V_35 ) ;
switch ( V_2 -> type ) {
case V_36 :
switch ( V_2 -> V_28 ) {
case V_29 :
F_1 ( V_2 , V_4 ) ;
break;
case V_37 :
V_4 -> V_38 =
sizeof( struct V_39 ) +
sizeof( struct V_40 ) ;
F_8 ( V_9 , V_2 , V_4 ) ;
break;
case V_41 :
F_3 ( V_9 , V_2 , V_4 ) ;
break;
case V_42 :
F_11 ( V_9 , V_2 , V_4 ) ;
break;
case V_43 :
F_12 ( V_9 , V_2 , V_4 ) ;
break;
default:
F_6 ( V_9 , V_2 , V_4 ) ;
break;
}
break;
default:
V_4 -> error = V_44 ;
break;
}
}
static void F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 V_45 ;
struct V_8 * V_9 ;
T_2 V_46 ;
T_1 V_15 = 0 ;
T_2 V_47 = 0 ;
F_16 ( V_48 , L_3 ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_12 = F_17 ( sizeof( struct V_10 ) , V_49 ) ;
if ( ! V_45 . V_12 ) {
F_16 ( ERROR , L_4 ) ;
V_4 -> error = V_50 ;
return;
}
V_45 . V_51 = * V_2 -> V_52 . V_53 . V_54 . V_55 . V_51 ;
V_15 = F_18 ( & V_45 , & V_46 ) ;
if ( V_15 ) {
F_19 ( & V_45 ) ;
if ( V_15 >= V_16 ) {
V_4 -> error = V_56 ;
V_4 -> V_18 = V_15 ;
} else {
V_4 -> error = V_15 ;
}
V_4 -> V_52 . V_53 . V_57 = V_46 ;
return;
}
V_9 = F_14 ( V_45 . V_58 ) ;
if ( ! V_9 ) {
F_16 ( ERROR , L_5 ) ;
V_4 -> error = V_59 ;
return;
}
for ( V_47 = 0 ; V_47 < V_60 ; V_47 ++ ) {
struct V_10 * V_11 = V_9 -> V_12 ;
V_11 -> V_61 [ V_47 ] . V_62 = V_9 ;
}
V_4 -> V_52 . V_53 . V_63 = V_45 . type ;
V_4 -> V_52 . V_53 . V_30 = V_45 . V_58 ;
V_4 -> error = 0 ;
}
static void F_10 ( struct V_8 * V_9 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
F_19 ( V_9 ) ;
F_20 ( V_9 ) ;
V_4 -> error = 0 ;
}
static short F_18 ( struct V_8 * V_9 ,
T_2 * V_64 )
{
short V_65 = 0 ;
T_2 V_47 = 0 ;
T_2 V_66 = 0 ;
T_2 V_67 = 0 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_11 -> V_68 = V_9 -> V_51 . V_69 [ 0 ] ;
V_11 -> V_70 = V_9 -> V_51 . V_69 [ 1 ] ;
F_16 ( V_48 , L_6 , V_11 -> V_68 ,
V_11 -> V_70 ) ;
for ( V_47 = 0 ; V_47 < V_60 ; V_47 ++ ) {
V_11 -> V_61 [ V_47 ] . V_71 =
V_11 -> V_70 + ( V_72 +
V_73 * V_47 ) ;
V_11 -> V_61 [ V_47 ] . V_74 =
V_11 -> V_70 + ( V_75 +
V_73 * V_47 ) ;
V_11 -> V_61 [ V_47 ] . V_76 =
V_11 -> V_70 + ( V_77 + V_73 * V_47 ) ;
V_11 -> V_61 [ V_47 ] . V_78 =
V_11 -> V_70 + ( V_79 +
V_73 * V_47 ) ;
F_16 ( V_48 , L_7 ,
V_11 -> V_61 [ V_47 ] . V_71 ,
V_11 -> V_61 [ V_47 ] . V_74 ,
V_11 -> V_61 [ V_47 ] . V_76 ,
V_11 -> V_61 [ V_47 ] . V_78 ) ;
V_11 -> V_61 [ V_47 ] . V_62 = V_9 ;
}
V_11 -> V_80 = 0 ;
V_9 -> V_14 = 0 ;
V_11 -> V_81 = 1 ;
V_65 = F_21 ( V_9 , V_64 ) ;
if ( V_65 )
return V_65 ;
F_16 ( V_82 , L_8 ) ;
V_11 -> V_83 = 0L ;
V_11 -> V_84 = 0L ;
{
struct V_1 V_85 ;
struct V_3 V_86 ;
struct V_3 V_87 ;
T_1 error = 0 ;
F_16 ( V_48 , L_9 ) ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . type = V_36 ;
V_85 . V_38 = sizeof( struct V_1 ) ;
V_85 . V_28 = V_37 ;
V_85 . V_5 = V_88 ;
V_85 . V_30 = 0 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_86 . V_38 = sizeof( V_86 ) ;
V_87 . V_38 = sizeof( V_87 ) ;
error = F_22 ( V_9 , 0 , & V_85 , & V_86 ) ;
if ( V_86 . error ) {
F_16 ( V_32 , L_10 , V_86 . error ) ;
return V_86 . error ;
}
if ( V_11 -> V_81 == 2 ) {
error = F_22 ( V_9 , 1 , & V_85 ,
& V_87 ) ;
if ( error )
return error ;
}
V_9 -> type = V_86 . V_52 . V_89 . V_90 . V_63 ;
V_9 -> V_58 = V_86 . V_52 . V_89 . V_90 . V_30 ;
}
memset ( & V_11 -> V_91 [ 0 ] , 0 ,
sizeof( struct V_92 ) *
V_93 ) ;
V_66 =
F_23 ( & V_11 -> V_61 [ 0 ] ,
F_24 ( V_94 ) ) ;
if ( V_66 ) {
V_67 =
F_23 ( & V_11 -> V_61 [ 0 ] ,
F_24 ( V_67 ) ) ;
V_11 -> V_19 =
F_25 ( V_67 ,
V_66 , ( unsigned char * )
& V_11 -> V_91 [ 0 ]
) ;
if ( V_11 -> V_19 )
V_9 -> V_14 = 1 ;
}
F_16 ( V_32 , L_11 , V_9 -> type ,
V_9 -> V_58 ) ;
if ( V_11 -> V_19 )
V_11 -> V_19 -> V_95 = V_9 -> V_58 ;
return F_26 ( V_9 ) ;
}
static void F_19 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
if ( V_9 -> V_14 )
F_27 ( V_11 -> V_19 ) ;
F_28 ( 0x0003000F , V_11 -> V_68 + V_96 ) ;
F_29 ( V_11 ) ;
}
static void F_9 ( struct V_8 * V_9 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
#ifndef F_30
if ( ( V_97 > 0 ) || ( V_98 > 0 ) ) {
V_4 -> V_52 . V_89 . assert . V_99 =
V_97 * 100 + V_98 ;
V_4 -> V_52 . V_89 . assert . V_100 = 0 ;
V_4 -> V_52 . V_89 . assert . V_101 = 1 ;
V_4 -> V_52 . V_89 . assert . V_47 = - 1 ;
strcpy ( V_4 -> V_52 . V_89 . assert . V_102 , L_12 ) ;
V_4 -> V_52 . V_89 . assert . V_103 = 0 ;
V_97 = 0 ;
V_98 = 0 ;
V_4 -> error = 0 ;
} else
#endif
F_6 ( V_9 , V_2 , V_4 ) ;
return;
}
static short F_21 ( struct V_8 * V_9 ,
T_2 * V_64 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
short error ;
T_2 V_104 ;
T_2 V_105 = 0 ;
T_2 V_106 = 0 ;
T_2 V_57 = 0 ;
T_2 V_107 = 0 ;
T_2 V_108 = 0x80000000 ;
T_2 V_109 = 0x00000001 ;
T_2 V_110 = 0 ;
T_2 V_47 = 0 ;
T_2 V_111 = 0 ;
T_2 V_112 = 0 ;
T_2 V_113 = 0 ;
struct V_114 V_114 ;
T_1 V_115 = 0 ;
switch ( V_9 -> V_51 . V_116 -> V_117 ) {
case 0x5100 :
case 0x5110 :
case 0x5200 :
case 0x6100 :
case 0x6200 :
V_115 = F_31 ( 0x6200 ) ;
break;
default:
return V_118 ;
}
V_111 = 0 ;
V_110 = 0x0003000F ;
F_28 ( V_110 , V_11 -> V_68 + V_96 ) ;
F_32 ( 1000 ) ;
V_113 = F_33 ( V_11 -> V_68 + V_96 ) ;
if ( V_113 != V_110 ) {
F_16 ( ERROR , L_13 , V_110 ,
V_113 ) ;
return V_119 ;
}
F_28 ( 0x00000003 , V_11 -> V_68 + V_120 ) ;
F_28 ( 0x60000000 , V_11 -> V_68 + V_121 ) ;
V_110 = V_110 & ( ~ ( V_111 << 3 ) ) ;
F_28 ( V_110 , V_11 -> V_68 + V_96 ) ;
V_11 -> V_61 [ 0 ] . V_122 = 'B' ;
V_11 -> V_61 [ 1 ] . V_122 = 'B' ;
V_110 = V_110 & ( ~ 0x00000001 ) ;
F_28 ( V_110 , V_11 -> V_68 + V_96 ) ;
V_110 = V_110 & ( ~ 0x00000002 ) ;
F_28 ( V_110 , V_11 -> V_68 + V_96 ) ;
V_110 = V_110 & ( ~ 0x00000008 ) ;
F_28 ( V_110 , V_11 -> V_68 + V_96 ) ;
F_32 ( 100 ) ;
for ( V_47 = 0 ; V_47 < V_11 -> V_81 ; V_47 ++ ) {
struct V_123 * V_124 = & V_11 -> V_61 [ V_47 ] ;
F_28 ( 0x00010001 , V_124 -> V_71 ) ;
V_109 = 0x00000001 ;
for ( V_107 = 0 ; V_107 < 32 ; V_107 ++ ) {
F_28 ( V_109 , V_124 -> V_74 ) ;
V_57 = F_33 ( V_124 -> V_74 ) ;
if ( V_57 != V_109 ) {
F_16 ( ERROR , L_14 ,
V_109 , V_57 , V_47 ) ;
return V_125 ;
}
V_109 = V_109 << 1 ;
}
{
F_34 ( V_124 , 0x01B7C100 , 0x0000 ) ;
F_32 ( 100 ) ;
F_34 ( V_124 , 0x01B7C120 , 0x8002 ) ;
F_32 ( 100 ) ;
F_34 ( V_124 , 0x01B7C11C , 0x8001 ) ;
F_32 ( 100 ) ;
F_34 ( V_124 , 0x01B7C118 , 0x8000 ) ;
F_32 ( 2000 ) ;
F_34 ( V_124 , 0x01B7C100 , 0x0001 ) ;
F_32 ( 2000 ) ;
}
for ( V_106 = 0 ; V_106 < 100 ; V_106 ++ ) {
V_108 = 0x00000000 ;
V_109 = 0x00000001 ;
for ( V_107 = 0 ; V_107 < 32 ; V_107 ++ ) {
F_34 ( V_124 , V_108 + V_106 , V_109 ) ;
V_57 = F_23 ( V_124 , V_108 + V_106 ) ;
if ( V_57 != V_109 ) {
F_16 ( ERROR ,
L_15 ,
V_108 + V_106 , V_109 ,
V_57 , V_47 ) ;
return V_126 ;
}
V_109 = V_109 << 1 ;
}
}
F_34 ( V_124 , 0x01800000 , 0x34A8 ) ;
F_34 ( V_124 , 0x01800008 , 0x00000030 ) ;
F_34 ( V_124 , 0x01800020 , 0x001BDF29 ) ;
F_34 ( V_124 , 0x01800018 , 0x47117000 ) ;
F_34 ( V_124 , 0x0180001C , 0x00000410 ) ;
{
T_2 V_127 =
( 1L << 28 ) | ( 3L << 22 ) | ( 1L << 20 ) | ( 1L <<
16 ) | ( 2L << 14 ) | ( 3L << 8 ) | ( 2L << 4 ) | 1L ;
F_34 ( V_124 , 0x01800004 , V_127 ) ;
}
F_32 ( 1000 ) ;
{
V_108 = 0x80000000 ;
V_109 = 0x00000001 ;
for ( V_107 = 0 ; V_107 < 32 ; V_107 ++ ) {
F_34 ( V_124 , V_108 , V_109 ) ;
V_57 = F_23 ( V_124 , V_108 ) ;
if ( V_57 != V_109 ) {
F_16 ( ERROR ,
L_16 ,
V_108 , V_109 , V_57 ,
V_47 ) ;
return V_128 ;
}
V_109 = V_109 << 1 ;
}
#define F_35 0x200000
#define F_36 1024
V_108 = 0x80000000 ;
V_109 = 0x0 ;
for ( V_106 = 0 ; V_106 < F_35 ; V_106 = V_106 + F_36 ) {
F_34 ( V_124 , V_108 + V_106 , V_109 ) ;
V_109 ++ ;
}
V_108 = 0x80000000 ;
V_109 = 0x0 ;
for ( V_106 = 0 ; V_106 < F_35 ; V_106 = V_106 + F_36 ) {
V_57 = F_23 ( V_124 , V_108 + V_106 ) ;
if ( V_57 != V_109 ) {
F_16 ( ERROR ,
L_16 ,
V_108 + V_106 , V_109 ,
V_57 , V_47 ) ;
return V_129 ;
}
V_109 ++ ;
}
}
error = F_37 ( V_115 , V_9 -> V_51 . V_116 ,
& V_114 , V_64 ) ;
if ( error )
return error ;
while ( 1 ) {
T_2 V_130 ;
T_2 V_131 ;
T_2 type ;
T_2 * V_132 ;
error = F_38 ( & V_114 , & V_130 ) ;
if ( error )
break;
if ( V_130 == 0xFFFFFFFF )
break;
error = F_38 ( & V_114 , & V_131 ) ;
if ( error )
break;
error = F_38 ( & V_114 , & type ) ;
if ( error )
break;
error = F_39 ( V_130 , & V_114 ,
& V_132 ) ;
if ( error )
break;
error = F_40 ( V_9 , ( T_1 ) V_47 ,
V_131 , V_132 , V_130 ) ;
if ( error )
break;
}
if ( error ) {
F_41 ( & V_114 ) ;
return error ;
}
F_42 ( & V_114 ) ;
while ( 1 ) {
T_2 V_130 ;
T_2 V_131 ;
T_2 type ;
T_2 * V_132 ;
F_38 ( & V_114 , & V_130 ) ;
if ( V_130 == 0xFFFFFFFF )
break;
F_38 ( & V_114 , & V_131 ) ;
F_38 ( & V_114 , & type ) ;
F_39 ( V_130 , & V_114 , & V_132 ) ;
for ( V_106 = 0 ; V_106 < V_130 ; V_106 ++ ) {
V_57 = F_23 ( V_124 , V_131 ) ;
if ( V_57 != * V_132 ) {
error = V_133 ;
F_16 ( ERROR ,
L_17 ,
V_131 , * V_132 , V_57 ,
V_47 ) ;
break;
}
V_132 ++ ;
V_131 += 4 ;
}
if ( error )
break;
}
F_41 ( & V_114 ) ;
if ( error )
return error ;
{
T_2 V_131 = F_24 ( V_134 ) ;
for ( V_106 = 0 ; V_106 < 4 ; V_106 ++ ) {
F_34 ( V_124 , V_131 , 0 ) ;
V_131 += 4 ;
}
}
F_34 ( V_124 , F_24 ( V_135 ) , V_47 ) ;
if ( V_47 > 0 )
F_34 ( V_124 , F_24 ( V_112 ) ,
V_112 ) ;
F_28 ( 0x00030003 , V_124 -> V_71 ) ;
F_32 ( 10000 ) ;
V_104 = 2000000 ;
while ( V_104 ) {
do {
V_105 = F_23 ( V_124 ,
F_24 ( V_134 ) ) ;
} while ( -- V_104
&& F_43 ( V_9 ,
V_136 ) );
if ( V_105 )
break;
else
F_32 ( 10000 ) ;
}
if ( V_104 == 0 )
return V_137 ;
if ( V_47 == 0 ) {
T_2 V_138 = 0 ;
V_112 =
F_23 ( V_124 ,
F_24 ( V_112 ) ) ;
if ( F_31
( F_44
( V_112 ) ) ==
F_31 ( 0x6200 ) )
V_11 -> V_81 = 2 ;
#define F_45 0x90000000L
switch ( V_115 ) {
case F_31 ( 0x6200 ) :
V_138 = 0xFFFFFF00L ;
if ( F_31 ( V_9 -> V_51 . V_116 ->
V_117 ) ==
F_31 ( 0x5100 ) )
V_138 = 0x00000000L ;
if ( F_31 ( V_9 -> V_51 . V_116 ->
V_117 ) ==
F_31 ( 0x5200 ) )
V_138 = 0x00000000L ;
break;
case F_31 ( 0x8800 ) :
V_138 = 0xFFFF0000L ;
break;
}
V_109 = 0xAAAAAA00L & V_138 ;
F_34 ( V_124 , F_45 + 4L , V_109 ) ;
V_105 = F_23 ( V_124 ,
F_45 + 4L ) & V_138 ;
if ( V_105 != V_109 ) {
F_16 ( ERROR , L_18 , V_109 ,
V_105 ) ;
return V_139 ;
}
V_109 = 0x55555500L & V_138 ;
F_34 ( V_124 , F_45 + 4L , V_109 ) ;
V_105 = F_23 ( V_124 ,
F_45 + 4L ) & V_138 ;
if ( V_105 != V_109 ) {
F_16 ( ERROR , L_18 , V_109 ,
V_105 ) ;
return V_140 ;
}
}
}
return 0 ;
}
static int F_46 ( struct V_123 * V_124 , T_2 V_131 )
{
T_2 V_104 = V_141 ;
do {
F_28 ( V_131 , V_124 -> V_74 ) ;
} while ( F_43 ( V_124 -> V_62 ,
V_142 )
&& -- V_104 );
if ( V_104 )
return 0 ;
return 1 ;
}
static void F_34 ( struct V_123 * V_124 , T_2 V_131 , T_2 V_57 )
{
if ( F_46 ( V_124 , V_131 ) )
return;
F_28 ( V_57 , V_124 -> V_76 ) ;
}
static T_2 F_23 ( struct V_123 * V_124 , T_2 V_131 )
{
T_2 V_57 = 0 ;
if ( F_46 ( V_124 , V_131 ) )
return 0 ;
V_57 = F_33 ( V_124 -> V_76 ) ;
return V_57 ;
}
static void F_47 ( struct V_123 * V_124 , T_2 V_131 , T_2 * V_143 ,
T_2 V_130 )
{
T_1 V_144 = V_130 - 1 ;
if ( V_130 == 0 )
return;
if ( F_46 ( V_124 , V_131 ) )
return;
F_48 ( V_124 -> V_78 , V_143 , V_144 ) ;
F_28 ( * ( V_143 + V_130 - 1 ) , V_124 -> V_76 ) ;
}
static void F_49 ( struct V_123 * V_124 , T_2 V_131 , T_2 * V_143 ,
T_2 V_130 )
{
T_1 V_144 = V_130 - 1 ;
if ( V_130 == 0 )
return;
if ( F_46 ( V_124 , V_131 ) )
return;
F_50 ( V_124 -> V_78 , V_143 , V_144 ) ;
* ( V_143 + V_130 - 1 ) = F_33 ( V_124 -> V_76 ) ;
}
static T_1 F_40 ( struct V_8 * V_9 ,
T_1 V_47 , T_2 V_145 , T_2 * V_146 , T_2 V_101 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_123 * V_124 = & V_11 -> V_61 [ V_47 ] ;
T_2 V_147 = V_141 ;
int V_148 = 128 ;
T_2 V_149 = V_145 ;
int V_150 = V_101 ;
int V_151 ;
T_2 * V_143 = V_146 ;
while ( V_150 ) {
if ( V_150 > V_148 )
V_151 = V_148 ;
else
V_151 = V_150 ;
V_147 = V_141 ;
do {
F_47 ( V_124 , V_149 , V_143 ,
V_151 ) ;
} while ( F_43 ( V_9 , V_142 )
&& -- V_147 );
if ( ! V_147 )
break;
V_143 += V_151 ;
V_149 += sizeof( T_2 ) * V_151 ;
V_150 -= V_151 ;
}
if ( V_147 )
return 0 ;
else
return 1 ;
}
static T_1 F_51 ( struct V_8 * V_9 ,
T_1 V_47 , T_2 V_145 , T_2 * V_152 , T_2 V_101 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_123 * V_124 = & V_11 -> V_61 [ V_47 ] ;
T_2 V_147 = V_141 ;
int V_148 = 16 ;
T_2 V_149 = V_145 ;
int V_150 = V_101 ;
int V_151 ;
T_2 * V_143 = V_152 ;
T_2 V_153 = 0 ;
while ( V_150 ) {
if ( V_150 > V_148 )
V_151 = V_148 ;
else
V_151 = V_150 ;
V_147 = V_141 ;
do {
F_49 ( V_124 , V_149 , V_143 ,
V_151 ) ;
} while ( F_43 ( V_9 , V_136 )
&& -- V_147 );
if ( ! V_147 )
break;
V_143 += V_151 ;
V_149 += sizeof( T_2 ) * V_151 ;
V_150 -= V_151 ;
V_153 ++ ;
}
if ( V_147 )
return 0 ;
else
return 1 ;
}
static short F_22 ( struct V_8 * V_9 ,
T_1 V_47 , struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_123 * V_124 = & V_11 -> V_61 [ V_47 ] ;
T_2 V_104 ;
T_1 V_154 ;
T_2 V_131 ;
T_2 V_130 ;
T_2 * V_155 ;
T_1 error = 0 ;
V_154 = F_52 ( V_9 , V_47 , V_156 ) ;
if ( V_154 & V_157 ) {
V_9 -> V_33 ++ ;
return V_158 ;
}
V_9 -> V_33 = 0 ;
if ( V_11 -> V_83 == 0 ) {
V_104 = V_159 ;
do {
V_131 =
F_23 ( V_124 ,
F_24 ( V_160 ) ) ;
V_11 -> V_83 = V_131 ;
} while ( F_43 ( V_9 , V_136 )
&& -- V_104 );
if ( ! V_104 )
return V_161 ;
} else
V_131 = V_11 -> V_83 ;
V_130 = V_2 -> V_38 ;
V_155 = ( T_2 * ) V_2 ;
if ( F_40 ( V_9 , V_47 , V_131 , V_155 ,
( T_1 ) V_130 / 4 ) )
return V_162 ;
if ( F_53 ( V_9 , V_47 , V_163 ) )
return V_164 ;
F_54 ( V_124 ) ;
V_154 = F_52 ( V_9 , V_47 , V_163 ) ;
if ( V_154 & V_157 )
return V_165 ;
if ( V_11 -> V_84 == 0 ) {
V_104 = V_159 ;
do {
V_131 =
F_23 ( V_124 ,
F_24 ( V_166 ) ) ;
} while ( F_43 ( V_9 , V_136 )
&& -- V_104 );
V_11 -> V_84 = V_131 ;
if ( ! V_104 )
return V_167 ;
} else
V_131 = V_11 -> V_84 ;
V_104 = V_159 ;
do {
V_130 = F_23 ( V_124 , F_24 ( V_130 ) ) ;
} while ( F_43 ( V_9 , V_136 ) && -- V_104 );
if ( ! V_104 )
return V_168 ;
if ( V_130 > V_4 -> V_38 )
return V_169 ;
V_155 = ( T_2 * ) V_4 ;
if ( F_51 ( V_9 , V_47 , V_131 , V_155 ,
( T_1 ) V_130 / 4 ) )
return V_170 ;
if ( F_53 ( V_9 , V_47 , V_156 ) )
return V_171 ;
F_54 ( V_124 ) ;
error = F_55 ( V_2 , V_4 ) ;
return error ;
}
static short F_56 ( T_2 V_131 , T_2 V_172 )
{
#ifdef F_57
if ( V_131 < ( T_2 ) V_173 )
return 0 ;
if ( V_131 > ( T_2 ) ( V_174 + V_175 ) )
return 0 ;
if ( ( V_131 + ( V_172 << 2 ) ) >
( T_2 ) ( V_174 + V_175 ) )
return 0 ;
#else
( void ) V_131 ;
( void ) V_172 ;
return 1 ;
#endif
}
static short F_58 ( struct V_8 * V_9 , T_1 V_47 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_123 * V_124 = & V_11 -> V_61 [ V_47 ] ;
T_2 V_176 = 0 ;
T_1 V_154 ;
T_2 V_130 , V_131 ;
T_2 * V_155 = ( T_2 * ) V_2 -> V_52 . V_177 . V_52 . V_57 . V_178 ;
T_1 V_147 = 8 ;
( void ) V_4 ;
while ( ( V_176 < ( V_2 -> V_52 . V_177 . V_52 . V_57 . V_179 & ~ 3L ) )
&& -- V_147 ) {
V_154 = F_52 ( V_9 , V_47 , V_156 ) ;
if ( V_154 & V_157 )
return V_180 ;
if ( F_53 ( V_9 , V_47 ,
V_181 ) )
return V_182 ;
F_54 ( V_124 ) ;
V_154 = F_52 ( V_9 , V_47 , V_181 ) ;
if ( V_154 & V_157 )
return V_183 ;
do {
V_131 = F_23 ( V_124 , F_24 ( V_131 ) ) ;
V_130 = F_23 ( V_124 , F_24 ( V_130 ) ) ;
} while ( F_43 ( V_9 , V_136 ) );
if ( ! F_56 ( V_131 , V_130 ) )
return V_184 ;
{
T_2 V_185 = V_130 ;
T_2 V_186 = 512 ;
while ( V_185 ) {
if ( V_185 < V_186 )
V_186 = V_185 ;
if ( F_40 ( V_9 , V_47 ,
V_131 , V_155 , V_186 ) )
return V_187 ;
V_131 += V_186 * 4 ;
V_155 += V_186 ;
V_185 -= V_186 ;
}
}
if ( F_53 ( V_9 , V_47 , V_156 ) )
return V_188 ;
F_54 ( V_124 ) ;
V_176 += V_130 * 4 ;
}
if ( ! V_147 )
return V_189 ;
return 0 ;
}
static short F_59 ( struct V_8 * V_9 , T_1 V_47 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_123 * V_124 = & V_11 -> V_61 [ V_47 ] ;
T_2 V_190 = 0 ;
T_1 V_154 ;
T_2 V_130 , V_131 ;
T_2 * V_155 = ( T_2 * ) V_2 -> V_52 . V_177 . V_52 . V_57 . V_178 ;
( void ) V_4 ;
while ( V_190 < ( V_2 -> V_52 . V_177 . V_52 . V_57 . V_179 & ~ 3L ) ) {
V_154 = F_52 ( V_9 , V_47 , V_156 ) ;
if ( V_154 & V_157 )
return V_191 ;
if ( F_53 ( V_9 , V_47 ,
V_192 ) )
return V_193 ;
F_54 ( V_124 ) ;
V_154 = F_52 ( V_9 , V_47 , V_192 ) ;
if ( V_154 & V_157 )
return V_194 ;
do {
V_131 = F_23 ( V_124 , F_24 ( V_131 ) ) ;
V_130 = F_23 ( V_124 , F_24 ( V_130 ) ) ;
} while ( F_43 ( V_9 , V_136 ) );
{
T_2 V_185 = V_130 ;
T_2 V_186 = 512 ;
while ( V_185 ) {
if ( V_185 < V_186 )
V_186 = V_185 ;
if ( F_51 ( V_9 , V_47 ,
V_131 , V_155 , V_186 ) )
return V_195 ;
V_131 += V_186 * 4 ;
V_155 += V_186 ;
V_185 -= V_186 ;
}
}
if ( F_53 ( V_9 , V_47 , V_156 ) )
return V_196 ;
F_54 ( V_124 ) ;
V_190 += V_130 * 4 ;
}
return 0 ;
}
static void F_54 ( struct V_123 * V_124 )
{
F_28 ( 0x00030003 , V_124 -> V_71 ) ;
}
static short F_53 ( struct V_8 * V_9 ,
T_1 V_47 , T_2 V_134 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_123 * V_124 = & V_11 -> V_61 [ V_47 ] ;
T_2 V_104 = V_159 ;
do {
F_34 ( V_124 , F_24 ( V_134 ) , V_134 ) ;
F_46 ( V_124 , F_24 ( V_134 ) ) ;
} while ( F_43 ( V_9 , V_142 ) && -- V_104 );
F_28 ( 0x00040004 , V_124 -> V_71 ) ;
if ( V_104 )
return 0 ;
else
return 1 ;
}
static short F_43 ( struct V_8 * V_9 ,
T_1 V_197 )
{
T_2 V_198 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_198 = F_33 ( V_11 -> V_68 + V_199 ) ;
if ( V_198 ) {
F_28 ( 0L , V_11 -> V_68 + V_199 ) ;
V_11 -> V_80 ++ ;
if ( V_197 == 1 )
V_97 ++ ;
else
V_98 ++ ;
return 1 ;
} else
return 0 ;
}
static short F_52 ( struct V_8 * V_9 , T_1 V_47 ,
T_2 V_200 )
{
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_123 * V_124 = & V_11 -> V_61 [ V_47 ] ;
T_2 V_154 = 0L ;
T_2 V_104 ;
T_2 V_201 = 0L ;
V_104 = V_159 ;
while ( -- V_104 ) {
V_201 = F_33 ( V_124 -> V_71 ) ;
if ( V_201 & 0x04 )
break;
}
if ( V_104 == 0 )
return V_157 ;
V_104 = V_159 ;
while ( -- V_104 ) {
V_154 = F_23 ( V_124 , F_24 ( V_202 ) ) ;
if ( V_154 == V_200 )
break;
if ( ( V_154 & V_157 )
&& ! F_43 ( V_9 , V_136 ) )
break;
}
if ( V_154 & V_157 )
V_154 = V_157 ;
if ( V_104 == 0 )
V_154 = V_157 ;
return ( short ) V_154 ;
}
static short F_4 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
const T_1 V_47 = 0 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_123 * V_124 = & V_11 -> V_61 [ V_47 ] ;
T_2 V_104 ;
T_2 V_203 ;
T_1 V_15 ;
F_60 ( V_9 ) ;
V_104 = V_159 ;
do {
V_203 =
F_23 ( (struct V_123 * ) V_124 ,
F_24 ( V_204 ) ) ;
} while ( F_43 ( V_9 , V_136 ) && -- V_104 );
if ( ! V_104 ) {
V_15 = V_205 ;
goto V_206;
}
if ( V_203 ) {
T_2 V_131 ;
T_2 V_130 ;
V_104 = V_159 ;
if ( V_124 -> V_207 == 0 ) {
do {
V_131 =
F_23 ( (struct V_123 * ) V_124 ,
F_24 ( V_208 ) ) ;
V_130 = F_23 ( (struct V_123 * ) V_124 ,
F_24
( V_94 ) ) ;
} while ( F_43 ( V_9 , V_136 )
&& -- V_104 );
if ( ! V_104 ) {
V_15 = V_209 ;
goto V_206;
}
V_124 -> V_207 = V_131 ;
V_124 -> V_210 = V_130 ;
} else {
V_131 = V_124 -> V_207 ;
V_130 = V_124 -> V_210 ;
}
if ( F_51 ( V_9 , V_47 , V_131 ,
( T_2 * ) & V_11 -> V_91 [ 0 ] ,
V_130 / sizeof( T_2 ) ) ) {
V_15 = V_211 ;
goto V_206;
}
do {
F_34 ( (struct V_123 * ) V_124 ,
F_24 ( V_204 ) , 0 ) ;
F_46 ( V_124 , F_24 ( V_134 ) ) ;
} while ( F_43 ( V_9 , V_142 )
&& -- V_104 );
if ( ! V_104 ) {
V_15 = V_212 ;
goto V_206;
}
}
V_15 = 0 ;
V_206:
F_61 ( V_9 ) ;
return V_15 ;
}
static T_1 F_62 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
T_1 V_213 = 0 ;
switch ( V_2 -> V_28 ) {
case V_43 :
if ( V_2 -> V_214 < 2 )
V_213 = 1 ;
break;
case V_215 :
V_213 = V_2 -> V_214 ;
break;
default:
break;
}
return V_213 ;
}
static void F_6 ( struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 error = 0 ;
T_1 V_47 = 0 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_81 = V_11 -> V_81 ;
if ( V_81 < 2 )
V_47 = 0 ;
else {
V_47 = F_62 ( V_9 , V_2 ) ;
if ( ( V_2 -> V_5 == V_216 )
|| ( V_2 -> V_5 == V_217 ) ) {
struct V_1 V_85 ;
T_1 V_218 ;
V_85 . V_214 = V_2 -> V_52 . V_177 . V_52 . V_219 . V_220 ;
V_85 . V_28 = V_2 -> V_52 . V_177 . V_52 . V_219 . V_221 ;
V_218 = F_62 ( V_9 , & V_85 ) ;
if ( V_218 != V_47 ) {
V_4 -> error = V_222 ;
return;
}
}
}
F_60 ( V_9 ) ;
error = F_22 ( V_9 , V_47 , V_2 , V_4 ) ;
if ( error )
goto V_15;
if ( V_4 -> error )
goto V_223;
switch ( V_2 -> V_5 ) {
case V_224 :
case V_225 :
error = F_58 ( V_9 , V_47 , V_2 , V_4 ) ;
break;
case V_226 :
case V_227 :
error = F_59 ( V_9 , V_47 , V_2 , V_4 ) ;
break;
case V_22 :
V_4 -> V_52 . V_89 . assert . V_47 = 0 ;
if ( V_81 == 2 ) {
if ( ! V_4 -> V_52 . V_89 . assert . V_101 ) {
error = F_22 ( V_9 ,
1 , V_2 , V_4 ) ;
V_4 -> V_52 . V_89 . assert . V_47 = 1 ;
}
}
}
V_15:
if ( error ) {
if ( error >= V_16 ) {
V_4 -> error = V_228 ;
V_4 -> V_18 = error ;
} else {
V_4 -> error = error ;
}
V_4 -> V_38 = sizeof( struct V_39 ) ;
}
V_223:
F_61 ( V_9 ) ;
return;
}
