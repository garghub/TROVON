static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ( V_3 & V_5 ) !=
V_6 )
return - V_7 ;
V_3 = F_3 ( V_2 , V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ( V_3 & V_9 ) !=
V_10 ) {
F_4 ( & V_2 -> V_11 , L_1 ) ;
return - V_7 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_6 ( V_2 , V_12 ,
V_13 ) ;
}
static int F_7 ( struct V_14 * V_15 )
{
int V_3 , V_16 = 11 ;
while ( V_16 -- > 0 ) {
V_3 = F_2 ( V_15 -> V_2 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ( V_3 & V_17 ) || V_16 == 0 )
break;
F_8 ( 100 ) ;
}
if ( ! ( V_3 & V_17 ) )
return - V_7 ;
return F_9 ( V_15 -> V_2 ,
V_18 , 8 ,
( char * ) & V_15 -> V_19 ) ;
}
static int F_10 ( struct V_20 * V_21 ,
struct V_22 const * V_23 ,
int * V_24 , int * V_25 , long V_26 )
{
struct V_14 * V_15 = F_11 ( V_21 ) ;
int V_3 ;
switch ( V_26 ) {
case V_27 :
F_12 ( & V_15 -> V_28 ) ;
V_3 = F_7 ( V_15 ) ;
if ( V_3 < 0 ) {
F_13 ( & V_15 -> V_28 ) ;
return V_3 ;
}
switch ( V_23 -> type ) {
case V_29 :
* V_24 = F_14 ( V_15 -> V_19 . V_30 ) &
V_31 ;
V_3 = V_32 ;
break;
case V_33 :
* V_24 = F_14 ( V_15 -> V_19 . V_30 ) >> 10 ;
V_3 = V_32 ;
break;
case V_34 :
switch ( V_23 -> V_35 ) {
case V_36 :
* V_24 = F_14 ( V_15 -> V_19 . V_37 ) ;
V_3 = V_32 ;
break;
case V_38 :
* V_24 = F_14 ( V_15 -> V_19 . V_39 ) ;
V_3 = V_32 ;
break;
default:
V_3 = - V_40 ;
}
break;
default:
V_3 = - V_40 ;
}
F_13 ( & V_15 -> V_28 ) ;
return V_3 ;
case V_41 :
switch ( V_23 -> type ) {
case V_29 :
* V_24 = 1 ;
* V_25 = 612903 ;
return V_42 ;
case V_33 :
* V_24 = 0 ;
* V_25 = 1000 ;
return V_42 ;
case V_34 :
switch ( V_23 -> V_35 ) {
case V_36 :
* V_24 = 0 ;
* V_25 = 12834 ;
return V_42 ;
case V_38 :
* V_24 = 0 ;
* V_25 = 84246 ;
return V_42 ;
default:
return - V_40 ;
}
default:
return - V_40 ;
}
case V_43 :
if ( ! ( V_23 -> type == V_34 &&
V_23 -> V_35 == V_36 ) )
return - V_40 ;
* V_24 = - 400 ;
return V_32 ;
default:
return - V_40 ;
}
}
static T_1 F_15 ( int V_44 , void * V_45 )
{
struct V_46 * V_47 = V_45 ;
struct V_20 * V_21 = V_47 -> V_21 ;
struct V_14 * V_15 = F_11 ( V_21 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
T_2 V_48 [ 8 ] ;
int V_3 ;
V_3 = F_9 ( V_2 , V_18 , 4 ,
( V_49 * ) & V_48 ) ;
if ( V_3 != 4 ) {
F_4 ( & V_2 -> V_11 , L_2 ) ;
goto V_50;
}
F_16 ( V_21 , V_48 ,
F_17 ( V_21 ) ) ;
V_50:
F_18 ( V_21 -> V_51 ) ;
return V_52 ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_53 * V_54 )
{
struct V_20 * V_21 ;
struct V_14 * V_15 ;
int V_3 ;
if ( ! F_20 ( V_2 -> V_55 , V_56
| V_57
| V_58 ) )
return - V_59 ;
V_3 = F_2 ( V_2 , V_60 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 != V_61 ) {
F_4 ( & V_2 -> V_11 , L_3 ) ;
return - V_62 ;
}
V_3 = F_2 ( V_2 , V_63 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ( V_3 & V_64 ) != V_65 ) {
F_4 ( & V_2 -> V_11 , L_4 ) ;
return - V_62 ;
}
V_21 = F_21 ( & V_2 -> V_11 , sizeof( * V_15 ) ) ;
if ( ! V_21 )
return - V_66 ;
V_3 = F_5 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_15 = F_11 ( V_21 ) ;
F_22 ( V_2 , V_21 ) ;
V_15 -> V_2 = V_2 ;
F_23 ( & V_15 -> V_28 ) ;
V_21 -> V_11 . V_67 = & V_2 -> V_11 ;
V_21 -> V_68 = V_54 -> V_68 ;
V_21 -> V_69 = & V_70 ;
V_21 -> V_71 = V_72 ;
V_21 -> V_73 = F_24 ( V_72 ) ;
V_3 = F_25 ( V_21 , NULL ,
F_15 , NULL ) ;
if ( V_3 < 0 ) {
F_4 ( & V_2 -> V_11 , L_5 ) ;
goto V_74;
}
V_3 = F_26 ( V_21 ) ;
if ( V_3 < 0 ) {
F_4 ( & V_2 -> V_11 , L_6 ) ;
goto V_75;
}
return 0 ;
V_75:
F_27 ( V_21 ) ;
V_74:
F_6 ( V_2 , V_12 , V_76 ) ;
return V_3 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_29 ( V_2 ) ;
F_30 ( V_21 ) ;
F_27 ( V_21 ) ;
return F_6 ( V_2 , V_12 ,
V_76 ) ;
}
