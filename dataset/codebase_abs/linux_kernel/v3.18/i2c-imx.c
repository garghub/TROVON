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
if ( V_13 & V_18 ) {
V_13 &= ~ V_18 ;
F_2 ( V_13 , V_2 , V_17 ) ;
return - V_19 ;
}
if ( V_10 && ( V_13 & V_20 ) )
break;
if ( ! V_10 && ! ( V_13 & V_20 ) )
break;
if ( F_8 ( V_12 , V_11 + F_9 ( 500 ) ) ) {
F_7 ( & V_2 -> V_14 . V_15 ,
L_2 , V_16 ) ;
return - V_21 ;
}
F_10 () ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 -> V_22 , V_2 -> V_23 & V_24 , V_25 / 10 ) ;
if ( F_13 ( ! ( V_2 -> V_23 & V_24 ) ) ) {
F_7 ( & V_2 -> V_14 . V_15 , L_3 , V_16 ) ;
return - V_21 ;
}
F_7 ( & V_2 -> V_14 . V_15 , L_4 , V_16 ) ;
V_2 -> V_23 = 0 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 , V_17 ) & V_26 ) {
F_7 ( & V_2 -> V_14 . V_15 , L_5 , V_16 ) ;
return - V_27 ;
}
F_7 ( & V_2 -> V_14 . V_15 , L_6 , V_16 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_3 -> V_30 ;
unsigned int V_31 ;
unsigned int div ;
int V_32 ;
V_31 = F_16 ( V_2 -> V_33 ) ;
if ( V_2 -> V_34 == V_31 )
return;
else
V_2 -> V_34 = V_31 ;
div = ( V_31 + V_2 -> V_35 - 1 ) / V_2 -> V_35 ;
if ( div < V_29 [ 0 ] . div )
V_32 = 0 ;
else if ( div > V_29 [ V_2 -> V_3 -> V_36 - 1 ] . div )
V_32 = V_2 -> V_3 -> V_36 - 1 ;
else
for ( V_32 = 0 ; V_29 [ V_32 ] . div < div ; V_32 ++ ) ;
V_2 -> V_37 = V_29 [ V_32 ] . V_6 ;
V_2 -> V_38 = ( 500000U * V_29 [ V_32 ] . div
+ ( V_31 / 2 ) - 1 ) / ( V_31 / 2 ) ;
#ifdef F_17
F_7 ( & V_2 -> V_14 . V_15 , L_7 ,
V_31 , div ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_8 ,
V_29 [ V_32 ] . V_6 , V_29 [ V_32 ] . div ) ;
#endif
}
static int F_18 ( struct V_1 * V_2 )
{
unsigned int V_13 = 0 ;
int V_39 ;
F_7 ( & V_2 -> V_14 . V_15 , L_1 , V_16 ) ;
F_15 ( V_2 ) ;
V_39 = F_19 ( V_2 -> V_33 ) ;
if ( V_39 )
return V_39 ;
F_2 ( V_2 -> V_37 , V_2 , V_40 ) ;
F_2 ( V_2 -> V_3 -> V_41 , V_2 , V_17 ) ;
F_2 ( V_2 -> V_3 -> V_42 , V_2 , V_43 ) ;
F_20 ( 50 ) ;
V_13 = F_4 ( V_2 , V_43 ) ;
V_13 |= V_44 ;
F_2 ( V_13 , V_2 , V_43 ) ;
V_39 = F_6 ( V_2 , 1 ) ;
if ( V_39 )
return V_39 ;
V_2 -> V_45 = 0 ;
V_13 |= V_46 | V_47 | V_48 ;
F_2 ( V_13 , V_2 , V_43 ) ;
return V_39 ;
}
static void F_21 ( struct V_1 * V_2 )
{
unsigned int V_13 = 0 ;
if ( ! V_2 -> V_45 ) {
F_7 ( & V_2 -> V_14 . V_15 , L_1 , V_16 ) ;
V_13 = F_4 ( V_2 , V_43 ) ;
V_13 &= ~ ( V_44 | V_47 ) ;
F_2 ( V_13 , V_2 , V_43 ) ;
}
if ( F_1 ( V_2 ) ) {
F_20 ( V_2 -> V_38 ) ;
}
if ( ! V_2 -> V_45 ) {
F_6 ( V_2 , 0 ) ;
V_2 -> V_45 = 1 ;
}
V_13 = V_2 -> V_3 -> V_42 ^ V_49 ,
F_2 ( V_13 , V_2 , V_43 ) ;
F_22 ( V_2 -> V_33 ) ;
}
static T_1 F_23 ( int V_50 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
unsigned int V_13 ;
V_13 = F_4 ( V_2 , V_17 ) ;
if ( V_13 & V_24 ) {
V_2 -> V_23 = V_13 ;
V_13 &= ~ V_24 ;
V_13 |= ( V_2 -> V_3 -> V_41 & V_24 ) ;
F_2 ( V_13 , V_2 , V_17 ) ;
F_24 ( & V_2 -> V_22 ) ;
return V_52 ;
}
return V_53 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
int V_32 , V_39 ;
F_7 ( & V_2 -> V_14 . V_15 , L_9 ,
V_16 , V_55 -> V_56 << 1 ) ;
F_2 ( V_55 -> V_56 << 1 , V_2 , V_57 ) ;
V_39 = F_11 ( V_2 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_14 ( V_2 ) ;
if ( V_39 )
return V_39 ;
F_7 ( & V_2 -> V_14 . V_15 , L_10 , V_16 ) ;
for ( V_32 = 0 ; V_32 < V_55 -> V_58 ; V_32 ++ ) {
F_7 ( & V_2 -> V_14 . V_15 ,
L_11 ,
V_16 , V_32 , V_55 -> V_59 [ V_32 ] ) ;
F_2 ( V_55 -> V_59 [ V_32 ] , V_2 , V_57 ) ;
V_39 = F_11 ( V_2 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_14 ( V_2 ) ;
if ( V_39 )
return V_39 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_54 * V_55 , bool V_60 )
{
int V_32 , V_39 ;
unsigned int V_13 ;
int V_61 = V_55 -> V_62 & V_63 ;
F_7 ( & V_2 -> V_14 . V_15 ,
L_9 ,
V_16 , ( V_55 -> V_56 << 1 ) | 0x01 ) ;
F_2 ( ( V_55 -> V_56 << 1 ) | 0x01 , V_2 , V_57 ) ;
V_39 = F_11 ( V_2 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_14 ( V_2 ) ;
if ( V_39 )
return V_39 ;
F_7 ( & V_2 -> V_14 . V_15 , L_12 , V_16 ) ;
V_13 = F_4 ( V_2 , V_43 ) ;
V_13 &= ~ V_47 ;
if ( ( V_55 -> V_58 - 1 ) || V_61 )
V_13 &= ~ V_48 ;
F_2 ( V_13 , V_2 , V_43 ) ;
F_4 ( V_2 , V_57 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_13 , V_16 ) ;
for ( V_32 = 0 ; V_32 < V_55 -> V_58 ; V_32 ++ ) {
T_2 V_58 = 0 ;
V_39 = F_11 ( V_2 ) ;
if ( V_39 )
return V_39 ;
if ( ( ! V_32 ) && V_61 ) {
V_58 = F_4 ( V_2 , V_57 ) ;
if ( ( V_58 == 0 ) || ( V_58 > V_64 ) )
return - V_65 ;
F_7 ( & V_2 -> V_14 . V_15 ,
L_14 ,
V_16 , V_58 ) ;
V_55 -> V_58 += V_58 ;
}
if ( V_32 == ( V_55 -> V_58 - 1 ) ) {
if ( V_60 ) {
F_7 ( & V_2 -> V_14 . V_15 ,
L_15 , V_16 ) ;
V_13 = F_4 ( V_2 , V_43 ) ;
V_13 &= ~ ( V_44 | V_47 ) ;
F_2 ( V_13 , V_2 , V_43 ) ;
F_6 ( V_2 , 0 ) ;
V_2 -> V_45 = 1 ;
} else {
V_13 = F_5 ( V_2 -> V_8 + V_43 ) ;
V_13 |= V_47 ;
F_3 ( V_13 , V_2 -> V_8 + V_43 ) ;
}
} else if ( V_32 == ( V_55 -> V_58 - 2 ) ) {
F_7 ( & V_2 -> V_14 . V_15 ,
L_16 , V_16 ) ;
V_13 = F_4 ( V_2 , V_43 ) ;
V_13 |= V_48 ;
F_2 ( V_13 , V_2 , V_43 ) ;
}
if ( ( ! V_32 ) && V_61 )
V_55 -> V_59 [ 0 ] = V_58 ;
else
V_55 -> V_59 [ V_32 ] = F_4 ( V_2 , V_57 ) ;
F_7 ( & V_2 -> V_14 . V_15 ,
L_17 ,
V_16 , V_32 , V_55 -> V_59 [ V_32 ] ) ;
}
return 0 ;
}
static int F_27 ( struct V_66 * V_14 ,
struct V_54 * V_55 , int V_67 )
{
unsigned int V_32 , V_13 ;
int V_39 ;
bool V_60 = false ;
struct V_1 * V_2 = F_28 ( V_14 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_1 , V_16 ) ;
V_39 = F_18 ( V_2 ) ;
if ( V_39 )
goto V_68;
for ( V_32 = 0 ; V_32 < V_67 ; V_32 ++ ) {
if ( V_32 == V_67 - 1 )
V_60 = true ;
if ( V_32 ) {
F_7 ( & V_2 -> V_14 . V_15 ,
L_18 , V_16 ) ;
V_13 = F_4 ( V_2 , V_43 ) ;
V_13 |= V_69 ;
F_2 ( V_13 , V_2 , V_43 ) ;
V_39 = F_6 ( V_2 , 1 ) ;
if ( V_39 )
goto V_68;
}
F_7 ( & V_2 -> V_14 . V_15 ,
L_19 , V_16 , V_32 ) ;
#ifdef F_17
V_13 = F_4 ( V_2 , V_43 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_20
L_21 , V_16 ,
( V_13 & V_49 ? 1 : 0 ) , ( V_13 & V_46 ? 1 : 0 ) ,
( V_13 & V_44 ? 1 : 0 ) , ( V_13 & V_47 ? 1 : 0 ) ,
( V_13 & V_48 ? 1 : 0 ) , ( V_13 & V_69 ? 1 : 0 ) ) ;
V_13 = F_4 ( V_2 , V_17 ) ;
F_7 ( & V_2 -> V_14 . V_15 ,
L_22
L_23 , V_16 ,
( V_13 & V_70 ? 1 : 0 ) , ( V_13 & V_71 ? 1 : 0 ) ,
( V_13 & V_20 ? 1 : 0 ) , ( V_13 & V_18 ? 1 : 0 ) ,
( V_13 & V_72 ? 1 : 0 ) , ( V_13 & V_24 ? 1 : 0 ) ,
( V_13 & V_26 ? 1 : 0 ) ) ;
#endif
if ( V_55 [ V_32 ] . V_62 & V_73 )
V_39 = F_26 ( V_2 , & V_55 [ V_32 ] , V_60 ) ;
else
V_39 = F_25 ( V_2 , & V_55 [ V_32 ] ) ;
if ( V_39 )
goto V_68;
}
V_68:
F_21 ( V_2 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_24 , V_16 ,
( V_39 < 0 ) ? L_25 : L_26 ,
( V_39 < 0 ) ? V_39 : V_67 ) ;
return ( V_39 < 0 ) ? V_39 : V_67 ;
}
static T_3 F_29 ( struct V_66 * V_14 )
{
return V_74 | V_75
| V_76 ;
}
static int F_30 ( struct V_77 * V_78 )
{
const struct V_79 * V_80 = F_31 ( V_81 ,
& V_78 -> V_15 ) ;
struct V_1 * V_2 ;
struct V_82 * V_83 ;
struct V_84 * V_85 = F_32 ( & V_78 -> V_15 ) ;
void T_4 * V_8 ;
int V_50 , V_86 ;
F_7 ( & V_78 -> V_15 , L_1 , V_16 ) ;
V_50 = F_33 ( V_78 , 0 ) ;
if ( V_50 < 0 ) {
F_34 ( & V_78 -> V_15 , L_27 ) ;
return V_50 ;
}
V_83 = F_35 ( V_78 , V_87 , 0 ) ;
V_8 = F_36 ( & V_78 -> V_15 , V_83 ) ;
if ( F_37 ( V_8 ) )
return F_38 ( V_8 ) ;
V_2 = F_39 ( & V_78 -> V_15 , sizeof( struct V_1 ) ,
V_88 ) ;
if ( ! V_2 )
return - V_89 ;
if ( V_80 )
V_2 -> V_3 = V_80 -> V_90 ;
else
V_2 -> V_3 = (struct V_91 * )
F_40 ( V_78 ) -> V_92 ;
F_41 ( V_2 -> V_14 . V_93 , V_78 -> V_93 , sizeof( V_2 -> V_14 . V_93 ) ) ;
V_2 -> V_14 . V_94 = V_95 ;
V_2 -> V_14 . V_96 = & V_97 ;
V_2 -> V_14 . V_15 . V_98 = & V_78 -> V_15 ;
V_2 -> V_14 . V_99 = V_78 -> V_100 ;
V_2 -> V_14 . V_15 . V_101 = V_78 -> V_15 . V_101 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_33 = F_42 ( & V_78 -> V_15 , NULL ) ;
if ( F_37 ( V_2 -> V_33 ) ) {
F_34 ( & V_78 -> V_15 , L_28 ) ;
return F_38 ( V_2 -> V_33 ) ;
}
V_86 = F_19 ( V_2 -> V_33 ) ;
if ( V_86 ) {
F_34 ( & V_78 -> V_15 , L_29 ) ;
return V_86 ;
}
V_86 = F_43 ( & V_78 -> V_15 , V_50 , F_23 , 0 ,
V_78 -> V_93 , V_2 ) ;
if ( V_86 ) {
F_34 ( & V_78 -> V_15 , L_30 , V_50 ) ;
goto V_102;
}
F_44 ( & V_2 -> V_22 ) ;
F_45 ( & V_2 -> V_14 , V_2 ) ;
V_2 -> V_35 = V_103 ;
V_86 = F_46 ( V_78 -> V_15 . V_101 ,
L_31 , & V_2 -> V_35 ) ;
if ( V_86 < 0 && V_85 && V_85 -> V_35 )
V_2 -> V_35 = V_85 -> V_35 ;
F_2 ( V_2 -> V_3 -> V_42 ^ V_49 ,
V_2 , V_43 ) ;
F_2 ( V_2 -> V_3 -> V_41 , V_2 , V_17 ) ;
V_86 = F_47 ( & V_2 -> V_14 ) ;
if ( V_86 < 0 ) {
F_34 ( & V_78 -> V_15 , L_32 ) ;
goto V_102;
}
F_48 ( V_78 , V_2 ) ;
F_22 ( V_2 -> V_33 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_33 , V_50 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_34 , V_83 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_35 ,
V_2 -> V_14 . V_93 ) ;
F_49 ( & V_2 -> V_14 . V_15 , L_36 ) ;
return 0 ;
V_102:
F_22 ( V_2 -> V_33 ) ;
return V_86 ;
}
static int F_50 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_51 ( V_78 ) ;
F_7 ( & V_2 -> V_14 . V_15 , L_37 ) ;
F_52 ( & V_2 -> V_14 ) ;
F_2 ( 0 , V_2 , V_104 ) ;
F_2 ( 0 , V_2 , V_40 ) ;
F_2 ( 0 , V_2 , V_43 ) ;
F_2 ( 0 , V_2 , V_17 ) ;
return 0 ;
}
static int T_5 F_53 ( void )
{
return F_54 ( & V_105 ) ;
}
static void T_6 F_55 ( void )
{
F_56 ( & V_105 ) ;
}
