static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
V_2 -> V_5 [ 0 ] = F_2 ( V_6 | F_3 ( V_3 ) |
( V_4 & V_7 ) ) ;
return F_4 ( V_2 -> V_8 , & V_2 -> V_5 [ 0 ] , 2 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_9 ;
struct V_10 V_11 = {
. V_12 = & V_2 -> V_5 [ 0 ] ,
. V_13 = & V_2 -> V_5 [ 1 ] ,
. V_14 = 2 ,
} ;
V_2 -> V_5 [ 0 ] = F_2 ( V_15 | F_3 ( V_3 ) ) ;
V_9 = F_6 ( V_2 -> V_8 , & V_11 , 1 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_7 ( V_2 -> V_5 [ 1 ] ) & V_7 ;
}
static int F_8 ( struct V_16 * V_17 ,
struct V_18 const * V_19 ,
int * V_4 ,
int * V_20 ,
long V_21 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_9 ;
switch ( V_21 ) {
case V_22 :
V_9 = F_5 ( V_2 , V_19 -> V_23 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_4 = V_9 ;
return V_24 ;
case V_25 :
* V_4 = V_2 -> V_26 ;
* V_20 = V_19 -> V_27 . V_28 ;
return V_29 ;
}
return - V_30 ;
}
static int F_10 ( struct V_16 * V_17 ,
struct V_18 const * V_19 ,
int V_4 ,
int V_20 ,
long V_31 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_9 ;
switch ( V_31 ) {
case V_22 :
if ( V_4 >= ( 1 << V_19 -> V_27 . V_28 ) || V_4 < 0 )
return - V_30 ;
return F_1 ( V_2 , V_19 -> V_23 , V_4 ) ;
default:
V_9 = - V_30 ;
}
return - V_30 ;
}
static int F_11 ( struct V_16 * V_17 ,
const struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
return V_2 -> V_32 ;
}
static int F_12 ( struct V_16 * V_17 ,
const struct V_18 * V_19 , unsigned int V_33 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
V_2 -> V_32 = V_33 ;
return 0 ;
}
static T_3 F_13 ( struct V_16 * V_17 ,
T_4 V_34 , const struct V_18 * V_19 , char * V_35 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
return sprintf ( V_35 , L_1 ,
! ( V_2 -> V_36 & ( 1 << V_19 -> V_37 ) ) ) ;
}
static T_3 F_14 ( struct V_16 * V_17 ,
T_4 V_34 , const struct V_18 * V_19 , const char * V_35 ,
T_5 V_14 )
{
bool V_38 ;
int V_9 ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
V_9 = F_15 ( V_35 , & V_38 ) ;
if ( V_9 )
return V_9 ;
if ( V_38 )
V_2 -> V_36 |= ( 1 << V_19 -> V_37 ) ;
else
V_2 -> V_36 &= ~ ( 1 << V_19 -> V_37 ) ;
V_9 = F_1 ( V_2 , V_39 ,
F_16 ( V_2 -> V_32 ) |
F_17 ( V_2 -> V_36 ) ) ;
F_1 ( V_2 , V_40 , 0 ) ;
return V_9 ? V_9 : V_14 ;
}
static T_6 F_18 ( int V_41 , void * V_34 )
{
F_19 ( V_34 ,
F_20 ( V_42 ,
0 ,
V_43 ,
V_44 ) ,
F_21 () ) ;
return V_45 ;
}
static int F_22 ( struct V_46 * V_8 )
{
struct V_47 * V_48 = V_8 -> V_49 . V_50 ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
struct V_51 * V_52 ;
int V_9 , V_53 = 0 ;
V_17 = F_23 ( & V_8 -> V_49 , sizeof( * V_2 ) ) ;
if ( ! V_17 )
return - V_54 ;
V_52 = F_24 ( & V_8 -> V_49 , L_2 ) ;
if ( ! F_25 ( V_52 ) ) {
V_9 = F_26 ( V_52 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_27 ( V_52 ) ;
if ( V_9 < 0 )
goto V_55;
V_53 = V_9 ;
}
F_28 ( V_8 , V_17 ) ;
V_2 = F_9 ( V_17 ) ;
if ( V_53 )
V_2 -> V_26 = V_53 / 1000 ;
else if ( V_48 )
V_2 -> V_26 = V_48 -> V_26 ;
else
F_29 ( & V_8 -> V_49 , L_3 ) ;
V_2 -> V_52 = V_52 ;
V_2 -> V_8 = V_8 ;
V_17 -> V_49 . V_56 = & V_8 -> V_49 ;
V_17 -> V_57 = F_30 ( V_2 -> V_8 ) -> V_57 ;
V_17 -> V_58 = & V_59 ;
if ( F_30 ( V_2 -> V_8 ) -> V_60 == V_61 )
V_17 -> V_62 = 1 ;
else
V_17 -> V_62 = 4 ;
V_17 -> V_63 = V_64 ;
V_17 -> V_65 = V_66 ;
if ( V_8 -> V_41 ) {
V_9 = F_31 ( & V_8 -> V_49 , V_8 -> V_41 ,
NULL ,
& F_18 ,
V_67 | V_68 ,
F_30 ( V_2 -> V_8 ) -> V_57 ,
V_17 ) ;
if ( V_9 )
goto V_55;
}
V_9 = F_32 ( V_17 ) ;
if ( V_9 )
goto V_55;
return 0 ;
V_55:
if ( ! F_25 ( V_52 ) )
F_33 ( V_52 ) ;
return V_9 ;
}
static int F_34 ( struct V_46 * V_8 )
{
struct V_16 * V_17 = F_35 ( V_8 ) ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
F_36 ( V_17 ) ;
if ( ! F_25 ( V_2 -> V_52 ) )
F_33 ( V_2 -> V_52 ) ;
return 0 ;
}
