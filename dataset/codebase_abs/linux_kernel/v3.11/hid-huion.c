static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
switch ( V_2 -> V_5 ) {
case V_6 :
if ( * V_4 == V_7 ) {
V_3 = V_8 ;
* V_4 = sizeof( V_8 ) ;
}
break;
}
return V_3 ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_9 ;
char V_10 [ 22 ] ;
V_9 = F_3 ( F_4 ( V_2 ) , 0x64 , V_10 , sizeof( V_10 ) ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , const struct V_11 * V_12 )
{
int V_13 ;
struct V_14 * V_15 = F_6 ( V_2 -> V_16 . V_17 ) ;
switch ( V_12 -> V_5 ) {
case V_6 :
if ( V_15 -> V_18 -> V_19 . V_20 != 0x00 )
return - V_21 ;
break;
}
V_13 = F_7 ( V_2 ) ;
if ( V_13 ) {
F_8 ( V_2 , L_1 ) ;
goto V_22;
}
V_13 = F_9 ( V_2 , V_23 ) ;
if ( V_13 ) {
F_8 ( V_2 , L_2 ) ;
goto V_22;
}
switch ( V_12 -> V_5 ) {
case V_6 :
V_13 = F_2 ( V_2 ) ;
if ( V_13 ) {
F_8 ( V_2 , L_3 ) ;
goto V_24;
}
break;
}
return 0 ;
V_24:
F_10 ( V_2 ) ;
V_22:
return V_13 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_25 * V_26 ,
T_2 * V_27 , int V_28 )
{
if ( V_26 -> type == V_29 && V_26 -> V_12 == 0x07 && V_28 >= 2 )
V_27 [ 1 ] ^= 0x40 ;
return 0 ;
}
