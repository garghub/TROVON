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
static void F_15 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_3 -> V_28 ;
unsigned int V_29 ;
unsigned int div ;
int V_30 ;
V_29 = F_16 ( V_2 -> V_31 ) ;
if ( V_2 -> V_32 == V_29 )
return;
else
V_2 -> V_32 = V_29 ;
div = ( V_29 + V_2 -> V_33 - 1 ) / V_2 -> V_33 ;
if ( div < V_27 [ 0 ] . div )
V_30 = 0 ;
else if ( div > V_27 [ V_2 -> V_3 -> V_34 - 1 ] . div )
V_30 = V_2 -> V_3 -> V_34 - 1 ;
else
for ( V_30 = 0 ; V_27 [ V_30 ] . div < div ; V_30 ++ ) ;
V_2 -> V_35 = V_27 [ V_30 ] . V_6 ;
V_2 -> V_36 = ( 500000U * V_27 [ V_30 ] . div
+ ( V_29 / 2 ) - 1 ) / ( V_29 / 2 ) ;
#ifdef F_17
F_7 ( & V_2 -> V_14 . V_15 , L_7 ,
V_29 , div ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_8 ,
V_27 [ V_30 ] . V_6 , V_27 [ V_30 ] . div ) ;
#endif
}
static int F_18 ( struct V_1 * V_2 )
{
unsigned int V_13 = 0 ;
int V_37 ;
F_7 ( & V_2 -> V_14 . V_15 , L_1 , V_16 ) ;
F_15 ( V_2 ) ;
V_37 = F_19 ( V_2 -> V_31 ) ;
if ( V_37 )
return V_37 ;
F_2 ( V_2 -> V_35 , V_2 , V_38 ) ;
F_2 ( V_2 -> V_3 -> V_39 , V_2 , V_17 ) ;
F_2 ( V_2 -> V_3 -> V_40 , V_2 , V_41 ) ;
F_20 ( 50 ) ;
V_13 = F_4 ( V_2 , V_41 ) ;
V_13 |= V_42 ;
F_2 ( V_13 , V_2 , V_41 ) ;
V_37 = F_6 ( V_2 , 1 ) ;
if ( V_37 )
return V_37 ;
V_2 -> V_43 = 0 ;
V_13 |= V_44 | V_45 | V_46 ;
F_2 ( V_13 , V_2 , V_41 ) ;
return V_37 ;
}
static void F_21 ( struct V_1 * V_2 )
{
unsigned int V_13 = 0 ;
if ( ! V_2 -> V_43 ) {
F_7 ( & V_2 -> V_14 . V_15 , L_1 , V_16 ) ;
V_13 = F_4 ( V_2 , V_41 ) ;
V_13 &= ~ ( V_42 | V_45 ) ;
F_2 ( V_13 , V_2 , V_41 ) ;
}
if ( F_1 ( V_2 ) ) {
F_20 ( V_2 -> V_36 ) ;
}
if ( ! V_2 -> V_43 ) {
F_6 ( V_2 , 0 ) ;
V_2 -> V_43 = 1 ;
}
V_13 = V_2 -> V_3 -> V_40 ^ V_47 ,
F_2 ( V_13 , V_2 , V_41 ) ;
F_22 ( V_2 -> V_31 ) ;
}
static T_1 F_23 ( int V_48 , void * V_49 )
{
struct V_1 * V_2 = V_49 ;
unsigned int V_13 ;
V_13 = F_4 ( V_2 , V_17 ) ;
if ( V_13 & V_22 ) {
V_2 -> V_21 = V_13 ;
V_13 &= ~ V_22 ;
V_13 |= ( V_2 -> V_3 -> V_39 & V_22 ) ;
F_2 ( V_13 , V_2 , V_17 ) ;
F_24 ( & V_2 -> V_20 ) ;
return V_50 ;
}
return V_51 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
int V_30 , V_37 ;
F_7 ( & V_2 -> V_14 . V_15 , L_9 ,
V_16 , V_53 -> V_54 << 1 ) ;
F_2 ( V_53 -> V_54 << 1 , V_2 , V_55 ) ;
V_37 = F_11 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_14 ( V_2 ) ;
if ( V_37 )
return V_37 ;
F_7 ( & V_2 -> V_14 . V_15 , L_10 , V_16 ) ;
for ( V_30 = 0 ; V_30 < V_53 -> V_56 ; V_30 ++ ) {
F_7 ( & V_2 -> V_14 . V_15 ,
L_11 ,
V_16 , V_30 , V_53 -> V_57 [ V_30 ] ) ;
F_2 ( V_53 -> V_57 [ V_30 ] , V_2 , V_55 ) ;
V_37 = F_11 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_14 ( V_2 ) ;
if ( V_37 )
return V_37 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_52 * V_53 , bool V_58 )
{
int V_30 , V_37 ;
unsigned int V_13 ;
int V_59 = V_53 -> V_60 & V_61 ;
F_7 ( & V_2 -> V_14 . V_15 ,
L_9 ,
V_16 , ( V_53 -> V_54 << 1 ) | 0x01 ) ;
F_2 ( ( V_53 -> V_54 << 1 ) | 0x01 , V_2 , V_55 ) ;
V_37 = F_11 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_14 ( V_2 ) ;
if ( V_37 )
return V_37 ;
F_7 ( & V_2 -> V_14 . V_15 , L_12 , V_16 ) ;
V_13 = F_4 ( V_2 , V_41 ) ;
V_13 &= ~ V_45 ;
if ( ( V_53 -> V_56 - 1 ) || V_59 )
V_13 &= ~ V_46 ;
F_2 ( V_13 , V_2 , V_41 ) ;
F_4 ( V_2 , V_55 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_13 , V_16 ) ;
for ( V_30 = 0 ; V_30 < V_53 -> V_56 ; V_30 ++ ) {
T_2 V_56 = 0 ;
V_37 = F_11 ( V_2 ) ;
if ( V_37 )
return V_37 ;
if ( ( ! V_30 ) && V_59 ) {
V_56 = F_4 ( V_2 , V_55 ) ;
if ( ( V_56 == 0 ) || ( V_56 > V_62 ) )
return - V_63 ;
F_7 ( & V_2 -> V_14 . V_15 ,
L_14 ,
V_16 , V_56 ) ;
V_53 -> V_56 += V_56 ;
}
if ( V_30 == ( V_53 -> V_56 - 1 ) ) {
if ( V_58 ) {
F_7 ( & V_2 -> V_14 . V_15 ,
L_15 , V_16 ) ;
V_13 = F_4 ( V_2 , V_41 ) ;
V_13 &= ~ ( V_42 | V_45 ) ;
F_2 ( V_13 , V_2 , V_41 ) ;
F_6 ( V_2 , 0 ) ;
V_2 -> V_43 = 1 ;
} else {
V_13 = F_5 ( V_2 -> V_8 + V_41 ) ;
V_13 |= V_45 ;
F_3 ( V_13 , V_2 -> V_8 + V_41 ) ;
}
} else if ( V_30 == ( V_53 -> V_56 - 2 ) ) {
F_7 ( & V_2 -> V_14 . V_15 ,
L_16 , V_16 ) ;
V_13 = F_4 ( V_2 , V_41 ) ;
V_13 |= V_46 ;
F_2 ( V_13 , V_2 , V_41 ) ;
}
if ( ( ! V_30 ) && V_59 )
V_53 -> V_57 [ 0 ] = V_56 ;
else
V_53 -> V_57 [ V_30 ] = F_4 ( V_2 , V_55 ) ;
F_7 ( & V_2 -> V_14 . V_15 ,
L_17 ,
V_16 , V_30 , V_53 -> V_57 [ V_30 ] ) ;
}
return 0 ;
}
static int F_27 ( struct V_64 * V_14 ,
struct V_52 * V_53 , int V_65 )
{
unsigned int V_30 , V_13 ;
int V_37 ;
bool V_58 = false ;
struct V_1 * V_2 = F_28 ( V_14 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_1 , V_16 ) ;
V_37 = F_18 ( V_2 ) ;
if ( V_37 )
goto V_66;
for ( V_30 = 0 ; V_30 < V_65 ; V_30 ++ ) {
if ( V_30 == V_65 - 1 )
V_58 = true ;
if ( V_30 ) {
F_7 ( & V_2 -> V_14 . V_15 ,
L_18 , V_16 ) ;
V_13 = F_4 ( V_2 , V_41 ) ;
V_13 |= V_67 ;
F_2 ( V_13 , V_2 , V_41 ) ;
V_37 = F_6 ( V_2 , 1 ) ;
if ( V_37 )
goto V_66;
}
F_7 ( & V_2 -> V_14 . V_15 ,
L_19 , V_16 , V_30 ) ;
#ifdef F_17
V_13 = F_4 ( V_2 , V_41 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_20
L_21 , V_16 ,
( V_13 & V_47 ? 1 : 0 ) , ( V_13 & V_44 ? 1 : 0 ) ,
( V_13 & V_42 ? 1 : 0 ) , ( V_13 & V_45 ? 1 : 0 ) ,
( V_13 & V_46 ? 1 : 0 ) , ( V_13 & V_67 ? 1 : 0 ) ) ;
V_13 = F_4 ( V_2 , V_17 ) ;
F_7 ( & V_2 -> V_14 . V_15 ,
L_22
L_23 , V_16 ,
( V_13 & V_68 ? 1 : 0 ) , ( V_13 & V_69 ? 1 : 0 ) ,
( V_13 & V_18 ? 1 : 0 ) , ( V_13 & V_70 ? 1 : 0 ) ,
( V_13 & V_71 ? 1 : 0 ) , ( V_13 & V_22 ? 1 : 0 ) ,
( V_13 & V_24 ? 1 : 0 ) ) ;
#endif
if ( V_53 [ V_30 ] . V_60 & V_72 )
V_37 = F_26 ( V_2 , & V_53 [ V_30 ] , V_58 ) ;
else
V_37 = F_25 ( V_2 , & V_53 [ V_30 ] ) ;
if ( V_37 )
goto V_66;
}
V_66:
F_21 ( V_2 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_24 , V_16 ,
( V_37 < 0 ) ? L_25 : L_26 ,
( V_37 < 0 ) ? V_37 : V_65 ) ;
return ( V_37 < 0 ) ? V_37 : V_65 ;
}
static T_3 F_29 ( struct V_64 * V_14 )
{
return V_73 | V_74
| V_75 ;
}
static int F_30 ( struct V_76 * V_77 )
{
const struct V_78 * V_79 = F_31 ( V_80 ,
& V_77 -> V_15 ) ;
struct V_1 * V_2 ;
struct V_81 * V_82 ;
struct V_83 * V_84 = F_32 ( & V_77 -> V_15 ) ;
void T_4 * V_8 ;
int V_48 , V_85 ;
F_7 ( & V_77 -> V_15 , L_1 , V_16 ) ;
V_48 = F_33 ( V_77 , 0 ) ;
if ( V_48 < 0 ) {
F_34 ( & V_77 -> V_15 , L_27 ) ;
return V_48 ;
}
V_82 = F_35 ( V_77 , V_86 , 0 ) ;
V_8 = F_36 ( & V_77 -> V_15 , V_82 ) ;
if ( F_37 ( V_8 ) )
return F_38 ( V_8 ) ;
V_2 = F_39 ( & V_77 -> V_15 , sizeof( struct V_1 ) ,
V_87 ) ;
if ( ! V_2 )
return - V_88 ;
if ( V_79 )
V_2 -> V_3 = V_79 -> V_89 ;
else
V_2 -> V_3 = (struct V_90 * )
F_40 ( V_77 ) -> V_91 ;
F_41 ( V_2 -> V_14 . V_92 , V_77 -> V_92 , sizeof( V_2 -> V_14 . V_92 ) ) ;
V_2 -> V_14 . V_93 = V_94 ;
V_2 -> V_14 . V_95 = & V_96 ;
V_2 -> V_14 . V_15 . V_97 = & V_77 -> V_15 ;
V_2 -> V_14 . V_98 = V_77 -> V_99 ;
V_2 -> V_14 . V_15 . V_100 = V_77 -> V_15 . V_100 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_31 = F_42 ( & V_77 -> V_15 , NULL ) ;
if ( F_37 ( V_2 -> V_31 ) ) {
F_34 ( & V_77 -> V_15 , L_28 ) ;
return F_38 ( V_2 -> V_31 ) ;
}
V_85 = F_19 ( V_2 -> V_31 ) ;
if ( V_85 ) {
F_34 ( & V_77 -> V_15 , L_29 ) ;
return V_85 ;
}
V_85 = F_43 ( & V_77 -> V_15 , V_48 , F_23 , 0 ,
V_77 -> V_92 , V_2 ) ;
if ( V_85 ) {
F_34 ( & V_77 -> V_15 , L_30 , V_48 ) ;
return V_85 ;
}
F_44 ( & V_2 -> V_20 ) ;
F_45 ( & V_2 -> V_14 , V_2 ) ;
V_2 -> V_33 = V_101 ;
V_85 = F_46 ( V_77 -> V_15 . V_100 ,
L_31 , & V_2 -> V_33 ) ;
if ( V_85 < 0 && V_84 && V_84 -> V_33 )
V_2 -> V_33 = V_84 -> V_33 ;
F_2 ( V_2 -> V_3 -> V_40 ^ V_47 ,
V_2 , V_41 ) ;
F_2 ( V_2 -> V_3 -> V_39 , V_2 , V_17 ) ;
V_85 = F_47 ( & V_2 -> V_14 ) ;
if ( V_85 < 0 ) {
F_34 ( & V_77 -> V_15 , L_32 ) ;
return V_85 ;
}
F_48 ( V_77 , V_2 ) ;
F_22 ( V_2 -> V_31 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_33 , V_48 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_34 ,
V_82 -> V_102 , V_82 -> V_103 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_35 ,
F_49 ( V_82 ) , V_82 -> V_102 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_36 ,
V_2 -> V_14 . V_92 ) ;
F_50 ( & V_2 -> V_14 . V_15 , L_37 ) ;
return 0 ;
}
static int F_51 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_52 ( V_77 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_38 ) ;
F_53 ( & V_2 -> V_14 ) ;
F_2 ( 0 , V_2 , V_104 ) ;
F_2 ( 0 , V_2 , V_38 ) ;
F_2 ( 0 , V_2 , V_41 ) ;
F_2 ( 0 , V_2 , V_17 ) ;
return 0 ;
}
static int T_5 F_54 ( void )
{
return F_55 ( & V_105 ) ;
}
static void T_6 F_56 ( void )
{
F_57 ( & V_105 ) ;
}
