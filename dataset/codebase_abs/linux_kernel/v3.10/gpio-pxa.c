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
static int F_43 ( struct V_78 * V_79 )
{
const struct V_80 * V_81 = F_44 ( V_79 ) ;
struct V_82 * V_83 = (struct V_82 * ) V_81 -> V_84 ;
int V_85 = 0 ;
switch ( V_83 -> type ) {
case V_19 :
case V_10 :
case V_20 :
case V_86 :
case V_87 :
case V_8 :
case V_88 :
V_9 = V_83 -> type ;
V_85 = V_83 -> V_89 - 1 ;
break;
default:
V_85 = - V_37 ;
break;
}
return V_85 ;
}
static int F_45 ( struct V_90 * V_65 , unsigned int V_24 ,
T_4 V_91 )
{
F_46 ( V_24 , & V_92 ,
V_93 ) ;
F_47 ( V_24 , V_94 | V_95 ) ;
return 0 ;
}
static int F_48 ( struct V_78 * V_79 )
{
int V_15 , V_96 ;
struct V_97 * V_98 , * V_99 , * V_100 = V_79 -> V_101 . V_52 ;
const struct V_102 * V_103 =
F_49 ( V_104 , & V_79 -> V_101 ) ;
const struct V_82 * V_105 ;
if ( ! V_103 || ! V_103 -> V_106 ) {
F_50 ( & V_79 -> V_101 , L_7 ) ;
return - V_107 ;
}
V_105 = V_103 -> V_106 ;
V_9 = V_105 -> type ;
V_99 = F_51 ( V_100 , NULL ) ;
V_98 = V_99 ;
if ( ! V_99 ) {
F_50 ( & V_79 -> V_101 , L_8 ) ;
V_15 = - V_37 ;
goto V_108;
}
F_52 ( V_98 ) ;
V_96 = V_105 -> V_89 ;
V_36 = V_96 - 1 ;
V_23 = F_53 ( - 1 , 0 , V_96 , 0 ) ;
if ( V_23 < 0 ) {
F_50 ( & V_79 -> V_101 , L_9 ) ;
goto V_108;
}
V_109 = F_54 ( V_100 , V_96 , V_23 , 0 ,
& V_110 , NULL ) ;
V_53 = V_100 ;
return 0 ;
V_108:
F_55 ( V_46 ) ;
return V_15 ;
}
static int F_56 ( struct V_78 * V_79 )
{
struct V_3 * V_2 ;
struct V_111 * V_112 ;
struct V_113 * V_113 ;
struct V_114 * V_115 ;
int V_6 , V_24 , V_15 , V_116 = 0 ;
int V_117 = 0 , V_118 = 0 , V_119 , V_120 = 0 ;
V_115 = F_57 ( & V_79 -> V_101 ) ;
if ( V_115 ) {
V_23 = V_115 -> V_23 ;
if ( V_23 <= 0 )
return - V_37 ;
V_36 = F_43 ( V_79 ) ;
} else {
V_23 = 0 ;
V_116 = 1 ;
V_15 = F_48 ( V_79 ) ;
if ( V_15 < 0 )
return - V_37 ;
}
if ( ! V_36 )
return - V_37 ;
V_117 = F_58 ( V_79 , L_10 ) ;
V_118 = F_58 ( V_79 , L_11 ) ;
V_119 = F_58 ( V_79 , L_12 ) ;
if ( ( V_117 > 0 && V_118 <= 0 ) || ( V_117 <= 0 && V_118 > 0 )
|| ( V_119 <= 0 ) )
return - V_37 ;
V_112 = F_59 ( V_79 , V_121 , 0 ) ;
if ( ! V_112 )
return - V_37 ;
V_46 = F_60 ( V_112 -> V_122 , F_61 ( V_112 ) ) ;
if ( ! V_46 )
return - V_37 ;
if ( V_117 > 0 )
V_120 = 2 ;
V_113 = F_62 ( & V_79 -> V_101 , NULL ) ;
if ( F_63 ( V_113 ) ) {
F_50 ( & V_79 -> V_101 , L_13 ,
F_64 ( V_113 ) ) ;
F_55 ( V_46 ) ;
return F_64 ( V_113 ) ;
}
V_15 = F_65 ( V_113 ) ;
if ( V_15 ) {
F_66 ( V_113 ) ;
F_55 ( V_46 ) ;
return V_15 ;
}
F_21 ( V_36 , V_115 ? V_115 -> V_123 : NULL ) ;
F_34 (gpio, c) {
F_15 ( 0 , V_2 -> V_5 + V_61 ) ;
F_15 ( 0 , V_2 -> V_5 + V_59 ) ;
F_15 ( ~ 0 , V_2 -> V_5 + V_76 ) ;
if ( F_6 ( V_9 ) )
F_15 ( ~ 0 , V_2 -> V_5 + V_124 ) ;
}
if ( ! V_116 ) {
#ifdef F_67
V_24 = F_37 ( 0 ) ;
F_46 ( V_24 , & V_92 ,
V_93 ) ;
F_47 ( V_24 , V_94 | V_95 ) ;
F_68 ( V_125 , F_31 ) ;
V_24 = F_37 ( 1 ) ;
F_46 ( V_24 , & V_92 ,
V_93 ) ;
F_47 ( V_24 , V_94 | V_95 ) ;
F_68 ( V_126 , F_31 ) ;
#endif
for ( V_24 = F_37 ( V_120 ) ;
V_24 <= F_37 ( V_36 ) ; V_24 ++ ) {
F_46 ( V_24 , & V_92 ,
V_93 ) ;
F_47 ( V_24 , V_94 | V_95 ) ;
}
}
F_68 ( V_119 , F_31 ) ;
return 0 ;
}
static int T_5 F_69 ( void )
{
return F_70 ( & V_127 ) ;
}
static int F_71 ( void )
{
struct V_3 * V_2 ;
int V_6 ;
F_34 (gpio, c) {
V_2 -> V_128 = F_9 ( V_2 -> V_5 + V_32 ) ;
V_2 -> V_129 = F_9 ( V_2 -> V_5 + V_18 ) ;
V_2 -> V_130 = F_9 ( V_2 -> V_5 + V_59 ) ;
V_2 -> V_131 = F_9 ( V_2 -> V_5 + V_61 ) ;
F_15 ( 0xffffffff , V_2 -> V_5 + V_76 ) ;
}
return 0 ;
}
static void F_72 ( void )
{
struct V_3 * V_2 ;
int V_6 ;
F_34 (gpio, c) {
F_15 ( V_2 -> V_128 , V_2 -> V_5 + V_30 ) ;
F_15 ( ~ V_2 -> V_128 , V_2 -> V_5 + V_31 ) ;
F_15 ( V_2 -> V_130 , V_2 -> V_5 + V_59 ) ;
F_15 ( V_2 -> V_131 , V_2 -> V_5 + V_61 ) ;
F_15 ( V_2 -> V_129 , V_2 -> V_5 + V_18 ) ;
}
}
static int T_5 F_73 ( void )
{
F_74 ( & V_132 ) ;
return 0 ;
}
