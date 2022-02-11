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
if ( V_14 )
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
F_22 ( V_8 ) ;
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
int F_39 ( struct V_5 * V_60 ,
struct V_61 * args )
{
struct V_57 * V_58 ;
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_12 ;
struct V_62 * V_63 = NULL ;
struct V_62 * V_64 = NULL ;
if ( F_40 ( V_2 , V_65 ) ) {
F_7 ( V_2 , L_8 ) ;
return - V_66 ;
}
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
V_58 = F_41 ( V_60 ) ;
if ( ! F_42 ( V_58 ) ) {
V_12 = F_43 ( V_58 , V_60 ) ;
if ( V_12 )
return V_12 ;
} else if ( F_44 ( V_58 ) != - V_74 ) {
return F_44 ( V_58 ) ;
}
F_45 ( & V_2 -> V_75 ) ;
V_12 = F_46 ( V_60 , args -> V_67 . V_71 ,
args -> V_67 . V_72 ,
& V_64 ) ;
if ( V_12 ) {
F_47 ( & V_2 -> V_75 ) ;
return V_12 ;
}
V_12 = F_48 ( V_60 , args -> V_67 . V_73 ,
V_64 , & V_63 ) ;
F_47 ( & V_2 -> V_75 ) ;
if ( V_12 )
return V_12 ;
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
F_49 ( ! V_64 ) ;
V_8 -> V_37 = V_64 ;
F_49 ( ! V_63 ) ;
V_8 -> V_38 = V_63 ;
F_50 ( V_79
L_9 ,
V_64 -> V_80 ? L_10 :
F_51 ( V_64 -> V_81 ) ,
V_64 -> V_59 ,
F_51 ( V_63 -> V_81 ) ) ;
V_8 -> V_25 = V_46 ;
V_8 -> V_29 = F_52 () ;
V_8 -> V_33 = 0 ;
V_8 -> V_34 = 0 ;
V_8 -> V_35 = 0 ;
V_8 -> V_36 = 0 ;
V_8 -> V_39 = 1 ;
V_8 -> V_40 = 1 ;
args -> V_76 = V_82 ;
F_23 ( V_8 ) ;
F_53 ( V_60 -> V_2 , - 1 ) ;
V_58 = F_54 ( V_60 , 0 ) ;
if ( F_42 ( V_58 ) ) {
V_12 = F_44 ( V_58 ) ;
F_22 ( V_8 ) ;
goto V_78;
}
V_12 = F_43 ( V_58 , V_60 ) ;
F_49 ( V_12 ) ;
V_12 = F_55 ( V_2 , V_64 -> V_59 , 0 ,
F_56 ( V_64 ) ,
& V_8 -> V_83 , 0 , 1 ) ;
V_12 = F_57 ( V_60 -> V_2 , V_12 ) ;
F_49 ( V_12 ) ;
return 0 ;
V_78:
V_8 -> V_37 = NULL ;
V_8 -> V_38 = NULL ;
F_23 ( V_8 ) ;
F_58 ( V_2 , V_63 ) ;
return V_12 ;
}
static void F_59 ( struct V_1 * V_2 )
{
T_2 V_84 ;
F_60 ( V_85 ) ;
F_61 ( V_86 , & V_2 -> V_87 ) ;
do {
F_62 ( & V_2 -> V_88 , & V_85 ,
V_89 ) ;
V_84 = F_63 ( & V_2 -> V_90 ) ;
if ( V_84 )
F_64 () ;
F_65 ( & V_2 -> V_88 , & V_85 ) ;
} while ( V_84 );
}
static void F_66 ( struct V_1 * V_2 )
{
F_67 ( V_86 , & V_2 -> V_87 ) ;
if ( F_68 ( & V_2 -> V_88 ) )
F_69 ( & V_2 -> V_88 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
int V_91 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_62 * V_63 ;
struct V_62 * V_64 ;
struct V_5 * V_60 = V_2 -> V_92 ;
T_3 V_93 [ V_94 ] ;
struct V_57 * V_58 ;
int V_12 = 0 ;
F_45 ( & V_8 -> V_95 ) ;
F_22 ( V_8 ) ;
if ( V_8 -> V_25 !=
V_46 ) {
F_23 ( V_8 ) ;
F_47 ( & V_8 -> V_95 ) ;
return 0 ;
}
V_63 = V_8 -> V_38 ;
V_64 = V_8 -> V_37 ;
F_23 ( V_8 ) ;
V_12 = F_70 ( V_60 -> V_2 , 0 , - 1 ) ;
if ( V_12 ) {
F_47 ( & V_8 -> V_95 ) ;
return V_12 ;
}
F_53 ( V_60 -> V_2 , - 1 ) ;
V_58 = F_54 ( V_60 , 0 ) ;
if ( F_42 ( V_58 ) ) {
F_47 ( & V_8 -> V_95 ) ;
return F_44 ( V_58 ) ;
}
V_12 = F_43 ( V_58 , V_60 ) ;
F_49 ( V_12 ) ;
F_45 ( & V_96 ) ;
F_45 ( & V_60 -> V_2 -> V_97 -> V_98 ) ;
F_45 ( & V_60 -> V_2 -> V_99 ) ;
F_22 ( V_8 ) ;
V_8 -> V_25 =
V_91 ? V_45
: V_44 ;
V_8 -> V_38 = NULL ;
V_8 -> V_37 = NULL ;
V_8 -> V_30 = F_52 () ;
V_8 -> V_40 = 1 ;
if ( ! V_91 ) {
F_71 ( V_2 ,
V_64 ,
V_63 ) ;
} else {
F_50 ( V_100
L_11 ,
V_64 -> V_80 ? L_10 :
F_51 ( V_64 -> V_81 ) ,
V_64 -> V_59 ,
F_51 ( V_63 -> V_81 ) , V_91 ) ;
F_23 ( V_8 ) ;
F_47 ( & V_60 -> V_2 -> V_99 ) ;
F_47 ( & V_60 -> V_2 -> V_97 -> V_98 ) ;
F_47 ( & V_96 ) ;
if ( V_63 )
F_58 ( V_2 , V_63 ) ;
F_47 ( & V_8 -> V_95 ) ;
return 0 ;
}
F_50 ( V_79
L_12 ,
V_64 -> V_80 ? L_10 :
F_51 ( V_64 -> V_81 ) ,
V_64 -> V_59 ,
F_51 ( V_63 -> V_81 ) ) ;
V_63 -> V_56 = 0 ;
V_63 -> V_59 = V_64 -> V_59 ;
V_64 -> V_59 = V_48 ;
memcpy ( V_93 , V_63 -> V_101 , sizeof( V_93 ) ) ;
memcpy ( V_63 -> V_101 , V_64 -> V_101 , sizeof( V_63 -> V_101 ) ) ;
memcpy ( V_64 -> V_101 , V_93 , sizeof( V_64 -> V_101 ) ) ;
F_72 ( V_63 , V_64 -> V_51 ) ;
F_73 ( V_63 ,
V_64 -> V_52 ) ;
F_74 ( V_63 , V_64 -> V_54 ) ;
ASSERT ( F_75 ( & V_64 -> V_102 ) ) ;
V_63 -> V_53 = V_64 -> V_53 ;
V_63 -> V_55 = V_64 -> V_54 ;
if ( V_2 -> V_103 -> V_104 == V_64 -> V_105 )
V_2 -> V_103 -> V_104 = V_63 -> V_105 ;
if ( V_2 -> V_97 -> V_106 == V_64 -> V_105 )
V_2 -> V_97 -> V_106 = V_63 -> V_105 ;
F_76 ( & V_63 -> V_107 , & V_2 -> V_97 -> V_108 ) ;
V_2 -> V_97 -> V_109 ++ ;
F_77 ( V_2 , V_64 ) ;
F_78 ( V_2 , V_63 ) ;
F_23 ( V_8 ) ;
F_59 ( V_2 ) ;
F_79 ( V_2 , V_64 ) ;
F_66 ( V_2 ) ;
F_47 ( & V_60 -> V_2 -> V_99 ) ;
F_47 ( & V_60 -> V_2 -> V_97 -> V_98 ) ;
F_47 ( & V_96 ) ;
V_58 = F_54 ( V_60 , 0 ) ;
if ( ! F_42 ( V_58 ) )
F_43 ( V_58 , V_60 ) ;
F_47 ( & V_8 -> V_95 ) ;
return 0 ;
}
static void F_71 (
struct V_1 * V_2 ,
struct V_62 * V_37 ,
struct V_62 * V_38 )
{
struct V_110 * V_111 = & V_2 -> V_112 . V_113 ;
struct V_114 * V_115 ;
struct V_116 * V_117 ;
T_1 V_67 = 0 ;
int V_118 ;
F_80 ( & V_111 -> V_119 ) ;
do {
V_115 = F_81 ( V_111 , V_67 , ( T_1 ) - 1 ) ;
if ( ! V_115 )
break;
V_117 = (struct V_116 * ) V_115 -> V_105 ;
for ( V_118 = 0 ; V_118 < V_117 -> V_120 ; V_118 ++ )
if ( V_37 == V_117 -> V_121 [ V_118 ] . V_122 )
V_117 -> V_121 [ V_118 ] . V_122 = V_38 ;
V_67 = V_115 -> V_67 + V_115 -> V_123 ;
F_82 ( V_115 ) ;
} while ( V_67 );
F_83 ( & V_111 -> V_119 ) ;
}
static int F_46 ( struct V_5 * V_60 , T_1 V_71 ,
char * V_72 ,
struct V_62 * * V_124 )
{
int V_12 ;
if ( V_71 ) {
V_12 = 0 ;
* V_124 = F_17 ( V_60 -> V_2 , V_71 , NULL ,
NULL ) ;
if ( ! * V_124 )
V_12 = - V_74 ;
} else {
V_12 = F_84 ( V_60 , V_72 ,
V_124 ) ;
}
return V_12 ;
}
void F_85 ( struct V_1 * V_2 ,
struct V_61 * args )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_62 * V_37 ;
F_22 ( V_8 ) ;
args -> V_76 = V_82 ;
args -> V_125 . V_25 = V_8 -> V_25 ;
args -> V_125 . V_29 = V_8 -> V_29 ;
args -> V_125 . V_30 = V_8 -> V_30 ;
args -> V_125 . V_31 =
F_33 ( & V_8 -> V_31 ) ;
args -> V_125 . V_32 =
F_33 ( & V_8 -> V_32 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_45 :
args -> V_125 . V_126 = 0 ;
break;
case V_44 :
args -> V_125 . V_126 = 1000 ;
break;
case V_46 :
case V_47 :
V_37 = V_8 -> V_37 ;
args -> V_125 . V_126 = F_86 ( V_8 -> V_33 ,
F_86 ( F_56 ( V_37 ) , 1000 ) ) ;
break;
}
F_23 ( V_8 ) ;
}
int F_87 ( struct V_1 * V_2 ,
struct V_61 * args )
{
args -> V_76 = F_88 ( V_2 ) ;
return 0 ;
}
static T_1 F_88 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_62 * V_63 = NULL ;
struct V_57 * V_58 ;
struct V_5 * V_60 = V_2 -> V_92 ;
T_1 V_76 ;
int V_12 ;
if ( V_2 -> V_103 -> V_127 & V_128 )
return - V_129 ;
F_45 ( & V_8 -> V_95 ) ;
F_22 ( V_8 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_44 :
case V_45 :
V_76 = V_130 ;
F_23 ( V_8 ) ;
goto V_78;
case V_46 :
case V_47 :
V_76 = V_82 ;
V_63 = V_8 -> V_38 ;
V_8 -> V_38 = NULL ;
V_8 -> V_37 = NULL ;
break;
}
V_8 -> V_25 = V_45 ;
V_8 -> V_30 = F_52 () ;
V_8 -> V_40 = 1 ;
F_23 ( V_8 ) ;
F_89 ( V_2 ) ;
V_58 = F_54 ( V_60 , 0 ) ;
if ( F_42 ( V_58 ) ) {
F_47 ( & V_8 -> V_95 ) ;
return F_44 ( V_58 ) ;
}
V_12 = F_43 ( V_58 , V_60 ) ;
F_49 ( V_12 ) ;
if ( V_63 )
F_58 ( V_2 , V_63 ) ;
V_78:
F_47 ( & V_8 -> V_95 ) ;
return V_76 ;
}
void F_90 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
F_45 ( & V_8 -> V_95 ) ;
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
V_8 -> V_30 = F_52 () ;
V_8 -> V_40 = 1 ;
F_91 ( V_2 , L_13 ) ;
break;
}
F_23 ( V_8 ) ;
F_47 ( & V_8 -> V_95 ) ;
}
int F_92 ( struct V_1 * V_2 )
{
struct V_131 * V_132 ;
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
if ( ! V_8 -> V_38 || ! V_8 -> V_38 -> V_105 ) {
F_91 ( V_2 , L_14 ) ;
F_91 ( V_2 ,
L_15 ) ;
F_23 ( V_8 ) ;
return 0 ;
}
F_23 ( V_8 ) ;
F_49 ( F_93 (
& V_2 -> V_133 , 1 ) ) ;
V_132 = F_94 ( V_134 , V_2 , L_16 ) ;
return F_95 ( V_132 ) ;
}
static int V_134 ( void * V_135 )
{
struct V_1 * V_2 = V_135 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_61 * V_136 ;
T_1 V_137 ;
V_136 = F_96 ( sizeof( * V_136 ) , V_138 ) ;
if ( V_136 ) {
F_85 ( V_2 , V_136 ) ;
V_137 = V_136 -> V_125 . V_126 ;
F_97 ( V_136 ) ;
F_98 ( V_137 , 10 ) ;
F_50 ( V_79
L_17 ,
V_8 -> V_37 -> V_80 ? L_10 :
F_51 ( V_8 -> V_37 -> V_81 ) ,
V_8 -> V_37 -> V_59 ,
V_8 -> V_38 ?
F_51 ( V_8 -> V_38 -> V_81 ) :
L_18 ,
( unsigned int ) V_137 ) ;
}
F_99 ( V_2 ) ;
F_100 ( & V_2 -> V_133 , 0 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_12 ;
V_12 = F_55 ( V_2 , V_8 -> V_37 -> V_59 ,
V_8 -> V_34 ,
F_56 ( V_8 -> V_37 ) ,
& V_8 -> V_83 , 0 , 1 ) ;
V_12 = F_57 ( V_2 , V_12 ) ;
F_49 ( V_12 ) ;
return 0 ;
}
int F_101 ( struct V_7 * V_8 )
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
if ( F_102 ( & V_8 -> V_139 ) == 0 ) {
V_140:
F_45 ( & V_8 -> V_119 ) ;
F_45 ( & V_8 -> V_141 ) ;
V_8 -> V_142 = V_143 -> V_144 ;
F_103 ( & V_8 -> V_139 ) ;
F_47 ( & V_8 -> V_141 ) ;
return;
}
F_45 ( & V_8 -> V_141 ) ;
if ( F_102 ( & V_8 -> V_139 ) > 0 &&
V_8 -> V_142 == V_143 -> V_144 ) {
F_49 ( ! F_104 ( & V_8 -> V_119 ) ) ;
F_103 ( & V_8 -> V_139 ) ;
F_47 ( & V_8 -> V_141 ) ;
return;
}
F_47 ( & V_8 -> V_141 ) ;
goto V_140;
}
void F_23 ( struct V_7 * V_8 )
{
F_49 ( ! F_104 ( & V_8 -> V_119 ) ) ;
F_45 ( & V_8 -> V_141 ) ;
F_49 ( F_102 ( & V_8 -> V_139 ) < 1 ) ;
F_49 ( V_8 -> V_142 != V_143 -> V_144 ) ;
F_105 ( & V_8 -> V_139 ) ;
if ( F_102 ( & V_8 -> V_139 ) == 0 ) {
V_8 -> V_142 = 0 ;
F_47 ( & V_8 -> V_141 ) ;
F_47 ( & V_8 -> V_119 ) ;
} else {
F_47 ( & V_8 -> V_141 ) ;
}
}
void F_106 ( struct V_1 * V_2 )
{
F_107 ( & V_2 -> V_90 ) ;
}
void F_108 ( struct V_1 * V_2 )
{
F_109 ( & V_2 -> V_90 ) ;
if ( F_68 ( & V_2 -> V_88 ) )
F_69 ( & V_2 -> V_88 ) ;
}
void F_110 ( struct V_1 * V_2 )
{
F_60 ( V_85 ) ;
V_145:
F_107 ( & V_2 -> V_90 ) ;
if ( F_111 ( V_86 , & V_2 -> V_87 ) ) {
F_108 ( V_2 ) ;
F_112 ( V_2 -> V_88 ,
! F_111 ( V_86 ,
& V_2 -> V_87 ) ) ;
goto V_145;
}
}
