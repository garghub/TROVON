static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_2 (host, &nvmf_hosts, list) {
if ( ! strcmp ( V_3 -> V_4 , V_2 ) )
return V_3 ;
}
return NULL ;
}
static struct V_1 * F_3 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_4 ( & V_5 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_5 ( & V_3 -> V_6 ) ;
goto V_7;
}
V_3 = F_6 ( sizeof( * V_3 ) , V_8 ) ;
if ( ! V_3 )
goto V_7;
F_7 ( & V_3 -> V_6 ) ;
memcpy ( V_3 -> V_4 , V_2 , V_9 ) ;
F_8 ( & V_3 -> V_10 , & V_11 ) ;
V_7:
F_9 ( & V_5 ) ;
return V_3 ;
}
static struct V_1 * F_10 ( void )
{
struct V_1 * V_3 ;
V_3 = F_6 ( sizeof( * V_3 ) , V_8 ) ;
if ( ! V_3 )
return NULL ;
F_7 ( & V_3 -> V_6 ) ;
snprintf ( V_3 -> V_4 , V_9 ,
L_1 , & V_3 -> V_12 ) ;
F_4 ( & V_5 ) ;
F_8 ( & V_3 -> V_10 , & V_11 ) ;
F_9 ( & V_5 ) ;
return V_3 ;
}
static void F_11 ( struct V_13 * V_6 )
{
struct V_1 * V_3 = F_12 ( V_6 , struct V_1 , V_6 ) ;
F_4 ( & V_5 ) ;
F_13 ( & V_3 -> V_10 ) ;
F_9 ( & V_5 ) ;
F_14 ( V_3 ) ;
}
static void F_15 ( struct V_1 * V_3 )
{
if ( V_3 )
F_16 ( & V_3 -> V_6 , F_11 ) ;
}
int F_17 ( struct V_14 * V_15 , char * V_16 , int V_17 )
{
int V_18 = 0 ;
if ( V_15 -> V_19 -> V_20 & V_21 )
V_18 += snprintf ( V_16 , V_17 , L_2 , V_15 -> V_19 -> V_22 ) ;
if ( V_15 -> V_19 -> V_20 & V_23 )
V_18 += snprintf ( V_16 + V_18 , V_17 - V_18 , L_3 ,
( V_18 ) ? L_4 : L_5 , V_15 -> V_19 -> V_24 ) ;
if ( V_15 -> V_19 -> V_20 & V_25 )
V_18 += snprintf ( V_16 + V_18 , V_17 - V_18 , L_6 ,
( V_18 ) ? L_4 : L_5 , V_15 -> V_19 -> V_26 ) ;
V_18 += snprintf ( V_16 + V_18 , V_17 - V_18 , L_7 ) ;
return V_18 ;
}
int F_18 ( struct V_14 * V_15 , T_1 V_27 , T_1 * V_28 )
{
struct V_29 V_30 ;
union V_31 V_32 ;
int V_33 ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_34 . V_35 = V_36 ;
V_30 . V_34 . V_37 = V_38 ;
V_30 . V_34 . V_39 = F_19 ( V_27 ) ;
V_33 = F_20 ( V_15 -> V_40 , & V_30 , & V_32 , NULL , 0 , 0 ,
V_41 , 0 , 0 ) ;
if ( V_33 >= 0 )
* V_28 = F_21 ( V_32 . V_42 ) ;
if ( F_22 ( V_33 != 0 ) )
F_23 ( V_15 -> V_43 ,
L_8 ,
V_33 > 0 ? V_33 & ~ V_44 : V_33 , V_27 ) ;
return V_33 ;
}
int F_24 ( struct V_14 * V_15 , T_1 V_27 , V_42 * V_28 )
{
struct V_29 V_30 ;
union V_31 V_32 ;
int V_33 ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_34 . V_35 = V_36 ;
V_30 . V_34 . V_37 = V_38 ;
V_30 . V_34 . V_45 = 1 ;
V_30 . V_34 . V_39 = F_19 ( V_27 ) ;
V_33 = F_20 ( V_15 -> V_40 , & V_30 , & V_32 , NULL , 0 , 0 ,
V_41 , 0 , 0 ) ;
if ( V_33 >= 0 )
* V_28 = F_21 ( V_32 . V_42 ) ;
if ( F_22 ( V_33 != 0 ) )
F_23 ( V_15 -> V_43 ,
L_8 ,
V_33 > 0 ? V_33 & ~ V_44 : V_33 , V_27 ) ;
return V_33 ;
}
int F_25 ( struct V_14 * V_15 , T_1 V_27 , T_1 V_28 )
{
struct V_29 V_30 ;
int V_33 ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_46 . V_35 = V_36 ;
V_30 . V_46 . V_37 = V_47 ;
V_30 . V_46 . V_45 = 0 ;
V_30 . V_46 . V_39 = F_19 ( V_27 ) ;
V_30 . V_46 . V_48 = F_26 ( V_28 ) ;
V_33 = F_20 ( V_15 -> V_40 , & V_30 , NULL , NULL , 0 , 0 ,
V_41 , 0 , 0 ) ;
if ( F_22 ( V_33 ) )
F_23 ( V_15 -> V_43 ,
L_9 ,
V_33 > 0 ? V_33 & ~ V_44 : V_33 , V_27 ) ;
return V_33 ;
}
static void F_27 ( struct V_14 * V_15 ,
int V_49 , int V_39 , struct V_29 * V_30 ,
struct V_50 * V_51 )
{
int V_52 = V_49 & ( ~ V_44 ) ;
switch ( V_52 ) {
case ( V_53 ) :
if ( V_39 >> 16 ) {
char * V_54 = L_10 ;
switch ( V_39 & 0xffff ) {
case ( F_28 ( struct V_50 , V_55 ) ) :
F_23 ( V_15 -> V_43 ,
L_11 ,
V_54 , V_51 -> V_55 ) ;
break;
case ( F_28 ( struct V_50 , V_2 ) ) :
F_23 ( V_15 -> V_43 ,
L_12 ,
V_54 , V_51 -> V_2 ) ;
break;
case ( F_28 ( struct V_50 , V_56 ) ) :
F_23 ( V_15 -> V_43 ,
L_13 ,
V_54 , V_51 -> V_56 ) ;
break;
default:
F_23 ( V_15 -> V_43 ,
L_14 ,
V_54 , V_39 & 0xffff ) ;
break;
}
} else {
char * V_57 = L_15 ;
switch ( V_39 ) {
case ( F_28 ( struct V_58 , V_59 ) ) :
F_23 ( V_15 -> V_43 ,
L_16 ,
V_57 , V_30 -> V_60 . V_59 ) ;
break;
default:
F_23 ( V_15 -> V_43 ,
L_14 ,
V_57 , V_39 ) ;
}
}
break;
case V_61 :
F_23 ( V_15 -> V_43 ,
L_17 ,
V_51 -> V_56 , V_51 -> V_2 ) ;
break;
case V_62 :
F_23 ( V_15 -> V_43 ,
L_18 ) ;
break;
case V_63 :
F_23 ( V_15 -> V_43 ,
L_19 ,
V_30 -> V_60 . V_64 ) ;
break;
default:
F_23 ( V_15 -> V_43 ,
L_20 ,
V_52 ) ;
break;
}
}
int F_29 ( struct V_14 * V_15 )
{
struct V_29 V_30 ;
union V_31 V_32 ;
struct V_50 * V_51 ;
int V_33 ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_60 . V_35 = V_36 ;
V_30 . V_60 . V_37 = V_65 ;
V_30 . V_60 . V_59 = 0 ;
V_30 . V_60 . V_66 = F_30 ( V_67 - 1 ) ;
V_30 . V_60 . V_68 = V_15 -> V_19 -> V_69 ? 0 :
F_19 ( ( V_15 -> V_68 + V_70 ) * 1000 ) ;
V_51 = F_31 ( sizeof( * V_51 ) , V_8 ) ;
if ( ! V_51 )
return - V_71 ;
F_32 ( & V_51 -> V_72 , & V_15 -> V_19 -> V_3 -> V_12 ) ;
V_51 -> V_55 = F_30 ( 0xffff ) ;
strncpy ( V_51 -> V_56 , V_15 -> V_19 -> V_56 , V_9 ) ;
strncpy ( V_51 -> V_2 , V_15 -> V_19 -> V_3 -> V_4 , V_9 ) ;
V_33 = F_20 ( V_15 -> V_40 , & V_30 , & V_32 ,
V_51 , sizeof( * V_51 ) , 0 , V_41 , 1 ,
V_73 | V_74 ) ;
if ( V_33 ) {
F_27 ( V_15 , V_33 , F_33 ( V_32 . T_1 ) ,
& V_30 , V_51 ) ;
goto V_75;
}
V_15 -> V_55 = F_34 ( V_32 . V_76 ) ;
V_75:
F_14 ( V_51 ) ;
return V_33 ;
}
int F_35 ( struct V_14 * V_15 , V_76 V_59 )
{
struct V_29 V_30 ;
struct V_50 * V_51 ;
union V_31 V_32 ;
int V_33 ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_60 . V_35 = V_36 ;
V_30 . V_60 . V_37 = V_65 ;
V_30 . V_60 . V_59 = F_30 ( V_59 ) ;
V_30 . V_60 . V_66 = F_30 ( V_15 -> V_66 ) ;
V_51 = F_31 ( sizeof( * V_51 ) , V_8 ) ;
if ( ! V_51 )
return - V_71 ;
F_32 ( & V_51 -> V_72 , & V_15 -> V_19 -> V_3 -> V_12 ) ;
V_51 -> V_55 = F_30 ( V_15 -> V_55 ) ;
strncpy ( V_51 -> V_56 , V_15 -> V_19 -> V_56 , V_9 ) ;
strncpy ( V_51 -> V_2 , V_15 -> V_19 -> V_3 -> V_4 , V_9 ) ;
V_33 = F_20 ( V_15 -> V_77 , & V_30 , & V_32 ,
V_51 , sizeof( * V_51 ) , 0 , V_59 , 1 ,
V_73 | V_74 ) ;
if ( V_33 ) {
F_27 ( V_15 , V_33 , F_33 ( V_32 . T_1 ) ,
& V_30 , V_51 ) ;
}
F_14 ( V_51 ) ;
return V_33 ;
}
bool F_36 ( struct V_14 * V_15 )
{
if ( V_15 -> V_19 -> V_78 != - 1 &&
V_15 -> V_79 < V_15 -> V_19 -> V_78 )
return true ;
return false ;
}
int F_37 ( struct V_80 * V_81 )
{
if ( ! V_81 -> V_82 )
return - V_83 ;
F_38 ( & V_84 ) ;
F_8 ( & V_81 -> V_85 , & V_86 ) ;
F_39 ( & V_84 ) ;
return 0 ;
}
void F_40 ( struct V_80 * V_81 )
{
F_38 ( & V_84 ) ;
F_13 ( & V_81 -> V_85 ) ;
F_39 ( & V_84 ) ;
}
static struct V_80 * F_41 (
struct V_87 * V_19 )
{
struct V_80 * V_81 ;
F_42 ( & V_84 ) ;
F_2 (ops, &nvmf_transports, entry) {
if ( strcmp ( V_81 -> V_88 , V_19 -> V_89 ) == 0 )
return V_81 ;
}
return NULL ;
}
static int F_43 ( struct V_87 * V_19 ,
const char * V_16 )
{
T_2 args [ V_90 ] ;
char * V_91 , * V_92 , * V_93 ;
int V_94 , V_33 = 0 ;
T_3 V_95 = 0 ;
int V_96 = V_97 ;
T_4 V_72 ;
V_19 -> V_98 = V_99 ;
V_19 -> V_100 = F_44 () ;
V_19 -> V_101 = V_102 ;
V_19 -> V_68 = V_103 ;
V_91 = V_92 = F_45 ( V_16 , V_8 ) ;
if ( ! V_91 )
return - V_71 ;
F_46 ( & V_72 ) ;
while ( ( V_93 = F_47 ( & V_92 , L_21 ) ) != NULL ) {
if ( ! * V_93 )
continue;
V_94 = F_48 ( V_93 , V_104 , args ) ;
V_19 -> V_20 |= V_94 ;
switch ( V_94 ) {
case V_105 :
V_93 = F_49 ( args ) ;
if ( ! V_93 ) {
V_33 = - V_71 ;
goto V_106;
}
V_19 -> V_89 = V_93 ;
break;
case V_107 :
V_93 = F_49 ( args ) ;
if ( ! V_93 ) {
V_33 = - V_71 ;
goto V_106;
}
V_19 -> V_56 = V_93 ;
V_95 = strlen ( V_19 -> V_56 ) ;
if ( V_95 >= V_9 ) {
F_50 ( L_22 ,
V_19 -> V_56 , V_9 ) ;
V_33 = - V_83 ;
goto V_106;
}
V_19 -> V_69 =
! ( strcmp ( V_19 -> V_56 ,
V_108 ) ) ;
if ( V_19 -> V_69 )
V_19 -> V_100 = 0 ;
break;
case V_21 :
V_93 = F_49 ( args ) ;
if ( ! V_93 ) {
V_33 = - V_71 ;
goto V_106;
}
V_19 -> V_22 = V_93 ;
break;
case V_23 :
V_93 = F_49 ( args ) ;
if ( ! V_93 ) {
V_33 = - V_71 ;
goto V_106;
}
V_19 -> V_24 = V_93 ;
break;
case V_109 :
if ( F_51 ( args , & V_94 ) ) {
V_33 = - V_83 ;
goto V_106;
}
if ( V_94 < V_110 ||
V_94 > V_111 ) {
F_50 ( L_23 , V_94 ) ;
V_33 = - V_83 ;
goto V_106;
}
V_19 -> V_98 = V_94 ;
break;
case V_112 :
if ( F_51 ( args , & V_94 ) ) {
V_33 = - V_83 ;
goto V_106;
}
if ( V_94 <= 0 ) {
F_50 ( L_24 , V_94 ) ;
V_33 = - V_83 ;
goto V_106;
}
V_19 -> V_100 = F_52 (unsigned int,
num_online_cpus(), token) ;
break;
case V_113 :
if ( F_51 ( args , & V_94 ) ) {
V_33 = - V_83 ;
goto V_106;
}
if ( V_94 < 0 ) {
F_50 ( L_25 , V_94 ) ;
V_33 = - V_83 ;
goto V_106;
} else if ( V_94 == 0 && ! V_19 -> V_69 ) {
F_53 ( L_26 ) ;
}
V_19 -> V_68 = V_94 ;
if ( V_19 -> V_69 && V_19 -> V_68 ) {
F_50 ( L_27 ) ;
V_33 = - V_83 ;
goto V_106;
}
break;
case V_114 :
if ( F_51 ( args , & V_94 ) ) {
V_33 = - V_83 ;
goto V_106;
}
if ( V_94 < 0 )
F_53 ( L_28 ) ;
V_96 = V_94 ;
break;
case V_115 :
if ( V_19 -> V_3 ) {
F_50 ( L_29 ,
V_19 -> V_3 -> V_4 ) ;
V_33 = - V_116 ;
goto V_106;
}
V_93 = F_49 ( args ) ;
if ( ! V_93 ) {
V_33 = - V_71 ;
goto V_106;
}
V_95 = strlen ( V_93 ) ;
if ( V_95 >= V_9 ) {
F_50 ( L_22 ,
V_93 , V_9 ) ;
F_14 ( V_93 ) ;
V_33 = - V_83 ;
goto V_106;
}
V_19 -> V_3 = F_3 ( V_93 ) ;
F_14 ( V_93 ) ;
if ( ! V_19 -> V_3 ) {
V_33 = - V_71 ;
goto V_106;
}
break;
case V_117 :
if ( F_51 ( args , & V_94 ) ) {
V_33 = - V_83 ;
goto V_106;
}
if ( V_94 <= 0 ) {
F_50 ( L_30 , V_94 ) ;
V_33 = - V_83 ;
goto V_106;
}
V_19 -> V_101 = V_94 ;
break;
case V_25 :
V_93 = F_49 ( args ) ;
if ( ! V_93 ) {
V_33 = - V_71 ;
goto V_106;
}
V_19 -> V_26 = V_93 ;
break;
case V_118 :
V_93 = F_49 ( args ) ;
if ( ! V_93 ) {
V_33 = - V_71 ;
goto V_106;
}
if ( F_54 ( V_93 , & V_72 ) ) {
F_50 ( L_31 , V_93 ) ;
V_33 = - V_83 ;
goto V_106;
}
break;
default:
F_53 ( L_32 ,
V_93 ) ;
V_33 = - V_83 ;
goto V_106;
}
}
if ( V_96 < 0 )
V_19 -> V_78 = - 1 ;
else
V_19 -> V_78 = F_55 ( V_96 ,
V_19 -> V_101 ) ;
if ( ! V_19 -> V_3 ) {
F_5 ( & V_119 -> V_6 ) ;
V_19 -> V_3 = V_119 ;
}
F_32 ( & V_19 -> V_3 -> V_12 , & V_72 ) ;
V_106:
F_14 ( V_91 ) ;
return V_33 ;
}
static int F_56 ( struct V_87 * V_19 ,
unsigned int V_120 )
{
if ( ( V_19 -> V_20 & V_120 ) != V_120 ) {
int V_121 ;
for ( V_121 = 0 ; V_121 < F_57 ( V_104 ) ; V_121 ++ ) {
if ( ( V_104 [ V_121 ] . V_94 & V_120 ) &&
! ( V_104 [ V_121 ] . V_94 & V_19 -> V_20 ) ) {
F_53 ( L_33 ,
V_104 [ V_121 ] . V_122 ) ;
}
}
return - V_83 ;
}
return 0 ;
}
static int F_58 ( struct V_87 * V_19 ,
unsigned int V_123 )
{
if ( V_19 -> V_20 & ~ V_123 ) {
int V_121 ;
for ( V_121 = 0 ; V_121 < F_57 ( V_104 ) ; V_121 ++ ) {
if ( ( V_104 [ V_121 ] . V_94 & V_19 -> V_20 ) &&
( V_104 [ V_121 ] . V_94 & ~ V_123 ) ) {
F_53 ( L_34 ,
V_104 [ V_121 ] . V_122 ) ;
}
}
return - V_83 ;
}
return 0 ;
}
void F_59 ( struct V_87 * V_19 )
{
F_15 ( V_19 -> V_3 ) ;
F_14 ( V_19 -> V_89 ) ;
F_14 ( V_19 -> V_22 ) ;
F_14 ( V_19 -> V_24 ) ;
F_14 ( V_19 -> V_56 ) ;
F_14 ( V_19 -> V_26 ) ;
F_14 ( V_19 ) ;
}
static struct V_14 *
F_60 ( struct V_43 * V_124 , const char * V_16 , T_3 V_125 )
{
struct V_87 * V_19 ;
struct V_80 * V_81 ;
struct V_14 * V_15 ;
int V_33 ;
V_19 = F_31 ( sizeof( * V_19 ) , V_8 ) ;
if ( ! V_19 )
return F_61 ( - V_71 ) ;
V_33 = F_43 ( V_19 , V_16 ) ;
if ( V_33 )
goto V_126;
V_33 = F_56 ( V_19 , V_127 ) ;
if ( V_33 )
goto V_126;
V_19 -> V_20 &= ~ V_127 ;
F_62 ( & V_84 ) ;
V_81 = F_41 ( V_19 ) ;
if ( ! V_81 ) {
F_63 ( L_35 ,
V_19 -> V_89 ) ;
V_33 = - V_83 ;
goto V_7;
}
V_33 = F_56 ( V_19 , V_81 -> V_120 ) ;
if ( V_33 )
goto V_7;
V_33 = F_58 ( V_19 , V_128 |
V_81 -> V_123 | V_81 -> V_120 ) ;
if ( V_33 )
goto V_7;
V_15 = V_81 -> V_82 ( V_124 , V_19 ) ;
if ( F_64 ( V_15 ) ) {
V_33 = F_65 ( V_15 ) ;
goto V_7;
}
if ( strcmp ( V_15 -> V_129 , V_19 -> V_56 ) ) {
F_66 ( V_15 -> V_43 ,
L_36 ,
V_15 -> V_129 ) ;
F_67 ( & V_84 ) ;
V_15 -> V_81 -> V_130 ( V_15 ) ;
return F_61 ( - V_83 ) ;
}
F_67 ( & V_84 ) ;
return V_15 ;
V_7:
F_67 ( & V_84 ) ;
V_126:
F_59 ( V_19 ) ;
return F_61 ( V_33 ) ;
}
static T_5 F_68 ( struct V_131 * V_131 , const char T_6 * V_132 ,
T_3 V_125 , T_7 * V_133 )
{
struct V_134 * V_134 = V_131 -> V_135 ;
struct V_14 * V_15 ;
const char * V_16 ;
int V_33 = 0 ;
if ( V_125 > V_136 )
return - V_71 ;
V_16 = F_69 ( V_132 , V_125 ) ;
if ( F_64 ( V_16 ) )
return F_65 ( V_16 ) ;
F_4 ( & V_137 ) ;
if ( V_134 -> V_138 ) {
V_33 = - V_83 ;
goto V_7;
}
V_15 = F_60 ( V_139 , V_16 , V_125 ) ;
if ( F_64 ( V_15 ) ) {
V_33 = F_65 ( V_15 ) ;
goto V_7;
}
V_134 -> V_138 = V_15 ;
V_7:
F_9 ( & V_137 ) ;
F_14 ( V_16 ) ;
return V_33 ? V_33 : V_125 ;
}
static int F_70 ( struct V_134 * V_134 , void * V_138 )
{
struct V_14 * V_15 ;
int V_33 = 0 ;
F_4 ( & V_137 ) ;
V_15 = V_134 -> V_138 ;
if ( ! V_15 ) {
V_33 = - V_83 ;
goto V_7;
}
F_71 ( V_134 , L_37 ,
V_15 -> V_140 , V_15 -> V_55 ) ;
V_7:
F_9 ( & V_137 ) ;
return V_33 ;
}
static int F_72 ( struct V_141 * V_141 , struct V_131 * V_131 )
{
V_131 -> V_135 = NULL ;
return F_73 ( V_131 , F_70 , NULL ) ;
}
static int F_74 ( struct V_141 * V_141 , struct V_131 * V_131 )
{
struct V_134 * V_134 = V_131 -> V_135 ;
struct V_14 * V_15 = V_134 -> V_138 ;
if ( V_15 )
F_75 ( V_15 ) ;
return F_76 ( V_141 , V_131 ) ;
}
static int T_8 F_77 ( void )
{
int V_33 ;
V_119 = F_10 () ;
if ( ! V_119 )
return - V_71 ;
V_142 = F_78 ( V_143 , L_38 ) ;
if ( F_64 ( V_142 ) ) {
F_50 ( L_39 ) ;
V_33 = F_65 ( V_142 ) ;
goto V_144;
}
V_139 =
F_79 ( V_142 , NULL , F_80 ( 0 , 0 ) , NULL , L_40 ) ;
if ( F_64 ( V_139 ) ) {
F_50 ( L_41 ) ;
V_33 = F_65 ( V_139 ) ;
goto V_145;
}
V_33 = F_81 ( & V_146 ) ;
if ( V_33 ) {
F_50 ( L_42 , V_33 ) ;
goto V_147;
}
return 0 ;
V_147:
F_82 ( V_142 , F_80 ( 0 , 0 ) ) ;
V_145:
F_83 ( V_142 ) ;
V_144:
F_15 ( V_119 ) ;
return V_33 ;
}
static void T_9 F_84 ( void )
{
F_85 ( & V_146 ) ;
F_82 ( V_142 , F_80 ( 0 , 0 ) ) ;
F_83 ( V_142 ) ;
F_15 ( V_119 ) ;
F_86 ( sizeof( struct V_58 ) != 64 ) ;
F_86 ( sizeof( struct V_148 ) != 64 ) ;
F_86 ( sizeof( struct V_149 ) != 64 ) ;
F_86 ( sizeof( struct V_50 ) != 1024 ) ;
}
