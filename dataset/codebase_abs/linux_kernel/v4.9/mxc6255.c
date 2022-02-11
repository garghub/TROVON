static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned int V_10 ;
int V_11 ;
switch ( V_7 ) {
case V_12 :
V_11 = F_3 ( V_9 -> V_13 , V_4 -> V_14 , & V_10 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_9 -> V_15 -> V_16 ,
L_1 , V_4 -> V_14 ) ;
return V_11 ;
}
* V_5 = F_5 ( V_10 , 7 ) ;
return V_17 ;
case V_18 :
* V_5 = 0 ;
* V_6 = V_19 ;
return V_20 ;
default:
return - V_21 ;
}
}
static bool F_6 ( struct V_22 * V_16 , unsigned int V_10 )
{
switch ( V_10 ) {
case V_23 :
case V_24 :
case V_25 :
return true ;
default:
return false ;
}
}
static int F_7 ( struct V_26 * V_15 ,
const struct V_27 * V_28 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_13 * V_13 ;
unsigned int V_29 ;
int V_11 ;
V_2 = F_8 ( & V_15 -> V_16 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_30 ;
V_13 = F_9 ( V_15 , & V_31 ) ;
if ( F_10 ( V_13 ) ) {
F_4 ( & V_15 -> V_16 , L_2 ) ;
return F_11 ( V_13 ) ;
}
V_9 = F_2 ( V_2 ) ;
F_12 ( V_15 , V_2 ) ;
V_9 -> V_15 = V_15 ;
V_9 -> V_13 = V_13 ;
V_2 -> V_32 = V_33 ;
V_2 -> V_16 . V_34 = & V_15 -> V_16 ;
V_2 -> V_35 = V_36 ;
V_2 -> V_37 = F_13 ( V_36 ) ;
V_2 -> V_38 = V_39 ;
V_2 -> V_40 = & V_41 ;
V_11 = F_3 ( V_9 -> V_13 , V_25 , & V_29 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_15 -> V_16 , L_3 , V_11 ) ;
return V_11 ;
}
if ( ( V_29 & 0x1f ) != V_42 ) {
F_4 ( & V_15 -> V_16 , L_4 , V_29 ) ;
return - V_43 ;
}
F_14 ( & V_15 -> V_16 , L_5 , V_29 ) ;
V_11 = F_15 ( & V_15 -> V_16 , V_2 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_15 -> V_16 , L_6 ) ;
return V_11 ;
}
return 0 ;
}
