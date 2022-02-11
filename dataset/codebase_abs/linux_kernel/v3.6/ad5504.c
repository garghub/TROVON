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
struct V_15 V_16 ;
F_6 ( & V_16 ) ;
F_7 ( & V_11 , & V_16 ) ;
V_9 = F_8 ( V_2 , & V_16 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_9 ( V_4 ) & V_7 ;
}
static int F_10 ( struct V_17 * V_18 ,
struct V_19 const * V_20 ,
int * V_4 ,
int * V_21 ,
long V_16 )
{
struct V_22 * V_23 = F_11 ( V_18 ) ;
unsigned long V_24 ;
int V_9 ;
switch ( V_16 ) {
case V_25 :
V_9 = F_5 ( V_23 -> V_2 , V_20 -> V_26 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_4 = V_9 ;
return V_27 ;
case V_28 :
V_24 = ( V_23 -> V_29 * 1000 ) >> V_20 -> V_30 . V_31 ;
* V_4 = V_24 / 1000 ;
* V_21 = ( V_24 % 1000 ) * 1000 ;
return V_32 ;
}
return - V_33 ;
}
static int F_12 ( struct V_17 * V_18 ,
struct V_19 const * V_20 ,
int V_4 ,
int V_21 ,
long V_34 )
{
struct V_22 * V_23 = F_11 ( V_18 ) ;
int V_9 ;
switch ( V_34 ) {
case V_25 :
if ( V_4 >= ( 1 << V_20 -> V_30 . V_31 ) || V_4 < 0 )
return - V_33 ;
return F_1 ( V_23 -> V_2 , V_20 -> V_26 , V_4 ) ;
default:
V_9 = - V_33 ;
}
return - V_33 ;
}
static int F_13 ( struct V_17 * V_18 ,
const struct V_19 * V_20 )
{
struct V_22 * V_23 = F_11 ( V_18 ) ;
return V_23 -> V_35 ;
}
static int F_14 ( struct V_17 * V_18 ,
const struct V_19 * V_20 , unsigned int V_36 )
{
struct V_22 * V_23 = F_11 ( V_18 ) ;
V_23 -> V_35 = V_36 ;
return 0 ;
}
static T_3 F_15 ( struct V_17 * V_18 ,
T_4 V_37 , const struct V_19 * V_20 , char * V_38 )
{
struct V_22 * V_23 = F_11 ( V_18 ) ;
return sprintf ( V_38 , L_1 ,
! ( V_23 -> V_39 & ( 1 << V_20 -> V_40 ) ) ) ;
}
static T_3 F_16 ( struct V_17 * V_18 ,
T_4 V_37 , const struct V_19 * V_20 , const char * V_38 ,
T_5 V_14 )
{
bool V_41 ;
int V_9 ;
struct V_22 * V_23 = F_11 ( V_18 ) ;
V_9 = F_17 ( V_38 , & V_41 ) ;
if ( V_9 )
return V_9 ;
if ( V_41 )
V_23 -> V_39 |= ( 1 << V_20 -> V_40 ) ;
else
V_23 -> V_39 &= ~ ( 1 << V_20 -> V_40 ) ;
V_9 = F_1 ( V_23 -> V_2 , V_42 ,
F_18 ( V_23 -> V_35 ) |
F_19 ( V_23 -> V_39 ) ) ;
F_1 ( V_23 -> V_2 , V_43 , 0 ) ;
return V_9 ? V_9 : V_14 ;
}
static T_6 F_20 ( int V_44 , void * V_37 )
{
F_21 ( V_37 ,
F_22 ( V_45 ,
0 ,
V_46 ,
V_47 ) ,
F_23 () ) ;
return V_48 ;
}
static int T_7 F_24 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_51 . V_52 ;
struct V_17 * V_18 ;
struct V_22 * V_23 ;
struct V_53 * V_54 ;
int V_9 , V_55 = 0 ;
V_18 = F_25 ( sizeof( * V_23 ) ) ;
if ( V_18 == NULL ) {
V_9 = - V_56 ;
goto V_57;
}
V_54 = F_26 ( & V_2 -> V_51 , L_2 ) ;
if ( ! F_27 ( V_54 ) ) {
V_9 = F_28 ( V_54 ) ;
if ( V_9 )
goto V_58;
V_55 = F_29 ( V_54 ) ;
}
F_30 ( V_2 , V_18 ) ;
V_23 = F_11 ( V_18 ) ;
if ( V_55 )
V_23 -> V_29 = V_55 / 1000 ;
else if ( V_50 )
V_23 -> V_29 = V_50 -> V_29 ;
else
F_31 ( & V_2 -> V_51 , L_3 ) ;
V_23 -> V_54 = V_54 ;
V_23 -> V_2 = V_2 ;
V_18 -> V_51 . V_59 = & V_2 -> V_51 ;
V_18 -> V_60 = F_32 ( V_23 -> V_2 ) -> V_60 ;
V_18 -> V_61 = & V_62 ;
if ( F_32 ( V_23 -> V_2 ) -> V_63 == V_64 )
V_18 -> V_65 = 1 ;
else
V_18 -> V_65 = 4 ;
V_18 -> V_66 = V_67 ;
V_18 -> V_68 = V_69 ;
if ( V_2 -> V_44 ) {
V_9 = F_33 ( V_2 -> V_44 ,
NULL ,
& F_20 ,
V_70 | V_71 ,
F_32 ( V_23 -> V_2 ) -> V_60 ,
V_18 ) ;
if ( V_9 )
goto V_72;
}
V_9 = F_34 ( V_18 ) ;
if ( V_9 )
goto V_73;
return 0 ;
V_73:
if ( V_2 -> V_44 )
F_35 ( V_2 -> V_44 , V_18 ) ;
V_72:
if ( ! F_27 ( V_54 ) )
F_36 ( V_54 ) ;
V_58:
if ( ! F_27 ( V_54 ) )
F_37 ( V_54 ) ;
F_38 ( V_18 ) ;
V_57:
return V_9 ;
}
static int T_8 F_39 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_40 ( V_2 ) ;
struct V_22 * V_23 = F_11 ( V_18 ) ;
F_41 ( V_18 ) ;
if ( V_2 -> V_44 )
F_35 ( V_2 -> V_44 , V_18 ) ;
if ( ! F_27 ( V_23 -> V_54 ) ) {
F_36 ( V_23 -> V_54 ) ;
F_37 ( V_23 -> V_54 ) ;
}
F_38 ( V_18 ) ;
return 0 ;
}
