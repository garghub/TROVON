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
F_8 ( & V_3 -> V_10 ) ;
F_9 ( & V_3 -> V_11 , & V_12 ) ;
V_7:
F_10 ( & V_5 ) ;
return V_3 ;
}
static struct V_1 * F_11 ( void )
{
struct V_1 * V_3 ;
V_3 = F_6 ( sizeof( * V_3 ) , V_8 ) ;
if ( ! V_3 )
return NULL ;
F_7 ( & V_3 -> V_6 ) ;
F_8 ( & V_3 -> V_10 ) ;
snprintf ( V_3 -> V_4 , V_9 ,
L_1 , & V_3 -> V_10 ) ;
F_4 ( & V_5 ) ;
F_9 ( & V_3 -> V_11 , & V_12 ) ;
F_10 ( & V_5 ) ;
return V_3 ;
}
static void F_12 ( struct V_13 * V_6 )
{
struct V_1 * V_3 = F_13 ( V_6 , struct V_1 , V_6 ) ;
F_4 ( & V_5 ) ;
F_14 ( & V_3 -> V_11 ) ;
F_10 ( & V_5 ) ;
F_15 ( V_3 ) ;
}
static void F_16 ( struct V_1 * V_3 )
{
if ( V_3 )
F_17 ( & V_3 -> V_6 , F_12 ) ;
}
int F_18 ( struct V_14 * V_15 , char * V_16 , int V_17 )
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
const char * F_19 ( struct V_14 * V_15 )
{
return V_15 -> V_19 -> V_27 ;
}
int F_20 ( struct V_14 * V_15 , T_1 V_28 , T_1 * V_29 )
{
struct V_30 V_31 ;
union V_32 V_33 ;
int V_34 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_35 . V_36 = V_37 ;
V_31 . V_35 . V_38 = V_39 ;
V_31 . V_35 . V_40 = F_21 ( V_28 ) ;
V_34 = F_22 ( V_15 -> V_41 , & V_31 , & V_33 , NULL , 0 , 0 ,
V_42 , 0 , 0 ) ;
if ( V_34 >= 0 )
* V_29 = F_23 ( V_33 . V_43 ) ;
if ( F_24 ( V_34 != 0 ) )
F_25 ( V_15 -> V_44 ,
L_8 ,
V_34 > 0 ? V_34 & ~ V_45 : V_34 , V_28 ) ;
return V_34 ;
}
int F_26 ( struct V_14 * V_15 , T_1 V_28 , V_43 * V_29 )
{
struct V_30 V_31 ;
union V_32 V_33 ;
int V_34 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_35 . V_36 = V_37 ;
V_31 . V_35 . V_38 = V_39 ;
V_31 . V_35 . V_46 = 1 ;
V_31 . V_35 . V_40 = F_21 ( V_28 ) ;
V_34 = F_22 ( V_15 -> V_41 , & V_31 , & V_33 , NULL , 0 , 0 ,
V_42 , 0 , 0 ) ;
if ( V_34 >= 0 )
* V_29 = F_23 ( V_33 . V_43 ) ;
if ( F_24 ( V_34 != 0 ) )
F_25 ( V_15 -> V_44 ,
L_8 ,
V_34 > 0 ? V_34 & ~ V_45 : V_34 , V_28 ) ;
return V_34 ;
}
int F_27 ( struct V_14 * V_15 , T_1 V_28 , T_1 V_29 )
{
struct V_30 V_31 ;
int V_34 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_47 . V_36 = V_37 ;
V_31 . V_47 . V_38 = V_48 ;
V_31 . V_47 . V_46 = 0 ;
V_31 . V_47 . V_40 = F_21 ( V_28 ) ;
V_31 . V_47 . V_49 = F_28 ( V_29 ) ;
V_34 = F_22 ( V_15 -> V_41 , & V_31 , NULL , NULL , 0 , 0 ,
V_42 , 0 , 0 ) ;
if ( F_24 ( V_34 ) )
F_25 ( V_15 -> V_44 ,
L_9 ,
V_34 > 0 ? V_34 & ~ V_45 : V_34 , V_28 ) ;
return V_34 ;
}
static void F_29 ( struct V_14 * V_15 ,
int V_50 , int V_40 , struct V_30 * V_31 ,
struct V_51 * V_52 )
{
int V_53 = V_50 & ( ~ V_45 ) ;
switch ( V_53 ) {
case ( V_54 ) :
if ( V_40 >> 16 ) {
char * V_55 = L_10 ;
switch ( V_40 & 0xffff ) {
case ( F_30 ( struct V_51 , V_56 ) ) :
F_25 ( V_15 -> V_44 ,
L_11 ,
V_55 , V_52 -> V_56 ) ;
break;
case ( F_30 ( struct V_51 , V_2 ) ) :
F_25 ( V_15 -> V_44 ,
L_12 ,
V_55 , V_52 -> V_2 ) ;
break;
case ( F_30 ( struct V_51 , V_27 ) ) :
F_25 ( V_15 -> V_44 ,
L_13 ,
V_55 , V_52 -> V_27 ) ;
break;
default:
F_25 ( V_15 -> V_44 ,
L_14 ,
V_55 , V_40 & 0xffff ) ;
break;
}
} else {
char * V_57 = L_15 ;
switch ( V_40 ) {
case ( F_30 ( struct V_58 , V_59 ) ) :
F_25 ( V_15 -> V_44 ,
L_16 ,
V_57 , V_31 -> V_60 . V_59 ) ;
break;
default:
F_25 ( V_15 -> V_44 ,
L_14 ,
V_57 , V_40 ) ;
}
}
break;
default:
F_25 ( V_15 -> V_44 ,
L_17 ,
V_53 ) ;
break;
}
}
int F_31 ( struct V_14 * V_15 )
{
struct V_30 V_31 ;
union V_32 V_33 ;
struct V_51 * V_52 ;
int V_34 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_60 . V_36 = V_37 ;
V_31 . V_60 . V_38 = V_61 ;
V_31 . V_60 . V_59 = 0 ;
V_31 . V_60 . V_62 = F_32 ( V_63 - 1 ) ;
V_31 . V_60 . V_64 = V_15 -> V_19 -> V_65 ? 0 :
F_21 ( ( V_15 -> V_64 + V_66 ) * 1000 ) ;
V_52 = F_33 ( sizeof( * V_52 ) , V_8 ) ;
if ( ! V_52 )
return - V_67 ;
memcpy ( & V_52 -> V_68 , & V_15 -> V_19 -> V_3 -> V_10 , sizeof( V_69 ) ) ;
V_52 -> V_56 = F_32 ( 0xffff ) ;
strncpy ( V_52 -> V_27 , V_15 -> V_19 -> V_27 , V_9 ) ;
strncpy ( V_52 -> V_2 , V_15 -> V_19 -> V_3 -> V_4 , V_9 ) ;
V_34 = F_22 ( V_15 -> V_41 , & V_31 , & V_33 ,
V_52 , sizeof( * V_52 ) , 0 , V_42 , 1 ,
V_70 | V_71 ) ;
if ( V_34 ) {
F_29 ( V_15 , V_34 , F_34 ( V_33 . T_1 ) ,
& V_31 , V_52 ) ;
goto V_72;
}
V_15 -> V_56 = F_35 ( V_33 . V_73 ) ;
V_72:
F_15 ( V_52 ) ;
return V_34 ;
}
int F_36 ( struct V_14 * V_15 , V_73 V_59 )
{
struct V_30 V_31 ;
struct V_51 * V_52 ;
union V_32 V_33 ;
int V_34 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_60 . V_36 = V_37 ;
V_31 . V_60 . V_38 = V_61 ;
V_31 . V_60 . V_59 = F_32 ( V_59 ) ;
V_31 . V_60 . V_62 = F_32 ( V_15 -> V_62 ) ;
V_52 = F_33 ( sizeof( * V_52 ) , V_8 ) ;
if ( ! V_52 )
return - V_67 ;
memcpy ( & V_52 -> V_68 , & V_15 -> V_19 -> V_3 -> V_10 , sizeof( V_69 ) ) ;
V_52 -> V_56 = F_32 ( V_15 -> V_56 ) ;
strncpy ( V_52 -> V_27 , V_15 -> V_19 -> V_27 , V_9 ) ;
strncpy ( V_52 -> V_2 , V_15 -> V_19 -> V_3 -> V_4 , V_9 ) ;
V_34 = F_22 ( V_15 -> V_74 , & V_31 , & V_33 ,
V_52 , sizeof( * V_52 ) , 0 , V_59 , 1 ,
V_70 | V_71 ) ;
if ( V_34 ) {
F_29 ( V_15 , V_34 , F_34 ( V_33 . T_1 ) ,
& V_31 , V_52 ) ;
}
F_15 ( V_52 ) ;
return V_34 ;
}
bool F_37 ( struct V_14 * V_15 )
{
if ( V_15 -> V_19 -> V_75 != - 1 &&
V_15 -> V_19 -> V_76 < V_15 -> V_19 -> V_75 )
return true ;
return false ;
}
int F_38 ( struct V_77 * V_78 )
{
if ( ! V_78 -> V_79 )
return - V_80 ;
F_4 ( & V_81 ) ;
F_9 ( & V_78 -> V_82 , & V_83 ) ;
F_10 ( & V_81 ) ;
return 0 ;
}
void F_39 ( struct V_77 * V_78 )
{
F_4 ( & V_81 ) ;
F_14 ( & V_78 -> V_82 ) ;
F_10 ( & V_81 ) ;
}
static struct V_77 * F_40 (
struct V_84 * V_19 )
{
struct V_77 * V_78 ;
F_41 ( & V_81 ) ;
F_2 (ops, &nvmf_transports, entry) {
if ( strcmp ( V_78 -> V_85 , V_19 -> V_86 ) == 0 )
return V_78 ;
}
return NULL ;
}
static int F_42 ( struct V_84 * V_19 ,
const char * V_16 )
{
T_2 args [ V_87 ] ;
char * V_88 , * V_89 , * V_90 ;
int V_91 , V_34 = 0 ;
T_3 V_92 = 0 ;
int V_93 = V_94 ;
V_19 -> V_95 = V_96 ;
V_19 -> V_97 = F_43 () ;
V_19 -> V_98 = V_99 ;
V_88 = V_89 = F_44 ( V_16 , V_8 ) ;
if ( ! V_88 )
return - V_67 ;
while ( ( V_90 = F_45 ( & V_89 , L_18 ) ) != NULL ) {
if ( ! * V_90 )
continue;
V_91 = F_46 ( V_90 , V_100 , args ) ;
V_19 -> V_20 |= V_91 ;
switch ( V_91 ) {
case V_101 :
V_90 = F_47 ( args ) ;
if ( ! V_90 ) {
V_34 = - V_67 ;
goto V_102;
}
V_19 -> V_86 = V_90 ;
break;
case V_103 :
V_90 = F_47 ( args ) ;
if ( ! V_90 ) {
V_34 = - V_67 ;
goto V_102;
}
V_19 -> V_27 = V_90 ;
V_92 = strlen ( V_19 -> V_27 ) ;
if ( V_92 >= V_9 ) {
F_48 ( L_19 ,
V_19 -> V_27 , V_9 ) ;
V_34 = - V_80 ;
goto V_102;
}
V_19 -> V_65 =
! ( strcmp ( V_19 -> V_27 ,
V_104 ) ) ;
if ( V_19 -> V_65 )
V_19 -> V_97 = 0 ;
break;
case V_21 :
V_90 = F_47 ( args ) ;
if ( ! V_90 ) {
V_34 = - V_67 ;
goto V_102;
}
V_19 -> V_22 = V_90 ;
break;
case V_23 :
V_90 = F_47 ( args ) ;
if ( ! V_90 ) {
V_34 = - V_67 ;
goto V_102;
}
V_19 -> V_24 = V_90 ;
break;
case V_105 :
if ( F_49 ( args , & V_91 ) ) {
V_34 = - V_80 ;
goto V_102;
}
if ( V_91 < V_106 ||
V_91 > V_107 ) {
F_48 ( L_20 , V_91 ) ;
V_34 = - V_80 ;
goto V_102;
}
V_19 -> V_95 = V_91 ;
break;
case V_108 :
if ( F_49 ( args , & V_91 ) ) {
V_34 = - V_80 ;
goto V_102;
}
if ( V_91 <= 0 ) {
F_48 ( L_21 , V_91 ) ;
V_34 = - V_80 ;
goto V_102;
}
V_19 -> V_97 = F_50 (unsigned int,
num_online_cpus(), token) ;
break;
case V_109 :
if ( F_49 ( args , & V_91 ) ) {
V_34 = - V_80 ;
goto V_102;
}
if ( V_19 -> V_65 ) {
F_48 ( L_22 ) ;
V_34 = - V_80 ;
goto V_102;
}
if ( V_91 < 0 ) {
F_48 ( L_23 , V_91 ) ;
V_34 = - V_80 ;
goto V_102;
} else if ( V_91 == 0 ) {
F_51 ( L_24 ) ;
}
V_19 -> V_64 = V_91 ;
break;
case V_110 :
if ( F_49 ( args , & V_91 ) ) {
V_34 = - V_80 ;
goto V_102;
}
if ( V_91 < 0 )
F_51 ( L_25 ) ;
V_93 = V_91 ;
break;
case V_111 :
if ( V_19 -> V_3 ) {
F_48 ( L_26 ,
V_19 -> V_3 -> V_4 ) ;
V_34 = - V_112 ;
goto V_102;
}
V_90 = F_47 ( args ) ;
if ( ! V_90 ) {
V_34 = - V_67 ;
goto V_102;
}
V_92 = strlen ( V_90 ) ;
if ( V_92 >= V_9 ) {
F_48 ( L_19 ,
V_90 , V_9 ) ;
F_15 ( V_90 ) ;
V_34 = - V_80 ;
goto V_102;
}
V_19 -> V_3 = F_3 ( V_90 ) ;
F_15 ( V_90 ) ;
if ( ! V_19 -> V_3 ) {
V_34 = - V_67 ;
goto V_102;
}
break;
case V_113 :
if ( F_49 ( args , & V_91 ) ) {
V_34 = - V_80 ;
goto V_102;
}
if ( V_91 <= 0 ) {
F_48 ( L_27 , V_91 ) ;
V_34 = - V_80 ;
goto V_102;
}
V_19 -> V_98 = V_91 ;
break;
case V_25 :
V_90 = F_47 ( args ) ;
if ( ! V_90 ) {
V_34 = - V_67 ;
goto V_102;
}
V_19 -> V_26 = V_90 ;
break;
default:
F_51 ( L_28 ,
V_90 ) ;
V_34 = - V_80 ;
goto V_102;
}
}
if ( V_93 < 0 )
V_19 -> V_75 = - 1 ;
else
V_19 -> V_75 = F_52 ( V_93 ,
V_19 -> V_98 ) ;
if ( ! V_19 -> V_3 ) {
F_5 ( & V_114 -> V_6 ) ;
V_19 -> V_3 = V_114 ;
}
V_102:
if ( ! V_19 -> V_65 && ! V_19 -> V_64 )
V_19 -> V_64 = V_115 ;
F_15 ( V_88 ) ;
return V_34 ;
}
static int F_53 ( struct V_84 * V_19 ,
unsigned int V_116 )
{
if ( ( V_19 -> V_20 & V_116 ) != V_116 ) {
int V_117 ;
for ( V_117 = 0 ; V_117 < F_54 ( V_100 ) ; V_117 ++ ) {
if ( ( V_100 [ V_117 ] . V_91 & V_116 ) &&
! ( V_100 [ V_117 ] . V_91 & V_19 -> V_20 ) ) {
F_51 ( L_29 ,
V_100 [ V_117 ] . V_118 ) ;
}
}
return - V_80 ;
}
return 0 ;
}
static int F_55 ( struct V_84 * V_19 ,
unsigned int V_119 )
{
if ( V_19 -> V_20 & ~ V_119 ) {
int V_117 ;
for ( V_117 = 0 ; V_117 < F_54 ( V_100 ) ; V_117 ++ ) {
if ( V_100 [ V_117 ] . V_91 & ~ V_119 ) {
F_51 ( L_30 ,
V_100 [ V_117 ] . V_118 ) ;
}
}
return - V_80 ;
}
return 0 ;
}
void F_56 ( struct V_84 * V_19 )
{
F_16 ( V_19 -> V_3 ) ;
F_15 ( V_19 -> V_86 ) ;
F_15 ( V_19 -> V_22 ) ;
F_15 ( V_19 -> V_24 ) ;
F_15 ( V_19 -> V_27 ) ;
F_15 ( V_19 -> V_26 ) ;
F_15 ( V_19 ) ;
}
static struct V_14 *
F_57 ( struct V_44 * V_120 , const char * V_16 , T_3 V_121 )
{
struct V_84 * V_19 ;
struct V_77 * V_78 ;
struct V_14 * V_15 ;
int V_34 ;
V_19 = F_33 ( sizeof( * V_19 ) , V_8 ) ;
if ( ! V_19 )
return F_58 ( - V_67 ) ;
V_34 = F_42 ( V_19 , V_16 ) ;
if ( V_34 )
goto V_122;
V_34 = F_53 ( V_19 , V_123 ) ;
if ( V_34 )
goto V_122;
V_19 -> V_20 &= ~ V_123 ;
F_4 ( & V_81 ) ;
V_78 = F_40 ( V_19 ) ;
if ( ! V_78 ) {
F_59 ( L_31 ,
V_19 -> V_86 ) ;
V_34 = - V_80 ;
goto V_7;
}
V_34 = F_53 ( V_19 , V_78 -> V_116 ) ;
if ( V_34 )
goto V_7;
V_34 = F_55 ( V_19 , V_124 |
V_78 -> V_119 | V_78 -> V_116 ) ;
if ( V_34 )
goto V_7;
V_15 = V_78 -> V_79 ( V_120 , V_19 ) ;
if ( F_60 ( V_15 ) ) {
V_34 = F_61 ( V_15 ) ;
goto V_7;
}
F_10 ( & V_81 ) ;
return V_15 ;
V_7:
F_10 ( & V_81 ) ;
V_122:
F_56 ( V_19 ) ;
return F_58 ( V_34 ) ;
}
static T_4 F_62 ( struct V_125 * V_125 , const char T_5 * V_126 ,
T_3 V_121 , T_6 * V_127 )
{
struct V_128 * V_128 = V_125 -> V_129 ;
struct V_14 * V_15 ;
const char * V_16 ;
int V_34 = 0 ;
if ( V_121 > V_130 )
return - V_67 ;
V_16 = F_63 ( V_126 , V_121 ) ;
if ( F_60 ( V_16 ) )
return F_61 ( V_16 ) ;
F_4 ( & V_131 ) ;
if ( V_128 -> V_132 ) {
V_34 = - V_80 ;
goto V_7;
}
V_15 = F_57 ( V_133 , V_16 , V_121 ) ;
if ( F_60 ( V_15 ) ) {
V_34 = F_61 ( V_15 ) ;
goto V_7;
}
V_128 -> V_132 = V_15 ;
V_7:
F_10 ( & V_131 ) ;
F_15 ( V_16 ) ;
return V_34 ? V_34 : V_121 ;
}
static int F_64 ( struct V_128 * V_128 , void * V_132 )
{
struct V_14 * V_15 ;
int V_34 = 0 ;
F_4 ( & V_131 ) ;
V_15 = V_128 -> V_132 ;
if ( ! V_15 ) {
V_34 = - V_80 ;
goto V_7;
}
F_65 ( V_128 , L_32 ,
V_15 -> V_134 , V_15 -> V_56 ) ;
V_7:
F_10 ( & V_131 ) ;
return V_34 ;
}
static int F_66 ( struct V_135 * V_135 , struct V_125 * V_125 )
{
V_125 -> V_129 = NULL ;
return F_67 ( V_125 , F_64 , NULL ) ;
}
static int F_68 ( struct V_135 * V_135 , struct V_125 * V_125 )
{
struct V_128 * V_128 = V_125 -> V_129 ;
struct V_14 * V_15 = V_128 -> V_132 ;
if ( V_15 )
F_69 ( V_15 ) ;
return F_70 ( V_135 , V_125 ) ;
}
static int T_7 F_71 ( void )
{
int V_34 ;
V_114 = F_11 () ;
if ( ! V_114 )
return - V_67 ;
V_136 = F_72 ( V_137 , L_33 ) ;
if ( F_60 ( V_136 ) ) {
F_48 ( L_34 ) ;
V_34 = F_61 ( V_136 ) ;
goto V_138;
}
V_133 =
F_73 ( V_136 , NULL , F_74 ( 0 , 0 ) , NULL , L_35 ) ;
if ( F_60 ( V_133 ) ) {
F_48 ( L_36 ) ;
V_34 = F_61 ( V_133 ) ;
goto V_139;
}
V_34 = F_75 ( & V_140 ) ;
if ( V_34 ) {
F_48 ( L_37 , V_34 ) ;
goto V_141;
}
return 0 ;
V_141:
F_76 ( V_136 , F_74 ( 0 , 0 ) ) ;
V_139:
F_77 ( V_136 ) ;
V_138:
F_16 ( V_114 ) ;
return V_34 ;
}
static void T_8 F_78 ( void )
{
F_79 ( & V_140 ) ;
F_76 ( V_136 , F_74 ( 0 , 0 ) ) ;
F_77 ( V_136 ) ;
F_16 ( V_114 ) ;
F_80 ( sizeof( struct V_58 ) != 64 ) ;
F_80 ( sizeof( struct V_142 ) != 64 ) ;
F_80 ( sizeof( struct V_143 ) != 64 ) ;
F_80 ( sizeof( struct V_51 ) != 1024 ) ;
}
