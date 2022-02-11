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
F_22 ( & V_34 , & V_31 -> V_4 ) ;
F_23 ( V_31 ) ;
}
static unsigned V_21 ( struct V_35 * V_36 , struct V_7 * V_7 )
{
#ifdef F_24
int V_37 = F_3 ( V_7 ) -> V_21 ;
if ( V_37 >= 0 )
return V_37 ;
#endif
return F_25 ( & V_36 -> V_38 ) ;
}
static bool V_23 ( struct V_35 * V_36 , struct V_7 * V_7 )
{
#ifdef F_24
if ( F_3 ( V_7 ) -> V_23 )
return true ;
#endif
return V_36 -> V_23 ;
}
static void F_26 ( struct V_7 * V_7 , struct V_39 * V_40 )
{
struct V_41 * V_42 ;
T_6 V_43 = 0 ;
int V_44 ;
F_27 (bv, bio, i) {
void * V_45 = F_28 ( V_42 -> V_46 ) + V_42 -> V_47 ;
V_43 = F_29 ( V_43 , V_45 , V_42 -> V_48 ) ;
F_30 ( V_42 -> V_46 ) ;
}
V_40 -> V_49 [ F_31 ( V_40 ) ] = V_43 & ( ~ 0ULL >> 1 ) ;
}
static void F_32 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
T_7 * V_54 = NULL ;
struct V_39 * V_55 = V_53 -> V_56 ? & V_53 -> V_55 : NULL ;
int V_57 ;
#if 0
while (atomic_read(&s->cl.remaining) & CLOSURE_WAITING)
closure_sync(&s->cl);
#endif
if ( ! V_53 -> V_56 )
V_54 = F_33 ( V_53 -> V_58 , & V_53 -> V_59 ,
V_53 -> V_60 ? V_51 : NULL ) ;
V_57 = F_34 ( V_53 -> V_58 , & V_53 -> V_59 ,
V_54 , V_55 ) ;
if ( V_57 == - V_61 ) {
V_53 -> V_62 = true ;
} else if ( V_57 ) {
V_53 -> error = - V_33 ;
V_53 -> V_63 = true ;
}
if ( V_54 )
F_35 ( V_54 ) ;
if ( ! V_53 -> V_63 )
F_36 ( V_51 , V_64 , V_65 ) ;
F_37 ( & V_53 -> V_59 ) ;
F_38 ( V_51 ) ;
}
static void F_39 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
struct V_7 * V_7 = V_53 -> V_7 ;
F_40 ( L_1 ,
F_41 ( V_7 ) , ( T_6 ) V_7 -> V_66 ) ;
while ( F_41 ( V_7 ) ) {
unsigned V_67 = F_42 ( F_41 ( V_7 ) ,
1U << ( V_68 - 1 ) ) ;
if ( F_43 ( & V_53 -> V_59 , 0 , V_53 -> V_58 ) )
goto V_69;
V_7 -> V_66 += V_67 ;
V_7 -> V_70 -= V_67 << 9 ;
F_44 ( & V_53 -> V_59 ,
& F_45 ( V_53 -> V_71 , V_7 -> V_66 , V_67 ) ) ;
}
V_53 -> V_63 = true ;
F_46 ( V_7 ) ;
V_69:
F_36 ( V_51 , F_32 , V_65 ) ;
}
static void F_47 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
struct V_39 * V_72 = V_53 -> V_59 . V_73 , * V_74 = V_53 -> V_59 . V_73 ;
while ( V_72 != V_53 -> V_59 . V_75 ) {
struct V_39 * V_76 = F_48 ( V_72 ) ;
F_49 ( V_72 , 0 ) ;
memmove ( V_74 , V_72 , F_50 ( V_72 ) ) ;
V_74 = F_48 ( V_74 ) ;
V_72 = V_76 ;
}
V_53 -> V_59 . V_75 = V_74 ;
F_32 ( V_51 ) ;
}
static void F_51 ( struct V_7 * V_7 , int error )
{
struct V_50 * V_51 = V_7 -> V_77 ;
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
if ( error ) {
if ( V_53 -> V_78 )
V_53 -> error = error ;
else if ( ! V_53 -> V_56 )
F_52 ( V_51 , F_47 , V_65 ) ;
else
F_52 ( V_51 , NULL , NULL ) ;
}
F_53 ( V_53 -> V_58 , V_7 , error , L_2 ) ;
}
static void V_64 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
struct V_7 * V_7 = V_53 -> V_7 , * V_76 ;
if ( V_53 -> V_79 )
return F_39 ( V_51 ) ;
if ( F_54 ( F_41 ( V_7 ) , & V_53 -> V_58 -> V_80 ) < 0 ) {
F_55 ( V_53 -> V_58 ) ;
F_56 ( V_53 -> V_58 ) ;
}
V_7 -> V_81 &= ~ ( V_82 | V_83 ) ;
do {
unsigned V_44 ;
struct V_39 * V_40 ;
struct V_84 * V_85 = V_53 -> V_58 -> V_86 ;
if ( F_43 ( & V_53 -> V_59 ,
1 + ( V_53 -> V_43 ? 1 : 0 ) ,
V_53 -> V_58 ) )
F_36 ( V_51 , F_32 , V_65 ) ;
V_40 = V_53 -> V_59 . V_75 ;
F_57 ( V_40 ) ;
F_58 ( V_40 , V_53 -> V_71 ) ;
F_59 ( V_40 , V_7 -> V_66 ) ;
if ( ! F_60 ( V_53 -> V_58 , V_40 , F_41 ( V_7 ) ,
V_53 -> V_87 , V_53 -> V_88 ,
V_53 -> V_78 ) )
goto V_89;
V_76 = F_61 ( V_7 , F_62 ( V_40 ) , V_90 , V_85 ) ;
V_76 -> V_91 = F_51 ;
V_76 -> V_77 = V_51 ;
if ( V_53 -> V_78 ) {
F_63 ( V_40 , true ) ;
for ( V_44 = 0 ; V_44 < F_31 ( V_40 ) ; V_44 ++ )
F_64 ( F_65 ( V_53 -> V_58 , V_40 , V_44 ) ,
V_92 ) ;
}
F_66 ( V_40 , V_53 -> V_43 ) ;
if ( F_67 ( V_40 ) )
F_26 ( V_76 , V_40 ) ;
F_68 ( V_40 ) ;
F_69 ( & V_53 -> V_59 ) ;
V_76 -> V_81 |= V_93 ;
F_70 ( V_76 , V_53 -> V_58 , V_40 , 0 ) ;
} while ( V_76 != V_7 );
V_53 -> V_63 = true ;
F_36 ( V_51 , F_32 , V_65 ) ;
V_89:
F_71 ( V_53 -> V_78 ) ;
if ( ! V_53 -> V_56 ) {
V_53 -> V_79 = true ;
return F_39 ( V_51 ) ;
} else {
V_53 -> V_63 = true ;
F_46 ( V_7 ) ;
if ( ! F_72 ( & V_53 -> V_59 ) )
F_36 ( V_51 , F_32 , V_65 ) ;
else
F_38 ( V_51 ) ;
}
}
void F_73 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
F_74 ( V_53 -> V_7 , V_53 -> V_78 , V_53 -> V_79 ) ;
F_75 ( & V_53 -> V_59 ) ;
F_76 ( V_53 -> V_7 ) ;
V_64 ( V_51 ) ;
}
unsigned F_77 ( struct V_94 * V_58 )
{
int V_44 ;
long rand ;
if ( ! V_58 -> V_95 &&
! V_58 -> V_96 )
return 0 ;
V_44 = ( F_78 () - V_58 -> V_97 ) / 1024 ;
if ( V_44 < 0 )
return 0 ;
V_44 += F_13 ( & V_58 -> V_98 ) ;
if ( V_44 >= 0 )
return 0 ;
V_44 += V_99 ;
if ( V_44 > 0 )
V_44 = F_79 ( V_44 , 6 ) ;
rand = F_80 () ;
V_44 -= F_81 ( & rand , V_100 ) ;
return V_44 > 0 ? V_44 : 1 ;
}
static void F_82 ( struct V_101 * V_102 )
{
F_83 ( V_102 -> V_103 ,
V_102 -> V_104 , 8 , 0 ) ;
V_102 -> V_104 = 0 ;
}
static struct V_105 * F_84 ( struct V_35 * V_36 , T_6 V_40 )
{
return & V_36 -> V_106 [ F_85 ( V_40 , V_107 ) ] ;
}
static bool F_86 ( struct V_35 * V_36 , struct V_7 * V_7 )
{
struct V_94 * V_58 = V_36 -> V_108 . V_58 ;
unsigned V_109 = V_21 ( V_36 , V_7 ) ;
unsigned V_67 , V_98 = F_77 ( V_58 ) ;
struct V_101 * V_110 = V_9 ;
struct V_111 * V_44 ;
if ( F_87 ( V_112 , & V_36 -> V_108 . V_113 ) ||
V_58 -> V_114 . V_115 > V_116 ||
( V_7 -> V_81 & V_117 ) )
goto V_118;
if ( V_109 == V_119 ||
( V_109 == V_120 &&
( V_7 -> V_81 & V_93 ) ) )
goto V_118;
if ( V_7 -> V_66 & ( V_58 -> V_38 . V_121 - 1 ) ||
F_41 ( V_7 ) & ( V_58 -> V_38 . V_121 - 1 ) ) {
F_40 ( L_3 ) ;
goto V_118;
}
if ( F_88 ( V_36 ) ) {
if ( ( F_80 () & 3 ) == 3 )
goto V_118;
else
goto V_122;
}
if ( ! V_98 && ! V_36 -> V_123 )
goto V_122;
if ( ! V_98 &&
V_109 == V_124 &&
( V_7 -> V_81 & V_93 ) &&
( V_7 -> V_81 & V_125 ) )
goto V_122;
F_89 ( & V_36 -> V_126 ) ;
F_90 (i, iohash(dc, bio->bi_sector), hash)
if ( V_44 -> V_127 == V_7 -> V_66 &&
F_91 ( V_128 , V_44 -> V_128 ) )
goto V_129;
V_44 = F_92 ( & V_36 -> V_130 , struct V_111 , V_131 ) ;
F_82 ( V_110 ) ;
V_44 -> V_132 = 0 ;
V_129:
if ( V_44 -> V_132 + V_7 -> V_70 > V_44 -> V_132 )
V_44 -> V_132 += V_7 -> V_70 ;
V_44 -> V_127 = F_93 ( V_7 ) ;
V_44 -> V_128 = V_128 + F_94 ( 5000 ) ;
V_110 -> V_104 = V_44 -> V_132 ;
F_95 ( & V_44 -> V_133 ) ;
F_96 ( & V_44 -> V_133 , F_84 ( V_36 , V_44 -> V_127 ) ) ;
F_97 ( & V_44 -> V_131 , & V_36 -> V_130 ) ;
F_98 ( & V_36 -> V_126 ) ;
V_67 = F_99 ( V_110 -> V_104 ,
V_110 -> V_103 ) >> 9 ;
if ( V_36 -> V_123 &&
V_67 >= V_36 -> V_123 >> 9 ) {
F_100 ( V_7 ) ;
goto V_118;
}
if ( V_98 && V_67 >= V_98 ) {
F_101 ( V_7 ) ;
goto V_118;
}
V_122:
F_102 ( V_58 , F_41 ( V_7 ) ) ;
return false ;
V_118:
F_103 ( V_58 , V_36 , F_41 ( V_7 ) ) ;
return true ;
}
static void F_104 ( struct V_7 * V_7 , int error )
{
struct V_134 * V_135 = F_2 ( V_7 , struct V_134 , V_7 ) ;
struct V_50 * V_51 = V_7 -> V_77 ;
struct V_136 * V_137 = F_2 ( V_51 , struct V_136 , V_51 ) ;
if ( error )
V_137 -> V_138 . error = error ;
else if ( F_105 ( V_137 -> V_138 . V_58 , & V_135 -> V_139 , 0 ) ) {
F_106 ( & V_137 -> V_138 . V_58 -> V_140 ) ;
V_137 -> V_138 . error = - V_141 ;
}
F_53 ( V_137 -> V_138 . V_58 , V_7 , error , L_4 ) ;
}
static int F_107 ( struct V_142 * V_53 , struct V_143 * V_135 , struct V_39 * V_40 )
{
struct V_136 * V_137 = F_2 ( V_53 , struct V_136 , V_53 ) ;
struct V_7 * V_76 , * V_7 = & V_137 -> V_7 . V_7 ;
struct V_39 * V_144 ;
unsigned V_49 ;
if ( F_108 ( V_40 , & F_45 ( V_137 -> V_138 . V_71 , V_7 -> V_66 , 0 ) ) <= 0 )
return V_145 ;
if ( F_109 ( V_40 ) != V_137 -> V_138 . V_71 ||
F_110 ( V_40 ) > V_7 -> V_66 ) {
unsigned F_41 = F_41 ( V_7 ) ;
unsigned V_67 = F_109 ( V_40 ) == V_137 -> V_138 . V_71
? F_111 ( T_6 , V_146 ,
F_110 ( V_40 ) - V_7 -> V_66 )
: V_146 ;
int V_57 = V_137 -> V_45 -> V_147 ( V_135 , V_137 , V_7 , V_67 ) ;
if ( V_57 != V_145 )
return V_57 ;
F_71 ( F_41 <= V_67 ) ;
}
if ( ! F_62 ( V_40 ) )
return V_145 ;
V_49 = 0 ;
F_65 ( V_135 -> V_58 , V_40 , V_49 ) -> V_148 = V_149 ;
if ( F_112 ( V_40 ) )
V_137 -> V_150 = true ;
V_76 = F_61 ( V_7 , F_111 ( T_6 , V_146 ,
F_113 ( V_40 ) - V_7 -> V_66 ) ,
V_90 , V_137 -> V_45 -> V_86 ) ;
V_144 = & F_2 ( V_76 , struct V_134 , V_7 ) -> V_139 ;
F_114 ( V_144 , V_40 , V_49 ) ;
F_115 ( & F_45 ( V_137 -> V_138 . V_71 , V_76 -> V_66 , 0 ) , V_144 ) ;
F_116 ( & F_45 ( V_137 -> V_138 . V_71 , F_93 ( V_76 ) , 0 ) , V_144 ) ;
V_76 -> V_91 = F_104 ;
V_76 -> V_77 = & V_137 -> V_51 ;
F_117 ( V_76 , V_135 -> V_58 ) ;
return V_76 == V_7 ? V_151 : V_145 ;
}
static void F_118 ( struct V_50 * V_51 )
{
struct V_136 * V_137 = F_2 ( V_51 , struct V_136 , V_138 . V_51 ) ;
struct V_7 * V_7 = & V_137 -> V_7 . V_7 ;
int V_57 = F_119 ( & V_137 -> V_53 , V_137 -> V_138 . V_58 ,
& F_45 ( V_137 -> V_138 . V_71 , V_7 -> V_66 , 0 ) ,
F_107 , V_152 ) ;
if ( V_57 == - V_153 )
F_36 ( V_51 , F_118 , V_65 ) ;
F_38 ( V_51 ) ;
}
static void F_120 ( struct V_7 * V_7 , int error )
{
struct V_50 * V_51 = V_7 -> V_77 ;
if ( error ) {
struct V_136 * V_137 = F_2 ( V_51 , struct V_136 , V_51 ) ;
V_137 -> V_138 . error = error ;
V_137 -> V_154 = false ;
}
F_46 ( V_7 ) ;
F_121 ( V_51 ) ;
}
static void F_122 ( struct V_136 * V_137 )
{
if ( V_137 -> V_155 ) {
int V_156 , V_157 = F_123 ( V_137 -> V_155 ) ;
unsigned long V_158 = V_128 - V_137 -> V_159 ;
V_156 = F_124 () ;
F_125 ( V_156 , & V_137 -> V_45 -> V_108 -> V_160 ) ;
F_126 ( V_156 , & V_137 -> V_45 -> V_108 -> V_160 , V_161 [ V_157 ] , V_158 ) ;
F_127 () ;
F_128 ( V_137 -> V_45 , V_137 -> V_155 ) ;
F_129 ( V_137 -> V_155 , V_137 -> V_138 . error ) ;
V_137 -> V_155 = NULL ;
}
}
static void F_130 ( struct V_136 * V_137 )
{
struct V_7 * V_7 = & V_137 -> V_7 . V_7 ;
memcpy ( V_7 , V_137 -> V_155 , sizeof( struct V_7 ) ) ;
V_7 -> V_91 = F_120 ;
V_7 -> V_77 = & V_137 -> V_51 ;
F_131 ( & V_7 -> V_162 , 3 ) ;
}
static void F_132 ( struct V_50 * V_51 )
{
struct V_136 * V_137 = F_2 ( V_51 , struct V_136 , V_51 ) ;
F_122 ( V_137 ) ;
if ( V_137 -> V_138 . V_7 )
F_46 ( V_137 -> V_138 . V_7 ) ;
if ( V_137 -> V_163 )
F_133 ( V_137 -> V_7 . V_7 . V_164 , V_137 -> V_45 -> V_163 ) ;
F_134 ( V_51 ) ;
F_133 ( V_137 , V_137 -> V_45 -> V_58 -> V_136 ) ;
}
static struct V_136 * F_135 ( struct V_7 * V_7 , struct V_165 * V_45 )
{
struct V_136 * V_137 ;
struct V_41 * V_42 ;
V_137 = F_136 ( V_45 -> V_58 -> V_136 , V_90 ) ;
memset ( V_137 , 0 , F_137 ( struct V_136 , V_138 . V_59 ) ) ;
F_138 ( & V_137 -> V_51 , NULL ) ;
V_137 -> V_138 . V_71 = V_45 -> V_166 ;
V_137 -> V_138 . V_58 = V_45 -> V_58 ;
V_137 -> V_45 = V_45 ;
V_137 -> V_53 . V_167 = - 1 ;
V_137 -> V_138 . V_87 = F_139 ( ( unsigned long ) V_9 , 16 ) ;
V_137 -> V_155 = V_7 ;
V_137 -> V_168 = ( V_7 -> V_81 & V_93 ) != 0 ;
V_137 -> V_138 . V_60 = ( V_7 -> V_81 & ( V_82 | V_83 ) ) != 0 ;
V_137 -> V_154 = 1 ;
V_137 -> V_159 = V_128 ;
F_130 ( V_137 ) ;
if ( V_7 -> V_70 != F_140 ( V_7 ) * V_19 ) {
V_42 = F_136 ( V_45 -> V_163 , V_90 ) ;
memcpy ( V_42 , F_141 ( V_7 ) ,
sizeof( struct V_41 ) * F_140 ( V_7 ) ) ;
V_137 -> V_7 . V_7 . V_164 = V_42 ;
V_137 -> V_163 = 1 ;
}
return V_137 ;
}
static void F_142 ( struct V_50 * V_51 )
{
struct V_136 * V_137 = F_2 ( V_51 , struct V_136 , V_51 ) ;
struct V_35 * V_36 = F_2 ( V_137 -> V_45 , struct V_35 , V_108 ) ;
F_132 ( V_51 ) ;
F_143 ( V_36 ) ;
}
static void F_144 ( struct V_50 * V_51 )
{
struct V_136 * V_137 = F_2 ( V_51 , struct V_136 , V_51 ) ;
if ( V_137 -> V_138 . V_62 )
F_145 ( V_137 -> V_138 . V_58 , V_137 -> V_45 ) ;
if ( V_137 -> V_138 . V_7 ) {
int V_44 ;
struct V_41 * V_42 ;
F_146 (bv, s->iop.bio, i)
F_147 ( V_42 -> V_46 ) ;
}
F_142 ( V_51 ) ;
}
static void F_148 ( struct V_50 * V_51 )
{
struct V_136 * V_137 = F_2 ( V_51 , struct V_136 , V_51 ) ;
struct V_7 * V_7 = & V_137 -> V_7 . V_7 ;
struct V_41 * V_42 ;
int V_44 ;
if ( V_137 -> V_154 ) {
F_149 ( V_137 -> V_155 ) ;
V_137 -> V_138 . error = 0 ;
V_42 = V_137 -> V_7 . V_7 . V_164 ;
F_130 ( V_137 ) ;
V_137 -> V_7 . V_7 . V_164 = V_42 ;
if ( ! V_137 -> V_163 )
F_27 (bv, s->orig_bio, i)
V_42 -> V_47 = 0 , V_42 -> V_48 = V_19 ;
else
memcpy ( V_137 -> V_7 . V_7 . V_164 ,
F_141 ( V_137 -> V_155 ) ,
sizeof( struct V_41 ) *
F_140 ( V_137 -> V_155 ) ) ;
F_150 ( V_7 , V_51 , V_137 -> V_45 ) ;
}
F_36 ( V_51 , F_144 , NULL ) ;
}
static void F_151 ( struct V_50 * V_51 )
{
struct V_136 * V_137 = F_2 ( V_51 , struct V_136 , V_51 ) ;
struct V_35 * V_36 = F_2 ( V_137 -> V_45 , struct V_35 , V_108 ) ;
if ( V_137 -> V_138 . V_7 ) {
F_152 ( V_137 -> V_138 . V_7 ) ;
V_137 -> V_138 . V_7 -> V_66 = V_137 -> V_147 -> V_66 ;
V_137 -> V_138 . V_7 -> V_169 = V_137 -> V_147 -> V_169 ;
V_137 -> V_138 . V_7 -> V_70 = V_137 -> V_170 << 9 ;
F_153 ( V_137 -> V_138 . V_7 , NULL ) ;
F_154 ( V_137 -> V_147 , V_137 -> V_138 . V_7 ) ;
F_46 ( V_137 -> V_147 ) ;
V_137 -> V_147 = NULL ;
}
if ( V_23 ( V_36 , & V_137 -> V_7 . V_7 ) && V_137 -> V_154 &&
! V_137 -> V_163 && ! V_137 -> V_150 )
F_155 ( V_36 , V_137 -> V_155 ) ;
F_122 ( V_137 ) ;
if ( V_137 -> V_138 . V_7 &&
! F_87 ( V_171 , & V_137 -> V_138 . V_58 -> V_113 ) ) {
F_71 ( ! V_137 -> V_138 . V_56 ) ;
F_156 ( & V_137 -> V_138 . V_51 , F_73 , NULL , V_51 ) ;
}
F_36 ( V_51 , F_144 , NULL ) ;
}
static void F_157 ( struct V_50 * V_51 )
{
struct V_136 * V_137 = F_2 ( V_51 , struct V_136 , V_51 ) ;
struct V_35 * V_36 = F_2 ( V_137 -> V_45 , struct V_35 , V_108 ) ;
F_158 ( V_137 -> V_138 . V_58 , V_137 -> V_45 ,
! V_137 -> V_147 , V_137 -> V_138 . V_79 ) ;
F_159 ( V_137 -> V_155 , ! V_137 -> V_147 , V_137 -> V_138 . V_79 ) ;
if ( V_137 -> V_138 . error )
F_160 ( V_51 , F_148 , V_65 ) ;
else if ( V_137 -> V_138 . V_7 || V_23 ( V_36 , & V_137 -> V_7 . V_7 ) )
F_160 ( V_51 , F_151 , V_65 ) ;
else
F_160 ( V_51 , F_142 , NULL ) ;
}
static int F_161 ( struct V_143 * V_135 , struct V_136 * V_137 ,
struct V_7 * V_7 , unsigned V_67 )
{
int V_57 = V_145 ;
unsigned V_172 = 0 ;
struct V_35 * V_36 = F_2 ( V_137 -> V_45 , struct V_35 , V_108 ) ;
struct V_7 * V_173 , * V_174 ;
if ( V_137 -> V_147 || V_137 -> V_138 . V_79 ) {
V_173 = F_61 ( V_7 , V_67 , V_90 , V_137 -> V_45 -> V_86 ) ;
V_57 = V_173 == V_7 ? V_151 : V_145 ;
goto V_175;
}
if ( ! ( V_7 -> V_81 & V_176 ) &&
! ( V_7 -> V_81 & V_177 ) &&
V_137 -> V_138 . V_58 -> V_114 . V_115 < V_178 )
V_172 = F_111 ( V_179 , V_36 -> V_180 >> 9 ,
F_162 ( V_7 -> V_169 ) - F_93 ( V_7 ) ) ;
V_137 -> V_170 = F_42 ( V_67 , F_41 ( V_7 ) + V_172 ) ;
V_137 -> V_138 . V_55 = F_45 ( V_137 -> V_138 . V_71 ,
V_7 -> V_66 + V_137 -> V_170 ,
V_137 -> V_170 ) ;
V_57 = F_163 ( V_135 , & V_137 -> V_53 , & V_137 -> V_138 . V_55 ) ;
if ( V_57 )
return V_57 ;
V_137 -> V_138 . V_56 = true ;
V_173 = F_61 ( V_7 , V_67 , V_90 , V_137 -> V_45 -> V_86 ) ;
V_57 = V_173 == V_7 ? V_151 : - V_141 ;
V_174 = F_164 ( V_181 ,
F_165 ( V_137 -> V_170 , V_182 ) ,
V_36 -> V_108 . V_86 ) ;
if ( ! V_174 )
goto V_175;
V_174 -> V_66 = V_173 -> V_66 ;
V_174 -> V_169 = V_173 -> V_169 ;
V_174 -> V_70 = V_137 -> V_170 << 9 ;
V_174 -> V_91 = F_120 ;
V_174 -> V_77 = & V_137 -> V_51 ;
F_153 ( V_174 , NULL ) ;
if ( F_166 ( V_174 , V_183 | V_90 ) )
goto V_184;
if ( V_172 )
F_167 ( V_137 -> V_138 . V_58 , V_137 -> V_45 ) ;
V_137 -> V_147 = V_173 ;
V_137 -> V_138 . V_7 = V_174 ;
F_76 ( V_174 ) ;
F_150 ( V_174 , & V_137 -> V_51 , V_137 -> V_45 ) ;
return V_57 ;
V_184:
F_46 ( V_174 ) ;
V_175:
V_173 -> V_91 = F_120 ;
V_173 -> V_77 = & V_137 -> V_51 ;
F_150 ( V_173 , & V_137 -> V_51 , V_137 -> V_45 ) ;
return V_57 ;
}
static void F_168 ( struct V_35 * V_36 , struct V_136 * V_137 )
{
struct V_50 * V_51 = & V_137 -> V_51 ;
F_156 ( & V_137 -> V_138 . V_51 , F_118 , NULL , V_51 ) ;
F_36 ( V_51 , F_157 , NULL ) ;
}
static void F_169 ( struct V_50 * V_51 )
{
struct V_136 * V_137 = F_2 ( V_51 , struct V_136 , V_51 ) ;
struct V_35 * V_36 = F_2 ( V_137 -> V_45 , struct V_35 , V_108 ) ;
F_170 ( & V_36 -> V_185 ) ;
F_142 ( V_51 ) ;
}
static void F_171 ( struct V_35 * V_36 , struct V_136 * V_137 )
{
struct V_50 * V_51 = & V_137 -> V_51 ;
struct V_7 * V_7 = & V_137 -> V_7 . V_7 ;
struct V_39 V_186 = F_45 ( V_36 -> V_108 . V_166 , V_7 -> V_66 , 0 ) ;
struct V_39 V_187 = F_45 ( V_36 -> V_108 . V_166 , F_93 ( V_7 ) , 0 ) ;
F_172 ( & V_137 -> V_138 . V_58 -> V_188 , & V_186 , & V_187 ) ;
F_173 ( & V_36 -> V_185 ) ;
if ( F_172 ( & V_36 -> V_189 , & V_186 , & V_187 ) ) {
V_137 -> V_138 . V_79 = false ;
V_137 -> V_138 . V_78 = true ;
}
if ( V_7 -> V_81 & V_117 )
V_137 -> V_138 . V_79 = true ;
if ( F_174 ( V_36 , V_137 -> V_155 ,
V_21 ( V_36 , V_7 ) ,
V_137 -> V_138 . V_79 ) ) {
V_137 -> V_138 . V_79 = false ;
V_137 -> V_138 . V_78 = true ;
}
if ( V_137 -> V_138 . V_79 ) {
V_137 -> V_138 . V_7 = V_137 -> V_155 ;
F_76 ( V_137 -> V_138 . V_7 ) ;
if ( ! ( V_7 -> V_81 & V_117 ) ||
F_175 ( F_176 ( V_36 -> V_190 ) ) )
F_150 ( V_7 , V_51 , V_137 -> V_45 ) ;
} else if ( V_137 -> V_138 . V_78 ) {
F_177 ( V_36 ) ;
V_137 -> V_138 . V_7 = V_7 ;
if ( V_7 -> V_81 & V_82 ) {
struct V_7 * V_191 = F_164 ( V_90 , 0 ,
V_36 -> V_108 . V_86 ) ;
V_191 -> V_81 = V_192 ;
V_191 -> V_169 = V_7 -> V_169 ;
V_191 -> V_91 = F_120 ;
V_191 -> V_77 = V_51 ;
F_150 ( V_191 , V_51 , V_137 -> V_45 ) ;
}
} else {
V_137 -> V_138 . V_7 = F_178 ( V_7 , V_90 ,
V_36 -> V_108 . V_86 ) ;
F_150 ( V_7 , V_51 , V_137 -> V_45 ) ;
}
F_156 ( & V_137 -> V_138 . V_51 , F_73 , NULL , V_51 ) ;
F_36 ( V_51 , F_169 , NULL ) ;
}
static void F_179 ( struct V_50 * V_51 )
{
struct V_136 * V_137 = F_2 ( V_51 , struct V_136 , V_51 ) ;
struct V_7 * V_7 = & V_137 -> V_7 . V_7 ;
if ( V_137 -> V_138 . V_60 )
F_180 ( V_137 -> V_138 . V_58 , V_51 ) ;
F_150 ( V_7 , V_51 , V_137 -> V_45 ) ;
F_36 ( V_51 , F_142 , NULL ) ;
}
static void F_181 ( struct V_193 * V_194 , struct V_7 * V_7 )
{
struct V_136 * V_137 ;
struct V_165 * V_45 = V_7 -> V_169 -> V_195 -> V_196 ;
struct V_35 * V_36 = F_2 ( V_45 , struct V_35 , V_108 ) ;
int V_156 , V_157 = F_123 ( V_7 ) ;
V_156 = F_124 () ;
F_182 ( V_156 , & V_45 -> V_108 -> V_160 , V_197 [ V_157 ] ) ;
F_126 ( V_156 , & V_45 -> V_108 -> V_160 , V_67 [ V_157 ] , F_41 ( V_7 ) ) ;
F_127 () ;
V_7 -> V_169 = V_36 -> V_190 ;
V_7 -> V_66 += V_36 -> V_38 . V_198 ;
if ( F_183 ( V_36 ) ) {
V_137 = F_135 ( V_7 , V_45 ) ;
F_184 ( V_137 -> V_45 , V_7 ) ;
if ( ! V_7 -> V_70 ) {
F_160 ( & V_137 -> V_51 ,
F_179 ,
V_65 ) ;
} else {
V_137 -> V_138 . V_79 = F_86 ( V_36 , V_7 ) ;
if ( V_157 )
F_171 ( V_36 , V_137 ) ;
else
F_168 ( V_36 , V_137 ) ;
}
} else {
if ( ( V_7 -> V_81 & V_117 ) &&
! F_175 ( F_176 ( V_36 -> V_190 ) ) )
F_129 ( V_7 , 0 ) ;
else
F_185 ( V_7 , & V_45 -> V_199 ) ;
}
}
static int F_186 ( struct V_165 * V_45 , T_8 V_109 ,
unsigned int V_200 , unsigned long V_201 )
{
struct V_35 * V_36 = F_2 ( V_45 , struct V_35 , V_108 ) ;
return F_187 ( V_36 -> V_190 , V_109 , V_200 , V_201 ) ;
}
static int F_188 ( void * V_202 , int V_203 )
{
struct V_165 * V_45 = V_202 ;
struct V_35 * V_36 = F_2 ( V_45 , struct V_35 , V_108 ) ;
struct V_193 * V_194 = F_176 ( V_36 -> V_190 ) ;
int V_57 = 0 ;
if ( F_189 ( & V_194 -> V_204 , V_203 ) )
return 1 ;
if ( F_183 ( V_36 ) ) {
unsigned V_44 ;
struct V_205 * V_206 ;
F_190 (ca, d->c, i) {
V_194 = F_176 ( V_206 -> V_190 ) ;
V_57 |= F_189 ( & V_194 -> V_204 , V_203 ) ;
}
F_143 ( V_36 ) ;
}
return V_57 ;
}
void F_191 ( struct V_35 * V_36 )
{
struct V_207 * V_208 = V_36 -> V_108 . V_108 ;
V_208 -> V_209 -> V_210 = F_181 ;
V_208 -> V_209 -> V_204 . V_211 = F_188 ;
V_36 -> V_108 . V_147 = F_161 ;
V_36 -> V_108 . V_212 = F_186 ;
}
static int F_192 ( struct V_143 * V_135 , struct V_136 * V_137 ,
struct V_7 * V_7 , unsigned V_67 )
{
struct V_41 * V_42 ;
int V_44 ;
F_27 (bv, bio, i) {
unsigned V_213 = F_42 ( V_42 -> V_48 >> 9 , V_67 ) ;
void * V_214 = F_28 ( V_42 -> V_46 ) ;
memset ( V_214 + V_42 -> V_47 , 0 , V_213 << 9 ) ;
F_30 ( V_42 -> V_46 ) ;
V_67 -= V_213 ;
}
F_193 ( V_7 , F_42 ( V_67 << 9 , V_7 -> V_70 ) ) ;
if ( ! V_7 -> V_70 )
return V_151 ;
return V_145 ;
}
static void F_194 ( struct V_50 * V_51 )
{
struct V_136 * V_137 = F_2 ( V_51 , struct V_136 , V_51 ) ;
if ( V_137 -> V_138 . V_60 )
F_180 ( V_137 -> V_138 . V_58 , V_51 ) ;
F_36 ( V_51 , F_132 , NULL ) ;
}
static void F_195 ( struct V_193 * V_194 , struct V_7 * V_7 )
{
struct V_136 * V_137 ;
struct V_50 * V_51 ;
struct V_165 * V_45 = V_7 -> V_169 -> V_195 -> V_196 ;
int V_156 , V_157 = F_123 ( V_7 ) ;
V_156 = F_124 () ;
F_182 ( V_156 , & V_45 -> V_108 -> V_160 , V_197 [ V_157 ] ) ;
F_126 ( V_156 , & V_45 -> V_108 -> V_160 , V_67 [ V_157 ] , F_41 ( V_7 ) ) ;
F_127 () ;
V_137 = F_135 ( V_7 , V_45 ) ;
V_51 = & V_137 -> V_51 ;
V_7 = & V_137 -> V_7 . V_7 ;
F_184 ( V_137 -> V_45 , V_7 ) ;
if ( ! V_7 -> V_70 ) {
F_160 ( & V_137 -> V_51 ,
F_194 ,
V_65 ) ;
} else if ( V_157 ) {
F_172 ( & V_137 -> V_138 . V_58 -> V_188 ,
& F_45 ( V_45 -> V_166 , V_7 -> V_66 , 0 ) ,
& F_45 ( V_45 -> V_166 , F_93 ( V_7 ) , 0 ) ) ;
V_137 -> V_138 . V_79 = ( V_7 -> V_81 & V_117 ) != 0 ;
V_137 -> V_138 . V_78 = true ;
V_137 -> V_138 . V_7 = V_7 ;
F_156 ( & V_137 -> V_138 . V_51 , F_73 , NULL , V_51 ) ;
} else {
F_156 ( & V_137 -> V_138 . V_51 , F_118 , NULL , V_51 ) ;
}
F_36 ( V_51 , F_132 , NULL ) ;
}
static int F_196 ( struct V_165 * V_45 , T_8 V_109 ,
unsigned int V_200 , unsigned long V_201 )
{
return - V_215 ;
}
static int F_197 ( void * V_202 , int V_203 )
{
struct V_165 * V_45 = V_202 ;
struct V_193 * V_194 ;
struct V_205 * V_206 ;
unsigned V_44 ;
int V_57 = 0 ;
F_190 (ca, d->c, i) {
V_194 = F_176 ( V_206 -> V_190 ) ;
V_57 |= F_189 ( & V_194 -> V_204 , V_203 ) ;
}
return V_57 ;
}
void F_198 ( struct V_165 * V_45 )
{
struct V_207 * V_208 = V_45 -> V_108 ;
V_208 -> V_209 -> V_210 = F_195 ;
V_208 -> V_209 -> V_204 . V_211 = F_197 ;
V_45 -> V_147 = F_192 ;
V_45 -> V_212 = F_196 ;
}
void F_199 ( void )
{
#ifdef F_24
F_200 ( & V_34 ) ;
#endif
if ( V_216 )
F_201 ( V_216 ) ;
}
int T_9 F_202 ( void )
{
V_216 = F_203 ( V_136 , 0 ) ;
if ( ! V_216 )
return - V_33 ;
#ifdef F_24
F_204 ( & V_34 ) ;
F_17 ( & V_6 ) ;
F_205 ( & V_34 , V_217 ) ;
#endif
return 0 ;
}
