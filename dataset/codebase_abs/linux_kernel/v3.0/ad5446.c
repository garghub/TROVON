static void F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
V_2 -> V_4 . V_5 = F_2 ( V_6 |
( V_3 << V_2 -> V_7 -> V_8 ) ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned V_3 )
{
V_2 -> V_4 . V_5 = F_2 ( V_3 << V_2 -> V_7 -> V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
V_2 -> V_4 . V_5 = F_2 ( V_9 |
( V_3 << V_2 -> V_7 -> V_8 ) ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
V_3 |= V_10 ;
V_2 -> V_4 . V_11 [ 0 ] = ( V_3 >> 16 ) & 0xFF ;
V_2 -> V_4 . V_11 [ 1 ] = ( V_3 >> 8 ) & 0xFF ;
V_2 -> V_4 . V_11 [ 2 ] = V_3 & 0xFF ;
}
static void F_6 ( struct V_1 * V_2 , unsigned V_12 )
{
V_2 -> V_4 . V_5 = F_2 ( V_12 << 14 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned V_12 )
{
unsigned V_3 = V_12 << 16 ;
V_2 -> V_4 . V_11 [ 0 ] = ( V_3 >> 16 ) & 0xFF ;
V_2 -> V_4 . V_11 [ 1 ] = ( V_3 >> 8 ) & 0xFF ;
V_2 -> V_4 . V_11 [ 2 ] = V_3 & 0xFF ;
}
static T_1 F_8 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
const char * V_17 ,
T_2 V_18 )
{
struct V_19 * V_20 = F_9 ( V_14 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
int V_22 ;
long V_3 ;
V_22 = F_10 ( V_17 , 10 , & V_3 ) ;
if ( V_22 )
goto V_23;
if ( V_3 > F_11 ( V_2 -> V_7 -> V_24 ) ) {
V_22 = - V_25 ;
goto V_23;
}
F_12 ( & V_20 -> V_26 ) ;
V_2 -> V_27 = V_3 ;
V_2 -> V_7 -> V_28 ( V_2 , V_3 ) ;
V_22 = F_13 ( V_2 -> V_29 , & V_2 -> V_30 ) ;
F_14 ( & V_20 -> V_26 ) ;
V_23:
return V_22 ? V_22 : V_18 ;
}
static T_1 F_15 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
char * V_17 )
{
struct V_19 * V_20 = F_9 ( V_14 ) ;
struct V_1 * V_2 = F_16 ( V_20 ) ;
unsigned int V_31 = ( V_2 -> V_32 * 1000 ) >> V_2 -> V_7 -> V_24 ;
return sprintf ( V_17 , L_1 , V_31 / 1000 , V_31 % 1000 ) ;
}
static T_1 F_17 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
const char * V_17 , T_2 V_18 )
{
struct V_19 * V_20 = F_9 ( V_14 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
if ( F_18 ( V_17 , L_2 ) )
V_2 -> V_33 = V_34 ;
else if ( F_18 ( V_17 , L_3 ) )
V_2 -> V_33 = V_35 ;
else if ( F_18 ( V_17 , L_4 ) )
V_2 -> V_33 = V_36 ;
else
return - V_25 ;
return V_18 ;
}
static T_1 F_19 ( struct V_13 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_19 * V_20 = F_9 ( V_14 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
char V_12 [] [ 15 ] = { L_5 , L_2 , L_3 , L_4 } ;
return sprintf ( V_17 , L_6 , V_12 [ V_2 -> V_33 ] ) ;
}
static T_1 F_20 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
char * V_17 )
{
struct V_19 * V_20 = F_9 ( V_14 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
return sprintf ( V_17 , L_7 , V_2 -> V_37 ) ;
}
static T_1 F_21 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
const char * V_17 , T_2 V_18 )
{
struct V_19 * V_20 = F_9 ( V_14 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
unsigned long V_38 ;
int V_22 ;
V_22 = F_10 ( V_17 , 10 , & V_38 ) ;
if ( V_22 )
return V_22 ;
if ( V_38 > 1 )
V_22 = - V_25 ;
F_12 ( & V_20 -> V_26 ) ;
V_2 -> V_37 = V_38 ;
if ( V_2 -> V_37 )
V_2 -> V_7 -> V_39 ( V_2 , V_2 -> V_33 ) ;
else
V_2 -> V_7 -> V_28 ( V_2 , V_2 -> V_27 ) ;
V_22 = F_13 ( V_2 -> V_29 , & V_2 -> V_30 ) ;
F_14 ( & V_20 -> V_26 ) ;
return V_22 ? V_22 : V_18 ;
}
static T_3 F_22 ( struct V_40 * V_41 ,
struct V_42 * V_16 , int V_43 )
{
struct V_13 * V_14 = F_23 ( V_41 , struct V_13 , V_41 ) ;
struct V_19 * V_20 = F_9 ( V_14 ) ;
struct V_1 * V_2 = F_16 ( V_20 ) ;
T_3 V_12 = V_16 -> V_12 ;
if ( ! V_2 -> V_7 -> V_39 &&
( V_16 == & V_44 . V_45 . V_16 ||
V_16 == & V_46 . V_45 . V_16 ||
V_16 ==
& V_47 . V_45 . V_16 ) )
V_12 = 0 ;
return V_12 ;
}
static int T_4 F_24 ( struct V_48 * V_29 )
{
struct V_1 * V_2 ;
int V_22 , V_49 = 0 ;
V_2 = F_25 ( sizeof( * V_2 ) , V_50 ) ;
if ( V_2 == NULL ) {
V_22 = - V_51 ;
goto V_23;
}
V_2 -> V_52 = F_26 ( & V_29 -> V_14 , L_8 ) ;
if ( ! F_27 ( V_2 -> V_52 ) ) {
V_22 = F_28 ( V_2 -> V_52 ) ;
if ( V_22 )
goto V_53;
V_49 = F_29 ( V_2 -> V_52 ) ;
}
V_2 -> V_7 =
& V_54 [ F_30 ( V_29 ) -> V_55 ] ;
F_31 ( V_29 , V_2 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_56 = F_32 ( 0 ) ;
if ( V_2 -> V_56 == NULL ) {
V_22 = - V_51 ;
goto V_57;
}
V_2 -> V_56 -> V_14 . V_58 = & V_29 -> V_14 ;
V_2 -> V_56 -> V_59 = F_30 ( V_29 ) -> V_59 ;
V_2 -> V_56 -> V_60 = & V_61 ;
V_2 -> V_56 -> V_21 = ( void * ) ( V_2 ) ;
V_2 -> V_56 -> V_62 = V_63 ;
V_2 -> V_64 . V_65 = & V_2 -> V_4 ;
V_2 -> V_64 . V_18 = V_2 -> V_7 -> V_66 / 8 ;
F_33 ( & V_2 -> V_30 ) ;
F_34 ( & V_2 -> V_64 , & V_2 -> V_30 ) ;
switch ( F_30 ( V_29 ) -> V_55 ) {
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
V_2 -> V_32 = V_2 -> V_7 -> V_73 ;
break;
default:
if ( V_49 )
V_2 -> V_32 = V_49 / 1000 ;
else
F_35 ( & V_29 -> V_14 ,
L_9 ) ;
}
V_22 = F_36 ( V_2 -> V_56 ) ;
if ( V_22 )
goto V_74;
return 0 ;
V_74:
F_37 ( V_2 -> V_56 ) ;
V_57:
if ( ! F_27 ( V_2 -> V_52 ) )
F_38 ( V_2 -> V_52 ) ;
V_53:
if ( ! F_27 ( V_2 -> V_52 ) )
F_39 ( V_2 -> V_52 ) ;
F_40 ( V_2 ) ;
V_23:
return V_22 ;
}
static int F_41 ( struct V_48 * V_29 )
{
struct V_1 * V_2 = F_42 ( V_29 ) ;
struct V_19 * V_56 = V_2 -> V_56 ;
F_43 ( V_56 ) ;
if ( ! F_27 ( V_2 -> V_52 ) ) {
F_38 ( V_2 -> V_52 ) ;
F_39 ( V_2 -> V_52 ) ;
}
F_40 ( V_2 ) ;
return 0 ;
}
static int T_5 F_44 ( void )
{
return F_45 ( & V_75 ) ;
}
static void T_6 F_46 ( void )
{
F_47 ( & V_75 ) ;
}
