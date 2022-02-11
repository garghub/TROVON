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
if ( V_20 -> V_58 )
return F_22 ( V_18 ) ;
if ( F_36 ( F_24 ( V_3 ) , & V_20 -> V_25 -> V_59 ) < 0 )
F_37 ( V_20 -> V_25 ) ;
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
V_20 -> V_58 = true ;
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
V_20 -> V_57 , V_20 -> V_58 ) ;
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
F_74 ( & V_2 -> V_104 ) ;
F_75 (i, iohash(dc, bio->bi_iter.bi_sector), hash)
if ( V_63 -> V_105 == V_3 -> V_43 . V_44 &&
F_76 ( V_106 , V_63 -> V_106 ) )
goto V_107;
V_63 = F_77 ( & V_2 -> V_108 , struct V_91 , V_109 ) ;
F_65 ( V_89 ) ;
V_63 -> V_110 = 0 ;
V_107:
if ( V_63 -> V_110 + V_3 -> V_43 . V_48 > V_63 -> V_110 )
V_63 -> V_110 += V_3 -> V_43 . V_48 ;
V_63 -> V_105 = F_78 ( V_3 ) ;
V_63 -> V_106 = V_106 + F_79 ( 5000 ) ;
V_89 -> V_83 = V_63 -> V_110 ;
F_80 ( & V_63 -> V_111 ) ;
F_81 ( & V_63 -> V_111 , F_67 ( V_2 , V_63 -> V_105 ) ) ;
F_82 ( & V_63 -> V_109 , & V_2 -> V_108 ) ;
F_83 ( & V_2 -> V_104 ) ;
V_45 = F_84 ( V_89 -> V_83 ,
V_89 -> V_82 ) >> 9 ;
if ( V_2 -> V_103 &&
V_45 >= V_2 -> V_103 >> 9 ) {
F_85 ( V_3 ) ;
goto V_98;
}
if ( V_77 && V_45 >= V_77 ) {
F_86 ( V_3 ) ;
goto V_98;
}
V_102:
F_87 ( V_25 , F_24 ( V_3 ) ) ;
return false ;
V_98:
F_88 ( V_25 , V_2 , F_24 ( V_3 ) ) ;
return true ;
}
static void F_89 ( struct V_3 * V_3 )
{
struct V_112 * V_113 = F_11 ( V_3 , struct V_112 , V_3 ) ;
struct V_17 * V_18 = V_3 -> V_55 ;
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
if ( V_3 -> V_56 )
V_115 -> V_116 . V_30 = V_3 -> V_56 ;
else if ( ! F_90 ( & V_113 -> V_117 ) &&
F_91 ( V_115 -> V_116 . V_25 , & V_113 -> V_117 , 0 ) ) {
F_92 ( & V_115 -> V_116 . V_25 -> V_118 ) ;
V_115 -> V_116 . V_30 = V_119 ;
}
F_35 ( V_115 -> V_116 . V_25 , V_3 , V_3 -> V_56 , L_4 ) ;
}
static int F_93 ( struct V_120 * V_20 , struct V_121 * V_113 , struct V_5 * V_6 )
{
struct V_114 * V_115 = F_11 ( V_20 , struct V_114 , V_20 ) ;
struct V_3 * V_54 , * V_3 = & V_115 -> V_3 . V_3 ;
struct V_5 * V_122 ;
unsigned V_16 ;
if ( F_94 ( V_6 , & F_27 ( V_115 -> V_116 . V_49 , V_3 -> V_43 . V_44 , 0 ) ) <= 0 )
return V_123 ;
if ( F_95 ( V_6 ) != V_115 -> V_116 . V_49 ||
F_96 ( V_6 ) > V_3 -> V_43 . V_44 ) {
unsigned F_24 = F_24 ( V_3 ) ;
unsigned V_45 = F_95 ( V_6 ) == V_115 -> V_116 . V_49
? F_97 ( T_1 , V_124 ,
F_96 ( V_6 ) - V_3 -> V_43 . V_44 )
: V_124 ;
int V_24 = V_115 -> V_12 -> V_125 ( V_113 , V_115 , V_3 , V_45 ) ;
if ( V_24 != V_123 )
return V_24 ;
F_53 ( F_24 <= V_45 ) ;
}
if ( ! F_43 ( V_6 ) )
return V_123 ;
V_16 = 0 ;
F_46 ( V_113 -> V_25 , V_6 , V_16 ) -> V_126 = V_127 ;
if ( F_90 ( V_6 ) )
V_115 -> V_128 = true ;
V_54 = F_42 ( V_3 , F_97 ( T_1 , V_124 ,
F_98 ( V_6 ) - V_3 -> V_43 . V_44 ) ,
V_70 , V_115 -> V_12 -> V_66 ) ;
V_122 = & F_11 ( V_54 , struct V_112 , V_3 ) -> V_117 ;
F_99 ( V_122 , V_6 , V_16 ) ;
F_100 ( & F_27 ( V_115 -> V_116 . V_49 , V_54 -> V_43 . V_44 , 0 ) , V_122 ) ;
F_101 ( & F_27 ( V_115 -> V_116 . V_49 , F_78 ( V_54 ) , 0 ) , V_122 ) ;
V_54 -> V_71 = F_89 ;
V_54 -> V_55 = & V_115 -> V_18 ;
F_102 ( V_54 , V_113 -> V_25 ) ;
return V_54 == V_3 ? V_129 : V_123 ;
}
static void F_103 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_116 . V_18 ) ;
struct V_3 * V_3 = & V_115 -> V_3 . V_3 ;
int V_24 ;
F_104 ( & V_115 -> V_20 , - 1 ) ;
V_24 = F_105 ( & V_115 -> V_20 , V_115 -> V_116 . V_25 ,
& F_27 ( V_115 -> V_116 . V_49 , V_3 -> V_43 . V_44 , 0 ) ,
F_93 , V_130 ) ;
if ( V_24 == - V_131 ) {
F_15 ( V_18 , F_103 , V_132 ) ;
return;
}
F_17 ( V_18 ) ;
}
static void F_106 ( struct V_3 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_55 ;
if ( V_3 -> V_56 ) {
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
V_115 -> V_116 . V_30 = V_3 -> V_56 ;
V_115 -> V_133 = false ;
}
F_28 ( V_3 ) ;
F_107 ( V_18 ) ;
}
static void F_108 ( struct V_114 * V_115 )
{
if ( V_115 -> V_134 ) {
struct V_135 * V_136 = V_115 -> V_134 -> V_137 -> V_138 ;
F_109 ( V_136 , F_110 ( V_115 -> V_134 ) ,
& V_115 -> V_12 -> V_87 -> V_139 , V_115 -> V_140 ) ;
F_111 ( V_115 -> V_12 , V_115 -> V_134 ) ;
V_115 -> V_134 -> V_56 = V_115 -> V_116 . V_30 ;
F_112 ( V_115 -> V_134 ) ;
V_115 -> V_134 = NULL ;
}
}
static void F_113 ( struct V_114 * V_115 , struct V_3 * V_134 )
{
struct V_3 * V_3 = & V_115 -> V_3 . V_3 ;
F_114 ( V_3 , NULL , 0 ) ;
F_115 ( V_3 , V_134 ) ;
V_3 -> V_71 = F_106 ;
V_3 -> V_55 = & V_115 -> V_18 ;
F_116 ( V_3 , 3 ) ;
}
static void F_117 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
F_108 ( V_115 ) ;
if ( V_115 -> V_116 . V_3 )
F_28 ( V_115 -> V_116 . V_3 ) ;
F_118 ( V_18 ) ;
F_119 ( V_115 , V_115 -> V_12 -> V_25 -> V_114 ) ;
}
static inline struct V_114 * F_120 ( struct V_3 * V_3 ,
struct V_141 * V_12 )
{
struct V_114 * V_115 ;
V_115 = F_121 ( V_12 -> V_25 -> V_114 , V_70 ) ;
F_122 ( & V_115 -> V_18 , NULL ) ;
F_113 ( V_115 , V_3 ) ;
V_115 -> V_134 = V_3 ;
V_115 -> V_125 = NULL ;
V_115 -> V_12 = V_12 ;
V_115 -> V_133 = 1 ;
V_115 -> V_142 = F_72 ( F_71 ( V_3 ) ) ;
V_115 -> V_128 = 0 ;
V_115 -> V_140 = V_106 ;
V_115 -> V_116 . V_25 = V_12 -> V_25 ;
V_115 -> V_116 . V_3 = NULL ;
V_115 -> V_116 . V_49 = V_12 -> V_143 ;
V_115 -> V_116 . V_67 = F_123 ( ( unsigned long ) V_90 , 16 ) ;
V_115 -> V_116 . V_68 = 0 ;
V_115 -> V_116 . V_30 = 0 ;
V_115 -> V_116 . V_93 = 0 ;
V_115 -> V_116 . V_27 = F_124 ( V_3 -> V_60 ) ;
V_115 -> V_116 . V_34 = V_132 ;
return V_115 ;
}
static void F_125 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
struct V_1 * V_2 = F_11 ( V_115 -> V_12 , struct V_1 , V_87 ) ;
F_117 ( V_18 ) ;
F_126 ( V_2 ) ;
}
static void F_127 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
if ( V_115 -> V_116 . V_29 )
F_128 ( V_115 -> V_116 . V_25 , V_115 -> V_12 ) ;
if ( V_115 -> V_116 . V_3 )
F_129 ( V_115 -> V_116 . V_3 ) ;
F_125 ( V_18 ) ;
}
static void F_130 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
struct V_3 * V_3 = & V_115 -> V_3 . V_3 ;
if ( V_115 -> V_133 ) {
F_131 ( V_115 -> V_134 ) ;
V_115 -> V_116 . V_30 = 0 ;
F_113 ( V_115 , V_115 -> V_134 ) ;
F_132 ( V_3 , V_18 ) ;
}
F_15 ( V_18 , F_127 , NULL ) ;
}
static void F_133 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
struct V_1 * V_2 = F_11 ( V_115 -> V_12 , struct V_1 , V_87 ) ;
if ( V_115 -> V_116 . V_3 ) {
F_134 ( V_115 -> V_116 . V_3 ) ;
V_115 -> V_116 . V_3 -> V_43 . V_44 = V_115 -> V_125 -> V_43 . V_44 ;
F_135 ( V_115 -> V_116 . V_3 , V_115 -> V_125 ) ;
V_115 -> V_116 . V_3 -> V_43 . V_48 = V_115 -> V_144 << 9 ;
F_136 ( V_115 -> V_116 . V_3 , NULL ) ;
F_137 ( V_115 -> V_125 , V_115 -> V_116 . V_3 ) ;
F_28 ( V_115 -> V_125 ) ;
V_115 -> V_125 = NULL ;
}
if ( F_3 ( V_2 , & V_115 -> V_3 . V_3 ) && V_115 -> V_133 && ! V_115 -> V_128 )
F_138 ( V_2 , V_115 -> V_134 ) ;
F_108 ( V_115 ) ;
if ( V_115 -> V_116 . V_3 &&
! F_70 ( V_145 , & V_115 -> V_116 . V_25 -> V_93 ) ) {
F_53 ( ! V_115 -> V_116 . V_23 ) ;
F_139 ( & V_115 -> V_116 . V_18 , F_55 , NULL , V_18 ) ;
}
F_15 ( V_18 , F_127 , NULL ) ;
}
static void F_140 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
struct V_1 * V_2 = F_11 ( V_115 -> V_12 , struct V_1 , V_87 ) ;
F_141 ( V_115 -> V_116 . V_25 , V_115 -> V_12 ,
! V_115 -> V_125 , V_115 -> V_116 . V_58 ) ;
F_142 ( V_115 -> V_134 , ! V_115 -> V_125 , V_115 -> V_116 . V_58 ) ;
if ( V_115 -> V_116 . V_30 )
F_143 ( V_18 , F_130 , V_132 ) ;
else if ( V_115 -> V_116 . V_3 || F_3 ( V_2 , & V_115 -> V_3 . V_3 ) )
F_143 ( V_18 , F_133 , V_132 ) ;
else
F_143 ( V_18 , F_125 , NULL ) ;
}
static int F_144 ( struct V_121 * V_113 , struct V_114 * V_115 ,
struct V_3 * V_3 , unsigned V_45 )
{
int V_24 = V_123 ;
unsigned V_146 = 0 ;
struct V_1 * V_2 = F_11 ( V_115 -> V_12 , struct V_1 , V_87 ) ;
struct V_3 * V_147 , * V_148 ;
if ( V_115 -> V_125 || V_115 -> V_116 . V_58 ) {
V_147 = F_42 ( V_3 , V_45 , V_70 , V_115 -> V_12 -> V_66 ) ;
V_24 = V_147 == V_3 ? V_129 : V_123 ;
goto V_149;
}
if ( ! ( V_3 -> V_60 & V_150 ) &&
! ( V_3 -> V_60 & V_151 ) &&
V_115 -> V_116 . V_25 -> V_94 . V_95 < V_152 )
V_146 = F_97 ( V_153 , V_2 -> V_154 >> 9 ,
F_145 ( V_3 -> V_137 ) - F_78 ( V_3 ) ) ;
V_115 -> V_144 = F_25 ( V_45 , F_24 ( V_3 ) + V_146 ) ;
V_115 -> V_116 . V_22 = F_27 ( V_115 -> V_116 . V_49 ,
V_3 -> V_43 . V_44 + V_115 -> V_144 ,
V_115 -> V_144 ) ;
V_24 = F_146 ( V_113 , & V_115 -> V_20 , & V_115 -> V_116 . V_22 ) ;
if ( V_24 )
return V_24 ;
V_115 -> V_116 . V_23 = true ;
V_147 = F_42 ( V_3 , V_45 , V_70 , V_115 -> V_12 -> V_66 ) ;
V_24 = V_147 == V_3 ? V_129 : - V_155 ;
V_148 = F_147 ( V_156 ,
F_148 ( V_115 -> V_144 , V_157 ) ,
V_2 -> V_87 . V_66 ) ;
if ( ! V_148 )
goto V_149;
V_148 -> V_43 . V_44 = V_147 -> V_43 . V_44 ;
F_135 ( V_148 , V_147 ) ;
V_148 -> V_43 . V_48 = V_115 -> V_144 << 9 ;
V_148 -> V_71 = F_106 ;
V_148 -> V_55 = & V_115 -> V_18 ;
F_136 ( V_148 , NULL ) ;
if ( F_149 ( V_148 , V_158 | V_70 ) )
goto V_159;
if ( V_146 )
F_150 ( V_115 -> V_116 . V_25 , V_115 -> V_12 ) ;
V_115 -> V_125 = V_147 ;
V_115 -> V_116 . V_3 = V_148 ;
F_58 ( V_148 ) ;
F_132 ( V_148 , & V_115 -> V_18 ) ;
return V_24 ;
V_159:
F_28 ( V_148 ) ;
V_149:
V_147 -> V_71 = F_106 ;
V_147 -> V_55 = & V_115 -> V_18 ;
F_132 ( V_147 , & V_115 -> V_18 ) ;
return V_24 ;
}
static void F_151 ( struct V_1 * V_2 , struct V_114 * V_115 )
{
struct V_17 * V_18 = & V_115 -> V_18 ;
F_139 ( & V_115 -> V_116 . V_18 , F_103 , NULL , V_18 ) ;
F_15 ( V_18 , F_140 , NULL ) ;
}
static void F_152 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
struct V_1 * V_2 = F_11 ( V_115 -> V_12 , struct V_1 , V_87 ) ;
F_153 ( & V_2 -> V_160 ) ;
F_125 ( V_18 ) ;
}
static void F_154 ( struct V_1 * V_2 , struct V_114 * V_115 )
{
struct V_17 * V_18 = & V_115 -> V_18 ;
struct V_3 * V_3 = & V_115 -> V_3 . V_3 ;
struct V_5 V_161 = F_27 ( V_2 -> V_87 . V_143 , V_3 -> V_43 . V_44 , 0 ) ;
struct V_5 V_162 = F_27 ( V_2 -> V_87 . V_143 , F_78 ( V_3 ) , 0 ) ;
F_155 ( & V_115 -> V_116 . V_25 -> V_163 , & V_161 , & V_162 ) ;
F_156 ( & V_2 -> V_160 ) ;
if ( F_155 ( & V_2 -> V_164 , & V_161 , & V_162 ) ) {
V_115 -> V_116 . V_58 = false ;
V_115 -> V_116 . V_57 = true ;
}
if ( F_71 ( V_3 ) == V_97 )
V_115 -> V_116 . V_58 = true ;
if ( F_157 ( V_2 , V_115 -> V_134 ,
F_1 ( V_2 , V_3 ) ,
V_115 -> V_116 . V_58 ) ) {
V_115 -> V_116 . V_58 = false ;
V_115 -> V_116 . V_57 = true ;
}
if ( V_115 -> V_116 . V_58 ) {
V_115 -> V_116 . V_3 = V_115 -> V_134 ;
F_58 ( V_115 -> V_116 . V_3 ) ;
if ( ( F_71 ( V_3 ) != V_97 ) ||
F_158 ( F_159 ( V_2 -> V_165 ) ) )
F_132 ( V_3 , V_18 ) ;
} else if ( V_115 -> V_116 . V_57 ) {
F_160 ( V_2 ) ;
V_115 -> V_116 . V_3 = V_3 ;
if ( V_3 -> V_60 & V_61 ) {
struct V_3 * V_166 = F_147 ( V_70 , 0 ,
V_2 -> V_87 . V_66 ) ;
F_135 ( V_166 , V_3 ) ;
V_166 -> V_71 = F_106 ;
V_166 -> V_55 = V_18 ;
V_166 -> V_60 = V_73 | V_61 ;
F_132 ( V_166 , V_18 ) ;
}
} else {
V_115 -> V_116 . V_3 = F_161 ( V_3 , V_70 , V_2 -> V_87 . V_66 ) ;
F_132 ( V_3 , V_18 ) ;
}
F_139 ( & V_115 -> V_116 . V_18 , F_55 , NULL , V_18 ) ;
F_15 ( V_18 , F_152 , NULL ) ;
}
static void F_162 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
struct V_3 * V_3 = & V_115 -> V_3 . V_3 ;
if ( V_115 -> V_116 . V_27 )
F_163 ( V_115 -> V_116 . V_25 , V_18 ) ;
F_132 ( V_3 , V_18 ) ;
F_15 ( V_18 , F_125 , NULL ) ;
}
static T_4 F_164 ( struct V_135 * V_136 ,
struct V_3 * V_3 )
{
struct V_114 * V_115 ;
struct V_141 * V_12 = V_3 -> V_137 -> V_167 ;
struct V_1 * V_2 = F_11 ( V_12 , struct V_1 , V_87 ) ;
int V_168 = F_110 ( V_3 ) ;
F_165 ( V_136 , V_168 , F_24 ( V_3 ) , & V_12 -> V_87 -> V_139 ) ;
F_166 ( V_3 , V_2 -> V_165 ) ;
V_3 -> V_43 . V_44 += V_2 -> V_4 . V_169 ;
if ( F_167 ( V_2 ) ) {
V_115 = F_120 ( V_3 , V_12 ) ;
F_168 ( V_115 -> V_12 , V_3 ) ;
if ( ! V_3 -> V_43 . V_48 ) {
F_143 ( & V_115 -> V_18 ,
F_162 ,
V_132 ) ;
} else {
V_115 -> V_116 . V_58 = F_69 ( V_2 , V_3 ) ;
if ( V_168 )
F_154 ( V_2 , V_115 ) ;
else
F_151 ( V_2 , V_115 ) ;
}
} else {
if ( ( F_71 ( V_3 ) == V_97 ) &&
! F_158 ( F_159 ( V_2 -> V_165 ) ) )
F_112 ( V_3 ) ;
else
F_169 ( V_3 ) ;
}
return V_170 ;
}
static int F_170 ( struct V_141 * V_12 , T_5 V_88 ,
unsigned int V_171 , unsigned long V_172 )
{
struct V_1 * V_2 = F_11 ( V_12 , struct V_1 , V_87 ) ;
return F_171 ( V_2 -> V_165 , V_88 , V_171 , V_172 ) ;
}
static int F_172 ( void * V_173 , int V_174 )
{
struct V_141 * V_12 = V_173 ;
struct V_1 * V_2 = F_11 ( V_12 , struct V_1 , V_87 ) ;
struct V_135 * V_136 = F_159 ( V_2 -> V_165 ) ;
int V_24 = 0 ;
if ( F_173 ( V_136 -> V_175 , V_174 ) )
return 1 ;
if ( F_167 ( V_2 ) ) {
unsigned V_63 ;
struct V_176 * V_177 ;
F_174 (ca, d->c, i) {
V_136 = F_159 ( V_177 -> V_165 ) ;
V_24 |= F_173 ( V_136 -> V_175 , V_174 ) ;
}
F_126 ( V_2 ) ;
}
return V_24 ;
}
void F_175 ( struct V_1 * V_2 )
{
struct V_178 * V_179 = V_2 -> V_87 . V_87 ;
V_179 -> V_138 -> V_180 = F_164 ;
V_179 -> V_138 -> V_175 -> V_181 = F_172 ;
V_2 -> V_87 . V_125 = F_144 ;
V_2 -> V_87 . V_182 = F_170 ;
}
static int F_176 ( struct V_121 * V_113 , struct V_114 * V_115 ,
struct V_3 * V_3 , unsigned V_45 )
{
unsigned V_183 = F_25 ( V_45 , F_24 ( V_3 ) ) << 9 ;
F_177 ( V_3 -> V_43 . V_48 , V_183 ) ;
F_178 ( V_3 ) ;
F_177 ( V_3 -> V_43 . V_48 , V_183 ) ;
F_179 ( V_3 , V_183 ) ;
if ( ! V_3 -> V_43 . V_48 )
return V_129 ;
return V_123 ;
}
static void F_180 ( struct V_17 * V_18 )
{
struct V_114 * V_115 = F_11 ( V_18 , struct V_114 , V_18 ) ;
if ( V_115 -> V_116 . V_27 )
F_163 ( V_115 -> V_116 . V_25 , V_18 ) ;
F_15 ( V_18 , F_117 , NULL ) ;
}
static T_4 F_181 ( struct V_135 * V_136 ,
struct V_3 * V_3 )
{
struct V_114 * V_115 ;
struct V_17 * V_18 ;
struct V_141 * V_12 = V_3 -> V_137 -> V_167 ;
int V_168 = F_110 ( V_3 ) ;
F_165 ( V_136 , V_168 , F_24 ( V_3 ) , & V_12 -> V_87 -> V_139 ) ;
V_115 = F_120 ( V_3 , V_12 ) ;
V_18 = & V_115 -> V_18 ;
V_3 = & V_115 -> V_3 . V_3 ;
F_168 ( V_115 -> V_12 , V_3 ) ;
if ( ! V_3 -> V_43 . V_48 ) {
F_143 ( & V_115 -> V_18 ,
F_180 ,
V_132 ) ;
return V_170 ;
} else if ( V_168 ) {
F_155 ( & V_115 -> V_116 . V_25 -> V_163 ,
& F_27 ( V_12 -> V_143 , V_3 -> V_43 . V_44 , 0 ) ,
& F_27 ( V_12 -> V_143 , F_78 ( V_3 ) , 0 ) ) ;
V_115 -> V_116 . V_58 = ( F_71 ( V_3 ) == V_97 ) != 0 ;
V_115 -> V_116 . V_57 = true ;
V_115 -> V_116 . V_3 = V_3 ;
F_139 ( & V_115 -> V_116 . V_18 , F_55 , NULL , V_18 ) ;
} else {
F_139 ( & V_115 -> V_116 . V_18 , F_103 , NULL , V_18 ) ;
}
F_15 ( V_18 , F_117 , NULL ) ;
return V_170 ;
}
static int F_182 ( struct V_141 * V_12 , T_5 V_88 ,
unsigned int V_171 , unsigned long V_172 )
{
return - V_184 ;
}
static int F_183 ( void * V_173 , int V_174 )
{
struct V_141 * V_12 = V_173 ;
struct V_135 * V_136 ;
struct V_176 * V_177 ;
unsigned V_63 ;
int V_24 = 0 ;
F_174 (ca, d->c, i) {
V_136 = F_159 ( V_177 -> V_165 ) ;
V_24 |= F_173 ( V_136 -> V_175 , V_174 ) ;
}
return V_24 ;
}
void F_184 ( struct V_141 * V_12 )
{
struct V_178 * V_179 = V_12 -> V_87 ;
V_179 -> V_138 -> V_180 = F_181 ;
V_179 -> V_138 -> V_175 -> V_181 = F_183 ;
V_12 -> V_125 = F_176 ;
V_12 -> V_182 = F_182 ;
}
void F_185 ( void )
{
if ( V_185 )
F_186 ( V_185 ) ;
}
int T_6 F_187 ( void )
{
V_185 = F_188 ( V_114 , 0 ) ;
if ( ! V_185 )
return - V_42 ;
return 0 ;
}
