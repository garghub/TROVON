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
struct V_15 * V_42 ;
T_3 V_43 ;
int V_44 ;
V_29 = V_41 +
V_45 ;
V_42 = F_25 ( sizeof( * V_42 ) , V_46 ) ;
if ( ! V_42 )
return - V_47 ;
V_42 -> V_48 = F_14 ;
V_42 -> V_49 = F_18 ;
V_42 -> V_50 = V_40 ;
V_27 =
F_26 ( NULL , V_13 ,
& V_51 ,
NULL ) ;
if ( ! V_27 ) {
F_27 ( V_42 ) ;
return - V_47 ;
}
V_44 = F_28 ( V_42 ) ;
if ( V_44 < 0 ) {
F_29 ( V_27 ) ;
F_27 ( V_42 ) ;
return V_44 ;
}
V_43 = F_30 ( V_7 + V_52 )
| V_53 ;
F_3 ( V_43 , V_7 +
V_52 ) ;
F_3 ( 1 , V_7 + V_10 ) ;
return 0 ;
}
static inline int F_24 ( struct V_39 * V_40 ,
T_2 V_41 )
{
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_54 * V_55 , bool V_56 )
{
T_1 V_3 = F_2 ( V_2 ) ;
unsigned long V_43 , V_57 ;
int V_58 ;
V_58 = F_32 ( V_55 , V_59 ) ;
V_57 = 1UL << F_33 ( V_58 ) ;
F_34 ( & V_60 ) ;
V_43 = F_30 ( V_5 + F_35 ( V_3 ) ) ;
V_43 = ( V_43 & ( ~ V_61 ) ) | V_57 ;
F_3 ( V_43 , V_5 + F_35 ( V_3 ) ) ;
F_36 ( & V_60 ) ;
return V_62 ;
}
static int F_37 ( struct V_33 * V_63 ,
unsigned int V_23 , T_1 V_35 )
{
F_1 ( F_19 ( V_23 ) ) ;
if ( V_35 != V_4 )
F_3 ( V_35 , V_7 +
V_10 ) ;
else
F_3 ( V_35 , V_5 + V_9 ) ;
F_38 ( V_23 , V_64 ) ;
if ( V_35 == V_4 ) {
F_39 ( V_23 ) ;
F_22 ( V_23 , & V_65 ,
V_66 ) ;
} else {
F_22 ( V_23 , & V_65 ,
V_67 ) ;
}
F_23 ( V_23 , V_38 | V_68 ) ;
return 0 ;
}
static void F_40 ( const struct V_54 * V_57 ,
unsigned int V_32 )
{
int V_58 ;
unsigned long V_69 = 0 ;
F_41 (cpu, mask)
V_69 |= 1 << F_33 ( V_58 ) ;
F_42 () ;
F_3 ( ( V_69 << 8 ) | V_32 , V_5 +
V_45 ) ;
}
static void F_43 ( void )
{
T_3 V_70 ;
int V_71 , V_72 ;
V_70 = F_30 ( V_5 + V_73 ) ;
V_71 = ( V_70 >> 2 ) & 0x3ff ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ )
F_3 ( V_72 , V_7 + V_8 ) ;
F_3 ( 0 , V_7 + V_74 ) ;
F_3 ( V_75 , V_7 +
V_52 ) ;
F_3 ( 0 , V_7 + V_10 ) ;
}
static int F_44 ( struct V_76 * V_77 ,
unsigned long V_78 , void * V_79 )
{
if ( V_78 == V_80 || V_78 == V_81 )
F_43 () ;
return V_82 ;
}
static void F_45 ( struct V_83 * V_84 , bool V_85 )
{
T_3 V_86 , V_87 ;
V_86 = F_46 ( V_7 +
V_74 )
& V_53 ;
F_3 ( ~ V_86 , V_7 +
V_74 ) ;
for ( V_87 = V_88 ;
V_87 < V_89 ; V_87 ++ ) {
int V_32 ;
if ( ! ( V_86 & F_47 ( V_87 ) ) )
continue;
if ( V_85 ) {
V_32 = F_48 ( V_27 ,
V_87 - 16 ) ;
F_49 ( V_32 ) ;
} else {
V_32 = V_87 - 16 ;
F_50 ( V_27 ,
V_32 , V_84 ) ;
}
}
}
static void F_45 ( struct V_83 * V_90 , bool V_91 ) {}
static void F_51 ( unsigned int V_32 ,
struct V_92 * V_20 )
{
struct V_93 * V_16 = F_52 ( V_32 ) ;
unsigned long V_94 , V_95 , V_96 , V_97 ;
unsigned int V_98 ;
F_53 ( V_16 , V_20 ) ;
V_94 = F_46 ( V_7 + V_99 ) ;
V_97 = F_33 ( F_54 () ) ;
F_55 (irqn, &irqmap, BITS_PER_LONG) {
V_96 = F_46 ( V_5 +
F_35 ( V_95 ) ) ;
if ( ! ( V_96 & F_56 ( V_97 ) ) )
continue;
if ( V_95 == 1 ) {
F_45 ( NULL , true ) ;
continue;
}
V_98 = F_48 ( V_100 , V_95 ) ;
F_49 ( V_98 ) ;
}
F_57 ( V_16 , V_20 ) ;
}
static void T_4
F_58 ( struct V_83 * V_84 )
{
T_3 V_101 , V_102 ;
do {
V_101 = F_46 ( V_7 +
V_103 ) ;
V_102 = V_101 & 0x3FF ;
if ( V_102 > 1022 )
break;
if ( V_102 > 1 ) {
F_50 ( V_100 ,
V_102 , V_84 ) ;
continue;
}
if ( V_102 == 1 )
F_45 ( V_84 , false ) ;
#ifdef F_59
if ( V_102 == 0 ) {
T_3 V_104 , V_105 ;
V_104 = F_46 ( V_7 +
V_74 )
& V_75 ;
F_3 ( ~ V_104 , V_7 +
V_74 ) ;
for ( V_105 = V_106 ;
V_105 < V_107 ; V_105 ++ ) {
if ( V_104 & ( 0x1 << V_105 ) )
F_60 ( V_105 , V_84 ) ;
}
continue;
}
#endif
} while ( 1 );
}
static int F_61 ( void )
{
V_108 = F_30 ( V_7 +
V_52 ) ;
return 0 ;
}
static void F_62 ( void )
{
int V_109 ;
T_1 V_32 ;
V_109 = ( F_30 ( V_5 + V_73 ) >> 2 ) & 0x3ff ;
for ( V_32 = 0 ; V_32 < V_109 ; V_32 ++ ) {
struct V_1 * V_31 ;
int V_23 ;
V_23 = F_63 ( V_100 , V_32 ) ;
if ( V_23 == 0 )
continue;
if ( V_32 != V_4 )
F_3 ( V_32 , V_7 +
V_10 ) ;
else
F_3 ( V_32 , V_5 +
V_9 ) ;
V_31 = F_19 ( V_23 ) ;
if ( ! F_64 ( V_31 ) )
F_4 ( V_31 ) ;
}
F_3 ( V_108 ,
V_7 + V_52 ) ;
if ( V_108 & V_75 )
F_3 ( 0 , V_7 + V_10 ) ;
if ( V_108 & V_53 )
F_3 ( 1 , V_7 + V_10 ) ;
}
static int T_5 F_65 ( struct V_39 * V_40 ,
struct V_39 * V_110 )
{
struct V_111 V_112 , V_113 ;
int V_114 , V_71 , V_72 ;
T_3 V_70 ;
F_66 ( F_67 ( V_40 , 0 , & V_112 ) ) ;
F_66 ( F_67 ( V_40 , 1 , & V_113 ) ) ;
F_66 ( ! F_68 ( V_112 . V_115 ,
F_69 ( & V_112 ) ,
V_40 -> V_116 ) ) ;
F_66 ( ! F_68 ( V_113 . V_115 ,
F_69 ( & V_113 ) ,
V_40 -> V_116 ) ) ;
V_5 = F_70 ( V_112 . V_115 ,
F_69 ( & V_112 ) ) ;
F_66 ( ! V_5 ) ;
V_7 = F_70 ( V_113 . V_115 ,
F_69 ( & V_113 ) ) ;
F_66 ( ! V_7 ) ;
V_70 = F_30 ( V_5 + V_73 ) ;
V_71 = ( V_70 >> 2 ) & 0x3ff ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ )
F_3 ( V_72 , V_5 + V_6 ) ;
V_100 =
F_26 ( V_40 , V_71 ,
& V_117 , NULL ) ;
F_66 ( ! V_100 ) ;
#ifdef F_59
F_43 () ;
#endif
F_24 ( V_40 , V_112 . V_115 ) ;
V_114 = F_71 ( V_40 , 0 ) ;
if ( V_114 <= 0 ) {
F_72 ( V_100 ) ;
F_73 ( F_58 ) ;
#ifdef F_59
F_74 ( F_40 ) ;
F_75 ( & V_118 ) ;
#endif
} else {
F_76 ( V_114 ,
F_51 ) ;
}
F_77 ( & V_119 ) ;
return 0 ;
}
