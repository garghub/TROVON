static inline bool F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
return true ;
default:
return false ;
}
}
static void F_2 ( struct V_4 * V_5 )
{
T_1 V_6 = F_3 ( V_5 ) ;
if ( ! F_1 ( V_6 ) )
F_4 ( V_6 , V_7 +
V_8 ) ;
else
F_4 ( V_6 , V_9 +
V_10 ) ;
}
static void F_5 ( struct V_4 * V_5 )
{
T_1 V_6 = F_3 ( V_5 ) ;
if ( ! F_1 ( V_6 ) )
F_4 ( V_6 , V_7 +
V_11 ) ;
else
F_4 ( V_6 , V_9 +
V_12 ) ;
}
static int F_6 ( void )
{
int V_6 ;
F_7 ( & V_13 ) ;
V_6 = F_8 ( & V_14 , V_15 ) ;
if ( V_6 >= V_15 )
V_6 = - V_16 ;
else
F_9 ( V_6 , V_14 ) ;
F_10 ( & V_13 ) ;
return V_6 ;
}
static void F_11 ( int V_6 )
{
F_7 ( & V_13 ) ;
if ( ! F_12 ( V_6 , V_14 ) )
F_13 ( L_1 , V_6 ) ;
else
F_14 ( V_6 , V_14 ) ;
F_10 ( & V_13 ) ;
}
static int F_15 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 V_24 ;
int V_25 , V_6 ;
if ( V_22 -> V_26 . V_27 )
return - V_28 ;
V_6 = F_6 () ;
if ( V_6 < 0 )
return V_6 ;
V_25 = F_16 ( V_29 , V_6 ) ;
if ( ! V_25 ) {
F_11 ( V_6 ) ;
return - V_28 ;
}
F_17 ( V_25 , V_22 ) ;
V_24 . V_30 = V_31 ;
V_24 . V_32 = 0 ;
V_24 . V_33 = 0xf00 | ( V_6 + 16 ) ;
F_18 ( V_25 , & V_24 ) ;
return 0 ;
}
static void F_19 ( struct V_17 * V_18 ,
unsigned int V_1 )
{
struct V_4 * V_5 = F_20 ( V_1 ) ;
unsigned long V_6 = V_5 -> V_6 ;
F_21 ( V_1 ) ;
F_11 ( V_6 ) ;
}
static int F_22 ( struct V_34 * V_35 , unsigned int V_25 ,
T_1 V_36 )
{
F_23 ( V_25 , & V_37 ,
V_38 ) ;
F_24 ( V_25 , V_39 ) ;
return 0 ;
}
static int F_25 ( struct V_40 * V_41 ,
T_2 V_42 )
{
struct V_17 * V_43 ;
T_3 V_44 ;
int V_45 ;
V_31 = V_42 +
V_46 ;
V_43 = F_26 ( sizeof( * V_43 ) , V_47 ) ;
if ( ! V_43 )
return - V_48 ;
V_43 -> V_49 = F_15 ;
V_43 -> V_50 = F_19 ;
V_43 -> V_51 = V_41 ;
V_29 =
F_27 ( NULL , V_15 ,
& V_52 ,
NULL ) ;
if ( ! V_29 ) {
F_28 ( V_43 ) ;
return - V_48 ;
}
V_45 = F_29 ( V_43 ) ;
if ( V_45 < 0 ) {
F_30 ( V_29 ) ;
F_28 ( V_43 ) ;
return V_45 ;
}
V_44 = F_31 ( V_9 + V_53 )
| V_54 ;
F_4 ( V_44 , V_9 +
V_53 ) ;
F_4 ( 1 , V_9 + V_12 ) ;
return 0 ;
}
static inline int F_25 ( struct V_40 * V_41 ,
T_2 V_42 )
{
return 0 ;
}
static int F_32 ( struct V_4 * V_5 ,
const struct V_55 * V_56 , bool V_57 )
{
T_1 V_6 = F_3 ( V_5 ) ;
unsigned long V_44 , V_58 ;
int V_59 ;
V_59 = F_33 ( V_56 , V_60 ) ;
V_58 = 1UL << F_34 ( V_59 ) ;
F_35 ( & V_61 ) ;
V_44 = F_31 ( V_7 + F_36 ( V_6 ) ) ;
V_44 = ( V_44 & ( ~ V_62 ) ) | V_58 ;
F_4 ( V_44 , V_7 + F_36 ( V_6 ) ) ;
F_37 ( & V_61 ) ;
return V_63 ;
}
static int F_38 ( struct V_34 * V_64 ,
unsigned int V_25 , T_1 V_36 )
{
F_2 ( F_20 ( V_25 ) ) ;
if ( ! F_1 ( V_36 ) )
F_4 ( V_36 , V_9 +
V_12 ) ;
else
F_4 ( V_36 , V_7 + V_11 ) ;
F_39 ( V_25 , V_65 ) ;
if ( F_1 ( V_36 ) ) {
F_40 ( V_25 ) ;
F_23 ( V_25 , & V_66 ,
V_67 ) ;
} else {
F_23 ( V_25 , & V_66 ,
V_68 ) ;
}
F_24 ( V_25 , V_39 | V_69 ) ;
return 0 ;
}
static void F_41 ( void )
{
T_3 V_70 ;
int V_71 , V_72 ;
V_70 = F_31 ( V_7 + V_73 ) ;
V_71 = ( V_70 >> 2 ) & 0x3ff ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ )
F_4 ( V_72 , V_9 + V_10 ) ;
F_4 ( 0 , V_9 + V_74 ) ;
F_4 ( V_75 , V_9 +
V_53 ) ;
F_4 ( 0 , V_9 + V_12 ) ;
}
static void F_42 ( void )
{
unsigned long V_76 = F_34 ( F_43 () ) ;
F_4 ( F_44 ( V_76 ) ,
V_9 + V_77 ) ;
}
static void F_45 ( const struct V_55 * V_58 ,
unsigned int V_1 )
{
int V_59 ;
unsigned long V_78 = 0 ;
F_46 (cpu, mask)
V_78 |= 1 << F_34 ( V_59 ) ;
F_47 () ;
F_4 ( ( V_78 << 8 ) | V_1 , V_7 +
V_46 ) ;
}
static int F_48 ( struct V_79 * V_80 ,
unsigned long V_81 , void * V_82 )
{
if ( V_81 == V_83 || V_81 == V_84 ) {
F_42 () ;
F_41 () ;
}
return V_85 ;
}
static int F_49 ( struct V_79 * V_80 ,
unsigned long V_81 , void * V_82 )
{
if ( V_81 == V_83 || V_81 == V_84 ) {
F_42 () ;
F_50 ( V_86 , V_87 ) ;
}
return V_85 ;
}
static void F_51 ( struct V_88 * V_89 , bool V_90 )
{
T_3 V_91 , V_92 ;
V_91 = F_52 ( V_9 +
V_74 )
& V_54 ;
F_4 ( ~ V_91 , V_9 +
V_74 ) ;
for ( V_92 = V_93 ;
V_92 < V_94 ; V_92 ++ ) {
int V_1 ;
if ( ! ( V_91 & F_53 ( V_92 ) ) )
continue;
if ( V_90 ) {
V_1 = F_54 ( V_29 ,
V_92 - 16 ) ;
F_55 ( V_1 ) ;
} else {
V_1 = V_92 - 16 ;
F_56 ( V_29 ,
V_1 , V_89 ) ;
}
}
}
static void F_51 ( struct V_88 * V_95 , bool V_96 ) {}
static void F_57 ( unsigned int V_1 ,
struct V_97 * V_22 )
{
struct V_98 * V_18 = F_58 ( V_1 ) ;
unsigned long V_99 , V_100 , V_101 , V_76 ;
unsigned int V_102 ;
F_59 ( V_18 , V_22 ) ;
V_99 = F_52 ( V_9 + V_103 ) ;
V_76 = F_34 ( F_43 () ) ;
F_60 (irqn, &irqmap, BITS_PER_LONG) {
V_101 = F_52 ( V_7 +
F_36 ( V_100 ) ) ;
if ( ! ( V_101 & F_61 ( V_76 ) ) )
continue;
if ( V_100 == 1 ) {
F_51 ( NULL , true ) ;
continue;
}
V_102 = F_54 ( V_104 , V_100 ) ;
F_55 ( V_102 ) ;
}
F_62 ( V_18 , V_22 ) ;
}
static void T_4
F_63 ( struct V_88 * V_89 )
{
T_3 V_105 , V_106 ;
do {
V_105 = F_52 ( V_9 +
V_107 ) ;
V_106 = V_105 & 0x3FF ;
if ( V_106 > 1022 )
break;
if ( V_106 > 1 ) {
F_56 ( V_104 ,
V_106 , V_89 ) ;
continue;
}
if ( V_106 == 1 )
F_51 ( V_89 , false ) ;
#ifdef F_64
if ( V_106 == 0 ) {
T_3 V_108 , V_109 ;
V_108 = F_52 ( V_9 +
V_74 )
& V_75 ;
F_4 ( ~ V_108 , V_9 +
V_74 ) ;
for ( V_109 = V_110 ;
V_109 < V_111 ; V_109 ++ ) {
if ( V_108 & ( 0x1 << V_109 ) )
F_65 ( V_109 , V_89 ) ;
}
continue;
}
#endif
} while ( 1 );
}
static int F_66 ( void )
{
V_112 = F_31 ( V_9 +
V_53 ) ;
return 0 ;
}
static void F_67 ( void )
{
int V_113 ;
T_1 V_1 ;
V_113 = ( F_31 ( V_7 + V_73 ) >> 2 ) & 0x3ff ;
for ( V_1 = 0 ; V_1 < V_113 ; V_1 ++ ) {
struct V_4 * V_33 ;
int V_25 ;
V_25 = F_68 ( V_104 , V_1 ) ;
if ( V_25 == 0 )
continue;
if ( V_1 != V_2 )
F_4 ( V_1 , V_9 +
V_12 ) ;
else
F_4 ( V_1 , V_7 +
V_11 ) ;
V_33 = F_20 ( V_25 ) ;
if ( ! F_69 ( V_33 ) )
F_5 ( V_33 ) ;
}
F_4 ( V_112 ,
V_9 + V_53 ) ;
if ( V_112 & V_75 )
F_4 ( 0 , V_9 + V_12 ) ;
if ( V_112 & V_54 )
F_4 ( 1 , V_9 + V_12 ) ;
}
static int T_5 F_70 ( struct V_40 * V_41 ,
struct V_40 * V_114 )
{
struct V_115 V_116 , V_117 ;
int V_71 , V_72 ;
T_3 V_70 ;
F_71 ( F_72 ( V_41 , 0 , & V_116 ) ) ;
F_71 ( F_72 ( V_41 , 1 , & V_117 ) ) ;
F_71 ( ! F_73 ( V_116 . V_118 ,
F_74 ( & V_116 ) ,
V_41 -> V_119 ) ) ;
F_71 ( ! F_73 ( V_117 . V_118 ,
F_74 ( & V_117 ) ,
V_41 -> V_119 ) ) ;
V_7 = F_75 ( V_116 . V_118 ,
F_74 ( & V_116 ) ) ;
F_71 ( ! V_7 ) ;
V_9 = F_75 ( V_117 . V_118 ,
F_74 ( & V_117 ) ) ;
F_71 ( ! V_9 ) ;
V_70 = F_31 ( V_7 + V_73 ) ;
V_71 = ( V_70 >> 2 ) & 0x3ff ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ )
F_4 ( V_72 , V_7 + V_8 ) ;
V_104 =
F_27 ( V_41 , V_71 ,
& V_120 , NULL ) ;
F_71 ( ! V_104 ) ;
F_42 () ;
F_41 () ;
F_25 ( V_41 , V_116 . V_118 ) ;
V_86 = F_76 ( V_41 , 0 ) ;
if ( V_86 <= 0 ) {
F_77 ( V_104 ) ;
F_78 ( F_63 ) ;
#ifdef F_64
F_79 ( F_45 ) ;
F_80 ( & V_121 ) ;
#endif
} else {
#ifdef F_64
F_80 ( & V_122 ) ;
#endif
F_81 ( V_86 ,
F_57 ) ;
}
F_82 ( & V_123 ) ;
return 0 ;
}
