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
int F_42 ( struct V_63 * V_64 , struct V_67 * V_68 )
{
struct V_65 * V_66 ;
struct V_1 * V_2 ;
unsigned long V_69 ;
unsigned long V_70 = 0 ;
int V_71 = 0 ;
int V_42 ;
T_1 V_72 ;
V_66 = F_36 ( V_64 , struct V_65 , V_34 ) ;
V_2 = F_43 ( V_66 -> V_49 . V_23 , struct V_1 , V_51 ) ;
V_72 = F_44 ( V_64 -> V_73 . V_74 ) ;
while ( F_45 ( V_68 ) && V_71 < V_72 ) {
if ( V_70 == V_13 ) {
V_2 = F_43 ( V_2 -> V_51 . V_23 ,
struct V_1 , V_51 ) ;
V_70 = 0 ;
}
V_69 = F_46 (unsigned long, iov_iter_count(to),
RDS_FRAG_SIZE - frag_off) ;
V_69 = F_46 (unsigned long, to_copy, len - copied) ;
F_47 ( V_75 , V_69 ) ;
V_42 = F_48 ( V_2 -> V_3 ,
V_2 -> V_52 + V_70 ,
V_69 ,
V_68 ) ;
if ( V_42 != V_69 )
return - V_76 ;
V_70 += V_69 ;
V_71 += V_69 ;
}
return V_71 ;
}
void F_49 ( struct V_5 * V_6 )
{
struct V_77 * V_78 = & V_6 -> V_79 ;
struct V_19 * V_20 = & V_6 -> V_80 ;
V_20 -> V_29 = V_6 -> V_81 ;
V_20 -> V_30 = sizeof( struct V_33 ) ;
V_20 -> V_31 = F_50 ( V_6 ) ;
V_78 -> V_25 = V_20 ;
V_78 -> V_27 = 1 ;
V_78 -> V_82 = V_83 ;
V_78 -> V_24 = V_84 ;
V_78 -> V_85 = V_86 | V_87 ;
}
static void F_51 ( struct V_5 * V_6 , T_4 V_88 ,
int V_89 )
{
unsigned long V_90 ;
F_52 ( & V_6 -> V_91 , V_90 ) ;
V_6 -> V_92 = V_88 ;
if ( V_89 )
F_53 ( V_93 , & V_6 -> V_94 ) ;
F_54 ( & V_6 -> V_91 , V_90 ) ;
}
static T_4 F_55 ( struct V_5 * V_6 )
{
unsigned long V_90 ;
T_4 V_88 ;
F_56 ( V_93 , & V_6 -> V_94 ) ;
F_52 ( & V_6 -> V_91 , V_90 ) ;
V_88 = V_6 -> V_92 ;
F_54 ( & V_6 -> V_91 , V_90 ) ;
return V_88 ;
}
static void F_51 ( struct V_5 * V_6 , T_4 V_88 ,
int V_89 )
{
F_57 ( & V_6 -> V_92 , V_88 ) ;
if ( V_89 ) {
F_58 () ;
F_53 ( V_93 , & V_6 -> V_94 ) ;
}
}
static T_4 F_55 ( struct V_5 * V_6 )
{
F_56 ( V_93 , & V_6 -> V_94 ) ;
F_59 () ;
return F_60 ( & V_6 -> V_92 ) ;
}
static void F_61 ( struct V_5 * V_6 , unsigned int V_95 )
{
struct V_33 * V_96 = V_6 -> V_97 ;
struct V_77 * V_56 ;
T_4 V_88 ;
int V_42 ;
V_88 = F_55 ( V_6 ) ;
F_2 ( L_10 , V_6 , ( unsigned long long ) V_88 ) ;
F_62 ( V_96 , 0 , 0 , 0 ) ;
V_96 -> V_98 = F_63 ( V_88 ) ;
V_96 -> V_99 = V_95 ;
F_64 ( V_96 ) ;
V_6 -> V_100 = V_101 ;
V_42 = F_65 ( V_6 -> V_11 -> V_61 , & V_6 -> V_79 , & V_56 ) ;
if ( F_66 ( V_42 ) ) {
F_56 ( V_102 , & V_6 -> V_94 ) ;
F_53 ( V_93 , & V_6 -> V_94 ) ;
F_17 ( V_103 ) ;
F_32 ( V_6 -> V_37 , L_11 ) ;
} else
F_17 ( V_104 ) ;
}
void F_67 ( struct V_5 * V_6 )
{
unsigned int V_95 ;
if ( ! F_68 ( V_93 , & V_6 -> V_94 ) )
return;
if ( F_69 ( V_102 , & V_6 -> V_94 ) ) {
F_17 ( V_105 ) ;
return;
}
if ( ! F_70 ( V_6 , 1 , & V_95 , 0 , V_106 ) ) {
F_17 ( V_107 ) ;
F_56 ( V_102 , & V_6 -> V_94 ) ;
return;
}
F_56 ( V_93 , & V_6 -> V_94 ) ;
F_61 ( V_6 , V_95 ) ;
}
void F_71 ( struct V_5 * V_6 )
{
F_56 ( V_102 , & V_6 -> V_94 ) ;
F_67 ( V_6 ) ;
}
T_4 F_72 ( struct V_5 * V_6 )
{
if ( F_73 ( V_93 , & V_6 -> V_94 ) )
F_17 ( V_108 ) ;
return F_55 ( V_6 ) ;
}
static void F_74 ( struct V_36 * V_37 ,
struct V_65 * V_66 )
{
struct V_109 * V_110 ;
unsigned int V_111 ;
unsigned int V_112 ;
struct V_1 * V_2 ;
unsigned long V_70 ;
unsigned long V_69 ;
unsigned long V_71 ;
T_5 V_113 = 0 ;
void * V_29 ;
if ( F_44 ( V_66 -> V_34 . V_73 . V_74 ) != V_114 )
return;
V_110 = V_37 -> V_115 ;
V_112 = 0 ;
V_111 = 0 ;
V_2 = F_43 ( V_66 -> V_49 . V_23 , struct V_1 , V_51 ) ;
V_70 = 0 ;
V_71 = 0 ;
while ( V_71 < V_114 ) {
T_5 * V_116 , * V_117 ;
unsigned int V_118 ;
V_69 = F_75 ( V_13 - V_70 , V_119 - V_111 ) ;
F_5 ( V_69 & 7 ) ;
V_29 = F_76 ( V_2 -> V_3 ) ;
V_116 = V_29 + V_70 ;
V_117 = ( void * ) V_110 -> V_120 [ V_112 ] + V_111 ;
for ( V_118 = 0 ; V_118 < V_69 ; V_118 += 8 ) {
V_113 |= ~ ( * V_116 ) & * V_117 ;
* V_117 ++ = * V_116 ++ ;
}
F_77 ( V_29 ) ;
V_71 += V_69 ;
V_111 += V_69 ;
if ( V_111 == V_119 ) {
V_111 = 0 ;
V_112 ++ ;
}
V_70 += V_69 ;
if ( V_70 == V_13 ) {
V_2 = F_43 ( V_2 -> V_51 . V_23 ,
struct V_1 , V_51 ) ;
V_70 = 0 ;
}
}
V_113 = F_78 ( V_113 ) ;
F_79 ( V_110 , V_113 ) ;
}
static void F_80 ( struct V_36 * V_37 ,
struct V_7 * V_8 , T_1 V_121 ,
struct V_122 * V_123 )
{
struct V_5 * V_6 = V_37 -> V_40 ;
struct V_65 * V_66 = V_6 -> V_124 ;
struct V_33 * V_125 , * V_96 ;
F_2 ( L_12 , V_6 , V_66 , V_8 ,
V_121 ) ;
if ( V_121 < sizeof( struct V_33 ) ) {
F_32 ( V_37 , L_13
L_14
L_15
L_7 ,
& V_37 -> V_50 ) ;
return;
}
V_121 -= sizeof( struct V_33 ) ;
V_125 = & V_6 -> V_126 [ V_8 - V_6 -> V_16 ] ;
if ( ! F_81 ( V_125 ) ) {
F_32 ( V_37 , L_13
L_16
L_17 ,
& V_37 -> V_50 ) ;
F_82 ( V_127 ) ;
return;
}
V_123 -> V_128 = F_83 ( V_125 -> V_98 ) ;
V_123 -> V_129 = 1 ;
if ( V_125 -> V_99 )
F_84 ( V_37 , V_125 -> V_99 ) ;
if ( V_125 -> V_130 == 0 && V_125 -> V_131 == 0 && V_121 == 0 ) {
F_17 ( V_132 ) ;
F_1 ( V_8 -> V_9 ) ;
return;
}
if ( ! V_66 ) {
V_66 = V_8 -> V_21 ;
V_8 -> V_21 = NULL ;
V_6 -> V_124 = V_66 ;
V_96 = & V_66 -> V_34 . V_73 ;
memcpy ( V_96 , V_125 , sizeof( * V_96 ) ) ;
V_6 -> V_133 = F_44 ( V_96 -> V_74 ) ;
F_2 ( L_18 , V_6 , V_66 ,
V_6 -> V_133 , V_96 -> V_134 ) ;
} else {
V_96 = & V_66 -> V_34 . V_73 ;
if ( V_96 -> V_135 != V_125 -> V_135 ||
V_96 -> V_74 != V_125 -> V_74 ||
V_96 -> V_130 != V_125 -> V_130 ||
V_96 -> V_131 != V_125 -> V_131 ) {
F_32 ( V_37 ,
L_19 ) ;
return;
}
}
F_85 ( & V_8 -> V_9 -> V_51 , & V_66 -> V_49 ) ;
V_8 -> V_9 = NULL ;
if ( V_6 -> V_133 > V_13 )
V_6 -> V_133 -= V_13 ;
else {
V_6 -> V_133 = 0 ;
V_6 -> V_124 = NULL ;
if ( V_66 -> V_34 . V_73 . V_134 == V_136 )
F_74 ( V_37 , V_66 ) ;
else {
F_86 ( V_37 , V_37 -> V_50 , V_37 -> V_137 ,
& V_66 -> V_34 , V_138 ) ;
V_123 -> V_139 = F_83 ( V_96 -> V_135 ) ;
V_123 -> V_140 = 1 ;
}
if ( V_96 -> V_134 & V_141 ) {
F_82 ( V_142 ) ;
V_123 -> V_89 = 1 ;
}
F_13 ( & V_66 -> V_34 ) ;
}
}
void F_87 ( struct V_143 * V_144 , void * V_145 )
{
struct V_36 * V_37 = V_145 ;
struct V_5 * V_6 = V_37 -> V_40 ;
F_2 ( L_20 , V_37 , V_144 ) ;
F_17 ( V_146 ) ;
F_88 ( & V_6 -> V_147 ) ;
}
static inline void F_89 ( struct V_5 * V_6 ,
struct V_122 * V_123 )
{
struct V_36 * V_37 = V_6 -> V_37 ;
struct V_148 V_149 ;
struct V_7 * V_8 ;
while ( F_90 ( V_6 -> V_150 , 1 , & V_149 ) > 0 ) {
F_2 ( L_21 ,
( unsigned long long ) V_149 . V_24 , V_149 . V_151 , V_149 . V_121 ,
F_44 ( V_149 . V_152 . V_153 ) ) ;
F_17 ( V_154 ) ;
V_8 = & V_6 -> V_16 [ F_91 ( & V_6 -> V_17 ) ] ;
F_7 ( V_6 , V_8 ) ;
if ( F_28 ( V_37 ) || F_92 ( V_37 ) ) {
if ( V_149 . V_151 == V_155 ) {
F_80 ( V_37 , V_8 , V_149 . V_121 , V_123 ) ;
} else {
F_32 ( V_37 , L_22
L_23
L_7 , & V_37 -> V_50 ,
V_149 . V_151 ) ;
}
}
F_93 ( & V_6 -> V_17 , 1 ) ;
}
}
void F_94 ( unsigned long V_156 )
{
struct V_5 * V_6 = (struct V_5 * ) V_156 ;
struct V_36 * V_37 = V_6 -> V_37 ;
struct V_122 V_123 = { 0 , } ;
F_89 ( V_6 , & V_123 ) ;
F_95 ( V_6 -> V_150 , V_157 ) ;
F_89 ( V_6 , & V_123 ) ;
if ( V_123 . V_140 )
F_51 ( V_6 , V_123 . V_139 , V_123 . V_89 ) ;
if ( V_123 . V_129 && V_123 . V_128 > V_6 -> V_158 ) {
F_96 ( V_37 , V_123 . V_128 , NULL ) ;
V_6 -> V_158 = V_123 . V_128 ;
}
if ( F_28 ( V_37 ) )
F_67 ( V_6 ) ;
if ( F_97 ( & V_6 -> V_17 ) )
F_17 ( V_159 ) ;
if ( F_98 ( & V_6 -> V_17 ) )
F_99 ( V_160 , & V_37 -> V_161 , 0 ) ;
}
int F_100 ( struct V_36 * V_37 )
{
struct V_5 * V_6 = V_37 -> V_40 ;
int V_42 = 0 ;
F_2 ( L_24 , V_37 ) ;
F_101 ( & V_6 -> V_162 ) ;
if ( F_27 ( V_37 , V_163 , V_164 , 0 ) )
V_42 = - V_43 ;
else
F_17 ( V_165 ) ;
F_102 ( & V_6 -> V_162 ) ;
if ( F_28 ( V_37 ) )
F_67 ( V_6 ) ;
return V_42 ;
}
int F_103 ( void )
{
struct V_166 V_167 ;
int V_42 = - V_43 ;
F_104 ( & V_167 ) ;
V_45 = V_167 . V_168 / 3 * V_119 / V_13 ;
V_48 = F_105 ( L_25 ,
sizeof( struct V_65 ) ,
0 , 0 , NULL ) ;
if ( ! V_48 )
goto V_47;
V_4 = F_105 ( L_26 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( ! V_4 )
F_106 ( V_48 ) ;
else
V_42 = 0 ;
V_47:
return V_42 ;
}
void F_107 ( void )
{
F_106 ( V_48 ) ;
F_106 ( V_4 ) ;
}
