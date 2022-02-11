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
if ( F_11 ( V_21 -> V_25 < 0 ) )
return - V_26 ;
for ( V_24 = 0 ; V_24 < V_21 -> V_27 ; V_24 ++ ) {
if ( V_21 -> V_28 [ V_24 ] == V_17 )
break;
}
if ( F_11 ( V_24 == V_21 -> V_27 ) )
return - V_26 ;
F_12 ( & V_7 -> V_29 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_31 ) ;
V_23 &= ~ ( 0x7 << V_21 -> V_25 ) ;
V_23 |= V_24 << V_21 -> V_25 ;
F_14 ( V_23 , V_7 -> V_30 + V_21 -> V_31 ) ;
F_15 ( & V_7 -> V_29 , V_22 ) ;
return 0 ;
}
static void F_16 ( struct V_5 * V_6 ,
unsigned V_17 ,
unsigned V_10 )
{
struct V_1 * V_7 = F_4 ( V_6 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_10 ] ;
if ( F_11 ( V_21 -> V_25 < 0 ) )
return;
F_12 ( & V_7 -> V_29 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_31 ) ;
V_23 &= ~ ( 0x7 << V_21 -> V_25 ) ;
F_14 ( V_23 , V_7 -> V_30 + V_21 -> V_31 ) ;
F_15 ( & V_7 -> V_29 , V_22 ) ;
}
static int F_17 ( struct V_1 * V_7 ,
const struct V_20 * V_21 ,
unsigned V_32 ,
unsigned * V_33 ,
unsigned * V_34 )
{
switch ( V_32 ) {
case V_35 :
case V_36 :
case V_37 :
* V_34 = V_21 -> V_38 ;
* V_33 = 3 ;
break;
case V_39 :
* V_34 = V_21 -> V_40 ;
* V_33 = 7 ;
break;
case V_41 :
* V_34 = V_21 -> V_42 ;
* V_33 = 1 ;
break;
default:
F_18 ( V_7 -> V_43 , L_1 , V_32 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_19 ( struct V_5 * V_6 ,
unsigned int V_45 ,
unsigned long * V_46 )
{
F_18 ( V_6 -> V_43 , L_2 ) ;
return - V_44 ;
}
static int F_20 ( struct V_5 * V_6 , unsigned int V_45 ,
unsigned long * V_47 , unsigned V_48 )
{
F_18 ( V_6 -> V_43 , L_2 ) ;
return - V_44 ;
}
static unsigned F_21 ( T_1 V_23 )
{
return ( V_23 + 1 ) * 2 ;
}
static int F_22 ( struct V_5 * V_6 ,
unsigned int V_10 ,
unsigned long * V_46 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_4 ( V_6 ) ;
unsigned V_32 = F_23 ( * V_46 ) ;
unsigned V_33 ;
unsigned V_49 ;
unsigned V_34 ;
int V_50 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_10 ] ;
V_50 = F_17 ( V_7 , V_21 , V_32 , & V_33 , & V_34 ) ;
if ( V_50 < 0 )
return V_50 ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_31 ) ;
V_49 = ( V_23 >> V_34 ) & V_33 ;
switch ( V_32 ) {
case V_35 :
V_49 = V_49 == V_51 ;
break;
case V_36 :
V_49 = V_49 == V_52 ;
break;
case V_37 :
V_49 = V_49 == V_53 ;
break;
case V_39 :
V_49 = F_21 ( V_49 ) ;
break;
case V_41 :
if ( ! V_49 )
return - V_26 ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_54 ) ;
V_49 = ! ! ( V_23 & F_24 ( V_21 -> V_55 ) ) ;
break;
default:
F_18 ( V_7 -> V_43 , L_3 ,
V_32 ) ;
return - V_26 ;
}
* V_46 = F_25 ( V_32 , V_49 ) ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 ,
unsigned V_10 ,
unsigned long * V_47 ,
unsigned V_48 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_4 ( V_6 ) ;
unsigned long V_22 ;
unsigned V_32 ;
unsigned V_33 ;
unsigned V_49 ;
unsigned V_34 ;
int V_50 ;
T_1 V_23 ;
int V_24 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_10 ] ;
for ( V_24 = 0 ; V_24 < V_48 ; V_24 ++ ) {
V_32 = F_23 ( V_47 [ V_24 ] ) ;
V_49 = F_27 ( V_47 [ V_24 ] ) ;
V_50 = F_17 ( V_7 , V_21 , V_32 , & V_33 , & V_34 ) ;
if ( V_50 < 0 )
return V_50 ;
switch ( V_32 ) {
case V_35 :
V_49 = V_51 ;
break;
case V_36 :
V_49 = V_52 ;
break;
case V_37 :
V_49 = V_53 ;
break;
case V_39 :
if ( V_49 > 16 || V_49 < 2 || ( V_49 % 2 ) != 0 )
V_49 = - 1 ;
else
V_49 = ( V_49 / 2 ) - 1 ;
break;
case V_41 :
F_12 ( & V_7 -> V_29 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_54 ) ;
if ( V_49 )
V_23 |= F_24 ( V_21 -> V_56 ) ;
else
V_23 &= ~ F_24 ( V_21 -> V_56 ) ;
F_14 ( V_23 , V_7 -> V_30 + V_21 -> V_54 ) ;
F_15 ( & V_7 -> V_29 , V_22 ) ;
V_49 = 1 ;
break;
default:
F_18 ( V_7 -> V_43 , L_3 ,
V_32 ) ;
return - V_26 ;
}
if ( V_49 & ~ V_33 ) {
F_18 ( V_7 -> V_43 , L_4 , V_32 , V_49 ) ;
return - V_26 ;
}
F_12 ( & V_7 -> V_29 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_31 ) ;
V_23 &= ~ ( V_33 << V_34 ) ;
V_23 |= V_49 << V_34 ;
F_14 ( V_23 , V_7 -> V_30 + V_21 -> V_31 ) ;
F_15 ( & V_7 -> V_29 , V_22 ) ;
}
return 0 ;
}
static int F_28 ( struct V_2 * V_4 , unsigned V_57 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_57 ] ;
F_12 ( & V_7 -> V_29 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_31 ) ;
V_23 &= ~ F_24 ( V_21 -> V_42 ) ;
F_14 ( V_23 , V_7 -> V_30 + V_21 -> V_31 ) ;
F_15 ( & V_7 -> V_29 , V_22 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_4 , unsigned V_57 , int V_58 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_57 ] ;
F_12 ( & V_7 -> V_29 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_54 ) ;
if ( V_58 )
V_23 |= F_24 ( V_21 -> V_56 ) ;
else
V_23 &= ~ F_24 ( V_21 -> V_56 ) ;
F_14 ( V_23 , V_7 -> V_30 + V_21 -> V_54 ) ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_31 ) ;
V_23 |= F_24 ( V_21 -> V_42 ) ;
F_14 ( V_23 , V_7 -> V_30 + V_21 -> V_31 ) ;
F_15 ( & V_7 -> V_29 , V_22 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_4 , unsigned V_57 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_57 ] ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_54 ) ;
return ! ! ( V_23 & F_24 ( V_21 -> V_55 ) ) ;
}
static void F_31 ( struct V_2 * V_4 , unsigned V_57 , int V_58 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_57 ] ;
F_12 ( & V_7 -> V_29 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_54 ) ;
if ( V_58 )
V_23 |= F_24 ( V_21 -> V_56 ) ;
else
V_23 &= ~ F_24 ( V_21 -> V_56 ) ;
F_14 ( V_23 , V_7 -> V_30 + V_21 -> V_54 ) ;
F_15 ( & V_7 -> V_29 , V_22 ) ;
}
static int F_32 ( struct V_2 * V_4 , unsigned V_57 )
{
int V_59 = V_4 -> V_60 + V_57 ;
return F_33 ( V_59 ) ;
}
static void F_34 ( struct V_2 * V_4 , unsigned V_57 )
{
int V_59 = V_4 -> V_60 + V_57 ;
return F_35 ( V_59 ) ;
}
static void F_36 ( struct V_61 * V_62 ,
struct V_5 * V_6 ,
struct V_2 * V_4 ,
unsigned V_57 ,
unsigned V_59 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
unsigned V_63 ;
int V_64 ;
int V_65 ;
int V_66 ;
T_1 V_31 ;
static const char * const V_67 [] = {
L_5 ,
L_6 ,
L_7 ,
L_8
} ;
V_21 = & V_7 -> V_8 -> V_11 [ V_57 ] ;
V_31 = F_13 ( V_7 -> V_30 + V_21 -> V_31 ) ;
V_64 = ! ! ( V_31 & F_24 ( V_21 -> V_42 ) ) ;
V_63 = ( V_31 >> V_21 -> V_25 ) & 7 ;
V_65 = ( V_31 >> V_21 -> V_40 ) & 7 ;
V_66 = ( V_31 >> V_21 -> V_38 ) & 3 ;
F_37 ( V_62 , L_9 , V_21 -> V_12 , V_64 ? L_10 : L_11 , V_63 ) ;
F_37 ( V_62 , L_12 , F_21 ( V_65 ) ) ;
F_37 ( V_62 , L_13 , V_67 [ V_66 ] ) ;
}
static void F_38 ( struct V_61 * V_62 , struct V_2 * V_4 )
{
unsigned V_59 = V_4 -> V_60 ;
unsigned V_24 ;
for ( V_24 = 0 ; V_24 < V_4 -> V_68 ; V_24 ++ , V_59 ++ ) {
F_36 ( V_62 , NULL , V_4 , V_24 , V_59 ) ;
F_39 ( V_62 , L_14 ) ;
}
}
static void F_40 ( struct V_1 * V_7 ,
const struct V_20 * V_21 ,
struct V_69 * V_70 )
{
int V_71 = 100 ;
unsigned V_23 , V_72 , V_73 ;
unsigned V_74 ;
do {
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_54 ) & F_24 ( V_21 -> V_55 ) ;
V_74 = F_13 ( V_7 -> V_30 + V_21 -> V_75 ) ;
V_74 ^= F_24 ( V_21 -> V_76 ) ;
F_14 ( V_74 , V_7 -> V_30 + V_21 -> V_75 ) ;
V_72 = F_13 ( V_7 -> V_30 + V_21 -> V_54 ) & F_24 ( V_21 -> V_55 ) ;
V_73 = F_13 ( V_7 -> V_30 + V_21 -> V_77 ) ;
if ( V_73 || ( V_23 == V_72 ) )
return;
} while ( V_71 -- > 0 );
F_18 ( V_7 -> V_43 , L_15 ,
V_23 , V_72 ) ;
}
static void F_41 ( struct V_69 * V_70 )
{
struct V_2 * V_3 = F_42 ( V_70 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_70 -> V_78 ] ;
F_12 ( & V_7 -> V_29 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_75 ) ;
V_23 &= ~ F_24 ( V_21 -> V_79 ) ;
F_14 ( V_23 , V_7 -> V_30 + V_21 -> V_75 ) ;
F_43 ( V_70 -> V_78 , V_7 -> V_80 ) ;
F_15 ( & V_7 -> V_29 , V_22 ) ;
}
static void F_44 ( struct V_69 * V_70 )
{
struct V_2 * V_3 = F_42 ( V_70 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_70 -> V_78 ] ;
F_12 ( & V_7 -> V_29 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_77 ) ;
V_23 &= ~ F_24 ( V_21 -> V_81 ) ;
F_14 ( V_23 , V_7 -> V_30 + V_21 -> V_77 ) ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_75 ) ;
V_23 |= F_24 ( V_21 -> V_79 ) ;
F_14 ( V_23 , V_7 -> V_30 + V_21 -> V_75 ) ;
F_45 ( V_70 -> V_78 , V_7 -> V_80 ) ;
F_15 ( & V_7 -> V_29 , V_22 ) ;
}
static void F_46 ( struct V_69 * V_70 )
{
struct V_2 * V_3 = F_42 ( V_70 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_70 -> V_78 ] ;
F_12 ( & V_7 -> V_29 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_77 ) ;
if ( V_21 -> V_82 )
V_23 |= F_24 ( V_21 -> V_81 ) ;
else
V_23 &= ~ F_24 ( V_21 -> V_81 ) ;
F_14 ( V_23 , V_7 -> V_30 + V_21 -> V_77 ) ;
if ( F_47 ( V_70 -> V_78 , V_7 -> V_83 ) )
F_40 ( V_7 , V_21 , V_70 ) ;
F_15 ( & V_7 -> V_29 , V_22 ) ;
}
static int F_48 ( struct V_69 * V_70 , unsigned int type )
{
struct V_2 * V_3 = F_42 ( V_70 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_70 -> V_78 ] ;
F_12 ( & V_7 -> V_29 , V_22 ) ;
if ( V_21 -> V_84 == 1 && type == V_85 )
F_45 ( V_70 -> V_78 , V_7 -> V_83 ) ;
else
F_43 ( V_70 -> V_78 , V_7 -> V_83 ) ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_86 ) ;
V_23 &= ~ ( 7 << V_21 -> V_87 ) ;
V_23 |= V_88 << V_21 -> V_87 ;
F_14 ( V_23 , V_7 -> V_30 + V_21 -> V_86 ) ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_75 ) ;
V_23 |= F_24 ( V_21 -> V_89 ) ;
if ( V_21 -> V_84 == 2 ) {
V_23 &= ~ ( 3 << V_21 -> V_90 ) ;
V_23 &= ~ ( 1 << V_21 -> V_76 ) ;
switch ( type ) {
case V_91 :
V_23 |= 1 << V_21 -> V_90 ;
V_23 |= F_24 ( V_21 -> V_76 ) ;
break;
case V_92 :
V_23 |= 2 << V_21 -> V_90 ;
V_23 |= F_24 ( V_21 -> V_76 ) ;
break;
case V_85 :
V_23 |= 3 << V_21 -> V_90 ;
V_23 |= F_24 ( V_21 -> V_76 ) ;
break;
case V_93 :
break;
case V_94 :
V_23 |= F_24 ( V_21 -> V_76 ) ;
break;
}
} else if ( V_21 -> V_84 == 1 ) {
V_23 &= ~ ( 1 << V_21 -> V_90 ) ;
V_23 &= ~ ( 1 << V_21 -> V_76 ) ;
switch ( type ) {
case V_91 :
V_23 |= F_24 ( V_21 -> V_90 ) ;
V_23 |= F_24 ( V_21 -> V_76 ) ;
break;
case V_92 :
V_23 |= F_24 ( V_21 -> V_90 ) ;
break;
case V_85 :
V_23 |= F_24 ( V_21 -> V_90 ) ;
V_23 |= F_24 ( V_21 -> V_76 ) ;
break;
case V_93 :
break;
case V_94 :
V_23 |= F_24 ( V_21 -> V_76 ) ;
break;
}
} else {
F_49 () ;
}
F_14 ( V_23 , V_7 -> V_30 + V_21 -> V_75 ) ;
if ( F_47 ( V_70 -> V_78 , V_7 -> V_83 ) )
F_40 ( V_7 , V_21 , V_70 ) ;
F_15 ( & V_7 -> V_29 , V_22 ) ;
if ( type & ( V_93 | V_94 ) )
F_50 ( V_70 -> V_95 , V_96 ) ;
else if ( type & ( V_92 | V_91 ) )
F_50 ( V_70 -> V_95 , V_97 ) ;
return 0 ;
}
static int F_51 ( struct V_69 * V_70 , unsigned int V_98 )
{
struct V_2 * V_3 = F_42 ( V_70 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_22 ;
F_12 ( & V_7 -> V_29 , V_22 ) ;
F_52 ( V_7 -> V_95 , V_98 ) ;
F_15 ( & V_7 -> V_29 , V_22 ) ;
return 0 ;
}
static void F_53 ( unsigned int V_95 , struct V_99 * V_100 )
{
struct V_2 * V_3 = F_54 ( V_100 ) ;
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_101 * V_4 = F_55 ( V_95 ) ;
int V_102 ;
int V_103 = 0 ;
T_1 V_23 ;
int V_24 ;
F_56 ( V_4 , V_100 ) ;
F_57 (i, pctrl->enabled_irqs, pctrl->chip.ngpio) {
V_21 = & V_7 -> V_8 -> V_11 [ V_24 ] ;
V_23 = F_13 ( V_7 -> V_30 + V_21 -> V_77 ) ;
if ( V_23 & F_24 ( V_21 -> V_81 ) ) {
V_102 = F_58 ( V_3 -> V_104 , V_24 ) ;
F_59 ( V_102 ) ;
V_103 ++ ;
}
}
if ( V_103 == 0 )
F_60 ( V_95 , V_100 ) ;
F_61 ( V_4 , V_100 ) ;
}
static int F_62 ( struct V_1 * V_7 )
{
struct V_2 * V_4 ;
int V_50 ;
unsigned V_68 = V_7 -> V_8 -> V_105 ;
if ( F_11 ( V_68 > V_106 ) )
return - V_26 ;
V_4 = & V_7 -> V_4 ;
V_4 -> V_60 = 0 ;
V_4 -> V_68 = V_68 ;
V_4 -> V_107 = F_63 ( V_7 -> V_43 ) ;
V_4 -> V_43 = V_7 -> V_43 ;
V_4 -> V_108 = V_109 ;
V_4 -> V_110 = V_7 -> V_43 -> V_110 ;
V_50 = F_64 ( & V_7 -> V_4 ) ;
if ( V_50 ) {
F_18 ( V_7 -> V_43 , L_16 ) ;
return V_50 ;
}
V_50 = F_65 ( & V_7 -> V_4 , F_63 ( V_7 -> V_43 ) , 0 , 0 , V_4 -> V_68 ) ;
if ( V_50 ) {
F_18 ( V_7 -> V_43 , L_17 ) ;
return V_50 ;
}
V_50 = F_66 ( V_4 ,
& V_111 ,
0 ,
V_97 ,
V_112 ) ;
if ( V_50 ) {
F_18 ( V_7 -> V_43 , L_18 ) ;
return - V_113 ;
}
F_67 ( V_4 , & V_111 , V_7 -> V_95 ,
F_53 ) ;
return 0 ;
}
int F_68 ( struct V_114 * V_115 ,
const struct V_116 * V_117 )
{
struct V_1 * V_7 ;
struct V_118 * V_119 ;
int V_50 ;
V_7 = F_69 ( & V_115 -> V_43 , sizeof( * V_7 ) , V_120 ) ;
if ( ! V_7 ) {
F_18 ( & V_115 -> V_43 , L_19 ) ;
return - V_121 ;
}
V_7 -> V_43 = & V_115 -> V_43 ;
V_7 -> V_8 = V_117 ;
V_7 -> V_4 = V_122 ;
F_70 ( & V_7 -> V_29 ) ;
V_119 = F_71 ( V_115 , V_123 , 0 ) ;
V_7 -> V_30 = F_72 ( & V_115 -> V_43 , V_119 ) ;
if ( F_73 ( V_7 -> V_30 ) )
return F_74 ( V_7 -> V_30 ) ;
V_7 -> V_95 = F_75 ( V_115 , 0 ) ;
if ( V_7 -> V_95 < 0 ) {
F_18 ( & V_115 -> V_43 , L_20 ) ;
return V_7 -> V_95 ;
}
V_124 . V_12 = F_63 ( & V_115 -> V_43 ) ;
V_124 . V_13 = V_7 -> V_8 -> V_13 ;
V_124 . V_15 = V_7 -> V_8 -> V_15 ;
V_7 -> V_7 = F_76 ( & V_124 , & V_115 -> V_43 , V_7 ) ;
if ( ! V_7 -> V_7 ) {
F_18 ( & V_115 -> V_43 , L_21 ) ;
return - V_125 ;
}
V_50 = F_62 ( V_7 ) ;
if ( V_50 ) {
F_77 ( V_7 -> V_7 ) ;
return V_50 ;
}
F_78 ( V_115 , V_7 ) ;
F_79 ( & V_115 -> V_43 , L_22 ) ;
return 0 ;
}
int F_80 ( struct V_114 * V_115 )
{
struct V_1 * V_7 = F_81 ( V_115 ) ;
int V_50 ;
V_50 = F_82 ( & V_7 -> V_4 ) ;
if ( V_50 ) {
F_18 ( & V_115 -> V_43 , L_23 ) ;
return V_50 ;
}
F_77 ( V_7 -> V_7 ) ;
return 0 ;
}
