static inline unsigned int F_1 ( T_1 V_1 ,
const struct V_2 * V_3 ,
T_2 V_4 )
{
unsigned int V_5 = F_2 ( V_1 & V_3 -> V_6 ) >> V_4 ;
return V_5 ;
}
static int F_3 ( struct V_7 * V_8 , const struct V_9 * V_10 , struct V_11 * V_12 )
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
#ifdef F_8
if ( ( V_8 -> V_33 & V_21 -> V_34 ) != V_21 -> V_35 ) {
V_21 = F_4 ( V_21 -> V_36 ) ;
goto V_28;
} else {
F_7 ( * V_21 -> V_37 ) ;
}
#endif
for ( V_25 = V_21 -> V_3 . V_38 ; V_25 > 0 ; V_25 -- , V_1 ++ ) {
int V_39 = V_15 + V_1 -> V_15 + ( V_23 & V_1 -> V_40 ) ;
T_1 * V_41 , V_42 ;
if ( F_9 ( V_8 ) + V_39 > V_43 )
goto V_44;
V_41 = F_10 ( V_8 , V_39 , 4 , & V_42 ) ;
if ( ! V_41 )
goto V_44;
if ( ( * V_41 ^ V_1 -> V_35 ) & V_1 -> V_34 ) {
V_21 = F_4 ( V_21 -> V_36 ) ;
goto V_28;
}
#ifdef F_6
F_7 ( V_21 -> V_31 -> V_45 [ V_24 ] ) ;
V_24 ++ ;
#endif
}
V_19 = F_4 ( V_21 -> V_46 ) ;
if ( ! V_19 ) {
V_47:
if ( V_21 -> V_3 . V_48 & V_49 ) {
* V_12 = V_21 -> V_12 ;
#ifdef F_11
if ( ! F_12 ( V_8 , V_21 -> V_50 ) ) {
V_21 = F_4 ( V_21 -> V_36 ) ;
goto V_28;
}
#endif
#ifdef F_6
F_7 ( V_21 -> V_31 -> V_51 ) ;
#endif
V_26 = F_13 ( V_8 , & V_21 -> V_52 , V_12 ) ;
if ( V_26 < 0 ) {
V_21 = F_4 ( V_21 -> V_36 ) ;
goto V_28;
}
return V_26 ;
}
V_21 = F_4 ( V_21 -> V_36 ) ;
goto V_28;
}
if ( V_22 >= V_17 )
goto V_53;
V_16 [ V_22 ] . V_14 = V_21 ;
V_16 [ V_22 ] . V_15 = V_15 ;
V_22 ++ ;
V_19 = F_4 ( V_21 -> V_46 ) ;
V_3 = 0 ;
if ( V_19 -> V_54 ) {
T_1 * V_41 , V_42 ;
V_41 = F_10 ( V_8 , V_15 + V_21 -> V_3 . V_55 , 4 ,
& V_42 ) ;
if ( ! V_41 )
goto V_44;
V_3 = V_19 -> V_54 & F_1 ( * V_41 , & V_21 -> V_3 ,
V_21 -> V_4 ) ;
}
if ( ! ( V_21 -> V_3 . V_48 & ( V_56 | V_57 | V_58 ) ) )
goto V_27;
if ( V_21 -> V_3 . V_48 & ( V_57 | V_56 ) ) {
V_23 = V_21 -> V_3 . V_15 + 3 ;
if ( V_21 -> V_3 . V_48 & V_56 ) {
T_3 * V_41 , V_42 ;
V_41 = F_10 ( V_8 ,
V_15 + V_21 -> V_3 . V_59 ,
2 , & V_42 ) ;
if ( ! V_41 )
goto V_44;
V_23 += F_14 ( V_21 -> V_3 . V_40 & * V_41 ) >>
V_21 -> V_3 . V_60 ;
}
V_23 &= ~ 3 ;
}
if ( V_21 -> V_3 . V_48 & V_58 ) {
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
goto V_47;
}
V_44:
return - 1 ;
V_53:
F_15 ( L_1 ) ;
return - 1 ;
}
static struct V_18 *
F_16 ( struct V_63 * V_64 , T_4 V_65 )
{
struct V_18 * V_19 ;
for ( V_19 = F_17 ( V_64 -> V_66 ) ;
V_19 ;
V_19 = F_17 ( V_19 -> V_36 ) )
if ( V_19 -> V_65 == V_65 )
break;
return V_19 ;
}
static struct V_13 *
F_18 ( struct V_18 * V_19 , T_4 V_65 )
{
unsigned int V_3 ;
struct V_13 * V_21 = NULL ;
V_3 = F_19 ( V_65 ) ;
if ( V_3 > V_19 -> V_54 )
goto V_44;
for ( V_21 = F_17 ( V_19 -> V_19 [ V_3 ] ) ;
V_21 ;
V_21 = F_17 ( V_21 -> V_36 ) )
if ( V_21 -> V_65 == V_65 )
break;
V_44:
return V_21 ;
}
static unsigned long F_20 ( struct V_9 * V_10 , T_4 V_65 )
{
struct V_18 * V_19 ;
struct V_63 * V_64 = V_10 -> V_41 ;
if ( F_21 ( V_65 ) == V_67 )
V_19 = F_17 ( V_10 -> V_20 ) ;
else
V_19 = F_16 ( V_64 , F_21 ( V_65 ) ) ;
if ( ! V_19 )
return 0 ;
if ( F_22 ( V_65 ) == 0 )
return ( unsigned long ) V_19 ;
return ( unsigned long ) F_18 ( V_19 , V_65 ) ;
}
static T_4 F_23 ( struct V_63 * V_64 )
{
int V_25 = 0x800 ;
do {
if ( ++ V_64 -> V_68 == 0x7FF )
V_64 -> V_68 = 1 ;
} while ( -- V_25 > 0 && F_16 ( V_64 , ( V_64 -> V_68 | 0x800 ) << 20 ) );
return V_25 > 0 ? ( V_64 -> V_68 | 0x800 ) << 20 : 0 ;
}
static int F_24 ( struct V_9 * V_10 )
{
struct V_18 * V_69 ;
struct V_63 * V_64 ;
V_64 = V_10 -> V_70 -> V_71 ;
V_69 = F_25 ( sizeof( * V_69 ) , V_72 ) ;
if ( V_69 == NULL )
return - V_73 ;
V_69 -> V_54 = 0 ;
V_69 -> V_74 ++ ;
V_69 -> V_65 = V_64 ? F_23 ( V_64 ) : 0x80000000 ;
V_69 -> V_75 = V_10 -> V_75 ;
if ( V_64 == NULL ) {
V_64 = F_25 ( sizeof( * V_64 ) , V_72 ) ;
if ( V_64 == NULL ) {
F_26 ( V_69 ) ;
return - V_73 ;
}
V_64 -> V_70 = V_10 -> V_70 ;
V_10 -> V_70 -> V_71 = V_64 ;
}
V_64 -> V_74 ++ ;
F_27 ( V_69 -> V_36 , V_64 -> V_66 ) ;
F_28 ( V_64 -> V_66 , V_69 ) ;
V_69 -> V_64 = V_64 ;
F_28 ( V_10 -> V_20 , V_69 ) ;
V_10 -> V_41 = V_64 ;
return 0 ;
}
static int F_29 ( struct V_9 * V_10 ,
struct V_13 * V_21 ,
bool V_76 )
{
F_30 ( & V_21 -> V_52 ) ;
if ( V_21 -> V_46 )
V_21 -> V_46 -> V_74 -- ;
#ifdef F_6
if ( V_76 )
F_31 ( V_21 -> V_31 ) ;
#endif
#ifdef F_8
if ( V_76 )
F_31 ( V_21 -> V_37 ) ;
#endif
F_26 ( V_21 ) ;
return 0 ;
}
static void F_32 ( struct V_77 * V_78 )
{
struct V_13 * V_1 = F_33 ( V_78 , struct V_13 , V_78 ) ;
F_29 ( V_1 -> V_10 , V_1 , false ) ;
}
static void F_34 ( struct V_77 * V_78 )
{
struct V_13 * V_1 = F_33 ( V_78 , struct V_13 , V_78 ) ;
F_29 ( V_1 -> V_10 , V_1 , true ) ;
}
static int F_35 ( struct V_9 * V_10 , struct V_13 * V_1 )
{
struct V_13 T_5 * * V_79 ;
struct V_13 * V_80 ;
struct V_18 * V_19 = F_17 ( V_1 -> V_62 ) ;
if ( V_19 ) {
V_79 = & V_19 -> V_19 [ F_19 ( V_1 -> V_65 ) ] ;
for ( V_80 = F_17 ( * V_79 ) ; V_80 ;
V_79 = & V_80 -> V_36 , V_80 = F_17 ( * V_79 ) ) {
if ( V_80 == V_1 ) {
F_27 ( * V_79 , V_1 -> V_36 ) ;
F_36 ( V_10 , & V_1 -> V_12 ) ;
F_37 ( & V_1 -> V_78 , F_34 ) ;
return 0 ;
}
}
}
F_38 ( 1 ) ;
return 0 ;
}
static void F_39 ( struct V_9 * V_10 , T_4 V_65 )
{
struct V_81 * V_82 = V_10 -> V_70 -> V_83 -> V_82 ;
struct V_84 V_85 = { 0 } ;
struct V_86 V_87 ;
V_87 . type = V_88 ;
V_87 . V_89 = & V_85 ;
if ( F_40 ( V_82 , 0 ) ) {
V_87 . V_89 -> V_90 = V_91 ;
V_87 . V_89 -> V_14 . V_65 = V_65 ;
V_82 -> V_92 -> V_93 ( V_82 , V_10 -> V_70 -> V_65 ,
V_10 -> V_94 , & V_87 ) ;
}
}
static void F_41 ( struct V_9 * V_10 ,
struct V_18 * V_5 ,
T_4 V_48 )
{
struct V_81 * V_82 = V_10 -> V_70 -> V_83 -> V_82 ;
struct V_84 V_85 = { 0 } ;
struct V_86 V_87 ;
V_87 . type = V_88 ;
V_87 . V_89 = & V_85 ;
if ( F_40 ( V_82 , V_48 ) ) {
V_87 . V_89 -> V_90 = V_95 ;
V_87 . V_89 -> V_96 . V_54 = V_5 -> V_54 ;
V_87 . V_89 -> V_96 . V_65 = V_5 -> V_65 ;
V_87 . V_89 -> V_96 . V_75 = V_5 -> V_75 ;
V_82 -> V_92 -> V_93 ( V_82 , V_10 -> V_70 -> V_65 ,
V_10 -> V_94 , & V_87 ) ;
}
}
static void F_42 ( struct V_9 * V_10 , struct V_18 * V_5 )
{
struct V_81 * V_82 = V_10 -> V_70 -> V_83 -> V_82 ;
struct V_84 V_85 = { 0 } ;
struct V_86 V_87 ;
V_87 . type = V_88 ;
V_87 . V_89 = & V_85 ;
if ( F_40 ( V_82 , 0 ) ) {
V_87 . V_89 -> V_90 = V_97 ;
V_87 . V_89 -> V_96 . V_54 = V_5 -> V_54 ;
V_87 . V_89 -> V_96 . V_65 = V_5 -> V_65 ;
V_87 . V_89 -> V_96 . V_75 = V_5 -> V_75 ;
V_82 -> V_92 -> V_93 ( V_82 , V_10 -> V_70 -> V_65 ,
V_10 -> V_94 , & V_87 ) ;
}
}
static void F_43 ( struct V_9 * V_10 ,
struct V_13 * V_21 ,
T_4 V_48 )
{
struct V_81 * V_82 = V_10 -> V_70 -> V_83 -> V_82 ;
struct V_84 V_85 = { 0 } ;
struct V_86 V_87 ;
V_87 . type = V_88 ;
V_87 . V_89 = & V_85 ;
if ( F_40 ( V_82 , V_48 ) ) {
V_87 . V_89 -> V_90 = V_98 ;
V_87 . V_89 -> V_14 . V_65 = V_21 -> V_65 ;
V_87 . V_89 -> V_14 . V_4 = V_21 -> V_4 ;
#ifdef F_8
V_87 . V_89 -> V_14 . V_35 = V_21 -> V_35 ;
V_87 . V_89 -> V_14 . V_34 = V_21 -> V_34 ;
#else
V_87 . V_89 -> V_14 . V_35 = 0 ;
V_87 . V_89 -> V_14 . V_34 = 0 ;
#endif
V_87 . V_89 -> V_14 . V_3 = & V_21 -> V_3 ;
V_87 . V_89 -> V_14 . V_52 = & V_21 -> V_52 ;
if ( V_21 -> V_46 )
V_87 . V_89 -> V_14 . V_99 = V_21 -> V_46 -> V_65 ;
V_82 -> V_92 -> V_93 ( V_82 , V_10 -> V_70 -> V_65 ,
V_10 -> V_94 , & V_87 ) ;
}
}
static void F_44 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_13 * V_21 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ ) {
while ( ( V_21 = F_17 ( V_19 -> V_19 [ V_5 ] ) ) != NULL ) {
F_27 ( V_19 -> V_19 [ V_5 ] ,
F_17 ( V_21 -> V_36 ) ) ;
F_36 ( V_10 , & V_21 -> V_12 ) ;
F_39 ( V_10 , V_21 -> V_65 ) ;
F_37 ( & V_21 -> V_78 , F_34 ) ;
}
}
}
static int F_45 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 T_5 * * V_100 ;
struct V_18 * V_101 ;
F_38 ( V_19 -> V_74 ) ;
F_44 ( V_10 , V_19 ) ;
V_100 = & V_64 -> V_66 ;
for ( V_101 = F_17 ( * V_100 ) ;
V_101 ;
V_100 = & V_101 -> V_36 , V_101 = F_17 ( * V_100 ) ) {
if ( V_101 == V_19 ) {
F_42 ( V_10 , V_19 ) ;
F_27 ( * V_100 , V_19 -> V_36 ) ;
F_46 ( V_19 , V_78 ) ;
return 0 ;
}
}
return - V_102 ;
}
static bool F_47 ( struct V_18 * V_19 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ )
if ( F_48 ( V_19 -> V_19 [ V_5 ] ) )
return false ;
return true ;
}
static bool F_49 ( struct V_9 * V_10 , bool V_103 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * V_69 = F_17 ( V_10 -> V_20 ) ;
F_38 ( V_69 == NULL ) ;
if ( ! V_103 ) {
if ( V_69 ) {
if ( V_69 -> V_74 > 1 )
return false ;
if ( V_69 -> V_74 == 1 ) {
if ( ! F_47 ( V_69 ) )
return false ;
}
}
if ( V_64 -> V_74 > 1 )
return false ;
if ( V_64 -> V_74 == 1 ) {
struct V_18 * V_19 ;
for ( V_19 = F_17 ( V_64 -> V_66 ) ;
V_19 ;
V_19 = F_17 ( V_19 -> V_36 ) )
if ( ! F_47 ( V_19 ) )
return false ;
}
}
if ( V_69 && -- V_69 -> V_74 == 0 )
F_45 ( V_10 , V_69 ) ;
if ( -- V_64 -> V_74 == 0 ) {
struct V_18 * V_19 ;
V_10 -> V_70 -> V_71 = NULL ;
for ( V_19 = F_17 ( V_64 -> V_66 ) ;
V_19 ;
V_19 = F_17 ( V_19 -> V_36 ) ) {
V_19 -> V_74 -- ;
F_44 ( V_10 , V_19 ) ;
}
while ( ( V_19 = F_17 ( V_64 -> V_66 ) ) != NULL ) {
F_27 ( V_64 -> V_66 , V_19 -> V_36 ) ;
F_46 ( V_19 , V_78 ) ;
}
F_26 ( V_64 ) ;
}
V_10 -> V_41 = NULL ;
return true ;
}
static int F_50 ( struct V_9 * V_10 , unsigned long V_104 )
{
struct V_18 * V_19 = (struct V_18 * ) V_104 ;
struct V_18 * V_69 = F_17 ( V_10 -> V_20 ) ;
if ( V_19 == NULL )
return 0 ;
if ( F_22 ( V_19 -> V_65 ) ) {
F_39 ( V_10 , V_19 -> V_65 ) ;
return F_35 ( V_10 , (struct V_13 * ) V_19 ) ;
}
if ( V_69 == V_19 )
return - V_105 ;
if ( V_19 -> V_74 == 1 ) {
V_19 -> V_74 -- ;
F_45 ( V_10 , V_19 ) ;
} else {
return - V_106 ;
}
return 0 ;
}
static T_4 F_51 ( struct V_18 * V_19 , T_4 V_65 )
{
struct V_13 * V_21 ;
unsigned long V_25 ;
unsigned long * V_107 = F_25 ( F_52 ( V_108 ) * sizeof( unsigned long ) ,
V_72 ) ;
if ( ! V_107 )
return V_65 | 0xFFF ;
for ( V_21 = F_17 ( V_19 -> V_19 [ F_19 ( V_65 ) ] ) ;
V_21 ;
V_21 = F_17 ( V_21 -> V_36 ) )
F_53 ( F_54 ( V_21 -> V_65 ) , V_107 ) ;
V_25 = F_55 ( V_107 , V_108 , 0x800 ) ;
if ( V_25 >= V_108 )
V_25 = F_55 ( V_107 , V_108 , 1 ) ;
F_26 ( V_107 ) ;
return V_65 | ( V_25 >= V_108 ? 0xFFF : V_25 ) ;
}
static int F_56 ( struct V_109 * V_109 , struct V_9 * V_10 ,
unsigned long V_110 , struct V_18 * V_19 ,
struct V_13 * V_21 , struct V_111 * * V_112 ,
struct V_111 * V_113 , bool V_114 )
{
int V_115 ;
struct V_116 V_117 ;
F_57 ( & V_117 , V_118 , V_119 ) ;
V_115 = F_58 ( V_109 , V_10 , V_112 , V_113 , & V_117 , V_114 ) ;
if ( V_115 < 0 )
return V_115 ;
V_115 = - V_105 ;
if ( V_112 [ V_120 ] ) {
T_4 V_65 = F_59 ( V_112 [ V_120 ] ) ;
struct V_18 * V_46 = NULL , * V_121 ;
if ( F_22 ( V_65 ) )
goto V_122;
if ( V_65 ) {
V_46 = F_16 ( V_19 -> V_64 , V_65 ) ;
if ( V_46 == NULL )
goto V_122;
V_46 -> V_74 ++ ;
}
V_121 = F_17 ( V_21 -> V_46 ) ;
F_28 ( V_21 -> V_46 , V_46 ) ;
if ( V_121 )
V_121 -> V_74 -- ;
}
if ( V_112 [ V_123 ] ) {
V_21 -> V_12 . V_124 = F_59 ( V_112 [ V_123 ] ) ;
F_60 ( V_10 , & V_21 -> V_12 , V_110 ) ;
}
#ifdef F_11
if ( V_112 [ V_125 ] ) {
int V_126 ;
V_126 = F_61 ( V_109 , V_112 [ V_125 ] ) ;
if ( V_126 < 0 )
goto V_122;
V_21 -> V_50 = V_126 ;
}
#endif
F_62 ( V_10 , & V_21 -> V_52 , & V_117 ) ;
return 0 ;
V_122:
F_30 ( & V_117 ) ;
return V_115 ;
}
static void F_63 ( struct V_9 * V_10 ,
struct V_63 * V_64 ,
struct V_13 * V_21 )
{
struct V_13 T_5 * * V_127 ;
struct V_13 * V_128 ;
struct V_18 * V_19 ;
if ( F_21 ( V_21 -> V_65 ) == V_67 )
V_19 = F_17 ( V_10 -> V_20 ) ;
else
V_19 = F_16 ( V_64 , F_21 ( V_21 -> V_65 ) ) ;
V_127 = & V_19 -> V_19 [ F_19 ( V_21 -> V_65 ) ] ;
for ( V_128 = F_17 ( * V_127 ) ; ;
V_127 = & V_128 -> V_36 , V_128 = F_17 ( * V_127 ) )
if ( V_128 -> V_65 == V_21 -> V_65 )
break;
F_27 ( V_21 -> V_36 , V_128 -> V_36 ) ;
F_28 ( * V_127 , V_21 ) ;
}
static struct V_13 * F_64 ( struct V_9 * V_10 ,
struct V_13 * V_21 )
{
struct V_13 * V_129 ;
struct V_2 * V_130 = & V_21 -> V_3 ;
V_129 = F_25 ( sizeof( * V_21 ) + V_130 -> V_38 * sizeof( struct V_29 ) ,
V_72 ) ;
if ( ! V_129 )
return NULL ;
F_27 ( V_129 -> V_36 , V_21 -> V_36 ) ;
V_129 -> V_65 = V_21 -> V_65 ;
F_27 ( V_129 -> V_62 , V_21 -> V_62 ) ;
#ifdef F_11
V_129 -> V_50 = V_21 -> V_50 ;
#endif
V_129 -> V_4 = V_21 -> V_4 ;
V_129 -> V_12 = V_21 -> V_12 ;
V_129 -> V_48 = V_21 -> V_48 ;
F_27 ( V_129 -> V_46 , V_21 -> V_46 ) ;
if ( V_129 -> V_46 )
V_129 -> V_46 -> V_74 ++ ;
#ifdef F_6
V_129 -> V_31 = V_21 -> V_31 ;
#endif
#ifdef F_8
V_129 -> V_35 = V_21 -> V_35 ;
V_129 -> V_34 = V_21 -> V_34 ;
V_129 -> V_37 = V_21 -> V_37 ;
#endif
V_129 -> V_10 = V_10 ;
memcpy ( & V_129 -> V_3 , V_130 , sizeof( * V_130 ) + V_130 -> V_38 * sizeof( struct V_29 ) ) ;
F_57 ( & V_129 -> V_52 , V_118 , V_119 ) ;
return V_129 ;
}
static int F_65 ( struct V_109 * V_109 , struct V_7 * V_131 ,
struct V_9 * V_10 , unsigned long V_110 , T_4 V_65 ,
struct V_111 * * V_132 ,
unsigned long * V_104 , bool V_114 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * V_19 ;
struct V_13 * V_21 ;
struct V_2 * V_130 ;
struct V_111 * V_133 = V_132 [ V_134 ] ;
struct V_111 * V_112 [ V_135 + 1 ] ;
T_4 V_136 , V_48 = 0 ;
int V_115 ;
#ifdef F_6
T_6 V_137 ;
#endif
if ( V_133 == NULL )
return V_65 ? - V_105 : 0 ;
V_115 = F_66 ( V_112 , V_135 , V_133 , V_138 ) ;
if ( V_115 < 0 )
return V_115 ;
if ( V_112 [ V_139 ] )
V_48 = F_59 ( V_112 [ V_139 ] ) ;
V_21 = (struct V_13 * ) * V_104 ;
if ( V_21 ) {
struct V_13 * V_129 ;
if ( F_22 ( V_21 -> V_65 ) == 0 )
return - V_105 ;
if ( V_21 -> V_48 != V_48 )
return - V_105 ;
V_129 = F_64 ( V_10 , V_21 ) ;
if ( ! V_129 )
return - V_140 ;
V_115 = F_56 ( V_109 , V_10 , V_110 ,
F_17 ( V_21 -> V_62 ) , V_129 , V_112 ,
V_132 [ V_141 ] , V_114 ) ;
if ( V_115 ) {
F_29 ( V_10 , V_129 , false ) ;
return V_115 ;
}
F_63 ( V_10 , V_64 , V_129 ) ;
F_36 ( V_10 , & V_21 -> V_12 ) ;
F_37 ( & V_21 -> V_78 , F_32 ) ;
F_43 ( V_10 , V_129 , V_48 ) ;
return 0 ;
}
if ( V_112 [ V_142 ] ) {
unsigned int V_54 = F_59 ( V_112 [ V_142 ] ) ;
if ( -- V_54 > 0x100 )
return - V_105 ;
if ( F_22 ( V_65 ) )
return - V_105 ;
if ( V_65 == 0 ) {
V_65 = F_23 ( V_10 -> V_41 ) ;
if ( V_65 == 0 )
return - V_140 ;
}
V_19 = F_25 ( sizeof( * V_19 ) + V_54 * sizeof( void * ) , V_72 ) ;
if ( V_19 == NULL )
return - V_73 ;
V_19 -> V_64 = V_64 ;
V_19 -> V_74 = 1 ;
V_19 -> V_54 = V_54 ;
V_19 -> V_65 = V_65 ;
V_19 -> V_75 = V_10 -> V_75 ;
F_27 ( V_19 -> V_36 , V_64 -> V_66 ) ;
F_28 ( V_64 -> V_66 , V_19 ) ;
* V_104 = ( unsigned long ) V_19 ;
F_41 ( V_10 , V_19 , V_48 ) ;
return 0 ;
}
if ( V_112 [ V_143 ] ) {
V_136 = F_59 ( V_112 [ V_143 ] ) ;
if ( F_21 ( V_136 ) == V_67 ) {
V_19 = F_17 ( V_10 -> V_20 ) ;
V_136 = V_19 -> V_65 ;
} else {
V_19 = F_16 ( V_10 -> V_41 , F_21 ( V_136 ) ) ;
if ( V_19 == NULL )
return - V_105 ;
}
} else {
V_19 = F_17 ( V_10 -> V_20 ) ;
V_136 = V_19 -> V_65 ;
}
if ( V_19 -> V_54 < F_19 ( V_136 ) )
return - V_105 ;
if ( V_65 ) {
if ( F_21 ( V_65 ) && F_21 ( V_65 ^ V_136 ) )
return - V_105 ;
V_65 = V_136 | F_54 ( V_65 ) ;
} else
V_65 = F_51 ( V_19 , V_136 ) ;
if ( V_112 [ V_144 ] == NULL )
return - V_105 ;
V_130 = F_67 ( V_112 [ V_144 ] ) ;
V_21 = F_25 ( sizeof( * V_21 ) + V_130 -> V_38 * sizeof( struct V_29 ) , V_72 ) ;
if ( V_21 == NULL )
return - V_73 ;
#ifdef F_6
V_137 = sizeof( struct V_145 ) + V_130 -> V_38 * sizeof( V_146 ) ;
V_21 -> V_31 = F_68 ( V_137 , F_69 ( struct V_145 ) ) ;
if ( ! V_21 -> V_31 ) {
F_26 ( V_21 ) ;
return - V_73 ;
}
#endif
memcpy ( & V_21 -> V_3 , V_130 , sizeof( * V_130 ) + V_130 -> V_38 * sizeof( struct V_29 ) ) ;
F_27 ( V_21 -> V_62 , V_19 ) ;
V_21 -> V_65 = V_65 ;
V_21 -> V_4 = V_130 -> V_6 ? F_70 ( F_2 ( V_130 -> V_6 ) ) - 1 : 0 ;
V_21 -> V_48 = V_48 ;
F_57 ( & V_21 -> V_52 , V_118 , V_119 ) ;
V_21 -> V_10 = V_10 ;
#ifdef F_8
V_21 -> V_37 = F_71 ( T_4 ) ;
if ( ! V_21 -> V_37 ) {
V_115 = - V_140 ;
goto V_122;
}
if ( V_112 [ V_147 ] ) {
struct V_148 * V_33 ;
V_33 = F_67 ( V_112 [ V_147 ] ) ;
V_21 -> V_35 = V_33 -> V_35 ;
V_21 -> V_34 = V_33 -> V_34 ;
}
#endif
V_115 = F_56 ( V_109 , V_10 , V_110 , V_19 , V_21 , V_112 , V_132 [ V_141 ] , V_114 ) ;
if ( V_115 == 0 ) {
struct V_13 T_5 * * V_127 ;
struct V_13 * V_128 ;
V_127 = & V_19 -> V_19 [ F_19 ( V_65 ) ] ;
for ( V_128 = F_17 ( * V_127 ) ; V_128 ;
V_127 = & V_128 -> V_36 , V_128 = F_17 ( * V_127 ) )
if ( F_54 ( V_65 ) < F_54 ( V_128 -> V_65 ) )
break;
F_27 ( V_21 -> V_36 , V_128 ) ;
F_28 ( * V_127 , V_21 ) ;
F_43 ( V_10 , V_21 , V_48 ) ;
* V_104 = ( unsigned long ) V_21 ;
return 0 ;
}
#ifdef F_8
F_31 ( V_21 -> V_37 ) ;
V_122:
#endif
#ifdef F_6
F_31 ( V_21 -> V_31 ) ;
#endif
F_26 ( V_21 ) ;
return V_115 ;
}
static void F_72 ( struct V_9 * V_10 , struct V_149 * V_104 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * V_19 ;
struct V_13 * V_21 ;
unsigned int V_5 ;
if ( V_104 -> V_150 )
return;
for ( V_19 = F_17 ( V_64 -> V_66 ) ;
V_19 ;
V_19 = F_17 ( V_19 -> V_36 ) ) {
if ( V_19 -> V_75 != V_10 -> V_75 )
continue;
if ( V_104 -> V_151 >= V_104 -> V_152 ) {
if ( V_104 -> V_153 ( V_10 , ( unsigned long ) V_19 , V_104 ) < 0 ) {
V_104 -> V_150 = 1 ;
return;
}
}
V_104 -> V_151 ++ ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ ) {
for ( V_21 = F_17 ( V_19 -> V_19 [ V_5 ] ) ;
V_21 ;
V_21 = F_17 ( V_21 -> V_36 ) ) {
if ( V_104 -> V_151 < V_104 -> V_152 ) {
V_104 -> V_151 ++ ;
continue;
}
if ( V_104 -> V_153 ( V_10 , ( unsigned long ) V_21 , V_104 ) < 0 ) {
V_104 -> V_150 = 1 ;
return;
}
V_104 -> V_151 ++ ;
}
}
}
}
static int F_73 ( struct V_109 * V_109 , struct V_9 * V_10 , unsigned long V_154 ,
struct V_7 * V_8 , struct V_155 * V_156 )
{
struct V_13 * V_21 = (struct V_13 * ) V_154 ;
struct V_18 * V_62 , * V_46 ;
struct V_111 * V_157 ;
if ( V_21 == NULL )
return V_8 -> V_61 ;
V_156 -> V_158 = V_21 -> V_65 ;
V_157 = F_74 ( V_8 , V_134 ) ;
if ( V_157 == NULL )
goto V_159;
if ( F_22 ( V_21 -> V_65 ) == 0 ) {
struct V_18 * V_19 = (struct V_18 * ) V_154 ;
T_4 V_54 = V_19 -> V_54 + 1 ;
if ( F_75 ( V_8 , V_142 , V_54 ) )
goto V_159;
} else {
#ifdef F_6
struct V_145 * V_160 ;
int V_161 ;
#endif
if ( F_76 ( V_8 , V_144 ,
sizeof( V_21 -> V_3 ) + V_21 -> V_3 . V_38 * sizeof( struct V_29 ) ,
& V_21 -> V_3 ) )
goto V_159;
V_62 = F_17 ( V_21 -> V_62 ) ;
if ( V_62 ) {
T_4 V_136 = V_21 -> V_65 & 0xFFFFF000 ;
if ( F_75 ( V_8 , V_143 , V_136 ) )
goto V_159;
}
if ( V_21 -> V_12 . V_124 &&
F_75 ( V_8 , V_123 , V_21 -> V_12 . V_124 ) )
goto V_159;
V_46 = F_17 ( V_21 -> V_46 ) ;
if ( V_46 &&
F_75 ( V_8 , V_120 , V_46 -> V_65 ) )
goto V_159;
if ( V_21 -> V_48 && F_75 ( V_8 , V_139 , V_21 -> V_48 ) )
goto V_159;
#ifdef F_8
if ( ( V_21 -> V_35 || V_21 -> V_34 ) ) {
struct V_148 V_33 = { . V_35 = V_21 -> V_35 ,
. V_34 = V_21 -> V_34 ,
. V_162 = 0 } ;
int V_163 ;
F_77 (cpum) {
T_7 V_164 = * F_78 ( V_21 -> V_37 , V_163 ) ;
V_33 . V_162 += V_164 ;
}
if ( F_76 ( V_8 , V_147 , sizeof( V_33 ) , & V_33 ) )
goto V_159;
}
#endif
if ( F_79 ( V_8 , & V_21 -> V_52 ) < 0 )
goto V_159;
#ifdef F_11
if ( V_21 -> V_50 ) {
struct V_81 * V_82 ;
V_82 = F_80 ( V_109 , V_21 -> V_50 ) ;
if ( V_82 && F_81 ( V_8 , V_125 , V_82 -> V_165 ) )
goto V_159;
}
#endif
#ifdef F_6
V_160 = F_25 ( sizeof( struct V_145 ) +
V_21 -> V_3 . V_38 * sizeof( V_146 ) ,
V_72 ) ;
if ( ! V_160 )
goto V_159;
F_77 (cpu) {
int V_25 ;
struct V_145 * V_31 = F_78 ( V_21 -> V_31 , V_161 ) ;
V_160 -> V_32 += V_31 -> V_32 ;
V_160 -> V_51 += V_31 -> V_51 ;
for ( V_25 = 0 ; V_25 < V_21 -> V_3 . V_38 ; V_25 ++ )
V_160 -> V_45 [ V_25 ] += V_31 -> V_45 [ V_25 ] ;
}
if ( F_76 ( V_8 , V_166 ,
sizeof( struct V_145 ) + V_21 -> V_3 . V_38 * sizeof( V_146 ) ,
V_160 ) ) {
F_26 ( V_160 ) ;
goto V_159;
}
F_26 ( V_160 ) ;
#endif
}
F_82 ( V_8 , V_157 ) ;
if ( F_22 ( V_21 -> V_65 ) )
if ( F_83 ( V_8 , & V_21 -> V_52 ) < 0 )
goto V_159;
return V_8 -> V_61 ;
V_159:
F_84 ( V_8 , V_157 ) ;
return - 1 ;
}
static int T_8 F_85 ( void )
{
F_86 ( L_2 ) ;
#ifdef F_6
F_86 ( L_3 ) ;
#endif
#ifdef F_11
F_86 ( L_4 ) ;
#endif
#ifdef F_87
F_86 ( L_5 ) ;
#endif
return F_88 ( & V_167 ) ;
}
static void T_9 F_89 ( void )
{
F_90 ( & V_167 ) ;
}
