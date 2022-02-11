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
if ( F_10 ( V_2 ) )
F_11 ( V_2 , & V_2 -> V_23 , true , V_24 ) ;
else
F_12 ( V_2 , V_15 , V_24 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_14 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
F_16 () ;
V_26 = F_17 ( V_2 -> V_26 ) ;
if ( ! V_26 || ! V_26 -> V_27 )
goto V_28;
F_18 ( V_2 , L_1 ) ;
if ( ! F_19 ( V_26 ) ) {
F_20 ( V_2 , L_2 ) ;
goto V_28;
}
F_21 ( V_26 ) ;
F_22 () ;
F_23 ( V_2 -> V_26 , NULL ) ;
return;
V_28:
F_22 () ;
}
static bool F_24 ( struct V_1 * V_2 ,
struct V_25 * V_6 ,
const char * V_29 )
{
if ( V_6 -> type != V_30 )
return false ;
if ( V_6 -> V_31 . V_32 && V_6 -> V_31 . V_33 )
return false ;
if ( V_29 )
F_25 ( V_2 , L_3 , V_29 ) ;
F_26 ( V_2 , V_6 , V_29 ) ;
return true ;
}
static void
F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_34 * V_35 )
{
struct V_25 * V_6 = V_4 -> V_6 ;
struct V_36 * V_37 = F_28 ( V_6 ) ;
if ( ! V_35 -> V_17 )
F_18 ( V_2 , L_4 ) ;
switch ( V_4 -> V_6 -> type ) {
case V_38 :
if ( ! V_35 -> V_17 )
V_37 -> V_39 = true ;
F_15 ( V_2 ) ;
break;
case V_30 :
if ( ! V_35 -> V_17 ) {
F_26 ( V_2 , V_6 ,
L_5 ) ;
break;
}
F_29 ( V_2 , V_4 -> V_6 ) ;
F_30 ( V_4 -> V_6 , true ) ;
break;
default:
F_31 ( 1 ) ;
break;
}
F_1 ( V_2 , V_4 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_40 * V_41 ;
struct V_42 * V_43 ;
int V_44 ;
if ( ! F_33 ( V_2 -> V_45 , V_46 ) )
return;
V_41 = F_34 ( V_2 -> V_45 , V_46 ) ;
V_43 = ( void * ) V_41 -> V_47 ;
if ( ! F_35 ( V_2 , V_4 -> V_6 , V_41 ) )
return;
for ( V_44 = 0 ; V_44 < F_36 ( V_43 -> V_48 ) ; V_44 ++ ) {
T_1 V_49 = F_37 ( V_43 -> V_48 [ V_44 ] . V_10 ) ;
T_1 V_50 =
F_37 ( V_43 -> V_48 [ V_44 ] . V_51 ) ;
T_1 V_52 =
F_37 ( V_43 -> V_48 [ V_44 ] . V_53 ) ;
if ( V_49 != V_4 -> V_10 ||
! ( V_50 & F_37 ( V_35 -> V_54 ) ) ||
! ( V_52 & F_7 ( F_37 ( V_35 -> V_17 ) ) ) )
continue;
F_38 ( V_2 , V_41 ,
L_6 ,
V_4 -> V_10 ,
F_37 ( V_35 -> V_54 ) ,
F_37 ( V_35 -> V_17 ) ) ;
break;
}
}
static void F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_34 * V_35 )
{
F_2 ( & V_2 -> V_5 ) ;
F_18 ( V_2 , L_7 ,
F_37 ( V_35 -> V_55 ) ,
F_37 ( V_35 -> V_54 ) ) ;
F_32 ( V_2 , V_35 , V_4 ) ;
if ( ! F_37 ( V_35 -> V_17 ) ) {
const char * V_56 ;
if ( V_35 -> V_54 & F_40 ( V_57 ) )
V_56 = L_8 ;
else
V_56 = L_9 ;
F_18 ( V_2 , L_3 , V_56 ) ;
if ( F_24 ( V_2 , V_4 -> V_6 , V_56 ) ) {
F_1 ( V_2 , V_4 ) ;
return;
}
}
if ( F_37 ( V_35 -> V_54 ) & V_58 ) {
F_18 ( V_2 ,
L_10 ,
V_59 , V_4 -> V_60 ) ;
switch ( V_4 -> V_6 -> type ) {
case V_61 :
F_41 ( V_2 -> V_62 ) ;
F_13 ( V_2 ) ;
break;
case V_30 :
F_24 ( V_2 , V_4 -> V_6 ,
L_11 ) ;
break;
default:
break;
}
F_1 ( V_2 , V_4 ) ;
} else if ( F_37 ( V_35 -> V_54 ) & V_57 ) {
V_4 -> V_8 = true ;
V_4 -> V_60 = F_42 ( V_4 -> V_63 ) ;
if ( V_4 -> V_6 -> type == V_61 ) {
F_43 ( V_16 , & V_2 -> V_17 ) ;
F_44 ( V_2 , V_19 ) ;
F_45 ( V_2 -> V_62 ) ;
} else if ( V_4 -> V_10 == V_64 ) {
F_27 ( V_2 , V_4 , V_35 ) ;
}
} else {
F_20 ( V_2 , L_12 ) ;
}
}
static int F_46 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 , * V_65 ;
bool V_66 = false ;
F_47 (te_data, tmp, &mvm->aux_roc_te_list, list) {
if ( F_37 ( V_35 -> V_55 ) == V_4 -> V_9 ) {
V_66 = true ;
break;
}
}
if ( ! V_66 )
return - V_67 ;
F_32 ( V_2 , V_35 , V_4 ) ;
F_18 ( V_2 ,
L_13 ,
F_37 ( V_35 -> V_55 ) ,
F_37 ( V_35 -> V_54 ) , F_37 ( V_35 -> V_17 ) ) ;
if ( ! F_37 ( V_35 -> V_17 ) ||
F_37 ( V_35 -> V_54 ) == V_58 ) {
F_41 ( V_2 -> V_62 ) ;
F_13 ( V_2 ) ;
F_3 ( & V_4 -> V_7 ) ;
V_4 -> V_8 = false ;
V_4 -> V_6 = NULL ;
V_4 -> V_9 = 0 ;
V_4 -> V_10 = V_11 ;
} else if ( F_37 ( V_35 -> V_54 ) == V_57 ) {
F_43 ( V_20 , & V_2 -> V_17 ) ;
V_4 -> V_8 = true ;
F_44 ( V_2 , V_22 ) ;
F_45 ( V_2 -> V_62 ) ;
} else {
F_18 ( V_2 ,
L_14 ,
F_37 ( V_35 -> V_54 ) ) ;
return - V_67 ;
}
return 0 ;
}
void F_48 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_70 * V_71 = F_49 ( V_69 ) ;
struct V_34 * V_35 = ( void * ) V_71 -> V_47 ;
struct V_3 * V_4 , * V_65 ;
F_18 ( V_2 , L_15 ,
F_37 ( V_35 -> V_55 ) ,
F_37 ( V_35 -> V_54 ) ) ;
F_50 ( & V_2 -> V_5 ) ;
if ( ! F_46 ( V_2 , V_35 ) )
goto V_72;
F_47 (te_data, tmp, &mvm->time_event_list, list) {
if ( F_37 ( V_35 -> V_55 ) == V_4 -> V_9 )
F_39 ( V_2 , V_4 , V_35 ) ;
}
V_72:
F_51 ( & V_2 -> V_5 ) ;
}
static bool F_52 ( struct V_73 * V_74 ,
struct V_70 * V_71 , void * V_47 )
{
struct V_1 * V_2 =
F_5 ( V_74 , struct V_1 , V_74 ) ;
struct V_3 * V_4 = V_47 ;
struct V_34 * V_75 ;
int V_76 = F_53 ( V_71 ) ;
if ( F_54 ( V_71 -> V_77 . V_78 != V_79 ) )
return true ;
if ( F_31 ( V_76 != sizeof( * V_75 ) ) ) {
F_25 ( V_2 , L_16 ) ;
return true ;
}
V_75 = ( void * ) V_71 -> V_47 ;
if ( F_37 ( V_75 -> V_55 ) != V_4 -> V_9 )
return false ;
F_18 ( V_2 , L_17 ,
V_4 -> V_9 ) ;
if ( ! V_75 -> V_17 )
F_25 ( V_2 ,
L_18 ) ;
return true ;
}
static bool F_55 ( struct V_73 * V_74 ,
struct V_70 * V_71 , void * V_47 )
{
struct V_1 * V_2 =
F_5 ( V_74 , struct V_1 , V_74 ) ;
struct V_3 * V_4 = V_47 ;
struct V_80 * V_75 ;
int V_76 = F_53 ( V_71 ) ;
if ( F_54 ( V_71 -> V_77 . V_78 != V_81 ) )
return true ;
if ( F_31 ( V_76 != sizeof( * V_75 ) ) ) {
F_25 ( V_2 , L_19 ) ;
return true ;
}
V_75 = ( void * ) V_71 -> V_47 ;
if ( F_31 ( F_37 ( V_75 -> V_10 ) != V_4 -> V_10 ) )
return false ;
V_4 -> V_9 = F_37 ( V_75 -> V_55 ) ;
F_18 ( V_2 , L_20 ,
V_4 -> V_9 ) ;
return true ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_25 * V_6 ,
struct V_3 * V_4 ,
struct V_82 * V_83 )
{
static const T_2 V_84 [] = { V_81 } ;
struct V_85 V_86 ;
int V_87 ;
F_2 ( & V_2 -> V_88 ) ;
F_18 ( V_2 , L_21 ,
F_37 ( V_83 -> V_63 ) ) ;
F_50 ( & V_2 -> V_5 ) ;
if ( F_54 ( V_4 -> V_10 != V_11 ) ) {
F_51 ( & V_2 -> V_5 ) ;
return - V_89 ;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_63 = F_37 ( V_83 -> V_63 ) ;
V_4 -> V_10 = F_37 ( V_83 -> V_10 ) ;
F_57 ( & V_4 -> V_7 , & V_2 -> V_90 ) ;
F_51 ( & V_2 -> V_5 ) ;
F_58 ( & V_2 -> V_74 , & V_86 ,
V_84 ,
F_36 ( V_84 ) ,
F_55 , V_4 ) ;
V_87 = F_59 ( V_2 , V_81 , 0 ,
sizeof( * V_83 ) , V_83 ) ;
if ( V_87 ) {
F_25 ( V_2 , L_22 , V_87 ) ;
F_60 ( & V_2 -> V_74 , & V_86 ) ;
goto V_91;
}
V_87 = F_61 ( & V_2 -> V_74 , & V_86 , 1 ) ;
F_31 ( V_87 ) ;
if ( V_87 ) {
V_91:
F_50 ( & V_2 -> V_5 ) ;
F_1 ( V_2 , V_4 ) ;
F_51 ( & V_2 -> V_5 ) ;
}
return V_87 ;
}
void F_62 ( struct V_1 * V_2 ,
struct V_25 * V_6 ,
T_1 V_63 , T_1 V_92 ,
T_1 V_93 , bool V_94 )
{
struct V_36 * V_37 = F_28 ( V_6 ) ;
struct V_3 * V_4 = & V_37 -> V_95 ;
const T_2 V_96 [] = { V_79 } ;
struct V_85 V_97 ;
struct V_82 V_98 = {} ;
F_2 ( & V_2 -> V_88 ) ;
if ( V_4 -> V_8 &&
F_63 ( V_4 -> V_60 , F_42 ( V_92 ) ) ) {
F_18 ( V_2 , L_23 ,
F_64 ( V_4 -> V_60 - V_59 ) ) ;
return;
}
if ( V_4 -> V_8 ) {
F_18 ( V_2 , L_24 ,
V_4 -> V_9 ,
F_64 ( V_4 -> V_60 - V_59 ) ) ;
F_65 ( V_2 , V_6 ) ;
}
V_98 . V_54 = F_40 ( V_99 ) ;
V_98 . V_100 =
F_40 ( F_66 ( V_37 -> V_10 , V_37 -> V_101 ) ) ;
V_98 . V_10 = F_40 ( V_102 ) ;
V_98 . V_103 = F_40 ( 0 ) ;
V_98 . V_104 = V_105 ;
V_98 . V_93 = F_40 ( V_93 ) ;
V_98 . V_106 = F_40 ( 1 ) ;
V_98 . V_63 = F_40 ( V_63 ) ;
V_98 . V_107 = 1 ;
V_98 . V_108 = F_67 ( V_57 |
V_58 |
V_109 ) ;
if ( ! V_94 ) {
F_56 ( V_2 , V_6 , V_4 , & V_98 ) ;
return;
}
F_58 ( & V_2 -> V_74 , & V_97 ,
V_96 ,
F_36 ( V_96 ) ,
F_52 , V_4 ) ;
if ( F_56 ( V_2 , V_6 , V_4 , & V_98 ) ) {
F_25 ( V_2 , L_25 ) ;
F_60 ( & V_2 -> V_74 , & V_97 ) ;
} else if ( F_61 ( & V_2 -> V_74 , & V_97 ,
F_68 ( V_93 ) ) ) {
F_25 ( V_2 , L_26 ) ;
}
}
static bool F_69 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_9 )
{
T_1 V_10 ;
F_50 ( & V_2 -> V_5 ) ;
* V_9 = V_4 -> V_9 ;
V_10 = V_4 -> V_10 ;
F_1 ( V_2 , V_4 ) ;
F_51 ( & V_2 -> V_5 ) ;
if ( V_10 == V_11 ) {
F_18 ( V_2 , L_27 , * V_9 ) ;
return false ;
}
return true ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_3 * V_4 )
{
struct V_110 V_111 = {} ;
T_1 V_9 ;
int V_87 ;
if ( ! F_69 ( V_2 , V_4 , & V_9 ) )
return;
V_111 . V_112 = F_40 ( V_9 ) ;
V_111 . V_54 = F_40 ( V_113 ) ;
V_111 . V_100 =
F_40 ( F_66 ( V_37 -> V_10 , V_37 -> V_101 ) ) ;
F_18 ( V_2 , L_28 ,
F_37 ( V_111 . V_112 ) ) ;
V_87 = F_59 ( V_2 , V_114 , 0 ,
sizeof( V_111 ) , & V_111 ) ;
if ( F_54 ( V_87 ) )
return;
}
void F_71 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_3 * V_4 )
{
struct V_82 V_98 = {} ;
T_1 V_9 ;
int V_87 ;
if ( ! F_69 ( V_2 , V_4 , & V_9 ) )
return;
V_98 . V_10 = F_40 ( V_9 ) ;
V_98 . V_54 = F_40 ( V_113 ) ;
V_98 . V_100 =
F_40 ( F_66 ( V_37 -> V_10 , V_37 -> V_101 ) ) ;
F_18 ( V_2 , L_29 , F_37 ( V_98 . V_10 ) ) ;
V_87 = F_59 ( V_2 , V_81 , 0 ,
sizeof( V_98 ) , & V_98 ) ;
if ( F_54 ( V_87 ) )
return;
}
void F_65 ( struct V_1 * V_2 ,
struct V_25 * V_6 )
{
struct V_36 * V_37 = F_28 ( V_6 ) ;
struct V_3 * V_4 = & V_37 -> V_95 ;
F_2 ( & V_2 -> V_88 ) ;
F_71 ( V_2 , V_37 , V_4 ) ;
}
int F_72 ( struct V_1 * V_2 , struct V_25 * V_6 ,
int V_63 , enum V_115 type )
{
struct V_36 * V_37 = F_28 ( V_6 ) ;
struct V_3 * V_4 = & V_37 -> V_95 ;
struct V_82 V_98 = {} ;
F_2 ( & V_2 -> V_88 ) ;
if ( V_4 -> V_8 ) {
F_20 ( V_2 , L_30 ) ;
return - V_116 ;
}
F_73 ( & V_2 -> V_14 ) ;
V_98 . V_54 = F_40 ( V_99 ) ;
V_98 . V_100 =
F_40 ( F_66 ( V_37 -> V_10 , V_37 -> V_101 ) ) ;
switch ( type ) {
case V_117 :
V_98 . V_10 = F_40 ( V_118 ) ;
break;
case V_119 :
V_98 . V_10 = F_40 ( V_120 ) ;
break;
default:
F_74 ( 1 , L_31 ) ;
return - V_67 ;
}
V_98 . V_103 = F_40 ( 0 ) ;
V_98 . V_106 = F_40 ( 1 ) ;
V_98 . V_104 = F_75 ( F_76 ( V_63 ) / 50 , V_121 ) ;
V_98 . V_93 = F_40 ( F_76 ( V_63 / 2 ) ) ;
V_98 . V_63 = F_40 ( F_76 ( V_63 ) ) ;
V_98 . V_107 = 1 ;
V_98 . V_108 = F_67 ( V_57 |
V_58 |
V_109 ) ;
return F_56 ( V_2 , V_6 , V_4 , & V_98 ) ;
}
static struct V_3 * F_77 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_88 ) ;
F_50 ( & V_2 -> V_5 ) ;
F_78 (te_data, &mvm->time_event_list, list) {
if ( V_4 -> V_6 -> type == V_61 )
goto V_122;
}
V_4 = F_79 ( & V_2 -> V_123 ,
struct V_3 ,
V_7 ) ;
V_122:
F_51 ( & V_2 -> V_5 ) ;
return V_4 ;
}
void F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_9 ;
V_4 = F_77 ( V_2 ) ;
if ( V_4 )
F_69 ( V_2 , V_4 , & V_9 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
struct V_3 * V_4 ;
V_4 = F_77 ( V_2 ) ;
if ( ! V_4 ) {
F_20 ( V_2 , L_32 ) ;
return;
}
V_37 = F_28 ( V_4 -> V_6 ) ;
if ( V_4 -> V_6 -> type == V_61 )
F_71 ( V_2 , V_37 , V_4 ) ;
else
F_70 ( V_2 , V_37 , V_4 ) ;
F_13 ( V_2 ) ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_25 * V_6 ,
T_1 V_63 , T_1 V_103 )
{
struct V_36 * V_37 = F_28 ( V_6 ) ;
struct V_3 * V_4 = & V_37 -> V_95 ;
struct V_82 V_98 = {} ;
F_2 ( & V_2 -> V_88 ) ;
if ( V_4 -> V_8 ) {
F_18 ( V_2 , L_33 ) ;
return - V_116 ;
}
V_98 . V_54 = F_40 ( V_99 ) ;
V_98 . V_100 =
F_40 ( F_66 ( V_37 -> V_10 , V_37 -> V_101 ) ) ;
V_98 . V_10 = F_40 ( V_64 ) ;
V_98 . V_103 = F_40 ( V_103 ) ;
V_98 . V_104 = V_105 ;
V_98 . V_63 = F_40 ( V_63 ) ;
V_98 . V_107 = 1 ;
V_98 . V_106 = F_40 ( 1 ) ;
V_98 . V_108 = F_67 ( V_57 |
V_124 ) ;
return F_56 ( V_2 , V_6 , V_4 , & V_98 ) ;
}
