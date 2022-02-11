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
V_31 -> V_19 . V_61 . V_62 . V_64 . V_65 = 1 ;
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
int V_66 ;
struct V_4 * V_5 ;
V_4 = F_5 ( V_3 ) ;
if ( ! V_4 )
return - V_32 ;
V_5 = V_4 -> V_5 ;
V_31 = & V_4 -> V_36 ;
if ( F_21 ( V_3 , V_4 , V_31 ,
V_59 ) == 0 ) {
V_4 -> V_67 = V_59 ;
} else if ( F_21 ( V_3 , V_4 , V_31 ,
V_68 ) == 0 ) {
V_4 -> V_67 = V_68 ;
} else {
V_14 = - V_69 ;
goto V_35;
}
F_23 ( L_10 , V_4 -> V_67 ) ;
memset ( V_31 , 0 , sizeof( struct V_12 ) ) ;
V_66 = 0x00050001 ;
V_31 -> V_16 . V_17 = V_70 ;
V_31 -> V_19 . V_20 .
V_71 . V_72 =
( V_66 & 0xFFFF0000 ) >> 16 ;
V_31 -> V_19 . V_20 .
V_71 . V_73 =
V_66 & 0xFFFF ;
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
struct V_74 * V_75 , * V_76 ;
unsigned long V_77 ;
V_4 = F_2 ( V_3 ) ;
F_26 ( & V_3 -> V_24 -> V_78 , V_77 ) ;
V_4 -> V_8 = true ;
F_27 ( & V_3 -> V_24 -> V_78 , V_77 ) ;
while ( F_7 ( & V_4 -> V_11 ) ) {
F_28 ( & V_3 -> V_3 ,
L_11 ,
F_7 ( & V_4 -> V_11 ) ) ;
F_29 ( 100 ) ;
}
F_24 ( V_4 ) ;
F_26 ( & V_3 -> V_24 -> V_78 , V_77 ) ;
F_4 ( V_3 , NULL ) ;
F_27 ( & V_3 -> V_24 -> V_78 , V_77 ) ;
F_30 ( & V_3 -> V_3 , L_12 ) ;
F_31 ( V_3 -> V_24 ) ;
F_32 (netvsc_packet, pos,
&net_device->recv_pkt_list, list_ent) {
F_33 ( & V_75 -> V_79 ) ;
F_14 ( V_75 ) ;
}
F_14 ( V_4 ) ;
return 0 ;
}
static void F_34 ( struct V_2 * V_3 ,
struct V_80 * V_81 )
{
struct V_1 * V_4 ;
struct V_12 * V_82 ;
struct V_74 * V_83 ;
struct V_4 * V_5 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
V_82 = (struct V_12 * ) ( ( unsigned long ) V_81 +
( V_81 -> V_84 << 3 ) ) ;
if ( ( V_82 -> V_16 . V_17 == V_85 ) ||
( V_82 -> V_16 . V_17 ==
V_86 ) ||
( V_82 -> V_16 . V_17 ==
V_87 ) ) {
memcpy ( & V_4 -> V_36 , V_82 ,
sizeof( struct V_12 ) ) ;
F_35 ( & V_4 -> V_41 ) ;
} else if ( V_82 -> V_16 . V_17 ==
V_88 ) {
V_83 = (struct V_74 * ) ( unsigned long )
V_81 -> V_89 ;
V_83 -> V_90 . V_91 . V_92 (
V_83 -> V_90 . V_91 . V_93 ) ;
F_36 ( & V_4 -> V_11 ) ;
if ( F_37 ( V_5 ) && ! V_4 -> V_7 )
F_38 ( V_5 ) ;
} else {
F_10 ( V_5 , L_13
L_14 , V_82 -> V_16 . V_17 ) ;
}
}
int F_39 ( struct V_2 * V_3 ,
struct V_74 * V_81 )
{
struct V_1 * V_4 ;
int V_14 = 0 ;
struct V_12 V_94 ;
struct V_4 * V_5 ;
V_4 = F_5 ( V_3 ) ;
if ( ! V_4 )
return - V_32 ;
V_5 = V_4 -> V_5 ;
V_94 . V_16 . V_17 = V_95 ;
if ( V_81 -> V_96 ) {
V_94 . V_19 . V_20 . V_97 . V_98 = 0 ;
} else {
V_94 . V_19 . V_20 . V_97 . V_98 = 1 ;
}
V_94 . V_19 . V_20 . V_97 . V_99 =
0xFFFFFFFF ;
V_94 . V_19 . V_20 . V_97 . V_100 = 0 ;
if ( V_81 -> V_101 ) {
V_14 = F_40 ( V_3 -> V_24 ,
V_81 -> V_102 ,
V_81 -> V_101 ,
& V_94 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_81 ) ;
} else {
V_14 = F_9 ( V_3 -> V_24 , & V_94 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_81 ,
V_25 ,
V_40 ) ;
}
if ( V_14 == 0 ) {
F_41 ( & V_4 -> V_11 ) ;
} else if ( V_14 == - V_103 ) {
F_42 ( V_5 ) ;
if ( F_7 ( & V_4 -> V_11 ) < 1 )
F_38 ( V_5 ) ;
} else {
F_10 ( V_5 , L_15 ,
V_81 , V_14 ) ;
}
return V_14 ;
}
static void F_43 ( struct V_2 * V_3 ,
T_2 V_104 )
{
struct V_12 V_105 ;
int V_106 = 0 ;
int V_14 ;
struct V_4 * V_5 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
V_5 = V_4 -> V_5 ;
V_105 . V_16 . V_17 =
V_88 ;
V_105 . V_19 . V_20 . V_107 . V_44 =
V_45 ;
V_108:
V_14 = F_9 ( V_3 -> V_24 , & V_105 ,
sizeof( struct V_12 ) , V_104 ,
V_109 , 0 ) ;
if ( V_14 == 0 ) {
} else if ( V_14 == - V_103 ) {
V_106 ++ ;
F_10 ( V_5 , L_16
L_17 , V_104 , V_106 ) ;
if ( V_106 < 4 ) {
F_29 ( 100 ) ;
goto V_108;
} else {
F_10 ( V_5 , L_18
L_19 ,
V_104 ) ;
}
} else {
F_10 ( V_5 , L_18
L_20 , V_104 ) ;
}
}
static void F_44 ( void * V_110 )
{
struct V_74 * V_81 = V_110 ;
struct V_2 * V_3 = (struct V_2 * ) V_81 -> V_3 ;
struct V_1 * V_4 ;
T_2 V_104 = 0 ;
bool V_111 = false ;
unsigned long V_77 ;
struct V_4 * V_5 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
F_26 ( & V_4 -> V_112 , V_77 ) ;
V_81 -> V_113 -> V_114 -- ;
if ( V_81 -> V_113 -> V_114 == 0 ) {
V_111 = true ;
V_104 = V_81 -> V_90 . V_115 . V_116 ;
F_45 ( & V_81 -> V_113 -> V_79 ,
& V_4 -> V_117 ) ;
}
F_45 ( & V_81 -> V_79 , & V_4 -> V_117 ) ;
F_27 ( & V_4 -> V_112 , V_77 ) ;
if ( V_111 )
F_43 ( V_3 , V_104 ) ;
}
static void F_46 ( struct V_2 * V_3 ,
struct V_80 * V_81 )
{
struct V_1 * V_4 ;
struct V_118 * V_119 ;
struct V_12 * V_82 ;
struct V_74 * V_75 = NULL ;
struct V_120 * V_120 = NULL ;
int V_121 ;
int V_114 = 0 ;
unsigned long V_77 ;
struct V_4 * V_5 ;
F_47 ( V_122 ) ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
if ( V_81 -> type != V_123 ) {
F_10 ( V_5 , L_21 ,
V_81 -> type ) ;
return;
}
V_82 = (struct V_12 * ) ( ( unsigned long ) V_81 +
( V_81 -> V_84 << 3 ) ) ;
if ( V_82 -> V_16 . V_17 !=
V_95 ) {
F_10 ( V_5 , L_22
L_23 , V_82 -> V_16 . V_17 ) ;
return;
}
V_119 = (struct V_118 * ) V_81 ;
if ( V_119 -> V_124 != V_23 ) {
F_10 ( V_5 , L_24
L_25 , V_23 ,
V_119 -> V_124 ) ;
return;
}
F_26 ( & V_4 -> V_112 , V_77 ) ;
while ( ! F_48 ( & V_4 -> V_117 ) ) {
F_49 ( V_4 -> V_117 . V_125 , & V_122 ) ;
if ( ++ V_114 == V_119 -> V_126 + 1 )
break;
}
F_27 ( & V_4 -> V_112 , V_77 ) ;
if ( V_114 < 2 ) {
F_10 ( V_5 , L_26
L_27 ,
V_114 , V_119 -> V_126 + 1 ) ;
F_26 ( & V_4 -> V_112 , V_77 ) ;
for ( V_121 = V_114 ; V_121 != 0 ; V_121 -- ) {
F_49 ( V_122 . V_125 ,
& V_4 -> V_117 ) ;
}
F_27 ( & V_4 -> V_112 ,
V_77 ) ;
F_43 ( V_3 ,
V_119 -> V_127 . V_89 ) ;
return;
}
V_120 = (struct V_120 * ) V_122 . V_125 ;
F_33 ( & V_120 -> V_79 ) ;
V_120 -> V_114 = V_114 - 1 ;
if ( V_120 -> V_114 != V_119 -> V_126 ) {
F_10 ( V_5 , L_28
L_29 ,
V_119 -> V_126 , V_120 -> V_114 ) ;
}
for ( V_121 = 0 ; V_121 < ( V_114 - 1 ) ; V_121 ++ ) {
V_75 = (struct V_74 * ) V_122 . V_125 ;
F_33 ( & V_75 -> V_79 ) ;
V_75 -> V_113 = V_120 ;
V_75 -> V_90 . V_115 . V_128 =
F_44 ;
V_75 -> V_90 . V_115 . V_129 =
V_75 ;
V_75 -> V_3 = V_3 ;
V_75 -> V_90 . V_115 . V_116 =
V_119 -> V_127 . V_89 ;
V_75 -> V_130 = ( void * ) ( ( unsigned long ) V_4 ->
V_27 + V_119 -> V_131 [ V_121 ] . V_132 ) ;
V_75 -> V_133 =
V_119 -> V_131 [ V_121 ] . V_134 ;
F_50 ( V_3 , V_75 ) ;
F_44 ( V_75 ->
V_90 . V_115 . V_129 ) ;
}
}
static void F_51 ( void * V_110 )
{
int V_14 ;
struct V_2 * V_3 = V_110 ;
struct V_1 * V_4 ;
T_1 V_135 ;
T_2 V_136 ;
unsigned char * V_81 ;
struct V_80 * V_137 ;
unsigned char * V_138 ;
int V_139 = V_140 ;
struct V_4 * V_5 ;
V_81 = F_3 ( V_140 * sizeof( unsigned char ) ,
V_141 ) ;
if ( ! V_81 )
return;
V_138 = V_81 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
goto V_142;
V_5 = V_4 -> V_5 ;
do {
V_14 = F_52 ( V_3 -> V_24 , V_138 , V_139 ,
& V_135 , & V_136 ) ;
if ( V_14 == 0 ) {
if ( V_135 > 0 ) {
V_137 = (struct V_80 * ) V_138 ;
switch ( V_137 -> type ) {
case V_109 :
F_34 ( V_3 , V_137 ) ;
break;
case V_123 :
F_46 ( V_3 , V_137 ) ;
break;
default:
F_10 ( V_5 ,
L_30
L_31 ,
V_137 -> type , V_136 ,
V_135 ) ;
break;
}
if ( V_139 > V_140 ) {
F_14 ( V_138 ) ;
V_138 = V_81 ;
V_139 = V_140 ;
}
} else {
if ( V_139 > V_140 ) {
F_14 ( V_138 ) ;
V_138 = V_81 ;
V_139 = V_140 ;
}
break;
}
} else if ( V_14 == - V_143 ) {
V_138 = F_53 ( V_135 , V_141 ) ;
if ( V_138 == NULL ) {
F_10 ( V_5 ,
L_32
L_33 , V_135 ) ;
break;
}
V_139 = V_135 ;
}
} while ( 1 );
V_142:
F_14 ( V_138 ) ;
return;
}
int F_54 ( struct V_2 * V_3 , void * V_144 )
{
int V_14 = 0 ;
int V_121 ;
int V_145 =
( (struct V_146 * ) V_144 ) -> V_145 ;
struct V_1 * V_4 ;
struct V_74 * V_81 , * V_76 ;
struct V_4 * V_5 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_14 = - V_34 ;
goto V_35;
}
V_5 = V_4 -> V_5 ;
V_4 -> V_28 = V_147 ;
F_55 ( & V_4 -> V_112 ) ;
F_56 ( & V_4 -> V_117 ) ;
for ( V_121 = 0 ; V_121 < V_148 ; V_121 ++ ) {
V_81 = F_3 ( sizeof( struct V_74 ) +
( V_149 *
sizeof( struct V_150 ) ) , V_6 ) ;
if ( ! V_81 )
break;
F_45 ( & V_81 -> V_79 ,
& V_4 -> V_117 ) ;
}
F_57 ( & V_4 -> V_41 ) ;
V_14 = F_58 ( V_3 -> V_24 , V_145 * V_151 ,
V_145 * V_151 , NULL , 0 ,
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
goto V_152;
}
return V_14 ;
V_152:
F_31 ( V_3 -> V_24 ) ;
V_35:
if ( V_4 ) {
F_32 (packet, pos,
&net_device->recv_pkt_list,
list_ent) {
F_33 ( & V_81 -> V_79 ) ;
F_14 ( V_81 ) ;
}
F_14 ( V_4 ) ;
}
return V_14 ;
}
