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
V_58 = F_40 ( V_60 ) ;
if ( ! F_41 ( V_58 ) ) {
V_12 = F_42 ( V_58 , V_60 ) ;
if ( V_12 )
return V_12 ;
} else if ( F_43 ( V_58 ) != - V_72 ) {
return F_43 ( V_58 ) ;
}
F_44 ( & V_2 -> V_73 ) ;
V_12 = F_45 ( V_60 , args -> V_65 . V_69 ,
args -> V_65 . V_70 ,
& V_64 ) ;
if ( V_12 ) {
F_46 ( & V_2 -> V_73 ) ;
return V_12 ;
}
V_12 = F_47 ( V_60 , args -> V_65 . V_71 ,
V_64 , & V_63 ) ;
F_46 ( & V_2 -> V_73 ) ;
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
args -> V_74 = V_75 ;
goto V_76;
}
V_8 -> V_27 =
args -> V_65 . V_27 ;
F_48 ( ! V_64 ) ;
V_8 -> V_37 = V_64 ;
F_48 ( ! V_63 ) ;
V_8 -> V_38 = V_63 ;
V_12 = F_49 ( V_63 -> V_77 , V_63 ) ;
if ( V_12 )
F_50 ( V_60 -> V_2 , L_8 , V_12 ) ;
F_51 ( V_78
L_9 ,
V_64 -> V_79 ? L_10 :
F_52 ( V_64 -> V_80 ) ,
V_64 -> V_59 ,
F_52 ( V_63 -> V_80 ) ) ;
V_8 -> V_25 = V_46 ;
V_8 -> V_29 = F_53 () ;
V_8 -> V_33 = 0 ;
V_8 -> V_34 = 0 ;
V_8 -> V_35 = 0 ;
V_8 -> V_36 = 0 ;
V_8 -> V_39 = 1 ;
V_8 -> V_40 = 1 ;
args -> V_74 = V_81 ;
F_23 ( V_8 ) ;
F_54 ( V_60 -> V_2 , - 1 ) ;
V_58 = F_55 ( V_60 , 0 ) ;
if ( F_41 ( V_58 ) ) {
V_12 = F_43 ( V_58 ) ;
F_22 ( V_8 ) ;
goto V_76;
}
V_12 = F_42 ( V_58 , V_60 ) ;
F_48 ( V_12 ) ;
V_12 = F_56 ( V_2 , V_64 -> V_59 , 0 ,
F_57 ( V_64 ) ,
& V_8 -> V_82 , 0 , 1 ) ;
V_12 = F_58 ( V_60 -> V_2 , V_12 ) ;
if ( V_12 == - V_83 ) {
args -> V_74 = V_84 ;
V_12 = 0 ;
} else {
F_48 ( V_12 ) ;
}
return V_12 ;
V_76:
V_8 -> V_37 = NULL ;
V_8 -> V_38 = NULL ;
F_23 ( V_8 ) ;
F_59 ( V_2 , V_63 ) ;
return V_12 ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_61 ( V_85 , & V_2 -> V_86 ) ;
F_62 ( V_2 -> V_87 , ! F_63 (
& V_2 -> V_88 ) ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_65 ( V_85 , & V_2 -> V_86 ) ;
if ( F_66 ( & V_2 -> V_87 ) )
F_67 ( & V_2 -> V_87 ) ;
}
static int F_58 ( struct V_1 * V_2 ,
int V_89 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_62 * V_63 ;
struct V_62 * V_64 ;
struct V_5 * V_60 = V_2 -> V_90 ;
T_2 V_91 [ V_92 ] ;
struct V_57 * V_58 ;
int V_12 = 0 ;
F_44 ( & V_8 -> V_93 ) ;
F_22 ( V_8 ) ;
if ( V_8 -> V_25 !=
V_46 ) {
F_23 ( V_8 ) ;
F_46 ( & V_8 -> V_93 ) ;
return 0 ;
}
V_63 = V_8 -> V_38 ;
V_64 = V_8 -> V_37 ;
F_23 ( V_8 ) ;
V_12 = F_68 ( V_60 -> V_2 , 0 , - 1 ) ;
if ( V_12 ) {
F_46 ( & V_8 -> V_93 ) ;
return V_12 ;
}
F_54 ( V_60 -> V_2 , - 1 ) ;
V_58 = F_55 ( V_60 , 0 ) ;
if ( F_41 ( V_58 ) ) {
F_46 ( & V_8 -> V_93 ) ;
return F_43 ( V_58 ) ;
}
V_12 = F_42 ( V_58 , V_60 ) ;
F_48 ( V_12 ) ;
F_44 ( & V_94 ) ;
F_44 ( & V_60 -> V_2 -> V_77 -> V_95 ) ;
F_44 ( & V_60 -> V_2 -> V_96 ) ;
F_22 ( V_8 ) ;
V_8 -> V_25 =
V_89 ? V_45
: V_44 ;
V_8 -> V_38 = NULL ;
V_8 -> V_37 = NULL ;
V_8 -> V_30 = F_53 () ;
V_8 -> V_40 = 1 ;
if ( ! V_89 ) {
F_69 ( V_2 ,
V_64 ,
V_63 ) ;
} else {
F_51 ( V_97
L_11 ,
V_64 -> V_79 ? L_10 :
F_52 ( V_64 -> V_80 ) ,
V_64 -> V_59 ,
F_52 ( V_63 -> V_80 ) , V_89 ) ;
F_23 ( V_8 ) ;
F_46 ( & V_60 -> V_2 -> V_96 ) ;
F_46 ( & V_60 -> V_2 -> V_77 -> V_95 ) ;
F_46 ( & V_94 ) ;
if ( V_63 )
F_59 ( V_2 , V_63 ) ;
F_46 ( & V_8 -> V_93 ) ;
return V_89 ;
}
F_51 ( V_78
L_12 ,
V_64 -> V_79 ? L_10 :
F_52 ( V_64 -> V_80 ) ,
V_64 -> V_59 ,
F_52 ( V_63 -> V_80 ) ) ;
V_63 -> V_56 = 0 ;
V_63 -> V_59 = V_64 -> V_59 ;
V_64 -> V_59 = V_48 ;
memcpy ( V_91 , V_63 -> V_98 , sizeof( V_91 ) ) ;
memcpy ( V_63 -> V_98 , V_64 -> V_98 , sizeof( V_63 -> V_98 ) ) ;
memcpy ( V_64 -> V_98 , V_91 , sizeof( V_64 -> V_98 ) ) ;
F_70 ( V_63 , V_64 -> V_51 ) ;
F_71 ( V_63 ,
V_64 -> V_52 ) ;
F_72 ( V_63 , V_64 -> V_54 ) ;
ASSERT ( F_73 ( & V_64 -> V_99 ) ) ;
V_63 -> V_53 = V_64 -> V_53 ;
V_63 -> V_55 = V_64 -> V_54 ;
if ( V_2 -> V_100 -> V_101 == V_64 -> V_102 )
V_2 -> V_100 -> V_101 = V_63 -> V_102 ;
if ( V_2 -> V_77 -> V_103 == V_64 -> V_102 )
V_2 -> V_77 -> V_103 = V_63 -> V_102 ;
F_74 ( & V_63 -> V_104 , & V_2 -> V_77 -> V_105 ) ;
V_2 -> V_77 -> V_106 ++ ;
F_23 ( V_8 ) ;
F_60 ( V_2 ) ;
F_75 ( V_2 , V_64 ) ;
F_64 ( V_2 ) ;
F_46 ( & V_60 -> V_2 -> V_96 ) ;
F_46 ( & V_60 -> V_2 -> V_77 -> V_95 ) ;
F_46 ( & V_94 ) ;
F_76 ( V_2 -> V_77 , V_64 ) ;
F_77 ( V_2 , V_64 ) ;
V_58 = F_55 ( V_60 , 0 ) ;
if ( ! F_41 ( V_58 ) )
F_42 ( V_58 , V_60 ) ;
F_46 ( & V_8 -> V_93 ) ;
return 0 ;
}
static void F_69 (
struct V_1 * V_2 ,
struct V_62 * V_37 ,
struct V_62 * V_38 )
{
struct V_107 * V_108 = & V_2 -> V_109 . V_110 ;
struct V_111 * V_112 ;
struct V_113 * V_114 ;
T_1 V_65 = 0 ;
int V_115 ;
F_78 ( & V_108 -> V_116 ) ;
do {
V_112 = F_79 ( V_108 , V_65 , ( T_1 ) - 1 ) ;
if ( ! V_112 )
break;
V_114 = (struct V_113 * ) V_112 -> V_102 ;
for ( V_115 = 0 ; V_115 < V_114 -> V_117 ; V_115 ++ )
if ( V_37 == V_114 -> V_118 [ V_115 ] . V_119 )
V_114 -> V_118 [ V_115 ] . V_119 = V_38 ;
V_65 = V_112 -> V_65 + V_112 -> V_120 ;
F_80 ( V_112 ) ;
} while ( V_65 );
F_81 ( & V_108 -> V_116 ) ;
}
static int F_45 ( struct V_5 * V_60 , T_1 V_69 ,
char * V_70 ,
struct V_62 * * V_121 )
{
int V_12 ;
if ( V_69 ) {
V_12 = 0 ;
* V_121 = F_17 ( V_60 -> V_2 , V_69 , NULL ,
NULL ) ;
if ( ! * V_121 )
V_12 = - V_72 ;
} else {
V_12 = F_82 ( V_60 , V_70 ,
V_121 ) ;
}
return V_12 ;
}
void F_83 ( struct V_1 * V_2 ,
struct V_61 * args )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_62 * V_37 ;
F_22 ( V_8 ) ;
args -> V_74 = V_81 ;
args -> V_122 . V_25 = V_8 -> V_25 ;
args -> V_122 . V_29 = V_8 -> V_29 ;
args -> V_122 . V_30 = V_8 -> V_30 ;
args -> V_122 . V_31 =
F_33 ( & V_8 -> V_31 ) ;
args -> V_122 . V_32 =
F_33 ( & V_8 -> V_32 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_45 :
args -> V_122 . V_123 = 0 ;
break;
case V_44 :
args -> V_122 . V_123 = 1000 ;
break;
case V_46 :
case V_47 :
V_37 = V_8 -> V_37 ;
args -> V_122 . V_123 = F_84 ( V_8 -> V_33 ,
F_84 ( F_57 ( V_37 ) , 1000 ) ) ;
break;
}
F_23 ( V_8 ) ;
}
int F_85 ( struct V_1 * V_2 ,
struct V_61 * args )
{
args -> V_74 = F_86 ( V_2 ) ;
return 0 ;
}
static T_1 F_86 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_62 * V_63 = NULL ;
struct V_57 * V_58 ;
struct V_5 * V_60 = V_2 -> V_90 ;
T_1 V_74 ;
int V_12 ;
if ( V_2 -> V_100 -> V_124 & V_125 )
return - V_126 ;
F_44 ( & V_8 -> V_93 ) ;
F_22 ( V_8 ) ;
switch ( V_8 -> V_25 ) {
case V_43 :
case V_44 :
case V_45 :
V_74 = V_127 ;
F_23 ( V_8 ) ;
goto V_76;
case V_46 :
case V_47 :
V_74 = V_81 ;
V_63 = V_8 -> V_38 ;
V_8 -> V_38 = NULL ;
V_8 -> V_37 = NULL ;
break;
}
V_8 -> V_25 = V_45 ;
V_8 -> V_30 = F_53 () ;
V_8 -> V_40 = 1 ;
F_23 ( V_8 ) ;
F_87 ( V_2 ) ;
V_58 = F_55 ( V_60 , 0 ) ;
if ( F_41 ( V_58 ) ) {
F_46 ( & V_8 -> V_93 ) ;
return F_43 ( V_58 ) ;
}
V_12 = F_42 ( V_58 , V_60 ) ;
F_48 ( V_12 ) ;
if ( V_63 )
F_59 ( V_2 , V_63 ) ;
V_76:
F_46 ( & V_8 -> V_93 ) ;
return V_74 ;
}
void F_88 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
F_44 ( & V_8 -> V_93 ) ;
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
V_8 -> V_30 = F_53 () ;
V_8 -> V_40 = 1 ;
F_89 ( V_2 , L_13 ) ;
break;
}
F_23 ( V_8 ) ;
F_46 ( & V_8 -> V_93 ) ;
}
int F_90 ( struct V_1 * V_2 )
{
struct V_128 * V_129 ;
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
if ( ! V_8 -> V_38 || ! V_8 -> V_38 -> V_102 ) {
F_89 ( V_2 , L_14 ) ;
F_89 ( V_2 ,
L_15 ) ;
F_23 ( V_8 ) ;
return 0 ;
}
F_23 ( V_8 ) ;
F_48 ( F_91 (
& V_2 -> V_130 , 1 ) ) ;
V_129 = F_92 ( V_131 , V_2 , L_16 ) ;
return F_93 ( V_129 ) ;
}
static int V_131 ( void * V_132 )
{
struct V_1 * V_2 = V_132 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_61 * V_133 ;
T_1 V_134 ;
V_133 = F_94 ( sizeof( * V_133 ) , V_135 ) ;
if ( V_133 ) {
F_83 ( V_2 , V_133 ) ;
V_134 = V_133 -> V_122 . V_123 ;
F_95 ( V_133 ) ;
V_134 = F_84 ( V_134 , 10 ) ;
F_51 ( V_78
L_17 ,
V_8 -> V_37 -> V_79 ? L_10 :
F_52 ( V_8 -> V_37 -> V_80 ) ,
V_8 -> V_37 -> V_59 ,
V_8 -> V_38 ?
F_52 ( V_8 -> V_38 -> V_80 ) :
L_18 ,
( unsigned int ) V_134 ) ;
}
F_96 ( V_2 ) ;
F_97 ( & V_2 -> V_130 , 0 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_12 ;
V_12 = F_56 ( V_2 , V_8 -> V_37 -> V_59 ,
V_8 -> V_34 ,
F_57 ( V_8 -> V_37 ) ,
& V_8 -> V_82 , 0 , 1 ) ;
V_12 = F_58 ( V_2 , V_12 ) ;
F_48 ( V_12 ) ;
return 0 ;
}
int F_98 ( struct V_7 * V_8 )
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
if ( F_99 ( & V_8 -> V_136 ) == 0 ) {
V_137:
F_44 ( & V_8 -> V_116 ) ;
F_44 ( & V_8 -> V_138 ) ;
V_8 -> V_139 = V_140 -> V_141 ;
F_100 ( & V_8 -> V_136 ) ;
F_46 ( & V_8 -> V_138 ) ;
return;
}
F_44 ( & V_8 -> V_138 ) ;
if ( F_99 ( & V_8 -> V_136 ) > 0 &&
V_8 -> V_139 == V_140 -> V_141 ) {
F_48 ( ! F_101 ( & V_8 -> V_116 ) ) ;
F_100 ( & V_8 -> V_136 ) ;
F_46 ( & V_8 -> V_138 ) ;
return;
}
F_46 ( & V_8 -> V_138 ) ;
goto V_137;
}
void F_23 ( struct V_7 * V_8 )
{
F_48 ( ! F_101 ( & V_8 -> V_116 ) ) ;
F_44 ( & V_8 -> V_138 ) ;
F_48 ( F_99 ( & V_8 -> V_136 ) < 1 ) ;
F_48 ( V_8 -> V_139 != V_140 -> V_141 ) ;
F_102 ( & V_8 -> V_136 ) ;
if ( F_99 ( & V_8 -> V_136 ) == 0 ) {
V_8 -> V_139 = 0 ;
F_46 ( & V_8 -> V_138 ) ;
F_46 ( & V_8 -> V_116 ) ;
} else {
F_46 ( & V_8 -> V_138 ) ;
}
}
void F_103 ( struct V_1 * V_2 )
{
F_104 ( & V_2 -> V_88 ) ;
}
void F_105 ( struct V_1 * V_2 , T_3 V_142 )
{
F_106 ( & V_2 -> V_88 , V_142 ) ;
if ( F_66 ( & V_2 -> V_87 ) )
F_67 ( & V_2 -> V_87 ) ;
}
void F_107 ( struct V_1 * V_2 )
{
while ( 1 ) {
F_104 ( & V_2 -> V_88 ) ;
if ( F_108 ( ! F_109 ( V_85 ,
& V_2 -> V_86 ) ) )
break;
F_110 ( V_2 ) ;
F_62 ( V_2 -> V_87 ,
! F_109 ( V_85 ,
& V_2 -> V_86 ) ) ;
}
}
