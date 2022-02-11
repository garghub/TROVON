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
case V_26 :
if ( V_5 >= ( 1 << V_12 -> V_20 . V_21 ) || V_5 < 0 )
return - V_23 ;
return F_1 ( V_16 -> V_27 ,
V_28 ,
V_12 -> V_29 , V_5 ,
V_12 -> V_20 . V_30 ) ;
default:
V_25 = - V_23 ;
}
return - V_23 ;
}
static T_4 F_6 ( struct V_31 * V_32 ,
struct V_33 * V_34 , char * V_35 )
{
struct V_9 * V_10 = F_7 ( V_32 ) ;
struct V_15 * V_16 = F_4 ( V_10 ) ;
char V_36 [] [ 15 ] = { L_1 , L_2 , L_3 , L_4 } ;
return sprintf ( V_35 , L_5 , V_36 [ V_16 -> V_37 ] ) ;
}
static T_4 F_8 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
const char * V_35 , T_5 V_6 )
{
struct V_9 * V_10 = F_7 ( V_32 ) ;
struct V_15 * V_16 = F_4 ( V_10 ) ;
int V_25 ;
if ( F_9 ( V_35 , L_2 ) )
V_16 -> V_37 = V_38 ;
else if ( F_9 ( V_35 , L_3 ) )
V_16 -> V_37 = V_39 ;
else if ( F_9 ( V_35 , L_4 ) )
V_16 -> V_37 = V_40 ;
else
V_25 = - V_23 ;
return V_25 ? V_25 : V_6 ;
}
static T_4 F_10 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_35 )
{
struct V_9 * V_10 = F_7 ( V_32 ) ;
struct V_15 * V_16 = F_4 ( V_10 ) ;
struct V_41 * V_42 = F_11 ( V_34 ) ;
return sprintf ( V_35 , L_6 ,
! ! ( V_16 -> V_43 & ( 1 << V_42 -> V_29 ) ) ) ;
}
static T_4 F_12 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
const char * V_35 , T_5 V_6 )
{
long V_44 ;
int V_25 ;
struct V_9 * V_10 = F_7 ( V_32 ) ;
struct V_15 * V_16 = F_4 ( V_10 ) ;
struct V_41 * V_42 = F_11 ( V_34 ) ;
V_25 = F_13 ( V_35 , 10 , & V_44 ) ;
if ( V_25 )
return V_25 ;
if ( V_44 == 1 )
V_16 -> V_43 |= ( 1 << V_42 -> V_29 ) ;
else if ( ! V_44 )
V_16 -> V_43 &= ~ ( 1 << V_42 -> V_29 ) ;
else
V_25 = - V_23 ;
V_25 = F_1 ( V_16 -> V_27 , V_45 , 0 ,
( V_16 -> V_37 << 4 ) |
V_16 -> V_43 , 16 ) ;
return V_25 ? V_25 : V_6 ;
}
static int T_6 F_14 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_9 * V_10 ;
int V_25 , V_46 = 0 ;
V_10 = F_15 ( sizeof( * V_16 ) ) ;
if ( V_10 == NULL ) {
V_25 = - V_47 ;
goto V_48;
}
V_16 = F_4 ( V_10 ) ;
V_16 -> V_49 = F_16 ( & V_2 -> V_32 , L_7 ) ;
if ( ! F_17 ( V_16 -> V_49 ) ) {
V_25 = F_18 ( V_16 -> V_49 ) ;
if ( V_25 )
goto V_50;
V_46 = F_19 ( V_16 -> V_49 ) ;
}
F_20 ( V_2 , V_10 ) ;
V_16 -> V_51 =
& V_52 [ F_21 ( V_2 ) -> V_53 ] ;
if ( V_46 )
V_16 -> V_19 = V_46 / 1000 ;
else
V_16 -> V_19 = V_16 -> V_51 -> V_54 ;
V_16 -> V_27 = V_2 ;
V_10 -> V_32 . V_55 = & V_2 -> V_32 ;
V_10 -> V_56 = F_21 ( V_2 ) -> V_56 ;
V_10 -> V_57 = & V_58 ;
V_10 -> V_59 = V_60 ;
V_10 -> V_61 = V_16 -> V_51 -> V_61 ;
V_10 -> V_62 = V_63 ;
V_25 = F_1 ( V_2 , V_64 , 0 ,
! ! V_46 , 16 ) ;
if ( V_25 )
goto V_65;
V_25 = F_22 ( V_10 ) ;
if ( V_25 )
goto V_65;
return 0 ;
V_65:
if ( ! F_17 ( V_16 -> V_49 ) )
F_23 ( V_16 -> V_49 ) ;
V_50:
if ( ! F_17 ( V_16 -> V_49 ) )
F_24 ( V_16 -> V_49 ) ;
F_25 ( V_10 ) ;
V_48:
return V_25 ;
}
static int T_7 F_26 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_27 ( V_2 ) ;
struct V_15 * V_16 = F_4 ( V_10 ) ;
F_28 ( V_10 ) ;
if ( ! F_17 ( V_16 -> V_49 ) ) {
F_23 ( V_16 -> V_49 ) ;
F_24 ( V_16 -> V_49 ) ;
}
F_25 ( V_10 ) ;
return 0 ;
}
