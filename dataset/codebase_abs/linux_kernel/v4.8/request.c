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
V_20 -> error = - V_30 ;
V_20 -> V_31 = true ;
}
if ( V_21 )
F_14 ( V_21 ) ;
if ( ! V_20 -> V_31 ) {
F_15 ( V_18 , V_32 , V_20 -> V_33 ) ;
return;
}
F_16 ( & V_20 -> V_26 ) ;
F_17 ( V_18 ) ;
}
static int F_18 ( struct V_34 * V_35 , unsigned V_36 ,
struct V_37 * V_25 )
{
T_3 V_38 = F_19 ( V_35 ) ;
T_3 V_39 = V_38 + V_36 ;
if ( V_39 * sizeof( T_1 ) > F_20 ( V_25 ) - sizeof( struct V_40 ) )
return - V_30 ;
return F_21 ( V_35 , V_36 ) ;
}
static void F_22 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_11 ( V_18 , struct V_19 , V_18 ) ;
struct V_3 * V_3 = V_20 -> V_3 ;
F_23 ( L_1 ,
F_24 ( V_3 ) , ( T_1 ) V_3 -> V_41 . V_42 ) ;
while ( F_24 ( V_3 ) ) {
unsigned V_43 = F_25 ( F_24 ( V_3 ) ,
1U << ( V_44 - 1 ) ) ;
if ( F_18 ( & V_20 -> V_26 , 2 , V_20 -> V_25 ) )
goto V_45;
V_3 -> V_41 . V_42 += V_43 ;
V_3 -> V_41 . V_46 -= V_43 << 9 ;
F_26 ( & V_20 -> V_26 ,
& F_27 ( V_20 -> V_47 , V_3 -> V_41 . V_42 , V_43 ) ) ;
}
V_20 -> V_31 = true ;
F_28 ( V_3 ) ;
V_45:
F_15 ( V_18 , F_10 , V_20 -> V_33 ) ;
}
static void F_29 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_11 ( V_18 , struct V_19 , V_18 ) ;
struct V_5 * V_48 = V_20 -> V_26 . V_49 , * V_50 = V_20 -> V_26 . V_49 ;
while ( V_48 != V_20 -> V_26 . V_51 ) {
struct V_5 * V_52 = F_30 ( V_48 ) ;
F_31 ( V_48 , 0 ) ;
memmove ( V_50 , V_48 , F_32 ( V_48 ) ) ;
V_50 = F_30 ( V_50 ) ;
V_48 = V_52 ;
}
V_20 -> V_26 . V_51 = V_50 ;
F_10 ( V_18 ) ;
}
static void F_33 ( struct V_3 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_53 ;
struct V_19 * V_20 = F_11 ( V_18 , struct V_19 , V_18 ) ;
if ( V_3 -> V_54 ) {
if ( V_20 -> V_55 )
V_20 -> error = V_3 -> V_54 ;
else if ( ! V_20 -> V_23 )
F_34 ( V_18 , F_29 , V_20 -> V_33 ) ;
else
F_34 ( V_18 , NULL , NULL ) ;
}
F_35 ( V_20 -> V_25 , V_3 , V_3 -> V_54 , L_2 ) ;
}
static void V_32 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_11 ( V_18 , struct V_19 , V_18 ) ;
struct V_3 * V_3 = V_20 -> V_3 , * V_52 ;
if ( F_36 ( F_24 ( V_3 ) , & V_20 -> V_25 -> V_56 ) < 0 ) {
F_37 ( V_20 -> V_25 ) ;
F_38 ( V_20 -> V_25 ) ;
}
if ( V_20 -> V_57 )
return F_22 ( V_18 ) ;
V_3 -> V_58 &= ~ ( V_59 | V_60 ) ;
do {
unsigned V_61 ;
struct V_5 * V_6 ;
struct V_62 * V_63 = V_20 -> V_25 -> V_64 ;
if ( F_18 ( & V_20 -> V_26 ,
3 + ( V_20 -> V_11 ? 1 : 0 ) ,
V_20 -> V_25 ) ) {
F_15 ( V_18 , F_10 , V_20 -> V_33 ) ;
return;
}
V_6 = V_20 -> V_26 . V_51 ;
F_39 ( V_6 ) ;
F_40 ( V_6 , V_20 -> V_47 ) ;
F_41 ( V_6 , V_3 -> V_41 . V_42 ) ;
if ( ! F_42 ( V_20 -> V_25 , V_6 , F_24 ( V_3 ) ,
V_20 -> V_65 , V_20 -> V_66 ,
V_20 -> V_55 ) )
goto V_67;
V_52 = F_43 ( V_3 , F_44 ( V_6 ) , V_68 , V_63 ) ;
V_52 -> V_69 = F_33 ;
V_52 -> V_53 = V_18 ;
if ( V_20 -> V_55 ) {
F_45 ( V_6 , true ) ;
for ( V_61 = 0 ; V_61 < F_9 ( V_6 ) ; V_61 ++ )
F_46 ( F_47 ( V_20 -> V_25 , V_6 , V_61 ) ,
V_70 ) ;
}
F_48 ( V_6 , V_20 -> V_11 ) ;
if ( F_49 ( V_6 ) )
F_4 ( V_52 , V_6 ) ;
F_50 ( V_6 ) ;
F_51 ( & V_20 -> V_26 ) ;
F_52 ( V_52 , V_71 , 0 ) ;
F_53 ( V_52 , V_20 -> V_25 , V_6 , 0 ) ;
} while ( V_52 != V_3 );
V_20 -> V_31 = true ;
F_15 ( V_18 , F_10 , V_20 -> V_33 ) ;
return;
V_67:
F_54 ( V_20 -> V_55 ) ;
if ( ! V_20 -> V_23 ) {
V_20 -> V_57 = true ;
return F_22 ( V_18 ) ;
} else {
V_20 -> V_31 = true ;
F_28 ( V_3 ) ;
if ( ! F_55 ( & V_20 -> V_26 ) )
F_15 ( V_18 , F_10 , V_20 -> V_33 ) ;
else
F_17 ( V_18 ) ;
}
}
void F_56 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_11 ( V_18 , struct V_19 , V_18 ) ;
F_57 ( V_20 -> V_25 , V_20 -> V_47 , V_20 -> V_3 ,
V_20 -> V_55 , V_20 -> V_57 ) ;
F_58 ( & V_20 -> V_26 ) ;
F_59 ( V_20 -> V_3 ) ;
V_32 ( V_18 ) ;
}
unsigned F_60 ( struct V_37 * V_25 )
{
int V_61 ;
long rand ;
if ( ! V_25 -> V_72 &&
! V_25 -> V_73 )
return 0 ;
V_61 = ( F_61 () - V_25 -> V_74 ) / 1024 ;
if ( V_61 < 0 )
return 0 ;
V_61 += F_62 ( & V_25 -> V_75 ) ;
if ( V_61 >= 0 )
return 0 ;
V_61 += V_76 ;
if ( V_61 > 0 )
V_61 = F_63 ( V_61 , 6 ) ;
rand = F_64 () ;
V_61 -= F_65 ( & rand , V_77 ) ;
return V_61 > 0 ? V_61 : 1 ;
}
static void F_66 ( struct V_78 * V_79 )
{
F_67 ( V_79 -> V_80 ,
V_79 -> V_81 , 8 , 0 ) ;
V_79 -> V_81 = 0 ;
}
static struct V_82 * F_68 ( struct V_1 * V_2 , T_1 V_6 )
{
return & V_2 -> V_83 [ F_69 ( V_6 , V_84 ) ] ;
}
static bool F_70 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_37 * V_25 = V_2 -> V_85 . V_25 ;
unsigned V_86 = F_1 ( V_2 , V_3 ) ;
unsigned V_43 , V_75 = F_60 ( V_25 ) ;
struct V_78 * V_87 = V_88 ;
struct V_89 * V_61 ;
if ( F_71 ( V_90 , & V_2 -> V_85 . V_91 ) ||
V_25 -> V_92 . V_93 > V_94 ||
( F_72 ( V_3 ) == V_95 ) )
goto V_96;
if ( V_86 == V_97 ||
( V_86 == V_98 &&
F_73 ( F_72 ( V_3 ) ) ) )
goto V_96;
if ( V_3 -> V_41 . V_42 & ( V_25 -> V_4 . V_99 - 1 ) ||
F_24 ( V_3 ) & ( V_25 -> V_4 . V_99 - 1 ) ) {
F_23 ( L_3 ) ;
goto V_96;
}
if ( F_74 ( V_2 ) ) {
if ( ( F_64 () & 3 ) == 3 )
goto V_96;
else
goto V_100;
}
if ( ! V_75 && ! V_2 -> V_101 )
goto V_100;
if ( ! V_75 &&
V_86 == V_102 &&
F_73 ( F_72 ( V_3 ) ) &&
( V_3 -> V_58 & V_103 ) )
goto V_100;
F_75 ( & V_2 -> V_104 ) ;
F_76 (i, iohash(dc, bio->bi_iter.bi_sector), hash)
if ( V_61 -> V_105 == V_3 -> V_41 . V_42 &&
F_77 ( V_106 , V_61 -> V_106 ) )
goto V_107;
V_61 = F_78 ( & V_2 -> V_108 , struct V_89 , V_109 ) ;
F_66 ( V_87 ) ;
V_61 -> V_110 = 0 ;
V_107:
if ( V_61 -> V_110 + V_3 -> V_41 . V_46 > V_61 -> V_110 )
V_61 -> V_110 += V_3 -> V_41 . V_46 ;
V_61 -> V_105 = F_79 ( V_3 ) ;
V_61 -> V_106 = V_106 + F_80 ( 5000 ) ;
V_87 -> V_81 = V_61 -> V_110 ;
F_81 ( & V_61 -> V_111 ) ;
F_82 ( & V_61 -> V_111 , F_68 ( V_2 , V_61 -> V_105 ) ) ;
F_83 ( & V_61 -> V_109 , & V_2 -> V_108 ) ;
F_84 ( & V_2 -> V_104 ) ;
V_43 = F_85 ( V_87 -> V_81 ,
V_87 -> V_80 ) >> 9 ;
if ( V_2 -> V_101 &&
V_43 >= V_2 -> V_101 >> 9 ) {
F_86 ( V_3 ) ;
goto V_96;
}
if ( V_75 && V_43 >= V_75 ) {
F_87 ( V_3 ) ;
goto V_96;
}
V_100:
F_88 ( V_25 , F_24 ( V_3 ) ) ;
return false ;
V_96:
F_89 ( V_25 , V_2 , F_24 ( V_3 ) ) ;
return true ;
}
static void F_90 ( struct V_3 * V_3 )
{
struct V_112 * V_113 = F_11 ( V_3 , struct V_112 , V_3 ) ;
struct V_17 * V_18 = V_3 -> V_53 ;
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
if ( V_3 -> V_54 )
V_115 -> V_116 . error = V_3 -> V_54 ;
else if ( ! F_91 ( & V_113 -> V_117 ) &&
F_92 ( V_115 -> V_116 . V_25 , & V_113 -> V_117 , 0 ) ) {
F_93 ( & V_115 -> V_116 . V_25 -> V_118 ) ;
V_115 -> V_116 . error = - V_119 ;
}
F_35 ( V_115 -> V_116 . V_25 , V_3 , V_3 -> V_54 , L_4 ) ;
}
static int F_94 ( struct V_120 * V_20 , struct V_121 * V_113 , struct V_5 * V_6 )
{
struct V_114 * V_115 = F_11 ( V_20 , struct V_114 , V_20 ) ;
struct V_3 * V_52 , * V_3 = & V_115 -> V_3 . V_3 ;
struct V_5 * V_122 ;
unsigned V_16 ;
if ( F_95 ( V_6 , & F_27 ( V_115 -> V_116 . V_47 , V_3 -> V_41 . V_42 , 0 ) ) <= 0 )
return V_123 ;
if ( F_96 ( V_6 ) != V_115 -> V_116 . V_47 ||
F_97 ( V_6 ) > V_3 -> V_41 . V_42 ) {
unsigned F_24 = F_24 ( V_3 ) ;
unsigned V_43 = F_96 ( V_6 ) == V_115 -> V_116 . V_47
? F_98 ( T_1 , V_124 ,
F_97 ( V_6 ) - V_3 -> V_41 . V_42 )
: V_124 ;
int V_24 = V_115 -> V_12 -> V_125 ( V_113 , V_115 , V_3 , V_43 ) ;
if ( V_24 != V_123 )
return V_24 ;
F_54 ( F_24 <= V_43 ) ;
}
if ( ! F_44 ( V_6 ) )
return V_123 ;
V_16 = 0 ;
F_47 ( V_113 -> V_25 , V_6 , V_16 ) -> V_126 = V_127 ;
if ( F_91 ( V_6 ) )
V_115 -> V_128 = true ;
V_52 = F_43 ( V_3 , F_98 ( T_1 , V_124 ,
F_99 ( V_6 ) - V_3 -> V_41 . V_42 ) ,
V_68 , V_115 -> V_12 -> V_64 ) ;
V_122 = & F_11 ( V_52 , struct V_112 , V_3 ) -> V_117 ;
F_100 ( V_122 , V_6 , V_16 ) ;
F_101 ( & F_27 ( V_115 -> V_116 . V_47 , V_52 -> V_41 . V_42 , 0 ) , V_122 ) ;
F_102 ( & F_27 ( V_115 -> V_116 . V_47 , F_79 ( V_52 ) , 0 ) , V_122 ) ;
V_52 -> V_69 = F_90 ;
V_52 -> V_53 = & V_115 -> V_18 ;
F_103 ( V_52 , V_113 -> V_25 ) ;
return V_52 == V_3 ? V_129 : V_123 ;
}
static void F_104 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_116 . V_18 ) ;
struct V_3 * V_3 = & V_115 -> V_3 . V_3 ;
int V_24 ;
F_105 ( & V_115 -> V_20 , - 1 ) ;
V_24 = F_106 ( & V_115 -> V_20 , V_115 -> V_116 . V_25 ,
& F_27 ( V_115 -> V_116 . V_47 , V_3 -> V_41 . V_42 , 0 ) ,
F_94 , V_130 ) ;
if ( V_24 == - V_131 ) {
F_15 ( V_18 , F_104 , V_132 ) ;
return;
}
F_17 ( V_18 ) ;
}
static void F_107 ( struct V_3 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_53 ;
if ( V_3 -> V_54 ) {
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
V_115 -> V_116 . error = V_3 -> V_54 ;
V_115 -> V_133 = false ;
}
F_28 ( V_3 ) ;
F_108 ( V_18 ) ;
}
static void F_109 ( struct V_114 * V_115 )
{
if ( V_115 -> V_134 ) {
F_110 ( F_111 ( V_115 -> V_134 ) ,
& V_115 -> V_12 -> V_85 -> V_135 , V_115 -> V_136 ) ;
F_112 ( V_115 -> V_12 , V_115 -> V_134 ) ;
V_115 -> V_134 -> V_54 = V_115 -> V_116 . error ;
F_113 ( V_115 -> V_134 ) ;
V_115 -> V_134 = NULL ;
}
}
static void F_114 ( struct V_114 * V_115 , struct V_3 * V_134 )
{
struct V_3 * V_3 = & V_115 -> V_3 . V_3 ;
F_115 ( V_3 ) ;
F_116 ( V_3 , V_134 ) ;
V_3 -> V_69 = F_107 ;
V_3 -> V_53 = & V_115 -> V_18 ;
F_117 ( V_3 , 3 ) ;
}
static void F_118 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
F_109 ( V_115 ) ;
if ( V_115 -> V_116 . V_3 )
F_28 ( V_115 -> V_116 . V_3 ) ;
F_119 ( V_18 ) ;
F_120 ( V_115 , V_115 -> V_12 -> V_25 -> V_114 ) ;
}
static inline struct V_114 * F_121 ( struct V_3 * V_3 ,
struct V_137 * V_12 )
{
struct V_114 * V_115 ;
V_115 = F_122 ( V_12 -> V_25 -> V_114 , V_68 ) ;
F_123 ( & V_115 -> V_18 , NULL ) ;
F_114 ( V_115 , V_3 ) ;
V_115 -> V_134 = V_3 ;
V_115 -> V_125 = NULL ;
V_115 -> V_12 = V_12 ;
V_115 -> V_133 = 1 ;
V_115 -> V_138 = F_73 ( F_72 ( V_3 ) ) ;
V_115 -> V_128 = 0 ;
V_115 -> V_136 = V_106 ;
V_115 -> V_116 . V_25 = V_12 -> V_25 ;
V_115 -> V_116 . V_3 = NULL ;
V_115 -> V_116 . V_47 = V_12 -> V_139 ;
V_115 -> V_116 . V_65 = F_124 ( ( unsigned long ) V_88 , 16 ) ;
V_115 -> V_116 . V_66 = 0 ;
V_115 -> V_116 . error = 0 ;
V_115 -> V_116 . V_91 = 0 ;
V_115 -> V_116 . V_27 = ( V_3 -> V_58 & ( V_59 | V_60 ) ) != 0 ;
V_115 -> V_116 . V_33 = V_132 ;
return V_115 ;
}
static void F_125 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
struct V_1 * V_2 = F_11 ( V_115 -> V_12 , struct V_1 , V_85 ) ;
F_118 ( V_18 ) ;
F_126 ( V_2 ) ;
}
static void F_127 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
if ( V_115 -> V_116 . V_29 )
F_128 ( V_115 -> V_116 . V_25 , V_115 -> V_12 ) ;
if ( V_115 -> V_116 . V_3 ) {
int V_61 ;
struct V_7 * V_8 ;
F_129 (bv, s->iop.bio, i)
F_130 ( V_8 -> V_13 ) ;
}
F_125 ( V_18 ) ;
}
static void F_131 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
struct V_3 * V_3 = & V_115 -> V_3 . V_3 ;
if ( V_115 -> V_133 ) {
F_132 ( V_115 -> V_134 ) ;
V_115 -> V_116 . error = 0 ;
F_114 ( V_115 , V_115 -> V_134 ) ;
F_133 ( V_3 , V_18 ) ;
}
F_15 ( V_18 , F_127 , NULL ) ;
}
static void F_134 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
struct V_1 * V_2 = F_11 ( V_115 -> V_12 , struct V_1 , V_85 ) ;
if ( V_115 -> V_116 . V_3 ) {
F_135 ( V_115 -> V_116 . V_3 ) ;
V_115 -> V_116 . V_3 -> V_41 . V_42 = V_115 -> V_125 -> V_41 . V_42 ;
V_115 -> V_116 . V_3 -> V_140 = V_115 -> V_125 -> V_140 ;
V_115 -> V_116 . V_3 -> V_41 . V_46 = V_115 -> V_141 << 9 ;
F_136 ( V_115 -> V_116 . V_3 , NULL ) ;
F_137 ( V_115 -> V_125 , V_115 -> V_116 . V_3 ) ;
F_28 ( V_115 -> V_125 ) ;
V_115 -> V_125 = NULL ;
}
if ( F_3 ( V_2 , & V_115 -> V_3 . V_3 ) && V_115 -> V_133 && ! V_115 -> V_128 )
F_138 ( V_2 , V_115 -> V_134 ) ;
F_109 ( V_115 ) ;
if ( V_115 -> V_116 . V_3 &&
! F_71 ( V_142 , & V_115 -> V_116 . V_25 -> V_91 ) ) {
F_54 ( ! V_115 -> V_116 . V_23 ) ;
F_139 ( & V_115 -> V_116 . V_18 , F_56 , NULL , V_18 ) ;
}
F_15 ( V_18 , F_127 , NULL ) ;
}
static void F_140 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
struct V_1 * V_2 = F_11 ( V_115 -> V_12 , struct V_1 , V_85 ) ;
F_141 ( V_115 -> V_116 . V_25 , V_115 -> V_12 ,
! V_115 -> V_125 , V_115 -> V_116 . V_57 ) ;
F_142 ( V_115 -> V_134 , ! V_115 -> V_125 , V_115 -> V_116 . V_57 ) ;
if ( V_115 -> V_116 . error )
F_143 ( V_18 , F_131 , V_132 ) ;
else if ( V_115 -> V_116 . V_3 || F_3 ( V_2 , & V_115 -> V_3 . V_3 ) )
F_143 ( V_18 , F_134 , V_132 ) ;
else
F_143 ( V_18 , F_125 , NULL ) ;
}
static int F_144 ( struct V_121 * V_113 , struct V_114 * V_115 ,
struct V_3 * V_3 , unsigned V_43 )
{
int V_24 = V_123 ;
unsigned V_143 = 0 ;
struct V_1 * V_2 = F_11 ( V_115 -> V_12 , struct V_1 , V_85 ) ;
struct V_3 * V_144 , * V_145 ;
if ( V_115 -> V_125 || V_115 -> V_116 . V_57 ) {
V_144 = F_43 ( V_3 , V_43 , V_68 , V_115 -> V_12 -> V_64 ) ;
V_24 = V_144 == V_3 ? V_129 : V_123 ;
goto V_146;
}
if ( ! ( V_3 -> V_58 & V_147 ) &&
! ( V_3 -> V_58 & V_148 ) &&
V_115 -> V_116 . V_25 -> V_92 . V_93 < V_149 )
V_143 = F_98 ( V_150 , V_2 -> V_151 >> 9 ,
F_145 ( V_3 -> V_140 ) - F_79 ( V_3 ) ) ;
V_115 -> V_141 = F_25 ( V_43 , F_24 ( V_3 ) + V_143 ) ;
V_115 -> V_116 . V_22 = F_27 ( V_115 -> V_116 . V_47 ,
V_3 -> V_41 . V_42 + V_115 -> V_141 ,
V_115 -> V_141 ) ;
V_24 = F_146 ( V_113 , & V_115 -> V_20 , & V_115 -> V_116 . V_22 ) ;
if ( V_24 )
return V_24 ;
V_115 -> V_116 . V_23 = true ;
V_144 = F_43 ( V_3 , V_43 , V_68 , V_115 -> V_12 -> V_64 ) ;
V_24 = V_144 == V_3 ? V_129 : - V_119 ;
V_145 = F_147 ( V_152 ,
F_148 ( V_115 -> V_141 , V_153 ) ,
V_2 -> V_85 . V_64 ) ;
if ( ! V_145 )
goto V_146;
V_145 -> V_41 . V_42 = V_144 -> V_41 . V_42 ;
V_145 -> V_140 = V_144 -> V_140 ;
V_145 -> V_41 . V_46 = V_115 -> V_141 << 9 ;
V_145 -> V_69 = F_107 ;
V_145 -> V_53 = & V_115 -> V_18 ;
F_136 ( V_145 , NULL ) ;
if ( F_149 ( V_145 , V_154 | V_68 ) )
goto V_155;
if ( V_143 )
F_150 ( V_115 -> V_116 . V_25 , V_115 -> V_12 ) ;
V_115 -> V_125 = V_144 ;
V_115 -> V_116 . V_3 = V_145 ;
F_59 ( V_145 ) ;
F_133 ( V_145 , & V_115 -> V_18 ) ;
return V_24 ;
V_155:
F_28 ( V_145 ) ;
V_146:
V_144 -> V_69 = F_107 ;
V_144 -> V_53 = & V_115 -> V_18 ;
F_133 ( V_144 , & V_115 -> V_18 ) ;
return V_24 ;
}
static void F_151 ( struct V_1 * V_2 , struct V_114 * V_115 )
{
struct V_17 * V_18 = & V_115 -> V_18 ;
F_139 ( & V_115 -> V_116 . V_18 , F_104 , NULL , V_18 ) ;
F_15 ( V_18 , F_140 , NULL ) ;
}
static void F_152 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
struct V_1 * V_2 = F_11 ( V_115 -> V_12 , struct V_1 , V_85 ) ;
F_153 ( & V_2 -> V_156 ) ;
F_125 ( V_18 ) ;
}
static void F_154 ( struct V_1 * V_2 , struct V_114 * V_115 )
{
struct V_17 * V_18 = & V_115 -> V_18 ;
struct V_3 * V_3 = & V_115 -> V_3 . V_3 ;
struct V_5 V_157 = F_27 ( V_2 -> V_85 . V_139 , V_3 -> V_41 . V_42 , 0 ) ;
struct V_5 V_158 = F_27 ( V_2 -> V_85 . V_139 , F_79 ( V_3 ) , 0 ) ;
F_155 ( & V_115 -> V_116 . V_25 -> V_159 , & V_157 , & V_158 ) ;
F_156 ( & V_2 -> V_156 ) ;
if ( F_155 ( & V_2 -> V_160 , & V_157 , & V_158 ) ) {
V_115 -> V_116 . V_57 = false ;
V_115 -> V_116 . V_55 = true ;
}
if ( F_72 ( V_3 ) == V_95 )
V_115 -> V_116 . V_57 = true ;
if ( F_157 ( V_2 , V_115 -> V_134 ,
F_1 ( V_2 , V_3 ) ,
V_115 -> V_116 . V_57 ) ) {
V_115 -> V_116 . V_57 = false ;
V_115 -> V_116 . V_55 = true ;
}
if ( V_115 -> V_116 . V_57 ) {
V_115 -> V_116 . V_3 = V_115 -> V_134 ;
F_59 ( V_115 -> V_116 . V_3 ) ;
if ( ( F_72 ( V_3 ) != V_95 ) ||
F_158 ( F_159 ( V_2 -> V_161 ) ) )
F_133 ( V_3 , V_18 ) ;
} else if ( V_115 -> V_116 . V_55 ) {
F_160 ( V_2 ) ;
V_115 -> V_116 . V_3 = V_3 ;
if ( V_3 -> V_58 & V_59 ) {
struct V_3 * V_162 = F_147 ( V_68 , 0 ,
V_2 -> V_85 . V_64 ) ;
V_162 -> V_140 = V_3 -> V_140 ;
V_162 -> V_69 = F_107 ;
V_162 -> V_53 = V_18 ;
F_52 ( V_162 , V_71 , V_163 ) ;
F_133 ( V_162 , V_18 ) ;
}
} else {
V_115 -> V_116 . V_3 = F_161 ( V_3 , V_68 , V_2 -> V_85 . V_64 ) ;
F_133 ( V_3 , V_18 ) ;
}
F_139 ( & V_115 -> V_116 . V_18 , F_56 , NULL , V_18 ) ;
F_15 ( V_18 , F_152 , NULL ) ;
}
static void F_162 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
struct V_3 * V_3 = & V_115 -> V_3 . V_3 ;
if ( V_115 -> V_116 . V_27 )
F_163 ( V_115 -> V_116 . V_25 , V_18 ) ;
F_133 ( V_3 , V_18 ) ;
F_15 ( V_18 , F_125 , NULL ) ;
}
static T_4 F_164 ( struct V_164 * V_165 ,
struct V_3 * V_3 )
{
struct V_114 * V_115 ;
struct V_137 * V_12 = V_3 -> V_140 -> V_166 -> V_167 ;
struct V_1 * V_2 = F_11 ( V_12 , struct V_1 , V_85 ) ;
int V_168 = F_111 ( V_3 ) ;
F_165 ( V_168 , F_24 ( V_3 ) , & V_12 -> V_85 -> V_135 ) ;
V_3 -> V_140 = V_2 -> V_161 ;
V_3 -> V_41 . V_42 += V_2 -> V_4 . V_169 ;
if ( F_166 ( V_2 ) ) {
V_115 = F_121 ( V_3 , V_12 ) ;
F_167 ( V_115 -> V_12 , V_3 ) ;
if ( ! V_3 -> V_41 . V_46 ) {
F_143 ( & V_115 -> V_18 ,
F_162 ,
V_132 ) ;
} else {
V_115 -> V_116 . V_57 = F_70 ( V_2 , V_3 ) ;
if ( V_168 )
F_154 ( V_2 , V_115 ) ;
else
F_151 ( V_2 , V_115 ) ;
}
} else {
if ( ( F_72 ( V_3 ) == V_95 ) &&
! F_158 ( F_159 ( V_2 -> V_161 ) ) )
F_113 ( V_3 ) ;
else
F_168 ( V_3 ) ;
}
return V_170 ;
}
static int F_169 ( struct V_137 * V_12 , T_5 V_86 ,
unsigned int V_171 , unsigned long V_172 )
{
struct V_1 * V_2 = F_11 ( V_12 , struct V_1 , V_85 ) ;
return F_170 ( V_2 -> V_161 , V_86 , V_171 , V_172 ) ;
}
static int F_171 ( void * V_173 , int V_174 )
{
struct V_137 * V_12 = V_173 ;
struct V_1 * V_2 = F_11 ( V_12 , struct V_1 , V_85 ) ;
struct V_164 * V_165 = F_159 ( V_2 -> V_161 ) ;
int V_24 = 0 ;
if ( F_172 ( & V_165 -> V_175 , V_174 ) )
return 1 ;
if ( F_166 ( V_2 ) ) {
unsigned V_61 ;
struct V_176 * V_177 ;
F_173 (ca, d->c, i) {
V_165 = F_159 ( V_177 -> V_161 ) ;
V_24 |= F_172 ( & V_165 -> V_175 , V_174 ) ;
}
F_126 ( V_2 ) ;
}
return V_24 ;
}
void F_174 ( struct V_1 * V_2 )
{
struct V_178 * V_179 = V_2 -> V_85 . V_85 ;
V_179 -> V_180 -> V_181 = F_164 ;
V_179 -> V_180 -> V_175 . V_182 = F_171 ;
V_2 -> V_85 . V_125 = F_144 ;
V_2 -> V_85 . V_183 = F_169 ;
}
static int F_175 ( struct V_121 * V_113 , struct V_114 * V_115 ,
struct V_3 * V_3 , unsigned V_43 )
{
unsigned V_184 = F_25 ( V_43 , F_24 ( V_3 ) ) << 9 ;
F_176 ( V_3 -> V_41 . V_46 , V_184 ) ;
F_177 ( V_3 ) ;
F_176 ( V_3 -> V_41 . V_46 , V_184 ) ;
F_178 ( V_3 , V_184 ) ;
if ( ! V_3 -> V_41 . V_46 )
return V_129 ;
return V_123 ;
}
static void F_179 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
if ( V_115 -> V_116 . V_27 )
F_163 ( V_115 -> V_116 . V_25 , V_18 ) ;
F_15 ( V_18 , F_118 , NULL ) ;
}
static T_4 F_180 ( struct V_164 * V_165 ,
struct V_3 * V_3 )
{
struct V_114 * V_115 ;
struct V_17 * V_18 ;
struct V_137 * V_12 = V_3 -> V_140 -> V_166 -> V_167 ;
int V_168 = F_111 ( V_3 ) ;
F_165 ( V_168 , F_24 ( V_3 ) , & V_12 -> V_85 -> V_135 ) ;
V_115 = F_121 ( V_3 , V_12 ) ;
V_18 = & V_115 -> V_18 ;
V_3 = & V_115 -> V_3 . V_3 ;
F_167 ( V_115 -> V_12 , V_3 ) ;
if ( ! V_3 -> V_41 . V_46 ) {
F_143 ( & V_115 -> V_18 ,
F_179 ,
V_132 ) ;
return V_170 ;
} else if ( V_168 ) {
F_155 ( & V_115 -> V_116 . V_25 -> V_159 ,
& F_27 ( V_12 -> V_139 , V_3 -> V_41 . V_42 , 0 ) ,
& F_27 ( V_12 -> V_139 , F_79 ( V_3 ) , 0 ) ) ;
V_115 -> V_116 . V_57 = ( F_72 ( V_3 ) == V_95 ) != 0 ;
V_115 -> V_116 . V_55 = true ;
V_115 -> V_116 . V_3 = V_3 ;
F_139 ( & V_115 -> V_116 . V_18 , F_56 , NULL , V_18 ) ;
} else {
F_139 ( & V_115 -> V_116 . V_18 , F_104 , NULL , V_18 ) ;
}
F_15 ( V_18 , F_118 , NULL ) ;
return V_170 ;
}
static int F_181 ( struct V_137 * V_12 , T_5 V_86 ,
unsigned int V_171 , unsigned long V_172 )
{
return - V_185 ;
}
static int F_182 ( void * V_173 , int V_174 )
{
struct V_137 * V_12 = V_173 ;
struct V_164 * V_165 ;
struct V_176 * V_177 ;
unsigned V_61 ;
int V_24 = 0 ;
F_173 (ca, d->c, i) {
V_165 = F_159 ( V_177 -> V_161 ) ;
V_24 |= F_172 ( & V_165 -> V_175 , V_174 ) ;
}
return V_24 ;
}
void F_183 ( struct V_137 * V_12 )
{
struct V_178 * V_179 = V_12 -> V_85 ;
V_179 -> V_180 -> V_181 = F_180 ;
V_179 -> V_180 -> V_175 . V_182 = F_182 ;
V_12 -> V_125 = F_175 ;
V_12 -> V_183 = F_181 ;
}
void F_184 ( void )
{
if ( V_186 )
F_185 ( V_186 ) ;
}
int T_6 F_186 ( void )
{
V_186 = F_187 ( V_114 , 0 ) ;
if ( ! V_186 )
return - V_30 ;
return 0 ;
}
