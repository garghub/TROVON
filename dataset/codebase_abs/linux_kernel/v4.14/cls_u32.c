static inline unsigned int F_1 ( T_1 V_1 ,
const struct V_2 * V_3 ,
T_2 V_4 )
{
unsigned int V_5 = F_2 ( V_1 & V_3 -> V_6 ) >> V_4 ;
return V_5 ;
}
static int F_3 ( struct V_7 * V_8 , const struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct {
struct V_13 * V_14 ;
unsigned int V_15 ;
} V_16 [ V_17 ] ;
struct V_18 * V_19 = F_4 ( V_10 -> V_20 ) ;
unsigned int V_15 = F_5 ( V_8 ) ;
struct V_13 * V_21 ;
int V_22 = 0 ;
int V_23 = 0 ;
int V_3 = 0 ;
#ifdef F_6
int V_24 ;
#endif
int V_25 , V_26 ;
V_27:
V_21 = F_4 ( V_19 -> V_19 [ V_3 ] ) ;
V_28:
if ( V_21 ) {
struct V_29 * V_1 = V_21 -> V_3 . V_30 ;
#ifdef F_6
F_7 ( V_21 -> V_31 -> V_32 ) ;
V_24 = 0 ;
#endif
if ( F_8 ( V_21 -> V_33 ) ) {
V_21 = F_4 ( V_21 -> V_34 ) ;
goto V_28;
}
#ifdef F_9
if ( ( V_8 -> V_35 & V_21 -> V_36 ) != V_21 -> V_37 ) {
V_21 = F_4 ( V_21 -> V_34 ) ;
goto V_28;
} else {
F_7 ( * V_21 -> V_38 ) ;
}
#endif
for ( V_25 = V_21 -> V_3 . V_39 ; V_25 > 0 ; V_25 -- , V_1 ++ ) {
int V_40 = V_15 + V_1 -> V_15 + ( V_23 & V_1 -> V_41 ) ;
T_1 * V_42 , V_43 ;
if ( F_10 ( V_8 ) + V_40 > V_44 )
goto V_45;
V_42 = F_11 ( V_8 , V_40 , 4 , & V_43 ) ;
if ( ! V_42 )
goto V_45;
if ( ( * V_42 ^ V_1 -> V_37 ) & V_1 -> V_36 ) {
V_21 = F_4 ( V_21 -> V_34 ) ;
goto V_28;
}
#ifdef F_6
F_7 ( V_21 -> V_31 -> V_46 [ V_24 ] ) ;
V_24 ++ ;
#endif
}
V_19 = F_4 ( V_21 -> V_47 ) ;
if ( ! V_19 ) {
V_48:
if ( V_21 -> V_3 . V_33 & V_49 ) {
* V_12 = V_21 -> V_12 ;
#ifdef F_12
if ( ! F_13 ( V_8 , V_21 -> V_50 ) ) {
V_21 = F_4 ( V_21 -> V_34 ) ;
goto V_28;
}
#endif
#ifdef F_6
F_7 ( V_21 -> V_31 -> V_51 ) ;
#endif
V_26 = F_14 ( V_8 , & V_21 -> V_52 , V_12 ) ;
if ( V_26 < 0 ) {
V_21 = F_4 ( V_21 -> V_34 ) ;
goto V_28;
}
return V_26 ;
}
V_21 = F_4 ( V_21 -> V_34 ) ;
goto V_28;
}
if ( V_22 >= V_17 )
goto V_53;
V_16 [ V_22 ] . V_14 = V_21 ;
V_16 [ V_22 ] . V_15 = V_15 ;
V_22 ++ ;
V_19 = F_4 ( V_21 -> V_47 ) ;
V_3 = 0 ;
if ( V_19 -> V_54 ) {
T_1 * V_42 , V_43 ;
V_42 = F_11 ( V_8 , V_15 + V_21 -> V_3 . V_55 , 4 ,
& V_43 ) ;
if ( ! V_42 )
goto V_45;
V_3 = V_19 -> V_54 & F_1 ( * V_42 , & V_21 -> V_3 ,
V_21 -> V_4 ) ;
}
if ( ! ( V_21 -> V_3 . V_33 & ( V_56 | V_57 | V_58 ) ) )
goto V_27;
if ( V_21 -> V_3 . V_33 & ( V_57 | V_56 ) ) {
V_23 = V_21 -> V_3 . V_15 + 3 ;
if ( V_21 -> V_3 . V_33 & V_56 ) {
T_3 * V_42 , V_43 ;
V_42 = F_11 ( V_8 ,
V_15 + V_21 -> V_3 . V_59 ,
2 , & V_43 ) ;
if ( ! V_42 )
goto V_45;
V_23 += F_15 ( V_21 -> V_3 . V_41 & * V_42 ) >>
V_21 -> V_3 . V_60 ;
}
V_23 &= ~ 3 ;
}
if ( V_21 -> V_3 . V_33 & V_58 ) {
V_15 += V_23 ;
V_23 = 0 ;
}
if ( V_15 < V_8 -> V_61 )
goto V_27;
}
if ( V_22 -- ) {
V_21 = V_16 [ V_22 ] . V_14 ;
V_19 = F_4 ( V_21 -> V_62 ) ;
V_15 = V_16 [ V_22 ] . V_15 ;
goto V_48;
}
V_45:
return - 1 ;
V_53:
F_16 ( L_1 ) ;
return - 1 ;
}
static struct V_18 * F_17 ( struct V_63 * V_64 , T_4 V_65 )
{
struct V_18 * V_19 ;
for ( V_19 = F_18 ( V_64 -> V_66 ) ;
V_19 ;
V_19 = F_18 ( V_19 -> V_34 ) )
if ( V_19 -> V_65 == V_65 )
break;
return V_19 ;
}
static struct V_13 * F_19 ( struct V_18 * V_19 , T_4 V_65 )
{
unsigned int V_3 ;
struct V_13 * V_21 = NULL ;
V_3 = F_20 ( V_65 ) ;
if ( V_3 > V_19 -> V_54 )
goto V_45;
for ( V_21 = F_18 ( V_19 -> V_19 [ V_3 ] ) ;
V_21 ;
V_21 = F_18 ( V_21 -> V_34 ) )
if ( V_21 -> V_65 == V_65 )
break;
V_45:
return V_21 ;
}
static void * F_21 ( struct V_9 * V_10 , T_4 V_65 )
{
struct V_18 * V_19 ;
struct V_63 * V_64 = V_10 -> V_42 ;
if ( F_22 ( V_65 ) == V_67 )
V_19 = F_18 ( V_10 -> V_20 ) ;
else
V_19 = F_17 ( V_64 , F_22 ( V_65 ) ) ;
if ( ! V_19 )
return NULL ;
if ( F_23 ( V_65 ) == 0 )
return V_19 ;
return F_19 ( V_19 , V_65 ) ;
}
static T_4 F_24 ( struct V_63 * V_64 )
{
int V_25 = 0x800 ;
do {
if ( ++ V_64 -> V_68 == 0x7FF )
V_64 -> V_68 = 1 ;
} while ( -- V_25 > 0 && F_17 ( V_64 , ( V_64 -> V_68 | 0x800 ) << 20 ) );
return V_25 > 0 ? ( V_64 -> V_68 | 0x800 ) << 20 : 0 ;
}
static unsigned int F_25 ( const struct V_9 * V_10 )
{
struct V_69 * V_70 = V_10 -> V_71 -> V_72 -> V_70 ;
T_4 V_73 = V_10 -> V_71 -> V_65 ;
int V_50 = V_70 -> V_50 ;
return F_26 ( ( V_74 ) V_50 << 32 | V_73 , V_75 ) ;
}
static struct V_63 * F_27 ( const struct V_9 * V_10 )
{
struct V_63 * V_76 ;
unsigned int V_5 ;
V_5 = F_25 ( V_10 ) ;
F_28 (tc, &tc_u_common_hash[h], hnode) {
if ( V_76 -> V_71 == V_10 -> V_71 )
return V_76 ;
}
return NULL ;
}
static int F_29 ( struct V_9 * V_10 )
{
struct V_18 * V_77 ;
struct V_63 * V_64 ;
unsigned int V_5 ;
V_64 = F_27 ( V_10 ) ;
V_77 = F_30 ( sizeof( * V_77 ) , V_78 ) ;
if ( V_77 == NULL )
return - V_79 ;
V_77 -> V_80 ++ ;
V_77 -> V_65 = V_64 ? F_24 ( V_64 ) : 0x80000000 ;
V_77 -> V_81 = V_10 -> V_81 ;
if ( V_64 == NULL ) {
V_64 = F_30 ( sizeof( * V_64 ) , V_78 ) ;
if ( V_64 == NULL ) {
F_31 ( V_77 ) ;
return - V_79 ;
}
V_64 -> V_71 = V_10 -> V_71 ;
F_32 ( & V_64 -> V_82 ) ;
V_5 = F_25 ( V_10 ) ;
F_33 ( & V_64 -> V_82 , & V_83 [ V_5 ] ) ;
}
V_64 -> V_80 ++ ;
F_34 ( V_77 -> V_34 , V_64 -> V_66 ) ;
F_35 ( V_64 -> V_66 , V_77 ) ;
V_77 -> V_64 = V_64 ;
F_35 ( V_10 -> V_20 , V_77 ) ;
V_10 -> V_42 = V_64 ;
return 0 ;
}
static int F_36 ( struct V_9 * V_10 , struct V_13 * V_21 ,
bool V_84 )
{
F_37 ( & V_21 -> V_52 ) ;
F_38 ( & V_21 -> V_52 ) ;
if ( V_21 -> V_47 )
V_21 -> V_47 -> V_80 -- ;
#ifdef F_6
if ( V_84 )
F_39 ( V_21 -> V_31 ) ;
#endif
#ifdef F_9
if ( V_84 )
F_39 ( V_21 -> V_38 ) ;
#endif
F_31 ( V_21 ) ;
return 0 ;
}
static void F_40 ( struct V_85 * V_86 )
{
struct V_13 * V_1 = F_41 ( V_86 , struct V_13 , V_86 ) ;
F_42 () ;
F_36 ( V_1 -> V_10 , V_1 , false ) ;
F_43 () ;
}
static void F_44 ( struct V_87 * V_88 )
{
struct V_13 * V_1 = F_41 ( V_88 , struct V_13 , V_88 ) ;
F_45 ( & V_1 -> V_86 , F_40 ) ;
F_46 ( & V_1 -> V_86 ) ;
}
static void F_47 ( struct V_85 * V_86 )
{
struct V_13 * V_1 = F_41 ( V_86 , struct V_13 , V_86 ) ;
F_42 () ;
F_36 ( V_1 -> V_10 , V_1 , true ) ;
F_43 () ;
}
static void F_48 ( struct V_87 * V_88 )
{
struct V_13 * V_1 = F_41 ( V_88 , struct V_13 , V_88 ) ;
F_45 ( & V_1 -> V_86 , F_47 ) ;
F_46 ( & V_1 -> V_86 ) ;
}
static int F_49 ( struct V_9 * V_10 , struct V_13 * V_1 )
{
struct V_13 T_5 * * V_89 ;
struct V_13 * V_90 ;
struct V_18 * V_19 = F_18 ( V_1 -> V_62 ) ;
if ( V_19 ) {
V_89 = & V_19 -> V_19 [ F_20 ( V_1 -> V_65 ) ] ;
for ( V_90 = F_18 ( * V_89 ) ; V_90 ;
V_89 = & V_90 -> V_34 , V_90 = F_18 ( * V_89 ) ) {
if ( V_90 == V_1 ) {
F_34 ( * V_89 , V_1 -> V_34 ) ;
F_50 ( V_10 , & V_1 -> V_12 ) ;
F_51 ( & V_1 -> V_52 ) ;
F_52 ( & V_1 -> V_88 , F_48 ) ;
return 0 ;
}
}
}
F_53 ( 1 ) ;
return 0 ;
}
static void F_54 ( struct V_9 * V_10 , T_4 V_65 )
{
struct V_69 * V_70 = V_10 -> V_71 -> V_72 -> V_70 ;
struct V_91 V_92 = {} ;
if ( ! F_55 ( V_70 , 0 ) )
return;
F_56 ( & V_92 . V_93 , V_10 ) ;
V_92 . V_94 = V_95 ;
V_92 . V_14 . V_65 = V_65 ;
V_70 -> V_96 -> V_97 ( V_70 , V_98 , & V_92 ) ;
}
static int F_57 ( struct V_9 * V_10 , struct V_18 * V_5 ,
T_4 V_33 )
{
struct V_69 * V_70 = V_10 -> V_71 -> V_72 -> V_70 ;
struct V_91 V_92 = {} ;
int V_99 ;
if ( ! F_55 ( V_70 , V_33 ) )
return F_8 ( V_33 ) ? - V_100 : 0 ;
F_56 ( & V_92 . V_93 , V_10 ) ;
V_92 . V_94 = V_101 ;
V_92 . V_82 . V_54 = V_5 -> V_54 ;
V_92 . V_82 . V_65 = V_5 -> V_65 ;
V_92 . V_82 . V_81 = V_5 -> V_81 ;
V_99 = V_70 -> V_96 -> V_97 ( V_70 , V_98 , & V_92 ) ;
if ( F_8 ( V_33 ) )
return V_99 ;
return 0 ;
}
static void F_58 ( struct V_9 * V_10 , struct V_18 * V_5 )
{
struct V_69 * V_70 = V_10 -> V_71 -> V_72 -> V_70 ;
struct V_91 V_92 = {} ;
if ( ! F_55 ( V_70 , 0 ) )
return;
F_56 ( & V_92 . V_93 , V_10 ) ;
V_92 . V_94 = V_102 ;
V_92 . V_82 . V_54 = V_5 -> V_54 ;
V_92 . V_82 . V_65 = V_5 -> V_65 ;
V_92 . V_82 . V_81 = V_5 -> V_81 ;
V_70 -> V_96 -> V_97 ( V_70 , V_98 , & V_92 ) ;
}
static int F_59 ( struct V_9 * V_10 , struct V_13 * V_21 ,
T_4 V_33 )
{
struct V_69 * V_70 = V_10 -> V_71 -> V_72 -> V_70 ;
struct V_91 V_92 = {} ;
int V_99 ;
if ( ! F_55 ( V_70 , V_33 ) )
return F_8 ( V_33 ) ? - V_100 : 0 ;
F_56 ( & V_92 . V_93 , V_10 ) ;
V_92 . V_94 = V_103 ;
V_92 . V_14 . V_65 = V_21 -> V_65 ;
V_92 . V_14 . V_4 = V_21 -> V_4 ;
#ifdef F_9
V_92 . V_14 . V_37 = V_21 -> V_37 ;
V_92 . V_14 . V_36 = V_21 -> V_36 ;
#else
V_92 . V_14 . V_37 = 0 ;
V_92 . V_14 . V_36 = 0 ;
#endif
V_92 . V_14 . V_3 = & V_21 -> V_3 ;
V_92 . V_14 . V_52 = & V_21 -> V_52 ;
if ( V_21 -> V_47 )
V_92 . V_14 . V_104 = V_21 -> V_47 -> V_65 ;
V_99 = V_70 -> V_96 -> V_97 ( V_70 , V_98 , & V_92 ) ;
if ( ! V_99 )
V_21 -> V_33 |= V_105 ;
if ( F_8 ( V_33 ) )
return V_99 ;
return 0 ;
}
static void F_60 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_13 * V_21 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ ) {
while ( ( V_21 = F_18 ( V_19 -> V_19 [ V_5 ] ) ) != NULL ) {
F_34 ( V_19 -> V_19 [ V_5 ] ,
F_18 ( V_21 -> V_34 ) ) ;
F_50 ( V_10 , & V_21 -> V_12 ) ;
F_54 ( V_10 , V_21 -> V_65 ) ;
if ( F_51 ( & V_21 -> V_52 ) )
F_52 ( & V_21 -> V_88 , F_48 ) ;
else
F_36 ( V_21 -> V_10 , V_21 , true ) ;
}
}
}
static int F_61 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_63 * V_64 = V_10 -> V_42 ;
struct V_18 T_5 * * V_106 ;
struct V_18 * V_107 ;
F_53 ( V_19 -> V_80 ) ;
F_60 ( V_10 , V_19 ) ;
V_106 = & V_64 -> V_66 ;
for ( V_107 = F_18 ( * V_106 ) ;
V_107 ;
V_106 = & V_107 -> V_34 , V_107 = F_18 ( * V_106 ) ) {
if ( V_107 == V_19 ) {
F_58 ( V_10 , V_19 ) ;
F_34 ( * V_106 , V_19 -> V_34 ) ;
F_62 ( V_19 , V_88 ) ;
return 0 ;
}
}
return - V_108 ;
}
static bool F_63 ( struct V_18 * V_19 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ )
if ( F_64 ( V_19 -> V_19 [ V_5 ] ) )
return false ;
return true ;
}
static void F_65 ( struct V_9 * V_10 )
{
struct V_63 * V_64 = V_10 -> V_42 ;
struct V_18 * V_77 = F_18 ( V_10 -> V_20 ) ;
F_53 ( V_77 == NULL ) ;
if ( V_77 && -- V_77 -> V_80 == 0 )
F_61 ( V_10 , V_77 ) ;
if ( -- V_64 -> V_80 == 0 ) {
struct V_18 * V_19 ;
F_66 ( & V_64 -> V_82 ) ;
for ( V_19 = F_18 ( V_64 -> V_66 ) ;
V_19 ;
V_19 = F_18 ( V_19 -> V_34 ) ) {
V_19 -> V_80 -- ;
F_60 ( V_10 , V_19 ) ;
}
while ( ( V_19 = F_18 ( V_64 -> V_66 ) ) != NULL ) {
F_34 ( V_64 -> V_66 , V_19 -> V_34 ) ;
F_62 ( V_19 , V_88 ) ;
}
F_31 ( V_64 ) ;
}
V_10 -> V_42 = NULL ;
}
static int F_67 ( struct V_9 * V_10 , void * V_109 , bool * V_110 )
{
struct V_18 * V_19 = V_109 ;
struct V_18 * V_77 = F_18 ( V_10 -> V_20 ) ;
struct V_63 * V_64 = V_10 -> V_42 ;
int V_111 = 0 ;
if ( V_19 == NULL )
goto V_45;
if ( F_23 ( V_19 -> V_65 ) ) {
F_54 ( V_10 , V_19 -> V_65 ) ;
V_111 = F_49 ( V_10 , (struct V_13 * ) V_19 ) ;
goto V_45;
}
if ( V_77 == V_19 )
return - V_100 ;
if ( V_19 -> V_80 == 1 ) {
V_19 -> V_80 -- ;
F_61 ( V_10 , V_19 ) ;
} else {
return - V_112 ;
}
V_45:
* V_110 = true ;
if ( V_77 ) {
if ( V_77 -> V_80 > 1 ) {
* V_110 = false ;
goto V_111;
}
if ( V_77 -> V_80 == 1 ) {
if ( ! F_63 ( V_77 ) ) {
* V_110 = false ;
goto V_111;
}
}
}
if ( V_64 -> V_80 > 1 ) {
* V_110 = false ;
goto V_111;
}
if ( V_64 -> V_80 == 1 ) {
struct V_18 * V_19 ;
for ( V_19 = F_18 ( V_64 -> V_66 ) ;
V_19 ;
V_19 = F_18 ( V_19 -> V_34 ) )
if ( ! F_63 ( V_19 ) ) {
* V_110 = false ;
break;
}
}
V_111:
return V_111 ;
}
static T_4 F_68 ( struct V_18 * V_19 , T_4 V_65 )
{
struct V_13 * V_21 ;
unsigned long V_25 ;
unsigned long * V_113 = F_30 ( F_69 ( V_114 ) * sizeof( unsigned long ) ,
V_78 ) ;
if ( ! V_113 )
return V_65 | 0xFFF ;
for ( V_21 = F_18 ( V_19 -> V_19 [ F_20 ( V_65 ) ] ) ;
V_21 ;
V_21 = F_18 ( V_21 -> V_34 ) )
F_70 ( F_71 ( V_21 -> V_65 ) , V_113 ) ;
V_25 = F_72 ( V_113 , V_114 , 0x800 ) ;
if ( V_25 >= V_114 )
V_25 = F_72 ( V_113 , V_114 , 1 ) ;
F_31 ( V_113 ) ;
return V_65 | ( V_25 >= V_114 ? 0xFFF : V_25 ) ;
}
static int F_73 ( struct V_115 * V_115 , struct V_9 * V_10 ,
unsigned long V_116 , struct V_18 * V_19 ,
struct V_13 * V_21 , struct V_117 * * V_118 ,
struct V_117 * V_119 , bool V_120 )
{
int V_99 ;
V_99 = F_74 ( V_115 , V_10 , V_118 , V_119 , & V_21 -> V_52 , V_120 ) ;
if ( V_99 < 0 )
return V_99 ;
if ( V_118 [ V_121 ] ) {
T_4 V_65 = F_75 ( V_118 [ V_121 ] ) ;
struct V_18 * V_47 = NULL , * V_122 ;
if ( F_23 ( V_65 ) )
return - V_100 ;
if ( V_65 ) {
V_47 = F_17 ( V_19 -> V_64 , V_65 ) ;
if ( V_47 == NULL )
return - V_100 ;
V_47 -> V_80 ++ ;
}
V_122 = F_18 ( V_21 -> V_47 ) ;
F_35 ( V_21 -> V_47 , V_47 ) ;
if ( V_122 )
V_122 -> V_80 -- ;
}
if ( V_118 [ V_123 ] ) {
V_21 -> V_12 . V_124 = F_75 ( V_118 [ V_123 ] ) ;
F_76 ( V_10 , & V_21 -> V_12 , V_116 ) ;
}
#ifdef F_12
if ( V_118 [ V_125 ] ) {
int V_111 ;
V_111 = F_77 ( V_115 , V_118 [ V_125 ] ) ;
if ( V_111 < 0 )
return - V_100 ;
V_21 -> V_50 = V_111 ;
}
#endif
return 0 ;
}
static void F_78 ( struct V_9 * V_10 , struct V_63 * V_64 ,
struct V_13 * V_21 )
{
struct V_13 T_5 * * V_126 ;
struct V_13 * V_127 ;
struct V_18 * V_19 ;
if ( F_22 ( V_21 -> V_65 ) == V_67 )
V_19 = F_18 ( V_10 -> V_20 ) ;
else
V_19 = F_17 ( V_64 , F_22 ( V_21 -> V_65 ) ) ;
V_126 = & V_19 -> V_19 [ F_20 ( V_21 -> V_65 ) ] ;
for ( V_127 = F_18 ( * V_126 ) ; ;
V_126 = & V_127 -> V_34 , V_127 = F_18 ( * V_126 ) )
if ( V_127 -> V_65 == V_21 -> V_65 )
break;
F_34 ( V_21 -> V_34 , V_127 -> V_34 ) ;
F_35 ( * V_126 , V_21 ) ;
}
static struct V_13 * F_79 ( struct V_9 * V_10 ,
struct V_13 * V_21 )
{
struct V_13 * V_128 ;
struct V_2 * V_129 = & V_21 -> V_3 ;
V_128 = F_30 ( sizeof( * V_21 ) + V_129 -> V_39 * sizeof( struct V_29 ) ,
V_78 ) ;
if ( ! V_128 )
return NULL ;
F_34 ( V_128 -> V_34 , V_21 -> V_34 ) ;
V_128 -> V_65 = V_21 -> V_65 ;
F_34 ( V_128 -> V_62 , V_21 -> V_62 ) ;
#ifdef F_12
V_128 -> V_50 = V_21 -> V_50 ;
#endif
V_128 -> V_4 = V_21 -> V_4 ;
V_128 -> V_12 = V_21 -> V_12 ;
V_128 -> V_33 = V_21 -> V_33 ;
F_34 ( V_128 -> V_47 , V_21 -> V_47 ) ;
if ( V_128 -> V_47 )
V_128 -> V_47 -> V_80 ++ ;
#ifdef F_6
V_128 -> V_31 = V_21 -> V_31 ;
#endif
#ifdef F_9
V_128 -> V_37 = V_21 -> V_37 ;
V_128 -> V_36 = V_21 -> V_36 ;
V_128 -> V_38 = V_21 -> V_38 ;
#endif
V_128 -> V_10 = V_10 ;
memcpy ( & V_128 -> V_3 , V_129 , sizeof( * V_129 ) + V_129 -> V_39 * sizeof( struct V_29 ) ) ;
if ( F_80 ( & V_128 -> V_52 , V_130 , V_131 ) ) {
F_31 ( V_128 ) ;
return NULL ;
}
return V_128 ;
}
static int F_81 ( struct V_115 * V_115 , struct V_7 * V_132 ,
struct V_9 * V_10 , unsigned long V_116 , T_4 V_65 ,
struct V_117 * * V_133 , void * * V_109 , bool V_120 )
{
struct V_63 * V_64 = V_10 -> V_42 ;
struct V_18 * V_19 ;
struct V_13 * V_21 ;
struct V_2 * V_129 ;
struct V_117 * V_134 = V_133 [ V_135 ] ;
struct V_117 * V_118 [ V_136 + 1 ] ;
T_4 V_137 , V_33 = 0 ;
int V_99 ;
#ifdef F_6
T_6 V_138 ;
#endif
if ( V_134 == NULL )
return V_65 ? - V_100 : 0 ;
V_99 = F_82 ( V_118 , V_136 , V_134 , V_139 , NULL ) ;
if ( V_99 < 0 )
return V_99 ;
if ( V_118 [ V_140 ] ) {
V_33 = F_75 ( V_118 [ V_140 ] ) ;
if ( ! F_83 ( V_33 ) )
return - V_100 ;
}
V_21 = * V_109 ;
if ( V_21 ) {
struct V_13 * V_128 ;
if ( F_23 ( V_21 -> V_65 ) == 0 )
return - V_100 ;
if ( V_21 -> V_33 != V_33 )
return - V_100 ;
V_128 = F_79 ( V_10 , V_21 ) ;
if ( ! V_128 )
return - V_141 ;
V_99 = F_73 ( V_115 , V_10 , V_116 ,
F_18 ( V_21 -> V_62 ) , V_128 , V_118 ,
V_133 [ V_142 ] , V_120 ) ;
if ( V_99 ) {
F_36 ( V_10 , V_128 , false ) ;
return V_99 ;
}
V_99 = F_59 ( V_10 , V_128 , V_33 ) ;
if ( V_99 ) {
F_36 ( V_10 , V_128 , false ) ;
return V_99 ;
}
if ( ! F_84 ( V_128 -> V_33 ) )
V_128 -> V_33 |= V_143 ;
F_78 ( V_10 , V_64 , V_128 ) ;
F_50 ( V_10 , & V_21 -> V_12 ) ;
F_51 ( & V_21 -> V_52 ) ;
F_52 ( & V_21 -> V_88 , F_44 ) ;
return 0 ;
}
if ( V_118 [ V_144 ] ) {
unsigned int V_54 = F_75 ( V_118 [ V_144 ] ) ;
if ( -- V_54 > 0x100 )
return - V_100 ;
if ( F_23 ( V_65 ) )
return - V_100 ;
if ( V_65 == 0 ) {
V_65 = F_24 ( V_10 -> V_42 ) ;
if ( V_65 == 0 )
return - V_141 ;
}
V_19 = F_30 ( sizeof( * V_19 ) + V_54 * sizeof( void * ) , V_78 ) ;
if ( V_19 == NULL )
return - V_79 ;
V_19 -> V_64 = V_64 ;
V_19 -> V_80 = 1 ;
V_19 -> V_54 = V_54 ;
V_19 -> V_65 = V_65 ;
V_19 -> V_81 = V_10 -> V_81 ;
V_99 = F_57 ( V_10 , V_19 , V_33 ) ;
if ( V_99 ) {
F_31 ( V_19 ) ;
return V_99 ;
}
F_34 ( V_19 -> V_34 , V_64 -> V_66 ) ;
F_35 ( V_64 -> V_66 , V_19 ) ;
* V_109 = V_19 ;
return 0 ;
}
if ( V_118 [ V_145 ] ) {
V_137 = F_75 ( V_118 [ V_145 ] ) ;
if ( F_22 ( V_137 ) == V_67 ) {
V_19 = F_18 ( V_10 -> V_20 ) ;
V_137 = V_19 -> V_65 ;
} else {
V_19 = F_17 ( V_10 -> V_42 , F_22 ( V_137 ) ) ;
if ( V_19 == NULL )
return - V_100 ;
}
} else {
V_19 = F_18 ( V_10 -> V_20 ) ;
V_137 = V_19 -> V_65 ;
}
if ( V_19 -> V_54 < F_20 ( V_137 ) )
return - V_100 ;
if ( V_65 ) {
if ( F_22 ( V_65 ) && F_22 ( V_65 ^ V_137 ) )
return - V_100 ;
V_65 = V_137 | F_71 ( V_65 ) ;
} else
V_65 = F_68 ( V_19 , V_137 ) ;
if ( V_118 [ V_146 ] == NULL )
return - V_100 ;
V_129 = F_85 ( V_118 [ V_146 ] ) ;
V_21 = F_30 ( sizeof( * V_21 ) + V_129 -> V_39 * sizeof( struct V_29 ) , V_78 ) ;
if ( V_21 == NULL )
return - V_79 ;
#ifdef F_6
V_138 = sizeof( struct V_147 ) + V_129 -> V_39 * sizeof( V_74 ) ;
V_21 -> V_31 = F_86 ( V_138 , F_87 ( struct V_147 ) ) ;
if ( ! V_21 -> V_31 ) {
F_31 ( V_21 ) ;
return - V_79 ;
}
#endif
memcpy ( & V_21 -> V_3 , V_129 , sizeof( * V_129 ) + V_129 -> V_39 * sizeof( struct V_29 ) ) ;
F_34 ( V_21 -> V_62 , V_19 ) ;
V_21 -> V_65 = V_65 ;
V_21 -> V_4 = V_129 -> V_6 ? F_88 ( F_2 ( V_129 -> V_6 ) ) - 1 : 0 ;
V_21 -> V_33 = V_33 ;
V_21 -> V_10 = V_10 ;
V_99 = F_80 ( & V_21 -> V_52 , V_130 , V_131 ) ;
if ( V_99 < 0 )
goto V_148;
#ifdef F_9
V_21 -> V_38 = F_89 ( T_4 ) ;
if ( ! V_21 -> V_38 ) {
V_99 = - V_141 ;
goto V_148;
}
if ( V_118 [ V_149 ] ) {
struct V_150 * V_35 ;
V_35 = F_85 ( V_118 [ V_149 ] ) ;
V_21 -> V_37 = V_35 -> V_37 ;
V_21 -> V_36 = V_35 -> V_36 ;
}
#endif
V_99 = F_73 ( V_115 , V_10 , V_116 , V_19 , V_21 , V_118 , V_133 [ V_142 ] , V_120 ) ;
if ( V_99 == 0 ) {
struct V_13 T_5 * * V_126 ;
struct V_13 * V_127 ;
V_99 = F_59 ( V_10 , V_21 , V_33 ) ;
if ( V_99 )
goto V_151;
if ( ! F_84 ( V_21 -> V_33 ) )
V_21 -> V_33 |= V_143 ;
V_126 = & V_19 -> V_19 [ F_20 ( V_65 ) ] ;
for ( V_127 = F_18 ( * V_126 ) ; V_127 ;
V_126 = & V_127 -> V_34 , V_127 = F_18 ( * V_126 ) )
if ( F_71 ( V_65 ) < F_71 ( V_127 -> V_65 ) )
break;
F_34 ( V_21 -> V_34 , V_127 ) ;
F_35 ( * V_126 , V_21 ) ;
* V_109 = V_21 ;
return 0 ;
}
V_151:
#ifdef F_9
F_39 ( V_21 -> V_38 ) ;
#endif
V_148:
F_37 ( & V_21 -> V_52 ) ;
#ifdef F_6
F_39 ( V_21 -> V_31 ) ;
#endif
F_31 ( V_21 ) ;
return V_99 ;
}
static void F_90 ( struct V_9 * V_10 , struct V_152 * V_109 )
{
struct V_63 * V_64 = V_10 -> V_42 ;
struct V_18 * V_19 ;
struct V_13 * V_21 ;
unsigned int V_5 ;
if ( V_109 -> V_153 )
return;
for ( V_19 = F_18 ( V_64 -> V_66 ) ;
V_19 ;
V_19 = F_18 ( V_19 -> V_34 ) ) {
if ( V_19 -> V_81 != V_10 -> V_81 )
continue;
if ( V_109 -> V_154 >= V_109 -> V_155 ) {
if ( V_109 -> V_156 ( V_10 , V_19 , V_109 ) < 0 ) {
V_109 -> V_153 = 1 ;
return;
}
}
V_109 -> V_154 ++ ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ ) {
for ( V_21 = F_18 ( V_19 -> V_19 [ V_5 ] ) ;
V_21 ;
V_21 = F_18 ( V_21 -> V_34 ) ) {
if ( V_109 -> V_154 < V_109 -> V_155 ) {
V_109 -> V_154 ++ ;
continue;
}
if ( V_109 -> V_156 ( V_10 , V_21 , V_109 ) < 0 ) {
V_109 -> V_153 = 1 ;
return;
}
V_109 -> V_154 ++ ;
}
}
}
}
static void F_91 ( void * V_157 , T_4 V_124 , unsigned long V_158 )
{
struct V_13 * V_21 = V_157 ;
if ( V_21 && V_21 -> V_12 . V_124 == V_124 )
V_21 -> V_12 . V_159 = V_158 ;
}
static int F_92 ( struct V_115 * V_115 , struct V_9 * V_10 , void * V_157 ,
struct V_7 * V_8 , struct V_160 * V_161 )
{
struct V_13 * V_21 = V_157 ;
struct V_18 * V_62 , * V_47 ;
struct V_117 * V_162 ;
if ( V_21 == NULL )
return V_8 -> V_61 ;
V_161 -> V_163 = V_21 -> V_65 ;
V_162 = F_93 ( V_8 , V_135 ) ;
if ( V_162 == NULL )
goto V_164;
if ( F_23 ( V_21 -> V_65 ) == 0 ) {
struct V_18 * V_19 = V_157 ;
T_4 V_54 = V_19 -> V_54 + 1 ;
if ( F_94 ( V_8 , V_144 , V_54 ) )
goto V_164;
} else {
#ifdef F_6
struct V_147 * V_165 ;
int V_166 ;
#endif
if ( F_95 ( V_8 , V_146 ,
sizeof( V_21 -> V_3 ) + V_21 -> V_3 . V_39 * sizeof( struct V_29 ) ,
& V_21 -> V_3 ) )
goto V_164;
V_62 = F_18 ( V_21 -> V_62 ) ;
if ( V_62 ) {
T_4 V_137 = V_21 -> V_65 & 0xFFFFF000 ;
if ( F_94 ( V_8 , V_145 , V_137 ) )
goto V_164;
}
if ( V_21 -> V_12 . V_124 &&
F_94 ( V_8 , V_123 , V_21 -> V_12 . V_124 ) )
goto V_164;
V_47 = F_18 ( V_21 -> V_47 ) ;
if ( V_47 &&
F_94 ( V_8 , V_121 , V_47 -> V_65 ) )
goto V_164;
if ( V_21 -> V_33 && F_94 ( V_8 , V_140 , V_21 -> V_33 ) )
goto V_164;
#ifdef F_9
if ( ( V_21 -> V_37 || V_21 -> V_36 ) ) {
struct V_150 V_35 = { . V_37 = V_21 -> V_37 ,
. V_36 = V_21 -> V_36 ,
. V_167 = 0 } ;
int V_168 ;
F_96 (cpum) {
T_7 V_169 = * F_97 ( V_21 -> V_38 , V_168 ) ;
V_35 . V_167 += V_169 ;
}
if ( F_95 ( V_8 , V_149 , sizeof( V_35 ) , & V_35 ) )
goto V_164;
}
#endif
if ( F_98 ( V_8 , & V_21 -> V_52 ) < 0 )
goto V_164;
#ifdef F_12
if ( V_21 -> V_50 ) {
struct V_69 * V_70 ;
V_70 = F_99 ( V_115 , V_21 -> V_50 ) ;
if ( V_70 && F_100 ( V_8 , V_125 , V_70 -> V_170 ) )
goto V_164;
}
#endif
#ifdef F_6
V_165 = F_30 ( sizeof( struct V_147 ) +
V_21 -> V_3 . V_39 * sizeof( V_74 ) ,
V_78 ) ;
if ( ! V_165 )
goto V_164;
F_96 (cpu) {
int V_25 ;
struct V_147 * V_31 = F_97 ( V_21 -> V_31 , V_166 ) ;
V_165 -> V_32 += V_31 -> V_32 ;
V_165 -> V_51 += V_31 -> V_51 ;
for ( V_25 = 0 ; V_25 < V_21 -> V_3 . V_39 ; V_25 ++ )
V_165 -> V_46 [ V_25 ] += V_31 -> V_46 [ V_25 ] ;
}
if ( F_101 ( V_8 , V_171 ,
sizeof( struct V_147 ) +
V_21 -> V_3 . V_39 * sizeof( V_74 ) ,
V_165 , V_172 ) ) {
F_31 ( V_165 ) ;
goto V_164;
}
F_31 ( V_165 ) ;
#endif
}
F_102 ( V_8 , V_162 ) ;
if ( F_23 ( V_21 -> V_65 ) )
if ( F_103 ( V_8 , & V_21 -> V_52 ) < 0 )
goto V_164;
return V_8 -> V_61 ;
V_164:
F_104 ( V_8 , V_162 ) ;
return - 1 ;
}
static int T_8 F_105 ( void )
{
int V_25 , V_111 ;
F_106 ( L_2 ) ;
#ifdef F_6
F_106 ( L_3 ) ;
#endif
#ifdef F_12
F_106 ( L_4 ) ;
#endif
#ifdef F_107
F_106 ( L_5 ) ;
#endif
V_83 = F_108 ( V_173 ,
sizeof( struct V_174 ) ,
V_78 ) ;
if ( ! V_83 )
return - V_141 ;
for ( V_25 = 0 ; V_25 < V_173 ; V_25 ++ )
F_109 ( & V_83 [ V_25 ] ) ;
V_111 = F_110 ( & V_175 ) ;
if ( V_111 )
F_111 ( V_83 ) ;
return V_111 ;
}
static void T_9 F_112 ( void )
{
F_113 ( & V_175 ) ;
F_111 ( V_83 ) ;
}
