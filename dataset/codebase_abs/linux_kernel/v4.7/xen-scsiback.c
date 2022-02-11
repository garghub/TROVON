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
static void F_37 ( struct V_1 * V_2 ,
char * V_20 , T_2 V_47 , T_3 V_48 ,
T_4 V_49 )
{
struct V_50 * V_51 ;
int V_52 ;
struct V_53 V_54 ;
unsigned long V_7 ;
unsigned V_55 ;
F_9 ( & V_2 -> V_56 , V_7 ) ;
V_51 = F_38 ( & V_2 -> V_57 , V_2 -> V_57 . V_58 ) ;
V_2 -> V_57 . V_58 ++ ;
V_51 -> V_59 = V_47 ;
V_51 -> V_49 = V_49 ;
if ( V_20 != NULL &&
F_39 ( V_20 , V_60 ,
& V_54 ) ) {
V_55 = F_40 ( unsigned , 8 + V_20 [ 7 ] ,
V_60 ) ;
memcpy ( V_51 -> V_20 , V_20 , V_55 ) ;
V_51 -> V_61 = V_55 ;
} else {
V_51 -> V_61 = 0 ;
}
V_51 -> V_62 = V_48 ;
F_41 ( & V_2 -> V_57 , V_52 ) ;
F_11 ( & V_2 -> V_56 , V_7 ) ;
if ( V_52 )
F_42 ( V_2 -> V_63 ) ;
}
static void F_43 ( char * V_20 , T_2 V_47 ,
T_3 V_48 , struct V_16 * V_22 )
{
F_37 ( V_22 -> V_2 , V_20 , V_47 ,
V_48 , V_22 -> V_49 ) ;
if ( V_22 -> V_25 )
F_44 ( & V_22 -> V_25 -> V_42 ,
F_33 ) ;
}
static void F_45 ( struct V_16 * V_22 )
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
F_43 ( V_20 , V_21 , V_48 , V_22 ) ;
F_3 ( V_2 ) ;
F_46 ( & V_22 -> V_64 ) ;
}
static void F_47 ( struct V_16 * V_22 )
{
struct V_64 * V_64 = & V_22 -> V_64 ;
struct V_67 * V_68 = V_22 -> V_25 -> V_24 -> V_69 -> V_70 ;
int V_71 ;
F_1 ( V_22 -> V_2 ) ;
V_64 -> V_72 = V_22 -> V_49 ;
V_71 = F_48 ( V_64 , V_68 , V_22 -> V_29 ,
V_22 -> V_20 , V_22 -> V_25 -> V_28 ,
V_22 -> V_73 , 0 ,
V_22 -> V_74 , V_75 ,
V_22 -> V_36 , V_22 -> V_37 ,
NULL , 0 , NULL , 0 ) ;
if ( V_71 < 0 ) {
F_49 ( V_64 ,
V_76 , 0 ) ;
F_50 ( V_64 , 0 ) ;
}
}
static int F_51 ( struct V_77 * V_78 ,
struct V_5 * * V_79 , T_1 * V_80 , int V_81 )
{
int V_35 , V_8 ;
if ( ! V_81 )
return 0 ;
V_35 = F_52 ( V_78 , NULL , V_79 , V_81 ) ;
F_32 ( V_35 ) ;
for ( V_8 = 0 ; V_8 < V_81 ; V_8 ++ ) {
if ( F_53 ( V_78 [ V_8 ] . V_82 != V_83 ) ) {
F_22 ( L_2 ) ;
V_78 [ V_8 ] . V_34 = V_40 ;
V_35 = - V_84 ;
} else {
F_54 ( V_79 [ V_8 ] ) ;
}
V_80 [ V_8 ] = V_78 [ V_8 ] . V_34 ;
}
return V_35 ;
}
static int F_55 ( struct V_16 * V_22 ,
struct V_85 * V_18 , struct V_5 * * V_79 ,
T_1 * V_80 , int V_81 , T_5 V_7 )
{
int V_86 = 0 , V_8 , V_35 = 0 ;
struct V_77 V_78 [ V_32 ] ;
struct V_1 * V_2 = V_22 -> V_2 ;
for ( V_8 = 0 ; V_8 < V_81 ; V_8 ++ ) {
if ( F_12 ( V_79 + V_86 ) ) {
F_6 ( V_79 , V_86 ) ;
F_22 ( L_3 ) ;
return - V_84 ;
}
F_56 ( & V_78 [ V_86 ] , F_17 ( V_79 [ V_86 ] ) ,
V_7 , V_18 [ V_8 ] . V_87 , V_2 -> V_88 ) ;
V_86 ++ ;
if ( V_86 < V_32 )
continue;
V_35 = F_51 ( V_78 , V_79 , V_80 , V_86 ) ;
V_79 += V_86 ;
V_80 += V_86 ;
V_22 -> V_38 += V_86 ;
if ( V_35 )
return V_35 ;
V_86 = 0 ;
}
V_35 = F_51 ( V_78 , V_79 , V_80 , V_86 ) ;
V_22 -> V_38 += V_86 ;
return V_35 ;
}
static int F_57 ( struct V_89 * V_90 ,
struct V_16 * V_22 )
{
T_5 V_7 ;
int V_8 , V_35 , V_91 , V_92 = 0 ;
struct V_5 * * V_79 ;
struct V_85 * V_18 ;
unsigned long V_93 = 0 ;
unsigned int V_94 = ( unsigned int ) V_90 -> V_94 ;
unsigned int V_95 = 0 ;
struct V_96 * V_97 ;
T_1 * V_80 ;
V_22 -> V_37 = 0 ;
V_22 -> V_38 = 0 ;
V_22 -> V_73 = 0 ;
V_94 &= ~ V_98 ;
if ( ! V_94 )
return 0 ;
if ( V_94 > V_99 ) {
F_58 ( L_4 ,
V_90 -> V_94 ) ;
return - V_100 ;
}
if ( V_90 -> V_94 & V_98 ) {
V_35 = F_55 ( V_22 , V_90 -> V_18 ,
V_22 -> V_19 , V_22 -> V_39 ,
V_94 , V_41 | V_101 ) ;
if ( V_35 )
return V_35 ;
V_95 = V_94 ;
V_94 = 0 ;
for ( V_8 = 0 ; V_8 < V_95 ; V_8 ++ ) {
V_91 = V_90 -> V_18 [ V_8 ] . V_102 /
sizeof( struct V_85 ) ;
if ( ( unsigned ) V_90 -> V_18 [ V_8 ] . V_103 +
( unsigned ) V_90 -> V_18 [ V_8 ] . V_102 > V_104 ||
V_91 * sizeof( struct V_85 ) !=
V_90 -> V_18 [ V_8 ] . V_102 )
return - V_100 ;
V_94 += V_91 ;
}
if ( V_94 > V_105 ) {
F_58 ( L_5 , V_94 ) ;
return - V_100 ;
}
}
V_22 -> V_36 = F_59 ( V_94 ,
sizeof( struct V_96 ) , V_106 ) ;
if ( ! V_22 -> V_36 )
return - V_84 ;
F_60 ( V_22 -> V_36 , V_94 ) ;
V_22 -> V_37 = V_94 ;
V_7 = V_41 ;
if ( V_22 -> V_74 == V_107 )
V_7 |= V_101 ;
V_79 = V_22 -> V_19 + V_95 ;
V_80 = V_22 -> V_39 + V_95 ;
if ( ! V_95 ) {
V_18 = V_90 -> V_18 ;
V_35 = F_55 ( V_22 , V_18 ,
V_79 , V_80 , V_94 , V_7 ) ;
if ( V_35 )
return V_35 ;
} else {
for ( V_8 = 0 ; V_8 < V_95 ; V_8 ++ ) {
V_18 = (struct V_85 * ) (
F_20 ( V_22 , V_8 ) + V_90 -> V_18 [ V_8 ] . V_103 ) ;
V_91 = V_90 -> V_18 [ V_8 ] . V_102 /
sizeof( struct V_85 ) ;
V_35 = F_55 ( V_22 , V_18 ,
V_79 , V_80 , V_91 , V_7 ) ;
if ( V_35 )
return V_35 ;
V_79 += V_91 ;
V_80 += V_91 ;
}
V_93 = F_20 ( V_22 , 0 ) + V_90 -> V_18 [ 0 ] . V_103 ;
V_18 = (struct V_85 * ) V_93 ;
V_93 += V_90 -> V_18 [ 0 ] . V_102 ;
V_79 = V_22 -> V_19 + V_95 ;
}
F_61 (pending_req->sgl, sg, nr_segments, i) {
F_62 ( V_97 , V_79 [ V_8 ] , V_18 -> V_102 , V_18 -> V_103 ) ;
V_22 -> V_73 += V_18 -> V_102 ;
V_18 ++ ;
if ( V_95 && ( unsigned long ) V_18 >= V_93 ) {
V_92 ++ ;
V_93 = F_20 ( V_22 , V_92 ) +
V_90 -> V_18 [ V_92 ] . V_103 ;
V_18 = (struct V_85 * ) V_93 ;
V_93 += V_90 -> V_18 [ V_92 ] . V_102 ;
}
if ( V_97 -> V_103 >= V_104 ||
V_97 -> V_102 > V_104 ||
V_97 -> V_103 + V_97 -> V_102 > V_104 )
return - V_100 ;
}
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_64 ( V_2 -> V_4 ,
F_65 ( & V_2 -> V_3 ) == 0 ) ;
F_66 ( V_2 -> V_63 , V_2 ) ;
V_2 -> V_63 = 0 ;
F_67 ( V_2 -> V_108 , V_2 -> V_57 . V_109 ) ;
}
static void F_68 ( struct V_16 * V_22 ,
enum V_110 V_111 , int V_72 )
{
struct V_23 * V_24 = V_22 -> V_25 -> V_24 ;
struct V_112 * V_113 = V_24 -> V_69 ;
struct V_64 * V_64 = & V_22 -> V_64 ;
struct V_114 * V_115 ;
T_6 V_116 = V_22 -> V_25 -> V_28 ;
int V_71 , V_35 = V_117 ;
V_115 = F_69 ( sizeof( struct V_114 ) , V_106 ) ;
if ( ! V_115 ) {
F_46 ( V_64 ) ;
goto V_35;
}
F_70 ( & V_115 -> V_118 ) ;
V_71 = F_71 ( & V_22 -> V_64 , V_113 -> V_70 ,
& V_22 -> V_20 [ 0 ] ,
V_116 , V_115 , V_111 , V_106 ,
V_72 , V_75 ) ;
if ( V_71 )
goto V_35;
F_64 ( V_115 -> V_118 , F_65 ( & V_115 -> V_119 ) ) ;
V_35 = ( V_64 -> V_120 -> V_121 == V_122 ) ?
V_123 : V_117 ;
F_43 ( NULL , V_35 , 0 , V_22 ) ;
F_50 ( & V_22 -> V_64 , 1 ) ;
return;
V_35:
if ( V_115 )
F_28 ( V_115 ) ;
F_43 ( NULL , V_35 , 0 , V_22 ) ;
}
static struct V_43 * F_72 ( struct V_1 * V_2 ,
struct V_124 * V_125 )
{
struct V_43 * V_44 ;
struct V_126 * V_127 = & ( V_2 -> V_128 ) ;
unsigned long V_7 ;
F_9 ( & V_2 -> V_129 , V_7 ) ;
F_73 (entry, head, l) {
if ( ( V_44 -> V_125 . V_130 == V_125 -> V_130 ) &&
( V_44 -> V_125 . V_131 == V_125 -> V_131 ) &&
( V_44 -> V_125 . V_28 == V_125 -> V_28 ) ) {
F_74 ( & V_44 -> V_42 ) ;
goto V_132;
}
}
V_44 = NULL ;
V_132:
F_11 ( & V_2 -> V_129 , V_7 ) ;
return V_44 ;
}
static struct V_16 * F_75 ( struct V_133 * V_57 ,
struct V_43 * V_25 )
{
struct V_23 * V_24 = V_25 -> V_24 ;
struct V_112 * V_113 = V_24 -> V_69 ;
struct V_67 * V_134 = V_113 -> V_70 ;
struct V_16 * V_17 ;
int V_72 , V_8 ;
V_72 = F_76 ( & V_134 -> V_135 , V_136 ) ;
if ( V_72 < 0 ) {
F_22 ( L_6 ) ;
return F_77 ( - V_84 ) ;
}
V_17 = & ( (struct V_16 * ) V_134 -> V_137 ) [ V_72 ] ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
V_17 -> V_64 . V_138 = V_72 ;
for ( V_8 = 0 ; V_8 < V_139 ; V_8 ++ )
V_17 -> V_39 [ V_8 ] = V_40 ;
return V_17 ;
}
static struct V_16 * F_78 ( struct V_1 * V_2 ,
struct V_133 * V_57 ,
struct V_89 * V_90 )
{
struct V_16 * V_22 ;
struct V_43 * V_25 ;
struct V_124 V_140 ;
if ( ( V_90 -> V_74 != V_141 ) &&
( V_90 -> V_74 != V_107 ) &&
( V_90 -> V_74 != V_142 ) &&
( V_90 -> V_74 != V_143 ) ) {
F_58 ( L_7 ,
V_90 -> V_74 ) ;
return F_77 ( - V_100 ) ;
}
if ( V_90 -> V_144 > V_145 ) {
F_58 ( L_8 ,
V_90 -> V_144 ) ;
return F_77 ( - V_100 ) ;
}
V_140 . V_130 = V_90 -> V_146 ;
V_140 . V_131 = V_90 -> V_147 ;
V_140 . V_28 = V_90 -> V_28 ;
V_25 = F_72 ( V_2 , & V_140 ) ;
if ( ! V_25 ) {
F_58 ( L_9 ,
V_140 . V_130 , V_140 . V_131 , V_140 . V_28 ) ;
return F_77 ( - V_148 ) ;
}
V_22 = F_75 ( V_57 , V_25 ) ;
if ( F_79 ( V_22 ) ) {
F_44 ( & V_25 -> V_42 , F_33 ) ;
return F_77 ( - V_84 ) ;
}
V_22 -> V_49 = V_90 -> V_49 ;
V_22 -> V_2 = V_2 ;
V_22 -> V_25 = V_25 ;
V_22 -> V_74 = V_90 -> V_74 ;
V_22 -> V_144 = V_90 -> V_144 ;
memcpy ( V_22 -> V_29 , V_90 -> V_29 , V_22 -> V_144 ) ;
return V_22 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_133 * V_57 = & V_2 -> V_57 ;
struct V_89 V_90 ;
struct V_16 * V_22 ;
T_7 V_71 , V_149 ;
int V_150 ;
T_3 V_47 ;
V_71 = V_57 -> V_151 ;
V_149 = V_57 -> V_109 -> V_152 ;
F_81 () ;
if ( F_82 ( V_57 , V_149 ) ) {
V_71 = V_57 -> V_58 ;
F_83 ( L_10 ,
V_2 -> V_88 , V_149 , V_71 , V_149 - V_71 ) ;
V_2 -> V_153 = 1 ;
return 0 ;
}
while ( ( V_71 != V_149 ) ) {
if ( F_84 ( V_57 , V_71 ) )
break;
F_85 ( V_57 , V_71 , & V_90 ) ;
V_57 -> V_151 = ++ V_71 ;
V_22 = F_78 ( V_2 , V_57 , & V_90 ) ;
if ( F_79 ( V_22 ) ) {
switch ( F_86 ( V_22 ) ) {
case - V_148 :
V_47 = V_154 ;
break;
default:
V_47 = V_155 ;
break;
}
F_37 ( V_2 , NULL , V_47 << 24 , 0 ,
V_90 . V_49 ) ;
return 1 ;
}
switch ( V_90 . V_111 ) {
case V_156 :
if ( F_57 ( & V_90 , V_22 ) ) {
F_27 ( V_22 ) ;
F_43 ( NULL ,
V_155 << 24 , 0 , V_22 ) ;
F_50 ( & V_22 -> V_64 , 0 ) ;
} else {
F_47 ( V_22 ) ;
}
break;
case V_157 :
F_68 ( V_22 , V_158 ,
V_90 . V_159 ) ;
break;
case V_160 :
F_68 ( V_22 , V_161 , 0 ) ;
break;
default:
F_87 ( L_11 ) ;
F_43 ( NULL , V_155 << 24 , 0 ,
V_22 ) ;
F_50 ( & V_22 -> V_64 , 0 ) ;
break;
}
F_88 () ;
}
F_89 ( & V_2 -> V_57 , V_150 ) ;
return V_150 ;
}
static T_8 F_90 ( int V_63 , void * V_162 )
{
struct V_1 * V_2 = V_162 ;
if ( V_2 -> V_153 )
return V_163 ;
while ( F_80 ( V_2 ) )
F_88 () ;
return V_163 ;
}
static int F_91 ( struct V_1 * V_2 , T_9 V_164 ,
T_10 V_165 )
{
void * V_166 ;
struct V_167 * V_109 ;
int V_35 ;
if ( V_2 -> V_63 )
return - 1 ;
V_35 = F_92 ( V_2 -> V_108 , & V_164 , 1 , & V_166 ) ;
if ( V_35 )
return V_35 ;
V_109 = (struct V_167 * ) V_166 ;
F_93 ( & V_2 -> V_57 , V_109 , V_104 ) ;
V_35 = F_94 ( V_2 -> V_88 , V_165 ) ;
if ( V_35 < 0 )
goto V_168;
V_2 -> V_63 = V_35 ;
V_35 = F_95 ( V_2 -> V_63 , NULL , F_90 ,
V_169 , L_12 , V_2 ) ;
if ( V_35 )
goto V_170;
return 0 ;
V_170:
F_66 ( V_2 -> V_63 , V_2 ) ;
V_2 -> V_63 = 0 ;
V_168:
F_67 ( V_2 -> V_108 , V_166 ) ;
return V_35 ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_171 * V_108 = V_2 -> V_108 ;
unsigned int V_164 , V_165 ;
int V_35 ;
V_35 = F_97 ( V_172 , V_108 -> V_173 ,
L_13 , L_14 , & V_164 ,
L_15 , L_14 , & V_165 , NULL ) ;
if ( V_35 ) {
F_98 ( V_108 , V_35 , L_16 , V_108 -> V_173 ) ;
return V_35 ;
}
return F_91 ( V_2 , V_164 , V_165 ) ;
}
static struct V_43 * F_99 (
struct V_1 * V_2 , struct V_124 * V_125 )
{
struct V_126 * V_127 = & ( V_2 -> V_128 ) ;
struct V_43 * V_44 ;
F_73 (entry, head, l)
if ( ( V_44 -> V_125 . V_130 == V_125 -> V_130 ) &&
( V_44 -> V_125 . V_131 == V_125 -> V_131 ) &&
( V_44 -> V_125 . V_28 == V_125 -> V_28 ) )
return V_44 ;
return NULL ;
}
static int F_100 ( struct V_1 * V_2 ,
char * V_174 , struct V_124 * V_125 )
{
int V_35 = 0 ;
struct V_43 * V_175 ;
unsigned long V_7 ;
char * V_176 ;
unsigned long long V_116 ;
struct V_177 * V_177 ;
struct V_23 * V_178 , * V_24 = NULL ;
char * error = L_17 ;
V_176 = strrchr ( V_174 , ':' ) ;
if ( ! V_176 ) {
F_22 ( L_18 , V_174 ) ;
return - V_100 ;
}
* V_176 = 0 ;
V_176 ++ ;
V_35 = F_101 ( V_176 , 10 , & V_116 ) ;
if ( V_35 < 0 ) {
F_22 ( L_19 , V_176 ) ;
return V_35 ;
}
F_35 ( & V_179 ) ;
F_73 (tpg_entry, &scsiback_list, tv_tpg_list) {
if ( ! strcmp ( V_174 , V_178 -> V_26 -> V_27 ) ||
! strcmp ( V_174 , V_178 -> V_180 ) ) {
F_35 ( & V_178 -> V_181 . V_182 ) ;
F_102 (se_lun, &tpg_entry->se_tpg.tpg_lun_hlist, link) {
if ( V_177 -> V_116 == V_116 ) {
if ( ! V_178 -> V_69 )
error = L_20 ;
else
V_24 = V_178 ;
break;
}
}
F_36 ( & V_178 -> V_181 . V_182 ) ;
break;
}
}
if ( V_24 ) {
F_35 ( & V_24 -> V_45 ) ;
V_24 -> V_46 ++ ;
F_36 ( & V_24 -> V_45 ) ;
}
F_36 ( & V_179 ) ;
if ( ! V_24 ) {
F_22 ( L_21 , V_174 , V_116 , error ) ;
return - V_148 ;
}
V_175 = F_103 ( sizeof( struct V_43 ) , V_106 ) ;
if ( V_175 == NULL ) {
V_35 = - V_84 ;
goto V_183;
}
F_9 ( & V_2 -> V_129 , V_7 ) ;
if ( F_99 ( V_2 , V_125 ) ) {
F_83 ( L_22 ) ;
V_35 = - V_184 ;
goto V_132;
}
F_104 ( & V_175 -> V_42 ) ;
V_175 -> V_125 = * V_125 ;
V_175 -> V_24 = V_24 ;
V_175 -> V_28 = V_116 ;
F_105 ( & V_175 -> V_185 , & V_2 -> V_128 ) ;
V_132:
F_11 ( & V_2 -> V_129 , V_7 ) ;
V_183:
if ( V_35 ) {
F_35 ( & V_24 -> V_45 ) ;
V_24 -> V_46 -- ;
F_36 ( & V_24 -> V_45 ) ;
F_28 ( V_175 ) ;
}
return V_35 ;
}
static void F_106 ( struct V_43 * V_44 )
{
F_16 ( & V_44 -> V_185 ) ;
F_44 ( & V_44 -> V_42 , F_33 ) ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_124 * V_125 )
{
struct V_43 * V_44 ;
unsigned long V_7 ;
int V_186 = 0 ;
F_9 ( & V_2 -> V_129 , V_7 ) ;
V_44 = F_99 ( V_2 , V_125 ) ;
if ( V_44 )
F_106 ( V_44 ) ;
else
V_186 = - V_187 ;
F_11 ( & V_2 -> V_129 , V_7 ) ;
return V_186 ;
}
static void F_108 ( struct V_1 * V_2 , const char * V_188 ,
char * V_174 , struct V_124 * V_140 , int V_189 )
{
struct V_43 * V_44 ;
unsigned long V_7 ;
if ( V_189 ) {
F_9 ( & V_2 -> V_129 , V_7 ) ;
V_44 = F_99 ( V_2 , V_140 ) ;
F_11 ( & V_2 -> V_129 , V_7 ) ;
if ( V_44 )
return;
}
if ( ! F_100 ( V_2 , V_174 , V_140 ) ) {
if ( F_109 ( V_172 , V_2 -> V_108 -> V_190 , V_188 ,
L_23 , V_191 ) ) {
F_22 ( L_24 , V_188 ) ;
F_107 ( V_2 , V_140 ) ;
}
} else if ( ! V_189 ) {
F_109 ( V_172 , V_2 -> V_108 -> V_190 , V_188 ,
L_23 , V_192 ) ;
}
}
static void F_110 ( struct V_1 * V_2 , const char * V_188 ,
struct V_124 * V_140 )
{
if ( ! F_107 ( V_2 , V_140 ) ) {
if ( F_109 ( V_172 , V_2 -> V_108 -> V_190 , V_188 ,
L_23 , V_192 ) )
F_22 ( L_24 , V_188 ) ;
}
}
static void F_111 ( struct V_1 * V_2 , int V_193 ,
char * V_194 )
{
int V_35 ;
struct V_124 V_140 ;
char * V_195 ;
int V_196 ;
char V_174 [ V_197 ] ;
char V_198 [ 64 ] ;
char V_188 [ 64 ] ;
struct V_171 * V_108 = V_2 -> V_108 ;
snprintf ( V_188 , sizeof( V_188 ) , L_25 , V_194 ) ;
V_35 = F_112 ( V_172 , V_108 -> V_190 , V_188 , L_14 , & V_196 ) ;
if ( F_113 ( V_35 ) )
return;
snprintf ( V_198 , sizeof( V_198 ) , L_26 , V_194 ) ;
V_195 = F_114 ( V_172 , V_108 -> V_190 , V_198 , NULL ) ;
if ( F_79 ( V_195 ) ) {
F_109 ( V_172 , V_108 -> V_190 , V_188 ,
L_23 , V_192 ) ;
return;
}
F_115 ( V_174 , V_195 , V_197 ) ;
F_28 ( V_195 ) ;
snprintf ( V_198 , sizeof( V_198 ) , L_27 , V_194 ) ;
V_35 = F_112 ( V_172 , V_108 -> V_190 , V_198 , L_28 ,
& V_140 . V_199 , & V_140 . V_130 , & V_140 . V_131 , & V_140 . V_28 ) ;
if ( F_113 ( V_35 ) ) {
F_109 ( V_172 , V_108 -> V_190 , V_188 ,
L_23 , V_192 ) ;
return;
}
switch ( V_193 ) {
case V_200 :
switch ( V_196 ) {
case V_201 :
F_108 ( V_2 , V_188 , V_174 , & V_140 , 0 ) ;
break;
case V_202 :
F_108 ( V_2 , V_188 , V_174 , & V_140 , 1 ) ;
break;
case V_203 :
F_110 ( V_2 , V_188 , & V_140 ) ;
break;
default:
break;
}
break;
case V_204 :
if ( V_196 == V_191 ) {
if ( F_109 ( V_172 , V_108 -> V_190 , V_188 ,
L_23 , V_202 ) ) {
F_22 ( L_24 , V_198 ) ;
F_107 ( V_2 , & V_140 ) ;
F_109 ( V_172 , V_108 -> V_190 , V_188 ,
L_23 , V_192 ) ;
}
}
break;
default:
break;
}
}
static void F_116 ( struct V_1 * V_2 , int V_193 )
{
int V_8 ;
char * * V_205 ;
unsigned int V_206 = 0 ;
V_205 = F_117 ( V_172 , V_2 -> V_108 -> V_190 , L_29 ,
& V_206 ) ;
if ( F_79 ( V_205 ) )
return;
for ( V_8 = 0 ; V_8 < V_206 ; V_8 ++ )
F_111 ( V_2 , V_193 , V_205 [ V_8 ] ) ;
F_28 ( V_205 ) ;
}
static void F_118 ( struct V_171 * V_108 ,
enum V_207 V_208 )
{
struct V_1 * V_2 = F_119 ( & V_108 -> V_108 ) ;
switch ( V_208 ) {
case V_201 :
break;
case V_191 :
if ( F_96 ( V_2 ) )
break;
F_116 ( V_2 , V_200 ) ;
F_120 ( V_108 , V_202 ) ;
break;
case V_202 :
F_116 ( V_2 , V_204 ) ;
if ( V_108 -> V_188 == V_202 )
break;
F_120 ( V_108 , V_202 ) ;
break;
case V_203 :
if ( V_2 -> V_63 )
F_63 ( V_2 ) ;
F_120 ( V_108 , V_203 ) ;
break;
case V_192 :
F_120 ( V_108 , V_192 ) ;
if ( F_121 ( V_108 ) )
break;
case V_209 :
F_122 ( & V_108 -> V_108 ) ;
break;
case V_210 :
F_116 ( V_2 , V_200 ) ;
F_120 ( V_108 , V_211 ) ;
break;
default:
F_98 ( V_108 , - V_100 , L_30 ,
V_208 ) ;
break;
}
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_43 * V_44 , * V_212 ;
struct V_126 * V_127 = & ( V_2 -> V_128 ) ;
unsigned long V_7 ;
F_9 ( & V_2 -> V_129 , V_7 ) ;
F_124 (entry, tmp, head, l)
F_106 ( V_44 ) ;
F_11 ( & V_2 -> V_129 , V_7 ) ;
}
static int F_125 ( struct V_171 * V_108 )
{
struct V_1 * V_2 = F_119 ( & V_108 -> V_108 ) ;
if ( V_2 -> V_63 )
F_63 ( V_2 ) ;
F_123 ( V_2 ) ;
F_126 ( & V_108 -> V_108 , NULL ) ;
return 0 ;
}
static int F_127 ( struct V_171 * V_108 ,
const struct V_213 * V_147 )
{
int V_35 ;
struct V_1 * V_2 = F_69 ( sizeof( struct V_1 ) ,
V_106 ) ;
F_58 ( L_31 , V_214 , V_108 , V_108 -> V_215 ) ;
if ( ! V_2 ) {
F_98 ( V_108 , - V_84 , L_32 ) ;
return - V_84 ;
}
V_2 -> V_108 = V_108 ;
F_126 ( & V_108 -> V_108 , V_2 ) ;
V_2 -> V_88 = V_108 -> V_215 ;
F_128 ( & V_2 -> V_56 ) ;
V_2 -> V_153 = 0 ;
F_129 ( & V_2 -> V_3 , 0 ) ;
F_70 ( & V_2 -> V_4 ) ;
V_2 -> V_108 = V_108 ;
V_2 -> V_63 = 0 ;
F_130 ( & V_2 -> V_128 ) ;
F_128 ( & V_2 -> V_129 ) ;
V_35 = F_109 ( V_172 , V_108 -> V_190 , L_33 , L_14 ,
V_105 ) ;
if ( V_35 )
F_131 ( V_108 , V_35 , L_34 ) ;
V_35 = F_120 ( V_108 , V_216 ) ;
if ( V_35 )
goto V_217;
return 0 ;
V_217:
F_83 ( L_35 , V_214 ) ;
F_125 ( V_108 ) ;
return V_35 ;
}
static char * F_132 ( struct V_218 * V_26 )
{
switch ( V_26 -> V_219 ) {
case V_220 :
return L_36 ;
case V_221 :
return L_37 ;
case V_222 :
return L_38 ;
default:
break;
}
return L_39 ;
}
static char * F_133 ( struct V_223 * V_181 )
{
struct V_23 * V_24 = F_34 ( V_181 ,
struct V_23 , V_181 ) ;
struct V_218 * V_26 = V_24 -> V_26 ;
return & V_26 -> V_27 [ 0 ] ;
}
static T_11 F_134 ( struct V_223 * V_181 )
{
struct V_23 * V_24 = F_34 ( V_181 ,
struct V_23 , V_181 ) ;
return V_24 -> V_224 ;
}
static struct V_225 *
F_135 ( struct V_226 * V_227 ,
struct V_228 * V_229 ,
const char * V_230 )
{
struct V_218 * V_26 ;
char * V_231 ;
T_6 V_232 = 0 ;
int V_233 = 0 ;
V_26 = F_69 ( sizeof( struct V_218 ) , V_106 ) ;
if ( ! V_26 )
return F_77 ( - V_84 ) ;
V_26 -> V_234 = V_232 ;
V_231 = strstr ( V_230 , L_40 ) ;
if ( V_231 ) {
V_26 -> V_219 = V_220 ;
goto V_235;
}
V_231 = strstr ( V_230 , L_41 ) ;
if ( V_231 ) {
V_26 -> V_219 = V_221 ;
V_233 = 3 ;
goto V_235;
}
V_231 = strstr ( V_230 , L_42 ) ;
if ( V_231 ) {
V_26 -> V_219 = V_222 ;
goto V_235;
}
F_22 ( L_43 , V_230 ) ;
F_28 ( V_26 ) ;
return F_77 ( - V_100 ) ;
V_235:
if ( strlen ( V_230 ) >= V_197 ) {
F_22 ( L_44 , V_230 ,
F_132 ( V_26 ) , V_197 ) ;
F_28 ( V_26 ) ;
return F_77 ( - V_100 ) ;
}
snprintf ( & V_26 -> V_27 [ 0 ] , V_197 , L_45 , & V_230 [ V_233 ] ) ;
F_58 ( L_46 ,
F_132 ( V_26 ) , V_230 ) ;
return & V_26 -> V_236 ;
}
static void F_136 ( struct V_225 * V_237 )
{
struct V_218 * V_26 = F_34 ( V_237 ,
struct V_218 , V_236 ) ;
F_58 ( L_47 ,
F_132 ( V_26 ) , V_26 -> V_27 ) ;
F_28 ( V_26 ) ;
}
static T_5 F_137 ( struct V_223 * V_181 )
{
return 1 ;
}
static int F_138 ( struct V_64 * V_64 )
{
return F_50 ( V_64 , 0 ) ;
}
static void F_139 ( struct V_64 * V_64 )
{
struct V_67 * V_134 = V_64 -> V_134 ;
struct V_120 * V_238 = V_64 -> V_120 ;
if ( V_238 && V_64 -> V_239 & V_240 ) {
struct V_114 * V_115 = V_238 -> V_241 ;
F_28 ( V_115 ) ;
}
F_140 ( & V_134 -> V_135 , V_64 -> V_138 ) ;
}
static T_5 F_141 ( struct V_67 * V_134 )
{
return 0 ;
}
static int F_142 ( struct V_64 * V_64 )
{
F_143 ( V_64 ) ;
return 0 ;
}
static int F_144 ( struct V_64 * V_64 )
{
return 0 ;
}
static void F_145 ( struct V_242 * V_243 )
{
}
static int F_146 ( struct V_64 * V_64 )
{
return 0 ;
}
static int F_147 ( struct V_64 * V_64 )
{
struct V_16 * V_22 = F_34 ( V_64 ,
struct V_16 , V_64 ) ;
V_22 -> V_47 = V_244 ;
F_45 ( V_22 ) ;
return 0 ;
}
static int F_148 ( struct V_64 * V_64 )
{
struct V_16 * V_22 = F_34 ( V_64 ,
struct V_16 , V_64 ) ;
if ( V_64 -> V_20 &&
( ( V_64 -> V_239 & V_245 ) ||
( V_64 -> V_239 & V_246 ) ) )
V_22 -> V_47 = ( V_247 << 24 ) |
V_248 ;
else
V_22 -> V_47 = V_64 -> V_249 ;
F_45 ( V_22 ) ;
return 0 ;
}
static void F_149 ( struct V_64 * V_64 )
{
struct V_120 * V_238 = V_64 -> V_120 ;
struct V_114 * V_115 = V_238 -> V_241 ;
F_129 ( & V_115 -> V_119 , 1 ) ;
F_5 ( & V_115 -> V_118 ) ;
}
static void F_150 ( struct V_64 * V_64 )
{
}
static T_12 F_151 ( struct V_250 * V_251 ,
char * V_5 )
{
struct V_223 * V_181 = F_152 ( V_251 ) ;
struct V_23 * V_24 = F_34 ( V_181 , struct V_23 ,
V_181 ) ;
T_12 V_252 ;
F_35 ( & V_24 -> V_45 ) ;
V_252 = snprintf ( V_5 , V_104 , L_48 , V_24 -> V_180 ) ;
F_36 ( & V_24 -> V_45 ) ;
return V_252 ;
}
static T_12 F_153 ( struct V_250 * V_251 ,
const char * V_5 , T_13 V_253 )
{
struct V_223 * V_181 = F_152 ( V_251 ) ;
struct V_23 * V_24 = F_34 ( V_181 , struct V_23 ,
V_181 ) ;
int V_55 ;
if ( strlen ( V_5 ) >= V_197 ) {
F_22 ( L_49 , V_5 ,
V_197 ) ;
return - V_100 ;
}
F_35 ( & V_24 -> V_45 ) ;
V_55 = snprintf ( V_24 -> V_180 , V_197 , L_45 , V_5 ) ;
if ( V_24 -> V_180 [ V_55 - 1 ] == '\n' )
V_24 -> V_180 [ V_55 - 1 ] = '\0' ;
F_36 ( & V_24 -> V_45 ) ;
return V_253 ;
}
static int F_154 ( struct V_223 * V_181 ,
struct V_67 * V_134 , void * V_254 )
{
struct V_23 * V_24 = F_34 ( V_181 ,
struct V_23 , V_181 ) ;
V_24 -> V_69 = V_254 ;
return 0 ;
}
static int F_155 ( struct V_23 * V_24 ,
const char * V_230 )
{
struct V_112 * V_255 ;
int V_186 = 0 ;
F_35 ( & V_24 -> V_45 ) ;
if ( V_24 -> V_69 ) {
F_58 ( L_50 ) ;
V_186 = - V_184 ;
goto V_256;
}
V_255 = F_69 ( sizeof( struct V_112 ) , V_106 ) ;
if ( ! V_255 ) {
V_186 = - V_84 ;
goto V_256;
}
V_255 -> V_70 = F_156 ( & V_24 -> V_181 ,
V_257 ,
sizeof( struct V_16 ) ,
V_258 , V_230 ,
V_255 , F_154 ) ;
if ( F_79 ( V_255 -> V_70 ) ) {
F_28 ( V_255 ) ;
V_186 = - V_84 ;
goto V_256;
}
V_256:
F_36 ( & V_24 -> V_45 ) ;
return V_186 ;
}
static int F_157 ( struct V_23 * V_24 )
{
struct V_67 * V_134 ;
struct V_112 * V_255 ;
F_35 ( & V_24 -> V_45 ) ;
V_255 = V_24 -> V_69 ;
if ( ! V_255 ) {
F_36 ( & V_24 -> V_45 ) ;
return - V_148 ;
}
V_134 = V_255 -> V_70 ;
if ( ! V_134 ) {
F_36 ( & V_24 -> V_45 ) ;
return - V_148 ;
}
if ( V_24 -> V_259 != 0 ) {
F_36 ( & V_24 -> V_45 ) ;
F_22 ( L_51 ,
V_24 -> V_259 ) ;
return - V_260 ;
}
if ( V_24 -> V_46 != 0 ) {
F_36 ( & V_24 -> V_45 ) ;
F_22 ( L_52 ,
V_24 -> V_46 ) ;
return - V_260 ;
}
F_58 ( L_53 ,
F_132 ( V_24 -> V_26 ) ,
V_255 -> V_70 -> V_242 -> V_261 ) ;
F_158 ( V_255 -> V_70 ) ;
V_24 -> V_69 = NULL ;
F_36 ( & V_24 -> V_45 ) ;
F_28 ( V_255 ) ;
return 0 ;
}
static T_12 F_159 ( struct V_250 * V_251 , char * V_5 )
{
struct V_223 * V_181 = F_160 ( V_251 ) ;
struct V_23 * V_24 = F_34 ( V_181 ,
struct V_23 , V_181 ) ;
struct V_112 * V_255 ;
T_12 V_186 ;
F_35 ( & V_24 -> V_45 ) ;
V_255 = V_24 -> V_69 ;
if ( ! V_255 ) {
F_36 ( & V_24 -> V_45 ) ;
return - V_148 ;
}
V_186 = snprintf ( V_5 , V_104 , L_48 ,
V_255 -> V_70 -> V_242 -> V_261 ) ;
F_36 ( & V_24 -> V_45 ) ;
return V_186 ;
}
static T_12 F_161 ( struct V_250 * V_251 ,
const char * V_5 , T_13 V_253 )
{
struct V_223 * V_181 = F_160 ( V_251 ) ;
struct V_23 * V_24 = F_34 ( V_181 ,
struct V_23 , V_181 ) ;
struct V_218 * V_236 = V_24 -> V_26 ;
unsigned char V_262 [ V_197 ] , * V_231 , * V_263 ;
int V_186 ;
if ( ! strncmp ( V_5 , L_54 , 4 ) ) {
V_186 = F_157 ( V_24 ) ;
return ( ! V_186 ) ? V_253 : V_186 ;
}
if ( strlen ( V_5 ) >= V_197 ) {
F_22 ( L_55 ,
V_5 , V_197 ) ;
return - V_100 ;
}
snprintf ( & V_262 [ 0 ] , V_197 , L_45 , V_5 ) ;
V_231 = strstr ( V_262 , L_40 ) ;
if ( V_231 ) {
if ( V_236 -> V_219 != V_220 ) {
F_22 ( L_56 ,
V_262 , F_132 ( V_236 ) ) ;
return - V_100 ;
}
V_263 = & V_262 [ 0 ] ;
goto V_264;
}
V_231 = strstr ( V_262 , L_41 ) ;
if ( V_231 ) {
if ( V_236 -> V_219 != V_221 ) {
F_22 ( L_57 ,
V_262 , F_132 ( V_236 ) ) ;
return - V_100 ;
}
V_263 = & V_262 [ 3 ] ;
goto V_264;
}
V_231 = strstr ( V_262 , L_42 ) ;
if ( V_231 ) {
if ( V_236 -> V_219 != V_222 ) {
F_22 ( L_58 ,
V_262 , F_132 ( V_236 ) ) ;
return - V_100 ;
}
V_263 = & V_262 [ 0 ] ;
goto V_264;
}
F_22 ( L_59 ,
V_262 ) ;
return - V_100 ;
V_264:
if ( V_262 [ strlen ( V_262 ) - 1 ] == '\n' )
V_262 [ strlen ( V_262 ) - 1 ] = '\0' ;
V_186 = F_155 ( V_24 , V_263 ) ;
if ( V_186 < 0 )
return V_186 ;
return V_253 ;
}
static T_12
F_162 ( struct V_250 * V_251 , char * V_5 )
{
return sprintf ( V_5 , L_60
V_265 L_61 ,
V_266 , F_163 () -> V_267 , F_163 () -> V_268 ) ;
}
static char * F_164 ( void )
{
return L_62 ;
}
static int F_165 ( struct V_223 * V_181 ,
struct V_177 * V_28 )
{
struct V_23 * V_24 = F_34 ( V_181 ,
struct V_23 , V_181 ) ;
F_35 ( & V_24 -> V_45 ) ;
V_24 -> V_259 ++ ;
F_36 ( & V_24 -> V_45 ) ;
return 0 ;
}
static void F_166 ( struct V_223 * V_181 ,
struct V_177 * V_28 )
{
struct V_23 * V_24 = F_34 ( V_181 ,
struct V_23 , V_181 ) ;
F_35 ( & V_24 -> V_45 ) ;
V_24 -> V_259 -- ;
F_36 ( & V_24 -> V_45 ) ;
}
static struct V_223 *
F_167 ( struct V_225 * V_237 ,
struct V_228 * V_229 ,
const char * V_230 )
{
struct V_218 * V_26 = F_34 ( V_237 ,
struct V_218 , V_236 ) ;
struct V_23 * V_24 ;
T_11 V_269 ;
int V_186 ;
if ( strstr ( V_230 , L_63 ) != V_230 )
return F_77 ( - V_100 ) ;
V_186 = F_168 ( V_230 + 5 , 10 , & V_269 ) ;
if ( V_186 )
return F_77 ( V_186 ) ;
V_24 = F_69 ( sizeof( struct V_23 ) , V_106 ) ;
if ( ! V_24 )
return F_77 ( - V_84 ) ;
F_169 ( & V_24 -> V_45 ) ;
F_130 ( & V_24 -> V_270 ) ;
F_130 ( & V_24 -> V_271 ) ;
V_24 -> V_26 = V_26 ;
V_24 -> V_224 = V_269 ;
V_186 = F_170 ( V_237 , & V_24 -> V_181 , V_26 -> V_219 ) ;
if ( V_186 < 0 ) {
F_28 ( V_24 ) ;
return NULL ;
}
F_35 ( & V_179 ) ;
F_105 ( & V_24 -> V_270 , & V_272 ) ;
F_36 ( & V_179 ) ;
return & V_24 -> V_181 ;
}
static void F_171 ( struct V_223 * V_181 )
{
struct V_23 * V_24 = F_34 ( V_181 ,
struct V_23 , V_181 ) ;
F_35 ( & V_179 ) ;
F_16 ( & V_24 -> V_270 ) ;
F_36 ( & V_179 ) ;
F_157 ( V_24 ) ;
F_172 ( V_181 ) ;
F_28 ( V_24 ) ;
}
static int F_173 ( struct V_223 * V_181 )
{
return 1 ;
}
static int F_174 ( struct V_223 * V_181 )
{
return 0 ;
}
static int T_14 F_175 ( void )
{
int V_186 ;
if ( ! F_176 () )
return - V_148 ;
F_58 ( L_64 V_265 L_61 ,
V_266 , F_163 () -> V_267 , F_163 () -> V_268 ) ;
V_186 = F_177 ( & V_273 ) ;
if ( V_186 )
goto V_132;
V_186 = F_178 ( & V_274 ) ;
if ( V_186 )
goto V_275;
return 0 ;
V_275:
F_179 ( & V_273 ) ;
V_132:
F_22 ( L_65 , V_214 , V_186 ) ;
return V_186 ;
}
static void T_15 F_180 ( void )
{
struct V_5 * V_5 ;
while ( V_9 ) {
if ( F_12 ( & V_5 ) )
F_181 () ;
F_8 ( 1 , & V_5 ) ;
}
F_182 ( & V_274 ) ;
F_179 ( & V_273 ) ;
}
