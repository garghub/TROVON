static int F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
return ( 1 ) ;
}
return ( 0 ) ;
}
static void F_2 ( T_1 * V_4 )
{
V_4 -> V_5 . V_6 . V_7 [ V_8 ] = 0 ;
V_4 -> V_5 . V_6 . V_7 [ V_9 ] = 2 ;
V_4 -> V_5 . V_6 . V_7 [ V_10 ] = 4 ;
V_4 -> V_5 . V_6 . V_7 [ V_11 ] = 0 ;
V_4 -> V_5 . V_6 . V_7 [ V_12 ] = 2 ;
V_4 -> V_5 . V_6 . V_7 [ V_13 ] = 4 ;
V_4 -> V_5 . V_6 . V_7 [ V_14 ] = 3 ;
V_4 -> V_15 . V_16 = V_4 -> V_5 . V_6 . V_17 [ 0 ] ;
V_4 -> V_15 . V_18 = V_4 -> V_5 . V_6 . V_17 [ 2 ] ;
V_4 -> V_15 . V_19 = V_4 -> V_5 . V_6 . V_17 [ 4 ] ;
V_4 -> V_15 . V_20 = V_4 -> V_5 . V_6 . V_17 [ 0 ] ;
V_4 -> V_15 . V_20 += V_21 ;
V_4 -> V_15 . V_22 = V_4 -> V_5 . V_6 . V_17 [ 2 ] ;
V_4 -> V_15 . V_22 += V_23 ;
V_4 -> V_15 . V_24 = V_4 -> V_5 . V_6 . V_17 [ 4 ] ;
V_4 -> V_15 . V_24 += V_25 ;
V_4 -> V_15 . V_26 = V_4 -> V_5 . V_6 . V_27 [ 0 ] ;
V_4 -> V_15 . V_28 = V_4 -> V_5 . V_6 . V_17 [ 3 ] ;
}
int F_3 ( T_1 * V_4 )
{
int V_27 = 0 ;
int V_29 ;
unsigned long V_30 [ 5 ] = {
V_31 ,
0x1000 ,
0x2000 ,
0x8000 ,
0x1000
} ;
V_29 = F_1 ( V_4 -> V_32 ) ;
if ( V_29 ) {
V_30 [ 0 ] = V_33 ;
}
V_4 -> V_15 . V_34 = V_35 [ V_4 -> V_32 ] ;
F_4 ((L_1, a->xdi_adapter.Properties.Name))
for ( V_27 = 0 ; V_27 < 5 ; V_27 ++ ) {
V_4 -> V_5 . V_6 . V_27 [ V_27 ] =
F_5 ( V_4 -> V_5 . V_6 . V_36 ,
V_4 -> V_5 . V_6 . V_37 , V_27 ,
V_4 -> V_5 . V_6 . V_38 ) ;
if ( ! V_4 -> V_5 . V_6 . V_27 [ V_27 ]
|| ( V_4 -> V_5 . V_6 . V_27 [ V_27 ] == 0xFFFFFFF0 ) ) {
F_6 ((L_2, bar,
a->resources.pci.bar[bar]))
return ( - 1 ) ;
}
}
V_4 -> V_5 . V_6 . V_39 =
( V_40 ) F_7 ( V_4 -> V_5 . V_6 . V_36 ,
V_4 -> V_5 . V_6 . V_37 ,
V_4 -> V_5 . V_6 . V_38 ) ;
if ( ! V_4 -> V_5 . V_6 . V_39 ) {
F_6 ( ( L_3 ) ) ;
return ( - 1 ) ;
}
for ( V_27 = 0 ; V_27 < 5 ; V_27 ++ ) {
V_4 -> V_5 . V_6 . V_17 [ V_27 ] =
F_8 ( V_4 , V_27 , V_4 -> V_5 . V_6 . V_27 [ V_27 ] ,
V_30 [ V_27 ] ) ;
if ( ! V_4 -> V_5 . V_6 . V_17 [ V_27 ] ) {
F_6 ((L_4,
a->controller, bar))
F_9 ( V_4 ) ;
return ( - 1 ) ;
}
}
F_2 ( V_4 ) ;
if ( F_10 ( V_4 ) ) {
T_2 V_41 ;
V_41 = V_4 -> V_5 . V_6 . V_27 [ 1 ] & 0xffff0000 ;
V_41 |= ( ( T_2 ) V_4 -> V_5 . V_6 . V_36 ) << 8 ;
V_41 += ( V_4 -> V_5 . V_6 . V_37 + V_4 -> V_42 + 1 ) ;
V_4 -> V_15 . V_43 = V_41 & ~ 0xFF000000 ;
F_6 ((L_5,
a->controller, a->xdi_adapter.serialNo))
}
if ( F_11 ( & V_4 -> V_15 . V_44 , L_6 ) ) {
F_9 ( V_4 ) ;
return ( - 1 ) ;
}
if ( F_11
( & V_4 -> V_15 . V_45 , L_7 ) ) {
F_9 ( V_4 ) ;
return ( - 1 ) ;
}
strcpy ( V_4 -> V_15 . V_46 . V_47 , L_8 ) ;
if ( F_12 ( & V_4 -> V_15 . V_46 ,
V_48 , & V_4 -> V_15 ) ) {
F_9 ( V_4 ) ;
return ( - 1 ) ;
}
V_4 -> V_15 . V_49 . V_50 =
V_4 -> V_15 . V_46 . V_50 ;
V_4 -> V_15 . V_51 = V_35 [ V_4 -> V_32 ] . V_51 ;
V_4 -> V_15 . V_52 = V_35 [ V_4 -> V_32 ] . V_53 ;
V_4 -> V_15 . V_54 =
F_13 ( 0 , V_4 -> V_15 . V_52 * sizeof( V_55 ) ) ;
if ( ! V_4 -> V_15 . V_54 ) {
F_9 ( V_4 ) ;
return ( - 1 ) ;
}
memset ( V_4 -> V_15 . V_54 , 0x00 , V_4 -> V_15 . V_52 * sizeof( V_55 ) ) ;
V_4 -> V_15 . V_4 . V_56 = & V_4 -> V_15 ;
V_4 -> V_15 . V_57 = V_58 ;
V_4 -> V_59 . V_60 = F_9 ;
V_4 -> V_59 . V_61 = V_62 ;
if ( V_29 ) {
F_14 ( & V_4 -> V_15 ) ;
} else {
F_15 ( & V_4 -> V_15 ) ;
}
V_4 -> V_63 = F_16 ( V_4 ) ;
if ( V_29 ) {
F_17 ( V_4 -> V_5 . V_6 . V_38 ,
(struct V_64 * * ) & V_4 -> V_15 . V_65 , 32 ) ;
}
V_4 -> V_15 . V_66 . V_67 = V_4 -> V_5 . V_6 . V_39 ;
sprintf ( V_4 -> V_15 . V_66 . V_68 ,
L_9 , ( long ) V_4 -> V_15 . V_43 ) ;
if ( F_18 ( V_4 , V_4 -> V_15 . V_66 . V_67 ,
V_4 -> V_15 . V_66 . V_68 ) ) {
F_9 ( V_4 ) ;
return ( - 1 ) ;
}
V_4 -> V_15 . V_66 . V_69 = 1 ;
F_19 ( L_10 , V_4 -> V_15 . V_34 . V_70 ,
V_4 -> V_5 . V_6 . V_39 , V_4 -> V_15 . V_43 ) ;
return ( 0 ) ;
}
static int F_9 ( T_1 * V_4 )
{
int V_27 = 0 ;
if ( V_4 -> V_15 . V_71 ) {
F_20 ( V_4 ) ;
}
if ( V_4 -> V_15 . V_66 . V_69 ) {
F_21 ( V_4 , V_4 -> V_15 . V_66 . V_67 ) ;
}
V_4 -> V_15 . V_66 . V_69 = 0 ;
for ( V_27 = 0 ; V_27 < 5 ; V_27 ++ ) {
if ( V_4 -> V_5 . V_6 . V_27 [ V_27 ]
&& V_4 -> V_5 . V_6 . V_17 [ V_27 ] ) {
F_22 ( V_4 -> V_5 . V_6 . V_17 [ V_27 ] ) ;
V_4 -> V_5 . V_6 . V_27 [ V_27 ] = 0 ;
V_4 -> V_5 . V_6 . V_17 [ V_27 ] = NULL ;
}
}
F_23 ( & V_4 -> V_15 . V_49 ) ;
F_23 ( & V_4 -> V_15 . V_46 ) ;
F_24 ( & V_4 -> V_15 . V_46 ) ;
V_4 -> V_15 . V_49 . V_50 = NULL ;
F_25 ( & V_4 -> V_15 . V_44 , L_11 ) ;
F_25 ( & V_4 -> V_15 . V_45 , L_11 ) ;
if ( V_4 -> V_15 . V_54 ) {
F_26 ( 0 , V_4 -> V_15 . V_54 ) ;
V_4 -> V_15 . V_54 = NULL ;
}
V_4 -> V_15 . V_51 = 0 ;
V_4 -> V_15 . V_52 = 0 ;
F_27 ( V_4 -> V_5 . V_6 . V_38 ,
(struct V_64 * ) V_4 -> V_15 .
V_65 ) ;
V_4 -> V_15 . V_65 = NULL ;
return ( 0 ) ;
}
static int F_28 ( T_3 V_72 )
{
T_2 V_73 ;
struct V_74 T_4 * V_75 ;
if ( ! V_72 -> V_16 || ! V_72 -> V_22 ) {
return ( - 1 ) ;
}
if ( V_72 -> V_71 ) {
F_6 ((L_12,
IoAdapter->ANum))
return ( - 1 ) ;
}
V_75 = (struct V_74 T_4 * ) F_29 ( V_72 ) ;
F_30 ( & V_75 -> V_76 , 0 ) ;
F_31 ( V_72 , V_75 ) ;
V_72 -> V_77 ( V_72 ) ;
F_32 ( 10 ) ;
V_75 = (struct V_74 T_4 * ) F_29 ( V_72 ) ;
V_73 = F_33 ( & V_75 -> V_78 ) ;
F_32 ( 10 ) ;
if ( V_73 == F_33 ( & V_75 -> V_78 ) ) {
F_31 ( V_72 , V_75 ) ;
F_6 ((L_13,
IoAdapter->ANum, IoAdapter->serialNo))
return ( - 1 ) ;
}
if ( F_33 ( & V_75 -> V_76 ) ) {
F_6 ((L_14,
IoAdapter->ANum, IoAdapter->serialNo,
READ_DWORD(&boot->err)))
F_31 ( V_72 , V_75 ) ;
return ( - 1 ) ;
}
F_31 ( V_72 , V_75 ) ;
V_72 -> V_79 = 0 ;
if ( V_72 -> V_54 ) {
memset ( V_72 -> V_54 , 0x00 ,
V_72 -> V_52 * sizeof( V_55 ) ) ;
}
V_72 -> V_80 = 0 ;
V_72 -> V_81 = 0 ;
V_72 -> V_82 = 0 ;
V_72 -> V_83 = 0 ;
memset ( & V_72 -> V_4 . V_84 [ 0 ] , 0x00 ,
sizeof( V_72 -> V_4 . V_84 ) ) ;
memset ( & V_72 -> V_4 . V_85 [ 0 ] , 0x00 ,
sizeof( V_72 -> V_4 . V_85 ) ) ;
memset ( & V_72 -> V_4 . V_86 [ 0 ] , 0x00 ,
sizeof( V_72 -> V_4 . V_86 ) ) ;
memset ( & V_72 -> V_4 . V_87 [ 0 ] , 0x00 ,
sizeof( V_72 -> V_4 . V_87 ) ) ;
memset ( & V_72 -> V_4 . V_88 [ 0 ] , 0x00 ,
sizeof( V_72 -> V_4 . V_88 ) ) ;
memset ( & V_72 -> V_4 . V_89 [ 0 ] , 0x00 ,
sizeof( V_72 -> V_4 . V_89 ) ) ;
memset ( & V_72 -> V_4 . V_90 [ 0 ] , 0x00 ,
sizeof( V_72 -> V_4 . V_90 ) ) ;
memset ( & V_72 -> V_4 . V_91 [ 0 ] , 0x00 , sizeof( V_72 -> V_4 . V_91 ) ) ;
memset ( & V_72 -> V_4 . V_92 [ 0 ] , 0x00 , sizeof( V_72 -> V_4 . V_92 ) ) ;
return ( 0 ) ;
}
static int
F_34 ( T_3 V_72 ,
T_2 V_93 ,
const V_40 * V_94 , T_2 V_95 , T_2 V_96 )
{
V_40 T_4 * V_97 = F_29 ( V_72 ) ;
V_40 T_4 * V_98 = V_97 ;
if ( ( ( V_93 + V_95 ) >= V_96 ) || ! V_98 ) {
F_31 ( V_72 , V_97 ) ;
F_6 ((L_15,
IoAdapter->ANum, address + length))
return ( - 1 ) ;
}
V_98 += V_93 ;
while ( V_95 -- ) {
F_35 ( V_98 ++ , * V_94 ++ ) ;
}
F_31 ( V_72 , V_97 ) ;
return ( 0 ) ;
}
static int
F_36 ( T_3 V_72 ,
T_2 V_99 , T_2 V_100 )
{
T_2 V_73 ;
int V_101 = 0 ;
V_40 T_4 * V_97 ;
struct V_74 T_4 * V_75 = (struct V_74 T_4 * ) F_29 ( V_72 ) ;
T_5 * V_4 = & V_72 -> V_4 ;
if ( V_72 -> V_71 ) {
F_31 ( V_72 , V_75 ) ;
F_6 ((L_16,
IoAdapter->ANum))
return ( - 1 ) ;
}
if ( ! V_75 ) {
F_31 ( V_72 , V_75 ) ;
F_6 ((L_17,
IoAdapter->serialNo))
return ( - 1 ) ;
}
sprintf ( V_72 -> V_70 , L_18 , ( int ) V_72 -> V_102 ) ;
F_4 ((L_19, IoAdapter->ANum,
start_address))
F_30 ( & V_75 -> V_17 , V_99 ) ;
F_30 ( & V_75 -> V_103 , 3 ) ;
for ( V_73 = 0 ; V_73 < 300 ; ++ V_73 ) {
F_32 ( 10 ) ;
if ( ( F_33 ( & V_75 -> V_104 ) >> 16 ) == 0x4447 ) {
F_4 ((L_20,
IoAdapter->ANum, (i / 100), (i % 100)))
V_101 = 1 ;
break;
}
}
if ( ! V_101 ) {
V_40 T_4 * V_97 = ( V_40 T_4 * ) V_75 ;
T_2 V_105 ;
T_2 V_106 ;
V_105 = F_33 ( & V_97 [ 0x80 ] ) ;
V_106 = F_33 ( & V_97 [ 0x1c ] ) ;
F_6 ((L_21,
IoAdapter->ANum, READ_DWORD(&boot->signature),
TrapId, debug))
F_31 ( V_72 , V_75 ) ;
if ( V_72 -> V_107 ) {
( * ( V_72 -> V_107 ) ) ( V_72 ) ;
}
V_72 -> V_108 ( V_72 ) ;
return ( - 1 ) ;
}
F_31 ( V_72 , V_75 ) ;
V_72 -> V_71 = true ;
V_72 -> V_109 = 0 ;
V_97 = F_37 ( V_72 ) ;
F_30 ( V_97 , ( T_2 ) ~ 0x03E00000 ) ;
F_38 ( V_72 , V_97 ) ;
V_4 -> V_110 = 1 ;
V_4 -> V_111 ( V_4 , & V_112 -> V_110 , 1 ) ;
for ( V_73 = 100 ; ! V_72 -> V_109 && ( V_73 -- > 0 ) ; F_32 ( 10 ) ) ;
if ( ! V_72 -> V_109 ) {
F_6 ((L_22,
IoAdapter->ANum))
V_72 -> V_71 = false ;
V_72 -> V_108 ( V_72 ) ;
return ( - 1 ) ;
}
V_72 -> V_34 . V_113 = ( V_114 ) V_100 ;
F_39 ( V_72 -> V_102 ) ;
F_4 ((L_23, IoAdapter->ANum))
F_40 ( V_72 -> V_102 ) ;
return ( 0 ) ;
}
static void F_41 ( T_1 * V_4 )
{
T_3 V_72 = & V_4 -> V_15 ;
V_72 -> V_115 ( V_72 ) ;
V_72 -> V_116 ( & V_72 -> V_4 ) ;
V_72 -> V_117 ( & V_72 -> V_4 ) ;
V_72 -> V_116 ( & V_72 -> V_4 ) ;
F_23 ( & V_72 -> V_46 ) ;
F_23 ( & V_72 -> V_49 ) ;
}
static int F_20 ( T_1 * V_4 )
{
T_3 V_72 = & V_4 -> V_15 ;
int V_73 = 100 ;
if ( ! V_72 -> V_20 ) {
return ( - 1 ) ;
}
if ( ! V_72 -> V_71 ) {
F_6 ((L_24,
IoAdapter->ANum))
return ( - 1 ) ;
}
V_72 -> V_71 = 0 ;
F_42 ( V_72 -> V_102 ) ;
V_4 -> V_118 = F_41 ;
V_72 -> V_4 . V_110 = 1 ;
V_72 -> V_4 . V_119 ( & V_72 -> V_4 , & V_112 -> V_110 ) ;
do {
F_43 ( 10 ) ;
} while ( V_73 -- && V_4 -> V_118 );
if ( V_4 -> V_118 ) {
F_41 ( V_4 ) ;
V_4 -> V_118 = NULL ;
F_6 ((L_25,
IoAdapter->ANum))
}
V_72 -> V_4 . V_110 = 0 ;
V_72 -> V_108 ( V_72 ) ;
return ( 0 ) ;
}
static int
V_62 ( struct V_120 * V_4 ,
T_6 * V_103 , int V_95 )
{
int V_121 = - 1 ;
if ( V_103 -> V_122 != V_4 -> V_42 ) {
F_6 ((L_26,
cmd->adapter, a->controller))
return ( - 1 ) ;
}
switch ( V_103 -> V_123 ) {
case V_124 :
V_4 -> V_125 . V_126 = sizeof( T_2 ) ;
V_4 -> V_125 . V_94 =
F_13 ( 0 , V_4 -> V_125 . V_126 ) ;
if ( V_4 -> V_125 . V_94 ) {
* ( T_2 * ) V_4 -> V_125 . V_94 =
( T_2 ) V_4 -> V_32 ;
V_4 -> V_125 . V_127 = V_128 ;
V_121 = 0 ;
}
break;
case V_129 :
V_4 -> V_125 . V_126 = sizeof( T_2 ) ;
V_4 -> V_125 . V_94 =
F_13 ( 0 , V_4 -> V_125 . V_126 ) ;
if ( V_4 -> V_125 . V_94 ) {
* ( T_2 * ) V_4 -> V_125 . V_94 =
( T_2 ) V_4 -> V_15 . V_43 ;
V_4 -> V_125 . V_127 = V_128 ;
V_121 = 0 ;
}
break;
case V_130 :
V_4 -> V_125 . V_126 = sizeof( T_2 ) * 9 ;
V_4 -> V_125 . V_94 =
F_13 ( 0 , V_4 -> V_125 . V_126 ) ;
if ( V_4 -> V_125 . V_94 ) {
int V_73 ;
T_2 * V_94 = ( T_2 * ) V_4 -> V_125 . V_94 ;
for ( V_73 = 0 ; V_73 < 8 ; V_73 ++ ) {
* V_94 ++ = V_4 -> V_5 . V_6 . V_27 [ V_73 ] ;
}
* V_94 ++ = ( T_2 ) V_4 -> V_5 . V_6 . V_39 ;
V_4 -> V_125 . V_127 = V_128 ;
V_121 = 0 ;
}
break;
case V_131 :
V_121 = F_28 ( & V_4 -> V_15 ) ;
break;
case V_132 :
V_121 = F_34 ( & V_4 -> V_15 ,
V_103 -> V_133 .
V_134 . V_135 ,
( V_40 * ) & V_103 [ 1 ] ,
V_103 -> V_133 .
V_134 . V_95 ,
F_1 ( V_4 ->
V_32 )
? V_33 :
V_31 ) ;
break;
case V_136 :
V_121 = F_20 ( V_4 ) ;
break;
case V_137 :
V_121 = F_36 ( & V_4 -> V_15 ,
V_103 -> V_133 . V_138 .
V_135 ,
V_103 -> V_133 . V_138 .
V_100 ) ;
break;
case V_139 :
V_4 -> V_15 . V_100 =
V_103 -> V_133 . V_100 . V_100 ;
V_4 -> V_15 . V_4 . V_140 =
V_4 -> V_15 . V_100 ;
F_44 ((L_27,
a->xdi_adapter.features))
V_121 = 0 ;
break;
case V_141 :
V_4 -> V_125 . V_126 = sizeof( T_2 ) ;
V_4 -> V_125 . V_94 =
F_13 ( 0 , V_4 -> V_125 . V_126 ) ;
if ( V_4 -> V_125 . V_94 ) {
T_2 * V_94 = ( T_2 * ) V_4 -> V_125 . V_94 ;
if ( ! V_4 -> V_15 . V_20 ||
! V_4 -> V_15 . V_22 ||
! V_4 -> V_15 . V_24 ) {
* V_94 = 3 ;
} else if ( V_4 -> V_15 . V_83 ) {
* V_94 = 2 ;
} else if ( V_4 -> V_15 . V_71 ) {
* V_94 = 1 ;
} else {
* V_94 = 0 ;
}
V_4 -> V_125 . V_127 = V_128 ;
V_121 = 0 ;
}
break;
case V_142 :
V_121 = F_45 ( V_4 ) ;
break;
case V_143 :
if ( V_4 -> V_15 . V_16 ) {
if (
( V_4 -> V_125 . V_126 =
V_103 -> V_133 . V_144 . V_95 ) ) {
if (
( V_4 -> V_125 . V_126 +
V_103 -> V_133 . V_144 . V_135 ) <
V_4 -> V_15 . V_145 ) {
V_4 -> V_125 . V_94 =
F_13 ( 0 ,
V_4 -> V_125 .
V_126 ) ;
if ( V_4 -> V_125 . V_94 ) {
V_40 T_4 * V_97 = F_29 ( & V_4 -> V_15 ) ;
V_40 T_4 * V_146 = V_97 ;
V_40 * V_147 = V_4 -> V_125 . V_94 ;
T_2 V_148 = V_4 -> V_125 . V_126 ;
V_146 += V_103 -> V_133 . V_144 . V_135 ;
while ( V_148 -- ) {
* V_147 ++ = F_46 ( V_146 ++ ) ;
}
V_4 -> V_125 . V_127 = V_128 ;
F_31 ( & V_4 -> V_15 , V_97 ) ;
V_121 = 0 ;
}
}
}
}
break;
default:
F_6 ((L_28, a->controller,
cmd->command))
}
return ( V_121 ) ;
}
static int F_10 ( T_1 * V_4 )
{
V_40 V_94 [ 64 ] ;
int V_73 ;
T_2 V_148 = sizeof( V_94 ) ;
volatile V_40 T_4 * V_149 ;
volatile V_40 T_4 * V_150 ;
V_40 V_151 ;
V_149 = F_47 ( & V_4 -> V_15 ) ;
V_151 = F_46 ( & V_149 [ 0xc3c ] ) ;
if ( ! ( V_151 & 0x08 ) ) {
F_35 ( & V_149 [ 0xc3c ] , V_151 ) ;
}
F_35 ( & V_149 [ V_152 ] , 0x00 ) ;
F_35 ( & V_149 [ V_153 ] , 0xFF ) ;
F_48 ( & V_4 -> V_15 , V_149 ) ;
memset ( V_94 , '\0' , V_148 ) ;
V_150 = F_49 ( & V_4 -> V_15 ) ;
for ( V_73 = 0 ; V_73 < V_148 ; V_73 ++ ) {
V_94 [ V_73 ] = F_46 ( & V_150 [ 0x8000 - V_148 + V_73 ] ) ;
}
F_50 ( & V_4 -> V_15 , V_150 ) ;
V_149 = F_47 ( & V_4 -> V_15 ) ;
F_35 ( & V_149 [ V_152 ] , 0xFC ) ;
F_35 ( & V_149 [ V_153 ] , 0xFF ) ;
F_48 ( & V_4 -> V_15 , V_149 ) ;
if ( memcmp ( & V_94 [ 48 ] , L_29 , 12 ) ) {
#if ! F_51 ( V_154 )
V_114 V_103 = 0 , V_155 ;
void * V_17 ;
T_2 V_156 , V_157 , V_158 ;
V_40 V_159 , V_160 ;
void * V_38 ;
V_158 = V_4 -> V_5 . V_6 . V_27 [ 4 ] ;
V_157 = V_4 -> V_5 . V_6 . V_27 [ 3 ] ;
V_156 = V_4 -> V_5 . V_6 . V_27 [ 1 ] ;
F_6 ((L_30))
F_4 ((L_31,
data[0], data[1], data[2], data[3],
data[4], data[5], data[6], data[7]))
V_159 = V_4 -> V_5 . V_6 . V_36 ;
V_160 = V_4 -> V_5 . V_6 . V_37 ;
V_38 = V_4 -> V_5 . V_6 . V_38 ;
F_52 ( V_159 , V_160 , 0x04 , & V_155 , sizeof( V_155 ) , V_38 ) ;
F_53 ( V_159 , V_160 , 0x04 , & V_103 , sizeof( V_103 ) , V_38 ) ;
F_53 ( V_159 , V_160 , 0x14 , & V_158 , sizeof( V_158 ) , V_38 ) ;
F_53 ( V_159 , V_160 , 0x20 , & V_156 , sizeof( V_156 ) , V_38 ) ;
F_53 ( V_159 , V_160 , 0x04 , & V_155 , sizeof( V_155 ) , V_38 ) ;
V_17 = V_4 -> V_5 . V_6 . V_17 [ 1 ] ;
V_4 -> V_5 . V_6 . V_17 [ 1 ] = V_4 -> V_5 . V_6 . V_17 [ 4 ] ;
V_4 -> V_5 . V_6 . V_17 [ 4 ] = V_17 ;
V_156 = V_4 -> V_5 . V_6 . V_27 [ 1 ] ;
V_4 -> V_5 . V_6 . V_27 [ 1 ] = V_4 -> V_5 . V_6 . V_27 [ 4 ] ;
V_4 -> V_5 . V_6 . V_27 [ 4 ] = V_156 ;
V_148 = sizeof( V_94 ) ;
V_149 = F_47 ( & V_4 -> V_15 ) ;
if ( ! ( V_149 [ 0xc3c ] & 0x08 ) ) {
V_149 [ 0xc3c ] |= 0x08 ;
}
V_149 [ V_152 ] = 0x00 ;
V_149 [ V_153 ] = 0xFF ;
F_48 ( & V_4 -> V_15 , V_149 ) ;
memset ( V_94 , '\0' , V_148 ) ;
V_150 = F_49 ( & V_4 -> V_15 ) ;
for ( V_73 = 0 ; V_73 < V_148 ; V_73 ++ ) {
V_94 [ V_73 ] = V_150 [ 0x8000 - V_148 + V_73 ] ;
}
F_49 ( & V_4 -> V_15 , V_150 ) ;
V_149 = F_47 ( & V_4 -> V_15 ) ;
V_149 [ V_152 ] = 0xFC ;
V_149 [ V_153 ] = 0xFF ;
F_48 ( & V_4 -> V_15 , V_149 ) ;
if ( memcmp ( & V_94 [ 48 ] , L_29 , 12 ) ) {
F_6 ((L_32))
F_4 ((L_31,
data[0], data[1], data[2], data[3],
data[4], data[5], data[6], data[7]))
return ( - 1 ) ;
}
#else
F_6 ((L_33))
F_4 ((L_31,
data[0], data[1], data[2], data[3],
data[4], data[5], data[6], data[7]))
F_4 ((L_34, data[47], data[46],
data[45], data[44]))
#endif
}
V_4 -> V_15 . V_43 =
( V_94 [ 47 ] << 24 ) | ( V_94 [ 46 ] << 16 ) | ( V_94 [ 45 ] << 8 ) |
V_94 [ 44 ] ;
if ( ! V_4 -> V_15 . V_43
|| ( V_4 -> V_15 . V_43 == 0xffffffff ) ) {
V_4 -> V_15 . V_43 = 0 ;
F_6 ((L_32))
return ( - 1 ) ;
}
F_4 ((L_35, a->xdi_adapter.serialNo))
F_44 ((L_36, (int) data[41],
(int) data[40]))
F_44 ((L_37, (int) data[33],
(int) data[32]))
F_44 ((L_38, (int) data[37],
(int) data[36]))
F_44 ((L_39,
(int) ((data[28] > 90) ? 1900 : 2000) +
(int) data[28], (int) data[29], (int) data[30]))
return ( 0 ) ;
}
void F_54 ( T_3 V_72 )
{
}
void F_55 ( T_3 V_72 )
{
}
static int
F_56 ( volatile V_40 T_4 * V_17 , volatile V_40 T_4 * V_94 , int V_161 )
{
V_114 V_162 ;
F_57 ( V_17 , 0x4000 ) ;
F_57 ( V_94 , V_163 ) ;
F_57 ( V_17 , 0x4000 ) ;
V_162 = F_58 ( V_94 ) ;
if ( V_162 != V_163 ) {
F_44 ((L_40,
dsp, pattern, DSP_SIGNATURE_PROBE_WORD))
return ( - 1 ) ;
}
F_57 ( V_17 , 0x4000 ) ;
F_57 ( V_94 , ~ V_163 ) ;
F_57 ( V_17 , 0x4000 ) ;
V_162 = F_58 ( V_94 ) ;
if ( V_162 != ( V_114 ) ~ V_163 ) {
F_6 ((L_41,
dsp, pattern, (word) ~ DSP_SIGNATURE_PROBE_WORD))
return ( - 2 ) ;
}
F_44 ((L_42, dsp))
return ( 0 ) ;
}
static T_2 F_16 ( T_1 * V_4 )
{
V_40 T_4 * V_164 ;
V_40 T_4 * V_97 ;
T_2 V_121 = 0 ;
T_2 V_165 [ 7 ] = {
0x00000000 ,
0x00000800 ,
0x00000840 ,
0x00001000 ,
0x00001040 ,
0x00000000
} ;
V_40 T_4 * V_166 ;
V_40 T_4 * V_167 ;
V_40 V_168 ;
int V_169 = 0 , V_170 , V_171 ;
if ( ! V_4 -> V_15 . V_18 || ! V_4 -> V_15 . V_22 ) {
return ( 0 ) ;
}
V_97 = F_59 ( & V_4 -> V_15 ) ;
F_35 ( V_97 , V_172 | V_173 ) ;
F_60 ( & V_4 -> V_15 , V_97 ) ;
F_32 ( 5 ) ;
V_164 = F_61 ( & V_4 -> V_15 ) ;
for ( V_171 = 0 ; V_171 < 30 ; V_171 ++ ) {
V_169 = V_171 / 7 + 1 ;
V_170 = V_171 % 7 ;
V_167 = V_164 ;
V_166 = V_164 ;
V_167 += V_165 [ V_169 ] ;
V_166 += V_165 [ V_169 ] ;
V_167 += ( V_170 * 8 ) ;
V_166 += ( V_170 * 8 ) + 0x80 ;
if ( ! F_56
( V_166 , V_167 , V_171 + 1 ) ) {
V_121 |= ( 1 << V_171 ) ;
}
}
F_62 ( & V_4 -> V_15 , V_164 ) ;
V_97 = F_59 ( & V_4 -> V_15 ) ;
F_35 ( V_97 , V_172 | V_174 | V_175 ) ;
F_60 ( & V_4 -> V_15 , V_97 ) ;
F_32 ( 5 ) ;
for ( V_169 = 0 ; V_169 < 4 ; V_169 ++ ) {
V_168 = ( ( V_121 >> ( V_169 * 7 ) ) & 0x7F ) ;
if ( V_168 && ( V_168 != 0x7F ) ) {
for ( V_170 = 0 ; V_170 < 7 ; V_170 ++ ) {
if ( ! ( V_168 & ( 1 << V_170 ) ) ) {
F_6 ((L_43,
dsp_row + 1,
dsp_index + 1))
}
}
}
}
if ( ! ( V_121 & 0x10000000 ) ) {
F_6 ((L_44))
}
if ( ! ( V_121 & 0x20000000 ) ) {
F_6 ((L_45))
}
F_4 ((L_46))
F_4 ((L_47))
F_4 ((L_46))
F_4 ((L_48))
F_4 ((L_46))
F_4 ((L_49,
((ret >> (0 * 7)) & 0x7F) ? L_50 : L_51,
((ret >> (1 * 7)) & 0x7F) ? L_50 : L_51,
((ret >> (2 * 7)) & 0x7F) ? L_50 : L_51,
((ret >> (3 * 7)) & 0x7F) ? L_50 : L_51))
F_4 ((L_46))
F_4 ((L_52, ret,
~ret & 0x3fffffff))
return ( V_121 ) ;
}
