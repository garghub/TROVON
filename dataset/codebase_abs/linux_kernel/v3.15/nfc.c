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
F_6 ( & V_7 -> V_14 -> V_7 , L_2 ,
V_2 -> V_11 ) ;
return - V_15 ;
}
case V_16 :
switch ( V_2 -> V_11 ) {
case V_17 :
V_2 -> V_13 = L_3 ;
return 0 ;
default:
F_6 ( & V_7 -> V_14 -> V_7 , L_2 ,
V_2 -> V_11 ) ;
return - V_15 ;
}
default:
F_6 ( & V_7 -> V_14 -> V_7 , L_4 ,
V_2 -> V_9 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_18 * V_3 ;
struct V_19 * V_20 , * V_21 ;
struct F_7 * V_22 ;
struct V_23 * V_24 ;
T_1 V_25 , V_26 ;
int V_27 , V_28 ;
V_3 = V_2 -> V_3 ;
V_7 = V_3 -> V_7 ;
V_25 = sizeof( struct V_19 ) +
sizeof( struct F_7 ) ;
V_26 = sizeof( struct V_19 ) +
sizeof( struct V_23 ) ;
V_20 = F_8 ( V_25 , V_29 ) ;
if ( ! V_20 )
return - V_30 ;
V_22 = (struct F_7 * ) V_20 -> V_31 ;
V_21 = F_8 ( V_26 , V_29 ) ;
if ( ! V_21 ) {
F_4 ( V_20 ) ;
return - V_30 ;
}
V_24 = (struct V_23 * ) V_21 -> V_31 ;
V_20 -> V_32 = V_33 ;
V_20 -> V_34 = 3 ;
V_20 -> V_35 = V_36 ;
V_22 -> V_37 = V_2 -> V_37 ;
V_22 -> V_9 = V_2 -> V_9 ;
V_28 = F_9 ( V_3 , ( V_38 * ) V_20 , V_25 ) ;
if ( V_28 < 0 ) {
F_6 ( & V_7 -> V_14 -> V_7 , L_5 ) ;
goto V_39;
}
V_27 = F_10 ( V_3 , ( V_38 * ) V_21 , V_26 ) ;
if ( V_27 < 0 ) {
F_6 ( & V_7 -> V_14 -> V_7 , L_6 ) ;
V_28 = V_27 ;
goto V_39;
}
F_11 ( & V_7 -> V_14 -> V_7 , L_7 ,
V_24 -> V_37 , V_24 -> V_9 ) ;
F_11 ( & V_7 -> V_14 -> V_7 , L_8 ,
V_24 -> V_40 , V_24 -> V_41 ,
V_24 -> V_42 , V_24 -> V_43 ) ;
V_28 = 0 ;
V_39:
F_4 ( V_21 ) ;
F_4 ( V_20 ) ;
return V_28 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_18 * V_3 ;
struct V_19 V_20 ;
struct V_44 * V_21 = NULL ;
struct F_12 * V_45 ;
T_1 V_46 ;
int V_27 , V_28 ;
V_3 = V_2 -> V_5 ;
V_7 = V_3 -> V_7 ;
memset ( & V_20 , 0 , sizeof( struct V_19 ) ) ;
V_20 . V_32 = V_33 ;
V_20 . V_34 = 1 ;
V_20 . V_35 = V_47 ;
V_28 = F_9 ( V_3 , ( V_38 * ) & V_20 , sizeof( struct V_19 ) ) ;
if ( V_28 < 0 ) {
F_6 ( & V_7 -> V_14 -> V_7 , L_9 ) ;
return V_28 ;
}
V_46 = sizeof( struct V_44 ) +
sizeof( struct F_12 ) ;
V_21 = F_8 ( V_46 , V_29 ) ;
if ( ! V_21 )
return - V_30 ;
V_27 = F_10 ( V_3 , ( V_38 * ) V_21 , V_46 ) ;
if ( V_27 < 0 || V_27 < sizeof( struct V_44 ) ) {
F_6 ( & V_7 -> V_14 -> V_7 , L_10 ) ;
V_28 = - V_48 ;
goto V_39;
}
V_45 = (struct F_12 * ) V_21 -> V_31 ;
V_2 -> V_37 = V_45 -> V_37 ;
V_2 -> V_9 = V_45 -> V_9 ;
V_2 -> V_11 = V_45 -> V_11 ;
V_39:
F_4 ( V_21 ) ;
return V_28 ;
}
static int F_13 ( struct V_49 * V_50 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 = & V_51 ;
int V_28 ;
V_7 = V_2 -> V_3 -> V_7 ;
V_28 = F_7 ( V_2 ) ;
if ( V_28 < 0 ) {
F_6 ( & V_7 -> V_14 -> V_7 , L_11 ) ;
return V_28 ;
}
return 0 ;
}
static int F_14 ( struct V_49 * V_50 )
{
return 0 ;
}
static int F_15 ( struct V_49 * V_50 , V_38 * V_52 , T_1 V_53 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_54 * V_55 ;
V_38 * V_56 ;
int V_39 ;
V_2 = (struct V_1 * ) V_50 -> V_57 ;
V_7 = V_2 -> V_3 -> V_7 ;
V_56 = F_8 ( V_53 + V_58 , V_29 ) ;
if ( ! V_56 )
return - V_30 ;
V_55 = (struct V_54 * ) V_56 ;
V_55 -> V_20 = V_59 ;
V_55 -> V_60 = 0 ;
V_55 -> V_61 = V_2 -> V_61 ;
V_55 -> V_62 = 0 ;
V_55 -> V_34 = V_53 ;
memcpy ( V_56 + V_58 , V_52 , V_53 ) ;
V_39 = F_9 ( V_2 -> V_3 , V_56 , V_53 + V_58 ) ;
if ( V_39 < 0 )
return V_39 ;
F_4 ( V_56 ) ;
if ( ! F_16 ( V_2 -> V_63 ,
V_2 -> V_64 == V_2 -> V_61 , V_65 ) ) {
F_6 ( & V_7 -> V_14 -> V_7 , L_12 ) ;
V_39 = - V_66 ;
} else {
V_2 -> V_61 ++ ;
}
return V_39 ;
}
static int F_17 ( struct V_49 * V_50 , V_38 * V_52 , T_1 V_53 )
{
struct V_1 * V_2 ;
struct V_54 * V_67 ;
int V_68 ;
V_2 = (struct V_1 * ) V_50 -> V_57 ;
V_68 = F_10 ( V_2 -> V_3 , V_52 , V_53 ) ;
if ( V_68 < 0 )
return V_68 ;
V_67 = (struct V_54 * ) V_52 ;
if ( V_67 -> V_20 == V_59 ) {
V_2 -> V_64 = V_67 -> V_61 ;
F_18 ( & V_2 -> V_63 ) ;
return 0 ;
}
return V_68 ;
}
static void F_19 ( struct V_69 * V_70 )
{
struct V_6 * V_7 ;
struct V_49 * V_50 ;
struct V_1 * V_2 ;
struct V_18 * V_5 ;
V_2 = F_20 ( V_70 , struct V_1 , V_71 ) ;
V_5 = V_2 -> V_5 ;
V_7 = V_5 -> V_7 ;
F_21 ( & V_7 -> V_72 ) ;
if ( F_22 ( V_5 , NULL ) < 0 ) {
F_23 ( & V_7 -> V_72 ) ;
F_6 ( & V_7 -> V_14 -> V_7 ,
L_13 ) ;
goto V_39;
}
F_23 ( & V_7 -> V_72 ) ;
if ( F_12 ( V_2 ) < 0 ) {
F_6 ( & V_7 -> V_14 -> V_7 , L_14 ) ;
goto V_39;
}
F_11 ( & V_7 -> V_14 -> V_7 ,
L_15 ,
V_2 -> V_37 , V_2 -> V_9 , V_2 -> V_11 ) ;
F_21 ( & V_7 -> V_72 ) ;
if ( F_24 ( V_5 ) < 0 ) {
F_23 ( & V_7 -> V_72 ) ;
F_6 ( & V_7 -> V_14 -> V_7 ,
L_16 ) ;
goto V_39;
}
F_23 ( & V_7 -> V_72 ) ;
if ( F_5 ( V_2 ) < 0 ) {
F_6 ( & V_7 -> V_14 -> V_7 ,
L_17 ) ;
return;
}
V_50 = F_25 ( V_7 , V_73 , V_2 -> V_13 , & V_74 ) ;
if ( ! V_50 ) {
F_6 ( & V_7 -> V_14 -> V_7 ,
L_18 ) ;
goto V_39;
}
V_50 -> V_57 = V_2 ;
return;
V_39:
F_21 ( & V_7 -> V_72 ) ;
F_1 ( V_2 ) ;
F_23 ( & V_7 -> V_72 ) ;
return;
}
int F_26 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_51 ;
struct V_18 * V_5 , * V_3 = NULL ;
int V_75 , V_28 ;
if ( V_2 -> V_5 )
return 0 ;
V_2 -> V_5 = F_27 ( V_7 ) ;
V_2 -> V_3 = F_27 ( V_7 ) ;
V_3 = V_2 -> V_3 ;
V_5 = V_2 -> V_5 ;
if ( ! V_3 || ! V_5 ) {
V_28 = - V_30 ;
goto V_39;
}
V_75 = F_28 ( V_7 , & V_76 ) ;
if ( V_75 < 0 ) {
F_11 ( & V_7 -> V_14 -> V_7 , L_19 ) ;
V_28 = - V_77 ;
goto V_39;
}
V_5 -> V_78 = V_7 -> V_79 [ V_75 ] . V_80 ;
V_28 = F_29 ( V_5 , V_81 ) ;
if ( V_28 )
goto V_39;
V_5 -> V_82 = V_76 ;
F_30 ( & V_5 -> V_4 , & V_7 -> V_83 ) ;
V_75 = F_28 ( V_7 , & V_73 ) ;
if ( V_75 < 0 ) {
F_11 ( & V_7 -> V_14 -> V_7 , L_19 ) ;
V_28 = - V_77 ;
goto V_39;
}
V_3 -> V_78 = V_7 -> V_79 [ V_75 ] . V_80 ;
V_28 = F_29 ( V_3 , V_81 ) ;
if ( V_28 )
goto V_39;
V_3 -> V_82 = V_73 ;
F_30 ( & V_3 -> V_4 , & V_7 -> V_83 ) ;
V_2 -> V_61 = 1 ;
F_31 ( & V_2 -> V_71 , F_19 ) ;
F_32 ( & V_2 -> V_63 ) ;
F_33 ( & V_2 -> V_71 ) ;
return 0 ;
V_39:
F_1 ( V_2 ) ;
return V_28 ;
}
void F_34 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_51 ;
F_35 ( & V_2 -> V_71 ) ;
}
