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
struct V_1 * V_2 = F_10 ( V_20 ) ;
int V_21 ;
long V_3 ;
V_21 = F_11 ( V_17 , 10 , & V_3 ) ;
if ( V_21 )
goto V_22;
if ( V_3 > F_12 ( V_2 -> V_7 -> V_23 ) ) {
V_21 = - V_24 ;
goto V_22;
}
F_13 ( & V_20 -> V_25 ) ;
V_2 -> V_26 = V_3 ;
V_2 -> V_7 -> V_27 ( V_2 , V_3 ) ;
V_21 = F_14 ( V_2 -> V_28 , & V_2 -> V_29 ) ;
F_15 ( & V_20 -> V_25 ) ;
V_22:
return V_21 ? V_21 : V_18 ;
}
static T_1 F_16 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
char * V_17 )
{
struct V_19 * V_20 = F_9 ( V_14 ) ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
unsigned int V_30 = ( V_2 -> V_31 * 1000 ) >> V_2 -> V_7 -> V_23 ;
return sprintf ( V_17 , L_1 , V_30 / 1000 , V_30 % 1000 ) ;
}
static T_1 F_17 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
const char * V_17 , T_2 V_18 )
{
struct V_19 * V_20 = F_9 ( V_14 ) ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
if ( F_18 ( V_17 , L_2 ) )
V_2 -> V_32 = V_33 ;
else if ( F_18 ( V_17 , L_3 ) )
V_2 -> V_32 = V_34 ;
else if ( F_18 ( V_17 , L_4 ) )
V_2 -> V_32 = V_35 ;
else
return - V_24 ;
return V_18 ;
}
static T_1 F_19 ( struct V_13 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_19 * V_20 = F_9 ( V_14 ) ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
char V_12 [] [ 15 ] = { L_5 , L_2 , L_3 , L_4 } ;
return sprintf ( V_17 , L_6 , V_12 [ V_2 -> V_32 ] ) ;
}
static T_1 F_20 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
char * V_17 )
{
struct V_19 * V_20 = F_9 ( V_14 ) ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
return sprintf ( V_17 , L_7 , V_2 -> V_36 ) ;
}
static T_1 F_21 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
const char * V_17 , T_2 V_18 )
{
struct V_19 * V_20 = F_9 ( V_14 ) ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
unsigned long V_37 ;
int V_21 ;
V_21 = F_11 ( V_17 , 10 , & V_37 ) ;
if ( V_21 )
return V_21 ;
if ( V_37 > 1 )
V_21 = - V_24 ;
F_13 ( & V_20 -> V_25 ) ;
V_2 -> V_36 = V_37 ;
if ( V_2 -> V_36 )
V_2 -> V_7 -> V_38 ( V_2 , V_2 -> V_32 ) ;
else
V_2 -> V_7 -> V_27 ( V_2 , V_2 -> V_26 ) ;
V_21 = F_14 ( V_2 -> V_28 , & V_2 -> V_29 ) ;
F_15 ( & V_20 -> V_25 ) ;
return V_21 ? V_21 : V_18 ;
}
static T_3 F_22 ( struct V_39 * V_40 ,
struct V_41 * V_16 , int V_42 )
{
struct V_13 * V_14 = F_23 ( V_40 , struct V_13 , V_40 ) ;
struct V_19 * V_20 = F_9 ( V_14 ) ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
T_3 V_12 = V_16 -> V_12 ;
if ( ! V_2 -> V_7 -> V_38 &&
( V_16 == & V_43 . V_44 . V_16 ||
V_16 == & V_45 .
V_44 . V_16 ||
V_16 ==
& V_46 .
V_44 . V_16 ) )
V_12 = 0 ;
return V_12 ;
}
static int T_4 F_24 ( struct V_47 * V_28 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 ;
struct V_48 * V_49 ;
int V_21 , V_50 = 0 ;
V_49 = F_25 ( & V_28 -> V_14 , L_8 ) ;
if ( ! F_26 ( V_49 ) ) {
V_21 = F_27 ( V_49 ) ;
if ( V_21 )
goto V_51;
V_50 = F_28 ( V_49 ) ;
}
V_20 = F_29 ( sizeof( * V_2 ) ) ;
if ( V_20 == NULL ) {
V_21 = - V_52 ;
goto V_53;
}
V_2 = F_10 ( V_20 ) ;
V_2 -> V_7 =
& V_54 [ F_30 ( V_28 ) -> V_55 ] ;
F_31 ( V_28 , V_20 ) ;
V_2 -> V_49 = V_49 ;
V_2 -> V_28 = V_28 ;
V_20 -> V_14 . V_56 = & V_28 -> V_14 ;
V_20 -> V_57 = F_30 ( V_28 ) -> V_57 ;
V_20 -> V_58 = & V_59 ;
V_20 -> V_60 = V_61 ;
V_2 -> V_62 . V_63 = & V_2 -> V_4 ;
V_2 -> V_62 . V_18 = V_2 -> V_7 -> V_64 / 8 ;
F_32 ( & V_2 -> V_29 ) ;
F_33 ( & V_2 -> V_62 , & V_2 -> V_29 ) ;
switch ( F_30 ( V_28 ) -> V_55 ) {
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
V_2 -> V_31 = V_2 -> V_7 -> V_71 ;
break;
default:
if ( V_50 )
V_2 -> V_31 = V_50 / 1000 ;
else
F_34 ( & V_28 -> V_14 ,
L_9 ) ;
}
V_21 = F_35 ( V_20 ) ;
if ( V_21 )
goto V_72;
return 0 ;
V_72:
F_36 ( V_20 ) ;
V_53:
if ( ! F_26 ( V_49 ) )
F_37 ( V_49 ) ;
V_51:
if ( ! F_26 ( V_49 ) )
F_38 ( V_49 ) ;
return V_21 ;
}
static int F_39 ( struct V_47 * V_28 )
{
struct V_19 * V_20 = F_40 ( V_28 ) ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
F_41 ( V_20 ) ;
if ( ! F_26 ( V_2 -> V_49 ) ) {
F_37 ( V_2 -> V_49 ) ;
F_38 ( V_2 -> V_49 ) ;
}
F_36 ( V_20 ) ;
return 0 ;
}
static int T_5 F_42 ( void )
{
return F_43 ( & V_73 ) ;
}
static void T_6 F_44 ( void )
{
F_45 ( & V_73 ) ;
}
