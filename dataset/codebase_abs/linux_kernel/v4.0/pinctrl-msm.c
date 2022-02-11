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
static unsigned F_18 ( T_1 V_23 )
{
return ( V_23 + 1 ) * 2 ;
}
static int F_19 ( struct V_5 * V_6 ,
unsigned int V_10 ,
unsigned long * V_46 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_4 ( V_6 ) ;
unsigned V_32 = F_20 ( * V_46 ) ;
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
V_47 = F_18 ( V_47 ) ;
break;
case V_42 :
if ( ! V_47 )
return - V_27 ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_53 ) ;
V_47 = ! ! ( V_23 & F_21 ( V_21 -> V_54 ) ) ;
break;
default:
F_17 ( V_7 -> V_44 , L_2 ,
V_32 ) ;
return - V_27 ;
}
* V_46 = F_22 ( V_32 , V_47 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
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
V_32 = F_20 ( V_55 [ V_24 ] ) ;
V_47 = F_24 ( V_55 [ V_24 ] ) ;
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
V_23 |= F_21 ( V_21 -> V_57 ) ;
else
V_23 &= ~ F_21 ( V_21 -> V_57 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_53 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
V_47 = 1 ;
break;
default:
F_17 ( V_7 -> V_44 , L_2 ,
V_32 ) ;
return - V_27 ;
}
if ( V_47 & ~ V_33 ) {
F_17 ( V_7 -> V_44 , L_3 , V_32 , V_47 ) ;
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
static int F_25 ( struct V_2 * V_4 , unsigned V_58 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_58 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_30 ) ;
V_23 &= ~ F_21 ( V_21 -> V_43 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_30 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_4 , unsigned V_58 , int V_59 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_58 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_53 ) ;
if ( V_59 )
V_23 |= F_21 ( V_21 -> V_57 ) ;
else
V_23 &= ~ F_21 ( V_21 -> V_57 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_53 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_30 ) ;
V_23 |= F_21 ( V_21 -> V_43 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_30 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_4 , unsigned V_58 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_58 ] ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_53 ) ;
return ! ! ( V_23 & F_21 ( V_21 -> V_54 ) ) ;
}
static void F_28 ( struct V_2 * V_4 , unsigned V_58 , int V_59 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_58 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_53 ) ;
if ( V_59 )
V_23 |= F_21 ( V_21 -> V_57 ) ;
else
V_23 &= ~ F_21 ( V_21 -> V_57 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_53 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
}
static int F_29 ( struct V_2 * V_4 , unsigned V_58 )
{
int V_60 = V_4 -> V_61 + V_58 ;
return F_30 ( V_60 ) ;
}
static void F_31 ( struct V_2 * V_4 , unsigned V_58 )
{
int V_60 = V_4 -> V_61 + V_58 ;
return F_32 ( V_60 ) ;
}
static void F_33 ( struct V_62 * V_63 ,
struct V_5 * V_6 ,
struct V_2 * V_4 ,
unsigned V_58 ,
unsigned V_60 )
{
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_2 ( V_4 , struct V_1 , V_4 ) ;
unsigned V_64 ;
int V_65 ;
int V_66 ;
int V_67 ;
T_1 V_30 ;
static const char * const V_68 [] = {
L_4 ,
L_5 ,
L_6 ,
L_7
} ;
V_21 = & V_7 -> V_8 -> V_11 [ V_58 ] ;
V_30 = F_13 ( V_7 -> V_29 + V_21 -> V_30 ) ;
V_65 = ! ! ( V_30 & F_21 ( V_21 -> V_43 ) ) ;
V_64 = ( V_30 >> V_21 -> V_31 ) & 7 ;
V_66 = ( V_30 >> V_21 -> V_41 ) & 7 ;
V_67 = ( V_30 >> V_21 -> V_39 ) & 3 ;
F_34 ( V_63 , L_8 , V_21 -> V_12 , V_65 ? L_9 : L_10 , V_64 ) ;
F_34 ( V_63 , L_11 , F_18 ( V_66 ) ) ;
F_34 ( V_63 , L_12 , V_68 [ V_67 ] ) ;
}
static void F_35 ( struct V_62 * V_63 , struct V_2 * V_4 )
{
unsigned V_60 = V_4 -> V_61 ;
unsigned V_24 ;
for ( V_24 = 0 ; V_24 < V_4 -> V_69 ; V_24 ++ , V_60 ++ ) {
F_33 ( V_63 , NULL , V_4 , V_24 , V_60 ) ;
F_36 ( V_63 , L_13 ) ;
}
}
static void F_37 ( struct V_1 * V_7 ,
const struct V_20 * V_21 ,
struct V_70 * V_71 )
{
int V_72 = 100 ;
unsigned V_23 , V_73 , V_74 ;
unsigned V_75 ;
do {
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_53 ) & F_21 ( V_21 -> V_54 ) ;
V_75 = F_13 ( V_7 -> V_29 + V_21 -> V_76 ) ;
V_75 ^= F_21 ( V_21 -> V_77 ) ;
F_14 ( V_75 , V_7 -> V_29 + V_21 -> V_76 ) ;
V_73 = F_13 ( V_7 -> V_29 + V_21 -> V_53 ) & F_21 ( V_21 -> V_54 ) ;
V_74 = F_13 ( V_7 -> V_29 + V_21 -> V_78 ) ;
if ( V_74 || ( V_23 == V_73 ) )
return;
} while ( V_72 -- > 0 );
F_17 ( V_7 -> V_44 , L_14 ,
V_23 , V_73 ) ;
}
static void F_38 ( struct V_70 * V_71 )
{
struct V_2 * V_3 = F_39 ( V_71 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_71 -> V_79 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_76 ) ;
V_23 &= ~ F_21 ( V_21 -> V_80 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_76 ) ;
F_40 ( V_71 -> V_79 , V_7 -> V_81 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
}
static void F_41 ( struct V_70 * V_71 )
{
struct V_2 * V_3 = F_39 ( V_71 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_71 -> V_79 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_78 ) ;
V_23 &= ~ F_21 ( V_21 -> V_82 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_78 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_76 ) ;
V_23 |= F_21 ( V_21 -> V_80 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_76 ) ;
F_42 ( V_71 -> V_79 , V_7 -> V_81 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
}
static void F_43 ( struct V_70 * V_71 )
{
struct V_2 * V_3 = F_39 ( V_71 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_71 -> V_79 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_78 ) ;
if ( V_21 -> V_83 )
V_23 |= F_21 ( V_21 -> V_82 ) ;
else
V_23 &= ~ F_21 ( V_21 -> V_82 ) ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_78 ) ;
if ( F_44 ( V_71 -> V_79 , V_7 -> V_84 ) )
F_37 ( V_7 , V_21 , V_71 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
}
static int F_45 ( struct V_70 * V_71 , unsigned int type )
{
struct V_2 * V_3 = F_39 ( V_71 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
const struct V_20 * V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
V_21 = & V_7 -> V_8 -> V_11 [ V_71 -> V_79 ] ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
if ( V_21 -> V_85 == 1 && type == V_86 )
F_42 ( V_71 -> V_79 , V_7 -> V_84 ) ;
else
F_40 ( V_71 -> V_79 , V_7 -> V_84 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_87 ) ;
V_23 &= ~ ( 7 << V_21 -> V_88 ) ;
V_23 |= V_21 -> V_89 << V_21 -> V_88 ;
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_87 ) ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_76 ) ;
V_23 |= F_21 ( V_21 -> V_90 ) ;
if ( V_21 -> V_85 == 2 ) {
V_23 &= ~ ( 3 << V_21 -> V_91 ) ;
V_23 &= ~ ( 1 << V_21 -> V_77 ) ;
switch ( type ) {
case V_92 :
V_23 |= 1 << V_21 -> V_91 ;
V_23 |= F_21 ( V_21 -> V_77 ) ;
break;
case V_93 :
V_23 |= 2 << V_21 -> V_91 ;
V_23 |= F_21 ( V_21 -> V_77 ) ;
break;
case V_86 :
V_23 |= 3 << V_21 -> V_91 ;
V_23 |= F_21 ( V_21 -> V_77 ) ;
break;
case V_94 :
break;
case V_95 :
V_23 |= F_21 ( V_21 -> V_77 ) ;
break;
}
} else if ( V_21 -> V_85 == 1 ) {
V_23 &= ~ ( 1 << V_21 -> V_91 ) ;
V_23 &= ~ ( 1 << V_21 -> V_77 ) ;
switch ( type ) {
case V_92 :
V_23 |= F_21 ( V_21 -> V_91 ) ;
V_23 |= F_21 ( V_21 -> V_77 ) ;
break;
case V_93 :
V_23 |= F_21 ( V_21 -> V_91 ) ;
break;
case V_86 :
V_23 |= F_21 ( V_21 -> V_91 ) ;
V_23 |= F_21 ( V_21 -> V_77 ) ;
break;
case V_94 :
break;
case V_95 :
V_23 |= F_21 ( V_21 -> V_77 ) ;
break;
}
} else {
F_46 () ;
}
F_14 ( V_23 , V_7 -> V_29 + V_21 -> V_76 ) ;
if ( F_44 ( V_71 -> V_79 , V_7 -> V_84 ) )
F_37 ( V_7 , V_21 , V_71 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
if ( type & ( V_94 | V_95 ) )
F_47 ( V_71 -> V_96 , V_97 ) ;
else if ( type & ( V_93 | V_92 ) )
F_47 ( V_71 -> V_96 , V_98 ) ;
return 0 ;
}
static int F_48 ( struct V_70 * V_71 , unsigned int V_99 )
{
struct V_2 * V_3 = F_39 ( V_71 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_22 ;
F_12 ( & V_7 -> V_28 , V_22 ) ;
F_49 ( V_7 -> V_96 , V_99 ) ;
F_15 ( & V_7 -> V_28 , V_22 ) ;
return 0 ;
}
static void F_50 ( unsigned int V_96 , struct V_100 * V_101 )
{
struct V_2 * V_3 = F_51 ( V_101 ) ;
const struct V_20 * V_21 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_102 * V_4 = F_52 ( V_96 ) ;
int V_103 ;
int V_104 = 0 ;
T_1 V_23 ;
int V_24 ;
F_53 ( V_4 , V_101 ) ;
F_54 (i, pctrl->enabled_irqs, pctrl->chip.ngpio) {
V_21 = & V_7 -> V_8 -> V_11 [ V_24 ] ;
V_23 = F_13 ( V_7 -> V_29 + V_21 -> V_78 ) ;
if ( V_23 & F_21 ( V_21 -> V_82 ) ) {
V_103 = F_55 ( V_3 -> V_105 , V_24 ) ;
F_56 ( V_103 ) ;
V_104 ++ ;
}
}
if ( V_104 == 0 )
F_57 ( V_96 , V_101 ) ;
F_58 ( V_4 , V_101 ) ;
}
static int F_59 ( struct V_1 * V_7 )
{
struct V_2 * V_4 ;
int V_48 ;
unsigned V_69 = V_7 -> V_8 -> V_106 ;
if ( F_11 ( V_69 > V_107 ) )
return - V_27 ;
V_4 = & V_7 -> V_4 ;
V_4 -> V_61 = 0 ;
V_4 -> V_69 = V_69 ;
V_4 -> V_108 = F_60 ( V_7 -> V_44 ) ;
V_4 -> V_44 = V_7 -> V_44 ;
V_4 -> V_109 = V_110 ;
V_4 -> V_111 = V_7 -> V_44 -> V_111 ;
V_48 = F_61 ( & V_7 -> V_4 ) ;
if ( V_48 ) {
F_17 ( V_7 -> V_44 , L_15 ) ;
return V_48 ;
}
V_48 = F_62 ( & V_7 -> V_4 , F_60 ( V_7 -> V_44 ) , 0 , 0 , V_4 -> V_69 ) ;
if ( V_48 ) {
F_17 ( V_7 -> V_44 , L_16 ) ;
F_63 ( & V_7 -> V_4 ) ;
return V_48 ;
}
V_48 = F_64 ( V_4 ,
& V_112 ,
0 ,
V_98 ,
V_113 ) ;
if ( V_48 ) {
F_17 ( V_7 -> V_44 , L_17 ) ;
F_63 ( & V_7 -> V_4 ) ;
return - V_114 ;
}
F_65 ( V_4 , & V_112 , V_7 -> V_96 ,
F_50 ) ;
return 0 ;
}
static int F_66 ( struct V_115 * V_116 , unsigned long V_117 ,
void * V_118 )
{
struct V_1 * V_7 = F_2 ( V_116 , struct V_1 , V_119 ) ;
F_14 ( 0 , V_7 -> V_29 + V_120 ) ;
F_67 ( 1000 ) ;
return V_121 ;
}
static void F_68 ( struct V_1 * V_7 )
{
int V_24 ;
const struct V_122 * V_64 = V_7 -> V_8 -> V_18 ;
for ( V_24 = 0 ; V_24 < V_7 -> V_8 -> V_16 ; V_24 ++ )
if ( ! strcmp ( V_64 [ V_24 ] . V_12 , L_18 ) ) {
V_7 -> V_119 . V_123 = F_66 ;
V_7 -> V_119 . V_124 = 128 ;
if ( F_69 ( & V_7 -> V_119 ) )
F_17 ( V_7 -> V_44 ,
L_19 ) ;
break;
}
}
int F_70 ( struct V_125 * V_126 ,
const struct V_127 * V_128 )
{
struct V_1 * V_7 ;
struct V_129 * V_130 ;
int V_48 ;
V_7 = F_71 ( & V_126 -> V_44 , sizeof( * V_7 ) , V_131 ) ;
if ( ! V_7 ) {
F_17 ( & V_126 -> V_44 , L_20 ) ;
return - V_132 ;
}
V_7 -> V_44 = & V_126 -> V_44 ;
V_7 -> V_8 = V_128 ;
V_7 -> V_4 = V_133 ;
F_72 ( & V_7 -> V_28 ) ;
V_130 = F_73 ( V_126 , V_134 , 0 ) ;
V_7 -> V_29 = F_74 ( & V_126 -> V_44 , V_130 ) ;
if ( F_75 ( V_7 -> V_29 ) )
return F_76 ( V_7 -> V_29 ) ;
F_68 ( V_7 ) ;
V_7 -> V_96 = F_77 ( V_126 , 0 ) ;
if ( V_7 -> V_96 < 0 ) {
F_17 ( & V_126 -> V_44 , L_21 ) ;
return V_7 -> V_96 ;
}
V_135 . V_12 = F_60 ( & V_126 -> V_44 ) ;
V_135 . V_13 = V_7 -> V_8 -> V_13 ;
V_135 . V_15 = V_7 -> V_8 -> V_15 ;
V_7 -> V_7 = F_78 ( & V_135 , & V_126 -> V_44 , V_7 ) ;
if ( ! V_7 -> V_7 ) {
F_17 ( & V_126 -> V_44 , L_22 ) ;
return - V_136 ;
}
V_48 = F_59 ( V_7 ) ;
if ( V_48 ) {
F_79 ( V_7 -> V_7 ) ;
return V_48 ;
}
F_80 ( V_126 , V_7 ) ;
F_81 ( & V_126 -> V_44 , L_23 ) ;
return 0 ;
}
int F_82 ( struct V_125 * V_126 )
{
struct V_1 * V_7 = F_83 ( V_126 ) ;
F_63 ( & V_7 -> V_4 ) ;
F_79 ( V_7 -> V_7 ) ;
F_84 ( & V_7 -> V_119 ) ;
return 0 ;
}
