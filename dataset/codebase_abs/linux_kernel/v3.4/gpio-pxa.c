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
static int T_3 F_26 ( int V_32 ,
int (* F_27)( unsigned int , unsigned int ) )
{
int V_33 , V_6 , V_34 = F_4 ( V_32 ) + 1 ;
struct V_3 * V_35 ;
V_35 = F_28 ( V_34 * sizeof( struct V_3 ) , V_36 ) ;
if ( V_35 == NULL ) {
F_29 ( L_1 , V_37 ) ;
return - V_38 ;
}
for ( V_33 = 0 , V_6 = 0 ; V_33 < V_34 ; V_33 ++ , V_6 += 32 ) {
struct V_1 * V_2 = & V_35 [ V_33 ] . V_4 ;
sprintf ( V_35 [ V_33 ] . V_39 , L_2 , V_33 ) ;
V_35 [ V_33 ] . V_5 = V_40 + F_30 ( V_33 ) ;
V_35 [ V_33 ] . F_27 = F_27 ;
V_2 -> V_12 = V_6 ;
V_2 -> V_39 = V_35 [ V_33 ] . V_39 ;
V_2 -> V_41 = F_19 ;
V_2 -> V_42 = F_23 ;
V_2 -> V_43 = F_24 ;
V_2 -> V_44 = F_25 ;
V_2 -> V_45 = F_17 ;
V_2 -> V_46 = ( V_6 + 31 > V_32 ) ? ( V_32 - V_6 + 1 ) : 32 ;
F_31 ( V_2 ) ;
}
V_7 = V_35 ;
return 0 ;
}
static inline void F_32 ( struct V_3 * V_2 )
{
T_2 V_47 , V_48 ;
V_47 = F_9 ( V_2 -> V_5 + V_49 ) & ~ V_2 -> V_50 ;
V_48 = F_9 ( V_2 -> V_5 + V_51 ) & ~ V_2 -> V_50 ;
V_47 |= V_2 -> V_52 & V_2 -> V_50 ;
V_48 |= V_2 -> V_53 & V_2 -> V_50 ;
F_21 ( V_47 , V_2 -> V_5 + V_49 ) ;
F_21 ( V_48 , V_2 -> V_5 + V_51 ) ;
}
static int F_33 ( struct V_54 * V_55 , unsigned int type )
{
struct V_3 * V_2 ;
int V_6 = F_18 ( V_55 -> V_22 ) ;
unsigned long V_14 , V_25 = F_10 ( V_6 ) ;
V_2 = F_3 ( V_6 ) ;
if ( type == V_56 ) {
if ( ( V_2 -> V_52 | V_2 -> V_53 ) & F_10 ( V_6 ) )
return 0 ;
if ( F_8 ( V_6 ) )
return 0 ;
type = V_57 | V_58 ;
}
V_14 = F_9 ( V_2 -> V_5 + V_18 ) ;
if ( F_7 ( V_6 ) )
F_21 ( V_14 | V_25 , V_2 -> V_5 + V_18 ) ;
else
F_21 ( V_14 & ~ V_25 , V_2 -> V_5 + V_18 ) ;
if ( type & V_57 )
V_2 -> V_52 |= V_25 ;
else
V_2 -> V_52 &= ~ V_25 ;
if ( type & V_58 )
V_2 -> V_53 |= V_25 ;
else
V_2 -> V_53 &= ~ V_25 ;
F_32 ( V_2 ) ;
F_34 ( L_3 , V_37 , V_55 -> V_22 , V_6 ,
( ( type & V_57 ) ? L_4 : L_5 ) ,
( ( type & V_58 ) ? L_6 : L_5 ) ) ;
return 0 ;
}
static void F_35 ( unsigned int V_22 , struct V_59 * V_60 )
{
struct V_3 * V_2 ;
int V_61 , V_6 , V_62 , V_63 ;
unsigned long V_64 ;
do {
V_61 = 0 ;
F_36 (gpio, c) {
V_62 = V_2 -> V_4 . V_12 ;
V_64 = F_9 ( V_2 -> V_5 + V_65 ) ;
V_64 = V_64 & V_2 -> V_50 ;
F_21 ( V_64 , V_2 -> V_5 + V_65 ) ;
V_63 = F_37 ( & V_64 , V_66 ) ;
while ( V_63 < V_66 ) {
V_61 = 1 ;
F_38 ( F_39 ( V_62 + V_63 ) ) ;
V_63 = F_40 ( & V_64 , V_66 , V_63 + 1 ) ;
}
}
} while ( V_61 );
}
static void F_41 ( struct V_54 * V_55 )
{
int V_6 = F_18 ( V_55 -> V_22 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
F_21 ( F_10 ( V_6 ) , V_2 -> V_5 + V_65 ) ;
}
static void F_42 ( struct V_54 * V_55 )
{
int V_6 = F_18 ( V_55 -> V_22 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
T_2 V_47 , V_48 ;
V_2 -> V_50 &= ~ F_10 ( V_6 ) ;
V_47 = F_9 ( V_2 -> V_5 + V_49 ) & ~ F_10 ( V_6 ) ;
V_48 = F_9 ( V_2 -> V_5 + V_51 ) & ~ F_10 ( V_6 ) ;
F_21 ( V_47 , V_2 -> V_5 + V_49 ) ;
F_21 ( V_48 , V_2 -> V_5 + V_51 ) ;
}
static int F_43 ( struct V_54 * V_55 , unsigned int V_67 )
{
int V_6 = F_18 ( V_55 -> V_22 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
if ( V_2 -> F_27 )
return V_2 -> F_27 ( V_6 , V_67 ) ;
else
return 0 ;
}
static void F_44 ( struct V_54 * V_55 )
{
int V_6 = F_18 ( V_55 -> V_22 ) ;
struct V_3 * V_2 = F_3 ( V_6 ) ;
V_2 -> V_50 |= F_10 ( V_6 ) ;
F_32 ( V_2 ) ;
}
static int F_45 ( void )
{
int V_68 = 0 ;
#ifdef F_46
if ( F_47 () ) {
#ifdef F_48
V_68 = 89 ;
V_9 = V_10 ;
#elif F_49 ( V_69 )
V_68 = 84 ;
V_9 = V_10 ;
#endif
} else if ( F_50 () ) {
V_68 = 120 ;
V_9 = V_20 ;
} else if ( F_51 () || F_52 () ) {
V_68 = 191 ;
V_9 = V_70 ;
} else if ( F_53 () ) {
V_68 = 127 ;
V_9 = V_71 ;
}
#endif
#ifdef F_54
if ( F_55 () || F_56 () ) {
V_68 = 127 ;
V_9 = V_8 ;
} else if ( F_57 () ) {
V_68 = 191 ;
V_9 = V_72 ;
}
#endif
return V_68 ;
}
static int T_3 F_58 ( struct V_73 * V_74 )
{
struct V_3 * V_2 ;
struct V_75 * V_76 ;
struct V_77 * V_77 ;
struct V_78 * V_79 ;
int V_6 , V_22 , V_15 ;
int V_80 = 0 , V_81 = 0 , V_82 , V_83 = 0 ;
V_84 = F_45 () ;
if ( ! V_84 )
return - V_85 ;
V_80 = F_59 ( V_74 , L_7 ) ;
V_81 = F_59 ( V_74 , L_8 ) ;
V_82 = F_59 ( V_74 , L_9 ) ;
if ( ( V_80 > 0 && V_81 <= 0 ) || ( V_80 <= 0 && V_81 > 0 )
|| ( V_82 <= 0 ) )
return - V_85 ;
V_76 = F_60 ( V_74 , V_86 , 0 ) ;
if ( ! V_76 )
return - V_85 ;
V_40 = F_61 ( V_76 -> V_87 , F_62 ( V_76 ) ) ;
if ( ! V_40 )
return - V_85 ;
if ( V_80 > 0 )
V_83 = 2 ;
V_77 = F_63 ( & V_74 -> V_88 , NULL ) ;
if ( F_64 ( V_77 ) ) {
F_65 ( & V_74 -> V_88 , L_10 ,
F_66 ( V_77 ) ) ;
F_67 ( V_40 ) ;
return F_66 ( V_77 ) ;
}
V_15 = F_68 ( V_77 ) ;
if ( V_15 ) {
F_69 ( V_77 ) ;
F_67 ( V_40 ) ;
return V_15 ;
}
V_15 = F_70 ( V_77 ) ;
if ( V_15 ) {
F_71 ( V_77 ) ;
F_69 ( V_77 ) ;
F_67 ( V_40 ) ;
return V_15 ;
}
V_79 = F_72 ( & V_74 -> V_88 ) ;
F_26 ( V_84 , V_79 ? V_79 -> V_89 : NULL ) ;
F_36 (gpio, c) {
F_21 ( 0 , V_2 -> V_5 + V_51 ) ;
F_21 ( 0 , V_2 -> V_5 + V_49 ) ;
F_21 ( ~ 0 , V_2 -> V_5 + V_65 ) ;
if ( F_6 ( V_9 ) )
F_21 ( ~ 0 , V_2 -> V_5 + V_90 ) ;
}
#ifdef F_46
V_22 = F_39 ( 0 ) ;
F_73 ( V_22 , & V_91 ,
V_92 ) ;
F_74 ( V_22 , V_93 | V_94 ) ;
F_75 ( V_95 , F_35 ) ;
V_22 = F_39 ( 1 ) ;
F_73 ( V_22 , & V_91 ,
V_92 ) ;
F_74 ( V_22 , V_93 | V_94 ) ;
F_75 ( V_96 , F_35 ) ;
#endif
for ( V_22 = F_39 ( V_83 ) ;
V_22 <= F_39 ( V_84 ) ; V_22 ++ ) {
F_73 ( V_22 , & V_91 ,
V_92 ) ;
F_74 ( V_22 , V_93 | V_94 ) ;
}
F_75 ( V_82 , F_35 ) ;
return 0 ;
}
static int T_4 F_76 ( void )
{
return F_77 ( & V_97 ) ;
}
static int F_78 ( void )
{
struct V_3 * V_2 ;
int V_6 ;
F_36 (gpio, c) {
V_2 -> V_98 = F_9 ( V_2 -> V_5 + V_31 ) ;
V_2 -> V_99 = F_9 ( V_2 -> V_5 + V_18 ) ;
V_2 -> V_100 = F_9 ( V_2 -> V_5 + V_49 ) ;
V_2 -> V_101 = F_9 ( V_2 -> V_5 + V_51 ) ;
F_21 ( 0xffffffff , V_2 -> V_5 + V_65 ) ;
}
return 0 ;
}
static void F_79 ( void )
{
struct V_3 * V_2 ;
int V_6 ;
F_36 (gpio, c) {
F_21 ( V_2 -> V_98 , V_2 -> V_5 + V_29 ) ;
F_21 ( ~ V_2 -> V_98 , V_2 -> V_5 + V_30 ) ;
F_21 ( V_2 -> V_100 , V_2 -> V_5 + V_49 ) ;
F_21 ( V_2 -> V_101 , V_2 -> V_5 + V_51 ) ;
F_21 ( V_2 -> V_99 , V_2 -> V_5 + V_18 ) ;
}
}
static int T_4 F_80 ( void )
{
F_81 ( & V_102 ) ;
return 0 ;
}
