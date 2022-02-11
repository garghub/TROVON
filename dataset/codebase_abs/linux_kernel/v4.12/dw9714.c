static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 V_5 ;
const int V_6 = 1 ;
int V_7 ;
T_1 V_8 ;
V_8 = F_2 ( V_3 ) ;
V_5 . V_9 = V_10 ;
V_5 . V_11 = 0 ;
V_5 . V_12 = V_13 ;
V_5 . V_14 = ( V_15 * ) & V_8 ;
V_7 = F_3 ( V_2 -> V_16 , & V_5 , 1 ) ;
return V_7 == V_6 ? 0 : - V_17 ;
}
int F_4 ( struct V_18 * V_19 )
{
int V_7 ;
V_7 = V_20 . V_21 -> V_22 ( V_19 , 1 ) ;
F_5 ( 12000 , 12500 ) ;
return V_7 ;
}
int F_6 ( struct V_18 * V_19 )
{
return V_20 . V_21 -> V_22 ( V_19 , 0 ) ;
}
int F_7 ( struct V_18 * V_19 , T_1 V_8 )
{
struct V_1 * V_2 = F_8 ( V_19 ) ;
int V_7 = - V_23 ;
V_15 V_24 = F_9 ( V_20 . V_25 . V_26 ) ;
V_15 V_27 = F_10 ( V_20 . V_25 . V_26 ) ;
switch ( V_20 . V_28 ) {
case V_29 :
if ( V_20 . V_25 . V_30 ) {
V_7 = F_1 ( V_2 , V_31 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 , V_32 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 , V_33 ) ;
if ( V_7 )
return V_7 ;
V_20 . V_25 . V_30 = false ;
}
V_7 = F_1 ( V_2 ,
F_11 ( V_8 , V_34 ) ) ;
break;
case V_35 :
if ( V_20 . V_25 . V_30 ) {
V_7 = F_1 ( V_2 , V_31 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 ,
F_12 ( V_36 , V_24 ) ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 ,
F_13 ( V_20 . V_25 . V_37 ) ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 , V_33 ) ;
if ( V_7 )
return V_7 ;
V_20 . V_25 . V_30 = false ;
}
V_7 = F_1 ( V_2 , F_11 ( V_8 , V_27 ) ) ;
break;
case V_38 :
if ( V_20 . V_25 . V_30 ) {
V_7 = F_1 ( V_2 , V_31 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 ,
F_12 ( V_39 , V_24 ) ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 ,
F_13 ( V_20 . V_25 . V_37 ) ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 , V_33 ) ;
if ( V_7 )
return V_7 ;
V_20 . V_25 . V_30 = false ;
}
V_7 = F_1 ( V_2 ,
F_11 ( V_8 , V_34 ) ) ;
break;
}
return V_7 ;
}
int F_14 ( struct V_18 * V_19 , T_2 V_40 )
{
int V_7 ;
V_40 = F_15 ( V_40 , 0 , V_41 ) ;
V_7 = F_7 ( V_19 , V_40 ) ;
if ( V_7 == 0 ) {
V_20 . V_42 = V_40 - V_20 . V_43 ;
V_20 . V_43 = V_40 ;
F_16 ( & ( V_20 . V_44 ) ) ;
}
return V_7 ;
}
int F_17 ( struct V_18 * V_19 )
{
int V_7 ;
V_7 = F_7 ( V_19 , V_45 ) ;
if ( V_7 == 0 ) {
V_20 . V_42 =
V_45 - V_20 . V_43 ;
V_20 . V_43 = V_45 ;
F_16 ( & ( V_20 . V_44 ) ) ;
}
return V_7 ;
}
int F_18 ( struct V_18 * V_19 , T_2 V_40 )
{
return F_14 ( V_19 , V_20 . V_43 + V_40 ) ;
}
int F_19 ( struct V_18 * V_19 , T_2 * V_40 )
{
T_3 V_46 = 0 ;
struct V_47 V_48 ;
const struct V_47 V_49 = {
0 ,
F_20 ( T_3 , abs ( V_20 . V_42 ) * V_50 ,
V_51 ) ,
} ;
F_21 ( & V_48 ) ;
V_48 = F_22 ( V_48 , ( V_20 . V_44 ) ) ;
if ( F_23 ( & V_48 , & V_49 ) <= 0 ) {
V_46 |= V_52 ;
V_46 |= V_53 ;
} else {
V_46 |= V_54 ;
V_46 |= V_55 ;
}
* V_40 = V_46 ;
return 0 ;
}
int F_24 ( struct V_18 * V_19 , T_2 * V_40 )
{
T_2 V_8 ;
F_19 ( V_19 , & V_8 ) ;
if ( V_8 & V_52 )
* V_40 = V_20 . V_43 - V_20 . V_42 ;
else
* V_40 = V_20 . V_43 ;
return 0 ;
}
int F_25 ( struct V_18 * V_19 , T_2 V_40 )
{
V_20 . V_25 . V_26 = V_40 ;
V_20 . V_25 . V_30 = true ;
return 0 ;
}
int F_26 ( struct V_18 * V_19 , T_2 V_40 )
{
V_20 . V_25 . V_37 = V_40 ;
V_20 . V_25 . V_30 = true ;
return 0 ;
}
int F_27 ( struct V_18 * V_19 )
{
V_20 . V_28 = V_29 ;
V_20 . V_25 . V_30 = false ;
V_20 . V_21 = F_28 () ;
return ( NULL == V_20 . V_21 ) ? - V_56 : 0 ;
}
