static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
struct V_5 V_6 = {
. V_7 = V_3 ,
. V_8 = V_3 ,
. V_4 = V_4 ,
} ;
struct V_9 V_10 ;
F_2 ( & V_10 ) ;
F_3 ( & V_6 , & V_10 ) ;
return F_4 ( V_2 , & V_10 ) ;
}
static int F_5 ( struct V_11 * V_12 ,
struct V_13 const * V_14 ,
int * V_15 , int * V_16 , long V_17 )
{
int V_18 ;
struct V_19 * V_20 = F_6 ( V_12 ) ;
int V_21 = V_14 -> V_22 ;
switch ( V_17 ) {
case V_23 :
F_7 ( & V_20 -> V_24 ) ;
V_20 -> V_3 [ 0 ] = ( V_21 << V_25 ) | V_26 ;
V_20 -> V_3 [ 1 ] = 0 ;
V_18 = F_1 ( V_20 -> V_2 , V_20 -> V_3 , 2 ) ;
if ( V_18 ) {
F_8 ( & V_20 -> V_24 ) ;
return V_18 ;
}
if ( ! F_9 ( V_20 -> V_3 ) ) {
F_8 ( & V_20 -> V_24 ) ;
return - V_27 ;
}
* V_15 = F_10 ( V_20 -> V_3 ) ;
F_8 ( & V_20 -> V_24 ) ;
return V_28 ;
case V_29 :
* V_15 = 1000 * V_20 -> V_30 -> V_31 ;
* V_16 = V_20 -> V_30 -> V_32 ;
return V_33 ;
}
return - V_34 ;
}
static int F_11 ( struct V_11 * V_12 ,
struct V_13 const * V_14 ,
int V_15 , int V_16 , long V_17 )
{
int V_18 ;
struct V_19 * V_20 = F_6 ( V_12 ) ;
int V_21 = V_14 -> V_22 << V_25 ;
switch ( V_17 ) {
case V_23 :
if ( V_15 > V_20 -> V_30 -> V_32 || V_15 < 0 )
return - V_34 ;
break;
default:
return - V_34 ;
}
F_7 ( & V_20 -> V_24 ) ;
V_20 -> V_3 [ 0 ] = V_21 << V_25 ;
V_20 -> V_3 [ 0 ] |= V_35 | ( V_15 >> 8 ) ;
V_20 -> V_3 [ 1 ] = V_15 & 0xFF ;
V_18 = F_12 ( V_20 -> V_2 , V_20 -> V_3 , 2 ) ;
F_8 ( & V_20 -> V_24 ) ;
return V_18 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_36 * V_37 = & V_2 -> V_37 ;
unsigned long V_38 = F_14 ( V_2 ) -> V_39 ;
struct V_19 * V_20 ;
struct V_11 * V_12 ;
V_12 = F_15 ( V_37 , sizeof( * V_20 ) ) ;
if ( ! V_12 )
return - V_40 ;
V_20 = F_6 ( V_12 ) ;
F_16 ( V_2 , V_12 ) ;
V_20 -> V_2 = V_2 ;
V_20 -> V_30 = & V_41 [ V_38 ] ;
F_17 ( & V_20 -> V_24 ) ;
V_12 -> V_37 . V_42 = V_37 ;
V_12 -> V_43 = & V_44 ;
V_12 -> V_45 = V_46 ;
V_12 -> V_47 = V_20 -> V_30 -> V_48 ;
V_12 -> V_49 = F_14 ( V_2 ) -> V_49 ;
V_18 = F_18 ( V_37 , V_12 ) ;
if ( V_18 ) {
F_19 ( & V_2 -> V_37 , L_1 , V_12 -> V_49 ) ;
return V_18 ;
}
return 0 ;
}
