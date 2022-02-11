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
F_25 ( V_27 / V_63 , & V_2 -> V_64 ) ;
F_26 ( V_65 , V_27 ) ;
}
void F_27 ( struct V_66 * V_50 )
{
struct V_49 * V_67 ;
struct V_52 * V_53 ;
struct V_52 * V_68 ;
struct V_1 * V_2 = V_50 -> V_69 -> V_70 ;
V_67 = F_28 ( V_50 , struct V_49 , V_71 ) ;
F_16 (frag, pos, &ibinc->ii_frags, f_item) {
F_29 ( & V_53 -> V_60 ) ;
F_21 ( V_2 , V_53 ) ;
}
F_30 ( ! F_19 ( & V_67 -> V_57 ) ) ;
F_22 ( L_2 , V_67 , V_50 ) ;
F_24 ( & V_67 -> V_56 , & V_2 -> V_46 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_11 ) {
F_32 ( & V_4 -> V_11 -> V_71 ) ;
V_4 -> V_11 = NULL ;
}
if ( V_4 -> V_12 ) {
F_33 ( V_2 -> V_72 -> V_73 , & V_4 -> V_12 -> V_62 , 1 , V_74 ) ;
F_21 ( V_2 , V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
}
}
void F_34 ( struct V_1 * V_2 )
{
T_1 V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_7 . V_8 ; V_5 ++ )
F_31 ( V_2 , & V_2 -> V_6 [ V_5 ] ) ;
}
static struct V_49 * F_35 ( struct V_1 * V_2 ,
T_2 V_75 )
{
struct V_49 * V_67 ;
struct V_28 * V_76 ;
int V_77 ;
V_76 = F_36 ( & V_2 -> V_46 ) ;
if ( V_76 ) {
V_67 = F_28 ( V_76 , struct V_49 , V_56 ) ;
} else {
V_77 = F_37 ( & V_78 ,
1 , V_79 ) ;
if ( ! V_77 ) {
F_38 ( V_80 ) ;
return NULL ;
}
V_67 = F_39 ( V_58 , V_75 ) ;
if ( ! V_67 ) {
F_40 ( & V_78 ) ;
return NULL ;
}
F_38 ( V_81 ) ;
}
F_41 ( & V_67 -> V_57 ) ;
F_42 ( & V_67 -> V_71 , V_2 -> V_82 , V_2 -> V_82 -> V_83 ) ;
return V_67 ;
}
static struct V_52 * F_43 ( struct V_1 * V_2 ,
T_2 V_75 , T_2 V_84 )
{
struct V_52 * V_53 ;
struct V_28 * V_76 ;
int V_45 ;
V_76 = F_36 ( & V_2 -> V_47 ) ;
if ( V_76 ) {
V_53 = F_28 ( V_76 , struct V_52 , V_59 ) ;
F_44 ( V_27 / V_63 , & V_2 -> V_64 ) ;
F_26 ( V_65 , V_27 ) ;
} else {
V_53 = F_39 ( V_61 , V_75 ) ;
if ( ! V_53 )
return NULL ;
F_45 ( & V_53 -> V_62 , 1 ) ;
V_45 = F_46 ( & V_53 -> V_62 ,
V_27 , V_84 ) ;
if ( V_45 ) {
F_20 ( V_61 , V_53 ) ;
return NULL ;
}
F_38 ( V_85 ) ;
}
F_41 ( & V_53 -> V_60 ) ;
return V_53 ;
}
static int F_47 ( struct V_86 * V_82 ,
struct V_3 * V_4 , T_2 V_87 )
{
struct V_1 * V_2 = V_82 -> V_70 ;
struct V_9 * V_10 ;
int V_45 = - V_42 ;
T_2 V_75 = V_88 ;
T_2 V_84 = V_88 ;
if ( V_87 & V_89 ) {
V_75 = V_90 ;
V_84 = V_91 ;
}
if ( ! V_2 -> V_46 . V_37 )
F_5 ( & V_2 -> V_46 ) ;
if ( ! V_2 -> V_47 . V_37 )
F_5 ( & V_2 -> V_47 ) ;
if ( ! V_4 -> V_11 ) {
V_4 -> V_11 = F_35 ( V_2 , V_75 ) ;
if ( ! V_4 -> V_11 )
goto V_92;
}
F_18 ( V_4 -> V_12 ) ;
V_4 -> V_12 = F_43 ( V_2 , V_75 , V_84 ) ;
if ( ! V_4 -> V_12 )
goto V_92;
V_45 = F_48 ( V_2 -> V_72 -> V_73 , & V_4 -> V_12 -> V_62 ,
1 , V_74 ) ;
F_18 ( V_45 != 1 ) ;
V_10 = & V_4 -> V_17 [ 0 ] ;
V_10 -> V_20 = V_2 -> V_21 + ( V_4 - V_2 -> V_6 ) * sizeof( struct V_22 ) ;
V_10 -> V_23 = sizeof( struct V_22 ) ;
V_10 = & V_4 -> V_17 [ 1 ] ;
V_10 -> V_20 = F_49 ( V_2 -> V_72 -> V_73 , & V_4 -> V_12 -> V_62 ) ;
V_10 -> V_23 = F_50 ( V_2 -> V_72 -> V_73 , & V_4 -> V_12 -> V_62 ) ;
V_45 = 0 ;
V_92:
return V_45 ;
}
static int F_51 ( struct V_86 * V_82 )
{
return F_52 ( V_93 , & V_82 -> V_94 ) == 0 ;
}
static void F_53 ( struct V_86 * V_82 )
{
F_54 ( V_93 , & V_82 -> V_94 ) ;
if ( F_55 ( & V_82 -> V_95 ) )
F_56 ( & V_82 -> V_95 ) ;
}
void F_57 ( struct V_86 * V_82 , int V_96 , T_2 V_87 )
{
struct V_1 * V_2 = V_82 -> V_70 ;
struct V_3 * V_4 ;
struct V_97 * V_98 ;
unsigned int V_99 = 0 ;
int V_45 = 0 ;
bool V_100 = ! ! ( V_87 & V_89 ) ;
T_1 V_68 ;
if ( ! F_51 ( V_82 ) )
return;
while ( ( V_96 || F_58 ( V_82 ) ) &&
F_59 ( & V_2 -> V_7 , 1 , & V_68 ) ) {
if ( V_68 >= V_2 -> V_7 . V_8 ) {
F_60 ( V_101 L_3 ,
V_68 ) ;
break;
}
V_4 = & V_2 -> V_6 [ V_68 ] ;
V_45 = F_47 ( V_82 , V_4 , V_87 ) ;
if ( V_45 ) {
break;
}
V_45 = F_61 ( V_2 -> V_72 -> V_102 , & V_4 -> V_13 , & V_98 ) ;
F_22 ( L_4 , V_4 ,
V_4 -> V_11 , F_23 ( & V_4 -> V_12 -> V_62 ) ,
( long ) F_49 (
V_2 -> V_72 -> V_73 ,
& V_4 -> V_12 -> V_62 ) ,
V_45 ) ;
if ( V_45 ) {
F_62 ( V_82 , L_5
L_6
L_7 , & V_82 -> V_83 ,
V_45 ) ;
break;
}
V_99 ++ ;
}
if ( V_2 -> V_103 && V_99 )
F_63 ( V_82 , V_99 ) ;
if ( V_45 )
F_64 ( & V_2 -> V_7 , 1 ) ;
F_53 ( V_82 ) ;
if ( F_58 ( V_82 ) &&
( ( V_100 && F_65 ( & V_2 -> V_7 ) ) ||
F_66 ( & V_2 -> V_7 ) ) ) {
F_67 ( V_104 , & V_82 -> V_105 , 1 ) ;
}
}
static void F_24 ( struct V_28 * V_106 ,
struct V_33 * V_34 )
{
unsigned long V_107 ;
struct V_28 * V_108 , * V_109 ;
F_68 ( V_107 ) ;
V_109 = F_69 ( V_34 -> V_41 -> V_43 ) ;
if ( ! V_109 )
F_41 ( V_106 ) ;
else
F_4 ( V_106 , V_109 ) ;
F_70 ( V_34 -> V_41 -> V_43 , V_106 ) ;
F_71 ( V_34 -> V_41 -> V_44 ) ;
if ( F_69 ( V_34 -> V_41 -> V_44 ) < V_110 )
goto V_111;
do {
V_108 = F_6 ( & V_34 -> V_36 , NULL ) ;
if ( V_108 )
F_2 ( V_108 , V_109 ) ;
V_108 = F_72 ( & V_34 -> V_36 , NULL , V_109 ) ;
} while ( V_108 );
F_70 ( V_34 -> V_41 -> V_43 , NULL ) ;
F_70 ( V_34 -> V_41 -> V_44 , 0 ) ;
V_111:
F_73 ( V_107 ) ;
}
static struct V_28 * F_36 ( struct V_33 * V_34 )
{
struct V_28 * V_39 = V_34 -> V_37 ;
if ( V_39 ) {
if ( ! F_19 ( V_39 ) ) {
V_34 -> V_37 = V_39 -> V_14 ;
F_29 ( V_39 ) ;
} else
V_34 -> V_37 = NULL ;
}
return V_39 ;
}
int F_74 ( struct V_66 * V_50 , struct V_112 * V_30 )
{
struct V_49 * V_67 ;
struct V_52 * V_53 ;
unsigned long V_113 ;
unsigned long V_114 = 0 ;
int V_115 = 0 ;
int V_45 ;
T_1 V_116 ;
V_67 = F_28 ( V_50 , struct V_49 , V_71 ) ;
V_53 = F_75 ( V_67 -> V_57 . V_14 , struct V_52 , V_60 ) ;
V_116 = F_76 ( V_50 -> V_117 . V_118 ) ;
while ( F_77 ( V_30 ) && V_115 < V_116 ) {
if ( V_114 == V_27 ) {
V_53 = F_75 ( V_53 -> V_60 . V_14 ,
struct V_52 , V_60 ) ;
V_114 = 0 ;
}
V_113 = F_78 (unsigned long, iov_iter_count(to),
RDS_FRAG_SIZE - frag_off) ;
V_113 = F_78 (unsigned long, to_copy, len - copied) ;
F_79 ( V_119 , V_113 ) ;
V_45 = F_80 ( F_23 ( & V_53 -> V_62 ) ,
V_53 -> V_62 . V_120 + V_114 ,
V_113 ,
V_30 ) ;
if ( V_45 != V_113 )
return - V_121 ;
V_114 += V_113 ;
V_115 += V_113 ;
}
return V_115 ;
}
void F_81 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = & V_2 -> V_124 ;
struct V_9 * V_10 = & V_2 -> V_125 ;
V_10 -> V_20 = V_2 -> V_126 ;
V_10 -> V_23 = sizeof( struct V_22 ) ;
V_10 -> V_24 = V_2 -> V_25 -> V_26 ;
V_123 -> V_16 = V_10 ;
V_123 -> V_18 = 1 ;
V_123 -> V_127 = V_128 ;
V_123 -> V_15 = V_129 ;
V_123 -> V_130 = V_131 | V_132 ;
}
void F_82 ( struct V_1 * V_2 , T_3 V_133 , int V_134 )
{
unsigned long V_107 ;
F_83 ( & V_2 -> V_135 , V_107 ) ;
V_2 -> V_136 = V_133 ;
if ( V_134 )
F_84 ( V_137 , & V_2 -> V_138 ) ;
F_85 ( & V_2 -> V_135 , V_107 ) ;
}
static T_3 F_86 ( struct V_1 * V_2 )
{
unsigned long V_107 ;
T_3 V_133 ;
F_54 ( V_137 , & V_2 -> V_138 ) ;
F_83 ( & V_2 -> V_135 , V_107 ) ;
V_133 = V_2 -> V_136 ;
F_85 ( & V_2 -> V_135 , V_107 ) ;
return V_133 ;
}
void F_82 ( struct V_1 * V_2 , T_3 V_133 , int V_134 )
{
F_87 ( & V_2 -> V_136 , V_133 ) ;
if ( V_134 ) {
F_88 () ;
F_84 ( V_137 , & V_2 -> V_138 ) ;
}
}
static T_3 F_86 ( struct V_1 * V_2 )
{
F_54 ( V_137 , & V_2 -> V_138 ) ;
F_89 () ;
return F_90 ( & V_2 -> V_136 ) ;
}
static void F_91 ( struct V_1 * V_2 , unsigned int V_139 )
{
struct V_22 * V_140 = V_2 -> V_141 ;
struct V_122 * V_98 ;
T_3 V_133 ;
int V_45 ;
V_133 = F_86 ( V_2 ) ;
F_22 ( L_8 , V_2 , ( unsigned long long ) V_133 ) ;
F_92 ( V_140 , 0 , 0 , 0 ) ;
V_140 -> V_142 = F_93 ( V_133 ) ;
V_140 -> V_143 = V_139 ;
F_94 ( V_140 ) ;
V_2 -> V_144 = V_145 ;
V_45 = F_95 ( V_2 -> V_72 -> V_102 , & V_2 -> V_124 , & V_98 ) ;
if ( F_96 ( V_45 ) ) {
F_54 ( V_146 , & V_2 -> V_138 ) ;
F_84 ( V_137 , & V_2 -> V_138 ) ;
F_38 ( V_147 ) ;
F_62 ( V_2 -> V_82 , L_9 ) ;
} else
F_38 ( V_148 ) ;
}
void F_97 ( struct V_1 * V_2 )
{
unsigned int V_139 ;
if ( ! F_98 ( V_137 , & V_2 -> V_138 ) )
return;
if ( F_52 ( V_146 , & V_2 -> V_138 ) ) {
F_38 ( V_149 ) ;
return;
}
if ( ! F_99 ( V_2 , 1 , & V_139 , 0 , V_150 ) ) {
F_38 ( V_151 ) ;
F_54 ( V_146 , & V_2 -> V_138 ) ;
return;
}
F_54 ( V_137 , & V_2 -> V_138 ) ;
F_91 ( V_2 , V_139 ) ;
}
void F_100 ( struct V_1 * V_2 )
{
F_54 ( V_146 , & V_2 -> V_138 ) ;
F_97 ( V_2 ) ;
}
T_3 F_101 ( struct V_1 * V_2 )
{
if ( F_102 ( V_137 , & V_2 -> V_138 ) )
F_38 ( V_152 ) ;
return F_86 ( V_2 ) ;
}
static void F_103 ( struct V_86 * V_82 ,
struct V_49 * V_67 )
{
struct V_153 * V_154 ;
unsigned int V_155 ;
unsigned int V_156 ;
struct V_52 * V_53 ;
unsigned long V_114 ;
unsigned long V_113 ;
unsigned long V_115 ;
T_4 V_157 = 0 ;
void * V_20 ;
if ( F_76 ( V_67 -> V_71 . V_117 . V_118 ) != V_158 )
return;
V_154 = V_82 -> V_159 ;
V_156 = 0 ;
V_155 = 0 ;
V_53 = F_75 ( V_67 -> V_57 . V_14 , struct V_52 , V_60 ) ;
V_114 = 0 ;
V_115 = 0 ;
while ( V_115 < V_158 ) {
T_4 * V_160 , * V_161 ;
unsigned int V_162 ;
V_113 = F_104 ( V_27 - V_114 , V_163 - V_155 ) ;
F_30 ( V_113 & 7 ) ;
V_20 = F_105 ( F_23 ( & V_53 -> V_62 ) ) ;
V_160 = V_20 + V_53 -> V_62 . V_120 + V_114 ;
V_161 = ( void * ) V_154 -> V_164 [ V_156 ] + V_155 ;
for ( V_162 = 0 ; V_162 < V_113 ; V_162 += 8 ) {
V_157 |= ~ ( * V_160 ) & * V_161 ;
* V_161 ++ = * V_160 ++ ;
}
F_106 ( V_20 ) ;
V_115 += V_113 ;
V_155 += V_113 ;
if ( V_155 == V_163 ) {
V_155 = 0 ;
V_156 ++ ;
}
V_114 += V_113 ;
if ( V_114 == V_27 ) {
V_53 = F_75 ( V_53 -> V_60 . V_14 ,
struct V_52 , V_60 ) ;
V_114 = 0 ;
}
}
V_157 = F_107 ( V_157 ) ;
F_108 ( V_154 , V_157 ) ;
}
static void F_109 ( struct V_86 * V_82 ,
struct V_3 * V_4 , T_1 V_165 ,
struct V_166 * V_167 )
{
struct V_1 * V_2 = V_82 -> V_70 ;
struct V_49 * V_67 = V_2 -> V_168 ;
struct V_22 * V_169 , * V_140 ;
F_22 ( L_10 , V_2 , V_67 , V_4 ,
V_165 ) ;
if ( V_165 < sizeof( struct V_22 ) ) {
F_62 ( V_82 , L_11
L_12
L_13
L_7 ,
& V_82 -> V_83 ) ;
return;
}
V_165 -= sizeof( struct V_22 ) ;
V_169 = & V_2 -> V_170 [ V_4 - V_2 -> V_6 ] ;
if ( ! F_110 ( V_169 ) ) {
F_62 ( V_82 , L_11
L_14
L_15 ,
& V_82 -> V_83 ) ;
F_111 ( V_171 ) ;
return;
}
V_167 -> V_172 = F_112 ( V_169 -> V_142 ) ;
V_167 -> V_173 = 1 ;
if ( V_169 -> V_143 )
F_113 ( V_82 , V_169 -> V_143 ) ;
if ( V_169 -> V_174 == 0 && V_169 -> V_175 == 0 && V_165 == 0 ) {
F_38 ( V_176 ) ;
F_21 ( V_2 , V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
return;
}
if ( ! V_67 ) {
V_67 = V_4 -> V_11 ;
V_4 -> V_11 = NULL ;
V_2 -> V_168 = V_67 ;
V_140 = & V_67 -> V_71 . V_117 ;
V_67 -> V_71 . V_177 [ V_178 ] =
F_114 () ;
memcpy ( V_140 , V_169 , sizeof( * V_140 ) ) ;
V_2 -> V_179 = F_76 ( V_140 -> V_118 ) ;
V_67 -> V_71 . V_177 [ V_180 ] =
F_114 () ;
F_22 ( L_16 , V_2 , V_67 ,
V_2 -> V_179 , V_140 -> V_181 ) ;
} else {
V_140 = & V_67 -> V_71 . V_117 ;
if ( V_140 -> V_182 != V_169 -> V_182 ||
V_140 -> V_118 != V_169 -> V_118 ||
V_140 -> V_174 != V_169 -> V_174 ||
V_140 -> V_175 != V_169 -> V_175 ) {
F_62 ( V_82 ,
L_17 ) ;
return;
}
}
F_4 ( & V_4 -> V_12 -> V_60 , & V_67 -> V_57 ) ;
V_4 -> V_12 = NULL ;
if ( V_2 -> V_179 > V_27 )
V_2 -> V_179 -= V_27 ;
else {
V_2 -> V_179 = 0 ;
V_2 -> V_168 = NULL ;
if ( V_67 -> V_71 . V_117 . V_181 == V_183 )
F_103 ( V_82 , V_67 ) ;
else {
F_115 ( V_82 , V_82 -> V_83 , V_82 -> V_184 ,
& V_67 -> V_71 , V_185 ) ;
V_167 -> V_186 = F_112 ( V_140 -> V_182 ) ;
V_167 -> V_187 = 1 ;
}
if ( V_140 -> V_181 & V_188 ) {
F_111 ( V_189 ) ;
V_167 -> V_134 = 1 ;
}
F_32 ( & V_67 -> V_71 ) ;
}
}
void F_116 ( struct V_1 * V_2 ,
struct V_190 * V_191 ,
struct V_166 * V_167 )
{
struct V_86 * V_82 = V_2 -> V_82 ;
struct V_3 * V_4 ;
F_22 ( L_18 ,
( unsigned long long ) V_191 -> V_15 , V_191 -> V_192 ,
F_117 ( V_191 -> V_192 ) , V_191 -> V_193 ,
F_76 ( V_191 -> V_194 . V_195 ) ) ;
F_38 ( V_196 ) ;
V_4 = & V_2 -> V_6 [ F_118 ( & V_2 -> V_7 ) ] ;
F_33 ( V_2 -> V_72 -> V_73 , & V_4 -> V_12 -> V_62 , 1 ,
V_74 ) ;
if ( V_191 -> V_192 == V_197 ) {
F_109 ( V_82 , V_4 , V_191 -> V_193 , V_167 ) ;
} else {
if ( F_58 ( V_82 ) || F_119 ( V_82 ) )
F_62 ( V_82 , L_19 ,
& V_82 -> V_184 , & V_82 -> V_83 ,
V_191 -> V_192 ,
F_117 ( V_191 -> V_192 ) ) ;
}
if ( V_4 -> V_12 ) {
F_21 ( V_2 , V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
}
F_120 ( & V_2 -> V_7 , 1 ) ;
if ( F_66 ( & V_2 -> V_7 ) )
F_38 ( V_198 ) ;
if ( F_65 ( & V_2 -> V_7 ) )
F_57 ( V_82 , 0 , V_88 ) ;
}
int F_121 ( struct V_199 * V_200 )
{
struct V_86 * V_82 = V_200 -> V_201 ;
struct V_1 * V_2 = V_82 -> V_70 ;
int V_45 = 0 ;
F_22 ( L_20 , V_82 ) ;
if ( F_58 ( V_82 ) ) {
F_97 ( V_2 ) ;
F_57 ( V_82 , 0 , V_90 ) ;
}
return V_45 ;
}
int F_122 ( void )
{
struct V_202 V_203 ;
int V_45 = - V_42 ;
F_123 ( & V_203 ) ;
V_79 = V_203 . V_204 / 3 * V_163 / V_27 ;
V_58 = F_124 ( L_21 ,
sizeof( struct V_49 ) ,
0 , V_205 , NULL ) ;
if ( ! V_58 )
goto V_92;
V_61 = F_124 ( L_22 ,
sizeof( struct V_52 ) ,
0 , V_205 , NULL ) ;
if ( ! V_61 ) {
F_125 ( V_58 ) ;
V_58 = NULL ;
} else
V_45 = 0 ;
V_92:
return V_45 ;
}
void F_126 ( void )
{
F_125 ( V_58 ) ;
F_125 ( V_61 ) ;
}
