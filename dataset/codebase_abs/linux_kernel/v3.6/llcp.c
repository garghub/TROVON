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
F_22 ( V_8 -> V_29 ) ;
F_22 ( V_8 -> V_30 ) ;
F_22 ( V_8 -> V_31 ) ;
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
V_37 ) ;
F_36 ( V_8 -> V_18 ) ;
}
static void F_37 ( unsigned long V_38 )
{
struct V_7 * V_8 = (struct V_7 * ) V_38 ;
F_38 ( L_2 ) ;
F_39 ( V_8 -> V_31 , & V_8 -> V_37 ) ;
}
struct V_7 * F_40 ( struct V_39 * V_18 )
{
struct V_7 * V_8 , * V_21 ;
F_11 (local, n, &llcp_devices, list)
if ( V_8 -> V_18 == V_18 )
return V_8 ;
F_28 ( L_3 ) ;
return NULL ;
}
static int F_41 ( char * V_40 , T_2 V_41 )
{
int V_42 , V_43 ;
F_28 ( L_4 , V_40 ) ;
if ( V_40 == NULL )
return - V_44 ;
V_43 = F_42 ( V_45 ) ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
if ( V_45 [ V_42 ] == NULL )
continue;
if ( strncmp ( V_45 [ V_42 ] , V_40 , V_41 ) == 0 )
return V_42 ;
}
return - V_44 ;
}
static
struct V_13 * F_43 ( struct V_7 * V_8 ,
T_1 * V_46 , T_2 V_47 )
{
struct V_3 * V_4 ;
struct V_10 * V_11 ;
struct V_13 * V_14 , * V_48 ;
F_28 ( L_5 , V_47 , V_46 ) ;
if ( V_46 == NULL || V_47 == 0 )
return NULL ;
F_29 ( & V_8 -> V_15 . V_5 ) ;
V_14 = NULL ;
F_30 (sk, node, &local->sockets.head) {
V_48 = V_13 ( V_4 ) ;
F_28 ( L_6 , V_48 ) ;
if ( V_48 -> V_4 . V_16 != V_19 )
continue;
if ( V_48 -> V_40 == NULL ||
V_48 -> V_41 == 0 )
continue;
if ( V_48 -> V_41 != V_47 )
continue;
if ( memcmp ( V_46 , V_48 -> V_40 , V_47 ) == 0 ) {
V_14 = V_48 ;
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
F_45 ( & V_8 -> V_49 ) ;
if ( V_3 -> V_40 != NULL && V_3 -> V_41 > 0 ) {
int V_33 = F_41 ( V_3 -> V_40 ,
V_3 -> V_41 ) ;
if ( V_33 > 0 ) {
F_28 ( L_8 , V_33 ) ;
if ( V_8 -> V_50 & F_46 ( V_33 ) ) {
F_47 ( & V_8 -> V_49 ) ;
return V_51 ;
}
F_48 ( V_33 , & V_8 -> V_50 ) ;
F_47 ( & V_8 -> V_49 ) ;
return V_33 ;
}
if ( F_43 ( V_8 , V_3 -> V_40 ,
V_3 -> V_41 ) != NULL ) {
F_47 ( & V_8 -> V_49 ) ;
return V_51 ;
}
F_47 ( & V_8 -> V_49 ) ;
return V_52 ;
} else if ( V_3 -> V_33 != 0 && V_3 -> V_33 < V_53 ) {
if ( ! F_49 ( V_3 -> V_33 , & V_8 -> V_50 ) ) {
F_48 ( V_3 -> V_33 , & V_8 -> V_50 ) ;
F_47 ( & V_8 -> V_49 ) ;
return V_3 -> V_33 ;
}
}
F_47 ( & V_8 -> V_49 ) ;
return V_51 ;
}
T_1 F_50 ( struct V_7 * V_8 )
{
T_1 V_54 ;
F_45 ( & V_8 -> V_49 ) ;
V_54 = F_51 ( & V_8 -> V_55 , V_56 ) ;
if ( V_54 == V_56 ) {
F_47 ( & V_8 -> V_49 ) ;
return V_51 ;
}
F_48 ( V_54 , & V_8 -> V_55 ) ;
F_47 ( & V_8 -> V_49 ) ;
return V_54 + V_57 ;
}
void F_52 ( struct V_7 * V_8 , T_1 V_33 )
{
T_1 V_54 ;
unsigned long * V_58 ;
if ( V_33 < V_53 ) {
V_54 = V_33 ;
V_58 = & V_8 -> V_50 ;
} else if ( V_33 < V_56 ) {
T_3 * V_59 ;
V_54 = V_33 - V_53 ;
V_58 = & V_8 -> V_60 ;
V_59 = & V_8 -> V_61 [ V_54 ] ;
F_28 ( L_9 , F_53 ( V_59 ) ) ;
F_45 ( & V_8 -> V_49 ) ;
if ( F_54 ( V_59 ) ) {
struct V_13 * V_62 ;
F_28 ( L_10 , V_33 ) ;
F_55 ( V_54 , V_58 ) ;
V_62 = F_27 ( V_8 , V_33 , V_63 ) ;
if ( V_62 ) {
V_62 -> V_33 = V_52 ;
F_33 ( V_62 ) ;
}
}
F_47 ( & V_8 -> V_49 ) ;
return;
} else if ( V_33 < V_64 ) {
V_54 = V_33 - V_56 ;
V_58 = & V_8 -> V_55 ;
} else {
return;
}
F_45 ( & V_8 -> V_49 ) ;
F_55 ( V_54 , V_58 ) ;
F_47 ( & V_8 -> V_49 ) ;
}
static T_1 F_56 ( struct V_7 * V_8 )
{
T_1 V_33 ;
F_45 ( & V_8 -> V_49 ) ;
V_33 = F_51 ( & V_8 -> V_60 , V_65 ) ;
if ( V_33 == V_65 ) {
F_47 ( & V_8 -> V_49 ) ;
return V_51 ;
}
F_28 ( L_11 , V_53 + V_33 ) ;
F_48 ( V_33 , & V_8 -> V_60 ) ;
F_47 ( & V_8 -> V_49 ) ;
return V_53 + V_33 ;
}
static int F_57 ( struct V_7 * V_8 )
{
T_1 * V_66 , * V_67 , V_68 , V_69 ;
T_1 * V_70 , V_71 , V_72 ;
T_1 * V_73 , V_74 ;
T_1 * V_75 , V_76 ;
T_4 V_77 ;
T_1 V_78 = 0 ;
V_68 = V_79 ;
V_67 = F_58 ( V_80 , & V_68 ,
1 , & V_69 ) ;
V_78 += V_69 ;
V_71 = 150 ;
V_70 = F_58 ( V_81 , & V_71 , 1 , & V_72 ) ;
V_78 += V_72 ;
F_28 ( L_12 , V_8 -> V_50 ) ;
V_73 = F_58 ( V_82 , ( T_1 * ) & V_8 -> V_50 , 2 ,
& V_74 ) ;
V_78 += V_74 ;
V_77 = F_59 ( V_83 ) ;
V_75 = F_58 ( V_84 , ( T_1 * ) & V_77 , 0 ,
& V_76 ) ;
V_78 += V_76 ;
V_78 += F_42 ( V_85 ) ;
if ( V_78 > V_86 ) {
F_24 ( V_67 ) ;
return - V_44 ;
}
V_66 = V_8 -> V_87 ;
memcpy ( V_66 , V_85 , F_42 ( V_85 ) ) ;
V_66 += F_42 ( V_85 ) ;
memcpy ( V_66 , V_67 , V_69 ) ;
V_66 += V_69 ;
memcpy ( V_66 , V_70 , V_72 ) ;
V_66 += V_72 ;
memcpy ( V_66 , V_73 , V_74 ) ;
V_66 += V_74 ;
memcpy ( V_66 , V_75 , V_76 ) ;
V_66 += V_76 ;
F_24 ( V_67 ) ;
F_24 ( V_70 ) ;
V_8 -> V_78 = V_78 ;
return 0 ;
}
T_1 * F_60 ( struct V_39 * V_18 , T_2 * V_88 )
{
struct V_7 * V_8 ;
V_8 = F_40 ( V_18 ) ;
if ( V_8 == NULL ) {
* V_88 = 0 ;
return NULL ;
}
F_57 ( V_8 ) ;
* V_88 = V_8 -> V_78 ;
return V_8 -> V_87 ;
}
int F_61 ( struct V_39 * V_18 , T_1 * V_87 , T_1 V_78 )
{
struct V_7 * V_8 = F_40 ( V_18 ) ;
if ( V_8 == NULL ) {
F_38 ( L_13 ) ;
return - V_89 ;
}
memset ( V_8 -> V_90 , 0 , V_86 ) ;
memcpy ( V_8 -> V_90 , V_87 , V_78 ) ;
V_8 -> V_91 = V_78 ;
if ( V_8 -> V_90 == NULL || V_8 -> V_91 == 0 )
return - V_89 ;
if ( memcmp ( V_8 -> V_90 , V_85 , 3 ) ) {
F_38 ( L_14 ) ;
return - V_44 ;
}
return F_62 ( V_8 ,
& V_8 -> V_90 [ 3 ] ,
V_8 -> V_91 - 3 ) ;
}
static T_1 F_63 ( struct V_92 * V_93 )
{
return ( V_93 -> V_38 [ 0 ] & 0xfc ) >> 2 ;
}
static T_1 F_64 ( struct V_92 * V_93 )
{
return ( ( V_93 -> V_38 [ 0 ] & 0x03 ) << 2 ) | ( ( V_93 -> V_38 [ 1 ] & 0xc0 ) >> 6 ) ;
}
static T_1 F_65 ( struct V_92 * V_93 )
{
return V_93 -> V_38 [ 1 ] & 0x3f ;
}
static T_1 F_66 ( struct V_92 * V_93 )
{
return V_93 -> V_38 [ 2 ] >> 4 ;
}
static T_1 F_67 ( struct V_92 * V_93 )
{
return V_93 -> V_38 [ 2 ] & 0xf ;
}
static void F_68 ( struct V_13 * V_3 , struct V_92 * V_93 )
{
V_93 -> V_38 [ 2 ] = ( V_3 -> V_94 << 4 ) | ( V_3 -> V_95 ) ;
V_3 -> V_94 = ( V_3 -> V_94 + 1 ) % 16 ;
V_3 -> V_96 = ( V_3 -> V_95 - 1 ) % 16 ;
}
static void F_69 ( struct V_35 * V_36 )
{
struct V_7 * V_8 = F_18 ( V_36 , struct V_7 ,
V_97 ) ;
struct V_92 * V_98 ;
struct V_3 * V_4 ;
struct V_13 * V_14 ;
V_98 = F_70 ( & V_8 -> V_28 ) ;
if ( V_98 != NULL ) {
V_4 = V_98 -> V_4 ;
V_14 = V_13 ( V_4 ) ;
if ( V_14 != NULL ) {
int V_99 ;
F_28 ( L_15 ) ;
F_71 ( V_100 , L_16 ,
V_101 , 16 , 1 ,
V_98 -> V_38 , V_98 -> V_102 , true ) ;
V_99 = F_72 ( V_8 -> V_18 , V_8 -> V_103 ,
V_98 , V_104 , V_8 ) ;
if ( ! V_99 && F_64 ( V_98 ) == V_105 ) {
V_98 = F_73 ( V_98 ) ;
F_74 ( & V_14 -> V_106 ,
V_98 ) ;
}
} else {
F_75 ( V_8 -> V_18 ) ;
}
} else {
F_75 ( V_8 -> V_18 ) ;
}
F_76 ( & V_8 -> V_27 ,
V_107 + F_77 ( 2 * V_8 -> V_108 ) ) ;
}
static struct V_13 * F_78 ( struct V_7 * V_8 ,
T_1 V_33 )
{
struct V_3 * V_4 ;
struct V_13 * V_14 ;
struct V_10 * V_11 ;
F_29 ( & V_8 -> V_109 . V_5 ) ;
F_30 (sk, node, &local->connecting_sockets.head) {
V_14 = V_13 ( V_4 ) ;
if ( V_14 -> V_33 == V_33 ) {
F_32 ( & V_14 -> V_4 ) ;
goto V_110;
}
}
V_14 = NULL ;
V_110:
F_31 ( & V_8 -> V_109 . V_5 ) ;
return V_14 ;
}
static struct V_13 * F_79 ( struct V_7 * V_8 ,
T_1 * V_46 , T_2 V_47 )
{
struct V_13 * V_14 ;
V_14 = F_43 ( V_8 , V_46 , V_47 ) ;
if ( V_14 == NULL )
return NULL ;
F_32 ( & V_14 -> V_4 ) ;
return V_14 ;
}
static T_1 * F_80 ( struct V_92 * V_98 , T_2 * V_47 )
{
T_1 * V_111 = & V_98 -> V_38 [ 2 ] , type , V_112 ;
T_2 V_113 = V_98 -> V_102 - V_114 , V_115 = 0 ;
while ( V_115 < V_113 ) {
type = V_111 [ 0 ] ;
V_112 = V_111 [ 1 ] ;
F_28 ( L_17 , type , V_112 ) ;
if ( type == V_116 ) {
* V_47 = V_112 ;
return & V_111 [ 2 ] ;
}
V_115 += V_112 + 2 ;
V_111 += V_112 + 2 ;
}
return NULL ;
}
static void F_81 ( struct V_7 * V_8 ,
struct V_92 * V_98 )
{
struct V_3 * V_117 , * V_118 ;
struct V_13 * V_3 , * V_119 ;
T_1 V_34 , V_33 , V_120 ;
V_34 = F_63 ( V_98 ) ;
V_33 = F_65 ( V_98 ) ;
F_28 ( L_18 , V_34 , V_33 ) ;
if ( V_34 != V_63 ) {
V_3 = F_27 ( V_8 , V_34 , V_63 ) ;
if ( V_3 == NULL || V_3 -> V_4 . V_16 != V_19 ) {
V_120 = V_121 ;
goto V_122;
}
} else {
T_1 * V_46 ;
T_2 V_47 ;
V_46 = F_80 ( V_98 , & V_47 ) ;
if ( V_46 == NULL ) {
V_120 = V_121 ;
goto V_122;
}
F_28 ( L_19 , V_47 ) ;
V_3 = F_79 ( V_8 , V_46 , V_47 ) ;
if ( V_3 == NULL ) {
V_120 = V_121 ;
goto V_122;
}
}
F_9 ( & V_3 -> V_4 ) ;
V_118 = & V_3 -> V_4 ;
if ( F_82 ( V_118 ) ) {
V_120 = V_123 ;
F_13 ( & V_3 -> V_4 ) ;
F_34 ( & V_3 -> V_4 ) ;
goto V_122;
}
if ( V_3 -> V_33 == V_52 ) {
T_1 V_33 = F_56 ( V_8 ) ;
F_28 ( L_20 , V_33 ) ;
if ( V_33 == V_51 ) {
V_120 = V_123 ;
F_13 ( & V_3 -> V_4 ) ;
F_34 ( & V_3 -> V_4 ) ;
goto V_122;
}
V_3 -> V_33 = V_33 ;
}
V_117 = F_83 ( NULL , V_118 -> V_124 , V_125 ) ;
if ( V_117 == NULL ) {
V_120 = V_123 ;
F_13 ( & V_3 -> V_4 ) ;
F_34 ( & V_3 -> V_4 ) ;
goto V_122;
}
V_119 = V_13 ( V_117 ) ;
V_119 -> V_18 = V_8 -> V_18 ;
V_119 -> V_8 = F_15 ( V_8 ) ;
V_119 -> V_126 = V_8 -> V_127 ;
V_119 -> V_128 = V_3 -> V_128 ;
V_119 -> V_34 = V_33 ;
V_119 -> V_103 = V_8 -> V_103 ;
V_119 -> V_118 = V_118 ;
V_119 -> V_33 = V_3 -> V_33 ;
if ( V_3 -> V_33 < V_56 && V_3 -> V_33 >= V_53 ) {
T_3 * V_129 ;
F_28 ( L_21 , V_3 -> V_33 , V_119 ) ;
V_129 =
& V_8 -> V_61 [ V_3 -> V_33 - V_53 ] ;
F_84 ( V_129 ) ;
V_119 -> V_130 = V_3 -> V_33 ;
}
F_85 ( V_119 , & V_98 -> V_38 [ V_114 ] ,
V_98 -> V_102 - V_114 ) ;
F_28 ( L_22 , V_119 , & V_119 -> V_4 ) ;
F_1 ( & V_8 -> V_15 , V_117 ) ;
F_86 ( & V_3 -> V_4 , V_117 ) ;
F_87 ( V_8 -> V_18 -> V_131 ) ;
V_117 -> V_16 = V_17 ;
V_118 -> V_132 ( V_118 , 0 ) ;
F_88 ( V_119 ) ;
F_13 ( & V_3 -> V_4 ) ;
F_34 ( & V_3 -> V_4 ) ;
return;
V_122:
F_89 ( V_8 , V_34 , V_33 , V_120 ) ;
return;
}
int F_90 ( struct V_13 * V_3 )
{
int V_133 = 0 ;
struct V_7 * V_8 = V_3 -> V_8 ;
F_28 ( L_23 ,
V_3 -> V_134 , F_91 ( & V_3 -> V_106 ) ,
V_3 -> V_135 ) ;
while ( V_3 -> V_134 &&
F_91 ( & V_3 -> V_106 ) < V_3 -> V_135 ) {
struct V_92 * V_93 ;
V_93 = F_70 ( & V_3 -> V_28 ) ;
if ( V_93 == NULL )
break;
F_68 ( V_3 , V_93 ) ;
F_74 ( & V_8 -> V_28 , V_93 ) ;
V_133 ++ ;
}
return V_133 ;
}
static void F_92 ( struct V_7 * V_8 ,
struct V_92 * V_98 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
T_1 V_34 , V_33 , V_136 , V_137 , V_138 ;
V_136 = F_64 ( V_98 ) ;
V_34 = F_63 ( V_98 ) ;
V_33 = F_65 ( V_98 ) ;
V_137 = F_66 ( V_98 ) ;
V_138 = F_67 ( V_98 ) ;
F_28 ( L_24 , V_34 , V_33 , V_138 , V_137 ) ;
V_14 = F_27 ( V_8 , V_34 , V_33 ) ;
if ( V_14 == NULL ) {
F_89 ( V_8 , V_34 , V_33 , V_139 ) ;
return;
}
V_4 = & V_14 -> V_4 ;
F_9 ( V_4 ) ;
if ( V_4 -> V_16 == V_23 ) {
F_13 ( V_4 ) ;
F_33 ( V_14 ) ;
}
if ( V_136 == V_105 ) {
F_28 ( L_25 , & V_14 -> V_4 ) ;
if ( V_137 == V_14 -> V_95 )
V_14 -> V_95 = ( V_14 -> V_95 + 1 ) % 16 ;
else
F_38 ( L_26 ) ;
F_93 ( V_98 , V_114 + V_140 ) ;
if ( F_94 ( & V_14 -> V_4 , V_98 ) ) {
F_38 ( L_27 ) ;
F_95 ( & V_14 -> V_141 , V_98 ) ;
}
}
if ( V_14 -> V_142 != V_138 ) {
struct V_92 * V_143 , * V_12 ;
V_14 -> V_142 = V_138 ;
F_96 (&llcp_sock->tx_pending_queue, s, tmp) {
F_97 ( V_143 , & V_14 -> V_106 ) ;
F_23 ( V_143 ) ;
if ( F_66 ( V_143 ) == V_138 )
break;
}
F_98 (&llcp_sock->tx_pending_queue,
s, tmp) {
F_97 ( V_143 , & V_14 -> V_106 ) ;
F_95 ( & V_8 -> V_28 , V_143 ) ;
}
}
if ( V_136 == V_144 )
V_14 -> V_134 = true ;
else if ( V_136 == V_145 )
V_14 -> V_134 = false ;
if ( F_90 ( V_14 ) == 0 && V_136 == V_105 )
F_99 ( V_14 ) ;
F_13 ( V_4 ) ;
F_33 ( V_14 ) ;
}
static void F_100 ( struct V_7 * V_8 ,
struct V_92 * V_98 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
T_1 V_34 , V_33 ;
V_34 = F_63 ( V_98 ) ;
V_33 = F_65 ( V_98 ) ;
V_14 = F_27 ( V_8 , V_34 , V_33 ) ;
if ( V_14 == NULL ) {
F_89 ( V_8 , V_34 , V_33 , V_139 ) ;
return;
}
V_4 = & V_14 -> V_4 ;
F_9 ( V_4 ) ;
if ( V_4 -> V_16 == V_23 ) {
F_13 ( V_4 ) ;
F_33 ( V_14 ) ;
}
if ( V_4 -> V_16 == V_17 ) {
F_10 ( V_8 -> V_18 ) ;
V_4 -> V_16 = V_23 ;
V_4 -> V_146 ( V_4 ) ;
}
F_89 ( V_8 , V_34 , V_33 , V_147 ) ;
F_13 ( V_4 ) ;
F_33 ( V_14 ) ;
}
static void F_101 ( struct V_7 * V_8 , struct V_92 * V_98 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
T_1 V_34 , V_33 ;
V_34 = F_63 ( V_98 ) ;
V_33 = F_65 ( V_98 ) ;
V_14 = F_78 ( V_8 , V_34 ) ;
if ( V_14 == NULL ) {
F_38 ( L_28 ) ;
F_89 ( V_8 , V_34 , V_33 , V_139 ) ;
return;
}
V_4 = & V_14 -> V_4 ;
F_5 ( & V_8 -> V_109 , V_4 ) ;
F_1 ( & V_8 -> V_15 , V_4 ) ;
V_14 -> V_34 = V_33 ;
F_85 ( V_14 , & V_98 -> V_38 [ V_114 ] ,
V_98 -> V_102 - V_114 ) ;
V_4 -> V_16 = V_17 ;
V_4 -> V_146 ( V_4 ) ;
F_33 ( V_14 ) ;
}
static void F_102 ( struct V_7 * V_8 , struct V_92 * V_98 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
T_1 V_34 , V_33 , V_120 ;
V_34 = F_63 ( V_98 ) ;
V_33 = F_65 ( V_98 ) ;
V_120 = V_98 -> V_38 [ 2 ] ;
F_28 ( L_29 , V_33 , V_34 , V_120 ) ;
switch ( V_120 ) {
case V_121 :
case V_123 :
V_14 = F_78 ( V_8 , V_34 ) ;
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
V_4 -> V_148 = V_149 ;
V_4 -> V_16 = V_23 ;
V_4 -> V_146 ( V_4 ) ;
F_33 ( V_14 ) ;
return;
}
static void F_103 ( struct V_35 * V_36 )
{
struct V_7 * V_8 = F_18 ( V_36 , struct V_7 ,
V_150 ) ;
T_1 V_34 , V_33 , V_136 ;
struct V_92 * V_98 ;
V_98 = V_8 -> V_32 ;
if ( V_98 == NULL ) {
F_28 ( L_31 ) ;
return;
}
V_136 = F_64 ( V_98 ) ;
V_34 = F_63 ( V_98 ) ;
V_33 = F_65 ( V_98 ) ;
F_28 ( L_32 , V_136 , V_34 , V_33 ) ;
if ( V_136 != V_151 )
F_71 ( V_100 , L_33 , V_101 ,
16 , 1 , V_98 -> V_38 , V_98 -> V_102 , true ) ;
switch ( V_136 ) {
case V_151 :
F_28 ( L_34 ) ;
break;
case V_152 :
F_28 ( L_35 ) ;
F_81 ( V_8 , V_98 ) ;
break;
case V_153 :
F_28 ( L_36 ) ;
F_100 ( V_8 , V_98 ) ;
break;
case V_154 :
F_28 ( L_37 ) ;
F_101 ( V_8 , V_98 ) ;
break;
case V_155 :
F_28 ( L_38 ) ;
F_102 ( V_8 , V_98 ) ;
break;
case V_105 :
case V_144 :
case V_145 :
F_28 ( L_39 ) ;
F_92 ( V_8 , V_98 ) ;
break;
}
F_39 ( V_8 -> V_29 , & V_8 -> V_97 ) ;
F_23 ( V_8 -> V_32 ) ;
V_8 -> V_32 = NULL ;
return;
}
void V_104 ( void * V_38 , struct V_92 * V_98 , int V_156 )
{
struct V_7 * V_8 = (struct V_7 * ) V_38 ;
F_28 ( L_40 ) ;
if ( V_156 < 0 ) {
F_38 ( L_41 , V_156 ) ;
return;
}
V_8 -> V_32 = F_73 ( V_98 ) ;
F_104 ( & V_8 -> V_27 ) ;
F_39 ( V_8 -> V_30 , & V_8 -> V_150 ) ;
return;
}
int F_105 ( struct V_39 * V_18 , struct V_92 * V_98 )
{
struct V_7 * V_8 ;
V_8 = F_40 ( V_18 ) ;
if ( V_8 == NULL )
return - V_89 ;
V_8 -> V_32 = F_73 ( V_98 ) ;
F_104 ( & V_8 -> V_27 ) ;
F_39 ( V_8 -> V_30 , & V_8 -> V_150 ) ;
return 0 ;
}
void F_106 ( struct V_39 * V_18 )
{
struct V_7 * V_8 ;
V_8 = F_40 ( V_18 ) ;
if ( V_8 == NULL )
return;
F_7 ( V_8 , true ) ;
}
void F_107 ( struct V_39 * V_18 , T_5 V_103 ,
T_1 V_157 , T_1 V_158 )
{
struct V_7 * V_8 ;
F_28 ( L_42 , V_158 ) ;
V_8 = F_40 ( V_18 ) ;
if ( V_8 == NULL )
return;
V_8 -> V_103 = V_103 ;
V_8 -> V_157 = V_157 ;
V_8 -> V_158 = V_158 ;
if ( V_158 == V_159 ) {
F_28 ( L_43 ) ;
F_39 ( V_8 -> V_29 , & V_8 -> V_97 ) ;
} else {
F_76 ( & V_8 -> V_27 ,
V_107 + F_77 ( V_8 -> V_108 ) ) ;
}
}
int F_108 ( struct V_39 * V_160 )
{
struct V_161 * V_18 = & V_160 -> V_18 ;
struct V_7 * V_8 ;
char V_162 [ 32 ] ;
int V_156 ;
V_8 = F_109 ( sizeof( struct V_7 ) , V_163 ) ;
if ( V_8 == NULL )
return - V_164 ;
V_8 -> V_18 = V_160 ;
F_110 ( & V_8 -> V_26 ) ;
F_111 ( & V_8 -> V_24 ) ;
F_112 ( & V_8 -> V_49 ) ;
F_113 ( & V_8 -> V_27 ) ;
V_8 -> V_27 . V_38 = ( unsigned long ) V_8 ;
V_8 -> V_27 . V_165 = F_37 ;
F_114 ( & V_8 -> V_28 ) ;
F_115 ( & V_8 -> V_97 , F_69 ) ;
snprintf ( V_162 , sizeof( V_162 ) , L_44 , F_116 ( V_18 ) ) ;
V_8 -> V_29 =
F_117 ( V_162 ,
V_166 | V_167 | V_168 ,
1 ) ;
if ( V_8 -> V_29 == NULL ) {
V_156 = - V_164 ;
goto V_169;
}
V_8 -> V_32 = NULL ;
F_115 ( & V_8 -> V_150 , F_103 ) ;
snprintf ( V_162 , sizeof( V_162 ) , L_45 , F_116 ( V_18 ) ) ;
V_8 -> V_30 =
F_117 ( V_162 ,
V_166 | V_167 | V_168 ,
1 ) ;
if ( V_8 -> V_30 == NULL ) {
V_156 = - V_164 ;
goto V_170;
}
F_115 ( & V_8 -> V_37 , F_35 ) ;
snprintf ( V_162 , sizeof( V_162 ) , L_46 , F_116 ( V_18 ) ) ;
V_8 -> V_31 =
F_117 ( V_162 ,
V_166 | V_167 | V_168 ,
1 ) ;
if ( V_8 -> V_31 == NULL ) {
V_156 = - V_164 ;
goto V_171;
}
V_8 -> V_15 . V_5 = F_118 ( V_8 -> V_15 . V_5 ) ;
V_8 -> V_109 . V_5 = F_118 ( V_8 -> V_109 . V_5 ) ;
F_57 ( V_8 ) ;
V_8 -> V_127 = V_172 ;
V_8 -> V_108 = V_173 ;
F_119 ( & V_174 , & V_8 -> V_26 ) ;
return 0 ;
V_171:
F_22 ( V_8 -> V_30 ) ;
V_170:
F_22 ( V_8 -> V_29 ) ;
V_169:
F_24 ( V_8 ) ;
return 0 ;
}
void F_120 ( struct V_39 * V_18 )
{
struct V_7 * V_8 = F_40 ( V_18 ) ;
if ( V_8 == NULL ) {
F_28 ( L_47 ) ;
return;
}
F_25 ( V_8 ) ;
}
int T_6 F_121 ( void )
{
F_110 ( & V_174 ) ;
return F_122 () ;
}
void F_123 ( void )
{
F_124 () ;
}
