static inline bool F_1 ( T_1 V_1 )
{
if ( V_1 <= V_2 )
return true ;
return false ;
}
static void F_2 ( struct V_3 * V_4 )
{
T_1 V_5 = F_3 ( V_4 ) ;
if ( ! F_1 ( V_5 ) )
F_4 ( V_5 , V_6 +
V_7 ) ;
else
F_4 ( V_5 , V_8 +
V_9 ) ;
}
static void F_5 ( struct V_3 * V_4 )
{
T_1 V_5 = F_3 ( V_4 ) ;
if ( ! F_1 ( V_5 ) )
F_4 ( V_5 , V_6 +
V_10 ) ;
else
F_4 ( V_5 , V_8 +
V_11 ) ;
}
static int F_6 ( void )
{
int V_5 ;
F_7 ( & V_12 ) ;
V_5 = F_8 ( & V_13 , V_14 ) ;
if ( V_5 >= V_14 )
V_5 = - V_15 ;
else
F_9 ( V_5 , V_13 ) ;
F_10 ( & V_12 ) ;
return V_5 ;
}
static void F_11 ( int V_5 )
{
F_7 ( & V_12 ) ;
if ( ! F_12 ( V_5 , V_13 ) )
F_13 ( L_1 , V_5 ) ;
else
F_14 ( V_5 , V_13 ) ;
F_10 ( & V_12 ) ;
}
static int F_15 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 V_23 ;
int V_24 , V_5 ;
if ( V_21 -> V_25 . V_26 )
return - V_27 ;
V_5 = F_6 () ;
if ( V_5 < 0 )
return V_5 ;
V_24 = F_16 ( V_28 , V_5 ) ;
if ( ! V_24 ) {
F_11 ( V_5 ) ;
return - V_27 ;
}
F_17 ( V_24 , V_21 ) ;
V_23 . V_29 = V_30 ;
V_23 . V_31 = 0 ;
V_23 . V_32 = 0xf00 | ( V_5 + 16 ) ;
F_18 ( V_24 , & V_23 ) ;
return 0 ;
}
static void F_19 ( struct V_16 * V_17 ,
unsigned int V_1 )
{
struct V_3 * V_4 = F_20 ( V_1 ) ;
unsigned long V_5 = V_4 -> V_5 ;
F_21 ( V_1 ) ;
F_11 ( V_5 ) ;
}
static int F_22 ( struct V_33 * V_34 , unsigned int V_24 ,
T_1 V_35 )
{
F_23 ( V_24 , & V_36 ,
V_37 ) ;
return 0 ;
}
static int F_24 ( struct V_38 * V_39 ,
T_2 V_40 )
{
struct V_16 * V_41 ;
T_3 V_42 ;
int V_43 ;
V_30 = V_40 +
V_44 ;
V_41 = F_25 ( sizeof( * V_41 ) , V_45 ) ;
if ( ! V_41 )
return - V_46 ;
V_41 -> V_47 = F_15 ;
V_41 -> V_48 = F_19 ;
V_41 -> V_49 = V_39 ;
V_28 =
F_26 ( NULL , V_14 ,
& V_50 ,
NULL ) ;
if ( ! V_28 ) {
F_27 ( V_41 ) ;
return - V_46 ;
}
V_43 = F_28 ( V_41 ) ;
if ( V_43 < 0 ) {
F_29 ( V_28 ) ;
F_27 ( V_41 ) ;
return V_43 ;
}
V_42 = F_30 ( V_8 + V_51 )
| V_52 ;
F_4 ( V_42 , V_8 +
V_51 ) ;
F_4 ( 1 , V_8 + V_11 ) ;
return 0 ;
}
static inline int F_24 ( struct V_38 * V_39 ,
T_2 V_40 )
{
return 0 ;
}
static int F_31 ( struct V_3 * V_4 ,
const struct V_53 * V_54 , bool V_55 )
{
T_1 V_5 = F_3 ( V_4 ) ;
unsigned long V_42 , V_56 ;
int V_57 ;
V_57 = F_32 ( V_54 , V_58 ) ;
V_56 = 1UL << F_33 ( V_57 ) ;
F_34 ( & V_59 ) ;
V_42 = F_30 ( V_6 + F_35 ( V_5 ) ) ;
V_42 = ( V_42 & ( ~ V_60 ) ) | V_56 ;
F_4 ( V_42 , V_6 + F_35 ( V_5 ) ) ;
F_36 ( & V_59 ) ;
return V_61 ;
}
static int F_37 ( struct V_33 * V_62 ,
unsigned int V_24 , T_1 V_35 )
{
F_2 ( F_20 ( V_24 ) ) ;
if ( ! F_1 ( V_35 ) )
F_4 ( V_35 , V_8 +
V_11 ) ;
else
F_4 ( V_35 , V_6 + V_10 ) ;
F_38 ( V_24 , V_63 ) ;
if ( F_1 ( V_35 ) ) {
F_39 ( V_24 ) ;
F_23 ( V_24 , & V_64 ,
V_65 ) ;
} else {
F_23 ( V_24 , & V_64 ,
V_66 ) ;
}
F_40 ( V_24 ) ;
F_41 ( V_24 , V_67 ) ;
return 0 ;
}
static void F_42 ( void )
{
T_3 V_68 ;
int V_69 , V_70 ;
V_68 = F_30 ( V_6 + V_71 ) ;
V_69 = ( V_68 >> 2 ) & 0x3ff ;
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ )
F_4 ( V_70 , V_8 + V_9 ) ;
F_4 ( 0 , V_8 + V_72 ) ;
F_4 ( V_73 , V_8 +
V_51 ) ;
F_4 ( 0 , V_8 + V_11 ) ;
}
static void F_43 ( void )
{
unsigned long V_74 = F_33 ( F_44 () ) ;
F_4 ( F_45 ( V_74 ) ,
V_8 + V_75 ) ;
}
static void F_46 ( const struct V_53 * V_56 ,
unsigned int V_1 )
{
int V_57 ;
unsigned long V_76 = 0 ;
F_47 (cpu, mask)
V_76 |= 1 << F_33 ( V_57 ) ;
F_48 () ;
F_4 ( ( V_76 << 8 ) | V_1 , V_6 +
V_44 ) ;
}
static int F_49 ( struct V_77 * V_78 ,
unsigned long V_79 , void * V_80 )
{
if ( V_79 == V_81 || V_79 == V_82 ) {
F_43 () ;
F_42 () ;
}
return V_83 ;
}
static int F_50 ( struct V_77 * V_78 ,
unsigned long V_79 , void * V_80 )
{
if ( V_79 == V_81 || V_79 == V_82 ) {
F_43 () ;
F_51 ( V_84 , V_85 ) ;
}
return V_83 ;
}
static void F_52 ( struct V_86 * V_87 , bool V_88 )
{
T_3 V_89 , V_90 ;
V_89 = F_53 ( V_8 +
V_72 )
& V_52 ;
F_4 ( ~ V_89 , V_8 +
V_72 ) ;
for ( V_90 = V_91 ;
V_90 < V_92 ; V_90 ++ ) {
int V_1 ;
if ( ! ( V_89 & F_54 ( V_90 ) ) )
continue;
if ( V_88 ) {
V_1 = F_55 ( V_28 ,
V_90 - 16 ) ;
F_56 ( V_1 ) ;
} else {
V_1 = V_90 - 16 ;
F_57 ( V_28 ,
V_1 , V_87 ) ;
}
}
}
static void F_52 ( struct V_86 * V_93 , bool V_94 ) {}
static void F_58 ( struct V_95 * V_21 )
{
struct V_96 * V_17 = F_59 ( V_21 ) ;
unsigned long V_97 , V_98 , V_99 , V_74 ;
unsigned int V_100 ;
F_60 ( V_17 , V_21 ) ;
V_97 = F_53 ( V_8 + V_101 ) ;
V_74 = F_33 ( F_44 () ) ;
F_61 (irqn, &irqmap, BITS_PER_LONG) {
V_99 = F_53 ( V_6 +
F_35 ( V_98 ) ) ;
if ( ! ( V_99 & F_62 ( V_74 ) ) )
continue;
if ( V_98 == 1 ) {
F_52 ( NULL , true ) ;
continue;
}
V_100 = F_55 ( V_102 , V_98 ) ;
F_56 ( V_100 ) ;
}
F_63 ( V_17 , V_21 ) ;
}
static void T_4
F_64 ( struct V_86 * V_87 )
{
T_3 V_103 , V_104 ;
do {
V_103 = F_53 ( V_8 +
V_105 ) ;
V_104 = V_103 & 0x3FF ;
if ( V_104 > 1022 )
break;
if ( V_104 > 1 ) {
F_57 ( V_102 ,
V_104 , V_87 ) ;
continue;
}
if ( V_104 == 1 )
F_52 ( V_87 , false ) ;
#ifdef F_65
if ( V_104 == 0 ) {
T_3 V_106 , V_107 ;
V_106 = F_53 ( V_8 +
V_72 )
& V_73 ;
F_4 ( ~ V_106 , V_8 +
V_72 ) ;
for ( V_107 = V_108 ;
V_107 < V_109 ; V_107 ++ ) {
if ( V_106 & ( 0x1 << V_107 ) )
F_66 ( V_107 , V_87 ) ;
}
continue;
}
#endif
} while ( 1 );
}
static int F_67 ( void )
{
V_110 = F_30 ( V_8 +
V_51 ) ;
return 0 ;
}
static void F_68 ( void )
{
int V_111 ;
T_1 V_1 ;
V_111 = ( F_30 ( V_6 + V_71 ) >> 2 ) & 0x3ff ;
for ( V_1 = 0 ; V_1 < V_111 ; V_1 ++ ) {
struct V_3 * V_32 ;
int V_24 ;
V_24 = F_69 ( V_102 , V_1 ) ;
if ( V_24 == 0 )
continue;
if ( ! F_1 ( V_1 ) )
F_4 ( V_1 , V_8 +
V_11 ) ;
else
F_4 ( V_1 , V_6 +
V_10 ) ;
V_32 = F_20 ( V_24 ) ;
if ( ! F_70 ( V_32 ) )
F_5 ( V_32 ) ;
}
F_4 ( V_110 ,
V_8 + V_51 ) ;
if ( V_110 & V_73 )
F_4 ( 0 , V_8 + V_11 ) ;
if ( V_110 & V_52 )
F_4 ( 1 , V_8 + V_11 ) ;
}
static int T_5 F_71 ( struct V_38 * V_39 ,
struct V_38 * V_112 )
{
struct V_113 V_114 , V_115 ;
int V_69 , V_70 ;
T_3 V_68 ;
F_72 ( F_73 ( V_39 , 0 , & V_114 ) ) ;
F_72 ( F_73 ( V_39 , 1 , & V_115 ) ) ;
F_72 ( ! F_74 ( V_114 . V_116 ,
F_75 ( & V_114 ) ,
V_39 -> V_117 ) ) ;
F_72 ( ! F_74 ( V_115 . V_116 ,
F_75 ( & V_115 ) ,
V_39 -> V_117 ) ) ;
V_6 = F_76 ( V_114 . V_116 ,
F_75 ( & V_114 ) ) ;
F_72 ( ! V_6 ) ;
V_8 = F_76 ( V_115 . V_116 ,
F_75 ( & V_115 ) ) ;
F_72 ( ! V_8 ) ;
V_68 = F_30 ( V_6 + V_71 ) ;
V_69 = ( V_68 >> 2 ) & 0x3ff ;
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ )
F_4 ( V_70 , V_6 + V_7 ) ;
V_102 =
F_26 ( V_39 , V_69 ,
& V_118 , NULL ) ;
F_72 ( ! V_102 ) ;
F_43 () ;
F_42 () ;
F_24 ( V_39 , V_114 . V_116 ) ;
V_84 = F_77 ( V_39 , 0 ) ;
if ( V_84 <= 0 ) {
F_78 ( V_102 ) ;
F_79 ( F_64 ) ;
#ifdef F_65
F_80 ( F_46 ) ;
F_81 ( & V_119 ) ;
#endif
} else {
#ifdef F_65
F_81 ( & V_120 ) ;
#endif
F_82 ( V_84 ,
F_58 ) ;
}
F_83 ( & V_121 ) ;
return 0 ;
}
