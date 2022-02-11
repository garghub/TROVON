static inline void T_1 * F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , struct V_3 , V_4 ) -> V_5 ;
}
static inline struct V_3 * F_3 ( unsigned V_6 )
{
return & V_7 [ F_4 ( V_6 ) ] ;
}
static inline int F_5 ( int type )
{
return ( type & V_8 ) == 0 ;
}
static inline int F_6 ( int type )
{
return ( type & V_8 ) != 0 ;
}
static inline int F_7 ( int V_6 )
{
if ( ( V_9 == V_10 ) && ( V_6 > 85 ) )
return 1 ;
return 0 ;
}
static inline int F_8 ( unsigned V_6 )
{
struct V_3 * V_11 ;
void T_1 * V_12 ;
unsigned long V_13 = 0 , V_14 = 0 ;
int V_15 , V_16 = 0 , V_17 = 0 ;
V_11 = F_3 ( V_6 ) ;
V_12 = F_1 ( & V_11 -> V_4 ) ;
V_14 = F_9 ( V_12 + V_18 ) ;
switch ( V_9 ) {
case V_19 :
case V_10 :
case V_20 :
V_13 = F_9 ( V_12 + V_21 ) ;
V_16 = ( V_13 >> ( ( V_6 & 0xf ) * 2 ) ) & 0x3 ;
V_17 = V_14 & F_10 ( V_6 ) ;
if ( F_7 ( V_6 ) )
V_15 = ( V_16 != 1 ) || ( V_17 == 0 ) ;
else
V_15 = ( V_16 != 0 ) || ( V_17 != 0 ) ;
break;
default:
V_15 = V_14 & F_10 ( V_6 ) ;
break;
}
return V_15 ;
}
static int F_11 ( struct V_1 * V_4 , unsigned V_22 )
{
return V_4 -> V_12 + V_22 + V_23 ;
}
int F_12 ( int V_24 )
{
return V_24 - V_23 ;
}
static int F_13 ( struct V_1 * V_4 , unsigned V_22 )
{
void T_1 * V_12 = F_1 ( V_4 ) ;
T_2 V_25 , V_26 = 1 << V_22 ;
unsigned long V_27 ;
F_14 ( & V_28 , V_27 ) ;
V_25 = F_9 ( V_12 + V_18 ) ;
if ( F_7 ( V_4 -> V_12 + V_22 ) )
V_25 |= V_26 ;
else
V_25 &= ~ V_26 ;
F_15 ( V_25 , V_12 + V_18 ) ;
F_16 ( & V_28 , V_27 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_4 ,
unsigned V_22 , int V_25 )
{
void T_1 * V_12 = F_1 ( V_4 ) ;
T_2 V_29 , V_26 = 1 << V_22 ;
unsigned long V_27 ;
F_15 ( V_26 , V_12 + ( V_25 ? V_30 : V_31 ) ) ;
F_14 ( & V_28 , V_27 ) ;
V_29 = F_9 ( V_12 + V_18 ) ;
if ( F_7 ( V_4 -> V_12 + V_22 ) )
V_29 &= ~ V_26 ;
else
V_29 |= V_26 ;
F_15 ( V_29 , V_12 + V_18 ) ;
F_16 ( & V_28 , V_27 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_4 , unsigned V_22 )
{
return F_9 ( F_1 ( V_4 ) + V_32 ) & ( 1 << V_22 ) ;
}
static void F_19 ( struct V_1 * V_4 , unsigned V_22 , int V_25 )
{
F_15 ( 1 << V_22 , F_1 ( V_4 ) +
( V_25 ? V_30 : V_31 ) ) ;
}
static int F_20 ( struct V_1 * V_33 ,
const struct V_34 * V_35 ,
T_3 * V_27 )
{
if ( V_35 -> args [ 0 ] > V_36 )
return - V_37 ;
if ( V_33 != & V_7 [ V_35 -> args [ 0 ] / 32 ] . V_4 )
return - V_37 ;
if ( V_27 )
* V_27 = V_35 -> args [ 1 ] ;
return V_35 -> args [ 0 ] % 32 ;
}
static int F_21 ( int V_38 ,
int (* F_22)( unsigned int , unsigned int ) )
{
int V_39 , V_6 , V_40 = F_4 ( V_38 ) + 1 ;
struct V_3 * V_41 ;
V_41 = F_23 ( V_40 * sizeof( struct V_3 ) , V_42 ) ;
if ( V_41 == NULL ) {
F_24 ( L_1 , V_43 ) ;
return - V_44 ;
}
for ( V_39 = 0 , V_6 = 0 ; V_39 < V_40 ; V_39 ++ , V_6 += 32 ) {
struct V_1 * V_2 = & V_41 [ V_39 ] . V_4 ;
sprintf ( V_41 [ V_39 ] . V_45 , L_2 , V_39 ) ;
V_41 [ V_39 ] . V_5 = V_46 + F_25 ( V_39 ) ;
V_41 [ V_39 ] . F_22 = F_22 ;
V_2 -> V_12 = V_6 ;
V_2 -> V_45 = V_41 [ V_39 ] . V_45 ;
V_2 -> V_47 = F_13 ;
V_2 -> V_48 = F_17 ;
V_2 -> V_49 = F_18 ;
V_2 -> V_50 = F_19 ;
V_2 -> V_51 = F_11 ;
#ifdef F_26
V_2 -> V_52 = V_53 ;
V_2 -> V_54 = F_20 ;
V_2 -> V_55 = 2 ;
#endif
V_2 -> V_56 = ( V_6 + 31 > V_38 ) ? ( V_38 - V_6 + 1 ) : 32 ;
F_27 ( V_2 ) ;
}
V_7 = V_41 ;
return 0 ;
}
static inline void F_28 ( struct V_3 * V_2 )
{
T_2 V_57 , V_58 ;
V_57 = F_9 ( V_2 -> V_5 + V_59 ) & ~ V_2 -> V_60 ;
V_58 = F_9 ( V_2 -> V_5 + V_61 ) & ~ V_2 -> V_60 ;
V_57 |= V_2 -> V_62 & V_2 -> V_60 ;
V_58 |= V_2 -> V_63 & V_2 -> V_60 ;
F_15 ( V_57 , V_2 -> V_5 + V_59 ) ;
F_15 ( V_58 , V_2 -> V_5 + V_61 ) ;
}
static int F_29 ( struct V_64 * V_65 , unsigned int type )
{
struct V_3 * V_2 ;
int V_6 = F_12 ( V_65 -> V_24 ) ;
unsigned long V_14 , V_26 = F_10 ( V_6 ) ;
V_2 = F_3 ( V_6 ) ;
if ( type == V_66 ) {
if ( ( V_2 -> V_62 | V_2 -> V_63 ) & F_10 ( V_6 ) )
return 0 ;
if ( F_8 ( V_6 ) )
return 0 ;
type = V_67 | V_68 ;
}
V_14 = F_9 ( V_2 -> V_5 + V_18 ) ;
if ( F_7 ( V_6 ) )
F_15 ( V_14 | V_26 , V_2 -> V_5 + V_18 ) ;
else
F_15 ( V_14 & ~ V_26 , V_2 -> V_5 + V_18 ) ;
if ( type & V_67 )
V_2 -> V_62 |= V_26 ;
else
V_2 -> V_62 &= ~ V_26 ;
if ( type & V_68 )
V_2 -> V_63 |= V_26 ;
else
V_2 -> V_63 &= ~ V_26 ;
F_28 ( V_2 ) ;
F_30 ( L_3 , V_43 , V_65 -> V_24 , V_6 ,
( ( type & V_67 ) ? L_4 : L_5 ) ,
( ( type & V_68 ) ? L_6 : L_5 ) ) ;
return 0 ;
}
static void F_31 ( unsigned int V_24 , struct V_69 * V_70 )
{
struct V_3 * V_2 ;
int V_71 , V_6 , V_72 , V_73 ;
unsigned long V_74 ;
struct V_75 * V_4 = F_32 ( V_70 ) ;
F_33 ( V_4 , V_70 ) ;
do {
V_71 = 0 ;
F_34 (gpio, c) {
V_72 = V_2 -> V_4 . V_12 ;
V_74 = F_9 ( V_2 -> V_5 + V_76 ) ;
V_74 = V_74 & V_2 -> V_60 ;
F_15 ( V_74 , V_2 -> V_5 + V_76 ) ;
F_35 (n, &gedr, BITS_PER_LONG) {
V_71 = 1 ;
F_36 ( F_37 ( V_72 + V_73 ) ) ;
}
}
} while ( V_71 );
F_38 ( V_4 , V_70 ) ;
}
static void F_39 ( struct V_64 * V_65 )
{
int V_6 = F_12 ( V_65 -> V_24 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
F_15 ( F_10 ( V_6 ) , V_2 -> V_5 + V_76 ) ;
}
static void F_40 ( struct V_64 * V_65 )
{
int V_6 = F_12 ( V_65 -> V_24 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
T_2 V_57 , V_58 ;
V_2 -> V_60 &= ~ F_10 ( V_6 ) ;
V_57 = F_9 ( V_2 -> V_5 + V_59 ) & ~ F_10 ( V_6 ) ;
V_58 = F_9 ( V_2 -> V_5 + V_61 ) & ~ F_10 ( V_6 ) ;
F_15 ( V_57 , V_2 -> V_5 + V_59 ) ;
F_15 ( V_58 , V_2 -> V_5 + V_61 ) ;
}
static int F_41 ( struct V_64 * V_65 , unsigned int V_77 )
{
int V_6 = F_12 ( V_65 -> V_24 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
if ( V_2 -> F_22 )
return V_2 -> F_22 ( V_6 , V_77 ) ;
else
return 0 ;
}
static void F_42 ( struct V_64 * V_65 )
{
int V_6 = F_12 ( V_65 -> V_24 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
V_2 -> V_60 |= F_10 ( V_6 ) ;
F_28 ( V_2 ) ;
}
static int F_43 ( void )
{
int V_78 = 0 ;
#ifdef F_44
if ( F_45 () ) {
#ifdef F_46
V_78 = 89 ;
V_9 = V_10 ;
#elif F_47 ( V_79 )
V_78 = 84 ;
V_9 = V_10 ;
#endif
} else if ( F_48 () ) {
V_78 = 120 ;
V_9 = V_20 ;
} else if ( F_49 () ) {
V_78 = 191 ;
V_9 = V_80 ;
} else if ( F_50 () ) {
V_78 = 127 ;
V_9 = V_81 ;
}
#endif
#ifdef F_51
if ( F_52 () || F_53 () ) {
V_78 = 127 ;
V_9 = V_8 ;
} else if ( F_54 () ) {
V_78 = 191 ;
V_9 = V_8 ;
}
#endif
return V_78 ;
}
static int F_55 ( struct V_82 * V_65 , unsigned int V_24 ,
T_4 V_83 )
{
F_56 ( V_24 , & V_84 ,
V_85 ) ;
F_57 ( V_24 , V_86 | V_87 ) ;
return 0 ;
}
static int F_58 ( struct V_88 * V_89 )
{
int V_15 , V_90 , V_91 ;
struct V_92 * V_93 , * V_94 , * V_95 = V_89 -> V_96 . V_52 ;
const struct V_97 * V_98 =
F_59 ( V_99 , & V_89 -> V_96 ) ;
if ( ! V_98 ) {
F_60 ( & V_89 -> V_96 , L_7 ) ;
return - V_100 ;
}
V_9 = ( int ) V_98 -> V_101 ;
V_94 = F_61 ( V_95 , NULL ) ;
V_93 = V_94 ;
if ( ! V_94 ) {
F_60 ( & V_89 -> V_96 , L_8 ) ;
V_15 = - V_37 ;
goto V_102;
}
for ( V_90 = 1 ; ; V_90 ++ ) {
V_94 = F_61 ( V_95 , V_93 ) ;
if ( ! V_94 )
break;
V_93 = V_94 ;
}
F_62 ( V_93 ) ;
V_91 = V_90 << 5 ;
V_36 = V_91 - 1 ;
V_23 = F_63 ( - 1 , 0 , V_91 , 0 ) ;
if ( V_23 < 0 ) {
F_60 ( & V_89 -> V_96 , L_9 ) ;
goto V_102;
}
V_103 = F_64 ( V_95 , V_91 , V_23 , 0 ,
& V_104 , NULL ) ;
V_53 = V_95 ;
return 0 ;
V_102:
F_65 ( V_46 ) ;
return V_15 ;
}
static int F_66 ( struct V_88 * V_89 )
{
struct V_3 * V_2 ;
struct V_105 * V_106 ;
struct V_107 * V_107 ;
struct V_108 * V_109 ;
int V_6 , V_24 , V_15 , V_110 = 0 ;
int V_111 = 0 , V_112 = 0 , V_113 , V_114 = 0 ;
V_15 = F_58 ( V_89 ) ;
if ( V_15 < 0 ) {
V_36 = F_43 () ;
#ifdef F_44
if ( F_5 ( V_9 ) )
V_23 = F_67 ( 0 ) ;
#endif
#ifdef F_51
if ( F_6 ( V_9 ) )
V_23 = F_68 ( 0 ) ;
#endif
} else {
V_110 = 1 ;
}
if ( ! V_36 )
return - V_37 ;
V_111 = F_69 ( V_89 , L_10 ) ;
V_112 = F_69 ( V_89 , L_11 ) ;
V_113 = F_69 ( V_89 , L_12 ) ;
if ( ( V_111 > 0 && V_112 <= 0 ) || ( V_111 <= 0 && V_112 > 0 )
|| ( V_113 <= 0 ) )
return - V_37 ;
V_106 = F_70 ( V_89 , V_115 , 0 ) ;
if ( ! V_106 )
return - V_37 ;
V_46 = F_71 ( V_106 -> V_116 , F_72 ( V_106 ) ) ;
if ( ! V_46 )
return - V_37 ;
if ( V_111 > 0 )
V_114 = 2 ;
V_107 = F_73 ( & V_89 -> V_96 , NULL ) ;
if ( F_74 ( V_107 ) ) {
F_60 ( & V_89 -> V_96 , L_13 ,
F_75 ( V_107 ) ) ;
F_65 ( V_46 ) ;
return F_75 ( V_107 ) ;
}
V_15 = F_76 ( V_107 ) ;
if ( V_15 ) {
F_77 ( V_107 ) ;
F_65 ( V_46 ) ;
return V_15 ;
}
V_109 = F_78 ( & V_89 -> V_96 ) ;
F_21 ( V_36 , V_109 ? V_109 -> V_117 : NULL ) ;
F_34 (gpio, c) {
F_15 ( 0 , V_2 -> V_5 + V_61 ) ;
F_15 ( 0 , V_2 -> V_5 + V_59 ) ;
F_15 ( ~ 0 , V_2 -> V_5 + V_76 ) ;
if ( F_6 ( V_9 ) )
F_15 ( ~ 0 , V_2 -> V_5 + V_118 ) ;
}
if ( ! V_110 ) {
#ifdef F_44
V_24 = F_37 ( 0 ) ;
F_56 ( V_24 , & V_84 ,
V_85 ) ;
F_57 ( V_24 , V_86 | V_87 ) ;
F_79 ( V_119 , F_31 ) ;
V_24 = F_37 ( 1 ) ;
F_56 ( V_24 , & V_84 ,
V_85 ) ;
F_57 ( V_24 , V_86 | V_87 ) ;
F_79 ( V_120 , F_31 ) ;
#endif
for ( V_24 = F_37 ( V_114 ) ;
V_24 <= F_37 ( V_36 ) ; V_24 ++ ) {
F_56 ( V_24 , & V_84 ,
V_85 ) ;
F_57 ( V_24 , V_86 | V_87 ) ;
}
}
F_79 ( V_113 , F_31 ) ;
return 0 ;
}
static int T_5 F_80 ( void )
{
return F_81 ( & V_121 ) ;
}
static int F_82 ( void )
{
struct V_3 * V_2 ;
int V_6 ;
F_34 (gpio, c) {
V_2 -> V_122 = F_9 ( V_2 -> V_5 + V_32 ) ;
V_2 -> V_123 = F_9 ( V_2 -> V_5 + V_18 ) ;
V_2 -> V_124 = F_9 ( V_2 -> V_5 + V_59 ) ;
V_2 -> V_125 = F_9 ( V_2 -> V_5 + V_61 ) ;
F_15 ( 0xffffffff , V_2 -> V_5 + V_76 ) ;
}
return 0 ;
}
static void F_83 ( void )
{
struct V_3 * V_2 ;
int V_6 ;
F_34 (gpio, c) {
F_15 ( V_2 -> V_122 , V_2 -> V_5 + V_30 ) ;
F_15 ( ~ V_2 -> V_122 , V_2 -> V_5 + V_31 ) ;
F_15 ( V_2 -> V_124 , V_2 -> V_5 + V_59 ) ;
F_15 ( V_2 -> V_125 , V_2 -> V_5 + V_61 ) ;
F_15 ( V_2 -> V_123 , V_2 -> V_5 + V_18 ) ;
}
}
static int T_5 F_84 ( void )
{
F_85 ( & V_126 ) ;
return 0 ;
}
