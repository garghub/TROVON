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
static void F_7 ( struct V_7 * V_8 , bool V_9 )
{
struct V_3 * V_4 ;
struct V_10 * V_11 , * V_12 ;
struct V_13 * V_14 ;
F_2 ( & V_8 -> V_15 . V_5 ) ;
F_8 (sk, node, tmp, &local->sockets.head) {
V_14 = V_13 ( V_4 ) ;
F_9 ( V_4 ) ;
if ( V_4 -> V_16 == V_17 )
F_10 ( V_14 -> V_18 ) ;
if ( V_4 -> V_16 == V_19 ) {
struct V_13 * V_20 , * V_21 ;
struct V_3 * V_22 ;
F_11 (lsk, n, &llcp_sock->accept_queue,
accept_queue) {
V_22 = & V_20 -> V_4 ;
F_9 ( V_22 ) ;
F_12 ( V_22 ) ;
V_22 -> V_16 = V_23 ;
F_13 ( V_22 ) ;
F_14 ( V_22 ) ;
}
if ( V_9 == true ) {
F_13 ( V_4 ) ;
continue;
}
}
V_4 -> V_16 = V_23 ;
F_13 ( V_4 ) ;
F_14 ( V_4 ) ;
F_6 ( V_4 ) ;
}
F_4 ( & V_8 -> V_15 . V_5 ) ;
}
struct V_7 * F_15 ( struct V_7 * V_8 )
{
F_16 ( & V_8 -> V_24 ) ;
return V_8 ;
}
static void F_17 ( struct V_25 * V_24 )
{
struct V_7 * V_8 ;
V_8 = F_18 ( V_24 , struct V_7 , V_24 ) ;
F_19 ( & V_8 -> V_26 ) ;
F_7 ( V_8 , false ) ;
F_20 ( & V_8 -> V_27 ) ;
F_21 ( & V_8 -> V_28 ) ;
F_22 ( & V_8 -> V_29 ) ;
F_22 ( & V_8 -> V_30 ) ;
F_22 ( & V_8 -> V_31 ) ;
F_23 ( V_8 -> V_32 ) ;
F_24 ( V_8 ) ;
}
int F_25 ( struct V_7 * V_8 )
{
if ( V_8 == NULL )
return 0 ;
return F_26 ( & V_8 -> V_24 , F_17 ) ;
}
static struct V_13 * F_27 ( struct V_7 * V_8 ,
T_1 V_33 , T_1 V_34 )
{
struct V_3 * V_4 ;
struct V_10 * V_11 ;
struct V_13 * V_14 ;
F_28 ( L_1 , V_33 , V_34 ) ;
if ( V_33 == 0 && V_34 == 0 )
return NULL ;
F_29 ( & V_8 -> V_15 . V_5 ) ;
V_14 = NULL ;
F_30 (sk, node, &local->sockets.head) {
V_14 = V_13 ( V_4 ) ;
if ( V_14 -> V_33 == V_33 && V_14 -> V_34 == V_34 )
break;
}
F_31 ( & V_8 -> V_15 . V_5 ) ;
if ( V_14 == NULL )
return NULL ;
F_32 ( & V_14 -> V_4 ) ;
return V_14 ;
}
static void F_33 ( struct V_13 * V_3 )
{
F_34 ( & V_3 -> V_4 ) ;
}
static void F_35 ( struct V_35 * V_36 )
{
struct V_7 * V_8 = F_18 ( V_36 , struct V_7 ,
V_31 ) ;
F_36 ( V_8 -> V_18 ) ;
}
static void F_37 ( unsigned long V_37 )
{
struct V_7 * V_8 = (struct V_7 * ) V_37 ;
F_38 ( L_2 ) ;
F_39 ( & V_8 -> V_31 ) ;
}
struct V_7 * F_40 ( struct V_38 * V_18 )
{
struct V_7 * V_8 , * V_21 ;
F_11 (local, n, &llcp_devices, list)
if ( V_8 -> V_18 == V_18 )
return V_8 ;
F_28 ( L_3 ) ;
return NULL ;
}
static int F_41 ( char * V_39 , T_2 V_40 )
{
int V_41 , V_42 ;
F_28 ( L_4 , V_39 ) ;
if ( V_39 == NULL )
return - V_43 ;
V_42 = F_42 ( V_44 ) ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
if ( V_44 [ V_41 ] == NULL )
continue;
if ( strncmp ( V_44 [ V_41 ] , V_39 , V_40 ) == 0 )
return V_41 ;
}
return - V_43 ;
}
static
struct V_13 * F_43 ( struct V_7 * V_8 ,
T_1 * V_45 , T_2 V_46 )
{
struct V_3 * V_4 ;
struct V_10 * V_11 ;
struct V_13 * V_14 , * V_47 ;
F_28 ( L_5 , V_46 , V_45 ) ;
if ( V_45 == NULL || V_46 == 0 )
return NULL ;
F_29 ( & V_8 -> V_15 . V_5 ) ;
V_14 = NULL ;
F_30 (sk, node, &local->sockets.head) {
V_47 = V_13 ( V_4 ) ;
F_28 ( L_6 , V_47 ) ;
if ( V_47 -> V_4 . V_16 != V_19 )
continue;
if ( V_47 -> V_39 == NULL ||
V_47 -> V_40 == 0 )
continue;
if ( V_47 -> V_40 != V_46 )
continue;
if ( memcmp ( V_45 , V_47 -> V_39 , V_46 ) == 0 ) {
V_14 = V_47 ;
break;
}
}
F_31 ( & V_8 -> V_15 . V_5 ) ;
F_28 ( L_7 , V_14 ) ;
return V_14 ;
}
T_1 F_44 ( struct V_7 * V_8 ,
struct V_13 * V_3 )
{
F_45 ( & V_8 -> V_48 ) ;
if ( V_3 -> V_39 != NULL && V_3 -> V_40 > 0 ) {
int V_33 = F_41 ( V_3 -> V_39 ,
V_3 -> V_40 ) ;
if ( V_33 > 0 ) {
F_28 ( L_8 , V_33 ) ;
if ( V_8 -> V_49 & F_46 ( V_33 ) ) {
F_47 ( & V_8 -> V_48 ) ;
return V_50 ;
}
F_48 ( V_33 , & V_8 -> V_49 ) ;
F_47 ( & V_8 -> V_48 ) ;
return V_33 ;
}
if ( F_43 ( V_8 , V_3 -> V_39 ,
V_3 -> V_40 ) != NULL ) {
F_47 ( & V_8 -> V_48 ) ;
return V_50 ;
}
F_47 ( & V_8 -> V_48 ) ;
return V_51 ;
} else if ( V_3 -> V_33 != 0 && V_3 -> V_33 < V_52 ) {
if ( ! F_49 ( V_3 -> V_33 , & V_8 -> V_49 ) ) {
F_48 ( V_3 -> V_33 , & V_8 -> V_49 ) ;
F_47 ( & V_8 -> V_48 ) ;
return V_3 -> V_33 ;
}
}
F_47 ( & V_8 -> V_48 ) ;
return V_50 ;
}
T_1 F_50 ( struct V_7 * V_8 )
{
T_1 V_53 ;
F_45 ( & V_8 -> V_48 ) ;
V_53 = F_51 ( & V_8 -> V_54 , V_55 ) ;
if ( V_53 == V_55 ) {
F_47 ( & V_8 -> V_48 ) ;
return V_50 ;
}
F_48 ( V_53 , & V_8 -> V_54 ) ;
F_47 ( & V_8 -> V_48 ) ;
return V_53 + V_56 ;
}
void F_52 ( struct V_7 * V_8 , T_1 V_33 )
{
T_1 V_53 ;
unsigned long * V_57 ;
if ( V_33 < V_52 ) {
V_53 = V_33 ;
V_57 = & V_8 -> V_49 ;
} else if ( V_33 < V_55 ) {
T_3 * V_58 ;
V_53 = V_33 - V_52 ;
V_57 = & V_8 -> V_59 ;
V_58 = & V_8 -> V_60 [ V_53 ] ;
F_28 ( L_9 , F_53 ( V_58 ) ) ;
F_45 ( & V_8 -> V_48 ) ;
if ( F_54 ( V_58 ) ) {
struct V_13 * V_61 ;
F_28 ( L_10 , V_33 ) ;
F_55 ( V_53 , V_57 ) ;
V_61 = F_27 ( V_8 , V_33 , V_62 ) ;
if ( V_61 ) {
V_61 -> V_33 = V_51 ;
F_33 ( V_61 ) ;
}
}
F_47 ( & V_8 -> V_48 ) ;
return;
} else if ( V_33 < V_63 ) {
V_53 = V_33 - V_55 ;
V_57 = & V_8 -> V_54 ;
} else {
return;
}
F_45 ( & V_8 -> V_48 ) ;
F_55 ( V_53 , V_57 ) ;
F_47 ( & V_8 -> V_48 ) ;
}
static T_1 F_56 ( struct V_7 * V_8 )
{
T_1 V_33 ;
F_45 ( & V_8 -> V_48 ) ;
V_33 = F_51 ( & V_8 -> V_59 , V_64 ) ;
if ( V_33 == V_64 ) {
F_47 ( & V_8 -> V_48 ) ;
return V_50 ;
}
F_28 ( L_11 , V_52 + V_33 ) ;
F_48 ( V_33 , & V_8 -> V_59 ) ;
F_47 ( & V_8 -> V_48 ) ;
return V_52 + V_33 ;
}
static int F_57 ( struct V_7 * V_8 )
{
T_1 * V_65 , * V_66 , V_67 , V_68 ;
T_1 * V_69 , V_70 , V_71 ;
T_1 * V_72 , V_73 ;
T_1 * V_74 , V_75 ;
T_4 V_76 ;
T_1 V_77 = 0 ;
int V_78 = 0 ;
V_67 = V_79 ;
V_66 = F_58 ( V_80 , & V_67 ,
1 , & V_68 ) ;
V_77 += V_68 ;
V_70 = 150 ;
V_69 = F_58 ( V_81 , & V_70 , 1 , & V_71 ) ;
V_77 += V_71 ;
F_28 ( L_12 , V_8 -> V_49 ) ;
V_72 = F_58 ( V_82 , ( T_1 * ) & V_8 -> V_49 , 2 ,
& V_73 ) ;
V_77 += V_73 ;
V_76 = F_59 ( V_83 ) ;
V_74 = F_58 ( V_84 , ( T_1 * ) & V_76 , 0 ,
& V_75 ) ;
V_77 += V_75 ;
V_77 += F_42 ( V_85 ) ;
if ( V_77 > V_86 ) {
V_78 = - V_43 ;
goto V_87;
}
V_65 = V_8 -> V_88 ;
memcpy ( V_65 , V_85 , F_42 ( V_85 ) ) ;
V_65 += F_42 ( V_85 ) ;
memcpy ( V_65 , V_66 , V_68 ) ;
V_65 += V_68 ;
memcpy ( V_65 , V_69 , V_71 ) ;
V_65 += V_71 ;
memcpy ( V_65 , V_72 , V_73 ) ;
V_65 += V_73 ;
memcpy ( V_65 , V_74 , V_75 ) ;
V_65 += V_75 ;
V_8 -> V_77 = V_77 ;
V_87:
F_24 ( V_66 ) ;
F_24 ( V_69 ) ;
F_24 ( V_72 ) ;
F_24 ( V_74 ) ;
return V_78 ;
}
T_1 * F_60 ( struct V_38 * V_18 , T_2 * V_89 )
{
struct V_7 * V_8 ;
V_8 = F_40 ( V_18 ) ;
if ( V_8 == NULL ) {
* V_89 = 0 ;
return NULL ;
}
F_57 ( V_8 ) ;
* V_89 = V_8 -> V_77 ;
return V_8 -> V_88 ;
}
int F_61 ( struct V_38 * V_18 , T_1 * V_88 , T_1 V_77 )
{
struct V_7 * V_8 = F_40 ( V_18 ) ;
if ( V_8 == NULL ) {
F_38 ( L_13 ) ;
return - V_90 ;
}
memset ( V_8 -> V_91 , 0 , V_86 ) ;
memcpy ( V_8 -> V_91 , V_88 , V_77 ) ;
V_8 -> V_92 = V_77 ;
if ( V_8 -> V_91 == NULL || V_8 -> V_92 == 0 )
return - V_90 ;
if ( memcmp ( V_8 -> V_91 , V_85 , 3 ) ) {
F_38 ( L_14 ) ;
return - V_43 ;
}
return F_62 ( V_8 ,
& V_8 -> V_91 [ 3 ] ,
V_8 -> V_92 - 3 ) ;
}
static T_1 F_63 ( struct V_93 * V_94 )
{
return ( V_94 -> V_37 [ 0 ] & 0xfc ) >> 2 ;
}
static T_1 F_64 ( struct V_93 * V_94 )
{
return ( ( V_94 -> V_37 [ 0 ] & 0x03 ) << 2 ) | ( ( V_94 -> V_37 [ 1 ] & 0xc0 ) >> 6 ) ;
}
static T_1 F_65 ( struct V_93 * V_94 )
{
return V_94 -> V_37 [ 1 ] & 0x3f ;
}
static T_1 F_66 ( struct V_93 * V_94 )
{
return V_94 -> V_37 [ 2 ] >> 4 ;
}
static T_1 F_67 ( struct V_93 * V_94 )
{
return V_94 -> V_37 [ 2 ] & 0xf ;
}
static void F_68 ( struct V_13 * V_3 , struct V_93 * V_94 )
{
V_94 -> V_37 [ 2 ] = ( V_3 -> V_95 << 4 ) | ( V_3 -> V_96 ) ;
V_3 -> V_95 = ( V_3 -> V_95 + 1 ) % 16 ;
V_3 -> V_97 = ( V_3 -> V_96 - 1 ) % 16 ;
}
void F_69 ( struct V_7 * V_8 ,
struct V_93 * V_98 , T_1 V_99 )
{
struct V_10 * V_11 ;
struct V_93 * V_100 = NULL , * V_101 ;
struct V_3 * V_4 ;
T_1 * V_37 ;
F_29 ( & V_8 -> V_102 . V_5 ) ;
F_30 (sk, node, &local->raw_sockets.head) {
if ( V_4 -> V_16 != V_103 )
continue;
if ( V_100 == NULL ) {
V_100 = F_70 ( V_98 , V_104 ,
V_105 ) ;
if ( V_100 == NULL )
continue;
V_37 = F_71 ( V_100 , V_104 ) ;
V_37 [ 0 ] = V_8 -> V_18 ? V_8 -> V_18 -> V_106 : 0xFF ;
V_37 [ 1 ] = V_99 ;
}
V_101 = F_72 ( V_100 , V_105 ) ;
if ( ! V_101 )
continue;
if ( F_73 ( V_4 , V_101 ) )
F_23 ( V_101 ) ;
}
F_31 ( & V_8 -> V_102 . V_5 ) ;
F_23 ( V_100 ) ;
}
static void F_74 ( struct V_35 * V_36 )
{
struct V_7 * V_8 = F_18 ( V_36 , struct V_7 ,
V_29 ) ;
struct V_93 * V_98 ;
struct V_3 * V_4 ;
struct V_13 * V_14 ;
V_98 = F_75 ( & V_8 -> V_28 ) ;
if ( V_98 != NULL ) {
V_4 = V_98 -> V_4 ;
V_14 = V_13 ( V_4 ) ;
if ( V_14 != NULL ) {
int V_78 ;
F_28 ( L_15 ) ;
F_76 ( V_107 , L_16 ,
V_108 , 16 , 1 ,
V_98 -> V_37 , V_98 -> V_109 , true ) ;
F_69 ( V_8 , V_98 ,
V_110 ) ;
V_78 = F_77 ( V_8 -> V_18 , V_8 -> V_111 ,
V_98 , V_112 , V_8 ) ;
if ( ! V_78 && F_64 ( V_98 ) == V_113 ) {
V_98 = F_78 ( V_98 ) ;
F_79 ( & V_14 -> V_114 ,
V_98 ) ;
}
} else {
F_80 ( V_8 -> V_18 ) ;
}
} else {
F_80 ( V_8 -> V_18 ) ;
}
F_81 ( & V_8 -> V_27 ,
V_115 + F_82 ( 2 * V_8 -> V_116 ) ) ;
}
static struct V_13 * F_83 ( struct V_7 * V_8 ,
T_1 V_33 )
{
struct V_3 * V_4 ;
struct V_13 * V_14 ;
struct V_10 * V_11 ;
F_29 ( & V_8 -> V_117 . V_5 ) ;
F_30 (sk, node, &local->connecting_sockets.head) {
V_14 = V_13 ( V_4 ) ;
if ( V_14 -> V_33 == V_33 ) {
F_32 ( & V_14 -> V_4 ) ;
goto V_87;
}
}
V_14 = NULL ;
V_87:
F_31 ( & V_8 -> V_117 . V_5 ) ;
return V_14 ;
}
static struct V_13 * F_84 ( struct V_7 * V_8 ,
T_1 * V_45 , T_2 V_46 )
{
struct V_13 * V_14 ;
V_14 = F_43 ( V_8 , V_45 , V_46 ) ;
if ( V_14 == NULL )
return NULL ;
F_32 ( & V_14 -> V_4 ) ;
return V_14 ;
}
static T_1 * F_85 ( struct V_93 * V_98 , T_2 * V_46 )
{
T_1 * V_118 = & V_98 -> V_37 [ 2 ] , type , V_119 ;
T_2 V_120 = V_98 -> V_109 - V_121 , V_122 = 0 ;
while ( V_122 < V_120 ) {
type = V_118 [ 0 ] ;
V_119 = V_118 [ 1 ] ;
F_28 ( L_17 , type , V_119 ) ;
if ( type == V_123 ) {
* V_46 = V_119 ;
return & V_118 [ 2 ] ;
}
V_122 += V_119 + 2 ;
V_118 += V_119 + 2 ;
}
return NULL ;
}
static void F_86 ( struct V_7 * V_8 ,
struct V_93 * V_98 )
{
struct V_3 * V_124 , * V_125 ;
struct V_13 * V_3 , * V_126 ;
T_1 V_34 , V_33 , V_127 ;
V_34 = F_63 ( V_98 ) ;
V_33 = F_65 ( V_98 ) ;
F_28 ( L_18 , V_34 , V_33 ) ;
if ( V_34 != V_62 ) {
V_3 = F_27 ( V_8 , V_34 , V_62 ) ;
if ( V_3 == NULL || V_3 -> V_4 . V_16 != V_19 ) {
V_127 = V_128 ;
goto V_129;
}
} else {
T_1 * V_45 ;
T_2 V_46 ;
V_45 = F_85 ( V_98 , & V_46 ) ;
if ( V_45 == NULL ) {
V_127 = V_128 ;
goto V_129;
}
F_28 ( L_19 , V_46 ) ;
V_3 = F_84 ( V_8 , V_45 , V_46 ) ;
if ( V_3 == NULL ) {
V_127 = V_128 ;
goto V_129;
}
}
F_87 ( & V_3 -> V_4 ) ;
V_125 = & V_3 -> V_4 ;
if ( F_88 ( V_125 ) ) {
V_127 = V_130 ;
F_89 ( & V_3 -> V_4 ) ;
F_34 ( & V_3 -> V_4 ) ;
goto V_129;
}
if ( V_3 -> V_33 == V_51 ) {
T_1 V_33 = F_56 ( V_8 ) ;
F_28 ( L_20 , V_33 ) ;
if ( V_33 == V_50 ) {
V_127 = V_130 ;
F_89 ( & V_3 -> V_4 ) ;
F_34 ( & V_3 -> V_4 ) ;
goto V_129;
}
V_3 -> V_33 = V_33 ;
}
V_124 = F_90 ( NULL , V_125 -> V_131 , V_105 ) ;
if ( V_124 == NULL ) {
V_127 = V_130 ;
F_89 ( & V_3 -> V_4 ) ;
F_34 ( & V_3 -> V_4 ) ;
goto V_129;
}
V_126 = V_13 ( V_124 ) ;
V_126 -> V_18 = V_8 -> V_18 ;
V_126 -> V_8 = F_15 ( V_8 ) ;
V_126 -> V_132 = V_8 -> V_133 ;
V_126 -> V_134 = V_3 -> V_134 ;
V_126 -> V_34 = V_33 ;
V_126 -> V_111 = V_8 -> V_111 ;
V_126 -> V_125 = V_125 ;
V_126 -> V_33 = V_3 -> V_33 ;
if ( V_3 -> V_33 < V_55 && V_3 -> V_33 >= V_52 ) {
T_3 * V_135 ;
F_28 ( L_21 , V_3 -> V_33 , V_126 ) ;
V_135 =
& V_8 -> V_60 [ V_3 -> V_33 - V_52 ] ;
F_91 ( V_135 ) ;
V_126 -> V_136 = V_3 -> V_33 ;
}
F_92 ( V_126 , & V_98 -> V_37 [ V_121 ] ,
V_98 -> V_109 - V_121 ) ;
F_28 ( L_22 , V_126 , & V_126 -> V_4 ) ;
F_1 ( & V_8 -> V_15 , V_124 ) ;
F_93 ( & V_3 -> V_4 , V_124 ) ;
F_94 ( V_8 -> V_18 -> V_106 ) ;
V_124 -> V_16 = V_17 ;
V_125 -> V_137 ( V_125 , 0 ) ;
F_95 ( V_126 ) ;
F_89 ( & V_3 -> V_4 ) ;
F_34 ( & V_3 -> V_4 ) ;
return;
V_129:
F_96 ( V_8 , V_34 , V_33 , V_127 ) ;
return;
}
int F_97 ( struct V_13 * V_3 )
{
int V_138 = 0 ;
struct V_7 * V_8 = V_3 -> V_8 ;
F_28 ( L_23 ,
V_3 -> V_139 , F_98 ( & V_3 -> V_114 ) ,
V_3 -> V_140 ) ;
while ( V_3 -> V_139 &&
F_98 ( & V_3 -> V_114 ) < V_3 -> V_140 ) {
struct V_93 * V_94 ;
V_94 = F_75 ( & V_3 -> V_28 ) ;
if ( V_94 == NULL )
break;
F_68 ( V_3 , V_94 ) ;
F_79 ( & V_8 -> V_28 , V_94 ) ;
V_138 ++ ;
}
return V_138 ;
}
static void F_99 ( struct V_7 * V_8 ,
struct V_93 * V_98 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
T_1 V_34 , V_33 , V_141 , V_142 , V_143 ;
V_141 = F_64 ( V_98 ) ;
V_34 = F_63 ( V_98 ) ;
V_33 = F_65 ( V_98 ) ;
V_142 = F_66 ( V_98 ) ;
V_143 = F_67 ( V_98 ) ;
F_28 ( L_24 , V_34 , V_33 , V_143 , V_142 ) ;
V_14 = F_27 ( V_8 , V_34 , V_33 ) ;
if ( V_14 == NULL ) {
F_96 ( V_8 , V_34 , V_33 , V_144 ) ;
return;
}
V_4 = & V_14 -> V_4 ;
F_87 ( V_4 ) ;
if ( V_4 -> V_16 == V_23 ) {
F_89 ( V_4 ) ;
F_33 ( V_14 ) ;
}
if ( V_141 == V_113 ) {
F_28 ( L_25 , & V_14 -> V_4 ) ;
if ( V_142 == V_14 -> V_96 )
V_14 -> V_96 = ( V_14 -> V_96 + 1 ) % 16 ;
else
F_38 ( L_26 ) ;
F_100 ( V_98 , V_121 + V_145 ) ;
if ( F_73 ( & V_14 -> V_4 , V_98 ) ) {
F_38 ( L_27 ) ;
F_101 ( & V_14 -> V_146 , V_98 ) ;
}
}
if ( V_14 -> V_147 != V_143 ) {
struct V_93 * V_148 , * V_12 ;
V_14 -> V_147 = V_143 ;
F_102 (&llcp_sock->tx_pending_queue, s, tmp) {
F_103 ( V_148 , & V_14 -> V_114 ) ;
F_23 ( V_148 ) ;
if ( F_66 ( V_148 ) == V_143 )
break;
}
F_104 (&llcp_sock->tx_pending_queue,
s, tmp) {
F_103 ( V_148 , & V_14 -> V_114 ) ;
F_101 ( & V_8 -> V_28 , V_148 ) ;
}
}
if ( V_141 == V_149 )
V_14 -> V_139 = true ;
else if ( V_141 == V_150 )
V_14 -> V_139 = false ;
if ( F_97 ( V_14 ) == 0 && V_141 == V_113 )
F_105 ( V_14 ) ;
F_89 ( V_4 ) ;
F_33 ( V_14 ) ;
}
static void F_106 ( struct V_7 * V_8 ,
struct V_93 * V_98 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
T_1 V_34 , V_33 ;
V_34 = F_63 ( V_98 ) ;
V_33 = F_65 ( V_98 ) ;
V_14 = F_27 ( V_8 , V_34 , V_33 ) ;
if ( V_14 == NULL ) {
F_96 ( V_8 , V_34 , V_33 , V_144 ) ;
return;
}
V_4 = & V_14 -> V_4 ;
F_87 ( V_4 ) ;
if ( V_4 -> V_16 == V_23 ) {
F_89 ( V_4 ) ;
F_33 ( V_14 ) ;
}
if ( V_4 -> V_16 == V_17 ) {
F_10 ( V_8 -> V_18 ) ;
V_4 -> V_16 = V_23 ;
V_4 -> V_151 ( V_4 ) ;
}
F_96 ( V_8 , V_34 , V_33 , V_152 ) ;
F_89 ( V_4 ) ;
F_33 ( V_14 ) ;
}
static void F_107 ( struct V_7 * V_8 , struct V_93 * V_98 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
T_1 V_34 , V_33 ;
V_34 = F_63 ( V_98 ) ;
V_33 = F_65 ( V_98 ) ;
V_14 = F_83 ( V_8 , V_34 ) ;
if ( V_14 == NULL ) {
F_38 ( L_28 ) ;
F_96 ( V_8 , V_34 , V_33 , V_144 ) ;
return;
}
V_4 = & V_14 -> V_4 ;
F_5 ( & V_8 -> V_117 , V_4 ) ;
F_1 ( & V_8 -> V_15 , V_4 ) ;
V_14 -> V_34 = V_33 ;
F_92 ( V_14 , & V_98 -> V_37 [ V_121 ] ,
V_98 -> V_109 - V_121 ) ;
V_4 -> V_16 = V_17 ;
V_4 -> V_151 ( V_4 ) ;
F_33 ( V_14 ) ;
}
static void F_108 ( struct V_7 * V_8 , struct V_93 * V_98 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
T_1 V_34 , V_33 , V_127 ;
V_34 = F_63 ( V_98 ) ;
V_33 = F_65 ( V_98 ) ;
V_127 = V_98 -> V_37 [ 2 ] ;
F_28 ( L_29 , V_33 , V_34 , V_127 ) ;
switch ( V_127 ) {
case V_128 :
case V_130 :
V_14 = F_83 ( V_8 , V_34 ) ;
break;
default:
V_14 = F_27 ( V_8 , V_34 , V_33 ) ;
break;
}
if ( V_14 == NULL ) {
F_38 ( L_30 ) ;
return;
}
V_4 = & V_14 -> V_4 ;
V_4 -> V_153 = V_154 ;
V_4 -> V_16 = V_23 ;
V_4 -> V_151 ( V_4 ) ;
F_33 ( V_14 ) ;
return;
}
static void F_109 ( struct V_35 * V_36 )
{
struct V_7 * V_8 = F_18 ( V_36 , struct V_7 ,
V_30 ) ;
T_1 V_34 , V_33 , V_141 ;
struct V_93 * V_98 ;
V_98 = V_8 -> V_32 ;
if ( V_98 == NULL ) {
F_28 ( L_31 ) ;
return;
}
V_141 = F_64 ( V_98 ) ;
V_34 = F_63 ( V_98 ) ;
V_33 = F_65 ( V_98 ) ;
F_28 ( L_32 , V_141 , V_34 , V_33 ) ;
if ( V_141 != V_155 )
F_76 ( V_107 , L_33 , V_108 ,
16 , 1 , V_98 -> V_37 , V_98 -> V_109 , true ) ;
F_69 ( V_8 , V_98 , V_156 ) ;
switch ( V_141 ) {
case V_155 :
F_28 ( L_34 ) ;
break;
case V_157 :
F_28 ( L_35 ) ;
F_86 ( V_8 , V_98 ) ;
break;
case V_158 :
F_28 ( L_36 ) ;
F_106 ( V_8 , V_98 ) ;
break;
case V_159 :
F_28 ( L_37 ) ;
F_107 ( V_8 , V_98 ) ;
break;
case V_160 :
F_28 ( L_38 ) ;
F_108 ( V_8 , V_98 ) ;
break;
case V_113 :
case V_149 :
case V_150 :
F_28 ( L_39 ) ;
F_99 ( V_8 , V_98 ) ;
break;
}
F_39 ( & V_8 -> V_29 ) ;
F_23 ( V_8 -> V_32 ) ;
V_8 -> V_32 = NULL ;
return;
}
void V_112 ( void * V_37 , struct V_93 * V_98 , int V_161 )
{
struct V_7 * V_8 = (struct V_7 * ) V_37 ;
F_28 ( L_40 ) ;
if ( V_161 < 0 ) {
F_38 ( L_41 , V_161 ) ;
return;
}
V_8 -> V_32 = F_78 ( V_98 ) ;
F_110 ( & V_8 -> V_27 ) ;
F_39 ( & V_8 -> V_30 ) ;
return;
}
int F_111 ( struct V_38 * V_18 , struct V_93 * V_98 )
{
struct V_7 * V_8 ;
V_8 = F_40 ( V_18 ) ;
if ( V_8 == NULL )
return - V_90 ;
V_8 -> V_32 = F_78 ( V_98 ) ;
F_110 ( & V_8 -> V_27 ) ;
F_39 ( & V_8 -> V_30 ) ;
return 0 ;
}
void F_112 ( struct V_38 * V_18 )
{
struct V_7 * V_8 ;
V_8 = F_40 ( V_18 ) ;
if ( V_8 == NULL )
return;
F_7 ( V_8 , true ) ;
}
void F_113 ( struct V_38 * V_18 , T_5 V_111 ,
T_1 V_162 , T_1 V_163 )
{
struct V_7 * V_8 ;
F_28 ( L_42 , V_163 ) ;
V_8 = F_40 ( V_18 ) ;
if ( V_8 == NULL )
return;
V_8 -> V_111 = V_111 ;
V_8 -> V_162 = V_162 ;
V_8 -> V_163 = V_163 ;
if ( V_163 == V_164 ) {
F_28 ( L_43 ) ;
F_39 ( & V_8 -> V_29 ) ;
} else {
F_81 ( & V_8 -> V_27 ,
V_115 + F_82 ( V_8 -> V_116 ) ) ;
}
}
int F_114 ( struct V_38 * V_165 )
{
struct V_7 * V_8 ;
V_8 = F_115 ( sizeof( struct V_7 ) , V_166 ) ;
if ( V_8 == NULL )
return - V_167 ;
V_8 -> V_18 = V_165 ;
F_116 ( & V_8 -> V_26 ) ;
F_117 ( & V_8 -> V_24 ) ;
F_118 ( & V_8 -> V_48 ) ;
F_119 ( & V_8 -> V_27 ) ;
V_8 -> V_27 . V_37 = ( unsigned long ) V_8 ;
V_8 -> V_27 . V_168 = F_37 ;
F_120 ( & V_8 -> V_28 ) ;
F_121 ( & V_8 -> V_29 , F_74 ) ;
V_8 -> V_32 = NULL ;
F_121 ( & V_8 -> V_30 , F_109 ) ;
F_121 ( & V_8 -> V_31 , F_35 ) ;
F_122 ( & V_8 -> V_15 . V_5 ) ;
F_122 ( & V_8 -> V_117 . V_5 ) ;
F_122 ( & V_8 -> V_102 . V_5 ) ;
F_57 ( V_8 ) ;
V_8 -> V_133 = V_169 ;
V_8 -> V_116 = V_170 ;
F_123 ( & V_8 -> V_26 , & V_171 ) ;
return 0 ;
}
void F_124 ( struct V_38 * V_18 )
{
struct V_7 * V_8 = F_40 ( V_18 ) ;
if ( V_8 == NULL ) {
F_28 ( L_44 ) ;
return;
}
F_25 ( V_8 ) ;
}
int T_6 F_125 ( void )
{
F_116 ( & V_171 ) ;
return F_126 () ;
}
void F_127 ( void )
{
F_128 () ;
}
