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
F_7 ( L_1 ) ;
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
F_7 ( L_2 L_3 ,
( unsigned long long ) V_18 ) ;
}
if ( ! V_8 -> V_38 &&
! F_18 ( V_6 , V_49 ) ) {
V_12 = - V_50 ;
F_7 ( L_2 L_4 ,
( unsigned long long ) V_48 ) ;
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
F_7 ( L_5 ,
V_12 ) ;
goto V_20;
}
if ( V_12 == 0 &&
F_5 ( V_14 -> V_42 [ 0 ] , V_14 -> V_41 [ 0 ] ) < sizeof( * V_17 ) ) {
V_12 = F_24 ( V_56 , V_6 , V_14 ) ;
if ( V_12 != 0 ) {
F_7 ( L_6 ,
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
F_7 ( L_7 ,
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
static T_1 F_39 ( void )
{
struct V_58 V_59 = V_60 ;
return V_59 . V_61 ;
}
int F_40 ( struct V_5 * V_62 ,
struct V_63 * args )
{
struct V_55 * V_56 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_12 ;
struct V_64 * V_65 = NULL ;
struct V_64 * V_66 = NULL ;
switch ( args -> V_67 . V_27 ) {
case V_68 :
case V_69 :
break;
default:
return - V_70 ;
}
if ( ( args -> V_67 . V_71 == 0 && args -> V_67 . V_72 [ 0 ] == '\0' ) ||
args -> V_67 . V_73 [ 0 ] == '\0' )
return - V_70 ;
F_41 ( & V_2 -> V_74 ) ;
V_12 = F_42 ( V_62 , args -> V_67 . V_73 ,
& V_65 ) ;
if ( V_12 ) {
F_43 ( L_8 ,
args -> V_67 . V_73 ) ;
F_44 ( & V_2 -> V_74 ) ;
return - V_70 ;
}
V_12 = F_45 ( V_62 , args -> V_67 . V_71 ,
args -> V_67 . V_72 ,
& V_66 ) ;
F_44 ( & V_2 -> V_74 ) ;
if ( V_12 ) {
V_12 = - V_70 ;
goto V_75;
}
if ( V_65 -> V_51 < V_66 -> V_51 ) {
F_43 ( L_9 ) ;
V_12 = - V_70 ;
goto V_75;
}
F_22 ( V_8 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_44 :
case V_45 :
break;
case V_46 :
case V_47 :
args -> V_76 = V_77 ;
goto V_78;
}
V_8 -> V_27 =
args -> V_67 . V_27 ;
F_46 ( ! V_66 ) ;
V_8 -> V_37 = V_66 ;
F_46 ( ! V_65 ) ;
V_8 -> V_38 = V_65 ;
F_47 ( V_79
L_10 ,
V_66 -> V_80 ? L_11 :
F_48 ( V_66 -> V_81 ) ,
V_66 -> V_57 ,
F_48 ( V_65 -> V_81 ) ) ;
V_65 -> V_51 = V_66 -> V_51 ;
V_65 -> V_52 = V_66 -> V_52 ;
V_65 -> V_53 = V_66 -> V_53 ;
V_8 -> V_25 = V_46 ;
V_8 -> V_29 = F_39 () ;
V_8 -> V_33 = 0 ;
V_8 -> V_34 = 0 ;
V_8 -> V_35 = 0 ;
V_8 -> V_36 = 0 ;
V_8 -> V_39 = 1 ;
V_8 -> V_40 = 1 ;
args -> V_76 = V_82 ;
F_23 ( V_8 ) ;
F_49 ( V_62 , 0 ) ;
V_56 = F_50 ( V_62 , 0 ) ;
if ( F_51 ( V_56 ) ) {
V_12 = F_52 ( V_56 ) ;
F_22 ( V_8 ) ;
goto V_78;
}
V_12 = F_53 ( V_56 , V_62 ) ;
F_46 ( V_12 ) ;
V_12 = F_54 ( V_2 , V_66 -> V_57 , 0 ,
V_66 -> V_51 ,
& V_8 -> V_83 , 0 , 1 ) ;
V_12 = F_55 ( V_62 -> V_2 , V_12 ) ;
F_46 ( V_12 ) ;
return 0 ;
V_78:
V_8 -> V_37 = NULL ;
V_8 -> V_38 = NULL ;
F_23 ( V_8 ) ;
V_75:
if ( V_65 )
F_56 ( V_2 , V_65 ) ;
return V_12 ;
}
static int F_55 ( struct V_1 * V_2 ,
int V_84 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_64 * V_65 ;
struct V_64 * V_66 ;
struct V_5 * V_62 = V_2 -> V_85 ;
T_2 V_86 [ V_87 ] ;
struct V_55 * V_56 ;
int V_12 = 0 ;
F_41 ( & V_8 -> V_88 ) ;
F_22 ( V_8 ) ;
if ( V_8 -> V_25 !=
V_46 ) {
F_23 ( V_8 ) ;
F_44 ( & V_8 -> V_88 ) ;
return 0 ;
}
V_65 = V_8 -> V_38 ;
V_66 = V_8 -> V_37 ;
F_23 ( V_8 ) ;
if ( ! V_84 )
F_57 ( V_2 ,
V_66 ,
V_65 ) ;
V_12 = F_58 ( V_62 , 0 ) ;
if ( V_12 ) {
F_44 ( & V_8 -> V_88 ) ;
return V_12 ;
}
F_49 ( V_62 , 0 ) ;
V_56 = F_50 ( V_62 , 0 ) ;
if ( F_51 ( V_56 ) ) {
F_44 ( & V_8 -> V_88 ) ;
return F_52 ( V_56 ) ;
}
V_12 = F_53 ( V_56 , V_62 ) ;
F_46 ( V_12 ) ;
F_41 ( & V_62 -> V_2 -> V_89 -> V_90 ) ;
F_22 ( V_8 ) ;
V_8 -> V_25 =
V_84 ? V_45
: V_44 ;
V_8 -> V_38 = NULL ;
V_8 -> V_37 = NULL ;
V_8 -> V_30 = F_39 () ;
V_8 -> V_40 = 1 ;
if ( V_84 ) {
F_47 ( V_91
L_12 ,
V_66 -> V_80 ? L_11 :
F_48 ( V_66 -> V_81 ) ,
V_66 -> V_57 ,
F_48 ( V_65 -> V_81 ) , V_84 ) ;
F_23 ( V_8 ) ;
F_44 ( & V_62 -> V_2 -> V_89 -> V_90 ) ;
if ( V_65 )
F_56 ( V_2 , V_65 ) ;
F_44 ( & V_8 -> V_88 ) ;
return 0 ;
}
F_47 ( V_79
L_13 ,
V_66 -> V_80 ? L_11 :
F_48 ( V_66 -> V_81 ) ,
V_66 -> V_57 ,
F_48 ( V_65 -> V_81 ) ) ;
V_65 -> V_54 = 0 ;
V_65 -> V_57 = V_66 -> V_57 ;
V_66 -> V_57 = V_48 ;
V_65 -> V_53 = V_66 -> V_53 ;
memcpy ( V_86 , V_65 -> V_92 , sizeof( V_86 ) ) ;
memcpy ( V_65 -> V_92 , V_66 -> V_92 , sizeof( V_65 -> V_92 ) ) ;
memcpy ( V_66 -> V_92 , V_86 , sizeof( V_66 -> V_92 ) ) ;
V_65 -> V_51 = V_66 -> V_51 ;
V_65 -> V_52 = V_66 -> V_52 ;
V_65 -> V_53 = V_66 -> V_53 ;
if ( V_2 -> V_93 -> V_94 == V_66 -> V_95 )
V_2 -> V_93 -> V_94 = V_65 -> V_95 ;
if ( V_2 -> V_89 -> V_96 == V_66 -> V_95 )
V_2 -> V_89 -> V_96 = V_65 -> V_95 ;
F_59 ( & V_65 -> V_97 , & V_2 -> V_89 -> V_98 ) ;
F_60 ( V_2 , V_66 ) ;
if ( V_66 -> V_95 ) {
F_61 ( V_66 ) ;
}
F_23 ( V_8 ) ;
F_44 ( & V_62 -> V_2 -> V_89 -> V_90 ) ;
V_56 = F_50 ( V_62 , 0 ) ;
if ( ! F_51 ( V_56 ) )
F_53 ( V_56 , V_62 ) ;
F_44 ( & V_8 -> V_88 ) ;
return 0 ;
}
static void F_57 (
struct V_1 * V_2 ,
struct V_64 * V_37 ,
struct V_64 * V_38 )
{
struct V_99 * V_100 = & V_2 -> V_101 . V_102 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
T_1 V_67 = 0 ;
int V_107 ;
F_62 ( & V_100 -> V_108 ) ;
do {
V_104 = F_63 ( V_100 , V_67 , ( T_1 ) - 1 ) ;
if ( ! V_104 )
break;
V_106 = (struct V_105 * ) V_104 -> V_95 ;
for ( V_107 = 0 ; V_107 < V_106 -> V_109 ; V_107 ++ )
if ( V_37 == V_106 -> V_110 [ V_107 ] . V_111 )
V_106 -> V_110 [ V_107 ] . V_111 = V_38 ;
V_67 = V_104 -> V_67 + V_104 -> V_112 ;
F_64 ( V_104 ) ;
} while ( V_67 );
F_65 ( & V_100 -> V_108 ) ;
}
static int F_45 ( struct V_5 * V_62 , T_1 V_71 ,
char * V_72 ,
struct V_64 * * V_113 )
{
int V_12 ;
if ( V_71 ) {
V_12 = 0 ;
* V_113 = F_17 ( V_62 -> V_2 , V_71 , NULL ,
NULL ) ;
if ( ! * V_113 )
V_12 = - V_114 ;
} else {
V_12 = F_66 ( V_62 , V_72 ,
V_113 ) ;
}
return V_12 ;
}
void F_67 ( struct V_1 * V_2 ,
struct V_63 * args )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
F_22 ( V_8 ) ;
args -> V_76 = V_82 ;
args -> V_115 . V_25 = V_8 -> V_25 ;
args -> V_115 . V_29 = V_8 -> V_29 ;
args -> V_115 . V_30 = V_8 -> V_30 ;
args -> V_115 . V_31 =
F_33 ( & V_8 -> V_31 ) ;
args -> V_115 . V_32 =
F_33 ( & V_8 -> V_32 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_45 :
args -> V_115 . V_116 = 0 ;
break;
case V_44 :
args -> V_115 . V_116 = 1000 ;
break;
case V_46 :
case V_47 :
args -> V_115 . V_116 = F_68 ( V_8 -> V_33 ,
F_68 ( V_8 -> V_37 -> V_51 , 1000 ) ) ;
break;
}
F_23 ( V_8 ) ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_63 * args )
{
args -> V_76 = F_70 ( V_2 ) ;
return 0 ;
}
static T_1 F_70 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_64 * V_65 = NULL ;
struct V_55 * V_56 ;
struct V_5 * V_62 = V_2 -> V_85 ;
T_1 V_76 ;
int V_12 ;
F_41 ( & V_8 -> V_88 ) ;
F_22 ( V_8 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_44 :
case V_45 :
V_76 = V_117 ;
F_23 ( V_8 ) ;
goto V_78;
case V_46 :
case V_47 :
V_76 = V_82 ;
V_65 = V_8 -> V_38 ;
V_8 -> V_38 = NULL ;
V_8 -> V_37 = NULL ;
break;
}
V_8 -> V_25 = V_45 ;
V_8 -> V_30 = F_39 () ;
V_8 -> V_40 = 1 ;
F_23 ( V_8 ) ;
F_71 ( V_2 ) ;
V_56 = F_50 ( V_62 , 0 ) ;
if ( F_51 ( V_56 ) ) {
F_44 ( & V_8 -> V_88 ) ;
return F_52 ( V_56 ) ;
}
V_12 = F_53 ( V_56 , V_62 ) ;
F_46 ( V_12 ) ;
if ( V_65 )
F_56 ( V_2 , V_65 ) ;
V_78:
F_44 ( & V_8 -> V_88 ) ;
return V_76 ;
}
void F_72 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
F_41 ( & V_8 -> V_88 ) ;
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
V_8 -> V_30 = F_39 () ;
V_8 -> V_40 = 1 ;
F_73 ( L_14 ) ;
break;
}
F_23 ( V_8 ) ;
F_44 ( & V_8 -> V_88 ) ;
}
int F_74 ( struct V_1 * V_2 )
{
struct V_118 * V_119 ;
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
if ( ! V_8 -> V_38 || ! V_8 -> V_38 -> V_95 ) {
F_73 ( L_15
L_16 ) ;
F_23 ( V_8 ) ;
return 0 ;
}
F_23 ( V_8 ) ;
F_46 ( F_75 (
& V_2 -> V_120 , 1 ) ) ;
V_119 = F_76 ( V_121 , V_2 , L_17 ) ;
return F_77 ( V_119 ) ;
}
static int V_121 ( void * V_122 )
{
struct V_1 * V_2 = V_122 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_63 * V_123 ;
T_1 V_124 ;
V_123 = F_78 ( sizeof( * V_123 ) , V_125 ) ;
if ( V_123 ) {
F_67 ( V_2 , V_123 ) ;
V_124 = V_123 -> V_115 . V_116 ;
F_79 ( V_123 ) ;
F_80 ( V_124 , 10 ) ;
F_47 ( V_79
L_18 ,
V_8 -> V_37 -> V_80 ? L_11 :
F_48 ( V_8 -> V_37 -> V_81 ) ,
V_8 -> V_37 -> V_57 ,
V_8 -> V_38 ?
F_48 ( V_8 -> V_38 -> V_81 ) :
L_19 ,
( unsigned int ) V_124 ) ;
}
F_81 ( V_2 ) ;
F_82 ( & V_2 -> V_120 , 0 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_12 ;
V_12 = F_54 ( V_2 , V_8 -> V_37 -> V_57 ,
V_8 -> V_34 ,
V_8 -> V_37 -> V_51 ,
& V_8 -> V_83 , 0 , 1 ) ;
V_12 = F_55 ( V_2 , V_12 ) ;
F_46 ( V_12 ) ;
return 0 ;
}
int F_83 ( struct V_7 * V_8 )
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
if ( F_84 ( & V_8 -> V_126 ) == 0 ) {
V_127:
F_41 ( & V_8 -> V_108 ) ;
F_41 ( & V_8 -> V_128 ) ;
V_8 -> V_129 = V_130 -> V_131 ;
F_85 ( & V_8 -> V_126 ) ;
F_44 ( & V_8 -> V_128 ) ;
return;
}
F_41 ( & V_8 -> V_128 ) ;
if ( F_84 ( & V_8 -> V_126 ) > 0 &&
V_8 -> V_129 == V_130 -> V_131 ) {
F_46 ( ! F_86 ( & V_8 -> V_108 ) ) ;
F_85 ( & V_8 -> V_126 ) ;
F_44 ( & V_8 -> V_128 ) ;
return;
}
F_44 ( & V_8 -> V_128 ) ;
goto V_127;
}
void F_23 ( struct V_7 * V_8 )
{
F_46 ( ! F_86 ( & V_8 -> V_108 ) ) ;
F_41 ( & V_8 -> V_128 ) ;
F_46 ( F_84 ( & V_8 -> V_126 ) < 1 ) ;
F_46 ( V_8 -> V_129 != V_130 -> V_131 ) ;
F_87 ( & V_8 -> V_126 ) ;
if ( F_84 ( & V_8 -> V_126 ) == 0 ) {
V_8 -> V_129 = 0 ;
F_44 ( & V_8 -> V_128 ) ;
F_44 ( & V_8 -> V_108 ) ;
} else {
F_44 ( & V_8 -> V_128 ) ;
}
}
