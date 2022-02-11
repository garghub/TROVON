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
static int F_19 ( struct V_26 * V_27 , struct V_1 * V_2 )
{
static const int V_28 [] = {
19200000 , 9600000 , 6400000 , 4800000 , 3840000 , 3200000 , 2740000 ,
2400000 , 2130000 , 1920000 , 1750000 , 1600000 , 1480000 , 1370000 ,
1280000 , 1200000 ,
} ;
const char * V_29 ;
T_1 V_30 ;
int V_21 ;
int V_31 ;
V_29 = L_1 ;
V_21 = F_20 ( V_27 -> V_32 , V_29 , & V_30 ) ;
if ( V_21 ) {
F_21 ( V_27 , L_2 , V_29 ) ;
return - V_8 ;
}
for ( V_31 = 0 ; V_31 < F_22 ( V_28 ) ; V_31 ++ ) {
if ( V_30 == V_28 [ V_31 ] ) {
F_18 ( V_2 , & V_2 -> V_14 -> V_30 , V_31 + 1 ) ;
return 0 ;
}
}
F_21 ( V_27 , L_3 , V_30 ) ;
return - V_8 ;
}
static int F_23 ( struct V_33 * V_34 )
{
struct V_35 * V_36 ;
const struct V_1 * V_37 ;
const struct V_38 * V_39 ;
struct V_40 V_41 = { } ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
const char * V_29 ;
T_1 V_42 ;
bool V_43 ;
T_1 V_9 ;
int V_21 ;
V_39 = F_24 ( V_44 , & V_34 -> V_27 ) ;
V_37 = V_39 -> V_45 ;
V_2 = F_25 ( & V_34 -> V_27 , sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 ) {
F_21 ( & V_34 -> V_27 , L_4 ) ;
return - V_47 ;
}
memcpy ( V_2 , V_37 , sizeof( * V_2 ) ) ;
F_26 ( & V_2 -> V_23 ) ;
V_2 -> V_27 = & V_34 -> V_27 ;
V_2 -> V_48 . V_49 = - 1 ;
V_2 -> V_48 . V_50 = V_51 ;
V_2 -> V_48 . type = V_52 ;
V_2 -> V_48 . V_53 = V_34 -> V_27 . V_32 -> V_53 ;
V_2 -> V_48 . V_54 = L_5 ;
V_2 -> V_11 = F_27 ( V_34 -> V_27 . V_55 ) ;
if ( ! V_2 -> V_11 ) {
F_21 ( & V_34 -> V_27 , L_6 ) ;
return - V_56 ;
}
V_36 = F_28 ( & V_34 -> V_27 , V_34 -> V_27 . V_32 ,
& V_2 -> V_48 ) ;
if ( ! V_36 )
return - V_8 ;
V_29 = L_7 ;
V_21 = F_20 ( V_34 -> V_27 . V_32 , V_29 , & V_9 ) ;
if ( V_21 ) {
F_21 ( & V_34 -> V_27 , L_8 , V_29 ) ;
return V_21 ;
}
V_2 -> V_13 = V_9 ;
if ( ( V_2 -> V_14 -> V_22 . V_7 || V_2 -> V_14 -> V_20 . V_7 ) &&
( ! V_36 -> V_57 . V_58 || ! V_36 -> V_57 . V_59 ) ) {
F_21 ( & V_34 -> V_27 , L_9 ) ;
return - V_8 ;
}
V_29 = L_10 ;
if ( F_29 ( V_34 -> V_27 . V_32 , V_29 ) ) {
V_21 = F_18 ( V_2 , & V_2 -> V_14 -> V_60 , 1 ) ;
if ( V_21 ) {
F_21 ( & V_34 -> V_27 , L_11 , V_29 ) ;
return V_21 ;
}
}
if ( V_2 -> V_14 -> V_30 . V_7 ) {
V_21 = F_19 ( & V_34 -> V_27 , V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
}
if ( V_2 -> V_14 -> V_61 . V_7 ) {
V_29 = L_12 ;
V_43 = ! F_29 ( V_34 -> V_27 . V_32 , V_29 ) ;
V_21 = F_18 ( V_2 , & V_2 -> V_14 -> V_61 , V_43 ) ;
if ( V_21 ) {
F_21 ( & V_34 -> V_27 , L_13 ) ;
return V_21 ;
}
}
if ( V_2 -> V_14 -> V_62 . V_7 ) {
V_42 = - 1 ;
V_29 = L_14 ;
V_21 = F_20 ( V_34 -> V_27 . V_32 , V_29 , & V_9 ) ;
if ( V_21 == - V_8 ) {
V_9 = V_63 ;
} else if ( V_21 < 0 ) {
F_21 ( & V_34 -> V_27 , L_8 , V_29 ) ;
return V_21 ;
}
switch ( V_9 ) {
case V_63 :
V_42 = 0 ;
break;
case V_64 :
V_42 = 1 ;
break;
case V_65 :
if ( F_30 ( V_2 ) )
V_42 = 2 ;
else
V_42 = 3 ;
break;
case V_66 :
if ( V_2 -> V_67 )
V_42 = 2 ;
break;
case V_68 :
if ( V_2 -> V_69 )
V_42 = 4 ;
break;
}
if ( V_42 == - 1 ) {
F_21 ( & V_34 -> V_27 , L_15 ) ;
return - V_8 ;
}
V_21 = F_18 ( V_2 , & V_2 -> V_14 -> V_62 , V_42 ) ;
if ( V_21 ) {
F_21 ( & V_34 -> V_27 , L_16 ) ;
return V_21 ;
}
}
V_41 . V_27 = & V_34 -> V_27 ;
V_41 . V_70 = V_36 ;
V_41 . V_71 = V_2 ;
V_41 . V_32 = V_34 -> V_27 . V_32 ;
V_17 = F_31 ( & V_34 -> V_27 , & V_2 -> V_48 , & V_41 ) ;
if ( F_32 ( V_17 ) ) {
F_21 ( & V_34 -> V_27 , L_17 ) ;
return F_33 ( V_17 ) ;
}
return 0 ;
}
static int T_2 F_34 ( void )
{
return F_35 ( & V_72 ) ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_72 ) ;
}
