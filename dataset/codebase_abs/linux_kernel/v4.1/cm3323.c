static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_3 = F_3 ( V_5 -> V_6 , V_7 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_5 -> V_6 -> V_8 , L_1 ) ;
return V_3 ;
}
V_3 &= ~ ( V_9 | V_10 ) ;
V_3 = F_5 ( V_5 -> V_6 , V_7 , V_3 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_5 -> V_6 -> V_8 , L_2 ) ;
return V_3 ;
}
V_5 -> V_11 = V_3 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_3 = F_5 ( V_5 -> V_6 , V_7 ,
V_9 ) ;
if ( V_3 < 0 )
F_4 ( & V_5 -> V_6 -> V_8 , L_2 ) ;
}
static int F_7 ( struct V_4 * V_5 , int V_12 , int V_13 )
{
int V_14 , V_3 ;
T_1 V_11 ;
for ( V_14 = 0 ; V_14 < F_8 ( V_15 ) ; V_14 ++ ) {
if ( V_12 == V_15 [ V_14 ] . V_12 &&
V_13 == V_15 [ V_14 ] . V_13 ) {
V_11 = V_5 -> V_11 ;
V_11 |= V_14 << V_16 ;
V_3 = F_5 ( V_5 -> V_6 ,
V_7 ,
V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
V_5 -> V_11 = V_11 ;
return 0 ;
}
}
return - V_17 ;
}
static int F_9 ( struct V_4 * V_5 )
{
int V_18 ;
V_18 = ( V_5 -> V_11 & V_19 ) >>
V_16 ;
if ( V_18 >= F_8 ( V_15 ) )
return - V_17 ;
return V_18 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_20 const * V_21 , int * V_12 ,
int * V_13 , long V_22 )
{
int V_14 , V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_22 ) {
case V_23 :
F_11 ( & V_5 -> V_24 ) ;
V_3 = F_3 ( V_5 -> V_6 , V_21 -> V_25 ) ;
if ( V_3 < 0 ) {
F_12 ( & V_5 -> V_24 ) ;
return V_3 ;
}
* V_12 = V_3 ;
F_12 ( & V_5 -> V_24 ) ;
return V_26 ;
case V_27 :
F_11 ( & V_5 -> V_24 ) ;
V_14 = F_9 ( V_5 ) ;
if ( V_14 < 0 ) {
F_12 ( & V_5 -> V_24 ) ;
return - V_17 ;
}
* V_12 = V_15 [ V_14 ] . V_12 ;
* V_13 = V_15 [ V_14 ] . V_13 ;
F_12 ( & V_5 -> V_24 ) ;
return V_28 ;
default:
return - V_17 ;
}
}
static int F_13 ( struct V_1 * V_2 ,
struct V_20 const * V_21 , int V_12 ,
int V_13 , long V_22 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_3 ;
switch ( V_22 ) {
case V_27 :
F_11 ( & V_5 -> V_24 ) ;
V_3 = F_7 ( V_5 , V_12 , V_13 ) ;
F_12 ( & V_5 -> V_24 ) ;
return V_3 ;
default:
return - V_17 ;
}
}
static int F_14 ( struct V_29 * V_6 ,
const struct V_30 * V_31 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
int V_3 ;
V_2 = F_15 ( & V_6 -> V_8 , sizeof( * V_5 ) ) ;
if ( ! V_2 )
return - V_32 ;
V_5 = F_2 ( V_2 ) ;
F_16 ( V_6 , V_2 ) ;
V_5 -> V_6 = V_6 ;
F_17 ( & V_5 -> V_24 ) ;
V_2 -> V_8 . V_33 = & V_6 -> V_8 ;
V_2 -> V_34 = & V_35 ;
V_2 -> V_36 = V_37 ;
V_2 -> V_38 = V_39 ;
V_2 -> V_40 = F_8 ( V_39 ) ;
V_2 -> V_41 = V_42 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_6 -> V_8 , L_3 ) ;
return V_3 ;
}
V_3 = F_18 ( V_2 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_6 -> V_8 , L_4 ) ;
goto V_43;
}
return 0 ;
V_43:
F_6 ( V_2 ) ;
return V_3 ;
}
static int F_19 ( struct V_29 * V_6 )
{
struct V_1 * V_2 = F_20 ( V_6 ) ;
F_21 ( V_2 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
