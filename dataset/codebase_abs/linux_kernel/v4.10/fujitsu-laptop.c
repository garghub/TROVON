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
static int F_6 ( struct V_19 * V_20 ,
enum V_21 V_22 )
{
if ( V_22 >= V_23 ) {
F_1 ( V_24 , 0x1 , V_25 , V_26 ) ;
return F_1 ( V_24 , 0x1 , V_27 , V_26 ) ;
} else if ( V_22 >= V_28 ) {
F_1 ( V_24 , 0x1 , V_25 , V_26 ) ;
return F_1 ( V_24 , 0x1 , V_27 , V_29 ) ;
} else {
return F_1 ( V_24 , 0x1 , V_25 , V_29 ) ;
}
}
static int F_7 ( struct V_19 * V_20 ,
enum V_21 V_22 )
{
if ( V_22 >= V_23 )
return F_1 ( V_24 , 0x1 , V_30 , V_26 ) ;
else
return F_1 ( V_24 , 0x1 , V_30 , V_29 ) ;
}
static int F_8 ( struct V_19 * V_20 ,
enum V_21 V_22 )
{
if ( V_22 >= V_23 )
return F_1 ( V_31 , 0x5 , V_32 , V_32 ) ;
else
return F_1 ( V_31 , 0x5 , V_32 , 0x0 ) ;
}
static int F_9 ( struct V_19 * V_20 ,
enum V_21 V_22 )
{
int V_33 ;
V_33 = F_1 ( V_24 , 0x2 , V_34 , 0x0 ) ;
if ( V_22 >= V_23 )
return F_1 ( V_24 , 0x1 , V_34 , V_33 | V_35 ) ;
else
return F_1 ( V_24 , 0x1 , V_34 , V_33 & ~ V_35 ) ;
}
static enum V_21 F_10 ( struct V_19 * V_20 )
{
enum V_21 V_22 = V_36 ;
int V_37 , V_38 ;
V_37 = F_1 ( V_24 , 0x2 , V_25 , 0x0 ) ;
if ( V_37 == V_26 ) {
V_22 = V_28 ;
V_38 = F_1 ( V_24 , 0x2 , V_27 , 0x0 ) ;
if ( V_38 == V_26 )
V_22 = V_23 ;
}
return V_22 ;
}
static enum V_21 F_11 ( struct V_19 * V_20 )
{
enum V_21 V_22 = V_36 ;
if ( F_1 ( V_24 , 0x2 , V_30 , 0x0 ) == V_26 )
V_22 = V_23 ;
return V_22 ;
}
static enum V_21 F_12 ( struct V_19 * V_20 )
{
enum V_21 V_22 = V_36 ;
if ( F_1 ( V_31 , 0x4 , 0x0 , 0x0 ) & V_32 )
V_22 = V_23 ;
return V_22 ;
}
static enum V_21 F_13 ( struct V_19 * V_20 )
{
enum V_21 V_22 = V_36 ;
if ( F_1 ( V_24 , 0x2 , V_34 , 0x0 ) & V_35 )
V_22 = V_23 ;
return V_22 ;
}
static int F_14 ( int V_39 )
{
T_1 V_5 = V_6 ;
T_2 V_13 = NULL ;
F_4 ( V_18 , L_5 ,
V_39 ) ;
if ( V_39 < 0 || V_39 >= V_40 -> V_41 )
return - V_42 ;
V_5 = F_2 ( V_40 -> T_2 , L_6 , & V_13 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( V_15 , L_7 ) ;
return - V_16 ;
}
V_5 = F_15 ( V_13 , NULL , V_39 ) ;
if ( F_3 ( V_5 ) )
return - V_16 ;
return 0 ;
}
static int F_16 ( int V_39 )
{
T_1 V_5 = V_6 ;
T_2 V_13 = NULL ;
F_4 ( V_18 , L_8 ,
V_39 ) ;
if ( V_39 < 0 || V_39 >= V_40 -> V_41 )
return - V_42 ;
V_5 = F_2 ( V_40 -> T_2 , L_9 , & V_13 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( V_15 , L_10 ) ;
return - V_16 ;
}
V_5 = F_15 ( V_13 , NULL , V_39 ) ;
if ( F_3 ( V_5 ) )
return - V_16 ;
return 0 ;
}
static int F_17 ( void )
{
unsigned long long V_43 = 0 ;
T_1 V_5 = V_6 ;
F_4 ( V_18 , L_11 ) ;
V_5 =
F_5 ( V_40 -> T_2 , L_12 , NULL , & V_43 ) ;
if ( F_3 ( V_5 ) )
return 0 ;
V_40 -> V_44 = V_43 & 0x0fffffff ;
if ( V_43 & 0x80000000 )
V_40 -> V_45 = 1 ;
else
V_40 -> V_45 = 0 ;
return V_40 -> V_44 ;
}
static int F_18 ( void )
{
unsigned long long V_43 = 0 ;
T_1 V_5 = V_6 ;
F_4 ( V_18 , L_13 ) ;
V_5 =
F_5 ( V_40 -> T_2 , L_14 , NULL , & V_43 ) ;
if ( F_3 ( V_5 ) )
return - 1 ;
V_40 -> V_41 = V_43 ;
return V_40 -> V_41 ;
}
static int F_19 ( struct V_46 * V_47 )
{
return F_17 () ;
}
static int F_20 ( struct V_46 * V_47 )
{
int V_48 ;
if ( V_47 -> V_49 . V_50 == V_51 )
V_48 = F_1 ( V_52 , 0x1 , 0x4 , 0x3 ) ;
else
V_48 = F_1 ( V_52 , 0x1 , 0x4 , 0x0 ) ;
if ( V_48 != 0 )
F_4 ( V_15 ,
L_15 ,
V_48 ) ;
if ( V_53 )
V_48 = F_16 ( V_47 -> V_49 . V_22 ) ;
else
V_48 = F_14 ( V_47 -> V_49 . V_22 ) ;
if ( V_48 != 0 )
F_4 ( V_15 ,
L_16 ,
V_48 ) ;
return V_48 ;
}
static T_3
F_21 ( struct V_54 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
int V_48 ;
V_48 = F_18 () ;
if ( V_48 < 0 )
return V_48 ;
return sprintf ( V_58 , L_17 , V_48 ) ;
}
static T_3
F_22 ( struct V_54 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
int V_48 ;
V_48 = V_40 -> V_45 ;
if ( V_48 < 0 )
return V_48 ;
return sprintf ( V_58 , L_17 , V_48 ) ;
}
static T_3 F_23 ( struct V_54 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
int V_48 ;
V_48 = F_17 () ;
if ( V_48 < 0 )
return V_48 ;
return sprintf ( V_58 , L_17 , V_48 ) ;
}
static T_3 F_24 ( struct V_54 * V_55 ,
struct V_56 * V_57 , const char * V_58 ,
T_4 V_59 )
{
int V_39 , V_48 ;
if ( sscanf ( V_58 , L_18 , & V_39 ) != 1
|| ( V_39 < 0 || V_39 >= V_40 -> V_41 ) )
return - V_42 ;
if ( V_53 )
V_48 = F_16 ( V_39 ) ;
else
V_48 = F_14 ( V_39 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_17 () ;
if ( V_48 < 0 )
return V_48 ;
return V_59 ;
}
static T_3
F_25 ( struct V_54 * V_55 ,
struct V_56 * V_57 , const char * V_58 , T_4 V_59 )
{
return V_59 ;
}
static T_3
F_26 ( struct V_54 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
if ( ! ( V_14 -> V_60 & 0x100 ) )
return sprintf ( V_58 , L_19 ) ;
if ( V_14 -> V_61 & 0x100 )
return sprintf ( V_58 , L_20 ) ;
else
return sprintf ( V_58 , L_21 ) ;
}
static T_3
F_27 ( struct V_54 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
if ( ! ( V_14 -> V_60 & 0x200 ) )
return sprintf ( V_58 , L_19 ) ;
if ( V_14 -> V_61 & 0x200 )
return sprintf ( V_58 , L_22 ) ;
else
return sprintf ( V_58 , L_23 ) ;
}
static T_3
F_28 ( struct V_54 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
if ( ! ( V_14 -> V_60 & 0x20 ) )
return sprintf ( V_58 , L_19 ) ;
if ( V_14 -> V_61 & 0x20 )
return sprintf ( V_58 , L_24 ) ;
else
return sprintf ( V_58 , L_25 ) ;
}
static void T_5 F_29 ( const struct V_62 * V_63 )
{
F_30 ( L_26 , V_63 -> V_64 ) ;
if ( V_53 == - 1 ) {
if ( F_31 ( NULL ,
L_27 ) )
V_53 = 1 ;
else
V_53 = 0 ;
F_4 ( V_18 , L_28
L_17 , V_53 ) ;
}
}
static int T_5 F_32 ( const struct V_62 * V_63 )
{
F_29 ( V_63 ) ;
V_40 -> V_65 = V_66 ;
V_40 -> V_67 = V_68 ;
return 1 ;
}
static int T_5 F_33 ( const struct V_62 * V_63 )
{
F_29 ( V_63 ) ;
V_40 -> V_65 = V_66 ;
V_40 -> V_67 = V_68 ;
return 1 ;
}
static int T_5 F_34 ( const struct V_62 * V_63 )
{
F_29 ( V_63 ) ;
V_40 -> V_65 = V_68 ;
V_40 -> V_69 = V_70 ;
V_40 -> V_71 = V_72 ;
return 1 ;
}
static int F_35 ( struct V_73 * V_54 )
{
int V_43 = 0 ;
struct V_74 * V_75 ;
int error ;
if ( ! V_54 )
return - V_42 ;
V_40 -> T_2 = V_54 -> V_13 ;
sprintf ( F_36 ( V_54 ) , L_29 , V_76 ) ;
sprintf ( F_37 ( V_54 ) , L_29 , V_77 ) ;
V_54 -> V_78 = V_40 ;
V_40 -> V_75 = V_75 = F_38 () ;
if ( ! V_75 ) {
error = - V_79 ;
goto V_80;
}
snprintf ( V_40 -> V_81 , sizeof( V_40 -> V_81 ) ,
L_30 , F_39 ( V_54 ) ) ;
V_75 -> V_82 = F_36 ( V_54 ) ;
V_75 -> V_81 = V_40 -> V_81 ;
V_75 -> V_63 . V_83 = V_84 ;
V_75 -> V_63 . V_85 = 0x06 ;
V_75 -> V_55 . V_86 = & V_54 -> V_55 ;
V_75 -> V_87 [ 0 ] = F_40 ( V_88 ) ;
F_41 ( V_89 , V_75 -> V_90 ) ;
F_41 ( V_91 , V_75 -> V_90 ) ;
F_41 ( V_92 , V_75 -> V_90 ) ;
error = F_42 ( V_75 ) ;
if ( error )
goto V_93;
error = F_43 ( V_40 -> T_2 , & V_43 ) ;
if ( error ) {
F_44 ( L_31 ) ;
goto V_94;
}
F_30 ( L_32 ,
F_36 ( V_54 ) , F_45 ( V_54 ) ,
! V_54 -> V_50 . V_43 ? L_33 : L_34 ) ;
V_40 -> V_55 = V_54 ;
if ( F_31 ( V_54 -> V_13 , V_95 ) ) {
F_4 ( V_96 , L_35 ) ;
if ( F_3
( F_46
( V_54 -> V_13 , V_95 , NULL , NULL ) ) )
F_44 ( L_36 ) ;
}
V_53 = V_53 == 1 ? 1 : 0 ;
V_97 = V_97 == 1 ? 1 : 0 ;
F_4 ( V_96 ,
L_37 ,
V_53 , V_97 ) ;
if ( F_18 () <= 0 )
V_40 -> V_41 = V_98 ;
F_17 () ;
return 0 ;
V_94:
F_47 ( V_75 ) ;
V_75 = NULL ;
V_93:
F_48 ( V_75 ) ;
V_80:
return error ;
}
static int F_49 ( struct V_73 * V_54 )
{
struct V_99 * V_40 = F_50 ( V_54 ) ;
struct V_74 * V_75 = V_40 -> V_75 ;
F_47 ( V_75 ) ;
V_40 -> T_2 = NULL ;
return 0 ;
}
static void F_51 ( struct V_73 * V_54 , T_6 V_100 )
{
struct V_74 * V_75 ;
int V_101 ;
int V_102 , V_103 ;
V_75 = V_40 -> V_75 ;
switch ( V_100 ) {
case V_104 :
V_101 = 0 ;
V_102 = V_40 -> V_44 ;
F_17 () ;
V_103 = V_40 -> V_44 ;
F_4 ( V_18 ,
L_38 ,
V_102 , V_103 , V_40 -> V_45 ) ;
if ( V_102 < V_103 ) {
if ( V_97 != 1 ) {
if ( V_53 )
F_16 ( V_103 ) ;
else
F_14 ( V_103 ) ;
}
V_101 = V_89 ;
} else if ( V_102 > V_103 ) {
if ( V_97 != 1 ) {
if ( V_53 )
F_16 ( V_103 ) ;
else
F_14 ( V_103 ) ;
}
V_101 = V_91 ;
}
break;
default:
V_101 = V_92 ;
F_4 ( V_17 ,
L_39 , V_100 ) ;
break;
}
if ( V_101 != 0 ) {
F_52 ( V_75 , V_101 , 1 ) ;
F_53 ( V_75 ) ;
F_52 ( V_75 , V_101 , 0 ) ;
F_53 ( V_75 ) ;
}
}
static int F_54 ( struct V_73 * V_54 )
{
int V_105 = 0 ;
int V_43 = 0 ;
struct V_74 * V_75 ;
int error ;
int V_106 ;
if ( ! V_54 )
return - V_42 ;
V_14 -> T_2 = V_54 -> V_13 ;
sprintf ( F_36 ( V_54 ) , L_29 ,
V_107 ) ;
sprintf ( F_37 ( V_54 ) , L_29 , V_77 ) ;
V_54 -> V_78 = V_14 ;
F_55 ( & V_14 -> V_108 ) ;
error = F_56 ( & V_14 -> V_109 , V_110 * sizeof( int ) ,
V_111 ) ;
if ( error ) {
F_44 ( L_40 ) ;
goto V_80;
}
V_14 -> V_75 = V_75 = F_38 () ;
if ( ! V_75 ) {
error = - V_79 ;
goto V_112;
}
snprintf ( V_14 -> V_81 , sizeof( V_14 -> V_81 ) ,
L_30 , F_39 ( V_54 ) ) ;
V_75 -> V_82 = F_36 ( V_54 ) ;
V_75 -> V_81 = V_14 -> V_81 ;
V_75 -> V_63 . V_83 = V_84 ;
V_75 -> V_63 . V_85 = 0x06 ;
V_75 -> V_55 . V_86 = & V_54 -> V_55 ;
F_41 ( V_88 , V_75 -> V_87 ) ;
F_41 ( V_40 -> V_65 , V_75 -> V_90 ) ;
F_41 ( V_40 -> V_67 , V_75 -> V_90 ) ;
F_41 ( V_40 -> V_69 , V_75 -> V_90 ) ;
F_41 ( V_40 -> V_71 , V_75 -> V_90 ) ;
F_41 ( V_40 -> V_113 , V_75 -> V_90 ) ;
F_41 ( V_114 , V_75 -> V_90 ) ;
F_41 ( V_92 , V_75 -> V_90 ) ;
error = F_42 ( V_75 ) ;
if ( error )
goto V_93;
error = F_43 ( V_14 -> T_2 , & V_43 ) ;
if ( error ) {
F_44 ( L_31 ) ;
goto V_94;
}
F_30 ( L_32 ,
F_36 ( V_54 ) , F_45 ( V_54 ) ,
! V_54 -> V_50 . V_43 ? L_33 : L_34 ) ;
V_14 -> V_55 = V_54 ;
if ( F_31 ( V_54 -> V_13 , V_95 ) ) {
F_4 ( V_96 , L_35 ) ;
if ( F_3
( F_46
( V_54 -> V_13 , V_95 , NULL , NULL ) ) )
F_44 ( L_36 ) ;
}
V_106 = 0 ;
while ( F_1 ( V_115 , 0x1 , 0x0 , 0x0 ) != 0
&& ( V_106 ++ ) < V_116 )
;
F_4 ( V_96 , L_41 , V_106 ) ;
V_14 -> V_60 =
F_1 ( V_31 , 0x0 , 0x0 , 0x0 ) ;
if ( V_14 -> V_60 == V_117 )
V_14 -> V_60 = 0 ;
if ( V_14 -> V_60 )
V_14 -> V_61 =
F_1 ( V_31 , 0x4 , 0x0 , 0x0 ) ;
F_30 ( L_42 , F_1 ( V_115 , 0x0 , 0x0 , 0x0 ) ) ;
#if F_57 ( V_118 )
if ( F_1 ( V_24 , 0x0 , 0x0 , 0x0 ) & V_25 ) {
V_105 = F_58 ( & V_40 -> V_119 -> V_55 ,
& V_120 ) ;
if ( V_105 == 0 ) {
V_14 -> V_121 = 1 ;
} else {
F_44 ( L_43 ,
V_105 ) ;
}
}
if ( ( F_1 ( V_24 , 0x0 , 0x0 , 0x0 ) & V_30 ) &&
( F_1 ( V_115 , 0x0 , 0x0 , 0x0 ) == 0x0 ) ) {
V_105 = F_58 ( & V_40 -> V_119 -> V_55 ,
& V_122 ) ;
if ( V_105 == 0 ) {
V_14 -> V_123 = 1 ;
} else {
F_44 ( L_44 ,
V_105 ) ;
}
}
if ( F_1 ( V_115 , 0x0 , 0x0 , 0x0 ) & F_40 ( 24 ) ) {
V_105 = F_58 ( & V_40 -> V_119 -> V_55 ,
& V_124 ) ;
if ( V_105 == 0 ) {
V_14 -> V_125 = 1 ;
} else {
F_44 ( L_45 ,
V_105 ) ;
}
}
if ( ( F_1 ( V_24 , 0x0 , 0x0 , 0x0 ) & F_40 ( 14 ) ) &&
( F_1 ( V_24 , 0x2 , V_34 , 0x0 ) != V_117 ) ) {
V_105 = F_58 ( & V_40 -> V_119 -> V_55 ,
& V_126 ) ;
if ( V_105 == 0 ) {
V_14 -> V_127 = 1 ;
} else {
F_44 ( L_46 ,
V_105 ) ;
}
}
#endif
return V_105 ;
V_94:
F_47 ( V_75 ) ;
V_75 = NULL ;
V_93:
F_48 ( V_75 ) ;
V_112:
F_59 ( & V_14 -> V_109 ) ;
V_80:
return error ;
}
static int F_60 ( struct V_73 * V_54 )
{
struct V_128 * V_14 = F_50 ( V_54 ) ;
struct V_74 * V_75 = V_14 -> V_75 ;
#if F_57 ( V_118 )
if ( V_14 -> V_121 )
F_61 ( & V_120 ) ;
if ( V_14 -> V_123 )
F_61 ( & V_122 ) ;
if ( V_14 -> V_125 )
F_61 ( & V_124 ) ;
if ( V_14 -> V_127 )
F_61 ( & V_126 ) ;
#endif
F_47 ( V_75 ) ;
F_59 ( & V_14 -> V_109 ) ;
V_14 -> T_2 = NULL ;
return 0 ;
}
static void F_62 ( struct V_73 * V_54 , T_6 V_100 )
{
struct V_74 * V_75 ;
int V_101 , V_129 ;
unsigned int V_130 = 1 ;
int V_106 , V_5 ;
V_75 = V_14 -> V_75 ;
if ( V_14 -> V_60 )
V_14 -> V_61 =
F_1 ( V_31 , 0x4 , 0x0 , 0x0 ) ;
switch ( V_100 ) {
case V_104 :
V_106 = 0 ;
while ( ( V_130 =
F_1 ( V_115 , 0x1 , 0x0 , 0x0 ) ) != 0
&& ( V_106 ++ ) < V_116 ) {
switch ( V_130 & 0x4ff ) {
case V_131 :
V_101 = V_40 -> V_65 ;
break;
case V_132 :
V_101 = V_40 -> V_67 ;
break;
case V_133 :
V_101 = V_40 -> V_69 ;
break;
case V_134 :
V_101 = V_40 -> V_71 ;
break;
case V_135 :
V_101 = V_40 -> V_113 ;
break;
case 0 :
V_101 = 0 ;
break;
default:
F_4 ( V_17 ,
L_47 , V_130 ) ;
V_101 = - 1 ;
break;
}
if ( V_101 > 0 ) {
F_4 ( V_18 ,
L_48 ,
V_101 ) ;
V_5 = F_63 ( & V_14 -> V_109 ,
( unsigned char * ) & V_101 ,
sizeof( V_101 ) ,
& V_14 -> V_108 ) ;
if ( V_5 != sizeof( V_101 ) ) {
F_4 ( V_17 ,
L_49 ,
V_101 ) ;
} else {
F_52 ( V_75 , V_101 , 1 ) ;
F_53 ( V_75 ) ;
}
} else if ( V_101 == 0 ) {
while ( ( V_5 =
F_64 (
& V_14 -> V_109 ,
( unsigned char * ) & V_129 ,
sizeof( V_129 ) ,
& V_14 -> V_108 ) )
== sizeof( V_129 ) ) {
F_52 ( V_75 , V_129 , 0 ) ;
F_53 ( V_75 ) ;
F_4 ( V_18 ,
L_50 ,
V_129 ) ;
}
}
}
if ( ( V_14 -> V_60 & F_40 ( 26 ) ) &&
( F_1 ( V_31 , 0x1 , 0x0 , 0x0 ) & F_40 ( 26 ) ) ) {
V_101 = V_114 ;
F_52 ( V_75 , V_101 , 1 ) ;
F_53 ( V_75 ) ;
F_52 ( V_75 , V_101 , 0 ) ;
F_53 ( V_75 ) ;
}
break;
default:
V_101 = V_92 ;
F_4 ( V_17 ,
L_51 , V_100 ) ;
F_52 ( V_75 , V_101 , 1 ) ;
F_53 ( V_75 ) ;
F_52 ( V_75 , V_101 , 0 ) ;
F_53 ( V_75 ) ;
break;
}
}
static int T_5 F_65 ( void )
{
int V_48 , V_105 , V_41 ;
if ( V_136 )
return - V_16 ;
V_40 = F_66 ( sizeof( struct V_99 ) , V_111 ) ;
if ( ! V_40 )
return - V_79 ;
V_40 -> V_65 = V_137 ;
V_40 -> V_67 = V_138 ;
V_40 -> V_69 = V_139 ;
V_40 -> V_71 = V_140 ;
V_40 -> V_113 = V_141 ;
F_67 ( V_142 ) ;
V_105 = F_68 ( & V_143 ) ;
if ( V_105 < 0 ) {
V_48 = - V_16 ;
goto V_144;
}
V_40 -> V_119 = F_69 ( L_52 , - 1 ) ;
if ( ! V_40 -> V_119 ) {
V_48 = - V_79 ;
goto V_145;
}
V_48 = F_70 ( V_40 -> V_119 ) ;
if ( V_48 )
goto V_146;
V_48 =
F_71 ( & V_40 -> V_119 -> V_55 . V_147 ,
& V_148 ) ;
if ( V_48 )
goto V_149;
if ( F_72 () == V_150 ) {
struct V_151 V_49 ;
memset ( & V_49 , 0 , sizeof( struct V_151 ) ) ;
V_41 = V_40 -> V_41 ;
V_49 . type = V_152 ;
V_49 . V_41 = V_41 - 1 ;
V_40 -> V_153 = F_73 ( L_52 ,
NULL , NULL ,
& V_154 ,
& V_49 ) ;
if ( F_74 ( V_40 -> V_153 ) ) {
V_48 = F_75 ( V_40 -> V_153 ) ;
V_40 -> V_153 = NULL ;
goto V_155;
}
V_40 -> V_153 -> V_49 . V_22 = V_40 -> V_44 ;
}
V_48 = F_76 ( & V_156 ) ;
if ( V_48 )
goto V_157;
V_14 = F_66 ( sizeof( struct V_128 ) , V_111 ) ;
if ( ! V_14 ) {
V_48 = - V_79 ;
goto V_158;
}
V_105 = F_68 ( & V_159 ) ;
if ( V_105 < 0 ) {
V_48 = - V_16 ;
goto V_160;
}
if ( F_72 () == V_150 ) {
if ( F_1 ( V_52 , 0x2 , 0x4 , 0x0 ) == 3 )
V_40 -> V_153 -> V_49 . V_50 = V_51 ;
else
V_40 -> V_153 -> V_49 . V_50 = V_161 ;
}
F_30 ( L_53 V_162 L_54 ) ;
return 0 ;
V_160:
F_77 ( V_14 ) ;
V_158:
F_78 ( & V_156 ) ;
V_157:
F_79 ( V_40 -> V_153 ) ;
V_155:
F_80 ( & V_40 -> V_119 -> V_55 . V_147 ,
& V_148 ) ;
V_149:
F_81 ( V_40 -> V_119 ) ;
V_146:
F_82 ( V_40 -> V_119 ) ;
V_145:
F_83 ( & V_143 ) ;
V_144:
F_77 ( V_40 ) ;
return V_48 ;
}
static void T_7 F_84 ( void )
{
F_83 ( & V_159 ) ;
F_77 ( V_14 ) ;
F_78 ( & V_156 ) ;
F_79 ( V_40 -> V_153 ) ;
F_80 ( & V_40 -> V_119 -> V_55 . V_147 ,
& V_148 ) ;
F_85 ( V_40 -> V_119 ) ;
F_83 ( & V_143 ) ;
F_77 ( V_40 ) ;
F_30 ( L_55 ) ;
}
