static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
V_6 = F_2 ( V_4 -> V_7 + V_8 ) ;
if ( ! ( V_6 & ~ ( V_9 | V_10 ) ) ) {
F_3 ( V_4 -> V_7 + V_8 , V_6 ) ;
return;
}
F_4 ( L_1 ) ;
F_4 ( L_2 , V_6 ) ;
F_4 ( L_3 ,
F_2 ( V_4 -> V_7 + V_11 ) ) ;
F_4 ( L_4 ,
F_2 ( V_4 -> V_7 + V_12 ) ) ;
F_4 ( L_5 ,
F_2 ( V_4 -> V_7 + V_13 ) ) ;
F_4 ( L_6 ,
F_2 ( V_4 -> V_7 + V_14 ) ) ;
F_4 ( L_7 ,
F_2 ( V_4 -> V_7 + V_15 ) ) ;
F_3 ( V_4 -> V_7 + V_8 , V_6 ) ;
if ( V_6 & V_16 )
F_5 ( V_2 , V_2 -> V_17 ) ;
if ( ( V_6 & ~ V_9 ) & ~ V_16 )
F_6 ( V_2 , V_2 -> V_17 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 , V_18 ;
V_6 = F_2 ( V_4 -> V_7 + V_8 ) ;
V_18 = F_2 ( V_4 -> V_7 + V_19 ) ;
F_4 ( L_8 ) ;
F_4 ( L_9 , V_6 ) ;
F_4 ( L_10 , V_18 ) ;
F_4 ( L_11 ,
F_2 ( V_4 -> V_7 + V_20 ) ) ;
F_4 ( L_12 ,
F_2 ( V_4 -> V_7 + V_21 ) ) ;
F_4 ( L_13 ,
F_2 ( V_4 -> V_7 + V_22 ) ) ;
F_4 ( L_14 ,
F_2 ( V_4 -> V_7 + V_23 ) ) ;
F_3 ( V_4 -> V_7 + V_8 , V_6 ) ;
F_3 ( V_4 -> V_7 + V_19 , V_18 | 0x1 ) ;
}
static int F_8 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
if ( ! V_25 )
return - V_28 ;
V_27 = F_9 ( V_25 ) ;
return F_10 ( V_27 , 0 , 0 , V_29 ) ;
}
static T_2 F_11 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
V_6 = F_2 ( V_4 -> V_7 + V_8 ) ;
if ( ! V_6 )
return V_32 ;
if ( V_4 -> V_33 )
F_7 ( V_2 ) ;
else
F_1 ( V_2 ) ;
return V_34 ;
}
static int F_12 ( struct V_35 * V_36 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_37 * V_38 ;
struct V_24 * V_39 ;
struct V_40 V_41 ;
int V_42 = 0 ;
if ( ! F_13 ( & V_36 -> V_43 , F_12 , V_44 ) )
return - V_45 ;
V_2 = F_14 ( sizeof( * V_4 ) , L_15 ) ;
if ( ! V_2 )
return - V_45 ;
switch ( V_46 ) {
case V_47 :
case V_48 :
break;
default:
V_46 = V_48 ;
break;
}
V_4 = V_2 -> V_5 ;
V_4 -> V_49 = L_15 ;
V_38 = V_36 -> V_43 . V_50 ;
if ( ! V_38 ) {
F_15 ( & V_36 -> V_43 , L_16 ) ;
V_42 = - V_51 ;
goto V_52;
}
V_39 = V_38 -> V_39 ;
if ( F_8 ( V_39 ) > 0 )
V_4 -> V_33 = true ;
F_16 ( & V_36 -> V_43 , V_2 ) ;
V_2 -> V_43 = & V_36 -> V_43 ;
V_2 -> V_53 = V_54 ;
V_2 -> V_17 = V_4 -> V_49 ;
V_2 -> V_55 = V_55 ( & V_36 -> V_43 ) ;
if ( V_46 == V_47 ) {
if ( V_4 -> V_33 )
V_2 -> V_56 = F_7 ;
else
V_2 -> V_56 = F_1 ;
}
V_4 -> V_57 = V_58 ++ ;
V_42 = F_17 ( V_39 , 0 , & V_41 ) ;
if ( V_42 ) {
F_4 ( L_17 , V_59 ) ;
goto V_52;
}
V_41 . V_60 += 0xe00 ;
if ( ! F_18 ( & V_36 -> V_43 , V_41 . V_60 , F_19 ( & V_41 ) ,
V_4 -> V_49 ) ) {
F_4 ( L_18 , V_59 ) ;
V_42 = - V_61 ;
goto V_52;
}
V_4 -> V_7 = F_20 ( & V_36 -> V_43 , V_41 . V_60 , F_19 ( & V_41 ) ) ;
if ( ! V_4 -> V_7 ) {
F_4 ( L_19 , V_59 ) ;
V_42 = - V_45 ;
goto V_52;
}
if ( V_4 -> V_33 ) {
V_62 =
F_2 ( V_4 -> V_7 + V_12 ) ;
F_3 ( V_4 -> V_7 + V_12 , ~ 0 ) ;
V_63 =
F_2 ( V_4 -> V_7 + V_64 ) ;
F_3 ( V_4 -> V_7 + V_64 , 0 ) ;
} else {
V_62 =
F_2 ( V_4 -> V_7 + V_65 ) ;
F_3 ( V_4 -> V_7 + V_65 , 0x40 ) ;
V_63 =
F_2 ( V_4 -> V_7 + V_64 ) ;
F_3 ( V_4 -> V_7 + V_64 , ~ 0x40 ) ;
}
F_3 ( V_4 -> V_7 + V_8 , ~ 0 ) ;
F_3 ( V_4 -> V_7 + V_19 , 0x1 ) ;
if ( F_21 ( V_2 , V_4 -> V_57 ) > 0 ) {
F_22 ( 3 , L_20 ) ;
goto V_52;
}
if ( V_46 == V_48 ) {
V_4 -> V_30 = F_23 ( V_39 , 0 ) ;
V_42 = F_24 ( & V_36 -> V_43 , V_4 -> V_30 ,
F_11 ,
V_66 ,
L_21 , V_2 ) ;
if ( V_42 < 0 ) {
F_4 ( L_22 ,
V_59 , V_4 -> V_30 ) ;
F_25 ( V_4 -> V_30 ) ;
V_42 = - V_67 ;
goto V_68;
}
F_26 ( V_54 L_23 ,
V_4 -> V_30 ) ;
}
if ( V_4 -> V_33 ) {
F_3 ( V_4 -> V_7 + V_64 , ~ 0
& ~ V_69 ) ;
F_3 ( V_4 -> V_7 + V_12 , 0
| V_70 ) ;
}
F_27 ( & V_36 -> V_43 , F_12 ) ;
F_22 ( 3 , L_24 ) ;
F_26 ( V_54 L_25 ) ;
return 0 ;
V_68:
F_28 ( & V_36 -> V_43 ) ;
V_52:
F_29 ( V_2 ) ;
F_30 ( & V_36 -> V_43 , F_12 ) ;
return V_42 ;
}
static int F_31 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_32 ( & V_36 -> V_43 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_22 ( 0 , L_26 ) ;
F_3 ( V_4 -> V_7 + V_12 , V_62 ) ;
F_3 ( V_4 -> V_7 + V_64 , V_63 ) ;
F_28 ( & V_36 -> V_43 ) ;
F_29 ( V_2 ) ;
return 0 ;
}
static T_3 F_33 ( struct V_71
* V_72 , char * V_73 )
{
struct V_74 * V_4 = V_72 -> V_5 ;
return sprintf ( V_73 , L_27 ,
F_2 ( V_4 -> V_75 + V_76 ) ) ;
}
static T_3 F_34 ( struct V_71
* V_72 , char * V_73 )
{
struct V_74 * V_4 = V_72 -> V_5 ;
return sprintf ( V_73 , L_27 ,
F_2 ( V_4 -> V_75 + V_77 ) ) ;
}
static T_3 F_35 ( struct V_71
* V_72 , char * V_73 )
{
struct V_74 * V_4 = V_72 -> V_5 ;
return sprintf ( V_73 , L_27 ,
F_2 ( V_4 -> V_75 + V_78 ) ) ;
}
static T_3 F_36 ( struct V_71
* V_72 , const char * V_73 ,
T_4 V_79 )
{
struct V_74 * V_4 = V_72 -> V_5 ;
if ( isdigit ( * V_73 ) ) {
F_3 ( V_4 -> V_75 + V_76 ,
F_37 ( V_73 , NULL , 0 ) ) ;
return V_79 ;
}
return 0 ;
}
static T_3 F_38 ( struct V_71
* V_72 , const char * V_73 ,
T_4 V_79 )
{
struct V_74 * V_4 = V_72 -> V_5 ;
if ( isdigit ( * V_73 ) ) {
F_3 ( V_4 -> V_75 + V_77 ,
F_37 ( V_73 , NULL , 0 ) ) ;
return V_79 ;
}
return 0 ;
}
static T_3 F_39 ( struct V_71
* V_72 , const char * V_73 ,
T_4 V_79 )
{
struct V_74 * V_4 = V_72 -> V_5 ;
if ( isdigit ( * V_73 ) ) {
F_3 ( V_4 -> V_75 + V_78 ,
F_37 ( V_73 , NULL , 0 ) ) ;
return V_79 ;
}
return 0 ;
}
static void F_40 ( struct V_71
* V_72 )
{
V_72 -> V_80 = V_81 ;
}
static void F_41 ( struct V_71 * V_72 )
{
struct V_74 * V_4 = V_72 -> V_5 ;
T_1 V_6 ;
V_6 = F_2 ( V_4 -> V_75 + V_82 ) ;
if ( ! ( V_6 & V_83 ) )
return;
F_4 ( L_28 ) ;
F_4 ( L_29 , V_6 ) ;
F_4 ( L_30 ,
F_2 ( V_4 -> V_75 + V_84 ) ) ;
F_4 ( L_31 ,
F_2 ( V_4 -> V_75 + V_85 ) ) ;
F_4 ( L_32 ,
F_2 ( V_4 -> V_75 + V_86 ) ) ;
F_4 ( L_33 ,
F_2 ( V_4 -> V_75 + V_87 ) ) ;
F_4 ( L_34 ,
F_2 ( V_4 -> V_75 + V_88 ) ) ;
F_3 ( V_4 -> V_75 + V_82 , V_6 ) ;
if ( V_6 & V_89 )
F_42 ( V_72 , 0 , 0 , V_72 -> V_17 ) ;
if ( V_6 & V_90 )
F_43 ( V_72 , 0 , 0 , V_72 -> V_17 ) ;
}
static T_2 F_44 ( int V_30 , void * V_31 )
{
struct V_71 * V_72 = V_31 ;
struct V_74 * V_4 = V_72 -> V_5 ;
T_1 V_6 ;
V_6 = F_2 ( V_4 -> V_75 + V_82 ) ;
if ( ! ( V_6 & V_83 ) )
return V_32 ;
F_41 ( V_72 ) ;
return V_34 ;
}
static int F_45 ( struct V_35 * V_36 )
{
struct V_71 * V_72 ;
struct V_74 * V_4 ;
struct V_40 V_41 ;
int V_42 ;
if ( ! F_13 ( & V_36 -> V_43 , F_45 , V_44 ) )
return - V_45 ;
V_72 = F_46 ( sizeof( * V_4 ) ,
L_35 , 1 , L_36 , 1 , 2 , NULL , 0 ,
V_91 ) ;
if ( ! V_72 ) {
F_30 ( & V_36 -> V_43 , F_45 ) ;
return - V_45 ;
}
V_4 = V_72 -> V_5 ;
V_4 -> V_49 = L_37 ;
V_72 -> V_43 = & V_36 -> V_43 ;
F_16 ( V_72 -> V_43 , V_72 ) ;
V_72 -> V_17 = V_4 -> V_49 ;
V_72 -> V_55 = V_4 -> V_49 ;
V_42 = F_17 ( V_36 -> V_43 . V_39 , 0 , & V_41 ) ;
if ( V_42 ) {
F_4 ( L_38 , V_59 ) ;
goto V_52;
}
V_41 . V_60 += 0xe00 ;
if ( ! F_18 ( & V_36 -> V_43 , V_41 . V_60 , F_19 ( & V_41 ) ,
V_4 -> V_49 ) ) {
F_4 ( L_18 , V_59 ) ;
V_42 = - V_61 ;
goto V_52;
}
V_4 -> V_75 = F_20 ( & V_36 -> V_43 , V_41 . V_60 , F_19 ( & V_41 ) ) ;
if ( ! V_4 -> V_75 ) {
F_4 ( L_39 , V_59 ) ;
V_42 = - V_45 ;
goto V_52;
}
F_3 ( V_4 -> V_75 + V_82 , ~ 0 ) ;
V_92 = F_2 ( V_4 -> V_75 + V_93 ) ;
F_3 ( V_4 -> V_75 + V_93 , 0 ) ;
V_72 -> V_53 = V_54 ;
if ( V_46 == V_47 )
V_72 -> V_56 = F_41 ;
F_40 ( V_72 ) ;
V_4 -> V_57 = V_91 ++ ;
if ( F_47 ( V_72 ) > 0 ) {
F_22 ( 3 , L_40 ) ;
goto V_52;
}
if ( V_46 == V_48 ) {
V_4 -> V_30 = F_23 ( V_36 -> V_43 . V_39 , 0 ) ;
V_42 = F_24 ( & V_36 -> V_43 , V_4 -> V_30 ,
F_44 , V_66 ,
L_41 , V_72 ) ;
if ( V_42 < 0 ) {
F_4 ( L_42 ,
V_59 , V_4 -> V_30 ) ;
F_25 ( V_4 -> V_30 ) ;
V_42 = - V_67 ;
goto V_68;
}
F_26 ( V_54 L_43 , V_4 -> V_30 ) ;
V_72 -> V_94 = V_95 ;
F_3 ( V_4 -> V_75 + V_96 , V_97 ) ;
}
F_27 ( & V_36 -> V_43 , F_45 ) ;
F_22 ( 3 , L_24 ) ;
F_26 ( V_54 L_44 ) ;
return 0 ;
V_68:
F_48 ( & V_36 -> V_43 ) ;
V_52:
F_30 ( & V_36 -> V_43 , F_45 ) ;
F_49 ( V_72 ) ;
return V_42 ;
}
static int F_50 ( struct V_35 * V_36 )
{
struct V_71 * V_72 = F_32 ( & V_36 -> V_43 ) ;
struct V_74 * V_4 = V_72 -> V_5 ;
F_22 ( 0 , L_26 ) ;
if ( V_46 == V_48 ) {
F_3 ( V_4 -> V_75 + V_96 , 0 ) ;
F_25 ( V_4 -> V_30 ) ;
}
F_3 ( V_4 -> V_75 + V_93 , V_92 ) ;
F_48 ( & V_36 -> V_43 ) ;
F_49 ( V_72 ) ;
return 0 ;
}
static int T_5 F_51 ( void )
{
int V_42 = 0 ;
T_1 T_6 V_98 = 0 ;
F_26 ( L_45 ) ;
switch ( V_46 ) {
case V_47 :
case V_48 :
break;
default:
V_46 = V_48 ;
break;
}
V_42 = F_52 ( V_99 , F_53 ( V_99 ) ) ;
if ( V_42 )
F_54 ( V_54 L_46 ) ;
return 0 ;
}
static void T_7 F_55 ( void )
{
F_56 ( V_99 , F_53 ( V_99 ) ) ;
}
