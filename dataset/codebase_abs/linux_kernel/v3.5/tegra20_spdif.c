static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
F_4 ( V_2 -> V_5 , V_3 , & V_4 ) ;
return V_4 ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
F_7 ( V_2 -> V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
int V_9 ;
V_9 = F_9 ( V_2 -> V_8 ) ;
if ( V_9 ) {
F_10 ( V_7 , L_1 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static int F_11 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_6 * V_7 = V_11 -> V_16 -> V_17 -> V_7 ;
struct V_1 * V_2 = F_12 ( V_15 ) ;
int V_9 , V_18 ;
V_2 -> V_19 &= ~ V_20 ;
V_2 -> V_19 &= ~ V_21 ;
switch ( F_13 ( V_13 ) ) {
case V_22 :
V_2 -> V_19 |= V_20 ;
V_2 -> V_19 |= V_23 ;
break;
default:
return - V_24 ;
}
switch ( F_14 ( V_13 ) ) {
case 32000 :
V_18 = 4096000 ;
break;
case 44100 :
V_18 = 5644800 ;
break;
case 48000 :
V_18 = 6144000 ;
break;
case 88200 :
V_18 = 11289600 ;
break;
case 96000 :
V_18 = 12288000 ;
break;
case 176400 :
V_18 = 22579200 ;
break;
case 192000 :
V_18 = 24576000 ;
break;
default:
return - V_24 ;
}
V_9 = F_15 ( V_2 -> V_8 , V_18 ) ;
if ( V_9 ) {
F_10 ( V_7 , L_2 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
V_2 -> V_19 |= V_25 ;
F_1 ( V_2 , V_26 , V_2 -> V_19 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
V_2 -> V_19 &= ~ V_25 ;
F_1 ( V_2 , V_26 , V_2 -> V_19 ) ;
}
static int F_18 ( struct V_10 * V_11 , int V_27 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_12 ( V_15 ) ;
switch ( V_27 ) {
case V_28 :
case V_29 :
case V_30 :
F_16 ( V_2 ) ;
break;
case V_31 :
case V_32 :
case V_33 :
F_17 ( V_2 ) ;
break;
default:
return - V_24 ;
}
return 0 ;
}
static int F_19 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_12 ( V_15 ) ;
V_15 -> V_34 = NULL ;
V_15 -> V_35 = & V_2 -> V_35 ;
return 0 ;
}
static bool F_20 ( struct V_6 * V_7 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_26 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
return true ;
default:
return false ;
} ;
}
static bool F_21 ( struct V_6 * V_7 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_36 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_53 :
case V_54 :
return true ;
default:
return false ;
} ;
}
static bool F_22 ( struct V_6 * V_7 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_39 :
case V_40 :
case V_53 :
case V_54 :
return true ;
default:
return false ;
} ;
}
static T_2 int F_23 ( struct V_55 * V_56 )
{
struct V_1 * V_2 ;
struct V_57 * V_58 , * V_59 , * V_60 ;
void T_3 * V_61 ;
int V_9 ;
V_2 = F_24 ( & V_56 -> V_7 , sizeof( struct V_1 ) ,
V_62 ) ;
if ( ! V_2 ) {
F_10 ( & V_56 -> V_7 , L_3 ) ;
V_9 = - V_63 ;
goto V_64;
}
F_25 ( & V_56 -> V_7 , V_2 ) ;
V_2 -> V_8 = F_26 ( & V_56 -> V_7 , L_4 ) ;
if ( F_27 ( V_2 -> V_8 ) ) {
F_28 ( L_5 ) ;
V_9 = F_29 ( V_2 -> V_8 ) ;
goto V_64;
}
V_58 = F_30 ( V_56 , V_65 , 0 ) ;
if ( ! V_58 ) {
F_10 ( & V_56 -> V_7 , L_6 ) ;
V_9 = - V_66 ;
goto V_67;
}
V_60 = F_30 ( V_56 , V_68 , 0 ) ;
if ( ! V_60 ) {
F_10 ( & V_56 -> V_7 , L_7 ) ;
V_9 = - V_66 ;
goto V_67;
}
V_59 = F_31 ( & V_56 -> V_7 , V_58 -> V_69 ,
F_32 ( V_58 ) , V_70 ) ;
if ( ! V_59 ) {
F_10 ( & V_56 -> V_7 , L_8 ) ;
V_9 = - V_71 ;
goto V_67;
}
V_61 = F_33 ( & V_56 -> V_7 , V_58 -> V_69 , F_32 ( V_58 ) ) ;
if ( ! V_61 ) {
F_10 ( & V_56 -> V_7 , L_9 ) ;
V_9 = - V_63 ;
goto V_67;
}
V_2 -> V_5 = F_34 ( & V_56 -> V_7 , V_61 ,
& V_72 ) ;
if ( F_27 ( V_2 -> V_5 ) ) {
F_10 ( & V_56 -> V_7 , L_10 ) ;
V_9 = F_29 ( V_2 -> V_5 ) ;
goto V_67;
}
V_2 -> V_35 . V_73 = V_58 -> V_69 + V_39 ;
V_2 -> V_35 . V_74 = 4 ;
V_2 -> V_35 . V_75 = 32 ;
V_2 -> V_35 . V_76 = V_60 -> V_69 ;
F_35 ( & V_56 -> V_7 ) ;
if ( ! F_36 ( & V_56 -> V_7 ) ) {
V_9 = F_8 ( & V_56 -> V_7 ) ;
if ( V_9 )
goto V_77;
}
V_9 = F_37 ( & V_56 -> V_7 , & V_78 ) ;
if ( V_9 ) {
F_10 ( & V_56 -> V_7 , L_11 , V_9 ) ;
V_9 = - V_63 ;
goto V_79;
}
V_9 = F_38 ( & V_56 -> V_7 ) ;
if ( V_9 ) {
F_10 ( & V_56 -> V_7 , L_12 , V_9 ) ;
goto V_80;
}
return 0 ;
V_80:
F_39 ( & V_56 -> V_7 ) ;
V_79:
if ( ! F_40 ( & V_56 -> V_7 ) )
F_5 ( & V_56 -> V_7 ) ;
V_77:
F_41 ( & V_56 -> V_7 ) ;
V_67:
F_42 ( V_2 -> V_8 ) ;
V_64:
return V_9 ;
}
static int T_4 F_43 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_6 ( & V_56 -> V_7 ) ;
F_41 ( & V_56 -> V_7 ) ;
if ( ! F_40 ( & V_56 -> V_7 ) )
F_5 ( & V_56 -> V_7 ) ;
F_44 ( & V_56 -> V_7 ) ;
F_39 ( & V_56 -> V_7 ) ;
F_42 ( V_2 -> V_8 ) ;
return 0 ;
}
