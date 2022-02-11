static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 ;
switch ( V_7 ) {
case V_11 :
V_10 = F_3 ( V_9 -> V_12 ,
V_4 -> V_13 ) ;
if ( V_10 < 0 ) {
F_4 ( & V_9 -> V_12 -> V_14 ,
L_1 , V_10 ) ;
return V_10 ;
}
* V_5 = F_5 ( V_10 , V_15 ) ;
if ( V_9 -> V_16 == V_17 )
* V_5 = * V_5 >> 1 ;
switch ( V_4 -> type ) {
case V_18 :
return V_19 ;
case V_20 :
if ( V_9 -> V_16 != V_17 )
* V_5 = * V_5 / 2 ;
return V_19 ;
default:
return - V_21 ;
}
case V_22 :
switch ( V_4 -> type ) {
case V_20 :
* V_5 = V_23 ;
return V_19 ;
default:
return - V_21 ;
}
case V_24 :
switch ( V_4 -> type ) {
case V_18 :
* V_5 = 0 ;
if ( V_9 -> V_16 == V_17 )
* V_6 = V_25 ;
else
* V_6 = V_26 ;
return V_27 ;
default:
return - V_21 ;
}
default:
return - V_21 ;
}
}
static int F_6 ( struct V_28 * V_12 ,
const struct V_29 * V_30 )
{
int V_10 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
if ( ! F_7 ( V_12 -> V_31 , V_32 ) ) {
F_4 ( & V_12 -> V_14 , L_2 ) ;
return - V_33 ;
}
V_2 = F_8 ( & V_12 -> V_14 , sizeof( * V_9 ) ) ;
if ( ! V_2 ) {
F_4 ( & V_12 -> V_14 , L_3 ) ;
return - V_34 ;
}
V_9 = F_2 ( V_2 ) ;
V_9 -> V_12 = V_12 ;
V_10 = F_3 ( V_9 -> V_12 , V_35 ) ;
if ( V_10 < 0 ) {
F_4 ( & V_12 -> V_14 , L_4 , V_10 ) ;
return V_10 ;
}
if ( V_10 != V_36 && V_10 != V_17 &&
V_10 != V_37 ) {
F_4 ( & V_12 -> V_14 , L_5 , V_10 ) ;
return - V_38 ;
}
V_9 -> V_16 = V_10 ;
F_9 ( V_12 , V_2 ) ;
V_2 -> V_14 . V_39 = & V_12 -> V_14 ;
V_2 -> V_40 = V_41 ;
V_2 -> V_42 = V_43 ;
V_2 -> V_44 = V_45 ;
V_2 -> V_46 = F_10 ( V_45 ) ;
V_2 -> V_47 = & V_48 ;
return F_11 ( & V_12 -> V_14 , V_2 ) ;
}
static int F_12 ( struct V_49 * V_14 )
{
struct V_1 * V_2 = F_13 ( F_14 ( V_14 ) ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 ;
V_10 = F_15 ( V_9 -> V_12 , V_50 ,
V_51 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_16 ( struct V_49 * V_14 )
{
struct V_1 * V_2 = F_13 ( F_14 ( V_14 ) ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 ;
V_10 = F_15 ( V_9 -> V_12 , V_50 ,
V_52 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
