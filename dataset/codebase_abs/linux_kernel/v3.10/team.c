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
static void F_58 ( struct V_14 * V_14 , int V_72 )
{
if ( ! V_72 || ! F_56 ( V_14 ) ||
! V_14 -> V_58 -> V_73 -> V_74 )
V_14 -> V_73 . V_74 = F_53 ;
else
V_14 -> V_73 . V_74 = V_14 -> V_58 -> V_73 -> V_74 ;
if ( ! V_72 || ! F_56 ( V_14 ) ||
! V_14 -> V_58 -> V_73 -> V_75 )
V_14 -> V_73 . V_75 = F_55 ;
else
V_14 -> V_73 . V_75 = V_14 -> V_58 -> V_73 -> V_75 ;
}
static void F_59 ( struct V_14 * V_14 )
{
F_58 ( V_14 , V_14 -> V_72 ) ;
}
static int F_60 ( struct V_14 * V_14 ,
const struct V_59 * V_76 )
{
if ( F_56 ( V_14 ) ) {
void (* F_61)( struct V_14 * V_14 ) = V_14 -> V_73 . exit ;
memset ( & V_14 -> V_73 , 0 , sizeof( struct V_77 ) ) ;
F_59 ( V_14 ) ;
if ( F_61 )
F_61 ( V_14 ) ;
F_51 ( V_14 -> V_58 ) ;
F_57 ( V_14 ) ;
memset ( & V_14 -> V_78 , 0 ,
sizeof( struct V_14 ) - F_62 ( struct V_14 , V_78 ) ) ;
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
F_59 ( V_14 ) ;
return 0 ;
}
static int F_63 ( struct V_14 * V_14 , const char * V_56 )
{
const struct V_59 * V_76 ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_29 ;
if ( ! F_64 ( & V_14 -> V_79 ) ) {
F_65 ( V_3 , L_2 ) ;
return - V_80 ;
}
if ( F_56 ( V_14 ) && strcmp ( V_14 -> V_58 -> V_56 , V_56 ) == 0 ) {
F_65 ( V_3 , L_3 ) ;
return - V_62 ;
}
V_76 = F_48 ( V_56 ) ;
if ( ! V_76 ) {
F_65 ( V_3 , L_4 , V_56 ) ;
return - V_62 ;
}
V_29 = F_60 ( V_14 , V_76 ) ;
if ( V_29 ) {
F_65 ( V_3 , L_5 , V_56 ) ;
F_51 ( V_76 ) ;
return V_29 ;
}
F_66 ( V_3 , L_6 , V_56 ) ;
return 0 ;
}
static T_2 F_67 ( struct V_67 * * V_81 )
{
struct V_67 * V_68 = * V_81 ;
struct V_1 * V_4 ;
struct V_14 * V_14 ;
T_2 V_82 ;
V_68 = F_68 ( V_68 , V_83 ) ;
if ( ! V_68 )
return V_84 ;
* V_81 = V_68 ;
V_4 = F_1 ( V_68 -> V_3 ) ;
V_14 = V_4 -> V_14 ;
if ( ! F_69 ( V_4 ) ) {
V_82 = V_85 ;
} else {
V_82 = V_14 -> V_73 . V_75 ( V_14 , V_4 , V_68 ) ;
}
if ( V_82 == V_69 ) {
struct V_86 * V_87 ;
V_87 = F_70 ( V_14 -> V_87 ) ;
F_71 ( & V_87 -> V_88 ) ;
V_87 -> V_89 ++ ;
V_87 -> V_90 += V_68 -> V_91 ;
if ( V_68 -> V_92 == V_93 )
V_87 -> V_94 ++ ;
F_72 ( & V_87 -> V_88 ) ;
V_68 -> V_3 = V_14 -> V_3 ;
} else {
F_73 ( V_14 -> V_87 -> V_95 ) ;
}
return V_82 ;
}
static int F_74 ( struct V_14 * V_14 )
{
struct V_96 * V_97 ;
unsigned int V_98 = V_14 -> V_3 -> V_99 - 1 ;
unsigned int V_28 ;
if ( ! V_98 )
return 0 ;
V_97 = F_21 ( sizeof( struct V_96 ) * V_98 , V_30 ) ;
if ( ! V_97 )
return - V_31 ;
V_14 -> V_100 = V_97 ;
for ( V_28 = 0 ; V_28 < V_98 ; V_28 ++ )
F_75 ( V_97 ++ ) ;
return 0 ;
}
static void F_76 ( struct V_14 * V_14 )
{
F_17 ( V_14 -> V_100 ) ;
}
static struct V_96 * F_77 ( struct V_14 * V_14 , T_3 V_101 )
{
return & V_14 -> V_100 [ V_101 - 1 ] ;
}
static bool F_78 ( struct V_14 * V_14 , struct V_67 * V_68 )
{
struct V_96 * V_102 ;
struct V_1 * V_4 ;
if ( ! V_14 -> V_103 || ! V_68 -> V_104 )
return false ;
V_102 = F_77 ( V_14 , V_68 -> V_104 ) ;
F_79 (port, qom_list, qom_list) {
if ( ! F_80 ( V_14 , V_4 , V_68 ) )
return true ;
}
return false ;
}
static void F_81 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
F_82 ( & V_4 -> V_102 ) ;
F_83 () ;
F_75 ( & V_4 -> V_102 ) ;
}
static bool F_84 ( struct V_1 * V_4 ,
struct V_1 * V_105 )
{
if ( V_4 -> V_106 < V_105 -> V_106 )
return true ;
if ( V_4 -> V_106 > V_105 -> V_106 )
return false ;
if ( V_4 -> V_107 < V_105 -> V_107 )
return true ;
return false ;
}
static void F_85 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
struct V_1 * V_105 ;
struct V_96 * V_102 ;
struct V_96 * V_108 ;
if ( ! V_4 -> V_101 || ! F_69 ( V_4 ) )
return;
V_102 = F_77 ( V_14 , V_4 -> V_101 ) ;
V_108 = V_102 ;
F_14 (cur, qom_list, qom_list) {
if ( F_84 ( V_4 , V_105 ) )
break;
V_108 = & V_105 -> V_102 ;
}
F_86 ( & V_4 -> V_102 , V_108 ) ;
}
static void F_87 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
bool V_109 = false ;
F_14 (port, &team->port_list, list) {
if ( ! F_64 ( & V_4 -> V_102 ) ) {
V_109 = true ;
break;
}
}
if ( V_109 == V_14 -> V_103 )
return;
F_88 ( V_14 -> V_3 , L_7 ,
V_109 ? L_8 : L_9 ) ;
V_14 -> V_103 = V_109 ;
}
static void F_89 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
F_81 ( V_14 , V_4 ) ;
F_85 ( V_14 , V_4 ) ;
F_87 ( V_14 ) ;
}
static bool F_90 ( const struct V_14 * V_14 ,
const struct V_1 * V_4 )
{
struct V_1 * V_105 ;
F_14 (cur, &team->port_list, list)
if ( V_105 == V_4 )
return true ;
return false ;
}
static void F_91 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
if ( F_69 ( V_4 ) )
return;
V_4 -> V_107 = V_14 -> V_72 ++ ;
F_92 ( & V_4 -> V_110 ,
F_93 ( V_14 , V_4 -> V_107 ) ) ;
F_59 ( V_14 ) ;
F_89 ( V_14 , V_4 ) ;
if ( V_14 -> V_73 . V_111 )
V_14 -> V_73 . V_111 ( V_14 , V_4 ) ;
}
static void F_94 ( struct V_14 * V_14 , int V_112 )
{
int V_28 ;
struct V_1 * V_4 ;
for ( V_28 = V_112 + 1 ; V_28 < V_14 -> V_72 ; V_28 ++ ) {
V_4 = F_95 ( V_14 , V_28 ) ;
F_96 ( & V_4 -> V_110 ) ;
V_4 -> V_107 -- ;
F_92 ( & V_4 -> V_110 ,
F_93 ( V_14 , V_4 -> V_107 ) ) ;
}
}
static void F_97 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
if ( ! F_69 ( V_4 ) )
return;
if ( V_14 -> V_73 . V_113 )
V_14 -> V_73 . V_113 ( V_14 , V_4 ) ;
F_96 ( & V_4 -> V_110 ) ;
F_94 ( V_14 , V_4 -> V_107 ) ;
V_4 -> V_107 = - 1 ;
F_89 ( V_14 , V_4 ) ;
F_58 ( V_14 , V_14 -> V_72 - 1 ) ;
F_83 () ;
V_14 -> V_72 -- ;
}
static void F_98 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
T_4 V_114 = V_115 ;
unsigned short V_116 = V_117 ;
unsigned int V_118 , V_119 = V_120 ;
F_14 (port, &team->port_list, list) {
V_114 = F_99 ( V_114 ,
V_4 -> V_3 -> V_114 ,
V_115 ) ;
V_119 &= V_4 -> V_3 -> V_121 ;
if ( V_4 -> V_3 -> V_122 > V_116 )
V_116 = V_4 -> V_3 -> V_122 ;
}
V_14 -> V_3 -> V_114 = V_114 ;
V_14 -> V_3 -> V_122 = V_116 ;
V_118 = V_14 -> V_3 -> V_121 & ~ V_120 ;
V_14 -> V_3 -> V_121 = V_118 | V_119 ;
F_100 ( V_14 -> V_3 ) ;
}
static void F_101 ( struct V_14 * V_14 )
{
F_102 ( & V_14 -> V_123 ) ;
F_98 ( V_14 ) ;
F_103 ( & V_14 -> V_123 ) ;
}
static int F_104 ( struct V_14 * V_14 , struct V_1 * V_4 )
{
int V_29 = 0 ;
F_105 ( V_14 -> V_3 ) ;
V_4 -> V_3 -> V_121 |= V_124 ;
if ( V_14 -> V_73 . V_125 ) {
V_29 = V_14 -> V_73 . V_125 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_65 ( V_14 -> V_3 , L_10 ,
V_4 -> V_3 -> V_22 ) ;
goto V_126;
}
}
return 0 ;
V_126:
V_4 -> V_3 -> V_121 &= ~ V_124 ;
F_106 ( V_14 -> V_3 ) ;
return V_29 ;
}
static void F_107 ( struct V_14 * V_14 , struct V_1 * V_4 )
{
if ( V_14 -> V_73 . V_127 )
V_14 -> V_73 . V_127 ( V_14 , V_4 ) ;
V_4 -> V_3 -> V_121 &= ~ V_124 ;
F_106 ( V_14 -> V_3 ) ;
}
static int F_108 ( struct V_14 * V_14 , struct V_1 * V_4 ,
T_5 V_128 )
{
struct V_129 * V_130 ;
int V_29 ;
V_130 = F_29 ( sizeof( * V_130 ) , V_128 ) ;
if ( ! V_130 )
return - V_31 ;
V_29 = F_109 ( V_130 , V_4 -> V_3 , V_128 ) ;
if ( V_29 ) {
F_17 ( V_130 ) ;
return V_29 ;
}
V_4 -> V_130 = V_130 ;
return V_29 ;
}
static void F_110 ( struct V_1 * V_4 )
{
struct V_129 * V_130 = V_4 -> V_130 ;
if ( ! V_130 )
return;
V_4 -> V_130 = NULL ;
F_111 () ;
F_112 ( V_130 ) ;
F_17 ( V_130 ) ;
}
static struct V_131 * F_113 ( struct V_14 * V_14 )
{
return V_14 -> V_3 -> V_132 ;
}
static int F_108 ( struct V_14 * V_14 , struct V_1 * V_4 ,
T_5 V_128 )
{
return 0 ;
}
static void F_110 ( struct V_1 * V_4 )
{
}
static struct V_131 * F_113 ( struct V_14 * V_14 )
{
return NULL ;
}
static int F_114 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_4 ;
char * V_133 = V_6 -> V_22 ;
int V_29 ;
if ( V_6 -> V_118 & V_134 ) {
F_65 ( V_3 , L_11 ,
V_133 ) ;
return - V_62 ;
}
if ( F_3 ( V_6 ) ) {
F_65 ( V_3 , L_12
L_13 , V_133 ) ;
return - V_80 ;
}
if ( V_6 -> V_135 & V_136 &&
F_115 ( V_3 ) ) {
F_65 ( V_3 , L_14 ,
V_133 ) ;
return - V_137 ;
}
V_29 = F_116 ( V_3 , V_6 ) ;
if ( V_29 )
return V_29 ;
if ( V_6 -> V_118 & V_138 ) {
F_65 ( V_3 , L_15 ,
V_133 ) ;
return - V_80 ;
}
V_4 = F_29 ( sizeof( struct V_1 ) + V_14 -> V_58 -> V_139 ,
V_30 ) ;
if ( ! V_4 )
return - V_31 ;
V_4 -> V_3 = V_6 ;
V_4 -> V_14 = V_14 ;
F_75 ( & V_4 -> V_102 ) ;
V_4 -> V_13 . V_140 = V_6 -> V_140 ;
V_29 = F_117 ( V_6 , V_3 -> V_140 ) ;
if ( V_29 ) {
F_88 ( V_3 , L_16 , V_29 ) ;
goto V_141;
}
memcpy ( V_4 -> V_13 . V_7 , V_6 -> V_7 , V_6 -> V_11 ) ;
V_29 = F_104 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_65 ( V_3 , L_10 ,
V_133 ) ;
goto V_126;
}
V_29 = F_118 ( V_6 ) ;
if ( V_29 ) {
F_88 ( V_3 , L_17 ,
V_133 ) ;
goto V_142;
}
V_29 = F_119 ( V_6 , V_3 ) ;
if ( V_29 ) {
F_65 ( V_3 , L_18 ,
V_133 ) ;
goto V_143;
}
if ( F_113 ( V_14 ) ) {
V_29 = F_108 ( V_14 , V_4 , V_30 ) ;
if ( V_29 ) {
F_65 ( V_3 , L_19 ,
V_133 ) ;
goto V_144;
}
}
V_29 = F_120 ( V_6 , V_3 ) ;
if ( V_29 ) {
F_65 ( V_3 , L_20 ,
V_133 ) ;
goto V_145;
}
V_29 = F_121 ( V_6 , F_67 ,
V_4 ) ;
if ( V_29 ) {
F_65 ( V_3 , L_21 ,
V_133 ) ;
goto V_146;
}
V_29 = F_26 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_65 ( V_3 , L_22 ,
V_133 ) ;
goto V_147;
}
V_4 -> V_107 = - 1 ;
F_86 ( & V_4 -> V_25 , & V_14 -> V_79 ) ;
F_91 ( V_14 , V_4 ) ;
F_98 ( V_14 ) ;
F_122 ( V_4 , ! ! F_123 ( V_6 ) ) ;
F_34 ( V_14 ) ;
F_66 ( V_3 , L_23 , V_133 ) ;
return 0 ;
V_147:
F_124 ( V_6 ) ;
V_146:
F_125 ( V_6 , V_3 ) ;
V_145:
F_110 ( V_4 ) ;
V_144:
F_126 ( V_6 , V_3 ) ;
V_143:
F_127 ( V_6 ) ;
V_142:
F_107 ( V_14 , V_4 ) ;
F_8 ( V_4 ) ;
V_126:
F_117 ( V_6 , V_4 -> V_13 . V_140 ) ;
V_141:
F_17 ( V_4 ) ;
return V_29 ;
}
static int F_128 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_4 ;
char * V_133 = V_6 -> V_22 ;
V_4 = F_4 ( V_6 ) ;
if ( ! V_4 || ! F_90 ( V_14 , V_4 ) ) {
F_65 ( V_3 , L_24 ,
V_133 ) ;
return - V_148 ;
}
F_97 ( V_14 , V_4 ) ;
F_82 ( & V_4 -> V_25 ) ;
F_124 ( V_6 ) ;
F_125 ( V_6 , V_3 ) ;
F_110 ( V_4 ) ;
F_126 ( V_6 , V_3 ) ;
F_129 ( V_6 , V_3 ) ;
F_130 ( V_6 , V_3 ) ;
F_127 ( V_6 ) ;
F_107 ( V_14 , V_4 ) ;
F_27 ( V_14 , V_4 ) ;
F_34 ( V_14 ) ;
F_25 ( V_14 , V_4 ) ;
F_131 ( V_4 ) ;
F_8 ( V_4 ) ;
F_117 ( V_6 , V_4 -> V_13 . V_140 ) ;
F_83 () ;
F_17 ( V_4 ) ;
F_66 ( V_3 , L_25 , V_133 ) ;
F_98 ( V_14 ) ;
return 0 ;
}
static int F_132 ( struct V_14 * V_14 , struct V_48 * V_49 )
{
V_49 -> V_149 . V_150 = V_14 -> V_58 -> V_56 ;
return 0 ;
}
static int F_133 ( struct V_14 * V_14 , struct V_48 * V_49 )
{
return F_63 ( V_14 , V_49 -> V_149 . V_150 ) ;
}
static int F_134 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_149 . V_151 = F_69 ( V_4 ) ;
return 0 ;
}
static int F_135 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
if ( V_49 -> V_149 . V_151 )
F_91 ( V_14 , V_4 ) ;
else
F_97 ( V_14 , V_4 ) ;
return 0 ;
}
static int F_136 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_149 . V_151 = V_4 -> V_16 . V_15 ;
return 0 ;
}
static int F_137 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_4 -> V_16 . V_15 = V_49 -> V_149 . V_151 ;
F_12 ( V_4 ) ;
return 0 ;
}
static int F_138 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_149 . V_151 = V_4 -> V_16 . V_17 ;
return 0 ;
}
static int F_139 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_4 -> V_16 . V_17 = V_49 -> V_149 . V_151 ;
F_12 ( V_4 ) ;
return 0 ;
}
static int F_140 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_149 . V_152 = V_4 -> V_106 ;
return 0 ;
}
static int F_141 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_4 -> V_106 = V_49 -> V_149 . V_152 ;
F_89 ( V_14 , V_4 ) ;
return 0 ;
}
static int F_142 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_149 . V_153 = V_4 -> V_101 ;
return 0 ;
}
static int F_143 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
if ( V_4 -> V_101 == V_49 -> V_149 . V_153 )
return 0 ;
if ( V_49 -> V_149 . V_153 >= V_14 -> V_3 -> V_154 )
return - V_62 ;
V_4 -> V_101 = V_49 -> V_149 . V_153 ;
F_89 ( V_14 , V_4 ) ;
return 0 ;
}
static void F_144 ( struct V_2 * V_3 ,
struct V_155 * V_156 ,
void * V_157 )
{
F_145 ( & V_156 -> V_158 , & V_159 ) ;
}
static void F_146 ( struct V_2 * V_3 )
{
F_145 ( & V_3 -> V_160 , & V_161 ) ;
F_147 ( V_3 , F_144 , NULL ) ;
V_3 -> V_162 = & V_163 ;
}
static int F_148 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_149 ( V_3 ) ;
int V_28 ;
int V_29 ;
V_14 -> V_3 = V_3 ;
F_150 ( & V_14 -> V_123 ) ;
F_57 ( V_14 ) ;
V_14 -> V_87 = F_151 ( struct V_86 ) ;
if ( ! V_14 -> V_87 )
return - V_31 ;
for ( V_28 = 0 ; V_28 < V_164 ; V_28 ++ )
F_152 ( & V_14 -> V_165 [ V_28 ] ) ;
F_75 ( & V_14 -> V_79 ) ;
V_29 = F_74 ( V_14 ) ;
if ( V_29 )
goto V_166;
F_59 ( V_14 ) ;
F_75 ( & V_14 -> V_46 ) ;
F_75 ( & V_14 -> V_36 ) ;
V_29 = F_33 ( V_14 , V_167 , F_153 ( V_167 ) ) ;
if ( V_29 )
goto V_168;
F_154 ( V_3 ) ;
F_146 ( V_3 ) ;
return 0 ;
V_168:
F_76 ( V_14 ) ;
V_166:
F_155 ( V_14 -> V_87 ) ;
return V_29 ;
}
static void F_156 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_149 ( V_3 ) ;
struct V_1 * V_4 ;
struct V_1 * V_26 ;
F_102 ( & V_14 -> V_123 ) ;
F_19 (port, tmp, &team->port_list, list)
F_128 ( V_14 , V_4 -> V_3 ) ;
F_60 ( V_14 , NULL ) ;
F_32 ( V_14 , V_167 , F_153 ( V_167 ) ) ;
F_76 ( V_14 ) ;
F_103 ( & V_14 -> V_123 ) ;
}
static void F_157 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_149 ( V_3 ) ;
F_155 ( V_14 -> V_87 ) ;
F_158 ( V_3 ) ;
}
static int F_159 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_160 ( struct V_2 * V_3 )
{
return 0 ;
}
static T_6 F_161 ( struct V_67 * V_68 , struct V_2 * V_3 )
{
struct V_14 * V_14 = F_149 ( V_3 ) ;
bool V_169 ;
unsigned int V_91 = V_68 -> V_91 ;
V_169 = F_78 ( V_14 , V_68 ) ;
if ( ! V_169 )
V_169 = V_14 -> V_73 . V_74 ( V_14 , V_68 ) ;
if ( V_169 ) {
struct V_86 * V_87 ;
V_87 = F_70 ( V_14 -> V_87 ) ;
F_71 ( & V_87 -> V_88 ) ;
V_87 -> V_170 ++ ;
V_87 -> V_171 += V_91 ;
F_72 ( & V_87 -> V_88 ) ;
} else {
F_73 ( V_14 -> V_87 -> V_172 ) ;
}
return V_173 ;
}
static T_3 F_162 ( struct V_2 * V_3 , struct V_67 * V_68 )
{
T_3 V_156 = F_163 ( V_68 ) ? F_164 ( V_68 ) : 0 ;
F_165 ( V_68 ) -> V_174 = V_68 -> V_104 ;
if ( F_166 ( V_156 >= V_3 -> V_154 ) ) {
do {
V_156 -= V_3 -> V_154 ;
} while ( V_156 >= V_3 -> V_154 );
}
return V_156 ;
}
static void F_167 ( struct V_2 * V_3 , int V_175 )
{
struct V_14 * V_14 = F_149 ( V_3 ) ;
struct V_1 * V_4 ;
int V_176 ;
F_168 () ;
F_79 (port, &team->port_list, list) {
if ( V_175 & V_177 ) {
V_176 = V_3 -> V_118 & V_177 ? 1 : - 1 ;
F_169 ( V_4 -> V_3 , V_176 ) ;
}
if ( V_175 & V_178 ) {
V_176 = V_3 -> V_118 & V_178 ? 1 : - 1 ;
F_170 ( V_4 -> V_3 , V_176 ) ;
}
}
F_171 () ;
}
static void F_172 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_149 ( V_3 ) ;
struct V_1 * V_4 ;
F_168 () ;
F_79 (port, &team->port_list, list) {
F_173 ( V_4 -> V_3 , V_3 ) ;
F_174 ( V_4 -> V_3 , V_3 ) ;
}
F_171 () ;
}
static int F_175 ( struct V_2 * V_3 , void * V_179 )
{
struct V_8 * V_9 = V_179 ;
struct V_14 * V_14 = F_149 ( V_3 ) ;
struct V_1 * V_4 ;
if ( V_3 -> type == V_180 && ! F_176 ( V_9 -> V_10 ) )
return - V_181 ;
memcpy ( V_3 -> V_7 , V_9 -> V_10 , V_3 -> V_11 ) ;
F_168 () ;
F_79 (port, &team->port_list, list)
if ( V_14 -> V_73 . V_182 )
V_14 -> V_73 . V_182 ( V_14 , V_4 ) ;
F_171 () ;
return 0 ;
}
static int F_177 ( struct V_2 * V_3 , int V_183 )
{
struct V_14 * V_14 = F_149 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 ;
F_102 ( & V_14 -> V_123 ) ;
F_14 (port, &team->port_list, list) {
V_29 = F_117 ( V_4 -> V_3 , V_183 ) ;
if ( V_29 ) {
F_65 ( V_3 , L_26 ,
V_4 -> V_3 -> V_22 ) ;
goto V_184;
}
}
F_103 ( & V_14 -> V_123 ) ;
V_3 -> V_140 = V_183 ;
return 0 ;
V_184:
F_178 (port, &team->port_list, list)
F_117 ( V_4 -> V_3 , V_3 -> V_140 ) ;
F_103 ( & V_14 -> V_123 ) ;
return V_29 ;
}
static struct V_185 *
F_179 ( struct V_2 * V_3 , struct V_185 * V_186 )
{
struct V_14 * V_14 = F_149 ( V_3 ) ;
struct V_86 * V_179 ;
T_7 V_89 , V_90 , V_94 , V_170 , V_171 ;
T_4 V_95 = 0 , V_172 = 0 ;
unsigned int V_187 ;
int V_28 ;
F_180 (i) {
V_179 = F_181 ( V_14 -> V_87 , V_28 ) ;
do {
V_187 = F_182 ( & V_179 -> V_88 ) ;
V_89 = V_179 -> V_89 ;
V_90 = V_179 -> V_90 ;
V_94 = V_179 -> V_94 ;
V_170 = V_179 -> V_170 ;
V_171 = V_179 -> V_171 ;
} while ( F_183 ( & V_179 -> V_88 , V_187 ) );
V_186 -> V_89 += V_89 ;
V_186 -> V_90 += V_90 ;
V_186 -> V_188 += V_94 ;
V_186 -> V_170 += V_170 ;
V_186 -> V_171 += V_171 ;
V_95 += V_179 -> V_95 ;
V_172 += V_179 -> V_172 ;
}
V_186 -> V_95 = V_95 ;
V_186 -> V_172 = V_172 ;
return V_186 ;
}
static int F_184 ( struct V_2 * V_3 , T_8 V_189 , T_3 V_190 )
{
struct V_14 * V_14 = F_149 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 ;
F_102 ( & V_14 -> V_123 ) ;
F_14 (port, &team->port_list, list) {
V_29 = F_185 ( V_4 -> V_3 , V_189 , V_190 ) ;
if ( V_29 )
goto V_184;
}
F_103 ( & V_14 -> V_123 ) ;
return 0 ;
V_184:
F_178 (port, &team->port_list, list)
F_186 ( V_4 -> V_3 , V_189 , V_190 ) ;
F_103 ( & V_14 -> V_123 ) ;
return V_29 ;
}
static int F_187 ( struct V_2 * V_3 , T_8 V_189 , T_3 V_190 )
{
struct V_14 * V_14 = F_149 ( V_3 ) ;
struct V_1 * V_4 ;
F_168 () ;
F_79 (port, &team->port_list, list)
F_186 ( V_4 -> V_3 , V_189 , V_190 ) ;
F_171 () ;
return 0 ;
}
static void F_188 ( struct V_2 * V_3 )
{
}
static void F_189 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
F_14 (port, &team->port_list, list)
F_110 ( V_4 ) ;
}
static void F_190 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_149 ( V_3 ) ;
F_102 ( & V_14 -> V_123 ) ;
F_189 ( V_14 ) ;
F_103 ( & V_14 -> V_123 ) ;
}
static int F_191 ( struct V_2 * V_3 ,
struct V_131 * V_191 , T_5 V_128 )
{
struct V_14 * V_14 = F_149 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 = 0 ;
F_102 ( & V_14 -> V_123 ) ;
F_14 (port, &team->port_list, list) {
V_29 = F_108 ( V_14 , V_4 , V_128 ) ;
if ( V_29 ) {
F_189 ( V_14 ) ;
break;
}
}
F_103 ( & V_14 -> V_123 ) ;
return V_29 ;
}
static int F_192 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_149 ( V_3 ) ;
int V_29 ;
F_102 ( & V_14 -> V_123 ) ;
V_29 = F_114 ( V_14 , V_6 ) ;
F_103 ( & V_14 -> V_123 ) ;
return V_29 ;
}
static int F_193 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_149 ( V_3 ) ;
int V_29 ;
F_102 ( & V_14 -> V_123 ) ;
V_29 = F_128 ( V_14 , V_6 ) ;
F_103 ( & V_14 -> V_123 ) ;
return V_29 ;
}
static T_9 F_194 ( struct V_2 * V_3 ,
T_9 V_135 )
{
struct V_1 * V_4 ;
struct V_14 * V_14 = F_149 ( V_3 ) ;
T_9 V_192 ;
V_192 = V_135 ;
V_135 &= ~ V_193 ;
V_135 |= V_194 ;
F_168 () ;
F_79 (port, &team->port_list, list) {
V_135 = F_99 ( V_135 ,
V_4 -> V_3 -> V_135 ,
V_192 ) ;
}
F_171 () ;
return V_135 ;
}
static int F_195 ( struct V_2 * V_3 , bool V_195 )
{
struct V_14 * V_14 = F_149 ( V_3 ) ;
V_14 -> V_71 = true ;
if ( V_195 )
F_196 ( V_3 ) ;
else
F_154 ( V_3 ) ;
return 0 ;
}
static void F_197 ( struct V_2 * V_3 ,
struct V_196 * V_197 )
{
F_198 ( V_197 -> V_198 , V_199 , sizeof( V_197 -> V_198 ) ) ;
F_198 ( V_197 -> V_200 , V_201 , sizeof( V_197 -> V_200 ) ) ;
}
static void F_199 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
V_3 -> V_202 = V_6 -> V_202 ;
V_3 -> type = V_6 -> type ;
V_3 -> V_122 = V_6 -> V_122 ;
V_3 -> V_11 = V_6 -> V_11 ;
V_3 -> V_140 = V_6 -> V_140 ;
memcpy ( V_3 -> V_203 , V_6 -> V_203 , V_6 -> V_11 ) ;
memcpy ( V_3 -> V_7 , V_6 -> V_7 , V_6 -> V_11 ) ;
}
static int F_116 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
struct V_14 * V_14 = F_149 ( V_3 ) ;
char * V_133 = V_6 -> V_22 ;
int V_29 ;
if ( V_3 -> type == V_6 -> type )
return 0 ;
if ( ! F_64 ( & V_14 -> V_79 ) ) {
F_65 ( V_3 , L_27 , V_133 ) ;
return - V_80 ;
}
V_29 = F_200 ( V_204 , V_3 ) ;
V_29 = F_201 ( V_29 ) ;
if ( V_29 ) {
F_65 ( V_3 , L_28 ) ;
return V_29 ;
}
F_202 ( V_3 ) ;
F_203 ( V_3 ) ;
F_199 ( V_3 , V_6 ) ;
F_200 ( V_205 , V_3 ) ;
return 0 ;
}
static void F_204 ( struct V_2 * V_3 )
{
F_205 ( V_3 ) ;
V_3 -> V_206 = & V_207 ;
V_3 -> V_208 = & V_209 ;
V_3 -> V_210 = F_157 ;
V_3 -> V_211 = 0 ;
V_3 -> V_118 |= V_212 ;
V_3 -> V_121 &= ~ ( V_120 | V_213 ) ;
V_3 -> V_121 |= V_214 | V_215 ;
V_3 -> V_135 |= V_216 ;
V_3 -> V_135 |= V_217 ;
V_3 -> V_218 = V_115 |
V_219 |
V_220 |
V_221 ;
V_3 -> V_218 &= ~ ( V_222 & ~ V_223 ) ;
V_3 -> V_135 |= V_3 -> V_218 ;
}
static int F_206 ( struct V_224 * V_225 , struct V_2 * V_3 ,
struct V_226 * V_227 [] , struct V_226 * V_149 [] )
{
int V_29 ;
if ( V_227 [ V_228 ] == NULL )
F_207 ( V_3 ) ;
V_29 = F_208 ( V_3 ) ;
if ( V_29 )
return V_29 ;
return 0 ;
}
static int F_209 ( struct V_226 * V_227 [] , struct V_226 * V_149 [] )
{
if ( V_227 [ V_228 ] ) {
if ( F_210 ( V_227 [ V_228 ] ) != V_229 )
return - V_62 ;
if ( ! F_176 ( F_211 ( V_227 [ V_228 ] ) ) )
return - V_181 ;
}
return 0 ;
}
static unsigned int F_212 ( void )
{
return V_230 ;
}
static unsigned int F_213 ( void )
{
return V_231 ;
}
static int F_214 ( struct V_67 * V_68 , struct V_232 * V_32 )
{
struct V_67 * V_233 ;
void * V_234 ;
int V_29 ;
V_233 = F_215 ( V_235 , V_30 ) ;
if ( ! V_233 )
return - V_31 ;
V_234 = F_216 ( V_233 , V_32 -> V_236 , V_32 -> V_237 ,
& V_238 , 0 , V_239 ) ;
if ( ! V_234 ) {
V_29 = - V_240 ;
goto V_241;
}
F_217 ( V_233 , V_234 ) ;
return F_218 ( F_219 ( V_32 ) , V_233 , V_32 -> V_236 ) ;
V_241:
F_220 ( V_233 ) ;
return V_29 ;
}
static struct V_14 * F_221 ( struct V_232 * V_32 )
{
struct V_224 * V_224 = F_219 ( V_32 ) ;
int V_242 ;
struct V_2 * V_3 ;
struct V_14 * V_14 ;
if ( ! V_32 -> V_243 [ V_244 ] )
return NULL ;
V_242 = F_222 ( V_32 -> V_243 [ V_244 ] ) ;
V_3 = F_223 ( V_224 , V_242 ) ;
if ( ! V_3 || V_3 -> V_206 != & V_207 ) {
if ( V_3 )
F_106 ( V_3 ) ;
return NULL ;
}
V_14 = F_149 ( V_3 ) ;
F_102 ( & V_14 -> V_123 ) ;
return V_14 ;
}
static void F_224 ( struct V_14 * V_14 )
{
F_103 ( & V_14 -> V_123 ) ;
F_106 ( V_14 -> V_3 ) ;
}
static int F_225 ( struct V_67 * V_68 , struct V_14 * V_14 , T_4 V_245 )
{
return F_218 ( F_226 ( V_14 -> V_3 ) , V_68 , V_245 ) ;
}
static int F_227 ( struct V_67 * V_68 , struct V_14 * V_14 ,
struct V_23 * V_24 )
{
struct V_226 * V_246 ;
struct V_19 * V_21 = V_24 -> V_21 ;
struct V_53 * V_54 = & V_24 -> V_32 ;
struct V_48 V_49 ;
int V_29 ;
V_49 . V_32 = V_54 ;
V_29 = F_36 ( V_14 , V_24 , & V_49 ) ;
if ( V_29 )
return V_29 ;
V_246 = F_228 ( V_68 , V_247 ) ;
if ( ! V_246 )
return - V_240 ;
if ( F_229 ( V_68 , V_248 , V_21 -> V_22 ) )
goto V_249;
if ( V_54 -> V_4 &&
F_230 ( V_68 , V_250 ,
V_54 -> V_4 -> V_3 -> V_242 ) )
goto V_249;
if ( V_24 -> V_21 -> V_27 &&
F_230 ( V_68 , V_251 ,
V_54 -> V_33 ) )
goto V_249;
switch ( V_21 -> type ) {
case V_252 :
if ( F_231 ( V_68 , V_253 , V_254 ) )
goto V_249;
if ( F_230 ( V_68 , V_255 , V_49 . V_149 . V_153 ) )
goto V_249;
break;
case V_256 :
if ( F_231 ( V_68 , V_253 , V_257 ) )
goto V_249;
if ( F_229 ( V_68 , V_255 ,
V_49 . V_149 . V_150 ) )
goto V_249;
break;
case V_258 :
if ( F_231 ( V_68 , V_253 , V_259 ) )
goto V_249;
if ( F_232 ( V_68 , V_255 , V_49 . V_149 . V_260 . V_91 ,
V_49 . V_149 . V_260 . V_261 ) )
goto V_249;
break;
case V_262 :
if ( F_231 ( V_68 , V_253 , V_263 ) )
goto V_249;
if ( V_49 . V_149 . V_151 &&
F_233 ( V_68 , V_255 ) )
goto V_249;
break;
case V_264 :
if ( F_231 ( V_68 , V_253 , V_265 ) )
goto V_249;
if ( F_234 ( V_68 , V_255 , V_49 . V_149 . V_152 ) )
goto V_249;
break;
default:
F_235 () ;
}
if ( V_24 -> V_35 && F_233 ( V_68 , V_266 ) )
goto V_249;
if ( V_24 -> V_34 ) {
if ( F_233 ( V_68 , V_267 ) )
goto V_249;
V_24 -> V_34 = false ;
}
F_236 ( V_68 , V_246 ) ;
return 0 ;
V_249:
F_237 ( V_68 , V_246 ) ;
return - V_240 ;
}
static int F_238 ( struct V_67 * * V_81 ,
struct V_14 * V_14 , T_4 V_245 ,
T_10 * V_268 )
{
int V_29 ;
if ( * V_81 ) {
V_29 = V_268 ( * V_81 , V_14 , V_245 ) ;
if ( V_29 )
return V_29 ;
}
* V_81 = F_239 ( V_269 , V_30 ) ;
if ( ! * V_81 )
return - V_31 ;
return 0 ;
}
static int F_240 ( struct V_14 * V_14 , T_4 V_245 , T_4 V_270 ,
int V_118 , T_10 * V_268 ,
struct V_96 * V_271 )
{
struct V_226 * V_46 ;
struct V_272 * V_273 ;
void * V_234 ;
struct V_23 * V_24 ;
int V_29 ;
struct V_67 * V_68 = NULL ;
bool V_274 ;
int V_28 ;
V_24 = F_241 ( V_271 ,
struct V_23 , V_275 ) ;
V_276:
V_29 = F_238 ( & V_68 , V_14 , V_245 , V_268 ) ;
if ( V_29 )
return V_29 ;
V_234 = F_216 ( V_68 , V_245 , V_270 , & V_238 , V_118 | V_277 ,
V_278 ) ;
if ( ! V_234 )
return - V_240 ;
if ( F_230 ( V_68 , V_244 , V_14 -> V_3 -> V_242 ) )
goto V_279;
V_46 = F_228 ( V_68 , V_280 ) ;
if ( ! V_46 )
goto V_279;
V_28 = 0 ;
V_274 = false ;
F_242 (opt_inst, sel_opt_inst_list, tmp_list) {
V_29 = F_227 ( V_68 , V_14 , V_24 ) ;
if ( V_29 ) {
if ( V_29 == - V_240 ) {
if ( ! V_28 )
goto V_281;
V_274 = true ;
break;
}
goto V_281;
}
V_28 ++ ;
}
F_236 ( V_68 , V_46 ) ;
F_217 ( V_68 , V_234 ) ;
if ( V_274 )
goto V_276;
V_282:
V_273 = F_243 ( V_68 , V_245 , V_270 , V_283 , 0 , V_118 | V_277 ) ;
if ( ! V_273 ) {
V_29 = F_238 ( & V_68 , V_14 , V_245 , V_268 ) ;
if ( V_29 )
goto V_281;
goto V_282;
}
return V_268 ( V_68 , V_14 , V_245 ) ;
V_279:
V_29 = - V_240 ;
V_281:
F_244 ( V_68 , V_234 ) ;
F_220 ( V_68 ) ;
return V_29 ;
}
static int F_245 ( struct V_67 * V_68 , struct V_232 * V_32 )
{
struct V_14 * V_14 ;
struct V_23 * V_24 ;
int V_29 ;
F_246 ( V_271 ) ;
V_14 = F_221 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
F_14 (opt_inst, &team->option_inst_list, list)
F_22 ( & V_24 -> V_275 , & V_271 ) ;
V_29 = F_240 ( V_14 , V_32 -> V_236 , V_32 -> V_237 ,
V_284 , F_225 ,
& V_271 ) ;
F_224 ( V_14 ) ;
return V_29 ;
}
static int F_247 ( struct V_67 * V_68 , struct V_232 * V_32 )
{
struct V_14 * V_14 ;
int V_29 = 0 ;
int V_28 ;
struct V_226 * V_285 ;
F_246 ( V_286 ) ;
V_14 = F_221 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
V_29 = - V_62 ;
if ( ! V_32 -> V_243 [ V_280 ] ) {
V_29 = - V_62 ;
goto V_287;
}
F_248 (nl_option, info->attrs[TEAM_ATTR_LIST_OPTION], i) {
struct V_226 * V_288 [ V_289 + 1 ] ;
struct V_226 * V_290 ;
struct V_226 * V_291 ;
enum V_292 V_293 ;
int V_294 = 0 ;
T_4 V_295 = 0 ;
bool V_296 = false ;
struct V_23 * V_24 ;
char * V_20 ;
bool V_297 = false ;
if ( F_249 ( V_285 ) != V_247 ) {
V_29 = - V_62 ;
goto V_287;
}
V_29 = F_250 ( V_288 , V_289 ,
V_285 , V_298 ) ;
if ( V_29 )
goto V_287;
if ( ! V_288 [ V_248 ] ||
! V_288 [ V_253 ] ) {
V_29 = - V_62 ;
goto V_287;
}
switch ( F_251 ( V_288 [ V_253 ] ) ) {
case V_254 :
V_293 = V_252 ;
break;
case V_257 :
V_293 = V_256 ;
break;
case V_259 :
V_293 = V_258 ;
break;
case V_263 :
V_293 = V_262 ;
break;
case V_265 :
V_293 = V_264 ;
break;
default:
goto V_287;
}
V_291 = V_288 [ V_255 ] ;
if ( V_293 != V_262 && ! V_291 ) {
V_29 = - V_62 ;
goto V_287;
}
V_20 = F_211 ( V_288 [ V_248 ] ) ;
V_290 = V_288 [ V_250 ] ;
if ( V_290 )
V_294 = F_222 ( V_290 ) ;
V_290 = V_288 [ V_251 ] ;
if ( V_290 ) {
V_296 = true ;
V_295 = F_222 ( V_290 ) ;
}
F_14 (opt_inst, &team->option_inst_list, list) {
struct V_19 * V_21 = V_24 -> V_21 ;
struct V_48 V_49 ;
struct V_53 * V_54 ;
int V_299 ;
V_54 = & V_24 -> V_32 ;
V_299 = V_54 -> V_4 ?
V_54 -> V_4 -> V_3 -> V_242 : 0 ;
if ( V_21 -> type != V_293 ||
strcmp ( V_21 -> V_22 , V_20 ) ||
V_299 != V_294 ||
( V_21 -> V_27 && ! V_296 ) ||
V_54 -> V_33 != V_295 )
continue;
V_297 = true ;
V_49 . V_32 = V_54 ;
switch ( V_293 ) {
case V_252 :
V_49 . V_149 . V_153 = F_222 ( V_291 ) ;
break;
case V_256 :
if ( F_210 ( V_291 ) > V_300 ) {
V_29 = - V_62 ;
goto V_287;
}
V_49 . V_149 . V_150 = F_211 ( V_291 ) ;
break;
case V_258 :
V_49 . V_149 . V_260 . V_91 = F_210 ( V_291 ) ;
V_49 . V_149 . V_260 . V_261 = F_211 ( V_291 ) ;
break;
case V_262 :
V_49 . V_149 . V_151 = V_291 ? true : false ;
break;
case V_264 :
V_49 . V_149 . V_152 = F_252 ( V_291 ) ;
break;
default:
F_235 () ;
}
V_29 = F_37 ( V_14 , V_24 , & V_49 ) ;
if ( V_29 )
goto V_287;
V_24 -> V_34 = true ;
F_253 ( & V_24 -> V_275 , & V_286 ) ;
}
if ( ! V_297 ) {
V_29 = - V_148 ;
goto V_287;
}
}
V_29 = F_254 ( V_14 , & V_286 ) ;
V_287:
F_224 ( V_14 ) ;
return V_29 ;
}
static int F_255 ( struct V_67 * V_68 ,
struct V_1 * V_4 )
{
struct V_226 * V_301 ;
V_301 = F_228 ( V_68 , V_302 ) ;
if ( ! V_301 )
goto V_249;
if ( F_230 ( V_68 , V_303 , V_4 -> V_3 -> V_242 ) )
goto V_249;
if ( V_4 -> V_34 ) {
if ( F_233 ( V_68 , V_304 ) )
goto V_249;
V_4 -> V_34 = false ;
}
if ( ( V_4 -> V_35 &&
F_233 ( V_68 , V_305 ) ) ||
( V_4 -> V_18 . V_15 &&
F_233 ( V_68 , V_306 ) ) ||
F_230 ( V_68 , V_307 , V_4 -> V_18 . V_308 ) ||
F_231 ( V_68 , V_309 , V_4 -> V_18 . V_310 ) )
goto V_249;
F_236 ( V_68 , V_301 ) ;
return 0 ;
V_249:
F_237 ( V_68 , V_301 ) ;
return - V_240 ;
}
static int F_256 ( struct V_14 * V_14 , T_4 V_245 , T_4 V_270 ,
int V_118 , T_10 * V_268 ,
struct V_1 * V_311 )
{
struct V_226 * V_79 ;
struct V_272 * V_273 ;
void * V_234 ;
struct V_1 * V_4 ;
int V_29 ;
struct V_67 * V_68 = NULL ;
bool V_274 ;
int V_28 ;
V_4 = F_257 ( & V_14 -> V_79 ,
struct V_1 , V_25 ) ;
V_276:
V_29 = F_238 ( & V_68 , V_14 , V_245 , V_268 ) ;
if ( V_29 )
return V_29 ;
V_234 = F_216 ( V_68 , V_245 , V_270 , & V_238 , V_118 | V_277 ,
V_312 ) ;
if ( ! V_234 )
return - V_240 ;
if ( F_230 ( V_68 , V_244 , V_14 -> V_3 -> V_242 ) )
goto V_279;
V_79 = F_228 ( V_68 , V_313 ) ;
if ( ! V_79 )
goto V_279;
V_28 = 0 ;
V_274 = false ;
if ( V_311 ) {
V_29 = F_255 ( V_68 , V_311 ) ;
if ( V_29 )
goto V_281;
} else if ( V_4 ) {
F_242 (port, &team->port_list, list) {
V_29 = F_255 ( V_68 , V_4 ) ;
if ( V_29 ) {
if ( V_29 == - V_240 ) {
if ( ! V_28 )
goto V_281;
V_274 = true ;
break;
}
goto V_281;
}
V_28 ++ ;
}
}
F_236 ( V_68 , V_79 ) ;
F_217 ( V_68 , V_234 ) ;
if ( V_274 )
goto V_276;
V_282:
V_273 = F_243 ( V_68 , V_245 , V_270 , V_283 , 0 , V_118 | V_277 ) ;
if ( ! V_273 ) {
V_29 = F_238 ( & V_68 , V_14 , V_245 , V_268 ) ;
if ( V_29 )
goto V_281;
goto V_282;
}
return V_268 ( V_68 , V_14 , V_245 ) ;
V_279:
V_29 = - V_240 ;
V_281:
F_244 ( V_68 , V_234 ) ;
F_220 ( V_68 ) ;
return V_29 ;
}
static int F_258 ( struct V_67 * V_68 ,
struct V_232 * V_32 )
{
struct V_14 * V_14 ;
int V_29 ;
V_14 = F_221 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
V_29 = F_256 ( V_14 , V_32 -> V_236 , V_32 -> V_237 ,
V_284 , F_225 , NULL ) ;
F_224 ( V_14 ) ;
return V_29 ;
}
static int F_259 ( struct V_67 * V_68 ,
struct V_14 * V_14 , T_4 V_245 )
{
return F_260 ( F_226 ( V_14 -> V_3 ) , V_68 , 0 ,
V_314 . V_315 , V_30 ) ;
}
static int F_254 ( struct V_14 * V_14 ,
struct V_96 * V_271 )
{
return F_240 ( V_14 , 0 , 0 , 0 , F_259 ,
V_271 ) ;
}
static int F_261 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
return F_256 ( V_14 , 0 , 0 , 0 , F_259 ,
V_4 ) ;
}
static int F_262 ( void )
{
int V_29 ;
V_29 = F_263 ( & V_238 , V_316 ,
F_153 ( V_316 ) ) ;
if ( V_29 )
return V_29 ;
V_29 = F_264 ( & V_238 , & V_314 ) ;
if ( V_29 )
goto V_317;
return 0 ;
V_317:
F_265 ( & V_238 ) ;
return V_29 ;
}
static void F_266 ( void )
{
F_265 ( & V_238 ) ;
}
static void F_34 ( struct V_14 * V_14 )
{
int V_29 ;
struct V_23 * V_24 ;
F_246 ( V_271 ) ;
F_14 (opt_inst, &team->option_inst_list, list) {
if ( V_24 -> V_34 )
F_22 ( & V_24 -> V_275 , & V_271 ) ;
}
V_29 = F_254 ( V_14 , & V_271 ) ;
if ( V_29 && V_29 != - V_318 )
F_267 ( V_14 -> V_3 , L_29 ,
V_29 ) ;
}
static void F_268 ( struct V_1 * V_4 , bool V_15 )
{
int V_29 ;
V_4 -> V_34 = true ;
V_4 -> V_18 . V_15 = V_15 ;
F_12 ( V_4 ) ;
if ( V_15 ) {
struct V_319 V_320 ;
V_29 = F_269 ( V_4 -> V_3 , & V_320 ) ;
if ( ! V_29 ) {
V_4 -> V_18 . V_308 = F_270 ( & V_320 ) ;
V_4 -> V_18 . V_310 = V_320 . V_310 ;
goto V_321;
}
}
V_4 -> V_18 . V_308 = 0 ;
V_4 -> V_18 . V_310 = 0 ;
V_321:
V_29 = F_261 ( V_4 -> V_14 , V_4 ) ;
if ( V_29 && V_29 != - V_318 )
F_267 ( V_4 -> V_14 -> V_3 , L_30 ,
V_4 -> V_3 -> V_22 , V_29 ) ;
}
static void F_271 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
bool V_322 ;
if ( V_14 -> V_71 )
return;
V_322 = false ;
F_14 (port, &team->port_list, list) {
if ( V_4 -> V_15 ) {
V_322 = true ;
break;
}
}
if ( V_322 )
F_196 ( V_14 -> V_3 ) ;
else
F_154 ( V_14 -> V_3 ) ;
}
static void F_272 ( struct V_1 * V_4 , bool V_15 )
{
if ( V_4 -> V_18 . V_15 != V_15 )
F_268 ( V_4 , V_15 ) ;
F_271 ( V_4 -> V_14 ) ;
}
static void F_122 ( struct V_1 * V_4 , bool V_15 )
{
F_268 ( V_4 , V_15 ) ;
F_271 ( V_4 -> V_14 ) ;
}
static void F_131 ( struct V_1 * V_4 )
{
V_4 -> V_35 = true ;
F_268 ( V_4 , false ) ;
F_271 ( V_4 -> V_14 ) ;
}
static void F_273 ( struct V_1 * V_4 , bool V_15 )
{
struct V_14 * V_14 = V_4 -> V_14 ;
F_102 ( & V_14 -> V_123 ) ;
F_272 ( V_4 , V_15 ) ;
F_103 ( & V_14 -> V_123 ) ;
}
static int F_274 ( struct V_323 * V_157 ,
unsigned long V_324 , void * V_261 )
{
struct V_2 * V_3 = (struct V_2 * ) V_261 ;
struct V_1 * V_4 ;
V_4 = F_4 ( V_3 ) ;
if ( ! V_4 )
return V_325 ;
switch ( V_324 ) {
case V_326 :
if ( F_123 ( V_3 ) )
F_273 ( V_4 , true ) ;
case V_327 :
F_273 ( V_4 , false ) ;
case V_328 :
if ( F_275 ( V_4 -> V_3 ) )
F_273 ( V_4 ,
! ! F_123 ( V_4 -> V_3 ) ) ;
break;
case V_329 :
F_193 ( V_4 -> V_14 -> V_3 , V_3 ) ;
break;
case V_330 :
F_101 ( V_4 -> V_14 ) ;
break;
case V_331 :
return V_332 ;
case V_204 :
return V_332 ;
}
return V_325 ;
}
static int T_11 F_276 ( void )
{
int V_29 ;
F_277 ( & V_333 ) ;
V_29 = F_278 ( & V_334 ) ;
if ( V_29 )
goto V_335;
V_29 = F_262 () ;
if ( V_29 )
goto V_336;
return 0 ;
V_336:
F_279 ( & V_334 ) ;
V_335:
F_280 ( & V_333 ) ;
return V_29 ;
}
static void T_12 F_281 ( void )
{
F_266 () ;
F_279 ( & V_334 ) ;
F_280 ( & V_333 ) ;
}
