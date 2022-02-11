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
static int F_6 ( struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
struct V_15 * V_16 = F_4 ( V_10 ) ;
return V_16 -> V_31 ;
}
static int F_7 ( struct V_9 * V_10 ,
const struct V_11 * V_12 , unsigned int V_32 )
{
struct V_15 * V_16 = F_4 ( V_10 ) ;
V_16 -> V_31 = V_32 ;
return 0 ;
}
static T_4 F_8 ( struct V_9 * V_10 ,
T_5 V_33 , const struct V_11 * V_12 , char * V_34 )
{
struct V_15 * V_16 = F_4 ( V_10 ) ;
return sprintf ( V_34 , L_1 ,
! ! ( V_16 -> V_35 & ( 1 << V_12 -> V_36 ) ) ) ;
}
static T_4 F_9 ( struct V_9 * V_10 ,
T_5 V_33 , const struct V_11 * V_12 , const char * V_34 ,
T_6 V_6 )
{
bool V_37 ;
int V_25 ;
struct V_15 * V_16 = F_4 ( V_10 ) ;
V_25 = F_10 ( V_34 , & V_37 ) ;
if ( V_25 )
return V_25 ;
if ( V_37 )
V_16 -> V_35 |= ( 1 << V_12 -> V_36 ) ;
else
V_16 -> V_35 &= ~ ( 1 << V_12 -> V_36 ) ;
V_25 = F_1 ( V_16 -> V_27 , V_38 , 0 ,
( V_16 -> V_31 << 4 ) |
V_16 -> V_35 , 16 ) ;
return V_25 ? V_25 : V_6 ;
}
static int T_7 F_11 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_9 * V_10 ;
int V_25 , V_39 = 0 ;
V_10 = F_12 ( sizeof( * V_16 ) ) ;
if ( V_10 == NULL ) {
V_25 = - V_40 ;
goto V_41;
}
V_16 = F_4 ( V_10 ) ;
V_16 -> V_42 = F_13 ( & V_2 -> V_43 , L_2 ) ;
if ( ! F_14 ( V_16 -> V_42 ) ) {
V_25 = F_15 ( V_16 -> V_42 ) ;
if ( V_25 )
goto V_44;
V_39 = F_16 ( V_16 -> V_42 ) ;
}
F_17 ( V_2 , V_10 ) ;
V_16 -> V_45 =
& V_46 [ F_18 ( V_2 ) -> V_47 ] ;
if ( V_39 )
V_16 -> V_19 = V_39 / 1000 ;
else
V_16 -> V_19 = V_16 -> V_45 -> V_48 ;
V_16 -> V_27 = V_2 ;
V_10 -> V_43 . V_49 = & V_2 -> V_43 ;
V_10 -> V_50 = F_18 ( V_2 ) -> V_50 ;
V_10 -> V_51 = & V_52 ;
V_10 -> V_53 = V_54 ;
V_10 -> V_55 = V_16 -> V_45 -> V_55 ;
V_10 -> V_56 = V_57 ;
V_25 = F_1 ( V_2 , V_58 , 0 ,
! ! V_39 , 16 ) ;
if ( V_25 )
goto V_59;
V_25 = F_19 ( V_10 ) ;
if ( V_25 )
goto V_59;
return 0 ;
V_59:
if ( ! F_14 ( V_16 -> V_42 ) )
F_20 ( V_16 -> V_42 ) ;
V_44:
if ( ! F_14 ( V_16 -> V_42 ) )
F_21 ( V_16 -> V_42 ) ;
F_22 ( V_10 ) ;
V_41:
return V_25 ;
}
static int T_8 F_23 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_24 ( V_2 ) ;
struct V_15 * V_16 = F_4 ( V_10 ) ;
F_25 ( V_10 ) ;
if ( ! F_14 ( V_16 -> V_42 ) ) {
F_20 ( V_16 -> V_42 ) ;
F_21 ( V_16 -> V_42 ) ;
}
F_22 ( V_10 ) ;
return 0 ;
}
