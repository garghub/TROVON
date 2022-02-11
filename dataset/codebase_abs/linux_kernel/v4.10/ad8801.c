static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned char V_4 )
{
V_2 -> V_5 = F_2 ( ( V_3 << V_6 ) | V_4 ) ;
return F_3 ( V_2 -> V_7 , & V_2 -> V_5 , sizeof( V_2 -> V_5 ) ) ;
}
static int F_4 ( struct V_8 * V_9 ,
struct V_10 const * V_11 , int V_12 , int V_13 , long V_14 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
int V_15 ;
switch ( V_14 ) {
case V_16 :
if ( V_12 >= 256 || V_12 < 0 )
return - V_17 ;
V_15 = F_1 ( V_2 , V_11 -> V_3 , V_12 ) ;
if ( V_15 == 0 )
V_2 -> V_18 [ V_11 -> V_3 ] = V_12 ;
break;
default:
V_15 = - V_17 ;
}
return V_15 ;
}
static int F_6 ( struct V_8 * V_9 ,
struct V_10 const * V_11 , int * V_12 , int * V_13 , long V_19 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
switch ( V_19 ) {
case V_16 :
* V_12 = V_2 -> V_18 [ V_11 -> V_3 ] ;
return V_20 ;
case V_21 :
* V_12 = V_2 -> V_22 - V_2 -> V_23 ;
* V_13 = 8 ;
return V_24 ;
case V_25 :
* V_12 = V_2 -> V_23 ;
return V_20 ;
default:
return - V_17 ;
}
return - V_17 ;
}
static int F_7 ( struct V_26 * V_7 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 ;
const struct V_27 * V_28 ;
int V_15 ;
V_9 = F_8 ( & V_7 -> V_29 , sizeof( * V_2 ) ) ;
if ( V_9 == NULL )
return - V_30 ;
V_2 = F_5 ( V_9 ) ;
V_2 -> V_7 = V_7 ;
V_28 = F_9 ( V_7 ) ;
V_2 -> V_31 = F_10 ( & V_7 -> V_29 , L_1 ) ;
if ( F_11 ( V_2 -> V_31 ) ) {
F_12 ( & V_7 -> V_29 , L_2 ) ;
return F_13 ( V_2 -> V_31 ) ;
}
V_15 = F_14 ( V_2 -> V_31 ) ;
if ( V_15 ) {
F_12 ( & V_7 -> V_29 , L_3 ,
V_15 ) ;
return V_15 ;
}
V_15 = F_15 ( V_2 -> V_31 ) ;
if ( V_15 < 0 ) {
F_12 ( & V_7 -> V_29 , L_4 ,
V_15 ) ;
goto V_32;
}
V_2 -> V_22 = V_15 / 1000 ;
if ( V_28 -> V_33 == V_34 ) {
V_2 -> V_35 = F_10 ( & V_7 -> V_29 , L_5 ) ;
if ( F_11 ( V_2 -> V_35 ) ) {
F_12 ( & V_7 -> V_29 , L_6 ) ;
V_15 = F_13 ( V_2 -> V_35 ) ;
goto V_32;
}
V_15 = F_14 ( V_2 -> V_35 ) ;
if ( V_15 ) {
F_12 ( & V_7 -> V_29 , L_7 ,
V_15 ) ;
goto V_32;
}
V_15 = F_15 ( V_2 -> V_35 ) ;
if ( V_15 < 0 ) {
F_12 ( & V_7 -> V_29 , L_8 ,
V_15 ) ;
goto V_36;
}
V_2 -> V_23 = V_15 / 1000 ;
} else {
V_2 -> V_23 = 0 ;
V_2 -> V_35 = NULL ;
}
F_16 ( V_7 , V_9 ) ;
V_9 -> V_29 . V_37 = & V_7 -> V_29 ;
V_9 -> V_19 = & V_38 ;
V_9 -> V_39 = V_40 ;
V_9 -> V_41 = V_42 ;
V_9 -> V_43 = F_17 ( V_42 ) ;
V_9 -> V_44 = V_28 -> V_44 ;
V_15 = F_18 ( V_9 ) ;
if ( V_15 ) {
F_12 ( & V_7 -> V_29 , L_9 ,
V_15 ) ;
goto V_36;
}
return 0 ;
V_36:
if ( V_2 -> V_35 )
F_19 ( V_2 -> V_35 ) ;
V_32:
F_19 ( V_2 -> V_31 ) ;
return V_15 ;
}
static int F_20 ( struct V_26 * V_7 )
{
struct V_8 * V_9 = F_21 ( V_7 ) ;
struct V_1 * V_2 = F_5 ( V_9 ) ;
F_22 ( V_9 ) ;
if ( V_2 -> V_35 )
F_19 ( V_2 -> V_35 ) ;
F_19 ( V_2 -> V_31 ) ;
return 0 ;
}
