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
unsigned int V_25 = 0x7FF ;
for ( V_21 = V_19 -> V_19 [ F_16 ( V_65 ) ] ; V_21 ; V_21 = V_21 -> V_36 )
if ( V_25 < F_37 ( V_21 -> V_65 ) )
V_25 = F_37 ( V_21 -> V_65 ) ;
V_25 ++ ;
return V_65 | ( V_25 > 0xFFF ? 0xFFF : V_25 ) ;
}
static int F_38 ( struct V_83 * V_83 , struct V_9 * V_10 ,
unsigned long V_84 , struct V_18 * V_19 ,
struct V_13 * V_21 , struct V_85 * * V_86 ,
struct V_85 * V_87 )
{
int V_88 ;
struct V_89 V_90 ;
F_39 ( & V_90 , V_91 , V_92 ) ;
V_88 = F_40 ( V_83 , V_10 , V_86 , V_87 , & V_90 ) ;
if ( V_88 < 0 )
return V_88 ;
V_88 = - V_81 ;
if ( V_86 [ V_93 ] ) {
T_4 V_65 = F_41 ( V_86 [ V_93 ] ) ;
struct V_18 * V_46 = NULL , * V_94 ;
if ( F_19 ( V_65 ) )
goto V_95;
if ( V_65 ) {
V_46 = F_14 ( V_19 -> V_64 , V_65 ) ;
if ( V_46 == NULL )
goto V_95;
V_46 -> V_75 ++ ;
}
F_29 ( V_10 ) ;
V_94 = V_21 -> V_46 ;
V_21 -> V_46 = V_46 ;
F_30 ( V_10 ) ;
if ( V_94 )
V_94 -> V_75 -- ;
}
if ( V_86 [ V_96 ] ) {
V_21 -> V_12 . V_97 = F_41 ( V_86 [ V_96 ] ) ;
F_42 ( V_10 , & V_21 -> V_12 , V_84 ) ;
}
#ifdef F_9
if ( V_86 [ V_98 ] ) {
int V_99 ;
V_99 = F_43 ( V_83 , V_86 [ V_98 ] ) ;
if ( V_99 < 0 )
goto V_95;
V_21 -> V_50 = V_99 ;
}
#endif
F_44 ( V_10 , & V_21 -> V_52 , & V_90 ) ;
return 0 ;
V_95:
F_27 ( V_10 , & V_90 ) ;
return V_88 ;
}
static int F_45 ( struct V_83 * V_83 , struct V_7 * V_100 ,
struct V_9 * V_10 , unsigned long V_84 , T_4 V_65 ,
struct V_85 * * V_101 ,
unsigned long * V_80 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * V_19 ;
struct V_13 * V_21 ;
struct V_2 * V_102 ;
struct V_85 * V_103 = V_101 [ V_104 ] ;
struct V_85 * V_86 [ V_105 + 1 ] ;
T_4 V_106 ;
int V_88 ;
if ( V_103 == NULL )
return V_65 ? - V_81 : 0 ;
V_88 = F_46 ( V_86 , V_105 , V_103 , V_107 ) ;
if ( V_88 < 0 )
return V_88 ;
V_21 = (struct V_13 * ) * V_80 ;
if ( V_21 ) {
if ( F_19 ( V_21 -> V_65 ) == 0 )
return - V_81 ;
return F_38 ( V_83 , V_10 , V_84 , V_21 -> V_62 , V_21 , V_86 ,
V_101 [ V_108 ] ) ;
}
if ( V_86 [ V_109 ] ) {
unsigned int V_54 = F_41 ( V_86 [ V_109 ] ) ;
if ( -- V_54 > 0x100 )
return - V_81 ;
if ( F_19 ( V_65 ) )
return - V_81 ;
if ( V_65 == 0 ) {
V_65 = F_21 ( V_10 -> V_41 ) ;
if ( V_65 == 0 )
return - V_110 ;
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
if ( V_86 [ V_111 ] ) {
V_106 = F_41 ( V_86 [ V_111 ] ) ;
if ( F_18 ( V_106 ) == V_67 ) {
V_19 = V_10 -> V_20 ;
V_106 = V_19 -> V_65 ;
} else {
V_19 = F_14 ( V_10 -> V_41 , F_18 ( V_106 ) ) ;
if ( V_19 == NULL )
return - V_81 ;
}
} else {
V_19 = V_10 -> V_20 ;
V_106 = V_19 -> V_65 ;
}
if ( V_19 -> V_54 < F_16 ( V_106 ) )
return - V_81 ;
if ( V_65 ) {
if ( F_18 ( V_65 ) && F_18 ( V_65 ^ V_106 ) )
return - V_81 ;
V_65 = V_106 | F_37 ( V_65 ) ;
} else
V_65 = F_36 ( V_19 , V_106 ) ;
if ( V_86 [ V_112 ] == NULL )
return - V_81 ;
V_102 = F_47 ( V_86 [ V_112 ] ) ;
V_21 = F_23 ( sizeof( * V_21 ) + V_102 -> V_38 * sizeof( struct V_29 ) , V_73 ) ;
if ( V_21 == NULL )
return - V_74 ;
#ifdef F_5
V_21 -> V_31 = F_23 ( sizeof( struct V_113 ) + V_102 -> V_38 * sizeof( V_114 ) , V_73 ) ;
if ( V_21 -> V_31 == NULL ) {
F_24 ( V_21 ) ;
return - V_74 ;
}
#endif
memcpy ( & V_21 -> V_3 , V_102 , sizeof( * V_102 ) + V_102 -> V_38 * sizeof( struct V_29 ) ) ;
V_21 -> V_62 = V_19 ;
V_21 -> V_65 = V_65 ;
V_21 -> V_4 = V_102 -> V_6 ? F_48 ( F_2 ( V_102 -> V_6 ) ) - 1 : 0 ;
F_39 ( & V_21 -> V_52 , V_91 , V_92 ) ;
#ifdef F_6
if ( V_86 [ V_115 ] ) {
struct V_116 * V_33 ;
V_33 = F_47 ( V_86 [ V_115 ] ) ;
memcpy ( & V_21 -> V_33 , V_33 , sizeof( struct V_116 ) ) ;
V_21 -> V_33 . V_37 = 0 ;
}
#endif
V_88 = F_38 ( V_83 , V_10 , V_84 , V_19 , V_21 , V_86 , V_101 [ V_108 ] ) ;
if ( V_88 == 0 ) {
struct V_13 * * V_117 ;
for ( V_117 = & V_19 -> V_19 [ F_16 ( V_65 ) ] ; * V_117 ; V_117 = & ( * V_117 ) -> V_36 )
if ( F_37 ( V_65 ) < F_37 ( ( * V_117 ) -> V_65 ) )
break;
V_21 -> V_36 = * V_117 ;
F_29 ( V_10 ) ;
* V_117 = V_21 ;
F_30 ( V_10 ) ;
* V_80 = ( unsigned long ) V_21 ;
return 0 ;
}
#ifdef F_5
F_24 ( V_21 -> V_31 ) ;
#endif
F_24 ( V_21 ) ;
return V_88 ;
}
static void F_49 ( struct V_9 * V_10 , struct V_118 * V_80 )
{
struct V_63 * V_64 = V_10 -> V_41 ;
struct V_18 * V_19 ;
struct V_13 * V_21 ;
unsigned int V_5 ;
if ( V_80 -> V_119 )
return;
for ( V_19 = V_64 -> V_66 ; V_19 ; V_19 = V_19 -> V_36 ) {
if ( V_19 -> V_76 != V_10 -> V_76 )
continue;
if ( V_80 -> V_120 >= V_80 -> V_121 ) {
if ( V_80 -> V_122 ( V_10 , ( unsigned long ) V_19 , V_80 ) < 0 ) {
V_80 -> V_119 = 1 ;
return;
}
}
V_80 -> V_120 ++ ;
for ( V_5 = 0 ; V_5 <= V_19 -> V_54 ; V_5 ++ ) {
for ( V_21 = V_19 -> V_19 [ V_5 ] ; V_21 ; V_21 = V_21 -> V_36 ) {
if ( V_80 -> V_120 < V_80 -> V_121 ) {
V_80 -> V_120 ++ ;
continue;
}
if ( V_80 -> V_122 ( V_10 , ( unsigned long ) V_21 , V_80 ) < 0 ) {
V_80 -> V_119 = 1 ;
return;
}
V_80 -> V_120 ++ ;
}
}
}
}
static int F_50 ( struct V_83 * V_83 , struct V_9 * V_10 , unsigned long V_123 ,
struct V_7 * V_8 , struct V_124 * V_125 )
{
struct V_13 * V_21 = (struct V_13 * ) V_123 ;
struct V_85 * V_126 ;
if ( V_21 == NULL )
return V_8 -> V_61 ;
V_125 -> V_127 = V_21 -> V_65 ;
V_126 = F_51 ( V_8 , V_104 ) ;
if ( V_126 == NULL )
goto V_128;
if ( F_19 ( V_21 -> V_65 ) == 0 ) {
struct V_18 * V_19 = (struct V_18 * ) V_123 ;
T_4 V_54 = V_19 -> V_54 + 1 ;
if ( F_52 ( V_8 , V_109 , V_54 ) )
goto V_128;
} else {
if ( F_53 ( V_8 , V_112 ,
sizeof( V_21 -> V_3 ) + V_21 -> V_3 . V_38 * sizeof( struct V_29 ) ,
& V_21 -> V_3 ) )
goto V_128;
if ( V_21 -> V_62 ) {
T_4 V_106 = V_21 -> V_65 & 0xFFFFF000 ;
if ( F_52 ( V_8 , V_111 , V_106 ) )
goto V_128;
}
if ( V_21 -> V_12 . V_97 &&
F_52 ( V_8 , V_96 , V_21 -> V_12 . V_97 ) )
goto V_128;
if ( V_21 -> V_46 &&
F_52 ( V_8 , V_93 , V_21 -> V_46 -> V_65 ) )
goto V_128;
#ifdef F_6
if ( ( V_21 -> V_33 . V_35 || V_21 -> V_33 . V_34 ) &&
F_53 ( V_8 , V_115 , sizeof( V_21 -> V_33 ) , & V_21 -> V_33 ) )
goto V_128;
#endif
if ( F_54 ( V_8 , & V_21 -> V_52 ) < 0 )
goto V_128;
#ifdef F_9
if ( V_21 -> V_50 ) {
struct V_129 * V_130 ;
V_130 = F_55 ( V_83 , V_21 -> V_50 ) ;
if ( V_130 && F_56 ( V_8 , V_98 , V_130 -> V_131 ) )
goto V_128;
}
#endif
#ifdef F_5
if ( F_53 ( V_8 , V_132 ,
sizeof( struct V_113 ) + V_21 -> V_3 . V_38 * sizeof( V_114 ) ,
V_21 -> V_31 ) )
goto V_128;
#endif
}
F_57 ( V_8 , V_126 ) ;
if ( F_19 ( V_21 -> V_65 ) )
if ( F_58 ( V_8 , & V_21 -> V_52 ) < 0 )
goto V_128;
return V_8 -> V_61 ;
V_128:
F_59 ( V_8 , V_126 ) ;
return - 1 ;
}
static int T_5 F_60 ( void )
{
F_61 ( L_2 ) ;
#ifdef F_5
F_61 ( L_3 ) ;
#endif
#ifdef F_9
F_61 ( L_4 ) ;
#endif
#ifdef F_62
F_61 ( L_5 ) ;
#endif
return F_63 ( & V_133 ) ;
}
static void T_6 F_64 ( void )
{
F_65 ( & V_133 ) ;
}
