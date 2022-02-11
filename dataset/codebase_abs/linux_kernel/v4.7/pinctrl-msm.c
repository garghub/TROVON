static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_6 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_8 [ V_7 ] . V_9 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned V_7 ,
const unsigned * * V_10 ,
unsigned * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_10 = V_4 -> V_5 -> V_8 [ V_7 ] . V_10 ;
* V_11 = V_4 -> V_5 -> V_8 [ V_7 ] . V_12 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_13 ;
}
static const char * F_6 ( struct V_1 * V_2 ,
unsigned V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_15 [ V_14 ] . V_9 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_14 ,
const char * const * * V_8 ,
unsigned * const V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_8 = V_4 -> V_5 -> V_15 [ V_14 ] . V_8 ;
* V_16 = V_4 -> V_5 -> V_15 [ V_14 ] . V_6 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned V_14 ,
unsigned V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_17 * V_18 ;
unsigned long V_19 ;
T_1 V_20 ;
int V_21 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_7 ] ;
for ( V_21 = 0 ; V_21 < V_18 -> V_22 ; V_21 ++ ) {
if ( V_18 -> V_23 [ V_21 ] == V_14 )
break;
}
if ( F_9 ( V_21 == V_18 -> V_22 ) )
return - V_24 ;
F_10 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_27 ) ;
V_20 &= ~ ( 0x7 << V_18 -> V_28 ) ;
V_20 |= V_21 << V_18 -> V_28 ;
F_12 ( V_20 , V_4 -> V_26 + V_18 -> V_27 ) ;
F_13 ( & V_4 -> V_25 , V_19 ) ;
return 0 ;
}
static int F_14 ( struct V_3 * V_4 ,
const struct V_17 * V_18 ,
unsigned V_29 ,
unsigned * V_30 ,
unsigned * V_31 )
{
switch ( V_29 ) {
case V_32 :
case V_33 :
case V_34 :
case V_35 :
* V_31 = V_18 -> V_36 ;
* V_30 = 3 ;
break;
case V_37 :
* V_31 = V_18 -> V_38 ;
* V_30 = 7 ;
break;
case V_39 :
case V_40 :
* V_31 = V_18 -> V_41 ;
* V_30 = 1 ;
break;
default:
return - V_42 ;
}
return 0 ;
}
static unsigned F_15 ( T_1 V_20 )
{
return ( V_20 + 1 ) * 2 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned int V_7 ,
unsigned long * V_43 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned V_29 = F_17 ( * V_43 ) ;
unsigned V_30 ;
unsigned V_44 ;
unsigned V_31 ;
int V_45 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_7 ] ;
V_45 = F_14 ( V_4 , V_18 , V_29 , & V_30 , & V_31 ) ;
if ( V_45 < 0 )
return V_45 ;
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_27 ) ;
V_44 = ( V_20 >> V_31 ) & V_30 ;
switch ( V_29 ) {
case V_32 :
V_44 = V_44 == V_46 ;
break;
case V_33 :
V_44 = V_44 == V_47 ;
break;
case V_34 :
V_44 = V_44 == V_48 ;
break;
case V_35 :
V_44 = V_44 == V_49 ;
break;
case V_37 :
V_44 = F_15 ( V_44 ) ;
break;
case V_39 :
if ( ! V_44 )
return - V_24 ;
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_50 ) ;
V_44 = ! ! ( V_20 & F_18 ( V_18 -> V_51 ) ) ;
break;
case V_40 :
if ( V_44 )
return - V_24 ;
V_44 = 1 ;
break;
default:
return - V_42 ;
}
* V_43 = F_19 ( V_29 , V_44 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
unsigned V_7 ,
unsigned long * V_52 ,
unsigned V_53 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_19 ;
unsigned V_29 ;
unsigned V_30 ;
unsigned V_44 ;
unsigned V_31 ;
int V_45 ;
T_1 V_20 ;
int V_21 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_7 ] ;
for ( V_21 = 0 ; V_21 < V_53 ; V_21 ++ ) {
V_29 = F_17 ( V_52 [ V_21 ] ) ;
V_44 = F_21 ( V_52 [ V_21 ] ) ;
V_45 = F_14 ( V_4 , V_18 , V_29 , & V_30 , & V_31 ) ;
if ( V_45 < 0 )
return V_45 ;
switch ( V_29 ) {
case V_32 :
V_44 = V_46 ;
break;
case V_33 :
V_44 = V_47 ;
break;
case V_34 :
V_44 = V_48 ;
break;
case V_35 :
V_44 = V_49 ;
break;
case V_37 :
if ( V_44 > 16 || V_44 < 2 || ( V_44 % 2 ) != 0 )
V_44 = - 1 ;
else
V_44 = ( V_44 / 2 ) - 1 ;
break;
case V_39 :
F_10 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_50 ) ;
if ( V_44 )
V_20 |= F_18 ( V_18 -> V_54 ) ;
else
V_20 &= ~ F_18 ( V_18 -> V_54 ) ;
F_12 ( V_20 , V_4 -> V_26 + V_18 -> V_50 ) ;
F_13 ( & V_4 -> V_25 , V_19 ) ;
V_44 = 1 ;
break;
case V_40 :
V_44 = 0 ;
break;
default:
F_22 ( V_4 -> V_55 , L_1 ,
V_29 ) ;
return - V_24 ;
}
if ( V_44 & ~ V_30 ) {
F_22 ( V_4 -> V_55 , L_2 , V_29 , V_44 ) ;
return - V_24 ;
}
F_10 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_27 ) ;
V_20 &= ~ ( V_30 << V_31 ) ;
V_20 |= V_44 << V_31 ;
F_12 ( V_20 , V_4 -> V_26 + V_18 -> V_27 ) ;
F_13 ( & V_4 -> V_25 , V_19 ) ;
}
return 0 ;
}
static int F_23 ( struct V_56 * V_57 , unsigned V_58 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_24 ( V_57 ) ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_58 ] ;
F_10 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_27 ) ;
V_20 &= ~ F_18 ( V_18 -> V_41 ) ;
F_12 ( V_20 , V_4 -> V_26 + V_18 -> V_27 ) ;
F_13 ( & V_4 -> V_25 , V_19 ) ;
return 0 ;
}
static int F_25 ( struct V_56 * V_57 , unsigned V_58 , int V_59 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_24 ( V_57 ) ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_58 ] ;
F_10 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_50 ) ;
if ( V_59 )
V_20 |= F_18 ( V_18 -> V_54 ) ;
else
V_20 &= ~ F_18 ( V_18 -> V_54 ) ;
F_12 ( V_20 , V_4 -> V_26 + V_18 -> V_50 ) ;
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_27 ) ;
V_20 |= F_18 ( V_18 -> V_41 ) ;
F_12 ( V_20 , V_4 -> V_26 + V_18 -> V_27 ) ;
F_13 ( & V_4 -> V_25 , V_19 ) ;
return 0 ;
}
static int F_26 ( struct V_56 * V_57 , unsigned V_58 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_24 ( V_57 ) ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_58 ] ;
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_50 ) ;
return ! ! ( V_20 & F_18 ( V_18 -> V_51 ) ) ;
}
static void F_27 ( struct V_56 * V_57 , unsigned V_58 , int V_59 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_24 ( V_57 ) ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_58 ] ;
F_10 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_50 ) ;
if ( V_59 )
V_20 |= F_18 ( V_18 -> V_54 ) ;
else
V_20 &= ~ F_18 ( V_18 -> V_54 ) ;
F_12 ( V_20 , V_4 -> V_26 + V_18 -> V_50 ) ;
F_13 ( & V_4 -> V_25 , V_19 ) ;
}
static void F_28 ( struct V_60 * V_61 ,
struct V_1 * V_2 ,
struct V_56 * V_57 ,
unsigned V_58 ,
unsigned V_62 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_24 ( V_57 ) ;
unsigned V_63 ;
int V_64 ;
int V_65 ;
int V_66 ;
T_1 V_27 ;
static const char * const V_67 [] = {
L_3 ,
L_4 ,
L_5 ,
L_6
} ;
V_18 = & V_4 -> V_5 -> V_8 [ V_58 ] ;
V_27 = F_11 ( V_4 -> V_26 + V_18 -> V_27 ) ;
V_64 = ! ! ( V_27 & F_18 ( V_18 -> V_41 ) ) ;
V_63 = ( V_27 >> V_18 -> V_28 ) & 7 ;
V_65 = ( V_27 >> V_18 -> V_38 ) & 7 ;
V_66 = ( V_27 >> V_18 -> V_36 ) & 3 ;
F_29 ( V_61 , L_7 , V_18 -> V_9 , V_64 ? L_8 : L_9 , V_63 ) ;
F_29 ( V_61 , L_10 , F_15 ( V_65 ) ) ;
F_29 ( V_61 , L_11 , V_67 [ V_66 ] ) ;
}
static void F_30 ( struct V_60 * V_61 , struct V_56 * V_57 )
{
unsigned V_62 = V_57 -> V_68 ;
unsigned V_21 ;
for ( V_21 = 0 ; V_21 < V_57 -> V_69 ; V_21 ++ , V_62 ++ ) {
F_28 ( V_61 , NULL , V_57 , V_21 , V_62 ) ;
F_31 ( V_61 , L_12 ) ;
}
}
static void F_32 ( struct V_3 * V_4 ,
const struct V_17 * V_18 ,
struct V_70 * V_71 )
{
int V_72 = 100 ;
unsigned V_20 , V_73 , V_74 ;
unsigned V_75 ;
do {
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_50 ) & F_18 ( V_18 -> V_51 ) ;
V_75 = F_11 ( V_4 -> V_26 + V_18 -> V_76 ) ;
V_75 ^= F_18 ( V_18 -> V_77 ) ;
F_12 ( V_75 , V_4 -> V_26 + V_18 -> V_76 ) ;
V_73 = F_11 ( V_4 -> V_26 + V_18 -> V_50 ) & F_18 ( V_18 -> V_51 ) ;
V_74 = F_11 ( V_4 -> V_26 + V_18 -> V_78 ) ;
if ( V_74 || ( V_20 == V_73 ) )
return;
} while ( V_72 -- > 0 );
F_22 ( V_4 -> V_55 , L_13 ,
V_20 , V_73 ) ;
}
static void F_33 ( struct V_70 * V_71 )
{
struct V_56 * V_79 = F_34 ( V_71 ) ;
struct V_3 * V_4 = F_24 ( V_79 ) ;
const struct V_17 * V_18 ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_71 -> V_80 ] ;
F_10 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_76 ) ;
V_20 &= ~ F_18 ( V_18 -> V_81 ) ;
F_12 ( V_20 , V_4 -> V_26 + V_18 -> V_76 ) ;
F_35 ( V_71 -> V_80 , V_4 -> V_82 ) ;
F_13 ( & V_4 -> V_25 , V_19 ) ;
}
static void F_36 ( struct V_70 * V_71 )
{
struct V_56 * V_79 = F_34 ( V_71 ) ;
struct V_3 * V_4 = F_24 ( V_79 ) ;
const struct V_17 * V_18 ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_71 -> V_80 ] ;
F_10 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_78 ) ;
V_20 &= ~ F_18 ( V_18 -> V_83 ) ;
F_12 ( V_20 , V_4 -> V_26 + V_18 -> V_78 ) ;
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_76 ) ;
V_20 |= F_18 ( V_18 -> V_81 ) ;
F_12 ( V_20 , V_4 -> V_26 + V_18 -> V_76 ) ;
F_37 ( V_71 -> V_80 , V_4 -> V_82 ) ;
F_13 ( & V_4 -> V_25 , V_19 ) ;
}
static void F_38 ( struct V_70 * V_71 )
{
struct V_56 * V_79 = F_34 ( V_71 ) ;
struct V_3 * V_4 = F_24 ( V_79 ) ;
const struct V_17 * V_18 ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_71 -> V_80 ] ;
F_10 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_78 ) ;
if ( V_18 -> V_84 )
V_20 |= F_18 ( V_18 -> V_83 ) ;
else
V_20 &= ~ F_18 ( V_18 -> V_83 ) ;
F_12 ( V_20 , V_4 -> V_26 + V_18 -> V_78 ) ;
if ( F_39 ( V_71 -> V_80 , V_4 -> V_85 ) )
F_32 ( V_4 , V_18 , V_71 ) ;
F_13 ( & V_4 -> V_25 , V_19 ) ;
}
static int F_40 ( struct V_70 * V_71 , unsigned int type )
{
struct V_56 * V_79 = F_34 ( V_71 ) ;
struct V_3 * V_4 = F_24 ( V_79 ) ;
const struct V_17 * V_18 ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_71 -> V_80 ] ;
F_10 ( & V_4 -> V_25 , V_19 ) ;
if ( V_18 -> V_86 == 1 && type == V_87 )
F_37 ( V_71 -> V_80 , V_4 -> V_85 ) ;
else
F_35 ( V_71 -> V_80 , V_4 -> V_85 ) ;
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_88 ) ;
V_20 &= ~ ( 7 << V_18 -> V_89 ) ;
V_20 |= V_18 -> V_90 << V_18 -> V_89 ;
F_12 ( V_20 , V_4 -> V_26 + V_18 -> V_88 ) ;
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_76 ) ;
V_20 |= F_18 ( V_18 -> V_91 ) ;
if ( V_18 -> V_86 == 2 ) {
V_20 &= ~ ( 3 << V_18 -> V_92 ) ;
V_20 &= ~ ( 1 << V_18 -> V_77 ) ;
switch ( type ) {
case V_93 :
V_20 |= 1 << V_18 -> V_92 ;
V_20 |= F_18 ( V_18 -> V_77 ) ;
break;
case V_94 :
V_20 |= 2 << V_18 -> V_92 ;
V_20 |= F_18 ( V_18 -> V_77 ) ;
break;
case V_87 :
V_20 |= 3 << V_18 -> V_92 ;
V_20 |= F_18 ( V_18 -> V_77 ) ;
break;
case V_95 :
break;
case V_96 :
V_20 |= F_18 ( V_18 -> V_77 ) ;
break;
}
} else if ( V_18 -> V_86 == 1 ) {
V_20 &= ~ ( 1 << V_18 -> V_92 ) ;
V_20 &= ~ ( 1 << V_18 -> V_77 ) ;
switch ( type ) {
case V_93 :
V_20 |= F_18 ( V_18 -> V_92 ) ;
V_20 |= F_18 ( V_18 -> V_77 ) ;
break;
case V_94 :
V_20 |= F_18 ( V_18 -> V_92 ) ;
break;
case V_87 :
V_20 |= F_18 ( V_18 -> V_92 ) ;
V_20 |= F_18 ( V_18 -> V_77 ) ;
break;
case V_95 :
break;
case V_96 :
V_20 |= F_18 ( V_18 -> V_77 ) ;
break;
}
} else {
F_41 () ;
}
F_12 ( V_20 , V_4 -> V_26 + V_18 -> V_76 ) ;
if ( F_39 ( V_71 -> V_80 , V_4 -> V_85 ) )
F_32 ( V_4 , V_18 , V_71 ) ;
F_13 ( & V_4 -> V_25 , V_19 ) ;
if ( type & ( V_95 | V_96 ) )
F_42 ( V_71 , V_97 ) ;
else if ( type & ( V_94 | V_93 ) )
F_42 ( V_71 , V_98 ) ;
return 0 ;
}
static int F_43 ( struct V_70 * V_71 , unsigned int V_99 )
{
struct V_56 * V_79 = F_34 ( V_71 ) ;
struct V_3 * V_4 = F_24 ( V_79 ) ;
unsigned long V_19 ;
F_10 ( & V_4 -> V_25 , V_19 ) ;
F_44 ( V_4 -> V_100 , V_99 ) ;
F_13 ( & V_4 -> V_25 , V_19 ) ;
return 0 ;
}
static void F_45 ( struct V_101 * V_102 )
{
struct V_56 * V_79 = F_46 ( V_102 ) ;
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_24 ( V_79 ) ;
struct V_103 * V_57 = F_47 ( V_102 ) ;
int V_104 ;
int V_105 = 0 ;
T_1 V_20 ;
int V_21 ;
F_48 ( V_57 , V_102 ) ;
F_49 (i, pctrl->enabled_irqs, pctrl->chip.ngpio) {
V_18 = & V_4 -> V_5 -> V_8 [ V_21 ] ;
V_20 = F_11 ( V_4 -> V_26 + V_18 -> V_78 ) ;
if ( V_20 & F_18 ( V_18 -> V_83 ) ) {
V_104 = F_50 ( V_79 -> V_106 , V_21 ) ;
F_51 ( V_104 ) ;
V_105 ++ ;
}
}
if ( V_105 == 0 )
F_52 ( V_102 ) ;
F_53 ( V_57 , V_102 ) ;
}
static int F_54 ( struct V_3 * V_4 )
{
struct V_56 * V_57 ;
int V_45 ;
unsigned V_69 = V_4 -> V_5 -> V_107 ;
if ( F_9 ( V_69 > V_108 ) )
return - V_24 ;
V_57 = & V_4 -> V_57 ;
V_57 -> V_68 = 0 ;
V_57 -> V_69 = V_69 ;
V_57 -> V_109 = F_55 ( V_4 -> V_55 ) ;
V_57 -> V_110 = V_4 -> V_55 ;
V_57 -> V_111 = V_112 ;
V_57 -> V_113 = V_4 -> V_55 -> V_113 ;
V_45 = F_56 ( & V_4 -> V_57 , V_4 ) ;
if ( V_45 ) {
F_22 ( V_4 -> V_55 , L_14 ) ;
return V_45 ;
}
V_45 = F_57 ( & V_4 -> V_57 , F_55 ( V_4 -> V_55 ) , 0 , 0 , V_57 -> V_69 ) ;
if ( V_45 ) {
F_22 ( V_4 -> V_55 , L_15 ) ;
F_58 ( & V_4 -> V_57 ) ;
return V_45 ;
}
V_45 = F_59 ( V_57 ,
& V_114 ,
0 ,
V_98 ,
V_115 ) ;
if ( V_45 ) {
F_22 ( V_4 -> V_55 , L_16 ) ;
F_58 ( & V_4 -> V_57 ) ;
return - V_116 ;
}
F_60 ( V_57 , & V_114 , V_4 -> V_100 ,
F_45 ) ;
return 0 ;
}
static int F_61 ( struct V_117 * V_118 , unsigned long V_119 ,
void * V_120 )
{
struct V_3 * V_4 = F_62 ( V_118 , struct V_3 , V_121 ) ;
F_12 ( 0 , V_4 -> V_26 + V_122 ) ;
F_63 ( 1000 ) ;
return V_123 ;
}
static void F_64 ( void )
{
F_61 ( & V_124 -> V_121 , 0 , NULL ) ;
}
static void F_65 ( struct V_3 * V_4 )
{
int V_21 ;
const struct V_125 * V_63 = V_4 -> V_5 -> V_15 ;
for ( V_21 = 0 ; V_21 < V_4 -> V_5 -> V_13 ; V_21 ++ )
if ( ! strcmp ( V_63 [ V_21 ] . V_9 , L_17 ) ) {
V_4 -> V_121 . V_126 = F_61 ;
V_4 -> V_121 . V_127 = 128 ;
if ( F_66 ( & V_4 -> V_121 ) )
F_22 ( V_4 -> V_55 ,
L_18 ) ;
V_124 = V_4 ;
V_128 = F_64 ;
break;
}
}
int F_67 ( struct V_129 * V_130 ,
const struct V_131 * V_132 )
{
struct V_3 * V_4 ;
struct V_133 * V_134 ;
int V_45 ;
V_4 = F_68 ( & V_130 -> V_55 , sizeof( * V_4 ) , V_135 ) ;
if ( ! V_4 ) {
F_22 ( & V_130 -> V_55 , L_19 ) ;
return - V_136 ;
}
V_4 -> V_55 = & V_130 -> V_55 ;
V_4 -> V_5 = V_132 ;
V_4 -> V_57 = V_137 ;
F_69 ( & V_4 -> V_25 ) ;
V_134 = F_70 ( V_130 , V_138 , 0 ) ;
V_4 -> V_26 = F_71 ( & V_130 -> V_55 , V_134 ) ;
if ( F_72 ( V_4 -> V_26 ) )
return F_73 ( V_4 -> V_26 ) ;
F_65 ( V_4 ) ;
V_4 -> V_100 = F_74 ( V_130 , 0 ) ;
if ( V_4 -> V_100 < 0 ) {
F_22 ( & V_130 -> V_55 , L_20 ) ;
return V_4 -> V_100 ;
}
V_139 . V_9 = F_55 ( & V_130 -> V_55 ) ;
V_139 . V_10 = V_4 -> V_5 -> V_10 ;
V_139 . V_12 = V_4 -> V_5 -> V_12 ;
V_4 -> V_4 = F_75 ( & V_130 -> V_55 , & V_139 ,
V_4 ) ;
if ( F_72 ( V_4 -> V_4 ) ) {
F_22 ( & V_130 -> V_55 , L_21 ) ;
return F_73 ( V_4 -> V_4 ) ;
}
V_45 = F_54 ( V_4 ) ;
if ( V_45 )
return V_45 ;
F_76 ( V_130 , V_4 ) ;
F_77 ( & V_130 -> V_55 , L_22 ) ;
return 0 ;
}
int F_78 ( struct V_129 * V_130 )
{
struct V_3 * V_4 = F_79 ( V_130 ) ;
F_58 ( & V_4 -> V_57 ) ;
F_80 ( & V_4 -> V_121 ) ;
return 0 ;
}
