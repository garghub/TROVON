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
static T_3 F_13 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_39 )
{
struct V_17 * V_18 = F_14 ( V_36 ) ;
struct V_22 * V_23 = F_11 ( V_18 ) ;
const char V_40 [] [ 14 ] = { L_1 , L_2 } ;
return sprintf ( V_39 , L_3 , V_40 [ V_23 -> V_41 ] ) ;
}
static T_3 F_15 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
const char * V_39 , T_4 V_14 )
{
struct V_17 * V_18 = F_14 ( V_36 ) ;
struct V_22 * V_23 = F_11 ( V_18 ) ;
int V_9 ;
if ( F_16 ( V_39 , L_1 ) )
V_23 -> V_41 = V_42 ;
else if ( F_16 ( V_39 , L_2 ) )
V_23 -> V_41 = V_43 ;
else
V_9 = - V_33 ;
return V_9 ? V_9 : V_14 ;
}
static T_3 F_17 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
char * V_39 )
{
struct V_17 * V_18 = F_14 ( V_36 ) ;
struct V_22 * V_23 = F_11 ( V_18 ) ;
struct V_44 * V_45 = F_18 ( V_38 ) ;
return sprintf ( V_39 , L_4 ,
! ( V_23 -> V_46 & ( 1 << V_45 -> V_26 ) ) ) ;
}
static T_3 F_19 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
const char * V_39 , T_4 V_14 )
{
long V_47 ;
int V_9 ;
struct V_17 * V_18 = F_14 ( V_36 ) ;
struct V_22 * V_23 = F_11 ( V_18 ) ;
struct V_44 * V_45 = F_18 ( V_38 ) ;
V_9 = F_20 ( V_39 , 10 , & V_47 ) ;
if ( V_9 )
return V_9 ;
if ( V_47 == 0 )
V_23 -> V_46 |= ( 1 << V_45 -> V_26 ) ;
else if ( V_47 == 1 )
V_23 -> V_46 &= ~ ( 1 << V_45 -> V_26 ) ;
else
V_9 = - V_33 ;
V_9 = F_1 ( V_23 -> V_2 , V_48 ,
F_21 ( V_23 -> V_41 ) |
F_22 ( V_23 -> V_46 ) ) ;
F_1 ( V_23 -> V_2 , V_49 , 0 ) ;
return V_9 ? V_9 : V_14 ;
}
static T_5 F_23 ( int V_50 , void * V_51 )
{
F_24 ( V_51 ,
F_25 ( V_52 ,
0 ,
V_53 ,
V_54 ) ,
F_26 () ) ;
return V_55 ;
}
static int T_6 F_27 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = V_2 -> V_36 . V_58 ;
struct V_17 * V_18 ;
struct V_22 * V_23 ;
struct V_59 * V_60 ;
int V_9 , V_61 = 0 ;
V_18 = F_28 ( sizeof( * V_23 ) ) ;
if ( V_18 == NULL ) {
V_9 = - V_62 ;
goto V_63;
}
V_60 = F_29 ( & V_2 -> V_36 , L_5 ) ;
if ( ! F_30 ( V_60 ) ) {
V_9 = F_31 ( V_60 ) ;
if ( V_9 )
goto V_64;
V_61 = F_32 ( V_60 ) ;
}
F_33 ( V_2 , V_18 ) ;
V_23 = F_11 ( V_18 ) ;
if ( V_61 )
V_23 -> V_29 = V_61 / 1000 ;
else if ( V_57 )
V_23 -> V_29 = V_57 -> V_29 ;
else
F_34 ( & V_2 -> V_36 , L_6 ) ;
V_23 -> V_60 = V_60 ;
V_23 -> V_2 = V_2 ;
V_18 -> V_36 . V_65 = & V_2 -> V_36 ;
V_18 -> V_66 = F_35 ( V_23 -> V_2 ) -> V_66 ;
if ( F_35 ( V_23 -> V_2 ) -> V_67 == V_68 ) {
V_18 -> V_69 = & V_70 ;
V_18 -> V_71 = 1 ;
} else {
V_18 -> V_69 = & V_72 ;
V_18 -> V_71 = 4 ;
}
V_18 -> V_73 = V_74 ;
V_18 -> V_75 = V_76 ;
if ( V_2 -> V_50 ) {
V_9 = F_36 ( V_2 -> V_50 ,
NULL ,
& F_23 ,
V_77 | V_78 ,
F_35 ( V_23 -> V_2 ) -> V_66 ,
V_18 ) ;
if ( V_9 )
goto V_79;
}
V_9 = F_37 ( V_18 ) ;
if ( V_9 )
goto V_80;
return 0 ;
V_80:
F_38 ( V_2 -> V_50 , V_18 ) ;
V_79:
if ( ! F_30 ( V_60 ) )
F_39 ( V_60 ) ;
V_64:
if ( ! F_30 ( V_60 ) )
F_40 ( V_60 ) ;
F_41 ( V_18 ) ;
V_63:
return V_9 ;
}
static int T_7 F_42 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_43 ( V_2 ) ;
struct V_22 * V_23 = F_11 ( V_18 ) ;
F_44 ( V_18 ) ;
if ( V_2 -> V_50 )
F_38 ( V_2 -> V_50 , V_18 ) ;
if ( ! F_30 ( V_23 -> V_60 ) ) {
F_39 ( V_23 -> V_60 ) ;
F_40 ( V_23 -> V_60 ) ;
}
F_41 ( V_18 ) ;
return 0 ;
}
