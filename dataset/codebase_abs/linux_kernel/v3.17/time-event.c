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
T_1 V_15 = 0 ;
if ( F_6 ( V_16 , & V_2 -> V_17 ) )
V_15 |= F_7 ( V_18 ) ;
if ( F_6 ( V_19 , & V_2 -> V_17 ) )
V_15 |= F_7 ( V_2 -> V_20 ) ;
F_8 ( V_2 , V_21 ) ;
F_9 () ;
F_10 ( V_2 , V_15 , false ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_14 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
F_14 () ;
V_23 = F_15 ( V_2 -> V_23 ) ;
if ( ! V_23 || ! V_23 -> V_24 )
goto V_25;
F_16 ( V_2 , L_1 ) ;
if ( ! F_17 ( V_23 ) ) {
F_18 ( V_2 , L_2 ) ;
goto V_25;
}
F_19 ( V_23 ) ;
F_20 () ;
F_21 ( V_2 -> V_23 , NULL ) ;
return;
V_25:
F_20 () ;
}
static bool F_22 ( struct V_1 * V_2 ,
struct V_22 * V_11 ,
const char * V_26 )
{
if ( V_11 -> type != V_27 )
return false ;
if ( V_11 -> V_28 . V_29 && V_11 -> V_28 . V_30 )
return false ;
if ( V_26 )
F_23 ( V_2 , L_3 , V_26 ) ;
F_24 ( V_11 ) ;
return true ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 )
{
F_2 ( & V_2 -> V_5 ) ;
F_16 ( V_2 , L_4 ,
F_26 ( V_32 -> V_33 ) ,
F_26 ( V_32 -> V_34 ) ) ;
if ( ! F_26 ( V_32 -> V_17 ) ) {
bool V_35 = F_26 ( V_32 -> V_34 ) &
V_36 ;
F_18 ( V_2 , L_5 ,
V_35 ? L_6 : L_7 ) ;
if ( F_22 ( V_2 , V_4 -> V_11 , NULL ) ) {
F_1 ( V_2 , V_4 ) ;
return;
}
}
if ( F_26 ( V_32 -> V_34 ) & V_37 ) {
F_16 ( V_2 ,
L_8 ,
V_38 , V_4 -> V_39 ) ;
if ( V_4 -> V_11 -> type == V_40 ) {
F_27 ( V_2 -> V_41 ) ;
F_11 ( V_2 ) ;
}
F_22 ( V_2 , V_4 -> V_11 ,
L_9 ) ;
F_1 ( V_2 , V_4 ) ;
} else if ( F_26 ( V_32 -> V_34 ) & V_36 ) {
V_4 -> V_9 = true ;
V_4 -> V_39 = F_28 ( V_4 -> V_42 ) ;
if ( V_4 -> V_11 -> type == V_40 ) {
F_29 ( V_16 , & V_2 -> V_17 ) ;
F_30 ( V_2 , V_21 ) ;
F_31 ( V_2 -> V_41 ) ;
} else if ( V_4 -> V_11 -> type == V_43 ) {
if ( F_26 ( V_32 -> V_17 ) )
F_13 ( V_2 ) ;
else
F_16 ( V_2 , L_10 ) ;
F_1 ( V_2 , V_4 ) ;
}
} else {
F_18 ( V_2 , L_11 ) ;
}
}
static int F_32 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 , * V_44 ;
bool V_45 = false ;
F_33 (te_data, tmp, &mvm->aux_roc_te_list, list) {
if ( F_26 ( V_32 -> V_33 ) == V_4 -> V_10 ) {
V_45 = true ;
break;
}
}
if ( ! V_45 )
return - V_46 ;
if ( ! F_26 ( V_32 -> V_17 ) ) {
F_16 ( V_2 ,
L_12 ,
( F_26 ( V_32 -> V_34 ) &
V_36 ) ? L_6 : L_7 ) ;
return - V_46 ;
}
F_16 ( V_2 ,
L_13 ,
F_26 ( V_32 -> V_33 ) ,
F_26 ( V_32 -> V_34 ) ) ;
if ( F_26 ( V_32 -> V_34 ) == V_37 ) {
F_27 ( V_2 -> V_41 ) ;
F_11 ( V_2 ) ;
F_3 ( & V_4 -> V_8 ) ;
V_4 -> V_9 = false ;
V_4 -> V_11 = NULL ;
V_4 -> V_10 = 0 ;
} else if ( F_26 ( V_32 -> V_34 ) == V_36 ) {
F_29 ( V_16 , & V_2 -> V_17 ) ;
F_29 ( V_19 , & V_2 -> V_17 ) ;
V_4 -> V_9 = true ;
F_31 ( V_2 -> V_41 ) ;
} else {
F_16 ( V_2 ,
L_14 ,
F_26 ( V_32 -> V_34 ) ) ;
return - V_46 ;
}
return 0 ;
}
int F_34 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 = F_35 ( V_48 ) ;
struct V_31 * V_32 = ( void * ) V_52 -> V_53 ;
struct V_3 * V_4 , * V_44 ;
F_16 ( V_2 , L_15 ,
F_26 ( V_32 -> V_33 ) ,
F_26 ( V_32 -> V_34 ) ) ;
F_36 ( & V_2 -> V_5 ) ;
if ( ! F_32 ( V_2 , V_32 ) )
goto V_54;
F_33 (te_data, tmp, &mvm->time_event_list, list) {
if ( F_26 ( V_32 -> V_33 ) == V_4 -> V_10 )
F_25 ( V_2 , V_4 , V_32 ) ;
}
V_54:
F_37 ( & V_2 -> V_5 ) ;
return 0 ;
}
static bool F_38 ( struct V_55 * V_56 ,
struct V_51 * V_52 , void * V_53 )
{
struct V_1 * V_2 =
F_5 ( V_56 , struct V_1 , V_56 ) ;
struct V_3 * V_4 = V_53 ;
struct V_57 * V_58 ;
int V_59 = F_39 ( V_52 ) ;
if ( F_40 ( V_52 -> V_60 . V_50 != V_61 ) )
return true ;
if ( F_41 ( V_59 != sizeof( * V_58 ) ) ) {
F_23 ( V_2 , L_16 ) ;
return true ;
}
V_58 = ( void * ) V_52 -> V_53 ;
if ( F_41 ( F_26 ( V_58 -> V_6 ) != V_4 -> V_6 ) )
return false ;
V_4 -> V_10 = F_26 ( V_58 -> V_33 ) ;
F_16 ( V_2 , L_17 ,
V_4 -> V_10 ) ;
return true ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_22 * V_11 ,
struct V_3 * V_4 ,
struct V_62 * V_63 )
{
static const T_2 V_64 [] = { V_61 } ;
struct V_65 V_66 ;
int V_67 ;
F_2 ( & V_2 -> V_68 ) ;
F_16 ( V_2 , L_18 ,
F_26 ( V_63 -> V_42 ) ) ;
F_36 ( & V_2 -> V_5 ) ;
if ( F_40 ( V_4 -> V_6 != V_7 ) ) {
F_37 ( & V_2 -> V_5 ) ;
return - V_69 ;
}
V_4 -> V_11 = V_11 ;
V_4 -> V_42 = F_26 ( V_63 -> V_42 ) ;
V_4 -> V_6 = F_26 ( V_63 -> V_6 ) ;
F_43 ( & V_4 -> V_8 , & V_2 -> V_70 ) ;
F_37 ( & V_2 -> V_5 ) ;
F_44 ( & V_2 -> V_56 , & V_66 ,
V_64 ,
F_45 ( V_64 ) ,
F_38 , V_4 ) ;
V_67 = F_46 ( V_2 , V_61 , 0 ,
sizeof( * V_63 ) , V_63 ) ;
if ( V_67 ) {
F_23 ( V_2 , L_19 , V_67 ) ;
F_47 ( & V_2 -> V_56 , & V_66 ) ;
goto V_71;
}
V_67 = F_48 ( & V_2 -> V_56 , & V_66 , 1 ) ;
F_41 ( V_67 ) ;
if ( V_67 ) {
V_71:
F_36 ( & V_2 -> V_5 ) ;
F_1 ( V_2 , V_4 ) ;
F_37 ( & V_2 -> V_5 ) ;
}
return V_67 ;
}
void F_49 ( struct V_1 * V_2 ,
struct V_22 * V_11 ,
T_1 V_42 , T_1 V_72 ,
T_1 V_73 )
{
struct V_74 * V_75 = F_50 ( V_11 ) ;
struct V_3 * V_4 = & V_75 -> V_76 ;
struct V_62 V_77 = {} ;
F_2 ( & V_2 -> V_68 ) ;
if ( V_4 -> V_9 &&
F_51 ( V_4 -> V_39 , F_28 ( V_72 ) ) ) {
F_16 ( V_2 , L_20 ,
F_52 ( V_4 -> V_39 - V_38 ) ) ;
return;
}
if ( V_4 -> V_9 ) {
F_16 ( V_2 , L_21 ,
V_4 -> V_10 ,
F_52 ( V_4 -> V_39 - V_38 ) ) ;
F_53 ( V_2 , V_11 ) ;
}
V_77 . V_34 = F_54 ( V_78 ) ;
V_77 . V_79 =
F_54 ( F_55 ( V_75 -> V_6 , V_75 -> V_80 ) ) ;
V_77 . V_6 = F_54 ( V_81 ) ;
V_77 . V_82 =
F_54 ( F_56 ( V_2 -> V_83 , V_84 ) ) ;
V_77 . V_85 = V_86 ;
V_77 . V_73 = F_54 ( V_73 ) ;
V_77 . V_87 = F_54 ( 1 ) ;
V_77 . V_42 = F_54 ( V_42 ) ;
V_77 . V_88 = 1 ;
V_77 . V_89 = F_57 ( V_36 |
V_37 |
V_90 ) ;
F_42 ( V_2 , V_11 , V_4 , & V_77 ) ;
}
void F_58 ( struct V_1 * V_2 ,
struct V_74 * V_75 ,
struct V_3 * V_4 )
{
struct V_62 V_77 = {} ;
T_1 V_6 , V_10 ;
int V_67 ;
F_36 ( & V_2 -> V_5 ) ;
V_10 = V_4 -> V_10 ;
V_6 = V_4 -> V_6 ;
F_1 ( V_2 , V_4 ) ;
F_37 ( & V_2 -> V_5 ) ;
if ( V_6 == V_7 ) {
F_16 ( V_2 , L_22 , V_10 ) ;
return;
}
V_77 . V_6 = F_54 ( V_10 ) ;
V_77 . V_34 = F_54 ( V_91 ) ;
V_77 . V_79 =
F_54 ( F_55 ( V_75 -> V_6 , V_75 -> V_80 ) ) ;
F_16 ( V_2 , L_23 , F_26 ( V_77 . V_6 ) ) ;
V_67 = F_46 ( V_2 , V_61 , 0 ,
sizeof( V_77 ) , & V_77 ) ;
if ( F_40 ( V_67 ) )
return;
}
void F_53 ( struct V_1 * V_2 ,
struct V_22 * V_11 )
{
struct V_74 * V_75 = F_50 ( V_11 ) ;
struct V_3 * V_4 = & V_75 -> V_76 ;
F_2 ( & V_2 -> V_68 ) ;
F_58 ( V_2 , V_75 , V_4 ) ;
}
int F_59 ( struct V_1 * V_2 , struct V_22 * V_11 ,
int V_42 , enum V_92 type )
{
struct V_74 * V_75 = F_50 ( V_11 ) ;
struct V_3 * V_4 = & V_75 -> V_76 ;
struct V_62 V_77 = {} ;
F_2 ( & V_2 -> V_68 ) ;
if ( V_4 -> V_9 ) {
F_18 ( V_2 , L_24 ) ;
return - V_93 ;
}
F_60 ( & V_2 -> V_14 ) ;
V_77 . V_34 = F_54 ( V_78 ) ;
V_77 . V_79 =
F_54 ( F_55 ( V_75 -> V_6 , V_75 -> V_80 ) ) ;
switch ( type ) {
case V_94 :
V_77 . V_6 = F_54 ( V_95 ) ;
break;
case V_96 :
V_77 . V_6 = F_54 ( V_97 ) ;
break;
default:
F_61 ( 1 , L_25 ) ;
return - V_46 ;
}
V_77 . V_82 = F_54 ( 0 ) ;
V_77 . V_87 = F_54 ( 1 ) ;
V_77 . V_85 = F_62 ( F_63 ( V_42 ) / 50 , V_98 ) ;
V_77 . V_73 = F_54 ( F_63 ( V_42 / 2 ) ) ;
V_77 . V_42 = F_54 ( F_63 ( V_42 ) ) ;
V_77 . V_88 = 1 ;
V_77 . V_89 = F_57 ( V_36 |
V_37 |
V_90 ) ;
return F_42 ( V_2 , V_11 , V_4 , & V_77 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
struct V_74 * V_75 ;
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_68 ) ;
V_75 = NULL ;
F_36 ( & V_2 -> V_5 ) ;
F_65 (te_data, &mvm->time_event_list, list) {
if ( V_4 -> V_11 -> type == V_40 ) {
V_75 = F_50 ( V_4 -> V_11 ) ;
break;
}
}
F_37 ( & V_2 -> V_5 ) ;
if ( ! V_75 ) {
F_18 ( V_2 , L_26 ) ;
return;
}
F_58 ( V_2 , V_75 , V_4 ) ;
F_11 ( V_2 ) ;
}
int F_66 ( struct V_1 * V_2 ,
struct V_22 * V_11 ,
T_1 V_42 , T_1 V_82 )
{
struct V_74 * V_75 = F_50 ( V_11 ) ;
struct V_3 * V_4 = & V_75 -> V_76 ;
struct V_62 V_77 = {} ;
F_2 ( & V_2 -> V_68 ) ;
if ( V_4 -> V_9 ) {
F_16 ( V_2 , L_27 ) ;
return - V_93 ;
}
V_77 . V_34 = F_54 ( V_78 ) ;
V_77 . V_79 =
F_54 ( F_55 ( V_75 -> V_6 , V_75 -> V_80 ) ) ;
V_77 . V_6 = F_54 ( V_99 ) ;
V_77 . V_82 = F_54 ( V_82 ) ;
V_77 . V_85 = V_86 ;
V_77 . V_42 = F_54 ( V_42 ) ;
V_77 . V_88 = 1 ;
V_77 . V_87 = F_54 ( 1 ) ;
V_77 . V_89 = F_57 ( V_36 |
V_100 ) ;
return F_42 ( V_2 , V_11 , V_4 , & V_77 ) ;
}
