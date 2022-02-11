static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static struct V_1 * F_3 ( const struct V_2 * V_3 )
{
struct V_1 * V_5 = F_4 ( V_3 -> V_4 ) ;
return F_5 ( V_3 ) ? V_5 : NULL ;
}
static int F_6 ( struct V_2 * V_6 ,
const unsigned char * V_7 )
{
struct V_8 V_9 ;
memcpy ( V_9 . V_10 , V_7 , V_6 -> V_11 ) ;
V_9 . V_12 = V_6 -> type ;
return F_7 ( V_6 , & V_9 ) ;
}
static int F_8 ( struct V_1 * V_5 )
{
return F_6 ( V_5 -> V_3 , V_5 -> V_13 . V_7 ) ;
}
static int F_9 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
return F_6 ( V_5 -> V_3 , V_14 -> V_3 -> V_7 ) ;
}
int F_10 ( struct V_14 * V_14 , struct V_1 * V_5 )
{
return F_9 ( V_14 , V_5 ) ;
}
void F_11 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
F_9 ( V_14 , V_5 ) ;
}
static void F_12 ( struct V_1 * V_5 )
{
V_5 -> V_15 = V_5 -> V_16 . V_17 ? V_5 -> V_16 . V_15 :
V_5 -> V_18 . V_15 ;
}
static struct V_19 * F_13 ( struct V_14 * V_14 ,
const char * V_20 )
{
struct V_19 * V_21 ;
F_14 (option, &team->option_list, list) {
if ( strcmp ( V_21 -> V_22 , V_20 ) == 0 )
return V_21 ;
}
return NULL ;
}
static void F_15 ( struct V_23 * V_24 )
{
F_16 ( & V_24 -> V_25 ) ;
F_17 ( V_24 ) ;
}
static void F_18 ( struct V_14 * V_14 ,
struct V_19 * V_21 )
{
struct V_23 * V_24 , * V_26 ;
F_19 (opt_inst, tmp, &team->option_inst_list, list) {
if ( V_24 -> V_21 == V_21 )
F_15 ( V_24 ) ;
}
}
static int F_20 ( struct V_14 * V_14 , struct V_19 * V_21 ,
struct V_1 * V_5 )
{
struct V_23 * V_24 ;
unsigned int V_27 ;
unsigned int V_28 ;
int V_29 ;
V_27 = V_21 -> V_27 ;
if ( ! V_27 )
V_27 = 1 ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ ) {
V_24 = F_21 ( sizeof( * V_24 ) , V_30 ) ;
if ( ! V_24 )
return - V_31 ;
V_24 -> V_21 = V_21 ;
V_24 -> V_32 . V_5 = V_5 ;
V_24 -> V_32 . V_33 = V_28 ;
V_24 -> V_34 = true ;
V_24 -> V_35 = false ;
F_22 ( & V_24 -> V_25 , & V_14 -> V_36 ) ;
if ( V_21 -> V_37 ) {
V_29 = V_21 -> V_37 ( V_14 , & V_24 -> V_32 ) ;
if ( V_29 )
return V_29 ;
}
}
return 0 ;
}
static int F_23 ( struct V_14 * V_14 ,
struct V_19 * V_21 )
{
int V_29 ;
if ( ! V_21 -> V_38 ) {
V_29 = F_20 ( V_14 , V_21 , NULL ) ;
if ( V_29 )
goto V_39;
}
return 0 ;
V_39:
F_18 ( V_14 , V_21 ) ;
return V_29 ;
}
static void F_24 ( struct V_14 * V_14 ,
struct V_19 * V_21 )
{
struct V_23 * V_24 ;
F_14 (opt_inst, &team->option_inst_list, list) {
if ( V_24 -> V_21 == V_21 ) {
V_24 -> V_34 = true ;
V_24 -> V_35 = true ;
}
}
}
static void F_25 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
struct V_23 * V_24 , * V_26 ;
F_19 (opt_inst, tmp, &team->option_inst_list, list) {
if ( V_24 -> V_21 -> V_38 &&
V_24 -> V_32 . V_5 == V_5 )
F_15 ( V_24 ) ;
}
}
static int F_26 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
struct V_19 * V_21 ;
int V_29 ;
F_14 (option, &team->option_list, list) {
if ( ! V_21 -> V_38 )
continue;
V_29 = F_20 ( V_14 , V_21 , V_5 ) ;
if ( V_29 )
goto V_40;
}
return 0 ;
V_40:
F_25 ( V_14 , V_5 ) ;
return V_29 ;
}
static void F_27 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
struct V_23 * V_24 ;
F_14 (opt_inst, &team->option_inst_list, list) {
if ( V_24 -> V_32 . V_5 == V_5 ) {
V_24 -> V_34 = true ;
V_24 -> V_35 = true ;
}
}
}
static int F_28 ( struct V_14 * V_14 ,
const struct V_19 * V_21 ,
T_1 V_41 )
{
int V_28 ;
struct V_19 * * V_42 ;
int V_29 ;
V_42 = F_29 ( sizeof( struct V_19 * ) * V_41 ,
V_30 ) ;
if ( ! V_42 )
return - V_31 ;
for ( V_28 = 0 ; V_28 < V_41 ; V_28 ++ , V_21 ++ ) {
if ( F_13 ( V_14 , V_21 -> V_22 ) ) {
V_29 = - V_43 ;
goto V_44;
}
V_42 [ V_28 ] = F_30 ( V_21 , sizeof( * V_21 ) , V_30 ) ;
if ( ! V_42 [ V_28 ] ) {
V_29 = - V_31 ;
goto V_44;
}
}
for ( V_28 = 0 ; V_28 < V_41 ; V_28 ++ ) {
V_29 = F_23 ( V_14 , V_42 [ V_28 ] ) ;
if ( V_29 )
goto V_45;
F_22 ( & V_42 [ V_28 ] -> V_25 , & V_14 -> V_46 ) ;
}
F_17 ( V_42 ) ;
return 0 ;
V_45:
for ( V_28 -- ; V_28 >= 0 ; V_28 -- )
F_18 ( V_14 , V_42 [ V_28 ] ) ;
V_28 = V_41 - 1 ;
V_44:
for ( V_28 -- ; V_28 >= 0 ; V_28 -- )
F_17 ( V_42 [ V_28 ] ) ;
F_17 ( V_42 ) ;
return V_29 ;
}
static void F_31 ( struct V_14 * V_14 ,
const struct V_19 * V_21 ,
T_1 V_41 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_41 ; V_28 ++ , V_21 ++ ) {
struct V_19 * V_47 ;
V_47 = F_13 ( V_14 , V_21 -> V_22 ) ;
if ( V_47 )
F_24 ( V_14 , V_47 ) ;
}
}
static void F_32 ( struct V_14 * V_14 ,
const struct V_19 * V_21 ,
T_1 V_41 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_41 ; V_28 ++ , V_21 ++ ) {
struct V_19 * V_47 ;
V_47 = F_13 ( V_14 , V_21 -> V_22 ) ;
if ( V_47 ) {
F_18 ( V_14 , V_47 ) ;
F_16 ( & V_47 -> V_25 ) ;
F_17 ( V_47 ) ;
}
}
}
int F_33 ( struct V_14 * V_14 ,
const struct V_19 * V_21 ,
T_1 V_41 )
{
int V_29 ;
V_29 = F_28 ( V_14 , V_21 , V_41 ) ;
if ( V_29 )
return V_29 ;
F_34 ( V_14 ) ;
return 0 ;
}
void F_35 ( struct V_14 * V_14 ,
const struct V_19 * V_21 ,
T_1 V_41 )
{
F_31 ( V_14 , V_21 , V_41 ) ;
F_34 ( V_14 ) ;
F_32 ( V_14 , V_21 , V_41 ) ;
}
static int F_36 ( struct V_14 * V_14 ,
struct V_23 * V_24 ,
struct V_48 * V_49 )
{
if ( ! V_24 -> V_21 -> V_50 )
return - V_51 ;
return V_24 -> V_21 -> V_50 ( V_14 , V_49 ) ;
}
static int F_37 ( struct V_14 * V_14 ,
struct V_23 * V_24 ,
struct V_48 * V_49 )
{
if ( ! V_24 -> V_21 -> V_52 )
return - V_51 ;
return V_24 -> V_21 -> V_52 ( V_14 , V_49 ) ;
}
void F_38 ( struct V_53 * V_54 )
{
struct V_23 * V_24 ;
V_24 = F_39 ( V_54 , struct V_23 , V_32 ) ;
V_24 -> V_34 = true ;
}
void F_40 ( struct V_14 * V_14 )
{
F_34 ( V_14 ) ;
}
static struct V_55 * F_41 ( const char * V_56 )
{
struct V_55 * V_57 ;
F_14 (mitem, &mode_list, list) {
if ( strcmp ( V_57 -> V_58 -> V_56 , V_56 ) == 0 )
return V_57 ;
}
return NULL ;
}
static bool F_42 ( const char * V_22 )
{
while ( * V_22 != '\0' ) {
if ( ! isalpha ( * V_22 ) && ! isdigit ( * V_22 ) && * V_22 != '_' )
return false ;
V_22 ++ ;
}
return true ;
}
int F_43 ( const struct V_59 * V_58 )
{
int V_29 = 0 ;
struct V_55 * V_57 ;
if ( ! F_42 ( V_58 -> V_56 ) ||
V_58 -> V_60 > V_61 )
return - V_62 ;
V_57 = F_21 ( sizeof( * V_57 ) , V_30 ) ;
if ( ! V_57 )
return - V_31 ;
F_44 ( & V_63 ) ;
if ( F_41 ( V_58 -> V_56 ) ) {
V_29 = - V_43 ;
F_17 ( V_57 ) ;
goto V_64;
}
V_57 -> V_58 = V_58 ;
F_22 ( & V_57 -> V_25 , & V_65 ) ;
V_64:
F_45 ( & V_63 ) ;
return V_29 ;
}
void F_46 ( const struct V_59 * V_58 )
{
struct V_55 * V_57 ;
F_44 ( & V_63 ) ;
V_57 = F_41 ( V_58 -> V_56 ) ;
if ( V_57 ) {
F_47 ( & V_57 -> V_25 ) ;
F_17 ( V_57 ) ;
}
F_45 ( & V_63 ) ;
}
static const struct V_59 * F_48 ( const char * V_56 )
{
struct V_55 * V_57 ;
const struct V_59 * V_58 = NULL ;
F_44 ( & V_63 ) ;
V_57 = F_41 ( V_56 ) ;
if ( ! V_57 ) {
F_45 ( & V_63 ) ;
F_49 ( L_1 , V_56 ) ;
F_44 ( & V_63 ) ;
V_57 = F_41 ( V_56 ) ;
}
if ( V_57 ) {
V_58 = V_57 -> V_58 ;
if ( ! F_50 ( V_58 -> V_66 ) )
V_58 = NULL ;
}
F_45 ( & V_63 ) ;
return V_58 ;
}
static void F_51 ( const struct V_59 * V_58 )
{
F_52 ( V_58 -> V_66 ) ;
}
static bool F_53 ( struct V_14 * V_14 , struct V_67 * V_68 )
{
F_54 ( V_68 ) ;
return false ;
}
static T_2 F_55 ( struct V_14 * V_14 ,
struct V_1 * V_5 ,
struct V_67 * V_68 )
{
return V_69 ;
}
static bool F_56 ( struct V_14 * V_14 )
{
return V_14 -> V_58 != & V_70 ;
}
static void F_57 ( struct V_14 * V_14 )
{
V_14 -> V_71 = false ;
V_14 -> V_58 = & V_70 ;
}
static void F_58 ( struct V_14 * V_14 )
{
if ( ! V_14 -> V_72 || ! F_56 ( V_14 ) ||
! V_14 -> V_58 -> V_73 -> V_74 )
V_14 -> V_73 . V_74 = F_53 ;
else
V_14 -> V_73 . V_74 = V_14 -> V_58 -> V_73 -> V_74 ;
if ( ! V_14 -> V_72 || ! F_56 ( V_14 ) ||
! V_14 -> V_58 -> V_73 -> V_75 )
V_14 -> V_73 . V_75 = F_55 ;
else
V_14 -> V_73 . V_75 = V_14 -> V_58 -> V_73 -> V_75 ;
}
static int F_59 ( struct V_14 * V_14 ,
const struct V_59 * V_76 )
{
if ( F_56 ( V_14 ) ) {
void (* F_60)( struct V_14 * V_14 ) = V_14 -> V_73 . exit ;
memset ( & V_14 -> V_73 , 0 , sizeof( struct V_77 ) ) ;
F_58 ( V_14 ) ;
if ( F_60 )
F_60 ( V_14 ) ;
F_51 ( V_14 -> V_58 ) ;
F_57 ( V_14 ) ;
memset ( & V_14 -> V_78 , 0 ,
sizeof( struct V_14 ) - F_61 ( struct V_14 , V_78 ) ) ;
}
if ( ! V_76 )
return 0 ;
if ( V_76 -> V_73 -> V_37 ) {
int V_29 ;
V_29 = V_76 -> V_73 -> V_37 ( V_14 ) ;
if ( V_29 )
return V_29 ;
}
V_14 -> V_58 = V_76 ;
memcpy ( & V_14 -> V_73 , V_76 -> V_73 , sizeof( struct V_77 ) ) ;
F_58 ( V_14 ) ;
return 0 ;
}
static int F_62 ( struct V_14 * V_14 , const char * V_56 )
{
const struct V_59 * V_76 ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_29 ;
if ( ! F_63 ( & V_14 -> V_79 ) ) {
F_64 ( V_3 , L_2 ) ;
return - V_80 ;
}
if ( F_56 ( V_14 ) && strcmp ( V_14 -> V_58 -> V_56 , V_56 ) == 0 ) {
F_64 ( V_3 , L_3 ) ;
return - V_62 ;
}
V_76 = F_48 ( V_56 ) ;
if ( ! V_76 ) {
F_64 ( V_3 , L_4 , V_56 ) ;
return - V_62 ;
}
V_29 = F_59 ( V_14 , V_76 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_5 , V_56 ) ;
F_51 ( V_76 ) ;
return V_29 ;
}
F_65 ( V_3 , L_6 , V_56 ) ;
return 0 ;
}
static void F_66 ( struct V_81 * V_82 )
{
struct V_14 * V_14 ;
int V_83 ;
V_14 = F_39 ( V_82 , struct V_14 , V_84 . V_85 . V_82 ) ;
if ( ! F_67 () ) {
F_68 ( & V_14 -> V_84 . V_85 , 0 ) ;
return;
}
V_83 = F_69 ( & V_14 -> V_84 . V_86 ) ;
if ( V_83 < 0 ) {
F_70 () ;
return;
}
F_71 ( V_87 , V_14 -> V_3 ) ;
F_70 () ;
if ( V_83 )
F_68 ( & V_14 -> V_84 . V_85 ,
F_72 ( V_14 -> V_84 . V_88 ) ) ;
}
static void F_73 ( struct V_14 * V_14 )
{
if ( ! V_14 -> V_84 . V_89 || ! F_74 ( V_14 -> V_3 ) )
return;
F_75 ( V_14 -> V_84 . V_89 , & V_14 -> V_84 . V_86 ) ;
F_68 ( & V_14 -> V_84 . V_85 , 0 ) ;
}
static void F_76 ( struct V_14 * V_14 )
{
F_77 ( & V_14 -> V_84 . V_85 , F_66 ) ;
}
static void F_78 ( struct V_14 * V_14 )
{
F_79 ( & V_14 -> V_84 . V_85 ) ;
}
static void F_80 ( struct V_81 * V_82 )
{
struct V_14 * V_14 ;
int V_83 ;
V_14 = F_39 ( V_82 , struct V_14 , V_90 . V_85 . V_82 ) ;
if ( ! F_67 () ) {
F_68 ( & V_14 -> V_90 . V_85 , 0 ) ;
return;
}
V_83 = F_69 ( & V_14 -> V_90 . V_86 ) ;
if ( V_83 < 0 ) {
F_70 () ;
return;
}
F_71 ( V_91 , V_14 -> V_3 ) ;
F_70 () ;
if ( V_83 )
F_68 ( & V_14 -> V_90 . V_85 ,
F_72 ( V_14 -> V_90 . V_88 ) ) ;
}
static void F_81 ( struct V_14 * V_14 )
{
if ( ! V_14 -> V_90 . V_89 || ! F_74 ( V_14 -> V_3 ) )
return;
F_75 ( V_14 -> V_90 . V_89 , & V_14 -> V_90 . V_86 ) ;
F_68 ( & V_14 -> V_90 . V_85 , 0 ) ;
}
static void F_82 ( struct V_14 * V_14 )
{
F_77 ( & V_14 -> V_90 . V_85 , F_80 ) ;
}
static void F_83 ( struct V_14 * V_14 )
{
F_79 ( & V_14 -> V_90 . V_85 ) ;
}
static T_2 F_84 ( struct V_67 * * V_92 )
{
struct V_67 * V_68 = * V_92 ;
struct V_1 * V_5 ;
struct V_14 * V_14 ;
T_2 V_93 ;
V_68 = F_85 ( V_68 , V_94 ) ;
if ( ! V_68 )
return V_95 ;
* V_92 = V_68 ;
V_5 = F_1 ( V_68 -> V_3 ) ;
V_14 = V_5 -> V_14 ;
if ( ! F_86 ( V_5 ) ) {
V_93 = V_96 ;
} else {
V_93 = V_14 -> V_73 . V_75 ( V_14 , V_5 , V_68 ) ;
}
if ( V_93 == V_69 ) {
struct V_97 * V_98 ;
V_98 = F_87 ( V_14 -> V_98 ) ;
F_88 ( & V_98 -> V_99 ) ;
V_98 -> V_100 ++ ;
V_98 -> V_101 += V_68 -> V_102 ;
if ( V_68 -> V_103 == V_104 )
V_98 -> V_105 ++ ;
F_89 ( & V_98 -> V_99 ) ;
V_68 -> V_3 = V_14 -> V_3 ;
} else {
F_90 ( V_14 -> V_98 -> V_106 ) ;
}
return V_93 ;
}
static int F_91 ( struct V_14 * V_14 )
{
struct V_107 * V_108 ;
unsigned int V_109 = V_14 -> V_3 -> V_110 - 1 ;
unsigned int V_28 ;
if ( ! V_109 )
return 0 ;
V_108 = F_21 ( sizeof( struct V_107 ) * V_109 , V_30 ) ;
if ( ! V_108 )
return - V_31 ;
V_14 -> V_111 = V_108 ;
for ( V_28 = 0 ; V_28 < V_109 ; V_28 ++ )
F_92 ( V_108 ++ ) ;
return 0 ;
}
static void F_93 ( struct V_14 * V_14 )
{
F_17 ( V_14 -> V_111 ) ;
}
static struct V_107 * F_94 ( struct V_14 * V_14 , T_3 V_112 )
{
return & V_14 -> V_111 [ V_112 - 1 ] ;
}
static bool F_95 ( struct V_14 * V_14 , struct V_67 * V_68 )
{
struct V_107 * V_113 ;
struct V_1 * V_5 ;
if ( ! V_14 -> V_114 || ! V_68 -> V_115 )
return false ;
V_113 = F_94 ( V_14 , V_68 -> V_115 ) ;
F_96 (port, qom_list, qom_list) {
if ( ! F_97 ( V_14 , V_5 , V_68 ) )
return true ;
}
return false ;
}
static void F_98 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
if ( ! V_5 -> V_112 )
return;
F_99 ( & V_5 -> V_113 ) ;
}
static bool F_100 ( struct V_1 * V_5 ,
struct V_1 * V_116 )
{
if ( V_5 -> V_117 < V_116 -> V_117 )
return true ;
if ( V_5 -> V_117 > V_116 -> V_117 )
return false ;
if ( V_5 -> V_118 < V_116 -> V_118 )
return true ;
return false ;
}
static void F_101 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
struct V_1 * V_116 ;
struct V_107 * V_113 ;
struct V_107 * V_119 ;
if ( ! V_5 -> V_112 )
return;
V_113 = F_94 ( V_14 , V_5 -> V_112 ) ;
V_119 = V_113 ;
F_14 (cur, qom_list, qom_list) {
if ( F_100 ( V_5 , V_116 ) )
break;
V_119 = & V_116 -> V_113 ;
}
F_102 ( & V_5 -> V_113 , V_119 ) ;
}
static void F_103 ( struct V_14 * V_14 )
{
struct V_1 * V_5 ;
bool V_120 = false ;
F_14 (port, &team->port_list, list) {
if ( V_5 -> V_112 ) {
V_120 = true ;
break;
}
}
if ( V_120 == V_14 -> V_114 )
return;
F_104 ( V_14 -> V_3 , L_7 ,
V_120 ? L_8 : L_9 ) ;
V_14 -> V_114 = V_120 ;
}
static void F_105 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
if ( ! V_5 -> V_112 || F_86 ( V_5 ) )
return;
F_98 ( V_14 , V_5 ) ;
F_101 ( V_14 , V_5 ) ;
F_103 ( V_14 ) ;
}
static void F_106 ( struct V_14 * V_14 ,
struct V_1 * V_5 ,
T_3 V_121 )
{
if ( F_86 ( V_5 ) ) {
F_98 ( V_14 , V_5 ) ;
V_5 -> V_112 = V_121 ;
F_101 ( V_14 , V_5 ) ;
F_103 ( V_14 ) ;
} else {
V_5 -> V_112 = V_121 ;
}
}
static void F_107 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
F_101 ( V_14 , V_5 ) ;
F_103 ( V_14 ) ;
}
static void F_108 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
F_98 ( V_14 , V_5 ) ;
F_103 ( V_14 ) ;
}
static bool F_109 ( const struct V_14 * V_14 ,
const struct V_1 * V_5 )
{
struct V_1 * V_116 ;
F_14 (cur, &team->port_list, list)
if ( V_116 == V_5 )
return true ;
return false ;
}
static void F_110 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
if ( F_86 ( V_5 ) )
return;
V_5 -> V_118 = V_14 -> V_72 ++ ;
F_111 ( & V_5 -> V_122 ,
F_112 ( V_14 , V_5 -> V_118 ) ) ;
F_58 ( V_14 ) ;
F_107 ( V_14 , V_5 ) ;
if ( V_14 -> V_73 . V_123 )
V_14 -> V_73 . V_123 ( V_14 , V_5 ) ;
F_73 ( V_14 ) ;
F_81 ( V_14 ) ;
}
static void F_113 ( struct V_14 * V_14 , int V_124 )
{
int V_28 ;
struct V_1 * V_5 ;
for ( V_28 = V_124 + 1 ; V_28 < V_14 -> V_72 ; V_28 ++ ) {
V_5 = F_114 ( V_14 , V_28 ) ;
F_115 ( & V_5 -> V_122 ) ;
V_5 -> V_118 -- ;
F_111 ( & V_5 -> V_122 ,
F_112 ( V_14 , V_5 -> V_118 ) ) ;
}
}
static void F_116 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
if ( ! F_86 ( V_5 ) )
return;
if ( V_14 -> V_73 . V_125 )
V_14 -> V_73 . V_125 ( V_14 , V_5 ) ;
F_115 ( & V_5 -> V_122 ) ;
F_113 ( V_14 , V_5 -> V_118 ) ;
V_5 -> V_118 = - 1 ;
V_14 -> V_72 -- ;
F_108 ( V_14 , V_5 ) ;
F_58 ( V_14 ) ;
F_73 ( V_14 ) ;
F_81 ( V_14 ) ;
}
static void F_117 ( struct V_14 * V_14 )
{
struct V_1 * V_5 ;
T_4 V_126 = V_127 & V_128 ;
unsigned short V_129 = V_130 ;
unsigned int V_131 = V_132 |
V_133 ;
F_14 (port, &team->port_list, list) {
V_126 = F_118 ( V_126 ,
V_5 -> V_3 -> V_126 ,
V_127 ) ;
V_131 &= V_5 -> V_3 -> V_134 ;
if ( V_5 -> V_3 -> V_135 > V_129 )
V_129 = V_5 -> V_3 -> V_135 ;
}
V_14 -> V_3 -> V_126 = V_126 ;
V_14 -> V_3 -> V_135 = V_129 ;
V_14 -> V_3 -> V_134 &= ~ V_132 ;
if ( V_131 == ( V_132 | V_133 ) )
V_14 -> V_3 -> V_134 |= V_132 ;
F_119 ( V_14 -> V_3 ) ;
}
static void F_120 ( struct V_14 * V_14 )
{
F_121 ( & V_14 -> V_136 ) ;
F_117 ( V_14 ) ;
F_122 ( & V_14 -> V_136 ) ;
}
static int F_123 ( struct V_14 * V_14 , struct V_1 * V_5 )
{
int V_29 = 0 ;
F_124 ( V_14 -> V_3 ) ;
if ( V_14 -> V_73 . V_137 ) {
V_29 = V_14 -> V_73 . V_137 ( V_14 , V_5 ) ;
if ( V_29 ) {
F_64 ( V_14 -> V_3 , L_10 ,
V_5 -> V_3 -> V_22 ) ;
goto V_138;
}
}
return 0 ;
V_138:
F_125 ( V_14 -> V_3 ) ;
return V_29 ;
}
static void F_126 ( struct V_14 * V_14 , struct V_1 * V_5 )
{
if ( V_14 -> V_73 . V_139 )
V_14 -> V_73 . V_139 ( V_14 , V_5 ) ;
F_125 ( V_14 -> V_3 ) ;
}
static int F_127 ( struct V_14 * V_14 , struct V_1 * V_5 )
{
struct V_140 * V_141 ;
int V_29 ;
if ( ! V_14 -> V_3 -> V_142 )
return 0 ;
V_141 = F_29 ( sizeof( * V_141 ) , V_30 ) ;
if ( ! V_141 )
return - V_31 ;
V_29 = F_128 ( V_141 , V_5 -> V_3 ) ;
if ( V_29 ) {
F_17 ( V_141 ) ;
return V_29 ;
}
V_5 -> V_141 = V_141 ;
return V_29 ;
}
static void F_129 ( struct V_1 * V_5 )
{
struct V_140 * V_141 = V_5 -> V_141 ;
if ( ! V_141 )
return;
V_5 -> V_141 = NULL ;
F_130 () ;
F_131 ( V_141 ) ;
F_17 ( V_141 ) ;
}
static int F_127 ( struct V_14 * V_14 , struct V_1 * V_5 )
{
return 0 ;
}
static void F_129 ( struct V_1 * V_5 )
{
}
static int F_132 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
int V_29 ;
V_29 = F_133 ( V_6 , V_3 ) ;
if ( V_29 )
return V_29 ;
V_6 -> V_134 |= V_143 ;
return 0 ;
}
static void F_134 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
F_135 ( V_6 , V_3 ) ;
V_6 -> V_134 &= ~ V_143 ;
}
static int F_136 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_5 ;
char * V_144 = V_6 -> V_22 ;
int V_29 ;
if ( V_6 -> V_145 & V_146 ) {
F_64 ( V_3 , L_11 ,
V_144 ) ;
return - V_62 ;
}
if ( F_5 ( V_6 ) ) {
F_64 ( V_3 , L_12
L_13 , V_144 ) ;
return - V_80 ;
}
if ( V_6 -> V_147 & V_148 &&
F_137 ( V_3 ) ) {
F_64 ( V_3 , L_14 ,
V_144 ) ;
return - V_149 ;
}
V_29 = F_138 ( V_3 , V_6 ) ;
if ( V_29 )
return V_29 ;
if ( V_6 -> V_145 & V_150 ) {
F_64 ( V_3 , L_15 ,
V_144 ) ;
return - V_80 ;
}
V_5 = F_29 ( sizeof( struct V_1 ) + V_14 -> V_58 -> V_151 ,
V_30 ) ;
if ( ! V_5 )
return - V_31 ;
V_5 -> V_3 = V_6 ;
V_5 -> V_14 = V_14 ;
F_92 ( & V_5 -> V_113 ) ;
V_5 -> V_13 . V_152 = V_6 -> V_152 ;
V_29 = F_139 ( V_6 , V_3 -> V_152 ) ;
if ( V_29 ) {
F_104 ( V_3 , L_16 , V_29 ) ;
goto V_153;
}
memcpy ( V_5 -> V_13 . V_7 , V_6 -> V_7 , V_6 -> V_11 ) ;
V_29 = F_123 ( V_14 , V_5 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_10 ,
V_144 ) ;
goto V_138;
}
V_29 = F_140 ( V_6 ) ;
if ( V_29 ) {
F_104 ( V_3 , L_17 ,
V_144 ) ;
goto V_154;
}
V_29 = F_141 ( V_6 , V_3 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_18 ,
V_144 ) ;
goto V_155;
}
V_29 = F_127 ( V_14 , V_5 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_19 ,
V_144 ) ;
goto V_156;
}
if ( ! ( V_3 -> V_147 & V_157 ) )
F_142 ( V_6 ) ;
V_29 = F_143 ( V_6 , F_84 ,
V_5 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_20 ,
V_144 ) ;
goto V_158;
}
V_29 = F_132 ( V_3 , V_6 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_21 ,
V_144 ) ;
goto V_159;
}
V_29 = F_26 ( V_14 , V_5 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_22 ,
V_144 ) ;
goto V_160;
}
V_5 -> V_118 = - 1 ;
F_102 ( & V_5 -> V_25 , & V_14 -> V_79 ) ;
F_110 ( V_14 , V_5 ) ;
F_117 ( V_14 ) ;
F_144 ( V_5 , ! ! F_145 ( V_6 ) ) ;
F_34 ( V_14 ) ;
F_65 ( V_3 , L_23 , V_144 ) ;
return 0 ;
V_160:
F_134 ( V_3 , V_6 ) ;
V_159:
F_146 ( V_6 ) ;
V_158:
F_129 ( V_5 ) ;
V_156:
F_147 ( V_6 , V_3 ) ;
V_155:
F_148 ( V_6 ) ;
V_154:
F_126 ( V_14 , V_5 ) ;
F_8 ( V_5 ) ;
V_138:
F_139 ( V_6 , V_5 -> V_13 . V_152 ) ;
V_153:
F_17 ( V_5 ) ;
return V_29 ;
}
static int F_149 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_5 ;
char * V_144 = V_6 -> V_22 ;
V_5 = F_3 ( V_6 ) ;
if ( ! V_5 || ! F_109 ( V_14 , V_5 ) ) {
F_64 ( V_3 , L_24 ,
V_144 ) ;
return - V_161 ;
}
F_116 ( V_14 , V_5 ) ;
F_99 ( & V_5 -> V_25 ) ;
F_134 ( V_3 , V_6 ) ;
F_146 ( V_6 ) ;
F_129 ( V_5 ) ;
F_147 ( V_6 , V_3 ) ;
F_150 ( V_6 , V_3 ) ;
F_151 ( V_6 , V_3 ) ;
F_148 ( V_6 ) ;
F_126 ( V_14 , V_5 ) ;
F_27 ( V_14 , V_5 ) ;
F_34 ( V_14 ) ;
F_25 ( V_14 , V_5 ) ;
F_152 ( V_5 ) ;
F_8 ( V_5 ) ;
F_139 ( V_6 , V_5 -> V_13 . V_152 ) ;
F_153 ( V_5 , V_162 ) ;
F_65 ( V_3 , L_25 , V_144 ) ;
F_117 ( V_14 ) ;
return 0 ;
}
static int F_154 ( struct V_14 * V_14 , struct V_48 * V_49 )
{
V_49 -> V_163 . V_164 = V_14 -> V_58 -> V_56 ;
return 0 ;
}
static int F_155 ( struct V_14 * V_14 , struct V_48 * V_49 )
{
return F_62 ( V_14 , V_49 -> V_163 . V_164 ) ;
}
static int F_156 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_49 -> V_163 . V_165 = V_14 -> V_84 . V_89 ;
return 0 ;
}
static int F_157 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_14 -> V_84 . V_89 = V_49 -> V_163 . V_165 ;
return 0 ;
}
static int F_158 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_49 -> V_163 . V_165 = V_14 -> V_84 . V_88 ;
return 0 ;
}
static int F_159 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_14 -> V_84 . V_88 = V_49 -> V_163 . V_165 ;
return 0 ;
}
static int F_160 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_49 -> V_163 . V_165 = V_14 -> V_90 . V_89 ;
return 0 ;
}
static int F_161 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_14 -> V_90 . V_89 = V_49 -> V_163 . V_165 ;
return 0 ;
}
static int F_162 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_49 -> V_163 . V_165 = V_14 -> V_90 . V_88 ;
return 0 ;
}
static int F_163 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_14 -> V_90 . V_88 = V_49 -> V_163 . V_165 ;
return 0 ;
}
static int F_164 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_5 = V_49 -> V_32 -> V_5 ;
V_49 -> V_163 . V_166 = F_86 ( V_5 ) ;
return 0 ;
}
static int F_165 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_5 = V_49 -> V_32 -> V_5 ;
if ( V_49 -> V_163 . V_166 )
F_110 ( V_14 , V_5 ) ;
else
F_116 ( V_14 , V_5 ) ;
return 0 ;
}
static int F_166 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_5 = V_49 -> V_32 -> V_5 ;
V_49 -> V_163 . V_166 = V_5 -> V_16 . V_15 ;
return 0 ;
}
static int F_167 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_5 = V_49 -> V_32 -> V_5 ;
V_5 -> V_16 . V_15 = V_49 -> V_163 . V_166 ;
F_12 ( V_5 ) ;
F_168 ( V_5 -> V_14 ) ;
return 0 ;
}
static int F_169 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_5 = V_49 -> V_32 -> V_5 ;
V_49 -> V_163 . V_166 = V_5 -> V_16 . V_17 ;
return 0 ;
}
static int F_170 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_5 = V_49 -> V_32 -> V_5 ;
V_5 -> V_16 . V_17 = V_49 -> V_163 . V_166 ;
F_12 ( V_5 ) ;
F_168 ( V_5 -> V_14 ) ;
return 0 ;
}
static int F_171 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_5 = V_49 -> V_32 -> V_5 ;
V_49 -> V_163 . V_167 = V_5 -> V_117 ;
return 0 ;
}
static int F_172 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_5 = V_49 -> V_32 -> V_5 ;
T_5 V_117 = V_49 -> V_163 . V_167 ;
if ( V_5 -> V_117 == V_117 )
return 0 ;
V_5 -> V_117 = V_117 ;
F_105 ( V_14 , V_5 ) ;
return 0 ;
}
static int F_173 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_5 = V_49 -> V_32 -> V_5 ;
V_49 -> V_163 . V_165 = V_5 -> V_112 ;
return 0 ;
}
static int F_174 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_5 = V_49 -> V_32 -> V_5 ;
T_3 V_121 = V_49 -> V_163 . V_165 ;
if ( V_5 -> V_112 == V_121 )
return 0 ;
if ( V_121 >= V_14 -> V_3 -> V_168 )
return - V_62 ;
F_106 ( V_14 , V_5 , V_121 ) ;
return 0 ;
}
static void F_175 ( struct V_2 * V_3 ,
struct V_169 * V_170 ,
void * V_171 )
{
F_176 ( & V_170 -> V_172 , & V_173 ) ;
}
static void F_177 ( struct V_2 * V_3 )
{
F_176 ( & V_3 -> V_174 , & V_175 ) ;
F_178 ( V_3 , F_175 , NULL ) ;
V_3 -> V_176 = & V_177 ;
}
static int F_179 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_180 ( V_3 ) ;
int V_28 ;
int V_29 ;
V_14 -> V_3 = V_3 ;
F_181 ( & V_14 -> V_136 ) ;
F_57 ( V_14 ) ;
V_14 -> V_98 = F_182 ( struct V_97 ) ;
if ( ! V_14 -> V_98 )
return - V_31 ;
for ( V_28 = 0 ; V_28 < V_178 ; V_28 ++ )
F_183 ( & V_14 -> V_179 [ V_28 ] ) ;
F_92 ( & V_14 -> V_79 ) ;
V_29 = F_91 ( V_14 ) ;
if ( V_29 )
goto V_180;
F_58 ( V_14 ) ;
F_92 ( & V_14 -> V_46 ) ;
F_92 ( & V_14 -> V_36 ) ;
F_76 ( V_14 ) ;
F_82 ( V_14 ) ;
V_29 = F_33 ( V_14 , V_181 , F_184 ( V_181 ) ) ;
if ( V_29 )
goto V_182;
F_185 ( V_3 ) ;
F_177 ( V_3 ) ;
return 0 ;
V_182:
F_83 ( V_14 ) ;
F_78 ( V_14 ) ;
F_93 ( V_14 ) ;
V_180:
F_186 ( V_14 -> V_98 ) ;
return V_29 ;
}
static void F_187 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_180 ( V_3 ) ;
struct V_1 * V_5 ;
struct V_1 * V_26 ;
F_121 ( & V_14 -> V_136 ) ;
F_19 (port, tmp, &team->port_list, list)
F_149 ( V_14 , V_5 -> V_3 ) ;
F_59 ( V_14 , NULL ) ;
F_32 ( V_14 , V_181 , F_184 ( V_181 ) ) ;
F_83 ( V_14 ) ;
F_78 ( V_14 ) ;
F_93 ( V_14 ) ;
F_122 ( & V_14 -> V_136 ) ;
}
static void F_188 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_180 ( V_3 ) ;
F_186 ( V_14 -> V_98 ) ;
F_189 ( V_3 ) ;
}
static int F_190 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_191 ( struct V_2 * V_3 )
{
return 0 ;
}
static T_6 F_192 ( struct V_67 * V_68 , struct V_2 * V_3 )
{
struct V_14 * V_14 = F_180 ( V_3 ) ;
bool V_183 ;
unsigned int V_102 = V_68 -> V_102 ;
V_183 = F_95 ( V_14 , V_68 ) ;
if ( ! V_183 )
V_183 = V_14 -> V_73 . V_74 ( V_14 , V_68 ) ;
if ( V_183 ) {
struct V_97 * V_98 ;
V_98 = F_87 ( V_14 -> V_98 ) ;
F_88 ( & V_98 -> V_99 ) ;
V_98 -> V_184 ++ ;
V_98 -> V_185 += V_102 ;
F_89 ( & V_98 -> V_99 ) ;
} else {
F_90 ( V_14 -> V_98 -> V_186 ) ;
}
return V_187 ;
}
static T_3 F_193 ( struct V_2 * V_3 , struct V_67 * V_68 ,
void * V_188 , T_7 V_189 )
{
T_3 V_170 = F_194 ( V_68 ) ? F_195 ( V_68 ) : 0 ;
F_196 ( V_68 ) -> V_190 = V_68 -> V_115 ;
if ( F_197 ( V_170 >= V_3 -> V_168 ) ) {
do {
V_170 -= V_3 -> V_168 ;
} while ( V_170 >= V_3 -> V_168 );
}
return V_170 ;
}
static void F_198 ( struct V_2 * V_3 , int V_191 )
{
struct V_14 * V_14 = F_180 ( V_3 ) ;
struct V_1 * V_5 ;
int V_192 ;
F_199 () ;
F_96 (port, &team->port_list, list) {
if ( V_191 & V_193 ) {
V_192 = V_3 -> V_145 & V_193 ? 1 : - 1 ;
F_200 ( V_5 -> V_3 , V_192 ) ;
}
if ( V_191 & V_194 ) {
V_192 = V_3 -> V_145 & V_194 ? 1 : - 1 ;
F_201 ( V_5 -> V_3 , V_192 ) ;
}
}
F_202 () ;
}
static void F_203 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_180 ( V_3 ) ;
struct V_1 * V_5 ;
F_199 () ;
F_96 (port, &team->port_list, list) {
F_204 ( V_5 -> V_3 , V_3 ) ;
F_205 ( V_5 -> V_3 , V_3 ) ;
}
F_202 () ;
}
static int F_206 ( struct V_2 * V_3 , void * V_195 )
{
struct V_8 * V_9 = V_195 ;
struct V_14 * V_14 = F_180 ( V_3 ) ;
struct V_1 * V_5 ;
if ( V_3 -> type == V_196 && ! F_207 ( V_9 -> V_10 ) )
return - V_197 ;
memcpy ( V_3 -> V_7 , V_9 -> V_10 , V_3 -> V_11 ) ;
F_121 ( & V_14 -> V_136 ) ;
F_14 (port, &team->port_list, list)
if ( V_14 -> V_73 . V_198 )
V_14 -> V_73 . V_198 ( V_14 , V_5 ) ;
F_122 ( & V_14 -> V_136 ) ;
return 0 ;
}
static int F_208 ( struct V_2 * V_3 , int V_199 )
{
struct V_14 * V_14 = F_180 ( V_3 ) ;
struct V_1 * V_5 ;
int V_29 ;
F_121 ( & V_14 -> V_136 ) ;
V_14 -> V_200 = true ;
F_14 (port, &team->port_list, list) {
V_29 = F_139 ( V_5 -> V_3 , V_199 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_26 ,
V_5 -> V_3 -> V_22 ) ;
goto V_201;
}
}
V_14 -> V_200 = false ;
F_122 ( & V_14 -> V_136 ) ;
V_3 -> V_152 = V_199 ;
return 0 ;
V_201:
F_209 (port, &team->port_list, list)
F_139 ( V_5 -> V_3 , V_3 -> V_152 ) ;
V_14 -> V_200 = false ;
F_122 ( & V_14 -> V_136 ) ;
return V_29 ;
}
static struct V_202 *
F_210 ( struct V_2 * V_3 , struct V_202 * V_203 )
{
struct V_14 * V_14 = F_180 ( V_3 ) ;
struct V_97 * V_195 ;
T_8 V_100 , V_101 , V_105 , V_184 , V_185 ;
T_4 V_106 = 0 , V_186 = 0 ;
unsigned int V_204 ;
int V_28 ;
F_211 (i) {
V_195 = F_212 ( V_14 -> V_98 , V_28 ) ;
do {
V_204 = F_213 ( & V_195 -> V_99 ) ;
V_100 = V_195 -> V_100 ;
V_101 = V_195 -> V_101 ;
V_105 = V_195 -> V_105 ;
V_184 = V_195 -> V_184 ;
V_185 = V_195 -> V_185 ;
} while ( F_214 ( & V_195 -> V_99 , V_204 ) );
V_203 -> V_100 += V_100 ;
V_203 -> V_101 += V_101 ;
V_203 -> V_205 += V_105 ;
V_203 -> V_184 += V_184 ;
V_203 -> V_185 += V_185 ;
V_106 += V_195 -> V_106 ;
V_186 += V_195 -> V_186 ;
}
V_203 -> V_106 = V_106 ;
V_203 -> V_186 = V_186 ;
return V_203 ;
}
static int F_215 ( struct V_2 * V_3 , T_9 V_206 , T_3 V_207 )
{
struct V_14 * V_14 = F_180 ( V_3 ) ;
struct V_1 * V_5 ;
int V_29 ;
F_121 ( & V_14 -> V_136 ) ;
F_14 (port, &team->port_list, list) {
V_29 = F_216 ( V_5 -> V_3 , V_206 , V_207 ) ;
if ( V_29 )
goto V_201;
}
F_122 ( & V_14 -> V_136 ) ;
return 0 ;
V_201:
F_209 (port, &team->port_list, list)
F_217 ( V_5 -> V_3 , V_206 , V_207 ) ;
F_122 ( & V_14 -> V_136 ) ;
return V_29 ;
}
static int F_218 ( struct V_2 * V_3 , T_9 V_206 , T_3 V_207 )
{
struct V_14 * V_14 = F_180 ( V_3 ) ;
struct V_1 * V_5 ;
F_199 () ;
F_96 (port, &team->port_list, list)
F_217 ( V_5 -> V_3 , V_206 , V_207 ) ;
F_202 () ;
return 0 ;
}
static void F_219 ( struct V_2 * V_3 )
{
}
static void F_220 ( struct V_14 * V_14 )
{
struct V_1 * V_5 ;
F_14 (port, &team->port_list, list)
F_129 ( V_5 ) ;
}
static void F_221 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_180 ( V_3 ) ;
F_121 ( & V_14 -> V_136 ) ;
F_220 ( V_14 ) ;
F_122 ( & V_14 -> V_136 ) ;
}
static int F_222 ( struct V_2 * V_3 ,
struct V_208 * V_209 )
{
struct V_14 * V_14 = F_180 ( V_3 ) ;
struct V_1 * V_5 ;
int V_29 = 0 ;
F_121 ( & V_14 -> V_136 ) ;
F_14 (port, &team->port_list, list) {
V_29 = F_127 ( V_14 , V_5 ) ;
if ( V_29 ) {
F_220 ( V_14 ) ;
break;
}
}
F_122 ( & V_14 -> V_136 ) ;
return V_29 ;
}
static int F_223 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_180 ( V_3 ) ;
int V_29 ;
F_121 ( & V_14 -> V_136 ) ;
V_29 = F_136 ( V_14 , V_6 ) ;
F_122 ( & V_14 -> V_136 ) ;
return V_29 ;
}
static int F_224 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_180 ( V_3 ) ;
int V_29 ;
F_121 ( & V_14 -> V_136 ) ;
V_29 = F_149 ( V_14 , V_6 ) ;
F_122 ( & V_14 -> V_136 ) ;
return V_29 ;
}
static T_10 F_225 ( struct V_2 * V_3 ,
T_10 V_147 )
{
struct V_1 * V_5 ;
struct V_14 * V_14 = F_180 ( V_3 ) ;
T_10 V_210 ;
V_210 = V_147 ;
V_147 &= ~ V_211 ;
V_147 |= V_128 ;
F_199 () ;
F_96 (port, &team->port_list, list) {
V_147 = F_118 ( V_147 ,
V_5 -> V_3 -> V_147 ,
V_210 ) ;
}
F_202 () ;
V_147 = F_226 ( V_147 , V_210 ) ;
return V_147 ;
}
static int F_227 ( struct V_2 * V_3 , bool V_212 )
{
struct V_14 * V_14 = F_180 ( V_3 ) ;
V_14 -> V_71 = true ;
if ( V_212 )
F_228 ( V_3 ) ;
else
F_185 ( V_3 ) ;
return 0 ;
}
static void F_229 ( struct V_2 * V_3 ,
struct V_213 * V_214 )
{
F_230 ( V_214 -> V_215 , V_216 , sizeof( V_214 -> V_215 ) ) ;
F_230 ( V_214 -> V_217 , V_218 , sizeof( V_214 -> V_217 ) ) ;
}
static void F_231 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
V_3 -> V_219 = V_6 -> V_219 ;
V_3 -> type = V_6 -> type ;
V_3 -> V_135 = V_6 -> V_135 ;
V_3 -> V_11 = V_6 -> V_11 ;
V_3 -> V_152 = V_6 -> V_152 ;
memcpy ( V_3 -> V_220 , V_6 -> V_220 , V_6 -> V_11 ) ;
F_232 ( V_3 , V_6 ) ;
}
static int F_138 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
struct V_14 * V_14 = F_180 ( V_3 ) ;
char * V_144 = V_6 -> V_22 ;
int V_29 ;
if ( V_3 -> type == V_6 -> type )
return 0 ;
if ( ! F_63 ( & V_14 -> V_79 ) ) {
F_64 ( V_3 , L_27 , V_144 ) ;
return - V_80 ;
}
V_29 = F_71 ( V_221 , V_3 ) ;
V_29 = F_233 ( V_29 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_28 ) ;
return V_29 ;
}
F_234 ( V_3 ) ;
F_235 ( V_3 ) ;
F_231 ( V_3 , V_6 ) ;
F_71 ( V_222 , V_3 ) ;
return 0 ;
}
static void F_236 ( struct V_2 * V_3 )
{
F_237 ( V_3 ) ;
V_3 -> V_223 = & V_224 ;
V_3 -> V_225 = & V_226 ;
V_3 -> V_227 = F_188 ;
V_3 -> V_228 = 0 ;
V_3 -> V_145 |= V_229 ;
V_3 -> V_134 &= ~ ( V_132 | V_230 ) ;
V_3 -> V_134 |= V_231 | V_232 ;
V_3 -> V_147 |= V_233 ;
V_3 -> V_147 |= V_234 ;
V_3 -> V_147 |= V_235 ;
V_3 -> V_236 = V_127 |
V_237 |
V_238 |
V_239 ;
V_3 -> V_236 &= ~ ( V_240 & ~ V_241 ) ;
V_3 -> V_147 |= V_3 -> V_236 ;
}
static int F_238 ( struct V_242 * V_243 , struct V_2 * V_3 ,
struct V_244 * V_245 [] , struct V_244 * V_163 [] )
{
if ( V_245 [ V_246 ] == NULL )
F_239 ( V_3 ) ;
return F_240 ( V_3 ) ;
}
static int F_241 ( struct V_244 * V_245 [] , struct V_244 * V_163 [] )
{
if ( V_245 [ V_246 ] ) {
if ( F_242 ( V_245 [ V_246 ] ) != V_247 )
return - V_62 ;
if ( ! F_207 ( F_243 ( V_245 [ V_246 ] ) ) )
return - V_197 ;
}
return 0 ;
}
static unsigned int F_244 ( void )
{
return V_248 ;
}
static unsigned int F_245 ( void )
{
return V_249 ;
}
static int F_246 ( struct V_67 * V_68 , struct V_250 * V_32 )
{
struct V_67 * V_251 ;
void * V_252 ;
int V_29 ;
V_251 = F_247 ( V_253 , V_30 ) ;
if ( ! V_251 )
return - V_31 ;
V_252 = F_248 ( V_251 , V_32 -> V_254 , V_32 -> V_255 ,
& V_256 , 0 , V_257 ) ;
if ( ! V_252 ) {
V_29 = - V_258 ;
goto V_259;
}
F_249 ( V_251 , V_252 ) ;
return F_250 ( F_251 ( V_32 ) , V_251 , V_32 -> V_254 ) ;
V_259:
F_252 ( V_251 ) ;
return V_29 ;
}
static struct V_14 * F_253 ( struct V_250 * V_32 )
{
struct V_242 * V_242 = F_251 ( V_32 ) ;
int V_260 ;
struct V_2 * V_3 ;
struct V_14 * V_14 ;
if ( ! V_32 -> V_261 [ V_262 ] )
return NULL ;
V_260 = F_254 ( V_32 -> V_261 [ V_262 ] ) ;
V_3 = F_255 ( V_242 , V_260 ) ;
if ( ! V_3 || V_3 -> V_223 != & V_224 ) {
if ( V_3 )
F_125 ( V_3 ) ;
return NULL ;
}
V_14 = F_180 ( V_3 ) ;
F_121 ( & V_14 -> V_136 ) ;
return V_14 ;
}
static void F_256 ( struct V_14 * V_14 )
{
F_122 ( & V_14 -> V_136 ) ;
F_125 ( V_14 -> V_3 ) ;
}
static int F_257 ( struct V_67 * V_68 , struct V_14 * V_14 , T_4 V_263 )
{
return F_250 ( F_258 ( V_14 -> V_3 ) , V_68 , V_263 ) ;
}
static int F_259 ( struct V_67 * V_68 , struct V_14 * V_14 ,
struct V_23 * V_24 )
{
struct V_244 * V_264 ;
struct V_19 * V_21 = V_24 -> V_21 ;
struct V_53 * V_54 = & V_24 -> V_32 ;
struct V_48 V_49 ;
int V_29 ;
V_49 . V_32 = V_54 ;
V_29 = F_36 ( V_14 , V_24 , & V_49 ) ;
if ( V_29 )
return V_29 ;
V_264 = F_260 ( V_68 , V_265 ) ;
if ( ! V_264 )
return - V_258 ;
if ( F_261 ( V_68 , V_266 , V_21 -> V_22 ) )
goto V_267;
if ( V_54 -> V_5 &&
F_262 ( V_68 , V_268 ,
V_54 -> V_5 -> V_3 -> V_260 ) )
goto V_267;
if ( V_24 -> V_21 -> V_27 &&
F_262 ( V_68 , V_269 ,
V_54 -> V_33 ) )
goto V_267;
switch ( V_21 -> type ) {
case V_270 :
if ( F_263 ( V_68 , V_271 , V_272 ) )
goto V_267;
if ( F_262 ( V_68 , V_273 , V_49 . V_163 . V_165 ) )
goto V_267;
break;
case V_274 :
if ( F_263 ( V_68 , V_271 , V_275 ) )
goto V_267;
if ( F_261 ( V_68 , V_273 ,
V_49 . V_163 . V_164 ) )
goto V_267;
break;
case V_276 :
if ( F_263 ( V_68 , V_271 , V_277 ) )
goto V_267;
if ( F_264 ( V_68 , V_273 , V_49 . V_163 . V_278 . V_102 ,
V_49 . V_163 . V_278 . V_279 ) )
goto V_267;
break;
case V_280 :
if ( F_263 ( V_68 , V_271 , V_281 ) )
goto V_267;
if ( V_49 . V_163 . V_166 &&
F_265 ( V_68 , V_273 ) )
goto V_267;
break;
case V_282 :
if ( F_263 ( V_68 , V_271 , V_283 ) )
goto V_267;
if ( F_266 ( V_68 , V_273 , V_49 . V_163 . V_167 ) )
goto V_267;
break;
default:
F_267 () ;
}
if ( V_24 -> V_35 && F_265 ( V_68 , V_284 ) )
goto V_267;
if ( V_24 -> V_34 ) {
if ( F_265 ( V_68 , V_285 ) )
goto V_267;
V_24 -> V_34 = false ;
}
F_268 ( V_68 , V_264 ) ;
return 0 ;
V_267:
F_269 ( V_68 , V_264 ) ;
return - V_258 ;
}
static int F_270 ( struct V_67 * * V_92 ,
struct V_14 * V_14 , T_4 V_263 ,
T_11 * V_286 )
{
int V_29 ;
if ( * V_92 ) {
V_29 = V_286 ( * V_92 , V_14 , V_263 ) ;
if ( V_29 )
return V_29 ;
}
* V_92 = F_271 ( V_287 , V_30 ) ;
if ( ! * V_92 )
return - V_31 ;
return 0 ;
}
static int F_272 ( struct V_14 * V_14 , T_4 V_263 , T_4 V_288 ,
int V_145 , T_11 * V_286 ,
struct V_107 * V_289 )
{
struct V_244 * V_46 ;
struct V_290 * V_291 ;
void * V_252 ;
struct V_23 * V_24 ;
int V_29 ;
struct V_67 * V_68 = NULL ;
bool V_292 ;
int V_28 ;
V_24 = F_273 ( V_289 ,
struct V_23 , V_293 ) ;
V_294:
V_29 = F_270 ( & V_68 , V_14 , V_263 , V_286 ) ;
if ( V_29 )
return V_29 ;
V_252 = F_248 ( V_68 , V_263 , V_288 , & V_256 , V_145 | V_295 ,
V_296 ) ;
if ( ! V_252 )
return - V_258 ;
if ( F_262 ( V_68 , V_262 , V_14 -> V_3 -> V_260 ) )
goto V_297;
V_46 = F_260 ( V_68 , V_298 ) ;
if ( ! V_46 )
goto V_297;
V_28 = 0 ;
V_292 = false ;
F_274 (opt_inst, sel_opt_inst_list, tmp_list) {
V_29 = F_259 ( V_68 , V_14 , V_24 ) ;
if ( V_29 ) {
if ( V_29 == - V_258 ) {
if ( ! V_28 )
goto V_299;
V_292 = true ;
break;
}
goto V_299;
}
V_28 ++ ;
}
F_268 ( V_68 , V_46 ) ;
F_249 ( V_68 , V_252 ) ;
if ( V_292 )
goto V_294;
V_300:
V_291 = F_275 ( V_68 , V_263 , V_288 , V_301 , 0 , V_145 | V_295 ) ;
if ( ! V_291 ) {
V_29 = F_270 ( & V_68 , V_14 , V_263 , V_286 ) ;
if ( V_29 )
goto V_299;
goto V_300;
}
return V_286 ( V_68 , V_14 , V_263 ) ;
V_297:
V_29 = - V_258 ;
V_299:
F_276 ( V_68 , V_252 ) ;
F_252 ( V_68 ) ;
return V_29 ;
}
static int F_277 ( struct V_67 * V_68 , struct V_250 * V_32 )
{
struct V_14 * V_14 ;
struct V_23 * V_24 ;
int V_29 ;
F_278 ( V_289 ) ;
V_14 = F_253 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
F_14 (opt_inst, &team->option_inst_list, list)
F_22 ( & V_24 -> V_293 , & V_289 ) ;
V_29 = F_272 ( V_14 , V_32 -> V_254 , V_32 -> V_255 ,
V_302 , F_257 ,
& V_289 ) ;
F_256 ( V_14 ) ;
return V_29 ;
}
static int F_279 ( struct V_67 * V_68 , struct V_250 * V_32 )
{
struct V_14 * V_14 ;
int V_29 = 0 ;
int V_28 ;
struct V_244 * V_303 ;
F_278 ( V_304 ) ;
V_14 = F_253 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
V_29 = - V_62 ;
if ( ! V_32 -> V_261 [ V_298 ] ) {
V_29 = - V_62 ;
goto V_305;
}
F_280 (nl_option, info->attrs[TEAM_ATTR_LIST_OPTION], i) {
struct V_244 * V_306 [ V_307 + 1 ] ;
struct V_244 * V_308 ;
struct V_244 * V_309 ;
enum V_310 V_311 ;
int V_312 = 0 ;
T_4 V_313 = 0 ;
bool V_314 = false ;
struct V_23 * V_24 ;
char * V_20 ;
bool V_315 = false ;
if ( F_281 ( V_303 ) != V_265 ) {
V_29 = - V_62 ;
goto V_305;
}
V_29 = F_282 ( V_306 , V_307 ,
V_303 , V_316 ) ;
if ( V_29 )
goto V_305;
if ( ! V_306 [ V_266 ] ||
! V_306 [ V_271 ] ) {
V_29 = - V_62 ;
goto V_305;
}
switch ( F_283 ( V_306 [ V_271 ] ) ) {
case V_272 :
V_311 = V_270 ;
break;
case V_275 :
V_311 = V_274 ;
break;
case V_277 :
V_311 = V_276 ;
break;
case V_281 :
V_311 = V_280 ;
break;
case V_283 :
V_311 = V_282 ;
break;
default:
goto V_305;
}
V_309 = V_306 [ V_273 ] ;
if ( V_311 != V_280 && ! V_309 ) {
V_29 = - V_62 ;
goto V_305;
}
V_20 = F_243 ( V_306 [ V_266 ] ) ;
V_308 = V_306 [ V_268 ] ;
if ( V_308 )
V_312 = F_254 ( V_308 ) ;
V_308 = V_306 [ V_269 ] ;
if ( V_308 ) {
V_314 = true ;
V_313 = F_254 ( V_308 ) ;
}
F_14 (opt_inst, &team->option_inst_list, list) {
struct V_19 * V_21 = V_24 -> V_21 ;
struct V_48 V_49 ;
struct V_53 * V_54 ;
int V_317 ;
V_54 = & V_24 -> V_32 ;
V_317 = V_54 -> V_5 ?
V_54 -> V_5 -> V_3 -> V_260 : 0 ;
if ( V_21 -> type != V_311 ||
strcmp ( V_21 -> V_22 , V_20 ) ||
V_317 != V_312 ||
( V_21 -> V_27 && ! V_314 ) ||
V_54 -> V_33 != V_313 )
continue;
V_315 = true ;
V_49 . V_32 = V_54 ;
switch ( V_311 ) {
case V_270 :
V_49 . V_163 . V_165 = F_254 ( V_309 ) ;
break;
case V_274 :
if ( F_242 ( V_309 ) > V_318 ) {
V_29 = - V_62 ;
goto V_305;
}
V_49 . V_163 . V_164 = F_243 ( V_309 ) ;
break;
case V_276 :
V_49 . V_163 . V_278 . V_102 = F_242 ( V_309 ) ;
V_49 . V_163 . V_278 . V_279 = F_243 ( V_309 ) ;
break;
case V_280 :
V_49 . V_163 . V_166 = V_309 ? true : false ;
break;
case V_282 :
V_49 . V_163 . V_167 = F_284 ( V_309 ) ;
break;
default:
F_267 () ;
}
V_29 = F_37 ( V_14 , V_24 , & V_49 ) ;
if ( V_29 )
goto V_305;
V_24 -> V_34 = true ;
F_285 ( & V_24 -> V_293 , & V_304 ) ;
}
if ( ! V_315 ) {
V_29 = - V_161 ;
goto V_305;
}
}
V_29 = F_286 ( V_14 , & V_304 ) ;
V_305:
F_256 ( V_14 ) ;
return V_29 ;
}
static int F_287 ( struct V_67 * V_68 ,
struct V_1 * V_5 )
{
struct V_244 * V_319 ;
V_319 = F_260 ( V_68 , V_320 ) ;
if ( ! V_319 )
goto V_267;
if ( F_262 ( V_68 , V_321 , V_5 -> V_3 -> V_260 ) )
goto V_267;
if ( V_5 -> V_34 ) {
if ( F_265 ( V_68 , V_322 ) )
goto V_267;
V_5 -> V_34 = false ;
}
if ( ( V_5 -> V_35 &&
F_265 ( V_68 , V_323 ) ) ||
( V_5 -> V_18 . V_15 &&
F_265 ( V_68 , V_324 ) ) ||
F_262 ( V_68 , V_325 , V_5 -> V_18 . V_326 ) ||
F_263 ( V_68 , V_327 , V_5 -> V_18 . V_328 ) )
goto V_267;
F_268 ( V_68 , V_319 ) ;
return 0 ;
V_267:
F_269 ( V_68 , V_319 ) ;
return - V_258 ;
}
static int F_288 ( struct V_14 * V_14 , T_4 V_263 , T_4 V_288 ,
int V_145 , T_11 * V_286 ,
struct V_1 * V_329 )
{
struct V_244 * V_79 ;
struct V_290 * V_291 ;
void * V_252 ;
struct V_1 * V_5 ;
int V_29 ;
struct V_67 * V_68 = NULL ;
bool V_292 ;
int V_28 ;
V_5 = F_289 ( & V_14 -> V_79 ,
struct V_1 , V_25 ) ;
V_294:
V_29 = F_270 ( & V_68 , V_14 , V_263 , V_286 ) ;
if ( V_29 )
return V_29 ;
V_252 = F_248 ( V_68 , V_263 , V_288 , & V_256 , V_145 | V_295 ,
V_330 ) ;
if ( ! V_252 )
return - V_258 ;
if ( F_262 ( V_68 , V_262 , V_14 -> V_3 -> V_260 ) )
goto V_297;
V_79 = F_260 ( V_68 , V_331 ) ;
if ( ! V_79 )
goto V_297;
V_28 = 0 ;
V_292 = false ;
if ( V_329 ) {
V_29 = F_287 ( V_68 , V_329 ) ;
if ( V_29 )
goto V_299;
} else if ( V_5 ) {
F_274 (port, &team->port_list, list) {
V_29 = F_287 ( V_68 , V_5 ) ;
if ( V_29 ) {
if ( V_29 == - V_258 ) {
if ( ! V_28 )
goto V_299;
V_292 = true ;
break;
}
goto V_299;
}
V_28 ++ ;
}
}
F_268 ( V_68 , V_79 ) ;
F_249 ( V_68 , V_252 ) ;
if ( V_292 )
goto V_294;
V_300:
V_291 = F_275 ( V_68 , V_263 , V_288 , V_301 , 0 , V_145 | V_295 ) ;
if ( ! V_291 ) {
V_29 = F_270 ( & V_68 , V_14 , V_263 , V_286 ) ;
if ( V_29 )
goto V_299;
goto V_300;
}
return V_286 ( V_68 , V_14 , V_263 ) ;
V_297:
V_29 = - V_258 ;
V_299:
F_276 ( V_68 , V_252 ) ;
F_252 ( V_68 ) ;
return V_29 ;
}
static int F_290 ( struct V_67 * V_68 ,
struct V_250 * V_32 )
{
struct V_14 * V_14 ;
int V_29 ;
V_14 = F_253 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
V_29 = F_288 ( V_14 , V_32 -> V_254 , V_32 -> V_255 ,
V_302 , F_257 , NULL ) ;
F_256 ( V_14 ) ;
return V_29 ;
}
static int F_291 ( struct V_67 * V_68 ,
struct V_14 * V_14 , T_4 V_263 )
{
return F_292 ( & V_256 , F_258 ( V_14 -> V_3 ) ,
V_68 , 0 , 0 , V_30 ) ;
}
static int F_286 ( struct V_14 * V_14 ,
struct V_107 * V_289 )
{
return F_272 ( V_14 , 0 , 0 , 0 , F_291 ,
V_289 ) ;
}
static int F_293 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
return F_288 ( V_14 , 0 , 0 , 0 , F_291 ,
V_5 ) ;
}
static int F_294 ( void )
{
return F_295 ( & V_256 , V_332 ,
V_333 ) ;
}
static void F_296 ( void )
{
F_297 ( & V_256 ) ;
}
static void F_34 ( struct V_14 * V_14 )
{
int V_29 ;
struct V_23 * V_24 ;
F_278 ( V_289 ) ;
F_14 (opt_inst, &team->option_inst_list, list) {
if ( V_24 -> V_34 )
F_22 ( & V_24 -> V_293 , & V_289 ) ;
}
V_29 = F_286 ( V_14 , & V_289 ) ;
if ( V_29 && V_29 != - V_334 )
F_298 ( V_14 -> V_3 , L_29 ,
V_29 ) ;
}
static void F_299 ( struct V_1 * V_5 , bool V_15 )
{
int V_29 ;
V_5 -> V_34 = true ;
V_5 -> V_18 . V_15 = V_15 ;
F_12 ( V_5 ) ;
if ( V_15 ) {
struct V_335 V_336 ;
V_29 = F_300 ( V_5 -> V_3 , & V_336 ) ;
if ( ! V_29 ) {
V_5 -> V_18 . V_326 = F_301 ( & V_336 ) ;
V_5 -> V_18 . V_328 = V_336 . V_328 ;
goto V_337;
}
}
V_5 -> V_18 . V_326 = 0 ;
V_5 -> V_18 . V_328 = 0 ;
V_337:
V_29 = F_293 ( V_5 -> V_14 , V_5 ) ;
if ( V_29 && V_29 != - V_334 )
F_298 ( V_5 -> V_14 -> V_3 , L_30 ,
V_5 -> V_3 -> V_22 , V_29 ) ;
}
static void F_168 ( struct V_14 * V_14 )
{
struct V_1 * V_5 ;
bool V_338 ;
if ( V_14 -> V_71 )
return;
V_338 = false ;
F_14 (port, &team->port_list, list) {
if ( V_5 -> V_15 ) {
V_338 = true ;
break;
}
}
if ( V_338 )
F_228 ( V_14 -> V_3 ) ;
else
F_185 ( V_14 -> V_3 ) ;
}
static void F_302 ( struct V_1 * V_5 , bool V_15 )
{
if ( V_5 -> V_18 . V_15 != V_15 )
F_299 ( V_5 , V_15 ) ;
F_168 ( V_5 -> V_14 ) ;
}
static void F_144 ( struct V_1 * V_5 , bool V_15 )
{
F_299 ( V_5 , V_15 ) ;
F_168 ( V_5 -> V_14 ) ;
}
static void F_152 ( struct V_1 * V_5 )
{
V_5 -> V_35 = true ;
F_299 ( V_5 , false ) ;
F_168 ( V_5 -> V_14 ) ;
}
static void F_303 ( struct V_1 * V_5 , bool V_15 )
{
struct V_14 * V_14 = V_5 -> V_14 ;
F_121 ( & V_14 -> V_136 ) ;
F_302 ( V_5 , V_15 ) ;
F_122 ( & V_14 -> V_136 ) ;
}
static int F_304 ( struct V_339 * V_171 ,
unsigned long V_340 , void * V_279 )
{
struct V_2 * V_3 = F_305 ( V_279 ) ;
struct V_1 * V_5 ;
V_5 = F_3 ( V_3 ) ;
if ( ! V_5 )
return V_341 ;
switch ( V_340 ) {
case V_342 :
if ( F_145 ( V_3 ) )
F_303 ( V_5 , true ) ;
break;
case V_343 :
F_303 ( V_5 , false ) ;
break;
case V_344 :
if ( F_74 ( V_5 -> V_3 ) )
F_303 ( V_5 ,
! ! F_145 ( V_5 -> V_3 ) ) ;
break;
case V_345 :
F_224 ( V_5 -> V_14 -> V_3 , V_3 ) ;
break;
case V_346 :
F_120 ( V_5 -> V_14 ) ;
break;
case V_347 :
if ( ! V_5 -> V_14 -> V_200 )
return V_348 ;
break;
case V_221 :
return V_348 ;
case V_91 :
F_71 ( V_340 , V_5 -> V_14 -> V_3 ) ;
break;
}
return V_341 ;
}
static int T_12 F_306 ( void )
{
int V_29 ;
F_307 ( & V_349 ) ;
V_29 = F_308 ( & V_350 ) ;
if ( V_29 )
goto V_351;
V_29 = F_294 () ;
if ( V_29 )
goto V_352;
return 0 ;
V_352:
F_309 ( & V_350 ) ;
V_351:
F_310 ( & V_349 ) ;
return V_29 ;
}
static void T_13 F_311 ( void )
{
F_296 () ;
F_309 ( & V_350 ) ;
F_310 ( & V_349 ) ;
}
