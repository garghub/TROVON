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
return 0 ;
}
static int F_24 ( struct V_39 * V_40 ,
T_2 V_41 )
{
struct V_17 * V_42 ;
T_3 V_43 ;
int V_44 ;
V_31 = V_41 +
V_45 ;
V_42 = F_25 ( sizeof( * V_42 ) , V_46 ) ;
if ( ! V_42 )
return - V_47 ;
V_42 -> V_48 = F_15 ;
V_42 -> V_49 = F_19 ;
V_42 -> V_50 = V_40 ;
V_29 =
F_26 ( NULL , V_15 ,
& V_51 ,
NULL ) ;
if ( ! V_29 ) {
F_27 ( V_42 ) ;
return - V_47 ;
}
V_44 = F_28 ( V_42 ) ;
if ( V_44 < 0 ) {
F_29 ( V_29 ) ;
F_27 ( V_42 ) ;
return V_44 ;
}
V_43 = F_30 ( V_9 + V_52 )
| V_53 ;
F_4 ( V_43 , V_9 +
V_52 ) ;
F_4 ( 1 , V_9 + V_12 ) ;
return 0 ;
}
static inline int F_24 ( struct V_39 * V_40 ,
T_2 V_41 )
{
return 0 ;
}
static int F_31 ( struct V_4 * V_5 ,
const struct V_54 * V_55 , bool V_56 )
{
T_1 V_6 = F_3 ( V_5 ) ;
unsigned long V_43 , V_57 ;
int V_58 ;
V_58 = F_32 ( V_55 , V_59 ) ;
V_57 = 1UL << F_33 ( V_58 ) ;
F_34 ( & V_60 ) ;
V_43 = F_30 ( V_7 + F_35 ( V_6 ) ) ;
V_43 = ( V_43 & ( ~ V_61 ) ) | V_57 ;
F_4 ( V_43 , V_7 + F_35 ( V_6 ) ) ;
F_36 ( & V_60 ) ;
return V_62 ;
}
static int F_37 ( struct V_34 * V_63 ,
unsigned int V_25 , T_1 V_36 )
{
F_2 ( F_20 ( V_25 ) ) ;
if ( ! F_1 ( V_36 ) )
F_4 ( V_36 , V_9 +
V_12 ) ;
else
F_4 ( V_36 , V_7 + V_11 ) ;
F_38 ( V_25 , V_64 ) ;
if ( F_1 ( V_36 ) ) {
F_39 ( V_25 ) ;
F_23 ( V_25 , & V_65 ,
V_66 ) ;
} else {
F_23 ( V_25 , & V_65 ,
V_67 ) ;
}
F_40 ( V_25 ) ;
F_41 ( V_25 , V_68 ) ;
return 0 ;
}
static void F_42 ( void )
{
T_3 V_69 ;
int V_70 , V_71 ;
V_69 = F_30 ( V_7 + V_72 ) ;
V_70 = ( V_69 >> 2 ) & 0x3ff ;
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ )
F_4 ( V_71 , V_9 + V_10 ) ;
F_4 ( 0 , V_9 + V_73 ) ;
F_4 ( V_74 , V_9 +
V_52 ) ;
F_4 ( 0 , V_9 + V_12 ) ;
}
static void F_43 ( void )
{
unsigned long V_75 = F_33 ( F_44 () ) ;
F_4 ( F_45 ( V_75 ) ,
V_9 + V_76 ) ;
}
static void F_46 ( const struct V_54 * V_57 ,
unsigned int V_1 )
{
int V_58 ;
unsigned long V_77 = 0 ;
F_47 (cpu, mask)
V_77 |= 1 << F_33 ( V_58 ) ;
F_48 () ;
F_4 ( ( V_77 << 8 ) | V_1 , V_7 +
V_45 ) ;
}
static int F_49 ( struct V_78 * V_79 ,
unsigned long V_80 , void * V_81 )
{
if ( V_80 == V_82 || V_80 == V_83 ) {
F_43 () ;
F_42 () ;
}
return V_84 ;
}
static int F_50 ( struct V_78 * V_79 ,
unsigned long V_80 , void * V_81 )
{
if ( V_80 == V_82 || V_80 == V_83 ) {
F_43 () ;
F_51 ( V_85 , V_86 ) ;
}
return V_84 ;
}
static void F_52 ( struct V_87 * V_88 , bool V_89 )
{
T_3 V_90 , V_91 ;
V_90 = F_53 ( V_9 +
V_73 )
& V_53 ;
F_4 ( ~ V_90 , V_9 +
V_73 ) ;
for ( V_91 = V_92 ;
V_91 < V_93 ; V_91 ++ ) {
int V_1 ;
if ( ! ( V_90 & F_54 ( V_91 ) ) )
continue;
if ( V_89 ) {
V_1 = F_55 ( V_29 ,
V_91 - 16 ) ;
F_56 ( V_1 ) ;
} else {
V_1 = V_91 - 16 ;
F_57 ( V_29 ,
V_1 , V_88 ) ;
}
}
}
static void F_52 ( struct V_87 * V_94 , bool V_95 ) {}
static void F_58 ( struct V_96 * V_22 )
{
struct V_97 * V_18 = F_59 ( V_22 ) ;
unsigned long V_98 , V_99 , V_100 , V_75 ;
unsigned int V_101 ;
F_60 ( V_18 , V_22 ) ;
V_98 = F_53 ( V_9 + V_102 ) ;
V_75 = F_33 ( F_44 () ) ;
F_61 (irqn, &irqmap, BITS_PER_LONG) {
V_100 = F_53 ( V_7 +
F_35 ( V_99 ) ) ;
if ( ! ( V_100 & F_62 ( V_75 ) ) )
continue;
if ( V_99 == 1 ) {
F_52 ( NULL , true ) ;
continue;
}
V_101 = F_55 ( V_103 , V_99 ) ;
F_56 ( V_101 ) ;
}
F_63 ( V_18 , V_22 ) ;
}
static void T_4
F_64 ( struct V_87 * V_88 )
{
T_3 V_104 , V_105 ;
do {
V_104 = F_53 ( V_9 +
V_106 ) ;
V_105 = V_104 & 0x3FF ;
if ( V_105 > 1022 )
break;
if ( V_105 > 1 ) {
F_57 ( V_103 ,
V_105 , V_88 ) ;
continue;
}
if ( V_105 == 1 )
F_52 ( V_88 , false ) ;
#ifdef F_65
if ( V_105 == 0 ) {
T_3 V_107 , V_108 ;
V_107 = F_53 ( V_9 +
V_73 )
& V_74 ;
F_4 ( ~ V_107 , V_9 +
V_73 ) ;
for ( V_108 = V_109 ;
V_108 < V_110 ; V_108 ++ ) {
if ( V_107 & ( 0x1 << V_108 ) )
F_66 ( V_108 , V_88 ) ;
}
continue;
}
#endif
} while ( 1 );
}
static int F_67 ( void )
{
V_111 = F_30 ( V_9 +
V_52 ) ;
return 0 ;
}
static void F_68 ( void )
{
int V_112 ;
T_1 V_1 ;
V_112 = ( F_30 ( V_7 + V_72 ) >> 2 ) & 0x3ff ;
for ( V_1 = 0 ; V_1 < V_112 ; V_1 ++ ) {
struct V_4 * V_33 ;
int V_25 ;
V_25 = F_69 ( V_103 , V_1 ) ;
if ( V_25 == 0 )
continue;
if ( V_1 != V_2 )
F_4 ( V_1 , V_9 +
V_12 ) ;
else
F_4 ( V_1 , V_7 +
V_11 ) ;
V_33 = F_20 ( V_25 ) ;
if ( ! F_70 ( V_33 ) )
F_5 ( V_33 ) ;
}
F_4 ( V_111 ,
V_9 + V_52 ) ;
if ( V_111 & V_74 )
F_4 ( 0 , V_9 + V_12 ) ;
if ( V_111 & V_53 )
F_4 ( 1 , V_9 + V_12 ) ;
}
static int T_5 F_71 ( struct V_39 * V_40 ,
struct V_39 * V_113 )
{
struct V_114 V_115 , V_116 ;
int V_70 , V_71 ;
T_3 V_69 ;
F_72 ( F_73 ( V_40 , 0 , & V_115 ) ) ;
F_72 ( F_73 ( V_40 , 1 , & V_116 ) ) ;
F_72 ( ! F_74 ( V_115 . V_117 ,
F_75 ( & V_115 ) ,
V_40 -> V_118 ) ) ;
F_72 ( ! F_74 ( V_116 . V_117 ,
F_75 ( & V_116 ) ,
V_40 -> V_118 ) ) ;
V_7 = F_76 ( V_115 . V_117 ,
F_75 ( & V_115 ) ) ;
F_72 ( ! V_7 ) ;
V_9 = F_76 ( V_116 . V_117 ,
F_75 ( & V_116 ) ) ;
F_72 ( ! V_9 ) ;
V_69 = F_30 ( V_7 + V_72 ) ;
V_70 = ( V_69 >> 2 ) & 0x3ff ;
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ )
F_4 ( V_71 , V_7 + V_8 ) ;
V_103 =
F_26 ( V_40 , V_70 ,
& V_119 , NULL ) ;
F_72 ( ! V_103 ) ;
F_43 () ;
F_42 () ;
F_24 ( V_40 , V_115 . V_117 ) ;
V_85 = F_77 ( V_40 , 0 ) ;
if ( V_85 <= 0 ) {
F_78 ( V_103 ) ;
F_79 ( F_64 ) ;
#ifdef F_65
F_80 ( F_46 ) ;
F_81 ( & V_120 ) ;
#endif
} else {
#ifdef F_65
F_81 ( & V_121 ) ;
#endif
F_82 ( V_85 ,
F_58 ) ;
}
F_83 ( & V_122 ) ;
return 0 ;
}
