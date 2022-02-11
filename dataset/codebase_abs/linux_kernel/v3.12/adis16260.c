static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_8 = F_3 ( V_7 ) ;
int V_9 , V_10 = 0 ;
T_2 V_11 ;
int V_12 ;
V_9 = F_4 ( V_8 , V_13 , & V_11 ) ;
if ( V_9 )
return V_9 ;
if ( F_5 ( V_8 -> V_14 ) -> V_15 )
V_12 = ( V_11 & V_16 ) ? 8 : 256 ;
else
V_12 = ( V_11 & V_16 ) ? 66 : 2048 ;
V_12 /= ( V_11 & V_17 ) + 1 ;
V_10 = sprintf ( V_5 , L_1 , V_12 ) ;
return V_10 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_3 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_8 = F_3 ( V_7 ) ;
unsigned int V_18 ;
int V_9 ;
T_4 V_11 ;
V_9 = F_7 ( V_5 , 10 , & V_18 ) ;
if ( V_9 )
return V_9 ;
F_8 ( & V_7 -> V_19 ) ;
if ( F_5 ( V_8 -> V_14 ) -> V_15 )
V_11 = 256 / V_18 ;
else
V_11 = 2048 / V_18 ;
if ( V_11 > V_17 )
V_11 = V_17 ;
else if ( V_11 > 0 )
V_11 -- ;
if ( V_11 >= 0x0A )
V_8 -> V_14 -> V_20 = V_21 ;
else
V_8 -> V_14 -> V_20 = V_22 ;
V_9 = F_9 ( V_8 , V_13 , V_11 ) ;
F_10 ( & V_7 -> V_19 ) ;
return V_9 ? V_9 : V_10 ;
}
static int F_11 ( struct V_6 * V_7 )
{
struct V_8 * V_8 = F_3 ( V_7 ) ;
int V_9 ;
T_2 V_18 = V_23 ;
V_9 = F_12 ( V_8 , V_24 , V_18 ) ;
if ( V_9 )
F_13 ( & V_7 -> V_2 , L_2 ) ;
return V_9 ;
}
static int F_14 ( struct V_6 * V_7 ,
struct V_25 const * V_26 ,
int * V_18 , int * V_27 ,
long V_28 )
{
struct V_8 * V_8 = F_3 ( V_7 ) ;
int V_9 ;
T_4 V_29 ;
T_5 V_30 ;
switch ( V_28 ) {
case V_31 :
return F_15 ( V_7 , V_26 ,
V_32 , V_18 ) ;
case V_33 :
switch ( V_26 -> type ) {
case V_34 :
* V_18 = 0 ;
if ( F_5 ( V_8 -> V_14 ) -> V_15 ) {
* V_27 = F_16 ( 18320 ) ;
} else {
* V_27 = F_16 ( 73260 ) ;
}
return V_35 ;
case V_36 :
* V_18 = 0 ;
* V_27 = F_16 ( 36630 ) ;
return V_35 ;
case V_37 :
if ( V_26 -> V_38 == 0 ) {
* V_18 = 1 ;
* V_27 = 831500 ;
} else {
* V_18 = 0 ;
* V_27 = 610500 ;
}
return V_35 ;
case V_39 :
* V_18 = 145 ;
* V_27 = 300000 ;
return V_35 ;
default:
return - V_40 ;
}
break;
case V_41 :
* V_18 = 250000 / 1453 ;
return V_42 ;
case V_43 :
V_29 = V_44 [ V_26 -> V_45 ] [ 0 ] ;
V_9 = F_4 ( V_8 , V_29 , & V_30 ) ;
if ( V_9 )
return V_9 ;
* V_18 = F_17 ( V_30 , 11 ) ;
return V_42 ;
case V_46 :
V_29 = V_44 [ V_26 -> V_45 ] [ 1 ] ;
V_9 = F_4 ( V_8 , V_29 , & V_30 ) ;
if ( V_9 )
return V_9 ;
* V_18 = V_30 ;
return V_42 ;
}
return - V_40 ;
}
static int F_18 ( struct V_6 * V_7 ,
struct V_25 const * V_26 ,
int V_18 ,
int V_27 ,
long V_28 )
{
struct V_8 * V_8 = F_3 ( V_7 ) ;
T_4 V_29 ;
switch ( V_28 ) {
case V_43 :
if ( V_18 < - 2048 || V_18 >= 2048 )
return - V_40 ;
V_29 = V_44 [ V_26 -> V_45 ] [ 0 ] ;
return F_12 ( V_8 , V_29 , V_18 ) ;
case V_46 :
if ( V_18 < 0 || V_18 >= 4096 )
return - V_40 ;
V_29 = V_44 [ V_26 -> V_45 ] [ 1 ] ;
return F_12 ( V_8 , V_29 , V_18 ) ;
}
return - V_40 ;
}
static int F_19 ( struct V_47 * V_14 )
{
struct V_6 * V_7 ;
struct V_8 * V_8 ;
int V_9 ;
V_7 = F_20 ( & V_14 -> V_2 , sizeof( * V_8 ) ) ;
if ( ! V_7 )
return - V_48 ;
V_8 = F_3 ( V_7 ) ;
F_21 ( V_14 , V_7 ) ;
V_7 -> V_49 = F_5 ( V_14 ) -> V_49 ;
V_7 -> V_2 . V_50 = & V_14 -> V_2 ;
V_7 -> V_51 = & V_52 ;
V_7 -> V_53 = V_54 ;
V_7 -> V_55 = F_22 ( V_54 ) ;
V_7 -> V_56 = V_57 ;
V_9 = F_23 ( V_8 , V_7 , V_14 , & V_58 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_24 ( V_8 , V_7 , NULL ) ;
if ( V_9 )
return V_9 ;
V_9 = F_25 ( V_8 ) ;
if ( V_9 )
goto V_59;
V_9 = F_26 ( V_7 ) ;
if ( V_9 )
goto V_59;
return 0 ;
V_59:
F_27 ( V_8 , V_7 ) ;
return V_9 ;
}
static int F_28 ( struct V_47 * V_14 )
{
struct V_6 * V_7 = F_29 ( V_14 ) ;
struct V_8 * V_8 = F_3 ( V_7 ) ;
F_30 ( V_7 ) ;
F_11 ( V_7 ) ;
F_27 ( V_8 , V_7 ) ;
return 0 ;
}
