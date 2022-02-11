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
static unsigned long F_21 ( struct V_9 * V_10 , T_4 V_65 )
{
struct V_18 * V_19 ;
struct V_63 * V_64 = V_10 -> V_42 ;
if ( F_22 ( V_65 ) == V_67 )
V_19 = F_18 ( V_10 -> V_20 ) ;
else
V_19 = F_17 ( V_64 , F_22 ( V_65 ) ) ;
if ( ! V_19 )
return 0 ;
if ( F_23 ( V_65 ) == 0 )
return ( unsigned long ) V_19 ;
return ( unsigned long ) F_19 ( V_19 , V_65 ) ;
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
static int F_25 ( struct V_9 * V_10 )
{
struct V_18 * V_69 ;
struct V_63 * V_64 ;
V_64 = V_10 -> V_70 -> V_71 ;
V_69 = F_26 ( sizeof( * V_69 ) , V_72 ) ;
if ( V_69 == NULL )
return - V_73 ;
V_69 -> V_74 ++ ;
V_69 -> V_65 = V_64 ? F_24 ( V_64 ) : 0x80000000 ;
V_69 -> V_75 = V_10 -> V_75 ;
if ( V_64 == NULL ) {
V_64 = F_26 ( sizeof( * V_64 ) , V_72 ) ;
if ( V_64 == NULL ) {
F_27 ( V_69 ) ;
return - V_73 ;
}
V_64 -> V_70 = V_10 -> V_70 ;
V_10 -> V_70 -> V_71 = V_64 ;
}
V_64 -> V_74 ++ ;
F_28 ( V_69 -> V_34 , V_64 -> V_66 ) ;
F_29 ( V_64 -> V_66 , V_69 ) ;
V_69 -> V_64 = V_64 ;
F_29 ( V_10 -> V_20 , V_69 ) ;
V_10 -> V_42 = V_64 ;
return 0 ;
}
static int F_30 ( struct V_9 * V_10 , struct V_13 * V_21 ,
bool V_76 )
{
F_31 ( & V_21 -> V_52 ) ;
if ( V_21 -> V_47 )
V_21 -> V_47 -> V_74 -- ;
#ifdef F_6
if ( V_76 )
F_32 ( V_21 -> V_31 ) ;
#endif
#ifdef F_9
if ( V_76 )
F_32 ( V_21 -> V_38 ) ;
#endif
F_27 ( V_21 ) ;
return 0 ;
}
static void F_33 ( struct V_77 * V_78 )
{
struct V_13 * V_1 = F_34 ( V_78 , struct V_13 , V_78 ) ;
F_30 ( V_1 -> V_10 , V_1 , false ) ;
}
static void F_35 ( struct V_77 * V_78 )
{
struct V_13 * V_1 = F_34 ( V_78 , struct V_13 , V_78 ) ;
F_30 ( V_1 -> V_10 , V_1 , true ) ;
}
static int F_36 ( struct V_9 * V_10 , struct V_13 * V_1 )
{
struct V_13 T_5 * * V_79 ;
struct V_13 * V_80 ;
struct V_18 * V_19 = F_18 ( V_1 -> V_62 ) ;
if ( V_19 ) {
V_79 = & V_19 -> V_19 [ F_20 ( V_1 -> V_65 ) ] ;
for ( V_80 = F_18 ( * V_79 ) ; V_80 ;
V_79 = & V_80 -> V_34 , V_80 = F_18 ( * V_79 ) ) {
if ( V_80 == V_1 ) {
F_28 ( * V_79 , V_1 -> V_34 ) ;
F_37 ( V_10 , & V_1 -> V_12 ) ;
F_38 ( & V_1 -> V_78 , F_35 ) ;
return 0 ;
}
}
}
F_39 ( 1 ) ;
return 0 ;
}
static void F_40 ( struct V_9 * V_10 , T_4 V_65 )
{
struct V_81 * V_82 = V_10 -> V_70 -> V_83 -> V_82 ;
struct V_84 V_85 = { 0 } ;
struct V_86 V_87 ;
V_87 . type = V_88 ;
V_87 . V_89 = & V_85 ;
if ( F_41 ( V_82 , V_10 , 0 ) ) {
V_87 . V_89 -> V_90 = V_91 ;
V_87 . V_89 -> V_14 . V_65 = V_65 ;
V_82 -> V_92 -> V_93 ( V_82 , V_10 -> V_70 -> V_65 ,
V_10 -> V_94 , & V_87 ) ;
}
}
static int F_42 ( struct V_9 * V_10 , struct V_18 * V_5 ,
T_4 V_33 )
{
struct V_81 * V_82 = V_10 -> V_70 -> V_83 -> V_82 ;
struct V_84 V_85 = { 0 } ;
struct V_86 V_87 ;
int V_95 ;
if ( ! F_41 ( V_82 , V_10 , V_33 ) )
return F_8 ( V_33 ) ? - V_96 : 0 ;
V_87 . type = V_88 ;
V_87 . V_89 = & V_85 ;
V_87 . V_89 -> V_90 = V_97 ;
V_87 . V_89 -> V_98 . V_54 = V_5 -> V_54 ;
V_87 . V_89 -> V_98 . V_65 = V_5 -> V_65 ;
V_87 . V_89 -> V_98 . V_75 = V_5 -> V_75 ;
V_95 = V_82 -> V_92 -> V_93 ( V_82 , V_10 -> V_70 -> V_65 ,
V_10 -> V_94 , & V_87 ) ;
if ( F_8 ( V_33 ) )
return V_95 ;
return 0 ;
}
static void F_43 ( struct V_9 * V_10 , struct V_18 * V_5 )
{
struct V_81 * V_82 = V_10 -> V_70 -> V_83 -> V_82 ;
struct V_84 V_85 = { 0 } ;
struct V_86 V_87 ;
V_87 . type = V_88 ;
V_87 . V_89 = & V_85 ;
if ( F_41 ( V_82 , V_10 , 0 ) ) {
V_87 . V_89 -> V_90 = V_99 ;
V_87 . V_89 -> V_98 . V_54 = V_5 -> V_54 ;
V_87 . V_89 -> V_98 . V_65 = V_5 -> V_65 ;
V_87 . V_89 -> V_98 . V_75 = V_5 -> V_75 ;
V_82 -> V_92 -> V_93 ( V_82 , V_10 -> V_70 -> V_65 ,
V_10 -> V_94 , & V_87 ) ;
}
}
static int F_44 ( struct V_9 * V_10 , struct V_13 * V_21 ,
T_4 V_33 )
{
struct V_81 * V_82 = V_10 -> V_70 -> V_83 -> V_82 ;
struct V_84 V_85 = { 0 } ;
struct V_86 V_87 ;
int V_95 ;
V_87 . type = V_88 ;
V_87 . V_89 = & V_85 ;
if ( ! F_41 ( V_82 , V_10 , V_33 ) )
return F_8 ( V_33 ) ? - V_96 : 0 ;
V_87 . V_89 -> V_90 = V_100 ;
V_87 . V_89 -> V_14 . V_65 = V_21 -> V_65 ;
V_87 . V_89 -> V_14 . V_4 = V_21 -> V_4 ;
#ifdef F_9
V_87 . V_89 -> V_14 . V_37 = V_21 -> V_37 ;
V_87 . V_89 -> V_14 . V_36 = V_21 -> V_36 ;
#else
V_87 . V_89 -> V_14 . V_37 = 0 ;
V_87 . V_89 -> V_14 . V_36 = 0 ;
#endif
V_87 . V_89 -> V_14 . V_3 = & V_21 -> V_3 ;
V_87 . V_89 -> V_14 . V_52 = & V_21 -> V_52 ;
if ( V_21 -> V_47 )
V_87 . V_89 -> V_14 . V_101 = V_21 -> V_47 -> V_65 ;
V_95 = V_82 -> V_92 -> V_93 ( V_82 , V_10 -> V_70 -> V_65 ,
V_10 -> V_94 , & V_87 ) ;
if ( ! V_95 )
V_21 -> V_33 |= V_102 ;
if ( F_8 ( V_33 ) )
return V_95 ;
return 0 ;
}
static void F_45 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_13 * V_21 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ ) {
while ( ( V_21 = F_18 ( V_19 -> V_19 [ V_5 ] ) ) != NULL ) {
F_28 ( V_19 -> V_19 [ V_5 ] ,
F_18 ( V_21 -> V_34 ) ) ;
F_37 ( V_10 , & V_21 -> V_12 ) ;
F_40 ( V_10 , V_21 -> V_65 ) ;
F_38 ( & V_21 -> V_78 , F_35 ) ;
}
}
}
static int F_46 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_63 * V_64 = V_10 -> V_42 ;
struct V_18 T_5 * * V_103 ;
struct V_18 * V_104 ;
F_39 ( V_19 -> V_74 ) ;
F_45 ( V_10 , V_19 ) ;
V_103 = & V_64 -> V_66 ;
for ( V_104 = F_18 ( * V_103 ) ;
V_104 ;
V_103 = & V_104 -> V_34 , V_104 = F_18 ( * V_103 ) ) {
if ( V_104 == V_19 ) {
F_43 ( V_10 , V_19 ) ;
F_28 ( * V_103 , V_19 -> V_34 ) ;
F_47 ( V_19 , V_78 ) ;
return 0 ;
}
}
return - V_105 ;
}
static bool F_48 ( struct V_18 * V_19 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ )
if ( F_49 ( V_19 -> V_19 [ V_5 ] ) )
return false ;
return true ;
}
static void F_50 ( struct V_9 * V_10 )
{
struct V_63 * V_64 = V_10 -> V_42 ;
struct V_18 * V_69 = F_18 ( V_10 -> V_20 ) ;
F_39 ( V_69 == NULL ) ;
if ( V_69 && -- V_69 -> V_74 == 0 )
F_46 ( V_10 , V_69 ) ;
if ( -- V_64 -> V_74 == 0 ) {
struct V_18 * V_19 ;
V_10 -> V_70 -> V_71 = NULL ;
for ( V_19 = F_18 ( V_64 -> V_66 ) ;
V_19 ;
V_19 = F_18 ( V_19 -> V_34 ) ) {
V_19 -> V_74 -- ;
F_45 ( V_10 , V_19 ) ;
}
while ( ( V_19 = F_18 ( V_64 -> V_66 ) ) != NULL ) {
F_28 ( V_64 -> V_66 , V_19 -> V_34 ) ;
F_47 ( V_19 , V_78 ) ;
}
F_27 ( V_64 ) ;
}
V_10 -> V_42 = NULL ;
}
static int F_51 ( struct V_9 * V_10 , unsigned long V_106 , bool * V_107 )
{
struct V_18 * V_19 = (struct V_18 * ) V_106 ;
struct V_18 * V_69 = F_18 ( V_10 -> V_20 ) ;
struct V_63 * V_64 = V_10 -> V_42 ;
int V_108 = 0 ;
if ( V_19 == NULL )
goto V_45;
if ( F_23 ( V_19 -> V_65 ) ) {
F_40 ( V_10 , V_19 -> V_65 ) ;
V_108 = F_36 ( V_10 , (struct V_13 * ) V_19 ) ;
goto V_45;
}
if ( V_69 == V_19 )
return - V_96 ;
if ( V_19 -> V_74 == 1 ) {
V_19 -> V_74 -- ;
F_46 ( V_10 , V_19 ) ;
} else {
return - V_109 ;
}
V_45:
* V_107 = true ;
if ( V_69 ) {
if ( V_69 -> V_74 > 1 ) {
* V_107 = false ;
goto V_108;
}
if ( V_69 -> V_74 == 1 ) {
if ( ! F_48 ( V_69 ) ) {
* V_107 = false ;
goto V_108;
}
}
}
if ( V_64 -> V_74 > 1 ) {
* V_107 = false ;
goto V_108;
}
if ( V_64 -> V_74 == 1 ) {
struct V_18 * V_19 ;
for ( V_19 = F_18 ( V_64 -> V_66 ) ;
V_19 ;
V_19 = F_18 ( V_19 -> V_34 ) )
if ( ! F_48 ( V_19 ) ) {
* V_107 = false ;
break;
}
}
V_108:
return V_108 ;
}
static T_4 F_52 ( struct V_18 * V_19 , T_4 V_65 )
{
struct V_13 * V_21 ;
unsigned long V_25 ;
unsigned long * V_110 = F_26 ( F_53 ( V_111 ) * sizeof( unsigned long ) ,
V_72 ) ;
if ( ! V_110 )
return V_65 | 0xFFF ;
for ( V_21 = F_18 ( V_19 -> V_19 [ F_20 ( V_65 ) ] ) ;
V_21 ;
V_21 = F_18 ( V_21 -> V_34 ) )
F_54 ( F_55 ( V_21 -> V_65 ) , V_110 ) ;
V_25 = F_56 ( V_110 , V_111 , 0x800 ) ;
if ( V_25 >= V_111 )
V_25 = F_56 ( V_110 , V_111 , 1 ) ;
F_27 ( V_110 ) ;
return V_65 | ( V_25 >= V_111 ? 0xFFF : V_25 ) ;
}
static int F_57 ( struct V_112 * V_112 , struct V_9 * V_10 ,
unsigned long V_113 , struct V_18 * V_19 ,
struct V_13 * V_21 , struct V_114 * * V_115 ,
struct V_114 * V_116 , bool V_117 )
{
struct V_118 V_119 ;
int V_95 ;
V_95 = F_58 ( & V_119 , V_120 , V_121 ) ;
if ( V_95 < 0 )
return V_95 ;
V_95 = F_59 ( V_112 , V_10 , V_115 , V_116 , & V_119 , V_117 ) ;
if ( V_95 < 0 )
goto V_122;
V_95 = - V_96 ;
if ( V_115 [ V_123 ] ) {
T_4 V_65 = F_60 ( V_115 [ V_123 ] ) ;
struct V_18 * V_47 = NULL , * V_124 ;
if ( F_23 ( V_65 ) )
goto V_122;
if ( V_65 ) {
V_47 = F_17 ( V_19 -> V_64 , V_65 ) ;
if ( V_47 == NULL )
goto V_122;
V_47 -> V_74 ++ ;
}
V_124 = F_18 ( V_21 -> V_47 ) ;
F_29 ( V_21 -> V_47 , V_47 ) ;
if ( V_124 )
V_124 -> V_74 -- ;
}
if ( V_115 [ V_125 ] ) {
V_21 -> V_12 . V_126 = F_60 ( V_115 [ V_125 ] ) ;
F_61 ( V_10 , & V_21 -> V_12 , V_113 ) ;
}
#ifdef F_12
if ( V_115 [ V_127 ] ) {
int V_108 ;
V_108 = F_62 ( V_112 , V_115 [ V_127 ] ) ;
if ( V_108 < 0 )
goto V_122;
V_21 -> V_50 = V_108 ;
}
#endif
F_63 ( V_10 , & V_21 -> V_52 , & V_119 ) ;
return 0 ;
V_122:
F_31 ( & V_119 ) ;
return V_95 ;
}
static void F_64 ( struct V_9 * V_10 , struct V_63 * V_64 ,
struct V_13 * V_21 )
{
struct V_13 T_5 * * V_128 ;
struct V_13 * V_129 ;
struct V_18 * V_19 ;
if ( F_22 ( V_21 -> V_65 ) == V_67 )
V_19 = F_18 ( V_10 -> V_20 ) ;
else
V_19 = F_17 ( V_64 , F_22 ( V_21 -> V_65 ) ) ;
V_128 = & V_19 -> V_19 [ F_20 ( V_21 -> V_65 ) ] ;
for ( V_129 = F_18 ( * V_128 ) ; ;
V_128 = & V_129 -> V_34 , V_129 = F_18 ( * V_128 ) )
if ( V_129 -> V_65 == V_21 -> V_65 )
break;
F_28 ( V_21 -> V_34 , V_129 -> V_34 ) ;
F_29 ( * V_128 , V_21 ) ;
}
static struct V_13 * F_65 ( struct V_9 * V_10 ,
struct V_13 * V_21 )
{
struct V_13 * V_130 ;
struct V_2 * V_131 = & V_21 -> V_3 ;
V_130 = F_26 ( sizeof( * V_21 ) + V_131 -> V_39 * sizeof( struct V_29 ) ,
V_72 ) ;
if ( ! V_130 )
return NULL ;
F_28 ( V_130 -> V_34 , V_21 -> V_34 ) ;
V_130 -> V_65 = V_21 -> V_65 ;
F_28 ( V_130 -> V_62 , V_21 -> V_62 ) ;
#ifdef F_12
V_130 -> V_50 = V_21 -> V_50 ;
#endif
V_130 -> V_4 = V_21 -> V_4 ;
V_130 -> V_12 = V_21 -> V_12 ;
V_130 -> V_33 = V_21 -> V_33 ;
F_28 ( V_130 -> V_47 , V_21 -> V_47 ) ;
if ( V_130 -> V_47 )
V_130 -> V_47 -> V_74 ++ ;
#ifdef F_6
V_130 -> V_31 = V_21 -> V_31 ;
#endif
#ifdef F_9
V_130 -> V_37 = V_21 -> V_37 ;
V_130 -> V_36 = V_21 -> V_36 ;
V_130 -> V_38 = V_21 -> V_38 ;
#endif
V_130 -> V_10 = V_10 ;
memcpy ( & V_130 -> V_3 , V_131 , sizeof( * V_131 ) + V_131 -> V_39 * sizeof( struct V_29 ) ) ;
if ( F_58 ( & V_130 -> V_52 , V_120 , V_121 ) ) {
F_27 ( V_130 ) ;
return NULL ;
}
return V_130 ;
}
static int F_66 ( struct V_112 * V_112 , struct V_7 * V_132 ,
struct V_9 * V_10 , unsigned long V_113 , T_4 V_65 ,
struct V_114 * * V_133 , unsigned long * V_106 , bool V_117 )
{
struct V_63 * V_64 = V_10 -> V_42 ;
struct V_18 * V_19 ;
struct V_13 * V_21 ;
struct V_2 * V_131 ;
struct V_114 * V_134 = V_133 [ V_135 ] ;
struct V_114 * V_115 [ V_136 + 1 ] ;
T_4 V_137 , V_33 = 0 ;
int V_95 ;
#ifdef F_6
T_6 V_138 ;
#endif
if ( V_134 == NULL )
return V_65 ? - V_96 : 0 ;
V_95 = F_67 ( V_115 , V_136 , V_134 , V_139 , NULL ) ;
if ( V_95 < 0 )
return V_95 ;
if ( V_115 [ V_140 ] ) {
V_33 = F_60 ( V_115 [ V_140 ] ) ;
if ( ! F_68 ( V_33 ) )
return - V_96 ;
}
V_21 = (struct V_13 * ) * V_106 ;
if ( V_21 ) {
struct V_13 * V_130 ;
if ( F_23 ( V_21 -> V_65 ) == 0 )
return - V_96 ;
if ( V_21 -> V_33 != V_33 )
return - V_96 ;
V_130 = F_65 ( V_10 , V_21 ) ;
if ( ! V_130 )
return - V_141 ;
V_95 = F_57 ( V_112 , V_10 , V_113 ,
F_18 ( V_21 -> V_62 ) , V_130 , V_115 ,
V_133 [ V_142 ] , V_117 ) ;
if ( V_95 ) {
F_30 ( V_10 , V_130 , false ) ;
return V_95 ;
}
V_95 = F_44 ( V_10 , V_130 , V_33 ) ;
if ( V_95 ) {
F_30 ( V_10 , V_130 , false ) ;
return V_95 ;
}
if ( ! F_69 ( V_130 -> V_33 ) )
V_130 -> V_33 |= V_143 ;
F_64 ( V_10 , V_64 , V_130 ) ;
F_37 ( V_10 , & V_21 -> V_12 ) ;
F_38 ( & V_21 -> V_78 , F_33 ) ;
return 0 ;
}
if ( V_115 [ V_144 ] ) {
unsigned int V_54 = F_60 ( V_115 [ V_144 ] ) ;
if ( -- V_54 > 0x100 )
return - V_96 ;
if ( F_23 ( V_65 ) )
return - V_96 ;
if ( V_65 == 0 ) {
V_65 = F_24 ( V_10 -> V_42 ) ;
if ( V_65 == 0 )
return - V_141 ;
}
V_19 = F_26 ( sizeof( * V_19 ) + V_54 * sizeof( void * ) , V_72 ) ;
if ( V_19 == NULL )
return - V_73 ;
V_19 -> V_64 = V_64 ;
V_19 -> V_74 = 1 ;
V_19 -> V_54 = V_54 ;
V_19 -> V_65 = V_65 ;
V_19 -> V_75 = V_10 -> V_75 ;
V_95 = F_42 ( V_10 , V_19 , V_33 ) ;
if ( V_95 ) {
F_27 ( V_19 ) ;
return V_95 ;
}
F_28 ( V_19 -> V_34 , V_64 -> V_66 ) ;
F_29 ( V_64 -> V_66 , V_19 ) ;
* V_106 = ( unsigned long ) V_19 ;
return 0 ;
}
if ( V_115 [ V_145 ] ) {
V_137 = F_60 ( V_115 [ V_145 ] ) ;
if ( F_22 ( V_137 ) == V_67 ) {
V_19 = F_18 ( V_10 -> V_20 ) ;
V_137 = V_19 -> V_65 ;
} else {
V_19 = F_17 ( V_10 -> V_42 , F_22 ( V_137 ) ) ;
if ( V_19 == NULL )
return - V_96 ;
}
} else {
V_19 = F_18 ( V_10 -> V_20 ) ;
V_137 = V_19 -> V_65 ;
}
if ( V_19 -> V_54 < F_20 ( V_137 ) )
return - V_96 ;
if ( V_65 ) {
if ( F_22 ( V_65 ) && F_22 ( V_65 ^ V_137 ) )
return - V_96 ;
V_65 = V_137 | F_55 ( V_65 ) ;
} else
V_65 = F_52 ( V_19 , V_137 ) ;
if ( V_115 [ V_146 ] == NULL )
return - V_96 ;
V_131 = F_70 ( V_115 [ V_146 ] ) ;
V_21 = F_26 ( sizeof( * V_21 ) + V_131 -> V_39 * sizeof( struct V_29 ) , V_72 ) ;
if ( V_21 == NULL )
return - V_73 ;
#ifdef F_6
V_138 = sizeof( struct V_147 ) + V_131 -> V_39 * sizeof( V_148 ) ;
V_21 -> V_31 = F_71 ( V_138 , F_72 ( struct V_147 ) ) ;
if ( ! V_21 -> V_31 ) {
F_27 ( V_21 ) ;
return - V_73 ;
}
#endif
memcpy ( & V_21 -> V_3 , V_131 , sizeof( * V_131 ) + V_131 -> V_39 * sizeof( struct V_29 ) ) ;
F_28 ( V_21 -> V_62 , V_19 ) ;
V_21 -> V_65 = V_65 ;
V_21 -> V_4 = V_131 -> V_6 ? F_73 ( F_2 ( V_131 -> V_6 ) ) - 1 : 0 ;
V_21 -> V_33 = V_33 ;
V_21 -> V_10 = V_10 ;
V_95 = F_58 ( & V_21 -> V_52 , V_120 , V_121 ) ;
if ( V_95 < 0 )
goto V_122;
#ifdef F_9
V_21 -> V_38 = F_74 ( T_4 ) ;
if ( ! V_21 -> V_38 ) {
V_95 = - V_141 ;
goto V_122;
}
if ( V_115 [ V_149 ] ) {
struct V_150 * V_35 ;
V_35 = F_70 ( V_115 [ V_149 ] ) ;
V_21 -> V_37 = V_35 -> V_37 ;
V_21 -> V_36 = V_35 -> V_36 ;
}
#endif
V_95 = F_57 ( V_112 , V_10 , V_113 , V_19 , V_21 , V_115 , V_133 [ V_142 ] , V_117 ) ;
if ( V_95 == 0 ) {
struct V_13 T_5 * * V_128 ;
struct V_13 * V_129 ;
V_95 = F_44 ( V_10 , V_21 , V_33 ) ;
if ( V_95 )
goto V_151;
if ( ! F_69 ( V_21 -> V_33 ) )
V_21 -> V_33 |= V_143 ;
V_128 = & V_19 -> V_19 [ F_20 ( V_65 ) ] ;
for ( V_129 = F_18 ( * V_128 ) ; V_129 ;
V_128 = & V_129 -> V_34 , V_129 = F_18 ( * V_128 ) )
if ( F_55 ( V_65 ) < F_55 ( V_129 -> V_65 ) )
break;
F_28 ( V_21 -> V_34 , V_129 ) ;
F_29 ( * V_128 , V_21 ) ;
* V_106 = ( unsigned long ) V_21 ;
return 0 ;
}
V_151:
#ifdef F_9
F_32 ( V_21 -> V_38 ) ;
#endif
V_122:
F_31 ( & V_21 -> V_52 ) ;
#ifdef F_6
F_32 ( V_21 -> V_31 ) ;
#endif
F_27 ( V_21 ) ;
return V_95 ;
}
static void F_75 ( struct V_9 * V_10 , struct V_152 * V_106 )
{
struct V_63 * V_64 = V_10 -> V_42 ;
struct V_18 * V_19 ;
struct V_13 * V_21 ;
unsigned int V_5 ;
if ( V_106 -> V_153 )
return;
for ( V_19 = F_18 ( V_64 -> V_66 ) ;
V_19 ;
V_19 = F_18 ( V_19 -> V_34 ) ) {
if ( V_19 -> V_75 != V_10 -> V_75 )
continue;
if ( V_106 -> V_154 >= V_106 -> V_155 ) {
if ( V_106 -> V_156 ( V_10 , ( unsigned long ) V_19 , V_106 ) < 0 ) {
V_106 -> V_153 = 1 ;
return;
}
}
V_106 -> V_154 ++ ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ ) {
for ( V_21 = F_18 ( V_19 -> V_19 [ V_5 ] ) ;
V_21 ;
V_21 = F_18 ( V_21 -> V_34 ) ) {
if ( V_106 -> V_154 < V_106 -> V_155 ) {
V_106 -> V_154 ++ ;
continue;
}
if ( V_106 -> V_156 ( V_10 , ( unsigned long ) V_21 , V_106 ) < 0 ) {
V_106 -> V_153 = 1 ;
return;
}
V_106 -> V_154 ++ ;
}
}
}
}
static int F_76 ( struct V_112 * V_112 , struct V_9 * V_10 , unsigned long V_157 ,
struct V_7 * V_8 , struct V_158 * V_159 )
{
struct V_13 * V_21 = (struct V_13 * ) V_157 ;
struct V_18 * V_62 , * V_47 ;
struct V_114 * V_160 ;
if ( V_21 == NULL )
return V_8 -> V_61 ;
V_159 -> V_161 = V_21 -> V_65 ;
V_160 = F_77 ( V_8 , V_135 ) ;
if ( V_160 == NULL )
goto V_162;
if ( F_23 ( V_21 -> V_65 ) == 0 ) {
struct V_18 * V_19 = (struct V_18 * ) V_157 ;
T_4 V_54 = V_19 -> V_54 + 1 ;
if ( F_78 ( V_8 , V_144 , V_54 ) )
goto V_162;
} else {
#ifdef F_6
struct V_147 * V_163 ;
int V_164 ;
#endif
if ( F_79 ( V_8 , V_146 ,
sizeof( V_21 -> V_3 ) + V_21 -> V_3 . V_39 * sizeof( struct V_29 ) ,
& V_21 -> V_3 ) )
goto V_162;
V_62 = F_18 ( V_21 -> V_62 ) ;
if ( V_62 ) {
T_4 V_137 = V_21 -> V_65 & 0xFFFFF000 ;
if ( F_78 ( V_8 , V_145 , V_137 ) )
goto V_162;
}
if ( V_21 -> V_12 . V_126 &&
F_78 ( V_8 , V_125 , V_21 -> V_12 . V_126 ) )
goto V_162;
V_47 = F_18 ( V_21 -> V_47 ) ;
if ( V_47 &&
F_78 ( V_8 , V_123 , V_47 -> V_65 ) )
goto V_162;
if ( V_21 -> V_33 && F_78 ( V_8 , V_140 , V_21 -> V_33 ) )
goto V_162;
#ifdef F_9
if ( ( V_21 -> V_37 || V_21 -> V_36 ) ) {
struct V_150 V_35 = { . V_37 = V_21 -> V_37 ,
. V_36 = V_21 -> V_36 ,
. V_165 = 0 } ;
int V_166 ;
F_80 (cpum) {
T_7 V_167 = * F_81 ( V_21 -> V_38 , V_166 ) ;
V_35 . V_165 += V_167 ;
}
if ( F_79 ( V_8 , V_149 , sizeof( V_35 ) , & V_35 ) )
goto V_162;
}
#endif
if ( F_82 ( V_8 , & V_21 -> V_52 ) < 0 )
goto V_162;
#ifdef F_12
if ( V_21 -> V_50 ) {
struct V_81 * V_82 ;
V_82 = F_83 ( V_112 , V_21 -> V_50 ) ;
if ( V_82 && F_84 ( V_8 , V_127 , V_82 -> V_168 ) )
goto V_162;
}
#endif
#ifdef F_6
V_163 = F_26 ( sizeof( struct V_147 ) +
V_21 -> V_3 . V_39 * sizeof( V_148 ) ,
V_72 ) ;
if ( ! V_163 )
goto V_162;
F_80 (cpu) {
int V_25 ;
struct V_147 * V_31 = F_81 ( V_21 -> V_31 , V_164 ) ;
V_163 -> V_32 += V_31 -> V_32 ;
V_163 -> V_51 += V_31 -> V_51 ;
for ( V_25 = 0 ; V_25 < V_21 -> V_3 . V_39 ; V_25 ++ )
V_163 -> V_46 [ V_25 ] += V_31 -> V_46 [ V_25 ] ;
}
if ( F_85 ( V_8 , V_169 ,
sizeof( struct V_147 ) +
V_21 -> V_3 . V_39 * sizeof( V_148 ) ,
V_163 , V_170 ) ) {
F_27 ( V_163 ) ;
goto V_162;
}
F_27 ( V_163 ) ;
#endif
}
F_86 ( V_8 , V_160 ) ;
if ( F_23 ( V_21 -> V_65 ) )
if ( F_87 ( V_8 , & V_21 -> V_52 ) < 0 )
goto V_162;
return V_8 -> V_61 ;
V_162:
F_88 ( V_8 , V_160 ) ;
return - 1 ;
}
static int T_8 F_89 ( void )
{
F_90 ( L_2 ) ;
#ifdef F_6
F_90 ( L_3 ) ;
#endif
#ifdef F_12
F_90 ( L_4 ) ;
#endif
#ifdef F_91
F_90 ( L_5 ) ;
#endif
return F_92 ( & V_171 ) ;
}
static void T_9 F_93 ( void )
{
F_94 ( & V_171 ) ;
}
