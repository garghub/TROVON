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
void F_41 ( const struct V_55 * V_58 , unsigned int V_30 )
{
int V_59 ;
unsigned long V_69 = 0 ;
F_42 (cpu, mask)
V_69 |= 1 << F_34 ( V_59 ) ;
F_43 () ;
F_3 ( ( V_69 << 8 ) | V_30 , V_5 +
V_45 ) ;
}
void F_44 ( void )
{
F_3 ( 0 , V_7 + V_70 ) ;
F_3 ( V_71 , V_7 +
V_53 ) ;
F_3 ( 0 , V_7 + V_10 ) ;
}
static void F_45 ( struct V_72 * V_73 , bool V_74 )
{
T_3 V_75 , V_76 ;
V_75 = F_46 ( V_7 +
V_70 )
& V_54 ;
F_3 ( ~ V_75 , V_7 +
V_70 ) ;
for ( V_76 = V_77 ;
V_76 < V_78 ; V_76 ++ ) {
int V_30 ;
if ( ! ( V_75 & F_47 ( V_76 ) ) )
continue;
V_30 = F_48 ( V_24 ,
V_76 - 16 ) ;
if ( V_74 )
F_49 ( V_30 ) ;
else
F_50 ( V_30 , V_73 ) ;
}
}
static void F_45 ( struct V_72 * V_79 , bool V_80 ) {}
static void F_51 ( unsigned int V_30 ,
struct V_81 * V_20 )
{
struct V_82 * V_16 = F_52 ( V_30 ) ;
unsigned long V_83 , V_84 ;
unsigned int V_85 ;
F_53 ( V_16 , V_20 ) ;
V_83 = F_46 ( V_7 + V_86 ) ;
if ( V_83 & F_47 ( 0 ) ) {
F_45 ( NULL , true ) ;
V_83 &= ~ F_47 ( 0 ) ;
}
F_54 (irqn, &irqmap, BITS_PER_LONG) {
V_85 = F_48 ( V_87 , V_84 ) ;
F_49 ( V_85 ) ;
}
F_55 ( V_16 , V_20 ) ;
}
static void T_4
F_56 ( struct V_72 * V_73 )
{
T_3 V_88 , V_89 ;
do {
V_88 = F_46 ( V_7 +
V_90 ) ;
V_89 = V_88 & 0x3FF ;
if ( V_89 > 1022 )
break;
if ( V_89 > 1 ) {
V_89 = F_48 ( V_87 ,
V_89 ) ;
F_50 ( V_89 , V_73 ) ;
continue;
}
if ( V_89 == 1 )
F_45 ( V_73 , false ) ;
#ifdef F_57
if ( V_89 == 0 ) {
T_3 V_91 , V_92 ;
V_91 = F_46 ( V_7 +
V_70 )
& V_71 ;
F_3 ( ~ V_91 , V_7 +
V_70 ) ;
for ( V_92 = V_93 ;
V_92 < V_94 ; V_92 ++ ) {
if ( V_91 & ( 0x1 << V_92 ) )
F_58 ( V_92 , V_73 ) ;
}
continue;
}
#endif
} while ( 1 );
}
static int T_5 F_59 ( struct V_40 * V_41 ,
struct V_40 * V_95 )
{
struct V_96 V_97 , V_98 ;
int V_99 ;
T_3 V_100 ;
F_60 ( F_61 ( V_41 , 0 , & V_97 ) ) ;
F_60 ( F_61 ( V_41 , 1 , & V_98 ) ) ;
F_60 ( ! F_62 ( V_97 . V_101 ,
F_63 ( & V_97 ) ,
V_41 -> V_102 ) ) ;
F_60 ( ! F_62 ( V_98 . V_101 ,
F_63 ( & V_98 ) ,
V_41 -> V_102 ) ) ;
V_5 = F_64 ( V_97 . V_101 ,
F_63 ( & V_97 ) ) ;
F_60 ( ! V_5 ) ;
V_7 = F_64 ( V_98 . V_101 ,
F_63 ( & V_98 ) ) ;
F_60 ( ! V_7 ) ;
V_100 = F_31 ( V_5 + V_103 ) ;
V_87 =
F_27 ( V_41 , ( V_100 >> 2 ) & 0x3ff ,
& V_104 , NULL ) ;
F_60 ( ! V_87 ) ;
#ifdef F_57
F_44 () ;
#endif
F_25 ( V_41 , V_97 . V_101 ) ;
V_99 = F_65 ( V_41 , 0 ) ;
if ( V_99 <= 0 ) {
F_66 ( V_87 ) ;
F_67 ( F_56 ) ;
} else {
F_68 ( V_99 ,
F_51 ) ;
}
return 0 ;
}
