static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 , bool V_5 )
{
int V_6 ;
struct V_7 V_8 [ 1 ] = {
{
. V_9 = V_2 -> V_10 ,
. V_4 = V_4 ,
. V_11 = V_3 ,
}
} ;
if ( V_5 )
V_8 [ 0 ] . V_12 = V_13 ;
else
V_8 [ 0 ] . V_12 = 0 ;
V_6 = F_2 ( V_2 -> V_14 , V_8 , 1 ) ;
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_3 ( & V_2 -> V_14 -> V_15 , L_1 ,
V_16 , V_6 , V_5 ) ;
V_6 = - V_17 ;
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
static int F_6 ( struct V_18 * V_19 ,
enum V_20 V_20 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
int V_6 ;
F_7 ( & V_2 -> V_14 -> V_15 , L_2 , V_22 ,
V_20 ) ;
switch ( V_20 ) {
case V_23 :
V_2 -> V_24 [ 0 ] = 0x10 ;
break;
case V_25 :
V_2 -> V_24 [ 0 ] = 0x31 ;
break;
case V_26 :
V_2 -> V_24 [ 0 ] = 0x38 ;
break;
default:
V_6 = - V_27 ;
goto V_28;
}
V_6 = F_4 ( V_2 , & V_2 -> V_24 [ 0 ] , 1 ) ;
if ( V_6 )
goto V_28;
F_8 ( 1500 , 50000 ) ;
return V_6 ;
V_28:
F_7 ( & V_2 -> V_14 -> V_15 , L_3 , V_22 , V_6 ) ;
return V_6 ;
}
static void F_9 ( struct V_18 * V_19 )
{
F_6 ( V_19 , V_23 ) ;
F_10 ( V_19 -> V_21 ) ;
V_19 -> V_21 = NULL ;
}
struct V_18 * F_11 ( struct V_18 * V_19 ,
struct V_29 * V_14 , const struct V_30 * V_31 )
{
int V_6 ;
struct V_1 * V_2 = NULL ;
T_1 V_11 [ 2 ] ;
V_2 = F_12 ( sizeof( struct V_1 ) , V_32 ) ;
if ( V_2 == NULL ) {
V_6 = - V_33 ;
goto V_28;
}
V_2 -> V_14 = V_14 ;
V_2 -> V_10 = V_31 -> V_10 ;
V_19 -> V_21 = V_2 ;
V_6 = F_5 ( V_2 , V_11 , 2 ) ;
if ( V_6 )
goto V_28;
V_2 -> V_24 [ 0 ] = 0x10 ;
V_6 = F_4 ( V_2 , & V_2 -> V_24 [ 0 ] , 1 ) ;
if ( V_6 )
goto V_28;
V_2 -> V_24 [ 1 ] = 0x82 ;
V_6 = F_4 ( V_2 , & V_2 -> V_24 [ 1 ] , 1 ) ;
if ( V_6 )
goto V_28;
V_19 -> V_34 . V_35 = F_9 ;
V_19 -> V_34 . V_36 = F_6 ;
F_13 ( & V_2 -> V_14 -> V_15 , L_4 ,
V_16 ) ;
return V_19 ;
V_28:
F_7 ( & V_14 -> V_15 , L_3 , V_22 , V_6 ) ;
F_10 ( V_2 ) ;
return NULL ;
}
static int F_14 ( struct V_37 * V_38 ,
const struct V_39 * V_40 )
{
struct V_1 * V_15 ;
struct V_41 * V_42 = V_38 -> V_15 . V_43 ;
struct V_18 * V_19 = V_42 -> V_18 ;
int V_6 ;
T_1 V_11 [ 2 ] ;
V_15 = F_12 ( sizeof( * V_15 ) , V_32 ) ;
if ( ! V_15 ) {
V_6 = - V_33 ;
goto V_28;
}
V_15 -> V_38 = V_38 ;
V_15 -> V_14 = V_38 -> V_44 ;
V_15 -> V_10 = V_38 -> V_9 ;
V_6 = F_5 ( V_15 , V_11 , 2 ) ;
if ( V_6 )
goto V_45;
V_15 -> V_24 [ 0 ] = 0x10 ;
V_6 = F_4 ( V_15 , & V_15 -> V_24 [ 0 ] , 1 ) ;
if ( V_6 )
goto V_45;
V_15 -> V_24 [ 1 ] = 0x82 ;
V_6 = F_4 ( V_15 , & V_15 -> V_24 [ 1 ] , 1 ) ;
if ( V_6 )
goto V_45;
V_19 -> V_34 . V_36 = F_6 ;
V_19 -> V_21 = V_15 ;
F_15 ( V_38 , V_15 ) ;
F_13 ( & V_38 -> V_15 , L_5 ) ;
return 0 ;
V_45:
F_10 ( V_15 ) ;
V_28:
F_7 ( & V_38 -> V_15 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_16 ( struct V_37 * V_38 )
{
struct V_46 * V_15 = F_17 ( V_38 ) ;
F_7 ( & V_38 -> V_15 , L_7 ) ;
F_10 ( V_15 ) ;
return 0 ;
}
