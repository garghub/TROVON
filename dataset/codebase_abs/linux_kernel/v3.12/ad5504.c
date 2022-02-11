static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
T_2 V_5 = F_2 ( V_6 |
F_3 ( V_3 ) |
( V_4 & V_7 ) ) ;
return F_4 ( V_2 , ( T_1 * ) & V_5 , 2 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_5 = F_2 ( V_8 | F_3 ( V_3 ) ) ;
T_2 V_4 ;
int V_9 ;
struct V_10 V_11 = {
. V_12 = & V_5 ,
. V_13 = & V_4 ,
. V_14 = 2 ,
} ;
V_9 = F_6 ( V_2 , & V_11 , 1 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_7 ( V_4 ) & V_7 ;
}
static int F_8 ( struct V_15 * V_16 ,
struct V_17 const * V_18 ,
int * V_4 ,
int * V_19 ,
long V_20 )
{
struct V_21 * V_22 = F_9 ( V_16 ) ;
unsigned long V_23 ;
int V_9 ;
switch ( V_20 ) {
case V_24 :
V_9 = F_5 ( V_22 -> V_2 , V_18 -> V_25 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_4 = V_9 ;
return V_26 ;
case V_27 :
V_23 = ( V_22 -> V_28 * 1000 ) >> V_18 -> V_29 . V_30 ;
* V_4 = V_23 / 1000 ;
* V_19 = ( V_23 % 1000 ) * 1000 ;
return V_31 ;
}
return - V_32 ;
}
static int F_10 ( struct V_15 * V_16 ,
struct V_17 const * V_18 ,
int V_4 ,
int V_19 ,
long V_33 )
{
struct V_21 * V_22 = F_9 ( V_16 ) ;
int V_9 ;
switch ( V_33 ) {
case V_24 :
if ( V_4 >= ( 1 << V_18 -> V_29 . V_30 ) || V_4 < 0 )
return - V_32 ;
return F_1 ( V_22 -> V_2 , V_18 -> V_25 , V_4 ) ;
default:
V_9 = - V_32 ;
}
return - V_32 ;
}
static int F_11 ( struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
struct V_21 * V_22 = F_9 ( V_16 ) ;
return V_22 -> V_34 ;
}
static int F_12 ( struct V_15 * V_16 ,
const struct V_17 * V_18 , unsigned int V_35 )
{
struct V_21 * V_22 = F_9 ( V_16 ) ;
V_22 -> V_34 = V_35 ;
return 0 ;
}
static T_3 F_13 ( struct V_15 * V_16 ,
T_4 V_36 , const struct V_17 * V_18 , char * V_37 )
{
struct V_21 * V_22 = F_9 ( V_16 ) ;
return sprintf ( V_37 , L_1 ,
! ( V_22 -> V_38 & ( 1 << V_18 -> V_39 ) ) ) ;
}
static T_3 F_14 ( struct V_15 * V_16 ,
T_4 V_36 , const struct V_17 * V_18 , const char * V_37 ,
T_5 V_14 )
{
bool V_40 ;
int V_9 ;
struct V_21 * V_22 = F_9 ( V_16 ) ;
V_9 = F_15 ( V_37 , & V_40 ) ;
if ( V_9 )
return V_9 ;
if ( V_40 )
V_22 -> V_38 |= ( 1 << V_18 -> V_39 ) ;
else
V_22 -> V_38 &= ~ ( 1 << V_18 -> V_39 ) ;
V_9 = F_1 ( V_22 -> V_2 , V_41 ,
F_16 ( V_22 -> V_34 ) |
F_17 ( V_22 -> V_38 ) ) ;
F_1 ( V_22 -> V_2 , V_42 , 0 ) ;
return V_9 ? V_9 : V_14 ;
}
static T_6 F_18 ( int V_43 , void * V_36 )
{
F_19 ( V_36 ,
F_20 ( V_44 ,
0 ,
V_45 ,
V_46 ) ,
F_21 () ) ;
return V_47 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_50 . V_51 ;
struct V_15 * V_16 ;
struct V_21 * V_22 ;
struct V_52 * V_53 ;
int V_9 , V_54 = 0 ;
V_16 = F_23 ( & V_2 -> V_50 , sizeof( * V_22 ) ) ;
if ( ! V_16 )
return - V_55 ;
V_53 = F_24 ( & V_2 -> V_50 , L_2 ) ;
if ( ! F_25 ( V_53 ) ) {
V_9 = F_26 ( V_53 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_27 ( V_53 ) ;
if ( V_9 < 0 )
goto V_56;
V_54 = V_9 ;
}
F_28 ( V_2 , V_16 ) ;
V_22 = F_9 ( V_16 ) ;
if ( V_54 )
V_22 -> V_28 = V_54 / 1000 ;
else if ( V_49 )
V_22 -> V_28 = V_49 -> V_28 ;
else
F_29 ( & V_2 -> V_50 , L_3 ) ;
V_22 -> V_53 = V_53 ;
V_22 -> V_2 = V_2 ;
V_16 -> V_50 . V_57 = & V_2 -> V_50 ;
V_16 -> V_58 = F_30 ( V_22 -> V_2 ) -> V_58 ;
V_16 -> V_59 = & V_60 ;
if ( F_30 ( V_22 -> V_2 ) -> V_61 == V_62 )
V_16 -> V_63 = 1 ;
else
V_16 -> V_63 = 4 ;
V_16 -> V_64 = V_65 ;
V_16 -> V_66 = V_67 ;
if ( V_2 -> V_43 ) {
V_9 = F_31 ( & V_2 -> V_50 , V_2 -> V_43 ,
NULL ,
& F_18 ,
V_68 | V_69 ,
F_30 ( V_22 -> V_2 ) -> V_58 ,
V_16 ) ;
if ( V_9 )
goto V_56;
}
V_9 = F_32 ( V_16 ) ;
if ( V_9 )
goto V_56;
return 0 ;
V_56:
if ( ! F_25 ( V_53 ) )
F_33 ( V_53 ) ;
return V_9 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_35 ( V_2 ) ;
struct V_21 * V_22 = F_9 ( V_16 ) ;
F_36 ( V_16 ) ;
if ( ! F_25 ( V_22 -> V_53 ) )
F_33 ( V_22 -> V_53 ) ;
return 0 ;
}
