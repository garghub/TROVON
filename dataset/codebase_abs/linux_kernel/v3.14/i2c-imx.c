static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_5 ;
}
static inline void F_2 ( unsigned int V_6 ,
struct V_1 * V_2 , unsigned int V_7 )
{
F_3 ( V_6 , V_2 -> V_8 + ( V_7 << V_2 -> V_3 -> V_9 ) ) ;
}
static inline unsigned char F_4 ( struct V_1 * V_2 ,
unsigned int V_7 )
{
return F_5 ( V_2 -> V_8 + ( V_7 << V_2 -> V_3 -> V_9 ) ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_10 )
{
unsigned long V_11 = V_12 ;
unsigned int V_13 ;
F_7 ( & V_2 -> V_14 . V_15 , L_1 , V_16 ) ;
while ( 1 ) {
V_13 = F_4 ( V_2 , V_17 ) ;
if ( V_10 && ( V_13 & V_18 ) )
break;
if ( ! V_10 && ! ( V_13 & V_18 ) )
break;
if ( F_8 ( V_12 , V_11 + F_9 ( 500 ) ) ) {
F_7 ( & V_2 -> V_14 . V_15 ,
L_2 , V_16 ) ;
return - V_19 ;
}
F_10 () ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 -> V_20 , V_2 -> V_21 & V_22 , V_23 / 10 ) ;
if ( F_13 ( ! ( V_2 -> V_21 & V_22 ) ) ) {
F_7 ( & V_2 -> V_14 . V_15 , L_3 , V_16 ) ;
return - V_19 ;
}
F_7 ( & V_2 -> V_14 . V_15 , L_4 , V_16 ) ;
V_2 -> V_21 = 0 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 , V_17 ) & V_24 ) {
F_7 ( & V_2 -> V_14 . V_15 , L_5 , V_16 ) ;
return - V_25 ;
}
F_7 ( & V_2 -> V_14 . V_15 , L_6 , V_16 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
unsigned int V_13 = 0 ;
int V_26 ;
F_7 ( & V_2 -> V_14 . V_15 , L_1 , V_16 ) ;
V_26 = F_16 ( V_2 -> V_27 ) ;
if ( V_26 )
return V_26 ;
F_2 ( V_2 -> V_28 , V_2 , V_29 ) ;
F_2 ( V_2 -> V_3 -> V_30 , V_2 , V_17 ) ;
F_2 ( V_2 -> V_3 -> V_31 , V_2 , V_32 ) ;
F_17 ( 50 ) ;
V_13 = F_4 ( V_2 , V_32 ) ;
V_13 |= V_33 ;
F_2 ( V_13 , V_2 , V_32 ) ;
V_26 = F_6 ( V_2 , 1 ) ;
if ( V_26 )
return V_26 ;
V_2 -> V_34 = 0 ;
V_13 |= V_35 | V_36 | V_37 ;
F_2 ( V_13 , V_2 , V_32 ) ;
return V_26 ;
}
static void F_18 ( struct V_1 * V_2 )
{
unsigned int V_13 = 0 ;
if ( ! V_2 -> V_34 ) {
F_7 ( & V_2 -> V_14 . V_15 , L_1 , V_16 ) ;
V_13 = F_4 ( V_2 , V_32 ) ;
V_13 &= ~ ( V_33 | V_36 ) ;
F_2 ( V_13 , V_2 , V_32 ) ;
}
if ( F_1 ( V_2 ) ) {
F_17 ( V_2 -> V_38 ) ;
}
if ( ! V_2 -> V_34 ) {
F_6 ( V_2 , 0 ) ;
V_2 -> V_34 = 1 ;
}
V_13 = V_2 -> V_3 -> V_31 ^ V_39 ,
F_2 ( V_13 , V_2 , V_32 ) ;
F_19 ( V_2 -> V_27 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
unsigned int V_40 )
{
struct V_41 * V_42 = V_2 -> V_3 -> V_43 ;
unsigned int V_44 ;
unsigned int div ;
int V_45 ;
V_44 = F_21 ( V_2 -> V_27 ) ;
div = ( V_44 + V_40 - 1 ) / V_40 ;
if ( div < V_42 [ 0 ] . div )
V_45 = 0 ;
else if ( div > V_42 [ V_2 -> V_3 -> V_46 - 1 ] . div )
V_45 = V_2 -> V_3 -> V_46 - 1 ;
else
for ( V_45 = 0 ; V_42 [ V_45 ] . div < div ; V_45 ++ ) ;
V_2 -> V_28 = V_42 [ V_45 ] . V_6 ;
V_2 -> V_38 = ( 500000U * V_42 [ V_45 ] . div
+ ( V_44 / 2 ) - 1 ) / ( V_44 / 2 ) ;
#ifdef F_22
F_7 ( & V_2 -> V_14 . V_15 , L_7 ,
V_16 , V_44 , div ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_8 ,
V_16 , V_42 [ V_45 ] . V_6 , V_42 [ V_45 ] . div ) ;
#endif
}
static T_1 F_23 ( int V_47 , void * V_48 )
{
struct V_1 * V_2 = V_48 ;
unsigned int V_13 ;
V_13 = F_4 ( V_2 , V_17 ) ;
if ( V_13 & V_22 ) {
V_2 -> V_21 = V_13 ;
V_13 &= ~ V_22 ;
V_13 |= ( V_2 -> V_3 -> V_30 & V_22 ) ;
F_2 ( V_13 , V_2 , V_17 ) ;
F_24 ( & V_2 -> V_20 ) ;
return V_49 ;
}
return V_50 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
int V_45 , V_26 ;
F_7 ( & V_2 -> V_14 . V_15 , L_9 ,
V_16 , V_52 -> V_53 << 1 ) ;
F_2 ( V_52 -> V_53 << 1 , V_2 , V_54 ) ;
V_26 = F_11 ( V_2 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_14 ( V_2 ) ;
if ( V_26 )
return V_26 ;
F_7 ( & V_2 -> V_14 . V_15 , L_10 , V_16 ) ;
for ( V_45 = 0 ; V_45 < V_52 -> V_55 ; V_45 ++ ) {
F_7 ( & V_2 -> V_14 . V_15 ,
L_11 ,
V_16 , V_45 , V_52 -> V_56 [ V_45 ] ) ;
F_2 ( V_52 -> V_56 [ V_45 ] , V_2 , V_54 ) ;
V_26 = F_11 ( V_2 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_14 ( V_2 ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
int V_45 , V_26 ;
unsigned int V_13 ;
F_7 ( & V_2 -> V_14 . V_15 ,
L_9 ,
V_16 , ( V_52 -> V_53 << 1 ) | 0x01 ) ;
F_2 ( ( V_52 -> V_53 << 1 ) | 0x01 , V_2 , V_54 ) ;
V_26 = F_11 ( V_2 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_14 ( V_2 ) ;
if ( V_26 )
return V_26 ;
F_7 ( & V_2 -> V_14 . V_15 , L_12 , V_16 ) ;
V_13 = F_4 ( V_2 , V_32 ) ;
V_13 &= ~ V_36 ;
if ( V_52 -> V_55 - 1 )
V_13 &= ~ V_37 ;
F_2 ( V_13 , V_2 , V_32 ) ;
F_4 ( V_2 , V_54 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_13 , V_16 ) ;
for ( V_45 = 0 ; V_45 < V_52 -> V_55 ; V_45 ++ ) {
V_26 = F_11 ( V_2 ) ;
if ( V_26 )
return V_26 ;
if ( V_45 == ( V_52 -> V_55 - 1 ) ) {
F_7 ( & V_2 -> V_14 . V_15 ,
L_14 , V_16 ) ;
V_13 = F_4 ( V_2 , V_32 ) ;
V_13 &= ~ ( V_33 | V_36 ) ;
F_2 ( V_13 , V_2 , V_32 ) ;
F_6 ( V_2 , 0 ) ;
V_2 -> V_34 = 1 ;
} else if ( V_45 == ( V_52 -> V_55 - 2 ) ) {
F_7 ( & V_2 -> V_14 . V_15 ,
L_15 , V_16 ) ;
V_13 = F_4 ( V_2 , V_32 ) ;
V_13 |= V_37 ;
F_2 ( V_13 , V_2 , V_32 ) ;
}
V_52 -> V_56 [ V_45 ] = F_4 ( V_2 , V_54 ) ;
F_7 ( & V_2 -> V_14 . V_15 ,
L_16 ,
V_16 , V_45 , V_52 -> V_56 [ V_45 ] ) ;
}
return 0 ;
}
static int F_27 ( struct V_57 * V_14 ,
struct V_51 * V_52 , int V_58 )
{
unsigned int V_45 , V_13 ;
int V_26 ;
struct V_1 * V_2 = F_28 ( V_14 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_1 , V_16 ) ;
V_26 = F_15 ( V_2 ) ;
if ( V_26 )
goto V_59;
for ( V_45 = 0 ; V_45 < V_58 ; V_45 ++ ) {
if ( V_45 ) {
F_7 ( & V_2 -> V_14 . V_15 ,
L_17 , V_16 ) ;
V_13 = F_4 ( V_2 , V_32 ) ;
V_13 |= V_60 ;
F_2 ( V_13 , V_2 , V_32 ) ;
V_26 = F_6 ( V_2 , 1 ) ;
if ( V_26 )
goto V_59;
}
F_7 ( & V_2 -> V_14 . V_15 ,
L_18 , V_16 , V_45 ) ;
#ifdef F_22
V_13 = F_4 ( V_2 , V_32 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_19
L_20 , V_16 ,
( V_13 & V_39 ? 1 : 0 ) , ( V_13 & V_35 ? 1 : 0 ) ,
( V_13 & V_33 ? 1 : 0 ) , ( V_13 & V_36 ? 1 : 0 ) ,
( V_13 & V_37 ? 1 : 0 ) , ( V_13 & V_60 ? 1 : 0 ) ) ;
V_13 = F_4 ( V_2 , V_17 ) ;
F_7 ( & V_2 -> V_14 . V_15 ,
L_21
L_22 , V_16 ,
( V_13 & V_61 ? 1 : 0 ) , ( V_13 & V_62 ? 1 : 0 ) ,
( V_13 & V_18 ? 1 : 0 ) , ( V_13 & V_63 ? 1 : 0 ) ,
( V_13 & V_64 ? 1 : 0 ) , ( V_13 & V_22 ? 1 : 0 ) ,
( V_13 & V_24 ? 1 : 0 ) ) ;
#endif
if ( V_52 [ V_45 ] . V_65 & V_66 )
V_26 = F_26 ( V_2 , & V_52 [ V_45 ] ) ;
else
V_26 = F_25 ( V_2 , & V_52 [ V_45 ] ) ;
if ( V_26 )
goto V_59;
}
V_59:
F_18 ( V_2 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_23 , V_16 ,
( V_26 < 0 ) ? L_24 : L_25 ,
( V_26 < 0 ) ? V_26 : V_58 ) ;
return ( V_26 < 0 ) ? V_26 : V_58 ;
}
static T_2 F_29 ( struct V_57 * V_14 )
{
return V_67 | V_68 ;
}
static int F_30 ( struct V_69 * V_70 )
{
const struct V_71 * V_72 = F_31 ( V_73 ,
& V_70 -> V_15 ) ;
struct V_1 * V_2 ;
struct V_74 * V_75 ;
struct V_76 * V_77 = F_32 ( & V_70 -> V_15 ) ;
void T_3 * V_8 ;
int V_47 , V_78 ;
T_2 V_79 ;
F_7 ( & V_70 -> V_15 , L_1 , V_16 ) ;
V_47 = F_33 ( V_70 , 0 ) ;
if ( V_47 < 0 ) {
F_34 ( & V_70 -> V_15 , L_26 ) ;
return V_47 ;
}
V_75 = F_35 ( V_70 , V_80 , 0 ) ;
V_8 = F_36 ( & V_70 -> V_15 , V_75 ) ;
if ( F_37 ( V_8 ) )
return F_38 ( V_8 ) ;
V_2 = F_39 ( & V_70 -> V_15 , sizeof( struct V_1 ) ,
V_81 ) ;
if ( ! V_2 ) {
F_34 ( & V_70 -> V_15 , L_27 ) ;
return - V_82 ;
}
if ( V_72 )
V_2 -> V_3 = V_72 -> V_83 ;
else
V_2 -> V_3 = (struct V_84 * )
F_40 ( V_70 ) -> V_85 ;
F_41 ( V_2 -> V_14 . V_86 , V_70 -> V_86 , sizeof( V_2 -> V_14 . V_86 ) ) ;
V_2 -> V_14 . V_87 = V_88 ;
V_2 -> V_14 . V_89 = & V_90 ;
V_2 -> V_14 . V_15 . V_91 = & V_70 -> V_15 ;
V_2 -> V_14 . V_92 = V_70 -> V_93 ;
V_2 -> V_14 . V_15 . V_94 = V_70 -> V_15 . V_94 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_27 = F_42 ( & V_70 -> V_15 , NULL ) ;
if ( F_37 ( V_2 -> V_27 ) ) {
F_34 ( & V_70 -> V_15 , L_28 ) ;
return F_38 ( V_2 -> V_27 ) ;
}
V_78 = F_16 ( V_2 -> V_27 ) ;
if ( V_78 ) {
F_34 ( & V_70 -> V_15 , L_29 ) ;
return V_78 ;
}
V_78 = F_43 ( & V_70 -> V_15 , V_47 , F_23 , 0 ,
V_70 -> V_86 , V_2 ) ;
if ( V_78 ) {
F_34 ( & V_70 -> V_15 , L_30 , V_47 ) ;
return V_78 ;
}
F_44 ( & V_2 -> V_20 ) ;
F_45 ( & V_2 -> V_14 , V_2 ) ;
V_79 = V_95 ;
V_78 = F_46 ( V_70 -> V_15 . V_94 ,
L_31 , & V_79 ) ;
if ( V_78 < 0 && V_77 && V_77 -> V_79 )
V_79 = V_77 -> V_79 ;
F_20 ( V_2 , V_79 ) ;
F_2 ( V_2 -> V_3 -> V_31 ^ V_39 ,
V_2 , V_32 ) ;
F_2 ( V_2 -> V_3 -> V_30 , V_2 , V_17 ) ;
V_78 = F_47 ( & V_2 -> V_14 ) ;
if ( V_78 < 0 ) {
F_34 ( & V_70 -> V_15 , L_32 ) ;
return V_78 ;
}
F_48 ( V_70 , V_2 ) ;
F_19 ( V_2 -> V_27 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_33 , V_47 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_34 ,
V_75 -> V_96 , V_75 -> V_97 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_35 ,
F_49 ( V_75 ) , V_75 -> V_96 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_36 ,
V_2 -> V_14 . V_86 ) ;
F_50 ( & V_2 -> V_14 . V_15 , L_37 ) ;
return 0 ;
}
static int F_51 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_52 ( V_70 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_38 ) ;
F_53 ( & V_2 -> V_14 ) ;
F_2 ( 0 , V_2 , V_98 ) ;
F_2 ( 0 , V_2 , V_29 ) ;
F_2 ( 0 , V_2 , V_32 ) ;
F_2 ( 0 , V_2 , V_17 ) ;
return 0 ;
}
static int T_4 F_54 ( void )
{
return F_55 ( & V_99 ) ;
}
static void T_5 F_56 ( void )
{
F_57 ( & V_99 ) ;
}
