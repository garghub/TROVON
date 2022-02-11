static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_2 V_5 , T_1 V_6 )
{
T_3 V_7 ;
T_1 V_8 [ 3 ] ;
V_7 = ( 0 << 22 ) | ( V_3 << 19 ) | ( V_4 << 16 ) | ( V_5 << ( 16 - V_6 ) ) ;
V_8 [ 0 ] = V_7 >> 16 ;
V_8 [ 1 ] = V_7 >> 8 ;
V_8 [ 2 ] = V_7 ;
return F_2 ( V_2 , V_8 , 3 ) ;
}
static int F_3 ( struct V_9 * V_10 ,
struct V_11 const * V_12 ,
int * V_5 ,
int * V_13 ,
long V_14 )
{
struct V_15 * V_16 = F_4 ( V_10 ) ;
unsigned long V_17 ;
switch ( V_14 ) {
case V_18 :
V_17 = ( V_16 -> V_19 * 1000 ) >> V_12 -> V_20 . V_21 ;
* V_5 = V_17 / 1000 ;
* V_13 = ( V_17 % 1000 ) * 1000 ;
return V_22 ;
}
return - V_23 ;
}
static int F_5 ( struct V_9 * V_10 ,
struct V_11 const * V_12 ,
int V_5 ,
int V_13 ,
long V_24 )
{
struct V_15 * V_16 = F_4 ( V_10 ) ;
int V_25 ;
switch ( V_24 ) {
case 0 :
if ( V_5 >= ( 1 << V_12 -> V_20 . V_21 ) || V_5 < 0 )
return - V_23 ;
return F_1 ( V_16 -> V_26 ,
V_27 ,
V_12 -> V_28 , V_5 ,
V_12 -> V_20 . V_29 ) ;
default:
V_25 = - V_23 ;
}
return - V_23 ;
}
static T_4 F_6 ( struct V_30 * V_31 ,
struct V_32 * V_33 , char * V_34 )
{
struct V_9 * V_10 = F_7 ( V_31 ) ;
struct V_15 * V_16 = F_4 ( V_10 ) ;
char V_35 [] [ 15 ] = { L_1 , L_2 , L_3 , L_4 } ;
return sprintf ( V_34 , L_5 , V_35 [ V_16 -> V_36 ] ) ;
}
static T_4 F_8 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 , T_5 V_6 )
{
struct V_9 * V_10 = F_7 ( V_31 ) ;
struct V_15 * V_16 = F_4 ( V_10 ) ;
int V_25 ;
if ( F_9 ( V_34 , L_2 ) )
V_16 -> V_36 = V_37 ;
else if ( F_9 ( V_34 , L_3 ) )
V_16 -> V_36 = V_38 ;
else if ( F_9 ( V_34 , L_4 ) )
V_16 -> V_36 = V_39 ;
else
V_25 = - V_23 ;
return V_25 ? V_25 : V_6 ;
}
static T_4 F_10 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
char * V_34 )
{
struct V_9 * V_10 = F_7 ( V_31 ) ;
struct V_15 * V_16 = F_4 ( V_10 ) ;
struct V_40 * V_41 = F_11 ( V_33 ) ;
return sprintf ( V_34 , L_6 ,
! ! ( V_16 -> V_42 & ( 1 << V_41 -> V_28 ) ) ) ;
}
static T_4 F_12 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_34 , T_5 V_6 )
{
long V_43 ;
int V_25 ;
struct V_9 * V_10 = F_7 ( V_31 ) ;
struct V_15 * V_16 = F_4 ( V_10 ) ;
struct V_40 * V_41 = F_11 ( V_33 ) ;
V_25 = F_13 ( V_34 , 10 , & V_43 ) ;
if ( V_25 )
return V_25 ;
if ( V_43 == 1 )
V_16 -> V_42 |= ( 1 << V_41 -> V_28 ) ;
else if ( ! V_43 )
V_16 -> V_42 &= ~ ( 1 << V_41 -> V_28 ) ;
else
V_25 = - V_23 ;
V_25 = F_1 ( V_16 -> V_26 , V_44 , 0 ,
( V_16 -> V_36 << 4 ) |
V_16 -> V_42 , 16 ) ;
return V_25 ? V_25 : V_6 ;
}
static int T_6 F_14 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_9 * V_10 ;
int V_25 , V_45 = 0 ;
V_10 = F_15 ( sizeof( * V_16 ) ) ;
if ( V_10 == NULL ) {
V_25 = - V_46 ;
goto V_47;
}
V_16 = F_4 ( V_10 ) ;
V_16 -> V_48 = F_16 ( & V_2 -> V_31 , L_7 ) ;
if ( ! F_17 ( V_16 -> V_48 ) ) {
V_25 = F_18 ( V_16 -> V_48 ) ;
if ( V_25 )
goto V_49;
V_45 = F_19 ( V_16 -> V_48 ) ;
}
F_20 ( V_2 , V_10 ) ;
V_16 -> V_50 =
& V_51 [ F_21 ( V_2 ) -> V_52 ] ;
if ( V_45 )
V_16 -> V_19 = V_45 / 1000 ;
else
V_16 -> V_19 = V_16 -> V_50 -> V_53 ;
V_16 -> V_26 = V_2 ;
V_10 -> V_31 . V_54 = & V_2 -> V_31 ;
V_10 -> V_55 = F_21 ( V_2 ) -> V_55 ;
V_10 -> V_56 = & V_57 ;
V_10 -> V_58 = V_59 ;
V_10 -> V_60 = V_16 -> V_50 -> V_60 ;
V_10 -> V_61 = V_62 ;
V_25 = F_1 ( V_2 , V_63 , 0 ,
! ! V_45 , 16 ) ;
if ( V_25 )
goto V_64;
V_25 = F_22 ( V_10 ) ;
if ( V_25 )
goto V_64;
return 0 ;
V_64:
if ( ! F_17 ( V_16 -> V_48 ) )
F_23 ( V_16 -> V_48 ) ;
V_49:
if ( ! F_17 ( V_16 -> V_48 ) )
F_24 ( V_16 -> V_48 ) ;
F_25 ( V_10 ) ;
V_47:
return V_25 ;
}
static int T_7 F_26 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_27 ( V_2 ) ;
struct V_15 * V_16 = F_4 ( V_10 ) ;
F_28 ( V_10 ) ;
if ( ! F_17 ( V_16 -> V_48 ) ) {
F_23 ( V_16 -> V_48 ) ;
F_24 ( V_16 -> V_48 ) ;
}
F_25 ( V_10 ) ;
return 0 ;
}
