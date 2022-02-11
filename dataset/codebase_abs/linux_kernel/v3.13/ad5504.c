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
int V_9 ;
switch ( V_20 ) {
case V_23 :
V_9 = F_5 ( V_22 -> V_2 , V_18 -> V_24 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_4 = V_9 ;
return V_25 ;
case V_26 :
* V_4 = V_22 -> V_27 ;
* V_19 = V_18 -> V_28 . V_29 ;
return V_30 ;
}
return - V_31 ;
}
static int F_10 ( struct V_15 * V_16 ,
struct V_17 const * V_18 ,
int V_4 ,
int V_19 ,
long V_32 )
{
struct V_21 * V_22 = F_9 ( V_16 ) ;
int V_9 ;
switch ( V_32 ) {
case V_23 :
if ( V_4 >= ( 1 << V_18 -> V_28 . V_29 ) || V_4 < 0 )
return - V_31 ;
return F_1 ( V_22 -> V_2 , V_18 -> V_24 , V_4 ) ;
default:
V_9 = - V_31 ;
}
return - V_31 ;
}
static int F_11 ( struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
struct V_21 * V_22 = F_9 ( V_16 ) ;
return V_22 -> V_33 ;
}
static int F_12 ( struct V_15 * V_16 ,
const struct V_17 * V_18 , unsigned int V_34 )
{
struct V_21 * V_22 = F_9 ( V_16 ) ;
V_22 -> V_33 = V_34 ;
return 0 ;
}
static T_3 F_13 ( struct V_15 * V_16 ,
T_4 V_35 , const struct V_17 * V_18 , char * V_36 )
{
struct V_21 * V_22 = F_9 ( V_16 ) ;
return sprintf ( V_36 , L_1 ,
! ( V_22 -> V_37 & ( 1 << V_18 -> V_38 ) ) ) ;
}
static T_3 F_14 ( struct V_15 * V_16 ,
T_4 V_35 , const struct V_17 * V_18 , const char * V_36 ,
T_5 V_14 )
{
bool V_39 ;
int V_9 ;
struct V_21 * V_22 = F_9 ( V_16 ) ;
V_9 = F_15 ( V_36 , & V_39 ) ;
if ( V_9 )
return V_9 ;
if ( V_39 )
V_22 -> V_37 |= ( 1 << V_18 -> V_38 ) ;
else
V_22 -> V_37 &= ~ ( 1 << V_18 -> V_38 ) ;
V_9 = F_1 ( V_22 -> V_2 , V_40 ,
F_16 ( V_22 -> V_33 ) |
F_17 ( V_22 -> V_37 ) ) ;
F_1 ( V_22 -> V_2 , V_41 , 0 ) ;
return V_9 ? V_9 : V_14 ;
}
static T_6 F_18 ( int V_42 , void * V_35 )
{
F_19 ( V_35 ,
F_20 ( V_43 ,
0 ,
V_44 ,
V_45 ) ,
F_21 () ) ;
return V_46 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = V_2 -> V_49 . V_50 ;
struct V_15 * V_16 ;
struct V_21 * V_22 ;
struct V_51 * V_52 ;
int V_9 , V_53 = 0 ;
V_16 = F_23 ( & V_2 -> V_49 , sizeof( * V_22 ) ) ;
if ( ! V_16 )
return - V_54 ;
V_52 = F_24 ( & V_2 -> V_49 , L_2 ) ;
if ( ! F_25 ( V_52 ) ) {
V_9 = F_26 ( V_52 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_27 ( V_52 ) ;
if ( V_9 < 0 )
goto V_55;
V_53 = V_9 ;
}
F_28 ( V_2 , V_16 ) ;
V_22 = F_9 ( V_16 ) ;
if ( V_53 )
V_22 -> V_27 = V_53 / 1000 ;
else if ( V_48 )
V_22 -> V_27 = V_48 -> V_27 ;
else
F_29 ( & V_2 -> V_49 , L_3 ) ;
V_22 -> V_52 = V_52 ;
V_22 -> V_2 = V_2 ;
V_16 -> V_49 . V_56 = & V_2 -> V_49 ;
V_16 -> V_57 = F_30 ( V_22 -> V_2 ) -> V_57 ;
V_16 -> V_58 = & V_59 ;
if ( F_30 ( V_22 -> V_2 ) -> V_60 == V_61 )
V_16 -> V_62 = 1 ;
else
V_16 -> V_62 = 4 ;
V_16 -> V_63 = V_64 ;
V_16 -> V_65 = V_66 ;
if ( V_2 -> V_42 ) {
V_9 = F_31 ( & V_2 -> V_49 , V_2 -> V_42 ,
NULL ,
& F_18 ,
V_67 | V_68 ,
F_30 ( V_22 -> V_2 ) -> V_57 ,
V_16 ) ;
if ( V_9 )
goto V_55;
}
V_9 = F_32 ( V_16 ) ;
if ( V_9 )
goto V_55;
return 0 ;
V_55:
if ( ! F_25 ( V_52 ) )
F_33 ( V_52 ) ;
return V_9 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_35 ( V_2 ) ;
struct V_21 * V_22 = F_9 ( V_16 ) ;
F_36 ( V_16 ) ;
if ( ! F_25 ( V_22 -> V_52 ) )
F_33 ( V_22 -> V_52 ) ;
return 0 ;
}
