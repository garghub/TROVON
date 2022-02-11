static int F_1 ( int V_1 , int V_2 , int V_3 , int V_4 )
{
union V_5 V_6 [ 4 ] = {
{ . integer . type = V_7 , . integer . V_8 = V_1 } ,
{ . integer . type = V_7 , . integer . V_8 = V_2 } ,
{ . integer . type = V_7 , . integer . V_8 = V_3 } ,
{ . integer . type = V_7 , . integer . V_8 = V_4 }
} ;
struct V_9 V_10 = { 4 , V_6 } ;
unsigned long long V_8 ;
T_1 V_11 ;
V_11 = F_2 ( V_12 -> V_13 , L_1 ,
& V_10 , & V_8 ) ;
if ( F_3 ( V_11 ) ) {
F_4 ( V_14 , L_2 ) ;
return - V_15 ;
}
F_4 ( V_16 , L_3 ,
V_1 , V_2 , V_3 , V_4 , ( int ) V_8 ) ;
return V_8 ;
}
static int F_5 ( int V_17 )
{
T_1 V_11 ;
char * V_18 ;
switch ( V_19 ) {
case - 1 :
if ( F_6 ( V_20 -> V_13 , L_4 ) )
V_18 = L_4 ;
else
V_18 = L_5 ;
break;
case 1 :
V_18 = L_4 ;
break;
default:
V_18 = L_5 ;
break;
}
F_4 ( V_16 , L_6 ,
V_18 , V_17 ) ;
if ( V_17 < 0 || V_17 >= V_20 -> V_21 )
return - V_22 ;
V_11 = F_7 ( V_20 -> V_13 , V_18 ,
V_17 ) ;
if ( F_3 ( V_11 ) ) {
F_4 ( V_14 , L_7 ,
V_18 ) ;
return - V_15 ;
}
V_20 -> V_23 = V_17 ;
return 0 ;
}
static int F_8 ( void )
{
unsigned long long V_4 = 0 ;
T_1 V_11 = V_24 ;
F_4 ( V_16 , L_8 ) ;
V_11 = F_2 ( V_20 -> V_13 , L_9 , NULL ,
& V_4 ) ;
if ( F_3 ( V_11 ) )
return 0 ;
V_20 -> V_23 = V_4 & 0x0fffffff ;
return V_20 -> V_23 ;
}
static int F_9 ( void )
{
unsigned long long V_4 = 0 ;
T_1 V_11 = V_24 ;
F_4 ( V_16 , L_10 ) ;
V_11 = F_2 ( V_20 -> V_13 , L_11 , NULL ,
& V_4 ) ;
if ( F_3 ( V_11 ) )
return - 1 ;
V_20 -> V_21 = V_4 ;
return V_20 -> V_21 ;
}
static int F_10 ( struct V_25 * V_26 )
{
return V_26 -> V_27 . V_28 == V_29 ? 0 : F_8 () ;
}
static int F_11 ( struct V_25 * V_26 )
{
if ( V_26 -> V_27 . V_28 == V_29 )
F_1 ( V_30 , 0x1 , 0x4 , 0x3 ) ;
else
F_1 ( V_30 , 0x1 , 0x4 , 0x0 ) ;
return F_5 ( V_26 -> V_27 . V_31 ) ;
}
static T_2 F_12 ( struct V_32 * V_33 , struct V_34 * V_35 ,
char * V_36 )
{
if ( ! ( V_12 -> V_37 & V_38 ) )
return sprintf ( V_36 , L_12 ) ;
if ( V_12 -> V_39 & V_38 )
return sprintf ( V_36 , L_13 ) ;
else
return sprintf ( V_36 , L_14 ) ;
}
static T_2 F_13 ( struct V_32 * V_33 , struct V_34 * V_35 ,
char * V_36 )
{
if ( ! ( V_12 -> V_37 & V_40 ) )
return sprintf ( V_36 , L_12 ) ;
if ( V_12 -> V_39 & V_40 )
return sprintf ( V_36 , L_15 ) ;
else
return sprintf ( V_36 , L_16 ) ;
}
static T_2 F_14 ( struct V_32 * V_33 , struct V_34 * V_35 ,
char * V_36 )
{
if ( ! ( V_12 -> V_37 & V_41 ) )
return sprintf ( V_36 , L_12 ) ;
if ( V_12 -> V_39 & V_41 )
return sprintf ( V_36 , L_17 ) ;
else
return sprintf ( V_36 , L_18 ) ;
}
static int F_15 ( struct V_42 * V_32 )
{
struct V_20 * V_20 = F_16 ( V_32 ) ;
int V_43 ;
V_20 -> V_44 = F_17 ( & V_32 -> V_33 ) ;
if ( ! V_20 -> V_44 )
return - V_45 ;
snprintf ( V_20 -> V_46 , sizeof( V_20 -> V_46 ) ,
L_19 , F_18 ( V_32 ) ) ;
V_20 -> V_44 -> V_47 = F_19 ( V_32 ) ;
V_20 -> V_44 -> V_46 = V_20 -> V_46 ;
V_20 -> V_44 -> V_48 . V_49 = V_50 ;
V_20 -> V_44 -> V_48 . V_51 = 0x06 ;
V_43 = F_20 ( V_20 -> V_44 , V_52 , NULL ) ;
if ( V_43 )
return V_43 ;
return F_21 ( V_20 -> V_44 ) ;
}
static int F_22 ( struct V_42 * V_32 )
{
const struct V_53 V_27 = {
. V_31 = V_20 -> V_23 ,
. V_21 = V_20 -> V_21 - 1 ,
. type = V_54
} ;
struct V_25 * V_55 ;
V_55 = F_23 ( & V_32 -> V_33 , L_20 ,
& V_32 -> V_33 , NULL ,
& V_56 , & V_27 ) ;
if ( F_24 ( V_55 ) )
return F_25 ( V_55 ) ;
V_20 -> V_57 = V_55 ;
return 0 ;
}
static int F_26 ( struct V_42 * V_32 )
{
int V_4 = 0 ;
int error ;
if ( F_27 () != V_58 )
return - V_15 ;
if ( ! V_32 )
return - V_22 ;
V_20 -> V_13 = V_32 -> V_59 ;
sprintf ( F_19 ( V_32 ) , L_21 , V_60 ) ;
sprintf ( F_28 ( V_32 ) , L_21 , V_61 ) ;
V_32 -> V_62 = V_20 ;
error = F_15 ( V_32 ) ;
if ( error )
return error ;
error = F_29 ( V_20 -> V_13 , & V_4 ) ;
if ( error ) {
F_30 ( L_22 ) ;
return error ;
}
F_31 ( L_23 ,
F_19 ( V_32 ) , F_32 ( V_32 ) ,
! V_32 -> V_28 . V_4 ? L_24 : L_25 ) ;
if ( F_6 ( V_32 -> V_59 , V_63 ) ) {
F_4 ( V_64 , L_26 ) ;
if ( F_3
( F_33
( V_32 -> V_59 , V_63 , NULL , NULL ) ) )
F_30 ( L_27 ) ;
}
if ( F_9 () <= 0 )
V_20 -> V_21 = V_65 ;
F_8 () ;
error = F_22 ( V_32 ) ;
if ( error )
return error ;
return 0 ;
}
static void F_34 ( struct V_42 * V_32 , T_3 V_66 )
{
struct V_67 * V_44 ;
int V_68 , V_69 ;
V_44 = V_20 -> V_44 ;
if ( V_66 != V_70 ) {
F_4 ( V_71 ,
L_28 , V_66 ) ;
F_35 ( V_44 , - 1 , 1 , true ) ;
return;
}
V_68 = V_20 -> V_23 ;
F_8 () ;
V_69 = V_20 -> V_23 ;
F_4 ( V_16 , L_29 ,
V_68 , V_69 ) ;
if ( V_68 == V_69 )
return;
if ( ! V_72 )
F_5 ( V_69 ) ;
F_35 ( V_44 , V_68 < V_69 , 1 , true ) ;
}
static int F_36 ( const struct V_73 * V_48 )
{
F_31 ( L_30 , V_48 -> V_74 ) ;
V_75 = V_48 -> V_62 ;
return 1 ;
}
static int F_37 ( struct V_42 * V_32 )
{
struct V_12 * V_12 = F_16 ( V_32 ) ;
int V_43 ;
V_12 -> V_44 = F_17 ( & V_32 -> V_33 ) ;
if ( ! V_12 -> V_44 )
return - V_45 ;
snprintf ( V_12 -> V_46 , sizeof( V_12 -> V_46 ) ,
L_19 , F_18 ( V_32 ) ) ;
V_12 -> V_44 -> V_47 = F_19 ( V_32 ) ;
V_12 -> V_44 -> V_46 = V_12 -> V_46 ;
V_12 -> V_44 -> V_48 . V_49 = V_50 ;
V_12 -> V_44 -> V_48 . V_51 = 0x06 ;
F_38 ( V_76 ) ;
V_43 = F_20 ( V_12 -> V_44 , V_75 , NULL ) ;
if ( V_43 )
return V_43 ;
return F_21 ( V_12 -> V_44 ) ;
}
static int F_39 ( void )
{
int V_43 ;
V_12 -> V_77 = F_40 ( L_20 , - 1 ) ;
if ( ! V_12 -> V_77 )
return - V_45 ;
V_43 = F_41 ( V_12 -> V_77 ) ;
if ( V_43 )
goto V_78;
V_43 = F_42 ( & V_12 -> V_77 -> V_33 . V_79 ,
& V_80 ) ;
if ( V_43 )
goto V_81;
return 0 ;
V_81:
F_43 ( V_12 -> V_77 ) ;
V_78:
F_44 ( V_12 -> V_77 ) ;
return V_43 ;
}
static void F_45 ( void )
{
F_46 ( & V_12 -> V_77 -> V_33 . V_79 ,
& V_80 ) ;
F_47 ( V_12 -> V_77 ) ;
}
static int F_48 ( struct V_82 * V_83 ,
enum V_84 V_31 )
{
int V_85 = V_86 , V_87 = V_86 ;
int V_43 ;
if ( V_31 < V_88 )
V_85 = V_89 ;
if ( V_31 < V_90 )
V_87 = V_89 ;
V_43 = F_1 ( V_91 , 0x1 , V_92 , V_85 ) ;
if ( V_43 < 0 )
return V_43 ;
return F_1 ( V_91 , 0x1 , V_93 , V_87 ) ;
}
static enum V_84 F_49 ( struct V_82 * V_83 )
{
int V_43 ;
V_43 = F_1 ( V_91 , 0x2 , V_93 , 0x0 ) ;
if ( V_43 == V_86 )
return V_90 ;
V_43 = F_1 ( V_91 , 0x2 , V_92 , 0x0 ) ;
if ( V_43 == V_86 )
return V_88 ;
return V_94 ;
}
static int F_50 ( struct V_82 * V_83 ,
enum V_84 V_31 )
{
if ( V_31 >= V_90 )
return F_1 ( V_91 , 0x1 , V_95 ,
V_86 ) ;
else
return F_1 ( V_91 , 0x1 , V_95 ,
V_89 ) ;
}
static enum V_84 F_51 ( struct V_82 * V_83 )
{
enum V_84 V_31 = V_94 ;
if ( F_1 ( V_91 , 0x2 , V_95 , 0x0 ) == V_86 )
V_31 = V_90 ;
return V_31 ;
}
static int F_52 ( struct V_82 * V_83 ,
enum V_84 V_31 )
{
if ( V_31 >= V_90 )
return F_1 ( V_96 , 0x5 , V_97 ,
V_97 ) ;
else
return F_1 ( V_96 , 0x5 , V_97 , 0x0 ) ;
}
static enum V_84 F_53 ( struct V_82 * V_83 )
{
enum V_84 V_31 = V_94 ;
if ( F_1 ( V_96 , 0x4 , 0x0 , 0x0 ) & V_97 )
V_31 = V_90 ;
return V_31 ;
}
static int F_54 ( struct V_82 * V_83 ,
enum V_84 V_31 )
{
int V_98 ;
V_98 = F_1 ( V_91 , 0x2 , V_99 , 0x0 ) ;
if ( V_31 >= V_90 )
return F_1 ( V_91 , 0x1 , V_99 ,
V_98 | V_100 ) ;
else
return F_1 ( V_91 , 0x1 , V_99 ,
V_98 & ~ V_100 ) ;
}
static enum V_84 F_55 ( struct V_82 * V_83 )
{
enum V_84 V_31 = V_94 ;
if ( F_1 ( V_91 , 0x2 , V_99 , 0x0 ) & V_100 )
V_31 = V_90 ;
return V_31 ;
}
static int F_56 ( struct V_42 * V_32 )
{
int V_101 ;
if ( F_1 ( V_91 , 0x0 , 0x0 , 0x0 ) & V_92 ) {
V_101 = F_57 ( & V_32 -> V_33 ,
& V_102 ) ;
if ( V_101 )
return V_101 ;
}
if ( ( F_1 ( V_91 , 0x0 , 0x0 , 0x0 ) & V_95 ) &&
( F_1 ( V_103 , 0x0 , 0x0 , 0x0 ) == 0x0 ) ) {
V_101 = F_57 ( & V_32 -> V_33 , & V_104 ) ;
if ( V_101 )
return V_101 ;
}
if ( F_1 ( V_103 , 0x0 , 0x0 , 0x0 ) & F_58 ( 24 ) ) {
V_101 = F_57 ( & V_32 -> V_33 , & V_105 ) ;
if ( V_101 )
return V_101 ;
}
if ( ( F_1 ( V_91 , 0x0 , 0x0 , 0x0 ) & F_58 ( 14 ) ) &&
( F_1 ( V_91 , 0x2 , V_99 , 0x0 ) != V_106 ) ) {
V_101 = F_57 ( & V_32 -> V_33 , & V_107 ) ;
if ( V_101 )
return V_101 ;
}
return 0 ;
}
static int F_59 ( struct V_42 * V_32 )
{
int V_4 = 0 ;
int error ;
int V_108 ;
if ( ! V_32 )
return - V_22 ;
V_12 -> V_13 = V_32 -> V_59 ;
sprintf ( F_19 ( V_32 ) , L_21 ,
V_109 ) ;
sprintf ( F_28 ( V_32 ) , L_21 , V_61 ) ;
V_32 -> V_62 = V_12 ;
F_60 ( & V_12 -> V_110 ) ;
error = F_61 ( & V_12 -> V_111 , V_112 * sizeof( int ) ,
V_113 ) ;
if ( error ) {
F_30 ( L_31 ) ;
goto V_114;
}
error = F_37 ( V_32 ) ;
if ( error )
goto V_115;
error = F_29 ( V_12 -> V_13 , & V_4 ) ;
if ( error ) {
F_30 ( L_22 ) ;
goto V_115;
}
F_31 ( L_23 ,
F_19 ( V_32 ) , F_32 ( V_32 ) ,
! V_32 -> V_28 . V_4 ? L_24 : L_25 ) ;
V_12 -> V_33 = V_32 ;
if ( F_6 ( V_32 -> V_59 , V_63 ) ) {
F_4 ( V_64 , L_26 ) ;
if ( F_3
( F_33
( V_32 -> V_59 , V_63 , NULL , NULL ) ) )
F_30 ( L_27 ) ;
}
V_108 = 0 ;
while ( F_1 ( V_103 , 0x1 , 0x0 , 0x0 ) != 0
&& ( V_108 ++ ) < V_116 )
;
F_4 ( V_64 , L_32 , V_108 ) ;
V_12 -> V_37 =
F_1 ( V_96 , 0x0 , 0x0 , 0x0 ) ;
if ( V_12 -> V_37 == V_106 )
V_12 -> V_37 = 0 ;
if ( V_12 -> V_37 )
V_12 -> V_39 =
F_1 ( V_96 , 0x4 , 0x0 , 0x0 ) ;
F_31 ( L_33 , F_1 ( V_103 , 0x0 , 0x0 , 0x0 ) ) ;
if ( V_20 -> V_57 &&
F_27 () == V_58 ) {
if ( F_1 ( V_30 , 0x2 , 0x4 , 0x0 ) == 3 )
V_20 -> V_57 -> V_27 . V_28 = V_29 ;
else
V_20 -> V_57 -> V_27 . V_28 = V_117 ;
}
error = F_56 ( V_32 ) ;
if ( error )
goto V_115;
error = F_39 () ;
if ( error )
goto V_115;
return 0 ;
V_115:
F_62 ( & V_12 -> V_111 ) ;
V_114:
return error ;
}
static int F_63 ( struct V_42 * V_32 )
{
struct V_12 * V_12 = F_16 ( V_32 ) ;
F_45 () ;
F_62 ( & V_12 -> V_111 ) ;
return 0 ;
}
static void F_64 ( int V_118 )
{
struct V_67 * V_44 = V_12 -> V_44 ;
int V_11 ;
V_11 = F_65 ( & V_12 -> V_111 ,
( unsigned char * ) & V_118 , sizeof( V_118 ) ,
& V_12 -> V_110 ) ;
if ( V_11 != sizeof( V_118 ) ) {
F_4 ( V_71 ,
L_34 , V_118 ) ;
return;
}
F_35 ( V_44 , V_118 , 1 , false ) ;
F_4 ( V_16 ,
L_35 , V_118 ) ;
}
static void F_66 ( void )
{
struct V_67 * V_44 = V_12 -> V_44 ;
int V_118 , V_11 ;
while ( true ) {
V_11 = F_67 ( & V_12 -> V_111 ,
( unsigned char * ) & V_118 ,
sizeof( V_118 ) ,
& V_12 -> V_110 ) ;
if ( V_11 != sizeof( V_118 ) )
return;
F_35 ( V_44 , V_118 , 0 , false ) ;
F_4 ( V_16 ,
L_36 , V_118 ) ;
}
}
static void F_68 ( struct V_42 * V_32 , T_3 V_66 )
{
struct V_67 * V_44 ;
int V_118 , V_108 = 0 ;
unsigned int V_119 ;
V_44 = V_12 -> V_44 ;
if ( V_66 != V_70 ) {
F_4 ( V_71 ,
L_37 , V_66 ) ;
F_35 ( V_44 , - 1 , 1 , true ) ;
return;
}
if ( V_12 -> V_37 )
V_12 -> V_39 =
F_1 ( V_96 , 0x4 , 0x0 , 0x0 ) ;
while ( ( V_119 = F_1 ( V_103 , 0x1 , 0x0 , 0x0 ) ) != 0 &&
V_108 ++ < V_116 ) {
V_118 = V_119 & 0x4ff ;
if ( F_69 ( V_44 , V_118 ) )
F_64 ( V_118 ) ;
else if ( V_118 == 0 )
F_66 () ;
else
F_4 ( V_71 ,
L_38 , V_119 ) ;
}
if ( ( V_12 -> V_37 & F_58 ( 26 ) ) &&
( F_1 ( V_96 , 0x1 , 0x0 , 0x0 ) & F_58 ( 26 ) ) )
F_35 ( V_44 , F_58 ( 26 ) , 1 , true ) ;
}
static int T_4 F_70 ( void )
{
int V_43 ;
if ( V_120 )
return - V_15 ;
V_20 = F_71 ( sizeof( struct V_20 ) , V_113 ) ;
if ( ! V_20 )
return - V_45 ;
V_43 = F_72 ( & V_121 ) ;
if ( V_43 )
goto V_122;
V_43 = F_73 ( & V_123 ) ;
if ( V_43 )
goto V_124;
V_12 = F_71 ( sizeof( struct V_12 ) , V_113 ) ;
if ( ! V_12 ) {
V_43 = - V_45 ;
goto V_125;
}
V_43 = F_72 ( & V_126 ) ;
if ( V_43 )
goto V_127;
F_31 ( L_39 V_128 L_40 ) ;
return 0 ;
V_127:
F_74 ( V_12 ) ;
V_125:
F_75 ( & V_123 ) ;
V_124:
F_76 ( & V_121 ) ;
V_122:
F_74 ( V_20 ) ;
return V_43 ;
}
static void T_5 F_77 ( void )
{
F_76 ( & V_126 ) ;
F_74 ( V_12 ) ;
F_75 ( & V_123 ) ;
F_76 ( & V_121 ) ;
F_74 ( V_20 ) ;
F_31 ( L_41 ) ;
}
