static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_1 , V_5 ) ;
}
static T_1 F_2 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_3 )
{
struct V_10 * V_11 ;
T_2 V_12 ;
V_11 = F_3 ( V_7 ) ;
V_12 = F_4 ( V_11 -> V_13 ) ;
return snprintf ( V_3 , V_4 , L_2 , & V_12 ) ;
}
static int
F_5 ( struct V_6 * V_14 , struct V_15 * V_16 )
{
struct V_10 * V_7 ;
T_2 V_12 ;
V_7 = F_3 ( V_14 ) ;
V_12 = F_4 ( V_7 -> V_13 ) ;
if ( F_6 ( V_16 , L_3 , & V_12 ) )
return - V_17 ;
return 0 ;
}
static int
F_7 ( struct V_6 * V_14 , struct V_18 * V_19 )
{
T_2 V_20 ;
int V_21 ;
struct V_10 * V_7 ;
struct V_22 * V_23 ;
V_7 = F_3 ( V_14 ) ;
V_23 = F_8 ( V_19 ) ;
V_20 = F_4 ( V_7 -> V_13 ) ;
if ( V_24 )
return 1 ;
if ( V_25 )
return 0 ;
if ( ! V_23 -> V_26 )
return 0 ;
for ( V_21 = 0 ;
( F_9 ( V_23 -> V_26 [ V_21 ] . V_12 , V_27 ) != 0 ) ||
( V_23 -> V_26 [ V_21 ] . V_28 ) ;
V_21 ++ )
if ( F_9 ( V_23 -> V_26 [ V_21 ] . V_12 ,
V_20 ) == 0 )
return V_21 + 1 ;
return 0 ;
}
static void
F_10 ( struct V_6 * V_14 )
{
struct V_10 * V_7 = F_11 ( V_14 ) ;
F_12 ( V_7 ) ;
}
static void
F_13 ( struct V_6 * V_14 )
{
struct V_10 * V_7 = F_3 ( V_14 ) ;
if ( V_7 -> V_29 ) {
F_14 ( V_7 -> V_29 ) ;
V_7 -> V_29 = NULL ;
}
if ( V_7 -> V_13 ) {
F_15 ( V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
}
F_12 ( V_7 ) ;
}
static T_1 F_16 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_3 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( ! V_11 -> V_13 )
return 0 ;
return snprintf ( V_3 , V_4 , L_4 ,
F_17 ( V_11 -> V_13 ) ) ;
}
static T_1 F_18 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_3 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( ! V_11 -> V_13 )
return 0 ;
return snprintf ( V_3 , V_4 , L_5 ,
F_19 ( V_11 -> V_13 ) ) ;
}
static T_1 F_20 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_3 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( ! V_11 -> V_13 )
return 0 ;
return snprintf ( V_3 , V_4 , L_4 ,
F_21 ( V_11 -> V_13 ) ) ;
}
static T_1 F_22 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_3 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
char V_30 [ V_31 ] ;
if ( ! V_11 -> V_13 )
return 0 ;
return snprintf ( V_3 , V_4 , L_1 ,
F_23 ( V_11 -> V_13 , V_30 ) ) ;
}
static T_1 F_24 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_3 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
char V_32 [ V_31 ] ;
if ( ! V_11 -> V_13 )
return 0 ;
return snprintf ( V_3 , V_4 , L_1 ,
F_25 ( V_11 -> V_13 , V_32 ) ) ;
}
static T_1 F_26 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_3 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
int V_21 = 0 ;
struct V_1 * V_33 = V_7 -> V_2 ;
struct V_18 * V_19 = V_7 -> V_34 ;
struct V_22 * V_23 = NULL ;
if ( ! V_11 -> V_13 || ! V_33 || ! V_19 )
return 0 ;
V_21 = V_33 -> V_35 ( V_7 , V_19 ) ;
if ( ! V_21 )
return 0 ;
V_23 = F_8 ( V_19 ) ;
return snprintf ( V_3 , V_4 , L_1 , V_23 -> V_26 [ V_21 - 1 ] . V_28 ) ;
}
static T_1 F_27 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
T_3 V_36 = F_21 ( V_11 -> V_13 ) ;
return snprintf ( V_3 , V_4 , L_4 , V_36 ) ;
}
static T_1 F_28 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
return snprintf ( V_3 , V_4 , L_6 , & V_11 -> V_37 ) ;
}
static T_1 F_29 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
return snprintf ( V_3 , V_4 , L_1 , V_11 -> V_28 ) ;
}
static T_1 F_30 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
T_3 V_38 = F_17 ( V_11 -> V_13 ) ;
return snprintf ( V_3 , V_4 , L_4 , V_38 ) ;
}
static T_1 F_31 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
T_3 V_39 = F_19 ( V_11 -> V_13 ) ;
return snprintf ( V_3 , V_4 , L_4 , V_39 ) ;
}
static T_1 F_32 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
int V_40 = 0 ;
if ( V_11 -> V_13 ) {
F_23 ( V_11 -> V_13 , V_3 ) ;
V_40 = strlen ( V_3 ) ;
V_3 [ V_40 ++ ] = '\n' ;
}
return V_40 ;
}
static T_1 F_33 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
struct V_13 * V_41 = V_11 -> V_13 ;
int V_21 , V_42 , V_43 = V_4 ;
unsigned long V_44 ;
char * V_45 = V_3 ;
T_4 * V_46 ;
struct V_47 V_48 ;
V_46 = L_7 ;
if ( V_41 ) {
if ( V_11 -> V_28 )
V_46 = V_11 -> V_28 ;
V_42 = snprintf ( V_45 , V_43 ,
L_8 ,
V_46 , V_11 -> V_49 ) ;
V_45 += V_42 ;
V_43 -= V_42 ;
V_42 = F_34 ( V_41 ,
F_35 ( struct
V_50 ,
V_51 ) ,
& V_48 , sizeof( V_48 ) ) ;
if ( V_42 >= 0 ) {
V_42 = F_36 ( & V_48 , V_45 ,
V_43 , - 1 ) ;
V_45 += V_42 ;
V_43 -= V_42 ;
}
V_42 = F_34 ( V_41 ,
F_35 ( struct
V_50 ,
V_52 ) ,
& V_48 , sizeof( V_48 ) ) ;
if ( V_42 >= 0 ) {
V_42 = F_36 ( & V_48 , V_45 ,
V_43 , - 1 ) ;
V_45 += V_42 ;
V_43 -= V_42 ;
}
V_44 = F_35 ( struct V_50 , V_48 ) ;
V_21 = 0 ;
while ( V_44 + sizeof( V_48 ) <=
F_19 ( V_41 ) ) {
V_42 = F_34 ( V_41 ,
V_44 , & V_48 ,
sizeof( V_48 ) ) ;
if ( V_42 >= 0 ) {
V_42 = F_36
( & V_48 , V_45 , V_43 , V_21 ) ;
V_45 += V_42 ;
V_43 -= V_42 ;
}
V_44 += sizeof( V_48 ) ;
V_21 ++ ;
}
}
return V_4 - V_43 ;
}
static T_1
F_37 ( struct V_18 * V_19 , char * V_3 )
{
struct V_22 * V_23 = F_8 ( V_19 ) ;
return snprintf ( V_3 , V_4 , L_1 , V_23 -> V_53 ) ;
}
static int
F_38 ( struct V_22 * V_23 )
{
struct V_54 V_53 =
F_39 ( V_53 , V_55 , F_37 , NULL ) ;
V_23 -> V_56 = V_53 ;
return F_40 ( & V_23 -> V_34 , & V_23 -> V_56 ) ;
}
static void
F_41 ( struct V_22 * V_23 )
{
F_42 ( & V_23 -> V_34 , & V_23 -> V_56 ) ;
}
static void
F_43 ( void * V_14 )
{
struct V_10 * V_7 = V_14 ;
struct V_22 * V_23 = F_8 ( V_7 -> V_6 . V_34 ) ;
F_44 ( & V_7 -> V_57 ) ;
if ( V_23 -> V_58 )
V_23 -> V_58 ( V_7 ) ;
F_45 ( & V_7 -> V_57 ) ;
if ( ! F_46 ( V_7 -> V_29 ) )
F_47 ( & V_7 -> V_6 ) ;
}
static void
F_48 ( struct V_10 * V_7 )
{
if ( V_7 -> V_59 )
return;
F_49 ( & V_7 -> V_6 ) ;
if ( ! F_50 ( V_7 -> V_29 ) )
F_47 ( & V_7 -> V_6 ) ;
}
static void
F_51 ( struct V_10 * V_7 )
{
if ( F_52 ( V_7 -> V_29 ) )
F_47 ( & V_7 -> V_6 ) ;
}
static int
F_53 ( struct V_6 * V_14 )
{
int V_60 ;
struct V_22 * V_23 ;
struct V_10 * V_7 ;
V_23 = F_8 ( V_14 -> V_34 ) ;
V_7 = F_3 ( V_14 ) ;
if ( ! V_23 -> V_61 )
return - V_62 ;
F_44 ( & V_7 -> V_57 ) ;
V_7 -> V_59 = false ;
V_60 = V_23 -> V_61 ( V_7 ) ;
if ( V_60 >= 0 ) {
F_49 ( & V_7 -> V_6 ) ;
F_54 ( V_7 ) ;
}
F_45 ( & V_7 -> V_57 ) ;
return V_60 ;
}
static int
F_55 ( struct V_6 * V_14 )
{
struct V_10 * V_7 ;
struct V_22 * V_23 ;
V_7 = F_3 ( V_14 ) ;
V_23 = F_8 ( V_14 -> V_34 ) ;
F_44 ( & V_7 -> V_57 ) ;
V_7 -> V_59 = true ;
if ( V_23 -> remove )
V_23 -> remove ( V_7 ) ;
F_45 ( & V_7 -> V_57 ) ;
F_51 ( V_7 ) ;
F_47 ( & V_7 -> V_6 ) ;
return 0 ;
}
int F_56 ( struct V_22 * V_23 )
{
int V_63 = 0 ;
if ( V_64 < 0 )
return - V_62 ;
V_23 -> V_34 . V_28 = V_23 -> V_28 ;
V_23 -> V_34 . V_2 = & V_65 ;
V_23 -> V_34 . V_61 = F_53 ;
V_23 -> V_34 . remove = F_55 ;
V_23 -> V_34 . V_66 = V_23 -> V_66 ;
V_63 = F_57 ( & V_23 -> V_34 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_38 ( V_23 ) ;
if ( V_63 < 0 )
F_58 ( & V_23 -> V_34 ) ;
return V_63 ;
}
void
F_59 ( struct V_22 * V_23 )
{
F_41 ( V_23 ) ;
F_58 ( & V_23 -> V_34 ) ;
}
int
F_60 ( struct V_10 * V_7 , unsigned long V_67 ,
void * V_68 , unsigned long V_39 )
{
return F_34 ( V_7 -> V_13 , V_67 , V_68 , V_39 ) ;
}
int
F_61 ( struct V_10 * V_7 , unsigned long V_67 ,
void * V_69 , unsigned long V_39 )
{
return F_62 ( V_7 -> V_13 , V_67 , V_69 , V_39 ) ;
}
int
F_63 ( struct V_10 * V_7 , unsigned long V_67 , T_4 V_70 ,
unsigned long V_39 )
{
return F_64 ( V_7 -> V_13 , V_67 , V_70 , V_39 ) ;
}
void
F_65 ( struct V_10 * V_7 )
{
F_48 ( V_7 ) ;
}
void
F_66 ( struct V_10 * V_7 )
{
F_51 ( V_7 ) ;
}
static int
F_67 ( struct V_10 * V_7 )
{
int V_71 ;
T_5 V_72 = V_7 -> V_72 ;
T_5 V_49 = V_7 -> V_49 ;
F_68 ( V_73 , V_49 , V_72 ,
V_74 ) ;
F_69 ( & V_7 -> V_57 , 1 ) ;
V_7 -> V_6 . V_2 = & V_65 ;
V_7 -> V_6 . V_75 = V_76 ;
F_70 ( & V_7 -> V_6 ) ;
V_7 -> V_6 . V_77 = F_13 ;
F_49 ( & V_7 -> V_6 ) ;
V_7 -> V_29 =
F_71 ( V_78 ,
V_79 ,
F_43 ,
V_7 , F_72 ( & V_7 -> V_6 ) ) ;
if ( ! V_7 -> V_29 ) {
F_73 ( V_80 , V_49 ,
V_81 ) ;
V_71 = - V_82 ;
goto V_83;
}
F_74 ( & V_7 -> V_6 , L_9 ,
V_72 , V_49 ) ;
V_71 = F_75 ( & V_7 -> V_6 ) ;
if ( V_71 < 0 ) {
F_73 ( V_84 , V_72 ,
V_81 ) ;
goto V_83;
}
F_76 ( & V_7 -> V_85 , & V_86 ) ;
return 0 ;
V_83:
F_47 ( & V_7 -> V_6 ) ;
return V_71 ;
}
static void
F_77 ( struct V_10 * V_7 )
{
F_78 ( & V_7 -> V_85 ) ;
F_47 ( & V_7 -> V_6 ) ;
F_79 ( & V_7 -> V_6 ) ;
}
static int
F_80 ( struct V_13 * V_87 ,
struct V_88 * V_89 )
{
if ( ! F_81 ( F_82 ( V_87 ) ) )
return - V_82 ;
if ( F_34 ( V_87 , sizeof( struct V_90 ) , V_89 ,
sizeof( * V_89 ) ) < 0 ) {
return - V_91 ;
}
if ( V_89 -> V_92 < sizeof( struct V_88 ) )
return - V_82 ;
if ( V_89 -> V_93 <
sizeof( struct V_47 ) ) {
return - V_82 ;
}
return 0 ;
}
static int
F_83 ( struct V_13 * V_87 ,
struct V_88 * V_89 ,
struct V_47 * V_94 )
{
int V_44 = sizeof( struct V_90 ) + V_89 -> V_95 ;
if ( V_89 -> V_95 == 0 )
return - 1 ;
if ( F_62 ( V_87 , V_44 , V_94 , sizeof( * V_94 ) ) < 0 )
return - 1 ;
return 0 ;
}
static int
F_84 ( struct V_13 * V_87 ,
struct V_88 * V_89 ,
struct V_47 * V_94 )
{
int V_44 = sizeof( struct V_90 ) + V_89 -> V_96 ;
if ( V_89 -> V_96 == 0 )
return - 1 ;
if ( F_62 ( V_87 , V_44 , V_94 , sizeof( * V_94 ) ) < 0 )
return - 1 ;
return 0 ;
}
static int
F_85 ( struct V_13 * V_87 ,
struct V_88 * V_89 ,
struct V_47 * V_94 , int V_97 )
{
int V_44 =
( sizeof( struct V_90 ) + V_89 -> V_98 ) +
( V_89 -> V_93 * V_97 ) ;
if ( V_89 -> V_98 == 0 )
return - 1 ;
if ( F_62 ( V_87 , V_44 , V_94 , sizeof( * V_94 ) ) < 0 )
return - 1 ;
return 0 ;
}
static void
F_54 ( struct V_10 * V_99 )
{
int V_21 ;
struct V_10 * V_100 ;
struct V_22 * V_101 ;
int V_102 = V_99 -> V_72 ;
int V_103 = V_99 -> V_49 ;
struct V_47 V_48 ;
const char * V_104 = NULL ;
struct V_88 * V_89 ;
if ( ! V_99 -> V_6 . V_34 )
return;
V_89 = (struct V_88 * ) V_99 -> V_105 ;
if ( ! V_89 )
return;
V_100 = F_86 ( V_102 , V_106 , NULL ) ;
if ( ! V_100 )
return;
V_101 = F_8 ( V_99 -> V_6 . V_34 ) ;
for ( V_21 = 0 ; V_101 -> V_26 [ V_21 ] . V_28 ; V_21 ++ ) {
if ( memcmp ( & V_101 -> V_26 [ V_21 ] . V_12 ,
& V_99 -> V_107 ,
sizeof( V_101 -> V_26 [ V_21 ] . V_12 ) ) == 0 ) {
V_104 = V_101 -> V_26 [ V_21 ] . V_28 ;
break;
}
}
F_87 ( & V_48 , V_104 ,
V_101 -> V_28 , V_101 -> V_53 ,
V_101 -> V_108 ) ;
F_85 ( V_100 -> V_13 , V_89 , & V_48 , V_103 ) ;
F_83 ( V_100 -> V_13 , V_89 , & V_109 ) ;
F_84 ( V_100 -> V_13 , V_89 ,
& V_110 ) ;
}
static int
F_88 ( struct V_10 * V_7 )
{
int V_111 = V_7 -> V_72 ;
struct V_88 * V_89 ;
F_89 ( V_112 , V_74 ) ;
V_89 = F_90 ( sizeof( * V_89 ) , V_113 ) ;
if ( ! V_89 )
return - V_17 ;
F_74 ( & V_7 -> V_6 , L_10 , V_111 ) ;
V_7 -> V_6 . V_2 = & V_65 ;
V_7 -> V_6 . V_75 = V_114 ;
V_7 -> V_6 . V_77 = F_10 ;
if ( F_91 ( & V_7 -> V_6 ) < 0 ) {
F_73 ( V_80 , V_111 ,
V_115 ) ;
F_12 ( V_89 ) ;
return - V_62 ;
}
if ( F_80 ( V_7 -> V_13 , V_89 ) >= 0 ) {
V_7 -> V_105 = ( void * ) V_89 ;
F_83 ( V_7 -> V_13 , V_89 ,
& V_109 ) ;
F_84 ( V_7 -> V_13 , V_89 ,
& V_110 ) ;
} else {
F_12 ( V_89 ) ;
}
V_116 ++ ;
F_76 ( & V_7 -> V_85 , & V_117 ) ;
F_92 ( & V_7 -> V_6 , V_7 ) ;
return 0 ;
}
static void
F_93 ( struct V_10 * V_7 )
{
V_116 -- ;
if ( V_7 -> V_13 ) {
F_15 ( V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
}
F_12 ( V_7 -> V_105 ) ;
F_78 ( & V_7 -> V_85 ) ;
F_79 ( & V_7 -> V_6 ) ;
}
static int
F_94 ( void )
{
V_64 = F_95 ( & V_65 ) ;
return V_64 ;
}
static void
F_96 ( void )
{
F_97 ( & V_65 ) ;
}
static void
F_98 ( void )
{
struct V_118 * V_119 , * V_120 ;
F_99 (listentry, listtmp, &list_all_device_instances) {
struct V_10 * V_7 = F_100 ( V_119 ,
struct V_10 ,
V_85 ) ;
F_77 ( V_7 ) ;
}
}
static void
F_101 ( struct V_10 * V_7 )
{
int V_63 ;
T_5 V_102 = V_7 -> V_72 ;
F_73 ( V_112 , V_102 , V_74 ) ;
V_63 = F_88 ( V_7 ) ;
F_73 ( V_121 , V_102 , V_74 ) ;
if ( V_63 < 0 )
F_73 ( V_122 , V_102 ,
V_115 ) ;
else
F_73 ( V_123 , V_102 ,
V_74 ) ;
if ( V_124 . V_125 )
(* V_124 . V_125 ) ( V_7 , V_63 ) ;
}
static void
F_102 ( struct V_10 * V_7 )
{
F_93 ( V_7 ) ;
if ( V_124 . V_126 )
(* V_124 . V_126 )( V_7 , 0 ) ;
}
static void
F_103 ( struct V_10 * V_48 )
{
int V_63 ;
T_5 V_102 = V_48 -> V_72 ;
T_5 V_103 = V_48 -> V_49 ;
F_68 ( V_73 , V_103 , V_102 ,
V_74 ) ;
V_63 = F_67 ( V_48 ) ;
if ( V_124 . V_127 )
V_124 . V_127 ( V_48 , V_63 ) ;
if ( V_63 < 0 )
F_68 ( V_80 , V_103 , V_102 ,
V_115 ) ;
else
F_68 ( V_128 , V_103 , V_102 ,
V_74 ) ;
}
static void
F_104 ( struct V_10 * V_48 )
{
F_77 ( V_48 ) ;
if ( V_124 . V_129 )
(* V_124 . V_129 ) ( V_48 , 0 ) ;
}
static void
F_105 ( struct V_10 * V_7 , int V_130 )
{
if ( ! V_7 -> V_131 )
return;
V_7 -> V_131 = false ;
if ( ! V_124 . V_132 )
return;
(* V_124 . V_132 ) ( V_7 , V_130 ) ;
}
static void
F_106 ( struct V_10 * V_7 , int V_130 )
{
if ( ! V_7 -> V_133 )
return;
V_7 -> V_133 = false ;
if ( ! V_124 . V_134 )
return;
(* V_124 . V_134 ) ( V_7 , V_130 ) ;
}
static void
F_107 ( struct V_10 * V_7 , bool V_135 )
{
int V_63 ;
struct V_22 * V_23 = NULL ;
void (* F_108)( struct V_10 * V_7 , int V_136 ) = NULL ;
if ( V_135 )
F_108 = V_124 . V_132 ;
else
F_108 = V_124 . V_134 ;
if ( ! F_108 )
return;
V_23 = F_8 ( V_7 -> V_6 . V_34 ) ;
if ( ! V_23 ) {
(* F_108)( V_7 , - V_62 ) ;
return;
}
if ( V_7 -> V_131 || V_7 -> V_133 ) {
(* F_108)( V_7 , - V_137 ) ;
return;
}
if ( V_135 ) {
if ( ! V_23 -> V_138 ) {
(* F_108)( V_7 , - V_82 ) ;
return;
}
V_7 -> V_131 = true ;
V_63 = V_23 -> V_138 ( V_7 , F_105 ) ;
} else {
F_54 ( V_7 ) ;
if ( ! V_23 -> V_139 ) {
(* F_108)( V_7 , - V_82 ) ;
return;
}
V_7 -> V_133 = true ;
V_63 = V_23 -> V_139 ( V_7 , F_106 ) ;
}
if ( V_63 < 0 ) {
if ( V_135 )
V_7 -> V_131 = false ;
else
V_7 -> V_133 = false ;
(* F_108)( V_7 , - V_82 ) ;
}
}
static void
F_109 ( struct V_10 * V_48 )
{
F_107 ( V_48 , true ) ;
}
static void
F_110 ( struct V_10 * V_48 )
{
F_107 ( V_48 , false ) ;
}
int
F_111 ( void )
{
int V_71 ;
F_73 ( V_140 , 0 , V_74 ) ;
F_87 ( & V_110 ,
L_11 , L_12 ,
V_5 , NULL ) ;
V_71 = F_94 () ;
if ( V_71 < 0 ) {
F_89 ( V_112 , V_81 ) ;
goto error;
}
V_79 = F_112 ( L_13 ) ;
if ( ! V_79 ) {
F_89 ( V_141 , V_81 ) ;
V_71 = - V_17 ;
goto error;
}
F_113 ( & V_142 ,
& V_124 ,
& V_109 ) ;
return 0 ;
error:
F_73 ( V_143 , V_71 , V_115 ) ;
return V_71 ;
}
void
F_114 ( void )
{
struct V_118 * V_119 , * V_120 ;
F_113 ( NULL , NULL , NULL ) ;
F_98 () ;
F_115 ( V_79 ) ;
F_116 ( V_79 ) ;
V_79 = NULL ;
if ( V_144 ) {
F_117 ( & V_29 ) ;
F_115 ( V_144 ) ;
F_116 ( V_144 ) ;
V_144 = NULL ;
}
F_99 (listentry, listtmp, &list_all_bus_instances) {
struct V_10 * V_7 = F_100 ( V_119 ,
struct V_10 ,
V_85 ) ;
F_93 ( V_7 ) ;
}
F_96 () ;
}
