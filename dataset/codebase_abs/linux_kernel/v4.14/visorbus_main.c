static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
const T_2 * V_8 ;
V_7 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_7 -> V_9 ) ;
return sprintf ( V_5 , L_1 , V_8 ) ;
}
int F_4 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
const T_2 * V_12 ,
char * V_13 ,
T_3 V_14 ,
T_4 V_15 ,
T_3 V_16 )
{
if ( ! F_5 ( V_12 ) ) {
if ( ! F_6 ( & V_11 -> V_17 , V_12 ) ) {
F_7 ( V_2 , L_2 ,
V_13 , V_12 , V_12 ,
& V_11 -> V_17 ) ;
return 0 ;
}
}
if ( V_14 > 0 ) {
if ( V_11 -> V_18 < V_14 ) {
F_7 ( V_2 , L_3 ,
V_13 , V_12 ,
( unsigned long long ) V_14 ,
V_11 -> V_18 ) ;
return 0 ;
}
}
if ( V_15 > 0 ) {
if ( V_11 -> V_19 != V_15 ) {
F_7 ( V_2 , L_4 ,
V_13 , V_12 ,
( unsigned long ) V_15 ,
V_11 -> V_19 ) ;
return 0 ;
}
}
if ( V_16 > 0 ) {
if ( V_11 -> V_20 != V_16 ) {
F_7 ( V_2 , L_5 ,
V_13 , V_12 , V_16 ,
V_11 -> V_20 ) ;
return 0 ;
}
}
return 1 ;
}
static int F_8 ( struct V_1 * V_21 , struct V_22 * V_23 )
{
struct V_6 * V_2 ;
const T_2 * V_8 ;
V_2 = F_2 ( V_21 ) ;
V_8 = F_3 ( V_2 -> V_9 ) ;
return F_9 ( V_23 , L_6 , V_8 ) ;
}
static int F_10 ( struct V_1 * V_21 , struct V_24 * V_25 )
{
const T_2 * V_26 ;
int V_27 ;
struct V_6 * V_2 ;
struct V_28 * V_29 ;
V_2 = F_2 ( V_21 ) ;
V_26 = F_3 ( V_2 -> V_9 ) ;
V_29 = F_11 ( V_25 ) ;
if ( ! V_29 -> V_30 )
return 0 ;
for ( V_27 = 0 ; ! F_5 ( & V_29 -> V_30 [ V_27 ] . V_8 ) ; V_27 ++ )
if ( F_6 ( & V_29 -> V_30 [ V_27 ] . V_8 , V_26 ) )
return V_27 + 1 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_21 )
{
struct V_6 * V_2 = F_13 ( V_21 ) ;
F_14 ( V_2 -> V_31 ) ;
F_15 ( V_2 -> V_32 ) ;
F_16 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_21 )
{
struct V_6 * V_2 = F_2 ( V_21 ) ;
F_18 ( V_2 -> V_9 ) ;
F_16 ( V_2 ) ;
}
static T_1 F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_7 ,
F_20 ( V_7 -> V_9 ) ) ;
}
static T_1 F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_8 ,
F_22 ( V_7 -> V_9 ) ) ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_7 ,
F_24 ( V_7 -> V_9 ) ) ;
}
static T_1 F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char V_33 [ V_34 ] ;
return sprintf ( V_5 , L_9 ,
F_26 ( V_7 -> V_9 , V_33 ) ) ;
}
static T_1 F_27 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char V_35 [ V_34 ] ;
return sprintf ( V_5 , L_9 ,
F_28 ( V_7 -> V_9 , V_35 ) ) ;
}
static T_1 F_29 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_27 = 0 ;
struct V_36 * V_37 = V_2 -> V_38 ;
struct V_24 * V_25 = V_2 -> V_39 ;
struct V_28 * V_29 = NULL ;
if ( ! V_25 )
return 0 ;
V_27 = V_37 -> V_40 ( V_2 , V_25 ) ;
if ( ! V_27 )
return 0 ;
V_29 = F_11 ( V_25 ) ;
return sprintf ( V_5 , L_9 , V_29 -> V_30 [ V_27 - 1 ] . V_41 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_42 = F_24 ( V_7 -> V_9 ) ;
return sprintf ( V_5 , L_7 , V_42 ) ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , & V_7 -> V_43 ) ;
}
static T_1 F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_9 , V_7 -> V_41 ) ;
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_44 = F_20 ( V_7 -> V_9 ) ;
return sprintf ( V_5 , L_7 , V_44 ) ;
}
static T_1 F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_45 = F_22 ( V_7 -> V_9 ) ;
return sprintf ( V_5 , L_7 , V_45 ) ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_46 = 0 ;
F_26 ( V_7 -> V_9 , V_5 ) ;
V_46 = strlen ( V_5 ) ;
V_5 [ V_46 ++ ] = '\n' ;
return V_46 ;
}
static void F_36 ( struct V_47 * V_48 ,
struct V_49 * V_50 , int V_51 )
{
if ( ! isprint ( V_48 -> V_52 [ 0 ] ) )
return;
if ( V_51 >= 0 )
F_37 ( V_50 , L_11 , V_51 ) ;
else
F_38 ( V_50 , L_12 ) ;
F_37 ( V_50 , L_13 , ( int ) sizeof( V_48 -> V_52 ) ,
( int ) sizeof( V_48 -> V_52 ) , V_48 -> V_52 ) ;
F_37 ( V_50 , L_13 , ( int ) sizeof( V_48 -> V_53 ) ,
( int ) sizeof( V_48 -> V_53 ) , V_48 -> V_53 ) ;
F_37 ( V_50 , L_14 , ( int ) sizeof( V_48 -> V_54 ) ,
V_48 -> V_54 ) ;
}
static int F_39 ( struct V_49 * V_50 , void * V_55 )
{
int V_27 = 0 ;
unsigned long V_56 ;
struct V_47 V_57 ;
struct V_6 * V_7 = V_50 -> V_58 ;
struct V_9 * V_59 = V_7 -> V_9 ;
if ( ! V_59 )
return 0 ;
F_37 ( V_50 ,
L_15 ,
( ( V_7 -> V_41 ) ? ( char * ) ( V_7 -> V_41 ) : L_16 ) ,
V_7 -> V_60 ) ;
if ( F_40 ( V_59 ,
F_41 ( struct V_61 , V_62 ) ,
& V_57 , sizeof( V_57 ) ) >= 0 )
F_36 ( & V_57 , V_50 , - 1 ) ;
if ( F_40 ( V_59 ,
F_41 ( struct V_61 , V_63 ) ,
& V_57 , sizeof( V_57 ) ) >= 0 )
F_36 ( & V_57 , V_50 , - 1 ) ;
V_56 = F_41 ( struct V_61 , V_57 ) ;
while ( V_56 + sizeof( V_57 ) <= F_22 ( V_59 ) ) {
if ( F_40 ( V_59 , V_56 , & V_57 ,
sizeof( V_57 ) ) >= 0 )
F_36 ( & V_57 , V_50 , V_27 ) ;
V_56 += sizeof( V_57 ) ;
V_27 ++ ;
}
return 0 ;
}
static int F_42 ( struct V_64 * V_64 , struct V_65 * V_65 )
{
return F_43 ( V_65 , F_39 ,
V_64 -> V_66 ) ;
}
static void F_44 ( unsigned long V_67 )
{
struct V_6 * V_2 = (struct V_6 * ) V_67 ;
struct V_28 * V_29 = F_11 ( V_2 -> V_1 . V_39 ) ;
V_29 -> V_68 ( V_2 ) ;
F_45 ( & V_2 -> V_69 , V_70 + V_71 ) ;
}
static int F_46 ( struct V_6 * V_2 )
{
if ( V_2 -> V_72 || V_2 -> V_73 )
return - V_74 ;
F_47 ( & V_2 -> V_1 ) ;
V_2 -> V_69 . V_75 = V_70 + V_71 ;
F_48 ( & V_2 -> V_69 ) ;
V_2 -> V_73 = true ;
return 0 ;
}
static void F_49 ( struct V_6 * V_2 )
{
if ( ! V_2 -> V_73 )
return;
F_50 ( & V_2 -> V_69 ) ;
V_2 -> V_73 = false ;
F_51 ( & V_2 -> V_1 ) ;
}
static int F_52 ( struct V_1 * V_21 )
{
struct V_6 * V_2 ;
struct V_28 * V_29 ;
V_2 = F_2 ( V_21 ) ;
V_29 = F_11 ( V_21 -> V_39 ) ;
F_53 ( & V_2 -> V_76 ) ;
V_2 -> V_72 = true ;
V_29 -> remove ( V_2 ) ;
F_54 ( & V_2 -> V_76 ) ;
F_49 ( V_2 ) ;
F_51 ( & V_2 -> V_1 ) ;
return 0 ;
}
void F_55 ( struct V_28 * V_29 )
{
F_56 ( & V_29 -> V_39 ) ;
}
int F_57 ( struct V_6 * V_2 , unsigned long V_77 ,
void * V_78 , unsigned long V_45 )
{
return F_40 ( V_2 -> V_9 , V_77 , V_78 , V_45 ) ;
}
int F_58 ( struct V_6 * V_2 , unsigned long V_77 ,
void * V_79 , unsigned long V_45 )
{
return F_59 ( V_2 -> V_9 , V_77 , V_79 , V_45 ) ;
}
int F_60 ( struct V_6 * V_2 )
{
struct V_28 * V_29 = F_11 ( V_2 -> V_1 . V_39 ) ;
if ( ! V_29 -> V_68 ) {
F_7 ( & V_2 -> V_1 , L_17 , V_80 ) ;
return - V_81 ;
}
return F_46 ( V_2 ) ;
}
void F_61 ( struct V_6 * V_2 )
{
F_49 ( V_2 ) ;
}
int F_62 ( struct V_6 * V_2 )
{
int V_82 ;
T_4 V_60 = V_2 -> V_60 ;
T_4 V_83 = V_2 -> V_83 ;
F_63 ( & V_2 -> V_76 ) ;
V_2 -> V_1 . V_38 = & V_84 ;
V_2 -> V_1 . V_85 = V_86 ;
F_64 ( & V_2 -> V_1 ) ;
V_2 -> V_1 . V_87 = F_17 ;
F_47 ( & V_2 -> V_1 ) ;
F_65 ( & V_2 -> V_69 , F_44 , ( unsigned long ) V_2 ) ;
V_82 = F_66 ( & V_2 -> V_1 , L_18 ,
V_60 , V_83 ) ;
if ( V_82 )
goto V_88;
V_82 = F_67 ( & V_2 -> V_1 ) ;
if ( V_82 < 0 )
goto V_88;
F_68 ( & V_2 -> V_89 , & V_90 ) ;
V_2 -> V_91 . V_92 = 1 ;
F_69 ( V_2 , V_82 , V_93 ) ;
return 0 ;
V_88:
F_51 ( & V_2 -> V_1 ) ;
F_7 ( & V_2 -> V_1 , L_19 , V_82 ) ;
return V_82 ;
}
void F_70 ( struct V_6 * V_2 )
{
F_71 ( & V_2 -> V_89 ) ;
F_51 ( & V_2 -> V_1 ) ;
F_72 ( & V_2 -> V_1 ) ;
F_69 ( V_2 , 0 , V_94 ) ;
}
static int F_73 ( struct V_9 * V_95 ,
struct V_1 * V_2 ,
struct V_96 * V_97 )
{
int V_82 ;
if ( ! F_4 ( F_74 ( V_95 ) ,
V_2 ,
& V_98 ,
L_20 ,
sizeof( struct V_61 ) ,
V_99 ,
V_100 ) )
return - V_74 ;
V_82 = F_40 ( V_95 , sizeof( struct V_10 ) , V_97 ,
sizeof( * V_97 ) ) ;
if ( V_82 < 0 )
return V_82 ;
if ( V_97 -> V_101 < sizeof( struct V_96 ) )
return - V_74 ;
if ( V_97 -> V_102 <
sizeof( struct V_47 ) )
return - V_74 ;
return 0 ;
}
static void F_75 ( struct V_9 * V_95 ,
struct V_96 * V_97 ,
struct V_47 * V_103 )
{
int V_56 = sizeof( struct V_10 ) + V_97 -> V_104 ;
if ( V_97 -> V_104 == 0 )
return;
F_59 ( V_95 , V_56 , V_103 , sizeof( * V_103 ) ) ;
}
static void F_76 ( struct V_9 * V_95 ,
struct V_96 * V_97 ,
struct V_47 * V_103 )
{
int V_56 = sizeof( struct V_10 ) + V_97 -> V_105 ;
if ( V_97 -> V_105 == 0 )
return;
F_59 ( V_95 , V_56 , V_103 , sizeof( * V_103 ) ) ;
}
static void F_77 ( struct V_9 * V_95 ,
struct V_96 * V_97 ,
struct V_47 * V_103 ,
unsigned int V_51 )
{
int V_56 =
( sizeof( struct V_10 ) + V_97 -> V_106 ) +
( V_97 -> V_102 * V_51 ) ;
if ( V_97 -> V_106 == 0 )
return;
F_59 ( V_95 , V_56 , V_103 , sizeof( * V_103 ) ) ;
}
static void F_78 (
struct V_47 * V_107 ,
const char * V_108 , const char * V_109 )
{
memset ( V_107 , 0 , sizeof( struct V_47 ) ) ;
snprintf ( V_107 -> V_52 ,
sizeof( V_107 -> V_52 ) ,
L_21 , ( V_108 ) ? V_108 : L_22 ) ;
snprintf ( V_107 -> V_53 ,
sizeof( V_107 -> V_53 ) ,
L_21 , ( V_109 ) ? V_109 : L_23 ) ;
snprintf ( V_107 -> V_54 ,
sizeof( V_107 -> V_54 ) , L_24 ,
F_79 () -> V_87 ) ;
}
static void F_80 ( struct V_6 * V_110 )
{
int V_27 ;
struct V_6 * V_111 ;
struct V_28 * V_112 ;
T_4 V_113 = V_110 -> V_60 ;
T_4 V_114 = V_110 -> V_83 ;
struct V_47 V_57 ;
const char * V_115 = NULL ;
struct V_96 * V_97 ;
if ( ! V_110 -> V_1 . V_39 )
return;
V_111 = F_81 ( V_113 , V_116 , NULL ) ;
if ( ! V_111 )
return;
V_97 = (struct V_96 * ) V_111 -> V_117 ;
if ( ! V_97 )
return;
V_112 = F_11 ( V_110 -> V_1 . V_39 ) ;
for ( V_27 = 0 ; V_112 -> V_30 [ V_27 ] . V_41 ; V_27 ++ ) {
if ( memcmp ( & V_112 -> V_30 [ V_27 ] . V_8 ,
& V_110 -> V_118 ,
sizeof( V_112 -> V_30 [ V_27 ] . V_8 ) ) == 0 ) {
V_115 = V_112 -> V_30 [ V_27 ] . V_41 ;
break;
}
}
F_78 ( & V_57 , V_115 , V_112 -> V_41 ) ;
F_77 ( V_111 -> V_9 , V_97 , & V_57 , V_114 ) ;
F_75 ( V_111 -> V_9 , V_97 , & V_119 ) ;
F_76 ( V_111 -> V_9 , V_97 ,
& V_120 ) ;
}
static int F_82 ( struct V_1 * V_21 )
{
int V_121 ;
struct V_28 * V_29 ;
struct V_6 * V_2 ;
V_2 = F_2 ( V_21 ) ;
V_29 = F_11 ( V_21 -> V_39 ) ;
F_53 ( & V_2 -> V_76 ) ;
V_2 -> V_72 = false ;
V_121 = V_29 -> V_122 ( V_2 ) ;
if ( V_121 >= 0 ) {
F_47 ( & V_2 -> V_1 ) ;
F_80 ( V_2 ) ;
}
F_54 ( & V_2 -> V_76 ) ;
return V_121 ;
}
int F_83 ( struct V_28 * V_29 )
{
if ( ! V_123 )
return - V_124 ;
if ( ! V_29 -> V_122 )
return - V_74 ;
if ( ! V_29 -> remove )
return - V_74 ;
if ( ! V_29 -> V_125 )
return - V_74 ;
if ( ! V_29 -> V_126 )
return - V_74 ;
V_29 -> V_39 . V_41 = V_29 -> V_41 ;
V_29 -> V_39 . V_38 = & V_84 ;
V_29 -> V_39 . V_122 = F_82 ;
V_29 -> V_39 . remove = F_52 ;
V_29 -> V_39 . V_127 = V_29 -> V_127 ;
return F_84 ( & V_29 -> V_39 ) ;
}
int F_85 ( struct V_6 * V_2 )
{
int V_128 = V_2 -> V_60 ;
int V_82 ;
struct V_96 * V_97 ;
V_97 = F_86 ( sizeof( * V_97 ) , V_129 ) ;
if ( ! V_97 )
return - V_130 ;
F_66 ( & V_2 -> V_1 , L_25 , V_128 ) ;
V_2 -> V_1 . V_38 = & V_84 ;
V_2 -> V_1 . V_85 = V_131 ;
V_2 -> V_1 . V_87 = F_12 ;
V_2 -> V_32 = F_87 ( F_88 ( & V_2 -> V_1 ) ,
V_132 ) ;
V_2 -> V_31 =
F_89 ( L_26 , 0440 ,
V_2 -> V_32 , V_2 ,
& V_133 ) ;
F_90 ( & V_2 -> V_1 , V_2 ) ;
V_82 = F_73 ( V_2 -> V_9 , & V_2 -> V_1 , V_97 ) ;
if ( V_82 < 0 )
goto V_134;
V_82 = F_91 ( & V_2 -> V_1 ) ;
if ( V_82 < 0 )
goto V_134;
F_68 ( & V_2 -> V_89 , & V_135 ) ;
V_2 -> V_91 . V_92 = 1 ;
V_2 -> V_117 = ( void * ) V_97 ;
F_75 ( V_2 -> V_9 , V_97 ,
& V_119 ) ;
F_76 ( V_2 -> V_9 , V_97 ,
& V_120 ) ;
F_69 ( V_2 , V_82 , V_136 ) ;
return 0 ;
V_134:
F_15 ( V_2 -> V_32 ) ;
F_16 ( V_97 ) ;
F_7 ( & V_2 -> V_1 , L_27 , V_80 , V_82 ) ;
return V_82 ;
}
void F_92 ( struct V_6 * V_2 )
{
F_18 ( V_2 -> V_9 ) ;
F_16 ( V_2 -> V_117 ) ;
F_71 ( & V_2 -> V_89 ) ;
F_72 ( & V_2 -> V_1 ) ;
F_69 ( V_2 , 0 , V_137 ) ;
}
static void F_93 ( void )
{
struct V_138 * V_139 , * V_140 ;
F_94 (listentry, listtmp, &list_all_device_instances) {
struct V_6 * V_2 = F_95 ( V_139 ,
struct V_6 ,
V_89 ) ;
F_70 ( V_2 ) ;
}
}
static void F_96 ( struct V_6 * V_2 , int V_141 )
{
if ( ! V_2 -> V_142 )
return;
V_2 -> V_142 = false ;
F_97 ( V_2 , V_141 ,
V_143 ) ;
}
static void F_98 ( struct V_6 * V_2 , int V_141 )
{
if ( ! V_2 -> V_144 )
return;
V_2 -> V_144 = false ;
F_97 ( V_2 , V_141 ,
V_145 ) ;
}
static int F_99 ( struct V_6 * V_2 ,
bool V_146 )
{
int V_82 ;
struct V_28 * V_29 = NULL ;
if ( ! V_2 -> V_1 . V_39 )
return 0 ;
if ( V_2 -> V_142 || V_2 -> V_144 )
return - V_147 ;
V_29 = F_11 ( V_2 -> V_1 . V_39 ) ;
if ( V_146 ) {
V_2 -> V_142 = true ;
V_82 = V_29 -> V_125 ( V_2 , F_96 ) ;
} else {
F_80 ( V_2 ) ;
V_2 -> V_144 = true ;
V_82 = V_29 -> V_126 ( V_2 , F_98 ) ;
}
return V_82 ;
}
int F_100 ( struct V_6 * V_57 )
{
int V_82 ;
V_82 = F_99 ( V_57 , true ) ;
if ( V_82 < 0 ) {
V_57 -> V_142 = false ;
return V_82 ;
}
return 0 ;
}
int F_101 ( struct V_6 * V_57 )
{
int V_82 ;
V_82 = F_99 ( V_57 , false ) ;
if ( V_82 < 0 ) {
V_57 -> V_144 = false ;
return V_82 ;
}
return 0 ;
}
int F_102 ( void )
{
int V_82 ;
V_132 = F_87 ( L_28 , NULL ) ;
if ( ! V_132 )
return - V_130 ;
F_78 ( & V_120 , L_29 , L_28 ) ;
V_82 = F_103 ( & V_84 ) ;
if ( V_82 < 0 )
return V_82 ;
V_123 = true ;
F_78 ( & V_119 , L_30 , L_31 ) ;
return 0 ;
}
void F_104 ( void )
{
struct V_138 * V_139 , * V_140 ;
F_93 () ;
F_94 (listentry, listtmp, &list_all_bus_instances) {
struct V_6 * V_2 = F_95 ( V_139 ,
struct V_6 ,
V_89 ) ;
F_92 ( V_2 ) ;
}
F_105 ( & V_84 ) ;
V_123 = false ;
F_15 ( V_132 ) ;
}
