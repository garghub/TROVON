static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 ,
int * V_6 , long V_7 )
{
struct V_8 * * V_9 = F_2 ( V_2 ) ;
int V_10 ;
switch ( V_7 ) {
case V_11 :
V_10 = F_3 ( * V_9 ,
V_4 -> type == V_12 ?
V_13 :
V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_5 = V_10 >> 2 ;
if ( V_4 -> type == V_15 )
* V_5 = F_4 ( * V_5 , 786 , 13893 ) ;
return V_16 ;
case V_17 :
if ( V_4 -> type == V_12 )
* V_5 = 175720 ;
else
* V_5 = 125 * 1000 ;
* V_6 = 65536 >> 2 ;
return V_18 ;
case V_19 :
if ( V_4 -> type == V_12 )
* V_5 = - 4368 ;
else
* V_5 = - 786 ;
return V_16 ;
default:
break;
}
return - V_20 ;
}
static int F_5 ( struct V_8 * V_9 ,
const struct V_21 * V_22 )
{
struct V_1 * V_2 ;
struct V_8 * * V_23 ;
int V_10 ;
if ( ! F_6 ( V_9 -> V_24 ,
V_25 |
V_26 ) )
return - V_27 ;
V_10 = F_7 ( V_9 , V_28 ) ;
if ( V_10 < 0 )
return V_10 ;
F_8 ( 15 ) ;
V_2 = F_9 ( & V_9 -> V_29 , sizeof( * V_23 ) ) ;
if ( ! V_2 )
return - V_30 ;
V_23 = F_2 ( V_2 ) ;
* V_23 = V_9 ;
V_2 -> V_29 . V_31 = & V_9 -> V_29 ;
V_2 -> V_32 = F_10 ( & V_9 -> V_29 ) ;
V_2 -> V_33 = V_34 ;
V_2 -> V_35 = & V_36 ;
V_2 -> V_37 = V_38 ;
V_2 -> V_39 = F_11 ( V_38 ) ;
return F_12 ( & V_9 -> V_29 , V_2 ) ;
}
