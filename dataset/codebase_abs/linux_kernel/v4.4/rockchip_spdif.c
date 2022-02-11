static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
V_7 = F_5 ( V_4 -> V_5 ) ;
if ( V_7 ) {
F_6 ( V_4 -> V_2 , L_1 , V_7 ) ;
return V_7 ;
}
V_7 = F_5 ( V_4 -> V_6 ) ;
if ( V_7 ) {
F_6 ( V_4 -> V_2 , L_2 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_7 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_3 * V_4 = F_8 ( V_13 ) ;
unsigned int V_14 = V_15 ;
int V_16 , V_5 ;
int V_7 ;
V_16 = F_9 ( V_11 ) ;
switch ( V_16 ) {
case 32000 :
case 48000 :
case 96000 :
V_5 = 96000 * 128 ;
break;
case 44100 :
V_5 = 44100 * 256 ;
break;
case 192000 :
V_5 = 192000 * 128 ;
break;
default:
return - V_17 ;
}
switch ( F_10 ( V_11 ) ) {
case V_18 :
V_14 |= V_19 ;
break;
case V_20 :
V_14 |= V_21 ;
break;
case V_22 :
V_14 |= V_23 ;
break;
default:
return - V_17 ;
}
V_7 = F_11 ( V_4 -> V_5 , V_5 ) ;
if ( V_7 != 0 ) {
F_6 ( V_4 -> V_2 , L_3 ,
V_7 ) ;
return V_7 ;
}
V_14 |= F_12 ( V_5 / ( V_16 * 256 ) ) ;
V_7 = F_13 ( V_4 -> V_24 , V_25 ,
V_26 | V_15 |
V_27 ,
V_14 ) ;
return V_7 ;
}
static int F_14 ( struct V_8 * V_9 ,
int V_28 , struct V_12 * V_13 )
{
struct V_3 * V_4 = F_8 ( V_13 ) ;
int V_7 ;
switch ( V_28 ) {
case V_29 :
case V_30 :
case V_31 :
V_7 = F_13 ( V_4 -> V_24 , V_32 ,
V_33 |
V_34 ,
V_33 |
F_15 ( 16 ) ) ;
if ( V_7 != 0 )
return V_7 ;
V_7 = F_13 ( V_4 -> V_24 , V_35 ,
V_36 ,
V_36 ) ;
break;
case V_37 :
case V_38 :
case V_39 :
V_7 = F_13 ( V_4 -> V_24 , V_32 ,
V_33 ,
V_40 ) ;
if ( V_7 != 0 )
return V_7 ;
V_7 = F_13 ( V_4 -> V_24 , V_35 ,
V_36 ,
V_41 ) ;
break;
default:
V_7 = - V_17 ;
break;
}
return V_7 ;
}
static int F_16 ( struct V_12 * V_13 )
{
struct V_3 * V_4 = F_8 ( V_13 ) ;
V_13 -> V_42 = & V_4 -> V_42 ;
return 0 ;
}
static bool F_17 ( struct V_1 * V_2 , unsigned int V_43 )
{
switch ( V_43 ) {
case V_25 :
case V_32 :
case V_44 :
case V_35 :
case V_45 :
return true ;
default:
return false ;
}
}
static bool F_18 ( struct V_1 * V_2 , unsigned int V_43 )
{
switch ( V_43 ) {
case V_25 :
case V_46 :
case V_44 :
case V_47 :
case V_35 :
return true ;
default:
return false ;
}
}
static bool F_19 ( struct V_1 * V_2 , unsigned int V_43 )
{
switch ( V_43 ) {
case V_47 :
case V_46 :
return true ;
default:
return false ;
}
}
static int F_20 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = V_49 -> V_2 . V_52 ;
struct V_3 * V_4 ;
const struct V_53 * V_54 ;
struct V_55 * V_56 ;
void T_1 * V_57 ;
int V_7 ;
V_54 = F_21 ( V_58 , V_51 ) ;
if ( V_54 -> V_59 == ( void * ) V_60 ) {
struct V_24 * V_61 ;
V_61 = F_22 ( V_51 , L_4 ) ;
if ( F_23 ( V_61 ) ) {
F_6 ( & V_49 -> V_2 ,
L_5 ) ;
return F_24 ( V_61 ) ;
}
F_25 ( V_61 , V_62 , F_26 ( 1 ) << 16 ) ;
}
V_4 = F_27 ( & V_49 -> V_2 , sizeof( * V_4 ) , V_63 ) ;
if ( ! V_4 )
return - V_64 ;
V_4 -> V_6 = F_28 ( & V_49 -> V_2 , L_6 ) ;
if ( F_23 ( V_4 -> V_6 ) ) {
F_6 ( & V_49 -> V_2 , L_7 ) ;
return F_24 ( V_4 -> V_6 ) ;
}
V_7 = F_5 ( V_4 -> V_6 ) ;
if ( V_7 ) {
F_6 ( V_4 -> V_2 , L_8 , V_7 ) ;
return V_7 ;
}
V_4 -> V_5 = F_28 ( & V_49 -> V_2 , L_9 ) ;
if ( F_23 ( V_4 -> V_5 ) ) {
F_6 ( & V_49 -> V_2 , L_10 ) ;
return F_24 ( V_4 -> V_5 ) ;
}
V_7 = F_5 ( V_4 -> V_5 ) ;
if ( V_7 ) {
F_6 ( V_4 -> V_2 , L_11 , V_7 ) ;
return V_7 ;
}
V_56 = F_29 ( V_49 , V_65 , 0 ) ;
V_57 = F_30 ( & V_49 -> V_2 , V_56 ) ;
if ( F_23 ( V_57 ) )
return F_24 ( V_57 ) ;
V_4 -> V_24 = F_31 ( & V_49 -> V_2 , L_6 , V_57 ,
& V_66 ) ;
if ( F_23 ( V_4 -> V_24 ) ) {
F_6 ( & V_49 -> V_2 ,
L_12 ) ;
return F_24 ( V_4 -> V_24 ) ;
}
V_4 -> V_42 . V_67 = V_56 -> V_68 + V_45 ;
V_4 -> V_42 . V_69 = V_70 ;
V_4 -> V_42 . V_71 = 4 ;
V_4 -> V_2 = & V_49 -> V_2 ;
F_32 ( & V_49 -> V_2 , V_4 ) ;
F_33 ( & V_49 -> V_2 ) ;
F_34 ( & V_49 -> V_2 ) ;
F_35 ( & V_49 -> V_2 ) ;
V_7 = F_36 ( & V_49 -> V_2 ,
& V_72 ,
& V_73 , 1 ) ;
if ( V_7 ) {
F_6 ( & V_49 -> V_2 , L_13 ) ;
goto V_74;
}
V_7 = F_37 ( & V_49 -> V_2 , NULL , 0 ) ;
if ( V_7 ) {
F_6 ( & V_49 -> V_2 , L_14 ) ;
goto V_74;
}
return 0 ;
V_74:
F_38 ( & V_49 -> V_2 ) ;
return V_7 ;
}
static int F_39 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = F_2 ( & V_49 -> V_2 ) ;
F_38 ( & V_49 -> V_2 ) ;
if ( ! F_40 ( & V_49 -> V_2 ) )
F_1 ( & V_49 -> V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
return 0 ;
}
