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
struct V_12 * V_13 ;
F_59 (local, &llcp_devices, list)
if ( V_13 -> V_26 == V_26 )
return V_13 ;
F_9 ( L_4 ) ;
return NULL ;
}
static int F_60 ( char * V_63 , T_2 V_64 )
{
int V_59 , V_65 ;
F_9 ( L_5 , V_63 ) ;
if ( V_63 == NULL )
return - V_66 ;
V_65 = F_61 ( V_67 ) ;
for ( V_59 = 0 ; V_59 < V_65 ; V_59 ++ ) {
if ( V_67 [ V_59 ] == NULL )
continue;
if ( strncmp ( V_67 [ V_59 ] , V_63 , V_64 ) == 0 )
return V_59 ;
}
return - V_66 ;
}
static
struct V_7 * F_62 ( struct V_12 * V_13 ,
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
T_1 F_63 ( struct V_12 * V_13 ,
struct V_7 * V_3 )
{
F_47 ( & V_13 -> V_74 ) ;
if ( V_3 -> V_63 != NULL && V_3 -> V_64 > 0 ) {
int V_47 = F_60 ( V_3 -> V_63 ,
V_3 -> V_64 ) ;
if ( V_47 > 0 ) {
F_9 ( L_9 , V_47 ) ;
if ( V_13 -> V_75 & F_64 ( V_47 ) ) {
F_55 ( & V_13 -> V_74 ) ;
return V_76 ;
}
F_65 ( V_47 , & V_13 -> V_75 ) ;
F_55 ( & V_13 -> V_74 ) ;
return V_47 ;
}
if ( F_62 ( V_13 , V_3 -> V_63 ,
V_3 -> V_64 ) != NULL ) {
F_55 ( & V_13 -> V_74 ) ;
return V_76 ;
}
F_55 ( & V_13 -> V_74 ) ;
return V_60 ;
} else if ( V_3 -> V_47 != 0 && V_3 -> V_47 < V_77 ) {
if ( ! F_66 ( V_3 -> V_47 , & V_13 -> V_75 ) ) {
F_65 ( V_3 -> V_47 , & V_13 -> V_75 ) ;
F_55 ( & V_13 -> V_74 ) ;
return V_3 -> V_47 ;
}
}
F_55 ( & V_13 -> V_74 ) ;
return V_76 ;
}
T_1 F_67 ( struct V_12 * V_13 )
{
T_1 V_78 ;
F_47 ( & V_13 -> V_74 ) ;
V_78 = F_68 ( & V_13 -> V_79 , V_80 ) ;
if ( V_78 == V_80 ) {
F_55 ( & V_13 -> V_74 ) ;
return V_76 ;
}
F_65 ( V_78 , & V_13 -> V_79 ) ;
F_55 ( & V_13 -> V_74 ) ;
return V_78 + V_81 ;
}
void F_69 ( struct V_12 * V_13 , T_1 V_47 )
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
F_9 ( L_10 , F_70 ( V_82 ) ) ;
F_47 ( & V_13 -> V_74 ) ;
if ( F_71 ( V_82 ) ) {
struct V_7 * V_85 ;
F_9 ( L_11 , V_47 ) ;
F_72 ( V_78 , V_55 ) ;
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
F_72 ( V_78 , V_55 ) ;
F_55 ( & V_13 -> V_74 ) ;
}
static T_1 F_73 ( struct V_12 * V_13 )
{
T_1 V_47 ;
F_47 ( & V_13 -> V_74 ) ;
V_47 = F_68 ( & V_13 -> V_83 , V_88 ) ;
if ( V_47 == V_88 ) {
F_55 ( & V_13 -> V_74 ) ;
return V_76 ;
}
F_9 ( L_12 , V_77 + V_47 ) ;
F_65 ( V_47 , & V_13 -> V_83 ) ;
F_55 ( & V_13 -> V_74 ) ;
return V_77 + V_47 ;
}
static int F_74 ( struct V_12 * V_13 )
{
T_1 * V_89 , * V_90 , V_91 , V_92 ;
T_1 * V_93 , V_94 ;
T_1 * V_95 , V_96 ;
T_1 * V_97 , V_98 ;
T_4 V_67 = F_75 ( V_13 -> V_75 ) ;
T_1 V_99 = 0 ;
int V_100 = 0 ;
V_91 = V_101 ;
V_90 = F_76 ( V_102 , & V_91 ,
1 , & V_92 ) ;
V_99 += V_92 ;
V_93 = F_76 ( V_103 , & V_13 -> V_104 , 1 , & V_94 ) ;
V_99 += V_94 ;
F_9 ( L_13 , V_13 -> V_75 ) ;
V_95 = F_76 ( V_105 , ( T_1 * ) & V_67 , 2 , & V_96 ) ;
V_99 += V_96 ;
V_97 = F_76 ( V_106 , ( T_1 * ) & V_13 -> V_107 , 0 ,
& V_98 ) ;
V_99 += V_98 ;
V_99 += F_61 ( V_108 ) ;
if ( V_99 > V_109 ) {
V_100 = - V_66 ;
goto V_110;
}
V_89 = V_13 -> V_111 ;
memcpy ( V_89 , V_108 , F_61 ( V_108 ) ) ;
V_89 += F_61 ( V_108 ) ;
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
T_1 * F_77 ( struct V_62 * V_26 , T_2 * V_112 )
{
struct V_12 * V_13 ;
V_13 = F_58 ( V_26 ) ;
if ( V_13 == NULL ) {
* V_112 = 0 ;
return NULL ;
}
F_74 ( V_13 ) ;
* V_112 = V_13 -> V_99 ;
return V_13 -> V_111 ;
}
int F_78 ( struct V_62 * V_26 , T_1 * V_111 , T_1 V_99 )
{
struct V_12 * V_13 ;
if ( V_99 < 3 || V_99 > V_109 )
return - V_66 ;
V_13 = F_58 ( V_26 ) ;
if ( V_13 == NULL ) {
F_43 ( L_14 ) ;
return - V_113 ;
}
memset ( V_13 -> V_114 , 0 , V_109 ) ;
memcpy ( V_13 -> V_114 , V_111 , V_99 ) ;
V_13 -> V_115 = V_99 ;
if ( memcmp ( V_13 -> V_114 , V_108 , 3 ) ) {
F_43 ( L_15 ) ;
return - V_66 ;
}
return F_79 ( V_13 ,
& V_13 -> V_114 [ 3 ] ,
V_13 -> V_115 - 3 ) ;
}
static T_1 F_80 ( struct V_14 * V_116 )
{
return ( V_116 -> V_52 [ 0 ] & 0xfc ) >> 2 ;
}
static T_1 F_81 ( struct V_14 * V_116 )
{
return ( ( V_116 -> V_52 [ 0 ] & 0x03 ) << 2 ) | ( ( V_116 -> V_52 [ 1 ] & 0xc0 ) >> 6 ) ;
}
static T_1 F_82 ( struct V_14 * V_116 )
{
return V_116 -> V_52 [ 1 ] & 0x3f ;
}
static T_1 F_83 ( struct V_14 * V_116 )
{
return V_116 -> V_52 [ 2 ] >> 4 ;
}
static T_1 F_84 ( struct V_14 * V_116 )
{
return V_116 -> V_52 [ 2 ] & 0xf ;
}
static void F_85 ( struct V_7 * V_3 , struct V_14 * V_116 )
{
V_116 -> V_52 [ 2 ] = ( V_3 -> V_117 << 4 ) | ( V_3 -> V_118 ) ;
V_3 -> V_117 = ( V_3 -> V_117 + 1 ) % 16 ;
V_3 -> V_119 = ( V_3 -> V_118 - 1 ) % 16 ;
}
void F_86 ( struct V_12 * V_13 ,
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
V_122 = F_87 ( V_120 , V_124 ,
V_125 , true ) ;
if ( V_122 == NULL )
continue;
V_52 = F_88 ( V_122 , V_124 ) ;
V_52 [ 0 ] = V_13 -> V_26 ? V_13 -> V_26 -> V_126 : 0xFF ;
V_52 [ 1 ] = V_121 & 0x01 ;
V_52 [ 1 ] |= ( V_127 << 1 ) ;
}
V_123 = F_89 ( V_122 , V_125 ) ;
if ( ! V_123 )
continue;
if ( F_90 ( V_4 , V_123 ) )
F_13 ( V_123 ) ;
}
F_36 ( & V_13 -> V_34 . V_5 ) ;
F_13 ( V_122 ) ;
}
static void F_91 ( struct V_50 * V_51 )
{
struct V_12 * V_13 = F_28 ( V_51 , struct V_12 ,
V_38 ) ;
struct V_14 * V_120 ;
struct V_3 * V_4 ;
struct V_7 * V_22 ;
V_120 = F_92 ( & V_13 -> V_17 ) ;
if ( V_120 != NULL ) {
V_4 = V_120 -> V_4 ;
V_22 = V_7 ( V_4 ) ;
if ( V_22 == NULL && F_81 ( V_120 ) == V_128 ) {
F_13 ( V_120 ) ;
F_93 ( V_13 -> V_26 ) ;
} else if ( V_22 && ! V_22 -> V_129 ) {
F_94 ( & V_13 -> V_17 , V_120 ) ;
F_93 ( V_13 -> V_26 ) ;
} else {
struct V_14 * V_130 = NULL ;
T_1 V_131 = F_81 ( V_120 ) ;
int V_100 ;
F_9 ( L_16 ) ;
F_95 ( L_17 , V_132 ,
16 , 1 , V_120 -> V_52 , V_120 -> V_133 , true ) ;
if ( V_131 == V_134 && V_4 != NULL &&
V_4 -> V_24 == V_135 ) {
F_5 ( & V_13 -> V_23 , V_4 ) ;
F_96 ( V_4 ) ;
F_39 ( V_4 ) ;
}
if ( V_131 == V_128 )
V_130 = V_122 ( V_120 , V_125 ) ;
F_97 ( V_120 ) ;
F_86 ( V_13 , V_120 ,
V_136 ) ;
V_100 = F_98 ( V_13 -> V_26 , V_13 -> V_137 ,
V_120 , V_138 , V_13 ) ;
if ( V_100 ) {
F_13 ( V_130 ) ;
goto V_110;
}
if ( V_131 == V_128 && V_130 )
F_99 ( & V_22 -> V_18 ,
V_130 ) ;
}
} else {
F_93 ( V_13 -> V_26 ) ;
}
V_110:
F_54 ( & V_13 -> V_37 ,
V_57 + F_48 ( 2 * V_13 -> V_58 ) ) ;
}
static struct V_7 * F_100 ( struct V_12 * V_13 ,
T_1 V_47 )
{
struct V_3 * V_4 ;
struct V_7 * V_22 ;
F_34 ( & V_13 -> V_139 . V_5 ) ;
F_35 (sk, &local->connecting_sockets.head) {
V_22 = V_7 ( V_4 ) ;
if ( V_22 -> V_47 == V_47 ) {
F_37 ( & V_22 -> V_4 ) ;
goto V_110;
}
}
V_22 = NULL ;
V_110:
F_36 ( & V_13 -> V_139 . V_5 ) ;
return V_22 ;
}
static struct V_7 * F_101 ( struct V_12 * V_13 ,
T_1 * V_68 , T_2 V_69 )
{
struct V_7 * V_22 ;
V_22 = F_62 ( V_13 , V_68 , V_69 ) ;
if ( V_22 == NULL )
return NULL ;
F_37 ( & V_22 -> V_4 ) ;
return V_22 ;
}
static T_1 * F_102 ( struct V_14 * V_120 , T_2 * V_69 )
{
T_1 * V_140 = & V_120 -> V_52 [ 2 ] , type , V_141 ;
T_2 V_142 = V_120 -> V_133 - V_143 , V_144 = 0 ;
while ( V_144 < V_142 ) {
type = V_140 [ 0 ] ;
V_141 = V_140 [ 1 ] ;
F_9 ( L_18 , type , V_141 ) ;
if ( type == V_145 ) {
* V_69 = V_141 ;
return & V_140 [ 2 ] ;
}
V_144 += V_141 + 2 ;
V_140 += V_141 + 2 ;
}
return NULL ;
}
static void F_103 ( struct V_12 * V_13 ,
struct V_14 * V_120 )
{
struct V_7 * V_22 ;
struct V_146 * V_147 ;
T_1 V_48 , V_47 ;
V_48 = F_80 ( V_120 ) ;
V_47 = F_82 ( V_120 ) ;
V_147 = F_104 ( V_120 ) ;
V_147 -> V_48 = V_48 ;
V_147 -> V_47 = V_47 ;
F_9 ( L_19 , V_48 , V_47 ) ;
V_22 = F_33 ( V_13 , V_48 , V_86 ) ;
if ( V_22 == NULL || V_22 -> V_4 . V_70 != V_72 )
return;
F_105 ( V_120 , V_143 ) ;
if ( ! F_90 ( & V_22 -> V_4 , V_120 ) ) {
F_106 ( V_120 ) ;
} else {
F_43 ( L_20 ) ;
}
F_38 ( V_22 ) ;
}
static void F_107 ( struct V_12 * V_13 ,
struct V_14 * V_120 )
{
struct V_3 * V_148 , * V_149 ;
struct V_7 * V_3 , * V_150 ;
T_1 V_48 , V_47 , V_151 ;
V_48 = F_80 ( V_120 ) ;
V_47 = F_82 ( V_120 ) ;
F_9 ( L_19 , V_48 , V_47 ) ;
if ( V_48 != V_86 ) {
V_3 = F_33 ( V_13 , V_48 , V_86 ) ;
if ( V_3 == NULL || V_3 -> V_4 . V_24 != V_27 ) {
V_151 = V_152 ;
goto V_153;
}
} else {
T_1 * V_68 ;
T_2 V_69 ;
V_68 = F_102 ( V_120 , & V_69 ) ;
if ( V_68 == NULL ) {
V_151 = V_152 ;
goto V_153;
}
F_9 ( L_21 , V_69 ) ;
V_3 = F_101 ( V_13 , V_68 , V_69 ) ;
if ( V_3 == NULL ) {
V_151 = V_152 ;
goto V_153;
}
}
F_108 ( & V_3 -> V_4 ) ;
V_149 = & V_3 -> V_4 ;
if ( F_109 ( V_149 ) ) {
V_151 = V_154 ;
F_110 ( & V_3 -> V_4 ) ;
F_39 ( & V_3 -> V_4 ) ;
goto V_153;
}
if ( V_3 -> V_47 == V_60 ) {
T_1 V_47 = F_73 ( V_13 ) ;
F_9 ( L_22 , V_47 ) ;
if ( V_47 == V_76 ) {
V_151 = V_154 ;
F_110 ( & V_3 -> V_4 ) ;
F_39 ( & V_3 -> V_4 ) ;
goto V_153;
}
V_3 -> V_47 = V_47 ;
}
V_148 = F_111 ( NULL , V_149 -> V_70 , V_125 , 0 ) ;
if ( V_148 == NULL ) {
V_151 = V_154 ;
F_110 ( & V_3 -> V_4 ) ;
F_39 ( & V_3 -> V_4 ) ;
goto V_153;
}
V_150 = V_7 ( V_148 ) ;
V_150 -> V_26 = V_13 -> V_26 ;
V_150 -> V_13 = F_21 ( V_13 ) ;
V_150 -> V_155 = V_3 -> V_155 ;
V_150 -> V_107 = V_3 -> V_107 ;
V_150 -> V_156 = V_3 -> V_156 ;
V_150 -> V_48 = V_47 ;
V_150 -> V_137 = V_13 -> V_137 ;
V_150 -> V_149 = V_149 ;
V_150 -> V_47 = V_3 -> V_47 ;
if ( V_3 -> V_47 < V_80 && V_3 -> V_47 >= V_77 ) {
T_3 * V_157 ;
F_9 ( L_23 , V_3 -> V_47 , V_150 ) ;
V_157 =
& V_13 -> V_84 [ V_3 -> V_47 - V_77 ] ;
F_112 ( V_157 ) ;
V_150 -> V_158 = V_3 -> V_47 ;
}
F_113 ( V_150 , & V_120 -> V_52 [ V_143 ] ,
V_120 -> V_133 - V_143 ) ;
F_9 ( L_24 , V_150 , & V_150 -> V_4 ) ;
F_1 ( & V_13 -> V_23 , V_148 ) ;
F_114 ( & V_3 -> V_4 , V_148 ) ;
F_115 ( V_13 -> V_26 -> V_126 ) ;
V_148 -> V_24 = V_25 ;
V_149 -> V_159 ( V_149 ) ;
F_116 ( V_150 ) ;
F_110 ( & V_3 -> V_4 ) ;
F_39 ( & V_3 -> V_4 ) ;
return;
V_153:
F_117 ( V_13 , V_48 , V_47 , V_151 ) ;
}
int F_118 ( struct V_7 * V_3 )
{
int V_160 = 0 ;
struct V_12 * V_13 = V_3 -> V_13 ;
F_9 ( L_25 ,
V_3 -> V_129 , F_119 ( & V_3 -> V_18 ) ,
V_3 -> V_8 ) ;
while ( V_3 -> V_129 &&
F_119 ( & V_3 -> V_18 ) < V_3 -> V_8 ) {
struct V_14 * V_116 ;
V_116 = F_92 ( & V_3 -> V_17 ) ;
if ( V_116 == NULL )
break;
F_85 ( V_3 , V_116 ) ;
F_99 ( & V_13 -> V_17 , V_116 ) ;
V_160 ++ ;
}
return V_160 ;
}
static void F_120 ( struct V_12 * V_13 ,
struct V_14 * V_120 )
{
struct V_7 * V_22 ;
struct V_3 * V_4 ;
T_1 V_48 , V_47 , V_131 , V_161 , V_162 ;
V_131 = F_81 ( V_120 ) ;
V_48 = F_80 ( V_120 ) ;
V_47 = F_82 ( V_120 ) ;
V_161 = F_83 ( V_120 ) ;
V_162 = F_84 ( V_120 ) ;
F_9 ( L_26 , V_48 , V_47 , V_162 , V_161 ) ;
V_22 = F_33 ( V_13 , V_48 , V_47 ) ;
if ( V_22 == NULL ) {
F_117 ( V_13 , V_48 , V_47 , V_163 ) ;
return;
}
V_4 = & V_22 -> V_4 ;
F_108 ( V_4 ) ;
if ( V_4 -> V_24 == V_32 ) {
F_110 ( V_4 ) ;
F_38 ( V_22 ) ;
}
if ( V_131 == V_128 ) {
F_9 ( L_27 , & V_22 -> V_4 ) ;
if ( V_161 == V_22 -> V_118 )
V_22 -> V_118 = ( V_22 -> V_118 + 1 ) % 16 ;
else
F_43 ( L_28 ) ;
F_105 ( V_120 , V_143 + V_164 ) ;
if ( ! F_90 ( & V_22 -> V_4 , V_120 ) ) {
F_106 ( V_120 ) ;
} else {
F_43 ( L_20 ) ;
}
}
if ( V_22 -> V_165 != V_162 ) {
struct V_14 * V_15 , * V_16 ;
T_1 V_29 ;
V_22 -> V_165 = V_162 ;
F_11 (&llcp_sock->tx_pending_queue, s, tmp) {
V_29 = F_83 ( V_15 ) ;
F_12 ( V_15 , & V_22 -> V_18 ) ;
F_13 ( V_15 ) ;
if ( V_29 == V_162 )
break;
}
F_121 (&llcp_sock->tx_pending_queue,
s, tmp) {
F_12 ( V_15 , & V_22 -> V_18 ) ;
F_94 ( & V_13 -> V_17 , V_15 ) ;
}
}
if ( V_131 == V_166 )
V_22 -> V_129 = true ;
else if ( V_131 == V_167 )
V_22 -> V_129 = false ;
if ( F_118 ( V_22 ) == 0 && V_131 == V_128 )
F_122 ( V_22 ) ;
F_110 ( V_4 ) ;
F_38 ( V_22 ) ;
}
static void F_123 ( struct V_12 * V_13 ,
struct V_14 * V_120 )
{
struct V_7 * V_22 ;
struct V_3 * V_4 ;
T_1 V_48 , V_47 ;
V_48 = F_80 ( V_120 ) ;
V_47 = F_82 ( V_120 ) ;
if ( ( V_48 == 0 ) && ( V_47 == 0 ) ) {
F_9 ( L_29 ) ;
F_41 ( V_13 -> V_26 ) ;
return;
}
V_22 = F_33 ( V_13 , V_48 , V_47 ) ;
if ( V_22 == NULL ) {
F_117 ( V_13 , V_48 , V_47 , V_163 ) ;
return;
}
V_4 = & V_22 -> V_4 ;
F_108 ( V_4 ) ;
F_8 ( V_22 ) ;
if ( V_4 -> V_24 == V_32 ) {
F_110 ( V_4 ) ;
F_38 ( V_22 ) ;
}
if ( V_4 -> V_24 == V_25 ) {
F_17 ( V_13 -> V_26 ) ;
V_4 -> V_24 = V_32 ;
V_4 -> V_33 ( V_4 ) ;
}
F_117 ( V_13 , V_48 , V_47 , V_168 ) ;
F_110 ( V_4 ) ;
F_38 ( V_22 ) ;
}
static void F_124 ( struct V_12 * V_13 , struct V_14 * V_120 )
{
struct V_7 * V_22 ;
struct V_3 * V_4 ;
T_1 V_48 , V_47 ;
V_48 = F_80 ( V_120 ) ;
V_47 = F_82 ( V_120 ) ;
V_22 = F_100 ( V_13 , V_48 ) ;
if ( V_22 == NULL ) {
F_43 ( L_30 ) ;
F_117 ( V_13 , V_48 , V_47 , V_163 ) ;
return;
}
V_4 = & V_22 -> V_4 ;
F_5 ( & V_13 -> V_139 , V_4 ) ;
F_1 ( & V_13 -> V_23 , V_4 ) ;
V_22 -> V_48 = V_47 ;
F_113 ( V_22 , & V_120 -> V_52 [ V_143 ] ,
V_120 -> V_133 - V_143 ) ;
V_4 -> V_24 = V_25 ;
V_4 -> V_33 ( V_4 ) ;
F_38 ( V_22 ) ;
}
static void F_125 ( struct V_12 * V_13 , struct V_14 * V_120 )
{
struct V_7 * V_22 ;
struct V_3 * V_4 ;
T_1 V_48 , V_47 , V_151 ;
V_48 = F_80 ( V_120 ) ;
V_47 = F_82 ( V_120 ) ;
V_151 = V_120 -> V_52 [ 2 ] ;
F_9 ( L_31 , V_47 , V_48 , V_151 ) ;
switch ( V_151 ) {
case V_152 :
case V_154 :
V_22 = F_100 ( V_13 , V_48 ) ;
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
static void F_126 ( struct V_12 * V_13 ,
struct V_14 * V_120 )
{
struct V_7 * V_22 ;
T_1 V_48 , V_47 , * V_140 , type , V_141 , V_169 , V_59 ;
T_5 V_170 , V_144 ;
char * V_63 ;
T_2 V_64 ;
struct V_54 * V_55 ;
F_46 ( V_171 ) ;
T_2 V_172 ;
F_46 ( V_53 ) ;
V_48 = F_80 ( V_120 ) ;
V_47 = F_82 ( V_120 ) ;
F_9 ( L_19 , V_48 , V_47 ) ;
if ( V_48 != V_86 || V_47 != V_86 ) {
F_43 ( L_33 ) ;
return;
}
V_140 = & V_120 -> V_52 [ V_143 ] ;
V_170 = V_120 -> V_133 - V_143 ;
V_144 = 0 ;
V_172 = 0 ;
while ( V_144 < V_170 ) {
type = V_140 [ 0 ] ;
V_141 = V_140 [ 1 ] ;
switch ( type ) {
case V_173 :
V_169 = V_140 [ 2 ] ;
V_63 = ( char * ) & V_140 [ 3 ] ;
V_64 = V_141 - 1 ;
F_9 ( L_34 , V_63 ) ;
if ( V_64 == strlen ( L_35 ) &&
! strncmp ( V_63 , L_35 ,
V_64 ) ) {
V_59 = 1 ;
goto V_174;
}
V_22 = F_62 ( V_13 , V_63 ,
V_64 ) ;
if ( ! V_22 ) {
V_59 = 0 ;
goto V_174;
}
if ( V_22 -> V_47 == V_60 ) {
T_3 * V_157 ;
V_59 = F_73 ( V_13 ) ;
F_9 ( L_36 , V_59 ) ;
if ( V_59 == V_76 ) {
V_59 = 0 ;
goto V_174;
}
V_157 =
& V_13 -> V_84 [ V_59 -
V_77 ] ;
F_112 ( V_157 ) ;
V_22 -> V_47 = V_59 ;
V_22 -> V_158 = V_59 ;
} else {
V_59 = V_22 -> V_47 ;
}
F_9 ( L_37 , V_22 , V_59 ) ;
V_174:
V_55 = F_127 ( V_169 , V_59 ) ;
if ( V_55 == NULL )
goto exit;
V_172 += V_55 -> V_170 ;
F_52 ( & V_55 -> V_61 , & V_171 ) ;
break;
case V_175 :
F_47 ( & V_13 -> V_56 ) ;
F_9 ( L_38 , V_140 [ 2 ] ) ;
F_128 (sdp, &local->pending_sdreqs, node) {
if ( V_55 -> V_169 != V_140 [ 2 ] )
continue;
V_55 -> V_59 = V_140 [ 3 ] ;
F_9 ( L_39 ,
V_55 -> V_176 , V_55 -> V_59 ) ;
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
V_144 += V_141 + 2 ;
V_140 += V_141 + 2 ;
}
exit:
if ( ! F_53 ( & V_53 ) )
F_56 ( V_13 -> V_26 , & V_53 ) ;
if ( ! F_53 ( & V_171 ) )
F_129 ( V_13 , & V_171 , V_172 ) ;
}
static void F_130 ( struct V_12 * V_13 , struct V_14 * V_120 )
{
T_1 V_131 ;
T_5 V_177 ;
struct V_14 * V_178 ;
if ( V_120 -> V_133 <= V_143 ) {
F_43 ( L_41 ) ;
return;
}
F_105 ( V_120 , V_143 ) ;
while ( V_120 -> V_133 > V_179 ) {
V_177 = V_120 -> V_52 [ 0 ] << 8 | V_120 -> V_52 [ 1 ] ;
F_105 ( V_120 , V_179 ) ;
if ( V_177 < V_143 || V_177 > V_120 -> V_133 ) {
F_43 ( L_41 ) ;
return;
}
V_131 = F_81 ( V_120 ) ;
if ( V_131 == V_180 || V_131 == V_181 )
goto V_182;
V_178 = F_131 ( V_177 , V_183 ) ;
if ( V_178 == NULL ) {
F_43 ( L_42 ) ;
return;
}
memcpy ( F_132 ( V_178 , V_177 ) , V_120 -> V_52 , V_177 ) ;
F_133 ( V_13 , V_178 ) ;
F_13 ( V_178 ) ;
V_182:
F_105 ( V_120 , V_177 ) ;
}
}
static void F_133 ( struct V_12 * V_13 , struct V_14 * V_120 )
{
T_1 V_48 , V_47 , V_131 ;
V_131 = F_81 ( V_120 ) ;
V_48 = F_80 ( V_120 ) ;
V_47 = F_82 ( V_120 ) ;
F_9 ( L_43 , V_131 , V_48 , V_47 ) ;
if ( V_131 != V_180 )
F_95 ( L_44 , V_132 , 16 , 1 ,
V_120 -> V_52 , V_120 -> V_133 , true ) ;
switch ( V_131 ) {
case V_180 :
F_9 ( L_45 ) ;
break;
case V_184 :
F_9 ( L_46 ) ;
F_103 ( V_13 , V_120 ) ;
break;
case V_185 :
F_9 ( L_47 ) ;
F_107 ( V_13 , V_120 ) ;
break;
case V_134 :
F_9 ( L_48 ) ;
F_123 ( V_13 , V_120 ) ;
break;
case V_186 :
F_9 ( L_49 ) ;
F_124 ( V_13 , V_120 ) ;
break;
case V_187 :
F_9 ( L_50 ) ;
F_125 ( V_13 , V_120 ) ;
break;
case V_188 :
F_9 ( L_51 ) ;
F_126 ( V_13 , V_120 ) ;
break;
case V_128 :
case V_166 :
case V_167 :
F_9 ( L_52 ) ;
F_120 ( V_13 , V_120 ) ;
break;
case V_181 :
F_9 ( L_53 ) ;
F_130 ( V_13 , V_120 ) ;
break;
}
}
static void F_134 ( struct V_50 * V_51 )
{
struct V_12 * V_13 = F_28 ( V_51 , struct V_12 ,
V_39 ) ;
struct V_14 * V_120 ;
V_120 = V_13 -> V_41 ;
if ( V_120 == NULL ) {
F_9 ( L_54 ) ;
return;
}
F_97 ( V_120 ) ;
F_86 ( V_13 , V_120 , V_189 ) ;
F_133 ( V_13 , V_120 ) ;
F_44 ( & V_13 -> V_38 ) ;
F_13 ( V_13 -> V_41 ) ;
V_13 -> V_41 = NULL ;
}
static void F_135 ( struct V_12 * V_13 , struct V_14 * V_120 )
{
V_13 -> V_41 = V_120 ;
F_136 ( & V_13 -> V_37 ) ;
F_44 ( & V_13 -> V_39 ) ;
}
void V_138 ( void * V_52 , struct V_14 * V_120 , int V_20 )
{
struct V_12 * V_13 = (struct V_12 * ) V_52 ;
F_9 ( L_55 ) ;
if ( V_20 < 0 ) {
F_43 ( L_56 , V_20 ) ;
return;
}
F_135 ( V_13 , V_120 ) ;
}
int F_137 ( struct V_62 * V_26 , struct V_14 * V_120 )
{
struct V_12 * V_13 ;
V_13 = F_58 ( V_26 ) ;
if ( V_13 == NULL ) {
F_13 ( V_120 ) ;
return - V_113 ;
}
F_135 ( V_13 , V_120 ) ;
return 0 ;
}
void F_138 ( struct V_62 * V_26 )
{
struct V_12 * V_13 ;
V_13 = F_58 ( V_26 ) ;
if ( V_13 == NULL )
return;
V_13 -> V_10 = V_190 ;
V_13 -> V_58 = V_191 ;
F_14 ( V_13 , true , 0 ) ;
}
void F_139 ( struct V_62 * V_26 , T_6 V_137 ,
T_1 V_192 , T_1 V_193 )
{
struct V_12 * V_13 ;
F_9 ( L_57 , V_193 ) ;
V_13 = F_58 ( V_26 ) ;
if ( V_13 == NULL )
return;
V_13 -> V_137 = V_137 ;
V_13 -> V_192 = V_192 ;
V_13 -> V_193 = V_193 ;
if ( V_193 == V_194 ) {
F_9 ( L_58 ) ;
F_44 ( & V_13 -> V_38 ) ;
} else {
F_54 ( & V_13 -> V_37 ,
V_57 + F_48 ( V_13 -> V_58 ) ) ;
}
}
int F_140 ( struct V_62 * V_195 )
{
struct V_12 * V_13 ;
V_13 = F_141 ( sizeof( struct V_12 ) , V_183 ) ;
if ( V_13 == NULL )
return - V_196 ;
V_13 -> V_26 = V_195 ;
F_142 ( & V_13 -> V_46 ) ;
F_143 ( & V_13 -> V_35 ) ;
F_144 ( & V_13 -> V_74 ) ;
F_145 ( & V_13 -> V_37 ) ;
V_13 -> V_37 . V_52 = ( unsigned long ) V_13 ;
V_13 -> V_37 . V_197 = F_42 ;
F_146 ( & V_13 -> V_17 ) ;
F_147 ( & V_13 -> V_38 , F_91 ) ;
V_13 -> V_41 = NULL ;
F_147 ( & V_13 -> V_39 , F_134 ) ;
F_147 ( & V_13 -> V_40 , F_40 ) ;
F_148 ( & V_13 -> V_23 . V_5 ) ;
F_148 ( & V_13 -> V_139 . V_5 ) ;
F_148 ( & V_13 -> V_34 . V_5 ) ;
V_13 -> V_104 = 150 ;
V_13 -> V_155 = V_198 ;
V_13 -> V_107 = F_75 ( V_199 ) ;
V_13 -> V_75 = 0x1 ;
F_74 ( V_13 ) ;
V_13 -> V_10 = V_190 ;
V_13 -> V_58 = V_191 ;
F_144 ( & V_13 -> V_56 ) ;
F_149 ( & V_13 -> V_44 ) ;
F_145 ( & V_13 -> V_42 ) ;
V_13 -> V_42 . V_52 = ( unsigned long ) V_13 ;
V_13 -> V_42 . V_197 = F_57 ;
F_147 ( & V_13 -> V_43 , F_45 ) ;
F_150 ( & V_13 -> V_46 , & V_200 ) ;
return 0 ;
}
void F_151 ( struct V_62 * V_26 )
{
struct V_12 * V_13 = F_58 ( V_26 ) ;
if ( V_13 == NULL ) {
F_9 ( L_59 ) ;
return;
}
F_23 ( V_13 ) ;
F_31 ( V_13 ) ;
}
int T_7 F_152 ( void )
{
return F_153 () ;
}
void F_154 ( void )
{
F_155 () ;
}
