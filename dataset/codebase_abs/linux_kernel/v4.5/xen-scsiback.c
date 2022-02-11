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
V_64 -> V_72 = V_22 -> V_59 ;
V_71 = F_46 ( V_64 , V_68 , V_22 -> V_29 ,
V_22 -> V_20 , V_22 -> V_25 -> V_28 ,
V_22 -> V_73 , 0 ,
V_22 -> V_74 , 0 ,
V_22 -> V_36 , V_22 -> V_37 ,
NULL , 0 , NULL , 0 ) ;
if ( V_71 < 0 ) {
F_47 ( V_64 ,
V_75 , 0 ) ;
F_48 ( V_64 , 0 ) ;
}
}
static int F_49 ( struct V_76 * V_77 ,
struct V_5 * * V_78 , T_1 * V_79 , int V_80 )
{
int V_35 , V_8 ;
if ( ! V_80 )
return 0 ;
V_35 = F_50 ( V_77 , NULL , V_78 , V_80 ) ;
F_32 ( V_35 ) ;
for ( V_8 = 0 ; V_8 < V_80 ; V_8 ++ ) {
if ( F_51 ( V_77 [ V_8 ] . V_81 != V_82 ) ) {
F_22 ( L_2 ) ;
V_77 [ V_8 ] . V_34 = V_40 ;
V_35 = - V_83 ;
} else {
F_52 ( V_78 [ V_8 ] ) ;
}
V_79 [ V_8 ] = V_77 [ V_8 ] . V_34 ;
}
return V_35 ;
}
static int F_53 ( struct V_16 * V_22 ,
struct V_84 * V_18 , struct V_5 * * V_78 ,
T_1 * V_79 , int V_80 , T_4 V_7 )
{
int V_85 = 0 , V_8 , V_35 = 0 ;
struct V_76 V_77 [ V_32 ] ;
struct V_1 * V_2 = V_22 -> V_2 ;
for ( V_8 = 0 ; V_8 < V_80 ; V_8 ++ ) {
if ( F_12 ( V_78 + V_85 ) ) {
F_6 ( V_78 , V_85 ) ;
F_22 ( L_3 ) ;
return - V_83 ;
}
F_54 ( & V_77 [ V_85 ] , F_17 ( V_78 [ V_85 ] ) ,
V_7 , V_18 [ V_8 ] . V_86 , V_2 -> V_87 ) ;
V_85 ++ ;
if ( V_85 < V_32 )
continue;
V_35 = F_49 ( V_77 , V_78 , V_79 , V_85 ) ;
V_78 += V_85 ;
V_79 += V_85 ;
V_22 -> V_38 += V_85 ;
if ( V_35 )
return V_35 ;
V_85 = 0 ;
}
V_35 = F_49 ( V_77 , V_78 , V_79 , V_85 ) ;
V_22 -> V_38 += V_85 ;
return V_35 ;
}
static int F_55 ( struct V_88 * V_89 ,
struct V_16 * V_22 )
{
T_4 V_7 ;
int V_8 , V_35 , V_90 , V_91 = 0 ;
struct V_5 * * V_78 ;
struct V_84 * V_18 ;
unsigned long V_92 = 0 ;
unsigned int V_93 = ( unsigned int ) V_89 -> V_93 ;
unsigned int V_94 = 0 ;
struct V_95 * V_96 ;
T_1 * V_79 ;
V_22 -> V_37 = 0 ;
V_22 -> V_38 = 0 ;
V_22 -> V_73 = 0 ;
V_93 &= ~ V_97 ;
if ( ! V_93 )
return 0 ;
if ( V_93 > V_98 ) {
F_56 ( L_4 ,
V_89 -> V_93 ) ;
return - V_99 ;
}
if ( V_89 -> V_93 & V_97 ) {
V_35 = F_53 ( V_22 , V_89 -> V_18 ,
V_22 -> V_19 , V_22 -> V_39 ,
V_93 , V_41 | V_100 ) ;
if ( V_35 )
return V_35 ;
V_94 = V_93 ;
V_93 = 0 ;
for ( V_8 = 0 ; V_8 < V_94 ; V_8 ++ ) {
V_90 = V_89 -> V_18 [ V_8 ] . V_101 /
sizeof( struct V_84 ) ;
if ( ( unsigned ) V_89 -> V_18 [ V_8 ] . V_102 +
( unsigned ) V_89 -> V_18 [ V_8 ] . V_101 > V_103 ||
V_90 * sizeof( struct V_84 ) !=
V_89 -> V_18 [ V_8 ] . V_101 )
return - V_99 ;
V_93 += V_90 ;
}
if ( V_93 > V_104 ) {
F_56 ( L_5 , V_93 ) ;
return - V_99 ;
}
}
V_22 -> V_36 = F_57 ( V_93 ,
sizeof( struct V_95 ) , V_105 ) ;
if ( ! V_22 -> V_36 )
return - V_83 ;
F_58 ( V_22 -> V_36 , V_93 ) ;
V_22 -> V_37 = V_93 ;
V_7 = V_41 ;
if ( V_22 -> V_74 == V_106 )
V_7 |= V_100 ;
V_78 = V_22 -> V_19 + V_94 ;
V_79 = V_22 -> V_39 + V_94 ;
if ( ! V_94 ) {
V_18 = V_89 -> V_18 ;
V_35 = F_53 ( V_22 , V_18 ,
V_78 , V_79 , V_93 , V_7 ) ;
if ( V_35 )
return V_35 ;
} else {
for ( V_8 = 0 ; V_8 < V_94 ; V_8 ++ ) {
V_18 = (struct V_84 * ) (
F_20 ( V_22 , V_8 ) + V_89 -> V_18 [ V_8 ] . V_102 ) ;
V_90 = V_89 -> V_18 [ V_8 ] . V_101 /
sizeof( struct V_84 ) ;
V_35 = F_53 ( V_22 , V_18 ,
V_78 , V_79 , V_90 , V_7 ) ;
if ( V_35 )
return V_35 ;
V_78 += V_90 ;
V_79 += V_90 ;
}
V_92 = F_20 ( V_22 , 0 ) + V_89 -> V_18 [ 0 ] . V_102 ;
V_18 = (struct V_84 * ) V_92 ;
V_92 += V_89 -> V_18 [ 0 ] . V_101 ;
V_78 = V_22 -> V_19 + V_94 ;
}
F_59 (pending_req->sgl, sg, nr_segments, i) {
F_60 ( V_96 , V_78 [ V_8 ] , V_18 -> V_101 , V_18 -> V_102 ) ;
V_22 -> V_73 += V_18 -> V_101 ;
V_18 ++ ;
if ( V_94 && ( unsigned long ) V_18 >= V_92 ) {
V_91 ++ ;
V_92 = F_20 ( V_22 , V_91 ) +
V_89 -> V_18 [ V_91 ] . V_102 ;
V_18 = (struct V_84 * ) V_92 ;
V_92 += V_89 -> V_18 [ V_91 ] . V_101 ;
}
if ( V_96 -> V_102 >= V_103 ||
V_96 -> V_101 > V_103 ||
V_96 -> V_102 + V_96 -> V_101 > V_103 )
return - V_99 ;
}
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_62 ( V_2 -> V_4 ,
F_63 ( & V_2 -> V_3 ) == 0 ) ;
F_64 ( V_2 -> V_63 , V_2 ) ;
V_2 -> V_63 = 0 ;
F_65 ( V_2 -> V_107 , V_2 -> V_56 . V_108 ) ;
}
static void F_66 ( struct V_16 * V_22 ,
enum V_109 V_110 , int V_72 )
{
int V_71 , V_35 = V_111 ;
struct V_23 * V_24 = V_22 -> V_25 -> V_24 ;
struct V_64 * V_64 = & V_22 -> V_64 ;
struct V_112 * V_113 ;
V_113 = F_67 ( sizeof( struct V_112 ) , V_105 ) ;
if ( ! V_113 )
goto V_114;
F_68 ( & V_113 -> V_115 ) ;
F_69 ( V_64 , V_24 -> V_116 . V_117 ,
V_24 -> V_69 -> V_70 , 0 , V_118 , V_119 ,
& V_22 -> V_20 [ 0 ] ) ;
V_71 = F_70 ( V_64 , V_113 , V_110 , V_105 ) ;
if ( V_71 < 0 )
goto V_114;
V_64 -> V_120 -> V_121 = V_72 ;
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
struct V_88 * V_89 ,
struct V_16 * V_22 )
{
struct V_43 * V_25 ;
struct V_127 V_135 ;
V_22 -> V_59 = V_89 -> V_59 ;
V_22 -> V_2 = V_2 ;
V_135 . V_133 = V_89 -> V_136 ;
V_135 . V_134 = V_89 -> V_137 ;
V_135 . V_28 = V_89 -> V_28 ;
V_25 = F_74 ( V_2 , & V_135 ) ;
if ( ! V_25 ) {
V_22 -> V_25 = NULL ;
F_56 ( L_6 ,
V_135 . V_133 , V_135 . V_134 , V_135 . V_28 ) ;
return - V_138 ;
}
V_22 -> V_25 = V_25 ;
V_22 -> V_74 = V_89 -> V_74 ;
if ( ( V_22 -> V_74 != V_139 ) &&
( V_22 -> V_74 != V_106 ) &&
( V_22 -> V_74 != V_140 ) &&
( V_22 -> V_74 != V_118 ) ) {
F_56 ( L_7 ,
V_22 -> V_74 ) ;
return - V_99 ;
}
V_22 -> V_141 = V_89 -> V_141 ;
if ( V_22 -> V_141 > V_142 ) {
F_56 ( L_8 ,
V_22 -> V_141 ) ;
return - V_99 ;
}
memcpy ( V_22 -> V_29 , V_89 -> V_29 , V_22 -> V_141 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_143 * V_56 = & V_2 -> V_56 ;
struct V_88 V_89 ;
struct V_16 * V_22 ;
T_5 V_71 , V_144 ;
int V_35 , V_145 ;
T_3 V_47 ;
V_71 = V_56 -> V_146 ;
V_144 = V_56 -> V_108 -> V_147 ;
F_79 () ;
if ( F_80 ( V_56 , V_144 ) ) {
V_71 = V_56 -> V_57 ;
F_81 ( L_9 ,
V_2 -> V_87 , V_144 , V_71 , V_144 - V_71 ) ;
V_2 -> V_148 = 1 ;
return 0 ;
}
while ( ( V_71 != V_144 ) ) {
if ( F_82 ( V_56 , V_71 ) )
break;
V_22 = F_83 ( V_126 , V_105 ) ;
if ( ! V_22 )
return 1 ;
F_84 ( V_56 , V_71 , & V_89 ) ;
V_56 -> V_146 = ++ V_71 ;
V_35 = F_77 ( V_2 , & V_89 , V_22 ) ;
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
switch ( V_89 . V_110 ) {
case V_151 :
if ( F_55 ( & V_89 , V_22 ) ) {
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
V_89 . V_154 ) ;
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
struct V_162 * V_108 ;
int V_35 ;
if ( V_2 -> V_63 )
return - 1 ;
V_35 = F_90 ( V_2 -> V_107 , & V_159 , 1 , & V_161 ) ;
if ( V_35 )
return V_35 ;
V_108 = (struct V_162 * ) V_161 ;
F_91 ( & V_2 -> V_56 , V_108 , V_103 ) ;
V_35 = F_92 ( V_2 -> V_87 , V_160 ) ;
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
F_65 ( V_2 -> V_107 , V_161 ) ;
return V_35 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_166 * V_107 = V_2 -> V_107 ;
unsigned int V_159 , V_160 ;
int V_35 ;
V_35 = F_95 ( V_167 , V_107 -> V_168 ,
L_12 , L_13 , & V_159 ,
L_14 , L_13 , & V_160 , NULL ) ;
if ( V_35 ) {
F_96 ( V_107 , V_35 , L_15 , V_107 -> V_168 ) ;
return V_35 ;
}
return F_89 ( V_2 , V_159 , V_160 ) ;
}
static struct V_43 * F_97 (
struct V_1 * V_2 , struct V_127 * V_128 )
{
struct V_129 * V_130 = & ( V_2 -> V_131 ) ;
struct V_43 * V_44 ;
F_75 (entry, head, l)
if ( ( V_44 -> V_128 . V_133 == V_128 -> V_133 ) &&
( V_44 -> V_128 . V_134 == V_128 -> V_134 ) &&
( V_44 -> V_128 . V_28 == V_128 -> V_28 ) )
return V_44 ;
return NULL ;
}
static int F_98 ( struct V_1 * V_2 ,
char * V_169 , struct V_127 * V_128 )
{
int V_35 = 0 ;
struct V_43 * V_170 ;
unsigned long V_7 ;
char * V_171 ;
unsigned long long V_172 ;
struct V_173 * V_173 ;
struct V_23 * V_174 , * V_24 = NULL ;
char * error = L_16 ;
V_171 = strrchr ( V_169 , ':' ) ;
if ( ! V_171 ) {
F_22 ( L_17 , V_169 ) ;
return - V_99 ;
}
* V_171 = 0 ;
V_171 ++ ;
V_35 = F_99 ( V_171 , 10 , & V_172 ) ;
if ( V_35 < 0 ) {
F_22 ( L_18 , V_171 ) ;
return V_35 ;
}
F_35 ( & V_175 ) ;
F_75 (tpg_entry, &scsiback_list, tv_tpg_list) {
if ( ! strcmp ( V_169 , V_174 -> V_26 -> V_27 ) ||
! strcmp ( V_169 , V_174 -> V_176 ) ) {
F_35 ( & V_174 -> V_116 . V_177 ) ;
F_100 (se_lun, &tpg_entry->se_tpg.tpg_lun_hlist, link) {
if ( V_173 -> V_172 == V_172 ) {
if ( ! V_174 -> V_69 )
error = L_19 ;
else
V_24 = V_174 ;
break;
}
}
F_36 ( & V_174 -> V_116 . V_177 ) ;
break;
}
}
if ( V_24 ) {
F_35 ( & V_24 -> V_45 ) ;
V_24 -> V_46 ++ ;
F_36 ( & V_24 -> V_45 ) ;
}
F_36 ( & V_175 ) ;
if ( ! V_24 ) {
F_22 ( L_20 , V_169 , V_172 , error ) ;
return - V_138 ;
}
V_170 = F_101 ( sizeof( struct V_43 ) , V_105 ) ;
if ( V_170 == NULL ) {
V_35 = - V_83 ;
goto V_178;
}
F_9 ( & V_2 -> V_132 , V_7 ) ;
if ( F_97 ( V_2 , V_128 ) ) {
F_81 ( L_21 ) ;
V_35 = - V_179 ;
goto V_114;
}
F_102 ( & V_170 -> V_42 ) ;
V_170 -> V_128 = * V_128 ;
V_170 -> V_24 = V_24 ;
V_170 -> V_28 = V_172 ;
F_103 ( & V_170 -> V_180 , & V_2 -> V_131 ) ;
V_114:
F_11 ( & V_2 -> V_132 , V_7 ) ;
V_178:
if ( V_35 ) {
F_35 ( & V_24 -> V_45 ) ;
V_24 -> V_46 -- ;
F_36 ( & V_24 -> V_45 ) ;
F_28 ( V_170 ) ;
}
return V_35 ;
}
static void F_104 ( struct V_43 * V_44 )
{
F_16 ( & V_44 -> V_180 ) ;
F_43 ( & V_44 -> V_42 , F_33 ) ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
struct V_43 * V_44 ;
unsigned long V_7 ;
int V_181 = 0 ;
F_9 ( & V_2 -> V_132 , V_7 ) ;
V_44 = F_97 ( V_2 , V_128 ) ;
if ( V_44 )
F_104 ( V_44 ) ;
else
V_181 = - V_182 ;
F_11 ( & V_2 -> V_132 , V_7 ) ;
return V_181 ;
}
static void F_106 ( struct V_1 * V_2 , const char * V_183 ,
char * V_169 , struct V_127 * V_135 , int V_184 )
{
struct V_43 * V_44 ;
unsigned long V_7 ;
if ( V_184 ) {
F_9 ( & V_2 -> V_132 , V_7 ) ;
V_44 = F_97 ( V_2 , V_135 ) ;
F_11 ( & V_2 -> V_132 , V_7 ) ;
if ( V_44 )
return;
}
if ( ! F_98 ( V_2 , V_169 , V_135 ) ) {
if ( F_107 ( V_167 , V_2 -> V_107 -> V_185 , V_183 ,
L_22 , V_186 ) ) {
F_22 ( L_23 , V_183 ) ;
F_105 ( V_2 , V_135 ) ;
}
} else if ( ! V_184 ) {
F_107 ( V_167 , V_2 -> V_107 -> V_185 , V_183 ,
L_22 , V_187 ) ;
}
}
static void F_108 ( struct V_1 * V_2 , const char * V_183 ,
struct V_127 * V_135 )
{
if ( ! F_105 ( V_2 , V_135 ) ) {
if ( F_107 ( V_167 , V_2 -> V_107 -> V_185 , V_183 ,
L_22 , V_187 ) )
F_22 ( L_23 , V_183 ) ;
}
}
static void F_109 ( struct V_1 * V_2 , int V_188 ,
char * V_189 )
{
int V_35 ;
struct V_127 V_135 ;
char * V_190 ;
int V_191 ;
char V_169 [ V_192 ] ;
char V_193 [ 64 ] ;
char V_183 [ 64 ] ;
struct V_166 * V_107 = V_2 -> V_107 ;
snprintf ( V_183 , sizeof( V_183 ) , L_24 , V_189 ) ;
V_35 = F_110 ( V_167 , V_107 -> V_185 , V_183 , L_13 , & V_191 ) ;
if ( F_111 ( V_35 ) )
return;
snprintf ( V_193 , sizeof( V_193 ) , L_25 , V_189 ) ;
V_190 = F_112 ( V_167 , V_107 -> V_185 , V_193 , NULL ) ;
if ( F_113 ( V_190 ) ) {
F_107 ( V_167 , V_107 -> V_185 , V_183 ,
L_22 , V_187 ) ;
return;
}
F_114 ( V_169 , V_190 , V_192 ) ;
F_28 ( V_190 ) ;
snprintf ( V_193 , sizeof( V_193 ) , L_26 , V_189 ) ;
V_35 = F_110 ( V_167 , V_107 -> V_185 , V_193 , L_27 ,
& V_135 . V_194 , & V_135 . V_133 , & V_135 . V_134 , & V_135 . V_28 ) ;
if ( F_111 ( V_35 ) ) {
F_107 ( V_167 , V_107 -> V_185 , V_183 ,
L_22 , V_187 ) ;
return;
}
switch ( V_188 ) {
case V_195 :
switch ( V_191 ) {
case V_196 :
F_106 ( V_2 , V_183 , V_169 , & V_135 , 0 ) ;
break;
case V_197 :
F_106 ( V_2 , V_183 , V_169 , & V_135 , 1 ) ;
break;
case V_198 :
F_108 ( V_2 , V_183 , & V_135 ) ;
break;
default:
break;
}
break;
case V_199 :
if ( V_191 == V_186 ) {
if ( F_107 ( V_167 , V_107 -> V_185 , V_183 ,
L_22 , V_197 ) ) {
F_22 ( L_23 , V_193 ) ;
F_105 ( V_2 , & V_135 ) ;
F_107 ( V_167 , V_107 -> V_185 , V_183 ,
L_22 , V_187 ) ;
}
}
break;
default:
break;
}
}
static void F_115 ( struct V_1 * V_2 , int V_188 )
{
int V_8 ;
char * * V_200 ;
unsigned int V_201 = 0 ;
V_200 = F_116 ( V_167 , V_2 -> V_107 -> V_185 , L_28 ,
& V_201 ) ;
if ( F_113 ( V_200 ) )
return;
for ( V_8 = 0 ; V_8 < V_201 ; V_8 ++ )
F_109 ( V_2 , V_188 , V_200 [ V_8 ] ) ;
F_28 ( V_200 ) ;
}
static void F_117 ( struct V_166 * V_107 ,
enum V_202 V_203 )
{
struct V_1 * V_2 = F_118 ( & V_107 -> V_107 ) ;
switch ( V_203 ) {
case V_196 :
break;
case V_186 :
if ( F_94 ( V_2 ) )
break;
F_115 ( V_2 , V_195 ) ;
F_119 ( V_107 , V_197 ) ;
break;
case V_197 :
F_115 ( V_2 , V_199 ) ;
if ( V_107 -> V_183 == V_197 )
break;
F_119 ( V_107 , V_197 ) ;
break;
case V_198 :
if ( V_2 -> V_63 )
F_61 ( V_2 ) ;
F_119 ( V_107 , V_198 ) ;
break;
case V_187 :
F_119 ( V_107 , V_187 ) ;
if ( F_120 ( V_107 ) )
break;
case V_204 :
F_121 ( & V_107 -> V_107 ) ;
break;
case V_205 :
F_115 ( V_2 , V_195 ) ;
F_119 ( V_107 , V_206 ) ;
break;
default:
F_96 ( V_107 , - V_99 , L_29 ,
V_203 ) ;
break;
}
}
static void F_122 ( struct V_1 * V_2 )
{
struct V_43 * V_44 , * V_207 ;
struct V_129 * V_130 = & ( V_2 -> V_131 ) ;
unsigned long V_7 ;
F_9 ( & V_2 -> V_132 , V_7 ) ;
F_123 (entry, tmp, head, l)
F_104 ( V_44 ) ;
F_11 ( & V_2 -> V_132 , V_7 ) ;
}
static int F_124 ( struct V_166 * V_107 )
{
struct V_1 * V_2 = F_118 ( & V_107 -> V_107 ) ;
if ( V_2 -> V_63 )
F_61 ( V_2 ) ;
F_122 ( V_2 ) ;
F_125 ( & V_107 -> V_107 , NULL ) ;
return 0 ;
}
static int F_126 ( struct V_166 * V_107 ,
const struct V_208 * V_137 )
{
int V_35 ;
struct V_1 * V_2 = F_67 ( sizeof( struct V_1 ) ,
V_105 ) ;
F_56 ( L_30 , V_209 , V_107 , V_107 -> V_210 ) ;
if ( ! V_2 ) {
F_96 ( V_107 , - V_83 , L_31 ) ;
return - V_83 ;
}
V_2 -> V_107 = V_107 ;
F_125 ( & V_107 -> V_107 , V_2 ) ;
V_2 -> V_87 = V_107 -> V_210 ;
F_127 ( & V_2 -> V_55 ) ;
V_2 -> V_148 = 0 ;
F_128 ( & V_2 -> V_3 , 0 ) ;
F_68 ( & V_2 -> V_4 ) ;
V_2 -> V_107 = V_107 ;
V_2 -> V_63 = 0 ;
F_129 ( & V_2 -> V_131 ) ;
F_127 ( & V_2 -> V_132 ) ;
V_35 = F_107 ( V_167 , V_107 -> V_185 , L_32 , L_13 ,
V_104 ) ;
if ( V_35 )
F_130 ( V_107 , V_35 , L_33 ) ;
V_35 = F_119 ( V_107 , V_211 ) ;
if ( V_35 )
goto V_212;
return 0 ;
V_212:
F_81 ( L_34 , V_209 ) ;
F_124 ( V_107 ) ;
return V_35 ;
}
static char * F_131 ( struct V_213 * V_26 )
{
switch ( V_26 -> V_214 ) {
case V_215 :
return L_35 ;
case V_216 :
return L_36 ;
case V_217 :
return L_37 ;
default:
break;
}
return L_38 ;
}
static char * F_132 ( struct V_218 * V_116 )
{
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
struct V_213 * V_26 = V_24 -> V_26 ;
return & V_26 -> V_27 [ 0 ] ;
}
static T_9 F_133 ( struct V_218 * V_116 )
{
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
return V_24 -> V_219 ;
}
static struct V_220 *
F_134 ( struct V_221 * V_222 ,
struct V_223 * V_224 ,
const char * V_225 )
{
struct V_213 * V_26 ;
char * V_226 ;
T_10 V_227 = 0 ;
int V_228 = 0 ;
V_26 = F_67 ( sizeof( struct V_213 ) , V_105 ) ;
if ( ! V_26 )
return F_135 ( - V_83 ) ;
V_26 -> V_229 = V_227 ;
V_226 = strstr ( V_225 , L_39 ) ;
if ( V_226 ) {
V_26 -> V_214 = V_215 ;
goto V_230;
}
V_226 = strstr ( V_225 , L_40 ) ;
if ( V_226 ) {
V_26 -> V_214 = V_216 ;
V_228 = 3 ;
goto V_230;
}
V_226 = strstr ( V_225 , L_41 ) ;
if ( V_226 ) {
V_26 -> V_214 = V_217 ;
goto V_230;
}
F_22 ( L_42 , V_225 ) ;
F_28 ( V_26 ) ;
return F_135 ( - V_99 ) ;
V_230:
if ( strlen ( V_225 ) >= V_192 ) {
F_22 ( L_43 , V_225 ,
F_131 ( V_26 ) , V_192 ) ;
F_28 ( V_26 ) ;
return F_135 ( - V_99 ) ;
}
snprintf ( & V_26 -> V_27 [ 0 ] , V_192 , L_44 , & V_225 [ V_228 ] ) ;
F_56 ( L_45 ,
F_131 ( V_26 ) , V_225 ) ;
return & V_26 -> V_231 ;
}
static void F_136 ( struct V_220 * V_232 )
{
struct V_213 * V_26 = F_34 ( V_232 ,
struct V_213 , V_231 ) ;
F_56 ( L_46 ,
F_131 ( V_26 ) , V_26 -> V_27 ) ;
F_28 ( V_26 ) ;
}
static T_4 F_137 ( struct V_218 * V_116 )
{
return 1 ;
}
static int F_138 ( struct V_64 * V_64 )
{
if ( V_64 -> V_233 & V_234 )
return 0 ;
F_48 ( V_64 , 0 ) ;
return 1 ;
}
static void F_139 ( struct V_64 * V_64 )
{
struct V_16 * V_22 = F_34 ( V_64 ,
struct V_16 , V_64 ) ;
F_73 ( V_126 , V_22 ) ;
}
static int F_140 ( struct V_67 * V_235 )
{
return 0 ;
}
static void F_141 ( struct V_67 * V_235 )
{
}
static T_4 F_142 ( struct V_67 * V_235 )
{
return 0 ;
}
static int F_143 ( struct V_64 * V_64 )
{
F_144 ( V_64 ) ;
return 0 ;
}
static int F_145 ( struct V_64 * V_64 )
{
return 0 ;
}
static void F_146 ( struct V_236 * V_237 )
{
}
static int F_147 ( struct V_64 * V_64 )
{
return 0 ;
}
static int F_148 ( struct V_64 * V_64 )
{
struct V_16 * V_22 = F_34 ( V_64 ,
struct V_16 , V_64 ) ;
V_22 -> V_47 = V_238 ;
F_44 ( V_22 ) ;
return 0 ;
}
static int F_149 ( struct V_64 * V_64 )
{
struct V_16 * V_22 = F_34 ( V_64 ,
struct V_16 , V_64 ) ;
if ( V_64 -> V_20 &&
( ( V_64 -> V_233 & V_239 ) ||
( V_64 -> V_233 & V_240 ) ) )
V_22 -> V_47 = ( V_241 << 24 ) |
V_242 ;
else
V_22 -> V_47 = V_64 -> V_243 ;
F_44 ( V_22 ) ;
return 0 ;
}
static void F_150 ( struct V_64 * V_64 )
{
struct V_120 * V_244 = V_64 -> V_120 ;
struct V_112 * V_113 = V_244 -> V_245 ;
F_128 ( & V_113 -> V_122 , 1 ) ;
F_5 ( & V_113 -> V_115 ) ;
}
static void F_151 ( struct V_64 * V_64 )
{
}
static T_11 F_152 ( struct V_246 * V_247 ,
char * V_5 )
{
struct V_218 * V_116 = F_153 ( V_247 ) ;
struct V_23 * V_24 = F_34 ( V_116 , struct V_23 ,
V_116 ) ;
T_11 V_248 ;
F_35 ( & V_24 -> V_45 ) ;
V_248 = snprintf ( V_5 , V_103 , L_47 , V_24 -> V_176 ) ;
F_36 ( & V_24 -> V_45 ) ;
return V_248 ;
}
static T_11 F_154 ( struct V_246 * V_247 ,
const char * V_5 , T_12 V_249 )
{
struct V_218 * V_116 = F_153 ( V_247 ) ;
struct V_23 * V_24 = F_34 ( V_116 , struct V_23 ,
V_116 ) ;
int V_54 ;
if ( strlen ( V_5 ) >= V_192 ) {
F_22 ( L_48 , V_5 ,
V_192 ) ;
return - V_99 ;
}
F_35 ( & V_24 -> V_45 ) ;
V_54 = snprintf ( V_24 -> V_176 , V_192 , L_44 , V_5 ) ;
if ( V_24 -> V_176 [ V_54 - 1 ] == '\n' )
V_24 -> V_176 [ V_54 - 1 ] = '\0' ;
F_36 ( & V_24 -> V_45 ) ;
return V_249 ;
}
static int F_155 ( struct V_23 * V_24 ,
const char * V_225 )
{
struct V_218 * V_116 ;
struct V_67 * V_235 ;
struct V_250 * V_251 ;
F_35 ( & V_24 -> V_45 ) ;
if ( V_24 -> V_69 ) {
F_36 ( & V_24 -> V_45 ) ;
F_56 ( L_49 ) ;
return - V_179 ;
}
V_116 = & V_24 -> V_116 ;
V_251 = F_67 ( sizeof( struct V_250 ) , V_105 ) ;
if ( ! V_251 ) {
F_36 ( & V_24 -> V_45 ) ;
return - V_83 ;
}
V_251 -> V_70 = F_156 ( V_252 ) ;
if ( F_113 ( V_251 -> V_70 ) ) {
F_36 ( & V_24 -> V_45 ) ;
F_28 ( V_251 ) ;
return - V_83 ;
}
V_235 = V_251 -> V_70 ;
V_251 -> V_70 -> V_236 = F_157 (
V_116 , ( unsigned char * ) V_225 ) ;
if ( ! V_251 -> V_70 -> V_236 ) {
F_36 ( & V_24 -> V_45 ) ;
F_56 ( L_50 ,
V_225 ) ;
goto V_114;
}
F_158 ( V_116 , V_251 -> V_70 -> V_236 ,
V_251 -> V_70 , V_251 ) ;
V_24 -> V_69 = V_251 ;
F_36 ( & V_24 -> V_45 ) ;
return 0 ;
V_114:
F_159 ( V_235 ) ;
F_28 ( V_251 ) ;
return - V_83 ;
}
static int F_160 ( struct V_23 * V_24 )
{
struct V_67 * V_235 ;
struct V_250 * V_251 ;
F_35 ( & V_24 -> V_45 ) ;
V_251 = V_24 -> V_69 ;
if ( ! V_251 ) {
F_36 ( & V_24 -> V_45 ) ;
return - V_138 ;
}
V_235 = V_251 -> V_70 ;
if ( ! V_235 ) {
F_36 ( & V_24 -> V_45 ) ;
return - V_138 ;
}
if ( V_24 -> V_253 != 0 ) {
F_36 ( & V_24 -> V_45 ) ;
F_22 ( L_51 ,
V_24 -> V_253 ) ;
return - V_254 ;
}
if ( V_24 -> V_46 != 0 ) {
F_36 ( & V_24 -> V_45 ) ;
F_22 ( L_52 ,
V_24 -> V_46 ) ;
return - V_254 ;
}
F_56 ( L_53 ,
F_131 ( V_24 -> V_26 ) ,
V_251 -> V_70 -> V_236 -> V_255 ) ;
F_161 ( V_251 -> V_70 ) ;
V_24 -> V_69 = NULL ;
F_36 ( & V_24 -> V_45 ) ;
F_28 ( V_251 ) ;
return 0 ;
}
static T_11 F_162 ( struct V_246 * V_247 , char * V_5 )
{
struct V_218 * V_116 = F_163 ( V_247 ) ;
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
struct V_250 * V_251 ;
T_11 V_181 ;
F_35 ( & V_24 -> V_45 ) ;
V_251 = V_24 -> V_69 ;
if ( ! V_251 ) {
F_36 ( & V_24 -> V_45 ) ;
return - V_138 ;
}
V_181 = snprintf ( V_5 , V_103 , L_47 ,
V_251 -> V_70 -> V_236 -> V_255 ) ;
F_36 ( & V_24 -> V_45 ) ;
return V_181 ;
}
static T_11 F_164 ( struct V_246 * V_247 ,
const char * V_5 , T_12 V_249 )
{
struct V_218 * V_116 = F_163 ( V_247 ) ;
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
struct V_213 * V_231 = V_24 -> V_26 ;
unsigned char V_256 [ V_192 ] , * V_226 , * V_257 ;
int V_181 ;
if ( ! strncmp ( V_5 , L_54 , 4 ) ) {
V_181 = F_160 ( V_24 ) ;
return ( ! V_181 ) ? V_249 : V_181 ;
}
if ( strlen ( V_5 ) >= V_192 ) {
F_22 ( L_55 ,
V_5 , V_192 ) ;
return - V_99 ;
}
snprintf ( & V_256 [ 0 ] , V_192 , L_44 , V_5 ) ;
V_226 = strstr ( V_256 , L_39 ) ;
if ( V_226 ) {
if ( V_231 -> V_214 != V_215 ) {
F_22 ( L_56 ,
V_256 , F_131 ( V_231 ) ) ;
return - V_99 ;
}
V_257 = & V_256 [ 0 ] ;
goto V_258;
}
V_226 = strstr ( V_256 , L_40 ) ;
if ( V_226 ) {
if ( V_231 -> V_214 != V_216 ) {
F_22 ( L_57 ,
V_256 , F_131 ( V_231 ) ) ;
return - V_99 ;
}
V_257 = & V_256 [ 3 ] ;
goto V_258;
}
V_226 = strstr ( V_256 , L_41 ) ;
if ( V_226 ) {
if ( V_231 -> V_214 != V_217 ) {
F_22 ( L_58 ,
V_256 , F_131 ( V_231 ) ) ;
return - V_99 ;
}
V_257 = & V_256 [ 0 ] ;
goto V_258;
}
F_22 ( L_59 ,
V_256 ) ;
return - V_99 ;
V_258:
if ( V_256 [ strlen ( V_256 ) - 1 ] == '\n' )
V_256 [ strlen ( V_256 ) - 1 ] = '\0' ;
V_181 = F_155 ( V_24 , V_257 ) ;
if ( V_181 < 0 )
return V_181 ;
return V_249 ;
}
static T_11
F_165 ( struct V_246 * V_247 , char * V_5 )
{
return sprintf ( V_5 , L_60
V_259 L_61 ,
V_260 , F_166 () -> V_261 , F_166 () -> V_262 ) ;
}
static char * F_167 ( void )
{
return L_62 ;
}
static int F_168 ( struct V_218 * V_116 ,
struct V_173 * V_28 )
{
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
F_35 ( & V_24 -> V_45 ) ;
V_24 -> V_253 ++ ;
F_36 ( & V_24 -> V_45 ) ;
return 0 ;
}
static void F_169 ( struct V_218 * V_116 ,
struct V_173 * V_28 )
{
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
F_35 ( & V_24 -> V_45 ) ;
V_24 -> V_253 -- ;
F_36 ( & V_24 -> V_45 ) ;
}
static struct V_218 *
F_170 ( struct V_220 * V_232 ,
struct V_223 * V_224 ,
const char * V_225 )
{
struct V_213 * V_26 = F_34 ( V_232 ,
struct V_213 , V_231 ) ;
struct V_23 * V_24 ;
T_9 V_263 ;
int V_181 ;
if ( strstr ( V_225 , L_63 ) != V_225 )
return F_135 ( - V_99 ) ;
V_181 = F_171 ( V_225 + 5 , 10 , & V_263 ) ;
if ( V_181 )
return F_135 ( V_181 ) ;
V_24 = F_67 ( sizeof( struct V_23 ) , V_105 ) ;
if ( ! V_24 )
return F_135 ( - V_83 ) ;
F_172 ( & V_24 -> V_45 ) ;
F_129 ( & V_24 -> V_264 ) ;
F_129 ( & V_24 -> V_265 ) ;
V_24 -> V_26 = V_26 ;
V_24 -> V_219 = V_263 ;
V_181 = F_173 ( V_232 , & V_24 -> V_116 , V_26 -> V_214 ) ;
if ( V_181 < 0 ) {
F_28 ( V_24 ) ;
return NULL ;
}
F_35 ( & V_175 ) ;
F_103 ( & V_24 -> V_264 , & V_266 ) ;
F_36 ( & V_175 ) ;
return & V_24 -> V_116 ;
}
static void F_174 ( struct V_218 * V_116 )
{
struct V_23 * V_24 = F_34 ( V_116 ,
struct V_23 , V_116 ) ;
F_35 ( & V_175 ) ;
F_16 ( & V_24 -> V_264 ) ;
F_36 ( & V_175 ) ;
F_160 ( V_24 ) ;
F_175 ( V_116 ) ;
F_28 ( V_24 ) ;
}
static int F_176 ( struct V_218 * V_116 )
{
return 1 ;
}
static int F_177 ( struct V_218 * V_116 )
{
return 0 ;
}
static void F_178 ( void * V_267 )
{
struct V_16 * V_268 = V_267 ;
int V_8 ;
memset ( V_268 , 0 , sizeof( * V_268 ) ) ;
for ( V_8 = 0 ; V_8 < V_269 ; V_8 ++ )
V_268 -> V_39 [ V_8 ] = V_40 ;
}
static int T_13 F_179 ( void )
{
int V_181 ;
if ( ! F_180 () )
return - V_138 ;
F_56 ( L_64 V_259 L_61 ,
V_260 , F_166 () -> V_261 , F_166 () -> V_262 ) ;
V_126 = F_181 ( L_65 ,
sizeof( struct V_16 ) , 0 , 0 , F_178 ) ;
if ( ! V_126 )
return - V_83 ;
V_181 = F_182 ( & V_270 ) ;
if ( V_181 )
goto V_271;
V_181 = F_183 ( & V_272 ) ;
if ( V_181 )
goto V_273;
return 0 ;
V_273:
F_184 ( & V_270 ) ;
V_271:
F_185 ( V_126 ) ;
F_22 ( L_66 , V_209 , V_181 ) ;
return V_181 ;
}
static void T_14 F_186 ( void )
{
struct V_5 * V_5 ;
while ( V_9 ) {
if ( F_12 ( & V_5 ) )
F_187 () ;
F_8 ( 1 , & V_5 ) ;
}
F_188 ( & V_272 ) ;
F_184 ( & V_270 ) ;
F_185 ( V_126 ) ;
}
