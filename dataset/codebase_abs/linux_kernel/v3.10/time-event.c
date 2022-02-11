void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_5 ) ;
if ( V_4 -> V_6 == V_7 )
return;
F_3 ( & V_4 -> V_8 ) ;
V_4 -> V_9 = false ;
V_4 -> V_10 = 0 ;
V_4 -> V_6 = V_7 ;
V_4 -> V_11 = NULL ;
}
void F_4 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_5 ( V_13 , struct V_1 , V_14 ) ;
F_6 () ;
F_7 ( V_2 , F_8 ( V_15 ) , false ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_16 , & V_2 -> V_17 ) ;
F_11 ( & V_2 -> V_14 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_18 * V_19 )
{
F_2 ( & V_2 -> V_5 ) ;
F_13 ( V_2 , L_1 ,
F_14 ( V_19 -> V_20 ) ,
F_14 ( V_19 -> V_21 ) ) ;
F_15 ( ! F_14 ( V_19 -> V_17 ) ,
L_2 ) ;
if ( F_14 ( V_19 -> V_21 ) & V_22 ) {
F_13 ( V_2 ,
L_3 ,
V_23 , V_4 -> V_24 ) ;
if ( V_4 -> V_11 -> type == V_25 ) {
F_16 ( V_2 -> V_26 ) ;
F_9 ( V_2 ) ;
}
if ( V_4 -> V_11 -> type == V_27 &&
( ! V_4 -> V_11 -> V_28 . V_29 ||
! V_4 -> V_11 -> V_28 . V_30 ) ) {
F_17 ( V_2 ,
L_4 ) ;
F_18 ( V_4 -> V_11 ) ;
}
F_1 ( V_2 , V_4 ) ;
} else if ( F_14 ( V_19 -> V_21 ) & V_31 ) {
V_4 -> V_9 = true ;
V_4 -> V_24 = V_23 +
F_19 ( V_4 -> V_32 ) ;
if ( V_4 -> V_11 -> type == V_25 ) {
F_20 ( V_16 , & V_2 -> V_17 ) ;
F_21 ( V_2 -> V_26 ) ;
}
} else {
F_22 ( V_2 , L_5 ) ;
}
}
int F_23 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = F_24 ( V_34 ) ;
struct V_18 * V_19 = ( void * ) V_38 -> V_39 ;
struct V_3 * V_4 , * V_40 ;
F_13 ( V_2 , L_6 ,
F_14 ( V_19 -> V_20 ) ,
F_14 ( V_19 -> V_21 ) ) ;
F_25 ( & V_2 -> V_5 ) ;
F_26 (te_data, tmp, &mvm->time_event_list, list) {
if ( F_14 ( V_19 -> V_20 ) == V_4 -> V_10 )
F_12 ( V_2 , V_4 , V_19 ) ;
}
F_27 ( & V_2 -> V_5 ) ;
return 0 ;
}
static bool F_28 ( struct V_41 * V_42 ,
struct V_37 * V_38 , void * V_39 )
{
struct V_1 * V_2 =
F_5 ( V_42 , struct V_1 , V_42 ) ;
struct V_3 * V_4 = V_39 ;
struct V_43 * V_44 ;
int V_45 = F_14 ( V_38 -> V_46 ) & V_47 ;
if ( F_29 ( V_38 -> V_48 . V_36 != V_49 ) )
return true ;
if ( F_30 ( V_45 != sizeof( V_38 -> V_48 ) + sizeof( * V_44 ) ) ) {
F_17 ( V_2 , L_7 ) ;
return true ;
}
V_44 = ( void * ) V_38 -> V_39 ;
if ( F_30 ( F_14 ( V_44 -> V_6 ) != V_4 -> V_6 ) )
return false ;
V_4 -> V_10 = F_14 ( V_44 -> V_20 ) ;
F_13 ( V_2 , L_8 ,
V_4 -> V_10 ) ;
return true ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_50 * V_11 ,
struct V_3 * V_4 ,
struct V_51 * V_52 )
{
static const T_1 V_53 [] = { V_49 } ;
struct V_54 V_55 ;
int V_56 ;
F_2 ( & V_2 -> V_57 ) ;
F_13 ( V_2 , L_9 ,
F_14 ( V_52 -> V_32 ) ) ;
F_25 ( & V_2 -> V_5 ) ;
if ( F_29 ( V_4 -> V_6 != V_7 ) ) {
F_27 ( & V_2 -> V_5 ) ;
return - V_58 ;
}
V_4 -> V_11 = V_11 ;
V_4 -> V_32 = F_14 ( V_52 -> V_32 ) ;
V_4 -> V_6 = F_14 ( V_52 -> V_6 ) ;
F_32 ( & V_4 -> V_8 , & V_2 -> V_59 ) ;
F_27 ( & V_2 -> V_5 ) ;
F_33 ( & V_2 -> V_42 , & V_55 ,
V_53 ,
F_34 ( V_53 ) ,
F_28 , V_4 ) ;
V_56 = F_35 ( V_2 , V_49 , V_60 ,
sizeof( * V_52 ) , V_52 ) ;
if ( V_56 ) {
F_17 ( V_2 , L_10 , V_56 ) ;
F_36 ( & V_2 -> V_42 , & V_55 ) ;
goto V_61;
}
V_56 = F_37 ( & V_2 -> V_42 , & V_55 , 1 ) ;
F_30 ( V_56 ) ;
if ( V_56 ) {
V_61:
F_25 ( & V_2 -> V_5 ) ;
F_1 ( V_2 , V_4 ) ;
F_27 ( & V_2 -> V_5 ) ;
}
return V_56 ;
}
void F_38 ( struct V_1 * V_2 ,
struct V_50 * V_11 ,
T_2 V_32 , T_2 V_62 )
{
struct V_63 * V_64 = F_39 ( V_11 ) ;
struct V_3 * V_4 = & V_64 -> V_65 ;
struct V_51 V_66 = {} ;
F_2 ( & V_2 -> V_57 ) ;
if ( V_4 -> V_9 &&
F_40 ( V_4 -> V_24 ,
V_23 + F_19 ( V_62 ) ) ) {
F_13 ( V_2 , L_11 ,
F_41 ( V_4 -> V_24 - V_23 ) ) ;
return;
}
if ( V_4 -> V_9 ) {
F_13 ( V_2 , L_12 ,
V_4 -> V_10 ,
F_41 ( V_4 -> V_24 - V_23 ) ) ;
F_42 ( V_2 , V_11 ) ;
}
V_66 . V_21 = F_43 ( V_67 ) ;
V_66 . V_68 =
F_43 ( F_44 ( V_64 -> V_6 , V_64 -> V_69 ) ) ;
V_66 . V_6 = F_43 ( V_70 ) ;
V_66 . V_71 =
F_43 ( F_45 ( V_2 -> V_72 , V_73 ) ) ;
V_66 . V_74 = V_75 ;
V_66 . V_76 = F_43 ( 1 ) ;
V_66 . V_77 = F_43 ( V_78 ) ;
V_66 . V_79 = F_43 ( 500 ) ;
V_66 . V_80 = F_43 ( 1 ) ;
V_66 . V_81 = F_43 ( F_46 ( 1 ) ) ;
V_66 . V_32 = F_43 ( V_32 ) ;
V_66 . V_82 = F_43 ( 1 ) ;
V_66 . V_83 = F_43 ( V_31 |
V_22 ) ;
F_31 ( V_2 , V_11 , V_4 , & V_66 ) ;
}
void F_47 ( struct V_1 * V_2 ,
struct V_63 * V_64 ,
struct V_3 * V_4 )
{
struct V_51 V_66 = {} ;
T_2 V_6 , V_10 ;
int V_56 ;
F_25 ( & V_2 -> V_5 ) ;
V_10 = V_4 -> V_10 ;
V_6 = V_4 -> V_6 ;
F_1 ( V_2 , V_4 ) ;
F_27 ( & V_2 -> V_5 ) ;
if ( V_6 == V_7 ) {
F_13 ( V_2 , L_13 , V_10 ) ;
return;
}
V_66 . V_6 = F_43 ( V_10 ) ;
V_66 . V_21 = F_43 ( V_84 ) ;
V_66 . V_68 =
F_43 ( F_44 ( V_64 -> V_6 , V_64 -> V_69 ) ) ;
F_13 ( V_2 , L_14 , F_14 ( V_66 . V_6 ) ) ;
V_56 = F_35 ( V_2 , V_49 , V_60 ,
sizeof( V_66 ) , & V_66 ) ;
if ( F_29 ( V_56 ) )
return;
}
void F_42 ( struct V_1 * V_2 ,
struct V_50 * V_11 )
{
struct V_63 * V_64 = F_39 ( V_11 ) ;
struct V_3 * V_4 = & V_64 -> V_65 ;
F_2 ( & V_2 -> V_57 ) ;
F_47 ( V_2 , V_64 , V_4 ) ;
}
int F_48 ( struct V_1 * V_2 , struct V_50 * V_11 ,
int V_32 , enum V_85 type )
{
struct V_63 * V_64 = F_39 ( V_11 ) ;
struct V_3 * V_4 = & V_64 -> V_65 ;
struct V_51 V_66 = {} ;
F_2 ( & V_2 -> V_57 ) ;
if ( V_4 -> V_9 ) {
F_22 ( V_2 , L_15 ) ;
return - V_86 ;
}
F_49 ( & V_2 -> V_14 ) ;
V_66 . V_21 = F_43 ( V_67 ) ;
V_66 . V_68 =
F_43 ( F_44 ( V_64 -> V_6 , V_64 -> V_69 ) ) ;
switch ( type ) {
case V_87 :
V_66 . V_6 = F_43 ( V_88 ) ;
break;
case V_89 :
V_66 . V_6 = F_43 ( V_90 ) ;
break;
default:
F_15 ( 1 , L_16 ) ;
return - V_91 ;
}
V_66 . V_71 = F_43 ( 0 ) ;
V_66 . V_74 = F_43 ( V_75 ) ;
V_66 . V_76 = F_43 ( 1 ) ;
V_66 . V_80 = F_43 ( 1 ) ;
V_66 . V_77 = F_43 ( F_50 ( V_32 ) / 20 ) ;
V_66 . V_79 = F_43 ( F_50 ( V_32 / 2 ) ) ;
V_66 . V_32 = F_43 ( F_50 ( V_32 ) ) ;
V_66 . V_82 = F_43 ( 1 ) ;
V_66 . V_83 = F_43 ( V_31 |
V_22 ) ;
return F_31 ( V_2 , V_11 , V_4 , & V_66 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_57 ) ;
V_64 = NULL ;
F_25 ( & V_2 -> V_5 ) ;
F_52 (te_data, &mvm->time_event_list, list) {
if ( V_4 -> V_11 -> type == V_25 ) {
V_64 = F_39 ( V_4 -> V_11 ) ;
break;
}
}
F_27 ( & V_2 -> V_5 ) ;
if ( ! V_64 ) {
F_22 ( V_2 , L_17 ) ;
return;
}
F_47 ( V_2 , V_64 , V_4 ) ;
F_9 ( V_2 ) ;
}
