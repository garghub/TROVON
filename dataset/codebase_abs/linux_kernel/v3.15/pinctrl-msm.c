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
if ( F_9 ( V_18 -> V_22 < 0 ) )
return - V_23 ;
for ( V_21 = 0 ; V_21 < F_10 ( V_18 -> V_24 ) ; V_21 ++ ) {
if ( V_18 -> V_24 [ V_21 ] == V_14 )
break;
}
if ( F_9 ( V_21 == F_10 ( V_18 -> V_24 ) ) )
return - V_23 ;
F_11 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_27 ) ;
V_20 &= ~ ( 0x7 << V_18 -> V_22 ) ;
V_20 |= V_21 << V_18 -> V_22 ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_27 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 ,
unsigned V_14 ,
unsigned V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_17 * V_18 ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_7 ] ;
if ( F_9 ( V_18 -> V_22 < 0 ) )
return;
F_11 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_27 ) ;
V_20 &= ~ ( 0x7 << V_18 -> V_22 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_27 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
}
static int F_16 ( struct V_3 * V_4 ,
const struct V_17 * V_18 ,
unsigned V_28 ,
unsigned * V_29 ,
unsigned * V_30 )
{
switch ( V_28 ) {
case V_31 :
case V_32 :
case V_33 :
* V_30 = V_18 -> V_34 ;
* V_29 = 3 ;
break;
case V_35 :
* V_30 = V_18 -> V_36 ;
* V_29 = 7 ;
break;
case V_37 :
* V_30 = V_18 -> V_38 ;
* V_29 = 1 ;
break;
default:
F_17 ( V_4 -> V_39 , L_1 , V_28 ) ;
return - V_40 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned int V_41 ,
unsigned long * V_42 )
{
F_17 ( V_2 -> V_39 , L_2 ) ;
return - V_40 ;
}
static int F_19 ( struct V_1 * V_2 , unsigned int V_41 ,
unsigned long * V_43 , unsigned V_44 )
{
F_17 ( V_2 -> V_39 , L_2 ) ;
return - V_40 ;
}
static unsigned F_20 ( T_1 V_20 )
{
return ( V_20 + 1 ) * 2 ;
}
static int F_21 ( struct V_1 * V_2 ,
unsigned int V_7 ,
unsigned long * V_42 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned V_28 = F_22 ( * V_42 ) ;
unsigned V_29 ;
unsigned V_45 ;
unsigned V_30 ;
int V_46 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_7 ] ;
V_46 = F_16 ( V_4 , V_18 , V_28 , & V_29 , & V_30 ) ;
if ( V_46 < 0 )
return V_46 ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_27 ) ;
V_45 = ( V_20 >> V_30 ) & V_29 ;
switch ( V_28 ) {
case V_31 :
V_45 = V_45 == V_47 ;
break;
case V_32 :
V_45 = V_45 == V_48 ;
break;
case V_33 :
V_45 = V_45 == V_49 ;
break;
case V_35 :
V_45 = F_20 ( V_45 ) ;
break;
case V_37 :
if ( ! V_45 )
return - V_23 ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_50 ) ;
V_45 = ! ! ( V_20 & F_23 ( V_18 -> V_51 ) ) ;
break;
default:
F_17 ( V_4 -> V_39 , L_3 ,
V_28 ) ;
return - V_23 ;
}
* V_42 = F_24 ( V_28 , V_45 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
unsigned V_7 ,
unsigned long * V_43 ,
unsigned V_44 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_19 ;
unsigned V_28 ;
unsigned V_29 ;
unsigned V_45 ;
unsigned V_30 ;
int V_46 ;
T_1 V_20 ;
int V_21 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_7 ] ;
for ( V_21 = 0 ; V_21 < V_44 ; V_21 ++ ) {
V_28 = F_22 ( V_43 [ V_21 ] ) ;
V_45 = F_26 ( V_43 [ V_21 ] ) ;
V_46 = F_16 ( V_4 , V_18 , V_28 , & V_29 , & V_30 ) ;
if ( V_46 < 0 )
return V_46 ;
switch ( V_28 ) {
case V_31 :
V_45 = V_47 ;
break;
case V_32 :
V_45 = V_48 ;
break;
case V_33 :
V_45 = V_49 ;
break;
case V_35 :
if ( V_45 > 16 || V_45 < 2 || ( V_45 % 2 ) != 0 )
V_45 = - 1 ;
else
V_45 = ( V_45 / 2 ) - 1 ;
break;
case V_37 :
F_11 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_50 ) ;
if ( V_45 )
V_20 |= F_23 ( V_18 -> V_52 ) ;
else
V_20 &= ~ F_23 ( V_18 -> V_52 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_50 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
V_45 = 1 ;
break;
default:
F_17 ( V_4 -> V_39 , L_3 ,
V_28 ) ;
return - V_23 ;
}
if ( V_45 & ~ V_29 ) {
F_17 ( V_4 -> V_39 , L_4 , V_28 , V_45 ) ;
return - V_23 ;
}
F_11 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_27 ) ;
V_20 &= ~ ( V_29 << V_30 ) ;
V_20 |= V_45 << V_30 ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_27 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
}
return 0 ;
}
static int F_27 ( struct V_53 * V_54 , unsigned V_55 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_28 ( V_54 , struct V_3 , V_54 ) ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_55 ] ;
F_11 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_27 ) ;
V_20 &= ~ F_23 ( V_18 -> V_38 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_27 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
return 0 ;
}
static int F_29 ( struct V_53 * V_54 , unsigned V_55 , int V_56 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_28 ( V_54 , struct V_3 , V_54 ) ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_55 ] ;
F_11 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_50 ) ;
if ( V_56 )
V_20 |= F_23 ( V_18 -> V_52 ) ;
else
V_20 &= ~ F_23 ( V_18 -> V_52 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_50 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_27 ) ;
V_20 |= F_23 ( V_18 -> V_38 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_27 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
return 0 ;
}
static int F_30 ( struct V_53 * V_54 , unsigned V_55 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_28 ( V_54 , struct V_3 , V_54 ) ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_55 ] ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_50 ) ;
return ! ! ( V_20 & F_23 ( V_18 -> V_51 ) ) ;
}
static void F_31 ( struct V_53 * V_54 , unsigned V_55 , int V_56 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_28 ( V_54 , struct V_3 , V_54 ) ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_55 ] ;
F_11 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_50 ) ;
if ( V_56 )
V_20 |= F_23 ( V_18 -> V_52 ) ;
else
V_20 &= ~ F_23 ( V_18 -> V_52 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_50 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
}
static int F_32 ( struct V_53 * V_54 , unsigned V_55 )
{
struct V_3 * V_4 = F_28 ( V_54 , struct V_3 , V_54 ) ;
return F_33 ( V_4 -> V_57 , V_55 ) ;
}
static int F_34 ( struct V_53 * V_54 , unsigned V_55 )
{
int V_58 = V_54 -> V_59 + V_55 ;
return F_35 ( V_58 ) ;
}
static void F_36 ( struct V_53 * V_54 , unsigned V_55 )
{
int V_58 = V_54 -> V_59 + V_55 ;
return F_37 ( V_58 ) ;
}
static void F_38 ( struct V_60 * V_61 ,
struct V_1 * V_2 ,
struct V_53 * V_54 ,
unsigned V_55 ,
unsigned V_58 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_28 ( V_54 , struct V_3 , V_54 ) ;
unsigned V_62 ;
int V_63 ;
int V_64 ;
int V_65 ;
T_1 V_27 ;
static const char * const V_66 [] = {
L_5 ,
L_6 ,
L_7 ,
L_8
} ;
V_18 = & V_4 -> V_5 -> V_8 [ V_55 ] ;
V_27 = F_12 ( V_4 -> V_26 + V_18 -> V_27 ) ;
V_63 = ! ! ( V_27 & F_23 ( V_18 -> V_38 ) ) ;
V_62 = ( V_27 >> V_18 -> V_22 ) & 7 ;
V_64 = ( V_27 >> V_18 -> V_36 ) & 7 ;
V_65 = ( V_27 >> V_18 -> V_34 ) & 3 ;
F_39 ( V_61 , L_9 , V_18 -> V_9 , V_63 ? L_10 : L_11 , V_62 ) ;
F_39 ( V_61 , L_12 , F_20 ( V_64 ) ) ;
F_39 ( V_61 , L_13 , V_66 [ V_65 ] ) ;
}
static void F_40 ( struct V_60 * V_61 , struct V_53 * V_54 )
{
unsigned V_58 = V_54 -> V_59 ;
unsigned V_21 ;
for ( V_21 = 0 ; V_21 < V_54 -> V_67 ; V_21 ++ , V_58 ++ ) {
F_38 ( V_61 , NULL , V_54 , V_21 , V_58 ) ;
F_41 ( V_61 , L_14 ) ;
}
}
static void F_42 ( struct V_3 * V_4 ,
const struct V_17 * V_18 ,
struct V_68 * V_69 )
{
int V_70 = 100 ;
unsigned V_20 , V_71 , V_72 ;
unsigned V_73 ;
do {
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_50 ) & F_23 ( V_18 -> V_51 ) ;
V_73 = F_12 ( V_4 -> V_26 + V_18 -> V_74 ) ;
V_73 ^= F_23 ( V_18 -> V_75 ) ;
F_13 ( V_73 , V_4 -> V_26 + V_18 -> V_74 ) ;
V_71 = F_12 ( V_4 -> V_26 + V_18 -> V_50 ) & F_23 ( V_18 -> V_51 ) ;
V_72 = F_12 ( V_4 -> V_26 + V_18 -> V_76 ) ;
if ( V_72 || ( V_20 == V_71 ) )
return;
} while ( V_70 -- > 0 );
F_17 ( V_4 -> V_39 , L_15 ,
V_20 , V_71 ) ;
}
static void F_43 ( struct V_68 * V_69 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 ;
unsigned long V_19 ;
T_1 V_20 ;
V_4 = F_44 ( V_69 ) ;
V_18 = & V_4 -> V_5 -> V_8 [ V_69 -> V_77 ] ;
F_11 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_74 ) ;
V_20 &= ~ F_23 ( V_18 -> V_78 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_74 ) ;
F_45 ( V_69 -> V_77 , V_4 -> V_79 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
}
static void F_46 ( struct V_68 * V_69 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 ;
unsigned long V_19 ;
T_1 V_20 ;
V_4 = F_44 ( V_69 ) ;
V_18 = & V_4 -> V_5 -> V_8 [ V_69 -> V_77 ] ;
F_11 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_76 ) ;
V_20 &= ~ F_23 ( V_18 -> V_80 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_76 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_74 ) ;
V_20 |= F_23 ( V_18 -> V_78 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_74 ) ;
F_47 ( V_69 -> V_77 , V_4 -> V_79 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
}
static void F_48 ( struct V_68 * V_69 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 ;
unsigned long V_19 ;
T_1 V_20 ;
V_4 = F_44 ( V_69 ) ;
V_18 = & V_4 -> V_5 -> V_8 [ V_69 -> V_77 ] ;
F_11 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_76 ) ;
if ( V_18 -> V_81 )
V_20 |= F_23 ( V_18 -> V_80 ) ;
else
V_20 &= ~ F_23 ( V_18 -> V_80 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_76 ) ;
if ( F_49 ( V_69 -> V_77 , V_4 -> V_82 ) )
F_42 ( V_4 , V_18 , V_69 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
}
static int F_50 ( struct V_68 * V_69 , unsigned int type )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 ;
unsigned long V_19 ;
T_1 V_20 ;
V_4 = F_44 ( V_69 ) ;
V_18 = & V_4 -> V_5 -> V_8 [ V_69 -> V_77 ] ;
F_11 ( & V_4 -> V_25 , V_19 ) ;
if ( V_18 -> V_83 == 1 && type == V_84 )
F_47 ( V_69 -> V_77 , V_4 -> V_82 ) ;
else
F_45 ( V_69 -> V_77 , V_4 -> V_82 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_85 ) ;
V_20 &= ~ ( 7 << V_18 -> V_86 ) ;
V_20 |= V_87 << V_18 -> V_86 ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_85 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_74 ) ;
V_20 |= F_23 ( V_18 -> V_88 ) ;
if ( V_18 -> V_83 == 2 ) {
V_20 &= ~ ( 3 << V_18 -> V_89 ) ;
V_20 &= ~ ( 1 << V_18 -> V_75 ) ;
switch ( type ) {
case V_90 :
V_20 |= 1 << V_18 -> V_89 ;
V_20 |= F_23 ( V_18 -> V_75 ) ;
break;
case V_91 :
V_20 |= 2 << V_18 -> V_89 ;
V_20 |= F_23 ( V_18 -> V_75 ) ;
break;
case V_84 :
V_20 |= 3 << V_18 -> V_89 ;
V_20 |= F_23 ( V_18 -> V_75 ) ;
break;
case V_92 :
break;
case V_93 :
V_20 |= F_23 ( V_18 -> V_75 ) ;
break;
}
} else if ( V_18 -> V_83 == 1 ) {
V_20 &= ~ ( 1 << V_18 -> V_89 ) ;
V_20 &= ~ ( 1 << V_18 -> V_75 ) ;
switch ( type ) {
case V_90 :
V_20 |= F_23 ( V_18 -> V_89 ) ;
V_20 |= F_23 ( V_18 -> V_75 ) ;
break;
case V_91 :
V_20 |= F_23 ( V_18 -> V_89 ) ;
break;
case V_84 :
V_20 |= F_23 ( V_18 -> V_89 ) ;
V_20 |= F_23 ( V_18 -> V_75 ) ;
break;
case V_92 :
break;
case V_93 :
V_20 |= F_23 ( V_18 -> V_75 ) ;
break;
}
} else {
F_51 () ;
}
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_74 ) ;
if ( F_49 ( V_69 -> V_77 , V_4 -> V_82 ) )
F_42 ( V_4 , V_18 , V_69 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
if ( type & ( V_92 | V_93 ) )
F_52 ( V_69 -> V_94 , V_95 ) ;
else if ( type & ( V_91 | V_90 ) )
F_52 ( V_69 -> V_94 , V_96 ) ;
return 0 ;
}
static int F_53 ( struct V_68 * V_69 , unsigned int V_97 )
{
struct V_3 * V_4 ;
unsigned long V_19 ;
V_4 = F_44 ( V_69 ) ;
F_11 ( & V_4 -> V_25 , V_19 ) ;
F_54 ( V_4 -> V_94 , V_97 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
return 0 ;
}
static int F_55 ( struct V_68 * V_69 )
{
struct V_3 * V_4 = F_44 ( V_69 ) ;
if ( F_56 ( & V_4 -> V_54 , V_69 -> V_77 ) ) {
F_17 ( V_4 -> V_39 , L_16 ,
V_69 -> V_77 ) ;
return - V_23 ;
}
return 0 ;
}
static void F_57 ( struct V_68 * V_69 )
{
struct V_3 * V_4 = F_44 ( V_69 ) ;
F_58 ( & V_4 -> V_54 , V_69 -> V_77 ) ;
}
static void F_59 ( unsigned int V_94 , struct V_98 * V_99 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_60 ( V_99 ) ;
struct V_100 * V_54 = F_61 ( V_94 ) ;
int V_101 ;
int V_102 = 0 ;
T_1 V_20 ;
int V_21 ;
F_62 ( V_54 , V_99 ) ;
F_63 (i, pctrl->enabled_irqs, pctrl->chip.ngpio) {
V_18 = & V_4 -> V_5 -> V_8 [ V_21 ] ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_76 ) ;
if ( V_20 & F_23 ( V_18 -> V_80 ) ) {
V_101 = F_33 ( V_4 -> V_57 , V_21 ) ;
F_64 ( V_101 ) ;
V_102 ++ ;
}
}
if ( V_102 == 0 )
F_65 ( V_94 , V_99 ) ;
F_66 ( V_54 , V_99 ) ;
}
static int F_67 ( struct V_3 * V_4 )
{
struct V_53 * V_54 ;
int V_94 ;
int V_46 ;
int V_21 ;
int V_103 ;
unsigned V_67 = V_4 -> V_5 -> V_104 ;
if ( F_9 ( V_67 > V_105 ) )
return - V_23 ;
V_54 = & V_4 -> V_54 ;
V_54 -> V_59 = 0 ;
V_54 -> V_67 = V_67 ;
V_54 -> V_106 = F_68 ( V_4 -> V_39 ) ;
V_54 -> V_39 = V_4 -> V_39 ;
V_54 -> V_107 = V_108 ;
V_54 -> V_109 = V_4 -> V_39 -> V_109 ;
V_46 = F_69 ( & V_4 -> V_54 ) ;
if ( V_46 ) {
F_17 ( V_4 -> V_39 , L_17 ) ;
return V_46 ;
}
V_46 = F_70 ( & V_4 -> V_54 , F_68 ( V_4 -> V_39 ) , 0 , 0 , V_54 -> V_67 ) ;
if ( V_46 ) {
F_17 ( V_4 -> V_39 , L_18 ) ;
return V_46 ;
}
V_4 -> V_57 = F_71 ( V_4 -> V_39 -> V_109 , V_54 -> V_67 ,
& V_110 , NULL ) ;
if ( ! V_4 -> V_57 ) {
F_17 ( V_4 -> V_39 , L_19 ) ;
V_103 = F_72 ( & V_4 -> V_54 ) ;
return - V_111 ;
}
for ( V_21 = 0 ; V_21 < V_54 -> V_67 ; V_21 ++ ) {
V_94 = F_73 ( V_4 -> V_57 , V_21 ) ;
F_74 ( V_94 , & V_112 ) ;
F_75 ( V_94 , & V_113 , V_96 ) ;
F_76 ( V_94 , V_4 ) ;
}
F_77 ( V_4 -> V_94 , V_4 ) ;
F_78 ( V_4 -> V_94 , F_59 ) ;
return 0 ;
}
int F_79 ( struct V_114 * V_115 ,
const struct V_116 * V_117 )
{
struct V_3 * V_4 ;
struct V_118 * V_119 ;
int V_46 ;
V_4 = F_80 ( & V_115 -> V_39 , sizeof( * V_4 ) , V_120 ) ;
if ( ! V_4 ) {
F_17 ( & V_115 -> V_39 , L_20 ) ;
return - V_121 ;
}
V_4 -> V_39 = & V_115 -> V_39 ;
V_4 -> V_5 = V_117 ;
V_4 -> V_54 = V_122 ;
F_81 ( & V_4 -> V_25 ) ;
V_119 = F_82 ( V_115 , V_123 , 0 ) ;
V_4 -> V_26 = F_83 ( & V_115 -> V_39 , V_119 ) ;
if ( F_84 ( V_4 -> V_26 ) )
return F_85 ( V_4 -> V_26 ) ;
V_4 -> V_94 = F_86 ( V_115 , 0 ) ;
if ( V_4 -> V_94 < 0 ) {
F_17 ( & V_115 -> V_39 , L_21 ) ;
return V_4 -> V_94 ;
}
V_124 . V_9 = F_68 ( & V_115 -> V_39 ) ;
V_124 . V_10 = V_4 -> V_5 -> V_10 ;
V_124 . V_12 = V_4 -> V_5 -> V_12 ;
V_4 -> V_4 = F_87 ( & V_124 , & V_115 -> V_39 , V_4 ) ;
if ( ! V_4 -> V_4 ) {
F_17 ( & V_115 -> V_39 , L_22 ) ;
return - V_125 ;
}
V_46 = F_67 ( V_4 ) ;
if ( V_46 ) {
F_88 ( V_4 -> V_4 ) ;
return V_46 ;
}
F_89 ( V_115 , V_4 ) ;
F_90 ( & V_115 -> V_39 , L_23 ) ;
return 0 ;
}
int F_91 ( struct V_114 * V_115 )
{
struct V_3 * V_4 = F_92 ( V_115 ) ;
int V_46 ;
V_46 = F_72 ( & V_4 -> V_54 ) ;
if ( V_46 ) {
F_17 ( & V_115 -> V_39 , L_24 ) ;
return V_46 ;
}
F_78 ( V_4 -> V_94 , NULL ) ;
F_93 ( V_4 -> V_57 ) ;
F_88 ( V_4 -> V_4 ) ;
return 0 ;
}
