static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
int V_5 = 0 ;
if ( V_4 )
V_5 = F_2 ( & V_4 -> V_6 ) ;
return F_3 ( V_5 ) ;
}
static int F_4 ( struct V_3 * V_4 )
{
int V_5 = 0 ;
if ( ! V_4 || ! V_4 -> V_7 ) {
F_5 ( L_1 ) ;
return - V_8 ;
}
if ( V_4 -> V_7 -> V_9 )
V_4 -> V_10 = 1 ;
else
V_4 -> V_10 = F_6 ( V_4 -> V_7 ) ;
V_5 = F_7 ( V_4 -> V_7 -> V_1 , F_1 , V_11 ,
V_4 -> V_12 , ( void * ) V_4 ) ;
if ( V_5 ) {
F_5 ( L_2 ) ;
F_8 ( V_4 -> V_7 ) ;
}
return V_5 ;
}
static int F_9 ( struct V_3 * V_4 )
{
if ( ! V_4 || ! V_4 -> V_7 ) {
F_5 ( L_1 ) ;
return - V_8 ;
}
F_10 ( V_4 -> V_7 -> V_1 , V_4 ) ;
if ( V_4 -> V_10 )
F_8 ( V_4 -> V_7 ) ;
return 0 ;
}
struct V_13 * F_11 ( struct V_3 * V_4 , bool V_14 )
{
unsigned long V_15 = 0 ;
struct V_13 * V_16 ;
if ( ! V_4 )
return NULL ;
F_12 ( & V_4 -> V_17 , V_15 ) ;
V_16 = V_4 -> V_18 ;
if ( V_16 ) {
V_4 -> V_18 = V_4 -> V_18 -> V_19 ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
}
F_13 ( & V_4 -> V_17 , V_15 ) ;
return V_16 ;
}
void F_14 ( struct V_3 * V_4 , struct V_13 * V_20 ,
bool V_14 )
{
unsigned long V_15 = 0 ;
if ( ! V_4 || ! V_20 )
return;
F_12 ( & V_4 -> V_17 , V_15 ) ;
V_20 -> V_19 = V_4 -> V_18 ;
V_4 -> V_18 = V_20 ;
F_13 ( & V_4 -> V_17 , V_15 ) ;
}
static inline int F_15 ( unsigned long V_21 , void * V_22 , int V_23 , int V_24 )
{
int V_5 ;
if ( ! V_21 || ! V_22 ) {
F_5 ( L_3 ) ;
return - V_8 ;
}
if ( V_24 )
V_5 = F_16 ( ( void * ) V_21 , V_22 , V_23 ) ;
else
V_5 = F_17 ( V_22 , ( void * ) V_21 , V_23 ) ;
if ( V_5 ) {
F_5 ( L_4 ) ;
V_5 = - V_25 ;
}
return V_5 ;
}
static int F_18 ( struct V_3 * V_4 , struct V_13 * V_26 ,
T_2 V_27 , unsigned long V_28 )
{
unsigned long V_29 ;
int V_5 = 0 ;
if ( ! V_4 || ! V_26 || ! V_28 || ! V_27 ) {
F_5 ( L_5 ) ;
return - V_8 ;
}
V_26 -> V_30 = F_19 ( V_27 ) ;
if ( ! V_26 -> V_30 ) {
F_5 ( L_6 , V_27 ) ;
return - V_31 ;
}
V_26 -> V_32 = V_27 ;
V_29 = V_28 + sizeof( V_26 -> V_33 ) ;
V_5 = F_15 ( V_29 , V_26 -> V_30 , V_26 -> V_32 , 0 ) ;
if ( V_5 ) {
F_5 ( L_7 ,
V_26 -> V_32 , ( unsigned int ) V_29 ) ;
F_20 ( V_26 -> V_30 ) ;
V_26 -> V_30 = NULL ;
return - V_34 ;
}
return V_5 ;
}
static int F_21 ( struct V_3 * V_4 ,
struct V_13 * V_26 , unsigned long V_28 )
{
unsigned long V_29 ;
int V_5 ;
if ( ! V_4 || ! V_26 || ! V_28 ) {
F_5 ( L_5 ) ;
return - V_8 ;
}
if ( V_26 -> V_35 != V_36 ) {
V_29 = V_28 + sizeof( V_26 -> V_33 ) ;
V_5 = F_15 ( V_29 , V_26 -> V_30 ,
V_26 -> V_32 , 1 ) ;
if ( V_5 ) {
F_5 ( L_8 ,
V_26 -> V_32 , ( unsigned int ) V_29 ) ;
return - V_34 ;
}
}
if ( V_26 -> V_30 ) {
F_22 ( V_26 -> V_30 ) ;
V_26 -> V_30 = NULL ;
}
return 0 ;
}
static int F_23 ( struct V_3 * V_4 ,
struct V_13 * V_26 ,
unsigned long V_28 , int V_24 )
{
int V_5 ;
T_2 V_27 = 0 ;
if ( ! V_4 || ! V_26 || ! V_28 ) {
F_5 ( L_5 ) ;
return - V_8 ;
}
V_5 = F_15 ( V_28 , & V_26 -> V_33 , sizeof( V_26 -> V_33 ) , V_24 ) ;
if ( V_5 ) {
F_5 ( L_9 , ( V_24 ? L_10 : L_11 ) ) ;
return V_5 ;
}
switch ( V_26 -> V_35 ) {
case V_37 :
case V_38 :
case V_36 :
V_27 = V_26 -> V_33 . V_39 . V_40 . V_41 * 4 ;
if ( V_24 )
V_5 = F_21 ( V_4 , V_26 , V_28 ) ;
else
V_5 = F_18 ( V_4 , V_26 , V_27 , V_28 ) ;
break;
default:
break;
}
return V_5 ;
}
static int F_24 ( struct V_3 * V_4 , unsigned long V_28 ,
T_2 V_42 , T_2 V_35 , T_3 V_43 )
{
int V_5 ;
struct V_13 * V_16 ;
enum V_44 V_45 = V_46 ;
V_16 = F_11 ( V_4 , 0 ) ;
if ( ! V_16 ) {
F_5 ( L_12 ) ;
return - V_8 ;
}
V_16 -> V_47 = V_42 ;
V_16 -> V_35 = V_35 ;
V_5 = F_23 ( V_4 , V_16 , V_28 , 0 ) ;
if ( ! V_5 ) {
V_45 = V_43 ( & V_4 -> V_6 , V_16 ) ;
if ( V_45 == V_48 )
V_45 = V_49 ;
V_16 -> V_33 . V_50 = V_45 ;
V_5 = F_23 ( V_4 , V_16 , V_28 , 1 ) ;
}
if ( V_16 ) {
F_14 ( V_4 , V_16 , 0 ) ;
V_16 = NULL ;
}
return V_5 ;
}
static long F_25 ( struct V_51 * V_52 , unsigned int V_35 , unsigned long V_28 )
{
struct V_3 * V_4 = F_26 () ;
T_3 V_53 ;
struct V_54 * V_55 ;
int V_56 ;
if ( ! V_4 || ! V_52 ) {
F_5 ( L_13 ) ;
return - V_8 ;
}
V_55 = V_52 -> V_57 ;
if ( ! V_55 ) {
F_5 ( L_14 ) ;
return - V_34 ;
}
F_27 ( & V_58 ) ;
V_53 = F_28 ( & V_4 -> V_6 , V_35 , V_55 ) ;
if ( ! V_53 ) {
F_5 ( L_15 , V_35 ) ;
F_29 ( & V_58 ) ;
return - V_8 ;
}
V_56 = F_24 ( V_4 , V_28 , V_55 -> V_42 , V_35 , V_53 ) ;
F_29 ( & V_58 ) ;
return V_56 ;
}
static int F_30 ( struct V_59 * V_60 , struct V_51 * V_52 )
{
struct V_3 * V_4 = F_26 () ;
int V_5 = 0 ;
enum V_44 V_45 = V_46 ;
struct V_54 * V_55 = NULL ;
if ( ! V_4 ) {
F_5 ( L_13 ) ;
return - V_8 ;
}
if ( V_4 -> V_61 >= V_62 ) {
F_31 ( V_63 , L_16 , V_4 -> V_61 ) ;
return - V_64 ;
}
V_45 = F_32 ( & V_4 -> V_6 , & V_55 ) ;
if ( V_45 != V_46 ) {
F_5 ( L_17 , V_45 ) ;
V_5 = - V_64 ;
}
V_4 -> V_61 ++ ;
V_52 -> V_57 = V_55 ;
return V_5 ;
}
static int F_33 ( struct V_59 * V_60 , struct V_51 * V_52 )
{
struct V_3 * V_4 = F_26 () ;
struct V_54 * V_55 ;
if ( ! V_4 ) {
F_5 ( L_13 ) ;
return - V_8 ;
}
V_55 = V_52 -> V_57 ;
if ( ! V_55 ) {
F_5 ( L_14 ) ;
return - V_34 ;
}
F_34 ( & V_4 -> V_6 , V_55 ) ;
V_4 -> V_61 -- ;
return 0 ;
}
static int T_4 F_35 ( struct V_3 * V_4 )
{
struct V_13 * V_16 ;
struct V_65 * V_66 ;
int V_5 = - V_67 , V_68 = 0 ;
if ( ! V_4 )
goto V_69;
V_4 -> V_70 = F_36 ( 0 , V_71 ,
& V_72 ) ;
if ( V_4 -> V_70 < 0 ) {
F_5 ( L_18 ) ;
V_5 = V_4 -> V_70 ;
goto V_69;
}
V_73 = F_37 ( V_74 , L_19 ) ;
if ( F_38 ( V_73 ) ) {
F_5 ( L_20 ) ;
goto V_69;
}
V_66 = F_39 ( V_73 , NULL , F_40 ( V_4 -> V_70 , 0 ) ,
NULL , L_19 ) ;
if ( F_38 ( V_66 ) ) {
F_5 ( L_21 ) ;
goto V_75;
}
V_5 = F_41 ( V_4 , V_76 ) ;
if ( V_5 ) {
F_5 ( L_21 ) ;
goto V_77;
}
for ( V_68 = 0 ; V_68 < V_78 ; V_68 ++ ) {
V_16 = F_42 ( sizeof( struct V_13 ) , V_79 ) ;
if ( ! V_16 ) {
F_5 ( L_22 ) ;
V_5 = - V_31 ;
goto V_80;
}
F_14 ( V_4 , V_16 , 0 ) ;
}
return 0 ;
V_80:
F_43 ( V_4 ) ;
V_77:
F_44 ( V_73 , F_40 ( V_4 -> V_70 , 0 ) ) ;
V_75:
F_45 ( V_73 ) ;
V_69:
return V_5 ;
}
static void T_5 F_46 ( struct V_3 * V_4 )
{
struct V_13 * V_16 = NULL ;
if ( ! V_4 )
return;
if ( V_4 -> V_70 > 0 ) {
F_44 ( V_73 , F_40 ( V_4 -> V_70 , 0 ) ) ;
F_47 ( V_4 -> V_70 , V_71 ) ;
F_31 ( V_63 , L_23 ,
V_4 -> V_70 ) ;
F_45 ( V_73 ) ;
}
V_4 -> V_70 = 0 ;
do {
V_16 = F_11 ( V_4 , 0 ) ;
F_20 ( V_16 ) ;
} while ( V_16 );
F_43 ( V_4 ) ;
}
static int T_4 F_48 ( struct V_3 * V_81 )
{
int V_5 ;
unsigned long V_82 = F_49 ( V_81 -> V_7 , 2 ) ;
T_2 V_83 = F_50 ( V_81 -> V_7 , 2 ) ;
unsigned long V_84 = F_49 ( V_81 -> V_7 , 0 ) ;
T_2 V_85 = F_50 ( V_81 -> V_7 , 0 ) ;
F_31 ( V_86 , L_24 ,
V_82 , V_83 , V_84 , V_85 ) ;
V_5 = F_51 ( V_82 , V_83 ) ;
if ( V_5 ) {
F_5 ( L_25 ) ;
return - V_31 ;
}
V_81 -> V_87 = F_52 ( V_82 , V_83 ) ;
if ( ! V_81 -> V_87 ) {
F_5 ( L_26 ) ;
return - V_31 ;
}
V_81 -> V_88 = V_82 ;
V_81 -> V_89 = V_83 ;
V_5 = F_51 ( V_84 , V_85 ) ;
if ( V_5 ) {
F_5 ( L_25 ) ;
return - V_31 ;
}
V_81 -> V_90 = F_52 ( V_84 , V_85 ) ;
if ( ! V_81 -> V_90 ) {
F_5 ( L_26 ) ;
return - V_31 ;
}
V_81 -> V_91 = V_84 ;
V_81 -> V_92 = V_85 ;
V_5 = F_53 ( V_81 -> V_7 , V_81 -> V_12 ) ;
if ( V_5 < 0 ) {
F_5 ( L_27 , V_5 ) ;
return V_5 ;
}
F_31 ( V_86 , L_28 ,
( unsigned long ) V_81 -> V_87 , ( unsigned long ) V_81 -> V_90 ) ;
return 0 ;
}
static void T_5 F_54 ( struct V_3 * V_81 )
{
if ( ! V_81 )
return;
if ( V_81 -> V_87 )
F_55 ( V_81 -> V_87 ) ;
if ( V_81 -> V_90 )
F_55 ( V_81 -> V_90 ) ;
F_56 ( V_81 -> V_7 ) ;
}
static void T_5 F_57 ( struct V_93 * V_7 )
{
struct V_3 * V_81 ;
enum V_44 V_45 = V_46 ;
V_81 = F_58 ( V_7 ) ;
if ( ! V_81 ) {
F_5 ( L_29 ) ;
return;
}
V_45 = F_59 ( & V_81 -> V_6 ) ;
if ( V_45 != V_46 )
F_5 ( L_30 , V_45 ) ;
F_46 ( V_81 ) ;
F_9 ( V_81 ) ;
F_54 ( V_81 ) ;
F_60 ( V_81 -> V_7 ) ;
F_20 ( V_81 ) ;
V_94 = NULL ;
}
static int T_4 F_61 ( struct V_93 * V_7 ,
const struct V_95 * V_96 )
{
struct V_3 * V_81 ;
int V_5 ;
enum V_44 V_45 = V_46 ;
F_31 ( V_97 , L_31
L_32 ,
V_7 -> V_98 , V_7 -> V_65 , V_7 -> V_99 ,
V_7 -> V_100 ) ;
V_81 = F_42 ( sizeof( struct V_3 ) , V_79 ) ;
if ( ! V_81 ) {
F_5 ( L_33 ) ;
return - V_31 ;
}
V_81 -> V_7 = V_7 ;
V_5 = F_62 ( V_7 ) ;
if ( V_5 ) {
F_5 ( L_34 ) ;
goto V_101;
}
snprintf ( V_81 -> V_12 , sizeof( V_81 -> V_12 ) , L_35 ,
V_7 -> V_102 -> V_103 , F_63 ( V_7 -> V_104 ) ,
F_64 ( V_7 -> V_104 ) ) ;
V_5 = F_48 ( V_81 ) ;
if ( V_5 ) {
F_5 ( L_36 ) ;
F_60 ( V_7 ) ;
V_5 = - V_31 ;
goto V_101;
}
V_81 -> V_105 = 1 ;
V_81 -> V_106 = V_96 -> V_107 ;
F_65 ( & V_81 -> V_17 ) ;
F_35 ( V_81 ) ;
V_5 = F_4 ( V_81 ) ;
if ( V_5 ) {
F_5 ( L_37 , V_5 ) ;
F_60 ( V_7 ) ;
V_5 = - V_67 ;
goto V_101;
}
if ( ! F_66 ( V_7 , F_67 ( 64 ) ) ) {
F_68 ( V_7 , F_67 ( 64 ) ) ;
V_81 -> V_108 = 64 ;
} else if ( ! F_66 ( V_7 , F_67 ( 32 ) ) ) {
F_68 ( V_7 , F_67 ( 32 ) ) ;
V_81 -> V_108 = 32 ;
} else {
F_5 ( L_38 , V_5 ) ;
F_60 ( V_7 ) ;
V_5 = - V_67 ;
goto V_101;
}
V_45 = F_69 ( & V_81 -> V_6 , V_81 ) ;
if ( V_45 != V_46 ) {
F_5 ( L_39 , V_45 ) ;
F_60 ( V_7 ) ;
V_5 = - V_67 ;
goto V_101;
}
F_70 ( V_7 ) ;
F_71 ( V_7 , V_81 ) ;
V_94 = V_81 ;
return 0 ;
V_101:
F_20 ( V_81 ) ;
return V_5 ;
}
int F_72 ( struct V_93 * V_7 , T_6 V_109 )
{
struct V_3 * V_4 ;
struct V_13 * V_16 ;
enum V_44 V_45 = V_46 ;
V_4 = F_58 ( V_7 ) ;
if ( ! V_4 ) {
F_5 ( L_29 ) ;
return - V_67 ;
}
V_16 = F_11 ( V_4 , false ) ;
if ( ! V_16 ) {
F_5 ( L_40 ) ;
return - V_67 ;
}
V_45 = F_73 ( & V_4 -> V_6 , V_16 ) ;
if ( V_45 != V_46 ) {
F_5 ( L_41 , V_45 ) ;
return - V_67 ;
}
F_14 ( V_4 , V_16 , false ) ;
F_9 ( V_4 ) ;
F_74 ( V_7 ) ;
F_60 ( V_7 ) ;
F_75 ( V_7 , F_76 ( V_7 , V_109 ) ) ;
return 0 ;
}
int F_77 ( struct V_93 * V_7 )
{
struct V_3 * V_4 ;
enum V_44 V_45 = V_46 ;
int V_5 ;
V_4 = F_58 ( V_7 ) ;
if ( ! V_4 ) {
F_5 ( L_29 ) ;
return - V_67 ;
}
F_75 ( V_7 , V_110 ) ;
F_78 ( V_7 ) ;
if ( F_62 ( V_7 ) ) {
F_5 ( L_34 ) ;
return 1 ;
}
F_70 ( V_7 ) ;
V_5 = F_4 ( V_4 ) ;
if ( V_5 ) {
F_5 ( L_37 , V_5 ) ;
F_60 ( V_7 ) ;
return - V_67 ;
}
V_45 = F_79 ( & V_4 -> V_6 ) ;
if ( V_45 != V_46 ) {
F_5 ( L_42 , V_45 ) ;
F_60 ( V_7 ) ;
return - V_67 ;
}
return 0 ;
}
void F_80 ( struct V_3 * V_4 , char * V_2 )
{
if ( ( ! V_2 ) || ( strlen ( V_2 ) < 3 ) )
V_111 = V_112 | V_113 ;
else if ( ! strncmp ( V_2 , L_43 , 5 ) )
V_111 = V_63 | V_113 | V_97 |
V_86 | V_112 ;
else if ( ! strncmp ( V_2 , L_44 , 4 ) )
V_111 = V_112 | V_113 | V_63 ;
else if ( ! strncmp ( V_2 , L_45 , 5 ) )
V_111 = V_112 | V_113 | V_63 |
V_97 ;
else if ( ! strncmp ( V_2 , L_46 , 5 ) )
V_111 = 0xFFFFFFFF & ~ ( V_114 ) ;
else if ( ! strncmp ( V_2 , L_47 , 6 ) )
V_111 = 0 ;
else
V_111 = 0 ;
}
struct V_3 * F_26 ( void )
{
return V_94 ;
}
static int T_7 F_81 ( void )
{
int V_5 ;
F_80 ( NULL , L_45 ) ;
F_31 ( V_113 , L_48 ,
V_115 , V_116 , V_117 ) ;
V_5 = F_82 ( & V_118 ) ;
if ( V_5 < 0 )
F_5 ( L_49 , V_5 ) ;
return V_5 ;
}
static void T_8 F_83 ( void )
{
F_31 ( V_113 , L_50 ,
V_115 , V_116 , V_117 ) ;
F_84 ( & V_118 ) ;
}
