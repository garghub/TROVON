static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 )
{
unsigned int V_6 = V_2 -> V_7 -> V_8 ;
unsigned int V_9 = V_4 -> V_10 . V_9 + ( V_4 -> V_11 * 8 ) ;
T_1 V_12 ;
T_2 V_13 ;
int V_14 ;
switch ( V_6 ) {
case 2 :
V_14 = F_2 ( V_2 -> V_15 , ( void * ) & V_12 , V_6 ) ;
* V_5 = F_3 ( V_12 ) ;
break;
case 4 :
V_14 = F_2 ( V_2 -> V_15 , ( void * ) & V_13 , V_6 ) ;
* V_5 = F_4 ( V_13 ) ;
break;
default:
V_14 = - V_16 ;
}
if ( V_14 )
return V_14 ;
if ( * V_5 & V_2 -> V_7 -> V_17 )
return - V_16 ;
* V_5 = F_5 ( * V_5 >> V_9 , V_4 -> V_10 . V_18 - 1 ) ;
return 0 ;
}
static T_3 F_6 ( int V_19 , void * V_20 )
{
struct V_21 * V_22 = V_20 ;
struct V_23 * V_24 = V_22 -> V_24 ;
struct V_1 * V_2 = F_7 ( V_24 ) ;
int V_14 ;
V_14 = F_2 ( V_2 -> V_15 , V_2 -> V_25 , V_2 -> V_7 -> V_8 ) ;
if ( ! V_14 ) {
F_8 ( V_24 , V_2 -> V_25 ,
F_9 ( V_24 ) ) ;
}
F_10 ( V_24 -> V_26 ) ;
return V_27 ;
}
static int F_11 ( struct V_23 * V_24 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_28 , long V_29 )
{
struct V_1 * V_2 = F_7 ( V_24 ) ;
int V_14 = - V_16 ;
switch ( V_29 ) {
case V_30 :
V_14 = F_12 ( V_24 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_1 ( V_2 , V_4 , V_5 ) ;
F_13 ( V_24 ) ;
if ( ! V_14 )
return V_31 ;
break;
case V_32 :
switch ( V_4 -> V_33 ) {
case V_34 :
* V_5 = 62 ;
* V_28 = 500000 ;
V_14 = V_35 ;
break;
default:
* V_5 = 250 ;
V_14 = V_31 ;
} ;
break;
}
return V_14 ;
}
static int F_14 ( struct V_36 * V_15 )
{
const struct V_37 * V_38 = F_15 ( V_15 ) ;
struct V_23 * V_24 ;
struct V_1 * V_2 ;
const struct V_39 * V_7 =
& V_40 [ V_38 -> V_41 ] ;
int V_14 ;
V_24 = F_16 ( & V_15 -> V_42 , sizeof( * V_2 ) ) ;
if ( ! V_24 )
return - V_43 ;
V_24 -> V_44 = & V_45 ;
V_24 -> V_46 = V_47 ;
V_24 -> V_48 = V_7 -> V_48 ;
V_24 -> V_49 = V_7 -> V_50 ;
V_24 -> V_51 = V_7 -> V_51 ;
V_24 -> V_52 = V_53 ;
V_24 -> V_42 . V_54 = & V_15 -> V_42 ;
V_2 = F_7 ( V_24 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_7 = V_7 ;
V_14 = F_17 ( V_24 , NULL ,
F_6 , NULL ) ;
if ( V_14 )
return V_14 ;
V_14 = F_18 ( V_24 ) ;
if ( V_14 )
goto V_55;
return 0 ;
V_55:
F_19 ( V_24 ) ;
return V_14 ;
}
static int F_20 ( struct V_36 * V_15 )
{
struct V_23 * V_24 = F_21 ( V_15 ) ;
F_22 ( V_24 ) ;
F_19 ( V_24 ) ;
return 0 ;
}
