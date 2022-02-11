static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 -> V_5 ) ;
return F_3 ( V_3 ) ? V_4 : NULL ;
}
static struct V_1 * F_4 ( const struct V_2 * V_3 )
{
struct V_1 * V_4 = F_5 ( V_3 -> V_5 ) ;
return F_3 ( V_3 ) ? V_4 : NULL ;
}
static int F_6 ( struct V_2 * V_6 ,
const unsigned char * V_7 )
{
struct V_8 V_9 ;
memcpy ( V_9 . V_10 , V_7 , V_6 -> V_11 ) ;
V_9 . V_12 = V_6 -> type ;
return F_7 ( V_6 , & V_9 ) ;
}
static int F_8 ( struct V_1 * V_4 )
{
return F_6 ( V_4 -> V_3 , V_4 -> V_13 . V_7 ) ;
}
static int F_9 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
return F_6 ( V_4 -> V_3 , V_14 -> V_3 -> V_7 ) ;
}
int F_10 ( struct V_14 * V_14 , struct V_1 * V_4 )
{
return F_9 ( V_14 , V_4 ) ;
}
void F_11 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
F_9 ( V_14 , V_4 ) ;
}
static void F_12 ( struct V_1 * V_4 )
{
V_4 -> V_15 = V_4 -> V_16 . V_17 ? V_4 -> V_16 . V_15 :
V_4 -> V_18 . V_15 ;
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
struct V_1 * V_4 )
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
V_24 -> V_32 . V_4 = V_4 ;
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
struct V_1 * V_4 ;
int V_29 ;
if ( ! V_21 -> V_38 ) {
V_29 = F_20 ( V_14 , V_21 , NULL ) ;
if ( V_29 )
goto V_39;
}
F_14 (port, &team->port_list, list) {
V_29 = F_20 ( V_14 , V_21 , V_4 ) ;
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
struct V_1 * V_4 )
{
struct V_23 * V_24 , * V_26 ;
F_19 (opt_inst, tmp, &team->option_inst_list, list) {
if ( V_24 -> V_21 -> V_38 &&
V_24 -> V_32 . V_4 == V_4 )
F_15 ( V_24 ) ;
}
}
static int F_26 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
struct V_19 * V_21 ;
int V_29 ;
F_14 (option, &team->option_list, list) {
if ( ! V_21 -> V_38 )
continue;
V_29 = F_20 ( V_14 , V_21 , V_4 ) ;
if ( V_29 )
goto V_40;
}
return 0 ;
V_40:
F_25 ( V_14 , V_4 ) ;
return V_29 ;
}
static void F_27 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
struct V_23 * V_24 ;
F_14 (opt_inst, &team->option_inst_list, list) {
if ( V_24 -> V_32 . V_4 == V_4 ) {
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
struct V_1 * V_4 ,
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
V_14 = F_39 ( V_82 , struct V_14 , V_83 . V_84 . V_82 ) ;
if ( ! F_67 () ) {
F_68 ( & V_14 -> V_83 . V_84 , 0 ) ;
return;
}
F_69 ( V_85 , V_14 -> V_3 ) ;
F_70 () ;
if ( ! F_71 ( & V_14 -> V_83 . V_86 ) )
F_68 ( & V_14 -> V_83 . V_84 ,
F_72 ( V_14 -> V_83 . V_87 ) ) ;
}
static void F_73 ( struct V_14 * V_14 )
{
if ( ! V_14 -> V_83 . V_88 || ! F_74 ( V_14 -> V_3 ) )
return;
F_75 ( V_14 -> V_83 . V_88 , & V_14 -> V_83 . V_86 ) ;
F_68 ( & V_14 -> V_83 . V_84 , 0 ) ;
}
static void F_76 ( struct V_14 * V_14 )
{
F_77 ( & V_14 -> V_83 . V_84 , F_66 ) ;
}
static void F_78 ( struct V_14 * V_14 )
{
F_79 ( & V_14 -> V_83 . V_84 ) ;
}
static void F_80 ( struct V_81 * V_82 )
{
struct V_14 * V_14 ;
V_14 = F_39 ( V_82 , struct V_14 , V_89 . V_84 . V_82 ) ;
if ( ! F_67 () ) {
F_68 ( & V_14 -> V_89 . V_84 , 0 ) ;
return;
}
F_69 ( V_90 , V_14 -> V_3 ) ;
F_70 () ;
if ( ! F_71 ( & V_14 -> V_89 . V_86 ) )
F_68 ( & V_14 -> V_89 . V_84 ,
F_72 ( V_14 -> V_89 . V_87 ) ) ;
}
static void F_81 ( struct V_14 * V_14 )
{
if ( ! V_14 -> V_89 . V_88 || ! F_74 ( V_14 -> V_3 ) )
return;
F_75 ( V_14 -> V_89 . V_88 , & V_14 -> V_89 . V_86 ) ;
F_68 ( & V_14 -> V_89 . V_84 , 0 ) ;
}
static void F_82 ( struct V_14 * V_14 )
{
F_77 ( & V_14 -> V_89 . V_84 , F_80 ) ;
}
static void F_83 ( struct V_14 * V_14 )
{
F_79 ( & V_14 -> V_89 . V_84 ) ;
}
static T_2 F_84 ( struct V_67 * * V_91 )
{
struct V_67 * V_68 = * V_91 ;
struct V_1 * V_4 ;
struct V_14 * V_14 ;
T_2 V_92 ;
V_68 = F_85 ( V_68 , V_93 ) ;
if ( ! V_68 )
return V_94 ;
* V_91 = V_68 ;
V_4 = F_1 ( V_68 -> V_3 ) ;
V_14 = V_4 -> V_14 ;
if ( ! F_86 ( V_4 ) ) {
V_92 = V_95 ;
} else {
V_92 = V_14 -> V_73 . V_75 ( V_14 , V_4 , V_68 ) ;
}
if ( V_92 == V_69 ) {
struct V_96 * V_97 ;
V_97 = F_87 ( V_14 -> V_97 ) ;
F_88 ( & V_97 -> V_98 ) ;
V_97 -> V_99 ++ ;
V_97 -> V_100 += V_68 -> V_101 ;
if ( V_68 -> V_102 == V_103 )
V_97 -> V_104 ++ ;
F_89 ( & V_97 -> V_98 ) ;
V_68 -> V_3 = V_14 -> V_3 ;
} else {
F_90 ( V_14 -> V_97 -> V_105 ) ;
}
return V_92 ;
}
static int F_91 ( struct V_14 * V_14 )
{
struct V_106 * V_107 ;
unsigned int V_108 = V_14 -> V_3 -> V_109 - 1 ;
unsigned int V_28 ;
if ( ! V_108 )
return 0 ;
V_107 = F_21 ( sizeof( struct V_106 ) * V_108 , V_30 ) ;
if ( ! V_107 )
return - V_31 ;
V_14 -> V_110 = V_107 ;
for ( V_28 = 0 ; V_28 < V_108 ; V_28 ++ )
F_92 ( V_107 ++ ) ;
return 0 ;
}
static void F_93 ( struct V_14 * V_14 )
{
F_17 ( V_14 -> V_110 ) ;
}
static struct V_106 * F_94 ( struct V_14 * V_14 , T_3 V_111 )
{
return & V_14 -> V_110 [ V_111 - 1 ] ;
}
static bool F_95 ( struct V_14 * V_14 , struct V_67 * V_68 )
{
struct V_106 * V_112 ;
struct V_1 * V_4 ;
if ( ! V_14 -> V_113 || ! V_68 -> V_114 )
return false ;
V_112 = F_94 ( V_14 , V_68 -> V_114 ) ;
F_96 (port, qom_list, qom_list) {
if ( ! F_97 ( V_14 , V_4 , V_68 ) )
return true ;
}
return false ;
}
static void F_98 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
if ( ! V_4 -> V_111 )
return;
F_99 ( & V_4 -> V_112 ) ;
}
static bool F_100 ( struct V_1 * V_4 ,
struct V_1 * V_115 )
{
if ( V_4 -> V_116 < V_115 -> V_116 )
return true ;
if ( V_4 -> V_116 > V_115 -> V_116 )
return false ;
if ( V_4 -> V_117 < V_115 -> V_117 )
return true ;
return false ;
}
static void F_101 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
struct V_1 * V_115 ;
struct V_106 * V_112 ;
struct V_106 * V_118 ;
if ( ! V_4 -> V_111 )
return;
V_112 = F_94 ( V_14 , V_4 -> V_111 ) ;
V_118 = V_112 ;
F_14 (cur, qom_list, qom_list) {
if ( F_100 ( V_4 , V_115 ) )
break;
V_118 = & V_115 -> V_112 ;
}
F_102 ( & V_4 -> V_112 , V_118 ) ;
}
static void F_103 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
bool V_119 = false ;
F_14 (port, &team->port_list, list) {
if ( V_4 -> V_111 ) {
V_119 = true ;
break;
}
}
if ( V_119 == V_14 -> V_113 )
return;
F_104 ( V_14 -> V_3 , L_7 ,
V_119 ? L_8 : L_9 ) ;
V_14 -> V_113 = V_119 ;
}
static void F_105 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
if ( ! V_4 -> V_111 || F_86 ( V_4 ) )
return;
F_98 ( V_14 , V_4 ) ;
F_101 ( V_14 , V_4 ) ;
F_103 ( V_14 ) ;
}
static void F_106 ( struct V_14 * V_14 ,
struct V_1 * V_4 ,
T_3 V_120 )
{
if ( F_86 ( V_4 ) ) {
F_98 ( V_14 , V_4 ) ;
V_4 -> V_111 = V_120 ;
F_101 ( V_14 , V_4 ) ;
F_103 ( V_14 ) ;
} else {
V_4 -> V_111 = V_120 ;
}
}
static void F_107 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
F_101 ( V_14 , V_4 ) ;
F_103 ( V_14 ) ;
}
static void F_108 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
F_98 ( V_14 , V_4 ) ;
F_103 ( V_14 ) ;
}
static bool F_109 ( const struct V_14 * V_14 ,
const struct V_1 * V_4 )
{
struct V_1 * V_115 ;
F_14 (cur, &team->port_list, list)
if ( V_115 == V_4 )
return true ;
return false ;
}
static void F_110 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
if ( F_86 ( V_4 ) )
return;
V_4 -> V_117 = V_14 -> V_72 ++ ;
F_111 ( & V_4 -> V_121 ,
F_112 ( V_14 , V_4 -> V_117 ) ) ;
F_58 ( V_14 ) ;
F_107 ( V_14 , V_4 ) ;
if ( V_14 -> V_73 . V_122 )
V_14 -> V_73 . V_122 ( V_14 , V_4 ) ;
F_73 ( V_14 ) ;
F_81 ( V_14 ) ;
}
static void F_113 ( struct V_14 * V_14 , int V_123 )
{
int V_28 ;
struct V_1 * V_4 ;
for ( V_28 = V_123 + 1 ; V_28 < V_14 -> V_72 ; V_28 ++ ) {
V_4 = F_114 ( V_14 , V_28 ) ;
F_115 ( & V_4 -> V_121 ) ;
V_4 -> V_117 -- ;
F_111 ( & V_4 -> V_121 ,
F_112 ( V_14 , V_4 -> V_117 ) ) ;
}
}
static void F_116 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
if ( ! F_86 ( V_4 ) )
return;
if ( V_14 -> V_73 . V_124 )
V_14 -> V_73 . V_124 ( V_14 , V_4 ) ;
F_115 ( & V_4 -> V_121 ) ;
F_113 ( V_14 , V_4 -> V_117 ) ;
V_4 -> V_117 = - 1 ;
V_14 -> V_72 -- ;
F_108 ( V_14 , V_4 ) ;
F_58 ( V_14 ) ;
F_73 ( V_14 ) ;
F_81 ( V_14 ) ;
}
static void F_117 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
T_4 V_125 = V_126 & V_127 ;
unsigned short V_128 = V_129 ;
unsigned int V_130 = V_131 |
V_132 ;
F_14 (port, &team->port_list, list) {
V_125 = F_118 ( V_125 ,
V_4 -> V_3 -> V_125 ,
V_126 ) ;
V_130 &= V_4 -> V_3 -> V_133 ;
if ( V_4 -> V_3 -> V_134 > V_128 )
V_128 = V_4 -> V_3 -> V_134 ;
}
V_14 -> V_3 -> V_125 = V_125 ;
V_14 -> V_3 -> V_134 = V_128 ;
V_14 -> V_3 -> V_133 &= ~ V_131 ;
if ( V_130 == ( V_131 | V_132 ) )
V_14 -> V_3 -> V_133 |= V_131 ;
F_119 ( V_14 -> V_3 ) ;
}
static void F_120 ( struct V_14 * V_14 )
{
F_121 ( & V_14 -> V_135 ) ;
F_117 ( V_14 ) ;
F_122 ( & V_14 -> V_135 ) ;
}
static int F_123 ( struct V_14 * V_14 , struct V_1 * V_4 )
{
int V_29 = 0 ;
F_124 ( V_14 -> V_3 ) ;
if ( V_14 -> V_73 . V_136 ) {
V_29 = V_14 -> V_73 . V_136 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_64 ( V_14 -> V_3 , L_10 ,
V_4 -> V_3 -> V_22 ) ;
goto V_137;
}
}
return 0 ;
V_137:
F_125 ( V_14 -> V_3 ) ;
return V_29 ;
}
static void F_126 ( struct V_14 * V_14 , struct V_1 * V_4 )
{
if ( V_14 -> V_73 . V_138 )
V_14 -> V_73 . V_138 ( V_14 , V_4 ) ;
F_125 ( V_14 -> V_3 ) ;
}
static int F_127 ( struct V_14 * V_14 , struct V_1 * V_4 )
{
struct V_139 * V_140 ;
int V_29 ;
if ( ! V_14 -> V_3 -> V_141 )
return 0 ;
V_140 = F_29 ( sizeof( * V_140 ) , V_30 ) ;
if ( ! V_140 )
return - V_31 ;
V_29 = F_128 ( V_140 , V_4 -> V_3 ) ;
if ( V_29 ) {
F_17 ( V_140 ) ;
return V_29 ;
}
V_4 -> V_140 = V_140 ;
return V_29 ;
}
static void F_129 ( struct V_1 * V_4 )
{
struct V_139 * V_140 = V_4 -> V_140 ;
if ( ! V_140 )
return;
V_4 -> V_140 = NULL ;
F_130 () ;
F_131 ( V_140 ) ;
F_17 ( V_140 ) ;
}
static int F_127 ( struct V_14 * V_14 , struct V_1 * V_4 )
{
return 0 ;
}
static void F_129 ( struct V_1 * V_4 )
{
}
static int F_132 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
int V_29 ;
V_29 = F_133 ( V_6 , V_3 ) ;
if ( V_29 )
return V_29 ;
V_6 -> V_133 |= V_142 ;
return 0 ;
}
static void F_134 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
F_135 ( V_6 , V_3 ) ;
V_6 -> V_133 &= ~ V_142 ;
}
static int F_136 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_4 ;
char * V_143 = V_6 -> V_22 ;
int V_29 ;
if ( V_6 -> V_144 & V_145 ) {
F_64 ( V_3 , L_11 ,
V_143 ) ;
return - V_62 ;
}
if ( F_3 ( V_6 ) ) {
F_64 ( V_3 , L_12
L_13 , V_143 ) ;
return - V_80 ;
}
if ( V_6 -> V_146 & V_147 &&
F_137 ( V_3 ) ) {
F_64 ( V_3 , L_14 ,
V_143 ) ;
return - V_148 ;
}
V_29 = F_138 ( V_3 , V_6 ) ;
if ( V_29 )
return V_29 ;
if ( V_6 -> V_144 & V_149 ) {
F_64 ( V_3 , L_15 ,
V_143 ) ;
return - V_80 ;
}
V_4 = F_29 ( sizeof( struct V_1 ) + V_14 -> V_58 -> V_150 ,
V_30 ) ;
if ( ! V_4 )
return - V_31 ;
V_4 -> V_3 = V_6 ;
V_4 -> V_14 = V_14 ;
F_92 ( & V_4 -> V_112 ) ;
V_4 -> V_13 . V_151 = V_6 -> V_151 ;
V_29 = F_139 ( V_6 , V_3 -> V_151 ) ;
if ( V_29 ) {
F_104 ( V_3 , L_16 , V_29 ) ;
goto V_152;
}
memcpy ( V_4 -> V_13 . V_7 , V_6 -> V_7 , V_6 -> V_11 ) ;
V_29 = F_123 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_10 ,
V_143 ) ;
goto V_137;
}
V_29 = F_140 ( V_6 ) ;
if ( V_29 ) {
F_104 ( V_3 , L_17 ,
V_143 ) ;
goto V_153;
}
V_29 = F_141 ( V_6 , V_3 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_18 ,
V_143 ) ;
goto V_154;
}
V_29 = F_127 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_19 ,
V_143 ) ;
goto V_155;
}
V_29 = F_142 ( V_6 , F_84 ,
V_4 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_20 ,
V_143 ) ;
goto V_156;
}
V_29 = F_132 ( V_3 , V_6 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_21 ,
V_143 ) ;
goto V_157;
}
V_29 = F_26 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_22 ,
V_143 ) ;
goto V_158;
}
V_4 -> V_117 = - 1 ;
F_102 ( & V_4 -> V_25 , & V_14 -> V_79 ) ;
F_110 ( V_14 , V_4 ) ;
F_117 ( V_14 ) ;
F_143 ( V_4 , ! ! F_144 ( V_6 ) ) ;
F_34 ( V_14 ) ;
F_65 ( V_3 , L_23 , V_143 ) ;
return 0 ;
V_158:
F_134 ( V_3 , V_6 ) ;
V_157:
F_145 ( V_6 ) ;
V_156:
F_129 ( V_4 ) ;
V_155:
F_146 ( V_6 , V_3 ) ;
V_154:
F_147 ( V_6 ) ;
V_153:
F_126 ( V_14 , V_4 ) ;
F_8 ( V_4 ) ;
V_137:
F_139 ( V_6 , V_4 -> V_13 . V_151 ) ;
V_152:
F_17 ( V_4 ) ;
return V_29 ;
}
static int F_148 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_4 ;
char * V_143 = V_6 -> V_22 ;
V_4 = F_4 ( V_6 ) ;
if ( ! V_4 || ! F_109 ( V_14 , V_4 ) ) {
F_64 ( V_3 , L_24 ,
V_143 ) ;
return - V_159 ;
}
F_116 ( V_14 , V_4 ) ;
F_99 ( & V_4 -> V_25 ) ;
F_134 ( V_3 , V_6 ) ;
F_145 ( V_6 ) ;
F_129 ( V_4 ) ;
F_146 ( V_6 , V_3 ) ;
F_149 ( V_6 , V_3 ) ;
F_150 ( V_6 , V_3 ) ;
F_147 ( V_6 ) ;
F_126 ( V_14 , V_4 ) ;
F_27 ( V_14 , V_4 ) ;
F_34 ( V_14 ) ;
F_25 ( V_14 , V_4 ) ;
F_151 ( V_4 ) ;
F_8 ( V_4 ) ;
F_139 ( V_6 , V_4 -> V_13 . V_151 ) ;
F_152 ( V_4 , V_160 ) ;
F_65 ( V_3 , L_25 , V_143 ) ;
F_117 ( V_14 ) ;
return 0 ;
}
static int F_153 ( struct V_14 * V_14 , struct V_48 * V_49 )
{
V_49 -> V_161 . V_162 = V_14 -> V_58 -> V_56 ;
return 0 ;
}
static int F_154 ( struct V_14 * V_14 , struct V_48 * V_49 )
{
return F_62 ( V_14 , V_49 -> V_161 . V_162 ) ;
}
static int F_155 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_49 -> V_161 . V_163 = V_14 -> V_83 . V_88 ;
return 0 ;
}
static int F_156 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_14 -> V_83 . V_88 = V_49 -> V_161 . V_163 ;
return 0 ;
}
static int F_157 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_49 -> V_161 . V_163 = V_14 -> V_83 . V_87 ;
return 0 ;
}
static int F_158 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_14 -> V_83 . V_87 = V_49 -> V_161 . V_163 ;
return 0 ;
}
static int F_159 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_49 -> V_161 . V_163 = V_14 -> V_89 . V_88 ;
return 0 ;
}
static int F_160 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_14 -> V_89 . V_88 = V_49 -> V_161 . V_163 ;
return 0 ;
}
static int F_161 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_49 -> V_161 . V_163 = V_14 -> V_89 . V_87 ;
return 0 ;
}
static int F_162 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_14 -> V_89 . V_87 = V_49 -> V_161 . V_163 ;
return 0 ;
}
static int F_163 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_161 . V_164 = F_86 ( V_4 ) ;
return 0 ;
}
static int F_164 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
if ( V_49 -> V_161 . V_164 )
F_110 ( V_14 , V_4 ) ;
else
F_116 ( V_14 , V_4 ) ;
return 0 ;
}
static int F_165 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_161 . V_164 = V_4 -> V_16 . V_15 ;
return 0 ;
}
static int F_166 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_4 -> V_16 . V_15 = V_49 -> V_161 . V_164 ;
F_12 ( V_4 ) ;
F_167 ( V_4 -> V_14 ) ;
return 0 ;
}
static int F_168 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_161 . V_164 = V_4 -> V_16 . V_17 ;
return 0 ;
}
static int F_169 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_4 -> V_16 . V_17 = V_49 -> V_161 . V_164 ;
F_12 ( V_4 ) ;
F_167 ( V_4 -> V_14 ) ;
return 0 ;
}
static int F_170 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_161 . V_165 = V_4 -> V_116 ;
return 0 ;
}
static int F_171 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
T_5 V_116 = V_49 -> V_161 . V_165 ;
if ( V_4 -> V_116 == V_116 )
return 0 ;
V_4 -> V_116 = V_116 ;
F_105 ( V_14 , V_4 ) ;
return 0 ;
}
static int F_172 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_161 . V_163 = V_4 -> V_111 ;
return 0 ;
}
static int F_173 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
T_3 V_120 = V_49 -> V_161 . V_163 ;
if ( V_4 -> V_111 == V_120 )
return 0 ;
if ( V_120 >= V_14 -> V_3 -> V_166 )
return - V_62 ;
F_106 ( V_14 , V_4 , V_120 ) ;
return 0 ;
}
static void F_174 ( struct V_2 * V_3 ,
struct V_167 * V_168 ,
void * V_169 )
{
F_175 ( & V_168 -> V_170 , & V_171 ) ;
}
static void F_176 ( struct V_2 * V_3 )
{
F_175 ( & V_3 -> V_172 , & V_173 ) ;
F_177 ( V_3 , F_174 , NULL ) ;
V_3 -> V_174 = & V_175 ;
}
static int F_178 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_179 ( V_3 ) ;
int V_28 ;
int V_29 ;
V_14 -> V_3 = V_3 ;
F_180 ( & V_14 -> V_135 ) ;
F_57 ( V_14 ) ;
V_14 -> V_97 = F_181 ( struct V_96 ) ;
if ( ! V_14 -> V_97 )
return - V_31 ;
for ( V_28 = 0 ; V_28 < V_176 ; V_28 ++ )
F_182 ( & V_14 -> V_177 [ V_28 ] ) ;
F_92 ( & V_14 -> V_79 ) ;
V_29 = F_91 ( V_14 ) ;
if ( V_29 )
goto V_178;
F_58 ( V_14 ) ;
F_92 ( & V_14 -> V_46 ) ;
F_92 ( & V_14 -> V_36 ) ;
F_76 ( V_14 ) ;
F_82 ( V_14 ) ;
V_29 = F_33 ( V_14 , V_179 , F_183 ( V_179 ) ) ;
if ( V_29 )
goto V_180;
F_184 ( V_3 ) ;
F_176 ( V_3 ) ;
return 0 ;
V_180:
F_83 ( V_14 ) ;
F_78 ( V_14 ) ;
F_93 ( V_14 ) ;
V_178:
F_185 ( V_14 -> V_97 ) ;
return V_29 ;
}
static void F_186 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_179 ( V_3 ) ;
struct V_1 * V_4 ;
struct V_1 * V_26 ;
F_121 ( & V_14 -> V_135 ) ;
F_19 (port, tmp, &team->port_list, list)
F_148 ( V_14 , V_4 -> V_3 ) ;
F_59 ( V_14 , NULL ) ;
F_32 ( V_14 , V_179 , F_183 ( V_179 ) ) ;
F_83 ( V_14 ) ;
F_78 ( V_14 ) ;
F_93 ( V_14 ) ;
F_122 ( & V_14 -> V_135 ) ;
}
static void F_187 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_179 ( V_3 ) ;
F_185 ( V_14 -> V_97 ) ;
F_188 ( V_3 ) ;
}
static int F_189 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_190 ( struct V_2 * V_3 )
{
return 0 ;
}
static T_6 F_191 ( struct V_67 * V_68 , struct V_2 * V_3 )
{
struct V_14 * V_14 = F_179 ( V_3 ) ;
bool V_181 ;
unsigned int V_101 = V_68 -> V_101 ;
V_181 = F_95 ( V_14 , V_68 ) ;
if ( ! V_181 )
V_181 = V_14 -> V_73 . V_74 ( V_14 , V_68 ) ;
if ( V_181 ) {
struct V_96 * V_97 ;
V_97 = F_87 ( V_14 -> V_97 ) ;
F_88 ( & V_97 -> V_98 ) ;
V_97 -> V_182 ++ ;
V_97 -> V_183 += V_101 ;
F_89 ( & V_97 -> V_98 ) ;
} else {
F_90 ( V_14 -> V_97 -> V_184 ) ;
}
return V_185 ;
}
static T_3 F_192 ( struct V_2 * V_3 , struct V_67 * V_68 ,
void * V_186 , T_7 V_187 )
{
T_3 V_168 = F_193 ( V_68 ) ? F_194 ( V_68 ) : 0 ;
F_195 ( V_68 ) -> V_188 = V_68 -> V_114 ;
if ( F_196 ( V_168 >= V_3 -> V_166 ) ) {
do {
V_168 -= V_3 -> V_166 ;
} while ( V_168 >= V_3 -> V_166 );
}
return V_168 ;
}
static void F_197 ( struct V_2 * V_3 , int V_189 )
{
struct V_14 * V_14 = F_179 ( V_3 ) ;
struct V_1 * V_4 ;
int V_190 ;
F_198 () ;
F_96 (port, &team->port_list, list) {
if ( V_189 & V_191 ) {
V_190 = V_3 -> V_144 & V_191 ? 1 : - 1 ;
F_199 ( V_4 -> V_3 , V_190 ) ;
}
if ( V_189 & V_192 ) {
V_190 = V_3 -> V_144 & V_192 ? 1 : - 1 ;
F_200 ( V_4 -> V_3 , V_190 ) ;
}
}
F_201 () ;
}
static void F_202 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_179 ( V_3 ) ;
struct V_1 * V_4 ;
F_198 () ;
F_96 (port, &team->port_list, list) {
F_203 ( V_4 -> V_3 , V_3 ) ;
F_204 ( V_4 -> V_3 , V_3 ) ;
}
F_201 () ;
}
static int F_205 ( struct V_2 * V_3 , void * V_193 )
{
struct V_8 * V_9 = V_193 ;
struct V_14 * V_14 = F_179 ( V_3 ) ;
struct V_1 * V_4 ;
if ( V_3 -> type == V_194 && ! F_206 ( V_9 -> V_10 ) )
return - V_195 ;
memcpy ( V_3 -> V_7 , V_9 -> V_10 , V_3 -> V_11 ) ;
F_198 () ;
F_96 (port, &team->port_list, list)
if ( V_14 -> V_73 . V_196 )
V_14 -> V_73 . V_196 ( V_14 , V_4 ) ;
F_201 () ;
return 0 ;
}
static int F_207 ( struct V_2 * V_3 , int V_197 )
{
struct V_14 * V_14 = F_179 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 ;
F_121 ( & V_14 -> V_135 ) ;
V_14 -> V_198 = true ;
F_14 (port, &team->port_list, list) {
V_29 = F_139 ( V_4 -> V_3 , V_197 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_26 ,
V_4 -> V_3 -> V_22 ) ;
goto V_199;
}
}
V_14 -> V_198 = false ;
F_122 ( & V_14 -> V_135 ) ;
V_3 -> V_151 = V_197 ;
return 0 ;
V_199:
F_208 (port, &team->port_list, list)
F_139 ( V_4 -> V_3 , V_3 -> V_151 ) ;
V_14 -> V_198 = false ;
F_122 ( & V_14 -> V_135 ) ;
return V_29 ;
}
static struct V_200 *
F_209 ( struct V_2 * V_3 , struct V_200 * V_201 )
{
struct V_14 * V_14 = F_179 ( V_3 ) ;
struct V_96 * V_193 ;
T_8 V_99 , V_100 , V_104 , V_182 , V_183 ;
T_4 V_105 = 0 , V_184 = 0 ;
unsigned int V_202 ;
int V_28 ;
F_210 (i) {
V_193 = F_211 ( V_14 -> V_97 , V_28 ) ;
do {
V_202 = F_212 ( & V_193 -> V_98 ) ;
V_99 = V_193 -> V_99 ;
V_100 = V_193 -> V_100 ;
V_104 = V_193 -> V_104 ;
V_182 = V_193 -> V_182 ;
V_183 = V_193 -> V_183 ;
} while ( F_213 ( & V_193 -> V_98 , V_202 ) );
V_201 -> V_99 += V_99 ;
V_201 -> V_100 += V_100 ;
V_201 -> V_203 += V_104 ;
V_201 -> V_182 += V_182 ;
V_201 -> V_183 += V_183 ;
V_105 += V_193 -> V_105 ;
V_184 += V_193 -> V_184 ;
}
V_201 -> V_105 = V_105 ;
V_201 -> V_184 = V_184 ;
return V_201 ;
}
static int F_214 ( struct V_2 * V_3 , T_9 V_204 , T_3 V_205 )
{
struct V_14 * V_14 = F_179 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 ;
F_121 ( & V_14 -> V_135 ) ;
F_14 (port, &team->port_list, list) {
V_29 = F_215 ( V_4 -> V_3 , V_204 , V_205 ) ;
if ( V_29 )
goto V_199;
}
F_122 ( & V_14 -> V_135 ) ;
return 0 ;
V_199:
F_208 (port, &team->port_list, list)
F_216 ( V_4 -> V_3 , V_204 , V_205 ) ;
F_122 ( & V_14 -> V_135 ) ;
return V_29 ;
}
static int F_217 ( struct V_2 * V_3 , T_9 V_204 , T_3 V_205 )
{
struct V_14 * V_14 = F_179 ( V_3 ) ;
struct V_1 * V_4 ;
F_198 () ;
F_96 (port, &team->port_list, list)
F_216 ( V_4 -> V_3 , V_204 , V_205 ) ;
F_201 () ;
return 0 ;
}
static void F_218 ( struct V_2 * V_3 )
{
}
static void F_219 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
F_14 (port, &team->port_list, list)
F_129 ( V_4 ) ;
}
static void F_220 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_179 ( V_3 ) ;
F_121 ( & V_14 -> V_135 ) ;
F_219 ( V_14 ) ;
F_122 ( & V_14 -> V_135 ) ;
}
static int F_221 ( struct V_2 * V_3 ,
struct V_206 * V_207 )
{
struct V_14 * V_14 = F_179 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 = 0 ;
F_121 ( & V_14 -> V_135 ) ;
F_14 (port, &team->port_list, list) {
V_29 = F_127 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_219 ( V_14 ) ;
break;
}
}
F_122 ( & V_14 -> V_135 ) ;
return V_29 ;
}
static int F_222 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_179 ( V_3 ) ;
int V_29 ;
F_121 ( & V_14 -> V_135 ) ;
V_29 = F_136 ( V_14 , V_6 ) ;
F_122 ( & V_14 -> V_135 ) ;
return V_29 ;
}
static int F_223 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_179 ( V_3 ) ;
int V_29 ;
F_121 ( & V_14 -> V_135 ) ;
V_29 = F_148 ( V_14 , V_6 ) ;
F_122 ( & V_14 -> V_135 ) ;
return V_29 ;
}
static T_10 F_224 ( struct V_2 * V_3 ,
T_10 V_146 )
{
struct V_1 * V_4 ;
struct V_14 * V_14 = F_179 ( V_3 ) ;
T_10 V_208 ;
V_208 = V_146 ;
V_146 &= ~ V_209 ;
V_146 |= V_127 ;
F_198 () ;
F_96 (port, &team->port_list, list) {
V_146 = F_118 ( V_146 ,
V_4 -> V_3 -> V_146 ,
V_208 ) ;
}
F_201 () ;
return V_146 ;
}
static int F_225 ( struct V_2 * V_3 , bool V_210 )
{
struct V_14 * V_14 = F_179 ( V_3 ) ;
V_14 -> V_71 = true ;
if ( V_210 )
F_226 ( V_3 ) ;
else
F_184 ( V_3 ) ;
return 0 ;
}
static void F_227 ( struct V_2 * V_3 ,
struct V_211 * V_212 )
{
F_228 ( V_212 -> V_213 , V_214 , sizeof( V_212 -> V_213 ) ) ;
F_228 ( V_212 -> V_215 , V_216 , sizeof( V_212 -> V_215 ) ) ;
}
static void F_229 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
V_3 -> V_217 = V_6 -> V_217 ;
V_3 -> type = V_6 -> type ;
V_3 -> V_134 = V_6 -> V_134 ;
V_3 -> V_11 = V_6 -> V_11 ;
V_3 -> V_151 = V_6 -> V_151 ;
memcpy ( V_3 -> V_218 , V_6 -> V_218 , V_6 -> V_11 ) ;
F_230 ( V_3 , V_6 ) ;
}
static int F_138 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
struct V_14 * V_14 = F_179 ( V_3 ) ;
char * V_143 = V_6 -> V_22 ;
int V_29 ;
if ( V_3 -> type == V_6 -> type )
return 0 ;
if ( ! F_63 ( & V_14 -> V_79 ) ) {
F_64 ( V_3 , L_27 , V_143 ) ;
return - V_80 ;
}
V_29 = F_69 ( V_219 , V_3 ) ;
V_29 = F_231 ( V_29 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_28 ) ;
return V_29 ;
}
F_232 ( V_3 ) ;
F_233 ( V_3 ) ;
F_229 ( V_3 , V_6 ) ;
F_69 ( V_220 , V_3 ) ;
return 0 ;
}
static void F_234 ( struct V_2 * V_3 )
{
F_235 ( V_3 ) ;
V_3 -> V_221 = & V_222 ;
V_3 -> V_223 = & V_224 ;
V_3 -> V_225 = F_187 ;
V_3 -> V_226 = 0 ;
V_3 -> V_144 |= V_227 ;
V_3 -> V_133 &= ~ ( V_131 | V_228 ) ;
V_3 -> V_133 |= V_229 | V_230 ;
V_3 -> V_146 |= V_231 ;
V_3 -> V_146 |= V_232 ;
V_3 -> V_146 |= V_233 ;
V_3 -> V_234 = V_126 |
V_235 |
V_236 |
V_237 ;
V_3 -> V_234 &= ~ ( V_238 & ~ V_239 ) ;
V_3 -> V_146 |= V_3 -> V_234 ;
}
static int F_236 ( struct V_240 * V_241 , struct V_2 * V_3 ,
struct V_242 * V_243 [] , struct V_242 * V_161 [] )
{
if ( V_243 [ V_244 ] == NULL )
F_237 ( V_3 ) ;
return F_238 ( V_3 ) ;
}
static int F_239 ( struct V_242 * V_243 [] , struct V_242 * V_161 [] )
{
if ( V_243 [ V_244 ] ) {
if ( F_240 ( V_243 [ V_244 ] ) != V_245 )
return - V_62 ;
if ( ! F_206 ( F_241 ( V_243 [ V_244 ] ) ) )
return - V_195 ;
}
return 0 ;
}
static unsigned int F_242 ( void )
{
return V_246 ;
}
static unsigned int F_243 ( void )
{
return V_247 ;
}
static int F_244 ( struct V_67 * V_68 , struct V_248 * V_32 )
{
struct V_67 * V_249 ;
void * V_250 ;
int V_29 ;
V_249 = F_245 ( V_251 , V_30 ) ;
if ( ! V_249 )
return - V_31 ;
V_250 = F_246 ( V_249 , V_32 -> V_252 , V_32 -> V_253 ,
& V_254 , 0 , V_255 ) ;
if ( ! V_250 ) {
V_29 = - V_256 ;
goto V_257;
}
F_247 ( V_249 , V_250 ) ;
return F_248 ( F_249 ( V_32 ) , V_249 , V_32 -> V_252 ) ;
V_257:
F_250 ( V_249 ) ;
return V_29 ;
}
static struct V_14 * F_251 ( struct V_248 * V_32 )
{
struct V_240 * V_240 = F_249 ( V_32 ) ;
int V_258 ;
struct V_2 * V_3 ;
struct V_14 * V_14 ;
if ( ! V_32 -> V_259 [ V_260 ] )
return NULL ;
V_258 = F_252 ( V_32 -> V_259 [ V_260 ] ) ;
V_3 = F_253 ( V_240 , V_258 ) ;
if ( ! V_3 || V_3 -> V_221 != & V_222 ) {
if ( V_3 )
F_125 ( V_3 ) ;
return NULL ;
}
V_14 = F_179 ( V_3 ) ;
F_121 ( & V_14 -> V_135 ) ;
return V_14 ;
}
static void F_254 ( struct V_14 * V_14 )
{
F_122 ( & V_14 -> V_135 ) ;
F_125 ( V_14 -> V_3 ) ;
}
static int F_255 ( struct V_67 * V_68 , struct V_14 * V_14 , T_4 V_261 )
{
return F_248 ( F_256 ( V_14 -> V_3 ) , V_68 , V_261 ) ;
}
static int F_257 ( struct V_67 * V_68 , struct V_14 * V_14 ,
struct V_23 * V_24 )
{
struct V_242 * V_262 ;
struct V_19 * V_21 = V_24 -> V_21 ;
struct V_53 * V_54 = & V_24 -> V_32 ;
struct V_48 V_49 ;
int V_29 ;
V_49 . V_32 = V_54 ;
V_29 = F_36 ( V_14 , V_24 , & V_49 ) ;
if ( V_29 )
return V_29 ;
V_262 = F_258 ( V_68 , V_263 ) ;
if ( ! V_262 )
return - V_256 ;
if ( F_259 ( V_68 , V_264 , V_21 -> V_22 ) )
goto V_265;
if ( V_54 -> V_4 &&
F_260 ( V_68 , V_266 ,
V_54 -> V_4 -> V_3 -> V_258 ) )
goto V_265;
if ( V_24 -> V_21 -> V_27 &&
F_260 ( V_68 , V_267 ,
V_54 -> V_33 ) )
goto V_265;
switch ( V_21 -> type ) {
case V_268 :
if ( F_261 ( V_68 , V_269 , V_270 ) )
goto V_265;
if ( F_260 ( V_68 , V_271 , V_49 . V_161 . V_163 ) )
goto V_265;
break;
case V_272 :
if ( F_261 ( V_68 , V_269 , V_273 ) )
goto V_265;
if ( F_259 ( V_68 , V_271 ,
V_49 . V_161 . V_162 ) )
goto V_265;
break;
case V_274 :
if ( F_261 ( V_68 , V_269 , V_275 ) )
goto V_265;
if ( F_262 ( V_68 , V_271 , V_49 . V_161 . V_276 . V_101 ,
V_49 . V_161 . V_276 . V_277 ) )
goto V_265;
break;
case V_278 :
if ( F_261 ( V_68 , V_269 , V_279 ) )
goto V_265;
if ( V_49 . V_161 . V_164 &&
F_263 ( V_68 , V_271 ) )
goto V_265;
break;
case V_280 :
if ( F_261 ( V_68 , V_269 , V_281 ) )
goto V_265;
if ( F_264 ( V_68 , V_271 , V_49 . V_161 . V_165 ) )
goto V_265;
break;
default:
F_265 () ;
}
if ( V_24 -> V_35 && F_263 ( V_68 , V_282 ) )
goto V_265;
if ( V_24 -> V_34 ) {
if ( F_263 ( V_68 , V_283 ) )
goto V_265;
V_24 -> V_34 = false ;
}
F_266 ( V_68 , V_262 ) ;
return 0 ;
V_265:
F_267 ( V_68 , V_262 ) ;
return - V_256 ;
}
static int F_268 ( struct V_67 * * V_91 ,
struct V_14 * V_14 , T_4 V_261 ,
T_11 * V_284 )
{
int V_29 ;
if ( * V_91 ) {
V_29 = V_284 ( * V_91 , V_14 , V_261 ) ;
if ( V_29 )
return V_29 ;
}
* V_91 = F_269 ( V_285 , V_30 ) ;
if ( ! * V_91 )
return - V_31 ;
return 0 ;
}
static int F_270 ( struct V_14 * V_14 , T_4 V_261 , T_4 V_286 ,
int V_144 , T_11 * V_284 ,
struct V_106 * V_287 )
{
struct V_242 * V_46 ;
struct V_288 * V_289 ;
void * V_250 ;
struct V_23 * V_24 ;
int V_29 ;
struct V_67 * V_68 = NULL ;
bool V_290 ;
int V_28 ;
V_24 = F_271 ( V_287 ,
struct V_23 , V_291 ) ;
V_292:
V_29 = F_268 ( & V_68 , V_14 , V_261 , V_284 ) ;
if ( V_29 )
return V_29 ;
V_250 = F_246 ( V_68 , V_261 , V_286 , & V_254 , V_144 | V_293 ,
V_294 ) ;
if ( ! V_250 )
return - V_256 ;
if ( F_260 ( V_68 , V_260 , V_14 -> V_3 -> V_258 ) )
goto V_295;
V_46 = F_258 ( V_68 , V_296 ) ;
if ( ! V_46 )
goto V_295;
V_28 = 0 ;
V_290 = false ;
F_272 (opt_inst, sel_opt_inst_list, tmp_list) {
V_29 = F_257 ( V_68 , V_14 , V_24 ) ;
if ( V_29 ) {
if ( V_29 == - V_256 ) {
if ( ! V_28 )
goto V_297;
V_290 = true ;
break;
}
goto V_297;
}
V_28 ++ ;
}
F_266 ( V_68 , V_46 ) ;
F_247 ( V_68 , V_250 ) ;
if ( V_290 )
goto V_292;
V_298:
V_289 = F_273 ( V_68 , V_261 , V_286 , V_299 , 0 , V_144 | V_293 ) ;
if ( ! V_289 ) {
V_29 = F_268 ( & V_68 , V_14 , V_261 , V_284 ) ;
if ( V_29 )
goto V_297;
goto V_298;
}
return V_284 ( V_68 , V_14 , V_261 ) ;
V_295:
V_29 = - V_256 ;
V_297:
F_274 ( V_68 , V_250 ) ;
F_250 ( V_68 ) ;
return V_29 ;
}
static int F_275 ( struct V_67 * V_68 , struct V_248 * V_32 )
{
struct V_14 * V_14 ;
struct V_23 * V_24 ;
int V_29 ;
F_276 ( V_287 ) ;
V_14 = F_251 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
F_14 (opt_inst, &team->option_inst_list, list)
F_22 ( & V_24 -> V_291 , & V_287 ) ;
V_29 = F_270 ( V_14 , V_32 -> V_252 , V_32 -> V_253 ,
V_300 , F_255 ,
& V_287 ) ;
F_254 ( V_14 ) ;
return V_29 ;
}
static int F_277 ( struct V_67 * V_68 , struct V_248 * V_32 )
{
struct V_14 * V_14 ;
int V_29 = 0 ;
int V_28 ;
struct V_242 * V_301 ;
F_276 ( V_302 ) ;
V_14 = F_251 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
V_29 = - V_62 ;
if ( ! V_32 -> V_259 [ V_296 ] ) {
V_29 = - V_62 ;
goto V_303;
}
F_278 (nl_option, info->attrs[TEAM_ATTR_LIST_OPTION], i) {
struct V_242 * V_304 [ V_305 + 1 ] ;
struct V_242 * V_306 ;
struct V_242 * V_307 ;
enum V_308 V_309 ;
int V_310 = 0 ;
T_4 V_311 = 0 ;
bool V_312 = false ;
struct V_23 * V_24 ;
char * V_20 ;
bool V_313 = false ;
if ( F_279 ( V_301 ) != V_263 ) {
V_29 = - V_62 ;
goto V_303;
}
V_29 = F_280 ( V_304 , V_305 ,
V_301 , V_314 ) ;
if ( V_29 )
goto V_303;
if ( ! V_304 [ V_264 ] ||
! V_304 [ V_269 ] ) {
V_29 = - V_62 ;
goto V_303;
}
switch ( F_281 ( V_304 [ V_269 ] ) ) {
case V_270 :
V_309 = V_268 ;
break;
case V_273 :
V_309 = V_272 ;
break;
case V_275 :
V_309 = V_274 ;
break;
case V_279 :
V_309 = V_278 ;
break;
case V_281 :
V_309 = V_280 ;
break;
default:
goto V_303;
}
V_307 = V_304 [ V_271 ] ;
if ( V_309 != V_278 && ! V_307 ) {
V_29 = - V_62 ;
goto V_303;
}
V_20 = F_241 ( V_304 [ V_264 ] ) ;
V_306 = V_304 [ V_266 ] ;
if ( V_306 )
V_310 = F_252 ( V_306 ) ;
V_306 = V_304 [ V_267 ] ;
if ( V_306 ) {
V_312 = true ;
V_311 = F_252 ( V_306 ) ;
}
F_14 (opt_inst, &team->option_inst_list, list) {
struct V_19 * V_21 = V_24 -> V_21 ;
struct V_48 V_49 ;
struct V_53 * V_54 ;
int V_315 ;
V_54 = & V_24 -> V_32 ;
V_315 = V_54 -> V_4 ?
V_54 -> V_4 -> V_3 -> V_258 : 0 ;
if ( V_21 -> type != V_309 ||
strcmp ( V_21 -> V_22 , V_20 ) ||
V_315 != V_310 ||
( V_21 -> V_27 && ! V_312 ) ||
V_54 -> V_33 != V_311 )
continue;
V_313 = true ;
V_49 . V_32 = V_54 ;
switch ( V_309 ) {
case V_268 :
V_49 . V_161 . V_163 = F_252 ( V_307 ) ;
break;
case V_272 :
if ( F_240 ( V_307 ) > V_316 ) {
V_29 = - V_62 ;
goto V_303;
}
V_49 . V_161 . V_162 = F_241 ( V_307 ) ;
break;
case V_274 :
V_49 . V_161 . V_276 . V_101 = F_240 ( V_307 ) ;
V_49 . V_161 . V_276 . V_277 = F_241 ( V_307 ) ;
break;
case V_278 :
V_49 . V_161 . V_164 = V_307 ? true : false ;
break;
case V_280 :
V_49 . V_161 . V_165 = F_282 ( V_307 ) ;
break;
default:
F_265 () ;
}
V_29 = F_37 ( V_14 , V_24 , & V_49 ) ;
if ( V_29 )
goto V_303;
V_24 -> V_34 = true ;
F_283 ( & V_24 -> V_291 , & V_302 ) ;
}
if ( ! V_313 ) {
V_29 = - V_159 ;
goto V_303;
}
}
V_29 = F_284 ( V_14 , & V_302 ) ;
V_303:
F_254 ( V_14 ) ;
return V_29 ;
}
static int F_285 ( struct V_67 * V_68 ,
struct V_1 * V_4 )
{
struct V_242 * V_317 ;
V_317 = F_258 ( V_68 , V_318 ) ;
if ( ! V_317 )
goto V_265;
if ( F_260 ( V_68 , V_319 , V_4 -> V_3 -> V_258 ) )
goto V_265;
if ( V_4 -> V_34 ) {
if ( F_263 ( V_68 , V_320 ) )
goto V_265;
V_4 -> V_34 = false ;
}
if ( ( V_4 -> V_35 &&
F_263 ( V_68 , V_321 ) ) ||
( V_4 -> V_18 . V_15 &&
F_263 ( V_68 , V_322 ) ) ||
F_260 ( V_68 , V_323 , V_4 -> V_18 . V_324 ) ||
F_261 ( V_68 , V_325 , V_4 -> V_18 . V_326 ) )
goto V_265;
F_266 ( V_68 , V_317 ) ;
return 0 ;
V_265:
F_267 ( V_68 , V_317 ) ;
return - V_256 ;
}
static int F_286 ( struct V_14 * V_14 , T_4 V_261 , T_4 V_286 ,
int V_144 , T_11 * V_284 ,
struct V_1 * V_327 )
{
struct V_242 * V_79 ;
struct V_288 * V_289 ;
void * V_250 ;
struct V_1 * V_4 ;
int V_29 ;
struct V_67 * V_68 = NULL ;
bool V_290 ;
int V_28 ;
V_4 = F_287 ( & V_14 -> V_79 ,
struct V_1 , V_25 ) ;
V_292:
V_29 = F_268 ( & V_68 , V_14 , V_261 , V_284 ) ;
if ( V_29 )
return V_29 ;
V_250 = F_246 ( V_68 , V_261 , V_286 , & V_254 , V_144 | V_293 ,
V_328 ) ;
if ( ! V_250 )
return - V_256 ;
if ( F_260 ( V_68 , V_260 , V_14 -> V_3 -> V_258 ) )
goto V_295;
V_79 = F_258 ( V_68 , V_329 ) ;
if ( ! V_79 )
goto V_295;
V_28 = 0 ;
V_290 = false ;
if ( V_327 ) {
V_29 = F_285 ( V_68 , V_327 ) ;
if ( V_29 )
goto V_297;
} else if ( V_4 ) {
F_272 (port, &team->port_list, list) {
V_29 = F_285 ( V_68 , V_4 ) ;
if ( V_29 ) {
if ( V_29 == - V_256 ) {
if ( ! V_28 )
goto V_297;
V_290 = true ;
break;
}
goto V_297;
}
V_28 ++ ;
}
}
F_266 ( V_68 , V_79 ) ;
F_247 ( V_68 , V_250 ) ;
if ( V_290 )
goto V_292;
V_298:
V_289 = F_273 ( V_68 , V_261 , V_286 , V_299 , 0 , V_144 | V_293 ) ;
if ( ! V_289 ) {
V_29 = F_268 ( & V_68 , V_14 , V_261 , V_284 ) ;
if ( V_29 )
goto V_297;
goto V_298;
}
return V_284 ( V_68 , V_14 , V_261 ) ;
V_295:
V_29 = - V_256 ;
V_297:
F_274 ( V_68 , V_250 ) ;
F_250 ( V_68 ) ;
return V_29 ;
}
static int F_288 ( struct V_67 * V_68 ,
struct V_248 * V_32 )
{
struct V_14 * V_14 ;
int V_29 ;
V_14 = F_251 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
V_29 = F_286 ( V_14 , V_32 -> V_252 , V_32 -> V_253 ,
V_300 , F_255 , NULL ) ;
F_254 ( V_14 ) ;
return V_29 ;
}
static int F_289 ( struct V_67 * V_68 ,
struct V_14 * V_14 , T_4 V_261 )
{
return F_290 ( & V_254 , F_256 ( V_14 -> V_3 ) ,
V_68 , 0 , 0 , V_30 ) ;
}
static int F_284 ( struct V_14 * V_14 ,
struct V_106 * V_287 )
{
return F_270 ( V_14 , 0 , 0 , 0 , F_289 ,
V_287 ) ;
}
static int F_291 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
return F_286 ( V_14 , 0 , 0 , 0 , F_289 ,
V_4 ) ;
}
static int F_292 ( void )
{
return F_293 ( & V_254 , V_330 ,
V_331 ) ;
}
static void F_294 ( void )
{
F_295 ( & V_254 ) ;
}
static void F_34 ( struct V_14 * V_14 )
{
int V_29 ;
struct V_23 * V_24 ;
F_276 ( V_287 ) ;
F_14 (opt_inst, &team->option_inst_list, list) {
if ( V_24 -> V_34 )
F_22 ( & V_24 -> V_291 , & V_287 ) ;
}
V_29 = F_284 ( V_14 , & V_287 ) ;
if ( V_29 && V_29 != - V_332 )
F_296 ( V_14 -> V_3 , L_29 ,
V_29 ) ;
}
static void F_297 ( struct V_1 * V_4 , bool V_15 )
{
int V_29 ;
V_4 -> V_34 = true ;
V_4 -> V_18 . V_15 = V_15 ;
F_12 ( V_4 ) ;
if ( V_15 ) {
struct V_333 V_334 ;
V_29 = F_298 ( V_4 -> V_3 , & V_334 ) ;
if ( ! V_29 ) {
V_4 -> V_18 . V_324 = F_299 ( & V_334 ) ;
V_4 -> V_18 . V_326 = V_334 . V_326 ;
goto V_335;
}
}
V_4 -> V_18 . V_324 = 0 ;
V_4 -> V_18 . V_326 = 0 ;
V_335:
V_29 = F_291 ( V_4 -> V_14 , V_4 ) ;
if ( V_29 && V_29 != - V_332 )
F_296 ( V_4 -> V_14 -> V_3 , L_30 ,
V_4 -> V_3 -> V_22 , V_29 ) ;
}
static void F_167 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
bool V_336 ;
if ( V_14 -> V_71 )
return;
V_336 = false ;
F_14 (port, &team->port_list, list) {
if ( V_4 -> V_15 ) {
V_336 = true ;
break;
}
}
if ( V_336 )
F_226 ( V_14 -> V_3 ) ;
else
F_184 ( V_14 -> V_3 ) ;
}
static void F_300 ( struct V_1 * V_4 , bool V_15 )
{
if ( V_4 -> V_18 . V_15 != V_15 )
F_297 ( V_4 , V_15 ) ;
F_167 ( V_4 -> V_14 ) ;
}
static void F_143 ( struct V_1 * V_4 , bool V_15 )
{
F_297 ( V_4 , V_15 ) ;
F_167 ( V_4 -> V_14 ) ;
}
static void F_151 ( struct V_1 * V_4 )
{
V_4 -> V_35 = true ;
F_297 ( V_4 , false ) ;
F_167 ( V_4 -> V_14 ) ;
}
static void F_301 ( struct V_1 * V_4 , bool V_15 )
{
struct V_14 * V_14 = V_4 -> V_14 ;
F_121 ( & V_14 -> V_135 ) ;
F_300 ( V_4 , V_15 ) ;
F_122 ( & V_14 -> V_135 ) ;
}
static int F_302 ( struct V_337 * V_169 ,
unsigned long V_338 , void * V_277 )
{
struct V_2 * V_3 = F_303 ( V_277 ) ;
struct V_1 * V_4 ;
V_4 = F_4 ( V_3 ) ;
if ( ! V_4 )
return V_339 ;
switch ( V_338 ) {
case V_340 :
if ( F_144 ( V_3 ) )
F_301 ( V_4 , true ) ;
break;
case V_341 :
F_301 ( V_4 , false ) ;
break;
case V_342 :
if ( F_74 ( V_4 -> V_3 ) )
F_301 ( V_4 ,
! ! F_144 ( V_4 -> V_3 ) ) ;
break;
case V_343 :
F_223 ( V_4 -> V_14 -> V_3 , V_3 ) ;
break;
case V_344 :
F_120 ( V_4 -> V_14 ) ;
break;
case V_345 :
if ( ! V_4 -> V_14 -> V_198 )
return V_346 ;
break;
case V_219 :
return V_346 ;
case V_90 :
F_69 ( V_338 , V_4 -> V_14 -> V_3 ) ;
break;
}
return V_339 ;
}
static int T_12 F_304 ( void )
{
int V_29 ;
F_305 ( & V_347 ) ;
V_29 = F_306 ( & V_348 ) ;
if ( V_29 )
goto V_349;
V_29 = F_292 () ;
if ( V_29 )
goto V_350;
return 0 ;
V_350:
F_307 ( & V_348 ) ;
V_349:
F_308 ( & V_347 ) ;
return V_29 ;
}
static void T_13 F_309 ( void )
{
F_294 () ;
F_307 ( & V_348 ) ;
F_308 ( & V_347 ) ;
}
