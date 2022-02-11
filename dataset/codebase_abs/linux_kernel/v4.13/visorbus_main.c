static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
T_2 V_8 ;
V_7 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_7 -> V_9 ) ;
return sprintf ( V_5 , L_1 , & V_8 ) ;
}
static int
F_4 ( struct V_1 * V_10 , struct V_11 * V_12 )
{
struct V_6 * V_2 ;
T_2 V_8 ;
V_2 = F_2 ( V_10 ) ;
V_8 = F_3 ( V_2 -> V_9 ) ;
return F_5 ( V_12 , L_2 , & V_8 ) ;
}
static int
F_6 ( struct V_1 * V_10 , struct V_13 * V_14 )
{
T_2 V_15 ;
int V_16 ;
struct V_6 * V_2 ;
struct V_17 * V_18 ;
V_2 = F_2 ( V_10 ) ;
V_18 = F_7 ( V_14 ) ;
V_15 = F_3 ( V_2 -> V_9 ) ;
if ( ! V_18 -> V_19 )
return 0 ;
for ( V_16 = 0 ;
( F_8 ( V_18 -> V_19 [ V_16 ] . V_8 , V_20 ) != 0 ) ||
( V_18 -> V_19 [ V_16 ] . V_21 ) ;
V_16 ++ )
if ( F_8 ( V_18 -> V_19 [ V_16 ] . V_8 ,
V_15 ) == 0 )
return V_16 + 1 ;
return 0 ;
}
static void
F_9 ( struct V_1 * V_10 )
{
struct V_6 * V_2 = F_10 ( V_10 ) ;
F_11 ( V_2 -> V_22 ) ;
F_12 ( V_2 -> V_23 ) ;
F_13 ( V_2 ) ;
}
static void
F_14 ( struct V_1 * V_10 )
{
struct V_6 * V_2 = F_2 ( V_10 ) ;
if ( V_2 -> V_9 ) {
F_15 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
F_13 ( V_2 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_3 ,
F_17 ( V_7 -> V_9 ) ) ;
}
static T_1 F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_4 ,
F_19 ( V_7 -> V_9 ) ) ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_3 ,
F_21 ( V_7 -> V_9 ) ) ;
}
static T_1 F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char V_24 [ V_25 ] ;
return sprintf ( V_5 , L_5 ,
F_23 ( V_7 -> V_9 , V_24 ) ) ;
}
static T_1 F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char V_26 [ V_25 ] ;
return sprintf ( V_5 , L_5 ,
F_25 ( V_7 -> V_9 , V_26 ) ) ;
}
static T_1 F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_16 = 0 ;
struct V_27 * V_28 = V_2 -> V_29 ;
struct V_13 * V_14 = V_2 -> V_30 ;
struct V_17 * V_18 = NULL ;
if ( ! V_28 || ! V_14 )
return 0 ;
V_16 = V_28 -> V_31 ( V_2 , V_14 ) ;
if ( ! V_16 )
return 0 ;
V_18 = F_7 ( V_14 ) ;
return sprintf ( V_5 , L_5 , V_18 -> V_19 [ V_16 - 1 ] . V_21 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_32 = F_21 ( V_7 -> V_9 ) ;
return sprintf ( V_5 , L_3 , V_32 ) ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_6 , & V_7 -> V_33 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_5 , V_7 -> V_21 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_34 = F_17 ( V_7 -> V_9 ) ;
return sprintf ( V_5 , L_3 , V_34 ) ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_35 = F_19 ( V_7 -> V_9 ) ;
return sprintf ( V_5 , L_3 , V_35 ) ;
}
static T_1 F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_36 = 0 ;
F_23 ( V_7 -> V_9 , V_5 ) ;
V_36 = strlen ( V_5 ) ;
V_5 [ V_36 ++ ] = '\n' ;
return V_36 ;
}
static void
F_33 ( struct V_37 * V_38 ,
struct V_39 * V_40 , int V_41 )
{
if ( ! isprint ( V_38 -> V_42 [ 0 ] ) )
return;
if ( V_41 >= 0 )
F_34 ( V_40 , L_7 , V_41 ) ;
else
F_35 ( V_40 , L_8 ) ;
F_34 ( V_40 , L_9 , ( int ) sizeof( V_38 -> V_42 ) ,
( int ) sizeof( V_38 -> V_42 ) , V_38 -> V_42 ) ;
F_34 ( V_40 , L_9 , ( int ) sizeof( V_38 -> V_43 ) ,
( int ) sizeof( V_38 -> V_43 ) , V_38 -> V_43 ) ;
F_34 ( V_40 , L_10 , ( int ) sizeof( V_38 -> V_44 ) ,
V_38 -> V_44 ) ;
}
static int F_36 ( struct V_39 * V_40 , void * V_45 )
{
struct V_6 * V_7 = V_40 -> V_46 ;
struct V_9 * V_47 = V_7 -> V_9 ;
int V_16 ;
unsigned long V_48 ;
struct V_37 V_49 ;
if ( ! V_47 )
return 0 ;
F_34 ( V_40 ,
L_11 ,
( ( V_7 -> V_21 ) ? ( char * ) ( V_7 -> V_21 ) : L_12 ) ,
V_7 -> V_50 ) ;
if ( F_37 ( V_47 ,
F_38 ( struct V_51 , V_52 ) ,
& V_49 , sizeof( V_49 ) ) >= 0 )
F_33 ( & V_49 , V_40 , - 1 ) ;
if ( F_37 ( V_47 ,
F_38 ( struct V_51 , V_53 ) ,
& V_49 , sizeof( V_49 ) ) >= 0 )
F_33 ( & V_49 , V_40 , - 1 ) ;
V_48 = F_38 ( struct V_51 , V_49 ) ;
V_16 = 0 ;
while ( V_48 + sizeof( V_49 ) <= F_19 ( V_47 ) ) {
if ( F_37 ( V_47 , V_48 , & V_49 ,
sizeof( V_49 ) ) >= 0 )
F_33 ( & V_49 , V_40 , V_16 ) ;
V_48 += sizeof( V_49 ) ;
V_16 ++ ;
}
return 0 ;
}
static int F_39 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_40 ( V_55 , F_36 ,
V_54 -> V_56 ) ;
}
static void
F_41 ( unsigned long V_57 )
{
struct V_6 * V_2 = (struct V_6 * ) V_57 ;
struct V_17 * V_18 = F_7 ( V_2 -> V_1 . V_30 ) ;
V_18 -> V_58 ( V_2 ) ;
F_42 ( & V_2 -> V_59 , V_60 + V_61 ) ;
}
static int
F_43 ( struct V_6 * V_2 )
{
if ( V_2 -> V_62 || V_2 -> V_63 )
return - V_64 ;
F_44 ( & V_2 -> V_1 ) ;
V_2 -> V_59 . V_65 = V_60 + V_61 ;
F_45 ( & V_2 -> V_59 ) ;
V_2 -> V_63 = true ;
return 0 ;
}
static void
F_46 ( struct V_6 * V_2 )
{
if ( ! V_2 -> V_63 )
return;
F_47 ( & V_2 -> V_59 ) ;
V_2 -> V_63 = false ;
F_48 ( & V_2 -> V_1 ) ;
}
static int
F_49 ( struct V_1 * V_10 )
{
struct V_6 * V_2 ;
struct V_17 * V_18 ;
V_2 = F_2 ( V_10 ) ;
V_18 = F_7 ( V_10 -> V_30 ) ;
F_50 ( & V_2 -> V_66 ) ;
V_2 -> V_62 = true ;
if ( V_18 -> remove )
V_18 -> remove ( V_2 ) ;
F_51 ( & V_2 -> V_66 ) ;
F_46 ( V_2 ) ;
F_48 ( & V_2 -> V_1 ) ;
return 0 ;
}
void
F_52 ( struct V_17 * V_18 )
{
F_53 ( & V_18 -> V_30 ) ;
}
int
F_54 ( struct V_6 * V_2 , unsigned long V_67 ,
void * V_68 , unsigned long V_35 )
{
return F_37 ( V_2 -> V_9 , V_67 , V_68 , V_35 ) ;
}
int
F_55 ( struct V_6 * V_2 , unsigned long V_67 ,
void * V_69 , unsigned long V_35 )
{
return F_56 ( V_2 -> V_9 , V_67 , V_69 , V_35 ) ;
}
int
F_57 ( struct V_6 * V_2 )
{
struct V_17 * V_18 = F_7 ( V_2 -> V_1 . V_30 ) ;
if ( ! V_18 -> V_58 ) {
F_58 ( & V_2 -> V_1 , L_13 , V_70 ) ;
return - V_71 ;
}
return F_43 ( V_2 ) ;
}
void
F_59 ( struct V_6 * V_2 )
{
F_46 ( V_2 ) ;
}
static int
F_60 ( struct V_6 * V_2 )
{
int V_72 ;
T_4 V_50 = V_2 -> V_50 ;
T_4 V_73 = V_2 -> V_73 ;
F_61 ( & V_2 -> V_66 ) ;
V_2 -> V_1 . V_29 = & V_74 ;
V_2 -> V_1 . V_75 = V_76 ;
F_62 ( & V_2 -> V_1 ) ;
V_2 -> V_1 . V_77 = F_14 ;
F_44 ( & V_2 -> V_1 ) ;
F_63 ( & V_2 -> V_59 , F_41 , ( unsigned long ) V_2 ) ;
V_72 = F_64 ( & V_2 -> V_1 , L_14 ,
V_50 , V_73 ) ;
if ( V_72 )
goto V_78;
V_72 = F_65 ( & V_2 -> V_1 ) ;
if ( V_72 < 0 )
goto V_78;
F_66 ( & V_2 -> V_79 , & V_80 ) ;
return 0 ;
V_78:
F_48 ( & V_2 -> V_1 ) ;
F_58 ( & V_2 -> V_1 , L_15 , V_72 ) ;
return V_72 ;
}
static void
F_67 ( struct V_6 * V_2 )
{
F_68 ( & V_2 -> V_79 ) ;
F_48 ( & V_2 -> V_1 ) ;
F_69 ( & V_2 -> V_1 ) ;
}
static int
F_70 ( struct V_9 * V_81 ,
struct V_82 * V_83 )
{
int V_72 ;
if ( ! F_71 ( F_72 ( V_81 ) ,
V_84 ,
L_16 ,
sizeof( struct V_51 ) ,
V_85 ,
V_86 ) )
return - V_64 ;
V_72 = F_37 ( V_81 , sizeof( struct V_87 ) , V_83 ,
sizeof( * V_83 ) ) ;
if ( V_72 < 0 )
return V_72 ;
if ( V_83 -> V_88 < sizeof( struct V_82 ) )
return - V_64 ;
if ( V_83 -> V_89 <
sizeof( struct V_37 ) )
return - V_64 ;
return 0 ;
}
static void
F_73 ( struct V_9 * V_81 ,
struct V_82 * V_83 ,
struct V_37 * V_90 )
{
int V_48 = sizeof( struct V_87 ) + V_83 -> V_91 ;
if ( V_83 -> V_91 == 0 )
return;
F_56 ( V_81 , V_48 , V_90 , sizeof( * V_90 ) ) ;
}
static void
F_74 ( struct V_9 * V_81 ,
struct V_82 * V_83 ,
struct V_37 * V_90 )
{
int V_48 = sizeof( struct V_87 ) + V_83 -> V_92 ;
if ( V_83 -> V_92 == 0 )
return;
F_56 ( V_81 , V_48 , V_90 , sizeof( * V_90 ) ) ;
}
static void
F_75 ( struct V_9 * V_81 ,
struct V_82 * V_83 ,
struct V_37 * V_90 , unsigned int V_41 )
{
int V_48 =
( sizeof( struct V_87 ) + V_83 -> V_93 ) +
( V_83 -> V_89 * V_41 ) ;
if ( V_83 -> V_93 == 0 )
return;
F_56 ( V_81 , V_48 , V_90 , sizeof( * V_90 ) ) ;
}
static void F_76 (
struct V_37 * V_94 ,
const char * V_95 , const char * V_96 )
{
memset ( V_94 , 0 , sizeof( struct V_37 ) ) ;
snprintf ( V_94 -> V_42 ,
sizeof( V_94 -> V_42 ) ,
L_17 , ( V_95 ) ? V_95 : L_18 ) ;
snprintf ( V_94 -> V_43 ,
sizeof( V_94 -> V_43 ) ,
L_17 , ( V_96 ) ? V_96 : L_19 ) ;
snprintf ( V_94 -> V_44 ,
sizeof( V_94 -> V_44 ) , L_20 ,
F_77 () -> V_77 ) ;
}
static void
F_78 ( struct V_6 * V_97 )
{
int V_16 ;
struct V_6 * V_98 ;
struct V_17 * V_99 ;
T_4 V_100 = V_97 -> V_50 ;
T_4 V_101 = V_97 -> V_73 ;
struct V_37 V_49 ;
const char * V_102 = NULL ;
struct V_82 * V_83 ;
if ( ! V_97 -> V_1 . V_30 )
return;
V_98 = F_79 ( V_100 , V_103 , NULL ) ;
if ( ! V_98 )
return;
V_83 = (struct V_82 * ) V_98 -> V_104 ;
if ( ! V_83 )
return;
V_99 = F_7 ( V_97 -> V_1 . V_30 ) ;
for ( V_16 = 0 ; V_99 -> V_19 [ V_16 ] . V_21 ; V_16 ++ ) {
if ( memcmp ( & V_99 -> V_19 [ V_16 ] . V_8 ,
& V_97 -> V_105 ,
sizeof( V_99 -> V_19 [ V_16 ] . V_8 ) ) == 0 ) {
V_102 = V_99 -> V_19 [ V_16 ] . V_21 ;
break;
}
}
F_76 ( & V_49 , V_102 , V_99 -> V_21 ) ;
F_75 ( V_98 -> V_9 , V_83 , & V_49 , V_101 ) ;
F_73 ( V_98 -> V_9 , V_83 , & V_106 ) ;
F_74 ( V_98 -> V_9 , V_83 ,
& V_107 ) ;
}
static int
F_80 ( struct V_1 * V_10 )
{
int V_108 ;
struct V_17 * V_18 ;
struct V_6 * V_2 ;
V_18 = F_7 ( V_10 -> V_30 ) ;
V_2 = F_2 ( V_10 ) ;
if ( ! V_18 -> V_109 )
return - V_110 ;
F_50 ( & V_2 -> V_66 ) ;
V_2 -> V_62 = false ;
V_108 = V_18 -> V_109 ( V_2 ) ;
if ( V_108 >= 0 ) {
F_44 ( & V_2 -> V_1 ) ;
F_78 ( V_2 ) ;
}
F_51 ( & V_2 -> V_66 ) ;
return V_108 ;
}
int F_81 ( struct V_17 * V_18 )
{
if ( ! V_111 )
return - V_110 ;
V_18 -> V_30 . V_21 = V_18 -> V_21 ;
V_18 -> V_30 . V_29 = & V_74 ;
V_18 -> V_30 . V_109 = F_80 ;
V_18 -> V_30 . remove = F_49 ;
V_18 -> V_30 . V_112 = V_18 -> V_112 ;
return F_82 ( & V_18 -> V_30 ) ;
}
static int
F_83 ( struct V_6 * V_2 )
{
int V_113 = V_2 -> V_50 ;
int V_72 ;
struct V_82 * V_83 ;
V_83 = F_84 ( sizeof( * V_83 ) , V_114 ) ;
if ( ! V_83 )
return - V_115 ;
F_64 ( & V_2 -> V_1 , L_21 , V_113 ) ;
V_2 -> V_1 . V_29 = & V_74 ;
V_2 -> V_1 . V_75 = V_116 ;
V_2 -> V_1 . V_77 = F_9 ;
V_2 -> V_23 = F_85 ( F_86 ( & V_2 -> V_1 ) ,
V_117 ) ;
V_2 -> V_22 =
F_87 ( L_22 , 0440 ,
V_2 -> V_23 , V_2 ,
& V_118 ) ;
F_88 ( & V_2 -> V_1 , V_2 ) ;
V_72 = F_70 ( V_2 -> V_9 , V_83 ) ;
if ( V_72 < 0 )
goto V_119;
V_72 = F_89 ( & V_2 -> V_1 ) ;
if ( V_72 < 0 )
goto V_119;
F_66 ( & V_2 -> V_79 , & V_120 ) ;
V_2 -> V_104 = ( void * ) V_83 ;
F_73 ( V_2 -> V_9 , V_83 ,
& V_106 ) ;
F_74 ( V_2 -> V_9 , V_83 ,
& V_107 ) ;
return 0 ;
V_119:
F_12 ( V_2 -> V_23 ) ;
F_13 ( V_83 ) ;
F_58 ( & V_2 -> V_1 , L_23 , V_72 ) ;
return V_72 ;
}
static void
F_90 ( struct V_6 * V_2 )
{
if ( V_2 -> V_9 ) {
F_15 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
F_13 ( V_2 -> V_104 ) ;
F_68 ( & V_2 -> V_79 ) ;
F_69 ( & V_2 -> V_1 ) ;
}
static void
F_91 ( void )
{
struct V_121 * V_122 , * V_123 ;
F_92 (listentry, listtmp, &list_all_device_instances) {
struct V_6 * V_2 = F_93 ( V_122 ,
struct V_6 ,
V_79 ) ;
F_67 ( V_2 ) ;
}
}
int
F_94 ( struct V_6 * V_2 )
{
int V_72 ;
V_72 = F_83 ( V_2 ) ;
if ( V_72 < 0 )
return V_72 ;
F_95 ( V_2 , V_72 ) ;
return 0 ;
}
void
F_96 ( struct V_6 * V_2 )
{
F_90 ( V_2 ) ;
F_97 ( V_2 , 0 ) ;
}
int
F_98 ( struct V_6 * V_49 )
{
int V_72 ;
V_72 = F_60 ( V_49 ) ;
if ( V_72 < 0 )
return V_72 ;
F_99 ( V_49 , V_72 ) ;
return 0 ;
}
void
F_100 ( struct V_6 * V_49 )
{
F_67 ( V_49 ) ;
F_101 ( V_49 , 0 ) ;
}
static void
F_102 ( struct V_6 * V_2 , int V_124 )
{
if ( ! V_2 -> V_125 )
return;
V_2 -> V_125 = false ;
F_103 ( V_2 , V_124 ) ;
}
static void
F_104 ( struct V_6 * V_2 , int V_124 )
{
if ( ! V_2 -> V_126 )
return;
V_2 -> V_126 = false ;
F_105 ( V_2 , V_124 ) ;
}
static int
F_106 ( struct V_6 * V_2 ,
bool V_127 )
{
int V_72 ;
struct V_17 * V_18 = NULL ;
V_18 = F_7 ( V_2 -> V_1 . V_30 ) ;
if ( ! V_18 )
return - V_110 ;
if ( V_2 -> V_125 || V_2 -> V_126 )
return - V_128 ;
if ( V_127 ) {
if ( ! V_18 -> V_129 )
return - V_64 ;
V_2 -> V_125 = true ;
V_72 = V_18 -> V_129 ( V_2 , F_102 ) ;
} else {
F_78 ( V_2 ) ;
if ( ! V_18 -> V_130 )
return - V_64 ;
V_2 -> V_126 = true ;
V_72 = V_18 -> V_130 ( V_2 , F_104 ) ;
}
return V_72 ;
}
int
F_107 ( struct V_6 * V_49 )
{
int V_72 ;
V_72 = F_106 ( V_49 , true ) ;
if ( V_72 < 0 ) {
V_49 -> V_125 = false ;
return V_72 ;
}
return 0 ;
}
int
F_108 ( struct V_6 * V_49 )
{
int V_72 ;
V_72 = F_106 ( V_49 , false ) ;
if ( V_72 < 0 ) {
V_49 -> V_126 = false ;
return V_72 ;
}
return 0 ;
}
int
F_109 ( void )
{
int V_72 ;
V_117 = F_85 ( L_24 , NULL ) ;
if ( ! V_117 )
return - V_115 ;
F_76 ( & V_107 , L_25 , L_24 ) ;
V_72 = F_110 ( & V_74 ) ;
if ( V_72 < 0 )
return V_72 ;
V_111 = true ;
F_76 ( & V_106 , L_26 , L_27 ) ;
return 0 ;
}
void
F_111 ( void )
{
struct V_121 * V_122 , * V_123 ;
F_91 () ;
F_92 (listentry, listtmp, &list_all_bus_instances) {
struct V_6 * V_2 = F_93 ( V_122 ,
struct V_6 ,
V_79 ) ;
F_90 ( V_2 ) ;
}
F_112 ( & V_74 ) ;
V_111 = false ;
F_12 ( V_117 ) ;
}
