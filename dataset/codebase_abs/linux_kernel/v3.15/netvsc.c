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
if ( V_51 == V_59 )
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
T_1 V_67 [] = { V_59 , V_68 ,
V_69 , V_70 } ;
int V_71 , V_72 = 4 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return - V_32 ;
V_5 = V_4 -> V_5 ;
V_31 = & V_4 -> V_36 ;
for ( V_71 = V_72 - 1 ; V_71 >= 0 ; V_71 -- )
if ( F_21 ( V_3 , V_4 , V_31 ,
V_67 [ V_71 ] ) == 0 ) {
V_4 -> V_73 = V_67 [ V_71 ] ;
break;
}
if ( V_71 < 0 ) {
V_15 = - V_74 ;
goto V_35;
}
F_23 ( L_10 , V_4 -> V_73 ) ;
memset ( V_31 , 0 , sizeof( struct V_13 ) ) ;
if ( V_4 -> V_73 <= V_69 )
V_66 = 0x00060001 ;
else
V_66 = 0x0006001e ;
V_31 -> V_17 . V_18 = V_75 ;
V_31 -> V_20 . V_21 .
V_76 . V_77 =
( V_66 & 0xFFFF0000 ) >> 16 ;
V_31 -> V_20 . V_21 .
V_76 . V_78 =
V_66 & 0xFFFF ;
V_15 = F_10 ( V_3 -> V_25 , V_31 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_31 ,
V_26 , 0 ) ;
if ( V_15 != 0 )
goto V_35;
if ( V_4 -> V_73 <= V_68 )
V_4 -> V_33 = V_79 ;
else
V_4 -> V_33 = V_80 ;
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
struct V_81 * V_82 , * V_83 ;
unsigned long V_84 ;
V_4 = F_2 ( V_3 ) ;
F_24 ( V_4 ) ;
F_26 ( & V_3 -> V_25 -> V_85 , V_84 ) ;
F_5 ( V_3 , NULL ) ;
F_27 ( & V_3 -> V_25 -> V_85 , V_84 ) ;
F_28 ( & V_3 -> V_3 , L_11 ) ;
F_29 ( V_3 -> V_25 ) ;
F_30 (netvsc_packet, pos,
&net_device->recv_pkt_list, list_ent) {
F_31 ( & V_82 -> V_86 ) ;
F_14 ( V_82 ) ;
}
F_14 ( V_4 ) ;
return 0 ;
}
static inline T_1 F_32 (
struct V_87 * V_88 )
{
T_1 V_89 , V_90 ;
F_33 ( V_88 , & V_89 , & V_90 ) ;
return V_90 * 100 / V_88 -> V_91 ;
}
static void F_34 ( struct V_1 * V_4 ,
struct V_2 * V_3 ,
struct V_92 * V_93 )
{
struct V_13 * V_94 ;
struct V_81 * V_95 ;
struct V_4 * V_5 ;
V_5 = V_4 -> V_5 ;
V_94 = (struct V_13 * ) ( ( unsigned long ) V_93 +
( V_93 -> V_96 << 3 ) ) ;
if ( ( V_94 -> V_17 . V_18 == V_97 ) ||
( V_94 -> V_17 . V_18 ==
V_98 ) ||
( V_94 -> V_17 . V_18 ==
V_99 ) ) {
memcpy ( & V_4 -> V_36 , V_94 ,
sizeof( struct V_13 ) ) ;
F_35 ( & V_4 -> V_41 ) ;
} else if ( V_94 -> V_17 . V_18 ==
V_100 ) {
int V_12 ;
V_95 = (struct V_81 * ) ( unsigned long )
V_93 -> V_101 ;
if ( V_95 )
V_95 -> V_102 . V_103 . V_104 (
V_95 -> V_102 . V_103 .
V_105 ) ;
V_12 =
F_36 ( & V_4 -> V_12 ) ;
if ( V_4 -> V_9 && V_12 == 0 )
F_37 ( & V_4 -> V_7 ) ;
if ( F_38 ( V_5 ) && ! V_4 -> V_8 &&
( F_32 ( & V_3 -> V_25 -> V_106 )
> V_107 ||
V_12 < 1 ) )
F_39 ( V_5 ) ;
} else {
F_11 ( V_5 , L_12
L_13 , V_94 -> V_17 . V_18 ) ;
}
}
int F_40 ( struct V_2 * V_3 ,
struct V_81 * V_93 )
{
struct V_1 * V_4 ;
int V_15 = 0 ;
struct V_13 V_108 ;
struct V_4 * V_5 ;
T_2 V_109 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return - V_32 ;
V_5 = V_4 -> V_5 ;
V_108 . V_17 . V_18 = V_110 ;
if ( V_93 -> V_111 ) {
V_108 . V_20 . V_21 . V_112 . V_113 = 0 ;
} else {
V_108 . V_20 . V_21 . V_112 . V_113 = 1 ;
}
V_108 . V_20 . V_21 . V_112 . V_114 =
0xFFFFFFFF ;
V_108 . V_20 . V_21 . V_112 . V_115 = 0 ;
if ( V_93 -> V_102 . V_103 . V_104 )
V_109 = ( V_116 ) V_93 ;
else
V_109 = 0 ;
if ( V_93 -> V_117 ) {
V_15 = F_41 ( V_3 -> V_25 ,
V_93 -> V_118 ,
V_93 -> V_117 ,
& V_108 ,
sizeof( struct V_13 ) ,
V_109 ) ;
} else {
V_15 = F_10 ( V_3 -> V_25 , & V_108 ,
sizeof( struct V_13 ) ,
V_109 ,
V_26 ,
V_40 ) ;
}
if ( V_15 == 0 ) {
F_42 ( & V_4 -> V_12 ) ;
if ( F_32 ( & V_3 -> V_25 -> V_106 ) <
V_119 ) {
F_43 ( V_5 ) ;
if ( F_8 ( & V_4 ->
V_12 ) < 1 )
F_39 ( V_5 ) ;
}
} else if ( V_15 == - V_120 ) {
F_43 ( V_5 ) ;
if ( F_8 ( & V_4 -> V_12 ) < 1 ) {
F_39 ( V_5 ) ;
V_15 = - V_121 ;
}
} else {
F_11 ( V_5 , L_14 ,
V_93 , V_15 ) ;
}
return V_15 ;
}
static void F_44 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
T_2 V_122 , T_1 V_44 )
{
struct V_13 V_123 ;
int V_124 = 0 ;
int V_15 ;
struct V_4 * V_5 ;
V_5 = V_4 -> V_5 ;
V_123 . V_17 . V_18 =
V_100 ;
V_123 . V_20 . V_21 . V_125 . V_44 = V_44 ;
V_126:
V_15 = F_10 ( V_3 -> V_25 , & V_123 ,
sizeof( struct V_13 ) , V_122 ,
V_127 , 0 ) ;
if ( V_15 == 0 ) {
} else if ( V_15 == - V_120 ) {
V_124 ++ ;
F_11 ( V_5 , L_15
L_16 , V_122 , V_124 ) ;
if ( V_124 < 4 ) {
F_45 ( 100 ) ;
goto V_126;
} else {
F_11 ( V_5 , L_17
L_18 ,
V_122 ) ;
}
} else {
F_11 ( V_5 , L_17
L_19 , V_122 ) ;
}
}
static void F_46 ( void * V_128 )
{
struct V_81 * V_93 = V_128 ;
struct V_2 * V_3 = V_93 -> V_3 ;
struct V_1 * V_4 ;
T_2 V_122 = 0 ;
bool V_129 = false ;
unsigned long V_84 ;
struct V_4 * V_5 ;
T_1 V_44 = V_130 ;
V_4 = F_7 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
F_26 ( & V_4 -> V_131 , V_84 ) ;
if ( V_93 -> V_44 != V_45 )
V_93 -> V_132 -> V_44 = V_133 ;
V_93 -> V_132 -> V_134 -- ;
if ( V_93 -> V_132 -> V_134 == 0 ) {
V_129 = true ;
V_122 = V_93 -> V_102 . V_135 . V_136 ;
V_44 = V_93 -> V_132 -> V_44 ;
F_47 ( & V_93 -> V_132 -> V_86 ,
& V_4 -> V_137 ) ;
}
F_47 ( & V_93 -> V_86 , & V_4 -> V_137 ) ;
F_27 ( & V_4 -> V_131 , V_84 ) ;
if ( V_129 )
F_44 ( V_3 , V_4 , V_122 ,
V_44 ) ;
}
static void F_48 ( struct V_1 * V_4 ,
struct V_2 * V_3 ,
struct V_92 * V_93 )
{
struct V_138 * V_139 ;
struct V_13 * V_94 ;
struct V_81 * V_82 = NULL ;
struct V_140 * V_140 = NULL ;
int V_71 ;
int V_134 = 0 ;
unsigned long V_84 ;
struct V_4 * V_5 ;
F_49 ( V_141 ) ;
V_5 = V_4 -> V_5 ;
if ( V_93 -> type != V_142 ) {
F_11 ( V_5 , L_20 ,
V_93 -> type ) ;
return;
}
V_94 = (struct V_13 * ) ( ( unsigned long ) V_93 +
( V_93 -> V_96 << 3 ) ) ;
if ( V_94 -> V_17 . V_18 !=
V_110 ) {
F_11 ( V_5 , L_21
L_22 , V_94 -> V_17 . V_18 ) ;
return;
}
V_139 = (struct V_138 * ) V_93 ;
if ( V_139 -> V_143 != V_24 ) {
F_11 ( V_5 , L_23
L_24 , V_24 ,
V_139 -> V_143 ) ;
return;
}
F_26 ( & V_4 -> V_131 , V_84 ) ;
while ( ! F_50 ( & V_4 -> V_137 ) ) {
F_51 ( V_4 -> V_137 . V_144 , & V_141 ) ;
if ( ++ V_134 == V_139 -> V_145 + 1 )
break;
}
F_27 ( & V_4 -> V_131 , V_84 ) ;
if ( V_134 < 2 ) {
F_11 ( V_5 , L_25
L_26 ,
V_134 , V_139 -> V_145 + 1 ) ;
F_26 ( & V_4 -> V_131 , V_84 ) ;
for ( V_71 = V_134 ; V_71 != 0 ; V_71 -- ) {
F_51 ( V_141 . V_144 ,
& V_4 -> V_137 ) ;
}
F_27 ( & V_4 -> V_131 ,
V_84 ) ;
F_44 ( V_3 , V_4 ,
V_139 -> V_146 . V_101 ,
V_133 ) ;
return;
}
V_140 = (struct V_140 * ) V_141 . V_144 ;
F_31 ( & V_140 -> V_86 ) ;
V_140 -> V_44 = V_45 ;
V_140 -> V_134 = V_134 - 1 ;
if ( V_140 -> V_134 != V_139 -> V_145 ) {
F_11 ( V_5 , L_27
L_28 ,
V_139 -> V_145 , V_140 -> V_134 ) ;
}
for ( V_71 = 0 ; V_71 < ( V_134 - 1 ) ; V_71 ++ ) {
V_82 = (struct V_81 * ) V_141 . V_144 ;
F_31 ( & V_82 -> V_86 ) ;
V_82 -> V_44 = V_45 ;
V_82 -> V_132 = V_140 ;
V_82 -> V_102 . V_135 . V_147 =
F_46 ;
V_82 -> V_102 . V_135 . V_148 =
V_82 ;
V_82 -> V_3 = V_3 ;
V_82 -> V_102 . V_135 . V_136 =
V_139 -> V_146 . V_101 ;
V_82 -> V_149 = ( void * ) ( ( unsigned long ) V_4 ->
V_28 + V_139 -> V_150 [ V_71 ] . V_151 ) ;
V_82 -> V_152 =
V_139 -> V_150 [ V_71 ] . V_153 ;
F_52 ( V_3 , V_82 ) ;
F_46 ( V_82 ->
V_102 . V_135 . V_148 ) ;
}
}
static void F_53 ( void * V_128 )
{
int V_15 ;
struct V_2 * V_3 = V_128 ;
struct V_1 * V_4 ;
T_1 V_154 ;
T_2 V_155 ;
struct V_92 * V_156 ;
unsigned char * V_157 ;
int V_158 = V_159 ;
struct V_4 * V_5 ;
V_4 = F_7 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
V_157 = V_4 -> V_160 ;
do {
V_15 = F_54 ( V_3 -> V_25 , V_157 , V_158 ,
& V_154 , & V_155 ) ;
if ( V_15 == 0 ) {
if ( V_154 > 0 ) {
V_156 = (struct V_92 * ) V_157 ;
switch ( V_156 -> type ) {
case V_127 :
F_34 ( V_4 ,
V_3 , V_156 ) ;
break;
case V_142 :
F_48 ( V_4 ,
V_3 , V_156 ) ;
break;
default:
F_11 ( V_5 ,
L_29
L_30 ,
V_156 -> type , V_155 ,
V_154 ) ;
break;
}
} else {
break;
}
} else if ( V_15 == - V_161 ) {
if ( V_158 > V_159 )
F_14 ( V_157 ) ;
V_157 = F_55 ( V_154 , V_162 ) ;
if ( V_157 == NULL ) {
F_11 ( V_5 ,
L_31
L_32 , V_154 ) ;
break;
}
V_158 = V_154 ;
}
} while ( 1 );
if ( V_158 > V_159 )
F_14 ( V_157 ) ;
return;
}
int F_56 ( struct V_2 * V_3 , void * V_163 )
{
int V_15 = 0 ;
int V_71 ;
int V_164 =
( (struct V_165 * ) V_163 ) -> V_164 ;
struct V_1 * V_4 ;
struct V_81 * V_93 , * V_83 ;
struct V_4 * V_5 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_15 = - V_34 ;
goto V_35;
}
V_5 = V_4 -> V_5 ;
F_57 ( & V_4 -> V_131 ) ;
F_58 ( & V_4 -> V_137 ) ;
for ( V_71 = 0 ; V_71 < V_166 ; V_71 ++ ) {
V_93 = F_3 ( sizeof( struct V_81 ) , V_6 ) ;
if ( ! V_93 )
break;
F_47 ( & V_93 -> V_86 ,
& V_4 -> V_137 ) ;
}
F_59 ( & V_4 -> V_41 ) ;
V_15 = F_60 ( V_3 -> V_25 , V_164 * V_167 ,
V_164 * V_167 , NULL , 0 ,
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
goto V_168;
}
return V_15 ;
V_168:
F_29 ( V_3 -> V_25 ) ;
V_35:
if ( V_4 ) {
F_30 (packet, pos,
&net_device->recv_pkt_list,
list_ent) {
F_31 ( & V_93 -> V_86 ) ;
F_14 ( V_93 ) ;
}
F_14 ( V_4 ) ;
}
return V_15 ;
}
