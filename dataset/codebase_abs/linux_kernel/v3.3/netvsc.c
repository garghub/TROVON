static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_4 = F_3 ( sizeof( struct V_1 ) , V_6 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_7 = false ;
V_4 -> V_8 = false ;
V_4 -> V_9 = V_3 ;
V_4 -> V_5 = V_5 ;
F_4 ( V_3 , V_4 ) ;
return V_4 ;
}
static struct V_1 * F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( V_4 && V_4 -> V_8 )
V_4 = NULL ;
return V_4 ;
}
static struct V_1 * F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 )
goto V_10;
if ( V_4 -> V_8 &&
F_7 ( & V_4 -> V_11 ) == 0 )
V_4 = NULL ;
V_10:
return V_4 ;
}
static int F_8 ( struct V_1 * V_4 )
{
struct V_12 * V_13 ;
int V_14 = 0 ;
struct V_4 * V_5 = V_4 -> V_5 ;
if ( V_4 -> V_15 ) {
V_13 = & V_4 -> V_13 ;
memset ( V_13 , 0 , sizeof( struct V_12 ) ) ;
V_13 -> V_16 . V_17 =
V_18 ;
V_13 -> V_19 . V_20 .
V_21 . V_22 = V_23 ;
V_14 = F_9 ( V_4 -> V_9 -> V_24 ,
V_13 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_13 ,
V_25 , 0 ) ;
if ( V_14 != 0 ) {
F_10 ( V_5 , L_1
L_2 ) ;
return V_14 ;
}
}
if ( V_4 -> V_26 ) {
V_14 = F_11 ( V_4 -> V_9 -> V_24 ,
V_4 -> V_26 ) ;
if ( V_14 != 0 ) {
F_10 ( V_5 ,
L_3 ) ;
return V_14 ;
}
V_4 -> V_26 = 0 ;
}
if ( V_4 -> V_27 ) {
F_12 ( ( unsigned long ) V_4 -> V_27 ,
F_13 ( V_4 -> V_28 ) ) ;
V_4 -> V_27 = NULL ;
}
if ( V_4 -> V_29 ) {
V_4 -> V_15 = 0 ;
F_14 ( V_4 -> V_29 ) ;
V_4 -> V_29 = NULL ;
}
return V_14 ;
}
static int F_15 ( struct V_2 * V_3 )
{
int V_14 = 0 ;
int V_30 ;
struct V_1 * V_4 ;
struct V_12 * V_31 ;
struct V_4 * V_5 ;
V_4 = F_5 ( V_3 ) ;
if ( ! V_4 )
return - V_32 ;
V_5 = V_4 -> V_5 ;
V_4 -> V_27 =
( void * ) F_16 ( V_6 | V_33 ,
F_13 ( V_4 -> V_28 ) ) ;
if ( ! V_4 -> V_27 ) {
F_10 ( V_5 , L_4
L_5 , V_4 -> V_28 ) ;
V_14 = - V_34 ;
goto V_35;
}
V_14 = F_17 ( V_3 -> V_24 , V_4 -> V_27 ,
V_4 -> V_28 ,
& V_4 -> V_26 ) ;
if ( V_14 != 0 ) {
F_10 ( V_5 ,
L_6 ) ;
goto V_35;
}
V_31 = & V_4 -> V_36 ;
memset ( V_31 , 0 , sizeof( struct V_12 ) ) ;
V_31 -> V_16 . V_17 = V_37 ;
V_31 -> V_19 . V_20 . V_38 .
V_39 = V_4 -> V_26 ;
V_31 -> V_19 . V_20 .
V_38 . V_22 = V_23 ;
V_14 = F_9 ( V_3 -> V_24 , V_31 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_31 ,
V_25 ,
V_40 ) ;
if ( V_14 != 0 ) {
F_10 ( V_5 ,
L_7 ) ;
goto V_35;
}
V_30 = F_18 ( & V_4 -> V_41 , 5 * V_42 ) ;
F_19 ( V_30 == 0 ) ;
if ( V_31 -> V_19 . V_20 .
V_43 . V_44 != V_45 ) {
F_10 ( V_5 , L_8
L_9 ,
V_31 -> V_19 . V_20 .
V_43 . V_44 ) ;
V_14 = - V_46 ;
goto V_35;
}
V_4 -> V_15 = V_31 -> V_19 .
V_20 . V_43 . V_47 ;
V_4 -> V_29 = F_20 (
V_31 -> V_19 . V_20 . V_43 . V_48 ,
V_4 -> V_15 *
sizeof( struct V_49 ) ,
V_6 ) ;
if ( V_4 -> V_29 == NULL ) {
V_14 = - V_46 ;
goto V_35;
}
if ( V_4 -> V_15 != 1 ||
V_4 -> V_29 -> V_50 != 0 ) {
V_14 = - V_46 ;
goto V_35;
}
goto exit;
V_35:
F_8 ( V_4 ) ;
exit:
return V_14 ;
}
static int F_21 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_12 * V_31 ,
T_1 V_51 )
{
int V_14 , V_30 ;
memset ( V_31 , 0 , sizeof( struct V_12 ) ) ;
V_31 -> V_16 . V_17 = V_52 ;
V_31 -> V_19 . V_53 . V_54 . V_55 = V_51 ;
V_31 -> V_19 . V_53 . V_54 . V_56 = V_51 ;
V_14 = F_9 ( V_3 -> V_24 , V_31 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_31 ,
V_25 ,
V_40 ) ;
if ( V_14 != 0 )
return V_14 ;
V_30 = F_18 ( & V_4 -> V_41 , 5 * V_42 ) ;
if ( V_30 == 0 )
return - V_57 ;
if ( V_31 -> V_19 . V_53 . V_58 . V_44 !=
V_45 )
return - V_46 ;
if ( V_51 != V_59 )
return 0 ;
memset ( V_31 , 0 , sizeof( struct V_12 ) ) ;
V_31 -> V_16 . V_17 = V_60 ;
V_31 -> V_19 . V_61 . V_62 . V_63 = V_4 -> V_5 -> V_63 ;
V_14 = F_9 ( V_3 -> V_24 , V_31 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_31 ,
V_25 , 0 ) ;
return V_14 ;
}
static int F_22 ( struct V_2 * V_3 )
{
int V_14 ;
struct V_1 * V_4 ;
struct V_12 * V_31 ;
int V_64 ;
struct V_4 * V_5 ;
V_4 = F_5 ( V_3 ) ;
if ( ! V_4 )
return - V_32 ;
V_5 = V_4 -> V_5 ;
V_31 = & V_4 -> V_36 ;
if ( F_21 ( V_3 , V_4 , V_31 ,
V_59 ) == 0 ) {
V_4 -> V_65 = V_59 ;
} else if ( F_21 ( V_3 , V_4 , V_31 ,
V_66 ) == 0 ) {
V_4 -> V_65 = V_66 ;
} else {
V_14 = - V_67 ;
goto V_35;
}
F_23 ( L_10 , V_4 -> V_65 ) ;
memset ( V_31 , 0 , sizeof( struct V_12 ) ) ;
V_64 = 0x00050000 ;
V_31 -> V_16 . V_17 = V_68 ;
V_31 -> V_19 . V_20 .
V_69 . V_70 =
( V_64 & 0xFFFF0000 ) >> 16 ;
V_31 -> V_19 . V_20 .
V_69 . V_71 =
V_64 & 0xFFFF ;
V_14 = F_9 ( V_3 -> V_24 , V_31 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_31 ,
V_25 , 0 ) ;
if ( V_14 != 0 )
goto V_35;
V_14 = F_15 ( V_3 ) ;
V_35:
return V_14 ;
}
static void F_24 ( struct V_1 * V_4 )
{
F_8 ( V_4 ) ;
}
int F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_72 * V_73 , * V_74 ;
unsigned long V_75 ;
V_4 = F_2 ( V_3 ) ;
F_26 ( & V_3 -> V_24 -> V_76 , V_75 ) ;
V_4 -> V_8 = true ;
F_27 ( & V_3 -> V_24 -> V_76 , V_75 ) ;
while ( F_7 ( & V_4 -> V_11 ) ) {
F_28 ( & V_3 -> V_3 ,
L_11 ,
F_7 ( & V_4 -> V_11 ) ) ;
F_29 ( 100 ) ;
}
F_24 ( V_4 ) ;
F_26 ( & V_3 -> V_24 -> V_76 , V_75 ) ;
F_4 ( V_3 , NULL ) ;
F_27 ( & V_3 -> V_24 -> V_76 , V_75 ) ;
F_30 ( & V_3 -> V_3 , L_12 ) ;
F_31 ( V_3 -> V_24 ) ;
F_32 (netvsc_packet, pos,
&net_device->recv_pkt_list, list_ent) {
F_33 ( & V_73 -> V_77 ) ;
F_14 ( V_73 ) ;
}
F_14 ( V_4 ) ;
return 0 ;
}
static void F_34 ( struct V_2 * V_3 ,
struct V_78 * V_79 )
{
struct V_1 * V_4 ;
struct V_12 * V_80 ;
struct V_72 * V_81 ;
struct V_4 * V_5 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
V_80 = (struct V_12 * ) ( ( unsigned long ) V_79 +
( V_79 -> V_82 << 3 ) ) ;
if ( ( V_80 -> V_16 . V_17 == V_83 ) ||
( V_80 -> V_16 . V_17 ==
V_84 ) ||
( V_80 -> V_16 . V_17 ==
V_85 ) ) {
memcpy ( & V_4 -> V_36 , V_80 ,
sizeof( struct V_12 ) ) ;
F_35 ( & V_4 -> V_41 ) ;
} else if ( V_80 -> V_16 . V_17 ==
V_86 ) {
V_81 = (struct V_72 * ) ( unsigned long )
V_79 -> V_87 ;
V_81 -> V_88 . V_89 . V_90 (
V_81 -> V_88 . V_89 . V_91 ) ;
F_36 ( & V_4 -> V_11 ) ;
if ( F_37 ( V_5 ) && ! V_4 -> V_7 )
F_38 ( V_5 ) ;
} else {
F_10 ( V_5 , L_13
L_14 , V_80 -> V_16 . V_17 ) ;
}
}
int F_39 ( struct V_2 * V_3 ,
struct V_72 * V_79 )
{
struct V_1 * V_4 ;
int V_14 = 0 ;
struct V_12 V_92 ;
struct V_4 * V_5 ;
V_4 = F_5 ( V_3 ) ;
if ( ! V_4 )
return - V_32 ;
V_5 = V_4 -> V_5 ;
V_92 . V_16 . V_17 = V_93 ;
if ( V_79 -> V_94 ) {
V_92 . V_19 . V_20 . V_95 . V_96 = 0 ;
} else {
V_92 . V_19 . V_20 . V_95 . V_96 = 1 ;
}
V_92 . V_19 . V_20 . V_95 . V_97 =
0xFFFFFFFF ;
V_92 . V_19 . V_20 . V_95 . V_98 = 0 ;
if ( V_79 -> V_99 ) {
V_14 = F_40 ( V_3 -> V_24 ,
V_79 -> V_100 ,
V_79 -> V_99 ,
& V_92 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_79 ) ;
} else {
V_14 = F_9 ( V_3 -> V_24 , & V_92 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_79 ,
V_25 ,
V_40 ) ;
}
if ( V_14 == 0 ) {
F_41 ( & V_4 -> V_11 ) ;
} else if ( V_14 == - V_101 ) {
F_42 ( V_5 ) ;
if ( F_7 ( & V_4 -> V_11 ) < 1 )
F_38 ( V_5 ) ;
} else {
F_10 ( V_5 , L_15 ,
V_79 , V_14 ) ;
}
return V_14 ;
}
static void F_43 ( struct V_2 * V_3 ,
T_2 V_102 )
{
struct V_12 V_103 ;
int V_104 = 0 ;
int V_14 ;
struct V_4 * V_5 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
V_5 = V_4 -> V_5 ;
V_103 . V_16 . V_17 =
V_86 ;
V_103 . V_19 . V_20 . V_105 . V_44 =
V_45 ;
V_106:
V_14 = F_9 ( V_3 -> V_24 , & V_103 ,
sizeof( struct V_12 ) , V_102 ,
V_107 , 0 ) ;
if ( V_14 == 0 ) {
} else if ( V_14 == - V_101 ) {
V_104 ++ ;
F_10 ( V_5 , L_16
L_17 , V_102 , V_104 ) ;
if ( V_104 < 4 ) {
F_29 ( 100 ) ;
goto V_106;
} else {
F_10 ( V_5 , L_18
L_19 ,
V_102 ) ;
}
} else {
F_10 ( V_5 , L_18
L_20 , V_102 ) ;
}
}
static void F_44 ( void * V_108 )
{
struct V_72 * V_79 = V_108 ;
struct V_2 * V_3 = (struct V_2 * ) V_79 -> V_3 ;
struct V_1 * V_4 ;
T_2 V_102 = 0 ;
bool V_109 = false ;
unsigned long V_75 ;
struct V_4 * V_5 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
F_26 ( & V_4 -> V_110 , V_75 ) ;
V_79 -> V_111 -> V_112 -- ;
if ( V_79 -> V_111 -> V_112 == 0 ) {
V_109 = true ;
V_102 = V_79 -> V_88 . V_113 . V_114 ;
F_45 ( & V_79 -> V_111 -> V_77 ,
& V_4 -> V_115 ) ;
}
F_45 ( & V_79 -> V_77 , & V_4 -> V_115 ) ;
F_27 ( & V_4 -> V_110 , V_75 ) ;
if ( V_109 )
F_43 ( V_3 , V_102 ) ;
}
static void F_46 ( struct V_2 * V_3 ,
struct V_78 * V_79 )
{
struct V_1 * V_4 ;
struct V_116 * V_117 ;
struct V_12 * V_80 ;
struct V_72 * V_73 = NULL ;
struct V_118 * V_118 = NULL ;
int V_119 ;
int V_112 = 0 ;
unsigned long V_75 ;
struct V_4 * V_5 ;
F_47 ( V_120 ) ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
if ( V_79 -> type != V_121 ) {
F_10 ( V_5 , L_21 ,
V_79 -> type ) ;
return;
}
V_80 = (struct V_12 * ) ( ( unsigned long ) V_79 +
( V_79 -> V_82 << 3 ) ) ;
if ( V_80 -> V_16 . V_17 !=
V_93 ) {
F_10 ( V_5 , L_22
L_23 , V_80 -> V_16 . V_17 ) ;
return;
}
V_117 = (struct V_116 * ) V_79 ;
if ( V_117 -> V_122 != V_23 ) {
F_10 ( V_5 , L_24
L_25 , V_23 ,
V_117 -> V_122 ) ;
return;
}
F_26 ( & V_4 -> V_110 , V_75 ) ;
while ( ! F_48 ( & V_4 -> V_115 ) ) {
F_49 ( V_4 -> V_115 . V_123 , & V_120 ) ;
if ( ++ V_112 == V_117 -> V_124 + 1 )
break;
}
F_27 ( & V_4 -> V_110 , V_75 ) ;
if ( V_112 < 2 ) {
F_10 ( V_5 , L_26
L_27 ,
V_112 , V_117 -> V_124 + 1 ) ;
F_26 ( & V_4 -> V_110 , V_75 ) ;
for ( V_119 = V_112 ; V_119 != 0 ; V_119 -- ) {
F_49 ( V_120 . V_123 ,
& V_4 -> V_115 ) ;
}
F_27 ( & V_4 -> V_110 ,
V_75 ) ;
F_43 ( V_3 ,
V_117 -> V_125 . V_87 ) ;
return;
}
V_118 = (struct V_118 * ) V_120 . V_123 ;
F_33 ( & V_118 -> V_77 ) ;
V_118 -> V_112 = V_112 - 1 ;
if ( V_118 -> V_112 != V_117 -> V_124 ) {
F_10 ( V_5 , L_28
L_29 ,
V_117 -> V_124 , V_118 -> V_112 ) ;
}
for ( V_119 = 0 ; V_119 < ( V_112 - 1 ) ; V_119 ++ ) {
V_73 = (struct V_72 * ) V_120 . V_123 ;
F_33 ( & V_73 -> V_77 ) ;
V_73 -> V_111 = V_118 ;
V_73 -> V_88 . V_113 . V_126 =
F_44 ;
V_73 -> V_88 . V_113 . V_127 =
V_73 ;
V_73 -> V_3 = V_3 ;
V_73 -> V_88 . V_113 . V_114 =
V_117 -> V_125 . V_87 ;
V_73 -> V_128 = ( void * ) ( ( unsigned long ) V_4 ->
V_27 + V_117 -> V_129 [ V_119 ] . V_130 ) ;
V_73 -> V_131 =
V_117 -> V_129 [ V_119 ] . V_132 ;
F_50 ( V_3 , V_73 ) ;
F_44 ( V_73 ->
V_88 . V_113 . V_127 ) ;
}
}
static void F_51 ( void * V_108 )
{
int V_14 ;
struct V_2 * V_3 = V_108 ;
struct V_1 * V_4 ;
T_1 V_133 ;
T_2 V_134 ;
unsigned char * V_79 ;
struct V_78 * V_135 ;
unsigned char * V_136 ;
int V_137 = V_138 ;
struct V_4 * V_5 ;
V_79 = F_3 ( V_138 * sizeof( unsigned char ) ,
V_139 ) ;
if ( ! V_79 )
return;
V_136 = V_79 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
goto V_140;
V_5 = V_4 -> V_5 ;
do {
V_14 = F_52 ( V_3 -> V_24 , V_136 , V_137 ,
& V_133 , & V_134 ) ;
if ( V_14 == 0 ) {
if ( V_133 > 0 ) {
V_135 = (struct V_78 * ) V_136 ;
switch ( V_135 -> type ) {
case V_107 :
F_34 ( V_3 , V_135 ) ;
break;
case V_121 :
F_46 ( V_3 , V_135 ) ;
break;
default:
F_10 ( V_5 ,
L_30
L_31 ,
V_135 -> type , V_134 ,
V_133 ) ;
break;
}
if ( V_137 > V_138 ) {
F_14 ( V_136 ) ;
V_136 = V_79 ;
V_137 = V_138 ;
}
} else {
if ( V_137 > V_138 ) {
F_14 ( V_136 ) ;
V_136 = V_79 ;
V_137 = V_138 ;
}
break;
}
} else if ( V_14 == - V_141 ) {
V_136 = F_53 ( V_133 , V_139 ) ;
if ( V_136 == NULL ) {
F_10 ( V_5 ,
L_32
L_33 , V_133 ) ;
break;
}
V_137 = V_133 ;
}
} while ( 1 );
V_140:
F_14 ( V_136 ) ;
return;
}
int F_54 ( struct V_2 * V_3 , void * V_142 )
{
int V_14 = 0 ;
int V_119 ;
int V_143 =
( (struct V_144 * ) V_142 ) -> V_143 ;
struct V_1 * V_4 ;
struct V_72 * V_79 , * V_74 ;
struct V_4 * V_5 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_14 = - V_34 ;
goto V_35;
}
V_5 = V_4 -> V_5 ;
V_4 -> V_28 = V_145 ;
F_55 ( & V_4 -> V_110 ) ;
F_56 ( & V_4 -> V_115 ) ;
for ( V_119 = 0 ; V_119 < V_146 ; V_119 ++ ) {
V_79 = F_3 ( sizeof( struct V_72 ) +
( V_147 *
sizeof( struct V_148 ) ) , V_6 ) ;
if ( ! V_79 )
break;
F_45 ( & V_79 -> V_77 ,
& V_4 -> V_115 ) ;
}
F_57 ( & V_4 -> V_41 ) ;
V_14 = F_58 ( V_3 -> V_24 , V_143 * V_149 ,
V_143 * V_149 , NULL , 0 ,
F_51 , V_3 ) ;
if ( V_14 != 0 ) {
F_10 ( V_5 , L_34 , V_14 ) ;
goto V_35;
}
F_59 ( L_35 ) ;
V_14 = F_22 ( V_3 ) ;
if ( V_14 != 0 ) {
F_10 ( V_5 ,
L_36 , V_14 ) ;
goto V_150;
}
return V_14 ;
V_150:
F_31 ( V_3 -> V_24 ) ;
V_35:
if ( V_4 ) {
F_32 (packet, pos,
&net_device->recv_pkt_list,
list_ent) {
F_33 ( & V_79 -> V_77 ) ;
F_14 ( V_79 ) ;
}
F_14 ( V_4 ) ;
}
return V_14 ;
}
