static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
F_3 ( & V_4 -> V_6 , 0 , 2 ) ;
V_4 -> V_7 = V_3 ;
V_3 -> V_8 = V_4 ;
return V_4 ;
}
static void F_4 ( struct V_1 * V_3 )
{
F_5 ( F_6 ( & V_3 -> V_6 ) != 0 ) ;
V_3 -> V_7 -> V_8 = NULL ;
F_7 ( V_3 ) ;
}
static struct V_1 * F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = V_3 -> V_8 ;
if ( V_4 && F_6 ( & V_4 -> V_6 ) > 1 )
F_9 ( & V_4 -> V_6 ) ;
else
V_4 = NULL ;
return V_4 ;
}
static struct V_1 * F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = V_3 -> V_8 ;
if ( V_4 && F_6 ( & V_4 -> V_6 ) )
F_9 ( & V_4 -> V_6 ) ;
else
V_4 = NULL ;
return V_4 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = V_3 -> V_8 ;
F_12 ( & V_4 -> V_6 ) ;
}
static struct V_1 * F_13 (
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = V_3 -> V_8 ;
if ( V_4 == NULL )
return NULL ;
while ( F_3 ( & V_4 -> V_6 , 2 , 1 ) != 2 )
F_14 ( 100 ) ;
return V_4 ;
}
static struct V_1 * F_15 (
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = V_3 -> V_8 ;
if ( V_4 == NULL )
return NULL ;
while ( F_3 ( & V_4 -> V_6 , 1 , 0 ) != 1 )
F_14 ( 100 ) ;
V_3 -> V_8 = NULL ;
return V_4 ;
}
static int F_16 ( struct V_1 * V_4 )
{
struct V_9 * V_10 ;
int V_11 = 0 ;
if ( V_4 -> V_12 ) {
V_10 = & V_4 -> V_10 ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_13 . V_14 =
V_15 ;
V_10 -> V_16 . V_17 .
V_18 . V_19 = V_20 ;
V_11 = F_17 ( V_4 -> V_7 -> V_21 ,
V_10 ,
sizeof( struct V_9 ) ,
( unsigned long ) V_10 ,
V_22 , 0 ) ;
if ( V_11 != 0 ) {
F_18 ( & V_4 -> V_7 -> V_3 , L_1
L_2 ) ;
return - 1 ;
}
}
if ( V_4 -> V_23 ) {
V_11 = F_19 ( V_4 -> V_7 -> V_21 ,
V_4 -> V_23 ) ;
if ( V_11 != 0 ) {
F_18 ( & V_4 -> V_7 -> V_3 ,
L_3 ) ;
return - 1 ;
}
V_4 -> V_23 = 0 ;
}
if ( V_4 -> V_24 ) {
F_20 ( ( unsigned long ) V_4 -> V_24 ,
F_21 ( V_4 -> V_25 ) ) ;
V_4 -> V_24 = NULL ;
}
if ( V_4 -> V_26 ) {
V_4 -> V_12 = 0 ;
F_7 ( V_4 -> V_26 ) ;
V_4 -> V_26 = NULL ;
}
return V_11 ;
}
static int F_22 ( struct V_2 * V_3 )
{
int V_11 = 0 ;
int V_27 ;
struct V_1 * V_4 ;
struct V_9 * V_28 ;
V_4 = F_8 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( & V_3 -> V_3 , L_4
L_5 ) ;
return - 1 ;
}
V_4 -> V_24 =
( void * ) F_23 ( V_5 | V_29 ,
F_21 ( V_4 -> V_25 ) ) ;
if ( ! V_4 -> V_24 ) {
F_18 ( & V_3 -> V_3 , L_6
L_7 , V_4 -> V_25 ) ;
V_11 = - 1 ;
goto V_30;
}
V_11 = F_24 ( V_3 -> V_21 , V_4 -> V_24 ,
V_4 -> V_25 ,
& V_4 -> V_23 ) ;
if ( V_11 != 0 ) {
F_18 ( & V_3 -> V_3 ,
L_8 ) ;
goto V_30;
}
V_28 = & V_4 -> V_31 ;
memset ( V_28 , 0 , sizeof( struct V_9 ) ) ;
V_28 -> V_13 . V_14 = V_32 ;
V_28 -> V_16 . V_17 . V_33 .
V_34 = V_4 -> V_23 ;
V_28 -> V_16 . V_17 .
V_33 . V_19 = V_20 ;
V_11 = F_17 ( V_3 -> V_21 , V_28 ,
sizeof( struct V_9 ) ,
( unsigned long ) V_28 ,
V_22 ,
V_35 ) ;
if ( V_11 != 0 ) {
F_18 ( & V_3 -> V_3 ,
L_9 ) ;
goto V_30;
}
V_27 = F_25 ( & V_4 -> V_36 , 5 * V_37 ) ;
F_26 ( V_27 == 0 ) ;
if ( V_28 -> V_16 . V_17 .
V_38 . V_39 != V_40 ) {
F_18 ( & V_3 -> V_3 , L_10
L_11 ,
V_28 -> V_16 . V_17 .
V_38 . V_39 ) ;
V_11 = - 1 ;
goto V_30;
}
V_4 -> V_12 = V_28 -> V_16 .
V_17 . V_38 . V_41 ;
V_4 -> V_26 = F_27 ( V_4 -> V_12
* sizeof( struct V_42 ) , V_5 ) ;
if ( V_4 -> V_26 == NULL ) {
V_11 = - 1 ;
goto V_30;
}
memcpy ( V_4 -> V_26 ,
V_28 -> V_16 . V_17 .
V_38 . V_43 ,
V_4 -> V_12 *
sizeof( struct V_42 ) ) ;
if ( V_4 -> V_12 != 1 ||
V_4 -> V_26 -> V_44 != 0 ) {
V_11 = - 1 ;
goto V_30;
}
goto exit;
V_30:
F_16 ( V_4 ) ;
exit:
F_11 ( V_3 ) ;
return V_11 ;
}
static int F_28 ( struct V_2 * V_3 )
{
int V_11 , V_27 ;
struct V_1 * V_4 ;
struct V_9 * V_28 ;
int V_45 ;
V_4 = F_8 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( & V_3 -> V_3 , L_4
L_5 ) ;
return - 1 ;
}
V_28 = & V_4 -> V_31 ;
memset ( V_28 , 0 , sizeof( struct V_9 ) ) ;
V_28 -> V_13 . V_14 = V_46 ;
V_28 -> V_16 . V_47 . V_48 . V_49 =
V_50 ;
V_28 -> V_16 . V_47 . V_48 . V_51 =
V_52 ;
V_11 = F_17 ( V_3 -> V_21 , V_28 ,
sizeof( struct V_9 ) ,
( unsigned long ) V_28 ,
V_22 ,
V_35 ) ;
if ( V_11 != 0 )
goto V_30;
V_27 = F_25 ( & V_4 -> V_36 , 5 * V_37 ) ;
if ( V_27 == 0 ) {
V_11 = - V_53 ;
goto V_30;
}
if ( V_28 -> V_16 . V_47 . V_54 . V_39 !=
V_40 ) {
V_11 = - 1 ;
goto V_30;
}
if ( V_28 -> V_16 . V_47 . V_54 .
V_55 != V_56 ) {
V_11 = - 1 ;
goto V_30;
}
memset ( V_28 , 0 , sizeof( struct V_9 ) ) ;
V_45 = 0x00050000 ;
V_28 -> V_13 . V_14 = V_57 ;
V_28 -> V_16 . V_17 .
V_58 . V_59 =
( V_45 & 0xFFFF0000 ) >> 16 ;
V_28 -> V_16 . V_17 .
V_58 . V_60 =
V_45 & 0xFFFF ;
V_11 = F_17 ( V_3 -> V_21 , V_28 ,
sizeof( struct V_9 ) ,
( unsigned long ) V_28 ,
V_22 , 0 ) ;
if ( V_11 != 0 ) {
V_11 = - 1 ;
goto V_30;
}
V_11 = F_22 ( V_3 ) ;
V_30:
F_11 ( V_3 ) ;
return V_11 ;
}
static void F_29 ( struct V_1 * V_4 )
{
F_16 ( V_4 ) ;
}
int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_61 * V_62 , * V_63 ;
V_4 = F_13 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( & V_3 -> V_3 , L_12 ) ;
return - 1 ;
}
while ( F_6 ( & V_4 -> V_64 ) ) {
F_18 ( & V_3 -> V_3 ,
L_13 ,
F_6 ( & V_4 -> V_64 ) ) ;
F_14 ( 100 ) ;
}
F_29 ( V_4 ) ;
V_4 = F_15 ( V_3 ) ;
F_31 ( & V_3 -> V_3 , L_14 ) ;
F_32 ( V_3 -> V_21 ) ;
F_33 (netvsc_packet, pos,
&net_device->recv_pkt_list, list_ent) {
F_34 ( & V_62 -> V_65 ) ;
F_7 ( V_62 ) ;
}
F_4 ( V_4 ) ;
return 0 ;
}
static void F_35 ( struct V_2 * V_3 ,
struct V_66 * V_67 )
{
struct V_1 * V_4 ;
struct V_9 * V_68 ;
struct V_61 * V_69 ;
V_4 = F_10 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( & V_3 -> V_3 , L_4
L_5 ) ;
return;
}
V_68 = (struct V_9 * ) ( ( unsigned long ) V_67 +
( V_67 -> V_70 << 3 ) ) ;
if ( ( V_68 -> V_13 . V_14 == V_71 ) ||
( V_68 -> V_13 . V_14 ==
V_72 ) ||
( V_68 -> V_13 . V_14 ==
V_73 ) ) {
memcpy ( & V_4 -> V_31 , V_68 ,
sizeof( struct V_9 ) ) ;
F_36 ( & V_4 -> V_36 ) ;
} else if ( V_68 -> V_13 . V_14 ==
V_74 ) {
V_69 = (struct V_61 * ) ( unsigned long )
V_67 -> V_75 ;
V_69 -> V_76 . V_77 . V_78 (
V_69 -> V_76 . V_77 . V_79 ) ;
F_12 ( & V_4 -> V_64 ) ;
} else {
F_18 ( & V_3 -> V_3 , L_15
L_16 , V_68 -> V_13 . V_14 ) ;
}
F_11 ( V_3 ) ;
}
int F_37 ( struct V_2 * V_3 ,
struct V_61 * V_67 )
{
struct V_1 * V_4 ;
int V_11 = 0 ;
struct V_9 V_80 ;
V_4 = F_8 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( & V_3 -> V_3 , L_17
L_18 , V_4 ) ;
return - 2 ;
}
V_80 . V_13 . V_14 = V_81 ;
if ( V_67 -> V_82 ) {
V_80 . V_16 . V_17 . V_83 . V_84 = 0 ;
} else {
V_80 . V_16 . V_17 . V_83 . V_84 = 1 ;
}
V_80 . V_16 . V_17 . V_83 . V_85 =
0xFFFFFFFF ;
V_80 . V_16 . V_17 . V_83 . V_86 = 0 ;
if ( V_67 -> V_87 ) {
V_11 = F_38 ( V_3 -> V_21 ,
V_67 -> V_88 ,
V_67 -> V_87 ,
& V_80 ,
sizeof( struct V_9 ) ,
( unsigned long ) V_67 ) ;
} else {
V_11 = F_17 ( V_3 -> V_21 , & V_80 ,
sizeof( struct V_9 ) ,
( unsigned long ) V_67 ,
V_22 ,
V_35 ) ;
}
if ( V_11 != 0 )
F_18 ( & V_3 -> V_3 , L_19 ,
V_67 , V_11 ) ;
F_9 ( & V_4 -> V_64 ) ;
F_11 ( V_3 ) ;
return V_11 ;
}
static void F_39 ( struct V_2 * V_3 ,
T_1 V_89 )
{
struct V_9 V_90 ;
int V_91 = 0 ;
int V_11 ;
V_90 . V_13 . V_14 =
V_74 ;
V_90 . V_16 . V_17 . V_92 . V_39 =
V_40 ;
V_93:
V_11 = F_17 ( V_3 -> V_21 , & V_90 ,
sizeof( struct V_9 ) , V_89 ,
V_94 , 0 ) ;
if ( V_11 == 0 ) {
} else if ( V_11 == - 1 ) {
V_91 ++ ;
F_18 ( & V_3 -> V_3 , L_20
L_21 , V_89 , V_91 ) ;
if ( V_91 < 4 ) {
F_14 ( 100 ) ;
goto V_93;
} else {
F_18 ( & V_3 -> V_3 , L_22
L_23 ,
V_89 ) ;
}
} else {
F_18 ( & V_3 -> V_3 , L_22
L_24 , V_89 ) ;
}
}
static void F_40 ( void * V_95 )
{
struct V_61 * V_67 = V_95 ;
struct V_2 * V_3 = (struct V_2 * ) V_67 -> V_3 ;
struct V_1 * V_4 ;
T_1 V_89 = 0 ;
bool V_96 = false ;
unsigned long V_97 ;
V_4 = F_10 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( & V_3 -> V_3 , L_4
L_5 ) ;
return;
}
F_41 ( & V_4 -> V_98 , V_97 ) ;
V_67 -> V_99 -> V_100 -- ;
if ( V_67 -> V_99 -> V_100 == 0 ) {
V_96 = true ;
V_89 = V_67 -> V_76 . V_101 . V_102 ;
F_42 ( & V_67 -> V_99 -> V_65 ,
& V_4 -> V_103 ) ;
}
F_42 ( & V_67 -> V_65 , & V_4 -> V_103 ) ;
F_43 ( & V_4 -> V_98 , V_97 ) ;
if ( V_96 )
F_39 ( V_3 , V_89 ) ;
F_11 ( V_3 ) ;
}
static void F_44 ( struct V_2 * V_3 ,
struct V_66 * V_67 )
{
struct V_1 * V_4 ;
struct V_104 * V_105 ;
struct V_9 * V_68 ;
struct V_61 * V_62 = NULL ;
unsigned long V_106 ;
unsigned long V_107 , V_108 ;
struct V_109 * V_109 = NULL ;
int V_110 , V_111 ;
int V_100 = 0 , V_112 = 0 ;
unsigned long V_97 ;
F_45 ( V_113 ) ;
V_4 = F_10 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( & V_3 -> V_3 , L_4
L_5 ) ;
return;
}
if ( V_67 -> type != V_114 ) {
F_18 ( & V_3 -> V_3 , L_25 ,
V_67 -> type ) ;
F_11 ( V_3 ) ;
return;
}
V_68 = (struct V_9 * ) ( ( unsigned long ) V_67 +
( V_67 -> V_70 << 3 ) ) ;
if ( V_68 -> V_13 . V_14 !=
V_81 ) {
F_18 ( & V_3 -> V_3 , L_26
L_27 , V_68 -> V_13 . V_14 ) ;
F_11 ( V_3 ) ;
return;
}
V_105 = (struct V_104 * ) V_67 ;
if ( V_105 -> V_115 != V_20 ) {
F_18 ( & V_3 -> V_3 , L_28
L_29 , V_20 ,
V_105 -> V_115 ) ;
F_11 ( V_3 ) ;
return;
}
F_41 ( & V_4 -> V_98 , V_97 ) ;
while ( ! F_46 ( & V_4 -> V_103 ) ) {
F_47 ( V_4 -> V_103 . V_116 , & V_113 ) ;
if ( ++ V_100 == V_105 -> V_117 + 1 )
break;
}
F_43 ( & V_4 -> V_98 , V_97 ) ;
if ( V_100 < 2 ) {
F_18 ( & V_3 -> V_3 , L_30
L_31 ,
V_100 , V_105 -> V_117 + 1 ) ;
F_41 ( & V_4 -> V_98 , V_97 ) ;
for ( V_110 = V_100 ; V_110 != 0 ; V_110 -- ) {
F_47 ( V_113 . V_116 ,
& V_4 -> V_103 ) ;
}
F_43 ( & V_4 -> V_98 ,
V_97 ) ;
F_39 ( V_3 ,
V_105 -> V_118 . V_75 ) ;
F_11 ( V_3 ) ;
return;
}
V_109 = (struct V_109 * ) V_113 . V_116 ;
F_34 ( & V_109 -> V_65 ) ;
V_109 -> V_100 = V_100 - 1 ;
if ( V_109 -> V_100 != V_105 -> V_117 ) {
F_18 ( & V_3 -> V_3 , L_32
L_33 ,
V_105 -> V_117 , V_109 -> V_100 ) ;
}
for ( V_110 = 0 ; V_110 < ( V_100 - 1 ) ; V_110 ++ ) {
V_62 = (struct V_61 * ) V_113 . V_116 ;
F_34 ( & V_62 -> V_65 ) ;
V_62 -> V_99 = V_109 ;
V_62 -> V_76 . V_101 . V_119 =
F_40 ;
V_62 -> V_76 . V_101 . V_120 =
V_62 ;
V_62 -> V_3 = V_3 ;
V_62 -> V_76 . V_101 . V_102 =
V_105 -> V_118 . V_75 ;
V_62 -> V_121 =
V_105 -> V_122 [ V_110 ] . V_123 ;
V_62 -> V_87 = 1 ;
V_62 -> V_88 [ 0 ] . V_124 =
V_105 -> V_122 [ V_110 ] . V_123 ;
V_106 = F_48 ( ( void * ) ( ( unsigned long ) V_4 ->
V_24 + V_105 -> V_122 [ V_110 ] . V_125 ) ) ;
V_62 -> V_88 [ 0 ] . V_126 = V_106 >> V_127 ;
V_108 = ( unsigned long ) V_4 -> V_24
+ V_105 -> V_122 [ V_110 ] . V_125
+ V_105 -> V_122 [ V_110 ] . V_123 - 1 ;
V_107 = F_48 ( ( void * ) V_108 ) ;
V_62 -> V_88 [ 0 ] . V_44 =
V_105 -> V_122 [ V_110 ] . V_125 &
( V_128 - 1 ) ;
if ( ( V_107 >> V_127 ) != ( V_106 >> V_127 ) ) {
V_62 -> V_88 [ 0 ] . V_124 =
( V_62 -> V_88 [ 0 ] . V_126 <<
V_127 )
+ V_128 - V_106 ;
V_112 = V_62 -> V_121 -
V_62 -> V_88 [ 0 ] . V_124 ;
for ( V_111 = 1 ; V_111 < V_129 ; V_111 ++ ) {
V_62 -> V_88 [ V_111 ] . V_44 = 0 ;
if ( V_112 <= V_128 ) {
V_62 -> V_88 [ V_111 ] . V_124 =
V_112 ;
V_112 = 0 ;
} else {
V_62 -> V_88 [ V_111 ] . V_124 =
V_128 ;
V_112 -= V_128 ;
}
V_62 -> V_88 [ V_111 ] . V_126 =
F_48 ( ( void * ) ( V_108 -
V_112 ) ) >> V_127 ;
V_62 -> V_87 ++ ;
if ( V_112 == 0 )
break;
}
}
F_49 ( V_3 , V_62 ) ;
F_40 ( V_62 ->
V_76 . V_101 . V_120 ) ;
}
F_11 ( V_3 ) ;
}
static void F_50 ( void * V_95 )
{
int V_11 ;
struct V_2 * V_3 = V_95 ;
struct V_1 * V_4 ;
T_2 V_130 ;
T_1 V_131 ;
unsigned char * V_67 ;
struct V_66 * V_132 ;
unsigned char * V_133 ;
int V_134 = V_135 ;
V_67 = F_2 ( V_135 * sizeof( unsigned char ) ,
V_136 ) ;
if ( ! V_67 )
return;
V_133 = V_67 ;
V_4 = F_10 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( & V_3 -> V_3 , L_17
L_34 , V_4 ) ;
goto V_137;
}
do {
V_11 = F_51 ( V_3 -> V_21 , V_133 , V_134 ,
& V_130 , & V_131 ) ;
if ( V_11 == 0 ) {
if ( V_130 > 0 ) {
V_132 = (struct V_66 * ) V_133 ;
switch ( V_132 -> type ) {
case V_94 :
F_35 ( V_3 , V_132 ) ;
break;
case V_114 :
F_44 ( V_3 , V_132 ) ;
break;
default:
F_18 ( & V_3 -> V_3 ,
L_35
L_36 ,
V_132 -> type , V_131 ,
V_130 ) ;
break;
}
if ( V_134 > V_135 ) {
F_7 ( V_133 ) ;
V_133 = V_67 ;
V_134 = V_135 ;
}
} else {
if ( V_134 > V_135 ) {
F_7 ( V_133 ) ;
V_133 = V_67 ;
V_134 = V_135 ;
}
break;
}
} else if ( V_11 == - 2 ) {
V_133 = F_27 ( V_130 , V_136 ) ;
if ( V_133 == NULL ) {
F_18 ( & V_3 -> V_3 ,
L_37
L_38 , V_130 ) ;
break;
}
V_134 = V_130 ;
}
} while ( 1 );
F_11 ( V_3 ) ;
V_137:
F_7 ( V_133 ) ;
return;
}
int F_52 ( struct V_2 * V_3 , void * V_138 )
{
int V_11 = 0 ;
int V_110 ;
int V_139 =
( (struct V_140 * ) V_138 ) -> V_139 ;
struct V_1 * V_4 ;
struct V_61 * V_67 , * V_63 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_11 = - 1 ;
goto V_30;
}
V_4 -> V_25 = V_141 ;
F_53 ( & V_4 -> V_98 ) ;
F_54 ( & V_4 -> V_103 ) ;
for ( V_110 = 0 ; V_110 < V_142 ; V_110 ++ ) {
V_67 = F_2 ( sizeof( struct V_61 ) +
( V_143 *
sizeof( struct V_144 ) ) , V_5 ) ;
if ( ! V_67 )
break;
F_42 ( & V_67 -> V_65 ,
& V_4 -> V_103 ) ;
}
F_55 ( & V_4 -> V_36 ) ;
V_11 = F_56 ( V_3 -> V_21 , V_139 * V_128 ,
V_139 * V_128 , NULL , 0 ,
F_50 , V_3 ) ;
if ( V_11 != 0 ) {
F_18 ( & V_3 -> V_3 , L_39 , V_11 ) ;
V_11 = - 1 ;
goto V_30;
}
F_57 ( L_40 ) ;
V_11 = F_28 ( V_3 ) ;
if ( V_11 != 0 ) {
F_18 ( & V_3 -> V_3 ,
L_41 , V_11 ) ;
V_11 = - 1 ;
goto V_145;
}
return V_11 ;
V_145:
F_32 ( V_3 -> V_21 ) ;
V_30:
if ( V_4 ) {
F_33 (packet, pos,
&net_device->recv_pkt_list,
list_ent) {
F_34 ( & V_67 -> V_65 ) ;
F_7 ( V_67 ) ;
}
F_13 ( V_3 ) ;
F_15 ( V_3 ) ;
F_4 ( V_4 ) ;
}
return V_11 ;
}
int F_58 ( struct V_146 * V_147 )
{
V_147 -> V_148 = V_149 ;
memcpy ( & V_147 -> V_150 , & V_151 , sizeof( struct V_152 ) ) ;
return 0 ;
}
