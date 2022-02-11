static struct V_1 * F_1 ( struct V_2 * V_2 )
{
struct V_3 * V_4 ;
return V_2 &&
( V_4 = V_3 ( V_2 , V_5 ) )
? F_2 ( V_4 , struct V_1 , V_4 )
: & V_6 ;
}
struct V_1 * F_3 ( struct V_7 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_8
? V_3 ( V_7 -> V_8 -> V_2 , V_5 )
: F_4 ( V_9 , V_5 ) ;
return V_4
? F_2 ( V_4 , struct V_1 , V_4 )
: & V_6 ;
}
static T_1 F_5 ( struct V_2 * V_10 , struct V_11 * V_12 ,
struct V_13 * V_13 ,
char T_2 * V_14 , T_3 V_15 , T_4 * V_16 )
{
char V_17 [ 1024 ] ;
int V_18 = F_6 ( V_17 , V_19 , V_20 ,
F_1 ( V_10 ) -> V_21 + 1 ) ;
if ( V_18 < 0 )
return V_18 ;
return F_7 ( V_14 , V_15 , V_16 , V_17 , V_18 ) ;
}
static int F_8 ( struct V_2 * V_10 , struct V_11 * V_12 ,
const char * V_14 )
{
int V_22 = F_9 ( V_14 , V_20 ) ;
if ( V_22 < 0 )
return V_22 ;
F_1 ( V_10 ) -> V_21 = V_22 - 1 ;
return 0 ;
}
static T_5 F_10 ( struct V_2 * V_10 , struct V_11 * V_12 )
{
return F_1 ( V_10 ) -> V_23 ;
}
static int F_11 ( struct V_2 * V_10 , struct V_11 * V_12 , T_5 V_24 )
{
F_1 ( V_10 ) -> V_23 = V_24 ;
return 0 ;
}
static T_5 F_12 ( struct V_2 * V_10 , struct V_11 * V_12 )
{
struct V_1 * V_25 = F_1 ( V_10 ) ;
return F_13 ( & V_25 -> V_26 . V_27 ) ;
}
static T_5 F_14 ( struct V_2 * V_10 , struct V_11 * V_12 )
{
struct V_1 * V_25 = F_1 ( V_10 ) ;
return F_13 ( & V_25 -> V_26 . V_28 ) ;
}
static T_5 F_15 ( struct V_2 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_25 = F_1 ( V_10 ) ;
return F_13 ( & V_25 -> V_26 . V_29 ) ;
}
static T_5 F_16 ( struct V_2 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_25 = F_1 ( V_10 ) ;
return F_13 ( & V_25 -> V_26 . V_30 ) ;
}
static void F_17 ( struct V_1 * V_31 )
{
V_31 -> V_21 = - 1 ;
}
static struct V_3 * F_18 ( struct V_2 * V_2 )
{
struct V_1 * V_31 ;
V_31 = F_19 ( sizeof( * V_31 ) , V_32 ) ;
if ( ! V_31 )
return F_20 ( - V_33 ) ;
F_17 ( V_31 ) ;
return & V_31 -> V_4 ;
}
static void F_21 ( struct V_2 * V_2 )
{
struct V_1 * V_31 = F_1 ( V_2 ) ;
F_22 ( V_31 ) ;
}
static unsigned V_21 ( struct V_34 * V_35 , struct V_7 * V_7 )
{
#ifdef F_23
int V_36 = F_3 ( V_7 ) -> V_21 ;
if ( V_36 >= 0 )
return V_36 ;
#endif
return F_24 ( & V_35 -> V_37 ) ;
}
static bool V_23 ( struct V_34 * V_35 , struct V_7 * V_7 )
{
#ifdef F_23
if ( F_3 ( V_7 ) -> V_23 )
return true ;
#endif
return V_35 -> V_23 ;
}
static void F_25 ( struct V_7 * V_7 , struct V_38 * V_39 )
{
struct V_40 V_41 ;
struct V_42 V_43 ;
T_6 V_44 = 0 ;
F_26 (bv, bio, iter) {
void * V_45 = F_27 ( V_41 . V_46 ) + V_41 . V_47 ;
V_44 = F_28 ( V_44 , V_45 , V_41 . V_48 ) ;
F_29 ( V_41 . V_46 ) ;
}
V_39 -> V_49 [ F_30 ( V_39 ) ] = V_44 & ( ~ 0ULL >> 1 ) ;
}
static void F_31 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
T_7 * V_54 = NULL ;
struct V_38 * V_55 = V_53 -> V_56 ? & V_53 -> V_55 : NULL ;
int V_57 ;
#if 0
while (atomic_read(&s->cl.remaining) & CLOSURE_WAITING)
closure_sync(&s->cl);
#endif
if ( ! V_53 -> V_56 )
V_54 = F_32 ( V_53 -> V_58 , & V_53 -> V_59 ,
V_53 -> V_60 ? V_51 : NULL ) ;
V_57 = F_33 ( V_53 -> V_58 , & V_53 -> V_59 ,
V_54 , V_55 ) ;
if ( V_57 == - V_61 ) {
V_53 -> V_62 = true ;
} else if ( V_57 ) {
V_53 -> error = - V_33 ;
V_53 -> V_63 = true ;
}
if ( V_54 )
F_34 ( V_54 ) ;
if ( ! V_53 -> V_63 )
F_35 ( V_51 , V_64 , V_65 ) ;
F_36 ( & V_53 -> V_59 ) ;
F_37 ( V_51 ) ;
}
static int F_38 ( struct V_66 * V_67 , unsigned V_68 ,
struct V_69 * V_58 )
{
T_3 V_70 = F_39 ( V_67 ) ;
T_3 V_71 = V_70 + V_68 ;
if ( V_71 * sizeof( T_6 ) > F_40 ( V_58 ) - sizeof( struct V_72 ) )
return - V_33 ;
return F_41 ( V_67 , V_68 ) ;
}
static void F_42 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
struct V_7 * V_7 = V_53 -> V_7 ;
F_43 ( L_1 ,
F_44 ( V_7 ) , ( T_6 ) V_7 -> V_73 . V_74 ) ;
while ( F_44 ( V_7 ) ) {
unsigned V_75 = F_45 ( F_44 ( V_7 ) ,
1U << ( V_76 - 1 ) ) ;
if ( F_38 ( & V_53 -> V_59 , 2 , V_53 -> V_58 ) )
goto V_77;
V_7 -> V_73 . V_74 += V_75 ;
V_7 -> V_73 . V_78 -= V_75 << 9 ;
F_46 ( & V_53 -> V_59 ,
& F_47 ( V_53 -> V_79 , V_7 -> V_73 . V_74 , V_75 ) ) ;
}
V_53 -> V_63 = true ;
F_48 ( V_7 ) ;
V_77:
F_35 ( V_51 , F_31 , V_65 ) ;
}
static void F_49 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
struct V_38 * V_80 = V_53 -> V_59 . V_81 , * V_82 = V_53 -> V_59 . V_81 ;
while ( V_80 != V_53 -> V_59 . V_83 ) {
struct V_38 * V_84 = F_50 ( V_80 ) ;
F_51 ( V_80 , 0 ) ;
memmove ( V_82 , V_80 , F_52 ( V_80 ) ) ;
V_82 = F_50 ( V_82 ) ;
V_80 = V_84 ;
}
V_53 -> V_59 . V_83 = V_82 ;
F_31 ( V_51 ) ;
}
static void F_53 ( struct V_7 * V_7 , int error )
{
struct V_50 * V_51 = V_7 -> V_85 ;
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
if ( error ) {
if ( V_53 -> V_86 )
V_53 -> error = error ;
else if ( ! V_53 -> V_56 )
F_54 ( V_51 , F_49 , V_65 ) ;
else
F_54 ( V_51 , NULL , NULL ) ;
}
F_55 ( V_53 -> V_58 , V_7 , error , L_2 ) ;
}
static void V_64 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
struct V_7 * V_7 = V_53 -> V_7 , * V_84 ;
if ( F_56 ( F_44 ( V_7 ) , & V_53 -> V_58 -> V_87 ) < 0 ) {
F_57 ( V_53 -> V_58 ) ;
F_58 ( V_53 -> V_58 ) ;
}
if ( V_53 -> V_88 )
return F_42 ( V_51 ) ;
V_7 -> V_89 &= ~ ( V_90 | V_91 ) ;
do {
unsigned V_92 ;
struct V_38 * V_39 ;
struct V_93 * V_94 = V_53 -> V_58 -> V_95 ;
if ( F_38 ( & V_53 -> V_59 ,
3 + ( V_53 -> V_44 ? 1 : 0 ) ,
V_53 -> V_58 ) )
F_35 ( V_51 , F_31 , V_65 ) ;
V_39 = V_53 -> V_59 . V_83 ;
F_59 ( V_39 ) ;
F_60 ( V_39 , V_53 -> V_79 ) ;
F_61 ( V_39 , V_7 -> V_73 . V_74 ) ;
if ( ! F_62 ( V_53 -> V_58 , V_39 , F_44 ( V_7 ) ,
V_53 -> V_96 , V_53 -> V_97 ,
V_53 -> V_86 ) )
goto V_98;
V_84 = F_63 ( V_7 , F_64 ( V_39 ) , V_99 , V_94 ) ;
V_84 -> V_100 = F_53 ;
V_84 -> V_85 = V_51 ;
if ( V_53 -> V_86 ) {
F_65 ( V_39 , true ) ;
for ( V_92 = 0 ; V_92 < F_30 ( V_39 ) ; V_92 ++ )
F_66 ( F_67 ( V_53 -> V_58 , V_39 , V_92 ) ,
V_101 ) ;
}
F_68 ( V_39 , V_53 -> V_44 ) ;
if ( F_69 ( V_39 ) )
F_25 ( V_84 , V_39 ) ;
F_70 ( V_39 ) ;
F_71 ( & V_53 -> V_59 ) ;
V_84 -> V_89 |= V_102 ;
F_72 ( V_84 , V_53 -> V_58 , V_39 , 0 ) ;
} while ( V_84 != V_7 );
V_53 -> V_63 = true ;
F_35 ( V_51 , F_31 , V_65 ) ;
V_98:
F_73 ( V_53 -> V_86 ) ;
if ( ! V_53 -> V_56 ) {
V_53 -> V_88 = true ;
return F_42 ( V_51 ) ;
} else {
V_53 -> V_63 = true ;
F_48 ( V_7 ) ;
if ( ! F_74 ( & V_53 -> V_59 ) )
F_35 ( V_51 , F_31 , V_65 ) ;
else
F_37 ( V_51 ) ;
}
}
void F_75 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
F_76 ( V_53 -> V_7 , V_53 -> V_86 , V_53 -> V_88 ) ;
F_77 ( & V_53 -> V_59 ) ;
F_78 ( V_53 -> V_7 ) ;
V_64 ( V_51 ) ;
}
unsigned F_79 ( struct V_69 * V_58 )
{
int V_92 ;
long rand ;
if ( ! V_58 -> V_103 &&
! V_58 -> V_104 )
return 0 ;
V_92 = ( F_80 () - V_58 -> V_105 ) / 1024 ;
if ( V_92 < 0 )
return 0 ;
V_92 += F_13 ( & V_58 -> V_106 ) ;
if ( V_92 >= 0 )
return 0 ;
V_92 += V_107 ;
if ( V_92 > 0 )
V_92 = F_81 ( V_92 , 6 ) ;
rand = F_82 () ;
V_92 -= F_83 ( & rand , V_108 ) ;
return V_92 > 0 ? V_92 : 1 ;
}
static void F_84 ( struct V_109 * V_110 )
{
F_85 ( V_110 -> V_111 ,
V_110 -> V_112 , 8 , 0 ) ;
V_110 -> V_112 = 0 ;
}
static struct V_113 * F_86 ( struct V_34 * V_35 , T_6 V_39 )
{
return & V_35 -> V_114 [ F_87 ( V_39 , V_115 ) ] ;
}
static bool F_88 ( struct V_34 * V_35 , struct V_7 * V_7 )
{
struct V_69 * V_58 = V_35 -> V_116 . V_58 ;
unsigned V_117 = V_21 ( V_35 , V_7 ) ;
unsigned V_75 , V_106 = F_79 ( V_58 ) ;
struct V_109 * V_118 = V_9 ;
struct V_119 * V_92 ;
if ( F_89 ( V_120 , & V_35 -> V_116 . V_121 ) ||
V_58 -> V_122 . V_123 > V_124 ||
( V_7 -> V_89 & V_125 ) )
goto V_126;
if ( V_117 == V_127 ||
( V_117 == V_128 &&
( V_7 -> V_89 & V_102 ) ) )
goto V_126;
if ( V_7 -> V_73 . V_74 & ( V_58 -> V_37 . V_129 - 1 ) ||
F_44 ( V_7 ) & ( V_58 -> V_37 . V_129 - 1 ) ) {
F_43 ( L_3 ) ;
goto V_126;
}
if ( F_90 ( V_35 ) ) {
if ( ( F_82 () & 3 ) == 3 )
goto V_126;
else
goto V_130;
}
if ( ! V_106 && ! V_35 -> V_131 )
goto V_130;
if ( ! V_106 &&
V_117 == V_132 &&
( V_7 -> V_89 & V_102 ) &&
( V_7 -> V_89 & V_133 ) )
goto V_130;
F_91 ( & V_35 -> V_134 ) ;
F_92 (i, iohash(dc, bio->bi_iter.bi_sector), hash)
if ( V_92 -> V_135 == V_7 -> V_73 . V_74 &&
F_93 ( V_136 , V_92 -> V_136 ) )
goto V_137;
V_92 = F_94 ( & V_35 -> V_138 , struct V_119 , V_139 ) ;
F_84 ( V_118 ) ;
V_92 -> V_140 = 0 ;
V_137:
if ( V_92 -> V_140 + V_7 -> V_73 . V_78 > V_92 -> V_140 )
V_92 -> V_140 += V_7 -> V_73 . V_78 ;
V_92 -> V_135 = F_95 ( V_7 ) ;
V_92 -> V_136 = V_136 + F_96 ( 5000 ) ;
V_118 -> V_112 = V_92 -> V_140 ;
F_97 ( & V_92 -> V_141 ) ;
F_98 ( & V_92 -> V_141 , F_86 ( V_35 , V_92 -> V_135 ) ) ;
F_99 ( & V_92 -> V_139 , & V_35 -> V_138 ) ;
F_100 ( & V_35 -> V_134 ) ;
V_75 = F_101 ( V_118 -> V_112 ,
V_118 -> V_111 ) >> 9 ;
if ( V_35 -> V_131 &&
V_75 >= V_35 -> V_131 >> 9 ) {
F_102 ( V_7 ) ;
goto V_126;
}
if ( V_106 && V_75 >= V_106 ) {
F_103 ( V_7 ) ;
goto V_126;
}
V_130:
F_104 ( V_58 , F_44 ( V_7 ) ) ;
return false ;
V_126:
F_105 ( V_58 , V_35 , F_44 ( V_7 ) ) ;
return true ;
}
static void F_106 ( struct V_7 * V_7 , int error )
{
struct V_142 * V_143 = F_2 ( V_7 , struct V_142 , V_7 ) ;
struct V_50 * V_51 = V_7 -> V_85 ;
struct V_144 * V_145 = F_2 ( V_51 , struct V_144 , V_51 ) ;
if ( error )
V_145 -> V_146 . error = error ;
else if ( ! F_107 ( & V_143 -> V_147 ) &&
F_108 ( V_145 -> V_146 . V_58 , & V_143 -> V_147 , 0 ) ) {
F_109 ( & V_145 -> V_146 . V_58 -> V_148 ) ;
V_145 -> V_146 . error = - V_149 ;
}
F_55 ( V_145 -> V_146 . V_58 , V_7 , error , L_4 ) ;
}
static int F_110 ( struct V_150 * V_53 , struct V_151 * V_143 , struct V_38 * V_39 )
{
struct V_144 * V_145 = F_2 ( V_53 , struct V_144 , V_53 ) ;
struct V_7 * V_84 , * V_7 = & V_145 -> V_7 . V_7 ;
struct V_38 * V_152 ;
unsigned V_49 ;
if ( F_111 ( V_39 , & F_47 ( V_145 -> V_146 . V_79 , V_7 -> V_73 . V_74 , 0 ) ) <= 0 )
return V_153 ;
if ( F_112 ( V_39 ) != V_145 -> V_146 . V_79 ||
F_113 ( V_39 ) > V_7 -> V_73 . V_74 ) {
unsigned F_44 = F_44 ( V_7 ) ;
unsigned V_75 = F_112 ( V_39 ) == V_145 -> V_146 . V_79
? F_114 ( T_6 , V_154 ,
F_113 ( V_39 ) - V_7 -> V_73 . V_74 )
: V_154 ;
int V_57 = V_145 -> V_45 -> V_155 ( V_143 , V_145 , V_7 , V_75 ) ;
if ( V_57 != V_153 )
return V_57 ;
F_73 ( F_44 <= V_75 ) ;
}
if ( ! F_64 ( V_39 ) )
return V_153 ;
V_49 = 0 ;
F_67 ( V_143 -> V_58 , V_39 , V_49 ) -> V_156 = V_157 ;
if ( F_107 ( V_39 ) )
V_145 -> V_158 = true ;
V_84 = F_63 ( V_7 , F_114 ( T_6 , V_154 ,
F_115 ( V_39 ) - V_7 -> V_73 . V_74 ) ,
V_99 , V_145 -> V_45 -> V_95 ) ;
V_152 = & F_2 ( V_84 , struct V_142 , V_7 ) -> V_147 ;
F_116 ( V_152 , V_39 , V_49 ) ;
F_117 ( & F_47 ( V_145 -> V_146 . V_79 , V_84 -> V_73 . V_74 , 0 ) , V_152 ) ;
F_118 ( & F_47 ( V_145 -> V_146 . V_79 , F_95 ( V_84 ) , 0 ) , V_152 ) ;
V_84 -> V_100 = F_106 ;
V_84 -> V_85 = & V_145 -> V_51 ;
F_119 ( V_84 , V_143 -> V_58 ) ;
return V_84 == V_7 ? V_159 : V_153 ;
}
static void F_120 ( struct V_50 * V_51 )
{
struct V_144 * V_145 = F_2 ( V_51 , struct V_144 , V_146 . V_51 ) ;
struct V_7 * V_7 = & V_145 -> V_7 . V_7 ;
int V_57 ;
F_121 ( & V_145 -> V_53 , - 1 ) ;
V_57 = F_122 ( & V_145 -> V_53 , V_145 -> V_146 . V_58 ,
& F_47 ( V_145 -> V_146 . V_79 , V_7 -> V_73 . V_74 , 0 ) ,
F_110 , V_160 ) ;
if ( V_57 == - V_161 )
F_35 ( V_51 , F_120 , V_65 ) ;
F_37 ( V_51 ) ;
}
static void F_123 ( struct V_7 * V_7 , int error )
{
struct V_50 * V_51 = V_7 -> V_85 ;
if ( error ) {
struct V_144 * V_145 = F_2 ( V_51 , struct V_144 , V_51 ) ;
V_145 -> V_146 . error = error ;
V_145 -> V_162 = false ;
}
F_48 ( V_7 ) ;
F_124 ( V_51 ) ;
}
static void F_125 ( struct V_144 * V_145 )
{
if ( V_145 -> V_163 ) {
int V_164 , V_165 = F_126 ( V_145 -> V_163 ) ;
unsigned long V_166 = V_136 - V_145 -> V_167 ;
V_164 = F_127 () ;
F_128 ( V_164 , & V_145 -> V_45 -> V_116 -> V_168 ) ;
F_129 ( V_164 , & V_145 -> V_45 -> V_116 -> V_168 , V_169 [ V_165 ] , V_166 ) ;
F_130 () ;
F_131 ( V_145 -> V_45 , V_145 -> V_163 ) ;
F_132 ( V_145 -> V_163 , V_145 -> V_146 . error ) ;
V_145 -> V_163 = NULL ;
}
}
static void F_133 ( struct V_144 * V_145 , struct V_7 * V_163 )
{
struct V_7 * V_7 = & V_145 -> V_7 . V_7 ;
F_134 ( V_7 ) ;
F_135 ( V_7 , V_163 ) ;
V_7 -> V_100 = F_123 ;
V_7 -> V_85 = & V_145 -> V_51 ;
F_136 ( & V_7 -> V_170 , 3 ) ;
}
static void F_137 ( struct V_50 * V_51 )
{
struct V_144 * V_145 = F_2 ( V_51 , struct V_144 , V_51 ) ;
F_125 ( V_145 ) ;
if ( V_145 -> V_146 . V_7 )
F_48 ( V_145 -> V_146 . V_7 ) ;
F_138 ( V_51 ) ;
F_139 ( V_145 , V_145 -> V_45 -> V_58 -> V_144 ) ;
}
static inline struct V_144 * F_140 ( struct V_7 * V_7 ,
struct V_171 * V_45 )
{
struct V_144 * V_145 ;
V_145 = F_141 ( V_45 -> V_58 -> V_144 , V_99 ) ;
F_142 ( & V_145 -> V_51 , NULL ) ;
F_133 ( V_145 , V_7 ) ;
V_145 -> V_163 = V_7 ;
V_145 -> V_155 = NULL ;
V_145 -> V_45 = V_45 ;
V_145 -> V_162 = 1 ;
V_145 -> V_172 = ( V_7 -> V_89 & V_102 ) != 0 ;
V_145 -> V_158 = 0 ;
V_145 -> V_167 = V_136 ;
V_145 -> V_146 . V_58 = V_45 -> V_58 ;
V_145 -> V_146 . V_7 = NULL ;
V_145 -> V_146 . V_79 = V_45 -> V_173 ;
V_145 -> V_146 . V_96 = F_143 ( ( unsigned long ) V_9 , 16 ) ;
V_145 -> V_146 . V_97 = 0 ;
V_145 -> V_146 . error = 0 ;
V_145 -> V_146 . V_121 = 0 ;
V_145 -> V_146 . V_60 = ( V_7 -> V_89 & ( V_90 | V_91 ) ) != 0 ;
return V_145 ;
}
static void F_144 ( struct V_50 * V_51 )
{
struct V_144 * V_145 = F_2 ( V_51 , struct V_144 , V_51 ) ;
struct V_34 * V_35 = F_2 ( V_145 -> V_45 , struct V_34 , V_116 ) ;
F_137 ( V_51 ) ;
F_145 ( V_35 ) ;
}
static void F_146 ( struct V_50 * V_51 )
{
struct V_144 * V_145 = F_2 ( V_51 , struct V_144 , V_51 ) ;
if ( V_145 -> V_146 . V_62 )
F_147 ( V_145 -> V_146 . V_58 , V_145 -> V_45 ) ;
if ( V_145 -> V_146 . V_7 ) {
int V_92 ;
struct V_40 * V_41 ;
F_148 (bv, s->iop.bio, i)
F_149 ( V_41 -> V_46 ) ;
}
F_144 ( V_51 ) ;
}
static void F_150 ( struct V_50 * V_51 )
{
struct V_144 * V_145 = F_2 ( V_51 , struct V_144 , V_51 ) ;
struct V_7 * V_7 = & V_145 -> V_7 . V_7 ;
if ( V_145 -> V_162 ) {
F_151 ( V_145 -> V_163 ) ;
V_145 -> V_146 . error = 0 ;
F_133 ( V_145 , V_145 -> V_163 ) ;
F_152 ( V_7 , V_51 , V_145 -> V_45 ) ;
}
F_35 ( V_51 , F_146 , NULL ) ;
}
static void F_153 ( struct V_50 * V_51 )
{
struct V_144 * V_145 = F_2 ( V_51 , struct V_144 , V_51 ) ;
struct V_34 * V_35 = F_2 ( V_145 -> V_45 , struct V_34 , V_116 ) ;
if ( V_145 -> V_146 . V_7 ) {
F_154 ( V_145 -> V_146 . V_7 ) ;
V_145 -> V_146 . V_7 -> V_73 . V_74 = V_145 -> V_155 -> V_73 . V_74 ;
V_145 -> V_146 . V_7 -> V_174 = V_145 -> V_155 -> V_174 ;
V_145 -> V_146 . V_7 -> V_73 . V_78 = V_145 -> V_175 << 9 ;
F_155 ( V_145 -> V_146 . V_7 , NULL ) ;
F_156 ( V_145 -> V_155 , V_145 -> V_146 . V_7 ) ;
F_48 ( V_145 -> V_155 ) ;
V_145 -> V_155 = NULL ;
}
if ( V_23 ( V_35 , & V_145 -> V_7 . V_7 ) && V_145 -> V_162 && ! V_145 -> V_158 )
F_157 ( V_35 , V_145 -> V_163 ) ;
F_125 ( V_145 ) ;
if ( V_145 -> V_146 . V_7 &&
! F_89 ( V_176 , & V_145 -> V_146 . V_58 -> V_121 ) ) {
F_73 ( ! V_145 -> V_146 . V_56 ) ;
F_158 ( & V_145 -> V_146 . V_51 , F_75 , NULL , V_51 ) ;
}
F_35 ( V_51 , F_146 , NULL ) ;
}
static void F_159 ( struct V_50 * V_51 )
{
struct V_144 * V_145 = F_2 ( V_51 , struct V_144 , V_51 ) ;
struct V_34 * V_35 = F_2 ( V_145 -> V_45 , struct V_34 , V_116 ) ;
F_160 ( V_145 -> V_146 . V_58 , V_145 -> V_45 ,
! V_145 -> V_155 , V_145 -> V_146 . V_88 ) ;
F_161 ( V_145 -> V_163 , ! V_145 -> V_155 , V_145 -> V_146 . V_88 ) ;
if ( V_145 -> V_146 . error )
F_162 ( V_51 , F_150 , V_65 ) ;
else if ( V_145 -> V_146 . V_7 || V_23 ( V_35 , & V_145 -> V_7 . V_7 ) )
F_162 ( V_51 , F_153 , V_65 ) ;
else
F_162 ( V_51 , F_144 , NULL ) ;
}
static int F_163 ( struct V_151 * V_143 , struct V_144 * V_145 ,
struct V_7 * V_7 , unsigned V_75 )
{
int V_57 = V_153 ;
unsigned V_177 = 0 ;
struct V_34 * V_35 = F_2 ( V_145 -> V_45 , struct V_34 , V_116 ) ;
struct V_7 * V_178 , * V_179 ;
if ( V_145 -> V_155 || V_145 -> V_146 . V_88 ) {
V_178 = F_63 ( V_7 , V_75 , V_99 , V_145 -> V_45 -> V_95 ) ;
V_57 = V_178 == V_7 ? V_159 : V_153 ;
goto V_180;
}
if ( ! ( V_7 -> V_89 & V_181 ) &&
! ( V_7 -> V_89 & V_182 ) &&
V_145 -> V_146 . V_58 -> V_122 . V_123 < V_183 )
V_177 = F_114 ( V_184 , V_35 -> V_185 >> 9 ,
F_164 ( V_7 -> V_174 ) - F_95 ( V_7 ) ) ;
V_145 -> V_175 = F_45 ( V_75 , F_44 ( V_7 ) + V_177 ) ;
V_145 -> V_146 . V_55 = F_47 ( V_145 -> V_146 . V_79 ,
V_7 -> V_73 . V_74 + V_145 -> V_175 ,
V_145 -> V_175 ) ;
V_57 = F_165 ( V_143 , & V_145 -> V_53 , & V_145 -> V_146 . V_55 ) ;
if ( V_57 )
return V_57 ;
V_145 -> V_146 . V_56 = true ;
V_178 = F_63 ( V_7 , V_75 , V_99 , V_145 -> V_45 -> V_95 ) ;
V_57 = V_178 == V_7 ? V_159 : - V_149 ;
V_179 = F_166 ( V_186 ,
F_167 ( V_145 -> V_175 , V_187 ) ,
V_35 -> V_116 . V_95 ) ;
if ( ! V_179 )
goto V_180;
V_179 -> V_73 . V_74 = V_178 -> V_73 . V_74 ;
V_179 -> V_174 = V_178 -> V_174 ;
V_179 -> V_73 . V_78 = V_145 -> V_175 << 9 ;
V_179 -> V_100 = F_123 ;
V_179 -> V_85 = & V_145 -> V_51 ;
F_155 ( V_179 , NULL ) ;
if ( F_168 ( V_179 , V_188 | V_99 ) )
goto V_189;
if ( V_177 )
F_169 ( V_145 -> V_146 . V_58 , V_145 -> V_45 ) ;
V_145 -> V_155 = V_178 ;
V_145 -> V_146 . V_7 = V_179 ;
F_78 ( V_179 ) ;
F_152 ( V_179 , & V_145 -> V_51 , V_145 -> V_45 ) ;
return V_57 ;
V_189:
F_48 ( V_179 ) ;
V_180:
V_178 -> V_100 = F_123 ;
V_178 -> V_85 = & V_145 -> V_51 ;
F_152 ( V_178 , & V_145 -> V_51 , V_145 -> V_45 ) ;
return V_57 ;
}
static void F_170 ( struct V_34 * V_35 , struct V_144 * V_145 )
{
struct V_50 * V_51 = & V_145 -> V_51 ;
F_158 ( & V_145 -> V_146 . V_51 , F_120 , NULL , V_51 ) ;
F_35 ( V_51 , F_159 , NULL ) ;
}
static void F_171 ( struct V_50 * V_51 )
{
struct V_144 * V_145 = F_2 ( V_51 , struct V_144 , V_51 ) ;
struct V_34 * V_35 = F_2 ( V_145 -> V_45 , struct V_34 , V_116 ) ;
F_172 ( & V_35 -> V_190 ) ;
F_144 ( V_51 ) ;
}
static void F_173 ( struct V_34 * V_35 , struct V_144 * V_145 )
{
struct V_50 * V_51 = & V_145 -> V_51 ;
struct V_7 * V_7 = & V_145 -> V_7 . V_7 ;
struct V_38 V_191 = F_47 ( V_35 -> V_116 . V_173 , V_7 -> V_73 . V_74 , 0 ) ;
struct V_38 V_192 = F_47 ( V_35 -> V_116 . V_173 , F_95 ( V_7 ) , 0 ) ;
F_174 ( & V_145 -> V_146 . V_58 -> V_193 , & V_191 , & V_192 ) ;
F_175 ( & V_35 -> V_190 ) ;
if ( F_174 ( & V_35 -> V_194 , & V_191 , & V_192 ) ) {
V_145 -> V_146 . V_88 = false ;
V_145 -> V_146 . V_86 = true ;
}
if ( V_7 -> V_89 & V_125 )
V_145 -> V_146 . V_88 = true ;
if ( F_176 ( V_35 , V_145 -> V_163 ,
V_21 ( V_35 , V_7 ) ,
V_145 -> V_146 . V_88 ) ) {
V_145 -> V_146 . V_88 = false ;
V_145 -> V_146 . V_86 = true ;
}
if ( V_145 -> V_146 . V_88 ) {
V_145 -> V_146 . V_7 = V_145 -> V_163 ;
F_78 ( V_145 -> V_146 . V_7 ) ;
if ( ! ( V_7 -> V_89 & V_125 ) ||
F_177 ( F_178 ( V_35 -> V_195 ) ) )
F_152 ( V_7 , V_51 , V_145 -> V_45 ) ;
} else if ( V_145 -> V_146 . V_86 ) {
F_179 ( V_35 ) ;
V_145 -> V_146 . V_7 = V_7 ;
if ( V_7 -> V_89 & V_90 ) {
struct V_7 * V_196 = F_166 ( V_99 , 0 ,
V_35 -> V_116 . V_95 ) ;
V_196 -> V_89 = V_197 ;
V_196 -> V_174 = V_7 -> V_174 ;
V_196 -> V_100 = F_123 ;
V_196 -> V_85 = V_51 ;
F_152 ( V_196 , V_51 , V_145 -> V_45 ) ;
}
} else {
V_145 -> V_146 . V_7 = F_180 ( V_7 , V_99 , V_35 -> V_116 . V_95 ) ;
F_152 ( V_7 , V_51 , V_145 -> V_45 ) ;
}
F_158 ( & V_145 -> V_146 . V_51 , F_75 , NULL , V_51 ) ;
F_35 ( V_51 , F_171 , NULL ) ;
}
static void F_181 ( struct V_50 * V_51 )
{
struct V_144 * V_145 = F_2 ( V_51 , struct V_144 , V_51 ) ;
struct V_7 * V_7 = & V_145 -> V_7 . V_7 ;
if ( V_145 -> V_146 . V_60 )
F_182 ( V_145 -> V_146 . V_58 , V_51 ) ;
F_152 ( V_7 , V_51 , V_145 -> V_45 ) ;
F_35 ( V_51 , F_144 , NULL ) ;
}
static void F_183 ( struct V_198 * V_199 , struct V_7 * V_7 )
{
struct V_144 * V_145 ;
struct V_171 * V_45 = V_7 -> V_174 -> V_200 -> V_201 ;
struct V_34 * V_35 = F_2 ( V_45 , struct V_34 , V_116 ) ;
int V_164 , V_165 = F_126 ( V_7 ) ;
V_164 = F_127 () ;
F_184 ( V_164 , & V_45 -> V_116 -> V_168 , V_202 [ V_165 ] ) ;
F_129 ( V_164 , & V_45 -> V_116 -> V_168 , V_75 [ V_165 ] , F_44 ( V_7 ) ) ;
F_130 () ;
V_7 -> V_174 = V_35 -> V_195 ;
V_7 -> V_73 . V_74 += V_35 -> V_37 . V_203 ;
if ( F_185 ( V_35 ) ) {
V_145 = F_140 ( V_7 , V_45 ) ;
F_186 ( V_145 -> V_45 , V_7 ) ;
if ( ! V_7 -> V_73 . V_78 ) {
F_162 ( & V_145 -> V_51 ,
F_181 ,
V_65 ) ;
} else {
V_145 -> V_146 . V_88 = F_88 ( V_35 , V_7 ) ;
if ( V_165 )
F_173 ( V_35 , V_145 ) ;
else
F_170 ( V_35 , V_145 ) ;
}
} else {
if ( ( V_7 -> V_89 & V_125 ) &&
! F_177 ( F_178 ( V_35 -> V_195 ) ) )
F_132 ( V_7 , 0 ) ;
else
F_187 ( V_7 , & V_45 -> V_204 ) ;
}
}
static int F_188 ( struct V_171 * V_45 , T_8 V_117 ,
unsigned int V_205 , unsigned long V_206 )
{
struct V_34 * V_35 = F_2 ( V_45 , struct V_34 , V_116 ) ;
return F_189 ( V_35 -> V_195 , V_117 , V_205 , V_206 ) ;
}
static int F_190 ( void * V_207 , int V_208 )
{
struct V_171 * V_45 = V_207 ;
struct V_34 * V_35 = F_2 ( V_45 , struct V_34 , V_116 ) ;
struct V_198 * V_199 = F_178 ( V_35 -> V_195 ) ;
int V_57 = 0 ;
if ( F_191 ( & V_199 -> V_209 , V_208 ) )
return 1 ;
if ( F_185 ( V_35 ) ) {
unsigned V_92 ;
struct V_210 * V_211 ;
F_192 (ca, d->c, i) {
V_199 = F_178 ( V_211 -> V_195 ) ;
V_57 |= F_191 ( & V_199 -> V_209 , V_208 ) ;
}
F_145 ( V_35 ) ;
}
return V_57 ;
}
void F_193 ( struct V_34 * V_35 )
{
struct V_212 * V_213 = V_35 -> V_116 . V_116 ;
V_213 -> V_214 -> V_215 = F_183 ;
V_213 -> V_214 -> V_209 . V_216 = F_190 ;
V_35 -> V_116 . V_155 = F_163 ;
V_35 -> V_116 . V_217 = F_188 ;
}
static int F_194 ( struct V_151 * V_143 , struct V_144 * V_145 ,
struct V_7 * V_7 , unsigned V_75 )
{
struct V_40 V_41 ;
struct V_42 V_43 ;
F_26 (bv, bio, iter) {
unsigned V_218 = F_45 ( V_41 . V_48 >> 9 , V_75 ) ;
void * V_219 = F_27 ( V_41 . V_46 ) ;
memset ( V_219 + V_41 . V_47 , 0 , V_218 << 9 ) ;
F_29 ( V_41 . V_46 ) ;
V_75 -= V_218 ;
}
F_195 ( V_7 , F_45 ( V_75 << 9 , V_7 -> V_73 . V_78 ) ) ;
if ( ! V_7 -> V_73 . V_78 )
return V_159 ;
return V_153 ;
}
static void F_196 ( struct V_50 * V_51 )
{
struct V_144 * V_145 = F_2 ( V_51 , struct V_144 , V_51 ) ;
if ( V_145 -> V_146 . V_60 )
F_182 ( V_145 -> V_146 . V_58 , V_51 ) ;
F_35 ( V_51 , F_137 , NULL ) ;
}
static void F_197 ( struct V_198 * V_199 , struct V_7 * V_7 )
{
struct V_144 * V_145 ;
struct V_50 * V_51 ;
struct V_171 * V_45 = V_7 -> V_174 -> V_200 -> V_201 ;
int V_164 , V_165 = F_126 ( V_7 ) ;
V_164 = F_127 () ;
F_184 ( V_164 , & V_45 -> V_116 -> V_168 , V_202 [ V_165 ] ) ;
F_129 ( V_164 , & V_45 -> V_116 -> V_168 , V_75 [ V_165 ] , F_44 ( V_7 ) ) ;
F_130 () ;
V_145 = F_140 ( V_7 , V_45 ) ;
V_51 = & V_145 -> V_51 ;
V_7 = & V_145 -> V_7 . V_7 ;
F_186 ( V_145 -> V_45 , V_7 ) ;
if ( ! V_7 -> V_73 . V_78 ) {
F_162 ( & V_145 -> V_51 ,
F_196 ,
V_65 ) ;
} else if ( V_165 ) {
F_174 ( & V_145 -> V_146 . V_58 -> V_193 ,
& F_47 ( V_45 -> V_173 , V_7 -> V_73 . V_74 , 0 ) ,
& F_47 ( V_45 -> V_173 , F_95 ( V_7 ) , 0 ) ) ;
V_145 -> V_146 . V_88 = ( V_7 -> V_89 & V_125 ) != 0 ;
V_145 -> V_146 . V_86 = true ;
V_145 -> V_146 . V_7 = V_7 ;
F_158 ( & V_145 -> V_146 . V_51 , F_75 , NULL , V_51 ) ;
} else {
F_158 ( & V_145 -> V_146 . V_51 , F_120 , NULL , V_51 ) ;
}
F_35 ( V_51 , F_137 , NULL ) ;
}
static int F_198 ( struct V_171 * V_45 , T_8 V_117 ,
unsigned int V_205 , unsigned long V_206 )
{
return - V_220 ;
}
static int F_199 ( void * V_207 , int V_208 )
{
struct V_171 * V_45 = V_207 ;
struct V_198 * V_199 ;
struct V_210 * V_211 ;
unsigned V_92 ;
int V_57 = 0 ;
F_192 (ca, d->c, i) {
V_199 = F_178 ( V_211 -> V_195 ) ;
V_57 |= F_191 ( & V_199 -> V_209 , V_208 ) ;
}
return V_57 ;
}
void F_200 ( struct V_171 * V_45 )
{
struct V_212 * V_213 = V_45 -> V_116 ;
V_213 -> V_214 -> V_215 = F_197 ;
V_213 -> V_214 -> V_209 . V_216 = F_199 ;
V_45 -> V_155 = F_194 ;
V_45 -> V_217 = F_198 ;
}
void F_201 ( void )
{
#ifdef F_23
F_202 ( & V_221 ) ;
#endif
if ( V_222 )
F_203 ( V_222 ) ;
}
int T_9 F_204 ( void )
{
V_222 = F_205 ( V_144 , 0 ) ;
if ( ! V_222 )
return - V_33 ;
#ifdef F_23
F_206 ( & V_221 ) ;
F_17 ( & V_6 ) ;
F_207 ( & V_221 , V_223 ) ;
#endif
return 0 ;
}
