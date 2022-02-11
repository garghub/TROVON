static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_4 = F_3 ( sizeof( struct V_1 ) , V_6 ) ;
if ( ! V_4 )
return NULL ;
F_4 ( & V_4 -> V_7 ) ;
V_4 -> V_8 = false ;
V_4 -> V_9 = false ;
V_4 -> V_10 = V_3 ;
V_4 -> V_5 = V_5 ;
F_5 ( V_3 , V_4 ) ;
return V_4 ;
}
static struct V_1 * F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( V_4 && V_4 -> V_9 )
V_4 = NULL ;
return V_4 ;
}
static struct V_1 * F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 )
goto V_11;
if ( V_4 -> V_9 &&
F_8 ( & V_4 -> V_12 ) == 0 )
V_4 = NULL ;
V_11:
return V_4 ;
}
static int F_9 ( struct V_1 * V_4 )
{
struct V_13 * V_14 ;
int V_15 = 0 ;
struct V_4 * V_5 = V_4 -> V_5 ;
if ( V_4 -> V_16 ) {
V_14 = & V_4 -> V_14 ;
memset ( V_14 , 0 , sizeof( struct V_13 ) ) ;
V_14 -> V_17 . V_18 =
V_19 ;
V_14 -> V_20 . V_21 .
V_22 . V_23 = V_24 ;
V_15 = F_10 ( V_4 -> V_10 -> V_25 ,
V_14 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_14 ,
V_26 , 0 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 , L_1
L_2 ) ;
return V_15 ;
}
}
if ( V_4 -> V_27 ) {
V_15 = F_12 ( V_4 -> V_10 -> V_25 ,
V_4 -> V_27 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 ,
L_3 ) ;
return V_15 ;
}
V_4 -> V_27 = 0 ;
}
if ( V_4 -> V_28 ) {
F_13 ( ( unsigned long ) V_4 -> V_28 ,
F_14 ( V_4 -> V_29 ) ) ;
V_4 -> V_28 = NULL ;
}
if ( V_4 -> V_30 ) {
V_4 -> V_16 = 0 ;
F_15 ( V_4 -> V_30 ) ;
V_4 -> V_30 = NULL ;
}
return V_15 ;
}
static int F_16 ( struct V_2 * V_3 )
{
int V_15 = 0 ;
int V_31 ;
struct V_1 * V_4 ;
struct V_13 * V_32 ;
struct V_4 * V_5 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return - V_33 ;
V_5 = V_4 -> V_5 ;
V_4 -> V_28 =
( void * ) F_17 ( V_6 | V_34 ,
F_14 ( V_4 -> V_29 ) ) ;
if ( ! V_4 -> V_28 ) {
F_11 ( V_5 , L_4
L_5 , V_4 -> V_29 ) ;
V_15 = - V_35 ;
goto V_36;
}
V_15 = F_18 ( V_3 -> V_25 , V_4 -> V_28 ,
V_4 -> V_29 ,
& V_4 -> V_27 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 ,
L_6 ) ;
goto V_36;
}
V_32 = & V_4 -> V_37 ;
memset ( V_32 , 0 , sizeof( struct V_13 ) ) ;
V_32 -> V_17 . V_18 = V_38 ;
V_32 -> V_20 . V_21 . V_39 .
V_40 = V_4 -> V_27 ;
V_32 -> V_20 . V_21 .
V_39 . V_23 = V_24 ;
V_15 = F_10 ( V_3 -> V_25 , V_32 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_32 ,
V_26 ,
V_41 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 ,
L_7 ) ;
goto V_36;
}
V_31 = F_19 ( & V_4 -> V_42 , 5 * V_43 ) ;
F_20 ( V_31 == 0 ) ;
if ( V_32 -> V_20 . V_21 .
V_44 . V_45 != V_46 ) {
F_11 ( V_5 , L_8
L_9 ,
V_32 -> V_20 . V_21 .
V_44 . V_45 ) ;
V_15 = - V_47 ;
goto V_36;
}
V_4 -> V_16 = V_32 -> V_20 .
V_21 . V_44 . V_48 ;
V_4 -> V_30 = F_21 (
V_32 -> V_20 . V_21 . V_44 . V_49 ,
V_4 -> V_16 *
sizeof( struct V_50 ) ,
V_6 ) ;
if ( V_4 -> V_30 == NULL ) {
V_15 = - V_47 ;
goto V_36;
}
if ( V_4 -> V_16 != 1 ||
V_4 -> V_30 -> V_51 != 0 ) {
V_15 = - V_47 ;
goto V_36;
}
goto exit;
V_36:
F_9 ( V_4 ) ;
exit:
return V_15 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_13 * V_32 ,
T_1 V_52 )
{
int V_15 , V_31 ;
memset ( V_32 , 0 , sizeof( struct V_13 ) ) ;
V_32 -> V_17 . V_18 = V_53 ;
V_32 -> V_20 . V_54 . V_55 . V_56 = V_52 ;
V_32 -> V_20 . V_54 . V_55 . V_57 = V_52 ;
V_15 = F_10 ( V_3 -> V_25 , V_32 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_32 ,
V_26 ,
V_41 ) ;
if ( V_15 != 0 )
return V_15 ;
V_31 = F_19 ( & V_4 -> V_42 , 5 * V_43 ) ;
if ( V_31 == 0 )
return - V_58 ;
if ( V_32 -> V_20 . V_54 . V_59 . V_45 !=
V_46 )
return - V_47 ;
if ( V_52 != V_60 )
return 0 ;
memset ( V_32 , 0 , sizeof( struct V_13 ) ) ;
V_32 -> V_17 . V_18 = V_61 ;
V_32 -> V_20 . V_62 . V_63 . V_64 = V_4 -> V_5 -> V_64 ;
V_32 -> V_20 . V_62 . V_63 . V_65 . V_66 = 1 ;
V_15 = F_10 ( V_3 -> V_25 , V_32 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_32 ,
V_26 , 0 ) ;
return V_15 ;
}
static int F_23 ( struct V_2 * V_3 )
{
int V_15 ;
struct V_1 * V_4 ;
struct V_13 * V_32 ;
int V_67 ;
struct V_4 * V_5 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return - V_33 ;
V_5 = V_4 -> V_5 ;
V_32 = & V_4 -> V_37 ;
if ( F_22 ( V_3 , V_4 , V_32 ,
V_60 ) == 0 ) {
V_4 -> V_68 = V_60 ;
} else if ( F_22 ( V_3 , V_4 , V_32 ,
V_69 ) == 0 ) {
V_4 -> V_68 = V_69 ;
} else {
V_15 = - V_70 ;
goto V_36;
}
F_24 ( L_10 , V_4 -> V_68 ) ;
memset ( V_32 , 0 , sizeof( struct V_13 ) ) ;
V_67 = 0x00050001 ;
V_32 -> V_17 . V_18 = V_71 ;
V_32 -> V_20 . V_21 .
V_72 . V_73 =
( V_67 & 0xFFFF0000 ) >> 16 ;
V_32 -> V_20 . V_21 .
V_72 . V_74 =
V_67 & 0xFFFF ;
V_15 = F_10 ( V_3 -> V_25 , V_32 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_32 ,
V_26 , 0 ) ;
if ( V_15 != 0 )
goto V_36;
V_15 = F_16 ( V_3 ) ;
V_36:
return V_15 ;
}
static void F_25 ( struct V_1 * V_4 )
{
F_9 ( V_4 ) ;
}
int F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_75 * V_76 , * V_77 ;
unsigned long V_78 ;
V_4 = F_2 ( V_3 ) ;
F_25 ( V_4 ) ;
F_27 ( & V_3 -> V_25 -> V_79 , V_78 ) ;
F_5 ( V_3 , NULL ) ;
F_28 ( & V_3 -> V_25 -> V_79 , V_78 ) ;
F_29 ( & V_3 -> V_3 , L_11 ) ;
F_30 ( V_3 -> V_25 ) ;
F_31 (netvsc_packet, pos,
&net_device->recv_pkt_list, list_ent) {
F_32 ( & V_76 -> V_80 ) ;
F_15 ( V_76 ) ;
}
F_15 ( V_4 ) ;
return 0 ;
}
static inline T_1 F_33 (
struct V_81 * V_82 )
{
T_1 V_83 , V_84 ;
F_34 ( V_82 , & V_83 , & V_84 ) ;
return V_84 * 100 / V_82 -> V_85 ;
}
static void F_35 ( struct V_2 * V_3 ,
struct V_86 * V_87 )
{
struct V_1 * V_4 ;
struct V_13 * V_88 ;
struct V_75 * V_89 ;
struct V_4 * V_5 ;
V_4 = F_7 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
V_88 = (struct V_13 * ) ( ( unsigned long ) V_87 +
( V_87 -> V_90 << 3 ) ) ;
if ( ( V_88 -> V_17 . V_18 == V_91 ) ||
( V_88 -> V_17 . V_18 ==
V_92 ) ||
( V_88 -> V_17 . V_18 ==
V_93 ) ) {
memcpy ( & V_4 -> V_37 , V_88 ,
sizeof( struct V_13 ) ) ;
F_36 ( & V_4 -> V_42 ) ;
} else if ( V_88 -> V_17 . V_18 ==
V_94 ) {
int V_12 ;
V_89 = (struct V_75 * ) ( unsigned long )
V_87 -> V_95 ;
V_89 -> V_96 . V_97 . V_98 (
V_89 -> V_96 . V_97 . V_99 ) ;
V_12 =
F_37 ( & V_4 -> V_12 ) ;
if ( V_4 -> V_9 && V_12 == 0 )
F_38 ( & V_4 -> V_7 ) ;
if ( F_39 ( V_5 ) && ! V_4 -> V_8 &&
( F_33 ( & V_3 -> V_25 -> V_100 )
> V_101 ||
V_12 < 1 ) )
F_40 ( V_5 ) ;
} else {
F_11 ( V_5 , L_12
L_13 , V_88 -> V_17 . V_18 ) ;
}
}
int F_41 ( struct V_2 * V_3 ,
struct V_75 * V_87 )
{
struct V_1 * V_4 ;
int V_15 = 0 ;
struct V_13 V_102 ;
struct V_4 * V_5 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return - V_33 ;
V_5 = V_4 -> V_5 ;
V_102 . V_17 . V_18 = V_103 ;
if ( V_87 -> V_104 ) {
V_102 . V_20 . V_21 . V_105 . V_106 = 0 ;
} else {
V_102 . V_20 . V_21 . V_105 . V_106 = 1 ;
}
V_102 . V_20 . V_21 . V_105 . V_107 =
0xFFFFFFFF ;
V_102 . V_20 . V_21 . V_105 . V_108 = 0 ;
if ( V_87 -> V_109 ) {
V_15 = F_42 ( V_3 -> V_25 ,
V_87 -> V_110 ,
V_87 -> V_109 ,
& V_102 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_87 ) ;
} else {
V_15 = F_10 ( V_3 -> V_25 , & V_102 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_87 ,
V_26 ,
V_41 ) ;
}
if ( V_15 == 0 ) {
F_43 ( & V_4 -> V_12 ) ;
if ( F_33 ( & V_3 -> V_25 -> V_100 ) <
V_111 ) {
F_44 ( V_5 ) ;
if ( F_8 ( & V_4 ->
V_12 ) < 1 )
F_40 ( V_5 ) ;
}
} else if ( V_15 == - V_112 ) {
F_44 ( V_5 ) ;
if ( F_8 ( & V_4 -> V_12 ) < 1 ) {
F_40 ( V_5 ) ;
V_15 = - V_113 ;
}
} else {
F_11 ( V_5 , L_14 ,
V_87 , V_15 ) ;
}
return V_15 ;
}
static void F_45 ( struct V_2 * V_3 ,
T_2 V_114 )
{
struct V_13 V_115 ;
int V_116 = 0 ;
int V_15 ;
struct V_4 * V_5 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
V_5 = V_4 -> V_5 ;
V_115 . V_17 . V_18 =
V_94 ;
V_115 . V_20 . V_21 . V_117 . V_45 =
V_46 ;
V_118:
V_15 = F_10 ( V_3 -> V_25 , & V_115 ,
sizeof( struct V_13 ) , V_114 ,
V_119 , 0 ) ;
if ( V_15 == 0 ) {
} else if ( V_15 == - V_112 ) {
V_116 ++ ;
F_11 ( V_5 , L_15
L_16 , V_114 , V_116 ) ;
if ( V_116 < 4 ) {
F_46 ( 100 ) ;
goto V_118;
} else {
F_11 ( V_5 , L_17
L_18 ,
V_114 ) ;
}
} else {
F_11 ( V_5 , L_17
L_19 , V_114 ) ;
}
}
static void F_47 ( void * V_120 )
{
struct V_75 * V_87 = V_120 ;
struct V_2 * V_3 = V_87 -> V_3 ;
struct V_1 * V_4 ;
T_2 V_114 = 0 ;
bool V_121 = false ;
unsigned long V_78 ;
struct V_4 * V_5 ;
V_4 = F_7 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
F_27 ( & V_4 -> V_122 , V_78 ) ;
V_87 -> V_123 -> V_124 -- ;
if ( V_87 -> V_123 -> V_124 == 0 ) {
V_121 = true ;
V_114 = V_87 -> V_96 . V_125 . V_126 ;
F_48 ( & V_87 -> V_123 -> V_80 ,
& V_4 -> V_127 ) ;
}
F_48 ( & V_87 -> V_80 , & V_4 -> V_127 ) ;
F_28 ( & V_4 -> V_122 , V_78 ) ;
if ( V_121 )
F_45 ( V_3 , V_114 ) ;
}
static void F_49 ( struct V_2 * V_3 ,
struct V_86 * V_87 )
{
struct V_1 * V_4 ;
struct V_128 * V_129 ;
struct V_13 * V_88 ;
struct V_75 * V_76 = NULL ;
struct V_130 * V_130 = NULL ;
int V_131 ;
int V_124 = 0 ;
unsigned long V_78 ;
struct V_4 * V_5 ;
F_50 ( V_132 ) ;
V_4 = F_7 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
if ( V_87 -> type != V_133 ) {
F_11 ( V_5 , L_20 ,
V_87 -> type ) ;
return;
}
V_88 = (struct V_13 * ) ( ( unsigned long ) V_87 +
( V_87 -> V_90 << 3 ) ) ;
if ( V_88 -> V_17 . V_18 !=
V_103 ) {
F_11 ( V_5 , L_21
L_22 , V_88 -> V_17 . V_18 ) ;
return;
}
V_129 = (struct V_128 * ) V_87 ;
if ( V_129 -> V_134 != V_24 ) {
F_11 ( V_5 , L_23
L_24 , V_24 ,
V_129 -> V_134 ) ;
return;
}
F_27 ( & V_4 -> V_122 , V_78 ) ;
while ( ! F_51 ( & V_4 -> V_127 ) ) {
F_52 ( V_4 -> V_127 . V_135 , & V_132 ) ;
if ( ++ V_124 == V_129 -> V_136 + 1 )
break;
}
F_28 ( & V_4 -> V_122 , V_78 ) ;
if ( V_124 < 2 ) {
F_11 ( V_5 , L_25
L_26 ,
V_124 , V_129 -> V_136 + 1 ) ;
F_27 ( & V_4 -> V_122 , V_78 ) ;
for ( V_131 = V_124 ; V_131 != 0 ; V_131 -- ) {
F_52 ( V_132 . V_135 ,
& V_4 -> V_127 ) ;
}
F_28 ( & V_4 -> V_122 ,
V_78 ) ;
F_45 ( V_3 ,
V_129 -> V_137 . V_95 ) ;
return;
}
V_130 = (struct V_130 * ) V_132 . V_135 ;
F_32 ( & V_130 -> V_80 ) ;
V_130 -> V_124 = V_124 - 1 ;
if ( V_130 -> V_124 != V_129 -> V_136 ) {
F_11 ( V_5 , L_27
L_28 ,
V_129 -> V_136 , V_130 -> V_124 ) ;
}
for ( V_131 = 0 ; V_131 < ( V_124 - 1 ) ; V_131 ++ ) {
V_76 = (struct V_75 * ) V_132 . V_135 ;
F_32 ( & V_76 -> V_80 ) ;
V_76 -> V_123 = V_130 ;
V_76 -> V_96 . V_125 . V_138 =
F_47 ;
V_76 -> V_96 . V_125 . V_139 =
V_76 ;
V_76 -> V_3 = V_3 ;
V_76 -> V_96 . V_125 . V_126 =
V_129 -> V_137 . V_95 ;
V_76 -> V_140 = ( void * ) ( ( unsigned long ) V_4 ->
V_28 + V_129 -> V_141 [ V_131 ] . V_142 ) ;
V_76 -> V_143 =
V_129 -> V_141 [ V_131 ] . V_144 ;
F_53 ( V_3 , V_76 ) ;
F_47 ( V_76 ->
V_96 . V_125 . V_139 ) ;
}
}
static void F_54 ( void * V_120 )
{
int V_15 ;
struct V_2 * V_3 = V_120 ;
struct V_1 * V_4 ;
T_1 V_145 ;
T_2 V_146 ;
unsigned char * V_87 ;
struct V_86 * V_147 ;
unsigned char * V_148 ;
int V_149 = V_150 ;
struct V_4 * V_5 ;
V_87 = F_3 ( V_150 * sizeof( unsigned char ) ,
V_151 ) ;
if ( ! V_87 )
return;
V_148 = V_87 ;
V_4 = F_7 ( V_3 ) ;
if ( ! V_4 )
goto V_152;
V_5 = V_4 -> V_5 ;
do {
V_15 = F_55 ( V_3 -> V_25 , V_148 , V_149 ,
& V_145 , & V_146 ) ;
if ( V_15 == 0 ) {
if ( V_145 > 0 ) {
V_147 = (struct V_86 * ) V_148 ;
switch ( V_147 -> type ) {
case V_119 :
F_35 ( V_3 , V_147 ) ;
break;
case V_133 :
F_49 ( V_3 , V_147 ) ;
break;
default:
F_11 ( V_5 ,
L_29
L_30 ,
V_147 -> type , V_146 ,
V_145 ) ;
break;
}
if ( V_149 > V_150 ) {
F_15 ( V_148 ) ;
V_148 = V_87 ;
V_149 = V_150 ;
}
} else {
if ( V_149 > V_150 ) {
F_15 ( V_148 ) ;
V_148 = V_87 ;
V_149 = V_150 ;
}
break;
}
} else if ( V_15 == - V_153 ) {
V_148 = F_56 ( V_145 , V_151 ) ;
if ( V_148 == NULL ) {
F_11 ( V_5 ,
L_31
L_32 , V_145 ) ;
break;
}
V_149 = V_145 ;
}
} while ( 1 );
V_152:
F_15 ( V_148 ) ;
return;
}
int F_57 ( struct V_2 * V_3 , void * V_154 )
{
int V_15 = 0 ;
int V_131 ;
int V_155 =
( (struct V_156 * ) V_154 ) -> V_155 ;
struct V_1 * V_4 ;
struct V_75 * V_87 , * V_77 ;
struct V_4 * V_5 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_15 = - V_35 ;
goto V_36;
}
V_5 = V_4 -> V_5 ;
V_4 -> V_29 = V_157 ;
F_58 ( & V_4 -> V_122 ) ;
F_59 ( & V_4 -> V_127 ) ;
for ( V_131 = 0 ; V_131 < V_158 ; V_131 ++ ) {
V_87 = F_3 ( sizeof( struct V_75 ) +
( V_159 *
sizeof( struct V_160 ) ) , V_6 ) ;
if ( ! V_87 )
break;
F_48 ( & V_87 -> V_80 ,
& V_4 -> V_127 ) ;
}
F_60 ( & V_4 -> V_42 ) ;
V_15 = F_61 ( V_3 -> V_25 , V_155 * V_161 ,
V_155 * V_161 , NULL , 0 ,
F_54 , V_3 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 , L_33 , V_15 ) ;
goto V_36;
}
F_62 ( L_34 ) ;
V_15 = F_23 ( V_3 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 ,
L_35 , V_15 ) ;
goto V_162;
}
return V_15 ;
V_162:
F_30 ( V_3 -> V_25 ) ;
V_36:
if ( V_4 ) {
F_31 (packet, pos,
&net_device->recv_pkt_list,
list_ent) {
F_32 ( & V_87 -> V_80 ) ;
F_15 ( V_87 ) ;
}
F_15 ( V_4 ) ;
}
return V_15 ;
}
