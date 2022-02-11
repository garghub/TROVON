static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
return F_2 ( ( (struct V_5 * ) V_2 -> V_6 ) -> V_7 , V_3 ,
V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_8 )
{
F_4 ( ( (struct V_5 * ) V_2 -> V_6 ) -> V_7 , V_3 , V_4 , V_8 ) ;
return 0 ;
}
static int F_5 ( struct V_9 * V_7 , struct V_10 * V_11 , int V_12 )
{
if ( ! F_6 ( V_7 ) )
return - V_13 ;
if ( ! V_7 -> V_14 )
return - V_15 ;
return F_7 ( V_7 -> V_14 , V_11 , V_12 ) ;
}
static void F_8 ( struct V_9 * V_16 )
{
struct V_17 * V_14 = V_16 -> V_14 ;
struct V_5 * V_18 = F_9 ( V_16 ) ;
struct V_19 * V_6 = V_18 -> V_20 ;
T_1 V_21 = 0 ;
if ( V_14 -> V_22 ) {
V_21 = V_23 ;
if ( V_14 -> V_24 == V_25 )
V_21 &= ~ V_26 ;
if ( V_14 -> V_27 != V_28 )
V_21 &= ~ V_29 ;
}
if ( V_21 != V_6 -> V_30 ) {
F_10 ( V_18 , V_21 ) ;
V_6 -> V_30 = V_21 ;
F_11 ( V_16 , L_1 ,
V_14 -> V_27 , V_14 -> V_24 , V_21 ) ;
F_12 ( V_14 ) ;
}
}
static void F_13 ( struct V_5 * V_18 , struct V_31 * V_31 )
{
}
static int F_14 ( struct V_5 * V_18 )
{
struct V_19 * V_6 = V_18 -> V_20 ;
int V_32 ;
V_6 -> V_33 = F_15 () ;
if ( ! V_6 -> V_33 ) {
F_16 ( V_18 -> V_7 , L_2 ) ;
return - V_34 ;
}
V_6 -> V_33 -> V_6 = ( void * ) V_18 ;
V_6 -> V_33 -> V_35 = & F_1 ;
V_6 -> V_33 -> V_36 = & F_3 ;
V_6 -> V_33 -> V_37 = L_3 ;
snprintf ( V_6 -> V_33 -> V_38 , V_39 , L_4 ,
V_18 -> V_40 -> V_2 -> V_41 , V_18 -> V_40 -> V_42 ) ;
V_32 = F_17 ( V_6 -> V_33 ) ;
if ( V_32 ) {
F_16 ( V_18 -> V_7 , L_5 ) ;
goto V_43;
}
F_18 ( V_18 -> V_7 , L_6 , V_6 -> V_33 -> V_38 ) ;
return 0 ;
V_43:
F_19 ( V_6 -> V_33 ) ;
return V_32 ;
}
static void F_20 ( struct V_5 * V_18 )
{
struct V_19 * V_6 = V_18 -> V_20 ;
F_18 ( V_18 -> V_7 , L_7 , V_6 -> V_33 -> V_38 ) ;
F_21 ( V_6 -> V_33 ) ;
F_19 ( V_6 -> V_33 ) ;
}
static int F_22 ( struct V_9 * V_7 ,
struct V_44 * V_12 )
{
if ( ! V_7 -> V_14 )
return - V_15 ;
return F_23 ( V_7 -> V_14 , V_12 ) ;
}
static int F_24 ( struct V_9 * V_7 ,
struct V_44 * V_12 )
{
if ( ! V_7 -> V_14 )
return - V_15 ;
return F_25 ( V_7 -> V_14 , V_12 ) ;
}
static int F_26 ( struct V_9 * V_7 )
{
if ( ! V_7 -> V_14 )
return - V_15 ;
return F_27 ( V_7 -> V_14 ) ;
}
static int F_28 ( struct V_5 * V_18 , int V_45 )
{
int V_32 ;
V_32 = F_29 ( V_18 , V_46 ) ;
if ( V_32 < 0 )
goto V_47;
F_30 ( 150 ) ;
V_32 = F_29 ( V_18 , V_48 ) ;
if ( V_32 < 0 )
goto V_47;
F_30 ( 150 ) ;
V_32 = F_29 ( V_18 , V_45 ? V_49 : V_46 ) ;
if ( V_32 < 0 )
goto V_47;
return 0 ;
V_47:
return V_32 ;
}
static int F_31 ( struct V_5 * V_18 , struct V_50 * V_51 )
{
int V_32 ;
T_2 V_52 [ V_53 ] ;
struct V_19 * V_6 ;
F_32 ( V_18 , V_51 ) ;
V_6 = F_33 ( sizeof( * V_6 ) , V_54 ) ;
if ( ! V_6 )
return - V_34 ;
V_18 -> V_20 = V_6 ;
V_32 = F_34 ( V_18 , V_55 , 0 , 0 , V_53 , V_52 ) ;
if ( V_32 < 0 ) {
F_16 ( V_18 -> V_7 , L_8 , V_32 ) ;
goto free;
}
memcpy ( V_18 -> V_7 -> V_56 , V_52 , V_53 ) ;
V_18 -> V_7 -> V_57 = & V_58 ;
V_18 -> V_7 -> V_59 = & V_60 ;
V_32 = F_34 ( V_18 , V_61 , 0 , 0 , 1 , V_52 ) ;
if ( V_32 < 0 ) {
F_16 ( V_18 -> V_7 , L_9 ,
V_32 ) ;
goto free;
}
F_11 ( V_18 -> V_7 , L_10 , V_52 [ 0 ] ) ;
switch ( V_52 [ 0 ] & V_62 ) {
case V_63 :
F_11 ( V_18 -> V_7 , L_11 ) ;
V_6 -> V_64 = 1 ;
break;
case V_65 :
F_11 ( V_18 -> V_7 , L_12 ) ;
V_6 -> V_64 = 0 ;
break;
default:
F_16 ( V_18 -> V_7 , L_13 ) ;
V_32 = - V_66 ;
goto free;
}
V_6 -> V_67 = F_35 ( V_18 , V_6 -> V_64 ) ;
F_28 ( V_18 , V_6 -> V_64 ) ;
if ( V_18 -> V_68 -> V_69 & V_70 ) {
V_18 -> V_71 = 2048 ;
}
V_32 = F_14 ( V_18 ) ;
if ( V_32 )
goto free;
return 0 ;
free:
F_36 ( V_6 ) ;
return V_32 ;
}
static int F_37 ( struct V_5 * V_18 )
{
struct V_19 * V_6 = V_18 -> V_20 ;
F_11 ( V_18 -> V_7 , L_14 ) ;
if ( V_6 -> V_14 ) {
F_18 ( V_18 -> V_7 , L_15 ,
V_6 -> V_72 ) ;
F_38 ( V_6 -> V_14 ) ;
F_39 ( V_6 -> V_14 ) ;
}
return 0 ;
}
static void F_40 ( struct V_5 * V_18 , struct V_50 * V_51 )
{
struct V_19 * V_6 = V_18 -> V_20 ;
F_20 ( V_18 ) ;
F_36 ( V_6 ) ;
}
static int F_41 ( struct V_5 * V_18 )
{
struct V_73 * V_74 = (struct V_73 * ) & V_18 -> V_74 ;
struct V_19 * V_6 = V_18 -> V_20 ;
int V_32 ;
T_1 V_75 ;
F_28 ( V_18 , V_6 -> V_64 ) ;
F_30 ( 150 ) ;
V_75 = F_42 ( V_18 ) ;
F_11 ( V_18 -> V_7 , L_16 , V_75 ) ;
V_32 = F_43 ( V_18 , 0x0000 ) ;
if ( V_32 < 0 )
goto V_76;
V_75 = F_42 ( V_18 ) ;
F_11 ( V_18 -> V_7 , L_17 , V_75 ) ;
F_30 ( 150 ) ;
V_32 = F_44 ( V_18 , V_77 ,
V_78 | V_79 ,
V_80 , 0 , NULL ) ;
if ( V_32 < 0 ) {
F_16 ( V_18 -> V_7 , L_18 , V_32 ) ;
goto V_76;
}
memcpy ( V_74 -> V_81 , V_18 -> V_7 -> V_56 , V_53 ) ;
V_32 = F_44 ( V_18 , V_82 , 0 , 0 , V_53 ,
V_74 -> V_81 ) ;
if ( V_32 < 0 )
goto V_76;
V_32 = F_43 ( V_18 , V_83 ) ;
if ( V_32 < 0 )
goto V_76;
V_75 = F_42 ( V_18 ) ;
F_11 ( V_18 -> V_7 , L_19 ,
V_75 ) ;
V_75 = F_45 ( V_18 ) ;
F_11 ( V_18 -> V_7 , L_20 ,
V_75 ) ;
snprintf ( V_6 -> V_72 , 20 , V_84 ,
V_6 -> V_33 -> V_38 , V_6 -> V_67 ) ;
V_6 -> V_14 = F_46 ( V_18 -> V_7 , V_6 -> V_72 ,
& F_8 ,
V_85 ) ;
if ( F_47 ( V_6 -> V_14 ) ) {
F_16 ( V_18 -> V_7 , L_21 ,
V_6 -> V_72 ) ;
V_32 = F_48 ( V_6 -> V_14 ) ;
goto V_76;
}
F_18 ( V_18 -> V_7 , L_22 , V_6 -> V_72 ) ;
F_49 ( V_6 -> V_14 ) ;
F_50 ( V_6 -> V_14 ) ;
return 0 ;
V_76:
return V_32 ;
}
static int F_51 ( struct V_5 * V_18 , struct V_86 * V_87 )
{
struct V_19 * V_88 = V_18 -> V_20 ;
struct V_89 * V_90 = & V_88 -> V_91 ;
return F_52 ( V_18 , V_87 , V_90 ) ;
}
