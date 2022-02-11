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
static void F_23 ( struct V_9 * V_10 , unsigned long V_68 )
{
}
static T_4 F_24 ( struct V_63 * V_64 )
{
int V_25 = 0x800 ;
do {
if ( ++ V_64 -> V_69 == 0x7FF )
V_64 -> V_69 = 1 ;
} while ( -- V_25 > 0 && F_16 ( V_64 , ( V_64 -> V_69 | 0x800 ) << 20 ) );
return V_25 > 0 ? ( V_64 -> V_69 | 0x800 ) << 20 : 0 ;
}
static int F_25 ( struct V_9 * V_10 )
{
struct V_18 * V_70 ;
struct V_63 * V_64 ;
V_64 = V_10 -> V_71 -> V_72 ;
V_70 = F_26 ( sizeof( * V_70 ) , V_73 ) ;
if ( V_70 == NULL )
return - V_74 ;
V_70 -> V_54 = 0 ;
V_70 -> V_75 ++ ;
V_70 -> V_65 = V_64 ? F_24 ( V_64 ) : 0x80000000 ;
V_70 -> V_76 = V_10 -> V_76 ;
if ( V_64 == NULL ) {
V_64 = F_26 ( sizeof( * V_64 ) , V_73 ) ;
if ( V_64 == NULL ) {
F_27 ( V_70 ) ;
return - V_74 ;
}
V_64 -> V_71 = V_10 -> V_71 ;
V_10 -> V_71 -> V_72 = V_64 ;
}
V_64 -> V_75 ++ ;
F_28 ( V_70 -> V_36 , V_64 -> V_66 ) ;
F_29 ( V_64 -> V_66 , V_70 ) ;
V_70 -> V_64 = V_64 ;
F_29 ( V_10 -> V_20 , V_70 ) ;
V_10 -> V_41 = V_64 ;
return 0 ;
}
static int F_30 ( struct V_9 * V_10 ,
struct V_13 * V_21 ,
bool V_77 )
{
F_31 ( & V_21 -> V_52 ) ;
if ( V_21 -> V_46 )
V_21 -> V_46 -> V_75 -- ;
#ifdef F_6
if ( V_77 )
F_32 ( V_21 -> V_31 ) ;
#endif
#ifdef F_8
if ( V_77 )
F_32 ( V_21 -> V_37 ) ;
#endif
F_27 ( V_21 ) ;
return 0 ;
}
static void F_33 ( struct V_78 * V_79 )
{
struct V_13 * V_1 = F_34 ( V_79 , struct V_13 , V_79 ) ;
F_30 ( V_1 -> V_10 , V_1 , false ) ;
}
static void F_35 ( struct V_78 * V_79 )
{
struct V_13 * V_1 = F_34 ( V_79 , struct V_13 , V_79 ) ;
F_30 ( V_1 -> V_10 , V_1 , true ) ;
}
static int F_36 ( struct V_9 * V_10 , struct V_13 * V_1 )
{
struct V_13 T_5 * * V_80 ;
struct V_13 * V_81 ;
struct V_18 * V_19 = F_17 ( V_1 -> V_62 ) ;
if ( V_19 ) {
V_80 = & V_19 -> V_19 [ F_19 ( V_1 -> V_65 ) ] ;
for ( V_81 = F_17 ( * V_80 ) ; V_81 ;
V_80 = & V_81 -> V_36 , V_81 = F_17 ( * V_80 ) ) {
if ( V_81 == V_1 ) {
F_28 ( * V_80 , V_1 -> V_36 ) ;
F_37 ( V_10 , & V_1 -> V_12 ) ;
F_38 ( & V_1 -> V_79 , F_35 ) ;
return 0 ;
}
}
}
F_39 ( 1 ) ;
return 0 ;
}
static void F_40 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_13 * V_21 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ ) {
while ( ( V_21 = F_17 ( V_19 -> V_19 [ V_5 ] ) ) != NULL ) {
F_28 ( V_19 -> V_19 [ V_5 ] ,
F_17 ( V_21 -> V_36 ) ) ;
F_37 ( V_10 , & V_21 -> V_12 ) ;
F_38 ( & V_21 -> V_79 , F_35 ) ;
}
}
}
static int F_41 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 T_5 * * V_82 ;
struct V_18 * V_83 ;
F_39 ( V_19 -> V_75 ) ;
F_40 ( V_10 , V_19 ) ;
V_82 = & V_64 -> V_66 ;
for ( V_83 = F_17 ( * V_82 ) ;
V_83 ;
V_82 = & V_83 -> V_36 , V_83 = F_17 ( * V_82 ) ) {
if ( V_83 == V_19 ) {
F_28 ( * V_82 , V_19 -> V_36 ) ;
F_42 ( V_19 , V_79 ) ;
return 0 ;
}
}
return - V_84 ;
}
static void F_43 ( struct V_9 * V_10 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * V_70 = F_17 ( V_10 -> V_20 ) ;
F_39 ( V_70 == NULL ) ;
if ( V_70 && -- V_70 -> V_75 == 0 )
F_41 ( V_10 , V_70 ) ;
if ( -- V_64 -> V_75 == 0 ) {
struct V_18 * V_19 ;
V_10 -> V_71 -> V_72 = NULL ;
for ( V_19 = F_17 ( V_64 -> V_66 ) ;
V_19 ;
V_19 = F_17 ( V_19 -> V_36 ) ) {
V_19 -> V_75 -- ;
F_40 ( V_10 , V_19 ) ;
}
while ( ( V_19 = F_17 ( V_64 -> V_66 ) ) != NULL ) {
F_28 ( V_64 -> V_66 , V_19 -> V_36 ) ;
F_42 ( V_19 , V_79 ) ;
}
F_27 ( V_64 ) ;
}
V_10 -> V_41 = NULL ;
}
static int F_44 ( struct V_9 * V_10 , unsigned long V_85 )
{
struct V_18 * V_19 = (struct V_18 * ) V_85 ;
struct V_18 * V_70 = F_17 ( V_10 -> V_20 ) ;
if ( V_19 == NULL )
return 0 ;
if ( F_22 ( V_19 -> V_65 ) )
return F_36 ( V_10 , (struct V_13 * ) V_19 ) ;
if ( V_70 == V_19 )
return - V_86 ;
if ( V_19 -> V_75 == 1 ) {
V_19 -> V_75 -- ;
F_41 ( V_10 , V_19 ) ;
} else {
return - V_87 ;
}
return 0 ;
}
static T_4 F_45 ( struct V_18 * V_19 , T_4 V_65 )
{
struct V_13 * V_21 ;
unsigned long V_25 ;
unsigned long * V_88 = F_26 ( F_46 ( V_89 ) * sizeof( unsigned long ) ,
V_73 ) ;
if ( ! V_88 )
return V_65 | 0xFFF ;
for ( V_21 = F_17 ( V_19 -> V_19 [ F_19 ( V_65 ) ] ) ;
V_21 ;
V_21 = F_17 ( V_21 -> V_36 ) )
F_47 ( F_48 ( V_21 -> V_65 ) , V_88 ) ;
V_25 = F_49 ( V_88 , V_89 , 0x800 ) ;
if ( V_25 >= V_89 )
V_25 = F_49 ( V_88 , V_89 , 1 ) ;
F_27 ( V_88 ) ;
return V_65 | ( V_25 >= V_89 ? 0xFFF : V_25 ) ;
}
static int F_50 ( struct V_90 * V_90 , struct V_9 * V_10 ,
unsigned long V_91 , struct V_18 * V_19 ,
struct V_13 * V_21 , struct V_92 * * V_93 ,
struct V_92 * V_94 , bool V_95 )
{
int V_96 ;
struct V_97 V_98 ;
F_51 ( & V_98 , V_99 , V_100 ) ;
V_96 = F_52 ( V_90 , V_10 , V_93 , V_94 , & V_98 , V_95 ) ;
if ( V_96 < 0 )
return V_96 ;
V_96 = - V_86 ;
if ( V_93 [ V_101 ] ) {
T_4 V_65 = F_53 ( V_93 [ V_101 ] ) ;
struct V_18 * V_46 = NULL , * V_102 ;
if ( F_22 ( V_65 ) )
goto V_103;
if ( V_65 ) {
V_46 = F_16 ( V_19 -> V_64 , V_65 ) ;
if ( V_46 == NULL )
goto V_103;
V_46 -> V_75 ++ ;
}
V_102 = F_17 ( V_21 -> V_46 ) ;
F_29 ( V_21 -> V_46 , V_46 ) ;
if ( V_102 )
V_102 -> V_75 -- ;
}
if ( V_93 [ V_104 ] ) {
V_21 -> V_12 . V_105 = F_53 ( V_93 [ V_104 ] ) ;
F_54 ( V_10 , & V_21 -> V_12 , V_91 ) ;
}
#ifdef F_11
if ( V_93 [ V_106 ] ) {
int V_107 ;
V_107 = F_55 ( V_90 , V_93 [ V_106 ] ) ;
if ( V_107 < 0 )
goto V_103;
V_21 -> V_50 = V_107 ;
}
#endif
F_56 ( V_10 , & V_21 -> V_52 , & V_98 ) ;
return 0 ;
V_103:
F_31 ( & V_98 ) ;
return V_96 ;
}
static void F_57 ( struct V_9 * V_10 ,
struct V_63 * V_64 ,
struct V_13 * V_21 )
{
struct V_13 T_5 * * V_108 ;
struct V_13 * V_109 ;
struct V_18 * V_19 ;
if ( F_21 ( V_21 -> V_65 ) == V_67 )
V_19 = F_17 ( V_10 -> V_20 ) ;
else
V_19 = F_16 ( V_64 , F_21 ( V_21 -> V_65 ) ) ;
V_108 = & V_19 -> V_19 [ F_19 ( V_21 -> V_65 ) ] ;
for ( V_109 = F_17 ( * V_108 ) ; ;
V_108 = & V_109 -> V_36 , V_109 = F_17 ( * V_108 ) )
if ( V_109 -> V_65 == V_21 -> V_65 )
break;
F_28 ( V_21 -> V_36 , V_109 -> V_36 ) ;
F_29 ( * V_108 , V_21 ) ;
}
static struct V_13 * F_58 ( struct V_9 * V_10 ,
struct V_13 * V_21 )
{
struct V_13 * V_110 ;
struct V_2 * V_111 = & V_21 -> V_3 ;
V_110 = F_26 ( sizeof( * V_21 ) + V_111 -> V_38 * sizeof( struct V_29 ) ,
V_73 ) ;
if ( ! V_110 )
return NULL ;
F_28 ( V_110 -> V_36 , V_21 -> V_36 ) ;
V_110 -> V_65 = V_21 -> V_65 ;
F_28 ( V_110 -> V_62 , V_21 -> V_62 ) ;
#ifdef F_11
V_110 -> V_50 = V_21 -> V_50 ;
#endif
V_110 -> V_4 = V_21 -> V_4 ;
V_110 -> V_12 = V_21 -> V_12 ;
F_28 ( V_110 -> V_46 , V_21 -> V_46 ) ;
if ( V_110 -> V_46 )
V_110 -> V_46 -> V_75 ++ ;
#ifdef F_6
V_110 -> V_31 = V_21 -> V_31 ;
#endif
#ifdef F_8
V_110 -> V_35 = V_21 -> V_35 ;
V_110 -> V_34 = V_21 -> V_34 ;
V_110 -> V_37 = V_21 -> V_37 ;
#endif
V_110 -> V_10 = V_10 ;
memcpy ( & V_110 -> V_3 , V_111 , sizeof( * V_111 ) + V_111 -> V_38 * sizeof( struct V_29 ) ) ;
F_51 ( & V_110 -> V_52 , V_99 , V_100 ) ;
return V_110 ;
}
static int F_59 ( struct V_90 * V_90 , struct V_7 * V_112 ,
struct V_9 * V_10 , unsigned long V_91 , T_4 V_65 ,
struct V_92 * * V_113 ,
unsigned long * V_85 , bool V_95 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * V_19 ;
struct V_13 * V_21 ;
struct V_2 * V_111 ;
struct V_92 * V_114 = V_113 [ V_115 ] ;
struct V_92 * V_93 [ V_116 + 1 ] ;
T_4 V_117 ;
int V_96 ;
#ifdef F_6
T_6 V_118 ;
#endif
if ( V_114 == NULL )
return V_65 ? - V_86 : 0 ;
V_96 = F_60 ( V_93 , V_116 , V_114 , V_119 ) ;
if ( V_96 < 0 )
return V_96 ;
V_21 = (struct V_13 * ) * V_85 ;
if ( V_21 ) {
struct V_13 * V_110 ;
if ( F_22 ( V_21 -> V_65 ) == 0 )
return - V_86 ;
V_110 = F_58 ( V_10 , V_21 ) ;
if ( ! V_110 )
return - V_120 ;
V_96 = F_50 ( V_90 , V_10 , V_91 ,
F_17 ( V_21 -> V_62 ) , V_110 , V_93 ,
V_113 [ V_121 ] , V_95 ) ;
if ( V_96 ) {
F_30 ( V_10 , V_110 , false ) ;
return V_96 ;
}
F_57 ( V_10 , V_64 , V_110 ) ;
F_37 ( V_10 , & V_21 -> V_12 ) ;
F_38 ( & V_21 -> V_79 , F_33 ) ;
return 0 ;
}
if ( V_93 [ V_122 ] ) {
unsigned int V_54 = F_53 ( V_93 [ V_122 ] ) ;
if ( -- V_54 > 0x100 )
return - V_86 ;
if ( F_22 ( V_65 ) )
return - V_86 ;
if ( V_65 == 0 ) {
V_65 = F_24 ( V_10 -> V_41 ) ;
if ( V_65 == 0 )
return - V_120 ;
}
V_19 = F_26 ( sizeof( * V_19 ) + V_54 * sizeof( void * ) , V_73 ) ;
if ( V_19 == NULL )
return - V_74 ;
V_19 -> V_64 = V_64 ;
V_19 -> V_75 = 1 ;
V_19 -> V_54 = V_54 ;
V_19 -> V_65 = V_65 ;
V_19 -> V_76 = V_10 -> V_76 ;
F_28 ( V_19 -> V_36 , V_64 -> V_66 ) ;
F_29 ( V_64 -> V_66 , V_19 ) ;
* V_85 = ( unsigned long ) V_19 ;
return 0 ;
}
if ( V_93 [ V_123 ] ) {
V_117 = F_53 ( V_93 [ V_123 ] ) ;
if ( F_21 ( V_117 ) == V_67 ) {
V_19 = F_17 ( V_10 -> V_20 ) ;
V_117 = V_19 -> V_65 ;
} else {
V_19 = F_16 ( V_10 -> V_41 , F_21 ( V_117 ) ) ;
if ( V_19 == NULL )
return - V_86 ;
}
} else {
V_19 = F_17 ( V_10 -> V_20 ) ;
V_117 = V_19 -> V_65 ;
}
if ( V_19 -> V_54 < F_19 ( V_117 ) )
return - V_86 ;
if ( V_65 ) {
if ( F_21 ( V_65 ) && F_21 ( V_65 ^ V_117 ) )
return - V_86 ;
V_65 = V_117 | F_48 ( V_65 ) ;
} else
V_65 = F_45 ( V_19 , V_117 ) ;
if ( V_93 [ V_124 ] == NULL )
return - V_86 ;
V_111 = F_61 ( V_93 [ V_124 ] ) ;
V_21 = F_26 ( sizeof( * V_21 ) + V_111 -> V_38 * sizeof( struct V_29 ) , V_73 ) ;
if ( V_21 == NULL )
return - V_74 ;
#ifdef F_6
V_118 = sizeof( struct V_125 ) + V_111 -> V_38 * sizeof( V_126 ) ;
V_21 -> V_31 = F_62 ( V_118 , F_63 ( struct V_125 ) ) ;
if ( ! V_21 -> V_31 ) {
F_27 ( V_21 ) ;
return - V_74 ;
}
#endif
memcpy ( & V_21 -> V_3 , V_111 , sizeof( * V_111 ) + V_111 -> V_38 * sizeof( struct V_29 ) ) ;
F_28 ( V_21 -> V_62 , V_19 ) ;
V_21 -> V_65 = V_65 ;
V_21 -> V_4 = V_111 -> V_6 ? F_64 ( F_2 ( V_111 -> V_6 ) ) - 1 : 0 ;
F_51 ( & V_21 -> V_52 , V_99 , V_100 ) ;
V_21 -> V_10 = V_10 ;
#ifdef F_8
V_21 -> V_37 = F_65 ( T_4 ) ;
if ( ! V_21 -> V_37 ) {
V_96 = - V_120 ;
goto V_103;
}
if ( V_93 [ V_127 ] ) {
struct V_128 * V_33 ;
V_33 = F_61 ( V_93 [ V_127 ] ) ;
V_21 -> V_35 = V_33 -> V_35 ;
V_21 -> V_34 = V_33 -> V_34 ;
}
#endif
V_96 = F_50 ( V_90 , V_10 , V_91 , V_19 , V_21 , V_93 , V_113 [ V_121 ] , V_95 ) ;
if ( V_96 == 0 ) {
struct V_13 T_5 * * V_108 ;
struct V_13 * V_109 ;
V_108 = & V_19 -> V_19 [ F_19 ( V_65 ) ] ;
for ( V_109 = F_17 ( * V_108 ) ; V_109 ;
V_108 = & V_109 -> V_36 , V_109 = F_17 ( * V_108 ) )
if ( F_48 ( V_65 ) < F_48 ( V_109 -> V_65 ) )
break;
F_28 ( V_21 -> V_36 , V_109 ) ;
F_29 ( * V_108 , V_21 ) ;
* V_85 = ( unsigned long ) V_21 ;
return 0 ;
}
#ifdef F_8
F_32 ( V_21 -> V_37 ) ;
V_103:
#endif
#ifdef F_6
F_32 ( V_21 -> V_31 ) ;
#endif
F_27 ( V_21 ) ;
return V_96 ;
}
static void F_66 ( struct V_9 * V_10 , struct V_129 * V_85 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * V_19 ;
struct V_13 * V_21 ;
unsigned int V_5 ;
if ( V_85 -> V_130 )
return;
for ( V_19 = F_17 ( V_64 -> V_66 ) ;
V_19 ;
V_19 = F_17 ( V_19 -> V_36 ) ) {
if ( V_19 -> V_76 != V_10 -> V_76 )
continue;
if ( V_85 -> V_131 >= V_85 -> V_132 ) {
if ( V_85 -> V_133 ( V_10 , ( unsigned long ) V_19 , V_85 ) < 0 ) {
V_85 -> V_130 = 1 ;
return;
}
}
V_85 -> V_131 ++ ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ ) {
for ( V_21 = F_17 ( V_19 -> V_19 [ V_5 ] ) ;
V_21 ;
V_21 = F_17 ( V_21 -> V_36 ) ) {
if ( V_85 -> V_131 < V_85 -> V_132 ) {
V_85 -> V_131 ++ ;
continue;
}
if ( V_85 -> V_133 ( V_10 , ( unsigned long ) V_21 , V_85 ) < 0 ) {
V_85 -> V_130 = 1 ;
return;
}
V_85 -> V_131 ++ ;
}
}
}
}
static int F_67 ( struct V_90 * V_90 , struct V_9 * V_10 , unsigned long V_134 ,
struct V_7 * V_8 , struct V_135 * V_136 )
{
struct V_13 * V_21 = (struct V_13 * ) V_134 ;
struct V_18 * V_62 , * V_46 ;
struct V_92 * V_137 ;
if ( V_21 == NULL )
return V_8 -> V_61 ;
V_136 -> V_138 = V_21 -> V_65 ;
V_137 = F_68 ( V_8 , V_115 ) ;
if ( V_137 == NULL )
goto V_139;
if ( F_22 ( V_21 -> V_65 ) == 0 ) {
struct V_18 * V_19 = (struct V_18 * ) V_134 ;
T_4 V_54 = V_19 -> V_54 + 1 ;
if ( F_69 ( V_8 , V_122 , V_54 ) )
goto V_139;
} else {
#ifdef F_6
struct V_125 * V_140 ;
int V_141 ;
#endif
if ( F_70 ( V_8 , V_124 ,
sizeof( V_21 -> V_3 ) + V_21 -> V_3 . V_38 * sizeof( struct V_29 ) ,
& V_21 -> V_3 ) )
goto V_139;
V_62 = F_17 ( V_21 -> V_62 ) ;
if ( V_62 ) {
T_4 V_117 = V_21 -> V_65 & 0xFFFFF000 ;
if ( F_69 ( V_8 , V_123 , V_117 ) )
goto V_139;
}
if ( V_21 -> V_12 . V_105 &&
F_69 ( V_8 , V_104 , V_21 -> V_12 . V_105 ) )
goto V_139;
V_46 = F_17 ( V_21 -> V_46 ) ;
if ( V_46 &&
F_69 ( V_8 , V_101 , V_46 -> V_65 ) )
goto V_139;
#ifdef F_8
if ( ( V_21 -> V_35 || V_21 -> V_34 ) ) {
struct V_128 V_33 = { . V_35 = V_21 -> V_35 ,
. V_34 = V_21 -> V_34 ,
. V_142 = 0 } ;
int V_143 ;
F_71 (cpum) {
T_7 V_144 = * F_72 ( V_21 -> V_37 , V_143 ) ;
V_33 . V_142 += V_144 ;
}
if ( F_70 ( V_8 , V_127 , sizeof( V_33 ) , & V_33 ) )
goto V_139;
}
#endif
if ( F_73 ( V_8 , & V_21 -> V_52 ) < 0 )
goto V_139;
#ifdef F_11
if ( V_21 -> V_50 ) {
struct V_145 * V_146 ;
V_146 = F_74 ( V_90 , V_21 -> V_50 ) ;
if ( V_146 && F_75 ( V_8 , V_106 , V_146 -> V_147 ) )
goto V_139;
}
#endif
#ifdef F_6
V_140 = F_26 ( sizeof( struct V_125 ) +
V_21 -> V_3 . V_38 * sizeof( V_126 ) ,
V_73 ) ;
if ( ! V_140 )
goto V_139;
F_71 (cpu) {
int V_25 ;
struct V_125 * V_31 = F_72 ( V_21 -> V_31 , V_141 ) ;
V_140 -> V_32 += V_31 -> V_32 ;
V_140 -> V_51 += V_31 -> V_51 ;
for ( V_25 = 0 ; V_25 < V_21 -> V_3 . V_38 ; V_25 ++ )
V_140 -> V_45 [ V_25 ] += V_31 -> V_45 [ V_25 ] ;
}
if ( F_70 ( V_8 , V_148 ,
sizeof( struct V_125 ) + V_21 -> V_3 . V_38 * sizeof( V_126 ) ,
V_140 ) ) {
F_27 ( V_140 ) ;
goto V_139;
}
F_27 ( V_140 ) ;
#endif
}
F_76 ( V_8 , V_137 ) ;
if ( F_22 ( V_21 -> V_65 ) )
if ( F_77 ( V_8 , & V_21 -> V_52 ) < 0 )
goto V_139;
return V_8 -> V_61 ;
V_139:
F_78 ( V_8 , V_137 ) ;
return - 1 ;
}
static int T_8 F_79 ( void )
{
F_80 ( L_2 ) ;
#ifdef F_6
F_80 ( L_3 ) ;
#endif
#ifdef F_11
F_80 ( L_4 ) ;
#endif
#ifdef F_81
F_80 ( L_5 ) ;
#endif
return F_82 ( & V_149 ) ;
}
static void T_9 F_83 ( void )
{
F_84 ( & V_149 ) ;
}
