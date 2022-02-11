static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 )
{
int V_6 ;
switch ( V_2 -> V_7 ) {
case 2 : {
T_1 V_8 ;
V_6 = F_2 ( V_2 -> V_9 , ( void * ) & V_8 , 2 ) ;
if ( V_6 )
return V_6 ;
* V_5 = F_3 ( V_8 ) ;
break;
}
case 3 : {
T_2 V_8 ;
V_6 = F_2 ( V_2 -> V_9 , ( void * ) & V_8 , 3 ) ;
if ( V_6 )
return V_6 ;
* V_5 = F_4 ( V_8 ) >> 8 ;
break;
}
default:
return - V_10 ;
}
* V_5 = F_5 ( * V_5 >> V_2 -> V_11 , V_4 -> V_12 . V_13 - 1 ) ;
return 0 ;
}
static T_3 F_6 ( int V_14 , void * V_15 )
{
struct V_16 * V_17 = V_15 ;
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_1 * V_2 = F_7 ( V_19 ) ;
int V_6 ;
V_6 = F_1 ( V_2 , & V_19 -> V_20 [ 0 ] ,
( int * ) & V_2 -> V_21 ) ;
if ( ! V_6 )
F_8 ( V_19 ,
V_2 -> V_21 ,
F_9 ( V_19 ) ) ;
F_10 ( V_19 -> V_22 ) ;
return V_23 ;
}
static int F_11 ( struct V_18 * V_19 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_24 , long V_25 )
{
struct V_1 * V_2 = F_7 ( V_19 ) ;
int V_6 ;
if ( V_25 != V_26 )
return - V_10 ;
V_6 = F_12 ( V_19 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_1 ( V_2 , V_4 , V_5 ) ;
F_13 ( V_19 ) ;
if ( ! V_6 )
return V_27 ;
return 0 ;
}
static int F_14 ( struct V_28 * V_9 )
{
struct V_18 * V_19 ;
struct V_1 * V_2 ;
int V_6 ;
V_19 = F_15 ( & V_9 -> V_29 , sizeof( * V_2 ) ) ;
if ( ! V_19 )
return - V_30 ;
V_19 -> V_31 = & V_32 ;
V_19 -> V_29 . V_33 = & V_9 -> V_29 ;
V_19 -> V_29 . V_34 = V_9 -> V_29 . V_34 ;
V_19 -> V_35 = V_36 ;
V_19 -> V_37 = V_38 ;
F_16 ( V_9 , V_19 ) ;
V_2 = F_7 ( V_19 ) ;
V_2 -> V_9 = V_9 ;
switch ( F_17 ( V_9 ) -> V_39 ) {
case V_40 :
V_19 -> V_20 = V_41 ;
V_19 -> V_42 = F_18 ( V_41 ) ;
V_2 -> V_11 = 0 ;
V_2 -> V_7 = 2 ;
break;
case V_43 :
V_19 -> V_20 = V_44 ;
V_19 -> V_42 = F_18 ( V_44 ) ;
V_2 -> V_11 = 6 ;
V_2 -> V_7 = 3 ;
break;
}
V_6 = F_19 ( V_19 , NULL ,
F_6 , NULL ) ;
if ( V_6 )
return V_6 ;
V_6 = F_20 ( V_19 ) ;
if ( V_6 )
goto V_45;
return 0 ;
V_45:
F_21 ( V_19 ) ;
return V_6 ;
}
static int F_22 ( struct V_28 * V_9 )
{
struct V_18 * V_19 = F_23 ( V_9 ) ;
F_24 ( V_19 ) ;
F_21 ( V_19 ) ;
return 0 ;
}
