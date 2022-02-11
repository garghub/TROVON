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
V_7 -> V_101 &= ~ ( V_102 | V_103 ) ;
do {
unsigned V_44 ;
struct V_39 * V_40 ;
struct V_104 * V_105 = V_82 -> V_45
? V_82 -> V_45 -> V_106 : V_53 -> V_57 -> V_106 ;
if ( F_36 ( & V_53 -> V_56 ,
1 + ( V_53 -> V_43 ? 1 : 0 ) ,
V_53 -> V_57 ) )
F_40 ( V_51 , V_62 , V_63 ) ;
V_40 = V_53 -> V_56 . V_95 ;
F_52 ( V_40 ) ;
F_83 ( V_40 , V_53 -> V_60 ) ;
F_62 ( V_40 , V_7 -> V_55 ) ;
if ( ! F_53 ( V_40 , F_34 ( V_7 ) , V_82 ) )
goto V_107;
V_96 = F_84 ( V_7 , F_85 ( V_40 ) , V_108 , V_105 ) ;
V_96 -> V_109 = F_76 ;
V_96 -> V_97 = V_51 ;
if ( V_82 -> V_84 ) {
F_86 ( V_40 , true ) ;
for ( V_44 = 0 ; V_44 < F_31 ( V_40 ) ; V_44 ++ )
F_87 ( F_73 ( V_53 -> V_57 , V_40 , V_44 ) ,
V_110 ) ;
}
F_88 ( V_40 , V_53 -> V_43 ) ;
if ( F_89 ( V_40 ) )
F_26 ( V_96 , V_40 ) ;
F_90 ( V_40 ) ;
F_91 ( & V_53 -> V_56 ) ;
V_96 -> V_101 |= V_111 ;
F_92 ( V_96 , V_53 -> V_57 , V_40 , 0 ) ;
} while ( V_96 != V_7 );
V_53 -> V_61 = true ;
F_40 ( V_51 , V_62 , V_63 ) ;
V_107:
F_93 ( V_82 -> V_84 ) ;
if ( V_82 -> V_98 ) {
V_53 -> V_99 = true ;
return F_32 ( V_51 ) ;
} else {
V_53 -> V_61 = true ;
F_39 ( V_7 ) ;
if ( ! F_94 ( & V_53 -> V_56 ) )
F_40 ( V_51 , V_62 , V_63 ) ;
else
F_95 ( V_51 ) ;
}
}
void F_96 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
F_97 ( & V_53 -> V_56 ) ;
F_98 ( V_53 -> V_54 ) ;
F_79 ( V_51 ) ;
}
void F_99 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
struct V_70 * V_82 = F_2 ( V_53 , struct V_70 , V_53 ) ;
if ( F_100 ( V_53 , V_53 -> V_57 ) ) {
V_82 -> error = - V_33 ;
V_53 -> V_61 = true ;
}
if ( V_53 -> V_61 ) {
F_101 ( & V_53 -> V_56 ) ;
F_95 ( V_51 ) ;
} else
F_40 ( V_51 , F_79 , V_63 ) ;
}
static void F_102 ( struct V_7 * V_7 , int error )
{
struct V_50 * V_51 = V_7 -> V_97 ;
if ( error ) {
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
V_82 -> error = error ;
V_82 -> V_112 = false ;
}
F_39 ( V_7 ) ;
F_103 ( V_51 ) ;
}
void F_104 ( struct V_7 * V_7 , int error )
{
struct V_113 * V_66 = F_2 ( V_7 , struct V_113 , V_7 ) ;
struct V_50 * V_51 = V_7 -> V_97 ;
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
if ( error )
V_82 -> error = error ;
else if ( F_61 ( V_82 -> V_53 . V_57 , & V_66 -> V_76 , 0 ) ) {
F_105 ( & V_82 -> V_53 . V_57 -> V_114 ) ;
V_82 -> error = - V_115 ;
}
F_78 ( V_82 -> V_53 . V_57 , V_7 , error , L_3 ) ;
}
static void F_106 ( struct V_70 * V_82 )
{
if ( V_82 -> V_116 ) {
int V_117 , V_118 = F_107 ( V_82 -> V_116 ) ;
unsigned long V_119 = V_120 - V_82 -> V_121 ;
V_117 = F_108 () ;
F_109 ( V_117 , & V_82 -> V_45 -> V_122 -> V_123 ) ;
F_110 ( V_117 , & V_82 -> V_45 -> V_122 -> V_123 , V_124 [ V_118 ] , V_119 ) ;
F_111 () ;
F_112 ( V_82 , V_82 -> V_116 ) ;
F_113 ( V_82 -> V_116 , V_82 -> error ) ;
V_82 -> V_116 = NULL ;
}
}
static void F_114 ( struct V_70 * V_82 )
{
struct V_7 * V_7 = & V_82 -> V_7 . V_7 ;
memcpy ( V_7 , V_82 -> V_116 , sizeof( struct V_7 ) ) ;
V_7 -> V_109 = F_102 ;
V_7 -> V_97 = & V_82 -> V_51 ;
F_115 ( & V_7 -> V_125 , 3 ) ;
}
static void F_116 ( struct V_50 * V_51 )
{
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
F_106 ( V_82 ) ;
if ( V_82 -> V_53 . V_54 )
F_39 ( V_82 -> V_53 . V_54 ) ;
if ( V_82 -> V_126 )
F_117 ( V_82 -> V_7 . V_7 . V_127 , V_82 -> V_45 -> V_126 ) ;
F_118 ( V_51 ) ;
F_117 ( V_82 , V_82 -> V_45 -> V_57 -> V_70 ) ;
}
static struct V_70 * F_119 ( struct V_7 * V_7 , struct V_128 * V_45 )
{
struct V_41 * V_42 ;
struct V_70 * V_82 = F_120 ( V_45 -> V_57 -> V_70 , V_108 ) ;
memset ( V_82 , 0 , F_121 ( struct V_70 , V_53 . V_56 ) ) ;
F_122 ( & V_82 -> V_51 , NULL ) ;
V_82 -> V_53 . V_60 = V_45 -> V_129 ;
V_82 -> V_53 . V_57 = V_45 -> V_57 ;
V_82 -> V_45 = V_45 ;
V_82 -> V_53 . V_130 = - 1 ;
V_82 -> V_72 = V_9 ;
V_82 -> V_116 = V_7 ;
V_82 -> V_98 = ( V_7 -> V_101 & V_111 ) != 0 ;
V_82 -> V_53 . V_131 = ( V_7 -> V_101 & ( V_102 | V_103 ) ) != 0 ;
V_82 -> V_53 . V_99 = ( V_7 -> V_101 & V_132 ) != 0 ;
V_82 -> V_112 = 1 ;
V_82 -> V_121 = V_120 ;
F_114 ( V_82 ) ;
if ( V_7 -> V_59 != F_123 ( V_7 ) * V_19 ) {
V_42 = F_120 ( V_45 -> V_126 , V_108 ) ;
memcpy ( V_42 , F_124 ( V_7 ) ,
sizeof( struct V_41 ) * F_123 ( V_7 ) ) ;
V_82 -> V_7 . V_7 . V_127 = V_42 ;
V_82 -> V_126 = 1 ;
}
return V_82 ;
}
static void F_125 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_2 ( V_51 , struct V_52 , V_51 ) ;
int V_74 = F_126 ( V_133 , V_53 -> V_57 , V_53 ) ;
if ( V_74 == - V_134 )
F_40 ( V_51 , F_125 , V_63 ) ;
F_95 ( V_51 ) ;
}
static void F_127 ( struct V_50 * V_51 )
{
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
struct V_35 * V_36 = F_2 ( V_82 -> V_45 , struct V_35 , V_122 ) ;
F_116 ( V_51 ) ;
F_128 ( V_36 ) ;
}
static void F_129 ( struct V_50 * V_51 )
{
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
if ( V_82 -> V_53 . V_135 )
F_130 ( V_82 ) ;
if ( V_82 -> V_53 . V_54 ) {
int V_44 ;
struct V_41 * V_42 ;
F_131 (bv, s->op.cache_bio, i, 0 )
F_132 ( V_42 -> V_46 ) ;
}
F_127 ( V_51 ) ;
}
static void F_133 ( struct V_50 * V_51 )
{
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
struct V_41 * V_42 ;
int V_44 ;
if ( V_82 -> V_112 ) {
F_134 ( V_82 -> V_116 ) ;
V_82 -> error = 0 ;
V_42 = V_82 -> V_7 . V_7 . V_127 ;
F_114 ( V_82 ) ;
V_82 -> V_7 . V_7 . V_127 = V_42 ;
if ( ! V_82 -> V_126 )
F_27 (bv, s->orig_bio, i)
V_42 -> V_47 = 0 , V_42 -> V_48 = V_19 ;
else
memcpy ( V_82 -> V_7 . V_7 . V_127 ,
F_124 ( V_82 -> V_116 ) ,
sizeof( struct V_41 ) *
F_123 ( V_82 -> V_116 ) ) ;
F_135 ( & V_82 -> V_7 . V_7 , & V_82 -> V_51 , V_82 -> V_45 ) ;
}
F_40 ( V_51 , F_129 , NULL ) ;
}
static void F_136 ( struct V_50 * V_51 )
{
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
struct V_35 * V_36 = F_2 ( V_82 -> V_45 , struct V_35 , V_122 ) ;
if ( V_82 -> V_53 . V_54 ) {
F_137 ( V_82 -> V_53 . V_54 ) ;
V_82 -> V_53 . V_54 -> V_55 = V_82 -> V_136 -> V_55 ;
V_82 -> V_53 . V_54 -> V_137 = V_82 -> V_136 -> V_137 ;
V_82 -> V_53 . V_54 -> V_59 = V_82 -> V_138 << 9 ;
F_138 ( V_82 -> V_53 . V_54 , NULL ) ;
F_139 ( V_82 -> V_136 , V_82 -> V_53 . V_54 ) ;
F_39 ( V_82 -> V_136 ) ;
V_82 -> V_136 = NULL ;
}
if ( V_23 ( V_36 , & V_82 -> V_7 . V_7 ) && V_82 -> V_112 )
F_140 ( V_82 ) ;
F_106 ( V_82 ) ;
if ( V_82 -> V_53 . V_54 &&
! F_141 ( V_139 , & V_82 -> V_53 . V_57 -> V_140 ) ) {
V_82 -> V_53 . type = V_141 ;
F_142 ( & V_82 -> V_53 . V_51 , F_96 , NULL , V_51 ) ;
}
F_40 ( V_51 , F_129 , NULL ) ;
}
static void F_143 ( struct V_50 * V_51 )
{
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
struct V_35 * V_36 = F_2 ( V_82 -> V_45 , struct V_35 , V_122 ) ;
F_144 ( V_82 , ! V_82 -> V_136 , V_82 -> V_53 . V_99 ) ;
F_145 ( V_82 -> V_116 , ! V_82 -> V_136 , V_82 -> V_53 . V_99 ) ;
if ( V_82 -> error )
F_146 ( V_51 , F_133 , V_63 ) ;
else if ( V_82 -> V_53 . V_54 || V_23 ( V_36 , & V_82 -> V_7 . V_7 ) )
F_146 ( V_51 , F_136 , V_63 ) ;
else
F_146 ( V_51 , F_129 , NULL ) ;
}
static int F_147 ( struct V_142 * V_66 , struct V_70 * V_82 ,
struct V_7 * V_7 , unsigned V_81 )
{
int V_74 = 0 ;
unsigned V_143 ;
struct V_35 * V_36 = F_2 ( V_82 -> V_45 , struct V_35 , V_122 ) ;
struct V_7 * V_144 ;
V_144 = F_84 ( V_7 , V_81 , V_108 , V_82 -> V_45 -> V_106 ) ;
if ( V_144 == V_7 )
V_82 -> V_53 . V_145 = true ;
V_144 -> V_109 = F_102 ;
V_144 -> V_97 = & V_82 -> V_51 ;
if ( V_82 -> V_136 || V_82 -> V_53 . V_99 )
goto V_146;
if ( V_144 != V_7 ||
( V_7 -> V_101 & V_147 ) ||
( V_7 -> V_101 & V_148 ) ||
V_82 -> V_53 . V_57 -> V_149 . V_150 >= V_151 )
V_143 = 0 ;
else {
V_143 = F_35 ( V_36 -> V_152 >> 9 ,
V_81 - F_34 ( V_144 ) ) ;
if ( F_148 ( V_144 ) + V_143 > F_149 ( V_144 -> V_137 ) )
V_143 = F_149 ( V_144 -> V_137 ) -
F_148 ( V_144 ) ;
}
V_82 -> V_138 = F_34 ( V_144 ) + V_143 ;
V_82 -> V_53 . V_54 = F_150 ( V_153 ,
F_151 ( V_82 -> V_138 , V_154 ) ,
V_36 -> V_122 . V_106 ) ;
if ( ! V_82 -> V_53 . V_54 )
goto V_146;
V_82 -> V_53 . V_54 -> V_55 = V_144 -> V_55 ;
V_82 -> V_53 . V_54 -> V_137 = V_144 -> V_137 ;
V_82 -> V_53 . V_54 -> V_59 = V_82 -> V_138 << 9 ;
V_82 -> V_53 . V_54 -> V_109 = F_102 ;
V_82 -> V_53 . V_54 -> V_97 = & V_82 -> V_51 ;
V_74 = - V_115 ;
if ( ! F_152 ( V_66 , & V_82 -> V_53 , V_82 -> V_53 . V_54 ) )
goto V_155;
F_138 ( V_82 -> V_53 . V_54 , NULL ) ;
if ( F_153 ( V_82 -> V_53 . V_54 , V_156 | V_108 ) )
goto V_155;
V_82 -> V_136 = V_144 ;
F_98 ( V_82 -> V_53 . V_54 ) ;
F_135 ( V_82 -> V_53 . V_54 , & V_82 -> V_51 , V_82 -> V_45 ) ;
return V_74 ;
V_155:
F_39 ( V_82 -> V_53 . V_54 ) ;
V_82 -> V_53 . V_54 = NULL ;
V_146:
F_135 ( V_144 , & V_82 -> V_51 , V_82 -> V_45 ) ;
return V_74 ;
}
static void F_154 ( struct V_35 * V_36 , struct V_70 * V_82 )
{
struct V_50 * V_51 = & V_82 -> V_51 ;
F_155 ( V_36 , V_82 ) ;
F_142 ( & V_82 -> V_53 . V_51 , F_125 , NULL , V_51 ) ;
F_40 ( V_51 , F_143 , NULL ) ;
}
static void F_156 ( struct V_50 * V_51 )
{
struct V_70 * V_82 = F_2 ( V_51 , struct V_70 , V_51 ) ;
struct V_35 * V_36 = F_2 ( V_82 -> V_45 , struct V_35 , V_122 ) ;
F_157 ( & V_36 -> V_157 ) ;
F_127 ( V_51 ) ;
}
static void F_158 ( struct V_35 * V_36 , struct V_70 * V_82 )
{
struct V_50 * V_51 = & V_82 -> V_51 ;
struct V_7 * V_7 = & V_82 -> V_7 . V_7 ;
struct V_39 V_158 , V_159 ;
V_158 = F_38 ( V_36 -> V_122 . V_129 , V_7 -> V_55 , 0 ) ;
V_159 = F_38 ( V_36 -> V_122 . V_129 , F_148 ( V_7 ) , 0 ) ;
F_159 ( & V_82 -> V_53 . V_57 -> V_160 , & V_158 , & V_159 ) ;
F_155 ( V_36 , V_82 ) ;
F_160 ( & V_36 -> V_157 ) ;
if ( F_159 ( & V_36 -> V_161 , & V_158 , & V_159 ) ) {
V_82 -> V_53 . V_99 = false ;
V_82 -> V_84 = true ;
}
if ( V_7 -> V_101 & V_132 )
goto V_99;
if ( F_161 ( V_36 , V_82 -> V_116 ,
V_21 ( V_36 , V_7 ) ,
V_82 -> V_53 . V_99 ) ) {
V_82 -> V_53 . V_99 = false ;
V_82 -> V_84 = true ;
}
if ( V_82 -> V_53 . V_99 )
goto V_99;
F_162 ( V_82 -> V_116 , V_82 -> V_84 , V_82 -> V_53 . V_99 ) ;
if ( ! V_82 -> V_84 ) {
V_82 -> V_53 . V_54 = F_163 ( V_7 , V_108 ,
V_36 -> V_122 . V_106 ) ;
F_135 ( V_7 , V_51 , V_82 -> V_45 ) ;
} else {
F_164 ( V_36 ) ;
if ( V_82 -> V_53 . V_131 ) {
V_82 -> V_53 . V_54 = F_163 ( V_7 , V_108 ,
V_36 -> V_122 . V_106 ) ;
V_7 -> V_59 = 0 ;
V_7 -> V_162 = 0 ;
F_135 ( V_7 , V_51 , V_82 -> V_45 ) ;
} else {
V_82 -> V_53 . V_54 = V_7 ;
}
}
V_58:
F_142 ( & V_82 -> V_53 . V_51 , F_96 , NULL , V_51 ) ;
F_40 ( V_51 , F_156 , NULL ) ;
V_99:
V_82 -> V_53 . V_99 = true ;
V_82 -> V_53 . V_54 = V_82 -> V_116 ;
F_98 ( V_82 -> V_53 . V_54 ) ;
if ( ( V_7 -> V_101 & V_132 ) &&
! F_165 ( F_166 ( V_36 -> V_163 ) ) )
goto V_58;
F_135 ( V_7 , V_51 , V_82 -> V_45 ) ;
goto V_58;
}
static void F_167 ( struct V_35 * V_36 , struct V_70 * V_82 )
{
struct V_50 * V_51 = & V_82 -> V_51 ;
struct V_7 * V_7 = & V_82 -> V_7 . V_7 ;
if ( V_7 -> V_101 & V_132 ) {
F_158 ( V_36 , V_82 ) ;
return;
}
if ( V_82 -> V_53 . V_131 )
F_168 ( V_82 -> V_53 . V_57 , V_51 ) ;
F_135 ( V_7 , V_51 , V_82 -> V_45 ) ;
F_40 ( V_51 , F_127 , NULL ) ;
}
unsigned F_169 ( struct V_64 * V_57 )
{
int V_44 ;
long rand ;
if ( ! V_57 -> V_164 &&
! V_57 -> V_165 )
return 0 ;
V_44 = ( F_170 () - V_57 -> V_166 ) / 1024 ;
if ( V_44 < 0 )
return 0 ;
V_44 += F_13 ( & V_57 -> V_167 ) ;
if ( V_44 >= 0 )
return 0 ;
V_44 += V_168 ;
if ( V_44 > 0 )
V_44 = F_171 ( V_44 , 6 ) ;
rand = F_172 () ;
V_44 -= F_173 ( & rand , V_169 ) ;
return V_44 > 0 ? V_44 : 1 ;
}
static void F_174 ( struct V_71 * V_170 )
{
F_175 ( V_170 -> V_171 ,
V_170 -> V_172 , 8 , 0 ) ;
V_170 -> V_172 = 0 ;
}
static struct V_173 * F_176 ( struct V_35 * V_36 , T_6 V_40 )
{
return & V_36 -> V_174 [ F_177 ( V_40 , V_175 ) ] ;
}
static void F_155 ( struct V_35 * V_36 , struct V_70 * V_82 )
{
struct V_64 * V_57 = V_82 -> V_53 . V_57 ;
struct V_7 * V_7 = & V_82 -> V_7 . V_7 ;
unsigned V_176 = V_21 ( V_36 , V_7 ) ;
unsigned V_81 , V_167 = F_169 ( V_57 ) ;
if ( F_13 ( & V_36 -> V_122 . V_177 ) ||
V_57 -> V_149 . V_150 > V_178 ||
( V_7 -> V_101 & V_132 ) )
goto V_99;
if ( V_176 == V_179 ||
( V_176 == V_180 &&
( V_7 -> V_101 & V_111 ) ) )
goto V_99;
if ( V_7 -> V_55 & ( V_57 -> V_38 . V_90 - 1 ) ||
F_34 ( V_7 ) & ( V_57 -> V_38 . V_90 - 1 ) ) {
F_33 ( L_4 ) ;
goto V_99;
}
if ( ! V_167 && ! V_36 -> V_181 )
goto V_182;
if ( ! V_167 &&
V_176 == V_183 &&
( V_7 -> V_101 & V_111 ) &&
( V_7 -> V_101 & V_184 ) )
goto V_182;
if ( V_36 -> V_185 ) {
struct V_186 * V_44 ;
F_56 ( & V_36 -> V_187 ) ;
F_178 (i, iohash(dc, bio->bi_sector), hash)
if ( V_44 -> V_78 == V_7 -> V_55 &&
F_179 ( V_120 , V_44 -> V_120 ) )
goto V_77;
V_44 = F_43 ( & V_36 -> V_188 , struct V_186 , V_189 ) ;
F_174 ( V_82 -> V_72 ) ;
V_44 -> V_190 = 0 ;
V_77:
if ( V_44 -> V_190 + V_7 -> V_59 > V_44 -> V_190 )
V_44 -> V_190 += V_7 -> V_59 ;
V_44 -> V_78 = F_148 ( V_7 ) ;
V_44 -> V_120 = V_120 + F_180 ( 5000 ) ;
V_82 -> V_72 -> V_172 = V_44 -> V_190 ;
F_181 ( & V_44 -> V_191 ) ;
F_182 ( & V_44 -> V_191 , F_176 ( V_36 , V_44 -> V_78 ) ) ;
F_66 ( & V_44 -> V_189 , & V_36 -> V_188 ) ;
F_57 ( & V_36 -> V_187 ) ;
} else {
V_82 -> V_72 -> V_172 = V_7 -> V_59 ;
F_174 ( V_82 -> V_72 ) ;
}
V_81 = F_183 ( V_82 -> V_72 -> V_172 ,
V_82 -> V_72 -> V_171 ) >> 9 ;
if ( V_36 -> V_181 &&
V_81 >= V_36 -> V_181 >> 9 ) {
F_184 ( V_82 -> V_116 ) ;
goto V_99;
}
if ( V_167 && V_81 >= V_167 ) {
F_185 ( V_82 -> V_116 ) ;
goto V_99;
}
V_182:
F_186 ( V_57 , F_34 ( V_7 ) ) ;
return;
V_99:
F_187 ( V_82 , F_34 ( V_7 ) ) ;
V_82 -> V_53 . V_99 = true ;
}
static void F_188 ( struct V_192 * V_193 , struct V_7 * V_7 )
{
struct V_70 * V_82 ;
struct V_128 * V_45 = V_7 -> V_137 -> V_194 -> V_195 ;
struct V_35 * V_36 = F_2 ( V_45 , struct V_35 , V_122 ) ;
int V_117 , V_118 = F_107 ( V_7 ) ;
V_117 = F_108 () ;
F_189 ( V_117 , & V_45 -> V_122 -> V_123 , V_196 [ V_118 ] ) ;
F_110 ( V_117 , & V_45 -> V_122 -> V_123 , V_81 [ V_118 ] , F_34 ( V_7 ) ) ;
F_111 () ;
V_7 -> V_137 = V_36 -> V_163 ;
V_7 -> V_55 += V_36 -> V_38 . V_197 ;
if ( F_190 ( V_36 ) ) {
V_82 = F_119 ( V_7 , V_45 ) ;
F_191 ( V_82 , V_7 ) ;
if ( ! F_192 ( V_7 ) )
F_167 ( V_36 , V_82 ) ;
else if ( V_118 )
F_158 ( V_36 , V_82 ) ;
else
F_154 ( V_36 , V_82 ) ;
} else {
if ( ( V_7 -> V_101 & V_132 ) &&
! F_165 ( F_166 ( V_36 -> V_163 ) ) )
F_113 ( V_7 , 0 ) ;
else
F_193 ( V_7 , & V_45 -> V_198 ) ;
}
}
static int F_194 ( struct V_128 * V_45 , T_7 V_176 ,
unsigned int V_199 , unsigned long V_200 )
{
struct V_35 * V_36 = F_2 ( V_45 , struct V_35 , V_122 ) ;
return F_195 ( V_36 -> V_163 , V_176 , V_199 , V_200 ) ;
}
static int F_196 ( void * V_201 , int V_202 )
{
struct V_128 * V_45 = V_201 ;
struct V_35 * V_36 = F_2 ( V_45 , struct V_35 , V_122 ) ;
struct V_192 * V_193 = F_166 ( V_36 -> V_163 ) ;
int V_74 = 0 ;
if ( F_197 ( & V_193 -> V_203 , V_202 ) )
return 1 ;
if ( F_190 ( V_36 ) ) {
unsigned V_44 ;
struct V_204 * V_205 ;
F_198 (ca, d->c, i) {
V_193 = F_166 ( V_205 -> V_163 ) ;
V_74 |= F_197 ( & V_193 -> V_203 , V_202 ) ;
}
F_128 ( V_36 ) ;
}
return V_74 ;
}
void F_199 ( struct V_35 * V_36 )
{
struct V_206 * V_207 = V_36 -> V_122 . V_122 ;
V_207 -> V_208 -> V_209 = F_188 ;
V_207 -> V_208 -> V_203 . V_210 = F_196 ;
V_36 -> V_122 . V_136 = F_147 ;
V_36 -> V_122 . V_211 = F_194 ;
}
static int F_200 ( struct V_142 * V_66 , struct V_70 * V_82 ,
struct V_7 * V_7 , unsigned V_81 )
{
struct V_41 * V_42 ;
int V_44 ;
F_27 (bv, bio, i) {
unsigned V_212 = F_35 ( V_42 -> V_48 >> 9 , V_81 ) ;
void * V_213 = F_28 ( V_42 -> V_46 ) ;
memset ( V_213 + V_42 -> V_47 , 0 , V_212 << 9 ) ;
F_30 ( V_42 -> V_46 ) ;
V_81 -= V_212 ;
}
F_201 ( V_7 , F_35 ( V_81 << 9 , V_7 -> V_59 ) ) ;
if ( ! V_7 -> V_59 )
V_82 -> V_53 . V_145 = true ;
return 0 ;
}
static void F_202 ( struct V_192 * V_193 , struct V_7 * V_7 )
{
struct V_70 * V_82 ;
struct V_50 * V_51 ;
struct V_128 * V_45 = V_7 -> V_137 -> V_194 -> V_195 ;
int V_117 , V_118 = F_107 ( V_7 ) ;
V_117 = F_108 () ;
F_189 ( V_117 , & V_45 -> V_122 -> V_123 , V_196 [ V_118 ] ) ;
F_110 ( V_117 , & V_45 -> V_122 -> V_123 , V_81 [ V_118 ] , F_34 ( V_7 ) ) ;
F_111 () ;
V_82 = F_119 ( V_7 , V_45 ) ;
V_51 = & V_82 -> V_51 ;
V_7 = & V_82 -> V_7 . V_7 ;
F_191 ( V_82 , V_7 ) ;
if ( F_192 ( V_7 ) && ! V_118 ) {
F_142 ( & V_82 -> V_53 . V_51 , F_125 , NULL , V_51 ) ;
} else if ( F_192 ( V_7 ) || V_82 -> V_53 . V_99 ) {
F_159 ( & V_82 -> V_53 . V_57 -> V_160 ,
& F_38 ( V_45 -> V_129 , V_7 -> V_55 , 0 ) ,
& F_38 ( V_45 -> V_129 , F_148 ( V_7 ) , 0 ) ) ;
V_82 -> V_84 = true ;
V_82 -> V_53 . V_54 = V_7 ;
F_142 ( & V_82 -> V_53 . V_51 , F_96 , NULL , V_51 ) ;
} else {
if ( V_82 -> V_53 . V_131 )
F_168 ( V_82 -> V_53 . V_57 , V_51 ) ;
}
F_40 ( V_51 , F_116 , NULL ) ;
}
static int F_203 ( struct V_128 * V_45 , T_7 V_176 ,
unsigned int V_199 , unsigned long V_200 )
{
return - V_214 ;
}
static int F_204 ( void * V_201 , int V_202 )
{
struct V_128 * V_45 = V_201 ;
struct V_192 * V_193 ;
struct V_204 * V_205 ;
unsigned V_44 ;
int V_74 = 0 ;
F_198 (ca, d->c, i) {
V_193 = F_166 ( V_205 -> V_163 ) ;
V_74 |= F_197 ( & V_193 -> V_203 , V_202 ) ;
}
return V_74 ;
}
void F_205 ( struct V_128 * V_45 )
{
struct V_206 * V_207 = V_45 -> V_122 ;
V_207 -> V_208 -> V_209 = F_202 ;
V_207 -> V_208 -> V_203 . V_210 = F_204 ;
V_45 -> V_136 = F_200 ;
V_45 -> V_211 = F_203 ;
}
void F_206 ( void )
{
#ifdef F_24
F_207 ( & V_34 ) ;
#endif
if ( V_215 )
F_208 ( V_215 ) ;
}
int T_8 F_209 ( void )
{
V_215 = F_210 ( V_70 , 0 ) ;
if ( ! V_215 )
return - V_33 ;
#ifdef F_24
F_211 ( & V_34 ) ;
F_17 ( & V_6 ) ;
F_212 ( & V_34 , V_216 ) ;
#endif
return 0 ;
}
