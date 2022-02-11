static inline int F_1 ( int V_1 )
{
return F_2 ( V_1 * 2000 , 1023 ) + 2500 ;
}
static inline int F_3 ( int V_1 )
{
return F_2 ( V_1 * 2500 , 1023 ) ;
}
static inline int F_4 ( int V_1 )
{
return F_2 ( V_1 * 5000 , 1023 ) ;
}
static inline int F_5 ( struct V_2 * V_3 , int V_1 )
{
return F_2 ( V_1 * V_3 -> V_4 , 1023 ) ;
}
static inline int F_6 ( struct V_5 * V_5 )
{
return F_7 ( V_5 , V_6 ,
V_7 ,
V_7 ) ;
}
static inline int F_8 ( struct V_5 * V_5 )
{
return F_7 ( V_5 , V_6 ,
V_7 , 0 ) ;
}
static T_1 F_9 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_2 * V_3 = F_10 ( V_9 ) ;
int V_13 , V_14 ;
F_11 ( & V_3 -> V_15 ) ;
V_13 = F_6 ( V_3 -> V_5 ) ;
if ( V_13 < 0 )
goto V_16;
V_14 = F_12 ( V_3 -> V_5 , V_17 ) ;
if ( V_14 < 0 ) {
V_13 = V_14 ;
goto V_18;
}
V_13 = F_8 ( V_3 -> V_5 ) ;
if ( V_13 < 0 )
goto V_16;
F_13 ( & V_3 -> V_15 ) ;
return sprintf ( V_12 , L_1 , F_1 ( V_14 ) ) ;
V_18:
F_8 ( V_3 -> V_5 ) ;
V_16:
F_13 ( & V_3 -> V_15 ) ;
return V_13 ;
}
static T_1 F_14 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_2 * V_3 = F_10 ( V_9 ) ;
int V_13 ;
V_13 = F_12 ( V_3 -> V_5 , V_19 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_12 , L_1 , F_2 ( V_13 * 39 , 10 ) ) ;
}
static T_1 F_15 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_2 * V_3 = F_10 ( V_9 ) ;
return sprintf ( V_12 , L_1 , F_16 ( V_3 -> V_5 ) ) ;
}
static T_1 F_17 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_2 * V_3 = F_10 ( V_9 ) ;
int V_13 ;
V_13 = F_18 ( V_3 -> V_5 , V_20 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_12 , L_1 , F_1 ( V_13 ) ) ;
}
static T_1 F_19 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_2 * V_3 = F_10 ( V_9 ) ;
int V_21 = F_20 ( V_11 ) -> V_22 ;
int V_13 ;
V_13 = F_18 ( V_3 -> V_5 , V_21 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_12 , L_1 , F_3 ( V_13 ) ) ;
}
static int F_21 ( struct V_2 * V_3 , int V_21 )
{
T_2 V_23 = V_24 ;
switch ( V_21 ) {
case V_25 :
V_23 |= V_26 ;
break;
case V_27 :
V_23 |= V_28 ;
break;
case V_29 :
V_23 |= V_30 ;
break;
case V_31 :
V_23 |= V_32 ;
break;
}
return F_22 ( V_3 -> V_5 , V_33 , V_23 ) ;
}
static int F_23 ( struct V_2 * V_3 , int V_21 )
{
T_2 V_34 [ 3 ] ;
int V_35 , V_36 , V_37 ;
V_37 = F_24 ( V_3 -> V_5 , V_38 ,
F_25 ( V_34 ) , V_34 ) ;
if ( V_37 )
return V_37 ;
switch ( V_21 ) {
case V_25 :
case V_29 :
V_35 = V_34 [ 0 ] << V_39 ;
V_36 = V_34 [ 2 ] & V_40 ;
V_36 >>= V_41 ;
break;
case V_27 :
case V_31 :
V_35 = V_34 [ 1 ] << V_42 ;
V_36 = V_34 [ 2 ] & V_43 ;
V_36 >>= V_44 ;
break;
default:
return - V_45 ;
}
return V_35 | V_36 ;
}
static T_1 F_26 ( struct V_8 * V_9 , int V_21 )
{
struct V_2 * V_3 = F_10 ( V_9 ) ;
int V_13 ;
F_27 ( & V_3 -> V_46 ) ;
V_13 = F_21 ( V_3 , V_21 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ! F_28 ( & V_3 -> V_46 ,
F_29 ( 500 ) ) )
return - V_47 ;
return F_23 ( V_3 , V_21 ) ;
}
static T_1 F_30 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_2 * V_3 = F_10 ( V_9 ) ;
int V_21 = F_20 ( V_11 ) -> V_22 ;
int V_13 ;
F_11 ( & V_3 -> V_15 ) ;
V_13 = F_26 ( V_9 , V_21 ) ;
F_13 ( & V_3 -> V_15 ) ;
if ( V_13 < 0 )
return V_13 ;
else
return sprintf ( V_12 , L_1 , F_5 ( V_3 , V_13 ) ) ;
}
static T_1 F_31 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_2 * V_3 = F_10 ( V_9 ) ;
int V_48 ;
int V_49 ;
V_48 = F_12 ( V_3 -> V_5 , V_50 ) ;
if ( V_48 < 0 )
return V_48 ;
V_49 = F_12 ( V_3 -> V_5 , V_51 ) ;
if ( V_49 < 0 )
return V_49 ;
return sprintf ( V_12 , L_1 , 1708 * ( V_48 - V_49 ) - 108800 ) ;
}
static T_1 F_32 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_2 * V_3 = F_10 ( V_9 ) ;
int V_13 ;
V_13 = F_18 ( V_3 -> V_5 , V_52 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_12 , L_1 , F_4 ( V_13 ) ) ;
}
static T_1 F_33 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 )
{
return sprintf ( V_12 , L_2 ,
V_53 [ F_20 ( V_11 ) -> V_22 ] ) ;
}
static T_3 F_34 ( struct V_54 * V_55 ,
struct V_56 * V_57 , int V_22 )
{
struct V_8 * V_9 = F_35 ( V_55 , struct V_8 , V_55 ) ;
struct V_2 * V_3 = F_10 ( V_9 ) ;
struct V_10 * V_58 = F_35 ( V_57 ,
struct V_10 , V_57 ) ;
struct V_59 * V_60 = F_20 ( V_58 ) ;
if ( ! V_3 -> V_61 ) {
switch ( V_60 -> V_22 ) {
case V_25 :
case V_27 :
case V_29 :
case V_31 :
return 0 ;
}
}
return V_57 -> V_62 ;
}
static T_4 F_36 ( int V_63 , void * V_64 )
{
struct V_2 * V_3 = V_64 ;
F_37 ( & V_3 -> V_46 ) ;
return V_65 ;
}
static int F_38 ( struct V_66 * V_67 )
{
struct V_8 * V_9 = & V_67 -> V_9 ;
struct V_2 * V_3 ;
struct V_8 * V_68 ;
int V_37 ;
V_3 = F_39 ( V_9 , sizeof( struct V_2 ) , V_69 ) ;
if ( ! V_3 )
return - V_70 ;
F_40 ( V_67 , V_3 ) ;
F_41 ( & V_3 -> V_15 ) ;
V_3 -> V_5 = F_10 ( V_67 -> V_9 . V_71 ) ;
F_42 ( & V_3 -> V_46 ) ;
V_3 -> V_61 =
F_43 ( V_67 -> V_9 . V_71 , L_3 ) ;
if ( V_3 -> V_61 ) {
V_3 -> V_72 = F_44 ( V_67 -> V_9 . V_71 , L_4 ) ;
if ( F_45 ( V_3 -> V_72 ) ) {
V_37 = F_46 ( V_3 -> V_72 ) ;
F_47 ( & V_67 -> V_9 , L_5 , V_37 ) ;
return V_37 ;
}
V_37 = F_48 ( V_3 -> V_72 ) ;
if ( V_37 )
return V_37 ;
V_3 -> V_4 = F_49 ( V_3 -> V_72 ) ;
if ( V_3 -> V_4 < 0 ) {
V_37 = V_3 -> V_4 ;
goto V_73;
}
V_3 -> V_4 /= 1000 ;
if ( V_3 -> V_4 < 1800 || V_3 -> V_4 > 2600 ) {
F_47 ( V_3 -> V_5 -> V_9 , L_6 ,
V_3 -> V_4 ) ;
V_37 = - V_74 ;
goto V_73;
}
F_22 ( V_3 -> V_5 , V_75 , 0x00 ) ;
F_7 ( V_3 -> V_5 , V_6 ,
V_76 ,
V_76 ) ;
V_37 = F_50 ( V_3 -> V_5 , V_77 ,
L_7 , F_36 ,
V_3 ) ;
if ( V_37 ) {
F_47 ( & V_67 -> V_9 , L_8 ,
V_37 ) ;
goto V_73;
}
}
V_68 = F_51 ( V_9 , L_9 ,
V_3 ,
V_78 ) ;
V_37 = F_52 ( V_68 ) ;
if ( V_37 )
goto V_79;
return 0 ;
V_79:
if ( V_3 -> V_61 )
F_53 ( V_3 -> V_5 , V_77 , V_3 ) ;
V_73:
if ( V_3 -> V_72 )
F_54 ( V_3 -> V_72 ) ;
return V_37 ;
}
static int F_55 ( struct V_66 * V_67 )
{
struct V_2 * V_3 = F_56 ( V_67 ) ;
if ( V_3 -> V_61 ) {
F_53 ( V_3 -> V_5 , V_77 , V_3 ) ;
F_54 ( V_3 -> V_72 ) ;
}
return 0 ;
}
