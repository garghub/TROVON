static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_1 , V_5 ) ;
}
static int
F_2 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
if ( F_3 ( V_9 , L_2 , V_5 ) )
return - V_10 ;
return 0 ;
}
static int
F_4 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
T_2 V_13 ;
int V_14 = 0 ;
int V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
V_17 = F_5 ( V_7 ) ;
V_19 = F_6 ( V_12 ) ;
V_13 = F_7 ( V_17 -> V_20 ) ;
if ( V_21 ) {
V_14 = 1 ;
goto V_22;
}
if ( V_23 )
goto V_22;
if ( ! V_19 -> V_24 )
goto V_22;
for ( V_15 = 0 ;
( F_8 ( V_19 -> V_24 [ V_15 ] . V_25 , V_26 ) != 0 ) ||
( V_19 -> V_24 [ V_15 ] . V_27 ) ;
V_15 ++ )
if ( F_8 ( V_19 -> V_24 [ V_15 ] . V_25 ,
V_13 ) == 0 ) {
V_14 = V_15 + 1 ;
goto V_22;
}
V_22:
return V_14 ;
}
static void
F_9 ( struct V_6 * V_7 )
{
struct V_16 * V_17 = F_10 ( V_7 ) ;
F_11 ( V_7 , NULL ) ;
F_12 ( V_17 ) ;
}
static void
F_13 ( struct V_6 * V_7 )
{
struct V_16 * V_17 = F_5 ( V_7 ) ;
if ( V_17 -> V_28 ) {
F_14 ( V_17 -> V_28 ) ;
V_17 -> V_28 = NULL ;
}
if ( V_17 -> V_20 ) {
F_15 ( V_17 -> V_20 ) ;
V_17 -> V_20 = NULL ;
}
F_12 ( V_17 ) ;
}
static T_1 F_16 ( struct V_16 * V_17 , int V_29 , char * V_3 )
{
int V_30 = F_17 ( V_17 -> V_31 ) / sizeof( V_17 -> V_31 [ 0 ] ) ;
if ( V_29 < 0 || V_29 >= V_30 )
return 0 ;
return snprintf ( V_3 , V_4 , L_3 ,
V_17 -> V_31 [ V_29 ] . V_32 , V_17 -> V_31 [ V_29 ] . V_33 ) ;
}
static T_1
F_18 ( struct V_34 * V_35 , struct V_36 * V_37 , char * V_3 )
{
struct V_38 * V_39 =
F_19 ( V_37 ) ;
struct V_16 * V_17 = F_20 ( V_35 ) ;
T_1 V_40 = 0 ;
if ( V_39 -> V_41 )
V_40 = V_39 -> V_41 ( V_17 ,
V_39 -> V_29 , V_3 ) ;
return V_40 ;
}
static T_1
F_21 ( struct V_34 * V_35 ,
struct V_36 * V_37 , const char * V_3 , T_3 V_42 )
{
struct V_38 * V_39 =
F_19 ( V_37 ) ;
struct V_16 * V_17 = F_20 ( V_35 ) ;
T_1 V_40 = 0 ;
if ( V_39 -> V_43 )
V_40 = V_39 -> V_43 ( V_17 ,
V_39 -> V_29 ,
V_3 , V_42 ) ;
return V_40 ;
}
static int
F_22 ( struct V_16 * V_17 , const char * V_27 ,
int V_32 , int V_33 )
{
int V_30 = F_17 ( V_17 -> V_31 ) / sizeof( V_17 -> V_31 [ 0 ] ) ;
struct V_38 * V_44 = NULL ;
int V_45 = - 1 , V_14 = 0 , V_29 = - 1 ;
F_23 ( V_17 ) ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ )
if ( ! V_17 -> V_31 [ V_29 ] . V_37 )
break;
if ( V_29 == V_30 ) {
V_14 = - V_10 ;
goto V_22;
}
V_44 = F_24 ( sizeof( * V_44 ) , V_46 ) ;
if ( ! V_44 ) {
V_14 = - V_10 ;
goto V_22;
}
memset ( V_44 , 0 , sizeof( struct V_38 ) ) ;
V_44 -> V_41 = F_16 ;
V_44 -> V_43 = NULL ;
V_44 -> V_29 = V_29 ;
V_44 -> V_37 . V_27 = V_27 ;
V_44 -> V_37 . V_47 = V_48 ;
V_17 -> V_31 [ V_29 ] . V_37 = V_44 ;
V_17 -> V_31 [ V_29 ] . V_32 = V_32 ;
V_17 -> V_31 [ V_29 ] . V_33 = V_33 ;
V_45 = F_25 ( & V_17 -> V_49 , & V_44 -> V_37 ) ;
if ( V_45 < 0 ) {
V_14 = V_45 ;
goto V_22;
}
F_26 ( & V_17 -> V_6 . V_35 , V_50 ) ;
V_22:
if ( V_14 < 0 ) {
F_12 ( V_44 ) ;
V_44 = NULL ;
V_17 -> V_31 [ V_29 ] . V_37 = NULL ;
}
return V_14 ;
}
static void
F_27 ( struct V_16 * V_17 , int V_29 )
{
int V_30 = F_17 ( V_17 -> V_31 ) / sizeof( V_17 -> V_31 [ 0 ] ) ;
struct V_38 * V_44 = NULL ;
if ( V_29 < 0 || V_29 >= V_30 )
return;
V_44 = (struct V_38 * ) ( V_17 -> V_31 [ V_29 ] . V_37 ) ;
if ( ! V_44 )
return;
F_28 ( & V_17 -> V_49 , & V_44 -> V_37 ) ;
F_26 ( & V_17 -> V_6 . V_35 , V_51 ) ;
V_17 -> V_31 [ V_29 ] . V_37 = NULL ;
F_12 ( V_44 ) ;
}
static void
F_29 ( struct V_16 * V_17 )
{
int V_15 = 0 ;
int V_30 = F_17 ( V_17 -> V_31 ) / sizeof( V_17 -> V_31 [ 0 ] ) ;
for ( V_15 = 0 ; V_15 < V_30 ; V_15 ++ )
F_27 ( V_17 , V_15 ) ;
}
static int
F_23 ( struct V_16 * V_17 )
{
int V_14 = 0 , V_45 = 0 ;
if ( V_17 -> V_49 . V_52 )
goto V_22;
V_45 = F_30 ( & V_17 -> V_49 ,
& V_53 , & V_17 -> V_6 . V_35 ,
L_4 ) ;
if ( V_45 < 0 ) {
V_14 = V_45 ;
goto V_22;
}
F_26 ( & V_17 -> V_49 , V_54 ) ;
V_22:
return V_14 ;
}
static void
F_31 ( struct V_16 * V_17 )
{
if ( ! V_17 -> V_49 . V_52 )
return;
F_29 ( V_17 ) ;
F_32 ( & V_17 -> V_49 ) ;
F_33 ( & V_17 -> V_49 ) ;
V_17 -> V_49 . V_52 = NULL ;
}
static T_1 F_34 ( struct V_6 * V_17 , struct V_55 * V_37 ,
char * V_3 )
{
struct V_16 * V_56 = F_5 ( V_17 ) ;
if ( ! V_56 -> V_20 )
return 0 ;
return snprintf ( V_3 , V_4 , L_5 ,
F_35 ( V_56 -> V_20 ) ) ;
}
static T_1 F_36 ( struct V_6 * V_17 , struct V_55 * V_37 ,
char * V_3 )
{
struct V_16 * V_56 = F_5 ( V_17 ) ;
if ( ! V_56 -> V_20 )
return 0 ;
return snprintf ( V_3 , V_4 , L_6 ,
F_37 ( V_56 -> V_20 ) ) ;
}
static T_1 F_38 ( struct V_6 * V_17 ,
struct V_55 * V_37 , char * V_3 )
{
struct V_16 * V_56 = F_5 ( V_17 ) ;
if ( ! V_56 -> V_20 )
return 0 ;
return snprintf ( V_3 , V_4 , L_5 ,
F_39 ( V_56 -> V_20 ) ) ;
}
static T_1 F_40 ( struct V_6 * V_17 , struct V_55 * V_37 ,
char * V_3 )
{
struct V_16 * V_56 = F_5 ( V_17 ) ;
char V_57 [ 99 ] ;
if ( ! V_56 -> V_20 )
return 0 ;
return snprintf ( V_3 , V_4 , L_1 ,
F_41 ( V_56 -> V_20 , V_57 ) ) ;
}
static T_1 F_42 ( struct V_6 * V_17 , struct V_55 * V_37 ,
char * V_3 )
{
struct V_16 * V_56 = F_5 ( V_17 ) ;
char V_57 [ 99 ] ;
if ( ! V_56 -> V_20 )
return 0 ;
return snprintf ( V_3 , V_4 , L_1 ,
F_43 ( V_56 -> V_20 , V_57 ) ) ;
}
static T_1 F_44 ( struct V_6 * V_17 , struct V_55 * V_37 ,
char * V_3 )
{
struct V_16 * V_56 = F_5 ( V_17 ) ;
int V_15 = 0 ;
struct V_1 * V_58 = V_17 -> V_2 ;
struct V_11 * V_12 = V_17 -> V_59 ;
struct V_18 * V_19 = NULL ;
if ( ! V_56 -> V_20 || ! V_58 || ! V_12 )
return 0 ;
V_15 = V_58 -> V_60 ( V_17 , V_12 ) ;
if ( ! V_15 )
return 0 ;
V_19 = F_6 ( V_12 ) ;
return snprintf ( V_3 , V_4 , L_1 , V_19 -> V_24 [ V_15 - 1 ] . V_27 ) ;
}
static T_1 F_45 ( struct V_6 * V_17 ,
struct V_55 * V_37 ,
char * V_3 ) {
struct V_16 * V_56 = F_5 ( V_17 ) ;
T_4 V_61 = F_39 ( V_56 -> V_20 ) ;
return snprintf ( V_3 , V_4 , L_5 , V_61 ) ;
}
static T_1 F_46 ( struct V_6 * V_17 ,
struct V_55 * V_37 ,
char * V_3 ) {
struct V_16 * V_56 = F_5 ( V_17 ) ;
return snprintf ( V_3 , V_4 , L_7 , & V_56 -> V_62 ) ;
}
static T_1 F_47 ( struct V_6 * V_17 ,
struct V_55 * V_37 ,
char * V_3 ) {
struct V_16 * V_56 = F_5 ( V_17 ) ;
return snprintf ( V_3 , V_4 , L_1 , V_56 -> V_27 ) ;
}
static T_1 F_48 ( struct V_6 * V_17 ,
struct V_55 * V_37 ,
char * V_3 ) {
struct V_16 * V_56 = F_5 ( V_17 ) ;
T_4 V_63 = F_35 ( V_56 -> V_20 ) ;
return snprintf ( V_3 , V_4 , L_5 , V_63 ) ;
}
static T_1 F_49 ( struct V_6 * V_17 ,
struct V_55 * V_37 ,
char * V_3 ) {
struct V_16 * V_56 = F_5 ( V_17 ) ;
T_4 V_64 = F_37 ( V_56 -> V_20 ) ;
return snprintf ( V_3 , V_4 , L_5 , V_64 ) ;
}
static T_1 F_50 ( struct V_6 * V_17 ,
struct V_55 * V_37 ,
char * V_3 ) {
struct V_16 * V_56 = F_5 ( V_17 ) ;
int V_65 = 0 ;
if ( V_56 -> V_20 ) {
F_41 ( V_56 -> V_20 , V_3 ) ;
V_65 = strlen ( V_3 ) ;
V_3 [ V_65 ++ ] = '\n' ;
}
return V_65 ;
}
static T_1 F_51 ( struct V_6 * V_17 ,
struct V_55 * V_37 ,
char * V_3 ) {
struct V_16 * V_56 = F_5 ( V_17 ) ;
struct V_20 * V_66 = V_56 -> V_20 ;
int V_15 , V_45 , V_67 = V_4 ;
unsigned long V_68 ;
char * V_69 = V_3 ;
T_5 * V_70 ;
struct V_71 V_72 ;
V_70 = L_8 ;
if ( V_66 ) {
if ( V_56 -> V_27 )
V_70 = V_56 -> V_27 ;
V_45 = snprintf ( V_69 , V_67 ,
L_9 ,
V_70 , V_56 -> V_73 ) ;
V_69 += V_45 ;
V_67 -= V_45 ;
V_45 = F_52 ( V_66 ,
F_53 ( struct
V_74 ,
V_75 ) ,
& V_72 , sizeof( V_72 ) ) ;
if ( V_45 >= 0 ) {
V_45 = F_54 ( & V_72 , V_69 ,
V_67 , - 1 ) ;
V_69 += V_45 ;
V_67 -= V_45 ;
}
V_45 = F_52 ( V_66 ,
F_53 ( struct
V_74 ,
V_76 ) ,
& V_72 , sizeof( V_72 ) ) ;
if ( V_45 >= 0 ) {
V_45 = F_54 ( & V_72 , V_69 ,
V_67 , - 1 ) ;
V_69 += V_45 ;
V_67 -= V_45 ;
}
V_68 = F_53 ( struct V_74 , V_72 ) ;
V_15 = 0 ;
while ( V_68 + sizeof( V_72 ) <=
F_37 ( V_66 ) ) {
V_45 = F_52 ( V_66 ,
V_68 , & V_72 , sizeof( V_72 ) ) ;
if ( V_45 >= 0 ) {
V_45 = F_54
( & V_72 , V_69 , V_67 , V_15 ) ;
V_69 += V_45 ;
V_67 -= V_45 ;
}
V_68 += sizeof( V_72 ) ;
V_15 ++ ;
}
}
return V_4 - V_67 ;
}
static T_1
F_55 ( struct V_11 * V_12 , char * V_3 )
{
struct V_18 * V_19 = F_6 ( V_12 ) ;
return snprintf ( V_3 , V_4 , L_1 , V_19 -> V_77 ) ;
}
static int
F_56 ( struct V_18 * V_19 )
{
int V_14 ;
struct V_78 V_77 =
F_57 ( V_77 , V_48 , F_55 , NULL ) ;
V_19 -> V_79 = V_77 ;
V_14 = F_58 ( & V_19 -> V_59 , & V_19 -> V_79 ) ;
return V_14 ;
}
static void
F_59 ( struct V_18 * V_19 )
{
F_60 ( & V_19 -> V_59 , & V_19 -> V_79 ) ;
}
static void
F_61 ( void * V_7 )
{
struct V_16 * V_17 = (struct V_16 * ) V_7 ;
struct V_18 * V_19 = F_6 ( V_17 -> V_6 . V_59 ) ;
F_62 ( & V_17 -> V_80 ) ;
if ( V_19 -> V_81 )
V_19 -> V_81 ( V_17 ) ;
F_63 ( & V_17 -> V_80 ) ;
if ( ! F_64 ( V_17 -> V_28 ) )
F_65 ( & V_17 -> V_6 ) ;
}
static void
F_66 ( struct V_16 * V_17 )
{
if ( V_17 -> V_82 )
return;
F_67 ( & V_17 -> V_6 ) ;
if ( ! F_68 ( V_17 -> V_28 ) )
F_65 ( & V_17 -> V_6 ) ;
}
static void
F_69 ( struct V_16 * V_17 )
{
if ( F_70 ( V_17 -> V_28 ) )
F_65 ( & V_17 -> V_6 ) ;
}
static int
F_71 ( struct V_6 * V_7 )
{
int V_14 ;
struct V_18 * V_19 ;
struct V_16 * V_17 ;
V_19 = F_6 ( V_7 -> V_59 ) ;
V_17 = F_5 ( V_7 ) ;
F_62 ( & V_17 -> V_80 ) ;
V_17 -> V_82 = false ;
F_72 () ;
F_67 ( & V_17 -> V_6 ) ;
if ( ! V_19 -> V_83 ) {
F_63 ( & V_17 -> V_80 ) ;
V_14 = - 1 ;
goto V_22;
}
V_14 = V_19 -> V_83 ( V_17 ) ;
if ( V_14 < 0 )
goto V_22;
F_73 ( V_17 ) ;
F_63 ( & V_17 -> V_80 ) ;
V_14 = 0 ;
V_22:
if ( V_14 != 0 )
F_65 ( & V_17 -> V_6 ) ;
return V_14 ;
}
static int
F_74 ( struct V_6 * V_7 )
{
struct V_16 * V_17 ;
struct V_18 * V_19 ;
V_17 = F_5 ( V_7 ) ;
V_19 = F_6 ( V_7 -> V_59 ) ;
F_62 ( & V_17 -> V_80 ) ;
V_17 -> V_82 = true ;
F_72 () ;
if ( V_19 ) {
if ( V_19 -> remove )
V_19 -> remove ( V_17 ) ;
}
F_63 ( & V_17 -> V_80 ) ;
F_69 ( V_17 ) ;
F_29 ( V_17 ) ;
F_65 ( & V_17 -> V_6 ) ;
return 0 ;
}
int F_75 ( struct V_18 * V_19 )
{
int V_14 = 0 ;
V_19 -> V_59 . V_27 = V_19 -> V_27 ;
V_19 -> V_59 . V_2 = & V_84 ;
V_19 -> V_59 . V_83 = F_71 ;
V_19 -> V_59 . remove = F_74 ;
V_19 -> V_59 . V_85 = V_19 -> V_85 ;
V_14 = F_76 ( & V_19 -> V_59 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_56 ( V_19 ) ;
return V_14 ;
}
void
F_77 ( struct V_18 * V_19 )
{
F_59 ( V_19 ) ;
F_78 ( & V_19 -> V_59 ) ;
}
int
F_79 ( struct V_16 * V_17 , unsigned long V_86 ,
void * V_87 , unsigned long V_64 )
{
return F_52 ( V_17 -> V_20 , V_86 , V_87 , V_64 ) ;
}
int
F_80 ( struct V_16 * V_17 , unsigned long V_86 ,
void * V_88 , unsigned long V_64 )
{
return F_81 ( V_17 -> V_20 , V_86 , V_88 , V_64 ) ;
}
int
F_82 ( struct V_16 * V_17 , unsigned long V_86 , T_5 V_89 ,
unsigned long V_64 )
{
return F_83 ( V_17 -> V_20 , V_86 , V_89 , V_64 ) ;
}
int
F_84 ( struct V_16 * V_17 ,
const char * V_27 , int V_32 , int V_33 )
{
return F_22 ( V_17 , V_27 , V_32 , V_33 ) ;
}
void
F_85 ( struct V_16 * V_17 )
{
F_66 ( V_17 ) ;
}
void
F_86 ( struct V_16 * V_17 )
{
F_69 ( V_17 ) ;
}
static int
F_87 ( struct V_16 * V_17 )
{
int V_14 = - 1 ;
T_6 V_90 = V_17 -> V_90 ;
T_6 V_73 = V_17 -> V_73 ;
F_88 ( V_91 , V_73 , V_90 ,
V_92 ) ;
F_89 ( & V_17 -> V_80 , 1 ) ;
V_17 -> V_6 . V_2 = & V_84 ;
V_17 -> V_6 . V_93 = V_94 ;
F_90 ( & V_17 -> V_6 ) ;
V_17 -> V_6 . V_95 = F_13 ;
F_67 ( & V_17 -> V_6 ) ;
V_17 -> V_28 =
F_91 ( V_96 ,
V_97 ,
F_61 ,
V_17 , F_92 ( & V_17 -> V_6 ) ) ;
if ( ! V_17 -> V_28 ) {
F_93 ( V_98 , V_73 ,
V_99 ) ;
goto V_22;
}
F_94 ( & V_17 -> V_6 , L_10 ,
V_90 , V_73 ) ;
V_14 = F_95 ( & V_17 -> V_6 ) ;
if ( V_14 < 0 ) {
F_93 ( V_100 , V_90 ,
V_99 ) ;
goto V_22;
}
V_14 = F_23 ( V_17 ) ;
if ( V_14 < 0 ) {
F_93 ( V_101 , V_73 ,
V_99 ) ;
goto V_102;
}
F_96 ( & V_17 -> V_103 , & V_104 ) ;
return 0 ;
V_102:
F_97 ( & V_17 -> V_6 ) ;
V_22:
F_65 ( & V_17 -> V_6 ) ;
return V_14 ;
}
static void
F_98 ( struct V_16 * V_17 )
{
F_99 ( & V_17 -> V_103 ) ;
F_31 ( V_17 ) ;
F_65 ( & V_17 -> V_6 ) ;
F_97 ( & V_17 -> V_6 ) ;
}
static int
F_100 ( struct V_20 * V_105 ,
struct V_106 * V_107 )
{
int V_14 = - 1 ;
if ( ! F_101 ( F_102 ( V_105 ) ) )
goto V_22;
if ( F_52 ( V_105 , sizeof( struct V_108 ) , V_107 ,
sizeof( * V_107 ) ) < 0 ) {
goto V_22;
}
if ( V_107 -> V_109 < sizeof( struct V_106 ) )
goto V_22;
if ( V_107 -> V_110 <
sizeof( struct V_71 ) ) {
goto V_22;
}
V_14 = 0 ;
V_22:
return V_14 ;
}
static int
F_103 ( struct V_20 * V_105 ,
struct V_106 * V_107 ,
struct V_71 * V_111 )
{
int V_68 = sizeof( struct V_108 ) + V_107 -> V_112 ;
if ( V_107 -> V_112 == 0 )
return - 1 ;
if ( F_81 ( V_105 , V_68 , V_111 , sizeof( * V_111 ) ) < 0 )
return - 1 ;
return 0 ;
}
static int
F_104 ( struct V_20 * V_105 ,
struct V_106 * V_107 ,
struct V_71 * V_111 )
{
int V_68 = sizeof( struct V_108 ) + V_107 -> V_113 ;
if ( V_107 -> V_113 == 0 )
return - 1 ;
if ( F_81 ( V_105 , V_68 , V_111 , sizeof( * V_111 ) ) < 0 )
return - 1 ;
return 0 ;
}
static int
F_105 ( struct V_20 * V_105 ,
struct V_106 * V_107 ,
struct V_71 * V_111 , int V_114 )
{
int V_68 =
( sizeof( struct V_108 ) + V_107 -> V_115 ) +
( V_107 -> V_110 * V_114 ) ;
if ( V_107 -> V_115 == 0 )
return - 1 ;
if ( F_81 ( V_105 , V_68 , V_111 , sizeof( * V_111 ) ) < 0 )
return - 1 ;
return 0 ;
}
static void
F_73 ( struct V_16 * V_116 )
{
int V_15 ;
struct V_16 * V_117 ;
struct V_18 * V_118 ;
int V_119 = V_116 -> V_90 ;
int V_120 = V_116 -> V_73 ;
struct V_71 V_72 ;
const char * V_121 = NULL ;
struct V_106 * V_107 ;
if ( ! V_116 -> V_6 . V_59 )
return;
V_107 = (struct V_106 * ) V_116 -> V_122 ;
if ( ! V_107 )
return;
V_117 = F_106 ( V_119 , V_123 , NULL ) ;
if ( ! V_117 )
return;
V_118 = F_6 ( V_116 -> V_6 . V_59 ) ;
for ( V_15 = 0 ; V_118 -> V_24 [ V_15 ] . V_27 ; V_15 ++ ) {
if ( memcmp ( & V_118 -> V_24 [ V_15 ] . V_25 ,
& V_116 -> V_124 ,
sizeof( V_118 -> V_24 [ V_15 ] . V_25 ) ) == 0 ) {
V_121 = V_118 -> V_24 [ V_15 ] . V_27 ;
break;
}
}
F_107 ( & V_72 , V_121 ,
V_118 -> V_27 , V_118 -> V_77 ,
V_118 -> V_125 ) ;
F_105 ( V_117 -> V_20 , V_107 , & V_72 , V_120 ) ;
F_103 ( V_117 -> V_20 , V_107 , & V_126 ) ;
F_104 ( V_117 -> V_20 , V_107 ,
& V_127 ) ;
}
static int
F_108 ( struct V_16 * V_17 )
{
int V_14 ;
int V_128 = V_17 -> V_90 ;
struct V_106 * V_107 ;
F_109 ( V_129 , V_92 ) ;
V_107 = F_110 ( sizeof( * V_107 ) , V_46 ) ;
if ( ! V_107 ) {
V_14 = - 1 ;
goto V_22;
}
F_94 ( & V_17 -> V_6 , L_11 , V_128 ) ;
V_17 -> V_6 . V_2 = & V_84 ;
V_17 -> V_6 . V_93 = V_130 ;
V_17 -> V_6 . V_95 = F_9 ;
if ( F_111 ( & V_17 -> V_6 ) < 0 ) {
F_93 ( V_98 , V_128 ,
V_131 ) ;
V_14 = - 1 ;
goto V_132;
}
if ( F_100 ( V_17 -> V_20 , V_107 ) >= 0 ) {
V_17 -> V_122 = ( void * ) V_107 ;
F_103 ( V_17 -> V_20 , V_107 ,
& V_126 ) ;
F_104 ( V_17 -> V_20 , V_107 ,
& V_127 ) ;
} else {
F_12 ( V_107 ) ;
}
V_133 ++ ;
F_96 ( & V_17 -> V_103 , & V_134 ) ;
F_11 ( & V_17 -> V_6 , V_17 ) ;
return 0 ;
V_132:
F_12 ( V_107 ) ;
V_22:
return V_14 ;
}
static void
F_112 ( struct V_16 * V_17 )
{
V_133 -- ;
if ( V_17 -> V_20 ) {
F_15 ( V_17 -> V_20 ) ;
V_17 -> V_20 = NULL ;
}
F_12 ( V_17 -> V_122 ) ;
F_99 ( & V_17 -> V_103 ) ;
F_97 ( & V_17 -> V_6 ) ;
}
static int
F_113 ( void )
{
int V_14 = 0 ;
V_14 = F_114 ( & V_84 ) ;
return V_14 ;
}
static void
F_115 ( void )
{
F_116 ( & V_84 ) ;
}
static void
F_117 ( void )
{
struct V_135 * V_136 , * V_137 ;
F_118 (listentry, listtmp, &list_all_device_instances) {
struct V_16 * V_17 = F_119 ( V_136 ,
struct V_16 ,
V_103 ) ;
F_98 ( V_17 ) ;
}
}
static void
F_120 ( struct V_16 * V_17 )
{
int V_14 ;
T_6 V_119 = V_17 -> V_90 ;
F_93 ( V_129 , V_119 , V_92 ) ;
V_14 = F_108 ( V_17 ) ;
F_93 ( V_138 , V_119 , V_92 ) ;
if ( V_14 < 0 )
F_93 ( V_139 , V_119 ,
V_131 ) ;
else
F_93 ( V_140 , V_119 ,
V_92 ) ;
if ( V_141 . V_142 )
(* V_141 . V_142 ) ( V_17 , V_14 ) ;
}
static void
F_121 ( struct V_16 * V_17 )
{
F_112 ( V_17 ) ;
if ( V_141 . V_143 )
(* V_141 . V_143 )( V_17 , 0 ) ;
}
static void
F_122 ( struct V_16 * V_72 )
{
int V_14 = - 1 ;
T_6 V_119 = V_72 -> V_90 ;
T_6 V_120 = V_72 -> V_73 ;
F_88 ( V_91 , V_120 , V_119 ,
V_92 ) ;
V_14 = F_87 ( V_72 ) ;
if ( V_141 . V_144 )
V_141 . V_144 ( V_72 , V_14 ) ;
if ( V_14 < 0 )
F_88 ( V_98 , V_120 , V_119 ,
V_131 ) ;
else
F_88 ( V_145 , V_120 , V_119 ,
V_92 ) ;
}
static void
F_123 ( struct V_16 * V_72 )
{
F_98 ( V_72 ) ;
if ( V_141 . V_146 )
(* V_141 . V_146 ) ( V_72 , 0 ) ;
}
static void
F_124 ( struct V_16 * V_17 , int V_147 )
{
if ( ! V_17 -> V_148 )
return;
V_17 -> V_148 = false ;
if ( ! V_141 . V_149 )
return;
(* V_141 . V_149 ) ( V_17 , V_147 ) ;
}
static void
F_125 ( struct V_16 * V_17 , int V_147 )
{
if ( ! V_17 -> V_150 )
return;
V_17 -> V_150 = false ;
if ( ! V_141 . V_151 )
return;
(* V_141 . V_151 ) ( V_17 , V_147 ) ;
}
static void
F_126 ( struct V_16 * V_17 , bool V_152 )
{
int V_14 = - 1 , V_45 ;
struct V_18 * V_19 = NULL ;
void (* F_127)( struct V_16 * V_17 , int V_153 ) = NULL ;
if ( V_152 )
F_127 = V_141 . V_149 ;
else
F_127 = V_141 . V_151 ;
if ( ! F_127 )
goto V_22;
V_19 = F_6 ( V_17 -> V_6 . V_59 ) ;
if ( ! V_19 )
goto V_22;
if ( V_17 -> V_148 || V_17 -> V_150 )
goto V_22;
if ( V_152 ) {
if ( ! V_19 -> V_154 )
goto V_22;
V_17 -> V_148 = true ;
V_45 = V_19 -> V_154 ( V_17 , F_124 ) ;
} else {
F_73 ( V_17 ) ;
if ( ! V_19 -> V_155 )
goto V_22;
V_17 -> V_150 = true ;
V_45 = V_19 -> V_155 ( V_17 , F_125 ) ;
}
if ( V_45 < 0 ) {
if ( V_152 )
V_17 -> V_148 = false ;
else
V_17 -> V_150 = false ;
goto V_22;
}
V_14 = 0 ;
V_22:
if ( V_14 < 0 ) {
if ( F_127 )
(* F_127)( V_17 , V_14 ) ;
}
}
static void
F_128 ( struct V_16 * V_72 )
{
F_126 ( V_72 , true ) ;
}
static void
F_129 ( struct V_16 * V_72 )
{
F_126 ( V_72 , false ) ;
}
int
F_130 ( void )
{
int V_14 = 0 ;
F_93 ( V_156 , V_14 , V_92 ) ;
F_107 ( & V_127 ,
L_12 , L_13 ,
V_5 , NULL ) ;
V_14 = F_113 () ;
if ( V_14 < 0 ) {
F_109 ( V_129 , V_99 ) ;
goto V_22;
}
V_97 = F_131 ( L_14 ) ;
if ( ! V_97 ) {
F_109 ( V_157 , V_99 ) ;
V_14 = - V_10 ;
goto V_22;
}
F_132 ( & V_158 ,
& V_141 ,
& V_126 ) ;
V_14 = 0 ;
V_22:
if ( V_14 )
F_93 ( V_159 , V_14 ,
V_131 ) ;
return V_14 ;
}
void
F_133 ( void )
{
struct V_135 * V_136 , * V_137 ;
F_132 ( NULL , NULL , NULL ) ;
F_117 () ;
F_134 ( V_97 ) ;
F_135 ( V_97 ) ;
V_97 = NULL ;
if ( V_160 ) {
F_136 ( & V_28 ) ;
F_134 ( V_160 ) ;
F_135 ( V_160 ) ;
V_160 = NULL ;
}
F_118 (listentry, listtmp, &list_all_bus_instances) {
struct V_16 * V_17 = F_119 ( V_136 ,
struct
V_16 ,
V_103 ) ;
F_112 ( V_17 ) ;
}
F_115 () ;
}
