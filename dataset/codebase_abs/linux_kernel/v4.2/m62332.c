static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_9 [ 2 ] ;
int V_10 ;
if ( V_3 == V_6 -> V_11 [ V_4 ] )
return 0 ;
V_9 [ 0 ] = V_4 ;
V_9 [ 1 ] = V_3 ;
F_3 ( & V_6 -> V_12 ) ;
if ( V_3 ) {
V_10 = F_4 ( V_6 -> V_13 ) ;
if ( V_10 )
goto V_14;
}
V_10 = F_5 ( V_8 , V_9 , 2 ) ;
if ( V_10 >= 0 && V_10 != 2 )
V_10 = - V_15 ;
if ( V_10 < 0 )
goto V_14;
V_6 -> V_11 [ V_4 ] = V_3 ;
if ( ! V_3 )
F_6 ( V_6 -> V_13 ) ;
F_7 ( & V_6 -> V_12 ) ;
return 0 ;
V_14:
F_7 ( & V_6 -> V_12 ) ;
return V_10 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_16 const * V_17 ,
int * V_3 ,
int * V_18 ,
long V_19 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_19 ) {
case V_20 :
* V_3 = V_6 -> V_21 ;
* V_18 = 8 ;
return V_22 ;
case V_23 :
* V_3 = V_6 -> V_11 [ V_17 -> V_4 ] ;
return V_24 ;
case V_25 :
* V_3 = 1 ;
return V_24 ;
default:
break;
}
return - V_26 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_16 const * V_17 , int V_3 , int V_18 , long V_27 )
{
int V_28 ;
switch ( V_27 ) {
case V_23 :
if ( V_3 < 0 || V_3 > 255 )
return - V_26 ;
V_28 = F_1 ( V_2 , V_3 , V_17 -> V_4 ) ;
break;
default:
V_28 = - V_26 ;
break;
}
return V_28 ;
}
static int F_10 ( struct V_29 * V_30 )
{
struct V_7 * V_8 = F_11 ( V_30 ) ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_28 ;
V_6 -> V_31 [ 0 ] = V_6 -> V_11 [ 0 ] ;
V_6 -> V_31 [ 1 ] = V_6 -> V_11 [ 1 ] ;
V_28 = F_1 ( V_2 , 0 , 0 ) ;
if ( V_28 < 0 )
return V_28 ;
return F_1 ( V_2 , 0 , 1 ) ;
}
static int F_13 ( struct V_29 * V_30 )
{
struct V_7 * V_8 = F_11 ( V_30 ) ;
struct V_1 * V_2 = F_12 ( V_8 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_28 ;
V_28 = F_1 ( V_2 , V_6 -> V_31 [ 0 ] , 0 ) ;
if ( V_28 < 0 )
return V_28 ;
return F_1 ( V_2 , V_6 -> V_31 [ 1 ] , 1 ) ;
}
static int F_14 ( struct V_7 * V_8 ,
const struct V_32 * V_33 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_28 ;
V_2 = F_15 ( & V_8 -> V_30 , sizeof( * V_6 ) ) ;
if ( ! V_2 )
return - V_34 ;
V_6 = F_2 ( V_2 ) ;
F_16 ( V_8 , V_2 ) ;
V_6 -> V_8 = V_8 ;
F_17 ( & V_6 -> V_12 ) ;
V_6 -> V_13 = F_18 ( & V_8 -> V_30 , L_1 ) ;
if ( F_19 ( V_6 -> V_13 ) )
return F_20 ( V_6 -> V_13 ) ;
V_2 -> V_30 . V_35 = & V_8 -> V_30 ;
V_2 -> V_36 = V_37 ;
V_2 -> V_38 = V_39 ;
V_2 -> V_40 = V_41 ;
V_2 -> V_42 = & V_43 ;
V_28 = F_21 ( V_6 -> V_13 ) ;
if ( V_28 < 0 )
return V_28 ;
V_6 -> V_21 = V_28 / 1000 ;
V_28 = F_22 ( V_2 , V_8 -> V_30 . V_44 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_23 ( V_2 ) ;
if ( V_28 < 0 )
goto V_45;
return 0 ;
V_45:
F_24 ( V_2 ) ;
return V_28 ;
}
static int F_25 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_12 ( V_8 ) ;
F_26 ( V_2 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
