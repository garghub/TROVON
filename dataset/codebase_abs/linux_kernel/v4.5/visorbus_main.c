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
int V_21 = 0 ;
int V_22 ;
struct V_10 * V_7 ;
struct V_23 * V_24 ;
V_7 = F_3 ( V_14 ) ;
V_24 = F_8 ( V_19 ) ;
V_20 = F_4 ( V_7 -> V_13 ) ;
if ( V_25 ) {
V_21 = 1 ;
goto V_26;
}
if ( V_27 )
goto V_26;
if ( ! V_24 -> V_28 )
goto V_26;
for ( V_22 = 0 ;
( F_9 ( V_24 -> V_28 [ V_22 ] . V_12 , V_29 ) != 0 ) ||
( V_24 -> V_28 [ V_22 ] . V_30 ) ;
V_22 ++ )
if ( F_9 ( V_24 -> V_28 [ V_22 ] . V_12 ,
V_20 ) == 0 ) {
V_21 = V_22 + 1 ;
goto V_26;
}
V_26:
return V_21 ;
}
static void
F_10 ( struct V_6 * V_14 )
{
struct V_10 * V_7 = F_11 ( V_14 ) ;
F_12 ( V_14 , NULL ) ;
F_13 ( V_7 ) ;
}
static void
F_14 ( struct V_6 * V_14 )
{
struct V_10 * V_7 = F_3 ( V_14 ) ;
if ( V_7 -> V_31 ) {
F_15 ( V_7 -> V_31 ) ;
V_7 -> V_31 = NULL ;
}
if ( V_7 -> V_13 ) {
F_16 ( V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
}
F_13 ( V_7 ) ;
}
static T_1 F_17 ( struct V_10 * V_7 , int V_32 , char * V_3 )
{
int V_33 = F_18 ( V_7 -> V_34 ) / sizeof( V_7 -> V_34 [ 0 ] ) ;
if ( V_32 < 0 || V_32 >= V_33 )
return 0 ;
return snprintf ( V_3 , V_4 , L_4 ,
V_7 -> V_34 [ V_32 ] . V_35 , V_7 -> V_34 [ V_32 ] . V_36 ) ;
}
static T_1
F_19 ( struct V_37 * V_38 , struct V_39 * V_9 , char * V_3 )
{
struct V_40 * V_41 =
F_20 ( V_9 ) ;
struct V_10 * V_7 = F_21 ( V_38 ) ;
T_1 V_42 = 0 ;
if ( V_41 -> V_43 )
V_42 = V_41 -> V_43 ( V_7 ,
V_41 -> V_32 , V_3 ) ;
return V_42 ;
}
static T_1
F_22 ( struct V_37 * V_38 ,
struct V_39 * V_9 , const char * V_3 , T_3 V_44 )
{
struct V_40 * V_41 =
F_20 ( V_9 ) ;
struct V_10 * V_7 = F_21 ( V_38 ) ;
T_1 V_42 = 0 ;
if ( V_41 -> V_45 )
V_42 = V_41 -> V_45 ( V_7 ,
V_41 -> V_32 ,
V_3 , V_44 ) ;
return V_42 ;
}
static int
F_23 ( struct V_10 * V_7 , const char * V_30 ,
int V_35 , int V_36 )
{
int V_33 = F_18 ( V_7 -> V_34 ) / sizeof( V_7 -> V_34 [ 0 ] ) ;
struct V_40 * V_46 = NULL ;
int V_47 = - 1 , V_21 = 0 , V_32 = - 1 ;
F_24 ( V_7 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
if ( ! V_7 -> V_34 [ V_32 ] . V_9 )
break;
if ( V_32 == V_33 ) {
V_21 = - V_17 ;
goto V_26;
}
V_46 = F_25 ( sizeof( * V_46 ) , V_48 ) ;
if ( ! V_46 ) {
V_21 = - V_17 ;
goto V_26;
}
V_46 -> V_43 = F_17 ;
V_46 -> V_45 = NULL ;
V_46 -> V_32 = V_32 ;
V_46 -> V_9 . V_30 = V_30 ;
V_46 -> V_9 . V_49 = V_50 ;
V_7 -> V_34 [ V_32 ] . V_9 = V_46 ;
V_7 -> V_34 [ V_32 ] . V_35 = V_35 ;
V_7 -> V_34 [ V_32 ] . V_36 = V_36 ;
V_47 = F_26 ( & V_7 -> V_51 , & V_46 -> V_9 ) ;
if ( V_47 < 0 ) {
V_21 = V_47 ;
goto V_26;
}
F_27 ( & V_7 -> V_6 . V_38 , V_52 ) ;
V_26:
if ( V_21 < 0 ) {
F_13 ( V_46 ) ;
V_46 = NULL ;
V_7 -> V_34 [ V_32 ] . V_9 = NULL ;
}
return V_21 ;
}
static void
F_28 ( struct V_10 * V_7 , int V_32 )
{
int V_33 = F_18 ( V_7 -> V_34 ) / sizeof( V_7 -> V_34 [ 0 ] ) ;
struct V_40 * V_46 = NULL ;
if ( V_32 < 0 || V_32 >= V_33 )
return;
V_46 = (struct V_40 * ) ( V_7 -> V_34 [ V_32 ] . V_9 ) ;
if ( ! V_46 )
return;
F_29 ( & V_7 -> V_51 , & V_46 -> V_9 ) ;
F_27 ( & V_7 -> V_6 . V_38 , V_53 ) ;
V_7 -> V_34 [ V_32 ] . V_9 = NULL ;
F_13 ( V_46 ) ;
}
static void
F_30 ( struct V_10 * V_7 )
{
int V_22 = 0 ;
int V_33 = F_18 ( V_7 -> V_34 ) / sizeof( V_7 -> V_34 [ 0 ] ) ;
for ( V_22 = 0 ; V_22 < V_33 ; V_22 ++ )
F_28 ( V_7 , V_22 ) ;
}
static int
F_24 ( struct V_10 * V_7 )
{
int V_21 = 0 , V_47 = 0 ;
if ( V_7 -> V_51 . V_54 )
goto V_26;
V_47 = F_31 ( & V_7 -> V_51 ,
& V_55 , & V_7 -> V_6 . V_38 ,
L_5 ) ;
if ( V_47 < 0 ) {
V_21 = V_47 ;
goto V_26;
}
F_27 ( & V_7 -> V_51 , V_56 ) ;
V_26:
return V_21 ;
}
static void
F_32 ( struct V_10 * V_7 )
{
if ( ! V_7 -> V_51 . V_54 )
return;
F_30 ( V_7 ) ;
F_33 ( & V_7 -> V_51 ) ;
F_34 ( & V_7 -> V_51 ) ;
V_7 -> V_51 . V_54 = NULL ;
}
static T_1 F_35 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_3 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( ! V_11 -> V_13 )
return 0 ;
return snprintf ( V_3 , V_4 , L_6 ,
F_36 ( V_11 -> V_13 ) ) ;
}
static T_1 F_37 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_3 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( ! V_11 -> V_13 )
return 0 ;
return snprintf ( V_3 , V_4 , L_7 ,
F_38 ( V_11 -> V_13 ) ) ;
}
static T_1 F_39 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_3 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( ! V_11 -> V_13 )
return 0 ;
return snprintf ( V_3 , V_4 , L_6 ,
F_40 ( V_11 -> V_13 ) ) ;
}
static T_1 F_41 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_3 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
char V_57 [ 99 ] ;
if ( ! V_11 -> V_13 )
return 0 ;
return snprintf ( V_3 , V_4 , L_1 ,
F_42 ( V_11 -> V_13 , V_57 ) ) ;
}
static T_1 F_43 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_3 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
char V_57 [ 99 ] ;
if ( ! V_11 -> V_13 )
return 0 ;
return snprintf ( V_3 , V_4 , L_1 ,
F_44 ( V_11 -> V_13 , V_57 ) ) ;
}
static T_1 F_45 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_3 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
int V_22 = 0 ;
struct V_1 * V_58 = V_7 -> V_2 ;
struct V_18 * V_19 = V_7 -> V_59 ;
struct V_23 * V_24 = NULL ;
if ( ! V_11 -> V_13 || ! V_58 || ! V_19 )
return 0 ;
V_22 = V_58 -> V_60 ( V_7 , V_19 ) ;
if ( ! V_22 )
return 0 ;
V_24 = F_8 ( V_19 ) ;
return snprintf ( V_3 , V_4 , L_1 , V_24 -> V_28 [ V_22 - 1 ] . V_30 ) ;
}
static T_1 F_46 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
T_4 V_61 = F_40 ( V_11 -> V_13 ) ;
return snprintf ( V_3 , V_4 , L_6 , V_61 ) ;
}
static T_1 F_47 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
return snprintf ( V_3 , V_4 , L_8 , & V_11 -> V_62 ) ;
}
static T_1 F_48 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
return snprintf ( V_3 , V_4 , L_1 , V_11 -> V_30 ) ;
}
static T_1 F_49 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
T_4 V_63 = F_36 ( V_11 -> V_13 ) ;
return snprintf ( V_3 , V_4 , L_6 , V_63 ) ;
}
static T_1 F_50 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
T_4 V_64 = F_38 ( V_11 -> V_13 ) ;
return snprintf ( V_3 , V_4 , L_6 , V_64 ) ;
}
static T_1 F_51 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
int V_65 = 0 ;
if ( V_11 -> V_13 ) {
F_42 ( V_11 -> V_13 , V_3 ) ;
V_65 = strlen ( V_3 ) ;
V_3 [ V_65 ++ ] = '\n' ;
}
return V_65 ;
}
static T_1 F_52 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
struct V_13 * V_66 = V_11 -> V_13 ;
int V_22 , V_47 , V_67 = V_4 ;
unsigned long V_68 ;
char * V_69 = V_3 ;
T_5 * V_70 ;
struct V_71 V_72 ;
V_70 = L_9 ;
if ( V_66 ) {
if ( V_11 -> V_30 )
V_70 = V_11 -> V_30 ;
V_47 = snprintf ( V_69 , V_67 ,
L_10 ,
V_70 , V_11 -> V_73 ) ;
V_69 += V_47 ;
V_67 -= V_47 ;
V_47 = F_53 ( V_66 ,
F_54 ( struct
V_74 ,
V_75 ) ,
& V_72 , sizeof( V_72 ) ) ;
if ( V_47 >= 0 ) {
V_47 = F_55 ( & V_72 , V_69 ,
V_67 , - 1 ) ;
V_69 += V_47 ;
V_67 -= V_47 ;
}
V_47 = F_53 ( V_66 ,
F_54 ( struct
V_74 ,
V_76 ) ,
& V_72 , sizeof( V_72 ) ) ;
if ( V_47 >= 0 ) {
V_47 = F_55 ( & V_72 , V_69 ,
V_67 , - 1 ) ;
V_69 += V_47 ;
V_67 -= V_47 ;
}
V_68 = F_54 ( struct V_74 , V_72 ) ;
V_22 = 0 ;
while ( V_68 + sizeof( V_72 ) <=
F_38 ( V_66 ) ) {
V_47 = F_53 ( V_66 ,
V_68 , & V_72 , sizeof( V_72 ) ) ;
if ( V_47 >= 0 ) {
V_47 = F_55
( & V_72 , V_69 , V_67 , V_22 ) ;
V_69 += V_47 ;
V_67 -= V_47 ;
}
V_68 += sizeof( V_72 ) ;
V_22 ++ ;
}
}
return V_4 - V_67 ;
}
static T_1
F_56 ( struct V_18 * V_19 , char * V_3 )
{
struct V_23 * V_24 = F_8 ( V_19 ) ;
return snprintf ( V_3 , V_4 , L_1 , V_24 -> V_77 ) ;
}
static int
F_57 ( struct V_23 * V_24 )
{
int V_21 ;
struct V_78 V_77 =
F_58 ( V_77 , V_50 , F_56 , NULL ) ;
V_24 -> V_79 = V_77 ;
V_21 = F_59 ( & V_24 -> V_59 , & V_24 -> V_79 ) ;
return V_21 ;
}
static void
F_60 ( struct V_23 * V_24 )
{
F_61 ( & V_24 -> V_59 , & V_24 -> V_79 ) ;
}
static void
F_62 ( void * V_14 )
{
struct V_10 * V_7 = V_14 ;
struct V_23 * V_24 = F_8 ( V_7 -> V_6 . V_59 ) ;
F_63 ( & V_7 -> V_80 ) ;
if ( V_24 -> V_81 )
V_24 -> V_81 ( V_7 ) ;
F_64 ( & V_7 -> V_80 ) ;
if ( ! F_65 ( V_7 -> V_31 ) )
F_66 ( & V_7 -> V_6 ) ;
}
static void
F_67 ( struct V_10 * V_7 )
{
if ( V_7 -> V_82 )
return;
F_68 ( & V_7 -> V_6 ) ;
if ( ! F_69 ( V_7 -> V_31 ) )
F_66 ( & V_7 -> V_6 ) ;
}
static void
F_70 ( struct V_10 * V_7 )
{
if ( F_71 ( V_7 -> V_31 ) )
F_66 ( & V_7 -> V_6 ) ;
}
static int
F_72 ( struct V_6 * V_14 )
{
int V_21 ;
struct V_23 * V_24 ;
struct V_10 * V_7 ;
V_24 = F_8 ( V_14 -> V_59 ) ;
V_7 = F_3 ( V_14 ) ;
F_63 ( & V_7 -> V_80 ) ;
V_7 -> V_82 = false ;
F_73 () ;
F_68 ( & V_7 -> V_6 ) ;
if ( ! V_24 -> V_83 ) {
F_64 ( & V_7 -> V_80 ) ;
V_21 = - 1 ;
goto V_26;
}
V_21 = V_24 -> V_83 ( V_7 ) ;
if ( V_21 < 0 )
goto V_26;
F_74 ( V_7 ) ;
F_64 ( & V_7 -> V_80 ) ;
V_21 = 0 ;
V_26:
if ( V_21 != 0 )
F_66 ( & V_7 -> V_6 ) ;
return V_21 ;
}
static int
F_75 ( struct V_6 * V_14 )
{
struct V_10 * V_7 ;
struct V_23 * V_24 ;
V_7 = F_3 ( V_14 ) ;
V_24 = F_8 ( V_14 -> V_59 ) ;
F_63 ( & V_7 -> V_80 ) ;
V_7 -> V_82 = true ;
F_73 () ;
if ( V_24 ) {
if ( V_24 -> remove )
V_24 -> remove ( V_7 ) ;
}
F_64 ( & V_7 -> V_80 ) ;
F_70 ( V_7 ) ;
F_30 ( V_7 ) ;
F_66 ( & V_7 -> V_6 ) ;
return 0 ;
}
int F_76 ( struct V_23 * V_24 )
{
int V_21 = 0 ;
if ( V_84 < 0 )
return - V_85 ;
V_24 -> V_59 . V_30 = V_24 -> V_30 ;
V_24 -> V_59 . V_2 = & V_86 ;
V_24 -> V_59 . V_83 = F_72 ;
V_24 -> V_59 . remove = F_75 ;
V_24 -> V_59 . V_87 = V_24 -> V_87 ;
V_21 = F_77 ( & V_24 -> V_59 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_57 ( V_24 ) ;
if ( V_21 < 0 )
F_78 ( & V_24 -> V_59 ) ;
return V_21 ;
}
void
F_79 ( struct V_23 * V_24 )
{
F_60 ( V_24 ) ;
F_78 ( & V_24 -> V_59 ) ;
}
int
F_80 ( struct V_10 * V_7 , unsigned long V_88 ,
void * V_89 , unsigned long V_64 )
{
return F_53 ( V_7 -> V_13 , V_88 , V_89 , V_64 ) ;
}
int
F_81 ( struct V_10 * V_7 , unsigned long V_88 ,
void * V_90 , unsigned long V_64 )
{
return F_82 ( V_7 -> V_13 , V_88 , V_90 , V_64 ) ;
}
int
F_83 ( struct V_10 * V_7 , unsigned long V_88 , T_5 V_91 ,
unsigned long V_64 )
{
return F_84 ( V_7 -> V_13 , V_88 , V_91 , V_64 ) ;
}
int
F_85 ( struct V_10 * V_7 ,
const char * V_30 , int V_35 , int V_36 )
{
return F_23 ( V_7 , V_30 , V_35 , V_36 ) ;
}
void
F_86 ( struct V_10 * V_7 )
{
F_67 ( V_7 ) ;
}
void
F_87 ( struct V_10 * V_7 )
{
F_70 ( V_7 ) ;
}
static int
F_88 ( struct V_10 * V_7 )
{
int V_21 = - 1 ;
T_6 V_92 = V_7 -> V_92 ;
T_6 V_73 = V_7 -> V_73 ;
F_89 ( V_93 , V_73 , V_92 ,
V_94 ) ;
F_90 ( & V_7 -> V_80 , 1 ) ;
V_7 -> V_6 . V_2 = & V_86 ;
V_7 -> V_6 . V_95 = V_96 ;
F_91 ( & V_7 -> V_6 ) ;
V_7 -> V_6 . V_97 = F_14 ;
F_68 ( & V_7 -> V_6 ) ;
V_7 -> V_31 =
F_92 ( V_98 ,
V_99 ,
F_62 ,
V_7 , F_93 ( & V_7 -> V_6 ) ) ;
if ( ! V_7 -> V_31 ) {
F_94 ( V_100 , V_73 ,
V_101 ) ;
goto V_26;
}
F_95 ( & V_7 -> V_6 , L_11 ,
V_92 , V_73 ) ;
V_21 = F_96 ( & V_7 -> V_6 ) ;
if ( V_21 < 0 ) {
F_94 ( V_102 , V_92 ,
V_101 ) ;
goto V_26;
}
V_21 = F_24 ( V_7 ) ;
if ( V_21 < 0 ) {
F_94 ( V_103 , V_73 ,
V_101 ) ;
goto V_104;
}
F_97 ( & V_7 -> V_105 , & V_106 ) ;
return 0 ;
V_104:
F_98 ( & V_7 -> V_6 ) ;
V_26:
F_66 ( & V_7 -> V_6 ) ;
return V_21 ;
}
static void
F_99 ( struct V_10 * V_7 )
{
F_100 ( & V_7 -> V_105 ) ;
F_32 ( V_7 ) ;
F_66 ( & V_7 -> V_6 ) ;
F_98 ( & V_7 -> V_6 ) ;
}
static int
F_101 ( struct V_13 * V_107 ,
struct V_108 * V_109 )
{
int V_21 = - 1 ;
if ( ! F_102 ( F_103 ( V_107 ) ) )
goto V_26;
if ( F_53 ( V_107 , sizeof( struct V_110 ) , V_109 ,
sizeof( * V_109 ) ) < 0 ) {
goto V_26;
}
if ( V_109 -> V_111 < sizeof( struct V_108 ) )
goto V_26;
if ( V_109 -> V_112 <
sizeof( struct V_71 ) ) {
goto V_26;
}
V_21 = 0 ;
V_26:
return V_21 ;
}
static int
F_104 ( struct V_13 * V_107 ,
struct V_108 * V_109 ,
struct V_71 * V_113 )
{
int V_68 = sizeof( struct V_110 ) + V_109 -> V_114 ;
if ( V_109 -> V_114 == 0 )
return - 1 ;
if ( F_82 ( V_107 , V_68 , V_113 , sizeof( * V_113 ) ) < 0 )
return - 1 ;
return 0 ;
}
static int
F_105 ( struct V_13 * V_107 ,
struct V_108 * V_109 ,
struct V_71 * V_113 )
{
int V_68 = sizeof( struct V_110 ) + V_109 -> V_115 ;
if ( V_109 -> V_115 == 0 )
return - 1 ;
if ( F_82 ( V_107 , V_68 , V_113 , sizeof( * V_113 ) ) < 0 )
return - 1 ;
return 0 ;
}
static int
F_106 ( struct V_13 * V_107 ,
struct V_108 * V_109 ,
struct V_71 * V_113 , int V_116 )
{
int V_68 =
( sizeof( struct V_110 ) + V_109 -> V_117 ) +
( V_109 -> V_112 * V_116 ) ;
if ( V_109 -> V_117 == 0 )
return - 1 ;
if ( F_82 ( V_107 , V_68 , V_113 , sizeof( * V_113 ) ) < 0 )
return - 1 ;
return 0 ;
}
static void
F_74 ( struct V_10 * V_118 )
{
int V_22 ;
struct V_10 * V_119 ;
struct V_23 * V_120 ;
int V_121 = V_118 -> V_92 ;
int V_122 = V_118 -> V_73 ;
struct V_71 V_72 ;
const char * V_123 = NULL ;
struct V_108 * V_109 ;
if ( ! V_118 -> V_6 . V_59 )
return;
V_109 = (struct V_108 * ) V_118 -> V_124 ;
if ( ! V_109 )
return;
V_119 = F_107 ( V_121 , V_125 , NULL ) ;
if ( ! V_119 )
return;
V_120 = F_8 ( V_118 -> V_6 . V_59 ) ;
for ( V_22 = 0 ; V_120 -> V_28 [ V_22 ] . V_30 ; V_22 ++ ) {
if ( memcmp ( & V_120 -> V_28 [ V_22 ] . V_12 ,
& V_118 -> V_126 ,
sizeof( V_120 -> V_28 [ V_22 ] . V_12 ) ) == 0 ) {
V_123 = V_120 -> V_28 [ V_22 ] . V_30 ;
break;
}
}
F_108 ( & V_72 , V_123 ,
V_120 -> V_30 , V_120 -> V_77 ,
V_120 -> V_127 ) ;
F_106 ( V_119 -> V_13 , V_109 , & V_72 , V_122 ) ;
F_104 ( V_119 -> V_13 , V_109 , & V_128 ) ;
F_105 ( V_119 -> V_13 , V_109 ,
& V_129 ) ;
}
static int
F_109 ( struct V_10 * V_7 )
{
int V_21 ;
int V_130 = V_7 -> V_92 ;
struct V_108 * V_109 ;
F_110 ( V_131 , V_94 ) ;
V_109 = F_25 ( sizeof( * V_109 ) , V_48 ) ;
if ( ! V_109 ) {
V_21 = - 1 ;
goto V_26;
}
F_95 ( & V_7 -> V_6 , L_12 , V_130 ) ;
V_7 -> V_6 . V_2 = & V_86 ;
V_7 -> V_6 . V_95 = V_132 ;
V_7 -> V_6 . V_97 = F_10 ;
if ( F_111 ( & V_7 -> V_6 ) < 0 ) {
F_94 ( V_100 , V_130 ,
V_133 ) ;
V_21 = - 1 ;
goto V_134;
}
if ( F_101 ( V_7 -> V_13 , V_109 ) >= 0 ) {
V_7 -> V_124 = ( void * ) V_109 ;
F_104 ( V_7 -> V_13 , V_109 ,
& V_128 ) ;
F_105 ( V_7 -> V_13 , V_109 ,
& V_129 ) ;
} else {
F_13 ( V_109 ) ;
}
V_135 ++ ;
F_97 ( & V_7 -> V_105 , & V_136 ) ;
F_12 ( & V_7 -> V_6 , V_7 ) ;
return 0 ;
V_134:
F_13 ( V_109 ) ;
V_26:
return V_21 ;
}
static void
F_112 ( struct V_10 * V_7 )
{
V_135 -- ;
if ( V_7 -> V_13 ) {
F_16 ( V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
}
F_13 ( V_7 -> V_124 ) ;
F_100 ( & V_7 -> V_105 ) ;
F_98 ( & V_7 -> V_6 ) ;
}
static int
F_113 ( void )
{
V_84 = F_114 ( & V_86 ) ;
return V_84 ;
}
static void
F_115 ( void )
{
F_116 ( & V_86 ) ;
}
static void
F_117 ( void )
{
struct V_137 * V_138 , * V_139 ;
F_118 (listentry, listtmp, &list_all_device_instances) {
struct V_10 * V_7 = F_119 ( V_138 ,
struct V_10 ,
V_105 ) ;
F_99 ( V_7 ) ;
}
}
static void
F_120 ( struct V_10 * V_7 )
{
int V_21 ;
T_6 V_121 = V_7 -> V_92 ;
F_94 ( V_131 , V_121 , V_94 ) ;
V_21 = F_109 ( V_7 ) ;
F_94 ( V_140 , V_121 , V_94 ) ;
if ( V_21 < 0 )
F_94 ( V_141 , V_121 ,
V_133 ) ;
else
F_94 ( V_142 , V_121 ,
V_94 ) ;
if ( V_143 . V_144 )
(* V_143 . V_144 ) ( V_7 , V_21 ) ;
}
static void
F_121 ( struct V_10 * V_7 )
{
F_112 ( V_7 ) ;
if ( V_143 . V_145 )
(* V_143 . V_145 )( V_7 , 0 ) ;
}
static void
F_122 ( struct V_10 * V_72 )
{
int V_21 = - 1 ;
T_6 V_121 = V_72 -> V_92 ;
T_6 V_122 = V_72 -> V_73 ;
F_89 ( V_93 , V_122 , V_121 ,
V_94 ) ;
V_21 = F_88 ( V_72 ) ;
if ( V_143 . V_146 )
V_143 . V_146 ( V_72 , V_21 ) ;
if ( V_21 < 0 )
F_89 ( V_100 , V_122 , V_121 ,
V_133 ) ;
else
F_89 ( V_147 , V_122 , V_121 ,
V_94 ) ;
}
static void
F_123 ( struct V_10 * V_72 )
{
F_99 ( V_72 ) ;
if ( V_143 . V_148 )
(* V_143 . V_148 ) ( V_72 , 0 ) ;
}
static void
F_124 ( struct V_10 * V_7 , int V_149 )
{
if ( ! V_7 -> V_150 )
return;
V_7 -> V_150 = false ;
if ( ! V_143 . V_151 )
return;
(* V_143 . V_151 ) ( V_7 , V_149 ) ;
}
static void
F_125 ( struct V_10 * V_7 , int V_149 )
{
if ( ! V_7 -> V_152 )
return;
V_7 -> V_152 = false ;
if ( ! V_143 . V_153 )
return;
(* V_143 . V_153 ) ( V_7 , V_149 ) ;
}
static void
F_126 ( struct V_10 * V_7 , bool V_154 )
{
int V_21 = - 1 , V_47 ;
struct V_23 * V_24 = NULL ;
void (* F_127)( struct V_10 * V_7 , int V_155 ) = NULL ;
if ( V_154 )
F_127 = V_143 . V_151 ;
else
F_127 = V_143 . V_153 ;
if ( ! F_127 )
goto V_26;
V_24 = F_8 ( V_7 -> V_6 . V_59 ) ;
if ( ! V_24 )
goto V_26;
if ( V_7 -> V_150 || V_7 -> V_152 )
goto V_26;
if ( V_154 ) {
if ( ! V_24 -> V_156 )
goto V_26;
V_7 -> V_150 = true ;
V_47 = V_24 -> V_156 ( V_7 , F_124 ) ;
} else {
F_74 ( V_7 ) ;
if ( ! V_24 -> V_157 )
goto V_26;
V_7 -> V_152 = true ;
V_47 = V_24 -> V_157 ( V_7 , F_125 ) ;
}
if ( V_47 < 0 ) {
if ( V_154 )
V_7 -> V_150 = false ;
else
V_7 -> V_152 = false ;
goto V_26;
}
V_21 = 0 ;
V_26:
if ( V_21 < 0 ) {
if ( F_127 )
(* F_127)( V_7 , V_21 ) ;
}
}
static void
F_128 ( struct V_10 * V_72 )
{
F_126 ( V_72 , true ) ;
}
static void
F_129 ( struct V_10 * V_72 )
{
F_126 ( V_72 , false ) ;
}
int
F_130 ( void )
{
int V_21 = 0 ;
F_94 ( V_158 , V_21 , V_94 ) ;
F_108 ( & V_129 ,
L_13 , L_14 ,
V_5 , NULL ) ;
V_21 = F_113 () ;
if ( V_21 < 0 ) {
F_110 ( V_131 , V_101 ) ;
goto V_26;
}
V_99 = F_131 ( L_15 ) ;
if ( ! V_99 ) {
F_110 ( V_159 , V_101 ) ;
V_21 = - V_17 ;
goto V_26;
}
F_132 ( & V_160 ,
& V_143 ,
& V_128 ) ;
V_21 = 0 ;
V_26:
if ( V_21 )
F_94 ( V_161 , V_21 ,
V_133 ) ;
return V_21 ;
}
void
F_133 ( void )
{
struct V_137 * V_138 , * V_139 ;
F_132 ( NULL , NULL , NULL ) ;
F_117 () ;
F_134 ( V_99 ) ;
F_135 ( V_99 ) ;
V_99 = NULL ;
if ( V_162 ) {
F_136 ( & V_31 ) ;
F_134 ( V_162 ) ;
F_135 ( V_162 ) ;
V_162 = NULL ;
}
F_118 (listentry, listtmp, &list_all_bus_instances) {
struct V_10 * V_7 = F_119 ( V_138 ,
struct V_10 ,
V_105 ) ;
F_112 ( V_7 ) ;
}
F_115 () ;
}
