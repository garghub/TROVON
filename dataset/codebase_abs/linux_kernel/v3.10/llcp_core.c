void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_5 ) ;
F_3 ( V_4 , & V_2 -> V_6 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_5 ) ;
F_6 ( V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
void F_7 ( struct V_7 * V_3 )
{
V_3 -> V_8 = V_9 ;
V_3 -> V_10 = V_11 + 1 ;
}
static void F_8 ( struct V_7 * V_3 )
{
struct V_12 * V_13 = V_3 -> V_13 ;
struct V_14 * V_15 , * V_16 ;
F_9 ( L_1 , & V_3 -> V_4 ) ;
F_10 ( & V_3 -> V_17 ) ;
F_10 ( & V_3 -> V_18 ) ;
if ( V_13 == NULL )
return;
F_11 (&local->tx_queue, s, tmp) {
if ( V_15 -> V_4 != & V_3 -> V_4 )
continue;
F_12 ( V_15 , & V_13 -> V_17 ) ;
F_13 ( V_15 ) ;
}
}
static void F_14 ( struct V_12 * V_13 , bool V_19 ,
int V_20 )
{
struct V_3 * V_4 ;
struct V_21 * V_16 ;
struct V_7 * V_22 ;
F_10 ( & V_13 -> V_17 ) ;
F_2 ( & V_13 -> V_23 . V_5 ) ;
F_15 (sk, tmp, &local->sockets.head) {
V_22 = V_7 ( V_4 ) ;
F_16 ( V_4 ) ;
F_8 ( V_22 ) ;
if ( V_4 -> V_24 == V_25 )
F_17 ( V_22 -> V_26 ) ;
if ( V_4 -> V_24 == V_27 ) {
struct V_7 * V_28 , * V_29 ;
struct V_3 * V_30 ;
F_18 (lsk, n,
&llcp_sock->accept_queue,
accept_queue) {
V_30 = & V_28 -> V_4 ;
F_16 ( V_30 ) ;
F_19 ( V_30 ) ;
if ( V_20 )
V_30 -> V_31 = V_20 ;
V_30 -> V_24 = V_32 ;
V_30 -> V_33 ( V_4 ) ;
F_20 ( V_30 ) ;
}
}
if ( V_20 )
V_4 -> V_31 = V_20 ;
V_4 -> V_24 = V_32 ;
V_4 -> V_33 ( V_4 ) ;
F_20 ( V_4 ) ;
F_6 ( V_4 ) ;
}
F_4 ( & V_13 -> V_23 . V_5 ) ;
if ( V_19 == true )
return;
F_2 ( & V_13 -> V_34 . V_5 ) ;
F_15 (sk, tmp, &local->raw_sockets.head) {
V_22 = V_7 ( V_4 ) ;
F_16 ( V_4 ) ;
F_8 ( V_22 ) ;
if ( V_20 )
V_4 -> V_31 = V_20 ;
V_4 -> V_24 = V_32 ;
V_4 -> V_33 ( V_4 ) ;
F_20 ( V_4 ) ;
F_6 ( V_4 ) ;
}
F_4 ( & V_13 -> V_34 . V_5 ) ;
}
struct V_12 * F_21 ( struct V_12 * V_13 )
{
F_22 ( & V_13 -> V_35 ) ;
return V_13 ;
}
static void F_23 ( struct V_12 * V_13 )
{
F_14 ( V_13 , false , V_36 ) ;
F_24 ( & V_13 -> V_37 ) ;
F_10 ( & V_13 -> V_17 ) ;
F_25 ( & V_13 -> V_38 ) ;
F_25 ( & V_13 -> V_39 ) ;
F_25 ( & V_13 -> V_40 ) ;
F_13 ( V_13 -> V_41 ) ;
F_24 ( & V_13 -> V_42 ) ;
F_25 ( & V_13 -> V_43 ) ;
F_26 ( & V_13 -> V_44 ) ;
}
static void F_27 ( struct V_45 * V_35 )
{
struct V_12 * V_13 ;
V_13 = F_28 ( V_35 , struct V_12 , V_35 ) ;
F_29 ( & V_13 -> V_46 ) ;
F_23 ( V_13 ) ;
F_30 ( V_13 ) ;
}
int F_31 ( struct V_12 * V_13 )
{
if ( V_13 == NULL )
return 0 ;
return F_32 ( & V_13 -> V_35 , F_27 ) ;
}
static struct V_7 * F_33 ( struct V_12 * V_13 ,
T_1 V_47 , T_1 V_48 )
{
struct V_3 * V_4 ;
struct V_7 * V_22 , * V_49 ;
F_9 ( L_2 , V_47 , V_48 ) ;
if ( V_47 == 0 && V_48 == 0 )
return NULL ;
F_34 ( & V_13 -> V_23 . V_5 ) ;
V_22 = NULL ;
F_35 (sk, &local->sockets.head) {
V_49 = V_7 ( V_4 ) ;
if ( V_49 -> V_47 == V_47 && V_49 -> V_48 == V_48 ) {
V_22 = V_49 ;
break;
}
}
F_36 ( & V_13 -> V_23 . V_5 ) ;
if ( V_22 == NULL )
return NULL ;
F_37 ( & V_22 -> V_4 ) ;
return V_22 ;
}
static void F_38 ( struct V_7 * V_3 )
{
F_39 ( & V_3 -> V_4 ) ;
}
static void F_40 ( struct V_50 * V_51 )
{
struct V_12 * V_13 = F_28 ( V_51 , struct V_12 ,
V_40 ) ;
F_41 ( V_13 -> V_26 ) ;
}
static void F_42 ( unsigned long V_52 )
{
struct V_12 * V_13 = (struct V_12 * ) V_52 ;
F_43 ( L_3 ) ;
F_44 ( & V_13 -> V_40 ) ;
}
static void F_45 ( struct V_50 * V_51 )
{
unsigned long time ;
F_46 ( V_53 ) ;
struct V_21 * V_29 ;
struct V_54 * V_55 ;
struct V_12 * V_13 = F_28 ( V_51 , struct V_12 ,
V_43 ) ;
F_47 ( & V_13 -> V_56 ) ;
time = V_57 - F_48 ( 3 * V_13 -> V_58 ) ;
F_49 (sdp, n, &local->pending_sdreqs, node) {
if ( F_50 ( V_55 -> time , time ) )
continue;
V_55 -> V_59 = V_60 ;
F_51 ( & V_55 -> V_61 ) ;
F_52 ( & V_55 -> V_61 , & V_53 ) ;
}
if ( ! F_53 ( & V_13 -> V_44 ) )
F_54 ( & V_13 -> V_42 ,
V_57 + F_48 ( 3 * V_13 -> V_58 ) ) ;
F_55 ( & V_13 -> V_56 ) ;
if ( ! F_53 ( & V_53 ) )
F_56 ( V_13 -> V_26 , & V_53 ) ;
}
static void F_57 ( unsigned long V_52 )
{
struct V_12 * V_13 = (struct V_12 * ) V_52 ;
F_44 ( & V_13 -> V_43 ) ;
}
struct V_12 * F_58 ( struct V_62 * V_26 )
{
struct V_12 * V_13 , * V_29 ;
F_18 (local, n, &llcp_devices, list)
if ( V_13 -> V_26 == V_26 )
return V_13 ;
F_9 ( L_4 ) ;
return NULL ;
}
static int F_59 ( char * V_63 , T_2 V_64 )
{
int V_59 , V_65 ;
F_9 ( L_5 , V_63 ) ;
if ( V_63 == NULL )
return - V_66 ;
V_65 = F_60 ( V_67 ) ;
for ( V_59 = 0 ; V_59 < V_65 ; V_59 ++ ) {
if ( V_67 [ V_59 ] == NULL )
continue;
if ( strncmp ( V_67 [ V_59 ] , V_63 , V_64 ) == 0 )
return V_59 ;
}
return - V_66 ;
}
static
struct V_7 * F_61 ( struct V_12 * V_13 ,
T_1 * V_68 , T_2 V_69 )
{
struct V_3 * V_4 ;
struct V_7 * V_22 , * V_49 ;
F_9 ( L_6 , V_69 , V_68 ) ;
if ( V_68 == NULL || V_69 == 0 )
return NULL ;
F_34 ( & V_13 -> V_23 . V_5 ) ;
V_22 = NULL ;
F_35 (sk, &local->sockets.head) {
V_49 = V_7 ( V_4 ) ;
F_9 ( L_7 , V_49 ) ;
if ( V_49 -> V_4 . V_70 == V_71 &&
V_49 -> V_4 . V_24 != V_27 )
continue;
if ( V_49 -> V_4 . V_70 == V_72 &&
V_49 -> V_4 . V_24 != V_73 )
continue;
if ( V_49 -> V_63 == NULL ||
V_49 -> V_64 == 0 )
continue;
if ( V_49 -> V_64 != V_69 )
continue;
if ( memcmp ( V_68 , V_49 -> V_63 , V_69 ) == 0 ) {
V_22 = V_49 ;
break;
}
}
F_36 ( & V_13 -> V_23 . V_5 ) ;
F_9 ( L_8 , V_22 ) ;
return V_22 ;
}
T_1 F_62 ( struct V_12 * V_13 ,
struct V_7 * V_3 )
{
F_47 ( & V_13 -> V_74 ) ;
if ( V_3 -> V_63 != NULL && V_3 -> V_64 > 0 ) {
int V_47 = F_59 ( V_3 -> V_63 ,
V_3 -> V_64 ) ;
if ( V_47 > 0 ) {
F_9 ( L_9 , V_47 ) ;
if ( V_13 -> V_75 & F_63 ( V_47 ) ) {
F_55 ( & V_13 -> V_74 ) ;
return V_76 ;
}
F_64 ( V_47 , & V_13 -> V_75 ) ;
F_55 ( & V_13 -> V_74 ) ;
return V_47 ;
}
if ( F_61 ( V_13 , V_3 -> V_63 ,
V_3 -> V_64 ) != NULL ) {
F_55 ( & V_13 -> V_74 ) ;
return V_76 ;
}
F_55 ( & V_13 -> V_74 ) ;
return V_60 ;
} else if ( V_3 -> V_47 != 0 && V_3 -> V_47 < V_77 ) {
if ( ! F_65 ( V_3 -> V_47 , & V_13 -> V_75 ) ) {
F_64 ( V_3 -> V_47 , & V_13 -> V_75 ) ;
F_55 ( & V_13 -> V_74 ) ;
return V_3 -> V_47 ;
}
}
F_55 ( & V_13 -> V_74 ) ;
return V_76 ;
}
T_1 F_66 ( struct V_12 * V_13 )
{
T_1 V_78 ;
F_47 ( & V_13 -> V_74 ) ;
V_78 = F_67 ( & V_13 -> V_79 , V_80 ) ;
if ( V_78 == V_80 ) {
F_55 ( & V_13 -> V_74 ) ;
return V_76 ;
}
F_64 ( V_78 , & V_13 -> V_79 ) ;
F_55 ( & V_13 -> V_74 ) ;
return V_78 + V_81 ;
}
void F_68 ( struct V_12 * V_13 , T_1 V_47 )
{
T_1 V_78 ;
unsigned long * V_55 ;
if ( V_47 < V_77 ) {
V_78 = V_47 ;
V_55 = & V_13 -> V_75 ;
} else if ( V_47 < V_80 ) {
T_3 * V_82 ;
V_78 = V_47 - V_77 ;
V_55 = & V_13 -> V_83 ;
V_82 = & V_13 -> V_84 [ V_78 ] ;
F_9 ( L_10 , F_69 ( V_82 ) ) ;
F_47 ( & V_13 -> V_74 ) ;
if ( F_70 ( V_82 ) ) {
struct V_7 * V_85 ;
F_9 ( L_11 , V_47 ) ;
F_71 ( V_78 , V_55 ) ;
V_85 = F_33 ( V_13 , V_47 , V_86 ) ;
if ( V_85 ) {
V_85 -> V_47 = V_60 ;
F_38 ( V_85 ) ;
}
}
F_55 ( & V_13 -> V_74 ) ;
return;
} else if ( V_47 < V_87 ) {
V_78 = V_47 - V_80 ;
V_55 = & V_13 -> V_79 ;
} else {
return;
}
F_47 ( & V_13 -> V_74 ) ;
F_71 ( V_78 , V_55 ) ;
F_55 ( & V_13 -> V_74 ) ;
}
static T_1 F_72 ( struct V_12 * V_13 )
{
T_1 V_47 ;
F_47 ( & V_13 -> V_74 ) ;
V_47 = F_67 ( & V_13 -> V_83 , V_88 ) ;
if ( V_47 == V_88 ) {
F_55 ( & V_13 -> V_74 ) ;
return V_76 ;
}
F_9 ( L_12 , V_77 + V_47 ) ;
F_64 ( V_47 , & V_13 -> V_83 ) ;
F_55 ( & V_13 -> V_74 ) ;
return V_77 + V_47 ;
}
static int F_73 ( struct V_12 * V_13 )
{
T_1 * V_89 , * V_90 , V_91 , V_92 ;
T_1 * V_93 , V_94 ;
T_1 * V_95 , V_96 ;
T_1 * V_97 , V_98 ;
T_1 V_99 = 0 ;
int V_100 = 0 ;
V_91 = V_101 ;
V_90 = F_74 ( V_102 , & V_91 ,
1 , & V_92 ) ;
V_99 += V_92 ;
V_93 = F_74 ( V_103 , & V_13 -> V_104 , 1 , & V_94 ) ;
V_99 += V_94 ;
F_9 ( L_13 , V_13 -> V_75 ) ;
V_95 = F_74 ( V_105 , ( T_1 * ) & V_13 -> V_75 , 2 ,
& V_96 ) ;
V_99 += V_96 ;
V_97 = F_74 ( V_106 , ( T_1 * ) & V_13 -> V_107 , 0 ,
& V_98 ) ;
V_99 += V_98 ;
V_99 += F_60 ( V_108 ) ;
if ( V_99 > V_109 ) {
V_100 = - V_66 ;
goto V_110;
}
V_89 = V_13 -> V_111 ;
memcpy ( V_89 , V_108 , F_60 ( V_108 ) ) ;
V_89 += F_60 ( V_108 ) ;
memcpy ( V_89 , V_90 , V_92 ) ;
V_89 += V_92 ;
memcpy ( V_89 , V_93 , V_94 ) ;
V_89 += V_94 ;
memcpy ( V_89 , V_95 , V_96 ) ;
V_89 += V_96 ;
memcpy ( V_89 , V_97 , V_98 ) ;
V_89 += V_98 ;
V_13 -> V_99 = V_99 ;
V_110:
F_30 ( V_90 ) ;
F_30 ( V_93 ) ;
F_30 ( V_95 ) ;
F_30 ( V_97 ) ;
return V_100 ;
}
T_1 * F_75 ( struct V_62 * V_26 , T_2 * V_112 )
{
struct V_12 * V_13 ;
V_13 = F_58 ( V_26 ) ;
if ( V_13 == NULL ) {
* V_112 = 0 ;
return NULL ;
}
F_73 ( V_13 ) ;
* V_112 = V_13 -> V_99 ;
return V_13 -> V_111 ;
}
int F_76 ( struct V_62 * V_26 , T_1 * V_111 , T_1 V_99 )
{
struct V_12 * V_13 = F_58 ( V_26 ) ;
if ( V_13 == NULL ) {
F_43 ( L_14 ) ;
return - V_113 ;
}
if ( V_99 < 3 )
return - V_66 ;
memset ( V_13 -> V_114 , 0 , V_109 ) ;
memcpy ( V_13 -> V_114 , V_111 , V_99 ) ;
V_13 -> V_115 = V_99 ;
if ( memcmp ( V_13 -> V_114 , V_108 , 3 ) ) {
F_43 ( L_15 ) ;
return - V_66 ;
}
return F_77 ( V_13 ,
& V_13 -> V_114 [ 3 ] ,
V_13 -> V_115 - 3 ) ;
}
static T_1 F_78 ( struct V_14 * V_116 )
{
return ( V_116 -> V_52 [ 0 ] & 0xfc ) >> 2 ;
}
static T_1 F_79 ( struct V_14 * V_116 )
{
return ( ( V_116 -> V_52 [ 0 ] & 0x03 ) << 2 ) | ( ( V_116 -> V_52 [ 1 ] & 0xc0 ) >> 6 ) ;
}
static T_1 F_80 ( struct V_14 * V_116 )
{
return V_116 -> V_52 [ 1 ] & 0x3f ;
}
static T_1 F_81 ( struct V_14 * V_116 )
{
return V_116 -> V_52 [ 2 ] >> 4 ;
}
static T_1 F_82 ( struct V_14 * V_116 )
{
return V_116 -> V_52 [ 2 ] & 0xf ;
}
static void F_83 ( struct V_7 * V_3 , struct V_14 * V_116 )
{
V_116 -> V_52 [ 2 ] = ( V_3 -> V_117 << 4 ) | ( V_3 -> V_118 ) ;
V_3 -> V_117 = ( V_3 -> V_117 + 1 ) % 16 ;
V_3 -> V_119 = ( V_3 -> V_118 - 1 ) % 16 ;
}
void F_84 ( struct V_12 * V_13 ,
struct V_14 * V_120 , T_1 V_121 )
{
struct V_14 * V_122 = NULL , * V_123 ;
struct V_3 * V_4 ;
T_1 * V_52 ;
F_34 ( & V_13 -> V_34 . V_5 ) ;
F_35 (sk, &local->raw_sockets.head) {
if ( V_4 -> V_24 != V_73 )
continue;
if ( V_122 == NULL ) {
V_122 = F_85 ( V_120 , V_124 ,
V_125 ) ;
if ( V_122 == NULL )
continue;
V_52 = F_86 ( V_122 , V_124 ) ;
V_52 [ 0 ] = V_13 -> V_26 ? V_13 -> V_26 -> V_126 : 0xFF ;
V_52 [ 1 ] = V_121 ;
}
V_123 = F_87 ( V_122 , V_125 ) ;
if ( ! V_123 )
continue;
if ( F_88 ( V_4 , V_123 ) )
F_13 ( V_123 ) ;
}
F_36 ( & V_13 -> V_34 . V_5 ) ;
F_13 ( V_122 ) ;
}
static void F_89 ( struct V_50 * V_51 )
{
struct V_12 * V_13 = F_28 ( V_51 , struct V_12 ,
V_38 ) ;
struct V_14 * V_120 ;
struct V_3 * V_4 ;
struct V_7 * V_22 ;
V_120 = F_90 ( & V_13 -> V_17 ) ;
if ( V_120 != NULL ) {
V_4 = V_120 -> V_4 ;
V_22 = V_7 ( V_4 ) ;
if ( V_22 == NULL && F_79 ( V_120 ) == V_127 ) {
F_91 ( V_13 -> V_26 ) ;
} else {
struct V_14 * V_128 = NULL ;
T_1 V_129 = F_79 ( V_120 ) ;
int V_100 ;
F_9 ( L_16 ) ;
F_92 ( V_130 , L_17 ,
V_131 , 16 , 1 ,
V_120 -> V_52 , V_120 -> V_132 , true ) ;
if ( V_129 == V_127 )
V_128 = V_122 ( V_120 , V_125 ) ;
F_93 ( V_120 ) ;
F_84 ( V_13 , V_120 ,
V_133 ) ;
V_100 = F_94 ( V_13 -> V_26 , V_13 -> V_134 ,
V_120 , V_135 , V_13 ) ;
if ( V_100 ) {
F_13 ( V_128 ) ;
goto V_110;
}
if ( V_129 == V_127 && V_128 )
F_95 ( & V_22 -> V_18 ,
V_128 ) ;
}
} else {
F_91 ( V_13 -> V_26 ) ;
}
V_110:
F_54 ( & V_13 -> V_37 ,
V_57 + F_48 ( 2 * V_13 -> V_58 ) ) ;
}
static struct V_7 * F_96 ( struct V_12 * V_13 ,
T_1 V_47 )
{
struct V_3 * V_4 ;
struct V_7 * V_22 ;
F_34 ( & V_13 -> V_136 . V_5 ) ;
F_35 (sk, &local->connecting_sockets.head) {
V_22 = V_7 ( V_4 ) ;
if ( V_22 -> V_47 == V_47 ) {
F_37 ( & V_22 -> V_4 ) ;
goto V_110;
}
}
V_22 = NULL ;
V_110:
F_36 ( & V_13 -> V_136 . V_5 ) ;
return V_22 ;
}
static struct V_7 * F_97 ( struct V_12 * V_13 ,
T_1 * V_68 , T_2 V_69 )
{
struct V_7 * V_22 ;
V_22 = F_61 ( V_13 , V_68 , V_69 ) ;
if ( V_22 == NULL )
return NULL ;
F_37 ( & V_22 -> V_4 ) ;
return V_22 ;
}
static T_1 * F_98 ( struct V_14 * V_120 , T_2 * V_69 )
{
T_1 * V_137 = & V_120 -> V_52 [ 2 ] , type , V_138 ;
T_2 V_139 = V_120 -> V_132 - V_140 , V_141 = 0 ;
while ( V_141 < V_139 ) {
type = V_137 [ 0 ] ;
V_138 = V_137 [ 1 ] ;
F_9 ( L_18 , type , V_138 ) ;
if ( type == V_142 ) {
* V_69 = V_138 ;
return & V_137 [ 2 ] ;
}
V_141 += V_138 + 2 ;
V_137 += V_138 + 2 ;
}
return NULL ;
}
static void F_99 ( struct V_12 * V_13 ,
struct V_14 * V_120 )
{
struct V_7 * V_22 ;
struct V_143 * V_144 ;
T_1 V_48 , V_47 ;
V_48 = F_78 ( V_120 ) ;
V_47 = F_80 ( V_120 ) ;
V_144 = F_100 ( V_120 ) ;
V_144 -> V_48 = V_48 ;
V_144 -> V_47 = V_47 ;
F_9 ( L_19 , V_48 , V_47 ) ;
V_22 = F_33 ( V_13 , V_48 , V_86 ) ;
if ( V_22 == NULL || V_22 -> V_4 . V_70 != V_72 )
return;
F_101 ( V_120 , V_140 ) ;
if ( ! F_88 ( & V_22 -> V_4 , V_120 ) ) {
F_102 ( V_120 ) ;
} else {
F_43 ( L_20 ) ;
}
F_38 ( V_22 ) ;
}
static void F_103 ( struct V_12 * V_13 ,
struct V_14 * V_120 )
{
struct V_3 * V_145 , * V_146 ;
struct V_7 * V_3 , * V_147 ;
T_1 V_48 , V_47 , V_148 ;
V_48 = F_78 ( V_120 ) ;
V_47 = F_80 ( V_120 ) ;
F_9 ( L_19 , V_48 , V_47 ) ;
if ( V_48 != V_86 ) {
V_3 = F_33 ( V_13 , V_48 , V_86 ) ;
if ( V_3 == NULL || V_3 -> V_4 . V_24 != V_27 ) {
V_148 = V_149 ;
goto V_150;
}
} else {
T_1 * V_68 ;
T_2 V_69 ;
V_68 = F_98 ( V_120 , & V_69 ) ;
if ( V_68 == NULL ) {
V_148 = V_149 ;
goto V_150;
}
F_9 ( L_21 , V_69 ) ;
V_3 = F_97 ( V_13 , V_68 , V_69 ) ;
if ( V_3 == NULL ) {
V_148 = V_149 ;
goto V_150;
}
}
F_104 ( & V_3 -> V_4 ) ;
V_146 = & V_3 -> V_4 ;
if ( F_105 ( V_146 ) ) {
V_148 = V_151 ;
F_106 ( & V_3 -> V_4 ) ;
F_39 ( & V_3 -> V_4 ) ;
goto V_150;
}
if ( V_3 -> V_47 == V_60 ) {
T_1 V_47 = F_72 ( V_13 ) ;
F_9 ( L_22 , V_47 ) ;
if ( V_47 == V_76 ) {
V_148 = V_151 ;
F_106 ( & V_3 -> V_4 ) ;
F_39 ( & V_3 -> V_4 ) ;
goto V_150;
}
V_3 -> V_47 = V_47 ;
}
V_145 = F_107 ( NULL , V_146 -> V_70 , V_125 ) ;
if ( V_145 == NULL ) {
V_148 = V_151 ;
F_106 ( & V_3 -> V_4 ) ;
F_39 ( & V_3 -> V_4 ) ;
goto V_150;
}
V_147 = V_7 ( V_145 ) ;
V_147 -> V_26 = V_13 -> V_26 ;
V_147 -> V_13 = F_21 ( V_13 ) ;
V_147 -> V_152 = V_3 -> V_152 ;
V_147 -> V_107 = V_3 -> V_107 ;
V_147 -> V_10 = V_13 -> V_10 ;
V_147 -> V_153 = V_3 -> V_153 ;
V_147 -> V_48 = V_47 ;
V_147 -> V_134 = V_13 -> V_134 ;
V_147 -> V_146 = V_146 ;
V_147 -> V_47 = V_3 -> V_47 ;
if ( V_3 -> V_47 < V_80 && V_3 -> V_47 >= V_77 ) {
T_3 * V_154 ;
F_9 ( L_23 , V_3 -> V_47 , V_147 ) ;
V_154 =
& V_13 -> V_84 [ V_3 -> V_47 - V_77 ] ;
F_108 ( V_154 ) ;
V_147 -> V_155 = V_3 -> V_47 ;
}
F_109 ( V_147 , & V_120 -> V_52 [ V_140 ] ,
V_120 -> V_132 - V_140 ) ;
F_9 ( L_24 , V_147 , & V_147 -> V_4 ) ;
F_1 ( & V_13 -> V_23 , V_145 ) ;
F_110 ( & V_3 -> V_4 , V_145 ) ;
F_111 ( V_13 -> V_26 -> V_126 ) ;
V_145 -> V_24 = V_25 ;
V_146 -> V_156 ( V_146 , 0 ) ;
F_112 ( V_147 ) ;
F_106 ( & V_3 -> V_4 ) ;
F_39 ( & V_3 -> V_4 ) ;
return;
V_150:
F_113 ( V_13 , V_48 , V_47 , V_148 ) ;
}
int F_114 ( struct V_7 * V_3 )
{
int V_157 = 0 ;
struct V_12 * V_13 = V_3 -> V_13 ;
F_9 ( L_25 ,
V_3 -> V_158 , F_115 ( & V_3 -> V_18 ) ,
V_3 -> V_8 ) ;
while ( V_3 -> V_158 &&
F_115 ( & V_3 -> V_18 ) < V_3 -> V_8 ) {
struct V_14 * V_116 ;
V_116 = F_90 ( & V_3 -> V_17 ) ;
if ( V_116 == NULL )
break;
F_83 ( V_3 , V_116 ) ;
F_95 ( & V_13 -> V_17 , V_116 ) ;
V_157 ++ ;
}
return V_157 ;
}
static void F_116 ( struct V_12 * V_13 ,
struct V_14 * V_120 )
{
struct V_7 * V_22 ;
struct V_3 * V_4 ;
T_1 V_48 , V_47 , V_129 , V_159 , V_160 ;
V_129 = F_79 ( V_120 ) ;
V_48 = F_78 ( V_120 ) ;
V_47 = F_80 ( V_120 ) ;
V_159 = F_81 ( V_120 ) ;
V_160 = F_82 ( V_120 ) ;
F_9 ( L_26 , V_48 , V_47 , V_160 , V_159 ) ;
V_22 = F_33 ( V_13 , V_48 , V_47 ) ;
if ( V_22 == NULL ) {
F_113 ( V_13 , V_48 , V_47 , V_161 ) ;
return;
}
V_4 = & V_22 -> V_4 ;
F_104 ( V_4 ) ;
if ( V_4 -> V_24 == V_32 ) {
F_106 ( V_4 ) ;
F_38 ( V_22 ) ;
}
if ( V_129 == V_127 ) {
F_9 ( L_27 , & V_22 -> V_4 ) ;
if ( V_159 == V_22 -> V_118 )
V_22 -> V_118 = ( V_22 -> V_118 + 1 ) % 16 ;
else
F_43 ( L_28 ) ;
F_101 ( V_120 , V_140 + V_162 ) ;
if ( ! F_88 ( & V_22 -> V_4 , V_120 ) ) {
F_102 ( V_120 ) ;
} else {
F_43 ( L_20 ) ;
}
}
if ( V_22 -> V_163 != V_160 ) {
struct V_14 * V_15 , * V_16 ;
T_1 V_29 ;
V_22 -> V_163 = V_160 ;
F_11 (&llcp_sock->tx_pending_queue, s, tmp) {
V_29 = F_81 ( V_15 ) ;
F_12 ( V_15 , & V_22 -> V_18 ) ;
F_13 ( V_15 ) ;
if ( V_29 == V_160 )
break;
}
F_117 (&llcp_sock->tx_pending_queue,
s, tmp) {
F_12 ( V_15 , & V_22 -> V_18 ) ;
F_118 ( & V_13 -> V_17 , V_15 ) ;
}
}
if ( V_129 == V_164 )
V_22 -> V_158 = true ;
else if ( V_129 == V_165 )
V_22 -> V_158 = false ;
if ( F_114 ( V_22 ) == 0 && V_129 == V_127 )
F_119 ( V_22 ) ;
F_106 ( V_4 ) ;
F_38 ( V_22 ) ;
}
static void F_120 ( struct V_12 * V_13 ,
struct V_14 * V_120 )
{
struct V_7 * V_22 ;
struct V_3 * V_4 ;
T_1 V_48 , V_47 ;
V_48 = F_78 ( V_120 ) ;
V_47 = F_80 ( V_120 ) ;
if ( ( V_48 == 0 ) && ( V_47 == 0 ) ) {
F_9 ( L_29 ) ;
F_41 ( V_13 -> V_26 ) ;
return;
}
V_22 = F_33 ( V_13 , V_48 , V_47 ) ;
if ( V_22 == NULL ) {
F_113 ( V_13 , V_48 , V_47 , V_161 ) ;
return;
}
V_4 = & V_22 -> V_4 ;
F_104 ( V_4 ) ;
F_8 ( V_22 ) ;
if ( V_4 -> V_24 == V_32 ) {
F_106 ( V_4 ) ;
F_38 ( V_22 ) ;
}
if ( V_4 -> V_24 == V_25 ) {
F_17 ( V_13 -> V_26 ) ;
V_4 -> V_24 = V_32 ;
V_4 -> V_33 ( V_4 ) ;
}
F_113 ( V_13 , V_48 , V_47 , V_166 ) ;
F_106 ( V_4 ) ;
F_38 ( V_22 ) ;
}
static void F_121 ( struct V_12 * V_13 , struct V_14 * V_120 )
{
struct V_7 * V_22 ;
struct V_3 * V_4 ;
T_1 V_48 , V_47 ;
V_48 = F_78 ( V_120 ) ;
V_47 = F_80 ( V_120 ) ;
V_22 = F_96 ( V_13 , V_48 ) ;
if ( V_22 == NULL ) {
F_43 ( L_30 ) ;
F_113 ( V_13 , V_48 , V_47 , V_161 ) ;
return;
}
V_4 = & V_22 -> V_4 ;
F_5 ( & V_13 -> V_136 , V_4 ) ;
F_1 ( & V_13 -> V_23 , V_4 ) ;
V_22 -> V_48 = V_47 ;
F_109 ( V_22 , & V_120 -> V_52 [ V_140 ] ,
V_120 -> V_132 - V_140 ) ;
V_4 -> V_24 = V_25 ;
V_4 -> V_33 ( V_4 ) ;
F_38 ( V_22 ) ;
}
static void F_122 ( struct V_12 * V_13 , struct V_14 * V_120 )
{
struct V_7 * V_22 ;
struct V_3 * V_4 ;
T_1 V_48 , V_47 , V_148 ;
V_48 = F_78 ( V_120 ) ;
V_47 = F_80 ( V_120 ) ;
V_148 = V_120 -> V_52 [ 2 ] ;
F_9 ( L_31 , V_47 , V_48 , V_148 ) ;
switch ( V_148 ) {
case V_149 :
case V_151 :
V_22 = F_96 ( V_13 , V_48 ) ;
break;
default:
V_22 = F_33 ( V_13 , V_48 , V_47 ) ;
break;
}
if ( V_22 == NULL ) {
F_9 ( L_32 ) ;
return;
}
V_4 = & V_22 -> V_4 ;
V_4 -> V_31 = V_36 ;
V_4 -> V_24 = V_32 ;
V_4 -> V_33 ( V_4 ) ;
F_38 ( V_22 ) ;
}
static void F_123 ( struct V_12 * V_13 ,
struct V_14 * V_120 )
{
struct V_7 * V_22 ;
T_1 V_48 , V_47 , * V_137 , type , V_138 , V_167 , V_59 ;
T_4 V_168 , V_141 ;
char * V_63 ;
T_2 V_64 ;
struct V_54 * V_55 ;
F_46 ( V_169 ) ;
T_2 V_170 ;
F_46 ( V_53 ) ;
V_48 = F_78 ( V_120 ) ;
V_47 = F_80 ( V_120 ) ;
F_9 ( L_19 , V_48 , V_47 ) ;
if ( V_48 != V_86 || V_47 != V_86 ) {
F_43 ( L_33 ) ;
return;
}
V_137 = & V_120 -> V_52 [ V_140 ] ;
V_168 = V_120 -> V_132 - V_140 ;
V_141 = 0 ;
V_170 = 0 ;
while ( V_141 < V_168 ) {
type = V_137 [ 0 ] ;
V_138 = V_137 [ 1 ] ;
switch ( type ) {
case V_171 :
V_167 = V_137 [ 2 ] ;
V_63 = ( char * ) & V_137 [ 3 ] ;
V_64 = V_138 - 1 ;
F_9 ( L_34 , V_63 ) ;
if ( V_64 == strlen ( L_35 ) &&
! strncmp ( V_63 , L_35 ,
V_64 ) ) {
V_59 = 1 ;
goto V_172;
}
V_22 = F_61 ( V_13 , V_63 ,
V_64 ) ;
if ( ! V_22 ) {
V_59 = 0 ;
goto V_172;
}
if ( V_22 -> V_47 == V_60 ) {
T_3 * V_154 ;
V_59 = F_72 ( V_13 ) ;
F_9 ( L_36 , V_59 ) ;
if ( V_59 == V_76 ) {
V_59 = 0 ;
goto V_172;
}
V_154 =
& V_13 -> V_84 [ V_59 -
V_77 ] ;
F_108 ( V_154 ) ;
V_22 -> V_47 = V_59 ;
V_22 -> V_155 = V_59 ;
} else {
V_59 = V_22 -> V_47 ;
}
F_9 ( L_37 , V_22 , V_59 ) ;
V_172:
V_55 = F_124 ( V_167 , V_59 ) ;
if ( V_55 == NULL )
goto exit;
V_170 += V_55 -> V_168 ;
F_52 ( & V_55 -> V_61 , & V_169 ) ;
break;
case V_173 :
F_47 ( & V_13 -> V_56 ) ;
F_9 ( L_38 , V_137 [ 2 ] ) ;
F_125 (sdp, &local->pending_sdreqs, node) {
if ( V_55 -> V_167 != V_137 [ 2 ] )
continue;
V_55 -> V_59 = V_137 [ 3 ] ;
F_9 ( L_39 ,
V_55 -> V_174 , V_55 -> V_59 ) ;
F_51 ( & V_55 -> V_61 ) ;
F_52 ( & V_55 -> V_61 , & V_53 ) ;
break;
}
F_55 ( & V_13 -> V_56 ) ;
break;
default:
F_43 ( L_40 , type ) ;
break;
}
V_141 += V_138 + 2 ;
V_137 += V_138 + 2 ;
}
exit:
if ( ! F_53 ( & V_53 ) )
F_56 ( V_13 -> V_26 , & V_53 ) ;
if ( ! F_53 ( & V_169 ) )
F_126 ( V_13 , & V_169 , V_170 ) ;
}
static void F_127 ( struct V_12 * V_13 , struct V_14 * V_120 )
{
T_1 V_129 ;
T_4 V_175 ;
struct V_14 * V_176 ;
if ( V_120 -> V_132 <= V_140 ) {
F_43 ( L_41 ) ;
return;
}
F_101 ( V_120 , V_140 ) ;
while ( V_120 -> V_132 > V_177 ) {
V_175 = V_120 -> V_52 [ 0 ] << 8 | V_120 -> V_52 [ 1 ] ;
F_101 ( V_120 , V_177 ) ;
if ( V_175 < V_140 || V_175 > V_120 -> V_132 ) {
F_43 ( L_41 ) ;
return;
}
V_129 = F_79 ( V_120 ) ;
if ( V_129 == V_178 || V_129 == V_179 )
goto V_180;
V_176 = F_128 ( V_175 , V_181 ) ;
if ( V_176 == NULL ) {
F_43 ( L_42 ) ;
return;
}
memcpy ( F_129 ( V_176 , V_175 ) , V_120 -> V_52 , V_175 ) ;
F_130 ( V_13 , V_176 ) ;
F_13 ( V_176 ) ;
V_180:
F_101 ( V_120 , V_175 ) ;
}
}
static void F_130 ( struct V_12 * V_13 , struct V_14 * V_120 )
{
T_1 V_48 , V_47 , V_129 ;
V_129 = F_79 ( V_120 ) ;
V_48 = F_78 ( V_120 ) ;
V_47 = F_80 ( V_120 ) ;
F_9 ( L_43 , V_129 , V_48 , V_47 ) ;
if ( V_129 != V_178 )
F_92 ( V_130 , L_44 , V_131 ,
16 , 1 , V_120 -> V_52 , V_120 -> V_132 , true ) ;
switch ( V_129 ) {
case V_178 :
F_9 ( L_45 ) ;
break;
case V_182 :
F_9 ( L_46 ) ;
F_99 ( V_13 , V_120 ) ;
break;
case V_183 :
F_9 ( L_47 ) ;
F_103 ( V_13 , V_120 ) ;
break;
case V_184 :
F_9 ( L_48 ) ;
F_120 ( V_13 , V_120 ) ;
break;
case V_185 :
F_9 ( L_49 ) ;
F_121 ( V_13 , V_120 ) ;
break;
case V_186 :
F_9 ( L_50 ) ;
F_122 ( V_13 , V_120 ) ;
break;
case V_187 :
F_9 ( L_51 ) ;
F_123 ( V_13 , V_120 ) ;
break;
case V_127 :
case V_164 :
case V_165 :
F_9 ( L_52 ) ;
F_116 ( V_13 , V_120 ) ;
break;
case V_179 :
F_9 ( L_53 ) ;
F_127 ( V_13 , V_120 ) ;
break;
}
}
static void F_131 ( struct V_50 * V_51 )
{
struct V_12 * V_13 = F_28 ( V_51 , struct V_12 ,
V_39 ) ;
struct V_14 * V_120 ;
V_120 = V_13 -> V_41 ;
if ( V_120 == NULL ) {
F_9 ( L_54 ) ;
return;
}
F_93 ( V_120 ) ;
F_84 ( V_13 , V_120 , V_188 ) ;
F_130 ( V_13 , V_120 ) ;
F_44 ( & V_13 -> V_38 ) ;
F_13 ( V_13 -> V_41 ) ;
V_13 -> V_41 = NULL ;
}
static void F_132 ( struct V_12 * V_13 , struct V_14 * V_120 )
{
V_13 -> V_41 = V_120 ;
F_133 ( & V_13 -> V_37 ) ;
F_44 ( & V_13 -> V_39 ) ;
}
void V_135 ( void * V_52 , struct V_14 * V_120 , int V_20 )
{
struct V_12 * V_13 = (struct V_12 * ) V_52 ;
F_9 ( L_55 ) ;
if ( V_20 < 0 ) {
F_43 ( L_56 , V_20 ) ;
return;
}
F_132 ( V_13 , V_120 ) ;
}
int F_134 ( struct V_62 * V_26 , struct V_14 * V_120 )
{
struct V_12 * V_13 ;
V_13 = F_58 ( V_26 ) ;
if ( V_13 == NULL )
return - V_113 ;
F_132 ( V_13 , V_120 ) ;
return 0 ;
}
void F_135 ( struct V_62 * V_26 )
{
struct V_12 * V_13 ;
V_13 = F_58 ( V_26 ) ;
if ( V_13 == NULL )
return;
V_13 -> V_10 = V_189 ;
V_13 -> V_58 = V_190 ;
F_14 ( V_13 , true , 0 ) ;
}
void F_136 ( struct V_62 * V_26 , T_5 V_134 ,
T_1 V_191 , T_1 V_192 )
{
struct V_12 * V_13 ;
F_9 ( L_57 , V_192 ) ;
V_13 = F_58 ( V_26 ) ;
if ( V_13 == NULL )
return;
V_13 -> V_134 = V_134 ;
V_13 -> V_191 = V_191 ;
V_13 -> V_192 = V_192 ;
if ( V_192 == V_193 ) {
F_9 ( L_58 ) ;
F_44 ( & V_13 -> V_38 ) ;
} else {
F_54 ( & V_13 -> V_37 ,
V_57 + F_48 ( V_13 -> V_58 ) ) ;
}
}
int F_137 ( struct V_62 * V_194 )
{
struct V_12 * V_13 ;
V_13 = F_138 ( sizeof( struct V_12 ) , V_181 ) ;
if ( V_13 == NULL )
return - V_195 ;
V_13 -> V_26 = V_194 ;
F_139 ( & V_13 -> V_46 ) ;
F_140 ( & V_13 -> V_35 ) ;
F_141 ( & V_13 -> V_74 ) ;
F_142 ( & V_13 -> V_37 ) ;
V_13 -> V_37 . V_52 = ( unsigned long ) V_13 ;
V_13 -> V_37 . V_196 = F_42 ;
F_143 ( & V_13 -> V_17 ) ;
F_144 ( & V_13 -> V_38 , F_89 ) ;
V_13 -> V_41 = NULL ;
F_144 ( & V_13 -> V_39 , F_131 ) ;
F_144 ( & V_13 -> V_40 , F_40 ) ;
F_145 ( & V_13 -> V_23 . V_5 ) ;
F_145 ( & V_13 -> V_136 . V_5 ) ;
F_145 ( & V_13 -> V_34 . V_5 ) ;
V_13 -> V_104 = 150 ;
V_13 -> V_152 = V_197 ;
V_13 -> V_107 = F_146 ( V_198 ) ;
F_73 ( V_13 ) ;
V_13 -> V_10 = V_189 ;
V_13 -> V_58 = V_190 ;
F_141 ( & V_13 -> V_56 ) ;
F_147 ( & V_13 -> V_44 ) ;
F_142 ( & V_13 -> V_42 ) ;
V_13 -> V_42 . V_52 = ( unsigned long ) V_13 ;
V_13 -> V_42 . V_196 = F_57 ;
F_144 ( & V_13 -> V_43 , F_45 ) ;
F_148 ( & V_13 -> V_46 , & V_199 ) ;
return 0 ;
}
void F_149 ( struct V_62 * V_26 )
{
struct V_12 * V_13 = F_58 ( V_26 ) ;
if ( V_13 == NULL ) {
F_9 ( L_59 ) ;
return;
}
F_23 ( V_13 ) ;
F_31 ( V_13 ) ;
}
int T_6 F_150 ( void )
{
F_139 ( & V_199 ) ;
return F_151 () ;
}
void F_152 ( void )
{
F_153 () ;
}
