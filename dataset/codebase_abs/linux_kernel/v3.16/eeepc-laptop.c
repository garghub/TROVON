static int F_1 ( T_1 V_1 , const char * V_2 , int V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 , ( char * ) V_2 , V_3 ) ;
return ( V_4 == V_5 ? 0 : - 1 ) ;
}
static int F_3 ( T_1 V_1 , const char * V_2 , int * V_3 )
{
T_2 V_4 ;
unsigned long long V_6 ;
V_4 = F_4 ( V_1 , ( char * ) V_2 , NULL , & V_6 ) ;
if ( F_5 ( V_4 ) ) {
* V_3 = - 1 ;
return - 1 ;
} else {
* V_3 = V_6 ;
return 0 ;
}
}
static int F_6 ( struct V_7 * V_8 , int V_9 , int V_10 )
{
const char * V_2 = V_11 [ V_9 ] ;
if ( V_2 == NULL )
return - V_12 ;
if ( ( V_8 -> V_13 & ( 0x1 << V_9 ) ) == 0 )
return - V_12 ;
if ( F_1 ( V_8 -> V_1 , V_2 , V_10 ) )
F_7 ( L_1 , V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 , int V_9 )
{
const char * V_2 = V_14 [ V_9 ] ;
int V_10 ;
if ( V_2 == NULL )
return - V_12 ;
if ( ( V_8 -> V_13 & ( 0x1 << V_9 ) ) == 0 )
return - V_12 ;
if ( F_3 ( V_8 -> V_1 , V_2 , & V_10 ) )
F_7 ( L_2 , V_2 ) ;
return V_10 ;
}
static int F_9 ( struct V_7 * V_8 , int V_9 ,
T_1 * V_1 )
{
const char * V_2 = V_11 [ V_9 ] ;
T_2 V_4 ;
if ( V_2 == NULL )
return - V_12 ;
if ( ( V_8 -> V_13 & ( 0x1 << V_9 ) ) == 0 )
return - V_12 ;
V_4 = F_10 ( V_8 -> V_1 , ( char * ) V_2 ,
V_1 ) ;
if ( V_4 != V_5 ) {
F_7 ( L_3 , V_2 ) ;
return - V_12 ;
}
return 0 ;
}
static int F_11 ( const char * V_15 , unsigned long V_16 , int * V_3 )
{
if ( ! V_16 )
return 0 ;
if ( sscanf ( V_15 , L_4 , V_3 ) != 1 )
return - V_17 ;
return V_16 ;
}
static T_3 F_12 ( struct V_18 * V_19 , int V_9 ,
const char * V_15 , T_4 V_16 )
{
struct V_7 * V_8 = F_13 ( V_19 ) ;
int V_20 , V_10 ;
V_20 = F_11 ( V_15 , V_16 , & V_10 ) ;
if ( V_20 > 0 )
V_10 = F_6 ( V_8 , V_9 , V_10 ) ;
if ( V_10 < 0 )
return - V_21 ;
return V_20 ;
}
static T_3 F_14 ( struct V_18 * V_19 , int V_9 , char * V_15 )
{
struct V_7 * V_8 = F_13 ( V_19 ) ;
int V_10 = F_8 ( V_8 , V_9 ) ;
if ( V_10 < 0 )
return - V_21 ;
return sprintf ( V_15 , L_5 , V_10 ) ;
}
static int F_15 ( struct V_7 * V_8 , struct V_22 * V_23 )
{
V_23 -> V_24 = F_8 ( V_8 , V_25 ) ;
V_23 -> V_26 = ( V_23 -> V_24 >> 8 ) & 0xff ;
V_23 -> V_24 &= 0xff ;
if ( V_23 -> V_24 < 0 || V_23 -> V_26 <= 0 || V_23 -> V_26 > 12 )
return - V_12 ;
return 0 ;
}
static T_3 F_16 ( struct V_18 * V_19 ,
struct V_27 * V_28 ,
char * V_15 )
{
struct V_7 * V_8 = F_13 ( V_19 ) ;
struct V_22 V_23 ;
int V_29 ;
T_3 V_30 = 0 ;
if ( F_15 ( V_8 , & V_23 ) )
return - V_12 ;
for ( V_29 = 0 ; V_29 < V_23 . V_26 ; V_29 ++ )
V_30 += sprintf ( V_15 + V_30 , L_6 , V_29 ) ;
V_30 += sprintf ( V_15 + V_30 , L_7 ) ;
return V_30 ;
}
static T_3 F_17 ( struct V_18 * V_19 ,
struct V_27 * V_28 ,
char * V_15 )
{
struct V_7 * V_8 = F_13 ( V_19 ) ;
struct V_22 V_23 ;
if ( F_15 ( V_8 , & V_23 ) )
return - V_12 ;
return sprintf ( V_15 , L_8 , ( V_23 . V_26 << 8 ) | V_23 . V_24 ) ;
}
static T_3 F_18 ( struct V_18 * V_19 ,
struct V_27 * V_28 ,
const char * V_15 , T_4 V_16 )
{
struct V_7 * V_8 = F_13 ( V_19 ) ;
struct V_22 V_23 ;
int V_20 , V_10 ;
if ( V_8 -> V_31 )
return - V_32 ;
if ( F_15 ( V_8 , & V_23 ) )
return - V_12 ;
V_20 = F_11 ( V_15 , V_16 , & V_10 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( ! V_20 || V_10 < 0 || V_10 >= V_23 . V_26 )
return - V_17 ;
F_6 ( V_8 , V_25 , V_10 ) ;
return V_20 ;
}
static T_3 F_19 ( struct V_18 * V_19 ,
struct V_27 * V_28 ,
char * V_15 )
{
struct V_7 * V_8 = F_13 ( V_19 ) ;
return sprintf ( V_15 , L_5 , V_8 -> V_31 ) ;
}
static T_3 F_20 ( struct V_18 * V_19 ,
struct V_27 * V_28 ,
const char * V_15 , T_4 V_16 )
{
struct V_7 * V_8 = F_13 ( V_19 ) ;
int V_20 , V_10 ;
V_20 = F_11 ( V_15 , V_16 , & V_10 ) ;
if ( V_20 < 0 )
return V_20 ;
switch ( V_10 ) {
case 0 :
if ( V_8 -> V_31 )
F_7 ( L_9
L_10 ) ;
V_8 -> V_31 = false ;
return V_20 ;
case 1 :
return - V_32 ;
default:
return - V_17 ;
}
}
static int F_21 ( struct V_7 * V_8 )
{
int V_6 ;
V_8 -> V_33 = F_22 ( V_34 , - 1 ) ;
if ( ! V_8 -> V_33 )
return - V_35 ;
F_23 ( V_8 -> V_33 , V_8 ) ;
V_6 = F_24 ( V_8 -> V_33 ) ;
if ( V_6 )
goto V_36;
V_6 = F_25 ( & V_8 -> V_33 -> V_19 . V_37 ,
& V_38 ) ;
if ( V_6 )
goto V_39;
return 0 ;
V_39:
F_26 ( V_8 -> V_33 ) ;
V_36:
F_27 ( V_8 -> V_33 ) ;
return V_6 ;
}
static void F_28 ( struct V_7 * V_8 )
{
F_29 ( & V_8 -> V_33 -> V_19 . V_37 ,
& V_38 ) ;
F_30 ( V_8 -> V_33 ) ;
}
static void F_31 ( struct V_40 * V_41 )
{
struct V_7 * V_8 ;
V_8 = F_32 ( V_41 , struct V_7 , V_42 ) ;
F_6 ( V_8 , V_43 , V_8 -> V_44 ) ;
}
static void F_33 ( struct V_45 * V_46 ,
enum V_47 V_10 )
{
struct V_7 * V_8 ;
V_8 = F_32 ( V_46 , struct V_7 , V_48 ) ;
V_8 -> V_44 = ( V_10 > 0 ) ? 1 : 0 ;
F_34 ( V_8 -> V_49 , & V_8 -> V_42 ) ;
}
static enum V_47 F_35 ( struct V_45 * V_46 )
{
struct V_7 * V_8 ;
V_8 = F_32 ( V_46 , struct V_7 , V_48 ) ;
return F_8 ( V_8 , V_43 ) ;
}
static int F_36 ( struct V_7 * V_8 )
{
int V_20 ;
if ( F_8 ( V_8 , V_43 ) == - V_12 )
return 0 ;
V_8 -> V_49 = F_37 ( L_11 ) ;
if ( ! V_8 -> V_49 )
return - V_35 ;
F_38 ( & V_8 -> V_42 , F_31 ) ;
V_8 -> V_48 . V_50 = L_12 ;
V_8 -> V_48 . V_51 = F_33 ;
if ( F_8 ( V_8 , V_43 ) >= 0 )
V_8 -> V_48 . V_52 = F_35 ;
V_8 -> V_48 . V_53 = 1 ;
V_20 = F_39 ( & V_8 -> V_33 -> V_19 ,
& V_8 -> V_48 ) ;
if ( V_20 ) {
F_40 ( V_8 -> V_49 ) ;
return V_20 ;
}
return 0 ;
}
static void F_41 ( struct V_7 * V_8 )
{
if ( ! F_42 ( V_8 -> V_48 . V_19 ) )
F_43 ( & V_8 -> V_48 ) ;
if ( V_8 -> V_49 )
F_40 ( V_8 -> V_49 ) ;
}
static bool F_44 ( struct V_7 * V_8 )
{
if ( F_8 ( V_8 , V_54 ) == 1 )
return false ;
return true ;
}
static void F_45 ( struct V_7 * V_8 , T_1 V_1 )
{
struct V_55 * V_56 ;
struct V_55 * V_19 ;
struct V_57 * V_58 ;
bool V_59 = F_44 ( V_8 ) ;
bool V_60 ;
T_5 V_61 ;
if ( V_8 -> V_62 )
F_46 ( V_8 -> V_62 , V_59 ) ;
F_47 ( & V_8 -> V_63 ) ;
F_48 () ;
if ( V_8 -> V_64 ) {
V_56 = F_49 ( V_1 ) ;
if ( ! V_56 ) {
F_50 ( L_13 ) ;
goto V_65;
}
V_58 = V_56 -> V_66 ;
if ( ! V_58 ) {
F_7 ( L_14 ) ;
goto V_67;
}
if ( F_51 ( V_58 , 0 , V_68 , & V_61 ) ) {
F_52 ( L_15 ) ;
goto V_67;
}
V_60 = ( V_61 == 0xffffffff ) ;
if ( V_59 != V_60 ) {
F_7 ( L_16
L_17 ,
V_59 ? L_18 : L_19 ,
V_60 ? L_20 : L_21 ) ;
F_7 ( L_22
L_23 ) ;
goto V_67;
}
if ( ! V_59 ) {
V_19 = F_53 ( V_58 , 0 ) ;
if ( V_19 ) {
F_54 ( V_19 ) ;
goto V_67;
}
V_19 = F_55 ( V_58 , 0 ) ;
if ( V_19 ) {
F_56 ( V_58 ) ;
F_57 ( V_19 ) ;
}
} else {
V_19 = F_53 ( V_58 , 0 ) ;
if ( V_19 ) {
F_58 ( V_19 ) ;
F_54 ( V_19 ) ;
}
}
V_67:
F_54 ( V_56 ) ;
}
V_65:
F_59 () ;
F_60 ( & V_8 -> V_63 ) ;
}
static void F_61 ( struct V_7 * V_8 , char * V_69 )
{
T_2 V_4 = V_5 ;
T_1 V_1 ;
V_4 = F_10 ( NULL , V_69 , & V_1 ) ;
if ( F_62 ( V_4 ) )
F_45 ( V_8 , V_1 ) ;
}
static void F_63 ( T_1 V_1 , T_5 V_70 , void * V_71 )
{
struct V_7 * V_8 = V_71 ;
if ( V_70 != V_72 )
return;
F_45 ( V_8 , V_1 ) ;
}
static int F_64 ( struct V_7 * V_8 ,
char * V_69 )
{
T_2 V_4 ;
T_1 V_1 ;
V_4 = F_10 ( NULL , V_69 , & V_1 ) ;
if ( F_62 ( V_4 ) ) {
V_4 = F_65 ( V_1 ,
V_73 ,
F_63 ,
V_8 ) ;
if ( F_5 ( V_4 ) )
F_7 ( L_24 , V_69 ) ;
F_45 ( V_8 , V_1 ) ;
} else
return - V_12 ;
return 0 ;
}
static void F_66 ( struct V_7 * V_8 ,
char * V_69 )
{
T_2 V_4 = V_5 ;
T_1 V_1 ;
V_4 = F_10 ( NULL , V_69 , & V_1 ) ;
if ( F_62 ( V_4 ) ) {
V_4 = F_67 ( V_1 ,
V_73 ,
F_63 ) ;
if ( F_5 ( V_4 ) )
F_52 ( L_25 ,
V_69 ) ;
F_45 ( V_8 , V_1 ) ;
}
}
static int F_68 ( struct V_64 * V_64 ,
T_6 * V_10 )
{
struct V_7 * V_8 = V_64 -> V_74 ;
int V_3 = F_8 ( V_8 , V_54 ) ;
if ( V_3 == 1 || V_3 == 0 )
* V_10 = V_3 ;
else
return - V_17 ;
return 0 ;
}
static void F_69 ( struct V_64 * V_64 )
{
F_70 ( V_64 -> V_75 ) ;
F_70 ( V_64 ) ;
}
static int F_71 ( struct V_7 * V_8 )
{
int V_76 = - V_35 ;
struct V_57 * V_58 = F_72 ( 0 , 1 ) ;
if ( ! V_58 ) {
F_52 ( L_26 ) ;
return - V_12 ;
}
V_8 -> V_64 = F_73 ( sizeof( struct V_64 ) , V_77 ) ;
if ( ! V_8 -> V_64 )
goto V_78;
V_8 -> V_64 -> V_75 = F_73 ( sizeof( struct V_79 ) ,
V_77 ) ;
if ( ! V_8 -> V_64 -> V_75 )
goto V_80;
V_8 -> V_64 -> V_74 = V_8 ;
V_8 -> V_64 -> V_81 = & F_69 ;
V_8 -> V_64 -> V_82 = & V_83 ;
F_68 ( V_8 -> V_64 ,
& V_8 -> V_64 -> V_75 -> V_84 ) ;
V_76 = F_74 ( V_8 -> V_64 , V_58 , 0 , L_27 ) ;
if ( V_76 ) {
F_52 ( L_28 , V_76 ) ;
goto V_85;
}
return 0 ;
V_85:
F_70 ( V_8 -> V_64 -> V_75 ) ;
V_80:
F_70 ( V_8 -> V_64 ) ;
V_8 -> V_64 = NULL ;
V_78:
return V_76 ;
}
static int F_75 ( void * V_71 , bool V_59 )
{
T_1 V_1 = V_71 ;
return F_1 ( V_1 , NULL , ! V_59 ) ;
}
static int F_76 ( struct V_7 * V_8 ,
struct V_86 * * V_86 ,
const char * V_50 ,
enum V_87 type , int V_9 )
{
T_1 V_1 ;
int V_6 ;
V_6 = F_9 ( V_8 , V_9 , & V_1 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_86 = F_77 ( V_50 , & V_8 -> V_33 -> V_19 , type ,
& V_88 , V_1 ) ;
if ( ! * V_86 )
return - V_17 ;
F_78 ( * V_86 , F_8 ( V_8 , V_9 ) != 1 ) ;
V_6 = F_79 ( * V_86 ) ;
if ( V_6 ) {
F_80 ( * V_86 ) ;
* V_86 = NULL ;
return V_6 ;
}
return 0 ;
}
static void F_81 ( struct V_7 * V_8 )
{
F_66 ( V_8 , L_29 ) ;
F_66 ( V_8 , L_30 ) ;
F_66 ( V_8 , L_31 ) ;
if ( V_8 -> V_62 ) {
F_82 ( V_8 -> V_62 ) ;
F_80 ( V_8 -> V_62 ) ;
V_8 -> V_62 = NULL ;
}
if ( V_8 -> V_64 )
F_83 ( V_8 -> V_64 ) ;
if ( V_8 -> V_89 ) {
F_82 ( V_8 -> V_89 ) ;
F_80 ( V_8 -> V_89 ) ;
V_8 -> V_89 = NULL ;
}
if ( V_8 -> V_90 ) {
F_82 ( V_8 -> V_90 ) ;
F_80 ( V_8 -> V_90 ) ;
V_8 -> V_90 = NULL ;
}
if ( V_8 -> V_91 ) {
F_82 ( V_8 -> V_91 ) ;
F_80 ( V_8 -> V_91 ) ;
V_8 -> V_91 = NULL ;
}
}
static int F_84 ( struct V_7 * V_8 )
{
int V_6 = 0 ;
F_85 ( & V_8 -> V_63 ) ;
V_6 = F_76 ( V_8 , & V_8 -> V_62 ,
L_32 , V_92 ,
V_54 ) ;
if ( V_6 && V_6 != - V_12 )
goto exit;
V_6 = F_76 ( V_8 , & V_8 -> V_89 ,
L_33 , V_93 ,
V_94 ) ;
if ( V_6 && V_6 != - V_12 )
goto exit;
V_6 = F_76 ( V_8 , & V_8 -> V_90 ,
L_34 , V_95 ,
V_96 ) ;
if ( V_6 && V_6 != - V_12 )
goto exit;
V_6 = F_76 ( V_8 , & V_8 -> V_91 ,
L_35 , V_97 ,
V_98 ) ;
if ( V_6 && V_6 != - V_12 )
goto exit;
if ( V_8 -> V_99 )
return 0 ;
V_6 = F_71 ( V_8 ) ;
if ( V_6 == - V_100 )
V_6 = 0 ;
F_64 ( V_8 , L_29 ) ;
F_64 ( V_8 , L_30 ) ;
F_64 ( V_8 , L_31 ) ;
exit:
if ( V_6 && V_6 != - V_12 )
F_81 ( V_8 ) ;
return V_6 ;
}
static int F_86 ( struct V_18 * V_18 )
{
struct V_7 * V_8 = F_13 ( V_18 ) ;
if ( V_8 -> V_62 ) {
bool V_101 ;
V_101 = F_8 ( V_8 , V_54 ) ;
F_6 ( V_8 , V_54 , V_101 ) ;
}
return 0 ;
}
static int F_87 ( struct V_18 * V_18 )
{
struct V_7 * V_8 = F_13 ( V_18 ) ;
if ( V_8 -> V_62 ) {
F_61 ( V_8 , L_29 ) ;
F_61 ( V_8 , L_30 ) ;
F_61 ( V_8 , L_31 ) ;
}
if ( V_8 -> V_89 )
F_46 ( V_8 -> V_89 ,
F_8 ( V_8 , V_94 ) != 1 ) ;
if ( V_8 -> V_90 )
F_46 ( V_8 -> V_90 ,
F_8 ( V_8 , V_96 ) != 1 ) ;
if ( V_8 -> V_91 )
F_46 ( V_8 -> V_91 ,
F_8 ( V_8 , V_98 ) != 1 ) ;
return 0 ;
}
static int F_88 ( void )
{
T_6 V_10 = 0 ;
F_89 ( V_102 , & V_10 ) ;
return V_10 * 255 / 100 ;
}
static void F_90 ( int V_10 )
{
V_10 = F_91 ( V_10 , 0 , 255 ) ;
V_10 = V_10 * 100 / 255 ;
F_92 ( V_102 , V_10 ) ;
}
static int F_93 ( void )
{
T_6 V_103 = 0 ;
T_6 V_104 = 0 ;
F_89 ( V_105 , & V_103 ) ;
F_89 ( V_106 , & V_104 ) ;
return V_103 << 8 | V_104 ;
}
static int F_94 ( void )
{
T_6 V_10 = 0 ;
F_89 ( V_107 , & V_10 ) ;
if ( V_10 & 0x02 )
return 1 ;
else
return 2 ;
}
static void F_95 ( int V_108 )
{
T_6 V_10 = 0 ;
F_89 ( V_107 , & V_10 ) ;
if ( V_108 == 1 )
V_10 |= 0x02 ;
else
V_10 &= ~ 0x02 ;
F_92 ( V_107 , V_10 ) ;
}
static T_3 F_96 ( void (* F_97)( int ) , const char * V_15 , T_4 V_16 )
{
int V_20 , V_10 ;
V_20 = F_11 ( V_15 , V_16 , & V_10 ) ;
if ( V_20 > 0 )
F_97 ( V_10 ) ;
return V_20 ;
}
static T_3 F_98 ( int (* F_99)( void ) , char * V_15 )
{
return sprintf ( V_15 , L_5 , F_99 () ) ;
}
static int F_100 ( struct V_7 * V_8 )
{
struct V_18 * V_19 = & V_8 -> V_33 -> V_19 ;
struct V_18 * V_109 ;
V_109 = F_101 ( V_19 , L_36 , NULL ,
V_110 ) ;
if ( F_102 ( V_109 ) ) {
F_52 ( L_37 ) ;
return F_103 ( V_109 ) ;
}
return 0 ;
}
static int F_104 ( struct V_111 * V_112 )
{
struct V_7 * V_8 = F_105 ( V_112 ) ;
return F_8 ( V_8 , V_113 ) ;
}
static int F_106 ( struct V_111 * V_112 , int V_10 )
{
struct V_7 * V_8 = F_105 ( V_112 ) ;
return F_6 ( V_8 , V_113 , V_10 ) ;
}
static int F_107 ( struct V_111 * V_112 )
{
return F_106 ( V_112 , V_112 -> V_114 . V_115 ) ;
}
static int F_108 ( struct V_7 * V_8 )
{
struct V_111 * V_112 = V_8 -> V_111 ;
int V_116 = V_112 -> V_114 . V_115 ;
F_109 ( V_112 , V_117 ) ;
return V_116 ;
}
static int F_110 ( struct V_7 * V_8 )
{
struct V_118 V_114 ;
struct V_111 * V_112 ;
memset ( & V_114 , 0 , sizeof( struct V_118 ) ) ;
V_114 . type = V_119 ;
V_114 . V_53 = 15 ;
V_112 = F_111 ( V_34 ,
& V_8 -> V_33 -> V_19 , V_8 ,
& V_120 , & V_114 ) ;
if ( F_102 ( V_112 ) ) {
F_52 ( L_38 ) ;
V_8 -> V_111 = NULL ;
return F_103 ( V_112 ) ;
}
V_8 -> V_111 = V_112 ;
V_112 -> V_114 . V_115 = F_104 ( V_112 ) ;
V_112 -> V_114 . V_121 = V_122 ;
F_112 ( V_112 ) ;
return 0 ;
}
static void F_113 ( struct V_7 * V_8 )
{
if ( V_8 -> V_111 )
F_114 ( V_8 -> V_111 ) ;
V_8 -> V_111 = NULL ;
}
static int F_115 ( struct V_7 * V_8 )
{
struct V_123 * V_124 ;
int error ;
V_124 = F_116 () ;
if ( ! V_124 )
return - V_35 ;
V_124 -> V_50 = L_39 ;
V_124 -> V_125 = V_34 L_40 ;
V_124 -> V_126 . V_127 = V_128 ;
V_124 -> V_19 . V_129 = & V_8 -> V_33 -> V_19 ;
error = F_117 ( V_124 , V_130 , NULL ) ;
if ( error ) {
F_52 ( L_41 ) ;
goto V_131;
}
error = F_118 ( V_124 ) ;
if ( error ) {
F_52 ( L_42 ) ;
goto V_132;
}
V_8 -> V_133 = V_124 ;
return 0 ;
V_132:
F_119 ( V_124 ) ;
V_131:
F_120 ( V_124 ) ;
return error ;
}
static void F_121 ( struct V_7 * V_8 )
{
if ( V_8 -> V_133 ) {
F_119 ( V_8 -> V_133 ) ;
F_122 ( V_8 -> V_133 ) ;
}
V_8 -> V_133 = NULL ;
}
static void F_123 ( struct V_7 * V_8 , int V_70 )
{
if ( ! V_8 -> V_133 )
return ;
if ( ! F_124 ( V_8 -> V_133 , V_70 , 1 , true ) )
F_125 ( L_43 , V_70 ) ;
}
static void F_126 ( struct V_134 * V_18 , T_5 V_70 )
{
struct V_7 * V_8 = F_127 ( V_18 ) ;
T_7 V_16 ;
if ( V_70 > V_135 )
return;
V_16 = V_8 -> V_136 [ V_70 % 128 ] ++ ;
F_128 ( V_18 -> V_137 . V_138 ,
F_129 ( & V_18 -> V_19 ) , V_70 ,
V_16 ) ;
if ( V_70 >= V_139 && V_70 <= V_140 ) {
if ( V_8 -> V_111 != NULL ) {
int V_141 , V_142 ;
V_141 = F_108 ( V_8 ) ;
V_142 = V_70 - V_139 ;
if ( V_142 < V_141 ) {
V_70 = V_139 ;
} else if ( V_142 > V_141 ) {
V_70 = V_140 ;
} else {
}
F_123 ( V_8 , V_70 ) ;
}
} else {
F_123 ( V_8 , V_70 ) ;
}
}
static void F_130 ( struct V_7 * V_8 )
{
const char * V_143 ;
V_143 = F_131 ( V_144 ) ;
if ( ! V_143 )
return;
if ( strcmp ( V_143 , L_44 ) == 0 || strcmp ( V_143 , L_45 ) == 0 ) {
V_8 -> V_31 = true ;
F_125 ( L_46
L_47 , V_143 ) ;
F_125 ( L_48 ) ;
}
if ( strcmp ( V_143 , L_49 ) == 0 || strcmp ( V_143 , L_50 ) == 0 ||
strcmp ( V_143 , L_51 ) == 0 ) {
V_8 -> V_99 = true ;
F_125 ( L_52 ) ;
}
}
static void F_132 ( struct V_7 * V_8 , int V_9 , const char * V_50 )
{
int V_145 ;
if ( ! ( V_8 -> V_13 & ( 1 << V_9 ) )
&& ! F_3 ( V_8 -> V_1 , V_14 [ V_9 ] , & V_145 ) ) {
F_125 ( L_53
L_54 , V_50 , 1 << V_9 ) ;
V_8 -> V_13 |= 1 << V_9 ;
}
}
static void F_133 ( struct V_7 * V_8 )
{
F_132 ( V_8 , V_146 , L_55 ) ;
F_132 ( V_8 , V_147 , L_56 ) ;
F_132 ( V_8 , V_148 , L_57 ) ;
F_132 ( V_8 , V_43 , L_58 ) ;
}
static int F_134 ( struct V_7 * V_8 )
{
unsigned int V_149 ;
int V_6 ;
V_6 = F_135 ( V_8 -> V_18 ) ;
if ( V_6 )
return V_6 ;
if ( ! V_8 -> V_18 -> V_4 . V_150 ) {
F_52 ( L_59 ) ;
return - V_12 ;
}
V_149 = V_151 | V_152 ;
F_136 ( L_60 , V_149 ) ;
if ( F_1 ( V_8 -> V_1 , L_61 , V_149 ) ) {
F_52 ( L_62 ) ;
return - V_12 ;
}
if ( F_3 ( V_8 -> V_1 , L_63 , & V_8 -> V_13 ) ) {
F_52 ( L_64 ) ;
return - V_12 ;
}
F_133 ( V_8 ) ;
F_125 ( L_65 , V_8 -> V_13 ) ;
return 0 ;
}
static void F_137 ( struct V_7 * V_8 )
{
if ( F_8 ( V_8 , V_153 ) == 0 )
F_6 ( V_8 , V_153 , 1 ) ;
}
static int F_138 ( struct V_134 * V_18 )
{
struct V_7 * V_8 ;
int V_6 ;
F_136 ( V_154 L_7 ) ;
V_8 = F_73 ( sizeof( struct V_7 ) , V_77 ) ;
if ( ! V_8 )
return - V_35 ;
V_8 -> V_1 = V_18 -> V_1 ;
strcpy ( F_139 ( V_18 ) , V_155 ) ;
strcpy ( F_140 ( V_18 ) , V_156 ) ;
V_18 -> V_157 = V_8 ;
V_8 -> V_18 = V_18 ;
V_8 -> V_99 = V_99 ;
F_130 ( V_8 ) ;
V_6 = F_134 ( V_8 ) ;
if ( V_6 )
goto V_158;
F_137 ( V_8 ) ;
V_6 = F_21 ( V_8 ) ;
if ( V_6 )
goto V_158;
if ( ! F_141 () ) {
V_6 = F_110 ( V_8 ) ;
if ( V_6 )
goto V_159;
} else
F_125 ( L_66 ) ;
V_6 = F_115 ( V_8 ) ;
if ( V_6 )
goto V_160;
V_6 = F_100 ( V_8 ) ;
if ( V_6 )
goto V_161;
V_6 = F_36 ( V_8 ) ;
if ( V_6 )
goto V_162;
V_6 = F_84 ( V_8 ) ;
if ( V_6 )
goto V_163;
V_164 = true ;
return 0 ;
V_163:
F_41 ( V_8 ) ;
V_162:
V_161:
F_121 ( V_8 ) ;
V_160:
F_113 ( V_8 ) ;
V_159:
F_28 ( V_8 ) ;
V_158:
F_70 ( V_8 ) ;
return V_6 ;
}
static int F_142 ( struct V_134 * V_18 )
{
struct V_7 * V_8 = F_127 ( V_18 ) ;
F_113 ( V_8 ) ;
F_81 ( V_8 ) ;
F_121 ( V_8 ) ;
F_41 ( V_8 ) ;
F_28 ( V_8 ) ;
F_70 ( V_8 ) ;
return 0 ;
}
static int T_8 F_143 ( void )
{
int V_6 ;
V_6 = F_144 ( & V_165 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_145 ( & V_166 ) ;
if ( V_6 < 0 )
goto V_167;
if ( ! V_164 ) {
V_6 = - V_12 ;
goto V_168;
}
return 0 ;
V_168:
F_146 ( & V_166 ) ;
V_167:
F_147 ( & V_165 ) ;
return V_6 ;
}
static void T_9 F_148 ( void )
{
F_146 ( & V_166 ) ;
F_147 ( & V_165 ) ;
}
