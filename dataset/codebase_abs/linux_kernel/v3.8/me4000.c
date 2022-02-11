static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_8 = F_3 ( V_4 , 5 ) ;
T_1 V_9 = 0 ;
T_2 V_10 ;
int V_11 = 0 ;
int V_12 = 0 ;
if ( ! V_8 )
return - V_13 ;
F_4 ( & V_10 ) ;
F_5 ( 0x10 , V_6 -> V_14 + V_15 ) ;
V_9 = F_6 ( V_6 -> V_14 + V_16 ) ;
V_9 |= 0x100 ;
F_5 ( V_9 , V_6 -> V_14 + V_16 ) ;
F_7 ( V_8 + 0xC8 ) ;
F_8 ( 20 ) ;
if ( ! ( F_6 ( V_6 -> V_14 + V_15 ) & 0x20 ) ) {
F_9 ( V_2 -> V_17 , L_1 ) ;
return - V_18 ;
}
V_9 = F_6 ( V_6 -> V_14 + V_16 ) ;
V_9 &= ~ 0x100 ;
F_5 ( V_9 , V_6 -> V_14 + V_16 ) ;
if ( V_19 ) {
F_9 ( V_2 -> V_17 ,
L_2 ) ;
return - V_18 ;
} else {
V_12 = ( V_20 [ 0 ] << 24 ) + ( V_20 [ 1 ] << 16 ) +
( V_20 [ 2 ] << 8 ) + V_20 [ 3 ] ;
F_8 ( 10 ) ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
F_10 ( V_20 [ 16 + V_11 ] , V_8 ) ;
F_8 ( 10 ) ;
if ( F_6 ( V_6 -> V_14 + V_16 ) & 0x20 ) {
F_9 ( V_2 -> V_17 ,
L_3 ,
V_11 ) ;
return - V_18 ;
}
}
}
if ( F_6 ( V_6 -> V_14 + V_16 ) & 0x4 ) {
} else {
F_9 ( V_2 -> V_17 , L_4 ) ;
F_9 ( V_2 -> V_17 , L_5 ) ;
return - V_18 ;
}
V_9 = F_6 ( V_6 -> V_14 + V_16 ) ;
V_9 |= 0x100 ;
F_5 ( V_9 , V_6 -> V_14 + V_16 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_21 ;
int V_22 ;
V_21 = F_6 ( V_6 -> V_14 + V_16 ) ;
V_21 |= 0x40000000 ;
F_5 ( V_21 , V_6 -> V_14 + V_16 ) ;
V_21 &= ~ 0x40000000 ;
F_5 ( V_21 , V_6 -> V_14 + V_16 ) ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ )
F_5 ( 0x8000 , V_2 -> V_23 + F_12 ( V_22 ) ) ;
F_5 ( V_24 | V_25 ,
V_2 -> V_23 + V_26 ) ;
V_21 = V_27 | V_28 ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ )
F_5 ( V_21 , V_2 -> V_23 + F_13 ( V_22 ) ) ;
F_5 ( 0x43 , V_6 -> V_14 + V_15 ) ;
F_5 ( V_29 ,
V_2 -> V_23 + V_30 ) ;
if ( ! ( F_6 ( V_2 -> V_23 + V_31 ) & 0x1 ) )
F_5 ( 0x1 , V_2 -> V_23 + V_32 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
struct V_35 * V_36 , unsigned int * V_37 )
{
const struct V_38 * V_39 = F_15 ( V_2 ) ;
int V_22 = F_16 ( V_36 -> V_40 ) ;
int V_41 = F_17 ( V_36 -> V_40 ) ;
int V_42 = F_18 ( V_36 -> V_40 ) ;
unsigned long V_43 = 0 ;
unsigned long V_44 ;
long V_45 ;
if ( V_36 -> V_46 == 0 ) {
return 0 ;
} else if ( V_36 -> V_46 > 1 ) {
F_9 ( V_2 -> V_17 , L_6 ,
V_36 -> V_46 ) ;
return - V_47 ;
}
switch ( V_41 ) {
case 0 :
V_43 |= V_48 ;
break;
case 1 :
V_43 |= V_49 ;
break;
case 2 :
V_43 |= V_50 ;
break;
case 3 :
V_43 |= V_51 ;
break;
default:
F_9 ( V_2 -> V_17 , L_7 ) ;
return - V_47 ;
}
switch ( V_42 ) {
case V_52 :
case V_53 :
if ( V_22 >= V_39 -> V_54 ) {
F_9 ( V_2 -> V_17 ,
L_8 ) ;
return - V_47 ;
}
V_43 |= V_55 | V_22 ;
break;
case V_56 :
if ( V_41 == 0 || V_41 == 1 ) {
F_9 ( V_2 -> V_17 ,
L_9 ) ;
return - V_47 ;
}
if ( V_22 >= V_39 -> V_57 ) {
F_9 ( V_2 -> V_17 ,
L_8 ) ;
return - V_47 ;
}
V_43 |= V_58 | V_22 ;
break;
default:
F_9 ( V_2 -> V_17 , L_10 ) ;
return - V_47 ;
}
V_43 |= V_59 ;
V_44 = F_6 ( V_2 -> V_23 + V_26 ) ;
V_44 &= ~ ( V_60 |
V_61 |
V_25 | V_24 ) ;
F_5 ( V_44 , V_2 -> V_23 + V_26 ) ;
V_44 &= ~ ( V_62 | V_63 |
V_64 ) ;
F_5 ( V_44 , V_2 -> V_23 + V_26 ) ;
V_44 |= V_60 | V_61 ;
F_5 ( V_44 , V_2 -> V_23 + V_26 ) ;
F_5 ( V_43 , V_2 -> V_23 + V_65 ) ;
F_5 ( V_66 , V_2 -> V_23 + V_67 ) ;
F_5 ( V_66 , V_2 -> V_23 + V_68 ) ;
F_6 ( V_2 -> V_23 + V_69 ) ;
F_8 ( 10 ) ;
if ( ! ( F_6 ( V_2 -> V_23 + V_70 ) &
V_71 ) ) {
F_9 ( V_2 -> V_17 , L_11 ) ;
return - V_18 ;
}
V_45 = F_6 ( V_2 -> V_23 + V_72 ) & 0xFFFF ;
V_37 [ 0 ] = V_45 ^ 0x8000 ;
return 1 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_33 * V_73 )
{
unsigned long V_44 ;
V_44 = F_6 ( V_2 -> V_23 + V_26 ) ;
V_44 &= ~ ( V_25 | V_24 ) ;
F_5 ( V_44 , V_2 -> V_23 + V_26 ) ;
F_5 ( 0x0 , V_2 -> V_23 + V_26 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_33 * V_73 , struct V_74 * V_75 )
{
const struct V_38 * V_39 = F_15 ( V_2 ) ;
int V_42 ;
int V_76 ;
if ( ! V_75 -> V_77 ) {
F_9 ( V_2 -> V_17 , L_12 ) ;
return - V_47 ;
}
if ( V_75 -> V_77 > V_78 ) {
F_9 ( V_2 -> V_17 , L_13 ) ;
return - V_47 ;
}
if ( ! V_75 -> V_79 ) {
F_9 ( V_2 -> V_17 , L_14 ) ;
return - V_80 ;
}
V_42 = F_18 ( V_75 -> V_79 [ 0 ] ) ;
for ( V_76 = 0 ; V_76 < V_75 -> V_77 ; V_76 ++ ) {
if ( F_18 ( V_75 -> V_79 [ V_76 ] ) != V_42 ) {
F_9 ( V_2 -> V_17 ,
L_15 ) ;
return - V_47 ;
}
}
if ( V_42 == V_81 ) {
for ( V_76 = 0 ; V_76 < V_75 -> V_77 ; V_76 ++ ) {
if ( F_16 ( V_75 -> V_79 [ V_76 ] ) >=
V_39 -> V_57 ) {
F_9 ( V_2 -> V_17 ,
L_16 ) ;
return - V_47 ;
}
}
} else {
for ( V_76 = 0 ; V_76 < V_75 -> V_77 ; V_76 ++ ) {
if ( F_16 ( V_75 -> V_79 [ V_76 ] ) >= V_39 -> V_54 ) {
F_9 ( V_2 -> V_17 ,
L_16 ) ;
return - V_47 ;
}
}
}
if ( V_42 == V_81 ) {
for ( V_76 = 0 ; V_76 < V_75 -> V_77 ; V_76 ++ ) {
if ( F_17 ( V_75 -> V_79 [ V_76 ] ) != 1 &&
F_17 ( V_75 -> V_79 [ V_76 ] ) != 2 ) {
F_9 ( V_2 -> V_17 ,
L_17 ) ;
return - V_47 ;
}
}
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_33 * V_73 ,
struct V_74 * V_75 ,
unsigned int * V_82 ,
unsigned int * V_83 , unsigned int * V_84 )
{
int V_85 ;
* V_82 = 0 ;
* V_83 = 0 ;
* V_84 = 0 ;
if ( V_75 -> V_86 ) {
* V_82 = ( V_75 -> V_86 * 33 ) / 1000 ;
V_85 = ( V_75 -> V_86 * 33 ) % 1000 ;
if ( ( V_75 -> V_87 & V_88 ) == V_89 ) {
if ( V_85 > 33 )
( * V_82 ) ++ ;
} else if ( ( V_75 -> V_87 & V_88 ) == V_90 ) {
if ( V_85 )
( * V_82 ) ++ ;
}
}
if ( V_75 -> V_91 ) {
* V_83 = ( V_75 -> V_91 * 33 ) / 1000 ;
V_85 = ( V_75 -> V_91 * 33 ) % 1000 ;
if ( ( V_75 -> V_87 & V_88 ) == V_89 ) {
if ( V_85 > 33 )
( * V_83 ) ++ ;
} else if ( ( V_75 -> V_87 & V_88 ) == V_90 ) {
if ( V_85 )
( * V_83 ) ++ ;
}
}
if ( V_75 -> V_92 ) {
* V_84 = ( V_75 -> V_92 * 33 ) / 1000 ;
V_85 = ( V_75 -> V_92 * 33 ) % 1000 ;
if ( ( V_75 -> V_87 & V_88 ) == V_89 ) {
if ( V_85 > 33 )
( * V_84 ) ++ ;
} else if ( ( V_75 -> V_87 & V_88 ) == V_90 ) {
if ( V_85 )
( * V_84 ) ++ ;
}
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
unsigned int V_82 ,
unsigned int V_83 , unsigned int V_84 )
{
F_5 ( V_82 - 1 , V_2 -> V_23 + V_93 ) ;
F_5 ( 0x0 , V_2 -> V_23 + V_94 ) ;
if ( V_83 ) {
F_5 ( V_83 - 1 , V_2 -> V_23 + V_95 ) ;
F_5 ( 0x0 , V_2 -> V_23 + V_96 ) ;
}
F_5 ( V_84 - 1 , V_2 -> V_23 + V_68 ) ;
F_5 ( V_84 - 1 , V_2 -> V_23 + V_67 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_33 * V_73 , struct V_74 * V_75 )
{
unsigned int V_43 ;
unsigned int V_22 ;
unsigned int V_41 ;
unsigned int V_42 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_75 -> V_77 ; V_76 ++ ) {
V_22 = F_16 ( V_75 -> V_79 [ V_76 ] ) ;
V_41 = F_17 ( V_75 -> V_79 [ V_76 ] ) ;
V_42 = F_18 ( V_75 -> V_79 [ V_76 ] ) ;
V_43 = V_22 ;
if ( V_41 == 0 )
V_43 |= V_48 ;
else if ( V_41 == 1 )
V_43 |= V_49 ;
else if ( V_41 == 2 )
V_43 |= V_50 ;
else
V_43 |= V_51 ;
if ( V_42 == V_81 )
V_43 |= V_58 ;
else
V_43 |= V_55 ;
F_5 ( V_43 , V_2 -> V_23 + V_65 ) ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_33 * V_73 ,
struct V_74 * V_75 ,
unsigned int V_82 ,
unsigned int V_83 , unsigned int V_84 )
{
unsigned long V_44 = 0 ;
F_22 ( V_2 , V_82 , V_83 , V_84 ) ;
F_5 ( V_44 , V_2 -> V_23 + V_26 ) ;
if ( ( V_75 -> V_97 == V_98 &&
V_75 -> V_99 == V_100 &&
V_75 -> V_101 == V_100 ) ||
( V_75 -> V_97 == V_98 &&
V_75 -> V_99 == V_102 &&
V_75 -> V_101 == V_100 ) ) {
V_44 = V_63 |
V_60 |
V_61 ;
} else if ( V_75 -> V_97 == V_98 &&
V_75 -> V_99 == V_98 &&
V_75 -> V_101 == V_100 ) {
V_44 = V_64 |
V_60 |
V_61 ;
} else if ( V_75 -> V_97 == V_98 &&
V_75 -> V_99 == V_98 &&
V_75 -> V_101 == V_98 ) {
V_44 = V_62 |
V_63 |
V_60 |
V_61 ;
} else {
V_44 = V_62 |
V_60 |
V_61 ;
}
if ( V_75 -> V_103 == V_104 ) {
F_5 ( V_75 -> V_77 * V_75 -> V_105 ,
V_2 -> V_23 + V_106 ) ;
V_44 |= V_107 | V_108 ;
} else if ( V_75 -> V_103 == V_109 &&
V_75 -> V_110 == V_104 ) {
F_5 ( V_75 -> V_111 ,
V_2 -> V_23 + V_106 ) ;
V_44 |= V_107 | V_108 ;
} else {
V_44 |= V_107 ;
}
F_5 ( V_44 , V_2 -> V_23 + V_26 ) ;
F_23 ( V_2 , V_73 , V_75 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_33 * V_73 )
{
int V_112 ;
unsigned int V_82 = 0 ;
unsigned int V_83 = 0 ;
unsigned int V_84 = 0 ;
struct V_74 * V_75 = & V_73 -> V_113 -> V_75 ;
V_112 = F_19 ( V_2 , V_73 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_21 ( V_2 ,
V_73 , V_75 , & V_82 , & V_83 , & V_84 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_24 ( V_2 , V_73 , V_75 , V_82 , V_83 , V_84 ) ;
if ( V_112 )
return V_112 ;
F_6 ( V_2 -> V_23 + V_69 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_33 * V_73 ,
struct V_74 * V_75 )
{
unsigned int V_82 ;
unsigned int V_84 ;
unsigned int V_83 ;
int V_112 = 0 ;
V_75 -> V_87 &= V_89 | V_90 | V_114 ;
F_21 ( V_2 , V_73 , V_75 , & V_82 , & V_83 , & V_84 ) ;
V_112 |= F_27 ( & V_75 -> V_97 , V_115 | V_98 ) ;
V_112 |= F_27 ( & V_75 -> V_99 ,
V_102 | V_100 | V_98 ) ;
V_112 |= F_27 ( & V_75 -> V_101 , V_100 | V_98 ) ;
V_112 |= F_27 ( & V_75 -> V_110 ,
V_109 | V_104 ) ;
V_112 |= F_27 ( & V_75 -> V_103 , V_109 | V_104 ) ;
if ( V_112 )
return 1 ;
V_112 |= F_28 ( V_75 -> V_97 ) ;
V_112 |= F_28 ( V_75 -> V_99 ) ;
V_112 |= F_28 ( V_75 -> V_101 ) ;
V_112 |= F_28 ( V_75 -> V_110 ) ;
V_112 |= F_28 ( V_75 -> V_103 ) ;
if ( V_75 -> V_97 == V_115 &&
V_75 -> V_99 == V_100 &&
V_75 -> V_101 == V_100 ) {
} else if ( V_75 -> V_97 == V_115 &&
V_75 -> V_99 == V_102 &&
V_75 -> V_101 == V_100 ) {
} else if ( V_75 -> V_97 == V_98 &&
V_75 -> V_99 == V_100 &&
V_75 -> V_101 == V_100 ) {
} else if ( V_75 -> V_97 == V_98 &&
V_75 -> V_99 == V_102 &&
V_75 -> V_101 == V_100 ) {
} else if ( V_75 -> V_97 == V_98 &&
V_75 -> V_99 == V_98 &&
V_75 -> V_101 == V_100 ) {
} else if ( V_75 -> V_97 == V_98 &&
V_75 -> V_99 == V_98 &&
V_75 -> V_101 == V_98 ) {
} else {
V_112 |= - V_47 ;
}
if ( V_75 -> V_103 == V_109 && V_75 -> V_110 == V_109 ) {
} else if ( V_75 -> V_103 == V_104 &&
V_75 -> V_110 == V_109 ) {
} else if ( V_75 -> V_103 == V_109 &&
V_75 -> V_110 == V_104 ) {
} else if ( V_75 -> V_103 == V_104 &&
V_75 -> V_110 == V_104 ) {
} else {
V_112 |= - V_47 ;
}
if ( V_112 )
return 2 ;
if ( V_75 -> V_77 < 1 ) {
V_75 -> V_77 = 1 ;
V_112 |= - V_47 ;
}
if ( V_82 < 66 ) {
V_75 -> V_86 = 2000 ;
V_112 |= - V_47 ;
}
if ( V_83 && V_83 < 67 ) {
V_75 -> V_91 = 2031 ;
V_112 |= - V_47 ;
}
if ( V_84 < 66 ) {
V_75 -> V_92 = 2000 ;
V_112 |= - V_47 ;
}
if ( V_112 )
return 3 ;
if ( V_75 -> V_97 == V_115 &&
V_75 -> V_99 == V_100 &&
V_75 -> V_101 == V_100 ) {
if ( V_82 < V_66 ) {
F_9 ( V_2 -> V_17 , L_18 ) ;
V_75 -> V_86 = 2000 ;
V_112 ++ ;
}
if ( V_84 < V_66 ) {
F_9 ( V_2 -> V_17 , L_19 ) ;
V_75 -> V_92 = 2000 ;
V_112 ++ ;
}
if ( V_83 <= V_75 -> V_77 * V_84 ) {
F_9 ( V_2 -> V_17 , L_20 ) ;
V_75 -> V_111 = 2000 * V_75 -> V_77 + 31 ;
V_112 ++ ;
}
} else if ( V_75 -> V_97 == V_115 &&
V_75 -> V_99 == V_102 &&
V_75 -> V_101 == V_100 ) {
if ( V_82 < V_66 ) {
F_9 ( V_2 -> V_17 , L_18 ) ;
V_75 -> V_86 = 2000 ;
V_112 ++ ;
}
if ( V_84 < V_66 ) {
F_9 ( V_2 -> V_17 , L_19 ) ;
V_75 -> V_92 = 2000 ;
V_112 ++ ;
}
} else if ( V_75 -> V_97 == V_98 &&
V_75 -> V_99 == V_100 &&
V_75 -> V_101 == V_100 ) {
if ( V_82 < V_66 ) {
F_9 ( V_2 -> V_17 , L_18 ) ;
V_75 -> V_86 = 2000 ;
V_112 ++ ;
}
if ( V_84 < V_66 ) {
F_9 ( V_2 -> V_17 , L_19 ) ;
V_75 -> V_92 = 2000 ;
V_112 ++ ;
}
if ( V_83 <= V_75 -> V_77 * V_84 ) {
F_9 ( V_2 -> V_17 , L_20 ) ;
V_75 -> V_111 = 2000 * V_75 -> V_77 + 31 ;
V_112 ++ ;
}
} else if ( V_75 -> V_97 == V_98 &&
V_75 -> V_99 == V_102 &&
V_75 -> V_101 == V_100 ) {
if ( V_82 < V_66 ) {
F_9 ( V_2 -> V_17 , L_18 ) ;
V_75 -> V_86 = 2000 ;
V_112 ++ ;
}
if ( V_84 < V_66 ) {
F_9 ( V_2 -> V_17 , L_19 ) ;
V_75 -> V_92 = 2000 ;
V_112 ++ ;
}
} else if ( V_75 -> V_97 == V_98 &&
V_75 -> V_99 == V_98 &&
V_75 -> V_101 == V_100 ) {
if ( V_82 < V_66 ) {
F_9 ( V_2 -> V_17 , L_18 ) ;
V_75 -> V_86 = 2000 ;
V_112 ++ ;
}
if ( V_84 < V_66 ) {
F_9 ( V_2 -> V_17 , L_19 ) ;
V_75 -> V_92 = 2000 ;
V_112 ++ ;
}
} else if ( V_75 -> V_97 == V_98 &&
V_75 -> V_99 == V_98 &&
V_75 -> V_101 == V_98 ) {
if ( V_82 < V_66 ) {
F_9 ( V_2 -> V_17 , L_18 ) ;
V_75 -> V_86 = 2000 ;
V_112 ++ ;
}
}
if ( V_75 -> V_103 == V_104 ) {
if ( V_75 -> V_105 == 0 ) {
F_9 ( V_2 -> V_17 , L_21 ) ;
V_75 -> V_105 = 1 ;
V_112 ++ ;
}
}
if ( V_75 -> V_110 == V_104 ) {
if ( V_75 -> V_111 == 0 ) {
F_9 ( V_2 -> V_17 , L_20 ) ;
V_75 -> V_111 = 1 ;
V_112 ++ ;
}
}
if ( V_112 )
return 4 ;
if ( F_20 ( V_2 , V_73 , V_75 ) )
return 5 ;
return 0 ;
}
static T_3 F_29 ( int V_116 , void * V_117 )
{
unsigned int V_44 ;
struct V_1 * V_2 = V_117 ;
struct V_33 * V_73 = & V_2 -> V_118 [ 0 ] ;
int V_76 ;
int V_119 = 0 ;
long V_45 ;
if ( ! V_2 -> V_120 )
return V_121 ;
V_73 -> V_113 -> V_122 = 0 ;
if ( V_116 != V_2 -> V_116 ) {
F_9 ( V_2 -> V_17 , L_22 , V_116 ) ;
return V_123 ;
}
if ( F_6 ( V_2 -> V_23 + V_124 ) &
V_125 ) {
V_44 = F_6 ( V_2 -> V_23 + V_26 ) ;
if ( ! ( V_44 & V_126 ) &&
! ( V_44 & V_127 ) &&
( V_44 & V_71 ) ) {
V_119 = V_128 ;
V_44 |= V_24 ;
V_44 &= ~ ( V_107 |
V_108 ) ;
F_5 ( V_44 , V_2 -> V_23 + V_26 ) ;
V_73 -> V_113 -> V_122 |= V_129 | V_130 ;
F_9 ( V_2 -> V_17 , L_23 ) ;
} else if ( ( V_44 & V_126 )
&& ! ( V_44 & V_127 )
&& ( V_44 & V_71 ) ) {
V_73 -> V_113 -> V_122 |= V_131 ;
V_119 = V_128 / 2 ;
} else {
F_9 ( V_2 -> V_17 ,
L_24 ) ;
V_119 = 0 ;
V_44 |= V_24 ;
V_44 &= ~ ( V_107 |
V_108 ) ;
F_5 ( V_44 , V_2 -> V_23 + V_26 ) ;
V_73 -> V_113 -> V_122 |= V_129 | V_130 ;
F_9 ( V_2 -> V_17 , L_25 ) ;
}
for ( V_76 = 0 ; V_76 < V_119 ; V_76 ++ ) {
V_45 = F_6 ( V_2 -> V_23 + V_72 ) & 0xFFFF ;
V_45 ^= 0x8000 ;
if ( ! F_30 ( V_73 -> V_113 , V_45 ) ) {
V_44 |= V_24 ;
V_44 &= ~ ( V_107 |
V_108 ) ;
F_5 ( V_44 , V_2 -> V_23 + V_26 ) ;
V_73 -> V_113 -> V_122 |= V_132 ;
F_9 ( V_2 -> V_17 , L_26 ) ;
break;
}
}
V_44 |= V_133 ;
F_5 ( V_44 , V_2 -> V_23 + V_26 ) ;
V_44 &= ~ V_133 ;
F_5 ( V_44 , V_2 -> V_23 + V_26 ) ;
}
if ( F_6 ( V_2 -> V_23 + V_124 ) &
V_134 ) {
V_73 -> V_113 -> V_122 |= V_131 | V_130 ;
V_44 = F_6 ( V_2 -> V_23 + V_26 ) ;
V_44 |= V_24 ;
V_44 &= ~ ( V_107 | V_108 ) ;
F_5 ( V_44 , V_2 -> V_23 + V_26 ) ;
while ( F_6 ( V_2 -> V_23 + V_26 ) &
V_71 ) {
V_45 = F_6 ( V_2 -> V_23 + V_72 ) & 0xFFFF ;
V_45 ^= 0x8000 ;
if ( ! F_30 ( V_73 -> V_113 , V_45 ) ) {
F_9 ( V_2 -> V_17 , L_26 ) ;
V_73 -> V_113 -> V_122 |= V_132 ;
break;
}
}
V_44 |= V_135 ;
F_5 ( V_44 , V_2 -> V_23 + V_26 ) ;
V_44 &= ~ V_135 ;
F_5 ( V_44 , V_2 -> V_23 + V_26 ) ;
}
if ( V_73 -> V_113 -> V_122 )
F_31 ( V_2 , V_73 ) ;
return V_123 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_33 * V_73 ,
struct V_35 * V_36 , unsigned int * V_37 )
{
const struct V_38 * V_39 = F_15 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_22 = F_16 ( V_36 -> V_40 ) ;
int V_41 = F_17 ( V_36 -> V_40 ) ;
int V_42 = F_18 ( V_36 -> V_40 ) ;
unsigned long V_44 ;
if ( V_36 -> V_46 == 0 ) {
return 0 ;
} else if ( V_36 -> V_46 > 1 ) {
F_9 ( V_2 -> V_17 , L_6 ,
V_36 -> V_46 ) ;
return - V_47 ;
}
if ( V_22 >= V_39 -> V_136 ) {
F_9 ( V_2 -> V_17 , L_27 , V_36 -> V_46 ) ;
return - V_47 ;
}
if ( V_41 != 0 ) {
F_9 ( V_2 -> V_17 , L_28 , V_36 -> V_46 ) ;
return - V_47 ;
}
if ( V_42 != V_52 && V_42 != V_53 ) {
F_9 ( V_2 -> V_17 , L_29 , V_36 -> V_46 ) ;
return - V_47 ;
}
V_44 = F_6 ( V_2 -> V_23 + F_13 ( V_22 ) ) ;
V_44 |= V_27 ;
F_5 ( V_44 , V_2 -> V_23 + F_13 ( V_22 ) ) ;
F_5 ( 0x0 , V_2 -> V_23 + F_13 ( V_22 ) ) ;
F_5 ( V_37 [ 0 ] , V_2 -> V_23 + F_12 ( V_22 ) ) ;
V_6 -> V_137 [ V_22 ] = V_37 [ 0 ] ;
return 1 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_33 * V_73 ,
struct V_35 * V_36 , unsigned int * V_37 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_22 = F_16 ( V_36 -> V_40 ) ;
if ( V_36 -> V_46 == 0 ) {
return 0 ;
} else if ( V_36 -> V_46 > 1 ) {
F_9 ( V_2 -> V_17 , L_30 ) ;
return - V_47 ;
}
V_37 [ 0 ] = V_6 -> V_137 [ V_22 ] ;
return 1 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_33 * V_73 ,
struct V_35 * V_36 , unsigned int * V_37 )
{
if ( V_37 [ 0 ] ) {
if ( ( V_73 -> V_138 & V_37 [ 0 ] ) != V_37 [ 0 ] )
return - V_18 ;
V_73 -> V_139 &= ~ V_37 [ 0 ] ;
V_73 -> V_139 |= V_37 [ 0 ] & V_37 [ 1 ] ;
F_5 ( ( V_73 -> V_139 >> 0 ) & 0xFF ,
V_2 -> V_23 + V_140 ) ;
F_5 ( ( V_73 -> V_139 >> 8 ) & 0xFF ,
V_2 -> V_23 + V_141 ) ;
F_5 ( ( V_73 -> V_139 >> 16 ) & 0xFF ,
V_2 -> V_23 + V_142 ) ;
F_5 ( ( V_73 -> V_139 >> 24 ) & 0xFF ,
V_2 -> V_23 + V_143 ) ;
}
V_37 [ 1 ] = ( ( F_6 ( V_2 -> V_23 + V_140 ) & 0xFF ) << 0 ) |
( ( F_6 ( V_2 -> V_23 + V_141 ) & 0xFF ) << 8 ) |
( ( F_6 ( V_2 -> V_23 + V_142 ) & 0xFF ) << 16 ) |
( ( F_6 ( V_2 -> V_23 + V_143 ) & 0xFF ) << 24 ) ;
return V_36 -> V_46 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_33 * V_73 ,
struct V_35 * V_36 , unsigned int * V_37 )
{
unsigned long V_44 ;
int V_22 = F_16 ( V_36 -> V_40 ) ;
switch ( V_37 [ 0 ] ) {
default:
return - V_47 ;
case V_144 :
V_37 [ 1 ] =
( V_73 -> V_138 & ( 1 << V_22 ) ) ? V_145 : V_146 ;
return V_36 -> V_46 ;
case V_147 :
case V_148 :
break;
}
V_44 = F_6 ( V_2 -> V_23 + V_32 ) ;
if ( V_37 [ 0 ] == V_148 ) {
if ( V_22 < 8 ) {
V_73 -> V_138 |= 0xFF ;
V_44 &= ~ ( V_149 |
V_150 ) ;
V_44 |= V_149 ;
} else if ( V_22 < 16 ) {
if ( ! F_6 ( V_2 -> V_23 + V_31 ) )
return - V_13 ;
V_73 -> V_138 |= 0xFF00 ;
V_44 &= ~ ( V_151 |
V_152 ) ;
V_44 |= V_151 ;
} else if ( V_22 < 24 ) {
V_73 -> V_138 |= 0xFF0000 ;
V_44 &= ~ ( V_153 |
V_154 ) ;
V_44 |= V_153 ;
} else if ( V_22 < 32 ) {
V_73 -> V_138 |= 0xFF000000 ;
V_44 &= ~ ( V_155 |
V_156 ) ;
V_44 |= V_155 ;
} else {
return - V_47 ;
}
} else {
if ( V_22 < 8 ) {
if ( ! F_6 ( V_2 -> V_23 + V_31 ) )
return - V_13 ;
V_73 -> V_138 &= ~ 0xFF ;
V_44 &= ~ ( V_149 |
V_150 ) ;
} else if ( V_22 < 16 ) {
V_73 -> V_138 &= ~ 0xFF00 ;
V_44 &= ~ ( V_151 |
V_152 ) ;
} else if ( V_22 < 24 ) {
V_73 -> V_138 &= ~ 0xFF0000 ;
V_44 &= ~ ( V_153 |
V_154 ) ;
} else if ( V_22 < 32 ) {
V_73 -> V_138 &= ~ 0xFF000000 ;
V_44 &= ~ ( V_155 |
V_156 ) ;
} else {
return - V_47 ;
}
}
F_5 ( V_44 , V_2 -> V_23 + V_32 ) ;
return 1 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_33 * V_73 ,
struct V_35 * V_36 ,
unsigned int * V_37 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_112 ;
switch ( V_37 [ 0 ] ) {
case V_157 :
if ( V_36 -> V_46 != 1 )
return - V_47 ;
V_112 = F_37 ( V_6 -> V_158 , 0 , V_36 -> V_40 , 0 ,
V_159 | V_160 ) ;
if ( V_112 )
return V_112 ;
break;
case V_161 :
if ( V_36 -> V_46 != 2 )
return - V_47 ;
V_112 = F_38 ( V_6 -> V_158 , 0 , V_36 -> V_40 ,
( V_37 [ 1 ] << 1 ) | V_160 ) ;
if ( V_112 )
return V_112 ;
break;
default:
return - V_47 ;
}
return V_36 -> V_46 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_33 * V_73 ,
struct V_35 * V_36 , unsigned int * V_37 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_36 -> V_46 == 0 )
return 0 ;
if ( V_36 -> V_46 > 1 ) {
F_9 ( V_2 -> V_17 , L_6 ,
V_36 -> V_46 ) ;
return - V_47 ;
}
V_37 [ 0 ] = F_40 ( V_6 -> V_158 , 0 , V_36 -> V_40 ) ;
return 1 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_33 * V_73 ,
struct V_35 * V_36 , unsigned int * V_37 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_36 -> V_46 == 0 ) {
return 0 ;
} else if ( V_36 -> V_46 > 1 ) {
F_9 ( V_2 -> V_17 , L_6 ,
V_36 -> V_46 ) ;
return - V_47 ;
}
F_42 ( V_6 -> V_158 , 0 , V_36 -> V_40 , V_37 [ 0 ] ) ;
return 1 ;
}
static const void * F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_38 * V_39 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < F_44 ( V_162 ) ; V_76 ++ ) {
V_39 = & V_162 [ V_76 ] ;
if ( V_39 -> V_163 == V_4 -> V_164 )
return V_39 ;
}
return NULL ;
}
static int F_45 ( struct V_1 * V_2 ,
unsigned long V_165 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_38 * V_39 ;
struct V_5 * V_6 ;
struct V_33 * V_73 ;
int V_166 ;
V_39 = F_43 ( V_2 , V_4 ) ;
if ( ! V_39 )
return - V_13 ;
V_2 -> V_167 = V_39 ;
V_2 -> V_168 = V_39 -> V_169 ;
V_6 = F_46 ( sizeof( * V_6 ) , V_170 ) ;
if ( ! V_6 )
return - V_171 ;
V_2 -> V_7 = V_6 ;
V_166 = F_47 ( V_4 , V_2 -> V_168 ) ;
if ( V_166 )
return V_166 ;
V_6 -> V_14 = F_3 ( V_4 , 1 ) ;
V_2 -> V_23 = F_3 ( V_4 , 2 ) ;
V_6 -> V_158 = F_3 ( V_4 , 3 ) ;
if ( ! V_6 -> V_14 || ! V_2 -> V_23 || ! V_6 -> V_158 )
return - V_13 ;
V_166 = F_1 ( V_2 ) ;
if ( V_166 )
return V_166 ;
F_11 ( V_2 ) ;
V_166 = F_48 ( V_2 , 4 ) ;
if ( V_166 )
return V_166 ;
V_73 = & V_2 -> V_118 [ 0 ] ;
if ( V_39 -> V_54 ) {
V_73 -> type = V_172 ;
V_73 -> V_173 =
V_174 | V_175 | V_176 | V_81 ;
V_73 -> V_177 = V_39 -> V_54 ;
V_73 -> V_178 = 0xFFFF ;
V_73 -> V_179 = V_78 ;
V_73 -> V_180 = & V_181 ;
V_73 -> V_182 = F_14 ;
if ( V_4 -> V_116 > 0 ) {
if ( F_49 ( V_4 -> V_116 , F_29 ,
V_183 , V_2 -> V_168 , V_2 ) ) {
F_50 ( V_2 -> V_17 ,
L_31 ) ;
} else {
V_2 -> V_184 = V_73 ;
V_73 -> V_173 |= V_185 ;
V_73 -> V_186 = F_19 ;
V_73 -> V_187 = F_26 ;
V_73 -> V_188 = F_25 ;
V_2 -> V_116 = V_4 -> V_116 ;
}
} else {
F_50 ( V_2 -> V_17 , L_32 ) ;
}
} else {
V_73 -> type = V_189 ;
}
V_73 = & V_2 -> V_118 [ 1 ] ;
if ( V_39 -> V_136 ) {
V_73 -> type = V_190 ;
V_73 -> V_173 = V_191 | V_175 | V_176 ;
V_73 -> V_177 = V_39 -> V_136 ;
V_73 -> V_178 = 0xFFFF ;
V_73 -> V_180 = & V_192 ;
V_73 -> V_193 = F_32 ;
V_73 -> V_182 = F_33 ;
} else {
V_73 -> type = V_189 ;
}
V_73 = & V_2 -> V_118 [ 2 ] ;
if ( V_39 -> V_194 ) {
V_73 -> type = V_195 ;
V_73 -> V_173 = V_174 | V_196 ;
V_73 -> V_177 = V_39 -> V_194 ;
V_73 -> V_178 = 1 ;
V_73 -> V_180 = & V_197 ;
V_73 -> V_198 = F_34 ;
V_73 -> V_199 = F_35 ;
} else {
V_73 -> type = V_189 ;
}
if ( ! F_6 ( V_2 -> V_23 + V_31 ) ) {
V_73 -> V_138 |= 0xFF ;
F_5 ( V_149 ,
V_2 -> V_23 + V_31 ) ;
}
V_73 = & V_2 -> V_118 [ 3 ] ;
if ( V_39 -> V_200 ) {
V_73 -> type = V_201 ;
V_73 -> V_173 = V_174 | V_196 ;
V_73 -> V_177 = 3 ;
V_73 -> V_178 = 0xFFFF ;
V_73 -> V_182 = F_39 ;
V_73 -> V_193 = F_41 ;
V_73 -> V_199 = F_36 ;
} else {
V_73 -> type = V_189 ;
}
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_2 -> V_116 )
F_52 ( V_2 -> V_116 , V_2 ) ;
if ( V_4 ) {
if ( V_2 -> V_23 ) {
F_11 ( V_2 ) ;
F_53 ( V_4 ) ;
}
}
}
static int F_54 ( struct V_3 * V_2 ,
const struct V_202 * V_203 )
{
return F_55 ( V_2 , & V_204 ) ;
}
static void F_56 ( struct V_3 * V_2 )
{
F_57 ( V_2 ) ;
}
