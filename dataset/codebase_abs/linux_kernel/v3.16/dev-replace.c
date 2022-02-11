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
return - V_68 ;
}
if ( ( args -> V_65 . V_69 == 0 && args -> V_65 . V_70 [ 0 ] == '\0' ) ||
args -> V_65 . V_71 [ 0 ] == '\0' )
return - V_68 ;
F_41 ( & V_2 -> V_72 ) ;
V_12 = F_42 ( V_58 , args -> V_65 . V_71 ,
& V_61 ) ;
if ( V_12 ) {
F_43 ( V_2 , L_9 ,
args -> V_65 . V_71 ) ;
F_44 ( & V_2 -> V_72 ) ;
return - V_68 ;
}
V_12 = F_45 ( V_58 , args -> V_65 . V_69 ,
args -> V_65 . V_70 ,
& V_62 ) ;
F_44 ( & V_2 -> V_72 ) ;
if ( V_12 ) {
V_12 = - V_68 ;
goto V_73;
}
if ( V_61 -> V_51 < V_62 -> V_51 ) {
F_43 ( V_2 , L_10 ) ;
V_12 = - V_68 ;
goto V_73;
}
F_22 ( V_8 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_44 :
case V_45 :
break;
case V_46 :
case V_47 :
args -> V_74 = V_75 ;
goto V_76;
}
V_8 -> V_27 =
args -> V_65 . V_27 ;
F_46 ( ! V_62 ) ;
V_8 -> V_37 = V_62 ;
F_46 ( ! V_61 ) ;
V_8 -> V_38 = V_61 ;
F_47 ( V_77
L_11 ,
V_62 -> V_78 ? L_12 :
F_48 ( V_62 -> V_79 ) ,
V_62 -> V_57 ,
F_48 ( V_61 -> V_79 ) ) ;
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
args -> V_74 = V_80 ;
F_23 ( V_8 ) ;
F_50 ( V_58 -> V_2 , - 1 ) ;
V_56 = F_51 ( V_58 , 0 ) ;
if ( F_52 ( V_56 ) ) {
V_12 = F_53 ( V_56 ) ;
F_22 ( V_8 ) ;
goto V_76;
}
V_12 = F_54 ( V_56 , V_58 ) ;
F_46 ( V_12 ) ;
V_12 = F_55 ( V_2 , V_62 -> V_57 , 0 ,
V_62 -> V_51 ,
& V_8 -> V_81 , 0 , 1 ) ;
V_12 = F_56 ( V_58 -> V_2 , V_12 ) ;
F_46 ( V_12 ) ;
return 0 ;
V_76:
V_8 -> V_37 = NULL ;
V_8 -> V_38 = NULL ;
F_23 ( V_8 ) ;
V_73:
if ( V_61 )
F_57 ( V_2 , V_61 ) ;
return V_12 ;
}
static void F_58 ( struct V_1 * V_2 )
{
T_2 V_82 ;
F_59 ( V_83 ) ;
F_60 ( V_84 , & V_2 -> V_85 ) ;
do {
F_61 ( & V_2 -> V_86 , & V_83 ,
V_87 ) ;
V_82 = F_62 ( & V_2 -> V_88 ) ;
if ( V_82 )
F_63 () ;
F_64 ( & V_2 -> V_86 , & V_83 ) ;
} while ( V_82 );
}
static void F_65 ( struct V_1 * V_2 )
{
F_66 ( V_84 , & V_2 -> V_85 ) ;
if ( F_67 ( & V_2 -> V_86 ) )
F_68 ( & V_2 -> V_86 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
int V_89 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_60 * V_61 ;
struct V_60 * V_62 ;
struct V_5 * V_58 = V_2 -> V_90 ;
T_3 V_91 [ V_92 ] ;
struct V_55 * V_56 ;
int V_12 = 0 ;
F_41 ( & V_8 -> V_93 ) ;
F_22 ( V_8 ) ;
if ( V_8 -> V_25 !=
V_46 ) {
F_23 ( V_8 ) ;
F_44 ( & V_8 -> V_93 ) ;
return 0 ;
}
V_61 = V_8 -> V_38 ;
V_62 = V_8 -> V_37 ;
F_23 ( V_8 ) ;
V_12 = F_69 ( V_58 -> V_2 , 0 , - 1 ) ;
if ( V_12 ) {
F_44 ( & V_8 -> V_93 ) ;
return V_12 ;
}
F_50 ( V_58 -> V_2 , - 1 ) ;
V_56 = F_51 ( V_58 , 0 ) ;
if ( F_52 ( V_56 ) ) {
F_44 ( & V_8 -> V_93 ) ;
return F_53 ( V_56 ) ;
}
V_12 = F_54 ( V_56 , V_58 ) ;
F_46 ( V_12 ) ;
F_41 ( & V_58 -> V_2 -> V_94 ) ;
F_41 ( & V_58 -> V_2 -> V_95 -> V_96 ) ;
F_22 ( V_8 ) ;
V_8 -> V_25 =
V_89 ? V_45
: V_44 ;
V_8 -> V_38 = NULL ;
V_8 -> V_37 = NULL ;
V_8 -> V_30 = F_49 () ;
V_8 -> V_40 = 1 ;
if ( ! V_89 ) {
F_70 ( V_2 ,
V_62 ,
V_61 ) ;
} else {
F_47 ( V_97
L_13 ,
V_62 -> V_78 ? L_12 :
F_48 ( V_62 -> V_79 ) ,
V_62 -> V_57 ,
F_48 ( V_61 -> V_79 ) , V_89 ) ;
F_23 ( V_8 ) ;
F_44 ( & V_58 -> V_2 -> V_95 -> V_96 ) ;
F_44 ( & V_58 -> V_2 -> V_94 ) ;
if ( V_61 )
F_57 ( V_2 , V_61 ) ;
F_44 ( & V_8 -> V_93 ) ;
return 0 ;
}
F_47 ( V_77
L_14 ,
V_62 -> V_78 ? L_12 :
F_48 ( V_62 -> V_79 ) ,
V_62 -> V_57 ,
F_48 ( V_61 -> V_79 ) ) ;
V_61 -> V_54 = 0 ;
V_61 -> V_57 = V_62 -> V_57 ;
V_62 -> V_57 = V_48 ;
V_61 -> V_53 = V_62 -> V_53 ;
memcpy ( V_91 , V_61 -> V_98 , sizeof( V_91 ) ) ;
memcpy ( V_61 -> V_98 , V_62 -> V_98 , sizeof( V_61 -> V_98 ) ) ;
memcpy ( V_62 -> V_98 , V_91 , sizeof( V_62 -> V_98 ) ) ;
V_61 -> V_51 = V_62 -> V_51 ;
V_61 -> V_52 = V_62 -> V_52 ;
V_61 -> V_53 = V_62 -> V_53 ;
if ( V_2 -> V_99 -> V_100 == V_62 -> V_101 )
V_2 -> V_99 -> V_100 = V_61 -> V_101 ;
if ( V_2 -> V_95 -> V_102 == V_62 -> V_101 )
V_2 -> V_95 -> V_102 = V_61 -> V_101 ;
F_71 ( & V_61 -> V_103 , & V_2 -> V_95 -> V_104 ) ;
F_72 ( V_2 , V_62 ) ;
F_73 ( V_2 , V_61 ) ;
F_58 ( V_2 ) ;
F_74 ( V_2 , V_62 ) ;
F_65 ( V_2 ) ;
F_23 ( V_8 ) ;
F_44 ( & V_58 -> V_2 -> V_95 -> V_96 ) ;
F_44 ( & V_58 -> V_2 -> V_94 ) ;
V_56 = F_51 ( V_58 , 0 ) ;
if ( ! F_52 ( V_56 ) )
F_54 ( V_56 , V_58 ) ;
F_44 ( & V_8 -> V_93 ) ;
return 0 ;
}
static void F_70 (
struct V_1 * V_2 ,
struct V_60 * V_37 ,
struct V_60 * V_38 )
{
struct V_105 * V_106 = & V_2 -> V_107 . V_108 ;
struct V_109 * V_110 ;
struct V_111 * V_112 ;
T_1 V_65 = 0 ;
int V_113 ;
F_75 ( & V_106 -> V_114 ) ;
do {
V_110 = F_76 ( V_106 , V_65 , ( T_1 ) - 1 ) ;
if ( ! V_110 )
break;
V_112 = (struct V_111 * ) V_110 -> V_101 ;
for ( V_113 = 0 ; V_113 < V_112 -> V_115 ; V_113 ++ )
if ( V_37 == V_112 -> V_116 [ V_113 ] . V_117 )
V_112 -> V_116 [ V_113 ] . V_117 = V_38 ;
V_65 = V_110 -> V_65 + V_110 -> V_118 ;
F_77 ( V_110 ) ;
} while ( V_65 );
F_78 ( & V_106 -> V_114 ) ;
}
static int F_45 ( struct V_5 * V_58 , T_1 V_69 ,
char * V_70 ,
struct V_60 * * V_119 )
{
int V_12 ;
if ( V_69 ) {
V_12 = 0 ;
* V_119 = F_17 ( V_58 -> V_2 , V_69 , NULL ,
NULL ) ;
if ( ! * V_119 )
V_12 = - V_120 ;
} else {
V_12 = F_79 ( V_58 , V_70 ,
V_119 ) ;
}
return V_12 ;
}
void F_80 ( struct V_1 * V_2 ,
struct V_59 * args )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
F_22 ( V_8 ) ;
args -> V_74 = V_80 ;
args -> V_121 . V_25 = V_8 -> V_25 ;
args -> V_121 . V_29 = V_8 -> V_29 ;
args -> V_121 . V_30 = V_8 -> V_30 ;
args -> V_121 . V_31 =
F_33 ( & V_8 -> V_31 ) ;
args -> V_121 . V_32 =
F_33 ( & V_8 -> V_32 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_45 :
args -> V_121 . V_122 = 0 ;
break;
case V_44 :
args -> V_121 . V_122 = 1000 ;
break;
case V_46 :
case V_47 :
args -> V_121 . V_122 = F_81 ( V_8 -> V_33 ,
F_81 ( V_8 -> V_37 -> V_51 , 1000 ) ) ;
break;
}
F_23 ( V_8 ) ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_59 * args )
{
args -> V_74 = F_83 ( V_2 ) ;
return 0 ;
}
static T_1 F_83 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_60 * V_61 = NULL ;
struct V_55 * V_56 ;
struct V_5 * V_58 = V_2 -> V_90 ;
T_1 V_74 ;
int V_12 ;
if ( V_2 -> V_99 -> V_123 & V_124 )
return - V_125 ;
F_41 ( & V_8 -> V_93 ) ;
F_22 ( V_8 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_44 :
case V_45 :
V_74 = V_126 ;
F_23 ( V_8 ) ;
goto V_76;
case V_46 :
case V_47 :
V_74 = V_80 ;
V_61 = V_8 -> V_38 ;
V_8 -> V_38 = NULL ;
V_8 -> V_37 = NULL ;
break;
}
V_8 -> V_25 = V_45 ;
V_8 -> V_30 = F_49 () ;
V_8 -> V_40 = 1 ;
F_23 ( V_8 ) ;
F_84 ( V_2 ) ;
V_56 = F_51 ( V_58 , 0 ) ;
if ( F_52 ( V_56 ) ) {
F_44 ( & V_8 -> V_93 ) ;
return F_53 ( V_56 ) ;
}
V_12 = F_54 ( V_56 , V_58 ) ;
F_46 ( V_12 ) ;
if ( V_61 )
F_57 ( V_2 , V_61 ) ;
V_76:
F_44 ( & V_8 -> V_93 ) ;
return V_74 ;
}
void F_85 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
F_41 ( & V_8 -> V_93 ) ;
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
F_86 ( V_2 , L_15 ) ;
break;
}
F_23 ( V_8 ) ;
F_44 ( & V_8 -> V_93 ) ;
}
int F_87 ( struct V_1 * V_2 )
{
struct V_127 * V_128 ;
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
if ( ! V_8 -> V_38 || ! V_8 -> V_38 -> V_101 ) {
F_86 ( V_2 , L_16 ) ;
F_86 ( V_2 ,
L_17 ) ;
F_23 ( V_8 ) ;
return 0 ;
}
F_23 ( V_8 ) ;
F_46 ( F_88 (
& V_2 -> V_129 , 1 ) ) ;
V_128 = F_89 ( V_130 , V_2 , L_18 ) ;
return F_90 ( V_128 ) ;
}
static int V_130 ( void * V_131 )
{
struct V_1 * V_2 = V_131 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_59 * V_132 ;
T_1 V_133 ;
V_132 = F_91 ( sizeof( * V_132 ) , V_134 ) ;
if ( V_132 ) {
F_80 ( V_2 , V_132 ) ;
V_133 = V_132 -> V_121 . V_122 ;
F_92 ( V_132 ) ;
F_93 ( V_133 , 10 ) ;
F_47 ( V_77
L_19 ,
V_8 -> V_37 -> V_78 ? L_12 :
F_48 ( V_8 -> V_37 -> V_79 ) ,
V_8 -> V_37 -> V_57 ,
V_8 -> V_38 ?
F_48 ( V_8 -> V_38 -> V_79 ) :
L_20 ,
( unsigned int ) V_133 ) ;
}
F_94 ( V_2 ) ;
F_95 ( & V_2 -> V_129 , 0 ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_12 ;
V_12 = F_55 ( V_2 , V_8 -> V_37 -> V_57 ,
V_8 -> V_34 ,
V_8 -> V_37 -> V_51 ,
& V_8 -> V_81 , 0 , 1 ) ;
V_12 = F_56 ( V_2 , V_12 ) ;
F_46 ( V_12 ) ;
return 0 ;
}
int F_96 ( struct V_7 * V_8 )
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
if ( F_97 ( & V_8 -> V_135 ) == 0 ) {
V_136:
F_41 ( & V_8 -> V_114 ) ;
F_41 ( & V_8 -> V_137 ) ;
V_8 -> V_138 = V_139 -> V_140 ;
F_98 ( & V_8 -> V_135 ) ;
F_44 ( & V_8 -> V_137 ) ;
return;
}
F_41 ( & V_8 -> V_137 ) ;
if ( F_97 ( & V_8 -> V_135 ) > 0 &&
V_8 -> V_138 == V_139 -> V_140 ) {
F_46 ( ! F_99 ( & V_8 -> V_114 ) ) ;
F_98 ( & V_8 -> V_135 ) ;
F_44 ( & V_8 -> V_137 ) ;
return;
}
F_44 ( & V_8 -> V_137 ) ;
goto V_136;
}
void F_23 ( struct V_7 * V_8 )
{
F_46 ( ! F_99 ( & V_8 -> V_114 ) ) ;
F_41 ( & V_8 -> V_137 ) ;
F_46 ( F_97 ( & V_8 -> V_135 ) < 1 ) ;
F_46 ( V_8 -> V_138 != V_139 -> V_140 ) ;
F_100 ( & V_8 -> V_135 ) ;
if ( F_97 ( & V_8 -> V_135 ) == 0 ) {
V_8 -> V_138 = 0 ;
F_44 ( & V_8 -> V_137 ) ;
F_44 ( & V_8 -> V_114 ) ;
} else {
F_44 ( & V_8 -> V_137 ) ;
}
}
void F_101 ( struct V_1 * V_2 )
{
F_102 ( & V_2 -> V_88 ) ;
}
void F_103 ( struct V_1 * V_2 )
{
F_104 ( & V_2 -> V_88 ) ;
if ( F_67 ( & V_2 -> V_86 ) )
F_68 ( & V_2 -> V_86 ) ;
}
void F_105 ( struct V_1 * V_2 )
{
F_59 ( V_83 ) ;
V_141:
F_102 ( & V_2 -> V_88 ) ;
if ( F_106 ( V_84 , & V_2 -> V_85 ) ) {
F_103 ( V_2 ) ;
F_107 ( V_2 -> V_86 ,
! F_106 ( V_84 ,
& V_2 -> V_85 ) ) ;
goto V_141;
}
}
