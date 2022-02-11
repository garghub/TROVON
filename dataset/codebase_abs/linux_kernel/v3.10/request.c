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
struct V_7 * V_7 = V_53 -> V_54 ;
F_33 ( L_1 ,
F_34 ( V_7 ) , ( T_6 ) V_7 -> V_55 ) ;
while ( F_34 ( V_7 ) ) {
unsigned V_18 = F_35 ( F_34 ( V_7 ) , 1U << 14 ) ;
if ( F_36 ( & V_53 -> V_56 , 0 , V_53 -> V_57 ) )
goto V_58;
V_7 -> V_55 += V_18 ;
V_7 -> V_59 -= V_18 << 9 ;
F_37 ( & V_53 -> V_56 ,
& F_38 ( V_53 -> V_60 , V_7 -> V_55 , V_18 ) ) ;
}
V_53 -> V_61 = true ;
F_39 ( V_7 ) ;
V_58:
F_40 ( V_51 , V_62 , V_63 ) ;
}
void F_41 ( struct V_64 * V_57 )
{
struct V_65 * V_66 ;
while ( ! F_42 ( & V_57 -> V_67 ) ) {
V_66 = F_43 ( & V_57 -> V_67 ,
struct V_65 , V_68 ) ;
F_44 ( & V_66 -> V_68 ) ;
F_23 ( V_66 ) ;
}
}
int F_45 ( struct V_64 * V_57 )
{
int V_44 ;
F_46 ( & V_57 -> V_69 ) ;
for ( V_44 = 0 ; V_44 < 6 ; V_44 ++ ) {
struct V_65 * V_66 = F_19 ( sizeof( * V_66 ) , V_32 ) ;
if ( ! V_66 )
return - V_33 ;
F_47 ( & V_66 -> V_68 , & V_57 -> V_67 ) ;
}
return 0 ;
}
static struct V_65 * F_48 ( struct V_64 * V_57 ,
const struct V_39 * V_70 ,
struct V_71 * V_72 ,
struct V_39 * V_73 )
{
struct V_65 * V_74 , * V_75 = NULL ;
F_49 (ret, &c->data_buckets, list)
if ( ! F_50 ( & V_74 -> V_76 , V_70 ) )
goto V_77;
else if ( V_74 -> V_78 == V_72 )
V_75 = V_74 ;
V_74 = V_75 ? : F_43 ( & V_57 -> V_67 ,
struct V_65 , V_68 ) ;
V_77:
if ( ! V_74 -> V_79 && F_31 ( V_73 ) ) {
V_74 -> V_79 = V_57 -> V_38 . V_80 ;
F_51 ( & V_74 -> V_76 , V_73 ) ;
F_52 ( V_73 ) ;
}
if ( ! V_74 -> V_79 )
V_74 = NULL ;
return V_74 ;
}
static bool F_53 ( struct V_39 * V_40 , unsigned V_81 ,
struct V_70 * V_82 )
{
struct V_64 * V_57 = V_82 -> V_53 . V_57 ;
struct V_65 * V_66 ;
F_54 (key) V_73 ;
struct V_50 V_51 , * V_83 = NULL ;
unsigned V_44 ;
if ( V_82 -> V_84 ) {
F_55 ( & V_51 ) ;
V_83 = & V_51 ;
}
F_52 ( & V_73 . V_76 ) ;
F_56 ( & V_57 -> V_69 ) ;
while ( ! ( V_66 = F_48 ( V_57 , V_40 , V_82 -> V_72 , & V_73 . V_76 ) ) ) {
unsigned V_85 = V_82 -> V_53 . V_86
? V_87
: V_88 ;
F_57 ( & V_57 -> V_69 ) ;
if ( F_58 ( V_57 , V_85 , & V_73 . V_76 , 1 , V_83 ) )
return false ;
F_56 ( & V_57 -> V_69 ) ;
}
if ( F_31 ( & V_73 . V_76 ) )
F_59 ( V_57 , & V_73 . V_76 ) ;
for ( V_44 = 0 ; V_44 < F_31 ( & V_66 -> V_76 ) ; V_44 ++ )
F_60 ( F_61 ( V_57 , & V_66 -> V_76 , V_44 ) ) ;
for ( V_44 = 0 ; V_44 < F_31 ( & V_66 -> V_76 ) ; V_44 ++ )
V_40 -> V_49 [ V_44 ] = V_66 -> V_76 . V_49 [ V_44 ] ;
V_81 = F_35 ( V_81 , V_66 -> V_79 ) ;
F_62 ( V_40 , F_63 ( V_40 ) + V_81 ) ;
F_64 ( V_40 , V_81 ) ;
F_65 ( V_40 , F_31 ( & V_66 -> V_76 ) ) ;
F_66 ( & V_66 -> V_68 , & V_57 -> V_67 ) ;
F_67 ( & V_66 -> V_76 , V_40 ) ;
V_66 -> V_78 = V_82 -> V_72 ;
V_66 -> V_79 -= V_81 ;
for ( V_44 = 0 ; V_44 < F_31 ( & V_66 -> V_76 ) ; V_44 ++ ) {
F_68 ( & V_66 -> V_76 , V_44 , F_69 ( & V_66 -> V_76 , V_44 ) + V_81 ) ;
F_70 ( V_81 ,
& F_71 ( V_57 , & V_66 -> V_76 , V_44 ) -> V_89 ) ;
}
if ( V_66 -> V_79 < V_57 -> V_38 . V_90 )
V_66 -> V_79 = 0 ;
if ( V_66 -> V_79 )
for ( V_44 = 0 ; V_44 < F_31 ( & V_66 -> V_76 ) ; V_44 ++ )
F_72 ( & F_73 ( V_57 , & V_66 -> V_76 , V_44 ) -> V_91 ) ;
F_57 ( & V_57 -> V_69 ) ;
return true ;
}
static void F_74 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
struct V_39 * V_92 = V_53 -> V_56 . V_93 , * V_94 = V_53 -> V_56 . V_93 ;
while ( V_92 != V_53 -> V_56 . V_95 ) {
struct V_39 * V_96 = F_75 ( V_92 ) ;
F_65 ( V_92 , 0 ) ;
F_51 ( V_94 , V_92 ) ;
V_94 = F_75 ( V_94 ) ;
V_92 = V_96 ;
}
V_53 -> V_56 . V_95 = V_94 ;
V_62 ( V_51 ) ;
}
static void F_76 ( struct V_7 * V_7 , int error )
{
struct V_50 * V_51 = V_7 -> V_97 ;
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
struct V_70 * V_82 = F_2 ( V_53 , struct V_70 , V_53 ) ;
if ( error ) {
if ( V_82 -> V_84 )
V_82 -> error = error ;
else if ( V_82 -> V_98 )
F_77 ( V_51 , F_74 , V_63 ) ;
else
F_77 ( V_51 , NULL , NULL ) ;
}
F_78 ( V_53 -> V_57 , V_7 , error , L_2 ) ;
}
static void F_79 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
struct V_70 * V_82 = F_2 ( V_53 , struct V_70 , V_53 ) ;
struct V_7 * V_7 = V_53 -> V_54 , * V_96 ;
if ( V_53 -> V_99 )
return F_32 ( V_51 ) ;
if ( F_80 ( F_34 ( V_7 ) , & V_53 -> V_57 -> V_100 ) < 0 ) {
F_81 ( V_53 -> V_57 ) ;
F_82 ( V_53 -> V_57 ) ;
}
do {
unsigned V_44 ;
struct V_39 * V_40 ;
struct V_101 * V_102 = V_82 -> V_45
? V_82 -> V_45 -> V_103 : V_53 -> V_57 -> V_103 ;
if ( F_36 ( & V_53 -> V_56 ,
1 + ( V_53 -> V_43 ? 1 : 0 ) ,
V_53 -> V_57 ) )
F_40 ( V_51 , V_62 , V_63 ) ;
V_40 = V_53 -> V_56 . V_95 ;
F_52 ( V_40 ) ;
F_83 ( V_40 , V_53 -> V_60 ) ;
F_62 ( V_40 , V_7 -> V_55 ) ;
if ( ! F_53 ( V_40 , F_34 ( V_7 ) , V_82 ) )
goto V_104;
V_96 = F_84 ( V_7 , F_85 ( V_40 ) , V_105 , V_102 ) ;
if ( ! V_96 ) {
F_59 ( V_53 -> V_57 , V_40 ) ;
F_40 ( V_51 , F_79 , V_63 ) ;
}
V_96 -> V_106 = F_76 ;
V_96 -> V_97 = V_51 ;
if ( V_82 -> V_84 ) {
F_86 ( V_40 , true ) ;
for ( V_44 = 0 ; V_44 < F_31 ( V_40 ) ; V_44 ++ )
F_87 ( F_73 ( V_53 -> V_57 , V_40 , V_44 ) ,
V_107 ) ;
}
F_88 ( V_40 , V_53 -> V_43 ) ;
if ( F_89 ( V_40 ) )
F_26 ( V_96 , V_40 ) ;
F_33 ( L_3 , F_90 ( V_40 ) ) ;
F_91 ( & V_53 -> V_56 ) ;
F_92 ( V_96 , V_96 -> V_55 , V_96 -> V_108 ) ;
V_96 -> V_109 |= V_110 ;
F_93 ( V_96 , V_53 -> V_57 , V_40 , 0 ) ;
} while ( V_96 != V_7 );
V_53 -> V_61 = true ;
F_40 ( V_51 , V_62 , V_63 ) ;
V_104:
F_94 ( V_82 -> V_84 ) ;
if ( V_82 -> V_98 ) {
V_53 -> V_99 = true ;
return F_32 ( V_51 ) ;
} else {
V_53 -> V_61 = true ;
F_39 ( V_7 ) ;
if ( ! F_95 ( & V_53 -> V_56 ) )
F_40 ( V_51 , V_62 , V_63 ) ;
else
F_96 ( V_51 ) ;
}
}
void F_97 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
F_98 ( & V_53 -> V_56 ) ;
F_99 ( V_53 -> V_54 ) ;
F_79 ( V_51 ) ;
}
void F_100 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
struct V_70 * V_82 = F_2 ( V_53 , struct V_70 , V_53 ) ;
if ( F_101 ( V_53 , V_53 -> V_57 ) ) {
V_82 -> error = - V_33 ;
V_53 -> V_61 = true ;
}
if ( V_53 -> V_61 ) {
F_102 ( & V_53 -> V_56 ) ;
F_96 ( V_51 ) ;
} else
F_40 ( V_51 , F_79 , V_63 ) ;
}
static void F_103 ( struct V_7 * V_7 , int error )
{
struct V_50 * V_51 = V_7 -> V_97 ;
if ( error ) {
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
V_82 -> error = error ;
V_82 -> V_111 = false ;
}
F_39 ( V_7 ) ;
F_104 ( V_51 ) ;
}
void F_105 ( struct V_7 * V_7 , int error )
{
struct V_112 * V_66 = F_2 ( V_7 , struct V_112 , V_7 ) ;
struct V_50 * V_51 = V_7 -> V_97 ;
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
if ( error )
V_82 -> error = error ;
else if ( F_61 ( V_82 -> V_53 . V_57 , & V_66 -> V_76 , 0 ) ) {
F_106 ( & V_82 -> V_53 . V_57 -> V_113 ) ;
V_82 -> error = - V_114 ;
}
F_78 ( V_82 -> V_53 . V_57 , V_7 , error , L_4 ) ;
}
static void F_107 ( struct V_70 * V_82 )
{
if ( V_82 -> V_115 ) {
int V_116 , V_117 = F_108 ( V_82 -> V_115 ) ;
unsigned long V_118 = V_119 - V_82 -> V_120 ;
V_116 = F_109 () ;
F_110 ( V_116 , & V_82 -> V_45 -> V_121 -> V_122 ) ;
F_111 ( V_116 , & V_82 -> V_45 -> V_121 -> V_122 , V_123 [ V_117 ] , V_118 ) ;
F_112 () ;
F_113 ( V_82 , V_82 -> V_115 ) ;
F_114 ( V_82 -> V_115 , V_82 -> error ) ;
V_82 -> V_115 = NULL ;
}
}
static void F_115 ( struct V_70 * V_82 )
{
struct V_7 * V_7 = & V_82 -> V_7 . V_7 ;
memcpy ( V_7 , V_82 -> V_115 , sizeof( struct V_7 ) ) ;
V_7 -> V_106 = F_103 ;
V_7 -> V_97 = & V_82 -> V_51 ;
F_116 ( & V_7 -> V_124 , 3 ) ;
}
static void F_117 ( struct V_50 * V_51 )
{
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
F_107 ( V_82 ) ;
if ( V_82 -> V_53 . V_54 )
F_39 ( V_82 -> V_53 . V_54 ) ;
if ( V_82 -> V_125 )
F_118 ( V_82 -> V_7 . V_7 . V_126 , V_82 -> V_45 -> V_125 ) ;
F_119 ( V_51 ) ;
F_118 ( V_82 , V_82 -> V_45 -> V_57 -> V_70 ) ;
}
static struct V_70 * F_120 ( struct V_7 * V_7 , struct V_127 * V_45 )
{
struct V_41 * V_42 ;
struct V_70 * V_82 = F_121 ( V_45 -> V_57 -> V_70 , V_105 ) ;
memset ( V_82 , 0 , F_122 ( struct V_70 , V_53 . V_56 ) ) ;
F_123 ( & V_82 -> V_51 , NULL ) ;
V_82 -> V_53 . V_60 = V_45 -> V_128 ;
V_82 -> V_53 . V_57 = V_45 -> V_57 ;
V_82 -> V_45 = V_45 ;
V_82 -> V_53 . V_129 = - 1 ;
V_82 -> V_72 = V_9 ;
V_82 -> V_115 = V_7 ;
V_82 -> V_98 = ( V_7 -> V_109 & V_110 ) != 0 ;
V_82 -> V_53 . V_130 = ( V_7 -> V_109 & V_131 ) != 0 ;
V_82 -> V_53 . V_99 = ( V_7 -> V_109 & V_132 ) != 0 ;
V_82 -> V_111 = 1 ;
V_82 -> V_120 = V_119 ;
F_115 ( V_82 ) ;
if ( V_7 -> V_59 != F_124 ( V_7 ) * V_19 ) {
V_42 = F_121 ( V_45 -> V_125 , V_105 ) ;
memcpy ( V_42 , F_125 ( V_7 ) ,
sizeof( struct V_41 ) * F_124 ( V_7 ) ) ;
V_82 -> V_7 . V_7 . V_126 = V_42 ;
V_82 -> V_125 = 1 ;
}
return V_82 ;
}
static void F_126 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
int V_74 = F_127 ( V_133 , V_53 -> V_57 , V_53 ) ;
if ( V_74 == - V_134 )
F_40 ( V_51 , F_126 , V_63 ) ;
F_96 ( V_51 ) ;
}
static void F_128 ( struct V_50 * V_51 )
{
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
struct V_35 * V_36 = F_2 ( V_82 -> V_45 , struct V_35 , V_121 ) ;
F_117 ( V_51 ) ;
F_129 ( V_36 ) ;
}
static void F_130 ( struct V_50 * V_51 )
{
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
if ( V_82 -> V_53 . V_135 )
F_131 ( V_82 ) ;
if ( V_82 -> V_53 . V_54 ) {
int V_44 ;
struct V_41 * V_42 ;
F_132 (bv, s->op.cache_bio, i, 0 )
F_133 ( V_42 -> V_46 ) ;
}
F_128 ( V_51 ) ;
}
static void F_134 ( struct V_50 * V_51 )
{
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
struct V_41 * V_42 ;
int V_44 ;
if ( V_82 -> V_111 ) {
F_33 ( L_5 ,
( T_6 ) V_82 -> V_115 -> V_55 ) ;
V_82 -> error = 0 ;
V_42 = V_82 -> V_7 . V_7 . V_126 ;
F_115 ( V_82 ) ;
V_82 -> V_7 . V_7 . V_126 = V_42 ;
if ( ! V_82 -> V_125 )
F_27 (bv, s->orig_bio, i)
V_42 -> V_47 = 0 , V_42 -> V_48 = V_19 ;
else
memcpy ( V_82 -> V_7 . V_7 . V_126 ,
F_125 ( V_82 -> V_115 ) ,
sizeof( struct V_41 ) *
F_124 ( V_82 -> V_115 ) ) ;
F_135 ( & V_82 -> V_7 . V_7 ) ;
F_136 ( & V_82 -> V_7 . V_7 , & V_82 -> V_51 , V_82 -> V_45 ) ;
}
F_40 ( V_51 , F_130 , NULL ) ;
}
static void F_137 ( struct V_50 * V_51 )
{
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
struct V_35 * V_36 = F_2 ( V_82 -> V_45 , struct V_35 , V_121 ) ;
if ( V_82 -> V_53 . V_54 ) {
struct V_41 * V_92 , * V_94 ;
unsigned V_136 , V_137 , V_138 ;
void * V_139 ;
F_138 ( V_82 -> V_53 . V_54 ) ;
V_82 -> V_53 . V_54 -> V_55 = V_82 -> V_140 -> V_55 ;
V_82 -> V_53 . V_54 -> V_108 = V_82 -> V_140 -> V_108 ;
V_82 -> V_53 . V_54 -> V_59 = V_82 -> V_141 << 9 ;
F_139 ( V_82 -> V_53 . V_54 , NULL ) ;
V_92 = F_125 ( V_82 -> V_53 . V_54 ) ;
V_94 = F_125 ( V_82 -> V_140 ) ;
V_136 = V_92 -> V_47 ;
V_137 = V_94 -> V_47 ;
V_139 = F_28 ( V_94 -> V_46 ) ;
while ( 1 ) {
if ( V_137 == V_94 -> V_47 + V_94 -> V_48 ) {
F_30 ( V_94 -> V_46 ) ;
V_94 ++ ;
if ( V_94 == F_140 ( V_82 -> V_140 ,
V_82 -> V_140 -> V_142 ) )
break;
V_137 = V_94 -> V_47 ;
V_139 = F_28 ( V_94 -> V_46 ) ;
}
if ( V_136 == V_92 -> V_47 + V_92 -> V_48 ) {
V_92 ++ ;
if ( V_92 == F_140 ( V_82 -> V_53 . V_54 ,
V_82 -> V_53 . V_54 -> V_142 ) )
F_141 () ;
V_136 = V_92 -> V_47 ;
}
V_138 = F_35 ( V_94 -> V_47 + V_94 -> V_48 - V_137 ,
V_92 -> V_47 + V_92 -> V_48 - V_136 ) ;
memcpy ( V_139 + V_137 ,
F_142 ( V_92 -> V_46 ) + V_136 ,
V_138 ) ;
V_136 += V_138 ;
V_137 += V_138 ;
}
F_39 ( V_82 -> V_140 ) ;
V_82 -> V_140 = NULL ;
}
if ( V_23 ( V_36 , & V_82 -> V_7 . V_7 ) && V_82 -> V_111 )
F_143 ( V_82 ) ;
F_107 ( V_82 ) ;
if ( V_82 -> V_53 . V_54 &&
! F_144 ( V_143 , & V_82 -> V_53 . V_57 -> V_144 ) ) {
V_82 -> V_53 . type = V_145 ;
F_145 ( & V_82 -> V_53 . V_51 , F_97 , NULL , V_51 ) ;
}
F_40 ( V_51 , F_130 , NULL ) ;
}
static void F_146 ( struct V_50 * V_51 )
{
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
struct V_35 * V_36 = F_2 ( V_82 -> V_45 , struct V_35 , V_121 ) ;
F_147 ( V_82 , ! V_82 -> V_140 , V_82 -> V_53 . V_99 ) ;
if ( V_82 -> error )
F_148 ( V_51 , F_134 , V_63 ) ;
else if ( V_82 -> V_53 . V_54 || V_23 ( V_36 , & V_82 -> V_7 . V_7 ) )
F_148 ( V_51 , F_137 , V_63 ) ;
else
F_148 ( V_51 , F_130 , NULL ) ;
}
static int F_149 ( struct V_146 * V_66 , struct V_70 * V_82 ,
struct V_7 * V_7 , unsigned V_81 )
{
int V_74 = 0 ;
unsigned V_147 ;
struct V_35 * V_36 = F_2 ( V_82 -> V_45 , struct V_35 , V_121 ) ;
struct V_7 * V_148 ;
V_148 = F_84 ( V_7 , V_81 , V_105 , V_82 -> V_45 -> V_103 ) ;
if ( ! V_148 )
return - V_134 ;
if ( V_148 == V_7 )
V_82 -> V_53 . V_149 = true ;
V_148 -> V_106 = F_103 ;
V_148 -> V_97 = & V_82 -> V_51 ;
if ( V_82 -> V_140 || V_82 -> V_53 . V_99 )
goto V_150;
if ( V_148 != V_7 ||
( V_7 -> V_109 & V_151 ) ||
( V_7 -> V_109 & V_152 ) ||
V_82 -> V_53 . V_57 -> V_153 . V_154 >= V_155 )
V_147 = 0 ;
else {
V_147 = F_35 ( V_36 -> V_156 >> 9 ,
V_81 - F_34 ( V_148 ) ) ;
if ( F_150 ( V_148 ) + V_147 > F_151 ( V_148 -> V_108 ) )
V_147 = F_151 ( V_148 -> V_108 ) - F_150 ( V_148 ) ;
}
V_82 -> V_141 = F_34 ( V_148 ) + V_147 ;
V_82 -> V_53 . V_54 = F_152 ( V_157 ,
F_153 ( V_82 -> V_141 , V_158 ) ,
V_36 -> V_121 . V_103 ) ;
if ( ! V_82 -> V_53 . V_54 )
goto V_150;
V_82 -> V_53 . V_54 -> V_55 = V_148 -> V_55 ;
V_82 -> V_53 . V_54 -> V_108 = V_148 -> V_108 ;
V_82 -> V_53 . V_54 -> V_59 = V_82 -> V_141 << 9 ;
V_82 -> V_53 . V_54 -> V_106 = F_103 ;
V_82 -> V_53 . V_54 -> V_97 = & V_82 -> V_51 ;
V_74 = - V_114 ;
if ( ! F_154 ( V_66 , & V_82 -> V_53 , V_82 -> V_53 . V_54 ) )
goto V_159;
F_139 ( V_82 -> V_53 . V_54 , NULL ) ;
if ( F_155 ( V_82 -> V_53 . V_54 , V_160 | V_105 ) )
goto V_159;
V_82 -> V_140 = V_148 ;
F_99 ( V_82 -> V_53 . V_54 ) ;
F_156 ( V_82 -> V_115 ) ;
F_136 ( V_82 -> V_53 . V_54 , & V_82 -> V_51 , V_82 -> V_45 ) ;
return V_74 ;
V_159:
F_39 ( V_82 -> V_53 . V_54 ) ;
V_82 -> V_53 . V_54 = NULL ;
V_150:
F_136 ( V_148 , & V_82 -> V_51 , V_82 -> V_45 ) ;
return V_74 ;
}
static void F_157 ( struct V_35 * V_36 , struct V_70 * V_82 )
{
struct V_50 * V_51 = & V_82 -> V_51 ;
F_158 ( V_36 , V_82 ) ;
F_145 ( & V_82 -> V_53 . V_51 , F_126 , NULL , V_51 ) ;
F_40 ( V_51 , F_146 , NULL ) ;
}
static void F_159 ( struct V_50 * V_51 )
{
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
struct V_35 * V_36 = F_2 ( V_82 -> V_45 , struct V_35 , V_121 ) ;
F_160 ( & V_36 -> V_161 ) ;
F_128 ( V_51 ) ;
}
static bool F_161 ( struct V_35 * V_36 , struct V_7 * V_7 )
{
unsigned V_162 = ( V_7 -> V_109 & V_163 )
? V_164
: V_165 ;
return ! F_13 ( & V_36 -> V_121 . V_166 ) &&
V_21 ( V_36 , V_7 ) == V_167 &&
V_36 -> V_121 . V_57 -> V_153 . V_154 < V_162 ;
}
static void F_162 ( struct V_35 * V_36 , struct V_70 * V_82 )
{
struct V_50 * V_51 = & V_82 -> V_51 ;
struct V_7 * V_7 = & V_82 -> V_7 . V_7 ;
struct V_39 V_168 , V_169 ;
V_168 = F_38 ( V_36 -> V_121 . V_128 , V_7 -> V_55 , 0 ) ;
V_169 = F_38 ( V_36 -> V_121 . V_128 , F_150 ( V_7 ) , 0 ) ;
F_163 ( & V_82 -> V_53 . V_57 -> V_170 , & V_168 , & V_169 ) ;
F_158 ( V_36 , V_82 ) ;
F_164 ( & V_36 -> V_161 ) ;
if ( F_163 ( & V_36 -> V_171 , & V_168 , & V_169 ) ) {
V_82 -> V_53 . V_99 = false ;
V_82 -> V_84 = true ;
}
if ( V_7 -> V_109 & V_132 )
goto V_99;
if ( V_82 -> V_53 . V_99 )
goto V_99;
if ( F_161 ( V_36 , V_82 -> V_115 ) )
V_82 -> V_84 = true ;
if ( ! V_82 -> V_84 ) {
V_82 -> V_53 . V_54 = F_165 ( V_7 , V_105 ,
V_36 -> V_121 . V_103 ) ;
F_166 ( V_82 -> V_115 ) ;
F_136 ( V_7 , V_51 , V_82 -> V_45 ) ;
} else {
V_82 -> V_53 . V_54 = V_7 ;
F_167 ( V_82 -> V_115 ) ;
F_168 ( V_36 , F_34 ( V_7 ) ) ;
}
V_58:
F_145 ( & V_82 -> V_53 . V_51 , F_97 , NULL , V_51 ) ;
F_40 ( V_51 , F_159 , NULL ) ;
V_99:
V_82 -> V_53 . V_99 = true ;
V_82 -> V_53 . V_54 = V_82 -> V_115 ;
F_99 ( V_82 -> V_53 . V_54 ) ;
F_169 ( V_82 -> V_115 ) ;
if ( ( V_7 -> V_109 & V_132 ) &&
! F_170 ( F_171 ( V_36 -> V_172 ) ) )
goto V_58;
F_136 ( V_7 , V_51 , V_82 -> V_45 ) ;
goto V_58;
}
static void F_172 ( struct V_35 * V_36 , struct V_70 * V_82 )
{
struct V_50 * V_51 = & V_82 -> V_51 ;
struct V_7 * V_7 = & V_82 -> V_7 . V_7 ;
if ( V_7 -> V_109 & V_132 ) {
F_162 ( V_36 , V_82 ) ;
return;
}
if ( V_82 -> V_53 . V_130 )
F_173 ( V_82 -> V_53 . V_57 , V_51 ) ;
F_136 ( V_7 , V_51 , V_82 -> V_45 ) ;
F_40 ( V_51 , F_128 , NULL ) ;
}
int F_174 ( struct V_64 * V_57 )
{
int V_44 ;
if ( ! V_57 -> V_173 &&
! V_57 -> V_174 )
return 0 ;
V_44 = ( F_175 () - V_57 -> V_175 ) / 1024 ;
if ( V_44 < 0 )
return 0 ;
V_44 += F_13 ( & V_57 -> V_176 ) ;
if ( V_44 >= 0 )
return 0 ;
V_44 += V_177 ;
return V_44 <= 0 ? 1 : F_176 ( V_44 , 6 ) ;
}
static void F_177 ( struct V_71 * V_178 )
{
F_178 ( V_178 -> V_179 ,
V_178 -> V_180 , 8 , 0 ) ;
V_178 -> V_180 = 0 ;
}
static struct V_181 * F_179 ( struct V_35 * V_36 , T_6 V_40 )
{
return & V_36 -> V_182 [ F_180 ( V_40 , V_183 ) ] ;
}
static void F_158 ( struct V_35 * V_36 , struct V_70 * V_82 )
{
struct V_64 * V_57 = V_82 -> V_53 . V_57 ;
struct V_7 * V_7 = & V_82 -> V_7 . V_7 ;
long rand ;
int V_184 = F_174 ( V_57 ) ;
unsigned V_185 = V_21 ( V_36 , V_7 ) ;
if ( F_13 ( & V_36 -> V_121 . V_166 ) ||
V_57 -> V_153 . V_154 > V_186 ||
( V_7 -> V_109 & V_132 ) )
goto V_99;
if ( V_185 == V_187 ||
( V_185 == V_188 &&
( V_7 -> V_109 & V_110 ) ) )
goto V_99;
if ( V_7 -> V_55 & ( V_57 -> V_38 . V_90 - 1 ) ||
F_34 ( V_7 ) & ( V_57 -> V_38 . V_90 - 1 ) ) {
F_33 ( L_6 ) ;
goto V_99;
}
if ( ! V_184 ) {
V_184 = V_36 -> V_189 >> 9 ;
if ( ! V_184 )
goto V_190;
if ( V_185 == V_167 &&
( V_7 -> V_109 & V_110 ) &&
( V_7 -> V_109 & V_163 ) )
goto V_190;
}
if ( V_36 -> V_191 ) {
struct V_192 * V_44 ;
F_56 ( & V_36 -> V_193 ) ;
F_181 (i, iohash(dc, bio->bi_sector), hash)
if ( V_44 -> V_78 == V_7 -> V_55 &&
F_182 ( V_119 , V_44 -> V_119 ) )
goto V_77;
V_44 = F_43 ( & V_36 -> V_194 , struct V_192 , V_195 ) ;
F_177 ( V_82 -> V_72 ) ;
V_44 -> V_196 = 0 ;
V_77:
if ( V_44 -> V_196 + V_7 -> V_59 > V_44 -> V_196 )
V_44 -> V_196 += V_7 -> V_59 ;
V_44 -> V_78 = F_150 ( V_7 ) ;
V_44 -> V_119 = V_119 + F_183 ( 5000 ) ;
V_82 -> V_72 -> V_180 = V_44 -> V_196 ;
F_184 ( & V_44 -> V_197 ) ;
F_185 ( & V_44 -> V_197 , F_179 ( V_36 , V_44 -> V_78 ) ) ;
F_66 ( & V_44 -> V_195 , & V_36 -> V_194 ) ;
F_57 ( & V_36 -> V_193 ) ;
} else {
V_82 -> V_72 -> V_180 = V_7 -> V_59 ;
F_177 ( V_82 -> V_72 ) ;
}
rand = F_186 () ;
V_184 -= F_187 ( & rand , V_198 ) ;
if ( V_184 <= ( int ) ( F_188 ( V_82 -> V_72 -> V_180 ,
V_82 -> V_72 -> V_179 ) >> 9 ) )
goto V_99;
V_190:
F_189 ( V_57 , F_34 ( V_7 ) ) ;
return;
V_99:
F_190 ( V_82 , F_34 ( V_7 ) ) ;
V_82 -> V_53 . V_99 = true ;
}
static void F_191 ( struct V_199 * V_200 , struct V_7 * V_7 )
{
struct V_70 * V_82 ;
struct V_127 * V_45 = V_7 -> V_108 -> V_201 -> V_202 ;
struct V_35 * V_36 = F_2 ( V_45 , struct V_35 , V_121 ) ;
int V_116 , V_117 = F_108 ( V_7 ) ;
V_116 = F_109 () ;
F_192 ( V_116 , & V_45 -> V_121 -> V_122 , V_203 [ V_117 ] ) ;
F_111 ( V_116 , & V_45 -> V_121 -> V_122 , V_81 [ V_117 ] , F_34 ( V_7 ) ) ;
F_112 () ;
V_7 -> V_108 = V_36 -> V_172 ;
V_7 -> V_55 += V_36 -> V_38 . V_204 ;
if ( F_193 ( V_36 ) ) {
V_82 = F_120 ( V_7 , V_45 ) ;
F_194 ( V_82 , V_7 ) ;
if ( ! F_195 ( V_7 ) )
F_172 ( V_36 , V_82 ) ;
else if ( V_117 )
F_162 ( V_36 , V_82 ) ;
else
F_157 ( V_36 , V_82 ) ;
} else {
if ( ( V_7 -> V_109 & V_132 ) &&
! F_170 ( F_171 ( V_36 -> V_172 ) ) )
F_114 ( V_7 , 0 ) ;
else
F_196 ( V_7 , & V_45 -> V_205 ) ;
}
}
static int F_197 ( struct V_127 * V_45 , T_7 V_185 ,
unsigned int V_206 , unsigned long V_207 )
{
struct V_35 * V_36 = F_2 ( V_45 , struct V_35 , V_121 ) ;
return F_198 ( V_36 -> V_172 , V_185 , V_206 , V_207 ) ;
}
static int F_199 ( void * V_208 , int V_209 )
{
struct V_127 * V_45 = V_208 ;
struct V_35 * V_36 = F_2 ( V_45 , struct V_35 , V_121 ) ;
struct V_199 * V_200 = F_171 ( V_36 -> V_172 ) ;
int V_74 = 0 ;
if ( F_200 ( & V_200 -> V_210 , V_209 ) )
return 1 ;
if ( F_193 ( V_36 ) ) {
unsigned V_44 ;
struct V_211 * V_212 ;
F_201 (ca, d->c, i) {
V_200 = F_171 ( V_212 -> V_172 ) ;
V_74 |= F_200 ( & V_200 -> V_210 , V_209 ) ;
}
F_129 ( V_36 ) ;
}
return V_74 ;
}
void F_202 ( struct V_35 * V_36 )
{
struct V_213 * V_214 = V_36 -> V_121 . V_121 ;
V_214 -> V_215 -> V_216 = F_191 ;
V_214 -> V_215 -> V_210 . V_217 = F_199 ;
V_36 -> V_121 . V_140 = F_149 ;
V_36 -> V_121 . V_218 = F_197 ;
}
static int F_203 ( struct V_146 * V_66 , struct V_70 * V_82 ,
struct V_7 * V_7 , unsigned V_81 )
{
while ( V_7 -> V_219 != V_7 -> V_142 ) {
struct V_41 * V_42 = F_125 ( V_7 ) ;
unsigned V_220 = F_35 ( V_42 -> V_48 >> 9 , V_81 ) ;
void * V_221 = F_28 ( V_42 -> V_46 ) ;
memset ( V_221 + V_42 -> V_47 , 0 , V_220 << 9 ) ;
F_30 ( V_42 -> V_46 ) ;
V_42 -> V_48 -= V_220 << 9 ;
V_42 -> V_47 += V_220 << 9 ;
if ( V_42 -> V_48 )
return 0 ;
V_7 -> V_55 += V_220 ;
V_7 -> V_59 -= V_220 << 9 ;
V_7 -> V_219 ++ ;
V_81 -= V_220 ;
}
V_82 -> V_53 . V_149 = true ;
return 0 ;
}
static void F_204 ( struct V_199 * V_200 , struct V_7 * V_7 )
{
struct V_70 * V_82 ;
struct V_50 * V_51 ;
struct V_127 * V_45 = V_7 -> V_108 -> V_201 -> V_202 ;
int V_116 , V_117 = F_108 ( V_7 ) ;
V_116 = F_109 () ;
F_192 ( V_116 , & V_45 -> V_121 -> V_122 , V_203 [ V_117 ] ) ;
F_111 ( V_116 , & V_45 -> V_121 -> V_122 , V_81 [ V_117 ] , F_34 ( V_7 ) ) ;
F_112 () ;
V_82 = F_120 ( V_7 , V_45 ) ;
V_51 = & V_82 -> V_51 ;
V_7 = & V_82 -> V_7 . V_7 ;
F_194 ( V_82 , V_7 ) ;
if ( F_195 ( V_7 ) && ! V_117 ) {
F_145 ( & V_82 -> V_53 . V_51 , F_126 , NULL , V_51 ) ;
} else if ( F_195 ( V_7 ) || V_82 -> V_53 . V_99 ) {
F_163 ( & V_82 -> V_53 . V_57 -> V_170 ,
& F_38 ( V_45 -> V_128 , V_7 -> V_55 , 0 ) ,
& F_38 ( V_45 -> V_128 , F_150 ( V_7 ) , 0 ) ) ;
V_82 -> V_84 = true ;
V_82 -> V_53 . V_54 = V_7 ;
F_145 ( & V_82 -> V_53 . V_51 , F_97 , NULL , V_51 ) ;
} else {
if ( V_82 -> V_53 . V_130 )
F_173 ( V_82 -> V_53 . V_57 , V_51 ) ;
}
F_40 ( V_51 , F_117 , NULL ) ;
}
static int F_205 ( struct V_127 * V_45 , T_7 V_185 ,
unsigned int V_206 , unsigned long V_207 )
{
return - V_222 ;
}
static int F_206 ( void * V_208 , int V_209 )
{
struct V_127 * V_45 = V_208 ;
struct V_199 * V_200 ;
struct V_211 * V_212 ;
unsigned V_44 ;
int V_74 = 0 ;
F_201 (ca, d->c, i) {
V_200 = F_171 ( V_212 -> V_172 ) ;
V_74 |= F_200 ( & V_200 -> V_210 , V_209 ) ;
}
return V_74 ;
}
void F_207 ( struct V_127 * V_45 )
{
struct V_213 * V_214 = V_45 -> V_121 ;
V_214 -> V_215 -> V_216 = F_204 ;
V_214 -> V_215 -> V_210 . V_217 = F_206 ;
V_45 -> V_140 = F_203 ;
V_45 -> V_218 = F_205 ;
}
void F_208 ( void )
{
#ifdef F_24
F_209 ( & V_34 ) ;
#endif
if ( V_223 )
F_210 ( V_223 ) ;
}
int T_8 F_211 ( void )
{
V_223 = F_212 ( V_70 , 0 ) ;
if ( ! V_223 )
return - V_33 ;
#ifdef F_24
F_213 ( & V_34 ) ;
F_17 ( & V_6 ) ;
F_214 ( & V_34 , V_224 ) ;
#endif
return 0 ;
}
