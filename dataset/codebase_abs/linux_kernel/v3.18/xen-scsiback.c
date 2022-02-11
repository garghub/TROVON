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
return F_14 ( 1 , V_5 , false ) ;
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
if ( V_30 & F_23 ( V_21 ) )
F_27 ( L_2 , V_20 ,
V_31 ) ;
}
static void F_28 ( struct V_16 * V_17 )
{
struct V_32 V_33 [ V_34 ] ;
struct V_5 * V_19 [ V_34 ] ;
unsigned int V_8 , V_35 = 0 ;
T_1 V_36 ;
int V_37 ;
F_29 ( V_17 -> V_38 ) ;
V_17 -> V_38 = NULL ;
V_17 -> V_39 = 0 ;
if ( ! V_17 -> V_40 )
return;
for ( V_8 = 0 ; V_8 < V_17 -> V_40 ; V_8 ++ ) {
V_36 = V_17 -> V_41 [ V_8 ] ;
if ( V_36 == V_42 )
continue;
F_30 ( & V_33 [ V_35 ] , F_20 ( V_17 , V_8 ) ,
V_43 , V_36 ) ;
V_17 -> V_41 [ V_8 ] = V_42 ;
V_19 [ V_35 ] = V_17 -> V_19 [ V_8 ] ;
F_31 ( V_19 [ V_35 ] ) ;
V_35 ++ ;
if ( V_35 < V_34 )
continue;
V_37 = F_32 ( V_33 , NULL , V_19 , V_35 ) ;
F_33 ( V_37 ) ;
V_35 = 0 ;
}
if ( V_35 ) {
V_37 = F_32 ( V_33 , NULL , V_19 , V_35 ) ;
F_33 ( V_37 ) ;
}
F_6 ( V_17 -> V_19 , V_17 -> V_40 ) ;
V_17 -> V_40 = 0 ;
}
static void F_34 ( struct V_44 * V_44 )
{
struct V_45 * V_46 = F_35 ( V_44 , struct V_45 , V_44 ) ;
struct V_23 * V_24 = V_46 -> V_24 ;
F_36 ( & V_24 -> V_47 ) ;
V_24 -> V_48 -- ;
F_37 ( & V_24 -> V_47 ) ;
F_29 ( V_46 ) ;
}
static void F_38 ( char * V_20 , T_2 V_49 ,
T_3 V_50 , struct V_16 * V_22 )
{
struct V_51 * V_52 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_53 ;
struct V_54 V_55 ;
unsigned long V_7 ;
unsigned V_56 ;
F_9 ( & V_2 -> V_57 , V_7 ) ;
V_52 = F_39 ( & V_2 -> V_58 , V_2 -> V_58 . V_59 ) ;
V_2 -> V_58 . V_59 ++ ;
V_52 -> V_60 = V_49 ;
V_52 -> V_61 = V_22 -> V_61 ;
if ( V_20 != NULL &&
F_40 ( V_20 , V_62 ,
& V_55 ) ) {
V_56 = F_41 ( unsigned , 8 + V_20 [ 7 ] ,
V_62 ) ;
memcpy ( V_52 -> V_20 , V_20 , V_56 ) ;
V_52 -> V_63 = V_56 ;
} else {
V_52 -> V_63 = 0 ;
}
V_52 -> V_64 = V_50 ;
F_42 ( & V_2 -> V_58 , V_53 ) ;
F_11 ( & V_2 -> V_57 , V_7 ) ;
if ( V_53 )
F_43 ( V_2 -> V_65 ) ;
if ( V_22 -> V_25 )
F_44 ( & V_22 -> V_25 -> V_44 ,
F_34 ) ;
}
static void F_45 ( struct V_16 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
unsigned char * V_20 ;
unsigned int V_50 ;
int V_21 ;
V_20 = V_22 -> V_20 ;
V_50 = V_22 -> V_66 . V_67 ;
V_21 = V_22 -> V_49 ;
if ( V_21 && V_68 )
F_21 ( V_20 , V_21 , V_22 ) ;
F_28 ( V_22 ) ;
F_38 ( V_20 , V_21 , V_50 , V_22 ) ;
F_3 ( V_2 ) ;
}
static void F_46 ( struct V_16 * V_22 )
{
struct V_66 * V_66 = & V_22 -> V_66 ;
struct V_69 * V_70 = V_22 -> V_25 -> V_24 -> V_71 -> V_72 ;
int V_73 ;
memset ( V_22 -> V_20 , 0 , V_62 ) ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
F_1 ( V_22 -> V_2 ) ;
V_73 = F_47 ( V_66 , V_70 , V_22 -> V_29 ,
V_22 -> V_20 , V_22 -> V_25 -> V_28 ,
V_22 -> V_74 , 0 ,
V_22 -> V_75 , 0 ,
V_22 -> V_38 , V_22 -> V_39 ,
NULL , 0 , NULL , 0 ) ;
if ( V_73 < 0 ) {
F_48 ( V_66 ,
V_76 , 0 ) ;
F_49 ( V_66 , 0 ) ;
}
}
static int F_50 ( struct V_77 * V_78 ,
struct V_5 * * V_79 , T_1 * V_80 , int V_81 )
{
int V_37 , V_8 ;
if ( ! V_81 )
return 0 ;
V_37 = F_51 ( V_78 , NULL , V_79 , V_81 ) ;
F_33 ( V_37 ) ;
for ( V_8 = 0 ; V_8 < V_81 ; V_8 ++ ) {
if ( F_52 ( V_78 [ V_8 ] . V_82 != V_83 ) ) {
F_22 ( L_3 ) ;
V_78 [ V_8 ] . V_36 = V_42 ;
V_37 = - V_84 ;
} else {
F_53 ( V_79 [ V_8 ] ) ;
}
V_80 [ V_8 ] = V_78 [ V_8 ] . V_36 ;
}
return V_37 ;
}
static int F_54 ( struct V_16 * V_22 ,
struct V_85 * V_18 , struct V_5 * * V_79 ,
T_1 * V_80 , int V_81 , T_4 V_7 )
{
int V_86 = 0 , V_8 , V_37 = 0 ;
struct V_77 V_78 [ V_34 ] ;
struct V_1 * V_2 = V_22 -> V_2 ;
for ( V_8 = 0 ; V_8 < V_81 ; V_8 ++ ) {
if ( F_12 ( V_79 + V_86 ) ) {
F_6 ( V_79 , V_86 ) ;
F_22 ( L_4 ) ;
return - V_84 ;
}
F_55 ( & V_78 [ V_86 ] , F_17 ( V_79 [ V_86 ] ) ,
V_7 , V_18 [ V_8 ] . V_87 , V_2 -> V_88 ) ;
V_86 ++ ;
if ( V_86 < V_34 )
continue;
V_37 = F_50 ( V_78 , V_79 , V_80 , V_86 ) ;
V_79 += V_86 ;
V_80 += V_86 ;
V_22 -> V_40 += V_86 ;
if ( V_37 )
return V_37 ;
V_86 = 0 ;
}
V_37 = F_50 ( V_78 , V_79 , V_80 , V_86 ) ;
V_22 -> V_40 += V_86 ;
return V_37 ;
}
static int F_56 ( struct V_89 * V_90 ,
struct V_16 * V_22 )
{
T_4 V_7 ;
int V_8 , V_37 , V_91 , V_92 = 0 ;
struct V_5 * * V_79 ;
struct V_85 * V_18 ;
unsigned long V_93 = 0 ;
unsigned int V_94 = ( unsigned int ) V_90 -> V_94 ;
unsigned int V_95 = 0 ;
struct V_96 * V_97 ;
T_1 * V_80 ;
V_22 -> V_39 = 0 ;
V_22 -> V_40 = 0 ;
V_22 -> V_74 = 0 ;
V_94 &= ~ V_98 ;
if ( ! V_94 )
return 0 ;
if ( V_94 > V_99 ) {
F_57 ( L_5 ,
V_90 -> V_94 ) ;
return - V_100 ;
}
if ( V_90 -> V_94 & V_98 ) {
V_37 = F_54 ( V_22 , V_90 -> V_18 ,
V_22 -> V_19 , V_22 -> V_41 ,
V_94 , V_43 | V_101 ) ;
if ( V_37 )
return V_37 ;
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
F_57 ( L_6 ,
V_94 ) ;
return - V_100 ;
}
}
V_22 -> V_38 = F_58 ( V_94 ,
sizeof( struct V_96 ) , V_106 ) ;
if ( ! V_22 -> V_38 )
return - V_84 ;
F_59 ( V_22 -> V_38 , V_94 ) ;
V_22 -> V_39 = V_94 ;
V_7 = V_43 ;
if ( V_22 -> V_75 == V_107 )
V_7 |= V_101 ;
V_79 = V_22 -> V_19 + V_95 ;
V_80 = V_22 -> V_41 + V_95 ;
if ( ! V_95 ) {
V_18 = V_90 -> V_18 ;
V_37 = F_54 ( V_22 , V_18 ,
V_79 , V_80 , V_94 , V_7 ) ;
if ( V_37 )
return V_37 ;
} else {
for ( V_8 = 0 ; V_8 < V_95 ; V_8 ++ ) {
V_18 = (struct V_85 * ) (
F_20 ( V_22 , V_8 ) + V_90 -> V_18 [ V_8 ] . V_103 ) ;
V_91 = V_90 -> V_18 [ V_8 ] . V_102 /
sizeof( struct V_85 ) ;
V_37 = F_54 ( V_22 , V_18 ,
V_79 , V_80 , V_91 , V_7 ) ;
if ( V_37 )
return V_37 ;
V_79 += V_91 ;
V_80 += V_91 ;
}
V_93 = F_20 ( V_22 , 0 ) + V_90 -> V_18 [ 0 ] . V_103 ;
V_18 = (struct V_85 * ) V_93 ;
V_93 += V_90 -> V_18 [ 0 ] . V_102 ;
V_79 = V_22 -> V_19 + V_95 ;
}
F_60 (pending_req->sgl, sg, nr_segments, i) {
F_61 ( V_97 , V_79 [ V_8 ] , V_18 -> V_102 , V_18 -> V_103 ) ;
V_22 -> V_74 += V_18 -> V_102 ;
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
static void F_62 ( struct V_1 * V_2 )
{
F_63 ( V_2 -> V_4 ,
F_64 ( & V_2 -> V_3 ) == 0 ) ;
F_65 ( V_2 -> V_65 , V_2 ) ;
V_2 -> V_65 = 0 ;
F_66 ( V_2 -> V_108 , V_2 -> V_58 . V_109 ) ;
}
static void F_67 ( struct V_16 * V_22 ,
enum V_110 V_111 , int V_112 )
{
int V_73 , V_37 = V_113 ;
struct V_23 * V_24 = V_22 -> V_25 -> V_24 ;
struct V_66 * V_66 = & V_22 -> V_66 ;
struct V_114 * V_115 ;
V_115 = F_68 ( sizeof( struct V_114 ) , V_106 ) ;
if ( ! V_115 )
goto V_116;
F_69 ( & V_115 -> V_117 ) ;
F_70 ( V_66 , V_24 -> V_118 . V_119 ,
V_24 -> V_71 -> V_72 , 0 , V_120 , V_121 ,
& V_22 -> V_20 [ 0 ] ) ;
V_73 = F_71 ( V_66 , V_115 , V_111 , V_106 ) ;
if ( V_73 < 0 )
goto V_116;
V_66 -> V_122 -> V_123 = V_112 ;
if ( F_72 ( V_66 , V_22 -> V_25 -> V_28 ) < 0 )
goto V_116;
F_73 ( V_66 ) ;
F_63 ( V_115 -> V_117 , F_64 ( & V_115 -> V_124 ) ) ;
V_37 = ( V_66 -> V_122 -> V_125 == V_126 ) ?
V_127 : V_113 ;
V_116:
if ( V_115 ) {
F_49 ( & V_22 -> V_66 , 1 ) ;
F_29 ( V_115 ) ;
}
F_38 ( NULL , V_37 , 0 , V_22 ) ;
F_74 ( V_128 , V_22 ) ;
}
static struct V_45 * F_75 ( struct V_1 * V_2 ,
struct V_129 * V_130 )
{
struct V_45 * V_46 ;
struct V_131 * V_132 = & ( V_2 -> V_133 ) ;
unsigned long V_7 ;
F_9 ( & V_2 -> V_134 , V_7 ) ;
F_76 (entry, head, l) {
if ( ( V_46 -> V_130 . V_135 == V_130 -> V_135 ) &&
( V_46 -> V_130 . V_136 == V_130 -> V_136 ) &&
( V_46 -> V_130 . V_28 == V_130 -> V_28 ) ) {
F_77 ( & V_46 -> V_44 ) ;
goto V_116;
}
}
V_46 = NULL ;
V_116:
F_11 ( & V_2 -> V_134 , V_7 ) ;
return V_46 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
struct V_16 * V_22 )
{
struct V_45 * V_25 ;
struct V_129 V_137 ;
V_22 -> V_61 = V_90 -> V_61 ;
V_22 -> V_2 = V_2 ;
V_137 . V_135 = V_90 -> V_138 ;
V_137 . V_136 = V_90 -> V_139 ;
V_137 . V_28 = V_90 -> V_28 ;
V_25 = F_75 ( V_2 , & V_137 ) ;
if ( ! V_25 ) {
V_22 -> V_25 = NULL ;
F_57 ( L_7 ) ;
return - V_140 ;
}
V_22 -> V_25 = V_25 ;
V_22 -> V_75 = V_90 -> V_75 ;
if ( ( V_22 -> V_75 != V_141 ) &&
( V_22 -> V_75 != V_107 ) &&
( V_22 -> V_75 != V_142 ) &&
( V_22 -> V_75 != V_120 ) ) {
F_57 ( L_8 ,
V_22 -> V_75 ) ;
return - V_100 ;
}
V_22 -> V_143 = V_90 -> V_143 ;
if ( V_22 -> V_143 > V_144 ) {
F_57 ( L_9 ,
V_22 -> V_143 ) ;
return - V_100 ;
}
memcpy ( V_22 -> V_29 , V_90 -> V_29 , V_22 -> V_143 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_145 * V_58 = & V_2 -> V_58 ;
struct V_89 * V_90 ;
struct V_16 * V_22 ;
T_5 V_73 , V_146 ;
int V_37 , V_147 ;
T_3 V_49 ;
T_6 V_111 ;
V_73 = V_58 -> V_148 ;
V_146 = V_58 -> V_109 -> V_149 ;
F_80 () ;
if ( F_81 ( V_58 , V_146 ) ) {
V_73 = V_58 -> V_59 ;
F_82 ( L_10 ,
V_2 -> V_88 , V_146 , V_73 , V_146 - V_73 ) ;
V_2 -> V_150 = 1 ;
return 0 ;
}
while ( ( V_73 != V_146 ) ) {
if ( F_83 ( V_58 , V_73 ) )
break;
V_22 = F_84 ( V_128 , V_106 ) ;
if ( ! V_22 )
return 1 ;
V_90 = F_85 ( V_58 , V_73 ) ;
V_58 -> V_148 = ++ V_73 ;
V_111 = V_90 -> V_111 ;
V_37 = F_78 ( V_2 , V_90 , V_22 ) ;
if ( V_37 ) {
switch ( V_37 ) {
case - V_140 :
V_49 = V_151 ;
break;
default:
V_49 = V_152 ;
break;
}
F_38 ( NULL , V_49 << 24 , 0 ,
V_22 ) ;
F_74 ( V_128 , V_22 ) ;
return 1 ;
}
switch ( V_111 ) {
case V_153 :
if ( F_56 ( V_90 , V_22 ) ) {
F_28 ( V_22 ) ;
F_38 ( NULL ,
V_152 << 24 , 0 , V_22 ) ;
F_74 ( V_128 , V_22 ) ;
} else {
F_46 ( V_22 ) ;
}
break;
case V_154 :
F_67 ( V_22 , V_155 ,
V_90 -> V_156 ) ;
break;
case V_157 :
F_67 ( V_22 , V_158 , 0 ) ;
break;
default:
F_86 ( L_11 ) ;
F_38 ( NULL , V_152 << 24 ,
0 , V_22 ) ;
F_74 ( V_128 , V_22 ) ;
break;
}
F_87 () ;
}
F_88 ( & V_2 -> V_58 , V_147 ) ;
return V_147 ;
}
static T_7 F_89 ( int V_65 , void * V_159 )
{
struct V_1 * V_2 = V_159 ;
if ( V_2 -> V_150 )
return V_160 ;
while ( F_79 ( V_2 ) )
F_87 () ;
return V_160 ;
}
static int F_90 ( struct V_1 * V_2 , T_8 V_161 ,
T_9 V_162 )
{
void * V_163 ;
struct V_164 * V_109 ;
int V_37 ;
if ( V_2 -> V_65 )
return - 1 ;
V_37 = F_91 ( V_2 -> V_108 , V_161 , & V_163 ) ;
if ( V_37 )
return V_37 ;
V_109 = (struct V_164 * ) V_163 ;
F_92 ( & V_2 -> V_58 , V_109 , V_104 ) ;
V_37 = F_93 ( V_2 -> V_88 , V_162 ) ;
if ( V_37 < 0 )
goto V_165;
V_2 -> V_65 = V_37 ;
V_37 = F_94 ( V_2 -> V_65 , NULL , F_89 ,
V_166 , L_12 , V_2 ) ;
if ( V_37 )
goto V_167;
return 0 ;
V_167:
F_65 ( V_2 -> V_65 , V_2 ) ;
V_2 -> V_65 = 0 ;
V_165:
F_66 ( V_2 -> V_108 , V_163 ) ;
return V_37 ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_168 * V_108 = V_2 -> V_108 ;
unsigned int V_161 , V_162 ;
int V_37 ;
V_37 = F_96 ( V_169 , V_108 -> V_170 ,
L_13 , L_14 , & V_161 ,
L_15 , L_14 , & V_162 , NULL ) ;
if ( V_37 ) {
F_97 ( V_108 , V_37 , L_16 , V_108 -> V_170 ) ;
return V_37 ;
}
return F_90 ( V_2 , V_161 , V_162 ) ;
}
static int F_98 ( struct V_1 * V_2 ,
char * V_171 , struct V_129 * V_130 )
{
int V_37 = 0 ;
struct V_45 * V_46 ;
struct V_45 * V_172 ;
struct V_131 * V_132 = & ( V_2 -> V_133 ) ;
unsigned long V_7 ;
char * V_173 ;
unsigned int V_28 ;
struct V_23 * V_174 , * V_24 = NULL ;
char * error = L_17 ;
V_173 = strrchr ( V_171 , ':' ) ;
if ( ! V_173 ) {
F_22 ( L_18 ,
V_171 ) ;
return - V_100 ;
}
* V_173 = 0 ;
V_173 ++ ;
if ( F_99 ( V_173 , 10 , & V_28 ) || V_28 >= V_175 ) {
F_22 ( L_19 , V_173 ) ;
return - V_100 ;
}
F_36 ( & V_176 ) ;
F_76 (tpg_entry, &scsiback_list, tv_tpg_list) {
if ( ! strcmp ( V_171 , V_174 -> V_26 -> V_27 ) ||
! strcmp ( V_171 , V_174 -> V_177 ) ) {
F_100 ( & V_174 -> V_118 . V_178 ) ;
if ( V_174 -> V_118 . V_179 [ V_28 ] -> V_180 ==
V_181 ) {
if ( ! V_174 -> V_71 )
error = L_20 ;
else
V_24 = V_174 ;
}
F_101 ( & V_174 -> V_118 . V_178 ) ;
break;
}
}
if ( V_24 ) {
F_36 ( & V_24 -> V_47 ) ;
V_24 -> V_48 ++ ;
F_37 ( & V_24 -> V_47 ) ;
}
F_37 ( & V_176 ) ;
if ( ! V_24 ) {
F_22 ( L_21 , V_171 , V_28 , error ) ;
return - V_140 ;
}
V_172 = F_102 ( sizeof( struct V_45 ) , V_106 ) ;
if ( V_172 == NULL ) {
V_37 = - V_84 ;
goto V_182;
}
F_9 ( & V_2 -> V_134 , V_7 ) ;
F_76 (entry, head, l) {
if ( ( V_46 -> V_130 . V_135 == V_130 -> V_135 ) &&
( V_46 -> V_130 . V_136 == V_130 -> V_136 ) &&
( V_46 -> V_130 . V_28 == V_130 -> V_28 ) ) {
F_82 ( L_22 ) ;
V_37 = - V_183 ;
goto V_116;
}
}
F_103 ( & V_172 -> V_44 ) ;
V_172 -> V_130 = * V_130 ;
V_172 -> V_24 = V_24 ;
V_172 -> V_28 = V_28 ;
F_104 ( & V_172 -> V_184 , V_132 ) ;
V_116:
F_11 ( & V_2 -> V_134 , V_7 ) ;
V_182:
F_36 ( & V_24 -> V_47 ) ;
V_24 -> V_48 -- ;
F_37 ( & V_24 -> V_47 ) ;
if ( V_37 )
F_29 ( V_172 ) ;
return V_37 ;
}
static void F_105 ( struct V_45 * V_46 )
{
F_16 ( & V_46 -> V_184 ) ;
F_44 ( & V_46 -> V_44 , F_34 ) ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_129 * V_130 )
{
struct V_45 * V_46 ;
struct V_131 * V_132 = & ( V_2 -> V_133 ) ;
unsigned long V_7 ;
F_9 ( & V_2 -> V_134 , V_7 ) ;
F_76 (entry, head, l) {
if ( ( V_46 -> V_130 . V_135 == V_130 -> V_135 ) &&
( V_46 -> V_130 . V_136 == V_130 -> V_136 ) &&
( V_46 -> V_130 . V_28 == V_130 -> V_28 ) ) {
goto V_185;
}
}
F_11 ( & V_2 -> V_134 , V_7 ) ;
return 1 ;
V_185:
F_105 ( V_46 ) ;
F_11 ( & V_2 -> V_134 , V_7 ) ;
return 0 ;
}
static void F_107 ( struct V_1 * V_2 , const char * V_186 ,
char * V_171 , struct V_129 * V_137 )
{
if ( ! F_98 ( V_2 , V_171 , V_137 ) ) {
if ( F_108 ( V_169 , V_2 -> V_108 -> V_187 , V_186 ,
L_23 , V_188 ) ) {
F_22 ( L_24 , V_186 ) ;
F_106 ( V_2 , V_137 ) ;
}
} else {
F_108 ( V_169 , V_2 -> V_108 -> V_187 , V_186 ,
L_23 , V_189 ) ;
}
}
static void F_109 ( struct V_1 * V_2 , const char * V_186 ,
struct V_129 * V_137 )
{
if ( ! F_106 ( V_2 , V_137 ) ) {
if ( F_108 ( V_169 , V_2 -> V_108 -> V_187 , V_186 ,
L_23 , V_189 ) )
F_22 ( L_24 , V_186 ) ;
}
}
static void F_110 ( struct V_1 * V_2 , int V_190 ,
char * V_191 )
{
int V_37 ;
struct V_129 V_137 ;
char * V_192 ;
int V_193 ;
char V_171 [ V_194 ] ;
char V_195 [ 64 ] ;
char V_186 [ 64 ] ;
struct V_168 * V_108 = V_2 -> V_108 ;
snprintf ( V_186 , sizeof( V_186 ) , L_25 , V_191 ) ;
V_37 = F_111 ( V_169 , V_108 -> V_187 , V_186 , L_14 , & V_193 ) ;
if ( F_112 ( V_37 ) )
return;
snprintf ( V_195 , sizeof( V_195 ) , L_26 , V_191 ) ;
V_192 = F_113 ( V_169 , V_108 -> V_187 , V_195 , NULL ) ;
if ( F_114 ( V_192 ) ) {
F_108 ( V_169 , V_108 -> V_187 , V_186 ,
L_23 , V_189 ) ;
return;
}
F_115 ( V_171 , V_192 , V_194 ) ;
F_29 ( V_192 ) ;
snprintf ( V_195 , sizeof( V_195 ) , L_27 , V_191 ) ;
V_37 = F_111 ( V_169 , V_108 -> V_187 , V_195 , L_28 ,
& V_137 . V_196 , & V_137 . V_135 , & V_137 . V_136 , & V_137 . V_28 ) ;
if ( F_112 ( V_37 ) ) {
F_108 ( V_169 , V_108 -> V_187 , V_186 ,
L_23 , V_189 ) ;
return;
}
switch ( V_190 ) {
case V_197 :
if ( V_193 == V_198 )
F_107 ( V_2 , V_186 , V_171 , & V_137 ) ;
if ( V_193 == V_199 )
F_109 ( V_2 , V_186 , & V_137 ) ;
break;
case V_200 :
if ( V_193 == V_188 ) {
if ( F_108 ( V_169 , V_108 -> V_187 , V_186 ,
L_23 , V_201 ) ) {
F_22 ( L_24 ,
V_195 ) ;
F_106 ( V_2 , & V_137 ) ;
F_108 ( V_169 , V_108 -> V_187 , V_186 ,
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
if ( F_114 ( V_202 ) )
return;
for ( V_8 = 0 ; V_8 < V_203 ; V_8 ++ )
F_110 ( V_2 , V_190 , V_202 [ V_8 ] ) ;
F_29 ( V_202 ) ;
}
static void F_118 ( struct V_168 * V_108 ,
enum V_204 V_205 )
{
struct V_1 * V_2 = F_119 ( & V_108 -> V_108 ) ;
switch ( V_205 ) {
case V_198 :
break;
case V_188 :
if ( F_95 ( V_2 ) )
break;
F_116 ( V_2 , V_197 ) ;
F_120 ( V_108 , V_201 ) ;
break;
case V_201 :
F_116 ( V_2 , V_200 ) ;
if ( V_108 -> V_186 == V_201 )
break;
F_120 ( V_108 , V_201 ) ;
break;
case V_199 :
if ( V_2 -> V_65 )
F_62 ( V_2 ) ;
F_120 ( V_108 , V_199 ) ;
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
F_97 ( V_108 , - V_100 , L_30 ,
V_205 ) ;
break;
}
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_45 * V_46 , * V_209 ;
struct V_131 * V_132 = & ( V_2 -> V_133 ) ;
unsigned long V_7 ;
F_9 ( & V_2 -> V_134 , V_7 ) ;
F_124 (entry, tmp, head, l)
F_105 ( V_46 ) ;
F_11 ( & V_2 -> V_134 , V_7 ) ;
}
static int F_125 ( struct V_168 * V_108 )
{
struct V_1 * V_2 = F_119 ( & V_108 -> V_108 ) ;
if ( V_2 -> V_65 )
F_62 ( V_2 ) ;
F_123 ( V_2 ) ;
F_126 ( & V_108 -> V_108 , NULL ) ;
return 0 ;
}
static int F_127 ( struct V_168 * V_108 ,
const struct V_210 * V_139 )
{
int V_37 ;
struct V_1 * V_2 = F_68 ( sizeof( struct V_1 ) ,
V_106 ) ;
F_57 ( L_31 , V_108 , V_108 -> V_211 ) ;
if ( ! V_2 ) {
F_97 ( V_108 , - V_84 , L_32 ) ;
return - V_84 ;
}
V_2 -> V_108 = V_108 ;
F_126 ( & V_108 -> V_108 , V_2 ) ;
V_2 -> V_88 = V_108 -> V_211 ;
F_128 ( & V_2 -> V_57 ) ;
V_2 -> V_150 = 0 ;
F_129 ( & V_2 -> V_3 , 0 ) ;
F_69 ( & V_2 -> V_4 ) ;
V_2 -> V_108 = V_108 ;
V_2 -> V_65 = 0 ;
F_130 ( & V_2 -> V_133 ) ;
F_128 ( & V_2 -> V_134 ) ;
V_37 = F_108 ( V_169 , V_108 -> V_187 , L_33 , L_14 ,
V_105 ) ;
if ( V_37 )
F_131 ( V_108 , V_37 , L_34 ) ;
V_37 = F_120 ( V_108 , V_212 ) ;
if ( V_37 )
goto V_213;
return 0 ;
V_213:
F_82 ( L_35 , V_214 ) ;
F_125 ( V_108 ) ;
return V_37 ;
}
static char * F_132 ( struct V_215 * V_26 )
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
static T_10 F_133 ( struct V_220 * V_118 )
{
struct V_23 * V_24 = F_35 ( V_118 ,
struct V_23 , V_118 ) ;
struct V_215 * V_26 = V_24 -> V_26 ;
switch ( V_26 -> V_216 ) {
case V_217 :
return F_134 ( V_118 ) ;
case V_218 :
return F_135 ( V_118 ) ;
case V_219 :
return F_136 ( V_118 ) ;
default:
F_22 ( L_40 ,
V_26 -> V_216 ) ;
break;
}
return F_134 ( V_118 ) ;
}
static char * F_137 ( struct V_220 * V_118 )
{
struct V_23 * V_24 = F_35 ( V_118 ,
struct V_23 , V_118 ) ;
struct V_215 * V_26 = V_24 -> V_26 ;
return & V_26 -> V_27 [ 0 ] ;
}
static T_11 F_138 ( struct V_220 * V_118 )
{
struct V_23 * V_24 = F_35 ( V_118 ,
struct V_23 , V_118 ) ;
return V_24 -> V_221 ;
}
static T_4 F_139 ( struct V_220 * V_118 )
{
return 1 ;
}
static T_4
F_140 ( struct V_220 * V_118 ,
struct V_222 * V_223 ,
struct V_224 * V_225 ,
int * V_226 ,
unsigned char * V_227 )
{
struct V_23 * V_24 = F_35 ( V_118 ,
struct V_23 , V_118 ) ;
struct V_215 * V_26 = V_24 -> V_26 ;
switch ( V_26 -> V_216 ) {
case V_217 :
return F_141 ( V_118 , V_223 , V_225 ,
V_226 , V_227 ) ;
case V_218 :
return F_142 ( V_118 , V_223 , V_225 ,
V_226 , V_227 ) ;
case V_219 :
return F_143 ( V_118 , V_223 , V_225 ,
V_226 , V_227 ) ;
default:
F_22 ( L_40 ,
V_26 -> V_216 ) ;
break;
}
return F_141 ( V_118 , V_223 , V_225 ,
V_226 , V_227 ) ;
}
static T_4
F_144 ( struct V_220 * V_118 ,
struct V_222 * V_223 ,
struct V_224 * V_225 ,
int * V_226 )
{
struct V_23 * V_24 = F_35 ( V_118 ,
struct V_23 , V_118 ) ;
struct V_215 * V_26 = V_24 -> V_26 ;
switch ( V_26 -> V_216 ) {
case V_217 :
return F_145 ( V_118 , V_223 , V_225 ,
V_226 ) ;
case V_218 :
return F_146 ( V_118 , V_223 , V_225 ,
V_226 ) ;
case V_219 :
return F_147 ( V_118 , V_223 , V_225 ,
V_226 ) ;
default:
F_22 ( L_40 ,
V_26 -> V_216 ) ;
break;
}
return F_145 ( V_118 , V_223 , V_225 ,
V_226 ) ;
}
static char *
F_148 ( struct V_220 * V_118 ,
const char * V_227 ,
T_4 * V_228 ,
char * * V_229 )
{
struct V_23 * V_24 = F_35 ( V_118 ,
struct V_23 , V_118 ) ;
struct V_215 * V_26 = V_24 -> V_26 ;
switch ( V_26 -> V_216 ) {
case V_217 :
return F_149 ( V_118 , V_227 , V_228 ,
V_229 ) ;
case V_218 :
return F_150 ( V_118 , V_227 , V_228 ,
V_229 ) ;
case V_219 :
return F_151 ( V_118 , V_227 , V_228 ,
V_229 ) ;
default:
F_22 ( L_40 ,
V_26 -> V_216 ) ;
break;
}
return F_149 ( V_118 , V_227 , V_228 ,
V_229 ) ;
}
static struct V_230 *
F_152 ( struct V_231 * V_232 ,
struct V_233 * V_234 ,
const char * V_235 )
{
struct V_215 * V_26 ;
char * V_236 ;
T_12 V_237 = 0 ;
int V_238 = 0 ;
V_26 = F_68 ( sizeof( struct V_215 ) , V_106 ) ;
if ( ! V_26 )
return F_153 ( - V_84 ) ;
V_26 -> V_239 = V_237 ;
V_236 = strstr ( V_235 , L_41 ) ;
if ( V_236 ) {
V_26 -> V_216 = V_217 ;
goto V_240;
}
V_236 = strstr ( V_235 , L_42 ) ;
if ( V_236 ) {
V_26 -> V_216 = V_218 ;
V_238 = 3 ;
goto V_240;
}
V_236 = strstr ( V_235 , L_43 ) ;
if ( V_236 ) {
V_26 -> V_216 = V_219 ;
goto V_240;
}
F_22 ( L_44 , V_235 ) ;
F_29 ( V_26 ) ;
return F_153 ( - V_100 ) ;
V_240:
if ( strlen ( V_235 ) >= V_194 ) {
F_22 ( L_45 , V_235 ,
F_132 ( V_26 ) , V_194 ) ;
F_29 ( V_26 ) ;
return F_153 ( - V_100 ) ;
}
snprintf ( & V_26 -> V_27 [ 0 ] , V_194 , L_46 , & V_235 [ V_238 ] ) ;
F_154 ( L_47 ,
F_132 ( V_26 ) , V_235 ) ;
return & V_26 -> V_241 ;
}
static void F_155 ( struct V_230 * V_242 )
{
struct V_215 * V_26 = F_35 ( V_242 ,
struct V_215 , V_241 ) ;
F_154 ( L_48 ,
F_132 ( V_26 ) , V_26 -> V_27 ) ;
F_29 ( V_26 ) ;
}
static struct V_222 *
F_156 ( struct V_220 * V_118 )
{
return F_68 ( sizeof( struct V_222 ) , V_106 ) ;
}
static void
F_157 ( struct V_220 * V_118 ,
struct V_222 * V_223 )
{
F_29 ( V_223 ) ;
}
static T_4 F_158 ( struct V_220 * V_118 )
{
return 1 ;
}
static int F_159 ( struct V_66 * V_66 )
{
if ( V_66 -> V_243 & V_244 )
return 0 ;
F_49 ( V_66 , 0 ) ;
return 1 ;
}
static void F_160 ( struct V_66 * V_66 )
{
struct V_16 * V_22 = F_35 ( V_66 ,
struct V_16 , V_66 ) ;
F_74 ( V_128 , V_22 ) ;
}
static int F_161 ( struct V_69 * V_245 )
{
return 0 ;
}
static void F_162 ( struct V_69 * V_245 )
{
}
static T_4 F_163 ( struct V_69 * V_245 )
{
return 0 ;
}
static int F_164 ( struct V_66 * V_66 )
{
F_165 ( V_66 ) ;
return 0 ;
}
static int F_166 ( struct V_66 * V_66 )
{
return 0 ;
}
static void F_167 ( struct V_222 * V_246 )
{
}
static T_4 F_168 ( struct V_66 * V_66 )
{
struct V_16 * V_22 = F_35 ( V_66 ,
struct V_16 , V_66 ) ;
return V_22 -> V_61 ;
}
static int F_169 ( struct V_66 * V_66 )
{
return 0 ;
}
static int F_170 ( struct V_66 * V_66 )
{
struct V_16 * V_22 = F_35 ( V_66 ,
struct V_16 , V_66 ) ;
V_22 -> V_49 = V_247 ;
F_45 ( V_22 ) ;
return 0 ;
}
static int F_171 ( struct V_66 * V_66 )
{
struct V_16 * V_22 = F_35 ( V_66 ,
struct V_16 , V_66 ) ;
if ( V_66 -> V_20 &&
( ( V_66 -> V_243 & V_248 ) ||
( V_66 -> V_243 & V_249 ) ) )
V_22 -> V_49 = ( V_250 << 24 ) |
V_251 ;
else
V_22 -> V_49 = V_66 -> V_252 ;
F_45 ( V_22 ) ;
return 0 ;
}
static void F_172 ( struct V_66 * V_66 )
{
struct V_122 * V_253 = V_66 -> V_122 ;
struct V_114 * V_115 = V_253 -> V_254 ;
F_129 ( & V_115 -> V_124 , 1 ) ;
F_5 ( & V_115 -> V_117 ) ;
}
static void F_173 ( struct V_66 * V_66 )
{
}
static T_13 F_174 ( struct V_220 * V_118 ,
char * V_5 )
{
struct V_23 * V_24 = F_35 ( V_118 , struct V_23 ,
V_118 ) ;
T_13 V_255 ;
F_36 ( & V_24 -> V_47 ) ;
V_255 = snprintf ( V_5 , V_104 , L_49 , V_24 -> V_177 ) ;
F_37 ( & V_24 -> V_47 ) ;
return V_255 ;
}
static T_13 F_175 ( struct V_220 * V_118 ,
const char * V_5 , T_14 V_256 )
{
struct V_23 * V_24 = F_35 ( V_118 , struct V_23 ,
V_118 ) ;
int V_56 ;
if ( strlen ( V_5 ) >= V_194 ) {
F_22 ( L_50 , V_5 ,
V_194 ) ;
return - V_100 ;
}
F_36 ( & V_24 -> V_47 ) ;
V_56 = snprintf ( V_24 -> V_177 , V_194 , L_46 , V_5 ) ;
if ( V_24 -> V_177 [ V_56 - 1 ] == '\n' )
V_24 -> V_177 [ V_56 - 1 ] = '\0' ;
F_37 ( & V_24 -> V_47 ) ;
return V_256 ;
}
static int F_176 ( struct V_23 * V_24 ,
const char * V_235 )
{
struct V_220 * V_118 ;
struct V_69 * V_245 ;
struct V_257 * V_258 ;
F_36 ( & V_24 -> V_47 ) ;
if ( V_24 -> V_71 ) {
F_37 ( & V_24 -> V_47 ) ;
F_154 ( L_51 ) ;
return - V_183 ;
}
V_118 = & V_24 -> V_118 ;
V_258 = F_68 ( sizeof( struct V_257 ) , V_106 ) ;
if ( ! V_258 ) {
F_37 ( & V_24 -> V_47 ) ;
return - V_84 ;
}
V_258 -> V_72 = F_177 ( V_259 ) ;
if ( F_114 ( V_258 -> V_72 ) ) {
F_37 ( & V_24 -> V_47 ) ;
F_29 ( V_258 ) ;
return - V_84 ;
}
V_245 = V_258 -> V_72 ;
V_258 -> V_72 -> V_222 = F_178 (
V_118 , ( unsigned char * ) V_235 ) ;
if ( ! V_258 -> V_72 -> V_222 ) {
F_37 ( & V_24 -> V_47 ) ;
F_154 ( L_52 ,
V_235 ) ;
goto V_116;
}
F_179 ( V_118 , V_258 -> V_72 -> V_222 ,
V_258 -> V_72 , V_258 ) ;
V_24 -> V_71 = V_258 ;
F_37 ( & V_24 -> V_47 ) ;
return 0 ;
V_116:
F_180 ( V_245 ) ;
F_29 ( V_258 ) ;
return - V_84 ;
}
static int F_181 ( struct V_23 * V_24 )
{
struct V_69 * V_245 ;
struct V_257 * V_258 ;
F_36 ( & V_24 -> V_47 ) ;
V_258 = V_24 -> V_71 ;
if ( ! V_258 ) {
F_37 ( & V_24 -> V_47 ) ;
return - V_140 ;
}
V_245 = V_258 -> V_72 ;
if ( ! V_245 ) {
F_37 ( & V_24 -> V_47 ) ;
return - V_140 ;
}
if ( V_24 -> V_260 != 0 ) {
F_37 ( & V_24 -> V_47 ) ;
F_22 ( L_53 ,
V_24 -> V_260 ) ;
return - V_261 ;
}
if ( V_24 -> V_48 != 0 ) {
F_37 ( & V_24 -> V_47 ) ;
F_22 ( L_54 ,
V_24 -> V_48 ) ;
return - V_261 ;
}
F_154 ( L_55 ,
F_132 ( V_24 -> V_26 ) ,
V_258 -> V_72 -> V_222 -> V_262 ) ;
F_182 ( V_258 -> V_72 ) ;
V_24 -> V_71 = NULL ;
F_37 ( & V_24 -> V_47 ) ;
F_29 ( V_258 ) ;
return 0 ;
}
static T_13 F_183 ( struct V_220 * V_118 ,
char * V_5 )
{
struct V_23 * V_24 = F_35 ( V_118 ,
struct V_23 , V_118 ) ;
struct V_257 * V_258 ;
T_13 V_263 ;
F_36 ( & V_24 -> V_47 ) ;
V_258 = V_24 -> V_71 ;
if ( ! V_258 ) {
F_37 ( & V_24 -> V_47 ) ;
return - V_140 ;
}
V_263 = snprintf ( V_5 , V_104 , L_49 ,
V_258 -> V_72 -> V_222 -> V_262 ) ;
F_37 ( & V_24 -> V_47 ) ;
return V_263 ;
}
static T_13 F_184 ( struct V_220 * V_118 ,
const char * V_5 ,
T_14 V_256 )
{
struct V_23 * V_24 = F_35 ( V_118 ,
struct V_23 , V_118 ) ;
struct V_215 * V_241 = V_24 -> V_26 ;
unsigned char V_264 [ V_194 ] , * V_236 , * V_265 ;
int V_263 ;
if ( ! strncmp ( V_5 , L_56 , 4 ) ) {
V_263 = F_181 ( V_24 ) ;
return ( ! V_263 ) ? V_256 : V_263 ;
}
if ( strlen ( V_5 ) >= V_194 ) {
F_22 ( L_57 ,
V_5 , V_194 ) ;
return - V_100 ;
}
snprintf ( & V_264 [ 0 ] , V_194 , L_46 , V_5 ) ;
V_236 = strstr ( V_264 , L_41 ) ;
if ( V_236 ) {
if ( V_241 -> V_216 != V_217 ) {
F_22 ( L_58 ,
V_264 , F_132 ( V_241 ) ) ;
return - V_100 ;
}
V_265 = & V_264 [ 0 ] ;
goto V_266;
}
V_236 = strstr ( V_264 , L_42 ) ;
if ( V_236 ) {
if ( V_241 -> V_216 != V_218 ) {
F_22 ( L_59 ,
V_264 , F_132 ( V_241 ) ) ;
return - V_100 ;
}
V_265 = & V_264 [ 3 ] ;
goto V_266;
}
V_236 = strstr ( V_264 , L_43 ) ;
if ( V_236 ) {
if ( V_241 -> V_216 != V_219 ) {
F_22 ( L_60 ,
V_264 , F_132 ( V_241 ) ) ;
return - V_100 ;
}
V_265 = & V_264 [ 0 ] ;
goto V_266;
}
F_22 ( L_61 ,
V_264 ) ;
return - V_100 ;
V_266:
if ( V_264 [ strlen ( V_264 ) - 1 ] == '\n' )
V_264 [ strlen ( V_264 ) - 1 ] = '\0' ;
V_263 = F_176 ( V_24 , V_265 ) ;
if ( V_263 < 0 )
return V_263 ;
return V_256 ;
}
static T_13
F_185 ( struct V_231 * V_232 ,
char * V_5 )
{
return sprintf ( V_5 , L_62
V_267 L_63 ,
V_268 , F_186 () -> V_269 , F_186 () -> V_270 ) ;
}
static char * F_187 ( void )
{
return L_2 ;
}
static int F_188 ( struct V_220 * V_118 ,
struct V_271 * V_28 )
{
struct V_23 * V_24 = F_35 ( V_118 ,
struct V_23 , V_118 ) ;
F_36 ( & V_24 -> V_47 ) ;
V_24 -> V_260 ++ ;
F_37 ( & V_24 -> V_47 ) ;
return 0 ;
}
static void F_189 ( struct V_220 * V_118 ,
struct V_271 * V_28 )
{
struct V_23 * V_24 = F_35 ( V_118 ,
struct V_23 , V_118 ) ;
F_36 ( & V_24 -> V_47 ) ;
V_24 -> V_260 -- ;
F_37 ( & V_24 -> V_47 ) ;
}
static struct V_220 *
F_190 ( struct V_230 * V_242 ,
struct V_233 * V_234 ,
const char * V_235 )
{
struct V_215 * V_26 = F_35 ( V_242 ,
struct V_215 , V_241 ) ;
struct V_23 * V_24 ;
T_11 V_272 ;
int V_263 ;
if ( strstr ( V_235 , L_64 ) != V_235 )
return F_153 ( - V_100 ) ;
V_263 = F_191 ( V_235 + 5 , 10 , & V_272 ) ;
if ( V_263 )
return F_153 ( V_263 ) ;
V_24 = F_68 ( sizeof( struct V_23 ) , V_106 ) ;
if ( ! V_24 )
return F_153 ( - V_84 ) ;
F_192 ( & V_24 -> V_47 ) ;
F_130 ( & V_24 -> V_273 ) ;
F_130 ( & V_24 -> V_274 ) ;
V_24 -> V_26 = V_26 ;
V_24 -> V_221 = V_272 ;
V_263 = F_193 ( & V_275 -> V_276 , V_242 ,
& V_24 -> V_118 , V_24 , V_277 ) ;
if ( V_263 < 0 ) {
F_29 ( V_24 ) ;
return NULL ;
}
F_36 ( & V_176 ) ;
F_104 ( & V_24 -> V_273 , & V_278 ) ;
F_37 ( & V_176 ) ;
return & V_24 -> V_118 ;
}
static void F_194 ( struct V_220 * V_118 )
{
struct V_23 * V_24 = F_35 ( V_118 ,
struct V_23 , V_118 ) ;
F_36 ( & V_176 ) ;
F_16 ( & V_24 -> V_273 ) ;
F_37 ( & V_176 ) ;
F_181 ( V_24 ) ;
F_195 ( V_118 ) ;
F_29 ( V_24 ) ;
}
static int F_196 ( struct V_220 * V_118 )
{
return 1 ;
}
static int F_197 ( struct V_220 * V_118 )
{
return 0 ;
}
static int F_198 ( void )
{
struct V_231 * V_279 ;
int V_263 ;
F_154 ( L_65 V_267 L_63 ,
V_268 , F_186 () -> V_269 , F_186 () -> V_270 ) ;
V_279 = F_199 ( V_280 , L_2 ) ;
if ( F_114 ( V_279 ) )
return F_200 ( V_279 ) ;
V_279 -> V_276 = V_281 ;
V_279 -> V_282 . V_283 . V_284 = V_285 ;
V_279 -> V_282 . V_286 . V_284 = V_287 ;
V_279 -> V_282 . V_288 . V_284 = NULL ;
V_279 -> V_282 . V_289 . V_284 = V_290 ;
V_279 -> V_282 . V_291 . V_284 = NULL ;
V_279 -> V_282 . V_292 . V_284 = NULL ;
V_279 -> V_282 . V_293 . V_284 = NULL ;
V_279 -> V_282 . V_294 . V_284 = NULL ;
V_279 -> V_282 . V_295 . V_284 = NULL ;
V_263 = F_201 ( V_279 ) ;
if ( V_263 < 0 ) {
F_202 ( V_279 ) ;
return V_263 ;
}
V_275 = V_279 ;
F_154 ( L_66 ) ;
return 0 ;
}
static void F_203 ( void )
{
if ( ! V_275 )
return;
F_204 ( V_275 ) ;
V_275 = NULL ;
F_154 ( L_67 ) ;
}
static void F_205 ( void * V_296 )
{
struct V_16 * V_297 = V_296 ;
int V_8 ;
memset ( V_297 , 0 , sizeof( * V_297 ) ) ;
for ( V_8 = 0 ; V_8 < V_298 ; V_8 ++ )
V_297 -> V_41 [ V_8 ] = V_42 ;
}
static int T_15 F_206 ( void )
{
int V_263 ;
if ( ! F_207 () )
return - V_140 ;
V_128 = F_208 ( L_68 ,
sizeof( struct V_16 ) , 0 , 0 , F_205 ) ;
if ( ! V_128 )
return - V_84 ;
V_263 = F_209 ( & V_299 ) ;
if ( V_263 )
goto V_300;
V_263 = F_198 () ;
if ( V_263 )
goto V_301;
return 0 ;
V_301:
F_210 ( & V_299 ) ;
V_300:
F_211 ( V_128 ) ;
F_22 ( L_69 , V_214 , V_263 ) ;
return V_263 ;
}
static void T_16 F_212 ( void )
{
struct V_5 * V_5 ;
while ( V_9 ) {
if ( F_12 ( & V_5 ) )
F_213 () ;
F_8 ( 1 , & V_5 ) ;
}
F_203 () ;
F_210 ( & V_299 ) ;
F_211 ( V_128 ) ;
}
