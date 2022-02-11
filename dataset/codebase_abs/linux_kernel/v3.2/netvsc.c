static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_4 = F_3 ( sizeof( struct V_1 ) , V_6 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_7 = false ;
V_4 -> V_8 = V_3 ;
V_4 -> V_5 = V_5 ;
F_4 ( V_3 , V_4 ) ;
return V_4 ;
}
static struct V_1 * F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( V_4 && V_4 -> V_7 )
V_4 = NULL ;
return V_4 ;
}
static struct V_1 * F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 )
goto V_9;
if ( V_4 -> V_7 &&
F_7 ( & V_4 -> V_10 ) == 0 )
V_4 = NULL ;
V_9:
return V_4 ;
}
static int F_8 ( struct V_1 * V_4 )
{
struct V_11 * V_12 ;
int V_13 = 0 ;
struct V_4 * V_5 = V_4 -> V_5 ;
if ( V_4 -> V_14 ) {
V_12 = & V_4 -> V_12 ;
memset ( V_12 , 0 , sizeof( struct V_11 ) ) ;
V_12 -> V_15 . V_16 =
V_17 ;
V_12 -> V_18 . V_19 .
V_20 . V_21 = V_22 ;
V_13 = F_9 ( V_4 -> V_8 -> V_23 ,
V_12 ,
sizeof( struct V_11 ) ,
( unsigned long ) V_12 ,
V_24 , 0 ) ;
if ( V_13 != 0 ) {
F_10 ( V_5 , L_1
L_2 ) ;
return V_13 ;
}
}
if ( V_4 -> V_25 ) {
V_13 = F_11 ( V_4 -> V_8 -> V_23 ,
V_4 -> V_25 ) ;
if ( V_13 != 0 ) {
F_10 ( V_5 ,
L_3 ) ;
return V_13 ;
}
V_4 -> V_25 = 0 ;
}
if ( V_4 -> V_26 ) {
F_12 ( ( unsigned long ) V_4 -> V_26 ,
F_13 ( V_4 -> V_27 ) ) ;
V_4 -> V_26 = NULL ;
}
if ( V_4 -> V_28 ) {
V_4 -> V_14 = 0 ;
F_14 ( V_4 -> V_28 ) ;
V_4 -> V_28 = NULL ;
}
return V_13 ;
}
static int F_15 ( struct V_2 * V_3 )
{
int V_13 = 0 ;
int V_29 ;
struct V_1 * V_4 ;
struct V_11 * V_30 ;
struct V_4 * V_5 ;
V_4 = F_5 ( V_3 ) ;
if ( ! V_4 )
return - V_31 ;
V_5 = V_4 -> V_5 ;
V_4 -> V_26 =
( void * ) F_16 ( V_6 | V_32 ,
F_13 ( V_4 -> V_27 ) ) ;
if ( ! V_4 -> V_26 ) {
F_10 ( V_5 , L_4
L_5 , V_4 -> V_27 ) ;
V_13 = - V_33 ;
goto V_34;
}
V_13 = F_17 ( V_3 -> V_23 , V_4 -> V_26 ,
V_4 -> V_27 ,
& V_4 -> V_25 ) ;
if ( V_13 != 0 ) {
F_10 ( V_5 ,
L_6 ) ;
goto V_34;
}
V_30 = & V_4 -> V_35 ;
memset ( V_30 , 0 , sizeof( struct V_11 ) ) ;
V_30 -> V_15 . V_16 = V_36 ;
V_30 -> V_18 . V_19 . V_37 .
V_38 = V_4 -> V_25 ;
V_30 -> V_18 . V_19 .
V_37 . V_21 = V_22 ;
V_13 = F_9 ( V_3 -> V_23 , V_30 ,
sizeof( struct V_11 ) ,
( unsigned long ) V_30 ,
V_24 ,
V_39 ) ;
if ( V_13 != 0 ) {
F_10 ( V_5 ,
L_7 ) ;
goto V_34;
}
V_29 = F_18 ( & V_4 -> V_40 , 5 * V_41 ) ;
F_19 ( V_29 == 0 ) ;
if ( V_30 -> V_18 . V_19 .
V_42 . V_43 != V_44 ) {
F_10 ( V_5 , L_8
L_9 ,
V_30 -> V_18 . V_19 .
V_42 . V_43 ) ;
V_13 = - V_45 ;
goto V_34;
}
V_4 -> V_14 = V_30 -> V_18 .
V_19 . V_42 . V_46 ;
V_4 -> V_28 = F_20 ( V_4 -> V_14
* sizeof( struct V_47 ) , V_6 ) ;
if ( V_4 -> V_28 == NULL ) {
V_13 = - V_45 ;
goto V_34;
}
memcpy ( V_4 -> V_28 ,
V_30 -> V_18 . V_19 .
V_42 . V_48 ,
V_4 -> V_14 *
sizeof( struct V_47 ) ) ;
if ( V_4 -> V_14 != 1 ||
V_4 -> V_28 -> V_49 != 0 ) {
V_13 = - V_45 ;
goto V_34;
}
goto exit;
V_34:
F_8 ( V_4 ) ;
exit:
return V_13 ;
}
static int F_21 ( struct V_2 * V_3 )
{
int V_13 , V_29 ;
struct V_1 * V_4 ;
struct V_11 * V_30 ;
int V_50 ;
struct V_4 * V_5 ;
V_4 = F_5 ( V_3 ) ;
if ( ! V_4 )
return - V_31 ;
V_5 = V_4 -> V_5 ;
V_30 = & V_4 -> V_35 ;
memset ( V_30 , 0 , sizeof( struct V_11 ) ) ;
V_30 -> V_15 . V_16 = V_51 ;
V_30 -> V_18 . V_52 . V_53 . V_54 =
V_55 ;
V_30 -> V_18 . V_52 . V_53 . V_56 =
V_57 ;
V_13 = F_9 ( V_3 -> V_23 , V_30 ,
sizeof( struct V_11 ) ,
( unsigned long ) V_30 ,
V_24 ,
V_39 ) ;
if ( V_13 != 0 )
goto V_34;
V_29 = F_18 ( & V_4 -> V_40 , 5 * V_41 ) ;
if ( V_29 == 0 ) {
V_13 = - V_58 ;
goto V_34;
}
if ( V_30 -> V_18 . V_52 . V_59 . V_43 !=
V_44 ) {
V_13 = - V_45 ;
goto V_34;
}
if ( V_30 -> V_18 . V_52 . V_59 .
V_60 != V_61 ) {
V_13 = - V_62 ;
goto V_34;
}
memset ( V_30 , 0 , sizeof( struct V_11 ) ) ;
V_50 = 0x00050000 ;
V_30 -> V_15 . V_16 = V_63 ;
V_30 -> V_18 . V_19 .
V_64 . V_65 =
( V_50 & 0xFFFF0000 ) >> 16 ;
V_30 -> V_18 . V_19 .
V_64 . V_66 =
V_50 & 0xFFFF ;
V_13 = F_9 ( V_3 -> V_23 , V_30 ,
sizeof( struct V_11 ) ,
( unsigned long ) V_30 ,
V_24 , 0 ) ;
if ( V_13 != 0 )
goto V_34;
V_13 = F_15 ( V_3 ) ;
V_34:
return V_13 ;
}
static void F_22 ( struct V_1 * V_4 )
{
F_8 ( V_4 ) ;
}
int F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_67 * V_68 , * V_69 ;
unsigned long V_70 ;
V_4 = F_2 ( V_3 ) ;
F_24 ( & V_3 -> V_23 -> V_71 , V_70 ) ;
V_4 -> V_7 = true ;
F_25 ( & V_3 -> V_23 -> V_71 , V_70 ) ;
while ( F_7 ( & V_4 -> V_10 ) ) {
F_26 ( & V_3 -> V_3 ,
L_10 ,
F_7 ( & V_4 -> V_10 ) ) ;
F_27 ( 100 ) ;
}
F_22 ( V_4 ) ;
F_24 ( & V_3 -> V_23 -> V_71 , V_70 ) ;
F_4 ( V_3 , NULL ) ;
F_25 ( & V_3 -> V_23 -> V_71 , V_70 ) ;
F_28 ( & V_3 -> V_3 , L_11 ) ;
F_29 ( V_3 -> V_23 ) ;
F_30 (netvsc_packet, pos,
&net_device->recv_pkt_list, list_ent) {
F_31 ( & V_68 -> V_72 ) ;
F_14 ( V_68 ) ;
}
F_14 ( V_4 ) ;
return 0 ;
}
static void F_32 ( struct V_2 * V_3 ,
struct V_73 * V_74 )
{
struct V_1 * V_4 ;
struct V_11 * V_75 ;
struct V_67 * V_76 ;
struct V_4 * V_5 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
V_75 = (struct V_11 * ) ( ( unsigned long ) V_74 +
( V_74 -> V_77 << 3 ) ) ;
if ( ( V_75 -> V_15 . V_16 == V_78 ) ||
( V_75 -> V_15 . V_16 ==
V_79 ) ||
( V_75 -> V_15 . V_16 ==
V_80 ) ) {
memcpy ( & V_4 -> V_35 , V_75 ,
sizeof( struct V_11 ) ) ;
F_33 ( & V_4 -> V_40 ) ;
} else if ( V_75 -> V_15 . V_16 ==
V_81 ) {
V_76 = (struct V_67 * ) ( unsigned long )
V_74 -> V_82 ;
V_76 -> V_83 . V_84 . V_85 (
V_76 -> V_83 . V_84 . V_86 ) ;
F_34 ( & V_4 -> V_10 ) ;
} else {
F_10 ( V_5 , L_12
L_13 , V_75 -> V_15 . V_16 ) ;
}
}
int F_35 ( struct V_2 * V_3 ,
struct V_67 * V_74 )
{
struct V_1 * V_4 ;
int V_13 = 0 ;
struct V_11 V_87 ;
struct V_4 * V_5 ;
V_4 = F_5 ( V_3 ) ;
if ( ! V_4 )
return - V_31 ;
V_5 = V_4 -> V_5 ;
V_87 . V_15 . V_16 = V_88 ;
if ( V_74 -> V_89 ) {
V_87 . V_18 . V_19 . V_90 . V_91 = 0 ;
} else {
V_87 . V_18 . V_19 . V_90 . V_91 = 1 ;
}
V_87 . V_18 . V_19 . V_90 . V_92 =
0xFFFFFFFF ;
V_87 . V_18 . V_19 . V_90 . V_93 = 0 ;
if ( V_74 -> V_94 ) {
V_13 = F_36 ( V_3 -> V_23 ,
V_74 -> V_95 ,
V_74 -> V_94 ,
& V_87 ,
sizeof( struct V_11 ) ,
( unsigned long ) V_74 ) ;
} else {
V_13 = F_9 ( V_3 -> V_23 , & V_87 ,
sizeof( struct V_11 ) ,
( unsigned long ) V_74 ,
V_24 ,
V_39 ) ;
}
if ( V_13 != 0 )
F_10 ( V_5 , L_14 ,
V_74 , V_13 ) ;
else
F_37 ( & V_4 -> V_10 ) ;
return V_13 ;
}
static void F_38 ( struct V_2 * V_3 ,
T_1 V_96 )
{
struct V_11 V_97 ;
int V_98 = 0 ;
int V_13 ;
struct V_4 * V_5 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
V_5 = V_4 -> V_5 ;
V_97 . V_15 . V_16 =
V_81 ;
V_97 . V_18 . V_19 . V_99 . V_43 =
V_44 ;
V_100:
V_13 = F_9 ( V_3 -> V_23 , & V_97 ,
sizeof( struct V_11 ) , V_96 ,
V_101 , 0 ) ;
if ( V_13 == 0 ) {
} else if ( V_13 == - V_102 ) {
V_98 ++ ;
F_10 ( V_5 , L_15
L_16 , V_96 , V_98 ) ;
if ( V_98 < 4 ) {
F_27 ( 100 ) ;
goto V_100;
} else {
F_10 ( V_5 , L_17
L_18 ,
V_96 ) ;
}
} else {
F_10 ( V_5 , L_17
L_19 , V_96 ) ;
}
}
static void F_39 ( void * V_103 )
{
struct V_67 * V_74 = V_103 ;
struct V_2 * V_3 = (struct V_2 * ) V_74 -> V_3 ;
struct V_1 * V_4 ;
T_1 V_96 = 0 ;
bool V_104 = false ;
unsigned long V_70 ;
struct V_4 * V_5 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
F_24 ( & V_4 -> V_105 , V_70 ) ;
V_74 -> V_106 -> V_107 -- ;
if ( V_74 -> V_106 -> V_107 == 0 ) {
V_104 = true ;
V_96 = V_74 -> V_83 . V_108 . V_109 ;
F_40 ( & V_74 -> V_106 -> V_72 ,
& V_4 -> V_110 ) ;
}
F_40 ( & V_74 -> V_72 , & V_4 -> V_110 ) ;
F_25 ( & V_4 -> V_105 , V_70 ) ;
if ( V_104 )
F_38 ( V_3 , V_96 ) ;
}
static void F_41 ( struct V_2 * V_3 ,
struct V_73 * V_74 )
{
struct V_1 * V_4 ;
struct V_111 * V_112 ;
struct V_11 * V_75 ;
struct V_67 * V_68 = NULL ;
unsigned long V_113 ;
unsigned long V_114 , V_115 ;
struct V_116 * V_116 = NULL ;
int V_117 , V_118 ;
int V_107 = 0 , V_119 = 0 ;
unsigned long V_70 ;
struct V_4 * V_5 ;
F_42 ( V_120 ) ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
if ( V_74 -> type != V_121 ) {
F_10 ( V_5 , L_20 ,
V_74 -> type ) ;
return;
}
V_75 = (struct V_11 * ) ( ( unsigned long ) V_74 +
( V_74 -> V_77 << 3 ) ) ;
if ( V_75 -> V_15 . V_16 !=
V_88 ) {
F_10 ( V_5 , L_21
L_22 , V_75 -> V_15 . V_16 ) ;
return;
}
V_112 = (struct V_111 * ) V_74 ;
if ( V_112 -> V_122 != V_22 ) {
F_10 ( V_5 , L_23
L_24 , V_22 ,
V_112 -> V_122 ) ;
return;
}
F_24 ( & V_4 -> V_105 , V_70 ) ;
while ( ! F_43 ( & V_4 -> V_110 ) ) {
F_44 ( V_4 -> V_110 . V_123 , & V_120 ) ;
if ( ++ V_107 == V_112 -> V_124 + 1 )
break;
}
F_25 ( & V_4 -> V_105 , V_70 ) ;
if ( V_107 < 2 ) {
F_10 ( V_5 , L_25
L_26 ,
V_107 , V_112 -> V_124 + 1 ) ;
F_24 ( & V_4 -> V_105 , V_70 ) ;
for ( V_117 = V_107 ; V_117 != 0 ; V_117 -- ) {
F_44 ( V_120 . V_123 ,
& V_4 -> V_110 ) ;
}
F_25 ( & V_4 -> V_105 ,
V_70 ) ;
F_38 ( V_3 ,
V_112 -> V_125 . V_82 ) ;
return;
}
V_116 = (struct V_116 * ) V_120 . V_123 ;
F_31 ( & V_116 -> V_72 ) ;
V_116 -> V_107 = V_107 - 1 ;
if ( V_116 -> V_107 != V_112 -> V_124 ) {
F_10 ( V_5 , L_27
L_28 ,
V_112 -> V_124 , V_116 -> V_107 ) ;
}
for ( V_117 = 0 ; V_117 < ( V_107 - 1 ) ; V_117 ++ ) {
V_68 = (struct V_67 * ) V_120 . V_123 ;
F_31 ( & V_68 -> V_72 ) ;
V_68 -> V_106 = V_116 ;
V_68 -> V_83 . V_108 . V_126 =
F_39 ;
V_68 -> V_83 . V_108 . V_127 =
V_68 ;
V_68 -> V_3 = V_3 ;
V_68 -> V_83 . V_108 . V_109 =
V_112 -> V_125 . V_82 ;
V_68 -> V_128 =
V_112 -> V_129 [ V_117 ] . V_130 ;
V_68 -> V_94 = 1 ;
V_68 -> V_95 [ 0 ] . V_131 =
V_112 -> V_129 [ V_117 ] . V_130 ;
V_113 = F_45 ( ( void * ) ( ( unsigned long ) V_4 ->
V_26 + V_112 -> V_129 [ V_117 ] . V_132 ) ) ;
V_68 -> V_95 [ 0 ] . V_133 = V_113 >> V_134 ;
V_115 = ( unsigned long ) V_4 -> V_26
+ V_112 -> V_129 [ V_117 ] . V_132
+ V_112 -> V_129 [ V_117 ] . V_130 - 1 ;
V_114 = F_45 ( ( void * ) V_115 ) ;
V_68 -> V_95 [ 0 ] . V_49 =
V_112 -> V_129 [ V_117 ] . V_132 &
( V_135 - 1 ) ;
if ( ( V_114 >> V_134 ) != ( V_113 >> V_134 ) ) {
V_68 -> V_95 [ 0 ] . V_131 =
( V_68 -> V_95 [ 0 ] . V_133 <<
V_134 )
+ V_135 - V_113 ;
V_119 = V_68 -> V_128 -
V_68 -> V_95 [ 0 ] . V_131 ;
for ( V_118 = 1 ; V_118 < V_136 ; V_118 ++ ) {
V_68 -> V_95 [ V_118 ] . V_49 = 0 ;
if ( V_119 <= V_135 ) {
V_68 -> V_95 [ V_118 ] . V_131 =
V_119 ;
V_119 = 0 ;
} else {
V_68 -> V_95 [ V_118 ] . V_131 =
V_135 ;
V_119 -= V_135 ;
}
V_68 -> V_95 [ V_118 ] . V_133 =
F_45 ( ( void * ) ( V_115 -
V_119 ) ) >> V_134 ;
V_68 -> V_94 ++ ;
if ( V_119 == 0 )
break;
}
}
F_46 ( V_3 , V_68 ) ;
F_39 ( V_68 ->
V_83 . V_108 . V_127 ) ;
}
}
static void F_47 ( void * V_103 )
{
int V_13 ;
struct V_2 * V_3 = V_103 ;
struct V_1 * V_4 ;
T_2 V_137 ;
T_1 V_138 ;
unsigned char * V_74 ;
struct V_73 * V_139 ;
unsigned char * V_140 ;
int V_141 = V_142 ;
struct V_4 * V_5 ;
V_74 = F_3 ( V_142 * sizeof( unsigned char ) ,
V_143 ) ;
if ( ! V_74 )
return;
V_140 = V_74 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
goto V_144;
V_5 = V_4 -> V_5 ;
do {
V_13 = F_48 ( V_3 -> V_23 , V_140 , V_141 ,
& V_137 , & V_138 ) ;
if ( V_13 == 0 ) {
if ( V_137 > 0 ) {
V_139 = (struct V_73 * ) V_140 ;
switch ( V_139 -> type ) {
case V_101 :
F_32 ( V_3 , V_139 ) ;
break;
case V_121 :
F_41 ( V_3 , V_139 ) ;
break;
default:
F_10 ( V_5 ,
L_29
L_30 ,
V_139 -> type , V_138 ,
V_137 ) ;
break;
}
if ( V_141 > V_142 ) {
F_14 ( V_140 ) ;
V_140 = V_74 ;
V_141 = V_142 ;
}
} else {
if ( V_141 > V_142 ) {
F_14 ( V_140 ) ;
V_140 = V_74 ;
V_141 = V_142 ;
}
break;
}
} else if ( V_13 == - V_145 ) {
V_140 = F_20 ( V_137 , V_143 ) ;
if ( V_140 == NULL ) {
F_10 ( V_5 ,
L_31
L_32 , V_137 ) ;
break;
}
V_141 = V_137 ;
}
} while ( 1 );
V_144:
F_14 ( V_140 ) ;
return;
}
int F_49 ( struct V_2 * V_3 , void * V_146 )
{
int V_13 = 0 ;
int V_117 ;
int V_147 =
( (struct V_148 * ) V_146 ) -> V_147 ;
struct V_1 * V_4 ;
struct V_67 * V_74 , * V_69 ;
struct V_4 * V_5 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_13 = - V_33 ;
goto V_34;
}
V_5 = V_4 -> V_5 ;
V_4 -> V_27 = V_149 ;
F_50 ( & V_4 -> V_105 ) ;
F_51 ( & V_4 -> V_110 ) ;
for ( V_117 = 0 ; V_117 < V_150 ; V_117 ++ ) {
V_74 = F_3 ( sizeof( struct V_67 ) +
( V_151 *
sizeof( struct V_152 ) ) , V_6 ) ;
if ( ! V_74 )
break;
F_40 ( & V_74 -> V_72 ,
& V_4 -> V_110 ) ;
}
F_52 ( & V_4 -> V_40 ) ;
V_13 = F_53 ( V_3 -> V_23 , V_147 * V_135 ,
V_147 * V_135 , NULL , 0 ,
F_47 , V_3 ) ;
if ( V_13 != 0 ) {
F_10 ( V_5 , L_33 , V_13 ) ;
goto V_34;
}
F_54 ( L_34 ) ;
V_13 = F_21 ( V_3 ) ;
if ( V_13 != 0 ) {
F_10 ( V_5 ,
L_35 , V_13 ) ;
goto V_153;
}
return V_13 ;
V_153:
F_29 ( V_3 -> V_23 ) ;
V_34:
if ( V_4 ) {
F_30 (packet, pos,
&net_device->recv_pkt_list,
list_ent) {
F_31 ( & V_74 -> V_72 ) ;
F_14 ( V_74 ) ;
}
F_14 ( V_4 ) ;
}
return V_13 ;
}
