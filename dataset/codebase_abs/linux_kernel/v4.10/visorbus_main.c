static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
T_2 V_8 ;
V_7 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_7 -> V_9 ) ;
return snprintf ( V_5 , V_10 , L_1 , & V_8 ) ;
}
static int
F_4 ( struct V_1 * V_11 , struct V_12 * V_13 )
{
struct V_6 * V_2 ;
T_2 V_8 ;
V_2 = F_2 ( V_11 ) ;
V_8 = F_3 ( V_2 -> V_9 ) ;
if ( F_5 ( V_13 , L_2 , & V_8 ) )
return - V_14 ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_11 , struct V_15 * V_16 )
{
T_2 V_17 ;
int V_18 ;
struct V_6 * V_2 ;
struct V_19 * V_20 ;
V_2 = F_2 ( V_11 ) ;
V_20 = F_7 ( V_16 ) ;
V_17 = F_3 ( V_2 -> V_9 ) ;
if ( V_21 )
return 1 ;
if ( V_22 )
return 0 ;
if ( ! V_20 -> V_23 )
return 0 ;
for ( V_18 = 0 ;
( F_8 ( V_20 -> V_23 [ V_18 ] . V_8 , V_24 ) != 0 ) ||
( V_20 -> V_23 [ V_18 ] . V_25 ) ;
V_18 ++ )
if ( F_8 ( V_20 -> V_23 [ V_18 ] . V_8 ,
V_17 ) == 0 )
return V_18 + 1 ;
return 0 ;
}
static void
F_9 ( struct V_1 * V_11 )
{
struct V_6 * V_2 = F_10 ( V_11 ) ;
F_11 ( V_2 -> V_26 ) ;
F_12 ( V_2 -> V_27 ) ;
F_13 ( V_2 ) ;
}
static void
F_14 ( struct V_1 * V_11 )
{
struct V_6 * V_2 = F_2 ( V_11 ) ;
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
return snprintf ( V_5 , V_10 , L_3 ,
F_17 ( V_7 -> V_9 ) ) ;
}
static T_1 F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 -> V_9 )
return 0 ;
return snprintf ( V_5 , V_10 , L_4 ,
F_19 ( V_7 -> V_9 ) ) ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 -> V_9 )
return 0 ;
return snprintf ( V_5 , V_10 , L_3 ,
F_21 ( V_7 -> V_9 ) ) ;
}
static T_1 F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char V_28 [ V_29 ] ;
if ( ! V_7 -> V_9 )
return 0 ;
return snprintf ( V_5 , V_10 , L_5 ,
F_23 ( V_7 -> V_9 , V_28 ) ) ;
}
static T_1 F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char V_30 [ V_29 ] ;
if ( ! V_7 -> V_9 )
return 0 ;
return snprintf ( V_5 , V_10 , L_5 ,
F_25 ( V_7 -> V_9 , V_30 ) ) ;
}
static T_1 F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_18 = 0 ;
struct V_31 * V_32 = V_2 -> V_33 ;
struct V_15 * V_16 = V_2 -> V_34 ;
struct V_19 * V_20 = NULL ;
if ( ! V_7 -> V_9 || ! V_32 || ! V_16 )
return 0 ;
V_18 = V_32 -> V_35 ( V_2 , V_16 ) ;
if ( ! V_18 )
return 0 ;
V_20 = F_7 ( V_16 ) ;
return snprintf ( V_5 , V_10 , L_5 , V_20 -> V_23 [ V_18 - 1 ] . V_25 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_36 = F_21 ( V_7 -> V_9 ) ;
return snprintf ( V_5 , V_10 , L_3 , V_36 ) ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_10 , L_6 , & V_7 -> V_37 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_10 , L_5 , V_7 -> V_25 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_38 = F_17 ( V_7 -> V_9 ) ;
return snprintf ( V_5 , V_10 , L_3 , V_38 ) ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_39 = F_19 ( V_7 -> V_9 ) ;
return snprintf ( V_5 , V_10 , L_3 , V_39 ) ;
}
static T_1 F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_40 = 0 ;
if ( V_7 -> V_9 ) {
F_23 ( V_7 -> V_9 , V_5 ) ;
V_40 = strlen ( V_5 ) ;
V_5 [ V_40 ++ ] = '\n' ;
}
return V_40 ;
}
static int F_33 ( struct V_41 * V_42 , void * V_43 )
{
struct V_6 * V_7 = V_42 -> V_44 ;
struct V_9 * V_45 = V_7 -> V_9 ;
int V_18 ;
unsigned long V_46 ;
struct V_47 V_48 ;
if ( ! V_45 )
return 0 ;
F_34 ( V_42 ,
L_7 ,
( ( V_7 -> V_25 ) ? ( char * ) ( V_7 -> V_25 ) : L_8 ) ,
V_7 -> V_49 ) ;
if ( F_35 ( V_45 ,
F_36 ( struct V_50 ,
V_51 ) ,
& V_48 , sizeof( V_48 ) ) >= 0 )
F_37 ( & V_48 , V_42 , - 1 ) ;
if ( F_35 ( V_45 ,
F_36 ( struct V_50 ,
V_52 ) ,
& V_48 , sizeof( V_48 ) ) >= 0 )
F_37 ( & V_48 , V_42 , - 1 ) ;
V_46 = F_36 ( struct V_50 , V_48 ) ;
V_18 = 0 ;
while ( V_46 + sizeof( V_48 ) <= F_19 ( V_45 ) ) {
if ( F_35 ( V_45 , V_46 , & V_48 ,
sizeof( V_48 ) ) >= 0 )
F_37 ( & V_48 , V_42 , V_18 ) ;
V_46 += sizeof( V_48 ) ;
V_18 ++ ;
}
return 0 ;
}
static int F_38 ( struct V_53 * V_53 , struct V_54 * V_54 )
{
return F_39 ( V_54 , F_33 ,
V_53 -> V_55 ) ;
}
static void
F_40 ( unsigned long V_56 )
{
struct V_6 * V_2 = (struct V_6 * ) V_56 ;
struct V_19 * V_20 = F_7 ( V_2 -> V_1 . V_34 ) ;
if ( V_20 -> V_57 )
V_20 -> V_57 ( V_2 ) ;
F_41 ( & V_2 -> V_58 , V_59 + V_60 ) ;
}
static void
F_42 ( struct V_6 * V_2 )
{
if ( V_2 -> V_61 || V_2 -> V_62 )
return;
F_43 ( & V_2 -> V_1 ) ;
V_2 -> V_58 . V_63 = V_59 + V_60 ;
F_44 ( & V_2 -> V_58 ) ;
V_2 -> V_62 = true ;
}
static void
F_45 ( struct V_6 * V_2 )
{
if ( ! V_2 -> V_62 )
return;
F_46 ( & V_2 -> V_58 ) ;
V_2 -> V_62 = false ;
F_47 ( & V_2 -> V_1 ) ;
}
static int
F_48 ( struct V_1 * V_11 )
{
struct V_6 * V_2 ;
struct V_19 * V_20 ;
V_2 = F_2 ( V_11 ) ;
V_20 = F_7 ( V_11 -> V_34 ) ;
F_49 ( & V_2 -> V_64 ) ;
V_2 -> V_61 = true ;
if ( V_20 -> remove )
V_20 -> remove ( V_2 ) ;
F_50 ( & V_2 -> V_64 ) ;
F_45 ( V_2 ) ;
F_47 ( & V_2 -> V_1 ) ;
return 0 ;
}
void
F_51 ( struct V_19 * V_20 )
{
F_52 ( & V_20 -> V_34 ) ;
}
int
F_53 ( struct V_6 * V_2 , unsigned long V_65 ,
void * V_66 , unsigned long V_39 )
{
return F_35 ( V_2 -> V_9 , V_65 , V_66 , V_39 ) ;
}
int
F_54 ( struct V_6 * V_2 , unsigned long V_65 ,
void * V_67 , unsigned long V_39 )
{
return F_55 ( V_2 -> V_9 , V_65 , V_67 , V_39 ) ;
}
void
F_56 ( struct V_6 * V_2 )
{
F_42 ( V_2 ) ;
}
void
F_57 ( struct V_6 * V_2 )
{
F_45 ( V_2 ) ;
}
static int
F_58 ( struct V_6 * V_2 )
{
int V_68 ;
T_4 V_49 = V_2 -> V_49 ;
T_4 V_69 = V_2 -> V_69 ;
F_59 ( V_70 , V_69 , V_49 ,
V_71 ) ;
F_60 ( & V_2 -> V_64 ) ;
V_2 -> V_1 . V_33 = & V_72 ;
V_2 -> V_1 . V_73 = V_74 ;
F_61 ( & V_2 -> V_1 ) ;
V_2 -> V_1 . V_75 = F_14 ;
F_43 ( & V_2 -> V_1 ) ;
F_62 ( & V_2 -> V_58 ) ;
V_2 -> V_58 . V_76 = ( unsigned long ) ( V_2 ) ;
V_2 -> V_58 . V_77 = F_40 ;
F_63 ( & V_2 -> V_1 , L_9 ,
V_49 , V_69 ) ;
V_68 = F_64 ( & V_2 -> V_1 ) ;
if ( V_68 < 0 ) {
F_59 ( V_78 , 0 , V_49 ,
V_79 ) ;
goto V_80;
}
F_65 ( & V_2 -> V_81 , & V_82 ) ;
return 0 ;
V_80:
F_47 ( & V_2 -> V_1 ) ;
return V_68 ;
}
static void
F_66 ( struct V_6 * V_2 )
{
F_67 ( & V_2 -> V_81 ) ;
F_47 ( & V_2 -> V_1 ) ;
F_68 ( & V_2 -> V_1 ) ;
}
static int
F_69 ( struct V_9 * V_83 ,
struct V_84 * V_85 )
{
if ( ! F_70 ( F_71 ( V_83 ) ) )
return - V_86 ;
if ( F_35 ( V_83 , sizeof( struct V_87 ) , V_85 ,
sizeof( * V_85 ) ) < 0 ) {
return - V_88 ;
}
if ( V_85 -> V_89 < sizeof( struct V_84 ) )
return - V_86 ;
if ( V_85 -> V_90 <
sizeof( struct V_47 ) ) {
return - V_86 ;
}
return 0 ;
}
static void
F_72 ( struct V_9 * V_83 ,
struct V_84 * V_85 ,
struct V_47 * V_91 )
{
int V_46 = sizeof( struct V_87 ) + V_85 -> V_92 ;
if ( V_85 -> V_92 == 0 )
return;
F_55 ( V_83 , V_46 , V_91 , sizeof( * V_91 ) ) ;
}
static void
F_73 ( struct V_9 * V_83 ,
struct V_84 * V_85 ,
struct V_47 * V_91 )
{
int V_46 = sizeof( struct V_87 ) + V_85 -> V_93 ;
if ( V_85 -> V_93 == 0 )
return;
F_55 ( V_83 , V_46 , V_91 , sizeof( * V_91 ) ) ;
}
static void
F_74 ( struct V_9 * V_83 ,
struct V_84 * V_85 ,
struct V_47 * V_91 , unsigned int V_94 )
{
int V_46 =
( sizeof( struct V_87 ) + V_85 -> V_95 ) +
( V_85 -> V_90 * V_94 ) ;
if ( V_85 -> V_95 == 0 )
return;
F_55 ( V_83 , V_46 , V_91 , sizeof( * V_91 ) ) ;
}
static void
F_75 ( struct V_6 * V_96 )
{
int V_18 ;
struct V_6 * V_97 ;
struct V_19 * V_98 ;
T_4 V_99 = V_96 -> V_49 ;
T_4 V_100 = V_96 -> V_69 ;
struct V_47 V_48 ;
const char * V_101 = NULL ;
struct V_84 * V_85 ;
if ( ! V_96 -> V_1 . V_34 )
return;
V_97 = F_76 ( V_99 , V_102 , NULL ) ;
if ( ! V_97 )
return;
V_85 = (struct V_84 * ) V_97 -> V_103 ;
if ( ! V_85 )
return;
V_98 = F_7 ( V_96 -> V_1 . V_34 ) ;
for ( V_18 = 0 ; V_98 -> V_23 [ V_18 ] . V_25 ; V_18 ++ ) {
if ( memcmp ( & V_98 -> V_23 [ V_18 ] . V_8 ,
& V_96 -> V_104 ,
sizeof( V_98 -> V_23 [ V_18 ] . V_8 ) ) == 0 ) {
V_101 = V_98 -> V_23 [ V_18 ] . V_25 ;
break;
}
}
F_77 ( & V_48 , V_101 , V_98 -> V_25 ) ;
F_74 ( V_97 -> V_9 , V_85 , & V_48 , V_100 ) ;
F_72 ( V_97 -> V_9 , V_85 , & V_105 ) ;
F_73 ( V_97 -> V_9 , V_85 ,
& V_106 ) ;
}
static int
F_78 ( struct V_1 * V_11 )
{
int V_107 ;
struct V_19 * V_20 ;
struct V_6 * V_2 ;
V_20 = F_7 ( V_11 -> V_34 ) ;
V_2 = F_2 ( V_11 ) ;
if ( ! V_20 -> V_108 )
return - V_109 ;
F_49 ( & V_2 -> V_64 ) ;
V_2 -> V_61 = false ;
V_107 = V_20 -> V_108 ( V_2 ) ;
if ( V_107 >= 0 ) {
F_43 ( & V_2 -> V_1 ) ;
F_75 ( V_2 ) ;
}
F_50 ( & V_2 -> V_64 ) ;
return V_107 ;
}
int F_79 ( struct V_19 * V_20 )
{
int V_110 = 0 ;
if ( V_111 < 0 )
return - V_109 ;
V_20 -> V_34 . V_25 = V_20 -> V_25 ;
V_20 -> V_34 . V_33 = & V_72 ;
V_20 -> V_34 . V_108 = F_78 ;
V_20 -> V_34 . remove = F_48 ;
V_20 -> V_34 . V_112 = V_20 -> V_112 ;
V_110 = F_80 ( & V_20 -> V_34 ) ;
if ( V_110 < 0 )
F_52 ( & V_20 -> V_34 ) ;
return V_110 ;
}
static int
F_81 ( struct V_6 * V_2 )
{
int V_113 = V_2 -> V_49 ;
int V_68 ;
struct V_84 * V_85 ;
F_59 ( V_114 , 0 , 0 , V_71 ) ;
V_85 = F_82 ( sizeof( * V_85 ) , V_115 ) ;
if ( ! V_85 )
return - V_14 ;
F_63 ( & V_2 -> V_1 , L_10 , V_113 ) ;
V_2 -> V_1 . V_33 = & V_72 ;
V_2 -> V_1 . V_73 = V_116 ;
V_2 -> V_1 . V_75 = F_9 ;
V_2 -> V_27 = F_83 ( F_84 ( & V_2 -> V_1 ) ,
V_117 ) ;
if ( ! V_2 -> V_27 ) {
V_68 = - V_14 ;
goto V_118;
}
V_2 -> V_26 =
F_85 ( L_11 , V_119 | V_120 ,
V_2 -> V_27 , V_2 ,
& V_121 ) ;
if ( ! V_2 -> V_26 ) {
V_68 = - V_14 ;
goto V_122;
}
if ( F_86 ( & V_2 -> V_1 ) < 0 ) {
F_59 ( V_123 , 0 , V_113 ,
V_79 ) ;
V_68 = - V_109 ;
goto V_124;
}
if ( F_69 ( V_2 -> V_9 , V_85 ) >= 0 ) {
V_2 -> V_103 = ( void * ) V_85 ;
F_72 ( V_2 -> V_9 , V_85 ,
& V_105 ) ;
F_73 ( V_2 -> V_9 , V_85 ,
& V_106 ) ;
} else {
F_13 ( V_85 ) ;
}
F_65 ( & V_2 -> V_81 , & V_125 ) ;
F_87 ( & V_2 -> V_1 , V_2 ) ;
return 0 ;
V_124:
F_11 ( V_2 -> V_26 ) ;
V_122:
F_12 ( V_2 -> V_27 ) ;
V_118:
F_13 ( V_85 ) ;
return V_68 ;
}
static void
F_88 ( struct V_6 * V_2 )
{
if ( V_2 -> V_9 ) {
F_15 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
F_13 ( V_2 -> V_103 ) ;
F_67 ( & V_2 -> V_81 ) ;
F_68 ( & V_2 -> V_1 ) ;
}
static int
F_89 ( void )
{
V_111 = F_90 ( & V_72 ) ;
return V_111 ;
}
static void
F_91 ( void )
{
F_92 ( & V_72 ) ;
}
static void
F_93 ( void )
{
struct V_126 * V_127 , * V_128 ;
F_94 (listentry, listtmp, &list_all_device_instances) {
struct V_6 * V_2 = F_95 ( V_127 ,
struct V_6 ,
V_81 ) ;
F_66 ( V_2 ) ;
}
}
void
F_96 ( struct V_6 * V_2 )
{
int V_110 ;
T_4 V_99 = V_2 -> V_49 ;
F_59 ( V_114 , 0 , V_99 , V_71 ) ;
V_110 = F_81 ( V_2 ) ;
F_59 ( V_129 , 0 , V_99 , V_71 ) ;
if ( V_110 < 0 )
F_59 ( V_130 , 0 , V_99 ,
V_79 ) ;
else
F_59 ( V_131 , 0 , V_99 ,
V_71 ) ;
F_97 ( V_2 , V_110 ) ;
}
void
F_98 ( struct V_6 * V_2 )
{
F_88 ( V_2 ) ;
F_99 ( V_2 , 0 ) ;
}
void
F_100 ( struct V_6 * V_48 )
{
int V_110 ;
T_4 V_99 = V_48 -> V_49 ;
T_4 V_100 = V_48 -> V_69 ;
F_59 ( V_70 , V_100 , V_99 ,
V_71 ) ;
V_110 = F_58 ( V_48 ) ;
F_101 ( V_48 , V_110 ) ;
if ( V_110 < 0 )
F_59 ( V_123 , V_100 , V_99 ,
V_79 ) ;
else
F_59 ( V_132 , V_100 , V_99 ,
V_71 ) ;
}
void
F_102 ( struct V_6 * V_48 )
{
F_66 ( V_48 ) ;
F_103 ( V_48 , 0 ) ;
}
static void
F_104 ( struct V_6 * V_2 , int V_133 )
{
if ( ! V_2 -> V_134 )
return;
V_2 -> V_134 = false ;
F_105 ( V_2 , V_133 ) ;
}
static void
F_106 ( struct V_6 * V_2 , int V_133 )
{
if ( ! V_2 -> V_135 )
return;
V_2 -> V_135 = false ;
F_107 ( V_2 , V_133 ) ;
}
static void
F_108 ( struct V_6 * V_2 , bool V_136 )
{
int V_110 ;
struct V_19 * V_20 = NULL ;
void (* F_109)( struct V_6 * V_2 , int V_137 ) = NULL ;
if ( V_136 )
F_109 = F_105 ;
else
F_109 = F_107 ;
if ( ! F_109 )
return;
V_20 = F_7 ( V_2 -> V_1 . V_34 ) ;
if ( ! V_20 ) {
(* F_109)( V_2 , - V_109 ) ;
return;
}
if ( V_2 -> V_134 || V_2 -> V_135 ) {
(* F_109)( V_2 , - V_138 ) ;
return;
}
if ( V_136 ) {
if ( ! V_20 -> V_139 ) {
(* F_109)( V_2 , - V_86 ) ;
return;
}
V_2 -> V_134 = true ;
V_110 = V_20 -> V_139 ( V_2 , F_104 ) ;
} else {
F_75 ( V_2 ) ;
if ( ! V_20 -> V_140 ) {
(* F_109)( V_2 , - V_86 ) ;
return;
}
V_2 -> V_135 = true ;
V_110 = V_20 -> V_140 ( V_2 , F_106 ) ;
}
if ( V_110 < 0 ) {
if ( V_136 )
V_2 -> V_134 = false ;
else
V_2 -> V_135 = false ;
(* F_109)( V_2 , - V_86 ) ;
}
}
void
F_110 ( struct V_6 * V_48 )
{
F_108 ( V_48 , true ) ;
}
void
F_111 ( struct V_6 * V_48 )
{
F_108 ( V_48 , false ) ;
}
int
F_112 ( void )
{
int V_68 ;
F_59 ( V_141 , 0 , 0 , V_71 ) ;
V_117 = F_83 ( L_12 , NULL ) ;
if ( ! V_117 )
return - V_14 ;
F_77 ( & V_106 , L_13 , L_12 ) ;
V_68 = F_89 () ;
if ( V_68 < 0 ) {
F_59 ( V_114 , 0 , 0 , V_79 ) ;
goto error;
}
F_77 ( & V_105 , L_14 , L_15 ) ;
return 0 ;
error:
F_59 ( V_142 , 0 , V_68 , V_79 ) ;
return V_68 ;
}
void
F_113 ( void )
{
struct V_126 * V_127 , * V_128 ;
F_93 () ;
F_94 (listentry, listtmp, &list_all_bus_instances) {
struct V_6 * V_2 = F_95 ( V_127 ,
struct V_6 ,
V_81 ) ;
F_88 ( V_2 ) ;
}
F_91 () ;
F_12 ( V_117 ) ;
}
