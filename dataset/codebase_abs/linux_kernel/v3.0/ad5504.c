static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
T_2 V_5 = F_2 ( V_6 |
F_3 ( V_3 ) |
( V_4 & V_7 ) ) ;
return F_4 ( V_2 , ( T_1 * ) & V_5 , 2 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
T_2 V_5 = F_2 ( V_8 | F_3 ( V_3 ) ) ;
int V_9 ;
struct V_10 V_11 = {
. V_12 = & V_5 ,
. V_13 = V_4 ,
. V_14 = 2 ,
} ;
struct V_15 V_16 ;
F_6 ( & V_16 ) ;
F_7 ( & V_11 , & V_16 ) ;
V_9 = F_8 ( V_2 , & V_16 ) ;
* V_4 = F_9 ( * V_4 ) & V_7 ;
return V_9 ;
}
static T_3 F_10 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
const char * V_21 , T_4 V_14 )
{
struct V_22 * V_23 = F_11 ( V_18 ) ;
struct V_24 * V_25 = F_12 ( V_23 ) ;
struct V_26 * V_27 = F_13 ( V_20 ) ;
long V_28 ;
int V_9 ;
V_9 = F_14 ( V_21 , 10 , & V_28 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_1 ( V_25 -> V_2 , V_27 -> V_29 , V_28 ) ;
return V_9 ? V_9 : V_14 ;
}
static T_3 F_15 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_18 ) ;
struct V_24 * V_25 = F_12 ( V_23 ) ;
struct V_26 * V_27 = F_13 ( V_20 ) ;
int V_9 ;
T_2 V_4 ;
V_9 = F_5 ( V_25 -> V_2 , V_27 -> V_29 , & V_4 ) ;
if ( V_9 )
return V_9 ;
return sprintf ( V_21 , L_1 , V_4 ) ;
}
static T_3 F_16 ( struct V_17 * V_18 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_18 ) ;
struct V_24 * V_25 = F_12 ( V_23 ) ;
const char V_30 [] [ 14 ] = { L_2 , L_3 } ;
return sprintf ( V_21 , L_4 , V_30 [ V_25 -> V_31 ] ) ;
}
static T_3 F_17 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
const char * V_21 , T_4 V_14 )
{
struct V_22 * V_23 = F_11 ( V_18 ) ;
struct V_24 * V_25 = F_12 ( V_23 ) ;
int V_9 ;
if ( F_18 ( V_21 , L_2 ) )
V_25 -> V_31 = V_32 ;
else if ( F_18 ( V_21 , L_3 ) )
V_25 -> V_31 = V_33 ;
else
V_9 = - V_34 ;
return V_9 ? V_9 : V_14 ;
}
static T_3 F_19 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_18 ) ;
struct V_24 * V_25 = F_12 ( V_23 ) ;
struct V_26 * V_27 = F_13 ( V_20 ) ;
return sprintf ( V_21 , L_1 ,
! ( V_25 -> V_35 & ( 1 << V_27 -> V_29 ) ) ) ;
}
static T_3 F_20 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
const char * V_21 , T_4 V_14 )
{
long V_28 ;
int V_9 ;
struct V_22 * V_23 = F_11 ( V_18 ) ;
struct V_24 * V_25 = F_12 ( V_23 ) ;
struct V_26 * V_27 = F_13 ( V_20 ) ;
V_9 = F_14 ( V_21 , 10 , & V_28 ) ;
if ( V_9 )
return V_9 ;
if ( V_28 == 0 )
V_25 -> V_35 |= ( 1 << V_27 -> V_29 ) ;
else if ( V_28 == 1 )
V_25 -> V_35 &= ~ ( 1 << V_27 -> V_29 ) ;
else
V_9 = - V_34 ;
V_9 = F_1 ( V_25 -> V_2 , V_36 ,
F_21 ( V_25 -> V_31 ) |
F_22 ( V_25 -> V_35 ) ) ;
F_1 ( V_25 -> V_2 , V_37 , 0 ) ;
return V_9 ? V_9 : V_14 ;
}
static T_3 F_23 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_11 ( V_18 ) ;
struct V_24 * V_25 = F_12 ( V_23 ) ;
unsigned int V_38 = ( V_25 -> V_39 * 1000 ) >> V_40 ;
return sprintf ( V_21 , L_5 , V_38 / 1000 , V_38 % 1000 ) ;
}
static T_5 F_24 ( int V_41 , void * V_42 )
{
F_25 ( V_42 , 0 ,
F_26 ( V_43 ,
0 ,
V_44 ,
V_45 ) ,
F_27 () ) ;
return V_46 ;
}
static int T_6 F_28 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = V_2 -> V_18 . V_49 ;
struct V_24 * V_25 ;
int V_9 , V_50 = 0 ;
V_25 = F_29 ( sizeof( * V_25 ) , V_51 ) ;
if ( V_25 == NULL ) {
V_9 = - V_52 ;
goto V_53;
}
F_30 ( V_2 , V_25 ) ;
V_25 -> V_54 = F_31 ( & V_2 -> V_18 , L_6 ) ;
if ( ! F_32 ( V_25 -> V_54 ) ) {
V_9 = F_33 ( V_25 -> V_54 ) ;
if ( V_9 )
goto V_55;
V_50 = F_34 ( V_25 -> V_54 ) ;
}
if ( V_50 )
V_25 -> V_39 = V_50 / 1000 ;
else if ( V_48 )
V_25 -> V_39 = V_48 -> V_39 ;
else
F_35 ( & V_2 -> V_18 , L_7 ) ;
V_25 -> V_2 = V_2 ;
V_25 -> V_23 = F_36 ( 0 ) ;
if ( V_25 -> V_23 == NULL ) {
V_9 = - V_52 ;
goto V_56;
}
V_25 -> V_23 -> V_18 . V_57 = & V_2 -> V_18 ;
V_25 -> V_23 -> V_58 = F_37 ( V_25 -> V_2 ) -> V_58 ;
if ( F_37 ( V_25 -> V_2 ) -> V_59 == V_60 )
V_25 -> V_23 -> V_61 = & V_62 ;
else
V_25 -> V_23 -> V_61 = & V_63 ;
V_25 -> V_23 -> V_64 = ( void * ) ( V_25 ) ;
V_25 -> V_23 -> V_65 = V_66 ;
V_9 = F_38 ( V_25 -> V_23 ) ;
if ( V_9 )
goto V_67;
if ( V_2 -> V_41 ) {
V_9 = F_39 ( V_2 -> V_41 ,
NULL ,
& F_24 ,
V_68 | V_69 ,
F_37 ( V_25 -> V_2 ) -> V_58 ,
V_25 -> V_23 ) ;
if ( V_9 )
goto V_70;
}
return 0 ;
V_70:
F_40 ( V_25 -> V_23 ) ;
V_67:
F_41 ( V_25 -> V_23 ) ;
V_56:
if ( ! F_32 ( V_25 -> V_54 ) )
F_42 ( V_25 -> V_54 ) ;
V_55:
if ( ! F_32 ( V_25 -> V_54 ) )
F_43 ( V_25 -> V_54 ) ;
F_44 ( V_25 ) ;
V_53:
return V_9 ;
}
static int T_7 F_45 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_46 ( V_2 ) ;
if ( V_2 -> V_41 )
F_47 ( V_2 -> V_41 , V_25 -> V_23 ) ;
F_40 ( V_25 -> V_23 ) ;
if ( ! F_32 ( V_25 -> V_54 ) ) {
F_42 ( V_25 -> V_54 ) ;
F_43 ( V_25 -> V_54 ) ;
}
F_44 ( V_25 ) ;
return 0 ;
}
static T_8 int F_48 ( void )
{
return F_49 ( & V_71 ) ;
}
static T_9 void F_50 ( void )
{
F_51 ( & V_71 ) ;
}
