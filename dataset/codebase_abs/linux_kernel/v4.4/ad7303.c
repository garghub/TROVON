static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 )
{
V_2 -> V_5 = F_2 ( V_6 |
( V_3 << V_7 ) |
V_2 -> V_8 | V_4 ) ;
return F_3 ( V_2 -> V_9 , & V_2 -> V_5 , sizeof( V_2 -> V_5 ) ) ;
}
static T_2 F_4 ( struct V_10 * V_11 ,
T_3 V_12 , const struct V_13 * V_3 , char * V_14 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
return sprintf ( V_14 , L_1 , ( bool ) ( V_2 -> V_8 &
F_6 ( V_3 -> V_15 ) ) ) ;
}
static T_2 F_7 ( struct V_10 * V_11 ,
T_3 V_12 , const struct V_13 * V_3 , const char * V_14 ,
T_4 V_16 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
bool V_17 ;
int V_18 ;
V_18 = F_8 ( V_14 , & V_17 ) ;
if ( V_18 )
return V_18 ;
F_9 ( & V_11 -> V_19 ) ;
if ( V_17 )
V_2 -> V_8 |= F_6 ( V_3 -> V_15 ) ;
else
V_2 -> V_8 &= ~ F_6 ( V_3 -> V_15 ) ;
F_1 ( V_2 , V_3 -> V_15 , V_2 -> V_20 [ V_3 -> V_15 ] ) ;
F_10 ( & V_11 -> V_19 ) ;
return V_16 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_13 const * V_3 )
{
int V_18 ;
if ( V_2 -> V_8 & V_21 )
return F_12 ( V_2 -> V_22 ) ;
V_18 = F_12 ( V_2 -> V_23 ) ;
if ( V_18 < 0 )
return V_18 ;
return V_18 / 2 ;
}
static int F_13 ( struct V_10 * V_11 ,
struct V_13 const * V_3 , int * V_4 , int * V_24 , long V_25 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
int V_26 ;
switch ( V_25 ) {
case V_27 :
* V_4 = V_2 -> V_20 [ V_3 -> V_15 ] ;
return V_28 ;
case V_29 :
V_26 = F_11 ( V_2 , V_3 ) ;
if ( V_26 < 0 )
return V_26 ;
* V_4 = 2 * V_26 / 1000 ;
* V_24 = V_3 -> V_30 . V_31 ;
return V_32 ;
default:
break;
}
return - V_33 ;
}
static int F_14 ( struct V_10 * V_11 ,
struct V_13 const * V_3 , int V_4 , int V_24 , long V_34 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
int V_18 ;
switch ( V_34 ) {
case V_27 :
if ( V_4 >= ( 1 << V_3 -> V_30 . V_31 ) || V_4 < 0 )
return - V_33 ;
F_9 ( & V_11 -> V_19 ) ;
V_18 = F_1 ( V_2 , V_3 -> V_35 , V_4 ) ;
if ( V_18 == 0 )
V_2 -> V_20 [ V_3 -> V_15 ] = V_4 ;
F_10 ( & V_11 -> V_19 ) ;
break;
default:
V_18 = - V_33 ;
}
return V_18 ;
}
static int F_15 ( struct V_36 * V_9 )
{
const struct V_37 * V_38 = F_16 ( V_9 ) ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
bool V_39 ;
int V_18 ;
V_11 = F_17 ( & V_9 -> V_40 , sizeof( * V_2 ) ) ;
if ( V_11 == NULL )
return - V_41 ;
V_2 = F_5 ( V_11 ) ;
F_18 ( V_9 , V_11 ) ;
V_2 -> V_9 = V_9 ;
V_2 -> V_23 = F_19 ( & V_9 -> V_40 , L_2 ) ;
if ( F_20 ( V_2 -> V_23 ) )
return F_21 ( V_2 -> V_23 ) ;
V_18 = F_22 ( V_2 -> V_23 ) ;
if ( V_18 )
return V_18 ;
if ( V_9 -> V_40 . V_42 ) {
V_39 = F_23 ( V_9 -> V_40 . V_42 ,
L_3 ) ;
} else {
struct V_43 * V_44 = V_9 -> V_40 . V_45 ;
if ( V_44 && V_44 -> V_46 )
V_39 = true ;
else
V_39 = false ;
}
if ( V_39 ) {
V_2 -> V_22 = F_19 ( & V_9 -> V_40 , L_4 ) ;
if ( F_20 ( V_2 -> V_22 ) ) {
V_18 = F_21 ( V_2 -> V_22 ) ;
goto V_47;
}
V_18 = F_22 ( V_2 -> V_22 ) ;
if ( V_18 )
goto V_47;
V_2 -> V_8 |= V_21 ;
}
V_11 -> V_40 . V_48 = & V_9 -> V_40 ;
V_11 -> V_49 = V_38 -> V_49 ;
V_11 -> V_25 = & V_50 ;
V_11 -> V_51 = V_52 ;
V_11 -> V_53 = V_54 ;
V_11 -> V_55 = F_24 ( V_54 ) ;
V_18 = F_25 ( V_11 ) ;
if ( V_18 )
goto V_56;
return 0 ;
V_56:
if ( V_2 -> V_22 )
F_26 ( V_2 -> V_22 ) ;
V_47:
F_26 ( V_2 -> V_23 ) ;
return V_18 ;
}
static int F_27 ( struct V_36 * V_9 )
{
struct V_10 * V_11 = F_28 ( V_9 ) ;
struct V_1 * V_2 = F_5 ( V_11 ) ;
F_29 ( V_11 ) ;
if ( V_2 -> V_22 )
F_26 ( V_2 -> V_22 ) ;
F_26 ( V_2 -> V_23 ) ;
return 0 ;
}
