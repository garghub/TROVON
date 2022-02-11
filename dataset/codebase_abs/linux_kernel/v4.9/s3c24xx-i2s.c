static void F_1 ( int V_1 )
{
T_1 V_2 ;
T_1 V_3 ;
T_1 V_4 ;
F_2 ( L_1 , V_5 ) ;
V_2 = F_3 ( V_6 . V_7 + V_8 ) ;
V_3 = F_3 ( V_6 . V_7 + V_9 ) ;
V_4 = F_3 ( V_6 . V_7 + V_10 ) ;
F_2 ( L_2 , V_3 , V_4 , V_2 ) ;
if ( V_1 ) {
V_2 |= V_11 | V_12 ;
V_3 |= V_13 | V_14 ;
V_3 &= ~ V_15 ;
V_4 |= V_16 ;
F_4 ( V_4 , V_6 . V_7 + V_10 ) ;
F_4 ( V_2 , V_6 . V_7 + V_8 ) ;
F_4 ( V_3 , V_6 . V_7 + V_9 ) ;
} else {
V_2 &= ~ V_12 ;
V_2 &= ~ V_11 ;
V_3 |= V_15 ;
V_3 &= ~ V_13 ;
V_4 &= ~ V_16 ;
F_4 ( V_3 , V_6 . V_7 + V_9 ) ;
F_4 ( V_2 , V_6 . V_7 + V_8 ) ;
F_4 ( V_4 , V_6 . V_7 + V_10 ) ;
}
F_2 ( L_3 , V_3 , V_4 , V_2 ) ;
}
static void F_5 ( int V_1 )
{
T_1 V_2 ;
T_1 V_3 ;
T_1 V_4 ;
F_2 ( L_1 , V_5 ) ;
V_2 = F_3 ( V_6 . V_7 + V_8 ) ;
V_3 = F_3 ( V_6 . V_7 + V_9 ) ;
V_4 = F_3 ( V_6 . V_7 + V_10 ) ;
F_2 ( L_2 , V_3 , V_4 , V_2 ) ;
if ( V_1 ) {
V_2 |= V_17 | V_18 ;
V_3 |= V_19 | V_14 ;
V_3 &= ~ V_20 ;
V_4 |= V_21 ;
F_4 ( V_4 , V_6 . V_7 + V_10 ) ;
F_4 ( V_2 , V_6 . V_7 + V_8 ) ;
F_4 ( V_3 , V_6 . V_7 + V_9 ) ;
} else {
V_2 &= ~ V_18 ;
V_2 &= ~ V_17 ;
V_3 |= V_20 ;
V_3 &= ~ V_19 ;
V_4 &= ~ V_21 ;
F_4 ( V_2 , V_6 . V_7 + V_8 ) ;
F_4 ( V_3 , V_6 . V_7 + V_9 ) ;
F_4 ( V_4 , V_6 . V_7 + V_10 ) ;
}
F_2 ( L_3 , V_3 , V_4 , V_2 ) ;
}
static int F_6 ( void )
{
T_1 V_3 ;
int V_22 = 50 ;
F_2 ( L_1 , V_5 ) ;
while ( 1 ) {
V_3 = F_3 ( V_6 . V_7 + V_9 ) ;
if ( V_3 & V_23 )
break;
if ( ! V_22 -- )
return - V_24 ;
F_7 ( 100 ) ;
}
return 0 ;
}
static inline int F_8 ( void )
{
F_2 ( L_1 , V_5 ) ;
return ( F_3 ( V_6 . V_7 + V_10 ) & V_25 ) ? 0 : 1 ;
}
static int F_9 ( struct V_26 * V_27 ,
unsigned int V_28 )
{
T_1 V_4 ;
F_2 ( L_1 , V_5 ) ;
V_4 = F_3 ( V_6 . V_7 + V_10 ) ;
F_2 ( L_4 , V_4 ) ;
switch ( V_28 & V_29 ) {
case V_30 :
V_4 |= V_25 ;
break;
case V_31 :
V_4 &= ~ V_25 ;
break;
default:
return - V_32 ;
}
switch ( V_28 & V_33 ) {
case V_34 :
V_4 |= V_35 ;
break;
case V_36 :
V_4 &= ~ V_35 ;
break;
default:
return - V_32 ;
}
F_4 ( V_4 , V_6 . V_7 + V_10 ) ;
F_2 ( L_5 , V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_26 * V_41 )
{
struct V_42 * V_43 ;
T_1 V_4 ;
F_2 ( L_1 , V_5 ) ;
V_43 = F_11 ( V_41 , V_38 ) ;
V_4 = F_3 ( V_6 . V_7 + V_10 ) ;
F_2 ( L_6 , V_4 ) ;
switch ( F_12 ( V_40 ) ) {
case 8 :
V_4 &= ~ V_44 ;
V_43 -> V_45 = 1 ;
break;
case 16 :
V_4 |= V_44 ;
V_43 -> V_45 = 2 ;
break;
default:
return - V_32 ;
}
F_4 ( V_4 , V_6 . V_7 + V_10 ) ;
F_2 ( L_7 , V_4 ) ;
return 0 ;
}
static int F_13 ( struct V_37 * V_38 , int V_46 ,
struct V_26 * V_41 )
{
int V_47 = 0 ;
F_2 ( L_1 , V_5 ) ;
switch ( V_46 ) {
case V_48 :
case V_49 :
case V_50 :
if ( ! F_8 () ) {
V_47 = F_6 () ;
if ( V_47 )
goto V_51;
}
if ( V_38 -> V_52 == V_53 )
F_5 ( 1 ) ;
else
F_1 ( 1 ) ;
break;
case V_54 :
case V_55 :
case V_56 :
if ( V_38 -> V_52 == V_53 )
F_5 ( 0 ) ;
else
F_1 ( 0 ) ;
break;
default:
V_47 = - V_32 ;
break;
}
V_51:
return V_47 ;
}
static int F_14 ( struct V_26 * V_27 ,
int V_57 , unsigned int V_58 , int V_59 )
{
T_1 V_4 = F_3 ( V_6 . V_7 + V_10 ) ;
F_2 ( L_1 , V_5 ) ;
V_4 &= ~ V_60 ;
switch ( V_57 ) {
case V_61 :
break;
case V_62 :
V_4 |= V_60 ;
break;
default:
return - V_32 ;
}
F_4 ( V_4 , V_6 . V_7 + V_10 ) ;
return 0 ;
}
static int F_15 ( struct V_26 * V_27 ,
int V_63 , int div )
{
T_1 V_64 ;
F_2 ( L_1 , V_5 ) ;
switch ( V_63 ) {
case V_65 :
V_64 = F_3 ( V_6 . V_7 + V_10 ) & ~ V_66 ;
F_4 ( V_64 | div , V_6 . V_7 + V_10 ) ;
break;
case V_67 :
V_64 = F_3 ( V_6 . V_7 + V_10 ) & ~ ( V_68 ) ;
F_4 ( V_64 | div , V_6 . V_7 + V_10 ) ;
break;
case V_69 :
F_4 ( div , V_6 . V_7 + V_70 ) ;
V_64 = F_3 ( V_6 . V_7 + V_9 ) ;
F_4 ( V_64 | V_71 , V_6 . V_7 + V_9 ) ;
break;
default:
return - V_32 ;
}
return 0 ;
}
T_1 F_16 ( void )
{
return F_17 ( V_6 . V_72 ) ;
}
static int F_18 ( struct V_26 * V_41 )
{
F_2 ( L_1 , V_5 ) ;
F_19 ( V_41 , & V_73 ,
& V_74 ) ;
V_6 . V_72 = F_20 ( V_41 -> V_75 , L_8 ) ;
if ( F_21 ( V_6 . V_72 ) ) {
F_22 ( L_9 ) ;
return F_23 ( V_6 . V_72 ) ;
}
F_24 ( V_6 . V_72 ) ;
F_25 ( F_26 ( 0 ) , 5 , F_27 ( 2 ) ,
V_76 ) ;
F_4 ( V_14 , V_6 . V_7 + V_9 ) ;
F_1 ( 0 ) ;
F_5 ( 0 ) ;
return 0 ;
}
static int F_28 ( struct V_26 * V_27 )
{
F_2 ( L_1 , V_5 ) ;
V_6 . V_3 = F_3 ( V_6 . V_7 + V_9 ) ;
V_6 . V_4 = F_3 ( V_6 . V_7 + V_10 ) ;
V_6 . V_2 = F_3 ( V_6 . V_7 + V_8 ) ;
V_6 . V_77 = F_3 ( V_6 . V_7 + V_70 ) ;
F_29 ( V_6 . V_72 ) ;
return 0 ;
}
static int F_30 ( struct V_26 * V_27 )
{
F_2 ( L_1 , V_5 ) ;
F_24 ( V_6 . V_72 ) ;
F_4 ( V_6 . V_3 , V_6 . V_7 + V_9 ) ;
F_4 ( V_6 . V_4 , V_6 . V_7 + V_10 ) ;
F_4 ( V_6 . V_2 , V_6 . V_7 + V_8 ) ;
F_4 ( V_6 . V_77 , V_6 . V_7 + V_70 ) ;
return 0 ;
}
static int F_31 ( struct V_78 * V_79 )
{
int V_47 = 0 ;
struct V_80 * V_81 ;
struct V_82 * V_83 = F_32 ( & V_79 -> V_75 ) ;
if ( ! V_83 ) {
F_33 ( & V_79 -> V_75 , L_10 ) ;
return - V_84 ;
}
V_81 = F_34 ( V_79 , V_85 , 0 ) ;
if ( ! V_81 ) {
F_33 ( & V_79 -> V_75 , L_11 ) ;
return - V_86 ;
}
V_6 . V_7 = F_35 ( & V_79 -> V_75 , V_81 ) ;
if ( F_21 ( V_6 . V_7 ) )
return F_23 ( V_6 . V_7 ) ;
V_73 . V_87 = V_81 -> V_88 + V_89 ;
V_73 . V_90 = V_83 -> V_91 ;
V_74 . V_87 = V_81 -> V_88 + V_89 ;
V_74 . V_90 = V_83 -> V_92 ;
V_47 = F_36 ( & V_79 -> V_75 ,
V_83 -> V_93 ,
NULL , NULL ) ;
if ( V_47 ) {
F_22 ( L_12 , V_47 ) ;
return V_47 ;
}
V_47 = F_37 ( & V_79 -> V_75 ,
& V_94 , & V_95 , 1 ) ;
if ( V_47 )
F_22 ( L_13 ) ;
return V_47 ;
}
