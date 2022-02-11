static inline T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , unsigned V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( unsigned long V_6 , unsigned long V_7 )
{
T_2 V_8 = V_6 ;
int div ;
V_8 *= 16 ;
F_6 ( V_8 , V_7 ) ;
div = V_8 ;
if ( div < 0x10 )
div = 0x10 ;
#ifdef F_7
if ( div & 0x10 )
div &= ~ 0x7 ;
else {
if ( ( div & 0xC ) == 0xC ) {
div += 0x10 ;
div &= ~ 0xF ;
}
}
#endif
return div ;
}
static unsigned long F_8 ( struct V_9 * V_10 ,
unsigned long V_11 )
{
struct V_1 * V_2 = F_9 ( V_10 , struct V_1 , V_12 ) ;
unsigned long V_7 ;
T_1 div = F_1 ( V_2 , V_13 ) ;
if ( div < 0x10 )
div = 0x10 ;
V_7 = ( V_11 / div ) * 16 ;
return V_7 ;
}
static long F_10 ( struct V_9 * V_10 , unsigned long V_14 ,
unsigned long * V_15 )
{
struct V_1 * V_2 = F_9 ( V_10 , struct V_1 , V_12 ) ;
unsigned long V_7 ;
int div ;
T_1 V_16 ;
div = F_5 ( * V_15 , V_14 ) ;
V_7 = ( * V_15 / div ) * 16 ;
V_16 = F_1 ( V_2 , V_17 ) ;
if ( ! ( V_16 & V_18 ) && V_7 > * V_15 / 2 )
V_7 = * V_15 / 2 ;
F_11 ( V_2 -> V_19 -> V_20 ,
L_1 ,
V_21 , * V_15 , div , V_7 , V_14 ) ;
return V_7 ;
}
static int F_12 ( struct V_9 * V_10 , unsigned long V_14 ,
unsigned long V_11 )
{
struct V_1 * V_2 = F_9 ( V_10 , struct V_1 , V_12 ) ;
int div ;
T_1 V_22 ;
V_22 = F_1 ( V_2 , V_13 ) & ~ 0xfff ;
div = F_5 ( V_11 , V_14 ) ;
F_3 ( V_2 , V_22 | div , V_13 ) ;
F_11 ( V_2 -> V_19 -> V_20 , L_2 ,
V_21 , V_11 , V_14 , div ) ;
return 0 ;
}
static T_3 F_13 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_10 , struct V_1 , V_12 ) ;
T_1 V_16 ;
V_16 = F_1 ( V_2 , V_17 ) ;
return V_16 & V_18 ? 1 : 0 ;
}
static int F_14 ( struct V_9 * V_10 , T_3 V_23 )
{
struct V_1 * V_2 = F_9 ( V_10 , struct V_1 , V_12 ) ;
T_1 V_16 ;
V_16 = F_1 ( V_2 , V_17 ) ;
if ( V_23 )
V_16 |= V_18 ;
else
V_16 &= ~ V_18 ;
F_3 ( V_2 , V_16 , V_17 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 ,
int V_24 ,
int V_25 , int V_26 )
{
T_1 V_27 ;
V_27 = ( V_25 << V_28 ) |
( V_26 << V_29 ) ;
F_3 ( V_2 , V_27 , F_16 ( V_24 ) ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_24 , int V_30 ,
int V_31 , int V_32 , int V_33 )
{
T_1 V_27 ;
V_27 = F_1 ( V_2 , F_16 ( V_24 ) ) ;
V_27 &= ~ ( 0x3 << ( V_30 * 2 ) ) ;
V_27 |= V_31 << ( V_30 * 2 ) ;
F_3 ( V_2 , V_27 , F_16 ( V_24 ) ) ;
F_3 ( V_2 , ( V_33 << 16 ) | V_32 , F_18 ( V_24 , V_31 ) ) ;
}
static void F_19 ( struct V_1 * V_2 , struct V_34 * V_35 ,
int V_36 , int V_37 )
{
T_1 V_27 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ ) {
struct V_34 * V_39 = & V_35 [ V_38 ] ;
int V_24 = V_36 + V_38 + 1 ;
if ( ( V_39 -> V_40 >= 0x1000 ) || ( V_39 -> V_41 >= 0x1000 ) ||
( V_39 -> V_42 >= 0x1000 ) ||
( V_39 -> V_43 >= 0x400 ) ||
( V_39 -> V_44 >= 0x400 ) ) {
F_20 ( V_2 -> V_19 -> V_20 , L_3 ,
V_2 -> V_45 ) ;
return;
}
V_27 = F_21 ( V_39 -> V_40 ) |
F_22 ( V_39 -> V_46 ) |
F_23 ( V_39 -> V_41 ) |
F_24 ( V_39 -> V_47 ) ;
F_3 ( V_2 , V_27 , F_25 ( V_24 ) ) ;
V_27 = F_26 ( V_39 -> V_48 ) |
F_27 ( V_39 -> V_49 ) |
F_28 (
V_39 -> V_50 ) |
F_29 ( V_39 -> V_51 ) |
F_30 ( V_39 -> V_44 ) |
F_31 ( V_39 -> V_43 ) ;
if ( V_39 -> V_42 == 0 )
V_27 |= V_52 ;
F_3 ( V_2 , V_27 , F_32 ( V_24 ) ) ;
V_27 = F_1 ( V_2 , F_33 ( V_24 ) ) ;
V_27 &= ~ ( 0xffff << ( 16 * ( ( V_24 - 1 ) & 0x1 ) ) ) ;
V_27 |= V_39 -> V_42 << ( 16 * ( ( V_24 - 1 ) & 0x1 ) ) ;
F_3 ( V_2 , V_27 , F_33 ( V_24 ) ) ;
}
}
static void F_34 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
T_1 V_55 = V_54 -> V_56 + V_54 -> V_57 +
V_54 -> V_58 + V_54 -> V_59 ;
T_1 V_60 = V_54 -> V_61 + V_54 -> V_62 +
V_54 -> V_63 + V_54 -> V_64 ;
T_1 V_27 ;
struct V_34 V_65 [] = {
{
. V_40 = V_55 / 2 - 1 ,
. V_46 = V_66 ,
} , {
. V_40 = V_55 - 11 ,
. V_46 = V_66 ,
. V_44 = 4 ,
} , {
. V_40 = V_60 * 2 - 1 ,
. V_46 = V_67 ,
. V_41 = 1 ,
. V_47 = V_67 ,
. V_44 = 4 ,
} , {
. V_40 = V_60 / 2 - 1 ,
. V_46 = V_68 ,
. V_41 = V_54 -> V_63 ,
. V_47 = V_68 ,
. V_42 = 2 ,
. V_49 = V_69 ,
} , {
. V_46 = V_68 ,
. V_42 = V_54 -> V_61 / 2 ,
. V_49 = 4 ,
} , {
. V_40 = V_60 - 1 ,
. V_46 = V_68 ,
} , {
. V_40 = V_60 / 2 - 1 ,
. V_46 = V_68 ,
. V_41 = 9 ,
. V_47 = V_68 ,
. V_42 = 2 ,
. V_49 = V_69 ,
} , {
. V_46 = V_66 ,
. V_41 = V_54 -> V_58 ,
. V_47 = V_66 ,
. V_42 = V_54 -> V_56 ,
. V_49 = 5 ,
} , {
. V_40 = V_60 - 1 ,
. V_46 = V_67 ,
. V_41 = V_60 / 2 ,
. V_47 = V_67 ,
. V_49 = V_68 ,
. V_44 = 4 ,
}
} ;
F_19 ( V_2 , V_65 , 0 , F_35 ( V_65 ) ) ;
V_27 = F_1 ( V_2 , F_32 ( 9 ) ) ;
V_27 &= 0x1FFFFFFF ;
V_27 |= ( 3 - 1 ) << 29 | 0x00008000 ;
F_3 ( V_2 , V_27 , F_32 ( 9 ) ) ;
F_3 ( V_2 , V_60 / 2 - 1 , V_70 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_53 * V_54 , int div )
{
T_1 V_55 = V_54 -> V_56 + V_54 -> V_57 + V_54 -> V_58 +
V_54 -> V_59 ;
T_1 V_60 = V_54 -> V_61 + V_54 -> V_62 + V_54 -> V_63 +
V_54 -> V_64 ;
struct V_34 V_65 [] = {
{
. V_40 = V_55 - 1 ,
. V_46 = V_66 ,
} , {
. V_40 = V_55 - 1 ,
. V_46 = V_66 ,
. V_41 = div * V_54 -> V_71 ,
. V_47 = V_66 ,
. V_48 = 1 ,
. V_50 = V_66 ,
. V_44 = V_54 -> V_57 * 2 ,
} , {
. V_40 = V_60 - 1 ,
. V_46 = V_67 ,
. V_48 = 1 ,
. V_50 = V_67 ,
. V_44 = V_54 -> V_62 * 2 ,
} , {
. V_46 = V_68 ,
. V_41 = V_54 -> V_62 + V_54 -> V_63 ,
. V_47 = V_68 ,
. V_42 = V_54 -> V_61 ,
. V_49 = V_69 ,
} , {
. V_46 = V_66 ,
. V_41 = V_54 -> V_57 + V_54 -> V_58 ,
. V_47 = V_66 ,
. V_42 = V_54 -> V_56 ,
. V_49 = 5 ,
} , {
} , {
} , {
} , {
} ,
} ;
F_3 ( V_2 , V_60 - 1 , V_70 ) ;
F_19 ( V_2 , V_65 , 0 , F_35 ( V_65 ) ) ;
}
int F_37 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
T_1 V_27 ;
T_1 V_72 , V_73 ;
T_1 div ;
T_1 V_55 , V_60 ;
int V_74 ;
unsigned long V_75 ;
struct V_76 * V_77 ;
F_11 ( V_2 -> V_19 -> V_20 , L_4 ,
V_2 -> V_45 , V_54 -> V_56 , V_54 -> V_61 ) ;
if ( ( V_54 -> V_62 == 0 ) || ( V_54 -> V_57 == 0 ) )
return - V_78 ;
if ( V_54 -> V_79 & V_80 )
V_77 = V_2 -> V_81 ;
else
V_77 = V_2 -> V_82 ;
V_74 = F_38 ( V_2 -> V_83 , V_77 ) ;
if ( V_74 ) {
F_20 ( V_2 -> V_19 -> V_20 ,
L_5 ,
F_39 ( V_77 ) , V_74 ) ;
return V_74 ;
}
if ( V_54 -> V_79 & V_84 )
V_75 = F_40 ( V_77 ) ;
else
V_75 = F_41 ( V_2 -> V_83 , V_54 -> V_85 ) ;
V_74 = F_42 ( V_2 -> V_83 , V_75 ) ;
V_55 = V_54 -> V_56 + V_54 -> V_57 + V_54 -> V_58 +
V_54 -> V_59 ;
V_60 = V_54 -> V_61 + V_54 -> V_62 + V_54 -> V_63 +
V_54 -> V_64 ;
F_43 ( & V_86 ) ;
div = F_1 ( V_2 , V_13 ) & 0xfff ;
div = div / 16 ;
F_3 ( V_2 , ( div << 16 ) , V_87 ) ;
F_15 ( V_2 , V_88 , div - 1 , div - 1 ) ;
F_17 ( V_2 , V_88 , V_89 , 3 , 0 , div * 2 ) ;
V_72 = F_1 ( V_2 , V_17 ) & V_18 ;
V_72 |= V_90 ;
if ( V_54 -> V_91 ) {
F_34 ( V_2 , V_54 ) ;
V_72 |= 0x10000000 ;
V_72 |= V_92 ;
V_72 |= V_93 ;
V_73 = 7 ;
if ( V_54 -> V_94 )
V_72 |= V_95 ;
if ( V_54 -> V_96 )
V_72 |= V_97 ;
} else {
F_36 ( V_2 , V_54 , div ) ;
V_73 = 3 ;
if ( V_54 -> V_94 )
V_72 |= V_97 ;
if ( V_54 -> V_96 )
V_72 |= V_95 ;
}
if ( ! V_54 -> V_98 )
V_72 |= V_99 ;
F_3 ( V_2 , V_72 , V_17 ) ;
F_3 ( V_2 , ( -- V_73 << V_100 ) | 0x00000002 ,
V_101 ) ;
V_27 = F_1 ( V_2 , V_102 ) ;
V_27 &= ~ ( V_103 | V_104 ) ;
if ( V_54 -> V_105 )
V_27 |= V_104 ;
if ( V_54 -> V_106 )
V_27 |= V_103 ;
F_3 ( V_2 , V_27 , V_102 ) ;
F_44 ( & V_86 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 )
{
F_46 ( V_2 -> V_83 ) ;
F_47 ( V_2 -> V_19 , V_2 -> V_107 ) ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 )
{
F_49 ( V_2 -> V_19 , V_2 -> V_107 ) ;
F_50 ( V_2 -> V_83 ) ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 )
{
return V_2 -> V_45 ;
}
struct V_1 * F_52 ( struct V_108 * V_19 , int V_109 )
{
struct V_1 * V_2 ;
if ( V_109 > 1 )
return F_53 ( - V_78 ) ;
V_2 = V_19 -> V_110 [ V_109 ] ;
F_43 ( & V_111 ) ;
if ( V_2 -> V_112 ) {
V_2 = F_53 ( - V_113 ) ;
goto V_114;
}
V_2 -> V_112 = true ;
V_114:
F_44 ( & V_111 ) ;
return V_2 ;
}
void F_54 ( struct V_1 * V_2 )
{
F_43 ( & V_111 ) ;
V_2 -> V_112 = false ;
F_44 ( & V_111 ) ;
}
int F_55 ( struct V_108 * V_19 , struct V_115 * V_20 , int V_45 ,
unsigned long V_4 ,
T_1 V_107 , struct V_76 * V_82 )
{
struct V_1 * V_2 ;
int V_74 ;
const char * V_116 [ 2 ] ;
struct V_117 V_118 = {
. V_119 = & V_120 ,
. V_121 = 2 ,
. V_122 = 0 ,
} ;
if ( V_45 > 1 )
return - V_123 ;
V_2 = F_56 ( V_20 , sizeof( * V_2 ) , V_124 ) ;
if ( ! V_2 )
return - V_125 ;
V_19 -> V_110 [ V_45 ] = V_2 ;
V_2 -> V_81 = F_57 ( V_20 , V_45 ? L_6 : L_7 ) ;
if ( F_58 ( V_2 -> V_81 ) )
return F_59 ( V_2 -> V_81 ) ;
V_2 -> V_107 = V_107 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_82 = V_82 ;
V_2 -> V_4 = F_60 ( V_20 , V_4 , V_126 ) ;
if ( ! V_2 -> V_4 )
return - V_125 ;
V_116 [ 0 ] = F_39 ( V_2 -> V_82 ) ;
V_116 [ 1 ] = F_39 ( V_2 -> V_81 ) ;
F_3 ( V_2 , 0x10 , V_13 ) ;
V_118 . V_127 = ( const char * * ) & V_116 ;
V_2 -> V_128 = F_61 ( V_124 , L_8 ,
F_62 ( V_20 ) , V_45 ) ;
if ( ! V_2 -> V_128 )
return - V_125 ;
V_118 . V_129 = V_2 -> V_128 ;
V_2 -> V_12 . V_118 = & V_118 ;
V_2 -> V_83 = F_63 ( V_20 , & V_2 -> V_12 ) ;
if ( F_58 ( V_2 -> V_83 ) ) {
V_74 = F_59 ( V_2 -> V_83 ) ;
goto V_130;
}
F_11 ( V_20 , L_9 ,
V_45 , V_4 , V_2 -> V_4 ) ;
V_2 -> V_112 = false ;
V_2 -> V_19 = V_19 ;
return 0 ;
V_130:
F_64 ( V_2 -> V_128 ) ;
return V_74 ;
}
void F_65 ( struct V_108 * V_19 , int V_45 )
{
struct V_1 * V_2 = V_19 -> V_110 [ V_45 ] ;
F_66 ( V_2 -> V_83 ) ;
F_64 ( V_2 -> V_128 ) ;
}
