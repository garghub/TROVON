static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 , V_2 , V_2 -> V_3 ) ;
F_3 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( L_1 , V_2 , V_2 -> V_3 ) ;
F_5 ( V_2 -> V_3 ) ;
F_6 ( V_4 , V_2 ) ;
}
static void F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 ;
F_2 ( L_2 , V_8 , V_2 , V_2 -> V_3 ) ;
if ( V_2 -> V_10 )
F_8 ( V_6 -> V_11 -> V_12 ,
V_2 -> V_10 ,
V_13 , V_14 ) ;
V_2 -> V_10 = 0 ;
}
void F_9 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
T_1 V_15 ;
for ( V_15 = 0 , V_8 = V_6 -> V_16 ; V_15 < V_6 -> V_17 . V_18 ; V_15 ++ , V_8 ++ ) {
struct V_19 * V_20 ;
V_8 -> V_21 = NULL ;
V_8 -> V_9 = NULL ;
V_8 -> V_22 . V_23 = NULL ;
V_8 -> V_22 . V_24 = V_15 ;
V_8 -> V_22 . V_25 = V_8 -> V_26 ;
V_8 -> V_22 . V_27 = V_28 ;
V_20 = F_10 ( V_6 , V_8 -> V_26 ) ;
V_20 -> V_29 = 0 ;
V_20 -> V_30 = V_13 ;
V_20 -> V_31 = 0 ;
V_20 = F_11 ( V_6 , V_8 -> V_26 ) ;
V_20 -> V_29 = V_6 -> V_32 + ( V_15 * sizeof( struct V_33 ) ) ;
V_20 -> V_30 = sizeof( struct V_33 ) ;
V_20 -> V_31 = 0 ;
}
}
static void F_12 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
if ( V_8 -> V_21 ) {
F_13 ( & V_8 -> V_21 -> V_34 ) ;
V_8 -> V_21 = NULL ;
}
if ( V_8 -> V_9 ) {
F_7 ( V_6 , V_8 ) ;
if ( V_8 -> V_9 -> V_3 )
F_1 ( V_8 -> V_9 ) ;
F_4 ( V_8 -> V_9 ) ;
V_8 -> V_9 = NULL ;
}
}
void F_14 ( struct V_5 * V_6 )
{
T_1 V_15 ;
for ( V_15 = 0 ; V_15 < V_6 -> V_17 . V_18 ; V_15 ++ )
F_12 ( V_6 , & V_6 -> V_16 [ V_15 ] ) ;
if ( V_6 -> V_35 . V_3 )
F_1 ( & V_6 -> V_35 ) ;
}
static int F_15 ( struct V_36 * V_37 ,
struct V_7 * V_8 ,
T_2 V_38 , T_2 V_39 )
{
struct V_5 * V_6 = V_37 -> V_40 ;
T_3 V_41 ;
struct V_19 * V_20 ;
int V_42 = - V_43 ;
if ( ! V_8 -> V_21 ) {
if ( ! F_16 ( & V_44 , 1 , V_45 ) ) {
F_17 ( V_46 ) ;
goto V_47;
}
V_8 -> V_21 = F_18 ( V_48 ,
V_38 ) ;
if ( ! V_8 -> V_21 ) {
F_19 ( & V_44 ) ;
goto V_47;
}
F_20 ( & V_8 -> V_21 -> V_49 ) ;
F_21 ( & V_8 -> V_21 -> V_34 , V_37 , V_37 -> V_50 ) ;
}
if ( ! V_8 -> V_9 ) {
V_8 -> V_9 = F_18 ( V_4 , V_38 ) ;
if ( ! V_8 -> V_9 )
goto V_47;
F_20 ( & V_8 -> V_9 -> V_51 ) ;
V_8 -> V_9 -> V_3 = NULL ;
}
if ( ! V_6 -> V_35 . V_3 ) {
V_6 -> V_35 . V_3 = F_22 ( V_39 ) ;
if ( ! V_6 -> V_35 . V_3 )
goto V_47;
V_6 -> V_35 . V_52 = 0 ;
}
V_41 = F_23 ( V_6 -> V_11 -> V_12 ,
V_6 -> V_35 . V_3 ,
V_6 -> V_35 . V_52 ,
V_13 ,
V_14 ) ;
if ( F_24 ( V_6 -> V_11 -> V_12 , V_41 ) )
goto V_47;
V_8 -> V_9 -> V_3 = V_6 -> V_35 . V_3 ;
V_8 -> V_9 -> V_52 = V_6 -> V_35 . V_52 ;
V_8 -> V_9 -> V_10 = V_41 ;
V_20 = F_10 ( V_6 , V_8 -> V_26 ) ;
V_20 -> V_29 = V_41 ;
V_20 -> V_30 = V_13 ;
V_20 = F_11 ( V_6 , V_8 -> V_26 ) ;
V_20 -> V_29 = V_6 -> V_32 + ( V_8 - V_6 -> V_16 ) * sizeof( struct V_33 ) ;
V_20 -> V_30 = sizeof( struct V_33 ) ;
F_25 ( V_8 -> V_9 -> V_3 ) ;
if ( V_6 -> V_35 . V_52 < V_53 ) {
V_6 -> V_35 . V_52 += V_13 ;
} else {
F_26 ( V_6 -> V_35 . V_3 ) ;
V_6 -> V_35 . V_3 = NULL ;
V_6 -> V_35 . V_52 = 0 ;
}
V_42 = 0 ;
V_47:
return V_42 ;
}
int F_27 ( struct V_36 * V_37 , T_2 V_38 ,
T_2 V_39 , int V_54 )
{
struct V_5 * V_6 = V_37 -> V_40 ;
struct V_7 * V_8 ;
struct V_55 * V_56 ;
unsigned int V_57 = 0 ;
int V_42 = 0 ;
T_1 V_58 ;
while ( ( V_54 || F_28 ( V_37 ) ) &&
F_29 ( & V_6 -> V_17 , 1 , & V_58 ) ) {
if ( V_58 >= V_6 -> V_17 . V_18 ) {
F_30 ( V_59 L_3 ,
V_58 ) ;
V_42 = - V_60 ;
break;
}
V_8 = & V_6 -> V_16 [ V_58 ] ;
V_42 = F_15 ( V_37 , V_8 , V_38 , V_39 ) ;
if ( V_42 ) {
V_42 = - 1 ;
break;
}
V_42 = F_31 ( V_6 -> V_11 -> V_61 , & V_8 -> V_22 , & V_56 ) ;
F_2 ( L_4 , V_8 ,
V_8 -> V_21 , V_8 -> V_9 -> V_3 ,
( long ) V_8 -> V_9 -> V_10 , V_42 ) ;
if ( V_42 ) {
F_32 ( V_37 , L_5
L_6
L_7 , & V_37 -> V_50 ,
V_42 ) ;
V_42 = - 1 ;
break;
}
V_57 ++ ;
}
if ( V_6 -> V_62 && V_57 )
F_33 ( V_37 , V_57 ) ;
if ( V_42 )
F_34 ( & V_6 -> V_17 , 1 ) ;
return V_42 ;
}
static void F_35 ( struct V_63 * V_64 )
{
struct V_65 * V_66 ;
struct V_1 * V_2 ;
struct V_1 * V_58 ;
V_66 = F_36 ( V_64 , struct V_65 , V_34 ) ;
F_2 ( L_8 , V_66 , V_64 ) ;
F_37 (frag, pos, &iwinc->ii_frags, f_item) {
F_38 ( & V_2 -> V_51 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
}
void F_39 ( struct V_63 * V_64 )
{
struct V_65 * V_66 ;
V_66 = F_36 ( V_64 , struct V_65 , V_34 ) ;
F_35 ( V_64 ) ;
F_2 ( L_9 , V_66 , V_64 ) ;
F_5 ( ! F_40 ( & V_66 -> V_49 ) ) ;
F_6 ( V_48 , V_66 ) ;
F_19 ( & V_44 ) ;
F_5 ( F_41 ( & V_44 ) < 0 ) ;
}
int F_42 ( struct V_63 * V_64 , struct V_67 * V_68 ,
T_4 V_69 )
{
struct V_65 * V_66 ;
struct V_1 * V_2 ;
struct V_67 * V_70 = V_68 ;
unsigned long V_71 ;
unsigned long V_72 = 0 ;
unsigned long V_73 = 0 ;
int V_74 = 0 ;
int V_42 ;
T_1 V_75 ;
V_66 = F_36 ( V_64 , struct V_65 , V_34 ) ;
V_2 = F_43 ( V_66 -> V_49 . V_23 , struct V_1 , V_51 ) ;
V_75 = F_44 ( V_64 -> V_76 . V_77 ) ;
while ( V_74 < V_69 && V_74 < V_75 ) {
if ( V_72 == V_13 ) {
V_2 = F_43 ( V_2 -> V_51 . V_23 ,
struct V_1 , V_51 ) ;
V_72 = 0 ;
}
while ( V_73 == V_70 -> V_78 ) {
V_73 = 0 ;
V_70 ++ ;
}
V_71 = F_45 ( V_70 -> V_78 - V_73 , V_13 - V_72 ) ;
V_71 = F_46 ( T_4 , V_71 , V_69 - V_74 ) ;
V_71 = F_46 (unsigned long, to_copy, len - copied) ;
F_2 ( L_10
L_11 ,
V_71 , V_70 -> V_79 , V_70 -> V_78 , V_73 ,
V_2 -> V_3 , V_2 -> V_52 , V_72 ) ;
V_42 = F_47 ( V_2 -> V_3 ,
V_2 -> V_52 + V_72 ,
V_70 -> V_79 + V_73 ,
V_71 ) ;
if ( V_42 ) {
V_74 = V_42 ;
break;
}
V_73 += V_71 ;
V_72 += V_71 ;
V_74 += V_71 ;
}
return V_74 ;
}
void F_48 ( struct V_5 * V_6 )
{
struct V_80 * V_81 = & V_6 -> V_82 ;
struct V_19 * V_20 = & V_6 -> V_83 ;
V_20 -> V_29 = V_6 -> V_84 ;
V_20 -> V_30 = sizeof( struct V_33 ) ;
V_20 -> V_31 = F_49 ( V_6 ) ;
V_81 -> V_25 = V_20 ;
V_81 -> V_27 = 1 ;
V_81 -> V_85 = V_86 ;
V_81 -> V_24 = V_87 ;
V_81 -> V_88 = V_89 | V_90 ;
}
static void F_50 ( struct V_5 * V_6 , T_5 V_91 ,
int V_92 )
{
unsigned long V_93 ;
F_51 ( & V_6 -> V_94 , V_93 ) ;
V_6 -> V_95 = V_91 ;
if ( V_92 )
F_52 ( V_96 , & V_6 -> V_97 ) ;
F_53 ( & V_6 -> V_94 , V_93 ) ;
}
static T_5 F_54 ( struct V_5 * V_6 )
{
unsigned long V_93 ;
T_5 V_91 ;
F_55 ( V_96 , & V_6 -> V_97 ) ;
F_51 ( & V_6 -> V_94 , V_93 ) ;
V_91 = V_6 -> V_95 ;
F_53 ( & V_6 -> V_94 , V_93 ) ;
return V_91 ;
}
static void F_50 ( struct V_5 * V_6 , T_5 V_91 ,
int V_92 )
{
F_56 ( & V_6 -> V_95 , V_91 ) ;
if ( V_92 ) {
F_57 () ;
F_52 ( V_96 , & V_6 -> V_97 ) ;
}
}
static T_5 F_54 ( struct V_5 * V_6 )
{
F_55 ( V_96 , & V_6 -> V_97 ) ;
F_58 () ;
return F_59 ( & V_6 -> V_95 ) ;
}
static void F_60 ( struct V_5 * V_6 , unsigned int V_98 )
{
struct V_33 * V_99 = V_6 -> V_100 ;
struct V_80 * V_56 ;
T_5 V_91 ;
int V_42 ;
V_91 = F_54 ( V_6 ) ;
F_2 ( L_12 , V_6 , ( unsigned long long ) V_91 ) ;
F_61 ( V_99 , 0 , 0 , 0 ) ;
V_99 -> V_101 = F_62 ( V_91 ) ;
V_99 -> V_102 = V_98 ;
F_63 ( V_99 ) ;
V_6 -> V_103 = V_104 ;
V_42 = F_64 ( V_6 -> V_11 -> V_61 , & V_6 -> V_82 , & V_56 ) ;
if ( F_65 ( V_42 ) ) {
F_55 ( V_105 , & V_6 -> V_97 ) ;
F_52 ( V_96 , & V_6 -> V_97 ) ;
F_17 ( V_106 ) ;
F_32 ( V_6 -> V_37 , L_13 ) ;
} else
F_17 ( V_107 ) ;
}
void F_66 ( struct V_5 * V_6 )
{
unsigned int V_98 ;
if ( ! F_67 ( V_96 , & V_6 -> V_97 ) )
return;
if ( F_68 ( V_105 , & V_6 -> V_97 ) ) {
F_17 ( V_108 ) ;
return;
}
if ( ! F_69 ( V_6 , 1 , & V_98 , 0 , V_109 ) ) {
F_17 ( V_110 ) ;
F_55 ( V_105 , & V_6 -> V_97 ) ;
return;
}
F_55 ( V_96 , & V_6 -> V_97 ) ;
F_60 ( V_6 , V_98 ) ;
}
void F_70 ( struct V_5 * V_6 )
{
F_55 ( V_105 , & V_6 -> V_97 ) ;
F_66 ( V_6 ) ;
}
T_5 F_71 ( struct V_5 * V_6 )
{
if ( F_72 ( V_96 , & V_6 -> V_97 ) )
F_17 ( V_111 ) ;
return F_54 ( V_6 ) ;
}
static void F_73 ( struct V_36 * V_37 ,
struct V_65 * V_66 )
{
struct V_112 * V_113 ;
unsigned int V_114 ;
unsigned int V_115 ;
struct V_1 * V_2 ;
unsigned long V_72 ;
unsigned long V_71 ;
unsigned long V_74 ;
T_6 V_116 = 0 ;
void * V_29 ;
if ( F_44 ( V_66 -> V_34 . V_76 . V_77 ) != V_117 )
return;
V_113 = V_37 -> V_118 ;
V_115 = 0 ;
V_114 = 0 ;
V_2 = F_43 ( V_66 -> V_49 . V_23 , struct V_1 , V_51 ) ;
V_72 = 0 ;
V_74 = 0 ;
while ( V_74 < V_117 ) {
T_6 * V_119 , * V_120 ;
unsigned int V_121 ;
V_71 = F_45 ( V_13 - V_72 , V_122 - V_114 ) ;
F_5 ( V_71 & 7 ) ;
V_29 = F_74 ( V_2 -> V_3 ) ;
V_119 = V_29 + V_72 ;
V_120 = ( void * ) V_113 -> V_123 [ V_115 ] + V_114 ;
for ( V_121 = 0 ; V_121 < V_71 ; V_121 += 8 ) {
V_116 |= ~ ( * V_119 ) & * V_120 ;
* V_120 ++ = * V_119 ++ ;
}
F_75 ( V_29 ) ;
V_74 += V_71 ;
V_114 += V_71 ;
if ( V_114 == V_122 ) {
V_114 = 0 ;
V_115 ++ ;
}
V_72 += V_71 ;
if ( V_72 == V_13 ) {
V_2 = F_43 ( V_2 -> V_51 . V_23 ,
struct V_1 , V_51 ) ;
V_72 = 0 ;
}
}
V_116 = F_76 ( V_116 ) ;
F_77 ( V_113 , V_116 ) ;
}
static void F_78 ( struct V_36 * V_37 ,
struct V_7 * V_8 , T_1 V_124 ,
struct V_125 * V_126 )
{
struct V_5 * V_6 = V_37 -> V_40 ;
struct V_65 * V_66 = V_6 -> V_127 ;
struct V_33 * V_128 , * V_99 ;
F_2 ( L_14 , V_6 , V_66 , V_8 ,
V_124 ) ;
if ( V_124 < sizeof( struct V_33 ) ) {
F_32 ( V_37 , L_15
L_16
L_17
L_7 ,
& V_37 -> V_50 ) ;
return;
}
V_124 -= sizeof( struct V_33 ) ;
V_128 = & V_6 -> V_129 [ V_8 - V_6 -> V_16 ] ;
if ( ! F_79 ( V_128 ) ) {
F_32 ( V_37 , L_15
L_18
L_19 ,
& V_37 -> V_50 ) ;
F_80 ( V_130 ) ;
return;
}
V_126 -> V_131 = F_81 ( V_128 -> V_101 ) ;
V_126 -> V_132 = 1 ;
if ( V_128 -> V_102 )
F_82 ( V_37 , V_128 -> V_102 ) ;
if ( V_128 -> V_133 == 0 && V_128 -> V_134 == 0 && V_124 == 0 ) {
F_17 ( V_135 ) ;
F_1 ( V_8 -> V_9 ) ;
return;
}
if ( ! V_66 ) {
V_66 = V_8 -> V_21 ;
V_8 -> V_21 = NULL ;
V_6 -> V_127 = V_66 ;
V_99 = & V_66 -> V_34 . V_76 ;
memcpy ( V_99 , V_128 , sizeof( * V_99 ) ) ;
V_6 -> V_136 = F_44 ( V_99 -> V_77 ) ;
F_2 ( L_20 , V_6 , V_66 ,
V_6 -> V_136 , V_99 -> V_137 ) ;
} else {
V_99 = & V_66 -> V_34 . V_76 ;
if ( V_99 -> V_138 != V_128 -> V_138 ||
V_99 -> V_77 != V_128 -> V_77 ||
V_99 -> V_133 != V_128 -> V_133 ||
V_99 -> V_134 != V_128 -> V_134 ) {
F_32 ( V_37 ,
L_21 ) ;
return;
}
}
F_83 ( & V_8 -> V_9 -> V_51 , & V_66 -> V_49 ) ;
V_8 -> V_9 = NULL ;
if ( V_6 -> V_136 > V_13 )
V_6 -> V_136 -= V_13 ;
else {
V_6 -> V_136 = 0 ;
V_6 -> V_127 = NULL ;
if ( V_66 -> V_34 . V_76 . V_137 == V_139 )
F_73 ( V_37 , V_66 ) ;
else {
F_84 ( V_37 , V_37 -> V_50 , V_37 -> V_140 ,
& V_66 -> V_34 , V_141 ) ;
V_126 -> V_142 = F_81 ( V_99 -> V_138 ) ;
V_126 -> V_143 = 1 ;
}
if ( V_99 -> V_137 & V_144 ) {
F_80 ( V_145 ) ;
V_126 -> V_92 = 1 ;
}
F_13 ( & V_66 -> V_34 ) ;
}
}
void F_85 ( struct V_146 * V_147 , void * V_148 )
{
struct V_36 * V_37 = V_148 ;
struct V_5 * V_6 = V_37 -> V_40 ;
F_2 ( L_22 , V_37 , V_147 ) ;
F_17 ( V_149 ) ;
F_86 ( & V_6 -> V_150 ) ;
}
static inline void F_87 ( struct V_5 * V_6 ,
struct V_125 * V_126 )
{
struct V_36 * V_37 = V_6 -> V_37 ;
struct V_151 V_152 ;
struct V_7 * V_8 ;
while ( F_88 ( V_6 -> V_153 , 1 , & V_152 ) > 0 ) {
F_2 ( L_23 ,
( unsigned long long ) V_152 . V_24 , V_152 . V_154 , V_152 . V_124 ,
F_44 ( V_152 . V_155 . V_156 ) ) ;
F_17 ( V_157 ) ;
V_8 = & V_6 -> V_16 [ F_89 ( & V_6 -> V_17 ) ] ;
F_7 ( V_6 , V_8 ) ;
if ( F_28 ( V_37 ) || F_90 ( V_37 ) ) {
if ( V_152 . V_154 == V_158 ) {
F_78 ( V_37 , V_8 , V_152 . V_124 , V_126 ) ;
} else {
F_32 ( V_37 , L_24
L_25
L_7 , & V_37 -> V_50 ,
V_152 . V_154 ) ;
}
}
F_91 ( & V_6 -> V_17 , 1 ) ;
}
}
void F_92 ( unsigned long V_159 )
{
struct V_5 * V_6 = (struct V_5 * ) V_159 ;
struct V_36 * V_37 = V_6 -> V_37 ;
struct V_125 V_126 = { 0 , } ;
F_87 ( V_6 , & V_126 ) ;
F_93 ( V_6 -> V_153 , V_160 ) ;
F_87 ( V_6 , & V_126 ) ;
if ( V_126 . V_143 )
F_50 ( V_6 , V_126 . V_142 , V_126 . V_92 ) ;
if ( V_126 . V_132 && V_126 . V_131 > V_6 -> V_161 ) {
F_94 ( V_37 , V_126 . V_131 , NULL ) ;
V_6 -> V_161 = V_126 . V_131 ;
}
if ( F_28 ( V_37 ) )
F_66 ( V_6 ) ;
if ( F_95 ( & V_6 -> V_17 ) )
F_17 ( V_162 ) ;
if ( F_96 ( & V_6 -> V_17 ) )
F_97 ( V_163 , & V_37 -> V_164 , 0 ) ;
}
int F_98 ( struct V_36 * V_37 )
{
struct V_5 * V_6 = V_37 -> V_40 ;
int V_42 = 0 ;
F_2 ( L_26 , V_37 ) ;
F_99 ( & V_6 -> V_165 ) ;
if ( F_27 ( V_37 , V_166 , V_167 , 0 ) )
V_42 = - V_43 ;
else
F_17 ( V_168 ) ;
F_100 ( & V_6 -> V_165 ) ;
if ( F_28 ( V_37 ) )
F_66 ( V_6 ) ;
return V_42 ;
}
int F_101 ( void )
{
struct V_169 V_170 ;
int V_42 = - V_43 ;
F_102 ( & V_170 ) ;
V_45 = V_170 . V_171 / 3 * V_122 / V_13 ;
V_48 = F_103 ( L_27 ,
sizeof( struct V_65 ) ,
0 , 0 , NULL ) ;
if ( ! V_48 )
goto V_47;
V_4 = F_103 ( L_28 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_4 )
F_104 ( V_48 ) ;
else
V_42 = 0 ;
V_47:
return V_42 ;
}
void F_105 ( void )
{
F_104 ( V_48 ) ;
F_104 ( V_4 ) ;
}
