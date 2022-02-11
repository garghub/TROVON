static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 ,
int * V_6 , long V_7 )
{
int V_8 ;
T_1 V_9 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
switch ( V_7 ) {
case V_12 :
switch ( V_4 -> type ) {
case V_13 :
V_8 = F_3 ( V_11 ,
& V_9 ) ;
if ( V_8 )
return V_8 ;
* V_5 = V_9 ;
return V_14 ;
default:
return - V_15 ;
}
case V_16 :
* V_5 = V_17 [ V_11 -> V_18 ] ;
return V_14 ;
default:
return - V_15 ;
}
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 const * V_19 ,
int V_5 , int V_6 , long V_7 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_20 , V_8 ;
switch ( V_7 ) {
case V_16 :
V_20 = F_5 ( V_17 ) ;
while ( V_20 -- > 0 )
if ( V_5 == V_17 [ V_20 ] )
break;
if ( V_20 < 0 )
return - V_15 ;
F_6 ( & V_11 -> V_21 ) ;
V_11 -> V_18 = V_20 ;
V_8 = F_7 ( V_11 , V_20 ) ;
F_8 ( & V_11 -> V_21 ) ;
return V_8 ;
default:
return - V_15 ;
}
}
static T_2 F_9 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
char * V_26 )
{
struct V_1 * V_2 = F_10 ( V_23 ) ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
return F_11 ( V_11 , V_26 ) ;
}
static int F_12 ( struct V_27 * V_28 ,
const struct V_29 * V_30 )
{
struct V_10 * V_11 ;
struct V_1 * V_2 ;
int V_8 ;
T_3 V_31 ;
if ( ! F_13 ( V_28 -> V_32 ,
V_33 |
V_34 |
V_35 ) ) {
F_14 ( & V_28 -> V_23 ,
L_1 ) ;
return - V_36 ;
}
V_2 = F_15 ( & V_28 -> V_23 , sizeof( * V_11 ) ) ;
if ( ! V_2 )
return - V_37 ;
V_11 = F_2 ( V_2 ) ;
V_11 -> V_28 = V_28 ;
V_11 -> V_18 = 0 ;
F_16 ( & V_11 -> V_21 ) ;
V_2 -> V_38 = & V_39 ;
V_2 -> V_40 = V_30 -> V_40 ;
V_2 -> V_23 . V_41 = & V_28 -> V_23 ;
V_2 -> V_42 = V_43 ;
V_2 -> V_44 = V_45 ;
V_2 -> V_46 = F_5 ( V_45 ) ;
F_17 ( V_28 , V_2 ) ;
V_8 = F_18 ( V_28 , V_47 , 15000 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_19 ( V_28 , & V_31 ) ;
if ( V_8 )
return V_8 ;
F_20 ( & V_28 -> V_23 , L_2 , V_31 ) ;
return F_21 ( & V_28 -> V_23 , V_2 ) ;
}
