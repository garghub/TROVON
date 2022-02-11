static T_1 F_1 ( void )
{
T_1 V_1 ;
unsigned int V_2 ;
if ( ! F_2 ( V_3 ) )
return 0 ;
V_2 = F_3 ( 0x80000000 ) ;
if ( V_2 < V_4 )
return V_5 ;
V_1 = F_3 ( V_4 ) ;
if ( ! ( V_1 & V_6 ) )
return V_5 ;
return V_1 ;
}
static unsigned int F_4 ( void )
{
static unsigned int V_7 = 0xF00D ;
unsigned int V_8 ;
V_8 = ( ( V_7 >> 0 ) ^
( V_7 >> 2 ) ^
( V_7 >> 3 ) ^
( V_7 >> 5 ) ) & 0x0001 ;
V_7 = ( V_7 >> 1 ) | ( V_8 << 15 ) ;
return V_7 ;
}
static inline T_2 F_5 ( T_2 V_9 )
{
unsigned int V_10 = F_4 () ;
if ( ! ( V_1 & V_11 ) )
V_9 += ( V_12 ) ( V_10 >> 4 ) ;
else
V_9 |= ( T_2 ) ( V_10 & V_13 ) << 32 ;
return V_9 ;
}
static inline void
F_6 ( struct V_14 * const V_15 ,
struct V_16 const * const V_17 )
{
T_2 V_9 , V_18 ;
struct V_19 V_20 ;
if ( ! V_1 )
return;
if ( V_21 . V_22 ) {
F_7 ( V_23 , V_18 ) ;
if ( V_18 & V_24 ) {
F_7 ( V_25 , V_9 ) ;
F_8 ( & V_20 , V_15 , V_9 ,
V_26 , V_27 ) ;
F_9 ( & V_20 , V_9 ) ;
F_9 ( & V_20 , V_18 ) ;
F_7 ( V_28 , V_9 ) ;
F_9 ( & V_20 , V_9 ) ;
F_10 ( & V_20 ) ;
V_18 &= ~ ( V_24 | V_29 ) ;
V_18 |= V_30 ;
F_11 ( V_23 , V_18 ) ;
}
}
if ( V_21 . V_31 ) {
F_7 ( V_32 , V_18 ) ;
if ( V_18 & V_33 ) {
F_7 ( V_34 , V_9 ) ;
F_8 ( & V_20 , V_15 , V_9 , V_35 ,
V_36 . V_37 ) ;
F_9 ( & V_20 , V_9 ) ;
F_7 ( V_38 , V_9 ) ;
F_9 ( & V_20 , V_9 ) ;
F_7 ( V_39 , V_9 ) ;
F_9 ( & V_20 , V_9 ) ;
F_7 ( V_40 , V_9 ) ;
F_9 ( & V_20 , V_9 ) ;
F_7 ( V_41 , V_9 ) ;
F_9 ( & V_20 , V_9 ) ;
F_7 ( V_42 , V_9 ) ;
F_9 ( & V_20 , V_9 ) ;
if ( V_36 . V_43 ) {
F_7 ( V_44 , V_9 ) ;
F_12 ( & V_20 , ( unsigned long ) V_9 ) ;
}
F_10 ( & V_20 ) ;
V_18 = F_5 ( V_36 . V_45 ) ;
F_11 ( V_32 , V_18 ) ;
}
}
}
static inline void F_13 ( void )
{
T_2 V_9 ;
if ( ! V_1 )
return;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
if ( V_21 . V_22 ) {
V_9 = V_21 . V_46 >> 4 ;
V_9 = F_14 ( V_9 , V_47 ) ;
V_21 . V_46 = V_9 << 4 ;
V_9 |= V_21 . V_48 ? V_49 : 0 ;
V_9 |= V_30 ;
F_11 ( V_23 , V_9 ) ;
}
if ( V_21 . V_31 ) {
V_9 = V_21 . V_50 >> 4 ;
if ( ! ( V_1 & V_11 ) ) {
V_9 = F_15 ( V_9 , 0x0081ULL , 0xFF80ULL ) ;
V_21 . V_50 = V_9 << 4 ;
} else {
V_9 += V_51 ;
if ( V_1 & V_52 )
V_9 = F_14 ( V_9 , V_53 ) ;
else
V_9 = F_14 ( V_9 , V_54 ) ;
V_21 . V_50 =
( V_9 - V_51 ) << 4 ;
}
V_9 = ( ( V_9 & ~ V_54 ) << 4 ) | ( V_9 & V_54 ) ;
V_9 |= V_21 . V_55 ? V_56 : 0 ;
V_9 |= V_57 ;
V_36 . V_45 = V_9 ;
V_36 . V_37 = V_58 ;
if ( V_21 . V_43 ) {
V_36 . V_43 = 1 ;
V_36 . V_37 ++ ;
}
V_9 = F_5 ( V_36 . V_45 ) ;
F_11 ( V_32 , V_9 ) ;
}
}
static void F_16 ( void )
{
if ( ! V_1 )
return;
if ( V_21 . V_22 )
F_11 ( V_23 , 0 ) ;
if ( V_21 . V_31 )
F_11 ( V_32 , 0 ) ;
}
static inline int F_17 ( int V_59 )
{
return ! F_18 ( V_59 , 0 , V_60 , 1 ) ;
}
static inline int F_19 ( int V_59 )
{
return ! F_18 ( V_59 , 0 , 0 , 1 ) ;
}
static inline int F_20 ( void )
{
int V_59 ;
T_2 V_9 ;
int V_61 = 0 ;
F_21 () ;
F_7 ( V_62 , V_9 ) ;
V_59 = V_9 & V_63 ;
if ( ! ( V_9 & V_64 ) ) {
F_22 ( V_65 L_1 ,
F_23 () , V_59 , V_62 , V_9 ) ;
goto V_66;
}
if ( ! F_17 ( V_59 ) ) {
F_22 ( V_65 L_2 ,
F_23 () , V_59 , V_62 , V_9 ) ;
goto V_66;
}
V_61 = 1 ;
V_66:
F_24 () ;
return V_61 ;
}
static inline int F_25 ( void )
{
T_2 V_9 ;
F_7 ( V_62 , V_9 ) ;
if ( ! ( V_9 & V_64 ) )
return - V_67 ;
return V_9 & V_63 ;
}
static void F_26 ( void )
{
int V_59 ;
V_59 = F_25 () ;
if ( V_59 < 0 )
goto V_68;
if ( ! F_18 ( V_59 , 0 , V_60 , 0 ) )
return;
V_68:
F_27 ( L_3 ,
F_23 () ) ;
}
static void F_28 ( void )
{
int V_59 ;
V_59 = F_25 () ;
if ( V_59 >= 0 )
F_18 ( V_59 , 0 , V_69 , 1 ) ;
}
static void F_29 ( struct V_70 const * V_71 ,
struct V_16 const * const V_17 )
{
T_2 V_9 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_73 ; ++ V_72 ) {
int V_74 = F_30 ( V_72 ) ;
if ( ! V_75 [ V_74 ] )
continue;
F_7 ( V_17 -> V_76 [ V_72 ] . V_77 , V_9 ) ;
V_9 &= V_71 -> V_78 ;
V_9 |= F_31 ( V_71 , & V_79 [ V_74 ] ) ;
F_11 ( V_17 -> V_76 [ V_72 ] . V_77 , V_9 ) ;
}
}
static void F_32 ( struct V_16 const * const V_17 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_73 ; ++ V_72 ) {
if ( ! V_17 -> V_80 [ V_72 ] . V_77 )
continue;
F_33 ( V_81 + V_72 ) ;
F_34 ( V_82 + V_72 ) ;
}
}
static int F_35 ( struct V_16 * const V_17 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ ) {
if ( ! F_36 ( V_81 + V_72 ) )
goto V_83;
if ( ! F_37 ( V_82 + V_72 ) ) {
F_33 ( V_81 + V_72 ) ;
goto V_83;
}
if ( V_73 == V_84 ) {
V_17 -> V_80 [ V_72 ] . V_77 = V_85 + ( V_72 << 1 ) ;
V_17 -> V_76 [ V_72 ] . V_77 = V_86 + ( V_72 << 1 ) ;
} else {
V_17 -> V_76 [ V_72 ] . V_77 = V_82 + V_72 ;
V_17 -> V_80 [ V_72 ] . V_77 = V_81 + V_72 ;
}
continue;
V_83:
if ( ! V_79 [ V_72 ] . V_87 )
continue;
F_38 ( V_72 ) ;
F_32 ( V_17 ) ;
return - V_88 ;
}
return 0 ;
}
static void F_39 ( struct V_70 const * V_71 ,
struct V_16 const * const V_17 )
{
T_2 V_9 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_89 ; ++ V_72 ) {
if ( V_79 [ V_72 ] . V_87
&& V_17 -> V_80 [ F_40 ( V_72 ) ] . V_77 )
V_75 [ V_72 ] = V_79 [ V_72 ] . V_90 ;
else
V_75 [ V_72 ] = 0 ;
}
for ( V_72 = 0 ; V_72 < V_73 ; ++ V_72 ) {
if ( ! V_17 -> V_76 [ V_72 ] . V_77 )
continue;
F_7 ( V_17 -> V_76 [ V_72 ] . V_77 , V_9 ) ;
if ( V_9 & V_91 )
F_41 ( V_72 ) ;
V_9 &= V_71 -> V_78 ;
F_11 ( V_17 -> V_76 [ V_72 ] . V_77 , V_9 ) ;
F_11 ( V_17 -> V_80 [ V_72 ] . V_77 , - 1LL ) ;
}
for ( V_72 = 0 ; V_72 < V_73 ; ++ V_72 ) {
int V_74 = F_30 ( V_72 ) ;
if ( ! V_75 [ V_74 ] )
continue;
F_11 ( V_17 -> V_80 [ V_72 ] . V_77 , - ( T_2 ) V_75 [ V_74 ] ) ;
F_7 ( V_17 -> V_76 [ V_72 ] . V_77 , V_9 ) ;
V_9 &= V_71 -> V_78 ;
V_9 |= F_31 ( V_71 , & V_79 [ V_74 ] ) ;
F_11 ( V_17 -> V_76 [ V_72 ] . V_77 , V_9 ) ;
}
if ( V_1 )
F_26 () ;
}
static void F_42 ( void )
{
if ( V_1 )
F_28 () ;
}
static int F_43 ( struct V_14 * const V_15 ,
struct V_16 const * const V_17 )
{
T_2 V_9 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_73 ; ++ V_72 ) {
int V_74 = F_30 ( V_72 ) ;
if ( ! V_75 [ V_74 ] )
continue;
F_7 ( V_17 -> V_80 [ V_72 ] . V_77 , V_9 ) ;
if ( V_9 & V_92 )
continue;
F_44 ( V_15 , V_74 ) ;
F_11 ( V_17 -> V_80 [ V_72 ] . V_77 , - ( T_2 ) V_75 [ V_74 ] ) ;
}
F_6 ( V_15 , V_17 ) ;
return 1 ;
}
static void F_45 ( struct V_16 const * const V_17 )
{
T_2 V_9 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_73 ; ++ V_72 ) {
if ( ! V_75 [ F_30 ( V_72 ) ] )
continue;
F_7 ( V_17 -> V_76 [ V_72 ] . V_77 , V_9 ) ;
V_9 |= V_91 ;
F_11 ( V_17 -> V_76 [ V_72 ] . V_77 , V_9 ) ;
}
F_13 () ;
}
static void F_46 ( struct V_16 const * const V_17 )
{
T_2 V_9 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_73 ; ++ V_72 ) {
if ( ! V_75 [ F_30 ( V_72 ) ] )
continue;
F_7 ( V_17 -> V_76 [ V_72 ] . V_77 , V_9 ) ;
V_9 &= ~ V_91 ;
F_11 ( V_17 -> V_76 [ V_72 ] . V_77 , V_9 ) ;
}
F_16 () ;
}
static int F_47 ( int V_93 )
{
struct V_94 * V_95 ;
int V_96 ;
T_1 V_97 = 0 ;
V_96 = 0 ;
V_95 = NULL ;
do {
V_95 = F_48 ( V_98 ,
V_99 ,
V_95 ) ;
if ( ! V_95 )
break;
++ V_96 ;
F_49 ( V_95 , V_100 , V_93
| V_64 ) ;
F_50 ( V_95 , V_100 , & V_97 ) ;
if ( V_97 != ( V_93 | V_64 ) ) {
F_51 ( V_95 ) ;
F_52 ( V_101 L_4
L_5 , V_97 ) ;
return - V_67 ;
}
} while ( 1 );
if ( ! V_96 ) {
F_52 ( V_101 L_6 ) ;
return - V_102 ;
}
return 0 ;
}
static int F_53 ( void )
{
int V_59 ;
int V_103 ;
F_21 () ;
for ( V_59 = 1 ; V_59 < V_104 ; V_59 ++ ) {
if ( F_17 ( V_59 ) )
break;
}
F_24 () ;
if ( V_59 == V_104 ) {
F_52 ( V_101 L_7 ) ;
return - V_88 ;
}
V_103 = F_47 ( V_59 ) ;
if ( V_103 )
goto V_66;
if ( ! F_20 () ) {
V_103 = - V_105 ;
goto V_66;
}
F_22 ( V_65 L_8 , V_59 ) ;
F_22 ( V_65 L_9 ) ;
return 0 ;
V_66:
F_21 () ;
F_19 ( V_59 ) ;
F_24 () ;
return V_103 ;
}
static void F_54 ( void )
{
V_1 = F_1 () ;
if ( ! V_1 )
return;
if ( F_20 () )
goto V_66;
if ( ! F_53 () )
goto V_66;
V_1 = 0 ;
return;
V_66:
F_52 ( V_106 L_10 , V_1 ) ;
}
static int F_55 ( struct V_107 * V_108 , struct V_109 * V_110 )
{
struct V_109 * V_111 ;
int V_103 = 0 ;
if ( V_112 )
V_103 = V_112 ( V_108 , V_110 ) ;
if ( V_103 )
return V_103 ;
if ( ! V_1 )
return V_103 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_46 = 250000 ;
V_21 . V_50 = 250000 ;
if ( V_1 & V_113 ) {
V_111 = F_56 ( V_108 , V_110 , L_11 ) ;
F_57 ( V_108 , V_111 , L_12 ,
& V_21 . V_22 ) ;
F_57 ( V_108 , V_111 , L_13 ,
& V_21 . V_46 ) ;
F_57 ( V_108 , V_111 , L_14 ,
& V_21 . V_48 ) ;
}
if ( V_1 & V_114 ) {
V_111 = F_56 ( V_108 , V_110 , L_15 ) ;
F_57 ( V_108 , V_111 , L_12 ,
& V_21 . V_31 ) ;
F_57 ( V_108 , V_111 , L_13 ,
& V_21 . V_50 ) ;
if ( V_1 & V_115 )
F_57 ( V_108 , V_111 , L_16 ,
& V_21 . V_55 ) ;
if ( V_1 & V_116 )
F_57 ( V_108 , V_111 , L_17 ,
& V_21 . V_43 ) ;
}
return 0 ;
}
static int F_58 ( struct V_117 * V_118 )
{
F_54 () ;
V_112 = V_118 -> V_119 ;
V_118 -> V_119 = F_55 ;
if ( V_120 . V_121 == 0x15 ) {
V_73 = V_84 ;
} else {
V_73 = V_122 ;
}
V_123 . V_73 = V_73 ;
V_123 . V_124 = V_73 ;
V_123 . V_125 = F_59 ( V_73 , V_126 ) ;
return 0 ;
}
