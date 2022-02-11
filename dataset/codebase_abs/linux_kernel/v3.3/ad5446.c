static void F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
V_2 -> V_4 . V_5 = F_2 ( V_6 | V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned V_3 )
{
V_2 -> V_4 . V_5 = F_2 ( V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
V_2 -> V_4 . V_5 = F_2 ( V_7 | V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
V_3 |= V_8 ;
V_2 -> V_4 . V_9 [ 0 ] = ( V_3 >> 16 ) & 0xFF ;
V_2 -> V_4 . V_9 [ 1 ] = ( V_3 >> 8 ) & 0xFF ;
V_2 -> V_4 . V_9 [ 2 ] = V_3 & 0xFF ;
}
static void F_6 ( struct V_1 * V_2 , unsigned V_10 )
{
V_2 -> V_4 . V_5 = F_2 ( V_10 << 14 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned V_10 )
{
unsigned V_3 = V_10 << 16 ;
V_2 -> V_4 . V_9 [ 0 ] = ( V_3 >> 16 ) & 0xFF ;
V_2 -> V_4 . V_9 [ 1 ] = ( V_3 >> 8 ) & 0xFF ;
V_2 -> V_4 . V_9 [ 2 ] = V_3 & 0xFF ;
}
static T_1 F_8 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 , T_2 V_16 )
{
struct V_17 * V_18 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
if ( F_11 ( V_15 , L_1 ) )
V_2 -> V_19 = V_20 ;
else if ( F_11 ( V_15 , L_2 ) )
V_2 -> V_19 = V_21 ;
else if ( F_11 ( V_15 , L_3 ) )
V_2 -> V_19 = V_22 ;
else
return - V_23 ;
return V_16 ;
}
static T_1 F_12 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * V_15 )
{
struct V_17 * V_18 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
char V_10 [] [ 15 ] = { L_4 , L_1 , L_2 , L_3 } ;
return sprintf ( V_15 , L_5 , V_10 [ V_2 -> V_19 ] ) ;
}
static T_1 F_13 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_17 * V_18 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
return sprintf ( V_15 , L_6 , V_2 -> V_24 ) ;
}
static T_1 F_14 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
const char * V_15 , T_2 V_16 )
{
struct V_17 * V_18 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
unsigned long V_25 ;
int V_26 ;
V_26 = F_15 ( V_15 , 10 , & V_25 ) ;
if ( V_26 )
return V_26 ;
if ( V_25 > 1 )
V_26 = - V_23 ;
F_16 ( & V_18 -> V_27 ) ;
V_2 -> V_24 = V_25 ;
if ( V_2 -> V_24 )
V_2 -> V_28 -> V_29 ( V_2 , V_2 -> V_19 ) ;
else
V_2 -> V_28 -> V_30 ( V_2 , V_2 -> V_31 ) ;
V_26 = F_17 ( V_2 -> V_32 , & V_2 -> V_33 ) ;
F_18 ( & V_18 -> V_27 ) ;
return V_26 ? V_26 : V_16 ;
}
static T_3 F_19 ( struct V_34 * V_35 ,
struct V_36 * V_14 , int V_37 )
{
struct V_11 * V_12 = F_20 ( V_35 , struct V_11 , V_35 ) ;
struct V_17 * V_18 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
T_3 V_10 = V_14 -> V_10 ;
if ( ! V_2 -> V_28 -> V_29 &&
( V_14 == & V_38 . V_39 . V_14 ||
V_14 == & V_40 .
V_39 . V_14 ||
V_14 ==
& V_41 .
V_39 . V_14 ) )
V_10 = 0 ;
return V_10 ;
}
static int F_21 ( struct V_17 * V_18 ,
struct V_42 const * V_43 ,
int * V_3 ,
int * V_44 ,
long V_45 )
{
struct V_1 * V_2 = F_10 ( V_18 ) ;
unsigned long V_46 ;
switch ( V_45 ) {
case V_47 :
V_46 = ( V_2 -> V_48 * 1000 ) >> V_43 -> V_49 . V_50 ;
* V_3 = V_46 / 1000 ;
* V_44 = ( V_46 % 1000 ) * 1000 ;
return V_51 ;
}
return - V_23 ;
}
static int F_22 ( struct V_17 * V_18 ,
struct V_42 const * V_43 ,
int V_3 ,
int V_44 ,
long V_52 )
{
struct V_1 * V_2 = F_10 ( V_18 ) ;
int V_26 ;
switch ( V_52 ) {
case 0 :
if ( V_3 >= ( 1 << V_43 -> V_49 . V_50 ) || V_3 < 0 )
return - V_23 ;
V_3 <<= V_43 -> V_49 . V_53 ;
F_16 ( & V_18 -> V_27 ) ;
V_2 -> V_31 = V_3 ;
V_2 -> V_28 -> V_30 ( V_2 , V_3 ) ;
V_26 = F_17 ( V_2 -> V_32 , & V_2 -> V_33 ) ;
F_18 ( & V_18 -> V_27 ) ;
break;
default:
V_26 = - V_23 ;
}
return V_26 ;
}
static int T_4 F_23 ( struct V_54 * V_32 )
{
struct V_1 * V_2 ;
struct V_17 * V_18 ;
struct V_55 * V_56 ;
int V_26 , V_57 = 0 ;
V_56 = F_24 ( & V_32 -> V_12 , L_7 ) ;
if ( ! F_25 ( V_56 ) ) {
V_26 = F_26 ( V_56 ) ;
if ( V_26 )
goto V_58;
V_57 = F_27 ( V_56 ) ;
}
V_18 = F_28 ( sizeof( * V_2 ) ) ;
if ( V_18 == NULL ) {
V_26 = - V_59 ;
goto V_60;
}
V_2 = F_10 ( V_18 ) ;
V_2 -> V_28 =
& V_61 [ F_29 ( V_32 ) -> V_62 ] ;
F_30 ( V_32 , V_18 ) ;
V_2 -> V_56 = V_56 ;
V_2 -> V_32 = V_32 ;
V_18 -> V_12 . V_63 = & V_32 -> V_12 ;
V_18 -> V_64 = F_29 ( V_32 ) -> V_64 ;
V_18 -> V_65 = & V_66 ;
V_18 -> V_67 = V_68 ;
V_18 -> V_69 = & V_2 -> V_28 -> V_70 ;
V_18 -> V_71 = 1 ;
V_2 -> V_72 . V_73 = & V_2 -> V_4 ;
V_2 -> V_72 . V_16 = V_2 -> V_28 -> V_70 . V_49 . V_74 / 8 ;
F_31 ( & V_2 -> V_33 ) ;
F_32 ( & V_2 -> V_72 , & V_2 -> V_33 ) ;
switch ( F_29 ( V_32 ) -> V_62 ) {
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
V_2 -> V_48 = V_2 -> V_28 -> V_81 ;
break;
default:
if ( V_57 )
V_2 -> V_48 = V_57 / 1000 ;
else
F_33 ( & V_32 -> V_12 ,
L_8 ) ;
}
V_26 = F_34 ( V_18 ) ;
if ( V_26 )
goto V_82;
return 0 ;
V_82:
F_35 ( V_18 ) ;
V_60:
if ( ! F_25 ( V_56 ) )
F_36 ( V_56 ) ;
V_58:
if ( ! F_25 ( V_56 ) )
F_37 ( V_56 ) ;
return V_26 ;
}
static int F_38 ( struct V_54 * V_32 )
{
struct V_17 * V_18 = F_39 ( V_32 ) ;
struct V_1 * V_2 = F_10 ( V_18 ) ;
F_40 ( V_18 ) ;
if ( ! F_25 ( V_2 -> V_56 ) ) {
F_36 ( V_2 -> V_56 ) ;
F_37 ( V_2 -> V_56 ) ;
}
F_35 ( V_18 ) ;
return 0 ;
}
