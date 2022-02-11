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
F_3 ( L_1 , V_6 , V_5 ) ;
V_6 = - V_16 ;
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
static int F_6 ( struct V_17 * V_18 ,
T_2 V_19 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
int V_6 ;
F_7 ( L_2 , V_21 , V_19 ) ;
switch ( V_19 ) {
case V_22 :
V_2 -> V_23 [ 0 ] = 0x10 ;
break;
case V_24 :
V_2 -> V_23 [ 0 ] = 0x31 ;
break;
case V_25 :
V_2 -> V_23 [ 0 ] = 0x38 ;
break;
default:
V_6 = - V_26 ;
goto V_27;
} ;
V_6 = F_4 ( V_2 , & V_2 -> V_23 [ 0 ] , 1 ) ;
if ( V_6 )
goto V_27;
return V_6 ;
V_27:
F_7 ( L_3 , V_21 , V_6 ) ;
return V_6 ;
}
static void F_8 ( struct V_17 * V_18 )
{
F_7 ( L_4 , V_21 ) ;
F_6 ( V_18 , V_22 ) ;
F_9 ( V_18 -> V_20 ) ;
V_18 -> V_20 = NULL ;
}
struct V_17 * F_10 ( struct V_17 * V_18 ,
struct V_28 * V_15 , const struct V_29 * V_10 )
{
int V_6 ;
struct V_1 * V_2 = NULL ;
T_1 V_12 [ 2 ] ;
V_2 = F_11 ( sizeof( struct V_1 ) , V_30 ) ;
if ( V_2 == NULL ) {
V_6 = - V_31 ;
goto V_27;
}
V_2 -> V_15 = V_15 ;
V_2 -> V_10 = V_10 ;
V_18 -> V_20 = V_2 ;
V_6 = F_5 ( V_2 , V_12 , 2 ) ;
if ( V_6 )
goto V_27;
V_2 -> V_23 [ 0 ] = 0x10 ;
V_6 = F_4 ( V_2 , & V_2 -> V_23 [ 1 ] , 1 ) ;
if ( V_6 )
goto V_27;
V_2 -> V_23 [ 1 ] = 0x82 ;
V_6 = F_4 ( V_2 , & V_2 -> V_23 [ 1 ] , 1 ) ;
if ( V_6 )
goto V_27;
F_12 ( L_5 ) ;
V_18 -> V_32 . V_33 = F_8 ;
V_18 -> V_32 . V_34 = F_6 ;
return V_18 ;
V_27:
F_7 ( L_3 , V_21 , V_6 ) ;
F_9 ( V_2 ) ;
return NULL ;
}
