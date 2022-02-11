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
F_10 ( V_2 , V_15 , V_23 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_14 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
F_14 () ;
V_25 = F_15 ( V_2 -> V_25 ) ;
if ( ! V_25 || ! V_25 -> V_26 )
goto V_27;
F_16 ( V_2 , L_1 ) ;
if ( ! F_17 ( V_25 ) ) {
F_18 ( V_2 , L_2 ) ;
goto V_27;
}
F_19 ( V_25 ) ;
F_20 () ;
F_21 ( V_2 -> V_25 , NULL ) ;
return;
V_27:
F_20 () ;
}
static bool F_22 ( struct V_1 * V_2 ,
struct V_24 * V_6 ,
const char * V_28 )
{
if ( V_6 -> type != V_29 )
return false ;
if ( V_6 -> V_30 . V_31 && V_6 -> V_30 . V_32 )
return false ;
if ( V_28 )
F_23 ( V_2 , L_3 , V_28 ) ;
F_24 ( V_2 , V_6 , V_28 ) ;
return true ;
}
static void
F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_33 * V_34 )
{
struct V_24 * V_6 = V_4 -> V_6 ;
struct V_35 * V_36 = F_26 ( V_6 ) ;
if ( ! V_34 -> V_17 )
F_16 ( V_2 , L_4 ) ;
switch ( V_4 -> V_6 -> type ) {
case V_37 :
if ( ! V_34 -> V_17 )
V_36 -> V_38 = true ;
F_13 ( V_2 ) ;
break;
case V_29 :
if ( ! V_34 -> V_17 ) {
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
struct V_33 * V_34 ,
struct V_3 * V_4 )
{
struct V_39 * V_40 ;
struct V_41 * V_42 ;
int V_43 ;
if ( ! F_31 ( V_2 -> V_44 , V_45 ) )
return;
V_40 = F_32 ( V_2 -> V_44 , V_45 ) ;
V_42 = ( void * ) V_40 -> V_46 ;
if ( ! F_33 ( V_2 , V_4 -> V_6 , V_40 ) )
return;
for ( V_43 = 0 ; V_43 < F_34 ( V_42 -> V_47 ) ; V_43 ++ ) {
T_1 V_48 = F_35 ( V_42 -> V_47 [ V_43 ] . V_10 ) ;
T_1 V_49 =
F_35 ( V_42 -> V_47 [ V_43 ] . V_50 ) ;
T_1 V_51 =
F_35 ( V_42 -> V_47 [ V_43 ] . V_52 ) ;
if ( V_48 != V_4 -> V_10 ||
! ( V_49 & F_35 ( V_34 -> V_53 ) ) ||
! ( V_51 & F_7 ( F_35 ( V_34 -> V_17 ) ) ) )
continue;
F_36 ( V_2 , V_40 ,
L_6 ,
V_4 -> V_10 ,
F_35 ( V_34 -> V_53 ) ,
F_35 ( V_34 -> V_17 ) ) ;
break;
}
}
static void F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_33 * V_34 )
{
F_2 ( & V_2 -> V_5 ) ;
F_16 ( V_2 , L_7 ,
F_35 ( V_34 -> V_54 ) ,
F_35 ( V_34 -> V_53 ) ) ;
F_30 ( V_2 , V_34 , V_4 ) ;
if ( ! F_35 ( V_34 -> V_17 ) ) {
const char * V_55 ;
if ( V_34 -> V_53 & F_38 ( V_56 ) )
V_55 = L_8 ;
else
V_55 = L_9 ;
F_16 ( V_2 , L_3 , V_55 ) ;
if ( F_22 ( V_2 , V_4 -> V_6 , V_55 ) ) {
F_1 ( V_2 , V_4 ) ;
return;
}
}
if ( F_35 ( V_34 -> V_53 ) & V_57 ) {
F_16 ( V_2 ,
L_10 ,
V_58 , V_4 -> V_59 ) ;
switch ( V_4 -> V_6 -> type ) {
case V_60 :
F_39 ( V_2 -> V_61 ) ;
F_11 ( V_2 ) ;
break;
case V_29 :
F_22 ( V_2 , V_4 -> V_6 ,
L_11 ) ;
break;
default:
break;
}
F_1 ( V_2 , V_4 ) ;
} else if ( F_35 ( V_34 -> V_53 ) & V_56 ) {
V_4 -> V_8 = true ;
V_4 -> V_59 = F_40 ( V_4 -> V_62 ) ;
if ( V_4 -> V_6 -> type == V_60 ) {
F_41 ( V_16 , & V_2 -> V_17 ) ;
F_42 ( V_2 , V_19 ) ;
F_43 ( V_2 -> V_61 ) ;
} else if ( V_4 -> V_10 == V_63 ) {
F_25 ( V_2 , V_4 , V_34 ) ;
}
} else {
F_18 ( V_2 , L_12 ) ;
}
}
static int F_44 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_3 * V_4 , * V_64 ;
bool V_65 = false ;
F_45 (te_data, tmp, &mvm->aux_roc_te_list, list) {
if ( F_35 ( V_34 -> V_54 ) == V_4 -> V_9 ) {
V_65 = true ;
break;
}
}
if ( ! V_65 )
return - V_66 ;
F_30 ( V_2 , V_34 , V_4 ) ;
if ( ! F_35 ( V_34 -> V_17 ) ) {
F_16 ( V_2 ,
L_13 ,
( F_35 ( V_34 -> V_53 ) &
V_56 ) ? L_14 : L_15 ) ;
return - V_66 ;
}
F_16 ( V_2 ,
L_16 ,
F_35 ( V_34 -> V_54 ) ,
F_35 ( V_34 -> V_53 ) ) ;
if ( F_35 ( V_34 -> V_53 ) == V_57 ) {
F_39 ( V_2 -> V_61 ) ;
F_11 ( V_2 ) ;
F_3 ( & V_4 -> V_7 ) ;
V_4 -> V_8 = false ;
V_4 -> V_6 = NULL ;
V_4 -> V_9 = 0 ;
V_4 -> V_10 = V_11 ;
} else if ( F_35 ( V_34 -> V_53 ) == V_56 ) {
F_41 ( V_20 , & V_2 -> V_17 ) ;
V_4 -> V_8 = true ;
F_42 ( V_2 , V_22 ) ;
F_43 ( V_2 -> V_61 ) ;
} else {
F_16 ( V_2 ,
L_17 ,
F_35 ( V_34 -> V_53 ) ) ;
return - V_66 ;
}
return 0 ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
struct V_69 * V_70 = F_47 ( V_68 ) ;
struct V_33 * V_34 = ( void * ) V_70 -> V_46 ;
struct V_3 * V_4 , * V_64 ;
F_16 ( V_2 , L_18 ,
F_35 ( V_34 -> V_54 ) ,
F_35 ( V_34 -> V_53 ) ) ;
F_48 ( & V_2 -> V_5 ) ;
if ( ! F_44 ( V_2 , V_34 ) )
goto V_71;
F_45 (te_data, tmp, &mvm->time_event_list, list) {
if ( F_35 ( V_34 -> V_54 ) == V_4 -> V_9 )
F_37 ( V_2 , V_4 , V_34 ) ;
}
V_71:
F_49 ( & V_2 -> V_5 ) ;
}
static bool F_50 ( struct V_72 * V_73 ,
struct V_69 * V_70 , void * V_46 )
{
struct V_1 * V_2 =
F_5 ( V_73 , struct V_1 , V_73 ) ;
struct V_3 * V_4 = V_46 ;
struct V_33 * V_74 ;
int V_75 = F_51 ( V_70 ) ;
if ( F_52 ( V_70 -> V_76 . V_77 != V_78 ) )
return true ;
if ( F_29 ( V_75 != sizeof( * V_74 ) ) ) {
F_23 ( V_2 , L_19 ) ;
return true ;
}
V_74 = ( void * ) V_70 -> V_46 ;
if ( F_35 ( V_74 -> V_54 ) != V_4 -> V_9 )
return false ;
F_16 ( V_2 , L_20 ,
V_4 -> V_9 ) ;
if ( ! V_74 -> V_17 )
F_23 ( V_2 ,
L_21 ) ;
return true ;
}
static bool F_53 ( struct V_72 * V_73 ,
struct V_69 * V_70 , void * V_46 )
{
struct V_1 * V_2 =
F_5 ( V_73 , struct V_1 , V_73 ) ;
struct V_3 * V_4 = V_46 ;
struct V_79 * V_74 ;
int V_75 = F_51 ( V_70 ) ;
if ( F_52 ( V_70 -> V_76 . V_77 != V_80 ) )
return true ;
if ( F_29 ( V_75 != sizeof( * V_74 ) ) ) {
F_23 ( V_2 , L_22 ) ;
return true ;
}
V_74 = ( void * ) V_70 -> V_46 ;
if ( F_29 ( F_35 ( V_74 -> V_10 ) != V_4 -> V_10 ) )
return false ;
V_4 -> V_9 = F_35 ( V_74 -> V_54 ) ;
F_16 ( V_2 , L_23 ,
V_4 -> V_9 ) ;
return true ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_24 * V_6 ,
struct V_3 * V_4 ,
struct V_81 * V_82 )
{
static const T_2 V_83 [] = { V_80 } ;
struct V_84 V_85 ;
int V_86 ;
F_2 ( & V_2 -> V_87 ) ;
F_16 ( V_2 , L_24 ,
F_35 ( V_82 -> V_62 ) ) ;
F_48 ( & V_2 -> V_5 ) ;
if ( F_52 ( V_4 -> V_10 != V_11 ) ) {
F_49 ( & V_2 -> V_5 ) ;
return - V_88 ;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_62 = F_35 ( V_82 -> V_62 ) ;
V_4 -> V_10 = F_35 ( V_82 -> V_10 ) ;
F_55 ( & V_4 -> V_7 , & V_2 -> V_89 ) ;
F_49 ( & V_2 -> V_5 ) ;
F_56 ( & V_2 -> V_73 , & V_85 ,
V_83 ,
F_34 ( V_83 ) ,
F_53 , V_4 ) ;
V_86 = F_57 ( V_2 , V_80 , 0 ,
sizeof( * V_82 ) , V_82 ) ;
if ( V_86 ) {
F_23 ( V_2 , L_25 , V_86 ) ;
F_58 ( & V_2 -> V_73 , & V_85 ) ;
goto V_90;
}
V_86 = F_59 ( & V_2 -> V_73 , & V_85 , 1 ) ;
F_29 ( V_86 ) ;
if ( V_86 ) {
V_90:
F_48 ( & V_2 -> V_5 ) ;
F_1 ( V_2 , V_4 ) ;
F_49 ( & V_2 -> V_5 ) ;
}
return V_86 ;
}
void F_60 ( struct V_1 * V_2 ,
struct V_24 * V_6 ,
T_1 V_62 , T_1 V_91 ,
T_1 V_92 , bool V_93 )
{
struct V_35 * V_36 = F_26 ( V_6 ) ;
struct V_3 * V_4 = & V_36 -> V_94 ;
const T_2 V_95 [] = { V_78 } ;
struct V_84 V_96 ;
struct V_81 V_97 = {} ;
F_2 ( & V_2 -> V_87 ) ;
if ( V_4 -> V_8 &&
F_61 ( V_4 -> V_59 , F_40 ( V_91 ) ) ) {
F_16 ( V_2 , L_26 ,
F_62 ( V_4 -> V_59 - V_58 ) ) ;
return;
}
if ( V_4 -> V_8 ) {
F_16 ( V_2 , L_27 ,
V_4 -> V_9 ,
F_62 ( V_4 -> V_59 - V_58 ) ) ;
F_63 ( V_2 , V_6 ) ;
}
V_97 . V_53 = F_38 ( V_98 ) ;
V_97 . V_99 =
F_38 ( F_64 ( V_36 -> V_10 , V_36 -> V_100 ) ) ;
V_97 . V_10 = F_38 ( V_101 ) ;
V_97 . V_102 = F_38 ( 0 ) ;
V_97 . V_103 = V_104 ;
V_97 . V_92 = F_38 ( V_92 ) ;
V_97 . V_105 = F_38 ( 1 ) ;
V_97 . V_62 = F_38 ( V_62 ) ;
V_97 . V_106 = 1 ;
V_97 . V_107 = F_65 ( V_56 |
V_57 |
V_108 ) ;
if ( ! V_93 ) {
F_54 ( V_2 , V_6 , V_4 , & V_97 ) ;
return;
}
F_56 ( & V_2 -> V_73 , & V_96 ,
V_95 ,
F_34 ( V_95 ) ,
F_50 , V_4 ) ;
if ( F_54 ( V_2 , V_6 , V_4 , & V_97 ) ) {
F_23 ( V_2 , L_28 ) ;
F_58 ( & V_2 -> V_73 , & V_96 ) ;
} else if ( F_59 ( & V_2 -> V_73 , & V_96 ,
F_66 ( V_92 ) ) ) {
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
struct V_35 * V_36 ,
struct V_3 * V_4 )
{
struct V_109 V_110 = {} ;
T_1 V_9 ;
int V_86 ;
if ( ! F_67 ( V_2 , V_4 , & V_9 ) )
return;
V_110 . V_111 = F_38 ( V_9 ) ;
V_110 . V_53 = F_38 ( V_112 ) ;
V_110 . V_99 =
F_38 ( F_64 ( V_36 -> V_10 , V_36 -> V_100 ) ) ;
F_16 ( V_2 , L_31 ,
F_35 ( V_110 . V_111 ) ) ;
V_86 = F_57 ( V_2 , V_113 , 0 ,
sizeof( V_110 ) , & V_110 ) ;
if ( F_52 ( V_86 ) )
return;
}
void F_69 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_3 * V_4 )
{
struct V_81 V_97 = {} ;
T_1 V_9 ;
int V_86 ;
if ( ! F_67 ( V_2 , V_4 , & V_9 ) )
return;
V_97 . V_10 = F_38 ( V_9 ) ;
V_97 . V_53 = F_38 ( V_112 ) ;
V_97 . V_99 =
F_38 ( F_64 ( V_36 -> V_10 , V_36 -> V_100 ) ) ;
F_16 ( V_2 , L_32 , F_35 ( V_97 . V_10 ) ) ;
V_86 = F_57 ( V_2 , V_80 , 0 ,
sizeof( V_97 ) , & V_97 ) ;
if ( F_52 ( V_86 ) )
return;
}
void F_63 ( struct V_1 * V_2 ,
struct V_24 * V_6 )
{
struct V_35 * V_36 = F_26 ( V_6 ) ;
struct V_3 * V_4 = & V_36 -> V_94 ;
F_2 ( & V_2 -> V_87 ) ;
F_69 ( V_2 , V_36 , V_4 ) ;
}
int F_70 ( struct V_1 * V_2 , struct V_24 * V_6 ,
int V_62 , enum V_114 type )
{
struct V_35 * V_36 = F_26 ( V_6 ) ;
struct V_3 * V_4 = & V_36 -> V_94 ;
struct V_81 V_97 = {} ;
F_2 ( & V_2 -> V_87 ) ;
if ( V_4 -> V_8 ) {
F_18 ( V_2 , L_33 ) ;
return - V_115 ;
}
F_71 ( & V_2 -> V_14 ) ;
V_97 . V_53 = F_38 ( V_98 ) ;
V_97 . V_99 =
F_38 ( F_64 ( V_36 -> V_10 , V_36 -> V_100 ) ) ;
switch ( type ) {
case V_116 :
V_97 . V_10 = F_38 ( V_117 ) ;
break;
case V_118 :
V_97 . V_10 = F_38 ( V_119 ) ;
break;
default:
F_72 ( 1 , L_34 ) ;
return - V_66 ;
}
V_97 . V_102 = F_38 ( 0 ) ;
V_97 . V_105 = F_38 ( 1 ) ;
V_97 . V_103 = F_73 ( F_74 ( V_62 ) / 50 , V_120 ) ;
V_97 . V_92 = F_38 ( F_74 ( V_62 / 2 ) ) ;
V_97 . V_62 = F_38 ( F_74 ( V_62 ) ) ;
V_97 . V_106 = 1 ;
V_97 . V_107 = F_65 ( V_56 |
V_57 |
V_108 ) ;
return F_54 ( V_2 , V_6 , V_4 , & V_97 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = NULL ;
struct V_3 * V_4 ;
bool V_121 = false ;
F_2 ( & V_2 -> V_87 ) ;
F_48 ( & V_2 -> V_5 ) ;
F_76 (te_data, &mvm->time_event_list, list) {
if ( V_4 -> V_6 -> type == V_60 ) {
V_36 = F_26 ( V_4 -> V_6 ) ;
V_121 = true ;
goto V_122;
}
}
V_4 = F_77 ( & V_2 -> V_123 ,
struct V_3 ,
V_7 ) ;
if ( V_4 )
V_36 = F_26 ( V_4 -> V_6 ) ;
V_122:
F_49 ( & V_2 -> V_5 ) ;
if ( ! V_36 ) {
F_18 ( V_2 , L_35 ) ;
return;
}
if ( V_121 )
F_69 ( V_2 , V_36 , V_4 ) ;
else
F_68 ( V_2 , V_36 , V_4 ) ;
F_11 ( V_2 ) ;
}
int F_78 ( struct V_1 * V_2 ,
struct V_24 * V_6 ,
T_1 V_62 , T_1 V_102 )
{
struct V_35 * V_36 = F_26 ( V_6 ) ;
struct V_3 * V_4 = & V_36 -> V_94 ;
struct V_81 V_97 = {} ;
F_2 ( & V_2 -> V_87 ) ;
if ( V_4 -> V_8 ) {
F_16 ( V_2 , L_36 ) ;
return - V_115 ;
}
V_97 . V_53 = F_38 ( V_98 ) ;
V_97 . V_99 =
F_38 ( F_64 ( V_36 -> V_10 , V_36 -> V_100 ) ) ;
V_97 . V_10 = F_38 ( V_63 ) ;
V_97 . V_102 = F_38 ( V_102 ) ;
V_97 . V_103 = V_104 ;
V_97 . V_62 = F_38 ( V_62 ) ;
V_97 . V_106 = 1 ;
V_97 . V_105 = F_38 ( 1 ) ;
V_97 . V_107 = F_65 ( V_56 |
V_124 ) ;
return F_54 ( V_2 , V_6 , V_4 , & V_97 ) ;
}
