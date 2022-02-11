int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_9 * V_10 ;
int V_11 ;
int V_12 = 0 ;
struct V_13 * V_14 = NULL ;
int V_15 ;
struct V_16 * V_17 ;
T_1 V_18 ;
V_14 = F_2 () ;
if ( ! V_14 ) {
V_12 = - V_19 ;
goto V_20;
}
V_4 . V_21 = 0 ;
V_4 . type = V_22 ;
V_4 . V_23 = 0 ;
V_12 = F_3 ( NULL , V_6 , & V_4 , V_14 , 0 , 0 ) ;
if ( V_12 ) {
V_24:
V_12 = 0 ;
V_8 -> V_25 =
V_26 ;
V_8 -> V_27 =
V_28 ;
V_8 -> V_25 = 0 ;
V_8 -> V_29 = 0 ;
V_8 -> V_30 = 0 ;
F_4 ( & V_8 -> V_31 , 0 ) ;
F_4 ( & V_8 -> V_32 , 0 ) ;
V_8 -> V_33 = 0 ;
V_8 -> V_34 = 0 ;
V_8 -> V_35 = 0 ;
V_8 -> V_36 = 0 ;
V_8 -> V_37 = NULL ;
V_8 -> V_38 = NULL ;
V_8 -> V_39 = 0 ;
V_8 -> V_40 = 0 ;
goto V_20;
}
V_11 = V_14 -> V_41 [ 0 ] ;
V_10 = V_14 -> V_42 [ 0 ] ;
V_15 = F_5 ( V_10 , V_11 ) ;
V_17 = F_6 ( V_10 , V_11 , struct V_16 ) ;
if ( V_15 != sizeof( struct V_16 ) ) {
F_7 ( V_2 ,
L_1 ) ;
goto V_24;
}
V_18 = F_8 ( V_10 , V_17 ) ;
V_8 -> V_27 =
F_9 ( V_10 , V_17 ) ;
V_8 -> V_25 = F_10 ( V_10 , V_17 ) ;
V_8 -> V_29 = F_11 ( V_10 , V_17 ) ;
V_8 -> V_30 =
F_12 ( V_10 , V_17 ) ;
F_4 ( & V_8 -> V_31 ,
F_13 ( V_10 , V_17 ) ) ;
F_4 ( & V_8 -> V_32 ,
F_14 ( V_10 , V_17 ) ) ;
V_8 -> V_33 = F_15 ( V_10 , V_17 ) ;
V_8 -> V_34 = V_8 -> V_33 ;
V_8 -> V_35 = V_8 -> V_33 ;
V_8 -> V_36 = F_16 ( V_10 , V_17 ) ;
V_8 -> V_39 = 1 ;
V_8 -> V_40 = 0 ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_44 :
case V_45 :
V_8 -> V_37 = NULL ;
V_8 -> V_38 = NULL ;
break;
case V_46 :
case V_47 :
V_8 -> V_37 = F_17 ( V_2 , V_18 ,
NULL , NULL ) ;
V_8 -> V_38 = F_17 ( V_2 ,
V_48 ,
NULL , NULL ) ;
if ( ! V_8 -> V_37 &&
! F_18 ( V_6 , V_49 ) ) {
V_12 = - V_50 ;
F_7 ( V_2 ,
L_2 ) ;
F_7 ( V_2 ,
L_3 ,
V_18 ) ;
}
if ( ! V_8 -> V_38 &&
! F_18 ( V_6 , V_49 ) ) {
V_12 = - V_50 ;
F_7 ( V_2 ,
L_2 ) ;
F_7 ( V_2 ,
L_4 ,
V_48 ) ;
}
if ( V_8 -> V_38 ) {
if ( V_8 -> V_37 ) {
V_8 -> V_38 -> V_51 =
V_8 -> V_37 -> V_51 ;
V_8 -> V_38 -> V_52 =
V_8 -> V_37 -> V_52 ;
V_8 -> V_38 -> V_53 =
V_8 -> V_37 -> V_53 ;
V_8 -> V_38 -> V_54 =
V_8 -> V_37 -> V_54 ;
V_8 -> V_38 -> V_55 =
V_8 -> V_37 -> V_55 ;
}
V_8 -> V_38 -> V_56 = 1 ;
F_19 ( V_2 ,
V_8 -> V_38 ) ;
}
break;
}
V_20:
F_20 ( V_14 ) ;
return V_12 ;
}
int F_21 ( struct V_57 * V_58 ,
struct V_1 * V_2 )
{
int V_12 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_13 * V_14 ;
struct V_3 V_4 ;
struct V_9 * V_10 ;
struct V_16 * V_17 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
F_22 ( V_8 , 0 ) ;
if ( ! V_8 -> V_39 ||
! V_8 -> V_40 ) {
F_23 ( V_8 , 0 ) ;
return 0 ;
}
F_23 ( V_8 , 0 ) ;
V_4 . V_21 = 0 ;
V_4 . type = V_22 ;
V_4 . V_23 = 0 ;
V_14 = F_2 () ;
if ( ! V_14 ) {
V_12 = - V_19 ;
goto V_20;
}
V_12 = F_3 ( V_58 , V_6 , & V_4 , V_14 , - 1 , 1 ) ;
if ( V_12 < 0 ) {
F_7 ( V_2 , L_5 ,
V_12 ) ;
goto V_20;
}
if ( V_12 == 0 &&
F_5 ( V_14 -> V_42 [ 0 ] , V_14 -> V_41 [ 0 ] ) < sizeof( * V_17 ) ) {
V_12 = F_24 ( V_58 , V_6 , V_14 ) ;
if ( V_12 != 0 ) {
F_7 ( V_2 , L_6 ,
V_12 ) ;
goto V_20;
}
V_12 = 1 ;
}
if ( V_12 == 1 ) {
F_25 ( V_14 ) ;
V_12 = F_26 ( V_58 , V_6 , V_14 ,
& V_4 , sizeof( * V_17 ) ) ;
if ( V_12 < 0 ) {
F_7 ( V_2 , L_7 ,
V_12 ) ;
goto V_20;
}
}
V_10 = V_14 -> V_42 [ 0 ] ;
V_17 = F_6 ( V_10 , V_14 -> V_41 [ 0 ] ,
struct V_16 ) ;
F_22 ( V_8 , 1 ) ;
if ( V_8 -> V_37 )
F_27 ( V_10 , V_17 ,
V_8 -> V_37 -> V_59 ) ;
else
F_27 ( V_10 , V_17 , ( T_1 ) - 1 ) ;
F_28 ( V_10 , V_17 ,
V_8 -> V_27 ) ;
F_29 ( V_10 , V_17 ,
V_8 -> V_25 ) ;
F_30 ( V_10 , V_17 , V_8 -> V_29 ) ;
F_31 ( V_10 , V_17 , V_8 -> V_30 ) ;
F_32 ( V_10 , V_17 ,
F_33 ( & V_8 -> V_31 ) ) ;
F_34 ( V_10 , V_17 ,
F_33 ( & V_8 -> V_32 ) ) ;
V_8 -> V_35 =
V_8 -> V_33 ;
F_35 ( V_10 , V_17 ,
V_8 -> V_35 ) ;
F_36 ( V_10 , V_17 ,
V_8 -> V_36 ) ;
V_8 -> V_40 = 0 ;
F_23 ( V_8 , 1 ) ;
F_37 ( V_10 ) ;
V_20:
F_20 ( V_14 ) ;
return V_12 ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
V_8 -> V_34 =
V_8 -> V_35 ;
}
int F_39 ( struct V_5 * V_60 , char * V_61 ,
T_1 V_62 , char * V_63 , int V_64 )
{
struct V_57 * V_58 ;
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_12 ;
struct V_65 * V_66 = NULL ;
struct V_65 * V_67 = NULL ;
F_40 ( & V_2 -> V_68 ) ;
V_12 = F_41 ( V_60 , V_62 ,
V_63 , & V_67 ) ;
if ( V_12 ) {
F_42 ( & V_2 -> V_68 ) ;
return V_12 ;
}
V_12 = F_43 ( V_60 , V_61 ,
V_67 , & V_66 ) ;
F_42 ( & V_2 -> V_68 ) ;
if ( V_12 )
return V_12 ;
V_58 = F_44 ( V_60 ) ;
if ( ! F_45 ( V_58 ) ) {
V_12 = F_46 ( V_58 , V_60 ) ;
if ( V_12 )
return V_12 ;
} else if ( F_47 ( V_58 ) != - V_69 ) {
return F_47 ( V_58 ) ;
}
F_22 ( V_8 , 1 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_44 :
case V_45 :
break;
case V_46 :
case V_47 :
V_12 = V_70 ;
goto V_71;
}
V_8 -> V_27 = V_64 ;
F_48 ( ! V_67 ) ;
V_8 -> V_37 = V_67 ;
F_48 ( ! V_66 ) ;
V_8 -> V_38 = V_66 ;
F_49 ( V_2 ,
L_8 ,
V_67 -> V_72 ? L_9 :
F_50 ( V_67 -> V_73 ) ,
V_67 -> V_59 ,
F_50 ( V_66 -> V_73 ) ) ;
V_8 -> V_25 = V_46 ;
V_8 -> V_29 = F_51 () ;
V_8 -> V_33 = 0 ;
V_8 -> V_34 = 0 ;
V_8 -> V_35 = 0 ;
V_8 -> V_36 = 0 ;
V_8 -> V_39 = 1 ;
V_8 -> V_40 = 1 ;
F_4 ( & V_8 -> V_31 , 0 ) ;
F_4 ( & V_8 -> V_32 , 0 ) ;
F_23 ( V_8 , 1 ) ;
V_12 = F_52 ( V_66 -> V_74 , V_66 ) ;
if ( V_12 )
F_53 ( V_2 , L_10 , V_12 ) ;
F_54 ( V_60 -> V_2 , - 1 , 0 , ( T_1 ) - 1 ) ;
V_58 = F_55 ( V_60 , 0 ) ;
if ( F_45 ( V_58 ) ) {
V_12 = F_47 ( V_58 ) ;
F_22 ( V_8 , 1 ) ;
goto V_71;
}
V_12 = F_46 ( V_58 , V_60 ) ;
F_48 ( V_12 ) ;
V_12 = F_56 ( V_2 , V_67 -> V_59 , 0 ,
F_57 ( V_67 ) ,
& V_8 -> V_75 , 0 , 1 ) ;
V_12 = F_58 ( V_2 , V_12 ) ;
if ( V_12 == - V_76 ) {
V_12 = V_77 ;
} else {
F_48 ( V_12 ) ;
}
return V_12 ;
V_71:
V_8 -> V_37 = NULL ;
V_8 -> V_38 = NULL ;
F_23 ( V_8 , 1 ) ;
F_59 ( V_2 , V_66 ) ;
return V_12 ;
}
int F_60 ( struct V_5 * V_60 ,
struct V_78 * args )
{
int V_12 ;
switch ( args -> V_79 . V_27 ) {
case V_80 :
case V_81 :
break;
default:
return - V_82 ;
}
if ( ( args -> V_79 . V_62 == 0 && args -> V_79 . V_63 [ 0 ] == '\0' ) ||
args -> V_79 . V_61 [ 0 ] == '\0' )
return - V_82 ;
V_12 = F_39 ( V_60 , args -> V_79 . V_61 ,
args -> V_79 . V_62 ,
args -> V_79 . V_63 ,
args -> V_79 . V_27 ) ;
args -> V_83 = V_12 ;
if ( V_12 == V_77 )
V_12 = 0 ;
return V_12 ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_62 ( V_84 , & V_2 -> V_85 ) ;
F_63 ( V_2 -> V_86 , ! F_64 (
& V_2 -> V_87 ) ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_66 ( V_84 , & V_2 -> V_85 ) ;
F_67 ( & V_2 -> V_86 ) ;
}
static int F_58 ( struct V_1 * V_2 ,
int V_88 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_65 * V_66 ;
struct V_65 * V_67 ;
struct V_5 * V_60 = V_2 -> V_89 ;
T_2 V_90 [ V_91 ] ;
struct V_57 * V_58 ;
int V_12 = 0 ;
F_40 ( & V_8 -> V_92 ) ;
F_22 ( V_8 , 0 ) ;
if ( V_8 -> V_25 !=
V_46 ) {
F_23 ( V_8 , 0 ) ;
F_42 ( & V_8 -> V_92 ) ;
return 0 ;
}
V_66 = V_8 -> V_38 ;
V_67 = V_8 -> V_37 ;
F_23 ( V_8 , 0 ) ;
V_12 = F_68 ( V_60 -> V_2 , 0 , - 1 ) ;
if ( V_12 ) {
F_42 ( & V_8 -> V_92 ) ;
return V_12 ;
}
F_54 ( V_60 -> V_2 , - 1 , 0 , ( T_1 ) - 1 ) ;
V_58 = F_55 ( V_60 , 0 ) ;
if ( F_45 ( V_58 ) ) {
F_42 ( & V_8 -> V_92 ) ;
return F_47 ( V_58 ) ;
}
V_12 = F_46 ( V_58 , V_60 ) ;
F_48 ( V_12 ) ;
F_40 ( & V_93 ) ;
F_40 ( & V_60 -> V_2 -> V_74 -> V_94 ) ;
F_40 ( & V_60 -> V_2 -> V_95 ) ;
F_22 ( V_8 , 1 ) ;
V_8 -> V_25 =
V_88 ? V_45
: V_44 ;
V_8 -> V_38 = NULL ;
V_8 -> V_37 = NULL ;
V_8 -> V_30 = F_51 () ;
V_8 -> V_40 = 1 ;
if ( ! V_88 ) {
F_69 ( V_2 ,
V_67 ,
V_66 ) ;
} else {
F_70 ( V_60 -> V_2 ,
L_11 ,
V_67 -> V_72 ? L_9 :
F_50 ( V_67 -> V_73 ) ,
V_67 -> V_59 ,
F_50 ( V_66 -> V_73 ) , V_88 ) ;
F_23 ( V_8 , 1 ) ;
F_42 ( & V_60 -> V_2 -> V_95 ) ;
F_42 ( & V_60 -> V_2 -> V_74 -> V_94 ) ;
F_42 ( & V_93 ) ;
if ( V_66 )
F_59 ( V_2 , V_66 ) ;
F_42 ( & V_8 -> V_92 ) ;
return V_88 ;
}
F_49 ( V_60 -> V_2 ,
L_12 ,
V_67 -> V_72 ? L_9 :
F_50 ( V_67 -> V_73 ) ,
V_67 -> V_59 ,
F_50 ( V_66 -> V_73 ) ) ;
V_66 -> V_56 = 0 ;
V_66 -> V_59 = V_67 -> V_59 ;
V_67 -> V_59 = V_48 ;
memcpy ( V_90 , V_66 -> V_96 , sizeof( V_90 ) ) ;
memcpy ( V_66 -> V_96 , V_67 -> V_96 , sizeof( V_66 -> V_96 ) ) ;
memcpy ( V_67 -> V_96 , V_90 , sizeof( V_67 -> V_96 ) ) ;
F_71 ( V_66 , V_67 -> V_51 ) ;
F_72 ( V_66 ,
V_67 -> V_52 ) ;
F_73 ( V_66 , V_67 -> V_54 ) ;
ASSERT ( F_74 ( & V_67 -> V_97 ) ) ;
V_66 -> V_53 = V_67 -> V_53 ;
V_66 -> V_55 = V_67 -> V_54 ;
F_75 ( V_2 , V_67 , V_66 ) ;
F_76 ( & V_66 -> V_98 , & V_2 -> V_74 -> V_99 ) ;
V_2 -> V_74 -> V_100 ++ ;
F_23 ( V_8 , 1 ) ;
F_61 ( V_2 ) ;
F_77 ( V_2 , V_67 ) ;
F_65 ( V_2 ) ;
F_42 ( & V_60 -> V_2 -> V_95 ) ;
F_42 ( & V_60 -> V_2 -> V_74 -> V_94 ) ;
F_42 ( & V_93 ) ;
F_78 ( V_2 -> V_74 , V_67 ) ;
F_79 ( V_2 , V_67 ) ;
V_58 = F_55 ( V_60 , 0 ) ;
if ( ! F_45 ( V_58 ) )
F_46 ( V_58 , V_60 ) ;
F_42 ( & V_8 -> V_92 ) ;
return 0 ;
}
static void F_69 (
struct V_1 * V_2 ,
struct V_65 * V_37 ,
struct V_65 * V_38 )
{
struct V_101 * V_102 = & V_2 -> V_103 . V_104 ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
T_1 V_79 = 0 ;
int V_109 ;
F_80 ( & V_102 -> V_110 ) ;
do {
V_106 = F_81 ( V_102 , V_79 , ( T_1 ) - 1 ) ;
if ( ! V_106 )
break;
V_108 = V_106 -> V_107 ;
for ( V_109 = 0 ; V_109 < V_108 -> V_111 ; V_109 ++ )
if ( V_37 == V_108 -> V_112 [ V_109 ] . V_113 )
V_108 -> V_112 [ V_109 ] . V_113 = V_38 ;
V_79 = V_106 -> V_79 + V_106 -> V_114 ;
F_82 ( V_106 ) ;
} while ( V_79 );
F_83 ( & V_102 -> V_110 ) ;
}
void F_84 ( struct V_1 * V_2 ,
struct V_78 * args )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_65 * V_37 ;
F_22 ( V_8 , 0 ) ;
args -> V_83 = V_115 ;
args -> V_116 . V_25 = V_8 -> V_25 ;
args -> V_116 . V_29 = V_8 -> V_29 ;
args -> V_116 . V_30 = V_8 -> V_30 ;
args -> V_116 . V_31 =
F_33 ( & V_8 -> V_31 ) ;
args -> V_116 . V_32 =
F_33 ( & V_8 -> V_32 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_45 :
args -> V_116 . V_117 = 0 ;
break;
case V_44 :
args -> V_116 . V_117 = 1000 ;
break;
case V_46 :
case V_47 :
V_37 = V_8 -> V_37 ;
args -> V_116 . V_117 = F_85 ( V_8 -> V_33 ,
F_85 ( F_57 ( V_37 ) , 1000 ) ) ;
break;
}
F_23 ( V_8 , 0 ) ;
}
int F_86 ( struct V_1 * V_2 ,
struct V_78 * args )
{
args -> V_83 = F_87 ( V_2 ) ;
return 0 ;
}
static T_1 F_87 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_65 * V_66 = NULL ;
struct V_57 * V_58 ;
struct V_5 * V_60 = V_2 -> V_89 ;
T_1 V_83 ;
int V_12 ;
if ( V_2 -> V_118 -> V_119 & V_120 )
return - V_121 ;
F_40 ( & V_8 -> V_92 ) ;
F_22 ( V_8 , 1 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_44 :
case V_45 :
V_83 = V_122 ;
F_23 ( V_8 , 1 ) ;
goto V_71;
case V_46 :
case V_47 :
V_83 = V_115 ;
V_66 = V_8 -> V_38 ;
V_8 -> V_38 = NULL ;
V_8 -> V_37 = NULL ;
break;
}
V_8 -> V_25 = V_45 ;
V_8 -> V_30 = F_51 () ;
V_8 -> V_40 = 1 ;
F_23 ( V_8 , 1 ) ;
F_88 ( V_2 ) ;
V_58 = F_55 ( V_60 , 0 ) ;
if ( F_45 ( V_58 ) ) {
F_42 ( & V_8 -> V_92 ) ;
return F_47 ( V_58 ) ;
}
V_12 = F_46 ( V_58 , V_60 ) ;
F_48 ( V_12 ) ;
if ( V_66 )
F_59 ( V_2 , V_66 ) ;
V_71:
F_42 ( & V_8 -> V_92 ) ;
return V_83 ;
}
void F_89 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
F_40 ( & V_8 -> V_92 ) ;
F_22 ( V_8 , 1 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_44 :
case V_45 :
case V_47 :
break;
case V_46 :
V_8 -> V_25 =
V_47 ;
V_8 -> V_30 = F_51 () ;
V_8 -> V_40 = 1 ;
F_90 ( V_2 , L_13 ) ;
break;
}
F_23 ( V_8 , 1 ) ;
F_42 ( & V_8 -> V_92 ) ;
}
int F_91 ( struct V_1 * V_2 )
{
struct V_123 * V_124 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
F_22 ( V_8 , 1 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_44 :
case V_45 :
F_23 ( V_8 , 1 ) ;
return 0 ;
case V_46 :
break;
case V_47 :
V_8 -> V_25 =
V_46 ;
break;
}
if ( ! V_8 -> V_38 || ! V_8 -> V_38 -> V_125 ) {
F_90 ( V_2 , L_14 ) ;
F_90 ( V_2 ,
L_15 ) ;
F_23 ( V_8 , 1 ) ;
return 0 ;
}
F_23 ( V_8 , 1 ) ;
F_48 ( F_92 (
& V_2 -> V_126 , 1 ) ) ;
V_124 = F_93 ( V_127 , V_2 , L_16 ) ;
return F_94 ( V_124 ) ;
}
static int V_127 ( void * V_128 )
{
struct V_1 * V_2 = V_128 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_78 * V_129 ;
T_1 V_130 ;
V_129 = F_95 ( sizeof( * V_129 ) , V_131 ) ;
if ( V_129 ) {
F_84 ( V_2 , V_129 ) ;
V_130 = V_129 -> V_116 . V_117 ;
F_96 ( V_129 ) ;
V_130 = F_85 ( V_130 , 10 ) ;
F_49 ( V_2 ,
L_17 ,
V_8 -> V_37 -> V_72 ? L_9 :
F_50 ( V_8 -> V_37 -> V_73 ) ,
V_8 -> V_37 -> V_59 ,
V_8 -> V_38 ?
F_50 ( V_8 -> V_38 -> V_73 ) :
L_18 ,
( unsigned int ) V_130 ) ;
}
F_97 ( V_2 ) ;
F_98 ( & V_2 -> V_126 , 0 ) ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_12 ;
V_12 = F_56 ( V_2 , V_8 -> V_37 -> V_59 ,
V_8 -> V_34 ,
F_57 ( V_8 -> V_37 ) ,
& V_8 -> V_75 , 0 , 1 ) ;
V_12 = F_58 ( V_2 , V_12 ) ;
F_48 ( V_12 ) ;
return 0 ;
}
int F_99 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_39 )
return 0 ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_44 :
case V_45 :
return 0 ;
case V_46 :
case V_47 :
break;
}
return 1 ;
}
void F_22 ( struct V_7 * V_8 , int V_132 )
{
if ( V_132 == 1 ) {
V_133:
F_63 ( V_8 -> V_134 ,
F_100 ( & V_8 -> V_135 ) == 0 ) ;
F_80 ( & V_8 -> V_110 ) ;
if ( F_100 ( & V_8 -> V_135 ) ) {
F_83 ( & V_8 -> V_110 ) ;
goto V_133;
}
} else {
F_101 ( & V_8 -> V_110 ) ;
F_102 ( & V_8 -> V_136 ) ;
}
}
void F_23 ( struct V_7 * V_8 , int V_132 )
{
if ( V_132 == 1 ) {
ASSERT ( F_100 ( & V_8 -> V_135 ) == 0 ) ;
F_83 ( & V_8 -> V_110 ) ;
} else {
ASSERT ( F_100 ( & V_8 -> V_136 ) > 0 ) ;
F_103 ( & V_8 -> V_136 ) ;
F_104 ( & V_8 -> V_110 ) ;
}
}
void F_105 (
struct V_7 * V_8 )
{
ASSERT ( F_100 ( & V_8 -> V_136 ) > 0 ) ;
F_102 ( & V_8 -> V_135 ) ;
F_104 ( & V_8 -> V_110 ) ;
}
void F_106 (
struct V_7 * V_8 )
{
ASSERT ( F_100 ( & V_8 -> V_136 ) > 0 ) ;
ASSERT ( F_100 ( & V_8 -> V_135 ) > 0 ) ;
F_101 ( & V_8 -> V_110 ) ;
if ( F_107 ( & V_8 -> V_135 ) &&
F_108 ( & V_8 -> V_134 ) )
F_67 ( & V_8 -> V_134 ) ;
}
void F_109 ( struct V_1 * V_2 )
{
F_110 ( & V_2 -> V_87 ) ;
}
void F_111 ( struct V_1 * V_2 , T_3 V_137 )
{
F_112 ( & V_2 -> V_87 , V_137 ) ;
if ( F_108 ( & V_2 -> V_86 ) )
F_67 ( & V_2 -> V_86 ) ;
}
void F_113 ( struct V_1 * V_2 )
{
while ( 1 ) {
F_110 ( & V_2 -> V_87 ) ;
if ( F_114 ( ! F_115 ( V_84 ,
& V_2 -> V_85 ) ) )
break;
F_116 ( V_2 ) ;
F_63 ( V_2 -> V_86 ,
! F_115 ( V_84 ,
& V_2 -> V_85 ) ) ;
}
}
