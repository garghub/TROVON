static const struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 = F_2 ( V_2 ) ;
F_3 ( V_3 > F_4 ( V_4 ) ) ;
return & V_4 [ V_3 ] ;
}
static void T_1 * F_5 ( struct V_5 * V_6 ,
const struct V_1 * V_3 ,
unsigned int V_7 )
{
return V_6 -> V_8 + V_3 -> V_9 + V_7 ;
}
static void T_1 * F_6 ( struct V_5 * V_6 ,
const struct V_1 * V_3 ,
unsigned int V_7 )
{
return V_6 -> V_8 + V_3 -> V_10 + V_7 ;
}
static int F_7 ( struct V_11 * V_12 , unsigned int V_2 )
{
struct V_5 * V_6 = F_8 ( V_12 ) ;
const struct V_1 * V_3 = F_1 ( V_2 ) ;
return ! ! ( F_9 ( F_5 ( V_6 , V_3 , V_13 ) )
& F_10 ( V_2 ) ) ;
}
static void F_11 ( struct V_11 * V_12 , unsigned int V_2 ,
int V_14 )
{
struct V_5 * V_6 = F_8 ( V_12 ) ;
const struct V_1 * V_3 = F_1 ( V_2 ) ;
void T_1 * V_15 ;
T_2 V_7 ;
V_15 = F_5 ( V_6 , V_3 , V_13 ) ;
V_7 = F_9 ( V_15 ) ;
if ( V_14 )
V_7 |= F_10 ( V_2 ) ;
else
V_7 &= ~ F_10 ( V_2 ) ;
F_12 ( V_7 , V_15 ) ;
}
static void F_13 ( struct V_11 * V_12 , unsigned int V_2 ,
int V_14 )
{
struct V_5 * V_6 = F_8 ( V_12 ) ;
unsigned long V_16 ;
F_14 ( & V_6 -> V_17 , V_16 ) ;
F_11 ( V_12 , V_2 , V_14 ) ;
F_15 ( & V_6 -> V_17 , V_16 ) ;
}
static int F_16 ( struct V_11 * V_12 , unsigned int V_2 )
{
struct V_5 * V_6 = F_8 ( V_12 ) ;
const struct V_1 * V_3 = F_1 ( V_2 ) ;
unsigned long V_16 ;
T_2 V_7 ;
F_14 ( & V_6 -> V_17 , V_16 ) ;
V_7 = F_9 ( F_5 ( V_6 , V_3 , V_18 ) ) ;
F_12 ( V_7 & ~ F_10 ( V_2 ) , F_5 ( V_6 , V_3 , V_18 ) ) ;
F_15 ( & V_6 -> V_17 , V_16 ) ;
return 0 ;
}
static int F_17 ( struct V_11 * V_12 ,
unsigned int V_2 , int V_14 )
{
struct V_5 * V_6 = F_8 ( V_12 ) ;
const struct V_1 * V_3 = F_1 ( V_2 ) ;
unsigned long V_16 ;
T_2 V_7 ;
F_14 ( & V_6 -> V_17 , V_16 ) ;
V_7 = F_9 ( F_5 ( V_6 , V_3 , V_18 ) ) ;
F_12 ( V_7 | F_10 ( V_2 ) , F_5 ( V_6 , V_3 , V_18 ) ) ;
F_11 ( V_12 , V_2 , V_14 ) ;
F_15 ( & V_6 -> V_17 , V_16 ) ;
return 0 ;
}
static int F_18 ( struct V_11 * V_12 , unsigned int V_2 )
{
struct V_5 * V_6 = F_8 ( V_12 ) ;
const struct V_1 * V_3 = F_1 ( V_2 ) ;
unsigned long V_16 ;
T_2 V_14 ;
F_14 ( & V_6 -> V_17 , V_16 ) ;
V_14 = F_9 ( F_5 ( V_6 , V_3 , V_18 ) ) & F_10 ( V_2 ) ;
F_15 ( & V_6 -> V_17 , V_16 ) ;
return ! V_14 ;
}
static inline int F_19 ( struct V_19 * V_20 ,
struct V_5 * * V_6 ,
const struct V_1 * * V_3 ,
T_2 * V_21 )
{
int V_2 ;
V_2 = F_20 ( V_20 ) ;
* V_6 = F_21 ( V_20 ) ;
* V_3 = F_1 ( V_2 ) ;
* V_21 = F_10 ( V_2 ) ;
return 0 ;
}
static void F_22 ( struct V_19 * V_20 )
{
const struct V_1 * V_3 ;
struct V_5 * V_6 ;
unsigned long V_16 ;
void T_1 * V_22 ;
T_2 V_21 ;
int V_23 ;
V_23 = F_19 ( V_20 , & V_6 , & V_3 , & V_21 ) ;
if ( V_23 )
return;
V_22 = F_6 ( V_6 , V_3 , V_24 ) ;
F_14 ( & V_6 -> V_17 , V_16 ) ;
F_12 ( V_21 , V_22 ) ;
F_15 ( & V_6 -> V_17 , V_16 ) ;
}
static void F_23 ( struct V_19 * V_20 , bool V_25 )
{
const struct V_1 * V_3 ;
struct V_5 * V_6 ;
unsigned long V_16 ;
T_2 V_7 , V_21 ;
void T_1 * V_15 ;
int V_23 ;
V_23 = F_19 ( V_20 , & V_6 , & V_3 , & V_21 ) ;
if ( V_23 )
return;
V_15 = F_6 ( V_6 , V_3 , V_26 ) ;
F_14 ( & V_6 -> V_17 , V_16 ) ;
V_7 = F_9 ( V_15 ) ;
if ( V_25 )
V_7 |= V_21 ;
else
V_7 &= V_21 ;
F_12 ( V_7 , V_15 ) ;
F_15 ( & V_6 -> V_17 , V_16 ) ;
}
static void F_24 ( struct V_19 * V_20 )
{
F_23 ( V_20 , false ) ;
}
static void F_25 ( struct V_19 * V_20 )
{
F_23 ( V_20 , true ) ;
}
static int F_26 ( struct V_19 * V_20 , unsigned int type )
{
T_2 V_27 = 0 ;
T_2 V_28 = 0 ;
T_2 V_29 = 0 ;
T_2 V_21 , V_7 ;
const struct V_1 * V_3 ;
T_3 V_30 ;
struct V_5 * V_6 ;
unsigned long V_16 ;
void T_1 * V_15 ;
int V_23 ;
V_23 = F_19 ( V_20 , & V_6 , & V_3 , & V_21 ) ;
if ( V_23 )
return - V_31 ;
switch ( type & V_32 ) {
case V_33 :
V_29 |= V_21 ;
case V_34 :
V_27 |= V_21 ;
case V_35 :
V_30 = V_36 ;
break;
case V_37 :
V_27 |= V_21 ;
case V_38 :
V_28 |= V_21 ;
V_30 = V_39 ;
break;
default:
return - V_31 ;
}
F_14 ( & V_6 -> V_17 , V_16 ) ;
V_15 = F_6 ( V_6 , V_3 , V_40 ) ;
V_7 = F_9 ( V_15 ) ;
V_7 = ( V_7 & ~ V_21 ) | V_27 ;
F_12 ( V_7 , V_15 ) ;
V_15 = F_6 ( V_6 , V_3 , V_41 ) ;
V_7 = F_9 ( V_15 ) ;
V_7 = ( V_7 & ~ V_21 ) | V_28 ;
F_12 ( V_7 , V_15 ) ;
V_15 = F_6 ( V_6 , V_3 , V_42 ) ;
V_7 = F_9 ( V_15 ) ;
V_7 = ( V_7 & ~ V_21 ) | V_29 ;
F_12 ( V_7 , V_15 ) ;
F_15 ( & V_6 -> V_17 , V_16 ) ;
F_27 ( V_20 , V_30 ) ;
return 0 ;
}
static void F_28 ( struct V_43 * V_44 )
{
struct V_11 * V_12 = F_29 ( V_44 ) ;
struct V_45 * V_46 = F_30 ( V_44 ) ;
struct V_5 * V_47 = F_8 ( V_12 ) ;
unsigned int V_48 , V_49 , V_50 ;
unsigned long V_7 ;
F_31 ( V_46 , V_44 ) ;
for ( V_48 = 0 ; V_48 < F_4 ( V_4 ) ; V_48 ++ ) {
const struct V_1 * V_3 = & V_4 [ V_48 ] ;
V_7 = F_9 ( F_6 ( V_47 , V_3 , V_24 ) ) ;
F_32 (p, &reg, 32 ) {
V_50 = F_33 ( V_12 -> V_51 , V_48 * 32 + V_49 ) ;
F_34 ( V_50 ) ;
}
}
F_35 ( V_46 , V_44 ) ;
}
static int F_36 ( struct V_5 * V_6 ,
struct V_52 * V_53 )
{
int V_23 ;
V_23 = F_37 ( V_53 , 0 ) ;
if ( V_23 < 0 )
return V_23 ;
V_6 -> V_54 = V_23 ;
V_23 = F_38 ( & V_6 -> V_55 , & V_56 ,
0 , V_57 , V_58 ) ;
if ( V_23 ) {
F_39 ( & V_53 -> V_59 , L_1 ) ;
return V_23 ;
}
F_40 ( & V_6 -> V_55 , & V_56 ,
V_6 -> V_54 , F_28 ) ;
return 0 ;
}
static int F_41 ( struct V_11 * V_55 , unsigned int V_2 )
{
return F_42 ( V_55 -> V_8 + V_2 ) ;
}
static void F_43 ( struct V_11 * V_55 , unsigned int V_2 )
{
F_44 ( V_55 -> V_8 + V_2 ) ;
}
static int T_4 F_45 ( struct V_52 * V_53 )
{
struct V_5 * V_6 ;
struct V_60 * V_61 ;
int V_23 ;
V_6 = F_46 ( & V_53 -> V_59 , sizeof( * V_6 ) , V_62 ) ;
if ( ! V_6 )
return - V_63 ;
V_61 = F_47 ( V_53 , V_64 , 0 ) ;
V_6 -> V_8 = F_48 ( & V_53 -> V_59 , V_61 ) ;
if ( F_49 ( V_6 -> V_8 ) )
return F_50 ( V_6 -> V_8 ) ;
F_51 ( & V_6 -> V_17 ) ;
V_6 -> V_55 . V_65 = F_4 ( V_4 ) * 32 ;
V_6 -> V_55 . V_66 = & V_53 -> V_59 ;
V_6 -> V_55 . V_67 = F_16 ;
V_6 -> V_55 . V_68 = F_17 ;
V_6 -> V_55 . V_69 = F_18 ;
V_6 -> V_55 . V_70 = F_41 ;
V_6 -> V_55 . free = F_43 ;
V_6 -> V_55 . V_71 = F_7 ;
V_6 -> V_55 . V_25 = F_13 ;
V_6 -> V_55 . V_72 = F_52 ( & V_53 -> V_59 ) ;
V_6 -> V_55 . V_8 = - 1 ;
V_23 = F_53 ( & V_53 -> V_59 , & V_6 -> V_55 , V_6 ) ;
if ( V_23 < 0 )
return V_23 ;
return F_36 ( V_6 , V_53 ) ;
}
