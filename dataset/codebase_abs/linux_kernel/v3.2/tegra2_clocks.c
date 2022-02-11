unsigned long F_1 ( void )
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
F_4 ( L_1 , V_6 , V_1 ) ;
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
if ( V_11 - 1 > 255 )
return - V_10 ;
return V_11 - 1 ;
}
static unsigned long F_9 ( struct V_12 * V_13 )
{
T_1 V_14 = F_3 ( V_15 ) & ~ V_16 ;
V_13 -> V_8 = F_1 () ;
switch ( V_13 -> V_8 ) {
case 12000000 :
V_14 |= V_17 ;
break;
case 13000000 :
V_14 |= V_18 ;
break;
case 19200000 :
V_14 |= V_19 ;
break;
case 26000000 :
V_14 |= V_20 ;
break;
default:
F_4 ( L_2 , V_6 , V_13 -> V_8 ) ;
F_5 () ;
}
F_2 ( V_14 , V_15 ) ;
return V_13 -> V_8 ;
}
static void F_10 ( struct V_12 * V_13 )
{
F_11 ( L_3 , V_6 , V_13 -> V_21 ) ;
F_9 ( V_13 ) ;
}
static int F_12 ( struct V_12 * V_13 )
{
F_11 ( L_3 , V_6 , V_13 -> V_21 ) ;
return 0 ;
}
static void F_13 ( struct V_12 * V_13 )
{
F_11 ( L_3 , V_6 , V_13 -> V_21 ) ;
F_5 () ;
}
void F_14 ( struct V_12 * V_13 )
{
F_15 ( ! V_13 -> V_22 -> V_23 ) ;
V_13 -> V_22 -> V_23 ( V_13 , true ) ;
}
void F_16 ( struct V_12 * V_13 )
{
F_15 ( ! V_13 -> V_22 -> V_23 ) ;
V_13 -> V_22 -> V_23 ( V_13 , false ) ;
}
static void F_17 ( struct V_12 * V_13 )
{
T_1 V_24 ;
int V_25 ;
int V_26 ;
const struct V_27 * V_28 ;
V_24 = F_3 ( V_13 -> V_29 + V_30 ) ;
V_13 -> V_31 = V_32 ;
F_15 ( ( ( V_24 & V_33 ) != V_34 ) &&
( ( V_24 & V_33 ) != V_35 ) ) ;
V_26 = ( ( V_24 & V_33 ) == V_35 ) ?
V_36 : V_37 ;
V_25 = ( V_24 >> V_26 ) & V_38 ;
for ( V_28 = V_13 -> V_39 ; V_28 -> V_40 != NULL ; V_28 ++ ) {
if ( V_28 -> V_41 == V_25 )
break;
}
F_15 ( V_28 -> V_40 == NULL ) ;
V_13 -> V_42 = V_28 -> V_40 ;
}
static int F_18 ( struct V_12 * V_13 )
{
F_2 ( 0 , V_13 -> V_29 + V_43 ) ;
return 0 ;
}
static void F_19 ( struct V_12 * V_13 )
{
F_11 ( L_3 , V_6 , V_13 -> V_21 ) ;
F_5 () ;
}
static int F_20 ( struct V_12 * V_13 , struct V_12 * V_44 )
{
T_1 V_24 ;
const struct V_27 * V_28 ;
int V_26 ;
V_24 = F_3 ( V_13 -> V_29 + V_30 ) ;
F_15 ( ( ( V_24 & V_33 ) != V_34 ) &&
( ( V_24 & V_33 ) != V_35 ) ) ;
V_26 = ( ( V_24 & V_33 ) == V_35 ) ?
V_36 : V_37 ;
for ( V_28 = V_13 -> V_39 ; V_28 -> V_40 != NULL ; V_28 ++ ) {
if ( V_28 -> V_40 == V_44 ) {
V_24 &= ~ ( V_38 << V_26 ) ;
V_24 |= V_28 -> V_41 << V_26 ;
if ( V_13 -> V_45 )
F_21 ( V_44 ) ;
F_2 ( V_24 , V_13 -> V_29 ) ;
if ( V_13 -> V_45 && V_13 -> V_42 )
F_22 ( V_13 -> V_42 ) ;
F_23 ( V_13 , V_44 ) ;
return 0 ;
}
}
return - V_10 ;
}
static int F_24 ( struct V_12 * V_13 , unsigned long V_8 )
{
return F_25 ( V_13 -> V_42 , V_8 ) ;
}
static void F_26 ( struct V_12 * V_13 )
{
}
static int F_27 ( struct V_12 * V_13 )
{
return 0 ;
}
static void F_28 ( struct V_12 * V_13 )
{
F_11 ( L_3 , V_6 , V_13 -> V_21 ) ;
F_5 () ;
}
static int F_29 ( struct V_12 * V_13 , unsigned long V_8 )
{
int V_46 ;
F_21 ( V_13 -> V_47 . V_48 . main ) ;
V_46 = F_30 ( V_13 -> V_42 , V_13 -> V_47 . V_48 . V_49 ) ;
if ( V_46 ) {
F_4 ( L_4 , V_13 -> V_47 . V_48 . V_49 -> V_21 ) ;
goto V_50;
}
if ( V_8 == F_31 ( V_13 -> V_47 . V_48 . V_49 ) )
goto V_50;
V_46 = F_25 ( V_13 -> V_47 . V_48 . main , V_8 ) ;
if ( V_46 ) {
F_4 ( L_5 , V_8 ) ;
goto V_50;
}
V_46 = F_30 ( V_13 -> V_42 , V_13 -> V_47 . V_48 . main ) ;
if ( V_46 ) {
F_4 ( L_4 , V_13 -> V_47 . V_48 . main-> V_21 ) ;
goto V_50;
}
V_50:
F_22 ( V_13 -> V_47 . V_48 . main ) ;
return V_46 ;
}
static void F_32 ( struct V_12 * V_13 , bool assert )
{
unsigned long V_29 = assert ? V_51 : V_52 ;
F_11 ( L_6 , V_6 , assert ? L_7 : L_8 ) ;
F_2 ( 1 << 1 , V_29 ) ;
}
static void F_33 ( struct V_12 * V_13 )
{
T_1 V_24 = F_3 ( V_13 -> V_29 ) ;
V_13 -> V_31 = ( ( V_24 >> V_13 -> V_53 ) & V_54 ) ? V_55 : V_32 ;
V_13 -> div = ( ( V_24 >> V_13 -> V_53 ) & V_56 ) + 1 ;
V_13 -> V_57 = 1 ;
}
static int F_34 ( struct V_12 * V_13 )
{
T_1 V_24 ;
unsigned long V_58 ;
F_35 ( & V_59 , V_58 ) ;
V_24 = F_3 ( V_13 -> V_29 ) ;
V_24 &= ~ ( V_54 << V_13 -> V_53 ) ;
F_2 ( V_24 , V_13 -> V_29 ) ;
F_36 ( & V_59 , V_58 ) ;
return 0 ;
}
static void F_37 ( struct V_12 * V_13 )
{
T_1 V_24 ;
unsigned long V_58 ;
F_35 ( & V_59 , V_58 ) ;
V_24 = F_3 ( V_13 -> V_29 ) ;
V_24 |= V_54 << V_13 -> V_53 ;
F_2 ( V_24 , V_13 -> V_29 ) ;
F_36 ( & V_59 , V_58 ) ;
}
static int F_38 ( struct V_12 * V_13 , unsigned long V_8 )
{
T_1 V_24 ;
unsigned long V_7 = F_31 ( V_13 -> V_42 ) ;
unsigned long V_58 ;
int V_46 = - V_10 ;
int V_60 ;
F_35 ( & V_59 , V_58 ) ;
V_24 = F_3 ( V_13 -> V_29 ) ;
for ( V_60 = 1 ; V_60 <= 4 ; V_60 ++ ) {
if ( V_8 == V_7 / V_60 ) {
V_24 &= ~ ( V_56 << V_13 -> V_53 ) ;
V_24 |= ( V_60 - 1 ) << V_13 -> V_53 ;
F_2 ( V_24 , V_13 -> V_29 ) ;
V_13 -> div = V_60 ;
V_13 -> V_57 = 1 ;
V_46 = 0 ;
break;
}
}
F_36 ( & V_59 , V_58 ) ;
return V_46 ;
}
static void F_39 ( struct V_12 * V_13 )
{
T_1 V_24 ;
V_24 = F_40 ( V_61 ) ;
V_13 -> V_31 = ( V_24 & V_62 ) ? V_32 : V_55 ;
V_13 -> V_57 = 1 ;
V_24 = F_40 ( V_13 -> V_29 ) ;
if ( V_24 & V_63 ) {
unsigned int V_64 ;
V_64 = ( V_24 >> V_65 ) &
V_66 ;
V_24 >>= V_67 ;
V_24 &= V_68 ;
V_64 += V_24 ;
V_13 -> div = V_64 * 4 ;
} else {
V_13 -> div = 1 ;
}
}
static int F_41 ( struct V_12 * V_13 )
{
T_1 V_24 ;
V_24 = F_40 ( V_69 ) ;
F_42 ( V_24 | V_70 , V_69 ) ;
V_24 = F_40 ( V_61 ) ;
F_42 ( V_24 | V_62 , V_61 ) ;
return 0 ;
}
static void F_43 ( struct V_12 * V_13 )
{
T_1 V_24 ;
V_24 = F_40 ( V_61 ) ;
F_42 ( V_24 & ~ V_62 , V_61 ) ;
V_24 = F_40 ( V_69 ) ;
F_42 ( V_24 & ~ V_70 , V_69 ) ;
}
static int F_44 ( struct V_12 * V_13 , unsigned long V_8 )
{
unsigned long V_7 = F_31 ( V_13 -> V_42 ) ;
if ( V_8 >= V_7 ) {
V_13 -> div = 1 ;
F_42 ( 0 , V_13 -> V_29 ) ;
} else {
unsigned int V_64 ;
T_1 V_24 ;
V_64 = F_45 ( V_7 / 8 , V_8 ) ;
V_13 -> div = V_64 * 8 ;
V_24 = ( V_64 & V_66 ) <<
V_65 ;
V_64 &= V_68 ;
V_64 <<= V_67 ;
V_24 |= V_64 ;
V_24 |= V_63 ;
F_42 ( V_24 , V_13 -> V_29 ) ;
}
return 0 ;
}
static int F_46 ( struct V_12 * V_13 )
{
F_47 ( V_13 -> V_47 . V_71 . V_72 ) ;
return 0 ;
}
static void F_48 ( struct V_12 * V_13 )
{
T_1 V_24 = F_3 ( V_13 -> V_29 + V_73 ) ;
V_13 -> V_31 = ( V_24 & V_74 ) ? V_32 : V_55 ;
if ( V_13 -> V_58 & V_75 && ! ( V_24 & V_76 ) ) {
F_49 ( L_9 , V_13 -> V_21 ) ;
V_13 -> V_57 = 1 ;
V_13 -> div = 1 ;
} else if ( V_24 & V_77 ) {
V_13 -> V_57 = 1 ;
V_13 -> div = 1 ;
} else {
V_13 -> V_57 = ( V_24 & V_78 ) >> V_79 ;
V_13 -> div = ( V_24 & V_80 ) >> V_81 ;
if ( V_13 -> V_58 & V_82 )
V_13 -> div *= ( V_24 & V_83 ) ? 1 : 2 ;
else
V_13 -> div *= ( V_24 & V_84 ) ? 2 : 1 ;
}
}
static int F_50 ( struct V_12 * V_13 )
{
T_1 V_24 ;
F_11 ( L_3 , V_6 , V_13 -> V_21 ) ;
V_24 = F_3 ( V_13 -> V_29 + V_73 ) ;
V_24 &= ~ V_77 ;
V_24 |= V_74 ;
F_2 ( V_24 , V_13 -> V_29 + V_73 ) ;
F_46 ( V_13 ) ;
return 0 ;
}
static void F_51 ( struct V_12 * V_13 )
{
T_1 V_24 ;
F_11 ( L_3 , V_6 , V_13 -> V_21 ) ;
V_24 = F_3 ( V_13 -> V_29 ) ;
V_24 &= ~ ( V_77 | V_74 ) ;
F_2 ( V_24 , V_13 -> V_29 ) ;
}
static int F_52 ( struct V_12 * V_13 , unsigned long V_8 )
{
T_1 V_24 ;
unsigned long V_85 ;
const struct V_86 * V_28 ;
F_11 ( L_10 , V_6 , V_13 -> V_21 , V_8 ) ;
V_85 = F_31 ( V_13 -> V_42 ) ;
for ( V_28 = V_13 -> V_47 . V_71 . V_87 ; V_28 -> V_85 != 0 ; V_28 ++ ) {
if ( V_28 -> V_85 == V_85 && V_28 -> V_88 == V_8 ) {
V_13 -> V_57 = V_28 -> V_89 ;
V_13 -> div = V_28 -> V_90 * V_28 -> V_44 ;
V_24 = F_3 ( V_13 -> V_29 + V_73 ) ;
if ( V_13 -> V_58 & V_75 )
V_24 |= V_76 ;
V_24 &= ~ ( V_84 | V_78 |
V_80 ) ;
V_24 |= ( V_28 -> V_90 << V_81 ) |
( V_28 -> V_89 << V_79 ) ;
F_15 ( V_28 -> V_44 < 1 || V_28 -> V_44 > 2 ) ;
if ( V_13 -> V_58 & V_82 ) {
if ( V_28 -> V_44 == 1 )
V_24 |= V_83 ;
} else {
if ( V_28 -> V_44 == 2 )
V_24 |= 1 << V_91 ;
}
F_2 ( V_24 , V_13 -> V_29 + V_73 ) ;
if ( V_13 -> V_58 & V_92 ) {
V_24 = F_3 ( V_13 -> V_29 + F_53 ( V_13 ) ) ;
V_24 &= ~ V_93 ;
V_24 |= V_28 -> V_94 << V_95 ;
F_2 ( V_24 , V_13 -> V_29 + F_53 ( V_13 ) ) ;
}
if ( V_13 -> V_31 == V_32 )
F_50 ( V_13 ) ;
return 0 ;
}
}
return - V_10 ;
}
static void F_54 ( struct V_12 * V_13 )
{
F_48 ( V_13 ) ;
if ( F_55 () == 7 )
V_13 -> V_96 = 750000000 ;
}
static int F_56 ( struct V_12 * V_13 )
{
T_1 V_24 ;
F_11 ( L_3 , V_6 , V_13 -> V_21 ) ;
F_57 ( 1 ) ;
V_24 = F_3 ( V_13 -> V_29 + V_73 ) ;
if ( ! ( V_24 & V_97 ) )
return - V_98 ;
V_24 = F_3 ( V_13 -> V_29 + V_73 ) ;
V_24 |= V_74 | V_77 ;
F_2 ( V_24 , V_13 -> V_29 + V_73 ) ;
return 0 ;
}
static void F_58 ( struct V_12 * V_13 )
{
T_1 V_24 = F_3 ( V_13 -> V_29 ) ;
T_1 V_99 ;
V_24 >>= V_13 -> V_53 ;
V_13 -> V_31 = ( V_24 & V_100 ) ? V_32 : V_55 ;
if ( ! ( V_24 & V_101 ) )
V_13 -> V_31 = V_55 ;
if ( V_13 -> V_58 & V_102 ) {
V_99 = ( V_24 & V_103 ) >> V_104 ;
V_13 -> div = ( V_99 + 2 ) ;
V_13 -> V_57 = 2 ;
} else if ( V_13 -> V_58 & V_105 ) {
V_13 -> div = 2 ;
V_13 -> V_57 = 1 ;
} else {
V_13 -> div = 1 ;
V_13 -> V_57 = 1 ;
}
}
static int F_59 ( struct V_12 * V_13 )
{
T_1 V_24 ;
T_1 V_106 ;
unsigned long V_58 ;
F_11 ( L_11 , V_6 , V_13 -> V_21 ) ;
if ( V_13 -> V_58 & V_102 ) {
F_35 ( & V_59 , V_58 ) ;
V_24 = F_3 ( V_13 -> V_29 ) ;
V_106 = V_24 >> V_13 -> V_53 ;
V_106 &= 0xFFFF ;
V_106 |= V_100 | V_101 ;
V_24 &= ~ ( 0xFFFF << V_13 -> V_53 ) ;
V_24 |= V_106 << V_13 -> V_53 ;
F_2 ( V_24 , V_13 -> V_29 ) ;
F_36 ( & V_59 , V_58 ) ;
return 0 ;
} else if ( V_13 -> V_58 & V_105 ) {
F_15 ( ! ( V_13 -> V_58 & V_107 ) ) ;
F_35 ( & V_59 , V_58 ) ;
V_24 = F_3 ( V_13 -> V_29 ) ;
V_24 &= ~ V_108 ;
F_2 ( V_24 , V_13 -> V_29 ) ;
F_36 ( & V_59 , V_58 ) ;
return 0 ;
}
return - V_10 ;
}
static void F_60 ( struct V_12 * V_13 )
{
T_1 V_24 ;
T_1 V_106 ;
unsigned long V_58 ;
F_11 ( L_11 , V_6 , V_13 -> V_21 ) ;
if ( V_13 -> V_58 & V_102 ) {
F_35 ( & V_59 , V_58 ) ;
V_24 = F_3 ( V_13 -> V_29 ) ;
V_106 = V_24 >> V_13 -> V_53 ;
V_106 &= 0xFFFF ;
V_106 &= ~ ( V_100 | V_101 ) ;
V_24 &= ~ ( 0xFFFF << V_13 -> V_53 ) ;
V_24 |= V_106 << V_13 -> V_53 ;
F_2 ( V_24 , V_13 -> V_29 ) ;
F_36 ( & V_59 , V_58 ) ;
} else if ( V_13 -> V_58 & V_105 ) {
F_15 ( ! ( V_13 -> V_58 & V_107 ) ) ;
F_35 ( & V_59 , V_58 ) ;
V_24 = F_3 ( V_13 -> V_29 ) ;
V_24 |= V_108 ;
F_2 ( V_24 , V_13 -> V_29 ) ;
F_36 ( & V_59 , V_58 ) ;
}
}
static int F_61 ( struct V_12 * V_13 , unsigned long V_8 )
{
T_1 V_24 ;
T_1 V_106 ;
int V_9 ;
unsigned long V_7 = F_31 ( V_13 -> V_42 ) ;
unsigned long V_58 ;
F_11 ( L_10 , V_6 , V_13 -> V_21 , V_8 ) ;
if ( V_13 -> V_58 & V_102 ) {
V_9 = F_6 ( V_7 , V_8 ) ;
if ( V_9 >= 0 ) {
F_35 ( & V_59 , V_58 ) ;
V_24 = F_3 ( V_13 -> V_29 ) ;
V_106 = V_24 >> V_13 -> V_53 ;
V_106 &= 0xFFFF ;
if ( V_13 -> V_58 & V_109 )
V_106 |= V_110 ;
V_106 &= ~ V_103 ;
V_106 |= V_9 << V_104 ;
V_24 &= ~ ( 0xFFFF << V_13 -> V_53 ) ;
V_24 |= V_106 << V_13 -> V_53 ;
F_2 ( V_24 , V_13 -> V_29 ) ;
V_13 -> div = V_9 + 2 ;
V_13 -> V_57 = 2 ;
F_36 ( & V_59 , V_58 ) ;
return 0 ;
}
} else if ( V_13 -> V_58 & V_105 ) {
if ( V_7 == V_8 * 2 )
return 0 ;
}
return - V_10 ;
}
static long F_62 ( struct V_12 * V_13 , unsigned long V_8 )
{
int V_111 ;
unsigned long V_7 = F_31 ( V_13 -> V_42 ) ;
F_11 ( L_10 , V_6 , V_13 -> V_21 , V_8 ) ;
if ( V_13 -> V_58 & V_102 ) {
V_111 = F_6 ( V_7 , V_8 ) ;
if ( V_111 < 0 )
return V_111 ;
return F_45 ( V_7 * 2 , V_111 + 2 ) ;
} else if ( V_13 -> V_58 & V_105 ) {
return F_45 ( V_7 , 2 ) ;
}
return - V_10 ;
}
static void F_63 ( struct V_12 * V_13 )
{
T_1 V_24 = F_3 ( V_13 -> V_29 ) ;
const struct V_27 * V_112 = NULL ;
const struct V_27 * V_28 ;
if ( V_13 -> V_58 & V_113 ) {
for ( V_28 = V_13 -> V_39 ; V_28 -> V_40 != NULL ; V_28 ++ ) {
if ( V_24 >> V_114 == V_28 -> V_41 )
V_112 = V_28 ;
}
F_15 ( ! V_112 ) ;
V_13 -> V_42 = V_112 -> V_40 ;
} else {
V_13 -> V_42 = V_13 -> V_39 [ 0 ] . V_40 ;
}
if ( V_13 -> V_58 & V_102 ) {
T_1 V_99 = V_24 & V_115 ;
V_13 -> div = V_99 + 2 ;
V_13 -> V_57 = 2 ;
} else if ( V_13 -> V_58 & V_116 ) {
T_1 V_117 = V_24 & V_118 ;
V_13 -> div = V_117 + 1 ;
V_13 -> V_57 = 1 ;
} else {
V_13 -> div = 1 ;
V_13 -> V_57 = 1 ;
}
V_13 -> V_31 = V_32 ;
if ( ! V_13 -> V_47 . V_119 . V_120 )
return;
if ( ! ( F_3 ( V_121 + F_64 ( V_13 ) ) &
F_65 ( V_13 ) ) )
V_13 -> V_31 = V_55 ;
if ( ! ( V_13 -> V_58 & V_122 ) )
if ( F_3 ( V_123 + F_64 ( V_13 ) ) &
F_65 ( V_13 ) )
V_13 -> V_31 = V_55 ;
}
static int F_66 ( struct V_12 * V_13 )
{
T_1 V_24 ;
unsigned long V_58 ;
int V_124 ;
F_11 ( L_3 , V_6 , V_13 -> V_21 ) ;
if ( ! V_13 -> V_47 . V_119 . V_120 )
return 0 ;
F_35 ( & V_59 , V_58 ) ;
V_124 = V_125 [ V_13 -> V_47 . V_119 . V_120 ] ++ ;
if ( V_124 > 1 )
goto V_50;
F_2 ( F_65 ( V_13 ) ,
V_126 + F_67 ( V_13 ) ) ;
if ( ! ( V_13 -> V_58 & V_122 ) && ! ( V_13 -> V_58 & V_127 ) )
F_2 ( F_65 ( V_13 ) ,
V_52 + F_67 ( V_13 ) ) ;
if ( V_13 -> V_58 & V_128 ) {
V_24 = F_3 ( V_13 -> V_29 ) ;
V_24 |= 0x3 << 24 ;
F_2 ( V_24 , V_13 -> V_29 ) ;
}
V_50:
F_36 ( & V_59 , V_58 ) ;
return 0 ;
}
static void F_68 ( struct V_12 * V_13 )
{
unsigned long V_58 ;
F_11 ( L_3 , V_6 , V_13 -> V_21 ) ;
if ( ! V_13 -> V_47 . V_119 . V_120 )
return;
F_35 ( & V_59 , V_58 ) ;
if ( V_13 -> V_45 )
V_125 [ V_13 -> V_47 . V_119 . V_120 ] -- ;
if ( V_125 [ V_13 -> V_47 . V_119 . V_120 ] == 0 )
F_2 ( F_65 ( V_13 ) ,
V_129 + F_67 ( V_13 ) ) ;
F_36 ( & V_59 , V_58 ) ;
}
static void F_69 ( struct V_12 * V_13 , bool assert )
{
unsigned long V_130 = assert ? V_51 : V_52 ;
F_11 ( L_12 , V_6 ,
assert ? L_7 : L_8 , V_13 -> V_21 ) ;
F_15 ( ! V_13 -> V_47 . V_119 . V_120 ) ;
if ( ! ( V_13 -> V_58 & V_122 ) )
F_2 ( F_65 ( V_13 ) ,
V_130 + F_67 ( V_13 ) ) ;
}
static int F_70 ( struct V_12 * V_13 , struct V_12 * V_44 )
{
T_1 V_24 ;
const struct V_27 * V_28 ;
F_11 ( L_13 , V_6 , V_13 -> V_21 , V_44 -> V_21 ) ;
for ( V_28 = V_13 -> V_39 ; V_28 -> V_40 != NULL ; V_28 ++ ) {
if ( V_28 -> V_40 == V_44 ) {
V_24 = F_3 ( V_13 -> V_29 ) ;
V_24 &= ~ V_131 ;
V_24 |= ( V_28 -> V_41 ) << V_114 ;
if ( V_13 -> V_45 )
F_21 ( V_44 ) ;
F_2 ( V_24 , V_13 -> V_29 ) ;
if ( V_13 -> V_45 && V_13 -> V_42 )
F_22 ( V_13 -> V_42 ) ;
F_23 ( V_13 , V_44 ) ;
return 0 ;
}
}
return - V_10 ;
}
static int F_71 ( struct V_12 * V_13 , unsigned long V_8 )
{
T_1 V_24 ;
int V_111 ;
unsigned long V_7 = F_31 ( V_13 -> V_42 ) ;
if ( V_13 -> V_58 & V_102 ) {
V_111 = F_6 ( V_7 , V_8 ) ;
if ( V_111 >= 0 ) {
V_24 = F_3 ( V_13 -> V_29 ) ;
V_24 &= ~ V_115 ;
V_24 |= V_111 ;
F_2 ( V_24 , V_13 -> V_29 ) ;
V_13 -> div = V_111 + 2 ;
V_13 -> V_57 = 2 ;
return 0 ;
}
} else if ( V_13 -> V_58 & V_116 ) {
V_111 = F_8 ( V_7 , V_8 ) ;
if ( V_111 >= 0 ) {
V_24 = F_3 ( V_13 -> V_29 ) ;
V_24 &= ~ V_118 ;
V_24 |= V_111 ;
F_2 ( V_24 , V_13 -> V_29 ) ;
V_13 -> div = V_111 + 1 ;
V_13 -> V_57 = 1 ;
return 0 ;
}
} else if ( V_7 <= V_8 ) {
V_13 -> div = 1 ;
V_13 -> V_57 = 1 ;
return 0 ;
}
return - V_10 ;
}
static long F_72 ( struct V_12 * V_13 ,
unsigned long V_8 )
{
int V_111 ;
unsigned long V_7 = F_31 ( V_13 -> V_42 ) ;
F_11 ( L_10 , V_6 , V_13 -> V_21 , V_8 ) ;
if ( V_13 -> V_58 & V_102 ) {
V_111 = F_6 ( V_7 , V_8 ) ;
if ( V_111 < 0 )
return V_111 ;
return F_45 ( V_7 * 2 , V_111 + 2 ) ;
} else if ( V_13 -> V_58 & V_116 ) {
V_111 = F_8 ( V_7 , V_8 ) ;
if ( V_111 < 0 )
return V_111 ;
return F_45 ( V_7 , V_111 + 1 ) ;
}
return - V_10 ;
}
void F_73 ( struct V_12 * V_13 , int V_132 )
{
T_1 V_29 ;
V_132 = F_74 ( V_132 , 0 , 15 ) ;
V_29 = F_3 ( V_13 -> V_29 ) ;
V_29 &= ~ V_133 ;
V_29 |= V_134 ;
V_29 |= V_132 << V_135 ;
F_2 ( V_29 , V_13 -> V_29 ) ;
}
static void F_75 ( struct V_12 * V_13 )
{
F_63 ( V_13 ) ;
V_13 -> V_96 = F_76 ( V_13 ) ;
}
static long F_77 ( struct V_12 * V_13 , unsigned long V_8 )
{
long V_136 = V_8 ;
V_136 = F_78 ( V_136 ) ;
if ( V_136 < 0 )
return V_13 -> V_96 ;
F_15 ( V_136 != F_72 ( V_13 , V_136 ) ) ;
return V_136 ;
}
static int F_79 ( struct V_12 * V_13 , unsigned long V_8 )
{
int V_46 ;
V_46 = F_80 ( V_8 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_71 ( V_13 , V_8 ) ;
F_47 ( 1 ) ;
return V_46 ;
}
static void F_81 ( struct V_12 * V_13 )
{
V_13 -> V_57 = 2 ;
V_13 -> div = 1 ;
V_13 -> V_31 = V_32 ;
if ( ! V_13 -> V_47 . V_119 . V_120 )
return;
if ( ! ( F_3 ( V_121 + F_64 ( V_13 ) ) &
F_65 ( V_13 ) ) )
V_13 -> V_31 = V_55 ;
}
static int F_82 ( struct V_12 * V_13 , unsigned long V_8 )
{
if ( V_8 != 2 * F_31 ( V_13 -> V_42 ) )
return - V_10 ;
V_13 -> V_57 = 2 ;
V_13 -> div = 1 ;
return 0 ;
}
static void F_83 ( struct V_12 * V_13 )
{
int V_25 ;
const struct V_27 * V_28 ;
T_1 V_24 = F_3 ( V_13 -> V_29 ) ;
V_13 -> V_31 = ( V_24 & ( 1 << 4 ) ) ? V_55 : V_32 ;
V_25 = V_24 & 0xf ;
for ( V_28 = V_13 -> V_39 ; V_28 -> V_40 != NULL ; V_28 ++ )
if ( V_28 -> V_41 == V_25 )
break;
F_15 ( V_28 -> V_40 == NULL ) ;
V_13 -> V_42 = V_28 -> V_40 ;
}
static int F_84 ( struct V_12 * V_13 )
{
F_2 ( 0 , V_13 -> V_29 ) ;
return 0 ;
}
static void F_85 ( struct V_12 * V_13 )
{
F_2 ( 1 , V_13 -> V_29 ) ;
}
static int F_86 ( struct V_12 * V_13 , struct V_12 * V_44 )
{
T_1 V_24 ;
const struct V_27 * V_28 ;
for ( V_28 = V_13 -> V_39 ; V_28 -> V_40 != NULL ; V_28 ++ ) {
if ( V_28 -> V_40 == V_44 ) {
V_24 = F_3 ( V_13 -> V_29 ) ;
V_24 &= ~ 0xf ;
V_24 |= V_28 -> V_41 ;
if ( V_13 -> V_45 )
F_21 ( V_44 ) ;
F_2 ( V_24 , V_13 -> V_29 ) ;
if ( V_13 -> V_45 && V_13 -> V_42 )
F_22 ( V_13 -> V_42 ) ;
F_23 ( V_13 , V_44 ) ;
return 0 ;
}
}
return - V_10 ;
}
static void F_87 ( struct V_12 * V_13 )
{
V_13 -> V_31 = V_32 ;
F_15 ( ! V_13 -> V_47 . V_119 . V_120 ) ;
if ( ! ( F_3 ( V_121 + F_64 ( V_13 ) ) &
F_65 ( V_13 ) ) )
V_13 -> V_31 = V_55 ;
}
static int F_88 ( struct V_12 * V_13 )
{
F_15 ( ! V_13 -> V_47 . V_119 . V_120 ) ;
F_2 ( F_65 ( V_13 ) ,
V_126 + F_67 ( V_13 ) ) ;
return 0 ;
}
static void F_89 ( struct V_12 * V_13 )
{
F_15 ( ! V_13 -> V_47 . V_119 . V_120 ) ;
F_2 ( F_65 ( V_13 ) ,
V_129 + F_67 ( V_13 ) ) ;
}
static int F_90 ( struct V_12 * V_137 )
{
struct V_12 * V_13 ;
unsigned long V_8 = V_137 -> V_138 ;
F_91 (c, &bus->shared_bus_list, u.shared_bus_user.node)
if ( V_13 -> V_47 . V_139 . V_140 )
V_8 = F_92 ( V_13 -> V_47 . V_139 . V_8 , V_8 ) ;
if ( V_8 == F_76 ( V_137 ) )
return 0 ;
return F_93 ( V_137 , V_8 ) ;
}
static void F_94 ( struct V_12 * V_13 )
{
unsigned long V_58 ;
V_13 -> V_96 = V_13 -> V_42 -> V_96 ;
V_13 -> V_47 . V_139 . V_8 = V_13 -> V_42 -> V_96 ;
V_13 -> V_31 = V_55 ;
V_13 -> V_141 = true ;
F_35 ( & V_13 -> V_42 -> V_142 , V_58 ) ;
F_95 ( & V_13 -> V_47 . V_139 . V_143 ,
& V_13 -> V_42 -> V_144 ) ;
F_36 ( & V_13 -> V_42 -> V_142 , V_58 ) ;
}
static int F_96 ( struct V_12 * V_13 , unsigned long V_8 )
{
unsigned long V_58 ;
int V_46 ;
long V_136 = V_8 ;
V_136 = F_97 ( V_13 -> V_42 , V_136 ) ;
if ( V_136 < 0 )
return V_136 ;
F_35 ( & V_13 -> V_42 -> V_142 , V_58 ) ;
V_13 -> V_47 . V_139 . V_8 = V_136 ;
V_46 = F_90 ( V_13 -> V_42 ) ;
F_36 ( & V_13 -> V_42 -> V_142 , V_58 ) ;
return V_46 ;
}
static long F_98 ( struct V_12 * V_13 , unsigned long V_8 )
{
return F_97 ( V_13 -> V_42 , V_8 ) ;
}
static int F_99 ( struct V_12 * V_13 )
{
unsigned long V_58 ;
int V_46 ;
F_35 ( & V_13 -> V_42 -> V_142 , V_58 ) ;
V_13 -> V_47 . V_139 . V_140 = true ;
V_46 = F_90 ( V_13 -> V_42 ) ;
F_36 ( & V_13 -> V_42 -> V_142 , V_58 ) ;
return V_46 ;
}
static void F_100 ( struct V_12 * V_13 )
{
unsigned long V_58 ;
int V_46 ;
F_35 ( & V_13 -> V_42 -> V_142 , V_58 ) ;
V_13 -> V_47 . V_139 . V_140 = false ;
V_46 = F_90 ( V_13 -> V_42 ) ;
F_101 ( V_46 ) ;
F_36 ( & V_13 -> V_42 -> V_142 , V_58 ) ;
}
static void F_102 ( void )
{
int V_60 ;
struct V_27 * V_28 = V_145 ;
const struct V_146 * V_147 = V_148 ;
struct V_149 * V_150 ;
for ( V_60 = 0 ; V_147 -> V_21 ; V_60 ++ , V_28 ++ , V_147 ++ ) {
V_28 -> V_40 = F_103 ( V_147 -> V_21 ) ;
if ( ! V_28 -> V_40 )
F_4 ( L_14 , V_6 ,
V_147 -> V_21 ) ;
V_28 -> V_41 = V_147 -> V_41 ;
}
V_150 = V_151 ;
for ( V_60 = 0 ; V_60 < F_104 ( V_151 ) ; V_60 ++ , V_150 ++ ) {
F_105 ( V_150 -> V_12 ) ;
F_106 ( V_150 ) ;
}
}
static void F_107 ( struct V_12 * V_13 )
{
F_105 ( V_13 ) ;
F_108 ( & V_13 -> V_144 ) ;
if ( ! V_13 -> V_150 . V_152 && ! V_13 -> V_150 . V_153 )
V_13 -> V_150 . V_153 = V_13 -> V_21 ;
V_13 -> V_150 . V_12 = V_13 ;
F_106 ( & V_13 -> V_150 ) ;
}
void T_3 F_109 ( void )
{
int V_60 ;
struct V_12 * V_13 ;
for ( V_60 = 0 ; V_60 < F_104 ( V_154 ) ; V_60 ++ )
F_107 ( V_154 [ V_60 ] ) ;
for ( V_60 = 0 ; V_60 < F_104 ( V_155 ) ; V_60 ++ )
F_107 ( & V_155 [ V_60 ] ) ;
for ( V_60 = 0 ; V_60 < F_104 ( V_156 ) ; V_60 ++ ) {
V_13 = F_103 ( V_156 [ V_60 ] . V_21 ) ;
if ( ! V_13 ) {
F_4 ( L_15 , V_6 ,
V_156 [ V_60 ] . V_21 ) ;
continue;
}
V_156 [ V_60 ] . V_150 . V_12 = V_13 ;
F_106 ( & V_156 [ V_60 ] . V_150 ) ;
}
F_102 () ;
}
void F_110 ( void )
{
unsigned long V_157 , V_60 ;
T_1 * V_158 = V_159 ;
* V_158 ++ = F_3 ( V_15 ) & V_160 ;
* V_158 ++ = F_3 ( V_161 . V_29 + V_73 ) ;
* V_158 ++ = F_3 ( V_161 . V_29 + F_53 ( & V_161 ) ) ;
* V_158 ++ = F_3 ( V_162 . V_29 + V_73 ) ;
* V_158 ++ = F_3 ( V_162 . V_29 + F_53 ( & V_162 ) ) ;
* V_158 ++ = F_3 ( V_163 . V_29 + V_73 ) ;
* V_158 ++ = F_3 ( V_163 . V_29 + F_53 ( & V_163 ) ) ;
* V_158 ++ = F_3 ( V_164 . V_29 + V_73 ) ;
* V_158 ++ = F_3 ( V_164 . V_29 + F_53 ( & V_164 ) ) ;
* V_158 ++ = F_3 ( V_165 . V_29 + V_73 ) ;
* V_158 ++ = F_3 ( V_165 . V_29 + F_53 ( & V_165 ) ) ;
* V_158 ++ = F_3 ( V_166 . V_29 ) ;
* V_158 ++ = F_3 ( V_167 . V_29 ) ;
* V_158 ++ = F_3 ( V_168 . V_29 ) ;
* V_158 ++ = F_3 ( V_169 . V_29 ) ;
* V_158 ++ = F_3 ( V_169 . V_29 + V_43 ) ;
* V_158 ++ = F_3 ( V_170 . V_29 ) ;
* V_158 ++ = F_3 ( V_170 . V_29 + V_43 ) ;
* V_158 ++ = F_3 ( V_171 . V_29 ) ;
* V_158 ++ = F_3 ( V_172 . V_29 ) ;
for ( V_157 = V_173 ; V_157 <= V_174 ;
V_157 += 4 ) {
if ( V_157 == V_175 )
continue;
* V_158 ++ = F_3 ( V_157 ) ;
}
V_157 = V_123 ;
for ( V_60 = 0 ; V_60 < V_176 ; V_60 ++ , V_157 += 4 )
* V_158 ++ = F_3 ( V_157 ) ;
V_157 = V_121 ;
for ( V_60 = 0 ; V_60 < V_177 ; V_60 ++ , V_157 += 4 )
* V_158 ++ = F_3 ( V_157 ) ;
* V_158 ++ = F_3 ( V_178 ) ;
* V_158 ++ = F_3 ( V_179 ) ;
F_15 ( V_158 - V_159 != F_104 ( V_159 ) ) ;
}
void F_111 ( void )
{
unsigned long V_157 , V_60 ;
const T_1 * V_158 = V_159 ;
T_1 V_24 ;
V_24 = F_3 ( V_15 ) & ~ V_160 ;
V_24 |= * V_158 ++ ;
F_2 ( V_24 , V_15 ) ;
F_2 ( * V_158 ++ , V_161 . V_29 + V_73 ) ;
F_2 ( * V_158 ++ , V_161 . V_29 + F_53 ( & V_161 ) ) ;
F_2 ( * V_158 ++ , V_162 . V_29 + V_73 ) ;
F_2 ( * V_158 ++ , V_162 . V_29 + F_53 ( & V_162 ) ) ;
F_2 ( * V_158 ++ , V_163 . V_29 + V_73 ) ;
F_2 ( * V_158 ++ , V_163 . V_29 + F_53 ( & V_163 ) ) ;
F_2 ( * V_158 ++ , V_164 . V_29 + V_73 ) ;
F_2 ( * V_158 ++ , V_164 . V_29 + F_53 ( & V_164 ) ) ;
F_2 ( * V_158 ++ , V_165 . V_29 + V_73 ) ;
F_2 ( * V_158 ++ , V_165 . V_29 + F_53 ( & V_165 ) ) ;
F_47 ( 1000 ) ;
F_2 ( * V_158 ++ , V_166 . V_29 ) ;
F_2 ( * V_158 ++ , V_167 . V_29 ) ;
F_2 ( * V_158 ++ , V_168 . V_29 ) ;
F_2 ( * V_158 ++ , V_169 . V_29 ) ;
F_2 ( * V_158 ++ , V_169 . V_29 + V_43 ) ;
F_2 ( * V_158 ++ , V_170 . V_29 ) ;
F_2 ( * V_158 ++ , V_170 . V_29 + V_43 ) ;
F_2 ( * V_158 ++ , V_171 . V_29 ) ;
F_2 ( * V_158 ++ , V_172 . V_29 ) ;
F_2 ( 0xbffffff9ul , V_121 ) ;
F_2 ( 0xfefffff7ul , V_121 + 4 ) ;
F_2 ( 0x77f01bfful , V_121 + 8 ) ;
F_112 () ;
for ( V_157 = V_173 ; V_157 <= V_174 ;
V_157 += 4 ) {
if ( V_157 == V_175 )
continue;
F_2 ( * V_158 ++ , V_157 ) ;
}
F_112 () ;
V_157 = V_123 ;
for ( V_60 = 0 ; V_60 < V_176 ; V_60 ++ , V_157 += 4 )
F_2 ( * V_158 ++ , V_157 ) ;
F_112 () ;
V_157 = V_121 ;
for ( V_60 = 0 ; V_60 < V_177 ; V_60 ++ , V_157 += 4 )
F_2 ( * V_158 ++ , V_157 ) ;
F_112 () ;
F_2 ( * V_158 ++ , V_178 ) ;
F_2 ( * V_158 ++ , V_179 ) ;
}
