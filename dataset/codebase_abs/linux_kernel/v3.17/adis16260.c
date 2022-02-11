static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 ;
T_1 V_5 = V_6 ;
V_4 = F_3 ( V_3 , V_7 , V_5 ) ;
if ( V_4 )
F_4 ( & V_2 -> V_8 , L_1 ) ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_9 const * V_10 ,
int * V_5 , int * V_11 ,
long V_12 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 ;
T_2 V_13 ;
T_3 V_14 ;
switch ( V_12 ) {
case V_15 :
return F_6 ( V_2 , V_10 ,
V_16 , V_5 ) ;
case V_17 :
switch ( V_10 -> type ) {
case V_18 :
* V_5 = 0 ;
if ( F_7 ( V_3 -> V_19 ) -> V_20 ) {
* V_11 = F_8 ( 18320 ) ;
} else {
* V_11 = F_8 ( 73260 ) ;
}
return V_21 ;
case V_22 :
* V_5 = 0 ;
* V_11 = F_8 ( 36630 ) ;
return V_21 ;
case V_23 :
if ( V_10 -> V_24 == 0 ) {
* V_5 = 1 ;
* V_11 = 831500 ;
} else {
* V_5 = 0 ;
* V_11 = 610500 ;
}
return V_21 ;
case V_25 :
* V_5 = 145 ;
* V_11 = 300000 ;
return V_21 ;
default:
return - V_26 ;
}
case V_27 :
* V_5 = 250000 / 1453 ;
return V_28 ;
case V_29 :
V_13 = V_30 [ V_10 -> V_31 ] [ 0 ] ;
V_4 = F_9 ( V_3 , V_13 , & V_14 ) ;
if ( V_4 )
return V_4 ;
* V_5 = F_10 ( V_14 , 11 ) ;
return V_28 ;
case V_32 :
V_13 = V_30 [ V_10 -> V_31 ] [ 1 ] ;
V_4 = F_9 ( V_3 , V_13 , & V_14 ) ;
if ( V_4 )
return V_4 ;
* V_5 = V_14 ;
return V_28 ;
case V_33 :
V_4 = F_9 ( V_3 , V_34 , & V_14 ) ;
if ( V_4 )
return V_4 ;
if ( F_7 ( V_3 -> V_19 ) -> V_20 )
* V_5 = ( V_14 & V_35 ) ?
8 : 256 ;
else
* V_5 = ( V_14 & V_35 ) ?
66 : 2048 ;
* V_5 /= ( V_14 & V_36 ) + 1 ;
return V_28 ;
}
return - V_26 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_9 const * V_10 ,
int V_5 ,
int V_11 ,
long V_12 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 ;
T_2 V_13 ;
T_2 V_37 ;
switch ( V_12 ) {
case V_29 :
if ( V_5 < - 2048 || V_5 >= 2048 )
return - V_26 ;
V_13 = V_30 [ V_10 -> V_31 ] [ 0 ] ;
return F_3 ( V_3 , V_13 , V_5 ) ;
case V_32 :
if ( V_5 < 0 || V_5 >= 4096 )
return - V_26 ;
V_13 = V_30 [ V_10 -> V_31 ] [ 1 ] ;
return F_3 ( V_3 , V_13 , V_5 ) ;
case V_33 :
F_12 ( & V_2 -> V_38 ) ;
if ( F_7 ( V_3 -> V_19 ) -> V_20 )
V_37 = 256 / V_5 ;
else
V_37 = 2048 / V_5 ;
if ( V_37 > V_36 )
V_37 = V_36 ;
else if ( V_37 > 0 )
V_37 -- ;
if ( V_37 >= 0x0A )
V_3 -> V_19 -> V_39 = V_40 ;
else
V_3 -> V_19 -> V_39 = V_41 ;
V_4 = F_13 ( V_3 , V_34 , V_37 ) ;
F_14 ( & V_2 -> V_38 ) ;
return V_4 ;
}
return - V_26 ;
}
static int F_15 ( struct V_42 * V_19 )
{
struct V_1 * V_2 ;
struct V_3 * V_3 ;
int V_4 ;
V_2 = F_16 ( & V_19 -> V_8 , sizeof( * V_3 ) ) ;
if ( ! V_2 )
return - V_43 ;
V_3 = F_2 ( V_2 ) ;
F_17 ( V_19 , V_2 ) ;
V_2 -> V_44 = F_7 ( V_19 ) -> V_44 ;
V_2 -> V_8 . V_45 = & V_19 -> V_8 ;
V_2 -> V_46 = & V_47 ;
V_2 -> V_48 = V_49 ;
V_2 -> V_50 = F_18 ( V_49 ) ;
V_2 -> V_51 = V_52 ;
V_4 = F_19 ( V_3 , V_2 , V_19 , & V_53 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_20 ( V_3 , V_2 , NULL ) ;
if ( V_4 )
return V_4 ;
V_4 = F_21 ( V_3 ) ;
if ( V_4 )
goto V_54;
V_4 = F_22 ( V_2 ) ;
if ( V_4 )
goto V_54;
return 0 ;
V_54:
F_23 ( V_3 , V_2 ) ;
return V_4 ;
}
static int F_24 ( struct V_42 * V_19 )
{
struct V_1 * V_2 = F_25 ( V_19 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_26 ( V_2 ) ;
F_1 ( V_2 ) ;
F_23 ( V_3 , V_2 ) ;
return 0 ;
}
