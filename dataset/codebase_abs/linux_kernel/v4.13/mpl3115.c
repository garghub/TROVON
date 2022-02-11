static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = 15 ;
V_3 = F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 | V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
while ( V_4 -- > 0 ) {
V_3 = F_3 ( V_2 -> V_5 , V_6 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ! ( V_3 & V_8 ) )
break;
F_4 ( 20 ) ;
}
if ( V_4 < 0 ) {
F_5 ( & V_2 -> V_5 -> V_9 , L_1 ) ;
return - V_10 ;
}
return 0 ;
}
static int F_6 ( struct V_11 * V_12 ,
struct V_13 const * V_14 ,
int * V_15 , int * V_16 , long V_17 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_18 = 0 ;
int V_3 ;
switch ( V_17 ) {
case V_19 :
V_3 = F_8 ( V_12 ) ;
if ( V_3 )
return V_3 ;
switch ( V_14 -> type ) {
case V_20 :
F_9 ( & V_2 -> V_21 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_10 ( & V_2 -> V_21 ) ;
break;
}
V_3 = F_11 ( V_2 -> V_5 ,
V_22 , 3 , ( V_23 * ) & V_18 ) ;
F_10 ( & V_2 -> V_21 ) ;
if ( V_3 < 0 )
break;
* V_15 = F_12 ( V_18 ) >> 12 ;
V_3 = V_24 ;
break;
case V_25 :
F_9 ( & V_2 -> V_21 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_10 ( & V_2 -> V_21 ) ;
break;
}
V_3 = F_11 ( V_2 -> V_5 ,
V_26 , 2 , ( V_23 * ) & V_18 ) ;
F_10 ( & V_2 -> V_21 ) ;
if ( V_3 < 0 )
break;
* V_15 = F_13 ( F_12 ( V_18 ) >> 20 , 11 ) ;
V_3 = V_24 ;
break;
default:
V_3 = - V_27 ;
break;
}
F_14 ( V_12 ) ;
return V_3 ;
case V_28 :
switch ( V_14 -> type ) {
case V_20 :
* V_15 = 0 ;
* V_16 = 250 ;
return V_29 ;
case V_25 :
* V_15 = 0 ;
* V_16 = 62500 ;
return V_29 ;
default:
return - V_27 ;
}
}
return - V_27 ;
}
static T_2 F_15 ( int V_30 , void * V_31 )
{
struct V_32 * V_33 = V_31 ;
struct V_11 * V_12 = V_33 -> V_12 ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
V_23 V_34 [ 16 ] ;
int V_3 , V_35 = 0 ;
F_9 ( & V_2 -> V_21 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_10 ( & V_2 -> V_21 ) ;
goto V_36;
}
memset ( V_34 , 0 , sizeof( V_34 ) ) ;
if ( F_16 ( 0 , V_12 -> V_37 ) ) {
V_3 = F_11 ( V_2 -> V_5 ,
V_22 , 3 , & V_34 [ V_35 ] ) ;
if ( V_3 < 0 ) {
F_10 ( & V_2 -> V_21 ) ;
goto V_36;
}
V_35 += 4 ;
}
if ( F_16 ( 1 , V_12 -> V_37 ) ) {
V_3 = F_11 ( V_2 -> V_5 ,
V_26 , 2 , & V_34 [ V_35 ] ) ;
if ( V_3 < 0 ) {
F_10 ( & V_2 -> V_21 ) ;
goto V_36;
}
}
F_10 ( & V_2 -> V_21 ) ;
F_17 ( V_12 , V_34 ,
F_18 ( V_12 ) ) ;
V_36:
F_19 ( V_12 -> V_38 ) ;
return V_39 ;
}
static int F_20 ( struct V_40 * V_5 ,
const struct V_41 * V_42 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int V_3 ;
V_3 = F_3 ( V_5 , V_43 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 != V_44 )
return - V_45 ;
V_12 = F_21 ( & V_5 -> V_9 , sizeof( * V_2 ) ) ;
if ( ! V_12 )
return - V_46 ;
V_2 = F_7 ( V_12 ) ;
V_2 -> V_5 = V_5 ;
F_22 ( & V_2 -> V_21 ) ;
F_23 ( V_5 , V_12 ) ;
V_12 -> V_47 = & V_48 ;
V_12 -> V_49 = V_42 -> V_49 ;
V_12 -> V_9 . V_50 = & V_5 -> V_9 ;
V_12 -> V_51 = V_52 ;
V_12 -> V_53 = V_54 ;
V_12 -> V_55 = F_24 ( V_54 ) ;
F_2 ( V_5 , V_6 ,
V_56 ) ;
F_4 ( 50 ) ;
V_2 -> V_7 = V_57 ;
V_3 = F_2 ( V_5 , V_6 ,
V_2 -> V_7 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_25 ( V_12 , NULL ,
F_15 , NULL ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_26 ( V_12 ) ;
if ( V_3 < 0 )
goto V_58;
return 0 ;
V_58:
F_27 ( V_12 ) ;
return V_3 ;
}
static int F_28 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 & ~ V_59 ) ;
}
static int F_29 ( struct V_40 * V_5 )
{
struct V_11 * V_12 = F_30 ( V_5 ) ;
F_31 ( V_12 ) ;
F_27 ( V_12 ) ;
F_28 ( F_7 ( V_12 ) ) ;
return 0 ;
}
static int F_32 ( struct V_60 * V_9 )
{
return F_28 ( F_7 ( F_30 (
F_33 ( V_9 ) ) ) ) ;
}
static int F_34 ( struct V_60 * V_9 )
{
struct V_1 * V_2 = F_7 ( F_30 (
F_33 ( V_9 ) ) ) ;
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 ) ;
}
