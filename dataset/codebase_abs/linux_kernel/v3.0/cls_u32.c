static inline unsigned int F_1 ( T_1 V_1 ,
const struct V_2 * V_3 ,
T_2 V_4 )
{
unsigned int V_5 = F_2 ( V_1 & V_3 -> V_6 ) >> V_4 ;
return V_5 ;
}
static int F_3 ( struct V_7 * V_8 , struct V_9 * V_10 , struct V_11 * V_12 )
{
struct {
struct V_13 * V_14 ;
unsigned int V_15 ;
} V_16 [ V_17 ] ;
struct V_18 * V_19 = (struct V_18 * ) V_10 -> V_20 ;
unsigned int V_15 = F_4 ( V_8 ) ;
struct V_13 * V_21 ;
int V_22 = 0 ;
int V_23 = 0 ;
int V_3 = 0 ;
#ifdef F_5
int V_24 ;
#endif
int V_25 , V_26 ;
V_27:
V_21 = V_19 -> V_19 [ V_3 ] ;
V_28:
if ( V_21 ) {
struct V_29 * V_1 = V_21 -> V_3 . V_30 ;
#ifdef F_5
V_21 -> V_31 -> V_32 += 1 ;
V_24 = 0 ;
#endif
#ifdef F_6
if ( ( V_8 -> V_33 & V_21 -> V_33 . V_34 ) != V_21 -> V_33 . V_35 ) {
V_21 = V_21 -> V_36 ;
goto V_28;
} else {
V_21 -> V_33 . V_37 ++ ;
}
#endif
for ( V_25 = V_21 -> V_3 . V_38 ; V_25 > 0 ; V_25 -- , V_1 ++ ) {
int V_39 = V_15 + V_1 -> V_15 + ( V_23 & V_1 -> V_40 ) ;
T_1 * V_41 , V_42 ;
if ( F_7 ( V_8 ) + V_39 > V_43 )
goto V_44;
V_41 = F_8 ( V_8 , V_39 , 4 , & V_42 ) ;
if ( ! V_41 )
goto V_44;
if ( ( * V_41 ^ V_1 -> V_35 ) & V_1 -> V_34 ) {
V_21 = V_21 -> V_36 ;
goto V_28;
}
#ifdef F_5
V_21 -> V_31 -> V_45 [ V_24 ] += 1 ;
V_24 ++ ;
#endif
}
if ( V_21 -> V_46 == NULL ) {
V_47:
if ( V_21 -> V_3 . V_48 & V_49 ) {
* V_12 = V_21 -> V_12 ;
#ifdef F_9
if ( ! F_10 ( V_8 , V_21 -> V_50 ) ) {
V_21 = V_21 -> V_36 ;
goto V_28;
}
#endif
#ifdef F_5
V_21 -> V_31 -> V_51 += 1 ;
#endif
V_26 = F_11 ( V_8 , & V_21 -> V_52 , V_12 ) ;
if ( V_26 < 0 ) {
V_21 = V_21 -> V_36 ;
goto V_28;
}
return V_26 ;
}
V_21 = V_21 -> V_36 ;
goto V_28;
}
if ( V_22 >= V_17 )
goto V_53;
V_16 [ V_22 ] . V_14 = V_21 ;
V_16 [ V_22 ] . V_15 = V_15 ;
V_22 ++ ;
V_19 = V_21 -> V_46 ;
V_3 = 0 ;
if ( V_19 -> V_54 ) {
T_1 * V_41 , V_42 ;
V_41 = F_8 ( V_8 , V_15 + V_21 -> V_3 . V_55 , 4 ,
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
V_41 = F_8 ( V_8 ,
V_15 + V_21 -> V_3 . V_59 ,
2 , & V_42 ) ;
if ( ! V_41 )
goto V_44;
V_23 += F_12 ( V_21 -> V_3 . V_40 & * V_41 ) >>
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
V_19 = V_21 -> V_62 ;
V_15 = V_16 [ V_22 ] . V_15 ;
goto V_47;
}
V_44:
return - 1 ;
V_53:
if ( F_13 () )
F_14 ( L_1 ) ;
return - 1 ;
}
static struct V_18 *
F_15 ( struct V_63 * V_64 , T_4 V_65 )
{
struct V_18 * V_19 ;
for ( V_19 = V_64 -> V_66 ; V_19 ; V_19 = V_19 -> V_36 )
if ( V_19 -> V_65 == V_65 )
break;
return V_19 ;
}
static struct V_13 *
F_16 ( struct V_18 * V_19 , T_4 V_65 )
{
unsigned int V_3 ;
struct V_13 * V_21 = NULL ;
V_3 = F_17 ( V_65 ) ;
if ( V_3 > V_19 -> V_54 )
goto V_44;
for ( V_21 = V_19 -> V_19 [ V_3 ] ; V_21 ; V_21 = V_21 -> V_36 )
if ( V_21 -> V_65 == V_65 )
break;
V_44:
return V_21 ;
}
static unsigned long F_18 ( struct V_9 * V_10 , T_4 V_65 )
{
struct V_18 * V_19 ;
struct V_63 * V_64 = V_10 -> V_41 ;
if ( F_19 ( V_65 ) == V_67 )
V_19 = V_10 -> V_20 ;
else
V_19 = F_15 ( V_64 , F_19 ( V_65 ) ) ;
if ( ! V_19 )
return 0 ;
if ( F_20 ( V_65 ) == 0 )
return ( unsigned long ) V_19 ;
return ( unsigned long ) F_16 ( V_19 , V_65 ) ;
}
static void F_21 ( struct V_9 * V_10 , unsigned long V_68 )
{
}
static T_4 F_22 ( struct V_63 * V_64 )
{
int V_25 = 0x800 ;
do {
if ( ++ V_64 -> V_69 == 0x7FF )
V_64 -> V_69 = 1 ;
} while ( -- V_25 > 0 && F_15 ( V_64 , ( V_64 -> V_69 | 0x800 ) << 20 ) );
return V_25 > 0 ? ( V_64 -> V_69 | 0x800 ) << 20 : 0 ;
}
static int F_23 ( struct V_9 * V_10 )
{
struct V_18 * V_70 ;
struct V_63 * V_64 ;
V_64 = V_10 -> V_71 -> V_72 ;
V_70 = F_24 ( sizeof( * V_70 ) , V_73 ) ;
if ( V_70 == NULL )
return - V_74 ;
V_70 -> V_54 = 0 ;
V_70 -> V_75 ++ ;
V_70 -> V_65 = V_64 ? F_22 ( V_64 ) : 0x80000000 ;
V_70 -> V_76 = V_10 -> V_76 ;
if ( V_64 == NULL ) {
V_64 = F_24 ( sizeof( * V_64 ) , V_73 ) ;
if ( V_64 == NULL ) {
F_25 ( V_70 ) ;
return - V_74 ;
}
V_64 -> V_71 = V_10 -> V_71 ;
V_10 -> V_71 -> V_72 = V_64 ;
}
V_64 -> V_75 ++ ;
V_70 -> V_36 = V_64 -> V_66 ;
V_64 -> V_66 = V_70 ;
V_70 -> V_64 = V_64 ;
V_10 -> V_20 = V_70 ;
V_10 -> V_41 = V_64 ;
return 0 ;
}
static int F_26 ( struct V_9 * V_10 , struct V_13 * V_21 )
{
F_27 ( V_10 , & V_21 -> V_12 ) ;
F_28 ( V_10 , & V_21 -> V_52 ) ;
if ( V_21 -> V_46 )
V_21 -> V_46 -> V_75 -- ;
#ifdef F_5
F_25 ( V_21 -> V_31 ) ;
#endif
F_25 ( V_21 ) ;
return 0 ;
}
static int F_29 ( struct V_9 * V_10 , struct V_13 * V_1 )
{
struct V_13 * * V_77 ;
struct V_18 * V_19 = V_1 -> V_62 ;
if ( V_19 ) {
for ( V_77 = & V_19 -> V_19 [ F_17 ( V_1 -> V_65 ) ] ; * V_77 ; V_77 = & ( * V_77 ) -> V_36 ) {
if ( * V_77 == V_1 ) {
F_30 ( V_10 ) ;
* V_77 = V_1 -> V_36 ;
F_31 ( V_10 ) ;
F_26 ( V_10 , V_1 ) ;
return 0 ;
}
}
}
F_32 ( 1 ) ;
return 0 ;
}
static void F_33 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_13 * V_21 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ ) {
while ( ( V_21 = V_19 -> V_19 [ V_5 ] ) != NULL ) {
V_19 -> V_19 [ V_5 ] = V_21 -> V_36 ;
F_26 ( V_10 , V_21 ) ;
}
}
}
static int F_34 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * * V_78 ;
F_32 ( V_19 -> V_75 ) ;
F_33 ( V_10 , V_19 ) ;
for ( V_78 = & V_64 -> V_66 ; * V_78 ; V_78 = & ( * V_78 ) -> V_36 ) {
if ( * V_78 == V_19 ) {
* V_78 = V_19 -> V_36 ;
F_25 ( V_19 ) ;
return 0 ;
}
}
F_32 ( 1 ) ;
return - V_79 ;
}
static void F_35 ( struct V_9 * V_10 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * V_70 = V_10 -> V_20 ;
F_32 ( V_70 == NULL ) ;
if ( V_70 && -- V_70 -> V_75 == 0 )
F_34 ( V_10 , V_70 ) ;
if ( -- V_64 -> V_75 == 0 ) {
struct V_18 * V_19 ;
V_10 -> V_71 -> V_72 = NULL ;
for ( V_19 = V_64 -> V_66 ; V_19 ; V_19 = V_19 -> V_36 ) {
V_19 -> V_75 -- ;
F_33 ( V_10 , V_19 ) ;
}
while ( ( V_19 = V_64 -> V_66 ) != NULL ) {
V_64 -> V_66 = V_19 -> V_36 ;
F_32 ( V_19 -> V_75 != 0 ) ;
F_25 ( V_19 ) ;
}
F_25 ( V_64 ) ;
}
V_10 -> V_41 = NULL ;
}
static int F_36 ( struct V_9 * V_10 , unsigned long V_80 )
{
struct V_18 * V_19 = (struct V_18 * ) V_80 ;
if ( V_19 == NULL )
return 0 ;
if ( F_20 ( V_19 -> V_65 ) )
return F_29 ( V_10 , (struct V_13 * ) V_19 ) ;
if ( V_10 -> V_20 == V_19 )
return - V_81 ;
if ( V_19 -> V_75 == 1 ) {
V_19 -> V_75 -- ;
F_34 ( V_10 , V_19 ) ;
} else {
return - V_82 ;
}
return 0 ;
}
static T_4 F_37 ( struct V_18 * V_19 , T_4 V_65 )
{
struct V_13 * V_21 ;
unsigned int V_25 = 0x7FF ;
for ( V_21 = V_19 -> V_19 [ F_17 ( V_65 ) ] ; V_21 ; V_21 = V_21 -> V_36 )
if ( V_25 < F_38 ( V_21 -> V_65 ) )
V_25 = F_38 ( V_21 -> V_65 ) ;
V_25 ++ ;
return V_65 | ( V_25 > 0xFFF ? 0xFFF : V_25 ) ;
}
static int F_39 ( struct V_9 * V_10 , unsigned long V_83 ,
struct V_18 * V_19 ,
struct V_13 * V_21 , struct V_84 * * V_85 ,
struct V_84 * V_86 )
{
int V_87 ;
struct V_88 V_89 ;
V_87 = F_40 ( V_10 , V_85 , V_86 , & V_89 , & V_90 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 = - V_81 ;
if ( V_85 [ V_91 ] ) {
T_4 V_65 = F_41 ( V_85 [ V_91 ] ) ;
struct V_18 * V_46 = NULL , * V_92 ;
if ( F_20 ( V_65 ) )
goto V_93;
if ( V_65 ) {
V_46 = F_15 ( V_19 -> V_64 , V_65 ) ;
if ( V_46 == NULL )
goto V_93;
V_46 -> V_75 ++ ;
}
F_30 ( V_10 ) ;
V_92 = V_21 -> V_46 ;
V_21 -> V_46 = V_46 ;
F_31 ( V_10 ) ;
if ( V_92 )
V_92 -> V_75 -- ;
}
if ( V_85 [ V_94 ] ) {
V_21 -> V_12 . V_95 = F_41 ( V_85 [ V_94 ] ) ;
F_42 ( V_10 , & V_21 -> V_12 , V_83 ) ;
}
#ifdef F_9
if ( V_85 [ V_96 ] ) {
V_87 = F_43 ( V_10 , V_21 -> V_50 , V_85 [ V_96 ] ) ;
if ( V_87 < 0 )
goto V_93;
}
#endif
F_44 ( V_10 , & V_21 -> V_52 , & V_89 ) ;
return 0 ;
V_93:
F_28 ( V_10 , & V_89 ) ;
return V_87 ;
}
static int F_45 ( struct V_9 * V_10 , unsigned long V_83 , T_4 V_65 ,
struct V_84 * * V_97 ,
unsigned long * V_80 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * V_19 ;
struct V_13 * V_21 ;
struct V_2 * V_98 ;
struct V_84 * V_99 = V_97 [ V_100 ] ;
struct V_84 * V_85 [ V_101 + 1 ] ;
T_4 V_102 ;
int V_87 ;
if ( V_99 == NULL )
return V_65 ? - V_81 : 0 ;
V_87 = F_46 ( V_85 , V_101 , V_99 , V_103 ) ;
if ( V_87 < 0 )
return V_87 ;
V_21 = (struct V_13 * ) * V_80 ;
if ( V_21 ) {
if ( F_20 ( V_21 -> V_65 ) == 0 )
return - V_81 ;
return F_39 ( V_10 , V_83 , V_21 -> V_62 , V_21 , V_85 , V_97 [ V_104 ] ) ;
}
if ( V_85 [ V_105 ] ) {
unsigned int V_54 = F_41 ( V_85 [ V_105 ] ) ;
if ( -- V_54 > 0x100 )
return - V_81 ;
if ( F_20 ( V_65 ) )
return - V_81 ;
if ( V_65 == 0 ) {
V_65 = F_22 ( V_10 -> V_41 ) ;
if ( V_65 == 0 )
return - V_106 ;
}
V_19 = F_24 ( sizeof( * V_19 ) + V_54 * sizeof( void * ) , V_73 ) ;
if ( V_19 == NULL )
return - V_74 ;
V_19 -> V_64 = V_64 ;
V_19 -> V_75 = 1 ;
V_19 -> V_54 = V_54 ;
V_19 -> V_65 = V_65 ;
V_19 -> V_76 = V_10 -> V_76 ;
V_19 -> V_36 = V_64 -> V_66 ;
V_64 -> V_66 = V_19 ;
* V_80 = ( unsigned long ) V_19 ;
return 0 ;
}
if ( V_85 [ V_107 ] ) {
V_102 = F_41 ( V_85 [ V_107 ] ) ;
if ( F_19 ( V_102 ) == V_67 ) {
V_19 = V_10 -> V_20 ;
V_102 = V_19 -> V_65 ;
} else {
V_19 = F_15 ( V_10 -> V_41 , F_19 ( V_102 ) ) ;
if ( V_19 == NULL )
return - V_81 ;
}
} else {
V_19 = V_10 -> V_20 ;
V_102 = V_19 -> V_65 ;
}
if ( V_19 -> V_54 < F_17 ( V_102 ) )
return - V_81 ;
if ( V_65 ) {
if ( F_19 ( V_65 ) && F_19 ( V_65 ^ V_102 ) )
return - V_81 ;
V_65 = V_102 | F_38 ( V_65 ) ;
} else
V_65 = F_37 ( V_19 , V_102 ) ;
if ( V_85 [ V_108 ] == NULL )
return - V_81 ;
V_98 = F_47 ( V_85 [ V_108 ] ) ;
V_21 = F_24 ( sizeof( * V_21 ) + V_98 -> V_38 * sizeof( struct V_29 ) , V_73 ) ;
if ( V_21 == NULL )
return - V_74 ;
#ifdef F_5
V_21 -> V_31 = F_24 ( sizeof( struct V_109 ) + V_98 -> V_38 * sizeof( V_110 ) , V_73 ) ;
if ( V_21 -> V_31 == NULL ) {
F_25 ( V_21 ) ;
return - V_74 ;
}
#endif
memcpy ( & V_21 -> V_3 , V_98 , sizeof( * V_98 ) + V_98 -> V_38 * sizeof( struct V_29 ) ) ;
V_21 -> V_62 = V_19 ;
V_21 -> V_65 = V_65 ;
V_21 -> V_4 = V_98 -> V_6 ? F_48 ( F_2 ( V_98 -> V_6 ) ) - 1 : 0 ;
#ifdef F_6
if ( V_85 [ V_111 ] ) {
struct V_112 * V_33 ;
V_33 = F_47 ( V_85 [ V_111 ] ) ;
memcpy ( & V_21 -> V_33 , V_33 , sizeof( struct V_112 ) ) ;
V_21 -> V_33 . V_37 = 0 ;
}
#endif
V_87 = F_39 ( V_10 , V_83 , V_19 , V_21 , V_85 , V_97 [ V_104 ] ) ;
if ( V_87 == 0 ) {
struct V_13 * * V_113 ;
for ( V_113 = & V_19 -> V_19 [ F_17 ( V_65 ) ] ; * V_113 ; V_113 = & ( * V_113 ) -> V_36 )
if ( F_38 ( V_65 ) < F_38 ( ( * V_113 ) -> V_65 ) )
break;
V_21 -> V_36 = * V_113 ;
F_30 ( V_10 ) ;
* V_113 = V_21 ;
F_31 ( V_10 ) ;
* V_80 = ( unsigned long ) V_21 ;
return 0 ;
}
#ifdef F_5
F_25 ( V_21 -> V_31 ) ;
#endif
F_25 ( V_21 ) ;
return V_87 ;
}
static void F_49 ( struct V_9 * V_10 , struct V_114 * V_80 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * V_19 ;
struct V_13 * V_21 ;
unsigned int V_5 ;
if ( V_80 -> V_115 )
return;
for ( V_19 = V_64 -> V_66 ; V_19 ; V_19 = V_19 -> V_36 ) {
if ( V_19 -> V_76 != V_10 -> V_76 )
continue;
if ( V_80 -> V_116 >= V_80 -> V_117 ) {
if ( V_80 -> V_118 ( V_10 , ( unsigned long ) V_19 , V_80 ) < 0 ) {
V_80 -> V_115 = 1 ;
return;
}
}
V_80 -> V_116 ++ ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ ) {
for ( V_21 = V_19 -> V_19 [ V_5 ] ; V_21 ; V_21 = V_21 -> V_36 ) {
if ( V_80 -> V_116 < V_80 -> V_117 ) {
V_80 -> V_116 ++ ;
continue;
}
if ( V_80 -> V_118 ( V_10 , ( unsigned long ) V_21 , V_80 ) < 0 ) {
V_80 -> V_115 = 1 ;
return;
}
V_80 -> V_116 ++ ;
}
}
}
}
static int F_50 ( struct V_9 * V_10 , unsigned long V_119 ,
struct V_7 * V_8 , struct V_120 * V_121 )
{
struct V_13 * V_21 = (struct V_13 * ) V_119 ;
struct V_84 * V_122 ;
if ( V_21 == NULL )
return V_8 -> V_61 ;
V_121 -> V_123 = V_21 -> V_65 ;
V_122 = F_51 ( V_8 , V_100 ) ;
if ( V_122 == NULL )
goto V_124;
if ( F_20 ( V_21 -> V_65 ) == 0 ) {
struct V_18 * V_19 = (struct V_18 * ) V_119 ;
T_4 V_54 = V_19 -> V_54 + 1 ;
F_52 ( V_8 , V_105 , V_54 ) ;
} else {
F_53 ( V_8 , V_108 ,
sizeof( V_21 -> V_3 ) + V_21 -> V_3 . V_38 * sizeof( struct V_29 ) ,
& V_21 -> V_3 ) ;
if ( V_21 -> V_62 ) {
T_4 V_102 = V_21 -> V_65 & 0xFFFFF000 ;
F_52 ( V_8 , V_107 , V_102 ) ;
}
if ( V_21 -> V_12 . V_95 )
F_52 ( V_8 , V_94 , V_21 -> V_12 . V_95 ) ;
if ( V_21 -> V_46 )
F_52 ( V_8 , V_91 , V_21 -> V_46 -> V_65 ) ;
#ifdef F_6
if ( V_21 -> V_33 . V_35 || V_21 -> V_33 . V_34 )
F_53 ( V_8 , V_111 , sizeof( V_21 -> V_33 ) , & V_21 -> V_33 ) ;
#endif
if ( F_54 ( V_8 , & V_21 -> V_52 , & V_90 ) < 0 )
goto V_124;
#ifdef F_9
if ( strlen ( V_21 -> V_50 ) )
F_55 ( V_8 , V_96 , V_21 -> V_50 ) ;
#endif
#ifdef F_5
F_53 ( V_8 , V_125 ,
sizeof( struct V_109 ) + V_21 -> V_3 . V_38 * sizeof( V_110 ) ,
V_21 -> V_31 ) ;
#endif
}
F_56 ( V_8 , V_122 ) ;
if ( F_20 ( V_21 -> V_65 ) )
if ( F_57 ( V_8 , & V_21 -> V_52 , & V_90 ) < 0 )
goto V_124;
return V_8 -> V_61 ;
V_124:
F_58 ( V_8 , V_122 ) ;
return - 1 ;
}
static int T_5 F_59 ( void )
{
F_60 ( L_2 ) ;
#ifdef F_5
F_60 ( L_3 ) ;
#endif
#ifdef F_9
F_60 ( L_4 ) ;
#endif
#ifdef F_61
F_60 ( L_5 ) ;
#endif
return F_62 ( & V_126 ) ;
}
static void T_6 F_63 ( void )
{
F_64 ( & V_126 ) ;
}
