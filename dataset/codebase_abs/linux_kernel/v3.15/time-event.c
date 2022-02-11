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
static inline T_1 F_34 ( T_2 V_52 )
{
return F_35 ( V_52 ) & V_53 ;
}
static inline T_1 F_36 ( T_2 V_52 )
{
return ( F_35 ( V_52 ) & V_54 ) >>
V_55 ;
}
static inline T_1 F_37 ( T_2 V_52 )
{
return ( F_35 ( V_52 ) & V_56 ) >> V_57 ;
}
static void F_38 ( const struct V_58 * V_59 ,
struct V_60 * V_61 )
{
V_61 -> V_62 = V_59 -> V_62 ;
V_61 -> V_28 = V_59 -> V_28 ;
V_61 -> V_6 = V_59 -> V_6 ;
V_61 -> V_63 = V_59 -> V_63 ;
V_61 -> V_64 = V_59 -> V_64 ;
V_61 -> V_65 = V_59 -> V_65 ;
V_61 -> V_66 = V_59 -> V_66 ;
V_61 -> V_36 = V_59 -> V_36 ;
if ( V_59 -> V_67 == V_68 )
V_61 -> V_67 = F_39 ( V_69 ) ;
else
V_61 -> V_67 = F_39 ( V_59 -> V_67 ) ;
V_61 -> V_70 = F_39 ( V_59 -> V_70 ) ;
V_61 -> V_71 = 0 ;
V_61 -> V_72 = F_39 ( F_36 ( V_59 -> V_52 ) ) ;
V_61 -> V_73 = F_39 ( ! F_37 ( V_59 -> V_52 ) ) ;
V_61 -> V_74 = F_39 ( F_34 ( V_59 -> V_52 ) ) ;
}
static int F_40 ( struct V_1 * V_2 ,
const struct V_58 * V_40 )
{
struct V_60 V_61 ;
if ( V_2 -> V_75 -> V_76 . V_77 & V_78 )
return F_41 ( V_2 , V_51 , V_79 ,
sizeof( * V_40 ) , V_40 ) ;
F_38 ( V_40 , & V_61 ) ;
return F_41 ( V_2 , V_51 , V_79 ,
sizeof( V_61 ) , & V_61 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_19 * V_11 ,
struct V_3 * V_4 ,
struct V_58 * V_80 )
{
static const T_3 V_81 [] = { V_51 } ;
struct V_82 V_83 ;
int V_84 ;
F_2 ( & V_2 -> V_85 ) ;
F_17 ( V_2 , L_12 ,
F_18 ( V_80 -> V_36 ) ) ;
F_27 ( & V_2 -> V_5 ) ;
if ( F_32 ( V_4 -> V_6 != V_7 ) ) {
F_29 ( & V_2 -> V_5 ) ;
return - V_86 ;
}
V_4 -> V_11 = V_11 ;
V_4 -> V_36 = F_18 ( V_80 -> V_36 ) ;
V_4 -> V_6 = F_18 ( V_80 -> V_6 ) ;
F_43 ( & V_4 -> V_8 , & V_2 -> V_87 ) ;
F_29 ( & V_2 -> V_5 ) ;
F_44 ( & V_2 -> V_46 , & V_83 ,
V_81 ,
F_45 ( V_81 ) ,
F_30 , V_4 ) ;
V_84 = F_40 ( V_2 , V_80 ) ;
if ( V_84 ) {
F_14 ( V_2 , L_13 , V_84 ) ;
F_46 ( & V_2 -> V_46 , & V_83 ) ;
goto V_88;
}
V_84 = F_47 ( & V_2 -> V_46 , & V_83 , 1 ) ;
F_33 ( V_84 ) ;
if ( V_84 ) {
V_88:
F_27 ( & V_2 -> V_5 ) ;
F_1 ( V_2 , V_4 ) ;
F_29 ( & V_2 -> V_5 ) ;
}
return V_84 ;
}
void F_48 ( struct V_1 * V_2 ,
struct V_19 * V_11 ,
T_4 V_36 , T_4 V_89 ,
T_4 V_64 )
{
struct V_90 * V_91 = F_49 ( V_11 ) ;
struct V_3 * V_4 = & V_91 -> V_92 ;
struct V_58 V_93 = {} ;
F_2 ( & V_2 -> V_85 ) ;
if ( V_4 -> V_9 &&
F_50 ( V_4 -> V_33 , F_21 ( V_89 ) ) ) {
F_17 ( V_2 , L_14 ,
F_51 ( V_4 -> V_33 - V_32 ) ) ;
return;
}
if ( V_4 -> V_9 ) {
F_17 ( V_2 , L_15 ,
V_4 -> V_10 ,
F_51 ( V_4 -> V_33 - V_32 ) ) ;
F_52 ( V_2 , V_11 ) ;
}
V_93 . V_28 = F_39 ( V_94 ) ;
V_93 . V_62 =
F_39 ( F_53 ( V_91 -> V_6 , V_91 -> V_95 ) ) ;
V_93 . V_6 = F_39 ( V_96 ) ;
V_93 . V_63 =
F_39 ( F_54 ( V_2 -> V_97 , V_98 ) ) ;
V_93 . V_70 = V_99 ;
V_93 . V_64 = F_39 ( V_64 ) ;
V_93 . V_66 = F_39 ( 1 ) ;
V_93 . V_36 = F_39 ( V_36 ) ;
V_93 . V_67 = 1 ;
V_93 . V_52 = F_55 ( V_30 |
V_31 |
V_100 ) ;
F_42 ( V_2 , V_11 , V_4 , & V_93 ) ;
}
void F_56 ( struct V_1 * V_2 ,
struct V_90 * V_91 ,
struct V_3 * V_4 )
{
struct V_58 V_93 = {} ;
T_4 V_6 , V_10 ;
int V_84 ;
F_27 ( & V_2 -> V_5 ) ;
V_10 = V_4 -> V_10 ;
V_6 = V_4 -> V_6 ;
F_1 ( V_2 , V_4 ) ;
F_29 ( & V_2 -> V_5 ) ;
if ( V_6 == V_7 ) {
F_17 ( V_2 , L_16 , V_10 ) ;
return;
}
V_93 . V_6 = F_39 ( V_10 ) ;
V_93 . V_28 = F_39 ( V_101 ) ;
V_93 . V_62 =
F_39 ( F_53 ( V_91 -> V_6 , V_91 -> V_95 ) ) ;
F_17 ( V_2 , L_17 , F_18 ( V_93 . V_6 ) ) ;
V_84 = F_40 ( V_2 , & V_93 ) ;
if ( F_32 ( V_84 ) )
return;
}
void F_52 ( struct V_1 * V_2 ,
struct V_19 * V_11 )
{
struct V_90 * V_91 = F_49 ( V_11 ) ;
struct V_3 * V_4 = & V_91 -> V_92 ;
F_2 ( & V_2 -> V_85 ) ;
F_56 ( V_2 , V_91 , V_4 ) ;
}
int F_57 ( struct V_1 * V_2 , struct V_19 * V_11 ,
int V_36 , enum V_102 type )
{
struct V_90 * V_91 = F_49 ( V_11 ) ;
struct V_3 * V_4 = & V_91 -> V_92 ;
struct V_58 V_93 = {} ;
F_2 ( & V_2 -> V_85 ) ;
if ( V_4 -> V_9 ) {
F_19 ( V_2 , L_18 ) ;
return - V_103 ;
}
F_58 ( & V_2 -> V_14 ) ;
V_93 . V_28 = F_39 ( V_94 ) ;
V_93 . V_62 =
F_39 ( F_53 ( V_91 -> V_6 , V_91 -> V_95 ) ) ;
switch ( type ) {
case V_104 :
V_93 . V_6 = F_39 ( V_105 ) ;
break;
case V_106 :
V_93 . V_6 = F_39 ( V_107 ) ;
break;
default:
F_59 ( 1 , L_19 ) ;
return - V_108 ;
}
V_93 . V_63 = F_39 ( 0 ) ;
V_93 . V_66 = F_39 ( 1 ) ;
V_93 . V_70 = F_60 ( F_61 ( V_36 ) / 50 , V_109 ) ;
V_93 . V_64 = F_39 ( F_61 ( V_36 / 2 ) ) ;
V_93 . V_36 = F_39 ( F_61 ( V_36 ) ) ;
V_93 . V_67 = 1 ;
V_93 . V_52 = F_55 ( V_30 |
V_31 |
V_100 ) ;
return F_42 ( V_2 , V_11 , V_4 , & V_93 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_90 * V_91 ;
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_85 ) ;
V_91 = NULL ;
F_27 ( & V_2 -> V_5 ) ;
F_63 (te_data, &mvm->time_event_list, list) {
if ( V_4 -> V_11 -> type == V_34 ) {
V_91 = F_49 ( V_4 -> V_11 ) ;
break;
}
}
F_29 ( & V_2 -> V_5 ) ;
if ( ! V_91 ) {
F_19 ( V_2 , L_20 ) ;
return;
}
F_56 ( V_2 , V_91 , V_4 ) ;
F_9 ( V_2 ) ;
}
