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
if ( V_89 )
V_89 -> V_96 . V_97 . V_98 (
V_89 -> V_96 . V_97 .
V_99 ) ;
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
T_2 V_103 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return - V_33 ;
V_5 = V_4 -> V_5 ;
V_102 . V_17 . V_18 = V_104 ;
if ( V_87 -> V_105 ) {
V_102 . V_20 . V_21 . V_106 . V_107 = 0 ;
} else {
V_102 . V_20 . V_21 . V_106 . V_107 = 1 ;
}
V_102 . V_20 . V_21 . V_106 . V_108 =
0xFFFFFFFF ;
V_102 . V_20 . V_21 . V_106 . V_109 = 0 ;
if ( V_87 -> V_96 . V_97 . V_98 )
V_103 = ( V_110 ) V_87 ;
else
V_103 = 0 ;
if ( V_87 -> V_111 ) {
V_15 = F_42 ( V_3 -> V_25 ,
V_87 -> V_112 ,
V_87 -> V_111 ,
& V_102 ,
sizeof( struct V_13 ) ,
V_103 ) ;
} else {
V_15 = F_10 ( V_3 -> V_25 , & V_102 ,
sizeof( struct V_13 ) ,
V_103 ,
V_26 ,
V_41 ) ;
}
if ( V_15 == 0 ) {
F_43 ( & V_4 -> V_12 ) ;
if ( F_33 ( & V_3 -> V_25 -> V_100 ) <
V_113 ) {
F_44 ( V_5 ) ;
if ( F_8 ( & V_4 ->
V_12 ) < 1 )
F_40 ( V_5 ) ;
}
} else if ( V_15 == - V_114 ) {
F_44 ( V_5 ) ;
if ( F_8 ( & V_4 -> V_12 ) < 1 ) {
F_40 ( V_5 ) ;
V_15 = - V_115 ;
}
} else {
F_11 ( V_5 , L_14 ,
V_87 , V_15 ) ;
}
return V_15 ;
}
static void F_45 ( struct V_2 * V_3 ,
T_2 V_116 , T_1 V_45 )
{
struct V_13 V_117 ;
int V_118 = 0 ;
int V_15 ;
struct V_4 * V_5 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
V_5 = V_4 -> V_5 ;
V_117 . V_17 . V_18 =
V_94 ;
V_117 . V_20 . V_21 . V_119 . V_45 = V_45 ;
V_120:
V_15 = F_10 ( V_3 -> V_25 , & V_117 ,
sizeof( struct V_13 ) , V_116 ,
V_121 , 0 ) ;
if ( V_15 == 0 ) {
} else if ( V_15 == - V_114 ) {
V_118 ++ ;
F_11 ( V_5 , L_15
L_16 , V_116 , V_118 ) ;
if ( V_118 < 4 ) {
F_46 ( 100 ) ;
goto V_120;
} else {
F_11 ( V_5 , L_17
L_18 ,
V_116 ) ;
}
} else {
F_11 ( V_5 , L_17
L_19 , V_116 ) ;
}
}
static void F_47 ( void * V_122 )
{
struct V_75 * V_87 = V_122 ;
struct V_2 * V_3 = V_87 -> V_3 ;
struct V_1 * V_4 ;
T_2 V_116 = 0 ;
bool V_123 = false ;
unsigned long V_78 ;
struct V_4 * V_5 ;
T_1 V_45 = V_124 ;
V_4 = F_7 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
F_27 ( & V_4 -> V_125 , V_78 ) ;
if ( V_87 -> V_45 != V_46 )
V_87 -> V_126 -> V_45 = V_127 ;
V_87 -> V_126 -> V_128 -- ;
if ( V_87 -> V_126 -> V_128 == 0 ) {
V_123 = true ;
V_116 = V_87 -> V_96 . V_129 . V_130 ;
V_45 = V_87 -> V_126 -> V_45 ;
F_48 ( & V_87 -> V_126 -> V_80 ,
& V_4 -> V_131 ) ;
}
F_48 ( & V_87 -> V_80 , & V_4 -> V_131 ) ;
F_28 ( & V_4 -> V_125 , V_78 ) ;
if ( V_123 )
F_45 ( V_3 , V_116 , V_45 ) ;
}
static void F_49 ( struct V_2 * V_3 ,
struct V_86 * V_87 )
{
struct V_1 * V_4 ;
struct V_132 * V_133 ;
struct V_13 * V_88 ;
struct V_75 * V_76 = NULL ;
struct V_134 * V_134 = NULL ;
int V_135 ;
int V_128 = 0 ;
unsigned long V_78 ;
struct V_4 * V_5 ;
F_50 ( V_136 ) ;
V_4 = F_7 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
if ( V_87 -> type != V_137 ) {
F_11 ( V_5 , L_20 ,
V_87 -> type ) ;
return;
}
V_88 = (struct V_13 * ) ( ( unsigned long ) V_87 +
( V_87 -> V_90 << 3 ) ) ;
if ( V_88 -> V_17 . V_18 !=
V_104 ) {
F_11 ( V_5 , L_21
L_22 , V_88 -> V_17 . V_18 ) ;
return;
}
V_133 = (struct V_132 * ) V_87 ;
if ( V_133 -> V_138 != V_24 ) {
F_11 ( V_5 , L_23
L_24 , V_24 ,
V_133 -> V_138 ) ;
return;
}
F_27 ( & V_4 -> V_125 , V_78 ) ;
while ( ! F_51 ( & V_4 -> V_131 ) ) {
F_52 ( V_4 -> V_131 . V_139 , & V_136 ) ;
if ( ++ V_128 == V_133 -> V_140 + 1 )
break;
}
F_28 ( & V_4 -> V_125 , V_78 ) ;
if ( V_128 < 2 ) {
F_11 ( V_5 , L_25
L_26 ,
V_128 , V_133 -> V_140 + 1 ) ;
F_27 ( & V_4 -> V_125 , V_78 ) ;
for ( V_135 = V_128 ; V_135 != 0 ; V_135 -- ) {
F_52 ( V_136 . V_139 ,
& V_4 -> V_131 ) ;
}
F_28 ( & V_4 -> V_125 ,
V_78 ) ;
F_45 ( V_3 ,
V_133 -> V_141 . V_95 ,
V_127 ) ;
return;
}
V_134 = (struct V_134 * ) V_136 . V_139 ;
F_32 ( & V_134 -> V_80 ) ;
V_134 -> V_45 = V_46 ;
V_134 -> V_128 = V_128 - 1 ;
if ( V_134 -> V_128 != V_133 -> V_140 ) {
F_11 ( V_5 , L_27
L_28 ,
V_133 -> V_140 , V_134 -> V_128 ) ;
}
for ( V_135 = 0 ; V_135 < ( V_128 - 1 ) ; V_135 ++ ) {
V_76 = (struct V_75 * ) V_136 . V_139 ;
F_32 ( & V_76 -> V_80 ) ;
V_76 -> V_45 = V_46 ;
V_76 -> V_126 = V_134 ;
V_76 -> V_96 . V_129 . V_142 =
F_47 ;
V_76 -> V_96 . V_129 . V_143 =
V_76 ;
V_76 -> V_3 = V_3 ;
V_76 -> V_96 . V_129 . V_130 =
V_133 -> V_141 . V_95 ;
V_76 -> V_144 = ( void * ) ( ( unsigned long ) V_4 ->
V_28 + V_133 -> V_145 [ V_135 ] . V_146 ) ;
V_76 -> V_147 =
V_133 -> V_145 [ V_135 ] . V_148 ;
F_53 ( V_3 , V_76 ) ;
F_47 ( V_76 ->
V_96 . V_129 . V_143 ) ;
}
}
static void F_54 ( void * V_122 )
{
int V_15 ;
struct V_2 * V_3 = V_122 ;
struct V_1 * V_4 ;
T_1 V_149 ;
T_2 V_150 ;
unsigned char * V_87 ;
struct V_86 * V_151 ;
unsigned char * V_152 ;
int V_153 = V_154 ;
struct V_4 * V_5 ;
V_87 = F_3 ( V_154 * sizeof( unsigned char ) ,
V_155 ) ;
if ( ! V_87 )
return;
V_152 = V_87 ;
V_4 = F_7 ( V_3 ) ;
if ( ! V_4 )
goto V_156;
V_5 = V_4 -> V_5 ;
do {
V_15 = F_55 ( V_3 -> V_25 , V_152 , V_153 ,
& V_149 , & V_150 ) ;
if ( V_15 == 0 ) {
if ( V_149 > 0 ) {
V_151 = (struct V_86 * ) V_152 ;
switch ( V_151 -> type ) {
case V_121 :
F_35 ( V_3 , V_151 ) ;
break;
case V_137 :
F_49 ( V_3 , V_151 ) ;
break;
default:
F_11 ( V_5 ,
L_29
L_30 ,
V_151 -> type , V_150 ,
V_149 ) ;
break;
}
if ( V_153 > V_154 ) {
F_15 ( V_152 ) ;
V_152 = V_87 ;
V_153 = V_154 ;
}
} else {
if ( V_153 > V_154 ) {
F_15 ( V_152 ) ;
V_152 = V_87 ;
V_153 = V_154 ;
}
break;
}
} else if ( V_15 == - V_157 ) {
V_152 = F_56 ( V_149 , V_155 ) ;
if ( V_152 == NULL ) {
F_11 ( V_5 ,
L_31
L_32 , V_149 ) ;
break;
}
V_153 = V_149 ;
}
} while ( 1 );
V_156:
F_15 ( V_152 ) ;
return;
}
int F_57 ( struct V_2 * V_3 , void * V_158 )
{
int V_15 = 0 ;
int V_135 ;
int V_159 =
( (struct V_160 * ) V_158 ) -> V_159 ;
struct V_1 * V_4 ;
struct V_75 * V_87 , * V_77 ;
struct V_4 * V_5 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_15 = - V_35 ;
goto V_36;
}
V_5 = V_4 -> V_5 ;
V_4 -> V_29 = V_161 ;
F_58 ( & V_4 -> V_125 ) ;
F_59 ( & V_4 -> V_131 ) ;
for ( V_135 = 0 ; V_135 < V_162 ; V_135 ++ ) {
V_87 = F_3 ( sizeof( struct V_75 ) , V_6 ) ;
if ( ! V_87 )
break;
F_48 ( & V_87 -> V_80 ,
& V_4 -> V_131 ) ;
}
F_60 ( & V_4 -> V_42 ) ;
V_15 = F_61 ( V_3 -> V_25 , V_159 * V_163 ,
V_159 * V_163 , NULL , 0 ,
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
goto V_164;
}
return V_15 ;
V_164:
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
