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
if ( V_9 == NULL )
return;
F_10 (&local->tx_queue, s, tmp) {
if ( V_11 -> V_4 != & V_3 -> V_4 )
continue;
F_11 ( V_11 , & V_9 -> V_13 ) ;
F_12 ( V_11 ) ;
}
}
static void F_13 ( struct V_8 * V_9 , bool V_15 ,
int V_16 )
{
struct V_3 * V_4 ;
struct V_17 * V_12 ;
struct V_7 * V_18 ;
F_9 ( & V_9 -> V_13 ) ;
F_2 ( & V_9 -> V_19 . V_5 ) ;
F_14 (sk, tmp, &local->sockets.head) {
V_18 = V_7 ( V_4 ) ;
F_15 ( V_4 ) ;
F_7 ( V_18 ) ;
if ( V_4 -> V_20 == V_21 )
F_16 ( V_18 -> V_22 ) ;
if ( V_4 -> V_20 == V_23 ) {
struct V_7 * V_24 , * V_25 ;
struct V_3 * V_26 ;
F_17 (lsk, n,
&llcp_sock->accept_queue,
accept_queue) {
V_26 = & V_24 -> V_4 ;
F_15 ( V_26 ) ;
F_18 ( V_26 ) ;
if ( V_16 )
V_26 -> V_27 = V_16 ;
V_26 -> V_20 = V_28 ;
V_26 -> V_29 ( V_4 ) ;
F_19 ( V_26 ) ;
}
if ( V_15 == true ) {
F_19 ( V_4 ) ;
continue;
}
}
if ( V_4 -> V_20 == V_30 && V_4 -> V_31 == V_32 &&
V_15 == true ) {
F_19 ( V_4 ) ;
continue;
}
if ( V_16 )
V_4 -> V_27 = V_16 ;
V_4 -> V_20 = V_28 ;
V_4 -> V_29 ( V_4 ) ;
F_19 ( V_4 ) ;
F_6 ( V_4 ) ;
}
F_4 ( & V_9 -> V_19 . V_5 ) ;
if ( V_15 == true )
return;
F_2 ( & V_9 -> V_33 . V_5 ) ;
F_14 (sk, tmp, &local->raw_sockets.head) {
V_18 = V_7 ( V_4 ) ;
F_15 ( V_4 ) ;
F_7 ( V_18 ) ;
if ( V_16 )
V_4 -> V_27 = V_16 ;
V_4 -> V_20 = V_28 ;
V_4 -> V_29 ( V_4 ) ;
F_19 ( V_4 ) ;
F_6 ( V_4 ) ;
}
F_4 ( & V_9 -> V_33 . V_5 ) ;
}
struct V_8 * F_20 ( struct V_8 * V_9 )
{
F_21 ( & V_9 -> V_34 ) ;
return V_9 ;
}
static void F_22 ( struct V_8 * V_9 , bool V_15 )
{
F_13 ( V_9 , V_15 , V_35 ) ;
F_23 ( & V_9 -> V_36 ) ;
F_9 ( & V_9 -> V_13 ) ;
F_24 ( & V_9 -> V_37 ) ;
F_24 ( & V_9 -> V_38 ) ;
F_24 ( & V_9 -> V_39 ) ;
F_12 ( V_9 -> V_40 ) ;
}
static void F_25 ( struct V_41 * V_34 )
{
struct V_8 * V_9 ;
V_9 = F_26 ( V_34 , struct V_8 , V_34 ) ;
F_27 ( & V_9 -> V_42 ) ;
F_22 ( V_9 , false ) ;
F_28 ( V_9 ) ;
}
int F_29 ( struct V_8 * V_9 )
{
if ( V_9 == NULL )
return 0 ;
return F_30 ( & V_9 -> V_34 , F_25 ) ;
}
static struct V_7 * F_31 ( struct V_8 * V_9 ,
T_1 V_43 , T_1 V_44 )
{
struct V_3 * V_4 ;
struct V_7 * V_18 , * V_45 ;
F_8 ( L_2 , V_43 , V_44 ) ;
if ( V_43 == 0 && V_44 == 0 )
return NULL ;
F_32 ( & V_9 -> V_19 . V_5 ) ;
V_18 = NULL ;
F_33 (sk, &local->sockets.head) {
V_45 = V_7 ( V_4 ) ;
if ( V_45 -> V_43 == V_43 && V_45 -> V_44 == V_44 ) {
V_18 = V_45 ;
break;
}
}
F_34 ( & V_9 -> V_19 . V_5 ) ;
if ( V_18 == NULL )
return NULL ;
F_35 ( & V_18 -> V_4 ) ;
return V_18 ;
}
static void F_36 ( struct V_7 * V_3 )
{
F_37 ( & V_3 -> V_4 ) ;
}
static void F_38 ( struct V_46 * V_47 )
{
struct V_8 * V_9 = F_26 ( V_47 , struct V_8 ,
V_39 ) ;
F_39 ( V_9 -> V_22 ) ;
}
static void F_40 ( unsigned long V_48 )
{
struct V_8 * V_9 = (struct V_8 * ) V_48 ;
F_41 ( L_3 ) ;
F_42 ( & V_9 -> V_39 ) ;
}
struct V_8 * F_43 ( struct V_49 * V_22 )
{
struct V_8 * V_9 , * V_25 ;
F_17 (local, n, &llcp_devices, list)
if ( V_9 -> V_22 == V_22 )
return V_9 ;
F_8 ( L_4 ) ;
return NULL ;
}
static int F_44 ( char * V_50 , T_2 V_51 )
{
int V_52 , V_53 ;
F_8 ( L_5 , V_50 ) ;
if ( V_50 == NULL )
return - V_54 ;
V_53 = F_45 ( V_55 ) ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ ) {
if ( V_55 [ V_52 ] == NULL )
continue;
if ( strncmp ( V_55 [ V_52 ] , V_50 , V_51 ) == 0 )
return V_52 ;
}
return - V_54 ;
}
static
struct V_7 * F_46 ( struct V_8 * V_9 ,
T_1 * V_56 , T_2 V_57 )
{
struct V_3 * V_4 ;
struct V_7 * V_18 , * V_45 ;
F_8 ( L_6 , V_57 , V_56 ) ;
if ( V_56 == NULL || V_57 == 0 )
return NULL ;
F_32 ( & V_9 -> V_19 . V_5 ) ;
V_18 = NULL ;
F_33 (sk, &local->sockets.head) {
V_45 = V_7 ( V_4 ) ;
F_8 ( L_7 , V_45 ) ;
if ( V_45 -> V_4 . V_31 == V_58 &&
V_45 -> V_4 . V_20 != V_23 )
continue;
if ( V_45 -> V_4 . V_31 == V_32 &&
V_45 -> V_4 . V_20 != V_30 )
continue;
if ( V_45 -> V_50 == NULL ||
V_45 -> V_51 == 0 )
continue;
if ( V_45 -> V_51 != V_57 )
continue;
if ( memcmp ( V_56 , V_45 -> V_50 , V_57 ) == 0 ) {
V_18 = V_45 ;
break;
}
}
F_34 ( & V_9 -> V_19 . V_5 ) ;
F_8 ( L_8 , V_18 ) ;
return V_18 ;
}
T_1 F_47 ( struct V_8 * V_9 ,
struct V_7 * V_3 )
{
F_48 ( & V_9 -> V_59 ) ;
if ( V_3 -> V_50 != NULL && V_3 -> V_51 > 0 ) {
int V_43 = F_44 ( V_3 -> V_50 ,
V_3 -> V_51 ) ;
if ( V_43 > 0 ) {
F_8 ( L_9 , V_43 ) ;
if ( V_9 -> V_60 & F_49 ( V_43 ) ) {
F_50 ( & V_9 -> V_59 ) ;
return V_61 ;
}
F_51 ( V_43 , & V_9 -> V_60 ) ;
F_50 ( & V_9 -> V_59 ) ;
return V_43 ;
}
if ( F_46 ( V_9 , V_3 -> V_50 ,
V_3 -> V_51 ) != NULL ) {
F_50 ( & V_9 -> V_59 ) ;
return V_61 ;
}
F_50 ( & V_9 -> V_59 ) ;
return V_62 ;
} else if ( V_3 -> V_43 != 0 && V_3 -> V_43 < V_63 ) {
if ( ! F_52 ( V_3 -> V_43 , & V_9 -> V_60 ) ) {
F_51 ( V_3 -> V_43 , & V_9 -> V_60 ) ;
F_50 ( & V_9 -> V_59 ) ;
return V_3 -> V_43 ;
}
}
F_50 ( & V_9 -> V_59 ) ;
return V_61 ;
}
T_1 F_53 ( struct V_8 * V_9 )
{
T_1 V_64 ;
F_48 ( & V_9 -> V_59 ) ;
V_64 = F_54 ( & V_9 -> V_65 , V_66 ) ;
if ( V_64 == V_66 ) {
F_50 ( & V_9 -> V_59 ) ;
return V_61 ;
}
F_51 ( V_64 , & V_9 -> V_65 ) ;
F_50 ( & V_9 -> V_59 ) ;
return V_64 + V_67 ;
}
void F_55 ( struct V_8 * V_9 , T_1 V_43 )
{
T_1 V_64 ;
unsigned long * V_68 ;
if ( V_43 < V_63 ) {
V_64 = V_43 ;
V_68 = & V_9 -> V_60 ;
} else if ( V_43 < V_66 ) {
T_3 * V_69 ;
V_64 = V_43 - V_63 ;
V_68 = & V_9 -> V_70 ;
V_69 = & V_9 -> V_71 [ V_64 ] ;
F_8 ( L_10 , F_56 ( V_69 ) ) ;
F_48 ( & V_9 -> V_59 ) ;
if ( F_57 ( V_69 ) ) {
struct V_7 * V_72 ;
F_8 ( L_11 , V_43 ) ;
F_58 ( V_64 , V_68 ) ;
V_72 = F_31 ( V_9 , V_43 , V_73 ) ;
if ( V_72 ) {
V_72 -> V_43 = V_62 ;
F_36 ( V_72 ) ;
}
}
F_50 ( & V_9 -> V_59 ) ;
return;
} else if ( V_43 < V_74 ) {
V_64 = V_43 - V_66 ;
V_68 = & V_9 -> V_65 ;
} else {
return;
}
F_48 ( & V_9 -> V_59 ) ;
F_58 ( V_64 , V_68 ) ;
F_50 ( & V_9 -> V_59 ) ;
}
static T_1 F_59 ( struct V_8 * V_9 )
{
T_1 V_43 ;
F_48 ( & V_9 -> V_59 ) ;
V_43 = F_54 ( & V_9 -> V_70 , V_75 ) ;
if ( V_43 == V_75 ) {
F_50 ( & V_9 -> V_59 ) ;
return V_61 ;
}
F_8 ( L_12 , V_63 + V_43 ) ;
F_51 ( V_43 , & V_9 -> V_70 ) ;
F_50 ( & V_9 -> V_59 ) ;
return V_63 + V_43 ;
}
static int F_60 ( struct V_8 * V_9 )
{
T_1 * V_76 , * V_77 , V_78 , V_79 ;
T_1 * V_80 , V_81 ;
T_1 * V_82 , V_83 ;
T_1 * V_84 , V_85 ;
T_1 V_86 = 0 ;
int V_87 = 0 ;
V_78 = V_88 ;
V_77 = F_61 ( V_89 , & V_78 ,
1 , & V_79 ) ;
V_86 += V_79 ;
V_80 = F_61 ( V_90 , & V_9 -> V_91 , 1 , & V_81 ) ;
V_86 += V_81 ;
F_8 ( L_13 , V_9 -> V_60 ) ;
V_82 = F_61 ( V_92 , ( T_1 * ) & V_9 -> V_60 , 2 ,
& V_83 ) ;
V_86 += V_83 ;
V_84 = F_61 ( V_93 , ( T_1 * ) & V_9 -> V_94 , 0 ,
& V_85 ) ;
V_86 += V_85 ;
V_86 += F_45 ( V_95 ) ;
if ( V_86 > V_96 ) {
V_87 = - V_54 ;
goto V_97;
}
V_76 = V_9 -> V_98 ;
memcpy ( V_76 , V_95 , F_45 ( V_95 ) ) ;
V_76 += F_45 ( V_95 ) ;
memcpy ( V_76 , V_77 , V_79 ) ;
V_76 += V_79 ;
memcpy ( V_76 , V_80 , V_81 ) ;
V_76 += V_81 ;
memcpy ( V_76 , V_82 , V_83 ) ;
V_76 += V_83 ;
memcpy ( V_76 , V_84 , V_85 ) ;
V_76 += V_85 ;
V_9 -> V_86 = V_86 ;
V_97:
F_28 ( V_77 ) ;
F_28 ( V_80 ) ;
F_28 ( V_82 ) ;
F_28 ( V_84 ) ;
return V_87 ;
}
T_1 * F_62 ( struct V_49 * V_22 , T_2 * V_99 )
{
struct V_8 * V_9 ;
V_9 = F_43 ( V_22 ) ;
if ( V_9 == NULL ) {
* V_99 = 0 ;
return NULL ;
}
F_60 ( V_9 ) ;
* V_99 = V_9 -> V_86 ;
return V_9 -> V_98 ;
}
int F_63 ( struct V_49 * V_22 , T_1 * V_98 , T_1 V_86 )
{
struct V_8 * V_9 = F_43 ( V_22 ) ;
if ( V_9 == NULL ) {
F_41 ( L_14 ) ;
return - V_100 ;
}
if ( V_86 < 3 )
return - V_54 ;
memset ( V_9 -> V_101 , 0 , V_96 ) ;
memcpy ( V_9 -> V_101 , V_98 , V_86 ) ;
V_9 -> V_102 = V_86 ;
if ( memcmp ( V_9 -> V_101 , V_95 , 3 ) ) {
F_41 ( L_15 ) ;
return - V_54 ;
}
return F_64 ( V_9 ,
& V_9 -> V_101 [ 3 ] ,
V_9 -> V_102 - 3 ) ;
}
static T_1 F_65 ( struct V_10 * V_103 )
{
return ( V_103 -> V_48 [ 0 ] & 0xfc ) >> 2 ;
}
static T_1 F_66 ( struct V_10 * V_103 )
{
return ( ( V_103 -> V_48 [ 0 ] & 0x03 ) << 2 ) | ( ( V_103 -> V_48 [ 1 ] & 0xc0 ) >> 6 ) ;
}
static T_1 F_67 ( struct V_10 * V_103 )
{
return V_103 -> V_48 [ 1 ] & 0x3f ;
}
static T_1 F_68 ( struct V_10 * V_103 )
{
return V_103 -> V_48 [ 2 ] >> 4 ;
}
static T_1 F_69 ( struct V_10 * V_103 )
{
return V_103 -> V_48 [ 2 ] & 0xf ;
}
static void F_70 ( struct V_7 * V_3 , struct V_10 * V_103 )
{
V_103 -> V_48 [ 2 ] = ( V_3 -> V_104 << 4 ) | ( V_3 -> V_105 ) ;
V_3 -> V_104 = ( V_3 -> V_104 + 1 ) % 16 ;
V_3 -> V_106 = ( V_3 -> V_105 - 1 ) % 16 ;
}
void F_71 ( struct V_8 * V_9 ,
struct V_10 * V_107 , T_1 V_108 )
{
struct V_10 * V_109 = NULL , * V_110 ;
struct V_3 * V_4 ;
T_1 * V_48 ;
F_32 ( & V_9 -> V_33 . V_5 ) ;
F_33 (sk, &local->raw_sockets.head) {
if ( V_4 -> V_20 != V_30 )
continue;
if ( V_109 == NULL ) {
V_109 = F_72 ( V_107 , V_111 ,
V_112 ) ;
if ( V_109 == NULL )
continue;
V_48 = F_73 ( V_109 , V_111 ) ;
V_48 [ 0 ] = V_9 -> V_22 ? V_9 -> V_22 -> V_113 : 0xFF ;
V_48 [ 1 ] = V_108 ;
}
V_110 = F_74 ( V_109 , V_112 ) ;
if ( ! V_110 )
continue;
if ( F_75 ( V_4 , V_110 ) )
F_12 ( V_110 ) ;
}
F_34 ( & V_9 -> V_33 . V_5 ) ;
F_12 ( V_109 ) ;
}
static void F_76 ( struct V_46 * V_47 )
{
struct V_8 * V_9 = F_26 ( V_47 , struct V_8 ,
V_37 ) ;
struct V_10 * V_107 ;
struct V_3 * V_4 ;
struct V_7 * V_18 ;
V_107 = F_77 ( & V_9 -> V_13 ) ;
if ( V_107 != NULL ) {
V_4 = V_107 -> V_4 ;
V_18 = V_7 ( V_4 ) ;
if ( V_18 == NULL && F_66 ( V_107 ) == V_114 ) {
F_78 ( V_9 -> V_22 ) ;
} else {
struct V_10 * V_115 = NULL ;
T_1 V_116 = F_66 ( V_107 ) ;
int V_87 ;
F_8 ( L_16 ) ;
F_79 ( V_117 , L_17 ,
V_118 , 16 , 1 ,
V_107 -> V_48 , V_107 -> V_119 , true ) ;
if ( V_116 == V_114 )
V_115 = V_109 ( V_107 , V_112 ) ;
F_80 ( V_107 ) ;
F_71 ( V_9 , V_107 ,
V_120 ) ;
V_87 = F_81 ( V_9 -> V_22 , V_9 -> V_121 ,
V_107 , V_122 , V_9 ) ;
if ( V_87 ) {
F_12 ( V_115 ) ;
goto V_97;
}
if ( V_116 == V_114 && V_115 )
F_82 ( & V_18 -> V_14 ,
V_115 ) ;
}
} else {
F_78 ( V_9 -> V_22 ) ;
}
V_97:
F_83 ( & V_9 -> V_36 ,
V_123 + F_84 ( 2 * V_9 -> V_124 ) ) ;
}
static struct V_7 * F_85 ( struct V_8 * V_9 ,
T_1 V_43 )
{
struct V_3 * V_4 ;
struct V_7 * V_18 ;
F_32 ( & V_9 -> V_125 . V_5 ) ;
F_33 (sk, &local->connecting_sockets.head) {
V_18 = V_7 ( V_4 ) ;
if ( V_18 -> V_43 == V_43 ) {
F_35 ( & V_18 -> V_4 ) ;
goto V_97;
}
}
V_18 = NULL ;
V_97:
F_34 ( & V_9 -> V_125 . V_5 ) ;
return V_18 ;
}
static struct V_7 * F_86 ( struct V_8 * V_9 ,
T_1 * V_56 , T_2 V_57 )
{
struct V_7 * V_18 ;
V_18 = F_46 ( V_9 , V_56 , V_57 ) ;
if ( V_18 == NULL )
return NULL ;
F_35 ( & V_18 -> V_4 ) ;
return V_18 ;
}
static T_1 * F_87 ( struct V_10 * V_107 , T_2 * V_57 )
{
T_1 * V_126 = & V_107 -> V_48 [ 2 ] , type , V_127 ;
T_2 V_128 = V_107 -> V_119 - V_129 , V_130 = 0 ;
while ( V_130 < V_128 ) {
type = V_126 [ 0 ] ;
V_127 = V_126 [ 1 ] ;
F_8 ( L_18 , type , V_127 ) ;
if ( type == V_131 ) {
* V_57 = V_127 ;
return & V_126 [ 2 ] ;
}
V_130 += V_127 + 2 ;
V_126 += V_127 + 2 ;
}
return NULL ;
}
static void F_88 ( struct V_8 * V_9 ,
struct V_10 * V_107 )
{
struct V_7 * V_18 ;
struct V_132 * V_133 ;
T_1 V_44 , V_43 ;
V_44 = F_65 ( V_107 ) ;
V_43 = F_67 ( V_107 ) ;
V_133 = F_89 ( V_107 ) ;
V_133 -> V_44 = V_44 ;
V_133 -> V_43 = V_43 ;
F_90 ( L_19 , V_134 , V_44 , V_43 ) ;
F_8 ( L_20 , V_44 , V_43 ) ;
V_18 = F_31 ( V_9 , V_44 , V_73 ) ;
if ( V_18 == NULL || V_18 -> V_4 . V_31 != V_32 )
return;
F_91 ( V_107 , V_129 ) ;
if ( ! F_75 ( & V_18 -> V_4 , V_107 ) ) {
F_92 ( V_107 ) ;
} else {
F_41 ( L_21 ) ;
}
F_36 ( V_18 ) ;
}
static void F_93 ( struct V_8 * V_9 ,
struct V_10 * V_107 )
{
struct V_3 * V_135 , * V_136 ;
struct V_7 * V_3 , * V_137 ;
T_1 V_44 , V_43 , V_138 ;
V_44 = F_65 ( V_107 ) ;
V_43 = F_67 ( V_107 ) ;
F_8 ( L_20 , V_44 , V_43 ) ;
if ( V_44 != V_73 ) {
V_3 = F_31 ( V_9 , V_44 , V_73 ) ;
if ( V_3 == NULL || V_3 -> V_4 . V_20 != V_23 ) {
V_138 = V_139 ;
goto V_140;
}
} else {
T_1 * V_56 ;
T_2 V_57 ;
V_56 = F_87 ( V_107 , & V_57 ) ;
if ( V_56 == NULL ) {
V_138 = V_139 ;
goto V_140;
}
F_8 ( L_22 , V_57 ) ;
V_3 = F_86 ( V_9 , V_56 , V_57 ) ;
if ( V_3 == NULL ) {
V_138 = V_139 ;
goto V_140;
}
}
F_94 ( & V_3 -> V_4 ) ;
V_136 = & V_3 -> V_4 ;
if ( F_95 ( V_136 ) ) {
V_138 = V_141 ;
F_96 ( & V_3 -> V_4 ) ;
F_37 ( & V_3 -> V_4 ) ;
goto V_140;
}
if ( V_3 -> V_43 == V_62 ) {
T_1 V_43 = F_59 ( V_9 ) ;
F_8 ( L_23 , V_43 ) ;
if ( V_43 == V_61 ) {
V_138 = V_141 ;
F_96 ( & V_3 -> V_4 ) ;
F_37 ( & V_3 -> V_4 ) ;
goto V_140;
}
V_3 -> V_43 = V_43 ;
}
V_135 = F_97 ( NULL , V_136 -> V_31 , V_112 ) ;
if ( V_135 == NULL ) {
V_138 = V_141 ;
F_96 ( & V_3 -> V_4 ) ;
F_37 ( & V_3 -> V_4 ) ;
goto V_140;
}
V_137 = V_7 ( V_135 ) ;
V_137 -> V_22 = V_9 -> V_22 ;
V_137 -> V_9 = F_20 ( V_9 ) ;
V_137 -> V_142 = V_9 -> V_143 ;
V_137 -> V_144 = V_3 -> V_144 ;
V_137 -> V_44 = V_43 ;
V_137 -> V_121 = V_9 -> V_121 ;
V_137 -> V_136 = V_136 ;
V_137 -> V_43 = V_3 -> V_43 ;
if ( V_3 -> V_43 < V_66 && V_3 -> V_43 >= V_63 ) {
T_3 * V_145 ;
F_8 ( L_24 , V_3 -> V_43 , V_137 ) ;
V_145 =
& V_9 -> V_71 [ V_3 -> V_43 - V_63 ] ;
F_98 ( V_145 ) ;
V_137 -> V_146 = V_3 -> V_43 ;
}
F_99 ( V_137 , & V_107 -> V_48 [ V_129 ] ,
V_107 -> V_119 - V_129 ) ;
F_8 ( L_25 , V_137 , & V_137 -> V_4 ) ;
F_1 ( & V_9 -> V_19 , V_135 ) ;
F_100 ( & V_3 -> V_4 , V_135 ) ;
F_101 ( V_9 -> V_22 -> V_113 ) ;
V_135 -> V_20 = V_21 ;
V_136 -> V_147 ( V_136 , 0 ) ;
F_102 ( V_137 ) ;
F_96 ( & V_3 -> V_4 ) ;
F_37 ( & V_3 -> V_4 ) ;
return;
V_140:
F_103 ( V_9 , V_44 , V_43 , V_138 ) ;
}
int F_104 ( struct V_7 * V_3 )
{
int V_148 = 0 ;
struct V_8 * V_9 = V_3 -> V_9 ;
F_8 ( L_26 ,
V_3 -> V_149 , F_105 ( & V_3 -> V_14 ) ,
V_3 -> V_150 ) ;
while ( V_3 -> V_149 &&
F_105 ( & V_3 -> V_14 ) < V_3 -> V_150 ) {
struct V_10 * V_103 ;
V_103 = F_77 ( & V_3 -> V_13 ) ;
if ( V_103 == NULL )
break;
F_70 ( V_3 , V_103 ) ;
F_82 ( & V_9 -> V_13 , V_103 ) ;
V_148 ++ ;
}
return V_148 ;
}
static void F_106 ( struct V_8 * V_9 ,
struct V_10 * V_107 )
{
struct V_7 * V_18 ;
struct V_3 * V_4 ;
T_1 V_44 , V_43 , V_116 , V_151 , V_152 ;
V_116 = F_66 ( V_107 ) ;
V_44 = F_65 ( V_107 ) ;
V_43 = F_67 ( V_107 ) ;
V_151 = F_68 ( V_107 ) ;
V_152 = F_69 ( V_107 ) ;
F_8 ( L_27 , V_44 , V_43 , V_152 , V_151 ) ;
V_18 = F_31 ( V_9 , V_44 , V_43 ) ;
if ( V_18 == NULL ) {
F_103 ( V_9 , V_44 , V_43 , V_153 ) ;
return;
}
V_4 = & V_18 -> V_4 ;
F_94 ( V_4 ) ;
if ( V_4 -> V_20 == V_28 ) {
F_96 ( V_4 ) ;
F_36 ( V_18 ) ;
}
if ( V_116 == V_114 ) {
F_8 ( L_28 , & V_18 -> V_4 ) ;
if ( V_151 == V_18 -> V_105 )
V_18 -> V_105 = ( V_18 -> V_105 + 1 ) % 16 ;
else
F_41 ( L_29 ) ;
F_91 ( V_107 , V_129 + V_154 ) ;
if ( ! F_75 ( & V_18 -> V_4 , V_107 ) ) {
F_92 ( V_107 ) ;
} else {
F_41 ( L_21 ) ;
}
}
if ( V_18 -> V_155 != V_152 ) {
struct V_10 * V_11 , * V_12 ;
T_1 V_25 ;
V_18 -> V_155 = V_152 ;
F_10 (&llcp_sock->tx_pending_queue, s, tmp) {
V_25 = F_68 ( V_11 ) ;
F_11 ( V_11 , & V_18 -> V_14 ) ;
F_12 ( V_11 ) ;
if ( V_25 == V_152 )
break;
}
F_107 (&llcp_sock->tx_pending_queue,
s, tmp) {
F_11 ( V_11 , & V_18 -> V_14 ) ;
F_108 ( & V_9 -> V_13 , V_11 ) ;
}
}
if ( V_116 == V_156 )
V_18 -> V_149 = true ;
else if ( V_116 == V_157 )
V_18 -> V_149 = false ;
if ( F_104 ( V_18 ) == 0 && V_116 == V_114 )
F_109 ( V_18 ) ;
F_96 ( V_4 ) ;
F_36 ( V_18 ) ;
}
static void F_110 ( struct V_8 * V_9 ,
struct V_10 * V_107 )
{
struct V_7 * V_18 ;
struct V_3 * V_4 ;
T_1 V_44 , V_43 ;
V_44 = F_65 ( V_107 ) ;
V_43 = F_67 ( V_107 ) ;
V_18 = F_31 ( V_9 , V_44 , V_43 ) ;
if ( V_18 == NULL ) {
F_103 ( V_9 , V_44 , V_43 , V_153 ) ;
return;
}
V_4 = & V_18 -> V_4 ;
F_94 ( V_4 ) ;
F_7 ( V_18 ) ;
if ( V_4 -> V_20 == V_28 ) {
F_96 ( V_4 ) ;
F_36 ( V_18 ) ;
}
if ( V_4 -> V_20 == V_21 ) {
F_16 ( V_9 -> V_22 ) ;
V_4 -> V_20 = V_28 ;
V_4 -> V_29 ( V_4 ) ;
}
F_103 ( V_9 , V_44 , V_43 , V_158 ) ;
F_96 ( V_4 ) ;
F_36 ( V_18 ) ;
}
static void F_111 ( struct V_8 * V_9 , struct V_10 * V_107 )
{
struct V_7 * V_18 ;
struct V_3 * V_4 ;
T_1 V_44 , V_43 ;
V_44 = F_65 ( V_107 ) ;
V_43 = F_67 ( V_107 ) ;
V_18 = F_85 ( V_9 , V_44 ) ;
if ( V_18 == NULL ) {
F_41 ( L_30 ) ;
F_103 ( V_9 , V_44 , V_43 , V_153 ) ;
return;
}
V_4 = & V_18 -> V_4 ;
F_5 ( & V_9 -> V_125 , V_4 ) ;
F_1 ( & V_9 -> V_19 , V_4 ) ;
V_18 -> V_44 = V_43 ;
F_99 ( V_18 , & V_107 -> V_48 [ V_129 ] ,
V_107 -> V_119 - V_129 ) ;
V_4 -> V_20 = V_21 ;
V_4 -> V_29 ( V_4 ) ;
F_36 ( V_18 ) ;
}
static void F_112 ( struct V_8 * V_9 , struct V_10 * V_107 )
{
struct V_7 * V_18 ;
struct V_3 * V_4 ;
T_1 V_44 , V_43 , V_138 ;
V_44 = F_65 ( V_107 ) ;
V_43 = F_67 ( V_107 ) ;
V_138 = V_107 -> V_48 [ 2 ] ;
F_8 ( L_31 , V_43 , V_44 , V_138 ) ;
switch ( V_138 ) {
case V_139 :
case V_141 :
V_18 = F_85 ( V_9 , V_44 ) ;
break;
default:
V_18 = F_31 ( V_9 , V_44 , V_43 ) ;
break;
}
if ( V_18 == NULL ) {
F_8 ( L_32 ) ;
return;
}
V_4 = & V_18 -> V_4 ;
V_4 -> V_27 = V_35 ;
V_4 -> V_20 = V_28 ;
V_4 -> V_29 ( V_4 ) ;
F_36 ( V_18 ) ;
}
static void F_113 ( struct V_8 * V_9 ,
struct V_10 * V_107 )
{
struct V_7 * V_18 ;
T_1 V_44 , V_43 , * V_126 , type , V_127 , V_159 , V_52 ;
T_4 V_160 , V_130 ;
char * V_50 ;
T_2 V_51 ;
V_44 = F_65 ( V_107 ) ;
V_43 = F_67 ( V_107 ) ;
F_8 ( L_20 , V_44 , V_43 ) ;
if ( V_44 != V_73 || V_43 != V_73 ) {
F_41 ( L_33 ) ;
return;
}
V_126 = & V_107 -> V_48 [ V_129 ] ;
V_160 = V_107 -> V_119 - V_129 ;
V_130 = 0 ;
while ( V_130 < V_160 ) {
type = V_126 [ 0 ] ;
V_127 = V_126 [ 1 ] ;
switch ( type ) {
case V_161 :
V_159 = V_126 [ 2 ] ;
V_50 = ( char * ) & V_126 [ 3 ] ;
V_51 = V_127 - 1 ;
F_8 ( L_34 , V_50 ) ;
if ( V_51 == strlen ( L_35 ) &&
! strncmp ( V_50 , L_35 ,
V_51 ) ) {
V_52 = 1 ;
goto V_162;
}
V_18 = F_46 ( V_9 , V_50 ,
V_51 ) ;
if ( ! V_18 ) {
V_52 = 0 ;
goto V_162;
}
if ( V_18 -> V_43 == V_62 ) {
T_3 * V_145 ;
V_52 = F_59 ( V_9 ) ;
F_8 ( L_36 , V_52 ) ;
if ( V_52 == V_61 ) {
V_52 = 0 ;
goto V_162;
}
V_145 =
& V_9 -> V_71 [ V_52 -
V_63 ] ;
F_98 ( V_145 ) ;
V_18 -> V_43 = V_52 ;
V_18 -> V_146 = V_52 ;
} else {
V_52 = V_18 -> V_43 ;
}
F_8 ( L_37 , V_18 , V_52 ) ;
V_162:
F_114 ( V_9 , V_159 , V_52 ) ;
break;
default:
F_41 ( L_38 , type ) ;
break;
}
V_130 += V_127 + 2 ;
V_126 += V_127 + 2 ;
}
}
static void F_115 ( struct V_46 * V_47 )
{
struct V_8 * V_9 = F_26 ( V_47 , struct V_8 ,
V_38 ) ;
T_1 V_44 , V_43 , V_116 ;
struct V_10 * V_107 ;
V_107 = V_9 -> V_40 ;
if ( V_107 == NULL ) {
F_8 ( L_39 ) ;
return;
}
V_116 = F_66 ( V_107 ) ;
V_44 = F_65 ( V_107 ) ;
V_43 = F_67 ( V_107 ) ;
F_8 ( L_40 , V_116 , V_44 , V_43 ) ;
if ( V_116 != V_163 )
F_79 ( V_117 , L_41 , V_118 ,
16 , 1 , V_107 -> V_48 , V_107 -> V_119 , true ) ;
F_80 ( V_107 ) ;
F_71 ( V_9 , V_107 , V_164 ) ;
switch ( V_116 ) {
case V_163 :
F_8 ( L_42 ) ;
break;
case V_165 :
F_8 ( L_43 ) ;
F_88 ( V_9 , V_107 ) ;
break;
case V_166 :
F_8 ( L_44 ) ;
F_93 ( V_9 , V_107 ) ;
break;
case V_167 :
F_8 ( L_45 ) ;
F_110 ( V_9 , V_107 ) ;
break;
case V_168 :
F_8 ( L_46 ) ;
F_111 ( V_9 , V_107 ) ;
break;
case V_169 :
F_8 ( L_47 ) ;
F_112 ( V_9 , V_107 ) ;
break;
case V_170 :
F_8 ( L_48 ) ;
F_113 ( V_9 , V_107 ) ;
break;
case V_114 :
case V_156 :
case V_157 :
F_8 ( L_49 ) ;
F_106 ( V_9 , V_107 ) ;
break;
}
F_42 ( & V_9 -> V_37 ) ;
F_12 ( V_9 -> V_40 ) ;
V_9 -> V_40 = NULL ;
}
static void F_116 ( struct V_8 * V_9 , struct V_10 * V_107 )
{
V_9 -> V_40 = V_107 ;
F_117 ( & V_9 -> V_36 ) ;
F_42 ( & V_9 -> V_38 ) ;
}
void V_122 ( void * V_48 , struct V_10 * V_107 , int V_16 )
{
struct V_8 * V_9 = (struct V_8 * ) V_48 ;
F_8 ( L_50 ) ;
if ( V_16 < 0 ) {
F_41 ( L_51 , V_16 ) ;
return;
}
F_116 ( V_9 , V_107 ) ;
}
int F_118 ( struct V_49 * V_22 , struct V_10 * V_107 )
{
struct V_8 * V_9 ;
V_9 = F_43 ( V_22 ) ;
if ( V_9 == NULL )
return - V_100 ;
F_116 ( V_9 , V_107 ) ;
return 0 ;
}
void F_119 ( struct V_49 * V_22 )
{
struct V_8 * V_9 ;
V_9 = F_43 ( V_22 ) ;
if ( V_9 == NULL )
return;
F_13 ( V_9 , true , 0 ) ;
}
void F_120 ( struct V_49 * V_22 , T_5 V_121 ,
T_1 V_171 , T_1 V_172 )
{
struct V_8 * V_9 ;
F_8 ( L_52 , V_172 ) ;
V_9 = F_43 ( V_22 ) ;
if ( V_9 == NULL )
return;
V_9 -> V_121 = V_121 ;
V_9 -> V_171 = V_171 ;
V_9 -> V_172 = V_172 ;
if ( V_172 == V_173 ) {
F_8 ( L_53 ) ;
F_42 ( & V_9 -> V_37 ) ;
} else {
F_83 ( & V_9 -> V_36 ,
V_123 + F_84 ( V_9 -> V_124 ) ) ;
}
}
int F_121 ( struct V_49 * V_174 )
{
struct V_8 * V_9 ;
V_9 = F_122 ( sizeof( struct V_8 ) , V_175 ) ;
if ( V_9 == NULL )
return - V_176 ;
V_9 -> V_22 = V_174 ;
F_123 ( & V_9 -> V_42 ) ;
F_124 ( & V_9 -> V_34 ) ;
F_125 ( & V_9 -> V_59 ) ;
F_126 ( & V_9 -> V_36 ) ;
V_9 -> V_36 . V_48 = ( unsigned long ) V_9 ;
V_9 -> V_36 . V_177 = F_40 ;
F_127 ( & V_9 -> V_13 ) ;
F_128 ( & V_9 -> V_37 , F_76 ) ;
V_9 -> V_40 = NULL ;
F_128 ( & V_9 -> V_38 , F_115 ) ;
F_128 ( & V_9 -> V_39 , F_38 ) ;
F_129 ( & V_9 -> V_19 . V_5 ) ;
F_129 ( & V_9 -> V_125 . V_5 ) ;
F_129 ( & V_9 -> V_33 . V_5 ) ;
V_9 -> V_91 = 150 ;
V_9 -> V_150 = V_178 ;
V_9 -> V_94 = F_130 ( V_179 ) ;
F_60 ( V_9 ) ;
V_9 -> V_143 = V_180 ;
V_9 -> V_124 = V_181 ;
F_131 ( & V_9 -> V_42 , & V_182 ) ;
return 0 ;
}
void F_132 ( struct V_49 * V_22 )
{
struct V_8 * V_9 = F_43 ( V_22 ) ;
if ( V_9 == NULL ) {
F_8 ( L_54 ) ;
return;
}
F_22 ( V_9 , false ) ;
F_29 ( V_9 ) ;
}
int T_6 F_133 ( void )
{
F_123 ( & V_182 ) ;
return F_134 () ;
}
void F_135 ( void )
{
F_136 () ;
}
