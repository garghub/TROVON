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
F_24 ( V_2 , V_11 , V_26 ) ;
return true ;
}
static void
F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 )
{
struct V_22 * V_11 = V_4 -> V_11 ;
struct V_33 * V_34 = F_26 ( V_11 ) ;
if ( ! V_32 -> V_17 )
F_16 ( V_2 , L_4 ) ;
switch ( V_4 -> V_11 -> type ) {
case V_35 :
if ( ! V_32 -> V_17 )
V_34 -> V_36 = true ;
F_13 ( V_2 ) ;
break;
case V_27 :
if ( ! V_32 -> V_17 ) {
F_24 ( V_2 , V_11 ,
L_5 ) ;
break;
}
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
struct V_31 * V_32 ,
struct V_3 * V_4 )
{
struct V_37 * V_38 ;
struct V_39 * V_40 ;
int V_41 ;
if ( ! F_31 ( V_2 -> V_42 , V_43 ) )
return;
V_38 = F_32 ( V_2 -> V_42 , V_43 ) ;
V_40 = ( void * ) V_38 -> V_44 ;
if ( ! F_33 ( V_2 , V_4 -> V_11 , V_38 ) )
return;
for ( V_41 = 0 ; V_41 < F_34 ( V_40 -> V_45 ) ; V_41 ++ ) {
T_1 V_46 = F_35 ( V_40 -> V_45 [ V_41 ] . V_6 ) ;
T_1 V_47 =
F_35 ( V_40 -> V_45 [ V_41 ] . V_48 ) ;
T_1 V_49 =
F_35 ( V_40 -> V_45 [ V_41 ] . V_50 ) ;
if ( V_46 != V_4 -> V_6 ||
! ( V_47 & F_35 ( V_32 -> V_51 ) ) ||
! ( V_49 & F_7 ( F_35 ( V_32 -> V_17 ) ) ) )
continue;
F_36 ( V_2 , V_38 ,
L_6 ,
V_4 -> V_6 ,
F_35 ( V_32 -> V_51 ) ,
F_35 ( V_32 -> V_17 ) ) ;
break;
}
}
static void F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_31 * V_32 )
{
F_2 ( & V_2 -> V_5 ) ;
F_16 ( V_2 , L_7 ,
F_35 ( V_32 -> V_52 ) ,
F_35 ( V_32 -> V_51 ) ) ;
F_30 ( V_2 , V_32 , V_4 ) ;
if ( ! F_35 ( V_32 -> V_17 ) ) {
const char * V_53 ;
if ( V_32 -> V_51 & F_38 ( V_54 ) )
V_53 = L_8 ;
else
V_53 = L_9 ;
F_16 ( V_2 , L_3 , V_53 ) ;
if ( F_22 ( V_2 , V_4 -> V_11 , V_53 ) ) {
F_1 ( V_2 , V_4 ) ;
return;
}
}
if ( F_35 ( V_32 -> V_51 ) & V_55 ) {
F_16 ( V_2 ,
L_10 ,
V_56 , V_4 -> V_57 ) ;
switch ( V_4 -> V_11 -> type ) {
case V_58 :
F_39 ( V_2 -> V_59 ) ;
F_11 ( V_2 ) ;
break;
case V_27 :
F_22 ( V_2 , V_4 -> V_11 ,
L_11 ) ;
break;
default:
break;
}
F_1 ( V_2 , V_4 ) ;
} else if ( F_35 ( V_32 -> V_51 ) & V_54 ) {
V_4 -> V_9 = true ;
V_4 -> V_57 = F_40 ( V_4 -> V_60 ) ;
if ( V_4 -> V_11 -> type == V_58 ) {
F_41 ( V_16 , & V_2 -> V_17 ) ;
F_42 ( V_2 , V_21 ) ;
F_43 ( V_2 -> V_59 ) ;
} else if ( V_4 -> V_6 == V_61 ) {
F_25 ( V_2 , V_4 , V_32 ) ;
}
} else {
F_18 ( V_2 , L_12 ) ;
}
}
static int F_44 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 , * V_62 ;
bool V_63 = false ;
F_45 (te_data, tmp, &mvm->aux_roc_te_list, list) {
if ( F_35 ( V_32 -> V_52 ) == V_4 -> V_10 ) {
V_63 = true ;
break;
}
}
if ( ! V_63 )
return - V_64 ;
F_30 ( V_2 , V_32 , V_4 ) ;
if ( ! F_35 ( V_32 -> V_17 ) ) {
F_16 ( V_2 ,
L_13 ,
( F_35 ( V_32 -> V_51 ) &
V_54 ) ? L_14 : L_15 ) ;
return - V_64 ;
}
F_16 ( V_2 ,
L_16 ,
F_35 ( V_32 -> V_52 ) ,
F_35 ( V_32 -> V_51 ) ) ;
if ( F_35 ( V_32 -> V_51 ) == V_55 ) {
F_39 ( V_2 -> V_59 ) ;
F_11 ( V_2 ) ;
F_3 ( & V_4 -> V_8 ) ;
V_4 -> V_9 = false ;
V_4 -> V_11 = NULL ;
V_4 -> V_10 = 0 ;
V_4 -> V_6 = V_7 ;
} else if ( F_35 ( V_32 -> V_51 ) == V_54 ) {
F_41 ( V_19 , & V_2 -> V_17 ) ;
V_4 -> V_9 = true ;
F_43 ( V_2 -> V_59 ) ;
} else {
F_16 ( V_2 ,
L_17 ,
F_35 ( V_32 -> V_51 ) ) ;
return - V_64 ;
}
return 0 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_69 * V_70 = F_47 ( V_66 ) ;
struct V_31 * V_32 = ( void * ) V_70 -> V_44 ;
struct V_3 * V_4 , * V_62 ;
F_16 ( V_2 , L_18 ,
F_35 ( V_32 -> V_52 ) ,
F_35 ( V_32 -> V_51 ) ) ;
F_48 ( & V_2 -> V_5 ) ;
if ( ! F_44 ( V_2 , V_32 ) )
goto V_71;
F_45 (te_data, tmp, &mvm->time_event_list, list) {
if ( F_35 ( V_32 -> V_52 ) == V_4 -> V_10 )
F_37 ( V_2 , V_4 , V_32 ) ;
}
V_71:
F_49 ( & V_2 -> V_5 ) ;
return 0 ;
}
static bool F_50 ( struct V_72 * V_73 ,
struct V_69 * V_70 , void * V_44 )
{
struct V_1 * V_2 =
F_5 ( V_73 , struct V_1 , V_73 ) ;
struct V_3 * V_4 = V_44 ;
struct V_31 * V_74 ;
int V_75 = F_51 ( V_70 ) ;
if ( F_52 ( V_70 -> V_76 . V_68 != V_77 ) )
return true ;
if ( F_29 ( V_75 != sizeof( * V_74 ) ) ) {
F_23 ( V_2 , L_19 ) ;
return true ;
}
V_74 = ( void * ) V_70 -> V_44 ;
if ( F_35 ( V_74 -> V_52 ) != V_4 -> V_10 )
return false ;
F_16 ( V_2 , L_20 ,
V_4 -> V_10 ) ;
if ( ! V_74 -> V_17 )
F_23 ( V_2 ,
L_21 ) ;
return true ;
}
static bool F_53 ( struct V_72 * V_73 ,
struct V_69 * V_70 , void * V_44 )
{
struct V_1 * V_2 =
F_5 ( V_73 , struct V_1 , V_73 ) ;
struct V_3 * V_4 = V_44 ;
struct V_78 * V_74 ;
int V_75 = F_51 ( V_70 ) ;
if ( F_52 ( V_70 -> V_76 . V_68 != V_79 ) )
return true ;
if ( F_29 ( V_75 != sizeof( * V_74 ) ) ) {
F_23 ( V_2 , L_22 ) ;
return true ;
}
V_74 = ( void * ) V_70 -> V_44 ;
if ( F_29 ( F_35 ( V_74 -> V_6 ) != V_4 -> V_6 ) )
return false ;
V_4 -> V_10 = F_35 ( V_74 -> V_52 ) ;
F_16 ( V_2 , L_23 ,
V_4 -> V_10 ) ;
return true ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_22 * V_11 ,
struct V_3 * V_4 ,
struct V_80 * V_81 )
{
static const T_2 V_82 [] = { V_79 } ;
struct V_83 V_84 ;
int V_85 ;
F_2 ( & V_2 -> V_86 ) ;
F_16 ( V_2 , L_24 ,
F_35 ( V_81 -> V_60 ) ) ;
F_48 ( & V_2 -> V_5 ) ;
if ( F_52 ( V_4 -> V_6 != V_7 ) ) {
F_49 ( & V_2 -> V_5 ) ;
return - V_87 ;
}
V_4 -> V_11 = V_11 ;
V_4 -> V_60 = F_35 ( V_81 -> V_60 ) ;
V_4 -> V_6 = F_35 ( V_81 -> V_6 ) ;
F_55 ( & V_4 -> V_8 , & V_2 -> V_88 ) ;
F_49 ( & V_2 -> V_5 ) ;
F_56 ( & V_2 -> V_73 , & V_84 ,
V_82 ,
F_34 ( V_82 ) ,
F_53 , V_4 ) ;
V_85 = F_57 ( V_2 , V_79 , 0 ,
sizeof( * V_81 ) , V_81 ) ;
if ( V_85 ) {
F_23 ( V_2 , L_25 , V_85 ) ;
F_58 ( & V_2 -> V_73 , & V_84 ) ;
goto V_89;
}
V_85 = F_59 ( & V_2 -> V_73 , & V_84 , 1 ) ;
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
struct V_22 * V_11 ,
T_1 V_60 , T_1 V_90 ,
T_1 V_91 , bool V_92 )
{
struct V_33 * V_34 = F_26 ( V_11 ) ;
struct V_3 * V_4 = & V_34 -> V_93 ;
const T_2 V_94 [] = { V_77 } ;
struct V_83 V_95 ;
struct V_80 V_96 = {} ;
F_2 ( & V_2 -> V_86 ) ;
if ( V_4 -> V_9 &&
F_61 ( V_4 -> V_57 , F_40 ( V_90 ) ) ) {
F_16 ( V_2 , L_26 ,
F_62 ( V_4 -> V_57 - V_56 ) ) ;
return;
}
if ( V_4 -> V_9 ) {
F_16 ( V_2 , L_27 ,
V_4 -> V_10 ,
F_62 ( V_4 -> V_57 - V_56 ) ) ;
F_63 ( V_2 , V_11 ) ;
}
V_96 . V_51 = F_38 ( V_97 ) ;
V_96 . V_98 =
F_38 ( F_64 ( V_34 -> V_6 , V_34 -> V_99 ) ) ;
V_96 . V_6 = F_38 ( V_100 ) ;
V_96 . V_101 =
F_38 ( F_65 ( V_2 -> V_102 , V_103 ) ) ;
V_96 . V_104 = V_105 ;
V_96 . V_91 = F_38 ( V_91 ) ;
V_96 . V_106 = F_38 ( 1 ) ;
V_96 . V_60 = F_38 ( V_60 ) ;
V_96 . V_107 = 1 ;
V_96 . V_108 = F_66 ( V_54 |
V_55 |
V_109 ) ;
if ( ! V_92 ) {
F_54 ( V_2 , V_11 , V_4 , & V_96 ) ;
return;
}
F_56 ( & V_2 -> V_73 , & V_95 ,
V_94 ,
F_34 ( V_94 ) ,
F_50 , V_4 ) ;
if ( F_54 ( V_2 , V_11 , V_4 , & V_96 ) ) {
F_23 ( V_2 , L_28 ) ;
F_58 ( & V_2 -> V_73 , & V_95 ) ;
} else if ( F_59 ( & V_2 -> V_73 , & V_95 ,
F_67 ( V_91 ) ) ) {
F_23 ( V_2 , L_29 ) ;
}
}
static bool F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_10 )
{
T_1 V_6 ;
F_48 ( & V_2 -> V_5 ) ;
* V_10 = V_4 -> V_10 ;
V_6 = V_4 -> V_6 ;
F_1 ( V_2 , V_4 ) ;
F_49 ( & V_2 -> V_5 ) ;
if ( V_6 == V_7 ) {
F_16 ( V_2 , L_30 , * V_10 ) ;
return false ;
}
return true ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
struct V_3 * V_4 )
{
struct V_110 V_111 = {} ;
T_1 V_10 ;
int V_85 ;
if ( ! F_68 ( V_2 , V_4 , & V_10 ) )
return;
V_111 . V_112 = F_38 ( V_10 ) ;
V_111 . V_51 = F_38 ( V_113 ) ;
V_111 . V_98 =
F_38 ( F_64 ( V_34 -> V_6 , V_34 -> V_99 ) ) ;
F_16 ( V_2 , L_31 ,
F_35 ( V_111 . V_112 ) ) ;
V_85 = F_57 ( V_2 , V_114 , 0 ,
sizeof( V_111 ) , & V_111 ) ;
if ( F_52 ( V_85 ) )
return;
}
void F_70 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
struct V_3 * V_4 )
{
struct V_80 V_96 = {} ;
T_1 V_10 ;
int V_85 ;
if ( ! F_68 ( V_2 , V_4 , & V_10 ) )
return;
V_96 . V_6 = F_38 ( V_10 ) ;
V_96 . V_51 = F_38 ( V_113 ) ;
V_96 . V_98 =
F_38 ( F_64 ( V_34 -> V_6 , V_34 -> V_99 ) ) ;
F_16 ( V_2 , L_32 , F_35 ( V_96 . V_6 ) ) ;
V_85 = F_57 ( V_2 , V_79 , 0 ,
sizeof( V_96 ) , & V_96 ) ;
if ( F_52 ( V_85 ) )
return;
}
void F_63 ( struct V_1 * V_2 ,
struct V_22 * V_11 )
{
struct V_33 * V_34 = F_26 ( V_11 ) ;
struct V_3 * V_4 = & V_34 -> V_93 ;
F_2 ( & V_2 -> V_86 ) ;
F_70 ( V_2 , V_34 , V_4 ) ;
}
int F_71 ( struct V_1 * V_2 , struct V_22 * V_11 ,
int V_60 , enum V_115 type )
{
struct V_33 * V_34 = F_26 ( V_11 ) ;
struct V_3 * V_4 = & V_34 -> V_93 ;
struct V_80 V_96 = {} ;
F_2 ( & V_2 -> V_86 ) ;
if ( V_4 -> V_9 ) {
F_18 ( V_2 , L_33 ) ;
return - V_116 ;
}
F_72 ( & V_2 -> V_14 ) ;
V_96 . V_51 = F_38 ( V_97 ) ;
V_96 . V_98 =
F_38 ( F_64 ( V_34 -> V_6 , V_34 -> V_99 ) ) ;
switch ( type ) {
case V_117 :
V_96 . V_6 = F_38 ( V_118 ) ;
break;
case V_119 :
V_96 . V_6 = F_38 ( V_120 ) ;
break;
default:
F_73 ( 1 , L_34 ) ;
return - V_64 ;
}
V_96 . V_101 = F_38 ( 0 ) ;
V_96 . V_106 = F_38 ( 1 ) ;
V_96 . V_104 = F_74 ( F_75 ( V_60 ) / 50 , V_121 ) ;
V_96 . V_91 = F_38 ( F_75 ( V_60 / 2 ) ) ;
V_96 . V_60 = F_38 ( F_75 ( V_60 ) ) ;
V_96 . V_107 = 1 ;
V_96 . V_108 = F_66 ( V_54 |
V_55 |
V_109 ) ;
return F_54 ( V_2 , V_11 , V_4 , & V_96 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
struct V_33 * V_34 ;
struct V_3 * V_4 ;
bool V_122 = false ;
F_2 ( & V_2 -> V_86 ) ;
V_34 = NULL ;
F_48 ( & V_2 -> V_5 ) ;
F_77 (te_data, &mvm->time_event_list, list) {
if ( V_4 -> V_11 -> type == V_58 ) {
V_34 = F_26 ( V_4 -> V_11 ) ;
V_122 = true ;
goto V_123;
}
}
F_77 (te_data, &mvm->aux_roc_te_list, list) {
V_34 = F_26 ( V_4 -> V_11 ) ;
goto V_123;
}
V_123:
F_49 ( & V_2 -> V_5 ) ;
if ( ! V_34 ) {
F_18 ( V_2 , L_35 ) ;
return;
}
if ( V_122 )
F_70 ( V_2 , V_34 , V_4 ) ;
else
F_69 ( V_2 , V_34 , V_4 ) ;
F_11 ( V_2 ) ;
}
int F_78 ( struct V_1 * V_2 ,
struct V_22 * V_11 ,
T_1 V_60 , T_1 V_101 )
{
struct V_33 * V_34 = F_26 ( V_11 ) ;
struct V_3 * V_4 = & V_34 -> V_93 ;
struct V_80 V_96 = {} ;
F_2 ( & V_2 -> V_86 ) ;
if ( V_4 -> V_9 ) {
F_16 ( V_2 , L_36 ) ;
return - V_116 ;
}
V_96 . V_51 = F_38 ( V_97 ) ;
V_96 . V_98 =
F_38 ( F_64 ( V_34 -> V_6 , V_34 -> V_99 ) ) ;
V_96 . V_6 = F_38 ( V_61 ) ;
V_96 . V_101 = F_38 ( V_101 ) ;
V_96 . V_104 = V_105 ;
V_96 . V_60 = F_38 ( V_60 ) ;
V_96 . V_107 = 1 ;
V_96 . V_106 = F_38 ( 1 ) ;
V_96 . V_108 = F_66 ( V_54 |
V_124 ) ;
return F_54 ( V_2 , V_11 , V_4 , & V_96 ) ;
}
