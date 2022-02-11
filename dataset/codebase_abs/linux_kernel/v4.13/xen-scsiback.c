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
T_6 V_114 = V_22 -> V_25 -> V_28 ;
int V_71 , V_35 = V_115 ;
F_69 ( & V_22 -> V_116 ) ;
V_71 = F_70 ( & V_22 -> V_64 , V_113 -> V_70 ,
& V_22 -> V_20 [ 0 ] ,
V_114 , NULL , V_111 , V_106 ,
V_72 , V_75 ) ;
if ( V_71 )
goto V_35;
F_71 ( & V_22 -> V_116 ) ;
V_35 = ( V_64 -> V_117 -> V_118 == V_119 ) ?
V_120 : V_115 ;
F_43 ( NULL , V_35 , 0 , V_22 ) ;
F_50 ( & V_22 -> V_64 , 0 ) ;
return;
V_35:
F_43 ( NULL , V_35 , 0 , V_22 ) ;
}
static struct V_43 * F_72 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
struct V_43 * V_44 ;
struct V_123 * V_124 = & ( V_2 -> V_125 ) ;
unsigned long V_7 ;
F_9 ( & V_2 -> V_126 , V_7 ) ;
F_73 (entry, head, l) {
if ( ( V_44 -> V_122 . V_127 == V_122 -> V_127 ) &&
( V_44 -> V_122 . V_128 == V_122 -> V_128 ) &&
( V_44 -> V_122 . V_28 == V_122 -> V_28 ) ) {
F_74 ( & V_44 -> V_42 ) ;
goto V_129;
}
}
V_44 = NULL ;
V_129:
F_11 ( & V_2 -> V_126 , V_7 ) ;
return V_44 ;
}
static struct V_16 * F_75 ( struct V_130 * V_57 ,
struct V_43 * V_25 )
{
struct V_23 * V_24 = V_25 -> V_24 ;
struct V_112 * V_113 = V_24 -> V_69 ;
struct V_67 * V_131 = V_113 -> V_70 ;
struct V_16 * V_17 ;
int V_72 , V_8 ;
V_72 = F_76 ( & V_131 -> V_132 , V_133 ) ;
if ( V_72 < 0 ) {
F_22 ( L_6 ) ;
return F_77 ( - V_84 ) ;
}
V_17 = & ( (struct V_16 * ) V_131 -> V_134 ) [ V_72 ] ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
V_17 -> V_64 . V_135 = V_72 ;
for ( V_8 = 0 ; V_8 < V_136 ; V_8 ++ )
V_17 -> V_39 [ V_8 ] = V_40 ;
return V_17 ;
}
static struct V_16 * F_78 ( struct V_1 * V_2 ,
struct V_130 * V_57 ,
struct V_89 * V_90 )
{
struct V_16 * V_22 ;
struct V_43 * V_25 ;
struct V_121 V_137 ;
if ( ( V_90 -> V_74 != V_138 ) &&
( V_90 -> V_74 != V_107 ) &&
( V_90 -> V_74 != V_139 ) &&
( V_90 -> V_74 != V_140 ) ) {
F_58 ( L_7 ,
V_90 -> V_74 ) ;
return F_77 ( - V_100 ) ;
}
if ( V_90 -> V_141 > V_142 ) {
F_58 ( L_8 ,
V_90 -> V_141 ) ;
return F_77 ( - V_100 ) ;
}
V_137 . V_127 = V_90 -> V_143 ;
V_137 . V_128 = V_90 -> V_144 ;
V_137 . V_28 = V_90 -> V_28 ;
V_25 = F_72 ( V_2 , & V_137 ) ;
if ( ! V_25 ) {
F_58 ( L_9 ,
V_137 . V_127 , V_137 . V_128 , V_137 . V_28 ) ;
return F_77 ( - V_145 ) ;
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
V_22 -> V_141 = V_90 -> V_141 ;
memcpy ( V_22 -> V_29 , V_90 -> V_29 , V_22 -> V_141 ) ;
return V_22 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_130 * V_57 = & V_2 -> V_57 ;
struct V_89 V_90 ;
struct V_16 * V_22 ;
T_7 V_71 , V_146 ;
int V_147 ;
T_3 V_47 ;
V_71 = V_57 -> V_148 ;
V_146 = V_57 -> V_109 -> V_149 ;
F_81 () ;
if ( F_82 ( V_57 , V_146 ) ) {
V_71 = V_57 -> V_58 ;
F_83 ( L_10 ,
V_2 -> V_88 , V_146 , V_71 , V_146 - V_71 ) ;
V_2 -> V_150 = 1 ;
return 0 ;
}
while ( ( V_71 != V_146 ) ) {
if ( F_84 ( V_57 , V_71 ) )
break;
F_85 ( V_57 , V_71 , & V_90 ) ;
V_57 -> V_148 = ++ V_71 ;
V_22 = F_78 ( V_2 , V_57 , & V_90 ) ;
if ( F_79 ( V_22 ) ) {
switch ( F_86 ( V_22 ) ) {
case - V_145 :
V_47 = V_151 ;
break;
default:
V_47 = V_152 ;
break;
}
F_37 ( V_2 , NULL , V_47 << 24 , 0 ,
V_90 . V_49 ) ;
return 1 ;
}
switch ( V_90 . V_111 ) {
case V_153 :
if ( F_57 ( & V_90 , V_22 ) ) {
F_27 ( V_22 ) ;
F_43 ( NULL ,
V_152 << 24 , 0 , V_22 ) ;
F_50 ( & V_22 -> V_64 , 0 ) ;
} else {
F_47 ( V_22 ) ;
}
break;
case V_154 :
F_68 ( V_22 , V_155 ,
V_90 . V_156 ) ;
break;
case V_157 :
F_68 ( V_22 , V_158 , 0 ) ;
break;
default:
F_87 ( L_11 ) ;
F_43 ( NULL , V_152 << 24 , 0 ,
V_22 ) ;
F_50 ( & V_22 -> V_64 , 0 ) ;
break;
}
F_88 () ;
}
F_89 ( & V_2 -> V_57 , V_147 ) ;
return V_147 ;
}
static T_8 F_90 ( int V_63 , void * V_159 )
{
struct V_1 * V_2 = V_159 ;
if ( V_2 -> V_150 )
return V_160 ;
while ( F_80 ( V_2 ) )
F_88 () ;
return V_160 ;
}
static int F_91 ( struct V_1 * V_2 , T_9 V_161 ,
T_10 V_162 )
{
void * V_163 ;
struct V_164 * V_109 ;
int V_35 ;
if ( V_2 -> V_63 )
return - 1 ;
V_35 = F_92 ( V_2 -> V_108 , & V_161 , 1 , & V_163 ) ;
if ( V_35 )
return V_35 ;
V_109 = (struct V_164 * ) V_163 ;
F_93 ( & V_2 -> V_57 , V_109 , V_104 ) ;
V_35 = F_94 ( V_2 -> V_88 , V_162 ) ;
if ( V_35 < 0 )
goto V_165;
V_2 -> V_63 = V_35 ;
V_35 = F_95 ( V_2 -> V_63 , NULL , F_90 ,
V_166 , L_12 , V_2 ) ;
if ( V_35 )
goto V_167;
return 0 ;
V_167:
F_66 ( V_2 -> V_63 , V_2 ) ;
V_2 -> V_63 = 0 ;
V_165:
F_67 ( V_2 -> V_108 , V_163 ) ;
return V_35 ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_168 * V_108 = V_2 -> V_108 ;
unsigned int V_161 , V_162 ;
int V_35 ;
V_35 = F_97 ( V_169 , V_108 -> V_170 ,
L_13 , L_14 , & V_161 ,
L_15 , L_14 , & V_162 , NULL ) ;
if ( V_35 ) {
F_98 ( V_108 , V_35 , L_16 , V_108 -> V_170 ) ;
return V_35 ;
}
return F_91 ( V_2 , V_161 , V_162 ) ;
}
static struct V_43 * F_99 (
struct V_1 * V_2 , struct V_121 * V_122 )
{
struct V_123 * V_124 = & ( V_2 -> V_125 ) ;
struct V_43 * V_44 ;
F_73 (entry, head, l)
if ( ( V_44 -> V_122 . V_127 == V_122 -> V_127 ) &&
( V_44 -> V_122 . V_128 == V_122 -> V_128 ) &&
( V_44 -> V_122 . V_28 == V_122 -> V_28 ) )
return V_44 ;
return NULL ;
}
static int F_100 ( struct V_1 * V_2 ,
char * V_171 , struct V_121 * V_122 )
{
int V_35 = 0 ;
struct V_43 * V_172 ;
unsigned long V_7 ;
char * V_173 ;
unsigned long long V_114 ;
struct V_174 * V_174 ;
struct V_23 * V_175 , * V_24 = NULL ;
char * error = L_17 ;
V_173 = strrchr ( V_171 , ':' ) ;
if ( ! V_173 ) {
F_22 ( L_18 , V_171 ) ;
return - V_100 ;
}
* V_173 = 0 ;
V_173 ++ ;
V_35 = F_101 ( V_173 , 10 , & V_114 ) ;
if ( V_35 < 0 ) {
F_22 ( L_19 , V_173 ) ;
return V_35 ;
}
F_35 ( & V_176 ) ;
F_73 (tpg_entry, &scsiback_list, tv_tpg_list) {
if ( ! strcmp ( V_171 , V_175 -> V_26 -> V_27 ) ||
! strcmp ( V_171 , V_175 -> V_177 ) ) {
F_35 ( & V_175 -> V_178 . V_179 ) ;
F_102 (se_lun, &tpg_entry->se_tpg.tpg_lun_hlist, link) {
if ( V_174 -> V_114 == V_114 ) {
if ( ! V_175 -> V_69 )
error = L_20 ;
else
V_24 = V_175 ;
break;
}
}
F_36 ( & V_175 -> V_178 . V_179 ) ;
break;
}
}
if ( V_24 ) {
F_35 ( & V_24 -> V_45 ) ;
V_24 -> V_46 ++ ;
F_36 ( & V_24 -> V_45 ) ;
}
F_36 ( & V_176 ) ;
if ( ! V_24 ) {
F_22 ( L_21 , V_171 , V_114 , error ) ;
return - V_145 ;
}
V_172 = F_103 ( sizeof( struct V_43 ) , V_106 ) ;
if ( V_172 == NULL ) {
V_35 = - V_84 ;
goto V_180;
}
F_9 ( & V_2 -> V_126 , V_7 ) ;
if ( F_99 ( V_2 , V_122 ) ) {
F_83 ( L_22 ) ;
V_35 = - V_181 ;
goto V_129;
}
F_104 ( & V_172 -> V_42 ) ;
V_172 -> V_122 = * V_122 ;
V_172 -> V_24 = V_24 ;
V_172 -> V_28 = V_114 ;
F_105 ( & V_172 -> V_182 , & V_2 -> V_125 ) ;
V_129:
F_11 ( & V_2 -> V_126 , V_7 ) ;
V_180:
if ( V_35 ) {
F_35 ( & V_24 -> V_45 ) ;
V_24 -> V_46 -- ;
F_36 ( & V_24 -> V_45 ) ;
F_28 ( V_172 ) ;
}
return V_35 ;
}
static void F_106 ( struct V_43 * V_44 )
{
F_16 ( & V_44 -> V_182 ) ;
F_44 ( & V_44 -> V_42 , F_33 ) ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
struct V_43 * V_44 ;
unsigned long V_7 ;
int V_183 = 0 ;
F_9 ( & V_2 -> V_126 , V_7 ) ;
V_44 = F_99 ( V_2 , V_122 ) ;
if ( V_44 )
F_106 ( V_44 ) ;
else
V_183 = - V_184 ;
F_11 ( & V_2 -> V_126 , V_7 ) ;
return V_183 ;
}
static void F_108 ( struct V_1 * V_2 , const char * V_185 ,
char * V_171 , struct V_121 * V_137 , int V_186 )
{
struct V_43 * V_44 ;
unsigned long V_7 ;
if ( V_186 ) {
F_9 ( & V_2 -> V_126 , V_7 ) ;
V_44 = F_99 ( V_2 , V_137 ) ;
F_11 ( & V_2 -> V_126 , V_7 ) ;
if ( V_44 )
return;
}
if ( ! F_100 ( V_2 , V_171 , V_137 ) ) {
if ( F_109 ( V_169 , V_2 -> V_108 -> V_187 , V_185 ,
L_23 , V_188 ) ) {
F_22 ( L_24 , V_185 ) ;
F_107 ( V_2 , V_137 ) ;
}
} else if ( ! V_186 ) {
F_109 ( V_169 , V_2 -> V_108 -> V_187 , V_185 ,
L_23 , V_189 ) ;
}
}
static void F_110 ( struct V_1 * V_2 , const char * V_185 ,
struct V_121 * V_137 )
{
if ( ! F_107 ( V_2 , V_137 ) ) {
if ( F_109 ( V_169 , V_2 -> V_108 -> V_187 , V_185 ,
L_23 , V_189 ) )
F_22 ( L_24 , V_185 ) ;
}
}
static void F_111 ( struct V_1 * V_2 , int V_190 ,
char * V_191 )
{
int V_35 ;
struct V_121 V_137 ;
char * V_192 ;
int V_193 ;
char V_171 [ V_194 ] ;
char V_195 [ 64 ] ;
char V_185 [ 64 ] ;
struct V_168 * V_108 = V_2 -> V_108 ;
snprintf ( V_185 , sizeof( V_185 ) , L_25 , V_191 ) ;
V_35 = F_112 ( V_169 , V_108 -> V_187 , V_185 , L_14 , & V_193 ) ;
if ( F_113 ( V_35 ) )
return;
snprintf ( V_195 , sizeof( V_195 ) , L_26 , V_191 ) ;
V_192 = F_114 ( V_169 , V_108 -> V_187 , V_195 , NULL ) ;
if ( F_79 ( V_192 ) ) {
F_109 ( V_169 , V_108 -> V_187 , V_185 ,
L_23 , V_189 ) ;
return;
}
F_115 ( V_171 , V_192 , V_194 ) ;
F_28 ( V_192 ) ;
snprintf ( V_195 , sizeof( V_195 ) , L_27 , V_191 ) ;
V_35 = F_112 ( V_169 , V_108 -> V_187 , V_195 , L_28 ,
& V_137 . V_196 , & V_137 . V_127 , & V_137 . V_128 , & V_137 . V_28 ) ;
if ( F_113 ( V_35 ) ) {
F_109 ( V_169 , V_108 -> V_187 , V_185 ,
L_23 , V_189 ) ;
return;
}
switch ( V_190 ) {
case V_197 :
switch ( V_193 ) {
case V_198 :
F_108 ( V_2 , V_185 , V_171 , & V_137 , 0 ) ;
break;
case V_199 :
F_108 ( V_2 , V_185 , V_171 , & V_137 , 1 ) ;
break;
case V_200 :
F_110 ( V_2 , V_185 , & V_137 ) ;
break;
default:
break;
}
break;
case V_201 :
if ( V_193 == V_188 ) {
if ( F_109 ( V_169 , V_108 -> V_187 , V_185 ,
L_23 , V_199 ) ) {
F_22 ( L_24 , V_195 ) ;
F_107 ( V_2 , & V_137 ) ;
F_109 ( V_169 , V_108 -> V_187 , V_185 ,
L_23 , V_189 ) ;
}
}
break;
default:
break;
}
}
static void F_116 ( struct V_1 * V_2 , int V_190 )
{
int V_8 ;
char * * V_202 ;
unsigned int V_203 = 0 ;
V_202 = F_117 ( V_169 , V_2 -> V_108 -> V_187 , L_29 ,
& V_203 ) ;
if ( F_79 ( V_202 ) )
return;
for ( V_8 = 0 ; V_8 < V_203 ; V_8 ++ )
F_111 ( V_2 , V_190 , V_202 [ V_8 ] ) ;
F_28 ( V_202 ) ;
}
static void F_118 ( struct V_168 * V_108 ,
enum V_204 V_205 )
{
struct V_1 * V_2 = F_119 ( & V_108 -> V_108 ) ;
switch ( V_205 ) {
case V_198 :
break;
case V_188 :
if ( F_96 ( V_2 ) )
break;
F_116 ( V_2 , V_197 ) ;
F_120 ( V_108 , V_199 ) ;
break;
case V_199 :
F_116 ( V_2 , V_201 ) ;
if ( V_108 -> V_185 == V_199 )
break;
F_120 ( V_108 , V_199 ) ;
break;
case V_200 :
if ( V_2 -> V_63 )
F_63 ( V_2 ) ;
F_120 ( V_108 , V_200 ) ;
break;
case V_189 :
F_120 ( V_108 , V_189 ) ;
if ( F_121 ( V_108 ) )
break;
case V_206 :
F_122 ( & V_108 -> V_108 ) ;
break;
case V_207 :
F_116 ( V_2 , V_197 ) ;
F_120 ( V_108 , V_208 ) ;
break;
default:
F_98 ( V_108 , - V_100 , L_30 ,
V_205 ) ;
break;
}
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_43 * V_44 , * V_209 ;
struct V_123 * V_124 = & ( V_2 -> V_125 ) ;
unsigned long V_7 ;
F_9 ( & V_2 -> V_126 , V_7 ) ;
F_124 (entry, tmp, head, l)
F_106 ( V_44 ) ;
F_11 ( & V_2 -> V_126 , V_7 ) ;
}
static int F_125 ( struct V_168 * V_108 )
{
struct V_1 * V_2 = F_119 ( & V_108 -> V_108 ) ;
if ( V_2 -> V_63 )
F_63 ( V_2 ) ;
F_123 ( V_2 ) ;
F_126 ( & V_108 -> V_108 , NULL ) ;
return 0 ;
}
static int F_127 ( struct V_168 * V_108 ,
const struct V_210 * V_144 )
{
int V_35 ;
struct V_1 * V_2 = F_128 ( sizeof( struct V_1 ) ,
V_106 ) ;
F_58 ( L_31 , V_211 , V_108 , V_108 -> V_212 ) ;
if ( ! V_2 ) {
F_98 ( V_108 , - V_84 , L_32 ) ;
return - V_84 ;
}
V_2 -> V_108 = V_108 ;
F_126 ( & V_108 -> V_108 , V_2 ) ;
V_2 -> V_88 = V_108 -> V_212 ;
F_129 ( & V_2 -> V_56 ) ;
V_2 -> V_150 = 0 ;
F_130 ( & V_2 -> V_3 , 0 ) ;
F_131 ( & V_2 -> V_4 ) ;
V_2 -> V_108 = V_108 ;
V_2 -> V_63 = 0 ;
F_132 ( & V_2 -> V_125 ) ;
F_129 ( & V_2 -> V_126 ) ;
V_35 = F_109 ( V_169 , V_108 -> V_187 , L_33 , L_14 ,
V_105 ) ;
if ( V_35 )
F_133 ( V_108 , V_35 , L_34 ) ;
V_35 = F_120 ( V_108 , V_213 ) ;
if ( V_35 )
goto V_214;
return 0 ;
V_214:
F_83 ( L_35 , V_211 ) ;
F_125 ( V_108 ) ;
return V_35 ;
}
static char * F_134 ( struct V_215 * V_26 )
{
switch ( V_26 -> V_216 ) {
case V_217 :
return L_36 ;
case V_218 :
return L_37 ;
case V_219 :
return L_38 ;
default:
break;
}
return L_39 ;
}
static char * F_135 ( struct V_220 * V_178 )
{
struct V_23 * V_24 = F_34 ( V_178 ,
struct V_23 , V_178 ) ;
struct V_215 * V_26 = V_24 -> V_26 ;
return & V_26 -> V_27 [ 0 ] ;
}
static T_11 F_136 ( struct V_220 * V_178 )
{
struct V_23 * V_24 = F_34 ( V_178 ,
struct V_23 , V_178 ) ;
return V_24 -> V_221 ;
}
static struct V_222 *
F_137 ( struct V_223 * V_224 ,
struct V_225 * V_226 ,
const char * V_227 )
{
struct V_215 * V_26 ;
char * V_228 ;
T_6 V_229 = 0 ;
int V_230 = 0 ;
V_26 = F_128 ( sizeof( struct V_215 ) , V_106 ) ;
if ( ! V_26 )
return F_77 ( - V_84 ) ;
V_26 -> V_231 = V_229 ;
V_228 = strstr ( V_227 , L_40 ) ;
if ( V_228 ) {
V_26 -> V_216 = V_217 ;
goto V_232;
}
V_228 = strstr ( V_227 , L_41 ) ;
if ( V_228 ) {
V_26 -> V_216 = V_218 ;
V_230 = 3 ;
goto V_232;
}
V_228 = strstr ( V_227 , L_42 ) ;
if ( V_228 ) {
V_26 -> V_216 = V_219 ;
goto V_232;
}
F_22 ( L_43 , V_227 ) ;
F_28 ( V_26 ) ;
return F_77 ( - V_100 ) ;
V_232:
if ( strlen ( V_227 ) >= V_194 ) {
F_22 ( L_44 , V_227 ,
F_134 ( V_26 ) , V_194 ) ;
F_28 ( V_26 ) ;
return F_77 ( - V_100 ) ;
}
snprintf ( & V_26 -> V_27 [ 0 ] , V_194 , L_45 , & V_227 [ V_230 ] ) ;
F_58 ( L_46 ,
F_134 ( V_26 ) , V_227 ) ;
return & V_26 -> V_233 ;
}
static void F_138 ( struct V_222 * V_234 )
{
struct V_215 * V_26 = F_34 ( V_234 ,
struct V_215 , V_233 ) ;
F_58 ( L_47 ,
F_134 ( V_26 ) , V_26 -> V_27 ) ;
F_28 ( V_26 ) ;
}
static T_5 F_139 ( struct V_220 * V_178 )
{
return 1 ;
}
static int F_140 ( struct V_64 * V_64 )
{
return F_50 ( V_64 , 0 ) ;
}
static void F_141 ( struct V_64 * V_64 )
{
struct V_67 * V_131 = V_64 -> V_131 ;
F_142 ( & V_131 -> V_132 , V_64 -> V_135 ) ;
}
static T_5 F_143 ( struct V_67 * V_131 )
{
return 0 ;
}
static int F_144 ( struct V_64 * V_64 )
{
F_145 ( V_64 ) ;
return 0 ;
}
static int F_146 ( struct V_64 * V_64 )
{
return 0 ;
}
static void F_147 ( struct V_235 * V_236 )
{
}
static int F_148 ( struct V_64 * V_64 )
{
return 0 ;
}
static int F_149 ( struct V_64 * V_64 )
{
struct V_16 * V_22 = F_34 ( V_64 ,
struct V_16 , V_64 ) ;
V_22 -> V_47 = V_237 ;
F_45 ( V_22 ) ;
return 0 ;
}
static int F_150 ( struct V_64 * V_64 )
{
struct V_16 * V_22 = F_34 ( V_64 ,
struct V_16 , V_64 ) ;
if ( V_64 -> V_20 &&
( ( V_64 -> V_238 & V_239 ) ||
( V_64 -> V_238 & V_240 ) ) )
V_22 -> V_47 = ( V_241 << 24 ) |
V_242 ;
else
V_22 -> V_47 = V_64 -> V_243 ;
F_45 ( V_22 ) ;
return 0 ;
}
static void F_151 ( struct V_64 * V_64 )
{
struct V_16 * V_22 = F_34 ( V_64 ,
struct V_16 , V_64 ) ;
F_152 ( & V_22 -> V_116 ) ;
}
static void F_153 ( struct V_64 * V_64 )
{
}
static T_12 F_154 ( struct V_244 * V_245 ,
char * V_5 )
{
struct V_220 * V_178 = F_155 ( V_245 ) ;
struct V_23 * V_24 = F_34 ( V_178 , struct V_23 ,
V_178 ) ;
T_12 V_246 ;
F_35 ( & V_24 -> V_45 ) ;
V_246 = snprintf ( V_5 , V_104 , L_48 , V_24 -> V_177 ) ;
F_36 ( & V_24 -> V_45 ) ;
return V_246 ;
}
static T_12 F_156 ( struct V_244 * V_245 ,
const char * V_5 , T_13 V_247 )
{
struct V_220 * V_178 = F_155 ( V_245 ) ;
struct V_23 * V_24 = F_34 ( V_178 , struct V_23 ,
V_178 ) ;
int V_55 ;
if ( strlen ( V_5 ) >= V_194 ) {
F_22 ( L_49 , V_5 ,
V_194 ) ;
return - V_100 ;
}
F_35 ( & V_24 -> V_45 ) ;
V_55 = snprintf ( V_24 -> V_177 , V_194 , L_45 , V_5 ) ;
if ( V_24 -> V_177 [ V_55 - 1 ] == '\n' )
V_24 -> V_177 [ V_55 - 1 ] = '\0' ;
F_36 ( & V_24 -> V_45 ) ;
return V_247 ;
}
static int F_157 ( struct V_220 * V_178 ,
struct V_67 * V_131 , void * V_248 )
{
struct V_23 * V_24 = F_34 ( V_178 ,
struct V_23 , V_178 ) ;
V_24 -> V_69 = V_248 ;
return 0 ;
}
static int F_158 ( struct V_23 * V_24 ,
const char * V_227 )
{
struct V_112 * V_249 ;
int V_183 = 0 ;
F_35 ( & V_24 -> V_45 ) ;
if ( V_24 -> V_69 ) {
F_58 ( L_50 ) ;
V_183 = - V_181 ;
goto V_250;
}
V_249 = F_128 ( sizeof( struct V_112 ) , V_106 ) ;
if ( ! V_249 ) {
V_183 = - V_84 ;
goto V_250;
}
V_249 -> V_70 = F_159 ( & V_24 -> V_178 ,
V_251 ,
sizeof( struct V_16 ) ,
V_252 , V_227 ,
V_249 , F_157 ) ;
if ( F_79 ( V_249 -> V_70 ) ) {
F_28 ( V_249 ) ;
V_183 = - V_84 ;
goto V_250;
}
V_250:
F_36 ( & V_24 -> V_45 ) ;
return V_183 ;
}
static int F_160 ( struct V_23 * V_24 )
{
struct V_67 * V_131 ;
struct V_112 * V_249 ;
F_35 ( & V_24 -> V_45 ) ;
V_249 = V_24 -> V_69 ;
if ( ! V_249 ) {
F_36 ( & V_24 -> V_45 ) ;
return - V_145 ;
}
V_131 = V_249 -> V_70 ;
if ( ! V_131 ) {
F_36 ( & V_24 -> V_45 ) ;
return - V_145 ;
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
F_58 ( L_53 ,
F_134 ( V_24 -> V_26 ) ,
V_249 -> V_70 -> V_235 -> V_255 ) ;
F_161 ( V_249 -> V_70 ) ;
V_24 -> V_69 = NULL ;
F_36 ( & V_24 -> V_45 ) ;
F_28 ( V_249 ) ;
return 0 ;
}
static T_12 F_162 ( struct V_244 * V_245 , char * V_5 )
{
struct V_220 * V_178 = F_163 ( V_245 ) ;
struct V_23 * V_24 = F_34 ( V_178 ,
struct V_23 , V_178 ) ;
struct V_112 * V_249 ;
T_12 V_183 ;
F_35 ( & V_24 -> V_45 ) ;
V_249 = V_24 -> V_69 ;
if ( ! V_249 ) {
F_36 ( & V_24 -> V_45 ) ;
return - V_145 ;
}
V_183 = snprintf ( V_5 , V_104 , L_48 ,
V_249 -> V_70 -> V_235 -> V_255 ) ;
F_36 ( & V_24 -> V_45 ) ;
return V_183 ;
}
static T_12 F_164 ( struct V_244 * V_245 ,
const char * V_5 , T_13 V_247 )
{
struct V_220 * V_178 = F_163 ( V_245 ) ;
struct V_23 * V_24 = F_34 ( V_178 ,
struct V_23 , V_178 ) ;
struct V_215 * V_233 = V_24 -> V_26 ;
unsigned char V_256 [ V_194 ] , * V_228 , * V_257 ;
int V_183 ;
if ( ! strncmp ( V_5 , L_54 , 4 ) ) {
V_183 = F_160 ( V_24 ) ;
return ( ! V_183 ) ? V_247 : V_183 ;
}
if ( strlen ( V_5 ) >= V_194 ) {
F_22 ( L_55 ,
V_5 , V_194 ) ;
return - V_100 ;
}
snprintf ( & V_256 [ 0 ] , V_194 , L_45 , V_5 ) ;
V_228 = strstr ( V_256 , L_40 ) ;
if ( V_228 ) {
if ( V_233 -> V_216 != V_217 ) {
F_22 ( L_56 ,
V_256 , F_134 ( V_233 ) ) ;
return - V_100 ;
}
V_257 = & V_256 [ 0 ] ;
goto V_258;
}
V_228 = strstr ( V_256 , L_41 ) ;
if ( V_228 ) {
if ( V_233 -> V_216 != V_218 ) {
F_22 ( L_57 ,
V_256 , F_134 ( V_233 ) ) ;
return - V_100 ;
}
V_257 = & V_256 [ 3 ] ;
goto V_258;
}
V_228 = strstr ( V_256 , L_42 ) ;
if ( V_228 ) {
if ( V_233 -> V_216 != V_219 ) {
F_22 ( L_58 ,
V_256 , F_134 ( V_233 ) ) ;
return - V_100 ;
}
V_257 = & V_256 [ 0 ] ;
goto V_258;
}
F_22 ( L_59 ,
V_256 ) ;
return - V_100 ;
V_258:
if ( V_256 [ strlen ( V_256 ) - 1 ] == '\n' )
V_256 [ strlen ( V_256 ) - 1 ] = '\0' ;
V_183 = F_158 ( V_24 , V_257 ) ;
if ( V_183 < 0 )
return V_183 ;
return V_247 ;
}
static T_12
F_165 ( struct V_244 * V_245 , char * V_5 )
{
return sprintf ( V_5 , L_60
V_259 L_61 ,
V_260 , F_166 () -> V_261 , F_166 () -> V_262 ) ;
}
static char * F_167 ( void )
{
return L_62 ;
}
static int F_168 ( struct V_220 * V_178 ,
struct V_174 * V_28 )
{
struct V_23 * V_24 = F_34 ( V_178 ,
struct V_23 , V_178 ) ;
F_35 ( & V_24 -> V_45 ) ;
V_24 -> V_253 ++ ;
F_36 ( & V_24 -> V_45 ) ;
return 0 ;
}
static void F_169 ( struct V_220 * V_178 ,
struct V_174 * V_28 )
{
struct V_23 * V_24 = F_34 ( V_178 ,
struct V_23 , V_178 ) ;
F_35 ( & V_24 -> V_45 ) ;
V_24 -> V_253 -- ;
F_36 ( & V_24 -> V_45 ) ;
}
static struct V_220 *
F_170 ( struct V_222 * V_234 ,
struct V_225 * V_226 ,
const char * V_227 )
{
struct V_215 * V_26 = F_34 ( V_234 ,
struct V_215 , V_233 ) ;
struct V_23 * V_24 ;
T_11 V_263 ;
int V_183 ;
if ( strstr ( V_227 , L_63 ) != V_227 )
return F_77 ( - V_100 ) ;
V_183 = F_171 ( V_227 + 5 , 10 , & V_263 ) ;
if ( V_183 )
return F_77 ( V_183 ) ;
V_24 = F_128 ( sizeof( struct V_23 ) , V_106 ) ;
if ( ! V_24 )
return F_77 ( - V_84 ) ;
F_172 ( & V_24 -> V_45 ) ;
F_132 ( & V_24 -> V_264 ) ;
F_132 ( & V_24 -> V_265 ) ;
V_24 -> V_26 = V_26 ;
V_24 -> V_221 = V_263 ;
V_183 = F_173 ( V_234 , & V_24 -> V_178 , V_26 -> V_216 ) ;
if ( V_183 < 0 ) {
F_28 ( V_24 ) ;
return NULL ;
}
F_35 ( & V_176 ) ;
F_105 ( & V_24 -> V_264 , & V_266 ) ;
F_36 ( & V_176 ) ;
return & V_24 -> V_178 ;
}
static void F_174 ( struct V_220 * V_178 )
{
struct V_23 * V_24 = F_34 ( V_178 ,
struct V_23 , V_178 ) ;
F_35 ( & V_176 ) ;
F_16 ( & V_24 -> V_264 ) ;
F_36 ( & V_176 ) ;
F_160 ( V_24 ) ;
F_175 ( V_178 ) ;
F_28 ( V_24 ) ;
}
static int F_176 ( struct V_220 * V_178 )
{
return 1 ;
}
static int F_177 ( struct V_220 * V_178 )
{
return 0 ;
}
static int T_14 F_178 ( void )
{
int V_183 ;
if ( ! F_179 () )
return - V_145 ;
F_58 ( L_64 V_259 L_61 ,
V_260 , F_166 () -> V_261 , F_166 () -> V_262 ) ;
V_183 = F_180 ( & V_267 ) ;
if ( V_183 )
goto V_129;
V_183 = F_181 ( & V_268 ) ;
if ( V_183 )
goto V_269;
return 0 ;
V_269:
F_182 ( & V_267 ) ;
V_129:
F_22 ( L_65 , V_211 , V_183 ) ;
return V_183 ;
}
static void T_15 F_183 ( void )
{
struct V_5 * V_5 ;
while ( V_9 ) {
if ( F_12 ( & V_5 ) )
F_184 () ;
F_8 ( 1 , & V_5 ) ;
}
F_185 ( & V_268 ) ;
F_182 ( & V_267 ) ;
}
