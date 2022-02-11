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
switch ( V_3 ) {
case V_31 :
V_5 |= V_32 ;
break;
case V_25 :
V_5 |= ( V_5 & 0x4 ) << 2 ;
break;
default:
break;
}
F_15 ( V_5 , V_41 -> V_4 + ( V_3 << V_41 -> V_42 ) ) ;
}
static int F_16 ( struct V_43 * V_44 )
{
struct V_45 V_46 = {} ;
struct V_47 * V_48 = F_17 ( V_44 , V_49 , 0 ) ;
struct V_47 * V_50 = F_17 ( V_44 , V_51 , 0 ) ;
struct V_52 * V_53 ;
int V_54 , line ;
if ( ! V_48 || ! V_50 ) {
F_18 ( & V_44 -> V_16 , L_3 ) ;
return - V_55 ;
}
V_53 = F_19 ( & V_44 -> V_16 , sizeof( * V_53 ) , V_56 ) ;
if ( ! V_53 )
return - V_57 ;
F_20 ( & V_46 . V_2 . V_58 ) ;
V_46 . V_2 . type = V_59 ;
V_46 . V_2 . V_60 = V_61 | V_62 | V_63 ;
V_46 . V_2 . V_64 = V_65 ;
V_46 . V_2 . V_66 = V_48 -> V_67 ;
V_46 . V_2 . V_42 = 2 ;
V_46 . V_2 . V_68 = F_14 ;
V_46 . V_2 . V_50 = V_50 -> V_67 ;
V_46 . V_2 . V_16 = & V_44 -> V_16 ;
line = F_21 ( V_44 -> V_16 . V_69 , L_4 ) ;
if ( line >= 0 )
V_46 . V_2 . line = line ;
V_46 . V_2 . V_4 = F_22 ( & V_44 -> V_16 , V_48 -> V_67 ,
F_23 ( V_48 ) ) ;
if ( ! V_46 . V_2 . V_4 )
return - V_57 ;
V_53 -> V_70 = F_24 ( & V_44 -> V_16 , L_5 ) ;
if ( F_25 ( V_53 -> V_70 ) ) {
V_54 = F_26 ( V_53 -> V_70 ) ;
if ( V_54 != - V_71 )
F_18 ( & V_44 -> V_16 ,
L_6 , V_54 ) ;
return V_54 ;
}
V_53 -> V_72 = F_24 ( & V_44 -> V_16 , L_7 ) ;
if ( F_25 ( V_53 -> V_72 ) ) {
V_54 = F_26 ( V_53 -> V_72 ) ;
if ( V_54 != - V_71 )
F_18 ( & V_44 -> V_16 ,
L_8 , V_54 ) ;
return V_54 ;
}
V_54 = F_27 ( V_53 -> V_70 ) ;
if ( V_54 ) {
F_18 ( & V_44 -> V_16 , L_9 , V_54 ) ;
goto V_73;
}
V_54 = F_27 ( V_53 -> V_72 ) ;
if ( V_54 ) {
F_18 ( & V_44 -> V_16 , L_10 , V_54 ) ;
goto V_74;
}
V_46 . V_2 . V_20 = F_28 ( V_53 -> V_72 ) ;
V_53 -> line = F_29 ( & V_46 ) ;
if ( V_53 -> line < 0 ) {
V_54 = V_53 -> line ;
goto V_75;
}
F_30 ( V_44 , V_53 ) ;
return 0 ;
V_75:
F_31 ( V_53 -> V_72 ) ;
V_74:
F_31 ( V_53 -> V_70 ) ;
V_73:
return V_54 ;
}
static int F_32 ( struct V_43 * V_44 )
{
struct V_52 * V_53 = F_33 ( V_44 ) ;
F_34 ( V_53 -> line ) ;
F_31 ( V_53 -> V_70 ) ;
F_31 ( V_53 -> V_72 ) ;
return 0 ;
}
