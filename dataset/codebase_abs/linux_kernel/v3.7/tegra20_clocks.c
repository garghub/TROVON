static unsigned long F_1 ( void )
{
T_1 V_1 ;
F_2 ( V_2 | 1 , V_3 ) ;
do {} while ( F_3 ( V_4 ) & V_5 );
V_1 = F_3 ( V_4 ) ;
if ( V_1 >= 732 - 3 && V_1 <= 732 + 3 ) {
return 12000000 ;
} else if ( V_1 >= 794 - 3 && V_1 <= 794 + 3 ) {
return 13000000 ;
} else if ( V_1 >= 1172 - 3 && V_1 <= 1172 + 3 ) {
return 19200000 ;
} else if ( V_1 >= 1587 - 3 && V_1 <= 1587 + 3 ) {
return 26000000 ;
} else {
F_4 ( L_1 ,
V_6 , V_1 ) ;
F_5 () ;
return 0 ;
}
}
static int F_6 ( unsigned long V_7 , unsigned long V_8 )
{
T_2 V_9 = V_7 * 2 ;
V_9 += V_8 - 1 ;
F_7 ( V_9 , V_8 ) ;
if ( V_9 - 2 < 0 )
return 0 ;
if ( V_9 - 2 > 255 )
return - V_10 ;
return V_9 - 2 ;
}
static int F_8 ( unsigned long V_7 , unsigned long V_8 )
{
T_2 V_11 ;
V_11 = V_7 ;
V_11 += V_8 - 1 ;
F_7 ( V_11 , V_8 ) ;
if ( V_11 - 1 < 0 )
return 0 ;
if ( V_11 - 1 > 0xFFFF )
return - V_10 ;
return V_11 - 1 ;
}
static unsigned long F_9 ( struct V_12 * V_13 ,
unsigned long V_7 )
{
return F_10 ( V_13 ) -> V_14 ;
}
static unsigned long F_11 ( struct V_12 * V_13 ,
unsigned long V_15 )
{
if ( ! F_10 ( V_13 ) -> V_14 )
F_10 ( V_13 ) -> V_14 = F_1 () ;
return F_10 ( V_13 ) -> V_14 ;
}
static void F_12 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_18 = F_3 ( V_19 ) ;
T_1 V_20 = V_18 & ~ V_21 ;
switch ( V_17 -> V_14 ) {
case 12000000 :
V_20 |= V_22 ;
break;
case 13000000 :
V_20 |= V_23 ;
break;
case 19200000 :
V_20 |= V_24 ;
break;
case 26000000 :
V_20 |= V_25 ;
break;
default:
F_5 () ;
}
F_2 ( V_20 , V_19 ) ;
}
static int F_13 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_26 ;
V_26 = F_3 ( V_17 -> V_27 + V_28 ) ;
F_14 ( ( ( V_26 & V_29 ) != V_30 ) &&
( ( V_26 & V_29 ) != V_31 ) ) ;
V_17 -> V_32 = V_33 ;
return V_17 -> V_32 ;
}
static int F_15 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
F_2 ( 0 , V_17 -> V_27 + V_34 ) ;
return 0 ;
}
static void F_16 ( struct V_12 * V_13 )
{
F_17 ( L_2 , V_6 , F_18 ( V_13 -> V_35 ) ) ;
F_5 () ;
}
static T_3 F_19 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
int V_26 = F_3 ( V_17 -> V_27 + V_28 ) ;
int V_36 ;
int V_37 ;
F_14 ( ( ( V_26 & V_29 ) != V_30 ) &&
( ( V_26 & V_29 ) != V_31 ) ) ;
V_37 = ( ( V_26 & V_29 ) == V_31 ) ?
V_38 : V_39 ;
V_36 = ( V_26 >> V_37 ) & V_40 ;
return V_36 ;
}
static int F_20 ( struct V_12 * V_13 , T_3 V_41 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_26 = F_3 ( V_17 -> V_27 + V_28 ) ;
int V_37 ;
F_14 ( ( ( V_26 & V_29 ) != V_30 ) &&
( ( V_26 & V_29 ) != V_31 ) ) ;
V_37 = ( ( V_26 & V_29 ) == V_31 ) ?
V_38 : V_39 ;
V_26 &= ~ ( V_40 << V_37 ) ;
V_26 |= V_41 << V_37 ;
F_2 ( V_26 , V_17 -> V_27 ) ;
return 0 ;
}
static unsigned long F_21 ( struct V_12 * V_13 ,
unsigned long V_15 )
{
return V_15 ;
}
static long F_22 ( struct V_12 * V_13 , unsigned long V_8 ,
unsigned long * V_15 )
{
return * V_15 ;
}
static int F_23 ( struct V_12 * V_13 , unsigned long V_8 ,
unsigned long V_7 )
{
return 0 ;
}
static unsigned long F_24 ( struct V_12 * V_13 ,
unsigned long V_7 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_4 V_8 = V_7 ;
if ( V_17 -> V_42 != 0 && V_17 -> div != 0 ) {
V_8 *= V_17 -> V_42 ;
V_8 += V_17 -> div - 1 ;
F_7 ( V_8 , V_17 -> div ) ;
}
return V_8 ;
}
static T_3 F_25 ( struct V_12 * V_13 )
{
return 0 ;
}
void F_26 ( struct V_12 * V_13 , bool assert )
{
unsigned long V_27 = assert ? V_43 : V_44 ;
F_17 ( L_3 , V_6 , assert ? L_4 : L_5 ) ;
F_2 ( 1 << 1 , V_27 ) ;
}
static int F_27 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_26 = F_3 ( V_17 -> V_27 ) ;
V_17 -> V_32 = ( ( V_26 >> V_17 -> V_45 ) & V_46 ) ? V_47 : V_33 ;
return V_17 -> V_32 ;
}
static int F_28 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
unsigned long V_48 ;
T_1 V_26 ;
F_29 ( & V_49 , V_48 ) ;
V_26 = F_3 ( V_17 -> V_27 ) ;
V_26 &= ~ ( V_46 << V_17 -> V_45 ) ;
F_2 ( V_26 , V_17 -> V_27 ) ;
F_30 ( & V_49 , V_48 ) ;
return 0 ;
}
static void F_31 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
unsigned long V_48 ;
T_1 V_26 ;
F_29 ( & V_49 , V_48 ) ;
V_26 = F_3 ( V_17 -> V_27 ) ;
V_26 |= V_46 << V_17 -> V_45 ;
F_2 ( V_26 , V_17 -> V_27 ) ;
F_30 ( & V_49 , V_48 ) ;
}
static unsigned long F_32 ( struct V_12 * V_13 ,
unsigned long V_15 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_26 = F_3 ( V_17 -> V_27 ) ;
T_4 V_8 = V_15 ;
V_17 -> div = ( ( V_26 >> V_17 -> V_45 ) & V_50 ) + 1 ;
V_17 -> V_42 = 1 ;
if ( V_17 -> V_42 != 0 && V_17 -> div != 0 ) {
V_8 *= V_17 -> V_42 ;
V_8 += V_17 -> div - 1 ;
F_7 ( V_8 , V_17 -> div ) ;
}
return V_8 ;
}
static int F_33 ( struct V_12 * V_13 , unsigned long V_8 ,
unsigned long V_7 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
int V_51 = - V_10 ;
unsigned long V_48 ;
T_1 V_26 ;
int V_52 ;
F_29 ( & V_49 , V_48 ) ;
V_26 = F_3 ( V_17 -> V_27 ) ;
for ( V_52 = 1 ; V_52 <= 4 ; V_52 ++ ) {
if ( V_8 == V_7 / V_52 ) {
V_26 &= ~ ( V_50 << V_17 -> V_45 ) ;
V_26 |= ( V_52 - 1 ) << V_17 -> V_45 ;
F_2 ( V_26 , V_17 -> V_27 ) ;
V_17 -> div = V_52 ;
V_17 -> V_42 = 1 ;
V_51 = 0 ;
break;
}
}
F_30 ( & V_49 , V_48 ) ;
return V_51 ;
}
static long F_34 ( struct V_12 * V_13 , unsigned long V_8 ,
unsigned long * V_15 )
{
unsigned long V_7 = * V_15 ;
T_2 V_53 ;
if ( V_8 >= V_7 )
return V_8 ;
V_53 = V_7 ;
V_53 += V_8 - 1 ;
F_7 ( V_53 , V_8 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_53 > 4 )
V_53 = 4 ;
F_7 ( V_7 , V_53 ) ;
return V_7 ;
}
static int F_35 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_26 ;
V_26 = F_36 ( V_54 ) ;
V_17 -> V_32 = ( V_26 & V_55 ) ? V_33 : V_47 ;
return V_17 -> V_32 ;
}
static unsigned long F_37 ( struct V_12 * V_13 ,
unsigned long V_15 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_4 V_8 = V_15 ;
T_1 V_26 ;
V_17 -> V_42 = 1 ;
V_26 = F_36 ( V_17 -> V_27 ) ;
if ( V_26 & V_56 ) {
unsigned int V_57 ;
V_57 = ( V_26 >> V_58 ) &
V_59 ;
V_26 >>= V_60 ;
V_26 &= V_61 ;
V_57 += V_26 ;
V_17 -> div = V_57 * 4 ;
} else {
V_17 -> div = 1 ;
}
if ( V_17 -> V_42 != 0 && V_17 -> div != 0 ) {
V_8 *= V_17 -> V_42 ;
V_8 += V_17 -> div - 1 ;
F_7 ( V_8 , V_17 -> div ) ;
}
return V_8 ;
}
static int F_38 ( struct V_12 * V_13 )
{
T_1 V_26 ;
V_26 = F_36 ( V_62 ) ;
F_39 ( V_26 | V_63 , V_62 ) ;
V_26 = F_36 ( V_54 ) ;
F_39 ( V_26 | V_55 , V_54 ) ;
return 0 ;
}
static void F_40 ( struct V_12 * V_13 )
{
T_1 V_26 ;
V_26 = F_36 ( V_54 ) ;
F_39 ( V_26 & ~ V_55 , V_54 ) ;
V_26 = F_36 ( V_62 ) ;
F_39 ( V_26 & ~ V_63 , V_62 ) ;
}
static int F_41 ( struct V_12 * V_13 , unsigned long V_8 ,
unsigned long V_7 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
if ( V_8 >= V_7 ) {
V_17 -> div = 1 ;
F_39 ( 0 , V_17 -> V_27 ) ;
} else {
unsigned int V_57 ;
T_1 V_26 ;
V_57 = F_42 ( V_7 / 8 , V_8 ) ;
V_17 -> div = V_57 * 8 ;
V_26 = ( V_57 & V_59 ) <<
V_58 ;
V_57 &= V_61 ;
V_57 <<= V_60 ;
V_26 |= V_57 ;
V_26 |= V_56 ;
F_39 ( V_26 , V_17 -> V_27 ) ;
}
return 0 ;
}
static long F_43 ( struct V_12 * V_13 , unsigned long V_8 ,
unsigned long * V_15 )
{
int div ;
int V_42 ;
long V_64 = * V_15 ;
V_42 = 1 ;
if ( V_8 >= * V_15 ) {
div = 1 ;
} else {
div = F_42 ( * V_15 / 8 , V_8 ) ;
div *= 8 ;
}
V_64 *= V_42 ;
V_64 += div - 1 ;
F_7 ( V_64 , div ) ;
return V_64 ;
}
static int F_44 ( struct V_16 * V_17 )
{
F_45 ( V_17 -> V_65 . V_66 . V_67 ) ;
return 0 ;
}
static int F_46 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_26 = F_3 ( V_17 -> V_27 + V_68 ) ;
V_17 -> V_32 = ( V_26 & V_69 ) ? V_33 : V_47 ;
return V_17 -> V_32 ;
}
static unsigned long F_47 ( struct V_12 * V_13 ,
unsigned long V_15 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_26 = F_3 ( V_17 -> V_27 + V_68 ) ;
T_4 V_8 = V_15 ;
if ( V_17 -> V_48 & V_70 && ! ( V_26 & V_71 ) ) {
const struct V_72 * V_73 ;
for ( V_73 = V_17 -> V_65 . V_66 . V_74 ; V_73 -> V_75 != 0 ; V_73 ++ ) {
if ( V_73 -> V_75 == V_15 &&
V_73 -> V_76 == V_17 -> V_65 . V_66 . V_14 ) {
V_17 -> V_42 = V_73 -> V_77 ;
V_17 -> div = V_73 -> V_78 * V_73 -> V_79 ;
break;
}
}
F_4 ( L_6 ,
F_18 ( V_13 -> V_35 ) ) ;
F_5 () ;
} else if ( V_26 & V_80 ) {
V_17 -> V_42 = 1 ;
V_17 -> div = 1 ;
} else {
V_17 -> V_42 = ( V_26 & V_81 ) >> V_82 ;
V_17 -> div = ( V_26 & V_83 ) >> V_84 ;
if ( V_17 -> V_48 & V_85 )
V_17 -> div *= ( V_26 & V_86 ) ? 1 : 2 ;
else
V_17 -> div *= ( V_26 & V_87 ) ? 2 : 1 ;
}
if ( V_17 -> V_42 != 0 && V_17 -> div != 0 ) {
V_8 *= V_17 -> V_42 ;
V_8 += V_17 -> div - 1 ;
F_7 ( V_8 , V_17 -> div ) ;
}
return V_8 ;
}
static int F_48 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_26 ;
F_17 ( L_2 , V_6 , F_18 ( V_13 -> V_35 ) ) ;
V_26 = F_3 ( V_17 -> V_27 + V_68 ) ;
V_26 &= ~ V_80 ;
V_26 |= V_69 ;
F_2 ( V_26 , V_17 -> V_27 + V_68 ) ;
F_44 ( V_17 ) ;
return 0 ;
}
static void F_49 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_26 ;
F_17 ( L_2 , V_6 , F_18 ( V_13 -> V_35 ) ) ;
V_26 = F_3 ( V_17 -> V_27 ) ;
V_26 &= ~ ( V_80 | V_69 ) ;
F_2 ( V_26 , V_17 -> V_27 ) ;
}
static int F_50 ( struct V_12 * V_13 , unsigned long V_8 ,
unsigned long V_7 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
unsigned long V_75 = V_7 ;
const struct V_72 * V_73 ;
T_1 V_26 ;
F_17 ( L_7 , V_6 , F_18 ( V_13 -> V_35 ) , V_8 ) ;
if ( V_17 -> V_48 & V_70 ) {
int V_51 = 0 ;
if ( V_8 != V_17 -> V_65 . V_66 . V_14 ) {
F_4 ( L_8 ,
V_6 , F_18 ( V_13 -> V_35 ) ,
V_17 -> V_65 . V_66 . V_14 , V_8 ) ;
V_51 = - V_10 ;
}
return V_51 ;
}
for ( V_73 = V_17 -> V_65 . V_66 . V_74 ; V_73 -> V_75 != 0 ; V_73 ++ ) {
if ( V_73 -> V_75 == V_75 && V_73 -> V_76 == V_8 ) {
V_17 -> V_42 = V_73 -> V_77 ;
V_17 -> div = V_73 -> V_78 * V_73 -> V_79 ;
V_26 = F_3 ( V_17 -> V_27 + V_68 ) ;
if ( V_17 -> V_48 & V_70 )
V_26 |= V_71 ;
V_26 &= ~ ( V_87 | V_81 |
V_83 ) ;
V_26 |= ( V_73 -> V_78 << V_84 ) |
( V_73 -> V_77 << V_82 ) ;
F_14 ( V_73 -> V_79 < 1 || V_73 -> V_79 > 2 ) ;
if ( V_17 -> V_48 & V_85 ) {
if ( V_73 -> V_79 == 1 )
V_26 |= V_86 ;
} else {
if ( V_73 -> V_79 == 2 )
V_26 |= 1 << V_88 ;
}
F_2 ( V_26 , V_17 -> V_27 + V_68 ) ;
if ( V_17 -> V_48 & V_89 ) {
V_26 = F_3 ( V_17 -> V_27 + F_51 ( V_17 ) ) ;
V_26 &= ~ V_90 ;
V_26 |= V_73 -> V_91 << V_92 ;
F_2 ( V_26 , V_17 -> V_27 + F_51 ( V_17 ) ) ;
}
if ( V_17 -> V_32 == V_33 )
F_48 ( V_13 ) ;
return 0 ;
}
}
return - V_10 ;
}
static long F_52 ( struct V_12 * V_13 , unsigned long V_8 ,
unsigned long * V_15 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
const struct V_72 * V_73 ;
unsigned long V_75 = * V_15 ;
T_4 V_76 = * V_15 ;
int V_42 ;
int div ;
if ( V_17 -> V_48 & V_70 )
return V_17 -> V_65 . V_66 . V_14 ;
for ( V_73 = V_17 -> V_65 . V_66 . V_74 ; V_73 -> V_75 != 0 ; V_73 ++ )
if ( V_73 -> V_75 == V_75 && V_73 -> V_76 == V_8 ) {
V_42 = V_73 -> V_77 ;
div = V_73 -> V_78 * V_73 -> V_79 ;
break;
}
if ( V_73 -> V_75 == 0 )
return - V_10 ;
V_76 *= V_42 ;
V_76 += div - 1 ;
F_7 ( V_76 , div ) ;
return V_76 ;
}
static void F_53 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
if ( V_93 == 7 )
V_17 -> V_94 = 750000000 ;
}
static int F_54 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_26 ;
F_17 ( L_2 , V_6 , F_18 ( V_13 -> V_35 ) ) ;
F_55 ( 1 ) ;
V_26 = F_3 ( V_17 -> V_27 + V_68 ) ;
if ( ! ( V_26 & V_95 ) )
return - V_96 ;
V_26 = F_3 ( V_17 -> V_27 + V_68 ) ;
V_26 |= V_69 | V_80 ;
F_2 ( V_26 , V_17 -> V_27 + V_68 ) ;
return 0 ;
}
static int F_56 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_26 = F_3 ( V_17 -> V_27 ) ;
V_26 >>= V_17 -> V_45 ;
V_17 -> V_32 = ( V_26 & V_97 ) ? V_33 : V_47 ;
if ( ! ( V_26 & V_98 ) )
V_17 -> V_32 = V_47 ;
return V_17 -> V_32 ;
}
static unsigned long F_57 ( struct V_12 * V_13 ,
unsigned long V_15 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_4 V_8 = V_15 ;
T_1 V_26 = F_3 ( V_17 -> V_27 ) ;
T_1 V_99 ;
V_26 >>= V_17 -> V_45 ;
if ( V_17 -> V_48 & V_100 ) {
V_99 = ( V_26 & V_101 ) >> V_102 ;
V_17 -> div = ( V_99 + 2 ) ;
V_17 -> V_42 = 2 ;
} else if ( V_17 -> V_48 & V_103 ) {
V_17 -> div = 2 ;
V_17 -> V_42 = 1 ;
} else {
V_17 -> div = 1 ;
V_17 -> V_42 = 1 ;
}
V_8 *= V_17 -> V_42 ;
V_8 += V_17 -> div - 1 ;
F_7 ( V_8 , V_17 -> div ) ;
return V_8 ;
}
static int F_58 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
unsigned long V_48 ;
T_1 V_104 ;
T_1 V_26 ;
F_17 ( L_9 , V_6 , F_18 ( V_13 -> V_35 ) ) ;
if ( V_17 -> V_48 & V_100 ) {
F_29 ( & V_49 , V_48 ) ;
V_26 = F_3 ( V_17 -> V_27 ) ;
V_104 = V_26 >> V_17 -> V_45 ;
V_104 &= 0xFFFF ;
V_104 |= V_97 | V_98 ;
V_26 &= ~ ( 0xFFFF << V_17 -> V_45 ) ;
V_26 |= V_104 << V_17 -> V_45 ;
F_2 ( V_26 , V_17 -> V_27 ) ;
F_30 ( & V_49 , V_48 ) ;
return 0 ;
} else if ( V_17 -> V_48 & V_103 ) {
F_14 ( ! ( V_17 -> V_48 & V_105 ) ) ;
F_29 ( & V_49 , V_48 ) ;
V_26 = F_3 ( V_17 -> V_27 ) ;
V_26 &= ~ V_106 ;
F_2 ( V_26 , V_17 -> V_27 ) ;
F_30 ( & V_49 , V_48 ) ;
return 0 ;
}
return - V_10 ;
}
static void F_59 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
unsigned long V_48 ;
T_1 V_104 ;
T_1 V_26 ;
F_17 ( L_9 , V_6 , F_18 ( V_13 -> V_35 ) ) ;
if ( V_17 -> V_48 & V_100 ) {
F_29 ( & V_49 , V_48 ) ;
V_26 = F_3 ( V_17 -> V_27 ) ;
V_104 = V_26 >> V_17 -> V_45 ;
V_104 &= 0xFFFF ;
V_104 &= ~ ( V_97 | V_98 ) ;
V_26 &= ~ ( 0xFFFF << V_17 -> V_45 ) ;
V_26 |= V_104 << V_17 -> V_45 ;
F_2 ( V_26 , V_17 -> V_27 ) ;
F_30 ( & V_49 , V_48 ) ;
} else if ( V_17 -> V_48 & V_103 ) {
F_14 ( ! ( V_17 -> V_48 & V_105 ) ) ;
F_29 ( & V_49 , V_48 ) ;
V_26 = F_3 ( V_17 -> V_27 ) ;
V_26 |= V_106 ;
F_2 ( V_26 , V_17 -> V_27 ) ;
F_30 ( & V_49 , V_48 ) ;
}
}
static int F_60 ( struct V_12 * V_13 , unsigned long V_8 ,
unsigned long V_7 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
unsigned long V_48 ;
int V_9 ;
T_1 V_104 ;
T_1 V_26 ;
F_17 ( L_7 , V_6 , F_18 ( V_13 -> V_35 ) , V_8 ) ;
if ( V_17 -> V_48 & V_100 ) {
V_9 = F_6 ( V_7 , V_8 ) ;
if ( V_9 >= 0 ) {
F_29 ( & V_49 , V_48 ) ;
V_26 = F_3 ( V_17 -> V_27 ) ;
V_104 = V_26 >> V_17 -> V_45 ;
V_104 &= 0xFFFF ;
if ( V_17 -> V_48 & V_107 )
V_104 |= V_108 ;
V_104 &= ~ V_101 ;
V_104 |= V_9 << V_102 ;
V_26 &= ~ ( 0xFFFF << V_17 -> V_45 ) ;
V_26 |= V_104 << V_17 -> V_45 ;
F_2 ( V_26 , V_17 -> V_27 ) ;
V_17 -> div = V_9 + 2 ;
V_17 -> V_42 = 2 ;
F_30 ( & V_49 , V_48 ) ;
return 0 ;
}
} else if ( V_17 -> V_48 & V_103 ) {
if ( V_7 == V_8 * 2 )
return 0 ;
}
return - V_10 ;
}
static long F_61 ( struct V_12 * V_13 , unsigned long V_8 ,
unsigned long * V_15 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
unsigned long V_7 = * V_15 ;
int V_53 ;
F_17 ( L_7 , V_6 , F_18 ( V_13 -> V_35 ) , V_8 ) ;
if ( V_17 -> V_48 & V_100 ) {
V_53 = F_6 ( V_7 , V_8 ) ;
if ( V_53 < 0 )
return V_53 ;
return F_42 ( V_7 * 2 , V_53 + 2 ) ;
} else if ( V_17 -> V_48 & V_103 ) {
return F_42 ( V_7 , 2 ) ;
}
return - V_10 ;
}
static int F_62 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
V_17 -> V_32 = V_33 ;
if ( ! V_17 -> V_65 . V_109 . V_110 )
goto V_111;
if ( ! ( F_3 ( V_112 + F_63 ( V_17 ) ) &
F_64 ( V_17 ) ) )
V_17 -> V_32 = V_47 ;
if ( ! ( V_17 -> V_48 & V_113 ) )
if ( F_3 ( V_114 + F_63 ( V_17 ) ) &
F_64 ( V_17 ) )
V_17 -> V_32 = V_47 ;
V_111:
return V_17 -> V_32 ;
}
static int F_65 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
unsigned long V_48 ;
T_1 V_26 ;
F_17 ( L_2 , V_6 , F_18 ( V_13 -> V_35 ) ) ;
if ( ! V_17 -> V_65 . V_109 . V_110 )
return 0 ;
V_115 [ V_17 -> V_65 . V_109 . V_110 ] ++ ;
if ( V_115 [ V_17 -> V_65 . V_109 . V_110 ] > 1 )
return 0 ;
F_29 ( & V_49 , V_48 ) ;
F_2 ( F_64 ( V_17 ) ,
V_116 + F_66 ( V_17 ) ) ;
if ( ! ( V_17 -> V_48 & V_113 ) && ! ( V_17 -> V_48 & V_117 ) )
F_2 ( F_64 ( V_17 ) ,
V_44 + F_66 ( V_17 ) ) ;
if ( V_17 -> V_48 & V_118 ) {
V_26 = F_3 ( V_17 -> V_27 ) ;
V_26 |= 0x3 << 24 ;
F_2 ( V_26 , V_17 -> V_27 ) ;
}
F_30 ( & V_49 , V_48 ) ;
return 0 ;
}
static void F_67 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
unsigned long V_48 ;
F_17 ( L_2 , V_6 , F_18 ( V_13 -> V_35 ) ) ;
if ( ! V_17 -> V_65 . V_109 . V_110 )
return;
V_115 [ V_17 -> V_65 . V_109 . V_110 ] -- ;
if ( V_115 [ V_17 -> V_65 . V_109 . V_110 ] > 0 )
return;
F_29 ( & V_49 , V_48 ) ;
F_2 ( F_64 ( V_17 ) ,
V_119 + F_66 ( V_17 ) ) ;
F_30 ( & V_49 , V_48 ) ;
}
void F_68 ( struct V_12 * V_13 , bool assert )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
unsigned long V_120 = assert ? V_43 : V_44 ;
F_17 ( L_10 , V_6 ,
assert ? L_4 : L_5 , F_18 ( V_13 -> V_35 ) ) ;
F_14 ( ! V_17 -> V_65 . V_109 . V_110 ) ;
if ( ! ( V_17 -> V_48 & V_113 ) )
F_2 ( F_64 ( V_17 ) ,
V_120 + F_66 ( V_17 ) ) ;
}
static int F_69 ( struct V_12 * V_13 , T_3 V_41 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_26 ;
T_1 V_121 ;
T_1 V_37 ;
F_17 ( L_11 , V_6 , F_18 ( V_13 -> V_35 ) , V_41 ) ;
if ( V_17 -> V_48 & V_122 ) {
V_37 = V_123 ;
V_121 = V_124 ;
} else {
V_37 = V_125 ;
V_121 = V_126 ;
}
V_26 = F_3 ( V_17 -> V_27 ) ;
V_26 &= ~ V_121 ;
V_26 |= ( V_41 ) << V_37 ;
F_2 ( V_26 , V_17 -> V_27 ) ;
return 0 ;
}
static T_3 F_70 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_26 = F_3 ( V_17 -> V_27 ) ;
T_1 V_121 ;
T_1 V_37 ;
if ( V_17 -> V_48 & V_122 ) {
V_37 = V_123 ;
V_121 = V_124 ;
} else {
V_37 = V_125 ;
V_121 = V_126 ;
}
if ( V_17 -> V_48 & V_127 )
return ( V_26 & V_121 ) >> V_37 ;
else
return 0 ;
}
static unsigned long F_71 ( struct V_12 * V_13 ,
unsigned long V_15 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
unsigned long V_8 = V_15 ;
T_1 V_26 = F_3 ( V_17 -> V_27 ) ;
if ( V_17 -> V_48 & V_100 ) {
T_1 V_99 = V_26 & V_128 ;
V_17 -> div = V_99 + 2 ;
V_17 -> V_42 = 2 ;
} else if ( V_17 -> V_48 & V_129 ) {
T_1 V_130 = V_26 & V_131 ;
V_17 -> div = V_130 + 1 ;
V_17 -> V_42 = 1 ;
} else {
V_17 -> div = 1 ;
V_17 -> V_42 = 1 ;
return V_8 ;
}
if ( V_17 -> V_42 != 0 && V_17 -> div != 0 ) {
V_8 *= V_17 -> V_42 ;
V_8 += V_17 -> div - 1 ;
F_7 ( V_8 , V_17 -> div ) ;
}
return V_8 ;
}
static int F_72 ( struct V_12 * V_13 , unsigned long V_8 ,
unsigned long V_7 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_26 ;
int V_53 ;
V_26 = F_3 ( V_17 -> V_27 ) ;
if ( V_17 -> V_48 & V_100 ) {
V_53 = F_6 ( V_7 , V_8 ) ;
if ( V_53 >= 0 ) {
V_26 = F_3 ( V_17 -> V_27 ) ;
V_26 &= ~ V_128 ;
V_26 |= V_53 ;
F_2 ( V_26 , V_17 -> V_27 ) ;
V_17 -> div = V_53 + 2 ;
V_17 -> V_42 = 2 ;
return 0 ;
}
} else if ( V_17 -> V_48 & V_129 ) {
V_53 = F_8 ( V_7 , V_8 ) ;
if ( V_53 >= 0 ) {
V_26 = F_3 ( V_17 -> V_27 ) ;
V_26 &= ~ V_131 ;
V_26 |= V_53 ;
F_2 ( V_26 , V_17 -> V_27 ) ;
V_17 -> div = V_53 + 1 ;
V_17 -> V_42 = 1 ;
return 0 ;
}
} else if ( V_7 <= V_8 ) {
V_17 -> div = 1 ;
V_17 -> V_42 = 1 ;
return 0 ;
}
return - V_10 ;
}
static long F_73 ( struct V_12 * V_13 ,
unsigned long V_8 , unsigned long * V_15 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
unsigned long V_7 = F_74 ( F_75 ( V_13 -> V_35 ) ) ;
int V_53 ;
F_17 ( L_7 , V_6 , F_18 ( V_13 -> V_35 ) , V_8 ) ;
if ( V_15 )
V_7 = * V_15 ;
if ( V_17 -> V_48 & V_100 ) {
V_53 = F_6 ( V_7 , V_8 ) ;
if ( V_53 < 0 )
return V_53 ;
return F_42 ( V_7 * 2 , V_53 + 2 ) ;
} else if ( V_17 -> V_48 & V_129 ) {
V_53 = F_8 ( V_7 , V_8 ) ;
if ( V_53 < 0 )
return V_53 ;
return F_42 ( V_7 , V_53 + 1 ) ;
}
return - V_10 ;
}
static void F_76 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
V_17 -> V_94 = F_74 ( V_13 -> V_35 ) ;
}
static long F_77 ( struct V_12 * V_13 , unsigned long V_8 ,
unsigned long * V_15 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
long V_132 ;
long V_133 ;
V_132 = F_78 ( V_8 ) ;
if ( V_132 < 0 )
return V_17 -> V_94 ;
V_133 = F_73 ( V_13 , V_132 , NULL ) ;
F_79 ( V_132 != V_133 ,
L_12 ,
V_132 , V_133 ) ;
return V_132 ;
}
static int F_80 ( struct V_12 * V_13 , unsigned long V_8 ,
unsigned long V_7 )
{
int V_51 ;
V_51 = F_81 ( V_8 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 = F_72 ( V_13 , V_8 , V_7 ) ;
F_45 ( 1 ) ;
return V_51 ;
}
static int F_82 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
V_17 -> V_32 = V_33 ;
if ( ! V_17 -> V_65 . V_109 . V_110 )
goto V_111;
if ( ! ( F_3 ( V_112 + F_63 ( V_17 ) ) &
F_64 ( V_17 ) ) )
V_17 -> V_32 = V_47 ;
V_111:
return V_17 -> V_32 ;
}
static unsigned long F_83 ( struct V_12 * V_13 ,
unsigned long V_15 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_4 V_8 = V_15 ;
V_17 -> V_42 = 2 ;
V_17 -> div = 1 ;
V_8 *= V_17 -> V_42 ;
V_8 += V_17 -> div - 1 ;
F_7 ( V_8 , V_17 -> div ) ;
return V_8 ;
}
static long F_84 ( struct V_12 * V_13 , unsigned long V_8 ,
unsigned long * V_15 )
{
unsigned long V_76 = * V_15 ;
F_7 ( V_76 , 2 ) ;
return V_76 ;
}
static int F_85 ( struct V_12 * V_13 , unsigned long V_8 ,
unsigned long V_7 )
{
if ( V_8 != 2 * V_7 )
return - V_10 ;
return 0 ;
}
static int F_86 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_26 = F_3 ( V_17 -> V_27 ) ;
V_17 -> V_32 = ( V_26 & ( 1 << 4 ) ) ? V_47 : V_33 ;
return V_17 -> V_32 ;
}
static int F_87 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
F_2 ( 0 , V_17 -> V_27 ) ;
return 0 ;
}
static void F_88 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
F_2 ( 1 , V_17 -> V_27 ) ;
}
static T_3 F_89 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_26 = F_3 ( V_17 -> V_27 ) ;
int V_36 ;
V_36 = V_26 & 0xf ;
return V_36 ;
}
static int F_90 ( struct V_12 * V_13 , T_3 V_41 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
T_1 V_26 ;
V_26 = F_3 ( V_17 -> V_27 ) ;
V_26 &= ~ 0xf ;
V_26 |= V_41 ;
F_2 ( V_26 , V_17 -> V_27 ) ;
return 0 ;
}
static int F_91 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
V_17 -> V_32 = V_33 ;
F_14 ( ! V_17 -> V_65 . V_109 . V_110 ) ;
if ( ! ( F_3 ( V_112 + F_63 ( V_17 ) ) &
F_64 ( V_17 ) ) )
V_17 -> V_32 = V_47 ;
return V_17 -> V_32 ;
}
static int F_92 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
F_14 ( ! V_17 -> V_65 . V_109 . V_110 ) ;
F_2 ( F_64 ( V_17 ) ,
V_116 + F_66 ( V_17 ) ) ;
return 0 ;
}
static void F_93 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
F_14 ( ! V_17 -> V_65 . V_109 . V_110 ) ;
F_2 ( F_64 ( V_17 ) ,
V_119 + F_66 ( V_17 ) ) ;
}
static unsigned long F_94 ( struct V_12 * V_13 ,
unsigned long V_15 )
{
return F_10 ( V_13 ) -> V_14 ;
}
static void F_95 ( T_1 V_134 )
{
unsigned int V_27 ;
do {
V_27 = F_96 ( V_135 +
V_136 ) ;
F_97 () ;
} while ( ! ( V_27 & ( 1 << V_134 ) ) );
return;
}
static void F_98 ( T_1 V_134 )
{
F_99 ( F_100 ( V_134 ) ,
V_135 + V_136 ) ;
F_101 () ;
}
static void F_102 ( T_1 V_134 )
{
F_99 ( F_100 ( V_134 ) ,
V_135 + V_137 ) ;
F_103 () ;
}
static void F_104 ( T_1 V_134 )
{
unsigned int V_27 ;
V_27 = F_96 ( V_135 + V_138 ) ;
F_99 ( V_27 & ~ F_105 ( V_134 ) ,
V_135 + V_138 ) ;
F_106 () ;
V_27 = F_96 ( V_135 + V_138 ) ;
}
static void F_107 ( T_1 V_134 )
{
unsigned int V_27 ;
V_27 = F_96 ( V_135 + V_138 ) ;
F_99 ( V_27 | F_105 ( V_134 ) ,
V_135 + V_138 ) ;
}
void T_5 F_108 ( void )
{
V_139 = & V_140 ;
}
