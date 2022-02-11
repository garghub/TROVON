void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_5 ) ;
if ( ! V_4 -> V_6 )
return;
F_3 ( & V_4 -> V_7 ) ;
V_4 -> V_8 = false ;
V_4 -> V_9 = 0 ;
V_4 -> V_10 = V_11 ;
V_4 -> V_6 = NULL ;
}
void F_4 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_5 ( V_13 , struct V_1 , V_14 ) ;
T_1 V_15 = 0 ;
if ( F_6 ( V_16 , & V_2 -> V_17 ) ) {
V_15 |= F_7 ( V_18 ) ;
F_8 ( V_2 , V_19 ) ;
}
if ( F_6 ( V_20 , & V_2 -> V_17 ) ) {
V_15 |= F_7 ( V_2 -> V_21 ) ;
F_8 ( V_2 , V_22 ) ;
}
F_9 () ;
F_10 ( V_2 , V_15 , false ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_14 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
F_14 () ;
V_24 = F_15 ( V_2 -> V_24 ) ;
if ( ! V_24 || ! V_24 -> V_25 )
goto V_26;
F_16 ( V_2 , L_1 ) ;
if ( ! F_17 ( V_24 ) ) {
F_18 ( V_2 , L_2 ) ;
goto V_26;
}
F_19 ( V_24 ) ;
F_20 () ;
F_21 ( V_2 -> V_24 , NULL ) ;
return;
V_26:
F_20 () ;
}
static bool F_22 ( struct V_1 * V_2 ,
struct V_23 * V_6 ,
const char * V_27 )
{
if ( V_6 -> type != V_28 )
return false ;
if ( V_6 -> V_29 . V_30 && V_6 -> V_29 . V_31 )
return false ;
if ( V_27 )
F_23 ( V_2 , L_3 , V_27 ) ;
F_24 ( V_2 , V_6 , V_27 ) ;
return true ;
}
static void
F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 )
{
struct V_23 * V_6 = V_4 -> V_6 ;
struct V_34 * V_35 = F_26 ( V_6 ) ;
if ( ! V_33 -> V_17 )
F_16 ( V_2 , L_4 ) ;
switch ( V_4 -> V_6 -> type ) {
case V_36 :
if ( ! V_33 -> V_17 )
V_35 -> V_37 = true ;
F_13 ( V_2 ) ;
break;
case V_28 :
if ( ! V_33 -> V_17 ) {
F_24 ( V_2 , V_6 ,
L_5 ) ;
break;
}
F_27 ( V_2 , V_4 -> V_6 ) ;
F_28 ( V_4 -> V_6 , true ) ;
break;
default:
F_29 ( 1 ) ;
break;
}
F_1 ( V_2 , V_4 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_3 * V_4 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 ;
int V_42 ;
if ( ! F_31 ( V_2 -> V_43 , V_44 ) )
return;
V_39 = F_32 ( V_2 -> V_43 , V_44 ) ;
V_41 = ( void * ) V_39 -> V_45 ;
if ( ! F_33 ( V_2 , V_4 -> V_6 , V_39 ) )
return;
for ( V_42 = 0 ; V_42 < F_34 ( V_41 -> V_46 ) ; V_42 ++ ) {
T_1 V_47 = F_35 ( V_41 -> V_46 [ V_42 ] . V_10 ) ;
T_1 V_48 =
F_35 ( V_41 -> V_46 [ V_42 ] . V_49 ) ;
T_1 V_50 =
F_35 ( V_41 -> V_46 [ V_42 ] . V_51 ) ;
if ( V_47 != V_4 -> V_10 ||
! ( V_48 & F_35 ( V_33 -> V_52 ) ) ||
! ( V_50 & F_7 ( F_35 ( V_33 -> V_17 ) ) ) )
continue;
F_36 ( V_2 , V_39 ,
L_6 ,
V_4 -> V_10 ,
F_35 ( V_33 -> V_52 ) ,
F_35 ( V_33 -> V_17 ) ) ;
break;
}
}
static void F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_32 * V_33 )
{
F_2 ( & V_2 -> V_5 ) ;
F_16 ( V_2 , L_7 ,
F_35 ( V_33 -> V_53 ) ,
F_35 ( V_33 -> V_52 ) ) ;
F_30 ( V_2 , V_33 , V_4 ) ;
if ( ! F_35 ( V_33 -> V_17 ) ) {
const char * V_54 ;
if ( V_33 -> V_52 & F_38 ( V_55 ) )
V_54 = L_8 ;
else
V_54 = L_9 ;
F_16 ( V_2 , L_3 , V_54 ) ;
if ( F_22 ( V_2 , V_4 -> V_6 , V_54 ) ) {
F_1 ( V_2 , V_4 ) ;
return;
}
}
if ( F_35 ( V_33 -> V_52 ) & V_56 ) {
F_16 ( V_2 ,
L_10 ,
V_57 , V_4 -> V_58 ) ;
switch ( V_4 -> V_6 -> type ) {
case V_59 :
F_39 ( V_2 -> V_60 ) ;
F_11 ( V_2 ) ;
break;
case V_28 :
F_22 ( V_2 , V_4 -> V_6 ,
L_11 ) ;
break;
default:
break;
}
F_1 ( V_2 , V_4 ) ;
} else if ( F_35 ( V_33 -> V_52 ) & V_55 ) {
V_4 -> V_8 = true ;
V_4 -> V_58 = F_40 ( V_4 -> V_61 ) ;
if ( V_4 -> V_6 -> type == V_59 ) {
F_41 ( V_16 , & V_2 -> V_17 ) ;
F_42 ( V_2 , V_19 ) ;
F_43 ( V_2 -> V_60 ) ;
} else if ( V_4 -> V_10 == V_62 ) {
F_25 ( V_2 , V_4 , V_33 ) ;
}
} else {
F_18 ( V_2 , L_12 ) ;
}
}
static int F_44 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_3 * V_4 , * V_63 ;
bool V_64 = false ;
F_45 (te_data, tmp, &mvm->aux_roc_te_list, list) {
if ( F_35 ( V_33 -> V_53 ) == V_4 -> V_9 ) {
V_64 = true ;
break;
}
}
if ( ! V_64 )
return - V_65 ;
F_30 ( V_2 , V_33 , V_4 ) ;
if ( ! F_35 ( V_33 -> V_17 ) ) {
F_16 ( V_2 ,
L_13 ,
( F_35 ( V_33 -> V_52 ) &
V_55 ) ? L_14 : L_15 ) ;
return - V_65 ;
}
F_16 ( V_2 ,
L_16 ,
F_35 ( V_33 -> V_53 ) ,
F_35 ( V_33 -> V_52 ) ) ;
if ( F_35 ( V_33 -> V_52 ) == V_56 ) {
F_39 ( V_2 -> V_60 ) ;
F_11 ( V_2 ) ;
F_3 ( & V_4 -> V_7 ) ;
V_4 -> V_8 = false ;
V_4 -> V_6 = NULL ;
V_4 -> V_9 = 0 ;
V_4 -> V_10 = V_11 ;
} else if ( F_35 ( V_33 -> V_52 ) == V_55 ) {
F_41 ( V_20 , & V_2 -> V_17 ) ;
V_4 -> V_8 = true ;
F_42 ( V_2 , V_22 ) ;
F_43 ( V_2 -> V_60 ) ;
} else {
F_16 ( V_2 ,
L_17 ,
F_35 ( V_33 -> V_52 ) ) ;
return - V_65 ;
}
return 0 ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
struct V_68 * V_69 = F_47 ( V_67 ) ;
struct V_32 * V_33 = ( void * ) V_69 -> V_45 ;
struct V_3 * V_4 , * V_63 ;
F_16 ( V_2 , L_18 ,
F_35 ( V_33 -> V_53 ) ,
F_35 ( V_33 -> V_52 ) ) ;
F_48 ( & V_2 -> V_5 ) ;
if ( ! F_44 ( V_2 , V_33 ) )
goto V_70;
F_45 (te_data, tmp, &mvm->time_event_list, list) {
if ( F_35 ( V_33 -> V_53 ) == V_4 -> V_9 )
F_37 ( V_2 , V_4 , V_33 ) ;
}
V_70:
F_49 ( & V_2 -> V_5 ) ;
}
static bool F_50 ( struct V_71 * V_72 ,
struct V_68 * V_69 , void * V_45 )
{
struct V_1 * V_2 =
F_5 ( V_72 , struct V_1 , V_72 ) ;
struct V_3 * V_4 = V_45 ;
struct V_32 * V_73 ;
int V_74 = F_51 ( V_69 ) ;
if ( F_52 ( V_69 -> V_75 . V_76 != V_77 ) )
return true ;
if ( F_29 ( V_74 != sizeof( * V_73 ) ) ) {
F_23 ( V_2 , L_19 ) ;
return true ;
}
V_73 = ( void * ) V_69 -> V_45 ;
if ( F_35 ( V_73 -> V_53 ) != V_4 -> V_9 )
return false ;
F_16 ( V_2 , L_20 ,
V_4 -> V_9 ) ;
if ( ! V_73 -> V_17 )
F_23 ( V_2 ,
L_21 ) ;
return true ;
}
static bool F_53 ( struct V_71 * V_72 ,
struct V_68 * V_69 , void * V_45 )
{
struct V_1 * V_2 =
F_5 ( V_72 , struct V_1 , V_72 ) ;
struct V_3 * V_4 = V_45 ;
struct V_78 * V_73 ;
int V_74 = F_51 ( V_69 ) ;
if ( F_52 ( V_69 -> V_75 . V_76 != V_79 ) )
return true ;
if ( F_29 ( V_74 != sizeof( * V_73 ) ) ) {
F_23 ( V_2 , L_22 ) ;
return true ;
}
V_73 = ( void * ) V_69 -> V_45 ;
if ( F_29 ( F_35 ( V_73 -> V_10 ) != V_4 -> V_10 ) )
return false ;
V_4 -> V_9 = F_35 ( V_73 -> V_53 ) ;
F_16 ( V_2 , L_23 ,
V_4 -> V_9 ) ;
return true ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_23 * V_6 ,
struct V_3 * V_4 ,
struct V_80 * V_81 )
{
static const T_2 V_82 [] = { V_79 } ;
struct V_83 V_84 ;
int V_85 ;
F_2 ( & V_2 -> V_86 ) ;
F_16 ( V_2 , L_24 ,
F_35 ( V_81 -> V_61 ) ) ;
F_48 ( & V_2 -> V_5 ) ;
if ( F_52 ( V_4 -> V_10 != V_11 ) ) {
F_49 ( & V_2 -> V_5 ) ;
return - V_87 ;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_61 = F_35 ( V_81 -> V_61 ) ;
V_4 -> V_10 = F_35 ( V_81 -> V_10 ) ;
F_55 ( & V_4 -> V_7 , & V_2 -> V_88 ) ;
F_49 ( & V_2 -> V_5 ) ;
F_56 ( & V_2 -> V_72 , & V_84 ,
V_82 ,
F_34 ( V_82 ) ,
F_53 , V_4 ) ;
V_85 = F_57 ( V_2 , V_79 , 0 ,
sizeof( * V_81 ) , V_81 ) ;
if ( V_85 ) {
F_23 ( V_2 , L_25 , V_85 ) ;
F_58 ( & V_2 -> V_72 , & V_84 ) ;
goto V_89;
}
V_85 = F_59 ( & V_2 -> V_72 , & V_84 , 1 ) ;
F_29 ( V_85 ) ;
if ( V_85 ) {
V_89:
F_48 ( & V_2 -> V_5 ) ;
F_1 ( V_2 , V_4 ) ;
F_49 ( & V_2 -> V_5 ) ;
}
return V_85 ;
}
void F_60 ( struct V_1 * V_2 ,
struct V_23 * V_6 ,
T_1 V_61 , T_1 V_90 ,
T_1 V_91 , bool V_92 )
{
struct V_34 * V_35 = F_26 ( V_6 ) ;
struct V_3 * V_4 = & V_35 -> V_93 ;
const T_2 V_94 [] = { V_77 } ;
struct V_83 V_95 ;
struct V_80 V_96 = {} ;
F_2 ( & V_2 -> V_86 ) ;
if ( V_4 -> V_8 &&
F_61 ( V_4 -> V_58 , F_40 ( V_90 ) ) ) {
F_16 ( V_2 , L_26 ,
F_62 ( V_4 -> V_58 - V_57 ) ) ;
return;
}
if ( V_4 -> V_8 ) {
F_16 ( V_2 , L_27 ,
V_4 -> V_9 ,
F_62 ( V_4 -> V_58 - V_57 ) ) ;
F_63 ( V_2 , V_6 ) ;
}
V_96 . V_52 = F_38 ( V_97 ) ;
V_96 . V_98 =
F_38 ( F_64 ( V_35 -> V_10 , V_35 -> V_99 ) ) ;
V_96 . V_10 = F_38 ( V_100 ) ;
V_96 . V_101 = F_38 ( 0 ) ;
V_96 . V_102 = V_103 ;
V_96 . V_91 = F_38 ( V_91 ) ;
V_96 . V_104 = F_38 ( 1 ) ;
V_96 . V_61 = F_38 ( V_61 ) ;
V_96 . V_105 = 1 ;
V_96 . V_106 = F_65 ( V_55 |
V_56 |
V_107 ) ;
if ( ! V_92 ) {
F_54 ( V_2 , V_6 , V_4 , & V_96 ) ;
return;
}
F_56 ( & V_2 -> V_72 , & V_95 ,
V_94 ,
F_34 ( V_94 ) ,
F_50 , V_4 ) ;
if ( F_54 ( V_2 , V_6 , V_4 , & V_96 ) ) {
F_23 ( V_2 , L_28 ) ;
F_58 ( & V_2 -> V_72 , & V_95 ) ;
} else if ( F_59 ( & V_2 -> V_72 , & V_95 ,
F_66 ( V_91 ) ) ) {
F_23 ( V_2 , L_29 ) ;
}
}
static bool F_67 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_9 )
{
T_1 V_10 ;
F_48 ( & V_2 -> V_5 ) ;
* V_9 = V_4 -> V_9 ;
V_10 = V_4 -> V_10 ;
F_1 ( V_2 , V_4 ) ;
F_49 ( & V_2 -> V_5 ) ;
if ( V_10 == V_11 ) {
F_16 ( V_2 , L_30 , * V_9 ) ;
return false ;
}
return true ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_108 V_109 = {} ;
T_1 V_9 ;
int V_85 ;
if ( ! F_67 ( V_2 , V_4 , & V_9 ) )
return;
V_109 . V_110 = F_38 ( V_9 ) ;
V_109 . V_52 = F_38 ( V_111 ) ;
V_109 . V_98 =
F_38 ( F_64 ( V_35 -> V_10 , V_35 -> V_99 ) ) ;
F_16 ( V_2 , L_31 ,
F_35 ( V_109 . V_110 ) ) ;
V_85 = F_57 ( V_2 , V_112 , 0 ,
sizeof( V_109 ) , & V_109 ) ;
if ( F_52 ( V_85 ) )
return;
}
void F_69 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_80 V_96 = {} ;
T_1 V_9 ;
int V_85 ;
if ( ! F_67 ( V_2 , V_4 , & V_9 ) )
return;
V_96 . V_10 = F_38 ( V_9 ) ;
V_96 . V_52 = F_38 ( V_111 ) ;
V_96 . V_98 =
F_38 ( F_64 ( V_35 -> V_10 , V_35 -> V_99 ) ) ;
F_16 ( V_2 , L_32 , F_35 ( V_96 . V_10 ) ) ;
V_85 = F_57 ( V_2 , V_79 , 0 ,
sizeof( V_96 ) , & V_96 ) ;
if ( F_52 ( V_85 ) )
return;
}
void F_63 ( struct V_1 * V_2 ,
struct V_23 * V_6 )
{
struct V_34 * V_35 = F_26 ( V_6 ) ;
struct V_3 * V_4 = & V_35 -> V_93 ;
F_2 ( & V_2 -> V_86 ) ;
F_69 ( V_2 , V_35 , V_4 ) ;
}
int F_70 ( struct V_1 * V_2 , struct V_23 * V_6 ,
int V_61 , enum V_113 type )
{
struct V_34 * V_35 = F_26 ( V_6 ) ;
struct V_3 * V_4 = & V_35 -> V_93 ;
struct V_80 V_96 = {} ;
F_2 ( & V_2 -> V_86 ) ;
if ( V_4 -> V_8 ) {
F_18 ( V_2 , L_33 ) ;
return - V_114 ;
}
F_71 ( & V_2 -> V_14 ) ;
V_96 . V_52 = F_38 ( V_97 ) ;
V_96 . V_98 =
F_38 ( F_64 ( V_35 -> V_10 , V_35 -> V_99 ) ) ;
switch ( type ) {
case V_115 :
V_96 . V_10 = F_38 ( V_116 ) ;
break;
case V_117 :
V_96 . V_10 = F_38 ( V_118 ) ;
break;
default:
F_72 ( 1 , L_34 ) ;
return - V_65 ;
}
V_96 . V_101 = F_38 ( 0 ) ;
V_96 . V_104 = F_38 ( 1 ) ;
V_96 . V_102 = F_73 ( F_74 ( V_61 ) / 50 , V_119 ) ;
V_96 . V_91 = F_38 ( F_74 ( V_61 / 2 ) ) ;
V_96 . V_61 = F_38 ( F_74 ( V_61 ) ) ;
V_96 . V_105 = 1 ;
V_96 . V_106 = F_65 ( V_55 |
V_56 |
V_107 ) ;
return F_54 ( V_2 , V_6 , V_4 , & V_96 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = NULL ;
struct V_3 * V_4 ;
bool V_120 = false ;
F_2 ( & V_2 -> V_86 ) ;
F_48 ( & V_2 -> V_5 ) ;
F_76 (te_data, &mvm->time_event_list, list) {
if ( V_4 -> V_6 -> type == V_59 ) {
V_35 = F_26 ( V_4 -> V_6 ) ;
V_120 = true ;
goto V_121;
}
}
V_4 = F_77 ( & V_2 -> V_122 ,
struct V_3 ,
V_7 ) ;
if ( V_4 )
V_35 = F_26 ( V_4 -> V_6 ) ;
V_121:
F_49 ( & V_2 -> V_5 ) ;
if ( ! V_35 ) {
F_18 ( V_2 , L_35 ) ;
return;
}
if ( V_120 )
F_69 ( V_2 , V_35 , V_4 ) ;
else
F_68 ( V_2 , V_35 , V_4 ) ;
F_11 ( V_2 ) ;
}
int F_78 ( struct V_1 * V_2 ,
struct V_23 * V_6 ,
T_1 V_61 , T_1 V_101 )
{
struct V_34 * V_35 = F_26 ( V_6 ) ;
struct V_3 * V_4 = & V_35 -> V_93 ;
struct V_80 V_96 = {} ;
F_2 ( & V_2 -> V_86 ) ;
if ( V_4 -> V_8 ) {
F_16 ( V_2 , L_36 ) ;
return - V_114 ;
}
V_96 . V_52 = F_38 ( V_97 ) ;
V_96 . V_98 =
F_38 ( F_64 ( V_35 -> V_10 , V_35 -> V_99 ) ) ;
V_96 . V_10 = F_38 ( V_62 ) ;
V_96 . V_101 = F_38 ( V_101 ) ;
V_96 . V_102 = V_103 ;
V_96 . V_61 = F_38 ( V_61 ) ;
V_96 . V_105 = 1 ;
V_96 . V_104 = F_38 ( 1 ) ;
V_96 . V_106 = F_65 ( V_55 |
V_123 ) ;
return F_54 ( V_2 , V_6 , V_4 , & V_96 ) ;
}
