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
F_10 ( V_2 , & V_2 -> V_23 , true , V_24 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_14 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
F_14 () ;
V_26 = F_15 ( V_2 -> V_26 ) ;
if ( ! V_26 || ! V_26 -> V_27 )
goto V_28;
F_16 ( V_2 , L_1 ) ;
if ( ! F_17 ( V_26 ) ) {
F_18 ( V_2 , L_2 ) ;
goto V_28;
}
F_19 ( V_26 ) ;
F_20 () ;
F_21 ( V_2 -> V_26 , NULL ) ;
return;
V_28:
F_20 () ;
}
static bool F_22 ( struct V_1 * V_2 ,
struct V_25 * V_6 ,
const char * V_29 )
{
if ( V_6 -> type != V_30 )
return false ;
if ( V_6 -> V_31 . V_32 && V_6 -> V_31 . V_33 )
return false ;
if ( V_29 )
F_23 ( V_2 , L_3 , V_29 ) ;
F_24 ( V_2 , V_6 , V_29 ) ;
return true ;
}
static void
F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_34 * V_35 )
{
struct V_25 * V_6 = V_4 -> V_6 ;
struct V_36 * V_37 = F_26 ( V_6 ) ;
if ( ! V_35 -> V_17 )
F_16 ( V_2 , L_4 ) ;
switch ( V_4 -> V_6 -> type ) {
case V_38 :
if ( ! V_35 -> V_17 )
V_37 -> V_39 = true ;
F_13 ( V_2 ) ;
break;
case V_30 :
if ( ! V_35 -> V_17 ) {
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
struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_40 * V_41 ;
struct V_42 * V_43 ;
int V_44 ;
if ( ! F_31 ( V_2 -> V_45 , V_46 ) )
return;
V_41 = F_32 ( V_2 -> V_45 , V_46 ) ;
V_43 = ( void * ) V_41 -> V_47 ;
if ( ! F_33 ( & V_2 -> V_48 ,
F_34 ( V_4 -> V_6 ) ,
V_41 ) )
return;
for ( V_44 = 0 ; V_44 < F_35 ( V_43 -> V_49 ) ; V_44 ++ ) {
T_1 V_50 = F_36 ( V_43 -> V_49 [ V_44 ] . V_10 ) ;
T_1 V_51 =
F_36 ( V_43 -> V_49 [ V_44 ] . V_52 ) ;
T_1 V_53 =
F_36 ( V_43 -> V_49 [ V_44 ] . V_54 ) ;
if ( V_50 != V_4 -> V_10 ||
! ( V_51 & F_36 ( V_35 -> V_55 ) ) ||
! ( V_53 & F_7 ( F_36 ( V_35 -> V_17 ) ) ) )
continue;
F_37 ( & V_2 -> V_48 , V_41 ,
L_6 ,
V_4 -> V_10 ,
F_36 ( V_35 -> V_55 ) ,
F_36 ( V_35 -> V_17 ) ) ;
break;
}
}
static void F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_34 * V_35 )
{
F_2 ( & V_2 -> V_5 ) ;
F_16 ( V_2 , L_7 ,
F_36 ( V_35 -> V_56 ) ,
F_36 ( V_35 -> V_55 ) ) ;
F_30 ( V_2 , V_35 , V_4 ) ;
if ( ! F_36 ( V_35 -> V_17 ) ) {
const char * V_57 ;
if ( V_35 -> V_55 & F_39 ( V_58 ) )
V_57 = L_8 ;
else
V_57 = L_9 ;
F_16 ( V_2 , L_3 , V_57 ) ;
if ( F_22 ( V_2 , V_4 -> V_6 , V_57 ) ) {
F_1 ( V_2 , V_4 ) ;
return;
}
}
if ( F_36 ( V_35 -> V_55 ) & V_59 ) {
F_16 ( V_2 ,
L_10 ,
V_60 , V_4 -> V_61 ) ;
switch ( V_4 -> V_6 -> type ) {
case V_62 :
F_40 ( V_2 -> V_63 ) ;
F_11 ( V_2 ) ;
break;
case V_30 :
F_22 ( V_2 , V_4 -> V_6 ,
L_11 ) ;
break;
default:
break;
}
F_1 ( V_2 , V_4 ) ;
} else if ( F_36 ( V_35 -> V_55 ) & V_58 ) {
V_4 -> V_8 = true ;
V_4 -> V_61 = F_41 ( V_4 -> V_64 ) ;
if ( V_4 -> V_6 -> type == V_62 ) {
F_42 ( V_16 , & V_2 -> V_17 ) ;
F_43 ( V_2 , V_19 ) ;
F_44 ( V_2 -> V_63 ) ;
} else if ( V_4 -> V_10 == V_65 ) {
F_25 ( V_2 , V_4 , V_35 ) ;
}
} else {
F_18 ( V_2 , L_12 ) ;
}
}
static int F_45 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 , * V_66 ;
bool V_67 = false ;
F_46 (te_data, tmp, &mvm->aux_roc_te_list, list) {
if ( F_36 ( V_35 -> V_56 ) == V_4 -> V_9 ) {
V_67 = true ;
break;
}
}
if ( ! V_67 )
return - V_68 ;
F_30 ( V_2 , V_35 , V_4 ) ;
F_16 ( V_2 ,
L_13 ,
F_36 ( V_35 -> V_56 ) ,
F_36 ( V_35 -> V_55 ) , F_36 ( V_35 -> V_17 ) ) ;
if ( ! F_36 ( V_35 -> V_17 ) ||
F_36 ( V_35 -> V_55 ) == V_59 ) {
F_40 ( V_2 -> V_63 ) ;
F_11 ( V_2 ) ;
F_3 ( & V_4 -> V_7 ) ;
V_4 -> V_8 = false ;
V_4 -> V_6 = NULL ;
V_4 -> V_9 = 0 ;
V_4 -> V_10 = V_11 ;
} else if ( F_36 ( V_35 -> V_55 ) == V_58 ) {
F_42 ( V_20 , & V_2 -> V_17 ) ;
V_4 -> V_8 = true ;
F_43 ( V_2 , V_22 ) ;
F_44 ( V_2 -> V_63 ) ;
} else {
F_16 ( V_2 ,
L_14 ,
F_36 ( V_35 -> V_55 ) ) ;
return - V_68 ;
}
return 0 ;
}
void F_47 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
struct V_71 * V_72 = F_48 ( V_70 ) ;
struct V_34 * V_35 = ( void * ) V_72 -> V_47 ;
struct V_3 * V_4 , * V_66 ;
F_16 ( V_2 , L_15 ,
F_36 ( V_35 -> V_56 ) ,
F_36 ( V_35 -> V_55 ) ) ;
F_49 ( & V_2 -> V_5 ) ;
if ( ! F_45 ( V_2 , V_35 ) )
goto V_73;
F_46 (te_data, tmp, &mvm->time_event_list, list) {
if ( F_36 ( V_35 -> V_56 ) == V_4 -> V_9 )
F_38 ( V_2 , V_4 , V_35 ) ;
}
V_73:
F_50 ( & V_2 -> V_5 ) ;
}
static bool F_51 ( struct V_74 * V_75 ,
struct V_71 * V_72 , void * V_47 )
{
struct V_1 * V_2 =
F_5 ( V_75 , struct V_1 , V_75 ) ;
struct V_3 * V_4 = V_47 ;
struct V_34 * V_76 ;
int V_77 = F_52 ( V_72 ) ;
if ( F_53 ( V_72 -> V_78 . V_79 != V_80 ) )
return true ;
if ( F_29 ( V_77 != sizeof( * V_76 ) ) ) {
F_23 ( V_2 , L_16 ) ;
return true ;
}
V_76 = ( void * ) V_72 -> V_47 ;
if ( F_36 ( V_76 -> V_56 ) != V_4 -> V_9 )
return false ;
F_16 ( V_2 , L_17 ,
V_4 -> V_9 ) ;
if ( ! V_76 -> V_17 )
F_23 ( V_2 ,
L_18 ) ;
return true ;
}
static bool F_54 ( struct V_74 * V_75 ,
struct V_71 * V_72 , void * V_47 )
{
struct V_1 * V_2 =
F_5 ( V_75 , struct V_1 , V_75 ) ;
struct V_3 * V_4 = V_47 ;
struct V_81 * V_76 ;
int V_77 = F_52 ( V_72 ) ;
if ( F_53 ( V_72 -> V_78 . V_79 != V_82 ) )
return true ;
if ( F_29 ( V_77 != sizeof( * V_76 ) ) ) {
F_23 ( V_2 , L_19 ) ;
return true ;
}
V_76 = ( void * ) V_72 -> V_47 ;
if ( F_29 ( F_36 ( V_76 -> V_10 ) != V_4 -> V_10 ) )
return false ;
V_4 -> V_9 = F_36 ( V_76 -> V_56 ) ;
F_16 ( V_2 , L_20 ,
V_4 -> V_9 ) ;
return true ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_25 * V_6 ,
struct V_3 * V_4 ,
struct V_83 * V_84 )
{
static const T_2 V_85 [] = { V_82 } ;
struct V_86 V_87 ;
int V_88 ;
F_2 ( & V_2 -> V_89 ) ;
F_16 ( V_2 , L_21 ,
F_36 ( V_84 -> V_64 ) ) ;
F_49 ( & V_2 -> V_5 ) ;
if ( F_53 ( V_4 -> V_10 != V_11 ) ) {
F_50 ( & V_2 -> V_5 ) ;
return - V_90 ;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_64 = F_36 ( V_84 -> V_64 ) ;
V_4 -> V_10 = F_36 ( V_84 -> V_10 ) ;
F_56 ( & V_4 -> V_7 , & V_2 -> V_91 ) ;
F_50 ( & V_2 -> V_5 ) ;
F_57 ( & V_2 -> V_75 , & V_87 ,
V_85 ,
F_35 ( V_85 ) ,
F_54 , V_4 ) ;
V_88 = F_58 ( V_2 , V_82 , 0 ,
sizeof( * V_84 ) , V_84 ) ;
if ( V_88 ) {
F_23 ( V_2 , L_22 , V_88 ) ;
F_59 ( & V_2 -> V_75 , & V_87 ) ;
goto V_92;
}
V_88 = F_60 ( & V_2 -> V_75 , & V_87 , 1 ) ;
F_29 ( V_88 ) ;
if ( V_88 ) {
V_92:
F_49 ( & V_2 -> V_5 ) ;
F_1 ( V_2 , V_4 ) ;
F_50 ( & V_2 -> V_5 ) ;
}
return V_88 ;
}
void F_61 ( struct V_1 * V_2 ,
struct V_25 * V_6 ,
T_1 V_64 , T_1 V_93 ,
T_1 V_94 , bool V_95 )
{
struct V_36 * V_37 = F_26 ( V_6 ) ;
struct V_3 * V_4 = & V_37 -> V_96 ;
const T_2 V_97 [] = { V_80 } ;
struct V_86 V_98 ;
struct V_83 V_99 = {} ;
F_2 ( & V_2 -> V_89 ) ;
if ( V_4 -> V_8 &&
F_62 ( V_4 -> V_61 , F_41 ( V_93 ) ) ) {
F_16 ( V_2 , L_23 ,
F_63 ( V_4 -> V_61 - V_60 ) ) ;
return;
}
if ( V_4 -> V_8 ) {
F_16 ( V_2 , L_24 ,
V_4 -> V_9 ,
F_63 ( V_4 -> V_61 - V_60 ) ) ;
F_64 ( V_2 , V_6 ) ;
}
V_99 . V_55 = F_39 ( V_100 ) ;
V_99 . V_101 =
F_39 ( F_65 ( V_37 -> V_10 , V_37 -> V_102 ) ) ;
V_99 . V_10 = F_39 ( V_103 ) ;
V_99 . V_104 = F_39 ( 0 ) ;
V_99 . V_105 = V_106 ;
V_99 . V_94 = F_39 ( V_94 ) ;
V_99 . V_107 = F_39 ( 1 ) ;
V_99 . V_64 = F_39 ( V_64 ) ;
V_99 . V_108 = 1 ;
V_99 . V_109 = F_66 ( V_58 |
V_59 |
V_110 ) ;
if ( ! V_95 ) {
F_55 ( V_2 , V_6 , V_4 , & V_99 ) ;
return;
}
F_57 ( & V_2 -> V_75 , & V_98 ,
V_97 ,
F_35 ( V_97 ) ,
F_51 , V_4 ) ;
if ( F_55 ( V_2 , V_6 , V_4 , & V_99 ) ) {
F_23 ( V_2 , L_25 ) ;
F_59 ( & V_2 -> V_75 , & V_98 ) ;
} else if ( F_60 ( & V_2 -> V_75 , & V_98 ,
F_67 ( V_94 ) ) ) {
F_23 ( V_2 , L_26 ) ;
}
}
static bool F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 * V_9 )
{
T_1 V_10 ;
F_49 ( & V_2 -> V_5 ) ;
* V_9 = V_4 -> V_9 ;
V_10 = V_4 -> V_10 ;
F_1 ( V_2 , V_4 ) ;
F_50 ( & V_2 -> V_5 ) ;
if ( V_10 == V_11 ) {
F_16 ( V_2 , L_27 , * V_9 ) ;
return false ;
}
return true ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_3 * V_4 )
{
struct V_111 V_112 = {} ;
T_1 V_9 ;
int V_88 ;
if ( ! F_68 ( V_2 , V_4 , & V_9 ) )
return;
V_112 . V_113 = F_39 ( V_9 ) ;
V_112 . V_55 = F_39 ( V_114 ) ;
V_112 . V_101 =
F_39 ( F_65 ( V_37 -> V_10 , V_37 -> V_102 ) ) ;
F_16 ( V_2 , L_28 ,
F_36 ( V_112 . V_113 ) ) ;
V_88 = F_58 ( V_2 , V_115 , 0 ,
sizeof( V_112 ) , & V_112 ) ;
if ( F_53 ( V_88 ) )
return;
}
void F_70 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_3 * V_4 )
{
struct V_83 V_99 = {} ;
T_1 V_9 ;
int V_88 ;
if ( ! F_68 ( V_2 , V_4 , & V_9 ) )
return;
V_99 . V_10 = F_39 ( V_9 ) ;
V_99 . V_55 = F_39 ( V_114 ) ;
V_99 . V_101 =
F_39 ( F_65 ( V_37 -> V_10 , V_37 -> V_102 ) ) ;
F_16 ( V_2 , L_29 , F_36 ( V_99 . V_10 ) ) ;
V_88 = F_58 ( V_2 , V_82 , 0 ,
sizeof( V_99 ) , & V_99 ) ;
if ( F_53 ( V_88 ) )
return;
}
void F_64 ( struct V_1 * V_2 ,
struct V_25 * V_6 )
{
struct V_36 * V_37 = F_26 ( V_6 ) ;
struct V_3 * V_4 = & V_37 -> V_96 ;
T_1 V_10 ;
F_2 ( & V_2 -> V_89 ) ;
F_49 ( & V_2 -> V_5 ) ;
V_10 = V_4 -> V_10 ;
F_50 ( & V_2 -> V_5 ) ;
if ( V_10 != V_103 ) {
F_16 ( V_2 ,
L_30 ,
V_10 ) ;
return;
}
F_70 ( V_2 , V_37 , V_4 ) ;
}
int F_71 ( struct V_1 * V_2 , struct V_25 * V_6 ,
int V_64 , enum V_116 type )
{
struct V_36 * V_37 = F_26 ( V_6 ) ;
struct V_3 * V_4 = & V_37 -> V_96 ;
struct V_83 V_99 = {} ;
F_2 ( & V_2 -> V_89 ) ;
if ( V_4 -> V_8 ) {
F_18 ( V_2 , L_31 ) ;
return - V_117 ;
}
F_72 ( & V_2 -> V_14 ) ;
V_99 . V_55 = F_39 ( V_100 ) ;
V_99 . V_101 =
F_39 ( F_65 ( V_37 -> V_10 , V_37 -> V_102 ) ) ;
switch ( type ) {
case V_118 :
V_99 . V_10 = F_39 ( V_119 ) ;
break;
case V_120 :
V_99 . V_10 = F_39 ( V_121 ) ;
break;
default:
F_73 ( 1 , L_32 ) ;
return - V_68 ;
}
V_99 . V_104 = F_39 ( 0 ) ;
V_99 . V_107 = F_39 ( 1 ) ;
V_99 . V_105 = F_74 ( F_75 ( V_64 ) / 50 , V_122 ) ;
V_99 . V_94 = F_39 ( F_75 ( V_64 / 2 ) ) ;
V_99 . V_64 = F_39 ( F_75 ( V_64 ) ) ;
V_99 . V_108 = 1 ;
V_99 . V_109 = F_66 ( V_58 |
V_59 |
V_110 ) ;
return F_55 ( V_2 , V_6 , V_4 , & V_99 ) ;
}
static struct V_3 * F_76 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_89 ) ;
F_49 ( & V_2 -> V_5 ) ;
F_77 (te_data, &mvm->time_event_list, list) {
if ( V_4 -> V_6 -> type == V_62 )
goto V_123;
}
V_4 = F_78 ( & V_2 -> V_124 ,
struct V_3 ,
V_7 ) ;
V_123:
F_50 ( & V_2 -> V_5 ) ;
return V_4 ;
}
void F_79 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_9 ;
V_4 = F_76 ( V_2 ) ;
if ( V_4 )
F_68 ( V_2 , V_4 , & V_9 ) ;
}
void F_80 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
struct V_3 * V_4 ;
V_4 = F_76 ( V_2 ) ;
if ( ! V_4 ) {
F_18 ( V_2 , L_33 ) ;
return;
}
V_37 = F_26 ( V_4 -> V_6 ) ;
if ( V_4 -> V_6 -> type == V_62 )
F_70 ( V_2 , V_37 , V_4 ) ;
else
F_69 ( V_2 , V_37 , V_4 ) ;
F_11 ( V_2 ) ;
}
int F_81 ( struct V_1 * V_2 ,
struct V_25 * V_6 ,
T_1 V_64 , T_1 V_104 )
{
struct V_36 * V_37 = F_26 ( V_6 ) ;
struct V_3 * V_4 = & V_37 -> V_96 ;
struct V_83 V_99 = {} ;
F_2 ( & V_2 -> V_89 ) ;
if ( V_4 -> V_8 ) {
T_1 V_10 ;
F_49 ( & V_2 -> V_5 ) ;
V_10 = V_4 -> V_10 ;
F_50 ( & V_2 -> V_5 ) ;
if ( V_10 == V_65 ) {
F_16 ( V_2 , L_34 ) ;
return - V_117 ;
}
F_70 ( V_2 , V_37 , V_4 ) ;
}
V_99 . V_55 = F_39 ( V_100 ) ;
V_99 . V_101 =
F_39 ( F_65 ( V_37 -> V_10 , V_37 -> V_102 ) ) ;
V_99 . V_10 = F_39 ( V_65 ) ;
V_99 . V_104 = F_39 ( V_104 ) ;
V_99 . V_105 = V_106 ;
V_99 . V_64 = F_39 ( V_64 ) ;
V_99 . V_108 = 1 ;
V_99 . V_107 = F_39 ( 1 ) ;
V_99 . V_109 = F_66 ( V_58 |
V_125 ) ;
return F_55 ( V_2 , V_6 , V_4 , & V_99 ) ;
}
