static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = 15 ;
V_3 = F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 | V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
while ( V_4 -- > 0 ) {
V_3 = F_3 ( V_2 -> V_5 , V_6 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ! ( V_3 & V_8 ) )
break;
F_4 ( 20 ) ;
}
if ( V_4 < 0 ) {
F_5 ( & V_2 -> V_5 -> V_9 , L_1 ) ;
return - V_10 ;
}
return 0 ;
}
static int F_6 ( struct V_11 * V_12 ,
struct V_13 const * V_14 ,
int * V_15 , int * V_16 , long V_17 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_18 = 0 ;
int V_3 ;
switch ( V_17 ) {
case V_19 :
if ( F_8 ( V_12 ) )
return - V_20 ;
switch ( V_14 -> type ) {
case V_21 :
F_9 ( & V_2 -> V_22 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_10 ( & V_2 -> V_22 ) ;
return V_3 ;
}
V_3 = F_11 ( V_2 -> V_5 ,
V_23 , 3 , ( V_24 * ) & V_18 ) ;
F_10 ( & V_2 -> V_22 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_15 = F_12 ( V_18 ) >> 12 ;
return V_25 ;
case V_26 :
F_9 ( & V_2 -> V_22 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_10 ( & V_2 -> V_22 ) ;
return V_3 ;
}
V_3 = F_11 ( V_2 -> V_5 ,
V_27 , 2 , ( V_24 * ) & V_18 ) ;
F_10 ( & V_2 -> V_22 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_15 = F_13 ( F_12 ( V_18 ) >> 20 , 11 ) ;
return V_25 ;
default:
return - V_28 ;
}
case V_29 :
switch ( V_14 -> type ) {
case V_21 :
* V_15 = 0 ;
* V_16 = 250 ;
return V_30 ;
case V_26 :
* V_15 = 0 ;
* V_16 = 62500 ;
return V_30 ;
default:
return - V_28 ;
}
}
return - V_28 ;
}
static T_2 F_14 ( int V_31 , void * V_32 )
{
struct V_33 * V_34 = V_32 ;
struct V_11 * V_12 = V_34 -> V_12 ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
V_24 V_35 [ 16 ] ;
int V_3 , V_36 = 0 ;
F_9 ( & V_2 -> V_22 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_10 ( & V_2 -> V_22 ) ;
goto V_37;
}
memset ( V_35 , 0 , sizeof( V_35 ) ) ;
if ( F_15 ( 0 , V_12 -> V_38 ) ) {
V_3 = F_11 ( V_2 -> V_5 ,
V_23 , 3 , & V_35 [ V_36 ] ) ;
if ( V_3 < 0 ) {
F_10 ( & V_2 -> V_22 ) ;
goto V_37;
}
V_36 += 4 ;
}
if ( F_15 ( 1 , V_12 -> V_38 ) ) {
V_3 = F_11 ( V_2 -> V_5 ,
V_27 , 2 , & V_35 [ V_36 ] ) ;
if ( V_3 < 0 ) {
F_10 ( & V_2 -> V_22 ) ;
goto V_37;
}
}
F_10 ( & V_2 -> V_22 ) ;
F_16 ( V_12 , V_35 ,
F_17 () ) ;
V_37:
F_18 ( V_12 -> V_39 ) ;
return V_40 ;
}
static int F_19 ( struct V_41 * V_5 ,
const struct V_42 * V_43 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int V_3 ;
V_3 = F_3 ( V_5 , V_44 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 != V_45 )
return - V_46 ;
V_12 = F_20 ( & V_5 -> V_9 , sizeof( * V_2 ) ) ;
if ( ! V_12 )
return - V_47 ;
V_2 = F_7 ( V_12 ) ;
V_2 -> V_5 = V_5 ;
F_21 ( & V_2 -> V_22 ) ;
F_22 ( V_5 , V_12 ) ;
V_12 -> V_48 = & V_49 ;
V_12 -> V_50 = V_43 -> V_50 ;
V_12 -> V_9 . V_51 = & V_5 -> V_9 ;
V_12 -> V_52 = V_53 ;
V_12 -> V_54 = V_55 ;
V_12 -> V_56 = F_23 ( V_55 ) ;
F_2 ( V_5 , V_6 ,
V_57 ) ;
F_4 ( 50 ) ;
V_2 -> V_7 = V_58 ;
V_3 = F_2 ( V_5 , V_6 ,
V_2 -> V_7 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_24 ( V_12 , NULL ,
F_14 , NULL ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_25 ( V_12 ) ;
if ( V_3 < 0 )
goto V_59;
return 0 ;
V_59:
F_26 ( V_12 ) ;
return V_3 ;
}
static int F_27 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 & ~ V_60 ) ;
}
static int F_28 ( struct V_41 * V_5 )
{
struct V_11 * V_12 = F_29 ( V_5 ) ;
F_30 ( V_12 ) ;
F_26 ( V_12 ) ;
F_27 ( F_7 ( V_12 ) ) ;
return 0 ;
}
static int F_31 ( struct V_61 * V_9 )
{
return F_27 ( F_7 ( F_29 (
F_32 ( V_9 ) ) ) ) ;
}
static int F_33 ( struct V_61 * V_9 )
{
struct V_1 * V_2 = F_7 ( F_29 (
F_32 ( V_9 ) ) ) ;
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 ) ;
}
