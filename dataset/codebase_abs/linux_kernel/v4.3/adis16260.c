static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 ;
T_1 V_5 = V_6 ;
V_4 = F_3 ( & V_3 -> V_7 , V_8 , V_5 ) ;
if ( V_4 )
F_4 ( & V_2 -> V_9 , L_1 ) ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_10 const * V_11 ,
int * V_5 , int * V_12 ,
long V_13 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
const struct V_14 * V_15 = V_3 -> V_15 ;
struct V_7 * V_7 = & V_3 -> V_7 ;
int V_4 ;
T_2 V_16 ;
T_3 V_17 ;
switch ( V_13 ) {
case V_18 :
return F_6 ( V_2 , V_11 ,
V_19 , V_5 ) ;
case V_20 :
switch ( V_11 -> type ) {
case V_21 :
* V_5 = V_15 -> V_22 ;
* V_12 = V_15 -> V_23 ;
return V_24 ;
case V_25 :
* V_5 = 0 ;
* V_12 = F_7 ( 36630 ) ;
return V_26 ;
case V_27 :
if ( V_11 -> V_28 == 0 ) {
* V_5 = 1 ;
* V_12 = 831500 ;
} else {
* V_5 = 0 ;
* V_12 = 610500 ;
}
return V_26 ;
case V_29 :
* V_5 = 145 ;
* V_12 = 300000 ;
return V_26 ;
default:
return - V_30 ;
}
case V_31 :
* V_5 = 250000 / 1453 ;
return V_32 ;
case V_33 :
V_16 = V_34 [ V_11 -> V_35 ] [ 0 ] ;
V_4 = F_8 ( V_7 , V_16 , & V_17 ) ;
if ( V_4 )
return V_4 ;
* V_5 = F_9 ( V_17 , 11 ) ;
return V_32 ;
case V_36 :
V_16 = V_34 [ V_11 -> V_35 ] [ 1 ] ;
V_4 = F_8 ( V_7 , V_16 , & V_17 ) ;
if ( V_4 )
return V_4 ;
* V_5 = V_17 ;
return V_32 ;
case V_37 :
V_4 = F_8 ( V_7 , V_38 , & V_17 ) ;
if ( V_4 )
return V_4 ;
if ( F_10 ( V_7 -> V_39 ) -> V_40 )
* V_5 = ( V_17 & V_41 ) ?
8 : 256 ;
else
* V_5 = ( V_17 & V_41 ) ?
66 : 2048 ;
* V_5 /= ( V_17 & V_42 ) + 1 ;
return V_32 ;
}
return - V_30 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_10 const * V_11 ,
int V_5 ,
int V_12 ,
long V_13 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_7 * V_7 = & V_3 -> V_7 ;
int V_4 ;
T_2 V_16 ;
T_2 V_43 ;
switch ( V_13 ) {
case V_33 :
if ( V_5 < - 2048 || V_5 >= 2048 )
return - V_30 ;
V_16 = V_34 [ V_11 -> V_35 ] [ 0 ] ;
return F_3 ( V_7 , V_16 , V_5 ) ;
case V_36 :
if ( V_5 < 0 || V_5 >= 4096 )
return - V_30 ;
V_16 = V_34 [ V_11 -> V_35 ] [ 1 ] ;
return F_3 ( V_7 , V_16 , V_5 ) ;
case V_37 :
F_12 ( & V_2 -> V_44 ) ;
if ( F_10 ( V_7 -> V_39 ) -> V_40 )
V_43 = 256 / V_5 ;
else
V_43 = 2048 / V_5 ;
if ( V_43 > V_42 )
V_43 = V_42 ;
else if ( V_43 > 0 )
V_43 -- ;
if ( V_43 >= 0x0A )
V_7 -> V_39 -> V_45 = V_46 ;
else
V_7 -> V_39 -> V_45 = V_47 ;
V_4 = F_13 ( V_7 , V_38 , V_43 ) ;
F_14 ( & V_2 -> V_44 ) ;
return V_4 ;
}
return - V_30 ;
}
static int F_15 ( struct V_48 * V_39 )
{
const struct V_49 * V_50 ;
struct V_3 * V_3 ;
struct V_1 * V_2 ;
int V_4 ;
V_50 = F_10 ( V_39 ) ;
if ( ! V_50 )
return - V_51 ;
V_2 = F_16 ( & V_39 -> V_9 , sizeof( * V_3 ) ) ;
if ( ! V_2 )
return - V_52 ;
V_3 = F_2 ( V_2 ) ;
F_17 ( V_39 , V_2 ) ;
V_3 -> V_15 = & V_53 [ V_50 -> V_40 ] ;
V_2 -> V_54 = V_50 -> V_54 ;
V_2 -> V_9 . V_55 = & V_39 -> V_9 ;
V_2 -> V_15 = & V_56 ;
V_2 -> V_57 = V_3 -> V_15 -> V_57 ;
V_2 -> V_58 = V_3 -> V_15 -> V_58 ;
V_2 -> V_59 = V_60 ;
V_4 = F_18 ( & V_3 -> V_7 , V_2 , V_39 , & V_61 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_19 ( & V_3 -> V_7 , V_2 , NULL ) ;
if ( V_4 )
return V_4 ;
V_4 = F_20 ( & V_3 -> V_7 ) ;
if ( V_4 )
goto V_62;
V_4 = F_21 ( V_2 ) ;
if ( V_4 )
goto V_62;
return 0 ;
V_62:
F_22 ( & V_3 -> V_7 , V_2 ) ;
return V_4 ;
}
static int F_23 ( struct V_48 * V_39 )
{
struct V_1 * V_2 = F_24 ( V_39 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_25 ( V_2 ) ;
F_1 ( V_2 ) ;
F_22 ( & V_3 -> V_7 , V_2 ) ;
return 0 ;
}
