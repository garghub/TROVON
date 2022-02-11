static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( F_4 ( & V_2 -> V_3 ) )
F_5 ( & V_2 -> V_4 ) ;
}
static void F_6 ( struct V_5 * * V_5 , int V_6 )
{
unsigned long V_7 ;
int V_8 = V_9 + V_6 , V_10 = V_6 ;
if ( V_6 == 0 )
return;
if ( V_8 > V_11 ) {
V_10 = F_7 ( V_6 , V_8 - V_11 ) ;
F_8 ( V_10 , V_5 + V_6 - V_10 ) ;
V_10 = V_6 - V_10 ;
}
F_9 ( & V_12 , V_7 ) ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ )
F_10 ( & V_5 [ V_8 ] -> V_13 , & V_14 ) ;
V_9 += V_10 ;
F_11 ( & V_12 , V_7 ) ;
}
static int F_12 ( struct V_5 * * V_5 )
{
unsigned long V_7 ;
F_9 ( & V_12 , V_7 ) ;
if ( F_13 ( & V_14 ) ) {
F_11 ( & V_12 , V_7 ) ;
return F_14 ( 1 , V_5 ) ;
}
V_5 [ 0 ] = F_15 ( & V_14 , struct V_5 , V_13 ) ;
F_16 ( & V_5 [ 0 ] -> V_13 ) ;
V_9 -- ;
F_11 ( & V_12 , V_7 ) ;
return 0 ;
}
static unsigned long F_17 ( struct V_5 * V_5 )
{
unsigned long V_15 = F_18 ( V_5 ) ;
return ( unsigned long ) F_19 ( V_15 ) ;
}
static unsigned long F_20 ( struct V_16 * V_17 , int V_18 )
{
return F_17 ( V_17 -> V_19 [ V_18 ] ) ;
}
static void F_21 ( char * V_20 , int V_21 ,
struct V_16 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_25 -> V_24 ;
F_22 ( L_1 ,
V_24 -> V_26 -> V_27 , V_22 -> V_25 -> V_28 ,
V_22 -> V_29 [ 0 ] , F_23 ( V_21 ) , F_24 ( V_21 ) ,
F_25 ( V_21 ) , F_26 ( V_21 ) ) ;
}
static void F_27 ( struct V_16 * V_17 )
{
struct V_30 V_31 [ V_32 ] ;
struct V_5 * V_19 [ V_32 ] ;
unsigned int V_8 , V_33 = 0 ;
T_1 V_34 ;
int V_35 ;
F_28 ( V_17 -> V_36 ) ;
V_17 -> V_36 = NULL ;
V_17 -> V_37 = 0 ;
if ( ! V_17 -> V_38 )
return;
for ( V_8 = 0 ; V_8 < V_17 -> V_38 ; V_8 ++ ) {
V_34 = V_17 -> V_39 [ V_8 ] ;
if ( V_34 == V_40 )
continue;
F_29 ( & V_31 [ V_33 ] , F_20 ( V_17 , V_8 ) ,
V_41 , V_34 ) ;
V_17 -> V_39 [ V_8 ] = V_40 ;
V_19 [ V_33 ] = V_17 -> V_19 [ V_8 ] ;
F_30 ( V_19 [ V_33 ] ) ;
V_33 ++ ;
if ( V_33 < V_32 )
continue;
V_35 = F_31 ( V_31 , NULL , V_19 , V_33 ) ;
F_32 ( V_35 ) ;
V_33 = 0 ;
}
if ( V_33 ) {
V_35 = F_31 ( V_31 , NULL , V_19 , V_33 ) ;
F_32 ( V_35 ) ;
}
F_6 ( V_17 -> V_19 , V_17 -> V_38 ) ;
V_17 -> V_38 = 0 ;
}
static void F_33 ( struct V_42 * V_42 )
{
struct V_43 * V_44 = F_34 ( V_42 , struct V_43 , V_42 ) ;
struct V_23 * V_24 = V_44 -> V_24 ;
F_35 ( & V_24 -> V_45 ) ;
V_24 -> V_46 -- ;
F_36 ( & V_24 -> V_45 ) ;
F_28 ( V_44 ) ;
}
static void F_37 ( char * V_20 , T_2 V_47 ,
T_3 V_48 , struct V_16 * V_22 )
{
struct V_49 * V_50 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_51 ;
struct V_52 V_53 ;
unsigned long V_7 ;
unsigned V_54 ;
F_9 ( & V_2 -> V_55 , V_7 ) ;
V_50 = F_38 ( & V_2 -> V_56 , V_2 -> V_56 . V_57 ) ;
V_2 -> V_56 . V_57 ++ ;
V_50 -> V_58 = V_47 ;
V_50 -> V_59 = V_22 -> V_59 ;
if ( V_20 != NULL &&
F_39 ( V_20 , V_60 ,
& V_53 ) ) {
V_54 = F_40 ( unsigned , 8 + V_20 [ 7 ] ,
V_60 ) ;
memcpy ( V_50 -> V_20 , V_20 , V_54 ) ;
V_50 -> V_61 = V_54 ;
} else {
V_50 -> V_61 = 0 ;
}
V_50 -> V_62 = V_48 ;
F_41 ( & V_2 -> V_56 , V_51 ) ;
F_11 ( & V_2 -> V_55 , V_7 ) ;
if ( V_51 )
F_42 ( V_2 -> V_63 ) ;
if ( V_22 -> V_25 )
F_43 ( & V_22 -> V_25 -> V_42 ,
F_33 ) ;
}
static void F_44 ( struct V_16 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
unsigned char * V_20 ;
unsigned int V_48 ;
int V_21 ;
V_20 = V_22 -> V_20 ;
V_48 = V_22 -> V_64 . V_65 ;
V_21 = V_22 -> V_47 ;
if ( V_21 && V_66 )
F_21 ( V_20 , V_21 , V_22 ) ;
F_27 ( V_22 ) ;
F_37 ( V_20 , V_21 , V_48 , V_22 ) ;
F_3 ( V_2 ) ;
}
static void F_45 ( struct V_16 * V_22 )
{
struct V_64 * V_64 = & V_22 -> V_64 ;
struct V_67 * V_68 = V_22 -> V_25 -> V_24 -> V_69 -> V_70 ;
int V_71 ;
memset ( V_22 -> V_20 , 0 , V_60 ) ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
F_1 ( V_22 -> V_2 ) ;
V_71 = F_46 ( V_64 , V_68 , V_22 -> V_29 ,
V_22 -> V_20 , V_22 -> V_25 -> V_28 ,
V_22 -> V_72 , 0 ,
V_22 -> V_73 , 0 ,
V_22 -> V_36 , V_22 -> V_37 ,
NULL , 0 , NULL , 0 ) ;
if ( V_71 < 0 ) {
F_47 ( V_64 ,
V_74 , 0 ) ;
F_48 ( V_64 , 0 ) ;
}
}
static int F_49 ( struct V_75 * V_76 ,
struct V_5 * * V_77 , T_1 * V_78 , int V_79 )
{
int V_35 , V_8 ;
if ( ! V_79 )
return 0 ;
V_35 = F_50 ( V_76 , NULL , V_77 , V_79 ) ;
F_32 ( V_35 ) ;
for ( V_8 = 0 ; V_8 < V_79 ; V_8 ++ ) {
if ( F_51 ( V_76 [ V_8 ] . V_80 != V_81 ) ) {
F_22 ( L_2 ) ;
V_76 [ V_8 ] . V_34 = V_40 ;
V_35 = - V_82 ;
} else {
F_52 ( V_77 [ V_8 ] ) ;
}
V_78 [ V_8 ] = V_76 [ V_8 ] . V_34 ;
}
return V_35 ;
}
static int F_53 ( struct V_16 * V_22 ,
struct V_83 * V_18 , struct V_5 * * V_77 ,
T_1 * V_78 , int V_79 , T_4 V_7 )
{
int V_84 = 0 , V_8 , V_35 = 0 ;
struct V_75 V_76 [ V_32 ] ;
struct V_1 * V_2 = V_22 -> V_2 ;
for ( V_8 = 0 ; V_8 < V_79 ; V_8 ++ ) {
if ( F_12 ( V_77 + V_84 ) ) {
F_6 ( V_77 , V_84 ) ;
F_22 ( L_3 ) ;
return - V_82 ;
}
F_54 ( & V_76 [ V_84 ] , F_17 ( V_77 [ V_84 ] ) ,
V_7 , V_18 [ V_8 ] . V_85 , V_2 -> V_86 ) ;
V_84 ++ ;
if ( V_84 < V_32 )
continue;
V_35 = F_49 ( V_76 , V_77 , V_78 , V_84 ) ;
V_77 += V_84 ;
V_78 += V_84 ;
V_22 -> V_38 += V_84 ;
if ( V_35 )
return V_35 ;
V_84 = 0 ;
}
V_35 = F_49 ( V_76 , V_77 , V_78 , V_84 ) ;
V_22 -> V_38 += V_84 ;
return V_35 ;
}
static int F_55 ( struct V_87 * V_88 ,
struct V_16 * V_22 )
{
T_4 V_7 ;
int V_8 , V_35 , V_89 , V_90 = 0 ;
struct V_5 * * V_77 ;
struct V_83 * V_18 ;
unsigned long V_91 = 0 ;
unsigned int V_92 = ( unsigned int ) V_88 -> V_92 ;
unsigned int V_93 = 0 ;
struct V_94 * V_95 ;
T_1 * V_78 ;
V_22 -> V_37 = 0 ;
V_22 -> V_38 = 0 ;
V_22 -> V_72 = 0 ;
V_92 &= ~ V_96 ;
if ( ! V_92 )
return 0 ;
if ( V_92 > V_97 ) {
F_56 ( L_4 ,
V_88 -> V_92 ) ;
return - V_98 ;
}
if ( V_88 -> V_92 & V_96 ) {
V_35 = F_53 ( V_22 , V_88 -> V_18 ,
V_22 -> V_19 , V_22 -> V_39 ,
V_92 , V_41 | V_99 ) ;
if ( V_35 )
return V_35 ;
V_93 = V_92 ;
V_92 = 0 ;
for ( V_8 = 0 ; V_8 < V_93 ; V_8 ++ ) {
V_89 = V_88 -> V_18 [ V_8 ] . V_100 /
sizeof( struct V_83 ) ;
if ( ( unsigned ) V_88 -> V_18 [ V_8 ] . V_101 +
( unsigned ) V_88 -> V_18 [ V_8 ] . V_100 > V_102 ||
V_89 * sizeof( struct V_83 ) !=
V_88 -> V_18 [ V_8 ] . V_100 )
return - V_98 ;
V_92 += V_89 ;
}
if ( V_92 > V_103 ) {
F_56 ( L_5 , V_92 ) ;
return - V_98 ;
}
}
V_22 -> V_36 = F_57 ( V_92 ,
sizeof( struct V_94 ) , V_104 ) ;
if ( ! V_22 -> V_36 )
return - V_82 ;
F_58 ( V_22 -> V_36 , V_92 ) ;
V_22 -> V_37 = V_92 ;
V_7 = V_41 ;
if ( V_22 -> V_73 == V_105 )
V_7 |= V_99 ;
V_77 = V_22 -> V_19 + V_93 ;
V_78 = V_22 -> V_39 + V_93 ;
if ( ! V_93 ) {
V_18 = V_88 -> V_18 ;
V_35 = F_53 ( V_22 , V_18 ,
V_77 , V_78 , V_92 , V_7 ) ;
if ( V_35 )
return V_35 ;
} else {
for ( V_8 = 0 ; V_8 < V_93 ; V_8 ++ ) {
V_18 = (struct V_83 * ) (
F_20 ( V_22 , V_8 ) + V_88 -> V_18 [ V_8 ] . V_101 ) ;
V_89 = V_88 -> V_18 [ V_8 ] . V_100 /
sizeof( struct V_83 ) ;
V_35 = F_53 ( V_22 , V_18 ,
V_77 , V_78 , V_89 , V_7 ) ;
if ( V_35 )
return V_35 ;
V_77 += V_89 ;
V_78 += V_89 ;
}
V_91 = F_20 ( V_22 , 0 ) + V_88 -> V_18 [ 0 ] . V_101 ;
V_18 = (struct V_83 * ) V_91 ;
V_91 += V_88 -> V_18 [ 0 ] . V_100 ;
V_77 = V_22 -> V_19 + V_93 ;
}
F_59 (pending_req->sgl, sg, nr_segments, i) {
F_60 ( V_95 , V_77 [ V_8 ] , V_18 -> V_100 , V_18 -> V_101 ) ;
V_22 -> V_72 += V_18 -> V_100 ;
V_18 ++ ;
if ( V_93 && ( unsigned long ) V_18 >= V_91 ) {
V_90 ++ ;
V_91 = F_20 ( V_22 , V_90 ) +
V_88 -> V_18 [ V_90 ] . V_101 ;
V_18 = (struct V_83 * ) V_91 ;
V_91 += V_88 -> V_18 [ V_90 ] . V_100 ;
}
if ( V_95 -> V_101 >= V_102 ||
V_95 -> V_100 > V_102 ||
V_95 -> V_101 + V_95 -> V_100 > V_102 )
return - V_98 ;
}
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_62 ( V_2 -> V_4 ,
F_63 ( & V_2 -> V_3 ) == 0 ) ;
F_64 ( V_2 -> V_63 , V_2 ) ;
V_2 -> V_63 = 0 ;
F_65 ( V_2 -> V_106 , V_2 -> V_56 . V_107 ) ;
}
static void F_66 ( struct V_16 * V_22 ,
enum V_108 V_109 , int V_110 )
{
int V_71 , V_35 = V_111 ;
struct V_23 * V_24 = V_22 -> V_25 -> V_24 ;
struct V_64 * V_64 = & V_22 -> V_64 ;
struct V_112 * V_113 ;
V_113 = F_67 ( sizeof( struct V_112 ) , V_104 ) ;
if ( ! V_113 )
goto V_114;
F_68 ( & V_113 -> V_115 ) ;
F_69 ( V_64 , V_24 -> V_116 . V_117 ,
V_24 -> V_69 -> V_70 , 0 , V_118 , V_119 ,
& V_22 -> V_20 [ 0 ] ) ;
V_71 = F_70 ( V_64 , V_113 , V_109 , V_104 ) ;
if ( V_71 < 0 )
goto V_114;
V_64 -> V_120 -> V_121 = V_110 ;
if ( F_71 ( V_64 , V_22 -> V_25 -> V_28 ) < 0 )
goto V_114;
F_72 ( V_64 ) ;
F_62 ( V_113 -> V_115 , F_63 ( & V_113 -> V_122 ) ) ;
V_35 = ( V_64 -> V_120 -> V_123 == V_124 ) ?
V_125 : V_111 ;
V_114:
if ( V_113 ) {
F_48 ( & V_22 -> V_64 , 1 ) ;
F_28 ( V_113 ) ;
}
F_37 ( NULL , V_35 , 0 , V_22 ) ;
F_73 ( V_126 , V_22 ) ;
}
static struct V_43 * F_74 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
struct V_43 * V_44 ;
struct V_129 * V_130 = & ( V_2 -> V_131 ) ;
unsigned long V_7 ;
F_9 ( & V_2 -> V_132 , V_7 ) ;
F_75 (entry, head, l) {
if ( ( V_44 -> V_128 . V_133 == V_128 -> V_133 ) &&
( V_44 -> V_128 . V_134 == V_128 -> V_134 ) &&
( V_44 -> V_128 . V_28 == V_128 -> V_28 ) ) {
F_76 ( & V_44 -> V_42 ) ;
goto V_114;
}
}
V_44 = NULL ;
V_114:
F_11 ( & V_2 -> V_132 , V_7 ) ;
return V_44 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_16 * V_22 )
{
struct V_43 * V_25 ;
struct V_127 V_135 ;
V_22 -> V_59 = V_88 -> V_59 ;
V_22 -> V_2 = V_2 ;
V_135 . V_133 = V_88 -> V_136 ;
V_135 . V_134 = V_88 -> V_137 ;
V_135 . V_28 = V_88 -> V_28 ;
V_25 = F_74 ( V_2 , & V_135 ) ;
if ( ! V_25 ) {
V_22 -> V_25 = NULL ;
F_56 ( L_6 ,
V_135 . V_133 , V_135 . V_134 , V_135 . V_28 ) ;
return - V_138 ;
}
V_22 -> V_25 = V_25 ;
V_22 -> V_73 = V_88 -> V_73 ;
if ( ( V_22 -> V_73 != V_139 ) &&
( V_22 -> V_73 != V_105 ) &&
( V_22 -> V_73 != V_140 ) &&
( V_22 -> V_73 != V_118 ) ) {
F_56 ( L_7 ,
V_22 -> V_73 ) ;
return - V_98 ;
}
V_22 -> V_141 = V_88 -> V_141 ;
if ( V_22 -> V_141 > V_142 ) {
F_56 ( L_8 ,
V_22 -> V_141 ) ;
return - V_98 ;
}
memcpy ( V_22 -> V_29 , V_88 -> V_29 , V_22 -> V_141 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_143 * V_56 = & V_2 -> V_56 ;
struct V_87 V_88 ;
struct V_16 * V_22 ;
T_5 V_71 , V_144 ;
int V_35 , V_145 ;
T_3 V_47 ;
V_71 = V_56 -> V_146 ;
V_144 = V_56 -> V_107 -> V_147 ;
F_79 () ;
if ( F_80 ( V_56 , V_144 ) ) {
V_71 = V_56 -> V_57 ;
F_81 ( L_9 ,
V_2 -> V_86 , V_144 , V_71 , V_144 - V_71 ) ;
V_2 -> V_148 = 1 ;
return 0 ;
}
while ( ( V_71 != V_144 ) ) {
if ( F_82 ( V_56 , V_71 ) )
break;
V_22 = F_83 ( V_126 , V_104 ) ;
if ( ! V_22 )
return 1 ;
V_88 = * F_84 ( V_56 , V_71 ) ;
V_56 -> V_146 = ++ V_71 ;
V_35 = F_77 ( V_2 , & V_88 , V_22 ) ;
if ( V_35 ) {
switch ( V_35 ) {
case - V_138 :
V_47 = V_149 ;
break;
default:
V_47 = V_150 ;
break;
}
F_37 ( NULL , V_47 << 24 , 0 ,
V_22 ) ;
F_73 ( V_126 , V_22 ) ;
return 1 ;
}
switch ( V_88 . V_109 ) {
case V_151 :
if ( F_55 ( & V_88 , V_22 ) ) {
F_27 ( V_22 ) ;
F_37 ( NULL ,
V_150 << 24 , 0 , V_22 ) ;
F_73 ( V_126 , V_22 ) ;
} else {
F_45 ( V_22 ) ;
}
break;
case V_152 :
F_66 ( V_22 , V_153 ,
V_88 . V_154 ) ;
break;
case V_155 :
F_66 ( V_22 , V_156 , 0 ) ;
break;
default:
F_85 ( L_10 ) ;
F_37 ( NULL , V_150 << 24 ,
0 , V_22 ) ;
F_73 ( V_126 , V_22 ) ;
break;
}
F_86 () ;
}
F_87 ( & V_2 -> V_56 , V_145 ) ;
return V_145 ;
}
static T_6 F_88 ( int V_63 , void * V_157 )
{
struct V_1 * V_2 = V_157 ;
if ( V_2 -> V_148 )
return V_158 ;
while ( F_78 ( V_2 ) )
F_86 () ;
return V_158 ;
}
static int F_89 ( struct V_1 * V_2 , T_7 V_159 ,
T_8 V_160 )
{
void * V_161 ;
struct V_162 * V_107 ;
int V_35 ;
if ( V_2 -> V_63 )
return - 1 ;
V_35 = F_90 ( V_2 -> V_106 , & V_159 , 1 , & V_161 ) ;
if ( V_35 )
return V_35 ;
V_107 = (struct V_162 * ) V_161 ;
F_91 ( & V_2 -> V_56 , V_107 , V_102 ) ;
V_35 = F_92 ( V_2 -> V_86 , V_160 ) ;
if ( V_35 < 0 )
goto V_163;
V_2 -> V_63 = V_35 ;
V_35 = F_93 ( V_2 -> V_63 , NULL , F_88 ,
V_164 , L_11 , V_2 ) ;
if ( V_35 )
goto V_165;
return 0 ;
V_165:
F_64 ( V_2 -> V_63 , V_2 ) ;
V_2 -> V_63 = 0 ;
V_163:
F_65 ( V_2 -> V_106 , V_161 ) ;
return V_35 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_166 * V_106 = V_2 -> V_106 ;
unsigned int V_159 , V_160 ;
int V_35 ;
V_35 = F_95 ( V_167 , V_106 -> V_168 ,
L_12 , L_13 , & V_159 ,
L_14 , L_13 , & V_160 , NULL ) ;
if ( V_35 ) {
F_96 ( V_106 , V_35 , L_15 , V_106 -> V_168 ) ;
return V_35 ;
}
return F_89 ( V_2 , V_159 , V_160 ) ;
}
static int F_97 ( struct V_1 * V_2 ,
char * V_169 , struct V_127 * V_128 )
{
int V_35 = 0 ;
struct V_43 * V_44 ;
struct V_43 * V_170 ;
struct V_129 * V_130 = & ( V_2 -> V_131 ) ;
unsigned long V_7 ;
char * V_171 ;
unsigned int V_28 ;
struct V_23 * V_172 , * V_24 = NULL ;
char * error = L_16 ;
V_171 = strrchr ( V_169 , ':' ) ;
if ( ! V_171 ) {
F_22 ( L_17 , V_169 ) ;
return - V_98 ;
}
* V_171 = 0 ;
V_171 ++ ;
if ( F_98 ( V_171 , 10 , & V_28 ) || V_28 >= V_173 ) {
F_22 ( L_18 , V_171 ) ;
return - V_98 ;
}
F_35 ( & V_174 ) ;
F_75 (tpg_entry, &scsiback_list, tv_tpg_list) {
if ( ! strcmp ( V_169 , V_172 -> V_26 -> V_27 ) ||
! strcmp ( V_169 , V_172 -> V_175 ) ) {
F_99 ( & V_172 -> V_116 . V_176 ) ;
if ( V_172 -> V_116 . V_177 [ V_28 ] -> V_178 ==
V_179 ) {
if ( ! V_172 -> V_69 )
error = L_19 ;
else
V_24 = V_172 ;
}
F_100 ( & V_172 -> V_116 . V_176 ) ;
break;
}
}
if ( V_24 ) {
F_35 ( & V_24 -> V_45 ) ;
V_24 -> V_46 ++ ;
F_36 ( & V_24 -> V_45 ) ;
}
F_36 ( & V_174 ) ;
if ( ! V_24 ) {
F_22 ( L_20 , V_169 , V_28 , error ) ;
return - V_138 ;
}
V_170 = F_101 ( sizeof( struct V_43 ) , V_104 ) ;
if ( V_170 == NULL ) {
V_35 = - V_82 ;
goto V_180;
}
F_9 ( & V_2 -> V_132 , V_7 ) ;
F_75 (entry, head, l) {
if ( ( V_44 -> V_128 . V_133 == V_128 -> V_133 ) &&
( V_44 -> V_128 . V_134 == V_128 -> V_134 ) &&
( V_44 -> V_128 . V_28 == V_128 -> V_28 ) ) {
F_81 ( L_21 ) ;
V_35 = - V_181 ;
goto V_114;
}
}
F_102 ( & V_170 -> V_42 ) ;
V_170 -> V_128 = * V_128 ;
V_170 -> V_24 = V_24 ;
V_170 -> V_28 = V_28 ;
F_103 ( & V_170 -> V_182 , V_130 ) ;
V_114:
F_11 ( & V_2 -> V_132 , V_7 ) ;
V_180:
F_35 ( & V_24 -> V_45 ) ;
V_24 -> V_46 -- ;
F_36 ( & V_24 -> V_45 ) ;
if ( V_35 )
F_28 ( V_170 ) ;
return V_35 ;
}
static void F_104 ( struct V_43 * V_44 )
{
F_16 ( & V_44 -> V_182 ) ;
F_43 ( & V_44 -> V_42 , F_33 ) ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
struct V_43 * V_44 ;
struct V_129 * V_130 = & ( V_2 -> V_131 ) ;
unsigned long V_7 ;
F_9 ( & V_2 -> V_132 , V_7 ) ;
F_75 (entry, head, l) {
if ( ( V_44 -> V_128 . V_133 == V_128 -> V_133 ) &&
( V_44 -> V_128 . V_134 == V_128 -> V_134 ) &&
( V_44 -> V_128 . V_28 == V_128 -> V_28 ) ) {
goto V_183;
}
}
F_11 ( & V_2 -> V_132 , V_7 ) ;
return 1 ;
V_183:
F_104 ( V_44 ) ;
F_11 ( & V_2 -> V_132 , V_7 ) ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 , const char * V_184 ,
char * V_169 , struct V_127 * V_135 , int V_185 )
{
if ( ! F_97 ( V_2 , V_169 , V_135 ) ) {
if ( F_107 ( V_167 , V_2 -> V_106 -> V_186 , V_184 ,
L_22 , V_187 ) ) {
F_22 ( L_23 , V_184 ) ;
F_105 ( V_2 , V_135 ) ;
}
} else if ( ! V_185 ) {
F_107 ( V_167 , V_2 -> V_106 -> V_186 , V_184 ,
L_22 , V_188 ) ;
}
}
static void F_108 ( struct V_1 * V_2 , const char * V_184 ,
struct V_127 * V_135 )
{
if ( ! F_105 ( V_2 , V_135 ) ) {
if ( F_107 ( V_167 , V_2 -> V_106 -> V_186 , V_184 ,
L_22 , V_188 ) )
F_22 ( L_23 , V_184 ) ;
}
}
static void F_109 ( struct V_1 * V_2 , int V_189 ,
char * V_190 )
{
int V_35 ;
struct V_127 V_135 ;
char * V_191 ;
int V_192 ;
char V_169 [ V_193 ] ;
char V_194 [ 64 ] ;
char V_184 [ 64 ] ;
struct V_166 * V_106 = V_2 -> V_106 ;
snprintf ( V_184 , sizeof( V_184 ) , L_24 , V_190 ) ;
V_35 = F_110 ( V_167 , V_106 -> V_186 , V_184 , L_13 , & V_192 ) ;
if ( F_111 ( V_35 ) )
return;
snprintf ( V_194 , sizeof( V_194 ) , L_25 , V_190 ) ;
V_191 = F_112 ( V_167 , V_106 -> V_186 , V_194 , NULL ) ;
if ( F_113 ( V_191 ) ) {
F_107 ( V_167 , V_106 -> V_186 , V_184 ,
L_22 , V_188 ) ;
return;
}
F_114 ( V_169 , V_191 , V_193 ) ;
F_28 ( V_191 ) ;
snprintf ( V_194 , sizeof( V_194 ) , L_26 , V_190 ) ;
V_35 = F_110 ( V_167 , V_106 -> V_186 , V_194 , L_27 ,
& V_135 . V_195 , & V_135 . V_133 , & V_135 . V_134 , & V_135 . V_28 ) ;
if ( F_111 ( V_35 ) ) {
F_107 ( V_167 , V_106 -> V_186 , V_184 ,
L_22 , V_188 ) ;
return;
}
switch ( V_189 ) {
case V_196 :
switch ( V_192 ) {
case V_197 :
F_106 ( V_2 , V_184 , V_169 , & V_135 , 0 ) ;
break;
case V_198 :
F_106 ( V_2 , V_184 , V_169 , & V_135 , 1 ) ;
break;
case V_199 :
F_108 ( V_2 , V_184 , & V_135 ) ;
break;
default:
break;
}
break;
case V_200 :
if ( V_192 == V_187 ) {
if ( F_107 ( V_167 , V_106 -> V_186 , V_184 ,
L_22 , V_198 ) ) {
F_22 ( L_23 , V_194 ) ;
F_105 ( V_2 , & V_135 ) ;
F_107 ( V_167 , V_106 -> V_186 , V_184 ,
L_22 , V_188 ) ;
}
}
break;
default:
break;
}
}
static void F_115 ( struct V_1 * V_2 , int V_189 )
{
int V_8 ;
char * * V_201 ;
unsigned int V_202 = 0 ;
V_201 = F_116 ( V_167 , V_2 -> V_106 -> V_186 , L_28 ,
& V_202 ) ;
if ( F_113 ( V_201 ) )
return;
for ( V_8 = 0 ; V_8 < V_202 ; V_8 ++ )
F_109 ( V_2 , V_189 , V_201 [ V_8 ] ) ;
F_28 ( V_201 ) ;
}
static void F_117 ( struct V_166 * V_106 ,
enum V_203 V_204 )
{
struct V_1 * V_2 = F_118 ( & V_106 -> V_106 ) ;
switch ( V_204 ) {
case V_197 :
break;
case V_187 :
if ( F_94 ( V_2 ) )
break;
F_115 ( V_2 , V_196 ) ;
F_119 ( V_106 , V_198 ) ;
break;
case V_198 :
F_115 ( V_2 , V_200 ) ;
if ( V_106 -> V_184 == V_198 )
break;
F_119 ( V_106 , V_198 ) ;
break;
case V_199 :
if ( V_2 -> V_63 )
F_61 ( V_2 ) ;
F_119 ( V_106 , V_199 ) ;
break;
case V_188 :
F_119 ( V_106 , V_188 ) ;
if ( F_120 ( V_106 ) )
break;
case V_205 :
F_121 ( & V_106 -> V_106 ) ;
break;
case V_206 :
F_115 ( V_2 , V_196 ) ;
F_119 ( V_106 , V_207 ) ;
break;
default:
F_96 ( V_106 , - V_98 , L_29 ,
V_204 ) ;
break;
}
}
static void F_122 ( struct V_1 * V_2 )
{
struct V_43 * V_44 , * V_208 ;
struct V_129 * V_130 = & ( V_2 -> V_131 ) ;
unsigned long V_7 ;
F_9 ( & V_2 -> V_132 , V_7 ) ;
F_123 (entry, tmp, head, l)
F_104 ( V_44 ) ;
F_11 ( & V_2 -> V_132 , V_7 ) ;
}
static int F_124 ( struct V_166 * V_106 )
{
struct V_1 * V_2 = F_118 ( & V_106 -> V_106 ) ;
if ( V_2 -> V_63 )
F_61 ( V_2 ) ;
F_122 ( V_2 ) ;
F_125 ( & V_106 -> V_106 , NULL ) ;
return 0 ;
}
static int F_126 ( struct V_166 * V_106 ,
const struct V_209 * V_137 )
{
int V_35 ;
struct V_1 * V_2 = F_67 ( sizeof( struct V_1 ) ,
V_104 ) ;
F_56 ( L_30 , V_210 , V_106 , V_106 -> V_211 ) ;
if ( ! V_2 ) {
F_96 ( V_106 , - V_82 , L_31 ) ;
return - V_82 ;
}
V_2 -> V_106 = V_106 ;
F_125 ( & V_106 -> V_106 , V_2 ) ;
V_2 -> V_86 = V_106 -> V_211 ;
F_127 ( & V_2 -> V_55 ) ;
V_2 -> V_148 = 0 ;
F_128 ( & V_2 -> V_3 , 0 ) ;
F_68 ( & V_2 -> V_4 ) ;
V_2 -> V_106 = V_106 ;
V_2 -> V_63 = 0 ;
F_129 ( & V_2 -> V_131 ) ;
F_127 ( & V_2 -> V_132 ) ;
V_35 = F_107 ( V_167 , V_106 -> V_186 , L_32 , L_13 ,
V_103 ) ;
if ( V_35 )
F_130 ( V_106 , V_35 , L_33 ) ;
V_35 = F_119 ( V_106 , V_212 ) ;
if ( V_35 )
goto V_213;
return 0 ;
V_213:
F_81 ( L_34 , V_210 ) ;
F_124 ( V_106 ) ;
return V_35 ;
}
static char * F_131 ( struct V_214 * V_26 )
{
switch ( V_26 -> V_215 ) {
case V_216 :
return L_35 ;
case V_217 :
return L_36 ;
case V_218 :
return L_37 ;
default:
break;
}
return L_38 ;
}
static T_9 F_132 ( struct V_219 * V_116 )
{
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
struct V_214 * V_26 = V_24 -> V_26 ;
switch ( V_26 -> V_215 ) {
case V_216 :
return F_133 ( V_116 ) ;
case V_217 :
return F_134 ( V_116 ) ;
case V_218 :
return F_135 ( V_116 ) ;
default:
F_22 ( L_39 ,
V_26 -> V_215 ) ;
break;
}
return F_133 ( V_116 ) ;
}
static char * F_136 ( struct V_219 * V_116 )
{
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
struct V_214 * V_26 = V_24 -> V_26 ;
return & V_26 -> V_27 [ 0 ] ;
}
static T_10 F_137 ( struct V_219 * V_116 )
{
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
return V_24 -> V_220 ;
}
static T_4 F_138 ( struct V_219 * V_116 )
{
return 1 ;
}
static T_4
F_139 ( struct V_219 * V_116 ,
struct V_221 * V_222 ,
struct V_223 * V_224 ,
int * V_225 ,
unsigned char * V_226 )
{
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
struct V_214 * V_26 = V_24 -> V_26 ;
switch ( V_26 -> V_215 ) {
case V_216 :
return F_140 ( V_116 , V_222 , V_224 ,
V_225 , V_226 ) ;
case V_217 :
return F_141 ( V_116 , V_222 , V_224 ,
V_225 , V_226 ) ;
case V_218 :
return F_142 ( V_116 , V_222 , V_224 ,
V_225 , V_226 ) ;
default:
F_22 ( L_39 ,
V_26 -> V_215 ) ;
break;
}
return F_140 ( V_116 , V_222 , V_224 ,
V_225 , V_226 ) ;
}
static T_4
F_143 ( struct V_219 * V_116 ,
struct V_221 * V_222 ,
struct V_223 * V_224 ,
int * V_225 )
{
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
struct V_214 * V_26 = V_24 -> V_26 ;
switch ( V_26 -> V_215 ) {
case V_216 :
return F_144 ( V_116 , V_222 , V_224 ,
V_225 ) ;
case V_217 :
return F_145 ( V_116 , V_222 , V_224 ,
V_225 ) ;
case V_218 :
return F_146 ( V_116 , V_222 , V_224 ,
V_225 ) ;
default:
F_22 ( L_39 ,
V_26 -> V_215 ) ;
break;
}
return F_144 ( V_116 , V_222 , V_224 ,
V_225 ) ;
}
static char *
F_147 ( struct V_219 * V_116 ,
const char * V_226 ,
T_4 * V_227 ,
char * * V_228 )
{
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
struct V_214 * V_26 = V_24 -> V_26 ;
switch ( V_26 -> V_215 ) {
case V_216 :
return F_148 ( V_116 , V_226 , V_227 ,
V_228 ) ;
case V_217 :
return F_149 ( V_116 , V_226 , V_227 ,
V_228 ) ;
case V_218 :
return F_150 ( V_116 , V_226 , V_227 ,
V_228 ) ;
default:
F_22 ( L_39 ,
V_26 -> V_215 ) ;
break;
}
return F_148 ( V_116 , V_226 , V_227 ,
V_228 ) ;
}
static struct V_229 *
F_151 ( struct V_230 * V_231 ,
struct V_232 * V_233 ,
const char * V_234 )
{
struct V_214 * V_26 ;
char * V_235 ;
T_11 V_236 = 0 ;
int V_237 = 0 ;
V_26 = F_67 ( sizeof( struct V_214 ) , V_104 ) ;
if ( ! V_26 )
return F_152 ( - V_82 ) ;
V_26 -> V_238 = V_236 ;
V_235 = strstr ( V_234 , L_40 ) ;
if ( V_235 ) {
V_26 -> V_215 = V_216 ;
goto V_239;
}
V_235 = strstr ( V_234 , L_41 ) ;
if ( V_235 ) {
V_26 -> V_215 = V_217 ;
V_237 = 3 ;
goto V_239;
}
V_235 = strstr ( V_234 , L_42 ) ;
if ( V_235 ) {
V_26 -> V_215 = V_218 ;
goto V_239;
}
F_22 ( L_43 , V_234 ) ;
F_28 ( V_26 ) ;
return F_152 ( - V_98 ) ;
V_239:
if ( strlen ( V_234 ) >= V_193 ) {
F_22 ( L_44 , V_234 ,
F_131 ( V_26 ) , V_193 ) ;
F_28 ( V_26 ) ;
return F_152 ( - V_98 ) ;
}
snprintf ( & V_26 -> V_27 [ 0 ] , V_193 , L_45 , & V_234 [ V_237 ] ) ;
F_56 ( L_46 ,
F_131 ( V_26 ) , V_234 ) ;
return & V_26 -> V_240 ;
}
static void F_153 ( struct V_229 * V_241 )
{
struct V_214 * V_26 = F_34 ( V_241 ,
struct V_214 , V_240 ) ;
F_56 ( L_47 ,
F_131 ( V_26 ) , V_26 -> V_27 ) ;
F_28 ( V_26 ) ;
}
static struct V_221 *
F_154 ( struct V_219 * V_116 )
{
return F_67 ( sizeof( struct V_221 ) , V_104 ) ;
}
static void
F_155 ( struct V_219 * V_116 ,
struct V_221 * V_222 )
{
F_28 ( V_222 ) ;
}
static T_4 F_156 ( struct V_219 * V_116 )
{
return 1 ;
}
static int F_157 ( struct V_64 * V_64 )
{
if ( V_64 -> V_242 & V_243 )
return 0 ;
F_48 ( V_64 , 0 ) ;
return 1 ;
}
static void F_158 ( struct V_64 * V_64 )
{
struct V_16 * V_22 = F_34 ( V_64 ,
struct V_16 , V_64 ) ;
F_73 ( V_126 , V_22 ) ;
}
static int F_159 ( struct V_67 * V_244 )
{
return 0 ;
}
static void F_160 ( struct V_67 * V_244 )
{
}
static T_4 F_161 ( struct V_67 * V_244 )
{
return 0 ;
}
static int F_162 ( struct V_64 * V_64 )
{
F_163 ( V_64 ) ;
return 0 ;
}
static int F_164 ( struct V_64 * V_64 )
{
return 0 ;
}
static void F_165 ( struct V_221 * V_245 )
{
}
static T_4 F_166 ( struct V_64 * V_64 )
{
struct V_16 * V_22 = F_34 ( V_64 ,
struct V_16 , V_64 ) ;
return V_22 -> V_59 ;
}
static int F_167 ( struct V_64 * V_64 )
{
return 0 ;
}
static int F_168 ( struct V_64 * V_64 )
{
struct V_16 * V_22 = F_34 ( V_64 ,
struct V_16 , V_64 ) ;
V_22 -> V_47 = V_246 ;
F_44 ( V_22 ) ;
return 0 ;
}
static int F_169 ( struct V_64 * V_64 )
{
struct V_16 * V_22 = F_34 ( V_64 ,
struct V_16 , V_64 ) ;
if ( V_64 -> V_20 &&
( ( V_64 -> V_242 & V_247 ) ||
( V_64 -> V_242 & V_248 ) ) )
V_22 -> V_47 = ( V_249 << 24 ) |
V_250 ;
else
V_22 -> V_47 = V_64 -> V_251 ;
F_44 ( V_22 ) ;
return 0 ;
}
static void F_170 ( struct V_64 * V_64 )
{
struct V_120 * V_252 = V_64 -> V_120 ;
struct V_112 * V_113 = V_252 -> V_253 ;
F_128 ( & V_113 -> V_122 , 1 ) ;
F_5 ( & V_113 -> V_115 ) ;
}
static void F_171 ( struct V_64 * V_64 )
{
}
static T_12 F_172 ( struct V_219 * V_116 ,
char * V_5 )
{
struct V_23 * V_24 = F_34 ( V_116 , struct V_23 ,
V_116 ) ;
T_12 V_254 ;
F_35 ( & V_24 -> V_45 ) ;
V_254 = snprintf ( V_5 , V_102 , L_48 , V_24 -> V_175 ) ;
F_36 ( & V_24 -> V_45 ) ;
return V_254 ;
}
static T_12 F_173 ( struct V_219 * V_116 ,
const char * V_5 , T_13 V_255 )
{
struct V_23 * V_24 = F_34 ( V_116 , struct V_23 ,
V_116 ) ;
int V_54 ;
if ( strlen ( V_5 ) >= V_193 ) {
F_22 ( L_49 , V_5 ,
V_193 ) ;
return - V_98 ;
}
F_35 ( & V_24 -> V_45 ) ;
V_54 = snprintf ( V_24 -> V_175 , V_193 , L_45 , V_5 ) ;
if ( V_24 -> V_175 [ V_54 - 1 ] == '\n' )
V_24 -> V_175 [ V_54 - 1 ] = '\0' ;
F_36 ( & V_24 -> V_45 ) ;
return V_255 ;
}
static int F_174 ( struct V_23 * V_24 ,
const char * V_234 )
{
struct V_219 * V_116 ;
struct V_67 * V_244 ;
struct V_256 * V_257 ;
F_35 ( & V_24 -> V_45 ) ;
if ( V_24 -> V_69 ) {
F_36 ( & V_24 -> V_45 ) ;
F_56 ( L_50 ) ;
return - V_181 ;
}
V_116 = & V_24 -> V_116 ;
V_257 = F_67 ( sizeof( struct V_256 ) , V_104 ) ;
if ( ! V_257 ) {
F_36 ( & V_24 -> V_45 ) ;
return - V_82 ;
}
V_257 -> V_70 = F_175 ( V_258 ) ;
if ( F_113 ( V_257 -> V_70 ) ) {
F_36 ( & V_24 -> V_45 ) ;
F_28 ( V_257 ) ;
return - V_82 ;
}
V_244 = V_257 -> V_70 ;
V_257 -> V_70 -> V_221 = F_176 (
V_116 , ( unsigned char * ) V_234 ) ;
if ( ! V_257 -> V_70 -> V_221 ) {
F_36 ( & V_24 -> V_45 ) ;
F_56 ( L_51 ,
V_234 ) ;
goto V_114;
}
F_177 ( V_116 , V_257 -> V_70 -> V_221 ,
V_257 -> V_70 , V_257 ) ;
V_24 -> V_69 = V_257 ;
F_36 ( & V_24 -> V_45 ) ;
return 0 ;
V_114:
F_178 ( V_244 ) ;
F_28 ( V_257 ) ;
return - V_82 ;
}
static int F_179 ( struct V_23 * V_24 )
{
struct V_67 * V_244 ;
struct V_256 * V_257 ;
F_35 ( & V_24 -> V_45 ) ;
V_257 = V_24 -> V_69 ;
if ( ! V_257 ) {
F_36 ( & V_24 -> V_45 ) ;
return - V_138 ;
}
V_244 = V_257 -> V_70 ;
if ( ! V_244 ) {
F_36 ( & V_24 -> V_45 ) ;
return - V_138 ;
}
if ( V_24 -> V_259 != 0 ) {
F_36 ( & V_24 -> V_45 ) ;
F_22 ( L_52 ,
V_24 -> V_259 ) ;
return - V_260 ;
}
if ( V_24 -> V_46 != 0 ) {
F_36 ( & V_24 -> V_45 ) ;
F_22 ( L_53 ,
V_24 -> V_46 ) ;
return - V_260 ;
}
F_56 ( L_54 ,
F_131 ( V_24 -> V_26 ) ,
V_257 -> V_70 -> V_221 -> V_261 ) ;
F_180 ( V_257 -> V_70 ) ;
V_24 -> V_69 = NULL ;
F_36 ( & V_24 -> V_45 ) ;
F_28 ( V_257 ) ;
return 0 ;
}
static T_12 F_181 ( struct V_219 * V_116 ,
char * V_5 )
{
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
struct V_256 * V_257 ;
T_12 V_262 ;
F_35 ( & V_24 -> V_45 ) ;
V_257 = V_24 -> V_69 ;
if ( ! V_257 ) {
F_36 ( & V_24 -> V_45 ) ;
return - V_138 ;
}
V_262 = snprintf ( V_5 , V_102 , L_48 ,
V_257 -> V_70 -> V_221 -> V_261 ) ;
F_36 ( & V_24 -> V_45 ) ;
return V_262 ;
}
static T_12 F_182 ( struct V_219 * V_116 ,
const char * V_5 ,
T_13 V_255 )
{
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
struct V_214 * V_240 = V_24 -> V_26 ;
unsigned char V_263 [ V_193 ] , * V_235 , * V_264 ;
int V_262 ;
if ( ! strncmp ( V_5 , L_55 , 4 ) ) {
V_262 = F_179 ( V_24 ) ;
return ( ! V_262 ) ? V_255 : V_262 ;
}
if ( strlen ( V_5 ) >= V_193 ) {
F_22 ( L_56 ,
V_5 , V_193 ) ;
return - V_98 ;
}
snprintf ( & V_263 [ 0 ] , V_193 , L_45 , V_5 ) ;
V_235 = strstr ( V_263 , L_40 ) ;
if ( V_235 ) {
if ( V_240 -> V_215 != V_216 ) {
F_22 ( L_57 ,
V_263 , F_131 ( V_240 ) ) ;
return - V_98 ;
}
V_264 = & V_263 [ 0 ] ;
goto V_265;
}
V_235 = strstr ( V_263 , L_41 ) ;
if ( V_235 ) {
if ( V_240 -> V_215 != V_217 ) {
F_22 ( L_58 ,
V_263 , F_131 ( V_240 ) ) ;
return - V_98 ;
}
V_264 = & V_263 [ 3 ] ;
goto V_265;
}
V_235 = strstr ( V_263 , L_42 ) ;
if ( V_235 ) {
if ( V_240 -> V_215 != V_218 ) {
F_22 ( L_59 ,
V_263 , F_131 ( V_240 ) ) ;
return - V_98 ;
}
V_264 = & V_263 [ 0 ] ;
goto V_265;
}
F_22 ( L_60 ,
V_263 ) ;
return - V_98 ;
V_265:
if ( V_263 [ strlen ( V_263 ) - 1 ] == '\n' )
V_263 [ strlen ( V_263 ) - 1 ] = '\0' ;
V_262 = F_174 ( V_24 , V_264 ) ;
if ( V_262 < 0 )
return V_262 ;
return V_255 ;
}
static T_12
F_183 ( struct V_230 * V_231 ,
char * V_5 )
{
return sprintf ( V_5 , L_61
V_266 L_62 ,
V_267 , F_184 () -> V_268 , F_184 () -> V_269 ) ;
}
static char * F_185 ( void )
{
return L_63 ;
}
static int F_186 ( struct V_219 * V_116 ,
struct V_270 * V_28 )
{
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
F_35 ( & V_24 -> V_45 ) ;
V_24 -> V_259 ++ ;
F_36 ( & V_24 -> V_45 ) ;
return 0 ;
}
static void F_187 ( struct V_219 * V_116 ,
struct V_270 * V_28 )
{
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
F_35 ( & V_24 -> V_45 ) ;
V_24 -> V_259 -- ;
F_36 ( & V_24 -> V_45 ) ;
}
static struct V_219 *
F_188 ( struct V_229 * V_241 ,
struct V_232 * V_233 ,
const char * V_234 )
{
struct V_214 * V_26 = F_34 ( V_241 ,
struct V_214 , V_240 ) ;
struct V_23 * V_24 ;
T_10 V_271 ;
int V_262 ;
if ( strstr ( V_234 , L_64 ) != V_234 )
return F_152 ( - V_98 ) ;
V_262 = F_189 ( V_234 + 5 , 10 , & V_271 ) ;
if ( V_262 )
return F_152 ( V_262 ) ;
V_24 = F_67 ( sizeof( struct V_23 ) , V_104 ) ;
if ( ! V_24 )
return F_152 ( - V_82 ) ;
F_190 ( & V_24 -> V_45 ) ;
F_129 ( & V_24 -> V_272 ) ;
F_129 ( & V_24 -> V_273 ) ;
V_24 -> V_26 = V_26 ;
V_24 -> V_220 = V_271 ;
V_262 = F_191 ( & V_274 , V_241 ,
& V_24 -> V_116 , V_24 , V_275 ) ;
if ( V_262 < 0 ) {
F_28 ( V_24 ) ;
return NULL ;
}
F_35 ( & V_174 ) ;
F_103 ( & V_24 -> V_272 , & V_276 ) ;
F_36 ( & V_174 ) ;
return & V_24 -> V_116 ;
}
static void F_192 ( struct V_219 * V_116 )
{
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
F_35 ( & V_174 ) ;
F_16 ( & V_24 -> V_272 ) ;
F_36 ( & V_174 ) ;
F_179 ( V_24 ) ;
F_193 ( V_116 ) ;
F_28 ( V_24 ) ;
}
static int F_194 ( struct V_219 * V_116 )
{
return 1 ;
}
static int F_195 ( struct V_219 * V_116 )
{
return 0 ;
}
static void F_196 ( void * V_277 )
{
struct V_16 * V_278 = V_277 ;
int V_8 ;
memset ( V_278 , 0 , sizeof( * V_278 ) ) ;
for ( V_8 = 0 ; V_8 < V_279 ; V_8 ++ )
V_278 -> V_39 [ V_8 ] = V_40 ;
}
static int T_14 F_197 ( void )
{
int V_262 ;
if ( ! F_198 () )
return - V_138 ;
F_56 ( L_65 V_266 L_62 ,
V_267 , F_184 () -> V_268 , F_184 () -> V_269 ) ;
V_126 = F_199 ( L_66 ,
sizeof( struct V_16 ) , 0 , 0 , F_196 ) ;
if ( ! V_126 )
return - V_82 ;
V_262 = F_200 ( & V_280 ) ;
if ( V_262 )
goto V_281;
V_262 = F_201 ( & V_274 ) ;
if ( V_262 )
goto V_282;
return 0 ;
V_282:
F_202 ( & V_280 ) ;
V_281:
F_203 ( V_126 ) ;
F_22 ( L_67 , V_210 , V_262 ) ;
return V_262 ;
}
static void T_15 F_204 ( void )
{
struct V_5 * V_5 ;
while ( V_9 ) {
if ( F_12 ( & V_5 ) )
F_205 () ;
F_8 ( 1 , & V_5 ) ;
}
F_206 ( & V_274 ) ;
F_202 ( & V_280 ) ;
F_203 ( V_126 ) ;
}
