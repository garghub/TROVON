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
V_4 -> V_6 = V_7 ;
} else if ( F_26 ( V_32 -> V_34 ) == V_36 ) {
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
struct V_31 * V_57 ;
int V_58 = F_39 ( V_52 ) ;
if ( F_40 ( V_52 -> V_59 . V_50 != V_60 ) )
return true ;
if ( F_41 ( V_58 != sizeof( * V_57 ) ) ) {
F_23 ( V_2 , L_16 ) ;
return true ;
}
V_57 = ( void * ) V_52 -> V_53 ;
if ( F_26 ( V_57 -> V_33 ) != V_4 -> V_10 )
return false ;
F_16 ( V_2 , L_17 ,
V_4 -> V_10 ) ;
if ( ! V_57 -> V_17 )
F_23 ( V_2 ,
L_18 ) ;
return true ;
}
static bool F_42 ( struct V_55 * V_56 ,
struct V_51 * V_52 , void * V_53 )
{
struct V_1 * V_2 =
F_5 ( V_56 , struct V_1 , V_56 ) ;
struct V_3 * V_4 = V_53 ;
struct V_61 * V_57 ;
int V_58 = F_39 ( V_52 ) ;
if ( F_40 ( V_52 -> V_59 . V_50 != V_62 ) )
return true ;
if ( F_41 ( V_58 != sizeof( * V_57 ) ) ) {
F_23 ( V_2 , L_19 ) ;
return true ;
}
V_57 = ( void * ) V_52 -> V_53 ;
if ( F_41 ( F_26 ( V_57 -> V_6 ) != V_4 -> V_6 ) )
return false ;
V_4 -> V_10 = F_26 ( V_57 -> V_33 ) ;
F_16 ( V_2 , L_20 ,
V_4 -> V_10 ) ;
return true ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_22 * V_11 ,
struct V_3 * V_4 ,
struct V_63 * V_64 )
{
static const T_2 V_65 [] = { V_62 } ;
struct V_66 V_67 ;
int V_68 ;
F_2 ( & V_2 -> V_69 ) ;
F_16 ( V_2 , L_21 ,
F_26 ( V_64 -> V_42 ) ) ;
F_36 ( & V_2 -> V_5 ) ;
if ( F_40 ( V_4 -> V_6 != V_7 ) ) {
F_37 ( & V_2 -> V_5 ) ;
return - V_70 ;
}
V_4 -> V_11 = V_11 ;
V_4 -> V_42 = F_26 ( V_64 -> V_42 ) ;
V_4 -> V_6 = F_26 ( V_64 -> V_6 ) ;
F_44 ( & V_4 -> V_8 , & V_2 -> V_71 ) ;
F_37 ( & V_2 -> V_5 ) ;
F_45 ( & V_2 -> V_56 , & V_67 ,
V_65 ,
F_46 ( V_65 ) ,
F_42 , V_4 ) ;
V_68 = F_47 ( V_2 , V_62 , 0 ,
sizeof( * V_64 ) , V_64 ) ;
if ( V_68 ) {
F_23 ( V_2 , L_22 , V_68 ) ;
F_48 ( & V_2 -> V_56 , & V_67 ) ;
goto V_72;
}
V_68 = F_49 ( & V_2 -> V_56 , & V_67 , 1 ) ;
F_41 ( V_68 ) ;
if ( V_68 ) {
V_72:
F_36 ( & V_2 -> V_5 ) ;
F_1 ( V_2 , V_4 ) ;
F_37 ( & V_2 -> V_5 ) ;
}
return V_68 ;
}
void F_50 ( struct V_1 * V_2 ,
struct V_22 * V_11 ,
T_1 V_42 , T_1 V_73 ,
T_1 V_74 , bool V_75 )
{
struct V_76 * V_77 = F_51 ( V_11 ) ;
struct V_3 * V_4 = & V_77 -> V_78 ;
const T_2 V_79 [] = { V_60 } ;
struct V_66 V_80 ;
struct V_63 V_81 = {} ;
F_2 ( & V_2 -> V_69 ) ;
if ( V_4 -> V_9 &&
F_52 ( V_4 -> V_39 , F_28 ( V_73 ) ) ) {
F_16 ( V_2 , L_23 ,
F_53 ( V_4 -> V_39 - V_38 ) ) ;
return;
}
if ( V_4 -> V_9 ) {
F_16 ( V_2 , L_24 ,
V_4 -> V_10 ,
F_53 ( V_4 -> V_39 - V_38 ) ) ;
F_54 ( V_2 , V_11 ) ;
}
V_81 . V_34 = F_55 ( V_82 ) ;
V_81 . V_83 =
F_55 ( F_56 ( V_77 -> V_6 , V_77 -> V_84 ) ) ;
V_81 . V_6 = F_55 ( V_85 ) ;
V_81 . V_86 =
F_55 ( F_57 ( V_2 -> V_87 , V_88 ) ) ;
V_81 . V_89 = V_90 ;
V_81 . V_74 = F_55 ( V_74 ) ;
V_81 . V_91 = F_55 ( 1 ) ;
V_81 . V_42 = F_55 ( V_42 ) ;
V_81 . V_92 = 1 ;
V_81 . V_93 = F_58 ( V_36 |
V_37 |
V_94 ) ;
if ( ! V_75 ) {
F_43 ( V_2 , V_11 , V_4 , & V_81 ) ;
return;
}
F_45 ( & V_2 -> V_56 , & V_80 ,
V_79 ,
F_46 ( V_79 ) ,
F_38 , V_4 ) ;
if ( F_43 ( V_2 , V_11 , V_4 , & V_81 ) ) {
F_23 ( V_2 , L_25 ) ;
F_48 ( & V_2 -> V_56 , & V_80 ) ;
} else if ( F_49 ( & V_2 -> V_56 , & V_80 ,
F_59 ( V_74 ) ) ) {
F_23 ( V_2 , L_26 ) ;
}
}
void F_60 ( struct V_1 * V_2 ,
struct V_76 * V_77 ,
struct V_3 * V_4 )
{
struct V_63 V_81 = {} ;
T_1 V_6 , V_10 ;
int V_68 ;
F_36 ( & V_2 -> V_5 ) ;
V_10 = V_4 -> V_10 ;
V_6 = V_4 -> V_6 ;
F_1 ( V_2 , V_4 ) ;
F_37 ( & V_2 -> V_5 ) ;
if ( V_6 == V_7 ) {
F_16 ( V_2 , L_27 , V_10 ) ;
return;
}
V_81 . V_6 = F_55 ( V_10 ) ;
V_81 . V_34 = F_55 ( V_95 ) ;
V_81 . V_83 =
F_55 ( F_56 ( V_77 -> V_6 , V_77 -> V_84 ) ) ;
F_16 ( V_2 , L_28 , F_26 ( V_81 . V_6 ) ) ;
V_68 = F_47 ( V_2 , V_62 , 0 ,
sizeof( V_81 ) , & V_81 ) ;
if ( F_40 ( V_68 ) )
return;
}
void F_54 ( struct V_1 * V_2 ,
struct V_22 * V_11 )
{
struct V_76 * V_77 = F_51 ( V_11 ) ;
struct V_3 * V_4 = & V_77 -> V_78 ;
F_2 ( & V_2 -> V_69 ) ;
F_60 ( V_2 , V_77 , V_4 ) ;
}
int F_61 ( struct V_1 * V_2 , struct V_22 * V_11 ,
int V_42 , enum V_96 type )
{
struct V_76 * V_77 = F_51 ( V_11 ) ;
struct V_3 * V_4 = & V_77 -> V_78 ;
struct V_63 V_81 = {} ;
F_2 ( & V_2 -> V_69 ) ;
if ( V_4 -> V_9 ) {
F_18 ( V_2 , L_29 ) ;
return - V_97 ;
}
F_62 ( & V_2 -> V_14 ) ;
V_81 . V_34 = F_55 ( V_82 ) ;
V_81 . V_83 =
F_55 ( F_56 ( V_77 -> V_6 , V_77 -> V_84 ) ) ;
switch ( type ) {
case V_98 :
V_81 . V_6 = F_55 ( V_99 ) ;
break;
case V_100 :
V_81 . V_6 = F_55 ( V_101 ) ;
break;
default:
F_63 ( 1 , L_30 ) ;
return - V_46 ;
}
V_81 . V_86 = F_55 ( 0 ) ;
V_81 . V_91 = F_55 ( 1 ) ;
V_81 . V_89 = F_64 ( F_65 ( V_42 ) / 50 , V_102 ) ;
V_81 . V_74 = F_55 ( F_65 ( V_42 / 2 ) ) ;
V_81 . V_42 = F_55 ( F_65 ( V_42 ) ) ;
V_81 . V_92 = 1 ;
V_81 . V_93 = F_58 ( V_36 |
V_37 |
V_94 ) ;
return F_43 ( V_2 , V_11 , V_4 , & V_81 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
struct V_76 * V_77 ;
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_69 ) ;
V_77 = NULL ;
F_36 ( & V_2 -> V_5 ) ;
F_67 (te_data, &mvm->time_event_list, list) {
if ( V_4 -> V_11 -> type == V_40 ) {
V_77 = F_51 ( V_4 -> V_11 ) ;
break;
}
}
F_37 ( & V_2 -> V_5 ) ;
if ( ! V_77 ) {
F_18 ( V_2 , L_31 ) ;
return;
}
F_60 ( V_2 , V_77 , V_4 ) ;
F_11 ( V_2 ) ;
}
int F_68 ( struct V_1 * V_2 ,
struct V_22 * V_11 ,
T_1 V_42 , T_1 V_86 )
{
struct V_76 * V_77 = F_51 ( V_11 ) ;
struct V_3 * V_4 = & V_77 -> V_78 ;
struct V_63 V_81 = {} ;
F_2 ( & V_2 -> V_69 ) ;
if ( V_4 -> V_9 ) {
F_16 ( V_2 , L_32 ) ;
return - V_97 ;
}
V_81 . V_34 = F_55 ( V_82 ) ;
V_81 . V_83 =
F_55 ( F_56 ( V_77 -> V_6 , V_77 -> V_84 ) ) ;
V_81 . V_6 = F_55 ( V_103 ) ;
V_81 . V_86 = F_55 ( V_86 ) ;
V_81 . V_89 = V_90 ;
V_81 . V_42 = F_55 ( V_42 ) ;
V_81 . V_92 = 1 ;
V_81 . V_91 = F_55 ( 1 ) ;
V_81 . V_93 = F_58 ( V_36 |
V_104 ) ;
return F_43 ( V_2 , V_11 , V_4 , & V_81 ) ;
}
