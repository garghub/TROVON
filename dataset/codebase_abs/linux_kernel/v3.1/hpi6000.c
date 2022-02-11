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
switch ( V_2 -> V_5 ) {
case V_10 :
if ( V_9 -> V_11 ) {
T_1 V_12 ;
V_12 = F_4 ( V_9 , V_2 ) ;
if ( V_12 ) {
if ( V_12 >= V_13 ) {
V_4 -> error =
V_14 ;
V_4 -> V_15 = V_12 ;
} else {
V_4 -> error = V_12 ;
}
break;
}
if ( F_5 ( ( (struct V_16 * )
V_9 -> V_17 ) -> V_18 , V_2 ,
V_4 ) )
break;
}
F_6 ( V_9 , V_2 , V_4 ) ;
break;
case V_19 :
F_6 ( V_9 , V_2 , V_4 ) ;
F_7 ( ( (struct V_16 * ) V_9 ->
V_17 ) -> V_18 , V_2 , V_4 ) ;
break;
case V_20 :
default:
F_6 ( V_9 , V_2 , V_4 ) ;
break;
}
}
static void F_8 ( struct V_8 * V_9 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
switch ( V_2 -> V_5 ) {
case V_21 :
F_9 ( V_9 , V_2 , V_4 ) ;
break;
case V_22 :
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
case V_23 :
case V_24 :
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
case V_25 :
case V_26 :
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
if ( V_2 -> V_27 != V_28 ) {
V_9 = F_14 ( V_2 -> V_29 ) ;
if ( ! V_9 ) {
F_15 ( V_4 , V_2 -> V_27 , V_2 -> V_5 ,
V_30 ) ;
F_16 ( V_31 , L_1 ,
V_2 -> V_29 ) ;
return;
}
if ( V_9 -> V_32 >= 10 ) {
F_15 ( V_4 , V_2 -> V_27 , V_2 -> V_5 ,
V_33 ) ;
F_16 ( V_31 , L_2 ,
V_2 -> V_29 ) ;
return;
}
}
if ( V_2 -> V_5 != V_6 )
F_15 ( V_4 , V_2 -> V_27 , V_2 -> V_5 ,
V_34 ) ;
switch ( V_2 -> type ) {
case V_35 :
switch ( V_2 -> V_27 ) {
case V_28 :
F_1 ( V_2 , V_4 ) ;
break;
case V_36 :
V_4 -> V_37 =
sizeof( struct V_38 ) +
sizeof( struct V_39 ) ;
F_8 ( V_9 , V_2 , V_4 ) ;
break;
case V_40 :
F_3 ( V_9 , V_2 , V_4 ) ;
break;
case V_41 :
F_11 ( V_9 , V_2 , V_4 ) ;
break;
case V_42 :
F_12 ( V_9 , V_2 , V_4 ) ;
break;
default:
F_6 ( V_9 , V_2 , V_4 ) ;
break;
}
break;
default:
V_4 -> error = V_43 ;
break;
}
}
static void F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 V_44 ;
struct V_8 * V_9 ;
T_2 V_45 ;
T_1 V_12 = 0 ;
T_2 V_46 = 0 ;
F_16 ( V_47 , L_3 ) ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_17 = F_17 ( sizeof( struct V_16 ) , V_48 ) ;
if ( ! V_44 . V_17 ) {
F_16 ( ERROR , L_4 ) ;
V_4 -> error = V_49 ;
return;
}
V_44 . V_50 = * V_2 -> V_51 . V_52 . V_53 . V_54 . V_50 ;
V_12 = F_18 ( & V_44 , & V_45 ) ;
if ( V_12 ) {
F_19 ( & V_44 ) ;
if ( V_12 >= V_13 ) {
V_4 -> error = V_55 ;
V_4 -> V_15 = V_12 ;
} else {
V_4 -> error = V_12 ;
}
V_4 -> V_51 . V_52 . V_56 = V_45 ;
return;
}
V_9 = F_14 ( V_44 . V_57 ) ;
if ( ! V_9 ) {
F_16 ( ERROR , L_5 ) ;
V_4 -> error = V_58 ;
return;
}
for ( V_46 = 0 ; V_46 < V_59 ; V_46 ++ ) {
struct V_16 * V_60 = (struct V_16 * ) V_9 -> V_17 ;
V_60 -> V_61 [ V_46 ] . V_62 = V_9 ;
}
V_4 -> V_51 . V_52 . V_63 = V_44 . V_63 ;
V_4 -> V_51 . V_52 . V_29 = V_44 . V_57 ;
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
T_2 V_46 = 0 ;
T_2 V_66 = 0 ;
T_2 V_67 = 0 ;
struct V_16 * V_60 = (struct V_16 * ) V_9 -> V_17 ;
V_60 -> V_68 = V_9 -> V_50 . V_69 [ 0 ] ;
V_60 -> V_70 = V_9 -> V_50 . V_69 [ 1 ] ;
F_16 ( V_47 , L_6 , V_60 -> V_68 ,
V_60 -> V_70 ) ;
for ( V_46 = 0 ; V_46 < V_59 ; V_46 ++ ) {
V_60 -> V_61 [ V_46 ] . V_71 =
V_60 -> V_70 + ( V_72 +
V_73 * V_46 ) ;
V_60 -> V_61 [ V_46 ] . V_74 =
V_60 -> V_70 + ( V_75 +
V_73 * V_46 ) ;
V_60 -> V_61 [ V_46 ] . V_76 =
V_60 -> V_70 + ( V_77 + V_73 * V_46 ) ;
V_60 -> V_61 [ V_46 ] . V_78 =
V_60 -> V_70 + ( V_79 +
V_73 * V_46 ) ;
F_16 ( V_47 , L_7 ,
V_60 -> V_61 [ V_46 ] . V_71 ,
V_60 -> V_61 [ V_46 ] . V_74 ,
V_60 -> V_61 [ V_46 ] . V_76 ,
V_60 -> V_61 [ V_46 ] . V_78 ) ;
V_60 -> V_61 [ V_46 ] . V_62 = V_9 ;
}
V_60 -> V_80 = 0 ;
V_9 -> V_11 = 0 ;
V_60 -> V_81 = 1 ;
V_65 = F_21 ( V_9 , V_64 ) ;
if ( V_65 )
return V_65 ;
F_16 ( V_82 , L_8 ) ;
V_60 -> V_83 = 0L ;
V_60 -> V_84 = 0L ;
{
struct V_1 V_85 ;
struct V_3 V_86 ;
struct V_3 V_87 ;
T_1 error = 0 ;
F_16 ( V_47 , L_9 ) ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . type = V_35 ;
V_85 . V_37 = sizeof( struct V_1 ) ;
V_85 . V_27 = V_36 ;
V_85 . V_5 = V_88 ;
V_85 . V_29 = 0 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_86 . V_37 = sizeof( V_86 ) ;
V_87 . V_37 = sizeof( V_87 ) ;
error = F_22 ( V_9 , 0 , & V_85 , & V_86 ) ;
if ( V_86 . error ) {
F_16 ( V_31 , L_10 , V_86 . error ) ;
return V_86 . error ;
}
if ( V_60 -> V_81 == 2 ) {
error = F_22 ( V_9 , 1 , & V_85 ,
& V_87 ) ;
if ( error )
return error ;
}
V_9 -> V_63 = V_86 . V_51 . V_89 . V_90 . V_63 ;
V_9 -> V_57 = V_86 . V_51 . V_89 . V_90 . V_29 ;
}
memset ( & V_60 -> V_91 [ 0 ] , 0 ,
sizeof( struct V_92 ) *
V_93 ) ;
V_66 =
F_23 ( & V_60 -> V_61 [ 0 ] ,
F_24 ( V_94 ) ) ;
if ( V_66 ) {
V_67 =
F_23 ( & V_60 -> V_61 [ 0 ] ,
F_24 ( V_67 ) ) ;
V_60 -> V_18 =
F_25 ( V_67 ,
V_66 , ( unsigned char * )
& V_60 -> V_91 [ 0 ]
) ;
if ( V_60 -> V_18 )
V_9 -> V_11 = 1 ;
}
F_16 ( V_31 , L_11 ,
V_9 -> V_63 , V_9 -> V_57 ) ;
V_9 -> V_95 = 0 ;
if ( V_60 -> V_18 )
V_60 -> V_18 -> V_96 = V_9 -> V_57 ;
return F_26 ( V_9 ) ;
}
static void F_19 ( struct V_8 * V_9 )
{
struct V_16 * V_60 = (struct V_16 * ) V_9 -> V_17 ;
if ( V_9 -> V_11 )
F_27 ( V_60 -> V_18 ) ;
F_28 ( 0x0003000F , V_60 -> V_68 + V_97 ) ;
F_29 ( V_60 ) ;
}
static void F_9 ( struct V_8 * V_9 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
#ifndef F_30
if ( ( V_98 > 0 ) || ( V_99 > 0 ) ) {
V_4 -> V_51 . V_89 . assert . V_100 =
V_98 * 100 + V_99 ;
V_4 -> V_51 . V_89 . assert . V_101 = 0 ;
V_4 -> V_51 . V_89 . assert . V_102 = 1 ;
V_4 -> V_51 . V_89 . assert . V_46 = - 1 ;
strcpy ( V_4 -> V_51 . V_89 . assert . V_103 , L_12 ) ;
V_4 -> V_51 . V_89 . assert . V_104 = 0 ;
V_98 = 0 ;
V_99 = 0 ;
V_4 -> error = 0 ;
} else
#endif
F_6 ( V_9 , V_2 , V_4 ) ;
return;
}
static short F_21 ( struct V_8 * V_9 ,
T_2 * V_64 )
{
struct V_16 * V_60 = (struct V_16 * ) V_9 -> V_17 ;
short error ;
T_2 V_105 ;
T_2 V_106 = 0 ;
T_2 V_107 = 0 ;
T_2 V_56 = 0 ;
T_2 V_108 = 0 ;
T_2 V_109 = 0x80000000 ;
T_2 V_110 = 0x00000001 ;
T_2 V_111 = 0 ;
T_2 V_46 = 0 ;
T_2 V_112 = 0 ;
T_2 V_113 = 0 ;
T_2 V_114 = 0 ;
struct V_115 V_115 ;
T_1 V_116 = 0 ;
switch ( V_9 -> V_50 . V_117 -> V_118 ) {
case 0x5100 :
case 0x5110 :
case 0x5200 :
case 0x6100 :
case 0x6200 :
V_116 = F_31 ( 0x6200 ) ;
break;
default:
return V_119 ;
}
V_112 = 0 ;
V_111 = 0x0003000F ;
F_28 ( V_111 , V_60 -> V_68 + V_97 ) ;
F_32 ( 1000 ) ;
V_114 = F_33 ( V_60 -> V_68 + V_97 ) ;
if ( V_114 != V_111 ) {
F_16 ( ERROR , L_13 , V_111 ,
V_114 ) ;
return V_120 ;
}
F_28 ( 0x00000003 , V_60 -> V_68 + V_121 ) ;
F_28 ( 0x60000000 , V_60 -> V_68 + V_122 ) ;
V_111 = V_111 & ( ~ ( V_112 << 3 ) ) ;
F_28 ( V_111 , V_60 -> V_68 + V_97 ) ;
V_60 -> V_61 [ 0 ] . V_123 = 'B' ;
V_60 -> V_61 [ 1 ] . V_123 = 'B' ;
V_111 = V_111 & ( ~ 0x00000001 ) ;
F_28 ( V_111 , V_60 -> V_68 + V_97 ) ;
V_111 = V_111 & ( ~ 0x00000002 ) ;
F_28 ( V_111 , V_60 -> V_68 + V_97 ) ;
V_111 = V_111 & ( ~ 0x00000008 ) ;
F_28 ( V_111 , V_60 -> V_68 + V_97 ) ;
F_32 ( 100 ) ;
for ( V_46 = 0 ; V_46 < V_60 -> V_81 ; V_46 ++ ) {
struct V_124 * V_125 = & V_60 -> V_61 [ V_46 ] ;
F_28 ( 0x00010001 , V_125 -> V_71 ) ;
V_110 = 0x00000001 ;
for ( V_108 = 0 ; V_108 < 32 ; V_108 ++ ) {
F_28 ( V_110 , V_125 -> V_74 ) ;
V_56 = F_33 ( V_125 -> V_74 ) ;
if ( V_56 != V_110 ) {
F_16 ( ERROR , L_14 ,
V_110 , V_56 , V_46 ) ;
return V_126 ;
}
V_110 = V_110 << 1 ;
}
{
F_34 ( V_125 , 0x01B7C100 , 0x0000 ) ;
F_32 ( 100 ) ;
F_34 ( V_125 , 0x01B7C120 , 0x8002 ) ;
F_32 ( 100 ) ;
F_34 ( V_125 , 0x01B7C11C , 0x8001 ) ;
F_32 ( 100 ) ;
F_34 ( V_125 , 0x01B7C118 , 0x8000 ) ;
F_32 ( 2000 ) ;
F_34 ( V_125 , 0x01B7C100 , 0x0001 ) ;
F_32 ( 2000 ) ;
}
for ( V_107 = 0 ; V_107 < 100 ; V_107 ++ ) {
V_109 = 0x00000000 ;
V_110 = 0x00000001 ;
for ( V_108 = 0 ; V_108 < 32 ; V_108 ++ ) {
F_34 ( V_125 , V_109 + V_107 , V_110 ) ;
V_56 = F_23 ( V_125 , V_109 + V_107 ) ;
if ( V_56 != V_110 ) {
F_16 ( ERROR ,
L_15 ,
V_109 + V_107 , V_110 ,
V_56 , V_46 ) ;
return V_127 ;
}
V_110 = V_110 << 1 ;
}
}
F_34 ( V_125 , 0x01800000 , 0x34A8 ) ;
F_34 ( V_125 , 0x01800008 , 0x00000030 ) ;
F_34 ( V_125 , 0x01800020 , 0x001BDF29 ) ;
F_34 ( V_125 , 0x01800018 , 0x47117000 ) ;
F_34 ( V_125 , 0x0180001C , 0x00000410 ) ;
{
T_2 V_128 =
( 1L << 28 ) | ( 3L << 22 ) | ( 1L << 20 ) | ( 1L <<
16 ) | ( 2L << 14 ) | ( 3L << 8 ) | ( 2L << 4 ) | 1L ;
F_34 ( V_125 , 0x01800004 , V_128 ) ;
}
F_32 ( 1000 ) ;
{
V_109 = 0x80000000 ;
V_110 = 0x00000001 ;
for ( V_108 = 0 ; V_108 < 32 ; V_108 ++ ) {
F_34 ( V_125 , V_109 , V_110 ) ;
V_56 = F_23 ( V_125 , V_109 ) ;
if ( V_56 != V_110 ) {
F_16 ( ERROR ,
L_16 ,
V_109 , V_110 , V_56 ,
V_46 ) ;
return V_129 ;
}
V_110 = V_110 << 1 ;
}
#define F_35 0x200000
#define F_36 1024
V_109 = 0x80000000 ;
V_110 = 0x0 ;
for ( V_107 = 0 ; V_107 < F_35 ; V_107 = V_107 + F_36 ) {
F_34 ( V_125 , V_109 + V_107 , V_110 ) ;
V_110 ++ ;
}
V_109 = 0x80000000 ;
V_110 = 0x0 ;
for ( V_107 = 0 ; V_107 < F_35 ; V_107 = V_107 + F_36 ) {
V_56 = F_23 ( V_125 , V_109 + V_107 ) ;
if ( V_56 != V_110 ) {
F_16 ( ERROR ,
L_16 ,
V_109 + V_107 , V_110 ,
V_56 , V_46 ) ;
return V_130 ;
}
V_110 ++ ;
}
}
error = F_37 ( V_116 , V_9 -> V_50 . V_117 ,
& V_115 , V_64 ) ;
if ( error )
return error ;
while ( 1 ) {
T_2 V_131 ;
T_2 V_132 ;
T_2 type ;
T_2 * V_133 ;
error = F_38 ( & V_115 , & V_131 ) ;
if ( error )
break;
if ( V_131 == 0xFFFFFFFF )
break;
error = F_38 ( & V_115 , & V_132 ) ;
if ( error )
break;
error = F_38 ( & V_115 , & type ) ;
if ( error )
break;
error = F_39 ( V_131 , & V_115 ,
& V_133 ) ;
if ( error )
break;
error = F_40 ( V_9 , ( T_1 ) V_46 ,
V_132 , V_133 , V_131 ) ;
if ( error )
break;
}
if ( error ) {
F_41 ( & V_115 ) ;
return error ;
}
F_42 ( & V_115 ) ;
while ( 1 ) {
T_2 V_131 ;
T_2 V_132 ;
T_2 type ;
T_2 * V_133 ;
F_38 ( & V_115 , & V_131 ) ;
if ( V_131 == 0xFFFFFFFF )
break;
F_38 ( & V_115 , & V_132 ) ;
F_38 ( & V_115 , & type ) ;
F_39 ( V_131 , & V_115 , & V_133 ) ;
for ( V_107 = 0 ; V_107 < V_131 ; V_107 ++ ) {
V_56 = F_23 ( V_125 , V_132 ) ;
if ( V_56 != * V_133 ) {
error = V_134 ;
F_16 ( ERROR ,
L_17 ,
V_132 , * V_133 , V_56 ,
V_46 ) ;
break;
}
V_133 ++ ;
V_132 += 4 ;
}
if ( error )
break;
}
F_41 ( & V_115 ) ;
if ( error )
return error ;
{
T_2 V_132 = F_24 ( V_135 ) ;
for ( V_107 = 0 ; V_107 < 4 ; V_107 ++ ) {
F_34 ( V_125 , V_132 , 0 ) ;
V_132 += 4 ;
}
}
F_34 ( V_125 , F_24 ( V_136 ) , V_46 ) ;
if ( V_46 > 0 )
F_34 ( V_125 , F_24 ( V_113 ) ,
V_113 ) ;
F_28 ( 0x00030003 , V_125 -> V_71 ) ;
F_32 ( 10000 ) ;
V_105 = 2000000 ;
while ( V_105 ) {
do {
V_106 = F_23 ( V_125 ,
F_24 ( V_135 ) ) ;
} while ( -- V_105
&& F_43 ( V_9 ,
V_137 ) );
if ( V_106 )
break;
else
F_32 ( 10000 ) ;
}
if ( V_105 == 0 )
return V_138 ;
if ( V_46 == 0 ) {
T_2 V_139 = 0 ;
V_113 =
F_23 ( V_125 ,
F_24 ( V_113 ) ) ;
if ( F_31
( F_44
( V_113 ) ) ==
F_31 ( 0x6200 ) )
V_60 -> V_81 = 2 ;
#define F_45 0x90000000L
switch ( V_116 ) {
case F_31 ( 0x6200 ) :
V_139 = 0xFFFFFF00L ;
if ( F_31 ( V_9 -> V_50 . V_117 ->
V_118 ) ==
F_31 ( 0x5100 ) )
V_139 = 0x00000000L ;
if ( F_31 ( V_9 -> V_50 . V_117 ->
V_118 ) ==
F_31 ( 0x5200 ) )
V_139 = 0x00000000L ;
break;
case F_31 ( 0x8800 ) :
V_139 = 0xFFFF0000L ;
break;
}
V_110 = 0xAAAAAA00L & V_139 ;
F_34 ( V_125 , F_45 + 4L , V_110 ) ;
V_106 = F_23 ( V_125 ,
F_45 + 4L ) & V_139 ;
if ( V_106 != V_110 ) {
F_16 ( ERROR , L_18 , V_110 ,
V_106 ) ;
return V_140 ;
}
V_110 = 0x55555500L & V_139 ;
F_34 ( V_125 , F_45 + 4L , V_110 ) ;
V_106 = F_23 ( V_125 ,
F_45 + 4L ) & V_139 ;
if ( V_106 != V_110 ) {
F_16 ( ERROR , L_18 , V_110 ,
V_106 ) ;
return V_141 ;
}
}
}
return 0 ;
}
static int F_46 ( struct V_124 * V_125 , T_2 V_132 )
{
T_2 V_105 = V_142 ;
do {
F_28 ( V_132 , V_125 -> V_74 ) ;
} while ( F_43 ( V_125 -> V_62 ,
V_143 )
&& -- V_105 );
if ( V_105 )
return 0 ;
return 1 ;
}
static void F_34 ( struct V_124 * V_125 , T_2 V_132 , T_2 V_56 )
{
if ( F_46 ( V_125 , V_132 ) )
return;
F_28 ( V_56 , V_125 -> V_76 ) ;
}
static T_2 F_23 ( struct V_124 * V_125 , T_2 V_132 )
{
T_2 V_56 = 0 ;
if ( F_46 ( V_125 , V_132 ) )
return 0 ;
V_56 = F_33 ( V_125 -> V_76 ) ;
return V_56 ;
}
static void F_47 ( struct V_124 * V_125 , T_2 V_132 , T_2 * V_144 ,
T_2 V_131 )
{
T_1 V_145 = V_131 - 1 ;
if ( V_131 == 0 )
return;
if ( F_46 ( V_125 , V_132 ) )
return;
F_48 ( V_125 -> V_78 , V_144 , V_145 ) ;
F_28 ( * ( V_144 + V_131 - 1 ) , V_125 -> V_76 ) ;
}
static void F_49 ( struct V_124 * V_125 , T_2 V_132 , T_2 * V_144 ,
T_2 V_131 )
{
T_1 V_145 = V_131 - 1 ;
if ( V_131 == 0 )
return;
if ( F_46 ( V_125 , V_132 ) )
return;
F_50 ( V_125 -> V_78 , V_144 , V_145 ) ;
* ( V_144 + V_131 - 1 ) = F_33 ( V_125 -> V_76 ) ;
}
static T_1 F_40 ( struct V_8 * V_9 ,
T_1 V_46 , T_2 V_146 , T_2 * V_147 , T_2 V_102 )
{
struct V_124 * V_125 =
& ( * (struct V_16 * ) V_9 -> V_17 ) . V_61 [ V_46 ] ;
T_2 V_148 = V_142 ;
int V_149 = 128 ;
T_2 V_150 = V_146 ;
int V_151 = V_102 ;
int V_152 ;
T_2 * V_144 = V_147 ;
while ( V_151 ) {
if ( V_151 > V_149 )
V_152 = V_149 ;
else
V_152 = V_151 ;
V_148 = V_142 ;
do {
F_47 ( V_125 , V_150 , V_144 ,
V_152 ) ;
} while ( F_43 ( V_9 , V_143 )
&& -- V_148 );
if ( ! V_148 )
break;
V_144 += V_152 ;
V_150 += sizeof( T_2 ) * V_152 ;
V_151 -= V_152 ;
}
if ( V_148 )
return 0 ;
else
return 1 ;
}
static T_1 F_51 ( struct V_8 * V_9 ,
T_1 V_46 , T_2 V_146 , T_2 * V_153 , T_2 V_102 )
{
struct V_124 * V_125 =
& ( * (struct V_16 * ) V_9 -> V_17 ) . V_61 [ V_46 ] ;
T_2 V_148 = V_142 ;
int V_149 = 16 ;
T_2 V_150 = V_146 ;
int V_151 = V_102 ;
int V_152 ;
T_2 * V_144 = V_153 ;
T_2 V_154 = 0 ;
while ( V_151 ) {
if ( V_151 > V_149 )
V_152 = V_149 ;
else
V_152 = V_151 ;
V_148 = V_142 ;
do {
F_49 ( V_125 , V_150 , V_144 ,
V_152 ) ;
} while ( F_43 ( V_9 , V_137 )
&& -- V_148 );
if ( ! V_148 )
break;
V_144 += V_152 ;
V_150 += sizeof( T_2 ) * V_152 ;
V_151 -= V_152 ;
V_154 ++ ;
}
if ( V_148 )
return 0 ;
else
return 1 ;
}
static short F_22 ( struct V_8 * V_9 ,
T_1 V_46 , struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_16 * V_60 = (struct V_16 * ) V_9 -> V_17 ;
struct V_124 * V_125 = & V_60 -> V_61 [ V_46 ] ;
T_2 V_105 ;
T_1 V_155 ;
T_2 V_132 ;
T_2 V_131 ;
T_2 * V_156 ;
T_1 error = 0 ;
V_155 = F_52 ( V_9 , V_46 , V_157 ) ;
if ( V_155 & V_158 ) {
V_9 -> V_32 ++ ;
return V_159 ;
}
V_9 -> V_32 = 0 ;
if ( V_60 -> V_83 == 0 ) {
V_105 = V_160 ;
do {
V_132 =
F_23 ( V_125 ,
F_24 ( V_161 ) ) ;
V_60 -> V_83 = V_132 ;
} while ( F_43 ( V_9 , V_137 )
&& -- V_105 );
if ( ! V_105 )
return V_162 ;
} else
V_132 = V_60 -> V_83 ;
V_131 = V_2 -> V_37 ;
V_156 = ( T_2 * ) V_2 ;
if ( F_40 ( V_9 , V_46 , V_132 , V_156 ,
( T_1 ) V_131 / 4 ) )
return V_163 ;
if ( F_53 ( V_9 , V_46 , V_164 ) )
return V_165 ;
F_54 ( V_125 ) ;
V_155 = F_52 ( V_9 , V_46 , V_164 ) ;
if ( V_155 & V_158 )
return V_166 ;
if ( V_60 -> V_84 == 0 ) {
V_105 = V_160 ;
do {
V_132 =
F_23 ( V_125 ,
F_24 ( V_167 ) ) ;
} while ( F_43 ( V_9 , V_137 )
&& -- V_105 );
V_60 -> V_84 = V_132 ;
if ( ! V_105 )
return V_168 ;
} else
V_132 = V_60 -> V_84 ;
V_105 = V_160 ;
do {
V_131 = F_23 ( V_125 , F_24 ( V_131 ) ) ;
} while ( F_43 ( V_9 , V_137 ) && -- V_105 );
if ( ! V_105 )
V_131 = sizeof( struct V_3 ) ;
V_156 = ( T_2 * ) V_4 ;
if ( F_51 ( V_9 , V_46 , V_132 , V_156 ,
( T_1 ) V_131 / 4 ) )
return V_169 ;
if ( F_53 ( V_9 , V_46 , V_157 ) )
return V_170 ;
F_54 ( V_125 ) ;
error = F_55 ( V_2 , V_4 ) ;
return error ;
}
static short F_56 ( T_2 V_132 , T_2 V_171 )
{
#ifdef F_57
if ( V_132 < ( T_2 ) V_172 )
return 0 ;
if ( V_132 > ( T_2 ) ( V_173 + V_174 ) )
return 0 ;
if ( ( V_132 + ( V_171 << 2 ) ) >
( T_2 ) ( V_173 + V_174 ) )
return 0 ;
#else
( void ) V_132 ;
( void ) V_171 ;
return 1 ;
#endif
}
static short F_58 ( struct V_8 * V_9 , T_1 V_46 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_124 * V_125 =
& ( * (struct V_16 * ) V_9 -> V_17 ) . V_61 [ V_46 ] ;
T_2 V_175 = 0 ;
T_1 V_155 ;
T_2 V_131 , V_132 ;
T_2 * V_156 = ( T_2 * ) V_2 -> V_51 . V_176 . V_51 . V_56 . V_177 ;
T_1 V_148 = 8 ;
( void ) V_4 ;
while ( ( V_175 < ( V_2 -> V_51 . V_176 . V_51 . V_56 . V_178 & ~ 3L ) )
&& -- V_148 ) {
V_155 = F_52 ( V_9 , V_46 , V_157 ) ;
if ( V_155 & V_158 )
return V_179 ;
if ( F_53 ( V_9 , V_46 ,
V_180 ) )
return V_181 ;
F_54 ( V_125 ) ;
V_155 = F_52 ( V_9 , V_46 , V_180 ) ;
if ( V_155 & V_158 )
return V_182 ;
do {
V_132 = F_23 ( V_125 , F_24 ( V_132 ) ) ;
V_131 = F_23 ( V_125 , F_24 ( V_131 ) ) ;
} while ( F_43 ( V_9 , V_137 ) );
if ( ! F_56 ( V_132 , V_131 ) )
return V_183 ;
{
T_2 V_184 = V_131 ;
T_2 V_185 = 512 ;
while ( V_184 ) {
if ( V_184 < V_185 )
V_185 = V_184 ;
if ( F_40 ( V_9 , V_46 ,
V_132 , V_156 , V_185 ) )
return V_186 ;
V_132 += V_185 * 4 ;
V_156 += V_185 ;
V_184 -= V_185 ;
}
}
if ( F_53 ( V_9 , V_46 , V_157 ) )
return V_187 ;
F_54 ( V_125 ) ;
V_175 += V_131 * 4 ;
}
if ( ! V_148 )
return V_188 ;
return 0 ;
}
static short F_59 ( struct V_8 * V_9 , T_1 V_46 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_124 * V_125 =
& ( * (struct V_16 * ) V_9 -> V_17 ) . V_61 [ V_46 ] ;
T_2 V_189 = 0 ;
T_1 V_155 ;
T_2 V_131 , V_132 ;
T_2 * V_156 = ( T_2 * ) V_2 -> V_51 . V_176 . V_51 . V_56 . V_177 ;
( void ) V_4 ;
while ( V_189 < ( V_2 -> V_51 . V_176 . V_51 . V_56 . V_178 & ~ 3L ) ) {
V_155 = F_52 ( V_9 , V_46 , V_157 ) ;
if ( V_155 & V_158 )
return V_190 ;
if ( F_53 ( V_9 , V_46 ,
V_191 ) )
return V_192 ;
F_54 ( V_125 ) ;
V_155 = F_52 ( V_9 , V_46 , V_191 ) ;
if ( V_155 & V_158 )
return V_193 ;
do {
V_132 = F_23 ( V_125 , F_24 ( V_132 ) ) ;
V_131 = F_23 ( V_125 , F_24 ( V_131 ) ) ;
} while ( F_43 ( V_9 , V_137 ) );
{
T_2 V_184 = V_131 ;
T_2 V_185 = 512 ;
while ( V_184 ) {
if ( V_184 < V_185 )
V_185 = V_184 ;
if ( F_51 ( V_9 , V_46 ,
V_132 , V_156 , V_185 ) )
return V_194 ;
V_132 += V_185 * 4 ;
V_156 += V_185 ;
V_184 -= V_185 ;
}
}
if ( F_53 ( V_9 , V_46 , V_157 ) )
return V_195 ;
F_54 ( V_125 ) ;
V_189 += V_131 * 4 ;
}
return 0 ;
}
static void F_54 ( struct V_124 * V_125 )
{
F_28 ( 0x00030003 , V_125 -> V_71 ) ;
}
static short F_53 ( struct V_8 * V_9 ,
T_1 V_46 , T_2 V_135 )
{
struct V_124 * V_125 =
& ( * (struct V_16 * ) V_9 -> V_17 ) . V_61 [ V_46 ] ;
T_2 V_105 = V_160 ;
do {
F_34 ( V_125 , F_24 ( V_135 ) , V_135 ) ;
F_46 ( V_125 , F_24 ( V_135 ) ) ;
} while ( F_43 ( V_9 , V_143 ) && -- V_105 );
F_28 ( 0x00040004 , V_125 -> V_71 ) ;
if ( V_105 )
return 0 ;
else
return 1 ;
}
static short F_43 ( struct V_8 * V_9 ,
T_1 V_196 )
{
T_2 V_197 ;
struct V_16 * V_60 = (struct V_16 * ) V_9 -> V_17 ;
V_197 = F_33 ( V_60 -> V_68 + V_198 ) ;
if ( V_197 ) {
F_28 ( 0L , V_60 -> V_68 + V_198 ) ;
V_60 -> V_80 ++ ;
if ( V_196 == 1 )
V_98 ++ ;
else
V_99 ++ ;
return 1 ;
} else
return 0 ;
}
static short F_52 ( struct V_8 * V_9 , T_1 V_46 ,
T_2 V_199 )
{
struct V_124 * V_125 =
& ( * (struct V_16 * ) V_9 -> V_17 ) . V_61 [ V_46 ] ;
T_2 V_155 = 0L ;
T_2 V_105 ;
T_2 V_200 = 0L ;
V_105 = V_160 ;
while ( -- V_105 ) {
V_200 = F_33 ( V_125 -> V_71 ) ;
if ( V_200 & 0x04 )
break;
}
if ( V_105 == 0 )
return V_158 ;
V_105 = V_160 ;
while ( -- V_105 ) {
V_155 = F_23 ( V_125 , F_24 ( V_201 ) ) ;
if ( V_155 == V_199 )
break;
if ( ( V_155 & V_158 )
&& ! F_43 ( V_9 , V_137 ) )
break;
}
if ( V_155 & V_158 )
V_155 = V_158 ;
if ( V_105 == 0 )
V_155 = V_158 ;
return ( short ) V_155 ;
}
static short F_4 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
const T_1 V_46 = 0 ;
struct V_16 * V_60 = (struct V_16 * ) V_9 -> V_17 ;
struct V_124 * V_125 = & V_60 -> V_61 [ V_46 ] ;
T_2 V_105 ;
T_2 V_202 ;
T_1 V_12 ;
F_60 ( V_9 ) ;
V_105 = V_160 ;
do {
V_202 =
F_23 ( (struct V_124 * ) V_125 ,
F_24 ( V_203 ) ) ;
} while ( F_43 ( V_9 , V_137 ) && -- V_105 );
if ( ! V_105 ) {
V_12 = V_204 ;
goto V_205;
}
if ( V_202 ) {
T_2 V_132 ;
T_2 V_131 ;
V_105 = V_160 ;
if ( V_125 -> V_206 == 0 ) {
do {
V_132 =
F_23 ( (struct V_124 * ) V_125 ,
F_24 ( V_207 ) ) ;
V_131 = F_23 ( (struct V_124 * ) V_125 ,
F_24
( V_94 ) ) ;
} while ( F_43 ( V_9 , V_137 )
&& -- V_105 );
if ( ! V_105 ) {
V_12 = V_208 ;
goto V_205;
}
V_125 -> V_206 = V_132 ;
V_125 -> V_209 = V_131 ;
} else {
V_132 = V_125 -> V_206 ;
V_131 = V_125 -> V_209 ;
}
if ( F_51 ( V_9 , V_46 , V_132 ,
( T_2 * ) & V_60 -> V_91 [ 0 ] ,
V_131 / sizeof( T_2 ) ) ) {
V_12 = V_210 ;
goto V_205;
}
do {
F_34 ( (struct V_124 * ) V_125 ,
F_24 ( V_203 ) , 0 ) ;
F_46 ( V_125 , F_24 ( V_135 ) ) ;
} while ( F_43 ( V_9 , V_143 )
&& -- V_105 );
if ( ! V_105 ) {
V_12 = V_211 ;
goto V_205;
}
}
V_12 = 0 ;
V_205:
F_61 ( V_9 ) ;
return V_12 ;
}
static T_1 F_62 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
T_1 V_212 = 0 ;
switch ( V_2 -> V_27 ) {
case V_42 :
if ( V_2 -> V_213 < 2 )
V_212 = 1 ;
break;
case V_214 :
V_212 = V_2 -> V_213 ;
break;
default:
break;
}
return V_212 ;
}
static void F_6 ( struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 error = 0 ;
T_1 V_46 = 0 ;
T_1 V_81 = ( (struct V_16 * ) V_9 -> V_17 ) -> V_81 ;
if ( V_81 < 2 )
V_46 = 0 ;
else {
V_46 = F_62 ( V_9 , V_2 ) ;
if ( ( V_2 -> V_5 == V_215 )
|| ( V_2 -> V_5 == V_216 ) ) {
struct V_1 V_85 ;
T_1 V_217 ;
V_85 . V_213 = V_2 -> V_51 . V_176 . V_51 . V_218 . V_219 ;
V_85 . V_27 = V_2 -> V_51 . V_176 . V_51 . V_218 . V_220 ;
V_217 = F_62 ( V_9 , & V_85 ) ;
if ( V_217 != V_46 ) {
V_4 -> error = V_221 ;
return;
}
}
}
F_60 ( V_9 ) ;
error = F_22 ( V_9 , V_46 , V_2 , V_4 ) ;
if ( error )
goto V_12;
if ( V_4 -> error )
goto V_222;
switch ( V_2 -> V_5 ) {
case V_223 :
case V_224 :
error = F_58 ( V_9 , V_46 , V_2 , V_4 ) ;
break;
case V_225 :
case V_226 :
error = F_59 ( V_9 , V_46 , V_2 , V_4 ) ;
break;
case V_21 :
V_4 -> V_51 . V_89 . assert . V_46 = 0 ;
if ( V_81 == 2 ) {
if ( ! V_4 -> V_51 . V_89 . assert . V_102 ) {
error = F_22 ( V_9 ,
1 , V_2 , V_4 ) ;
V_4 -> V_51 . V_89 . assert . V_46 = 1 ;
}
}
}
V_12:
if ( error ) {
if ( error >= V_13 ) {
V_4 -> error = V_227 ;
V_4 -> V_15 = error ;
} else {
V_4 -> error = error ;
}
V_4 -> V_37 = sizeof( struct V_38 ) ;
}
V_222:
F_61 ( V_9 ) ;
return;
}
