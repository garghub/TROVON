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
F_12 ( V_7 ) ;
}
static void
F_13 ( struct V_6 * V_14 )
{
struct V_10 * V_7 = F_3 ( V_14 ) ;
if ( V_7 -> V_31 ) {
F_14 ( V_7 -> V_31 ) ;
V_7 -> V_31 = NULL ;
}
if ( V_7 -> V_13 ) {
F_15 ( V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
}
F_12 ( V_7 ) ;
}
static T_1 F_16 ( struct V_10 * V_7 , int V_32 , char * V_3 )
{
int V_33 = F_17 ( V_7 -> V_34 ) / sizeof( V_7 -> V_34 [ 0 ] ) ;
if ( V_32 < 0 || V_32 >= V_33 )
return 0 ;
return snprintf ( V_3 , V_4 , L_4 ,
V_7 -> V_34 [ V_32 ] . V_35 , V_7 -> V_34 [ V_32 ] . V_36 ) ;
}
static T_1
F_18 ( struct V_37 * V_38 , struct V_39 * V_9 , char * V_3 )
{
struct V_40 * V_41 =
F_19 ( V_9 ) ;
struct V_10 * V_7 = F_20 ( V_38 ) ;
T_1 V_42 = 0 ;
if ( V_41 -> V_43 )
V_42 = V_41 -> V_43 ( V_7 ,
V_41 -> V_32 , V_3 ) ;
return V_42 ;
}
static T_1
F_21 ( struct V_37 * V_38 ,
struct V_39 * V_9 , const char * V_3 , T_3 V_44 )
{
struct V_40 * V_41 =
F_19 ( V_9 ) ;
struct V_10 * V_7 = F_20 ( V_38 ) ;
T_1 V_42 = 0 ;
if ( V_41 -> V_45 )
V_42 = V_41 -> V_45 ( V_7 ,
V_41 -> V_32 ,
V_3 , V_44 ) ;
return V_42 ;
}
static int
F_22 ( struct V_10 * V_7 , const char * V_30 ,
int V_35 , int V_36 )
{
int V_33 = F_17 ( V_7 -> V_34 ) / sizeof( V_7 -> V_34 [ 0 ] ) ;
struct V_40 * V_46 = NULL ;
int V_47 = - 1 , V_21 = 0 , V_32 = - 1 ;
F_23 ( V_7 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
if ( ! V_7 -> V_34 [ V_32 ] . V_9 )
break;
if ( V_32 == V_33 ) {
V_21 = - V_17 ;
goto V_26;
}
V_46 = F_24 ( sizeof( * V_46 ) , V_48 ) ;
if ( ! V_46 ) {
V_21 = - V_17 ;
goto V_26;
}
V_46 -> V_43 = F_16 ;
V_46 -> V_45 = NULL ;
V_46 -> V_32 = V_32 ;
V_46 -> V_9 . V_30 = V_30 ;
V_46 -> V_9 . V_49 = V_50 ;
V_7 -> V_34 [ V_32 ] . V_9 = V_46 ;
V_7 -> V_34 [ V_32 ] . V_35 = V_35 ;
V_7 -> V_34 [ V_32 ] . V_36 = V_36 ;
V_47 = F_25 ( & V_7 -> V_51 , & V_46 -> V_9 ) ;
if ( V_47 < 0 ) {
V_21 = V_47 ;
goto V_26;
}
F_26 ( & V_7 -> V_6 . V_38 , V_52 ) ;
V_26:
if ( V_21 < 0 ) {
F_12 ( V_46 ) ;
V_46 = NULL ;
V_7 -> V_34 [ V_32 ] . V_9 = NULL ;
}
return V_21 ;
}
static void
F_27 ( struct V_10 * V_7 , int V_32 )
{
int V_33 = F_17 ( V_7 -> V_34 ) / sizeof( V_7 -> V_34 [ 0 ] ) ;
struct V_40 * V_46 = NULL ;
if ( V_32 < 0 || V_32 >= V_33 )
return;
V_46 = (struct V_40 * ) ( V_7 -> V_34 [ V_32 ] . V_9 ) ;
if ( ! V_46 )
return;
F_28 ( & V_7 -> V_51 , & V_46 -> V_9 ) ;
F_26 ( & V_7 -> V_6 . V_38 , V_53 ) ;
V_7 -> V_34 [ V_32 ] . V_9 = NULL ;
F_12 ( V_46 ) ;
}
static void
F_29 ( struct V_10 * V_7 )
{
int V_22 = 0 ;
int V_33 = F_17 ( V_7 -> V_34 ) / sizeof( V_7 -> V_34 [ 0 ] ) ;
for ( V_22 = 0 ; V_22 < V_33 ; V_22 ++ )
F_27 ( V_7 , V_22 ) ;
}
static int
F_23 ( struct V_10 * V_7 )
{
int V_21 = 0 , V_47 = 0 ;
if ( V_7 -> V_51 . V_54 )
goto V_26;
V_47 = F_30 ( & V_7 -> V_51 ,
& V_55 , & V_7 -> V_6 . V_38 ,
L_5 ) ;
if ( V_47 < 0 ) {
V_21 = V_47 ;
goto V_26;
}
F_26 ( & V_7 -> V_51 , V_56 ) ;
V_26:
return V_21 ;
}
static void
F_31 ( struct V_10 * V_7 )
{
if ( ! V_7 -> V_51 . V_54 )
return;
F_29 ( V_7 ) ;
F_32 ( & V_7 -> V_51 ) ;
F_33 ( & V_7 -> V_51 ) ;
V_7 -> V_51 . V_54 = NULL ;
}
static T_1 F_34 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_3 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( ! V_11 -> V_13 )
return 0 ;
return snprintf ( V_3 , V_4 , L_6 ,
F_35 ( V_11 -> V_13 ) ) ;
}
static T_1 F_36 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_3 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( ! V_11 -> V_13 )
return 0 ;
return snprintf ( V_3 , V_4 , L_7 ,
F_37 ( V_11 -> V_13 ) ) ;
}
static T_1 F_38 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_3 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( ! V_11 -> V_13 )
return 0 ;
return snprintf ( V_3 , V_4 , L_6 ,
F_39 ( V_11 -> V_13 ) ) ;
}
static T_1 F_40 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_3 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
char V_57 [ 99 ] ;
if ( ! V_11 -> V_13 )
return 0 ;
return snprintf ( V_3 , V_4 , L_1 ,
F_41 ( V_11 -> V_13 , V_57 ) ) ;
}
static T_1 F_42 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_3 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
char V_57 [ 99 ] ;
if ( ! V_11 -> V_13 )
return 0 ;
return snprintf ( V_3 , V_4 , L_1 ,
F_43 ( V_11 -> V_13 , V_57 ) ) ;
}
static T_1 F_44 ( struct V_6 * V_7 , struct V_8 * V_9 ,
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
static T_1 F_45 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
T_4 V_61 = F_39 ( V_11 -> V_13 ) ;
return snprintf ( V_3 , V_4 , L_6 , V_61 ) ;
}
static T_1 F_46 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
return snprintf ( V_3 , V_4 , L_8 , & V_11 -> V_62 ) ;
}
static T_1 F_47 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
return snprintf ( V_3 , V_4 , L_1 , V_11 -> V_30 ) ;
}
static T_1 F_48 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
T_4 V_63 = F_35 ( V_11 -> V_13 ) ;
return snprintf ( V_3 , V_4 , L_6 , V_63 ) ;
}
static T_1 F_49 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
T_4 V_64 = F_37 ( V_11 -> V_13 ) ;
return snprintf ( V_3 , V_4 , L_6 , V_64 ) ;
}
static T_1 F_50 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_3 ) {
struct V_10 * V_11 = F_3 ( V_7 ) ;
int V_65 = 0 ;
if ( V_11 -> V_13 ) {
F_41 ( V_11 -> V_13 , V_3 ) ;
V_65 = strlen ( V_3 ) ;
V_3 [ V_65 ++ ] = '\n' ;
}
return V_65 ;
}
static T_1 F_51 ( struct V_6 * V_7 ,
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
V_47 = F_52 ( V_66 ,
F_53 ( struct
V_74 ,
V_75 ) ,
& V_72 , sizeof( V_72 ) ) ;
if ( V_47 >= 0 ) {
V_47 = F_54 ( & V_72 , V_69 ,
V_67 , - 1 ) ;
V_69 += V_47 ;
V_67 -= V_47 ;
}
V_47 = F_52 ( V_66 ,
F_53 ( struct
V_74 ,
V_76 ) ,
& V_72 , sizeof( V_72 ) ) ;
if ( V_47 >= 0 ) {
V_47 = F_54 ( & V_72 , V_69 ,
V_67 , - 1 ) ;
V_69 += V_47 ;
V_67 -= V_47 ;
}
V_68 = F_53 ( struct V_74 , V_72 ) ;
V_22 = 0 ;
while ( V_68 + sizeof( V_72 ) <=
F_37 ( V_66 ) ) {
V_47 = F_52 ( V_66 ,
V_68 , & V_72 , sizeof( V_72 ) ) ;
if ( V_47 >= 0 ) {
V_47 = F_54
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
F_55 ( struct V_18 * V_19 , char * V_3 )
{
struct V_23 * V_24 = F_8 ( V_19 ) ;
return snprintf ( V_3 , V_4 , L_1 , V_24 -> V_77 ) ;
}
static int
F_56 ( struct V_23 * V_24 )
{
struct V_78 V_77 =
F_57 ( V_77 , V_50 , F_55 , NULL ) ;
V_24 -> V_79 = V_77 ;
return F_58 ( & V_24 -> V_59 , & V_24 -> V_79 ) ;
}
static void
F_59 ( struct V_23 * V_24 )
{
F_60 ( & V_24 -> V_59 , & V_24 -> V_79 ) ;
}
static void
F_61 ( void * V_14 )
{
struct V_10 * V_7 = V_14 ;
struct V_23 * V_24 = F_8 ( V_7 -> V_6 . V_59 ) ;
F_62 ( & V_7 -> V_80 ) ;
if ( V_24 -> V_81 )
V_24 -> V_81 ( V_7 ) ;
F_63 ( & V_7 -> V_80 ) ;
if ( ! F_64 ( V_7 -> V_31 ) )
F_65 ( & V_7 -> V_6 ) ;
}
static void
F_66 ( struct V_10 * V_7 )
{
if ( V_7 -> V_82 )
return;
F_67 ( & V_7 -> V_6 ) ;
if ( ! F_68 ( V_7 -> V_31 ) )
F_65 ( & V_7 -> V_6 ) ;
}
static void
F_69 ( struct V_10 * V_7 )
{
if ( F_70 ( V_7 -> V_31 ) )
F_65 ( & V_7 -> V_6 ) ;
}
static int
F_71 ( struct V_6 * V_14 )
{
int V_21 ;
struct V_23 * V_24 ;
struct V_10 * V_7 ;
V_24 = F_8 ( V_14 -> V_59 ) ;
V_7 = F_3 ( V_14 ) ;
F_62 ( & V_7 -> V_80 ) ;
V_7 -> V_82 = false ;
F_72 () ;
F_67 ( & V_7 -> V_6 ) ;
if ( ! V_24 -> V_83 ) {
F_63 ( & V_7 -> V_80 ) ;
V_21 = - V_84 ;
goto V_26;
}
V_21 = V_24 -> V_83 ( V_7 ) ;
if ( V_21 < 0 )
goto V_26;
F_73 ( V_7 ) ;
F_63 ( & V_7 -> V_80 ) ;
V_21 = 0 ;
V_26:
if ( V_21 != 0 )
F_65 ( & V_7 -> V_6 ) ;
return V_21 ;
}
static int
F_74 ( struct V_6 * V_14 )
{
struct V_10 * V_7 ;
struct V_23 * V_24 ;
V_7 = F_3 ( V_14 ) ;
V_24 = F_8 ( V_14 -> V_59 ) ;
F_62 ( & V_7 -> V_80 ) ;
V_7 -> V_82 = true ;
F_72 () ;
if ( V_24 ) {
if ( V_24 -> remove )
V_24 -> remove ( V_7 ) ;
}
F_63 ( & V_7 -> V_80 ) ;
F_69 ( V_7 ) ;
F_29 ( V_7 ) ;
F_65 ( & V_7 -> V_6 ) ;
return 0 ;
}
int F_75 ( struct V_23 * V_24 )
{
int V_21 = 0 ;
if ( V_85 < 0 )
return - V_84 ;
V_24 -> V_59 . V_30 = V_24 -> V_30 ;
V_24 -> V_59 . V_2 = & V_86 ;
V_24 -> V_59 . V_83 = F_71 ;
V_24 -> V_59 . remove = F_74 ;
V_24 -> V_59 . V_87 = V_24 -> V_87 ;
V_21 = F_76 ( & V_24 -> V_59 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_56 ( V_24 ) ;
if ( V_21 < 0 )
F_77 ( & V_24 -> V_59 ) ;
return V_21 ;
}
void
F_78 ( struct V_23 * V_24 )
{
F_59 ( V_24 ) ;
F_77 ( & V_24 -> V_59 ) ;
}
int
F_79 ( struct V_10 * V_7 , unsigned long V_88 ,
void * V_89 , unsigned long V_64 )
{
return F_52 ( V_7 -> V_13 , V_88 , V_89 , V_64 ) ;
}
int
F_80 ( struct V_10 * V_7 , unsigned long V_88 ,
void * V_90 , unsigned long V_64 )
{
return F_81 ( V_7 -> V_13 , V_88 , V_90 , V_64 ) ;
}
int
F_82 ( struct V_10 * V_7 , unsigned long V_88 , T_5 V_91 ,
unsigned long V_64 )
{
return F_83 ( V_7 -> V_13 , V_88 , V_91 , V_64 ) ;
}
int
F_84 ( struct V_10 * V_7 ,
const char * V_30 , int V_35 , int V_36 )
{
return F_22 ( V_7 , V_30 , V_35 , V_36 ) ;
}
void
F_85 ( struct V_10 * V_7 )
{
F_66 ( V_7 ) ;
}
void
F_86 ( struct V_10 * V_7 )
{
F_69 ( V_7 ) ;
}
static int
F_87 ( struct V_10 * V_7 )
{
int V_21 ;
T_6 V_92 = V_7 -> V_92 ;
T_6 V_73 = V_7 -> V_73 ;
F_88 ( V_93 , V_73 , V_92 ,
V_94 ) ;
F_89 ( & V_7 -> V_80 , 1 ) ;
V_7 -> V_6 . V_2 = & V_86 ;
V_7 -> V_6 . V_95 = V_96 ;
F_90 ( & V_7 -> V_6 ) ;
V_7 -> V_6 . V_97 = F_13 ;
F_67 ( & V_7 -> V_6 ) ;
V_7 -> V_31 =
F_91 ( V_98 ,
V_99 ,
F_61 ,
V_7 , F_92 ( & V_7 -> V_6 ) ) ;
if ( ! V_7 -> V_31 ) {
F_93 ( V_100 , V_73 ,
V_101 ) ;
V_21 = - V_102 ;
goto V_26;
}
F_94 ( & V_7 -> V_6 , L_11 ,
V_92 , V_73 ) ;
V_21 = F_95 ( & V_7 -> V_6 ) ;
if ( V_21 < 0 ) {
F_93 ( V_103 , V_92 ,
V_101 ) ;
goto V_26;
}
V_21 = F_23 ( V_7 ) ;
if ( V_21 < 0 ) {
F_93 ( V_104 , V_73 ,
V_101 ) ;
goto V_105;
}
F_96 ( & V_7 -> V_106 , & V_107 ) ;
return 0 ;
V_105:
F_97 ( & V_7 -> V_6 ) ;
V_26:
F_65 ( & V_7 -> V_6 ) ;
return V_21 ;
}
static void
F_98 ( struct V_10 * V_7 )
{
F_99 ( & V_7 -> V_106 ) ;
F_31 ( V_7 ) ;
F_65 ( & V_7 -> V_6 ) ;
F_97 ( & V_7 -> V_6 ) ;
}
static int
F_100 ( struct V_13 * V_108 ,
struct V_109 * V_110 )
{
if ( ! F_101 ( F_102 ( V_108 ) ) )
return - V_102 ;
if ( F_52 ( V_108 , sizeof( struct V_111 ) , V_110 ,
sizeof( * V_110 ) ) < 0 ) {
return - V_112 ;
}
if ( V_110 -> V_113 < sizeof( struct V_109 ) )
return - V_102 ;
if ( V_110 -> V_114 <
sizeof( struct V_71 ) ) {
return - V_102 ;
}
return 0 ;
}
static int
F_103 ( struct V_13 * V_108 ,
struct V_109 * V_110 ,
struct V_71 * V_115 )
{
int V_68 = sizeof( struct V_111 ) + V_110 -> V_116 ;
if ( V_110 -> V_116 == 0 )
return - 1 ;
if ( F_81 ( V_108 , V_68 , V_115 , sizeof( * V_115 ) ) < 0 )
return - 1 ;
return 0 ;
}
static int
F_104 ( struct V_13 * V_108 ,
struct V_109 * V_110 ,
struct V_71 * V_115 )
{
int V_68 = sizeof( struct V_111 ) + V_110 -> V_117 ;
if ( V_110 -> V_117 == 0 )
return - 1 ;
if ( F_81 ( V_108 , V_68 , V_115 , sizeof( * V_115 ) ) < 0 )
return - 1 ;
return 0 ;
}
static int
F_105 ( struct V_13 * V_108 ,
struct V_109 * V_110 ,
struct V_71 * V_115 , int V_118 )
{
int V_68 =
( sizeof( struct V_111 ) + V_110 -> V_119 ) +
( V_110 -> V_114 * V_118 ) ;
if ( V_110 -> V_119 == 0 )
return - 1 ;
if ( F_81 ( V_108 , V_68 , V_115 , sizeof( * V_115 ) ) < 0 )
return - 1 ;
return 0 ;
}
static void
F_73 ( struct V_10 * V_120 )
{
int V_22 ;
struct V_10 * V_121 ;
struct V_23 * V_122 ;
int V_123 = V_120 -> V_92 ;
int V_124 = V_120 -> V_73 ;
struct V_71 V_72 ;
const char * V_125 = NULL ;
struct V_109 * V_110 ;
if ( ! V_120 -> V_6 . V_59 )
return;
V_110 = (struct V_109 * ) V_120 -> V_126 ;
if ( ! V_110 )
return;
V_121 = F_106 ( V_123 , V_127 , NULL ) ;
if ( ! V_121 )
return;
V_122 = F_8 ( V_120 -> V_6 . V_59 ) ;
for ( V_22 = 0 ; V_122 -> V_28 [ V_22 ] . V_30 ; V_22 ++ ) {
if ( memcmp ( & V_122 -> V_28 [ V_22 ] . V_12 ,
& V_120 -> V_128 ,
sizeof( V_122 -> V_28 [ V_22 ] . V_12 ) ) == 0 ) {
V_125 = V_122 -> V_28 [ V_22 ] . V_30 ;
break;
}
}
F_107 ( & V_72 , V_125 ,
V_122 -> V_30 , V_122 -> V_77 ,
V_122 -> V_129 ) ;
F_105 ( V_121 -> V_13 , V_110 , & V_72 , V_124 ) ;
F_103 ( V_121 -> V_13 , V_110 , & V_130 ) ;
F_104 ( V_121 -> V_13 , V_110 ,
& V_131 ) ;
}
static int
F_108 ( struct V_10 * V_7 )
{
int V_132 = V_7 -> V_92 ;
struct V_109 * V_110 ;
F_109 ( V_133 , V_94 ) ;
V_110 = F_24 ( sizeof( * V_110 ) , V_48 ) ;
if ( ! V_110 )
return - V_17 ;
F_94 ( & V_7 -> V_6 , L_12 , V_132 ) ;
V_7 -> V_6 . V_2 = & V_86 ;
V_7 -> V_6 . V_95 = V_134 ;
V_7 -> V_6 . V_97 = F_10 ;
if ( F_110 ( & V_7 -> V_6 ) < 0 ) {
F_93 ( V_100 , V_132 ,
V_135 ) ;
F_12 ( V_110 ) ;
return - V_84 ;
}
if ( F_100 ( V_7 -> V_13 , V_110 ) >= 0 ) {
V_7 -> V_126 = ( void * ) V_110 ;
F_103 ( V_7 -> V_13 , V_110 ,
& V_130 ) ;
F_104 ( V_7 -> V_13 , V_110 ,
& V_131 ) ;
} else {
F_12 ( V_110 ) ;
}
V_136 ++ ;
F_96 ( & V_7 -> V_106 , & V_137 ) ;
F_111 ( & V_7 -> V_6 , V_7 ) ;
return 0 ;
}
static void
F_112 ( struct V_10 * V_7 )
{
V_136 -- ;
if ( V_7 -> V_13 ) {
F_15 ( V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
}
F_12 ( V_7 -> V_126 ) ;
F_99 ( & V_7 -> V_106 ) ;
F_97 ( & V_7 -> V_6 ) ;
}
static int
F_113 ( void )
{
V_85 = F_114 ( & V_86 ) ;
return V_85 ;
}
static void
F_115 ( void )
{
F_116 ( & V_86 ) ;
}
static void
F_117 ( void )
{
struct V_138 * V_139 , * V_140 ;
F_118 (listentry, listtmp, &list_all_device_instances) {
struct V_10 * V_7 = F_119 ( V_139 ,
struct V_10 ,
V_106 ) ;
F_98 ( V_7 ) ;
}
}
static void
F_120 ( struct V_10 * V_7 )
{
int V_21 ;
T_6 V_123 = V_7 -> V_92 ;
F_93 ( V_133 , V_123 , V_94 ) ;
V_21 = F_108 ( V_7 ) ;
F_93 ( V_141 , V_123 , V_94 ) ;
if ( V_21 < 0 )
F_93 ( V_142 , V_123 ,
V_135 ) ;
else
F_93 ( V_143 , V_123 ,
V_94 ) ;
if ( V_144 . V_145 )
(* V_144 . V_145 ) ( V_7 , V_21 ) ;
}
static void
F_121 ( struct V_10 * V_7 )
{
F_112 ( V_7 ) ;
if ( V_144 . V_146 )
(* V_144 . V_146 )( V_7 , 0 ) ;
}
static void
F_122 ( struct V_10 * V_72 )
{
int V_21 ;
T_6 V_123 = V_72 -> V_92 ;
T_6 V_124 = V_72 -> V_73 ;
F_88 ( V_93 , V_124 , V_123 ,
V_94 ) ;
V_21 = F_87 ( V_72 ) ;
if ( V_144 . V_147 )
V_144 . V_147 ( V_72 , V_21 ) ;
if ( V_21 < 0 )
F_88 ( V_100 , V_124 , V_123 ,
V_135 ) ;
else
F_88 ( V_148 , V_124 , V_123 ,
V_94 ) ;
}
static void
F_123 ( struct V_10 * V_72 )
{
F_98 ( V_72 ) ;
if ( V_144 . V_149 )
(* V_144 . V_149 ) ( V_72 , 0 ) ;
}
static void
F_124 ( struct V_10 * V_7 , int V_150 )
{
if ( ! V_7 -> V_151 )
return;
V_7 -> V_151 = false ;
if ( ! V_144 . V_152 )
return;
(* V_144 . V_152 ) ( V_7 , V_150 ) ;
}
static void
F_125 ( struct V_10 * V_7 , int V_150 )
{
if ( ! V_7 -> V_153 )
return;
V_7 -> V_153 = false ;
if ( ! V_144 . V_154 )
return;
(* V_144 . V_154 ) ( V_7 , V_150 ) ;
}
static void
F_126 ( struct V_10 * V_7 , bool V_155 )
{
int V_21 ;
struct V_23 * V_24 = NULL ;
void (* F_127)( struct V_10 * V_7 , int V_156 ) = NULL ;
if ( V_155 )
F_127 = V_144 . V_152 ;
else
F_127 = V_144 . V_154 ;
if ( ! F_127 )
return;
V_24 = F_8 ( V_7 -> V_6 . V_59 ) ;
if ( ! V_24 ) {
(* F_127)( V_7 , - V_84 ) ;
return;
}
if ( V_7 -> V_151 || V_7 -> V_153 ) {
(* F_127)( V_7 , - V_157 ) ;
return;
}
if ( V_155 ) {
if ( ! V_24 -> V_158 ) {
(* F_127)( V_7 , - V_102 ) ;
return;
}
V_7 -> V_151 = true ;
V_21 = V_24 -> V_158 ( V_7 , F_124 ) ;
} else {
F_73 ( V_7 ) ;
if ( ! V_24 -> V_159 ) {
(* F_127)( V_7 , - V_102 ) ;
return;
}
V_7 -> V_153 = true ;
V_21 = V_24 -> V_159 ( V_7 , F_125 ) ;
}
if ( V_21 < 0 ) {
if ( V_155 )
V_7 -> V_151 = false ;
else
V_7 -> V_153 = false ;
(* F_127)( V_7 , - V_102 ) ;
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
F_93 ( V_160 , V_21 , V_94 ) ;
F_107 ( & V_131 ,
L_13 , L_14 ,
V_5 , NULL ) ;
V_21 = F_113 () ;
if ( V_21 < 0 ) {
F_109 ( V_133 , V_101 ) ;
goto V_26;
}
V_99 = F_131 ( L_15 ) ;
if ( ! V_99 ) {
F_109 ( V_161 , V_101 ) ;
V_21 = - V_17 ;
goto V_26;
}
F_132 ( & V_162 ,
& V_144 ,
& V_130 ) ;
V_21 = 0 ;
V_26:
if ( V_21 )
F_93 ( V_163 , V_21 ,
V_135 ) ;
return V_21 ;
}
void
F_133 ( void )
{
struct V_138 * V_139 , * V_140 ;
F_132 ( NULL , NULL , NULL ) ;
F_117 () ;
F_134 ( V_99 ) ;
F_135 ( V_99 ) ;
V_99 = NULL ;
if ( V_164 ) {
F_136 ( & V_31 ) ;
F_134 ( V_164 ) ;
F_135 ( V_164 ) ;
V_164 = NULL ;
}
F_118 (listentry, listtmp, &list_all_bus_instances) {
struct V_10 * V_7 = F_119 ( V_139 ,
struct V_10 ,
V_106 ) ;
F_112 ( V_7 ) ;
}
F_115 () ;
}
