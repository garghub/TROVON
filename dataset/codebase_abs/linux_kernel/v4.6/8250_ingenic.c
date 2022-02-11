static T_1 T_2 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + ( V_3 << 2 ) ) ;
}
static void T_2 F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + ( V_3 << 2 ) ) ;
}
static void T_2 F_5 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_7 ;
do {
V_7 = F_1 ( V_2 , V_8 ) ;
} while ( ( V_7 & V_9 ) == 0 );
F_3 ( V_2 , V_10 , V_6 ) ;
}
static void T_2 F_6 ( struct V_11 * V_11 ,
const char * V_12 , unsigned int V_13 )
{
F_7 ( & V_14 -> V_2 , V_12 , V_13 ,
F_5 ) ;
}
static void T_2 F_8 ( struct V_15 * V_16 )
{
void * V_17 = V_18 ;
const T_3 * V_19 ;
int V_3 ;
V_3 = F_9 ( V_17 , L_1 ) ;
if ( V_3 < 0 )
return;
V_19 = F_10 ( V_17 , V_3 , L_2 , NULL ) ;
if ( ! V_19 )
return;
V_16 -> V_2 . V_20 = F_11 ( V_19 ) ;
}
static int T_2 F_12 ( struct V_15 * V_16 ,
const char * V_21 )
{
struct V_1 * V_2 = & V_16 -> V_2 ;
unsigned int V_22 , V_23 ;
if ( ! V_16 -> V_2 . V_4 )
return - V_24 ;
F_8 ( V_16 ) ;
V_22 = V_16 -> V_22 ? : 115200 ;
V_23 = F_13 ( V_2 -> V_20 , 16 * V_22 ) ;
F_3 ( V_2 , V_25 , 0 ) ;
F_3 ( V_2 , V_26 , V_27 | V_28 ) ;
F_3 ( V_2 , V_29 , 0 ) ;
F_3 ( V_2 , V_30 , 0 ) ;
F_3 ( V_2 , V_26 , V_28 ) ;
F_3 ( V_2 , V_31 , V_32 | V_33 |
V_34 | V_35 ) ;
F_3 ( V_2 , V_36 , V_37 | V_38 ) ;
F_3 ( V_2 , V_26 , V_27 | V_28 ) ;
F_3 ( V_2 , V_29 , V_23 & 0xff ) ;
F_3 ( V_2 , V_30 , ( V_23 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_26 , V_28 ) ;
V_14 = V_16 ;
V_16 -> V_39 -> V_40 = F_6 ;
return 0 ;
}
static void F_14 ( struct V_1 * V_41 , int V_3 , int V_5 )
{
int V_42 ;
switch ( V_3 ) {
case V_31 :
V_5 |= V_32 ;
break;
case V_25 :
V_5 |= ( V_5 & 0x4 ) << 2 ;
break;
case V_36 :
V_42 = V_41 -> V_43 ( V_41 , V_25 ) ;
if ( V_42 & V_44 )
V_5 |= V_45 | V_46 ;
else
V_5 &= ~ ( V_45 | V_46 ) ;
break;
default:
break;
}
F_15 ( V_5 , V_41 -> V_4 + ( V_3 << V_41 -> V_47 ) ) ;
}
static unsigned int F_16 ( struct V_1 * V_41 , int V_3 )
{
unsigned int V_5 ;
V_5 = F_17 ( V_41 -> V_4 + ( V_3 << V_41 -> V_47 ) ) ;
switch ( V_3 ) {
case V_31 :
V_5 &= ~ V_32 ;
break;
case V_36 :
V_5 &= ~ ( V_45 | V_46 ) ;
break;
default:
break;
}
return V_5 ;
}
static int F_18 ( struct V_48 * V_49 )
{
struct V_50 V_51 = {} ;
struct V_52 * V_53 = F_19 ( V_49 , V_54 , 0 ) ;
struct V_52 * V_55 = F_19 ( V_49 , V_56 , 0 ) ;
struct V_57 * V_58 ;
const struct V_59 * V_60 ;
const struct V_61 * V_62 ;
int V_63 , line ;
V_62 = F_20 ( V_64 , & V_49 -> V_16 ) ;
if ( ! V_62 ) {
F_21 ( & V_49 -> V_16 , L_3 ) ;
return - V_24 ;
}
V_60 = V_62 -> V_58 ;
if ( ! V_53 || ! V_55 ) {
F_21 ( & V_49 -> V_16 , L_4 ) ;
return - V_65 ;
}
V_58 = F_22 ( & V_49 -> V_16 , sizeof( * V_58 ) , V_66 ) ;
if ( ! V_58 )
return - V_67 ;
F_23 ( & V_51 . V_2 . V_68 ) ;
V_51 . V_2 . type = V_69 ;
V_51 . V_2 . V_70 = V_71 | V_72 | V_73 ;
V_51 . V_2 . V_74 = V_75 ;
V_51 . V_2 . V_76 = V_53 -> V_77 ;
V_51 . V_2 . V_47 = 2 ;
V_51 . V_2 . V_78 = F_14 ;
V_51 . V_2 . V_43 = F_16 ;
V_51 . V_2 . V_55 = V_55 -> V_77 ;
V_51 . V_2 . V_16 = & V_49 -> V_16 ;
V_51 . V_2 . V_79 = V_60 -> V_79 ;
V_51 . V_80 = V_60 -> V_80 ;
V_51 . V_81 = V_82 | V_83 ;
line = F_24 ( V_49 -> V_16 . V_84 , L_5 ) ;
if ( line >= 0 )
V_51 . V_2 . line = line ;
V_51 . V_2 . V_4 = F_25 ( & V_49 -> V_16 , V_53 -> V_77 ,
F_26 ( V_53 ) ) ;
if ( ! V_51 . V_2 . V_4 )
return - V_67 ;
V_58 -> V_85 = F_27 ( & V_49 -> V_16 , L_6 ) ;
if ( F_28 ( V_58 -> V_85 ) ) {
V_63 = F_29 ( V_58 -> V_85 ) ;
if ( V_63 != - V_86 )
F_21 ( & V_49 -> V_16 ,
L_7 , V_63 ) ;
return V_63 ;
}
V_58 -> V_87 = F_27 ( & V_49 -> V_16 , L_8 ) ;
if ( F_28 ( V_58 -> V_87 ) ) {
V_63 = F_29 ( V_58 -> V_87 ) ;
if ( V_63 != - V_86 )
F_21 ( & V_49 -> V_16 ,
L_9 , V_63 ) ;
return V_63 ;
}
V_63 = F_30 ( V_58 -> V_85 ) ;
if ( V_63 ) {
F_21 ( & V_49 -> V_16 , L_10 , V_63 ) ;
goto V_88;
}
V_63 = F_30 ( V_58 -> V_87 ) ;
if ( V_63 ) {
F_21 ( & V_49 -> V_16 , L_11 , V_63 ) ;
goto V_89;
}
V_51 . V_2 . V_20 = F_31 ( V_58 -> V_87 ) ;
V_58 -> line = F_32 ( & V_51 ) ;
if ( V_58 -> line < 0 ) {
V_63 = V_58 -> line ;
goto V_90;
}
F_33 ( V_49 , V_58 ) ;
return 0 ;
V_90:
F_34 ( V_58 -> V_87 ) ;
V_89:
F_34 ( V_58 -> V_85 ) ;
V_88:
return V_63 ;
}
static int F_35 ( struct V_48 * V_49 )
{
struct V_57 * V_58 = F_36 ( V_49 ) ;
F_37 ( V_58 -> line ) ;
F_34 ( V_58 -> V_85 ) ;
F_34 ( V_58 -> V_87 ) ;
return 0 ;
}
