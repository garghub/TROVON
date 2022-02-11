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
static void F_6 ( struct V_3 * V_12 , struct V_13 * V_14 )
{
V_14 -> V_15 = F_7 ( V_16 ) ;
V_14 -> V_17 = F_8 ( V_16 ) ;
V_14 -> V_12 = 0xf00 | ( V_12 -> V_5 + V_18 ) ;
}
static int F_9 ( struct V_3 * V_3 ,
const struct V_19 * V_20 , bool V_21 )
{
return - V_22 ;
}
static int F_10 ( struct V_23 * V_24 , unsigned int V_25 ,
unsigned int V_26 , void * args )
{
int V_5 , V_27 ;
F_11 ( & V_28 ) ;
V_5 = F_12 ( V_29 , V_30 ,
0 , V_26 , 0 ) ;
if ( V_5 >= V_30 ) {
F_13 ( & V_28 ) ;
return - V_31 ;
}
F_14 ( V_29 , V_5 , V_26 ) ;
F_13 ( & V_28 ) ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {
F_15 ( V_24 , V_25 + V_27 , V_5 + V_27 ,
& V_32 ,
V_24 -> V_33 , V_34 ,
NULL , NULL ) ;
}
return V_5 ;
}
static void F_16 ( struct V_23 * V_24 ,
unsigned int V_25 , unsigned int V_26 )
{
struct V_3 * V_4 = F_17 ( V_24 , V_25 ) ;
F_11 ( & V_28 ) ;
F_18 ( V_29 , V_4 -> V_5 , V_26 ) ;
F_13 ( & V_28 ) ;
}
static int F_19 ( struct V_35 * V_36 ,
T_2 V_37 )
{
T_3 V_38 ;
V_16 = V_37 +
V_39 ;
V_40 =
F_20 ( NULL , V_30 ,
& V_41 , NULL ) ;
if ( ! V_40 )
return - V_42 ;
V_43 =
F_21 ( F_22 ( V_36 ) ,
& V_44 ,
V_40 ) ;
if ( ! V_43 ) {
F_23 ( V_40 ) ;
return - V_42 ;
}
V_38 = F_24 ( V_8 + V_45 )
| V_46 ;
F_4 ( V_38 , V_8 +
V_45 ) ;
F_4 ( 1 , V_8 + V_11 ) ;
return 0 ;
}
static inline int F_19 ( struct V_35 * V_36 ,
T_2 V_37 )
{
return 0 ;
}
static int F_25 ( struct V_3 * V_4 ,
const struct V_19 * V_47 , bool V_21 )
{
T_1 V_5 = F_3 ( V_4 ) ;
unsigned long V_38 , V_20 ;
int V_48 ;
V_48 = F_26 ( V_47 , V_49 ) ;
V_20 = 1UL << F_27 ( V_48 ) ;
F_28 ( & V_50 ) ;
V_38 = F_24 ( V_6 + F_29 ( V_5 ) ) ;
V_38 = ( V_38 & ( ~ V_51 ) ) | V_20 ;
F_4 ( V_38 , V_6 + F_29 ( V_5 ) ) ;
F_30 ( & V_50 ) ;
return V_52 ;
}
static int F_31 ( struct V_23 * V_53 ,
unsigned int V_25 , T_1 V_54 )
{
F_2 ( F_32 ( V_25 ) ) ;
if ( ! F_1 ( V_54 ) )
F_4 ( V_54 , V_8 +
V_11 ) ;
else
F_4 ( V_54 , V_6 + V_10 ) ;
F_33 ( V_25 , V_55 ) ;
if ( F_1 ( V_54 ) ) {
F_34 ( V_25 ) ;
F_35 ( V_25 , & V_56 ,
V_57 ) ;
} else {
F_35 ( V_25 , & V_56 ,
V_58 ) ;
}
F_36 ( V_25 ) ;
F_37 ( V_25 , V_59 ) ;
return 0 ;
}
static void F_38 ( void )
{
T_3 V_60 ;
int V_26 , V_27 ;
V_60 = F_24 ( V_6 + V_61 ) ;
V_26 = ( V_60 >> 2 ) & 0x3ff ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ )
F_4 ( V_27 , V_8 + V_9 ) ;
F_4 ( 0 , V_8 + V_62 ) ;
F_4 ( V_63 , V_8 +
V_45 ) ;
F_4 ( 0 , V_8 + V_11 ) ;
}
static void F_39 ( void )
{
unsigned long V_64 = F_27 ( F_40 () ) ;
F_4 ( F_41 ( V_64 ) ,
V_8 + V_65 ) ;
}
static void F_42 ( const struct V_19 * V_20 ,
unsigned int V_1 )
{
int V_48 ;
unsigned long V_66 = 0 ;
F_43 (cpu, mask)
V_66 |= 1 << F_27 ( V_48 ) ;
F_44 () ;
F_4 ( ( V_66 << 8 ) | V_1 , V_6 +
V_39 ) ;
}
static int F_45 ( struct V_67 * V_68 ,
unsigned long V_69 , void * V_70 )
{
if ( V_69 == V_71 || V_69 == V_72 ) {
F_39 () ;
F_38 () ;
}
return V_73 ;
}
static int F_46 ( struct V_67 * V_68 ,
unsigned long V_69 , void * V_70 )
{
if ( V_69 == V_71 || V_69 == V_72 ) {
F_39 () ;
F_47 ( V_74 , V_75 ) ;
}
return V_73 ;
}
static void F_48 ( struct V_76 * V_77 , bool V_78 )
{
T_3 V_79 , V_80 ;
V_79 = F_49 ( V_8 +
V_62 )
& V_46 ;
F_4 ( ~ V_79 , V_8 +
V_62 ) ;
for ( V_80 = V_18 ;
V_80 < V_81 ; V_80 ++ ) {
int V_1 ;
if ( ! ( V_79 & F_50 ( V_80 ) ) )
continue;
if ( V_78 ) {
V_1 = F_51 ( V_40 ,
V_80 - V_18 ) ;
F_52 ( V_1 ) ;
} else {
V_1 = V_80 - V_18 ;
F_53 ( V_40 ,
V_1 , V_77 ) ;
}
}
}
static void F_48 ( struct V_76 * V_82 , bool V_83 ) {}
static void F_54 ( struct V_84 * V_85 )
{
struct V_86 * V_87 = F_55 ( V_85 ) ;
unsigned long V_88 , V_89 , V_90 , V_64 ;
unsigned int V_91 ;
F_56 ( V_87 , V_85 ) ;
V_88 = F_49 ( V_8 + V_92 ) ;
V_64 = F_27 ( F_40 () ) ;
F_57 (irqn, &irqmap, BITS_PER_LONG) {
V_90 = F_49 ( V_6 +
F_29 ( V_89 ) ) ;
if ( ! ( V_90 & F_58 ( V_64 ) ) )
continue;
if ( V_89 == 1 ) {
F_48 ( NULL , true ) ;
continue;
}
V_91 = F_51 ( V_93 , V_89 ) ;
F_52 ( V_91 ) ;
}
F_59 ( V_87 , V_85 ) ;
}
static void T_4
F_60 ( struct V_76 * V_77 )
{
T_3 V_94 , V_95 ;
do {
V_94 = F_49 ( V_8 +
V_96 ) ;
V_95 = V_94 & 0x3FF ;
if ( V_95 > 1022 )
break;
if ( V_95 > 1 ) {
F_53 ( V_93 ,
V_95 , V_77 ) ;
continue;
}
if ( V_95 == 1 )
F_48 ( V_77 , false ) ;
#ifdef F_61
if ( V_95 == 0 ) {
T_3 V_97 , V_98 ;
V_97 = F_49 ( V_8 +
V_62 )
& V_63 ;
F_4 ( ~ V_97 , V_8 +
V_62 ) ;
for ( V_98 = V_99 ;
V_98 < V_100 ; V_98 ++ ) {
if ( V_97 & ( 0x1 << V_98 ) )
F_62 ( V_98 , V_77 ) ;
}
continue;
}
#endif
} while ( 1 );
}
static int F_63 ( void )
{
V_101 = F_24 ( V_8 +
V_45 ) ;
return 0 ;
}
static void F_64 ( void )
{
int V_102 ;
T_1 V_1 ;
V_102 = ( F_24 ( V_6 + V_61 ) >> 2 ) & 0x3ff ;
for ( V_1 = 0 ; V_1 < V_102 ; V_1 ++ ) {
struct V_3 * V_12 ;
int V_25 ;
V_25 = F_65 ( V_93 , V_1 ) ;
if ( V_25 == 0 )
continue;
if ( ! F_1 ( V_1 ) )
F_4 ( V_1 , V_8 +
V_11 ) ;
else
F_4 ( V_1 , V_6 +
V_10 ) ;
V_12 = F_32 ( V_25 ) ;
if ( ! F_66 ( V_12 ) )
F_5 ( V_12 ) ;
}
F_4 ( V_101 ,
V_8 + V_45 ) ;
if ( V_101 & V_63 )
F_4 ( 0 , V_8 + V_11 ) ;
if ( V_101 & V_46 )
F_4 ( 1 , V_8 + V_11 ) ;
}
static int T_5 F_67 ( struct V_35 * V_36 ,
struct V_35 * V_103 )
{
struct V_104 V_105 , V_106 ;
int V_26 , V_27 ;
T_3 V_60 ;
F_68 ( F_69 ( V_36 , 0 , & V_105 ) ) ;
F_68 ( F_69 ( V_36 , 1 , & V_106 ) ) ;
F_68 ( ! F_70 ( V_105 . V_107 ,
F_71 ( & V_105 ) ,
V_36 -> V_108 ) ) ;
F_68 ( ! F_70 ( V_106 . V_107 ,
F_71 ( & V_106 ) ,
V_36 -> V_108 ) ) ;
V_6 = F_72 ( V_105 . V_107 ,
F_71 ( & V_105 ) ) ;
F_68 ( ! V_6 ) ;
V_8 = F_72 ( V_106 . V_107 ,
F_71 ( & V_106 ) ) ;
F_68 ( ! V_8 ) ;
V_60 = F_24 ( V_6 + V_61 ) ;
V_26 = ( V_60 >> 2 ) & 0x3ff ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ )
F_4 ( V_27 , V_6 + V_7 ) ;
V_93 =
F_20 ( V_36 , V_26 ,
& V_109 , NULL ) ;
F_68 ( ! V_93 ) ;
V_93 -> V_110 = V_111 ;
F_39 () ;
F_38 () ;
F_19 ( V_36 , V_105 . V_107 ) ;
V_74 = F_73 ( V_36 , 0 ) ;
if ( V_74 <= 0 ) {
F_74 ( V_93 ) ;
F_75 ( F_60 ) ;
#ifdef F_61
F_76 ( F_42 ) ;
F_77 ( & V_112 ) ;
#endif
} else {
#ifdef F_61
F_77 ( & V_113 ) ;
#endif
F_78 ( V_74 ,
F_54 ) ;
}
F_79 ( & V_114 ) ;
return 0 ;
}
