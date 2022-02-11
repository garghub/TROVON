static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const int V_5 )
{
if ( F_2 ( ( V_5 << V_4 -> V_6 ) & ~ V_4 -> V_7 ) )
return - V_8 ;
V_2 -> V_9 [ V_4 -> V_10 ] &= ~ V_4 -> V_7 ;
V_2 -> V_9 [ V_4 -> V_10 ] |= V_5 << V_4 -> V_6 ;
return F_3 ( V_2 -> V_11 ,
V_12 ,
V_2 -> V_13 ,
V_2 -> V_9 ,
V_2 -> V_14 -> V_15 ) ;
}
static int F_4 ( struct V_16 * V_17 ,
unsigned V_18 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
const struct V_19 * V_14 = V_2 -> V_14 ;
const struct V_3 * V_4 = & V_14 -> V_20 ;
int V_21 = 0 ;
int V_22 ;
if ( V_4 -> V_7 == 0 )
return - V_8 ;
V_22 = F_6 ( V_17 , V_18 ) ;
if ( V_22 < 0 )
return V_22 ;
F_7 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_24 )
V_21 = F_1 ( V_2 , V_4 , V_22 / 1000 ) ;
if ( ! V_21 )
V_2 -> V_22 = V_22 ;
F_8 ( & V_2 -> V_23 ) ;
return V_21 ;
}
static int F_9 ( struct V_16 * V_17 ,
unsigned V_18 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
const struct V_19 * V_14 = V_2 -> V_14 ;
const struct V_3 * V_4 = & V_14 -> V_22 ;
int V_21 = 0 ;
int V_22 ;
if ( V_4 -> V_7 == 0 )
return - V_8 ;
V_22 = F_6 ( V_17 , V_18 ) ;
if ( V_22 < 0 )
return V_22 ;
F_7 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_24 )
V_21 = F_1 ( V_2 , V_4 , V_22 ) ;
if ( ! V_21 )
V_2 -> V_22 = V_22 ;
F_8 ( & V_2 -> V_23 ) ;
return V_21 ;
}
static int F_10 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
return V_2 -> V_22 ;
}
static int F_11 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
const struct V_19 * V_14 = V_2 -> V_14 ;
const struct V_3 * V_4 = & V_14 -> V_20 ;
int V_21 ;
if ( V_4 -> V_7 == 0 )
return - V_8 ;
F_7 ( & V_2 -> V_23 ) ;
V_21 = F_1 ( V_2 , V_4 , V_2 -> V_22 / 1000 ) ;
if ( ! V_21 )
V_2 -> V_24 = 1 ;
F_8 ( & V_2 -> V_23 ) ;
return V_21 ;
}
static int F_12 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
const struct V_19 * V_14 = V_2 -> V_14 ;
const struct V_3 * V_4 = & V_14 -> V_22 ;
int V_21 ;
if ( V_4 -> V_7 == 0 )
return - V_8 ;
F_7 ( & V_2 -> V_23 ) ;
V_21 = F_1 ( V_2 , V_4 , V_2 -> V_22 ) ;
if ( ! V_21 )
V_2 -> V_24 = 1 ;
F_8 ( & V_2 -> V_23 ) ;
return V_21 ;
}
static int F_13 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
const struct V_19 * V_14 = V_2 -> V_14 ;
const struct V_3 * V_4 = & V_14 -> V_25 ;
int V_21 ;
if ( V_4 -> V_7 == 0 )
return - V_8 ;
F_7 ( & V_2 -> V_23 ) ;
V_21 = F_1 ( V_2 , V_4 , 1 ) ;
if ( ! V_21 )
V_2 -> V_24 = 1 ;
F_8 ( & V_2 -> V_23 ) ;
return V_21 ;
}
static int F_14 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
const struct V_19 * V_14 = V_2 -> V_14 ;
const struct V_3 * V_4 = & V_14 -> V_20 ;
int V_21 ;
if ( V_4 -> V_7 == 0 )
return - V_8 ;
F_7 ( & V_2 -> V_23 ) ;
V_21 = F_1 ( V_2 , V_4 , 0 ) ;
if ( ! V_21 )
V_2 -> V_24 = 0 ;
F_8 ( & V_2 -> V_23 ) ;
return V_21 ;
}
static int F_15 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
const struct V_19 * V_14 = V_2 -> V_14 ;
const struct V_3 * V_4 = & V_14 -> V_22 ;
int V_21 ;
if ( V_4 -> V_7 == 0 )
return - V_8 ;
F_7 ( & V_2 -> V_23 ) ;
V_21 = F_1 ( V_2 , V_4 , 0 ) ;
if ( ! V_21 )
V_2 -> V_24 = 0 ;
F_8 ( & V_2 -> V_23 ) ;
return V_21 ;
}
static int F_16 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
const struct V_19 * V_14 = V_2 -> V_14 ;
const struct V_3 * V_4 = & V_14 -> V_25 ;
int V_21 ;
if ( V_4 -> V_7 == 0 )
return - V_8 ;
F_7 ( & V_2 -> V_23 ) ;
V_21 = F_1 ( V_2 , V_4 , 0 ) ;
if ( ! V_21 )
V_2 -> V_24 = 0 ;
F_8 ( & V_2 -> V_23 ) ;
return V_21 ;
}
static int F_17 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
return V_2 -> V_24 ;
}
static int F_18 ( struct V_16 * V_17 , int V_26 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
const struct V_19 * V_14 = V_2 -> V_14 ;
const struct V_3 * V_4 = & V_14 -> V_27 ;
int V_28 = V_26 / 1000 ;
int V_29 = V_4 -> V_7 >> V_4 -> V_6 ;
int V_21 ;
if ( V_4 -> V_7 == 0 )
return - V_8 ;
if ( V_28 > V_29 )
V_28 = V_29 ;
F_7 ( & V_2 -> V_23 ) ;
V_21 = F_1 ( V_2 , V_4 , V_28 ) ;
F_8 ( & V_2 -> V_23 ) ;
return V_21 ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const int V_5 )
{
if ( V_4 -> V_7 == 0 || ( V_5 << V_4 -> V_6 ) & ~ V_4 -> V_7 )
return - V_8 ;
V_2 -> V_9 [ V_4 -> V_10 ] &= ~ V_4 -> V_7 ;
V_2 -> V_9 [ V_4 -> V_10 ] |= V_5 << V_4 -> V_6 ;
return 0 ;
}
static int F_20 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
struct V_1 * V_2 )
{
static const int V_34 [] = {
19200000 , 9600000 , 6400000 , 4800000 , 3840000 , 3200000 , 2740000 ,
2400000 , 2130000 , 1920000 , 1750000 , 1600000 , 1480000 , 1370000 ,
1280000 , 1200000 ,
} ;
const char * V_35 ;
T_1 V_36 ;
int V_21 ;
int V_37 ;
V_35 = L_1 ;
V_21 = F_21 ( V_33 , V_35 , & V_36 ) ;
if ( V_21 ) {
F_22 ( V_31 , L_2 , V_35 ) ;
return - V_8 ;
}
for ( V_37 = 0 ; V_37 < F_23 ( V_34 ) ; V_37 ++ ) {
if ( V_36 == V_34 [ V_37 ] ) {
F_19 ( V_2 , & V_2 -> V_14 -> V_36 , V_37 + 1 ) ;
return 0 ;
}
}
F_22 ( V_31 , L_3 , V_36 ) ;
return - V_8 ;
}
static int F_24 ( struct V_32 * V_33 ,
const struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_30 * V_31 = V_41 -> V_31 ;
const char * V_35 ;
T_1 V_43 ;
bool V_44 ;
T_1 V_9 ;
int V_21 ;
V_35 = L_4 ;
if ( F_25 ( V_33 , V_35 ) ) {
V_21 = F_19 ( V_2 , & V_2 -> V_14 -> V_45 , 1 ) ;
if ( V_21 ) {
F_22 ( V_31 , L_5 , V_35 ) ;
return V_21 ;
}
}
if ( V_2 -> V_14 -> V_36 . V_7 ) {
V_21 = F_20 ( V_31 , V_33 , V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
}
if ( V_2 -> V_14 -> V_46 . V_7 ) {
V_35 = L_6 ;
V_44 = ! F_25 ( V_33 , V_35 ) ;
V_21 = F_19 ( V_2 , & V_2 -> V_14 -> V_46 , V_44 ) ;
if ( V_21 ) {
F_22 ( V_31 , L_7 ) ;
return V_21 ;
}
}
if ( V_2 -> V_14 -> V_47 . V_7 ) {
V_43 = - 1 ;
V_35 = L_8 ;
V_21 = F_21 ( V_33 , V_35 , & V_9 ) ;
if ( V_21 == - V_8 ) {
V_9 = V_48 ;
} else if ( V_21 < 0 ) {
F_22 ( V_31 , L_9 , V_35 ) ;
return V_21 ;
}
switch ( V_9 ) {
case V_48 :
V_43 = 0 ;
break;
case V_49 :
V_43 = 1 ;
break;
case V_50 :
if ( F_26 ( V_2 ) )
V_43 = 2 ;
else
V_43 = 3 ;
break;
case V_51 :
if ( V_2 -> V_52 )
V_43 = 2 ;
break;
case V_53 :
if ( V_2 -> V_54 )
V_43 = 4 ;
break;
}
if ( V_43 == - 1 ) {
F_22 ( V_31 , L_10 ) ;
return - V_8 ;
}
V_21 = F_19 ( V_2 , & V_2 -> V_14 -> V_47 , V_43 ) ;
if ( V_21 ) {
F_22 ( V_31 , L_11 ) ;
return V_21 ;
}
}
return 0 ;
}
static int F_27 ( struct V_55 * V_56 )
{
const struct V_57 * V_58 ;
const struct V_59 * V_60 ;
struct V_40 V_41 = { } ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
struct V_61 * V_11 ;
V_11 = F_28 ( V_56 -> V_31 . V_62 ) ;
if ( ! V_11 ) {
F_22 ( & V_56 -> V_31 , L_12 ) ;
return - V_63 ;
}
V_60 = F_29 ( V_64 , & V_56 -> V_31 ) ;
if ( ! V_60 ) {
F_22 ( & V_56 -> V_31 , L_13 ) ;
return - V_63 ;
}
for ( V_58 = V_60 -> V_65 ; V_58 -> V_66 ; V_58 ++ ) {
V_2 = F_30 ( & V_56 -> V_31 , sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 )
return - V_68 ;
memcpy ( V_2 , V_58 -> V_69 , sizeof( * V_2 ) ) ;
F_31 ( & V_2 -> V_23 ) ;
V_2 -> V_31 = & V_56 -> V_31 ;
V_2 -> V_13 = V_58 -> V_13 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_39 . V_70 = - 1 ;
V_2 -> V_39 . V_71 = V_72 ;
V_2 -> V_39 . type = V_73 ;
V_2 -> V_39 . V_66 = V_58 -> V_66 ;
V_2 -> V_39 . V_74 = V_58 -> V_75 ;
V_2 -> V_39 . V_76 = V_58 -> V_66 ;
V_2 -> V_39 . V_77 = F_24 ;
V_41 . V_31 = & V_56 -> V_31 ;
V_41 . V_42 = V_2 ;
V_17 = F_32 ( & V_56 -> V_31 , & V_2 -> V_39 , & V_41 ) ;
if ( F_33 ( V_17 ) ) {
F_22 ( & V_56 -> V_31 , L_14 , V_58 -> V_66 ) ;
return F_34 ( V_17 ) ;
}
}
return 0 ;
}
static int T_2 F_35 ( void )
{
return F_36 ( & V_78 ) ;
}
static void T_3 F_37 ( void )
{
F_38 ( & V_78 ) ;
}
