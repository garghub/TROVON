static int F_1 ( struct V_1 * V_2 )
{
return ( F_2 ( ( unsigned long ) V_2 -> V_3 + V_2 -> V_4 ) -
( ( unsigned long ) V_2 -> V_3 & V_5 ) ) >> V_6 ;
}
static int F_3 ( struct V_7 * V_8 )
{
return 1 ;
}
static int F_4 ( struct V_7 * V_8 )
{
return 0 ;
}
static char * F_5 ( void )
{
return L_1 ;
}
static T_1 F_6 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_7 ( V_8 ,
struct V_9 , V_8 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
switch ( V_12 -> V_13 ) {
case V_14 :
return F_8 ( V_8 ) ;
case V_15 :
return F_9 ( V_8 ) ;
case V_16 :
return F_10 ( V_8 ) ;
default:
F_11 ( L_2
L_3 , V_12 -> V_13 ) ;
break;
}
return F_8 ( V_8 ) ;
}
static char * F_12 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_7 ( V_8 ,
struct V_9 , V_8 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
return & V_12 -> V_17 [ 0 ] ;
}
static T_2 F_13 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_7 ( V_8 ,
struct V_9 , V_8 ) ;
return V_10 -> V_18 ;
}
static T_3 F_14 ( struct V_7 * V_8 )
{
return 1 ;
}
static T_3 F_15 ( struct V_7 * V_8 ,
struct V_19 * V_20 ,
struct V_21 * V_22 ,
int * V_23 ,
unsigned char * V_24 )
{
struct V_9 * V_10 = F_7 ( V_8 ,
struct V_9 , V_8 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
switch ( V_12 -> V_13 ) {
case V_14 :
return F_16 ( V_8 , V_20 , V_22 ,
V_23 , V_24 ) ;
case V_15 :
return F_17 ( V_8 , V_20 , V_22 ,
V_23 , V_24 ) ;
case V_16 :
return F_18 ( V_8 , V_20 , V_22 ,
V_23 , V_24 ) ;
default:
F_11 ( L_2
L_3 , V_12 -> V_13 ) ;
break;
}
return F_16 ( V_8 , V_20 , V_22 ,
V_23 , V_24 ) ;
}
static T_3 F_19 ( struct V_7 * V_8 ,
struct V_19 * V_20 ,
struct V_21 * V_22 ,
int * V_23 )
{
struct V_9 * V_10 = F_7 ( V_8 ,
struct V_9 , V_8 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
switch ( V_12 -> V_13 ) {
case V_14 :
return F_20 ( V_8 , V_20 , V_22 ,
V_23 ) ;
case V_15 :
return F_21 ( V_8 , V_20 , V_22 ,
V_23 ) ;
case V_16 :
return F_22 ( V_8 , V_20 , V_22 ,
V_23 ) ;
default:
F_11 ( L_2
L_3 , V_12 -> V_13 ) ;
break;
}
return F_20 ( V_8 , V_20 , V_22 ,
V_23 ) ;
}
static char * F_23 ( struct V_7 * V_8 ,
const char * V_24 ,
T_3 * V_25 ,
char * * V_26 )
{
struct V_9 * V_10 = F_7 ( V_8 ,
struct V_9 , V_8 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
switch ( V_12 -> V_13 ) {
case V_14 :
return F_24 ( V_8 , V_24 , V_25 ,
V_26 ) ;
case V_15 :
return F_25 ( V_8 , V_24 , V_25 ,
V_26 ) ;
case V_16 :
return F_26 ( V_8 , V_24 , V_25 ,
V_26 ) ;
default:
F_11 ( L_2
L_3 , V_12 -> V_13 ) ;
break;
}
return F_24 ( V_8 , V_24 , V_25 ,
V_26 ) ;
}
static struct V_19 * F_27 (
struct V_7 * V_8 )
{
struct V_27 * V_28 ;
V_28 = F_28 ( sizeof( struct V_27 ) , V_29 ) ;
if ( ! V_28 ) {
F_11 ( L_4 ) ;
return NULL ;
}
return & V_28 -> V_19 ;
}
static void F_29 ( struct V_7 * V_8 ,
struct V_19 * V_20 )
{
struct V_27 * V_28 = F_7 ( V_20 ,
struct V_27 , V_19 ) ;
F_30 ( V_28 ) ;
}
static T_3 F_31 ( struct V_7 * V_8 )
{
return 1 ;
}
static void F_32 ( struct V_30 * V_30 )
{
return;
}
static int F_33 ( struct V_31 * V_32 )
{
return 0 ;
}
static void F_34 ( struct V_31 * V_32 )
{
return;
}
static T_3 F_35 ( struct V_31 * V_32 )
{
return 0 ;
}
static int F_36 ( struct V_30 * V_30 )
{
F_37 ( V_30 ) ;
return 0 ;
}
static int F_38 ( struct V_30 * V_30 )
{
return 0 ;
}
static void F_39 ( struct V_19 * V_28 )
{
return;
}
static T_3 F_40 ( struct V_30 * V_30 )
{
return 0 ;
}
static int F_41 ( struct V_30 * V_30 )
{
return 0 ;
}
static void F_42 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_37 ;
F_43 ( & V_34 -> V_38 , & V_36 -> V_39 ) ;
F_44 ( & V_36 -> V_40 , & V_36 -> V_41 ) ;
}
static int F_45 ( struct V_30 * V_30 )
{
struct V_33 * V_34 = F_7 ( V_30 ,
struct V_33 , V_42 ) ;
F_42 ( V_34 ) ;
return 0 ;
}
static int F_46 ( struct V_30 * V_30 )
{
struct V_33 * V_34 = F_7 ( V_30 ,
struct V_33 , V_42 ) ;
F_42 ( V_34 ) ;
return 0 ;
}
static int F_47 ( struct V_30 * V_30 )
{
return 0 ;
}
static void F_48 ( struct V_33 * V_34 )
{
struct V_30 * V_30 = & V_34 -> V_42 ;
F_49 ( V_30 , 1 ) ;
if ( V_34 -> V_43 ) {
T_3 V_44 ;
for ( V_44 = 0 ; V_44 < V_34 -> V_43 ; V_44 ++ )
F_50 ( F_51 ( & V_34 -> V_45 [ V_44 ] ) ) ;
F_30 ( V_34 -> V_45 ) ;
}
F_30 ( V_34 ) ;
}
static void F_52 ( struct V_46 * V_47 )
{
struct V_35 * V_36 = F_7 ( V_47 , struct V_35 ,
V_41 ) ;
F_53 ( signal , V_48 ) ;
struct V_49 V_50 ;
struct V_33 * V_34 ;
struct V_51 * V_52 ;
struct V_30 * V_30 ;
int V_53 , V_54 ;
F_54 ( signal , V_48 ) ;
V_52 = F_55 ( & V_36 -> V_39 ) ;
while ( V_52 ) {
V_34 = F_56 ( V_52 , struct V_33 ,
V_38 ) ;
V_52 = F_57 ( V_52 ) ;
V_30 = & V_34 -> V_42 ;
F_58 ( L_5 , V_55 ,
V_34 , V_30 -> V_56 , V_30 -> V_57 ) ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_58 = V_30 -> V_56 ;
V_50 . V_59 = V_30 -> V_57 ;
V_50 . V_60 = V_30 -> V_61 ;
memcpy ( V_50 . V_62 , V_34 -> V_63 ,
V_50 . V_60 ) ;
V_53 = F_59 ( V_34 -> V_64 , & V_50 , sizeof( V_50 ) ) ;
if ( F_60 ( V_53 == 0 ) ) {
F_61 ( V_34 -> V_65 , V_34 -> V_66 , 0 ) ;
V_54 = V_34 -> V_65 - V_36 -> V_67 ;
F_62 ( V_54 , signal ) ;
} else
F_11 ( L_6 ) ;
F_48 ( V_34 ) ;
}
V_54 = - 1 ;
while ( ( V_54 = F_63 ( signal , V_48 , V_54 + 1 ) )
< V_48 )
F_64 ( & V_36 -> V_40 , & V_36 -> V_67 [ V_54 ] ) ;
}
static struct V_33 * F_65 (
struct V_9 * V_68 ,
struct V_69 * V_70 ,
T_3 V_71 ,
int V_72 )
{
struct V_33 * V_34 ;
struct V_73 * V_74 ;
V_74 = V_68 -> V_75 ;
if ( ! V_74 ) {
F_11 ( L_7 ) ;
return F_66 ( - V_76 ) ;
}
V_34 = F_28 ( sizeof( struct V_33 ) , V_77 ) ;
if ( ! V_34 ) {
F_11 ( L_8 ) ;
return F_66 ( - V_78 ) ;
}
V_34 -> V_79 = V_70 -> V_80 ;
V_34 -> V_81 = V_70 -> V_82 ;
V_34 -> V_83 = V_71 ;
V_34 -> V_84 = V_72 ;
V_34 -> V_85 = V_74 ;
return V_34 ;
}
static int F_67 ( struct V_86 * V_87 ,
unsigned int V_88 , struct V_1 * V_2 , int V_89 )
{
unsigned int V_90 = 0 , V_91 , V_92 , V_93 ;
struct V_86 * V_94 = V_87 ;
void T_4 * V_95 = V_2 -> V_3 ;
T_5 V_96 = V_2 -> V_4 ;
struct V_97 * * V_98 ;
int V_53 , V_44 ;
V_91 = F_1 ( V_2 ) ;
if ( V_91 > V_88 )
return - V_99 ;
V_98 = F_68 ( V_91 * sizeof( struct V_97 * ) , V_29 ) ;
if ( ! V_98 )
return - V_78 ;
V_53 = F_69 ( ( unsigned long ) V_95 , V_91 , V_89 , V_98 ) ;
if ( V_53 < 0 )
goto V_100;
if ( V_53 != V_91 ) {
for ( V_44 = 0 ; V_44 < V_53 ; V_44 ++ )
F_50 ( V_98 [ V_44 ] ) ;
V_53 = - V_101 ;
goto V_100;
}
while ( V_96 > 0 ) {
V_92 = ( V_102 ) V_95 & ~ V_5 ;
V_93 = F_70 (unsigned int, PAGE_SIZE - offset, len) ;
F_71 ( V_94 , V_98 [ V_90 ] , V_93 , V_92 ) ;
V_95 += V_93 ;
V_96 -= V_93 ;
V_94 ++ ;
V_90 ++ ;
}
V_100:
F_30 ( V_98 ) ;
return V_53 ;
}
static int F_72 ( struct V_33 * V_34 ,
struct V_1 * V_2 , unsigned int V_103 , int V_89 )
{
int V_53 ;
unsigned int V_44 ;
T_3 V_88 ;
struct V_86 * V_94 ;
V_88 = 0 ;
for ( V_44 = 0 ; V_44 < V_103 ; V_44 ++ )
V_88 += F_1 ( & V_2 [ V_44 ] ) ;
V_94 = F_68 ( sizeof( V_34 -> V_45 [ 0 ] ) * V_88 , V_77 ) ;
if ( ! V_94 )
return - V_78 ;
F_58 ( L_9 , V_55 ,
V_94 , V_88 , ! V_94 ) ;
F_73 ( V_94 , V_88 ) ;
V_34 -> V_45 = V_94 ;
V_34 -> V_43 = V_88 ;
F_58 ( L_10 , V_103 , V_88 ) ;
for ( V_44 = 0 ; V_44 < V_103 ; V_44 ++ ) {
V_53 = F_67 ( V_94 , V_88 , & V_2 [ V_44 ] , V_89 ) ;
if ( V_53 < 0 ) {
for ( V_44 = 0 ; V_44 < V_34 -> V_43 ; V_44 ++ )
F_50 ( F_51 ( & V_34 -> V_45 [ V_44 ] ) ) ;
F_30 ( V_34 -> V_45 ) ;
V_34 -> V_45 = NULL ;
V_34 -> V_43 = 0 ;
return V_53 ;
}
V_94 += V_53 ;
V_88 -= V_53 ;
}
return 0 ;
}
static void F_74 ( struct V_104 * V_47 )
{
struct V_33 * V_34 =
F_7 ( V_47 , struct V_33 , V_47 ) ;
struct V_73 * V_74 ;
struct V_30 * V_30 = & V_34 -> V_42 ;
struct V_86 * V_105 , * V_106 = NULL ;
int V_107 , V_108 = 0 ;
if ( V_34 -> V_43 ) {
V_105 = V_34 -> V_45 ;
#if 0
if (se_cmd->se_cmd_flags & SCF_BIDI) {
sg_bidi_ptr = NULL;
sg_no_bidi = 0;
}
#endif
} else {
V_105 = NULL ;
}
V_74 = V_34 -> V_85 ;
V_107 = F_75 ( V_30 , V_74 -> V_109 ,
V_34 -> V_110 , & V_34 -> V_63 [ 0 ] ,
V_34 -> V_111 , V_34 -> V_83 ,
V_34 -> V_81 , V_34 -> V_84 ,
0 , V_105 , V_34 -> V_43 ,
V_106 , V_108 ) ;
if ( V_107 < 0 ) {
F_76 ( V_30 ,
V_112 , 0 ) ;
F_49 ( V_30 , 0 ) ;
}
}
static void F_77 ( struct V_35 * V_36 ,
struct V_113 * V_54 , int V_114 , unsigned V_100 )
{
struct V_49 T_4 * V_115 ;
struct V_49 V_116 ;
int V_53 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_117 = V_118 ;
V_115 = V_54 -> V_2 [ V_100 ] . V_3 ;
V_53 = F_78 ( V_115 , & V_116 , sizeof( V_116 ) ) ;
if ( ! V_53 )
F_79 ( & V_36 -> V_40 , V_54 , V_114 , 0 ) ;
else
F_11 ( L_6 ) ;
}
static void F_80 ( struct V_35 * V_36 ,
struct V_113 * V_54 )
{
struct V_9 * * V_119 ;
struct V_69 V_70 ;
struct V_9 * V_68 ;
struct V_33 * V_34 ;
T_3 V_71 , V_120 , V_121 , V_72 ;
unsigned V_100 , V_122 , V_44 ;
int V_114 , V_53 ;
T_1 V_123 ;
V_119 = F_81 ( V_54 -> V_124 , 1 ) ;
if ( ! V_119 )
return;
F_82 ( & V_54 -> V_125 ) ;
F_83 ( & V_36 -> V_40 , V_54 ) ;
for (; ; ) {
V_114 = F_84 ( & V_36 -> V_40 , V_54 , V_54 -> V_2 ,
F_85 ( V_54 -> V_2 ) , & V_100 , & V_122 ,
NULL , NULL ) ;
F_58 ( L_11 ,
V_114 , V_100 , V_122 ) ;
if ( F_86 ( V_114 < 0 ) )
break;
if ( V_114 == V_54 -> V_126 ) {
if ( F_86 ( F_87 ( & V_36 -> V_40 , V_54 ) ) ) {
F_83 ( & V_36 -> V_40 , V_54 ) ;
continue;
}
break;
}
if ( V_100 == 1 && V_122 == 1 ) {
V_72 = V_127 ;
V_120 = 0 ;
V_121 = 0 ;
} else if ( V_100 == 1 && V_122 > 1 ) {
V_72 = V_128 ;
V_120 = V_100 + 1 ;
V_121 = V_122 - 1 ;
} else if ( V_100 > 1 && V_122 == 1 ) {
V_72 = V_129 ;
V_120 = 1 ;
V_121 = V_100 - 1 ;
} else {
F_88 ( V_54 , L_12 ,
V_100 , V_122 ) ;
break;
}
if ( F_86 ( V_54 -> V_2 [ V_100 ] . V_4 !=
sizeof( struct V_49 ) ) ) {
F_88 ( V_54 , L_13
L_14 , V_54 -> V_2 [ V_100 ] . V_4 ) ;
break;
}
if ( F_86 ( V_54 -> V_2 [ 0 ] . V_4 != sizeof( V_70 ) ) ) {
F_88 ( V_54 , L_15
L_14 , V_54 -> V_2 [ 0 ] . V_4 ) ;
break;
}
F_58 ( L_16
L_17 , V_54 -> V_2 [ 0 ] . V_3 , sizeof( V_70 ) ) ;
V_53 = F_89 ( & V_70 , V_54 -> V_2 [ 0 ] . V_3 ,
sizeof( V_70 ) ) ;
if ( F_86 ( V_53 ) ) {
F_88 ( V_54 , L_18 ) ;
break;
}
V_123 = V_70 . V_130 [ 1 ] ;
V_68 = F_90 ( V_119 [ V_123 ] ) ;
if ( F_86 ( ! V_68 ) ) {
F_77 ( V_36 , V_54 , V_114 , V_100 ) ;
continue;
}
V_71 = 0 ;
for ( V_44 = 0 ; V_44 < V_121 ; V_44 ++ )
V_71 += V_54 -> V_2 [ V_120 + V_44 ] . V_4 ;
V_34 = F_65 ( V_68 , & V_70 ,
V_71 , V_72 ) ;
if ( F_91 ( V_34 ) ) {
F_88 ( V_54 , L_19 ,
F_92 ( V_34 ) ) ;
goto V_131;
}
F_58 ( L_20
L_21 , V_34 , V_71 , V_72 ) ;
V_34 -> V_37 = V_36 ;
V_34 -> V_65 = V_54 ;
V_34 -> V_64 = V_54 -> V_2 [ V_100 ] . V_3 ;
memcpy ( V_34 -> V_110 , V_70 . V_132 , V_133 ) ;
if ( F_86 ( F_93 ( V_34 -> V_110 ) >
V_133 ) ) {
F_88 ( V_54 , L_22
L_23 ,
F_93 ( V_34 -> V_110 ) ,
V_133 ) ;
goto V_134;
}
V_34 -> V_111 = ( ( V_70 . V_130 [ 2 ] << 8 ) | V_70 . V_130 [ 3 ] ) & 0x3FFF ;
F_58 ( L_24 ,
V_34 -> V_110 [ 0 ] , V_34 -> V_111 ) ;
if ( V_72 != V_127 ) {
V_53 = F_72 ( V_34 ,
& V_54 -> V_2 [ V_120 ] , V_121 ,
V_72 == V_129 ) ;
if ( F_86 ( V_53 ) ) {
F_88 ( V_54 , L_25 ) ;
goto V_134;
}
}
V_34 -> V_66 = V_114 ;
F_94 ( & V_34 -> V_47 , F_74 ) ;
F_95 ( V_135 , & V_34 -> V_47 ) ;
}
F_96 ( & V_54 -> V_125 ) ;
return;
V_134:
F_48 ( V_34 ) ;
V_131:
F_77 ( V_36 , V_54 , V_114 , V_100 ) ;
F_96 ( & V_54 -> V_125 ) ;
}
static void F_97 ( struct V_46 * V_47 )
{
F_58 ( L_26 , V_55 ) ;
}
static void F_98 ( struct V_46 * V_47 )
{
F_58 ( L_27 , V_55 ) ;
}
static void F_99 ( struct V_46 * V_47 )
{
struct V_113 * V_54 = F_7 ( V_47 , struct V_113 ,
V_136 . V_47 ) ;
struct V_35 * V_36 = F_7 ( V_54 -> V_40 , struct V_35 , V_40 ) ;
F_80 ( V_36 , V_54 ) ;
}
static void F_100 ( struct V_35 * V_36 , int V_137 )
{
F_101 ( & V_36 -> V_40 . V_67 [ V_137 ] . V_136 ) ;
}
static void F_102 ( struct V_35 * V_36 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_48 ; V_44 ++ )
F_100 ( V_36 , V_44 ) ;
F_103 ( & V_36 -> V_40 , & V_36 -> V_41 ) ;
}
static int F_104 (
struct V_35 * V_36 ,
struct V_138 * V_139 )
{
struct V_11 * V_140 ;
struct V_9 * V_68 ;
struct V_9 * * V_119 ;
struct V_113 * V_54 ;
int V_137 , V_53 , V_44 , V_96 ;
bool V_141 = false ;
F_82 ( & V_36 -> V_40 . V_125 ) ;
for ( V_137 = 0 ; V_137 < V_36 -> V_40 . V_142 ; ++ V_137 ) {
if ( ! F_105 ( & V_36 -> V_67 [ V_137 ] ) ) {
F_96 ( & V_36 -> V_40 . V_125 ) ;
return - V_101 ;
}
}
V_96 = sizeof( V_119 [ 0 ] ) * V_143 ;
V_119 = F_28 ( V_96 , V_29 ) ;
if ( ! V_119 ) {
F_96 ( & V_36 -> V_40 . V_125 ) ;
return - V_78 ;
}
if ( V_36 -> V_119 )
memcpy ( V_119 , V_36 -> V_119 , V_96 ) ;
F_82 ( & V_144 ) ;
F_106 (tv_tpg, &tcm_vhost_list, tv_tpg_list) {
F_82 ( & V_68 -> V_145 ) ;
if ( ! V_68 -> V_75 ) {
F_96 ( & V_68 -> V_145 ) ;
continue;
}
if ( V_68 -> V_146 != 0 ) {
F_96 ( & V_68 -> V_145 ) ;
continue;
}
V_140 = V_68 -> V_12 ;
if ( ! strcmp ( V_140 -> V_17 , V_139 -> V_147 ) ) {
if ( V_36 -> V_119 && V_36 -> V_119 [ V_68 -> V_18 ] ) {
F_96 ( & V_68 -> V_145 ) ;
F_96 ( & V_144 ) ;
F_96 ( & V_36 -> V_40 . V_125 ) ;
F_30 ( V_119 ) ;
return - V_148 ;
}
V_68 -> V_146 ++ ;
V_119 [ V_68 -> V_18 ] = V_68 ;
F_107 () ;
V_141 = true ;
}
F_96 ( & V_68 -> V_145 ) ;
}
F_96 ( & V_144 ) ;
if ( V_141 ) {
memcpy ( V_36 -> V_149 , V_139 -> V_147 ,
sizeof( V_36 -> V_149 ) ) ;
for ( V_44 = 0 ; V_44 < V_48 ; V_44 ++ ) {
V_54 = & V_36 -> V_67 [ V_44 ] ;
F_82 ( & V_54 -> V_125 ) ;
F_108 ( V_54 -> V_124 , V_119 ) ;
F_109 ( V_54 ) ;
F_96 ( & V_54 -> V_125 ) ;
}
V_53 = 0 ;
} else {
V_53 = - V_148 ;
}
F_102 ( V_36 ) ;
F_30 ( V_36 -> V_119 ) ;
V_36 -> V_119 = V_119 ;
F_96 ( & V_36 -> V_40 . V_125 ) ;
return V_53 ;
}
static int F_110 (
struct V_35 * V_36 ,
struct V_138 * V_139 )
{
struct V_11 * V_140 ;
struct V_9 * V_68 ;
struct V_113 * V_54 ;
bool V_141 = false ;
int V_137 , V_53 , V_44 ;
T_1 V_123 ;
F_82 ( & V_36 -> V_40 . V_125 ) ;
for ( V_137 = 0 ; V_137 < V_36 -> V_40 . V_142 ; ++ V_137 ) {
if ( ! F_105 ( & V_36 -> V_67 [ V_137 ] ) ) {
V_53 = - V_101 ;
goto V_150;
}
}
if ( ! V_36 -> V_119 ) {
F_96 ( & V_36 -> V_40 . V_125 ) ;
return 0 ;
}
for ( V_44 = 0 ; V_44 < V_143 ; V_44 ++ ) {
V_123 = V_44 ;
V_68 = V_36 -> V_119 [ V_123 ] ;
if ( ! V_68 )
continue;
F_82 ( & V_68 -> V_145 ) ;
V_140 = V_68 -> V_12 ;
if ( ! V_140 ) {
V_53 = - V_151 ;
goto V_152;
}
if ( strcmp ( V_140 -> V_17 , V_139 -> V_147 ) ) {
F_111 ( L_28
L_29 ,
V_140 -> V_17 , V_68 -> V_18 ,
V_139 -> V_147 , V_139 -> V_153 ) ;
V_53 = - V_154 ;
goto V_152;
}
V_68 -> V_146 -- ;
V_36 -> V_119 [ V_123 ] = NULL ;
V_141 = true ;
F_96 ( & V_68 -> V_145 ) ;
}
if ( V_141 ) {
for ( V_44 = 0 ; V_44 < V_48 ; V_44 ++ ) {
V_54 = & V_36 -> V_67 [ V_44 ] ;
F_82 ( & V_54 -> V_125 ) ;
F_108 ( V_54 -> V_124 , NULL ) ;
F_96 ( & V_54 -> V_125 ) ;
}
}
F_102 ( V_36 ) ;
F_30 ( V_36 -> V_119 ) ;
V_36 -> V_119 = NULL ;
F_96 ( & V_36 -> V_40 . V_125 ) ;
return 0 ;
V_152:
F_96 ( & V_68 -> V_145 ) ;
V_150:
F_96 ( & V_36 -> V_40 . V_125 ) ;
return V_53 ;
}
static int F_112 ( struct V_35 * V_36 , T_6 V_155 )
{
if ( V_155 & ~ V_156 )
return - V_157 ;
F_82 ( & V_36 -> V_40 . V_125 ) ;
if ( ( V_155 & ( 1 << V_158 ) ) &&
! F_113 ( & V_36 -> V_40 ) ) {
F_96 ( & V_36 -> V_40 . V_125 ) ;
return - V_101 ;
}
V_36 -> V_40 . V_159 = V_155 ;
F_114 () ;
F_102 ( V_36 ) ;
F_96 ( & V_36 -> V_40 . V_125 ) ;
return 0 ;
}
static int F_115 ( struct V_160 * V_160 , struct V_161 * V_162 )
{
struct V_35 * V_163 ;
int V_164 , V_44 ;
V_163 = F_28 ( sizeof( * V_163 ) , V_29 ) ;
if ( ! V_163 )
return - V_78 ;
F_116 ( & V_163 -> V_41 , F_52 ) ;
V_163 -> V_67 [ V_165 ] . V_166 = F_97 ;
V_163 -> V_67 [ V_167 ] . V_166 = F_98 ;
for ( V_44 = V_168 ; V_44 < V_48 ; V_44 ++ )
V_163 -> V_67 [ V_44 ] . V_166 = F_99 ;
V_164 = F_117 ( & V_163 -> V_40 , V_163 -> V_67 , V_48 ) ;
if ( V_164 < 0 ) {
F_30 ( V_163 ) ;
return V_164 ;
}
V_162 -> V_124 = V_163 ;
return 0 ;
}
static int F_118 ( struct V_160 * V_160 , struct V_161 * V_162 )
{
struct V_35 * V_163 = V_162 -> V_124 ;
struct V_138 V_139 ;
F_82 ( & V_163 -> V_40 . V_125 ) ;
memcpy ( V_139 . V_147 , V_163 -> V_149 , sizeof( V_139 . V_147 ) ) ;
F_96 ( & V_163 -> V_40 . V_125 ) ;
F_110 ( V_163 , & V_139 ) ;
F_119 ( & V_163 -> V_40 ) ;
F_120 ( & V_163 -> V_40 , false ) ;
F_30 ( V_163 ) ;
return 0 ;
}
static long F_121 ( struct V_161 * V_162 , unsigned int V_169 ,
unsigned long V_170 )
{
struct V_35 * V_36 = V_162 -> V_124 ;
struct V_138 V_171 ;
void T_4 * V_172 = ( void T_4 * ) V_170 ;
T_6 T_4 * V_173 = V_172 ;
T_6 V_155 ;
int V_164 , V_174 = V_175 ;
switch ( V_169 ) {
case V_176 :
if ( F_122 ( & V_171 , V_172 , sizeof V_171 ) )
return - V_101 ;
if ( V_171 . V_177 != 0 )
return - V_157 ;
return F_104 ( V_36 , & V_171 ) ;
case V_178 :
if ( F_122 ( & V_171 , V_172 , sizeof V_171 ) )
return - V_101 ;
if ( V_171 . V_177 != 0 )
return - V_157 ;
return F_110 ( V_36 , & V_171 ) ;
case V_179 :
if ( F_59 ( V_172 , & V_174 , sizeof V_174 ) )
return - V_101 ;
return 0 ;
case V_180 :
V_155 = V_156 ;
if ( F_59 ( V_173 , & V_155 , sizeof V_155 ) )
return - V_101 ;
return 0 ;
case V_181 :
if ( F_122 ( & V_155 , V_173 , sizeof V_155 ) )
return - V_101 ;
return F_112 ( V_36 , V_155 ) ;
default:
F_82 ( & V_36 -> V_40 . V_125 ) ;
V_164 = F_123 ( & V_36 -> V_40 , V_169 , V_172 ) ;
if ( V_164 == - V_182 )
V_164 = F_124 ( & V_36 -> V_40 , V_169 , V_172 ) ;
F_96 ( & V_36 -> V_40 . V_125 ) ;
return V_164 ;
}
}
static long F_125 ( struct V_161 * V_162 , unsigned int V_169 ,
unsigned long V_170 )
{
return F_121 ( V_162 , V_169 , ( unsigned long ) F_126 ( V_170 ) ) ;
}
static int T_7 F_127 ( void )
{
return F_128 ( & V_183 ) ;
}
static int F_129 ( void )
{
return F_130 ( & V_183 ) ;
}
static char * F_131 ( struct V_11 * V_12 )
{
switch ( V_12 -> V_13 ) {
case V_14 :
return L_30 ;
case V_15 :
return L_31 ;
case V_16 :
return L_32 ;
default:
break;
}
return L_33 ;
}
static int F_132 ( struct V_7 * V_8 ,
struct V_184 * V_130 )
{
struct V_9 * V_68 = F_7 ( V_8 ,
struct V_9 , V_8 ) ;
F_82 ( & V_68 -> V_145 ) ;
V_68 -> V_185 ++ ;
F_96 ( & V_68 -> V_145 ) ;
return 0 ;
}
static void F_133 ( struct V_7 * V_8 ,
struct V_184 * V_184 )
{
struct V_9 * V_68 = F_7 ( V_8 ,
struct V_9 , V_8 ) ;
F_82 ( & V_68 -> V_145 ) ;
V_68 -> V_185 -- ;
F_96 ( & V_68 -> V_145 ) ;
}
static struct V_19 * F_134 (
struct V_7 * V_8 ,
struct V_186 * V_187 ,
const char * V_188 )
{
struct V_19 * V_20 , * V_189 ;
struct V_27 * V_28 ;
T_6 V_190 = 0 ;
T_3 V_191 ;
V_189 = F_27 ( V_8 ) ;
if ( ! V_189 )
return F_66 ( - V_78 ) ;
V_191 = 1 ;
V_20 = F_135 ( V_8 , V_189 ,
V_188 , V_191 ) ;
if ( F_91 ( V_20 ) ) {
F_29 ( V_8 , V_189 ) ;
return V_20 ;
}
V_28 = F_7 ( V_20 , struct V_27 , V_19 ) ;
V_28 -> V_192 = V_190 ;
return V_20 ;
}
static void F_136 ( struct V_19 * V_193 )
{
struct V_27 * V_28 = F_7 ( V_193 ,
struct V_27 , V_19 ) ;
F_137 ( V_193 -> V_8 , V_193 , 1 ) ;
F_30 ( V_28 ) ;
}
static int F_138 ( struct V_9 * V_68 ,
const char * V_188 )
{
struct V_7 * V_8 ;
struct V_73 * V_74 ;
F_82 ( & V_68 -> V_145 ) ;
if ( V_68 -> V_75 ) {
F_96 ( & V_68 -> V_145 ) ;
F_58 ( L_34 ) ;
return - V_148 ;
}
V_8 = & V_68 -> V_8 ;
V_74 = F_28 ( sizeof( struct V_73 ) , V_29 ) ;
if ( ! V_74 ) {
F_96 ( & V_68 -> V_145 ) ;
F_11 ( L_35 ) ;
return - V_78 ;
}
V_74 -> V_109 = F_139 () ;
if ( F_91 ( V_74 -> V_109 ) ) {
F_96 ( & V_68 -> V_145 ) ;
F_30 ( V_74 ) ;
return - V_78 ;
}
V_74 -> V_109 -> V_19 = F_140 (
V_8 , ( unsigned char * ) V_188 ) ;
if ( ! V_74 -> V_109 -> V_19 ) {
F_96 ( & V_68 -> V_145 ) ;
F_58 ( L_36
L_37 , V_188 ) ;
F_141 ( V_74 -> V_109 ) ;
F_30 ( V_74 ) ;
return - V_78 ;
}
F_142 ( V_8 , V_74 -> V_109 -> V_19 ,
V_74 -> V_109 , V_74 ) ;
V_68 -> V_75 = V_74 ;
F_96 ( & V_68 -> V_145 ) ;
return 0 ;
}
static int F_143 ( struct V_9 * V_10 )
{
struct V_31 * V_32 ;
struct V_73 * V_74 ;
F_82 ( & V_10 -> V_145 ) ;
V_74 = V_10 -> V_75 ;
if ( ! V_74 ) {
F_96 ( & V_10 -> V_145 ) ;
return - V_151 ;
}
V_32 = V_74 -> V_109 ;
if ( ! V_32 ) {
F_96 ( & V_10 -> V_145 ) ;
return - V_151 ;
}
if ( V_10 -> V_185 != 0 ) {
F_96 ( & V_10 -> V_145 ) ;
F_11 ( L_38
L_39 ,
V_10 -> V_185 ) ;
return - V_194 ;
}
if ( V_10 -> V_146 != 0 ) {
F_96 ( & V_10 -> V_145 ) ;
F_11 ( L_38
L_40 ,
V_10 -> V_146 ) ;
return - V_194 ;
}
F_58 ( L_41
L_42 , F_131 ( V_10 -> V_12 ) ,
V_74 -> V_109 -> V_19 -> V_195 ) ;
F_144 ( V_74 -> V_109 ) ;
V_10 -> V_75 = NULL ;
F_96 ( & V_10 -> V_145 ) ;
F_30 ( V_74 ) ;
return 0 ;
}
static T_8 F_145 ( struct V_7 * V_8 ,
char * V_97 )
{
struct V_9 * V_68 = F_7 ( V_8 ,
struct V_9 , V_8 ) ;
struct V_73 * V_74 ;
T_8 V_53 ;
F_82 ( & V_68 -> V_145 ) ;
V_74 = V_68 -> V_75 ;
if ( ! V_74 ) {
F_96 ( & V_68 -> V_145 ) ;
return - V_151 ;
}
V_53 = snprintf ( V_97 , V_196 , L_43 ,
V_74 -> V_109 -> V_19 -> V_195 ) ;
F_96 ( & V_68 -> V_145 ) ;
return V_53 ;
}
static T_8 F_146 ( struct V_7 * V_8 ,
const char * V_97 ,
T_5 V_197 )
{
struct V_9 * V_68 = F_7 ( V_8 ,
struct V_9 , V_8 ) ;
struct V_11 * V_198 = V_68 -> V_12 ;
unsigned char V_199 [ V_200 ] , * V_95 , * V_201 ;
int V_53 ;
if ( ! strncmp ( V_97 , L_44 , 4 ) ) {
V_53 = F_143 ( V_68 ) ;
return ( ! V_53 ) ? V_197 : V_53 ;
}
if ( strlen ( V_97 ) >= V_200 ) {
F_11 ( L_45
L_46 , V_97 , V_200 ) ;
return - V_154 ;
}
snprintf ( & V_199 [ 0 ] , V_200 , L_47 , V_97 ) ;
V_95 = strstr ( V_199 , L_48 ) ;
if ( V_95 ) {
if ( V_198 -> V_13 != V_14 ) {
F_11 ( L_49
L_50 , V_199 ,
F_131 ( V_198 ) ) ;
return - V_154 ;
}
V_201 = & V_199 [ 0 ] ;
goto V_202;
}
V_95 = strstr ( V_199 , L_51 ) ;
if ( V_95 ) {
if ( V_198 -> V_13 != V_15 ) {
F_11 ( L_52
L_50 , V_199 ,
F_131 ( V_198 ) ) ;
return - V_154 ;
}
V_201 = & V_199 [ 3 ] ;
goto V_202;
}
V_95 = strstr ( V_199 , L_53 ) ;
if ( V_95 ) {
if ( V_198 -> V_13 != V_16 ) {
F_11 ( L_54
L_50 , V_199 ,
F_131 ( V_198 ) ) ;
return - V_154 ;
}
V_201 = & V_199 [ 0 ] ;
goto V_202;
}
F_11 ( L_55
L_56 , V_199 ) ;
return - V_154 ;
V_202:
if ( V_199 [ strlen ( V_199 ) - 1 ] == '\n' )
V_199 [ strlen ( V_199 ) - 1 ] = '\0' ;
V_53 = F_138 ( V_68 , V_201 ) ;
if ( V_53 < 0 )
return V_53 ;
return V_197 ;
}
static struct V_7 * F_147 ( struct V_203 * V_204 ,
struct V_186 * V_187 ,
const char * V_188 )
{
struct V_11 * V_12 = F_7 ( V_204 ,
struct V_11 , V_198 ) ;
struct V_9 * V_10 ;
unsigned long V_205 ;
int V_53 ;
if ( strstr ( V_188 , L_57 ) != V_188 )
return F_66 ( - V_154 ) ;
if ( F_148 ( V_188 + 5 , 10 , & V_205 ) || V_205 > V_206 )
return F_66 ( - V_154 ) ;
V_10 = F_28 ( sizeof( struct V_9 ) , V_29 ) ;
if ( ! V_10 ) {
F_11 ( L_58 ) ;
return F_66 ( - V_78 ) ;
}
F_149 ( & V_10 -> V_145 ) ;
F_150 ( & V_10 -> V_207 ) ;
V_10 -> V_12 = V_12 ;
V_10 -> V_18 = V_205 ;
V_53 = F_151 ( & V_208 -> V_209 , V_204 ,
& V_10 -> V_8 , V_10 , V_210 ) ;
if ( V_53 < 0 ) {
F_30 ( V_10 ) ;
return NULL ;
}
F_82 ( & V_144 ) ;
F_152 ( & V_10 -> V_207 , & V_211 ) ;
F_96 ( & V_144 ) ;
return & V_10 -> V_8 ;
}
static void F_153 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_7 ( V_8 ,
struct V_9 , V_8 ) ;
F_82 ( & V_144 ) ;
F_154 ( & V_10 -> V_207 ) ;
F_96 ( & V_144 ) ;
F_143 ( V_10 ) ;
F_155 ( V_8 ) ;
F_30 ( V_10 ) ;
}
static struct V_203 * F_156 ( struct V_212 * V_213 ,
struct V_186 * V_187 ,
const char * V_188 )
{
struct V_11 * V_12 ;
char * V_95 ;
T_6 V_190 = 0 ;
int V_214 = 0 ;
V_12 = F_28 ( sizeof( struct V_11 ) , V_29 ) ;
if ( ! V_12 ) {
F_11 ( L_59 ) ;
return F_66 ( - V_78 ) ;
}
V_12 -> V_215 = V_190 ;
V_95 = strstr ( V_188 , L_48 ) ;
if ( V_95 ) {
V_12 -> V_13 = V_14 ;
goto V_216;
}
V_95 = strstr ( V_188 , L_51 ) ;
if ( V_95 ) {
V_12 -> V_13 = V_15 ;
V_214 = 3 ;
goto V_216;
}
V_95 = strstr ( V_188 , L_53 ) ;
if ( V_95 ) {
V_12 -> V_13 = V_16 ;
goto V_216;
}
F_11 ( L_60
L_56 , V_188 ) ;
F_30 ( V_12 ) ;
return F_66 ( - V_154 ) ;
V_216:
if ( strlen ( V_188 ) >= V_200 ) {
F_11 ( L_61
L_46 , V_188 , F_131 ( V_12 ) ,
V_200 ) ;
F_30 ( V_12 ) ;
return F_66 ( - V_154 ) ;
}
snprintf ( & V_12 -> V_17 [ 0 ] , V_200 , L_47 , & V_188 [ V_214 ] ) ;
F_58 ( L_62
L_63 , F_131 ( V_12 ) , V_188 ) ;
return & V_12 -> V_198 ;
}
static void F_157 ( struct V_203 * V_204 )
{
struct V_11 * V_12 = F_7 ( V_204 ,
struct V_11 , V_198 ) ;
F_58 ( L_64
L_63 , F_131 ( V_12 ) ,
V_12 -> V_17 ) ;
F_30 ( V_12 ) ;
}
static T_8 F_158 (
struct V_212 * V_213 ,
char * V_97 )
{
return sprintf ( V_97 , L_65
L_66 V_217 L_67 , V_218 , F_159 () -> V_219 ,
F_159 () -> V_220 ) ;
}
static int F_160 ( void )
{
struct V_212 * V_221 ;
int V_53 ;
F_58 ( L_65
L_68 V_217 L_67 , V_218 , F_159 () -> V_219 ,
F_159 () -> V_220 ) ;
V_221 = F_161 ( V_222 , L_1 ) ;
if ( F_91 ( V_221 ) ) {
F_11 ( L_69 ) ;
return F_92 ( V_221 ) ;
}
V_221 -> V_209 = V_223 ;
F_162 ( V_221 ) -> V_224 . V_225 = V_226 ;
F_162 ( V_221 ) -> V_227 . V_225 = V_228 ;
F_162 ( V_221 ) -> V_229 . V_225 = NULL ;
F_162 ( V_221 ) -> V_230 . V_225 = NULL ;
F_162 ( V_221 ) -> V_231 . V_225 = NULL ;
F_162 ( V_221 ) -> V_232 . V_225 = NULL ;
F_162 ( V_221 ) -> V_233 . V_225 = NULL ;
F_162 ( V_221 ) -> V_234 . V_225 = NULL ;
F_162 ( V_221 ) -> V_235 . V_225 = NULL ;
V_53 = F_163 ( V_221 ) ;
if ( V_53 < 0 ) {
F_11 ( L_70
L_71 ) ;
return V_53 ;
}
V_208 = V_221 ;
F_58 ( L_72 ) ;
return 0 ;
}
static void F_164 ( void )
{
if ( ! V_208 )
return;
F_165 ( V_208 ) ;
V_208 = NULL ;
F_58 ( L_73 ) ;
}
static int T_7 F_166 ( void )
{
int V_53 = - V_78 ;
V_135 = F_167 ( L_74 , 0 , 0 ) ;
if ( ! V_135 )
goto V_100;
V_53 = F_127 () ;
if ( V_53 < 0 )
goto V_236;
V_53 = F_160 () ;
if ( V_53 < 0 )
goto V_237;
return 0 ;
V_237:
F_129 () ;
V_236:
F_168 ( V_135 ) ;
V_100:
return V_53 ;
}
static void F_169 ( void )
{
F_164 () ;
F_129 () ;
F_168 ( V_135 ) ;
}
