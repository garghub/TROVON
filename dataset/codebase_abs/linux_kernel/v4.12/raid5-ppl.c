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
unsigned int V_59 = ( log -> V_60 -> V_61 . V_62 << 9 ) - V_63 ;
struct V_64 * V_65 = V_3 -> V_66 ;
F_3 ( L_2 , V_16 , ( unsigned long long ) V_3 -> V_17 ) ;
if ( V_34 && ( V_34 -> V_67 == V_59 ||
V_34 -> V_68 == V_69 ) ) {
F_3 ( L_3 ,
V_16 , V_34 -> V_52 ) ;
V_34 = NULL ;
}
if ( ! V_34 ) {
V_34 = F_14 ( log , V_3 ) ;
if ( ! V_34 )
return - V_70 ;
F_25 ( & log -> V_71 ) ;
F_26 ( & V_34 -> V_43 , & log -> V_72 ) ;
F_27 ( & log -> V_71 ) ;
log -> V_54 = V_34 ;
}
for ( V_13 = 0 ; V_13 < V_3 -> V_7 ; V_13 ++ ) {
struct V_22 * V_20 = & V_3 -> V_20 [ V_13 ] ;
if ( V_13 != V_3 -> V_12 && F_4 ( V_73 , & V_20 -> V_24 ) ) {
if ( ! V_58 || V_20 -> V_17 < V_57 )
V_57 = V_20 -> V_17 ;
V_58 ++ ;
}
}
F_28 ( ! V_58 ) ;
F_3 ( L_4 , V_16 ,
V_34 -> V_52 , ( unsigned long long ) V_57 , V_58 ) ;
V_40 = F_19 ( V_34 -> V_35 ) ;
if ( V_34 -> V_68 > 0 ) {
struct V_55 * V_74 =
& V_40 -> V_75 [ V_34 -> V_68 - 1 ] ;
struct V_2 * V_76 = F_29 (
& V_34 -> V_44 , struct V_2 , V_77 ) ;
T_3 V_78 = F_30 ( V_74 -> V_57 ) ;
T_4 V_79 = F_31 ( V_74 -> V_80 ) ;
if ( ( V_3 -> V_17 == V_76 -> V_17 + V_81 ) &&
( V_57 >> F_32 ( V_65 -> V_82 ) ==
V_78 >> F_32 ( V_65 -> V_82 ) ) &&
( ( V_57 - V_78 ) * V_58 ==
V_79 >> 9 ) )
V_56 = V_74 ;
}
if ( ! V_56 ) {
V_56 = & V_40 -> V_75 [ V_34 -> V_68 ++ ] ;
V_56 -> V_57 = F_23 ( V_57 ) ;
V_56 -> V_83 = F_21 ( V_3 -> V_12 ) ;
V_56 -> V_84 = F_21 ( ~ 0 ) ;
}
F_33 ( & V_56 -> V_80 , V_58 << V_85 ) ;
if ( ! F_4 ( V_86 , & V_3 -> V_87 ) ) {
F_33 ( & V_56 -> V_67 , V_28 ) ;
V_34 -> V_67 += V_28 ;
V_56 -> V_84 = F_21 ( F_34 ( F_31 ( V_56 -> V_84 ) ,
F_19 ( V_3 -> V_27 ) ,
V_28 ) ) ;
}
F_26 ( & V_3 -> V_77 , & V_34 -> V_44 ) ;
F_35 ( & V_34 -> V_45 ) ;
V_3 -> V_88 = V_34 ;
return 0 ;
}
int F_36 ( struct V_64 * V_65 , struct V_2 * V_3 )
{
struct V_38 * V_38 = V_65 -> V_89 ;
struct V_33 * V_34 = V_3 -> V_88 ;
struct V_37 * log ;
if ( V_34 || F_4 ( V_90 , & V_3 -> V_87 ) || ! V_3 -> V_27 ||
! F_4 ( V_73 , & V_3 -> V_20 [ V_3 -> V_12 ] . V_24 ) ||
! F_4 ( V_91 , & V_3 -> V_20 [ V_3 -> V_12 ] . V_24 ) ) {
F_37 ( V_92 , & V_3 -> V_87 ) ;
return - V_93 ;
}
log = & V_38 -> V_94 [ V_3 -> V_12 ] ;
F_38 ( & log -> V_95 ) ;
if ( ! log -> V_60 || F_4 ( V_96 , & log -> V_60 -> V_24 ) ) {
F_39 ( & log -> V_95 ) ;
return - V_93 ;
}
F_40 ( V_92 , & V_3 -> V_87 ) ;
F_37 ( V_97 , & V_3 -> V_87 ) ;
F_35 ( & V_3 -> V_11 ) ;
if ( F_24 ( log , V_3 ) ) {
F_25 ( & V_38 -> V_98 ) ;
F_26 ( & V_3 -> V_77 , & V_38 -> V_99 ) ;
F_27 ( & V_38 -> V_98 ) ;
}
F_39 ( & log -> V_95 ) ;
return 0 ;
}
static void F_41 ( struct V_46 * V_46 )
{
struct V_33 * V_34 = V_46 -> V_100 ;
struct V_37 * log = V_34 -> log ;
struct V_38 * V_38 = log -> V_38 ;
struct V_2 * V_3 , * V_101 ;
F_3 ( L_5 , V_16 , V_34 -> V_52 ) ;
if ( V_46 -> V_102 )
F_42 ( V_38 -> V_103 , log -> V_60 ) ;
F_43 (sh, next, &io->stripe_list, log_list) {
F_44 ( & V_3 -> V_77 ) ;
F_40 ( V_104 , & V_3 -> V_87 ) ;
F_45 ( V_3 ) ;
}
}
static void F_46 ( struct V_33 * V_34 , struct V_46 * V_46 )
{
char V_105 [ V_106 ] ;
F_3 ( L_6 ,
V_16 , V_34 -> V_52 , V_46 -> V_107 . V_108 ,
( unsigned long long ) V_46 -> V_107 . V_109 ,
F_47 ( V_46 -> V_110 , V_105 ) ) ;
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
V_46 -> V_100 = V_34 ;
if ( ! log -> V_60 || F_4 ( V_96 , & log -> V_60 -> V_24 ) ) {
F_41 ( V_46 ) ;
return;
}
for ( V_13 = 0 ; V_13 < V_34 -> V_68 ; V_13 ++ ) {
struct V_55 * V_56 = & V_40 -> V_75 [ V_13 ] ;
F_3 ( L_7 ,
V_16 , V_34 -> V_52 , V_13 , F_30 ( V_56 -> V_57 ) ,
F_31 ( V_56 -> V_67 ) , F_31 ( V_56 -> V_80 ) ) ;
V_56 -> V_57 = F_23 ( F_30 ( V_56 -> V_57 ) >>
F_32 ( V_38 -> V_111 >> 9 ) ) ;
V_56 -> V_84 = F_21 ( ~ F_31 ( V_56 -> V_84 ) ) ;
}
V_40 -> V_68 = F_21 ( V_34 -> V_68 ) ;
V_40 -> V_84 = F_21 ( ~ F_34 ( ~ 0 , V_40 , V_63 ) ) ;
V_46 -> V_112 = F_41 ;
V_46 -> V_113 = V_114 | V_115 ;
V_46 -> V_110 = log -> V_60 -> V_116 ;
V_46 -> V_107 . V_109 = log -> V_60 -> V_61 . V_17 ;
F_50 ( V_46 , V_34 -> V_35 , V_28 , 0 ) ;
F_51 (sh, &io->stripe_list, log_list) {
if ( F_4 ( V_86 , & V_3 -> V_87 ) )
continue;
if ( ! F_50 ( V_46 , V_3 -> V_27 , V_28 , 0 ) ) {
struct V_46 * V_117 = V_46 ;
V_46 = F_52 ( V_118 , V_119 ,
V_38 -> V_120 ) ;
V_46 -> V_113 = V_117 -> V_113 ;
V_46 -> V_110 = V_117 -> V_110 ;
V_46 -> V_107 . V_109 = F_53 ( V_117 ) ;
F_50 ( V_46 , V_3 -> V_27 , V_28 , 0 ) ;
F_54 ( V_46 , V_117 ) ;
F_46 ( V_34 , V_117 ) ;
}
}
F_46 ( V_34 , V_46 ) ;
}
static void F_55 ( struct V_37 * log )
{
struct V_33 * V_34 ;
F_25 ( & log -> V_71 ) ;
V_34 = F_56 ( & log -> V_72 , struct V_33 ,
V_43 ) ;
if ( V_34 && V_34 -> V_121 )
V_34 = NULL ;
F_27 ( & log -> V_71 ) ;
if ( V_34 ) {
V_34 -> V_121 = true ;
if ( V_34 == log -> V_54 )
log -> V_54 = NULL ;
F_49 ( V_34 ) ;
}
}
void F_57 ( struct V_64 * V_65 )
{
struct V_38 * V_38 = V_65 -> V_89 ;
struct V_37 * log ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_38 -> V_11 ; V_13 ++ ) {
log = & V_38 -> V_94 [ V_13 ] ;
F_38 ( & log -> V_95 ) ;
F_55 ( log ) ;
F_39 ( & log -> V_95 ) ;
}
}
static void F_58 ( struct V_33 * V_34 )
{
struct V_37 * log = V_34 -> log ;
struct V_38 * V_38 = log -> V_38 ;
unsigned long V_24 ;
F_3 ( L_5 , V_16 , V_34 -> V_52 ) ;
F_59 ( V_24 ) ;
F_60 ( & log -> V_71 ) ;
F_61 ( & V_34 -> V_43 ) ;
F_62 ( & log -> V_71 ) ;
F_63 ( V_34 , V_38 -> V_41 ) ;
F_60 ( & V_38 -> V_98 ) ;
if ( ! F_64 ( & V_38 -> V_99 ) ) {
struct V_2 * V_3 ;
V_3 = F_65 ( & V_38 -> V_99 ,
struct V_2 , V_77 ) ;
F_44 ( & V_3 -> V_77 ) ;
F_40 ( V_104 , & V_3 -> V_87 ) ;
F_45 ( V_3 ) ;
}
F_62 ( & V_38 -> V_98 ) ;
F_66 ( V_24 ) ;
}
void F_67 ( struct V_2 * V_3 )
{
struct V_33 * V_34 ;
V_34 = V_3 -> V_88 ;
V_3 -> V_88 = NULL ;
if ( V_34 && F_68 ( & V_34 -> V_45 ) )
F_58 ( V_34 ) ;
}
static void F_69 ( int V_62 , struct V_8 * V_122 , struct V_8 * V_123 )
{
struct V_14 V_15 ;
struct V_1 * V_6 ;
struct V_8 * V_124 [] = { V_122 , V_123 } ;
F_5 ( & V_15 , V_125 | V_126 ,
NULL , NULL , NULL , NULL ) ;
V_6 = F_7 ( V_122 , V_124 , 0 , 2 , V_62 , & V_15 ) ;
F_70 ( & V_6 ) ;
}
static int F_71 ( struct V_37 * log , struct V_55 * V_56 ,
T_2 V_127 )
{
struct V_38 * V_38 = log -> V_38 ;
struct V_103 * V_103 = V_38 -> V_103 ;
struct V_64 * V_65 = V_103 -> V_128 ;
int V_111 = V_38 -> V_111 ;
struct V_8 * V_122 ;
struct V_8 * V_123 ;
T_2 V_129 ;
T_2 V_130 ;
int V_131 ;
int V_58 ;
int V_13 ;
int V_132 = 0 ;
char V_105 [ V_106 ] ;
unsigned int V_67 = F_31 ( V_56 -> V_67 ) ;
unsigned int V_80 = F_31 ( V_56 -> V_80 ) ;
V_122 = F_10 ( V_133 ) ;
V_123 = F_10 ( V_133 ) ;
if ( ! V_122 || ! V_123 ) {
V_132 = - V_70 ;
goto V_134;
}
V_129 = F_30 ( V_56 -> V_57 ) * ( V_111 >> 9 ) ;
if ( ( V_67 >> 9 ) < V_65 -> V_82 ) {
if ( V_67 > 0 ) {
V_58 = V_80 / V_67 ;
V_131 = V_67 >> 9 ;
} else {
V_58 = V_65 -> V_135 - V_65 -> V_136 ;
V_131 = ( V_80 >> 9 ) / V_58 ;
}
V_130 = V_129 +
( V_58 - 1 ) * V_65 -> V_82 +
V_131 ;
} else {
V_58 = V_65 -> V_135 - V_65 -> V_136 ;
V_131 = V_65 -> V_82 ;
V_130 = V_129 + ( V_80 >> 9 ) ;
}
F_3 ( L_8 , V_16 ,
( unsigned long long ) V_129 ,
( unsigned long long ) V_130 ) ;
if ( V_111 == 512 &&
( V_129 & ( V_81 - 1 ) ) == 0 &&
( V_130 & ( V_81 - 1 ) ) == 0 )
V_111 = V_137 ;
for ( V_13 = 0 ; V_13 < V_131 ; V_13 += ( V_111 >> 9 ) ) {
bool V_138 = false ;
T_2 V_139 ;
struct V_140 * V_141 ;
struct V_2 V_3 ;
int V_142 ;
int V_143 = 0 ;
F_3 ( L_9 , V_16 , V_143 , L_10 , V_13 ) ;
V_143 += 2 ;
memset ( F_19 ( V_122 ) , 0 , V_28 ) ;
for ( V_142 = 0 ; V_142 < V_58 ; V_142 ++ ) {
int V_144 ;
struct V_140 * V_60 ;
T_2 V_17 ;
T_2 V_145 = V_129 + V_13 +
( V_142 * V_65 -> V_82 ) ;
F_3 ( L_11 ,
V_16 , V_143 , L_10 , V_142 ) ;
V_143 += 2 ;
if ( V_145 >= V_130 ) {
F_3 ( L_12 ,
V_16 , V_143 , L_10 ,
( unsigned long long ) V_145 ) ;
V_143 -= 2 ;
continue;
}
V_138 = true ;
V_17 = F_72 ( V_65 , V_145 , 0 ,
& V_144 , NULL ) ;
F_3 ( L_13 ,
V_16 , V_143 , L_10 ,
( unsigned long long ) V_145 , V_144 ,
( unsigned long long ) V_17 ) ;
V_60 = V_65 -> V_7 [ V_144 ] . V_60 ;
if ( ! V_60 ) {
F_3 ( L_14 ,
V_16 , V_143 , L_10 , V_144 ) ;
V_138 = false ;
break;
}
F_3 ( L_15 ,
V_16 , V_143 , L_10 , F_47 ( V_60 -> V_116 , V_105 ) ,
( unsigned long long ) V_17 ) ;
if ( ! F_73 ( V_60 , V_17 , V_111 , V_123 ,
V_146 , 0 , false ) ) {
F_42 ( V_103 , V_60 ) ;
F_3 ( L_16 , V_16 ,
V_143 , L_10 ) ;
V_132 = - V_147 ;
goto V_134;
}
F_69 ( V_111 , V_122 , V_123 ) ;
V_143 -= 2 ;
}
if ( ! V_138 )
continue;
if ( V_67 > 0 ) {
F_3 ( L_17 ,
V_16 , V_143 , L_10 ,
( unsigned long long ) ( V_127 + V_13 ) ) ;
if ( ! F_73 ( log -> V_60 ,
V_127 - log -> V_60 -> V_148 + V_13 ,
V_111 , V_123 , V_146 , 0 ,
false ) ) {
F_3 ( L_16 , V_16 ,
V_143 , L_10 ) ;
F_42 ( V_103 , log -> V_60 ) ;
V_132 = - V_147 ;
goto V_134;
}
F_69 ( V_111 , V_122 , V_123 ) ;
}
V_139 = F_72 ( V_65 , V_129 + V_13 ,
0 , & V_142 , & V_3 ) ;
F_28 ( V_3 . V_12 != F_31 ( V_56 -> V_83 ) ) ;
V_141 = V_65 -> V_7 [ V_3 . V_12 ] . V_60 ;
F_28 ( V_141 -> V_116 -> V_149 != log -> V_60 -> V_116 -> V_149 ) ;
F_3 ( L_18 ,
V_16 , V_143 , L_10 ,
( unsigned long long ) V_139 ,
F_47 ( V_141 -> V_116 , V_105 ) ) ;
if ( ! F_73 ( V_141 , V_139 , V_111 ,
V_122 , V_114 , 0 , false ) ) {
F_3 ( L_19 , V_16 ,
V_143 , L_10 ) ;
F_42 ( V_103 , V_141 ) ;
V_132 = - V_147 ;
goto V_134;
}
}
V_134:
if ( V_122 )
F_13 ( V_122 ) ;
if ( V_123 )
F_13 ( V_123 ) ;
return V_132 ;
}
static int F_74 ( struct V_37 * log , struct V_39 * V_40 )
{
struct V_38 * V_38 = log -> V_38 ;
struct V_140 * V_60 = log -> V_60 ;
struct V_103 * V_103 = V_60 -> V_103 ;
T_2 V_127 = V_60 -> V_61 . V_17 + ( V_63 >> 9 ) ;
struct V_8 * V_8 ;
int V_13 ;
int V_132 = 0 ;
V_8 = F_10 ( V_133 ) ;
if ( ! V_8 )
return - V_70 ;
for ( V_13 = 0 ; V_13 < F_31 ( V_40 -> V_68 ) ; V_13 ++ ) {
struct V_55 * V_56 = & V_40 -> V_75 [ V_13 ] ;
T_4 V_67 = F_31 ( V_56 -> V_67 ) ;
T_2 V_17 = V_127 ;
int V_150 = V_67 >> 9 ;
T_4 V_151 , V_152 ;
F_3 ( L_20 ,
V_16 , V_60 -> V_153 , V_13 ,
( unsigned long long ) V_127 , V_67 ) ;
V_151 = ~ 0 ;
V_152 = F_31 ( V_56 -> V_84 ) ;
while ( V_67 ) {
int V_154 = V_67 > V_28 ? V_28 : V_67 ;
if ( ! F_73 ( V_60 , V_17 - V_60 -> V_148 ,
V_154 , V_8 , V_146 , 0 , false ) ) {
F_42 ( V_103 , V_60 ) ;
V_132 = - V_147 ;
goto V_134;
}
V_151 = F_34 ( V_151 , F_19 ( V_8 ) , V_154 ) ;
V_67 -= V_154 ;
V_17 += V_154 >> 9 ;
}
V_151 = ~ V_151 ;
if ( V_151 != V_152 ) {
F_3 ( L_21 ,
V_16 , V_152 , V_151 ) ;
V_38 -> V_155 ++ ;
} else {
V_132 = F_71 ( log , V_56 , V_127 ) ;
if ( V_132 )
goto V_134;
V_38 -> V_156 ++ ;
}
V_127 += V_150 ;
}
V_132 = F_75 ( V_60 -> V_116 , V_133 , NULL ) ;
V_134:
F_13 ( V_8 ) ;
return V_132 ;
}
static int F_76 ( struct V_37 * log )
{
struct V_8 * V_8 ;
struct V_39 * V_40 ;
struct V_140 * V_60 = log -> V_60 ;
int V_132 = 0 ;
F_3 ( L_22 , V_16 ,
V_60 -> V_153 , ( unsigned long long ) V_60 -> V_61 . V_17 ) ;
V_8 = F_10 ( V_118 | V_157 ) ;
if ( ! V_8 )
return - V_70 ;
V_40 = F_19 ( V_8 ) ;
memset ( V_40 -> V_49 , 0xff , V_50 ) ;
V_40 -> V_51 = F_21 ( log -> V_38 -> V_51 ) ;
V_40 -> V_84 = F_21 ( ~ F_34 ( ~ 0 , V_40 , V_28 ) ) ;
if ( ! F_73 ( V_60 , V_60 -> V_61 . V_17 - V_60 -> V_148 ,
V_63 , V_8 , V_114 | V_158 |
V_115 , 0 , false ) ) {
F_42 ( V_60 -> V_103 , V_60 ) ;
V_132 = - V_147 ;
}
F_13 ( V_8 ) ;
return V_132 ;
}
static int F_77 ( struct V_37 * log )
{
struct V_38 * V_38 = log -> V_38 ;
struct V_140 * V_60 = log -> V_60 ;
struct V_103 * V_103 = V_60 -> V_103 ;
struct V_8 * V_8 ;
struct V_39 * V_40 ;
T_4 V_151 , V_152 ;
T_4 V_51 ;
int V_132 = 0 ;
F_3 ( L_23 , V_16 , V_60 -> V_153 ) ;
V_8 = F_10 ( V_133 ) ;
if ( ! V_8 )
return - V_70 ;
if ( ! F_73 ( V_60 , V_60 -> V_61 . V_17 - V_60 -> V_148 ,
V_28 , V_8 , V_146 , 0 , false ) ) {
F_42 ( V_103 , V_60 ) ;
V_132 = - V_147 ;
goto V_134;
}
V_40 = F_19 ( V_8 ) ;
V_152 = F_31 ( V_40 -> V_84 ) ;
V_40 -> V_84 = 0 ;
V_151 = ~ F_34 ( ~ 0 , V_40 , V_28 ) ;
if ( V_152 != V_151 ) {
F_3 ( L_24 ,
V_16 , V_152 , V_151 ) ;
V_38 -> V_155 ++ ;
goto V_134;
}
V_51 = F_31 ( V_40 -> V_51 ) ;
if ( V_103 -> V_159 ) {
V_38 -> V_51 = V_51 ;
} else if ( V_38 -> V_51 != V_51 ) {
F_3 ( L_25 ,
V_16 , V_51 , V_38 -> V_51 ) ;
V_38 -> V_155 ++ ;
goto V_134;
}
if ( ! V_103 -> V_160 && V_103 -> V_161 != V_162 )
V_132 = F_74 ( log , V_40 ) ;
V_134:
if ( ! V_132 && ! V_103 -> V_160 )
V_132 = F_76 ( log ) ;
F_13 ( V_8 ) ;
F_3 ( L_26 ,
V_16 , V_132 , V_38 -> V_155 ,
V_38 -> V_156 ) ;
return V_132 ;
}
static int F_78 ( struct V_38 * V_38 )
{
int V_132 = 0 ;
T_4 V_51 = 0 ;
bool V_163 = false ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_38 -> V_11 ; V_13 ++ ) {
struct V_37 * log = & V_38 -> V_94 [ V_13 ] ;
if ( ! log -> V_60 )
continue;
V_132 = F_77 ( log ) ;
if ( V_132 )
break;
if ( V_38 -> V_103 -> V_159 ) {
if ( ! V_163 ) {
V_51 = V_38 -> V_51 ;
V_163 = true ;
} else if ( V_51 != V_38 -> V_51 ) {
F_79 ( L_27 ,
F_80 ( V_38 -> V_103 ) ) ;
V_132 = - V_164 ;
break;
}
}
}
F_3 ( L_26 ,
V_16 , V_132 , V_38 -> V_155 ,
V_38 -> V_156 ) ;
return V_132 ;
}
static void F_81 ( struct V_38 * V_38 )
{
F_37 ( V_165 , & V_38 -> V_103 -> V_24 ) ;
F_82 ( V_38 -> V_94 ) ;
if ( V_38 -> V_120 )
F_83 ( V_38 -> V_120 ) ;
F_84 ( V_38 -> V_41 ) ;
F_85 ( V_38 -> V_166 ) ;
F_82 ( V_38 ) ;
}
void F_86 ( struct V_64 * V_65 )
{
struct V_38 * V_38 = V_65 -> V_89 ;
if ( V_38 ) {
F_81 ( V_38 ) ;
V_65 -> V_89 = NULL ;
}
}
static int F_87 ( struct V_140 * V_60 )
{
char V_105 [ V_106 ] ;
int V_167 ;
int V_168 ;
V_167 = V_60 -> V_61 . V_62 - ( V_63 >> 9 ) ;
if ( V_167 > 0 )
V_167 = F_88 ( V_167 , V_81 ) ;
if ( V_167 <= 0 ) {
F_79 ( L_28 ,
F_80 ( V_60 -> V_103 ) , F_47 ( V_60 -> V_116 , V_105 ) ) ;
return - V_169 ;
}
V_168 = V_167 + ( V_63 >> 9 ) ;
if ( ( V_60 -> V_61 . V_17 < V_60 -> V_148 &&
V_60 -> V_61 . V_17 + V_168 > V_60 -> V_148 ) ||
( V_60 -> V_61 . V_17 >= V_60 -> V_148 &&
V_60 -> V_148 + V_60 -> V_170 > V_60 -> V_61 . V_17 ) ) {
F_79 ( L_29 ,
F_80 ( V_60 -> V_103 ) , F_47 ( V_60 -> V_116 , V_105 ) ) ;
return - V_164 ;
}
if ( ! V_60 -> V_103 -> V_159 &&
( ( V_60 -> V_61 . V_171 > 0 && V_60 -> V_61 . V_171 < ( V_60 -> V_172 >> 9 ) ) ||
( V_60 -> V_61 . V_171 <= 0 && V_60 -> V_61 . V_171 + V_168 > 0 ) ) ) {
F_79 ( L_30 ,
F_80 ( V_60 -> V_103 ) , F_47 ( V_60 -> V_116 , V_105 ) ) ;
return - V_164 ;
}
V_60 -> V_61 . V_62 = V_168 ;
return 0 ;
}
int F_89 ( struct V_64 * V_65 )
{
struct V_38 * V_38 ;
struct V_103 * V_103 = V_65 -> V_103 ;
int V_132 = 0 ;
int V_13 ;
bool V_173 = false ;
F_3 ( L_31 ,
F_80 ( V_65 -> V_103 ) ) ;
if ( V_28 != 4096 )
return - V_164 ;
if ( V_103 -> V_174 != 5 ) {
F_79 ( L_32 ,
F_80 ( V_103 ) , V_103 -> V_174 ) ;
return - V_164 ;
}
if ( V_103 -> V_175 . V_176 || V_103 -> V_175 . V_171 ) {
F_79 ( L_33 ,
F_80 ( V_103 ) ) ;
return - V_164 ;
}
if ( F_4 ( V_177 , & V_103 -> V_24 ) ) {
F_79 ( L_34 ,
F_80 ( V_103 ) ) ;
return - V_164 ;
}
V_38 = F_90 ( sizeof( struct V_38 ) , V_133 ) ;
if ( ! V_38 )
return - V_70 ;
V_38 -> V_103 = V_103 ;
V_38 -> V_166 = F_91 ( V_33 , 0 ) ;
if ( ! V_38 -> V_166 ) {
V_132 = - V_70 ;
goto V_178;
}
V_38 -> V_41 = F_92 ( V_65 -> V_135 , F_8 ,
F_12 , V_38 -> V_166 ) ;
if ( ! V_38 -> V_41 ) {
V_132 = - V_70 ;
goto V_178;
}
V_38 -> V_120 = F_93 ( V_65 -> V_135 , 0 ) ;
if ( ! V_38 -> V_120 ) {
V_132 = - V_70 ;
goto V_178;
}
V_38 -> V_11 = V_65 -> V_135 ;
V_38 -> V_94 = F_94 ( V_38 -> V_11 , sizeof( struct V_37 ) ,
V_133 ) ;
if ( ! V_38 -> V_94 ) {
V_132 = - V_70 ;
goto V_178;
}
F_95 ( & V_38 -> V_52 , 0 ) ;
F_16 ( & V_38 -> V_99 ) ;
F_96 ( & V_38 -> V_98 ) ;
if ( ! V_103 -> V_159 ) {
V_38 -> V_51 = ~ F_34 ( ~ 0 , V_103 -> V_179 , sizeof( V_103 -> V_179 ) ) ;
V_38 -> V_111 = 512 ;
} else {
V_38 -> V_111 = F_97 ( V_103 -> V_180 ) ;
}
for ( V_13 = 0 ; V_13 < V_38 -> V_11 ; V_13 ++ ) {
struct V_37 * log = & V_38 -> V_94 [ V_13 ] ;
struct V_140 * V_60 = V_65 -> V_7 [ V_13 ] . V_60 ;
F_98 ( & log -> V_95 ) ;
F_96 ( & log -> V_71 ) ;
F_16 ( & log -> V_72 ) ;
log -> V_38 = V_38 ;
log -> V_60 = V_60 ;
if ( V_60 ) {
struct V_181 * V_182 ;
V_132 = F_87 ( V_60 ) ;
if ( V_132 )
goto V_178;
V_182 = F_99 ( V_60 -> V_116 ) ;
if ( F_4 ( V_183 , & V_182 -> V_184 ) )
V_173 = true ;
}
}
if ( V_173 )
F_79 ( L_35 ,
F_80 ( V_103 ) ) ;
V_132 = F_78 ( V_38 ) ;
if ( V_132 ) {
goto V_178;
} else if ( ! V_103 -> V_160 &&
V_103 -> V_161 == 0 && ! V_103 -> V_185 &&
V_38 -> V_156 > 0 &&
V_38 -> V_155 == 0 ) {
V_103 -> V_161 = V_162 ;
F_40 ( V_186 , & V_103 -> V_187 ) ;
} else if ( V_103 -> V_160 && V_38 -> V_155 > 0 ) {
V_132 = - V_164 ;
goto V_178;
}
V_65 -> V_89 = V_38 ;
F_40 ( V_165 , & V_38 -> V_103 -> V_24 ) ;
return 0 ;
V_178:
F_81 ( V_38 ) ;
return V_132 ;
}
int F_100 ( struct V_64 * V_65 , struct V_140 * V_60 , bool V_188 )
{
struct V_38 * V_38 = V_65 -> V_89 ;
struct V_37 * log ;
int V_132 = 0 ;
char V_105 [ V_106 ] ;
if ( ! V_60 )
return - V_164 ;
F_3 ( L_36 ,
V_16 , V_60 -> V_153 , V_188 ? L_37 : L_38 ,
F_47 ( V_60 -> V_116 , V_105 ) ) ;
if ( V_60 -> V_153 < 0 )
return 0 ;
if ( V_60 -> V_153 >= V_38 -> V_11 )
return - V_189 ;
log = & V_38 -> V_94 [ V_60 -> V_153 ] ;
F_38 ( & log -> V_95 ) ;
if ( V_188 ) {
V_132 = F_87 ( V_60 ) ;
if ( ! V_132 ) {
log -> V_60 = V_60 ;
V_132 = F_76 ( log ) ;
}
} else {
log -> V_60 = NULL ;
}
F_39 ( & log -> V_95 ) ;
return V_132 ;
}
