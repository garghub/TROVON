static int F_1 ( T_1 V_1 , const char * V_2 , int V_3 )
{
struct V_4 V_5 ;
union V_6 V_7 ;
T_2 V_8 ;
V_5 . V_9 = 1 ;
V_5 . V_10 = & V_7 ;
V_7 . type = V_11 ;
V_7 . integer . V_12 = V_3 ;
V_8 = F_2 ( V_1 , ( char * ) V_2 , & V_5 , NULL ) ;
return ( V_8 == V_13 ? 0 : - 1 ) ;
}
static int F_3 ( T_1 V_1 , const char * V_2 , int * V_3 )
{
T_2 V_8 ;
unsigned long long V_14 ;
V_8 = F_4 ( V_1 , ( char * ) V_2 , NULL , & V_14 ) ;
if ( F_5 ( V_8 ) ) {
* V_3 = - 1 ;
return - 1 ;
} else {
* V_3 = V_14 ;
return 0 ;
}
}
static int F_6 ( struct V_15 * V_16 , int V_17 , int V_12 )
{
const char * V_2 = V_18 [ V_17 ] ;
if ( V_2 == NULL )
return - V_19 ;
if ( ( V_16 -> V_20 & ( 0x1 << V_17 ) ) == 0 )
return - V_19 ;
if ( F_1 ( V_16 -> V_1 , V_2 , V_12 ) )
F_7 ( L_1 , V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_15 * V_16 , int V_17 )
{
const char * V_2 = V_21 [ V_17 ] ;
int V_12 ;
if ( V_2 == NULL )
return - V_19 ;
if ( ( V_16 -> V_20 & ( 0x1 << V_17 ) ) == 0 )
return - V_19 ;
if ( F_3 ( V_16 -> V_1 , V_2 , & V_12 ) )
F_7 ( L_2 , V_2 ) ;
return V_12 ;
}
static int F_9 ( struct V_15 * V_16 , int V_17 ,
T_1 * V_1 )
{
const char * V_2 = V_18 [ V_17 ] ;
T_2 V_8 ;
if ( V_2 == NULL )
return - V_19 ;
if ( ( V_16 -> V_20 & ( 0x1 << V_17 ) ) == 0 )
return - V_19 ;
V_8 = F_10 ( V_16 -> V_1 , ( char * ) V_2 ,
V_1 ) ;
if ( V_8 != V_13 ) {
F_7 ( L_3 , V_2 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_11 ( const char * V_22 , unsigned long V_9 , int * V_3 )
{
if ( ! V_9 )
return 0 ;
if ( sscanf ( V_22 , L_4 , V_3 ) != 1 )
return - V_23 ;
return V_9 ;
}
static T_3 F_12 ( struct V_24 * V_25 , int V_17 ,
const char * V_22 , T_4 V_9 )
{
struct V_15 * V_16 = F_13 ( V_25 ) ;
int V_26 , V_12 ;
V_26 = F_11 ( V_22 , V_9 , & V_12 ) ;
if ( V_26 > 0 )
V_12 = F_6 ( V_16 , V_17 , V_12 ) ;
if ( V_12 < 0 )
return - V_27 ;
return V_26 ;
}
static T_3 F_14 ( struct V_24 * V_25 , int V_17 , char * V_22 )
{
struct V_15 * V_16 = F_13 ( V_25 ) ;
int V_12 = F_8 ( V_16 , V_17 ) ;
if ( V_12 < 0 )
return - V_27 ;
return sprintf ( V_22 , L_5 , V_12 ) ;
}
static int F_15 ( struct V_15 * V_16 , struct V_28 * V_29 )
{
V_29 -> V_30 = F_8 ( V_16 , V_31 ) ;
V_29 -> V_32 = ( V_29 -> V_30 >> 8 ) & 0xff ;
V_29 -> V_30 &= 0xff ;
if ( V_29 -> V_30 < 0 || V_29 -> V_32 <= 0 || V_29 -> V_32 > 12 )
return - V_19 ;
return 0 ;
}
static T_3 F_16 ( struct V_24 * V_25 ,
struct V_33 * V_34 ,
char * V_22 )
{
struct V_15 * V_16 = F_13 ( V_25 ) ;
struct V_28 V_29 ;
int V_35 ;
T_3 V_36 = 0 ;
if ( F_15 ( V_16 , & V_29 ) )
return - V_19 ;
for ( V_35 = 0 ; V_35 < V_29 . V_32 ; V_35 ++ )
V_36 += sprintf ( V_22 + V_36 , L_6 , V_35 ) ;
V_36 += sprintf ( V_22 + V_36 , L_7 ) ;
return V_36 ;
}
static T_3 F_17 ( struct V_24 * V_25 ,
struct V_33 * V_34 ,
char * V_22 )
{
struct V_15 * V_16 = F_13 ( V_25 ) ;
struct V_28 V_29 ;
if ( F_15 ( V_16 , & V_29 ) )
return - V_19 ;
return sprintf ( V_22 , L_8 , ( V_29 . V_32 << 8 ) | V_29 . V_30 ) ;
}
static T_3 F_18 ( struct V_24 * V_25 ,
struct V_33 * V_34 ,
const char * V_22 , T_4 V_9 )
{
struct V_15 * V_16 = F_13 ( V_25 ) ;
struct V_28 V_29 ;
int V_26 , V_12 ;
if ( V_16 -> V_37 )
return - V_38 ;
if ( F_15 ( V_16 , & V_29 ) )
return - V_19 ;
V_26 = F_11 ( V_22 , V_9 , & V_12 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( ! V_26 || V_12 < 0 || V_12 >= V_29 . V_32 )
return - V_23 ;
F_6 ( V_16 , V_31 , V_12 ) ;
return V_26 ;
}
static T_3 F_19 ( struct V_24 * V_25 ,
struct V_33 * V_34 ,
char * V_22 )
{
struct V_15 * V_16 = F_13 ( V_25 ) ;
return sprintf ( V_22 , L_5 , V_16 -> V_37 ) ;
}
static T_3 F_20 ( struct V_24 * V_25 ,
struct V_33 * V_34 ,
const char * V_22 , T_4 V_9 )
{
struct V_15 * V_16 = F_13 ( V_25 ) ;
int V_26 , V_12 ;
V_26 = F_11 ( V_22 , V_9 , & V_12 ) ;
if ( V_26 < 0 )
return V_26 ;
switch ( V_12 ) {
case 0 :
if ( V_16 -> V_37 )
F_7 ( L_9
L_10 ) ;
V_16 -> V_37 = false ;
return V_26 ;
case 1 :
return - V_38 ;
default:
return - V_23 ;
}
}
static int F_21 ( struct V_15 * V_16 )
{
int V_14 ;
V_16 -> V_39 = F_22 ( V_40 , - 1 ) ;
if ( ! V_16 -> V_39 )
return - V_41 ;
F_23 ( V_16 -> V_39 , V_16 ) ;
V_14 = F_24 ( V_16 -> V_39 ) ;
if ( V_14 )
goto V_42;
V_14 = F_25 ( & V_16 -> V_39 -> V_25 . V_43 ,
& V_44 ) ;
if ( V_14 )
goto V_45;
return 0 ;
V_45:
F_26 ( V_16 -> V_39 ) ;
V_42:
F_27 ( V_16 -> V_39 ) ;
return V_14 ;
}
static void F_28 ( struct V_15 * V_16 )
{
F_29 ( & V_16 -> V_39 -> V_25 . V_43 ,
& V_44 ) ;
F_30 ( V_16 -> V_39 ) ;
}
static void F_31 ( struct V_46 * V_47 )
{
struct V_15 * V_16 ;
V_16 = F_32 ( V_47 , struct V_15 , V_48 ) ;
F_6 ( V_16 , V_49 , V_16 -> V_50 ) ;
}
static void F_33 ( struct V_51 * V_52 ,
enum V_53 V_12 )
{
struct V_15 * V_16 ;
V_16 = F_32 ( V_52 , struct V_15 , V_54 ) ;
V_16 -> V_50 = ( V_12 > 0 ) ? 1 : 0 ;
F_34 ( V_16 -> V_55 , & V_16 -> V_48 ) ;
}
static enum V_53 F_35 ( struct V_51 * V_52 )
{
struct V_15 * V_16 ;
V_16 = F_32 ( V_52 , struct V_15 , V_54 ) ;
return F_8 ( V_16 , V_49 ) ;
}
static int F_36 ( struct V_15 * V_16 )
{
int V_26 ;
if ( F_8 ( V_16 , V_49 ) == - V_19 )
return 0 ;
V_16 -> V_55 = F_37 ( L_11 ) ;
if ( ! V_16 -> V_55 )
return - V_41 ;
F_38 ( & V_16 -> V_48 , F_31 ) ;
V_16 -> V_54 . V_56 = L_12 ;
V_16 -> V_54 . V_57 = F_33 ;
if ( F_8 ( V_16 , V_49 ) >= 0 )
V_16 -> V_54 . V_58 = F_35 ;
V_16 -> V_54 . V_59 = 1 ;
V_26 = F_39 ( & V_16 -> V_39 -> V_25 ,
& V_16 -> V_54 ) ;
if ( V_26 ) {
F_40 ( V_16 -> V_55 ) ;
return V_26 ;
}
return 0 ;
}
static void F_41 ( struct V_15 * V_16 )
{
if ( ! F_42 ( V_16 -> V_54 . V_25 ) )
F_43 ( & V_16 -> V_54 ) ;
if ( V_16 -> V_55 )
F_40 ( V_16 -> V_55 ) ;
}
static bool F_44 ( struct V_15 * V_16 )
{
if ( F_8 ( V_16 , V_60 ) == 1 )
return false ;
return true ;
}
static void F_45 ( struct V_15 * V_16 , T_1 V_1 )
{
struct V_61 * V_62 ;
struct V_61 * V_25 ;
struct V_63 * V_64 ;
bool V_65 = F_44 ( V_16 ) ;
bool V_66 ;
T_5 V_67 ;
if ( V_16 -> V_68 )
F_46 ( V_16 -> V_68 , V_65 ) ;
F_47 ( & V_16 -> V_69 ) ;
if ( V_16 -> V_70 ) {
V_62 = F_48 ( V_1 ) ;
if ( ! V_62 ) {
F_49 ( L_13 ) ;
goto V_71;
}
V_64 = V_62 -> V_72 ;
if ( ! V_64 ) {
F_7 ( L_14 ) ;
goto V_73;
}
if ( F_50 ( V_64 , 0 , V_74 , & V_67 ) ) {
F_51 ( L_15 ) ;
goto V_73;
}
V_66 = ( V_67 == 0xffffffff ) ;
if ( V_65 != V_66 ) {
F_7 ( L_16
L_17 ,
V_65 ? L_18 : L_19 ,
V_66 ? L_20 : L_21 ) ;
F_7 ( L_22
L_23 ) ;
goto V_73;
}
if ( ! V_65 ) {
V_25 = F_52 ( V_64 , 0 ) ;
if ( V_25 ) {
F_53 ( V_25 ) ;
goto V_73;
}
V_25 = F_54 ( V_64 , 0 ) ;
if ( V_25 ) {
F_55 ( V_64 ) ;
if ( F_56 ( V_25 ) )
F_51 ( L_24 ) ;
}
} else {
V_25 = F_52 ( V_64 , 0 ) ;
if ( V_25 ) {
F_57 ( V_25 ) ;
F_53 ( V_25 ) ;
}
}
V_73:
F_53 ( V_62 ) ;
}
V_71:
F_58 ( & V_16 -> V_69 ) ;
}
static void F_59 ( struct V_15 * V_16 , char * V_75 )
{
T_2 V_8 = V_13 ;
T_1 V_1 ;
V_8 = F_10 ( NULL , V_75 , & V_1 ) ;
if ( F_60 ( V_8 ) )
F_45 ( V_16 , V_1 ) ;
}
static void F_61 ( T_1 V_1 , T_5 V_76 , void * V_77 )
{
struct V_15 * V_16 = V_77 ;
if ( V_76 != V_78 )
return;
F_45 ( V_16 , V_1 ) ;
}
static int F_62 ( struct V_15 * V_16 ,
char * V_75 )
{
T_2 V_8 ;
T_1 V_1 ;
V_8 = F_10 ( NULL , V_75 , & V_1 ) ;
if ( F_60 ( V_8 ) ) {
V_8 = F_63 ( V_1 ,
V_79 ,
F_61 ,
V_16 ) ;
if ( F_5 ( V_8 ) )
F_7 ( L_25 , V_75 ) ;
F_45 ( V_16 , V_1 ) ;
} else
return - V_19 ;
return 0 ;
}
static void F_64 ( struct V_15 * V_16 ,
char * V_75 )
{
T_2 V_8 = V_13 ;
T_1 V_1 ;
V_8 = F_10 ( NULL , V_75 , & V_1 ) ;
if ( F_60 ( V_8 ) ) {
V_8 = F_65 ( V_1 ,
V_79 ,
F_61 ) ;
if ( F_5 ( V_8 ) )
F_51 ( L_26 ,
V_75 ) ;
F_45 ( V_16 , V_1 ) ;
}
}
static int F_66 ( struct V_70 * V_70 ,
T_6 * V_12 )
{
struct V_15 * V_16 = V_70 -> V_80 ;
int V_3 = F_8 ( V_16 , V_60 ) ;
if ( V_3 == 1 || V_3 == 0 )
* V_12 = V_3 ;
else
return - V_23 ;
return 0 ;
}
static void F_67 ( struct V_70 * V_70 )
{
F_68 ( V_70 -> V_81 ) ;
F_68 ( V_70 ) ;
}
static int F_69 ( struct V_15 * V_16 )
{
int V_82 = - V_41 ;
struct V_63 * V_64 = F_70 ( 0 , 1 ) ;
if ( ! V_64 ) {
F_51 ( L_27 ) ;
return - V_19 ;
}
V_16 -> V_70 = F_71 ( sizeof( struct V_70 ) , V_83 ) ;
if ( ! V_16 -> V_70 )
goto V_84;
V_16 -> V_70 -> V_81 = F_71 ( sizeof( struct V_85 ) ,
V_83 ) ;
if ( ! V_16 -> V_70 -> V_81 )
goto V_86;
V_16 -> V_70 -> V_80 = V_16 ;
V_16 -> V_70 -> V_87 = & F_67 ;
V_16 -> V_70 -> V_88 = & V_89 ;
F_66 ( V_16 -> V_70 ,
& V_16 -> V_70 -> V_81 -> V_90 ) ;
V_82 = F_72 ( V_16 -> V_70 , V_64 , 0 , L_28 ) ;
if ( V_82 ) {
F_51 ( L_29 , V_82 ) ;
goto V_91;
}
return 0 ;
V_91:
F_68 ( V_16 -> V_70 -> V_81 ) ;
V_86:
F_68 ( V_16 -> V_70 ) ;
V_16 -> V_70 = NULL ;
V_84:
return V_82 ;
}
static int F_73 ( void * V_77 , bool V_65 )
{
T_1 V_1 = V_77 ;
return F_1 ( V_1 , NULL , ! V_65 ) ;
}
static int F_74 ( struct V_15 * V_16 ,
struct V_92 * * V_92 ,
const char * V_56 ,
enum V_93 type , int V_17 )
{
T_1 V_1 ;
int V_14 ;
V_14 = F_9 ( V_16 , V_17 , & V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_92 = F_75 ( V_56 , & V_16 -> V_39 -> V_25 , type ,
& V_94 , V_1 ) ;
if ( ! * V_92 )
return - V_23 ;
F_76 ( * V_92 , F_8 ( V_16 , V_17 ) != 1 ) ;
V_14 = F_77 ( * V_92 ) ;
if ( V_14 ) {
F_78 ( * V_92 ) ;
* V_92 = NULL ;
return V_14 ;
}
return 0 ;
}
static void F_79 ( struct V_15 * V_16 )
{
F_64 ( V_16 , L_30 ) ;
F_64 ( V_16 , L_31 ) ;
F_64 ( V_16 , L_32 ) ;
if ( V_16 -> V_68 ) {
F_80 ( V_16 -> V_68 ) ;
F_78 ( V_16 -> V_68 ) ;
V_16 -> V_68 = NULL ;
}
if ( V_16 -> V_70 )
F_81 ( V_16 -> V_70 ) ;
if ( V_16 -> V_95 ) {
F_80 ( V_16 -> V_95 ) ;
F_78 ( V_16 -> V_95 ) ;
V_16 -> V_95 = NULL ;
}
if ( V_16 -> V_96 ) {
F_80 ( V_16 -> V_96 ) ;
F_78 ( V_16 -> V_96 ) ;
V_16 -> V_96 = NULL ;
}
if ( V_16 -> V_97 ) {
F_80 ( V_16 -> V_97 ) ;
F_78 ( V_16 -> V_97 ) ;
V_16 -> V_97 = NULL ;
}
}
static int F_82 ( struct V_15 * V_16 )
{
int V_14 = 0 ;
F_83 ( & V_16 -> V_69 ) ;
V_14 = F_74 ( V_16 , & V_16 -> V_68 ,
L_33 , V_98 ,
V_60 ) ;
if ( V_14 && V_14 != - V_19 )
goto exit;
V_14 = F_74 ( V_16 , & V_16 -> V_95 ,
L_34 , V_99 ,
V_100 ) ;
if ( V_14 && V_14 != - V_19 )
goto exit;
V_14 = F_74 ( V_16 , & V_16 -> V_96 ,
L_35 , V_101 ,
V_102 ) ;
if ( V_14 && V_14 != - V_19 )
goto exit;
V_14 = F_74 ( V_16 , & V_16 -> V_97 ,
L_36 , V_103 ,
V_104 ) ;
if ( V_14 && V_14 != - V_19 )
goto exit;
if ( V_16 -> V_105 )
return 0 ;
V_14 = F_69 ( V_16 ) ;
if ( V_14 == - V_106 )
V_14 = 0 ;
F_62 ( V_16 , L_30 ) ;
F_62 ( V_16 , L_31 ) ;
F_62 ( V_16 , L_32 ) ;
exit:
if ( V_14 && V_14 != - V_19 )
F_79 ( V_16 ) ;
return V_14 ;
}
static int F_84 ( struct V_24 * V_24 )
{
struct V_15 * V_16 = F_13 ( V_24 ) ;
if ( V_16 -> V_68 ) {
bool V_107 ;
V_107 = F_8 ( V_16 , V_60 ) ;
F_6 ( V_16 , V_60 , V_107 ) ;
}
return 0 ;
}
static int F_85 ( struct V_24 * V_24 )
{
struct V_15 * V_16 = F_13 ( V_24 ) ;
if ( V_16 -> V_68 ) {
F_59 ( V_16 , L_30 ) ;
F_59 ( V_16 , L_31 ) ;
F_59 ( V_16 , L_32 ) ;
}
if ( V_16 -> V_95 )
F_46 ( V_16 -> V_95 ,
F_8 ( V_16 , V_100 ) != 1 ) ;
if ( V_16 -> V_96 )
F_46 ( V_16 -> V_96 ,
F_8 ( V_16 , V_102 ) != 1 ) ;
if ( V_16 -> V_97 )
F_46 ( V_16 -> V_97 ,
F_8 ( V_16 , V_104 ) != 1 ) ;
return 0 ;
}
static int F_86 ( void )
{
T_6 V_12 = 0 ;
F_87 ( V_108 , & V_12 ) ;
return V_12 * 255 / 100 ;
}
static void F_88 ( int V_12 )
{
V_12 = F_89 ( V_12 , 0 , 255 ) ;
V_12 = V_12 * 100 / 255 ;
F_90 ( V_108 , V_12 ) ;
}
static int F_91 ( void )
{
T_6 V_109 = 0 ;
T_6 V_110 = 0 ;
F_87 ( V_111 , & V_109 ) ;
F_87 ( V_112 , & V_110 ) ;
return V_109 << 8 | V_110 ;
}
static int F_92 ( void )
{
T_6 V_12 = 0 ;
F_87 ( V_113 , & V_12 ) ;
if ( V_12 & 0x02 )
return 1 ;
else
return 2 ;
}
static void F_93 ( int V_114 )
{
T_6 V_12 = 0 ;
F_87 ( V_113 , & V_12 ) ;
if ( V_114 == 1 )
V_12 |= 0x02 ;
else
V_12 &= ~ 0x02 ;
F_90 ( V_113 , V_12 ) ;
}
static T_3 F_94 ( void (* F_95)( int ) , const char * V_22 , T_4 V_9 )
{
int V_26 , V_12 ;
V_26 = F_11 ( V_22 , V_9 , & V_12 ) ;
if ( V_26 > 0 )
F_95 ( V_12 ) ;
return V_26 ;
}
static T_3 F_96 ( int (* F_97)( void ) , char * V_22 )
{
return sprintf ( V_22 , L_5 , F_97 () ) ;
}
static T_3
F_98 ( struct V_24 * V_25 , struct V_33 * V_34 , char * V_22 )
{
return sprintf ( V_22 , L_37 ) ;
}
static void F_99 ( struct V_15 * V_16 )
{
struct V_24 * V_115 ;
V_115 = V_16 -> V_116 ;
if ( ! V_115 )
return;
F_29 ( & V_115 -> V_43 ,
& V_117 ) ;
F_100 ( V_115 ) ;
V_16 -> V_116 = NULL ;
}
static int F_101 ( struct V_15 * V_16 )
{
struct V_24 * V_115 ;
int V_14 ;
V_115 = F_102 ( & V_16 -> V_39 -> V_25 ) ;
if ( F_103 ( V_115 ) ) {
F_51 ( L_38 ) ;
V_16 -> V_116 = NULL ;
return F_104 ( V_115 ) ;
}
V_16 -> V_116 = V_115 ;
V_14 = F_25 ( & V_115 -> V_43 ,
& V_117 ) ;
if ( V_14 )
F_99 ( V_16 ) ;
return V_14 ;
}
static int F_105 ( struct V_118 * V_119 )
{
struct V_15 * V_16 = F_106 ( V_119 ) ;
return F_8 ( V_16 , V_120 ) ;
}
static int F_107 ( struct V_118 * V_119 , int V_12 )
{
struct V_15 * V_16 = F_106 ( V_119 ) ;
return F_6 ( V_16 , V_120 , V_12 ) ;
}
static int F_108 ( struct V_118 * V_119 )
{
return F_107 ( V_119 , V_119 -> V_121 . V_122 ) ;
}
static int F_109 ( struct V_15 * V_16 )
{
struct V_118 * V_119 = V_16 -> V_118 ;
int V_123 = V_119 -> V_121 . V_122 ;
F_110 ( V_119 , V_124 ) ;
return V_123 ;
}
static int F_111 ( struct V_15 * V_16 )
{
struct V_125 V_121 ;
struct V_118 * V_119 ;
memset ( & V_121 , 0 , sizeof( struct V_125 ) ) ;
V_121 . type = V_126 ;
V_121 . V_59 = 15 ;
V_119 = F_112 ( V_40 ,
& V_16 -> V_39 -> V_25 , V_16 ,
& V_127 , & V_121 ) ;
if ( F_103 ( V_119 ) ) {
F_51 ( L_39 ) ;
V_16 -> V_118 = NULL ;
return F_104 ( V_119 ) ;
}
V_16 -> V_118 = V_119 ;
V_119 -> V_121 . V_122 = F_105 ( V_119 ) ;
V_119 -> V_121 . V_128 = V_129 ;
F_113 ( V_119 ) ;
return 0 ;
}
static void F_114 ( struct V_15 * V_16 )
{
if ( V_16 -> V_118 )
F_115 ( V_16 -> V_118 ) ;
V_16 -> V_118 = NULL ;
}
static int F_116 ( struct V_15 * V_16 )
{
struct V_130 * V_131 ;
int error ;
V_131 = F_117 () ;
if ( ! V_131 ) {
F_118 ( L_40 ) ;
return - V_41 ;
}
V_131 -> V_56 = L_41 ;
V_131 -> V_132 = V_40 L_42 ;
V_131 -> V_133 . V_134 = V_135 ;
V_131 -> V_25 . V_136 = & V_16 -> V_39 -> V_25 ;
error = F_119 ( V_131 , V_137 , NULL ) ;
if ( error ) {
F_51 ( L_43 ) ;
goto V_138;
}
error = F_120 ( V_131 ) ;
if ( error ) {
F_51 ( L_44 ) ;
goto V_139;
}
V_16 -> V_140 = V_131 ;
return 0 ;
V_139:
F_121 ( V_131 ) ;
V_138:
F_122 ( V_131 ) ;
return error ;
}
static void F_123 ( struct V_15 * V_16 )
{
if ( V_16 -> V_140 ) {
F_121 ( V_16 -> V_140 ) ;
F_124 ( V_16 -> V_140 ) ;
}
V_16 -> V_140 = NULL ;
}
static void F_125 ( struct V_15 * V_16 , int V_76 )
{
if ( ! V_16 -> V_140 )
return ;
if ( ! F_126 ( V_16 -> V_140 , V_76 , 1 , true ) )
F_118 ( L_45 , V_76 ) ;
}
static void F_127 ( struct V_141 * V_24 , T_5 V_76 )
{
struct V_15 * V_16 = F_128 ( V_24 ) ;
T_7 V_9 ;
if ( V_76 > V_142 )
return;
V_9 = V_16 -> V_143 [ V_76 % 128 ] ++ ;
F_129 ( V_24 , V_76 , V_9 ) ;
F_130 ( V_24 -> V_144 . V_145 ,
F_131 ( & V_24 -> V_25 ) , V_76 ,
V_9 ) ;
if ( V_76 >= V_146 && V_76 <= V_147 ) {
if ( V_16 -> V_118 != NULL ) {
int V_148 , V_149 ;
V_148 = F_109 ( V_16 ) ;
V_149 = V_76 - V_146 ;
if ( V_149 < V_148 ) {
V_76 = V_146 ;
} else if ( V_149 > V_148 ) {
V_76 = V_147 ;
} else {
}
F_125 ( V_16 , V_76 ) ;
}
} else {
F_125 ( V_16 , V_76 ) ;
}
}
static void F_132 ( struct V_15 * V_16 )
{
const char * V_150 ;
V_150 = F_133 ( V_151 ) ;
if ( ! V_150 )
return;
if ( strcmp ( V_150 , L_46 ) == 0 || strcmp ( V_150 , L_47 ) == 0 ) {
V_16 -> V_37 = true ;
F_118 ( L_48
L_49 , V_150 ) ;
F_118 ( L_50 ) ;
}
if ( strcmp ( V_150 , L_51 ) == 0 || strcmp ( V_150 , L_52 ) == 0 ||
strcmp ( V_150 , L_53 ) == 0 ) {
V_16 -> V_105 = true ;
F_118 ( L_54 ) ;
}
}
static void F_134 ( struct V_15 * V_16 , int V_17 , const char * V_56 )
{
int V_152 ;
if ( ! ( V_16 -> V_20 & ( 1 << V_17 ) )
&& ! F_3 ( V_16 -> V_1 , V_21 [ V_17 ] , & V_152 ) ) {
F_118 ( L_55
L_56 , V_56 , 1 << V_17 ) ;
V_16 -> V_20 |= 1 << V_17 ;
}
}
static void F_135 ( struct V_15 * V_16 )
{
F_134 ( V_16 , V_153 , L_57 ) ;
F_134 ( V_16 , V_154 , L_58 ) ;
F_134 ( V_16 , V_155 , L_59 ) ;
F_134 ( V_16 , V_49 , L_60 ) ;
}
static int F_136 ( struct V_15 * V_16 )
{
unsigned int V_156 ;
int V_14 ;
V_14 = F_137 ( V_16 -> V_24 ) ;
if ( V_14 )
return V_14 ;
if ( ! V_16 -> V_24 -> V_8 . V_157 ) {
F_51 ( L_61 ) ;
return - V_19 ;
}
V_156 = V_158 | V_159 ;
F_138 ( L_62 , V_156 ) ;
if ( F_1 ( V_16 -> V_1 , L_63 , V_156 ) ) {
F_51 ( L_64 ) ;
return - V_19 ;
}
if ( F_3 ( V_16 -> V_1 , L_65 , & V_16 -> V_20 ) ) {
F_51 ( L_66 ) ;
return - V_19 ;
}
F_135 ( V_16 ) ;
F_118 ( L_67 , V_16 -> V_20 ) ;
return 0 ;
}
static void F_139 ( struct V_15 * V_16 )
{
if ( F_8 ( V_16 , V_160 ) == 0 )
F_6 ( V_16 , V_160 , 1 ) ;
}
static int F_140 ( struct V_141 * V_24 )
{
struct V_15 * V_16 ;
int V_14 ;
F_138 ( V_161 L_7 ) ;
V_16 = F_71 ( sizeof( struct V_15 ) , V_83 ) ;
if ( ! V_16 )
return - V_41 ;
V_16 -> V_1 = V_24 -> V_1 ;
strcpy ( F_141 ( V_24 ) , V_162 ) ;
strcpy ( F_142 ( V_24 ) , V_163 ) ;
V_24 -> V_164 = V_16 ;
V_16 -> V_24 = V_24 ;
V_16 -> V_105 = V_105 ;
F_132 ( V_16 ) ;
V_14 = F_136 ( V_16 ) ;
if ( V_14 )
goto V_165;
F_139 ( V_16 ) ;
V_14 = F_21 ( V_16 ) ;
if ( V_14 )
goto V_165;
if ( ! F_143 () ) {
V_14 = F_111 ( V_16 ) ;
if ( V_14 )
goto V_166;
} else
F_118 ( L_68 ) ;
V_14 = F_116 ( V_16 ) ;
if ( V_14 )
goto V_167;
V_14 = F_101 ( V_16 ) ;
if ( V_14 )
goto V_168;
V_14 = F_36 ( V_16 ) ;
if ( V_14 )
goto V_169;
V_14 = F_82 ( V_16 ) ;
if ( V_14 )
goto V_170;
V_171 = true ;
return 0 ;
V_170:
F_41 ( V_16 ) ;
V_169:
F_99 ( V_16 ) ;
V_168:
F_123 ( V_16 ) ;
V_167:
F_114 ( V_16 ) ;
V_166:
F_28 ( V_16 ) ;
V_165:
F_68 ( V_16 ) ;
return V_14 ;
}
static int F_144 ( struct V_141 * V_24 )
{
struct V_15 * V_16 = F_128 ( V_24 ) ;
F_114 ( V_16 ) ;
F_79 ( V_16 ) ;
F_123 ( V_16 ) ;
F_99 ( V_16 ) ;
F_41 ( V_16 ) ;
F_28 ( V_16 ) ;
F_68 ( V_16 ) ;
return 0 ;
}
static int T_8 F_145 ( void )
{
int V_14 ;
V_14 = F_146 ( & V_172 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_147 ( & V_173 ) ;
if ( V_14 < 0 )
goto V_174;
if ( ! V_171 ) {
V_14 = - V_19 ;
goto V_175;
}
return 0 ;
V_175:
F_148 ( & V_173 ) ;
V_174:
F_149 ( & V_172 ) ;
return V_14 ;
}
static void T_9 F_150 ( void )
{
F_148 ( & V_173 ) ;
F_149 ( & V_172 ) ;
}
