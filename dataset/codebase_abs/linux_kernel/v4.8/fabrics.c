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
return snprintf ( V_16 , V_17 , L_2 ,
V_15 -> V_18 -> V_19 , V_15 -> V_18 -> V_20 ) ;
}
const char * F_19 ( struct V_14 * V_15 )
{
return V_15 -> V_18 -> V_21 ;
}
int F_20 ( struct V_14 * V_15 , T_1 V_22 , T_1 * V_23 )
{
struct V_24 V_25 ;
struct V_26 V_27 ;
int V_28 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_29 . V_30 = V_31 ;
V_25 . V_29 . V_32 = V_33 ;
V_25 . V_29 . V_34 = F_21 ( V_22 ) ;
V_28 = F_22 ( V_15 -> V_35 , & V_25 , & V_27 , NULL , 0 , 0 ,
V_36 , 0 , 0 ) ;
if ( V_28 >= 0 )
* V_23 = F_23 ( V_27 . V_37 ) ;
if ( F_24 ( V_28 != 0 ) )
F_25 ( V_15 -> V_38 ,
L_3 ,
V_28 > 0 ? V_28 & ~ V_39 : V_28 , V_22 ) ;
return V_28 ;
}
int F_26 ( struct V_14 * V_15 , T_1 V_22 , T_2 * V_23 )
{
struct V_24 V_25 ;
struct V_26 V_27 ;
int V_28 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_29 . V_30 = V_31 ;
V_25 . V_29 . V_32 = V_33 ;
V_25 . V_29 . V_40 = 1 ;
V_25 . V_29 . V_34 = F_21 ( V_22 ) ;
V_28 = F_22 ( V_15 -> V_35 , & V_25 , & V_27 , NULL , 0 , 0 ,
V_36 , 0 , 0 ) ;
if ( V_28 >= 0 )
* V_23 = F_23 ( V_27 . V_37 ) ;
if ( F_24 ( V_28 != 0 ) )
F_25 ( V_15 -> V_38 ,
L_3 ,
V_28 > 0 ? V_28 & ~ V_39 : V_28 , V_22 ) ;
return V_28 ;
}
int F_27 ( struct V_14 * V_15 , T_1 V_22 , T_1 V_23 )
{
struct V_24 V_25 ;
int V_28 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_41 . V_30 = V_31 ;
V_25 . V_41 . V_32 = V_42 ;
V_25 . V_41 . V_40 = 0 ;
V_25 . V_41 . V_34 = F_21 ( V_22 ) ;
V_25 . V_41 . V_43 = F_28 ( V_23 ) ;
V_28 = F_22 ( V_15 -> V_35 , & V_25 , NULL , NULL , 0 , 0 ,
V_36 , 0 , 0 ) ;
if ( F_24 ( V_28 ) )
F_25 ( V_15 -> V_38 ,
L_4 ,
V_28 > 0 ? V_28 & ~ V_39 : V_28 , V_22 ) ;
return V_28 ;
}
static void F_29 ( struct V_14 * V_15 ,
int V_44 , int V_34 , struct V_24 * V_25 ,
struct V_45 * V_46 )
{
int V_47 = V_44 & ( ~ V_39 ) ;
switch ( V_47 ) {
case ( V_48 ) :
if ( V_34 >> 16 ) {
char * V_49 = L_5 ;
switch ( V_34 & 0xffff ) {
case ( F_30 ( struct V_45 , V_50 ) ) :
F_25 ( V_15 -> V_38 ,
L_6 ,
V_49 , V_46 -> V_50 ) ;
break;
case ( F_30 ( struct V_45 , V_2 ) ) :
F_25 ( V_15 -> V_38 ,
L_7 ,
V_49 , V_46 -> V_2 ) ;
break;
case ( F_30 ( struct V_45 , V_21 ) ) :
F_25 ( V_15 -> V_38 ,
L_8 ,
V_49 , V_46 -> V_21 ) ;
break;
default:
F_25 ( V_15 -> V_38 ,
L_9 ,
V_49 , V_34 & 0xffff ) ;
break;
}
} else {
char * V_51 = L_10 ;
switch ( V_34 ) {
case ( F_30 ( struct V_52 , V_53 ) ) :
F_25 ( V_15 -> V_38 ,
L_11 ,
V_51 , V_25 -> V_54 . V_53 ) ;
break;
default:
F_25 ( V_15 -> V_38 ,
L_9 ,
V_51 , V_34 ) ;
}
}
break;
default:
F_25 ( V_15 -> V_38 ,
L_12 ,
V_47 ) ;
break;
}
}
int F_31 ( struct V_14 * V_15 )
{
struct V_24 V_25 ;
struct V_26 V_27 ;
struct V_45 * V_46 ;
int V_28 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_54 . V_30 = V_31 ;
V_25 . V_54 . V_32 = V_55 ;
V_25 . V_54 . V_53 = 0 ;
V_25 . V_54 . V_56 = F_32 ( V_57 - 1 ) ;
V_25 . V_54 . V_58 = V_15 -> V_18 -> V_59 ? 0 :
F_21 ( ( V_15 -> V_58 + V_60 ) * 1000 ) ;
V_46 = F_33 ( sizeof( * V_46 ) , V_8 ) ;
if ( ! V_46 )
return - V_61 ;
memcpy ( & V_46 -> V_62 , & V_15 -> V_18 -> V_3 -> V_10 , sizeof( V_63 ) ) ;
V_46 -> V_50 = F_32 ( 0xffff ) ;
strncpy ( V_46 -> V_21 , V_15 -> V_18 -> V_21 , V_9 ) ;
strncpy ( V_46 -> V_2 , V_15 -> V_18 -> V_3 -> V_4 , V_9 ) ;
V_28 = F_22 ( V_15 -> V_35 , & V_25 , & V_27 ,
V_46 , sizeof( * V_46 ) , 0 , V_36 , 1 ,
V_64 | V_65 ) ;
if ( V_28 ) {
F_29 ( V_15 , V_28 , F_34 ( V_27 . V_66 ) ,
& V_25 , V_46 ) ;
goto V_67;
}
V_15 -> V_50 = F_35 ( V_27 . V_68 ) ;
V_67:
F_15 ( V_46 ) ;
return V_28 ;
}
int F_36 ( struct V_14 * V_15 , T_3 V_53 )
{
struct V_24 V_25 ;
struct V_45 * V_46 ;
struct V_26 V_27 ;
int V_28 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_54 . V_30 = V_31 ;
V_25 . V_54 . V_32 = V_55 ;
V_25 . V_54 . V_53 = F_32 ( V_53 ) ;
V_25 . V_54 . V_56 = F_32 ( V_15 -> V_56 ) ;
V_46 = F_33 ( sizeof( * V_46 ) , V_8 ) ;
if ( ! V_46 )
return - V_61 ;
memcpy ( & V_46 -> V_62 , & V_15 -> V_18 -> V_3 -> V_10 , sizeof( V_63 ) ) ;
V_46 -> V_50 = F_32 ( V_15 -> V_50 ) ;
strncpy ( V_46 -> V_21 , V_15 -> V_18 -> V_21 , V_9 ) ;
strncpy ( V_46 -> V_2 , V_15 -> V_18 -> V_3 -> V_4 , V_9 ) ;
V_28 = F_22 ( V_15 -> V_69 , & V_25 , & V_27 ,
V_46 , sizeof( * V_46 ) , 0 , V_53 , 1 ,
V_64 | V_65 ) ;
if ( V_28 ) {
F_29 ( V_15 , V_28 , F_34 ( V_27 . V_66 ) ,
& V_25 , V_46 ) ;
}
F_15 ( V_46 ) ;
return V_28 ;
}
void F_37 ( struct V_70 * V_71 )
{
F_4 ( & V_72 ) ;
F_9 ( & V_71 -> V_73 , & V_74 ) ;
F_10 ( & V_72 ) ;
}
void F_38 ( struct V_70 * V_71 )
{
F_4 ( & V_72 ) ;
F_14 ( & V_71 -> V_73 ) ;
F_10 ( & V_72 ) ;
}
static struct V_70 * F_39 (
struct V_75 * V_18 )
{
struct V_70 * V_71 ;
F_40 ( & V_72 ) ;
F_2 (ops, &nvmf_transports, entry) {
if ( strcmp ( V_71 -> V_76 , V_18 -> V_77 ) == 0 )
return V_71 ;
}
return NULL ;
}
static int F_41 ( struct V_75 * V_18 ,
const char * V_16 )
{
T_4 args [ V_78 ] ;
char * V_79 , * V_80 , * V_81 ;
int V_82 , V_28 = 0 ;
T_5 V_83 = 0 ;
V_18 -> V_84 = V_85 ;
V_18 -> V_86 = F_42 () ;
V_18 -> V_87 = V_88 ;
V_79 = V_80 = F_43 ( V_16 , V_8 ) ;
if ( ! V_79 )
return - V_61 ;
while ( ( V_81 = F_44 ( & V_80 , L_13 ) ) != NULL ) {
if ( ! * V_81 )
continue;
V_82 = F_45 ( V_81 , V_89 , args ) ;
V_18 -> V_90 |= V_82 ;
switch ( V_82 ) {
case V_91 :
V_81 = F_46 ( args ) ;
if ( ! V_81 ) {
V_28 = - V_61 ;
goto V_92;
}
V_18 -> V_77 = V_81 ;
break;
case V_93 :
V_81 = F_46 ( args ) ;
if ( ! V_81 ) {
V_28 = - V_61 ;
goto V_92;
}
V_18 -> V_21 = V_81 ;
V_83 = strlen ( V_18 -> V_21 ) ;
if ( V_83 >= V_9 ) {
F_47 ( L_14 ,
V_18 -> V_21 , V_9 ) ;
V_28 = - V_94 ;
goto V_92;
}
V_18 -> V_59 =
! ( strcmp ( V_18 -> V_21 ,
V_95 ) ) ;
if ( V_18 -> V_59 )
V_18 -> V_86 = 0 ;
break;
case V_96 :
V_81 = F_46 ( args ) ;
if ( ! V_81 ) {
V_28 = - V_61 ;
goto V_92;
}
V_18 -> V_19 = V_81 ;
break;
case V_97 :
V_81 = F_46 ( args ) ;
if ( ! V_81 ) {
V_28 = - V_61 ;
goto V_92;
}
V_18 -> V_20 = V_81 ;
break;
case V_98 :
if ( F_48 ( args , & V_82 ) ) {
V_28 = - V_94 ;
goto V_92;
}
if ( V_82 < V_99 ||
V_82 > V_100 ) {
F_47 ( L_15 , V_82 ) ;
V_28 = - V_94 ;
goto V_92;
}
V_18 -> V_84 = V_82 ;
break;
case V_101 :
if ( F_48 ( args , & V_82 ) ) {
V_28 = - V_94 ;
goto V_92;
}
if ( V_82 <= 0 ) {
F_47 ( L_16 , V_82 ) ;
V_28 = - V_94 ;
goto V_92;
}
V_18 -> V_86 = F_49 (unsigned int,
num_online_cpus(), token) ;
break;
case V_102 :
if ( F_48 ( args , & V_82 ) ) {
V_28 = - V_94 ;
goto V_92;
}
if ( V_18 -> V_59 ) {
F_47 ( L_17 ) ;
V_28 = - V_94 ;
goto V_92;
}
if ( V_82 < 0 ) {
F_47 ( L_18 , V_82 ) ;
V_28 = - V_94 ;
goto V_92;
} else if ( V_82 == 0 ) {
F_50 ( L_19 ) ;
}
V_18 -> V_58 = V_82 ;
break;
case V_103 :
if ( V_18 -> V_3 ) {
F_47 ( L_20 ,
V_18 -> V_3 -> V_4 ) ;
V_28 = - V_104 ;
goto V_92;
}
V_81 = F_46 ( args ) ;
if ( ! V_81 ) {
V_28 = - V_61 ;
goto V_92;
}
V_83 = strlen ( V_81 ) ;
if ( V_83 >= V_9 ) {
F_47 ( L_14 ,
V_81 , V_9 ) ;
V_28 = - V_94 ;
goto V_92;
}
V_18 -> V_3 = F_3 ( V_81 ) ;
if ( ! V_18 -> V_3 ) {
V_28 = - V_61 ;
goto V_92;
}
break;
case V_105 :
if ( F_48 ( args , & V_82 ) ) {
V_28 = - V_94 ;
goto V_92;
}
if ( V_82 <= 0 ) {
F_47 ( L_21 , V_82 ) ;
V_28 = - V_94 ;
goto V_92;
}
V_18 -> V_87 = V_82 ;
break;
default:
F_50 ( L_22 ,
V_81 ) ;
V_28 = - V_94 ;
goto V_92;
}
}
if ( ! V_18 -> V_3 ) {
F_5 ( & V_106 -> V_6 ) ;
V_18 -> V_3 = V_106 ;
}
V_92:
if ( ! V_18 -> V_59 && ! V_18 -> V_58 )
V_18 -> V_58 = V_107 ;
F_15 ( V_79 ) ;
return V_28 ;
}
static int F_51 ( struct V_75 * V_18 ,
unsigned int V_108 )
{
if ( ( V_18 -> V_90 & V_108 ) != V_108 ) {
int V_109 ;
for ( V_109 = 0 ; V_109 < F_52 ( V_89 ) ; V_109 ++ ) {
if ( ( V_89 [ V_109 ] . V_82 & V_108 ) &&
! ( V_89 [ V_109 ] . V_82 & V_18 -> V_90 ) ) {
F_50 ( L_23 ,
V_89 [ V_109 ] . V_110 ) ;
}
}
return - V_94 ;
}
return 0 ;
}
static int F_53 ( struct V_75 * V_18 ,
unsigned int V_111 )
{
if ( V_18 -> V_90 & ~ V_111 ) {
int V_109 ;
for ( V_109 = 0 ; V_109 < F_52 ( V_89 ) ; V_109 ++ ) {
if ( V_89 [ V_109 ] . V_82 & ~ V_111 ) {
F_50 ( L_24 ,
V_89 [ V_109 ] . V_110 ) ;
}
}
return - V_94 ;
}
return 0 ;
}
void F_54 ( struct V_75 * V_18 )
{
F_16 ( V_18 -> V_3 ) ;
F_15 ( V_18 -> V_77 ) ;
F_15 ( V_18 -> V_19 ) ;
F_15 ( V_18 -> V_20 ) ;
F_15 ( V_18 -> V_21 ) ;
F_15 ( V_18 ) ;
}
static struct V_14 *
F_55 ( struct V_38 * V_112 , const char * V_16 , T_5 V_113 )
{
struct V_75 * V_18 ;
struct V_70 * V_71 ;
struct V_14 * V_15 ;
int V_28 ;
V_18 = F_33 ( sizeof( * V_18 ) , V_8 ) ;
if ( ! V_18 )
return F_56 ( - V_61 ) ;
V_28 = F_41 ( V_18 , V_16 ) ;
if ( V_28 )
goto V_114;
V_28 = F_51 ( V_18 , V_115 ) ;
if ( V_28 )
goto V_114;
V_18 -> V_90 &= ~ V_115 ;
F_4 ( & V_72 ) ;
V_71 = F_39 ( V_18 ) ;
if ( ! V_71 ) {
F_57 ( L_25 ,
V_18 -> V_77 ) ;
V_28 = - V_94 ;
goto V_7;
}
V_28 = F_51 ( V_18 , V_71 -> V_108 ) ;
if ( V_28 )
goto V_7;
V_28 = F_53 ( V_18 , V_116 |
V_71 -> V_111 | V_71 -> V_108 ) ;
if ( V_28 )
goto V_7;
V_15 = V_71 -> V_117 ( V_112 , V_18 ) ;
if ( F_58 ( V_15 ) ) {
V_28 = F_59 ( V_15 ) ;
goto V_7;
}
F_10 ( & V_72 ) ;
return V_15 ;
V_7:
F_10 ( & V_72 ) ;
V_114:
F_16 ( V_18 -> V_3 ) ;
F_15 ( V_18 ) ;
return F_56 ( V_28 ) ;
}
static T_6 F_60 ( struct V_118 * V_118 , const char T_7 * V_119 ,
T_5 V_113 , T_8 * V_120 )
{
struct V_121 * V_121 = V_118 -> V_122 ;
struct V_14 * V_15 ;
const char * V_16 ;
int V_28 = 0 ;
if ( V_113 > V_123 )
return - V_61 ;
V_16 = F_61 ( V_119 , V_113 ) ;
if ( F_58 ( V_16 ) )
return F_59 ( V_16 ) ;
F_4 ( & V_124 ) ;
if ( V_121 -> V_125 ) {
V_28 = - V_94 ;
goto V_7;
}
V_15 = F_55 ( V_126 , V_16 , V_113 ) ;
if ( F_58 ( V_15 ) ) {
V_28 = F_59 ( V_15 ) ;
goto V_7;
}
V_121 -> V_125 = V_15 ;
V_7:
F_10 ( & V_124 ) ;
F_15 ( V_16 ) ;
return V_28 ? V_28 : V_113 ;
}
static int F_62 ( struct V_121 * V_121 , void * V_125 )
{
struct V_14 * V_15 ;
int V_28 = 0 ;
F_4 ( & V_124 ) ;
V_15 = V_121 -> V_125 ;
if ( ! V_15 ) {
V_28 = - V_94 ;
goto V_7;
}
F_63 ( V_121 , L_26 ,
V_15 -> V_127 , V_15 -> V_50 ) ;
V_7:
F_10 ( & V_124 ) ;
return V_28 ;
}
static int F_64 ( struct V_128 * V_128 , struct V_118 * V_118 )
{
V_118 -> V_122 = NULL ;
return F_65 ( V_118 , F_62 , NULL ) ;
}
static int F_66 ( struct V_128 * V_128 , struct V_118 * V_118 )
{
struct V_121 * V_121 = V_118 -> V_122 ;
struct V_14 * V_15 = V_121 -> V_125 ;
if ( V_15 )
F_67 ( V_15 ) ;
return F_68 ( V_128 , V_118 ) ;
}
static int T_9 F_69 ( void )
{
int V_28 ;
V_106 = F_11 () ;
if ( ! V_106 )
return - V_61 ;
V_129 = F_70 ( V_130 , L_27 ) ;
if ( F_58 ( V_129 ) ) {
F_47 ( L_28 ) ;
V_28 = F_59 ( V_129 ) ;
goto V_131;
}
V_126 =
F_71 ( V_129 , NULL , F_72 ( 0 , 0 ) , NULL , L_29 ) ;
if ( F_58 ( V_126 ) ) {
F_47 ( L_30 ) ;
V_28 = F_59 ( V_126 ) ;
goto V_132;
}
V_28 = F_73 ( & V_133 ) ;
if ( V_28 ) {
F_47 ( L_31 , V_28 ) ;
goto V_134;
}
return 0 ;
V_134:
F_74 ( V_129 , F_72 ( 0 , 0 ) ) ;
V_132:
F_75 ( V_129 ) ;
V_131:
F_16 ( V_106 ) ;
return V_28 ;
}
static void T_10 F_76 ( void )
{
F_77 ( & V_133 ) ;
F_74 ( V_129 , F_72 ( 0 , 0 ) ) ;
F_75 ( V_129 ) ;
F_16 ( V_106 ) ;
F_78 ( sizeof( struct V_52 ) != 64 ) ;
F_78 ( sizeof( struct V_135 ) != 64 ) ;
F_78 ( sizeof( struct V_136 ) != 64 ) ;
F_78 ( sizeof( struct V_45 ) != 1024 ) ;
}
