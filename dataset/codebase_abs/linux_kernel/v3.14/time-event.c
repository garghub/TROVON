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
if ( ! F_17 ( V_25 -> V_17 ) ) {
bool V_28 = F_17 ( V_25 -> V_27 ) &
V_29 ;
F_18 ( V_2 , L_3 ,
V_28 ? L_4 : L_5 ) ;
if ( F_12 ( V_2 , V_4 -> V_11 , NULL ) ) {
F_1 ( V_2 , V_4 ) ;
return;
}
}
if ( F_17 ( V_25 -> V_27 ) & V_30 ) {
F_16 ( V_2 ,
L_6 ,
V_31 , V_4 -> V_32 ) ;
if ( V_4 -> V_11 -> type == V_33 ) {
F_19 ( V_2 -> V_34 ) ;
F_9 ( V_2 ) ;
}
F_12 ( V_2 , V_4 -> V_11 ,
L_7 ) ;
F_1 ( V_2 , V_4 ) ;
} else if ( F_17 ( V_25 -> V_27 ) & V_29 ) {
V_4 -> V_9 = true ;
V_4 -> V_32 = F_20 ( V_4 -> V_35 ) ;
if ( V_4 -> V_11 -> type == V_33 ) {
F_21 ( V_16 , & V_2 -> V_17 ) ;
F_22 ( V_2 -> V_34 ) ;
}
} else {
F_18 ( V_2 , L_8 ) ;
}
}
int F_23 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_40 * V_41 = F_24 ( V_37 ) ;
struct V_24 * V_25 = ( void * ) V_41 -> V_42 ;
struct V_3 * V_4 , * V_43 ;
F_16 ( V_2 , L_9 ,
F_17 ( V_25 -> V_26 ) ,
F_17 ( V_25 -> V_27 ) ) ;
F_25 ( & V_2 -> V_5 ) ;
F_26 (te_data, tmp, &mvm->time_event_list, list) {
if ( F_17 ( V_25 -> V_26 ) == V_4 -> V_10 )
F_15 ( V_2 , V_4 , V_25 ) ;
}
F_27 ( & V_2 -> V_5 ) ;
return 0 ;
}
static bool F_28 ( struct V_44 * V_45 ,
struct V_40 * V_41 , void * V_42 )
{
struct V_1 * V_2 =
F_5 ( V_45 , struct V_1 , V_45 ) ;
struct V_3 * V_4 = V_42 ;
struct V_46 * V_47 ;
int V_48 = F_29 ( V_41 ) ;
if ( F_30 ( V_41 -> V_49 . V_39 != V_50 ) )
return true ;
if ( F_31 ( V_48 != sizeof( * V_47 ) ) ) {
F_13 ( V_2 , L_10 ) ;
return true ;
}
V_47 = ( void * ) V_41 -> V_42 ;
if ( F_31 ( F_17 ( V_47 -> V_6 ) != V_4 -> V_6 ) )
return false ;
V_4 -> V_10 = F_17 ( V_47 -> V_26 ) ;
F_16 ( V_2 , L_11 ,
V_4 -> V_10 ) ;
return true ;
}
static inline T_1 F_32 ( T_2 V_51 )
{
return F_33 ( V_51 ) & V_52 ;
}
static inline T_1 F_34 ( T_2 V_51 )
{
return ( F_33 ( V_51 ) & V_53 ) >>
V_54 ;
}
static inline T_1 F_35 ( T_2 V_51 )
{
return ( F_33 ( V_51 ) & V_55 ) >> V_56 ;
}
static void F_36 ( const struct V_57 * V_58 ,
struct V_59 * V_60 )
{
V_60 -> V_61 = V_58 -> V_61 ;
V_60 -> V_27 = V_58 -> V_27 ;
V_60 -> V_6 = V_58 -> V_6 ;
V_60 -> V_62 = V_58 -> V_62 ;
V_60 -> V_63 = V_58 -> V_63 ;
V_60 -> V_64 = V_58 -> V_64 ;
V_60 -> V_65 = V_58 -> V_65 ;
V_60 -> V_35 = V_58 -> V_35 ;
if ( V_58 -> V_66 == V_67 )
V_60 -> V_66 = F_37 ( V_68 ) ;
else
V_60 -> V_66 = F_37 ( V_58 -> V_66 ) ;
V_60 -> V_69 = F_37 ( V_58 -> V_69 ) ;
V_60 -> V_70 = 0 ;
V_60 -> V_71 = F_37 ( F_34 ( V_58 -> V_51 ) ) ;
V_60 -> V_72 = F_37 ( ! F_35 ( V_58 -> V_51 ) ) ;
V_60 -> V_73 = F_37 ( F_32 ( V_58 -> V_51 ) ) ;
}
static int F_38 ( struct V_1 * V_2 ,
const struct V_57 * V_39 )
{
struct V_59 V_60 ;
if ( V_2 -> V_74 -> V_75 . V_76 & V_77 )
return F_39 ( V_2 , V_50 , V_78 ,
sizeof( * V_39 ) , V_39 ) ;
F_36 ( V_39 , & V_60 ) ;
return F_39 ( V_2 , V_50 , V_78 ,
sizeof( V_60 ) , & V_60 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_18 * V_11 ,
struct V_3 * V_4 ,
struct V_57 * V_79 )
{
static const T_3 V_80 [] = { V_50 } ;
struct V_81 V_82 ;
int V_83 ;
F_2 ( & V_2 -> V_84 ) ;
F_16 ( V_2 , L_12 ,
F_17 ( V_79 -> V_35 ) ) ;
F_25 ( & V_2 -> V_5 ) ;
if ( F_30 ( V_4 -> V_6 != V_7 ) ) {
F_27 ( & V_2 -> V_5 ) ;
return - V_85 ;
}
V_4 -> V_11 = V_11 ;
V_4 -> V_35 = F_17 ( V_79 -> V_35 ) ;
V_4 -> V_6 = F_17 ( V_79 -> V_6 ) ;
F_41 ( & V_4 -> V_8 , & V_2 -> V_86 ) ;
F_27 ( & V_2 -> V_5 ) ;
F_42 ( & V_2 -> V_45 , & V_82 ,
V_80 ,
F_43 ( V_80 ) ,
F_28 , V_4 ) ;
V_83 = F_38 ( V_2 , V_79 ) ;
if ( V_83 ) {
F_13 ( V_2 , L_13 , V_83 ) ;
F_44 ( & V_2 -> V_45 , & V_82 ) ;
goto V_87;
}
V_83 = F_45 ( & V_2 -> V_45 , & V_82 , 1 ) ;
F_31 ( V_83 ) ;
if ( V_83 ) {
V_87:
F_25 ( & V_2 -> V_5 ) ;
F_1 ( V_2 , V_4 ) ;
F_27 ( & V_2 -> V_5 ) ;
}
return V_83 ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_18 * V_11 ,
T_4 V_35 , T_4 V_88 ,
T_4 V_63 )
{
struct V_89 * V_90 = F_47 ( V_11 ) ;
struct V_3 * V_4 = & V_90 -> V_91 ;
struct V_57 V_92 = {} ;
F_2 ( & V_2 -> V_84 ) ;
if ( V_4 -> V_9 &&
F_48 ( V_4 -> V_32 , F_20 ( V_88 ) ) ) {
F_16 ( V_2 , L_14 ,
F_49 ( V_4 -> V_32 - V_31 ) ) ;
return;
}
if ( V_4 -> V_9 ) {
F_16 ( V_2 , L_15 ,
V_4 -> V_10 ,
F_49 ( V_4 -> V_32 - V_31 ) ) ;
F_50 ( V_2 , V_11 ) ;
}
V_92 . V_27 = F_37 ( V_93 ) ;
V_92 . V_61 =
F_37 ( F_51 ( V_90 -> V_6 , V_90 -> V_94 ) ) ;
V_92 . V_6 = F_37 ( V_95 ) ;
V_92 . V_62 =
F_37 ( F_52 ( V_2 -> V_96 , V_97 ) ) ;
V_92 . V_69 = V_98 ;
V_92 . V_63 = F_37 ( V_63 ) ;
V_92 . V_65 = F_37 ( 1 ) ;
V_92 . V_35 = F_37 ( V_35 ) ;
V_92 . V_66 = 1 ;
V_92 . V_51 = F_53 ( V_29 |
V_30 ) ;
F_40 ( V_2 , V_11 , V_4 , & V_92 ) ;
}
void F_54 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
struct V_3 * V_4 )
{
struct V_57 V_92 = {} ;
T_4 V_6 , V_10 ;
int V_83 ;
F_25 ( & V_2 -> V_5 ) ;
V_10 = V_4 -> V_10 ;
V_6 = V_4 -> V_6 ;
F_1 ( V_2 , V_4 ) ;
F_27 ( & V_2 -> V_5 ) ;
if ( V_6 == V_7 ) {
F_16 ( V_2 , L_16 , V_10 ) ;
return;
}
V_92 . V_6 = F_37 ( V_10 ) ;
V_92 . V_27 = F_37 ( V_99 ) ;
V_92 . V_61 =
F_37 ( F_51 ( V_90 -> V_6 , V_90 -> V_94 ) ) ;
F_16 ( V_2 , L_17 , F_17 ( V_92 . V_6 ) ) ;
V_83 = F_38 ( V_2 , & V_92 ) ;
if ( F_30 ( V_83 ) )
return;
}
void F_50 ( struct V_1 * V_2 ,
struct V_18 * V_11 )
{
struct V_89 * V_90 = F_47 ( V_11 ) ;
struct V_3 * V_4 = & V_90 -> V_91 ;
F_2 ( & V_2 -> V_84 ) ;
F_54 ( V_2 , V_90 , V_4 ) ;
}
int F_55 ( struct V_1 * V_2 , struct V_18 * V_11 ,
int V_35 , enum V_100 type )
{
struct V_89 * V_90 = F_47 ( V_11 ) ;
struct V_3 * V_4 = & V_90 -> V_91 ;
struct V_57 V_92 = {} ;
F_2 ( & V_2 -> V_84 ) ;
if ( V_4 -> V_9 ) {
F_18 ( V_2 , L_18 ) ;
return - V_101 ;
}
F_56 ( & V_2 -> V_14 ) ;
V_92 . V_27 = F_37 ( V_93 ) ;
V_92 . V_61 =
F_37 ( F_51 ( V_90 -> V_6 , V_90 -> V_94 ) ) ;
switch ( type ) {
case V_102 :
V_92 . V_6 = F_37 ( V_103 ) ;
break;
case V_104 :
V_92 . V_6 = F_37 ( V_105 ) ;
break;
default:
F_57 ( 1 , L_19 ) ;
return - V_106 ;
}
V_92 . V_62 = F_37 ( 0 ) ;
V_92 . V_65 = F_37 ( 1 ) ;
V_92 . V_69 = F_58 ( F_59 ( V_35 ) / 50 , V_107 ) ;
V_92 . V_63 = F_37 ( F_59 ( V_35 / 2 ) ) ;
V_92 . V_35 = F_37 ( F_59 ( V_35 ) ) ;
V_92 . V_66 = 1 ;
V_92 . V_51 = F_53 ( V_29 |
V_30 ) ;
return F_40 ( V_2 , V_11 , V_4 , & V_92 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_89 * V_90 ;
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_84 ) ;
V_90 = NULL ;
F_25 ( & V_2 -> V_5 ) ;
F_61 (te_data, &mvm->time_event_list, list) {
if ( V_4 -> V_11 -> type == V_33 ) {
V_90 = F_47 ( V_4 -> V_11 ) ;
break;
}
}
F_27 ( & V_2 -> V_5 ) ;
if ( ! V_90 ) {
F_18 ( V_2 , L_20 ) ;
return;
}
F_54 ( V_2 , V_90 , V_4 ) ;
F_9 ( V_2 ) ;
}
