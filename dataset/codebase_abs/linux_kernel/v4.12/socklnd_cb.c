struct V_1 *
F_1 ( int type , int V_2 )
{
struct V_1 * V_3 = NULL ;
if ( type == V_4 ) {
F_2 ( V_2 == V_5 ) ;
F_3 ( & V_6 . V_7 ) ;
if ( ! F_4 ( & V_6 . V_8 ) ) {
V_3 = F_5 ( V_6 . V_8 . V_9 ,
struct V_1 , V_10 ) ;
F_2 ( V_3 -> V_11 == V_2 ) ;
F_6 ( & V_3 -> V_10 ) ;
}
F_7 ( & V_6 . V_7 ) ;
}
if ( ! V_3 )
F_8 ( V_3 , V_2 ) ;
if ( ! V_3 )
return NULL ;
F_9 ( & V_3 -> V_12 , 1 ) ;
V_3 -> V_13 = 0 ;
V_3 -> V_14 = 0 ;
V_3 -> V_15 = 0 ;
V_3 -> V_11 = V_2 ;
F_10 ( & V_6 . V_16 ) ;
return V_3 ;
}
struct V_1 *
F_11 ( T_1 V_17 , int V_18 )
{
struct V_1 * V_3 ;
V_3 = F_1 ( V_4 , V_5 ) ;
if ( ! V_3 ) {
F_12 ( L_1 ) ;
return NULL ;
}
V_3 -> V_19 = NULL ;
V_3 -> V_20 = NULL ;
V_3 -> V_21 = NULL ;
V_3 -> V_22 = 0 ;
V_3 -> V_23 = V_3 -> V_24 . V_25 . V_26 ;
V_3 -> V_27 = 1 ;
V_3 -> V_28 = V_18 ;
V_3 -> V_29 . V_30 = 0 ;
V_3 -> V_29 . V_31 = V_4 ;
V_3 -> V_29 . V_32 [ 0 ] = 0 ;
V_3 -> V_29 . V_32 [ 1 ] = V_17 ;
return V_3 ;
}
void
F_13 ( struct V_1 * V_3 )
{
F_14 ( & V_6 . V_16 ) ;
if ( ! V_3 -> V_20 && V_3 -> V_11 == V_5 ) {
F_3 ( & V_6 . V_7 ) ;
F_15 ( & V_3 -> V_10 , & V_6 . V_8 ) ;
F_7 ( & V_6 . V_7 ) ;
} else {
F_16 ( V_3 , V_3 -> V_11 ) ;
}
}
static int
F_17 ( struct V_33 * V_34 , struct V_1 * V_3 )
{
struct V_35 * V_26 = V_3 -> V_23 ;
int V_36 ;
int V_37 ;
F_2 ( V_3 -> V_27 > 0 ) ;
V_37 = F_18 ( V_34 , V_3 ) ;
if ( V_37 <= 0 )
return V_37 ;
V_36 = V_37 ;
F_2 ( V_36 <= V_3 -> V_38 ) ;
V_3 -> V_38 -= V_36 ;
do {
F_2 ( V_3 -> V_27 > 0 ) ;
if ( V_36 < ( int ) V_26 -> V_39 ) {
V_26 -> V_40 = ( void * ) ( ( char * ) V_26 -> V_40 + V_36 ) ;
V_26 -> V_39 -= V_36 ;
return V_37 ;
}
V_36 -= V_26 -> V_39 ;
V_3 -> V_23 = ++ V_26 ;
V_3 -> V_27 -- ;
} while ( V_36 );
return V_37 ;
}
static int
F_19 ( struct V_33 * V_34 , struct V_1 * V_3 )
{
struct V_41 * V_42 = V_3 -> V_21 ;
int V_36 ;
int V_37 ;
F_2 ( ! V_3 -> V_27 ) ;
F_2 ( V_3 -> V_22 > 0 ) ;
V_37 = F_20 ( V_34 , V_3 ) ;
if ( V_37 <= 0 )
return V_37 ;
V_36 = V_37 ;
F_2 ( V_36 <= V_3 -> V_38 ) ;
V_3 -> V_38 -= V_36 ;
do {
F_2 ( V_3 -> V_22 > 0 ) ;
if ( V_36 < ( int ) V_42 -> V_43 ) {
V_42 -> V_44 += V_36 ;
V_42 -> V_43 -= V_36 ;
return V_37 ;
}
V_36 -= ( int ) V_42 -> V_43 ;
V_3 -> V_21 = ++ V_42 ;
V_3 -> V_22 -- ;
} while ( V_36 );
return V_37 ;
}
static int
F_21 ( struct V_33 * V_34 , struct V_1 * V_3 )
{
int V_37 ;
int V_45 ;
if ( V_6 . V_46 ) {
F_22 ( V_47 ) ;
F_23 ( F_24 ( V_6 . V_46 ) ) ;
}
F_2 ( V_3 -> V_38 ) ;
V_37 = F_25 ( V_34 ) ;
if ( V_37 ) {
F_2 ( V_34 -> V_48 ) ;
return - V_49 ;
}
do {
if ( V_6 . V_50 > 0 ) {
V_6 . V_50 -- ;
V_37 = - V_51 ;
} else if ( V_3 -> V_27 ) {
V_37 = F_17 ( V_34 , V_3 ) ;
} else {
V_37 = F_19 ( V_34 , V_3 ) ;
}
V_45 = V_34 -> V_52 -> V_53 -> V_54 ;
if ( V_37 > 0 )
V_34 -> V_55 += V_37 ;
if ( V_45 < V_34 -> V_55 ) {
V_34 -> V_56 =
F_26 ( * V_57 . V_58 ) ;
V_34 -> V_59 -> V_60 = F_27 () ;
V_34 -> V_55 = V_45 ;
F_28 () ;
}
if ( V_37 <= 0 ) {
if ( ! V_37 )
V_37 = - V_51 ;
if ( V_37 == - V_51 && F_29 ( V_34 ) )
V_37 = - V_61 ;
break;
}
F_30 ( V_37 , & V_34 -> V_62 ) ;
V_37 = 0 ;
} while ( V_3 -> V_38 );
F_31 ( V_34 ) ;
return V_37 ;
}
static int
F_32 ( struct V_33 * V_34 )
{
struct V_35 * V_26 = V_34 -> V_63 ;
int V_36 ;
int V_37 ;
F_2 ( V_34 -> V_64 > 0 ) ;
V_37 = F_33 ( V_34 ) ;
if ( V_37 <= 0 )
return V_37 ;
V_36 = V_37 ;
V_34 -> V_59 -> V_60 = F_27 () ;
V_34 -> V_65 =
F_26 ( * V_57 . V_58 ) ;
F_28 () ;
V_34 -> V_66 = 1 ;
V_34 -> V_67 -= V_36 ;
V_34 -> V_68 -= V_36 ;
do {
F_2 ( V_34 -> V_64 > 0 ) ;
if ( V_36 < ( int ) V_26 -> V_39 ) {
V_26 -> V_39 -= V_36 ;
V_26 -> V_40 += V_36 ;
return - V_51 ;
}
V_36 -= V_26 -> V_39 ;
V_34 -> V_63 = ++ V_26 ;
V_34 -> V_64 -- ;
} while ( V_36 );
return V_37 ;
}
static int
F_34 ( struct V_33 * V_34 )
{
struct V_41 * V_42 = V_34 -> V_69 ;
int V_36 ;
int V_37 ;
F_2 ( V_34 -> V_70 > 0 ) ;
V_37 = F_35 ( V_34 ) ;
if ( V_37 <= 0 )
return V_37 ;
V_36 = V_37 ;
V_34 -> V_59 -> V_60 = F_27 () ;
V_34 -> V_65 =
F_26 ( * V_57 . V_58 ) ;
F_28 () ;
V_34 -> V_66 = 1 ;
V_34 -> V_67 -= V_36 ;
V_34 -> V_68 -= V_36 ;
do {
F_2 ( V_34 -> V_70 > 0 ) ;
if ( V_36 < ( int ) V_42 -> V_43 ) {
V_42 -> V_44 += V_36 ;
V_42 -> V_43 -= V_36 ;
return - V_51 ;
}
V_36 -= V_42 -> V_43 ;
V_34 -> V_69 = ++ V_42 ;
V_34 -> V_70 -- ;
} while ( V_36 );
return 1 ;
}
static int
F_36 ( struct V_33 * V_34 )
{
int V_37 ;
if ( V_6 . V_71 ) {
F_22 ( V_47 ) ;
F_23 ( F_24 ( V_6 . V_71 ) ) ;
}
V_37 = F_25 ( V_34 ) ;
if ( V_37 ) {
F_2 ( V_34 -> V_48 ) ;
return - V_49 ;
}
for (; ; ) {
if ( V_34 -> V_64 )
V_37 = F_32 ( V_34 ) ;
else
V_37 = F_34 ( V_34 ) ;
if ( V_37 <= 0 ) {
if ( V_37 == - V_51 ) {
V_37 = 1 ;
} else if ( ! V_37 && V_34 -> V_66 ) {
V_37 = - V_72 ;
}
break;
}
if ( ! V_34 -> V_67 ) {
V_37 = 1 ;
break;
}
}
F_31 ( V_34 ) ;
return V_37 ;
}
void
F_37 ( struct V_73 * V_74 , struct V_1 * V_3 )
{
struct V_75 * V_76 = V_3 -> V_20 ;
int V_37 = ( ! V_3 -> V_38 && ! V_3 -> V_13 ) ? 0 : - V_77 ;
F_2 ( V_74 || V_3 -> V_19 ) ;
if ( V_3 -> V_19 )
F_38 ( V_3 -> V_19 ) ;
if ( ! V_74 && V_3 -> V_19 )
V_74 = V_3 -> V_19 -> V_59 -> V_78 ;
F_13 ( V_3 ) ;
if ( V_76 )
F_39 ( V_74 , V_76 , V_37 ) ;
}
void
F_40 ( struct V_73 * V_74 , struct V_79 * V_80 , int error )
{
struct V_1 * V_3 ;
while ( ! F_4 ( V_80 ) ) {
V_3 = F_5 ( V_80 -> V_9 , struct V_1 , V_10 ) ;
if ( error && V_3 -> V_20 ) {
F_41 ( L_2 ,
F_42 ( V_3 -> V_20 -> V_81 . type ) ,
F_42 ( V_3 -> V_20 -> V_81 . V_82 ) ,
F_43 ( F_44 ( V_3 -> V_20 -> V_81 . V_83 ) ) ,
F_43 ( F_44 ( V_3 -> V_20 -> V_81 . V_84 ) ) ) ;
} else if ( error ) {
F_41 ( L_3 ) ;
}
F_6 ( & V_3 -> V_10 ) ;
F_2 ( F_45 ( & V_3 -> V_12 ) == 1 ) ;
F_37 ( V_74 , V_3 ) ;
}
}
static void
F_46 ( struct V_1 * V_3 )
{
struct V_33 * V_34 = V_3 -> V_19 ;
struct V_85 * V_86 = V_34 -> V_59 ;
F_2 ( V_3 -> V_29 . V_31 != V_4 ) ;
F_2 ( V_3 -> V_14 ) ;
V_3 -> V_15 = 1 ;
if ( V_34 -> V_87 == & V_88 ||
! V_34 -> V_89 )
return;
F_47 ( V_3 ) ;
F_3 ( & V_86 -> V_90 ) ;
V_3 -> V_91 =
F_26 ( * V_57 . V_58 ) ;
F_2 ( ! V_3 -> V_29 . V_32 [ 0 ] ) ;
V_3 -> V_29 . V_32 [ 0 ] = V_86 -> V_92 ++ ;
if ( ! V_86 -> V_92 )
V_86 -> V_92 = V_93 + 1 ;
F_48 ( & V_3 -> V_94 , & V_86 -> V_95 ) ;
F_7 ( & V_86 -> V_90 ) ;
}
static void
F_49 ( struct V_1 * V_3 )
{
struct V_85 * V_86 = V_3 -> V_19 -> V_59 ;
F_2 ( V_3 -> V_29 . V_31 != V_4 ) ;
F_2 ( V_3 -> V_14 ) ;
V_3 -> V_15 = 0 ;
F_3 ( & V_86 -> V_90 ) ;
if ( ! V_3 -> V_29 . V_32 [ 0 ] ) {
F_7 ( & V_86 -> V_90 ) ;
return;
}
V_3 -> V_29 . V_32 [ 0 ] = 0 ;
F_6 ( & V_3 -> V_94 ) ;
F_7 ( & V_86 -> V_90 ) ;
F_50 ( V_3 ) ;
}
static int
F_51 ( struct V_33 * V_34 , struct V_1 * V_3 )
{
int V_37 ;
if ( V_3 -> V_14 && ! V_3 -> V_15 )
F_46 ( V_3 ) ;
V_37 = F_21 ( V_34 , V_3 ) ;
F_52 ( V_96 , L_4 , V_3 -> V_38 , V_37 ) ;
if ( ! V_3 -> V_38 ) {
F_2 ( ! V_37 ) ;
return 0 ;
}
if ( V_37 == - V_51 )
return V_37 ;
if ( V_37 == - V_61 ) {
static int V_97 ;
V_97 ++ ;
if ( ( V_97 & ( - V_97 ) ) == V_97 )
F_53 ( L_5 , V_97 , V_34 ) ;
F_54 ( & V_6 . V_98 ) ;
F_2 ( V_34 -> V_99 ) ;
F_48 ( & V_34 -> V_100 ,
& V_6 . V_101 ) ;
if ( ! F_55 ( F_56 ( F_27 () ,
V_102 ) ,
V_6 . V_103 ) )
F_57 ( & V_6 . V_104 ) ;
F_58 ( & V_6 . V_98 ) ;
return V_37 ;
}
F_2 ( V_37 < 0 ) ;
if ( ! V_34 -> V_48 ) {
switch ( V_37 ) {
case - V_105 :
F_59 ( L_6 ,
& V_34 -> V_106 ) ;
break;
default:
F_59 ( L_7 ,
& V_34 -> V_106 , V_37 ) ;
break;
}
F_52 ( V_96 , L_8 ,
V_34 , V_37 ,
F_60 ( V_34 -> V_59 -> V_107 ) ,
& V_34 -> V_106 ,
V_34 -> V_108 ) ;
}
if ( V_3 -> V_15 )
F_49 ( V_3 ) ;
F_61 ( V_34 , ( V_34 -> V_48 ) ? 0 : V_37 ) ;
return V_37 ;
}
static void
F_62 ( struct V_109 * V_110 )
{
F_2 ( ! V_110 -> V_111 ) ;
F_2 ( ! V_110 -> V_112 ) ;
F_2 ( F_63 () & ~ V_110 -> V_113 ) ;
V_110 -> V_111 = 1 ;
F_64 ( V_110 ) ;
F_54 ( & V_6 . V_114 ) ;
F_48 ( & V_110 -> V_115 ,
& V_6 . V_116 ) ;
F_57 ( & V_6 . V_117 ) ;
F_58 ( & V_6 . V_114 ) ;
}
void
F_65 ( struct V_85 * V_86 )
{
struct V_109 * V_110 ;
for (; ; ) {
V_110 = F_66 ( V_86 ) ;
if ( ! V_110 )
return;
F_62 ( V_110 ) ;
}
}
struct V_33 *
F_67 ( struct V_85 * V_86 , struct V_1 * V_3 ,
int V_18 )
{
struct V_79 * V_118 ;
struct V_33 * V_34 ;
struct V_33 * V_119 = NULL ;
struct V_33 * V_120 = NULL ;
int V_121 = 0 ;
int V_122 = 0 ;
F_68 (tmp, &peer->ksnp_conns) {
struct V_33 * V_123 ;
int V_36 , V_37 ;
V_123 = F_5 ( V_118 , struct V_33 , V_124 ) ;
V_36 = F_45 ( & V_123 -> V_62 ) +
V_123 -> V_52 -> V_53 -> V_54 ;
F_2 ( ! V_123 -> V_48 ) ;
F_2 ( V_123 -> V_87 &&
V_123 -> V_87 -> V_125 ) ;
V_37 = V_123 -> V_87 -> V_125 ( V_123 , V_3 , V_18 ) ;
switch ( V_37 ) {
default:
F_69 () ;
case V_126 :
continue;
case V_127 :
if ( ! V_119 || V_121 > V_36 ||
( V_121 == V_36 && * V_57 . V_128 &&
F_70 ( V_119 -> V_129 , V_123 -> V_129 ) ) ) {
V_119 = V_123 ;
V_121 = V_36 ;
}
break;
case V_130 :
if ( ! V_120 || V_122 > V_36 ||
( V_122 == V_36 && * V_57 . V_128 &&
F_70 ( V_120 -> V_129 , V_123 -> V_129 ) ) ) {
V_120 = V_123 ;
V_122 = V_36 ;
}
break;
}
}
V_34 = ( V_119 ) ? V_119 : V_120 ;
if ( V_34 )
V_34 -> V_129 = F_27 () ;
return V_34 ;
}
void
F_71 ( struct V_33 * V_34 , struct V_1 * V_3 )
{
V_34 -> V_87 -> V_131 ( V_3 ) ;
F_72 ( V_3 -> V_132 , & V_34 -> V_62 ) ;
F_73 ( V_34 ) ;
V_3 -> V_19 = V_34 ;
}
void
F_74 ( struct V_1 * V_3 , struct V_33 * V_34 )
{
struct V_133 * V_134 = V_34 -> V_135 ;
struct V_136 * V_137 = & V_3 -> V_29 ;
struct V_1 * V_138 = NULL ;
int V_45 = 0 ;
F_2 ( ! V_34 -> V_48 ) ;
F_52 ( V_96 , L_9 ,
F_60 ( V_34 -> V_59 -> V_107 ) ,
& V_34 -> V_106 , V_34 -> V_108 ) ;
F_71 ( V_34 , V_3 ) ;
F_2 ( F_75 ( V_3 -> V_27 , V_3 -> V_23 ) +
F_76 ( V_3 -> V_22 , V_3 -> V_21 ) ==
( unsigned int ) V_3 -> V_132 ) ;
F_2 ( V_3 -> V_27 >= 1 ) ;
F_2 ( V_3 -> V_38 == V_3 -> V_132 ) ;
F_52 ( V_96 , L_10 ,
V_3 , ( V_3 -> V_20 ) ? V_3 -> V_20 -> V_81 . type :
V_4 ,
V_3 -> V_132 , V_3 -> V_27 , V_3 -> V_22 ) ;
V_45 = V_34 -> V_52 -> V_53 -> V_54 ;
F_54 ( & V_134 -> V_139 ) ;
if ( F_4 ( & V_34 -> V_140 ) && ! V_45 ) {
V_34 -> V_56 =
F_26 ( * V_57 . V_58 ) ;
if ( V_34 -> V_55 > 0 )
V_34 -> V_59 -> V_60 = F_27 () ;
V_34 -> V_55 = 0 ;
F_28 () ;
}
if ( V_137 -> V_31 == V_4 ) {
F_2 ( V_137 -> V_32 [ 1 ] ) ;
F_2 ( V_34 -> V_87 -> V_141 ) ;
if ( V_34 -> V_87 -> V_141 ( V_34 , V_3 , 0 ) )
V_138 = V_3 ;
} else {
F_2 ( ! V_137 -> V_32 [ 1 ] ) ;
F_2 ( V_34 -> V_87 -> V_142 ) ;
V_138 = V_34 -> V_87 -> V_142 ( V_34 , V_3 ) ;
}
if ( V_138 ) {
F_30 ( V_138 -> V_132 , & V_34 -> V_62 ) ;
F_48 ( & V_138 -> V_10 , & V_134 -> V_143 ) ;
}
if ( V_34 -> V_144 &&
! V_34 -> V_99 ) {
F_73 ( V_34 ) ;
F_48 ( & V_34 -> V_100 , & V_134 -> V_145 ) ;
V_34 -> V_99 = 1 ;
F_57 ( & V_134 -> V_146 ) ;
}
F_58 ( & V_134 -> V_139 ) ;
}
struct V_109 *
F_66 ( struct V_85 * V_86 )
{
unsigned long V_147 = F_27 () ;
struct V_79 * V_118 ;
struct V_109 * V_110 ;
F_68 (tmp, &peer->ksnp_routes) {
V_110 = F_5 ( V_118 , struct V_109 , V_148 ) ;
F_2 ( ! V_110 -> V_112 || V_110 -> V_111 ) ;
if ( V_110 -> V_111 )
continue;
if ( ! ( F_63 () & ~ V_110 -> V_113 ) )
continue;
if ( ! ( ! V_110 -> V_149 ||
F_55 ( V_147 , V_110 -> V_150 ) ) ) {
F_52 ( V_96 ,
L_11 ,
& V_110 -> V_151 ,
V_110 -> V_113 ,
V_110 -> V_149 ,
F_77 ( V_110 -> V_150 - V_147 ) ) ;
continue;
}
return V_110 ;
}
return NULL ;
}
struct V_109 *
F_78 ( struct V_85 * V_86 )
{
struct V_79 * V_118 ;
struct V_109 * V_110 ;
F_68 (tmp, &peer->ksnp_routes) {
V_110 = F_5 ( V_118 , struct V_109 , V_148 ) ;
F_2 ( ! V_110 -> V_112 || V_110 -> V_111 ) ;
if ( V_110 -> V_111 )
return V_110 ;
}
return NULL ;
}
int
F_79 ( struct V_73 * V_74 , struct V_1 * V_3 ,
struct V_152 V_153 )
{
struct V_85 * V_86 ;
struct V_33 * V_34 ;
T_2 * V_154 ;
int V_155 ;
int V_37 ;
F_2 ( ! V_3 -> V_19 ) ;
V_154 = & V_6 . V_156 ;
for ( V_155 = 0 ; ; V_155 = 1 ) {
F_80 ( V_154 ) ;
V_86 = F_81 ( V_74 , V_153 ) ;
if ( V_86 ) {
if ( ! F_66 ( V_86 ) ) {
V_34 = F_67 ( V_86 , V_3 , V_3 -> V_28 ) ;
if ( V_34 ) {
F_74 ( V_3 , V_34 ) ;
F_82 ( V_154 ) ;
return 0 ;
}
}
}
F_82 ( V_154 ) ;
F_83 ( V_154 ) ;
V_86 = F_81 ( V_74 , V_153 ) ;
if ( V_86 )
break;
F_84 ( V_154 ) ;
if ( V_153 . V_157 & V_158 ) {
F_12 ( L_12 ,
F_60 ( V_153 ) ) ;
return - V_159 ;
}
if ( V_155 ) {
F_12 ( L_13 , F_60 ( V_153 ) ) ;
return - V_159 ;
}
V_37 = F_85 ( V_74 , V_153 ,
F_86 ( V_153 . V_160 ) ,
F_87 () ) ;
if ( V_37 ) {
F_12 ( L_14 ,
F_60 ( V_153 ) , V_37 ) ;
return V_37 ;
}
}
F_65 ( V_86 ) ;
V_34 = F_67 ( V_86 , V_3 , V_3 -> V_28 ) ;
if ( V_34 ) {
F_74 ( V_3 , V_34 ) ;
F_84 ( V_154 ) ;
return 0 ;
}
if ( V_86 -> V_161 > 0 ||
F_78 ( V_86 ) ) {
V_3 -> V_91 =
F_26 ( * V_57 . V_58 ) ;
F_48 ( & V_3 -> V_10 , & V_86 -> V_162 ) ;
F_84 ( V_154 ) ;
return 0 ;
}
F_84 ( V_154 ) ;
F_41 ( L_15 , F_60 ( V_153 ) ) ;
return - V_159 ;
}
int
F_88 ( struct V_73 * V_74 , void * V_163 , struct V_75 * V_164 )
{
int V_165 = 1 ;
int type = V_164 -> V_166 ;
struct V_152 V_167 = V_164 -> V_168 ;
unsigned int V_169 = V_164 -> V_170 ;
struct V_35 * V_171 = V_164 -> V_172 ;
struct V_41 * V_173 = V_164 -> V_174 ;
unsigned int V_175 = V_164 -> V_176 ;
unsigned int V_177 = V_164 -> V_178 ;
struct V_1 * V_3 ;
int V_179 ;
int V_37 ;
F_52 ( V_96 , L_16 ,
V_177 , V_169 , F_60 ( V_167 ) ) ;
F_2 ( ! V_177 || V_169 > 0 ) ;
F_2 ( V_169 <= V_180 ) ;
F_2 ( ! ( V_173 && V_171 ) ) ;
F_2 ( ! F_89 () ) ;
if ( V_171 )
V_179 = F_90 ( struct V_1 ,
V_24 . V_25 . V_26 [ 1 + V_169 ] ) ;
else
V_179 = F_90 ( struct V_1 ,
V_24 . V_181 . V_42 [ V_169 ] ) ;
if ( V_164 -> V_182 )
V_165 = F_91 () ;
V_3 = F_1 ( V_183 , V_179 ) ;
if ( ! V_3 ) {
F_12 ( L_17 ,
type , V_179 ) ;
if ( V_164 -> V_182 )
F_92 ( V_165 ) ;
return - V_61 ;
}
V_3 -> V_19 = NULL ;
V_3 -> V_20 = V_164 ;
if ( V_171 ) {
V_3 -> V_21 = NULL ;
V_3 -> V_22 = 0 ;
V_3 -> V_23 = V_3 -> V_24 . V_25 . V_26 ;
V_3 -> V_27 = 1 +
F_93 ( V_169 , & V_3 -> V_23 [ 1 ] ,
V_169 , V_171 ,
V_175 , V_177 ) ;
} else {
V_3 -> V_27 = 1 ;
V_3 -> V_23 = & V_3 -> V_24 . V_181 . V_26 ;
V_3 -> V_21 = V_3 -> V_24 . V_181 . V_42 ;
V_3 -> V_22 = F_94 ( V_169 , V_3 -> V_21 ,
V_169 , V_173 ,
V_175 , V_177 ) ;
if ( V_177 >= * V_57 . V_184 )
V_3 -> V_14 = 1 ;
}
V_3 -> V_29 . V_30 = 0 ;
V_3 -> V_29 . V_31 = V_183 ;
V_3 -> V_29 . V_32 [ 0 ] = 0 ;
V_3 -> V_29 . V_32 [ 1 ] = 0 ;
V_37 = F_79 ( V_74 , V_3 , V_167 ) ;
if ( ! V_165 )
F_92 ( V_165 ) ;
if ( ! V_37 )
return 0 ;
F_13 ( V_3 ) ;
return - V_77 ;
}
int
F_95 ( int (* F_96)( void * V_185 ) , void * V_185 , char * V_186 )
{
struct V_187 * V_188 = F_97 ( F_96 , V_185 , L_18 , V_186 ) ;
if ( F_98 ( V_188 ) )
return F_99 ( V_188 ) ;
F_83 ( & V_6 . V_156 ) ;
V_6 . V_189 ++ ;
F_84 ( & V_6 . V_156 ) ;
return 0 ;
}
void
F_100 ( void )
{
F_83 ( & V_6 . V_156 ) ;
V_6 . V_189 -- ;
F_84 ( & V_6 . V_156 ) ;
}
int
F_101 ( struct V_33 * V_34 , int V_190 )
{
static char V_191 [ 4096 ] ;
int V_36 ;
unsigned int V_192 ;
int V_193 ;
F_2 ( V_34 -> V_87 ) ;
if ( * V_57 . V_194 & V_34 -> V_195 ) {
F_102 ( V_34 ) ;
}
if ( ! V_190 ) {
V_34 -> V_66 = 0 ;
F_28 () ;
switch ( V_34 -> V_87 -> V_196 ) {
case V_197 :
case V_198 :
V_34 -> V_199 = V_200 ;
V_34 -> V_63 = (struct V_35 * ) & V_34 -> V_201 ;
V_34 -> V_63 [ 0 ] . V_40 = & V_34 -> V_202 ;
V_34 -> V_67 = F_90 ( struct V_136 , V_203 ) ;
V_34 -> V_68 = F_90 ( struct V_136 , V_203 ) ;
V_34 -> V_63 [ 0 ] . V_39 = F_90 ( struct V_136 , V_203 ) ;
break;
case V_204 :
V_34 -> V_199 = V_205 ;
V_34 -> V_67 = sizeof( struct V_206 ) ;
V_34 -> V_68 = sizeof( struct V_206 ) ;
V_34 -> V_63 = (struct V_35 * ) & V_34 -> V_201 ;
V_34 -> V_63 [ 0 ] . V_40 = & V_34 -> V_202 . V_203 . V_76 ;
V_34 -> V_63 [ 0 ] . V_39 = sizeof( struct V_206 ) ;
break;
default:
F_69 () ;
}
V_34 -> V_64 = 1 ;
V_34 -> V_69 = NULL ;
V_34 -> V_70 = 0 ;
V_34 -> V_207 = ~ 0 ;
return 1 ;
}
V_34 -> V_199 = V_208 ;
V_34 -> V_68 = V_190 ;
V_34 -> V_63 = (struct V_35 * ) & V_34 -> V_201 ;
V_193 = 0 ;
V_192 = 0 ;
do {
V_36 = F_103 ( int , V_190 , sizeof( V_191 ) ) ;
V_34 -> V_63 [ V_192 ] . V_40 = V_191 ;
V_34 -> V_63 [ V_192 ] . V_39 = V_36 ;
V_192 ++ ;
V_193 += V_36 ;
V_190 -= V_36 ;
} while ( V_190 &&
V_192 < sizeof( V_34 -> V_201 ) / sizeof( struct V_209 ) );
V_34 -> V_64 = V_192 ;
V_34 -> V_69 = NULL ;
V_34 -> V_70 = 0 ;
V_34 -> V_67 = V_193 ;
return 0 ;
}
static int
F_104 ( struct V_33 * V_34 )
{
struct V_206 * V_210 ;
struct V_152 * V_153 ;
int V_37 ;
F_2 ( F_45 ( & V_34 -> V_211 ) > 0 ) ;
F_2 ( V_34 -> V_199 == V_200 ||
V_34 -> V_199 == V_212 ||
V_34 -> V_199 == V_205 ||
V_34 -> V_199 == V_208 ) ;
V_213:
if ( V_34 -> V_67 ) {
V_37 = F_36 ( V_34 ) ;
if ( V_37 <= 0 ) {
F_2 ( V_37 != - V_51 ) ;
if ( ! V_37 )
F_52 ( V_96 , L_19 ,
V_34 ,
F_60 ( V_34 -> V_59 -> V_107 ) ,
& V_34 -> V_106 ,
V_34 -> V_108 ) ;
else if ( ! V_34 -> V_48 )
F_12 ( L_20 ,
V_34 , V_37 ,
F_60 ( V_34 -> V_59 -> V_107 ) ,
& V_34 -> V_106 ,
V_34 -> V_108 ) ;
F_61 ( V_34 ,
( V_34 -> V_48 ) ? 0 : V_37 ) ;
return ( ! V_37 ? - V_49 : V_37 ) ;
}
if ( V_34 -> V_67 ) {
return - V_51 ;
}
}
switch ( V_34 -> V_199 ) {
case V_200 :
if ( V_34 -> V_214 ) {
F_105 ( & V_34 -> V_202 . V_31 ) ;
F_105 ( & V_34 -> V_202 . V_30 ) ;
F_106 ( & V_34 -> V_202 . V_32 [ 0 ] ) ;
F_106 ( & V_34 -> V_202 . V_32 [ 1 ] ) ;
}
if ( V_34 -> V_202 . V_31 != V_4 &&
V_34 -> V_202 . V_31 != V_183 ) {
F_12 ( L_21 ,
F_60 ( V_34 -> V_59 -> V_107 ) ,
V_34 -> V_202 . V_31 ) ;
F_101 ( V_34 , 0 ) ;
F_61 ( V_34 , - V_72 ) ;
return - V_72 ;
}
if ( V_34 -> V_202 . V_31 == V_4 &&
V_34 -> V_202 . V_30 &&
V_34 -> V_202 . V_30 != V_34 -> V_207 ) {
F_12 ( L_22 ,
F_60 ( V_34 -> V_59 -> V_107 ) ,
V_34 -> V_202 . V_30 , V_34 -> V_207 ) ;
F_101 ( V_34 , 0 ) ;
F_61 ( V_34 , - V_72 ) ;
return - V_77 ;
}
if ( V_34 -> V_202 . V_32 [ 1 ] ) {
T_1 V_17 = 0 ;
F_2 ( V_34 -> V_87 != & V_88 ) ;
if ( V_34 -> V_202 . V_31 == V_4 )
V_17 = V_34 -> V_202 . V_32 [ 0 ] ;
V_37 = V_34 -> V_87 -> V_215 ( V_34 , V_17 ,
V_34 -> V_202 . V_32 [ 1 ] ) ;
if ( V_37 ) {
F_12 ( L_23 ,
F_60 ( V_34 -> V_59 -> V_107 ) ,
V_17 , V_34 -> V_202 . V_32 [ 1 ] ) ;
F_101 ( V_34 , 0 ) ;
F_61 ( V_34 , - V_72 ) ;
return V_37 ;
}
}
if ( V_34 -> V_202 . V_31 == V_4 ) {
F_101 ( V_34 , 0 ) ;
return 0 ;
}
V_34 -> V_199 = V_205 ;
V_34 -> V_67 = sizeof( struct V_216 ) ;
V_34 -> V_68 = sizeof( struct V_216 ) ;
V_34 -> V_63 = (struct V_35 * ) & V_34 -> V_201 ;
V_34 -> V_63 [ 0 ] . V_40 = & V_34 -> V_202 . V_203 . V_76 ;
V_34 -> V_63 [ 0 ] . V_39 = sizeof( struct V_216 ) ;
V_34 -> V_64 = 1 ;
V_34 -> V_69 = NULL ;
V_34 -> V_70 = 0 ;
goto V_213;
case V_205 :
V_34 -> V_87 -> V_217 ( & V_34 -> V_202 ) ;
if ( V_34 -> V_59 -> V_107 . V_157 & V_158 ) {
V_210 = & V_34 -> V_202 . V_203 . V_76 . V_218 ;
V_153 = & V_34 -> V_59 -> V_107 ;
V_210 -> V_219 = F_107 ( V_153 -> V_157 ) ;
V_210 -> V_83 = F_108 ( V_153 -> V_160 ) ;
}
V_34 -> V_199 = V_220 ;
F_73 ( V_34 ) ;
V_37 = F_109 ( V_34 -> V_59 -> V_78 ,
& V_34 -> V_202 . V_203 . V_76 . V_218 ,
V_34 -> V_59 -> V_107 . V_160 , V_34 , 0 ) ;
if ( V_37 < 0 ) {
F_101 ( V_34 , 0 ) ;
F_61 ( V_34 , V_37 ) ;
F_38 ( V_34 ) ;
return - V_72 ;
}
F_2 ( V_34 -> V_199 == V_220 ||
V_34 -> V_199 == V_212 ) ;
if ( V_34 -> V_199 != V_212 )
return 0 ;
goto V_213;
case V_212 :
V_37 = 0 ;
if ( ! V_34 -> V_68 &&
V_34 -> V_202 . V_30 &&
V_34 -> V_202 . V_30 != V_34 -> V_207 ) {
F_12 ( L_22 ,
F_60 ( V_34 -> V_59 -> V_107 ) ,
V_34 -> V_202 . V_30 , V_34 -> V_207 ) ;
V_37 = - V_77 ;
}
if ( ! V_37 && V_34 -> V_202 . V_32 [ 0 ] ) {
F_2 ( V_34 -> V_87 != & V_88 ) ;
V_210 = & V_34 -> V_202 . V_203 . V_76 . V_218 ;
V_153 = & V_34 -> V_59 -> V_107 ;
V_37 = V_34 -> V_87 -> V_221 ( V_34 ,
V_34 -> V_202 . V_32 [ 0 ] ,
* V_57 . V_222 ||
F_44 ( V_210 -> V_83 ) != V_153 -> V_160 ) ;
}
F_39 ( V_34 -> V_59 -> V_78 , V_34 -> V_223 , V_37 ) ;
if ( V_37 ) {
F_101 ( V_34 , 0 ) ;
F_61 ( V_34 , V_37 ) ;
return - V_72 ;
}
case V_208 :
if ( F_101 ( V_34 , V_34 -> V_68 ) )
return 0 ;
goto V_213;
default:
break;
}
F_69 () ;
return - V_224 ;
}
int
F_110 ( struct V_73 * V_74 , void * V_163 , struct V_75 * V_137 ,
int V_225 , struct V_226 * V_227 , unsigned int V_228 )
{
struct V_33 * V_34 = V_163 ;
struct V_133 * V_134 = V_34 -> V_135 ;
F_2 ( F_111 ( V_227 ) <= V_228 ) ;
F_2 ( V_227 -> V_229 <= V_180 ) ;
V_34 -> V_223 = V_137 ;
V_34 -> V_67 = F_111 ( V_227 ) ;
V_34 -> V_68 = V_228 ;
if ( V_227 -> type & V_230 ) {
V_34 -> V_70 = 0 ;
V_34 -> V_69 = NULL ;
V_34 -> V_63 = V_34 -> V_201 . V_26 ;
V_34 -> V_64 =
F_93 ( V_180 , V_34 -> V_63 ,
V_227 -> V_229 , V_227 -> V_35 ,
V_227 -> V_231 , F_111 ( V_227 ) ) ;
} else {
V_34 -> V_64 = 0 ;
V_34 -> V_63 = NULL ;
V_34 -> V_69 = V_34 -> V_201 . V_42 ;
V_34 -> V_70 =
F_94 ( V_180 , V_34 -> V_69 ,
V_227 -> V_229 , V_227 -> V_232 ,
V_227 -> V_231 , F_111 ( V_227 ) ) ;
}
F_2 ( V_34 -> V_233 ) ;
F_54 ( & V_134 -> V_139 ) ;
switch ( V_34 -> V_199 ) {
case V_234 :
F_48 ( & V_34 -> V_235 , & V_134 -> V_236 ) ;
F_57 ( & V_134 -> V_146 ) ;
F_2 ( V_34 -> V_237 ) ;
break;
case V_220 :
break;
}
V_34 -> V_199 = V_212 ;
F_58 ( & V_134 -> V_139 ) ;
F_38 ( V_34 ) ;
return 0 ;
}
static inline int
F_112 ( struct V_133 * V_134 )
{
int V_37 ;
F_54 ( & V_134 -> V_139 ) ;
V_37 = ! V_6 . V_238 &&
F_4 ( & V_134 -> V_236 ) &&
F_4 ( & V_134 -> V_145 ) ;
F_58 ( & V_134 -> V_139 ) ;
return V_37 ;
}
int F_113 ( void * V_185 )
{
struct V_239 * V_240 ;
struct V_133 * V_134 ;
struct V_33 * V_34 ;
struct V_1 * V_3 ;
int V_37 ;
int V_241 = 0 ;
long V_153 = ( long ) V_185 ;
V_240 = V_6 . V_242 [ F_114 ( V_153 ) ] ;
V_134 = & V_240 -> V_243 [ F_115 ( V_153 ) ] ;
F_116 () ;
V_37 = F_117 ( F_118 () , V_240 -> V_244 ) ;
if ( V_37 ) {
F_53 ( L_24 ,
V_240 -> V_244 , V_37 ) ;
}
F_54 ( & V_134 -> V_139 ) ;
while ( ! V_6 . V_238 ) {
int V_245 = 0 ;
if ( ! F_4 ( & V_134 -> V_236 ) ) {
V_34 = F_5 ( V_134 -> V_236 . V_9 ,
struct V_33 , V_235 ) ;
F_6 ( & V_34 -> V_235 ) ;
F_2 ( V_34 -> V_233 ) ;
F_2 ( V_34 -> V_237 ) ;
V_34 -> V_237 = 0 ;
F_58 ( & V_134 -> V_139 ) ;
V_37 = F_104 ( V_34 ) ;
F_54 ( & V_134 -> V_139 ) ;
F_2 ( V_34 -> V_233 ) ;
if ( ! V_37 )
V_34 -> V_237 = 1 ;
if ( V_34 -> V_199 == V_220 ) {
V_34 -> V_199 = V_234 ;
} else if ( V_34 -> V_237 ) {
F_48 ( & V_34 -> V_235 ,
& V_134 -> V_236 ) ;
} else {
V_34 -> V_233 = 0 ;
F_38 ( V_34 ) ;
}
V_245 = 1 ;
}
if ( ! F_4 ( & V_134 -> V_145 ) ) {
F_119 ( V_246 ) ;
if ( ! F_4 ( & V_134 -> V_143 ) ) {
F_15 ( & V_246 , & V_134 -> V_143 ) ;
F_120 ( & V_134 -> V_143 ) ;
}
V_34 = F_5 ( V_134 -> V_145 . V_9 ,
struct V_33 , V_100 ) ;
F_6 ( & V_34 -> V_100 ) ;
F_2 ( V_34 -> V_99 ) ;
F_2 ( V_34 -> V_144 ) ;
F_2 ( ! F_4 ( & V_34 -> V_140 ) ) ;
V_3 = F_5 ( V_34 -> V_140 . V_9 ,
struct V_1 , V_10 ) ;
if ( V_34 -> V_247 == V_3 )
F_121 ( V_34 ) ;
F_6 ( & V_3 -> V_10 ) ;
V_34 -> V_144 = 0 ;
F_58 ( & V_134 -> V_139 ) ;
if ( ! F_4 ( & V_246 ) ) {
F_40 ( NULL , & V_246 , 0 ) ;
}
V_37 = F_51 ( V_34 , V_3 ) ;
if ( V_37 == - V_61 || V_37 == - V_51 ) {
F_54 ( & V_134 -> V_139 ) ;
F_15 ( & V_3 -> V_10 , & V_34 -> V_140 ) ;
} else {
F_50 ( V_3 ) ;
F_54 ( & V_134 -> V_139 ) ;
V_34 -> V_144 = 1 ;
}
if ( V_37 == - V_61 ) {
} else if ( V_34 -> V_144 &&
! F_4 ( & V_34 -> V_140 ) ) {
F_48 ( & V_34 -> V_100 ,
& V_134 -> V_145 ) ;
} else {
V_34 -> V_99 = 0 ;
F_38 ( V_34 ) ;
}
V_245 = 1 ;
}
if ( ! V_245 ||
++ V_241 == V_248 ) {
F_58 ( & V_134 -> V_139 ) ;
V_241 = 0 ;
if ( ! V_245 ) {
V_37 = F_122 (
V_134 -> V_146 ,
! F_112 ( V_134 ) ) ;
F_2 ( ! V_37 ) ;
} else {
F_123 () ;
}
F_54 ( & V_134 -> V_139 ) ;
}
}
F_58 ( & V_134 -> V_139 ) ;
F_100 () ;
return 0 ;
}
void F_124 ( struct V_33 * V_34 )
{
struct V_133 * V_134 ;
V_134 = V_34 -> V_135 ;
F_54 ( & V_134 -> V_139 ) ;
V_34 -> V_237 = 1 ;
if ( ! V_34 -> V_233 ) {
F_48 ( & V_34 -> V_235 , & V_134 -> V_236 ) ;
V_34 -> V_233 = 1 ;
F_73 ( V_34 ) ;
F_57 ( & V_134 -> V_146 ) ;
}
F_58 ( & V_134 -> V_139 ) ;
}
void F_125 ( struct V_33 * V_34 )
{
struct V_133 * V_134 ;
V_134 = V_34 -> V_135 ;
F_54 ( & V_134 -> V_139 ) ;
V_34 -> V_144 = 1 ;
if ( ! V_34 -> V_99 &&
! F_4 ( & V_34 -> V_140 ) ) {
F_48 ( & V_34 -> V_100 , & V_134 -> V_145 ) ;
V_34 -> V_99 = 1 ;
F_73 ( V_34 ) ;
F_57 ( & V_134 -> V_146 ) ;
}
F_58 ( & V_134 -> V_139 ) ;
}
static struct V_249 *
F_126 ( struct V_250 * V_251 )
{
T_3 V_252 = 0 ;
if ( V_251 -> V_253 == V_254 )
V_252 = V_251 -> V_255 ;
else if ( V_251 -> V_253 == F_127 ( V_254 ) )
V_252 = F_127 ( V_251 -> V_255 ) ;
if ( V_252 ) {
#if V_256
if ( * V_57 . V_257 == 1 )
return NULL ;
if ( * V_57 . V_257 == 2 &&
V_252 == V_198 )
return NULL ;
#endif
if ( V_252 == V_197 )
return & V_258 ;
if ( V_252 == V_198 )
return & V_259 ;
return NULL ;
}
if ( V_251 -> V_253 == F_42 ( V_260 ) ) {
struct V_261 * V_262 = (struct V_261 * ) V_251 ;
F_128 ( sizeof( struct V_261 ) !=
F_90 ( struct V_250 , V_263 ) ) ;
if ( V_262 -> V_264 == F_129 ( V_265 ) &&
V_262 -> V_266 == F_129 ( V_267 ) )
return & V_88 ;
}
return NULL ;
}
int
F_130 ( struct V_73 * V_74 , struct V_33 * V_34 ,
T_4 V_268 , struct V_250 * V_251 )
{
struct V_269 * V_270 = (struct V_269 * ) V_74 -> V_271 ;
F_2 ( V_251 -> V_272 <= V_273 ) ;
F_2 ( V_34 -> V_87 ) ;
V_251 -> V_263 = V_74 -> V_274 ;
V_251 -> V_275 = V_268 ;
V_251 -> V_276 = V_277 . V_278 ;
V_251 -> V_279 = V_270 -> V_280 ;
V_251 -> V_281 = V_34 -> V_195 ;
return V_34 -> V_87 -> V_282 ( V_34 , V_251 ) ;
}
static int
F_131 ( int type )
{
switch ( type ) {
case V_283 :
case V_284 :
return type ;
case V_285 :
return V_286 ;
case V_286 :
return V_285 ;
default:
return V_287 ;
}
}
int
F_132 ( struct V_73 * V_74 , struct V_33 * V_34 ,
struct V_250 * V_251 ,
struct V_152 * V_288 ,
T_1 * V_289 )
{
struct V_290 * V_291 = V_34 -> V_52 ;
int V_292 = ! ! V_34 -> V_87 ;
int V_293 ;
int V_294 ;
int V_37 ;
struct V_249 * V_295 ;
struct V_152 V_296 ;
F_2 ( ! V_292 == ! ( V_34 -> V_195 != V_287 ) ) ;
V_293 = V_292 ? * V_57 . V_58 :
F_133 () ;
V_37 = F_134 ( V_291 , & V_251 -> V_253 ,
sizeof( V_251 -> V_253 ) , V_293 ) ;
if ( V_37 ) {
F_12 ( L_25 ,
V_37 , & V_34 -> V_106 ) ;
F_2 ( V_37 < 0 ) ;
return V_37 ;
}
if ( V_251 -> V_253 != V_254 &&
V_251 -> V_253 != F_127 ( V_254 ) &&
V_251 -> V_253 != F_42 ( V_260 ) ) {
F_12 ( L_26 ,
F_135 ( V_251 -> V_253 ) ,
V_260 ,
& V_34 -> V_106 ) ;
return - V_72 ;
}
V_37 = F_134 ( V_291 , & V_251 -> V_255 ,
sizeof( V_251 -> V_255 ) , V_293 ) ;
if ( V_37 ) {
F_12 ( L_25 ,
V_37 , & V_34 -> V_106 ) ;
F_2 ( V_37 < 0 ) ;
return V_37 ;
}
V_295 = F_126 ( V_251 ) ;
if ( ! V_295 ) {
if ( ! V_292 ) {
V_34 -> V_87 = & V_259 ;
#if V_256
if ( * V_57 . V_257 == 2 )
V_34 -> V_87 = & V_258 ;
else if ( * V_57 . V_257 == 1 )
V_34 -> V_87 = & V_88 ;
#endif
V_251 -> V_272 = 0 ;
F_130 ( V_74 , V_34 , V_74 -> V_274 , V_251 ) ;
}
F_12 ( L_27 ,
V_34 -> V_87 -> V_196 ,
& V_34 -> V_106 ) ;
return - V_72 ;
}
V_294 = ( V_34 -> V_87 == V_295 ) ;
V_34 -> V_87 = V_295 ;
V_37 = V_34 -> V_87 -> V_297 ( V_34 , V_251 , V_293 ) ;
if ( V_37 ) {
F_12 ( L_28 ,
V_37 , & V_34 -> V_106 ) ;
F_2 ( V_37 < 0 ) ;
return V_37 ;
}
* V_289 = V_251 -> V_279 ;
if ( V_251 -> V_263 == V_298 ) {
F_12 ( L_29 ,
& V_34 -> V_106 ) ;
return - V_72 ;
}
if ( ! V_292 &&
V_34 -> V_108 > V_299 ) {
V_296 . V_157 = V_34 -> V_108 | V_158 ;
V_296 . V_160 = F_136 ( F_137 ( V_74 -> V_274 ) ,
V_34 -> V_106 ) ;
} else {
V_296 . V_160 = V_251 -> V_263 ;
V_296 . V_157 = V_251 -> V_276 ;
}
if ( ! V_292 ) {
* V_288 = V_296 ;
V_34 -> V_195 = F_131 ( V_251 -> V_281 ) ;
if ( V_34 -> V_195 == V_287 ) {
F_12 ( L_30 ,
V_251 -> V_281 , F_60 ( * V_288 ) ,
& V_34 -> V_106 ) ;
return - V_72 ;
}
return 0 ;
}
if ( V_288 -> V_157 != V_296 . V_157 ||
V_288 -> V_160 != V_296 . V_160 ) {
F_138 ( 0x130 , L_31 ,
F_60 ( * V_288 ) ,
& V_34 -> V_106 ,
F_60 ( V_296 ) ) ;
return - V_72 ;
}
if ( V_251 -> V_281 == V_287 ) {
return V_294 ? V_300 : V_72 ;
}
if ( F_131 ( V_251 -> V_281 ) != V_34 -> V_195 ) {
F_12 ( L_32 ,
V_34 -> V_195 , F_60 ( * V_288 ) ,
& V_34 -> V_106 , V_251 -> V_281 ) ;
return - V_72 ;
}
return 0 ;
}
static int
F_139 ( struct V_109 * V_110 )
{
F_119 ( V_301 ) ;
struct V_85 * V_86 = V_110 -> V_302 ;
int type ;
int V_303 ;
struct V_290 * V_291 ;
unsigned long V_304 ;
int V_305 = 0 ;
int V_37 = 0 ;
V_304 = F_56 ( F_27 () ,
F_24 ( * V_57 . V_58 ) ) ;
F_83 ( & V_6 . V_156 ) ;
F_2 ( V_110 -> V_111 ) ;
F_2 ( ! V_110 -> V_112 ) ;
V_110 -> V_112 = 1 ;
for (; ; ) {
V_303 = F_63 () & ~ V_110 -> V_113 ;
if ( V_86 -> V_306 || V_110 -> V_307 ||
! V_303 ) {
V_305 = 0 ;
break;
}
if ( V_86 -> V_161 > 0 ) {
F_52 ( V_96 ,
L_33 ,
F_43 ( V_86 -> V_107 . V_160 ) ,
V_86 -> V_161 ) ;
V_305 = 1 ;
}
if ( V_305 )
break;
if ( V_303 & F_140 ( V_283 ) ) {
type = V_283 ;
} else if ( V_303 & F_140 ( V_284 ) ) {
type = V_284 ;
} else if ( V_303 & F_140 ( V_285 ) ) {
type = V_285 ;
} else {
F_2 ( V_303 & F_140 ( V_286 ) ) ;
type = V_286 ;
}
F_84 ( & V_6 . V_156 ) ;
if ( F_55 ( F_27 () , V_304 ) ) {
V_37 = - V_308 ;
F_141 ( V_37 , V_86 -> V_107 . V_160 ,
V_110 -> V_151 ,
V_110 -> V_309 ) ;
goto V_310;
}
V_37 = F_142 ( & V_291 , V_86 -> V_107 . V_160 ,
V_110 -> V_311 ,
V_110 -> V_151 , V_110 -> V_309 ) ;
if ( V_37 )
goto V_310;
V_37 = F_143 ( V_86 -> V_78 , V_110 , V_291 , type ) ;
if ( V_37 < 0 ) {
F_141 ( V_37 , V_86 -> V_107 . V_160 ,
V_110 -> V_151 ,
V_110 -> V_309 ) ;
goto V_310;
}
V_305 = ( V_37 ) ;
if ( V_305 )
F_52 ( V_96 , L_34 ,
F_43 ( V_86 -> V_107 . V_160 ) ) ;
F_83 ( & V_6 . V_156 ) ;
}
V_110 -> V_111 = 0 ;
V_110 -> V_112 = 0 ;
if ( V_305 ) {
if ( V_37 == V_300 ||
( ! V_37 && V_86 -> V_161 > 0 ) ) {
V_110 -> V_149 =
F_24 ( * V_57 . V_312 ) / 1000 ;
V_110 -> V_150 = F_56 ( F_27 () ,
V_110 -> V_149 ) ;
}
F_62 ( V_110 ) ;
}
F_84 ( & V_6 . V_156 ) ;
return V_305 ;
V_310:
F_83 ( & V_6 . V_156 ) ;
V_110 -> V_111 = 0 ;
V_110 -> V_112 = 0 ;
V_110 -> V_149 *= 2 ;
V_110 -> V_149 =
F_144 ( V_110 -> V_149 ,
F_24 ( * V_57 . V_312 ) / 1000 ) ;
V_110 -> V_149 =
F_145 ( V_110 -> V_149 ,
F_24 ( * V_57 . V_313 ) / 1000 ) ;
F_2 ( V_110 -> V_149 ) ;
V_110 -> V_150 = F_56 ( F_27 () ,
V_110 -> V_149 ) ;
if ( ! F_4 ( & V_86 -> V_162 ) &&
! V_86 -> V_161 &&
! F_78 ( V_86 ) ) {
struct V_33 * V_34 ;
if ( ! F_4 ( & V_86 -> V_314 ) ) {
V_34 = F_5 ( V_86 -> V_314 . V_9 ,
struct V_33 , V_124 ) ;
F_2 ( V_34 -> V_87 == & V_259 ) ;
}
F_146 ( & V_86 -> V_162 , & V_301 ) ;
}
F_84 ( & V_6 . V_156 ) ;
F_147 ( V_86 ) ;
F_40 ( V_86 -> V_78 , & V_301 , 1 ) ;
return 0 ;
}
static int
F_148 ( T_5 V_315 , long * V_293 )
{
char V_186 [ 16 ] ;
int V_37 ;
int V_316 = V_6 . V_317 +
V_6 . V_318 ;
if ( F_149 ( V_6 . V_319 < V_320 ) ) {
return 0 ;
}
if ( V_316 >= * V_57 . V_321 ||
V_316 > V_6 . V_322 + V_323 ) {
return 0 ;
}
if ( F_4 ( & V_6 . V_116 ) ) {
return 0 ;
}
if ( V_315 - V_6 . V_324 <= 1 ) {
* V_293 = F_24 ( 1 ) ;
return 0 ;
}
if ( V_6 . V_317 > 0 ) {
return 0 ;
}
V_6 . V_325 = V_315 ;
V_6 . V_317 ++ ;
F_58 ( & V_6 . V_114 ) ;
snprintf ( V_186 , sizeof( V_186 ) , L_35 , V_316 ) ;
V_37 = F_95 ( V_326 , NULL , V_186 ) ;
F_54 ( & V_6 . V_114 ) ;
if ( ! V_37 )
return 1 ;
F_2 ( V_6 . V_317 > 0 ) ;
V_6 . V_317 -- ;
V_6 . V_324 = F_150 () ;
return 1 ;
}
static int
F_151 ( T_5 V_315 , long * V_293 )
{
int V_327 ;
if ( F_149 ( V_6 . V_319 < V_320 ) ) {
return 0 ;
}
if ( V_6 . V_317 > 0 ) {
return 0 ;
}
if ( V_6 . V_318 <=
* V_57 . V_328 ) {
return 0 ;
}
V_327 = ( int ) ( V_6 . V_325 +
V_329 - V_315 ) ;
* V_293 = ( V_327 > 0 ) ? F_24 ( V_327 ) :
F_24 ( V_329 ) ;
if ( V_327 > 0 )
return 0 ;
return V_6 . V_318 >
V_6 . V_322 + V_323 ;
}
static struct V_109 *
F_152 ( signed long * V_330 )
{
struct V_109 * V_110 ;
unsigned long V_147 ;
V_147 = F_27 () ;
F_153 (route, &ksocknal_data.ksnd_connd_routes,
ksnr_connd_list) {
if ( ! V_110 -> V_149 ||
F_55 ( V_147 , V_110 -> V_150 ) )
return V_110 ;
if ( * V_330 == V_331 ||
( int ) * V_330 > ( int ) ( V_110 -> V_150 - V_147 ) )
* V_330 = ( int ) ( V_110 -> V_150 - V_147 ) ;
}
return NULL ;
}
int
V_326 ( void * V_185 )
{
T_6 * V_332 = & V_6 . V_114 ;
struct V_333 * V_334 ;
T_7 V_335 ;
int V_241 = 0 ;
int V_336 = 0 ;
F_116 () ;
F_154 ( & V_335 , V_337 ) ;
F_54 ( V_332 ) ;
F_2 ( V_6 . V_317 > 0 ) ;
V_6 . V_317 -- ;
V_6 . V_318 ++ ;
while ( ! V_6 . V_238 ) {
struct V_109 * V_110 = NULL ;
T_5 V_315 = F_150 () ;
long V_293 = V_331 ;
int V_338 = 0 ;
if ( F_151 ( V_315 , & V_293 ) ) {
F_57 ( & V_6 . V_117 ) ;
break;
}
if ( F_148 ( V_315 , & V_293 ) ) {
V_338 = 1 ;
}
if ( ! F_4 ( & V_6 . V_339 ) ) {
V_334 = F_5 ( V_6 . V_339 . V_9 ,
struct V_333 , V_340 ) ;
F_6 ( & V_334 -> V_340 ) ;
F_58 ( V_332 ) ;
V_338 = 1 ;
F_143 ( V_334 -> V_341 , NULL ,
V_334 -> V_342 , V_287 ) ;
F_155 ( V_334 -> V_341 ) ;
F_16 ( V_334 , sizeof( * V_334 ) ) ;
F_54 ( V_332 ) ;
}
if ( V_6 . V_322 + V_323 <
V_6 . V_318 ) {
V_110 = F_152 ( & V_293 ) ;
}
if ( V_110 ) {
F_6 ( & V_110 -> V_115 ) ;
V_6 . V_322 ++ ;
F_58 ( V_332 ) ;
V_338 = 1 ;
if ( F_139 ( V_110 ) ) {
if ( V_336 ++ > V_343 ) {
F_53 ( L_36 ,
& V_110 -> V_151 ) ;
V_336 = 0 ;
}
} else {
V_336 = 0 ;
}
F_156 ( V_110 ) ;
F_54 ( V_332 ) ;
V_6 . V_322 -- ;
}
if ( V_338 ) {
if ( ++ V_241 < V_248 )
continue;
F_58 ( V_332 ) ;
V_241 = 0 ;
F_123 () ;
F_54 ( V_332 ) ;
continue;
}
F_22 ( V_344 ) ;
F_157 ( & V_6 . V_117 ,
& V_335 ) ;
F_58 ( V_332 ) ;
V_241 = 0 ;
F_23 ( V_293 ) ;
F_158 ( & V_6 . V_117 , & V_335 ) ;
F_54 ( V_332 ) ;
}
V_6 . V_318 -- ;
F_58 ( V_332 ) ;
F_100 () ;
return 0 ;
}
static struct V_33 *
F_159 ( struct V_85 * V_86 )
{
struct V_33 * V_34 ;
struct V_79 * V_345 ;
F_68 (ctmp, &peer->ksnp_conns) {
int error ;
V_34 = F_5 ( V_345 , struct V_33 , V_124 ) ;
F_2 ( ! V_34 -> V_48 ) ;
error = V_34 -> V_52 -> V_53 -> V_346 ;
if ( error ) {
F_73 ( V_34 ) ;
switch ( error ) {
case V_105 :
F_41 ( L_37 ,
F_60 ( V_86 -> V_107 ) ,
& V_34 -> V_106 ,
V_34 -> V_108 ) ;
break;
case V_308 :
F_41 ( L_38 ,
F_60 ( V_86 -> V_107 ) ,
& V_34 -> V_106 ,
V_34 -> V_108 ) ;
break;
default:
F_41 ( L_39 ,
error ,
F_60 ( V_86 -> V_107 ) ,
& V_34 -> V_106 ,
V_34 -> V_108 ) ;
break;
}
return V_34 ;
}
if ( V_34 -> V_66 &&
F_55 ( F_27 () ,
V_34 -> V_65 ) ) {
F_73 ( V_34 ) ;
F_41 ( L_40 ,
F_60 ( V_86 -> V_107 ) ,
& V_34 -> V_106 ,
V_34 -> V_108 ,
V_34 -> V_199 ,
V_34 -> V_67 ,
V_34 -> V_68 ) ;
return V_34 ;
}
if ( ( ! F_4 ( & V_34 -> V_140 ) ||
V_34 -> V_52 -> V_53 -> V_54 ) &&
F_55 ( F_27 () ,
V_34 -> V_56 ) ) {
F_73 ( V_34 ) ;
F_41 ( L_41 ,
F_60 ( V_86 -> V_107 ) ,
& V_34 -> V_106 ,
V_34 -> V_108 ) ;
return V_34 ;
}
}
return NULL ;
}
static inline void
F_160 ( struct V_85 * V_86 )
{
struct V_1 * V_3 ;
struct V_1 * V_118 ;
F_119 ( V_347 ) ;
F_83 ( & V_6 . V_156 ) ;
F_161 (tx, tmp, &peer->ksnp_tx_queue, tx_list) {
if ( ! F_55 ( F_27 () ,
V_3 -> V_91 ) )
break;
F_6 ( & V_3 -> V_10 ) ;
F_48 ( & V_3 -> V_10 , & V_347 ) ;
}
F_84 ( & V_6 . V_156 ) ;
F_40 ( V_86 -> V_78 , & V_347 , 1 ) ;
}
static int
F_162 ( struct V_85 * V_86 )
__must_hold( &ksocknal_data.ksnd_global_lock
static void
F_163 ( int V_348 )
{
struct V_79 * V_349 = & V_6 . V_350 [ V_348 ] ;
struct V_85 * V_86 ;
struct V_33 * V_34 ;
struct V_1 * V_3 ;
V_213:
F_80 ( & V_6 . V_156 ) ;
F_153 (peer, peers, ksnp_list) {
unsigned long V_304 = 0 ;
struct V_1 * V_351 ;
int V_352 = 0 ;
int V_353 = 0 ;
if ( F_162 ( V_86 ) ) {
F_82 ( & V_6 . V_156 ) ;
goto V_213;
}
V_34 = F_159 ( V_86 ) ;
if ( V_34 ) {
F_82 ( & V_6 . V_156 ) ;
F_61 ( V_34 , - V_308 ) ;
F_38 ( V_34 ) ;
goto V_213;
}
if ( ! F_4 ( & V_86 -> V_162 ) ) {
V_3 = F_5 ( V_86 -> V_162 . V_9 ,
struct V_1 , V_10 ) ;
if ( F_55 ( F_27 () ,
V_3 -> V_91 ) ) {
F_164 ( V_86 ) ;
F_82 ( & V_6 . V_156 ) ;
F_160 ( V_86 ) ;
F_165 ( V_86 ) ;
goto V_213;
}
}
if ( F_4 ( & V_86 -> V_95 ) )
continue;
V_351 = NULL ;
F_3 ( & V_86 -> V_90 ) ;
F_153 (tx, &peer->ksnp_zc_req_list, tx_zc_list) {
if ( ! F_55 ( F_27 () ,
V_3 -> V_91 ) )
break;
if ( V_3 -> V_19 -> V_48 )
continue;
if ( ! V_351 )
V_351 = V_3 ;
V_353 ++ ;
}
if ( ! V_351 ) {
F_7 ( & V_86 -> V_90 ) ;
continue;
}
V_304 = V_351 -> V_91 ;
V_352 = V_351 -> V_38 ;
V_34 = V_351 -> V_19 ;
F_73 ( V_34 ) ;
F_7 ( & V_86 -> V_90 ) ;
F_82 ( & V_6 . V_156 ) ;
F_12 ( L_42 ,
V_353 , F_43 ( V_86 -> V_107 . V_160 ) , V_351 ,
F_77 ( F_27 () - V_304 ) ,
V_352 , V_34 -> V_52 -> V_53 -> V_54 ) ;
F_61 ( V_34 , - V_308 ) ;
F_38 ( V_34 ) ;
goto V_213;
}
F_82 ( & V_6 . V_156 ) ;
}
int
F_166 ( void * V_185 )
{
T_7 V_335 ;
struct V_33 * V_34 ;
struct V_133 * V_134 ;
struct V_79 V_354 ;
int V_355 ;
long V_293 ;
int V_356 ;
int V_357 = 0 ;
unsigned long V_304 = F_27 () ;
F_116 () ;
F_167 ( & V_354 ) ;
F_154 ( & V_335 , V_337 ) ;
F_54 ( & V_6 . V_98 ) ;
while ( ! V_6 . V_238 ) {
if ( ! F_4 ( & V_6 . V_358 ) ) {
V_34 = F_5 ( V_6 . V_358 . V_9 ,
struct V_33 , V_124 ) ;
F_6 ( & V_34 -> V_124 ) ;
F_58 ( & V_6 . V_98 ) ;
F_168 ( V_34 ) ;
F_38 ( V_34 ) ;
F_54 ( & V_6 . V_98 ) ;
continue;
}
if ( ! F_4 ( & V_6 . V_359 ) ) {
V_34 = F_5 ( V_6 . V_359 . V_9 ,
struct V_33 , V_124 ) ;
F_6 ( & V_34 -> V_124 ) ;
F_58 ( & V_6 . V_98 ) ;
F_169 ( V_34 ) ;
F_54 ( & V_6 . V_98 ) ;
continue;
}
if ( ! F_4 ( & V_6 . V_101 ) ) {
F_15 ( & V_354 ,
& V_6 . V_101 ) ;
F_120 ( & V_6 . V_101 ) ;
}
F_58 ( & V_6 . V_98 ) ;
V_355 = 0 ;
while ( ! F_4 ( & V_354 ) ) {
V_34 = F_5 ( V_354 . V_9 , struct V_33 ,
V_100 ) ;
F_6 ( & V_34 -> V_100 ) ;
V_134 = V_34 -> V_135 ;
F_54 ( & V_134 -> V_139 ) ;
F_2 ( V_34 -> V_99 ) ;
V_34 -> V_144 = 1 ;
F_48 ( & V_34 -> V_100 ,
& V_134 -> V_145 ) ;
F_57 ( & V_134 -> V_146 ) ;
F_58 ( & V_134 -> V_139 ) ;
V_355 ++ ;
}
while ( ( V_293 = F_170 ( V_304 ,
F_27 () ) ) <= 0 ) {
const int V_353 = 4 ;
const int V_360 = 1 ;
int V_361 = V_6 . V_362 ;
if ( * V_57 . V_58 > V_353 * V_360 )
V_361 = ( V_361 * V_353 * V_360 ) /
* V_57 . V_58 ;
if ( ! V_361 )
V_361 = 1 ;
for ( V_356 = 0 ; V_356 < V_361 ; V_356 ++ ) {
F_163 ( V_357 ) ;
V_357 = ( V_357 + 1 ) %
V_6 . V_362 ;
}
V_304 = F_56 ( V_304 , F_24 ( V_360 ) ) ;
}
if ( V_355 ) {
V_293 = V_102 ;
}
V_6 . V_103 =
F_56 ( F_27 () , V_293 ) ;
F_22 ( V_344 ) ;
F_171 ( & V_6 . V_104 , & V_335 ) ;
if ( ! V_6 . V_238 &&
F_4 ( & V_6 . V_358 ) &&
F_4 ( & V_6 . V_359 ) )
F_23 ( V_293 ) ;
F_22 ( V_363 ) ;
F_158 ( & V_6 . V_104 , & V_335 ) ;
F_54 ( & V_6 . V_98 ) ;
}
F_58 ( & V_6 . V_98 ) ;
F_100 () ;
return 0 ;
}
