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
struct V_32 V_33 ;
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
int F_26 ( struct V_14 * V_15 , T_1 V_28 , T_2 * V_29 )
{
struct V_30 V_31 ;
struct V_32 V_33 ;
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
struct V_32 V_33 ;
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
F_29 ( V_15 , V_34 , F_34 ( V_33 . V_72 ) ,
& V_31 , V_52 ) ;
goto V_73;
}
V_15 -> V_56 = F_35 ( V_33 . V_74 ) ;
V_73:
F_15 ( V_52 ) ;
return V_34 ;
}
int F_36 ( struct V_14 * V_15 , T_3 V_59 )
{
struct V_30 V_31 ;
struct V_51 * V_52 ;
struct V_32 V_33 ;
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
V_34 = F_22 ( V_15 -> V_75 , & V_31 , & V_33 ,
V_52 , sizeof( * V_52 ) , 0 , V_59 , 1 ,
V_70 | V_71 ) ;
if ( V_34 ) {
F_29 ( V_15 , V_34 , F_34 ( V_33 . V_72 ) ,
& V_31 , V_52 ) ;
}
F_15 ( V_52 ) ;
return V_34 ;
}
void F_37 ( struct V_76 * V_77 )
{
F_4 ( & V_78 ) ;
F_9 ( & V_77 -> V_79 , & V_80 ) ;
F_10 ( & V_78 ) ;
}
void F_38 ( struct V_76 * V_77 )
{
F_4 ( & V_78 ) ;
F_14 ( & V_77 -> V_79 ) ;
F_10 ( & V_78 ) ;
}
static struct V_76 * F_39 (
struct V_81 * V_19 )
{
struct V_76 * V_77 ;
F_40 ( & V_78 ) ;
F_2 (ops, &nvmf_transports, entry) {
if ( strcmp ( V_77 -> V_82 , V_19 -> V_83 ) == 0 )
return V_77 ;
}
return NULL ;
}
static int F_41 ( struct V_81 * V_19 ,
const char * V_16 )
{
T_4 args [ V_84 ] ;
char * V_85 , * V_86 , * V_87 ;
int V_88 , V_34 = 0 ;
T_5 V_89 = 0 ;
V_19 -> V_90 = V_91 ;
V_19 -> V_92 = F_42 () ;
V_19 -> V_93 = V_94 ;
V_85 = V_86 = F_43 ( V_16 , V_8 ) ;
if ( ! V_85 )
return - V_67 ;
while ( ( V_87 = F_44 ( & V_86 , L_18 ) ) != NULL ) {
if ( ! * V_87 )
continue;
V_88 = F_45 ( V_87 , V_95 , args ) ;
V_19 -> V_20 |= V_88 ;
switch ( V_88 ) {
case V_96 :
V_87 = F_46 ( args ) ;
if ( ! V_87 ) {
V_34 = - V_67 ;
goto V_97;
}
V_19 -> V_83 = V_87 ;
break;
case V_98 :
V_87 = F_46 ( args ) ;
if ( ! V_87 ) {
V_34 = - V_67 ;
goto V_97;
}
V_19 -> V_27 = V_87 ;
V_89 = strlen ( V_19 -> V_27 ) ;
if ( V_89 >= V_9 ) {
F_47 ( L_19 ,
V_19 -> V_27 , V_9 ) ;
V_34 = - V_99 ;
goto V_97;
}
V_19 -> V_65 =
! ( strcmp ( V_19 -> V_27 ,
V_100 ) ) ;
if ( V_19 -> V_65 )
V_19 -> V_92 = 0 ;
break;
case V_21 :
V_87 = F_46 ( args ) ;
if ( ! V_87 ) {
V_34 = - V_67 ;
goto V_97;
}
V_19 -> V_22 = V_87 ;
break;
case V_23 :
V_87 = F_46 ( args ) ;
if ( ! V_87 ) {
V_34 = - V_67 ;
goto V_97;
}
V_19 -> V_24 = V_87 ;
break;
case V_101 :
if ( F_48 ( args , & V_88 ) ) {
V_34 = - V_99 ;
goto V_97;
}
if ( V_88 < V_102 ||
V_88 > V_103 ) {
F_47 ( L_20 , V_88 ) ;
V_34 = - V_99 ;
goto V_97;
}
V_19 -> V_90 = V_88 ;
break;
case V_104 :
if ( F_48 ( args , & V_88 ) ) {
V_34 = - V_99 ;
goto V_97;
}
if ( V_88 <= 0 ) {
F_47 ( L_21 , V_88 ) ;
V_34 = - V_99 ;
goto V_97;
}
V_19 -> V_92 = F_49 (unsigned int,
num_online_cpus(), token) ;
break;
case V_105 :
if ( F_48 ( args , & V_88 ) ) {
V_34 = - V_99 ;
goto V_97;
}
if ( V_19 -> V_65 ) {
F_47 ( L_22 ) ;
V_34 = - V_99 ;
goto V_97;
}
if ( V_88 < 0 ) {
F_47 ( L_23 , V_88 ) ;
V_34 = - V_99 ;
goto V_97;
} else if ( V_88 == 0 ) {
F_50 ( L_24 ) ;
}
V_19 -> V_64 = V_88 ;
break;
case V_106 :
if ( V_19 -> V_3 ) {
F_47 ( L_25 ,
V_19 -> V_3 -> V_4 ) ;
V_34 = - V_107 ;
goto V_97;
}
V_87 = F_46 ( args ) ;
if ( ! V_87 ) {
V_34 = - V_67 ;
goto V_97;
}
V_89 = strlen ( V_87 ) ;
if ( V_89 >= V_9 ) {
F_47 ( L_19 ,
V_87 , V_9 ) ;
V_34 = - V_99 ;
goto V_97;
}
V_19 -> V_3 = F_3 ( V_87 ) ;
if ( ! V_19 -> V_3 ) {
V_34 = - V_67 ;
goto V_97;
}
break;
case V_108 :
if ( F_48 ( args , & V_88 ) ) {
V_34 = - V_99 ;
goto V_97;
}
if ( V_88 <= 0 ) {
F_47 ( L_26 , V_88 ) ;
V_34 = - V_99 ;
goto V_97;
}
V_19 -> V_93 = V_88 ;
break;
case V_25 :
V_87 = F_46 ( args ) ;
if ( ! V_87 ) {
V_34 = - V_67 ;
goto V_97;
}
V_19 -> V_26 = V_87 ;
break;
default:
F_50 ( L_27 ,
V_87 ) ;
V_34 = - V_99 ;
goto V_97;
}
}
if ( ! V_19 -> V_3 ) {
F_5 ( & V_109 -> V_6 ) ;
V_19 -> V_3 = V_109 ;
}
V_97:
if ( ! V_19 -> V_65 && ! V_19 -> V_64 )
V_19 -> V_64 = V_110 ;
F_15 ( V_85 ) ;
return V_34 ;
}
static int F_51 ( struct V_81 * V_19 ,
unsigned int V_111 )
{
if ( ( V_19 -> V_20 & V_111 ) != V_111 ) {
int V_112 ;
for ( V_112 = 0 ; V_112 < F_52 ( V_95 ) ; V_112 ++ ) {
if ( ( V_95 [ V_112 ] . V_88 & V_111 ) &&
! ( V_95 [ V_112 ] . V_88 & V_19 -> V_20 ) ) {
F_50 ( L_28 ,
V_95 [ V_112 ] . V_113 ) ;
}
}
return - V_99 ;
}
return 0 ;
}
static int F_53 ( struct V_81 * V_19 ,
unsigned int V_114 )
{
if ( V_19 -> V_20 & ~ V_114 ) {
int V_112 ;
for ( V_112 = 0 ; V_112 < F_52 ( V_95 ) ; V_112 ++ ) {
if ( V_95 [ V_112 ] . V_88 & ~ V_114 ) {
F_50 ( L_29 ,
V_95 [ V_112 ] . V_113 ) ;
}
}
return - V_99 ;
}
return 0 ;
}
void F_54 ( struct V_81 * V_19 )
{
F_16 ( V_19 -> V_3 ) ;
F_15 ( V_19 -> V_83 ) ;
F_15 ( V_19 -> V_22 ) ;
F_15 ( V_19 -> V_24 ) ;
F_15 ( V_19 -> V_27 ) ;
F_15 ( V_19 -> V_26 ) ;
F_15 ( V_19 ) ;
}
static struct V_14 *
F_55 ( struct V_44 * V_115 , const char * V_16 , T_5 V_116 )
{
struct V_81 * V_19 ;
struct V_76 * V_77 ;
struct V_14 * V_15 ;
int V_34 ;
V_19 = F_33 ( sizeof( * V_19 ) , V_8 ) ;
if ( ! V_19 )
return F_56 ( - V_67 ) ;
V_34 = F_41 ( V_19 , V_16 ) ;
if ( V_34 )
goto V_117;
V_34 = F_51 ( V_19 , V_118 ) ;
if ( V_34 )
goto V_117;
V_19 -> V_20 &= ~ V_118 ;
F_4 ( & V_78 ) ;
V_77 = F_39 ( V_19 ) ;
if ( ! V_77 ) {
F_57 ( L_30 ,
V_19 -> V_83 ) ;
V_34 = - V_99 ;
goto V_7;
}
V_34 = F_51 ( V_19 , V_77 -> V_111 ) ;
if ( V_34 )
goto V_7;
V_34 = F_53 ( V_19 , V_119 |
V_77 -> V_114 | V_77 -> V_111 ) ;
if ( V_34 )
goto V_7;
V_15 = V_77 -> V_120 ( V_115 , V_19 ) ;
if ( F_58 ( V_15 ) ) {
V_34 = F_59 ( V_15 ) ;
goto V_7;
}
F_10 ( & V_78 ) ;
return V_15 ;
V_7:
F_10 ( & V_78 ) ;
V_117:
F_16 ( V_19 -> V_3 ) ;
F_15 ( V_19 ) ;
return F_56 ( V_34 ) ;
}
static T_6 F_60 ( struct V_121 * V_121 , const char T_7 * V_122 ,
T_5 V_116 , T_8 * V_123 )
{
struct V_124 * V_124 = V_121 -> V_125 ;
struct V_14 * V_15 ;
const char * V_16 ;
int V_34 = 0 ;
if ( V_116 > V_126 )
return - V_67 ;
V_16 = F_61 ( V_122 , V_116 ) ;
if ( F_58 ( V_16 ) )
return F_59 ( V_16 ) ;
F_4 ( & V_127 ) ;
if ( V_124 -> V_128 ) {
V_34 = - V_99 ;
goto V_7;
}
V_15 = F_55 ( V_129 , V_16 , V_116 ) ;
if ( F_58 ( V_15 ) ) {
V_34 = F_59 ( V_15 ) ;
goto V_7;
}
V_124 -> V_128 = V_15 ;
V_7:
F_10 ( & V_127 ) ;
F_15 ( V_16 ) ;
return V_34 ? V_34 : V_116 ;
}
static int F_62 ( struct V_124 * V_124 , void * V_128 )
{
struct V_14 * V_15 ;
int V_34 = 0 ;
F_4 ( & V_127 ) ;
V_15 = V_124 -> V_128 ;
if ( ! V_15 ) {
V_34 = - V_99 ;
goto V_7;
}
F_63 ( V_124 , L_31 ,
V_15 -> V_130 , V_15 -> V_56 ) ;
V_7:
F_10 ( & V_127 ) ;
return V_34 ;
}
static int F_64 ( struct V_131 * V_131 , struct V_121 * V_121 )
{
V_121 -> V_125 = NULL ;
return F_65 ( V_121 , F_62 , NULL ) ;
}
static int F_66 ( struct V_131 * V_131 , struct V_121 * V_121 )
{
struct V_124 * V_124 = V_121 -> V_125 ;
struct V_14 * V_15 = V_124 -> V_128 ;
if ( V_15 )
F_67 ( V_15 ) ;
return F_68 ( V_131 , V_121 ) ;
}
static int T_9 F_69 ( void )
{
int V_34 ;
V_109 = F_11 () ;
if ( ! V_109 )
return - V_67 ;
V_132 = F_70 ( V_133 , L_32 ) ;
if ( F_58 ( V_132 ) ) {
F_47 ( L_33 ) ;
V_34 = F_59 ( V_132 ) ;
goto V_134;
}
V_129 =
F_71 ( V_132 , NULL , F_72 ( 0 , 0 ) , NULL , L_34 ) ;
if ( F_58 ( V_129 ) ) {
F_47 ( L_35 ) ;
V_34 = F_59 ( V_129 ) ;
goto V_135;
}
V_34 = F_73 ( & V_136 ) ;
if ( V_34 ) {
F_47 ( L_36 , V_34 ) ;
goto V_137;
}
return 0 ;
V_137:
F_74 ( V_132 , F_72 ( 0 , 0 ) ) ;
V_135:
F_75 ( V_132 ) ;
V_134:
F_16 ( V_109 ) ;
return V_34 ;
}
static void T_10 F_76 ( void )
{
F_77 ( & V_136 ) ;
F_74 ( V_132 , F_72 ( 0 , 0 ) ) ;
F_75 ( V_132 ) ;
F_16 ( V_109 ) ;
F_78 ( sizeof( struct V_58 ) != 64 ) ;
F_78 ( sizeof( struct V_138 ) != 64 ) ;
F_78 ( sizeof( struct V_139 ) != 64 ) ;
F_78 ( sizeof( struct V_51 ) != 1024 ) ;
}
