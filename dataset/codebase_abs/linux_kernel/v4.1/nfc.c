static void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
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
F_4 ( V_2 ) ;
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
struct V_1 * V_2 ;
int V_27 ;
V_2 = (struct V_1 * ) V_49 -> V_50 ;
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
V_2 = (struct V_1 * ) V_49 -> V_50 ;
V_7 = V_2 -> V_3 -> V_7 ;
V_38 = - V_29 ;
V_55 = F_8 ( V_52 + V_56 , V_28 ) ;
if ( ! V_55 )
goto V_57;
V_54 = (struct V_53 * ) V_55 ;
V_54 -> V_19 = V_58 ;
V_54 -> V_59 = 0 ;
V_54 -> V_60 = V_2 -> V_60 ;
V_54 -> V_61 = 0 ;
V_54 -> V_33 = V_52 ;
memcpy ( V_55 + V_56 , V_51 , V_52 ) ;
V_38 = F_9 ( V_2 -> V_3 , V_55 , V_52 + V_56 ) ;
if ( V_38 < 0 )
goto V_57;
if ( ! F_16 ( V_2 -> V_62 ,
V_2 -> V_63 == V_2 -> V_60 , V_64 ) ) {
F_6 ( V_7 -> V_7 , L_12 ) ;
V_38 = - V_65 ;
} else {
V_2 -> V_60 ++ ;
}
V_57:
F_4 ( V_55 ) ;
return V_38 ;
}
static int F_17 ( struct V_48 * V_49 , V_37 * V_51 , T_1 V_52 )
{
struct V_1 * V_2 ;
struct V_53 * V_66 ;
int V_67 ;
V_2 = (struct V_1 * ) V_49 -> V_50 ;
V_67 = F_10 ( V_2 -> V_3 , V_51 , V_52 ) ;
if ( V_67 < 0 )
return V_67 ;
V_66 = (struct V_53 * ) V_51 ;
if ( V_66 -> V_19 == V_58 ) {
V_2 -> V_63 = V_66 -> V_60 ;
F_18 ( & V_2 -> V_62 ) ;
return 0 ;
}
return V_67 ;
}
static void F_19 ( struct V_68 * V_69 )
{
struct V_6 * V_7 ;
struct V_48 * V_49 ;
struct V_1 * V_2 ;
struct V_17 * V_5 ;
V_2 = F_20 ( V_69 , struct V_1 , V_70 ) ;
V_5 = V_2 -> V_5 ;
V_7 = V_5 -> V_7 ;
F_21 ( & V_7 -> V_71 ) ;
if ( F_22 ( V_5 , NULL ) < 0 ) {
F_23 ( & V_7 -> V_71 ) ;
F_6 ( V_7 -> V_7 , L_13 ) ;
goto V_38;
}
F_23 ( & V_7 -> V_71 ) ;
if ( F_12 ( V_2 ) < 0 ) {
F_6 ( V_7 -> V_7 , L_14 ) ;
goto V_38;
}
F_11 ( V_7 -> V_7 , L_15 ,
V_2 -> V_36 , V_2 -> V_9 , V_2 -> V_11 ) ;
F_21 ( & V_7 -> V_71 ) ;
if ( F_24 ( V_5 ) < 0 ) {
F_23 ( & V_7 -> V_71 ) ;
F_6 ( V_7 -> V_7 , L_16 ) ;
goto V_38;
}
F_23 ( & V_7 -> V_71 ) ;
if ( F_5 ( V_2 ) < 0 ) {
F_6 ( V_7 -> V_7 , L_17 ) ;
return;
}
V_49 = F_25 ( V_7 , V_72 , V_2 -> V_13 , & V_73 ) ;
if ( ! V_49 ) {
F_6 ( V_7 -> V_7 , L_18 ) ;
goto V_38;
}
V_49 -> V_50 = V_2 ;
return;
V_38:
F_21 ( & V_7 -> V_71 ) ;
F_1 ( V_2 ) ;
F_23 ( & V_7 -> V_71 ) ;
}
int F_26 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
struct V_17 * V_5 , * V_3 ;
struct V_74 * V_75 = NULL ;
int V_27 ;
V_3 = F_27 ( V_7 , V_72 ) ;
if ( V_3 )
return 0 ;
V_2 = F_8 ( sizeof( struct V_1 ) , V_28 ) ;
if ( ! V_2 ) {
V_27 = - V_29 ;
goto V_38;
}
V_75 = F_28 ( V_7 , & V_76 ) ;
if ( ! V_75 ) {
F_11 ( V_7 -> V_7 , L_19 ) ;
V_27 = - V_77 ;
goto V_38;
}
V_5 = F_29 ( V_7 , V_78 ) ;
if ( F_30 ( V_5 ) ) {
V_27 = F_31 ( V_5 ) ;
goto V_38;
}
V_5 -> V_79 = V_75 -> V_80 ;
V_5 -> V_81 = V_75 -> V_82 . V_83 ;
F_32 ( V_75 ) ;
V_75 = NULL ;
F_33 ( & V_5 -> V_4 , & V_7 -> V_84 ) ;
V_2 -> V_5 = V_5 ;
V_75 = F_28 ( V_7 , & V_72 ) ;
if ( ! V_75 ) {
F_11 ( V_7 -> V_7 , L_19 ) ;
V_27 = - V_77 ;
goto V_38;
}
V_3 = F_29 ( V_7 , V_78 ) ;
if ( F_30 ( V_3 ) ) {
V_27 = F_31 ( V_3 ) ;
goto V_38;
}
V_3 -> V_79 = V_75 -> V_80 ;
V_3 -> V_81 = V_75 -> V_82 . V_83 ;
F_32 ( V_75 ) ;
V_75 = NULL ;
F_33 ( & V_3 -> V_4 , & V_7 -> V_84 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_60 = 1 ;
F_34 ( & V_2 -> V_70 , F_19 ) ;
F_35 ( & V_2 -> V_62 ) ;
F_36 ( & V_2 -> V_70 ) ;
return 0 ;
V_38:
F_32 ( V_75 ) ;
F_1 ( V_2 ) ;
return V_27 ;
}
void F_37 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
struct V_17 * V_3 ;
struct V_48 * V_49 ;
V_3 = F_27 ( V_7 , V_72 ) ;
if ( ! V_3 )
return;
V_49 = V_3 -> V_85 ;
if ( ! V_49 )
return;
V_2 = (struct V_1 * ) V_49 -> V_50 ;
if ( V_2 )
F_38 ( & V_2 -> V_70 ) ;
V_49 -> V_50 = NULL ;
F_21 ( & V_7 -> V_71 ) ;
F_39 ( V_49 ) ;
F_1 ( V_2 ) ;
F_23 ( & V_7 -> V_71 ) ;
}
