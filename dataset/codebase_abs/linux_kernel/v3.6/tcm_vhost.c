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
static T_2 F_48 ( struct V_24 * V_24 ,
T_3 V_38 )
{
return 0 ;
}
static T_2 F_49 ( void )
{
return 0 ;
}
static void F_50 ( struct V_27 * V_28 )
{
struct V_24 * V_24 = & V_28 -> V_37 ;
F_51 ( V_24 , 1 ) ;
if ( V_28 -> V_39 ) {
T_3 V_40 ;
for ( V_40 = 0 ; V_40 < V_28 -> V_39 ; V_40 ++ )
F_52 ( F_53 ( & V_28 -> V_41 [ V_40 ] ) ) ;
F_28 ( V_28 -> V_41 ) ;
}
F_28 ( V_28 ) ;
}
static struct V_27 * F_54 (
struct V_29 * V_30 )
{
struct V_27 * V_28 = NULL ;
F_41 ( & V_30 -> V_32 ) ;
if ( F_55 ( & V_30 -> V_34 ) ) {
F_43 ( & V_30 -> V_32 ) ;
return NULL ;
}
F_56 (tv_cmd, &vs->vs_completion_list,
tvc_completion_list) {
F_57 ( & V_28 -> V_33 ) ;
break;
}
F_43 ( & V_30 -> V_32 ) ;
return V_28 ;
}
static void F_58 ( struct V_42 * V_43 )
{
struct V_29 * V_30 = F_5 ( V_43 , struct V_29 ,
V_36 ) ;
struct V_27 * V_28 ;
while ( ( V_28 = F_54 ( V_30 ) ) ) {
struct V_44 V_45 ;
struct V_24 * V_24 = & V_28 -> V_37 ;
int V_46 ;
F_59 ( L_5 , V_47 ,
V_28 , V_24 -> V_48 , V_24 -> V_49 ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_50 = V_24 -> V_48 ;
V_45 . V_51 = V_24 -> V_49 ;
V_45 . V_52 = V_24 -> V_53 ;
memcpy ( V_45 . V_54 , V_28 -> V_55 ,
V_45 . V_52 ) ;
V_46 = F_60 ( V_28 -> V_56 , & V_45 , sizeof( V_45 ) ) ;
if ( F_61 ( V_46 == 0 ) )
F_62 ( & V_30 -> V_57 [ 2 ] , V_28 -> V_58 , 0 ) ;
else
F_9 ( L_6 ) ;
F_50 ( V_28 ) ;
}
F_63 ( & V_30 -> V_35 , & V_30 -> V_57 [ 2 ] ) ;
}
static struct V_27 * F_64 (
struct V_3 * V_59 ,
struct V_60 * V_61 ,
T_3 V_62 ,
int V_63 )
{
struct V_27 * V_28 ;
struct V_64 * V_65 ;
struct V_1 * V_2 = & V_59 -> V_2 ;
struct V_25 * V_26 ;
struct V_24 * V_24 ;
int V_66 ;
V_65 = V_59 -> V_67 ;
if ( ! V_65 ) {
F_9 ( L_7 ) ;
return F_65 ( - V_68 ) ;
}
V_26 = V_65 -> V_69 ;
V_28 = F_26 ( sizeof( struct V_27 ) , V_70 ) ;
if ( ! V_28 ) {
F_9 ( L_8 ) ;
return F_65 ( - V_71 ) ;
}
F_66 ( & V_28 -> V_33 ) ;
V_28 -> V_72 = V_61 -> V_73 ;
V_24 = & V_28 -> V_37 ;
V_66 = V_61 -> V_74 ;
F_67 ( V_24 , V_2 -> V_75 , V_26 , V_62 ,
V_63 , V_66 ,
& V_28 -> V_55 [ 0 ] ) ;
#if 0
if (bidi)
se_cmd->se_cmd_flags |= SCF_BIDI;
#endif
return V_28 ;
}
static int F_68 ( struct V_76 * V_77 ,
unsigned int V_78 , void T_4 * V_79 , T_5 V_80 , int V_81 )
{
struct V_76 * V_82 = V_77 ;
unsigned int V_83 = 0 ;
int V_46 ;
while ( V_80 > 0 ) {
struct V_84 * V_84 ;
unsigned int V_85 = ( V_86 ) V_79 & ~ V_87 ;
unsigned int V_88 = F_69 (unsigned int,
PAGE_SIZE - offset, len) ;
if ( V_83 == V_78 ) {
V_46 = - V_89 ;
goto V_90;
}
V_46 = F_70 ( ( unsigned long ) V_79 , 1 , V_81 , & V_84 ) ;
F_71 ( V_46 == 0 ) ;
if ( V_46 < 0 )
goto V_90;
F_72 ( V_82 , V_84 , V_88 , V_85 ) ;
V_79 += V_88 ;
V_80 -= V_88 ;
V_82 ++ ;
V_83 ++ ;
}
return V_83 ;
V_90:
for ( V_82 = V_77 ; V_82 != & V_77 [ V_83 ] ; V_82 ++ )
F_52 ( F_53 ( V_82 ) ) ;
return V_46 ;
}
static int F_73 ( struct V_27 * V_28 ,
struct V_91 * V_92 , unsigned int V_93 , int V_81 )
{
int V_46 ;
unsigned int V_40 ;
T_3 V_78 ;
struct V_76 * V_82 ;
V_78 = 0 ;
for ( V_40 = 0 ; V_40 < V_93 ; V_40 ++ ) {
V_78 += ( ( ( V_86 ) V_92 [ V_40 ] . V_94 + V_92 [ V_40 ] . V_95 +
V_96 - 1 ) >> V_97 ) -
( ( V_86 ) V_92 [ V_40 ] . V_94 >> V_97 ) ;
}
V_82 = F_74 ( sizeof( V_28 -> V_41 [ 0 ] ) * V_78 , V_70 ) ;
if ( ! V_82 )
return - V_71 ;
F_59 ( L_9 , V_47 ,
V_82 , V_78 , ! V_82 ) ;
F_75 ( V_82 , V_78 ) ;
V_28 -> V_41 = V_82 ;
V_28 -> V_39 = V_78 ;
F_59 ( L_10 , V_93 , V_78 ) ;
for ( V_40 = 0 ; V_40 < V_93 ; V_40 ++ ) {
V_46 = F_68 ( V_82 , V_78 , V_92 [ V_40 ] . V_94 ,
V_92 [ V_40 ] . V_95 , V_81 ) ;
if ( V_46 < 0 ) {
for ( V_40 = 0 ; V_40 < V_28 -> V_39 ; V_40 ++ )
F_52 ( F_53 ( & V_28 -> V_41 [ V_40 ] ) ) ;
F_28 ( V_28 -> V_41 ) ;
V_28 -> V_41 = NULL ;
V_28 -> V_39 = 0 ;
return V_46 ;
}
V_82 += V_46 ;
V_78 -= V_46 ;
}
return 0 ;
}
static void F_76 ( struct V_98 * V_43 )
{
struct V_27 * V_28 =
F_5 ( V_43 , struct V_27 , V_43 ) ;
struct V_24 * V_24 = & V_28 -> V_37 ;
struct V_76 * V_99 , * V_100 = NULL ;
int V_101 , V_102 = 0 ;
V_101 = F_77 ( & V_28 -> V_37 , V_28 -> V_103 ) ;
if ( V_101 < 0 ) {
F_9 ( L_11 , V_28 -> V_103 ) ;
F_78 ( & V_28 -> V_37 ,
V_28 -> V_37 . V_104 , 0 ) ;
F_51 ( V_24 , 0 ) ;
return;
}
V_101 = F_79 ( V_24 , V_28 -> V_105 ) ;
if ( V_101 == - V_71 ) {
F_78 ( V_24 ,
V_106 , 0 ) ;
F_51 ( V_24 , 0 ) ;
return;
} else if ( V_101 < 0 ) {
if ( V_24 -> V_107 & V_108 )
F_46 ( V_24 ) ;
else
F_78 ( V_24 ,
V_24 -> V_104 , 0 ) ;
F_51 ( V_24 , 0 ) ;
return;
}
if ( V_28 -> V_39 ) {
V_99 = V_28 -> V_41 ;
#if 0
if (se_cmd->se_cmd_flags & SCF_BIDI) {
sg_bidi_ptr = NULL;
sg_no_bidi = 0;
}
#endif
} else {
V_99 = NULL ;
}
V_101 = F_80 ( V_24 , V_99 ,
V_28 -> V_39 , V_100 ,
V_102 ) ;
if ( V_101 < 0 ) {
F_78 ( V_24 ,
V_24 -> V_104 , 0 ) ;
F_51 ( V_24 , 0 ) ;
return;
}
F_81 ( V_24 ) ;
}
static void F_82 ( struct V_29 * V_30 )
{
struct V_109 * V_110 = & V_30 -> V_57 [ 2 ] ;
struct V_60 V_61 ;
struct V_3 * V_59 ;
struct V_27 * V_28 ;
T_3 V_62 , V_111 , V_112 , V_63 ;
unsigned V_113 , V_114 , V_40 ;
int V_115 , V_46 ;
V_59 = V_30 -> V_116 ;
if ( F_83 ( ! V_59 ) ) {
F_9 ( L_12 , V_47 ) ;
return;
}
F_84 ( & V_110 -> V_117 ) ;
F_85 ( & V_30 -> V_35 , V_110 ) ;
for (; ; ) {
V_115 = F_86 ( & V_30 -> V_35 , V_110 , V_110 -> V_92 ,
F_87 ( V_110 -> V_92 ) , & V_113 , & V_114 ,
NULL , NULL ) ;
F_59 ( L_13 ,
V_115 , V_113 , V_114 ) ;
if ( F_83 ( V_115 < 0 ) )
break;
if ( V_115 == V_110 -> V_118 ) {
if ( F_83 ( F_88 ( & V_30 -> V_35 , V_110 ) ) ) {
F_85 ( & V_30 -> V_35 , V_110 ) ;
continue;
}
break;
}
if ( V_113 == 1 && V_114 == 1 ) {
V_63 = V_119 ;
V_111 = 0 ;
V_112 = 0 ;
} else if ( V_113 == 1 && V_114 > 1 ) {
V_63 = V_120 ;
V_111 = V_113 + 1 ;
V_112 = V_114 - 1 ;
} else if ( V_113 > 1 && V_114 == 1 ) {
V_63 = V_121 ;
V_111 = 1 ;
V_112 = V_113 - 1 ;
} else {
F_89 ( V_110 , L_14 ,
V_113 , V_114 ) ;
break;
}
if ( F_83 ( V_110 -> V_92 [ V_113 ] . V_95 !=
sizeof( struct V_44 ) ) ) {
F_89 ( V_110 , L_15
L_16 , V_110 -> V_92 [ V_113 ] . V_95 ) ;
break;
}
if ( F_83 ( V_110 -> V_92 [ 0 ] . V_95 != sizeof( V_61 ) ) ) {
F_89 ( V_110 , L_17
L_16 , V_110 -> V_92 [ 0 ] . V_95 ) ;
break;
}
F_59 ( L_18
L_19 , V_110 -> V_92 [ 0 ] . V_94 , sizeof( V_61 ) ) ;
V_46 = F_90 ( & V_61 , V_110 -> V_92 [ 0 ] . V_94 ,
sizeof( V_61 ) ) ;
if ( F_83 ( V_46 ) ) {
F_89 ( V_110 , L_20 ) ;
break;
}
V_62 = 0 ;
for ( V_40 = 0 ; V_40 < V_112 ; V_40 ++ )
V_62 += V_110 -> V_92 [ V_111 + V_40 ] . V_95 ;
V_28 = F_64 ( V_59 , & V_61 ,
V_62 , V_63 ) ;
if ( F_91 ( V_28 ) ) {
F_89 ( V_110 , L_21 ,
F_92 ( V_28 ) ) ;
break;
}
F_59 ( L_22
L_23 , V_28 , V_62 , V_63 ) ;
V_28 -> V_31 = V_30 ;
if ( F_83 ( V_110 -> V_92 [ V_113 ] . V_95 !=
sizeof( struct V_44 ) ) ) {
F_89 ( V_110 , L_15
L_24 ,
V_110 -> V_92 [ V_113 ] . V_95 , V_113 , V_114 ) ;
break;
}
V_28 -> V_56 = V_110 -> V_92 [ V_113 ] . V_94 ;
memcpy ( V_28 -> V_105 , V_61 . V_122 , V_123 ) ;
if ( F_83 ( F_93 ( V_28 -> V_105 ) >
V_123 ) ) {
F_89 ( V_110 , L_25
L_26 ,
F_93 ( V_28 -> V_105 ) ,
V_123 ) ;
break;
}
V_28 -> V_103 = ( ( V_61 . V_124 [ 2 ] << 8 ) | V_61 . V_124 [ 3 ] ) & 0x3FFF ;
F_59 ( L_27 ,
V_28 -> V_105 [ 0 ] , V_28 -> V_103 ) ;
if ( V_63 != V_119 ) {
V_46 = F_73 ( V_28 ,
& V_110 -> V_92 [ V_111 ] , V_112 ,
V_63 == V_121 ) ;
if ( F_83 ( V_46 ) ) {
F_89 ( V_110 , L_28 ) ;
break;
}
}
V_28 -> V_58 = V_115 ;
F_94 ( & V_28 -> V_43 , F_76 ) ;
F_95 ( V_125 , & V_28 -> V_43 ) ;
}
F_96 ( & V_110 -> V_117 ) ;
}
static void F_97 ( struct V_42 * V_43 )
{
F_59 ( L_29 , V_47 ) ;
}
static void F_98 ( struct V_42 * V_43 )
{
F_59 ( L_30 , V_47 ) ;
}
static void F_99 ( struct V_42 * V_43 )
{
struct V_109 * V_110 = F_5 ( V_43 , struct V_109 ,
V_126 . V_43 ) ;
struct V_29 * V_30 = F_5 ( V_110 -> V_35 , struct V_29 , V_35 ) ;
F_82 ( V_30 ) ;
}
static int F_100 (
struct V_29 * V_30 ,
struct V_127 * V_128 )
{
struct V_5 * V_129 ;
struct V_3 * V_59 ;
int V_130 ;
F_84 ( & V_30 -> V_35 . V_117 ) ;
for ( V_130 = 0 ; V_130 < V_30 -> V_35 . V_131 ; ++ V_130 ) {
if ( ! F_101 ( & V_30 -> V_57 [ V_130 ] ) ) {
F_96 ( & V_30 -> V_35 . V_117 ) ;
return - V_132 ;
}
}
F_96 ( & V_30 -> V_35 . V_117 ) ;
F_84 ( & V_133 ) ;
F_56 (tv_tpg, &tcm_vhost_list, tv_tpg_list) {
F_84 ( & V_59 -> V_134 ) ;
if ( ! V_59 -> V_67 ) {
F_96 ( & V_59 -> V_134 ) ;
continue;
}
if ( V_59 -> V_135 != 0 ) {
F_96 ( & V_59 -> V_134 ) ;
continue;
}
V_129 = V_59 -> V_6 ;
if ( ! strcmp ( V_129 -> V_11 , V_128 -> V_136 ) &&
( V_59 -> V_12 == V_128 -> V_137 ) ) {
V_59 -> V_135 ++ ;
F_96 ( & V_59 -> V_134 ) ;
F_96 ( & V_133 ) ;
F_84 ( & V_30 -> V_35 . V_117 ) ;
if ( V_30 -> V_116 ) {
F_96 ( & V_30 -> V_35 . V_117 ) ;
F_84 ( & V_59 -> V_134 ) ;
V_59 -> V_135 -- ;
F_96 ( & V_59 -> V_134 ) ;
return - V_138 ;
}
V_30 -> V_116 = V_59 ;
F_102 () ;
F_96 ( & V_30 -> V_35 . V_117 ) ;
return 0 ;
}
F_96 ( & V_59 -> V_134 ) ;
}
F_96 ( & V_133 ) ;
return - V_139 ;
}
static int F_103 (
struct V_29 * V_30 ,
struct V_127 * V_128 )
{
struct V_5 * V_129 ;
struct V_3 * V_59 ;
int V_130 , V_46 ;
F_84 ( & V_30 -> V_35 . V_117 ) ;
for ( V_130 = 0 ; V_130 < V_30 -> V_35 . V_131 ; ++ V_130 ) {
if ( ! F_101 ( & V_30 -> V_57 [ V_130 ] ) ) {
V_46 = - V_132 ;
goto V_90;
}
}
if ( ! V_30 -> V_116 ) {
V_46 = - V_140 ;
goto V_90;
}
V_59 = V_30 -> V_116 ;
V_129 = V_59 -> V_6 ;
if ( strcmp ( V_129 -> V_11 , V_128 -> V_136 ) ||
( V_59 -> V_12 != V_128 -> V_137 ) ) {
F_104 ( L_31
L_32 ,
V_129 -> V_11 , V_59 -> V_12 ,
V_128 -> V_136 , V_128 -> V_137 ) ;
V_46 = - V_139 ;
goto V_90;
}
V_59 -> V_135 -- ;
V_30 -> V_116 = NULL ;
F_96 ( & V_30 -> V_35 . V_117 ) ;
return 0 ;
V_90:
F_96 ( & V_30 -> V_35 . V_117 ) ;
return V_46 ;
}
static int F_105 ( struct V_141 * V_141 , struct V_142 * V_143 )
{
struct V_29 * V_144 ;
int V_145 ;
V_144 = F_26 ( sizeof( * V_144 ) , V_23 ) ;
if ( ! V_144 )
return - V_71 ;
F_106 ( & V_144 -> V_36 , F_58 ) ;
F_66 ( & V_144 -> V_34 ) ;
F_107 ( & V_144 -> V_32 ) ;
V_144 -> V_57 [ V_146 ] . V_147 = F_97 ;
V_144 -> V_57 [ V_148 ] . V_147 = F_98 ;
V_144 -> V_57 [ V_149 ] . V_147 = F_99 ;
V_145 = F_108 ( & V_144 -> V_35 , V_144 -> V_57 , 3 ) ;
if ( V_145 < 0 ) {
F_28 ( V_144 ) ;
return V_145 ;
}
V_143 -> V_150 = V_144 ;
return 0 ;
}
static int F_109 ( struct V_141 * V_141 , struct V_142 * V_143 )
{
struct V_29 * V_144 = V_143 -> V_150 ;
if ( V_144 -> V_116 && V_144 -> V_116 -> V_6 ) {
struct V_127 V_151 ;
memcpy ( V_151 . V_136 , V_144 -> V_116 -> V_6 -> V_11 ,
sizeof( V_151 . V_136 ) ) ;
V_151 . V_137 = V_144 -> V_116 -> V_12 ;
F_103 ( V_144 , & V_151 ) ;
}
F_110 ( & V_144 -> V_35 , false ) ;
F_28 ( V_144 ) ;
return 0 ;
}
static void F_111 ( struct V_29 * V_30 , int V_130 )
{
F_112 ( & V_30 -> V_35 . V_57 [ V_130 ] . V_126 ) ;
}
static void F_113 ( struct V_29 * V_30 )
{
F_111 ( V_30 , V_146 ) ;
F_111 ( V_30 , V_148 ) ;
F_111 ( V_30 , V_149 ) ;
}
static int F_114 ( struct V_29 * V_30 , T_6 V_152 )
{
if ( V_152 & ~ V_153 )
return - V_154 ;
F_84 ( & V_30 -> V_35 . V_117 ) ;
if ( ( V_152 & ( 1 << V_155 ) ) &&
! F_115 ( & V_30 -> V_35 ) ) {
F_96 ( & V_30 -> V_35 . V_117 ) ;
return - V_132 ;
}
V_30 -> V_35 . V_156 = V_152 ;
F_116 () ;
F_113 ( V_30 ) ;
F_96 ( & V_30 -> V_35 . V_117 ) ;
return 0 ;
}
static long F_117 ( struct V_142 * V_143 , unsigned int V_157 ,
unsigned long V_158 )
{
struct V_29 * V_30 = V_143 -> V_150 ;
struct V_127 V_151 ;
void T_4 * V_159 = ( void T_4 * ) V_158 ;
T_6 T_4 * V_160 = V_159 ;
T_6 V_152 ;
int V_145 , V_161 = V_162 ;
switch ( V_157 ) {
case V_163 :
if ( F_118 ( & V_151 , V_159 , sizeof V_151 ) )
return - V_132 ;
if ( V_151 . V_164 != 0 )
return - V_154 ;
return F_100 ( V_30 , & V_151 ) ;
case V_165 :
if ( F_118 ( & V_151 , V_159 , sizeof V_151 ) )
return - V_132 ;
if ( V_151 . V_164 != 0 )
return - V_154 ;
return F_103 ( V_30 , & V_151 ) ;
case V_166 :
if ( F_60 ( V_159 , & V_161 , sizeof V_161 ) )
return - V_132 ;
return 0 ;
case V_167 :
V_152 = V_153 ;
if ( F_60 ( V_160 , & V_152 , sizeof V_152 ) )
return - V_132 ;
return 0 ;
case V_168 :
if ( F_118 ( & V_152 , V_160 , sizeof V_152 ) )
return - V_132 ;
return F_114 ( V_30 , V_152 ) ;
default:
F_84 ( & V_30 -> V_35 . V_117 ) ;
V_145 = F_119 ( & V_30 -> V_35 , V_157 , V_158 ) ;
F_96 ( & V_30 -> V_35 . V_117 ) ;
return V_145 ;
}
}
static long F_120 ( struct V_142 * V_143 , unsigned int V_157 ,
unsigned long V_158 )
{
return F_117 ( V_143 , V_157 , ( unsigned long ) F_121 ( V_158 ) ) ;
}
static int T_7 F_122 ( void )
{
return F_123 ( & V_169 ) ;
}
static int F_124 ( void )
{
return F_125 ( & V_169 ) ;
}
static char * F_126 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 ) {
case V_8 :
return L_33 ;
case V_9 :
return L_34 ;
case V_10 :
return L_35 ;
default:
break;
}
return L_36 ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_170 * V_124 )
{
struct V_3 * V_59 = F_5 ( V_2 ,
struct V_3 , V_2 ) ;
F_84 ( & V_59 -> V_134 ) ;
V_59 -> V_171 ++ ;
F_96 ( & V_59 -> V_134 ) ;
return 0 ;
}
static void F_128 ( struct V_1 * V_2 ,
struct V_170 * V_170 )
{
struct V_3 * V_59 = F_5 ( V_2 ,
struct V_3 , V_2 ) ;
F_84 ( & V_59 -> V_134 ) ;
V_59 -> V_171 -- ;
F_96 ( & V_59 -> V_134 ) ;
}
static struct V_13 * F_129 (
struct V_1 * V_2 ,
struct V_172 * V_173 ,
const char * V_174 )
{
struct V_13 * V_14 , * V_175 ;
struct V_21 * V_22 ;
T_6 V_176 = 0 ;
T_3 V_177 ;
V_175 = F_25 ( V_2 ) ;
if ( ! V_175 )
return F_65 ( - V_71 ) ;
V_177 = 1 ;
V_14 = F_130 ( V_2 , V_175 ,
V_174 , V_177 ) ;
if ( F_91 ( V_14 ) ) {
F_27 ( V_2 , V_175 ) ;
return V_14 ;
}
V_22 = F_5 ( V_14 , struct V_21 , V_13 ) ;
V_22 -> V_178 = V_176 ;
return V_14 ;
}
static void F_131 ( struct V_13 * V_179 )
{
struct V_21 * V_22 = F_5 ( V_179 ,
struct V_21 , V_13 ) ;
F_132 ( V_179 -> V_2 , V_179 , 1 ) ;
F_28 ( V_22 ) ;
}
static int F_133 ( struct V_3 * V_59 ,
const char * V_174 )
{
struct V_1 * V_2 ;
struct V_64 * V_65 ;
F_84 ( & V_59 -> V_134 ) ;
if ( V_59 -> V_67 ) {
F_96 ( & V_59 -> V_134 ) ;
F_59 ( L_37 ) ;
return - V_138 ;
}
V_2 = & V_59 -> V_2 ;
V_65 = F_26 ( sizeof( struct V_64 ) , V_23 ) ;
if ( ! V_65 ) {
F_96 ( & V_59 -> V_134 ) ;
F_9 ( L_38 ) ;
return - V_71 ;
}
V_65 -> V_69 = F_134 () ;
if ( F_91 ( V_65 -> V_69 ) ) {
F_96 ( & V_59 -> V_134 ) ;
F_28 ( V_65 ) ;
return - V_71 ;
}
V_65 -> V_69 -> V_13 = F_135 (
V_2 , ( unsigned char * ) V_174 ) ;
if ( ! V_65 -> V_69 -> V_13 ) {
F_96 ( & V_59 -> V_134 ) ;
F_59 ( L_39
L_40 , V_174 ) ;
F_136 ( V_65 -> V_69 ) ;
F_28 ( V_65 ) ;
return - V_71 ;
}
F_137 ( V_2 , V_65 -> V_69 -> V_13 ,
V_65 -> V_69 , V_65 ) ;
V_59 -> V_67 = V_65 ;
F_96 ( & V_59 -> V_134 ) ;
return 0 ;
}
static int F_138 ( struct V_3 * V_4 )
{
struct V_25 * V_26 ;
struct V_64 * V_65 ;
F_84 ( & V_4 -> V_134 ) ;
V_65 = V_4 -> V_67 ;
if ( ! V_65 ) {
F_96 ( & V_4 -> V_134 ) ;
return - V_140 ;
}
V_26 = V_65 -> V_69 ;
if ( ! V_26 ) {
F_96 ( & V_4 -> V_134 ) ;
return - V_140 ;
}
if ( V_4 -> V_171 != 0 ) {
F_96 ( & V_4 -> V_134 ) ;
F_9 ( L_41
L_42 ,
V_4 -> V_171 ) ;
return - V_180 ;
}
if ( V_4 -> V_135 != 0 ) {
F_96 ( & V_4 -> V_134 ) ;
F_9 ( L_41
L_43 ,
V_4 -> V_135 ) ;
return - V_180 ;
}
F_59 ( L_44
L_45 , F_126 ( V_4 -> V_6 ) ,
V_65 -> V_69 -> V_13 -> V_181 ) ;
F_139 ( V_65 -> V_69 ) ;
V_4 -> V_67 = NULL ;
F_96 ( & V_4 -> V_134 ) ;
F_28 ( V_65 ) ;
return 0 ;
}
static T_8 F_140 ( struct V_1 * V_2 ,
char * V_84 )
{
struct V_3 * V_59 = F_5 ( V_2 ,
struct V_3 , V_2 ) ;
struct V_64 * V_65 ;
T_8 V_46 ;
F_84 ( & V_59 -> V_134 ) ;
V_65 = V_59 -> V_67 ;
if ( ! V_65 ) {
F_96 ( & V_59 -> V_134 ) ;
return - V_140 ;
}
V_46 = snprintf ( V_84 , V_96 , L_46 ,
V_65 -> V_69 -> V_13 -> V_181 ) ;
F_96 ( & V_59 -> V_134 ) ;
return V_46 ;
}
static T_8 F_141 ( struct V_1 * V_2 ,
const char * V_84 ,
T_5 V_182 )
{
struct V_3 * V_59 = F_5 ( V_2 ,
struct V_3 , V_2 ) ;
struct V_5 * V_183 = V_59 -> V_6 ;
unsigned char V_184 [ V_185 ] , * V_79 , * V_186 ;
int V_46 ;
if ( ! strncmp ( V_84 , L_47 , 4 ) ) {
V_46 = F_138 ( V_59 ) ;
return ( ! V_46 ) ? V_182 : V_46 ;
}
if ( strlen ( V_84 ) >= V_185 ) {
F_9 ( L_48
L_49 , V_84 , V_185 ) ;
return - V_139 ;
}
snprintf ( & V_184 [ 0 ] , V_185 , L_50 , V_84 ) ;
V_79 = strstr ( V_184 , L_51 ) ;
if ( V_79 ) {
if ( V_183 -> V_7 != V_8 ) {
F_9 ( L_52
L_53 , V_184 ,
F_126 ( V_183 ) ) ;
return - V_139 ;
}
V_186 = & V_184 [ 0 ] ;
goto V_187;
}
V_79 = strstr ( V_184 , L_54 ) ;
if ( V_79 ) {
if ( V_183 -> V_7 != V_9 ) {
F_9 ( L_55
L_53 , V_184 ,
F_126 ( V_183 ) ) ;
return - V_139 ;
}
V_186 = & V_184 [ 3 ] ;
goto V_187;
}
V_79 = strstr ( V_184 , L_56 ) ;
if ( V_79 ) {
if ( V_183 -> V_7 != V_10 ) {
F_9 ( L_57
L_53 , V_184 ,
F_126 ( V_183 ) ) ;
return - V_139 ;
}
V_186 = & V_184 [ 0 ] ;
goto V_187;
}
F_9 ( L_58
L_59 , V_184 ) ;
return - V_139 ;
V_187:
if ( V_184 [ strlen ( V_184 ) - 1 ] == '\n' )
V_184 [ strlen ( V_184 ) - 1 ] = '\0' ;
V_46 = F_133 ( V_59 , V_186 ) ;
if ( V_46 < 0 )
return V_46 ;
return V_182 ;
}
static struct V_1 * F_142 ( struct V_188 * V_189 ,
struct V_172 * V_173 ,
const char * V_174 )
{
struct V_5 * V_6 = F_5 ( V_189 ,
struct V_5 , V_183 ) ;
struct V_3 * V_4 ;
unsigned long V_190 ;
int V_46 ;
if ( strstr ( V_174 , L_60 ) != V_174 )
return F_65 ( - V_139 ) ;
if ( F_143 ( V_174 + 5 , 10 , & V_190 ) || V_190 > V_191 )
return F_65 ( - V_139 ) ;
V_4 = F_26 ( sizeof( struct V_3 ) , V_23 ) ;
if ( ! V_4 ) {
F_9 ( L_61 ) ;
return F_65 ( - V_71 ) ;
}
F_144 ( & V_4 -> V_134 ) ;
F_66 ( & V_4 -> V_192 ) ;
V_4 -> V_6 = V_6 ;
V_4 -> V_12 = V_190 ;
V_46 = F_145 ( & V_193 -> V_194 , V_189 ,
& V_4 -> V_2 , V_4 , V_195 ) ;
if ( V_46 < 0 ) {
F_28 ( V_4 ) ;
return NULL ;
}
F_84 ( & V_133 ) ;
F_42 ( & V_4 -> V_192 , & V_196 ) ;
F_96 ( & V_133 ) ;
return & V_4 -> V_2 ;
}
static void F_146 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( V_2 ,
struct V_3 , V_2 ) ;
F_84 ( & V_133 ) ;
F_57 ( & V_4 -> V_192 ) ;
F_96 ( & V_133 ) ;
F_138 ( V_4 ) ;
F_147 ( V_2 ) ;
F_28 ( V_4 ) ;
}
static struct V_188 * F_148 ( struct V_197 * V_198 ,
struct V_172 * V_173 ,
const char * V_174 )
{
struct V_5 * V_6 ;
char * V_79 ;
T_6 V_176 = 0 ;
int V_199 = 0 ;
V_6 = F_26 ( sizeof( struct V_5 ) , V_23 ) ;
if ( ! V_6 ) {
F_9 ( L_62 ) ;
return F_65 ( - V_71 ) ;
}
V_6 -> V_200 = V_176 ;
V_79 = strstr ( V_174 , L_51 ) ;
if ( V_79 ) {
V_6 -> V_7 = V_8 ;
goto V_201;
}
V_79 = strstr ( V_174 , L_54 ) ;
if ( V_79 ) {
V_6 -> V_7 = V_9 ;
V_199 = 3 ;
goto V_201;
}
V_79 = strstr ( V_174 , L_56 ) ;
if ( V_79 ) {
V_6 -> V_7 = V_10 ;
goto V_201;
}
F_9 ( L_63
L_59 , V_174 ) ;
F_28 ( V_6 ) ;
return F_65 ( - V_139 ) ;
V_201:
if ( strlen ( V_174 ) >= V_185 ) {
F_9 ( L_64
L_49 , V_174 , F_126 ( V_6 ) ,
V_185 ) ;
F_28 ( V_6 ) ;
return F_65 ( - V_139 ) ;
}
snprintf ( & V_6 -> V_11 [ 0 ] , V_185 , L_50 , & V_174 [ V_199 ] ) ;
F_59 ( L_65
L_66 , F_126 ( V_6 ) , V_174 ) ;
return & V_6 -> V_183 ;
}
static void F_149 ( struct V_188 * V_189 )
{
struct V_5 * V_6 = F_5 ( V_189 ,
struct V_5 , V_183 ) ;
F_59 ( L_67
L_66 , F_126 ( V_6 ) ,
V_6 -> V_11 ) ;
F_28 ( V_6 ) ;
}
static T_8 F_150 (
struct V_197 * V_198 ,
char * V_84 )
{
return sprintf ( V_84 , L_68
L_69 V_202 L_70 , V_203 , F_151 () -> V_204 ,
F_151 () -> V_205 ) ;
}
static int F_152 ( void )
{
struct V_197 * V_206 ;
int V_46 ;
F_59 ( L_68
L_71 V_202 L_70 , V_203 , F_151 () -> V_204 ,
F_151 () -> V_205 ) ;
V_206 = F_153 ( V_207 , L_1 ) ;
if ( F_91 ( V_206 ) ) {
F_9 ( L_72 ) ;
return F_92 ( V_206 ) ;
}
V_206 -> V_194 = V_208 ;
F_154 ( V_206 ) -> V_209 . V_210 = V_211 ;
F_154 ( V_206 ) -> V_212 . V_210 = V_213 ;
F_154 ( V_206 ) -> V_214 . V_210 = NULL ;
F_154 ( V_206 ) -> V_215 . V_210 = NULL ;
F_154 ( V_206 ) -> V_216 . V_210 = NULL ;
F_154 ( V_206 ) -> V_217 . V_210 = NULL ;
F_154 ( V_206 ) -> V_218 . V_210 = NULL ;
F_154 ( V_206 ) -> V_219 . V_210 = NULL ;
F_154 ( V_206 ) -> V_220 . V_210 = NULL ;
V_46 = F_155 ( V_206 ) ;
if ( V_46 < 0 ) {
F_9 ( L_73
L_74 ) ;
return V_46 ;
}
V_193 = V_206 ;
F_59 ( L_75 ) ;
return 0 ;
}
static void F_156 ( void )
{
if ( ! V_193 )
return;
F_157 ( V_193 ) ;
V_193 = NULL ;
F_59 ( L_76 ) ;
}
static int T_7 F_158 ( void )
{
int V_46 = - V_71 ;
V_125 = F_159 ( L_77 , 0 , 0 ) ;
if ( ! V_125 )
goto V_113;
V_46 = F_122 () ;
if ( V_46 < 0 )
goto V_221;
V_46 = F_152 () ;
if ( V_46 < 0 )
goto V_222;
return 0 ;
V_222:
F_124 () ;
V_221:
F_160 ( V_125 ) ;
V_113:
return V_46 ;
}
static void F_161 ( void )
{
F_156 () ;
F_124 () ;
F_160 ( V_125 ) ;
}
