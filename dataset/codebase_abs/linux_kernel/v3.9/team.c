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
int F_9 ( struct V_1 * V_4 )
{
return F_6 ( V_4 -> V_3 , V_4 -> V_14 -> V_3 -> V_7 ) ;
}
static void F_10 ( struct V_1 * V_4 )
{
V_4 -> V_15 = V_4 -> V_16 . V_17 ? V_4 -> V_16 . V_15 :
V_4 -> V_18 . V_15 ;
}
static struct V_19 * F_11 ( struct V_14 * V_14 ,
const char * V_20 )
{
struct V_19 * V_21 ;
F_12 (option, &team->option_list, list) {
if ( strcmp ( V_21 -> V_22 , V_20 ) == 0 )
return V_21 ;
}
return NULL ;
}
static void F_13 ( struct V_23 * V_24 )
{
F_14 ( & V_24 -> V_25 ) ;
F_15 ( V_24 ) ;
}
static void F_16 ( struct V_14 * V_14 ,
struct V_19 * V_21 )
{
struct V_23 * V_24 , * V_26 ;
F_17 (opt_inst, tmp, &team->option_inst_list, list) {
if ( V_24 -> V_21 == V_21 )
F_13 ( V_24 ) ;
}
}
static int F_18 ( struct V_14 * V_14 , struct V_19 * V_21 ,
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
V_24 = F_19 ( sizeof( * V_24 ) , V_30 ) ;
if ( ! V_24 )
return - V_31 ;
V_24 -> V_21 = V_21 ;
V_24 -> V_32 . V_4 = V_4 ;
V_24 -> V_32 . V_33 = V_28 ;
V_24 -> V_34 = true ;
V_24 -> V_35 = false ;
F_20 ( & V_24 -> V_25 , & V_14 -> V_36 ) ;
if ( V_21 -> V_37 ) {
V_29 = V_21 -> V_37 ( V_14 , & V_24 -> V_32 ) ;
if ( V_29 )
return V_29 ;
}
}
return 0 ;
}
static int F_21 ( struct V_14 * V_14 ,
struct V_19 * V_21 )
{
struct V_1 * V_4 ;
int V_29 ;
if ( ! V_21 -> V_38 ) {
V_29 = F_18 ( V_14 , V_21 , NULL ) ;
if ( V_29 )
goto V_39;
}
F_12 (port, &team->port_list, list) {
V_29 = F_18 ( V_14 , V_21 , V_4 ) ;
if ( V_29 )
goto V_39;
}
return 0 ;
V_39:
F_16 ( V_14 , V_21 ) ;
return V_29 ;
}
static void F_22 ( struct V_14 * V_14 ,
struct V_19 * V_21 )
{
struct V_23 * V_24 ;
F_12 (opt_inst, &team->option_inst_list, list) {
if ( V_24 -> V_21 == V_21 ) {
V_24 -> V_34 = true ;
V_24 -> V_35 = true ;
}
}
}
static void F_23 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
struct V_23 * V_24 , * V_26 ;
F_17 (opt_inst, tmp, &team->option_inst_list, list) {
if ( V_24 -> V_21 -> V_38 &&
V_24 -> V_32 . V_4 == V_4 )
F_13 ( V_24 ) ;
}
}
static int F_24 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
struct V_19 * V_21 ;
int V_29 ;
F_12 (option, &team->option_list, list) {
if ( ! V_21 -> V_38 )
continue;
V_29 = F_18 ( V_14 , V_21 , V_4 ) ;
if ( V_29 )
goto V_40;
}
return 0 ;
V_40:
F_23 ( V_14 , V_4 ) ;
return V_29 ;
}
static void F_25 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
struct V_23 * V_24 ;
F_12 (opt_inst, &team->option_inst_list, list) {
if ( V_24 -> V_32 . V_4 == V_4 ) {
V_24 -> V_34 = true ;
V_24 -> V_35 = true ;
}
}
}
static int F_26 ( struct V_14 * V_14 ,
const struct V_19 * V_21 ,
T_1 V_41 )
{
int V_28 ;
struct V_19 * * V_42 ;
int V_29 ;
V_42 = F_27 ( sizeof( struct V_19 * ) * V_41 ,
V_30 ) ;
if ( ! V_42 )
return - V_31 ;
for ( V_28 = 0 ; V_28 < V_41 ; V_28 ++ , V_21 ++ ) {
if ( F_11 ( V_14 , V_21 -> V_22 ) ) {
V_29 = - V_43 ;
goto V_44;
}
V_42 [ V_28 ] = F_28 ( V_21 , sizeof( * V_21 ) , V_30 ) ;
if ( ! V_42 [ V_28 ] ) {
V_29 = - V_31 ;
goto V_44;
}
}
for ( V_28 = 0 ; V_28 < V_41 ; V_28 ++ ) {
V_29 = F_21 ( V_14 , V_42 [ V_28 ] ) ;
if ( V_29 )
goto V_45;
F_20 ( & V_42 [ V_28 ] -> V_25 , & V_14 -> V_46 ) ;
}
F_15 ( V_42 ) ;
return 0 ;
V_45:
for ( V_28 -- ; V_28 >= 0 ; V_28 -- )
F_16 ( V_14 , V_42 [ V_28 ] ) ;
V_28 = V_41 - 1 ;
V_44:
for ( V_28 -- ; V_28 >= 0 ; V_28 -- )
F_15 ( V_42 [ V_28 ] ) ;
F_15 ( V_42 ) ;
return V_29 ;
}
static void F_29 ( struct V_14 * V_14 ,
const struct V_19 * V_21 ,
T_1 V_41 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_41 ; V_28 ++ , V_21 ++ ) {
struct V_19 * V_47 ;
V_47 = F_11 ( V_14 , V_21 -> V_22 ) ;
if ( V_47 )
F_22 ( V_14 , V_47 ) ;
}
}
static void F_30 ( struct V_14 * V_14 ,
const struct V_19 * V_21 ,
T_1 V_41 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_41 ; V_28 ++ , V_21 ++ ) {
struct V_19 * V_47 ;
V_47 = F_11 ( V_14 , V_21 -> V_22 ) ;
if ( V_47 ) {
F_16 ( V_14 , V_47 ) ;
F_14 ( & V_47 -> V_25 ) ;
F_15 ( V_47 ) ;
}
}
}
int F_31 ( struct V_14 * V_14 ,
const struct V_19 * V_21 ,
T_1 V_41 )
{
int V_29 ;
V_29 = F_26 ( V_14 , V_21 , V_41 ) ;
if ( V_29 )
return V_29 ;
F_32 ( V_14 ) ;
return 0 ;
}
void F_33 ( struct V_14 * V_14 ,
const struct V_19 * V_21 ,
T_1 V_41 )
{
F_29 ( V_14 , V_21 , V_41 ) ;
F_32 ( V_14 ) ;
F_30 ( V_14 , V_21 , V_41 ) ;
}
static int F_34 ( struct V_14 * V_14 ,
struct V_23 * V_24 ,
struct V_48 * V_49 )
{
if ( ! V_24 -> V_21 -> V_50 )
return - V_51 ;
return V_24 -> V_21 -> V_50 ( V_14 , V_49 ) ;
}
static int F_35 ( struct V_14 * V_14 ,
struct V_23 * V_24 ,
struct V_48 * V_49 )
{
if ( ! V_24 -> V_21 -> V_52 )
return - V_51 ;
return V_24 -> V_21 -> V_52 ( V_14 , V_49 ) ;
}
void F_36 ( struct V_53 * V_54 )
{
struct V_23 * V_24 ;
V_24 = F_37 ( V_54 , struct V_23 , V_32 ) ;
V_24 -> V_34 = true ;
}
void F_38 ( struct V_14 * V_14 )
{
F_32 ( V_14 ) ;
}
static struct V_55 * F_39 ( const char * V_56 )
{
struct V_55 * V_57 ;
F_12 (mitem, &mode_list, list) {
if ( strcmp ( V_57 -> V_58 -> V_56 , V_56 ) == 0 )
return V_57 ;
}
return NULL ;
}
static bool F_40 ( const char * V_22 )
{
while ( * V_22 != '\0' ) {
if ( ! isalpha ( * V_22 ) && ! isdigit ( * V_22 ) && * V_22 != '_' )
return false ;
V_22 ++ ;
}
return true ;
}
int F_41 ( const struct V_59 * V_58 )
{
int V_29 = 0 ;
struct V_55 * V_57 ;
if ( ! F_40 ( V_58 -> V_56 ) ||
V_58 -> V_60 > V_61 )
return - V_62 ;
V_57 = F_19 ( sizeof( * V_57 ) , V_30 ) ;
if ( ! V_57 )
return - V_31 ;
F_42 ( & V_63 ) ;
if ( F_39 ( V_58 -> V_56 ) ) {
V_29 = - V_43 ;
F_15 ( V_57 ) ;
goto V_64;
}
V_57 -> V_58 = V_58 ;
F_20 ( & V_57 -> V_25 , & V_65 ) ;
V_64:
F_43 ( & V_63 ) ;
return V_29 ;
}
void F_44 ( const struct V_59 * V_58 )
{
struct V_55 * V_57 ;
F_42 ( & V_63 ) ;
V_57 = F_39 ( V_58 -> V_56 ) ;
if ( V_57 ) {
F_45 ( & V_57 -> V_25 ) ;
F_15 ( V_57 ) ;
}
F_43 ( & V_63 ) ;
}
static const struct V_59 * F_46 ( const char * V_56 )
{
struct V_55 * V_57 ;
const struct V_59 * V_58 = NULL ;
F_42 ( & V_63 ) ;
V_57 = F_39 ( V_56 ) ;
if ( ! V_57 ) {
F_43 ( & V_63 ) ;
F_47 ( L_1 , V_56 ) ;
F_42 ( & V_63 ) ;
V_57 = F_39 ( V_56 ) ;
}
if ( V_57 ) {
V_58 = V_57 -> V_58 ;
if ( ! F_48 ( V_58 -> V_66 ) )
V_58 = NULL ;
}
F_43 ( & V_63 ) ;
return V_58 ;
}
static void F_49 ( const struct V_59 * V_58 )
{
F_50 ( V_58 -> V_66 ) ;
}
static bool F_51 ( struct V_14 * V_14 , struct V_67 * V_68 )
{
F_52 ( V_68 ) ;
return false ;
}
T_2 F_53 ( struct V_14 * V_14 ,
struct V_1 * V_4 ,
struct V_67 * V_68 )
{
return V_69 ;
}
static bool F_54 ( struct V_14 * V_14 )
{
return V_14 -> V_58 != & V_70 ;
}
static void F_55 ( struct V_14 * V_14 )
{
V_14 -> V_71 = false ;
V_14 -> V_58 = & V_70 ;
}
static void F_56 ( struct V_14 * V_14 , int V_72 )
{
if ( ! V_72 || ! F_54 ( V_14 ) ||
! V_14 -> V_58 -> V_73 -> V_74 )
V_14 -> V_73 . V_74 = F_51 ;
else
V_14 -> V_73 . V_74 = V_14 -> V_58 -> V_73 -> V_74 ;
if ( ! V_72 || ! F_54 ( V_14 ) ||
! V_14 -> V_58 -> V_73 -> V_75 )
V_14 -> V_73 . V_75 = F_53 ;
else
V_14 -> V_73 . V_75 = V_14 -> V_58 -> V_73 -> V_75 ;
}
static void F_57 ( struct V_14 * V_14 )
{
F_56 ( V_14 , V_14 -> V_72 ) ;
}
static int F_58 ( struct V_14 * V_14 ,
const struct V_59 * V_76 )
{
if ( F_54 ( V_14 ) ) {
void (* F_59)( struct V_14 * V_14 ) = V_14 -> V_73 . exit ;
memset ( & V_14 -> V_73 , 0 , sizeof( struct V_77 ) ) ;
F_57 ( V_14 ) ;
if ( F_59 )
F_59 ( V_14 ) ;
F_49 ( V_14 -> V_58 ) ;
F_55 ( V_14 ) ;
memset ( & V_14 -> V_78 , 0 ,
sizeof( struct V_14 ) - F_60 ( struct V_14 , V_78 ) ) ;
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
F_57 ( V_14 ) ;
return 0 ;
}
static int F_61 ( struct V_14 * V_14 , const char * V_56 )
{
const struct V_59 * V_76 ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_29 ;
if ( ! F_62 ( & V_14 -> V_79 ) ) {
F_63 ( V_3 , L_2 ) ;
return - V_80 ;
}
if ( F_54 ( V_14 ) && strcmp ( V_14 -> V_58 -> V_56 , V_56 ) == 0 ) {
F_63 ( V_3 , L_3 ) ;
return - V_62 ;
}
V_76 = F_46 ( V_56 ) ;
if ( ! V_76 ) {
F_63 ( V_3 , L_4 , V_56 ) ;
return - V_62 ;
}
V_29 = F_58 ( V_14 , V_76 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_5 , V_56 ) ;
F_49 ( V_76 ) ;
return V_29 ;
}
F_64 ( V_3 , L_6 , V_56 ) ;
return 0 ;
}
static T_2 F_65 ( struct V_67 * * V_81 )
{
struct V_67 * V_68 = * V_81 ;
struct V_1 * V_4 ;
struct V_14 * V_14 ;
T_2 V_82 ;
V_68 = F_66 ( V_68 , V_83 ) ;
if ( ! V_68 )
return V_84 ;
* V_81 = V_68 ;
V_4 = F_1 ( V_68 -> V_3 ) ;
V_14 = V_4 -> V_14 ;
if ( ! F_67 ( V_4 ) ) {
V_82 = V_85 ;
} else {
V_82 = V_14 -> V_73 . V_75 ( V_14 , V_4 , V_68 ) ;
}
if ( V_82 == V_69 ) {
struct V_86 * V_87 ;
V_87 = F_68 ( V_14 -> V_87 ) ;
F_69 ( & V_87 -> V_88 ) ;
V_87 -> V_89 ++ ;
V_87 -> V_90 += V_68 -> V_91 ;
if ( V_68 -> V_92 == V_93 )
V_87 -> V_94 ++ ;
F_70 ( & V_87 -> V_88 ) ;
V_68 -> V_3 = V_14 -> V_3 ;
} else {
F_71 ( V_14 -> V_87 -> V_95 ) ;
}
return V_82 ;
}
static int F_72 ( struct V_14 * V_14 )
{
struct V_96 * V_97 ;
unsigned int V_98 = V_14 -> V_3 -> V_99 - 1 ;
unsigned int V_28 ;
if ( ! V_98 )
return 0 ;
V_97 = F_19 ( sizeof( struct V_96 ) * V_98 , V_30 ) ;
if ( ! V_97 )
return - V_31 ;
V_14 -> V_100 = V_97 ;
for ( V_28 = 0 ; V_28 < V_98 ; V_28 ++ )
F_73 ( V_97 ++ ) ;
return 0 ;
}
static void F_74 ( struct V_14 * V_14 )
{
F_15 ( V_14 -> V_100 ) ;
}
static struct V_96 * F_75 ( struct V_14 * V_14 , T_3 V_101 )
{
return & V_14 -> V_100 [ V_101 - 1 ] ;
}
static bool F_76 ( struct V_14 * V_14 , struct V_67 * V_68 )
{
struct V_96 * V_102 ;
struct V_1 * V_4 ;
if ( ! V_14 -> V_103 || ! V_68 -> V_104 )
return false ;
V_102 = F_75 ( V_14 , V_68 -> V_104 ) ;
F_77 (port, qom_list, qom_list) {
if ( ! F_78 ( V_14 , V_4 , V_68 ) )
return true ;
}
return false ;
}
static void F_79 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
F_80 ( & V_4 -> V_102 ) ;
F_81 () ;
F_73 ( & V_4 -> V_102 ) ;
}
static bool F_82 ( struct V_1 * V_4 ,
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
static void F_83 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
struct V_1 * V_105 ;
struct V_96 * V_102 ;
struct V_96 * V_108 ;
if ( ! V_4 -> V_101 || ! F_67 ( V_4 ) )
return;
V_102 = F_75 ( V_14 , V_4 -> V_101 ) ;
V_108 = V_102 ;
F_12 (cur, qom_list, qom_list) {
if ( F_82 ( V_4 , V_105 ) )
break;
V_108 = & V_105 -> V_102 ;
}
F_84 ( & V_4 -> V_102 , V_108 ) ;
}
static void F_85 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
bool V_109 = false ;
F_12 (port, &team->port_list, list) {
if ( ! F_62 ( & V_4 -> V_102 ) ) {
V_109 = true ;
break;
}
}
if ( V_109 == V_14 -> V_103 )
return;
F_86 ( V_14 -> V_3 , L_7 ,
V_109 ? L_8 : L_9 ) ;
V_14 -> V_103 = V_109 ;
}
static void F_87 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
F_79 ( V_14 , V_4 ) ;
F_83 ( V_14 , V_4 ) ;
F_85 ( V_14 ) ;
}
static bool F_88 ( const struct V_14 * V_14 ,
const struct V_1 * V_4 )
{
struct V_1 * V_105 ;
F_12 (cur, &team->port_list, list)
if ( V_105 == V_4 )
return true ;
return false ;
}
static void F_89 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
if ( F_67 ( V_4 ) )
return;
V_4 -> V_107 = V_14 -> V_72 ++ ;
F_90 ( & V_4 -> V_110 ,
F_91 ( V_14 , V_4 -> V_107 ) ) ;
F_57 ( V_14 ) ;
F_87 ( V_14 , V_4 ) ;
if ( V_14 -> V_73 . V_111 )
V_14 -> V_73 . V_111 ( V_14 , V_4 ) ;
}
static void F_92 ( struct V_14 * V_14 , int V_112 )
{
int V_28 ;
struct V_1 * V_4 ;
for ( V_28 = V_112 + 1 ; V_28 < V_14 -> V_72 ; V_28 ++ ) {
V_4 = F_93 ( V_14 , V_28 ) ;
F_94 ( & V_4 -> V_110 ) ;
V_4 -> V_107 -- ;
F_90 ( & V_4 -> V_110 ,
F_91 ( V_14 , V_4 -> V_107 ) ) ;
}
}
static void F_95 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
if ( ! F_67 ( V_4 ) )
return;
if ( V_14 -> V_73 . V_113 )
V_14 -> V_73 . V_113 ( V_14 , V_4 ) ;
F_94 ( & V_4 -> V_110 ) ;
F_92 ( V_14 , V_4 -> V_107 ) ;
V_4 -> V_107 = - 1 ;
F_87 ( V_14 , V_4 ) ;
F_56 ( V_14 , V_14 -> V_72 - 1 ) ;
F_81 () ;
V_14 -> V_72 -- ;
}
static void F_96 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
T_4 V_114 = V_115 ;
unsigned short V_116 = V_117 ;
unsigned int V_118 , V_119 = V_120 ;
F_12 (port, &team->port_list, list) {
V_114 = F_97 ( V_114 ,
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
F_98 ( V_14 -> V_3 ) ;
}
static void F_99 ( struct V_14 * V_14 )
{
F_100 ( & V_14 -> V_123 ) ;
F_96 ( V_14 ) ;
F_101 ( & V_14 -> V_123 ) ;
}
static int F_102 ( struct V_14 * V_14 , struct V_1 * V_4 )
{
int V_29 = 0 ;
F_103 ( V_14 -> V_3 ) ;
V_4 -> V_3 -> V_121 |= V_124 ;
if ( V_14 -> V_73 . V_125 ) {
V_29 = V_14 -> V_73 . V_125 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_63 ( V_14 -> V_3 , L_10 ,
V_4 -> V_3 -> V_22 ) ;
goto V_126;
}
}
return 0 ;
V_126:
V_4 -> V_3 -> V_121 &= ~ V_124 ;
F_104 ( V_14 -> V_3 ) ;
return V_29 ;
}
static void F_105 ( struct V_14 * V_14 , struct V_1 * V_4 )
{
if ( V_14 -> V_73 . V_127 )
V_14 -> V_73 . V_127 ( V_14 , V_4 ) ;
V_4 -> V_3 -> V_121 &= ~ V_124 ;
F_104 ( V_14 -> V_3 ) ;
}
static int F_106 ( struct V_14 * V_14 , struct V_1 * V_4 ,
T_5 V_128 )
{
struct V_129 * V_130 ;
int V_29 ;
V_130 = F_27 ( sizeof( * V_130 ) , V_128 ) ;
if ( ! V_130 )
return - V_31 ;
V_29 = F_107 ( V_130 , V_4 -> V_3 , V_128 ) ;
if ( V_29 ) {
F_15 ( V_130 ) ;
return V_29 ;
}
V_4 -> V_130 = V_130 ;
return V_29 ;
}
static void F_108 ( struct V_1 * V_4 )
{
struct V_129 * V_130 = V_4 -> V_130 ;
if ( ! V_130 )
return;
V_4 -> V_130 = NULL ;
F_109 () ;
F_110 ( V_130 ) ;
F_15 ( V_130 ) ;
}
static struct V_131 * F_111 ( struct V_14 * V_14 )
{
return V_14 -> V_3 -> V_132 ;
}
static int F_106 ( struct V_14 * V_14 , struct V_1 * V_4 ,
T_5 V_128 )
{
return 0 ;
}
static void F_108 ( struct V_1 * V_4 )
{
}
static struct V_131 * F_111 ( struct V_14 * V_14 )
{
return NULL ;
}
static int F_112 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_4 ;
char * V_133 = V_6 -> V_22 ;
int V_29 ;
if ( V_6 -> V_118 & V_134 ) {
F_63 ( V_3 , L_11 ,
V_133 ) ;
return - V_62 ;
}
if ( F_3 ( V_6 ) ) {
F_63 ( V_3 , L_12
L_13 , V_133 ) ;
return - V_80 ;
}
if ( V_6 -> V_135 & V_136 &&
F_113 ( V_3 ) ) {
F_63 ( V_3 , L_14 ,
V_133 ) ;
return - V_137 ;
}
V_29 = F_114 ( V_3 , V_6 ) ;
if ( V_29 )
return V_29 ;
if ( V_6 -> V_118 & V_138 ) {
F_63 ( V_3 , L_15 ,
V_133 ) ;
return - V_80 ;
}
V_4 = F_27 ( sizeof( struct V_1 ) + V_14 -> V_58 -> V_139 ,
V_30 ) ;
if ( ! V_4 )
return - V_31 ;
V_4 -> V_3 = V_6 ;
V_4 -> V_14 = V_14 ;
F_73 ( & V_4 -> V_102 ) ;
V_4 -> V_13 . V_140 = V_6 -> V_140 ;
V_29 = F_115 ( V_6 , V_3 -> V_140 ) ;
if ( V_29 ) {
F_86 ( V_3 , L_16 , V_29 ) ;
goto V_141;
}
memcpy ( V_4 -> V_13 . V_7 , V_6 -> V_7 , V_6 -> V_11 ) ;
V_29 = F_102 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_10 ,
V_133 ) ;
goto V_126;
}
V_29 = F_116 ( V_6 ) ;
if ( V_29 ) {
F_86 ( V_3 , L_17 ,
V_133 ) ;
goto V_142;
}
V_29 = F_117 ( V_6 , V_3 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_18 ,
V_133 ) ;
goto V_143;
}
if ( F_111 ( V_14 ) ) {
V_29 = F_106 ( V_14 , V_4 , V_30 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_19 ,
V_133 ) ;
goto V_144;
}
}
V_29 = F_118 ( V_6 , V_3 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_20 ,
V_133 ) ;
goto V_145;
}
V_29 = F_119 ( V_6 , F_65 ,
V_4 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_21 ,
V_133 ) ;
goto V_146;
}
V_29 = F_24 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_22 ,
V_133 ) ;
goto V_147;
}
V_4 -> V_107 = - 1 ;
F_89 ( V_14 , V_4 ) ;
F_84 ( & V_4 -> V_25 , & V_14 -> V_79 ) ;
F_96 ( V_14 ) ;
F_120 ( V_4 , ! ! F_121 ( V_6 ) ) ;
F_32 ( V_14 ) ;
F_64 ( V_3 , L_23 , V_133 ) ;
return 0 ;
V_147:
F_122 ( V_6 ) ;
V_146:
F_123 ( V_6 , V_3 ) ;
V_145:
F_108 ( V_4 ) ;
V_144:
F_124 ( V_6 , V_3 ) ;
V_143:
F_125 ( V_6 ) ;
V_142:
F_105 ( V_14 , V_4 ) ;
F_8 ( V_4 ) ;
V_126:
F_115 ( V_6 , V_4 -> V_13 . V_140 ) ;
V_141:
F_15 ( V_4 ) ;
return V_29 ;
}
static int F_126 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_4 ;
char * V_133 = V_6 -> V_22 ;
V_4 = F_4 ( V_6 ) ;
if ( ! V_4 || ! F_88 ( V_14 , V_4 ) ) {
F_63 ( V_3 , L_24 ,
V_133 ) ;
return - V_148 ;
}
F_95 ( V_14 , V_4 ) ;
F_80 ( & V_4 -> V_25 ) ;
F_122 ( V_6 ) ;
F_123 ( V_6 , V_3 ) ;
F_108 ( V_4 ) ;
F_124 ( V_6 , V_3 ) ;
F_127 ( V_6 , V_3 ) ;
F_128 ( V_6 , V_3 ) ;
F_125 ( V_6 ) ;
F_105 ( V_14 , V_4 ) ;
F_25 ( V_14 , V_4 ) ;
F_32 ( V_14 ) ;
F_23 ( V_14 , V_4 ) ;
F_129 ( V_4 ) ;
F_8 ( V_4 ) ;
F_115 ( V_6 , V_4 -> V_13 . V_140 ) ;
F_81 () ;
F_15 ( V_4 ) ;
F_64 ( V_3 , L_25 , V_133 ) ;
F_96 ( V_14 ) ;
return 0 ;
}
static int F_130 ( struct V_14 * V_14 , struct V_48 * V_49 )
{
V_49 -> V_149 . V_150 = V_14 -> V_58 -> V_56 ;
return 0 ;
}
static int F_131 ( struct V_14 * V_14 , struct V_48 * V_49 )
{
return F_61 ( V_14 , V_49 -> V_149 . V_150 ) ;
}
static int F_132 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_149 . V_151 = F_67 ( V_4 ) ;
return 0 ;
}
static int F_133 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
if ( V_49 -> V_149 . V_151 )
F_89 ( V_14 , V_4 ) ;
else
F_95 ( V_14 , V_4 ) ;
return 0 ;
}
static int F_134 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_149 . V_151 = V_4 -> V_16 . V_15 ;
return 0 ;
}
static int F_135 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_4 -> V_16 . V_15 = V_49 -> V_149 . V_151 ;
F_10 ( V_4 ) ;
return 0 ;
}
static int F_136 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_149 . V_151 = V_4 -> V_16 . V_17 ;
return 0 ;
}
static int F_137 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_4 -> V_16 . V_17 = V_49 -> V_149 . V_151 ;
F_10 ( V_4 ) ;
return 0 ;
}
static int F_138 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_149 . V_152 = V_4 -> V_106 ;
return 0 ;
}
static int F_139 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_4 -> V_106 = V_49 -> V_149 . V_152 ;
F_87 ( V_14 , V_4 ) ;
return 0 ;
}
static int F_140 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_149 . V_153 = V_4 -> V_101 ;
return 0 ;
}
static int F_141 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
if ( V_4 -> V_101 == V_49 -> V_149 . V_153 )
return 0 ;
if ( V_49 -> V_149 . V_153 >= V_14 -> V_3 -> V_154 )
return - V_62 ;
V_4 -> V_101 = V_49 -> V_149 . V_153 ;
F_87 ( V_14 , V_4 ) ;
return 0 ;
}
static void F_142 ( struct V_2 * V_3 ,
struct V_155 * V_156 ,
void * V_157 )
{
F_143 ( & V_156 -> V_158 , & V_159 ) ;
}
static void F_144 ( struct V_2 * V_3 )
{
F_143 ( & V_3 -> V_160 , & V_161 ) ;
F_145 ( V_3 , F_142 , NULL ) ;
V_3 -> V_162 = & V_163 ;
}
static int F_146 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_147 ( V_3 ) ;
int V_28 ;
int V_29 ;
V_14 -> V_3 = V_3 ;
F_148 ( & V_14 -> V_123 ) ;
F_55 ( V_14 ) ;
V_14 -> V_87 = F_149 ( struct V_86 ) ;
if ( ! V_14 -> V_87 )
return - V_31 ;
for ( V_28 = 0 ; V_28 < V_164 ; V_28 ++ )
F_150 ( & V_14 -> V_165 [ V_28 ] ) ;
F_73 ( & V_14 -> V_79 ) ;
V_29 = F_72 ( V_14 ) ;
if ( V_29 )
goto V_166;
F_57 ( V_14 ) ;
F_73 ( & V_14 -> V_46 ) ;
F_73 ( & V_14 -> V_36 ) ;
V_29 = F_31 ( V_14 , V_167 , F_151 ( V_167 ) ) ;
if ( V_29 )
goto V_168;
F_152 ( V_3 ) ;
F_144 ( V_3 ) ;
return 0 ;
V_168:
F_74 ( V_14 ) ;
V_166:
F_153 ( V_14 -> V_87 ) ;
return V_29 ;
}
static void F_154 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_147 ( V_3 ) ;
struct V_1 * V_4 ;
struct V_1 * V_26 ;
F_100 ( & V_14 -> V_123 ) ;
F_17 (port, tmp, &team->port_list, list)
F_126 ( V_14 , V_4 -> V_3 ) ;
F_58 ( V_14 , NULL ) ;
F_30 ( V_14 , V_167 , F_151 ( V_167 ) ) ;
F_74 ( V_14 ) ;
F_101 ( & V_14 -> V_123 ) ;
}
static void F_155 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_147 ( V_3 ) ;
F_153 ( V_14 -> V_87 ) ;
F_156 ( V_3 ) ;
}
static int F_157 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_158 ( struct V_2 * V_3 )
{
return 0 ;
}
static T_6 F_159 ( struct V_67 * V_68 , struct V_2 * V_3 )
{
struct V_14 * V_14 = F_147 ( V_3 ) ;
bool V_169 ;
unsigned int V_91 = V_68 -> V_91 ;
V_169 = F_76 ( V_14 , V_68 ) ;
if ( ! V_169 )
V_169 = V_14 -> V_73 . V_74 ( V_14 , V_68 ) ;
if ( V_169 ) {
struct V_86 * V_87 ;
V_87 = F_68 ( V_14 -> V_87 ) ;
F_69 ( & V_87 -> V_88 ) ;
V_87 -> V_170 ++ ;
V_87 -> V_171 += V_91 ;
F_70 ( & V_87 -> V_88 ) ;
} else {
F_71 ( V_14 -> V_87 -> V_172 ) ;
}
return V_173 ;
}
static T_3 F_160 ( struct V_2 * V_3 , struct V_67 * V_68 )
{
T_3 V_156 = F_161 ( V_68 ) ? F_162 ( V_68 ) : 0 ;
F_163 ( V_68 ) -> V_174 = V_68 -> V_104 ;
if ( F_164 ( V_156 >= V_3 -> V_154 ) ) {
do {
V_156 -= V_3 -> V_154 ;
} while ( V_156 >= V_3 -> V_154 );
}
return V_156 ;
}
static void F_165 ( struct V_2 * V_3 , int V_175 )
{
struct V_14 * V_14 = F_147 ( V_3 ) ;
struct V_1 * V_4 ;
int V_176 ;
F_166 () ;
F_77 (port, &team->port_list, list) {
if ( V_175 & V_177 ) {
V_176 = V_3 -> V_118 & V_177 ? 1 : - 1 ;
F_167 ( V_4 -> V_3 , V_176 ) ;
}
if ( V_175 & V_178 ) {
V_176 = V_3 -> V_118 & V_178 ? 1 : - 1 ;
F_168 ( V_4 -> V_3 , V_176 ) ;
}
}
F_169 () ;
}
static void F_170 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_147 ( V_3 ) ;
struct V_1 * V_4 ;
F_166 () ;
F_77 (port, &team->port_list, list) {
F_171 ( V_4 -> V_3 , V_3 ) ;
F_172 ( V_4 -> V_3 , V_3 ) ;
}
F_169 () ;
}
static int F_173 ( struct V_2 * V_3 , void * V_179 )
{
struct V_8 * V_9 = V_179 ;
struct V_14 * V_14 = F_147 ( V_3 ) ;
struct V_1 * V_4 ;
if ( V_3 -> type == V_180 && ! F_174 ( V_9 -> V_10 ) )
return - V_181 ;
memcpy ( V_3 -> V_7 , V_9 -> V_10 , V_3 -> V_11 ) ;
F_166 () ;
F_77 (port, &team->port_list, list)
if ( V_14 -> V_73 . V_182 )
V_14 -> V_73 . V_182 ( V_14 , V_4 ) ;
F_169 () ;
return 0 ;
}
static int F_175 ( struct V_2 * V_3 , int V_183 )
{
struct V_14 * V_14 = F_147 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 ;
F_100 ( & V_14 -> V_123 ) ;
F_12 (port, &team->port_list, list) {
V_29 = F_115 ( V_4 -> V_3 , V_183 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_26 ,
V_4 -> V_3 -> V_22 ) ;
goto V_184;
}
}
F_101 ( & V_14 -> V_123 ) ;
V_3 -> V_140 = V_183 ;
return 0 ;
V_184:
F_176 (port, &team->port_list, list)
F_115 ( V_4 -> V_3 , V_3 -> V_140 ) ;
F_101 ( & V_14 -> V_123 ) ;
return V_29 ;
}
static struct V_185 *
F_177 ( struct V_2 * V_3 , struct V_185 * V_186 )
{
struct V_14 * V_14 = F_147 ( V_3 ) ;
struct V_86 * V_179 ;
T_7 V_89 , V_90 , V_94 , V_170 , V_171 ;
T_4 V_95 = 0 , V_172 = 0 ;
unsigned int V_187 ;
int V_28 ;
F_178 (i) {
V_179 = F_179 ( V_14 -> V_87 , V_28 ) ;
do {
V_187 = F_180 ( & V_179 -> V_88 ) ;
V_89 = V_179 -> V_89 ;
V_90 = V_179 -> V_90 ;
V_94 = V_179 -> V_94 ;
V_170 = V_179 -> V_170 ;
V_171 = V_179 -> V_171 ;
} while ( F_181 ( & V_179 -> V_88 , V_187 ) );
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
static int F_182 ( struct V_2 * V_3 , T_8 V_189 )
{
struct V_14 * V_14 = F_147 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 ;
F_100 ( & V_14 -> V_123 ) ;
F_12 (port, &team->port_list, list) {
V_29 = F_183 ( V_4 -> V_3 , V_189 ) ;
if ( V_29 )
goto V_184;
}
F_101 ( & V_14 -> V_123 ) ;
return 0 ;
V_184:
F_176 (port, &team->port_list, list)
F_184 ( V_4 -> V_3 , V_189 ) ;
F_101 ( & V_14 -> V_123 ) ;
return V_29 ;
}
static int F_185 ( struct V_2 * V_3 , T_8 V_189 )
{
struct V_14 * V_14 = F_147 ( V_3 ) ;
struct V_1 * V_4 ;
F_166 () ;
F_77 (port, &team->port_list, list)
F_184 ( V_4 -> V_3 , V_189 ) ;
F_169 () ;
return 0 ;
}
static void F_186 ( struct V_2 * V_3 )
{
}
static void F_187 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
F_12 (port, &team->port_list, list)
F_108 ( V_4 ) ;
}
static void F_188 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_147 ( V_3 ) ;
F_100 ( & V_14 -> V_123 ) ;
F_187 ( V_14 ) ;
F_101 ( & V_14 -> V_123 ) ;
}
static int F_189 ( struct V_2 * V_3 ,
struct V_131 * V_190 , T_5 V_128 )
{
struct V_14 * V_14 = F_147 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 = 0 ;
F_100 ( & V_14 -> V_123 ) ;
F_12 (port, &team->port_list, list) {
V_29 = F_106 ( V_14 , V_4 , V_128 ) ;
if ( V_29 ) {
F_187 ( V_14 ) ;
break;
}
}
F_101 ( & V_14 -> V_123 ) ;
return V_29 ;
}
static int F_190 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_147 ( V_3 ) ;
int V_29 ;
F_100 ( & V_14 -> V_123 ) ;
V_29 = F_112 ( V_14 , V_6 ) ;
F_101 ( & V_14 -> V_123 ) ;
return V_29 ;
}
static int F_191 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_147 ( V_3 ) ;
int V_29 ;
F_100 ( & V_14 -> V_123 ) ;
V_29 = F_126 ( V_14 , V_6 ) ;
F_101 ( & V_14 -> V_123 ) ;
return V_29 ;
}
static T_9 F_192 ( struct V_2 * V_3 ,
T_9 V_135 )
{
struct V_1 * V_4 ;
struct V_14 * V_14 = F_147 ( V_3 ) ;
T_9 V_191 ;
V_191 = V_135 ;
V_135 &= ~ V_192 ;
V_135 |= V_193 ;
F_166 () ;
F_77 (port, &team->port_list, list) {
V_135 = F_97 ( V_135 ,
V_4 -> V_3 -> V_135 ,
V_191 ) ;
}
F_169 () ;
return V_135 ;
}
static int F_193 ( struct V_2 * V_3 , bool V_194 )
{
struct V_14 * V_14 = F_147 ( V_3 ) ;
V_14 -> V_71 = true ;
if ( V_194 )
F_194 ( V_3 ) ;
else
F_152 ( V_3 ) ;
return 0 ;
}
static void F_195 ( struct V_2 * V_3 ,
struct V_195 * V_196 )
{
F_196 ( V_196 -> V_197 , V_198 , sizeof( V_196 -> V_197 ) ) ;
F_196 ( V_196 -> V_199 , V_200 , sizeof( V_196 -> V_199 ) ) ;
}
static void F_197 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
V_3 -> V_201 = V_6 -> V_201 ;
V_3 -> type = V_6 -> type ;
V_3 -> V_122 = V_6 -> V_122 ;
V_3 -> V_11 = V_6 -> V_11 ;
V_3 -> V_140 = V_6 -> V_140 ;
memcpy ( V_3 -> V_202 , V_6 -> V_202 , V_6 -> V_11 ) ;
memcpy ( V_3 -> V_7 , V_6 -> V_7 , V_6 -> V_11 ) ;
}
static int F_114 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
struct V_14 * V_14 = F_147 ( V_3 ) ;
char * V_133 = V_6 -> V_22 ;
int V_29 ;
if ( V_3 -> type == V_6 -> type )
return 0 ;
if ( ! F_62 ( & V_14 -> V_79 ) ) {
F_63 ( V_3 , L_27 , V_133 ) ;
return - V_80 ;
}
V_29 = F_198 ( V_203 , V_3 ) ;
V_29 = F_199 ( V_29 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_28 ) ;
return V_29 ;
}
F_200 ( V_3 ) ;
F_201 ( V_3 ) ;
F_197 ( V_3 , V_6 ) ;
F_198 ( V_204 , V_3 ) ;
return 0 ;
}
static void F_202 ( struct V_2 * V_3 )
{
F_203 ( V_3 ) ;
V_3 -> V_205 = & V_206 ;
V_3 -> V_207 = & V_208 ;
V_3 -> V_209 = F_155 ;
V_3 -> V_210 = 0 ;
V_3 -> V_118 |= V_211 ;
V_3 -> V_121 &= ~ ( V_120 | V_212 ) ;
V_3 -> V_121 |= V_213 | V_214 ;
V_3 -> V_135 |= V_215 ;
V_3 -> V_135 |= V_216 ;
V_3 -> V_217 = V_115 |
V_218 |
V_219 |
V_220 ;
V_3 -> V_217 &= ~ ( V_221 & ~ V_222 ) ;
V_3 -> V_135 |= V_3 -> V_217 ;
}
static int F_204 ( struct V_223 * V_224 , struct V_2 * V_3 ,
struct V_225 * V_226 [] , struct V_225 * V_149 [] )
{
int V_29 ;
if ( V_226 [ V_227 ] == NULL )
F_205 ( V_3 ) ;
V_29 = F_206 ( V_3 ) ;
if ( V_29 )
return V_29 ;
return 0 ;
}
static int F_207 ( struct V_225 * V_226 [] , struct V_225 * V_149 [] )
{
if ( V_226 [ V_227 ] ) {
if ( F_208 ( V_226 [ V_227 ] ) != V_228 )
return - V_62 ;
if ( ! F_174 ( F_209 ( V_226 [ V_227 ] ) ) )
return - V_181 ;
}
return 0 ;
}
static unsigned int F_210 ( void )
{
return V_229 ;
}
static unsigned int F_211 ( void )
{
return V_230 ;
}
static int F_212 ( struct V_67 * V_68 , struct V_231 * V_32 )
{
struct V_67 * V_232 ;
void * V_233 ;
int V_29 ;
V_232 = F_213 ( V_234 , V_30 ) ;
if ( ! V_232 )
return - V_31 ;
V_233 = F_214 ( V_232 , V_32 -> V_235 , V_32 -> V_236 ,
& V_237 , 0 , V_238 ) ;
if ( ! V_233 ) {
V_29 = - V_239 ;
goto V_240;
}
F_215 ( V_232 , V_233 ) ;
return F_216 ( F_217 ( V_32 ) , V_232 , V_32 -> V_235 ) ;
V_240:
F_218 ( V_232 ) ;
return V_29 ;
}
static struct V_14 * F_219 ( struct V_231 * V_32 )
{
struct V_223 * V_223 = F_217 ( V_32 ) ;
int V_241 ;
struct V_2 * V_3 ;
struct V_14 * V_14 ;
if ( ! V_32 -> V_242 [ V_243 ] )
return NULL ;
V_241 = F_220 ( V_32 -> V_242 [ V_243 ] ) ;
V_3 = F_221 ( V_223 , V_241 ) ;
if ( ! V_3 || V_3 -> V_205 != & V_206 ) {
if ( V_3 )
F_104 ( V_3 ) ;
return NULL ;
}
V_14 = F_147 ( V_3 ) ;
F_100 ( & V_14 -> V_123 ) ;
return V_14 ;
}
static void F_222 ( struct V_14 * V_14 )
{
F_101 ( & V_14 -> V_123 ) ;
F_104 ( V_14 -> V_3 ) ;
}
static int F_223 ( struct V_67 * V_68 , struct V_14 * V_14 , T_4 V_244 )
{
return F_216 ( F_224 ( V_14 -> V_3 ) , V_68 , V_244 ) ;
}
static int F_225 ( struct V_67 * V_68 , struct V_14 * V_14 ,
struct V_23 * V_24 )
{
struct V_225 * V_245 ;
struct V_19 * V_21 = V_24 -> V_21 ;
struct V_53 * V_54 = & V_24 -> V_32 ;
struct V_48 V_49 ;
int V_29 ;
V_49 . V_32 = V_54 ;
V_29 = F_34 ( V_14 , V_24 , & V_49 ) ;
if ( V_29 )
return V_29 ;
V_245 = F_226 ( V_68 , V_246 ) ;
if ( ! V_245 )
return - V_239 ;
if ( F_227 ( V_68 , V_247 , V_21 -> V_22 ) )
goto V_248;
if ( V_54 -> V_4 &&
F_228 ( V_68 , V_249 ,
V_54 -> V_4 -> V_3 -> V_241 ) )
goto V_248;
if ( V_24 -> V_21 -> V_27 &&
F_228 ( V_68 , V_250 ,
V_54 -> V_33 ) )
goto V_248;
switch ( V_21 -> type ) {
case V_251 :
if ( F_229 ( V_68 , V_252 , V_253 ) )
goto V_248;
if ( F_228 ( V_68 , V_254 , V_49 . V_149 . V_153 ) )
goto V_248;
break;
case V_255 :
if ( F_229 ( V_68 , V_252 , V_256 ) )
goto V_248;
if ( F_227 ( V_68 , V_254 ,
V_49 . V_149 . V_150 ) )
goto V_248;
break;
case V_257 :
if ( F_229 ( V_68 , V_252 , V_258 ) )
goto V_248;
if ( F_230 ( V_68 , V_254 , V_49 . V_149 . V_259 . V_91 ,
V_49 . V_149 . V_259 . V_260 ) )
goto V_248;
break;
case V_261 :
if ( F_229 ( V_68 , V_252 , V_262 ) )
goto V_248;
if ( V_49 . V_149 . V_151 &&
F_231 ( V_68 , V_254 ) )
goto V_248;
break;
case V_263 :
if ( F_229 ( V_68 , V_252 , V_264 ) )
goto V_248;
if ( F_232 ( V_68 , V_254 , V_49 . V_149 . V_152 ) )
goto V_248;
break;
default:
F_233 () ;
}
if ( V_24 -> V_35 && F_231 ( V_68 , V_265 ) )
goto V_248;
if ( V_24 -> V_34 ) {
if ( F_231 ( V_68 , V_266 ) )
goto V_248;
V_24 -> V_34 = false ;
}
F_234 ( V_68 , V_245 ) ;
return 0 ;
V_248:
F_235 ( V_68 , V_245 ) ;
return - V_239 ;
}
static int F_236 ( struct V_67 * * V_81 ,
struct V_14 * V_14 , T_4 V_244 ,
T_10 * V_267 )
{
int V_29 ;
if ( * V_81 ) {
V_29 = V_267 ( * V_81 , V_14 , V_244 ) ;
if ( V_29 )
return V_29 ;
}
* V_81 = F_237 ( V_268 , V_30 ) ;
if ( ! * V_81 )
return - V_31 ;
return 0 ;
}
static int F_238 ( struct V_14 * V_14 , T_4 V_244 , T_4 V_269 ,
int V_118 , T_10 * V_267 ,
struct V_96 * V_270 )
{
struct V_225 * V_46 ;
struct V_271 * V_272 ;
void * V_233 ;
struct V_23 * V_24 ;
int V_29 ;
struct V_67 * V_68 = NULL ;
bool V_273 ;
int V_28 ;
V_24 = F_239 ( V_270 ,
struct V_23 , V_274 ) ;
V_275:
V_29 = F_236 ( & V_68 , V_14 , V_244 , V_267 ) ;
if ( V_29 )
return V_29 ;
V_233 = F_214 ( V_68 , V_244 , V_269 , & V_237 , V_118 | V_276 ,
V_277 ) ;
if ( ! V_233 )
return - V_239 ;
if ( F_228 ( V_68 , V_243 , V_14 -> V_3 -> V_241 ) )
goto V_278;
V_46 = F_226 ( V_68 , V_279 ) ;
if ( ! V_46 )
goto V_278;
V_28 = 0 ;
V_273 = false ;
F_240 (opt_inst, sel_opt_inst_list, tmp_list) {
V_29 = F_225 ( V_68 , V_14 , V_24 ) ;
if ( V_29 ) {
if ( V_29 == - V_239 ) {
if ( ! V_28 )
goto V_280;
V_273 = true ;
break;
}
goto V_280;
}
V_28 ++ ;
}
F_234 ( V_68 , V_46 ) ;
F_215 ( V_68 , V_233 ) ;
if ( V_273 )
goto V_275;
V_281:
V_272 = F_241 ( V_68 , V_244 , V_269 , V_282 , 0 , V_118 | V_276 ) ;
if ( ! V_272 ) {
V_29 = F_236 ( & V_68 , V_14 , V_244 , V_267 ) ;
if ( V_29 )
goto V_280;
goto V_281;
}
return V_267 ( V_68 , V_14 , V_244 ) ;
V_278:
V_29 = - V_239 ;
V_280:
F_242 ( V_68 , V_233 ) ;
F_218 ( V_68 ) ;
return V_29 ;
}
static int F_243 ( struct V_67 * V_68 , struct V_231 * V_32 )
{
struct V_14 * V_14 ;
struct V_23 * V_24 ;
int V_29 ;
F_244 ( V_270 ) ;
V_14 = F_219 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
F_12 (opt_inst, &team->option_inst_list, list)
F_20 ( & V_24 -> V_274 , & V_270 ) ;
V_29 = F_238 ( V_14 , V_32 -> V_235 , V_32 -> V_236 ,
V_283 , F_223 ,
& V_270 ) ;
F_222 ( V_14 ) ;
return V_29 ;
}
static int F_245 ( struct V_67 * V_68 , struct V_231 * V_32 )
{
struct V_14 * V_14 ;
int V_29 = 0 ;
int V_28 ;
struct V_225 * V_284 ;
F_244 ( V_285 ) ;
V_14 = F_219 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
V_29 = - V_62 ;
if ( ! V_32 -> V_242 [ V_279 ] ) {
V_29 = - V_62 ;
goto V_286;
}
F_246 (nl_option, info->attrs[TEAM_ATTR_LIST_OPTION], i) {
struct V_225 * V_287 [ V_288 + 1 ] ;
struct V_225 * V_289 ;
struct V_225 * V_290 ;
enum V_291 V_292 ;
int V_293 = 0 ;
T_4 V_294 = 0 ;
bool V_295 = false ;
struct V_23 * V_24 ;
char * V_20 ;
bool V_296 = false ;
if ( F_247 ( V_284 ) != V_246 ) {
V_29 = - V_62 ;
goto V_286;
}
V_29 = F_248 ( V_287 , V_288 ,
V_284 , V_297 ) ;
if ( V_29 )
goto V_286;
if ( ! V_287 [ V_247 ] ||
! V_287 [ V_252 ] ) {
V_29 = - V_62 ;
goto V_286;
}
switch ( F_249 ( V_287 [ V_252 ] ) ) {
case V_253 :
V_292 = V_251 ;
break;
case V_256 :
V_292 = V_255 ;
break;
case V_258 :
V_292 = V_257 ;
break;
case V_262 :
V_292 = V_261 ;
break;
case V_264 :
V_292 = V_263 ;
break;
default:
goto V_286;
}
V_290 = V_287 [ V_254 ] ;
if ( V_292 != V_261 && ! V_290 ) {
V_29 = - V_62 ;
goto V_286;
}
V_20 = F_209 ( V_287 [ V_247 ] ) ;
V_289 = V_287 [ V_249 ] ;
if ( V_289 )
V_293 = F_220 ( V_289 ) ;
V_289 = V_287 [ V_250 ] ;
if ( V_289 ) {
V_295 = true ;
V_294 = F_220 ( V_289 ) ;
}
F_12 (opt_inst, &team->option_inst_list, list) {
struct V_19 * V_21 = V_24 -> V_21 ;
struct V_48 V_49 ;
struct V_53 * V_54 ;
int V_298 ;
V_54 = & V_24 -> V_32 ;
V_298 = V_54 -> V_4 ?
V_54 -> V_4 -> V_3 -> V_241 : 0 ;
if ( V_21 -> type != V_292 ||
strcmp ( V_21 -> V_22 , V_20 ) ||
V_298 != V_293 ||
( V_21 -> V_27 && ! V_295 ) ||
V_54 -> V_33 != V_294 )
continue;
V_296 = true ;
V_49 . V_32 = V_54 ;
switch ( V_292 ) {
case V_251 :
V_49 . V_149 . V_153 = F_220 ( V_290 ) ;
break;
case V_255 :
if ( F_208 ( V_290 ) > V_299 ) {
V_29 = - V_62 ;
goto V_286;
}
V_49 . V_149 . V_150 = F_209 ( V_290 ) ;
break;
case V_257 :
V_49 . V_149 . V_259 . V_91 = F_208 ( V_290 ) ;
V_49 . V_149 . V_259 . V_260 = F_209 ( V_290 ) ;
break;
case V_261 :
V_49 . V_149 . V_151 = V_290 ? true : false ;
break;
case V_263 :
V_49 . V_149 . V_152 = F_250 ( V_290 ) ;
break;
default:
F_233 () ;
}
V_29 = F_35 ( V_14 , V_24 , & V_49 ) ;
if ( V_29 )
goto V_286;
V_24 -> V_34 = true ;
F_251 ( & V_24 -> V_274 , & V_285 ) ;
}
if ( ! V_296 ) {
V_29 = - V_148 ;
goto V_286;
}
}
V_29 = F_252 ( V_14 , & V_285 ) ;
V_286:
F_222 ( V_14 ) ;
return V_29 ;
}
static int F_253 ( struct V_67 * V_68 ,
struct V_1 * V_4 )
{
struct V_225 * V_300 ;
V_300 = F_226 ( V_68 , V_301 ) ;
if ( ! V_300 )
goto V_248;
if ( F_228 ( V_68 , V_302 , V_4 -> V_3 -> V_241 ) )
goto V_248;
if ( V_4 -> V_34 ) {
if ( F_231 ( V_68 , V_303 ) )
goto V_248;
V_4 -> V_34 = false ;
}
if ( ( V_4 -> V_35 &&
F_231 ( V_68 , V_304 ) ) ||
( V_4 -> V_18 . V_15 &&
F_231 ( V_68 , V_305 ) ) ||
F_228 ( V_68 , V_306 , V_4 -> V_18 . V_307 ) ||
F_229 ( V_68 , V_308 , V_4 -> V_18 . V_309 ) )
goto V_248;
F_234 ( V_68 , V_300 ) ;
return 0 ;
V_248:
F_235 ( V_68 , V_300 ) ;
return - V_239 ;
}
static int F_254 ( struct V_14 * V_14 , T_4 V_244 , T_4 V_269 ,
int V_118 , T_10 * V_267 ,
struct V_1 * V_310 )
{
struct V_225 * V_79 ;
struct V_271 * V_272 ;
void * V_233 ;
struct V_1 * V_4 ;
int V_29 ;
struct V_67 * V_68 = NULL ;
bool V_273 ;
int V_28 ;
V_4 = F_239 ( & V_14 -> V_79 , struct V_1 , V_25 ) ;
V_275:
V_29 = F_236 ( & V_68 , V_14 , V_244 , V_267 ) ;
if ( V_29 )
return V_29 ;
V_233 = F_214 ( V_68 , V_244 , V_269 , & V_237 , V_118 | V_276 ,
V_311 ) ;
if ( ! V_233 )
return - V_239 ;
if ( F_228 ( V_68 , V_243 , V_14 -> V_3 -> V_241 ) )
goto V_278;
V_79 = F_226 ( V_68 , V_312 ) ;
if ( ! V_79 )
goto V_278;
V_28 = 0 ;
V_273 = false ;
if ( V_310 ) {
V_29 = F_253 ( V_68 , V_310 ) ;
if ( V_29 )
goto V_280;
} else {
F_12 (port, &team->port_list, list) {
V_29 = F_253 ( V_68 , V_4 ) ;
if ( V_29 ) {
if ( V_29 == - V_239 ) {
if ( ! V_28 )
goto V_280;
V_273 = true ;
break;
}
goto V_280;
}
V_28 ++ ;
}
}
F_234 ( V_68 , V_79 ) ;
F_215 ( V_68 , V_233 ) ;
if ( V_273 )
goto V_275;
V_281:
V_272 = F_241 ( V_68 , V_244 , V_269 , V_282 , 0 , V_118 | V_276 ) ;
if ( ! V_272 ) {
V_29 = F_236 ( & V_68 , V_14 , V_244 , V_267 ) ;
if ( V_29 )
goto V_280;
goto V_281;
}
return V_267 ( V_68 , V_14 , V_244 ) ;
V_278:
V_29 = - V_239 ;
V_280:
F_242 ( V_68 , V_233 ) ;
F_218 ( V_68 ) ;
return V_29 ;
}
static int F_255 ( struct V_67 * V_68 ,
struct V_231 * V_32 )
{
struct V_14 * V_14 ;
int V_29 ;
V_14 = F_219 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
V_29 = F_254 ( V_14 , V_32 -> V_235 , V_32 -> V_236 ,
V_283 , F_223 , NULL ) ;
F_222 ( V_14 ) ;
return V_29 ;
}
static int F_256 ( struct V_67 * V_68 ,
struct V_14 * V_14 , T_4 V_244 )
{
return F_257 ( F_224 ( V_14 -> V_3 ) , V_68 , 0 ,
V_313 . V_314 , V_30 ) ;
}
static int F_252 ( struct V_14 * V_14 ,
struct V_96 * V_270 )
{
return F_238 ( V_14 , 0 , 0 , 0 , F_256 ,
V_270 ) ;
}
static int F_258 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
return F_254 ( V_14 , 0 , 0 , 0 , F_256 ,
V_4 ) ;
}
static int F_259 ( void )
{
int V_29 ;
V_29 = F_260 ( & V_237 , V_315 ,
F_151 ( V_315 ) ) ;
if ( V_29 )
return V_29 ;
V_29 = F_261 ( & V_237 , & V_313 ) ;
if ( V_29 )
goto V_316;
return 0 ;
V_316:
F_262 ( & V_237 ) ;
return V_29 ;
}
static void F_263 ( void )
{
F_262 ( & V_237 ) ;
}
static void F_32 ( struct V_14 * V_14 )
{
int V_29 ;
struct V_23 * V_24 ;
F_244 ( V_270 ) ;
F_12 (opt_inst, &team->option_inst_list, list) {
if ( V_24 -> V_34 )
F_20 ( & V_24 -> V_274 , & V_270 ) ;
}
V_29 = F_252 ( V_14 , & V_270 ) ;
if ( V_29 && V_29 != - V_317 )
F_264 ( V_14 -> V_3 , L_29 ,
V_29 ) ;
}
static void F_265 ( struct V_1 * V_4 , bool V_15 )
{
int V_29 ;
V_4 -> V_34 = true ;
V_4 -> V_18 . V_15 = V_15 ;
F_10 ( V_4 ) ;
if ( V_15 ) {
struct V_318 V_319 ;
V_29 = F_266 ( V_4 -> V_3 , & V_319 ) ;
if ( ! V_29 ) {
V_4 -> V_18 . V_307 = F_267 ( & V_319 ) ;
V_4 -> V_18 . V_309 = V_319 . V_309 ;
goto V_320;
}
}
V_4 -> V_18 . V_307 = 0 ;
V_4 -> V_18 . V_309 = 0 ;
V_320:
V_29 = F_258 ( V_4 -> V_14 , V_4 ) ;
if ( V_29 && V_29 != - V_317 )
F_264 ( V_4 -> V_14 -> V_3 , L_30 ,
V_4 -> V_3 -> V_22 , V_29 ) ;
}
static void F_268 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
bool V_321 ;
if ( V_14 -> V_71 )
return;
V_321 = false ;
F_12 (port, &team->port_list, list) {
if ( V_4 -> V_15 ) {
V_321 = true ;
break;
}
}
if ( V_321 )
F_194 ( V_14 -> V_3 ) ;
else
F_152 ( V_14 -> V_3 ) ;
}
static void F_269 ( struct V_1 * V_4 , bool V_15 )
{
if ( V_4 -> V_18 . V_15 != V_15 )
F_265 ( V_4 , V_15 ) ;
F_268 ( V_4 -> V_14 ) ;
}
static void F_120 ( struct V_1 * V_4 , bool V_15 )
{
F_265 ( V_4 , V_15 ) ;
F_268 ( V_4 -> V_14 ) ;
}
static void F_129 ( struct V_1 * V_4 )
{
V_4 -> V_35 = true ;
F_265 ( V_4 , false ) ;
F_268 ( V_4 -> V_14 ) ;
}
static void F_270 ( struct V_1 * V_4 , bool V_15 )
{
struct V_14 * V_14 = V_4 -> V_14 ;
F_100 ( & V_14 -> V_123 ) ;
F_269 ( V_4 , V_15 ) ;
F_101 ( & V_14 -> V_123 ) ;
}
static int F_271 ( struct V_322 * V_157 ,
unsigned long V_323 , void * V_260 )
{
struct V_2 * V_3 = (struct V_2 * ) V_260 ;
struct V_1 * V_4 ;
V_4 = F_4 ( V_3 ) ;
if ( ! V_4 )
return V_324 ;
switch ( V_323 ) {
case V_325 :
if ( F_121 ( V_3 ) )
F_270 ( V_4 , true ) ;
case V_326 :
F_270 ( V_4 , false ) ;
case V_327 :
if ( F_272 ( V_4 -> V_3 ) )
F_270 ( V_4 ,
! ! F_121 ( V_4 -> V_3 ) ) ;
break;
case V_328 :
F_191 ( V_4 -> V_14 -> V_3 , V_3 ) ;
break;
case V_329 :
F_99 ( V_4 -> V_14 ) ;
break;
case V_330 :
return V_331 ;
case V_203 :
return V_331 ;
}
return V_324 ;
}
static int T_11 F_273 ( void )
{
int V_29 ;
F_274 ( & V_332 ) ;
V_29 = F_275 ( & V_333 ) ;
if ( V_29 )
goto V_334;
V_29 = F_259 () ;
if ( V_29 )
goto V_335;
return 0 ;
V_335:
F_276 ( & V_333 ) ;
V_334:
F_277 ( & V_332 ) ;
return V_29 ;
}
static void T_12 F_278 ( void )
{
F_263 () ;
F_276 ( & V_333 ) ;
F_277 ( & V_332 ) ;
}
