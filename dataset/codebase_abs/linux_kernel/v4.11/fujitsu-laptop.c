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
int V_23 = V_24 , V_25 = V_24 ;
int V_26 ;
if ( V_22 < V_27 )
V_23 = V_28 ;
if ( V_22 < V_29 )
V_25 = V_28 ;
V_26 = F_1 ( V_30 , 0x1 , V_31 , V_23 ) ;
if ( V_26 < 0 )
return V_26 ;
return F_1 ( V_30 , 0x1 , V_32 , V_25 ) ;
}
static int F_7 ( struct V_19 * V_20 ,
enum V_21 V_22 )
{
if ( V_22 >= V_29 )
return F_1 ( V_30 , 0x1 , V_33 , V_24 ) ;
else
return F_1 ( V_30 , 0x1 , V_33 , V_28 ) ;
}
static int F_8 ( struct V_19 * V_20 ,
enum V_21 V_22 )
{
if ( V_22 >= V_29 )
return F_1 ( V_34 , 0x5 , V_35 , V_35 ) ;
else
return F_1 ( V_34 , 0x5 , V_35 , 0x0 ) ;
}
static int F_9 ( struct V_19 * V_20 ,
enum V_21 V_22 )
{
int V_36 ;
V_36 = F_1 ( V_30 , 0x2 , V_37 , 0x0 ) ;
if ( V_22 >= V_29 )
return F_1 ( V_30 , 0x1 , V_37 , V_36 | V_38 ) ;
else
return F_1 ( V_30 , 0x1 , V_37 , V_36 & ~ V_38 ) ;
}
static enum V_21 F_10 ( struct V_19 * V_20 )
{
int V_26 ;
V_26 = F_1 ( V_30 , 0x2 , V_32 , 0x0 ) ;
if ( V_26 == V_24 )
return V_29 ;
V_26 = F_1 ( V_30 , 0x2 , V_31 , 0x0 ) ;
if ( V_26 == V_24 )
return V_27 ;
return V_39 ;
}
static enum V_21 F_11 ( struct V_19 * V_20 )
{
enum V_21 V_22 = V_39 ;
if ( F_1 ( V_30 , 0x2 , V_33 , 0x0 ) == V_24 )
V_22 = V_29 ;
return V_22 ;
}
static enum V_21 F_12 ( struct V_19 * V_20 )
{
enum V_21 V_22 = V_39 ;
if ( F_1 ( V_34 , 0x4 , 0x0 , 0x0 ) & V_35 )
V_22 = V_29 ;
return V_22 ;
}
static enum V_21 F_13 ( struct V_19 * V_20 )
{
enum V_21 V_22 = V_39 ;
if ( F_1 ( V_30 , 0x2 , V_37 , 0x0 ) & V_38 )
V_22 = V_29 ;
return V_22 ;
}
static int F_14 ( int V_40 )
{
T_1 V_5 = V_6 ;
T_2 V_13 = NULL ;
F_4 ( V_18 , L_5 ,
V_40 ) ;
if ( V_40 < 0 || V_40 >= V_41 -> V_42 )
return - V_43 ;
V_5 = F_2 ( V_41 -> T_2 , L_6 , & V_13 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( V_15 , L_7 ) ;
return - V_16 ;
}
V_5 = F_15 ( V_13 , NULL , V_40 ) ;
if ( F_3 ( V_5 ) )
return - V_16 ;
return 0 ;
}
static int F_16 ( int V_40 )
{
T_1 V_5 = V_6 ;
T_2 V_13 = NULL ;
F_4 ( V_18 , L_8 ,
V_40 ) ;
if ( V_40 < 0 || V_40 >= V_41 -> V_42 )
return - V_43 ;
V_5 = F_2 ( V_41 -> T_2 , L_9 , & V_13 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( V_15 , L_10 ) ;
return - V_16 ;
}
V_5 = F_15 ( V_13 , NULL , V_40 ) ;
if ( F_3 ( V_5 ) )
return - V_16 ;
return 0 ;
}
static int F_17 ( void )
{
unsigned long long V_44 = 0 ;
T_1 V_5 = V_6 ;
F_4 ( V_18 , L_11 ) ;
V_5 = F_5 ( V_41 -> T_2 , L_12 , NULL ,
& V_44 ) ;
if ( F_3 ( V_5 ) )
return 0 ;
V_41 -> V_45 = V_44 & 0x0fffffff ;
if ( V_44 & 0x80000000 )
V_41 -> V_46 = 1 ;
else
V_41 -> V_46 = 0 ;
return V_41 -> V_45 ;
}
static int F_18 ( void )
{
unsigned long long V_44 = 0 ;
T_1 V_5 = V_6 ;
F_4 ( V_18 , L_13 ) ;
V_5 = F_5 ( V_41 -> T_2 , L_14 , NULL ,
& V_44 ) ;
if ( F_3 ( V_5 ) )
return - 1 ;
V_41 -> V_42 = V_44 ;
return V_41 -> V_42 ;
}
static int F_19 ( struct V_47 * V_48 )
{
return F_17 () ;
}
static int F_20 ( struct V_47 * V_48 )
{
int V_26 ;
if ( V_48 -> V_49 . V_50 == V_51 )
V_26 = F_1 ( V_52 , 0x1 , 0x4 , 0x3 ) ;
else
V_26 = F_1 ( V_52 , 0x1 , 0x4 , 0x0 ) ;
if ( V_26 != 0 )
F_4 ( V_15 ,
L_15 ,
V_26 ) ;
if ( V_53 )
V_26 = F_16 ( V_48 -> V_49 . V_22 ) ;
else
V_26 = F_14 ( V_48 -> V_49 . V_22 ) ;
if ( V_26 != 0 )
F_4 ( V_15 ,
L_16 ,
V_26 ) ;
return V_26 ;
}
static T_3
F_21 ( struct V_54 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
int V_26 ;
V_26 = F_18 () ;
if ( V_26 < 0 )
return V_26 ;
return sprintf ( V_58 , L_17 , V_26 ) ;
}
static T_3
F_22 ( struct V_54 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
int V_26 ;
V_26 = V_41 -> V_46 ;
if ( V_26 < 0 )
return V_26 ;
return sprintf ( V_58 , L_17 , V_26 ) ;
}
static T_3 F_23 ( struct V_54 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
int V_26 ;
V_26 = F_17 () ;
if ( V_26 < 0 )
return V_26 ;
return sprintf ( V_58 , L_17 , V_26 ) ;
}
static T_3 F_24 ( struct V_54 * V_55 ,
struct V_56 * V_57 , const char * V_58 ,
T_4 V_59 )
{
int V_40 , V_26 ;
if ( sscanf ( V_58 , L_18 , & V_40 ) != 1
|| ( V_40 < 0 || V_40 >= V_41 -> V_42 ) )
return - V_43 ;
if ( V_53 )
V_26 = F_16 ( V_40 ) ;
else
V_26 = F_14 ( V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_17 () ;
if ( V_26 < 0 )
return V_26 ;
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
if ( ! ( V_14 -> V_60 & V_61 ) )
return sprintf ( V_58 , L_19 ) ;
if ( V_14 -> V_62 & V_61 )
return sprintf ( V_58 , L_20 ) ;
else
return sprintf ( V_58 , L_21 ) ;
}
static T_3
F_27 ( struct V_54 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
if ( ! ( V_14 -> V_60 & V_63 ) )
return sprintf ( V_58 , L_19 ) ;
if ( V_14 -> V_62 & V_63 )
return sprintf ( V_58 , L_22 ) ;
else
return sprintf ( V_58 , L_23 ) ;
}
static T_3
F_28 ( struct V_54 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
if ( ! ( V_14 -> V_60 & V_64 ) )
return sprintf ( V_58 , L_19 ) ;
if ( V_14 -> V_62 & V_64 )
return sprintf ( V_58 , L_24 ) ;
else
return sprintf ( V_58 , L_25 ) ;
}
static void T_5 F_29 ( const struct V_65 * V_66 )
{
F_30 ( L_26 , V_66 -> V_67 ) ;
}
static int T_5 F_31 ( const struct V_65 * V_66 )
{
F_29 ( V_66 ) ;
V_41 -> V_68 = V_69 ;
V_41 -> V_70 = V_71 ;
return 1 ;
}
static int T_5 F_32 ( const struct V_65 * V_66 )
{
F_29 ( V_66 ) ;
V_41 -> V_68 = V_69 ;
V_41 -> V_70 = V_71 ;
return 1 ;
}
static int T_5 F_33 ( const struct V_65 * V_66 )
{
F_29 ( V_66 ) ;
V_41 -> V_68 = V_71 ;
V_41 -> V_72 = V_73 ;
V_41 -> V_74 = V_75 ;
return 1 ;
}
static int F_34 ( struct V_76 * V_54 )
{
int V_44 = 0 ;
struct V_77 * V_78 ;
int error ;
if ( ! V_54 )
return - V_43 ;
V_41 -> T_2 = V_54 -> V_13 ;
sprintf ( F_35 ( V_54 ) , L_27 , V_79 ) ;
sprintf ( F_36 ( V_54 ) , L_27 , V_80 ) ;
V_54 -> V_81 = V_41 ;
V_41 -> V_78 = V_78 = F_37 () ;
if ( ! V_78 ) {
error = - V_82 ;
goto V_83;
}
snprintf ( V_41 -> V_84 , sizeof( V_41 -> V_84 ) ,
L_28 , F_38 ( V_54 ) ) ;
V_78 -> V_85 = F_35 ( V_54 ) ;
V_78 -> V_84 = V_41 -> V_84 ;
V_78 -> V_66 . V_86 = V_87 ;
V_78 -> V_66 . V_88 = 0x06 ;
V_78 -> V_55 . V_89 = & V_54 -> V_55 ;
V_78 -> V_90 [ 0 ] = F_39 ( V_91 ) ;
F_40 ( V_92 , V_78 -> V_93 ) ;
F_40 ( V_94 , V_78 -> V_93 ) ;
F_40 ( V_95 , V_78 -> V_93 ) ;
error = F_41 ( V_78 ) ;
if ( error )
goto V_96;
error = F_42 ( V_41 -> T_2 , & V_44 ) ;
if ( error ) {
F_43 ( L_29 ) ;
goto V_97;
}
F_30 ( L_30 ,
F_35 ( V_54 ) , F_44 ( V_54 ) ,
! V_54 -> V_50 . V_44 ? L_31 : L_32 ) ;
V_41 -> V_55 = V_54 ;
if ( F_45 ( V_54 -> V_13 , V_98 ) ) {
F_4 ( V_99 , L_33 ) ;
if ( F_3
( F_46
( V_54 -> V_13 , V_98 , NULL , NULL ) ) )
F_43 ( L_34 ) ;
}
if ( V_53 == - 1 ) {
if ( F_45 ( NULL , L_35 ) )
V_53 = 1 ;
else
V_53 = 0 ;
F_4 ( V_18 , L_36 ,
V_53 ) ;
}
V_53 = V_53 == 1 ? 1 : 0 ;
V_100 = V_100 == 1 ? 1 : 0 ;
F_4 ( V_99 ,
L_37 ,
V_53 , V_100 ) ;
if ( F_18 () <= 0 )
V_41 -> V_42 = V_101 ;
F_17 () ;
return 0 ;
V_97:
F_47 ( V_78 ) ;
V_78 = NULL ;
V_96:
F_48 ( V_78 ) ;
V_83:
return error ;
}
static int F_49 ( struct V_76 * V_54 )
{
struct V_41 * V_41 = F_50 ( V_54 ) ;
struct V_77 * V_78 = V_41 -> V_78 ;
F_47 ( V_78 ) ;
V_41 -> T_2 = NULL ;
return 0 ;
}
static void F_51 ( struct V_76 * V_54 , T_6 V_102 )
{
struct V_77 * V_78 ;
int V_103 ;
int V_104 , V_105 ;
V_78 = V_41 -> V_78 ;
switch ( V_102 ) {
case V_106 :
V_103 = 0 ;
V_104 = V_41 -> V_45 ;
F_17 () ;
V_105 = V_41 -> V_45 ;
F_4 ( V_18 ,
L_38 ,
V_104 , V_105 , V_41 -> V_46 ) ;
if ( V_104 < V_105 ) {
if ( V_100 != 1 ) {
if ( V_53 )
F_16 ( V_105 ) ;
else
F_14 ( V_105 ) ;
}
V_103 = V_92 ;
} else if ( V_104 > V_105 ) {
if ( V_100 != 1 ) {
if ( V_53 )
F_16 ( V_105 ) ;
else
F_14 ( V_105 ) ;
}
V_103 = V_94 ;
}
break;
default:
V_103 = V_95 ;
F_4 ( V_17 ,
L_39 , V_102 ) ;
break;
}
if ( V_103 != 0 ) {
F_52 ( V_78 , V_103 , 1 ) ;
F_53 ( V_78 ) ;
F_52 ( V_78 , V_103 , 0 ) ;
F_53 ( V_78 ) ;
}
}
static int F_54 ( struct V_76 * V_54 )
{
int V_107 = 0 ;
int V_44 = 0 ;
struct V_77 * V_78 ;
int error ;
int V_108 ;
if ( ! V_54 )
return - V_43 ;
V_14 -> T_2 = V_54 -> V_13 ;
sprintf ( F_35 ( V_54 ) , L_27 ,
V_109 ) ;
sprintf ( F_36 ( V_54 ) , L_27 , V_80 ) ;
V_54 -> V_81 = V_14 ;
F_55 ( & V_14 -> V_110 ) ;
error = F_56 ( & V_14 -> V_111 , V_112 * sizeof( int ) ,
V_113 ) ;
if ( error ) {
F_43 ( L_40 ) ;
goto V_83;
}
V_14 -> V_78 = V_78 = F_37 () ;
if ( ! V_78 ) {
error = - V_82 ;
goto V_114;
}
snprintf ( V_14 -> V_84 , sizeof( V_14 -> V_84 ) ,
L_28 , F_38 ( V_54 ) ) ;
V_78 -> V_85 = F_35 ( V_54 ) ;
V_78 -> V_84 = V_14 -> V_84 ;
V_78 -> V_66 . V_86 = V_87 ;
V_78 -> V_66 . V_88 = 0x06 ;
V_78 -> V_55 . V_89 = & V_54 -> V_55 ;
F_40 ( V_91 , V_78 -> V_90 ) ;
F_40 ( V_41 -> V_68 , V_78 -> V_93 ) ;
F_40 ( V_41 -> V_70 , V_78 -> V_93 ) ;
F_40 ( V_41 -> V_72 , V_78 -> V_93 ) ;
F_40 ( V_41 -> V_74 , V_78 -> V_93 ) ;
F_40 ( V_41 -> V_115 , V_78 -> V_93 ) ;
F_40 ( V_116 , V_78 -> V_93 ) ;
F_40 ( V_95 , V_78 -> V_93 ) ;
error = F_41 ( V_78 ) ;
if ( error )
goto V_96;
error = F_42 ( V_14 -> T_2 , & V_44 ) ;
if ( error ) {
F_43 ( L_29 ) ;
goto V_97;
}
F_30 ( L_30 ,
F_35 ( V_54 ) , F_44 ( V_54 ) ,
! V_54 -> V_50 . V_44 ? L_31 : L_32 ) ;
V_14 -> V_55 = V_54 ;
if ( F_45 ( V_54 -> V_13 , V_98 ) ) {
F_4 ( V_99 , L_33 ) ;
if ( F_3
( F_46
( V_54 -> V_13 , V_98 , NULL , NULL ) ) )
F_43 ( L_34 ) ;
}
V_108 = 0 ;
while ( F_1 ( V_117 , 0x1 , 0x0 , 0x0 ) != 0
&& ( V_108 ++ ) < V_118 )
;
F_4 ( V_99 , L_41 , V_108 ) ;
V_14 -> V_60 =
F_1 ( V_34 , 0x0 , 0x0 , 0x0 ) ;
if ( V_14 -> V_60 == V_119 )
V_14 -> V_60 = 0 ;
if ( V_14 -> V_60 )
V_14 -> V_62 =
F_1 ( V_34 , 0x4 , 0x0 , 0x0 ) ;
F_30 ( L_42 , F_1 ( V_117 , 0x0 , 0x0 , 0x0 ) ) ;
#if F_57 ( V_120 )
if ( F_1 ( V_30 , 0x0 , 0x0 , 0x0 ) & V_31 ) {
V_107 = F_58 ( & V_41 -> V_121 -> V_55 ,
& V_122 ) ;
if ( V_107 == 0 ) {
V_14 -> V_123 = 1 ;
} else {
F_43 ( L_43 ,
V_107 ) ;
}
}
if ( ( F_1 ( V_30 , 0x0 , 0x0 , 0x0 ) & V_33 ) &&
( F_1 ( V_117 , 0x0 , 0x0 , 0x0 ) == 0x0 ) ) {
V_107 = F_58 ( & V_41 -> V_121 -> V_55 ,
& V_124 ) ;
if ( V_107 == 0 ) {
V_14 -> V_125 = 1 ;
} else {
F_43 ( L_44 ,
V_107 ) ;
}
}
if ( F_1 ( V_117 , 0x0 , 0x0 , 0x0 ) & F_39 ( 24 ) ) {
V_107 = F_58 ( & V_41 -> V_121 -> V_55 ,
& V_126 ) ;
if ( V_107 == 0 ) {
V_14 -> V_127 = 1 ;
} else {
F_43 ( L_45 ,
V_107 ) ;
}
}
if ( ( F_1 ( V_30 , 0x0 , 0x0 , 0x0 ) & F_39 ( 14 ) ) &&
( F_1 ( V_30 , 0x2 , V_37 , 0x0 ) != V_119 ) ) {
V_107 = F_58 ( & V_41 -> V_121 -> V_55 ,
& V_128 ) ;
if ( V_107 == 0 ) {
V_14 -> V_129 = 1 ;
} else {
F_43 ( L_46 ,
V_107 ) ;
}
}
#endif
return V_107 ;
V_97:
F_47 ( V_78 ) ;
V_78 = NULL ;
V_96:
F_48 ( V_78 ) ;
V_114:
F_59 ( & V_14 -> V_111 ) ;
V_83:
return error ;
}
static int F_60 ( struct V_76 * V_54 )
{
struct V_14 * V_14 = F_50 ( V_54 ) ;
struct V_77 * V_78 = V_14 -> V_78 ;
#if F_57 ( V_120 )
if ( V_14 -> V_123 )
F_61 ( & V_122 ) ;
if ( V_14 -> V_125 )
F_61 ( & V_124 ) ;
if ( V_14 -> V_127 )
F_61 ( & V_126 ) ;
if ( V_14 -> V_129 )
F_61 ( & V_128 ) ;
#endif
F_47 ( V_78 ) ;
F_59 ( & V_14 -> V_111 ) ;
V_14 -> T_2 = NULL ;
return 0 ;
}
static void F_62 ( int V_103 )
{
struct V_77 * V_78 = V_14 -> V_78 ;
int V_5 ;
V_5 = F_63 ( & V_14 -> V_111 ,
( unsigned char * ) & V_103 , sizeof( V_103 ) ,
& V_14 -> V_110 ) ;
if ( V_5 != sizeof( V_103 ) ) {
F_4 ( V_17 ,
L_47 , V_103 ) ;
return;
}
F_52 ( V_78 , V_103 , 1 ) ;
F_53 ( V_78 ) ;
F_4 ( V_18 ,
L_48 , V_103 ) ;
}
static void F_64 ( void )
{
struct V_77 * V_78 = V_14 -> V_78 ;
int V_103 , V_5 ;
while ( true ) {
V_5 = F_65 ( & V_14 -> V_111 ,
( unsigned char * ) & V_103 ,
sizeof( V_103 ) ,
& V_14 -> V_110 ) ;
if ( V_5 != sizeof( V_103 ) )
return;
F_52 ( V_78 , V_103 , 0 ) ;
F_53 ( V_78 ) ;
F_4 ( V_18 ,
L_49 , V_103 ) ;
}
}
static void F_66 ( struct V_76 * V_54 , T_6 V_102 )
{
struct V_77 * V_78 ;
int V_103 ;
unsigned int V_130 = 1 ;
int V_108 ;
V_78 = V_14 -> V_78 ;
if ( V_102 != V_106 ) {
V_103 = V_95 ;
F_4 ( V_17 ,
L_50 , V_102 ) ;
F_52 ( V_78 , V_103 , 1 ) ;
F_53 ( V_78 ) ;
F_52 ( V_78 , V_103 , 0 ) ;
F_53 ( V_78 ) ;
return;
}
if ( V_14 -> V_60 )
V_14 -> V_62 =
F_1 ( V_34 , 0x4 , 0x0 , 0x0 ) ;
V_108 = 0 ;
while ( ( V_130 =
F_1 ( V_117 , 0x1 , 0x0 , 0x0 ) ) != 0
&& ( V_108 ++ ) < V_118 ) {
switch ( V_130 & 0x4ff ) {
case V_131 :
V_103 = V_41 -> V_68 ;
break;
case V_132 :
V_103 = V_41 -> V_70 ;
break;
case V_133 :
V_103 = V_41 -> V_72 ;
break;
case V_134 :
V_103 = V_41 -> V_74 ;
break;
case V_135 :
V_103 = V_41 -> V_115 ;
break;
case 0 :
V_103 = 0 ;
break;
default:
F_4 ( V_17 ,
L_51 , V_130 ) ;
V_103 = - 1 ;
break;
}
if ( V_103 > 0 )
F_62 ( V_103 ) ;
else if ( V_103 == 0 )
F_64 () ;
}
if ( ( V_14 -> V_60 & F_39 ( 26 ) ) &&
( F_1 ( V_34 , 0x1 , 0x0 , 0x0 ) & F_39 ( 26 ) ) ) {
V_103 = V_116 ;
F_52 ( V_78 , V_103 , 1 ) ;
F_53 ( V_78 ) ;
F_52 ( V_78 , V_103 , 0 ) ;
F_53 ( V_78 ) ;
}
}
static int T_5 F_67 ( void )
{
int V_26 , V_42 ;
if ( V_136 )
return - V_16 ;
V_41 = F_68 ( sizeof( struct V_41 ) , V_113 ) ;
if ( ! V_41 )
return - V_82 ;
V_41 -> V_68 = V_137 ;
V_41 -> V_70 = V_138 ;
V_41 -> V_72 = V_139 ;
V_41 -> V_74 = V_140 ;
V_41 -> V_115 = V_141 ;
F_69 ( V_142 ) ;
V_26 = F_70 ( & V_143 ) ;
if ( V_26 )
goto V_144;
V_41 -> V_121 = F_71 ( L_52 , - 1 ) ;
if ( ! V_41 -> V_121 ) {
V_26 = - V_82 ;
goto V_145;
}
V_26 = F_72 ( V_41 -> V_121 ) ;
if ( V_26 )
goto V_146;
V_26 =
F_73 ( & V_41 -> V_121 -> V_55 . V_147 ,
& V_148 ) ;
if ( V_26 )
goto V_149;
if ( F_74 () == V_150 ) {
struct V_151 V_49 ;
memset ( & V_49 , 0 , sizeof( struct V_151 ) ) ;
V_42 = V_41 -> V_42 ;
V_49 . type = V_152 ;
V_49 . V_42 = V_42 - 1 ;
V_41 -> V_153 = F_75 ( L_52 ,
NULL , NULL ,
& V_154 ,
& V_49 ) ;
if ( F_76 ( V_41 -> V_153 ) ) {
V_26 = F_77 ( V_41 -> V_153 ) ;
V_41 -> V_153 = NULL ;
goto V_155;
}
V_41 -> V_153 -> V_49 . V_22 = V_41 -> V_45 ;
}
V_26 = F_78 ( & V_156 ) ;
if ( V_26 )
goto V_157;
V_14 = F_68 ( sizeof( struct V_14 ) , V_113 ) ;
if ( ! V_14 ) {
V_26 = - V_82 ;
goto V_158;
}
V_26 = F_70 ( & V_159 ) ;
if ( V_26 )
goto V_160;
if ( F_74 () == V_150 ) {
if ( F_1 ( V_52 , 0x2 , 0x4 , 0x0 ) == 3 )
V_41 -> V_153 -> V_49 . V_50 = V_51 ;
else
V_41 -> V_153 -> V_49 . V_50 = V_161 ;
}
F_30 ( L_53 V_162 L_54 ) ;
return 0 ;
V_160:
F_79 ( V_14 ) ;
V_158:
F_80 ( & V_156 ) ;
V_157:
F_81 ( V_41 -> V_153 ) ;
V_155:
F_82 ( & V_41 -> V_121 -> V_55 . V_147 ,
& V_148 ) ;
V_149:
F_83 ( V_41 -> V_121 ) ;
V_146:
F_84 ( V_41 -> V_121 ) ;
V_145:
F_85 ( & V_143 ) ;
V_144:
F_79 ( V_41 ) ;
return V_26 ;
}
static void T_7 F_86 ( void )
{
F_85 ( & V_159 ) ;
F_79 ( V_14 ) ;
F_80 ( & V_156 ) ;
F_81 ( V_41 -> V_153 ) ;
F_82 ( & V_41 -> V_121 -> V_55 . V_147 ,
& V_148 ) ;
F_87 ( V_41 -> V_121 ) ;
F_85 ( & V_143 ) ;
F_79 ( V_41 ) ;
F_30 ( L_55 ) ;
}
