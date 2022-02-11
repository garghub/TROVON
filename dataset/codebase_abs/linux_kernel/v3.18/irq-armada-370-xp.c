static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 ) ;
if ( V_3 != V_4 )
F_3 ( V_3 , V_5 +
V_6 ) ;
else
F_3 ( V_3 , V_7 +
V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 ) ;
if ( V_3 != V_4 )
F_3 ( V_3 , V_5 +
V_9 ) ;
else
F_3 ( V_3 , V_7 +
V_10 ) ;
}
static int F_5 ( void )
{
int V_3 ;
F_6 ( & V_11 ) ;
V_3 = F_7 ( & V_12 , V_13 ) ;
if ( V_3 >= V_13 )
V_3 = - V_14 ;
else
F_8 ( V_3 , V_12 ) ;
F_9 ( & V_11 ) ;
return V_3 ;
}
static void F_10 ( int V_3 )
{
F_6 ( & V_11 ) ;
if ( ! F_11 ( V_3 , V_12 ) )
F_12 ( L_1 , V_3 ) ;
else
F_13 ( V_3 , V_12 ) ;
F_9 ( & V_11 ) ;
}
static int F_14 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_21 V_22 ;
int V_23 , V_3 ;
if ( V_20 -> V_24 . V_25 )
return - V_26 ;
V_3 = F_5 () ;
if ( V_3 < 0 )
return V_3 ;
V_23 = F_15 ( V_27 , V_3 ) ;
if ( ! V_23 ) {
F_10 ( V_3 ) ;
return - V_26 ;
}
F_16 ( V_23 , V_20 ) ;
V_22 . V_28 = V_29 ;
V_22 . V_30 = 0 ;
V_22 . V_31 = 0xf00 | ( V_3 + 16 ) ;
F_17 ( V_23 , & V_22 ) ;
return 0 ;
}
static void F_18 ( struct V_15 * V_16 ,
unsigned int V_32 )
{
struct V_1 * V_2 = F_19 ( V_32 ) ;
unsigned long V_3 = V_2 -> V_3 ;
F_20 ( V_32 ) ;
F_10 ( V_3 ) ;
}
static int F_21 ( struct V_33 * V_34 , unsigned int V_23 ,
T_1 V_35 )
{
F_22 ( V_23 , & V_36 ,
V_37 ) ;
F_23 ( V_23 , V_38 ) ;
return 0 ;
}
static int F_24 ( struct V_39 * V_40 ,
T_2 V_41 )
{
struct V_15 * V_15 ;
T_3 V_42 ;
int V_43 ;
V_29 = V_41 +
V_44 ;
V_15 = F_25 ( sizeof( * V_15 ) , V_45 ) ;
if ( ! V_15 )
return - V_46 ;
V_15 -> V_47 = F_14 ;
V_15 -> V_48 = F_18 ;
V_15 -> V_49 = V_40 ;
V_27 =
F_26 ( NULL , V_13 ,
& V_50 ,
NULL ) ;
if ( ! V_27 ) {
F_27 ( V_15 ) ;
return - V_46 ;
}
V_43 = F_28 ( V_15 ) ;
if ( V_43 < 0 ) {
F_29 ( V_27 ) ;
F_27 ( V_15 ) ;
return V_43 ;
}
V_42 = F_30 ( V_7 + V_51 )
| V_52 ;
F_3 ( V_42 , V_7 +
V_51 ) ;
F_3 ( 1 , V_7 + V_10 ) ;
return 0 ;
}
static inline int F_24 ( struct V_39 * V_40 ,
T_2 V_41 )
{
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_53 * V_54 , bool V_55 )
{
T_1 V_3 = F_2 ( V_2 ) ;
unsigned long V_42 , V_56 ;
int V_57 ;
V_57 = F_32 ( V_54 , V_58 ) ;
V_56 = 1UL << F_33 ( V_57 ) ;
F_34 ( & V_59 ) ;
V_42 = F_30 ( V_5 + F_35 ( V_3 ) ) ;
V_42 = ( V_42 & ( ~ V_60 ) ) | V_56 ;
F_3 ( V_42 , V_5 + F_35 ( V_3 ) ) ;
F_36 ( & V_59 ) ;
return 0 ;
}
static int F_37 ( struct V_33 * V_61 ,
unsigned int V_23 , T_1 V_35 )
{
F_1 ( F_19 ( V_23 ) ) ;
if ( V_35 != V_4 )
F_3 ( V_35 , V_7 +
V_10 ) ;
else
F_3 ( V_35 , V_5 + V_9 ) ;
F_38 ( V_23 , V_62 ) ;
if ( V_35 == V_4 ) {
F_39 ( V_23 ) ;
F_22 ( V_23 , & V_63 ,
V_64 ) ;
} else {
F_22 ( V_23 , & V_63 ,
V_65 ) ;
}
F_23 ( V_23 , V_38 | V_66 ) ;
return 0 ;
}
static void F_40 ( const struct V_53 * V_56 ,
unsigned int V_32 )
{
int V_57 ;
unsigned long V_67 = 0 ;
F_41 (cpu, mask)
V_67 |= 1 << F_33 ( V_57 ) ;
F_42 () ;
F_3 ( ( V_67 << 8 ) | V_32 , V_5 +
V_44 ) ;
}
static void F_43 ( void )
{
T_3 V_68 ;
int V_69 , V_70 ;
V_68 = F_30 ( V_5 + V_71 ) ;
V_69 = ( V_68 >> 2 ) & 0x3ff ;
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ )
F_3 ( V_70 , V_7 + V_8 ) ;
F_3 ( 0 , V_7 + V_72 ) ;
F_3 ( V_73 , V_7 +
V_51 ) ;
F_3 ( 0 , V_7 + V_10 ) ;
}
static int F_44 ( struct V_74 * V_75 ,
unsigned long V_76 , void * V_77 )
{
if ( V_76 == V_78 || V_76 == V_79 )
F_43 () ;
return V_80 ;
}
static void F_45 ( struct V_81 * V_82 , bool V_83 )
{
T_3 V_84 , V_85 ;
V_84 = F_46 ( V_7 +
V_72 )
& V_52 ;
F_3 ( ~ V_84 , V_7 +
V_72 ) ;
for ( V_85 = V_86 ;
V_85 < V_87 ; V_85 ++ ) {
int V_32 ;
if ( ! ( V_84 & F_47 ( V_85 ) ) )
continue;
if ( V_83 ) {
V_32 = F_48 ( V_27 ,
V_85 - 16 ) ;
F_49 ( V_32 ) ;
} else {
V_32 = V_85 - 16 ;
F_50 ( V_27 ,
V_32 , V_82 ) ;
}
}
}
static void F_45 ( struct V_81 * V_88 , bool V_89 ) {}
static void F_51 ( unsigned int V_32 ,
struct V_90 * V_20 )
{
struct V_91 * V_16 = F_52 ( V_32 ) ;
unsigned long V_92 , V_93 , V_94 , V_95 ;
unsigned int V_96 ;
F_53 ( V_16 , V_20 ) ;
V_92 = F_46 ( V_7 + V_97 ) ;
V_95 = F_33 ( F_54 () ) ;
F_55 (irqn, &irqmap, BITS_PER_LONG) {
V_94 = F_46 ( V_5 +
F_35 ( V_93 ) ) ;
if ( ! ( V_94 & F_56 ( V_95 ) ) )
continue;
if ( V_93 == 1 ) {
F_45 ( NULL , true ) ;
continue;
}
V_96 = F_48 ( V_98 , V_93 ) ;
F_49 ( V_96 ) ;
}
F_57 ( V_16 , V_20 ) ;
}
static void T_4
F_58 ( struct V_81 * V_82 )
{
T_3 V_99 , V_100 ;
do {
V_99 = F_46 ( V_7 +
V_101 ) ;
V_100 = V_99 & 0x3FF ;
if ( V_100 > 1022 )
break;
if ( V_100 > 1 ) {
F_50 ( V_98 ,
V_100 , V_82 ) ;
continue;
}
if ( V_100 == 1 )
F_45 ( V_82 , false ) ;
#ifdef F_59
if ( V_100 == 0 ) {
T_3 V_102 , V_103 ;
V_102 = F_46 ( V_7 +
V_72 )
& V_73 ;
F_3 ( ~ V_102 , V_7 +
V_72 ) ;
for ( V_103 = V_104 ;
V_103 < V_105 ; V_103 ++ ) {
if ( V_102 & ( 0x1 << V_103 ) )
F_60 ( V_103 , V_82 ) ;
}
continue;
}
#endif
} while ( 1 );
}
static int T_5 F_61 ( struct V_39 * V_40 ,
struct V_39 * V_106 )
{
struct V_107 V_108 , V_109 ;
int V_110 , V_69 , V_70 ;
T_3 V_68 ;
F_62 ( F_63 ( V_40 , 0 , & V_108 ) ) ;
F_62 ( F_63 ( V_40 , 1 , & V_109 ) ) ;
F_62 ( ! F_64 ( V_108 . V_111 ,
F_65 ( & V_108 ) ,
V_40 -> V_112 ) ) ;
F_62 ( ! F_64 ( V_109 . V_111 ,
F_65 ( & V_109 ) ,
V_40 -> V_112 ) ) ;
V_5 = F_66 ( V_108 . V_111 ,
F_65 ( & V_108 ) ) ;
F_62 ( ! V_5 ) ;
V_7 = F_66 ( V_109 . V_111 ,
F_65 ( & V_109 ) ) ;
F_62 ( ! V_7 ) ;
V_68 = F_30 ( V_5 + V_71 ) ;
V_69 = ( V_68 >> 2 ) & 0x3ff ;
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ )
F_3 ( V_70 , V_5 + V_6 ) ;
V_98 =
F_26 ( V_40 , V_69 ,
& V_113 , NULL ) ;
F_62 ( ! V_98 ) ;
#ifdef F_59
F_43 () ;
#endif
F_24 ( V_40 , V_108 . V_111 ) ;
V_110 = F_67 ( V_40 , 0 ) ;
if ( V_110 <= 0 ) {
F_68 ( V_98 ) ;
F_69 ( F_58 ) ;
#ifdef F_59
F_70 ( F_40 ) ;
F_71 ( & V_114 ) ;
#endif
} else {
F_72 ( V_110 ,
F_51 ) ;
}
return 0 ;
}
