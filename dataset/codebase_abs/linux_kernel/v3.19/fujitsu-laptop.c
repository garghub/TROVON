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
if ( V_42 -> V_44 . V_45 == 4 )
V_43 = F_1 ( V_46 , 0x1 , 0x4 , 0x3 ) ;
else
V_43 = F_1 ( V_46 , 0x1 , 0x4 , 0x0 ) ;
if ( V_43 != 0 )
F_4 ( V_15 ,
L_15 ,
V_43 ) ;
if ( V_47 )
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
F_17 ( struct V_48 * V_49 ,
struct V_50 * V_51 , char * V_52 )
{
int V_43 ;
V_43 = F_14 () ;
if ( V_43 < 0 )
return V_43 ;
return sprintf ( V_52 , L_17 , V_43 ) ;
}
static T_3
F_18 ( struct V_48 * V_49 ,
struct V_50 * V_51 , char * V_52 )
{
int V_43 ;
V_43 = V_35 -> V_40 ;
if ( V_43 < 0 )
return V_43 ;
return sprintf ( V_52 , L_17 , V_43 ) ;
}
static T_3 F_19 ( struct V_48 * V_49 ,
struct V_50 * V_51 , char * V_52 )
{
int V_43 ;
V_43 = F_13 () ;
if ( V_43 < 0 )
return V_43 ;
return sprintf ( V_52 , L_17 , V_43 ) ;
}
static T_3 F_20 ( struct V_48 * V_49 ,
struct V_50 * V_51 , const char * V_52 ,
T_4 V_53 )
{
int V_34 , V_43 ;
if ( sscanf ( V_52 , L_18 , & V_34 ) != 1
|| ( V_34 < 0 || V_34 >= V_35 -> V_36 ) )
return - V_37 ;
if ( V_47 )
V_43 = F_12 ( V_34 ) ;
else
V_43 = F_10 ( V_34 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_13 () ;
if ( V_43 < 0 )
return V_43 ;
return V_53 ;
}
static T_3
F_21 ( struct V_48 * V_49 ,
struct V_50 * V_51 , const char * V_52 , T_4 V_53 )
{
return V_53 ;
}
static T_3
F_22 ( struct V_48 * V_49 ,
struct V_50 * V_51 , char * V_52 )
{
if ( ! ( V_14 -> V_54 & 0x100 ) )
return sprintf ( V_52 , L_19 ) ;
if ( V_14 -> V_55 & 0x100 )
return sprintf ( V_52 , L_20 ) ;
else
return sprintf ( V_52 , L_21 ) ;
}
static T_3
F_23 ( struct V_48 * V_49 ,
struct V_50 * V_51 , char * V_52 )
{
if ( ! ( V_14 -> V_54 & 0x200 ) )
return sprintf ( V_52 , L_19 ) ;
if ( V_14 -> V_55 & 0x200 )
return sprintf ( V_52 , L_22 ) ;
else
return sprintf ( V_52 , L_23 ) ;
}
static T_3
F_24 ( struct V_48 * V_49 ,
struct V_50 * V_51 , char * V_52 )
{
if ( ! ( V_14 -> V_54 & 0x20 ) )
return sprintf ( V_52 , L_19 ) ;
if ( V_14 -> V_55 & 0x20 )
return sprintf ( V_52 , L_24 ) ;
else
return sprintf ( V_52 , L_25 ) ;
}
static void T_5 F_25 ( const struct V_56 * V_57 )
{
F_26 ( L_26 , V_57 -> V_58 ) ;
if ( V_47 == - 1 ) {
if ( F_27 ( NULL ,
L_27 ) )
V_47 = 1 ;
else
V_47 = 0 ;
F_4 ( V_18 , L_28
L_17 , V_47 ) ;
}
}
static int T_5 F_28 ( const struct V_56 * V_57 )
{
F_25 ( V_57 ) ;
V_35 -> V_59 = V_60 ;
V_35 -> V_61 = V_62 ;
return 1 ;
}
static int T_5 F_29 ( const struct V_56 * V_57 )
{
F_25 ( V_57 ) ;
V_35 -> V_59 = V_60 ;
V_35 -> V_61 = V_62 ;
return 1 ;
}
static int T_5 F_30 ( const struct V_56 * V_57 )
{
F_25 ( V_57 ) ;
V_35 -> V_59 = V_62 ;
V_35 -> V_63 = V_64 ;
V_35 -> V_65 = V_66 ;
return 1 ;
}
static int F_31 ( struct V_67 * V_48 )
{
int V_38 = 0 ;
struct V_68 * V_69 ;
int error ;
if ( ! V_48 )
return - V_37 ;
V_35 -> T_2 = V_48 -> V_13 ;
sprintf ( F_32 ( V_48 ) , L_29 , V_70 ) ;
sprintf ( F_33 ( V_48 ) , L_29 , V_71 ) ;
V_48 -> V_72 = V_35 ;
V_35 -> V_69 = V_69 = F_34 () ;
if ( ! V_69 ) {
error = - V_73 ;
goto V_74;
}
snprintf ( V_35 -> V_75 , sizeof( V_35 -> V_75 ) ,
L_30 , F_35 ( V_48 ) ) ;
V_69 -> V_76 = F_32 ( V_48 ) ;
V_69 -> V_75 = V_35 -> V_75 ;
V_69 -> V_57 . V_77 = V_78 ;
V_69 -> V_57 . V_79 = 0x06 ;
V_69 -> V_49 . V_80 = & V_48 -> V_49 ;
V_69 -> V_81 [ 0 ] = F_36 ( V_82 ) ;
F_37 ( V_83 , V_69 -> V_84 ) ;
F_37 ( V_85 , V_69 -> V_84 ) ;
F_37 ( V_86 , V_69 -> V_84 ) ;
error = F_38 ( V_69 ) ;
if ( error )
goto V_87;
error = F_39 ( V_35 -> T_2 , & V_38 ) ;
if ( error ) {
F_40 ( L_31 ) ;
goto V_88;
}
F_26 ( L_32 ,
F_32 ( V_48 ) , F_41 ( V_48 ) ,
! V_48 -> V_45 . V_38 ? L_33 : L_34 ) ;
V_35 -> V_49 = V_48 ;
if ( F_27 ( V_48 -> V_13 , V_89 ) ) {
F_4 ( V_90 , L_35 ) ;
if ( F_3
( F_42
( V_48 -> V_13 , V_89 , NULL , NULL ) ) )
F_40 ( L_36 ) ;
}
V_47 = V_47 == 1 ? 1 : 0 ;
V_91 = V_91 == 1 ? 1 : 0 ;
F_4 ( V_90 ,
L_37 ,
V_47 , V_91 ) ;
if ( F_14 () <= 0 )
V_35 -> V_36 = V_92 ;
F_13 () ;
return 0 ;
V_88:
F_43 ( V_69 ) ;
V_69 = NULL ;
V_87:
F_44 ( V_69 ) ;
V_74:
return error ;
}
static int F_45 ( struct V_67 * V_48 )
{
struct V_93 * V_35 = F_46 ( V_48 ) ;
struct V_68 * V_69 = V_35 -> V_69 ;
F_43 ( V_69 ) ;
V_35 -> T_2 = NULL ;
return 0 ;
}
static void F_47 ( struct V_67 * V_48 , T_6 V_94 )
{
struct V_68 * V_69 ;
int V_95 ;
int V_96 , V_97 ;
V_69 = V_35 -> V_69 ;
switch ( V_94 ) {
case V_98 :
V_95 = 0 ;
V_96 = V_35 -> V_39 ;
F_13 () ;
V_97 = V_35 -> V_39 ;
F_4 ( V_18 ,
L_38 ,
V_96 , V_97 , V_35 -> V_40 ) ;
if ( V_96 < V_97 ) {
if ( V_91 != 1 ) {
if ( V_47 )
F_12 ( V_97 ) ;
else
F_10 ( V_97 ) ;
}
V_95 = V_83 ;
} else if ( V_96 > V_97 ) {
if ( V_91 != 1 ) {
if ( V_47 )
F_12 ( V_97 ) ;
else
F_10 ( V_97 ) ;
}
V_95 = V_85 ;
}
break;
default:
V_95 = V_86 ;
F_4 ( V_17 ,
L_39 , V_94 ) ;
break;
}
if ( V_95 != 0 ) {
F_48 ( V_69 , V_95 , 1 ) ;
F_49 ( V_69 ) ;
F_48 ( V_69 , V_95 , 0 ) ;
F_49 ( V_69 ) ;
}
}
static int F_50 ( struct V_67 * V_48 )
{
int V_99 = 0 ;
int V_38 = 0 ;
struct V_68 * V_69 ;
int error ;
int V_100 ;
if ( ! V_48 )
return - V_37 ;
V_14 -> T_2 = V_48 -> V_13 ;
sprintf ( F_32 ( V_48 ) , L_29 ,
V_101 ) ;
sprintf ( F_33 ( V_48 ) , L_29 , V_71 ) ;
V_48 -> V_72 = V_14 ;
F_51 ( & V_14 -> V_102 ) ;
error = F_52 ( & V_14 -> V_103 , V_104 * sizeof( int ) ,
V_105 ) ;
if ( error ) {
F_40 ( L_40 ) ;
goto V_74;
}
V_14 -> V_69 = V_69 = F_34 () ;
if ( ! V_69 ) {
error = - V_73 ;
goto V_106;
}
snprintf ( V_14 -> V_75 , sizeof( V_14 -> V_75 ) ,
L_30 , F_35 ( V_48 ) ) ;
V_69 -> V_76 = F_32 ( V_48 ) ;
V_69 -> V_75 = V_14 -> V_75 ;
V_69 -> V_57 . V_77 = V_78 ;
V_69 -> V_57 . V_79 = 0x06 ;
V_69 -> V_49 . V_80 = & V_48 -> V_49 ;
F_37 ( V_82 , V_69 -> V_81 ) ;
F_37 ( V_35 -> V_59 , V_69 -> V_84 ) ;
F_37 ( V_35 -> V_61 , V_69 -> V_84 ) ;
F_37 ( V_35 -> V_63 , V_69 -> V_84 ) ;
F_37 ( V_35 -> V_65 , V_69 -> V_84 ) ;
F_37 ( V_86 , V_69 -> V_84 ) ;
error = F_38 ( V_69 ) ;
if ( error )
goto V_87;
error = F_39 ( V_14 -> T_2 , & V_38 ) ;
if ( error ) {
F_40 ( L_31 ) ;
goto V_88;
}
F_26 ( L_32 ,
F_32 ( V_48 ) , F_41 ( V_48 ) ,
! V_48 -> V_45 . V_38 ? L_33 : L_34 ) ;
V_14 -> V_49 = V_48 ;
if ( F_27 ( V_48 -> V_13 , V_89 ) ) {
F_4 ( V_90 , L_35 ) ;
if ( F_3
( F_42
( V_48 -> V_13 , V_89 , NULL , NULL ) ) )
F_40 ( L_36 ) ;
}
V_100 = 0 ;
while ( F_1 ( V_107 , 0x1 , 0x0 , 0x0 ) != 0
&& ( V_100 ++ ) < V_108 )
;
F_4 ( V_90 , L_41 , V_100 ) ;
V_14 -> V_54 =
F_1 ( V_109 , 0x0 , 0x0 , 0x0 ) ;
if ( V_14 -> V_54 == V_110 )
V_14 -> V_54 = 0 ;
if ( V_14 -> V_54 )
V_14 -> V_55 =
F_1 ( V_109 , 0x4 , 0x0 , 0x0 ) ;
F_26 ( L_42 , F_1 ( V_107 , 0x0 , 0x0 , 0x0 ) ) ;
#if F_53 ( V_111 ) || F_53 ( V_112 )
if ( F_1 ( V_24 , 0x0 , 0x0 , 0x0 ) & V_25 ) {
V_99 = F_54 ( & V_35 -> V_113 -> V_49 ,
& V_114 ) ;
if ( V_99 == 0 ) {
V_14 -> V_115 = 1 ;
} else {
F_40 ( L_43 ,
V_99 ) ;
}
}
if ( ( F_1 ( V_24 , 0x0 , 0x0 , 0x0 ) & V_30 ) &&
( F_1 ( V_107 , 0x0 , 0x0 , 0x0 ) == 0x0 ) ) {
V_99 = F_54 ( & V_35 -> V_113 -> V_49 ,
& V_116 ) ;
if ( V_99 == 0 ) {
V_14 -> V_117 = 1 ;
} else {
F_40 ( L_44 ,
V_99 ) ;
}
}
#endif
return V_99 ;
V_88:
F_43 ( V_69 ) ;
V_69 = NULL ;
V_87:
F_44 ( V_69 ) ;
V_106:
F_55 ( & V_14 -> V_103 ) ;
V_74:
return error ;
}
static int F_56 ( struct V_67 * V_48 )
{
struct V_118 * V_14 = F_46 ( V_48 ) ;
struct V_68 * V_69 = V_14 -> V_69 ;
#if F_53 ( V_111 ) || F_53 ( V_112 )
if ( V_14 -> V_115 )
F_57 ( & V_114 ) ;
if ( V_14 -> V_117 )
F_57 ( & V_116 ) ;
#endif
F_43 ( V_69 ) ;
F_55 ( & V_14 -> V_103 ) ;
V_14 -> T_2 = NULL ;
return 0 ;
}
static void F_58 ( struct V_67 * V_48 , T_6 V_94 )
{
struct V_68 * V_69 ;
int V_95 , V_119 ;
unsigned int V_120 = 1 ;
int V_100 , V_5 ;
V_69 = V_14 -> V_69 ;
if ( V_14 -> V_54 )
V_14 -> V_55 =
F_1 ( V_109 , 0x4 , 0x0 , 0x0 ) ;
switch ( V_94 ) {
case V_98 :
V_100 = 0 ;
while ( ( V_120 =
F_1 ( V_107 , 0x1 , 0x0 , 0x0 ) ) != 0
&& ( V_100 ++ ) < V_108 ) {
switch ( V_120 & 0x4ff ) {
case V_121 :
V_95 = V_35 -> V_59 ;
break;
case V_122 :
V_95 = V_35 -> V_61 ;
break;
case V_123 :
V_95 = V_35 -> V_63 ;
break;
case V_124 :
V_95 = V_35 -> V_65 ;
break;
case 0 :
V_95 = 0 ;
break;
default:
F_4 ( V_17 ,
L_45 , V_120 ) ;
V_95 = - 1 ;
break;
}
if ( V_95 > 0 ) {
F_4 ( V_18 ,
L_46 ,
V_95 ) ;
V_5 = F_59 ( & V_14 -> V_103 ,
( unsigned char * ) & V_95 ,
sizeof( V_95 ) ,
& V_14 -> V_102 ) ;
if ( V_5 != sizeof( V_95 ) ) {
F_4 ( V_17 ,
L_47 ,
V_95 ) ;
} else {
F_48 ( V_69 , V_95 , 1 ) ;
F_49 ( V_69 ) ;
}
} else if ( V_95 == 0 ) {
while ( ( V_5 =
F_60 (
& V_14 -> V_103 ,
( unsigned char * ) & V_119 ,
sizeof( V_119 ) ,
& V_14 -> V_102 ) )
== sizeof( V_119 ) ) {
F_48 ( V_69 , V_119 , 0 ) ;
F_49 ( V_69 ) ;
F_4 ( V_18 ,
L_48 ,
V_119 ) ;
}
}
}
break;
default:
V_95 = V_86 ;
F_4 ( V_17 ,
L_49 , V_94 ) ;
F_48 ( V_69 , V_95 , 1 ) ;
F_49 ( V_69 ) ;
F_48 ( V_69 , V_95 , 0 ) ;
F_49 ( V_69 ) ;
break;
}
}
static int T_5 F_61 ( void )
{
int V_43 , V_99 , V_36 ;
if ( V_125 )
return - V_16 ;
V_35 = F_62 ( sizeof( struct V_93 ) , V_105 ) ;
if ( ! V_35 )
return - V_73 ;
V_35 -> V_59 = V_126 ;
V_35 -> V_61 = V_127 ;
V_35 -> V_63 = V_128 ;
V_35 -> V_65 = V_129 ;
F_63 ( V_130 ) ;
V_99 = F_64 ( & V_131 ) ;
if ( V_99 < 0 ) {
V_43 = - V_16 ;
goto V_132;
}
V_35 -> V_113 = F_65 ( L_50 , - 1 ) ;
if ( ! V_35 -> V_113 ) {
V_43 = - V_73 ;
goto V_133;
}
V_43 = F_66 ( V_35 -> V_113 ) ;
if ( V_43 )
goto V_134;
V_43 =
F_67 ( & V_35 -> V_113 -> V_49 . V_135 ,
& V_136 ) ;
if ( V_43 )
goto V_137;
if ( ! F_68 () ) {
struct V_138 V_44 ;
memset ( & V_44 , 0 , sizeof( struct V_138 ) ) ;
V_36 = V_35 -> V_36 ;
V_44 . type = V_139 ;
V_44 . V_36 = V_36 - 1 ;
V_35 -> V_140 = F_69 ( L_50 ,
NULL , NULL ,
& V_141 ,
& V_44 ) ;
if ( F_70 ( V_35 -> V_140 ) ) {
V_43 = F_71 ( V_35 -> V_140 ) ;
V_35 -> V_140 = NULL ;
goto V_142;
}
V_35 -> V_140 -> V_44 . V_22 = V_35 -> V_39 ;
}
V_43 = F_72 ( & V_143 ) ;
if ( V_43 )
goto V_144;
V_14 = F_62 ( sizeof( struct V_118 ) , V_105 ) ;
if ( ! V_14 ) {
V_43 = - V_73 ;
goto V_145;
}
V_99 = F_64 ( & V_146 ) ;
if ( V_99 < 0 ) {
V_43 = - V_16 ;
goto V_147;
}
if ( ! F_68 () ) {
if ( F_1 ( V_46 , 0x2 , 0x4 , 0x0 ) == 3 )
V_35 -> V_140 -> V_44 . V_45 = 4 ;
else
V_35 -> V_140 -> V_44 . V_45 = 0 ;
}
F_26 ( L_51 V_148 L_52 ) ;
return 0 ;
V_147:
F_73 ( V_14 ) ;
V_145:
F_74 ( & V_143 ) ;
V_144:
F_75 ( V_35 -> V_140 ) ;
V_142:
F_76 ( & V_35 -> V_113 -> V_49 . V_135 ,
& V_136 ) ;
V_137:
F_77 ( V_35 -> V_113 ) ;
V_134:
F_78 ( V_35 -> V_113 ) ;
V_133:
F_79 ( & V_131 ) ;
V_132:
F_73 ( V_35 ) ;
return V_43 ;
}
static void T_7 F_80 ( void )
{
F_79 ( & V_146 ) ;
F_73 ( V_14 ) ;
F_74 ( & V_143 ) ;
F_75 ( V_35 -> V_140 ) ;
F_76 ( & V_35 -> V_113 -> V_49 . V_135 ,
& V_136 ) ;
F_81 ( V_35 -> V_113 ) ;
F_79 ( & V_131 ) ;
F_73 ( V_35 ) ;
F_26 ( L_53 ) ;
}
