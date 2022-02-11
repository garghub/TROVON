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
F_11 ( V_2 ) ;
}
static void
F_12 ( struct V_1 * V_11 )
{
struct V_6 * V_2 = F_2 ( V_11 ) ;
if ( V_2 -> V_9 ) {
F_13 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
F_11 ( V_2 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 -> V_9 )
return 0 ;
return snprintf ( V_5 , V_10 , L_3 ,
F_15 ( V_7 -> V_9 ) ) ;
}
static T_1 F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 -> V_9 )
return 0 ;
return snprintf ( V_5 , V_10 , L_4 ,
F_17 ( V_7 -> V_9 ) ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! V_7 -> V_9 )
return 0 ;
return snprintf ( V_5 , V_10 , L_3 ,
F_19 ( V_7 -> V_9 ) ) ;
}
static T_1 F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char V_26 [ V_27 ] ;
if ( ! V_7 -> V_9 )
return 0 ;
return snprintf ( V_5 , V_10 , L_5 ,
F_21 ( V_7 -> V_9 , V_26 ) ) ;
}
static T_1 F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
char V_28 [ V_27 ] ;
if ( ! V_7 -> V_9 )
return 0 ;
return snprintf ( V_5 , V_10 , L_5 ,
F_23 ( V_7 -> V_9 , V_28 ) ) ;
}
static T_1 F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_18 = 0 ;
struct V_29 * V_30 = V_2 -> V_31 ;
struct V_15 * V_16 = V_2 -> V_32 ;
struct V_19 * V_20 = NULL ;
if ( ! V_7 -> V_9 || ! V_30 || ! V_16 )
return 0 ;
V_18 = V_30 -> V_33 ( V_2 , V_16 ) ;
if ( ! V_18 )
return 0 ;
V_20 = F_7 ( V_16 ) ;
return snprintf ( V_5 , V_10 , L_5 , V_20 -> V_23 [ V_18 - 1 ] . V_25 ) ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_34 = F_19 ( V_7 -> V_9 ) ;
return snprintf ( V_5 , V_10 , L_3 , V_34 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_10 , L_6 , & V_7 -> V_35 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_10 , L_5 , V_7 -> V_25 ) ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_36 = F_15 ( V_7 -> V_9 ) ;
return snprintf ( V_5 , V_10 , L_3 , V_36 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_37 = F_17 ( V_7 -> V_9 ) ;
return snprintf ( V_5 , V_10 , L_3 , V_37 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_38 = 0 ;
if ( V_7 -> V_9 ) {
F_21 ( V_7 -> V_9 , V_5 ) ;
V_38 = strlen ( V_5 ) ;
V_5 [ V_38 ++ ] = '\n' ;
}
return V_38 ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_9 * V_39 = V_7 -> V_9 ;
int V_18 , V_40 , V_41 = V_10 ;
unsigned long V_42 ;
char * V_43 = V_5 ;
T_4 * V_44 ;
struct V_45 V_46 ;
V_44 = L_7 ;
if ( V_39 ) {
if ( V_7 -> V_25 )
V_44 = V_7 -> V_25 ;
V_40 = snprintf ( V_43 , V_41 ,
L_8 ,
V_44 , V_7 -> V_47 ) ;
V_43 += V_40 ;
V_41 -= V_40 ;
V_40 = F_32 ( V_39 ,
F_33 ( struct
V_48 ,
V_49 ) ,
& V_46 , sizeof( V_46 ) ) ;
if ( V_40 >= 0 ) {
V_40 = F_34 ( & V_46 , V_43 ,
V_41 , - 1 ) ;
V_43 += V_40 ;
V_41 -= V_40 ;
}
V_40 = F_32 ( V_39 ,
F_33 ( struct
V_48 ,
V_50 ) ,
& V_46 , sizeof( V_46 ) ) ;
if ( V_40 >= 0 ) {
V_40 = F_34 ( & V_46 , V_43 ,
V_41 , - 1 ) ;
V_43 += V_40 ;
V_41 -= V_40 ;
}
V_42 = F_33 ( struct V_48 , V_46 ) ;
V_18 = 0 ;
while ( V_42 + sizeof( V_46 ) <=
F_17 ( V_39 ) ) {
V_40 = F_32 ( V_39 ,
V_42 , & V_46 ,
sizeof( V_46 ) ) ;
if ( V_40 >= 0 ) {
V_40 = F_34
( & V_46 , V_43 , V_41 , V_18 ) ;
V_43 += V_40 ;
V_41 -= V_40 ;
}
V_42 += sizeof( V_46 ) ;
V_18 ++ ;
}
}
return V_10 - V_41 ;
}
static void
F_35 ( unsigned long V_51 )
{
struct V_6 * V_2 = (struct V_6 * ) V_51 ;
struct V_19 * V_20 = F_7 ( V_2 -> V_1 . V_32 ) ;
if ( V_20 -> V_52 )
V_20 -> V_52 ( V_2 ) ;
F_36 ( & V_2 -> V_53 , V_54 + V_55 ) ;
}
static void
F_37 ( struct V_6 * V_2 )
{
if ( V_2 -> V_56 || V_2 -> V_57 )
return;
F_38 ( & V_2 -> V_1 ) ;
V_2 -> V_53 . V_58 = V_54 + V_55 ;
F_39 ( & V_2 -> V_53 ) ;
V_2 -> V_57 = true ;
}
static void
F_40 ( struct V_6 * V_2 )
{
if ( ! V_2 -> V_57 )
return;
F_41 ( & V_2 -> V_53 ) ;
V_2 -> V_57 = false ;
F_42 ( & V_2 -> V_1 ) ;
}
static int
F_43 ( struct V_1 * V_11 )
{
struct V_6 * V_2 ;
struct V_19 * V_20 ;
V_2 = F_2 ( V_11 ) ;
V_20 = F_7 ( V_11 -> V_32 ) ;
F_44 ( & V_2 -> V_59 ) ;
V_2 -> V_56 = true ;
if ( V_20 -> remove )
V_20 -> remove ( V_2 ) ;
F_45 ( & V_2 -> V_59 ) ;
F_40 ( V_2 ) ;
F_42 ( & V_2 -> V_1 ) ;
return 0 ;
}
void
F_46 ( struct V_19 * V_20 )
{
F_47 ( & V_20 -> V_32 ) ;
}
int
F_48 ( struct V_6 * V_2 , unsigned long V_60 ,
void * V_61 , unsigned long V_37 )
{
return F_32 ( V_2 -> V_9 , V_60 , V_61 , V_37 ) ;
}
int
F_49 ( struct V_6 * V_2 , unsigned long V_60 ,
void * V_62 , unsigned long V_37 )
{
return F_50 ( V_2 -> V_9 , V_60 , V_62 , V_37 ) ;
}
void
F_51 ( struct V_6 * V_2 )
{
F_37 ( V_2 ) ;
}
void
F_52 ( struct V_6 * V_2 )
{
F_40 ( V_2 ) ;
}
static int
F_53 ( struct V_6 * V_2 )
{
int V_63 ;
T_5 V_47 = V_2 -> V_47 ;
T_5 V_64 = V_2 -> V_64 ;
F_54 ( V_65 , V_64 , V_47 ,
V_66 ) ;
F_55 ( & V_2 -> V_59 ) ;
V_2 -> V_1 . V_31 = & V_67 ;
V_2 -> V_1 . V_68 = V_69 ;
F_56 ( & V_2 -> V_1 ) ;
V_2 -> V_1 . V_70 = F_12 ;
F_38 ( & V_2 -> V_1 ) ;
F_57 ( & V_2 -> V_53 ) ;
V_2 -> V_53 . V_71 = ( unsigned long ) ( V_2 ) ;
V_2 -> V_53 . V_72 = F_35 ;
F_58 ( & V_2 -> V_1 , L_9 ,
V_47 , V_64 ) ;
V_63 = F_59 ( & V_2 -> V_1 ) ;
if ( V_63 < 0 ) {
F_60 ( V_73 , V_47 ,
V_74 ) ;
goto V_75;
}
F_61 ( & V_2 -> V_76 , & V_77 ) ;
return 0 ;
V_75:
F_42 ( & V_2 -> V_1 ) ;
return V_63 ;
}
static void
F_62 ( struct V_6 * V_2 )
{
F_63 ( & V_2 -> V_76 ) ;
F_42 ( & V_2 -> V_1 ) ;
F_64 ( & V_2 -> V_1 ) ;
}
static int
F_65 ( struct V_9 * V_78 ,
struct V_79 * V_80 )
{
if ( ! F_66 ( F_67 ( V_78 ) ) )
return - V_81 ;
if ( F_32 ( V_78 , sizeof( struct V_82 ) , V_80 ,
sizeof( * V_80 ) ) < 0 ) {
return - V_83 ;
}
if ( V_80 -> V_84 < sizeof( struct V_79 ) )
return - V_81 ;
if ( V_80 -> V_85 <
sizeof( struct V_45 ) ) {
return - V_81 ;
}
return 0 ;
}
static void
F_68 ( struct V_9 * V_78 ,
struct V_79 * V_80 ,
struct V_45 * V_86 )
{
int V_42 = sizeof( struct V_82 ) + V_80 -> V_87 ;
if ( V_80 -> V_87 == 0 )
return;
F_50 ( V_78 , V_42 , V_86 , sizeof( * V_86 ) ) ;
}
static void
F_69 ( struct V_9 * V_78 ,
struct V_79 * V_80 ,
struct V_45 * V_86 )
{
int V_42 = sizeof( struct V_82 ) + V_80 -> V_88 ;
if ( V_80 -> V_88 == 0 )
return;
F_50 ( V_78 , V_42 , V_86 , sizeof( * V_86 ) ) ;
}
static void
F_70 ( struct V_9 * V_78 ,
struct V_79 * V_80 ,
struct V_45 * V_86 , unsigned int V_89 )
{
int V_42 =
( sizeof( struct V_82 ) + V_80 -> V_90 ) +
( V_80 -> V_85 * V_89 ) ;
if ( V_80 -> V_90 == 0 )
return;
F_50 ( V_78 , V_42 , V_86 , sizeof( * V_86 ) ) ;
}
static void
F_71 ( struct V_6 * V_91 )
{
int V_18 ;
struct V_6 * V_92 ;
struct V_19 * V_93 ;
T_5 V_94 = V_91 -> V_47 ;
T_5 V_95 = V_91 -> V_64 ;
struct V_45 V_46 ;
const char * V_96 = NULL ;
struct V_79 * V_80 ;
if ( ! V_91 -> V_1 . V_32 )
return;
V_92 = F_72 ( V_94 , V_97 , NULL ) ;
if ( ! V_92 )
return;
V_80 = (struct V_79 * ) V_92 -> V_98 ;
if ( ! V_80 )
return;
V_93 = F_7 ( V_91 -> V_1 . V_32 ) ;
for ( V_18 = 0 ; V_93 -> V_23 [ V_18 ] . V_25 ; V_18 ++ ) {
if ( memcmp ( & V_93 -> V_23 [ V_18 ] . V_8 ,
& V_91 -> V_99 ,
sizeof( V_93 -> V_23 [ V_18 ] . V_8 ) ) == 0 ) {
V_96 = V_93 -> V_23 [ V_18 ] . V_25 ;
break;
}
}
F_73 ( & V_46 , V_96 , V_93 -> V_25 ) ;
F_70 ( V_92 -> V_9 , V_80 , & V_46 , V_95 ) ;
F_68 ( V_92 -> V_9 , V_80 , & V_100 ) ;
F_69 ( V_92 -> V_9 , V_80 ,
& V_101 ) ;
}
static int
F_74 ( struct V_1 * V_11 )
{
int V_102 ;
struct V_19 * V_20 ;
struct V_6 * V_2 ;
V_20 = F_7 ( V_11 -> V_32 ) ;
V_2 = F_2 ( V_11 ) ;
if ( ! V_20 -> V_103 )
return - V_104 ;
F_44 ( & V_2 -> V_59 ) ;
V_2 -> V_56 = false ;
V_102 = V_20 -> V_103 ( V_2 ) ;
if ( V_102 >= 0 ) {
F_38 ( & V_2 -> V_1 ) ;
F_71 ( V_2 ) ;
}
F_45 ( & V_2 -> V_59 ) ;
return V_102 ;
}
int F_75 ( struct V_19 * V_20 )
{
int V_105 = 0 ;
if ( V_106 < 0 )
return - V_104 ;
V_20 -> V_32 . V_25 = V_20 -> V_25 ;
V_20 -> V_32 . V_31 = & V_67 ;
V_20 -> V_32 . V_103 = F_74 ;
V_20 -> V_32 . remove = F_43 ;
V_20 -> V_32 . V_107 = V_20 -> V_107 ;
V_105 = F_76 ( & V_20 -> V_32 ) ;
if ( V_105 < 0 )
F_47 ( & V_20 -> V_32 ) ;
return V_105 ;
}
static int
F_77 ( struct V_6 * V_2 )
{
int V_108 = V_2 -> V_47 ;
struct V_79 * V_80 ;
F_78 ( V_109 , V_66 ) ;
V_80 = F_79 ( sizeof( * V_80 ) , V_110 ) ;
if ( ! V_80 )
return - V_14 ;
F_58 ( & V_2 -> V_1 , L_10 , V_108 ) ;
V_2 -> V_1 . V_31 = & V_67 ;
V_2 -> V_1 . V_68 = V_111 ;
V_2 -> V_1 . V_70 = F_9 ;
if ( F_80 ( & V_2 -> V_1 ) < 0 ) {
F_60 ( V_112 , V_108 ,
V_113 ) ;
F_11 ( V_80 ) ;
return - V_104 ;
}
if ( F_65 ( V_2 -> V_9 , V_80 ) >= 0 ) {
V_2 -> V_98 = ( void * ) V_80 ;
F_68 ( V_2 -> V_9 , V_80 ,
& V_100 ) ;
F_69 ( V_2 -> V_9 , V_80 ,
& V_101 ) ;
} else {
F_11 ( V_80 ) ;
}
F_61 ( & V_2 -> V_76 , & V_114 ) ;
F_81 ( & V_2 -> V_1 , V_2 ) ;
return 0 ;
}
static void
F_82 ( struct V_6 * V_2 )
{
if ( V_2 -> V_9 ) {
F_13 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
F_11 ( V_2 -> V_98 ) ;
F_63 ( & V_2 -> V_76 ) ;
F_64 ( & V_2 -> V_1 ) ;
}
static int
F_83 ( void )
{
V_106 = F_84 ( & V_67 ) ;
return V_106 ;
}
static void
F_85 ( void )
{
F_86 ( & V_67 ) ;
}
static void
F_87 ( void )
{
struct V_115 * V_116 , * V_117 ;
F_88 (listentry, listtmp, &list_all_device_instances) {
struct V_6 * V_2 = F_89 ( V_116 ,
struct V_6 ,
V_76 ) ;
F_62 ( V_2 ) ;
}
}
void
F_90 ( struct V_6 * V_2 )
{
int V_105 ;
T_5 V_94 = V_2 -> V_47 ;
F_60 ( V_109 , V_94 , V_66 ) ;
V_105 = F_77 ( V_2 ) ;
F_60 ( V_118 , V_94 , V_66 ) ;
if ( V_105 < 0 )
F_60 ( V_119 , V_94 ,
V_113 ) ;
else
F_60 ( V_120 , V_94 ,
V_66 ) ;
F_91 ( V_2 , V_105 ) ;
}
void
F_92 ( struct V_6 * V_2 )
{
F_82 ( V_2 ) ;
F_93 ( V_2 , 0 ) ;
}
void
F_94 ( struct V_6 * V_46 )
{
int V_105 ;
T_5 V_94 = V_46 -> V_47 ;
T_5 V_95 = V_46 -> V_64 ;
F_54 ( V_65 , V_95 , V_94 ,
V_66 ) ;
V_105 = F_53 ( V_46 ) ;
F_95 ( V_46 , V_105 ) ;
if ( V_105 < 0 )
F_54 ( V_112 , V_95 , V_94 ,
V_113 ) ;
else
F_54 ( V_121 , V_95 , V_94 ,
V_66 ) ;
}
void
F_96 ( struct V_6 * V_46 )
{
F_62 ( V_46 ) ;
F_97 ( V_46 , 0 ) ;
}
static void
F_98 ( struct V_6 * V_2 , int V_122 )
{
if ( ! V_2 -> V_123 )
return;
V_2 -> V_123 = false ;
F_99 ( V_2 , V_122 ) ;
}
static void
F_100 ( struct V_6 * V_2 , int V_122 )
{
if ( ! V_2 -> V_124 )
return;
V_2 -> V_124 = false ;
F_101 ( V_2 , V_122 ) ;
}
static void
F_102 ( struct V_6 * V_2 , bool V_125 )
{
int V_105 ;
struct V_19 * V_20 = NULL ;
void (* F_103)( struct V_6 * V_2 , int V_126 ) = NULL ;
if ( V_125 )
F_103 = F_99 ;
else
F_103 = F_101 ;
if ( ! F_103 )
return;
V_20 = F_7 ( V_2 -> V_1 . V_32 ) ;
if ( ! V_20 ) {
(* F_103)( V_2 , - V_104 ) ;
return;
}
if ( V_2 -> V_123 || V_2 -> V_124 ) {
(* F_103)( V_2 , - V_127 ) ;
return;
}
if ( V_125 ) {
if ( ! V_20 -> V_128 ) {
(* F_103)( V_2 , - V_81 ) ;
return;
}
V_2 -> V_123 = true ;
V_105 = V_20 -> V_128 ( V_2 , F_98 ) ;
} else {
F_71 ( V_2 ) ;
if ( ! V_20 -> V_129 ) {
(* F_103)( V_2 , - V_81 ) ;
return;
}
V_2 -> V_124 = true ;
V_105 = V_20 -> V_129 ( V_2 , F_100 ) ;
}
if ( V_105 < 0 ) {
if ( V_125 )
V_2 -> V_123 = false ;
else
V_2 -> V_124 = false ;
(* F_103)( V_2 , - V_81 ) ;
}
}
void
F_104 ( struct V_6 * V_46 )
{
F_102 ( V_46 , true ) ;
}
void
F_105 ( struct V_6 * V_46 )
{
F_102 ( V_46 , false ) ;
}
int
F_106 ( void )
{
int V_63 ;
F_60 ( V_130 , 0 , V_66 ) ;
F_73 ( & V_101 , L_11 , L_12 ) ;
V_63 = F_83 () ;
if ( V_63 < 0 ) {
F_78 ( V_109 , V_74 ) ;
goto error;
}
F_73 ( & V_100 , L_13 , L_14 ) ;
return 0 ;
error:
F_60 ( V_131 , V_63 , V_113 ) ;
return V_63 ;
}
void
F_107 ( void )
{
struct V_115 * V_116 , * V_117 ;
F_87 () ;
F_88 (listentry, listtmp, &list_all_bus_instances) {
struct V_6 * V_2 = F_89 ( V_116 ,
struct V_6 ,
V_76 ) ;
F_82 ( V_2 ) ;
}
F_85 () ;
}
