static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ,
V_6 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_7 ,
V_8 << V_9 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_10 ,
V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_12 ,
V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_3 ( struct V_14 * V_15 ,
struct V_16 const * V_17 , int * V_18 ,
int * V_19 , long V_20 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
int V_3 ;
switch ( V_20 ) {
case V_21 :
V_3 = F_5 ( V_2 -> V_4 ,
V_22 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_18 = V_3 ;
return V_23 ;
case V_24 :
V_3 = F_6 ( V_2 -> V_4 ,
V_7 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = ( V_3 & V_25 ) >> V_9 ;
* V_18 = V_26 [ V_3 ] [ 0 ] ;
* V_19 = V_26 [ V_3 ] [ 1 ] ;
return V_27 ;
}
return - V_28 ;
}
static int F_7 ( struct V_14 * V_15 ,
struct V_16 const * V_17 , int V_18 ,
int V_19 , long V_20 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
int V_29 ;
switch ( V_20 ) {
case V_24 :
for ( V_29 = 0 ; V_29 < F_8 ( V_26 ) ; V_29 ++ ) {
if ( V_18 == V_26 [ V_29 ] [ 0 ] &&
V_19 == V_26 [ V_29 ] [ 1 ] )
return F_2 ( V_2 -> V_4 ,
V_7 ,
V_29 << V_9 ) ;
}
break;
}
return - V_28 ;
}
static int F_9 ( struct V_30 * V_4 ,
const struct V_31 * V_32 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_3 ;
V_15 = F_10 ( & V_4 -> V_33 , sizeof( * V_2 ) ) ;
if ( ! V_15 )
return - V_34 ;
V_2 = F_4 ( V_15 ) ;
F_11 ( V_4 , V_15 ) ;
V_2 -> V_4 = V_4 ;
V_15 -> V_33 . V_35 = & V_4 -> V_33 ;
V_15 -> V_36 = & V_37 ;
V_15 -> V_38 = V_39 ;
V_15 -> V_40 = V_41 ;
V_15 -> V_42 = F_8 ( V_41 ) ;
V_15 -> V_43 = V_44 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_12 ( & V_4 -> V_33 , L_1 ) ;
return V_3 ;
}
return F_13 ( & V_4 -> V_33 , V_15 ) ;
}
static int F_14 ( struct V_30 * V_4 )
{
return F_2 ( V_4 , V_5 ,
V_45 ) ;
}
