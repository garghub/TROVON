static void F_1 ( int V_1 )
{
T_1 V_2 ;
T_1 V_3 ;
T_1 V_4 ;
V_2 = F_2 ( V_5 . V_6 + V_7 ) ;
V_3 = F_2 ( V_5 . V_6 + V_8 ) ;
V_4 = F_2 ( V_5 . V_6 + V_9 ) ;
F_3 ( L_1 , V_3 , V_4 , V_2 ) ;
if ( V_1 ) {
V_2 |= V_10 | V_11 ;
V_3 |= V_12 | V_13 ;
V_3 &= ~ V_14 ;
V_4 |= V_15 ;
F_4 ( V_4 , V_5 . V_6 + V_9 ) ;
F_4 ( V_2 , V_5 . V_6 + V_7 ) ;
F_4 ( V_3 , V_5 . V_6 + V_8 ) ;
} else {
V_2 &= ~ V_11 ;
V_2 &= ~ V_10 ;
V_3 |= V_14 ;
V_3 &= ~ V_12 ;
V_4 &= ~ V_15 ;
F_4 ( V_3 , V_5 . V_6 + V_8 ) ;
F_4 ( V_2 , V_5 . V_6 + V_7 ) ;
F_4 ( V_4 , V_5 . V_6 + V_9 ) ;
}
F_3 ( L_2 , V_3 , V_4 , V_2 ) ;
}
static void F_5 ( int V_1 )
{
T_1 V_2 ;
T_1 V_3 ;
T_1 V_4 ;
V_2 = F_2 ( V_5 . V_6 + V_7 ) ;
V_3 = F_2 ( V_5 . V_6 + V_8 ) ;
V_4 = F_2 ( V_5 . V_6 + V_9 ) ;
F_3 ( L_1 , V_3 , V_4 , V_2 ) ;
if ( V_1 ) {
V_2 |= V_16 | V_17 ;
V_3 |= V_18 | V_13 ;
V_3 &= ~ V_19 ;
V_4 |= V_20 ;
F_4 ( V_4 , V_5 . V_6 + V_9 ) ;
F_4 ( V_2 , V_5 . V_6 + V_7 ) ;
F_4 ( V_3 , V_5 . V_6 + V_8 ) ;
} else {
V_2 &= ~ V_17 ;
V_2 &= ~ V_16 ;
V_3 |= V_19 ;
V_3 &= ~ V_18 ;
V_4 &= ~ V_20 ;
F_4 ( V_2 , V_5 . V_6 + V_7 ) ;
F_4 ( V_3 , V_5 . V_6 + V_8 ) ;
F_4 ( V_4 , V_5 . V_6 + V_9 ) ;
}
F_3 ( L_2 , V_3 , V_4 , V_2 ) ;
}
static int F_6 ( void )
{
T_1 V_3 ;
int V_21 = 50 ;
while ( 1 ) {
V_3 = F_2 ( V_5 . V_6 + V_8 ) ;
if ( V_3 & V_22 )
break;
if ( ! V_21 -- )
return - V_23 ;
F_7 ( 100 ) ;
}
return 0 ;
}
static inline int F_8 ( void )
{
return ( F_2 ( V_5 . V_6 + V_9 ) & V_24 ) ? 0 : 1 ;
}
static int F_9 ( struct V_25 * V_26 ,
unsigned int V_27 )
{
T_1 V_4 ;
V_4 = F_2 ( V_5 . V_6 + V_9 ) ;
F_3 ( L_3 , V_4 ) ;
switch ( V_27 & V_28 ) {
case V_29 :
V_4 |= V_24 ;
break;
case V_30 :
V_4 &= ~ V_24 ;
break;
default:
return - V_31 ;
}
switch ( V_27 & V_32 ) {
case V_33 :
V_4 |= V_34 ;
break;
case V_35 :
V_4 &= ~ V_34 ;
break;
default:
return - V_31 ;
}
F_4 ( V_4 , V_5 . V_6 + V_9 ) ;
F_3 ( L_4 , V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
struct V_25 * V_40 )
{
struct V_41 * V_42 ;
T_1 V_4 ;
V_42 = F_11 ( V_40 , V_37 ) ;
V_4 = F_2 ( V_5 . V_6 + V_9 ) ;
F_3 ( L_5 , V_4 ) ;
switch ( F_12 ( V_39 ) ) {
case 8 :
V_4 &= ~ V_43 ;
V_42 -> V_44 = 1 ;
break;
case 16 :
V_4 |= V_43 ;
V_42 -> V_44 = 2 ;
break;
default:
return - V_31 ;
}
F_4 ( V_4 , V_5 . V_6 + V_9 ) ;
F_3 ( L_6 , V_4 ) ;
return 0 ;
}
static int F_13 ( struct V_36 * V_37 , int V_45 ,
struct V_25 * V_40 )
{
int V_46 = 0 ;
switch ( V_45 ) {
case V_47 :
case V_48 :
case V_49 :
if ( ! F_8 () ) {
V_46 = F_6 () ;
if ( V_46 )
goto V_50;
}
if ( V_37 -> V_51 == V_52 )
F_5 ( 1 ) ;
else
F_1 ( 1 ) ;
break;
case V_53 :
case V_54 :
case V_55 :
if ( V_37 -> V_51 == V_52 )
F_5 ( 0 ) ;
else
F_1 ( 0 ) ;
break;
default:
V_46 = - V_31 ;
break;
}
V_50:
return V_46 ;
}
static int F_14 ( struct V_25 * V_26 ,
int V_56 , unsigned int V_57 , int V_58 )
{
T_1 V_4 = F_2 ( V_5 . V_6 + V_9 ) ;
V_4 &= ~ V_59 ;
switch ( V_56 ) {
case V_60 :
break;
case V_61 :
V_4 |= V_59 ;
break;
default:
return - V_31 ;
}
F_4 ( V_4 , V_5 . V_6 + V_9 ) ;
return 0 ;
}
static int F_15 ( struct V_25 * V_26 ,
int V_62 , int div )
{
T_1 V_63 ;
switch ( V_62 ) {
case V_64 :
V_63 = F_2 ( V_5 . V_6 + V_9 ) & ~ V_65 ;
F_4 ( V_63 | div , V_5 . V_6 + V_9 ) ;
break;
case V_66 :
V_63 = F_2 ( V_5 . V_6 + V_9 ) & ~ ( V_67 ) ;
F_4 ( V_63 | div , V_5 . V_6 + V_9 ) ;
break;
case V_68 :
F_4 ( div , V_5 . V_6 + V_69 ) ;
V_63 = F_2 ( V_5 . V_6 + V_8 ) ;
F_4 ( V_63 | V_70 , V_5 . V_6 + V_8 ) ;
break;
default:
return - V_31 ;
}
return 0 ;
}
T_1 F_16 ( void )
{
return F_17 ( V_5 . V_71 ) ;
}
static int F_18 ( struct V_25 * V_40 )
{
F_19 ( V_40 , & V_72 ,
& V_73 ) ;
V_5 . V_71 = F_20 ( V_40 -> V_74 , L_7 ) ;
if ( F_21 ( V_5 . V_71 ) ) {
F_22 ( L_8 ) ;
return F_23 ( V_5 . V_71 ) ;
}
F_24 ( V_5 . V_71 ) ;
F_25 ( F_26 ( 0 ) , 5 , F_27 ( 2 ) ,
V_75 ) ;
F_4 ( V_13 , V_5 . V_6 + V_8 ) ;
F_1 ( 0 ) ;
F_5 ( 0 ) ;
return 0 ;
}
static int F_28 ( struct V_25 * V_26 )
{
V_5 . V_3 = F_2 ( V_5 . V_6 + V_8 ) ;
V_5 . V_4 = F_2 ( V_5 . V_6 + V_9 ) ;
V_5 . V_2 = F_2 ( V_5 . V_6 + V_7 ) ;
V_5 . V_76 = F_2 ( V_5 . V_6 + V_69 ) ;
F_29 ( V_5 . V_71 ) ;
return 0 ;
}
static int F_30 ( struct V_25 * V_26 )
{
F_24 ( V_5 . V_71 ) ;
F_4 ( V_5 . V_3 , V_5 . V_6 + V_8 ) ;
F_4 ( V_5 . V_4 , V_5 . V_6 + V_9 ) ;
F_4 ( V_5 . V_2 , V_5 . V_6 + V_7 ) ;
F_4 ( V_5 . V_76 , V_5 . V_6 + V_69 ) ;
return 0 ;
}
static int F_31 ( struct V_77 * V_78 )
{
struct V_79 * V_80 ;
int V_46 ;
V_80 = F_32 ( V_78 , V_81 , 0 ) ;
V_5 . V_6 = F_33 ( & V_78 -> V_74 , V_80 ) ;
if ( F_21 ( V_5 . V_6 ) )
return F_23 ( V_5 . V_6 ) ;
V_72 . V_82 = V_80 -> V_83 + V_84 ;
V_73 . V_82 = V_80 -> V_83 + V_84 ;
V_46 = F_34 ( & V_78 -> V_74 , NULL ,
NULL , NULL ) ;
if ( V_46 ) {
F_35 ( & V_78 -> V_74 , L_9 , V_46 ) ;
return V_46 ;
}
V_46 = F_36 ( & V_78 -> V_74 ,
& V_85 , & V_86 , 1 ) ;
if ( V_46 )
F_35 ( & V_78 -> V_74 , L_10 ) ;
return V_46 ;
}
