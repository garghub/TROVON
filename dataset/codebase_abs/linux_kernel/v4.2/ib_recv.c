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
V_10 -> V_24 = V_2 -> V_25 -> V_24 ;
V_10 = & V_4 -> V_17 [ 1 ] ;
V_10 -> V_20 = 0 ;
V_10 -> V_23 = V_26 ;
V_10 -> V_24 = V_2 -> V_25 -> V_24 ;
}
}
static void F_2 ( struct V_27 * V_28 ,
struct V_27 * V_29 )
{
struct V_27 * V_30 = V_28 -> V_31 ;
F_3 ( V_30 , V_29 ) ;
F_4 ( V_30 , V_29 ) ;
}
static void F_5 ( struct V_32 * V_33 )
{
struct V_27 * V_34 ;
V_34 = F_6 ( & V_33 -> V_35 , NULL ) ;
if ( V_34 ) {
if ( V_33 -> V_36 )
F_2 ( V_34 , V_33 -> V_36 ) ;
else
V_33 -> V_36 = V_34 ;
}
}
static int F_7 ( struct V_32 * V_33 )
{
struct V_37 * V_38 ;
int V_39 ;
V_33 -> V_40 = F_8 ( struct V_37 ) ;
if ( ! V_33 -> V_40 )
return - V_41 ;
F_9 (cpu) {
V_38 = F_10 ( V_33 -> V_40 , V_39 ) ;
V_38 -> V_42 = NULL ;
V_38 -> V_43 = 0 ;
}
V_33 -> V_35 = NULL ;
V_33 -> V_36 = NULL ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_44 ;
V_44 = F_7 ( & V_2 -> V_45 ) ;
if ( ! V_44 ) {
V_44 = F_7 ( & V_2 -> V_46 ) ;
if ( V_44 )
F_12 ( V_2 -> V_45 . V_40 ) ;
}
return V_44 ;
}
static void F_13 ( struct V_32 * V_33 ,
struct V_27 * V_47 )
{
struct V_37 * V_38 ;
int V_39 ;
F_9 (cpu) {
V_38 = F_10 ( V_33 -> V_40 , V_39 ) ;
if ( V_38 -> V_42 ) {
F_2 ( V_38 -> V_42 , V_47 ) ;
V_38 -> V_42 = NULL ;
}
}
if ( V_33 -> V_36 ) {
F_2 ( V_33 -> V_36 , V_47 ) ;
V_33 -> V_36 = NULL ;
}
}
void F_14 ( struct V_1 * V_2 )
{
struct V_48 * V_49 ;
struct V_48 * V_50 ;
struct V_51 * V_52 ;
struct V_51 * V_53 ;
F_15 ( V_54 ) ;
F_5 ( & V_2 -> V_45 ) ;
F_13 ( & V_2 -> V_45 , & V_54 ) ;
F_12 ( V_2 -> V_45 . V_40 ) ;
F_16 (inc, inc_tmp, &list, ii_cache_entry) {
F_17 ( & V_49 -> V_55 ) ;
F_18 ( ! F_19 ( & V_49 -> V_56 ) ) ;
F_20 ( V_57 , V_49 ) ;
}
F_5 ( & V_2 -> V_46 ) ;
F_13 ( & V_2 -> V_46 , & V_54 ) ;
F_12 ( V_2 -> V_46 . V_40 ) ;
F_16 (frag, frag_tmp, &list, f_cache_entry) {
F_17 ( & V_52 -> V_58 ) ;
F_18 ( ! F_19 ( & V_52 -> V_59 ) ) ;
F_20 ( V_60 , V_52 ) ;
}
}
static void F_21 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
F_22 ( L_1 , V_52 , F_23 ( & V_52 -> V_61 ) ) ;
F_24 ( & V_52 -> V_58 , & V_2 -> V_46 ) ;
}
void F_25 ( struct V_62 * V_49 )
{
struct V_48 * V_63 ;
struct V_51 * V_52 ;
struct V_51 * V_64 ;
struct V_1 * V_2 = V_49 -> V_65 -> V_66 ;
V_63 = F_26 ( V_49 , struct V_48 , V_67 ) ;
F_16 (frag, pos, &ibinc->ii_frags, f_item) {
F_27 ( & V_52 -> V_59 ) ;
F_21 ( V_2 , V_52 ) ;
}
F_28 ( ! F_19 ( & V_63 -> V_56 ) ) ;
F_22 ( L_2 , V_63 , V_49 ) ;
F_24 ( & V_63 -> V_55 , & V_2 -> V_45 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_11 ) {
F_30 ( & V_4 -> V_11 -> V_67 ) ;
V_4 -> V_11 = NULL ;
}
if ( V_4 -> V_12 ) {
F_31 ( V_2 -> V_68 -> V_69 , & V_4 -> V_12 -> V_61 , 1 , V_70 ) ;
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
static struct V_48 * F_33 ( struct V_1 * V_2 ,
T_2 V_71 )
{
struct V_48 * V_63 ;
struct V_27 * V_72 ;
int V_73 ;
V_72 = F_34 ( & V_2 -> V_45 ) ;
if ( V_72 ) {
V_63 = F_26 ( V_72 , struct V_48 , V_55 ) ;
} else {
V_73 = F_35 ( & V_74 ,
1 , V_75 ) ;
if ( ! V_73 ) {
F_36 ( V_76 ) ;
return NULL ;
}
V_63 = F_37 ( V_57 , V_71 ) ;
if ( ! V_63 ) {
F_38 ( & V_74 ) ;
return NULL ;
}
}
F_39 ( & V_63 -> V_56 ) ;
F_40 ( & V_63 -> V_67 , V_2 -> V_77 , V_2 -> V_77 -> V_78 ) ;
return V_63 ;
}
static struct V_51 * F_41 ( struct V_1 * V_2 ,
T_2 V_71 , T_2 V_79 )
{
struct V_51 * V_52 ;
struct V_27 * V_72 ;
int V_44 ;
V_72 = F_34 ( & V_2 -> V_46 ) ;
if ( V_72 ) {
V_52 = F_26 ( V_72 , struct V_51 , V_58 ) ;
} else {
V_52 = F_37 ( V_60 , V_71 ) ;
if ( ! V_52 )
return NULL ;
F_42 ( & V_52 -> V_61 , 1 ) ;
V_44 = F_43 ( & V_52 -> V_61 ,
V_26 , V_79 ) ;
if ( V_44 ) {
F_20 ( V_60 , V_52 ) ;
return NULL ;
}
}
F_39 ( & V_52 -> V_59 ) ;
return V_52 ;
}
static int F_44 ( struct V_80 * V_77 ,
struct V_3 * V_4 , int V_81 )
{
struct V_1 * V_2 = V_77 -> V_66 ;
struct V_9 * V_10 ;
int V_44 = - V_41 ;
T_2 V_71 = V_82 ;
T_2 V_79 = V_82 ;
if ( V_81 ) {
V_71 = V_83 ;
V_79 = V_84 ;
}
if ( ! V_2 -> V_45 . V_36 )
F_5 ( & V_2 -> V_45 ) ;
if ( ! V_2 -> V_46 . V_36 )
F_5 ( & V_2 -> V_46 ) ;
if ( ! V_4 -> V_11 ) {
V_4 -> V_11 = F_33 ( V_2 , V_71 ) ;
if ( ! V_4 -> V_11 )
goto V_85;
}
F_18 ( V_4 -> V_12 ) ;
V_4 -> V_12 = F_41 ( V_2 , V_71 , V_79 ) ;
if ( ! V_4 -> V_12 )
goto V_85;
V_44 = F_45 ( V_2 -> V_68 -> V_69 , & V_4 -> V_12 -> V_61 ,
1 , V_70 ) ;
F_18 ( V_44 != 1 ) ;
V_10 = & V_4 -> V_17 [ 0 ] ;
V_10 -> V_20 = V_2 -> V_21 + ( V_4 - V_2 -> V_6 ) * sizeof( struct V_22 ) ;
V_10 -> V_23 = sizeof( struct V_22 ) ;
V_10 = & V_4 -> V_17 [ 1 ] ;
V_10 -> V_20 = F_46 ( V_2 -> V_68 -> V_69 , & V_4 -> V_12 -> V_61 ) ;
V_10 -> V_23 = F_47 ( V_2 -> V_68 -> V_69 , & V_4 -> V_12 -> V_61 ) ;
V_44 = 0 ;
V_85:
return V_44 ;
}
void F_48 ( struct V_80 * V_77 , int V_81 )
{
struct V_1 * V_2 = V_77 -> V_66 ;
struct V_3 * V_4 ;
struct V_86 * V_87 ;
unsigned int V_88 = 0 ;
int V_44 = 0 ;
T_1 V_64 ;
while ( ( V_81 || F_49 ( V_77 ) ) &&
F_50 ( & V_2 -> V_7 , 1 , & V_64 ) ) {
if ( V_64 >= V_2 -> V_7 . V_8 ) {
F_51 ( V_89 L_3 ,
V_64 ) ;
break;
}
V_4 = & V_2 -> V_6 [ V_64 ] ;
V_44 = F_44 ( V_77 , V_4 , V_81 ) ;
if ( V_44 ) {
break;
}
V_44 = F_52 ( V_2 -> V_68 -> V_90 , & V_4 -> V_13 , & V_87 ) ;
F_22 ( L_4 , V_4 ,
V_4 -> V_11 , F_23 ( & V_4 -> V_12 -> V_61 ) ,
( long ) F_46 (
V_2 -> V_68 -> V_69 ,
& V_4 -> V_12 -> V_61 ) ,
V_44 ) ;
if ( V_44 ) {
F_53 ( V_77 , L_5
L_6
L_7 , & V_77 -> V_78 ,
V_44 ) ;
break;
}
V_88 ++ ;
}
if ( V_2 -> V_91 && V_88 )
F_54 ( V_77 , V_88 ) ;
if ( V_44 )
F_55 ( & V_2 -> V_7 , 1 ) ;
}
static void F_24 ( struct V_27 * V_92 ,
struct V_32 * V_33 )
{
unsigned long V_93 ;
struct V_27 * V_94 , * V_95 ;
F_56 ( V_93 ) ;
V_95 = F_57 ( V_33 -> V_40 -> V_42 ) ;
if ( ! V_95 )
F_39 ( V_92 ) ;
else
F_4 ( V_92 , V_95 ) ;
F_58 ( V_33 -> V_40 -> V_42 , V_92 ) ;
F_59 ( V_33 -> V_40 -> V_43 ) ;
if ( F_57 ( V_33 -> V_40 -> V_43 ) < V_96 )
goto V_97;
do {
V_94 = F_6 ( & V_33 -> V_35 , NULL ) ;
if ( V_94 )
F_2 ( V_94 , V_95 ) ;
V_94 = F_60 ( & V_33 -> V_35 , NULL , V_95 ) ;
} while ( V_94 );
F_58 ( V_33 -> V_40 -> V_42 , NULL ) ;
F_58 ( V_33 -> V_40 -> V_43 , 0 ) ;
V_97:
F_61 ( V_93 ) ;
}
static struct V_27 * F_34 ( struct V_32 * V_33 )
{
struct V_27 * V_38 = V_33 -> V_36 ;
if ( V_38 ) {
if ( ! F_19 ( V_38 ) ) {
V_33 -> V_36 = V_38 -> V_14 ;
F_27 ( V_38 ) ;
} else
V_33 -> V_36 = NULL ;
}
return V_38 ;
}
int F_62 ( struct V_62 * V_49 , struct V_98 * V_29 )
{
struct V_48 * V_63 ;
struct V_51 * V_52 ;
unsigned long V_99 ;
unsigned long V_100 = 0 ;
int V_101 = 0 ;
int V_44 ;
T_1 V_102 ;
V_63 = F_26 ( V_49 , struct V_48 , V_67 ) ;
V_52 = F_63 ( V_63 -> V_56 . V_14 , struct V_51 , V_59 ) ;
V_102 = F_64 ( V_49 -> V_103 . V_104 ) ;
while ( F_65 ( V_29 ) && V_101 < V_102 ) {
if ( V_100 == V_26 ) {
V_52 = F_63 ( V_52 -> V_59 . V_14 ,
struct V_51 , V_59 ) ;
V_100 = 0 ;
}
V_99 = F_66 (unsigned long, iov_iter_count(to),
RDS_FRAG_SIZE - frag_off) ;
V_99 = F_66 (unsigned long, to_copy, len - copied) ;
F_67 ( V_105 , V_99 ) ;
V_44 = F_68 ( F_23 ( & V_52 -> V_61 ) ,
V_52 -> V_61 . V_106 + V_100 ,
V_99 ,
V_29 ) ;
if ( V_44 != V_99 )
return - V_107 ;
V_100 += V_99 ;
V_101 += V_99 ;
}
return V_101 ;
}
void F_69 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = & V_2 -> V_110 ;
struct V_9 * V_10 = & V_2 -> V_111 ;
V_10 -> V_20 = V_2 -> V_112 ;
V_10 -> V_23 = sizeof( struct V_22 ) ;
V_10 -> V_24 = V_2 -> V_25 -> V_24 ;
V_109 -> V_16 = V_10 ;
V_109 -> V_18 = 1 ;
V_109 -> V_113 = V_114 ;
V_109 -> V_15 = V_115 ;
V_109 -> V_116 = V_117 | V_118 ;
}
static void F_70 ( struct V_1 * V_2 , T_3 V_119 ,
int V_120 )
{
unsigned long V_93 ;
F_71 ( & V_2 -> V_121 , V_93 ) ;
V_2 -> V_122 = V_119 ;
if ( V_120 )
F_72 ( V_123 , & V_2 -> V_124 ) ;
F_73 ( & V_2 -> V_121 , V_93 ) ;
}
static T_3 F_74 ( struct V_1 * V_2 )
{
unsigned long V_93 ;
T_3 V_119 ;
F_75 ( V_123 , & V_2 -> V_124 ) ;
F_71 ( & V_2 -> V_121 , V_93 ) ;
V_119 = V_2 -> V_122 ;
F_73 ( & V_2 -> V_121 , V_93 ) ;
return V_119 ;
}
static void F_70 ( struct V_1 * V_2 , T_3 V_119 ,
int V_120 )
{
F_76 ( & V_2 -> V_122 , V_119 ) ;
if ( V_120 ) {
F_77 () ;
F_72 ( V_123 , & V_2 -> V_124 ) ;
}
}
static T_3 F_74 ( struct V_1 * V_2 )
{
F_75 ( V_123 , & V_2 -> V_124 ) ;
F_78 () ;
return F_79 ( & V_2 -> V_122 ) ;
}
static void F_80 ( struct V_1 * V_2 , unsigned int V_125 )
{
struct V_22 * V_126 = V_2 -> V_127 ;
struct V_108 * V_87 ;
T_3 V_119 ;
int V_44 ;
V_119 = F_74 ( V_2 ) ;
F_22 ( L_8 , V_2 , ( unsigned long long ) V_119 ) ;
F_81 ( V_126 , 0 , 0 , 0 ) ;
V_126 -> V_128 = F_82 ( V_119 ) ;
V_126 -> V_129 = V_125 ;
F_83 ( V_126 ) ;
V_2 -> V_130 = V_131 ;
V_44 = F_84 ( V_2 -> V_68 -> V_90 , & V_2 -> V_110 , & V_87 ) ;
if ( F_85 ( V_44 ) ) {
F_75 ( V_132 , & V_2 -> V_124 ) ;
F_72 ( V_123 , & V_2 -> V_124 ) ;
F_36 ( V_133 ) ;
F_53 ( V_2 -> V_77 , L_9 ) ;
} else
F_36 ( V_134 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
unsigned int V_125 ;
if ( ! F_87 ( V_123 , & V_2 -> V_124 ) )
return;
if ( F_88 ( V_132 , & V_2 -> V_124 ) ) {
F_36 ( V_135 ) ;
return;
}
if ( ! F_89 ( V_2 , 1 , & V_125 , 0 , V_136 ) ) {
F_36 ( V_137 ) ;
F_75 ( V_132 , & V_2 -> V_124 ) ;
return;
}
F_75 ( V_123 , & V_2 -> V_124 ) ;
F_80 ( V_2 , V_125 ) ;
}
void F_90 ( struct V_1 * V_2 )
{
F_75 ( V_132 , & V_2 -> V_124 ) ;
F_86 ( V_2 ) ;
}
T_3 F_91 ( struct V_1 * V_2 )
{
if ( F_92 ( V_123 , & V_2 -> V_124 ) )
F_36 ( V_138 ) ;
return F_74 ( V_2 ) ;
}
static void F_93 ( struct V_80 * V_77 ,
struct V_48 * V_63 )
{
struct V_139 * V_140 ;
unsigned int V_141 ;
unsigned int V_142 ;
struct V_51 * V_52 ;
unsigned long V_100 ;
unsigned long V_99 ;
unsigned long V_101 ;
T_4 V_143 = 0 ;
void * V_20 ;
if ( F_64 ( V_63 -> V_67 . V_103 . V_104 ) != V_144 )
return;
V_140 = V_77 -> V_145 ;
V_142 = 0 ;
V_141 = 0 ;
V_52 = F_63 ( V_63 -> V_56 . V_14 , struct V_51 , V_59 ) ;
V_100 = 0 ;
V_101 = 0 ;
while ( V_101 < V_144 ) {
T_4 * V_146 , * V_147 ;
unsigned int V_148 ;
V_99 = F_94 ( V_26 - V_100 , V_149 - V_141 ) ;
F_28 ( V_99 & 7 ) ;
V_20 = F_95 ( F_23 ( & V_52 -> V_61 ) ) ;
V_146 = V_20 + V_100 ;
V_147 = ( void * ) V_140 -> V_150 [ V_142 ] + V_141 ;
for ( V_148 = 0 ; V_148 < V_99 ; V_148 += 8 ) {
V_143 |= ~ ( * V_146 ) & * V_147 ;
* V_147 ++ = * V_146 ++ ;
}
F_96 ( V_20 ) ;
V_101 += V_99 ;
V_141 += V_99 ;
if ( V_141 == V_149 ) {
V_141 = 0 ;
V_142 ++ ;
}
V_100 += V_99 ;
if ( V_100 == V_26 ) {
V_52 = F_63 ( V_52 -> V_59 . V_14 ,
struct V_51 , V_59 ) ;
V_100 = 0 ;
}
}
V_143 = F_97 ( V_143 ) ;
F_98 ( V_140 , V_143 ) ;
}
static void F_99 ( struct V_80 * V_77 ,
struct V_3 * V_4 , T_1 V_151 ,
struct V_152 * V_153 )
{
struct V_1 * V_2 = V_77 -> V_66 ;
struct V_48 * V_63 = V_2 -> V_154 ;
struct V_22 * V_155 , * V_126 ;
F_22 ( L_10 , V_2 , V_63 , V_4 ,
V_151 ) ;
if ( V_151 < sizeof( struct V_22 ) ) {
F_53 ( V_77 , L_11
L_12
L_13
L_7 ,
& V_77 -> V_78 ) ;
return;
}
V_151 -= sizeof( struct V_22 ) ;
V_155 = & V_2 -> V_156 [ V_4 - V_2 -> V_6 ] ;
if ( ! F_100 ( V_155 ) ) {
F_53 ( V_77 , L_11
L_14
L_15 ,
& V_77 -> V_78 ) ;
F_101 ( V_157 ) ;
return;
}
V_153 -> V_158 = F_102 ( V_155 -> V_128 ) ;
V_153 -> V_159 = 1 ;
if ( V_155 -> V_129 )
F_103 ( V_77 , V_155 -> V_129 ) ;
if ( V_155 -> V_160 == 0 && V_155 -> V_161 == 0 && V_151 == 0 ) {
F_36 ( V_162 ) ;
F_21 ( V_2 , V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
return;
}
if ( ! V_63 ) {
V_63 = V_4 -> V_11 ;
V_4 -> V_11 = NULL ;
V_2 -> V_154 = V_63 ;
V_126 = & V_63 -> V_67 . V_103 ;
memcpy ( V_126 , V_155 , sizeof( * V_126 ) ) ;
V_2 -> V_163 = F_64 ( V_126 -> V_104 ) ;
F_22 ( L_16 , V_2 , V_63 ,
V_2 -> V_163 , V_126 -> V_164 ) ;
} else {
V_126 = & V_63 -> V_67 . V_103 ;
if ( V_126 -> V_165 != V_155 -> V_165 ||
V_126 -> V_104 != V_155 -> V_104 ||
V_126 -> V_160 != V_155 -> V_160 ||
V_126 -> V_161 != V_155 -> V_161 ) {
F_53 ( V_77 ,
L_17 ) ;
return;
}
}
F_4 ( & V_4 -> V_12 -> V_59 , & V_63 -> V_56 ) ;
V_4 -> V_12 = NULL ;
if ( V_2 -> V_163 > V_26 )
V_2 -> V_163 -= V_26 ;
else {
V_2 -> V_163 = 0 ;
V_2 -> V_154 = NULL ;
if ( V_63 -> V_67 . V_103 . V_164 == V_166 )
F_93 ( V_77 , V_63 ) ;
else {
F_104 ( V_77 , V_77 -> V_78 , V_77 -> V_167 ,
& V_63 -> V_67 , V_168 ) ;
V_153 -> V_169 = F_102 ( V_126 -> V_165 ) ;
V_153 -> V_170 = 1 ;
}
if ( V_126 -> V_164 & V_171 ) {
F_101 ( V_172 ) ;
V_153 -> V_120 = 1 ;
}
F_30 ( & V_63 -> V_67 ) ;
}
}
void F_105 ( struct V_173 * V_174 , void * V_175 )
{
struct V_80 * V_77 = V_175 ;
struct V_1 * V_2 = V_77 -> V_66 ;
F_22 ( L_18 , V_77 , V_174 ) ;
F_36 ( V_176 ) ;
F_106 ( & V_2 -> V_177 ) ;
}
static inline void F_107 ( struct V_1 * V_2 ,
struct V_152 * V_153 )
{
struct V_80 * V_77 = V_2 -> V_77 ;
struct V_178 V_179 ;
struct V_3 * V_4 ;
while ( F_108 ( V_2 -> V_180 , 1 , & V_179 ) > 0 ) {
F_22 ( L_19 ,
( unsigned long long ) V_179 . V_15 , V_179 . V_181 ,
F_109 ( V_179 . V_181 ) , V_179 . V_182 ,
F_64 ( V_179 . V_183 . V_184 ) ) ;
F_36 ( V_185 ) ;
V_4 = & V_2 -> V_6 [ F_110 ( & V_2 -> V_7 ) ] ;
F_31 ( V_2 -> V_68 -> V_69 , & V_4 -> V_12 -> V_61 , 1 , V_70 ) ;
if ( V_179 . V_181 == V_186 ) {
F_99 ( V_77 , V_4 , V_179 . V_182 , V_153 ) ;
} else {
if ( F_49 ( V_77 ) || F_111 ( V_77 ) )
F_53 ( V_77 , L_20
L_21
L_7 , & V_77 -> V_78 ,
V_179 . V_181 ,
F_109 ( V_179 . V_181 ) ) ;
}
F_112 ( & V_2 -> V_7 , 1 ) ;
}
}
void F_113 ( unsigned long V_187 )
{
struct V_1 * V_2 = (struct V_1 * ) V_187 ;
struct V_80 * V_77 = V_2 -> V_77 ;
struct V_152 V_153 = { 0 , } ;
F_107 ( V_2 , & V_153 ) ;
F_114 ( V_2 -> V_180 , V_188 ) ;
F_107 ( V_2 , & V_153 ) ;
if ( V_153 . V_170 )
F_70 ( V_2 , V_153 . V_169 , V_153 . V_120 ) ;
if ( V_153 . V_159 && V_153 . V_158 > V_2 -> V_189 ) {
F_115 ( V_77 , V_153 . V_158 , NULL ) ;
V_2 -> V_189 = V_153 . V_158 ;
}
if ( F_49 ( V_77 ) )
F_86 ( V_2 ) ;
if ( F_116 ( & V_2 -> V_7 ) )
F_36 ( V_190 ) ;
if ( F_117 ( & V_2 -> V_7 ) )
F_48 ( V_77 , 0 ) ;
}
int F_118 ( struct V_80 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_66 ;
int V_44 = 0 ;
F_22 ( L_22 , V_77 ) ;
if ( F_49 ( V_77 ) )
F_86 ( V_2 ) ;
return V_44 ;
}
int F_119 ( void )
{
struct V_191 V_192 ;
int V_44 = - V_41 ;
F_120 ( & V_192 ) ;
V_75 = V_192 . V_193 / 3 * V_149 / V_26 ;
V_57 = F_121 ( L_23 ,
sizeof( struct V_48 ) ,
0 , V_194 , NULL ) ;
if ( ! V_57 )
goto V_85;
V_60 = F_121 ( L_24 ,
sizeof( struct V_51 ) ,
0 , V_194 , NULL ) ;
if ( ! V_60 )
F_122 ( V_57 ) ;
else
V_44 = 0 ;
V_85:
return V_44 ;
}
void F_123 ( void )
{
F_122 ( V_57 ) ;
F_122 ( V_60 ) ;
}
