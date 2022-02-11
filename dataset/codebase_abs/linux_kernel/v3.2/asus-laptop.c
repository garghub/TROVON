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
static bool F_7 ( struct V_19 * V_20 )
{
return ! strcmp ( V_20 -> V_21 , V_22 ) &&
! F_4 ( V_20 -> V_1 , V_23 , NULL ) &&
! F_4 ( V_20 -> V_1 , V_24 , NULL ) &&
! F_4 ( V_20 -> V_1 , V_25 , NULL ) ;
}
static int F_8 ( struct V_19 * V_20 , int V_26 , bool V_27 )
{
char * V_2 = V_27 ? V_23 : V_24 ;
return F_3 ( V_20 -> V_1 , V_2 , V_26 ) ;
}
static int F_9 ( struct V_19 * V_20 , int V_28 , char * V_2 )
{
int V_29 , V_30 ;
unsigned long long V_3 ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
F_10 ( V_20 -> V_1 , V_2 , NULL , & V_3 ) ;
V_30 = abs ( V_28 - ( short ) V_3 ) ;
if ( V_30 < 128 && ! ( V_3 & ~ 0xffff ) )
break;
}
return F_11 ( ( short ) V_3 , - V_32 , V_32 ) ;
}
static void F_12 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_37 -> V_38 . V_36 ;
struct V_19 * V_20 = F_13 ( V_36 ) ;
if ( ! V_20 -> V_39 ) {
V_20 -> V_39 = true ;
F_14 ( V_34 -> V_37 , V_40 , 0 ) ;
F_14 ( V_34 -> V_37 , V_41 , 0 ) ;
F_14 ( V_34 -> V_37 , V_42 , 0 ) ;
F_15 ( V_34 -> V_37 ) ;
return;
}
V_20 -> V_43 = F_9 ( V_20 , V_20 -> V_43 , V_44 ) ;
V_20 -> V_45 = F_9 ( V_20 , V_20 -> V_45 , V_46 ) ;
V_20 -> V_47 = F_9 ( V_20 , V_20 -> V_47 , V_48 ) ;
F_14 ( V_34 -> V_37 , V_40 , - V_20 -> V_43 ) ;
F_14 ( V_34 -> V_37 , V_41 , - V_20 -> V_45 ) ;
F_14 ( V_34 -> V_37 , V_42 , V_20 -> V_47 ) ;
F_15 ( V_34 -> V_37 ) ;
}
static void F_16 ( struct V_19 * V_20 )
{
if ( V_20 -> F_12 ) {
F_17 ( V_20 -> F_12 ) ;
F_18 ( V_20 -> F_12 ) ;
}
V_20 -> F_12 = NULL ;
}
static int F_19 ( struct V_19 * V_20 )
{
int V_49 ;
struct V_33 * V_34 ;
if ( ! V_20 -> V_50 )
return - V_17 ;
if ( F_4 ( V_20 -> V_1 , V_44 , NULL ) ||
F_4 ( V_20 -> V_1 , V_46 , NULL ) ||
F_4 ( V_20 -> V_1 , V_48 , NULL ) )
return - V_17 ;
V_34 = F_20 () ;
if ( ! V_34 )
return - V_51 ;
V_34 -> V_52 = F_12 ;
V_34 -> V_53 = 125 ;
V_34 -> V_54 = 50 ;
V_34 -> V_55 = 2000 ;
V_34 -> V_37 -> V_21 = V_56 ;
V_34 -> V_37 -> V_57 = V_58 L_2 ;
V_34 -> V_37 -> V_38 . V_36 = & V_20 -> V_59 -> V_38 ;
V_34 -> V_37 -> V_60 . V_61 = V_62 ;
F_21 ( V_63 , V_34 -> V_37 -> V_64 ) ;
F_22 ( V_34 -> V_37 , V_40 ,
- V_32 , V_32 , 0 , 0 ) ;
F_22 ( V_34 -> V_37 , V_41 ,
- V_32 , V_32 , 0 , 0 ) ;
F_22 ( V_34 -> V_37 , V_42 ,
- V_32 , V_32 , 0 , 0 ) ;
V_49 = F_23 ( V_34 ) ;
if ( V_49 )
goto exit;
V_20 -> F_12 = V_34 ;
return 0 ;
exit:
F_18 ( V_34 ) ;
return V_49 ;
}
static int F_24 ( struct V_19 * V_20 , const char * V_2 ,
int V_14 )
{
if ( ! strcmp ( V_2 , V_65 ) )
V_14 = ! V_14 ;
else if ( ! strcmp ( V_2 , V_66 ) )
V_14 = ! V_14 + 1 ;
else
V_14 = ! ! V_14 ;
return F_3 ( V_20 -> V_1 , V_2 , V_14 ) ;
}
static void F_25 ( struct V_67 * V_68 ,
enum V_69 V_14 )
{
struct V_70 * V_71 = F_26 ( V_68 , struct V_70 , V_71 ) ;
struct V_19 * V_20 = V_71 -> V_20 ;
V_71 -> V_72 = ! ! V_14 ;
F_27 ( V_20 -> V_73 , & V_71 -> V_74 ) ;
}
static void F_28 ( struct V_75 * V_74 )
{
struct V_70 * V_71 = F_26 ( V_74 , struct V_70 , V_74 ) ;
struct V_19 * V_20 = V_71 -> V_20 ;
F_24 ( V_20 , V_71 -> V_2 , V_71 -> V_72 ) ;
}
static enum V_69 F_29 ( struct V_67 * V_68 )
{
return V_68 -> V_76 ;
}
static int F_30 ( struct V_19 * V_20 )
{
unsigned long long V_77 ;
struct V_6 V_7 ;
union V_8 V_9 ;
T_2 V_78 ;
V_7 . V_11 = 1 ;
V_7 . V_12 = & V_9 ;
V_9 . type = V_13 ;
V_9 . integer . V_14 = 2 ;
V_78 = F_10 ( V_20 -> V_1 , V_79 ,
& V_7 , & V_77 ) ;
if ( F_31 ( V_78 ) ) {
F_6 ( L_3 ) ;
return - V_17 ;
}
return V_77 ;
}
static int F_32 ( struct V_19 * V_20 , int V_77 )
{
if ( V_77 > 0 )
V_77 = ( 1 << 7 ) | ( V_77 & 0x7F ) ;
else
V_77 = 0 ;
if ( F_3 ( V_20 -> V_1 , V_80 , V_77 ) ) {
F_6 ( L_4 ) ;
return - V_81 ;
}
return 0 ;
}
static void F_33 ( struct V_67 * V_68 ,
enum V_69 V_14 )
{
struct V_70 * V_71 = F_26 ( V_68 , struct V_70 , V_71 ) ;
struct V_19 * V_20 = V_71 -> V_20 ;
V_71 -> V_72 = V_14 ;
F_27 ( V_20 -> V_73 , & V_71 -> V_74 ) ;
}
static void F_34 ( struct V_75 * V_74 )
{
struct V_70 * V_71 = F_26 ( V_74 , struct V_70 , V_74 ) ;
struct V_19 * V_20 = V_71 -> V_20 ;
F_32 ( V_20 , V_71 -> V_72 ) ;
}
static enum V_69 F_35 ( struct V_67 * V_68 )
{
struct V_70 * V_71 = F_26 ( V_68 , struct V_70 , V_71 ) ;
struct V_19 * V_20 = V_71 -> V_20 ;
return F_30 ( V_20 ) ;
}
static void F_36 ( struct V_19 * V_20 )
{
if ( ! F_37 ( V_20 -> V_82 . V_71 . V_38 ) )
F_38 ( & V_20 -> V_82 . V_71 ) ;
if ( ! F_37 ( V_20 -> V_83 . V_71 . V_38 ) )
F_38 ( & V_20 -> V_83 . V_71 ) ;
if ( ! F_37 ( V_20 -> V_84 . V_71 . V_38 ) )
F_38 ( & V_20 -> V_84 . V_71 ) ;
if ( ! F_37 ( V_20 -> V_85 . V_71 . V_38 ) )
F_38 ( & V_20 -> V_85 . V_71 ) ;
if ( ! F_37 ( V_20 -> V_86 . V_71 . V_38 ) )
F_38 ( & V_20 -> V_86 . V_71 ) ;
if ( ! F_37 ( V_20 -> V_87 . V_71 . V_38 ) )
F_38 ( & V_20 -> V_87 . V_71 ) ;
if ( V_20 -> V_73 ) {
F_39 ( V_20 -> V_73 ) ;
V_20 -> V_73 = NULL ;
}
}
static int F_40 ( struct V_19 * V_20 ,
struct V_70 * V_71 ,
const char * V_21 , const char * V_2 )
{
struct V_67 * V_68 = & V_71 -> V_71 ;
if ( ! V_2 || F_4 ( V_20 -> V_1 , V_2 , NULL ) )
return 0 ;
V_71 -> V_20 = V_20 ;
V_71 -> V_2 = V_2 ;
F_41 ( & V_71 -> V_74 , F_28 ) ;
V_68 -> V_21 = V_21 ;
V_68 -> V_88 = F_25 ;
V_68 -> V_89 = F_29 ;
V_68 -> V_90 = 1 ;
return F_42 ( & V_20 -> V_59 -> V_38 , V_68 ) ;
}
static int F_43 ( struct V_19 * V_20 )
{
int V_91 ;
if ( V_20 -> V_50 )
return 0 ;
V_20 -> V_73 = F_44 ( L_5 ) ;
if ( ! V_20 -> V_73 )
return - V_51 ;
V_91 = F_40 ( V_20 , & V_20 -> V_82 , L_6 , V_65 ) ;
if ( V_91 )
goto error;
V_91 = F_40 ( V_20 , & V_20 -> V_83 , L_7 , V_92 ) ;
if ( V_91 )
goto error;
V_91 = F_40 ( V_20 , & V_20 -> V_85 , L_8 , V_93 ) ;
if ( V_91 )
goto error;
V_91 = F_40 ( V_20 , & V_20 -> V_84 , L_9 , V_94 ) ;
if ( V_91 )
goto error;
V_91 = F_40 ( V_20 , & V_20 -> V_86 , L_10 , V_66 ) ;
if ( V_91 )
goto error;
if ( ! F_4 ( V_20 -> V_1 , V_80 , NULL ) &&
! F_4 ( V_20 -> V_1 , V_79 , NULL ) ) {
struct V_70 * V_71 = & V_20 -> V_87 ;
struct V_67 * V_95 = & V_71 -> V_71 ;
V_71 -> V_20 = V_20 ;
F_41 ( & V_71 -> V_74 , F_34 ) ;
V_95 -> V_21 = L_11 ;
V_95 -> V_88 = F_33 ;
V_95 -> V_89 = F_35 ;
V_95 -> V_90 = 3 ;
V_91 = F_42 ( & V_20 -> V_59 -> V_38 , V_95 ) ;
}
error:
if ( V_91 )
F_36 ( V_20 ) ;
return V_91 ;
}
static int F_45 ( struct V_96 * V_97 )
{
struct V_19 * V_20 = F_46 ( V_97 ) ;
unsigned long long V_14 ;
T_2 V_78 = V_15 ;
V_78 = F_10 ( V_20 -> V_1 , V_98 ,
NULL , & V_14 ) ;
if ( F_31 ( V_78 ) )
F_6 ( L_12 ) ;
return V_14 ;
}
static int F_47 ( struct V_96 * V_97 , int V_14 )
{
struct V_19 * V_20 = F_46 ( V_97 ) ;
if ( F_3 ( V_20 -> V_1 , V_99 , V_14 ) ) {
F_6 ( L_13 ) ;
return - V_100 ;
}
return 0 ;
}
static int F_48 ( struct V_96 * V_97 )
{
int V_14 = V_97 -> V_101 . V_76 ;
return F_47 ( V_97 , V_14 ) ;
}
static int F_49 ( struct V_19 * V_20 )
{
struct V_96 * V_97 = V_20 -> V_96 ;
int V_102 = V_97 -> V_101 . V_76 ;
F_50 ( V_97 , V_103 ) ;
return V_102 ;
}
static int F_51 ( struct V_19 * V_20 )
{
struct V_96 * V_97 ;
struct V_104 V_101 ;
if ( F_4 ( V_20 -> V_1 , V_98 , NULL ) ||
F_4 ( V_20 -> V_1 , V_99 , NULL ) )
return 0 ;
memset ( & V_101 , 0 , sizeof( struct V_104 ) ) ;
V_101 . V_90 = 15 ;
V_101 . type = V_105 ;
V_97 = F_52 ( V_106 ,
& V_20 -> V_59 -> V_38 , V_20 ,
& V_107 , & V_101 ) ;
if ( F_53 ( V_97 ) ) {
F_54 ( L_14 ) ;
V_20 -> V_96 = NULL ;
return F_55 ( V_97 ) ;
}
V_20 -> V_96 = V_97 ;
V_97 -> V_101 . V_76 = F_45 ( V_97 ) ;
V_97 -> V_101 . V_108 = V_109 ;
F_56 ( V_97 ) ;
return 0 ;
}
static void F_57 ( struct V_19 * V_20 )
{
if ( V_20 -> V_96 )
F_58 ( V_20 -> V_96 ) ;
V_20 -> V_96 = NULL ;
}
static T_3 F_59 ( struct V_35 * V_38 ,
struct V_110 * V_111 , char * V_112 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
int V_113 = 0 ;
unsigned long long V_114 ;
char V_115 [ 16 ] ;
T_2 V_78 = V_15 ;
V_113 += sprintf ( V_112 , V_116 L_15 V_117 L_16 ) ;
V_113 += sprintf ( V_112 + V_113 , L_17 , V_20 -> V_21 ) ;
V_78 = F_10 ( V_20 -> V_1 , L_18 , NULL , & V_114 ) ;
if ( ! F_31 ( V_78 ) )
V_113 += sprintf ( V_112 + V_113 , L_19 ,
( V_118 ) V_114 ) ;
V_78 = F_10 ( V_20 -> V_1 , L_20 , NULL , & V_114 ) ;
if ( ! F_31 ( V_78 ) )
V_113 += sprintf ( V_112 + V_113 , L_21 ,
( V_118 ) V_114 ) ;
V_78 = F_10 ( V_20 -> V_1 , L_22 , NULL , & V_114 ) ;
if ( ! F_31 ( V_78 ) )
V_113 += sprintf ( V_112 + V_113 , L_23 ,
( V_118 ) V_114 ) ;
if ( V_20 -> V_119 ) {
snprintf ( V_115 , 16 , L_24 , V_20 -> V_119 -> V_120 ) ;
V_113 += sprintf ( V_112 + V_113 , L_25 , V_115 ) ;
snprintf ( V_115 , 16 , L_24 , V_20 -> V_119 -> V_121 ) ;
V_113 += sprintf ( V_112 + V_113 , L_26 , V_115 ) ;
snprintf ( V_115 , 16 , L_24 , V_20 -> V_119 -> V_122 ) ;
V_113 += sprintf ( V_112 + V_113 , L_27 , V_115 ) ;
snprintf ( V_115 , 7 , L_28 , V_20 -> V_119 -> V_123 ) ;
V_113 += sprintf ( V_112 + V_113 , L_29 , V_115 ) ;
snprintf ( V_115 , 9 , L_28 , V_20 -> V_119 -> V_124 ) ;
V_113 += sprintf ( V_112 + V_113 , L_30 , V_115 ) ;
snprintf ( V_115 , 16 , L_31 , V_20 -> V_119 -> V_125 ) ;
V_113 += sprintf ( V_112 + V_113 , L_32 , V_115 ) ;
snprintf ( V_115 , 5 , L_28 , V_20 -> V_119 -> V_126 ) ;
V_113 += sprintf ( V_112 + V_113 , L_33 , V_115 ) ;
snprintf ( V_115 , 16 , L_31 , V_20 -> V_119 -> V_127 ) ;
V_113 += sprintf ( V_112 + V_113 , L_34 , V_115 ) ;
}
return V_113 ;
}
static int F_60 ( const char * V_115 , unsigned long V_11 , int * V_3 )
{
if ( ! V_11 )
return 0 ;
if ( V_11 > 31 )
return - V_81 ;
if ( sscanf ( V_115 , L_35 , V_3 ) != 1 )
return - V_81 ;
return V_11 ;
}
static T_3 F_61 ( struct V_19 * V_20 ,
const char * V_115 , T_4 V_11 ,
const char * V_2 )
{
int V_78 , V_14 ;
int V_128 = 0 ;
V_78 = F_60 ( V_115 , V_11 , & V_14 ) ;
if ( V_78 > 0 )
V_128 = V_14 ? 1 : 0 ;
if ( F_3 ( V_20 -> V_1 , V_2 , V_14 ) )
return - V_17 ;
return V_78 ;
}
static T_3 F_62 ( struct V_35 * V_38 ,
struct V_110 * V_111 , char * V_115 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return sprintf ( V_115 , L_36 , V_20 -> V_129 ) ;
}
static T_3 F_63 ( struct V_35 * V_38 , struct V_110 * V_111 ,
const char * V_115 , T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
int V_78 , V_14 ;
V_78 = F_60 ( V_115 , V_11 , & V_14 ) ;
if ( V_78 > 0 ) {
if ( F_3 ( V_20 -> V_1 , V_130 , V_14 ) ) {
F_6 ( L_37 ) ;
return - V_17 ;
}
V_20 -> V_129 = ( V_131 ) V_14 ;
}
return V_78 ;
}
static int F_64 ( struct V_19 * V_20 , int V_132 )
{
unsigned long long V_10 ;
T_2 V_78 = V_15 ;
if ( ! V_20 -> V_133 )
return ( V_20 -> V_134 & V_132 ) ? 1 : 0 ;
V_78 = F_10 ( V_20 -> V_1 , V_135 ,
NULL , & V_10 ) ;
if ( F_31 ( V_78 ) ) {
F_6 ( L_38 ) ;
return - V_81 ;
}
return ! ! ( V_10 & V_132 ) ;
}
static int F_65 ( struct V_19 * V_20 , int V_10 )
{
if ( F_3 ( V_20 -> V_1 , V_136 , ! ! V_10 ) ) {
F_6 ( L_39 , V_10 ) ;
return - V_100 ;
}
return 0 ;
}
static T_3 F_66 ( struct V_35 * V_38 ,
struct V_110 * V_111 , char * V_115 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return sprintf ( V_115 , L_40 , F_64 ( V_20 , V_137 ) ) ;
}
static T_3 F_67 ( struct V_35 * V_38 , struct V_110 * V_111 ,
const char * V_115 , T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return F_61 ( V_20 , V_115 , V_11 , V_136 ) ;
}
static int F_68 ( struct V_19 * V_20 , int V_10 )
{
if ( F_3 ( V_20 -> V_1 , V_138 , ! ! V_10 ) ) {
F_6 ( L_41 , V_10 ) ;
return - V_100 ;
}
return 0 ;
}
static T_3 F_69 ( struct V_35 * V_38 ,
struct V_110 * V_111 , char * V_115 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return sprintf ( V_115 , L_40 , F_64 ( V_20 , V_139 ) ) ;
}
static T_3 F_70 ( struct V_35 * V_38 ,
struct V_110 * V_111 , const char * V_115 ,
T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return F_61 ( V_20 , V_115 , V_11 , V_138 ) ;
}
static int F_71 ( struct V_19 * V_20 , int V_10 )
{
if ( F_3 ( V_20 -> V_1 , V_140 , ! ! V_10 ) ) {
F_6 ( L_42 , V_10 ) ;
return - V_100 ;
}
return 0 ;
}
static T_3 F_72 ( struct V_35 * V_38 ,
struct V_110 * V_111 , char * V_115 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return sprintf ( V_115 , L_40 , F_64 ( V_20 , V_141 ) ) ;
}
static T_3 F_73 ( struct V_35 * V_38 ,
struct V_110 * V_111 , const char * V_115 ,
T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return F_61 ( V_20 , V_115 , V_11 , V_140 ) ;
}
static int F_74 ( struct V_19 * V_20 , int V_10 )
{
if ( F_3 ( V_20 -> V_1 , V_142 , ! ! V_10 ) ) {
F_6 ( L_43 , V_10 ) ;
return - V_100 ;
}
return 0 ;
}
static T_3 F_75 ( struct V_35 * V_38 ,
struct V_110 * V_111 , char * V_115 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return sprintf ( V_115 , L_40 , F_64 ( V_20 , V_143 ) ) ;
}
static T_3 F_76 ( struct V_35 * V_38 ,
struct V_110 * V_111 , const char * V_115 ,
T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return F_61 ( V_20 , V_115 , V_11 , V_142 ) ;
}
static void F_77 ( struct V_19 * V_20 , int V_14 )
{
if ( F_3 ( V_20 -> V_1 , V_144 , V_14 ) )
F_6 ( L_44 ) ;
return;
}
static T_3 F_78 ( struct V_35 * V_38 , struct V_110 * V_111 ,
const char * V_115 , T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
int V_78 , V_14 ;
V_78 = F_60 ( V_115 , V_11 , & V_14 ) ;
if ( V_78 > 0 )
F_77 ( V_20 , V_14 ) ;
return V_78 ;
}
static void F_79 ( struct V_19 * V_20 , int V_14 )
{
int V_16 ;
if ( V_20 -> V_50 ) {
V_16 = F_8 ( V_20 , V_145 , V_14 ) ;
if ( ! V_16 )
V_16 = F_8 ( V_20 , V_146 , V_14 ) ;
} else {
V_16 = F_3 ( V_20 -> V_1 , V_147 , V_14 ) ;
}
if ( V_16 )
F_80 ( L_45 ) ;
V_20 -> V_148 = V_14 ;
}
static T_3 F_81 ( struct V_35 * V_38 ,
struct V_110 * V_111 , char * V_115 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return sprintf ( V_115 , L_40 , V_20 -> V_148 ) ;
}
static T_3 F_82 ( struct V_35 * V_38 , struct V_110 * V_111 ,
const char * V_115 , T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
int V_78 , V_14 ;
V_78 = F_60 ( V_115 , V_11 , & V_14 ) ;
if ( V_78 > 0 )
F_79 ( V_20 , V_14 ? 1 : 0 ) ;
return V_78 ;
}
static void F_83 ( struct V_19 * V_20 , int V_14 )
{
if ( F_3 ( V_20 -> V_1 , V_149 , V_14 ) )
F_6 ( L_46 ) ;
V_20 -> V_150 = V_14 ;
}
static T_3 F_84 ( struct V_35 * V_38 ,
struct V_110 * V_111 , char * V_115 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return sprintf ( V_115 , L_40 , V_20 -> V_150 ) ;
}
static T_3 F_85 ( struct V_35 * V_38 , struct V_110 * V_111 ,
const char * V_115 , T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
int V_78 , V_14 ;
V_78 = F_60 ( V_115 , V_11 , & V_14 ) ;
if ( V_78 > 0 ) {
V_14 = ( 0 < V_14 ) ? ( ( 15 < V_14 ) ? 15 : V_14 ) : 0 ;
F_83 ( V_20 , V_14 ) ;
}
return V_78 ;
}
static int F_86 ( struct V_19 * V_20 , int V_151 , int * V_152 )
{
struct V_4 V_153 = { V_154 , NULL } ;
int V_49 = F_1 ( V_20 -> V_1 , V_25 , V_151 ,
& V_153 ) ;
if ( ! V_49 ) {
union V_8 * V_155 = V_153 . V_12 ;
if ( V_155 && V_155 -> type == V_13 )
* V_152 = V_155 -> integer . V_14 ;
else
V_49 = - V_100 ;
}
return V_49 ;
}
static T_3 F_87 ( struct V_35 * V_38 ,
struct V_110 * V_111 , char * V_115 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
int V_49 , V_156 , V_157 ;
V_49 = F_86 ( V_20 , V_158 , & V_156 ) ;
if ( ! V_49 )
V_49 = F_86 ( V_20 , V_159 , & V_157 ) ;
if ( ! V_49 )
return sprintf ( V_115 , L_40 , 10 * V_156 + V_157 ) ;
return V_49 ;
}
static int F_88 ( struct V_19 * V_20 )
{
unsigned long long V_10 ;
T_2 V_78 = V_15 ;
V_78 = F_10 ( V_20 -> V_1 , V_160 ,
NULL , & V_10 ) ;
if ( F_31 ( V_78 ) ) {
F_6 ( L_47 ) ;
return - V_17 ;
}
return ! ! V_10 ;
}
static int F_89 ( struct V_19 * V_20 , int V_10 )
{
const char * V_161 = V_10 ? V_162 : V_163 ;
if ( F_3 ( V_20 -> V_1 , V_161 , 0x02 ) )
return - V_17 ;
return 0 ;
}
static T_3 F_90 ( struct V_35 * V_38 ,
struct V_110 * V_111 , char * V_115 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return sprintf ( V_115 , L_40 , F_88 ( V_20 ) ) ;
}
static T_3 F_91 ( struct V_35 * V_38 , struct V_110 * V_111 ,
const char * V_115 , T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
int V_78 , V_14 ;
int V_16 ;
V_78 = F_60 ( V_115 , V_11 , & V_14 ) ;
if ( V_78 <= 0 )
return - V_81 ;
V_16 = F_89 ( V_20 , ! ! V_14 ) ;
if ( V_16 )
return V_16 ;
F_92 ( V_20 -> V_164 , ! V_14 ) ;
return V_78 ;
}
static int F_93 ( void * V_165 , bool V_166 )
{
struct V_19 * V_20 = V_165 ;
return F_89 ( V_20 , ! V_166 ) ;
}
static void F_94 ( struct V_19 * V_20 )
{
if ( V_20 -> V_164 ) {
F_95 ( V_20 -> V_164 ) ;
F_96 ( V_20 -> V_164 ) ;
V_20 -> V_164 = NULL ;
}
}
static int F_97 ( struct V_19 * V_20 )
{
int V_152 ;
if ( F_4 ( V_20 -> V_1 , V_162 , NULL ) ||
F_4 ( V_20 -> V_1 , V_163 , NULL ) ||
F_4 ( V_20 -> V_1 , V_160 , NULL ) )
return 0 ;
V_20 -> V_164 = F_98 ( L_48 , & V_20 -> V_59 -> V_38 ,
V_167 ,
& V_168 , V_20 ) ;
if ( ! V_20 -> V_164 )
return - V_81 ;
V_152 = F_99 ( V_20 -> V_164 ) ;
if ( V_152 ) {
F_96 ( V_20 -> V_164 ) ;
V_20 -> V_164 = NULL ;
}
return V_152 ;
}
static int F_100 ( void * V_165 , bool V_166 )
{
struct V_169 * V_170 = V_165 ;
int V_16 = F_8 ( V_170 -> V_20 , V_170 -> V_171 , ! V_166 ) ;
F_6 ( L_49 , V_170 -> V_171 , ! V_166 , V_16 ) ;
return V_16 ;
}
static void F_101 ( struct V_169 * V_170 )
{
F_6 ( L_50 , V_170 -> V_171 ) ;
if ( V_170 -> V_172 ) {
F_95 ( V_170 -> V_172 ) ;
F_96 ( V_170 -> V_172 ) ;
V_170 -> V_172 = NULL ;
}
}
static void F_102 ( struct V_19 * V_20 )
{
F_101 ( & V_20 -> V_173 ) ;
F_101 ( & V_20 -> V_174 ) ;
F_101 ( & V_20 -> V_175 ) ;
}
static int F_103 ( struct V_19 * V_20 , struct V_169 * V_170 ,
const char * V_21 , int V_176 , int V_177 )
{
int V_152 ;
F_6 ( L_51 , V_21 , V_176 , V_177 ) ;
V_170 -> V_171 = V_176 ;
V_170 -> V_20 = V_20 ;
V_170 -> V_172 = F_98 ( V_21 , & V_20 -> V_59 -> V_38 ,
V_177 , & V_178 , V_170 ) ;
if ( ! V_170 -> V_172 )
return - V_81 ;
V_152 = F_99 ( V_170 -> V_172 ) ;
if ( V_152 ) {
F_96 ( V_170 -> V_172 ) ;
V_170 -> V_172 = NULL ;
}
return V_152 ;
}
static int F_104 ( struct V_19 * V_20 )
{
int V_16 = 0 ;
if( ! V_20 -> V_50 )
return - V_17 ;
V_16 = F_103 ( V_20 , & V_20 -> V_175 , L_52 , V_179 , V_180 ) ;
if( V_16 )
return V_16 ;
V_16 = F_103 ( V_20 , & V_20 -> V_174 , L_53 , V_181 , V_182 ) ;
if( V_16 )
goto V_183;
V_16 = F_103 ( V_20 , & V_20 -> V_173 , L_54 , V_184 , V_185 ) ;
if( V_16 )
goto V_186;
F_6 ( L_55 ) ;
return 0 ;
V_186:
F_101 ( & V_20 -> V_174 ) ;
V_183:
F_101 ( & V_20 -> V_175 ) ;
return V_16 ;
}
static void F_105 ( struct V_19 * V_20 , int V_187 )
{
if ( V_20 -> V_188 )
F_106 ( V_20 -> V_188 , V_187 , 1 , true ) ;
}
static int F_107 ( struct V_19 * V_20 )
{
struct V_189 * V_37 ;
int error ;
V_37 = F_108 () ;
if ( ! V_37 ) {
F_109 ( L_56 ) ;
return - V_51 ;
}
V_37 -> V_21 = L_57 ;
V_37 -> V_57 = V_106 L_2 ;
V_37 -> V_60 . V_61 = V_62 ;
V_37 -> V_38 . V_36 = & V_20 -> V_59 -> V_38 ;
error = F_110 ( V_37 , V_190 , NULL ) ;
if ( error ) {
F_54 ( L_58 ) ;
goto V_191;
}
error = F_111 ( V_37 ) ;
if ( error ) {
F_109 ( L_59 ) ;
goto V_192;
}
V_20 -> V_188 = V_37 ;
return 0 ;
V_192:
F_112 ( V_37 ) ;
V_191:
F_113 ( V_37 ) ;
return error ;
}
static void F_114 ( struct V_19 * V_20 )
{
if ( V_20 -> V_188 ) {
F_112 ( V_20 -> V_188 ) ;
F_115 ( V_20 -> V_188 ) ;
}
V_20 -> V_188 = NULL ;
}
static void F_116 ( struct V_193 * V_35 , V_131 V_187 )
{
struct V_19 * V_20 = F_117 ( V_35 ) ;
T_5 V_11 ;
V_11 = V_20 -> V_194 [ V_187 % 128 ] ++ ;
F_118 ( V_20 -> V_35 , V_187 , V_11 ) ;
F_119 ( V_20 -> V_35 -> V_195 . V_196 ,
F_120 ( & V_20 -> V_35 -> V_38 ) , V_187 ,
V_11 ) ;
if ( V_187 >= V_197 && V_187 <= V_198 ) {
if ( V_20 -> V_96 != NULL ) {
F_49 ( V_20 ) ;
}
return ;
}
if ( V_20 -> F_12 && V_187 == 0xEA ) {
F_121 ( & V_20 -> F_12 -> V_37 -> V_38 . V_199 ,
V_200 ) ;
return ;
}
F_105 ( V_20 , V_187 ) ;
}
static T_6 F_122 ( struct V_201 * V_199 ,
struct V_202 * V_111 ,
int V_203 )
{
struct V_35 * V_38 = F_26 ( V_199 , struct V_35 , V_199 ) ;
struct V_59 * V_204 = F_123 ( V_38 ) ;
struct V_19 * V_20 = F_124 ( V_204 ) ;
T_1 V_1 = V_20 -> V_1 ;
bool V_205 ;
if ( V_20 -> V_50 ) {
if ( V_111 == & V_206 . V_111 )
V_205 = true ;
else if ( V_111 == & V_207 . V_111 )
V_205 = false ;
else
goto V_208;
return V_205 ;
}
V_208:
if ( V_111 == & V_209 . V_111 ) {
V_205 = ! F_4 ( V_1 , V_136 , NULL ) ;
} else if ( V_111 == & V_210 . V_111 ) {
V_205 = ! F_4 ( V_1 , V_138 , NULL ) ;
} else if ( V_111 == & V_211 . V_111 ) {
V_205 = ! F_4 ( V_1 , V_144 , NULL ) ;
} else if ( V_111 == & V_212 . V_111 ) {
V_205 =
! F_4 ( V_20 -> V_1 , V_140 , NULL ) ;
} else if ( V_111 == & V_213 . V_111 ) {
V_205 = ! F_4 ( V_20 -> V_1 , V_142 , NULL ) ;
} else if ( V_111 == & V_214 . V_111 ) {
V_205 = ! F_4 ( V_1 , V_130 , NULL ) ;
} else if ( V_111 == & V_206 . V_111 ||
V_111 == & V_207 . V_111 ) {
V_205 = ! F_4 ( V_1 , V_147 , NULL ) &&
! F_4 ( V_1 , V_149 , NULL ) ;
} else if ( V_111 == & V_215 . V_111 ) {
V_205 = V_20 -> V_50 ;
} else if ( V_111 == & V_216 . V_111 ) {
V_205 = ! F_4 ( V_1 , V_162 , NULL ) &&
! F_4 ( V_1 , V_163 , NULL ) &&
! F_4 ( V_1 , V_160 , NULL ) ;
} else {
V_205 = true ;
}
return V_205 ? V_111 -> V_217 : 0 ;
}
static int F_125 ( struct V_19 * V_20 )
{
int V_152 ;
V_20 -> V_59 = F_126 ( V_106 , - 1 ) ;
if ( ! V_20 -> V_59 )
return - V_51 ;
F_127 ( V_20 -> V_59 , V_20 ) ;
V_152 = F_128 ( V_20 -> V_59 ) ;
if ( V_152 )
goto V_218;
V_152 = F_129 ( & V_20 -> V_59 -> V_38 . V_199 ,
& V_219 ) ;
if ( V_152 )
goto V_220;
return 0 ;
V_220:
F_130 ( V_20 -> V_59 ) ;
V_218:
F_131 ( V_20 -> V_59 ) ;
return V_152 ;
}
static void F_132 ( struct V_19 * V_20 )
{
F_133 ( & V_20 -> V_59 -> V_38 . V_199 , & V_219 ) ;
F_134 ( V_20 -> V_59 ) ;
}
static int F_135 ( struct V_19 * V_20 )
{
struct V_4 V_153 = { V_154 , NULL } ;
union V_8 * V_221 = NULL ;
unsigned long long V_222 , V_223 ;
char * string = NULL ;
T_2 V_10 ;
V_10 = F_136 ( V_224 , 1 , & V_20 -> V_119 ) ;
if ( F_31 ( V_10 ) )
F_6 ( L_60 ) ;
if ( F_1 ( V_20 -> V_1 , L_61 , 0 , & V_153 ) ) {
F_54 ( L_62 ) ;
return - V_17 ;
}
V_10 =
F_10 ( V_20 -> V_1 , L_63 , NULL , & V_222 ) ;
if ( F_31 ( V_10 ) )
F_6 ( L_64 ) ;
else if ( V_222 )
F_137 ( L_65 ,
( V_118 ) V_222 ) ;
if ( F_3 ( V_20 -> V_1 , L_66 , V_225 ) )
F_54 ( L_67 , V_225 ) ;
if ( V_153 . V_12 ) {
V_221 = V_153 . V_12 ;
switch ( V_221 -> type ) {
case V_226 :
string = V_221 -> string . V_12 ;
break;
case V_227 :
string = V_221 -> V_153 . V_12 ;
break;
default:
string = L_68 ;
break;
}
}
V_20 -> V_21 = F_138 ( string , V_228 ) ;
if ( ! V_20 -> V_21 ) {
F_139 ( V_153 . V_12 ) ;
return - V_51 ;
}
if ( * string )
F_137 ( L_69 , string ) ;
V_10 =
F_10 ( V_20 -> V_1 , L_20 , NULL , & V_223 ) ;
if ( ! F_31 ( V_10 ) )
F_137 ( L_70 , ( int ) V_223 ) ;
if ( ! F_4 ( V_20 -> V_1 , V_135 , NULL ) )
V_20 -> V_133 = true ;
F_139 ( V_221 ) ;
return V_15 ;
}
static int T_7 F_140 ( struct V_19 * V_20 )
{
int V_152 = 0 ;
V_152 = F_141 ( V_20 -> V_35 ) ;
if ( V_152 )
return V_152 ;
if ( ! V_20 -> V_35 -> V_10 . V_229 ) {
F_54 ( L_71 ) ;
return - V_17 ;
}
V_152 = F_135 ( V_20 ) ;
if ( V_152 )
return V_152 ;
if ( V_230 >= 0 )
F_68 ( V_20 , ! ! V_230 ) ;
if ( V_231 >= 0 )
F_65 ( V_20 , ! ! V_231 ) ;
if ( V_232 >= 0 )
F_71 ( V_20 , ! ! V_232 ) ;
if ( V_233 >= 0 )
F_74 ( V_20 , ! ! V_233 ) ;
if ( ! F_4 ( V_20 -> V_1 , V_80 , NULL ) )
F_32 ( V_20 , 1 ) ;
V_20 -> V_129 = 0xFFF ;
V_20 -> V_148 = ! ! V_234 ;
V_20 -> V_150 = 5 ;
if ( V_20 -> V_50 ) {
F_79 ( V_20 , V_20 -> V_148 ) ;
} else if ( ! F_4 ( V_20 -> V_1 , V_147 , NULL ) &&
! F_4 ( V_20 -> V_1 , V_149 , NULL ) ) {
F_79 ( V_20 , V_20 -> V_148 ) ;
F_83 ( V_20 , V_20 -> V_150 ) ;
}
return V_152 ;
}
static void T_7 F_142 ( void )
{
const char * V_221 ;
V_221 = F_143 ( V_235 ) ;
if ( ! V_221 )
return;
if ( strncmp ( V_221 , L_72 , 6 ) == 0 ) {
V_231 = - 1 ;
}
}
static int T_7 F_144 ( struct V_193 * V_35 )
{
struct V_19 * V_20 ;
int V_152 ;
F_137 ( L_73 ,
V_117 ) ;
V_20 = F_145 ( sizeof( struct V_19 ) , V_228 ) ;
if ( ! V_20 )
return - V_51 ;
V_20 -> V_1 = V_35 -> V_1 ;
strcpy ( F_146 ( V_35 ) , V_236 ) ;
strcpy ( F_147 ( V_35 ) , V_237 ) ;
V_35 -> V_238 = V_20 ;
V_20 -> V_35 = V_35 ;
F_142 () ;
V_152 = F_140 ( V_20 ) ;
if ( V_152 )
goto V_239;
V_20 -> V_50 = F_7 ( V_20 ) ;
V_152 = F_125 ( V_20 ) ;
if ( V_152 )
goto V_239;
if ( ! F_148 () ) {
V_152 = F_51 ( V_20 ) ;
if ( V_152 )
goto V_240;
} else
F_109 ( L_74 ) ;
V_152 = F_107 ( V_20 ) ;
if ( V_152 )
goto V_241;
V_152 = F_43 ( V_20 ) ;
if ( V_152 )
goto V_242;
V_152 = F_97 ( V_20 ) ;
if ( V_152 )
goto V_243;
V_152 = F_19 ( V_20 ) ;
if ( V_152 && V_152 != - V_17 )
goto V_244;
V_152 = F_104 ( V_20 ) ;
if ( V_152 && V_152 != - V_17 )
goto V_245;
V_246 = true ;
return 0 ;
V_245:
F_16 ( V_20 ) ;
V_244:
F_94 ( V_20 ) ;
V_243:
F_36 ( V_20 ) ;
V_242:
F_114 ( V_20 ) ;
V_241:
F_57 ( V_20 ) ;
V_240:
F_132 ( V_20 ) ;
V_239:
F_139 ( V_20 -> V_21 ) ;
F_139 ( V_20 ) ;
return V_152 ;
}
static int F_149 ( struct V_193 * V_35 , int type )
{
struct V_19 * V_20 = F_117 ( V_35 ) ;
F_57 ( V_20 ) ;
F_94 ( V_20 ) ;
F_36 ( V_20 ) ;
F_114 ( V_20 ) ;
F_16 ( V_20 ) ;
F_102 ( V_20 ) ;
F_132 ( V_20 ) ;
F_139 ( V_20 -> V_21 ) ;
F_139 ( V_20 ) ;
return 0 ;
}
static int T_8 F_150 ( void )
{
int V_152 ;
V_152 = F_151 ( & V_247 ) ;
if ( V_152 < 0 )
return V_152 ;
V_152 = F_152 ( & V_248 ) ;
if ( V_152 < 0 )
goto V_249;
if ( ! V_246 ) {
V_152 = - V_17 ;
goto V_250;
}
return 0 ;
V_250:
F_153 ( & V_248 ) ;
V_249:
F_154 ( & V_247 ) ;
return V_152 ;
}
static void T_9 F_155 ( void )
{
F_153 ( & V_248 ) ;
F_154 ( & V_247 ) ;
}
