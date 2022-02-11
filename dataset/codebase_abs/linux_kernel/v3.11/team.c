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
static T_2 F_66 ( struct V_67 * * V_81 )
{
struct V_67 * V_68 = * V_81 ;
struct V_1 * V_4 ;
struct V_14 * V_14 ;
T_2 V_82 ;
V_68 = F_67 ( V_68 , V_83 ) ;
if ( ! V_68 )
return V_84 ;
* V_81 = V_68 ;
V_4 = F_1 ( V_68 -> V_3 ) ;
V_14 = V_4 -> V_14 ;
if ( ! F_68 ( V_4 ) ) {
V_82 = V_85 ;
} else {
V_82 = V_14 -> V_73 . V_75 ( V_14 , V_4 , V_68 ) ;
}
if ( V_82 == V_69 ) {
struct V_86 * V_87 ;
V_87 = F_69 ( V_14 -> V_87 ) ;
F_70 ( & V_87 -> V_88 ) ;
V_87 -> V_89 ++ ;
V_87 -> V_90 += V_68 -> V_91 ;
if ( V_68 -> V_92 == V_93 )
V_87 -> V_94 ++ ;
F_71 ( & V_87 -> V_88 ) ;
V_68 -> V_3 = V_14 -> V_3 ;
} else {
F_72 ( V_14 -> V_87 -> V_95 ) ;
}
return V_82 ;
}
static int F_73 ( struct V_14 * V_14 )
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
F_74 ( V_97 ++ ) ;
return 0 ;
}
static void F_75 ( struct V_14 * V_14 )
{
F_17 ( V_14 -> V_100 ) ;
}
static struct V_96 * F_76 ( struct V_14 * V_14 , T_3 V_101 )
{
return & V_14 -> V_100 [ V_101 - 1 ] ;
}
static bool F_77 ( struct V_14 * V_14 , struct V_67 * V_68 )
{
struct V_96 * V_102 ;
struct V_1 * V_4 ;
if ( ! V_14 -> V_103 || ! V_68 -> V_104 )
return false ;
V_102 = F_76 ( V_14 , V_68 -> V_104 ) ;
F_78 (port, qom_list, qom_list) {
if ( ! F_79 ( V_14 , V_4 , V_68 ) )
return true ;
}
return false ;
}
static void F_80 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
if ( ! V_4 -> V_101 )
return;
F_81 ( & V_4 -> V_102 ) ;
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
if ( ! V_4 -> V_101 )
return;
V_102 = F_76 ( V_14 , V_4 -> V_101 ) ;
V_108 = V_102 ;
F_14 (cur, qom_list, qom_list) {
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
F_14 (port, &team->port_list, list) {
if ( V_4 -> V_101 ) {
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
if ( ! V_4 -> V_101 || F_68 ( V_4 ) )
return;
F_80 ( V_14 , V_4 ) ;
F_83 ( V_14 , V_4 ) ;
F_85 ( V_14 ) ;
}
static void F_88 ( struct V_14 * V_14 ,
struct V_1 * V_4 ,
T_3 V_110 )
{
if ( F_68 ( V_4 ) ) {
F_80 ( V_14 , V_4 ) ;
V_4 -> V_101 = V_110 ;
F_83 ( V_14 , V_4 ) ;
F_85 ( V_14 ) ;
} else {
V_4 -> V_101 = V_110 ;
}
}
static void F_89 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
F_83 ( V_14 , V_4 ) ;
F_85 ( V_14 ) ;
}
static void F_90 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
F_80 ( V_14 , V_4 ) ;
F_85 ( V_14 ) ;
}
static bool F_91 ( const struct V_14 * V_14 ,
const struct V_1 * V_4 )
{
struct V_1 * V_105 ;
F_14 (cur, &team->port_list, list)
if ( V_105 == V_4 )
return true ;
return false ;
}
static void F_92 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
if ( F_68 ( V_4 ) )
return;
V_4 -> V_107 = V_14 -> V_72 ++ ;
F_93 ( & V_4 -> V_111 ,
F_94 ( V_14 , V_4 -> V_107 ) ) ;
F_58 ( V_14 ) ;
F_89 ( V_14 , V_4 ) ;
if ( V_14 -> V_73 . V_112 )
V_14 -> V_73 . V_112 ( V_14 , V_4 ) ;
}
static void F_95 ( struct V_14 * V_14 , int V_113 )
{
int V_28 ;
struct V_1 * V_4 ;
for ( V_28 = V_113 + 1 ; V_28 < V_14 -> V_72 ; V_28 ++ ) {
V_4 = F_96 ( V_14 , V_28 ) ;
F_97 ( & V_4 -> V_111 ) ;
V_4 -> V_107 -- ;
F_93 ( & V_4 -> V_111 ,
F_94 ( V_14 , V_4 -> V_107 ) ) ;
}
}
static void F_98 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
if ( ! F_68 ( V_4 ) )
return;
if ( V_14 -> V_73 . V_114 )
V_14 -> V_73 . V_114 ( V_14 , V_4 ) ;
F_97 ( & V_4 -> V_111 ) ;
F_95 ( V_14 , V_4 -> V_107 ) ;
V_4 -> V_107 = - 1 ;
V_14 -> V_72 -- ;
F_90 ( V_14 , V_4 ) ;
F_58 ( V_14 ) ;
}
static void F_99 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
T_4 V_115 = V_116 ;
unsigned short V_117 = V_118 ;
unsigned int V_119 , V_120 = V_121 ;
F_14 (port, &team->port_list, list) {
V_115 = F_100 ( V_115 ,
V_4 -> V_3 -> V_115 ,
V_116 ) ;
V_120 &= V_4 -> V_3 -> V_122 ;
if ( V_4 -> V_3 -> V_123 > V_117 )
V_117 = V_4 -> V_3 -> V_123 ;
}
V_14 -> V_3 -> V_115 = V_115 ;
V_14 -> V_3 -> V_123 = V_117 ;
V_119 = V_14 -> V_3 -> V_122 & ~ V_121 ;
V_14 -> V_3 -> V_122 = V_119 | V_120 ;
F_101 ( V_14 -> V_3 ) ;
}
static void F_102 ( struct V_14 * V_14 )
{
F_103 ( & V_14 -> V_124 ) ;
F_99 ( V_14 ) ;
F_104 ( & V_14 -> V_124 ) ;
}
static int F_105 ( struct V_14 * V_14 , struct V_1 * V_4 )
{
int V_29 = 0 ;
F_106 ( V_14 -> V_3 ) ;
V_4 -> V_3 -> V_122 |= V_125 ;
if ( V_14 -> V_73 . V_126 ) {
V_29 = V_14 -> V_73 . V_126 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_64 ( V_14 -> V_3 , L_10 ,
V_4 -> V_3 -> V_22 ) ;
goto V_127;
}
}
return 0 ;
V_127:
V_4 -> V_3 -> V_122 &= ~ V_125 ;
F_107 ( V_14 -> V_3 ) ;
return V_29 ;
}
static void F_108 ( struct V_14 * V_14 , struct V_1 * V_4 )
{
if ( V_14 -> V_73 . V_128 )
V_14 -> V_73 . V_128 ( V_14 , V_4 ) ;
V_4 -> V_3 -> V_122 &= ~ V_125 ;
F_107 ( V_14 -> V_3 ) ;
}
static int F_109 ( struct V_14 * V_14 , struct V_1 * V_4 ,
T_5 V_129 )
{
struct V_130 * V_131 ;
int V_29 ;
V_131 = F_29 ( sizeof( * V_131 ) , V_129 ) ;
if ( ! V_131 )
return - V_31 ;
V_29 = F_110 ( V_131 , V_4 -> V_3 , V_129 ) ;
if ( V_29 ) {
F_17 ( V_131 ) ;
return V_29 ;
}
V_4 -> V_131 = V_131 ;
return V_29 ;
}
static void F_111 ( struct V_1 * V_4 )
{
struct V_130 * V_131 = V_4 -> V_131 ;
if ( ! V_131 )
return;
V_4 -> V_131 = NULL ;
F_112 () ;
F_113 ( V_131 ) ;
F_17 ( V_131 ) ;
}
static struct V_132 * F_114 ( struct V_14 * V_14 )
{
return V_14 -> V_3 -> V_133 ;
}
static int F_109 ( struct V_14 * V_14 , struct V_1 * V_4 ,
T_5 V_129 )
{
return 0 ;
}
static void F_111 ( struct V_1 * V_4 )
{
}
static struct V_132 * F_114 ( struct V_14 * V_14 )
{
return NULL ;
}
static int F_115 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_4 ;
char * V_134 = V_6 -> V_22 ;
int V_29 ;
if ( V_6 -> V_119 & V_135 ) {
F_64 ( V_3 , L_11 ,
V_134 ) ;
return - V_62 ;
}
if ( F_3 ( V_6 ) ) {
F_64 ( V_3 , L_12
L_13 , V_134 ) ;
return - V_80 ;
}
if ( V_6 -> V_136 & V_137 &&
F_116 ( V_3 ) ) {
F_64 ( V_3 , L_14 ,
V_134 ) ;
return - V_138 ;
}
V_29 = F_117 ( V_3 , V_6 ) ;
if ( V_29 )
return V_29 ;
if ( V_6 -> V_119 & V_139 ) {
F_64 ( V_3 , L_15 ,
V_134 ) ;
return - V_80 ;
}
V_4 = F_29 ( sizeof( struct V_1 ) + V_14 -> V_58 -> V_140 ,
V_30 ) ;
if ( ! V_4 )
return - V_31 ;
V_4 -> V_3 = V_6 ;
V_4 -> V_14 = V_14 ;
F_74 ( & V_4 -> V_102 ) ;
V_4 -> V_13 . V_141 = V_6 -> V_141 ;
V_29 = F_118 ( V_6 , V_3 -> V_141 ) ;
if ( V_29 ) {
F_86 ( V_3 , L_16 , V_29 ) ;
goto V_142;
}
memcpy ( V_4 -> V_13 . V_7 , V_6 -> V_7 , V_6 -> V_11 ) ;
V_29 = F_105 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_10 ,
V_134 ) ;
goto V_127;
}
V_29 = F_119 ( V_6 ) ;
if ( V_29 ) {
F_86 ( V_3 , L_17 ,
V_134 ) ;
goto V_143;
}
V_29 = F_120 ( V_6 , V_3 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_18 ,
V_134 ) ;
goto V_144;
}
if ( F_114 ( V_14 ) ) {
V_29 = F_109 ( V_14 , V_4 , V_30 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_19 ,
V_134 ) ;
goto V_145;
}
}
V_29 = F_121 ( V_6 , V_3 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_20 ,
V_134 ) ;
goto V_146;
}
V_29 = F_122 ( V_6 , F_66 ,
V_4 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_21 ,
V_134 ) ;
goto V_147;
}
V_29 = F_26 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_22 ,
V_134 ) ;
goto V_148;
}
V_4 -> V_107 = - 1 ;
F_84 ( & V_4 -> V_25 , & V_14 -> V_79 ) ;
F_92 ( V_14 , V_4 ) ;
F_99 ( V_14 ) ;
F_123 ( V_4 , ! ! F_124 ( V_6 ) ) ;
F_34 ( V_14 ) ;
F_65 ( V_3 , L_23 , V_134 ) ;
return 0 ;
V_148:
F_125 ( V_6 ) ;
V_147:
F_126 ( V_6 , V_3 ) ;
V_146:
F_111 ( V_4 ) ;
V_145:
F_127 ( V_6 , V_3 ) ;
V_144:
F_128 ( V_6 ) ;
V_143:
F_108 ( V_14 , V_4 ) ;
F_8 ( V_4 ) ;
V_127:
F_118 ( V_6 , V_4 -> V_13 . V_141 ) ;
V_142:
F_17 ( V_4 ) ;
return V_29 ;
}
static int F_129 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_4 ;
char * V_134 = V_6 -> V_22 ;
V_4 = F_4 ( V_6 ) ;
if ( ! V_4 || ! F_91 ( V_14 , V_4 ) ) {
F_64 ( V_3 , L_24 ,
V_134 ) ;
return - V_149 ;
}
F_98 ( V_14 , V_4 ) ;
F_81 ( & V_4 -> V_25 ) ;
F_125 ( V_6 ) ;
F_126 ( V_6 , V_3 ) ;
F_111 ( V_4 ) ;
F_127 ( V_6 , V_3 ) ;
F_130 ( V_6 , V_3 ) ;
F_131 ( V_6 , V_3 ) ;
F_128 ( V_6 ) ;
F_108 ( V_14 , V_4 ) ;
F_27 ( V_14 , V_4 ) ;
F_34 ( V_14 ) ;
F_25 ( V_14 , V_4 ) ;
F_132 ( V_4 ) ;
F_8 ( V_4 ) ;
F_118 ( V_6 , V_4 -> V_13 . V_141 ) ;
F_133 ( V_4 , V_150 ) ;
F_65 ( V_3 , L_25 , V_134 ) ;
F_99 ( V_14 ) ;
return 0 ;
}
static int F_134 ( struct V_14 * V_14 , struct V_48 * V_49 )
{
V_49 -> V_151 . V_152 = V_14 -> V_58 -> V_56 ;
return 0 ;
}
static int F_135 ( struct V_14 * V_14 , struct V_48 * V_49 )
{
return F_62 ( V_14 , V_49 -> V_151 . V_152 ) ;
}
static int F_136 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_151 . V_153 = F_68 ( V_4 ) ;
return 0 ;
}
static int F_137 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
if ( V_49 -> V_151 . V_153 )
F_92 ( V_14 , V_4 ) ;
else
F_98 ( V_14 , V_4 ) ;
return 0 ;
}
static int F_138 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_151 . V_153 = V_4 -> V_16 . V_15 ;
return 0 ;
}
static int F_139 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_4 -> V_16 . V_15 = V_49 -> V_151 . V_153 ;
F_12 ( V_4 ) ;
return 0 ;
}
static int F_140 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_151 . V_153 = V_4 -> V_16 . V_17 ;
return 0 ;
}
static int F_141 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_4 -> V_16 . V_17 = V_49 -> V_151 . V_153 ;
F_12 ( V_4 ) ;
return 0 ;
}
static int F_142 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_151 . V_154 = V_4 -> V_106 ;
return 0 ;
}
static int F_143 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
T_6 V_106 = V_49 -> V_151 . V_154 ;
if ( V_4 -> V_106 == V_106 )
return 0 ;
V_4 -> V_106 = V_106 ;
F_87 ( V_14 , V_4 ) ;
return 0 ;
}
static int F_144 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_151 . V_155 = V_4 -> V_101 ;
return 0 ;
}
static int F_145 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
T_3 V_110 = V_49 -> V_151 . V_155 ;
if ( V_4 -> V_101 == V_110 )
return 0 ;
if ( V_110 >= V_14 -> V_3 -> V_156 )
return - V_62 ;
F_88 ( V_14 , V_4 , V_110 ) ;
return 0 ;
}
static void F_146 ( struct V_2 * V_3 ,
struct V_157 * V_158 ,
void * V_159 )
{
F_147 ( & V_158 -> V_160 , & V_161 ) ;
}
static void F_148 ( struct V_2 * V_3 )
{
F_147 ( & V_3 -> V_162 , & V_163 ) ;
F_149 ( V_3 , F_146 , NULL ) ;
V_3 -> V_164 = & V_165 ;
}
static int F_150 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_151 ( V_3 ) ;
int V_28 ;
int V_29 ;
V_14 -> V_3 = V_3 ;
F_152 ( & V_14 -> V_124 ) ;
F_57 ( V_14 ) ;
V_14 -> V_87 = F_153 ( struct V_86 ) ;
if ( ! V_14 -> V_87 )
return - V_31 ;
for ( V_28 = 0 ; V_28 < V_166 ; V_28 ++ )
F_154 ( & V_14 -> V_167 [ V_28 ] ) ;
F_74 ( & V_14 -> V_79 ) ;
V_29 = F_73 ( V_14 ) ;
if ( V_29 )
goto V_168;
F_58 ( V_14 ) ;
F_74 ( & V_14 -> V_46 ) ;
F_74 ( & V_14 -> V_36 ) ;
V_29 = F_33 ( V_14 , V_169 , F_155 ( V_169 ) ) ;
if ( V_29 )
goto V_170;
F_156 ( V_3 ) ;
F_148 ( V_3 ) ;
return 0 ;
V_170:
F_75 ( V_14 ) ;
V_168:
F_157 ( V_14 -> V_87 ) ;
return V_29 ;
}
static void F_158 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_151 ( V_3 ) ;
struct V_1 * V_4 ;
struct V_1 * V_26 ;
F_103 ( & V_14 -> V_124 ) ;
F_19 (port, tmp, &team->port_list, list)
F_129 ( V_14 , V_4 -> V_3 ) ;
F_59 ( V_14 , NULL ) ;
F_32 ( V_14 , V_169 , F_155 ( V_169 ) ) ;
F_75 ( V_14 ) ;
F_104 ( & V_14 -> V_124 ) ;
}
static void F_159 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_151 ( V_3 ) ;
F_157 ( V_14 -> V_87 ) ;
F_160 ( V_3 ) ;
}
static int F_161 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_162 ( struct V_2 * V_3 )
{
return 0 ;
}
static T_7 F_163 ( struct V_67 * V_68 , struct V_2 * V_3 )
{
struct V_14 * V_14 = F_151 ( V_3 ) ;
bool V_171 ;
unsigned int V_91 = V_68 -> V_91 ;
V_171 = F_77 ( V_14 , V_68 ) ;
if ( ! V_171 )
V_171 = V_14 -> V_73 . V_74 ( V_14 , V_68 ) ;
if ( V_171 ) {
struct V_86 * V_87 ;
V_87 = F_69 ( V_14 -> V_87 ) ;
F_70 ( & V_87 -> V_88 ) ;
V_87 -> V_172 ++ ;
V_87 -> V_173 += V_91 ;
F_71 ( & V_87 -> V_88 ) ;
} else {
F_72 ( V_14 -> V_87 -> V_174 ) ;
}
return V_175 ;
}
static T_3 F_164 ( struct V_2 * V_3 , struct V_67 * V_68 )
{
T_3 V_158 = F_165 ( V_68 ) ? F_166 ( V_68 ) : 0 ;
F_167 ( V_68 ) -> V_176 = V_68 -> V_104 ;
if ( F_168 ( V_158 >= V_3 -> V_156 ) ) {
do {
V_158 -= V_3 -> V_156 ;
} while ( V_158 >= V_3 -> V_156 );
}
return V_158 ;
}
static void F_169 ( struct V_2 * V_3 , int V_177 )
{
struct V_14 * V_14 = F_151 ( V_3 ) ;
struct V_1 * V_4 ;
int V_178 ;
F_170 () ;
F_78 (port, &team->port_list, list) {
if ( V_177 & V_179 ) {
V_178 = V_3 -> V_119 & V_179 ? 1 : - 1 ;
F_171 ( V_4 -> V_3 , V_178 ) ;
}
if ( V_177 & V_180 ) {
V_178 = V_3 -> V_119 & V_180 ? 1 : - 1 ;
F_172 ( V_4 -> V_3 , V_178 ) ;
}
}
F_173 () ;
}
static void F_174 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_151 ( V_3 ) ;
struct V_1 * V_4 ;
F_170 () ;
F_78 (port, &team->port_list, list) {
F_175 ( V_4 -> V_3 , V_3 ) ;
F_176 ( V_4 -> V_3 , V_3 ) ;
}
F_173 () ;
}
static int F_177 ( struct V_2 * V_3 , void * V_181 )
{
struct V_8 * V_9 = V_181 ;
struct V_14 * V_14 = F_151 ( V_3 ) ;
struct V_1 * V_4 ;
if ( V_3 -> type == V_182 && ! F_178 ( V_9 -> V_10 ) )
return - V_183 ;
memcpy ( V_3 -> V_7 , V_9 -> V_10 , V_3 -> V_11 ) ;
F_170 () ;
F_78 (port, &team->port_list, list)
if ( V_14 -> V_73 . V_184 )
V_14 -> V_73 . V_184 ( V_14 , V_4 ) ;
F_173 () ;
return 0 ;
}
static int F_179 ( struct V_2 * V_3 , int V_185 )
{
struct V_14 * V_14 = F_151 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 ;
F_103 ( & V_14 -> V_124 ) ;
F_14 (port, &team->port_list, list) {
V_29 = F_118 ( V_4 -> V_3 , V_185 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_26 ,
V_4 -> V_3 -> V_22 ) ;
goto V_186;
}
}
F_104 ( & V_14 -> V_124 ) ;
V_3 -> V_141 = V_185 ;
return 0 ;
V_186:
F_180 (port, &team->port_list, list)
F_118 ( V_4 -> V_3 , V_3 -> V_141 ) ;
F_104 ( & V_14 -> V_124 ) ;
return V_29 ;
}
static struct V_187 *
F_181 ( struct V_2 * V_3 , struct V_187 * V_188 )
{
struct V_14 * V_14 = F_151 ( V_3 ) ;
struct V_86 * V_181 ;
T_8 V_89 , V_90 , V_94 , V_172 , V_173 ;
T_4 V_95 = 0 , V_174 = 0 ;
unsigned int V_189 ;
int V_28 ;
F_182 (i) {
V_181 = F_183 ( V_14 -> V_87 , V_28 ) ;
do {
V_189 = F_184 ( & V_181 -> V_88 ) ;
V_89 = V_181 -> V_89 ;
V_90 = V_181 -> V_90 ;
V_94 = V_181 -> V_94 ;
V_172 = V_181 -> V_172 ;
V_173 = V_181 -> V_173 ;
} while ( F_185 ( & V_181 -> V_88 , V_189 ) );
V_188 -> V_89 += V_89 ;
V_188 -> V_90 += V_90 ;
V_188 -> V_190 += V_94 ;
V_188 -> V_172 += V_172 ;
V_188 -> V_173 += V_173 ;
V_95 += V_181 -> V_95 ;
V_174 += V_181 -> V_174 ;
}
V_188 -> V_95 = V_95 ;
V_188 -> V_174 = V_174 ;
return V_188 ;
}
static int F_186 ( struct V_2 * V_3 , T_9 V_191 , T_3 V_192 )
{
struct V_14 * V_14 = F_151 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 ;
F_103 ( & V_14 -> V_124 ) ;
F_14 (port, &team->port_list, list) {
V_29 = F_187 ( V_4 -> V_3 , V_191 , V_192 ) ;
if ( V_29 )
goto V_186;
}
F_104 ( & V_14 -> V_124 ) ;
return 0 ;
V_186:
F_180 (port, &team->port_list, list)
F_188 ( V_4 -> V_3 , V_191 , V_192 ) ;
F_104 ( & V_14 -> V_124 ) ;
return V_29 ;
}
static int F_189 ( struct V_2 * V_3 , T_9 V_191 , T_3 V_192 )
{
struct V_14 * V_14 = F_151 ( V_3 ) ;
struct V_1 * V_4 ;
F_170 () ;
F_78 (port, &team->port_list, list)
F_188 ( V_4 -> V_3 , V_191 , V_192 ) ;
F_173 () ;
return 0 ;
}
static void F_190 ( struct V_2 * V_3 )
{
}
static void F_191 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
F_14 (port, &team->port_list, list)
F_111 ( V_4 ) ;
}
static void F_192 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_151 ( V_3 ) ;
F_103 ( & V_14 -> V_124 ) ;
F_191 ( V_14 ) ;
F_104 ( & V_14 -> V_124 ) ;
}
static int F_193 ( struct V_2 * V_3 ,
struct V_132 * V_193 , T_5 V_129 )
{
struct V_14 * V_14 = F_151 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 = 0 ;
F_103 ( & V_14 -> V_124 ) ;
F_14 (port, &team->port_list, list) {
V_29 = F_109 ( V_14 , V_4 , V_129 ) ;
if ( V_29 ) {
F_191 ( V_14 ) ;
break;
}
}
F_104 ( & V_14 -> V_124 ) ;
return V_29 ;
}
static int F_194 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_151 ( V_3 ) ;
int V_29 ;
F_103 ( & V_14 -> V_124 ) ;
V_29 = F_115 ( V_14 , V_6 ) ;
F_104 ( & V_14 -> V_124 ) ;
return V_29 ;
}
static int F_195 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_151 ( V_3 ) ;
int V_29 ;
F_103 ( & V_14 -> V_124 ) ;
V_29 = F_129 ( V_14 , V_6 ) ;
F_104 ( & V_14 -> V_124 ) ;
return V_29 ;
}
static T_10 F_196 ( struct V_2 * V_3 ,
T_10 V_136 )
{
struct V_1 * V_4 ;
struct V_14 * V_14 = F_151 ( V_3 ) ;
T_10 V_194 ;
V_194 = V_136 ;
V_136 &= ~ V_195 ;
V_136 |= V_196 ;
F_170 () ;
F_78 (port, &team->port_list, list) {
V_136 = F_100 ( V_136 ,
V_4 -> V_3 -> V_136 ,
V_194 ) ;
}
F_173 () ;
return V_136 ;
}
static int F_197 ( struct V_2 * V_3 , bool V_197 )
{
struct V_14 * V_14 = F_151 ( V_3 ) ;
V_14 -> V_71 = true ;
if ( V_197 )
F_198 ( V_3 ) ;
else
F_156 ( V_3 ) ;
return 0 ;
}
static void F_199 ( struct V_2 * V_3 ,
struct V_198 * V_199 )
{
F_200 ( V_199 -> V_200 , V_201 , sizeof( V_199 -> V_200 ) ) ;
F_200 ( V_199 -> V_202 , V_203 , sizeof( V_199 -> V_202 ) ) ;
}
static void F_201 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
V_3 -> V_204 = V_6 -> V_204 ;
V_3 -> type = V_6 -> type ;
V_3 -> V_123 = V_6 -> V_123 ;
V_3 -> V_11 = V_6 -> V_11 ;
V_3 -> V_141 = V_6 -> V_141 ;
memcpy ( V_3 -> V_205 , V_6 -> V_205 , V_6 -> V_11 ) ;
memcpy ( V_3 -> V_7 , V_6 -> V_7 , V_6 -> V_11 ) ;
}
static int F_117 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
struct V_14 * V_14 = F_151 ( V_3 ) ;
char * V_134 = V_6 -> V_22 ;
int V_29 ;
if ( V_3 -> type == V_6 -> type )
return 0 ;
if ( ! F_63 ( & V_14 -> V_79 ) ) {
F_64 ( V_3 , L_27 , V_134 ) ;
return - V_80 ;
}
V_29 = F_202 ( V_206 , V_3 ) ;
V_29 = F_203 ( V_29 ) ;
if ( V_29 ) {
F_64 ( V_3 , L_28 ) ;
return V_29 ;
}
F_204 ( V_3 ) ;
F_205 ( V_3 ) ;
F_201 ( V_3 , V_6 ) ;
F_202 ( V_207 , V_3 ) ;
return 0 ;
}
static void F_206 ( struct V_2 * V_3 )
{
F_207 ( V_3 ) ;
V_3 -> V_208 = & V_209 ;
V_3 -> V_210 = & V_211 ;
V_3 -> V_212 = F_159 ;
V_3 -> V_213 = 0 ;
V_3 -> V_119 |= V_214 ;
V_3 -> V_122 &= ~ ( V_121 | V_215 ) ;
V_3 -> V_122 |= V_216 | V_217 ;
V_3 -> V_136 |= V_218 ;
V_3 -> V_136 |= V_219 ;
V_3 -> V_220 = V_116 |
V_221 |
V_222 |
V_223 ;
V_3 -> V_220 &= ~ ( V_224 & ~ V_225 ) ;
V_3 -> V_136 |= V_3 -> V_220 ;
}
static int F_208 ( struct V_226 * V_227 , struct V_2 * V_3 ,
struct V_228 * V_229 [] , struct V_228 * V_151 [] )
{
int V_29 ;
if ( V_229 [ V_230 ] == NULL )
F_209 ( V_3 ) ;
V_29 = F_210 ( V_3 ) ;
if ( V_29 )
return V_29 ;
return 0 ;
}
static int F_211 ( struct V_228 * V_229 [] , struct V_228 * V_151 [] )
{
if ( V_229 [ V_230 ] ) {
if ( F_212 ( V_229 [ V_230 ] ) != V_231 )
return - V_62 ;
if ( ! F_178 ( F_213 ( V_229 [ V_230 ] ) ) )
return - V_183 ;
}
return 0 ;
}
static unsigned int F_214 ( void )
{
return V_232 ;
}
static unsigned int F_215 ( void )
{
return V_233 ;
}
static int F_216 ( struct V_67 * V_68 , struct V_234 * V_32 )
{
struct V_67 * V_235 ;
void * V_236 ;
int V_29 ;
V_235 = F_217 ( V_237 , V_30 ) ;
if ( ! V_235 )
return - V_31 ;
V_236 = F_218 ( V_235 , V_32 -> V_238 , V_32 -> V_239 ,
& V_240 , 0 , V_241 ) ;
if ( ! V_236 ) {
V_29 = - V_242 ;
goto V_243;
}
F_219 ( V_235 , V_236 ) ;
return F_220 ( F_221 ( V_32 ) , V_235 , V_32 -> V_238 ) ;
V_243:
F_222 ( V_235 ) ;
return V_29 ;
}
static struct V_14 * F_223 ( struct V_234 * V_32 )
{
struct V_226 * V_226 = F_221 ( V_32 ) ;
int V_244 ;
struct V_2 * V_3 ;
struct V_14 * V_14 ;
if ( ! V_32 -> V_245 [ V_246 ] )
return NULL ;
V_244 = F_224 ( V_32 -> V_245 [ V_246 ] ) ;
V_3 = F_225 ( V_226 , V_244 ) ;
if ( ! V_3 || V_3 -> V_208 != & V_209 ) {
if ( V_3 )
F_107 ( V_3 ) ;
return NULL ;
}
V_14 = F_151 ( V_3 ) ;
F_103 ( & V_14 -> V_124 ) ;
return V_14 ;
}
static void F_226 ( struct V_14 * V_14 )
{
F_104 ( & V_14 -> V_124 ) ;
F_107 ( V_14 -> V_3 ) ;
}
static int F_227 ( struct V_67 * V_68 , struct V_14 * V_14 , T_4 V_247 )
{
return F_220 ( F_228 ( V_14 -> V_3 ) , V_68 , V_247 ) ;
}
static int F_229 ( struct V_67 * V_68 , struct V_14 * V_14 ,
struct V_23 * V_24 )
{
struct V_228 * V_248 ;
struct V_19 * V_21 = V_24 -> V_21 ;
struct V_53 * V_54 = & V_24 -> V_32 ;
struct V_48 V_49 ;
int V_29 ;
V_49 . V_32 = V_54 ;
V_29 = F_36 ( V_14 , V_24 , & V_49 ) ;
if ( V_29 )
return V_29 ;
V_248 = F_230 ( V_68 , V_249 ) ;
if ( ! V_248 )
return - V_242 ;
if ( F_231 ( V_68 , V_250 , V_21 -> V_22 ) )
goto V_251;
if ( V_54 -> V_4 &&
F_232 ( V_68 , V_252 ,
V_54 -> V_4 -> V_3 -> V_244 ) )
goto V_251;
if ( V_24 -> V_21 -> V_27 &&
F_232 ( V_68 , V_253 ,
V_54 -> V_33 ) )
goto V_251;
switch ( V_21 -> type ) {
case V_254 :
if ( F_233 ( V_68 , V_255 , V_256 ) )
goto V_251;
if ( F_232 ( V_68 , V_257 , V_49 . V_151 . V_155 ) )
goto V_251;
break;
case V_258 :
if ( F_233 ( V_68 , V_255 , V_259 ) )
goto V_251;
if ( F_231 ( V_68 , V_257 ,
V_49 . V_151 . V_152 ) )
goto V_251;
break;
case V_260 :
if ( F_233 ( V_68 , V_255 , V_261 ) )
goto V_251;
if ( F_234 ( V_68 , V_257 , V_49 . V_151 . V_262 . V_91 ,
V_49 . V_151 . V_262 . V_263 ) )
goto V_251;
break;
case V_264 :
if ( F_233 ( V_68 , V_255 , V_265 ) )
goto V_251;
if ( V_49 . V_151 . V_153 &&
F_235 ( V_68 , V_257 ) )
goto V_251;
break;
case V_266 :
if ( F_233 ( V_68 , V_255 , V_267 ) )
goto V_251;
if ( F_236 ( V_68 , V_257 , V_49 . V_151 . V_154 ) )
goto V_251;
break;
default:
F_237 () ;
}
if ( V_24 -> V_35 && F_235 ( V_68 , V_268 ) )
goto V_251;
if ( V_24 -> V_34 ) {
if ( F_235 ( V_68 , V_269 ) )
goto V_251;
V_24 -> V_34 = false ;
}
F_238 ( V_68 , V_248 ) ;
return 0 ;
V_251:
F_239 ( V_68 , V_248 ) ;
return - V_242 ;
}
static int F_240 ( struct V_67 * * V_81 ,
struct V_14 * V_14 , T_4 V_247 ,
T_11 * V_270 )
{
int V_29 ;
if ( * V_81 ) {
V_29 = V_270 ( * V_81 , V_14 , V_247 ) ;
if ( V_29 )
return V_29 ;
}
* V_81 = F_241 ( V_271 , V_30 ) ;
if ( ! * V_81 )
return - V_31 ;
return 0 ;
}
static int F_242 ( struct V_14 * V_14 , T_4 V_247 , T_4 V_272 ,
int V_119 , T_11 * V_270 ,
struct V_96 * V_273 )
{
struct V_228 * V_46 ;
struct V_274 * V_275 ;
void * V_236 ;
struct V_23 * V_24 ;
int V_29 ;
struct V_67 * V_68 = NULL ;
bool V_276 ;
int V_28 ;
V_24 = F_243 ( V_273 ,
struct V_23 , V_277 ) ;
V_278:
V_29 = F_240 ( & V_68 , V_14 , V_247 , V_270 ) ;
if ( V_29 )
return V_29 ;
V_236 = F_218 ( V_68 , V_247 , V_272 , & V_240 , V_119 | V_279 ,
V_280 ) ;
if ( ! V_236 )
return - V_242 ;
if ( F_232 ( V_68 , V_246 , V_14 -> V_3 -> V_244 ) )
goto V_281;
V_46 = F_230 ( V_68 , V_282 ) ;
if ( ! V_46 )
goto V_281;
V_28 = 0 ;
V_276 = false ;
F_244 (opt_inst, sel_opt_inst_list, tmp_list) {
V_29 = F_229 ( V_68 , V_14 , V_24 ) ;
if ( V_29 ) {
if ( V_29 == - V_242 ) {
if ( ! V_28 )
goto V_283;
V_276 = true ;
break;
}
goto V_283;
}
V_28 ++ ;
}
F_238 ( V_68 , V_46 ) ;
F_219 ( V_68 , V_236 ) ;
if ( V_276 )
goto V_278;
V_284:
V_275 = F_245 ( V_68 , V_247 , V_272 , V_285 , 0 , V_119 | V_279 ) ;
if ( ! V_275 ) {
V_29 = F_240 ( & V_68 , V_14 , V_247 , V_270 ) ;
if ( V_29 )
goto V_283;
goto V_284;
}
return V_270 ( V_68 , V_14 , V_247 ) ;
V_281:
V_29 = - V_242 ;
V_283:
F_246 ( V_68 , V_236 ) ;
F_222 ( V_68 ) ;
return V_29 ;
}
static int F_247 ( struct V_67 * V_68 , struct V_234 * V_32 )
{
struct V_14 * V_14 ;
struct V_23 * V_24 ;
int V_29 ;
F_248 ( V_273 ) ;
V_14 = F_223 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
F_14 (opt_inst, &team->option_inst_list, list)
F_22 ( & V_24 -> V_277 , & V_273 ) ;
V_29 = F_242 ( V_14 , V_32 -> V_238 , V_32 -> V_239 ,
V_286 , F_227 ,
& V_273 ) ;
F_226 ( V_14 ) ;
return V_29 ;
}
static int F_249 ( struct V_67 * V_68 , struct V_234 * V_32 )
{
struct V_14 * V_14 ;
int V_29 = 0 ;
int V_28 ;
struct V_228 * V_287 ;
F_248 ( V_288 ) ;
V_14 = F_223 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
V_29 = - V_62 ;
if ( ! V_32 -> V_245 [ V_282 ] ) {
V_29 = - V_62 ;
goto V_289;
}
F_250 (nl_option, info->attrs[TEAM_ATTR_LIST_OPTION], i) {
struct V_228 * V_290 [ V_291 + 1 ] ;
struct V_228 * V_292 ;
struct V_228 * V_293 ;
enum V_294 V_295 ;
int V_296 = 0 ;
T_4 V_297 = 0 ;
bool V_298 = false ;
struct V_23 * V_24 ;
char * V_20 ;
bool V_299 = false ;
if ( F_251 ( V_287 ) != V_249 ) {
V_29 = - V_62 ;
goto V_289;
}
V_29 = F_252 ( V_290 , V_291 ,
V_287 , V_300 ) ;
if ( V_29 )
goto V_289;
if ( ! V_290 [ V_250 ] ||
! V_290 [ V_255 ] ) {
V_29 = - V_62 ;
goto V_289;
}
switch ( F_253 ( V_290 [ V_255 ] ) ) {
case V_256 :
V_295 = V_254 ;
break;
case V_259 :
V_295 = V_258 ;
break;
case V_261 :
V_295 = V_260 ;
break;
case V_265 :
V_295 = V_264 ;
break;
case V_267 :
V_295 = V_266 ;
break;
default:
goto V_289;
}
V_293 = V_290 [ V_257 ] ;
if ( V_295 != V_264 && ! V_293 ) {
V_29 = - V_62 ;
goto V_289;
}
V_20 = F_213 ( V_290 [ V_250 ] ) ;
V_292 = V_290 [ V_252 ] ;
if ( V_292 )
V_296 = F_224 ( V_292 ) ;
V_292 = V_290 [ V_253 ] ;
if ( V_292 ) {
V_298 = true ;
V_297 = F_224 ( V_292 ) ;
}
F_14 (opt_inst, &team->option_inst_list, list) {
struct V_19 * V_21 = V_24 -> V_21 ;
struct V_48 V_49 ;
struct V_53 * V_54 ;
int V_301 ;
V_54 = & V_24 -> V_32 ;
V_301 = V_54 -> V_4 ?
V_54 -> V_4 -> V_3 -> V_244 : 0 ;
if ( V_21 -> type != V_295 ||
strcmp ( V_21 -> V_22 , V_20 ) ||
V_301 != V_296 ||
( V_21 -> V_27 && ! V_298 ) ||
V_54 -> V_33 != V_297 )
continue;
V_299 = true ;
V_49 . V_32 = V_54 ;
switch ( V_295 ) {
case V_254 :
V_49 . V_151 . V_155 = F_224 ( V_293 ) ;
break;
case V_258 :
if ( F_212 ( V_293 ) > V_302 ) {
V_29 = - V_62 ;
goto V_289;
}
V_49 . V_151 . V_152 = F_213 ( V_293 ) ;
break;
case V_260 :
V_49 . V_151 . V_262 . V_91 = F_212 ( V_293 ) ;
V_49 . V_151 . V_262 . V_263 = F_213 ( V_293 ) ;
break;
case V_264 :
V_49 . V_151 . V_153 = V_293 ? true : false ;
break;
case V_266 :
V_49 . V_151 . V_154 = F_254 ( V_293 ) ;
break;
default:
F_237 () ;
}
V_29 = F_37 ( V_14 , V_24 , & V_49 ) ;
if ( V_29 )
goto V_289;
V_24 -> V_34 = true ;
F_255 ( & V_24 -> V_277 , & V_288 ) ;
}
if ( ! V_299 ) {
V_29 = - V_149 ;
goto V_289;
}
}
V_29 = F_256 ( V_14 , & V_288 ) ;
V_289:
F_226 ( V_14 ) ;
return V_29 ;
}
static int F_257 ( struct V_67 * V_68 ,
struct V_1 * V_4 )
{
struct V_228 * V_303 ;
V_303 = F_230 ( V_68 , V_304 ) ;
if ( ! V_303 )
goto V_251;
if ( F_232 ( V_68 , V_305 , V_4 -> V_3 -> V_244 ) )
goto V_251;
if ( V_4 -> V_34 ) {
if ( F_235 ( V_68 , V_306 ) )
goto V_251;
V_4 -> V_34 = false ;
}
if ( ( V_4 -> V_35 &&
F_235 ( V_68 , V_307 ) ) ||
( V_4 -> V_18 . V_15 &&
F_235 ( V_68 , V_308 ) ) ||
F_232 ( V_68 , V_309 , V_4 -> V_18 . V_310 ) ||
F_233 ( V_68 , V_311 , V_4 -> V_18 . V_312 ) )
goto V_251;
F_238 ( V_68 , V_303 ) ;
return 0 ;
V_251:
F_239 ( V_68 , V_303 ) ;
return - V_242 ;
}
static int F_258 ( struct V_14 * V_14 , T_4 V_247 , T_4 V_272 ,
int V_119 , T_11 * V_270 ,
struct V_1 * V_313 )
{
struct V_228 * V_79 ;
struct V_274 * V_275 ;
void * V_236 ;
struct V_1 * V_4 ;
int V_29 ;
struct V_67 * V_68 = NULL ;
bool V_276 ;
int V_28 ;
V_4 = F_259 ( & V_14 -> V_79 ,
struct V_1 , V_25 ) ;
V_278:
V_29 = F_240 ( & V_68 , V_14 , V_247 , V_270 ) ;
if ( V_29 )
return V_29 ;
V_236 = F_218 ( V_68 , V_247 , V_272 , & V_240 , V_119 | V_279 ,
V_314 ) ;
if ( ! V_236 )
return - V_242 ;
if ( F_232 ( V_68 , V_246 , V_14 -> V_3 -> V_244 ) )
goto V_281;
V_79 = F_230 ( V_68 , V_315 ) ;
if ( ! V_79 )
goto V_281;
V_28 = 0 ;
V_276 = false ;
if ( V_313 ) {
V_29 = F_257 ( V_68 , V_313 ) ;
if ( V_29 )
goto V_283;
} else if ( V_4 ) {
F_244 (port, &team->port_list, list) {
V_29 = F_257 ( V_68 , V_4 ) ;
if ( V_29 ) {
if ( V_29 == - V_242 ) {
if ( ! V_28 )
goto V_283;
V_276 = true ;
break;
}
goto V_283;
}
V_28 ++ ;
}
}
F_238 ( V_68 , V_79 ) ;
F_219 ( V_68 , V_236 ) ;
if ( V_276 )
goto V_278;
V_284:
V_275 = F_245 ( V_68 , V_247 , V_272 , V_285 , 0 , V_119 | V_279 ) ;
if ( ! V_275 ) {
V_29 = F_240 ( & V_68 , V_14 , V_247 , V_270 ) ;
if ( V_29 )
goto V_283;
goto V_284;
}
return V_270 ( V_68 , V_14 , V_247 ) ;
V_281:
V_29 = - V_242 ;
V_283:
F_246 ( V_68 , V_236 ) ;
F_222 ( V_68 ) ;
return V_29 ;
}
static int F_260 ( struct V_67 * V_68 ,
struct V_234 * V_32 )
{
struct V_14 * V_14 ;
int V_29 ;
V_14 = F_223 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
V_29 = F_258 ( V_14 , V_32 -> V_238 , V_32 -> V_239 ,
V_286 , F_227 , NULL ) ;
F_226 ( V_14 ) ;
return V_29 ;
}
static int F_261 ( struct V_67 * V_68 ,
struct V_14 * V_14 , T_4 V_247 )
{
return F_262 ( F_228 ( V_14 -> V_3 ) , V_68 , 0 ,
V_316 . V_317 , V_30 ) ;
}
static int F_256 ( struct V_14 * V_14 ,
struct V_96 * V_273 )
{
return F_242 ( V_14 , 0 , 0 , 0 , F_261 ,
V_273 ) ;
}
static int F_263 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
return F_258 ( V_14 , 0 , 0 , 0 , F_261 ,
V_4 ) ;
}
static int F_264 ( void )
{
int V_29 ;
V_29 = F_265 ( & V_240 , V_318 ,
F_155 ( V_318 ) ) ;
if ( V_29 )
return V_29 ;
V_29 = F_266 ( & V_240 , & V_316 ) ;
if ( V_29 )
goto V_319;
return 0 ;
V_319:
F_267 ( & V_240 ) ;
return V_29 ;
}
static void F_268 ( void )
{
F_267 ( & V_240 ) ;
}
static void F_34 ( struct V_14 * V_14 )
{
int V_29 ;
struct V_23 * V_24 ;
F_248 ( V_273 ) ;
F_14 (opt_inst, &team->option_inst_list, list) {
if ( V_24 -> V_34 )
F_22 ( & V_24 -> V_277 , & V_273 ) ;
}
V_29 = F_256 ( V_14 , & V_273 ) ;
if ( V_29 && V_29 != - V_320 )
F_269 ( V_14 -> V_3 , L_29 ,
V_29 ) ;
}
static void F_270 ( struct V_1 * V_4 , bool V_15 )
{
int V_29 ;
V_4 -> V_34 = true ;
V_4 -> V_18 . V_15 = V_15 ;
F_12 ( V_4 ) ;
if ( V_15 ) {
struct V_321 V_322 ;
V_29 = F_271 ( V_4 -> V_3 , & V_322 ) ;
if ( ! V_29 ) {
V_4 -> V_18 . V_310 = F_272 ( & V_322 ) ;
V_4 -> V_18 . V_312 = V_322 . V_312 ;
goto V_323;
}
}
V_4 -> V_18 . V_310 = 0 ;
V_4 -> V_18 . V_312 = 0 ;
V_323:
V_29 = F_263 ( V_4 -> V_14 , V_4 ) ;
if ( V_29 && V_29 != - V_320 )
F_269 ( V_4 -> V_14 -> V_3 , L_30 ,
V_4 -> V_3 -> V_22 , V_29 ) ;
}
static void F_273 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
bool V_324 ;
if ( V_14 -> V_71 )
return;
V_324 = false ;
F_14 (port, &team->port_list, list) {
if ( V_4 -> V_15 ) {
V_324 = true ;
break;
}
}
if ( V_324 )
F_198 ( V_14 -> V_3 ) ;
else
F_156 ( V_14 -> V_3 ) ;
}
static void F_274 ( struct V_1 * V_4 , bool V_15 )
{
if ( V_4 -> V_18 . V_15 != V_15 )
F_270 ( V_4 , V_15 ) ;
F_273 ( V_4 -> V_14 ) ;
}
static void F_123 ( struct V_1 * V_4 , bool V_15 )
{
F_270 ( V_4 , V_15 ) ;
F_273 ( V_4 -> V_14 ) ;
}
static void F_132 ( struct V_1 * V_4 )
{
V_4 -> V_35 = true ;
F_270 ( V_4 , false ) ;
F_273 ( V_4 -> V_14 ) ;
}
static void F_275 ( struct V_1 * V_4 , bool V_15 )
{
struct V_14 * V_14 = V_4 -> V_14 ;
F_103 ( & V_14 -> V_124 ) ;
F_274 ( V_4 , V_15 ) ;
F_104 ( & V_14 -> V_124 ) ;
}
static int F_276 ( struct V_325 * V_159 ,
unsigned long V_326 , void * V_263 )
{
struct V_2 * V_3 = F_277 ( V_263 ) ;
struct V_1 * V_4 ;
V_4 = F_4 ( V_3 ) ;
if ( ! V_4 )
return V_327 ;
switch ( V_326 ) {
case V_328 :
if ( F_124 ( V_3 ) )
F_275 ( V_4 , true ) ;
case V_329 :
F_275 ( V_4 , false ) ;
case V_330 :
if ( F_278 ( V_4 -> V_3 ) )
F_275 ( V_4 ,
! ! F_124 ( V_4 -> V_3 ) ) ;
break;
case V_331 :
F_195 ( V_4 -> V_14 -> V_3 , V_3 ) ;
break;
case V_332 :
F_102 ( V_4 -> V_14 ) ;
break;
case V_333 :
return V_334 ;
case V_206 :
return V_334 ;
}
return V_327 ;
}
static int T_12 F_279 ( void )
{
int V_29 ;
F_280 ( & V_335 ) ;
V_29 = F_281 ( & V_336 ) ;
if ( V_29 )
goto V_337;
V_29 = F_264 () ;
if ( V_29 )
goto V_338;
return 0 ;
V_338:
F_282 ( & V_336 ) ;
V_337:
F_283 ( & V_335 ) ;
return V_29 ;
}
static void T_13 F_284 ( void )
{
F_268 () ;
F_282 ( & V_336 ) ;
F_283 ( & V_335 ) ;
}
