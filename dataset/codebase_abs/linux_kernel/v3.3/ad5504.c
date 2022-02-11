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
case 0 :
V_9 = F_5 ( V_23 -> V_2 , V_20 -> V_25 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_4 = V_9 ;
return V_26 ;
case V_27 :
V_24 = ( V_23 -> V_28 * 1000 ) >> V_20 -> V_29 . V_30 ;
* V_4 = V_24 / 1000 ;
* V_21 = ( V_24 % 1000 ) * 1000 ;
return V_31 ;
}
return - V_32 ;
}
static int F_12 ( struct V_17 * V_18 ,
struct V_19 const * V_20 ,
int V_4 ,
int V_21 ,
long V_33 )
{
struct V_22 * V_23 = F_11 ( V_18 ) ;
int V_9 ;
switch ( V_33 ) {
case 0 :
if ( V_4 >= ( 1 << V_20 -> V_29 . V_30 ) || V_4 < 0 )
return - V_32 ;
return F_1 ( V_23 -> V_2 , V_20 -> V_25 , V_4 ) ;
default:
V_9 = - V_32 ;
}
return - V_32 ;
}
static T_3 F_13 ( struct V_34 * V_35 ,
struct V_36 * V_37 , char * V_38 )
{
struct V_17 * V_18 = F_14 ( V_35 ) ;
struct V_22 * V_23 = F_11 ( V_18 ) ;
const char V_39 [] [ 14 ] = { L_1 , L_2 } ;
return sprintf ( V_38 , L_3 , V_39 [ V_23 -> V_40 ] ) ;
}
static T_3 F_15 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
const char * V_38 , T_4 V_14 )
{
struct V_17 * V_18 = F_14 ( V_35 ) ;
struct V_22 * V_23 = F_11 ( V_18 ) ;
int V_9 ;
if ( F_16 ( V_38 , L_1 ) )
V_23 -> V_40 = V_41 ;
else if ( F_16 ( V_38 , L_2 ) )
V_23 -> V_40 = V_42 ;
else
V_9 = - V_32 ;
return V_9 ? V_9 : V_14 ;
}
static T_3 F_17 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
char * V_38 )
{
struct V_17 * V_18 = F_14 ( V_35 ) ;
struct V_22 * V_23 = F_11 ( V_18 ) ;
struct V_43 * V_44 = F_18 ( V_37 ) ;
return sprintf ( V_38 , L_4 ,
! ( V_23 -> V_45 & ( 1 << V_44 -> V_25 ) ) ) ;
}
static T_3 F_19 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
const char * V_38 , T_4 V_14 )
{
long V_46 ;
int V_9 ;
struct V_17 * V_18 = F_14 ( V_35 ) ;
struct V_22 * V_23 = F_11 ( V_18 ) ;
struct V_43 * V_44 = F_18 ( V_37 ) ;
V_9 = F_20 ( V_38 , 10 , & V_46 ) ;
if ( V_9 )
return V_9 ;
if ( V_46 == 0 )
V_23 -> V_45 |= ( 1 << V_44 -> V_25 ) ;
else if ( V_46 == 1 )
V_23 -> V_45 &= ~ ( 1 << V_44 -> V_25 ) ;
else
V_9 = - V_32 ;
V_9 = F_1 ( V_23 -> V_2 , V_47 ,
F_21 ( V_23 -> V_40 ) |
F_22 ( V_23 -> V_45 ) ) ;
F_1 ( V_23 -> V_2 , V_48 , 0 ) ;
return V_9 ? V_9 : V_14 ;
}
static T_5 F_23 ( int V_49 , void * V_50 )
{
F_24 ( V_50 ,
F_25 ( V_51 ,
0 ,
V_52 ,
V_53 ) ,
F_26 () ) ;
return V_54 ;
}
static int T_6 F_27 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_35 . V_57 ;
struct V_17 * V_18 ;
struct V_22 * V_23 ;
struct V_58 * V_59 ;
int V_9 , V_60 = 0 ;
V_18 = F_28 ( sizeof( * V_23 ) ) ;
if ( V_18 == NULL ) {
V_9 = - V_61 ;
goto V_62;
}
V_59 = F_29 ( & V_2 -> V_35 , L_5 ) ;
if ( ! F_30 ( V_59 ) ) {
V_9 = F_31 ( V_59 ) ;
if ( V_9 )
goto V_63;
V_60 = F_32 ( V_59 ) ;
}
F_33 ( V_2 , V_18 ) ;
V_23 = F_11 ( V_18 ) ;
if ( V_60 )
V_23 -> V_28 = V_60 / 1000 ;
else if ( V_56 )
V_23 -> V_28 = V_56 -> V_28 ;
else
F_34 ( & V_2 -> V_35 , L_6 ) ;
V_23 -> V_59 = V_59 ;
V_23 -> V_2 = V_2 ;
V_18 -> V_35 . V_64 = & V_2 -> V_35 ;
V_18 -> V_65 = F_35 ( V_23 -> V_2 ) -> V_65 ;
if ( F_35 ( V_23 -> V_2 ) -> V_66 == V_67 ) {
V_18 -> V_68 = & V_69 ;
V_18 -> V_70 = 1 ;
} else {
V_18 -> V_68 = & V_71 ;
V_18 -> V_70 = 4 ;
}
V_18 -> V_72 = V_73 ;
V_18 -> V_74 = V_75 ;
if ( V_2 -> V_49 ) {
V_9 = F_36 ( V_2 -> V_49 ,
NULL ,
& F_23 ,
V_76 | V_77 ,
F_35 ( V_23 -> V_2 ) -> V_65 ,
V_18 ) ;
if ( V_9 )
goto V_78;
}
V_9 = F_37 ( V_18 ) ;
if ( V_9 )
goto V_79;
return 0 ;
V_79:
F_38 ( V_2 -> V_49 , V_18 ) ;
V_78:
if ( ! F_30 ( V_59 ) )
F_39 ( V_59 ) ;
V_63:
if ( ! F_30 ( V_59 ) )
F_40 ( V_59 ) ;
F_41 ( V_18 ) ;
V_62:
return V_9 ;
}
static int T_7 F_42 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_43 ( V_2 ) ;
struct V_22 * V_23 = F_11 ( V_18 ) ;
F_44 ( V_18 ) ;
if ( V_2 -> V_49 )
F_38 ( V_2 -> V_49 , V_18 ) ;
if ( ! F_30 ( V_23 -> V_59 ) ) {
F_39 ( V_23 -> V_59 ) ;
F_40 ( V_23 -> V_59 ) ;
}
F_41 ( V_18 ) ;
return 0 ;
}
