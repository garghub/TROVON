static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , int V_6 )
{
union V_7 V_8 [ 4 ] = {
{ . integer . type = V_9 , . integer . V_10 = V_3 } ,
{ . integer . type = V_9 , . integer . V_10 = V_4 } ,
{ . integer . type = V_9 , . integer . V_10 = V_5 } ,
{ . integer . type = V_9 , . integer . V_10 = V_6 }
} ;
struct V_11 V_12 = { 4 , V_8 } ;
unsigned long long V_10 ;
T_1 V_13 ;
V_13 = F_2 ( V_2 -> V_14 , L_1 , & V_12 ,
& V_10 ) ;
if ( F_3 ( V_13 ) ) {
F_4 ( V_2 -> V_14 , L_2 ) ;
return - V_15 ;
}
F_5 ( V_2 -> V_14 ,
L_3 ,
V_3 , V_4 , V_5 , V_6 , ( int ) V_10 ) ;
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 , int V_16 )
{
struct V_17 * V_18 = F_7 ( V_2 ) ;
T_1 V_13 ;
char * V_19 ;
switch ( V_20 ) {
case - 1 :
if ( F_8 ( V_2 -> V_14 , L_4 ) )
V_19 = L_4 ;
else
V_19 = L_5 ;
break;
case 1 :
V_19 = L_4 ;
break;
default:
V_19 = L_5 ;
break;
}
F_5 ( V_2 -> V_14 , L_6 , V_19 ,
V_16 ) ;
if ( V_16 < 0 || V_16 >= V_18 -> V_21 )
return - V_22 ;
V_13 = F_9 ( V_2 -> V_14 , V_19 , V_16 ) ;
if ( F_3 ( V_13 ) ) {
F_4 ( V_2 -> V_14 , L_7 ,
V_19 ) ;
return - V_15 ;
}
V_18 -> V_23 = V_16 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_7 ( V_2 ) ;
unsigned long long V_6 = 0 ;
T_1 V_13 = V_24 ;
F_5 ( V_2 -> V_14 , L_8 ) ;
V_13 = F_2 ( V_2 -> V_14 , L_9 , NULL , & V_6 ) ;
if ( F_3 ( V_13 ) )
return 0 ;
V_18 -> V_23 = V_6 & 0x0fffffff ;
return V_18 -> V_23 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_7 ( V_2 ) ;
unsigned long long V_6 = 0 ;
T_1 V_13 = V_24 ;
F_5 ( V_2 -> V_14 , L_10 ) ;
V_13 = F_2 ( V_2 -> V_14 , L_11 , NULL , & V_6 ) ;
if ( F_3 ( V_13 ) )
return - 1 ;
V_18 -> V_21 = V_6 ;
return V_18 -> V_21 ;
}
static int F_12 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_13 ( V_26 ) ;
return V_26 -> V_27 . V_28 == V_29 ? 0 : F_10 ( V_2 ) ;
}
static int F_14 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_13 ( V_26 ) ;
if ( V_30 ) {
if ( V_26 -> V_27 . V_28 == V_29 )
F_1 ( V_30 , V_31 , 0x1 , 0x4 , 0x3 ) ;
else
F_1 ( V_30 , V_31 , 0x1 , 0x4 , 0x0 ) ;
}
return F_6 ( V_2 , V_26 -> V_27 . V_32 ) ;
}
static T_2 F_15 ( struct V_2 * V_33 , struct V_34 * V_35 ,
char * V_36 )
{
struct V_37 * V_18 = F_16 ( V_33 ) ;
if ( ! ( V_18 -> V_38 & V_39 ) )
return sprintf ( V_36 , L_12 ) ;
if ( V_18 -> V_40 & V_39 )
return sprintf ( V_36 , L_13 ) ;
else
return sprintf ( V_36 , L_14 ) ;
}
static T_2 F_17 ( struct V_2 * V_33 , struct V_34 * V_35 ,
char * V_36 )
{
struct V_37 * V_18 = F_16 ( V_33 ) ;
if ( ! ( V_18 -> V_38 & V_41 ) )
return sprintf ( V_36 , L_12 ) ;
if ( V_18 -> V_40 & V_41 )
return sprintf ( V_36 , L_15 ) ;
else
return sprintf ( V_36 , L_16 ) ;
}
static T_2 F_18 ( struct V_2 * V_33 , struct V_34 * V_35 ,
char * V_36 )
{
struct V_37 * V_18 = F_16 ( V_33 ) ;
if ( ! ( V_18 -> V_38 & V_42 ) )
return sprintf ( V_36 , L_12 ) ;
if ( V_18 -> V_40 & V_42 )
return sprintf ( V_36 , L_17 ) ;
else
return sprintf ( V_36 , L_18 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_7 ( V_2 ) ;
int V_43 ;
V_18 -> V_44 = F_20 ( & V_2 -> V_33 ) ;
if ( ! V_18 -> V_44 )
return - V_45 ;
snprintf ( V_18 -> V_46 , sizeof( V_18 -> V_46 ) , L_19 ,
F_21 ( V_2 ) ) ;
V_18 -> V_44 -> V_47 = F_22 ( V_2 ) ;
V_18 -> V_44 -> V_46 = V_18 -> V_46 ;
V_18 -> V_44 -> V_48 . V_49 = V_50 ;
V_18 -> V_44 -> V_48 . V_51 = 0x06 ;
V_43 = F_23 ( V_18 -> V_44 , V_52 , NULL ) ;
if ( V_43 )
return V_43 ;
return F_24 ( V_18 -> V_44 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_7 ( V_2 ) ;
const struct V_53 V_27 = {
. V_32 = V_18 -> V_23 ,
. V_21 = V_18 -> V_21 - 1 ,
. type = V_54
} ;
struct V_25 * V_55 ;
V_55 = F_26 ( & V_2 -> V_33 , L_20 ,
& V_2 -> V_33 , V_2 ,
& V_56 , & V_27 ) ;
if ( F_27 ( V_55 ) )
return F_28 ( V_55 ) ;
V_18 -> V_57 = V_55 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
int error ;
if ( F_30 () != V_58 )
return - V_15 ;
V_18 = F_31 ( & V_2 -> V_33 , sizeof( * V_18 ) , V_59 ) ;
if ( ! V_18 )
return - V_45 ;
V_17 = V_18 ;
strcpy ( F_22 ( V_2 ) , V_60 ) ;
strcpy ( F_32 ( V_2 ) , V_61 ) ;
V_2 -> V_62 = V_18 ;
error = F_19 ( V_2 ) ;
if ( error )
return error ;
F_33 ( L_21 ,
F_22 ( V_2 ) , F_34 ( V_2 ) ) ;
if ( F_11 ( V_2 ) <= 0 )
V_18 -> V_21 = V_63 ;
F_10 ( V_2 ) ;
error = F_25 ( V_2 ) ;
if ( error )
return error ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 , T_3 V_64 )
{
struct V_17 * V_18 = F_7 ( V_2 ) ;
int V_65 , V_66 ;
if ( V_64 != V_67 ) {
F_36 ( V_2 -> V_14 , L_22 ,
V_64 ) ;
F_37 ( V_18 -> V_44 , - 1 , 1 , true ) ;
return;
}
V_65 = V_18 -> V_23 ;
F_10 ( V_2 ) ;
V_66 = V_18 -> V_23 ;
F_5 ( V_2 -> V_14 ,
L_23 , V_65 , V_66 ) ;
if ( V_65 == V_66 )
return;
if ( ! V_68 )
F_6 ( V_2 , V_66 ) ;
F_37 ( V_18 -> V_44 , V_65 < V_66 , 1 , true ) ;
}
static int F_38 ( const struct V_69 * V_48 )
{
F_33 ( L_24 , V_48 -> V_70 ) ;
V_71 = V_48 -> V_62 ;
return 1 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_37 * V_18 = F_7 ( V_2 ) ;
int V_43 ;
V_18 -> V_44 = F_20 ( & V_2 -> V_33 ) ;
if ( ! V_18 -> V_44 )
return - V_45 ;
snprintf ( V_18 -> V_46 , sizeof( V_18 -> V_46 ) , L_25 ,
F_21 ( V_2 ) ) ;
V_18 -> V_44 -> V_47 = F_22 ( V_2 ) ;
V_18 -> V_44 -> V_46 = V_18 -> V_46 ;
V_18 -> V_44 -> V_48 . V_49 = V_50 ;
F_40 ( V_72 ) ;
V_43 = F_23 ( V_18 -> V_44 , V_71 , NULL ) ;
if ( V_43 )
return V_43 ;
return F_24 ( V_18 -> V_44 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_37 * V_18 = F_7 ( V_2 ) ;
int V_43 ;
V_18 -> V_73 = F_42 ( L_20 , - 1 ) ;
if ( ! V_18 -> V_73 )
return - V_45 ;
F_43 ( V_18 -> V_73 , V_18 ) ;
V_43 = F_44 ( V_18 -> V_73 ) ;
if ( V_43 )
goto V_74;
V_43 = F_45 ( & V_18 -> V_73 -> V_33 . V_75 ,
& V_76 ) ;
if ( V_43 )
goto V_77;
return 0 ;
V_77:
F_46 ( V_18 -> V_73 ) ;
V_74:
F_47 ( V_18 -> V_73 ) ;
return V_43 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_37 * V_18 = F_7 ( V_2 ) ;
F_49 ( & V_18 -> V_73 -> V_33 . V_75 ,
& V_76 ) ;
F_50 ( V_18 -> V_73 ) ;
}
static int F_51 ( struct V_78 * V_79 ,
enum V_80 V_32 )
{
struct V_1 * V_2 = F_52 ( V_79 -> V_33 -> V_81 ) ;
int V_82 = V_83 , V_84 = V_83 ;
int V_43 ;
if ( V_32 < V_85 )
V_82 = V_86 ;
if ( V_32 < V_87 )
V_84 = V_86 ;
V_43 = F_1 ( V_2 , V_88 , 0x1 , V_89 , V_82 ) ;
if ( V_43 < 0 )
return V_43 ;
return F_1 ( V_2 , V_88 , 0x1 , V_90 , V_84 ) ;
}
static enum V_80 F_53 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_52 ( V_79 -> V_33 -> V_81 ) ;
int V_43 ;
V_43 = F_1 ( V_2 , V_88 , 0x2 , V_90 , 0x0 ) ;
if ( V_43 == V_83 )
return V_87 ;
V_43 = F_1 ( V_2 , V_88 , 0x2 , V_89 , 0x0 ) ;
if ( V_43 == V_83 )
return V_85 ;
return V_91 ;
}
static int F_54 ( struct V_78 * V_79 ,
enum V_80 V_32 )
{
struct V_1 * V_2 = F_52 ( V_79 -> V_33 -> V_81 ) ;
if ( V_32 >= V_87 )
return F_1 ( V_2 , V_88 , 0x1 , V_92 ,
V_83 ) ;
else
return F_1 ( V_2 , V_88 , 0x1 , V_92 ,
V_86 ) ;
}
static enum V_80 F_55 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_52 ( V_79 -> V_33 -> V_81 ) ;
enum V_80 V_32 = V_91 ;
if ( F_1 ( V_2 ,
V_88 , 0x2 , V_92 , 0x0 ) == V_83 )
V_32 = V_87 ;
return V_32 ;
}
static int F_56 ( struct V_78 * V_79 ,
enum V_80 V_32 )
{
struct V_1 * V_2 = F_52 ( V_79 -> V_33 -> V_81 ) ;
if ( V_32 >= V_87 )
return F_1 ( V_2 , V_93 , 0x5 , V_94 ,
V_94 ) ;
else
return F_1 ( V_2 , V_93 , 0x5 , V_94 ,
0x0 ) ;
}
static enum V_80 F_57 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_52 ( V_79 -> V_33 -> V_81 ) ;
enum V_80 V_32 = V_91 ;
if ( F_1 ( V_2 , V_93 , 0x4 , 0x0 , 0x0 ) & V_94 )
V_32 = V_87 ;
return V_32 ;
}
static int F_58 ( struct V_78 * V_79 ,
enum V_80 V_32 )
{
struct V_1 * V_2 = F_52 ( V_79 -> V_33 -> V_81 ) ;
int V_95 ;
V_95 = F_1 ( V_2 , V_88 , 0x2 , V_96 , 0x0 ) ;
if ( V_32 >= V_87 )
return F_1 ( V_2 , V_88 , 0x1 , V_96 ,
V_95 | V_97 ) ;
else
return F_1 ( V_2 , V_88 , 0x1 , V_96 ,
V_95 & ~ V_97 ) ;
}
static enum V_80 F_59 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_52 ( V_79 -> V_33 -> V_81 ) ;
enum V_80 V_32 = V_91 ;
if ( F_1 ( V_2 , V_88 , 0x2 , V_96 , 0x0 ) & V_97 )
V_32 = V_87 ;
return V_32 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_78 * V_98 ;
int V_99 ;
if ( F_1 ( V_2 ,
V_88 , 0x0 , 0x0 , 0x0 ) & V_89 ) {
V_98 = F_31 ( & V_2 -> V_33 , sizeof( * V_98 ) , V_59 ) ;
if ( ! V_98 )
return - V_45 ;
V_98 -> V_47 = L_26 ;
V_98 -> V_100 = F_51 ;
V_98 -> V_101 = F_53 ;
V_99 = F_61 ( & V_2 -> V_33 , V_98 ) ;
if ( V_99 )
return V_99 ;
}
if ( ( F_1 ( V_2 ,
V_88 , 0x0 , 0x0 , 0x0 ) & V_92 ) &&
( F_1 ( V_2 , V_102 , 0x0 , 0x0 , 0x0 ) == 0x0 ) ) {
V_98 = F_31 ( & V_2 -> V_33 , sizeof( * V_98 ) , V_59 ) ;
if ( ! V_98 )
return - V_45 ;
V_98 -> V_47 = L_27 ;
V_98 -> V_100 = F_54 ;
V_98 -> V_101 = F_55 ;
V_99 = F_61 ( & V_2 -> V_33 , V_98 ) ;
if ( V_99 )
return V_99 ;
}
if ( F_1 ( V_2 , V_102 , 0x0 , 0x0 , 0x0 ) & F_62 ( 24 ) ) {
V_98 = F_31 ( & V_2 -> V_33 , sizeof( * V_98 ) , V_59 ) ;
if ( ! V_98 )
return - V_45 ;
V_98 -> V_47 = L_28 ;
V_98 -> V_100 = F_56 ;
V_98 -> V_101 = F_57 ;
V_98 -> V_103 = L_29 ;
V_99 = F_61 ( & V_2 -> V_33 , V_98 ) ;
if ( V_99 )
return V_99 ;
}
if ( ( F_1 ( V_2 , V_88 , 0x0 , 0x0 , 0x0 ) & F_62 ( 14 ) ) &&
( F_1 ( V_2 ,
V_88 , 0x2 , V_96 , 0x0 ) != V_104 ) ) {
V_98 = F_31 ( & V_2 -> V_33 , sizeof( * V_98 ) , V_59 ) ;
if ( ! V_98 )
return - V_45 ;
V_98 -> V_47 = L_30 ;
V_98 -> V_100 = F_58 ;
V_98 -> V_101 = F_59 ;
V_99 = F_61 ( & V_2 -> V_33 , V_98 ) ;
if ( V_99 )
return V_99 ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_37 * V_18 ;
int error ;
int V_105 ;
V_18 = F_31 ( & V_2 -> V_33 , sizeof( * V_18 ) , V_59 ) ;
if ( ! V_18 )
return - V_45 ;
F_64 ( V_30 , L_31 ) ;
V_30 = V_2 ;
strcpy ( F_22 ( V_2 ) , V_106 ) ;
strcpy ( F_32 ( V_2 ) , V_61 ) ;
V_2 -> V_62 = V_18 ;
F_65 ( & V_18 -> V_107 ) ;
error = F_66 ( & V_18 -> V_108 , V_109 * sizeof( int ) ,
V_59 ) ;
if ( error ) {
F_67 ( L_32 ) ;
goto V_110;
}
error = F_39 ( V_2 ) ;
if ( error )
goto V_111;
F_33 ( L_21 ,
F_22 ( V_2 ) , F_34 ( V_2 ) ) ;
V_105 = 0 ;
while ( F_1 ( V_2 , V_102 , 0x1 , 0x0 , 0x0 ) != 0
&& ( V_105 ++ ) < V_112 )
;
F_5 ( V_2 -> V_14 , L_33 ,
V_105 ) ;
V_18 -> V_38 = F_1 ( V_2 , V_93 , 0x0 , 0x0 ,
0x0 ) ;
if ( V_18 -> V_38 == V_104 )
V_18 -> V_38 = 0 ;
if ( V_18 -> V_38 )
V_18 -> V_40 = F_1 ( V_2 , V_93 , 0x4 , 0x0 ,
0x0 ) ;
F_36 ( V_2 -> V_14 , L_34 ,
F_1 ( V_2 , V_102 , 0x0 , 0x0 , 0x0 ) ) ;
if ( V_17 && V_17 -> V_57 &&
F_30 () == V_58 ) {
if ( F_1 ( V_30 , V_31 , 0x2 , 0x4 , 0x0 ) == 3 )
V_17 -> V_57 -> V_27 . V_28 = V_29 ;
else
V_17 -> V_57 -> V_27 . V_28 = V_113 ;
}
error = F_60 ( V_2 ) ;
if ( error )
goto V_111;
error = F_41 ( V_2 ) ;
if ( error )
goto V_111;
return 0 ;
V_111:
F_68 ( & V_18 -> V_108 ) ;
V_110:
return error ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_37 * V_18 = F_7 ( V_2 ) ;
F_48 ( V_2 ) ;
F_68 ( & V_18 -> V_108 ) ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 , int V_114 )
{
struct V_37 * V_18 = F_7 ( V_2 ) ;
int V_13 ;
V_13 = F_71 ( & V_18 -> V_108 , ( unsigned char * ) & V_114 ,
sizeof( V_114 ) , & V_18 -> V_107 ) ;
if ( V_13 != sizeof( V_114 ) ) {
F_72 ( & V_18 -> V_44 -> V_33 , L_35 ,
V_114 ) ;
return;
}
F_37 ( V_18 -> V_44 , V_114 , 1 , false ) ;
F_73 ( & V_18 -> V_44 -> V_33 , L_36 ,
V_114 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_37 * V_18 = F_7 ( V_2 ) ;
int V_114 , V_13 ;
while ( true ) {
V_13 = F_75 ( & V_18 -> V_108 ,
( unsigned char * ) & V_114 ,
sizeof( V_114 ) , & V_18 -> V_107 ) ;
if ( V_13 != sizeof( V_114 ) )
return;
F_37 ( V_18 -> V_44 , V_114 , 0 , false ) ;
F_73 ( & V_18 -> V_44 -> V_33 ,
L_37 , V_114 ) ;
}
}
static void F_76 ( struct V_1 * V_2 , T_3 V_64 )
{
struct V_37 * V_18 = F_7 ( V_2 ) ;
int V_114 , V_105 = 0 ;
unsigned int V_115 ;
if ( V_64 != V_67 ) {
F_36 ( V_2 -> V_14 , L_38 ,
V_64 ) ;
F_37 ( V_18 -> V_44 , - 1 , 1 , true ) ;
return;
}
if ( V_18 -> V_38 )
V_18 -> V_40 = F_1 ( V_2 , V_93 , 0x4 , 0x0 ,
0x0 ) ;
while ( ( V_115 = F_1 ( V_2 ,
V_102 , 0x1 , 0x0 , 0x0 ) ) != 0 &&
V_105 ++ < V_112 ) {
V_114 = V_115 & 0x4ff ;
if ( F_77 ( V_18 -> V_44 , V_114 ) )
F_70 ( V_2 , V_114 ) ;
else if ( V_114 == 0 )
F_74 ( V_2 ) ;
else
F_36 ( V_2 -> V_14 ,
L_39 , V_115 ) ;
}
if ( ( V_18 -> V_38 & F_62 ( 26 ) ) &&
( F_1 ( V_2 , V_93 , 0x1 , 0x0 , 0x0 ) & F_62 ( 26 ) ) )
F_37 ( V_18 -> V_44 , F_62 ( 26 ) , 1 , true ) ;
}
static int T_4 F_78 ( void )
{
int V_43 ;
V_43 = F_79 ( & V_116 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_80 ( & V_117 ) ;
if ( V_43 )
goto V_118;
V_43 = F_79 ( & V_119 ) ;
if ( V_43 )
goto V_120;
F_33 ( L_40 V_121 L_41 ) ;
return 0 ;
V_120:
F_81 ( & V_117 ) ;
V_118:
F_82 ( & V_116 ) ;
return V_43 ;
}
static void T_5 F_83 ( void )
{
F_82 ( & V_119 ) ;
F_81 ( & V_117 ) ;
F_82 ( & V_116 ) ;
F_33 ( L_42 ) ;
}
