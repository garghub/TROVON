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
T_3 V_32 = F_9 ( F_1 ( V_4 ) + V_33 ) ;
return ! ! ( V_32 & ( 1 << V_22 ) ) ;
}
static void F_19 ( struct V_1 * V_4 , unsigned V_22 , int V_25 )
{
F_15 ( 1 << V_22 , F_1 ( V_4 ) +
( V_25 ? V_30 : V_31 ) ) ;
}
static int F_20 ( struct V_1 * V_34 ,
const struct V_35 * V_36 ,
T_3 * V_27 )
{
if ( V_36 -> args [ 0 ] > V_37 )
return - V_38 ;
if ( V_34 != & V_7 [ V_36 -> args [ 0 ] / 32 ] . V_4 )
return - V_38 ;
if ( V_27 )
* V_27 = V_36 -> args [ 1 ] ;
return V_36 -> args [ 0 ] % 32 ;
}
static int F_21 ( int V_39 ,
int (* F_22)( unsigned int , unsigned int ) )
{
int V_40 , V_6 , V_41 = F_4 ( V_39 ) + 1 ;
struct V_3 * V_42 ;
V_42 = F_23 ( V_41 * sizeof( struct V_3 ) , V_43 ) ;
if ( V_42 == NULL ) {
F_24 ( L_1 , V_44 ) ;
return - V_45 ;
}
for ( V_40 = 0 , V_6 = 0 ; V_40 < V_41 ; V_40 ++ , V_6 += 32 ) {
struct V_1 * V_2 = & V_42 [ V_40 ] . V_4 ;
sprintf ( V_42 [ V_40 ] . V_46 , L_2 , V_40 ) ;
V_42 [ V_40 ] . V_5 = V_47 + F_25 ( V_40 ) ;
V_42 [ V_40 ] . F_22 = F_22 ;
V_2 -> V_12 = V_6 ;
V_2 -> V_46 = V_42 [ V_40 ] . V_46 ;
V_2 -> V_48 = F_13 ;
V_2 -> V_49 = F_17 ;
V_2 -> V_50 = F_18 ;
V_2 -> V_51 = F_19 ;
V_2 -> V_52 = F_11 ;
#ifdef F_26
V_2 -> V_53 = V_54 ;
V_2 -> V_55 = F_20 ;
V_2 -> V_56 = 2 ;
#endif
V_2 -> V_57 = ( V_6 + 31 > V_39 ) ? ( V_39 - V_6 + 1 ) : 32 ;
F_27 ( V_2 ) ;
}
V_7 = V_42 ;
return 0 ;
}
static inline void F_28 ( struct V_3 * V_2 )
{
T_2 V_58 , V_59 ;
V_58 = F_9 ( V_2 -> V_5 + V_60 ) & ~ V_2 -> V_61 ;
V_59 = F_9 ( V_2 -> V_5 + V_62 ) & ~ V_2 -> V_61 ;
V_58 |= V_2 -> V_63 & V_2 -> V_61 ;
V_59 |= V_2 -> V_64 & V_2 -> V_61 ;
F_15 ( V_58 , V_2 -> V_5 + V_60 ) ;
F_15 ( V_59 , V_2 -> V_5 + V_62 ) ;
}
static int F_29 ( struct V_65 * V_66 , unsigned int type )
{
struct V_3 * V_2 ;
int V_6 = F_12 ( V_66 -> V_24 ) ;
unsigned long V_14 , V_26 = F_10 ( V_6 ) ;
V_2 = F_3 ( V_6 ) ;
if ( type == V_67 ) {
if ( ( V_2 -> V_63 | V_2 -> V_64 ) & F_10 ( V_6 ) )
return 0 ;
if ( F_8 ( V_6 ) )
return 0 ;
type = V_68 | V_69 ;
}
V_14 = F_9 ( V_2 -> V_5 + V_18 ) ;
if ( F_7 ( V_6 ) )
F_15 ( V_14 | V_26 , V_2 -> V_5 + V_18 ) ;
else
F_15 ( V_14 & ~ V_26 , V_2 -> V_5 + V_18 ) ;
if ( type & V_68 )
V_2 -> V_63 |= V_26 ;
else
V_2 -> V_63 &= ~ V_26 ;
if ( type & V_69 )
V_2 -> V_64 |= V_26 ;
else
V_2 -> V_64 &= ~ V_26 ;
F_28 ( V_2 ) ;
F_30 ( L_3 , V_44 , V_66 -> V_24 , V_6 ,
( ( type & V_68 ) ? L_4 : L_5 ) ,
( ( type & V_69 ) ? L_6 : L_5 ) ) ;
return 0 ;
}
static void F_31 ( unsigned int V_24 , struct V_70 * V_71 )
{
struct V_3 * V_2 ;
int V_72 , V_6 , V_73 , V_74 ;
unsigned long V_75 ;
struct V_76 * V_4 = F_32 ( V_71 ) ;
F_33 ( V_4 , V_71 ) ;
do {
V_72 = 0 ;
F_34 (gpio, c) {
V_73 = V_2 -> V_4 . V_12 ;
V_75 = F_9 ( V_2 -> V_5 + V_77 ) ;
V_75 = V_75 & V_2 -> V_61 ;
F_15 ( V_75 , V_2 -> V_5 + V_77 ) ;
F_35 (n, &gedr, BITS_PER_LONG) {
V_72 = 1 ;
F_36 ( F_37 ( V_73 + V_74 ) ) ;
}
}
} while ( V_72 );
F_38 ( V_4 , V_71 ) ;
}
static void F_39 ( struct V_65 * V_66 )
{
int V_6 = F_12 ( V_66 -> V_24 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
F_15 ( F_10 ( V_6 ) , V_2 -> V_5 + V_77 ) ;
}
static void F_40 ( struct V_65 * V_66 )
{
int V_6 = F_12 ( V_66 -> V_24 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
T_2 V_58 , V_59 ;
V_2 -> V_61 &= ~ F_10 ( V_6 ) ;
V_58 = F_9 ( V_2 -> V_5 + V_60 ) & ~ F_10 ( V_6 ) ;
V_59 = F_9 ( V_2 -> V_5 + V_62 ) & ~ F_10 ( V_6 ) ;
F_15 ( V_58 , V_2 -> V_5 + V_60 ) ;
F_15 ( V_59 , V_2 -> V_5 + V_62 ) ;
}
static int F_41 ( struct V_65 * V_66 , unsigned int V_78 )
{
int V_6 = F_12 ( V_66 -> V_24 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
if ( V_2 -> F_22 )
return V_2 -> F_22 ( V_6 , V_78 ) ;
else
return 0 ;
}
static void F_42 ( struct V_65 * V_66 )
{
int V_6 = F_12 ( V_66 -> V_24 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
V_2 -> V_61 |= F_10 ( V_6 ) ;
F_28 ( V_2 ) ;
}
static int F_43 ( struct V_79 * V_80 )
{
const struct V_81 * V_82 = F_44 ( V_80 ) ;
struct V_83 * V_84 = (struct V_83 * ) V_82 -> V_85 ;
int V_86 = 0 ;
switch ( V_84 -> type ) {
case V_19 :
case V_10 :
case V_20 :
case V_87 :
case V_88 :
case V_8 :
case V_89 :
case V_90 :
V_9 = V_84 -> type ;
V_86 = V_84 -> V_91 - 1 ;
break;
default:
V_86 = - V_38 ;
break;
}
return V_86 ;
}
static int F_45 ( struct V_92 * V_66 , unsigned int V_24 ,
T_4 V_93 )
{
F_46 ( V_24 , & V_94 ,
V_95 ) ;
F_47 ( V_24 , V_96 | V_97 ) ;
return 0 ;
}
static int F_48 ( struct V_79 * V_80 )
{
int V_15 = 0 , V_98 ;
struct V_99 * V_100 = V_80 -> V_101 . V_53 ;
const struct V_102 * V_103 =
F_49 ( V_104 , & V_80 -> V_101 ) ;
const struct V_83 * V_105 ;
if ( ! V_103 || ! V_103 -> V_106 ) {
F_50 ( & V_80 -> V_101 , L_7 ) ;
return - V_107 ;
}
V_105 = V_103 -> V_106 ;
V_9 = V_105 -> type ;
V_98 = V_105 -> V_91 ;
V_37 = V_98 - 1 ;
V_23 = F_51 ( - 1 , 0 , V_98 , 0 ) ;
if ( V_23 < 0 ) {
F_50 ( & V_80 -> V_101 , L_8 ) ;
V_15 = V_23 ;
goto V_108;
}
V_109 = F_52 ( V_100 , V_98 , V_23 , 0 ,
& V_110 , NULL ) ;
V_54 = V_100 ;
return 0 ;
V_108:
F_53 ( V_47 ) ;
return V_15 ;
}
static int F_54 ( struct V_79 * V_80 )
{
struct V_3 * V_2 ;
struct V_111 * V_112 ;
struct V_113 * V_113 ;
struct V_114 * V_115 ;
int V_6 , V_24 , V_15 , V_116 = 0 ;
int V_117 = 0 , V_118 = 0 , V_119 , V_120 = 0 ;
V_115 = F_55 ( & V_80 -> V_101 ) ;
if ( V_115 ) {
V_23 = V_115 -> V_23 ;
if ( V_23 <= 0 )
return - V_38 ;
V_37 = F_43 ( V_80 ) ;
} else {
V_23 = 0 ;
V_116 = 1 ;
V_15 = F_48 ( V_80 ) ;
if ( V_15 < 0 )
return - V_38 ;
}
if ( ! V_37 )
return - V_38 ;
V_117 = F_56 ( V_80 , L_9 ) ;
V_118 = F_56 ( V_80 , L_10 ) ;
V_119 = F_56 ( V_80 , L_11 ) ;
if ( ( V_117 > 0 && V_118 <= 0 ) || ( V_117 <= 0 && V_118 > 0 )
|| ( V_119 <= 0 ) )
return - V_38 ;
V_112 = F_57 ( V_80 , V_121 , 0 ) ;
if ( ! V_112 )
return - V_38 ;
V_47 = F_58 ( V_112 -> V_122 , F_59 ( V_112 ) ) ;
if ( ! V_47 )
return - V_38 ;
if ( V_117 > 0 )
V_120 = 2 ;
V_113 = F_60 ( & V_80 -> V_101 , NULL ) ;
if ( F_61 ( V_113 ) ) {
F_50 ( & V_80 -> V_101 , L_12 ,
F_62 ( V_113 ) ) ;
F_53 ( V_47 ) ;
return F_62 ( V_113 ) ;
}
V_15 = F_63 ( V_113 ) ;
if ( V_15 ) {
F_64 ( V_113 ) ;
F_53 ( V_47 ) ;
return V_15 ;
}
F_21 ( V_37 , V_115 ? V_115 -> V_123 : NULL ) ;
F_34 (gpio, c) {
F_15 ( 0 , V_2 -> V_5 + V_62 ) ;
F_15 ( 0 , V_2 -> V_5 + V_60 ) ;
F_15 ( ~ 0 , V_2 -> V_5 + V_77 ) ;
if ( F_6 ( V_9 ) )
F_15 ( ~ 0 , V_2 -> V_5 + V_124 ) ;
}
if ( ! V_116 ) {
if ( V_117 > 0 ) {
V_24 = F_37 ( 0 ) ;
F_46 ( V_24 , & V_94 ,
V_95 ) ;
F_47 ( V_24 , V_96 | V_97 ) ;
}
if ( V_118 > 0 ) {
V_24 = F_37 ( 1 ) ;
F_46 ( V_24 , & V_94 ,
V_95 ) ;
F_47 ( V_24 , V_96 | V_97 ) ;
}
for ( V_24 = F_37 ( V_120 ) ;
V_24 <= F_37 ( V_37 ) ; V_24 ++ ) {
F_46 ( V_24 , & V_94 ,
V_95 ) ;
F_47 ( V_24 , V_96 | V_97 ) ;
}
}
if ( V_117 > 0 )
F_65 ( V_117 , F_31 ) ;
if ( V_118 > 0 )
F_65 ( V_118 , F_31 ) ;
F_65 ( V_119 , F_31 ) ;
return 0 ;
}
static int T_5 F_66 ( void )
{
return F_67 ( & V_125 ) ;
}
static int F_68 ( void )
{
struct V_3 * V_2 ;
int V_6 ;
F_34 (gpio, c) {
V_2 -> V_126 = F_9 ( V_2 -> V_5 + V_33 ) ;
V_2 -> V_127 = F_9 ( V_2 -> V_5 + V_18 ) ;
V_2 -> V_128 = F_9 ( V_2 -> V_5 + V_60 ) ;
V_2 -> V_129 = F_9 ( V_2 -> V_5 + V_62 ) ;
F_15 ( 0xffffffff , V_2 -> V_5 + V_77 ) ;
}
return 0 ;
}
static void F_69 ( void )
{
struct V_3 * V_2 ;
int V_6 ;
F_34 (gpio, c) {
F_15 ( V_2 -> V_126 , V_2 -> V_5 + V_30 ) ;
F_15 ( ~ V_2 -> V_126 , V_2 -> V_5 + V_31 ) ;
F_15 ( V_2 -> V_128 , V_2 -> V_5 + V_60 ) ;
F_15 ( V_2 -> V_129 , V_2 -> V_5 + V_62 ) ;
F_15 ( V_2 -> V_127 , V_2 -> V_5 + V_18 ) ;
}
}
static int T_5 F_70 ( void )
{
F_71 ( & V_130 ) ;
return 0 ;
}
