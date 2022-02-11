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
F_75 ( & V_14 -> V_83 . V_86 , V_14 -> V_83 . V_88 ) ;
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
F_75 ( & V_14 -> V_89 . V_86 , V_14 -> V_89 . V_88 ) ;
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
T_4 V_125 = V_126 ;
unsigned short V_127 = V_128 ;
unsigned int V_129 , V_130 = V_131 ;
F_14 (port, &team->port_list, list) {
V_125 = F_118 ( V_125 ,
V_4 -> V_3 -> V_125 ,
V_126 ) ;
V_130 &= V_4 -> V_3 -> V_132 ;
if ( V_4 -> V_3 -> V_133 > V_127 )
V_127 = V_4 -> V_3 -> V_133 ;
}
V_14 -> V_3 -> V_125 = V_125 ;
V_14 -> V_3 -> V_133 = V_127 ;
V_129 = V_14 -> V_3 -> V_132 & ~ V_131 ;
V_14 -> V_3 -> V_132 = V_129 | V_130 ;
F_119 ( V_14 -> V_3 ) ;
}
static void F_120 ( struct V_14 * V_14 )
{
F_121 ( & V_14 -> V_134 ) ;
F_117 ( V_14 ) ;
F_122 ( & V_14 -> V_134 ) ;
}
static int F_123 ( struct V_14 * V_14 , struct V_1 * V_4 )
{
int V_29 = 0 ;
F_124 ( V_14 -> V_3 ) ;
V_4 -> V_3 -> V_132 |= V_135 ;
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
V_4 -> V_3 -> V_132 &= ~ V_135 ;
F_125 ( V_14 -> V_3 ) ;
return V_29 ;
}
static void F_126 ( struct V_14 * V_14 , struct V_1 * V_4 )
{
if ( V_14 -> V_73 . V_138 )
V_14 -> V_73 . V_138 ( V_14 , V_4 ) ;
V_4 -> V_3 -> V_132 &= ~ V_135 ;
F_125 ( V_14 -> V_3 ) ;
}
static int F_127 ( struct V_14 * V_14 , struct V_1 * V_4 ,
T_5 V_139 )
{
struct V_140 * V_141 ;
int V_29 ;
if ( ! V_14 -> V_3 -> V_142 )
return 0 ;
V_141 = F_29 ( sizeof( * V_141 ) , V_139 ) ;
if ( ! V_141 )
return - V_31 ;
V_29 = F_128 ( V_141 , V_4 -> V_3 , V_139 ) ;
if ( V_29 ) {
F_17 ( V_141 ) ;
return V_29 ;
}
V_4 -> V_141 = V_141 ;
return V_29 ;
}
static void F_129 ( struct V_1 * V_4 )
{
struct V_140 * V_141 = V_4 -> V_141 ;
if ( ! V_141 )
return;
V_4 -> V_141 = NULL ;
F_130 () ;
F_131 ( V_141 ) ;
F_17 ( V_141 ) ;
}
static int F_127 ( struct V_14 * V_14 , struct V_1 * V_4 ,
T_5 V_139 )
{
return 0 ;
}
static void F_129 ( struct V_1 * V_4 )
{
}
static int F_132 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_4 ;
char * V_143 = V_6 -> V_22 ;
int V_29 ;
if ( V_6 -> V_129 & V_144 ) {
F_64 ( V_3 , L_11 ,
V_143 ) ;
return - V_62 ;
}
if ( F_3 ( V_6 ) ) {
F_64 ( V_3 , L_12
L_13 , V_143 ) ;
return - V_80 ;
}
if ( V_6 -> V_145 & V_146 &&
F_133 ( V_3 ) ) {
F_64 ( V_3 , L_14 ,
V_143 ) ;
return - V_147 ;
}
V_29 = F_134 ( V_3 , V_6 ) ;
if ( V_29 )
return V_29 ;
if ( V_6 -> V_129 & V_148 ) {
F_64 ( V_3 , L_15 ,
V_143 ) ;
return - V_80 ;
}
V_4 = F_29 ( sizeof( struct V_1 ) + V_14 -> V_58 -> V_149 ,
V_30 ) ;
if ( ! V_4 )
return - V_31 ;
V_4 -> V_3 = V_6 ;
V_4 -> V_14 = V_14 ;
F_92 ( & V_4 -> V_112 ) ;
V_4 -> V_13 . V_150 = V_6 -> V_150 ;
V_29 = F_135 ( V_6 , V_3 -> V_150 ) ;
if ( V_29 ) {
F_104 ( V_3 , L_16 , V_29 ) ;
goto V_151;
}
memcpy ( V_4 -> V_13 . V_7 , V_6 -> V_7 , V_6 -> V_11 ) ;
V_29 = F_123 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_10 ,
V_143 ) ;
goto V_137;
}
V_29 = F_136 ( V_6 ) ;
if ( V_29 ) {
F_104 ( V_3 , L_17 ,
V_143 ) ;
goto V_152;
}
V_29 = F_137 ( V_6 , V_3 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_18 ,
V_143 ) ;
goto V_153;
}
V_29 = F_127 ( V_14 , V_4 , V_30 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_19 ,
V_143 ) ;
goto V_154;
}
V_29 = F_138 ( V_6 , V_3 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_20 ,
V_143 ) ;
goto V_155;
}
V_29 = F_139 ( V_6 , F_84 ,
V_4 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_21 ,
V_143 ) ;
goto V_156;
}
V_29 = F_26 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_22 ,
V_143 ) ;
goto V_157;
}
V_4 -> V_117 = - 1 ;
F_102 ( & V_4 -> V_25 , & V_14 -> V_79 ) ;
F_110 ( V_14 , V_4 ) ;
F_117 ( V_14 ) ;
F_140 ( V_4 , ! ! F_141 ( V_6 ) ) ;
F_34 ( V_14 ) ;
F_65 ( V_3 , L_23 , V_143 ) ;
return 0 ;
V_157:
F_142 ( V_6 ) ;
V_156:
F_143 ( V_6 , V_3 ) ;
V_155:
F_129 ( V_4 ) ;
V_154:
F_144 ( V_6 , V_3 ) ;
V_153:
F_145 ( V_6 ) ;
V_152:
F_126 ( V_14 , V_4 ) ;
F_8 ( V_4 ) ;
V_137:
F_135 ( V_6 , V_4 -> V_13 . V_150 ) ;
V_151:
F_17 ( V_4 ) ;
return V_29 ;
}
static int F_146 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_4 ;
char * V_143 = V_6 -> V_22 ;
V_4 = F_4 ( V_6 ) ;
if ( ! V_4 || ! F_109 ( V_14 , V_4 ) ) {
F_64 ( V_3 , L_24 ,
V_143 ) ;
return - V_158 ;
}
F_116 ( V_14 , V_4 ) ;
F_99 ( & V_4 -> V_25 ) ;
F_142 ( V_6 ) ;
F_143 ( V_6 , V_3 ) ;
F_129 ( V_4 ) ;
F_144 ( V_6 , V_3 ) ;
F_147 ( V_6 , V_3 ) ;
F_148 ( V_6 , V_3 ) ;
F_145 ( V_6 ) ;
F_126 ( V_14 , V_4 ) ;
F_27 ( V_14 , V_4 ) ;
F_34 ( V_14 ) ;
F_25 ( V_14 , V_4 ) ;
F_149 ( V_4 ) ;
F_8 ( V_4 ) ;
F_135 ( V_6 , V_4 -> V_13 . V_150 ) ;
F_150 ( V_4 , V_159 ) ;
F_65 ( V_3 , L_25 , V_143 ) ;
F_117 ( V_14 ) ;
return 0 ;
}
static int F_151 ( struct V_14 * V_14 , struct V_48 * V_49 )
{
V_49 -> V_160 . V_161 = V_14 -> V_58 -> V_56 ;
return 0 ;
}
static int F_152 ( struct V_14 * V_14 , struct V_48 * V_49 )
{
return F_62 ( V_14 , V_49 -> V_160 . V_161 ) ;
}
static int F_153 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_49 -> V_160 . V_162 = V_14 -> V_83 . V_88 ;
return 0 ;
}
static int F_154 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_14 -> V_83 . V_88 = V_49 -> V_160 . V_162 ;
return 0 ;
}
static int F_155 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_49 -> V_160 . V_162 = V_14 -> V_83 . V_87 ;
return 0 ;
}
static int F_156 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_14 -> V_83 . V_87 = V_49 -> V_160 . V_162 ;
return 0 ;
}
static int F_157 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_49 -> V_160 . V_162 = V_14 -> V_89 . V_88 ;
return 0 ;
}
static int F_158 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_14 -> V_89 . V_88 = V_49 -> V_160 . V_162 ;
return 0 ;
}
static int F_159 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_49 -> V_160 . V_162 = V_14 -> V_89 . V_87 ;
return 0 ;
}
static int F_160 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
V_14 -> V_89 . V_87 = V_49 -> V_160 . V_162 ;
return 0 ;
}
static int F_161 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_160 . V_163 = F_86 ( V_4 ) ;
return 0 ;
}
static int F_162 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
if ( V_49 -> V_160 . V_163 )
F_110 ( V_14 , V_4 ) ;
else
F_116 ( V_14 , V_4 ) ;
return 0 ;
}
static int F_163 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_160 . V_163 = V_4 -> V_16 . V_15 ;
return 0 ;
}
static int F_164 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_4 -> V_16 . V_15 = V_49 -> V_160 . V_163 ;
F_12 ( V_4 ) ;
return 0 ;
}
static int F_165 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_160 . V_163 = V_4 -> V_16 . V_17 ;
return 0 ;
}
static int F_166 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_4 -> V_16 . V_17 = V_49 -> V_160 . V_163 ;
F_12 ( V_4 ) ;
return 0 ;
}
static int F_167 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_160 . V_164 = V_4 -> V_116 ;
return 0 ;
}
static int F_168 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
T_6 V_116 = V_49 -> V_160 . V_164 ;
if ( V_4 -> V_116 == V_116 )
return 0 ;
V_4 -> V_116 = V_116 ;
F_105 ( V_14 , V_4 ) ;
return 0 ;
}
static int F_169 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_160 . V_162 = V_4 -> V_111 ;
return 0 ;
}
static int F_170 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
T_3 V_120 = V_49 -> V_160 . V_162 ;
if ( V_4 -> V_111 == V_120 )
return 0 ;
if ( V_120 >= V_14 -> V_3 -> V_165 )
return - V_62 ;
F_106 ( V_14 , V_4 , V_120 ) ;
return 0 ;
}
static void F_171 ( struct V_2 * V_3 ,
struct V_166 * V_167 ,
void * V_168 )
{
F_172 ( & V_167 -> V_169 , & V_170 ) ;
}
static void F_173 ( struct V_2 * V_3 )
{
F_172 ( & V_3 -> V_171 , & V_172 ) ;
F_174 ( V_3 , F_171 , NULL ) ;
V_3 -> V_173 = & V_174 ;
}
static int F_175 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_176 ( V_3 ) ;
int V_28 ;
int V_29 ;
V_14 -> V_3 = V_3 ;
F_177 ( & V_14 -> V_134 ) ;
F_57 ( V_14 ) ;
V_14 -> V_97 = F_178 ( struct V_96 ) ;
if ( ! V_14 -> V_97 )
return - V_31 ;
for ( V_28 = 0 ; V_28 < V_175 ; V_28 ++ )
F_179 ( & V_14 -> V_176 [ V_28 ] ) ;
F_92 ( & V_14 -> V_79 ) ;
V_29 = F_91 ( V_14 ) ;
if ( V_29 )
goto V_177;
F_58 ( V_14 ) ;
F_92 ( & V_14 -> V_46 ) ;
F_92 ( & V_14 -> V_36 ) ;
F_76 ( V_14 ) ;
F_82 ( V_14 ) ;
V_29 = F_33 ( V_14 , V_178 , F_180 ( V_178 ) ) ;
if ( V_29 )
goto V_179;
F_181 ( V_3 ) ;
F_173 ( V_3 ) ;
return 0 ;
V_179:
F_83 ( V_14 ) ;
F_78 ( V_14 ) ;
F_93 ( V_14 ) ;
V_177:
F_182 ( V_14 -> V_97 ) ;
return V_29 ;
}
static void F_183 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_176 ( V_3 ) ;
struct V_1 * V_4 ;
struct V_1 * V_26 ;
F_121 ( & V_14 -> V_134 ) ;
F_19 (port, tmp, &team->port_list, list)
F_146 ( V_14 , V_4 -> V_3 ) ;
F_59 ( V_14 , NULL ) ;
F_32 ( V_14 , V_178 , F_180 ( V_178 ) ) ;
F_83 ( V_14 ) ;
F_78 ( V_14 ) ;
F_93 ( V_14 ) ;
F_122 ( & V_14 -> V_134 ) ;
}
static void F_184 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_176 ( V_3 ) ;
F_182 ( V_14 -> V_97 ) ;
F_185 ( V_3 ) ;
}
static int F_186 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_187 ( struct V_2 * V_3 )
{
return 0 ;
}
static T_7 F_188 ( struct V_67 * V_68 , struct V_2 * V_3 )
{
struct V_14 * V_14 = F_176 ( V_3 ) ;
bool V_180 ;
unsigned int V_101 = V_68 -> V_101 ;
V_180 = F_95 ( V_14 , V_68 ) ;
if ( ! V_180 )
V_180 = V_14 -> V_73 . V_74 ( V_14 , V_68 ) ;
if ( V_180 ) {
struct V_96 * V_97 ;
V_97 = F_87 ( V_14 -> V_97 ) ;
F_88 ( & V_97 -> V_98 ) ;
V_97 -> V_181 ++ ;
V_97 -> V_182 += V_101 ;
F_89 ( & V_97 -> V_98 ) ;
} else {
F_90 ( V_14 -> V_97 -> V_183 ) ;
}
return V_184 ;
}
static T_3 F_189 ( struct V_2 * V_3 , struct V_67 * V_68 )
{
T_3 V_167 = F_190 ( V_68 ) ? F_191 ( V_68 ) : 0 ;
F_192 ( V_68 ) -> V_185 = V_68 -> V_114 ;
if ( F_193 ( V_167 >= V_3 -> V_165 ) ) {
do {
V_167 -= V_3 -> V_165 ;
} while ( V_167 >= V_3 -> V_165 );
}
return V_167 ;
}
static void F_194 ( struct V_2 * V_3 , int V_186 )
{
struct V_14 * V_14 = F_176 ( V_3 ) ;
struct V_1 * V_4 ;
int V_187 ;
F_195 () ;
F_96 (port, &team->port_list, list) {
if ( V_186 & V_188 ) {
V_187 = V_3 -> V_129 & V_188 ? 1 : - 1 ;
F_196 ( V_4 -> V_3 , V_187 ) ;
}
if ( V_186 & V_189 ) {
V_187 = V_3 -> V_129 & V_189 ? 1 : - 1 ;
F_197 ( V_4 -> V_3 , V_187 ) ;
}
}
F_198 () ;
}
static void F_199 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_176 ( V_3 ) ;
struct V_1 * V_4 ;
F_195 () ;
F_96 (port, &team->port_list, list) {
F_200 ( V_4 -> V_3 , V_3 ) ;
F_201 ( V_4 -> V_3 , V_3 ) ;
}
F_198 () ;
}
static int F_202 ( struct V_2 * V_3 , void * V_190 )
{
struct V_8 * V_9 = V_190 ;
struct V_14 * V_14 = F_176 ( V_3 ) ;
struct V_1 * V_4 ;
if ( V_3 -> type == V_191 && ! F_203 ( V_9 -> V_10 ) )
return - V_192 ;
memcpy ( V_3 -> V_7 , V_9 -> V_10 , V_3 -> V_11 ) ;
F_195 () ;
F_96 (port, &team->port_list, list)
if ( V_14 -> V_73 . V_193 )
V_14 -> V_73 . V_193 ( V_14 , V_4 ) ;
F_198 () ;
return 0 ;
}
static int F_204 ( struct V_2 * V_3 , int V_194 )
{
struct V_14 * V_14 = F_176 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 ;
F_121 ( & V_14 -> V_134 ) ;
F_14 (port, &team->port_list, list) {
V_29 = F_135 ( V_4 -> V_3 , V_194 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_26 ,
V_4 -> V_3 -> V_22 ) ;
goto V_195;
}
}
F_122 ( & V_14 -> V_134 ) ;
V_3 -> V_150 = V_194 ;
return 0 ;
V_195:
F_205 (port, &team->port_list, list)
F_135 ( V_4 -> V_3 , V_3 -> V_150 ) ;
F_122 ( & V_14 -> V_134 ) ;
return V_29 ;
}
static struct V_196 *
F_206 ( struct V_2 * V_3 , struct V_196 * V_197 )
{
struct V_14 * V_14 = F_176 ( V_3 ) ;
struct V_96 * V_190 ;
T_8 V_99 , V_100 , V_104 , V_181 , V_182 ;
T_4 V_105 = 0 , V_183 = 0 ;
unsigned int V_198 ;
int V_28 ;
F_207 (i) {
V_190 = F_208 ( V_14 -> V_97 , V_28 ) ;
do {
V_198 = F_209 ( & V_190 -> V_98 ) ;
V_99 = V_190 -> V_99 ;
V_100 = V_190 -> V_100 ;
V_104 = V_190 -> V_104 ;
V_181 = V_190 -> V_181 ;
V_182 = V_190 -> V_182 ;
} while ( F_210 ( & V_190 -> V_98 , V_198 ) );
V_197 -> V_99 += V_99 ;
V_197 -> V_100 += V_100 ;
V_197 -> V_199 += V_104 ;
V_197 -> V_181 += V_181 ;
V_197 -> V_182 += V_182 ;
V_105 += V_190 -> V_105 ;
V_183 += V_190 -> V_183 ;
}
V_197 -> V_105 = V_105 ;
V_197 -> V_183 = V_183 ;
return V_197 ;
}
static int F_211 ( struct V_2 * V_3 , T_9 V_200 , T_3 V_201 )
{
struct V_14 * V_14 = F_176 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 ;
F_121 ( & V_14 -> V_134 ) ;
F_14 (port, &team->port_list, list) {
V_29 = F_212 ( V_4 -> V_3 , V_200 , V_201 ) ;
if ( V_29 )
goto V_195;
}
F_122 ( & V_14 -> V_134 ) ;
return 0 ;
V_195:
F_205 (port, &team->port_list, list)
F_213 ( V_4 -> V_3 , V_200 , V_201 ) ;
F_122 ( & V_14 -> V_134 ) ;
return V_29 ;
}
static int F_214 ( struct V_2 * V_3 , T_9 V_200 , T_3 V_201 )
{
struct V_14 * V_14 = F_176 ( V_3 ) ;
struct V_1 * V_4 ;
F_195 () ;
F_96 (port, &team->port_list, list)
F_213 ( V_4 -> V_3 , V_200 , V_201 ) ;
F_198 () ;
return 0 ;
}
static void F_215 ( struct V_2 * V_3 )
{
}
static void F_216 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
F_14 (port, &team->port_list, list)
F_129 ( V_4 ) ;
}
static void F_217 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_176 ( V_3 ) ;
F_121 ( & V_14 -> V_134 ) ;
F_216 ( V_14 ) ;
F_122 ( & V_14 -> V_134 ) ;
}
static int F_218 ( struct V_2 * V_3 ,
struct V_202 * V_203 , T_5 V_139 )
{
struct V_14 * V_14 = F_176 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 = 0 ;
F_121 ( & V_14 -> V_134 ) ;
F_14 (port, &team->port_list, list) {
V_29 = F_127 ( V_14 , V_4 , V_139 ) ;
if ( V_29 ) {
F_216 ( V_14 ) ;
break;
}
}
F_122 ( & V_14 -> V_134 ) ;
return V_29 ;
}
static int F_219 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_176 ( V_3 ) ;
int V_29 ;
F_121 ( & V_14 -> V_134 ) ;
V_29 = F_132 ( V_14 , V_6 ) ;
F_122 ( & V_14 -> V_134 ) ;
return V_29 ;
}
static int F_220 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_176 ( V_3 ) ;
int V_29 ;
F_121 ( & V_14 -> V_134 ) ;
V_29 = F_146 ( V_14 , V_6 ) ;
F_122 ( & V_14 -> V_134 ) ;
return V_29 ;
}
static T_10 F_221 ( struct V_2 * V_3 ,
T_10 V_145 )
{
struct V_1 * V_4 ;
struct V_14 * V_14 = F_176 ( V_3 ) ;
T_10 V_204 ;
V_204 = V_145 ;
V_145 &= ~ V_205 ;
V_145 |= V_206 ;
F_195 () ;
F_96 (port, &team->port_list, list) {
V_145 = F_118 ( V_145 ,
V_4 -> V_3 -> V_145 ,
V_204 ) ;
}
F_198 () ;
return V_145 ;
}
static int F_222 ( struct V_2 * V_3 , bool V_207 )
{
struct V_14 * V_14 = F_176 ( V_3 ) ;
V_14 -> V_71 = true ;
if ( V_207 )
F_223 ( V_3 ) ;
else
F_181 ( V_3 ) ;
return 0 ;
}
static void F_224 ( struct V_2 * V_3 ,
struct V_208 * V_209 )
{
F_225 ( V_209 -> V_210 , V_211 , sizeof( V_209 -> V_210 ) ) ;
F_225 ( V_209 -> V_212 , V_213 , sizeof( V_209 -> V_212 ) ) ;
}
static void F_226 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
V_3 -> V_214 = V_6 -> V_214 ;
V_3 -> type = V_6 -> type ;
V_3 -> V_133 = V_6 -> V_133 ;
V_3 -> V_11 = V_6 -> V_11 ;
V_3 -> V_150 = V_6 -> V_150 ;
memcpy ( V_3 -> V_215 , V_6 -> V_215 , V_6 -> V_11 ) ;
F_227 ( V_3 , V_6 ) ;
}
static int F_134 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
struct V_14 * V_14 = F_176 ( V_3 ) ;
char * V_143 = V_6 -> V_22 ;
int V_29 ;
if ( V_3 -> type == V_6 -> type )
return 0 ;
if ( ! F_63 ( & V_14 -> V_79 ) ) {
F_64 ( V_3 , L_27 , V_143 ) ;
return - V_80 ;
}
V_29 = F_69 ( V_216 , V_3 ) ;
V_29 = F_228 ( V_29 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_28 ) ;
return V_29 ;
}
F_229 ( V_3 ) ;
F_230 ( V_3 ) ;
F_226 ( V_3 , V_6 ) ;
F_69 ( V_217 , V_3 ) ;
return 0 ;
}
static void F_231 ( struct V_2 * V_3 )
{
F_232 ( V_3 ) ;
V_3 -> V_218 = & V_219 ;
V_3 -> V_220 = & V_221 ;
V_3 -> V_222 = F_184 ;
V_3 -> V_223 = 0 ;
V_3 -> V_129 |= V_224 ;
V_3 -> V_132 &= ~ ( V_131 | V_225 ) ;
V_3 -> V_132 |= V_226 | V_227 ;
V_3 -> V_145 |= V_228 ;
V_3 -> V_145 |= V_229 ;
V_3 -> V_230 = V_126 |
V_231 |
V_232 |
V_233 ;
V_3 -> V_230 &= ~ ( V_234 & ~ V_235 ) ;
V_3 -> V_145 |= V_3 -> V_230 ;
}
static int F_233 ( struct V_236 * V_237 , struct V_2 * V_3 ,
struct V_238 * V_239 [] , struct V_238 * V_160 [] )
{
int V_29 ;
if ( V_239 [ V_240 ] == NULL )
F_234 ( V_3 ) ;
V_29 = F_235 ( V_3 ) ;
if ( V_29 )
return V_29 ;
return 0 ;
}
static int F_236 ( struct V_238 * V_239 [] , struct V_238 * V_160 [] )
{
if ( V_239 [ V_240 ] ) {
if ( F_237 ( V_239 [ V_240 ] ) != V_241 )
return - V_62 ;
if ( ! F_203 ( F_238 ( V_239 [ V_240 ] ) ) )
return - V_192 ;
}
return 0 ;
}
static unsigned int F_239 ( void )
{
return V_242 ;
}
static unsigned int F_240 ( void )
{
return V_243 ;
}
static int F_241 ( struct V_67 * V_68 , struct V_244 * V_32 )
{
struct V_67 * V_245 ;
void * V_246 ;
int V_29 ;
V_245 = F_242 ( V_247 , V_30 ) ;
if ( ! V_245 )
return - V_31 ;
V_246 = F_243 ( V_245 , V_32 -> V_248 , V_32 -> V_249 ,
& V_250 , 0 , V_251 ) ;
if ( ! V_246 ) {
V_29 = - V_252 ;
goto V_253;
}
F_244 ( V_245 , V_246 ) ;
return F_245 ( F_246 ( V_32 ) , V_245 , V_32 -> V_248 ) ;
V_253:
F_247 ( V_245 ) ;
return V_29 ;
}
static struct V_14 * F_248 ( struct V_244 * V_32 )
{
struct V_236 * V_236 = F_246 ( V_32 ) ;
int V_254 ;
struct V_2 * V_3 ;
struct V_14 * V_14 ;
if ( ! V_32 -> V_255 [ V_256 ] )
return NULL ;
V_254 = F_249 ( V_32 -> V_255 [ V_256 ] ) ;
V_3 = F_250 ( V_236 , V_254 ) ;
if ( ! V_3 || V_3 -> V_218 != & V_219 ) {
if ( V_3 )
F_125 ( V_3 ) ;
return NULL ;
}
V_14 = F_176 ( V_3 ) ;
F_121 ( & V_14 -> V_134 ) ;
return V_14 ;
}
static void F_251 ( struct V_14 * V_14 )
{
F_122 ( & V_14 -> V_134 ) ;
F_125 ( V_14 -> V_3 ) ;
}
static int F_252 ( struct V_67 * V_68 , struct V_14 * V_14 , T_4 V_257 )
{
return F_245 ( F_253 ( V_14 -> V_3 ) , V_68 , V_257 ) ;
}
static int F_254 ( struct V_67 * V_68 , struct V_14 * V_14 ,
struct V_23 * V_24 )
{
struct V_238 * V_258 ;
struct V_19 * V_21 = V_24 -> V_21 ;
struct V_53 * V_54 = & V_24 -> V_32 ;
struct V_48 V_49 ;
int V_29 ;
V_49 . V_32 = V_54 ;
V_29 = F_36 ( V_14 , V_24 , & V_49 ) ;
if ( V_29 )
return V_29 ;
V_258 = F_255 ( V_68 , V_259 ) ;
if ( ! V_258 )
return - V_252 ;
if ( F_256 ( V_68 , V_260 , V_21 -> V_22 ) )
goto V_261;
if ( V_54 -> V_4 &&
F_257 ( V_68 , V_262 ,
V_54 -> V_4 -> V_3 -> V_254 ) )
goto V_261;
if ( V_24 -> V_21 -> V_27 &&
F_257 ( V_68 , V_263 ,
V_54 -> V_33 ) )
goto V_261;
switch ( V_21 -> type ) {
case V_264 :
if ( F_258 ( V_68 , V_265 , V_266 ) )
goto V_261;
if ( F_257 ( V_68 , V_267 , V_49 . V_160 . V_162 ) )
goto V_261;
break;
case V_268 :
if ( F_258 ( V_68 , V_265 , V_269 ) )
goto V_261;
if ( F_256 ( V_68 , V_267 ,
V_49 . V_160 . V_161 ) )
goto V_261;
break;
case V_270 :
if ( F_258 ( V_68 , V_265 , V_271 ) )
goto V_261;
if ( F_259 ( V_68 , V_267 , V_49 . V_160 . V_272 . V_101 ,
V_49 . V_160 . V_272 . V_273 ) )
goto V_261;
break;
case V_274 :
if ( F_258 ( V_68 , V_265 , V_275 ) )
goto V_261;
if ( V_49 . V_160 . V_163 &&
F_260 ( V_68 , V_267 ) )
goto V_261;
break;
case V_276 :
if ( F_258 ( V_68 , V_265 , V_277 ) )
goto V_261;
if ( F_261 ( V_68 , V_267 , V_49 . V_160 . V_164 ) )
goto V_261;
break;
default:
F_262 () ;
}
if ( V_24 -> V_35 && F_260 ( V_68 , V_278 ) )
goto V_261;
if ( V_24 -> V_34 ) {
if ( F_260 ( V_68 , V_279 ) )
goto V_261;
V_24 -> V_34 = false ;
}
F_263 ( V_68 , V_258 ) ;
return 0 ;
V_261:
F_264 ( V_68 , V_258 ) ;
return - V_252 ;
}
static int F_265 ( struct V_67 * * V_91 ,
struct V_14 * V_14 , T_4 V_257 ,
T_11 * V_280 )
{
int V_29 ;
if ( * V_91 ) {
V_29 = V_280 ( * V_91 , V_14 , V_257 ) ;
if ( V_29 )
return V_29 ;
}
* V_91 = F_266 ( V_281 , V_30 ) ;
if ( ! * V_91 )
return - V_31 ;
return 0 ;
}
static int F_267 ( struct V_14 * V_14 , T_4 V_257 , T_4 V_282 ,
int V_129 , T_11 * V_280 ,
struct V_106 * V_283 )
{
struct V_238 * V_46 ;
struct V_284 * V_285 ;
void * V_246 ;
struct V_23 * V_24 ;
int V_29 ;
struct V_67 * V_68 = NULL ;
bool V_286 ;
int V_28 ;
V_24 = F_268 ( V_283 ,
struct V_23 , V_287 ) ;
V_288:
V_29 = F_265 ( & V_68 , V_14 , V_257 , V_280 ) ;
if ( V_29 )
return V_29 ;
V_246 = F_243 ( V_68 , V_257 , V_282 , & V_250 , V_129 | V_289 ,
V_290 ) ;
if ( ! V_246 )
return - V_252 ;
if ( F_257 ( V_68 , V_256 , V_14 -> V_3 -> V_254 ) )
goto V_291;
V_46 = F_255 ( V_68 , V_292 ) ;
if ( ! V_46 )
goto V_291;
V_28 = 0 ;
V_286 = false ;
F_269 (opt_inst, sel_opt_inst_list, tmp_list) {
V_29 = F_254 ( V_68 , V_14 , V_24 ) ;
if ( V_29 ) {
if ( V_29 == - V_252 ) {
if ( ! V_28 )
goto V_293;
V_286 = true ;
break;
}
goto V_293;
}
V_28 ++ ;
}
F_263 ( V_68 , V_46 ) ;
F_244 ( V_68 , V_246 ) ;
if ( V_286 )
goto V_288;
V_294:
V_285 = F_270 ( V_68 , V_257 , V_282 , V_295 , 0 , V_129 | V_289 ) ;
if ( ! V_285 ) {
V_29 = F_265 ( & V_68 , V_14 , V_257 , V_280 ) ;
if ( V_29 )
goto V_293;
goto V_294;
}
return V_280 ( V_68 , V_14 , V_257 ) ;
V_291:
V_29 = - V_252 ;
V_293:
F_271 ( V_68 , V_246 ) ;
F_247 ( V_68 ) ;
return V_29 ;
}
static int F_272 ( struct V_67 * V_68 , struct V_244 * V_32 )
{
struct V_14 * V_14 ;
struct V_23 * V_24 ;
int V_29 ;
F_273 ( V_283 ) ;
V_14 = F_248 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
F_14 (opt_inst, &team->option_inst_list, list)
F_22 ( & V_24 -> V_287 , & V_283 ) ;
V_29 = F_267 ( V_14 , V_32 -> V_248 , V_32 -> V_249 ,
V_296 , F_252 ,
& V_283 ) ;
F_251 ( V_14 ) ;
return V_29 ;
}
static int F_274 ( struct V_67 * V_68 , struct V_244 * V_32 )
{
struct V_14 * V_14 ;
int V_29 = 0 ;
int V_28 ;
struct V_238 * V_297 ;
F_273 ( V_298 ) ;
V_14 = F_248 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
V_29 = - V_62 ;
if ( ! V_32 -> V_255 [ V_292 ] ) {
V_29 = - V_62 ;
goto V_299;
}
F_275 (nl_option, info->attrs[TEAM_ATTR_LIST_OPTION], i) {
struct V_238 * V_300 [ V_301 + 1 ] ;
struct V_238 * V_302 ;
struct V_238 * V_303 ;
enum V_304 V_305 ;
int V_306 = 0 ;
T_4 V_307 = 0 ;
bool V_308 = false ;
struct V_23 * V_24 ;
char * V_20 ;
bool V_309 = false ;
if ( F_276 ( V_297 ) != V_259 ) {
V_29 = - V_62 ;
goto V_299;
}
V_29 = F_277 ( V_300 , V_301 ,
V_297 , V_310 ) ;
if ( V_29 )
goto V_299;
if ( ! V_300 [ V_260 ] ||
! V_300 [ V_265 ] ) {
V_29 = - V_62 ;
goto V_299;
}
switch ( F_278 ( V_300 [ V_265 ] ) ) {
case V_266 :
V_305 = V_264 ;
break;
case V_269 :
V_305 = V_268 ;
break;
case V_271 :
V_305 = V_270 ;
break;
case V_275 :
V_305 = V_274 ;
break;
case V_277 :
V_305 = V_276 ;
break;
default:
goto V_299;
}
V_303 = V_300 [ V_267 ] ;
if ( V_305 != V_274 && ! V_303 ) {
V_29 = - V_62 ;
goto V_299;
}
V_20 = F_238 ( V_300 [ V_260 ] ) ;
V_302 = V_300 [ V_262 ] ;
if ( V_302 )
V_306 = F_249 ( V_302 ) ;
V_302 = V_300 [ V_263 ] ;
if ( V_302 ) {
V_308 = true ;
V_307 = F_249 ( V_302 ) ;
}
F_14 (opt_inst, &team->option_inst_list, list) {
struct V_19 * V_21 = V_24 -> V_21 ;
struct V_48 V_49 ;
struct V_53 * V_54 ;
int V_311 ;
V_54 = & V_24 -> V_32 ;
V_311 = V_54 -> V_4 ?
V_54 -> V_4 -> V_3 -> V_254 : 0 ;
if ( V_21 -> type != V_305 ||
strcmp ( V_21 -> V_22 , V_20 ) ||
V_311 != V_306 ||
( V_21 -> V_27 && ! V_308 ) ||
V_54 -> V_33 != V_307 )
continue;
V_309 = true ;
V_49 . V_32 = V_54 ;
switch ( V_305 ) {
case V_264 :
V_49 . V_160 . V_162 = F_249 ( V_303 ) ;
break;
case V_268 :
if ( F_237 ( V_303 ) > V_312 ) {
V_29 = - V_62 ;
goto V_299;
}
V_49 . V_160 . V_161 = F_238 ( V_303 ) ;
break;
case V_270 :
V_49 . V_160 . V_272 . V_101 = F_237 ( V_303 ) ;
V_49 . V_160 . V_272 . V_273 = F_238 ( V_303 ) ;
break;
case V_274 :
V_49 . V_160 . V_163 = V_303 ? true : false ;
break;
case V_276 :
V_49 . V_160 . V_164 = F_279 ( V_303 ) ;
break;
default:
F_262 () ;
}
V_29 = F_37 ( V_14 , V_24 , & V_49 ) ;
if ( V_29 )
goto V_299;
V_24 -> V_34 = true ;
F_280 ( & V_24 -> V_287 , & V_298 ) ;
}
if ( ! V_309 ) {
V_29 = - V_158 ;
goto V_299;
}
}
V_29 = F_281 ( V_14 , & V_298 ) ;
V_299:
F_251 ( V_14 ) ;
return V_29 ;
}
static int F_282 ( struct V_67 * V_68 ,
struct V_1 * V_4 )
{
struct V_238 * V_313 ;
V_313 = F_255 ( V_68 , V_314 ) ;
if ( ! V_313 )
goto V_261;
if ( F_257 ( V_68 , V_315 , V_4 -> V_3 -> V_254 ) )
goto V_261;
if ( V_4 -> V_34 ) {
if ( F_260 ( V_68 , V_316 ) )
goto V_261;
V_4 -> V_34 = false ;
}
if ( ( V_4 -> V_35 &&
F_260 ( V_68 , V_317 ) ) ||
( V_4 -> V_18 . V_15 &&
F_260 ( V_68 , V_318 ) ) ||
F_257 ( V_68 , V_319 , V_4 -> V_18 . V_320 ) ||
F_258 ( V_68 , V_321 , V_4 -> V_18 . V_322 ) )
goto V_261;
F_263 ( V_68 , V_313 ) ;
return 0 ;
V_261:
F_264 ( V_68 , V_313 ) ;
return - V_252 ;
}
static int F_283 ( struct V_14 * V_14 , T_4 V_257 , T_4 V_282 ,
int V_129 , T_11 * V_280 ,
struct V_1 * V_323 )
{
struct V_238 * V_79 ;
struct V_284 * V_285 ;
void * V_246 ;
struct V_1 * V_4 ;
int V_29 ;
struct V_67 * V_68 = NULL ;
bool V_286 ;
int V_28 ;
V_4 = F_284 ( & V_14 -> V_79 ,
struct V_1 , V_25 ) ;
V_288:
V_29 = F_265 ( & V_68 , V_14 , V_257 , V_280 ) ;
if ( V_29 )
return V_29 ;
V_246 = F_243 ( V_68 , V_257 , V_282 , & V_250 , V_129 | V_289 ,
V_324 ) ;
if ( ! V_246 )
return - V_252 ;
if ( F_257 ( V_68 , V_256 , V_14 -> V_3 -> V_254 ) )
goto V_291;
V_79 = F_255 ( V_68 , V_325 ) ;
if ( ! V_79 )
goto V_291;
V_28 = 0 ;
V_286 = false ;
if ( V_323 ) {
V_29 = F_282 ( V_68 , V_323 ) ;
if ( V_29 )
goto V_293;
} else if ( V_4 ) {
F_269 (port, &team->port_list, list) {
V_29 = F_282 ( V_68 , V_4 ) ;
if ( V_29 ) {
if ( V_29 == - V_252 ) {
if ( ! V_28 )
goto V_293;
V_286 = true ;
break;
}
goto V_293;
}
V_28 ++ ;
}
}
F_263 ( V_68 , V_79 ) ;
F_244 ( V_68 , V_246 ) ;
if ( V_286 )
goto V_288;
V_294:
V_285 = F_270 ( V_68 , V_257 , V_282 , V_295 , 0 , V_129 | V_289 ) ;
if ( ! V_285 ) {
V_29 = F_265 ( & V_68 , V_14 , V_257 , V_280 ) ;
if ( V_29 )
goto V_293;
goto V_294;
}
return V_280 ( V_68 , V_14 , V_257 ) ;
V_291:
V_29 = - V_252 ;
V_293:
F_271 ( V_68 , V_246 ) ;
F_247 ( V_68 ) ;
return V_29 ;
}
static int F_285 ( struct V_67 * V_68 ,
struct V_244 * V_32 )
{
struct V_14 * V_14 ;
int V_29 ;
V_14 = F_248 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
V_29 = F_283 ( V_14 , V_32 -> V_248 , V_32 -> V_249 ,
V_296 , F_252 , NULL ) ;
F_251 ( V_14 ) ;
return V_29 ;
}
static int F_286 ( struct V_67 * V_68 ,
struct V_14 * V_14 , T_4 V_257 )
{
return F_287 ( F_253 ( V_14 -> V_3 ) , V_68 , 0 ,
V_326 . V_327 , V_30 ) ;
}
static int F_281 ( struct V_14 * V_14 ,
struct V_106 * V_283 )
{
return F_267 ( V_14 , 0 , 0 , 0 , F_286 ,
V_283 ) ;
}
static int F_288 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
return F_283 ( V_14 , 0 , 0 , 0 , F_286 ,
V_4 ) ;
}
static int F_289 ( void )
{
int V_29 ;
V_29 = F_290 ( & V_250 , V_328 ,
F_180 ( V_328 ) ) ;
if ( V_29 )
return V_29 ;
V_29 = F_291 ( & V_250 , & V_326 ) ;
if ( V_29 )
goto V_329;
return 0 ;
V_329:
F_292 ( & V_250 ) ;
return V_29 ;
}
static void F_293 ( void )
{
F_292 ( & V_250 ) ;
}
static void F_34 ( struct V_14 * V_14 )
{
int V_29 ;
struct V_23 * V_24 ;
F_273 ( V_283 ) ;
F_14 (opt_inst, &team->option_inst_list, list) {
if ( V_24 -> V_34 )
F_22 ( & V_24 -> V_287 , & V_283 ) ;
}
V_29 = F_281 ( V_14 , & V_283 ) ;
if ( V_29 && V_29 != - V_330 )
F_294 ( V_14 -> V_3 , L_29 ,
V_29 ) ;
}
static void F_295 ( struct V_1 * V_4 , bool V_15 )
{
int V_29 ;
V_4 -> V_34 = true ;
V_4 -> V_18 . V_15 = V_15 ;
F_12 ( V_4 ) ;
if ( V_15 ) {
struct V_331 V_332 ;
V_29 = F_296 ( V_4 -> V_3 , & V_332 ) ;
if ( ! V_29 ) {
V_4 -> V_18 . V_320 = F_297 ( & V_332 ) ;
V_4 -> V_18 . V_322 = V_332 . V_322 ;
goto V_333;
}
}
V_4 -> V_18 . V_320 = 0 ;
V_4 -> V_18 . V_322 = 0 ;
V_333:
V_29 = F_288 ( V_4 -> V_14 , V_4 ) ;
if ( V_29 && V_29 != - V_330 )
F_294 ( V_4 -> V_14 -> V_3 , L_30 ,
V_4 -> V_3 -> V_22 , V_29 ) ;
}
static void F_298 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
bool V_334 ;
if ( V_14 -> V_71 )
return;
V_334 = false ;
F_14 (port, &team->port_list, list) {
if ( V_4 -> V_15 ) {
V_334 = true ;
break;
}
}
if ( V_334 )
F_223 ( V_14 -> V_3 ) ;
else
F_181 ( V_14 -> V_3 ) ;
}
static void F_299 ( struct V_1 * V_4 , bool V_15 )
{
if ( V_4 -> V_18 . V_15 != V_15 )
F_295 ( V_4 , V_15 ) ;
F_298 ( V_4 -> V_14 ) ;
}
static void F_140 ( struct V_1 * V_4 , bool V_15 )
{
F_295 ( V_4 , V_15 ) ;
F_298 ( V_4 -> V_14 ) ;
}
static void F_149 ( struct V_1 * V_4 )
{
V_4 -> V_35 = true ;
F_295 ( V_4 , false ) ;
F_298 ( V_4 -> V_14 ) ;
}
static void F_300 ( struct V_1 * V_4 , bool V_15 )
{
struct V_14 * V_14 = V_4 -> V_14 ;
F_121 ( & V_14 -> V_134 ) ;
F_299 ( V_4 , V_15 ) ;
F_122 ( & V_14 -> V_134 ) ;
}
static int F_301 ( struct V_335 * V_168 ,
unsigned long V_336 , void * V_273 )
{
struct V_2 * V_3 = F_302 ( V_273 ) ;
struct V_1 * V_4 ;
V_4 = F_4 ( V_3 ) ;
if ( ! V_4 )
return V_337 ;
switch ( V_336 ) {
case V_338 :
if ( F_141 ( V_3 ) )
F_300 ( V_4 , true ) ;
case V_339 :
F_300 ( V_4 , false ) ;
case V_340 :
if ( F_74 ( V_4 -> V_3 ) )
F_300 ( V_4 ,
! ! F_141 ( V_4 -> V_3 ) ) ;
break;
case V_341 :
F_220 ( V_4 -> V_14 -> V_3 , V_3 ) ;
break;
case V_342 :
F_120 ( V_4 -> V_14 ) ;
break;
case V_343 :
return V_344 ;
case V_216 :
return V_344 ;
case V_90 :
F_69 ( V_336 , V_4 -> V_14 -> V_3 ) ;
break;
}
return V_337 ;
}
static int T_12 F_303 ( void )
{
int V_29 ;
F_304 ( & V_345 ) ;
V_29 = F_305 ( & V_346 ) ;
if ( V_29 )
goto V_347;
V_29 = F_289 () ;
if ( V_29 )
goto V_348;
return 0 ;
V_348:
F_306 ( & V_346 ) ;
V_347:
F_307 ( & V_345 ) ;
return V_29 ;
}
static void T_13 F_308 ( void )
{
F_293 () ;
F_306 ( & V_346 ) ;
F_307 ( & V_345 ) ;
}
