static unsigned int F_1 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long long V_3 = ( V_4 ) V_2 * ( V_4 ) F_2 ( V_5 ) ;
F_3 ( V_3 , V_1 ) ;
return V_3 ;
}
static int F_4 ( struct V_6 * V_7 ,
unsigned long V_8 , unsigned long V_2 )
{
unsigned long V_9 ;
if ( V_2 > ( V_7 -> V_1 / 2 ) )
return - V_10 ;
V_9 = F_1 ( V_7 -> V_1 , V_2 ) ;
V_7 -> V_11 [ 0 ] = F_5 ( V_8 | ( V_9 &
F_6 ( V_5 / 2 ) ) ) ;
V_7 -> V_11 [ 1 ] = F_5 ( V_8 | ( ( V_9 >>
( V_5 / 2 ) ) &
F_6 ( V_5 / 2 ) ) ) ;
return F_7 ( V_7 -> V_12 , & V_7 -> V_13 ) ;
}
static int F_8 ( struct V_6 * V_7 ,
unsigned long V_8 , unsigned long V_14 )
{
if ( V_14 > F_2 ( V_15 ) )
return - V_10 ;
V_7 -> V_16 = F_5 ( V_8 | V_14 ) ;
return F_7 ( V_7 -> V_12 , & V_7 -> V_17 ) ;
}
static T_1 F_9 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
const char * V_22 ,
T_2 V_23 )
{
struct V_24 * V_25 = F_10 ( V_19 ) ;
struct V_6 * V_7 = F_11 ( V_25 ) ;
struct V_26 * V_27 = F_12 ( V_21 ) ;
int V_28 ;
unsigned long V_29 ;
V_28 = F_13 ( V_22 , 10 , & V_29 ) ;
if ( V_28 )
goto V_30;
F_14 ( & V_25 -> V_31 ) ;
switch ( ( V_32 ) V_27 -> V_33 ) {
case V_34 :
case V_35 :
V_28 = F_4 ( V_7 , V_27 -> V_33 , V_29 ) ;
break;
case V_36 :
case V_37 :
V_28 = F_8 ( V_7 , V_27 -> V_33 , V_29 ) ;
break;
case V_38 :
if ( V_7 -> V_39 & V_40 ) {
V_28 = - V_10 ;
break;
}
if ( V_29 )
V_7 -> V_39 |= V_38 ;
else
V_7 -> V_39 &= ~ V_38 ;
V_7 -> V_16 = F_5 ( V_41 | V_7 -> V_39 ) ;
V_28 = F_7 ( V_7 -> V_12 , & V_7 -> V_17 ) ;
break;
case V_42 :
if ( V_29 )
V_7 -> V_39 |= V_42 ;
else
V_7 -> V_39 &= ~ V_42 ;
V_7 -> V_16 = F_5 ( V_41 | V_7 -> V_39 ) ;
V_28 = F_7 ( V_7 -> V_12 , & V_7 -> V_17 ) ;
break;
case V_43 :
case V_44 :
if ( V_29 == 0 ) {
V_7 -> V_39 &= ~ ( V_27 -> V_33 | V_42 ) ;
} else if ( V_29 == 1 ) {
V_7 -> V_39 |= V_27 -> V_33 ;
V_7 -> V_39 &= ~ V_42 ;
} else {
V_28 = - V_10 ;
break;
}
V_7 -> V_16 = F_5 ( V_41 | V_7 -> V_39 ) ;
V_28 = F_7 ( V_7 -> V_12 , & V_7 -> V_17 ) ;
break;
case V_45 :
if ( V_29 )
V_7 -> V_39 &= ~ V_45 ;
else
V_7 -> V_39 |= V_45 ;
V_7 -> V_16 = F_5 ( V_41 | V_7 -> V_39 ) ;
V_28 = F_7 ( V_7 -> V_12 , & V_7 -> V_17 ) ;
break;
default:
V_28 = - V_46 ;
}
F_15 ( & V_25 -> V_31 ) ;
V_30:
return V_28 ? V_28 : V_23 ;
}
static T_1 F_16 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
const char * V_22 ,
T_2 V_23 )
{
struct V_24 * V_25 = F_10 ( V_19 ) ;
struct V_6 * V_7 = F_11 ( V_25 ) ;
struct V_26 * V_27 = F_12 ( V_21 ) ;
int V_28 = 0 ;
bool V_47 = ( V_7 -> V_48 == V_49 ) || ( V_7 -> V_48 == V_50 ) ;
F_14 ( & V_25 -> V_31 ) ;
switch ( ( V_32 ) V_27 -> V_33 ) {
case 0 :
if ( F_17 ( V_22 , L_1 ) ) {
V_7 -> V_39 &= ~ V_40 ;
if ( V_47 )
V_7 -> V_39 &= ~ V_38 ;
} else if ( F_17 ( V_22 , L_2 ) ) {
if ( V_47 ) {
V_7 -> V_39 &= ~ V_38 ;
V_7 -> V_39 |= V_40 ;
} else if ( V_7 -> V_39 & V_38 ) {
V_28 = - V_10 ;
} else {
V_7 -> V_39 |= V_40 ;
}
} else if ( V_47 && F_17 ( V_22 , L_3 ) ) {
V_7 -> V_39 &= ~ V_40 ;
V_7 -> V_39 |= V_38 ;
} else {
V_28 = - V_10 ;
}
break;
case 1 :
if ( F_17 ( V_22 , L_3 ) &&
! ( V_7 -> V_39 & V_40 ) ) {
V_7 -> V_39 &= ~ V_40 ;
V_7 -> V_39 |= V_38 ;
} else {
V_28 = - V_10 ;
}
break;
default:
V_28 = - V_10 ;
break;
}
if ( ! V_28 ) {
V_7 -> V_16 = F_5 ( V_41 | V_7 -> V_39 ) ;
V_28 = F_7 ( V_7 -> V_12 , & V_7 -> V_17 ) ;
}
F_15 ( & V_25 -> V_31 ) ;
return V_28 ? V_28 : V_23 ;
}
static
T_1 F_18 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
char * V_22 )
{
struct V_24 * V_25 = F_10 ( V_19 ) ;
struct V_6 * V_7 = F_11 ( V_25 ) ;
char * V_51 ;
if ( ( V_7 -> V_48 == V_49 ) || ( V_7 -> V_48 == V_50 ) )
V_51 = L_4 ;
else if ( V_7 -> V_39 & V_38 )
V_51 = L_1 ;
else
V_51 = L_5 ;
return sprintf ( V_22 , L_6 , V_51 ) ;
}
static
T_1 F_19 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
char * V_22 )
{
struct V_24 * V_25 = F_10 ( V_19 ) ;
struct V_6 * V_7 = F_11 ( V_25 ) ;
char * V_51 ;
if ( V_7 -> V_39 & V_40 )
V_51 = L_7 ;
else
V_51 = L_3 ;
return sprintf ( V_22 , L_6 , V_51 ) ;
}
static int F_20 ( struct V_52 * V_12 )
{
struct V_53 * V_54 = V_12 -> V_19 . V_55 ;
struct V_6 * V_7 ;
struct V_24 * V_25 ;
struct V_56 * V_57 ;
int V_28 ;
if ( ! V_54 ) {
F_21 ( & V_12 -> V_19 , L_8 ) ;
return - V_46 ;
}
V_57 = F_22 ( & V_12 -> V_19 , L_9 ) ;
if ( ! F_23 ( V_57 ) ) {
V_28 = F_24 ( V_57 ) ;
if ( V_28 )
return V_28 ;
}
V_25 = F_25 ( & V_12 -> V_19 , sizeof( * V_7 ) ) ;
if ( ! V_25 ) {
V_28 = - V_58 ;
goto V_59;
}
F_26 ( V_12 , V_25 ) ;
V_7 = F_11 ( V_25 ) ;
V_7 -> V_1 = V_54 -> V_1 ;
V_7 -> V_12 = V_12 ;
V_7 -> V_48 = F_27 ( V_12 ) -> V_60 ;
V_7 -> V_57 = V_57 ;
V_25 -> V_19 . V_61 = & V_12 -> V_19 ;
V_25 -> V_62 = F_27 ( V_12 ) -> V_62 ;
switch ( V_7 -> V_48 ) {
case V_49 :
case V_50 :
V_25 -> V_63 = & V_64 ;
break;
default:
V_25 -> V_63 = & V_65 ;
break;
}
V_25 -> V_66 = V_67 ;
V_7 -> V_68 . V_69 = & V_7 -> V_16 ;
V_7 -> V_68 . V_23 = 2 ;
F_28 ( & V_7 -> V_17 ) ;
F_29 ( & V_7 -> V_68 , & V_7 -> V_17 ) ;
V_7 -> V_70 [ 0 ] . V_69 = & V_7 -> V_11 [ 0 ] ;
V_7 -> V_70 [ 0 ] . V_23 = 2 ;
V_7 -> V_70 [ 0 ] . V_71 = 1 ;
V_7 -> V_70 [ 1 ] . V_69 = & V_7 -> V_11 [ 1 ] ;
V_7 -> V_70 [ 1 ] . V_23 = 2 ;
F_28 ( & V_7 -> V_13 ) ;
F_29 ( & V_7 -> V_70 [ 0 ] , & V_7 -> V_13 ) ;
F_29 ( & V_7 -> V_70 [ 1 ] , & V_7 -> V_13 ) ;
V_7 -> V_39 = V_72 | V_45 ;
if ( ! V_54 -> V_73 )
V_7 -> V_39 |= V_74 ;
if ( ! V_54 -> V_75 && ( V_7 -> V_48 == V_76 ) )
V_7 -> V_39 |= V_77 ;
V_7 -> V_16 = F_5 ( V_41 | V_7 -> V_39 ) ;
V_28 = F_7 ( V_7 -> V_12 , & V_7 -> V_17 ) ;
if ( V_28 ) {
F_30 ( & V_12 -> V_19 , L_10 ) ;
goto V_59;
}
V_28 = F_4 ( V_7 , V_34 , V_54 -> V_78 ) ;
if ( V_28 )
goto V_59;
V_28 = F_4 ( V_7 , V_35 , V_54 -> V_79 ) ;
if ( V_28 )
goto V_59;
V_28 = F_8 ( V_7 , V_36 , V_54 -> V_80 ) ;
if ( V_28 )
goto V_59;
V_28 = F_8 ( V_7 , V_37 , V_54 -> V_81 ) ;
if ( V_28 )
goto V_59;
V_28 = F_31 ( V_25 ) ;
if ( V_28 )
goto V_59;
return 0 ;
V_59:
if ( ! F_23 ( V_57 ) )
F_32 ( V_57 ) ;
return V_28 ;
}
static int F_33 ( struct V_52 * V_12 )
{
struct V_24 * V_25 = F_34 ( V_12 ) ;
struct V_6 * V_7 = F_11 ( V_25 ) ;
F_35 ( V_25 ) ;
if ( ! F_23 ( V_7 -> V_57 ) )
F_32 ( V_7 -> V_57 ) ;
return 0 ;
}
