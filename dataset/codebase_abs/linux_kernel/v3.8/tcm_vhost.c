static int F_1 ( struct V_1 * V_2 )
{
return 1 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static char * F_3 ( void )
{
return L_1 ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( V_2 ,
struct V_3 , V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
switch ( V_6 -> V_7 ) {
case V_8 :
return F_6 ( V_2 ) ;
case V_9 :
return F_7 ( V_2 ) ;
case V_10 :
return F_8 ( V_2 ) ;
default:
F_9 ( L_2
L_3 , V_6 -> V_7 ) ;
break;
}
return F_6 ( V_2 ) ;
}
static char * F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( V_2 ,
struct V_3 , V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
return & V_6 -> V_11 [ 0 ] ;
}
static T_2 F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( V_2 ,
struct V_3 , V_2 ) ;
return V_4 -> V_12 ;
}
static T_3 F_12 ( struct V_1 * V_2 )
{
return 1 ;
}
static T_3 F_13 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
int * V_17 ,
unsigned char * V_18 )
{
struct V_3 * V_4 = F_5 ( V_2 ,
struct V_3 , V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
switch ( V_6 -> V_7 ) {
case V_8 :
return F_14 ( V_2 , V_14 , V_16 ,
V_17 , V_18 ) ;
case V_9 :
return F_15 ( V_2 , V_14 , V_16 ,
V_17 , V_18 ) ;
case V_10 :
return F_16 ( V_2 , V_14 , V_16 ,
V_17 , V_18 ) ;
default:
F_9 ( L_2
L_3 , V_6 -> V_7 ) ;
break;
}
return F_14 ( V_2 , V_14 , V_16 ,
V_17 , V_18 ) ;
}
static T_3 F_17 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
int * V_17 )
{
struct V_3 * V_4 = F_5 ( V_2 ,
struct V_3 , V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
switch ( V_6 -> V_7 ) {
case V_8 :
return F_18 ( V_2 , V_14 , V_16 ,
V_17 ) ;
case V_9 :
return F_19 ( V_2 , V_14 , V_16 ,
V_17 ) ;
case V_10 :
return F_20 ( V_2 , V_14 , V_16 ,
V_17 ) ;
default:
F_9 ( L_2
L_3 , V_6 -> V_7 ) ;
break;
}
return F_18 ( V_2 , V_14 , V_16 ,
V_17 ) ;
}
static char * F_21 ( struct V_1 * V_2 ,
const char * V_18 ,
T_3 * V_19 ,
char * * V_20 )
{
struct V_3 * V_4 = F_5 ( V_2 ,
struct V_3 , V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
switch ( V_6 -> V_7 ) {
case V_8 :
return F_22 ( V_2 , V_18 , V_19 ,
V_20 ) ;
case V_9 :
return F_23 ( V_2 , V_18 , V_19 ,
V_20 ) ;
case V_10 :
return F_24 ( V_2 , V_18 , V_19 ,
V_20 ) ;
default:
F_9 ( L_2
L_3 , V_6 -> V_7 ) ;
break;
}
return F_22 ( V_2 , V_18 , V_19 ,
V_20 ) ;
}
static struct V_13 * F_25 (
struct V_1 * V_2 )
{
struct V_21 * V_22 ;
V_22 = F_26 ( sizeof( struct V_21 ) , V_23 ) ;
if ( ! V_22 ) {
F_9 ( L_4 ) ;
return NULL ;
}
return & V_22 -> V_13 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_21 * V_22 = F_5 ( V_14 ,
struct V_21 , V_13 ) ;
F_28 ( V_22 ) ;
}
static T_3 F_29 ( struct V_1 * V_2 )
{
return 1 ;
}
static void F_30 ( struct V_24 * V_24 )
{
return;
}
static int F_31 ( struct V_25 * V_26 )
{
return 0 ;
}
static void F_32 ( struct V_25 * V_26 )
{
return;
}
static T_3 F_33 ( struct V_25 * V_26 )
{
return 0 ;
}
static int F_34 ( struct V_24 * V_24 )
{
F_35 ( V_24 ) ;
return 0 ;
}
static int F_36 ( struct V_24 * V_24 )
{
return 0 ;
}
static void F_37 ( struct V_13 * V_22 )
{
return;
}
static T_3 F_38 ( struct V_24 * V_24 )
{
return 0 ;
}
static int F_39 ( struct V_24 * V_24 )
{
return 0 ;
}
static void F_40 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_31 ;
F_41 ( & V_30 -> V_32 ) ;
F_42 ( & V_28 -> V_33 , & V_30 -> V_34 ) ;
F_43 ( & V_30 -> V_32 ) ;
F_44 ( & V_30 -> V_35 , & V_30 -> V_36 ) ;
}
static int F_45 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = F_5 ( V_24 ,
struct V_27 , V_37 ) ;
F_40 ( V_28 ) ;
return 0 ;
}
static int F_46 ( struct V_24 * V_24 )
{
struct V_27 * V_28 = F_5 ( V_24 ,
struct V_27 , V_37 ) ;
F_40 ( V_28 ) ;
return 0 ;
}
static int F_47 ( struct V_24 * V_24 )
{
return 0 ;
}
static void F_48 ( struct V_27 * V_28 )
{
struct V_24 * V_24 = & V_28 -> V_37 ;
F_49 ( V_24 , 1 ) ;
if ( V_28 -> V_38 ) {
T_3 V_39 ;
for ( V_39 = 0 ; V_39 < V_28 -> V_38 ; V_39 ++ )
F_50 ( F_51 ( & V_28 -> V_40 [ V_39 ] ) ) ;
F_28 ( V_28 -> V_40 ) ;
}
F_28 ( V_28 ) ;
}
static struct V_27 * F_52 (
struct V_29 * V_30 )
{
struct V_27 * V_28 = NULL ;
F_41 ( & V_30 -> V_32 ) ;
if ( F_53 ( & V_30 -> V_34 ) ) {
F_43 ( & V_30 -> V_32 ) ;
return NULL ;
}
F_54 (tv_cmd, &vs->vs_completion_list,
tvc_completion_list) {
F_55 ( & V_28 -> V_33 ) ;
break;
}
F_43 ( & V_30 -> V_32 ) ;
return V_28 ;
}
static void F_56 ( struct V_41 * V_42 )
{
struct V_29 * V_30 = F_5 ( V_42 , struct V_29 ,
V_36 ) ;
struct V_27 * V_28 ;
while ( ( V_28 = F_52 ( V_30 ) ) ) {
struct V_43 V_44 ;
struct V_24 * V_24 = & V_28 -> V_37 ;
int V_45 ;
F_57 ( L_5 , V_46 ,
V_28 , V_24 -> V_47 , V_24 -> V_48 ) ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_49 = V_24 -> V_47 ;
V_44 . V_50 = V_24 -> V_48 ;
V_44 . V_51 = V_24 -> V_52 ;
memcpy ( V_44 . V_53 , V_28 -> V_54 ,
V_44 . V_51 ) ;
V_45 = F_58 ( V_28 -> V_55 , & V_44 , sizeof( V_44 ) ) ;
if ( F_59 ( V_45 == 0 ) )
F_60 ( & V_30 -> V_56 [ 2 ] , V_28 -> V_57 , 0 ) ;
else
F_9 ( L_6 ) ;
F_48 ( V_28 ) ;
}
F_61 ( & V_30 -> V_35 , & V_30 -> V_56 [ 2 ] ) ;
}
static struct V_27 * F_62 (
struct V_3 * V_58 ,
struct V_59 * V_60 ,
T_3 V_61 ,
int V_62 )
{
struct V_27 * V_28 ;
struct V_63 * V_64 ;
V_64 = V_58 -> V_65 ;
if ( ! V_64 ) {
F_9 ( L_7 ) ;
return F_63 ( - V_66 ) ;
}
V_28 = F_26 ( sizeof( struct V_27 ) , V_67 ) ;
if ( ! V_28 ) {
F_9 ( L_8 ) ;
return F_63 ( - V_68 ) ;
}
F_64 ( & V_28 -> V_33 ) ;
V_28 -> V_69 = V_60 -> V_70 ;
V_28 -> V_71 = V_60 -> V_72 ;
V_28 -> V_73 = V_61 ;
V_28 -> V_74 = V_62 ;
V_28 -> V_75 = V_64 ;
return V_28 ;
}
static int F_65 ( struct V_76 * V_77 ,
unsigned int V_78 , void T_4 * V_79 , T_5 V_80 , int V_81 )
{
struct V_76 * V_82 = V_77 ;
unsigned int V_83 = 0 ;
int V_45 ;
while ( V_80 > 0 ) {
struct V_84 * V_84 ;
unsigned int V_85 = ( V_86 ) V_79 & ~ V_87 ;
unsigned int V_88 = F_66 (unsigned int,
PAGE_SIZE - offset, len) ;
if ( V_83 == V_78 ) {
V_45 = - V_89 ;
goto V_90;
}
V_45 = F_67 ( ( unsigned long ) V_79 , 1 , V_81 , & V_84 ) ;
F_68 ( V_45 == 0 ) ;
if ( V_45 < 0 )
goto V_90;
F_69 ( V_82 , V_84 , V_88 , V_85 ) ;
V_79 += V_88 ;
V_80 -= V_88 ;
V_82 ++ ;
V_83 ++ ;
}
return V_83 ;
V_90:
for ( V_82 = V_77 ; V_82 != & V_77 [ V_83 ] ; V_82 ++ )
F_50 ( F_51 ( V_82 ) ) ;
return V_45 ;
}
static int F_70 ( struct V_27 * V_28 ,
struct V_91 * V_92 , unsigned int V_93 , int V_81 )
{
int V_45 ;
unsigned int V_39 ;
T_3 V_78 ;
struct V_76 * V_82 ;
V_78 = 0 ;
for ( V_39 = 0 ; V_39 < V_93 ; V_39 ++ ) {
V_78 += ( ( ( V_86 ) V_92 [ V_39 ] . V_94 + V_92 [ V_39 ] . V_95 +
V_96 - 1 ) >> V_97 ) -
( ( V_86 ) V_92 [ V_39 ] . V_94 >> V_97 ) ;
}
V_82 = F_71 ( sizeof( V_28 -> V_40 [ 0 ] ) * V_78 , V_67 ) ;
if ( ! V_82 )
return - V_68 ;
F_57 ( L_9 , V_46 ,
V_82 , V_78 , ! V_82 ) ;
F_72 ( V_82 , V_78 ) ;
V_28 -> V_40 = V_82 ;
V_28 -> V_38 = V_78 ;
F_57 ( L_10 , V_93 , V_78 ) ;
for ( V_39 = 0 ; V_39 < V_93 ; V_39 ++ ) {
V_45 = F_65 ( V_82 , V_78 , V_92 [ V_39 ] . V_94 ,
V_92 [ V_39 ] . V_95 , V_81 ) ;
if ( V_45 < 0 ) {
for ( V_39 = 0 ; V_39 < V_28 -> V_38 ; V_39 ++ )
F_50 ( F_51 ( & V_28 -> V_40 [ V_39 ] ) ) ;
F_28 ( V_28 -> V_40 ) ;
V_28 -> V_40 = NULL ;
V_28 -> V_38 = 0 ;
return V_45 ;
}
V_82 += V_45 ;
V_78 -= V_45 ;
}
return 0 ;
}
static void F_73 ( struct V_98 * V_42 )
{
struct V_27 * V_28 =
F_5 ( V_42 , struct V_27 , V_42 ) ;
struct V_63 * V_64 ;
struct V_24 * V_24 = & V_28 -> V_37 ;
struct V_76 * V_99 , * V_100 = NULL ;
int V_101 , V_102 = 0 ;
if ( V_28 -> V_38 ) {
V_99 = V_28 -> V_40 ;
#if 0
if (se_cmd->se_cmd_flags & SCF_BIDI) {
sg_bidi_ptr = NULL;
sg_no_bidi = 0;
}
#endif
} else {
V_99 = NULL ;
}
V_64 = V_28 -> V_75 ;
V_101 = F_74 ( V_24 , V_64 -> V_103 ,
V_28 -> V_104 , & V_28 -> V_54 [ 0 ] ,
V_28 -> V_105 , V_28 -> V_73 ,
V_28 -> V_71 , V_28 -> V_74 ,
0 , V_99 , V_28 -> V_38 ,
V_100 , V_102 ) ;
if ( V_101 < 0 ) {
F_75 ( V_24 ,
V_106 , 0 ) ;
F_49 ( V_24 , 0 ) ;
}
}
static void F_76 ( struct V_29 * V_30 )
{
struct V_107 * V_108 = & V_30 -> V_56 [ 2 ] ;
struct V_59 V_60 ;
struct V_3 * V_58 ;
struct V_27 * V_28 ;
T_3 V_61 , V_109 , V_110 , V_62 ;
unsigned V_111 , V_112 , V_39 ;
int V_113 , V_45 ;
V_58 = V_30 -> V_114 ;
if ( F_77 ( ! V_58 ) )
return;
F_78 ( & V_108 -> V_115 ) ;
F_79 ( & V_30 -> V_35 , V_108 ) ;
for (; ; ) {
V_113 = F_80 ( & V_30 -> V_35 , V_108 , V_108 -> V_92 ,
F_81 ( V_108 -> V_92 ) , & V_111 , & V_112 ,
NULL , NULL ) ;
F_57 ( L_11 ,
V_113 , V_111 , V_112 ) ;
if ( F_77 ( V_113 < 0 ) )
break;
if ( V_113 == V_108 -> V_116 ) {
if ( F_77 ( F_82 ( & V_30 -> V_35 , V_108 ) ) ) {
F_79 ( & V_30 -> V_35 , V_108 ) ;
continue;
}
break;
}
if ( V_111 == 1 && V_112 == 1 ) {
V_62 = V_117 ;
V_109 = 0 ;
V_110 = 0 ;
} else if ( V_111 == 1 && V_112 > 1 ) {
V_62 = V_118 ;
V_109 = V_111 + 1 ;
V_110 = V_112 - 1 ;
} else if ( V_111 > 1 && V_112 == 1 ) {
V_62 = V_119 ;
V_109 = 1 ;
V_110 = V_111 - 1 ;
} else {
F_83 ( V_108 , L_12 ,
V_111 , V_112 ) ;
break;
}
if ( F_77 ( V_108 -> V_92 [ V_111 ] . V_95 !=
sizeof( struct V_43 ) ) ) {
F_83 ( V_108 , L_13
L_14 , V_108 -> V_92 [ V_111 ] . V_95 ) ;
break;
}
if ( F_77 ( V_108 -> V_92 [ 0 ] . V_95 != sizeof( V_60 ) ) ) {
F_83 ( V_108 , L_15
L_14 , V_108 -> V_92 [ 0 ] . V_95 ) ;
break;
}
F_57 ( L_16
L_17 , V_108 -> V_92 [ 0 ] . V_94 , sizeof( V_60 ) ) ;
V_45 = F_84 ( & V_60 , V_108 -> V_92 [ 0 ] . V_94 ,
sizeof( V_60 ) ) ;
if ( F_77 ( V_45 ) ) {
F_83 ( V_108 , L_18 ) ;
break;
}
V_61 = 0 ;
for ( V_39 = 0 ; V_39 < V_110 ; V_39 ++ )
V_61 += V_108 -> V_92 [ V_109 + V_39 ] . V_95 ;
V_28 = F_62 ( V_58 , & V_60 ,
V_61 , V_62 ) ;
if ( F_85 ( V_28 ) ) {
F_83 ( V_108 , L_19 ,
F_86 ( V_28 ) ) ;
break;
}
F_57 ( L_20
L_21 , V_28 , V_61 , V_62 ) ;
V_28 -> V_31 = V_30 ;
if ( F_77 ( V_108 -> V_92 [ V_111 ] . V_95 !=
sizeof( struct V_43 ) ) ) {
F_83 ( V_108 , L_13
L_22 ,
V_108 -> V_92 [ V_111 ] . V_95 , V_111 , V_112 ) ;
break;
}
V_28 -> V_55 = V_108 -> V_92 [ V_111 ] . V_94 ;
memcpy ( V_28 -> V_104 , V_60 . V_120 , V_121 ) ;
if ( F_77 ( F_87 ( V_28 -> V_104 ) >
V_121 ) ) {
F_83 ( V_108 , L_23
L_24 ,
F_87 ( V_28 -> V_104 ) ,
V_121 ) ;
break;
}
V_28 -> V_105 = ( ( V_60 . V_122 [ 2 ] << 8 ) | V_60 . V_122 [ 3 ] ) & 0x3FFF ;
F_57 ( L_25 ,
V_28 -> V_104 [ 0 ] , V_28 -> V_105 ) ;
if ( V_62 != V_117 ) {
V_45 = F_70 ( V_28 ,
& V_108 -> V_92 [ V_109 ] , V_110 ,
V_62 == V_119 ) ;
if ( F_77 ( V_45 ) ) {
F_83 ( V_108 , L_26 ) ;
break;
}
}
V_28 -> V_57 = V_113 ;
F_88 ( & V_28 -> V_42 , F_73 ) ;
F_89 ( V_123 , & V_28 -> V_42 ) ;
}
F_90 ( & V_108 -> V_115 ) ;
}
static void F_91 ( struct V_41 * V_42 )
{
F_57 ( L_27 , V_46 ) ;
}
static void F_92 ( struct V_41 * V_42 )
{
F_57 ( L_28 , V_46 ) ;
}
static void F_93 ( struct V_41 * V_42 )
{
struct V_107 * V_108 = F_5 ( V_42 , struct V_107 ,
V_124 . V_42 ) ;
struct V_29 * V_30 = F_5 ( V_108 -> V_35 , struct V_29 , V_35 ) ;
F_76 ( V_30 ) ;
}
static int F_94 (
struct V_29 * V_30 ,
struct V_125 * V_126 )
{
struct V_5 * V_127 ;
struct V_3 * V_58 ;
int V_128 ;
F_78 ( & V_30 -> V_35 . V_115 ) ;
for ( V_128 = 0 ; V_128 < V_30 -> V_35 . V_129 ; ++ V_128 ) {
if ( ! F_95 ( & V_30 -> V_56 [ V_128 ] ) ) {
F_90 ( & V_30 -> V_35 . V_115 ) ;
return - V_130 ;
}
}
F_90 ( & V_30 -> V_35 . V_115 ) ;
F_78 ( & V_131 ) ;
F_54 (tv_tpg, &tcm_vhost_list, tv_tpg_list) {
F_78 ( & V_58 -> V_132 ) ;
if ( ! V_58 -> V_65 ) {
F_90 ( & V_58 -> V_132 ) ;
continue;
}
if ( V_58 -> V_133 != 0 ) {
F_90 ( & V_58 -> V_132 ) ;
continue;
}
V_127 = V_58 -> V_6 ;
if ( ! strcmp ( V_127 -> V_11 , V_126 -> V_134 ) &&
( V_58 -> V_12 == V_126 -> V_135 ) ) {
V_58 -> V_133 ++ ;
F_90 ( & V_58 -> V_132 ) ;
F_90 ( & V_131 ) ;
F_78 ( & V_30 -> V_35 . V_115 ) ;
if ( V_30 -> V_114 ) {
F_90 ( & V_30 -> V_35 . V_115 ) ;
F_78 ( & V_58 -> V_132 ) ;
V_58 -> V_133 -- ;
F_90 ( & V_58 -> V_132 ) ;
return - V_136 ;
}
V_30 -> V_114 = V_58 ;
F_96 () ;
F_90 ( & V_30 -> V_35 . V_115 ) ;
return 0 ;
}
F_90 ( & V_58 -> V_132 ) ;
}
F_90 ( & V_131 ) ;
return - V_137 ;
}
static int F_97 (
struct V_29 * V_30 ,
struct V_125 * V_126 )
{
struct V_5 * V_127 ;
struct V_3 * V_58 ;
int V_128 , V_45 ;
F_78 ( & V_30 -> V_35 . V_115 ) ;
for ( V_128 = 0 ; V_128 < V_30 -> V_35 . V_129 ; ++ V_128 ) {
if ( ! F_95 ( & V_30 -> V_56 [ V_128 ] ) ) {
V_45 = - V_130 ;
goto V_90;
}
}
if ( ! V_30 -> V_114 ) {
V_45 = - V_138 ;
goto V_90;
}
V_58 = V_30 -> V_114 ;
V_127 = V_58 -> V_6 ;
if ( strcmp ( V_127 -> V_11 , V_126 -> V_134 ) ||
( V_58 -> V_12 != V_126 -> V_135 ) ) {
F_98 ( L_29
L_30 ,
V_127 -> V_11 , V_58 -> V_12 ,
V_126 -> V_134 , V_126 -> V_135 ) ;
V_45 = - V_137 ;
goto V_90;
}
V_58 -> V_133 -- ;
V_30 -> V_114 = NULL ;
F_90 ( & V_30 -> V_35 . V_115 ) ;
return 0 ;
V_90:
F_90 ( & V_30 -> V_35 . V_115 ) ;
return V_45 ;
}
static int F_99 ( struct V_139 * V_139 , struct V_140 * V_141 )
{
struct V_29 * V_142 ;
int V_143 ;
V_142 = F_26 ( sizeof( * V_142 ) , V_23 ) ;
if ( ! V_142 )
return - V_68 ;
F_100 ( & V_142 -> V_36 , F_56 ) ;
F_64 ( & V_142 -> V_34 ) ;
F_101 ( & V_142 -> V_32 ) ;
V_142 -> V_56 [ V_144 ] . V_145 = F_91 ;
V_142 -> V_56 [ V_146 ] . V_145 = F_92 ;
V_142 -> V_56 [ V_147 ] . V_145 = F_93 ;
V_143 = F_102 ( & V_142 -> V_35 , V_142 -> V_56 , 3 ) ;
if ( V_143 < 0 ) {
F_28 ( V_142 ) ;
return V_143 ;
}
V_141 -> V_148 = V_142 ;
return 0 ;
}
static int F_103 ( struct V_139 * V_139 , struct V_140 * V_141 )
{
struct V_29 * V_142 = V_141 -> V_148 ;
if ( V_142 -> V_114 && V_142 -> V_114 -> V_6 ) {
struct V_125 V_149 ;
memcpy ( V_149 . V_134 , V_142 -> V_114 -> V_6 -> V_11 ,
sizeof( V_149 . V_134 ) ) ;
V_149 . V_135 = V_142 -> V_114 -> V_12 ;
F_97 ( V_142 , & V_149 ) ;
}
F_104 ( & V_142 -> V_35 ) ;
F_105 ( & V_142 -> V_35 , false ) ;
F_28 ( V_142 ) ;
return 0 ;
}
static void F_106 ( struct V_29 * V_30 , int V_128 )
{
F_107 ( & V_30 -> V_35 . V_56 [ V_128 ] . V_124 ) ;
}
static void F_108 ( struct V_29 * V_30 )
{
F_106 ( V_30 , V_144 ) ;
F_106 ( V_30 , V_146 ) ;
F_106 ( V_30 , V_147 ) ;
}
static int F_109 ( struct V_29 * V_30 , T_6 V_150 )
{
if ( V_150 & ~ V_151 )
return - V_152 ;
F_78 ( & V_30 -> V_35 . V_115 ) ;
if ( ( V_150 & ( 1 << V_153 ) ) &&
! F_110 ( & V_30 -> V_35 ) ) {
F_90 ( & V_30 -> V_35 . V_115 ) ;
return - V_130 ;
}
V_30 -> V_35 . V_154 = V_150 ;
F_111 () ;
F_108 ( V_30 ) ;
F_90 ( & V_30 -> V_35 . V_115 ) ;
return 0 ;
}
static long F_112 ( struct V_140 * V_141 , unsigned int V_155 ,
unsigned long V_156 )
{
struct V_29 * V_30 = V_141 -> V_148 ;
struct V_125 V_149 ;
void T_4 * V_157 = ( void T_4 * ) V_156 ;
T_6 T_4 * V_158 = V_157 ;
T_6 V_150 ;
int V_143 , V_159 = V_160 ;
switch ( V_155 ) {
case V_161 :
if ( F_113 ( & V_149 , V_157 , sizeof V_149 ) )
return - V_130 ;
if ( V_149 . V_162 != 0 )
return - V_152 ;
return F_94 ( V_30 , & V_149 ) ;
case V_163 :
if ( F_113 ( & V_149 , V_157 , sizeof V_149 ) )
return - V_130 ;
if ( V_149 . V_162 != 0 )
return - V_152 ;
return F_97 ( V_30 , & V_149 ) ;
case V_164 :
if ( F_58 ( V_157 , & V_159 , sizeof V_159 ) )
return - V_130 ;
return 0 ;
case V_165 :
V_150 = V_151 ;
if ( F_58 ( V_158 , & V_150 , sizeof V_150 ) )
return - V_130 ;
return 0 ;
case V_166 :
if ( F_113 ( & V_150 , V_158 , sizeof V_150 ) )
return - V_130 ;
return F_109 ( V_30 , V_150 ) ;
default:
F_78 ( & V_30 -> V_35 . V_115 ) ;
V_143 = F_114 ( & V_30 -> V_35 , V_155 , V_157 ) ;
if ( V_143 == - V_167 )
V_143 = F_115 ( & V_30 -> V_35 , V_155 , V_157 ) ;
F_90 ( & V_30 -> V_35 . V_115 ) ;
return V_143 ;
}
}
static long F_116 ( struct V_140 * V_141 , unsigned int V_155 ,
unsigned long V_156 )
{
return F_112 ( V_141 , V_155 , ( unsigned long ) F_117 ( V_156 ) ) ;
}
static int T_7 F_118 ( void )
{
return F_119 ( & V_168 ) ;
}
static int F_120 ( void )
{
return F_121 ( & V_168 ) ;
}
static char * F_122 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_8 :
return L_31 ;
case V_9 :
return L_32 ;
case V_10 :
return L_33 ;
default:
break;
}
return L_34 ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_169 * V_122 )
{
struct V_3 * V_58 = F_5 ( V_2 ,
struct V_3 , V_2 ) ;
F_78 ( & V_58 -> V_132 ) ;
V_58 -> V_170 ++ ;
F_90 ( & V_58 -> V_132 ) ;
return 0 ;
}
static void F_124 ( struct V_1 * V_2 ,
struct V_169 * V_169 )
{
struct V_3 * V_58 = F_5 ( V_2 ,
struct V_3 , V_2 ) ;
F_78 ( & V_58 -> V_132 ) ;
V_58 -> V_170 -- ;
F_90 ( & V_58 -> V_132 ) ;
}
static struct V_13 * F_125 (
struct V_1 * V_2 ,
struct V_171 * V_172 ,
const char * V_173 )
{
struct V_13 * V_14 , * V_174 ;
struct V_21 * V_22 ;
T_6 V_175 = 0 ;
T_3 V_176 ;
V_174 = F_25 ( V_2 ) ;
if ( ! V_174 )
return F_63 ( - V_68 ) ;
V_176 = 1 ;
V_14 = F_126 ( V_2 , V_174 ,
V_173 , V_176 ) ;
if ( F_85 ( V_14 ) ) {
F_27 ( V_2 , V_174 ) ;
return V_14 ;
}
V_22 = F_5 ( V_14 , struct V_21 , V_13 ) ;
V_22 -> V_177 = V_175 ;
return V_14 ;
}
static void F_127 ( struct V_13 * V_178 )
{
struct V_21 * V_22 = F_5 ( V_178 ,
struct V_21 , V_13 ) ;
F_128 ( V_178 -> V_2 , V_178 , 1 ) ;
F_28 ( V_22 ) ;
}
static int F_129 ( struct V_3 * V_58 ,
const char * V_173 )
{
struct V_1 * V_2 ;
struct V_63 * V_64 ;
F_78 ( & V_58 -> V_132 ) ;
if ( V_58 -> V_65 ) {
F_90 ( & V_58 -> V_132 ) ;
F_57 ( L_35 ) ;
return - V_136 ;
}
V_2 = & V_58 -> V_2 ;
V_64 = F_26 ( sizeof( struct V_63 ) , V_23 ) ;
if ( ! V_64 ) {
F_90 ( & V_58 -> V_132 ) ;
F_9 ( L_36 ) ;
return - V_68 ;
}
V_64 -> V_103 = F_130 () ;
if ( F_85 ( V_64 -> V_103 ) ) {
F_90 ( & V_58 -> V_132 ) ;
F_28 ( V_64 ) ;
return - V_68 ;
}
V_64 -> V_103 -> V_13 = F_131 (
V_2 , ( unsigned char * ) V_173 ) ;
if ( ! V_64 -> V_103 -> V_13 ) {
F_90 ( & V_58 -> V_132 ) ;
F_57 ( L_37
L_38 , V_173 ) ;
F_132 ( V_64 -> V_103 ) ;
F_28 ( V_64 ) ;
return - V_68 ;
}
F_133 ( V_2 , V_64 -> V_103 -> V_13 ,
V_64 -> V_103 , V_64 ) ;
V_58 -> V_65 = V_64 ;
F_90 ( & V_58 -> V_132 ) ;
return 0 ;
}
static int F_134 ( struct V_3 * V_4 )
{
struct V_25 * V_26 ;
struct V_63 * V_64 ;
F_78 ( & V_4 -> V_132 ) ;
V_64 = V_4 -> V_65 ;
if ( ! V_64 ) {
F_90 ( & V_4 -> V_132 ) ;
return - V_138 ;
}
V_26 = V_64 -> V_103 ;
if ( ! V_26 ) {
F_90 ( & V_4 -> V_132 ) ;
return - V_138 ;
}
if ( V_4 -> V_170 != 0 ) {
F_90 ( & V_4 -> V_132 ) ;
F_9 ( L_39
L_40 ,
V_4 -> V_170 ) ;
return - V_179 ;
}
if ( V_4 -> V_133 != 0 ) {
F_90 ( & V_4 -> V_132 ) ;
F_9 ( L_39
L_41 ,
V_4 -> V_133 ) ;
return - V_179 ;
}
F_57 ( L_42
L_43 , F_122 ( V_4 -> V_6 ) ,
V_64 -> V_103 -> V_13 -> V_180 ) ;
F_135 ( V_64 -> V_103 ) ;
V_4 -> V_65 = NULL ;
F_90 ( & V_4 -> V_132 ) ;
F_28 ( V_64 ) ;
return 0 ;
}
static T_8 F_136 ( struct V_1 * V_2 ,
char * V_84 )
{
struct V_3 * V_58 = F_5 ( V_2 ,
struct V_3 , V_2 ) ;
struct V_63 * V_64 ;
T_8 V_45 ;
F_78 ( & V_58 -> V_132 ) ;
V_64 = V_58 -> V_65 ;
if ( ! V_64 ) {
F_90 ( & V_58 -> V_132 ) ;
return - V_138 ;
}
V_45 = snprintf ( V_84 , V_96 , L_44 ,
V_64 -> V_103 -> V_13 -> V_180 ) ;
F_90 ( & V_58 -> V_132 ) ;
return V_45 ;
}
static T_8 F_137 ( struct V_1 * V_2 ,
const char * V_84 ,
T_5 V_181 )
{
struct V_3 * V_58 = F_5 ( V_2 ,
struct V_3 , V_2 ) ;
struct V_5 * V_182 = V_58 -> V_6 ;
unsigned char V_183 [ V_184 ] , * V_79 , * V_185 ;
int V_45 ;
if ( ! strncmp ( V_84 , L_45 , 4 ) ) {
V_45 = F_134 ( V_58 ) ;
return ( ! V_45 ) ? V_181 : V_45 ;
}
if ( strlen ( V_84 ) >= V_184 ) {
F_9 ( L_46
L_47 , V_84 , V_184 ) ;
return - V_137 ;
}
snprintf ( & V_183 [ 0 ] , V_184 , L_48 , V_84 ) ;
V_79 = strstr ( V_183 , L_49 ) ;
if ( V_79 ) {
if ( V_182 -> V_7 != V_8 ) {
F_9 ( L_50
L_51 , V_183 ,
F_122 ( V_182 ) ) ;
return - V_137 ;
}
V_185 = & V_183 [ 0 ] ;
goto V_186;
}
V_79 = strstr ( V_183 , L_52 ) ;
if ( V_79 ) {
if ( V_182 -> V_7 != V_9 ) {
F_9 ( L_53
L_51 , V_183 ,
F_122 ( V_182 ) ) ;
return - V_137 ;
}
V_185 = & V_183 [ 3 ] ;
goto V_186;
}
V_79 = strstr ( V_183 , L_54 ) ;
if ( V_79 ) {
if ( V_182 -> V_7 != V_10 ) {
F_9 ( L_55
L_51 , V_183 ,
F_122 ( V_182 ) ) ;
return - V_137 ;
}
V_185 = & V_183 [ 0 ] ;
goto V_186;
}
F_9 ( L_56
L_57 , V_183 ) ;
return - V_137 ;
V_186:
if ( V_183 [ strlen ( V_183 ) - 1 ] == '\n' )
V_183 [ strlen ( V_183 ) - 1 ] = '\0' ;
V_45 = F_129 ( V_58 , V_185 ) ;
if ( V_45 < 0 )
return V_45 ;
return V_181 ;
}
static struct V_1 * F_138 ( struct V_187 * V_188 ,
struct V_171 * V_172 ,
const char * V_173 )
{
struct V_5 * V_6 = F_5 ( V_188 ,
struct V_5 , V_182 ) ;
struct V_3 * V_4 ;
unsigned long V_189 ;
int V_45 ;
if ( strstr ( V_173 , L_58 ) != V_173 )
return F_63 ( - V_137 ) ;
if ( F_139 ( V_173 + 5 , 10 , & V_189 ) || V_189 > V_190 )
return F_63 ( - V_137 ) ;
V_4 = F_26 ( sizeof( struct V_3 ) , V_23 ) ;
if ( ! V_4 ) {
F_9 ( L_59 ) ;
return F_63 ( - V_68 ) ;
}
F_140 ( & V_4 -> V_132 ) ;
F_64 ( & V_4 -> V_191 ) ;
V_4 -> V_6 = V_6 ;
V_4 -> V_12 = V_189 ;
V_45 = F_141 ( & V_192 -> V_193 , V_188 ,
& V_4 -> V_2 , V_4 , V_194 ) ;
if ( V_45 < 0 ) {
F_28 ( V_4 ) ;
return NULL ;
}
F_78 ( & V_131 ) ;
F_42 ( & V_4 -> V_191 , & V_195 ) ;
F_90 ( & V_131 ) ;
return & V_4 -> V_2 ;
}
static void F_142 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( V_2 ,
struct V_3 , V_2 ) ;
F_78 ( & V_131 ) ;
F_55 ( & V_4 -> V_191 ) ;
F_90 ( & V_131 ) ;
F_134 ( V_4 ) ;
F_143 ( V_2 ) ;
F_28 ( V_4 ) ;
}
static struct V_187 * F_144 ( struct V_196 * V_197 ,
struct V_171 * V_172 ,
const char * V_173 )
{
struct V_5 * V_6 ;
char * V_79 ;
T_6 V_175 = 0 ;
int V_198 = 0 ;
V_6 = F_26 ( sizeof( struct V_5 ) , V_23 ) ;
if ( ! V_6 ) {
F_9 ( L_60 ) ;
return F_63 ( - V_68 ) ;
}
V_6 -> V_199 = V_175 ;
V_79 = strstr ( V_173 , L_49 ) ;
if ( V_79 ) {
V_6 -> V_7 = V_8 ;
goto V_200;
}
V_79 = strstr ( V_173 , L_52 ) ;
if ( V_79 ) {
V_6 -> V_7 = V_9 ;
V_198 = 3 ;
goto V_200;
}
V_79 = strstr ( V_173 , L_54 ) ;
if ( V_79 ) {
V_6 -> V_7 = V_10 ;
goto V_200;
}
F_9 ( L_61
L_57 , V_173 ) ;
F_28 ( V_6 ) ;
return F_63 ( - V_137 ) ;
V_200:
if ( strlen ( V_173 ) >= V_184 ) {
F_9 ( L_62
L_47 , V_173 , F_122 ( V_6 ) ,
V_184 ) ;
F_28 ( V_6 ) ;
return F_63 ( - V_137 ) ;
}
snprintf ( & V_6 -> V_11 [ 0 ] , V_184 , L_48 , & V_173 [ V_198 ] ) ;
F_57 ( L_63
L_64 , F_122 ( V_6 ) , V_173 ) ;
return & V_6 -> V_182 ;
}
static void F_145 ( struct V_187 * V_188 )
{
struct V_5 * V_6 = F_5 ( V_188 ,
struct V_5 , V_182 ) ;
F_57 ( L_65
L_64 , F_122 ( V_6 ) ,
V_6 -> V_11 ) ;
F_28 ( V_6 ) ;
}
static T_8 F_146 (
struct V_196 * V_197 ,
char * V_84 )
{
return sprintf ( V_84 , L_66
L_67 V_201 L_68 , V_202 , F_147 () -> V_203 ,
F_147 () -> V_204 ) ;
}
static int F_148 ( void )
{
struct V_196 * V_205 ;
int V_45 ;
F_57 ( L_66
L_69 V_201 L_68 , V_202 , F_147 () -> V_203 ,
F_147 () -> V_204 ) ;
V_205 = F_149 ( V_206 , L_1 ) ;
if ( F_85 ( V_205 ) ) {
F_9 ( L_70 ) ;
return F_86 ( V_205 ) ;
}
V_205 -> V_193 = V_207 ;
F_150 ( V_205 ) -> V_208 . V_209 = V_210 ;
F_150 ( V_205 ) -> V_211 . V_209 = V_212 ;
F_150 ( V_205 ) -> V_213 . V_209 = NULL ;
F_150 ( V_205 ) -> V_214 . V_209 = NULL ;
F_150 ( V_205 ) -> V_215 . V_209 = NULL ;
F_150 ( V_205 ) -> V_216 . V_209 = NULL ;
F_150 ( V_205 ) -> V_217 . V_209 = NULL ;
F_150 ( V_205 ) -> V_218 . V_209 = NULL ;
F_150 ( V_205 ) -> V_219 . V_209 = NULL ;
V_45 = F_151 ( V_205 ) ;
if ( V_45 < 0 ) {
F_9 ( L_71
L_72 ) ;
return V_45 ;
}
V_192 = V_205 ;
F_57 ( L_73 ) ;
return 0 ;
}
static void F_152 ( void )
{
if ( ! V_192 )
return;
F_153 ( V_192 ) ;
V_192 = NULL ;
F_57 ( L_74 ) ;
}
static int T_7 F_154 ( void )
{
int V_45 = - V_68 ;
V_123 = F_155 ( L_75 , 0 , 0 ) ;
if ( ! V_123 )
goto V_111;
V_45 = F_118 () ;
if ( V_45 < 0 )
goto V_220;
V_45 = F_148 () ;
if ( V_45 < 0 )
goto V_221;
return 0 ;
V_221:
F_120 () ;
V_220:
F_156 ( V_123 ) ;
V_111:
return V_45 ;
}
static void F_157 ( void )
{
F_152 () ;
F_120 () ;
F_156 ( V_123 ) ;
}
