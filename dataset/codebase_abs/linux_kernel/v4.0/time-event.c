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
static void
F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 )
{
if ( ! F_26 ( V_32 -> V_17 ) ) {
if ( V_4 -> V_11 -> type == V_27 )
F_24 ( V_4 -> V_11 ) ;
F_16 ( V_2 , L_4 ) ;
F_1 ( V_2 , V_4 ) ;
return;
}
switch ( V_4 -> V_11 -> type ) {
case V_33 :
F_13 ( V_2 ) ;
break;
case V_27 :
F_27 ( V_2 , V_4 -> V_11 ) ;
F_28 ( V_4 -> V_11 , true ) ;
break;
default:
F_29 ( 1 ) ;
break;
}
F_1 ( V_2 , V_4 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 )
{
F_2 ( & V_2 -> V_5 ) ;
F_16 ( V_2 , L_5 ,
F_26 ( V_32 -> V_34 ) ,
F_26 ( V_32 -> V_35 ) ) ;
if ( ! F_26 ( V_32 -> V_17 ) ) {
bool V_36 = F_26 ( V_32 -> V_35 ) &
V_37 ;
F_18 ( V_2 , L_6 ,
V_36 ? L_7 : L_8 ) ;
if ( F_22 ( V_2 , V_4 -> V_11 , NULL ) ) {
F_1 ( V_2 , V_4 ) ;
return;
}
}
if ( F_26 ( V_32 -> V_35 ) & V_38 ) {
F_16 ( V_2 ,
L_9 ,
V_39 , V_4 -> V_40 ) ;
if ( V_4 -> V_11 -> type == V_41 ) {
F_31 ( V_2 -> V_42 ) ;
F_11 ( V_2 ) ;
}
F_22 ( V_2 , V_4 -> V_11 ,
L_10 ) ;
F_1 ( V_2 , V_4 ) ;
} else if ( F_26 ( V_32 -> V_35 ) & V_37 ) {
V_4 -> V_9 = true ;
V_4 -> V_40 = F_32 ( V_4 -> V_43 ) ;
if ( V_4 -> V_11 -> type == V_41 ) {
F_33 ( V_16 , & V_2 -> V_17 ) ;
F_34 ( V_2 , V_21 ) ;
F_35 ( V_2 -> V_42 ) ;
} else if ( V_4 -> V_6 == V_44 ) {
F_25 ( V_2 , V_4 , V_32 ) ;
}
} else {
F_18 ( V_2 , L_11 ) ;
}
}
static int F_36 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 , * V_45 ;
bool V_46 = false ;
F_37 (te_data, tmp, &mvm->aux_roc_te_list, list) {
if ( F_26 ( V_32 -> V_34 ) == V_4 -> V_10 ) {
V_46 = true ;
break;
}
}
if ( ! V_46 )
return - V_47 ;
if ( ! F_26 ( V_32 -> V_17 ) ) {
F_16 ( V_2 ,
L_12 ,
( F_26 ( V_32 -> V_35 ) &
V_37 ) ? L_7 : L_8 ) ;
return - V_47 ;
}
F_16 ( V_2 ,
L_13 ,
F_26 ( V_32 -> V_34 ) ,
F_26 ( V_32 -> V_35 ) ) ;
if ( F_26 ( V_32 -> V_35 ) == V_38 ) {
F_31 ( V_2 -> V_42 ) ;
F_11 ( V_2 ) ;
F_3 ( & V_4 -> V_8 ) ;
V_4 -> V_9 = false ;
V_4 -> V_11 = NULL ;
V_4 -> V_10 = 0 ;
V_4 -> V_6 = V_7 ;
} else if ( F_26 ( V_32 -> V_35 ) == V_37 ) {
F_33 ( V_19 , & V_2 -> V_17 ) ;
V_4 -> V_9 = true ;
F_35 ( V_2 -> V_42 ) ;
} else {
F_16 ( V_2 ,
L_14 ,
F_26 ( V_32 -> V_35 ) ) ;
return - V_47 ;
}
return 0 ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 = F_39 ( V_49 ) ;
struct V_31 * V_32 = ( void * ) V_53 -> V_54 ;
struct V_3 * V_4 , * V_45 ;
F_16 ( V_2 , L_15 ,
F_26 ( V_32 -> V_34 ) ,
F_26 ( V_32 -> V_35 ) ) ;
F_40 ( & V_2 -> V_5 ) ;
if ( ! F_36 ( V_2 , V_32 ) )
goto V_55;
F_37 (te_data, tmp, &mvm->time_event_list, list) {
if ( F_26 ( V_32 -> V_34 ) == V_4 -> V_10 )
F_30 ( V_2 , V_4 , V_32 ) ;
}
V_55:
F_41 ( & V_2 -> V_5 ) ;
return 0 ;
}
static bool F_42 ( struct V_56 * V_57 ,
struct V_52 * V_53 , void * V_54 )
{
struct V_1 * V_2 =
F_5 ( V_57 , struct V_1 , V_57 ) ;
struct V_3 * V_4 = V_54 ;
struct V_31 * V_58 ;
int V_59 = F_43 ( V_53 ) ;
if ( F_44 ( V_53 -> V_60 . V_51 != V_61 ) )
return true ;
if ( F_29 ( V_59 != sizeof( * V_58 ) ) ) {
F_23 ( V_2 , L_16 ) ;
return true ;
}
V_58 = ( void * ) V_53 -> V_54 ;
if ( F_26 ( V_58 -> V_34 ) != V_4 -> V_10 )
return false ;
F_16 ( V_2 , L_17 ,
V_4 -> V_10 ) ;
if ( ! V_58 -> V_17 )
F_23 ( V_2 ,
L_18 ) ;
return true ;
}
static bool F_45 ( struct V_56 * V_57 ,
struct V_52 * V_53 , void * V_54 )
{
struct V_1 * V_2 =
F_5 ( V_57 , struct V_1 , V_57 ) ;
struct V_3 * V_4 = V_54 ;
struct V_62 * V_58 ;
int V_59 = F_43 ( V_53 ) ;
if ( F_44 ( V_53 -> V_60 . V_51 != V_63 ) )
return true ;
if ( F_29 ( V_59 != sizeof( * V_58 ) ) ) {
F_23 ( V_2 , L_19 ) ;
return true ;
}
V_58 = ( void * ) V_53 -> V_54 ;
if ( F_29 ( F_26 ( V_58 -> V_6 ) != V_4 -> V_6 ) )
return false ;
V_4 -> V_10 = F_26 ( V_58 -> V_34 ) ;
F_16 ( V_2 , L_20 ,
V_4 -> V_10 ) ;
return true ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_22 * V_11 ,
struct V_3 * V_4 ,
struct V_64 * V_65 )
{
static const T_2 V_66 [] = { V_63 } ;
struct V_67 V_68 ;
int V_69 ;
F_2 ( & V_2 -> V_70 ) ;
F_16 ( V_2 , L_21 ,
F_26 ( V_65 -> V_43 ) ) ;
F_40 ( & V_2 -> V_5 ) ;
if ( F_44 ( V_4 -> V_6 != V_7 ) ) {
F_41 ( & V_2 -> V_5 ) ;
return - V_71 ;
}
V_4 -> V_11 = V_11 ;
V_4 -> V_43 = F_26 ( V_65 -> V_43 ) ;
V_4 -> V_6 = F_26 ( V_65 -> V_6 ) ;
F_47 ( & V_4 -> V_8 , & V_2 -> V_72 ) ;
F_41 ( & V_2 -> V_5 ) ;
F_48 ( & V_2 -> V_57 , & V_68 ,
V_66 ,
F_49 ( V_66 ) ,
F_45 , V_4 ) ;
V_69 = F_50 ( V_2 , V_63 , 0 ,
sizeof( * V_65 ) , V_65 ) ;
if ( V_69 ) {
F_23 ( V_2 , L_22 , V_69 ) ;
F_51 ( & V_2 -> V_57 , & V_68 ) ;
goto V_73;
}
V_69 = F_52 ( & V_2 -> V_57 , & V_68 , 1 ) ;
F_29 ( V_69 ) ;
if ( V_69 ) {
V_73:
F_40 ( & V_2 -> V_5 ) ;
F_1 ( V_2 , V_4 ) ;
F_41 ( & V_2 -> V_5 ) ;
}
return V_69 ;
}
void F_53 ( struct V_1 * V_2 ,
struct V_22 * V_11 ,
T_1 V_43 , T_1 V_74 ,
T_1 V_75 , bool V_76 )
{
struct V_77 * V_78 = F_54 ( V_11 ) ;
struct V_3 * V_4 = & V_78 -> V_79 ;
const T_2 V_80 [] = { V_61 } ;
struct V_67 V_81 ;
struct V_64 V_82 = {} ;
F_2 ( & V_2 -> V_70 ) ;
if ( V_4 -> V_9 &&
F_55 ( V_4 -> V_40 , F_32 ( V_74 ) ) ) {
F_16 ( V_2 , L_23 ,
F_56 ( V_4 -> V_40 - V_39 ) ) ;
return;
}
if ( V_4 -> V_9 ) {
F_16 ( V_2 , L_24 ,
V_4 -> V_10 ,
F_56 ( V_4 -> V_40 - V_39 ) ) ;
F_57 ( V_2 , V_11 ) ;
}
V_82 . V_35 = F_58 ( V_83 ) ;
V_82 . V_84 =
F_58 ( F_59 ( V_78 -> V_6 , V_78 -> V_85 ) ) ;
V_82 . V_6 = F_58 ( V_86 ) ;
V_82 . V_87 =
F_58 ( F_60 ( V_2 -> V_88 , V_89 ) ) ;
V_82 . V_90 = V_91 ;
V_82 . V_75 = F_58 ( V_75 ) ;
V_82 . V_92 = F_58 ( 1 ) ;
V_82 . V_43 = F_58 ( V_43 ) ;
V_82 . V_93 = 1 ;
V_82 . V_94 = F_61 ( V_37 |
V_38 |
V_95 ) ;
if ( ! V_76 ) {
F_46 ( V_2 , V_11 , V_4 , & V_82 ) ;
return;
}
F_48 ( & V_2 -> V_57 , & V_81 ,
V_80 ,
F_49 ( V_80 ) ,
F_42 , V_4 ) ;
if ( F_46 ( V_2 , V_11 , V_4 , & V_82 ) ) {
F_23 ( V_2 , L_25 ) ;
F_51 ( & V_2 -> V_57 , & V_81 ) ;
} else if ( F_52 ( & V_2 -> V_57 , & V_81 ,
F_62 ( V_75 ) ) ) {
F_23 ( V_2 , L_26 ) ;
}
}
static bool F_63 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_10 )
{
T_1 V_6 ;
F_40 ( & V_2 -> V_5 ) ;
* V_10 = V_4 -> V_10 ;
V_6 = V_4 -> V_6 ;
F_1 ( V_2 , V_4 ) ;
F_41 ( & V_2 -> V_5 ) ;
if ( V_6 == V_7 ) {
F_16 ( V_2 , L_27 , * V_10 ) ;
return false ;
}
return true ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_77 * V_78 ,
struct V_3 * V_4 )
{
struct V_96 V_97 = {} ;
T_1 V_10 ;
int V_69 ;
if ( ! F_63 ( V_2 , V_4 , & V_10 ) )
return;
V_97 . V_98 = F_58 ( V_10 ) ;
V_97 . V_35 = F_58 ( V_99 ) ;
V_97 . V_84 =
F_58 ( F_59 ( V_78 -> V_6 , V_78 -> V_85 ) ) ;
F_16 ( V_2 , L_28 ,
F_26 ( V_97 . V_98 ) ) ;
V_69 = F_50 ( V_2 , V_100 , 0 ,
sizeof( V_97 ) , & V_97 ) ;
if ( F_44 ( V_69 ) )
return;
}
void F_65 ( struct V_1 * V_2 ,
struct V_77 * V_78 ,
struct V_3 * V_4 )
{
struct V_64 V_82 = {} ;
T_1 V_10 ;
int V_69 ;
if ( ! F_63 ( V_2 , V_4 , & V_10 ) )
return;
V_82 . V_6 = F_58 ( V_10 ) ;
V_82 . V_35 = F_58 ( V_99 ) ;
V_82 . V_84 =
F_58 ( F_59 ( V_78 -> V_6 , V_78 -> V_85 ) ) ;
F_16 ( V_2 , L_29 , F_26 ( V_82 . V_6 ) ) ;
V_69 = F_50 ( V_2 , V_63 , 0 ,
sizeof( V_82 ) , & V_82 ) ;
if ( F_44 ( V_69 ) )
return;
}
void F_57 ( struct V_1 * V_2 ,
struct V_22 * V_11 )
{
struct V_77 * V_78 = F_54 ( V_11 ) ;
struct V_3 * V_4 = & V_78 -> V_79 ;
F_2 ( & V_2 -> V_70 ) ;
F_65 ( V_2 , V_78 , V_4 ) ;
}
int F_66 ( struct V_1 * V_2 , struct V_22 * V_11 ,
int V_43 , enum V_101 type )
{
struct V_77 * V_78 = F_54 ( V_11 ) ;
struct V_3 * V_4 = & V_78 -> V_79 ;
struct V_64 V_82 = {} ;
F_2 ( & V_2 -> V_70 ) ;
if ( V_4 -> V_9 ) {
F_18 ( V_2 , L_30 ) ;
return - V_102 ;
}
F_67 ( & V_2 -> V_14 ) ;
V_82 . V_35 = F_58 ( V_83 ) ;
V_82 . V_84 =
F_58 ( F_59 ( V_78 -> V_6 , V_78 -> V_85 ) ) ;
switch ( type ) {
case V_103 :
V_82 . V_6 = F_58 ( V_104 ) ;
break;
case V_105 :
V_82 . V_6 = F_58 ( V_106 ) ;
break;
default:
F_68 ( 1 , L_31 ) ;
return - V_47 ;
}
V_82 . V_87 = F_58 ( 0 ) ;
V_82 . V_92 = F_58 ( 1 ) ;
V_82 . V_90 = F_69 ( F_70 ( V_43 ) / 50 , V_107 ) ;
V_82 . V_75 = F_58 ( F_70 ( V_43 / 2 ) ) ;
V_82 . V_43 = F_58 ( F_70 ( V_43 ) ) ;
V_82 . V_93 = 1 ;
V_82 . V_94 = F_61 ( V_37 |
V_38 |
V_95 ) ;
return F_46 ( V_2 , V_11 , V_4 , & V_82 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_77 * V_78 ;
struct V_3 * V_4 ;
bool V_108 = false ;
F_2 ( & V_2 -> V_70 ) ;
V_78 = NULL ;
F_40 ( & V_2 -> V_5 ) ;
F_72 (te_data, &mvm->time_event_list, list) {
if ( V_4 -> V_11 -> type == V_41 ) {
V_78 = F_54 ( V_4 -> V_11 ) ;
V_108 = true ;
goto V_109;
}
}
F_72 (te_data, &mvm->aux_roc_te_list, list) {
V_78 = F_54 ( V_4 -> V_11 ) ;
goto V_109;
}
V_109:
F_41 ( & V_2 -> V_5 ) ;
if ( ! V_78 ) {
F_18 ( V_2 , L_32 ) ;
return;
}
if ( V_108 )
F_65 ( V_2 , V_78 , V_4 ) ;
else
F_64 ( V_2 , V_78 , V_4 ) ;
F_11 ( V_2 ) ;
}
int F_73 ( struct V_1 * V_2 ,
struct V_22 * V_11 ,
T_1 V_43 , T_1 V_87 )
{
struct V_77 * V_78 = F_54 ( V_11 ) ;
struct V_3 * V_4 = & V_78 -> V_79 ;
struct V_64 V_82 = {} ;
F_2 ( & V_2 -> V_70 ) ;
if ( V_4 -> V_9 ) {
F_16 ( V_2 , L_33 ) ;
return - V_102 ;
}
V_82 . V_35 = F_58 ( V_83 ) ;
V_82 . V_84 =
F_58 ( F_59 ( V_78 -> V_6 , V_78 -> V_85 ) ) ;
V_82 . V_6 = F_58 ( V_44 ) ;
V_82 . V_87 = F_58 ( V_87 ) ;
V_82 . V_90 = V_91 ;
V_82 . V_43 = F_58 ( V_43 ) ;
V_82 . V_93 = 1 ;
V_82 . V_92 = F_58 ( 1 ) ;
V_82 . V_94 = F_61 ( V_37 |
V_110 ) ;
return F_46 ( V_2 , V_11 , V_4 , & V_82 ) ;
}
