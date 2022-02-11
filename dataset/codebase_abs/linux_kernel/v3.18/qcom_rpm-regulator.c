static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const int V_5 )
{
if ( F_2 ( ( V_5 << V_4 -> V_6 ) & ~ V_4 -> V_7 ) )
return - V_8 ;
V_2 -> V_9 [ V_4 -> V_10 ] &= ~ V_4 -> V_7 ;
V_2 -> V_9 [ V_4 -> V_10 ] |= V_5 << V_4 -> V_6 ;
return F_3 ( V_2 -> V_11 ,
V_2 -> V_12 ,
V_2 -> V_9 ,
V_2 -> V_13 -> V_14 ) ;
}
static int F_4 ( struct V_15 * V_16 ,
unsigned V_17 )
{
struct V_1 * V_2 = F_5 ( V_16 ) ;
const struct V_18 * V_13 = V_2 -> V_13 ;
const struct V_3 * V_4 = & V_13 -> V_19 ;
int V_20 = 0 ;
int V_21 ;
if ( V_4 -> V_7 == 0 )
return - V_8 ;
V_21 = F_6 ( V_16 , V_17 ) ;
if ( V_21 < 0 )
return V_21 ;
F_7 ( & V_2 -> V_22 ) ;
V_2 -> V_21 = V_21 ;
if ( V_2 -> V_23 )
V_20 = F_1 ( V_2 , V_4 , V_2 -> V_21 / 1000 ) ;
F_8 ( & V_2 -> V_22 ) ;
return V_20 ;
}
static int F_9 ( struct V_15 * V_16 ,
unsigned V_17 )
{
struct V_1 * V_2 = F_5 ( V_16 ) ;
const struct V_18 * V_13 = V_2 -> V_13 ;
const struct V_3 * V_4 = & V_13 -> V_21 ;
int V_20 = 0 ;
int V_21 ;
if ( V_4 -> V_7 == 0 )
return - V_8 ;
V_21 = F_6 ( V_16 , V_17 ) ;
if ( V_21 < 0 )
return V_21 ;
F_7 ( & V_2 -> V_22 ) ;
V_2 -> V_21 = V_21 ;
if ( V_2 -> V_23 )
V_20 = F_1 ( V_2 , V_4 , V_2 -> V_21 ) ;
F_8 ( & V_2 -> V_22 ) ;
return V_20 ;
}
static int F_10 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_5 ( V_16 ) ;
return V_2 -> V_21 ;
}
static int F_11 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_5 ( V_16 ) ;
const struct V_18 * V_13 = V_2 -> V_13 ;
const struct V_3 * V_4 = & V_13 -> V_19 ;
int V_20 ;
if ( V_4 -> V_7 == 0 )
return - V_8 ;
F_7 ( & V_2 -> V_22 ) ;
V_20 = F_1 ( V_2 , V_4 , V_2 -> V_21 / 1000 ) ;
if ( ! V_20 )
V_2 -> V_23 = 1 ;
F_8 ( & V_2 -> V_22 ) ;
return V_20 ;
}
static int F_12 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_5 ( V_16 ) ;
const struct V_18 * V_13 = V_2 -> V_13 ;
const struct V_3 * V_4 = & V_13 -> V_21 ;
int V_20 ;
if ( V_4 -> V_7 == 0 )
return - V_8 ;
F_7 ( & V_2 -> V_22 ) ;
V_20 = F_1 ( V_2 , V_4 , V_2 -> V_21 ) ;
if ( ! V_20 )
V_2 -> V_23 = 1 ;
F_8 ( & V_2 -> V_22 ) ;
return V_20 ;
}
static int F_13 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_5 ( V_16 ) ;
const struct V_18 * V_13 = V_2 -> V_13 ;
const struct V_3 * V_4 = & V_13 -> V_24 ;
int V_20 ;
if ( V_4 -> V_7 == 0 )
return - V_8 ;
F_7 ( & V_2 -> V_22 ) ;
V_20 = F_1 ( V_2 , V_4 , 1 ) ;
if ( ! V_20 )
V_2 -> V_23 = 1 ;
F_8 ( & V_2 -> V_22 ) ;
return V_20 ;
}
static int F_14 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_5 ( V_16 ) ;
const struct V_18 * V_13 = V_2 -> V_13 ;
const struct V_3 * V_4 = & V_13 -> V_19 ;
int V_20 ;
if ( V_4 -> V_7 == 0 )
return - V_8 ;
F_7 ( & V_2 -> V_22 ) ;
V_20 = F_1 ( V_2 , V_4 , 0 ) ;
if ( ! V_20 )
V_2 -> V_23 = 0 ;
F_8 ( & V_2 -> V_22 ) ;
return V_20 ;
}
static int F_15 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_5 ( V_16 ) ;
const struct V_18 * V_13 = V_2 -> V_13 ;
const struct V_3 * V_4 = & V_13 -> V_21 ;
int V_20 ;
if ( V_4 -> V_7 == 0 )
return - V_8 ;
F_7 ( & V_2 -> V_22 ) ;
V_20 = F_1 ( V_2 , V_4 , 0 ) ;
if ( ! V_20 )
V_2 -> V_23 = 0 ;
F_8 ( & V_2 -> V_22 ) ;
return V_20 ;
}
static int F_16 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_5 ( V_16 ) ;
const struct V_18 * V_13 = V_2 -> V_13 ;
const struct V_3 * V_4 = & V_13 -> V_24 ;
int V_20 ;
if ( V_4 -> V_7 == 0 )
return - V_8 ;
F_7 ( & V_2 -> V_22 ) ;
V_20 = F_1 ( V_2 , V_4 , 0 ) ;
if ( ! V_20 )
V_2 -> V_23 = 0 ;
F_8 ( & V_2 -> V_22 ) ;
return V_20 ;
}
static int F_17 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_5 ( V_16 ) ;
return V_2 -> V_23 ;
}
static int F_18 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const int V_5 )
{
if ( V_4 -> V_7 == 0 || ( V_5 << V_4 -> V_6 ) & ~ V_4 -> V_7 )
return - V_8 ;
V_2 -> V_9 [ V_4 -> V_10 ] &= ~ V_4 -> V_7 ;
V_2 -> V_9 [ V_4 -> V_10 ] |= V_5 << V_4 -> V_6 ;
return 0 ;
}
static int F_19 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
static const int V_27 [] = {
19200000 , 9600000 , 6400000 , 4800000 , 3840000 , 3200000 , 2740000 ,
2400000 , 2130000 , 1920000 , 1750000 , 1600000 , 1480000 , 1370000 ,
1280000 , 1200000 ,
} ;
const char * V_28 ;
T_1 V_29 ;
int V_20 ;
int V_30 ;
V_28 = L_1 ;
V_20 = F_20 ( V_26 -> V_31 , V_28 , & V_29 ) ;
if ( V_20 ) {
F_21 ( V_26 , L_2 , V_28 ) ;
return - V_8 ;
}
for ( V_30 = 0 ; V_30 < F_22 ( V_27 ) ; V_30 ++ ) {
if ( V_29 == V_27 [ V_30 ] ) {
F_18 ( V_2 , & V_2 -> V_13 -> V_29 , V_30 + 1 ) ;
return 0 ;
}
}
F_21 ( V_26 , L_3 , V_29 ) ;
return - V_8 ;
}
static int F_23 ( struct V_32 * V_33 )
{
struct V_34 * V_35 ;
const struct V_1 * V_36 ;
const struct V_37 * V_38 ;
struct V_39 V_40 = { } ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
const char * V_28 ;
T_1 V_41 ;
bool V_42 ;
T_1 V_9 ;
int V_20 ;
V_38 = F_24 ( V_43 , & V_33 -> V_26 ) ;
V_36 = V_38 -> V_44 ;
V_35 = F_25 ( & V_33 -> V_26 , V_33 -> V_26 . V_31 ) ;
if ( ! V_35 )
return - V_8 ;
V_2 = F_26 ( & V_33 -> V_26 , sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 ) {
F_21 ( & V_33 -> V_26 , L_4 ) ;
return - V_46 ;
}
memcpy ( V_2 , V_36 , sizeof( * V_2 ) ) ;
F_27 ( & V_2 -> V_22 ) ;
V_2 -> V_26 = & V_33 -> V_26 ;
V_2 -> V_47 . V_48 = - 1 ;
V_2 -> V_47 . V_49 = V_50 ;
V_2 -> V_47 . type = V_51 ;
V_2 -> V_47 . V_52 = V_33 -> V_26 . V_31 -> V_52 ;
V_2 -> V_11 = F_28 ( V_33 -> V_26 . V_53 ) ;
if ( ! V_2 -> V_11 ) {
F_21 ( & V_33 -> V_26 , L_5 ) ;
return - V_54 ;
}
V_28 = L_6 ;
V_20 = F_20 ( V_33 -> V_26 . V_31 , V_28 , & V_9 ) ;
if ( V_20 ) {
F_21 ( & V_33 -> V_26 , L_7 , V_28 ) ;
return V_20 ;
}
V_2 -> V_12 = V_9 ;
if ( ( V_2 -> V_13 -> V_21 . V_7 || V_2 -> V_13 -> V_19 . V_7 ) &&
( ! V_35 -> V_55 . V_56 || ! V_35 -> V_55 . V_57 ) ) {
F_21 ( & V_33 -> V_26 , L_8 ) ;
return - V_8 ;
}
V_28 = L_9 ;
if ( F_29 ( V_33 -> V_26 . V_31 , V_28 ) ) {
V_20 = F_18 ( V_2 , & V_2 -> V_13 -> V_58 , 1 ) ;
if ( V_20 ) {
F_21 ( & V_33 -> V_26 , L_10 , V_28 ) ;
return V_20 ;
}
}
if ( V_2 -> V_13 -> V_29 . V_7 ) {
V_20 = F_19 ( & V_33 -> V_26 , V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
}
if ( V_2 -> V_13 -> V_59 . V_7 ) {
V_28 = L_11 ;
V_42 = ! F_29 ( V_33 -> V_26 . V_31 , V_28 ) ;
V_20 = F_18 ( V_2 , & V_2 -> V_13 -> V_59 , V_42 ) ;
if ( V_20 ) {
F_21 ( & V_33 -> V_26 , L_12 ) ;
return V_20 ;
}
}
if ( V_2 -> V_13 -> V_60 . V_7 ) {
V_41 = - 1 ;
V_28 = L_13 ;
V_20 = F_20 ( V_33 -> V_26 . V_31 , V_28 , & V_9 ) ;
if ( V_20 == - V_8 ) {
V_9 = V_61 ;
} else if ( V_20 < 0 ) {
F_21 ( & V_33 -> V_26 , L_7 , V_28 ) ;
return V_20 ;
}
switch ( V_9 ) {
case V_61 :
V_41 = 0 ;
break;
case V_62 :
V_41 = 1 ;
break;
case V_63 :
if ( F_30 ( V_2 ) )
V_41 = 2 ;
else
V_41 = 3 ;
break;
case V_64 :
if ( V_2 -> V_65 )
V_41 = 2 ;
break;
case V_66 :
if ( V_2 -> V_67 )
V_41 = 4 ;
break;
}
if ( V_41 < 0 ) {
F_21 ( & V_33 -> V_26 , L_14 ) ;
return - V_8 ;
}
V_20 = F_18 ( V_2 , & V_2 -> V_13 -> V_60 , V_41 ) ;
if ( V_20 ) {
F_21 ( & V_33 -> V_26 , L_15 ) ;
return V_20 ;
}
}
V_40 . V_26 = & V_33 -> V_26 ;
V_40 . V_68 = V_35 ;
V_40 . V_69 = V_2 ;
V_40 . V_31 = V_33 -> V_26 . V_31 ;
V_16 = F_31 ( & V_33 -> V_26 , & V_2 -> V_47 , & V_40 ) ;
if ( F_32 ( V_16 ) ) {
F_21 ( & V_33 -> V_26 , L_16 ) ;
return F_33 ( V_16 ) ;
}
return 0 ;
}
static int T_2 F_34 ( void )
{
return F_35 ( & V_70 ) ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_70 ) ;
}
