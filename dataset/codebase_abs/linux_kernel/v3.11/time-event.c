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
static bool F_12 ( struct V_1 * V_2 ,
struct V_18 * V_11 ,
const char * V_19 )
{
if ( V_11 -> type != V_20 )
return false ;
if ( V_11 -> V_21 . V_22 && V_11 -> V_21 . V_23 )
return false ;
if ( V_19 )
F_13 ( V_2 , L_1 , V_19 ) ;
F_14 ( V_11 ) ;
return true ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_24 * V_25 )
{
F_2 ( & V_2 -> V_5 ) ;
F_16 ( V_2 , L_2 ,
F_17 ( V_25 -> V_26 ) ,
F_17 ( V_25 -> V_27 ) ) ;
if ( F_18 ( ! F_17 ( V_25 -> V_17 ) ,
L_3 ) ) {
if ( F_12 ( V_2 , V_4 -> V_11 , NULL ) ) {
F_1 ( V_2 , V_4 ) ;
return;
}
}
if ( F_17 ( V_25 -> V_27 ) & V_28 ) {
F_16 ( V_2 ,
L_4 ,
V_29 , V_4 -> V_30 ) ;
if ( V_4 -> V_11 -> type == V_31 ) {
F_19 ( V_2 -> V_32 ) ;
F_9 ( V_2 ) ;
}
F_12 ( V_2 , V_4 -> V_11 ,
L_5 ) ;
F_1 ( V_2 , V_4 ) ;
} else if ( F_17 ( V_25 -> V_27 ) & V_33 ) {
V_4 -> V_9 = true ;
V_4 -> V_30 = V_29 +
F_20 ( V_4 -> V_34 ) ;
if ( V_4 -> V_11 -> type == V_31 ) {
F_21 ( V_16 , & V_2 -> V_17 ) ;
F_22 ( V_2 -> V_32 ) ;
}
} else {
F_23 ( V_2 , L_6 ) ;
}
}
int F_24 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = F_25 ( V_36 ) ;
struct V_24 * V_25 = ( void * ) V_40 -> V_41 ;
struct V_3 * V_4 , * V_42 ;
F_16 ( V_2 , L_7 ,
F_17 ( V_25 -> V_26 ) ,
F_17 ( V_25 -> V_27 ) ) ;
F_26 ( & V_2 -> V_5 ) ;
F_27 (te_data, tmp, &mvm->time_event_list, list) {
if ( F_17 ( V_25 -> V_26 ) == V_4 -> V_10 )
F_15 ( V_2 , V_4 , V_25 ) ;
}
F_28 ( & V_2 -> V_5 ) ;
return 0 ;
}
static bool F_29 ( struct V_43 * V_44 ,
struct V_39 * V_40 , void * V_41 )
{
struct V_1 * V_2 =
F_5 ( V_44 , struct V_1 , V_44 ) ;
struct V_3 * V_4 = V_41 ;
struct V_45 * V_46 ;
int V_47 = F_17 ( V_40 -> V_48 ) & V_49 ;
if ( F_30 ( V_40 -> V_50 . V_38 != V_51 ) )
return true ;
if ( F_31 ( V_47 != sizeof( V_40 -> V_50 ) + sizeof( * V_46 ) ) ) {
F_13 ( V_2 , L_8 ) ;
return true ;
}
V_46 = ( void * ) V_40 -> V_41 ;
if ( F_31 ( F_17 ( V_46 -> V_6 ) != V_4 -> V_6 ) )
return false ;
V_4 -> V_10 = F_17 ( V_46 -> V_26 ) ;
F_16 ( V_2 , L_9 ,
V_4 -> V_10 ) ;
return true ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_18 * V_11 ,
struct V_3 * V_4 ,
struct V_52 * V_53 )
{
static const T_1 V_54 [] = { V_51 } ;
struct V_55 V_56 ;
int V_57 ;
F_2 ( & V_2 -> V_58 ) ;
F_16 ( V_2 , L_10 ,
F_17 ( V_53 -> V_34 ) ) ;
F_26 ( & V_2 -> V_5 ) ;
if ( F_30 ( V_4 -> V_6 != V_7 ) ) {
F_28 ( & V_2 -> V_5 ) ;
return - V_59 ;
}
V_4 -> V_11 = V_11 ;
V_4 -> V_34 = F_17 ( V_53 -> V_34 ) ;
V_4 -> V_6 = F_17 ( V_53 -> V_6 ) ;
F_33 ( & V_4 -> V_8 , & V_2 -> V_60 ) ;
F_28 ( & V_2 -> V_5 ) ;
F_34 ( & V_2 -> V_44 , & V_56 ,
V_54 ,
F_35 ( V_54 ) ,
F_29 , V_4 ) ;
V_57 = F_36 ( V_2 , V_51 , V_61 ,
sizeof( * V_53 ) , V_53 ) ;
if ( V_57 ) {
F_13 ( V_2 , L_11 , V_57 ) ;
F_37 ( & V_2 -> V_44 , & V_56 ) ;
goto V_62;
}
V_57 = F_38 ( & V_2 -> V_44 , & V_56 , 1 ) ;
F_31 ( V_57 ) ;
if ( V_57 ) {
V_62:
F_26 ( & V_2 -> V_5 ) ;
F_1 ( V_2 , V_4 ) ;
F_28 ( & V_2 -> V_5 ) ;
}
return V_57 ;
}
void F_39 ( struct V_1 * V_2 ,
struct V_18 * V_11 ,
T_2 V_34 , T_2 V_63 )
{
struct V_64 * V_65 = F_40 ( V_11 ) ;
struct V_3 * V_4 = & V_65 -> V_66 ;
struct V_52 V_67 = {} ;
F_2 ( & V_2 -> V_58 ) ;
if ( V_4 -> V_9 &&
F_41 ( V_4 -> V_30 ,
V_29 + F_20 ( V_63 ) ) ) {
F_16 ( V_2 , L_12 ,
F_42 ( V_4 -> V_30 - V_29 ) ) ;
return;
}
if ( V_4 -> V_9 ) {
F_16 ( V_2 , L_13 ,
V_4 -> V_10 ,
F_42 ( V_4 -> V_30 - V_29 ) ) ;
F_43 ( V_2 , V_11 ) ;
}
V_67 . V_27 = F_44 ( V_68 ) ;
V_67 . V_69 =
F_44 ( F_45 ( V_65 -> V_6 , V_65 -> V_70 ) ) ;
V_67 . V_6 = F_44 ( V_71 ) ;
V_67 . V_72 =
F_44 ( F_46 ( V_2 -> V_73 , V_74 ) ) ;
V_67 . V_75 = V_76 ;
V_67 . V_77 = F_44 ( 1 ) ;
V_67 . V_78 = F_44 ( V_79 ) ;
V_67 . V_80 = F_44 ( 500 ) ;
V_67 . V_81 = F_44 ( 1 ) ;
V_67 . V_82 = F_44 ( F_47 ( 1 ) ) ;
V_67 . V_34 = F_44 ( V_34 ) ;
V_67 . V_83 = F_44 ( 1 ) ;
V_67 . V_84 = F_44 ( V_33 |
V_28 ) ;
F_32 ( V_2 , V_11 , V_4 , & V_67 ) ;
}
void F_48 ( struct V_1 * V_2 ,
struct V_64 * V_65 ,
struct V_3 * V_4 )
{
struct V_52 V_67 = {} ;
T_2 V_6 , V_10 ;
int V_57 ;
F_26 ( & V_2 -> V_5 ) ;
V_10 = V_4 -> V_10 ;
V_6 = V_4 -> V_6 ;
F_1 ( V_2 , V_4 ) ;
F_28 ( & V_2 -> V_5 ) ;
if ( V_6 == V_7 ) {
F_16 ( V_2 , L_14 , V_10 ) ;
return;
}
V_67 . V_6 = F_44 ( V_10 ) ;
V_67 . V_27 = F_44 ( V_85 ) ;
V_67 . V_69 =
F_44 ( F_45 ( V_65 -> V_6 , V_65 -> V_70 ) ) ;
F_16 ( V_2 , L_15 , F_17 ( V_67 . V_6 ) ) ;
V_57 = F_36 ( V_2 , V_51 , V_61 ,
sizeof( V_67 ) , & V_67 ) ;
if ( F_30 ( V_57 ) )
return;
}
void F_43 ( struct V_1 * V_2 ,
struct V_18 * V_11 )
{
struct V_64 * V_65 = F_40 ( V_11 ) ;
struct V_3 * V_4 = & V_65 -> V_66 ;
F_2 ( & V_2 -> V_58 ) ;
F_48 ( V_2 , V_65 , V_4 ) ;
}
int F_49 ( struct V_1 * V_2 , struct V_18 * V_11 ,
int V_34 , enum V_86 type )
{
struct V_64 * V_65 = F_40 ( V_11 ) ;
struct V_3 * V_4 = & V_65 -> V_66 ;
struct V_52 V_67 = {} ;
F_2 ( & V_2 -> V_58 ) ;
if ( V_4 -> V_9 ) {
F_23 ( V_2 , L_16 ) ;
return - V_87 ;
}
F_50 ( & V_2 -> V_14 ) ;
V_67 . V_27 = F_44 ( V_68 ) ;
V_67 . V_69 =
F_44 ( F_45 ( V_65 -> V_6 , V_65 -> V_70 ) ) ;
switch ( type ) {
case V_88 :
V_67 . V_6 = F_44 ( V_89 ) ;
break;
case V_90 :
V_67 . V_6 = F_44 ( V_91 ) ;
break;
default:
F_18 ( 1 , L_17 ) ;
return - V_92 ;
}
V_67 . V_72 = F_44 ( 0 ) ;
V_67 . V_75 = F_44 ( V_76 ) ;
V_67 . V_77 = F_44 ( 1 ) ;
V_67 . V_81 = F_44 ( 1 ) ;
V_67 . V_78 = F_44 ( F_51 ( V_34 ) / 20 ) ;
V_67 . V_80 = F_44 ( F_51 ( V_34 / 2 ) ) ;
V_67 . V_34 = F_44 ( F_51 ( V_34 ) ) ;
V_67 . V_83 = F_44 ( 1 ) ;
V_67 . V_84 = F_44 ( V_33 |
V_28 ) ;
return F_32 ( V_2 , V_11 , V_4 , & V_67 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_58 ) ;
V_65 = NULL ;
F_26 ( & V_2 -> V_5 ) ;
F_53 (te_data, &mvm->time_event_list, list) {
if ( V_4 -> V_11 -> type == V_31 ) {
V_65 = F_40 ( V_4 -> V_11 ) ;
break;
}
}
F_28 ( & V_2 -> V_5 ) ;
if ( ! V_65 ) {
F_23 ( V_2 , L_18 ) ;
return;
}
F_48 ( V_2 , V_65 , V_4 ) ;
F_9 ( V_2 ) ;
}
