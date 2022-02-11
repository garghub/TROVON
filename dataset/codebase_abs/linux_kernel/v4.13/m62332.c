static int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
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
V_10 = F_5 ( V_8 , V_9 , F_6 ( V_9 ) ) ;
if ( V_10 >= 0 && V_10 != F_6 ( V_9 ) )
V_10 = - V_15 ;
if ( V_10 < 0 )
goto V_14;
V_6 -> V_11 [ V_4 ] = V_3 ;
if ( ! V_3 )
F_7 ( V_6 -> V_13 ) ;
F_8 ( & V_6 -> V_12 ) ;
return 0 ;
V_14:
F_8 ( & V_6 -> V_12 ) ;
return V_10 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_16 const * V_17 ,
int * V_3 ,
int * V_18 ,
long V_19 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_20 ;
switch ( V_19 ) {
case V_21 :
V_20 = F_10 ( V_6 -> V_13 ) ;
if ( V_20 < 0 )
return V_20 ;
* V_3 = V_20 / 1000 ;
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
static int F_11 ( struct V_1 * V_2 ,
struct V_16 const * V_17 , int V_3 , int V_18 ,
long V_19 )
{
switch ( V_19 ) {
case V_23 :
if ( V_3 < 0 || V_3 > 255 )
return - V_26 ;
return F_1 ( V_2 , V_3 , V_17 -> V_4 ) ;
default:
break;
}
return - V_26 ;
}
static int F_12 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = F_13 ( V_28 ) ;
struct V_1 * V_2 = F_14 ( V_8 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_20 ;
V_6 -> V_29 [ 0 ] = V_6 -> V_11 [ 0 ] ;
V_6 -> V_29 [ 1 ] = V_6 -> V_11 [ 1 ] ;
V_20 = F_1 ( V_2 , 0 , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_1 ( V_2 , 0 , 1 ) ;
}
static int F_15 ( struct V_27 * V_28 )
{
struct V_7 * V_8 = F_13 ( V_28 ) ;
struct V_1 * V_2 = F_14 ( V_8 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_20 ;
V_20 = F_1 ( V_2 , V_6 -> V_29 [ 0 ] , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_1 ( V_2 , V_6 -> V_29 [ 1 ] , 1 ) ;
}
static int F_16 ( struct V_7 * V_8 ,
const struct V_30 * V_31 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_20 ;
V_2 = F_17 ( & V_8 -> V_28 , sizeof( * V_6 ) ) ;
if ( ! V_2 )
return - V_32 ;
V_6 = F_2 ( V_2 ) ;
F_18 ( V_8 , V_2 ) ;
V_6 -> V_8 = V_8 ;
F_19 ( & V_6 -> V_12 ) ;
V_6 -> V_13 = F_20 ( & V_8 -> V_28 , L_1 ) ;
if ( F_21 ( V_6 -> V_13 ) )
return F_22 ( V_6 -> V_13 ) ;
V_2 -> V_28 . V_33 = & V_8 -> V_28 ;
V_2 -> V_34 = F_6 ( V_35 ) ;
V_2 -> V_36 = V_35 ;
V_2 -> V_37 = V_38 ;
V_2 -> V_39 = & V_40 ;
V_20 = F_23 ( V_2 , V_8 -> V_28 . V_41 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_24 ( V_2 ) ;
if ( V_20 < 0 )
goto V_42;
return 0 ;
V_42:
F_25 ( V_2 ) ;
return V_20 ;
}
static int F_26 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_14 ( V_8 ) ;
F_27 ( V_2 ) ;
F_25 ( V_2 ) ;
F_1 ( V_2 , 0 , 0 ) ;
F_1 ( V_2 , 0 , 1 ) ;
return 0 ;
}
