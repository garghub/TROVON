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
if ( ! F_37 ( V_20 -> V_88 . V_71 . V_38 ) )
F_38 ( & V_20 -> V_88 . V_71 ) ;
if ( ! F_37 ( V_20 -> V_89 . V_71 . V_38 ) )
F_38 ( & V_20 -> V_89 . V_71 ) ;
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
V_68 -> V_90 = F_25 ;
V_68 -> V_91 = F_29 ;
V_68 -> V_92 = 1 ;
return F_42 ( & V_20 -> V_59 -> V_38 , V_68 ) ;
}
static int F_43 ( struct V_19 * V_20 )
{
int V_93 = 0 ;
if ( V_20 -> V_50 )
return 0 ;
V_20 -> V_73 = F_44 ( L_5 ) ;
if ( ! V_20 -> V_73 )
return - V_51 ;
if ( V_20 -> V_94 == V_95 )
V_93 = F_40 ( V_20 , & V_20 -> V_82 , L_6 ,
V_96 ) ;
if ( V_93 )
goto error;
if ( V_20 -> V_97 == V_95 )
V_93 = F_40 ( V_20 , & V_20 -> V_83 , L_7 ,
V_98 ) ;
if ( V_93 )
goto error;
V_93 = F_40 ( V_20 , & V_20 -> V_84 , L_8 , V_65 ) ;
if ( V_93 )
goto error;
V_93 = F_40 ( V_20 , & V_20 -> V_85 , L_9 , V_99 ) ;
if ( V_93 )
goto error;
V_93 = F_40 ( V_20 , & V_20 -> V_87 , L_10 , V_100 ) ;
if ( V_93 )
goto error;
V_93 = F_40 ( V_20 , & V_20 -> V_86 , L_11 , V_101 ) ;
if ( V_93 )
goto error;
V_93 = F_40 ( V_20 , & V_20 -> V_88 , L_12 , V_66 ) ;
if ( V_93 )
goto error;
if ( ! F_4 ( V_20 -> V_1 , V_80 , NULL ) &&
! F_4 ( V_20 -> V_1 , V_79 , NULL ) ) {
struct V_70 * V_71 = & V_20 -> V_89 ;
struct V_67 * V_102 = & V_71 -> V_71 ;
V_71 -> V_20 = V_20 ;
F_41 ( & V_71 -> V_74 , F_34 ) ;
V_102 -> V_21 = L_13 ;
V_102 -> V_90 = F_33 ;
V_102 -> V_91 = F_35 ;
V_102 -> V_92 = 3 ;
V_93 = F_42 ( & V_20 -> V_59 -> V_38 , V_102 ) ;
}
error:
if ( V_93 )
F_36 ( V_20 ) ;
return V_93 ;
}
static int F_45 ( struct V_103 * V_104 )
{
struct V_19 * V_20 = F_46 ( V_104 ) ;
unsigned long long V_14 ;
T_2 V_78 = V_15 ;
V_78 = F_10 ( V_20 -> V_1 , V_105 ,
NULL , & V_14 ) ;
if ( F_31 ( V_78 ) )
F_6 ( L_14 ) ;
return V_14 ;
}
static int F_47 ( struct V_103 * V_104 , int V_14 )
{
struct V_19 * V_20 = F_46 ( V_104 ) ;
if ( F_3 ( V_20 -> V_1 , V_106 , V_14 ) ) {
F_6 ( L_15 ) ;
return - V_107 ;
}
return 0 ;
}
static int F_48 ( struct V_103 * V_104 )
{
int V_14 = V_104 -> V_108 . V_76 ;
return F_47 ( V_104 , V_14 ) ;
}
static int F_49 ( struct V_19 * V_20 )
{
struct V_103 * V_104 = V_20 -> V_103 ;
int V_109 = V_104 -> V_108 . V_76 ;
F_50 ( V_104 , V_110 ) ;
return V_109 ;
}
static int F_51 ( struct V_19 * V_20 )
{
struct V_103 * V_104 ;
struct V_111 V_108 ;
if ( F_4 ( V_20 -> V_1 , V_105 , NULL ) ||
F_4 ( V_20 -> V_1 , V_106 , NULL ) )
return 0 ;
memset ( & V_108 , 0 , sizeof( struct V_111 ) ) ;
V_108 . V_92 = 15 ;
V_108 . type = V_112 ;
V_104 = F_52 ( V_113 ,
& V_20 -> V_59 -> V_38 , V_20 ,
& V_114 , & V_108 ) ;
if ( F_53 ( V_104 ) ) {
F_54 ( L_16 ) ;
V_20 -> V_103 = NULL ;
return F_55 ( V_104 ) ;
}
V_20 -> V_103 = V_104 ;
V_104 -> V_108 . V_76 = F_45 ( V_104 ) ;
V_104 -> V_108 . V_115 = V_116 ;
F_56 ( V_104 ) ;
return 0 ;
}
static void F_57 ( struct V_19 * V_20 )
{
if ( V_20 -> V_103 )
F_58 ( V_20 -> V_103 ) ;
V_20 -> V_103 = NULL ;
}
static T_3 F_59 ( struct V_35 * V_38 ,
struct V_117 * V_118 , char * V_119 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
int V_120 = 0 ;
unsigned long long V_121 ;
char V_122 [ 16 ] ;
T_2 V_78 = V_15 ;
V_120 += sprintf ( V_119 , V_123 L_17 V_124 L_18 ) ;
V_120 += sprintf ( V_119 + V_120 , L_19 , V_20 -> V_21 ) ;
V_78 = F_10 ( V_20 -> V_1 , L_20 , NULL , & V_121 ) ;
if ( ! F_31 ( V_78 ) )
V_120 += sprintf ( V_119 + V_120 , L_21 ,
( V_125 ) V_121 ) ;
V_78 = F_10 ( V_20 -> V_1 , L_22 , NULL , & V_121 ) ;
if ( ! F_31 ( V_78 ) )
V_120 += sprintf ( V_119 + V_120 , L_23 ,
( V_125 ) V_121 ) ;
V_78 = F_10 ( V_20 -> V_1 , L_24 , NULL , & V_121 ) ;
if ( ! F_31 ( V_78 ) )
V_120 += sprintf ( V_119 + V_120 , L_25 ,
( V_125 ) V_121 ) ;
if ( V_20 -> V_126 ) {
snprintf ( V_122 , 16 , L_26 , V_20 -> V_126 -> V_127 ) ;
V_120 += sprintf ( V_119 + V_120 , L_27 , V_122 ) ;
snprintf ( V_122 , 16 , L_26 , V_20 -> V_126 -> V_128 ) ;
V_120 += sprintf ( V_119 + V_120 , L_28 , V_122 ) ;
snprintf ( V_122 , 16 , L_26 , V_20 -> V_126 -> V_129 ) ;
V_120 += sprintf ( V_119 + V_120 , L_29 , V_122 ) ;
snprintf ( V_122 , 7 , L_30 , V_20 -> V_126 -> V_130 ) ;
V_120 += sprintf ( V_119 + V_120 , L_31 , V_122 ) ;
snprintf ( V_122 , 9 , L_30 , V_20 -> V_126 -> V_131 ) ;
V_120 += sprintf ( V_119 + V_120 , L_32 , V_122 ) ;
snprintf ( V_122 , 16 , L_33 , V_20 -> V_126 -> V_132 ) ;
V_120 += sprintf ( V_119 + V_120 , L_34 , V_122 ) ;
snprintf ( V_122 , 5 , L_30 , V_20 -> V_126 -> V_133 ) ;
V_120 += sprintf ( V_119 + V_120 , L_35 , V_122 ) ;
snprintf ( V_122 , 16 , L_33 , V_20 -> V_126 -> V_134 ) ;
V_120 += sprintf ( V_119 + V_120 , L_36 , V_122 ) ;
}
return V_120 ;
}
static int F_60 ( const char * V_122 , unsigned long V_11 , int * V_3 )
{
if ( ! V_11 )
return 0 ;
if ( V_11 > 31 )
return - V_81 ;
if ( sscanf ( V_122 , L_37 , V_3 ) != 1 )
return - V_81 ;
return V_11 ;
}
static T_3 F_61 ( struct V_19 * V_20 ,
const char * V_122 , T_4 V_11 ,
const char * V_2 )
{
int V_78 , V_14 ;
int V_135 = 0 ;
V_78 = F_60 ( V_122 , V_11 , & V_14 ) ;
if ( V_78 > 0 )
V_135 = V_14 ? 1 : 0 ;
if ( F_3 ( V_20 -> V_1 , V_2 , V_14 ) )
return - V_17 ;
return V_78 ;
}
static T_3 F_62 ( struct V_35 * V_38 ,
struct V_117 * V_118 , char * V_122 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return sprintf ( V_122 , L_38 , V_20 -> V_136 ) ;
}
static T_3 F_63 ( struct V_35 * V_38 , struct V_117 * V_118 ,
const char * V_122 , T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
int V_78 , V_14 ;
V_78 = F_60 ( V_122 , V_11 , & V_14 ) ;
if ( V_78 > 0 ) {
if ( F_3 ( V_20 -> V_1 , V_137 , V_14 ) ) {
F_6 ( L_39 ) ;
return - V_17 ;
}
V_20 -> V_136 = ( V_138 ) V_14 ;
}
return V_78 ;
}
static int F_64 ( struct V_19 * V_20 , int V_139 )
{
unsigned long long V_10 ;
T_2 V_78 = V_15 ;
if ( ! V_20 -> V_140 )
return ( V_20 -> V_141 & V_139 ) ? 1 : 0 ;
V_78 = F_10 ( V_20 -> V_1 , V_142 ,
NULL , & V_10 ) ;
if ( F_31 ( V_78 ) ) {
F_6 ( L_40 ) ;
return - V_81 ;
}
return ! ! ( V_10 & V_139 ) ;
}
static int F_65 ( struct V_19 * V_20 , int V_10 )
{
if ( F_3 ( V_20 -> V_1 , V_96 , ! ! V_10 ) ) {
F_6 ( L_41 , V_10 ) ;
return - V_107 ;
}
return 0 ;
}
static T_3 F_66 ( struct V_35 * V_38 ,
struct V_117 * V_118 , char * V_122 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return sprintf ( V_122 , L_42 , F_64 ( V_20 , V_143 ) ) ;
}
static T_3 F_67 ( struct V_35 * V_38 , struct V_117 * V_118 ,
const char * V_122 , T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return F_61 ( V_20 , V_122 , V_11 , V_96 ) ;
}
static int F_68 ( struct V_19 * V_20 , int V_10 )
{
if ( F_3 ( V_20 -> V_1 , V_98 , ! ! V_10 ) ) {
F_6 ( L_43 , V_10 ) ;
return - V_107 ;
}
return 0 ;
}
static T_3 F_69 ( struct V_35 * V_38 ,
struct V_117 * V_118 , char * V_122 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return sprintf ( V_122 , L_42 , F_64 ( V_20 , V_144 ) ) ;
}
static T_3 F_70 ( struct V_35 * V_38 ,
struct V_117 * V_118 , const char * V_122 ,
T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return F_61 ( V_20 , V_122 , V_11 , V_98 ) ;
}
static int F_71 ( struct V_19 * V_20 , int V_10 )
{
if ( F_3 ( V_20 -> V_1 , V_145 , ! ! V_10 ) ) {
F_6 ( L_44 , V_10 ) ;
return - V_107 ;
}
return 0 ;
}
static T_3 F_72 ( struct V_35 * V_38 ,
struct V_117 * V_118 , char * V_122 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return sprintf ( V_122 , L_42 , F_64 ( V_20 , V_146 ) ) ;
}
static T_3 F_73 ( struct V_35 * V_38 ,
struct V_117 * V_118 , const char * V_122 ,
T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return F_61 ( V_20 , V_122 , V_11 , V_145 ) ;
}
static int F_74 ( struct V_19 * V_20 , int V_10 )
{
if ( F_3 ( V_20 -> V_1 , V_147 , ! ! V_10 ) ) {
F_6 ( L_45 , V_10 ) ;
return - V_107 ;
}
return 0 ;
}
static T_3 F_75 ( struct V_35 * V_38 ,
struct V_117 * V_118 , char * V_122 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return sprintf ( V_122 , L_42 , F_64 ( V_20 , V_148 ) ) ;
}
static T_3 F_76 ( struct V_35 * V_38 ,
struct V_117 * V_118 , const char * V_122 ,
T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return F_61 ( V_20 , V_122 , V_11 , V_147 ) ;
}
static void F_77 ( struct V_19 * V_20 , int V_14 )
{
if ( F_3 ( V_20 -> V_1 , V_149 , V_14 ) )
F_6 ( L_46 ) ;
return;
}
static T_3 F_78 ( struct V_35 * V_38 , struct V_117 * V_118 ,
const char * V_122 , T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
int V_78 , V_14 ;
V_78 = F_60 ( V_122 , V_11 , & V_14 ) ;
if ( V_78 > 0 )
F_77 ( V_20 , V_14 ) ;
return V_78 ;
}
static void F_79 ( struct V_19 * V_20 , int V_14 )
{
int V_16 ;
if ( V_20 -> V_50 ) {
V_16 = F_8 ( V_20 , V_150 , V_14 ) ;
if ( ! V_16 )
V_16 = F_8 ( V_20 , V_151 , V_14 ) ;
} else {
V_16 = F_3 ( V_20 -> V_1 , V_152 , V_14 ) ;
}
if ( V_16 )
F_80 ( L_47 ) ;
V_20 -> V_153 = V_14 ;
}
static T_3 F_81 ( struct V_35 * V_38 ,
struct V_117 * V_118 , char * V_122 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return sprintf ( V_122 , L_42 , V_20 -> V_153 ) ;
}
static T_3 F_82 ( struct V_35 * V_38 , struct V_117 * V_118 ,
const char * V_122 , T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
int V_78 , V_14 ;
V_78 = F_60 ( V_122 , V_11 , & V_14 ) ;
if ( V_78 > 0 )
F_79 ( V_20 , V_14 ? 1 : 0 ) ;
return V_78 ;
}
static void F_83 ( struct V_19 * V_20 , int V_14 )
{
if ( F_3 ( V_20 -> V_1 , V_154 , V_14 ) )
F_6 ( L_48 ) ;
V_20 -> V_155 = V_14 ;
}
static T_3 F_84 ( struct V_35 * V_38 ,
struct V_117 * V_118 , char * V_122 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return sprintf ( V_122 , L_42 , V_20 -> V_155 ) ;
}
static T_3 F_85 ( struct V_35 * V_38 , struct V_117 * V_118 ,
const char * V_122 , T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
int V_78 , V_14 ;
V_78 = F_60 ( V_122 , V_11 , & V_14 ) ;
if ( V_78 > 0 ) {
V_14 = ( 0 < V_14 ) ? ( ( 15 < V_14 ) ? 15 : V_14 ) : 0 ;
F_83 ( V_20 , V_14 ) ;
}
return V_78 ;
}
static int F_86 ( struct V_19 * V_20 , int V_156 , int * V_157 )
{
struct V_4 V_158 = { V_159 , NULL } ;
int V_49 = F_1 ( V_20 -> V_1 , V_25 , V_156 ,
& V_158 ) ;
if ( ! V_49 ) {
union V_8 * V_160 = V_158 . V_12 ;
if ( V_160 && V_160 -> type == V_13 )
* V_157 = V_160 -> integer . V_14 ;
else
V_49 = - V_107 ;
}
return V_49 ;
}
static T_3 F_87 ( struct V_35 * V_38 ,
struct V_117 * V_118 , char * V_122 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
int V_49 , V_161 , V_162 ;
V_49 = F_86 ( V_20 , V_163 , & V_161 ) ;
if ( ! V_49 )
V_49 = F_86 ( V_20 , V_164 , & V_162 ) ;
if ( ! V_49 )
return sprintf ( V_122 , L_42 , 10 * V_161 + V_162 ) ;
return V_49 ;
}
static int F_88 ( struct V_19 * V_20 )
{
unsigned long long V_10 ;
T_2 V_78 = V_15 ;
V_78 = F_10 ( V_20 -> V_1 , V_165 ,
NULL , & V_10 ) ;
if ( F_31 ( V_78 ) ) {
F_6 ( L_49 ) ;
return - V_17 ;
}
return ! ! V_10 ;
}
static int F_89 ( struct V_19 * V_20 , int V_10 )
{
const char * V_166 = V_10 ? V_167 : V_168 ;
if ( F_3 ( V_20 -> V_1 , V_166 , 0x02 ) )
return - V_17 ;
return 0 ;
}
static T_3 F_90 ( struct V_35 * V_38 ,
struct V_117 * V_118 , char * V_122 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
return sprintf ( V_122 , L_42 , F_88 ( V_20 ) ) ;
}
static T_3 F_91 ( struct V_35 * V_38 , struct V_117 * V_118 ,
const char * V_122 , T_4 V_11 )
{
struct V_19 * V_20 = F_13 ( V_38 ) ;
int V_78 , V_14 ;
int V_16 ;
V_78 = F_60 ( V_122 , V_11 , & V_14 ) ;
if ( V_78 <= 0 )
return - V_81 ;
V_16 = F_89 ( V_20 , ! ! V_14 ) ;
if ( V_16 )
return V_16 ;
F_92 ( V_20 -> V_169 . V_170 , ! V_14 ) ;
return V_78 ;
}
static int F_93 ( void * V_171 , bool V_172 )
{
struct V_19 * V_20 = V_171 ;
return F_89 ( V_20 , ! V_172 ) ;
}
static int F_94 ( void * V_171 , bool V_172 )
{
struct V_173 * V_174 = V_171 ;
struct V_19 * V_20 = V_174 -> V_20 ;
if ( V_174 -> V_175 == V_143 )
return F_65 ( V_20 , ! V_172 ) ;
else if ( V_174 -> V_175 == V_144 )
return F_68 ( V_20 , ! V_172 ) ;
else if ( V_174 -> V_175 == V_146 )
return F_71 ( V_20 , ! V_172 ) ;
else if ( V_174 -> V_175 == V_148 )
return F_74 ( V_20 , ! V_172 ) ;
return - V_81 ;
}
static void F_95 ( struct V_173 * V_174 )
{
if ( ! V_174 -> V_170 )
return ;
F_96 ( V_174 -> V_170 ) ;
F_97 ( V_174 -> V_170 ) ;
V_174 -> V_170 = NULL ;
}
static void F_98 ( struct V_19 * V_20 )
{
F_95 ( & V_20 -> V_176 ) ;
F_95 ( & V_20 -> V_177 ) ;
F_95 ( & V_20 -> V_178 ) ;
F_95 ( & V_20 -> V_169 ) ;
}
static int F_99 ( struct V_19 * V_20 , struct V_173 * V_174 ,
const char * V_21 , int V_175 , int type ,
const struct V_179 * V_180 )
{
int V_157 ;
V_174 -> V_175 = V_175 ;
V_174 -> V_20 = V_20 ;
V_174 -> V_170 = F_100 ( V_21 , & V_20 -> V_59 -> V_38 ,
type , V_180 , V_174 ) ;
if ( ! V_174 -> V_170 )
return - V_81 ;
V_157 = F_101 ( V_174 -> V_170 ) ;
if ( V_157 ) {
F_97 ( V_174 -> V_170 ) ;
V_174 -> V_170 = NULL ;
}
return V_157 ;
}
static int F_102 ( struct V_19 * V_20 )
{
int V_157 = 0 ;
if ( V_20 -> V_50 )
return - V_17 ;
if ( ! F_4 ( V_20 -> V_1 , V_167 , NULL ) &&
! F_4 ( V_20 -> V_1 , V_168 , NULL ) &&
! F_4 ( V_20 -> V_1 , V_165 , NULL ) )
V_157 = F_99 ( V_20 , & V_20 -> V_169 , L_50 ,
- 1 , V_181 ,
& V_182 ) ;
if ( V_157 )
goto exit;
if ( ! F_4 ( V_20 -> V_1 , V_96 , NULL ) &&
V_20 -> V_94 == V_183 )
V_157 = F_99 ( V_20 , & V_20 -> V_178 , L_51 ,
V_143 , V_184 ,
& V_185 ) ;
if ( V_157 )
goto exit;
if ( ! F_4 ( V_20 -> V_1 , V_98 , NULL ) &&
V_20 -> V_97 == V_183 )
V_157 = F_99 ( V_20 , & V_20 -> V_177 ,
L_52 , V_144 ,
V_186 ,
& V_185 ) ;
if ( V_157 )
goto exit;
if ( ! F_4 ( V_20 -> V_1 , V_147 , NULL ) )
V_157 = F_99 ( V_20 , & V_20 -> V_176 , L_53 ,
V_148 , V_187 ,
& V_185 ) ;
if ( V_157 )
goto exit;
if ( ! F_4 ( V_20 -> V_1 , V_145 , NULL ) )
V_157 = F_99 ( V_20 , & V_20 -> V_188 , L_54 ,
V_146 , V_189 ,
& V_185 ) ;
if ( V_157 )
goto exit;
exit:
if ( V_157 )
F_98 ( V_20 ) ;
return V_157 ;
}
static int F_103 ( void * V_171 , bool V_172 )
{
struct V_173 * V_174 = V_171 ;
int V_16 = F_8 ( V_174 -> V_20 , V_174 -> V_175 , ! V_172 ) ;
return V_16 ;
}
static int F_104 ( struct V_19 * V_20 , struct V_173 * V_174 ,
const char * V_21 , int V_190 , int V_191 )
{
return F_99 ( V_20 , V_174 , V_21 , V_190 , V_191 ,
& V_192 ) ;
}
static int F_105 ( struct V_19 * V_20 )
{
int V_16 = 0 ;
if( ! V_20 -> V_50 )
return - V_17 ;
V_16 = F_104 ( V_20 , & V_20 -> V_178 , L_55 ,
V_193 , V_184 ) ;
if( V_16 )
goto exit;
V_16 = F_104 ( V_20 , & V_20 -> V_177 , L_56 ,
V_194 , V_186 ) ;
if( V_16 )
goto exit;
V_16 = F_104 ( V_20 , & V_20 -> V_176 , L_57 ,
V_195 , V_187 ) ;
exit:
if ( V_16 )
F_98 ( V_20 ) ;
return V_16 ;
}
static void F_106 ( struct V_19 * V_20 , int V_196 )
{
if ( ! V_20 -> V_197 )
return ;
if ( ! F_107 ( V_20 -> V_197 , V_196 , 1 , true ) )
F_108 ( L_58 , V_196 ) ;
}
static int F_109 ( struct V_19 * V_20 )
{
struct V_198 * V_37 ;
int error ;
V_37 = F_110 () ;
if ( ! V_37 )
return - V_51 ;
V_37 -> V_21 = L_59 ;
V_37 -> V_57 = V_113 L_2 ;
V_37 -> V_60 . V_61 = V_62 ;
V_37 -> V_38 . V_36 = & V_20 -> V_59 -> V_38 ;
error = F_111 ( V_37 , V_199 , NULL ) ;
if ( error ) {
F_54 ( L_60 ) ;
goto V_200;
}
error = F_112 ( V_37 ) ;
if ( error ) {
F_6 ( L_61 ) ;
goto V_201;
}
V_20 -> V_197 = V_37 ;
return 0 ;
V_201:
F_113 ( V_37 ) ;
V_200:
F_114 ( V_37 ) ;
return error ;
}
static void F_115 ( struct V_19 * V_20 )
{
if ( V_20 -> V_197 ) {
F_113 ( V_20 -> V_197 ) ;
F_116 ( V_20 -> V_197 ) ;
}
V_20 -> V_197 = NULL ;
}
static void F_117 ( struct V_202 * V_35 , V_138 V_196 )
{
struct V_19 * V_20 = F_118 ( V_35 ) ;
T_5 V_11 ;
V_11 = V_20 -> V_203 [ V_196 % 128 ] ++ ;
F_119 ( V_20 -> V_35 -> V_204 . V_205 ,
F_120 ( & V_20 -> V_35 -> V_38 ) , V_196 ,
V_11 ) ;
if ( V_196 >= V_206 && V_196 <= V_207 )
V_196 = V_208 ;
else if ( V_196 >= V_209 &&
V_196 <= V_210 )
V_196 = V_211 ;
if ( V_196 == V_211 || V_196 == V_208 ) {
if ( V_20 -> V_103 != NULL ) {
F_49 ( V_20 ) ;
return ;
}
}
if ( V_20 -> F_12 && V_196 == 0xEA ) {
F_121 ( & V_20 -> F_12 -> V_37 -> V_38 . V_212 ,
V_213 ) ;
return ;
}
F_106 ( V_20 , V_196 ) ;
}
static T_6 F_122 ( struct V_214 * V_212 ,
struct V_215 * V_118 ,
int V_216 )
{
struct V_35 * V_38 = F_26 ( V_212 , struct V_35 , V_212 ) ;
struct V_59 * V_217 = F_123 ( V_38 ) ;
struct V_19 * V_20 = F_124 ( V_217 ) ;
T_1 V_1 = V_20 -> V_1 ;
bool V_218 ;
if ( V_20 -> V_50 ) {
if ( V_118 == & V_219 . V_118 )
V_218 = true ;
else if ( V_118 == & V_220 . V_118 )
V_218 = false ;
else
goto V_221;
return V_218 ;
}
V_221:
if ( V_118 == & V_222 . V_118 ) {
V_218 = ! F_4 ( V_1 , V_96 , NULL ) ;
} else if ( V_118 == & V_223 . V_118 ) {
V_218 = ! F_4 ( V_1 , V_98 , NULL ) ;
} else if ( V_118 == & V_224 . V_118 ) {
V_218 = ! F_4 ( V_1 , V_149 , NULL ) ;
} else if ( V_118 == & V_225 . V_118 ) {
V_218 =
! F_4 ( V_20 -> V_1 , V_145 , NULL ) ;
} else if ( V_118 == & V_226 . V_118 ) {
V_218 = ! F_4 ( V_20 -> V_1 , V_147 , NULL ) ;
} else if ( V_118 == & V_227 . V_118 ) {
V_218 = ! F_4 ( V_1 , V_137 , NULL ) ;
} else if ( V_118 == & V_219 . V_118 ||
V_118 == & V_220 . V_118 ) {
V_218 = ! F_4 ( V_1 , V_152 , NULL ) &&
! F_4 ( V_1 , V_154 , NULL ) ;
} else if ( V_118 == & V_228 . V_118 ) {
V_218 = V_20 -> V_50 ;
} else if ( V_118 == & V_229 . V_118 ) {
V_218 = ! F_4 ( V_1 , V_167 , NULL ) &&
! F_4 ( V_1 , V_168 , NULL ) &&
! F_4 ( V_1 , V_165 , NULL ) ;
} else {
V_218 = true ;
}
return V_218 ? V_118 -> V_230 : 0 ;
}
static int F_125 ( struct V_19 * V_20 )
{
int V_157 ;
V_20 -> V_59 = F_126 ( V_113 , - 1 ) ;
if ( ! V_20 -> V_59 )
return - V_51 ;
F_127 ( V_20 -> V_59 , V_20 ) ;
V_157 = F_128 ( V_20 -> V_59 ) ;
if ( V_157 )
goto V_231;
V_157 = F_129 ( & V_20 -> V_59 -> V_38 . V_212 ,
& V_232 ) ;
if ( V_157 )
goto V_233;
return 0 ;
V_233:
F_130 ( V_20 -> V_59 ) ;
V_231:
F_131 ( V_20 -> V_59 ) ;
return V_157 ;
}
static void F_132 ( struct V_19 * V_20 )
{
F_133 ( & V_20 -> V_59 -> V_38 . V_212 , & V_232 ) ;
F_134 ( V_20 -> V_59 ) ;
}
static int F_135 ( struct V_19 * V_20 )
{
struct V_4 V_158 = { V_159 , NULL } ;
union V_8 * V_234 = NULL ;
unsigned long long V_235 ;
char * string = NULL ;
T_2 V_10 ;
V_10 = F_136 ( V_236 , 1 , & V_20 -> V_126 ) ;
if ( F_31 ( V_10 ) )
F_6 ( L_62 ) ;
if ( F_1 ( V_20 -> V_1 , L_63 , 0 , & V_158 ) ) {
F_54 ( L_64 ) ;
return - V_17 ;
}
V_10 =
F_10 ( V_20 -> V_1 , L_65 , NULL , & V_235 ) ;
if ( F_31 ( V_10 ) )
F_6 ( L_66 ) ;
else if ( V_235 )
F_137 ( L_67 ,
( V_125 ) V_235 ) ;
if ( F_3 ( V_20 -> V_1 , L_68 , V_237 ) )
F_54 ( L_69 , V_237 ) ;
if ( V_158 . V_12 ) {
V_234 = V_158 . V_12 ;
switch ( V_234 -> type ) {
case V_238 :
string = V_234 -> string . V_12 ;
break;
case V_239 :
string = V_234 -> V_158 . V_12 ;
break;
default:
string = L_70 ;
break;
}
}
V_20 -> V_21 = F_138 ( string , V_240 ) ;
if ( ! V_20 -> V_21 ) {
F_139 ( V_158 . V_12 ) ;
return - V_51 ;
}
if ( string )
F_137 ( L_71 , string ) ;
if ( ! F_4 ( V_20 -> V_1 , V_142 , NULL ) )
V_20 -> V_140 = true ;
F_139 ( V_234 ) ;
return V_15 ;
}
static int F_140 ( struct V_19 * V_20 )
{
int V_157 = 0 ;
V_157 = F_141 ( V_20 -> V_35 ) ;
if ( V_157 )
return V_157 ;
if ( ! V_20 -> V_35 -> V_10 . V_241 ) {
F_54 ( L_72 ) ;
return - V_17 ;
}
V_157 = F_135 ( V_20 ) ;
if ( V_157 )
return V_157 ;
if ( ! strcmp ( V_97 , L_73 ) )
V_20 -> V_97 = V_95 ;
else if ( ! strcmp ( V_97 , L_74 ) )
V_20 -> V_97 = V_183 ;
if ( ! strcmp ( V_94 , L_73 ) )
V_20 -> V_94 = V_95 ;
else if ( ! strcmp ( V_94 , L_74 ) )
V_20 -> V_94 = V_183 ;
if ( V_242 >= 0 )
F_68 ( V_20 , ! ! V_242 ) ;
if ( V_243 >= 0 )
F_65 ( V_20 , ! ! V_243 ) ;
if ( V_244 >= 0 )
F_71 ( V_20 , ! ! V_244 ) ;
if ( V_245 >= 0 )
F_74 ( V_20 , ! ! V_245 ) ;
if ( ! F_4 ( V_20 -> V_1 , V_80 , NULL ) )
F_32 ( V_20 , 1 ) ;
V_20 -> V_136 = 0xFFF ;
V_20 -> V_153 = ! ! V_246 ;
V_20 -> V_155 = 5 ;
if ( V_20 -> V_50 ) {
F_79 ( V_20 , V_20 -> V_153 ) ;
} else if ( ! F_4 ( V_20 -> V_1 , V_152 , NULL ) &&
! F_4 ( V_20 -> V_1 , V_154 , NULL ) ) {
F_79 ( V_20 , V_20 -> V_153 ) ;
F_83 ( V_20 , V_20 -> V_155 ) ;
}
return V_157 ;
}
static void F_142 ( void )
{
const char * V_234 ;
V_234 = F_143 ( V_247 ) ;
if ( ! V_234 )
return;
if ( strncmp ( V_234 , L_75 , 6 ) == 0 ) {
V_243 = - 1 ;
}
}
static int F_144 ( struct V_202 * V_35 )
{
struct V_19 * V_20 ;
int V_157 ;
F_137 ( L_76 ,
V_124 ) ;
V_20 = F_145 ( sizeof( struct V_19 ) , V_240 ) ;
if ( ! V_20 )
return - V_51 ;
V_20 -> V_1 = V_35 -> V_1 ;
strcpy ( F_146 ( V_35 ) , V_248 ) ;
strcpy ( F_147 ( V_35 ) , V_249 ) ;
V_35 -> V_250 = V_20 ;
V_20 -> V_35 = V_35 ;
F_142 () ;
V_157 = F_140 ( V_20 ) ;
if ( V_157 )
goto V_251;
V_20 -> V_50 = F_7 ( V_20 ) ;
V_157 = F_125 ( V_20 ) ;
if ( V_157 )
goto V_251;
if ( ! F_148 () ) {
V_157 = F_51 ( V_20 ) ;
if ( V_157 )
goto V_252;
} else
F_108 ( L_77 ) ;
V_157 = F_109 ( V_20 ) ;
if ( V_157 )
goto V_253;
V_157 = F_43 ( V_20 ) ;
if ( V_157 )
goto V_254;
V_157 = F_102 ( V_20 ) ;
if ( V_157 && V_157 != - V_17 )
goto V_255;
V_157 = F_19 ( V_20 ) ;
if ( V_157 && V_157 != - V_17 )
goto V_256;
V_157 = F_105 ( V_20 ) ;
if ( V_157 && V_157 != - V_17 )
goto V_257;
V_258 = true ;
return 0 ;
V_257:
F_16 ( V_20 ) ;
V_256:
F_98 ( V_20 ) ;
V_255:
F_36 ( V_20 ) ;
V_254:
F_115 ( V_20 ) ;
V_253:
F_57 ( V_20 ) ;
V_252:
F_132 ( V_20 ) ;
V_251:
F_139 ( V_20 ) ;
return V_157 ;
}
static int F_149 ( struct V_202 * V_35 )
{
struct V_19 * V_20 = F_118 ( V_35 ) ;
F_57 ( V_20 ) ;
F_98 ( V_20 ) ;
F_36 ( V_20 ) ;
F_115 ( V_20 ) ;
F_16 ( V_20 ) ;
F_132 ( V_20 ) ;
F_139 ( V_20 -> V_21 ) ;
F_139 ( V_20 ) ;
return 0 ;
}
static int T_7 F_150 ( void )
{
int V_157 ;
V_157 = F_151 ( & V_259 ) ;
if ( V_157 < 0 )
return V_157 ;
V_157 = F_152 ( & V_260 ) ;
if ( V_157 < 0 )
goto V_261;
if ( ! V_258 ) {
V_157 = - V_17 ;
goto V_262;
}
return 0 ;
V_262:
F_153 ( & V_260 ) ;
V_261:
F_154 ( & V_259 ) ;
return V_157 ;
}
static void T_8 F_155 ( void )
{
F_153 ( & V_260 ) ;
F_154 ( & V_259 ) ;
}
