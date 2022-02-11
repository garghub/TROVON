static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 ,
int * V_6 , long V_7 )
{
int V_8 ;
int V_9 ;
unsigned int V_10 ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
switch ( V_7 ) {
case V_13 :
V_8 = F_3 ( V_12 ,
& V_9 ,
& V_10 ) ;
if ( V_8 )
return V_8 ;
switch ( V_4 -> type ) {
case V_14 :
* V_5 = V_9 ;
return V_15 ;
case V_16 :
* V_5 = V_10 / 1000 ;
* V_6 = ( V_10 % 1000 ) * 1000 ;
return V_17 ;
default:
return - V_18 ;
}
case V_19 :
* V_5 = V_20 [ V_12 -> V_21 ] ;
return V_15 ;
default:
return - V_18 ;
}
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 const * V_22 ,
int V_5 , int V_6 , long V_7 )
{
struct V_11 * V_12 = F_2 ( V_2 ) ;
int V_23 ;
switch ( V_7 ) {
case V_19 :
V_23 = F_5 ( V_20 ) ;
while ( V_23 -- > 0 )
if ( V_5 == V_20 [ V_23 ] )
break;
if ( V_23 < 0 )
return - V_18 ;
V_12 -> V_21 = V_23 ;
return 0 ;
default:
return - V_18 ;
}
}
static int F_6 ( struct V_24 * V_25 ,
const struct V_26 * V_27 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
int V_8 ;
if ( ! F_7 ( V_25 -> V_28 ,
V_29 |
V_30 |
V_31 ) ) {
F_8 ( & V_25 -> V_32 ,
L_1 ) ;
return - V_33 ;
}
V_2 = F_9 ( & V_25 -> V_32 , sizeof( * V_12 ) ) ;
if ( ! V_2 )
return - V_34 ;
V_12 = F_2 ( V_2 ) ;
V_12 -> V_25 = V_25 ;
V_12 -> V_21 = 5 ;
F_10 ( & V_12 -> V_35 ) ;
V_2 -> V_36 = & V_37 ;
V_2 -> V_38 = V_27 -> V_38 ;
V_2 -> V_32 . V_39 = & V_25 -> V_32 ;
V_2 -> V_40 = V_41 ;
V_2 -> V_42 = V_43 ;
V_2 -> V_44 = F_5 ( V_43 ) ;
F_11 ( V_25 , V_2 ) ;
V_8 = F_12 ( V_25 , 0x1E , 3000 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_13 ( V_12 ) ;
if ( V_8 )
return V_8 ;
return F_14 ( & V_25 -> V_32 , V_2 ) ;
}
