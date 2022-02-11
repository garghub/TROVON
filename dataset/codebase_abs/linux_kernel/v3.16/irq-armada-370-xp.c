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
V_3 = F_5 () ;
if ( V_3 < 0 )
return V_3 ;
V_23 = F_15 ( V_24 , V_3 ) ;
if ( ! V_23 ) {
F_10 ( V_3 ) ;
return - V_25 ;
}
F_16 ( V_23 , V_20 ) ;
V_22 . V_26 = V_27 ;
V_22 . V_28 = 0 ;
V_22 . V_29 = 0xf00 | ( V_3 + 16 ) ;
F_17 ( V_23 , & V_22 ) ;
return 0 ;
}
static void F_18 ( struct V_15 * V_16 ,
unsigned int V_30 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
unsigned long V_3 = V_2 -> V_3 ;
F_20 ( V_30 ) ;
F_10 ( V_3 ) ;
}
static int F_21 ( struct V_15 * V_16 , struct V_17 * V_31 ,
int V_32 , int type )
{
if ( type == V_33 )
return 0 ;
return - V_25 ;
}
static int F_22 ( struct V_34 * V_35 , unsigned int V_23 ,
T_1 V_36 )
{
F_23 ( V_23 , & V_37 ,
V_38 ) ;
F_24 ( V_23 , V_39 ) ;
return 0 ;
}
static int F_25 ( struct V_40 * V_41 ,
T_2 V_42 )
{
struct V_15 * V_15 ;
T_3 V_43 ;
int V_44 ;
V_27 = V_42 +
V_45 ;
V_15 = F_26 ( sizeof( * V_15 ) , V_46 ) ;
if ( ! V_15 )
return - V_47 ;
V_15 -> V_48 = F_14 ;
V_15 -> V_49 = F_18 ;
V_15 -> V_50 = F_21 ;
V_15 -> V_51 = V_41 ;
V_24 =
F_27 ( NULL , V_13 ,
& V_52 ,
NULL ) ;
if ( ! V_24 ) {
F_28 ( V_15 ) ;
return - V_47 ;
}
V_44 = F_29 ( V_15 ) ;
if ( V_44 < 0 ) {
F_30 ( V_24 ) ;
F_28 ( V_15 ) ;
return V_44 ;
}
V_43 = F_31 ( V_7 + V_53 )
| V_54 ;
F_3 ( V_43 , V_7 +
V_53 ) ;
F_3 ( 1 , V_7 + V_10 ) ;
return 0 ;
}
static inline int F_25 ( struct V_40 * V_41 ,
T_2 V_42 )
{
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
const struct V_55 * V_56 , bool V_57 )
{
T_1 V_3 = F_2 ( V_2 ) ;
unsigned long V_43 , V_58 ;
int V_59 ;
V_59 = F_33 ( V_56 , V_60 ) ;
V_58 = 1UL << F_34 ( V_59 ) ;
F_35 ( & V_61 ) ;
V_43 = F_31 ( V_5 + F_36 ( V_3 ) ) ;
V_43 = ( V_43 & ( ~ V_62 ) ) | V_58 ;
F_3 ( V_43 , V_5 + F_36 ( V_3 ) ) ;
F_37 ( & V_61 ) ;
return 0 ;
}
static int F_38 ( struct V_34 * V_63 ,
unsigned int V_23 , T_1 V_36 )
{
F_1 ( F_19 ( V_23 ) ) ;
if ( V_36 != V_4 )
F_3 ( V_36 , V_7 +
V_10 ) ;
else
F_3 ( V_36 , V_5 + V_9 ) ;
F_39 ( V_23 , V_64 ) ;
if ( V_36 == V_4 ) {
F_40 ( V_23 ) ;
F_23 ( V_23 , & V_65 ,
V_66 ) ;
} else {
F_23 ( V_23 , & V_65 ,
V_67 ) ;
}
F_24 ( V_23 , V_39 | V_68 ) ;
return 0 ;
}
static void F_41 ( const struct V_55 * V_58 ,
unsigned int V_30 )
{
int V_59 ;
unsigned long V_69 = 0 ;
F_42 (cpu, mask)
V_69 |= 1 << F_34 ( V_59 ) ;
F_43 () ;
F_3 ( ( V_69 << 8 ) | V_30 , V_5 +
V_45 ) ;
}
static void F_44 ( void )
{
T_3 V_70 ;
int V_71 , V_72 ;
V_70 = F_31 ( V_5 + V_73 ) ;
V_71 = ( V_70 >> 2 ) & 0x3ff ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ )
F_3 ( V_72 , V_7 + V_8 ) ;
F_3 ( 0 , V_7 + V_74 ) ;
F_3 ( V_75 , V_7 +
V_53 ) ;
F_3 ( 0 , V_7 + V_10 ) ;
}
static int F_45 ( struct V_76 * V_77 ,
unsigned long V_78 , void * V_79 )
{
if ( V_78 == V_80 || V_78 == V_81 )
F_44 () ;
return V_82 ;
}
static void F_46 ( struct V_83 * V_84 , bool V_85 )
{
T_3 V_86 , V_87 ;
V_86 = F_47 ( V_7 +
V_74 )
& V_54 ;
F_3 ( ~ V_86 , V_7 +
V_74 ) ;
for ( V_87 = V_88 ;
V_87 < V_89 ; V_87 ++ ) {
int V_30 ;
if ( ! ( V_86 & F_48 ( V_87 ) ) )
continue;
V_30 = F_49 ( V_24 ,
V_87 - 16 ) ;
if ( V_85 )
F_50 ( V_30 ) ;
else
F_51 ( V_30 , V_84 ) ;
}
}
static void F_46 ( struct V_83 * V_90 , bool V_91 ) {}
static void F_52 ( unsigned int V_30 ,
struct V_92 * V_20 )
{
struct V_93 * V_16 = F_53 ( V_30 ) ;
unsigned long V_94 , V_95 ;
unsigned int V_96 ;
F_54 ( V_16 , V_20 ) ;
V_94 = F_47 ( V_7 + V_97 ) ;
if ( V_94 & F_48 ( 0 ) ) {
F_46 ( NULL , true ) ;
V_94 &= ~ F_48 ( 0 ) ;
}
F_55 (irqn, &irqmap, BITS_PER_LONG) {
V_96 = F_49 ( V_98 , V_95 ) ;
F_50 ( V_96 ) ;
}
F_56 ( V_16 , V_20 ) ;
}
static void T_4
F_57 ( struct V_83 * V_84 )
{
T_3 V_99 , V_100 ;
do {
V_99 = F_47 ( V_7 +
V_101 ) ;
V_100 = V_99 & 0x3FF ;
if ( V_100 > 1022 )
break;
if ( V_100 > 1 ) {
V_100 = F_49 ( V_98 ,
V_100 ) ;
F_51 ( V_100 , V_84 ) ;
continue;
}
if ( V_100 == 1 )
F_46 ( V_84 , false ) ;
#ifdef F_58
if ( V_100 == 0 ) {
T_3 V_102 , V_103 ;
V_102 = F_47 ( V_7 +
V_74 )
& V_75 ;
F_3 ( ~ V_102 , V_7 +
V_74 ) ;
for ( V_103 = V_104 ;
V_103 < V_105 ; V_103 ++ ) {
if ( V_102 & ( 0x1 << V_103 ) )
F_59 ( V_103 , V_84 ) ;
}
continue;
}
#endif
} while ( 1 );
}
static int T_5 F_60 ( struct V_40 * V_41 ,
struct V_40 * V_106 )
{
struct V_107 V_108 , V_109 ;
int V_110 , V_71 , V_72 ;
T_3 V_70 ;
F_61 ( F_62 ( V_41 , 0 , & V_108 ) ) ;
F_61 ( F_62 ( V_41 , 1 , & V_109 ) ) ;
F_61 ( ! F_63 ( V_108 . V_111 ,
F_64 ( & V_108 ) ,
V_41 -> V_112 ) ) ;
F_61 ( ! F_63 ( V_109 . V_111 ,
F_64 ( & V_109 ) ,
V_41 -> V_112 ) ) ;
V_5 = F_65 ( V_108 . V_111 ,
F_64 ( & V_108 ) ) ;
F_61 ( ! V_5 ) ;
V_7 = F_65 ( V_109 . V_111 ,
F_64 ( & V_109 ) ) ;
F_61 ( ! V_7 ) ;
V_70 = F_31 ( V_5 + V_73 ) ;
V_71 = ( V_70 >> 2 ) & 0x3ff ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ )
F_3 ( V_72 , V_5 + V_6 ) ;
V_98 =
F_27 ( V_41 , V_71 ,
& V_113 , NULL ) ;
F_61 ( ! V_98 ) ;
#ifdef F_58
F_44 () ;
#endif
F_25 ( V_41 , V_108 . V_111 ) ;
V_110 = F_66 ( V_41 , 0 ) ;
if ( V_110 <= 0 ) {
F_67 ( V_98 ) ;
F_68 ( F_57 ) ;
#ifdef F_58
F_69 ( F_41 ) ;
F_70 ( & V_114 ) ;
#endif
} else {
F_71 ( V_110 ,
F_52 ) ;
}
return 0 ;
}
