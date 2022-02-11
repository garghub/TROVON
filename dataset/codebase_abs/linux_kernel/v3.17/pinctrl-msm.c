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
* V_34 = V_21 -> V_43 ;
* V_33 = 1 ;
break;
default:
F_17 ( V_7 -> V_44 , L_1 , V_32 ) ;
return - V_45 ;
}
return 0 ;
}
static int F_18 ( struct V_5 * V_6 ,
unsigned int V_46 ,
unsigned long * V_47 )
{
F_17 ( V_6 -> V_44 , L_2 ) ;
return - V_45 ;
}
static int F_19 ( struct V_5 * V_6 , unsigned int V_46 ,
unsigned long * V_48 , unsigned V_49 )
{
F_17 ( V_6 -> V_44 , L_2 ) ;
return - V_45 ;
}
static unsigned F_20 ( T_1 V_23 )
{
return ( V_23 + 1 ) * 2 ;
}
static int F_21 ( struct V_5 * V_6 ,
unsigned int V_10 ,
unsigned long * V_47 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_4 ( V_6 ) ;
unsigned V_32 = F_22 ( * V_47 ) ;
unsigned V_33 ;
unsigned V_50 ;
unsigned V_34 ;
int V_51 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_10 ] ;
V_51 = F_16 ( V_7 , V_21 , V_32 , & V_33 , & V_34 ) ;
if ( V_51 < 0 )
return V_51 ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_30 ) ;
V_50 = ( V_23 >> V_34 ) & V_33 ;
switch ( V_32 ) {
case V_35 :
V_50 = V_50 == V_52 ;
break;
case V_36 :
V_50 = V_50 == V_53 ;
break;
case V_37 :
V_50 = V_50 == V_54 ;
break;
case V_38 :
V_50 = V_50 == V_55 ;
break;
case V_40 :
V_50 = F_20 ( V_50 ) ;
break;
case V_42 :
if ( ! V_50 )
return - V_27 ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_56 ) ;
V_50 = ! ! ( V_23 & F_23 ( V_21 -> V_57 ) ) ;
break;
default:
F_17 ( V_7 -> V_44 , L_3 ,
V_32 ) ;
return - V_27 ;
}
* V_47 = F_24 ( V_32 , V_50 ) ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 ,
unsigned V_10 ,
unsigned long * V_48 ,
unsigned V_49 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_4 ( V_6 ) ;
unsigned long V_22 ;
unsigned V_32 ;
unsigned V_33 ;
unsigned V_50 ;
unsigned V_34 ;
int V_51 ;
T_1 V_23 ;
int V_24 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_10 ] ;
for ( V_24 = 0 ; V_24 < V_49 ; V_24 ++ ) {
V_32 = F_22 ( V_48 [ V_24 ] ) ;
V_50 = F_26 ( V_48 [ V_24 ] ) ;
V_51 = F_16 ( V_7 , V_21 , V_32 , & V_33 , & V_34 ) ;
if ( V_51 < 0 )
return V_51 ;
switch ( V_32 ) {
case V_35 :
V_50 = V_52 ;
break;
case V_36 :
V_50 = V_53 ;
break;
case V_37 :
V_50 = V_54 ;
break;
case V_38 :
V_50 = V_55 ;
break;
case V_40 :
if ( V_50 > 16 || V_50 < 2 || ( V_50 % 2 ) != 0 )
V_50 = - 1 ;
else
V_50 = ( V_50 / 2 ) - 1 ;
break;
case V_42 :
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_56 ) ;
if ( V_50 )
V_23 |= F_23 ( V_21 -> V_58 ) ;
else
V_23 &= ~ F_23 ( V_21 -> V_58 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_56 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
V_50 = 1 ;
break;
default:
F_17 ( V_7 -> V_44 , L_3 ,
V_32 ) ;
return - V_27 ;
}
if ( V_50 & ~ V_33 ) {
F_17 ( V_7 -> V_44 , L_4 , V_32 , V_50 ) ;
return - V_27 ;
}
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_30 ) ;
V_23 &= ~ ( V_33 << V_34 ) ;
V_23 |= V_50 << V_34 ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_30 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
}
return 0 ;
}
static int F_27 ( struct V_2 * V_4 , unsigned V_59 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_59 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_30 ) ;
V_23 &= ~ F_23 ( V_21 -> V_43 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_30 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_4 , unsigned V_59 , int V_60 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_59 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_56 ) ;
if ( V_60 )
V_23 |= F_23 ( V_21 -> V_58 ) ;
else
V_23 &= ~ F_23 ( V_21 -> V_58 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_56 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_30 ) ;
V_23 |= F_23 ( V_21 -> V_43 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_30 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_4 , unsigned V_59 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_59 ] ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_56 ) ;
return ! ! ( V_23 & F_23 ( V_21 -> V_57 ) ) ;
}
static void F_30 ( struct V_2 * V_4 , unsigned V_59 , int V_60 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_59 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_56 ) ;
if ( V_60 )
V_23 |= F_23 ( V_21 -> V_58 ) ;
else
V_23 &= ~ F_23 ( V_21 -> V_58 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_56 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
}
static int F_31 ( struct V_2 * V_4 , unsigned V_59 )
{
int V_61 = V_4 -> V_62 + V_59 ;
return F_32 ( V_61 ) ;
}
static void F_33 ( struct V_2 * V_4 , unsigned V_59 )
{
int V_61 = V_4 -> V_62 + V_59 ;
return F_34 ( V_61 ) ;
}
static void F_35 ( struct V_63 * V_64 ,
struct V_5 * V_6 ,
struct V_2 * V_4 ,
unsigned V_59 ,
unsigned V_61 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
unsigned V_65 ;
int V_66 ;
int V_67 ;
int V_68 ;
T_1 V_30 ;
static const char * const V_69 [] = {
L_5 ,
L_6 ,
L_7 ,
L_8
} ;
V_21 = & V_7 -> V_8 -> V_11 [ V_59 ] ;
V_30 = F_13 ( V_7 -> V_29 + V_21 -> V_30 ) ;
V_66 = ! ! ( V_30 & F_23 ( V_21 -> V_43 ) ) ;
V_65 = ( V_30 >> V_21 -> V_31 ) & 7 ;
V_67 = ( V_30 >> V_21 -> V_41 ) & 7 ;
V_68 = ( V_30 >> V_21 -> V_39 ) & 3 ;
F_36 ( V_64 , L_9 , V_21 -> V_12 , V_66 ? L_10 : L_11 , V_65 ) ;
F_36 ( V_64 , L_12 , F_20 ( V_67 ) ) ;
F_36 ( V_64 , L_13 , V_69 [ V_68 ] ) ;
}
static void F_37 ( struct V_63 * V_64 , struct V_2 * V_4 )
{
unsigned V_61 = V_4 -> V_62 ;
unsigned V_24 ;
for ( V_24 = 0 ; V_24 < V_4 -> V_70 ; V_24 ++ , V_61 ++ ) {
F_35 ( V_64 , NULL , V_4 , V_24 , V_61 ) ;
F_38 ( V_64 , L_14 ) ;
}
}
static void F_39 ( struct V_1 * V_7 ,
const struct V_20 * V_21 ,
struct V_71 * V_72 )
{
int V_73 = 100 ;
unsigned V_23 , V_74 , V_75 ;
unsigned V_76 ;
do {
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_56 ) & F_23 ( V_21 -> V_57 ) ;
V_76 = F_13 ( V_7 -> V_29 + V_21 -> V_77 ) ;
V_76 ^= F_23 ( V_21 -> V_78 ) ;
F_14 ( V_76 , V_7 -> V_29 + V_21 -> V_77 ) ;
V_74 = F_13 ( V_7 -> V_29 + V_21 -> V_56 ) & F_23 ( V_21 -> V_57 ) ;
V_75 = F_13 ( V_7 -> V_29 + V_21 -> V_79 ) ;
if ( V_75 || ( V_23 == V_74 ) )
return;
} while ( V_73 -- > 0 );
F_17 ( V_7 -> V_44 , L_15 ,
V_23 , V_74 ) ;
}
static void F_40 ( struct V_71 * V_72 )
{
struct V_2 * V_3 = F_41 ( V_72 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_72 -> V_80 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_77 ) ;
V_23 &= ~ F_23 ( V_21 -> V_81 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_77 ) ;
F_42 ( V_72 -> V_80 , V_7 -> V_82 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
}
static void F_43 ( struct V_71 * V_72 )
{
struct V_2 * V_3 = F_41 ( V_72 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_72 -> V_80 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_79 ) ;
V_23 &= ~ F_23 ( V_21 -> V_83 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_79 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_77 ) ;
V_23 |= F_23 ( V_21 -> V_81 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_77 ) ;
F_44 ( V_72 -> V_80 , V_7 -> V_82 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
}
static void F_45 ( struct V_71 * V_72 )
{
struct V_2 * V_3 = F_41 ( V_72 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_72 -> V_80 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_79 ) ;
if ( V_21 -> V_84 )
V_23 |= F_23 ( V_21 -> V_83 ) ;
else
V_23 &= ~ F_23 ( V_21 -> V_83 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_79 ) ;
if ( F_46 ( V_72 -> V_80 , V_7 -> V_85 ) )
F_39 ( V_7 , V_21 , V_72 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
}
static int F_47 ( struct V_71 * V_72 , unsigned int type )
{
struct V_2 * V_3 = F_41 ( V_72 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_72 -> V_80 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
if ( V_21 -> V_86 == 1 && type == V_87 )
F_44 ( V_72 -> V_80 , V_7 -> V_85 ) ;
else
F_42 ( V_72 -> V_80 , V_7 -> V_85 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_88 ) ;
V_23 &= ~ ( 7 << V_21 -> V_89 ) ;
V_23 |= V_90 << V_21 -> V_89 ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_88 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_77 ) ;
V_23 |= F_23 ( V_21 -> V_91 ) ;
if ( V_21 -> V_86 == 2 ) {
V_23 &= ~ ( 3 << V_21 -> V_92 ) ;
V_23 &= ~ ( 1 << V_21 -> V_78 ) ;
switch ( type ) {
case V_93 :
V_23 |= 1 << V_21 -> V_92 ;
V_23 |= F_23 ( V_21 -> V_78 ) ;
break;
case V_94 :
V_23 |= 2 << V_21 -> V_92 ;
V_23 |= F_23 ( V_21 -> V_78 ) ;
break;
case V_87 :
V_23 |= 3 << V_21 -> V_92 ;
V_23 |= F_23 ( V_21 -> V_78 ) ;
break;
case V_95 :
break;
case V_96 :
V_23 |= F_23 ( V_21 -> V_78 ) ;
break;
}
} else if ( V_21 -> V_86 == 1 ) {
V_23 &= ~ ( 1 << V_21 -> V_92 ) ;
V_23 &= ~ ( 1 << V_21 -> V_78 ) ;
switch ( type ) {
case V_93 :
V_23 |= F_23 ( V_21 -> V_92 ) ;
V_23 |= F_23 ( V_21 -> V_78 ) ;
break;
case V_94 :
V_23 |= F_23 ( V_21 -> V_92 ) ;
break;
case V_87 :
V_23 |= F_23 ( V_21 -> V_92 ) ;
V_23 |= F_23 ( V_21 -> V_78 ) ;
break;
case V_95 :
break;
case V_96 :
V_23 |= F_23 ( V_21 -> V_78 ) ;
break;
}
} else {
F_48 () ;
}
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_77 ) ;
if ( F_46 ( V_72 -> V_80 , V_7 -> V_85 ) )
F_39 ( V_7 , V_21 , V_72 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
if ( type & ( V_95 | V_96 ) )
F_49 ( V_72 -> V_97 , V_98 ) ;
else if ( type & ( V_94 | V_93 ) )
F_49 ( V_72 -> V_97 , V_99 ) ;
return 0 ;
}
static int F_50 ( struct V_71 * V_72 , unsigned int V_100 )
{
struct V_2 * V_3 = F_41 ( V_72 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_22 ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
F_51 ( V_7 -> V_97 , V_100 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
return 0 ;
}
static void F_52 ( unsigned int V_97 , struct V_101 * V_102 )
{
struct V_2 * V_3 = F_53 ( V_102 ) ;
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_103 * V_4 = F_54 ( V_97 ) ;
int V_104 ;
int V_105 = 0 ;
T_1 V_23 ;
int V_24 ;
F_55 ( V_4 , V_102 ) ;
F_56 (i, pctrl->enabled_irqs, pctrl->chip.ngpio) {
V_21 = & V_7 -> V_8 -> V_11 [ V_24 ] ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_79 ) ;
if ( V_23 & F_23 ( V_21 -> V_83 ) ) {
V_104 = F_57 ( V_3 -> V_106 , V_24 ) ;
F_58 ( V_104 ) ;
V_105 ++ ;
}
}
if ( V_105 == 0 )
F_59 ( V_97 , V_102 ) ;
F_60 ( V_4 , V_102 ) ;
}
static int F_61 ( struct V_1 * V_7 )
{
struct V_2 * V_4 ;
int V_51 ;
unsigned V_70 = V_7 -> V_8 -> V_107 ;
if ( F_11 ( V_70 > V_108 ) )
return - V_27 ;
V_4 = & V_7 -> V_4 ;
V_4 -> V_62 = 0 ;
V_4 -> V_70 = V_70 ;
V_4 -> V_109 = F_62 ( V_7 -> V_44 ) ;
V_4 -> V_44 = V_7 -> V_44 ;
V_4 -> V_110 = V_111 ;
V_4 -> V_112 = V_7 -> V_44 -> V_112 ;
V_51 = F_63 ( & V_7 -> V_4 ) ;
if ( V_51 ) {
F_17 ( V_7 -> V_44 , L_16 ) ;
return V_51 ;
}
V_51 = F_64 ( & V_7 -> V_4 , F_62 ( V_7 -> V_44 ) , 0 , 0 , V_4 -> V_70 ) ;
if ( V_51 ) {
F_17 ( V_7 -> V_44 , L_17 ) ;
return V_51 ;
}
V_51 = F_65 ( V_4 ,
& V_113 ,
0 ,
V_99 ,
V_114 ) ;
if ( V_51 ) {
F_17 ( V_7 -> V_44 , L_18 ) ;
return - V_115 ;
}
F_66 ( V_4 , & V_113 , V_7 -> V_97 ,
F_52 ) ;
return 0 ;
}
int F_67 ( struct V_116 * V_117 ,
const struct V_118 * V_119 )
{
struct V_1 * V_7 ;
struct V_120 * V_121 ;
int V_51 ;
V_7 = F_68 ( & V_117 -> V_44 , sizeof( * V_7 ) , V_122 ) ;
if ( ! V_7 ) {
F_17 ( & V_117 -> V_44 , L_19 ) ;
return - V_123 ;
}
V_7 -> V_44 = & V_117 -> V_44 ;
V_7 -> V_8 = V_119 ;
V_7 -> V_4 = V_124 ;
F_69 ( & V_7 -> V_28 ) ;
V_121 = F_70 ( V_117 , V_125 , 0 ) ;
V_7 -> V_29 = F_71 ( & V_117 -> V_44 , V_121 ) ;
if ( F_72 ( V_7 -> V_29 ) )
return F_73 ( V_7 -> V_29 ) ;
V_7 -> V_97 = F_74 ( V_117 , 0 ) ;
if ( V_7 -> V_97 < 0 ) {
F_17 ( & V_117 -> V_44 , L_20 ) ;
return V_7 -> V_97 ;
}
V_126 . V_12 = F_62 ( & V_117 -> V_44 ) ;
V_126 . V_13 = V_7 -> V_8 -> V_13 ;
V_126 . V_15 = V_7 -> V_8 -> V_15 ;
V_7 -> V_7 = F_75 ( & V_126 , & V_117 -> V_44 , V_7 ) ;
if ( ! V_7 -> V_7 ) {
F_17 ( & V_117 -> V_44 , L_21 ) ;
return - V_127 ;
}
V_51 = F_61 ( V_7 ) ;
if ( V_51 ) {
F_76 ( V_7 -> V_7 ) ;
return V_51 ;
}
F_77 ( V_117 , V_7 ) ;
F_78 ( & V_117 -> V_44 , L_22 ) ;
return 0 ;
}
int F_79 ( struct V_116 * V_117 )
{
struct V_1 * V_7 = F_80 ( V_117 ) ;
int V_51 ;
V_51 = F_81 ( & V_7 -> V_4 ) ;
if ( V_51 ) {
F_17 ( & V_117 -> V_44 , L_23 ) ;
return V_51 ;
}
F_76 ( V_7 -> V_7 ) ;
return 0 ;
}
