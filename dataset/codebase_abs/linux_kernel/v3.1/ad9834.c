static unsigned int F_1 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long long V_3 = ( V_4 ) V_2 * ( V_4 ) ( 1 << V_5 ) ;
F_2 ( V_3 , V_1 ) ;
return V_3 ;
}
static int F_3 ( struct V_6 * V_7 ,
unsigned long V_8 , unsigned long V_2 )
{
unsigned long V_9 ;
if ( V_2 > ( V_7 -> V_1 / 2 ) )
return - V_10 ;
V_9 = F_1 ( V_7 -> V_1 , V_2 ) ;
V_7 -> V_11 [ 0 ] = F_4 ( V_8 | ( V_9 &
F_5 ( V_5 / 2 ) ) ) ;
V_7 -> V_11 [ 1 ] = F_4 ( V_8 | ( ( V_9 >>
( V_5 / 2 ) ) &
F_5 ( V_5 / 2 ) ) ) ;
return F_6 ( V_7 -> V_12 , & V_7 -> V_13 ) ;
}
static int F_7 ( struct V_6 * V_7 ,
unsigned long V_8 , unsigned long V_14 )
{
if ( V_14 > ( 1 << V_15 ) )
return - V_10 ;
V_7 -> V_16 = F_4 ( V_8 | V_14 ) ;
return F_6 ( V_7 -> V_12 , & V_7 -> V_17 ) ;
}
static T_1 F_8 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
const char * V_22 ,
T_2 V_23 )
{
struct V_24 * V_25 = F_9 ( V_19 ) ;
struct V_6 * V_7 = F_10 ( V_25 ) ;
struct V_26 * V_27 = F_11 ( V_21 ) ;
int V_28 ;
long V_29 ;
V_28 = F_12 ( V_22 , 10 , & V_29 ) ;
if ( V_28 )
goto V_30;
F_13 ( & V_25 -> V_31 ) ;
switch ( V_27 -> V_32 ) {
case V_33 :
case V_34 :
V_28 = F_3 ( V_7 , V_27 -> V_32 , V_29 ) ;
break;
case V_35 :
case V_36 :
V_28 = F_7 ( V_7 , V_27 -> V_32 , V_29 ) ;
break;
case V_37 :
if ( V_7 -> V_38 & V_39 ) {
V_28 = - V_10 ;
break;
}
if ( V_29 )
V_7 -> V_38 |= V_37 ;
else
V_7 -> V_38 &= ~ V_37 ;
V_7 -> V_16 = F_4 ( V_40 | V_7 -> V_38 ) ;
V_28 = F_6 ( V_7 -> V_12 , & V_7 -> V_17 ) ;
break;
case V_41 :
if ( V_29 )
V_7 -> V_38 |= V_41 ;
else
V_7 -> V_38 &= ~ V_41 ;
V_7 -> V_16 = F_4 ( V_40 | V_7 -> V_38 ) ;
V_28 = F_6 ( V_7 -> V_12 , & V_7 -> V_17 ) ;
break;
case V_42 :
case V_43 :
if ( V_29 == 0 )
V_7 -> V_38 &= ~ ( V_27 -> V_32 | V_41 ) ;
else if ( V_29 == 1 ) {
V_7 -> V_38 |= V_27 -> V_32 ;
V_7 -> V_38 &= ~ V_41 ;
} else {
V_28 = - V_10 ;
break;
}
V_7 -> V_16 = F_4 ( V_40 | V_7 -> V_38 ) ;
V_28 = F_6 ( V_7 -> V_12 , & V_7 -> V_17 ) ;
break;
case V_44 :
if ( V_29 )
V_7 -> V_38 &= ~ V_44 ;
else
V_7 -> V_38 |= V_44 ;
V_7 -> V_16 = F_4 ( V_40 | V_7 -> V_38 ) ;
V_28 = F_6 ( V_7 -> V_12 , & V_7 -> V_17 ) ;
break;
default:
V_28 = - V_45 ;
}
F_14 ( & V_25 -> V_31 ) ;
V_30:
return V_28 ? V_28 : V_23 ;
}
static T_1 F_15 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
const char * V_22 ,
T_2 V_23 )
{
struct V_24 * V_25 = F_9 ( V_19 ) ;
struct V_6 * V_7 = F_10 ( V_25 ) ;
struct V_26 * V_27 = F_11 ( V_21 ) ;
int V_28 = 0 ;
bool V_46 = ( V_7 -> V_47 == V_48 ) || ( V_7 -> V_47 == V_49 ) ;
F_13 ( & V_25 -> V_31 ) ;
switch ( V_27 -> V_32 ) {
case 0 :
if ( F_16 ( V_22 , L_1 ) ) {
V_7 -> V_38 &= ~ V_39 ;
if ( V_46 )
V_7 -> V_38 &= ~ V_37 ;
} else if ( F_16 ( V_22 , L_2 ) ) {
if ( V_46 ) {
V_7 -> V_38 &= ~ V_37 ;
V_7 -> V_38 |= V_39 ;
} else if ( V_7 -> V_38 & V_37 ) {
V_28 = - V_10 ;
} else {
V_7 -> V_38 |= V_39 ;
}
} else if ( V_46 && F_16 ( V_22 , L_3 ) ) {
V_7 -> V_38 &= ~ V_39 ;
V_7 -> V_38 |= V_37 ;
} else {
V_28 = - V_10 ;
}
break;
case 1 :
if ( F_16 ( V_22 , L_3 ) &&
! ( V_7 -> V_38 & V_39 ) ) {
V_7 -> V_38 &= ~ V_39 ;
V_7 -> V_38 |= V_37 ;
} else {
V_28 = - V_10 ;
}
break;
default:
V_28 = - V_10 ;
break;
}
if ( ! V_28 ) {
V_7 -> V_16 = F_4 ( V_40 | V_7 -> V_38 ) ;
V_28 = F_6 ( V_7 -> V_12 , & V_7 -> V_17 ) ;
}
F_14 ( & V_25 -> V_31 ) ;
return V_28 ? V_28 : V_23 ;
}
static T_1 F_17 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
char * V_22 )
{
struct V_24 * V_25 = F_9 ( V_19 ) ;
struct V_6 * V_7 = F_10 ( V_25 ) ;
char * V_50 ;
if ( ( V_7 -> V_47 == V_48 ) || ( V_7 -> V_47 == V_49 ) )
V_50 = L_4 ;
else if ( V_7 -> V_38 & V_37 )
V_50 = L_1 ;
else
V_50 = L_5 ;
return sprintf ( V_22 , L_6 , V_50 ) ;
}
static T_1 F_18 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
char * V_22 )
{
struct V_24 * V_25 = F_9 ( V_19 ) ;
struct V_6 * V_7 = F_10 ( V_25 ) ;
char * V_50 ;
if ( V_7 -> V_38 & V_39 )
V_50 = L_7 ;
else
V_50 = L_3 ;
return sprintf ( V_22 , L_6 , V_50 ) ;
}
static T_3 F_19 ( struct V_51 * V_52 ,
struct V_53 * V_21 , int V_54 )
{
struct V_18 * V_19 = F_20 ( V_52 , struct V_18 , V_52 ) ;
struct V_24 * V_25 = F_9 ( V_19 ) ;
struct V_6 * V_7 = F_10 ( V_25 ) ;
T_3 V_55 = V_21 -> V_55 ;
if ( ( ( V_7 -> V_47 == V_48 ) || ( V_7 -> V_47 == V_49 ) ) &&
( ( V_21 == & V_56 . V_57 . V_21 ) ||
( V_21 == & V_58 . V_57 . V_21 ) ||
( V_21 ==
& V_59 . V_57 . V_21 ) ||
( V_21 == & V_60 . V_57 . V_21 ) ) )
V_55 = 0 ;
return V_55 ;
}
static int T_4 F_21 ( struct V_61 * V_12 )
{
struct V_62 * V_63 = V_12 -> V_19 . V_64 ;
struct V_6 * V_7 ;
struct V_24 * V_65 ;
struct V_66 * V_67 ;
int V_28 ;
if ( ! V_63 ) {
F_22 ( & V_12 -> V_19 , L_8 ) ;
return - V_45 ;
}
V_67 = F_23 ( & V_12 -> V_19 , L_9 ) ;
if ( ! F_24 ( V_67 ) ) {
V_28 = F_25 ( V_67 ) ;
if ( V_28 )
goto V_68;
}
V_65 = F_26 ( sizeof( * V_7 ) ) ;
if ( V_65 == NULL ) {
V_28 = - V_69 ;
goto V_70;
}
F_27 ( V_12 , V_65 ) ;
V_7 = F_10 ( V_65 ) ;
V_7 -> V_1 = V_63 -> V_1 ;
V_7 -> V_12 = V_12 ;
V_7 -> V_47 = F_28 ( V_12 ) -> V_71 ;
V_7 -> V_67 = V_67 ;
V_65 -> V_19 . V_72 = & V_12 -> V_19 ;
V_65 -> V_73 = F_28 ( V_12 ) -> V_73 ;
V_65 -> V_74 = & V_75 ;
V_65 -> V_76 = V_77 ;
V_7 -> V_78 . V_79 = & V_7 -> V_16 ;
V_7 -> V_78 . V_23 = 2 ;
F_29 ( & V_7 -> V_17 ) ;
F_30 ( & V_7 -> V_78 , & V_7 -> V_17 ) ;
V_7 -> V_80 [ 0 ] . V_79 = & V_7 -> V_11 [ 0 ] ;
V_7 -> V_80 [ 0 ] . V_23 = 2 ;
V_7 -> V_80 [ 0 ] . V_81 = 1 ;
V_7 -> V_80 [ 1 ] . V_79 = & V_7 -> V_11 [ 1 ] ;
V_7 -> V_80 [ 1 ] . V_23 = 2 ;
F_29 ( & V_7 -> V_13 ) ;
F_30 ( & V_7 -> V_80 [ 0 ] , & V_7 -> V_13 ) ;
F_30 ( & V_7 -> V_80 [ 1 ] , & V_7 -> V_13 ) ;
V_7 -> V_38 = V_82 | V_44 ;
if ( ! V_63 -> V_83 )
V_7 -> V_38 |= V_84 ;
if ( ! V_63 -> V_85 && ( V_7 -> V_47 == V_86 ) )
V_7 -> V_38 |= V_87 ;
V_7 -> V_16 = F_4 ( V_40 | V_7 -> V_38 ) ;
V_28 = F_6 ( V_7 -> V_12 , & V_7 -> V_17 ) ;
if ( V_28 ) {
F_31 ( & V_12 -> V_19 , L_10 ) ;
goto V_88;
}
V_28 = F_3 ( V_7 , V_33 , V_63 -> V_89 ) ;
if ( V_28 )
goto V_88;
V_28 = F_3 ( V_7 , V_34 , V_63 -> V_90 ) ;
if ( V_28 )
goto V_88;
V_28 = F_7 ( V_7 , V_35 , V_63 -> V_91 ) ;
if ( V_28 )
goto V_88;
V_28 = F_7 ( V_7 , V_36 , V_63 -> V_92 ) ;
if ( V_28 )
goto V_88;
V_28 = F_32 ( V_65 ) ;
if ( V_28 )
goto V_88;
return 0 ;
V_88:
F_33 ( V_65 ) ;
V_70:
if ( ! F_24 ( V_67 ) )
F_34 ( V_67 ) ;
V_68:
if ( ! F_24 ( V_67 ) )
F_35 ( V_67 ) ;
return V_28 ;
}
static int T_5 F_36 ( struct V_61 * V_12 )
{
struct V_24 * V_65 = F_37 ( V_12 ) ;
struct V_6 * V_7 = F_10 ( V_65 ) ;
struct V_66 * V_67 = V_7 -> V_67 ;
F_38 ( V_65 ) ;
if ( ! F_24 ( V_67 ) ) {
F_34 ( V_67 ) ;
F_35 ( V_67 ) ;
}
return 0 ;
}
static int T_6 F_39 ( void )
{
return F_40 ( & V_93 ) ;
}
static void T_7 F_41 ( void )
{
F_42 ( & V_93 ) ;
}
