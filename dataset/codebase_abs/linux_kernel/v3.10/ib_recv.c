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
struct V_27 * V_94 ;
struct V_27 T_3 * V_95 ;
F_56 ( V_93 ) ;
V_95 = F_57 ( V_33 -> V_40 -> V_42 ) ;
if ( ! V_95 )
F_39 ( V_92 ) ;
else
F_4 ( V_92 , V_95 ) ;
F_58 ( V_95 , V_92 ) ;
F_59 ( V_33 -> V_40 -> V_43 ) ;
if ( F_57 ( V_33 -> V_40 -> V_43 ) < V_96 )
goto V_97;
do {
V_94 = F_6 ( & V_33 -> V_35 , NULL ) ;
if ( V_94 )
F_2 ( V_94 , V_95 ) ;
V_94 = F_60 ( & V_33 -> V_35 , NULL , V_95 ) ;
} while ( V_94 );
F_58 ( V_95 , NULL ) ;
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
int F_62 ( struct V_62 * V_49 , struct V_98 * V_99 ,
T_4 V_100 )
{
struct V_48 * V_63 ;
struct V_51 * V_52 ;
struct V_98 * V_101 = V_99 ;
unsigned long V_102 ;
unsigned long V_103 = 0 ;
unsigned long V_104 = 0 ;
int V_105 = 0 ;
int V_44 ;
T_1 V_106 ;
V_63 = F_26 ( V_49 , struct V_48 , V_67 ) ;
V_52 = F_63 ( V_63 -> V_56 . V_14 , struct V_51 , V_59 ) ;
V_106 = F_64 ( V_49 -> V_107 . V_108 ) ;
while ( V_105 < V_100 && V_105 < V_106 ) {
if ( V_103 == V_26 ) {
V_52 = F_63 ( V_52 -> V_59 . V_14 ,
struct V_51 , V_59 ) ;
V_103 = 0 ;
}
while ( V_104 == V_101 -> V_109 ) {
V_104 = 0 ;
V_101 ++ ;
}
V_102 = F_65 ( V_101 -> V_109 - V_104 , V_26 - V_103 ) ;
V_102 = F_66 ( T_4 , V_102 , V_100 - V_105 ) ;
V_102 = F_66 (unsigned long, to_copy, len - copied) ;
F_22 ( L_8
L_9 ,
V_102 , V_101 -> V_110 , V_101 -> V_109 , V_104 ,
F_23 ( & V_52 -> V_61 ) , V_52 -> V_61 . V_111 , V_103 ) ;
V_44 = F_67 ( F_23 ( & V_52 -> V_61 ) ,
V_52 -> V_61 . V_111 + V_103 ,
V_101 -> V_110 + V_104 ,
V_102 ) ;
if ( V_44 ) {
V_105 = V_44 ;
break;
}
V_104 += V_102 ;
V_103 += V_102 ;
V_105 += V_102 ;
}
return V_105 ;
}
void F_68 ( struct V_1 * V_2 )
{
struct V_112 * V_113 = & V_2 -> V_114 ;
struct V_9 * V_10 = & V_2 -> V_115 ;
V_10 -> V_20 = V_2 -> V_116 ;
V_10 -> V_23 = sizeof( struct V_22 ) ;
V_10 -> V_24 = V_2 -> V_25 -> V_24 ;
V_113 -> V_16 = V_10 ;
V_113 -> V_18 = 1 ;
V_113 -> V_117 = V_118 ;
V_113 -> V_15 = V_119 ;
V_113 -> V_120 = V_121 | V_122 ;
}
static void F_69 ( struct V_1 * V_2 , T_5 V_123 ,
int V_124 )
{
unsigned long V_93 ;
F_70 ( & V_2 -> V_125 , V_93 ) ;
V_2 -> V_126 = V_123 ;
if ( V_124 )
F_71 ( V_127 , & V_2 -> V_128 ) ;
F_72 ( & V_2 -> V_125 , V_93 ) ;
}
static T_5 F_73 ( struct V_1 * V_2 )
{
unsigned long V_93 ;
T_5 V_123 ;
F_74 ( V_127 , & V_2 -> V_128 ) ;
F_70 ( & V_2 -> V_125 , V_93 ) ;
V_123 = V_2 -> V_126 ;
F_72 ( & V_2 -> V_125 , V_93 ) ;
return V_123 ;
}
static void F_69 ( struct V_1 * V_2 , T_5 V_123 ,
int V_124 )
{
F_75 ( & V_2 -> V_126 , V_123 ) ;
if ( V_124 ) {
F_76 () ;
F_71 ( V_127 , & V_2 -> V_128 ) ;
}
}
static T_5 F_73 ( struct V_1 * V_2 )
{
F_74 ( V_127 , & V_2 -> V_128 ) ;
F_77 () ;
return F_78 ( & V_2 -> V_126 ) ;
}
static void F_79 ( struct V_1 * V_2 , unsigned int V_129 )
{
struct V_22 * V_130 = V_2 -> V_131 ;
struct V_112 * V_87 ;
T_5 V_123 ;
int V_44 ;
V_123 = F_73 ( V_2 ) ;
F_22 ( L_10 , V_2 , ( unsigned long long ) V_123 ) ;
F_80 ( V_130 , 0 , 0 , 0 ) ;
V_130 -> V_132 = F_81 ( V_123 ) ;
V_130 -> V_133 = V_129 ;
F_82 ( V_130 ) ;
V_2 -> V_134 = V_135 ;
V_44 = F_83 ( V_2 -> V_68 -> V_90 , & V_2 -> V_114 , & V_87 ) ;
if ( F_84 ( V_44 ) ) {
F_74 ( V_136 , & V_2 -> V_128 ) ;
F_71 ( V_127 , & V_2 -> V_128 ) ;
F_36 ( V_137 ) ;
F_53 ( V_2 -> V_77 , L_11 ) ;
} else
F_36 ( V_138 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
unsigned int V_129 ;
if ( ! F_86 ( V_127 , & V_2 -> V_128 ) )
return;
if ( F_87 ( V_136 , & V_2 -> V_128 ) ) {
F_36 ( V_139 ) ;
return;
}
if ( ! F_88 ( V_2 , 1 , & V_129 , 0 , V_140 ) ) {
F_36 ( V_141 ) ;
F_74 ( V_136 , & V_2 -> V_128 ) ;
return;
}
F_74 ( V_127 , & V_2 -> V_128 ) ;
F_79 ( V_2 , V_129 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
F_74 ( V_136 , & V_2 -> V_128 ) ;
F_85 ( V_2 ) ;
}
T_5 F_90 ( struct V_1 * V_2 )
{
if ( F_91 ( V_127 , & V_2 -> V_128 ) )
F_36 ( V_142 ) ;
return F_73 ( V_2 ) ;
}
static void F_92 ( struct V_80 * V_77 ,
struct V_48 * V_63 )
{
struct V_143 * V_144 ;
unsigned int V_145 ;
unsigned int V_146 ;
struct V_51 * V_52 ;
unsigned long V_103 ;
unsigned long V_102 ;
unsigned long V_105 ;
T_6 V_147 = 0 ;
void * V_20 ;
if ( F_64 ( V_63 -> V_67 . V_107 . V_108 ) != V_148 )
return;
V_144 = V_77 -> V_149 ;
V_146 = 0 ;
V_145 = 0 ;
V_52 = F_63 ( V_63 -> V_56 . V_14 , struct V_51 , V_59 ) ;
V_103 = 0 ;
V_105 = 0 ;
while ( V_105 < V_148 ) {
T_6 * V_150 , * V_151 ;
unsigned int V_152 ;
V_102 = F_65 ( V_26 - V_103 , V_153 - V_145 ) ;
F_28 ( V_102 & 7 ) ;
V_20 = F_93 ( F_23 ( & V_52 -> V_61 ) ) ;
V_150 = V_20 + V_103 ;
V_151 = ( void * ) V_144 -> V_154 [ V_146 ] + V_145 ;
for ( V_152 = 0 ; V_152 < V_102 ; V_152 += 8 ) {
V_147 |= ~ ( * V_150 ) & * V_151 ;
* V_151 ++ = * V_150 ++ ;
}
F_94 ( V_20 ) ;
V_105 += V_102 ;
V_145 += V_102 ;
if ( V_145 == V_153 ) {
V_145 = 0 ;
V_146 ++ ;
}
V_103 += V_102 ;
if ( V_103 == V_26 ) {
V_52 = F_63 ( V_52 -> V_59 . V_14 ,
struct V_51 , V_59 ) ;
V_103 = 0 ;
}
}
V_147 = F_95 ( V_147 ) ;
F_96 ( V_144 , V_147 ) ;
}
static void F_97 ( struct V_80 * V_77 ,
struct V_3 * V_4 , T_1 V_155 ,
struct V_156 * V_157 )
{
struct V_1 * V_2 = V_77 -> V_66 ;
struct V_48 * V_63 = V_2 -> V_158 ;
struct V_22 * V_159 , * V_130 ;
F_22 ( L_12 , V_2 , V_63 , V_4 ,
V_155 ) ;
if ( V_155 < sizeof( struct V_22 ) ) {
F_53 ( V_77 , L_13
L_14
L_15
L_7 ,
& V_77 -> V_78 ) ;
return;
}
V_155 -= sizeof( struct V_22 ) ;
V_159 = & V_2 -> V_160 [ V_4 - V_2 -> V_6 ] ;
if ( ! F_98 ( V_159 ) ) {
F_53 ( V_77 , L_13
L_16
L_17 ,
& V_77 -> V_78 ) ;
F_99 ( V_161 ) ;
return;
}
V_157 -> V_162 = F_100 ( V_159 -> V_132 ) ;
V_157 -> V_163 = 1 ;
if ( V_159 -> V_133 )
F_101 ( V_77 , V_159 -> V_133 ) ;
if ( V_159 -> V_164 == 0 && V_159 -> V_165 == 0 && V_155 == 0 ) {
F_36 ( V_166 ) ;
F_21 ( V_2 , V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
return;
}
if ( ! V_63 ) {
V_63 = V_4 -> V_11 ;
V_4 -> V_11 = NULL ;
V_2 -> V_158 = V_63 ;
V_130 = & V_63 -> V_67 . V_107 ;
memcpy ( V_130 , V_159 , sizeof( * V_130 ) ) ;
V_2 -> V_167 = F_64 ( V_130 -> V_108 ) ;
F_22 ( L_18 , V_2 , V_63 ,
V_2 -> V_167 , V_130 -> V_168 ) ;
} else {
V_130 = & V_63 -> V_67 . V_107 ;
if ( V_130 -> V_169 != V_159 -> V_169 ||
V_130 -> V_108 != V_159 -> V_108 ||
V_130 -> V_164 != V_159 -> V_164 ||
V_130 -> V_165 != V_159 -> V_165 ) {
F_53 ( V_77 ,
L_19 ) ;
return;
}
}
F_4 ( & V_4 -> V_12 -> V_59 , & V_63 -> V_56 ) ;
V_4 -> V_12 = NULL ;
if ( V_2 -> V_167 > V_26 )
V_2 -> V_167 -= V_26 ;
else {
V_2 -> V_167 = 0 ;
V_2 -> V_158 = NULL ;
if ( V_63 -> V_67 . V_107 . V_168 == V_170 )
F_92 ( V_77 , V_63 ) ;
else {
F_102 ( V_77 , V_77 -> V_78 , V_77 -> V_171 ,
& V_63 -> V_67 , V_172 ) ;
V_157 -> V_173 = F_100 ( V_130 -> V_169 ) ;
V_157 -> V_174 = 1 ;
}
if ( V_130 -> V_168 & V_175 ) {
F_99 ( V_176 ) ;
V_157 -> V_124 = 1 ;
}
F_30 ( & V_63 -> V_67 ) ;
}
}
void F_103 ( struct V_177 * V_178 , void * V_179 )
{
struct V_80 * V_77 = V_179 ;
struct V_1 * V_2 = V_77 -> V_66 ;
F_22 ( L_20 , V_77 , V_178 ) ;
F_36 ( V_180 ) ;
F_104 ( & V_2 -> V_181 ) ;
}
static inline void F_105 ( struct V_1 * V_2 ,
struct V_156 * V_157 )
{
struct V_80 * V_77 = V_2 -> V_77 ;
struct V_182 V_183 ;
struct V_3 * V_4 ;
while ( F_106 ( V_2 -> V_184 , 1 , & V_183 ) > 0 ) {
F_22 ( L_21 ,
( unsigned long long ) V_183 . V_15 , V_183 . V_185 ,
F_107 ( V_183 . V_185 ) , V_183 . V_186 ,
F_64 ( V_183 . V_187 . V_188 ) ) ;
F_36 ( V_189 ) ;
V_4 = & V_2 -> V_6 [ F_108 ( & V_2 -> V_7 ) ] ;
F_31 ( V_2 -> V_68 -> V_69 , & V_4 -> V_12 -> V_61 , 1 , V_70 ) ;
if ( V_183 . V_185 == V_190 ) {
F_97 ( V_77 , V_4 , V_183 . V_186 , V_157 ) ;
} else {
if ( F_49 ( V_77 ) || F_109 ( V_77 ) )
F_53 ( V_77 , L_22
L_23
L_7 , & V_77 -> V_78 ,
V_183 . V_185 ,
F_107 ( V_183 . V_185 ) ) ;
}
F_110 ( & V_2 -> V_7 , 1 ) ;
}
}
void F_111 ( unsigned long V_191 )
{
struct V_1 * V_2 = (struct V_1 * ) V_191 ;
struct V_80 * V_77 = V_2 -> V_77 ;
struct V_156 V_157 = { 0 , } ;
F_105 ( V_2 , & V_157 ) ;
F_112 ( V_2 -> V_184 , V_192 ) ;
F_105 ( V_2 , & V_157 ) ;
if ( V_157 . V_174 )
F_69 ( V_2 , V_157 . V_173 , V_157 . V_124 ) ;
if ( V_157 . V_163 && V_157 . V_162 > V_2 -> V_193 ) {
F_113 ( V_77 , V_157 . V_162 , NULL ) ;
V_2 -> V_193 = V_157 . V_162 ;
}
if ( F_49 ( V_77 ) )
F_85 ( V_2 ) ;
if ( F_114 ( & V_2 -> V_7 ) )
F_36 ( V_194 ) ;
if ( F_115 ( & V_2 -> V_7 ) )
F_48 ( V_77 , 0 ) ;
}
int F_116 ( struct V_80 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_66 ;
int V_44 = 0 ;
F_22 ( L_24 , V_77 ) ;
if ( F_49 ( V_77 ) )
F_85 ( V_2 ) ;
return V_44 ;
}
int F_117 ( void )
{
struct V_195 V_196 ;
int V_44 = - V_41 ;
F_118 ( & V_196 ) ;
V_75 = V_196 . V_197 / 3 * V_153 / V_26 ;
V_57 = F_119 ( L_25 ,
sizeof( struct V_48 ) ,
0 , V_198 , NULL ) ;
if ( ! V_57 )
goto V_85;
V_60 = F_119 ( L_26 ,
sizeof( struct V_51 ) ,
0 , V_198 , NULL ) ;
if ( ! V_60 )
F_120 ( V_57 ) ;
else
V_44 = 0 ;
V_85:
return V_44 ;
}
void F_121 ( void )
{
F_120 ( V_57 ) ;
F_120 ( V_60 ) ;
}
