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
F_10 ( V_18 , V_21 , 0 ) ;
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
static int F_22 ( struct V_9 * V_7 )
{
if ( ! V_7 -> V_14 )
return - V_15 ;
return F_23 ( V_7 -> V_14 ) ;
}
static int F_24 ( struct V_5 * V_18 , int V_44 )
{
int V_32 ;
V_32 = F_25 ( V_18 , V_45 , 0 ) ;
if ( V_32 < 0 )
goto V_46;
F_26 ( 150 ) ;
V_32 = F_25 ( V_18 , V_47 , 0 ) ;
if ( V_32 < 0 )
goto V_46;
F_26 ( 150 ) ;
V_32 = F_25 ( V_18 , V_44 ? V_48 : V_45 ,
0 ) ;
if ( V_32 < 0 )
goto V_46;
return 0 ;
V_46:
return V_32 ;
}
static int F_27 ( struct V_5 * V_18 , struct V_49 * V_50 )
{
int V_32 ;
T_2 V_51 [ V_52 ] ;
struct V_19 * V_6 ;
F_28 ( V_18 , V_50 ) ;
V_6 = F_29 ( sizeof( * V_6 ) , V_53 ) ;
if ( ! V_6 )
return - V_34 ;
V_18 -> V_20 = V_6 ;
V_32 = F_30 ( V_18 , V_54 , 0 , 0 , V_52 , V_51 , 0 ) ;
if ( V_32 < 0 ) {
F_16 ( V_18 -> V_7 , L_8 , V_32 ) ;
goto free;
}
memcpy ( V_18 -> V_7 -> V_55 , V_51 , V_52 ) ;
V_18 -> V_7 -> V_56 = & V_57 ;
V_18 -> V_7 -> V_58 = & V_59 ;
V_32 = F_30 ( V_18 , V_60 , 0 , 0 , 1 , V_51 , 0 ) ;
if ( V_32 < 0 ) {
F_16 ( V_18 -> V_7 , L_9 ,
V_32 ) ;
goto free;
}
F_11 ( V_18 -> V_7 , L_10 , V_51 [ 0 ] ) ;
switch ( V_51 [ 0 ] & V_61 ) {
case V_62 :
F_11 ( V_18 -> V_7 , L_11 ) ;
V_6 -> V_63 = 1 ;
break;
case V_64 :
F_11 ( V_18 -> V_7 , L_12 ) ;
V_6 -> V_63 = 0 ;
break;
default:
F_16 ( V_18 -> V_7 , L_13 ) ;
V_32 = - V_65 ;
goto free;
}
V_6 -> V_66 = F_31 ( V_18 , V_6 -> V_63 ) ;
F_24 ( V_18 , V_6 -> V_63 ) ;
if ( V_18 -> V_67 -> V_68 & V_69 ) {
V_18 -> V_70 = 2048 ;
}
V_32 = F_14 ( V_18 ) ;
if ( V_32 )
goto free;
return 0 ;
free:
F_32 ( V_6 ) ;
return V_32 ;
}
static int F_33 ( struct V_5 * V_18 )
{
struct V_19 * V_6 = V_18 -> V_20 ;
F_11 ( V_18 -> V_7 , L_14 ) ;
if ( V_6 -> V_14 ) {
F_18 ( V_18 -> V_7 , L_15 ,
V_6 -> V_71 ) ;
F_34 ( V_6 -> V_14 ) ;
F_35 ( V_6 -> V_14 ) ;
}
return 0 ;
}
static void F_36 ( struct V_5 * V_18 , struct V_49 * V_50 )
{
struct V_19 * V_6 = V_18 -> V_20 ;
F_20 ( V_18 ) ;
F_32 ( V_6 ) ;
}
static int F_37 ( struct V_5 * V_18 )
{
struct V_72 * V_73 = (struct V_72 * ) & V_18 -> V_73 ;
struct V_19 * V_6 = V_18 -> V_20 ;
int V_32 ;
T_1 V_74 ;
F_24 ( V_18 , V_6 -> V_63 ) ;
F_26 ( 150 ) ;
V_74 = F_38 ( V_18 , 0 ) ;
F_11 ( V_18 -> V_7 , L_16 , V_74 ) ;
V_32 = F_39 ( V_18 , 0x0000 , 0 ) ;
if ( V_32 < 0 )
goto V_75;
V_74 = F_38 ( V_18 , 0 ) ;
F_11 ( V_18 -> V_7 , L_17 , V_74 ) ;
F_26 ( 150 ) ;
V_32 = F_40 ( V_18 , V_76 ,
V_77 | V_78 ,
V_79 , 0 , NULL , 0 ) ;
if ( V_32 < 0 ) {
F_16 ( V_18 -> V_7 , L_18 , V_32 ) ;
goto V_75;
}
memcpy ( V_73 -> V_80 , V_18 -> V_7 -> V_55 , V_52 ) ;
V_32 = F_40 ( V_18 , V_81 , 0 , 0 , V_52 ,
V_73 -> V_80 , 0 ) ;
if ( V_32 < 0 )
goto V_75;
V_32 = F_39 ( V_18 , V_82 , 0 ) ;
if ( V_32 < 0 )
goto V_75;
V_74 = F_38 ( V_18 , 0 ) ;
F_11 ( V_18 -> V_7 , L_19 ,
V_74 ) ;
V_74 = F_41 ( V_18 , 0 ) ;
F_11 ( V_18 -> V_7 , L_20 ,
V_74 ) ;
snprintf ( V_6 -> V_71 , 20 , V_83 ,
V_6 -> V_33 -> V_38 , V_6 -> V_66 ) ;
V_6 -> V_14 = F_42 ( V_18 -> V_7 , V_6 -> V_71 ,
& F_8 ,
V_84 ) ;
if ( F_43 ( V_6 -> V_14 ) ) {
F_16 ( V_18 -> V_7 , L_21 ,
V_6 -> V_71 ) ;
V_32 = F_44 ( V_6 -> V_14 ) ;
goto V_75;
}
F_18 ( V_18 -> V_7 , L_22 , V_6 -> V_71 ) ;
F_45 ( V_6 -> V_14 ) ;
F_46 ( V_6 -> V_14 ) ;
return 0 ;
V_75:
return V_32 ;
}
static int F_47 ( struct V_5 * V_18 , struct V_85 * V_86 )
{
struct V_19 * V_87 = V_18 -> V_20 ;
struct V_88 * V_89 = & V_87 -> V_90 ;
return F_48 ( V_18 , V_86 , V_89 ) ;
}
