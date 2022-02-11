static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = F_4 ( V_6 ) ;
return V_7 -> V_8 -> V_9 ;
}
static const char * F_5 ( struct V_5 * V_6 ,
unsigned V_10 )
{
struct V_1 * V_7 = F_4 ( V_6 ) ;
return V_7 -> V_8 -> V_11 [ V_10 ] . V_12 ;
}
static int F_6 ( struct V_5 * V_6 ,
unsigned V_10 ,
const unsigned * * V_13 ,
unsigned * V_14 )
{
struct V_1 * V_7 = F_4 ( V_6 ) ;
* V_13 = V_7 -> V_8 -> V_11 [ V_10 ] . V_13 ;
* V_14 = V_7 -> V_8 -> V_11 [ V_10 ] . V_15 ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_1 * V_7 = F_4 ( V_6 ) ;
return V_7 -> V_8 -> V_16 ;
}
static const char * F_8 ( struct V_5 * V_6 ,
unsigned V_17 )
{
struct V_1 * V_7 = F_4 ( V_6 ) ;
return V_7 -> V_8 -> V_18 [ V_17 ] . V_12 ;
}
static int F_9 ( struct V_5 * V_6 ,
unsigned V_17 ,
const char * const * * V_11 ,
unsigned * const V_19 )
{
struct V_1 * V_7 = F_4 ( V_6 ) ;
* V_11 = V_7 -> V_8 -> V_18 [ V_17 ] . V_11 ;
* V_19 = V_7 -> V_8 -> V_18 [ V_17 ] . V_9 ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 ,
unsigned V_17 ,
unsigned V_10 )
{
struct V_1 * V_7 = F_4 ( V_6 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
int V_24 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_10 ] ;
for ( V_24 = 0 ; V_24 < V_21 -> V_25 ; V_24 ++ ) {
if ( V_21 -> V_26 [ V_24 ] == V_17 )
break;
}
if ( F_11 ( V_24 == V_21 -> V_25 ) )
return - V_27 ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_30 ) ;
V_23 &= ~ ( 0x7 << V_21 -> V_31 ) ;
V_23 |= V_24 << V_21 -> V_31 ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_30 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_7 ,
const struct V_20 * V_21 ,
unsigned V_32 ,
unsigned * V_33 ,
unsigned * V_34 )
{
switch ( V_32 ) {
case V_35 :
case V_36 :
case V_37 :
case V_38 :
* V_34 = V_21 -> V_39 ;
* V_33 = 3 ;
break;
case V_40 :
* V_34 = V_21 -> V_41 ;
* V_33 = 7 ;
break;
case V_42 :
case V_43 :
* V_34 = V_21 -> V_44 ;
* V_33 = 1 ;
break;
default:
return - V_45 ;
}
return 0 ;
}
static unsigned F_17 ( T_1 V_23 )
{
return ( V_23 + 1 ) * 2 ;
}
static int F_18 ( struct V_5 * V_6 ,
unsigned int V_10 ,
unsigned long * V_46 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_4 ( V_6 ) ;
unsigned V_32 = F_19 ( * V_46 ) ;
unsigned V_33 ;
unsigned V_47 ;
unsigned V_34 ;
int V_48 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_10 ] ;
V_48 = F_16 ( V_7 , V_21 , V_32 , & V_33 , & V_34 ) ;
if ( V_48 < 0 )
return V_48 ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_30 ) ;
V_47 = ( V_23 >> V_34 ) & V_33 ;
switch ( V_32 ) {
case V_35 :
V_47 = V_47 == V_49 ;
break;
case V_36 :
V_47 = V_47 == V_50 ;
break;
case V_37 :
V_47 = V_47 == V_51 ;
break;
case V_38 :
V_47 = V_47 == V_52 ;
break;
case V_40 :
V_47 = F_17 ( V_47 ) ;
break;
case V_42 :
if ( ! V_47 )
return - V_27 ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_53 ) ;
V_47 = ! ! ( V_23 & F_20 ( V_21 -> V_54 ) ) ;
break;
case V_43 :
if ( V_47 )
return - V_27 ;
V_47 = 1 ;
break;
default:
return - V_45 ;
}
* V_46 = F_21 ( V_32 , V_47 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 ,
unsigned V_10 ,
unsigned long * V_55 ,
unsigned V_56 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_4 ( V_6 ) ;
unsigned long V_22 ;
unsigned V_32 ;
unsigned V_33 ;
unsigned V_47 ;
unsigned V_34 ;
int V_48 ;
T_1 V_23 ;
int V_24 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_10 ] ;
for ( V_24 = 0 ; V_24 < V_56 ; V_24 ++ ) {
V_32 = F_19 ( V_55 [ V_24 ] ) ;
V_47 = F_23 ( V_55 [ V_24 ] ) ;
V_48 = F_16 ( V_7 , V_21 , V_32 , & V_33 , & V_34 ) ;
if ( V_48 < 0 )
return V_48 ;
switch ( V_32 ) {
case V_35 :
V_47 = V_49 ;
break;
case V_36 :
V_47 = V_50 ;
break;
case V_37 :
V_47 = V_51 ;
break;
case V_38 :
V_47 = V_52 ;
break;
case V_40 :
if ( V_47 > 16 || V_47 < 2 || ( V_47 % 2 ) != 0 )
V_47 = - 1 ;
else
V_47 = ( V_47 / 2 ) - 1 ;
break;
case V_42 :
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_53 ) ;
if ( V_47 )
V_23 |= F_20 ( V_21 -> V_57 ) ;
else
V_23 &= ~ F_20 ( V_21 -> V_57 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_53 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
V_47 = 1 ;
break;
case V_43 :
V_47 = 0 ;
break;
default:
F_24 ( V_7 -> V_58 , L_1 ,
V_32 ) ;
return - V_27 ;
}
if ( V_47 & ~ V_33 ) {
F_24 ( V_7 -> V_58 , L_2 , V_32 , V_47 ) ;
return - V_27 ;
}
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_30 ) ;
V_23 &= ~ ( V_33 << V_34 ) ;
V_23 |= V_47 << V_34 ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_30 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
}
return 0 ;
}
static int F_25 ( struct V_2 * V_4 , unsigned V_59 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_59 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_30 ) ;
V_23 &= ~ F_20 ( V_21 -> V_44 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_30 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_4 , unsigned V_59 , int V_60 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_59 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_53 ) ;
if ( V_60 )
V_23 |= F_20 ( V_21 -> V_57 ) ;
else
V_23 &= ~ F_20 ( V_21 -> V_57 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_53 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_30 ) ;
V_23 |= F_20 ( V_21 -> V_44 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_30 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_4 , unsigned V_59 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_59 ] ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_53 ) ;
return ! ! ( V_23 & F_20 ( V_21 -> V_54 ) ) ;
}
static void F_28 ( struct V_2 * V_4 , unsigned V_59 , int V_60 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_59 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_53 ) ;
if ( V_60 )
V_23 |= F_20 ( V_21 -> V_57 ) ;
else
V_23 &= ~ F_20 ( V_21 -> V_57 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_53 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
}
static void F_29 ( struct V_61 * V_62 ,
struct V_5 * V_6 ,
struct V_2 * V_4 ,
unsigned V_59 ,
unsigned V_63 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
unsigned V_64 ;
int V_65 ;
int V_66 ;
int V_67 ;
T_1 V_30 ;
static const char * const V_68 [] = {
L_3 ,
L_4 ,
L_5 ,
L_6
} ;
V_21 = & V_7 -> V_8 -> V_11 [ V_59 ] ;
V_30 = F_13 ( V_7 -> V_29 + V_21 -> V_30 ) ;
V_65 = ! ! ( V_30 & F_20 ( V_21 -> V_44 ) ) ;
V_64 = ( V_30 >> V_21 -> V_31 ) & 7 ;
V_66 = ( V_30 >> V_21 -> V_41 ) & 7 ;
V_67 = ( V_30 >> V_21 -> V_39 ) & 3 ;
F_30 ( V_62 , L_7 , V_21 -> V_12 , V_65 ? L_8 : L_9 , V_64 ) ;
F_30 ( V_62 , L_10 , F_17 ( V_66 ) ) ;
F_30 ( V_62 , L_11 , V_68 [ V_67 ] ) ;
}
static void F_31 ( struct V_61 * V_62 , struct V_2 * V_4 )
{
unsigned V_63 = V_4 -> V_69 ;
unsigned V_24 ;
for ( V_24 = 0 ; V_24 < V_4 -> V_70 ; V_24 ++ , V_63 ++ ) {
F_29 ( V_62 , NULL , V_4 , V_24 , V_63 ) ;
F_32 ( V_62 , L_12 ) ;
}
}
static void F_33 ( struct V_1 * V_7 ,
const struct V_20 * V_21 ,
struct V_71 * V_72 )
{
int V_73 = 100 ;
unsigned V_23 , V_74 , V_75 ;
unsigned V_76 ;
do {
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_53 ) & F_20 ( V_21 -> V_54 ) ;
V_76 = F_13 ( V_7 -> V_29 + V_21 -> V_77 ) ;
V_76 ^= F_20 ( V_21 -> V_78 ) ;
F_14 ( V_76 , V_7 -> V_29 + V_21 -> V_77 ) ;
V_74 = F_13 ( V_7 -> V_29 + V_21 -> V_53 ) & F_20 ( V_21 -> V_54 ) ;
V_75 = F_13 ( V_7 -> V_29 + V_21 -> V_79 ) ;
if ( V_75 || ( V_23 == V_74 ) )
return;
} while ( V_73 -- > 0 );
F_24 ( V_7 -> V_58 , L_13 ,
V_23 , V_74 ) ;
}
static void F_34 ( struct V_71 * V_72 )
{
struct V_2 * V_3 = F_35 ( V_72 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_72 -> V_80 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_77 ) ;
V_23 &= ~ F_20 ( V_21 -> V_81 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_77 ) ;
F_36 ( V_72 -> V_80 , V_7 -> V_82 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
}
static void F_37 ( struct V_71 * V_72 )
{
struct V_2 * V_3 = F_35 ( V_72 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_72 -> V_80 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_79 ) ;
V_23 &= ~ F_20 ( V_21 -> V_83 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_79 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_77 ) ;
V_23 |= F_20 ( V_21 -> V_81 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_77 ) ;
F_38 ( V_72 -> V_80 , V_7 -> V_82 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
}
static void F_39 ( struct V_71 * V_72 )
{
struct V_2 * V_3 = F_35 ( V_72 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_72 -> V_80 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_79 ) ;
if ( V_21 -> V_84 )
V_23 |= F_20 ( V_21 -> V_83 ) ;
else
V_23 &= ~ F_20 ( V_21 -> V_83 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_79 ) ;
if ( F_40 ( V_72 -> V_80 , V_7 -> V_85 ) )
F_33 ( V_7 , V_21 , V_72 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
}
static int F_41 ( struct V_71 * V_72 , unsigned int type )
{
struct V_2 * V_3 = F_35 ( V_72 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_72 -> V_80 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
if ( V_21 -> V_86 == 1 && type == V_87 )
F_38 ( V_72 -> V_80 , V_7 -> V_85 ) ;
else
F_36 ( V_72 -> V_80 , V_7 -> V_85 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_88 ) ;
V_23 &= ~ ( 7 << V_21 -> V_89 ) ;
V_23 |= V_21 -> V_90 << V_21 -> V_89 ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_88 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_77 ) ;
V_23 |= F_20 ( V_21 -> V_91 ) ;
if ( V_21 -> V_86 == 2 ) {
V_23 &= ~ ( 3 << V_21 -> V_92 ) ;
V_23 &= ~ ( 1 << V_21 -> V_78 ) ;
switch ( type ) {
case V_93 :
V_23 |= 1 << V_21 -> V_92 ;
V_23 |= F_20 ( V_21 -> V_78 ) ;
break;
case V_94 :
V_23 |= 2 << V_21 -> V_92 ;
V_23 |= F_20 ( V_21 -> V_78 ) ;
break;
case V_87 :
V_23 |= 3 << V_21 -> V_92 ;
V_23 |= F_20 ( V_21 -> V_78 ) ;
break;
case V_95 :
break;
case V_96 :
V_23 |= F_20 ( V_21 -> V_78 ) ;
break;
}
} else if ( V_21 -> V_86 == 1 ) {
V_23 &= ~ ( 1 << V_21 -> V_92 ) ;
V_23 &= ~ ( 1 << V_21 -> V_78 ) ;
switch ( type ) {
case V_93 :
V_23 |= F_20 ( V_21 -> V_92 ) ;
V_23 |= F_20 ( V_21 -> V_78 ) ;
break;
case V_94 :
V_23 |= F_20 ( V_21 -> V_92 ) ;
break;
case V_87 :
V_23 |= F_20 ( V_21 -> V_92 ) ;
V_23 |= F_20 ( V_21 -> V_78 ) ;
break;
case V_95 :
break;
case V_96 :
V_23 |= F_20 ( V_21 -> V_78 ) ;
break;
}
} else {
F_42 () ;
}
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_77 ) ;
if ( F_40 ( V_72 -> V_80 , V_7 -> V_85 ) )
F_33 ( V_7 , V_21 , V_72 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
if ( type & ( V_95 | V_96 ) )
F_43 ( V_72 , V_97 ) ;
else if ( type & ( V_94 | V_93 ) )
F_43 ( V_72 , V_98 ) ;
return 0 ;
}
static int F_44 ( struct V_71 * V_72 , unsigned int V_99 )
{
struct V_2 * V_3 = F_35 ( V_72 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_22 ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
F_45 ( V_7 -> V_100 , V_99 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
return 0 ;
}
static void F_46 ( struct V_101 * V_102 )
{
struct V_2 * V_3 = F_47 ( V_102 ) ;
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_103 * V_4 = F_48 ( V_102 ) ;
int V_104 ;
int V_105 = 0 ;
T_1 V_23 ;
int V_24 ;
F_49 ( V_4 , V_102 ) ;
F_50 (i, pctrl->enabled_irqs, pctrl->chip.ngpio) {
V_21 = & V_7 -> V_8 -> V_11 [ V_24 ] ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_79 ) ;
if ( V_23 & F_20 ( V_21 -> V_83 ) ) {
V_104 = F_51 ( V_3 -> V_106 , V_24 ) ;
F_52 ( V_104 ) ;
V_105 ++ ;
}
}
if ( V_105 == 0 )
F_53 ( V_102 ) ;
F_54 ( V_4 , V_102 ) ;
}
static int F_55 ( struct V_1 * V_7 )
{
struct V_2 * V_4 ;
int V_48 ;
unsigned V_70 = V_7 -> V_8 -> V_107 ;
if ( F_11 ( V_70 > V_108 ) )
return - V_27 ;
V_4 = & V_7 -> V_4 ;
V_4 -> V_69 = 0 ;
V_4 -> V_70 = V_70 ;
V_4 -> V_109 = F_56 ( V_7 -> V_58 ) ;
V_4 -> V_58 = V_7 -> V_58 ;
V_4 -> V_110 = V_111 ;
V_4 -> V_112 = V_7 -> V_58 -> V_112 ;
V_48 = F_57 ( & V_7 -> V_4 ) ;
if ( V_48 ) {
F_24 ( V_7 -> V_58 , L_14 ) ;
return V_48 ;
}
V_48 = F_58 ( & V_7 -> V_4 , F_56 ( V_7 -> V_58 ) , 0 , 0 , V_4 -> V_70 ) ;
if ( V_48 ) {
F_24 ( V_7 -> V_58 , L_15 ) ;
F_59 ( & V_7 -> V_4 ) ;
return V_48 ;
}
V_48 = F_60 ( V_4 ,
& V_113 ,
0 ,
V_98 ,
V_114 ) ;
if ( V_48 ) {
F_24 ( V_7 -> V_58 , L_16 ) ;
F_59 ( & V_7 -> V_4 ) ;
return - V_115 ;
}
F_61 ( V_4 , & V_113 , V_7 -> V_100 ,
F_46 ) ;
return 0 ;
}
static int F_62 ( struct V_116 * V_117 , unsigned long V_118 ,
void * V_119 )
{
struct V_1 * V_7 = F_2 ( V_117 , struct V_1 , V_120 ) ;
F_14 ( 0 , V_7 -> V_29 + V_121 ) ;
F_63 ( 1000 ) ;
return V_122 ;
}
static void F_64 ( void )
{
F_62 ( & V_123 -> V_120 , 0 , NULL ) ;
}
static void F_65 ( struct V_1 * V_7 )
{
int V_24 ;
const struct V_124 * V_64 = V_7 -> V_8 -> V_18 ;
for ( V_24 = 0 ; V_24 < V_7 -> V_8 -> V_16 ; V_24 ++ )
if ( ! strcmp ( V_64 [ V_24 ] . V_12 , L_17 ) ) {
V_7 -> V_120 . V_125 = F_62 ;
V_7 -> V_120 . V_126 = 128 ;
if ( F_66 ( & V_7 -> V_120 ) )
F_24 ( V_7 -> V_58 ,
L_18 ) ;
V_123 = V_7 ;
V_127 = F_64 ;
break;
}
}
int F_67 ( struct V_128 * V_129 ,
const struct V_130 * V_131 )
{
struct V_1 * V_7 ;
struct V_132 * V_133 ;
int V_48 ;
V_7 = F_68 ( & V_129 -> V_58 , sizeof( * V_7 ) , V_134 ) ;
if ( ! V_7 ) {
F_24 ( & V_129 -> V_58 , L_19 ) ;
return - V_135 ;
}
V_7 -> V_58 = & V_129 -> V_58 ;
V_7 -> V_8 = V_131 ;
V_7 -> V_4 = V_136 ;
F_69 ( & V_7 -> V_28 ) ;
V_133 = F_70 ( V_129 , V_137 , 0 ) ;
V_7 -> V_29 = F_71 ( & V_129 -> V_58 , V_133 ) ;
if ( F_72 ( V_7 -> V_29 ) )
return F_73 ( V_7 -> V_29 ) ;
F_65 ( V_7 ) ;
V_7 -> V_100 = F_74 ( V_129 , 0 ) ;
if ( V_7 -> V_100 < 0 ) {
F_24 ( & V_129 -> V_58 , L_20 ) ;
return V_7 -> V_100 ;
}
V_138 . V_12 = F_56 ( & V_129 -> V_58 ) ;
V_138 . V_13 = V_7 -> V_8 -> V_13 ;
V_138 . V_15 = V_7 -> V_8 -> V_15 ;
V_7 -> V_7 = F_75 ( & V_138 , & V_129 -> V_58 , V_7 ) ;
if ( F_72 ( V_7 -> V_7 ) ) {
F_24 ( & V_129 -> V_58 , L_21 ) ;
return F_73 ( V_7 -> V_7 ) ;
}
V_48 = F_55 ( V_7 ) ;
if ( V_48 ) {
F_76 ( V_7 -> V_7 ) ;
return V_48 ;
}
F_77 ( V_129 , V_7 ) ;
F_78 ( & V_129 -> V_58 , L_22 ) ;
return 0 ;
}
int F_79 ( struct V_128 * V_129 )
{
struct V_1 * V_7 = F_80 ( V_129 ) ;
F_59 ( & V_7 -> V_4 ) ;
F_76 ( V_7 -> V_7 ) ;
F_81 ( & V_7 -> V_120 ) ;
return 0 ;
}
