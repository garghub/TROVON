struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_1 * V_6 )
{
int V_7 = V_3 -> V_7 ;
struct V_8 * * V_9 = F_2 ( V_5 -> V_10 , 0 ) ;
int V_11 = 0 , V_12 = V_3 -> V_12 , V_13 ;
struct V_14 V_15 ;
F_3 ( L_1 , V_16 , ( unsigned long long ) V_3 -> V_17 ) ;
if ( V_3 -> V_18 == V_19 ) {
V_9 [ V_11 ++ ] = V_3 -> V_20 [ V_12 ] . V_8 ;
} else if ( V_3 -> V_18 == V_21 ) {
for ( V_13 = V_7 ; V_13 -- ; ) {
struct V_22 * V_20 = & V_3 -> V_20 [ V_13 ] ;
if ( F_4 ( V_23 , & V_20 -> V_24 ) )
V_9 [ V_11 ++ ] = V_20 -> V_8 ;
}
} else {
return V_6 ;
}
F_5 ( & V_15 , V_25 | V_26 , V_6 ,
NULL , V_3 , F_2 ( V_5 -> V_10 , 0 )
+ sizeof( struct V_8 * ) * ( V_3 -> V_7 + 2 ) ) ;
if ( V_11 == 1 )
V_6 = F_6 ( V_3 -> V_27 , V_9 [ 0 ] , 0 , 0 , V_28 ,
& V_15 ) ;
else
V_6 = F_7 ( V_3 -> V_27 , V_9 , 0 , V_11 , V_28 ,
& V_15 ) ;
return V_6 ;
}
static void * F_8 ( T_1 V_29 , void * V_30 )
{
struct V_31 * V_32 = V_30 ;
struct V_33 * V_34 ;
V_34 = F_9 ( V_32 , V_29 ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_35 = F_10 ( V_29 ) ;
if ( ! V_34 -> V_35 ) {
F_11 ( V_32 , V_34 ) ;
return NULL ;
}
return V_34 ;
}
static void F_12 ( void * V_36 , void * V_30 )
{
struct V_31 * V_32 = V_30 ;
struct V_33 * V_34 = V_36 ;
F_13 ( V_34 -> V_35 ) ;
F_11 ( V_32 , V_34 ) ;
}
static struct V_33 * F_14 ( struct V_37 * log ,
struct V_2 * V_3 )
{
struct V_38 * V_38 = log -> V_38 ;
struct V_33 * V_34 ;
struct V_39 * V_40 ;
struct V_8 * V_35 ;
V_34 = F_15 ( V_38 -> V_41 , V_42 ) ;
if ( ! V_34 )
return NULL ;
V_35 = V_34 -> V_35 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_35 = V_35 ;
V_34 -> log = log ;
F_16 ( & V_34 -> V_43 ) ;
F_16 ( & V_34 -> V_44 ) ;
F_17 ( & V_34 -> V_45 , 0 ) ;
F_18 ( & V_34 -> V_46 , V_34 -> V_47 , V_48 ) ;
V_40 = F_19 ( V_34 -> V_35 ) ;
F_20 ( V_40 ) ;
memset ( V_40 -> V_49 , 0xff , V_50 ) ;
V_40 -> V_51 = F_21 ( V_38 -> V_51 ) ;
V_34 -> V_52 = F_22 ( 1 , & V_38 -> V_52 ) ;
V_40 -> V_53 = F_23 ( V_34 -> V_52 ) ;
return V_34 ;
}
static int F_24 ( struct V_37 * log , struct V_2 * V_3 )
{
struct V_33 * V_34 = log -> V_54 ;
struct V_55 * V_56 = NULL ;
struct V_39 * V_40 ;
int V_13 ;
T_2 V_57 = 0 ;
int V_58 = 0 ;
struct V_59 * V_60 = V_3 -> V_61 ;
F_3 ( L_2 , V_16 , ( unsigned long long ) V_3 -> V_17 ) ;
if ( V_34 && ( V_34 -> V_62 == log -> V_63 ||
V_34 -> V_64 == V_65 ) ) {
F_3 ( L_3 ,
V_16 , V_34 -> V_52 ) ;
V_34 = NULL ;
}
if ( ! V_34 ) {
V_34 = F_14 ( log , V_3 ) ;
if ( ! V_34 )
return - V_66 ;
F_25 ( & log -> V_67 ) ;
F_26 ( & V_34 -> V_43 , & log -> V_68 ) ;
F_27 ( & log -> V_67 ) ;
log -> V_54 = V_34 ;
}
for ( V_13 = 0 ; V_13 < V_3 -> V_7 ; V_13 ++ ) {
struct V_22 * V_20 = & V_3 -> V_20 [ V_13 ] ;
if ( V_13 != V_3 -> V_12 && F_4 ( V_69 , & V_20 -> V_24 ) ) {
if ( ! V_58 || V_20 -> V_17 < V_57 )
V_57 = V_20 -> V_17 ;
V_58 ++ ;
}
}
F_28 ( ! V_58 ) ;
F_3 ( L_4 , V_16 ,
V_34 -> V_52 , ( unsigned long long ) V_57 , V_58 ) ;
V_40 = F_19 ( V_34 -> V_35 ) ;
if ( V_34 -> V_64 > 0 ) {
struct V_55 * V_70 =
& V_40 -> V_71 [ V_34 -> V_64 - 1 ] ;
struct V_2 * V_72 = F_29 (
& V_34 -> V_44 , struct V_2 , V_73 ) ;
T_3 V_74 = F_30 ( V_70 -> V_57 ) ;
T_4 V_75 = F_31 ( V_70 -> V_76 ) ;
if ( ( V_3 -> V_17 == V_72 -> V_17 + V_77 ) &&
( V_57 >> F_32 ( V_60 -> V_78 ) ==
V_74 >> F_32 ( V_60 -> V_78 ) ) &&
( ( V_57 - V_74 ) * V_58 ==
V_75 >> 9 ) )
V_56 = V_70 ;
}
if ( ! V_56 ) {
V_56 = & V_40 -> V_71 [ V_34 -> V_64 ++ ] ;
V_56 -> V_57 = F_23 ( V_57 ) ;
V_56 -> V_79 = F_21 ( V_3 -> V_12 ) ;
V_56 -> V_80 = F_21 ( ~ 0 ) ;
}
F_33 ( & V_56 -> V_76 , V_58 << V_81 ) ;
if ( ! F_4 ( V_82 , & V_3 -> V_83 ) ) {
F_33 ( & V_56 -> V_62 , V_28 ) ;
V_34 -> V_62 += V_28 ;
V_56 -> V_80 = F_21 ( F_34 ( F_31 ( V_56 -> V_80 ) ,
F_19 ( V_3 -> V_27 ) ,
V_28 ) ) ;
}
F_26 ( & V_3 -> V_73 , & V_34 -> V_44 ) ;
F_35 ( & V_34 -> V_45 ) ;
V_3 -> V_84 = V_34 ;
return 0 ;
}
int F_36 ( struct V_59 * V_60 , struct V_2 * V_3 )
{
struct V_38 * V_38 = V_60 -> V_85 ;
struct V_33 * V_34 = V_3 -> V_84 ;
struct V_37 * log ;
if ( V_34 || F_4 ( V_86 , & V_3 -> V_83 ) || ! V_3 -> V_27 ||
! F_4 ( V_69 , & V_3 -> V_20 [ V_3 -> V_12 ] . V_24 ) ||
! F_4 ( V_87 , & V_3 -> V_20 [ V_3 -> V_12 ] . V_24 ) ) {
F_37 ( V_88 , & V_3 -> V_83 ) ;
return - V_89 ;
}
log = & V_38 -> V_90 [ V_3 -> V_12 ] ;
F_38 ( & log -> V_91 ) ;
if ( ! log -> V_92 || F_4 ( V_93 , & log -> V_92 -> V_24 ) ) {
F_39 ( & log -> V_91 ) ;
return - V_89 ;
}
F_40 ( V_88 , & V_3 -> V_83 ) ;
F_37 ( V_94 , & V_3 -> V_83 ) ;
F_35 ( & V_3 -> V_11 ) ;
if ( F_24 ( log , V_3 ) ) {
F_25 ( & V_38 -> V_95 ) ;
F_26 ( & V_3 -> V_73 , & V_38 -> V_96 ) ;
F_27 ( & V_38 -> V_95 ) ;
}
F_39 ( & log -> V_91 ) ;
return 0 ;
}
static void F_41 ( struct V_46 * V_46 )
{
struct V_33 * V_34 = V_46 -> V_97 ;
struct V_37 * log = V_34 -> log ;
struct V_38 * V_38 = log -> V_38 ;
struct V_2 * V_3 , * V_98 ;
F_3 ( L_5 , V_16 , V_34 -> V_52 ) ;
if ( V_46 -> V_99 )
F_42 ( V_38 -> V_100 , log -> V_92 ) ;
F_43 (sh, next, &io->stripe_list, log_list) {
F_44 ( & V_3 -> V_73 ) ;
F_40 ( V_101 , & V_3 -> V_83 ) ;
F_45 ( V_3 ) ;
}
}
static void F_46 ( struct V_33 * V_34 , struct V_46 * V_46 )
{
char V_102 [ V_103 ] ;
F_3 ( L_6 ,
V_16 , V_34 -> V_52 , V_46 -> V_104 . V_105 ,
( unsigned long long ) V_46 -> V_104 . V_106 ,
F_47 ( V_46 , V_102 ) ) ;
F_48 ( V_46 ) ;
}
static void F_49 ( struct V_33 * V_34 )
{
struct V_37 * log = V_34 -> log ;
struct V_38 * V_38 = log -> V_38 ;
struct V_39 * V_40 = F_19 ( V_34 -> V_35 ) ;
struct V_46 * V_46 = & V_34 -> V_46 ;
struct V_2 * V_3 ;
int V_13 ;
V_46 -> V_97 = V_34 ;
if ( ! log -> V_92 || F_4 ( V_93 , & log -> V_92 -> V_24 ) ) {
F_41 ( V_46 ) ;
return;
}
for ( V_13 = 0 ; V_13 < V_34 -> V_64 ; V_13 ++ ) {
struct V_55 * V_56 = & V_40 -> V_71 [ V_13 ] ;
F_3 ( L_7 ,
V_16 , V_34 -> V_52 , V_13 , F_30 ( V_56 -> V_57 ) ,
F_31 ( V_56 -> V_62 ) , F_31 ( V_56 -> V_76 ) ) ;
V_56 -> V_57 = F_23 ( F_30 ( V_56 -> V_57 ) >>
F_32 ( V_38 -> V_107 >> 9 ) ) ;
V_56 -> V_80 = F_21 ( ~ F_31 ( V_56 -> V_80 ) ) ;
}
V_40 -> V_64 = F_21 ( V_34 -> V_64 ) ;
V_40 -> V_80 = F_21 ( ~ F_34 ( ~ 0 , V_40 , V_108 ) ) ;
if ( log -> V_109 &&
log -> V_92 -> V_110 . V_17 + log -> V_92 -> V_110 . V_111 - log -> V_112 <
( V_108 + V_34 -> V_62 ) >> 9 )
log -> V_112 = log -> V_92 -> V_110 . V_17 ;
V_46 -> V_113 = F_41 ;
V_46 -> V_114 = V_115 | V_116 ;
F_50 ( V_46 , log -> V_92 -> V_117 ) ;
V_46 -> V_104 . V_106 = log -> V_112 ;
F_51 ( V_46 , V_34 -> V_35 , V_28 , 0 ) ;
F_3 ( L_8 , V_16 ,
( unsigned long long ) log -> V_112 ) ;
if ( log -> V_109 )
log -> V_112 += ( V_108 + V_34 -> V_62 ) >> 9 ;
F_52 (sh, &io->stripe_list, log_list) {
if ( F_4 ( V_82 , & V_3 -> V_83 ) )
continue;
if ( ! F_51 ( V_46 , V_3 -> V_27 , V_28 , 0 ) ) {
struct V_46 * V_118 = V_46 ;
V_46 = F_53 ( V_119 , V_120 ,
V_38 -> V_121 ) ;
V_46 -> V_114 = V_118 -> V_114 ;
F_54 ( V_46 , V_118 ) ;
V_46 -> V_104 . V_106 = F_55 ( V_118 ) ;
F_51 ( V_46 , V_3 -> V_27 , V_28 , 0 ) ;
F_56 ( V_46 , V_118 ) ;
F_46 ( V_34 , V_118 ) ;
}
}
F_46 ( V_34 , V_46 ) ;
}
static void F_57 ( struct V_37 * log )
{
struct V_33 * V_34 ;
F_25 ( & log -> V_67 ) ;
V_34 = F_58 ( & log -> V_68 , struct V_33 ,
V_43 ) ;
if ( V_34 && V_34 -> V_122 )
V_34 = NULL ;
F_27 ( & log -> V_67 ) ;
if ( V_34 ) {
V_34 -> V_122 = true ;
if ( V_34 == log -> V_54 )
log -> V_54 = NULL ;
F_49 ( V_34 ) ;
}
}
void F_59 ( struct V_59 * V_60 )
{
struct V_38 * V_38 = V_60 -> V_85 ;
struct V_37 * log ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_38 -> V_11 ; V_13 ++ ) {
log = & V_38 -> V_90 [ V_13 ] ;
F_38 ( & log -> V_91 ) ;
F_57 ( log ) ;
F_39 ( & log -> V_91 ) ;
}
}
static void F_60 ( struct V_33 * V_34 )
{
struct V_37 * log = V_34 -> log ;
struct V_38 * V_38 = log -> V_38 ;
unsigned long V_24 ;
F_3 ( L_5 , V_16 , V_34 -> V_52 ) ;
F_61 ( V_24 ) ;
F_62 ( & log -> V_67 ) ;
F_63 ( & V_34 -> V_43 ) ;
F_64 ( & log -> V_67 ) ;
F_65 ( V_34 , V_38 -> V_41 ) ;
F_62 ( & V_38 -> V_95 ) ;
if ( ! F_66 ( & V_38 -> V_96 ) ) {
struct V_2 * V_3 ;
V_3 = F_67 ( & V_38 -> V_96 ,
struct V_2 , V_73 ) ;
F_44 ( & V_3 -> V_73 ) ;
F_40 ( V_101 , & V_3 -> V_83 ) ;
F_45 ( V_3 ) ;
}
F_64 ( & V_38 -> V_95 ) ;
F_68 ( V_24 ) ;
}
void F_69 ( struct V_2 * V_3 )
{
struct V_33 * V_34 ;
V_34 = V_3 -> V_84 ;
V_3 -> V_84 = NULL ;
if ( V_34 && F_70 ( & V_34 -> V_45 ) )
F_60 ( V_34 ) ;
}
static void F_71 ( int V_111 , struct V_8 * V_123 , struct V_8 * V_124 )
{
struct V_14 V_15 ;
struct V_1 * V_6 ;
struct V_8 * V_125 [] = { V_123 , V_124 } ;
F_5 ( & V_15 , V_126 | V_127 ,
NULL , NULL , NULL , NULL ) ;
V_6 = F_7 ( V_123 , V_125 , 0 , 2 , V_111 , & V_15 ) ;
F_72 ( & V_6 ) ;
}
static int F_73 ( struct V_37 * log , struct V_55 * V_56 ,
T_2 V_128 )
{
struct V_38 * V_38 = log -> V_38 ;
struct V_100 * V_100 = V_38 -> V_100 ;
struct V_59 * V_60 = V_100 -> V_129 ;
int V_107 = V_38 -> V_107 ;
struct V_8 * V_123 ;
struct V_8 * V_124 ;
T_2 V_130 ;
T_2 V_131 ;
int V_132 ;
int V_58 ;
int V_13 ;
int V_133 = 0 ;
char V_102 [ V_103 ] ;
unsigned int V_62 = F_31 ( V_56 -> V_62 ) ;
unsigned int V_76 = F_31 ( V_56 -> V_76 ) ;
V_123 = F_10 ( V_134 ) ;
V_124 = F_10 ( V_134 ) ;
if ( ! V_123 || ! V_124 ) {
V_133 = - V_66 ;
goto V_135;
}
V_130 = F_30 ( V_56 -> V_57 ) * ( V_107 >> 9 ) ;
if ( ( V_62 >> 9 ) < V_60 -> V_78 ) {
if ( V_62 > 0 ) {
V_58 = V_76 / V_62 ;
V_132 = V_62 >> 9 ;
} else {
V_58 = V_60 -> V_136 - V_60 -> V_137 ;
V_132 = ( V_76 >> 9 ) / V_58 ;
}
V_131 = V_130 +
( V_58 - 1 ) * V_60 -> V_78 +
V_132 ;
} else {
V_58 = V_60 -> V_136 - V_60 -> V_137 ;
V_132 = V_60 -> V_78 ;
V_131 = V_130 + ( V_76 >> 9 ) ;
}
F_3 ( L_9 , V_16 ,
( unsigned long long ) V_130 ,
( unsigned long long ) V_131 ) ;
if ( V_107 == 512 &&
( V_130 & ( V_77 - 1 ) ) == 0 &&
( V_131 & ( V_77 - 1 ) ) == 0 )
V_107 = V_138 ;
for ( V_13 = 0 ; V_13 < V_132 ; V_13 += ( V_107 >> 9 ) ) {
bool V_139 = false ;
T_2 V_140 ;
struct V_141 * V_142 ;
struct V_2 V_3 ;
int V_143 ;
int V_144 = 0 ;
F_3 ( L_10 , V_16 , V_144 , L_11 , V_13 ) ;
V_144 += 2 ;
memset ( F_19 ( V_123 ) , 0 , V_28 ) ;
for ( V_143 = 0 ; V_143 < V_58 ; V_143 ++ ) {
int V_145 ;
struct V_141 * V_92 ;
T_2 V_17 ;
T_2 V_146 = V_130 + V_13 +
( V_143 * V_60 -> V_78 ) ;
F_3 ( L_12 ,
V_16 , V_144 , L_11 , V_143 ) ;
V_144 += 2 ;
if ( V_146 >= V_131 ) {
F_3 ( L_13 ,
V_16 , V_144 , L_11 ,
( unsigned long long ) V_146 ) ;
V_144 -= 2 ;
continue;
}
V_139 = true ;
V_17 = F_74 ( V_60 , V_146 , 0 ,
& V_145 , NULL ) ;
F_3 ( L_14 ,
V_16 , V_144 , L_11 ,
( unsigned long long ) V_146 , V_145 ,
( unsigned long long ) V_17 ) ;
V_92 = V_60 -> V_7 [ V_145 ] . V_92 ;
if ( ! V_92 ) {
F_3 ( L_15 ,
V_16 , V_144 , L_11 , V_145 ) ;
V_139 = false ;
break;
}
F_3 ( L_16 ,
V_16 , V_144 , L_11 , F_75 ( V_92 -> V_117 , V_102 ) ,
( unsigned long long ) V_17 ) ;
if ( ! F_76 ( V_92 , V_17 , V_107 , V_124 ,
V_147 , 0 , false ) ) {
F_42 ( V_100 , V_92 ) ;
F_3 ( L_17 , V_16 ,
V_144 , L_11 ) ;
V_133 = - V_148 ;
goto V_135;
}
F_71 ( V_107 , V_123 , V_124 ) ;
V_144 -= 2 ;
}
if ( ! V_139 )
continue;
if ( V_62 > 0 ) {
F_3 ( L_18 ,
V_16 , V_144 , L_11 ,
( unsigned long long ) ( V_128 + V_13 ) ) ;
if ( ! F_76 ( log -> V_92 ,
V_128 - log -> V_92 -> V_149 + V_13 ,
V_107 , V_124 , V_147 , 0 ,
false ) ) {
F_3 ( L_17 , V_16 ,
V_144 , L_11 ) ;
F_42 ( V_100 , log -> V_92 ) ;
V_133 = - V_148 ;
goto V_135;
}
F_71 ( V_107 , V_123 , V_124 ) ;
}
V_140 = F_74 ( V_60 , V_130 + V_13 ,
0 , & V_143 , & V_3 ) ;
F_28 ( V_3 . V_12 != F_31 ( V_56 -> V_79 ) ) ;
V_142 = V_60 -> V_7 [ V_3 . V_12 ] . V_92 ;
F_28 ( V_142 -> V_117 -> V_150 != log -> V_92 -> V_117 -> V_150 ) ;
F_3 ( L_19 ,
V_16 , V_144 , L_11 ,
( unsigned long long ) V_140 ,
F_75 ( V_142 -> V_117 , V_102 ) ) ;
if ( ! F_76 ( V_142 , V_140 , V_107 ,
V_123 , V_115 , 0 , false ) ) {
F_3 ( L_20 , V_16 ,
V_144 , L_11 ) ;
F_42 ( V_100 , V_142 ) ;
V_133 = - V_148 ;
goto V_135;
}
}
V_135:
if ( V_123 )
F_13 ( V_123 ) ;
if ( V_124 )
F_13 ( V_124 ) ;
return V_133 ;
}
static int F_77 ( struct V_37 * log , struct V_39 * V_40 ,
T_2 V_151 )
{
struct V_38 * V_38 = log -> V_38 ;
struct V_141 * V_92 = log -> V_92 ;
struct V_100 * V_100 = V_92 -> V_100 ;
T_2 V_128 = V_92 -> V_110 . V_17 + V_151 +
( V_108 >> 9 ) ;
struct V_8 * V_8 ;
int V_13 ;
int V_133 = 0 ;
V_8 = F_10 ( V_134 ) ;
if ( ! V_8 )
return - V_66 ;
for ( V_13 = 0 ; V_13 < F_31 ( V_40 -> V_64 ) ; V_13 ++ ) {
struct V_55 * V_56 = & V_40 -> V_71 [ V_13 ] ;
T_4 V_62 = F_31 ( V_56 -> V_62 ) ;
T_2 V_17 = V_128 ;
int V_152 = V_62 >> 9 ;
T_4 V_153 , V_154 ;
F_3 ( L_21 ,
V_16 , V_92 -> V_155 , V_13 ,
( unsigned long long ) V_128 , V_62 ) ;
V_153 = ~ 0 ;
V_154 = F_31 ( V_56 -> V_80 ) ;
while ( V_62 ) {
int V_156 = V_62 > V_28 ? V_28 : V_62 ;
if ( ! F_76 ( V_92 , V_17 - V_92 -> V_149 ,
V_156 , V_8 , V_147 , 0 , false ) ) {
F_42 ( V_100 , V_92 ) ;
V_133 = - V_148 ;
goto V_135;
}
V_153 = F_34 ( V_153 , F_19 ( V_8 ) , V_156 ) ;
V_62 -= V_156 ;
V_17 += V_156 >> 9 ;
}
V_153 = ~ V_153 ;
if ( V_153 != V_154 ) {
F_3 ( L_22 ,
V_16 , V_154 , V_153 ) ;
V_38 -> V_157 ++ ;
} else {
V_133 = F_73 ( log , V_56 , V_128 ) ;
if ( V_133 )
goto V_135;
V_38 -> V_158 ++ ;
}
V_128 += V_152 ;
}
V_133 = F_78 ( V_92 -> V_117 , V_134 , NULL ) ;
V_135:
F_13 ( V_8 ) ;
return V_133 ;
}
static int F_79 ( struct V_37 * log )
{
struct V_8 * V_8 ;
struct V_39 * V_40 ;
struct V_141 * V_92 = log -> V_92 ;
int V_133 = 0 ;
F_3 ( L_23 , V_16 ,
V_92 -> V_155 , ( unsigned long long ) V_92 -> V_110 . V_17 ) ;
V_8 = F_10 ( V_119 | V_159 ) ;
if ( ! V_8 )
return - V_66 ;
V_40 = F_19 ( V_8 ) ;
F_80 ( V_92 -> V_117 , V_92 -> V_110 . V_17 ,
log -> V_92 -> V_110 . V_111 , V_119 , 0 ) ;
memset ( V_40 -> V_49 , 0xff , V_50 ) ;
V_40 -> V_51 = F_21 ( log -> V_38 -> V_51 ) ;
V_40 -> V_80 = F_21 ( ~ F_34 ( ~ 0 , V_40 , V_28 ) ) ;
if ( ! F_76 ( V_92 , V_92 -> V_110 . V_17 - V_92 -> V_149 ,
V_108 , V_8 , V_115 | V_160 |
V_116 , 0 , false ) ) {
F_42 ( V_92 -> V_100 , V_92 ) ;
V_133 = - V_148 ;
}
F_13 ( V_8 ) ;
return V_133 ;
}
static int F_81 ( struct V_37 * log )
{
struct V_38 * V_38 = log -> V_38 ;
struct V_141 * V_92 = log -> V_92 ;
struct V_100 * V_100 = V_92 -> V_100 ;
struct V_8 * V_8 , * V_124 , * V_161 ;
struct V_39 * V_40 = NULL , * V_162 = NULL ;
T_4 V_153 , V_154 ;
T_4 V_51 ;
int V_133 = 0 , V_13 ;
T_2 V_163 = 0 , V_164 = 0 ;
F_3 ( L_24 , V_16 , V_92 -> V_155 ) ;
V_8 = F_10 ( V_134 ) ;
if ( ! V_8 )
return - V_66 ;
V_124 = F_10 ( V_134 ) ;
if ( ! V_124 ) {
F_13 ( V_8 ) ;
return - V_66 ;
}
while ( V_163 < V_92 -> V_110 . V_111 - ( V_108 >> 9 ) ) {
if ( ! F_76 ( V_92 ,
V_92 -> V_110 . V_17 - V_92 -> V_149 +
V_163 , V_28 , V_8 , V_147 ,
0 , false ) ) {
F_42 ( V_100 , V_92 ) ;
V_133 = - V_148 ;
V_40 = NULL ;
break;
}
V_40 = F_19 ( V_8 ) ;
V_154 = F_31 ( V_40 -> V_80 ) ;
V_40 -> V_80 = 0 ;
V_153 = ~ F_34 ( ~ 0 , V_40 , V_28 ) ;
if ( V_154 != V_153 ) {
F_3 ( L_25 ,
V_16 , V_154 , V_153 ,
( unsigned long long ) V_163 ) ;
V_40 = V_162 ;
V_163 = V_164 ;
break;
}
V_51 = F_31 ( V_40 -> V_51 ) ;
if ( V_100 -> V_165 ) {
V_38 -> V_51 = V_51 ;
} else if ( V_38 -> V_51 != V_51 ) {
F_3 ( L_26 ,
V_16 , V_51 , V_38 -> V_51 ,
( unsigned long long ) V_163 ) ;
V_40 = V_162 ;
V_163 = V_164 ;
break;
}
if ( V_162 && F_30 ( V_162 -> V_53 ) >
F_30 ( V_40 -> V_53 ) ) {
V_40 = V_162 ;
V_163 = V_164 ;
break;
}
V_164 = V_163 ;
V_162 = V_40 ;
V_161 = V_8 ;
V_8 = V_124 ;
V_124 = V_161 ;
for ( V_13 = 0 ; V_13 < F_31 ( V_40 -> V_64 ) ; V_13 ++ )
V_163 +=
F_31 ( V_40 -> V_71 [ V_13 ] . V_62 ) >> 9 ;
V_163 += V_108 >> 9 ;
}
if ( ! V_40 )
V_38 -> V_157 ++ ;
else
F_3 ( L_27 ,
V_16 , ( unsigned long long ) V_163 ,
F_30 ( V_40 -> V_53 ) ) ;
if ( V_40 && ! V_100 -> V_166 && V_100 -> V_167 != V_168 )
V_133 = F_77 ( log , V_40 , V_163 ) ;
if ( ! V_133 && ! V_100 -> V_166 )
V_133 = F_79 ( log ) ;
F_13 ( V_8 ) ;
F_13 ( V_124 ) ;
F_3 ( L_28 ,
V_16 , V_133 , V_38 -> V_157 ,
V_38 -> V_158 ) ;
return V_133 ;
}
static int F_82 ( struct V_38 * V_38 )
{
int V_133 = 0 ;
T_4 V_51 = 0 ;
bool V_169 = false ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_38 -> V_11 ; V_13 ++ ) {
struct V_37 * log = & V_38 -> V_90 [ V_13 ] ;
if ( ! log -> V_92 )
continue;
V_133 = F_81 ( log ) ;
if ( V_133 )
break;
if ( V_38 -> V_100 -> V_165 ) {
if ( ! V_169 ) {
V_51 = V_38 -> V_51 ;
V_169 = true ;
} else if ( V_51 != V_38 -> V_51 ) {
F_83 ( L_29 ,
F_84 ( V_38 -> V_100 ) ) ;
V_133 = - V_170 ;
break;
}
}
}
F_3 ( L_28 ,
V_16 , V_133 , V_38 -> V_157 ,
V_38 -> V_158 ) ;
return V_133 ;
}
static void F_85 ( struct V_38 * V_38 )
{
F_37 ( V_171 , & V_38 -> V_100 -> V_24 ) ;
F_37 ( V_172 , & V_38 -> V_100 -> V_24 ) ;
F_86 ( V_38 -> V_90 ) ;
if ( V_38 -> V_121 )
F_87 ( V_38 -> V_121 ) ;
F_88 ( V_38 -> V_41 ) ;
F_89 ( V_38 -> V_173 ) ;
F_86 ( V_38 ) ;
}
void F_90 ( struct V_59 * V_60 )
{
struct V_38 * V_38 = V_60 -> V_85 ;
if ( V_38 ) {
F_85 ( V_38 ) ;
V_60 -> V_85 = NULL ;
}
}
static int F_91 ( struct V_141 * V_92 )
{
char V_102 [ V_103 ] ;
int V_174 ;
int V_175 ;
V_174 = V_92 -> V_110 . V_111 - ( V_108 >> 9 ) ;
if ( V_174 > 0 )
V_174 = F_92 ( V_174 , V_77 ) ;
if ( V_174 <= 0 ) {
F_83 ( L_30 ,
F_84 ( V_92 -> V_100 ) , F_75 ( V_92 -> V_117 , V_102 ) ) ;
return - V_176 ;
}
V_175 = V_174 + ( V_108 >> 9 ) ;
if ( ( V_92 -> V_110 . V_17 < V_92 -> V_149 &&
V_92 -> V_110 . V_17 + V_175 > V_92 -> V_149 ) ||
( V_92 -> V_110 . V_17 >= V_92 -> V_149 &&
V_92 -> V_149 + V_92 -> V_177 > V_92 -> V_110 . V_17 ) ) {
F_83 ( L_31 ,
F_84 ( V_92 -> V_100 ) , F_75 ( V_92 -> V_117 , V_102 ) ) ;
return - V_170 ;
}
if ( ! V_92 -> V_100 -> V_165 &&
( ( V_92 -> V_110 . V_151 > 0 && V_92 -> V_110 . V_151 < ( V_92 -> V_178 >> 9 ) ) ||
( V_92 -> V_110 . V_151 <= 0 && V_92 -> V_110 . V_151 + V_175 > 0 ) ) ) {
F_83 ( L_32 ,
F_84 ( V_92 -> V_100 ) , F_75 ( V_92 -> V_117 , V_102 ) ) ;
return - V_170 ;
}
V_92 -> V_110 . V_111 = V_175 ;
return 0 ;
}
static void F_93 ( struct V_37 * log , struct V_141 * V_92 )
{
if ( ( V_92 -> V_110 . V_111 << 9 ) >= ( V_179 +
V_108 ) * 2 ) {
log -> V_109 = true ;
F_40 ( V_172 ,
& log -> V_38 -> V_100 -> V_24 ) ;
log -> V_63 = V_179 ;
} else {
log -> V_109 = false ;
log -> V_63 = ( log -> V_92 -> V_110 . V_111 << 9 ) -
V_108 ;
}
log -> V_112 = V_92 -> V_110 . V_17 ;
}
int F_94 ( struct V_59 * V_60 )
{
struct V_38 * V_38 ;
struct V_100 * V_100 = V_60 -> V_100 ;
int V_133 = 0 ;
int V_13 ;
bool V_180 = false ;
F_3 ( L_33 ,
F_84 ( V_60 -> V_100 ) ) ;
if ( V_28 != 4096 )
return - V_170 ;
if ( V_100 -> V_181 != 5 ) {
F_83 ( L_34 ,
F_84 ( V_100 ) , V_100 -> V_181 ) ;
return - V_170 ;
}
if ( V_100 -> V_182 . V_183 || V_100 -> V_182 . V_151 ) {
F_83 ( L_35 ,
F_84 ( V_100 ) ) ;
return - V_170 ;
}
if ( F_4 ( V_184 , & V_100 -> V_24 ) ) {
F_83 ( L_36 ,
F_84 ( V_100 ) ) ;
return - V_170 ;
}
V_38 = F_95 ( sizeof( struct V_38 ) , V_134 ) ;
if ( ! V_38 )
return - V_66 ;
V_38 -> V_100 = V_100 ;
V_38 -> V_173 = F_96 ( V_33 , 0 ) ;
if ( ! V_38 -> V_173 ) {
V_133 = - V_66 ;
goto V_185;
}
V_38 -> V_41 = F_97 ( V_60 -> V_136 , F_8 ,
F_12 , V_38 -> V_173 ) ;
if ( ! V_38 -> V_41 ) {
V_133 = - V_66 ;
goto V_185;
}
V_38 -> V_121 = F_98 ( V_60 -> V_136 , 0 , V_186 ) ;
if ( ! V_38 -> V_121 ) {
V_133 = - V_66 ;
goto V_185;
}
V_38 -> V_11 = V_60 -> V_136 ;
V_38 -> V_90 = F_99 ( V_38 -> V_11 , sizeof( struct V_37 ) ,
V_134 ) ;
if ( ! V_38 -> V_90 ) {
V_133 = - V_66 ;
goto V_185;
}
F_100 ( & V_38 -> V_52 , 0 ) ;
F_16 ( & V_38 -> V_96 ) ;
F_101 ( & V_38 -> V_95 ) ;
if ( ! V_100 -> V_165 ) {
V_38 -> V_51 = ~ F_34 ( ~ 0 , V_100 -> V_187 , sizeof( V_100 -> V_187 ) ) ;
V_38 -> V_107 = 512 ;
} else {
V_38 -> V_107 = F_102 ( V_100 -> V_188 ) ;
}
for ( V_13 = 0 ; V_13 < V_38 -> V_11 ; V_13 ++ ) {
struct V_37 * log = & V_38 -> V_90 [ V_13 ] ;
struct V_141 * V_92 = V_60 -> V_7 [ V_13 ] . V_92 ;
F_103 ( & log -> V_91 ) ;
F_101 ( & log -> V_67 ) ;
F_16 ( & log -> V_68 ) ;
log -> V_38 = V_38 ;
log -> V_92 = V_92 ;
if ( V_92 ) {
struct V_189 * V_190 ;
V_133 = F_91 ( V_92 ) ;
if ( V_133 )
goto V_185;
V_190 = F_104 ( V_92 -> V_117 ) ;
if ( F_4 ( V_191 , & V_190 -> V_192 ) )
V_180 = true ;
F_93 ( log , V_92 ) ;
}
}
if ( V_180 )
F_83 ( L_37 ,
F_84 ( V_100 ) ) ;
V_133 = F_82 ( V_38 ) ;
if ( V_133 ) {
goto V_185;
} else if ( ! V_100 -> V_166 &&
V_100 -> V_167 == 0 && ! V_100 -> V_193 &&
V_38 -> V_158 > 0 &&
V_38 -> V_157 == 0 ) {
V_100 -> V_167 = V_168 ;
F_40 ( V_194 , & V_100 -> V_195 ) ;
} else if ( V_100 -> V_166 && V_38 -> V_157 > 0 ) {
V_133 = - V_170 ;
goto V_185;
}
V_60 -> V_85 = V_38 ;
F_40 ( V_171 , & V_38 -> V_100 -> V_24 ) ;
return 0 ;
V_185:
F_85 ( V_38 ) ;
return V_133 ;
}
int F_105 ( struct V_59 * V_60 , struct V_141 * V_92 , bool V_196 )
{
struct V_38 * V_38 = V_60 -> V_85 ;
struct V_37 * log ;
int V_133 = 0 ;
char V_102 [ V_103 ] ;
if ( ! V_92 )
return - V_170 ;
F_3 ( L_38 ,
V_16 , V_92 -> V_155 , V_196 ? L_39 : L_40 ,
F_75 ( V_92 -> V_117 , V_102 ) ) ;
if ( V_92 -> V_155 < 0 )
return 0 ;
if ( V_92 -> V_155 >= V_38 -> V_11 )
return - V_197 ;
log = & V_38 -> V_90 [ V_92 -> V_155 ] ;
F_38 ( & log -> V_91 ) ;
if ( V_196 ) {
V_133 = F_91 ( V_92 ) ;
if ( ! V_133 ) {
log -> V_92 = V_92 ;
V_133 = F_79 ( log ) ;
F_93 ( log , V_92 ) ;
}
} else {
log -> V_92 = NULL ;
}
F_39 ( & log -> V_91 ) ;
return V_133 ;
}
