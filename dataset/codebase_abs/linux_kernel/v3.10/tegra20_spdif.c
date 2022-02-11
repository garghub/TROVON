static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_5 ( V_4 -> V_5 ) ;
if ( V_6 ) {
F_6 ( V_2 , L_1 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_7 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 = F_8 ( V_12 ) ;
unsigned int V_13 , V_14 ;
int V_6 , V_15 ;
V_13 = V_16 |
V_17 ;
switch ( F_9 ( V_10 ) ) {
case V_18 :
V_14 = V_16 |
V_19 ;
break;
default:
return - V_20 ;
}
F_10 ( V_4 -> V_21 , V_22 , V_13 , V_14 ) ;
switch ( F_11 ( V_10 ) ) {
case 32000 :
V_15 = 4096000 ;
break;
case 44100 :
V_15 = 5644800 ;
break;
case 48000 :
V_15 = 6144000 ;
break;
case 88200 :
V_15 = 11289600 ;
break;
case 96000 :
V_15 = 12288000 ;
break;
case 176400 :
V_15 = 22579200 ;
break;
case 192000 :
V_15 = 24576000 ;
break;
default:
return - V_20 ;
}
V_6 = F_12 ( V_4 -> V_5 , V_15 ) ;
if ( V_6 ) {
F_6 ( V_2 , L_2 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static void F_13 ( struct V_3 * V_4 )
{
F_10 ( V_4 -> V_21 , V_22 ,
V_23 ,
V_23 ) ;
}
static void F_14 ( struct V_3 * V_4 )
{
F_10 ( V_4 -> V_21 , V_22 ,
V_23 , 0 ) ;
}
static int F_15 ( struct V_7 * V_8 , int V_24 ,
struct V_11 * V_12 )
{
struct V_3 * V_4 = F_8 ( V_12 ) ;
switch ( V_24 ) {
case V_25 :
case V_26 :
case V_27 :
F_13 ( V_4 ) ;
break;
case V_28 :
case V_29 :
case V_30 :
F_14 ( V_4 ) ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = F_8 ( V_12 ) ;
V_12 -> V_31 = NULL ;
V_12 -> V_32 = & V_4 -> V_32 ;
return 0 ;
}
static bool F_17 ( struct V_1 * V_2 , unsigned int V_33 )
{
switch ( V_33 ) {
case V_22 :
case V_34 :
case V_35 :
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
return true ;
default:
return false ;
} ;
}
static bool F_18 ( struct V_1 * V_2 , unsigned int V_33 )
{
switch ( V_33 ) {
case V_34 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_51 :
case V_52 :
return true ;
default:
return false ;
} ;
}
static bool F_19 ( struct V_1 * V_2 , unsigned int V_33 )
{
switch ( V_33 ) {
case V_37 :
case V_38 :
case V_51 :
case V_52 :
return true ;
default:
return false ;
} ;
}
static int F_20 ( struct V_53 * V_54 )
{
struct V_3 * V_4 ;
struct V_55 * V_56 , * V_57 , * V_58 ;
void T_1 * V_59 ;
int V_6 ;
V_4 = F_21 ( & V_54 -> V_2 , sizeof( struct V_3 ) ,
V_60 ) ;
if ( ! V_4 ) {
F_6 ( & V_54 -> V_2 , L_3 ) ;
V_6 = - V_61 ;
goto V_62;
}
F_22 ( & V_54 -> V_2 , V_4 ) ;
V_4 -> V_5 = F_23 ( & V_54 -> V_2 , L_4 ) ;
if ( F_24 ( V_4 -> V_5 ) ) {
F_25 ( L_5 ) ;
V_6 = F_26 ( V_4 -> V_5 ) ;
goto V_62;
}
V_56 = F_27 ( V_54 , V_63 , 0 ) ;
if ( ! V_56 ) {
F_6 ( & V_54 -> V_2 , L_6 ) ;
V_6 = - V_64 ;
goto V_65;
}
V_58 = F_27 ( V_54 , V_66 , 0 ) ;
if ( ! V_58 ) {
F_6 ( & V_54 -> V_2 , L_7 ) ;
V_6 = - V_64 ;
goto V_65;
}
V_57 = F_28 ( & V_54 -> V_2 , V_56 -> V_67 ,
F_29 ( V_56 ) , V_68 ) ;
if ( ! V_57 ) {
F_6 ( & V_54 -> V_2 , L_8 ) ;
V_6 = - V_69 ;
goto V_65;
}
V_59 = F_30 ( & V_54 -> V_2 , V_56 -> V_67 , F_29 ( V_56 ) ) ;
if ( ! V_59 ) {
F_6 ( & V_54 -> V_2 , L_9 ) ;
V_6 = - V_61 ;
goto V_65;
}
V_4 -> V_21 = F_31 ( & V_54 -> V_2 , V_59 ,
& V_70 ) ;
if ( F_24 ( V_4 -> V_21 ) ) {
F_6 ( & V_54 -> V_2 , L_10 ) ;
V_6 = F_26 ( V_4 -> V_21 ) ;
goto V_65;
}
V_4 -> V_32 . V_71 = V_56 -> V_67 + V_37 ;
V_4 -> V_31 . V_72 = V_73 ;
V_4 -> V_31 . V_74 = 4 ;
V_4 -> V_32 . V_75 = V_58 -> V_67 ;
F_32 ( & V_54 -> V_2 ) ;
if ( ! F_33 ( & V_54 -> V_2 ) ) {
V_6 = F_4 ( & V_54 -> V_2 ) ;
if ( V_6 )
goto V_76;
}
V_6 = F_34 ( & V_54 -> V_2 , & V_77 ,
& V_78 , 1 ) ;
if ( V_6 ) {
F_6 ( & V_54 -> V_2 , L_11 , V_6 ) ;
V_6 = - V_61 ;
goto V_79;
}
V_6 = F_35 ( & V_54 -> V_2 ) ;
if ( V_6 ) {
F_6 ( & V_54 -> V_2 , L_12 , V_6 ) ;
goto V_80;
}
return 0 ;
V_80:
F_36 ( & V_54 -> V_2 ) ;
V_79:
if ( ! F_37 ( & V_54 -> V_2 ) )
F_1 ( & V_54 -> V_2 ) ;
V_76:
F_38 ( & V_54 -> V_2 ) ;
V_65:
F_39 ( V_4 -> V_5 ) ;
V_62:
return V_6 ;
}
static int F_40 ( struct V_53 * V_54 )
{
struct V_3 * V_4 = F_2 ( & V_54 -> V_2 ) ;
F_38 ( & V_54 -> V_2 ) ;
if ( ! F_37 ( & V_54 -> V_2 ) )
F_1 ( & V_54 -> V_2 ) ;
F_41 ( & V_54 -> V_2 ) ;
F_36 ( & V_54 -> V_2 ) ;
F_39 ( V_4 -> V_5 ) ;
return 0 ;
}
