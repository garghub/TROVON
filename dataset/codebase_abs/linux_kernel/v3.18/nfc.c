static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
F_2 ( & V_2 -> V_3 -> V_4 ) ;
F_3 ( V_2 -> V_3 ) ;
F_4 ( V_2 -> V_3 ) ;
}
if ( V_2 -> V_5 ) {
F_2 ( & V_2 -> V_5 -> V_4 ) ;
F_3 ( V_2 -> V_5 ) ;
F_4 ( V_2 -> V_5 ) ;
}
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
if ( ! V_2 -> V_3 )
return - V_8 ;
V_7 = V_2 -> V_3 -> V_7 ;
switch ( V_2 -> V_9 ) {
case V_10 :
switch ( V_2 -> V_11 ) {
case V_12 :
V_2 -> V_13 = L_1 ;
return 0 ;
default:
F_6 ( V_7 -> V_7 , L_2 ,
V_2 -> V_11 ) ;
return - V_14 ;
}
case V_15 :
switch ( V_2 -> V_11 ) {
case V_16 :
V_2 -> V_13 = L_3 ;
return 0 ;
default:
F_6 ( V_7 -> V_7 , L_2 ,
V_2 -> V_11 ) ;
return - V_14 ;
}
default:
F_6 ( V_7 -> V_7 , L_4 ,
V_2 -> V_9 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_17 * V_3 ;
struct V_18 * V_19 , * V_20 ;
struct F_7 * V_21 ;
struct V_22 * V_23 ;
T_1 V_24 , V_25 ;
int V_26 , V_27 ;
V_3 = V_2 -> V_3 ;
V_7 = V_3 -> V_7 ;
V_24 = sizeof( struct V_18 ) +
sizeof( struct F_7 ) ;
V_25 = sizeof( struct V_18 ) +
sizeof( struct V_22 ) ;
V_19 = F_8 ( V_24 , V_28 ) ;
if ( ! V_19 )
return - V_29 ;
V_21 = (struct F_7 * ) V_19 -> V_30 ;
V_20 = F_8 ( V_25 , V_28 ) ;
if ( ! V_20 ) {
F_4 ( V_19 ) ;
return - V_29 ;
}
V_23 = (struct V_22 * ) V_20 -> V_30 ;
V_19 -> V_31 = V_32 ;
V_19 -> V_33 = 3 ;
V_19 -> V_34 = V_35 ;
V_21 -> V_36 = V_2 -> V_36 ;
V_21 -> V_9 = V_2 -> V_9 ;
V_27 = F_9 ( V_3 , ( V_37 * ) V_19 , V_24 ) ;
if ( V_27 < 0 ) {
F_6 ( V_7 -> V_7 , L_5 ) ;
goto V_38;
}
V_26 = F_10 ( V_3 , ( V_37 * ) V_20 , V_25 ) ;
if ( V_26 < 0 ) {
F_6 ( V_7 -> V_7 , L_6 ) ;
V_27 = V_26 ;
goto V_38;
}
F_11 ( V_7 -> V_7 , L_7 ,
V_23 -> V_36 , V_23 -> V_9 ) ;
F_11 ( V_7 -> V_7 , L_8 ,
V_23 -> V_39 , V_23 -> V_40 ,
V_23 -> V_41 , V_23 -> V_42 ) ;
V_27 = 0 ;
V_38:
F_4 ( V_20 ) ;
F_4 ( V_19 ) ;
return V_27 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_17 * V_3 ;
struct V_18 V_19 ;
struct V_43 * V_20 = NULL ;
struct F_12 * V_44 ;
T_1 V_45 ;
int V_26 , V_27 ;
V_3 = V_2 -> V_5 ;
V_7 = V_3 -> V_7 ;
memset ( & V_19 , 0 , sizeof( struct V_18 ) ) ;
V_19 . V_31 = V_32 ;
V_19 . V_33 = 1 ;
V_19 . V_34 = V_46 ;
V_27 = F_9 ( V_3 , ( V_37 * ) & V_19 , sizeof( struct V_18 ) ) ;
if ( V_27 < 0 ) {
F_6 ( V_7 -> V_7 , L_9 ) ;
return V_27 ;
}
V_45 = sizeof( struct V_43 ) +
sizeof( struct F_12 ) ;
V_20 = F_8 ( V_45 , V_28 ) ;
if ( ! V_20 )
return - V_29 ;
V_26 = F_10 ( V_3 , ( V_37 * ) V_20 , V_45 ) ;
if ( V_26 < 0 || V_26 < sizeof( struct V_43 ) ) {
F_6 ( V_7 -> V_7 , L_10 ) ;
V_27 = - V_47 ;
goto V_38;
}
V_44 = (struct F_12 * ) V_20 -> V_30 ;
V_2 -> V_36 = V_44 -> V_36 ;
V_2 -> V_9 = V_44 -> V_9 ;
V_2 -> V_11 = V_44 -> V_11 ;
V_38:
F_4 ( V_20 ) ;
return V_27 ;
}
static int F_13 ( struct V_48 * V_49 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 = & V_50 ;
int V_27 ;
V_7 = V_2 -> V_3 -> V_7 ;
V_27 = F_7 ( V_2 ) ;
if ( V_27 < 0 ) {
F_6 ( V_7 -> V_7 , L_11 ) ;
return V_27 ;
}
return 0 ;
}
static int F_14 ( struct V_48 * V_49 )
{
return 0 ;
}
static int F_15 ( struct V_48 * V_49 , V_37 * V_51 , T_1 V_52 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_53 * V_54 ;
V_37 * V_55 ;
int V_38 ;
V_2 = (struct V_1 * ) V_49 -> V_56 ;
V_7 = V_2 -> V_3 -> V_7 ;
V_38 = - V_29 ;
V_55 = F_8 ( V_52 + V_57 , V_28 ) ;
if ( ! V_55 )
goto V_58;
V_54 = (struct V_53 * ) V_55 ;
V_54 -> V_19 = V_59 ;
V_54 -> V_60 = 0 ;
V_54 -> V_61 = V_2 -> V_61 ;
V_54 -> V_62 = 0 ;
V_54 -> V_33 = V_52 ;
memcpy ( V_55 + V_57 , V_51 , V_52 ) ;
V_38 = F_9 ( V_2 -> V_3 , V_55 , V_52 + V_57 ) ;
if ( V_38 < 0 )
goto V_58;
if ( ! F_16 ( V_2 -> V_63 ,
V_2 -> V_64 == V_2 -> V_61 , V_65 ) ) {
F_6 ( V_7 -> V_7 , L_12 ) ;
V_38 = - V_66 ;
} else {
V_2 -> V_61 ++ ;
}
V_58:
F_4 ( V_55 ) ;
return V_38 ;
}
static int F_17 ( struct V_48 * V_49 , V_37 * V_51 , T_1 V_52 )
{
struct V_1 * V_2 ;
struct V_53 * V_67 ;
int V_68 ;
V_2 = (struct V_1 * ) V_49 -> V_56 ;
V_68 = F_10 ( V_2 -> V_3 , V_51 , V_52 ) ;
if ( V_68 < 0 )
return V_68 ;
V_67 = (struct V_53 * ) V_51 ;
if ( V_67 -> V_19 == V_59 ) {
V_2 -> V_64 = V_67 -> V_61 ;
F_18 ( & V_2 -> V_63 ) ;
return 0 ;
}
return V_68 ;
}
static void F_19 ( struct V_69 * V_70 )
{
struct V_6 * V_7 ;
struct V_48 * V_49 ;
struct V_1 * V_2 ;
struct V_17 * V_5 ;
V_2 = F_20 ( V_70 , struct V_1 , V_71 ) ;
V_5 = V_2 -> V_5 ;
V_7 = V_5 -> V_7 ;
F_21 ( & V_7 -> V_72 ) ;
if ( F_22 ( V_5 , NULL ) < 0 ) {
F_23 ( & V_7 -> V_72 ) ;
F_6 ( V_7 -> V_7 , L_13 ) ;
goto V_38;
}
F_23 ( & V_7 -> V_72 ) ;
if ( F_12 ( V_2 ) < 0 ) {
F_6 ( V_7 -> V_7 , L_14 ) ;
goto V_38;
}
F_11 ( V_7 -> V_7 , L_15 ,
V_2 -> V_36 , V_2 -> V_9 , V_2 -> V_11 ) ;
F_21 ( & V_7 -> V_72 ) ;
if ( F_24 ( V_5 ) < 0 ) {
F_23 ( & V_7 -> V_72 ) ;
F_6 ( V_7 -> V_7 , L_16 ) ;
goto V_38;
}
F_23 ( & V_7 -> V_72 ) ;
if ( F_5 ( V_2 ) < 0 ) {
F_6 ( V_7 -> V_7 , L_17 ) ;
return;
}
V_49 = F_25 ( V_7 , V_73 , V_2 -> V_13 , & V_74 ) ;
if ( ! V_49 ) {
F_6 ( V_7 -> V_7 , L_18 ) ;
goto V_38;
}
V_49 -> V_56 = V_2 ;
return;
V_38:
F_21 ( & V_7 -> V_72 ) ;
F_1 ( V_2 ) ;
F_23 ( & V_7 -> V_72 ) ;
}
int F_26 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_50 ;
struct V_17 * V_5 , * V_3 = NULL ;
struct V_75 * V_76 ;
int V_27 ;
if ( V_2 -> V_5 )
return 0 ;
V_2 -> V_5 = F_27 ( V_7 ) ;
V_2 -> V_3 = F_27 ( V_7 ) ;
V_3 = V_2 -> V_3 ;
V_5 = V_2 -> V_5 ;
if ( ! V_3 || ! V_5 ) {
V_27 = - V_29 ;
goto V_38;
}
V_76 = F_28 ( V_7 , & V_77 ) ;
if ( ! V_76 ) {
F_11 ( V_7 -> V_7 , L_19 ) ;
V_27 = - V_78 ;
goto V_38;
}
V_5 -> V_79 = V_76 -> V_80 ;
V_5 -> V_81 = V_76 -> V_82 . V_83 ;
V_27 = F_29 ( V_5 , V_84 ) ;
if ( V_27 )
goto V_38;
F_30 ( & V_5 -> V_4 , & V_7 -> V_85 ) ;
V_76 = F_28 ( V_7 , & V_73 ) ;
if ( ! V_76 ) {
F_11 ( V_7 -> V_7 , L_19 ) ;
V_27 = - V_78 ;
goto V_38;
}
V_3 -> V_79 = V_76 -> V_80 ;
V_3 -> V_81 = V_76 -> V_82 . V_83 ;
V_27 = F_29 ( V_3 , V_84 ) ;
if ( V_27 )
goto V_38;
F_30 ( & V_3 -> V_4 , & V_7 -> V_85 ) ;
V_2 -> V_61 = 1 ;
F_31 ( & V_2 -> V_71 , F_19 ) ;
F_32 ( & V_2 -> V_63 ) ;
F_33 ( & V_2 -> V_71 ) ;
return 0 ;
V_38:
F_1 ( V_2 ) ;
return V_27 ;
}
void F_34 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_50 ;
F_35 ( & V_2 -> V_71 ) ;
}
