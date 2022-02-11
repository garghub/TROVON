void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
for ( V_5 = 0 , V_4 = V_2 -> V_6 ; V_5 < V_2 -> V_7 . V_8 ; V_5 ++ , V_4 ++ ) {
struct V_9 * V_10 ;
V_4 -> V_11 = NULL ;
V_4 -> V_12 = NULL ;
V_4 -> V_13 . V_14 = NULL ;
V_4 -> V_13 . V_15 = V_5 ;
V_4 -> V_13 . V_16 = V_4 -> V_17 ;
V_4 -> V_13 . V_18 = V_19 ;
V_10 = & V_4 -> V_17 [ 0 ] ;
V_10 -> V_20 = V_2 -> V_21 + ( V_5 * sizeof( struct V_22 ) ) ;
V_10 -> V_23 = sizeof( struct V_22 ) ;
V_10 -> V_24 = V_2 -> V_25 -> V_26 ;
V_10 = & V_4 -> V_17 [ 1 ] ;
V_10 -> V_20 = 0 ;
V_10 -> V_23 = V_27 ;
V_10 -> V_24 = V_2 -> V_25 -> V_26 ;
}
}
static void F_2 ( struct V_28 * V_29 ,
struct V_28 * V_30 )
{
struct V_28 * V_31 = V_29 -> V_32 ;
F_3 ( V_31 , V_30 ) ;
F_4 ( V_31 , V_30 ) ;
}
static void F_5 ( struct V_33 * V_34 )
{
struct V_28 * V_35 ;
V_35 = F_6 ( & V_34 -> V_36 , NULL ) ;
if ( V_35 ) {
if ( V_34 -> V_37 )
F_2 ( V_35 , V_34 -> V_37 ) ;
else
V_34 -> V_37 = V_35 ;
}
}
static int F_7 ( struct V_33 * V_34 )
{
struct V_38 * V_39 ;
int V_40 ;
V_34 -> V_41 = F_8 ( struct V_38 ) ;
if ( ! V_34 -> V_41 )
return - V_42 ;
F_9 (cpu) {
V_39 = F_10 ( V_34 -> V_41 , V_40 ) ;
V_39 -> V_43 = NULL ;
V_39 -> V_44 = 0 ;
}
V_34 -> V_36 = NULL ;
V_34 -> V_37 = NULL ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_45 ;
V_45 = F_7 ( & V_2 -> V_46 ) ;
if ( ! V_45 ) {
V_45 = F_7 ( & V_2 -> V_47 ) ;
if ( V_45 )
F_12 ( V_2 -> V_46 . V_41 ) ;
}
return V_45 ;
}
static void F_13 ( struct V_33 * V_34 ,
struct V_28 * V_48 )
{
struct V_38 * V_39 ;
int V_40 ;
F_9 (cpu) {
V_39 = F_10 ( V_34 -> V_41 , V_40 ) ;
if ( V_39 -> V_43 ) {
F_2 ( V_39 -> V_43 , V_48 ) ;
V_39 -> V_43 = NULL ;
}
}
if ( V_34 -> V_37 ) {
F_2 ( V_34 -> V_37 , V_48 ) ;
V_34 -> V_37 = NULL ;
}
}
void F_14 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
struct V_49 * V_51 ;
struct V_52 * V_53 ;
struct V_52 * V_54 ;
F_15 ( V_55 ) ;
F_5 ( & V_2 -> V_46 ) ;
F_13 ( & V_2 -> V_46 , & V_55 ) ;
F_12 ( V_2 -> V_46 . V_41 ) ;
F_16 (inc, inc_tmp, &list, ii_cache_entry) {
F_17 ( & V_50 -> V_56 ) ;
F_18 ( ! F_19 ( & V_50 -> V_57 ) ) ;
F_20 ( V_58 , V_50 ) ;
}
F_5 ( & V_2 -> V_47 ) ;
F_13 ( & V_2 -> V_47 , & V_55 ) ;
F_12 ( V_2 -> V_47 . V_41 ) ;
F_16 (frag, frag_tmp, &list, f_cache_entry) {
F_17 ( & V_53 -> V_59 ) ;
F_18 ( ! F_19 ( & V_53 -> V_60 ) ) ;
F_20 ( V_61 , V_53 ) ;
}
}
static void F_21 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
F_22 ( L_1 , V_53 , F_23 ( & V_53 -> V_62 ) ) ;
F_24 ( & V_53 -> V_59 , & V_2 -> V_47 ) ;
}
void F_25 ( struct V_63 * V_50 )
{
struct V_49 * V_64 ;
struct V_52 * V_53 ;
struct V_52 * V_65 ;
struct V_1 * V_2 = V_50 -> V_66 -> V_67 ;
V_64 = F_26 ( V_50 , struct V_49 , V_68 ) ;
F_16 (frag, pos, &ibinc->ii_frags, f_item) {
F_27 ( & V_53 -> V_60 ) ;
F_21 ( V_2 , V_53 ) ;
}
F_28 ( ! F_19 ( & V_64 -> V_57 ) ) ;
F_22 ( L_2 , V_64 , V_50 ) ;
F_24 ( & V_64 -> V_56 , & V_2 -> V_46 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_11 ) {
F_30 ( & V_4 -> V_11 -> V_68 ) ;
V_4 -> V_11 = NULL ;
}
if ( V_4 -> V_12 ) {
F_31 ( V_2 -> V_69 -> V_70 , & V_4 -> V_12 -> V_62 , 1 , V_71 ) ;
F_21 ( V_2 , V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
}
}
void F_32 ( struct V_1 * V_2 )
{
T_1 V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_7 . V_8 ; V_5 ++ )
F_29 ( V_2 , & V_2 -> V_6 [ V_5 ] ) ;
}
static struct V_49 * F_33 ( struct V_1 * V_2 ,
T_2 V_72 )
{
struct V_49 * V_64 ;
struct V_28 * V_73 ;
int V_74 ;
V_73 = F_34 ( & V_2 -> V_46 ) ;
if ( V_73 ) {
V_64 = F_26 ( V_73 , struct V_49 , V_56 ) ;
} else {
V_74 = F_35 ( & V_75 ,
1 , V_76 ) ;
if ( ! V_74 ) {
F_36 ( V_77 ) ;
return NULL ;
}
V_64 = F_37 ( V_58 , V_72 ) ;
if ( ! V_64 ) {
F_38 ( & V_75 ) ;
return NULL ;
}
}
F_39 ( & V_64 -> V_57 ) ;
F_40 ( & V_64 -> V_68 , V_2 -> V_78 , V_2 -> V_78 -> V_79 ) ;
return V_64 ;
}
static struct V_52 * F_41 ( struct V_1 * V_2 ,
T_2 V_72 , T_2 V_80 )
{
struct V_52 * V_53 ;
struct V_28 * V_73 ;
int V_45 ;
V_73 = F_34 ( & V_2 -> V_47 ) ;
if ( V_73 ) {
V_53 = F_26 ( V_73 , struct V_52 , V_59 ) ;
} else {
V_53 = F_37 ( V_61 , V_72 ) ;
if ( ! V_53 )
return NULL ;
F_42 ( & V_53 -> V_62 , 1 ) ;
V_45 = F_43 ( & V_53 -> V_62 ,
V_27 , V_80 ) ;
if ( V_45 ) {
F_20 ( V_61 , V_53 ) ;
return NULL ;
}
}
F_39 ( & V_53 -> V_60 ) ;
return V_53 ;
}
static int F_44 ( struct V_81 * V_78 ,
struct V_3 * V_4 , T_2 V_82 )
{
struct V_1 * V_2 = V_78 -> V_67 ;
struct V_9 * V_10 ;
int V_45 = - V_42 ;
T_2 V_72 = V_83 ;
T_2 V_80 = V_83 ;
if ( V_82 & V_84 ) {
V_72 = V_85 ;
V_80 = V_86 ;
}
if ( ! V_2 -> V_46 . V_37 )
F_5 ( & V_2 -> V_46 ) ;
if ( ! V_2 -> V_47 . V_37 )
F_5 ( & V_2 -> V_47 ) ;
if ( ! V_4 -> V_11 ) {
V_4 -> V_11 = F_33 ( V_2 , V_72 ) ;
if ( ! V_4 -> V_11 )
goto V_87;
}
F_18 ( V_4 -> V_12 ) ;
V_4 -> V_12 = F_41 ( V_2 , V_72 , V_80 ) ;
if ( ! V_4 -> V_12 )
goto V_87;
V_45 = F_45 ( V_2 -> V_69 -> V_70 , & V_4 -> V_12 -> V_62 ,
1 , V_71 ) ;
F_18 ( V_45 != 1 ) ;
V_10 = & V_4 -> V_17 [ 0 ] ;
V_10 -> V_20 = V_2 -> V_21 + ( V_4 - V_2 -> V_6 ) * sizeof( struct V_22 ) ;
V_10 -> V_23 = sizeof( struct V_22 ) ;
V_10 = & V_4 -> V_17 [ 1 ] ;
V_10 -> V_20 = F_46 ( V_2 -> V_69 -> V_70 , & V_4 -> V_12 -> V_62 ) ;
V_10 -> V_23 = F_47 ( V_2 -> V_69 -> V_70 , & V_4 -> V_12 -> V_62 ) ;
V_45 = 0 ;
V_87:
return V_45 ;
}
static int F_48 ( struct V_81 * V_78 )
{
return F_49 ( V_88 , & V_78 -> V_89 ) == 0 ;
}
static void F_50 ( struct V_81 * V_78 )
{
F_51 ( V_88 , & V_78 -> V_89 ) ;
if ( F_52 ( & V_78 -> V_90 ) )
F_53 ( & V_78 -> V_90 ) ;
}
void F_54 ( struct V_81 * V_78 , int V_91 , T_2 V_82 )
{
struct V_1 * V_2 = V_78 -> V_67 ;
struct V_3 * V_4 ;
struct V_92 * V_93 ;
unsigned int V_94 = 0 ;
int V_45 = 0 ;
bool V_95 = ! ! ( V_82 & V_84 ) ;
T_1 V_65 ;
if ( ! F_48 ( V_78 ) )
return;
while ( ( V_91 || F_55 ( V_78 ) ) &&
F_56 ( & V_2 -> V_7 , 1 , & V_65 ) ) {
if ( V_65 >= V_2 -> V_7 . V_8 ) {
F_57 ( V_96 L_3 ,
V_65 ) ;
break;
}
V_4 = & V_2 -> V_6 [ V_65 ] ;
V_45 = F_44 ( V_78 , V_4 , V_82 ) ;
if ( V_45 ) {
break;
}
V_45 = F_58 ( V_2 -> V_69 -> V_97 , & V_4 -> V_13 , & V_93 ) ;
F_22 ( L_4 , V_4 ,
V_4 -> V_11 , F_23 ( & V_4 -> V_12 -> V_62 ) ,
( long ) F_46 (
V_2 -> V_69 -> V_70 ,
& V_4 -> V_12 -> V_62 ) ,
V_45 ) ;
if ( V_45 ) {
F_59 ( V_78 , L_5
L_6
L_7 , & V_78 -> V_79 ,
V_45 ) ;
break;
}
V_94 ++ ;
}
if ( V_2 -> V_98 && V_94 )
F_60 ( V_78 , V_94 ) ;
if ( V_45 )
F_61 ( & V_2 -> V_7 , 1 ) ;
F_50 ( V_78 ) ;
if ( F_55 ( V_78 ) &&
( ( V_95 && F_62 ( & V_2 -> V_7 ) ) ||
F_63 ( & V_2 -> V_7 ) ) ) {
F_64 ( V_99 , & V_78 -> V_100 , 1 ) ;
}
}
static void F_24 ( struct V_28 * V_101 ,
struct V_33 * V_34 )
{
unsigned long V_102 ;
struct V_28 * V_103 , * V_104 ;
F_65 ( V_102 ) ;
V_104 = F_66 ( V_34 -> V_41 -> V_43 ) ;
if ( ! V_104 )
F_39 ( V_101 ) ;
else
F_4 ( V_101 , V_104 ) ;
F_67 ( V_34 -> V_41 -> V_43 , V_101 ) ;
F_68 ( V_34 -> V_41 -> V_44 ) ;
if ( F_66 ( V_34 -> V_41 -> V_44 ) < V_105 )
goto V_106;
do {
V_103 = F_6 ( & V_34 -> V_36 , NULL ) ;
if ( V_103 )
F_2 ( V_103 , V_104 ) ;
V_103 = F_69 ( & V_34 -> V_36 , NULL , V_104 ) ;
} while ( V_103 );
F_67 ( V_34 -> V_41 -> V_43 , NULL ) ;
F_67 ( V_34 -> V_41 -> V_44 , 0 ) ;
V_106:
F_70 ( V_102 ) ;
}
static struct V_28 * F_34 ( struct V_33 * V_34 )
{
struct V_28 * V_39 = V_34 -> V_37 ;
if ( V_39 ) {
if ( ! F_19 ( V_39 ) ) {
V_34 -> V_37 = V_39 -> V_14 ;
F_27 ( V_39 ) ;
} else
V_34 -> V_37 = NULL ;
}
return V_39 ;
}
int F_71 ( struct V_63 * V_50 , struct V_107 * V_30 )
{
struct V_49 * V_64 ;
struct V_52 * V_53 ;
unsigned long V_108 ;
unsigned long V_109 = 0 ;
int V_110 = 0 ;
int V_45 ;
T_1 V_111 ;
V_64 = F_26 ( V_50 , struct V_49 , V_68 ) ;
V_53 = F_72 ( V_64 -> V_57 . V_14 , struct V_52 , V_60 ) ;
V_111 = F_73 ( V_50 -> V_112 . V_113 ) ;
while ( F_74 ( V_30 ) && V_110 < V_111 ) {
if ( V_109 == V_27 ) {
V_53 = F_72 ( V_53 -> V_60 . V_14 ,
struct V_52 , V_60 ) ;
V_109 = 0 ;
}
V_108 = F_75 (unsigned long, iov_iter_count(to),
RDS_FRAG_SIZE - frag_off) ;
V_108 = F_75 (unsigned long, to_copy, len - copied) ;
F_76 ( V_114 , V_108 ) ;
V_45 = F_77 ( F_23 ( & V_53 -> V_62 ) ,
V_53 -> V_62 . V_115 + V_109 ,
V_108 ,
V_30 ) ;
if ( V_45 != V_108 )
return - V_116 ;
V_109 += V_108 ;
V_110 += V_108 ;
}
return V_110 ;
}
void F_78 ( struct V_1 * V_2 )
{
struct V_117 * V_118 = & V_2 -> V_119 ;
struct V_9 * V_10 = & V_2 -> V_120 ;
V_10 -> V_20 = V_2 -> V_121 ;
V_10 -> V_23 = sizeof( struct V_22 ) ;
V_10 -> V_24 = V_2 -> V_25 -> V_26 ;
V_118 -> V_16 = V_10 ;
V_118 -> V_18 = 1 ;
V_118 -> V_122 = V_123 ;
V_118 -> V_15 = V_124 ;
V_118 -> V_125 = V_126 | V_127 ;
}
static void F_79 ( struct V_1 * V_2 , T_3 V_128 ,
int V_129 )
{
unsigned long V_102 ;
F_80 ( & V_2 -> V_130 , V_102 ) ;
V_2 -> V_131 = V_128 ;
if ( V_129 )
F_81 ( V_132 , & V_2 -> V_133 ) ;
F_82 ( & V_2 -> V_130 , V_102 ) ;
}
static T_3 F_83 ( struct V_1 * V_2 )
{
unsigned long V_102 ;
T_3 V_128 ;
F_51 ( V_132 , & V_2 -> V_133 ) ;
F_80 ( & V_2 -> V_130 , V_102 ) ;
V_128 = V_2 -> V_131 ;
F_82 ( & V_2 -> V_130 , V_102 ) ;
return V_128 ;
}
static void F_79 ( struct V_1 * V_2 , T_3 V_128 ,
int V_129 )
{
F_84 ( & V_2 -> V_131 , V_128 ) ;
if ( V_129 ) {
F_85 () ;
F_81 ( V_132 , & V_2 -> V_133 ) ;
}
}
static T_3 F_83 ( struct V_1 * V_2 )
{
F_51 ( V_132 , & V_2 -> V_133 ) ;
F_86 () ;
return F_87 ( & V_2 -> V_131 ) ;
}
static void F_88 ( struct V_1 * V_2 , unsigned int V_134 )
{
struct V_22 * V_135 = V_2 -> V_136 ;
struct V_117 * V_93 ;
T_3 V_128 ;
int V_45 ;
V_128 = F_83 ( V_2 ) ;
F_22 ( L_8 , V_2 , ( unsigned long long ) V_128 ) ;
F_89 ( V_135 , 0 , 0 , 0 ) ;
V_135 -> V_137 = F_90 ( V_128 ) ;
V_135 -> V_138 = V_134 ;
F_91 ( V_135 ) ;
V_2 -> V_139 = V_140 ;
V_45 = F_92 ( V_2 -> V_69 -> V_97 , & V_2 -> V_119 , & V_93 ) ;
if ( F_93 ( V_45 ) ) {
F_51 ( V_141 , & V_2 -> V_133 ) ;
F_81 ( V_132 , & V_2 -> V_133 ) ;
F_36 ( V_142 ) ;
F_59 ( V_2 -> V_78 , L_9 ) ;
} else
F_36 ( V_143 ) ;
}
void F_94 ( struct V_1 * V_2 )
{
unsigned int V_134 ;
if ( ! F_95 ( V_132 , & V_2 -> V_133 ) )
return;
if ( F_49 ( V_141 , & V_2 -> V_133 ) ) {
F_36 ( V_144 ) ;
return;
}
if ( ! F_96 ( V_2 , 1 , & V_134 , 0 , V_145 ) ) {
F_36 ( V_146 ) ;
F_51 ( V_141 , & V_2 -> V_133 ) ;
return;
}
F_51 ( V_132 , & V_2 -> V_133 ) ;
F_88 ( V_2 , V_134 ) ;
}
void F_97 ( struct V_1 * V_2 )
{
F_51 ( V_141 , & V_2 -> V_133 ) ;
F_94 ( V_2 ) ;
}
T_3 F_98 ( struct V_1 * V_2 )
{
if ( F_99 ( V_132 , & V_2 -> V_133 ) )
F_36 ( V_147 ) ;
return F_83 ( V_2 ) ;
}
static void F_100 ( struct V_81 * V_78 ,
struct V_49 * V_64 )
{
struct V_148 * V_149 ;
unsigned int V_150 ;
unsigned int V_151 ;
struct V_52 * V_53 ;
unsigned long V_109 ;
unsigned long V_108 ;
unsigned long V_110 ;
T_4 V_152 = 0 ;
void * V_20 ;
if ( F_73 ( V_64 -> V_68 . V_112 . V_113 ) != V_153 )
return;
V_149 = V_78 -> V_154 ;
V_151 = 0 ;
V_150 = 0 ;
V_53 = F_72 ( V_64 -> V_57 . V_14 , struct V_52 , V_60 ) ;
V_109 = 0 ;
V_110 = 0 ;
while ( V_110 < V_153 ) {
T_4 * V_155 , * V_156 ;
unsigned int V_157 ;
V_108 = F_101 ( V_27 - V_109 , V_158 - V_150 ) ;
F_28 ( V_108 & 7 ) ;
V_20 = F_102 ( F_23 ( & V_53 -> V_62 ) ) ;
V_155 = V_20 + V_109 ;
V_156 = ( void * ) V_149 -> V_159 [ V_151 ] + V_150 ;
for ( V_157 = 0 ; V_157 < V_108 ; V_157 += 8 ) {
V_152 |= ~ ( * V_155 ) & * V_156 ;
* V_156 ++ = * V_155 ++ ;
}
F_103 ( V_20 ) ;
V_110 += V_108 ;
V_150 += V_108 ;
if ( V_150 == V_158 ) {
V_150 = 0 ;
V_151 ++ ;
}
V_109 += V_108 ;
if ( V_109 == V_27 ) {
V_53 = F_72 ( V_53 -> V_60 . V_14 ,
struct V_52 , V_60 ) ;
V_109 = 0 ;
}
}
V_152 = F_104 ( V_152 ) ;
F_105 ( V_149 , V_152 ) ;
}
static void F_106 ( struct V_81 * V_78 ,
struct V_3 * V_4 , T_1 V_160 ,
struct V_161 * V_162 )
{
struct V_1 * V_2 = V_78 -> V_67 ;
struct V_49 * V_64 = V_2 -> V_163 ;
struct V_22 * V_164 , * V_135 ;
F_22 ( L_10 , V_2 , V_64 , V_4 ,
V_160 ) ;
if ( V_160 < sizeof( struct V_22 ) ) {
F_59 ( V_78 , L_11
L_12
L_13
L_7 ,
& V_78 -> V_79 ) ;
return;
}
V_160 -= sizeof( struct V_22 ) ;
V_164 = & V_2 -> V_165 [ V_4 - V_2 -> V_6 ] ;
if ( ! F_107 ( V_164 ) ) {
F_59 ( V_78 , L_11
L_14
L_15 ,
& V_78 -> V_79 ) ;
F_108 ( V_166 ) ;
return;
}
V_162 -> V_167 = F_109 ( V_164 -> V_137 ) ;
V_162 -> V_168 = 1 ;
if ( V_164 -> V_138 )
F_110 ( V_78 , V_164 -> V_138 ) ;
if ( V_164 -> V_169 == 0 && V_164 -> V_170 == 0 && V_160 == 0 ) {
F_36 ( V_171 ) ;
F_21 ( V_2 , V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
return;
}
if ( ! V_64 ) {
V_64 = V_4 -> V_11 ;
V_4 -> V_11 = NULL ;
V_2 -> V_163 = V_64 ;
V_135 = & V_64 -> V_68 . V_112 ;
memcpy ( V_135 , V_164 , sizeof( * V_135 ) ) ;
V_2 -> V_172 = F_73 ( V_135 -> V_113 ) ;
F_22 ( L_16 , V_2 , V_64 ,
V_2 -> V_172 , V_135 -> V_173 ) ;
} else {
V_135 = & V_64 -> V_68 . V_112 ;
if ( V_135 -> V_174 != V_164 -> V_174 ||
V_135 -> V_113 != V_164 -> V_113 ||
V_135 -> V_169 != V_164 -> V_169 ||
V_135 -> V_170 != V_164 -> V_170 ) {
F_59 ( V_78 ,
L_17 ) ;
return;
}
}
F_4 ( & V_4 -> V_12 -> V_60 , & V_64 -> V_57 ) ;
V_4 -> V_12 = NULL ;
if ( V_2 -> V_172 > V_27 )
V_2 -> V_172 -= V_27 ;
else {
V_2 -> V_172 = 0 ;
V_2 -> V_163 = NULL ;
if ( V_64 -> V_68 . V_112 . V_173 == V_175 )
F_100 ( V_78 , V_64 ) ;
else {
F_111 ( V_78 , V_78 -> V_79 , V_78 -> V_176 ,
& V_64 -> V_68 , V_177 ) ;
V_162 -> V_178 = F_109 ( V_135 -> V_174 ) ;
V_162 -> V_179 = 1 ;
}
if ( V_135 -> V_173 & V_180 ) {
F_108 ( V_181 ) ;
V_162 -> V_129 = 1 ;
}
F_30 ( & V_64 -> V_68 ) ;
}
}
void F_112 ( struct V_182 * V_183 , void * V_184 )
{
struct V_81 * V_78 = V_184 ;
struct V_1 * V_2 = V_78 -> V_67 ;
F_22 ( L_18 , V_78 , V_183 ) ;
F_36 ( V_185 ) ;
F_113 ( & V_2 -> V_186 ) ;
}
static inline void F_114 ( struct V_1 * V_2 ,
struct V_161 * V_162 )
{
struct V_81 * V_78 = V_2 -> V_78 ;
struct V_187 V_188 ;
struct V_3 * V_4 ;
while ( F_115 ( V_2 -> V_189 , 1 , & V_188 ) > 0 ) {
F_22 ( L_19 ,
( unsigned long long ) V_188 . V_15 , V_188 . V_190 ,
F_116 ( V_188 . V_190 ) , V_188 . V_191 ,
F_73 ( V_188 . V_192 . V_193 ) ) ;
F_36 ( V_194 ) ;
V_4 = & V_2 -> V_6 [ F_117 ( & V_2 -> V_7 ) ] ;
F_31 ( V_2 -> V_69 -> V_70 , & V_4 -> V_12 -> V_62 , 1 , V_71 ) ;
if ( V_188 . V_190 == V_195 ) {
F_106 ( V_78 , V_4 , V_188 . V_191 , V_162 ) ;
} else {
if ( F_55 ( V_78 ) || F_118 ( V_78 ) )
F_59 ( V_78 , L_20
L_21
L_7 , & V_78 -> V_79 ,
V_188 . V_190 ,
F_116 ( V_188 . V_190 ) ) ;
}
if ( V_4 -> V_12 ) {
F_21 ( V_2 , V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
}
F_119 ( & V_2 -> V_7 , 1 ) ;
}
}
void F_120 ( unsigned long V_196 )
{
struct V_1 * V_2 = (struct V_1 * ) V_196 ;
struct V_81 * V_78 = V_2 -> V_78 ;
struct V_161 V_162 = { 0 , } ;
F_114 ( V_2 , & V_162 ) ;
F_121 ( V_2 -> V_189 , V_197 ) ;
F_114 ( V_2 , & V_162 ) ;
if ( V_162 . V_179 )
F_79 ( V_2 , V_162 . V_178 , V_162 . V_129 ) ;
if ( V_162 . V_168 && V_162 . V_167 > V_2 -> V_198 ) {
F_122 ( V_78 , V_162 . V_167 , NULL ) ;
V_2 -> V_198 = V_162 . V_167 ;
}
if ( F_55 ( V_78 ) )
F_94 ( V_2 ) ;
if ( F_63 ( & V_2 -> V_7 ) )
F_36 ( V_199 ) ;
if ( F_62 ( & V_2 -> V_7 ) )
F_54 ( V_78 , 0 , V_83 ) ;
}
int F_123 ( struct V_81 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_67 ;
int V_45 = 0 ;
F_22 ( L_22 , V_78 ) ;
if ( F_55 ( V_78 ) ) {
F_94 ( V_2 ) ;
F_54 ( V_78 , 0 , V_85 ) ;
}
return V_45 ;
}
int F_124 ( void )
{
struct V_200 V_201 ;
int V_45 = - V_42 ;
F_125 ( & V_201 ) ;
V_76 = V_201 . V_202 / 3 * V_158 / V_27 ;
V_58 = F_126 ( L_23 ,
sizeof( struct V_49 ) ,
0 , V_203 , NULL ) ;
if ( ! V_58 )
goto V_87;
V_61 = F_126 ( L_24 ,
sizeof( struct V_52 ) ,
0 , V_203 , NULL ) ;
if ( ! V_61 ) {
F_127 ( V_58 ) ;
V_58 = NULL ;
} else
V_45 = 0 ;
V_87:
return V_45 ;
}
void F_128 ( void )
{
F_127 ( V_58 ) ;
F_127 ( V_61 ) ;
}
