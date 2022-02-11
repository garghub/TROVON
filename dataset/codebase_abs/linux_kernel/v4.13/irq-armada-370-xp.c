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
return 0 ;
}
static void F_37 ( void )
{
T_3 V_59 ;
int V_26 , V_27 ;
V_59 = F_24 ( V_6 + V_60 ) ;
V_26 = ( V_59 >> 2 ) & 0x3ff ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ )
F_4 ( V_27 , V_8 + V_9 ) ;
F_4 ( 0 , V_8 + V_61 ) ;
F_4 ( V_62 , V_8 +
V_45 ) ;
F_4 ( 0 , V_8 + V_11 ) ;
}
static void F_38 ( void )
{
unsigned long V_63 = F_27 ( F_39 () ) ;
F_4 ( F_40 ( V_63 ) ,
V_8 + V_64 ) ;
}
static void F_41 ( const struct V_19 * V_20 ,
unsigned int V_1 )
{
int V_48 ;
unsigned long V_65 = 0 ;
F_42 (cpu, mask)
V_65 |= 1 << F_27 ( V_48 ) ;
F_43 () ;
F_4 ( ( V_65 << 8 ) | V_1 , V_6 +
V_39 ) ;
}
static void F_44 ( void )
{
unsigned int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
struct V_3 * V_12 ;
int V_25 ;
V_25 = F_45 ( V_66 , V_1 ) ;
if ( V_25 == 0 )
continue;
V_12 = F_32 ( V_25 ) ;
if ( ! F_46 ( V_25 ) )
continue;
F_5 ( V_12 ) ;
}
}
static int F_47 ( unsigned int V_48 )
{
F_38 () ;
F_37 () ;
F_44 () ;
return 0 ;
}
static int F_48 ( unsigned int V_48 )
{
F_38 () ;
F_44 () ;
F_49 ( V_67 , V_68 ) ;
return 0 ;
}
static void F_50 ( struct V_69 * V_70 , bool V_71 )
{
T_3 V_72 , V_73 ;
V_72 = F_51 ( V_8 +
V_61 )
& V_46 ;
F_4 ( ~ V_72 , V_8 +
V_61 ) ;
for ( V_73 = V_18 ;
V_73 < V_74 ; V_73 ++ ) {
int V_1 ;
if ( ! ( V_72 & F_52 ( V_73 ) ) )
continue;
if ( V_71 ) {
V_1 = F_53 ( V_40 ,
V_73 - V_18 ) ;
F_54 ( V_1 ) ;
} else {
V_1 = V_73 - V_18 ;
F_55 ( V_40 ,
V_1 , V_70 ) ;
}
}
}
static void F_50 ( struct V_69 * V_75 , bool V_76 ) {}
static void F_56 ( struct V_77 * V_78 )
{
struct V_79 * V_80 = F_57 ( V_78 ) ;
unsigned long V_81 , V_82 , V_83 , V_63 ;
unsigned int V_84 ;
F_58 ( V_80 , V_78 ) ;
V_81 = F_51 ( V_8 + V_85 ) ;
V_63 = F_27 ( F_39 () ) ;
F_59 (irqn, &irqmap, BITS_PER_LONG) {
V_83 = F_51 ( V_6 +
F_29 ( V_82 ) ) ;
if ( ! ( V_83 & F_60 ( V_63 ) ) )
continue;
if ( V_82 == 1 ) {
F_50 ( NULL , true ) ;
continue;
}
V_84 = F_53 ( V_66 , V_82 ) ;
F_54 ( V_84 ) ;
}
F_61 ( V_80 , V_78 ) ;
}
static void T_4
F_62 ( struct V_69 * V_70 )
{
T_3 V_86 , V_87 ;
do {
V_86 = F_51 ( V_8 +
V_88 ) ;
V_87 = V_86 & 0x3FF ;
if ( V_87 > 1022 )
break;
if ( V_87 > 1 ) {
F_55 ( V_66 ,
V_87 , V_70 ) ;
continue;
}
if ( V_87 == 1 )
F_50 ( V_70 , false ) ;
#ifdef F_63
if ( V_87 == 0 ) {
T_3 V_89 , V_90 ;
V_89 = F_51 ( V_8 +
V_61 )
& V_62 ;
F_4 ( ~ V_89 , V_8 +
V_61 ) ;
for ( V_90 = V_91 ;
V_90 < V_92 ; V_90 ++ ) {
if ( V_89 & ( 0x1 << V_90 ) )
F_64 ( V_90 , V_70 ) ;
}
continue;
}
#endif
} while ( 1 );
}
static int F_65 ( void )
{
V_93 = F_24 ( V_8 +
V_45 ) ;
return 0 ;
}
static void F_66 ( void )
{
int V_94 ;
T_1 V_1 ;
V_94 = ( F_24 ( V_6 + V_60 ) >> 2 ) & 0x3ff ;
for ( V_1 = 0 ; V_1 < V_94 ; V_1 ++ ) {
struct V_3 * V_12 ;
int V_25 ;
V_25 = F_45 ( V_66 , V_1 ) ;
if ( V_25 == 0 )
continue;
V_12 = F_32 ( V_25 ) ;
if ( ! F_1 ( V_1 ) ) {
F_4 ( V_1 , V_8 +
V_11 ) ;
if ( ! F_67 ( V_12 ) )
F_5 ( V_12 ) ;
} else {
F_4 ( V_1 , V_6 +
V_10 ) ;
if ( F_46 ( V_25 ) )
F_5 ( V_12 ) ;
}
}
F_4 ( V_93 ,
V_8 + V_45 ) ;
if ( V_93 & V_62 )
F_4 ( 0 , V_8 + V_11 ) ;
if ( V_93 & V_46 )
F_4 ( 1 , V_8 + V_11 ) ;
}
static int T_5 F_68 ( struct V_35 * V_36 ,
struct V_35 * V_95 )
{
struct V_96 V_97 , V_98 ;
int V_26 , V_27 ;
T_3 V_59 ;
F_69 ( F_70 ( V_36 , 0 , & V_97 ) ) ;
F_69 ( F_70 ( V_36 , 1 , & V_98 ) ) ;
F_69 ( ! F_71 ( V_97 . V_99 ,
F_72 ( & V_97 ) ,
V_36 -> V_100 ) ) ;
F_69 ( ! F_71 ( V_98 . V_99 ,
F_72 ( & V_98 ) ,
V_36 -> V_100 ) ) ;
V_6 = F_73 ( V_97 . V_99 ,
F_72 ( & V_97 ) ) ;
F_69 ( ! V_6 ) ;
V_8 = F_73 ( V_98 . V_99 ,
F_72 ( & V_98 ) ) ;
F_69 ( ! V_8 ) ;
V_59 = F_24 ( V_6 + V_60 ) ;
V_26 = ( V_59 >> 2 ) & 0x3ff ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ )
F_4 ( V_27 , V_6 + V_7 ) ;
V_66 =
F_20 ( V_36 , V_26 ,
& V_101 , NULL ) ;
F_69 ( ! V_66 ) ;
F_74 ( V_66 , V_102 ) ;
F_38 () ;
F_37 () ;
F_19 ( V_36 , V_97 . V_99 ) ;
V_67 = F_75 ( V_36 , 0 ) ;
if ( V_67 <= 0 ) {
F_76 ( V_66 ) ;
F_77 ( F_62 ) ;
#ifdef F_63
F_78 ( F_41 ) ;
F_79 ( V_103 ,
L_1 ,
F_47 , NULL ) ;
#endif
} else {
#ifdef F_63
F_79 ( V_103 ,
L_2 ,
F_48 , NULL ) ;
#endif
F_80 ( V_67 ,
F_56 ) ;
}
F_81 ( & V_104 ) ;
return 0 ;
}
