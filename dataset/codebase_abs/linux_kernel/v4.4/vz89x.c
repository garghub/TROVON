static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 [ V_4 ] == 0 )
return 1 ;
return ! ! ( V_2 -> V_3 [ V_5 - 1 ] > 0 ) ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_6 ;
int V_7 ;
if ( ! F_3 ( V_8 , V_2 -> V_9 + V_10 ) )
return 0 ;
V_6 = F_4 ( V_2 -> V_11 ,
V_12 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
for ( V_7 = 0 ; V_7 < V_5 ; V_7 ++ ) {
V_6 = F_5 ( V_2 -> V_11 ) ;
if ( V_6 < 0 )
return V_6 ;
V_2 -> V_3 [ V_7 ] = V_6 ;
}
V_6 = F_1 ( V_2 ) ;
if ( V_6 )
return - V_13 ;
V_2 -> V_9 = V_8 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 * V_14 = & V_2 -> V_3 [ V_15 ] ;
return V_14 [ 0 ] | ( V_14 [ 1 ] << 8 ) ;
}
static int F_7 ( struct V_16 * V_17 ,
struct V_18 const * V_19 , int * V_20 ,
int * V_21 , long V_22 )
{
struct V_1 * V_2 = F_8 ( V_17 ) ;
int V_6 = - V_23 ;
switch ( V_22 ) {
case V_24 :
F_9 ( & V_2 -> V_25 ) ;
V_6 = F_2 ( V_2 ) ;
F_10 ( & V_2 -> V_25 ) ;
if ( V_6 )
return V_6 ;
switch ( V_19 -> V_26 ) {
case V_27 :
case V_4 :
case V_28 :
* V_20 = V_2 -> V_3 [ V_19 -> V_26 ] ;
return V_29 ;
case V_15 :
* V_20 = F_6 ( V_2 ) ;
return V_29 ;
default:
return - V_23 ;
}
break;
case V_30 :
switch ( V_19 -> type ) {
case V_31 :
* V_20 = 10 ;
return V_29 ;
default:
return - V_23 ;
}
break;
case V_32 :
switch ( V_19 -> V_26 ) {
case V_27 :
* V_20 = 44 ;
* V_21 = 250000 ;
return V_33 ;
case V_28 :
* V_20 = - 13 ;
return V_29 ;
default:
return - V_23 ;
}
}
return V_6 ;
}
static int F_11 ( struct V_34 * V_11 ,
const struct V_35 * V_36 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 ;
if ( ! F_12 ( V_11 -> V_37 , V_38 |
V_39 ) )
return - V_40 ;
V_17 = F_13 ( & V_11 -> V_41 , sizeof( * V_2 ) ) ;
if ( ! V_17 )
return - V_42 ;
V_2 = F_8 ( V_17 ) ;
F_14 ( V_11 , V_17 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_9 = V_8 - V_10 ;
F_15 ( & V_2 -> V_25 ) ;
V_17 -> V_41 . V_43 = & V_11 -> V_41 ;
V_17 -> V_44 = & V_45 ,
V_17 -> V_46 = F_16 ( & V_11 -> V_41 ) ;
V_17 -> V_47 = V_48 ;
V_17 -> V_49 = V_50 ;
V_17 -> V_51 = F_17 ( V_50 ) ;
return F_18 ( & V_11 -> V_41 , V_17 ) ;
}
