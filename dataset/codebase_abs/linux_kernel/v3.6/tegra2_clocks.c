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
static void F_14 ( struct V_12 * V_13 )
{
T_1 V_22 ;
int V_23 ;
int V_24 ;
const struct V_25 * V_26 ;
V_22 = F_3 ( V_13 -> V_27 + V_28 ) ;
V_13 -> V_29 = V_30 ;
F_15 ( ( ( V_22 & V_31 ) != V_32 ) &&
( ( V_22 & V_31 ) != V_33 ) ) ;
V_24 = ( ( V_22 & V_31 ) == V_33 ) ?
V_34 : V_35 ;
V_23 = ( V_22 >> V_24 ) & V_36 ;
for ( V_26 = V_13 -> V_37 ; V_26 -> V_38 != NULL ; V_26 ++ ) {
if ( V_26 -> V_39 == V_23 )
break;
}
F_15 ( V_26 -> V_38 == NULL ) ;
V_13 -> V_40 = V_26 -> V_38 ;
}
static int F_16 ( struct V_12 * V_13 )
{
F_2 ( 0 , V_13 -> V_27 + V_41 ) ;
return 0 ;
}
static void F_17 ( struct V_12 * V_13 )
{
F_11 ( L_3 , V_6 , V_13 -> V_21 ) ;
F_5 () ;
}
static int F_18 ( struct V_12 * V_13 , struct V_12 * V_42 )
{
T_1 V_22 ;
const struct V_25 * V_26 ;
int V_24 ;
V_22 = F_3 ( V_13 -> V_27 + V_28 ) ;
F_15 ( ( ( V_22 & V_31 ) != V_32 ) &&
( ( V_22 & V_31 ) != V_33 ) ) ;
V_24 = ( ( V_22 & V_31 ) == V_33 ) ?
V_34 : V_35 ;
for ( V_26 = V_13 -> V_37 ; V_26 -> V_38 != NULL ; V_26 ++ ) {
if ( V_26 -> V_38 == V_42 ) {
V_22 &= ~ ( V_36 << V_24 ) ;
V_22 |= V_26 -> V_39 << V_24 ;
if ( V_13 -> V_43 )
F_19 ( V_42 ) ;
F_2 ( V_22 , V_13 -> V_27 ) ;
if ( V_13 -> V_43 && V_13 -> V_40 )
F_20 ( V_13 -> V_40 ) ;
F_21 ( V_13 , V_42 ) ;
return 0 ;
}
}
return - V_10 ;
}
static int F_22 ( struct V_12 * V_13 , unsigned long V_8 )
{
return F_23 ( V_13 -> V_40 , V_8 ) ;
}
static void F_24 ( struct V_12 * V_13 )
{
}
static int F_25 ( struct V_12 * V_13 )
{
return 0 ;
}
static void F_26 ( struct V_12 * V_13 )
{
F_11 ( L_3 , V_6 , V_13 -> V_21 ) ;
F_5 () ;
}
static int F_27 ( struct V_12 * V_13 , unsigned long V_8 )
{
int V_44 ;
F_19 ( V_13 -> V_45 . V_46 . main ) ;
V_44 = F_28 ( V_13 -> V_40 , V_13 -> V_45 . V_46 . V_47 ) ;
if ( V_44 ) {
F_4 ( L_4 , V_13 -> V_45 . V_46 . V_47 -> V_21 ) ;
goto V_48;
}
if ( V_8 == F_29 ( V_13 -> V_45 . V_46 . V_47 ) )
goto V_48;
V_44 = F_23 ( V_13 -> V_45 . V_46 . main , V_8 ) ;
if ( V_44 ) {
F_4 ( L_5 , V_8 ) ;
goto V_48;
}
V_44 = F_28 ( V_13 -> V_40 , V_13 -> V_45 . V_46 . main ) ;
if ( V_44 ) {
F_4 ( L_4 , V_13 -> V_45 . V_46 . main-> V_21 ) ;
goto V_48;
}
V_48:
F_20 ( V_13 -> V_45 . V_46 . main ) ;
return V_44 ;
}
static void F_30 ( struct V_12 * V_13 , bool assert )
{
unsigned long V_27 = assert ? V_49 : V_50 ;
F_11 ( L_6 , V_6 , assert ? L_7 : L_8 ) ;
F_2 ( 1 << 1 , V_27 ) ;
}
static void F_31 ( struct V_12 * V_13 )
{
T_1 V_22 = F_3 ( V_13 -> V_27 ) ;
V_13 -> V_29 = ( ( V_22 >> V_13 -> V_51 ) & V_52 ) ? V_53 : V_30 ;
V_13 -> div = ( ( V_22 >> V_13 -> V_51 ) & V_54 ) + 1 ;
V_13 -> V_55 = 1 ;
}
static int F_32 ( struct V_12 * V_13 )
{
T_1 V_22 ;
unsigned long V_56 ;
F_33 ( & V_57 , V_56 ) ;
V_22 = F_3 ( V_13 -> V_27 ) ;
V_22 &= ~ ( V_52 << V_13 -> V_51 ) ;
F_2 ( V_22 , V_13 -> V_27 ) ;
F_34 ( & V_57 , V_56 ) ;
return 0 ;
}
static void F_35 ( struct V_12 * V_13 )
{
T_1 V_22 ;
unsigned long V_56 ;
F_33 ( & V_57 , V_56 ) ;
V_22 = F_3 ( V_13 -> V_27 ) ;
V_22 |= V_52 << V_13 -> V_51 ;
F_2 ( V_22 , V_13 -> V_27 ) ;
F_34 ( & V_57 , V_56 ) ;
}
static int F_36 ( struct V_12 * V_13 , unsigned long V_8 )
{
T_1 V_22 ;
unsigned long V_7 = F_29 ( V_13 -> V_40 ) ;
unsigned long V_56 ;
int V_44 = - V_10 ;
int V_58 ;
F_33 ( & V_57 , V_56 ) ;
V_22 = F_3 ( V_13 -> V_27 ) ;
for ( V_58 = 1 ; V_58 <= 4 ; V_58 ++ ) {
if ( V_8 == V_7 / V_58 ) {
V_22 &= ~ ( V_54 << V_13 -> V_51 ) ;
V_22 |= ( V_58 - 1 ) << V_13 -> V_51 ;
F_2 ( V_22 , V_13 -> V_27 ) ;
V_13 -> div = V_58 ;
V_13 -> V_55 = 1 ;
V_44 = 0 ;
break;
}
}
F_34 ( & V_57 , V_56 ) ;
return V_44 ;
}
static void F_37 ( struct V_12 * V_13 )
{
T_1 V_22 ;
V_22 = F_38 ( V_59 ) ;
V_13 -> V_29 = ( V_22 & V_60 ) ? V_30 : V_53 ;
V_13 -> V_55 = 1 ;
V_22 = F_38 ( V_13 -> V_27 ) ;
if ( V_22 & V_61 ) {
unsigned int V_62 ;
V_62 = ( V_22 >> V_63 ) &
V_64 ;
V_22 >>= V_65 ;
V_22 &= V_66 ;
V_62 += V_22 ;
V_13 -> div = V_62 * 4 ;
} else {
V_13 -> div = 1 ;
}
}
static int F_39 ( struct V_12 * V_13 )
{
T_1 V_22 ;
V_22 = F_38 ( V_67 ) ;
F_40 ( V_22 | V_68 , V_67 ) ;
V_22 = F_38 ( V_59 ) ;
F_40 ( V_22 | V_60 , V_59 ) ;
return 0 ;
}
static void F_41 ( struct V_12 * V_13 )
{
T_1 V_22 ;
V_22 = F_38 ( V_59 ) ;
F_40 ( V_22 & ~ V_60 , V_59 ) ;
V_22 = F_38 ( V_67 ) ;
F_40 ( V_22 & ~ V_68 , V_67 ) ;
}
static int F_42 ( struct V_12 * V_13 , unsigned long V_8 )
{
unsigned long V_7 = F_29 ( V_13 -> V_40 ) ;
if ( V_8 >= V_7 ) {
V_13 -> div = 1 ;
F_40 ( 0 , V_13 -> V_27 ) ;
} else {
unsigned int V_62 ;
T_1 V_22 ;
V_62 = F_43 ( V_7 / 8 , V_8 ) ;
V_13 -> div = V_62 * 8 ;
V_22 = ( V_62 & V_64 ) <<
V_63 ;
V_62 &= V_66 ;
V_62 <<= V_65 ;
V_22 |= V_62 ;
V_22 |= V_61 ;
F_40 ( V_22 , V_13 -> V_27 ) ;
}
return 0 ;
}
static int F_44 ( struct V_12 * V_13 )
{
F_45 ( V_13 -> V_45 . V_69 . V_70 ) ;
return 0 ;
}
static void F_46 ( struct V_12 * V_13 )
{
T_1 V_22 = F_3 ( V_13 -> V_27 + V_71 ) ;
V_13 -> V_29 = ( V_22 & V_72 ) ? V_30 : V_53 ;
if ( V_13 -> V_56 & V_73 && ! ( V_22 & V_74 ) ) {
F_47 ( L_9 , V_13 -> V_21 ) ;
V_13 -> V_55 = 1 ;
V_13 -> div = 1 ;
} else if ( V_22 & V_75 ) {
V_13 -> V_55 = 1 ;
V_13 -> div = 1 ;
} else {
V_13 -> V_55 = ( V_22 & V_76 ) >> V_77 ;
V_13 -> div = ( V_22 & V_78 ) >> V_79 ;
if ( V_13 -> V_56 & V_80 )
V_13 -> div *= ( V_22 & V_81 ) ? 1 : 2 ;
else
V_13 -> div *= ( V_22 & V_82 ) ? 2 : 1 ;
}
}
static int F_48 ( struct V_12 * V_13 )
{
T_1 V_22 ;
F_11 ( L_3 , V_6 , V_13 -> V_21 ) ;
V_22 = F_3 ( V_13 -> V_27 + V_71 ) ;
V_22 &= ~ V_75 ;
V_22 |= V_72 ;
F_2 ( V_22 , V_13 -> V_27 + V_71 ) ;
F_44 ( V_13 ) ;
return 0 ;
}
static void F_49 ( struct V_12 * V_13 )
{
T_1 V_22 ;
F_11 ( L_3 , V_6 , V_13 -> V_21 ) ;
V_22 = F_3 ( V_13 -> V_27 ) ;
V_22 &= ~ ( V_75 | V_72 ) ;
F_2 ( V_22 , V_13 -> V_27 ) ;
}
static int F_50 ( struct V_12 * V_13 , unsigned long V_8 )
{
T_1 V_22 ;
unsigned long V_83 ;
const struct V_84 * V_26 ;
F_11 ( L_10 , V_6 , V_13 -> V_21 , V_8 ) ;
V_83 = F_29 ( V_13 -> V_40 ) ;
for ( V_26 = V_13 -> V_45 . V_69 . V_85 ; V_26 -> V_83 != 0 ; V_26 ++ ) {
if ( V_26 -> V_83 == V_83 && V_26 -> V_86 == V_8 ) {
V_13 -> V_55 = V_26 -> V_87 ;
V_13 -> div = V_26 -> V_88 * V_26 -> V_42 ;
V_22 = F_3 ( V_13 -> V_27 + V_71 ) ;
if ( V_13 -> V_56 & V_73 )
V_22 |= V_74 ;
V_22 &= ~ ( V_82 | V_76 |
V_78 ) ;
V_22 |= ( V_26 -> V_88 << V_79 ) |
( V_26 -> V_87 << V_77 ) ;
F_15 ( V_26 -> V_42 < 1 || V_26 -> V_42 > 2 ) ;
if ( V_13 -> V_56 & V_80 ) {
if ( V_26 -> V_42 == 1 )
V_22 |= V_81 ;
} else {
if ( V_26 -> V_42 == 2 )
V_22 |= 1 << V_89 ;
}
F_2 ( V_22 , V_13 -> V_27 + V_71 ) ;
if ( V_13 -> V_56 & V_90 ) {
V_22 = F_3 ( V_13 -> V_27 + F_51 ( V_13 ) ) ;
V_22 &= ~ V_91 ;
V_22 |= V_26 -> V_92 << V_93 ;
F_2 ( V_22 , V_13 -> V_27 + F_51 ( V_13 ) ) ;
}
if ( V_13 -> V_29 == V_30 )
F_48 ( V_13 ) ;
return 0 ;
}
}
return - V_10 ;
}
static void F_52 ( struct V_12 * V_13 )
{
F_46 ( V_13 ) ;
if ( V_94 == 7 )
V_13 -> V_95 = 750000000 ;
}
static int F_53 ( struct V_12 * V_13 )
{
T_1 V_22 ;
F_11 ( L_3 , V_6 , V_13 -> V_21 ) ;
F_54 ( 1 ) ;
V_22 = F_3 ( V_13 -> V_27 + V_71 ) ;
if ( ! ( V_22 & V_96 ) )
return - V_97 ;
V_22 = F_3 ( V_13 -> V_27 + V_71 ) ;
V_22 |= V_72 | V_75 ;
F_2 ( V_22 , V_13 -> V_27 + V_71 ) ;
return 0 ;
}
static void F_55 ( struct V_12 * V_13 )
{
T_1 V_22 = F_3 ( V_13 -> V_27 ) ;
T_1 V_98 ;
V_22 >>= V_13 -> V_51 ;
V_13 -> V_29 = ( V_22 & V_99 ) ? V_30 : V_53 ;
if ( ! ( V_22 & V_100 ) )
V_13 -> V_29 = V_53 ;
if ( V_13 -> V_56 & V_101 ) {
V_98 = ( V_22 & V_102 ) >> V_103 ;
V_13 -> div = ( V_98 + 2 ) ;
V_13 -> V_55 = 2 ;
} else if ( V_13 -> V_56 & V_104 ) {
V_13 -> div = 2 ;
V_13 -> V_55 = 1 ;
} else {
V_13 -> div = 1 ;
V_13 -> V_55 = 1 ;
}
}
static int F_56 ( struct V_12 * V_13 )
{
T_1 V_22 ;
T_1 V_105 ;
unsigned long V_56 ;
F_11 ( L_11 , V_6 , V_13 -> V_21 ) ;
if ( V_13 -> V_56 & V_101 ) {
F_33 ( & V_57 , V_56 ) ;
V_22 = F_3 ( V_13 -> V_27 ) ;
V_105 = V_22 >> V_13 -> V_51 ;
V_105 &= 0xFFFF ;
V_105 |= V_99 | V_100 ;
V_22 &= ~ ( 0xFFFF << V_13 -> V_51 ) ;
V_22 |= V_105 << V_13 -> V_51 ;
F_2 ( V_22 , V_13 -> V_27 ) ;
F_34 ( & V_57 , V_56 ) ;
return 0 ;
} else if ( V_13 -> V_56 & V_104 ) {
F_15 ( ! ( V_13 -> V_56 & V_106 ) ) ;
F_33 ( & V_57 , V_56 ) ;
V_22 = F_3 ( V_13 -> V_27 ) ;
V_22 &= ~ V_107 ;
F_2 ( V_22 , V_13 -> V_27 ) ;
F_34 ( & V_57 , V_56 ) ;
return 0 ;
}
return - V_10 ;
}
static void F_57 ( struct V_12 * V_13 )
{
T_1 V_22 ;
T_1 V_105 ;
unsigned long V_56 ;
F_11 ( L_11 , V_6 , V_13 -> V_21 ) ;
if ( V_13 -> V_56 & V_101 ) {
F_33 ( & V_57 , V_56 ) ;
V_22 = F_3 ( V_13 -> V_27 ) ;
V_105 = V_22 >> V_13 -> V_51 ;
V_105 &= 0xFFFF ;
V_105 &= ~ ( V_99 | V_100 ) ;
V_22 &= ~ ( 0xFFFF << V_13 -> V_51 ) ;
V_22 |= V_105 << V_13 -> V_51 ;
F_2 ( V_22 , V_13 -> V_27 ) ;
F_34 ( & V_57 , V_56 ) ;
} else if ( V_13 -> V_56 & V_104 ) {
F_15 ( ! ( V_13 -> V_56 & V_106 ) ) ;
F_33 ( & V_57 , V_56 ) ;
V_22 = F_3 ( V_13 -> V_27 ) ;
V_22 |= V_107 ;
F_2 ( V_22 , V_13 -> V_27 ) ;
F_34 ( & V_57 , V_56 ) ;
}
}
static int F_58 ( struct V_12 * V_13 , unsigned long V_8 )
{
T_1 V_22 ;
T_1 V_105 ;
int V_9 ;
unsigned long V_7 = F_29 ( V_13 -> V_40 ) ;
unsigned long V_56 ;
F_11 ( L_10 , V_6 , V_13 -> V_21 , V_8 ) ;
if ( V_13 -> V_56 & V_101 ) {
V_9 = F_6 ( V_7 , V_8 ) ;
if ( V_9 >= 0 ) {
F_33 ( & V_57 , V_56 ) ;
V_22 = F_3 ( V_13 -> V_27 ) ;
V_105 = V_22 >> V_13 -> V_51 ;
V_105 &= 0xFFFF ;
if ( V_13 -> V_56 & V_108 )
V_105 |= V_109 ;
V_105 &= ~ V_102 ;
V_105 |= V_9 << V_103 ;
V_22 &= ~ ( 0xFFFF << V_13 -> V_51 ) ;
V_22 |= V_105 << V_13 -> V_51 ;
F_2 ( V_22 , V_13 -> V_27 ) ;
V_13 -> div = V_9 + 2 ;
V_13 -> V_55 = 2 ;
F_34 ( & V_57 , V_56 ) ;
return 0 ;
}
} else if ( V_13 -> V_56 & V_104 ) {
if ( V_7 == V_8 * 2 )
return 0 ;
}
return - V_10 ;
}
static long F_59 ( struct V_12 * V_13 , unsigned long V_8 )
{
int V_110 ;
unsigned long V_7 = F_29 ( V_13 -> V_40 ) ;
F_11 ( L_10 , V_6 , V_13 -> V_21 , V_8 ) ;
if ( V_13 -> V_56 & V_101 ) {
V_110 = F_6 ( V_7 , V_8 ) ;
if ( V_110 < 0 )
return V_110 ;
return F_43 ( V_7 * 2 , V_110 + 2 ) ;
} else if ( V_13 -> V_56 & V_104 ) {
return F_43 ( V_7 , 2 ) ;
}
return - V_10 ;
}
static void F_60 ( struct V_12 * V_13 )
{
T_1 V_22 = F_3 ( V_13 -> V_27 ) ;
const struct V_25 * V_111 = NULL ;
const struct V_25 * V_26 ;
T_1 V_24 ;
T_1 V_112 ;
if ( V_13 -> V_56 & V_113 ) {
V_24 = V_114 ;
V_112 = V_115 ;
} else {
V_24 = V_116 ;
V_112 = V_117 ;
}
if ( V_13 -> V_56 & V_118 ) {
for ( V_26 = V_13 -> V_37 ; V_26 -> V_38 != NULL ; V_26 ++ ) {
if ( ( V_22 & V_112 ) >> V_24 == V_26 -> V_39 )
V_111 = V_26 ;
}
F_15 ( ! V_111 ) ;
V_13 -> V_40 = V_111 -> V_38 ;
} else {
V_13 -> V_40 = V_13 -> V_37 [ 0 ] . V_38 ;
}
if ( V_13 -> V_56 & V_101 ) {
T_1 V_98 = V_22 & V_119 ;
V_13 -> div = V_98 + 2 ;
V_13 -> V_55 = 2 ;
} else if ( V_13 -> V_56 & V_120 ) {
T_1 V_121 = V_22 & V_122 ;
V_13 -> div = V_121 + 1 ;
V_13 -> V_55 = 1 ;
} else {
V_13 -> div = 1 ;
V_13 -> V_55 = 1 ;
}
V_13 -> V_29 = V_30 ;
if ( ! V_13 -> V_45 . V_123 . V_124 )
return;
if ( ! ( F_3 ( V_125 + F_61 ( V_13 ) ) &
F_62 ( V_13 ) ) )
V_13 -> V_29 = V_53 ;
if ( ! ( V_13 -> V_56 & V_126 ) )
if ( F_3 ( V_127 + F_61 ( V_13 ) ) &
F_62 ( V_13 ) )
V_13 -> V_29 = V_53 ;
}
static int F_63 ( struct V_12 * V_13 )
{
T_1 V_22 ;
unsigned long V_56 ;
int V_128 ;
F_11 ( L_3 , V_6 , V_13 -> V_21 ) ;
if ( ! V_13 -> V_45 . V_123 . V_124 )
return 0 ;
F_33 ( & V_57 , V_56 ) ;
V_128 = V_129 [ V_13 -> V_45 . V_123 . V_124 ] ++ ;
if ( V_128 > 1 )
goto V_48;
F_2 ( F_62 ( V_13 ) ,
V_130 + F_64 ( V_13 ) ) ;
if ( ! ( V_13 -> V_56 & V_126 ) && ! ( V_13 -> V_56 & V_131 ) )
F_2 ( F_62 ( V_13 ) ,
V_50 + F_64 ( V_13 ) ) ;
if ( V_13 -> V_56 & V_132 ) {
V_22 = F_3 ( V_13 -> V_27 ) ;
V_22 |= 0x3 << 24 ;
F_2 ( V_22 , V_13 -> V_27 ) ;
}
V_48:
F_34 ( & V_57 , V_56 ) ;
return 0 ;
}
static void F_65 ( struct V_12 * V_13 )
{
unsigned long V_56 ;
F_11 ( L_3 , V_6 , V_13 -> V_21 ) ;
if ( ! V_13 -> V_45 . V_123 . V_124 )
return;
F_33 ( & V_57 , V_56 ) ;
if ( V_13 -> V_43 )
V_129 [ V_13 -> V_45 . V_123 . V_124 ] -- ;
if ( V_129 [ V_13 -> V_45 . V_123 . V_124 ] == 0 )
F_2 ( F_62 ( V_13 ) ,
V_133 + F_64 ( V_13 ) ) ;
F_34 ( & V_57 , V_56 ) ;
}
static void F_66 ( struct V_12 * V_13 , bool assert )
{
unsigned long V_134 = assert ? V_49 : V_50 ;
F_11 ( L_12 , V_6 ,
assert ? L_7 : L_8 , V_13 -> V_21 ) ;
F_15 ( ! V_13 -> V_45 . V_123 . V_124 ) ;
if ( ! ( V_13 -> V_56 & V_126 ) )
F_2 ( F_62 ( V_13 ) ,
V_134 + F_64 ( V_13 ) ) ;
}
static int F_67 ( struct V_12 * V_13 , struct V_12 * V_42 )
{
T_1 V_22 ;
const struct V_25 * V_26 ;
T_1 V_112 , V_24 ;
F_11 ( L_13 , V_6 , V_13 -> V_21 , V_42 -> V_21 ) ;
if ( V_13 -> V_56 & V_113 ) {
V_24 = V_114 ;
V_112 = V_115 ;
} else {
V_24 = V_116 ;
V_112 = V_117 ;
}
for ( V_26 = V_13 -> V_37 ; V_26 -> V_38 != NULL ; V_26 ++ ) {
if ( V_26 -> V_38 == V_42 ) {
V_22 = F_3 ( V_13 -> V_27 ) ;
V_22 &= ~ V_112 ;
V_22 |= ( V_26 -> V_39 ) << V_24 ;
if ( V_13 -> V_43 )
F_19 ( V_42 ) ;
F_2 ( V_22 , V_13 -> V_27 ) ;
if ( V_13 -> V_43 && V_13 -> V_40 )
F_20 ( V_13 -> V_40 ) ;
F_21 ( V_13 , V_42 ) ;
return 0 ;
}
}
return - V_10 ;
}
static int F_68 ( struct V_12 * V_13 , unsigned long V_8 )
{
T_1 V_22 ;
int V_110 ;
unsigned long V_7 = F_29 ( V_13 -> V_40 ) ;
if ( V_13 -> V_56 & V_101 ) {
V_110 = F_6 ( V_7 , V_8 ) ;
if ( V_110 >= 0 ) {
V_22 = F_3 ( V_13 -> V_27 ) ;
V_22 &= ~ V_119 ;
V_22 |= V_110 ;
F_2 ( V_22 , V_13 -> V_27 ) ;
V_13 -> div = V_110 + 2 ;
V_13 -> V_55 = 2 ;
return 0 ;
}
} else if ( V_13 -> V_56 & V_120 ) {
V_110 = F_8 ( V_7 , V_8 ) ;
if ( V_110 >= 0 ) {
V_22 = F_3 ( V_13 -> V_27 ) ;
V_22 &= ~ V_122 ;
V_22 |= V_110 ;
F_2 ( V_22 , V_13 -> V_27 ) ;
V_13 -> div = V_110 + 1 ;
V_13 -> V_55 = 1 ;
return 0 ;
}
} else if ( V_7 <= V_8 ) {
V_13 -> div = 1 ;
V_13 -> V_55 = 1 ;
return 0 ;
}
return - V_10 ;
}
static long F_69 ( struct V_12 * V_13 ,
unsigned long V_8 )
{
int V_110 ;
unsigned long V_7 = F_29 ( V_13 -> V_40 ) ;
F_11 ( L_10 , V_6 , V_13 -> V_21 , V_8 ) ;
if ( V_13 -> V_56 & V_101 ) {
V_110 = F_6 ( V_7 , V_8 ) ;
if ( V_110 < 0 )
return V_110 ;
return F_43 ( V_7 * 2 , V_110 + 2 ) ;
} else if ( V_13 -> V_56 & V_120 ) {
V_110 = F_8 ( V_7 , V_8 ) ;
if ( V_110 < 0 )
return V_110 ;
return F_43 ( V_7 , V_110 + 1 ) ;
}
return - V_10 ;
}
void F_70 ( struct V_12 * V_13 , int V_135 )
{
T_1 V_27 ;
unsigned long V_56 ;
F_33 ( & V_13 -> V_136 , V_56 ) ;
V_135 = F_71 ( V_135 , 0 , 15 ) ;
V_27 = F_3 ( V_13 -> V_27 ) ;
V_27 &= ~ V_137 ;
V_27 |= V_138 ;
V_27 |= V_135 << V_139 ;
F_2 ( V_27 , V_13 -> V_27 ) ;
F_34 ( & V_13 -> V_136 , V_56 ) ;
}
static void F_72 ( struct V_12 * V_13 )
{
F_60 ( V_13 ) ;
V_13 -> V_95 = F_73 ( V_13 ) ;
}
static long F_74 ( struct V_12 * V_13 , unsigned long V_8 )
{
long V_140 ;
long V_141 ;
V_140 = F_75 ( V_8 ) ;
if ( V_140 < 0 )
return V_13 -> V_95 ;
V_141 = F_69 ( V_13 , V_140 ) ;
F_76 ( V_140 != V_141 ,
L_14 ,
V_140 , V_141 ) ;
return V_140 ;
}
static int F_77 ( struct V_12 * V_13 , unsigned long V_8 )
{
int V_44 ;
V_44 = F_78 ( V_8 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_68 ( V_13 , V_8 ) ;
F_45 ( 1 ) ;
return V_44 ;
}
static void F_79 ( struct V_12 * V_13 )
{
V_13 -> V_55 = 2 ;
V_13 -> div = 1 ;
V_13 -> V_29 = V_30 ;
if ( ! V_13 -> V_45 . V_123 . V_124 )
return;
if ( ! ( F_3 ( V_125 + F_61 ( V_13 ) ) &
F_62 ( V_13 ) ) )
V_13 -> V_29 = V_53 ;
}
static int F_80 ( struct V_12 * V_13 , unsigned long V_8 )
{
if ( V_8 != 2 * F_29 ( V_13 -> V_40 ) )
return - V_10 ;
V_13 -> V_55 = 2 ;
V_13 -> div = 1 ;
return 0 ;
}
static void F_81 ( struct V_12 * V_13 )
{
int V_23 ;
const struct V_25 * V_26 ;
T_1 V_22 = F_3 ( V_13 -> V_27 ) ;
V_13 -> V_29 = ( V_22 & ( 1 << 4 ) ) ? V_53 : V_30 ;
V_23 = V_22 & 0xf ;
for ( V_26 = V_13 -> V_37 ; V_26 -> V_38 != NULL ; V_26 ++ )
if ( V_26 -> V_39 == V_23 )
break;
F_15 ( V_26 -> V_38 == NULL ) ;
V_13 -> V_40 = V_26 -> V_38 ;
}
static int F_82 ( struct V_12 * V_13 )
{
F_2 ( 0 , V_13 -> V_27 ) ;
return 0 ;
}
static void F_83 ( struct V_12 * V_13 )
{
F_2 ( 1 , V_13 -> V_27 ) ;
}
static int F_84 ( struct V_12 * V_13 , struct V_12 * V_42 )
{
T_1 V_22 ;
const struct V_25 * V_26 ;
for ( V_26 = V_13 -> V_37 ; V_26 -> V_38 != NULL ; V_26 ++ ) {
if ( V_26 -> V_38 == V_42 ) {
V_22 = F_3 ( V_13 -> V_27 ) ;
V_22 &= ~ 0xf ;
V_22 |= V_26 -> V_39 ;
if ( V_13 -> V_43 )
F_19 ( V_42 ) ;
F_2 ( V_22 , V_13 -> V_27 ) ;
if ( V_13 -> V_43 && V_13 -> V_40 )
F_20 ( V_13 -> V_40 ) ;
F_21 ( V_13 , V_42 ) ;
return 0 ;
}
}
return - V_10 ;
}
static void F_85 ( struct V_12 * V_13 )
{
V_13 -> V_29 = V_30 ;
F_15 ( ! V_13 -> V_45 . V_123 . V_124 ) ;
if ( ! ( F_3 ( V_125 + F_61 ( V_13 ) ) &
F_62 ( V_13 ) ) )
V_13 -> V_29 = V_53 ;
}
static int F_86 ( struct V_12 * V_13 )
{
F_15 ( ! V_13 -> V_45 . V_123 . V_124 ) ;
F_2 ( F_62 ( V_13 ) ,
V_130 + F_64 ( V_13 ) ) ;
return 0 ;
}
static void F_87 ( struct V_12 * V_13 )
{
F_15 ( ! V_13 -> V_45 . V_123 . V_124 ) ;
F_2 ( F_62 ( V_13 ) ,
V_133 + F_64 ( V_13 ) ) ;
}
static int F_88 ( struct V_12 * V_142 )
{
struct V_12 * V_13 ;
unsigned long V_8 = V_142 -> V_143 ;
F_89 (c, &bus->shared_bus_list, u.shared_bus_user.node)
if ( V_13 -> V_45 . V_144 . V_145 )
V_8 = F_90 ( V_13 -> V_45 . V_144 . V_8 , V_8 ) ;
if ( V_8 == F_73 ( V_142 ) )
return 0 ;
return F_91 ( V_142 , V_8 ) ;
}
static void F_92 ( struct V_12 * V_13 )
{
unsigned long V_56 ;
V_13 -> V_95 = V_13 -> V_40 -> V_95 ;
V_13 -> V_45 . V_144 . V_8 = V_13 -> V_40 -> V_95 ;
V_13 -> V_29 = V_53 ;
V_13 -> V_146 = true ;
F_33 ( & V_13 -> V_40 -> V_136 , V_56 ) ;
F_93 ( & V_13 -> V_45 . V_144 . V_147 ,
& V_13 -> V_40 -> V_148 ) ;
F_34 ( & V_13 -> V_40 -> V_136 , V_56 ) ;
}
static int F_94 ( struct V_12 * V_13 , unsigned long V_8 )
{
unsigned long V_56 ;
int V_44 ;
long V_149 = V_8 ;
V_149 = F_95 ( V_13 -> V_40 , V_149 ) ;
if ( V_149 < 0 )
return V_149 ;
F_33 ( & V_13 -> V_40 -> V_136 , V_56 ) ;
V_13 -> V_45 . V_144 . V_8 = V_149 ;
V_44 = F_88 ( V_13 -> V_40 ) ;
F_34 ( & V_13 -> V_40 -> V_136 , V_56 ) ;
return V_44 ;
}
static long F_96 ( struct V_12 * V_13 , unsigned long V_8 )
{
return F_95 ( V_13 -> V_40 , V_8 ) ;
}
static int F_97 ( struct V_12 * V_13 )
{
unsigned long V_56 ;
int V_44 ;
F_33 ( & V_13 -> V_40 -> V_136 , V_56 ) ;
V_13 -> V_45 . V_144 . V_145 = true ;
V_44 = F_88 ( V_13 -> V_40 ) ;
F_34 ( & V_13 -> V_40 -> V_136 , V_56 ) ;
return V_44 ;
}
static void F_98 ( struct V_12 * V_13 )
{
unsigned long V_56 ;
int V_44 ;
F_33 ( & V_13 -> V_40 -> V_136 , V_56 ) ;
V_13 -> V_45 . V_144 . V_145 = false ;
V_44 = F_88 ( V_13 -> V_40 ) ;
F_99 ( V_44 ) ;
F_34 ( & V_13 -> V_40 -> V_136 , V_56 ) ;
}
static void F_100 ( void )
{
int V_58 ;
struct V_25 * V_26 = V_150 ;
const struct V_151 * V_152 = V_153 ;
struct V_154 * V_155 ;
for ( V_58 = 0 ; V_152 -> V_21 ; V_58 ++ , V_26 ++ , V_152 ++ ) {
V_26 -> V_38 = F_101 ( V_152 -> V_21 ) ;
if ( ! V_26 -> V_38 )
F_4 ( L_15 , V_6 ,
V_152 -> V_21 ) ;
V_26 -> V_39 = V_152 -> V_39 ;
}
V_155 = V_156 ;
for ( V_58 = 0 ; V_58 < F_102 ( V_156 ) ; V_58 ++ , V_155 ++ ) {
F_103 ( V_155 -> V_12 ) ;
F_104 ( V_155 ) ;
}
}
static void F_105 ( struct V_12 * V_13 )
{
F_103 ( V_13 ) ;
F_106 ( & V_13 -> V_148 ) ;
if ( ! V_13 -> V_155 . V_157 && ! V_13 -> V_155 . V_158 )
V_13 -> V_155 . V_158 = V_13 -> V_21 ;
V_13 -> V_155 . V_12 = V_13 ;
F_104 ( & V_13 -> V_155 ) ;
}
void T_3 F_107 ( void )
{
int V_58 ;
struct V_12 * V_13 ;
for ( V_58 = 0 ; V_58 < F_102 ( V_159 ) ; V_58 ++ )
F_105 ( V_159 [ V_58 ] ) ;
for ( V_58 = 0 ; V_58 < F_102 ( V_160 ) ; V_58 ++ )
F_105 ( & V_160 [ V_58 ] ) ;
for ( V_58 = 0 ; V_58 < F_102 ( V_161 ) ; V_58 ++ ) {
V_13 = F_101 ( V_161 [ V_58 ] . V_21 ) ;
if ( ! V_13 ) {
F_4 ( L_16 , V_6 ,
V_161 [ V_58 ] . V_21 ) ;
continue;
}
V_161 [ V_58 ] . V_155 . V_12 = V_13 ;
F_104 ( & V_161 [ V_58 ] . V_155 ) ;
}
F_100 () ;
}
void F_108 ( void )
{
unsigned long V_162 , V_58 ;
T_1 * V_163 = V_164 ;
* V_163 ++ = F_3 ( V_15 ) & V_165 ;
* V_163 ++ = F_3 ( V_166 . V_27 + V_71 ) ;
* V_163 ++ = F_3 ( V_166 . V_27 + F_51 ( & V_166 ) ) ;
* V_163 ++ = F_3 ( V_167 . V_27 + V_71 ) ;
* V_163 ++ = F_3 ( V_167 . V_27 + F_51 ( & V_167 ) ) ;
* V_163 ++ = F_3 ( V_168 . V_27 + V_71 ) ;
* V_163 ++ = F_3 ( V_168 . V_27 + F_51 ( & V_168 ) ) ;
* V_163 ++ = F_3 ( V_169 . V_27 + V_71 ) ;
* V_163 ++ = F_3 ( V_169 . V_27 + F_51 ( & V_169 ) ) ;
* V_163 ++ = F_3 ( V_170 . V_27 + V_71 ) ;
* V_163 ++ = F_3 ( V_170 . V_27 + F_51 ( & V_170 ) ) ;
* V_163 ++ = F_3 ( V_171 . V_27 ) ;
* V_163 ++ = F_3 ( V_172 . V_27 ) ;
* V_163 ++ = F_3 ( V_173 . V_27 ) ;
* V_163 ++ = F_3 ( V_174 . V_27 ) ;
* V_163 ++ = F_3 ( V_174 . V_27 + V_41 ) ;
* V_163 ++ = F_3 ( V_175 . V_27 ) ;
* V_163 ++ = F_3 ( V_175 . V_27 + V_41 ) ;
* V_163 ++ = F_3 ( V_176 . V_27 ) ;
* V_163 ++ = F_3 ( V_177 . V_27 ) ;
for ( V_162 = V_178 ; V_162 <= V_179 ;
V_162 += 4 ) {
if ( V_162 == V_180 )
continue;
* V_163 ++ = F_3 ( V_162 ) ;
}
V_162 = V_127 ;
for ( V_58 = 0 ; V_58 < V_181 ; V_58 ++ , V_162 += 4 )
* V_163 ++ = F_3 ( V_162 ) ;
V_162 = V_125 ;
for ( V_58 = 0 ; V_58 < V_182 ; V_58 ++ , V_162 += 4 )
* V_163 ++ = F_3 ( V_162 ) ;
* V_163 ++ = F_3 ( V_183 ) ;
* V_163 ++ = F_3 ( V_184 ) ;
F_15 ( V_163 - V_164 != F_102 ( V_164 ) ) ;
}
void F_109 ( void )
{
unsigned long V_162 , V_58 ;
const T_1 * V_163 = V_164 ;
T_1 V_22 ;
V_22 = F_3 ( V_15 ) & ~ V_165 ;
V_22 |= * V_163 ++ ;
F_2 ( V_22 , V_15 ) ;
F_2 ( * V_163 ++ , V_166 . V_27 + V_71 ) ;
F_2 ( * V_163 ++ , V_166 . V_27 + F_51 ( & V_166 ) ) ;
F_2 ( * V_163 ++ , V_167 . V_27 + V_71 ) ;
F_2 ( * V_163 ++ , V_167 . V_27 + F_51 ( & V_167 ) ) ;
F_2 ( * V_163 ++ , V_168 . V_27 + V_71 ) ;
F_2 ( * V_163 ++ , V_168 . V_27 + F_51 ( & V_168 ) ) ;
F_2 ( * V_163 ++ , V_169 . V_27 + V_71 ) ;
F_2 ( * V_163 ++ , V_169 . V_27 + F_51 ( & V_169 ) ) ;
F_2 ( * V_163 ++ , V_170 . V_27 + V_71 ) ;
F_2 ( * V_163 ++ , V_170 . V_27 + F_51 ( & V_170 ) ) ;
F_45 ( 1000 ) ;
F_2 ( * V_163 ++ , V_171 . V_27 ) ;
F_2 ( * V_163 ++ , V_172 . V_27 ) ;
F_2 ( * V_163 ++ , V_173 . V_27 ) ;
F_2 ( * V_163 ++ , V_174 . V_27 ) ;
F_2 ( * V_163 ++ , V_174 . V_27 + V_41 ) ;
F_2 ( * V_163 ++ , V_175 . V_27 ) ;
F_2 ( * V_163 ++ , V_175 . V_27 + V_41 ) ;
F_2 ( * V_163 ++ , V_176 . V_27 ) ;
F_2 ( * V_163 ++ , V_177 . V_27 ) ;
F_2 ( 0xbffffff9ul , V_125 ) ;
F_2 ( 0xfefffff7ul , V_125 + 4 ) ;
F_2 ( 0x77f01bfful , V_125 + 8 ) ;
F_110 () ;
for ( V_162 = V_178 ; V_162 <= V_179 ;
V_162 += 4 ) {
if ( V_162 == V_180 )
continue;
F_2 ( * V_163 ++ , V_162 ) ;
}
F_110 () ;
V_162 = V_127 ;
for ( V_58 = 0 ; V_58 < V_181 ; V_58 ++ , V_162 += 4 )
F_2 ( * V_163 ++ , V_162 ) ;
F_110 () ;
V_162 = V_125 ;
for ( V_58 = 0 ; V_58 < V_182 ; V_58 ++ , V_162 += 4 )
F_2 ( * V_163 ++ , V_162 ) ;
F_110 () ;
F_2 ( * V_163 ++ , V_183 ) ;
F_2 ( * V_163 ++ , V_184 ) ;
}
