static unsigned long F_1 ( struct V_1 * V_1 )
{
return V_2 ;
}
static unsigned long F_2 ( struct V_1 * V_1 )
{
return V_3 ;
}
static unsigned long F_3 ( struct V_1 * V_1 )
{
return V_4 ;
}
static inline void T_1 * F_4 ( struct V_1 * V_5 )
{
if ( V_5 == & V_6 )
return V_7 ;
else if ( V_5 == & V_8 )
return V_9 ;
else if ( V_5 == & V_10 )
return V_11 ;
else if ( V_5 == & V_12 )
return V_13 ;
else if ( V_5 == & V_14 )
return V_15 ;
else if ( V_5 == & V_16 )
return V_17 ;
else if ( V_5 == & V_18 )
return V_19 ;
else if ( V_5 == & V_20 )
return V_21 ;
else
F_5 () ;
return NULL ;
}
static int F_6 ( struct V_1 * V_1 )
{
int V_22 = 0x100000 ;
void T_1 * V_23 ;
T_2 V_24 ;
V_23 = F_4 ( V_1 ) ;
V_24 = F_7 ( V_23 ) ;
V_24 &= ~ V_25 ;
V_24 &= ~ V_26 ;
if ( V_1 == & V_10 || V_1 == & V_18 )
V_24 |= V_26 ;
F_8 ( V_24 , V_23 ) ;
while ( ! ( F_7 ( V_23 ) & V_27 ) && -- V_22 )
F_9 () ;
if ( F_10 ( ! V_22 ) )
return - V_28 ;
V_24 = F_7 ( V_23 ) ;
V_24 |= V_29 ;
F_8 ( V_24 , V_23 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_1 )
{
void T_1 * V_23 ;
T_2 V_24 ;
V_23 = F_4 ( V_1 ) ;
V_24 = F_7 ( V_23 ) ;
V_24 &= ~ V_29 ;
V_24 |= V_25 ;
V_24 |= V_26 ;
if ( V_1 == & V_10 || V_1 == & V_18 )
V_24 &= ~ V_26 ;
F_8 ( V_24 , V_23 ) ;
}
static unsigned long F_12 ( struct V_1 * V_1 )
{
T_2 div = ( F_7 ( V_7 ) & V_30 ) >>
V_31 ;
return F_13 ( V_1 -> V_32 ) * div / 2 ;
}
static int F_14 ( struct V_1 * V_1 , unsigned long V_33 )
{
T_2 V_24 , div ;
if ( V_33 < V_34 || V_33 > V_35 )
return - V_36 ;
div = V_33 * 2 / F_13 ( V_1 -> V_32 ) ;
V_24 = F_7 ( V_7 ) ;
V_24 &= ~ V_30 ;
V_24 |= div << V_31 ;
F_8 ( V_24 , V_7 ) ;
return 0 ;
}
static unsigned long F_15 ( struct V_1 * V_1 )
{
T_2 div = ( F_7 ( V_21 ) & V_37 ) >>
V_38 ;
switch ( div ) {
case 0 :
return 25000000 ;
case 1 :
return 50000000 ;
case 2 :
return 100000000 ;
case 3 :
return 125000000 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_1 , unsigned long V_33 )
{
T_2 V_24 , div ;
switch ( V_33 ) {
case 25000000 :
div = 0 ;
break;
case 50000000 :
div = 1 ;
break;
case 100000000 :
div = 2 ;
break;
case 125000000 :
div = 3 ;
break;
default:
return - V_36 ;
}
V_24 = F_7 ( V_21 ) ;
V_24 &= ~ V_37 ;
V_24 |= div << V_38 ;
F_8 ( V_24 , V_21 ) ;
return 0 ;
}
static unsigned long F_17 ( struct V_1 * V_1 )
{
void T_1 * V_23 = ( V_1 == & V_12 ) ? V_13 : V_15 ;
unsigned long V_39 = F_13 ( V_1 -> V_32 ) ;
T_2 V_40 = F_7 ( V_23 + V_41 ) ;
T_2 V_42 = F_7 ( V_23 + V_43 ) ;
T_2 div = ( F_7 ( V_23 ) & V_44 ) >>
V_45 ;
return ( V_39 * div ) + ( ( V_39 / V_42 ) * V_40 ) ;
}
static int F_18 ( struct V_1 * V_1 , unsigned long V_33 )
{
void T_1 * V_23 = ( V_1 == & V_12 ) ? V_13 : V_15 ;
unsigned int V_39 = F_13 ( V_1 -> V_32 ) ;
T_2 V_24 , div ;
T_2 V_40 , V_42 = 1000000 ;
T_3 V_46 ;
if ( V_33 < V_34 || V_33 > V_35 )
return - V_36 ;
div = V_33 / V_39 ;
V_46 = ( V_47 ) ( V_33 - div * V_39 ) ;
V_46 *= V_42 ;
F_19 ( V_46 , V_39 ) ;
V_40 = V_46 ;
V_24 = F_7 ( V_23 ) ;
V_24 &= ~ V_44 ;
V_24 |= div << V_45 ;
F_8 ( V_24 , V_23 ) ;
F_8 ( V_40 , V_23 + V_41 ) ;
F_8 ( V_42 , V_23 + V_43 ) ;
return 0 ;
}
static void T_1 * F_20 ( struct V_1 * V_1 , T_2 * V_48 , T_2 * V_49 )
{
void T_1 * V_23 ;
if ( V_1 == & V_8 ) {
V_23 = V_9 ;
* V_48 = V_50 ;
* V_49 = V_51 ;
} else if ( V_1 == & V_10 ) {
V_23 = V_11 ;
* V_48 = V_52 ;
* V_49 = V_53 ;
} else if ( V_1 == & V_18 ) {
V_23 = V_19 ;
* V_48 = V_52 ;
* V_49 = V_53 ;
} else {
F_5 () ;
}
return V_23 ;
}
static unsigned long F_21 ( struct V_1 * V_1 )
{
void T_1 * V_23 ;
T_2 div , V_48 , V_49 ;
V_23 = F_20 ( V_1 , & V_48 , & V_49 ) ;
div = ( F_7 ( V_23 ) & V_49 ) >> V_48 ;
return ( div == 1 ) ? F_13 ( V_1 -> V_32 ) * 22 :
F_13 ( V_1 -> V_32 ) * 20 ;
}
static int F_22 ( struct V_1 * V_1 , unsigned long V_33 )
{
void T_1 * V_23 ;
T_2 V_24 , div , V_48 , V_49 ;
if ( V_33 == V_54 )
div = 1 ;
else if ( V_33 == V_55 )
div = 0 ;
else
return - V_36 ;
V_23 = F_20 ( V_1 , & V_48 , & V_49 ) ;
V_24 = F_7 ( V_23 ) ;
V_24 &= ~ V_49 ;
V_24 |= div << V_48 ;
F_8 ( V_24 , V_23 ) ;
return 0 ;
}
static unsigned long F_23 ( struct V_1 * V_1 )
{
V_47 V_56 = ( V_47 ) F_13 ( V_1 -> V_32 ) * 18 ;
T_2 V_57 , V_58 ;
if ( V_59 . V_60 == 0 )
V_59 . V_61 ( & V_59 ) ;
V_58 = V_1 -> V_62 - 7 ;
V_57 = F_7 ( V_1 -> V_63 ) >> V_58 & V_64 ;
F_19 ( V_56 , V_57 ) ;
return V_56 ;
}
static int F_24 ( struct V_1 * V_1 , unsigned long V_33 )
{
T_2 V_24 , V_57 , V_58 ;
V_47 V_56 = ( V_47 ) F_13 ( V_1 -> V_32 ) * 18 ;
if ( V_59 . V_60 == 0 )
V_59 . V_61 ( & V_59 ) ;
V_56 += V_33 / 2 ;
F_19 ( V_56 , V_33 ) ;
V_57 = V_56 ;
V_57 = ( V_57 < 12 ) ? 12 : V_57 ;
V_57 = ( V_57 > 35 ) ? 35 : V_57 ;
V_58 = V_1 -> V_62 - 7 ;
V_24 = F_7 ( V_1 -> V_63 ) ;
V_24 &= ~ ( V_64 << V_58 ) ;
V_24 |= V_57 << V_58 ;
F_8 ( V_24 , V_1 -> V_63 ) ;
V_56 = ( V_47 ) F_13 ( V_1 -> V_32 ) * 18 ;
F_19 ( V_56 , V_57 ) ;
if ( V_59 . V_60 == 0 )
V_59 . V_65 ( & V_59 ) ;
return 0 ;
}
static unsigned long F_25 ( struct V_1 * V_1 , unsigned long V_33 )
{
T_2 V_57 ;
V_47 V_56 ;
V_56 = ( V_47 ) F_13 ( V_1 -> V_32 ) * 18 ;
V_56 += V_33 / 2 ;
F_19 ( V_56 , V_33 ) ;
V_57 = V_56 ;
V_57 = ( V_57 < 12 ) ? 12 : V_57 ;
V_57 = ( V_57 > 35 ) ? 35 : V_57 ;
V_56 = ( V_47 ) F_13 ( V_1 -> V_32 ) * 18 ;
F_19 ( V_56 , V_57 ) ;
return V_56 ;
}
static int F_26 ( struct V_1 * V_1 )
{
T_2 V_24 ;
if ( V_59 . V_60 == 0 )
V_59 . V_61 ( & V_59 ) ;
V_24 = F_7 ( V_1 -> V_63 ) ;
V_24 &= ~ ( 1 << V_1 -> V_62 ) ;
F_8 ( V_24 , V_1 -> V_63 ) ;
if ( V_59 . V_60 == 0 )
V_59 . V_65 ( & V_59 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_1 )
{
T_2 V_24 ;
if ( V_59 . V_60 == 0 )
V_59 . V_61 ( & V_59 ) ;
V_24 = F_7 ( V_1 -> V_63 ) ;
V_24 |= 1 << V_1 -> V_62 ;
F_8 ( V_24 , V_1 -> V_63 ) ;
if ( V_59 . V_60 == 0 )
V_59 . V_65 ( & V_59 ) ;
}
static unsigned long F_28 ( struct V_1 * V_1 )
{
return F_13 ( V_1 -> V_32 ) / 2 ;
}
static unsigned long F_29 ( struct V_1 * V_1 )
{
return F_13 ( V_1 -> V_32 ) / 2 ;
}
static unsigned long F_30 ( struct V_1 * V_1 )
{
return F_13 ( V_1 -> V_32 ) / 4 ;
}
static unsigned long F_31 ( struct V_1 * V_1 )
{
return F_13 ( V_1 -> V_32 ) / 6 ;
}
static unsigned long F_32 ( struct V_1 * V_1 )
{
return F_13 ( V_1 -> V_32 ) / 8 ;
}
static int F_33 ( struct V_1 * V_1 , struct V_1 * V_32 )
{
T_2 V_24 = F_7 ( V_66 ) ;
if ( V_32 == & V_6 ) {
V_24 &= ~ V_67 ;
V_24 &= ~ V_68 ;
} else if ( V_32 == & V_69 ) {
V_24 |= V_67 ;
V_24 &= ~ V_68 ;
} else if ( V_32 == & V_70 ) {
V_24 |= V_67 ;
V_24 |= V_68 ;
} else {
return - V_36 ;
}
F_8 ( V_24 , V_66 ) ;
return 0 ;
}
static void F_34 ( T_2 div , T_2 * V_71 , T_2 * V_72 )
{
T_2 V_73 , V_74 , V_75 , V_76 ;
if ( div >= 512 ) {
* V_71 = 8 ;
* V_72 = 64 ;
} else if ( div >= 8 ) {
V_73 = ( div - 1 ) / 64 + 1 ;
V_75 = 8 ;
for ( V_74 = 8 ; V_74 >= V_73 ; V_74 -- ) {
V_76 = div % V_74 ;
if ( V_76 == 0 ) {
* V_71 = V_74 ;
break;
}
V_76 = V_74 - V_76 ;
if ( V_76 < V_75 ) {
V_75 = V_76 ;
* V_71 = V_74 ;
}
}
* V_72 = ( div + * V_71 - 1 ) / * V_71 ;
} else if ( div < 8 ) {
* V_71 = div ;
* V_72 = 1 ;
}
}
static int F_35 ( struct V_1 * V_1 )
{
T_2 V_23 ;
V_23 = F_7 ( V_1 -> V_63 ) ;
V_23 |= 0x3 << V_1 -> V_62 ;
F_8 ( V_23 , V_1 -> V_63 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_1 )
{
T_2 V_23 ;
V_23 = F_7 ( V_1 -> V_63 ) ;
V_23 &= ~ ( 0x3 << V_1 -> V_62 ) ;
F_8 ( V_23 , V_1 -> V_63 ) ;
}
static unsigned long F_37 ( struct V_1 * V_1 )
{
T_2 V_24 = F_7 ( V_77 ) ;
V_24 &= ( V_1 == & V_78 ) ? V_79 :
V_80 ;
if ( V_24 )
return F_13 ( V_1 -> V_32 ) / 7 ;
else
return F_13 ( V_1 -> V_32 ) * 2 / 7 ;
}
static int F_38 ( struct V_1 * V_1 , unsigned long V_33 )
{
unsigned long V_39 = F_13 ( V_1 -> V_32 ) ;
T_2 V_24 = F_7 ( V_77 ) ;
if ( V_33 * 7 <= V_39 + V_39 / 20 )
V_24 |= V_79 ;
else
V_24 &= ~ V_79 ;
F_8 ( V_24 , V_77 ) ;
return 0 ;
}
static unsigned long F_39 ( struct V_1 * V_1 , unsigned long V_33 )
{
unsigned long V_39 = F_13 ( V_1 -> V_32 ) ;
if ( V_33 * 7 <= V_39 + V_39 / 20 )
return V_39 / 7 ;
else
return 2 * V_39 / 7 ;
}
static unsigned long F_40 ( struct V_1 * V_1 )
{
struct V_81 * V_82 ;
T_2 V_24 , V_71 , V_72 ;
int V_83 , V_84 ;
if ( V_1 == & V_78 || V_1 == & V_85 )
return F_37 ( V_1 ) ;
V_84 = F_41 ( V_86 ) ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ )
if ( V_86 [ V_83 ] -> V_1 == V_1 ) {
V_82 = V_86 [ V_83 ] ;
break;
}
if ( V_83 == V_84 )
return F_13 ( V_1 -> V_32 ) ;
V_24 = F_7 ( V_82 -> V_23 ) ;
V_71 = ( ( V_24 & V_82 -> V_87 ) >> V_82 -> V_88 ) + 1 ;
V_72 = ( ( V_24 & V_82 -> V_89 ) >> V_82 -> V_90 ) + 1 ;
return F_13 ( V_1 -> V_32 ) / ( V_71 * V_72 ) ;
}
static int F_42 ( struct V_1 * V_1 )
{
int V_22 = 0x100000 ;
T_2 V_49 ;
if ( V_1 == & V_91 )
V_49 = V_92 ;
else if ( V_1 == & V_93 )
V_49 = V_94 ;
else if ( V_1 == & V_95 )
V_49 = V_96 ;
else if ( V_1 == & V_97 )
V_49 = V_98 ;
else if ( V_1 == & V_99 )
V_49 = V_100 ;
else
return - V_36 ;
while ( ( F_7 ( V_101 ) & V_49 ) && -- V_22 )
F_9 () ;
if ( F_10 ( ! V_22 ) )
return - V_28 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_1 , unsigned long V_33 )
{
unsigned long V_39 = F_13 ( V_1 -> V_32 ) ;
struct V_81 * V_82 ;
T_2 V_24 , div , V_102 , V_71 = 0 , V_72 ;
int V_83 , V_84 ;
if ( V_1 == & V_78 || V_1 == & V_85 )
return F_38 ( V_1 , V_33 ) ;
V_84 = F_41 ( V_86 ) ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ )
if ( V_86 [ V_83 ] -> V_1 == V_1 ) {
V_82 = V_86 [ V_83 ] ;
break;
}
if ( V_83 == V_84 )
return - V_36 ;
V_102 = ( ( V_82 -> V_87 >> V_82 -> V_88 ) + 1 ) *
( ( V_82 -> V_89 >> V_82 -> V_90 ) + 1 ) ;
div = V_39 / V_33 ;
if ( div == 0 )
div ++ ;
if ( ( V_39 / div != V_33 ) || div > V_102 )
return - V_36 ;
if ( V_82 -> V_87 ) {
F_34 ( div , & V_71 , & V_72 ) ;
} else {
V_71 = 1 ;
V_72 = div ;
}
V_24 = F_7 ( V_82 -> V_23 ) ;
V_24 &= ~ ( V_82 -> V_87 | V_82 -> V_89 ) ;
V_24 |= ( V_71 - 1 ) << V_82 -> V_88 | ( V_72 - 1 ) << V_82 -> V_90 ;
F_8 ( V_24 , V_82 -> V_23 ) ;
if ( V_1 == & V_91 || V_1 == & V_93 ||
V_1 == & V_95 || V_1 == & V_99 )
return F_42 ( V_1 ) ;
return 0 ;
}
static unsigned long F_44 ( struct V_1 * V_1 , unsigned long V_33 )
{
unsigned long V_39 = F_13 ( V_1 -> V_32 ) ;
T_2 div = V_39 / V_33 ;
T_2 V_103 , V_71 = 0 , V_72 ;
struct V_81 * V_82 ;
int V_83 , V_84 ;
if ( V_1 == & V_78 || V_1 == & V_85 )
return F_39 ( V_1 , V_33 ) ;
V_84 = F_41 ( V_86 ) ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ )
if ( V_86 [ V_83 ] -> V_1 == V_1 ) {
V_82 = V_86 [ V_83 ] ;
break;
}
if ( V_83 == V_84 )
return - V_36 ;
if ( div == 0 || V_39 % V_33 )
div ++ ;
if ( V_82 -> V_87 ) {
F_34 ( div , & V_71 , & V_72 ) ;
div = V_71 * V_72 ;
} else {
V_103 = ( V_82 -> V_89 >> V_82 -> V_90 ) + 1 ;
if ( div > V_103 )
div = V_103 ;
}
return V_39 / div ;
}
static int F_45 ( struct V_1 * V_1 , struct V_1 * V_32 )
{
struct V_104 * V_105 ;
int V_83 , V_84 ;
T_2 V_24 ;
V_84 = F_41 ( V_106 ) ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ )
if ( V_106 [ V_83 ] -> V_1 == V_1 ) {
V_105 = V_106 [ V_83 ] ;
break;
}
if ( V_83 == V_84 )
return - V_36 ;
V_83 = 0 ;
while ( V_105 -> V_107 [ V_83 ] ) {
if ( V_32 == V_105 -> V_107 [ V_83 ] )
break;
V_83 ++ ;
}
if ( ! V_105 -> V_107 [ V_83 ] )
return - V_36 ;
V_24 = F_7 ( V_105 -> V_23 ) ;
V_24 &= ~ V_105 -> V_49 ;
V_24 |= V_83 << V_105 -> V_48 ;
F_8 ( V_24 , V_105 -> V_23 ) ;
if ( V_1 == & V_97 )
return F_42 ( V_1 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_1 )
{
T_2 V_24 ;
V_24 = F_7 ( V_21 ) ;
V_24 |= V_108 ;
F_8 ( V_24 , V_21 ) ;
return F_35 ( V_1 ) ;
}
static void F_47 ( struct V_1 * V_1 )
{
T_2 V_24 ;
F_36 ( V_1 ) ;
V_24 = F_7 ( V_21 ) ;
V_24 &= V_108 ;
F_8 ( V_24 , V_21 ) ;
}
static int F_48 ( struct V_1 * V_1 )
{
T_2 V_24 ;
V_24 = F_7 ( V_21 ) ;
V_24 |= V_109 ;
F_8 ( V_24 , V_21 ) ;
return F_35 ( V_1 ) ;
}
static void F_49 ( struct V_1 * V_1 )
{
T_2 V_24 ;
F_36 ( V_1 ) ;
V_24 = F_7 ( V_21 ) ;
V_24 &= V_109 ;
F_8 ( V_24 , V_21 ) ;
}
int F_50 ( enum V_110 V_111 )
{
T_2 V_24 = F_7 ( V_112 ) ;
V_24 &= ~ V_113 ;
switch ( V_111 ) {
case V_114 :
break;
case V_115 :
V_24 |= 0x1 << V_116 ;
break;
case V_117 :
V_24 |= 0x2 << V_116 ;
break;
case V_118 :
V_24 |= 0x1 << V_116 ;
V_24 &= ~ V_119 ;
V_24 &= ~ V_120 ;
break;
case V_121 :
V_24 |= 0x2 << V_116 ;
V_24 |= 0x3 << V_122 ;
V_24 |= V_119 ;
V_24 |= V_120 ;
break;
default:
return - V_36 ;
}
F_8 ( V_24 , V_112 ) ;
return 0 ;
}
void T_4 F_51 ( void )
{
F_52 ( V_123 , F_41 ( V_123 ) ) ;
}
int T_4 F_53 ( void )
{
struct V_124 * V_125 ;
void T_1 * V_126 ;
int V_83 , V_127 ;
F_54 (np, NULL, L_1 ) {
T_2 V_33 ;
if ( F_55 ( V_125 , L_2 , & V_33 ) )
continue;
if ( F_56 ( V_125 , L_3 ) )
V_4 = V_33 ;
else if ( F_56 ( V_125 , L_4 ) )
V_3 = V_33 ;
else if ( F_56 ( V_125 , L_5 ) )
V_2 = V_33 ;
}
for ( V_83 = 0 ; V_83 < F_41 ( V_128 ) ; V_83 ++ )
F_57 ( & V_128 [ V_83 ] ) ;
F_8 ( 0x3 << V_129 | 0x3 << V_130 | 0x3 << V_131 , V_132 ) ;
F_8 ( 0x3 << V_133 | 0x3 << V_134 | 0x3 << V_135 , V_136 ) ;
F_8 ( 0x3 << V_135 | 0x3 << V_137 , V_138 ) ;
F_8 ( 0x3 << V_139 | 0x3 << V_140 | 0x3 << V_141 , V_142 ) ;
F_8 ( 0x3 << V_129 , V_143 ) ;
F_8 ( 0 , V_144 ) ;
F_8 ( 0 , V_145 ) ;
F_58 ( & V_146 ) ;
F_58 ( & V_95 ) ;
F_59 ( & V_12 , V_34 ) ;
F_59 ( & V_14 , V_34 ) ;
F_60 ( & V_147 , & V_148 ) ;
F_60 ( & V_148 , & V_14 ) ;
F_60 ( & V_149 , & V_150 ) ;
F_59 ( & V_149 , V_151 ) ;
F_60 ( & V_152 , & V_95 ) ;
F_59 ( & V_152 , V_54 ) ;
F_60 ( & V_153 , & V_10 ) ;
F_59 ( & V_153 , 1500000 ) ;
F_59 ( & V_154 , 11000000 ) ;
F_59 ( & V_155 , 49500000 ) ;
F_59 ( & V_156 , 49500000 ) ;
F_59 ( & V_157 , 49500000 ) ;
F_59 ( & V_158 , 49500000 ) ;
V_125 = F_61 ( NULL , NULL , L_6 ) ;
V_126 = F_62 ( V_125 , 0 ) ;
F_63 ( ! V_126 ) ;
V_127 = F_64 ( V_125 , 0 ) ;
F_65 ( & V_159 , V_126 , V_127 ) ;
return 0 ;
}
