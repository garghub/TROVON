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
break;
default:
return - V_15 ;
}
default:
return - V_15 ;
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_5 type ,
enum V_6 V_7 ,
enum V_16 V_17 ,
int * V_18 , int * V_19 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
* V_18 = V_9 -> V_20 ;
return V_21 ;
}
int F_5 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_5 type ,
enum V_6 V_7 ,
enum V_16 V_17 ,
int V_18 , int V_19 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_9 -> V_20 = V_18 ;
return 0 ;
}
static T_1 F_6 ( int V_22 , void * V_23 )
{
struct V_1 * V_2 = V_23 ;
F_7 ( V_2 ,
F_8 ( V_12 , 0 , 0 ,
V_14 ,
V_13 , 0 , 0 , 0 ) ,
F_9 () ) ;
return V_24 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_25 ;
V_9 -> V_26 = F_11 () ;
if ( V_9 -> V_26 < 0 ) {
V_25 = V_9 -> V_26 ;
goto V_27;
}
V_25 = F_12 ( V_9 -> V_26 ,
NULL ,
& F_6 ,
V_28 ,
L_1 ,
V_2 ) ;
if ( V_25 < 0 )
goto V_29;
return 0 ;
V_29:
F_13 ( V_9 -> V_26 ) ;
V_27:
return V_25 ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_15 ( V_9 -> V_26 , V_2 ) ;
F_13 ( V_9 -> V_26 ) ;
return 0 ;
}
