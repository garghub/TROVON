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
static void F_7 ( struct V_7 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_10 * V_11 , * V_12 ;
F_8 ( L_1 , & V_3 -> V_4 ) ;
F_9 ( & V_3 -> V_13 ) ;
F_9 ( & V_3 -> V_14 ) ;
F_9 ( & V_3 -> V_15 ) ;
if ( V_9 == NULL )
return;
F_10 (&local->tx_queue, s, tmp) {
if ( V_11 -> V_4 != & V_3 -> V_4 )
continue;
F_11 ( V_11 , & V_9 -> V_13 ) ;
F_12 ( V_11 ) ;
}
}
static void F_13 ( struct V_8 * V_9 , bool V_16 )
{
struct V_3 * V_4 ;
struct V_17 * V_18 , * V_12 ;
struct V_7 * V_19 ;
F_9 ( & V_9 -> V_13 ) ;
F_2 ( & V_9 -> V_20 . V_5 ) ;
F_14 (sk, node, tmp, &local->sockets.head) {
V_19 = V_7 ( V_4 ) ;
F_15 ( V_4 ) ;
F_7 ( V_19 ) ;
if ( V_4 -> V_21 == V_22 )
F_16 ( V_19 -> V_23 ) ;
if ( V_4 -> V_21 == V_24 ) {
struct V_7 * V_25 , * V_26 ;
struct V_3 * V_27 ;
F_17 (lsk, n,
&llcp_sock->accept_queue,
accept_queue) {
V_27 = & V_25 -> V_4 ;
F_15 ( V_27 ) ;
F_18 ( V_27 ) ;
V_27 -> V_21 = V_28 ;
F_19 ( V_27 ) ;
F_20 ( V_27 ) ;
}
if ( V_16 == true ) {
F_19 ( V_4 ) ;
continue;
}
}
if ( V_4 -> V_21 == V_29 && V_4 -> V_30 == V_31 &&
V_16 == true ) {
F_19 ( V_4 ) ;
continue;
}
V_4 -> V_21 = V_28 ;
F_19 ( V_4 ) ;
F_20 ( V_4 ) ;
F_6 ( V_4 ) ;
}
F_4 ( & V_9 -> V_20 . V_5 ) ;
}
struct V_8 * F_21 ( struct V_8 * V_9 )
{
F_22 ( & V_9 -> V_32 ) ;
return V_9 ;
}
static void F_23 ( struct V_33 * V_32 )
{
struct V_8 * V_9 ;
V_9 = F_24 ( V_32 , struct V_8 , V_32 ) ;
F_25 ( & V_9 -> V_34 ) ;
F_13 ( V_9 , false ) ;
F_26 ( & V_9 -> V_35 ) ;
F_9 ( & V_9 -> V_13 ) ;
F_27 ( & V_9 -> V_36 ) ;
F_27 ( & V_9 -> V_37 ) ;
F_27 ( & V_9 -> V_38 ) ;
F_12 ( V_9 -> V_39 ) ;
F_28 ( V_9 ) ;
}
int F_29 ( struct V_8 * V_9 )
{
if ( V_9 == NULL )
return 0 ;
return F_30 ( & V_9 -> V_32 , F_23 ) ;
}
static struct V_7 * F_31 ( struct V_8 * V_9 ,
T_1 V_40 , T_1 V_41 )
{
struct V_3 * V_4 ;
struct V_17 * V_18 ;
struct V_7 * V_19 , * V_42 ;
F_8 ( L_2 , V_40 , V_41 ) ;
if ( V_40 == 0 && V_41 == 0 )
return NULL ;
F_32 ( & V_9 -> V_20 . V_5 ) ;
V_19 = NULL ;
F_33 (sk, node, &local->sockets.head) {
V_42 = V_7 ( V_4 ) ;
if ( V_42 -> V_40 == V_40 && V_42 -> V_41 == V_41 ) {
V_19 = V_42 ;
break;
}
}
F_34 ( & V_9 -> V_20 . V_5 ) ;
if ( V_19 == NULL )
return NULL ;
F_35 ( & V_19 -> V_4 ) ;
return V_19 ;
}
static void F_36 ( struct V_7 * V_3 )
{
F_37 ( & V_3 -> V_4 ) ;
}
static void F_38 ( struct V_43 * V_44 )
{
struct V_8 * V_9 = F_24 ( V_44 , struct V_8 ,
V_38 ) ;
F_39 ( V_9 -> V_23 ) ;
}
static void F_40 ( unsigned long V_45 )
{
struct V_8 * V_9 = (struct V_8 * ) V_45 ;
F_41 ( L_3 ) ;
F_42 ( & V_9 -> V_38 ) ;
}
struct V_8 * F_43 ( struct V_46 * V_23 )
{
struct V_8 * V_9 , * V_26 ;
F_17 (local, n, &llcp_devices, list)
if ( V_9 -> V_23 == V_23 )
return V_9 ;
F_8 ( L_4 ) ;
return NULL ;
}
static int F_44 ( char * V_47 , T_2 V_48 )
{
int V_49 , V_50 ;
F_8 ( L_5 , V_47 ) ;
if ( V_47 == NULL )
return - V_51 ;
V_50 = F_45 ( V_52 ) ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
if ( V_52 [ V_49 ] == NULL )
continue;
if ( strncmp ( V_52 [ V_49 ] , V_47 , V_48 ) == 0 )
return V_49 ;
}
return - V_51 ;
}
static
struct V_7 * F_46 ( struct V_8 * V_9 ,
T_1 * V_53 , T_2 V_54 )
{
struct V_3 * V_4 ;
struct V_17 * V_18 ;
struct V_7 * V_19 , * V_42 ;
F_8 ( L_6 , V_54 , V_53 ) ;
if ( V_53 == NULL || V_54 == 0 )
return NULL ;
F_32 ( & V_9 -> V_20 . V_5 ) ;
V_19 = NULL ;
F_33 (sk, node, &local->sockets.head) {
V_42 = V_7 ( V_4 ) ;
F_8 ( L_7 , V_42 ) ;
if ( V_42 -> V_4 . V_30 == V_55 &&
V_42 -> V_4 . V_21 != V_24 )
continue;
if ( V_42 -> V_4 . V_30 == V_31 &&
V_42 -> V_4 . V_21 != V_29 )
continue;
if ( V_42 -> V_47 == NULL ||
V_42 -> V_48 == 0 )
continue;
if ( V_42 -> V_48 != V_54 )
continue;
if ( memcmp ( V_53 , V_42 -> V_47 , V_54 ) == 0 ) {
V_19 = V_42 ;
break;
}
}
F_34 ( & V_9 -> V_20 . V_5 ) ;
F_8 ( L_8 , V_19 ) ;
return V_19 ;
}
T_1 F_47 ( struct V_8 * V_9 ,
struct V_7 * V_3 )
{
F_48 ( & V_9 -> V_56 ) ;
if ( V_3 -> V_47 != NULL && V_3 -> V_48 > 0 ) {
int V_40 = F_44 ( V_3 -> V_47 ,
V_3 -> V_48 ) ;
if ( V_40 > 0 ) {
F_8 ( L_9 , V_40 ) ;
if ( V_9 -> V_57 & F_49 ( V_40 ) ) {
F_50 ( & V_9 -> V_56 ) ;
return V_58 ;
}
F_51 ( V_40 , & V_9 -> V_57 ) ;
F_50 ( & V_9 -> V_56 ) ;
return V_40 ;
}
if ( F_46 ( V_9 , V_3 -> V_47 ,
V_3 -> V_48 ) != NULL ) {
F_50 ( & V_9 -> V_56 ) ;
return V_58 ;
}
F_50 ( & V_9 -> V_56 ) ;
return V_59 ;
} else if ( V_3 -> V_40 != 0 && V_3 -> V_40 < V_60 ) {
if ( ! F_52 ( V_3 -> V_40 , & V_9 -> V_57 ) ) {
F_51 ( V_3 -> V_40 , & V_9 -> V_57 ) ;
F_50 ( & V_9 -> V_56 ) ;
return V_3 -> V_40 ;
}
}
F_50 ( & V_9 -> V_56 ) ;
return V_58 ;
}
T_1 F_53 ( struct V_8 * V_9 )
{
T_1 V_61 ;
F_48 ( & V_9 -> V_56 ) ;
V_61 = F_54 ( & V_9 -> V_62 , V_63 ) ;
if ( V_61 == V_63 ) {
F_50 ( & V_9 -> V_56 ) ;
return V_58 ;
}
F_51 ( V_61 , & V_9 -> V_62 ) ;
F_50 ( & V_9 -> V_56 ) ;
return V_61 + V_64 ;
}
void F_55 ( struct V_8 * V_9 , T_1 V_40 )
{
T_1 V_61 ;
unsigned long * V_65 ;
if ( V_40 < V_60 ) {
V_61 = V_40 ;
V_65 = & V_9 -> V_57 ;
} else if ( V_40 < V_63 ) {
T_3 * V_66 ;
V_61 = V_40 - V_60 ;
V_65 = & V_9 -> V_67 ;
V_66 = & V_9 -> V_68 [ V_61 ] ;
F_8 ( L_10 , F_56 ( V_66 ) ) ;
F_48 ( & V_9 -> V_56 ) ;
if ( F_57 ( V_66 ) ) {
struct V_7 * V_69 ;
F_8 ( L_11 , V_40 ) ;
F_58 ( V_61 , V_65 ) ;
V_69 = F_31 ( V_9 , V_40 , V_70 ) ;
if ( V_69 ) {
V_69 -> V_40 = V_59 ;
F_36 ( V_69 ) ;
}
}
F_50 ( & V_9 -> V_56 ) ;
return;
} else if ( V_40 < V_71 ) {
V_61 = V_40 - V_63 ;
V_65 = & V_9 -> V_62 ;
} else {
return;
}
F_48 ( & V_9 -> V_56 ) ;
F_58 ( V_61 , V_65 ) ;
F_50 ( & V_9 -> V_56 ) ;
}
static T_1 F_59 ( struct V_8 * V_9 )
{
T_1 V_40 ;
F_48 ( & V_9 -> V_56 ) ;
V_40 = F_54 ( & V_9 -> V_67 , V_72 ) ;
if ( V_40 == V_72 ) {
F_50 ( & V_9 -> V_56 ) ;
return V_58 ;
}
F_8 ( L_12 , V_60 + V_40 ) ;
F_51 ( V_40 , & V_9 -> V_67 ) ;
F_50 ( & V_9 -> V_56 ) ;
return V_60 + V_40 ;
}
static int F_60 ( struct V_8 * V_9 )
{
T_1 * V_73 , * V_74 , V_75 , V_76 ;
T_1 * V_77 , V_78 ;
T_1 * V_79 , V_80 ;
T_1 * V_81 , V_82 ;
T_1 V_83 = 0 ;
int V_84 = 0 ;
V_75 = V_85 ;
V_74 = F_61 ( V_86 , & V_75 ,
1 , & V_76 ) ;
V_83 += V_76 ;
V_77 = F_61 ( V_87 , & V_9 -> V_88 , 1 , & V_78 ) ;
V_83 += V_78 ;
F_8 ( L_13 , V_9 -> V_57 ) ;
V_79 = F_61 ( V_89 , ( T_1 * ) & V_9 -> V_57 , 2 ,
& V_80 ) ;
V_83 += V_80 ;
V_81 = F_61 ( V_90 , ( T_1 * ) & V_9 -> V_91 , 0 ,
& V_82 ) ;
V_83 += V_82 ;
V_83 += F_45 ( V_92 ) ;
if ( V_83 > V_93 ) {
V_84 = - V_51 ;
goto V_94;
}
V_73 = V_9 -> V_95 ;
memcpy ( V_73 , V_92 , F_45 ( V_92 ) ) ;
V_73 += F_45 ( V_92 ) ;
memcpy ( V_73 , V_74 , V_76 ) ;
V_73 += V_76 ;
memcpy ( V_73 , V_77 , V_78 ) ;
V_73 += V_78 ;
memcpy ( V_73 , V_79 , V_80 ) ;
V_73 += V_80 ;
memcpy ( V_73 , V_81 , V_82 ) ;
V_73 += V_82 ;
V_9 -> V_83 = V_83 ;
V_94:
F_28 ( V_74 ) ;
F_28 ( V_77 ) ;
F_28 ( V_79 ) ;
F_28 ( V_81 ) ;
return V_84 ;
}
T_1 * F_62 ( struct V_46 * V_23 , T_2 * V_96 )
{
struct V_8 * V_9 ;
V_9 = F_43 ( V_23 ) ;
if ( V_9 == NULL ) {
* V_96 = 0 ;
return NULL ;
}
F_60 ( V_9 ) ;
* V_96 = V_9 -> V_83 ;
return V_9 -> V_95 ;
}
int F_63 ( struct V_46 * V_23 , T_1 * V_95 , T_1 V_83 )
{
struct V_8 * V_9 = F_43 ( V_23 ) ;
if ( V_9 == NULL ) {
F_41 ( L_14 ) ;
return - V_97 ;
}
memset ( V_9 -> V_98 , 0 , V_93 ) ;
memcpy ( V_9 -> V_98 , V_95 , V_83 ) ;
V_9 -> V_99 = V_83 ;
if ( V_9 -> V_98 == NULL || V_9 -> V_99 == 0 )
return - V_97 ;
if ( memcmp ( V_9 -> V_98 , V_92 , 3 ) ) {
F_41 ( L_15 ) ;
return - V_51 ;
}
return F_64 ( V_9 ,
& V_9 -> V_98 [ 3 ] ,
V_9 -> V_99 - 3 ) ;
}
static T_1 F_65 ( struct V_10 * V_100 )
{
return ( V_100 -> V_45 [ 0 ] & 0xfc ) >> 2 ;
}
static T_1 F_66 ( struct V_10 * V_100 )
{
return ( ( V_100 -> V_45 [ 0 ] & 0x03 ) << 2 ) | ( ( V_100 -> V_45 [ 1 ] & 0xc0 ) >> 6 ) ;
}
static T_1 F_67 ( struct V_10 * V_100 )
{
return V_100 -> V_45 [ 1 ] & 0x3f ;
}
static T_1 F_68 ( struct V_10 * V_100 )
{
return V_100 -> V_45 [ 2 ] >> 4 ;
}
static T_1 F_69 ( struct V_10 * V_100 )
{
return V_100 -> V_45 [ 2 ] & 0xf ;
}
static void F_70 ( struct V_7 * V_3 , struct V_10 * V_100 )
{
V_100 -> V_45 [ 2 ] = ( V_3 -> V_101 << 4 ) | ( V_3 -> V_102 ) ;
V_3 -> V_101 = ( V_3 -> V_101 + 1 ) % 16 ;
V_3 -> V_103 = ( V_3 -> V_102 - 1 ) % 16 ;
}
void F_71 ( struct V_8 * V_9 ,
struct V_10 * V_104 , T_1 V_105 )
{
struct V_17 * V_18 ;
struct V_10 * V_106 = NULL , * V_107 ;
struct V_3 * V_4 ;
T_1 * V_45 ;
F_32 ( & V_9 -> V_108 . V_5 ) ;
F_33 (sk, node, &local->raw_sockets.head) {
if ( V_4 -> V_21 != V_29 )
continue;
if ( V_106 == NULL ) {
V_106 = F_72 ( V_104 , V_109 ,
V_110 ) ;
if ( V_106 == NULL )
continue;
V_45 = F_73 ( V_106 , V_109 ) ;
V_45 [ 0 ] = V_9 -> V_23 ? V_9 -> V_23 -> V_111 : 0xFF ;
V_45 [ 1 ] = V_105 ;
}
V_107 = F_74 ( V_106 , V_110 ) ;
if ( ! V_107 )
continue;
if ( F_75 ( V_4 , V_107 ) )
F_12 ( V_107 ) ;
}
F_34 ( & V_9 -> V_108 . V_5 ) ;
F_12 ( V_106 ) ;
}
static void F_76 ( struct V_43 * V_44 )
{
struct V_8 * V_9 = F_24 ( V_44 , struct V_8 ,
V_36 ) ;
struct V_10 * V_104 ;
struct V_3 * V_4 ;
struct V_7 * V_19 ;
V_104 = F_77 ( & V_9 -> V_13 ) ;
if ( V_104 != NULL ) {
V_4 = V_104 -> V_4 ;
V_19 = V_7 ( V_4 ) ;
if ( V_19 == NULL && F_66 ( V_104 ) == V_112 ) {
F_78 ( V_9 -> V_23 ) ;
} else {
struct V_10 * V_113 = NULL ;
T_1 V_114 = F_66 ( V_104 ) ;
int V_84 ;
F_8 ( L_16 ) ;
F_79 ( V_115 , L_17 ,
V_116 , 16 , 1 ,
V_104 -> V_45 , V_104 -> V_117 , true ) ;
if ( V_114 == V_112 )
V_113 = V_106 ( V_104 , V_110 ) ;
F_71 ( V_9 , V_104 ,
V_118 ) ;
V_84 = F_80 ( V_9 -> V_23 , V_9 -> V_119 ,
V_104 , V_120 , V_9 ) ;
if ( V_84 ) {
F_12 ( V_113 ) ;
goto V_94;
}
if ( V_114 == V_112 && V_113 )
F_81 ( & V_19 -> V_14 ,
V_113 ) ;
}
} else {
F_78 ( V_9 -> V_23 ) ;
}
V_94:
F_82 ( & V_9 -> V_35 ,
V_121 + F_83 ( 2 * V_9 -> V_122 ) ) ;
}
static struct V_7 * F_84 ( struct V_8 * V_9 ,
T_1 V_40 )
{
struct V_3 * V_4 ;
struct V_7 * V_19 ;
struct V_17 * V_18 ;
F_32 ( & V_9 -> V_123 . V_5 ) ;
F_33 (sk, node, &local->connecting_sockets.head) {
V_19 = V_7 ( V_4 ) ;
if ( V_19 -> V_40 == V_40 ) {
F_35 ( & V_19 -> V_4 ) ;
goto V_94;
}
}
V_19 = NULL ;
V_94:
F_34 ( & V_9 -> V_123 . V_5 ) ;
return V_19 ;
}
static struct V_7 * F_85 ( struct V_8 * V_9 ,
T_1 * V_53 , T_2 V_54 )
{
struct V_7 * V_19 ;
V_19 = F_46 ( V_9 , V_53 , V_54 ) ;
if ( V_19 == NULL )
return NULL ;
F_35 ( & V_19 -> V_4 ) ;
return V_19 ;
}
static T_1 * F_86 ( struct V_10 * V_104 , T_2 * V_54 )
{
T_1 * V_124 = & V_104 -> V_45 [ 2 ] , type , V_125 ;
T_2 V_126 = V_104 -> V_117 - V_127 , V_128 = 0 ;
while ( V_128 < V_126 ) {
type = V_124 [ 0 ] ;
V_125 = V_124 [ 1 ] ;
F_8 ( L_18 , type , V_125 ) ;
if ( type == V_129 ) {
* V_54 = V_125 ;
return & V_124 [ 2 ] ;
}
V_128 += V_125 + 2 ;
V_124 += V_125 + 2 ;
}
return NULL ;
}
static void F_87 ( struct V_8 * V_9 ,
struct V_10 * V_104 )
{
struct V_7 * V_19 ;
struct V_130 * V_131 ;
T_1 V_41 , V_40 ;
V_41 = F_65 ( V_104 ) ;
V_40 = F_67 ( V_104 ) ;
V_131 = F_88 ( V_104 ) ;
V_131 -> V_41 = V_41 ;
V_131 -> V_40 = V_40 ;
F_89 ( L_19 , V_132 , V_41 , V_40 ) ;
F_8 ( L_20 , V_41 , V_40 ) ;
V_19 = F_31 ( V_9 , V_41 , V_70 ) ;
if ( V_19 == NULL || V_19 -> V_4 . V_30 != V_31 )
return;
F_90 ( V_104 , V_127 ) ;
if ( F_75 ( & V_19 -> V_4 , V_104 ) ) {
F_41 ( L_21 ) ;
F_91 ( & V_19 -> V_15 , V_104 ) ;
}
F_36 ( V_19 ) ;
}
static void F_92 ( struct V_8 * V_9 ,
struct V_10 * V_104 )
{
struct V_3 * V_133 , * V_134 ;
struct V_7 * V_3 , * V_135 ;
T_1 V_41 , V_40 , V_136 ;
V_41 = F_65 ( V_104 ) ;
V_40 = F_67 ( V_104 ) ;
F_8 ( L_20 , V_41 , V_40 ) ;
if ( V_41 != V_70 ) {
V_3 = F_31 ( V_9 , V_41 , V_70 ) ;
if ( V_3 == NULL || V_3 -> V_4 . V_21 != V_24 ) {
V_136 = V_137 ;
goto V_138;
}
} else {
T_1 * V_53 ;
T_2 V_54 ;
V_53 = F_86 ( V_104 , & V_54 ) ;
if ( V_53 == NULL ) {
V_136 = V_137 ;
goto V_138;
}
F_8 ( L_22 , V_54 ) ;
V_3 = F_85 ( V_9 , V_53 , V_54 ) ;
if ( V_3 == NULL ) {
V_136 = V_137 ;
goto V_138;
}
}
F_93 ( & V_3 -> V_4 ) ;
V_134 = & V_3 -> V_4 ;
if ( F_94 ( V_134 ) ) {
V_136 = V_139 ;
F_95 ( & V_3 -> V_4 ) ;
F_37 ( & V_3 -> V_4 ) ;
goto V_138;
}
if ( V_3 -> V_40 == V_59 ) {
T_1 V_40 = F_59 ( V_9 ) ;
F_8 ( L_23 , V_40 ) ;
if ( V_40 == V_58 ) {
V_136 = V_139 ;
F_95 ( & V_3 -> V_4 ) ;
F_37 ( & V_3 -> V_4 ) ;
goto V_138;
}
V_3 -> V_40 = V_40 ;
}
V_133 = F_96 ( NULL , V_134 -> V_30 , V_110 ) ;
if ( V_133 == NULL ) {
V_136 = V_139 ;
F_95 ( & V_3 -> V_4 ) ;
F_37 ( & V_3 -> V_4 ) ;
goto V_138;
}
V_135 = V_7 ( V_133 ) ;
V_135 -> V_23 = V_9 -> V_23 ;
V_135 -> V_9 = F_21 ( V_9 ) ;
V_135 -> V_140 = V_9 -> V_141 ;
V_135 -> V_142 = V_3 -> V_142 ;
V_135 -> V_41 = V_40 ;
V_135 -> V_119 = V_9 -> V_119 ;
V_135 -> V_134 = V_134 ;
V_135 -> V_40 = V_3 -> V_40 ;
if ( V_3 -> V_40 < V_63 && V_3 -> V_40 >= V_60 ) {
T_3 * V_143 ;
F_8 ( L_24 , V_3 -> V_40 , V_135 ) ;
V_143 =
& V_9 -> V_68 [ V_3 -> V_40 - V_60 ] ;
F_97 ( V_143 ) ;
V_135 -> V_144 = V_3 -> V_40 ;
}
F_98 ( V_135 , & V_104 -> V_45 [ V_127 ] ,
V_104 -> V_117 - V_127 ) ;
F_8 ( L_25 , V_135 , & V_135 -> V_4 ) ;
F_1 ( & V_9 -> V_20 , V_133 ) ;
F_99 ( & V_3 -> V_4 , V_133 ) ;
F_100 ( V_9 -> V_23 -> V_111 ) ;
V_133 -> V_21 = V_22 ;
V_134 -> V_145 ( V_134 , 0 ) ;
F_101 ( V_135 ) ;
F_95 ( & V_3 -> V_4 ) ;
F_37 ( & V_3 -> V_4 ) ;
return;
V_138:
F_102 ( V_9 , V_41 , V_40 , V_136 ) ;
}
int F_103 ( struct V_7 * V_3 )
{
int V_146 = 0 ;
struct V_8 * V_9 = V_3 -> V_9 ;
F_8 ( L_26 ,
V_3 -> V_147 , F_104 ( & V_3 -> V_14 ) ,
V_3 -> V_148 ) ;
while ( V_3 -> V_147 &&
F_104 ( & V_3 -> V_14 ) < V_3 -> V_148 ) {
struct V_10 * V_100 ;
V_100 = F_77 ( & V_3 -> V_13 ) ;
if ( V_100 == NULL )
break;
F_70 ( V_3 , V_100 ) ;
F_81 ( & V_9 -> V_13 , V_100 ) ;
V_146 ++ ;
}
return V_146 ;
}
static void F_105 ( struct V_8 * V_9 ,
struct V_10 * V_104 )
{
struct V_7 * V_19 ;
struct V_3 * V_4 ;
T_1 V_41 , V_40 , V_114 , V_149 , V_150 ;
V_114 = F_66 ( V_104 ) ;
V_41 = F_65 ( V_104 ) ;
V_40 = F_67 ( V_104 ) ;
V_149 = F_68 ( V_104 ) ;
V_150 = F_69 ( V_104 ) ;
F_8 ( L_27 , V_41 , V_40 , V_150 , V_149 ) ;
V_19 = F_31 ( V_9 , V_41 , V_40 ) ;
if ( V_19 == NULL ) {
F_102 ( V_9 , V_41 , V_40 , V_151 ) ;
return;
}
V_4 = & V_19 -> V_4 ;
F_93 ( V_4 ) ;
if ( V_4 -> V_21 == V_28 ) {
F_95 ( V_4 ) ;
F_36 ( V_19 ) ;
}
if ( V_114 == V_112 ) {
F_8 ( L_28 , & V_19 -> V_4 ) ;
if ( V_149 == V_19 -> V_102 )
V_19 -> V_102 = ( V_19 -> V_102 + 1 ) % 16 ;
else
F_41 ( L_29 ) ;
F_90 ( V_104 , V_127 + V_152 ) ;
if ( F_75 ( & V_19 -> V_4 , V_104 ) ) {
F_41 ( L_21 ) ;
F_91 ( & V_19 -> V_15 , V_104 ) ;
}
}
if ( V_19 -> V_153 != V_150 ) {
struct V_10 * V_11 , * V_12 ;
T_1 V_26 ;
V_19 -> V_153 = V_150 ;
F_10 (&llcp_sock->tx_pending_queue, s, tmp) {
V_26 = F_68 ( V_11 ) ;
F_11 ( V_11 , & V_19 -> V_14 ) ;
F_12 ( V_11 ) ;
if ( V_26 == V_150 )
break;
}
F_106 (&llcp_sock->tx_pending_queue,
s, tmp) {
F_11 ( V_11 , & V_19 -> V_14 ) ;
F_91 ( & V_9 -> V_13 , V_11 ) ;
}
}
if ( V_114 == V_154 )
V_19 -> V_147 = true ;
else if ( V_114 == V_155 )
V_19 -> V_147 = false ;
if ( F_103 ( V_19 ) == 0 && V_114 == V_112 )
F_107 ( V_19 ) ;
F_95 ( V_4 ) ;
F_36 ( V_19 ) ;
}
static void F_108 ( struct V_8 * V_9 ,
struct V_10 * V_104 )
{
struct V_7 * V_19 ;
struct V_3 * V_4 ;
T_1 V_41 , V_40 ;
V_41 = F_65 ( V_104 ) ;
V_40 = F_67 ( V_104 ) ;
V_19 = F_31 ( V_9 , V_41 , V_40 ) ;
if ( V_19 == NULL ) {
F_102 ( V_9 , V_41 , V_40 , V_151 ) ;
return;
}
V_4 = & V_19 -> V_4 ;
F_93 ( V_4 ) ;
F_7 ( V_19 ) ;
if ( V_4 -> V_21 == V_28 ) {
F_95 ( V_4 ) ;
F_36 ( V_19 ) ;
}
if ( V_4 -> V_21 == V_22 ) {
F_16 ( V_9 -> V_23 ) ;
V_4 -> V_21 = V_28 ;
V_4 -> V_156 ( V_4 ) ;
}
F_102 ( V_9 , V_41 , V_40 , V_157 ) ;
F_95 ( V_4 ) ;
F_36 ( V_19 ) ;
}
static void F_109 ( struct V_8 * V_9 , struct V_10 * V_104 )
{
struct V_7 * V_19 ;
struct V_3 * V_4 ;
T_1 V_41 , V_40 ;
V_41 = F_65 ( V_104 ) ;
V_40 = F_67 ( V_104 ) ;
V_19 = F_84 ( V_9 , V_41 ) ;
if ( V_19 == NULL ) {
F_41 ( L_30 ) ;
F_102 ( V_9 , V_41 , V_40 , V_151 ) ;
return;
}
V_4 = & V_19 -> V_4 ;
F_5 ( & V_9 -> V_123 , V_4 ) ;
F_1 ( & V_9 -> V_20 , V_4 ) ;
V_19 -> V_41 = V_40 ;
F_98 ( V_19 , & V_104 -> V_45 [ V_127 ] ,
V_104 -> V_117 - V_127 ) ;
V_4 -> V_21 = V_22 ;
V_4 -> V_156 ( V_4 ) ;
F_36 ( V_19 ) ;
}
static void F_110 ( struct V_8 * V_9 , struct V_10 * V_104 )
{
struct V_7 * V_19 ;
struct V_3 * V_4 ;
T_1 V_41 , V_40 , V_136 ;
V_41 = F_65 ( V_104 ) ;
V_40 = F_67 ( V_104 ) ;
V_136 = V_104 -> V_45 [ 2 ] ;
F_8 ( L_31 , V_40 , V_41 , V_136 ) ;
switch ( V_136 ) {
case V_137 :
case V_139 :
V_19 = F_84 ( V_9 , V_41 ) ;
break;
default:
V_19 = F_31 ( V_9 , V_41 , V_40 ) ;
break;
}
if ( V_19 == NULL ) {
F_8 ( L_32 ) ;
return;
}
V_4 = & V_19 -> V_4 ;
V_4 -> V_158 = V_159 ;
V_4 -> V_21 = V_28 ;
V_4 -> V_156 ( V_4 ) ;
F_36 ( V_19 ) ;
}
static void F_111 ( struct V_8 * V_9 ,
struct V_10 * V_104 )
{
struct V_7 * V_19 ;
T_1 V_41 , V_40 , * V_124 , type , V_125 , V_160 , V_49 ;
T_4 V_161 , V_128 ;
char * V_47 ;
T_2 V_48 ;
V_41 = F_65 ( V_104 ) ;
V_40 = F_67 ( V_104 ) ;
F_8 ( L_20 , V_41 , V_40 ) ;
if ( V_41 != V_70 || V_40 != V_70 ) {
F_41 ( L_33 ) ;
return;
}
V_124 = & V_104 -> V_45 [ V_127 ] ;
V_161 = V_104 -> V_117 - V_127 ;
V_128 = 0 ;
while ( V_128 < V_161 ) {
type = V_124 [ 0 ] ;
V_125 = V_124 [ 1 ] ;
switch ( type ) {
case V_162 :
V_160 = V_124 [ 2 ] ;
V_47 = ( char * ) & V_124 [ 3 ] ;
V_48 = V_125 - 1 ;
F_8 ( L_34 , V_47 ) ;
if ( V_48 == strlen ( L_35 ) &&
! strncmp ( V_47 , L_35 ,
V_48 ) ) {
V_49 = 1 ;
goto V_163;
}
V_19 = F_46 ( V_9 , V_47 ,
V_48 ) ;
if ( ! V_19 ) {
V_49 = 0 ;
goto V_163;
}
if ( V_19 -> V_40 == V_59 ) {
T_3 * V_143 ;
V_49 = F_59 ( V_9 ) ;
F_8 ( L_36 , V_49 ) ;
if ( V_49 == V_58 ) {
V_49 = 0 ;
goto V_163;
}
V_143 =
& V_9 -> V_68 [ V_49 -
V_60 ] ;
F_97 ( V_143 ) ;
V_19 -> V_40 = V_49 ;
V_19 -> V_144 = V_49 ;
} else {
V_49 = V_19 -> V_40 ;
}
F_8 ( L_37 , V_19 , V_49 ) ;
V_163:
F_112 ( V_9 , V_160 , V_49 ) ;
break;
default:
F_41 ( L_38 , type ) ;
break;
}
V_128 += V_125 + 2 ;
V_124 += V_125 + 2 ;
}
}
static void F_113 ( struct V_43 * V_44 )
{
struct V_8 * V_9 = F_24 ( V_44 , struct V_8 ,
V_37 ) ;
T_1 V_41 , V_40 , V_114 ;
struct V_10 * V_104 ;
V_104 = V_9 -> V_39 ;
if ( V_104 == NULL ) {
F_8 ( L_39 ) ;
return;
}
V_114 = F_66 ( V_104 ) ;
V_41 = F_65 ( V_104 ) ;
V_40 = F_67 ( V_104 ) ;
F_8 ( L_40 , V_114 , V_41 , V_40 ) ;
if ( V_114 != V_164 )
F_79 ( V_115 , L_41 , V_116 ,
16 , 1 , V_104 -> V_45 , V_104 -> V_117 , true ) ;
F_71 ( V_9 , V_104 , V_165 ) ;
switch ( V_114 ) {
case V_164 :
F_8 ( L_42 ) ;
break;
case V_166 :
F_8 ( L_43 ) ;
F_87 ( V_9 , V_104 ) ;
break;
case V_167 :
F_8 ( L_44 ) ;
F_92 ( V_9 , V_104 ) ;
break;
case V_168 :
F_8 ( L_45 ) ;
F_108 ( V_9 , V_104 ) ;
break;
case V_169 :
F_8 ( L_46 ) ;
F_109 ( V_9 , V_104 ) ;
break;
case V_170 :
F_8 ( L_47 ) ;
F_110 ( V_9 , V_104 ) ;
break;
case V_171 :
F_8 ( L_48 ) ;
F_111 ( V_9 , V_104 ) ;
break;
case V_112 :
case V_154 :
case V_155 :
F_8 ( L_49 ) ;
F_105 ( V_9 , V_104 ) ;
break;
}
F_42 ( & V_9 -> V_36 ) ;
F_12 ( V_9 -> V_39 ) ;
V_9 -> V_39 = NULL ;
}
void V_120 ( void * V_45 , struct V_10 * V_104 , int V_172 )
{
struct V_8 * V_9 = (struct V_8 * ) V_45 ;
F_8 ( L_50 ) ;
if ( V_172 < 0 ) {
F_41 ( L_51 , V_172 ) ;
return;
}
V_9 -> V_39 = F_114 ( V_104 ) ;
F_115 ( & V_9 -> V_35 ) ;
F_42 ( & V_9 -> V_37 ) ;
}
int F_116 ( struct V_46 * V_23 , struct V_10 * V_104 )
{
struct V_8 * V_9 ;
V_9 = F_43 ( V_23 ) ;
if ( V_9 == NULL )
return - V_97 ;
V_9 -> V_39 = F_114 ( V_104 ) ;
F_115 ( & V_9 -> V_35 ) ;
F_42 ( & V_9 -> V_37 ) ;
return 0 ;
}
void F_117 ( struct V_46 * V_23 )
{
struct V_8 * V_9 ;
V_9 = F_43 ( V_23 ) ;
if ( V_9 == NULL )
return;
F_13 ( V_9 , true ) ;
}
void F_118 ( struct V_46 * V_23 , T_5 V_119 ,
T_1 V_173 , T_1 V_174 )
{
struct V_8 * V_9 ;
F_8 ( L_52 , V_174 ) ;
V_9 = F_43 ( V_23 ) ;
if ( V_9 == NULL )
return;
V_9 -> V_119 = V_119 ;
V_9 -> V_173 = V_173 ;
V_9 -> V_174 = V_174 ;
if ( V_174 == V_175 ) {
F_8 ( L_53 ) ;
F_42 ( & V_9 -> V_36 ) ;
} else {
F_82 ( & V_9 -> V_35 ,
V_121 + F_83 ( V_9 -> V_122 ) ) ;
}
}
int F_119 ( struct V_46 * V_176 )
{
struct V_8 * V_9 ;
V_9 = F_120 ( sizeof( struct V_8 ) , V_177 ) ;
if ( V_9 == NULL )
return - V_178 ;
V_9 -> V_23 = V_176 ;
F_121 ( & V_9 -> V_34 ) ;
F_122 ( & V_9 -> V_32 ) ;
F_123 ( & V_9 -> V_56 ) ;
F_124 ( & V_9 -> V_35 ) ;
V_9 -> V_35 . V_45 = ( unsigned long ) V_9 ;
V_9 -> V_35 . V_179 = F_40 ;
F_125 ( & V_9 -> V_13 ) ;
F_126 ( & V_9 -> V_36 , F_76 ) ;
V_9 -> V_39 = NULL ;
F_126 ( & V_9 -> V_37 , F_113 ) ;
F_126 ( & V_9 -> V_38 , F_38 ) ;
F_127 ( & V_9 -> V_20 . V_5 ) ;
F_127 ( & V_9 -> V_123 . V_5 ) ;
F_127 ( & V_9 -> V_108 . V_5 ) ;
V_9 -> V_88 = 150 ;
V_9 -> V_148 = V_180 ;
V_9 -> V_91 = F_128 ( V_181 ) ;
F_60 ( V_9 ) ;
V_9 -> V_141 = V_182 ;
V_9 -> V_122 = V_183 ;
F_129 ( & V_9 -> V_34 , & V_184 ) ;
return 0 ;
}
void F_130 ( struct V_46 * V_23 )
{
struct V_8 * V_9 = F_43 ( V_23 ) ;
if ( V_9 == NULL ) {
F_8 ( L_54 ) ;
return;
}
F_29 ( V_9 ) ;
}
int T_6 F_131 ( void )
{
F_121 ( & V_184 ) ;
return F_132 () ;
}
void F_133 ( void )
{
F_134 () ;
}
