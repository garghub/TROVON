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
V_27 = F_25 ( & V_4 -> V_36 , V_37 ) ;
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
static int F_28 ( struct V_1 * V_4 )
{
struct V_9 * V_10 ;
int V_11 = 0 ;
if ( V_4 -> V_45 ) {
V_10 = & V_4 -> V_10 ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_13 . V_14 =
V_46 ;
V_10 -> V_16 . V_17 .
V_47 . V_19 = V_48 ;
V_11 = F_17 ( V_4 -> V_7 -> V_21 ,
V_10 ,
sizeof( struct V_9 ) ,
( unsigned long ) V_10 ,
V_22 , 0 ) ;
if ( V_11 != 0 ) {
F_18 ( & V_4 -> V_7 -> V_3 , L_1
L_12 ) ;
return - 1 ;
}
}
if ( V_4 -> V_49 ) {
V_11 = F_19 ( V_4 -> V_7 -> V_21 ,
V_4 -> V_49 ) ;
if ( V_11 != 0 ) {
F_18 ( & V_4 -> V_7 -> V_3 ,
L_13 ) ;
return - 1 ;
}
V_4 -> V_49 = 0 ;
}
if ( V_4 -> V_50 ) {
F_20 ( ( unsigned long ) V_4 -> V_50 ,
F_21 ( V_4 -> V_51 ) ) ;
V_4 -> V_50 = NULL ;
}
return V_11 ;
}
static int F_29 ( struct V_2 * V_3 )
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
if ( V_4 -> V_51 <= 0 ) {
V_11 = - V_52 ;
goto V_30;
}
V_4 -> V_50 =
( void * ) F_23 ( V_5 | V_29 ,
F_21 ( V_4 -> V_51 ) ) ;
if ( ! V_4 -> V_50 ) {
F_18 ( & V_3 -> V_3 , L_14
L_7 , V_4 -> V_51 ) ;
V_11 = - 1 ;
goto V_30;
}
V_11 = F_24 ( V_3 -> V_21 , V_4 -> V_50 ,
V_4 -> V_51 ,
& V_4 -> V_49 ) ;
if ( V_11 != 0 ) {
F_18 ( & V_3 -> V_3 , L_15 ) ;
goto V_30;
}
V_28 = & V_4 -> V_31 ;
memset ( V_28 , 0 , sizeof( struct V_9 ) ) ;
V_28 -> V_13 . V_14 = V_53 ;
V_28 -> V_16 . V_17 . V_33 .
V_34 = V_4 -> V_49 ;
V_28 -> V_16 . V_17 . V_33 . V_19 =
V_48 ;
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
V_27 = F_25 ( & V_4 -> V_36 , V_37 ) ;
F_26 ( V_27 == 0 ) ;
if ( V_28 -> V_16 . V_17 .
V_54 . V_39 != V_40 ) {
F_18 ( & V_3 -> V_3 , L_16
L_11 ,
V_28 -> V_16 . V_17 .
V_54 . V_39 ) ;
V_11 = - 1 ;
goto V_30;
}
V_4 -> V_45 = V_28 ->
V_16 . V_17 . V_54 . V_55 ;
goto exit;
V_30:
F_28 ( V_4 ) ;
exit:
F_11 ( V_3 ) ;
return V_11 ;
}
static int F_30 ( struct V_2 * V_3 )
{
int V_11 , V_27 ;
struct V_1 * V_4 ;
struct V_9 * V_28 ;
int V_56 ;
V_4 = F_8 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( & V_3 -> V_3 , L_4
L_5 ) ;
return - 1 ;
}
V_28 = & V_4 -> V_31 ;
memset ( V_28 , 0 , sizeof( struct V_9 ) ) ;
V_28 -> V_13 . V_14 = V_57 ;
V_28 -> V_16 . V_58 . V_59 . V_60 =
V_61 ;
V_28 -> V_16 . V_58 . V_59 . V_62 =
V_63 ;
V_11 = F_17 ( V_3 -> V_21 , V_28 ,
sizeof( struct V_9 ) ,
( unsigned long ) V_28 ,
V_22 ,
V_35 ) ;
if ( V_11 != 0 )
goto V_30;
V_27 = F_25 ( & V_4 -> V_36 , V_37 ) ;
if ( V_27 == 0 ) {
V_11 = - V_64 ;
goto V_30;
}
if ( V_28 -> V_16 . V_58 . V_65 . V_39 !=
V_40 ) {
V_11 = - 1 ;
goto V_30;
}
if ( V_28 -> V_16 . V_58 . V_65 .
V_66 != V_67 ) {
V_11 = - 1 ;
goto V_30;
}
memset ( V_28 , 0 , sizeof( struct V_9 ) ) ;
V_56 = 0x00050000 ;
V_28 -> V_13 . V_14 = V_68 ;
V_28 -> V_16 . V_17 .
V_69 . V_70 =
( V_56 & 0xFFFF0000 ) >> 16 ;
V_28 -> V_16 . V_17 .
V_69 . V_71 =
V_56 & 0xFFFF ;
V_11 = F_17 ( V_3 -> V_21 , V_28 ,
sizeof( struct V_9 ) ,
( unsigned long ) V_28 ,
V_22 , 0 ) ;
if ( V_11 != 0 ) {
V_11 = - 1 ;
goto V_30;
}
V_11 = F_22 ( V_3 ) ;
if ( V_11 == 0 )
V_11 = F_29 ( V_3 ) ;
V_30:
F_11 ( V_3 ) ;
return V_11 ;
}
static void F_31 ( struct V_1 * V_4 )
{
F_16 ( V_4 ) ;
F_28 ( V_4 ) ;
}
int F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_72 * V_73 , * V_74 ;
V_4 = F_13 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( & V_3 -> V_3 , L_17 ) ;
return - 1 ;
}
while ( F_6 ( & V_4 -> V_75 ) ) {
F_18 ( & V_3 -> V_3 ,
L_18 ,
F_6 ( & V_4 -> V_75 ) ) ;
F_14 ( 100 ) ;
}
F_31 ( V_4 ) ;
V_4 = F_15 ( V_3 ) ;
F_33 ( & V_3 -> V_3 , L_19 ) ;
F_34 ( V_3 -> V_21 ) ;
F_35 (netvsc_packet, pos,
&net_device->recv_pkt_list, list_ent) {
F_36 ( & V_73 -> V_76 ) ;
F_7 ( V_73 ) ;
}
F_4 ( V_4 ) ;
return 0 ;
}
static void F_37 ( struct V_2 * V_3 ,
struct V_77 * V_78 )
{
struct V_1 * V_4 ;
struct V_9 * V_79 ;
struct V_72 * V_80 ;
V_4 = F_10 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( & V_3 -> V_3 , L_4
L_5 ) ;
return;
}
V_79 = (struct V_9 * ) ( ( unsigned long ) V_78 +
( V_78 -> V_81 << 3 ) ) ;
if ( ( V_79 -> V_13 . V_14 == V_82 ) ||
( V_79 -> V_13 . V_14 ==
V_83 ) ||
( V_79 -> V_13 . V_14 ==
V_84 ) ) {
memcpy ( & V_4 -> V_31 , V_79 ,
sizeof( struct V_9 ) ) ;
F_38 ( & V_4 -> V_36 ) ;
} else if ( V_79 -> V_13 . V_14 ==
V_85 ) {
V_80 = (struct V_72 * ) ( unsigned long )
V_78 -> V_86 ;
V_80 -> V_87 . V_88 . V_89 (
V_80 -> V_87 . V_88 . V_90 ) ;
F_12 ( & V_4 -> V_75 ) ;
} else {
F_18 ( & V_3 -> V_3 , L_20
L_21 , V_79 -> V_13 . V_14 ) ;
}
F_11 ( V_3 ) ;
}
int F_39 ( struct V_2 * V_3 ,
struct V_72 * V_78 )
{
struct V_1 * V_4 ;
int V_11 = 0 ;
struct V_9 V_91 ;
V_4 = F_8 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( & V_3 -> V_3 , L_22
L_23 , V_4 ) ;
return - 2 ;
}
V_91 . V_13 . V_14 = V_92 ;
if ( V_78 -> V_93 ) {
V_91 . V_16 . V_17 . V_94 . V_95 = 0 ;
} else {
V_91 . V_16 . V_17 . V_94 . V_95 = 1 ;
}
V_91 . V_16 . V_17 . V_94 . V_96 =
0xFFFFFFFF ;
V_91 . V_16 . V_17 . V_94 . V_97 = 0 ;
if ( V_78 -> V_98 ) {
V_11 = F_40 ( V_3 -> V_21 ,
V_78 -> V_99 ,
V_78 -> V_98 ,
& V_91 ,
sizeof( struct V_9 ) ,
( unsigned long ) V_78 ) ;
} else {
V_11 = F_17 ( V_3 -> V_21 , & V_91 ,
sizeof( struct V_9 ) ,
( unsigned long ) V_78 ,
V_22 ,
V_35 ) ;
}
if ( V_11 != 0 )
F_18 ( & V_3 -> V_3 , L_24 ,
V_78 , V_11 ) ;
F_9 ( & V_4 -> V_75 ) ;
F_11 ( V_3 ) ;
return V_11 ;
}
static void F_41 ( struct V_2 * V_3 ,
T_1 V_100 )
{
struct V_9 V_101 ;
int V_102 = 0 ;
int V_11 ;
V_101 . V_13 . V_14 =
V_85 ;
V_101 . V_16 . V_17 . V_103 . V_39 =
V_40 ;
V_104:
V_11 = F_17 ( V_3 -> V_21 , & V_101 ,
sizeof( struct V_9 ) , V_100 ,
V_105 , 0 ) ;
if ( V_11 == 0 ) {
} else if ( V_11 == - 1 ) {
V_102 ++ ;
F_18 ( & V_3 -> V_3 , L_25
L_26 , V_100 , V_102 ) ;
if ( V_102 < 4 ) {
F_14 ( 100 ) ;
goto V_104;
} else {
F_18 ( & V_3 -> V_3 , L_27
L_28 ,
V_100 ) ;
}
} else {
F_18 ( & V_3 -> V_3 , L_27
L_29 , V_100 ) ;
}
}
static void F_42 ( void * V_106 )
{
struct V_72 * V_78 = V_106 ;
struct V_2 * V_3 = (struct V_2 * ) V_78 -> V_3 ;
struct V_1 * V_4 ;
T_1 V_100 = 0 ;
bool V_107 = false ;
unsigned long V_108 ;
V_4 = F_10 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( & V_3 -> V_3 , L_4
L_5 ) ;
return;
}
F_43 ( & V_4 -> V_109 , V_108 ) ;
V_78 -> V_110 -> V_111 -- ;
if ( V_78 -> V_110 -> V_111 == 0 ) {
V_107 = true ;
V_100 = V_78 -> V_87 . V_112 . V_113 ;
F_44 ( & V_78 -> V_110 -> V_76 ,
& V_4 -> V_114 ) ;
}
F_44 ( & V_78 -> V_76 , & V_4 -> V_114 ) ;
F_45 ( & V_4 -> V_109 , V_108 ) ;
if ( V_107 )
F_41 ( V_3 , V_100 ) ;
F_11 ( V_3 ) ;
}
static void F_46 ( struct V_2 * V_3 ,
struct V_77 * V_78 )
{
struct V_1 * V_4 ;
struct V_115 * V_116 ;
struct V_9 * V_79 ;
struct V_72 * V_73 = NULL ;
unsigned long V_117 ;
unsigned long V_118 , V_119 ;
struct V_120 * V_120 = NULL ;
int V_121 , V_122 ;
int V_111 = 0 , V_123 = 0 ;
unsigned long V_108 ;
F_47 ( V_124 ) ;
V_4 = F_10 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( & V_3 -> V_3 , L_4
L_5 ) ;
return;
}
if ( V_78 -> type != V_125 ) {
F_18 ( & V_3 -> V_3 , L_30 ,
V_78 -> type ) ;
F_11 ( V_3 ) ;
return;
}
V_79 = (struct V_9 * ) ( ( unsigned long ) V_78 +
( V_78 -> V_81 << 3 ) ) ;
if ( V_79 -> V_13 . V_14 !=
V_92 ) {
F_18 ( & V_3 -> V_3 , L_31
L_32 , V_79 -> V_13 . V_14 ) ;
F_11 ( V_3 ) ;
return;
}
V_116 = (struct V_115 * ) V_78 ;
if ( V_116 -> V_126 != V_20 ) {
F_18 ( & V_3 -> V_3 , L_33
L_34 , V_20 ,
V_116 -> V_126 ) ;
F_11 ( V_3 ) ;
return;
}
F_43 ( & V_4 -> V_109 , V_108 ) ;
while ( ! F_48 ( & V_4 -> V_114 ) ) {
F_49 ( V_4 -> V_114 . V_127 , & V_124 ) ;
if ( ++ V_111 == V_116 -> V_128 + 1 )
break;
}
F_45 ( & V_4 -> V_109 , V_108 ) ;
if ( V_111 < 2 ) {
F_18 ( & V_3 -> V_3 , L_35
L_36 ,
V_111 , V_116 -> V_128 + 1 ) ;
F_43 ( & V_4 -> V_109 , V_108 ) ;
for ( V_121 = V_111 ; V_121 != 0 ; V_121 -- ) {
F_49 ( V_124 . V_127 ,
& V_4 -> V_114 ) ;
}
F_45 ( & V_4 -> V_109 ,
V_108 ) ;
F_41 ( V_3 ,
V_116 -> V_129 . V_86 ) ;
F_11 ( V_3 ) ;
return;
}
V_120 = (struct V_120 * ) V_124 . V_127 ;
F_36 ( & V_120 -> V_76 ) ;
V_120 -> V_111 = V_111 - 1 ;
if ( V_120 -> V_111 != V_116 -> V_128 ) {
F_18 ( & V_3 -> V_3 , L_37
L_38 ,
V_116 -> V_128 , V_120 -> V_111 ) ;
}
for ( V_121 = 0 ; V_121 < ( V_111 - 1 ) ; V_121 ++ ) {
V_73 = (struct V_72 * ) V_124 . V_127 ;
F_36 ( & V_73 -> V_76 ) ;
V_73 -> V_110 = V_120 ;
V_73 -> V_87 . V_112 . V_130 =
F_42 ;
V_73 -> V_87 . V_112 . V_131 =
V_73 ;
V_73 -> V_3 = V_3 ;
V_73 -> V_87 . V_112 . V_113 =
V_116 -> V_129 . V_86 ;
V_73 -> V_132 =
V_116 -> V_133 [ V_121 ] . V_134 ;
V_73 -> V_98 = 1 ;
V_73 -> V_99 [ 0 ] . V_135 =
V_116 -> V_133 [ V_121 ] . V_134 ;
V_117 = F_50 ( ( void * ) ( ( unsigned long ) V_4 ->
V_24 + V_116 -> V_133 [ V_121 ] . V_136 ) ) ;
V_73 -> V_99 [ 0 ] . V_137 = V_117 >> V_138 ;
V_119 = ( unsigned long ) V_4 -> V_24
+ V_116 -> V_133 [ V_121 ] . V_136
+ V_116 -> V_133 [ V_121 ] . V_134 - 1 ;
V_118 = F_50 ( ( void * ) V_119 ) ;
V_73 -> V_99 [ 0 ] . V_44 =
V_116 -> V_133 [ V_121 ] . V_136 &
( V_139 - 1 ) ;
if ( ( V_118 >> V_138 ) != ( V_117 >> V_138 ) ) {
V_73 -> V_99 [ 0 ] . V_135 =
( V_73 -> V_99 [ 0 ] . V_137 <<
V_138 )
+ V_139 - V_117 ;
V_123 = V_73 -> V_132 -
V_73 -> V_99 [ 0 ] . V_135 ;
for ( V_122 = 1 ; V_122 < V_140 ; V_122 ++ ) {
V_73 -> V_99 [ V_122 ] . V_44 = 0 ;
if ( V_123 <= V_139 ) {
V_73 -> V_99 [ V_122 ] . V_135 =
V_123 ;
V_123 = 0 ;
} else {
V_73 -> V_99 [ V_122 ] . V_135 =
V_139 ;
V_123 -= V_139 ;
}
V_73 -> V_99 [ V_122 ] . V_137 =
F_50 ( ( void * ) ( V_119 -
V_123 ) ) >> V_138 ;
V_73 -> V_98 ++ ;
if ( V_123 == 0 )
break;
}
}
F_51 ( V_3 , V_73 ) ;
F_42 ( V_73 ->
V_87 . V_112 . V_131 ) ;
}
F_11 ( V_3 ) ;
}
static void F_52 ( void * V_106 )
{
int V_11 ;
struct V_2 * V_3 = V_106 ;
struct V_1 * V_4 ;
T_2 V_141 ;
T_1 V_142 ;
unsigned char * V_78 ;
struct V_77 * V_143 ;
unsigned char * V_144 ;
int V_145 = V_146 ;
V_78 = F_2 ( V_146 * sizeof( unsigned char ) ,
V_147 ) ;
if ( ! V_78 )
return;
V_144 = V_78 ;
V_4 = F_10 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( & V_3 -> V_3 , L_22
L_39 , V_4 ) ;
goto V_148;
}
do {
V_11 = F_53 ( V_3 -> V_21 , V_144 , V_145 ,
& V_141 , & V_142 ) ;
if ( V_11 == 0 ) {
if ( V_141 > 0 ) {
V_143 = (struct V_77 * ) V_144 ;
switch ( V_143 -> type ) {
case V_105 :
F_37 ( V_3 , V_143 ) ;
break;
case V_125 :
F_46 ( V_3 , V_143 ) ;
break;
default:
F_18 ( & V_3 -> V_3 ,
L_40
L_41 ,
V_143 -> type , V_142 ,
V_141 ) ;
break;
}
if ( V_145 > V_146 ) {
F_7 ( V_144 ) ;
V_144 = V_78 ;
V_145 = V_146 ;
}
} else {
if ( V_145 > V_146 ) {
F_7 ( V_144 ) ;
V_144 = V_78 ;
V_145 = V_146 ;
}
break;
}
} else if ( V_11 == - 2 ) {
V_144 = F_27 ( V_141 , V_147 ) ;
if ( V_144 == NULL ) {
F_18 ( & V_3 -> V_3 ,
L_42
L_43 , V_141 ) ;
break;
}
V_145 = V_141 ;
}
} while ( 1 );
F_11 ( V_3 ) ;
V_148:
F_7 ( V_144 ) ;
return;
}
int F_54 ( struct V_2 * V_3 , void * V_149 )
{
int V_11 = 0 ;
int V_121 ;
int V_150 =
( (struct V_151 * ) V_149 ) -> V_150 ;
struct V_1 * V_4 ;
struct V_72 * V_78 , * V_74 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_11 = - 1 ;
goto V_30;
}
V_4 -> V_25 = V_152 ;
F_55 ( & V_4 -> V_109 ) ;
V_4 -> V_51 = V_153 ;
F_56 ( & V_4 -> V_114 ) ;
for ( V_121 = 0 ; V_121 < V_154 ; V_121 ++ ) {
V_78 = F_2 ( sizeof( struct V_72 ) +
( V_155 *
sizeof( struct V_156 ) ) , V_5 ) ;
if ( ! V_78 )
break;
F_44 ( & V_78 -> V_76 ,
& V_4 -> V_114 ) ;
}
F_57 ( & V_4 -> V_36 ) ;
V_11 = F_58 ( V_3 -> V_21 , V_150 * V_139 ,
V_150 * V_139 , NULL , 0 ,
F_52 , V_3 ) ;
if ( V_11 != 0 ) {
F_18 ( & V_3 -> V_3 , L_44 , V_11 ) ;
V_11 = - 1 ;
goto V_30;
}
F_59 ( L_45 ) ;
V_11 = F_30 ( V_3 ) ;
if ( V_11 != 0 ) {
F_18 ( & V_3 -> V_3 ,
L_46 , V_11 ) ;
V_11 = - 1 ;
goto V_157;
}
return V_11 ;
V_157:
F_34 ( V_3 -> V_21 ) ;
V_30:
if ( V_4 ) {
F_35 (packet, pos,
&net_device->recv_pkt_list,
list_ent) {
F_36 ( & V_78 -> V_76 ) ;
F_7 ( V_78 ) ;
}
F_13 ( V_3 ) ;
F_15 ( V_3 ) ;
F_4 ( V_4 ) ;
}
return V_11 ;
}
int F_60 ( struct V_158 * V_159 )
{
V_159 -> V_160 = V_161 ;
memcpy ( & V_159 -> V_162 , & V_163 , sizeof( struct V_164 ) ) ;
return 0 ;
}
