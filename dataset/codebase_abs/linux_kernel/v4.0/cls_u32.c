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
static void F_39 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_13 * V_21 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ ) {
while ( ( V_21 = F_17 ( V_19 -> V_19 [ V_5 ] ) ) != NULL ) {
F_27 ( V_19 -> V_19 [ V_5 ] ,
F_17 ( V_21 -> V_36 ) ) ;
F_36 ( V_10 , & V_21 -> V_12 ) ;
F_37 ( & V_21 -> V_78 , F_34 ) ;
}
}
}
static int F_40 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 T_5 * * V_81 ;
struct V_18 * V_82 ;
F_38 ( V_19 -> V_74 ) ;
F_39 ( V_10 , V_19 ) ;
V_81 = & V_64 -> V_66 ;
for ( V_82 = F_17 ( * V_81 ) ;
V_82 ;
V_81 = & V_82 -> V_36 , V_82 = F_17 ( * V_81 ) ) {
if ( V_82 == V_19 ) {
F_27 ( * V_81 , V_19 -> V_36 ) ;
F_41 ( V_19 , V_78 ) ;
return 0 ;
}
}
return - V_83 ;
}
static void F_42 ( struct V_9 * V_10 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * V_69 = F_17 ( V_10 -> V_20 ) ;
F_38 ( V_69 == NULL ) ;
if ( V_69 && -- V_69 -> V_74 == 0 )
F_40 ( V_10 , V_69 ) ;
if ( -- V_64 -> V_74 == 0 ) {
struct V_18 * V_19 ;
V_10 -> V_70 -> V_71 = NULL ;
for ( V_19 = F_17 ( V_64 -> V_66 ) ;
V_19 ;
V_19 = F_17 ( V_19 -> V_36 ) ) {
V_19 -> V_74 -- ;
F_39 ( V_10 , V_19 ) ;
}
while ( ( V_19 = F_17 ( V_64 -> V_66 ) ) != NULL ) {
F_27 ( V_64 -> V_66 , V_19 -> V_36 ) ;
F_41 ( V_19 , V_78 ) ;
}
F_26 ( V_64 ) ;
}
V_10 -> V_41 = NULL ;
}
static int F_43 ( struct V_9 * V_10 , unsigned long V_84 )
{
struct V_18 * V_19 = (struct V_18 * ) V_84 ;
struct V_18 * V_69 = F_17 ( V_10 -> V_20 ) ;
if ( V_19 == NULL )
return 0 ;
if ( F_22 ( V_19 -> V_65 ) )
return F_35 ( V_10 , (struct V_13 * ) V_19 ) ;
if ( V_69 == V_19 )
return - V_85 ;
if ( V_19 -> V_74 == 1 ) {
V_19 -> V_74 -- ;
F_40 ( V_10 , V_19 ) ;
} else {
return - V_86 ;
}
return 0 ;
}
static T_4 F_44 ( struct V_18 * V_19 , T_4 V_65 )
{
struct V_13 * V_21 ;
unsigned long V_25 ;
unsigned long * V_87 = F_25 ( F_45 ( V_88 ) * sizeof( unsigned long ) ,
V_72 ) ;
if ( ! V_87 )
return V_65 | 0xFFF ;
for ( V_21 = F_17 ( V_19 -> V_19 [ F_19 ( V_65 ) ] ) ;
V_21 ;
V_21 = F_17 ( V_21 -> V_36 ) )
F_46 ( F_47 ( V_21 -> V_65 ) , V_87 ) ;
V_25 = F_48 ( V_87 , V_88 , 0x800 ) ;
if ( V_25 >= V_88 )
V_25 = F_48 ( V_87 , V_88 , 1 ) ;
F_26 ( V_87 ) ;
return V_65 | ( V_25 >= V_88 ? 0xFFF : V_25 ) ;
}
static int F_49 ( struct V_89 * V_89 , struct V_9 * V_10 ,
unsigned long V_90 , struct V_18 * V_19 ,
struct V_13 * V_21 , struct V_91 * * V_92 ,
struct V_91 * V_93 , bool V_94 )
{
int V_95 ;
struct V_96 V_97 ;
F_50 ( & V_97 , V_98 , V_99 ) ;
V_95 = F_51 ( V_89 , V_10 , V_92 , V_93 , & V_97 , V_94 ) ;
if ( V_95 < 0 )
return V_95 ;
V_95 = - V_85 ;
if ( V_92 [ V_100 ] ) {
T_4 V_65 = F_52 ( V_92 [ V_100 ] ) ;
struct V_18 * V_46 = NULL , * V_101 ;
if ( F_22 ( V_65 ) )
goto V_102;
if ( V_65 ) {
V_46 = F_16 ( V_19 -> V_64 , V_65 ) ;
if ( V_46 == NULL )
goto V_102;
V_46 -> V_74 ++ ;
}
V_101 = F_17 ( V_21 -> V_46 ) ;
F_28 ( V_21 -> V_46 , V_46 ) ;
if ( V_101 )
V_101 -> V_74 -- ;
}
if ( V_92 [ V_103 ] ) {
V_21 -> V_12 . V_104 = F_52 ( V_92 [ V_103 ] ) ;
F_53 ( V_10 , & V_21 -> V_12 , V_90 ) ;
}
#ifdef F_11
if ( V_92 [ V_105 ] ) {
int V_106 ;
V_106 = F_54 ( V_89 , V_92 [ V_105 ] ) ;
if ( V_106 < 0 )
goto V_102;
V_21 -> V_50 = V_106 ;
}
#endif
F_55 ( V_10 , & V_21 -> V_52 , & V_97 ) ;
return 0 ;
V_102:
F_30 ( & V_97 ) ;
return V_95 ;
}
static void F_56 ( struct V_9 * V_10 ,
struct V_63 * V_64 ,
struct V_13 * V_21 )
{
struct V_13 T_5 * * V_107 ;
struct V_13 * V_108 ;
struct V_18 * V_19 ;
if ( F_21 ( V_21 -> V_65 ) == V_67 )
V_19 = F_17 ( V_10 -> V_20 ) ;
else
V_19 = F_16 ( V_64 , F_21 ( V_21 -> V_65 ) ) ;
V_107 = & V_19 -> V_19 [ F_19 ( V_21 -> V_65 ) ] ;
for ( V_108 = F_17 ( * V_107 ) ; ;
V_107 = & V_108 -> V_36 , V_108 = F_17 ( * V_107 ) )
if ( V_108 -> V_65 == V_21 -> V_65 )
break;
F_27 ( V_21 -> V_36 , V_108 -> V_36 ) ;
F_28 ( * V_107 , V_21 ) ;
}
static struct V_13 * F_57 ( struct V_9 * V_10 ,
struct V_13 * V_21 )
{
struct V_13 * V_109 ;
struct V_2 * V_110 = & V_21 -> V_3 ;
V_109 = F_25 ( sizeof( * V_21 ) + V_110 -> V_38 * sizeof( struct V_29 ) ,
V_72 ) ;
if ( ! V_109 )
return NULL ;
F_27 ( V_109 -> V_36 , V_21 -> V_36 ) ;
V_109 -> V_65 = V_21 -> V_65 ;
F_27 ( V_109 -> V_62 , V_21 -> V_62 ) ;
#ifdef F_11
V_109 -> V_50 = V_21 -> V_50 ;
#endif
V_109 -> V_4 = V_21 -> V_4 ;
V_109 -> V_12 = V_21 -> V_12 ;
F_27 ( V_109 -> V_46 , V_21 -> V_46 ) ;
if ( V_109 -> V_46 )
V_109 -> V_46 -> V_74 ++ ;
#ifdef F_6
V_109 -> V_31 = V_21 -> V_31 ;
#endif
#ifdef F_8
V_109 -> V_35 = V_21 -> V_35 ;
V_109 -> V_34 = V_21 -> V_34 ;
V_109 -> V_37 = V_21 -> V_37 ;
#endif
V_109 -> V_10 = V_10 ;
memcpy ( & V_109 -> V_3 , V_110 , sizeof( * V_110 ) + V_110 -> V_38 * sizeof( struct V_29 ) ) ;
F_50 ( & V_109 -> V_52 , V_98 , V_99 ) ;
return V_109 ;
}
static int F_58 ( struct V_89 * V_89 , struct V_7 * V_111 ,
struct V_9 * V_10 , unsigned long V_90 , T_4 V_65 ,
struct V_91 * * V_112 ,
unsigned long * V_84 , bool V_94 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * V_19 ;
struct V_13 * V_21 ;
struct V_2 * V_110 ;
struct V_91 * V_113 = V_112 [ V_114 ] ;
struct V_91 * V_92 [ V_115 + 1 ] ;
T_4 V_116 ;
int V_95 ;
#ifdef F_6
T_6 V_117 ;
#endif
if ( V_113 == NULL )
return V_65 ? - V_85 : 0 ;
V_95 = F_59 ( V_92 , V_115 , V_113 , V_118 ) ;
if ( V_95 < 0 )
return V_95 ;
V_21 = (struct V_13 * ) * V_84 ;
if ( V_21 ) {
struct V_13 * V_109 ;
if ( F_22 ( V_21 -> V_65 ) == 0 )
return - V_85 ;
V_109 = F_57 ( V_10 , V_21 ) ;
if ( ! V_109 )
return - V_119 ;
V_95 = F_49 ( V_89 , V_10 , V_90 ,
F_17 ( V_21 -> V_62 ) , V_109 , V_92 ,
V_112 [ V_120 ] , V_94 ) ;
if ( V_95 ) {
F_29 ( V_10 , V_109 , false ) ;
return V_95 ;
}
F_56 ( V_10 , V_64 , V_109 ) ;
F_36 ( V_10 , & V_21 -> V_12 ) ;
F_37 ( & V_21 -> V_78 , F_32 ) ;
return 0 ;
}
if ( V_92 [ V_121 ] ) {
unsigned int V_54 = F_52 ( V_92 [ V_121 ] ) ;
if ( -- V_54 > 0x100 )
return - V_85 ;
if ( F_22 ( V_65 ) )
return - V_85 ;
if ( V_65 == 0 ) {
V_65 = F_23 ( V_10 -> V_41 ) ;
if ( V_65 == 0 )
return - V_119 ;
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
* V_84 = ( unsigned long ) V_19 ;
return 0 ;
}
if ( V_92 [ V_122 ] ) {
V_116 = F_52 ( V_92 [ V_122 ] ) ;
if ( F_21 ( V_116 ) == V_67 ) {
V_19 = F_17 ( V_10 -> V_20 ) ;
V_116 = V_19 -> V_65 ;
} else {
V_19 = F_16 ( V_10 -> V_41 , F_21 ( V_116 ) ) ;
if ( V_19 == NULL )
return - V_85 ;
}
} else {
V_19 = F_17 ( V_10 -> V_20 ) ;
V_116 = V_19 -> V_65 ;
}
if ( V_19 -> V_54 < F_19 ( V_116 ) )
return - V_85 ;
if ( V_65 ) {
if ( F_21 ( V_65 ) && F_21 ( V_65 ^ V_116 ) )
return - V_85 ;
V_65 = V_116 | F_47 ( V_65 ) ;
} else
V_65 = F_44 ( V_19 , V_116 ) ;
if ( V_92 [ V_123 ] == NULL )
return - V_85 ;
V_110 = F_60 ( V_92 [ V_123 ] ) ;
V_21 = F_25 ( sizeof( * V_21 ) + V_110 -> V_38 * sizeof( struct V_29 ) , V_72 ) ;
if ( V_21 == NULL )
return - V_73 ;
#ifdef F_6
V_117 = sizeof( struct V_124 ) + V_110 -> V_38 * sizeof( V_125 ) ;
V_21 -> V_31 = F_61 ( V_117 , F_62 ( struct V_124 ) ) ;
if ( ! V_21 -> V_31 ) {
F_26 ( V_21 ) ;
return - V_73 ;
}
#endif
memcpy ( & V_21 -> V_3 , V_110 , sizeof( * V_110 ) + V_110 -> V_38 * sizeof( struct V_29 ) ) ;
F_27 ( V_21 -> V_62 , V_19 ) ;
V_21 -> V_65 = V_65 ;
V_21 -> V_4 = V_110 -> V_6 ? F_63 ( F_2 ( V_110 -> V_6 ) ) - 1 : 0 ;
F_50 ( & V_21 -> V_52 , V_98 , V_99 ) ;
V_21 -> V_10 = V_10 ;
#ifdef F_8
V_21 -> V_37 = F_64 ( T_4 ) ;
if ( ! V_21 -> V_37 ) {
V_95 = - V_119 ;
goto V_102;
}
if ( V_92 [ V_126 ] ) {
struct V_127 * V_33 ;
V_33 = F_60 ( V_92 [ V_126 ] ) ;
V_21 -> V_35 = V_33 -> V_35 ;
V_21 -> V_34 = V_33 -> V_34 ;
}
#endif
V_95 = F_49 ( V_89 , V_10 , V_90 , V_19 , V_21 , V_92 , V_112 [ V_120 ] , V_94 ) ;
if ( V_95 == 0 ) {
struct V_13 T_5 * * V_107 ;
struct V_13 * V_108 ;
V_107 = & V_19 -> V_19 [ F_19 ( V_65 ) ] ;
for ( V_108 = F_17 ( * V_107 ) ; V_108 ;
V_107 = & V_108 -> V_36 , V_108 = F_17 ( * V_107 ) )
if ( F_47 ( V_65 ) < F_47 ( V_108 -> V_65 ) )
break;
F_27 ( V_21 -> V_36 , V_108 ) ;
F_28 ( * V_107 , V_21 ) ;
* V_84 = ( unsigned long ) V_21 ;
return 0 ;
}
#ifdef F_8
F_31 ( V_21 -> V_37 ) ;
V_102:
#endif
#ifdef F_6
F_31 ( V_21 -> V_31 ) ;
#endif
F_26 ( V_21 ) ;
return V_95 ;
}
static void F_65 ( struct V_9 * V_10 , struct V_128 * V_84 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * V_19 ;
struct V_13 * V_21 ;
unsigned int V_5 ;
if ( V_84 -> V_129 )
return;
for ( V_19 = F_17 ( V_64 -> V_66 ) ;
V_19 ;
V_19 = F_17 ( V_19 -> V_36 ) ) {
if ( V_19 -> V_75 != V_10 -> V_75 )
continue;
if ( V_84 -> V_130 >= V_84 -> V_131 ) {
if ( V_84 -> V_132 ( V_10 , ( unsigned long ) V_19 , V_84 ) < 0 ) {
V_84 -> V_129 = 1 ;
return;
}
}
V_84 -> V_130 ++ ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ ) {
for ( V_21 = F_17 ( V_19 -> V_19 [ V_5 ] ) ;
V_21 ;
V_21 = F_17 ( V_21 -> V_36 ) ) {
if ( V_84 -> V_130 < V_84 -> V_131 ) {
V_84 -> V_130 ++ ;
continue;
}
if ( V_84 -> V_132 ( V_10 , ( unsigned long ) V_21 , V_84 ) < 0 ) {
V_84 -> V_129 = 1 ;
return;
}
V_84 -> V_130 ++ ;
}
}
}
}
static int F_66 ( struct V_89 * V_89 , struct V_9 * V_10 , unsigned long V_133 ,
struct V_7 * V_8 , struct V_134 * V_135 )
{
struct V_13 * V_21 = (struct V_13 * ) V_133 ;
struct V_18 * V_62 , * V_46 ;
struct V_91 * V_136 ;
if ( V_21 == NULL )
return V_8 -> V_61 ;
V_135 -> V_137 = V_21 -> V_65 ;
V_136 = F_67 ( V_8 , V_114 ) ;
if ( V_136 == NULL )
goto V_138;
if ( F_22 ( V_21 -> V_65 ) == 0 ) {
struct V_18 * V_19 = (struct V_18 * ) V_133 ;
T_4 V_54 = V_19 -> V_54 + 1 ;
if ( F_68 ( V_8 , V_121 , V_54 ) )
goto V_138;
} else {
#ifdef F_6
struct V_124 * V_139 ;
int V_140 ;
#endif
if ( F_69 ( V_8 , V_123 ,
sizeof( V_21 -> V_3 ) + V_21 -> V_3 . V_38 * sizeof( struct V_29 ) ,
& V_21 -> V_3 ) )
goto V_138;
V_62 = F_17 ( V_21 -> V_62 ) ;
if ( V_62 ) {
T_4 V_116 = V_21 -> V_65 & 0xFFFFF000 ;
if ( F_68 ( V_8 , V_122 , V_116 ) )
goto V_138;
}
if ( V_21 -> V_12 . V_104 &&
F_68 ( V_8 , V_103 , V_21 -> V_12 . V_104 ) )
goto V_138;
V_46 = F_17 ( V_21 -> V_46 ) ;
if ( V_46 &&
F_68 ( V_8 , V_100 , V_46 -> V_65 ) )
goto V_138;
#ifdef F_8
if ( ( V_21 -> V_35 || V_21 -> V_34 ) ) {
struct V_127 V_33 = { . V_35 = V_21 -> V_35 ,
. V_34 = V_21 -> V_34 ,
. V_141 = 0 } ;
int V_142 ;
F_70 (cpum) {
T_7 V_143 = * F_71 ( V_21 -> V_37 , V_142 ) ;
V_33 . V_141 += V_143 ;
}
if ( F_69 ( V_8 , V_126 , sizeof( V_33 ) , & V_33 ) )
goto V_138;
}
#endif
if ( F_72 ( V_8 , & V_21 -> V_52 ) < 0 )
goto V_138;
#ifdef F_11
if ( V_21 -> V_50 ) {
struct V_144 * V_145 ;
V_145 = F_73 ( V_89 , V_21 -> V_50 ) ;
if ( V_145 && F_74 ( V_8 , V_105 , V_145 -> V_146 ) )
goto V_138;
}
#endif
#ifdef F_6
V_139 = F_25 ( sizeof( struct V_124 ) +
V_21 -> V_3 . V_38 * sizeof( V_125 ) ,
V_72 ) ;
if ( ! V_139 )
goto V_138;
F_70 (cpu) {
int V_25 ;
struct V_124 * V_31 = F_71 ( V_21 -> V_31 , V_140 ) ;
V_139 -> V_32 += V_31 -> V_32 ;
V_139 -> V_51 += V_31 -> V_51 ;
for ( V_25 = 0 ; V_25 < V_21 -> V_3 . V_38 ; V_25 ++ )
V_139 -> V_45 [ V_25 ] += V_31 -> V_45 [ V_25 ] ;
}
if ( F_69 ( V_8 , V_147 ,
sizeof( struct V_124 ) + V_21 -> V_3 . V_38 * sizeof( V_125 ) ,
V_139 ) ) {
F_26 ( V_139 ) ;
goto V_138;
}
F_26 ( V_139 ) ;
#endif
}
F_75 ( V_8 , V_136 ) ;
if ( F_22 ( V_21 -> V_65 ) )
if ( F_76 ( V_8 , & V_21 -> V_52 ) < 0 )
goto V_138;
return V_8 -> V_61 ;
V_138:
F_77 ( V_8 , V_136 ) ;
return - 1 ;
}
static int T_8 F_78 ( void )
{
F_79 ( L_2 ) ;
#ifdef F_6
F_79 ( L_3 ) ;
#endif
#ifdef F_11
F_79 ( L_4 ) ;
#endif
#ifdef F_80
F_79 ( L_5 ) ;
#endif
return F_81 ( & V_148 ) ;
}
static void T_9 F_82 ( void )
{
F_83 ( & V_148 ) ;
}
