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
if ( F_5 ( V_12 , L_2 , & V_8 ) )
return - V_13 ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_10 , struct V_14 * V_15 )
{
T_2 V_16 ;
int V_17 ;
struct V_6 * V_2 ;
struct V_18 * V_19 ;
V_2 = F_2 ( V_10 ) ;
V_19 = F_7 ( V_15 ) ;
V_16 = F_3 ( V_2 -> V_9 ) ;
if ( V_20 )
return 1 ;
if ( V_21 )
return 0 ;
if ( ! V_19 -> V_22 )
return 0 ;
for ( V_17 = 0 ;
( F_8 ( V_19 -> V_22 [ V_17 ] . V_8 , V_23 ) != 0 ) ||
( V_19 -> V_22 [ V_17 ] . V_24 ) ;
V_17 ++ )
if ( F_8 ( V_19 -> V_22 [ V_17 ] . V_8 ,
V_16 ) == 0 )
return V_17 + 1 ;
return 0 ;
}
static void
F_9 ( struct V_1 * V_10 )
{
struct V_6 * V_2 = F_10 ( V_10 ) ;
F_11 ( V_2 -> V_25 ) ;
F_12 ( V_2 -> V_26 ) ;
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
if ( ! V_7 -> V_9 )
return 0 ;
return sprintf ( V_5 , L_3 ,
F_17 ( V_7 -> V_9 ) ) ;
}
static T_1 F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 -> V_9 )
return 0 ;
return sprintf ( V_5 , L_4 ,
F_19 ( V_7 -> V_9 ) ) ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 -> V_9 )
return 0 ;
return sprintf ( V_5 , L_3 ,
F_21 ( V_7 -> V_9 ) ) ;
}
static T_1 F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char V_27 [ V_28 ] ;
if ( ! V_7 -> V_9 )
return 0 ;
return sprintf ( V_5 , L_5 ,
F_23 ( V_7 -> V_9 , V_27 ) ) ;
}
static T_1 F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char V_29 [ V_28 ] ;
if ( ! V_7 -> V_9 )
return 0 ;
return sprintf ( V_5 , L_5 ,
F_25 ( V_7 -> V_9 , V_29 ) ) ;
}
static T_1 F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_17 = 0 ;
struct V_30 * V_31 = V_2 -> V_32 ;
struct V_14 * V_15 = V_2 -> V_33 ;
struct V_18 * V_19 = NULL ;
if ( ! V_7 -> V_9 || ! V_31 || ! V_15 )
return 0 ;
V_17 = V_31 -> V_34 ( V_2 , V_15 ) ;
if ( ! V_17 )
return 0 ;
V_19 = F_7 ( V_15 ) ;
return sprintf ( V_5 , L_5 , V_19 -> V_22 [ V_17 - 1 ] . V_24 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_35 = F_21 ( V_7 -> V_9 ) ;
return sprintf ( V_5 , L_3 , V_35 ) ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_6 , & V_7 -> V_36 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_5 , V_7 -> V_24 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_37 = F_17 ( V_7 -> V_9 ) ;
return sprintf ( V_5 , L_3 , V_37 ) ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_38 = F_19 ( V_7 -> V_9 ) ;
return sprintf ( V_5 , L_3 , V_38 ) ;
}
static T_1 F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_39 = 0 ;
if ( V_7 -> V_9 ) {
F_23 ( V_7 -> V_9 , V_5 ) ;
V_39 = strlen ( V_5 ) ;
V_5 [ V_39 ++ ] = '\n' ;
}
return V_39 ;
}
static int F_33 ( struct V_40 * V_41 , void * V_42 )
{
struct V_6 * V_7 = V_41 -> V_43 ;
struct V_9 * V_44 = V_7 -> V_9 ;
int V_17 ;
unsigned long V_45 ;
struct V_46 V_47 ;
if ( ! V_44 )
return 0 ;
F_34 ( V_41 ,
L_7 ,
( ( V_7 -> V_24 ) ? ( char * ) ( V_7 -> V_24 ) : L_8 ) ,
V_7 -> V_48 ) ;
if ( F_35 ( V_44 ,
F_36 ( struct V_49 ,
V_50 ) ,
& V_47 , sizeof( V_47 ) ) >= 0 )
F_37 ( & V_47 , V_41 , - 1 ) ;
if ( F_35 ( V_44 ,
F_36 ( struct V_49 ,
V_51 ) ,
& V_47 , sizeof( V_47 ) ) >= 0 )
F_37 ( & V_47 , V_41 , - 1 ) ;
V_45 = F_36 ( struct V_49 , V_47 ) ;
V_17 = 0 ;
while ( V_45 + sizeof( V_47 ) <= F_19 ( V_44 ) ) {
if ( F_35 ( V_44 , V_45 , & V_47 ,
sizeof( V_47 ) ) >= 0 )
F_37 ( & V_47 , V_41 , V_17 ) ;
V_45 += sizeof( V_47 ) ;
V_17 ++ ;
}
return 0 ;
}
static int F_38 ( struct V_52 * V_52 , struct V_53 * V_53 )
{
return F_39 ( V_53 , F_33 ,
V_52 -> V_54 ) ;
}
static void
F_40 ( unsigned long V_55 )
{
struct V_6 * V_2 = (struct V_6 * ) V_55 ;
struct V_18 * V_19 = F_7 ( V_2 -> V_1 . V_33 ) ;
V_19 -> V_56 ( V_2 ) ;
F_41 ( & V_2 -> V_57 , V_58 + V_59 ) ;
}
static void
F_42 ( struct V_6 * V_2 )
{
if ( V_2 -> V_60 || V_2 -> V_61 )
return;
F_43 ( & V_2 -> V_1 ) ;
V_2 -> V_57 . V_62 = V_58 + V_59 ;
F_44 ( & V_2 -> V_57 ) ;
V_2 -> V_61 = true ;
}
static void
F_45 ( struct V_6 * V_2 )
{
if ( ! V_2 -> V_61 )
return;
F_46 ( & V_2 -> V_57 ) ;
V_2 -> V_61 = false ;
F_47 ( & V_2 -> V_1 ) ;
}
static int
F_48 ( struct V_1 * V_10 )
{
struct V_6 * V_2 ;
struct V_18 * V_19 ;
V_2 = F_2 ( V_10 ) ;
V_19 = F_7 ( V_10 -> V_33 ) ;
F_49 ( & V_2 -> V_63 ) ;
V_2 -> V_60 = true ;
if ( V_19 -> remove )
V_19 -> remove ( V_2 ) ;
F_50 ( & V_2 -> V_63 ) ;
F_45 ( V_2 ) ;
F_47 ( & V_2 -> V_1 ) ;
return 0 ;
}
void
F_51 ( struct V_18 * V_19 )
{
F_52 ( & V_19 -> V_33 ) ;
}
int
F_53 ( struct V_6 * V_2 , unsigned long V_64 ,
void * V_65 , unsigned long V_38 )
{
return F_35 ( V_2 -> V_9 , V_64 , V_65 , V_38 ) ;
}
int
F_54 ( struct V_6 * V_2 , unsigned long V_64 ,
void * V_66 , unsigned long V_38 )
{
return F_55 ( V_2 -> V_9 , V_64 , V_66 , V_38 ) ;
}
void
F_56 ( struct V_6 * V_2 )
{
struct V_18 * V_19 = F_7 ( V_2 -> V_1 . V_33 ) ;
if ( ! V_19 -> V_56 ) {
F_57 ( & V_2 -> V_1 , L_9 , V_67 ) ;
return;
}
F_42 ( V_2 ) ;
}
void
F_58 ( struct V_6 * V_2 )
{
F_45 ( V_2 ) ;
}
static int
F_59 ( struct V_6 * V_2 )
{
int V_68 ;
T_4 V_48 = V_2 -> V_48 ;
T_4 V_69 = V_2 -> V_69 ;
F_60 ( V_70 , V_69 , V_48 ,
V_71 ) ;
F_61 ( & V_2 -> V_63 ) ;
V_2 -> V_1 . V_32 = & V_72 ;
V_2 -> V_1 . V_73 = V_74 ;
F_62 ( & V_2 -> V_1 ) ;
V_2 -> V_1 . V_75 = F_14 ;
F_43 ( & V_2 -> V_1 ) ;
F_63 ( & V_2 -> V_57 , F_40 , ( unsigned long ) V_2 ) ;
F_64 ( & V_2 -> V_1 , L_10 ,
V_48 , V_69 ) ;
V_68 = F_65 ( & V_2 -> V_1 ) ;
if ( V_68 < 0 ) {
F_60 ( V_76 , 0 , V_48 ,
V_77 ) ;
goto V_78;
}
F_66 ( & V_2 -> V_79 , & V_80 ) ;
return 0 ;
V_78:
F_47 ( & V_2 -> V_1 ) ;
return V_68 ;
}
static void
F_67 ( struct V_6 * V_2 )
{
F_68 ( & V_2 -> V_79 ) ;
F_47 ( & V_2 -> V_1 ) ;
F_69 ( & V_2 -> V_1 ) ;
}
static int
F_70 ( struct V_9 * V_81 ,
struct V_82 * V_83 )
{
if ( ! F_71 ( F_72 ( V_81 ) ) )
return - V_84 ;
if ( F_35 ( V_81 , sizeof( struct V_85 ) , V_83 ,
sizeof( * V_83 ) ) < 0 ) {
return - V_86 ;
}
if ( V_83 -> V_87 < sizeof( struct V_82 ) )
return - V_84 ;
if ( V_83 -> V_88 <
sizeof( struct V_46 ) ) {
return - V_84 ;
}
return 0 ;
}
static void
F_73 ( struct V_9 * V_81 ,
struct V_82 * V_83 ,
struct V_46 * V_89 )
{
int V_45 = sizeof( struct V_85 ) + V_83 -> V_90 ;
if ( V_83 -> V_90 == 0 )
return;
F_55 ( V_81 , V_45 , V_89 , sizeof( * V_89 ) ) ;
}
static void
F_74 ( struct V_9 * V_81 ,
struct V_82 * V_83 ,
struct V_46 * V_89 )
{
int V_45 = sizeof( struct V_85 ) + V_83 -> V_91 ;
if ( V_83 -> V_91 == 0 )
return;
F_55 ( V_81 , V_45 , V_89 , sizeof( * V_89 ) ) ;
}
static void
F_75 ( struct V_9 * V_81 ,
struct V_82 * V_83 ,
struct V_46 * V_89 , unsigned int V_92 )
{
int V_45 =
( sizeof( struct V_85 ) + V_83 -> V_93 ) +
( V_83 -> V_88 * V_92 ) ;
if ( V_83 -> V_93 == 0 )
return;
F_55 ( V_81 , V_45 , V_89 , sizeof( * V_89 ) ) ;
}
static void
F_76 ( struct V_6 * V_94 )
{
int V_17 ;
struct V_6 * V_95 ;
struct V_18 * V_96 ;
T_4 V_97 = V_94 -> V_48 ;
T_4 V_98 = V_94 -> V_69 ;
struct V_46 V_47 ;
const char * V_99 = NULL ;
struct V_82 * V_83 ;
if ( ! V_94 -> V_1 . V_33 )
return;
V_95 = F_77 ( V_97 , V_100 , NULL ) ;
if ( ! V_95 )
return;
V_83 = (struct V_82 * ) V_95 -> V_101 ;
if ( ! V_83 )
return;
V_96 = F_7 ( V_94 -> V_1 . V_33 ) ;
for ( V_17 = 0 ; V_96 -> V_22 [ V_17 ] . V_24 ; V_17 ++ ) {
if ( memcmp ( & V_96 -> V_22 [ V_17 ] . V_8 ,
& V_94 -> V_102 ,
sizeof( V_96 -> V_22 [ V_17 ] . V_8 ) ) == 0 ) {
V_99 = V_96 -> V_22 [ V_17 ] . V_24 ;
break;
}
}
F_78 ( & V_47 , V_99 , V_96 -> V_24 ) ;
F_75 ( V_95 -> V_9 , V_83 , & V_47 , V_98 ) ;
F_73 ( V_95 -> V_9 , V_83 , & V_103 ) ;
F_74 ( V_95 -> V_9 , V_83 ,
& V_104 ) ;
}
static int
F_79 ( struct V_1 * V_10 )
{
int V_105 ;
struct V_18 * V_19 ;
struct V_6 * V_2 ;
V_19 = F_7 ( V_10 -> V_33 ) ;
V_2 = F_2 ( V_10 ) ;
if ( ! V_19 -> V_106 )
return - V_107 ;
F_49 ( & V_2 -> V_63 ) ;
V_2 -> V_60 = false ;
V_105 = V_19 -> V_106 ( V_2 ) ;
if ( V_105 >= 0 ) {
F_43 ( & V_2 -> V_1 ) ;
F_76 ( V_2 ) ;
}
F_50 ( & V_2 -> V_63 ) ;
return V_105 ;
}
int F_80 ( struct V_18 * V_19 )
{
int V_108 = 0 ;
if ( V_109 < 0 )
return - V_107 ;
V_19 -> V_33 . V_24 = V_19 -> V_24 ;
V_19 -> V_33 . V_32 = & V_72 ;
V_19 -> V_33 . V_106 = F_79 ;
V_19 -> V_33 . remove = F_48 ;
V_19 -> V_33 . V_110 = V_19 -> V_110 ;
V_108 = F_81 ( & V_19 -> V_33 ) ;
if ( V_108 < 0 )
F_52 ( & V_19 -> V_33 ) ;
return V_108 ;
}
static int
F_82 ( struct V_6 * V_2 )
{
int V_111 = V_2 -> V_48 ;
int V_68 ;
struct V_82 * V_83 ;
F_60 ( V_112 , 0 , 0 , V_71 ) ;
V_83 = F_83 ( sizeof( * V_83 ) , V_113 ) ;
if ( ! V_83 )
return - V_13 ;
F_64 ( & V_2 -> V_1 , L_11 , V_111 ) ;
V_2 -> V_1 . V_32 = & V_72 ;
V_2 -> V_1 . V_73 = V_114 ;
V_2 -> V_1 . V_75 = F_9 ;
V_2 -> V_26 = F_84 ( F_85 ( & V_2 -> V_1 ) ,
V_115 ) ;
if ( ! V_2 -> V_26 ) {
V_68 = - V_13 ;
goto V_116;
}
V_2 -> V_25 =
F_86 ( L_12 , 0440 ,
V_2 -> V_26 , V_2 ,
& V_117 ) ;
if ( ! V_2 -> V_25 ) {
V_68 = - V_13 ;
goto V_118;
}
if ( F_87 ( & V_2 -> V_1 ) < 0 ) {
F_60 ( V_119 , 0 , V_111 ,
V_77 ) ;
V_68 = - V_107 ;
goto V_120;
}
if ( F_70 ( V_2 -> V_9 , V_83 ) >= 0 ) {
V_2 -> V_101 = ( void * ) V_83 ;
F_73 ( V_2 -> V_9 , V_83 ,
& V_103 ) ;
F_74 ( V_2 -> V_9 , V_83 ,
& V_104 ) ;
} else {
F_13 ( V_83 ) ;
}
F_66 ( & V_2 -> V_79 , & V_121 ) ;
F_88 ( & V_2 -> V_1 , V_2 ) ;
return 0 ;
V_120:
F_11 ( V_2 -> V_25 ) ;
V_118:
F_12 ( V_2 -> V_26 ) ;
V_116:
F_13 ( V_83 ) ;
return V_68 ;
}
static void
F_89 ( struct V_6 * V_2 )
{
if ( V_2 -> V_9 ) {
F_15 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
F_13 ( V_2 -> V_101 ) ;
F_68 ( & V_2 -> V_79 ) ;
F_69 ( & V_2 -> V_1 ) ;
}
static int
F_90 ( void )
{
V_109 = F_91 ( & V_72 ) ;
return V_109 ;
}
static void
F_92 ( void )
{
F_93 ( & V_72 ) ;
}
static void
F_94 ( void )
{
struct V_122 * V_123 , * V_124 ;
F_95 (listentry, listtmp, &list_all_device_instances) {
struct V_6 * V_2 = F_96 ( V_123 ,
struct V_6 ,
V_79 ) ;
F_67 ( V_2 ) ;
}
}
void
F_97 ( struct V_6 * V_2 )
{
int V_108 ;
T_4 V_97 = V_2 -> V_48 ;
F_60 ( V_112 , 0 , V_97 , V_71 ) ;
V_108 = F_82 ( V_2 ) ;
F_60 ( V_125 , 0 , V_97 , V_71 ) ;
if ( V_108 < 0 )
F_60 ( V_126 , 0 , V_97 ,
V_77 ) ;
else
F_60 ( V_127 , 0 , V_97 ,
V_71 ) ;
F_98 ( V_2 , V_108 ) ;
}
void
F_99 ( struct V_6 * V_2 )
{
F_89 ( V_2 ) ;
F_100 ( V_2 , 0 ) ;
}
void
F_101 ( struct V_6 * V_47 )
{
int V_108 ;
T_4 V_97 = V_47 -> V_48 ;
T_4 V_98 = V_47 -> V_69 ;
F_60 ( V_70 , V_98 , V_97 ,
V_71 ) ;
V_108 = F_59 ( V_47 ) ;
F_102 ( V_47 , V_108 ) ;
if ( V_108 < 0 )
F_60 ( V_119 , V_98 , V_97 ,
V_77 ) ;
else
F_60 ( V_128 , V_98 , V_97 ,
V_71 ) ;
}
void
F_103 ( struct V_6 * V_47 )
{
F_67 ( V_47 ) ;
F_104 ( V_47 , 0 ) ;
}
static void
F_105 ( struct V_6 * V_2 , int V_129 )
{
if ( ! V_2 -> V_130 )
return;
V_2 -> V_130 = false ;
F_106 ( V_2 , V_129 ) ;
}
static void
F_107 ( struct V_6 * V_2 , int V_129 )
{
if ( ! V_2 -> V_131 )
return;
V_2 -> V_131 = false ;
F_108 ( V_2 , V_129 ) ;
}
static void
F_109 ( struct V_6 * V_2 , bool V_132 )
{
int V_108 ;
struct V_18 * V_19 = NULL ;
void (* F_110)( struct V_6 * V_2 , int V_133 ) = NULL ;
if ( V_132 )
F_110 = F_106 ;
else
F_110 = F_108 ;
if ( ! F_110 )
return;
V_19 = F_7 ( V_2 -> V_1 . V_33 ) ;
if ( ! V_19 ) {
(* F_110)( V_2 , - V_107 ) ;
return;
}
if ( V_2 -> V_130 || V_2 -> V_131 ) {
(* F_110)( V_2 , - V_134 ) ;
return;
}
if ( V_132 ) {
if ( ! V_19 -> V_135 ) {
(* F_110)( V_2 , - V_84 ) ;
return;
}
V_2 -> V_130 = true ;
V_108 = V_19 -> V_135 ( V_2 , F_105 ) ;
} else {
F_76 ( V_2 ) ;
if ( ! V_19 -> V_136 ) {
(* F_110)( V_2 , - V_84 ) ;
return;
}
V_2 -> V_131 = true ;
V_108 = V_19 -> V_136 ( V_2 , F_107 ) ;
}
if ( V_108 < 0 ) {
if ( V_132 )
V_2 -> V_130 = false ;
else
V_2 -> V_131 = false ;
(* F_110)( V_2 , - V_84 ) ;
}
}
void
F_111 ( struct V_6 * V_47 )
{
F_109 ( V_47 , true ) ;
}
void
F_112 ( struct V_6 * V_47 )
{
F_109 ( V_47 , false ) ;
}
int
F_113 ( void )
{
int V_68 ;
F_60 ( V_137 , 0 , 0 , V_71 ) ;
V_115 = F_84 ( L_13 , NULL ) ;
if ( ! V_115 )
return - V_13 ;
F_78 ( & V_104 , L_14 , L_13 ) ;
V_68 = F_90 () ;
if ( V_68 < 0 ) {
F_60 ( V_112 , 0 , 0 , V_77 ) ;
goto error;
}
F_78 ( & V_103 , L_15 , L_16 ) ;
return 0 ;
error:
F_60 ( V_138 , 0 , V_68 , V_77 ) ;
return V_68 ;
}
void
F_114 ( void )
{
struct V_122 * V_123 , * V_124 ;
F_94 () ;
F_95 (listentry, listtmp, &list_all_bus_instances) {
struct V_6 * V_2 = F_96 ( V_123 ,
struct V_6 ,
V_79 ) ;
F_89 ( V_2 ) ;
}
F_92 () ;
F_12 ( V_115 ) ;
}
