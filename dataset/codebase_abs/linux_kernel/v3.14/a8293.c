static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 , bool V_5 )
{
int V_6 ;
struct V_7 V_8 [ 1 ] = {
{
. V_9 = V_2 -> V_10 -> V_11 ,
. V_4 = V_4 ,
. V_12 = V_3 ,
}
} ;
if ( V_5 )
V_8 [ 0 ] . V_13 = V_14 ;
else
V_8 [ 0 ] . V_13 = 0 ;
V_6 = F_2 ( V_2 -> V_15 , V_8 , 1 ) ;
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_3 ( & V_2 -> V_15 -> V_16 , L_1 ,
V_17 , V_6 , V_5 ) ;
V_6 = - V_18 ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_6 ( struct V_19 * V_20 ,
T_2 V_21 )
{
struct V_1 * V_2 = V_20 -> V_22 ;
int V_6 ;
F_7 ( & V_2 -> V_15 -> V_16 , L_2 , V_23 ,
V_21 ) ;
switch ( V_21 ) {
case V_24 :
V_2 -> V_25 [ 0 ] = 0x10 ;
break;
case V_26 :
V_2 -> V_25 [ 0 ] = 0x31 ;
break;
case V_27 :
V_2 -> V_25 [ 0 ] = 0x38 ;
break;
default:
V_6 = - V_28 ;
goto V_29;
}
V_6 = F_4 ( V_2 , & V_2 -> V_25 [ 0 ] , 1 ) ;
if ( V_6 )
goto V_29;
F_8 ( 1500 , 50000 ) ;
return V_6 ;
V_29:
F_7 ( & V_2 -> V_15 -> V_16 , L_3 , V_23 , V_6 ) ;
return V_6 ;
}
static void F_9 ( struct V_19 * V_20 )
{
F_6 ( V_20 , V_24 ) ;
F_10 ( V_20 -> V_22 ) ;
V_20 -> V_22 = NULL ;
}
struct V_19 * F_11 ( struct V_19 * V_20 ,
struct V_30 * V_15 , const struct V_31 * V_10 )
{
int V_6 ;
struct V_1 * V_2 = NULL ;
T_1 V_12 [ 2 ] ;
V_2 = F_12 ( sizeof( struct V_1 ) , V_32 ) ;
if ( V_2 == NULL ) {
V_6 = - V_33 ;
goto V_29;
}
V_2 -> V_15 = V_15 ;
V_2 -> V_10 = V_10 ;
V_20 -> V_22 = V_2 ;
V_6 = F_5 ( V_2 , V_12 , 2 ) ;
if ( V_6 )
goto V_29;
V_2 -> V_25 [ 0 ] = 0x10 ;
V_6 = F_4 ( V_2 , & V_2 -> V_25 [ 0 ] , 1 ) ;
if ( V_6 )
goto V_29;
V_2 -> V_25 [ 1 ] = 0x82 ;
V_6 = F_4 ( V_2 , & V_2 -> V_25 [ 1 ] , 1 ) ;
if ( V_6 )
goto V_29;
V_20 -> V_34 . V_35 = F_9 ;
V_20 -> V_34 . V_36 = F_6 ;
F_13 ( & V_2 -> V_15 -> V_16 , L_4 ,
V_17 ) ;
return V_20 ;
V_29:
F_7 ( & V_15 -> V_16 , L_3 , V_23 , V_6 ) ;
F_10 ( V_2 ) ;
return NULL ;
}
