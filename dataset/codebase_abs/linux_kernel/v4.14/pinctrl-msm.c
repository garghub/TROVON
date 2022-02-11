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
T_1 V_20 , V_21 ;
int V_22 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_7 ] ;
V_21 = F_9 ( V_18 -> V_23 + F_10 ( V_18 -> V_24 ) - 1 , V_18 -> V_23 ) ;
for ( V_22 = 0 ; V_22 < V_18 -> V_24 ; V_22 ++ ) {
if ( V_18 -> V_25 [ V_22 ] == V_14 )
break;
}
if ( F_11 ( V_22 == V_18 -> V_24 ) )
return - V_26 ;
F_12 ( & V_4 -> V_27 , V_19 ) ;
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_29 ) ;
V_20 &= ~ V_21 ;
V_20 |= V_22 << V_18 -> V_23 ;
F_14 ( V_20 , V_4 -> V_28 + V_18 -> V_29 ) ;
F_15 ( & V_4 -> V_27 , V_19 ) ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 ,
const struct V_17 * V_18 ,
unsigned V_30 ,
unsigned * V_21 ,
unsigned * V_31 )
{
switch ( V_30 ) {
case V_32 :
case V_33 :
case V_34 :
case V_35 :
* V_31 = V_18 -> V_36 ;
* V_21 = 3 ;
break;
case V_37 :
* V_31 = V_18 -> V_38 ;
* V_21 = 7 ;
break;
case V_39 :
case V_40 :
* V_31 = V_18 -> V_41 ;
* V_21 = 1 ;
break;
default:
return - V_42 ;
}
return 0 ;
}
static unsigned F_17 ( T_1 V_20 )
{
return ( V_20 + 1 ) * 2 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned int V_7 ,
unsigned long * V_43 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned V_30 = F_19 ( * V_43 ) ;
unsigned V_21 ;
unsigned V_44 ;
unsigned V_31 ;
int V_45 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_7 ] ;
V_45 = F_16 ( V_4 , V_18 , V_30 , & V_21 , & V_31 ) ;
if ( V_45 < 0 )
return V_45 ;
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_29 ) ;
V_44 = ( V_20 >> V_31 ) & V_21 ;
switch ( V_30 ) {
case V_32 :
V_44 = V_44 == V_46 ;
break;
case V_33 :
V_44 = V_44 == V_47 ;
break;
case V_34 :
if ( V_4 -> V_5 -> V_48 )
return - V_42 ;
V_44 = V_44 == V_49 ;
break;
case V_35 :
if ( V_4 -> V_5 -> V_48 )
V_44 = V_44 == V_50 ;
else
V_44 = V_44 == V_51 ;
break;
case V_37 :
V_44 = F_17 ( V_44 ) ;
break;
case V_39 :
if ( ! V_44 )
return - V_26 ;
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_52 ) ;
V_44 = ! ! ( V_20 & F_20 ( V_18 -> V_53 ) ) ;
break;
case V_40 :
if ( V_44 )
return - V_26 ;
V_44 = 1 ;
break;
default:
return - V_42 ;
}
* V_43 = F_21 ( V_30 , V_44 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned V_7 ,
unsigned long * V_54 ,
unsigned V_55 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_19 ;
unsigned V_30 ;
unsigned V_21 ;
unsigned V_44 ;
unsigned V_31 ;
int V_45 ;
T_1 V_20 ;
int V_22 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_7 ] ;
for ( V_22 = 0 ; V_22 < V_55 ; V_22 ++ ) {
V_30 = F_19 ( V_54 [ V_22 ] ) ;
V_44 = F_23 ( V_54 [ V_22 ] ) ;
V_45 = F_16 ( V_4 , V_18 , V_30 , & V_21 , & V_31 ) ;
if ( V_45 < 0 )
return V_45 ;
switch ( V_30 ) {
case V_32 :
V_44 = V_46 ;
break;
case V_33 :
V_44 = V_47 ;
break;
case V_34 :
if ( V_4 -> V_5 -> V_48 )
return - V_42 ;
V_44 = V_49 ;
break;
case V_35 :
if ( V_4 -> V_5 -> V_48 )
V_44 = V_50 ;
else
V_44 = V_51 ;
break;
case V_37 :
if ( V_44 > 16 || V_44 < 2 || ( V_44 % 2 ) != 0 )
V_44 = - 1 ;
else
V_44 = ( V_44 / 2 ) - 1 ;
break;
case V_39 :
F_12 ( & V_4 -> V_27 , V_19 ) ;
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_52 ) ;
if ( V_44 )
V_20 |= F_20 ( V_18 -> V_56 ) ;
else
V_20 &= ~ F_20 ( V_18 -> V_56 ) ;
F_14 ( V_20 , V_4 -> V_28 + V_18 -> V_52 ) ;
F_15 ( & V_4 -> V_27 , V_19 ) ;
V_44 = 1 ;
break;
case V_40 :
V_44 = 0 ;
break;
default:
F_24 ( V_4 -> V_57 , L_1 ,
V_30 ) ;
return - V_26 ;
}
if ( V_44 & ~ V_21 ) {
F_24 ( V_4 -> V_57 , L_2 , V_30 , V_44 ) ;
return - V_26 ;
}
F_12 ( & V_4 -> V_27 , V_19 ) ;
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_29 ) ;
V_20 &= ~ ( V_21 << V_31 ) ;
V_20 |= V_44 << V_31 ;
F_14 ( V_20 , V_4 -> V_28 + V_18 -> V_29 ) ;
F_15 ( & V_4 -> V_27 , V_19 ) ;
}
return 0 ;
}
static int F_25 ( struct V_58 * V_59 , unsigned V_60 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_26 ( V_59 ) ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_60 ] ;
F_12 ( & V_4 -> V_27 , V_19 ) ;
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_29 ) ;
V_20 &= ~ F_20 ( V_18 -> V_41 ) ;
F_14 ( V_20 , V_4 -> V_28 + V_18 -> V_29 ) ;
F_15 ( & V_4 -> V_27 , V_19 ) ;
return 0 ;
}
static int F_27 ( struct V_58 * V_59 , unsigned V_60 , int V_61 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_26 ( V_59 ) ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_60 ] ;
F_12 ( & V_4 -> V_27 , V_19 ) ;
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_52 ) ;
if ( V_61 )
V_20 |= F_20 ( V_18 -> V_56 ) ;
else
V_20 &= ~ F_20 ( V_18 -> V_56 ) ;
F_14 ( V_20 , V_4 -> V_28 + V_18 -> V_52 ) ;
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_29 ) ;
V_20 |= F_20 ( V_18 -> V_41 ) ;
F_14 ( V_20 , V_4 -> V_28 + V_18 -> V_29 ) ;
F_15 ( & V_4 -> V_27 , V_19 ) ;
return 0 ;
}
static int F_28 ( struct V_58 * V_59 , unsigned int V_60 )
{
struct V_3 * V_4 = F_26 ( V_59 ) ;
const struct V_17 * V_18 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_60 ] ;
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_29 ) ;
return V_20 & F_20 ( V_18 -> V_41 ) ? 0 : 1 ;
}
static int F_29 ( struct V_58 * V_59 , unsigned V_60 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_26 ( V_59 ) ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_60 ] ;
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_52 ) ;
return ! ! ( V_20 & F_20 ( V_18 -> V_53 ) ) ;
}
static void F_30 ( struct V_58 * V_59 , unsigned V_60 , int V_61 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_26 ( V_59 ) ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_60 ] ;
F_12 ( & V_4 -> V_27 , V_19 ) ;
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_52 ) ;
if ( V_61 )
V_20 |= F_20 ( V_18 -> V_56 ) ;
else
V_20 &= ~ F_20 ( V_18 -> V_56 ) ;
F_14 ( V_20 , V_4 -> V_28 + V_18 -> V_52 ) ;
F_15 ( & V_4 -> V_27 , V_19 ) ;
}
static void F_31 ( struct V_62 * V_63 ,
struct V_1 * V_2 ,
struct V_58 * V_59 ,
unsigned V_60 ,
unsigned V_64 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_26 ( V_59 ) ;
unsigned V_65 ;
int V_66 ;
int V_67 ;
int V_68 ;
T_1 V_29 ;
static const char * const V_69 [] = {
L_3 ,
L_4 ,
L_5 ,
L_6
} ;
V_18 = & V_4 -> V_5 -> V_8 [ V_60 ] ;
V_29 = F_13 ( V_4 -> V_28 + V_18 -> V_29 ) ;
V_66 = ! ! ( V_29 & F_20 ( V_18 -> V_41 ) ) ;
V_65 = ( V_29 >> V_18 -> V_23 ) & 7 ;
V_67 = ( V_29 >> V_18 -> V_38 ) & 7 ;
V_68 = ( V_29 >> V_18 -> V_36 ) & 3 ;
F_32 ( V_63 , L_7 , V_18 -> V_9 , V_66 ? L_8 : L_9 , V_65 ) ;
F_32 ( V_63 , L_10 , F_17 ( V_67 ) ) ;
F_32 ( V_63 , L_11 , V_69 [ V_68 ] ) ;
}
static void F_33 ( struct V_62 * V_63 , struct V_58 * V_59 )
{
unsigned V_64 = V_59 -> V_70 ;
unsigned V_22 ;
for ( V_22 = 0 ; V_22 < V_59 -> V_71 ; V_22 ++ , V_64 ++ ) {
F_31 ( V_63 , NULL , V_59 , V_22 , V_64 ) ;
F_34 ( V_63 , L_12 ) ;
}
}
static void F_35 ( struct V_3 * V_4 ,
const struct V_17 * V_18 ,
struct V_72 * V_73 )
{
int V_74 = 100 ;
unsigned V_20 , V_75 , V_76 ;
unsigned V_77 ;
do {
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_52 ) & F_20 ( V_18 -> V_53 ) ;
V_77 = F_13 ( V_4 -> V_28 + V_18 -> V_78 ) ;
V_77 ^= F_20 ( V_18 -> V_79 ) ;
F_14 ( V_77 , V_4 -> V_28 + V_18 -> V_78 ) ;
V_75 = F_13 ( V_4 -> V_28 + V_18 -> V_52 ) & F_20 ( V_18 -> V_53 ) ;
V_76 = F_13 ( V_4 -> V_28 + V_18 -> V_80 ) ;
if ( V_76 || ( V_20 == V_75 ) )
return;
} while ( V_74 -- > 0 );
F_24 ( V_4 -> V_57 , L_13 ,
V_20 , V_75 ) ;
}
static void F_36 ( struct V_72 * V_73 )
{
struct V_58 * V_81 = F_37 ( V_73 ) ;
struct V_3 * V_4 = F_26 ( V_81 ) ;
const struct V_17 * V_18 ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_73 -> V_82 ] ;
F_12 ( & V_4 -> V_27 , V_19 ) ;
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_78 ) ;
V_20 &= ~ F_20 ( V_18 -> V_83 ) ;
F_14 ( V_20 , V_4 -> V_28 + V_18 -> V_78 ) ;
F_38 ( V_73 -> V_82 , V_4 -> V_84 ) ;
F_15 ( & V_4 -> V_27 , V_19 ) ;
}
static void F_39 ( struct V_72 * V_73 )
{
struct V_58 * V_81 = F_37 ( V_73 ) ;
struct V_3 * V_4 = F_26 ( V_81 ) ;
const struct V_17 * V_18 ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_73 -> V_82 ] ;
F_12 ( & V_4 -> V_27 , V_19 ) ;
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_78 ) ;
V_20 |= F_20 ( V_18 -> V_83 ) ;
F_14 ( V_20 , V_4 -> V_28 + V_18 -> V_78 ) ;
F_40 ( V_73 -> V_82 , V_4 -> V_84 ) ;
F_15 ( & V_4 -> V_27 , V_19 ) ;
}
static void F_41 ( struct V_72 * V_73 )
{
struct V_58 * V_81 = F_37 ( V_73 ) ;
struct V_3 * V_4 = F_26 ( V_81 ) ;
const struct V_17 * V_18 ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_73 -> V_82 ] ;
F_12 ( & V_4 -> V_27 , V_19 ) ;
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_80 ) ;
if ( V_18 -> V_85 )
V_20 |= F_20 ( V_18 -> V_86 ) ;
else
V_20 &= ~ F_20 ( V_18 -> V_86 ) ;
F_14 ( V_20 , V_4 -> V_28 + V_18 -> V_80 ) ;
if ( F_42 ( V_73 -> V_82 , V_4 -> V_87 ) )
F_35 ( V_4 , V_18 , V_73 ) ;
F_15 ( & V_4 -> V_27 , V_19 ) ;
}
static int F_43 ( struct V_72 * V_73 , unsigned int type )
{
struct V_58 * V_81 = F_37 ( V_73 ) ;
struct V_3 * V_4 = F_26 ( V_81 ) ;
const struct V_17 * V_18 ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_73 -> V_82 ] ;
F_12 ( & V_4 -> V_27 , V_19 ) ;
if ( V_18 -> V_88 == 1 && type == V_89 )
F_40 ( V_73 -> V_82 , V_4 -> V_87 ) ;
else
F_38 ( V_73 -> V_82 , V_4 -> V_87 ) ;
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_90 ) ;
V_20 &= ~ ( 7 << V_18 -> V_91 ) ;
V_20 |= V_18 -> V_92 << V_18 -> V_91 ;
F_14 ( V_20 , V_4 -> V_28 + V_18 -> V_90 ) ;
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_78 ) ;
V_20 |= F_20 ( V_18 -> V_93 ) ;
if ( V_18 -> V_88 == 2 ) {
V_20 &= ~ ( 3 << V_18 -> V_94 ) ;
V_20 &= ~ ( 1 << V_18 -> V_79 ) ;
switch ( type ) {
case V_95 :
V_20 |= 1 << V_18 -> V_94 ;
V_20 |= F_20 ( V_18 -> V_79 ) ;
break;
case V_96 :
V_20 |= 2 << V_18 -> V_94 ;
V_20 |= F_20 ( V_18 -> V_79 ) ;
break;
case V_89 :
V_20 |= 3 << V_18 -> V_94 ;
V_20 |= F_20 ( V_18 -> V_79 ) ;
break;
case V_97 :
break;
case V_98 :
V_20 |= F_20 ( V_18 -> V_79 ) ;
break;
}
} else if ( V_18 -> V_88 == 1 ) {
V_20 &= ~ ( 1 << V_18 -> V_94 ) ;
V_20 &= ~ ( 1 << V_18 -> V_79 ) ;
switch ( type ) {
case V_95 :
V_20 |= F_20 ( V_18 -> V_94 ) ;
V_20 |= F_20 ( V_18 -> V_79 ) ;
break;
case V_96 :
V_20 |= F_20 ( V_18 -> V_94 ) ;
break;
case V_89 :
V_20 |= F_20 ( V_18 -> V_94 ) ;
V_20 |= F_20 ( V_18 -> V_79 ) ;
break;
case V_97 :
break;
case V_98 :
V_20 |= F_20 ( V_18 -> V_79 ) ;
break;
}
} else {
F_44 () ;
}
F_14 ( V_20 , V_4 -> V_28 + V_18 -> V_78 ) ;
if ( F_42 ( V_73 -> V_82 , V_4 -> V_87 ) )
F_35 ( V_4 , V_18 , V_73 ) ;
F_15 ( & V_4 -> V_27 , V_19 ) ;
if ( type & ( V_97 | V_98 ) )
F_45 ( V_73 , V_99 ) ;
else if ( type & ( V_96 | V_95 ) )
F_45 ( V_73 , V_100 ) ;
return 0 ;
}
static int F_46 ( struct V_72 * V_73 , unsigned int V_101 )
{
struct V_58 * V_81 = F_37 ( V_73 ) ;
struct V_3 * V_4 = F_26 ( V_81 ) ;
unsigned long V_19 ;
F_12 ( & V_4 -> V_27 , V_19 ) ;
F_47 ( V_4 -> V_102 , V_101 ) ;
F_15 ( & V_4 -> V_27 , V_19 ) ;
return 0 ;
}
static void F_48 ( struct V_103 * V_104 )
{
struct V_58 * V_81 = F_49 ( V_104 ) ;
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_26 ( V_81 ) ;
struct V_105 * V_59 = F_50 ( V_104 ) ;
int V_106 ;
int V_107 = 0 ;
T_1 V_20 ;
int V_22 ;
F_51 ( V_59 , V_104 ) ;
F_52 (i, pctrl->enabled_irqs, pctrl->chip.ngpio) {
V_18 = & V_4 -> V_5 -> V_8 [ V_22 ] ;
V_20 = F_13 ( V_4 -> V_28 + V_18 -> V_80 ) ;
if ( V_20 & F_20 ( V_18 -> V_86 ) ) {
V_106 = F_53 ( V_81 -> V_108 , V_22 ) ;
F_54 ( V_106 ) ;
V_107 ++ ;
}
}
if ( V_107 == 0 )
F_55 ( V_104 ) ;
F_56 ( V_59 , V_104 ) ;
}
static int F_57 ( struct V_3 * V_4 )
{
struct V_58 * V_59 ;
int V_45 ;
unsigned V_71 = V_4 -> V_5 -> V_109 ;
if ( F_11 ( V_71 > V_110 ) )
return - V_26 ;
V_59 = & V_4 -> V_59 ;
V_59 -> V_70 = 0 ;
V_59 -> V_71 = V_71 ;
V_59 -> V_111 = F_58 ( V_4 -> V_57 ) ;
V_59 -> V_112 = V_4 -> V_57 ;
V_59 -> V_113 = V_114 ;
V_59 -> V_115 = V_4 -> V_57 -> V_115 ;
V_45 = F_59 ( & V_4 -> V_59 , V_4 ) ;
if ( V_45 ) {
F_24 ( V_4 -> V_57 , L_14 ) ;
return V_45 ;
}
V_45 = F_60 ( & V_4 -> V_59 , F_58 ( V_4 -> V_57 ) , 0 , 0 , V_59 -> V_71 ) ;
if ( V_45 ) {
F_24 ( V_4 -> V_57 , L_15 ) ;
F_61 ( & V_4 -> V_59 ) ;
return V_45 ;
}
V_45 = F_62 ( V_59 ,
& V_116 ,
0 ,
V_100 ,
V_117 ) ;
if ( V_45 ) {
F_24 ( V_4 -> V_57 , L_16 ) ;
F_61 ( & V_4 -> V_59 ) ;
return - V_118 ;
}
F_63 ( V_59 , & V_116 , V_4 -> V_102 ,
F_48 ) ;
return 0 ;
}
static int F_64 ( struct V_119 * V_120 , unsigned long V_121 ,
void * V_122 )
{
struct V_3 * V_4 = F_65 ( V_120 , struct V_3 , V_123 ) ;
F_14 ( 0 , V_4 -> V_28 + V_124 ) ;
F_66 ( 1000 ) ;
return V_125 ;
}
static void F_67 ( void )
{
F_64 ( & V_126 -> V_123 , 0 , NULL ) ;
}
static void F_68 ( struct V_3 * V_4 )
{
int V_22 ;
const struct V_127 * V_65 = V_4 -> V_5 -> V_15 ;
for ( V_22 = 0 ; V_22 < V_4 -> V_5 -> V_13 ; V_22 ++ )
if ( ! strcmp ( V_65 [ V_22 ] . V_9 , L_17 ) ) {
V_4 -> V_123 . V_128 = F_64 ;
V_4 -> V_123 . V_129 = 128 ;
if ( F_69 ( & V_4 -> V_123 ) )
F_24 ( V_4 -> V_57 ,
L_18 ) ;
V_126 = V_4 ;
V_130 = F_67 ;
break;
}
}
int F_70 ( struct V_131 * V_132 ,
const struct V_133 * V_134 )
{
struct V_3 * V_4 ;
struct V_135 * V_136 ;
int V_45 ;
V_4 = F_71 ( & V_132 -> V_57 , sizeof( * V_4 ) , V_137 ) ;
if ( ! V_4 ) {
F_24 ( & V_132 -> V_57 , L_19 ) ;
return - V_138 ;
}
V_4 -> V_57 = & V_132 -> V_57 ;
V_4 -> V_5 = V_134 ;
V_4 -> V_59 = V_139 ;
F_72 ( & V_4 -> V_27 ) ;
V_136 = F_73 ( V_132 , V_140 , 0 ) ;
V_4 -> V_28 = F_74 ( & V_132 -> V_57 , V_136 ) ;
if ( F_75 ( V_4 -> V_28 ) )
return F_76 ( V_4 -> V_28 ) ;
F_68 ( V_4 ) ;
V_4 -> V_102 = F_77 ( V_132 , 0 ) ;
if ( V_4 -> V_102 < 0 ) {
F_24 ( & V_132 -> V_57 , L_20 ) ;
return V_4 -> V_102 ;
}
V_141 . V_9 = F_58 ( & V_132 -> V_57 ) ;
V_141 . V_10 = V_4 -> V_5 -> V_10 ;
V_141 . V_12 = V_4 -> V_5 -> V_12 ;
V_4 -> V_4 = F_78 ( & V_132 -> V_57 , & V_141 ,
V_4 ) ;
if ( F_75 ( V_4 -> V_4 ) ) {
F_24 ( & V_132 -> V_57 , L_21 ) ;
return F_76 ( V_4 -> V_4 ) ;
}
V_45 = F_57 ( V_4 ) ;
if ( V_45 )
return V_45 ;
F_79 ( V_132 , V_4 ) ;
F_80 ( & V_132 -> V_57 , L_22 ) ;
return 0 ;
}
int F_81 ( struct V_131 * V_132 )
{
struct V_3 * V_4 = F_82 ( V_132 ) ;
F_61 ( & V_4 -> V_59 ) ;
F_83 ( & V_4 -> V_123 ) ;
return 0 ;
}
