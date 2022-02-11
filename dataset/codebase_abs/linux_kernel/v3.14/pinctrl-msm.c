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
T_2 * V_29 ,
unsigned * V_30 ,
unsigned * V_31 )
{
switch ( V_28 ) {
case V_32 :
* V_29 = V_18 -> V_27 ;
* V_31 = V_18 -> V_33 ;
* V_30 = 3 ;
break;
case V_34 :
* V_29 = V_18 -> V_27 ;
* V_31 = V_18 -> V_33 ;
* V_30 = 3 ;
break;
case V_35 :
* V_29 = V_18 -> V_27 ;
* V_31 = V_18 -> V_33 ;
* V_30 = 3 ;
break;
case V_36 :
* V_29 = V_18 -> V_27 ;
* V_31 = V_18 -> V_37 ;
* V_30 = 7 ;
break;
default:
F_17 ( V_4 -> V_38 , L_1 , V_28 ) ;
return - V_39 ;
}
if ( * V_29 < 0 ) {
F_17 ( V_4 -> V_38 , L_2 ,
V_28 , V_18 -> V_9 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned int V_40 ,
unsigned long * V_41 )
{
F_17 ( V_2 -> V_38 , L_3 ) ;
return - V_39 ;
}
static int F_19 ( struct V_1 * V_2 , unsigned int V_40 ,
unsigned long * V_42 , unsigned V_43 )
{
F_17 ( V_2 -> V_38 , L_3 ) ;
return - V_39 ;
}
static int F_20 ( struct V_1 * V_2 ,
unsigned int V_7 ,
unsigned long * V_41 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned V_28 = F_21 ( * V_41 ) ;
unsigned V_30 ;
unsigned V_44 ;
unsigned V_31 ;
T_2 V_29 ;
int V_45 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_7 ] ;
V_45 = F_16 ( V_4 , V_18 , V_28 , & V_29 , & V_30 , & V_31 ) ;
if ( V_45 < 0 )
return V_45 ;
V_20 = F_12 ( V_4 -> V_26 + V_29 ) ;
V_44 = ( V_20 >> V_31 ) & V_30 ;
switch ( V_28 ) {
case V_32 :
V_44 = V_44 == V_46 ;
break;
case V_34 :
V_44 = V_44 == V_47 ;
break;
case V_35 :
V_44 = V_44 == V_48 ;
break;
case V_36 :
V_44 = V_49 [ V_44 ] ;
break;
default:
F_17 ( V_4 -> V_38 , L_4 ,
V_28 ) ;
return - V_23 ;
}
* V_41 = F_22 ( V_28 , V_44 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned V_7 ,
unsigned long * V_42 ,
unsigned V_43 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_19 ;
unsigned V_28 ;
unsigned V_30 ;
unsigned V_44 ;
unsigned V_31 ;
T_2 V_29 ;
int V_45 ;
T_1 V_20 ;
int V_21 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_7 ] ;
for ( V_21 = 0 ; V_21 < V_43 ; V_21 ++ ) {
V_28 = F_21 ( V_42 [ V_21 ] ) ;
V_44 = F_24 ( V_42 [ V_21 ] ) ;
V_45 = F_16 ( V_4 , V_18 , V_28 , & V_29 , & V_30 , & V_31 ) ;
if ( V_45 < 0 )
return V_45 ;
switch ( V_28 ) {
case V_32 :
V_44 = V_46 ;
break;
case V_34 :
V_44 = V_47 ;
break;
case V_35 :
V_44 = V_48 ;
break;
case V_36 :
if ( V_44 >= F_10 ( V_50 ) )
V_44 = - 1 ;
else
V_44 = V_50 [ V_44 ] ;
break;
default:
F_17 ( V_4 -> V_38 , L_4 ,
V_28 ) ;
return - V_23 ;
}
if ( V_44 & ~ V_30 ) {
F_17 ( V_4 -> V_38 , L_5 , V_28 , V_44 ) ;
return - V_23 ;
}
F_11 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_29 ) ;
V_20 &= ~ ( V_30 << V_31 ) ;
V_20 |= V_44 << V_31 ;
F_13 ( V_20 , V_4 -> V_26 + V_29 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
}
return 0 ;
}
static int F_25 ( struct V_51 * V_52 , unsigned V_53 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_26 ( V_52 , struct V_3 , V_52 ) ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_53 ] ;
if ( F_9 ( V_18 -> V_54 < 0 ) )
return - V_23 ;
F_11 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_27 ) ;
V_20 &= ~ F_27 ( V_18 -> V_55 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_27 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
return 0 ;
}
static int F_28 ( struct V_51 * V_52 , unsigned V_53 , int V_56 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_26 ( V_52 , struct V_3 , V_52 ) ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_53 ] ;
if ( F_9 ( V_18 -> V_54 < 0 ) )
return - V_23 ;
F_11 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_54 ) ;
if ( V_56 )
V_20 |= F_27 ( V_18 -> V_57 ) ;
else
V_20 &= ~ F_27 ( V_18 -> V_57 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_54 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_27 ) ;
V_20 |= F_27 ( V_18 -> V_55 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_27 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
return 0 ;
}
static int F_29 ( struct V_51 * V_52 , unsigned V_53 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_26 ( V_52 , struct V_3 , V_52 ) ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_53 ] ;
if ( F_9 ( V_18 -> V_54 < 0 ) )
return - V_23 ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_54 ) ;
return ! ! ( V_20 & F_27 ( V_18 -> V_58 ) ) ;
}
static void F_30 ( struct V_51 * V_52 , unsigned V_53 , int V_56 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_26 ( V_52 , struct V_3 , V_52 ) ;
unsigned long V_19 ;
T_1 V_20 ;
V_18 = & V_4 -> V_5 -> V_8 [ V_53 ] ;
if ( F_9 ( V_18 -> V_54 < 0 ) )
return;
F_11 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_54 ) ;
if ( V_56 )
V_20 |= F_27 ( V_18 -> V_57 ) ;
else
V_20 &= ~ F_27 ( V_18 -> V_57 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_54 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
}
static int F_31 ( struct V_51 * V_52 , unsigned V_53 )
{
struct V_3 * V_4 = F_26 ( V_52 , struct V_3 , V_52 ) ;
return F_32 ( V_4 -> V_59 , V_53 ) ;
}
static int F_33 ( struct V_51 * V_52 , unsigned V_53 )
{
int V_60 = V_52 -> V_61 + V_53 ;
return F_34 ( V_60 ) ;
}
static void F_35 ( struct V_51 * V_52 , unsigned V_53 )
{
int V_60 = V_52 -> V_61 + V_53 ;
return F_36 ( V_60 ) ;
}
static void F_37 ( struct V_62 * V_63 ,
struct V_1 * V_2 ,
struct V_51 * V_52 ,
unsigned V_53 ,
unsigned V_60 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_26 ( V_52 , struct V_3 , V_52 ) ;
unsigned V_64 ;
int V_65 ;
int V_66 ;
int V_67 ;
T_1 V_27 ;
static const char * const V_68 [] = {
L_6 ,
L_7 ,
L_8 ,
L_9
} ;
V_18 = & V_4 -> V_5 -> V_8 [ V_53 ] ;
V_27 = F_12 ( V_4 -> V_26 + V_18 -> V_27 ) ;
V_65 = ! ! ( V_27 & F_27 ( V_18 -> V_55 ) ) ;
V_64 = ( V_27 >> V_18 -> V_22 ) & 7 ;
V_66 = ( V_27 >> V_18 -> V_37 ) & 7 ;
V_67 = ( V_27 >> V_18 -> V_33 ) & 3 ;
F_38 ( V_63 , L_10 , V_18 -> V_9 , V_65 ? L_11 : L_12 , V_64 ) ;
F_38 ( V_63 , L_13 , V_49 [ V_66 ] ) ;
F_38 ( V_63 , L_14 , V_68 [ V_67 ] ) ;
}
static void F_39 ( struct V_62 * V_63 , struct V_51 * V_52 )
{
unsigned V_60 = V_52 -> V_61 ;
unsigned V_21 ;
for ( V_21 = 0 ; V_21 < V_52 -> V_69 ; V_21 ++ , V_60 ++ ) {
F_37 ( V_63 , NULL , V_52 , V_21 , V_60 ) ;
F_40 ( V_63 , L_15 ) ;
}
}
static void F_41 ( struct V_3 * V_4 ,
const struct V_17 * V_18 ,
struct V_70 * V_71 )
{
int V_72 = 100 ;
unsigned V_20 , V_73 , V_74 ;
unsigned V_75 ;
do {
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_54 ) & F_27 ( V_18 -> V_58 ) ;
V_75 = F_12 ( V_4 -> V_26 + V_18 -> V_76 ) ;
V_75 ^= F_27 ( V_18 -> V_77 ) ;
F_13 ( V_75 , V_4 -> V_26 + V_18 -> V_76 ) ;
V_73 = F_12 ( V_4 -> V_26 + V_18 -> V_54 ) & F_27 ( V_18 -> V_58 ) ;
V_74 = F_12 ( V_4 -> V_26 + V_18 -> V_78 ) ;
if ( V_74 || ( V_20 == V_73 ) )
return;
} while ( V_72 -- > 0 );
F_17 ( V_4 -> V_38 , L_16 ,
V_20 , V_73 ) ;
}
static void F_42 ( struct V_70 * V_71 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 ;
unsigned long V_19 ;
T_1 V_20 ;
V_4 = F_43 ( V_71 ) ;
V_18 = & V_4 -> V_5 -> V_8 [ V_71 -> V_79 ] ;
if ( F_9 ( V_18 -> V_76 < 0 ) )
return;
F_11 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_76 ) ;
V_20 &= ~ F_27 ( V_18 -> V_80 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_76 ) ;
F_44 ( V_71 -> V_79 , V_4 -> V_81 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
}
static void F_45 ( struct V_70 * V_71 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 ;
unsigned long V_19 ;
T_1 V_20 ;
V_4 = F_43 ( V_71 ) ;
V_18 = & V_4 -> V_5 -> V_8 [ V_71 -> V_79 ] ;
if ( F_9 ( V_18 -> V_78 < 0 ) )
return;
F_11 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_78 ) ;
V_20 &= ~ F_27 ( V_18 -> V_82 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_78 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_76 ) ;
V_20 |= F_27 ( V_18 -> V_80 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_76 ) ;
F_46 ( V_71 -> V_79 , V_4 -> V_81 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
}
static void F_47 ( struct V_70 * V_71 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 ;
unsigned long V_19 ;
T_1 V_20 ;
V_4 = F_43 ( V_71 ) ;
V_18 = & V_4 -> V_5 -> V_8 [ V_71 -> V_79 ] ;
if ( F_9 ( V_18 -> V_78 < 0 ) )
return;
F_11 ( & V_4 -> V_25 , V_19 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_78 ) ;
V_20 &= ~ F_27 ( V_18 -> V_82 ) ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_78 ) ;
if ( F_48 ( V_71 -> V_79 , V_4 -> V_83 ) )
F_41 ( V_4 , V_18 , V_71 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
}
static int F_49 ( struct V_70 * V_71 , unsigned int type )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 ;
unsigned long V_19 ;
T_1 V_20 ;
V_4 = F_43 ( V_71 ) ;
V_18 = & V_4 -> V_5 -> V_8 [ V_71 -> V_79 ] ;
if ( F_9 ( V_18 -> V_76 < 0 ) )
return - V_23 ;
F_11 ( & V_4 -> V_25 , V_19 ) ;
if ( V_18 -> V_84 == 1 && type == V_85 )
F_46 ( V_71 -> V_79 , V_4 -> V_83 ) ;
else
F_44 ( V_71 -> V_79 , V_4 -> V_83 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_86 ) ;
V_20 &= ~ ( 7 << V_18 -> V_87 ) ;
V_20 |= V_88 << V_18 -> V_87 ;
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_86 ) ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_76 ) ;
V_20 |= F_27 ( V_18 -> V_89 ) ;
if ( V_18 -> V_84 == 2 ) {
V_20 &= ~ ( 3 << V_18 -> V_90 ) ;
V_20 &= ~ ( 1 << V_18 -> V_77 ) ;
switch ( type ) {
case V_91 :
V_20 |= 1 << V_18 -> V_90 ;
V_20 |= F_27 ( V_18 -> V_77 ) ;
break;
case V_92 :
V_20 |= 2 << V_18 -> V_90 ;
V_20 |= F_27 ( V_18 -> V_77 ) ;
break;
case V_85 :
V_20 |= 3 << V_18 -> V_90 ;
V_20 |= F_27 ( V_18 -> V_77 ) ;
break;
case V_93 :
break;
case V_94 :
V_20 |= F_27 ( V_18 -> V_77 ) ;
break;
}
} else if ( V_18 -> V_84 == 1 ) {
V_20 &= ~ ( 1 << V_18 -> V_90 ) ;
V_20 &= ~ ( 1 << V_18 -> V_77 ) ;
switch ( type ) {
case V_91 :
V_20 |= F_27 ( V_18 -> V_90 ) ;
V_20 |= F_27 ( V_18 -> V_77 ) ;
break;
case V_92 :
V_20 |= F_27 ( V_18 -> V_90 ) ;
break;
case V_85 :
V_20 |= F_27 ( V_18 -> V_90 ) ;
break;
case V_93 :
break;
case V_94 :
V_20 |= F_27 ( V_18 -> V_77 ) ;
break;
}
} else {
F_50 () ;
}
F_13 ( V_20 , V_4 -> V_26 + V_18 -> V_76 ) ;
if ( F_48 ( V_71 -> V_79 , V_4 -> V_83 ) )
F_41 ( V_4 , V_18 , V_71 ) ;
F_14 ( & V_4 -> V_25 , V_19 ) ;
if ( type & ( V_93 | V_94 ) )
F_51 ( V_71 -> V_95 , V_96 ) ;
else if ( type & ( V_92 | V_91 ) )
F_51 ( V_71 -> V_95 , V_97 ) ;
return 0 ;
}
static int F_52 ( struct V_70 * V_71 , unsigned int V_98 )
{
struct V_3 * V_4 ;
unsigned long V_19 ;
unsigned V_69 ;
V_4 = F_43 ( V_71 ) ;
V_69 = V_4 -> V_52 . V_69 ;
F_11 ( & V_4 -> V_25 , V_19 ) ;
if ( V_98 ) {
if ( F_53 ( V_4 -> V_99 , V_69 ) )
F_54 ( V_4 -> V_95 ) ;
F_46 ( V_71 -> V_79 , V_4 -> V_99 ) ;
} else {
F_44 ( V_71 -> V_79 , V_4 -> V_99 ) ;
if ( F_53 ( V_4 -> V_99 , V_69 ) )
F_55 ( V_4 -> V_95 ) ;
}
F_14 ( & V_4 -> V_25 , V_19 ) ;
return 0 ;
}
static unsigned int F_56 ( struct V_70 * V_71 )
{
struct V_3 * V_4 = F_43 ( V_71 ) ;
if ( F_57 ( & V_4 -> V_52 , V_71 -> V_79 ) ) {
F_17 ( V_4 -> V_38 , L_17 ,
V_71 -> V_79 ) ;
}
F_45 ( V_71 ) ;
return 0 ;
}
static void F_58 ( struct V_70 * V_71 )
{
struct V_3 * V_4 = F_43 ( V_71 ) ;
F_42 ( V_71 ) ;
F_59 ( & V_4 -> V_52 , V_71 -> V_79 ) ;
}
static void F_60 ( unsigned int V_95 , struct V_100 * V_101 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 = F_61 ( V_101 ) ;
struct V_102 * V_52 = F_62 ( V_95 ) ;
int V_103 ;
int V_104 = 0 ;
T_1 V_20 ;
int V_21 ;
F_63 ( V_52 , V_101 ) ;
F_64 (i, pctrl->enabled_irqs, pctrl->chip.ngpio) {
V_18 = & V_4 -> V_5 -> V_8 [ V_21 ] ;
V_20 = F_12 ( V_4 -> V_26 + V_18 -> V_78 ) ;
if ( V_20 & F_27 ( V_18 -> V_82 ) ) {
V_103 = F_32 ( V_4 -> V_59 , V_21 ) ;
F_65 ( V_103 ) ;
V_104 ++ ;
}
}
if ( V_104 == 0 )
F_66 ( V_95 , V_101 ) ;
F_67 ( V_52 , V_101 ) ;
}
static int F_68 ( struct V_3 * V_4 )
{
struct V_51 * V_52 ;
int V_95 ;
int V_45 ;
int V_21 ;
int V_105 ;
V_52 = & V_4 -> V_52 ;
V_52 -> V_61 = 0 ;
V_52 -> V_69 = V_4 -> V_5 -> V_106 ;
V_52 -> V_107 = F_69 ( V_4 -> V_38 ) ;
V_52 -> V_38 = V_4 -> V_38 ;
V_52 -> V_108 = V_109 ;
V_52 -> V_110 = V_4 -> V_38 -> V_110 ;
V_45 = F_70 ( & V_4 -> V_52 ) ;
if ( V_45 ) {
F_17 ( V_4 -> V_38 , L_18 ) ;
return V_45 ;
}
V_45 = F_71 ( & V_4 -> V_52 , F_69 ( V_4 -> V_38 ) , 0 , 0 , V_52 -> V_69 ) ;
if ( V_45 ) {
F_17 ( V_4 -> V_38 , L_19 ) ;
return V_45 ;
}
V_4 -> V_59 = F_72 ( V_4 -> V_38 -> V_110 , V_52 -> V_69 ,
& V_111 , NULL ) ;
if ( ! V_4 -> V_59 ) {
F_17 ( V_4 -> V_38 , L_20 ) ;
V_105 = F_73 ( & V_4 -> V_52 ) ;
return - V_112 ;
}
for ( V_21 = 0 ; V_21 < V_52 -> V_69 ; V_21 ++ ) {
V_95 = F_74 ( V_4 -> V_59 , V_21 ) ;
F_75 ( V_95 , & V_113 , V_97 ) ;
F_76 ( V_95 , V_4 ) ;
}
F_77 ( V_4 -> V_95 , V_4 ) ;
F_78 ( V_4 -> V_95 , F_60 ) ;
return 0 ;
}
int F_79 ( struct V_114 * V_115 ,
const struct V_116 * V_117 )
{
struct V_3 * V_4 ;
struct V_118 * V_119 ;
int V_45 ;
V_4 = F_80 ( & V_115 -> V_38 , sizeof( * V_4 ) , V_120 ) ;
if ( ! V_4 ) {
F_17 ( & V_115 -> V_38 , L_21 ) ;
return - V_121 ;
}
V_4 -> V_38 = & V_115 -> V_38 ;
V_4 -> V_5 = V_117 ;
V_4 -> V_52 = V_122 ;
F_81 ( & V_4 -> V_25 ) ;
V_119 = F_82 ( V_115 , V_123 , 0 ) ;
V_4 -> V_26 = F_83 ( & V_115 -> V_38 , V_119 ) ;
if ( F_84 ( V_4 -> V_26 ) )
return F_85 ( V_4 -> V_26 ) ;
V_4 -> V_95 = F_86 ( V_115 , 0 ) ;
if ( V_4 -> V_95 < 0 ) {
F_17 ( & V_115 -> V_38 , L_22 ) ;
return V_4 -> V_95 ;
}
V_124 . V_9 = F_69 ( & V_115 -> V_38 ) ;
V_124 . V_10 = V_4 -> V_5 -> V_10 ;
V_124 . V_12 = V_4 -> V_5 -> V_12 ;
V_4 -> V_4 = F_87 ( & V_124 , & V_115 -> V_38 , V_4 ) ;
if ( ! V_4 -> V_4 ) {
F_17 ( & V_115 -> V_38 , L_23 ) ;
return - V_125 ;
}
V_45 = F_68 ( V_4 ) ;
if ( V_45 ) {
F_88 ( V_4 -> V_4 ) ;
return V_45 ;
}
F_89 ( V_115 , V_4 ) ;
F_90 ( & V_115 -> V_38 , L_24 ) ;
return 0 ;
}
int F_91 ( struct V_114 * V_115 )
{
struct V_3 * V_4 = F_92 ( V_115 ) ;
int V_45 ;
V_45 = F_73 ( & V_4 -> V_52 ) ;
if ( V_45 ) {
F_17 ( & V_115 -> V_38 , L_25 ) ;
return V_45 ;
}
F_78 ( V_4 -> V_95 , NULL ) ;
F_93 ( V_4 -> V_59 ) ;
F_88 ( V_4 -> V_4 ) ;
return 0 ;
}
