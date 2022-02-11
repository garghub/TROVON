static inline T_1 F_1 ( void T_2 * V_1 , T_3 V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline void F_3 ( void T_2 * V_1 , T_3 V_2 , T_1 V_3 )
{
F_4 ( V_3 , V_1 + V_2 ) ;
}
static inline enum V_4 F_5 ( T_1 error )
{
return ( error & 0x0f000000 ) >> V_5 ;
}
static inline T_4 F_6 ( T_1 V_6 )
{
return V_6 & 0xffffffff ;
}
static inline unsigned F_7 ( T_1 error )
{
return ( error & 0x07 ) >> V_7 ;
}
static inline enum V_8 F_8 ( T_1 error )
{
return ( error & 0xff00 ) >> V_9 ;
}
static inline unsigned F_9 ( T_1 error )
{
return ( error >> 32 ) & 0xffff ;
}
static char * F_10 ( T_5 V_10 )
{
switch ( V_10 ) {
case V_11 :
return L_1 ;
case V_12 :
return L_2 ;
case V_13 :
return L_3 ;
case V_14 :
return L_4 ;
case V_15 :
return L_5 ;
case V_16 :
return L_6 ;
case V_17 :
return L_7 ;
default:
return L_8 ;
}
}
static char * F_11 ( T_5 V_18 )
{
switch ( V_18 ) {
case V_19 :
return L_9 ;
case V_20 :
return L_10 ;
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
return L_11 ;
case V_26 :
case V_27 :
case V_28 :
return L_12 ;
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
return L_13 ;
case V_35 :
return L_14 ;
case V_36 :
case V_37 :
case V_38 :
return L_15 ;
case V_39 :
return L_16 ;
case V_40 :
case V_41 :
return L_17 ;
case V_42 :
case V_43 :
case V_44 :
case V_45 :
return L_18 ;
case V_46 :
return L_19 ;
case V_47 :
return L_20 ;
default:
return L_21 ;
}
}
static T_6 F_12 ( struct V_48 * V_49 ,
T_1 error , int V_6 )
{
T_5 V_10 = F_5 ( error ) ;
T_5 V_18 = F_8 ( error ) ;
T_5 V_50 = error & V_51 ;
T_4 V_52 = F_6 ( V_6 ) ;
F_13 ( L_22 ,
F_10 ( V_10 ) ,
F_11 ( V_18 ) ,
V_50 ? L_23 : L_24 , V_52 ) ;
F_14 ( 1 ) ;
return V_53 ;
}
static T_6 F_15 ( int V_54 , void * V_55 )
{
struct V_48 * V_49 = V_55 ;
T_1 V_56 , V_57 ;
T_1 error ;
T_1 V_6 ;
T_1 V_58 = 0 ;
void T_2 * V_1 ;
int V_59 ;
T_6 V_60 = V_61 ;
V_59 = V_54 == V_49 -> V_62 ? V_63 : V_64 ;
if ( ! V_59 ) {
V_56 = F_1 ( V_49 -> V_65 , V_66 ) ;
F_16 ( V_56 & V_67 ) ;
} else {
V_56 = F_1 ( V_49 -> V_65 , V_68 ) ;
}
V_58 = F_17 ( V_56 ) ;
V_1 = V_49 -> V_65 + V_69 [ V_59 ] [ V_58 ] ;
error = F_1 ( V_1 , V_70 ) ;
if ( error ) {
V_6 = F_1 ( V_1 , V_71 ) ;
V_60 |= F_12 ( V_49 , error , V_6 ) ;
}
V_57 = ( V_72 << V_59 ) |
V_73 ;
F_3 ( V_1 , V_74 , V_57 ) ;
F_3 ( V_1 , V_70 , error ) ;
return V_60 ;
}
static int F_18 ( struct V_75 * V_76 )
{
struct V_48 * V_49 ;
struct V_77 * V_78 ;
int V_60 ;
V_49 = F_19 ( sizeof( * V_49 ) , V_79 ) ;
if ( ! V_49 )
return - V_80 ;
F_20 ( V_76 , V_49 ) ;
V_78 = F_21 ( V_76 , V_81 , 0 ) ;
if ( ! V_78 ) {
F_22 ( & V_76 -> V_82 , L_25 ) ;
V_60 = - V_83 ;
goto V_84;
}
V_49 -> V_65 = F_23 ( V_78 -> V_85 , F_24 ( V_78 ) ) ;
if ( ! V_49 -> V_65 ) {
F_22 ( & V_76 -> V_82 , L_26 ) ;
V_60 = - V_80 ;
goto V_84;
}
V_49 -> V_86 = F_25 ( V_76 , 0 ) ;
V_60 = F_26 ( V_49 -> V_86 , F_15 , V_87 ,
L_27 , V_49 ) ;
if ( V_60 ) {
F_22 ( & V_76 -> V_82 , L_28 ) ;
goto V_88;
}
V_49 -> V_62 = F_25 ( V_76 , 1 ) ;
V_60 = F_26 ( V_49 -> V_62 , F_15 , V_87 ,
L_29 , V_49 ) ;
if ( V_60 ) {
F_22 ( & V_76 -> V_82 , L_30 ) ;
goto V_89;
}
return 0 ;
V_89:
F_27 ( V_49 -> V_86 , V_49 ) ;
V_88:
F_28 ( V_49 -> V_65 ) ;
V_84:
F_29 ( V_49 ) ;
return V_60 ;
}
static int F_30 ( struct V_75 * V_76 )
{
struct V_48 * V_49 = F_31 ( V_76 ) ;
F_27 ( V_49 -> V_62 , V_49 ) ;
F_27 ( V_49 -> V_86 , V_49 ) ;
F_28 ( V_49 -> V_65 ) ;
F_29 ( V_49 ) ;
return 0 ;
}
static int T_7 F_32 ( void )
{
return F_33 ( & V_90 ) ;
}
static void T_8 F_34 ( void )
{
F_35 ( & V_90 ) ;
}
