int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_5 type ,
enum V_6 V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return V_9 -> V_10 ;
}
int F_3 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_5 type ,
enum V_6 V_7 ,
int V_11 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_4 -> type ) {
case V_12 :
switch ( type ) {
case V_13 :
if ( V_7 == V_14 )
V_9 -> V_10 = V_11 ;
else
return - V_15 ;
default:
return - V_15 ;
}
break;
case V_16 :
switch ( type ) {
case V_13 :
V_9 -> V_10 = V_11 ;
break;
default:
return - V_15 ;
}
break;
case V_17 :
switch ( type ) {
case V_18 :
V_9 -> V_10 = V_11 ;
break;
default:
return - V_15 ;
}
break;
default:
return - V_15 ;
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_5 type ,
enum V_6 V_7 ,
enum V_19 V_20 ,
int * V_21 , int * V_22 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
* V_21 = V_9 -> V_23 ;
return V_24 ;
}
int F_5 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_5 type ,
enum V_6 V_7 ,
enum V_19 V_20 ,
int V_21 , int V_22 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_9 -> V_23 = V_21 ;
return 0 ;
}
static T_1 F_6 ( int V_25 , void * V_26 )
{
struct V_1 * V_2 = V_26 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_7 ( & V_2 -> V_27 , L_1 ,
V_9 -> V_28 -> V_29 , V_9 -> V_28 -> V_30 ) ;
switch ( V_9 -> V_28 -> V_30 ) {
case 0 :
F_8 ( V_2 ,
F_9 ( V_12 , 0 , 0 ,
V_14 ,
V_13 , 0 , 0 , 0 ) ,
F_10 () ) ;
break;
case 1 :
if ( V_9 -> V_31 > V_9 -> V_23 )
F_8 ( V_2 ,
F_9 ( V_16 , 0 ,
V_32 ,
V_14 ,
V_13 ,
0 , 0 , 0 ) ,
F_10 () ) ;
break;
case 2 :
if ( V_9 -> V_33 < V_9 -> V_23 )
F_8 ( V_2 ,
F_9 ( V_16 , 0 ,
V_34 ,
V_35 ,
V_13 ,
0 , 0 , 0 ) ,
F_10 () ) ;
break;
case 3 :
F_8 ( V_2 ,
F_9 ( V_17 , 0 , V_36 ,
V_37 ,
V_18 , 0 , 0 , 0 ) ,
F_10 () ) ;
break;
default:
break;
}
return V_38 ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_39 ;
V_9 -> V_40 = F_12 () ;
if ( V_9 -> V_40 < 0 ) {
V_39 = V_9 -> V_40 ;
goto V_41;
}
V_9 -> V_28 = F_13 ( V_9 -> V_40 ) ;
V_39 = F_14 ( V_9 -> V_40 ,
NULL ,
& F_6 ,
V_42 ,
L_2 ,
V_2 ) ;
if ( V_39 < 0 )
goto V_43;
return 0 ;
V_43:
F_15 ( V_9 -> V_40 ) ;
V_41:
return V_39 ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_17 ( V_9 -> V_40 , V_2 ) ;
F_15 ( V_9 -> V_40 ) ;
}
