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
int V_32 , V_33 ;
V_6 -> V_34 = F_15 () ;
if ( ! V_6 -> V_34 ) {
F_16 ( V_18 -> V_7 , L_2 ) ;
return - V_35 ;
}
V_6 -> V_34 -> V_6 = ( void * ) V_18 ;
V_6 -> V_34 -> V_36 = & F_1 ;
V_6 -> V_34 -> V_37 = & F_3 ;
V_6 -> V_34 -> V_38 = L_3 ;
snprintf ( V_6 -> V_34 -> V_39 , V_40 , L_4 ,
V_18 -> V_41 -> V_2 -> V_42 , V_18 -> V_41 -> V_43 ) ;
V_6 -> V_34 -> V_44 = F_17 ( sizeof( int ) * V_45 , V_46 ) ;
if ( ! V_6 -> V_34 -> V_44 ) {
V_32 = - V_35 ;
goto V_47;
}
for ( V_33 = 0 ; V_33 < V_45 ; V_33 ++ )
V_6 -> V_34 -> V_44 [ V_33 ] = V_48 ;
V_32 = F_18 ( V_6 -> V_34 ) ;
if ( V_32 ) {
F_16 ( V_18 -> V_7 , L_5 ) ;
goto V_49;
}
F_19 ( V_18 -> V_7 , L_6 , V_6 -> V_34 -> V_39 ) ;
return 0 ;
V_49:
F_20 ( V_6 -> V_34 -> V_44 ) ;
V_47:
F_21 ( V_6 -> V_34 ) ;
return V_32 ;
}
static void F_22 ( struct V_5 * V_18 )
{
struct V_19 * V_6 = V_18 -> V_20 ;
F_19 ( V_18 -> V_7 , L_7 , V_6 -> V_34 -> V_39 ) ;
F_23 ( V_6 -> V_34 ) ;
F_20 ( V_6 -> V_34 -> V_44 ) ;
F_21 ( V_6 -> V_34 ) ;
}
static int F_24 ( struct V_9 * V_7 ,
struct V_50 * V_12 )
{
if ( ! V_7 -> V_14 )
return - V_15 ;
return F_25 ( V_7 -> V_14 , V_12 ) ;
}
static int F_26 ( struct V_9 * V_7 ,
struct V_50 * V_12 )
{
if ( ! V_7 -> V_14 )
return - V_15 ;
return F_27 ( V_7 -> V_14 , V_12 ) ;
}
static int F_28 ( struct V_9 * V_7 )
{
if ( ! V_7 -> V_14 )
return - V_15 ;
return F_29 ( V_7 -> V_14 ) ;
}
static int F_30 ( struct V_5 * V_18 , int V_51 )
{
int V_32 ;
V_32 = F_31 ( V_18 , V_52 ) ;
if ( V_32 < 0 )
goto V_53;
F_32 ( 150 ) ;
V_32 = F_31 ( V_18 , V_54 ) ;
if ( V_32 < 0 )
goto V_53;
F_32 ( 150 ) ;
V_32 = F_31 ( V_18 , V_51 ? V_55 : V_52 ) ;
if ( V_32 < 0 )
goto V_53;
return 0 ;
V_53:
return V_32 ;
}
static int F_33 ( struct V_5 * V_18 , struct V_56 * V_57 )
{
int V_32 ;
T_2 V_58 [ V_59 ] ;
struct V_19 * V_6 ;
F_34 ( V_18 , V_57 ) ;
V_6 = F_17 ( sizeof( * V_6 ) , V_46 ) ;
if ( ! V_6 )
return - V_35 ;
V_18 -> V_20 = V_6 ;
V_32 = F_35 ( V_18 , V_60 , 0 , 0 , V_59 , V_58 ) ;
if ( V_32 < 0 ) {
F_16 ( V_18 -> V_7 , L_8 , V_32 ) ;
goto free;
}
memcpy ( V_18 -> V_7 -> V_61 , V_58 , V_59 ) ;
V_18 -> V_7 -> V_62 = & V_63 ;
V_18 -> V_7 -> V_64 = & V_65 ;
V_32 = F_35 ( V_18 , V_66 , 0 , 0 , 1 , V_58 ) ;
if ( V_32 < 0 ) {
F_16 ( V_18 -> V_7 , L_9 ,
V_32 ) ;
goto free;
}
F_11 ( V_18 -> V_7 , L_10 , V_58 [ 0 ] ) ;
switch ( V_58 [ 0 ] & V_67 ) {
case V_68 :
F_11 ( V_18 -> V_7 , L_11 ) ;
V_6 -> V_69 = 1 ;
break;
case V_70 :
F_11 ( V_18 -> V_7 , L_12 ) ;
V_6 -> V_69 = 0 ;
break;
default:
F_16 ( V_18 -> V_7 , L_13 ) ;
V_32 = - V_71 ;
goto free;
}
V_6 -> V_72 = F_36 ( V_18 , V_6 -> V_69 ) ;
F_30 ( V_18 , V_6 -> V_69 ) ;
if ( V_18 -> V_73 -> V_74 & V_75 ) {
V_18 -> V_76 = 2048 ;
}
V_32 = F_14 ( V_18 ) ;
if ( V_32 )
goto free;
return 0 ;
free:
F_20 ( V_6 ) ;
return V_32 ;
}
static int F_37 ( struct V_5 * V_18 )
{
struct V_19 * V_6 = V_18 -> V_20 ;
F_11 ( V_18 -> V_7 , L_14 ) ;
if ( V_6 -> V_14 ) {
F_19 ( V_18 -> V_7 , L_15 ,
V_6 -> V_77 ) ;
F_38 ( V_6 -> V_14 ) ;
F_39 ( V_6 -> V_14 ) ;
}
return 0 ;
}
static void F_40 ( struct V_5 * V_18 , struct V_56 * V_57 )
{
struct V_19 * V_6 = V_18 -> V_20 ;
F_22 ( V_18 ) ;
F_20 ( V_6 ) ;
}
static int F_41 ( struct V_5 * V_18 )
{
struct V_78 * V_79 = (struct V_78 * ) & V_18 -> V_79 ;
struct V_19 * V_6 = V_18 -> V_20 ;
int V_32 ;
T_1 V_80 ;
F_30 ( V_18 , V_6 -> V_69 ) ;
F_32 ( 150 ) ;
V_80 = F_42 ( V_18 ) ;
F_11 ( V_18 -> V_7 , L_16 , V_80 ) ;
V_32 = F_43 ( V_18 , 0x0000 ) ;
if ( V_32 < 0 )
goto V_81;
V_80 = F_42 ( V_18 ) ;
F_11 ( V_18 -> V_7 , L_17 , V_80 ) ;
F_32 ( 150 ) ;
V_32 = F_44 ( V_18 , V_82 ,
V_83 | V_84 ,
V_85 , 0 , NULL ) ;
if ( V_32 < 0 ) {
F_16 ( V_18 -> V_7 , L_18 , V_32 ) ;
goto V_81;
}
memcpy ( V_79 -> V_86 , V_18 -> V_7 -> V_61 , V_59 ) ;
V_32 = F_44 ( V_18 , V_87 , 0 , 0 , V_59 ,
V_79 -> V_86 ) ;
if ( V_32 < 0 )
goto V_81;
V_32 = F_43 ( V_18 , V_88 ) ;
if ( V_32 < 0 )
goto V_81;
V_80 = F_42 ( V_18 ) ;
F_11 ( V_18 -> V_7 , L_19 ,
V_80 ) ;
V_80 = F_45 ( V_18 ) ;
F_11 ( V_18 -> V_7 , L_20 ,
V_80 ) ;
snprintf ( V_6 -> V_77 , 20 , V_89 ,
V_6 -> V_34 -> V_39 , V_6 -> V_72 ) ;
V_6 -> V_14 = F_46 ( V_18 -> V_7 , V_6 -> V_77 ,
& F_8 ,
V_90 ) ;
if ( F_47 ( V_6 -> V_14 ) ) {
F_16 ( V_18 -> V_7 , L_21 ,
V_6 -> V_77 ) ;
V_32 = F_48 ( V_6 -> V_14 ) ;
goto V_81;
}
F_19 ( V_18 -> V_7 , L_22 , V_6 -> V_77 ) ;
F_49 ( V_6 -> V_14 ) ;
F_50 ( V_6 -> V_14 ) ;
return 0 ;
V_81:
return V_32 ;
}
static int F_51 ( struct V_5 * V_18 , struct V_91 * V_92 )
{
struct V_19 * V_93 = V_18 -> V_20 ;
struct V_94 * V_95 = & V_93 -> V_96 ;
return F_52 ( V_18 , V_92 , V_95 ) ;
}
