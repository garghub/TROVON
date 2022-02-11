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
}
V_8 -> V_38 -> V_54 = 1 ;
F_19 ( V_2 ,
V_8 -> V_38 ) ;
}
break;
}
V_20:
if ( V_14 )
F_20 ( V_14 ) ;
return V_12 ;
}
int F_21 ( struct V_55 * V_56 ,
struct V_1 * V_2 )
{
int V_12 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_13 * V_14 ;
struct V_3 V_4 ;
struct V_9 * V_10 ;
struct V_16 * V_17 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
F_22 ( V_8 ) ;
if ( ! V_8 -> V_39 ||
! V_8 -> V_40 ) {
F_23 ( V_8 ) ;
return 0 ;
}
F_23 ( V_8 ) ;
V_4 . V_21 = 0 ;
V_4 . type = V_22 ;
V_4 . V_23 = 0 ;
V_14 = F_2 () ;
if ( ! V_14 ) {
V_12 = - V_19 ;
goto V_20;
}
V_12 = F_3 ( V_56 , V_6 , & V_4 , V_14 , - 1 , 1 ) ;
if ( V_12 < 0 ) {
F_7 ( V_2 , L_5 ,
V_12 ) ;
goto V_20;
}
if ( V_12 == 0 &&
F_5 ( V_14 -> V_42 [ 0 ] , V_14 -> V_41 [ 0 ] ) < sizeof( * V_17 ) ) {
V_12 = F_24 ( V_56 , V_6 , V_14 ) ;
if ( V_12 != 0 ) {
F_7 ( V_2 , L_6 ,
V_12 ) ;
goto V_20;
}
V_12 = 1 ;
}
if ( V_12 == 1 ) {
F_25 ( V_14 ) ;
V_12 = F_26 ( V_56 , V_6 , V_14 ,
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
F_22 ( V_8 ) ;
if ( V_8 -> V_37 )
F_27 ( V_10 , V_17 ,
V_8 -> V_37 -> V_57 ) ;
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
F_23 ( V_8 ) ;
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
int F_39 ( struct V_5 * V_58 ,
struct V_59 * args )
{
struct V_55 * V_56 ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_12 ;
struct V_60 * V_61 = NULL ;
struct V_60 * V_62 = NULL ;
if ( F_40 ( V_2 , V_63 ) ) {
F_7 ( V_2 , L_8 ) ;
return - V_64 ;
}
switch ( args -> V_65 . V_27 ) {
case V_66 :
case V_67 :
break;
default:
return - V_64 ;
}
if ( ( args -> V_65 . V_68 == 0 && args -> V_65 . V_69 [ 0 ] == '\0' ) ||
args -> V_65 . V_70 [ 0 ] == '\0' )
return - V_64 ;
F_41 ( & V_2 -> V_71 ) ;
V_12 = F_42 ( V_58 , args -> V_65 . V_70 ,
& V_61 ) ;
if ( V_12 ) {
F_43 ( V_2 , L_9 ,
args -> V_65 . V_70 ) ;
F_44 ( & V_2 -> V_71 ) ;
return - V_64 ;
}
V_12 = F_45 ( V_58 , args -> V_65 . V_68 ,
args -> V_65 . V_69 ,
& V_62 ) ;
F_44 ( & V_2 -> V_71 ) ;
if ( V_12 ) {
V_12 = - V_64 ;
goto V_72;
}
if ( V_61 -> V_51 < V_62 -> V_51 ) {
F_43 ( V_2 , L_10 ) ;
V_12 = - V_64 ;
goto V_72;
}
F_22 ( V_8 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_44 :
case V_45 :
break;
case V_46 :
case V_47 :
args -> V_73 = V_74 ;
goto V_75;
}
V_8 -> V_27 =
args -> V_65 . V_27 ;
F_46 ( ! V_62 ) ;
V_8 -> V_37 = V_62 ;
F_46 ( ! V_61 ) ;
V_8 -> V_38 = V_61 ;
F_47 ( V_76
L_11 ,
V_62 -> V_77 ? L_12 :
F_48 ( V_62 -> V_78 ) ,
V_62 -> V_57 ,
F_48 ( V_61 -> V_78 ) ) ;
V_61 -> V_51 = V_62 -> V_51 ;
V_61 -> V_52 = V_62 -> V_52 ;
V_61 -> V_53 = V_62 -> V_53 ;
V_8 -> V_25 = V_46 ;
V_8 -> V_29 = F_49 () ;
V_8 -> V_33 = 0 ;
V_8 -> V_34 = 0 ;
V_8 -> V_35 = 0 ;
V_8 -> V_36 = 0 ;
V_8 -> V_39 = 1 ;
V_8 -> V_40 = 1 ;
args -> V_73 = V_79 ;
F_23 ( V_8 ) ;
F_50 ( V_58 -> V_2 , - 1 ) ;
V_56 = F_51 ( V_58 , 0 ) ;
if ( F_52 ( V_56 ) ) {
V_12 = F_53 ( V_56 ) ;
F_22 ( V_8 ) ;
goto V_75;
}
V_12 = F_54 ( V_56 , V_58 ) ;
F_46 ( V_12 ) ;
V_12 = F_55 ( V_2 , V_62 -> V_57 , 0 ,
V_62 -> V_51 ,
& V_8 -> V_80 , 0 , 1 ) ;
V_12 = F_56 ( V_58 -> V_2 , V_12 ) ;
F_46 ( V_12 ) ;
return 0 ;
V_75:
V_8 -> V_37 = NULL ;
V_8 -> V_38 = NULL ;
F_23 ( V_8 ) ;
V_72:
if ( V_61 )
F_57 ( V_2 , V_61 ) ;
return V_12 ;
}
static void F_58 ( struct V_1 * V_2 )
{
T_2 V_81 ;
F_59 ( V_82 ) ;
F_60 ( V_83 , & V_2 -> V_84 ) ;
do {
F_61 ( & V_2 -> V_85 , & V_82 ,
V_86 ) ;
V_81 = F_62 ( & V_2 -> V_87 ) ;
if ( V_81 )
F_63 () ;
F_64 ( & V_2 -> V_85 , & V_82 ) ;
} while ( V_81 );
}
static void F_65 ( struct V_1 * V_2 )
{
F_66 ( V_83 , & V_2 -> V_84 ) ;
if ( F_67 ( & V_2 -> V_85 ) )
F_68 ( & V_2 -> V_85 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
int V_88 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_60 * V_61 ;
struct V_60 * V_62 ;
struct V_5 * V_58 = V_2 -> V_89 ;
T_3 V_90 [ V_91 ] ;
struct V_55 * V_56 ;
int V_12 = 0 ;
F_41 ( & V_8 -> V_92 ) ;
F_22 ( V_8 ) ;
if ( V_8 -> V_25 !=
V_46 ) {
F_23 ( V_8 ) ;
F_44 ( & V_8 -> V_92 ) ;
return 0 ;
}
V_61 = V_8 -> V_38 ;
V_62 = V_8 -> V_37 ;
F_23 ( V_8 ) ;
V_12 = F_69 ( V_58 -> V_2 , 0 , - 1 ) ;
if ( V_12 ) {
F_44 ( & V_8 -> V_92 ) ;
return V_12 ;
}
F_50 ( V_58 -> V_2 , - 1 ) ;
V_56 = F_51 ( V_58 , 0 ) ;
if ( F_52 ( V_56 ) ) {
F_44 ( & V_8 -> V_92 ) ;
return F_53 ( V_56 ) ;
}
V_12 = F_54 ( V_56 , V_58 ) ;
F_46 ( V_12 ) ;
F_41 ( & V_58 -> V_2 -> V_93 ) ;
F_41 ( & V_58 -> V_2 -> V_94 -> V_95 ) ;
F_22 ( V_8 ) ;
V_8 -> V_25 =
V_88 ? V_45
: V_44 ;
V_8 -> V_38 = NULL ;
V_8 -> V_37 = NULL ;
V_8 -> V_30 = F_49 () ;
V_8 -> V_40 = 1 ;
if ( ! V_88 ) {
F_70 ( V_2 ,
V_62 ,
V_61 ) ;
} else {
F_47 ( V_96
L_13 ,
V_62 -> V_77 ? L_12 :
F_48 ( V_62 -> V_78 ) ,
V_62 -> V_57 ,
F_48 ( V_61 -> V_78 ) , V_88 ) ;
F_23 ( V_8 ) ;
F_44 ( & V_58 -> V_2 -> V_94 -> V_95 ) ;
F_44 ( & V_58 -> V_2 -> V_93 ) ;
if ( V_61 )
F_57 ( V_2 , V_61 ) ;
F_44 ( & V_8 -> V_92 ) ;
return 0 ;
}
F_47 ( V_76
L_14 ,
V_62 -> V_77 ? L_12 :
F_48 ( V_62 -> V_78 ) ,
V_62 -> V_57 ,
F_48 ( V_61 -> V_78 ) ) ;
V_61 -> V_54 = 0 ;
V_61 -> V_57 = V_62 -> V_57 ;
V_62 -> V_57 = V_48 ;
V_61 -> V_53 = V_62 -> V_53 ;
memcpy ( V_90 , V_61 -> V_97 , sizeof( V_90 ) ) ;
memcpy ( V_61 -> V_97 , V_62 -> V_97 , sizeof( V_61 -> V_97 ) ) ;
memcpy ( V_62 -> V_97 , V_90 , sizeof( V_62 -> V_97 ) ) ;
V_61 -> V_51 = V_62 -> V_51 ;
V_61 -> V_52 = V_62 -> V_52 ;
V_61 -> V_53 = V_62 -> V_53 ;
if ( V_2 -> V_98 -> V_99 == V_62 -> V_100 )
V_2 -> V_98 -> V_99 = V_61 -> V_100 ;
if ( V_2 -> V_94 -> V_101 == V_62 -> V_100 )
V_2 -> V_94 -> V_101 = V_61 -> V_100 ;
F_71 ( & V_61 -> V_102 , & V_2 -> V_94 -> V_103 ) ;
F_58 ( V_2 ) ;
F_72 ( V_2 , V_62 ) ;
F_65 ( V_2 ) ;
F_23 ( V_8 ) ;
F_44 ( & V_58 -> V_2 -> V_94 -> V_95 ) ;
F_44 ( & V_58 -> V_2 -> V_93 ) ;
V_56 = F_51 ( V_58 , 0 ) ;
if ( ! F_52 ( V_56 ) )
F_54 ( V_56 , V_58 ) ;
F_44 ( & V_8 -> V_92 ) ;
return 0 ;
}
static void F_70 (
struct V_1 * V_2 ,
struct V_60 * V_37 ,
struct V_60 * V_38 )
{
struct V_104 * V_105 = & V_2 -> V_106 . V_107 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
T_1 V_65 = 0 ;
int V_112 ;
F_73 ( & V_105 -> V_113 ) ;
do {
V_109 = F_74 ( V_105 , V_65 , ( T_1 ) - 1 ) ;
if ( ! V_109 )
break;
V_111 = (struct V_110 * ) V_109 -> V_100 ;
for ( V_112 = 0 ; V_112 < V_111 -> V_114 ; V_112 ++ )
if ( V_37 == V_111 -> V_115 [ V_112 ] . V_116 )
V_111 -> V_115 [ V_112 ] . V_116 = V_38 ;
V_65 = V_109 -> V_65 + V_109 -> V_117 ;
F_75 ( V_109 ) ;
} while ( V_65 );
F_76 ( & V_105 -> V_113 ) ;
}
static int F_45 ( struct V_5 * V_58 , T_1 V_68 ,
char * V_69 ,
struct V_60 * * V_118 )
{
int V_12 ;
if ( V_68 ) {
V_12 = 0 ;
* V_118 = F_17 ( V_58 -> V_2 , V_68 , NULL ,
NULL ) ;
if ( ! * V_118 )
V_12 = - V_119 ;
} else {
V_12 = F_77 ( V_58 , V_69 ,
V_118 ) ;
}
return V_12 ;
}
void F_78 ( struct V_1 * V_2 ,
struct V_59 * args )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
F_22 ( V_8 ) ;
args -> V_73 = V_79 ;
args -> V_120 . V_25 = V_8 -> V_25 ;
args -> V_120 . V_29 = V_8 -> V_29 ;
args -> V_120 . V_30 = V_8 -> V_30 ;
args -> V_120 . V_31 =
F_33 ( & V_8 -> V_31 ) ;
args -> V_120 . V_32 =
F_33 ( & V_8 -> V_32 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_45 :
args -> V_120 . V_121 = 0 ;
break;
case V_44 :
args -> V_120 . V_121 = 1000 ;
break;
case V_46 :
case V_47 :
args -> V_120 . V_121 = F_79 ( V_8 -> V_33 ,
F_79 ( V_8 -> V_37 -> V_51 , 1000 ) ) ;
break;
}
F_23 ( V_8 ) ;
}
int F_80 ( struct V_1 * V_2 ,
struct V_59 * args )
{
args -> V_73 = F_81 ( V_2 ) ;
return 0 ;
}
static T_1 F_81 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_60 * V_61 = NULL ;
struct V_55 * V_56 ;
struct V_5 * V_58 = V_2 -> V_89 ;
T_1 V_73 ;
int V_12 ;
if ( V_2 -> V_98 -> V_122 & V_123 )
return - V_124 ;
F_41 ( & V_8 -> V_92 ) ;
F_22 ( V_8 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_44 :
case V_45 :
V_73 = V_125 ;
F_23 ( V_8 ) ;
goto V_75;
case V_46 :
case V_47 :
V_73 = V_79 ;
V_61 = V_8 -> V_38 ;
V_8 -> V_38 = NULL ;
V_8 -> V_37 = NULL ;
break;
}
V_8 -> V_25 = V_45 ;
V_8 -> V_30 = F_49 () ;
V_8 -> V_40 = 1 ;
F_23 ( V_8 ) ;
F_82 ( V_2 ) ;
V_56 = F_51 ( V_58 , 0 ) ;
if ( F_52 ( V_56 ) ) {
F_44 ( & V_8 -> V_92 ) ;
return F_53 ( V_56 ) ;
}
V_12 = F_54 ( V_56 , V_58 ) ;
F_46 ( V_12 ) ;
if ( V_61 )
F_57 ( V_2 , V_61 ) ;
V_75:
F_44 ( & V_8 -> V_92 ) ;
return V_73 ;
}
void F_83 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
F_41 ( & V_8 -> V_92 ) ;
F_22 ( V_8 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_44 :
case V_45 :
case V_47 :
break;
case V_46 :
V_8 -> V_25 =
V_47 ;
V_8 -> V_30 = F_49 () ;
V_8 -> V_40 = 1 ;
F_84 ( V_2 , L_15 ) ;
break;
}
F_23 ( V_8 ) ;
F_44 ( & V_8 -> V_92 ) ;
}
int F_85 ( struct V_1 * V_2 )
{
struct V_126 * V_127 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
F_22 ( V_8 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_44 :
case V_45 :
F_23 ( V_8 ) ;
return 0 ;
case V_46 :
break;
case V_47 :
V_8 -> V_25 =
V_46 ;
break;
}
if ( ! V_8 -> V_38 || ! V_8 -> V_38 -> V_100 ) {
F_84 ( V_2 , L_16 ) ;
F_84 ( V_2 ,
L_17 ) ;
F_23 ( V_8 ) ;
return 0 ;
}
F_23 ( V_8 ) ;
F_46 ( F_86 (
& V_2 -> V_128 , 1 ) ) ;
V_127 = F_87 ( V_129 , V_2 , L_18 ) ;
return F_88 ( V_127 ) ;
}
static int V_129 ( void * V_130 )
{
struct V_1 * V_2 = V_130 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_59 * V_131 ;
T_1 V_132 ;
V_131 = F_89 ( sizeof( * V_131 ) , V_133 ) ;
if ( V_131 ) {
F_78 ( V_2 , V_131 ) ;
V_132 = V_131 -> V_120 . V_121 ;
F_90 ( V_131 ) ;
F_91 ( V_132 , 10 ) ;
F_47 ( V_76
L_19 ,
V_8 -> V_37 -> V_77 ? L_12 :
F_48 ( V_8 -> V_37 -> V_78 ) ,
V_8 -> V_37 -> V_57 ,
V_8 -> V_38 ?
F_48 ( V_8 -> V_38 -> V_78 ) :
L_20 ,
( unsigned int ) V_132 ) ;
}
F_92 ( V_2 ) ;
F_93 ( & V_2 -> V_128 , 0 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_12 ;
V_12 = F_55 ( V_2 , V_8 -> V_37 -> V_57 ,
V_8 -> V_34 ,
V_8 -> V_37 -> V_51 ,
& V_8 -> V_80 , 0 , 1 ) ;
V_12 = F_56 ( V_2 , V_12 ) ;
F_46 ( V_12 ) ;
return 0 ;
}
int F_94 ( struct V_7 * V_8 )
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
void F_22 ( struct V_7 * V_8 )
{
if ( F_95 ( & V_8 -> V_134 ) == 0 ) {
V_135:
F_41 ( & V_8 -> V_113 ) ;
F_41 ( & V_8 -> V_136 ) ;
V_8 -> V_137 = V_138 -> V_139 ;
F_96 ( & V_8 -> V_134 ) ;
F_44 ( & V_8 -> V_136 ) ;
return;
}
F_41 ( & V_8 -> V_136 ) ;
if ( F_95 ( & V_8 -> V_134 ) > 0 &&
V_8 -> V_137 == V_138 -> V_139 ) {
F_46 ( ! F_97 ( & V_8 -> V_113 ) ) ;
F_96 ( & V_8 -> V_134 ) ;
F_44 ( & V_8 -> V_136 ) ;
return;
}
F_44 ( & V_8 -> V_136 ) ;
goto V_135;
}
void F_23 ( struct V_7 * V_8 )
{
F_46 ( ! F_97 ( & V_8 -> V_113 ) ) ;
F_41 ( & V_8 -> V_136 ) ;
F_46 ( F_95 ( & V_8 -> V_134 ) < 1 ) ;
F_46 ( V_8 -> V_137 != V_138 -> V_139 ) ;
F_98 ( & V_8 -> V_134 ) ;
if ( F_95 ( & V_8 -> V_134 ) == 0 ) {
V_8 -> V_137 = 0 ;
F_44 ( & V_8 -> V_136 ) ;
F_44 ( & V_8 -> V_113 ) ;
} else {
F_44 ( & V_8 -> V_136 ) ;
}
}
void F_99 ( struct V_1 * V_2 )
{
F_100 ( & V_2 -> V_87 ) ;
}
void F_101 ( struct V_1 * V_2 )
{
F_102 ( & V_2 -> V_87 ) ;
if ( F_67 ( & V_2 -> V_85 ) )
F_68 ( & V_2 -> V_85 ) ;
}
void F_103 ( struct V_1 * V_2 )
{
F_59 ( V_82 ) ;
V_140:
F_100 ( & V_2 -> V_87 ) ;
if ( F_104 ( V_83 , & V_2 -> V_84 ) ) {
F_101 ( V_2 ) ;
F_105 ( V_2 -> V_85 ,
! F_104 ( V_83 ,
& V_2 -> V_84 ) ) ;
goto V_140;
}
}
