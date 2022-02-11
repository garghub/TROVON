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
static inline int F_11 ( int V_6 )
{
if ( F_5 ( V_9 ) )
return F_12 ( V_6 ) ;
return - 1 ;
}
static inline int F_13 ( int V_22 )
{
if ( F_5 ( V_9 ) )
return V_22 - F_12 ( 0 ) ;
return - 1 ;
}
static inline int F_11 ( int V_6 ) { return - 1 ; }
static inline int F_13 ( int V_22 ) { return - 1 ; }
static inline int F_14 ( int V_6 )
{
if ( F_6 ( V_9 ) )
return F_15 ( V_6 ) ;
return - 1 ;
}
static inline int F_16 ( int V_22 )
{
if ( F_6 ( V_9 ) )
return V_22 - F_15 ( 0 ) ;
return - 1 ;
}
static inline int F_14 ( int V_6 ) { return - 1 ; }
static inline int F_16 ( int V_22 ) { return - 1 ; }
static int F_17 ( struct V_1 * V_4 , unsigned V_23 )
{
int V_6 , V_15 ;
V_6 = V_4 -> V_12 + V_23 ;
V_15 = F_11 ( V_6 ) ;
if ( V_15 >= 0 )
return V_15 ;
return F_14 ( V_6 ) ;
}
int F_18 ( int V_22 )
{
int V_15 ;
V_15 = F_13 ( V_22 ) ;
if ( V_15 >= 0 )
return V_15 ;
return F_16 ( V_22 ) ;
}
static int F_19 ( struct V_1 * V_4 , unsigned V_23 )
{
void T_1 * V_12 = F_1 ( V_4 ) ;
T_2 V_24 , V_25 = 1 << V_23 ;
unsigned long V_26 ;
F_20 ( & V_27 , V_26 ) ;
V_24 = F_9 ( V_12 + V_18 ) ;
if ( F_7 ( V_4 -> V_12 + V_23 ) )
V_24 |= V_25 ;
else
V_24 &= ~ V_25 ;
F_21 ( V_24 , V_12 + V_18 ) ;
F_22 ( & V_27 , V_26 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_4 ,
unsigned V_23 , int V_24 )
{
void T_1 * V_12 = F_1 ( V_4 ) ;
T_2 V_28 , V_25 = 1 << V_23 ;
unsigned long V_26 ;
F_21 ( V_25 , V_12 + ( V_24 ? V_29 : V_30 ) ) ;
F_20 ( & V_27 , V_26 ) ;
V_28 = F_9 ( V_12 + V_18 ) ;
if ( F_7 ( V_4 -> V_12 + V_23 ) )
V_28 &= ~ V_25 ;
else
V_28 |= V_25 ;
F_21 ( V_28 , V_12 + V_18 ) ;
F_22 ( & V_27 , V_26 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_4 , unsigned V_23 )
{
return F_9 ( F_1 ( V_4 ) + V_31 ) & ( 1 << V_23 ) ;
}
static void F_25 ( struct V_1 * V_4 , unsigned V_23 , int V_24 )
{
F_21 ( 1 << V_23 , F_1 ( V_4 ) +
( V_24 ? V_29 : V_30 ) ) ;
}
static int F_26 ( struct V_1 * V_32 ,
const struct V_33 * V_34 ,
T_3 * V_26 )
{
if ( V_34 -> args [ 0 ] > V_35 )
return - V_36 ;
if ( V_32 != & V_7 [ V_34 -> args [ 0 ] / 32 ] . V_4 )
return - V_36 ;
if ( V_26 )
* V_26 = V_34 -> args [ 1 ] ;
return V_34 -> args [ 0 ] % 32 ;
}
static int T_4 F_27 ( int V_37 ,
int (* F_28)( unsigned int , unsigned int ) )
{
int V_38 , V_6 , V_39 = F_4 ( V_37 ) + 1 ;
struct V_3 * V_40 ;
V_40 = F_29 ( V_39 * sizeof( struct V_3 ) , V_41 ) ;
if ( V_40 == NULL ) {
F_30 ( L_1 , V_42 ) ;
return - V_43 ;
}
for ( V_38 = 0 , V_6 = 0 ; V_38 < V_39 ; V_38 ++ , V_6 += 32 ) {
struct V_1 * V_2 = & V_40 [ V_38 ] . V_4 ;
sprintf ( V_40 [ V_38 ] . V_44 , L_2 , V_38 ) ;
V_40 [ V_38 ] . V_5 = V_45 + F_31 ( V_38 ) ;
V_40 [ V_38 ] . F_28 = F_28 ;
V_2 -> V_12 = V_6 ;
V_2 -> V_44 = V_40 [ V_38 ] . V_44 ;
V_2 -> V_46 = F_19 ;
V_2 -> V_47 = F_23 ;
V_2 -> V_48 = F_24 ;
V_2 -> V_49 = F_25 ;
V_2 -> V_50 = F_17 ;
#ifdef F_32
V_2 -> V_51 = V_52 ;
V_2 -> V_53 = F_26 ;
V_2 -> V_54 = 2 ;
#endif
V_2 -> V_55 = ( V_6 + 31 > V_37 ) ? ( V_37 - V_6 + 1 ) : 32 ;
F_33 ( V_2 ) ;
}
V_7 = V_40 ;
return 0 ;
}
static inline void F_34 ( struct V_3 * V_2 )
{
T_2 V_56 , V_57 ;
V_56 = F_9 ( V_2 -> V_5 + V_58 ) & ~ V_2 -> V_59 ;
V_57 = F_9 ( V_2 -> V_5 + V_60 ) & ~ V_2 -> V_59 ;
V_56 |= V_2 -> V_61 & V_2 -> V_59 ;
V_57 |= V_2 -> V_62 & V_2 -> V_59 ;
F_21 ( V_56 , V_2 -> V_5 + V_58 ) ;
F_21 ( V_57 , V_2 -> V_5 + V_60 ) ;
}
static int F_35 ( struct V_63 * V_64 , unsigned int type )
{
struct V_3 * V_2 ;
int V_6 = F_18 ( V_64 -> V_22 ) ;
unsigned long V_14 , V_25 = F_10 ( V_6 ) ;
V_2 = F_3 ( V_6 ) ;
if ( type == V_65 ) {
if ( ( V_2 -> V_61 | V_2 -> V_62 ) & F_10 ( V_6 ) )
return 0 ;
if ( F_8 ( V_6 ) )
return 0 ;
type = V_66 | V_67 ;
}
V_14 = F_9 ( V_2 -> V_5 + V_18 ) ;
if ( F_7 ( V_6 ) )
F_21 ( V_14 | V_25 , V_2 -> V_5 + V_18 ) ;
else
F_21 ( V_14 & ~ V_25 , V_2 -> V_5 + V_18 ) ;
if ( type & V_66 )
V_2 -> V_61 |= V_25 ;
else
V_2 -> V_61 &= ~ V_25 ;
if ( type & V_67 )
V_2 -> V_62 |= V_25 ;
else
V_2 -> V_62 &= ~ V_25 ;
F_34 ( V_2 ) ;
F_36 ( L_3 , V_42 , V_64 -> V_22 , V_6 ,
( ( type & V_66 ) ? L_4 : L_5 ) ,
( ( type & V_67 ) ? L_6 : L_5 ) ) ;
return 0 ;
}
static void F_37 ( unsigned int V_22 , struct V_68 * V_69 )
{
struct V_3 * V_2 ;
int V_70 , V_6 , V_71 , V_72 ;
unsigned long V_73 ;
do {
V_70 = 0 ;
F_38 (gpio, c) {
V_71 = V_2 -> V_4 . V_12 ;
V_73 = F_9 ( V_2 -> V_5 + V_74 ) ;
V_73 = V_73 & V_2 -> V_59 ;
F_21 ( V_73 , V_2 -> V_5 + V_74 ) ;
V_72 = F_39 ( & V_73 , V_75 ) ;
while ( V_72 < V_75 ) {
V_70 = 1 ;
F_40 ( F_41 ( V_71 + V_72 ) ) ;
V_72 = F_42 ( & V_73 , V_75 , V_72 + 1 ) ;
}
}
} while ( V_70 );
}
static void F_43 ( struct V_63 * V_64 )
{
int V_6 = F_18 ( V_64 -> V_22 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
F_21 ( F_10 ( V_6 ) , V_2 -> V_5 + V_74 ) ;
}
static void F_44 ( struct V_63 * V_64 )
{
int V_6 = F_18 ( V_64 -> V_22 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
T_2 V_56 , V_57 ;
V_2 -> V_59 &= ~ F_10 ( V_6 ) ;
V_56 = F_9 ( V_2 -> V_5 + V_58 ) & ~ F_10 ( V_6 ) ;
V_57 = F_9 ( V_2 -> V_5 + V_60 ) & ~ F_10 ( V_6 ) ;
F_21 ( V_56 , V_2 -> V_5 + V_58 ) ;
F_21 ( V_57 , V_2 -> V_5 + V_60 ) ;
}
static int F_45 ( struct V_63 * V_64 , unsigned int V_76 )
{
int V_6 = F_18 ( V_64 -> V_22 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
if ( V_2 -> F_28 )
return V_2 -> F_28 ( V_6 , V_76 ) ;
else
return 0 ;
}
static void F_46 ( struct V_63 * V_64 )
{
int V_6 = F_18 ( V_64 -> V_22 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
V_2 -> V_59 |= F_10 ( V_6 ) ;
F_34 ( V_2 ) ;
}
static int F_47 ( void )
{
int V_77 = 0 ;
#ifdef F_48
if ( F_49 () ) {
#ifdef F_50
V_77 = 89 ;
V_9 = V_10 ;
#elif F_51 ( V_78 )
V_77 = 84 ;
V_9 = V_10 ;
#endif
} else if ( F_52 () ) {
V_77 = 120 ;
V_9 = V_20 ;
} else if ( F_53 () || F_54 () ) {
V_77 = 191 ;
V_9 = V_79 ;
} else if ( F_55 () ) {
V_77 = 127 ;
V_9 = V_80 ;
}
#endif
#ifdef F_56
if ( F_57 () || F_58 () ) {
V_77 = 127 ;
V_9 = V_8 ;
} else if ( F_59 () ) {
V_77 = 191 ;
V_9 = V_8 ;
}
#endif
return V_77 ;
}
static int F_60 ( struct V_81 * V_64 , unsigned int V_22 ,
T_5 V_82 )
{
F_61 ( V_22 , & V_83 ,
V_84 ) ;
F_62 ( V_22 , V_85 | V_86 ) ;
return 0 ;
}
static int T_4 F_63 ( struct V_87 * V_88 )
{
int V_15 , V_89 , V_90 , V_91 ;
struct V_92 * V_93 , * V_94 , * V_95 = V_88 -> V_96 . V_51 ;
const struct V_97 * V_98 =
F_64 ( V_99 , & V_88 -> V_96 ) ;
if ( ! V_98 ) {
F_65 ( & V_88 -> V_96 , L_7 ) ;
return - V_100 ;
}
V_9 = ( int ) V_98 -> V_101 ;
V_94 = F_66 ( V_95 , NULL ) ;
V_93 = V_94 ;
if ( ! V_94 ) {
F_65 ( & V_88 -> V_96 , L_8 ) ;
V_15 = - V_36 ;
goto V_102;
}
for ( V_89 = 1 ; ; V_89 ++ ) {
V_94 = F_66 ( V_95 , V_93 ) ;
if ( ! V_94 )
break;
V_93 = V_94 ;
}
F_67 ( V_93 ) ;
V_90 = V_89 << 5 ;
V_35 = V_90 - 1 ;
V_91 = F_68 ( - 1 , 0 , V_90 , 0 ) ;
if ( V_91 < 0 ) {
F_65 ( & V_88 -> V_96 , L_9 ) ;
goto V_102;
}
V_103 = F_69 ( V_95 , V_90 , V_91 , 0 ,
& V_104 , NULL ) ;
V_52 = V_95 ;
return 0 ;
V_102:
F_70 ( V_45 ) ;
return V_15 ;
}
static int T_4 F_71 ( struct V_87 * V_88 )
{
struct V_3 * V_2 ;
struct V_105 * V_106 ;
struct V_107 * V_107 ;
struct V_108 * V_109 ;
int V_6 , V_22 , V_15 , V_110 = 0 ;
int V_111 = 0 , V_112 = 0 , V_113 , V_114 = 0 ;
V_15 = F_63 ( V_88 ) ;
if ( V_15 < 0 )
V_35 = F_47 () ;
else
V_110 = 1 ;
if ( ! V_35 )
return - V_36 ;
V_111 = F_72 ( V_88 , L_10 ) ;
V_112 = F_72 ( V_88 , L_11 ) ;
V_113 = F_72 ( V_88 , L_12 ) ;
if ( ( V_111 > 0 && V_112 <= 0 ) || ( V_111 <= 0 && V_112 > 0 )
|| ( V_113 <= 0 ) )
return - V_36 ;
V_106 = F_73 ( V_88 , V_115 , 0 ) ;
if ( ! V_106 )
return - V_36 ;
V_45 = F_74 ( V_106 -> V_116 , F_75 ( V_106 ) ) ;
if ( ! V_45 )
return - V_36 ;
if ( V_111 > 0 )
V_114 = 2 ;
V_107 = F_76 ( & V_88 -> V_96 , NULL ) ;
if ( F_77 ( V_107 ) ) {
F_65 ( & V_88 -> V_96 , L_13 ,
F_78 ( V_107 ) ) ;
F_70 ( V_45 ) ;
return F_78 ( V_107 ) ;
}
V_15 = F_79 ( V_107 ) ;
if ( V_15 ) {
F_80 ( V_107 ) ;
F_70 ( V_45 ) ;
return V_15 ;
}
V_15 = F_81 ( V_107 ) ;
if ( V_15 ) {
F_82 ( V_107 ) ;
F_80 ( V_107 ) ;
F_70 ( V_45 ) ;
return V_15 ;
}
V_109 = F_83 ( & V_88 -> V_96 ) ;
F_27 ( V_35 , V_109 ? V_109 -> V_117 : NULL ) ;
F_38 (gpio, c) {
F_21 ( 0 , V_2 -> V_5 + V_60 ) ;
F_21 ( 0 , V_2 -> V_5 + V_58 ) ;
F_21 ( ~ 0 , V_2 -> V_5 + V_74 ) ;
if ( F_6 ( V_9 ) )
F_21 ( ~ 0 , V_2 -> V_5 + V_118 ) ;
}
if ( ! V_110 ) {
#ifdef F_48
V_22 = F_41 ( 0 ) ;
F_61 ( V_22 , & V_83 ,
V_84 ) ;
F_62 ( V_22 , V_85 | V_86 ) ;
F_84 ( V_119 , F_37 ) ;
V_22 = F_41 ( 1 ) ;
F_61 ( V_22 , & V_83 ,
V_84 ) ;
F_62 ( V_22 , V_85 | V_86 ) ;
F_84 ( V_120 , F_37 ) ;
#endif
for ( V_22 = F_41 ( V_114 ) ;
V_22 <= F_41 ( V_35 ) ; V_22 ++ ) {
F_61 ( V_22 , & V_83 ,
V_84 ) ;
F_62 ( V_22 , V_85 | V_86 ) ;
}
}
F_84 ( V_113 , F_37 ) ;
return 0 ;
}
static int T_6 F_85 ( void )
{
return F_86 ( & V_121 ) ;
}
static int F_87 ( void )
{
struct V_3 * V_2 ;
int V_6 ;
F_38 (gpio, c) {
V_2 -> V_122 = F_9 ( V_2 -> V_5 + V_31 ) ;
V_2 -> V_123 = F_9 ( V_2 -> V_5 + V_18 ) ;
V_2 -> V_124 = F_9 ( V_2 -> V_5 + V_58 ) ;
V_2 -> V_125 = F_9 ( V_2 -> V_5 + V_60 ) ;
F_21 ( 0xffffffff , V_2 -> V_5 + V_74 ) ;
}
return 0 ;
}
static void F_88 ( void )
{
struct V_3 * V_2 ;
int V_6 ;
F_38 (gpio, c) {
F_21 ( V_2 -> V_122 , V_2 -> V_5 + V_29 ) ;
F_21 ( ~ V_2 -> V_122 , V_2 -> V_5 + V_30 ) ;
F_21 ( V_2 -> V_124 , V_2 -> V_5 + V_58 ) ;
F_21 ( V_2 -> V_125 , V_2 -> V_5 + V_60 ) ;
F_21 ( V_2 -> V_123 , V_2 -> V_5 + V_18 ) ;
}
}
static int T_6 F_89 ( void )
{
F_90 ( & V_126 ) ;
return 0 ;
}
