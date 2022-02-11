static int F_1 ( int V_1 , int V_2 , int V_3 , int V_4 )
{
T_1 V_5 = V_6 ;
union V_7 V_8 [ 4 ] = {
{ . type = V_9 } ,
{ . type = V_9 } ,
{ . type = V_9 } ,
{ . type = V_9 }
} ;
struct V_10 V_11 = { 4 , & V_8 [ 0 ] } ;
unsigned long long V_12 ;
T_2 V_13 = NULL ;
V_5 = F_2 ( V_14 -> T_2 , L_1 , & V_13 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( V_15 ,
L_2 ) ;
return - V_16 ;
}
V_8 [ 0 ] . integer . V_12 = V_1 ;
V_8 [ 1 ] . integer . V_12 = V_2 ;
V_8 [ 2 ] . integer . V_12 = V_3 ;
V_8 [ 3 ] . integer . V_12 = V_4 ;
V_5 = F_5 ( V_13 , NULL , & V_11 , & V_12 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( V_17 ,
L_3 ,
V_1 , V_2 , V_3 , V_4 ) ;
return - V_16 ;
}
F_4 ( V_18 ,
L_4 ,
V_1 , V_2 , V_3 , V_4 , ( int ) V_12 ) ;
return V_12 ;
}
static void F_6 ( struct V_19 * V_20 ,
enum V_21 V_22 )
{
if ( V_22 >= V_23 ) {
F_1 ( V_24 , 0x1 , V_25 , V_26 ) ;
F_1 ( V_24 , 0x1 , V_27 , V_26 ) ;
} else if ( V_22 >= V_28 ) {
F_1 ( V_24 , 0x1 , V_25 , V_26 ) ;
F_1 ( V_24 , 0x1 , V_27 , V_29 ) ;
} else {
F_1 ( V_24 , 0x1 , V_25 , V_29 ) ;
}
}
static void F_7 ( struct V_19 * V_20 ,
enum V_21 V_22 )
{
if ( V_22 >= V_23 )
F_1 ( V_24 , 0x1 , V_30 , V_26 ) ;
else
F_1 ( V_24 , 0x1 , V_30 , V_29 ) ;
}
static enum V_21 F_8 ( struct V_19 * V_20 )
{
enum V_21 V_22 = V_31 ;
int V_32 , V_33 ;
V_32 = F_1 ( V_24 , 0x2 , V_25 , 0x0 ) ;
if ( V_32 == V_26 ) {
V_22 = V_28 ;
V_33 = F_1 ( V_24 , 0x2 , V_27 , 0x0 ) ;
if ( V_33 == V_26 )
V_22 = V_23 ;
}
return V_22 ;
}
static enum V_21 F_9 ( struct V_19 * V_20 )
{
enum V_21 V_22 = V_31 ;
if ( F_1 ( V_24 , 0x2 , V_30 , 0x0 ) == V_26 )
V_22 = V_23 ;
return V_22 ;
}
static int F_10 ( int V_34 )
{
T_1 V_5 = V_6 ;
T_2 V_13 = NULL ;
F_4 ( V_18 , L_5 ,
V_34 ) ;
if ( V_34 < 0 || V_34 >= V_35 -> V_36 )
return - V_37 ;
V_5 = F_2 ( V_35 -> T_2 , L_6 , & V_13 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( V_15 , L_7 ) ;
return - V_16 ;
}
V_5 = F_11 ( V_13 , NULL , V_34 ) ;
if ( F_3 ( V_5 ) )
return - V_16 ;
return 0 ;
}
static int F_12 ( int V_34 )
{
T_1 V_5 = V_6 ;
T_2 V_13 = NULL ;
F_4 ( V_18 , L_8 ,
V_34 ) ;
if ( V_34 < 0 || V_34 >= V_35 -> V_36 )
return - V_37 ;
V_5 = F_2 ( V_35 -> T_2 , L_9 , & V_13 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( V_15 , L_10 ) ;
return - V_16 ;
}
V_5 = F_11 ( V_13 , NULL , V_34 ) ;
if ( F_3 ( V_5 ) )
return - V_16 ;
return 0 ;
}
static int F_13 ( void )
{
unsigned long long V_38 = 0 ;
T_1 V_5 = V_6 ;
F_4 ( V_18 , L_11 ) ;
V_5 =
F_5 ( V_35 -> T_2 , L_12 , NULL , & V_38 ) ;
if ( F_3 ( V_5 ) )
return 0 ;
V_35 -> V_39 = V_38 & 0x0fffffff ;
if ( V_38 & 0x80000000 )
V_35 -> V_40 = 1 ;
else
V_35 -> V_40 = 0 ;
return V_35 -> V_39 ;
}
static int F_14 ( void )
{
unsigned long long V_38 = 0 ;
T_1 V_5 = V_6 ;
F_4 ( V_18 , L_13 ) ;
V_5 =
F_5 ( V_35 -> T_2 , L_14 , NULL , & V_38 ) ;
if ( F_3 ( V_5 ) )
return - 1 ;
V_35 -> V_36 = V_38 ;
return V_35 -> V_36 ;
}
static int F_15 ( struct V_41 * V_42 )
{
return F_13 () ;
}
static int F_16 ( struct V_41 * V_42 )
{
int V_43 ;
if ( V_42 -> V_44 . V_45 == V_46 )
V_43 = F_1 ( V_47 , 0x1 , 0x4 , 0x3 ) ;
else
V_43 = F_1 ( V_47 , 0x1 , 0x4 , 0x0 ) ;
if ( V_43 != 0 )
F_4 ( V_15 ,
L_15 ,
V_43 ) ;
if ( V_48 )
V_43 = F_12 ( V_42 -> V_44 . V_22 ) ;
else
V_43 = F_10 ( V_42 -> V_44 . V_22 ) ;
if ( V_43 != 0 )
F_4 ( V_15 ,
L_16 ,
V_43 ) ;
return V_43 ;
}
static T_3
F_17 ( struct V_49 * V_50 ,
struct V_51 * V_52 , char * V_53 )
{
int V_43 ;
V_43 = F_14 () ;
if ( V_43 < 0 )
return V_43 ;
return sprintf ( V_53 , L_17 , V_43 ) ;
}
static T_3
F_18 ( struct V_49 * V_50 ,
struct V_51 * V_52 , char * V_53 )
{
int V_43 ;
V_43 = V_35 -> V_40 ;
if ( V_43 < 0 )
return V_43 ;
return sprintf ( V_53 , L_17 , V_43 ) ;
}
static T_3 F_19 ( struct V_49 * V_50 ,
struct V_51 * V_52 , char * V_53 )
{
int V_43 ;
V_43 = F_13 () ;
if ( V_43 < 0 )
return V_43 ;
return sprintf ( V_53 , L_17 , V_43 ) ;
}
static T_3 F_20 ( struct V_49 * V_50 ,
struct V_51 * V_52 , const char * V_53 ,
T_4 V_54 )
{
int V_34 , V_43 ;
if ( sscanf ( V_53 , L_18 , & V_34 ) != 1
|| ( V_34 < 0 || V_34 >= V_35 -> V_36 ) )
return - V_37 ;
if ( V_48 )
V_43 = F_12 ( V_34 ) ;
else
V_43 = F_10 ( V_34 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_13 () ;
if ( V_43 < 0 )
return V_43 ;
return V_54 ;
}
static T_3
F_21 ( struct V_49 * V_50 ,
struct V_51 * V_52 , const char * V_53 , T_4 V_54 )
{
return V_54 ;
}
static T_3
F_22 ( struct V_49 * V_50 ,
struct V_51 * V_52 , char * V_53 )
{
if ( ! ( V_14 -> V_55 & 0x100 ) )
return sprintf ( V_53 , L_19 ) ;
if ( V_14 -> V_56 & 0x100 )
return sprintf ( V_53 , L_20 ) ;
else
return sprintf ( V_53 , L_21 ) ;
}
static T_3
F_23 ( struct V_49 * V_50 ,
struct V_51 * V_52 , char * V_53 )
{
if ( ! ( V_14 -> V_55 & 0x200 ) )
return sprintf ( V_53 , L_19 ) ;
if ( V_14 -> V_56 & 0x200 )
return sprintf ( V_53 , L_22 ) ;
else
return sprintf ( V_53 , L_23 ) ;
}
static T_3
F_24 ( struct V_49 * V_50 ,
struct V_51 * V_52 , char * V_53 )
{
if ( ! ( V_14 -> V_55 & 0x20 ) )
return sprintf ( V_53 , L_19 ) ;
if ( V_14 -> V_56 & 0x20 )
return sprintf ( V_53 , L_24 ) ;
else
return sprintf ( V_53 , L_25 ) ;
}
static void T_5 F_25 ( const struct V_57 * V_58 )
{
F_26 ( L_26 , V_58 -> V_59 ) ;
if ( V_48 == - 1 ) {
if ( F_27 ( NULL ,
L_27 ) )
V_48 = 1 ;
else
V_48 = 0 ;
F_4 ( V_18 , L_28
L_17 , V_48 ) ;
}
}
static int T_5 F_28 ( const struct V_57 * V_58 )
{
F_25 ( V_58 ) ;
V_35 -> V_60 = V_61 ;
V_35 -> V_62 = V_63 ;
return 1 ;
}
static int T_5 F_29 ( const struct V_57 * V_58 )
{
F_25 ( V_58 ) ;
V_35 -> V_60 = V_61 ;
V_35 -> V_62 = V_63 ;
return 1 ;
}
static int T_5 F_30 ( const struct V_57 * V_58 )
{
F_25 ( V_58 ) ;
V_35 -> V_60 = V_63 ;
V_35 -> V_64 = V_65 ;
V_35 -> V_66 = V_67 ;
return 1 ;
}
static int F_31 ( struct V_68 * V_49 )
{
int V_38 = 0 ;
struct V_69 * V_70 ;
int error ;
if ( ! V_49 )
return - V_37 ;
V_35 -> T_2 = V_49 -> V_13 ;
sprintf ( F_32 ( V_49 ) , L_29 , V_71 ) ;
sprintf ( F_33 ( V_49 ) , L_29 , V_72 ) ;
V_49 -> V_73 = V_35 ;
V_35 -> V_70 = V_70 = F_34 () ;
if ( ! V_70 ) {
error = - V_74 ;
goto V_75;
}
snprintf ( V_35 -> V_76 , sizeof( V_35 -> V_76 ) ,
L_30 , F_35 ( V_49 ) ) ;
V_70 -> V_77 = F_32 ( V_49 ) ;
V_70 -> V_76 = V_35 -> V_76 ;
V_70 -> V_58 . V_78 = V_79 ;
V_70 -> V_58 . V_80 = 0x06 ;
V_70 -> V_50 . V_81 = & V_49 -> V_50 ;
V_70 -> V_82 [ 0 ] = F_36 ( V_83 ) ;
F_37 ( V_84 , V_70 -> V_85 ) ;
F_37 ( V_86 , V_70 -> V_85 ) ;
F_37 ( V_87 , V_70 -> V_85 ) ;
error = F_38 ( V_70 ) ;
if ( error )
goto V_88;
error = F_39 ( V_35 -> T_2 , & V_38 ) ;
if ( error ) {
F_40 ( L_31 ) ;
goto V_89;
}
F_26 ( L_32 ,
F_32 ( V_49 ) , F_41 ( V_49 ) ,
! V_49 -> V_45 . V_38 ? L_33 : L_34 ) ;
V_35 -> V_50 = V_49 ;
if ( F_27 ( V_49 -> V_13 , V_90 ) ) {
F_4 ( V_91 , L_35 ) ;
if ( F_3
( F_42
( V_49 -> V_13 , V_90 , NULL , NULL ) ) )
F_40 ( L_36 ) ;
}
V_48 = V_48 == 1 ? 1 : 0 ;
V_92 = V_92 == 1 ? 1 : 0 ;
F_4 ( V_91 ,
L_37 ,
V_48 , V_92 ) ;
if ( F_14 () <= 0 )
V_35 -> V_36 = V_93 ;
F_13 () ;
return 0 ;
V_89:
F_43 ( V_70 ) ;
V_70 = NULL ;
V_88:
F_44 ( V_70 ) ;
V_75:
return error ;
}
static int F_45 ( struct V_68 * V_49 )
{
struct V_94 * V_35 = F_46 ( V_49 ) ;
struct V_69 * V_70 = V_35 -> V_70 ;
F_43 ( V_70 ) ;
V_35 -> T_2 = NULL ;
return 0 ;
}
static void F_47 ( struct V_68 * V_49 , T_6 V_95 )
{
struct V_69 * V_70 ;
int V_96 ;
int V_97 , V_98 ;
V_70 = V_35 -> V_70 ;
switch ( V_95 ) {
case V_99 :
V_96 = 0 ;
V_97 = V_35 -> V_39 ;
F_13 () ;
V_98 = V_35 -> V_39 ;
F_4 ( V_18 ,
L_38 ,
V_97 , V_98 , V_35 -> V_40 ) ;
if ( V_97 < V_98 ) {
if ( V_92 != 1 ) {
if ( V_48 )
F_12 ( V_98 ) ;
else
F_10 ( V_98 ) ;
}
V_96 = V_84 ;
} else if ( V_97 > V_98 ) {
if ( V_92 != 1 ) {
if ( V_48 )
F_12 ( V_98 ) ;
else
F_10 ( V_98 ) ;
}
V_96 = V_86 ;
}
break;
default:
V_96 = V_87 ;
F_4 ( V_17 ,
L_39 , V_95 ) ;
break;
}
if ( V_96 != 0 ) {
F_48 ( V_70 , V_96 , 1 ) ;
F_49 ( V_70 ) ;
F_48 ( V_70 , V_96 , 0 ) ;
F_49 ( V_70 ) ;
}
}
static int F_50 ( struct V_68 * V_49 )
{
int V_100 = 0 ;
int V_38 = 0 ;
struct V_69 * V_70 ;
int error ;
int V_101 ;
if ( ! V_49 )
return - V_37 ;
V_14 -> T_2 = V_49 -> V_13 ;
sprintf ( F_32 ( V_49 ) , L_29 ,
V_102 ) ;
sprintf ( F_33 ( V_49 ) , L_29 , V_72 ) ;
V_49 -> V_73 = V_14 ;
F_51 ( & V_14 -> V_103 ) ;
error = F_52 ( & V_14 -> V_104 , V_105 * sizeof( int ) ,
V_106 ) ;
if ( error ) {
F_40 ( L_40 ) ;
goto V_75;
}
V_14 -> V_70 = V_70 = F_34 () ;
if ( ! V_70 ) {
error = - V_74 ;
goto V_107;
}
snprintf ( V_14 -> V_76 , sizeof( V_14 -> V_76 ) ,
L_30 , F_35 ( V_49 ) ) ;
V_70 -> V_77 = F_32 ( V_49 ) ;
V_70 -> V_76 = V_14 -> V_76 ;
V_70 -> V_58 . V_78 = V_79 ;
V_70 -> V_58 . V_80 = 0x06 ;
V_70 -> V_50 . V_81 = & V_49 -> V_50 ;
F_37 ( V_83 , V_70 -> V_82 ) ;
F_37 ( V_35 -> V_60 , V_70 -> V_85 ) ;
F_37 ( V_35 -> V_62 , V_70 -> V_85 ) ;
F_37 ( V_35 -> V_64 , V_70 -> V_85 ) ;
F_37 ( V_35 -> V_66 , V_70 -> V_85 ) ;
F_37 ( V_87 , V_70 -> V_85 ) ;
error = F_38 ( V_70 ) ;
if ( error )
goto V_88;
error = F_39 ( V_14 -> T_2 , & V_38 ) ;
if ( error ) {
F_40 ( L_31 ) ;
goto V_89;
}
F_26 ( L_32 ,
F_32 ( V_49 ) , F_41 ( V_49 ) ,
! V_49 -> V_45 . V_38 ? L_33 : L_34 ) ;
V_14 -> V_50 = V_49 ;
if ( F_27 ( V_49 -> V_13 , V_90 ) ) {
F_4 ( V_91 , L_35 ) ;
if ( F_3
( F_42
( V_49 -> V_13 , V_90 , NULL , NULL ) ) )
F_40 ( L_36 ) ;
}
V_101 = 0 ;
while ( F_1 ( V_108 , 0x1 , 0x0 , 0x0 ) != 0
&& ( V_101 ++ ) < V_109 )
;
F_4 ( V_91 , L_41 , V_101 ) ;
V_14 -> V_55 =
F_1 ( V_110 , 0x0 , 0x0 , 0x0 ) ;
if ( V_14 -> V_55 == V_111 )
V_14 -> V_55 = 0 ;
if ( V_14 -> V_55 )
V_14 -> V_56 =
F_1 ( V_110 , 0x4 , 0x0 , 0x0 ) ;
F_26 ( L_42 , F_1 ( V_108 , 0x0 , 0x0 , 0x0 ) ) ;
#if F_53 ( V_112 ) || F_53 ( V_113 )
if ( F_1 ( V_24 , 0x0 , 0x0 , 0x0 ) & V_25 ) {
V_100 = F_54 ( & V_35 -> V_114 -> V_50 ,
& V_115 ) ;
if ( V_100 == 0 ) {
V_14 -> V_116 = 1 ;
} else {
F_40 ( L_43 ,
V_100 ) ;
}
}
if ( ( F_1 ( V_24 , 0x0 , 0x0 , 0x0 ) & V_30 ) &&
( F_1 ( V_108 , 0x0 , 0x0 , 0x0 ) == 0x0 ) ) {
V_100 = F_54 ( & V_35 -> V_114 -> V_50 ,
& V_117 ) ;
if ( V_100 == 0 ) {
V_14 -> V_118 = 1 ;
} else {
F_40 ( L_44 ,
V_100 ) ;
}
}
#endif
return V_100 ;
V_89:
F_43 ( V_70 ) ;
V_70 = NULL ;
V_88:
F_44 ( V_70 ) ;
V_107:
F_55 ( & V_14 -> V_104 ) ;
V_75:
return error ;
}
static int F_56 ( struct V_68 * V_49 )
{
struct V_119 * V_14 = F_46 ( V_49 ) ;
struct V_69 * V_70 = V_14 -> V_70 ;
#if F_53 ( V_112 ) || F_53 ( V_113 )
if ( V_14 -> V_116 )
F_57 ( & V_115 ) ;
if ( V_14 -> V_118 )
F_57 ( & V_117 ) ;
#endif
F_43 ( V_70 ) ;
F_55 ( & V_14 -> V_104 ) ;
V_14 -> T_2 = NULL ;
return 0 ;
}
static void F_58 ( struct V_68 * V_49 , T_6 V_95 )
{
struct V_69 * V_70 ;
int V_96 , V_120 ;
unsigned int V_121 = 1 ;
int V_101 , V_5 ;
V_70 = V_14 -> V_70 ;
if ( V_14 -> V_55 )
V_14 -> V_56 =
F_1 ( V_110 , 0x4 , 0x0 , 0x0 ) ;
switch ( V_95 ) {
case V_99 :
V_101 = 0 ;
while ( ( V_121 =
F_1 ( V_108 , 0x1 , 0x0 , 0x0 ) ) != 0
&& ( V_101 ++ ) < V_109 ) {
switch ( V_121 & 0x4ff ) {
case V_122 :
V_96 = V_35 -> V_60 ;
break;
case V_123 :
V_96 = V_35 -> V_62 ;
break;
case V_124 :
V_96 = V_35 -> V_64 ;
break;
case V_125 :
V_96 = V_35 -> V_66 ;
break;
case 0 :
V_96 = 0 ;
break;
default:
F_4 ( V_17 ,
L_45 , V_121 ) ;
V_96 = - 1 ;
break;
}
if ( V_96 > 0 ) {
F_4 ( V_18 ,
L_46 ,
V_96 ) ;
V_5 = F_59 ( & V_14 -> V_104 ,
( unsigned char * ) & V_96 ,
sizeof( V_96 ) ,
& V_14 -> V_103 ) ;
if ( V_5 != sizeof( V_96 ) ) {
F_4 ( V_17 ,
L_47 ,
V_96 ) ;
} else {
F_48 ( V_70 , V_96 , 1 ) ;
F_49 ( V_70 ) ;
}
} else if ( V_96 == 0 ) {
while ( ( V_5 =
F_60 (
& V_14 -> V_104 ,
( unsigned char * ) & V_120 ,
sizeof( V_120 ) ,
& V_14 -> V_103 ) )
== sizeof( V_120 ) ) {
F_48 ( V_70 , V_120 , 0 ) ;
F_49 ( V_70 ) ;
F_4 ( V_18 ,
L_48 ,
V_120 ) ;
}
}
}
break;
default:
V_96 = V_87 ;
F_4 ( V_17 ,
L_49 , V_95 ) ;
F_48 ( V_70 , V_96 , 1 ) ;
F_49 ( V_70 ) ;
F_48 ( V_70 , V_96 , 0 ) ;
F_49 ( V_70 ) ;
break;
}
}
static int T_5 F_61 ( void )
{
int V_43 , V_100 , V_36 ;
if ( V_126 )
return - V_16 ;
V_35 = F_62 ( sizeof( struct V_94 ) , V_106 ) ;
if ( ! V_35 )
return - V_74 ;
V_35 -> V_60 = V_127 ;
V_35 -> V_62 = V_128 ;
V_35 -> V_64 = V_129 ;
V_35 -> V_66 = V_130 ;
F_63 ( V_131 ) ;
V_100 = F_64 ( & V_132 ) ;
if ( V_100 < 0 ) {
V_43 = - V_16 ;
goto V_133;
}
V_35 -> V_114 = F_65 ( L_50 , - 1 ) ;
if ( ! V_35 -> V_114 ) {
V_43 = - V_74 ;
goto V_134;
}
V_43 = F_66 ( V_35 -> V_114 ) ;
if ( V_43 )
goto V_135;
V_43 =
F_67 ( & V_35 -> V_114 -> V_50 . V_136 ,
& V_137 ) ;
if ( V_43 )
goto V_138;
if ( F_68 () == V_139 ) {
struct V_140 V_44 ;
memset ( & V_44 , 0 , sizeof( struct V_140 ) ) ;
V_36 = V_35 -> V_36 ;
V_44 . type = V_141 ;
V_44 . V_36 = V_36 - 1 ;
V_35 -> V_142 = F_69 ( L_50 ,
NULL , NULL ,
& V_143 ,
& V_44 ) ;
if ( F_70 ( V_35 -> V_142 ) ) {
V_43 = F_71 ( V_35 -> V_142 ) ;
V_35 -> V_142 = NULL ;
goto V_144;
}
V_35 -> V_142 -> V_44 . V_22 = V_35 -> V_39 ;
}
V_43 = F_72 ( & V_145 ) ;
if ( V_43 )
goto V_146;
V_14 = F_62 ( sizeof( struct V_119 ) , V_106 ) ;
if ( ! V_14 ) {
V_43 = - V_74 ;
goto V_147;
}
V_100 = F_64 ( & V_148 ) ;
if ( V_100 < 0 ) {
V_43 = - V_16 ;
goto V_149;
}
if ( F_68 () == V_139 ) {
if ( F_1 ( V_47 , 0x2 , 0x4 , 0x0 ) == 3 )
V_35 -> V_142 -> V_44 . V_45 = V_46 ;
else
V_35 -> V_142 -> V_44 . V_45 = V_150 ;
}
F_26 ( L_51 V_151 L_52 ) ;
return 0 ;
V_149:
F_73 ( V_14 ) ;
V_147:
F_74 ( & V_145 ) ;
V_146:
F_75 ( V_35 -> V_142 ) ;
V_144:
F_76 ( & V_35 -> V_114 -> V_50 . V_136 ,
& V_137 ) ;
V_138:
F_77 ( V_35 -> V_114 ) ;
V_135:
F_78 ( V_35 -> V_114 ) ;
V_134:
F_79 ( & V_132 ) ;
V_133:
F_73 ( V_35 ) ;
return V_43 ;
}
static void T_7 F_80 ( void )
{
F_79 ( & V_148 ) ;
F_73 ( V_14 ) ;
F_74 ( & V_145 ) ;
F_75 ( V_35 -> V_142 ) ;
F_76 ( & V_35 -> V_114 -> V_50 . V_136 ,
& V_137 ) ;
F_81 ( V_35 -> V_114 ) ;
F_79 ( & V_132 ) ;
F_73 ( V_35 ) ;
F_26 ( L_53 ) ;
}
