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
F_11 ( V_2 , V_18 ) ;
F_12 ( & V_2 -> V_14 ) ;
}
static bool F_13 ( struct V_1 * V_2 ,
struct V_19 * V_11 ,
const char * V_20 )
{
if ( V_11 -> type != V_21 )
return false ;
if ( V_11 -> V_22 . V_23 && V_11 -> V_22 . V_24 )
return false ;
if ( V_20 )
F_14 ( V_2 , L_1 , V_20 ) ;
F_15 ( V_11 ) ;
return true ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_25 * V_26 )
{
F_2 ( & V_2 -> V_5 ) ;
F_17 ( V_2 , L_2 ,
F_18 ( V_26 -> V_27 ) ,
F_18 ( V_26 -> V_28 ) ) ;
if ( ! F_18 ( V_26 -> V_17 ) ) {
bool V_29 = F_18 ( V_26 -> V_28 ) &
V_30 ;
F_19 ( V_2 , L_3 ,
V_29 ? L_4 : L_5 ) ;
if ( F_13 ( V_2 , V_4 -> V_11 , NULL ) ) {
F_1 ( V_2 , V_4 ) ;
return;
}
}
if ( F_18 ( V_26 -> V_28 ) & V_31 ) {
F_17 ( V_2 ,
L_6 ,
V_32 , V_4 -> V_33 ) ;
if ( V_4 -> V_11 -> type == V_34 ) {
F_20 ( V_2 -> V_35 ) ;
F_9 ( V_2 ) ;
}
F_13 ( V_2 , V_4 -> V_11 ,
L_7 ) ;
F_1 ( V_2 , V_4 ) ;
} else if ( F_18 ( V_26 -> V_28 ) & V_30 ) {
V_4 -> V_9 = true ;
V_4 -> V_33 = F_21 ( V_4 -> V_36 ) ;
if ( V_4 -> V_11 -> type == V_34 ) {
F_22 ( V_16 , & V_2 -> V_17 ) ;
F_23 ( V_2 , V_18 ) ;
F_24 ( V_2 -> V_35 ) ;
}
} else {
F_19 ( V_2 , L_8 ) ;
}
}
int F_25 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_26 ( V_38 ) ;
struct V_25 * V_26 = ( void * ) V_42 -> V_43 ;
struct V_3 * V_4 , * V_44 ;
F_17 ( V_2 , L_9 ,
F_18 ( V_26 -> V_27 ) ,
F_18 ( V_26 -> V_28 ) ) ;
F_27 ( & V_2 -> V_5 ) ;
F_28 (te_data, tmp, &mvm->time_event_list, list) {
if ( F_18 ( V_26 -> V_27 ) == V_4 -> V_10 )
F_16 ( V_2 , V_4 , V_26 ) ;
}
F_29 ( & V_2 -> V_5 ) ;
return 0 ;
}
static bool F_30 ( struct V_45 * V_46 ,
struct V_41 * V_42 , void * V_43 )
{
struct V_1 * V_2 =
F_5 ( V_46 , struct V_1 , V_46 ) ;
struct V_3 * V_4 = V_43 ;
struct V_47 * V_48 ;
int V_49 = F_31 ( V_42 ) ;
if ( F_32 ( V_42 -> V_50 . V_40 != V_51 ) )
return true ;
if ( F_33 ( V_49 != sizeof( * V_48 ) ) ) {
F_14 ( V_2 , L_10 ) ;
return true ;
}
V_48 = ( void * ) V_42 -> V_43 ;
if ( F_33 ( F_18 ( V_48 -> V_6 ) != V_4 -> V_6 ) )
return false ;
V_4 -> V_10 = F_18 ( V_48 -> V_27 ) ;
F_17 ( V_2 , L_11 ,
V_4 -> V_10 ) ;
return true ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_19 * V_11 ,
struct V_3 * V_4 ,
struct V_52 * V_53 )
{
static const T_1 V_54 [] = { V_51 } ;
struct V_55 V_56 ;
int V_57 ;
F_2 ( & V_2 -> V_58 ) ;
F_17 ( V_2 , L_12 ,
F_18 ( V_53 -> V_36 ) ) ;
F_27 ( & V_2 -> V_5 ) ;
if ( F_32 ( V_4 -> V_6 != V_7 ) ) {
F_29 ( & V_2 -> V_5 ) ;
return - V_59 ;
}
V_4 -> V_11 = V_11 ;
V_4 -> V_36 = F_18 ( V_53 -> V_36 ) ;
V_4 -> V_6 = F_18 ( V_53 -> V_6 ) ;
F_35 ( & V_4 -> V_8 , & V_2 -> V_60 ) ;
F_29 ( & V_2 -> V_5 ) ;
F_36 ( & V_2 -> V_46 , & V_56 ,
V_54 ,
F_37 ( V_54 ) ,
F_30 , V_4 ) ;
V_57 = F_38 ( V_2 , V_51 , 0 ,
sizeof( * V_53 ) , V_53 ) ;
if ( V_57 ) {
F_14 ( V_2 , L_13 , V_57 ) ;
F_39 ( & V_2 -> V_46 , & V_56 ) ;
goto V_61;
}
V_57 = F_40 ( & V_2 -> V_46 , & V_56 , 1 ) ;
F_33 ( V_57 ) ;
if ( V_57 ) {
V_61:
F_27 ( & V_2 -> V_5 ) ;
F_1 ( V_2 , V_4 ) ;
F_29 ( & V_2 -> V_5 ) ;
}
return V_57 ;
}
void F_41 ( struct V_1 * V_2 ,
struct V_19 * V_11 ,
T_2 V_36 , T_2 V_62 ,
T_2 V_63 )
{
struct V_64 * V_65 = F_42 ( V_11 ) ;
struct V_3 * V_4 = & V_65 -> V_66 ;
struct V_52 V_67 = {} ;
F_2 ( & V_2 -> V_58 ) ;
if ( V_4 -> V_9 &&
F_43 ( V_4 -> V_33 , F_21 ( V_62 ) ) ) {
F_17 ( V_2 , L_14 ,
F_44 ( V_4 -> V_33 - V_32 ) ) ;
return;
}
if ( V_4 -> V_9 ) {
F_17 ( V_2 , L_15 ,
V_4 -> V_10 ,
F_44 ( V_4 -> V_33 - V_32 ) ) ;
F_45 ( V_2 , V_11 ) ;
}
V_67 . V_28 = F_46 ( V_68 ) ;
V_67 . V_69 =
F_46 ( F_47 ( V_65 -> V_6 , V_65 -> V_70 ) ) ;
V_67 . V_6 = F_46 ( V_71 ) ;
V_67 . V_72 =
F_46 ( F_48 ( V_2 -> V_73 , V_74 ) ) ;
V_67 . V_75 = V_76 ;
V_67 . V_63 = F_46 ( V_63 ) ;
V_67 . V_77 = F_46 ( 1 ) ;
V_67 . V_36 = F_46 ( V_36 ) ;
V_67 . V_78 = 1 ;
V_67 . V_79 = F_49 ( V_30 |
V_31 |
V_80 ) ;
F_34 ( V_2 , V_11 , V_4 , & V_67 ) ;
}
void F_50 ( struct V_1 * V_2 ,
struct V_64 * V_65 ,
struct V_3 * V_4 )
{
struct V_52 V_67 = {} ;
T_2 V_6 , V_10 ;
int V_57 ;
F_27 ( & V_2 -> V_5 ) ;
V_10 = V_4 -> V_10 ;
V_6 = V_4 -> V_6 ;
F_1 ( V_2 , V_4 ) ;
F_29 ( & V_2 -> V_5 ) ;
if ( V_6 == V_7 ) {
F_17 ( V_2 , L_16 , V_10 ) ;
return;
}
V_67 . V_6 = F_46 ( V_10 ) ;
V_67 . V_28 = F_46 ( V_81 ) ;
V_67 . V_69 =
F_46 ( F_47 ( V_65 -> V_6 , V_65 -> V_70 ) ) ;
F_17 ( V_2 , L_17 , F_18 ( V_67 . V_6 ) ) ;
V_57 = F_38 ( V_2 , V_51 , 0 ,
sizeof( V_67 ) , & V_67 ) ;
if ( F_32 ( V_57 ) )
return;
}
void F_45 ( struct V_1 * V_2 ,
struct V_19 * V_11 )
{
struct V_64 * V_65 = F_42 ( V_11 ) ;
struct V_3 * V_4 = & V_65 -> V_66 ;
F_2 ( & V_2 -> V_58 ) ;
F_50 ( V_2 , V_65 , V_4 ) ;
}
int F_51 ( struct V_1 * V_2 , struct V_19 * V_11 ,
int V_36 , enum V_82 type )
{
struct V_64 * V_65 = F_42 ( V_11 ) ;
struct V_3 * V_4 = & V_65 -> V_66 ;
struct V_52 V_67 = {} ;
F_2 ( & V_2 -> V_58 ) ;
if ( V_4 -> V_9 ) {
F_19 ( V_2 , L_18 ) ;
return - V_83 ;
}
F_52 ( & V_2 -> V_14 ) ;
V_67 . V_28 = F_46 ( V_68 ) ;
V_67 . V_69 =
F_46 ( F_47 ( V_65 -> V_6 , V_65 -> V_70 ) ) ;
switch ( type ) {
case V_84 :
V_67 . V_6 = F_46 ( V_85 ) ;
break;
case V_86 :
V_67 . V_6 = F_46 ( V_87 ) ;
break;
default:
F_53 ( 1 , L_19 ) ;
return - V_88 ;
}
V_67 . V_72 = F_46 ( 0 ) ;
V_67 . V_77 = F_46 ( 1 ) ;
V_67 . V_75 = F_54 ( F_55 ( V_36 ) / 50 , V_89 ) ;
V_67 . V_63 = F_46 ( F_55 ( V_36 / 2 ) ) ;
V_67 . V_36 = F_46 ( F_55 ( V_36 ) ) ;
V_67 . V_78 = 1 ;
V_67 . V_79 = F_49 ( V_30 |
V_31 |
V_80 ) ;
return F_34 ( V_2 , V_11 , V_4 , & V_67 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_58 ) ;
V_65 = NULL ;
F_27 ( & V_2 -> V_5 ) ;
F_57 (te_data, &mvm->time_event_list, list) {
if ( V_4 -> V_11 -> type == V_34 ) {
V_65 = F_42 ( V_4 -> V_11 ) ;
break;
}
}
F_29 ( & V_2 -> V_5 ) ;
if ( ! V_65 ) {
F_19 ( V_2 , L_20 ) ;
return;
}
F_50 ( V_2 , V_65 , V_4 ) ;
F_9 ( V_2 ) ;
}
