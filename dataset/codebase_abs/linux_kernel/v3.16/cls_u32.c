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
struct V_18 * V_19 = V_10 -> V_20 ;
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
F_13 ( L_1 ) ;
return - 1 ;
}
static struct V_18 *
F_14 ( struct V_63 * V_64 , T_4 V_65 )
{
struct V_18 * V_19 ;
for ( V_19 = V_64 -> V_66 ; V_19 ; V_19 = V_19 -> V_36 )
if ( V_19 -> V_65 == V_65 )
break;
return V_19 ;
}
static struct V_13 *
F_15 ( struct V_18 * V_19 , T_4 V_65 )
{
unsigned int V_3 ;
struct V_13 * V_21 = NULL ;
V_3 = F_16 ( V_65 ) ;
if ( V_3 > V_19 -> V_54 )
goto V_44;
for ( V_21 = V_19 -> V_19 [ V_3 ] ; V_21 ; V_21 = V_21 -> V_36 )
if ( V_21 -> V_65 == V_65 )
break;
V_44:
return V_21 ;
}
static unsigned long F_17 ( struct V_9 * V_10 , T_4 V_65 )
{
struct V_18 * V_19 ;
struct V_63 * V_64 = V_10 -> V_41 ;
if ( F_18 ( V_65 ) == V_67 )
V_19 = V_10 -> V_20 ;
else
V_19 = F_14 ( V_64 , F_18 ( V_65 ) ) ;
if ( ! V_19 )
return 0 ;
if ( F_19 ( V_65 ) == 0 )
return ( unsigned long ) V_19 ;
return ( unsigned long ) F_15 ( V_19 , V_65 ) ;
}
static void F_20 ( struct V_9 * V_10 , unsigned long V_68 )
{
}
static T_4 F_21 ( struct V_63 * V_64 )
{
int V_25 = 0x800 ;
do {
if ( ++ V_64 -> V_69 == 0x7FF )
V_64 -> V_69 = 1 ;
} while ( -- V_25 > 0 && F_14 ( V_64 , ( V_64 -> V_69 | 0x800 ) << 20 ) );
return V_25 > 0 ? ( V_64 -> V_69 | 0x800 ) << 20 : 0 ;
}
static int F_22 ( struct V_9 * V_10 )
{
struct V_18 * V_70 ;
struct V_63 * V_64 ;
V_64 = V_10 -> V_71 -> V_72 ;
V_70 = F_23 ( sizeof( * V_70 ) , V_73 ) ;
if ( V_70 == NULL )
return - V_74 ;
V_70 -> V_54 = 0 ;
V_70 -> V_75 ++ ;
V_70 -> V_65 = V_64 ? F_21 ( V_64 ) : 0x80000000 ;
V_70 -> V_76 = V_10 -> V_76 ;
if ( V_64 == NULL ) {
V_64 = F_23 ( sizeof( * V_64 ) , V_73 ) ;
if ( V_64 == NULL ) {
F_24 ( V_70 ) ;
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
static int F_25 ( struct V_9 * V_10 , struct V_13 * V_21 )
{
F_26 ( V_10 , & V_21 -> V_12 ) ;
F_27 ( V_10 , & V_21 -> V_52 ) ;
if ( V_21 -> V_46 )
V_21 -> V_46 -> V_75 -- ;
#ifdef F_5
F_24 ( V_21 -> V_31 ) ;
#endif
F_24 ( V_21 ) ;
return 0 ;
}
static int F_28 ( struct V_9 * V_10 , struct V_13 * V_1 )
{
struct V_13 * * V_77 ;
struct V_18 * V_19 = V_1 -> V_62 ;
if ( V_19 ) {
for ( V_77 = & V_19 -> V_19 [ F_16 ( V_1 -> V_65 ) ] ; * V_77 ; V_77 = & ( * V_77 ) -> V_36 ) {
if ( * V_77 == V_1 ) {
F_29 ( V_10 ) ;
* V_77 = V_1 -> V_36 ;
F_30 ( V_10 ) ;
F_25 ( V_10 , V_1 ) ;
return 0 ;
}
}
}
F_31 ( 1 ) ;
return 0 ;
}
static void F_32 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_13 * V_21 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ ) {
while ( ( V_21 = V_19 -> V_19 [ V_5 ] ) != NULL ) {
V_19 -> V_19 [ V_5 ] = V_21 -> V_36 ;
F_25 ( V_10 , V_21 ) ;
}
}
}
static int F_33 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * * V_78 ;
F_31 ( V_19 -> V_75 ) ;
F_32 ( V_10 , V_19 ) ;
for ( V_78 = & V_64 -> V_66 ; * V_78 ; V_78 = & ( * V_78 ) -> V_36 ) {
if ( * V_78 == V_19 ) {
* V_78 = V_19 -> V_36 ;
F_24 ( V_19 ) ;
return 0 ;
}
}
F_31 ( 1 ) ;
return - V_79 ;
}
static void F_34 ( struct V_9 * V_10 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * V_70 = V_10 -> V_20 ;
F_31 ( V_70 == NULL ) ;
if ( V_70 && -- V_70 -> V_75 == 0 )
F_33 ( V_10 , V_70 ) ;
if ( -- V_64 -> V_75 == 0 ) {
struct V_18 * V_19 ;
V_10 -> V_71 -> V_72 = NULL ;
for ( V_19 = V_64 -> V_66 ; V_19 ; V_19 = V_19 -> V_36 ) {
V_19 -> V_75 -- ;
F_32 ( V_10 , V_19 ) ;
}
while ( ( V_19 = V_64 -> V_66 ) != NULL ) {
V_64 -> V_66 = V_19 -> V_36 ;
F_31 ( V_19 -> V_75 != 0 ) ;
F_24 ( V_19 ) ;
}
F_24 ( V_64 ) ;
}
V_10 -> V_41 = NULL ;
}
static int F_35 ( struct V_9 * V_10 , unsigned long V_80 )
{
struct V_18 * V_19 = (struct V_18 * ) V_80 ;
if ( V_19 == NULL )
return 0 ;
if ( F_19 ( V_19 -> V_65 ) )
return F_28 ( V_10 , (struct V_13 * ) V_19 ) ;
if ( V_10 -> V_20 == V_19 )
return - V_81 ;
if ( V_19 -> V_75 == 1 ) {
V_19 -> V_75 -- ;
F_33 ( V_10 , V_19 ) ;
} else {
return - V_82 ;
}
return 0 ;
}
static T_4 F_36 ( struct V_18 * V_19 , T_4 V_65 )
{
struct V_13 * V_21 ;
unsigned long V_25 ;
unsigned long * V_83 = F_23 ( F_37 ( V_84 ) * sizeof( unsigned long ) ,
V_73 ) ;
if ( ! V_83 )
return V_65 | 0xFFF ;
for ( V_21 = V_19 -> V_19 [ F_16 ( V_65 ) ] ; V_21 ; V_21 = V_21 -> V_36 )
F_38 ( F_39 ( V_21 -> V_65 ) , V_83 ) ;
V_25 = F_40 ( V_83 , V_84 , 0x800 ) ;
if ( V_25 >= V_84 )
V_25 = F_40 ( V_83 , V_84 , 1 ) ;
F_24 ( V_83 ) ;
return V_65 | ( V_25 >= V_84 ? 0xFFF : V_25 ) ;
}
static int F_41 ( struct V_85 * V_85 , struct V_9 * V_10 ,
unsigned long V_86 , struct V_18 * V_19 ,
struct V_13 * V_21 , struct V_87 * * V_88 ,
struct V_87 * V_89 , bool V_90 )
{
int V_91 ;
struct V_92 V_93 ;
F_42 ( & V_93 , V_94 , V_95 ) ;
V_91 = F_43 ( V_85 , V_10 , V_88 , V_89 , & V_93 , V_90 ) ;
if ( V_91 < 0 )
return V_91 ;
V_91 = - V_81 ;
if ( V_88 [ V_96 ] ) {
T_4 V_65 = F_44 ( V_88 [ V_96 ] ) ;
struct V_18 * V_46 = NULL , * V_97 ;
if ( F_19 ( V_65 ) )
goto V_98;
if ( V_65 ) {
V_46 = F_14 ( V_19 -> V_64 , V_65 ) ;
if ( V_46 == NULL )
goto V_98;
V_46 -> V_75 ++ ;
}
F_29 ( V_10 ) ;
V_97 = V_21 -> V_46 ;
V_21 -> V_46 = V_46 ;
F_30 ( V_10 ) ;
if ( V_97 )
V_97 -> V_75 -- ;
}
if ( V_88 [ V_99 ] ) {
V_21 -> V_12 . V_100 = F_44 ( V_88 [ V_99 ] ) ;
F_45 ( V_10 , & V_21 -> V_12 , V_86 ) ;
}
#ifdef F_9
if ( V_88 [ V_101 ] ) {
int V_102 ;
V_102 = F_46 ( V_85 , V_88 [ V_101 ] ) ;
if ( V_102 < 0 )
goto V_98;
V_21 -> V_50 = V_102 ;
}
#endif
F_47 ( V_10 , & V_21 -> V_52 , & V_93 ) ;
return 0 ;
V_98:
F_27 ( V_10 , & V_93 ) ;
return V_91 ;
}
static int F_48 ( struct V_85 * V_85 , struct V_7 * V_103 ,
struct V_9 * V_10 , unsigned long V_86 , T_4 V_65 ,
struct V_87 * * V_104 ,
unsigned long * V_80 , bool V_90 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * V_19 ;
struct V_13 * V_21 ;
struct V_2 * V_105 ;
struct V_87 * V_106 = V_104 [ V_107 ] ;
struct V_87 * V_88 [ V_108 + 1 ] ;
T_4 V_109 ;
int V_91 ;
if ( V_106 == NULL )
return V_65 ? - V_81 : 0 ;
V_91 = F_49 ( V_88 , V_108 , V_106 , V_110 ) ;
if ( V_91 < 0 )
return V_91 ;
V_21 = (struct V_13 * ) * V_80 ;
if ( V_21 ) {
if ( F_19 ( V_21 -> V_65 ) == 0 )
return - V_81 ;
return F_41 ( V_85 , V_10 , V_86 , V_21 -> V_62 , V_21 , V_88 ,
V_104 [ V_111 ] , V_90 ) ;
}
if ( V_88 [ V_112 ] ) {
unsigned int V_54 = F_44 ( V_88 [ V_112 ] ) ;
if ( -- V_54 > 0x100 )
return - V_81 ;
if ( F_19 ( V_65 ) )
return - V_81 ;
if ( V_65 == 0 ) {
V_65 = F_21 ( V_10 -> V_41 ) ;
if ( V_65 == 0 )
return - V_113 ;
}
V_19 = F_23 ( sizeof( * V_19 ) + V_54 * sizeof( void * ) , V_73 ) ;
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
if ( V_88 [ V_114 ] ) {
V_109 = F_44 ( V_88 [ V_114 ] ) ;
if ( F_18 ( V_109 ) == V_67 ) {
V_19 = V_10 -> V_20 ;
V_109 = V_19 -> V_65 ;
} else {
V_19 = F_14 ( V_10 -> V_41 , F_18 ( V_109 ) ) ;
if ( V_19 == NULL )
return - V_81 ;
}
} else {
V_19 = V_10 -> V_20 ;
V_109 = V_19 -> V_65 ;
}
if ( V_19 -> V_54 < F_16 ( V_109 ) )
return - V_81 ;
if ( V_65 ) {
if ( F_18 ( V_65 ) && F_18 ( V_65 ^ V_109 ) )
return - V_81 ;
V_65 = V_109 | F_39 ( V_65 ) ;
} else
V_65 = F_36 ( V_19 , V_109 ) ;
if ( V_88 [ V_115 ] == NULL )
return - V_81 ;
V_105 = F_50 ( V_88 [ V_115 ] ) ;
V_21 = F_23 ( sizeof( * V_21 ) + V_105 -> V_38 * sizeof( struct V_29 ) , V_73 ) ;
if ( V_21 == NULL )
return - V_74 ;
#ifdef F_5
V_21 -> V_31 = F_23 ( sizeof( struct V_116 ) + V_105 -> V_38 * sizeof( V_117 ) , V_73 ) ;
if ( V_21 -> V_31 == NULL ) {
F_24 ( V_21 ) ;
return - V_74 ;
}
#endif
memcpy ( & V_21 -> V_3 , V_105 , sizeof( * V_105 ) + V_105 -> V_38 * sizeof( struct V_29 ) ) ;
V_21 -> V_62 = V_19 ;
V_21 -> V_65 = V_65 ;
V_21 -> V_4 = V_105 -> V_6 ? F_51 ( F_2 ( V_105 -> V_6 ) ) - 1 : 0 ;
F_42 ( & V_21 -> V_52 , V_94 , V_95 ) ;
#ifdef F_6
if ( V_88 [ V_118 ] ) {
struct V_119 * V_33 ;
V_33 = F_50 ( V_88 [ V_118 ] ) ;
memcpy ( & V_21 -> V_33 , V_33 , sizeof( struct V_119 ) ) ;
V_21 -> V_33 . V_37 = 0 ;
}
#endif
V_91 = F_41 ( V_85 , V_10 , V_86 , V_19 , V_21 , V_88 , V_104 [ V_111 ] , V_90 ) ;
if ( V_91 == 0 ) {
struct V_13 * * V_120 ;
for ( V_120 = & V_19 -> V_19 [ F_16 ( V_65 ) ] ; * V_120 ; V_120 = & ( * V_120 ) -> V_36 )
if ( F_39 ( V_65 ) < F_39 ( ( * V_120 ) -> V_65 ) )
break;
V_21 -> V_36 = * V_120 ;
F_29 ( V_10 ) ;
* V_120 = V_21 ;
F_30 ( V_10 ) ;
* V_80 = ( unsigned long ) V_21 ;
return 0 ;
}
#ifdef F_5
F_24 ( V_21 -> V_31 ) ;
#endif
F_24 ( V_21 ) ;
return V_91 ;
}
static void F_52 ( struct V_9 * V_10 , struct V_121 * V_80 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * V_19 ;
struct V_13 * V_21 ;
unsigned int V_5 ;
if ( V_80 -> V_122 )
return;
for ( V_19 = V_64 -> V_66 ; V_19 ; V_19 = V_19 -> V_36 ) {
if ( V_19 -> V_76 != V_10 -> V_76 )
continue;
if ( V_80 -> V_123 >= V_80 -> V_124 ) {
if ( V_80 -> V_125 ( V_10 , ( unsigned long ) V_19 , V_80 ) < 0 ) {
V_80 -> V_122 = 1 ;
return;
}
}
V_80 -> V_123 ++ ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ ) {
for ( V_21 = V_19 -> V_19 [ V_5 ] ; V_21 ; V_21 = V_21 -> V_36 ) {
if ( V_80 -> V_123 < V_80 -> V_124 ) {
V_80 -> V_123 ++ ;
continue;
}
if ( V_80 -> V_125 ( V_10 , ( unsigned long ) V_21 , V_80 ) < 0 ) {
V_80 -> V_122 = 1 ;
return;
}
V_80 -> V_123 ++ ;
}
}
}
}
static int F_53 ( struct V_85 * V_85 , struct V_9 * V_10 , unsigned long V_126 ,
struct V_7 * V_8 , struct V_127 * V_128 )
{
struct V_13 * V_21 = (struct V_13 * ) V_126 ;
struct V_87 * V_129 ;
if ( V_21 == NULL )
return V_8 -> V_61 ;
V_128 -> V_130 = V_21 -> V_65 ;
V_129 = F_54 ( V_8 , V_107 ) ;
if ( V_129 == NULL )
goto V_131;
if ( F_19 ( V_21 -> V_65 ) == 0 ) {
struct V_18 * V_19 = (struct V_18 * ) V_126 ;
T_4 V_54 = V_19 -> V_54 + 1 ;
if ( F_55 ( V_8 , V_112 , V_54 ) )
goto V_131;
} else {
if ( F_56 ( V_8 , V_115 ,
sizeof( V_21 -> V_3 ) + V_21 -> V_3 . V_38 * sizeof( struct V_29 ) ,
& V_21 -> V_3 ) )
goto V_131;
if ( V_21 -> V_62 ) {
T_4 V_109 = V_21 -> V_65 & 0xFFFFF000 ;
if ( F_55 ( V_8 , V_114 , V_109 ) )
goto V_131;
}
if ( V_21 -> V_12 . V_100 &&
F_55 ( V_8 , V_99 , V_21 -> V_12 . V_100 ) )
goto V_131;
if ( V_21 -> V_46 &&
F_55 ( V_8 , V_96 , V_21 -> V_46 -> V_65 ) )
goto V_131;
#ifdef F_6
if ( ( V_21 -> V_33 . V_35 || V_21 -> V_33 . V_34 ) &&
F_56 ( V_8 , V_118 , sizeof( V_21 -> V_33 ) , & V_21 -> V_33 ) )
goto V_131;
#endif
if ( F_57 ( V_8 , & V_21 -> V_52 ) < 0 )
goto V_131;
#ifdef F_9
if ( V_21 -> V_50 ) {
struct V_132 * V_133 ;
V_133 = F_58 ( V_85 , V_21 -> V_50 ) ;
if ( V_133 && F_59 ( V_8 , V_101 , V_133 -> V_134 ) )
goto V_131;
}
#endif
#ifdef F_5
if ( F_56 ( V_8 , V_135 ,
sizeof( struct V_116 ) + V_21 -> V_3 . V_38 * sizeof( V_117 ) ,
V_21 -> V_31 ) )
goto V_131;
#endif
}
F_60 ( V_8 , V_129 ) ;
if ( F_19 ( V_21 -> V_65 ) )
if ( F_61 ( V_8 , & V_21 -> V_52 ) < 0 )
goto V_131;
return V_8 -> V_61 ;
V_131:
F_62 ( V_8 , V_129 ) ;
return - 1 ;
}
static int T_5 F_63 ( void )
{
F_64 ( L_2 ) ;
#ifdef F_5
F_64 ( L_3 ) ;
#endif
#ifdef F_9
F_64 ( L_4 ) ;
#endif
#ifdef F_65
F_64 ( L_5 ) ;
#endif
return F_66 ( & V_136 ) ;
}
static void T_6 F_67 ( void )
{
F_68 ( & V_136 ) ;
}
