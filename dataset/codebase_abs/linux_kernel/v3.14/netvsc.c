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
F_13 ( V_4 -> V_28 ) ;
V_4 -> V_28 = NULL ;
}
if ( V_4 -> V_29 ) {
V_4 -> V_16 = 0 ;
F_14 ( V_4 -> V_29 ) ;
V_4 -> V_29 = NULL ;
}
return V_15 ;
}
static int F_15 ( struct V_2 * V_3 )
{
int V_15 = 0 ;
int V_30 ;
struct V_1 * V_4 ;
struct V_13 * V_31 ;
struct V_4 * V_5 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return - V_32 ;
V_5 = V_4 -> V_5 ;
V_4 -> V_28 = F_16 ( V_4 -> V_33 ) ;
if ( ! V_4 -> V_28 ) {
F_11 ( V_5 , L_4
L_5 , V_4 -> V_33 ) ;
V_15 = - V_34 ;
goto V_35;
}
V_15 = F_17 ( V_3 -> V_25 , V_4 -> V_28 ,
V_4 -> V_33 ,
& V_4 -> V_27 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 ,
L_6 ) ;
goto V_35;
}
V_31 = & V_4 -> V_36 ;
memset ( V_31 , 0 , sizeof( struct V_13 ) ) ;
V_31 -> V_17 . V_18 = V_37 ;
V_31 -> V_20 . V_21 . V_38 .
V_39 = V_4 -> V_27 ;
V_31 -> V_20 . V_21 .
V_38 . V_23 = V_24 ;
V_15 = F_10 ( V_3 -> V_25 , V_31 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_31 ,
V_26 ,
V_40 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 ,
L_7 ) ;
goto V_35;
}
V_30 = F_18 ( & V_4 -> V_41 , 5 * V_42 ) ;
F_19 ( V_30 == 0 ) ;
if ( V_31 -> V_20 . V_21 .
V_43 . V_44 != V_45 ) {
F_11 ( V_5 , L_8
L_9 ,
V_31 -> V_20 . V_21 .
V_43 . V_44 ) ;
V_15 = - V_46 ;
goto V_35;
}
V_4 -> V_16 = V_31 -> V_20 .
V_21 . V_43 . V_47 ;
V_4 -> V_29 = F_20 (
V_31 -> V_20 . V_21 . V_43 . V_48 ,
V_4 -> V_16 *
sizeof( struct V_49 ) ,
V_6 ) ;
if ( V_4 -> V_29 == NULL ) {
V_15 = - V_46 ;
goto V_35;
}
if ( V_4 -> V_16 != 1 ||
V_4 -> V_29 -> V_50 != 0 ) {
V_15 = - V_46 ;
goto V_35;
}
goto exit;
V_35:
F_9 ( V_4 ) ;
exit:
return V_15 ;
}
static int F_21 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_13 * V_31 ,
T_1 V_51 )
{
int V_15 , V_30 ;
memset ( V_31 , 0 , sizeof( struct V_13 ) ) ;
V_31 -> V_17 . V_18 = V_52 ;
V_31 -> V_20 . V_53 . V_54 . V_55 = V_51 ;
V_31 -> V_20 . V_53 . V_54 . V_56 = V_51 ;
V_15 = F_10 ( V_3 -> V_25 , V_31 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_31 ,
V_26 ,
V_40 ) ;
if ( V_15 != 0 )
return V_15 ;
V_30 = F_18 ( & V_4 -> V_41 , 5 * V_42 ) ;
if ( V_30 == 0 )
return - V_57 ;
if ( V_31 -> V_20 . V_53 . V_58 . V_44 !=
V_45 )
return - V_46 ;
if ( V_51 != V_59 )
return 0 ;
memset ( V_31 , 0 , sizeof( struct V_13 ) ) ;
V_31 -> V_17 . V_18 = V_60 ;
V_31 -> V_20 . V_61 . V_62 . V_63 = V_4 -> V_5 -> V_63 ;
V_31 -> V_20 . V_61 . V_62 . V_64 . V_65 = 1 ;
V_15 = F_10 ( V_3 -> V_25 , V_31 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_31 ,
V_26 , 0 ) ;
return V_15 ;
}
static int F_22 ( struct V_2 * V_3 )
{
int V_15 ;
struct V_1 * V_4 ;
struct V_13 * V_31 ;
int V_66 ;
struct V_4 * V_5 ;
V_4 = F_6 ( V_3 ) ;
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
V_15 = - V_69 ;
goto V_35;
}
F_23 ( L_10 , V_4 -> V_67 ) ;
memset ( V_31 , 0 , sizeof( struct V_13 ) ) ;
V_66 = 0x00050001 ;
V_31 -> V_17 . V_18 = V_70 ;
V_31 -> V_20 . V_21 .
V_71 . V_72 =
( V_66 & 0xFFFF0000 ) >> 16 ;
V_31 -> V_20 . V_21 .
V_71 . V_73 =
V_66 & 0xFFFF ;
V_15 = F_10 ( V_3 -> V_25 , V_31 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_31 ,
V_26 , 0 ) ;
if ( V_15 != 0 )
goto V_35;
V_15 = F_15 ( V_3 ) ;
V_35:
return V_15 ;
}
static void F_24 ( struct V_1 * V_4 )
{
F_9 ( V_4 ) ;
}
int F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_74 * V_75 , * V_76 ;
unsigned long V_77 ;
V_4 = F_2 ( V_3 ) ;
F_24 ( V_4 ) ;
F_26 ( & V_3 -> V_25 -> V_78 , V_77 ) ;
F_5 ( V_3 , NULL ) ;
F_27 ( & V_3 -> V_25 -> V_78 , V_77 ) ;
F_28 ( & V_3 -> V_3 , L_11 ) ;
F_29 ( V_3 -> V_25 ) ;
F_30 (netvsc_packet, pos,
&net_device->recv_pkt_list, list_ent) {
F_31 ( & V_75 -> V_79 ) ;
F_14 ( V_75 ) ;
}
F_14 ( V_4 ) ;
return 0 ;
}
static inline T_1 F_32 (
struct V_80 * V_81 )
{
T_1 V_82 , V_83 ;
F_33 ( V_81 , & V_82 , & V_83 ) ;
return V_83 * 100 / V_81 -> V_84 ;
}
static void F_34 ( struct V_2 * V_3 ,
struct V_85 * V_86 )
{
struct V_1 * V_4 ;
struct V_13 * V_87 ;
struct V_74 * V_88 ;
struct V_4 * V_5 ;
V_4 = F_7 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
V_87 = (struct V_13 * ) ( ( unsigned long ) V_86 +
( V_86 -> V_89 << 3 ) ) ;
if ( ( V_87 -> V_17 . V_18 == V_90 ) ||
( V_87 -> V_17 . V_18 ==
V_91 ) ||
( V_87 -> V_17 . V_18 ==
V_92 ) ) {
memcpy ( & V_4 -> V_36 , V_87 ,
sizeof( struct V_13 ) ) ;
F_35 ( & V_4 -> V_41 ) ;
} else if ( V_87 -> V_17 . V_18 ==
V_93 ) {
int V_12 ;
V_88 = (struct V_74 * ) ( unsigned long )
V_86 -> V_94 ;
if ( V_88 )
V_88 -> V_95 . V_96 . V_97 (
V_88 -> V_95 . V_96 .
V_98 ) ;
V_12 =
F_36 ( & V_4 -> V_12 ) ;
if ( V_4 -> V_9 && V_12 == 0 )
F_37 ( & V_4 -> V_7 ) ;
if ( F_38 ( V_5 ) && ! V_4 -> V_8 &&
( F_32 ( & V_3 -> V_25 -> V_99 )
> V_100 ||
V_12 < 1 ) )
F_39 ( V_5 ) ;
} else {
F_11 ( V_5 , L_12
L_13 , V_87 -> V_17 . V_18 ) ;
}
}
int F_40 ( struct V_2 * V_3 ,
struct V_74 * V_86 )
{
struct V_1 * V_4 ;
int V_15 = 0 ;
struct V_13 V_101 ;
struct V_4 * V_5 ;
T_2 V_102 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return - V_32 ;
V_5 = V_4 -> V_5 ;
V_101 . V_17 . V_18 = V_103 ;
if ( V_86 -> V_104 ) {
V_101 . V_20 . V_21 . V_105 . V_106 = 0 ;
} else {
V_101 . V_20 . V_21 . V_105 . V_106 = 1 ;
}
V_101 . V_20 . V_21 . V_105 . V_107 =
0xFFFFFFFF ;
V_101 . V_20 . V_21 . V_105 . V_108 = 0 ;
if ( V_86 -> V_95 . V_96 . V_97 )
V_102 = ( V_109 ) V_86 ;
else
V_102 = 0 ;
if ( V_86 -> V_110 ) {
V_15 = F_41 ( V_3 -> V_25 ,
V_86 -> V_111 ,
V_86 -> V_110 ,
& V_101 ,
sizeof( struct V_13 ) ,
V_102 ) ;
} else {
V_15 = F_10 ( V_3 -> V_25 , & V_101 ,
sizeof( struct V_13 ) ,
V_102 ,
V_26 ,
V_40 ) ;
}
if ( V_15 == 0 ) {
F_42 ( & V_4 -> V_12 ) ;
if ( F_32 ( & V_3 -> V_25 -> V_99 ) <
V_112 ) {
F_43 ( V_5 ) ;
if ( F_8 ( & V_4 ->
V_12 ) < 1 )
F_39 ( V_5 ) ;
}
} else if ( V_15 == - V_113 ) {
F_43 ( V_5 ) ;
if ( F_8 ( & V_4 -> V_12 ) < 1 ) {
F_39 ( V_5 ) ;
V_15 = - V_114 ;
}
} else {
F_11 ( V_5 , L_14 ,
V_86 , V_15 ) ;
}
return V_15 ;
}
static void F_44 ( struct V_2 * V_3 ,
T_2 V_115 , T_1 V_44 )
{
struct V_13 V_116 ;
int V_117 = 0 ;
int V_15 ;
struct V_4 * V_5 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
V_5 = V_4 -> V_5 ;
V_116 . V_17 . V_18 =
V_93 ;
V_116 . V_20 . V_21 . V_118 . V_44 = V_44 ;
V_119:
V_15 = F_10 ( V_3 -> V_25 , & V_116 ,
sizeof( struct V_13 ) , V_115 ,
V_120 , 0 ) ;
if ( V_15 == 0 ) {
} else if ( V_15 == - V_113 ) {
V_117 ++ ;
F_11 ( V_5 , L_15
L_16 , V_115 , V_117 ) ;
if ( V_117 < 4 ) {
F_45 ( 100 ) ;
goto V_119;
} else {
F_11 ( V_5 , L_17
L_18 ,
V_115 ) ;
}
} else {
F_11 ( V_5 , L_17
L_19 , V_115 ) ;
}
}
static void F_46 ( void * V_121 )
{
struct V_74 * V_86 = V_121 ;
struct V_2 * V_3 = V_86 -> V_3 ;
struct V_1 * V_4 ;
T_2 V_115 = 0 ;
bool V_122 = false ;
unsigned long V_77 ;
struct V_4 * V_5 ;
T_1 V_44 = V_123 ;
V_4 = F_7 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
F_26 ( & V_4 -> V_124 , V_77 ) ;
if ( V_86 -> V_44 != V_45 )
V_86 -> V_125 -> V_44 = V_126 ;
V_86 -> V_125 -> V_127 -- ;
if ( V_86 -> V_125 -> V_127 == 0 ) {
V_122 = true ;
V_115 = V_86 -> V_95 . V_128 . V_129 ;
V_44 = V_86 -> V_125 -> V_44 ;
F_47 ( & V_86 -> V_125 -> V_79 ,
& V_4 -> V_130 ) ;
}
F_47 ( & V_86 -> V_79 , & V_4 -> V_130 ) ;
F_27 ( & V_4 -> V_124 , V_77 ) ;
if ( V_122 )
F_44 ( V_3 , V_115 , V_44 ) ;
}
static void F_48 ( struct V_2 * V_3 ,
struct V_85 * V_86 )
{
struct V_1 * V_4 ;
struct V_131 * V_132 ;
struct V_13 * V_87 ;
struct V_74 * V_75 = NULL ;
struct V_133 * V_133 = NULL ;
int V_134 ;
int V_127 = 0 ;
unsigned long V_77 ;
struct V_4 * V_5 ;
F_49 ( V_135 ) ;
V_4 = F_7 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
if ( V_86 -> type != V_136 ) {
F_11 ( V_5 , L_20 ,
V_86 -> type ) ;
return;
}
V_87 = (struct V_13 * ) ( ( unsigned long ) V_86 +
( V_86 -> V_89 << 3 ) ) ;
if ( V_87 -> V_17 . V_18 !=
V_103 ) {
F_11 ( V_5 , L_21
L_22 , V_87 -> V_17 . V_18 ) ;
return;
}
V_132 = (struct V_131 * ) V_86 ;
if ( V_132 -> V_137 != V_24 ) {
F_11 ( V_5 , L_23
L_24 , V_24 ,
V_132 -> V_137 ) ;
return;
}
F_26 ( & V_4 -> V_124 , V_77 ) ;
while ( ! F_50 ( & V_4 -> V_130 ) ) {
F_51 ( V_4 -> V_130 . V_138 , & V_135 ) ;
if ( ++ V_127 == V_132 -> V_139 + 1 )
break;
}
F_27 ( & V_4 -> V_124 , V_77 ) ;
if ( V_127 < 2 ) {
F_11 ( V_5 , L_25
L_26 ,
V_127 , V_132 -> V_139 + 1 ) ;
F_26 ( & V_4 -> V_124 , V_77 ) ;
for ( V_134 = V_127 ; V_134 != 0 ; V_134 -- ) {
F_51 ( V_135 . V_138 ,
& V_4 -> V_130 ) ;
}
F_27 ( & V_4 -> V_124 ,
V_77 ) ;
F_44 ( V_3 ,
V_132 -> V_140 . V_94 ,
V_126 ) ;
return;
}
V_133 = (struct V_133 * ) V_135 . V_138 ;
F_31 ( & V_133 -> V_79 ) ;
V_133 -> V_44 = V_45 ;
V_133 -> V_127 = V_127 - 1 ;
if ( V_133 -> V_127 != V_132 -> V_139 ) {
F_11 ( V_5 , L_27
L_28 ,
V_132 -> V_139 , V_133 -> V_127 ) ;
}
for ( V_134 = 0 ; V_134 < ( V_127 - 1 ) ; V_134 ++ ) {
V_75 = (struct V_74 * ) V_135 . V_138 ;
F_31 ( & V_75 -> V_79 ) ;
V_75 -> V_44 = V_45 ;
V_75 -> V_125 = V_133 ;
V_75 -> V_95 . V_128 . V_141 =
F_46 ;
V_75 -> V_95 . V_128 . V_142 =
V_75 ;
V_75 -> V_3 = V_3 ;
V_75 -> V_95 . V_128 . V_129 =
V_132 -> V_140 . V_94 ;
V_75 -> V_143 = ( void * ) ( ( unsigned long ) V_4 ->
V_28 + V_132 -> V_144 [ V_134 ] . V_145 ) ;
V_75 -> V_146 =
V_132 -> V_144 [ V_134 ] . V_147 ;
F_52 ( V_3 , V_75 ) ;
F_46 ( V_75 ->
V_95 . V_128 . V_142 ) ;
}
}
static void F_53 ( void * V_121 )
{
int V_15 ;
struct V_2 * V_3 = V_121 ;
struct V_1 * V_4 ;
T_1 V_148 ;
T_2 V_149 ;
unsigned char * V_86 ;
struct V_85 * V_150 ;
unsigned char * V_151 ;
int V_152 = V_153 ;
struct V_4 * V_5 ;
V_86 = F_3 ( V_153 * sizeof( unsigned char ) ,
V_154 ) ;
if ( ! V_86 )
return;
V_151 = V_86 ;
V_4 = F_7 ( V_3 ) ;
if ( ! V_4 )
goto V_155;
V_5 = V_4 -> V_5 ;
do {
V_15 = F_54 ( V_3 -> V_25 , V_151 , V_152 ,
& V_148 , & V_149 ) ;
if ( V_15 == 0 ) {
if ( V_148 > 0 ) {
V_150 = (struct V_85 * ) V_151 ;
switch ( V_150 -> type ) {
case V_120 :
F_34 ( V_3 , V_150 ) ;
break;
case V_136 :
F_48 ( V_3 , V_150 ) ;
break;
default:
F_11 ( V_5 ,
L_29
L_30 ,
V_150 -> type , V_149 ,
V_148 ) ;
break;
}
if ( V_152 > V_153 ) {
F_14 ( V_151 ) ;
V_151 = V_86 ;
V_152 = V_153 ;
}
} else {
if ( V_152 > V_153 ) {
F_14 ( V_151 ) ;
V_151 = V_86 ;
V_152 = V_153 ;
}
break;
}
} else if ( V_15 == - V_156 ) {
V_151 = F_55 ( V_148 , V_154 ) ;
if ( V_151 == NULL ) {
F_11 ( V_5 ,
L_31
L_32 , V_148 ) ;
break;
}
V_152 = V_148 ;
}
} while ( 1 );
V_155:
F_14 ( V_151 ) ;
return;
}
int F_56 ( struct V_2 * V_3 , void * V_157 )
{
int V_15 = 0 ;
int V_134 ;
int V_158 =
( (struct V_159 * ) V_157 ) -> V_158 ;
struct V_1 * V_4 ;
struct V_74 * V_86 , * V_76 ;
struct V_4 * V_5 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_15 = - V_34 ;
goto V_35;
}
V_5 = V_4 -> V_5 ;
V_4 -> V_33 = V_160 ;
F_57 ( & V_4 -> V_124 ) ;
F_58 ( & V_4 -> V_130 ) ;
for ( V_134 = 0 ; V_134 < V_161 ; V_134 ++ ) {
V_86 = F_3 ( sizeof( struct V_74 ) , V_6 ) ;
if ( ! V_86 )
break;
F_47 ( & V_86 -> V_79 ,
& V_4 -> V_130 ) ;
}
F_59 ( & V_4 -> V_41 ) ;
V_15 = F_60 ( V_3 -> V_25 , V_158 * V_162 ,
V_158 * V_162 , NULL , 0 ,
F_53 , V_3 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 , L_33 , V_15 ) ;
goto V_35;
}
F_61 ( L_34 ) ;
V_15 = F_22 ( V_3 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 ,
L_35 , V_15 ) ;
goto V_163;
}
return V_15 ;
V_163:
F_29 ( V_3 -> V_25 ) ;
V_35:
if ( V_4 ) {
F_30 (packet, pos,
&net_device->recv_pkt_list,
list_ent) {
F_31 ( & V_86 -> V_79 ) ;
F_14 ( V_86 ) ;
}
F_14 ( V_4 ) ;
}
return V_15 ;
}
