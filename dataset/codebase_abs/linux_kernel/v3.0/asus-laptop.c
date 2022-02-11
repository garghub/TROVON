static int F_1 ( T_1 V_1 , const char * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 V_7 ;
union V_8 V_9 ;
T_2 V_10 ;
if ( ! V_1 )
return - 1 ;
V_7 . V_11 = 1 ;
V_7 . V_12 = & V_9 ;
V_9 . type = V_13 ;
V_9 . integer . V_14 = V_3 ;
V_10 = F_2 ( V_1 , ( char * ) V_2 , & V_7 , V_5 ) ;
if ( V_10 == V_15 )
return 0 ;
else
return - 1 ;
}
static int F_3 ( T_1 V_1 , const char * V_2 , int V_3 )
{
return F_1 ( V_1 , V_2 , V_3 , NULL ) ;
}
static int F_4 ( T_1 V_1 , const char * V_2 ,
T_1 * V_16 )
{
T_2 V_10 ;
if ( V_2 == NULL )
return - V_17 ;
if ( V_16 )
V_10 = F_5 ( V_1 , ( char * ) V_2 ,
V_16 ) ;
else {
T_1 V_18 ;
V_10 = F_5 ( V_1 , ( char * ) V_2 ,
& V_18 ) ;
}
if ( V_10 != V_15 ) {
if ( V_16 )
F_6 ( L_1 , V_2 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_7 ( struct V_19 * V_20 , const char * V_2 ,
int V_14 )
{
if ( ! strcmp ( V_2 , V_21 ) )
V_14 = ! V_14 ;
else if ( ! strcmp ( V_2 , V_22 ) )
V_14 = ! V_14 + 1 ;
else
V_14 = ! ! V_14 ;
return F_3 ( V_20 -> V_1 , V_2 , V_14 ) ;
}
static void F_8 ( struct V_23 * V_24 ,
enum V_25 V_14 )
{
struct V_26 * V_27 = F_9 ( V_24 , struct V_26 , V_27 ) ;
struct V_19 * V_20 = V_27 -> V_20 ;
V_27 -> V_28 = ! ! V_14 ;
F_10 ( V_20 -> V_29 , & V_27 -> V_30 ) ;
}
static void F_11 ( struct V_31 * V_30 )
{
struct V_26 * V_27 = F_9 ( V_30 , struct V_26 , V_30 ) ;
struct V_19 * V_20 = V_27 -> V_20 ;
F_7 ( V_20 , V_27 -> V_2 , V_27 -> V_28 ) ;
}
static enum V_25 F_12 ( struct V_23 * V_24 )
{
return V_24 -> V_32 ;
}
static int F_13 ( struct V_19 * V_20 )
{
unsigned long long V_33 ;
struct V_6 V_7 ;
union V_8 V_9 ;
T_2 V_34 ;
V_7 . V_11 = 1 ;
V_7 . V_12 = & V_9 ;
V_9 . type = V_13 ;
V_9 . integer . V_14 = 2 ;
V_34 = F_14 ( V_20 -> V_1 , V_35 ,
& V_7 , & V_33 ) ;
if ( F_15 ( V_34 ) ) {
F_6 ( L_2 ) ;
return - V_17 ;
}
return V_33 ;
}
static int F_16 ( struct V_19 * V_20 , int V_33 )
{
if ( V_33 > 0 )
V_33 = ( 1 << 7 ) | ( V_33 & 0x7F ) ;
else
V_33 = 0 ;
if ( F_3 ( V_20 -> V_1 , V_36 , V_33 ) ) {
F_6 ( L_3 ) ;
return - V_37 ;
}
return 0 ;
}
static void F_17 ( struct V_23 * V_24 ,
enum V_25 V_14 )
{
struct V_26 * V_27 = F_9 ( V_24 , struct V_26 , V_27 ) ;
struct V_19 * V_20 = V_27 -> V_20 ;
V_27 -> V_28 = V_14 ;
F_10 ( V_20 -> V_29 , & V_27 -> V_30 ) ;
}
static void F_18 ( struct V_31 * V_30 )
{
struct V_26 * V_27 = F_9 ( V_30 , struct V_26 , V_30 ) ;
struct V_19 * V_20 = V_27 -> V_20 ;
F_16 ( V_20 , V_27 -> V_28 ) ;
}
static enum V_25 F_19 ( struct V_23 * V_24 )
{
struct V_26 * V_27 = F_9 ( V_24 , struct V_26 , V_27 ) ;
struct V_19 * V_20 = V_27 -> V_20 ;
return F_13 ( V_20 ) ;
}
static void F_20 ( struct V_19 * V_20 )
{
if ( V_20 -> V_38 . V_27 . V_39 )
F_21 ( & V_20 -> V_38 . V_27 ) ;
if ( V_20 -> V_40 . V_27 . V_39 )
F_21 ( & V_20 -> V_40 . V_27 ) ;
if ( V_20 -> V_41 . V_27 . V_39 )
F_21 ( & V_20 -> V_41 . V_27 ) ;
if ( V_20 -> V_42 . V_27 . V_39 )
F_21 ( & V_20 -> V_42 . V_27 ) ;
if ( V_20 -> V_43 . V_27 . V_39 )
F_21 ( & V_20 -> V_43 . V_27 ) ;
if ( V_20 -> V_44 . V_27 . V_39 )
F_21 ( & V_20 -> V_44 . V_27 ) ;
if ( V_20 -> V_29 ) {
F_22 ( V_20 -> V_29 ) ;
V_20 -> V_29 = NULL ;
}
}
static int F_23 ( struct V_19 * V_20 ,
struct V_26 * V_27 ,
const char * V_45 , const char * V_2 )
{
struct V_23 * V_24 = & V_27 -> V_27 ;
if ( ! V_2 || F_4 ( V_20 -> V_1 , V_2 , NULL ) )
return 0 ;
V_27 -> V_20 = V_20 ;
V_27 -> V_2 = V_2 ;
F_24 ( & V_27 -> V_30 , F_11 ) ;
V_24 -> V_45 = V_45 ;
V_24 -> V_46 = F_8 ;
V_24 -> V_47 = F_12 ;
V_24 -> V_48 = 1 ;
return F_25 ( & V_20 -> V_49 -> V_39 , V_24 ) ;
}
static int F_26 ( struct V_19 * V_20 )
{
int V_50 ;
V_20 -> V_29 = F_27 ( L_4 ) ;
if ( ! V_20 -> V_29 )
return - V_51 ;
V_50 = F_23 ( V_20 , & V_20 -> V_38 , L_5 , V_21 ) ;
if ( V_50 )
goto error;
V_50 = F_23 ( V_20 , & V_20 -> V_40 , L_6 , V_52 ) ;
if ( V_50 )
goto error;
V_50 = F_23 ( V_20 , & V_20 -> V_42 , L_7 , V_53 ) ;
if ( V_50 )
goto error;
V_50 = F_23 ( V_20 , & V_20 -> V_41 , L_8 , V_54 ) ;
if ( V_50 )
goto error;
V_50 = F_23 ( V_20 , & V_20 -> V_43 , L_9 , V_22 ) ;
if ( V_50 )
goto error;
if ( ! F_4 ( V_20 -> V_1 , V_36 , NULL ) &&
! F_4 ( V_20 -> V_1 , V_35 , NULL ) ) {
struct V_26 * V_27 = & V_20 -> V_44 ;
struct V_23 * V_55 = & V_27 -> V_27 ;
V_27 -> V_20 = V_20 ;
F_24 ( & V_27 -> V_30 , F_18 ) ;
V_55 -> V_45 = L_10 ;
V_55 -> V_46 = F_17 ;
V_55 -> V_47 = F_19 ;
V_55 -> V_48 = 3 ;
V_50 = F_25 ( & V_20 -> V_49 -> V_39 , V_55 ) ;
}
error:
if ( V_50 )
F_20 ( V_20 ) ;
return V_50 ;
}
static int F_28 ( struct V_56 * V_57 )
{
struct V_19 * V_20 = F_29 ( V_57 ) ;
unsigned long long V_14 ;
T_2 V_34 = V_15 ;
V_34 = F_14 ( V_20 -> V_1 , V_58 ,
NULL , & V_14 ) ;
if ( F_15 ( V_34 ) )
F_6 ( L_11 ) ;
return V_14 ;
}
static int F_30 ( struct V_56 * V_57 , int V_14 )
{
struct V_19 * V_20 = F_29 ( V_57 ) ;
if ( F_3 ( V_20 -> V_1 , V_59 , V_14 ) ) {
F_6 ( L_12 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_31 ( struct V_56 * V_57 )
{
int V_14 = V_57 -> V_61 . V_32 ;
return F_30 ( V_57 , V_14 ) ;
}
static int F_32 ( struct V_19 * V_20 )
{
struct V_56 * V_57 = V_20 -> V_56 ;
int V_62 = V_57 -> V_61 . V_32 ;
F_33 ( V_57 , V_63 ) ;
return V_62 ;
}
static int F_34 ( struct V_19 * V_20 )
{
struct V_56 * V_57 ;
struct V_64 V_61 ;
if ( F_4 ( V_20 -> V_1 , V_58 , NULL ) ||
F_4 ( V_20 -> V_1 , V_59 , NULL ) )
return 0 ;
memset ( & V_61 , 0 , sizeof( struct V_64 ) ) ;
V_61 . V_48 = 15 ;
V_61 . type = V_65 ;
V_57 = F_35 ( V_66 ,
& V_20 -> V_49 -> V_39 , V_20 ,
& V_67 , & V_61 ) ;
if ( F_36 ( V_57 ) ) {
F_37 ( L_13 ) ;
V_20 -> V_56 = NULL ;
return F_38 ( V_57 ) ;
}
V_20 -> V_56 = V_57 ;
V_57 -> V_61 . V_32 = F_28 ( V_57 ) ;
V_57 -> V_61 . V_68 = V_69 ;
F_39 ( V_57 ) ;
return 0 ;
}
static void F_40 ( struct V_19 * V_20 )
{
if ( V_20 -> V_56 )
F_41 ( V_20 -> V_56 ) ;
V_20 -> V_56 = NULL ;
}
static T_3 F_42 ( struct V_70 * V_39 ,
struct V_71 * V_72 , char * V_73 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
int V_74 = 0 ;
unsigned long long V_75 ;
char V_76 [ 16 ] ;
T_2 V_34 = V_15 ;
V_74 += sprintf ( V_73 , V_77 L_14 V_78 L_15 ) ;
V_74 += sprintf ( V_73 + V_74 , L_16 , V_20 -> V_45 ) ;
V_34 = F_14 ( V_20 -> V_1 , L_17 , NULL , & V_75 ) ;
if ( ! F_15 ( V_34 ) )
V_74 += sprintf ( V_73 + V_74 , L_18 ,
( V_79 ) V_75 ) ;
V_34 = F_14 ( V_20 -> V_1 , L_19 , NULL , & V_75 ) ;
if ( ! F_15 ( V_34 ) )
V_74 += sprintf ( V_73 + V_74 , L_20 ,
( V_79 ) V_75 ) ;
V_34 = F_14 ( V_20 -> V_1 , L_21 , NULL , & V_75 ) ;
if ( ! F_15 ( V_34 ) )
V_74 += sprintf ( V_73 + V_74 , L_22 ,
( V_79 ) V_75 ) ;
if ( V_20 -> V_80 ) {
snprintf ( V_76 , 16 , L_23 , V_20 -> V_80 -> V_81 ) ;
V_74 += sprintf ( V_73 + V_74 , L_24 , V_76 ) ;
snprintf ( V_76 , 16 , L_23 , V_20 -> V_80 -> V_82 ) ;
V_74 += sprintf ( V_73 + V_74 , L_25 , V_76 ) ;
snprintf ( V_76 , 16 , L_23 , V_20 -> V_80 -> V_83 ) ;
V_74 += sprintf ( V_73 + V_74 , L_26 , V_76 ) ;
snprintf ( V_76 , 7 , L_27 , V_20 -> V_80 -> V_84 ) ;
V_74 += sprintf ( V_73 + V_74 , L_28 , V_76 ) ;
snprintf ( V_76 , 9 , L_27 , V_20 -> V_80 -> V_85 ) ;
V_74 += sprintf ( V_73 + V_74 , L_29 , V_76 ) ;
snprintf ( V_76 , 16 , L_30 , V_20 -> V_80 -> V_86 ) ;
V_74 += sprintf ( V_73 + V_74 , L_31 , V_76 ) ;
snprintf ( V_76 , 5 , L_27 , V_20 -> V_80 -> V_87 ) ;
V_74 += sprintf ( V_73 + V_74 , L_32 , V_76 ) ;
snprintf ( V_76 , 16 , L_30 , V_20 -> V_80 -> V_88 ) ;
V_74 += sprintf ( V_73 + V_74 , L_33 , V_76 ) ;
}
return V_74 ;
}
static int F_44 ( const char * V_76 , unsigned long V_11 , int * V_3 )
{
if ( ! V_11 )
return 0 ;
if ( V_11 > 31 )
return - V_37 ;
if ( sscanf ( V_76 , L_34 , V_3 ) != 1 )
return - V_37 ;
return V_11 ;
}
static T_3 F_45 ( struct V_19 * V_20 ,
const char * V_76 , T_4 V_11 ,
const char * V_2 )
{
int V_34 , V_14 ;
int V_89 = 0 ;
V_34 = F_44 ( V_76 , V_11 , & V_14 ) ;
if ( V_34 > 0 )
V_89 = V_14 ? 1 : 0 ;
if ( F_3 ( V_20 -> V_1 , V_2 , V_14 ) )
return - V_17 ;
return V_34 ;
}
static T_3 F_46 ( struct V_70 * V_39 ,
struct V_71 * V_72 , char * V_76 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
return sprintf ( V_76 , L_35 , V_20 -> V_90 ) ;
}
static T_3 F_47 ( struct V_70 * V_39 , struct V_71 * V_72 ,
const char * V_76 , T_4 V_11 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
int V_34 , V_14 ;
V_34 = F_44 ( V_76 , V_11 , & V_14 ) ;
if ( V_34 > 0 ) {
if ( F_3 ( V_20 -> V_1 , V_91 , V_14 ) ) {
F_6 ( L_36 ) ;
return - V_17 ;
}
V_20 -> V_90 = ( V_92 ) V_14 ;
}
return V_34 ;
}
static int F_48 ( struct V_19 * V_20 , int V_93 )
{
unsigned long long V_10 ;
T_2 V_34 = V_15 ;
if ( ! V_20 -> V_94 )
return ( V_20 -> V_95 & V_93 ) ? 1 : 0 ;
V_34 = F_14 ( V_20 -> V_1 , V_96 ,
NULL , & V_10 ) ;
if ( F_15 ( V_34 ) ) {
F_6 ( L_37 ) ;
return - V_37 ;
}
return ! ! ( V_10 & V_93 ) ;
}
static int F_49 ( struct V_19 * V_20 , int V_10 )
{
if ( F_3 ( V_20 -> V_1 , V_97 , ! ! V_10 ) ) {
F_6 ( L_38 , V_10 ) ;
return - V_60 ;
}
return 0 ;
}
static T_3 F_50 ( struct V_70 * V_39 ,
struct V_71 * V_72 , char * V_76 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
return sprintf ( V_76 , L_39 , F_48 ( V_20 , V_98 ) ) ;
}
static T_3 F_51 ( struct V_70 * V_39 , struct V_71 * V_72 ,
const char * V_76 , T_4 V_11 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
return F_45 ( V_20 , V_76 , V_11 , V_97 ) ;
}
static int F_52 ( struct V_19 * V_20 , int V_10 )
{
if ( F_3 ( V_20 -> V_1 , V_99 , ! ! V_10 ) ) {
F_6 ( L_40 , V_10 ) ;
return - V_60 ;
}
return 0 ;
}
static T_3 F_53 ( struct V_70 * V_39 ,
struct V_71 * V_72 , char * V_76 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
return sprintf ( V_76 , L_39 , F_48 ( V_20 , V_100 ) ) ;
}
static T_3 F_54 ( struct V_70 * V_39 ,
struct V_71 * V_72 , const char * V_76 ,
T_4 V_11 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
return F_45 ( V_20 , V_76 , V_11 , V_99 ) ;
}
static int F_55 ( struct V_19 * V_20 , int V_10 )
{
if ( F_3 ( V_20 -> V_1 , V_101 , ! ! V_10 ) ) {
F_6 ( L_41 , V_10 ) ;
return - V_60 ;
}
return 0 ;
}
static T_3 F_56 ( struct V_70 * V_39 ,
struct V_71 * V_72 , char * V_76 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
return sprintf ( V_76 , L_39 , F_48 ( V_20 , V_102 ) ) ;
}
static T_3 F_57 ( struct V_70 * V_39 ,
struct V_71 * V_72 , const char * V_76 ,
T_4 V_11 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
return F_45 ( V_20 , V_76 , V_11 , V_101 ) ;
}
static int F_58 ( struct V_19 * V_20 , int V_10 )
{
if ( F_3 ( V_20 -> V_1 , V_103 , ! ! V_10 ) ) {
F_6 ( L_42 , V_10 ) ;
return - V_60 ;
}
return 0 ;
}
static T_3 F_59 ( struct V_70 * V_39 ,
struct V_71 * V_72 , char * V_76 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
return sprintf ( V_76 , L_39 , F_48 ( V_20 , V_104 ) ) ;
}
static T_3 F_60 ( struct V_70 * V_39 ,
struct V_71 * V_72 , const char * V_76 ,
T_4 V_11 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
return F_45 ( V_20 , V_76 , V_11 , V_103 ) ;
}
static void F_61 ( struct V_19 * V_20 , int V_14 )
{
if ( F_3 ( V_20 -> V_1 , V_105 , V_14 ) )
F_6 ( L_43 ) ;
return;
}
static T_3 F_62 ( struct V_70 * V_39 , struct V_71 * V_72 ,
const char * V_76 , T_4 V_11 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
int V_34 , V_14 ;
V_34 = F_44 ( V_76 , V_11 , & V_14 ) ;
if ( V_34 > 0 )
F_61 ( V_20 , V_14 ) ;
return V_34 ;
}
static void F_63 ( struct V_19 * V_20 , int V_14 )
{
if ( F_3 ( V_20 -> V_1 , V_106 , V_14 ) )
F_6 ( L_44 ) ;
V_20 -> V_107 = V_14 ;
}
static T_3 F_64 ( struct V_70 * V_39 ,
struct V_71 * V_72 , char * V_76 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
return sprintf ( V_76 , L_39 , V_20 -> V_107 ) ;
}
static T_3 F_65 ( struct V_70 * V_39 , struct V_71 * V_72 ,
const char * V_76 , T_4 V_11 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
int V_34 , V_14 ;
V_34 = F_44 ( V_76 , V_11 , & V_14 ) ;
if ( V_34 > 0 )
F_63 ( V_20 , V_14 ? 1 : 0 ) ;
return V_34 ;
}
static void F_66 ( struct V_19 * V_20 , int V_14 )
{
if ( F_3 ( V_20 -> V_1 , V_108 , V_14 ) )
F_6 ( L_45 ) ;
V_20 -> V_109 = V_14 ;
}
static T_3 F_67 ( struct V_70 * V_39 ,
struct V_71 * V_72 , char * V_76 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
return sprintf ( V_76 , L_39 , V_20 -> V_109 ) ;
}
static T_3 F_68 ( struct V_70 * V_39 , struct V_71 * V_72 ,
const char * V_76 , T_4 V_11 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
int V_34 , V_14 ;
V_34 = F_44 ( V_76 , V_11 , & V_14 ) ;
if ( V_34 > 0 ) {
V_14 = ( 0 < V_14 ) ? ( ( 15 < V_14 ) ? 15 : V_14 ) : 0 ;
F_66 ( V_20 , V_14 ) ;
}
return V_34 ;
}
static int F_69 ( struct V_19 * V_20 )
{
unsigned long long V_10 ;
T_2 V_34 = V_15 ;
V_34 = F_14 ( V_20 -> V_1 , V_110 ,
NULL , & V_10 ) ;
if ( F_15 ( V_34 ) ) {
F_6 ( L_46 ) ;
return - V_17 ;
}
return ! ! V_10 ;
}
static int F_70 ( struct V_19 * V_20 , int V_10 )
{
const char * V_111 = V_10 ? V_112 : V_113 ;
if ( F_3 ( V_20 -> V_1 , V_111 , 0x02 ) )
return - V_17 ;
return 0 ;
}
static T_3 F_71 ( struct V_70 * V_39 ,
struct V_71 * V_72 , char * V_76 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
return sprintf ( V_76 , L_39 , F_69 ( V_20 ) ) ;
}
static T_3 F_72 ( struct V_70 * V_39 , struct V_71 * V_72 ,
const char * V_76 , T_4 V_11 )
{
struct V_19 * V_20 = F_43 ( V_39 ) ;
int V_34 , V_14 ;
int V_16 ;
V_34 = F_44 ( V_76 , V_11 , & V_14 ) ;
if ( V_34 <= 0 )
return - V_37 ;
V_16 = F_70 ( V_20 , ! ! V_14 ) ;
if ( V_16 )
return V_16 ;
F_73 ( V_20 -> V_114 , ! V_14 ) ;
return V_34 ;
}
static int F_74 ( void * V_115 , bool V_116 )
{
struct V_19 * V_20 = V_115 ;
return F_70 ( V_20 , ! V_116 ) ;
}
static void F_75 ( struct V_19 * V_20 )
{
if ( V_20 -> V_114 ) {
F_76 ( V_20 -> V_114 ) ;
F_77 ( V_20 -> V_114 ) ;
V_20 -> V_114 = NULL ;
}
}
static int F_78 ( struct V_19 * V_20 )
{
int V_117 ;
if ( F_4 ( V_20 -> V_1 , V_112 , NULL ) ||
F_4 ( V_20 -> V_1 , V_113 , NULL ) ||
F_4 ( V_20 -> V_1 , V_110 , NULL ) )
return 0 ;
V_20 -> V_114 = F_79 ( L_47 , & V_20 -> V_49 -> V_39 ,
V_118 ,
& V_119 , V_20 ) ;
if ( ! V_20 -> V_114 )
return - V_37 ;
V_117 = F_80 ( V_20 -> V_114 ) ;
if ( V_117 ) {
F_77 ( V_20 -> V_114 ) ;
V_20 -> V_114 = NULL ;
}
return V_117 ;
}
static void F_81 ( struct V_19 * V_20 , int V_120 )
{
if ( V_20 -> V_121 )
F_82 ( V_20 -> V_121 , V_120 , 1 , true ) ;
}
static int F_83 ( struct V_19 * V_20 )
{
struct V_122 * V_123 ;
int error ;
V_123 = F_84 () ;
if ( ! V_123 ) {
F_85 ( L_48 ) ;
return - V_51 ;
}
V_123 -> V_45 = L_49 ;
V_123 -> V_124 = V_66 L_50 ;
V_123 -> V_125 . V_126 = V_127 ;
V_123 -> V_39 . V_128 = & V_20 -> V_49 -> V_39 ;
error = F_86 ( V_123 , V_129 , NULL ) ;
if ( error ) {
F_37 ( L_51 ) ;
goto V_130;
}
error = F_87 ( V_123 ) ;
if ( error ) {
F_85 ( L_52 ) ;
goto V_131;
}
V_20 -> V_121 = V_123 ;
return 0 ;
V_131:
F_88 ( V_123 ) ;
V_130:
F_89 ( V_123 ) ;
return error ;
}
static void F_90 ( struct V_19 * V_20 )
{
if ( V_20 -> V_121 ) {
F_88 ( V_20 -> V_121 ) ;
F_91 ( V_20 -> V_121 ) ;
}
V_20 -> V_121 = NULL ;
}
static void F_92 ( struct V_132 * V_70 , V_92 V_120 )
{
struct V_19 * V_20 = F_93 ( V_70 ) ;
T_5 V_11 ;
V_11 = V_20 -> V_133 [ V_120 % 128 ] ++ ;
F_94 ( V_20 -> V_70 , V_120 , V_11 ) ;
F_95 ( V_20 -> V_70 -> V_134 . V_135 ,
F_96 ( & V_20 -> V_70 -> V_39 ) , V_120 ,
V_11 ) ;
if ( V_120 >= V_136 && V_120 <= V_137 ) {
if ( V_20 -> V_56 != NULL ) {
F_32 ( V_20 ) ;
}
return ;
}
F_81 ( V_20 , V_120 ) ;
}
static T_6 F_97 ( struct V_138 * V_139 ,
struct V_140 * V_72 ,
int V_141 )
{
struct V_70 * V_39 = F_9 ( V_139 , struct V_70 , V_139 ) ;
struct V_49 * V_142 = F_98 ( V_39 ) ;
struct V_19 * V_20 = F_99 ( V_142 ) ;
T_1 V_1 = V_20 -> V_1 ;
bool V_143 ;
if ( V_72 == & V_144 . V_72 ) {
V_143 = ! F_4 ( V_1 , V_97 , NULL ) ;
} else if ( V_72 == & V_145 . V_72 ) {
V_143 = ! F_4 ( V_1 , V_99 , NULL ) ;
} else if ( V_72 == & V_146 . V_72 ) {
V_143 = ! F_4 ( V_1 , V_105 , NULL ) ;
} else if ( V_72 == & V_147 . V_72 ) {
V_143 =
! F_4 ( V_20 -> V_1 , V_101 , NULL ) ;
} else if ( V_72 == & V_148 . V_72 ) {
V_143 = ! F_4 ( V_20 -> V_1 , V_103 , NULL ) ;
} else if ( V_72 == & V_149 . V_72 ) {
V_143 = ! F_4 ( V_1 , V_91 , NULL ) ;
} else if ( V_72 == & V_150 . V_72 ||
V_72 == & V_151 . V_72 ) {
V_143 = ! F_4 ( V_1 , V_106 , NULL ) &&
! F_4 ( V_1 , V_108 , NULL ) ;
} else if ( V_72 == & V_152 . V_72 ) {
V_143 = ! F_4 ( V_1 , V_112 , NULL ) &&
! F_4 ( V_1 , V_113 , NULL ) &&
! F_4 ( V_1 , V_110 , NULL ) ;
} else {
V_143 = true ;
}
return V_143 ? V_72 -> V_153 : 0 ;
}
static int F_100 ( struct V_19 * V_20 )
{
int V_117 ;
V_20 -> V_49 = F_101 ( V_66 , - 1 ) ;
if ( ! V_20 -> V_49 )
return - V_51 ;
F_102 ( V_20 -> V_49 , V_20 ) ;
V_117 = F_103 ( V_20 -> V_49 ) ;
if ( V_117 )
goto V_154;
V_117 = F_104 ( & V_20 -> V_49 -> V_39 . V_139 ,
& V_155 ) ;
if ( V_117 )
goto V_156;
return 0 ;
V_156:
F_105 ( V_20 -> V_49 ) ;
V_154:
F_106 ( V_20 -> V_49 ) ;
return V_117 ;
}
static void F_107 ( struct V_19 * V_20 )
{
F_108 ( & V_20 -> V_49 -> V_39 . V_139 , & V_155 ) ;
F_109 ( V_20 -> V_49 ) ;
}
static int F_110 ( struct V_19 * V_20 )
{
struct V_4 V_157 = { V_158 , NULL } ;
union V_8 * V_159 = NULL ;
unsigned long long V_160 , V_161 ;
char * string = NULL ;
T_2 V_10 ;
V_10 = F_111 ( V_162 , 1 , & V_20 -> V_80 ) ;
if ( F_15 ( V_10 ) )
F_6 ( L_53 ) ;
if ( F_1 ( V_20 -> V_1 , L_54 , 0 , & V_157 ) ) {
F_37 ( L_55 ) ;
return - V_17 ;
}
V_10 =
F_14 ( V_20 -> V_1 , L_56 , NULL , & V_160 ) ;
if ( F_15 ( V_10 ) )
F_6 ( L_57 ) ;
else if ( V_160 )
F_112 ( L_58 ,
( V_79 ) V_160 ) ;
if ( F_3 ( V_20 -> V_1 , L_59 , V_163 ) )
F_37 ( L_60 , V_163 ) ;
if ( V_157 . V_12 ) {
V_159 = V_157 . V_12 ;
switch ( V_159 -> type ) {
case V_164 :
string = V_159 -> string . V_12 ;
break;
case V_165 :
string = V_159 -> V_157 . V_12 ;
break;
default:
string = L_61 ;
break;
}
}
V_20 -> V_45 = F_113 ( string , V_166 ) ;
if ( ! V_20 -> V_45 ) {
F_114 ( V_157 . V_12 ) ;
return - V_51 ;
}
if ( * string )
F_112 ( L_62 , string ) ;
V_10 =
F_14 ( V_20 -> V_1 , L_19 , NULL , & V_161 ) ;
if ( ! F_15 ( V_10 ) )
F_112 ( L_63 , ( int ) V_161 ) ;
if ( ! F_4 ( V_20 -> V_1 , V_96 , NULL ) )
V_20 -> V_94 = true ;
F_114 ( V_159 ) ;
return V_15 ;
}
static int T_7 F_115 ( struct V_19 * V_20 )
{
int V_117 = 0 ;
V_117 = F_116 ( V_20 -> V_70 ) ;
if ( V_117 )
return V_117 ;
if ( ! V_20 -> V_70 -> V_10 . V_167 ) {
F_37 ( L_64 ) ;
return - V_17 ;
}
V_117 = F_110 ( V_20 ) ;
if ( V_117 )
return V_117 ;
if ( V_168 >= 0 )
F_52 ( V_20 , ! ! V_168 ) ;
if ( V_169 >= 0 )
F_49 ( V_20 , ! ! V_169 ) ;
if ( V_170 >= 0 )
F_55 ( V_20 , ! ! V_170 ) ;
if ( V_171 >= 0 )
F_58 ( V_20 , ! ! V_171 ) ;
if ( ! F_4 ( V_20 -> V_1 , V_36 , NULL ) )
F_16 ( V_20 , 1 ) ;
V_20 -> V_90 = 0xFFF ;
V_20 -> V_107 = 0 ;
V_20 -> V_109 = 5 ;
if ( ! F_4 ( V_20 -> V_1 , V_106 , NULL ) &&
! F_4 ( V_20 -> V_1 , V_108 , NULL ) ) {
F_63 ( V_20 , V_20 -> V_107 ) ;
F_66 ( V_20 , V_20 -> V_109 ) ;
}
return V_117 ;
}
static void T_7 F_117 ( void )
{
const char * V_159 ;
V_159 = F_118 ( V_172 ) ;
if ( ! V_159 )
return;
if ( strncmp ( V_159 , L_65 , 6 ) == 0 ) {
V_169 = - 1 ;
}
}
static int T_7 F_119 ( struct V_132 * V_70 )
{
struct V_19 * V_20 ;
int V_117 ;
F_112 ( L_66 ,
V_78 ) ;
V_20 = F_120 ( sizeof( struct V_19 ) , V_166 ) ;
if ( ! V_20 )
return - V_51 ;
V_20 -> V_1 = V_70 -> V_1 ;
strcpy ( F_121 ( V_70 ) , V_173 ) ;
strcpy ( F_122 ( V_70 ) , V_174 ) ;
V_70 -> V_175 = V_20 ;
V_20 -> V_70 = V_70 ;
F_117 () ;
V_117 = F_115 ( V_20 ) ;
if ( V_117 )
goto V_176;
V_117 = F_100 ( V_20 ) ;
if ( V_117 )
goto V_176;
if ( ! F_123 () ) {
V_117 = F_34 ( V_20 ) ;
if ( V_117 )
goto V_177;
} else
F_85 ( L_67 ) ;
V_117 = F_83 ( V_20 ) ;
if ( V_117 )
goto V_178;
V_117 = F_26 ( V_20 ) ;
if ( V_117 )
goto V_179;
V_117 = F_78 ( V_20 ) ;
if ( V_117 )
goto V_180;
V_181 = true ;
return 0 ;
V_180:
F_20 ( V_20 ) ;
V_179:
F_90 ( V_20 ) ;
V_178:
F_40 ( V_20 ) ;
V_177:
F_107 ( V_20 ) ;
V_176:
F_114 ( V_20 -> V_45 ) ;
F_114 ( V_20 ) ;
return V_117 ;
}
static int F_124 ( struct V_132 * V_70 , int type )
{
struct V_19 * V_20 = F_93 ( V_70 ) ;
F_40 ( V_20 ) ;
F_75 ( V_20 ) ;
F_20 ( V_20 ) ;
F_90 ( V_20 ) ;
F_107 ( V_20 ) ;
F_114 ( V_20 -> V_45 ) ;
F_114 ( V_20 ) ;
return 0 ;
}
static int T_8 F_125 ( void )
{
int V_117 ;
V_117 = F_126 ( & V_182 ) ;
if ( V_117 < 0 )
return V_117 ;
V_117 = F_127 ( & V_183 ) ;
if ( V_117 < 0 )
goto V_184;
if ( ! V_181 ) {
V_117 = - V_17 ;
goto V_185;
}
return 0 ;
V_185:
F_128 ( & V_183 ) ;
V_184:
F_129 ( & V_182 ) ;
return V_117 ;
}
static void T_9 F_130 ( void )
{
F_128 ( & V_183 ) ;
F_129 ( & V_182 ) ;
}
