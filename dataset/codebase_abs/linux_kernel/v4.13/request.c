static unsigned F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
return F_2 ( & V_2 -> V_4 ) ;
}
static bool F_3 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
return V_2 -> F_3 ;
}
static void F_4 ( struct V_3 * V_3 , struct V_5 * V_6 )
{
struct V_7 V_8 ;
struct V_9 V_10 ;
T_1 V_11 = 0 ;
F_5 (bv, bio, iter) {
void * V_12 = F_6 ( V_8 . V_13 ) + V_8 . V_14 ;
V_11 = F_7 ( V_11 , V_12 , V_8 . V_15 ) ;
F_8 ( V_8 . V_13 ) ;
}
V_6 -> V_16 [ F_9 ( V_6 ) ] = V_11 & ( ~ 0ULL >> 1 ) ;
}
static void F_10 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_11 ( V_18 , struct V_19 , V_18 ) ;
T_2 * V_21 = NULL ;
struct V_5 * V_22 = V_20 -> V_23 ? & V_20 -> V_22 : NULL ;
int V_24 ;
#if 0
while (atomic_read(&s->cl.remaining) & CLOSURE_WAITING)
closure_sync(&s->cl);
#endif
if ( ! V_20 -> V_23 )
V_21 = F_12 ( V_20 -> V_25 , & V_20 -> V_26 ,
V_20 -> V_27 ? V_18 : NULL ) ;
V_24 = F_13 ( V_20 -> V_25 , & V_20 -> V_26 ,
V_21 , V_22 ) ;
if ( V_24 == - V_28 ) {
V_20 -> V_29 = true ;
} else if ( V_24 ) {
V_20 -> V_30 = V_31 ;
V_20 -> V_32 = true ;
}
if ( V_21 )
F_14 ( V_21 ) ;
if ( ! V_20 -> V_32 ) {
F_15 ( V_18 , V_33 , V_20 -> V_34 ) ;
return;
}
F_16 ( & V_20 -> V_26 ) ;
F_17 ( V_18 ) ;
}
static int F_18 ( struct V_35 * V_36 , unsigned V_37 ,
struct V_38 * V_25 )
{
T_3 V_39 = F_19 ( V_36 ) ;
T_3 V_40 = V_39 + V_37 ;
if ( V_40 * sizeof( T_1 ) > F_20 ( V_25 ) - sizeof( struct V_41 ) )
return - V_42 ;
return F_21 ( V_36 , V_37 ) ;
}
static void F_22 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_11 ( V_18 , struct V_19 , V_18 ) ;
struct V_3 * V_3 = V_20 -> V_3 ;
F_23 ( L_1 ,
F_24 ( V_3 ) , ( T_1 ) V_3 -> V_43 . V_44 ) ;
while ( F_24 ( V_3 ) ) {
unsigned V_45 = F_25 ( F_24 ( V_3 ) ,
1U << ( V_46 - 1 ) ) ;
if ( F_18 ( & V_20 -> V_26 , 2 , V_20 -> V_25 ) )
goto V_47;
V_3 -> V_43 . V_44 += V_45 ;
V_3 -> V_43 . V_48 -= V_45 << 9 ;
F_26 ( & V_20 -> V_26 ,
& F_27 ( V_20 -> V_49 , V_3 -> V_43 . V_44 , V_45 ) ) ;
}
V_20 -> V_32 = true ;
F_28 ( V_3 ) ;
V_47:
F_15 ( V_18 , F_10 , V_20 -> V_34 ) ;
}
static void F_29 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_11 ( V_18 , struct V_19 , V_18 ) ;
struct V_5 * V_50 = V_20 -> V_26 . V_51 , * V_52 = V_20 -> V_26 . V_51 ;
while ( V_50 != V_20 -> V_26 . V_53 ) {
struct V_5 * V_54 = F_30 ( V_50 ) ;
F_31 ( V_50 , 0 ) ;
memmove ( V_52 , V_50 , F_32 ( V_50 ) ) ;
V_52 = F_30 ( V_52 ) ;
V_50 = V_54 ;
}
V_20 -> V_26 . V_53 = V_52 ;
F_10 ( V_18 ) ;
}
static void F_33 ( struct V_3 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_55 ;
struct V_19 * V_20 = F_11 ( V_18 , struct V_19 , V_18 ) ;
if ( V_3 -> V_56 ) {
if ( V_20 -> V_57 )
V_20 -> V_30 = V_3 -> V_56 ;
else if ( ! V_20 -> V_23 )
F_34 ( V_18 , F_29 , V_20 -> V_34 ) ;
else
F_34 ( V_18 , NULL , NULL ) ;
}
F_35 ( V_20 -> V_25 , V_3 , V_3 -> V_56 , L_2 ) ;
}
static void V_33 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_11 ( V_18 , struct V_19 , V_18 ) ;
struct V_3 * V_3 = V_20 -> V_3 , * V_54 ;
if ( F_36 ( F_24 ( V_3 ) , & V_20 -> V_25 -> V_58 ) < 0 )
F_37 ( V_20 -> V_25 ) ;
if ( V_20 -> V_59 )
return F_22 ( V_18 ) ;
V_3 -> V_60 &= ~ ( V_61 | V_62 ) ;
do {
unsigned V_63 ;
struct V_5 * V_6 ;
struct V_64 * V_65 = V_20 -> V_25 -> V_66 ;
if ( F_18 ( & V_20 -> V_26 ,
3 + ( V_20 -> V_11 ? 1 : 0 ) ,
V_20 -> V_25 ) ) {
F_15 ( V_18 , F_10 , V_20 -> V_34 ) ;
return;
}
V_6 = V_20 -> V_26 . V_53 ;
F_38 ( V_6 ) ;
F_39 ( V_6 , V_20 -> V_49 ) ;
F_40 ( V_6 , V_3 -> V_43 . V_44 ) ;
if ( ! F_41 ( V_20 -> V_25 , V_6 , F_24 ( V_3 ) ,
V_20 -> V_67 , V_20 -> V_68 ,
V_20 -> V_57 ) )
goto V_69;
V_54 = F_42 ( V_3 , F_43 ( V_6 ) , V_70 , V_65 ) ;
V_54 -> V_71 = F_33 ;
V_54 -> V_55 = V_18 ;
if ( V_20 -> V_57 ) {
F_44 ( V_6 , true ) ;
for ( V_63 = 0 ; V_63 < F_9 ( V_6 ) ; V_63 ++ )
F_45 ( F_46 ( V_20 -> V_25 , V_6 , V_63 ) ,
V_72 ) ;
}
F_47 ( V_6 , V_20 -> V_11 ) ;
if ( F_48 ( V_6 ) )
F_4 ( V_54 , V_6 ) ;
F_49 ( V_6 ) ;
F_50 ( & V_20 -> V_26 ) ;
F_51 ( V_54 , V_73 , 0 ) ;
F_52 ( V_54 , V_20 -> V_25 , V_6 , 0 ) ;
} while ( V_54 != V_3 );
V_20 -> V_32 = true ;
F_15 ( V_18 , F_10 , V_20 -> V_34 ) ;
return;
V_69:
F_53 ( V_20 -> V_57 ) ;
if ( ! V_20 -> V_23 ) {
V_20 -> V_59 = true ;
return F_22 ( V_18 ) ;
} else {
V_20 -> V_32 = true ;
F_28 ( V_3 ) ;
if ( ! F_54 ( & V_20 -> V_26 ) )
F_15 ( V_18 , F_10 , V_20 -> V_34 ) ;
else
F_17 ( V_18 ) ;
}
}
void F_55 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_11 ( V_18 , struct V_19 , V_18 ) ;
F_56 ( V_20 -> V_25 , V_20 -> V_49 , V_20 -> V_3 ,
V_20 -> V_57 , V_20 -> V_59 ) ;
F_57 ( & V_20 -> V_26 ) ;
F_58 ( V_20 -> V_3 ) ;
V_33 ( V_18 ) ;
}
unsigned F_59 ( struct V_38 * V_25 )
{
int V_63 ;
long rand ;
if ( ! V_25 -> V_74 &&
! V_25 -> V_75 )
return 0 ;
V_63 = ( F_60 () - V_25 -> V_76 ) / 1024 ;
if ( V_63 < 0 )
return 0 ;
V_63 += F_61 ( & V_25 -> V_77 ) ;
if ( V_63 >= 0 )
return 0 ;
V_63 += V_78 ;
if ( V_63 > 0 )
V_63 = F_62 ( V_63 , 6 ) ;
rand = F_63 () ;
V_63 -= F_64 ( & rand , V_79 ) ;
return V_63 > 0 ? V_63 : 1 ;
}
static void F_65 ( struct V_80 * V_81 )
{
F_66 ( V_81 -> V_82 ,
V_81 -> V_83 , 8 , 0 ) ;
V_81 -> V_83 = 0 ;
}
static struct V_84 * F_67 ( struct V_1 * V_2 , T_1 V_6 )
{
return & V_2 -> V_85 [ F_68 ( V_6 , V_86 ) ] ;
}
static bool F_69 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_38 * V_25 = V_2 -> V_87 . V_25 ;
unsigned V_88 = F_1 ( V_2 , V_3 ) ;
unsigned V_45 , V_77 = F_59 ( V_25 ) ;
struct V_80 * V_89 = V_90 ;
struct V_91 * V_63 ;
if ( F_70 ( V_92 , & V_2 -> V_87 . V_93 ) ||
V_25 -> V_94 . V_95 > V_96 ||
( F_71 ( V_3 ) == V_97 ) )
goto V_98;
if ( V_88 == V_99 ||
( V_88 == V_100 &&
F_72 ( F_71 ( V_3 ) ) ) )
goto V_98;
if ( V_3 -> V_43 . V_44 & ( V_25 -> V_4 . V_101 - 1 ) ||
F_24 ( V_3 ) & ( V_25 -> V_4 . V_101 - 1 ) ) {
F_23 ( L_3 ) ;
goto V_98;
}
if ( F_73 ( V_2 ) ) {
if ( ( F_63 () & 3 ) == 3 )
goto V_98;
else
goto V_102;
}
if ( ! V_77 && ! V_2 -> V_103 )
goto V_102;
if ( ! V_77 &&
V_88 == V_104 &&
F_72 ( V_3 -> V_60 ) &&
F_74 ( V_3 -> V_60 ) )
goto V_102;
F_75 ( & V_2 -> V_105 ) ;
F_76 (i, iohash(dc, bio->bi_iter.bi_sector), hash)
if ( V_63 -> V_106 == V_3 -> V_43 . V_44 &&
F_77 ( V_107 , V_63 -> V_107 ) )
goto V_108;
V_63 = F_78 ( & V_2 -> V_109 , struct V_91 , V_110 ) ;
F_65 ( V_89 ) ;
V_63 -> V_111 = 0 ;
V_108:
if ( V_63 -> V_111 + V_3 -> V_43 . V_48 > V_63 -> V_111 )
V_63 -> V_111 += V_3 -> V_43 . V_48 ;
V_63 -> V_106 = F_79 ( V_3 ) ;
V_63 -> V_107 = V_107 + F_80 ( 5000 ) ;
V_89 -> V_83 = V_63 -> V_111 ;
F_81 ( & V_63 -> V_112 ) ;
F_82 ( & V_63 -> V_112 , F_67 ( V_2 , V_63 -> V_106 ) ) ;
F_83 ( & V_63 -> V_110 , & V_2 -> V_109 ) ;
F_84 ( & V_2 -> V_105 ) ;
V_45 = F_85 ( V_89 -> V_83 ,
V_89 -> V_82 ) >> 9 ;
if ( V_2 -> V_103 &&
V_45 >= V_2 -> V_103 >> 9 ) {
F_86 ( V_3 ) ;
goto V_98;
}
if ( V_77 && V_45 >= V_77 ) {
F_87 ( V_3 ) ;
goto V_98;
}
V_102:
F_88 ( V_25 , F_24 ( V_3 ) ) ;
return false ;
V_98:
F_89 ( V_25 , V_2 , F_24 ( V_3 ) ) ;
return true ;
}
static void F_90 ( struct V_3 * V_3 )
{
struct V_113 * V_114 = F_11 ( V_3 , struct V_113 , V_3 ) ;
struct V_17 * V_18 = V_3 -> V_55 ;
struct V_115 * V_116 = F_11 ( V_18 , struct V_115 , V_18 ) ;
if ( V_3 -> V_56 )
V_116 -> V_117 . V_30 = V_3 -> V_56 ;
else if ( ! F_91 ( & V_114 -> V_118 ) &&
F_92 ( V_116 -> V_117 . V_25 , & V_114 -> V_118 , 0 ) ) {
F_93 ( & V_116 -> V_117 . V_25 -> V_119 ) ;
V_116 -> V_117 . V_30 = V_120 ;
}
F_35 ( V_116 -> V_117 . V_25 , V_3 , V_3 -> V_56 , L_4 ) ;
}
static int F_94 ( struct V_121 * V_20 , struct V_122 * V_114 , struct V_5 * V_6 )
{
struct V_115 * V_116 = F_11 ( V_20 , struct V_115 , V_20 ) ;
struct V_3 * V_54 , * V_3 = & V_116 -> V_3 . V_3 ;
struct V_5 * V_123 ;
unsigned V_16 ;
if ( F_95 ( V_6 , & F_27 ( V_116 -> V_117 . V_49 , V_3 -> V_43 . V_44 , 0 ) ) <= 0 )
return V_124 ;
if ( F_96 ( V_6 ) != V_116 -> V_117 . V_49 ||
F_97 ( V_6 ) > V_3 -> V_43 . V_44 ) {
unsigned F_24 = F_24 ( V_3 ) ;
unsigned V_45 = F_96 ( V_6 ) == V_116 -> V_117 . V_49
? F_98 ( T_1 , V_125 ,
F_97 ( V_6 ) - V_3 -> V_43 . V_44 )
: V_125 ;
int V_24 = V_116 -> V_12 -> V_126 ( V_114 , V_116 , V_3 , V_45 ) ;
if ( V_24 != V_124 )
return V_24 ;
F_53 ( F_24 <= V_45 ) ;
}
if ( ! F_43 ( V_6 ) )
return V_124 ;
V_16 = 0 ;
F_46 ( V_114 -> V_25 , V_6 , V_16 ) -> V_127 = V_128 ;
if ( F_91 ( V_6 ) )
V_116 -> V_129 = true ;
V_54 = F_42 ( V_3 , F_98 ( T_1 , V_125 ,
F_99 ( V_6 ) - V_3 -> V_43 . V_44 ) ,
V_70 , V_116 -> V_12 -> V_66 ) ;
V_123 = & F_11 ( V_54 , struct V_113 , V_3 ) -> V_118 ;
F_100 ( V_123 , V_6 , V_16 ) ;
F_101 ( & F_27 ( V_116 -> V_117 . V_49 , V_54 -> V_43 . V_44 , 0 ) , V_123 ) ;
F_102 ( & F_27 ( V_116 -> V_117 . V_49 , F_79 ( V_54 ) , 0 ) , V_123 ) ;
V_54 -> V_71 = F_90 ;
V_54 -> V_55 = & V_116 -> V_18 ;
F_103 ( V_54 , V_114 -> V_25 ) ;
return V_54 == V_3 ? V_130 : V_124 ;
}
static void F_104 ( struct V_17 * V_18 )
{
struct V_115 * V_116 = F_11 ( V_18 , struct V_115 , V_117 . V_18 ) ;
struct V_3 * V_3 = & V_116 -> V_3 . V_3 ;
int V_24 ;
F_105 ( & V_116 -> V_20 , - 1 ) ;
V_24 = F_106 ( & V_116 -> V_20 , V_116 -> V_117 . V_25 ,
& F_27 ( V_116 -> V_117 . V_49 , V_3 -> V_43 . V_44 , 0 ) ,
F_94 , V_131 ) ;
if ( V_24 == - V_132 ) {
F_15 ( V_18 , F_104 , V_133 ) ;
return;
}
F_17 ( V_18 ) ;
}
static void F_107 ( struct V_3 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_55 ;
if ( V_3 -> V_56 ) {
struct V_115 * V_116 = F_11 ( V_18 , struct V_115 , V_18 ) ;
V_116 -> V_117 . V_30 = V_3 -> V_56 ;
V_116 -> V_134 = false ;
}
F_28 ( V_3 ) ;
F_108 ( V_18 ) ;
}
static void F_109 ( struct V_115 * V_116 )
{
if ( V_116 -> V_135 ) {
F_110 ( F_111 ( V_116 -> V_135 ) ,
& V_116 -> V_12 -> V_87 -> V_136 , V_116 -> V_137 ) ;
F_112 ( V_116 -> V_12 , V_116 -> V_135 ) ;
V_116 -> V_135 -> V_56 = V_116 -> V_117 . V_30 ;
F_113 ( V_116 -> V_135 ) ;
V_116 -> V_135 = NULL ;
}
}
static void F_114 ( struct V_115 * V_116 , struct V_3 * V_135 )
{
struct V_3 * V_3 = & V_116 -> V_3 . V_3 ;
F_115 ( V_3 , NULL , 0 ) ;
F_116 ( V_3 , V_135 ) ;
V_3 -> V_71 = F_107 ;
V_3 -> V_55 = & V_116 -> V_18 ;
F_117 ( V_3 , 3 ) ;
}
static void F_118 ( struct V_17 * V_18 )
{
struct V_115 * V_116 = F_11 ( V_18 , struct V_115 , V_18 ) ;
F_109 ( V_116 ) ;
if ( V_116 -> V_117 . V_3 )
F_28 ( V_116 -> V_117 . V_3 ) ;
F_119 ( V_18 ) ;
F_120 ( V_116 , V_116 -> V_12 -> V_25 -> V_115 ) ;
}
static inline struct V_115 * F_121 ( struct V_3 * V_3 ,
struct V_138 * V_12 )
{
struct V_115 * V_116 ;
V_116 = F_122 ( V_12 -> V_25 -> V_115 , V_70 ) ;
F_123 ( & V_116 -> V_18 , NULL ) ;
F_114 ( V_116 , V_3 ) ;
V_116 -> V_135 = V_3 ;
V_116 -> V_126 = NULL ;
V_116 -> V_12 = V_12 ;
V_116 -> V_134 = 1 ;
V_116 -> V_139 = F_72 ( F_71 ( V_3 ) ) ;
V_116 -> V_129 = 0 ;
V_116 -> V_137 = V_107 ;
V_116 -> V_117 . V_25 = V_12 -> V_25 ;
V_116 -> V_117 . V_3 = NULL ;
V_116 -> V_117 . V_49 = V_12 -> V_140 ;
V_116 -> V_117 . V_67 = F_124 ( ( unsigned long ) V_90 , 16 ) ;
V_116 -> V_117 . V_68 = 0 ;
V_116 -> V_117 . V_30 = 0 ;
V_116 -> V_117 . V_93 = 0 ;
V_116 -> V_117 . V_27 = F_125 ( V_3 -> V_60 ) ;
V_116 -> V_117 . V_34 = V_133 ;
return V_116 ;
}
static void F_126 ( struct V_17 * V_18 )
{
struct V_115 * V_116 = F_11 ( V_18 , struct V_115 , V_18 ) ;
struct V_1 * V_2 = F_11 ( V_116 -> V_12 , struct V_1 , V_87 ) ;
F_118 ( V_18 ) ;
F_127 ( V_2 ) ;
}
static void F_128 ( struct V_17 * V_18 )
{
struct V_115 * V_116 = F_11 ( V_18 , struct V_115 , V_18 ) ;
if ( V_116 -> V_117 . V_29 )
F_129 ( V_116 -> V_117 . V_25 , V_116 -> V_12 ) ;
if ( V_116 -> V_117 . V_3 )
F_130 ( V_116 -> V_117 . V_3 ) ;
F_126 ( V_18 ) ;
}
static void F_131 ( struct V_17 * V_18 )
{
struct V_115 * V_116 = F_11 ( V_18 , struct V_115 , V_18 ) ;
struct V_3 * V_3 = & V_116 -> V_3 . V_3 ;
if ( V_116 -> V_134 ) {
F_132 ( V_116 -> V_135 ) ;
V_116 -> V_117 . V_30 = 0 ;
F_114 ( V_116 , V_116 -> V_135 ) ;
F_133 ( V_3 , V_18 ) ;
}
F_15 ( V_18 , F_128 , NULL ) ;
}
static void F_134 ( struct V_17 * V_18 )
{
struct V_115 * V_116 = F_11 ( V_18 , struct V_115 , V_18 ) ;
struct V_1 * V_2 = F_11 ( V_116 -> V_12 , struct V_1 , V_87 ) ;
if ( V_116 -> V_117 . V_3 ) {
F_135 ( V_116 -> V_117 . V_3 ) ;
V_116 -> V_117 . V_3 -> V_43 . V_44 = V_116 -> V_126 -> V_43 . V_44 ;
V_116 -> V_117 . V_3 -> V_141 = V_116 -> V_126 -> V_141 ;
V_116 -> V_117 . V_3 -> V_43 . V_48 = V_116 -> V_142 << 9 ;
F_136 ( V_116 -> V_117 . V_3 , NULL ) ;
F_137 ( V_116 -> V_126 , V_116 -> V_117 . V_3 ) ;
F_28 ( V_116 -> V_126 ) ;
V_116 -> V_126 = NULL ;
}
if ( F_3 ( V_2 , & V_116 -> V_3 . V_3 ) && V_116 -> V_134 && ! V_116 -> V_129 )
F_138 ( V_2 , V_116 -> V_135 ) ;
F_109 ( V_116 ) ;
if ( V_116 -> V_117 . V_3 &&
! F_70 ( V_143 , & V_116 -> V_117 . V_25 -> V_93 ) ) {
F_53 ( ! V_116 -> V_117 . V_23 ) ;
F_139 ( & V_116 -> V_117 . V_18 , F_55 , NULL , V_18 ) ;
}
F_15 ( V_18 , F_128 , NULL ) ;
}
static void F_140 ( struct V_17 * V_18 )
{
struct V_115 * V_116 = F_11 ( V_18 , struct V_115 , V_18 ) ;
struct V_1 * V_2 = F_11 ( V_116 -> V_12 , struct V_1 , V_87 ) ;
F_141 ( V_116 -> V_117 . V_25 , V_116 -> V_12 ,
! V_116 -> V_126 , V_116 -> V_117 . V_59 ) ;
F_142 ( V_116 -> V_135 , ! V_116 -> V_126 , V_116 -> V_117 . V_59 ) ;
if ( V_116 -> V_117 . V_30 )
F_143 ( V_18 , F_131 , V_133 ) ;
else if ( V_116 -> V_117 . V_3 || F_3 ( V_2 , & V_116 -> V_3 . V_3 ) )
F_143 ( V_18 , F_134 , V_133 ) ;
else
F_143 ( V_18 , F_126 , NULL ) ;
}
static int F_144 ( struct V_122 * V_114 , struct V_115 * V_116 ,
struct V_3 * V_3 , unsigned V_45 )
{
int V_24 = V_124 ;
unsigned V_144 = 0 ;
struct V_1 * V_2 = F_11 ( V_116 -> V_12 , struct V_1 , V_87 ) ;
struct V_3 * V_145 , * V_146 ;
if ( V_116 -> V_126 || V_116 -> V_117 . V_59 ) {
V_145 = F_42 ( V_3 , V_45 , V_70 , V_116 -> V_12 -> V_66 ) ;
V_24 = V_145 == V_3 ? V_130 : V_124 ;
goto V_147;
}
if ( ! ( V_3 -> V_60 & V_148 ) &&
! ( V_3 -> V_60 & V_149 ) &&
V_116 -> V_117 . V_25 -> V_94 . V_95 < V_150 )
V_144 = F_98 ( V_151 , V_2 -> V_152 >> 9 ,
F_145 ( V_3 -> V_141 ) - F_79 ( V_3 ) ) ;
V_116 -> V_142 = F_25 ( V_45 , F_24 ( V_3 ) + V_144 ) ;
V_116 -> V_117 . V_22 = F_27 ( V_116 -> V_117 . V_49 ,
V_3 -> V_43 . V_44 + V_116 -> V_142 ,
V_116 -> V_142 ) ;
V_24 = F_146 ( V_114 , & V_116 -> V_20 , & V_116 -> V_117 . V_22 ) ;
if ( V_24 )
return V_24 ;
V_116 -> V_117 . V_23 = true ;
V_145 = F_42 ( V_3 , V_45 , V_70 , V_116 -> V_12 -> V_66 ) ;
V_24 = V_145 == V_3 ? V_130 : - V_153 ;
V_146 = F_147 ( V_154 ,
F_148 ( V_116 -> V_142 , V_155 ) ,
V_2 -> V_87 . V_66 ) ;
if ( ! V_146 )
goto V_147;
V_146 -> V_43 . V_44 = V_145 -> V_43 . V_44 ;
V_146 -> V_141 = V_145 -> V_141 ;
V_146 -> V_43 . V_48 = V_116 -> V_142 << 9 ;
V_146 -> V_71 = F_107 ;
V_146 -> V_55 = & V_116 -> V_18 ;
F_136 ( V_146 , NULL ) ;
if ( F_149 ( V_146 , V_156 | V_70 ) )
goto V_157;
if ( V_144 )
F_150 ( V_116 -> V_117 . V_25 , V_116 -> V_12 ) ;
V_116 -> V_126 = V_145 ;
V_116 -> V_117 . V_3 = V_146 ;
F_58 ( V_146 ) ;
F_133 ( V_146 , & V_116 -> V_18 ) ;
return V_24 ;
V_157:
F_28 ( V_146 ) ;
V_147:
V_145 -> V_71 = F_107 ;
V_145 -> V_55 = & V_116 -> V_18 ;
F_133 ( V_145 , & V_116 -> V_18 ) ;
return V_24 ;
}
static void F_151 ( struct V_1 * V_2 , struct V_115 * V_116 )
{
struct V_17 * V_18 = & V_116 -> V_18 ;
F_139 ( & V_116 -> V_117 . V_18 , F_104 , NULL , V_18 ) ;
F_15 ( V_18 , F_140 , NULL ) ;
}
static void F_152 ( struct V_17 * V_18 )
{
struct V_115 * V_116 = F_11 ( V_18 , struct V_115 , V_18 ) ;
struct V_1 * V_2 = F_11 ( V_116 -> V_12 , struct V_1 , V_87 ) ;
F_153 ( & V_2 -> V_158 ) ;
F_126 ( V_18 ) ;
}
static void F_154 ( struct V_1 * V_2 , struct V_115 * V_116 )
{
struct V_17 * V_18 = & V_116 -> V_18 ;
struct V_3 * V_3 = & V_116 -> V_3 . V_3 ;
struct V_5 V_159 = F_27 ( V_2 -> V_87 . V_140 , V_3 -> V_43 . V_44 , 0 ) ;
struct V_5 V_160 = F_27 ( V_2 -> V_87 . V_140 , F_79 ( V_3 ) , 0 ) ;
F_155 ( & V_116 -> V_117 . V_25 -> V_161 , & V_159 , & V_160 ) ;
F_156 ( & V_2 -> V_158 ) ;
if ( F_155 ( & V_2 -> V_162 , & V_159 , & V_160 ) ) {
V_116 -> V_117 . V_59 = false ;
V_116 -> V_117 . V_57 = true ;
}
if ( F_71 ( V_3 ) == V_97 )
V_116 -> V_117 . V_59 = true ;
if ( F_157 ( V_2 , V_116 -> V_135 ,
F_1 ( V_2 , V_3 ) ,
V_116 -> V_117 . V_59 ) ) {
V_116 -> V_117 . V_59 = false ;
V_116 -> V_117 . V_57 = true ;
}
if ( V_116 -> V_117 . V_59 ) {
V_116 -> V_117 . V_3 = V_116 -> V_135 ;
F_58 ( V_116 -> V_117 . V_3 ) ;
if ( ( F_71 ( V_3 ) != V_97 ) ||
F_158 ( F_159 ( V_2 -> V_163 ) ) )
F_133 ( V_3 , V_18 ) ;
} else if ( V_116 -> V_117 . V_57 ) {
F_160 ( V_2 ) ;
V_116 -> V_117 . V_3 = V_3 ;
if ( V_3 -> V_60 & V_61 ) {
struct V_3 * V_164 = F_147 ( V_70 , 0 ,
V_2 -> V_87 . V_66 ) ;
V_164 -> V_141 = V_3 -> V_141 ;
V_164 -> V_71 = F_107 ;
V_164 -> V_55 = V_18 ;
V_164 -> V_60 = V_73 | V_61 ;
F_133 ( V_164 , V_18 ) ;
}
} else {
V_116 -> V_117 . V_3 = F_161 ( V_3 , V_70 , V_2 -> V_87 . V_66 ) ;
F_133 ( V_3 , V_18 ) ;
}
F_139 ( & V_116 -> V_117 . V_18 , F_55 , NULL , V_18 ) ;
F_15 ( V_18 , F_152 , NULL ) ;
}
static void F_162 ( struct V_17 * V_18 )
{
struct V_115 * V_116 = F_11 ( V_18 , struct V_115 , V_18 ) ;
struct V_3 * V_3 = & V_116 -> V_3 . V_3 ;
if ( V_116 -> V_117 . V_27 )
F_163 ( V_116 -> V_117 . V_25 , V_18 ) ;
F_133 ( V_3 , V_18 ) ;
F_15 ( V_18 , F_126 , NULL ) ;
}
static T_4 F_164 ( struct V_165 * V_166 ,
struct V_3 * V_3 )
{
struct V_115 * V_116 ;
struct V_138 * V_12 = V_3 -> V_141 -> V_167 -> V_168 ;
struct V_1 * V_2 = F_11 ( V_12 , struct V_1 , V_87 ) ;
int V_169 = F_111 ( V_3 ) ;
F_165 ( V_169 , F_24 ( V_3 ) , & V_12 -> V_87 -> V_136 ) ;
V_3 -> V_141 = V_2 -> V_163 ;
V_3 -> V_43 . V_44 += V_2 -> V_4 . V_170 ;
if ( F_166 ( V_2 ) ) {
V_116 = F_121 ( V_3 , V_12 ) ;
F_167 ( V_116 -> V_12 , V_3 ) ;
if ( ! V_3 -> V_43 . V_48 ) {
F_143 ( & V_116 -> V_18 ,
F_162 ,
V_133 ) ;
} else {
V_116 -> V_117 . V_59 = F_69 ( V_2 , V_3 ) ;
if ( V_169 )
F_154 ( V_2 , V_116 ) ;
else
F_151 ( V_2 , V_116 ) ;
}
} else {
if ( ( F_71 ( V_3 ) == V_97 ) &&
! F_158 ( F_159 ( V_2 -> V_163 ) ) )
F_113 ( V_3 ) ;
else
F_168 ( V_3 ) ;
}
return V_171 ;
}
static int F_169 ( struct V_138 * V_12 , T_5 V_88 ,
unsigned int V_172 , unsigned long V_173 )
{
struct V_1 * V_2 = F_11 ( V_12 , struct V_1 , V_87 ) ;
return F_170 ( V_2 -> V_163 , V_88 , V_172 , V_173 ) ;
}
static int F_171 ( void * V_174 , int V_175 )
{
struct V_138 * V_12 = V_174 ;
struct V_1 * V_2 = F_11 ( V_12 , struct V_1 , V_87 ) ;
struct V_165 * V_166 = F_159 ( V_2 -> V_163 ) ;
int V_24 = 0 ;
if ( F_172 ( V_166 -> V_176 , V_175 ) )
return 1 ;
if ( F_166 ( V_2 ) ) {
unsigned V_63 ;
struct V_177 * V_178 ;
F_173 (ca, d->c, i) {
V_166 = F_159 ( V_178 -> V_163 ) ;
V_24 |= F_172 ( V_166 -> V_176 , V_175 ) ;
}
F_127 ( V_2 ) ;
}
return V_24 ;
}
void F_174 ( struct V_1 * V_2 )
{
struct V_179 * V_180 = V_2 -> V_87 . V_87 ;
V_180 -> V_181 -> V_182 = F_164 ;
V_180 -> V_181 -> V_176 -> V_183 = F_171 ;
V_2 -> V_87 . V_126 = F_144 ;
V_2 -> V_87 . V_184 = F_169 ;
}
static int F_175 ( struct V_122 * V_114 , struct V_115 * V_116 ,
struct V_3 * V_3 , unsigned V_45 )
{
unsigned V_185 = F_25 ( V_45 , F_24 ( V_3 ) ) << 9 ;
F_176 ( V_3 -> V_43 . V_48 , V_185 ) ;
F_177 ( V_3 ) ;
F_176 ( V_3 -> V_43 . V_48 , V_185 ) ;
F_178 ( V_3 , V_185 ) ;
if ( ! V_3 -> V_43 . V_48 )
return V_130 ;
return V_124 ;
}
static void F_179 ( struct V_17 * V_18 )
{
struct V_115 * V_116 = F_11 ( V_18 , struct V_115 , V_18 ) ;
if ( V_116 -> V_117 . V_27 )
F_163 ( V_116 -> V_117 . V_25 , V_18 ) ;
F_15 ( V_18 , F_118 , NULL ) ;
}
static T_4 F_180 ( struct V_165 * V_166 ,
struct V_3 * V_3 )
{
struct V_115 * V_116 ;
struct V_17 * V_18 ;
struct V_138 * V_12 = V_3 -> V_141 -> V_167 -> V_168 ;
int V_169 = F_111 ( V_3 ) ;
F_165 ( V_169 , F_24 ( V_3 ) , & V_12 -> V_87 -> V_136 ) ;
V_116 = F_121 ( V_3 , V_12 ) ;
V_18 = & V_116 -> V_18 ;
V_3 = & V_116 -> V_3 . V_3 ;
F_167 ( V_116 -> V_12 , V_3 ) ;
if ( ! V_3 -> V_43 . V_48 ) {
F_143 ( & V_116 -> V_18 ,
F_179 ,
V_133 ) ;
return V_171 ;
} else if ( V_169 ) {
F_155 ( & V_116 -> V_117 . V_25 -> V_161 ,
& F_27 ( V_12 -> V_140 , V_3 -> V_43 . V_44 , 0 ) ,
& F_27 ( V_12 -> V_140 , F_79 ( V_3 ) , 0 ) ) ;
V_116 -> V_117 . V_59 = ( F_71 ( V_3 ) == V_97 ) != 0 ;
V_116 -> V_117 . V_57 = true ;
V_116 -> V_117 . V_3 = V_3 ;
F_139 ( & V_116 -> V_117 . V_18 , F_55 , NULL , V_18 ) ;
} else {
F_139 ( & V_116 -> V_117 . V_18 , F_104 , NULL , V_18 ) ;
}
F_15 ( V_18 , F_118 , NULL ) ;
return V_171 ;
}
static int F_181 ( struct V_138 * V_12 , T_5 V_88 ,
unsigned int V_172 , unsigned long V_173 )
{
return - V_186 ;
}
static int F_182 ( void * V_174 , int V_175 )
{
struct V_138 * V_12 = V_174 ;
struct V_165 * V_166 ;
struct V_177 * V_178 ;
unsigned V_63 ;
int V_24 = 0 ;
F_173 (ca, d->c, i) {
V_166 = F_159 ( V_178 -> V_163 ) ;
V_24 |= F_172 ( V_166 -> V_176 , V_175 ) ;
}
return V_24 ;
}
void F_183 ( struct V_138 * V_12 )
{
struct V_179 * V_180 = V_12 -> V_87 ;
V_180 -> V_181 -> V_182 = F_180 ;
V_180 -> V_181 -> V_176 -> V_183 = F_182 ;
V_12 -> V_126 = F_175 ;
V_12 -> V_184 = F_181 ;
}
void F_184 ( void )
{
if ( V_187 )
F_185 ( V_187 ) ;
}
int T_6 F_186 ( void )
{
V_187 = F_187 ( V_115 , 0 ) ;
if ( ! V_187 )
return - V_42 ;
return 0 ;
}
