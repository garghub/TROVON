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
V_14 -> V_58 = & V_70 ;
}
static void F_56 ( struct V_14 * V_14 , int V_71 )
{
if ( ! V_71 || ! F_54 ( V_14 ) ||
! V_14 -> V_58 -> V_72 -> V_73 )
V_14 -> V_72 . V_73 = F_51 ;
else
V_14 -> V_72 . V_73 = V_14 -> V_58 -> V_72 -> V_73 ;
if ( ! V_71 || ! F_54 ( V_14 ) ||
! V_14 -> V_58 -> V_72 -> V_74 )
V_14 -> V_72 . V_74 = F_53 ;
else
V_14 -> V_72 . V_74 = V_14 -> V_58 -> V_72 -> V_74 ;
}
static void F_57 ( struct V_14 * V_14 )
{
F_56 ( V_14 , V_14 -> V_71 ) ;
}
static int F_58 ( struct V_14 * V_14 ,
const struct V_59 * V_75 )
{
if ( F_54 ( V_14 ) ) {
void (* F_59)( struct V_14 * V_14 ) = V_14 -> V_72 . exit ;
memset ( & V_14 -> V_72 , 0 , sizeof( struct V_76 ) ) ;
F_57 ( V_14 ) ;
if ( F_59 )
F_59 ( V_14 ) ;
F_49 ( V_14 -> V_58 ) ;
F_55 ( V_14 ) ;
memset ( & V_14 -> V_77 , 0 ,
sizeof( struct V_14 ) - F_60 ( struct V_14 , V_77 ) ) ;
}
if ( ! V_75 )
return 0 ;
if ( V_75 -> V_72 -> V_37 ) {
int V_29 ;
V_29 = V_75 -> V_72 -> V_37 ( V_14 ) ;
if ( V_29 )
return V_29 ;
}
V_14 -> V_58 = V_75 ;
memcpy ( & V_14 -> V_72 , V_75 -> V_72 , sizeof( struct V_76 ) ) ;
F_57 ( V_14 ) ;
return 0 ;
}
static int F_61 ( struct V_14 * V_14 , const char * V_56 )
{
const struct V_59 * V_75 ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_29 ;
if ( ! F_62 ( & V_14 -> V_78 ) ) {
F_63 ( V_3 , L_2 ) ;
return - V_79 ;
}
if ( F_54 ( V_14 ) && strcmp ( V_14 -> V_58 -> V_56 , V_56 ) == 0 ) {
F_63 ( V_3 , L_3 ) ;
return - V_62 ;
}
V_75 = F_46 ( V_56 ) ;
if ( ! V_75 ) {
F_63 ( V_3 , L_4 , V_56 ) ;
return - V_62 ;
}
V_29 = F_58 ( V_14 , V_75 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_5 , V_56 ) ;
F_49 ( V_75 ) ;
return V_29 ;
}
F_64 ( V_3 , L_6 , V_56 ) ;
return 0 ;
}
static T_2 F_65 ( struct V_67 * * V_80 )
{
struct V_67 * V_68 = * V_80 ;
struct V_1 * V_4 ;
struct V_14 * V_14 ;
T_2 V_81 ;
V_68 = F_66 ( V_68 , V_82 ) ;
if ( ! V_68 )
return V_83 ;
* V_80 = V_68 ;
V_4 = F_1 ( V_68 -> V_3 ) ;
V_14 = V_4 -> V_14 ;
if ( ! F_67 ( V_4 ) ) {
V_81 = V_84 ;
} else {
V_81 = V_14 -> V_72 . V_74 ( V_14 , V_4 , V_68 ) ;
}
if ( V_81 == V_69 ) {
struct V_85 * V_86 ;
V_86 = F_68 ( V_14 -> V_86 ) ;
F_69 ( & V_86 -> V_87 ) ;
V_86 -> V_88 ++ ;
V_86 -> V_89 += V_68 -> V_90 ;
if ( V_68 -> V_91 == V_92 )
V_86 -> V_93 ++ ;
F_70 ( & V_86 -> V_87 ) ;
V_68 -> V_3 = V_14 -> V_3 ;
} else {
F_71 ( V_14 -> V_86 -> V_94 ) ;
}
return V_81 ;
}
static int F_72 ( struct V_14 * V_14 )
{
struct V_95 * V_96 ;
unsigned int V_97 = V_14 -> V_3 -> V_98 - 1 ;
unsigned int V_28 ;
if ( ! V_97 )
return 0 ;
V_96 = F_19 ( sizeof( struct V_95 ) * V_97 , V_30 ) ;
if ( ! V_96 )
return - V_31 ;
V_14 -> V_99 = V_96 ;
for ( V_28 = 0 ; V_28 < V_97 ; V_28 ++ )
F_73 ( V_96 ++ ) ;
return 0 ;
}
static void F_74 ( struct V_14 * V_14 )
{
F_15 ( V_14 -> V_99 ) ;
}
static struct V_95 * F_75 ( struct V_14 * V_14 , T_3 V_100 )
{
return & V_14 -> V_99 [ V_100 - 1 ] ;
}
static bool F_76 ( struct V_14 * V_14 , struct V_67 * V_68 )
{
struct V_95 * V_101 ;
struct V_1 * V_4 ;
if ( ! V_14 -> V_102 || ! V_68 -> V_103 )
return false ;
V_101 = F_75 ( V_14 , V_68 -> V_103 ) ;
F_77 (port, qom_list, qom_list) {
if ( ! F_78 ( V_14 , V_4 , V_68 ) )
return true ;
}
return false ;
}
static void F_79 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
F_80 ( & V_4 -> V_101 ) ;
F_81 () ;
F_73 ( & V_4 -> V_101 ) ;
}
static bool F_82 ( struct V_1 * V_4 ,
struct V_1 * V_104 )
{
if ( V_4 -> V_105 < V_104 -> V_105 )
return true ;
if ( V_4 -> V_105 > V_104 -> V_105 )
return false ;
if ( V_4 -> V_106 < V_104 -> V_106 )
return true ;
return false ;
}
static void F_83 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
struct V_1 * V_104 ;
struct V_95 * V_101 ;
struct V_95 * V_107 ;
if ( ! V_4 -> V_100 || ! F_67 ( V_4 ) )
return;
V_101 = F_75 ( V_14 , V_4 -> V_100 ) ;
V_107 = V_101 ;
F_12 (cur, qom_list, qom_list) {
if ( F_82 ( V_4 , V_104 ) )
break;
V_107 = & V_104 -> V_101 ;
}
F_84 ( & V_4 -> V_101 , V_107 ) ;
}
static void F_85 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
bool V_108 = false ;
F_12 (port, &team->port_list, list) {
if ( ! F_62 ( & V_4 -> V_101 ) ) {
V_108 = true ;
break;
}
}
if ( V_108 == V_14 -> V_102 )
return;
F_86 ( V_14 -> V_3 , L_7 ,
V_108 ? L_8 : L_9 ) ;
V_14 -> V_102 = V_108 ;
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
struct V_1 * V_104 ;
F_12 (cur, &team->port_list, list)
if ( V_104 == V_4 )
return true ;
return false ;
}
static void F_89 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
if ( F_67 ( V_4 ) )
return;
V_4 -> V_106 = V_14 -> V_71 ++ ;
F_90 ( & V_4 -> V_109 ,
F_91 ( V_14 , V_4 -> V_106 ) ) ;
F_57 ( V_14 ) ;
F_87 ( V_14 , V_4 ) ;
if ( V_14 -> V_72 . V_110 )
V_14 -> V_72 . V_110 ( V_14 , V_4 ) ;
}
static void F_92 ( struct V_14 * V_14 , int V_111 )
{
int V_28 ;
struct V_1 * V_4 ;
for ( V_28 = V_111 + 1 ; V_28 < V_14 -> V_71 ; V_28 ++ ) {
V_4 = F_93 ( V_14 , V_28 ) ;
F_94 ( & V_4 -> V_109 ) ;
V_4 -> V_106 -- ;
F_90 ( & V_4 -> V_109 ,
F_91 ( V_14 , V_4 -> V_106 ) ) ;
}
}
static void F_95 ( struct V_14 * V_14 ,
struct V_1 * V_4 )
{
if ( ! F_67 ( V_4 ) )
return;
if ( V_14 -> V_72 . V_112 )
V_14 -> V_72 . V_112 ( V_14 , V_4 ) ;
F_94 ( & V_4 -> V_109 ) ;
F_92 ( V_14 , V_4 -> V_106 ) ;
V_4 -> V_106 = - 1 ;
F_87 ( V_14 , V_4 ) ;
F_56 ( V_14 , V_14 -> V_71 - 1 ) ;
F_81 () ;
V_14 -> V_71 -- ;
}
static void F_96 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
T_4 V_113 = V_114 ;
unsigned short V_115 = V_116 ;
unsigned int V_117 , V_118 = V_119 ;
F_12 (port, &team->port_list, list) {
V_113 = F_97 ( V_113 ,
V_4 -> V_3 -> V_113 ,
V_114 ) ;
V_118 &= V_4 -> V_3 -> V_120 ;
if ( V_4 -> V_3 -> V_121 > V_115 )
V_115 = V_4 -> V_3 -> V_121 ;
}
V_14 -> V_3 -> V_113 = V_113 ;
V_14 -> V_3 -> V_121 = V_115 ;
V_117 = V_14 -> V_3 -> V_120 & ~ V_119 ;
V_14 -> V_3 -> V_120 = V_117 | V_118 ;
F_98 ( V_14 -> V_3 ) ;
}
static void F_99 ( struct V_14 * V_14 )
{
F_100 ( & V_14 -> V_122 ) ;
F_96 ( V_14 ) ;
F_101 ( & V_14 -> V_122 ) ;
}
static int F_102 ( struct V_14 * V_14 , struct V_1 * V_4 )
{
int V_29 = 0 ;
F_103 ( V_14 -> V_3 ) ;
V_4 -> V_3 -> V_120 |= V_123 ;
if ( V_14 -> V_72 . V_124 ) {
V_29 = V_14 -> V_72 . V_124 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_63 ( V_14 -> V_3 , L_10 ,
V_4 -> V_3 -> V_22 ) ;
goto V_125;
}
}
return 0 ;
V_125:
V_4 -> V_3 -> V_120 &= ~ V_123 ;
F_104 ( V_14 -> V_3 ) ;
return V_29 ;
}
static void F_105 ( struct V_14 * V_14 , struct V_1 * V_4 )
{
if ( V_14 -> V_72 . V_126 )
V_14 -> V_72 . V_126 ( V_14 , V_4 ) ;
V_4 -> V_3 -> V_120 &= ~ V_123 ;
F_104 ( V_14 -> V_3 ) ;
}
static int F_106 ( struct V_14 * V_14 , struct V_1 * V_4 ,
T_5 V_127 )
{
struct V_128 * V_129 ;
int V_29 ;
V_129 = F_27 ( sizeof( * V_129 ) , V_127 ) ;
if ( ! V_129 )
return - V_31 ;
V_29 = F_107 ( V_129 , V_4 -> V_3 , V_127 ) ;
if ( V_29 ) {
F_15 ( V_129 ) ;
return V_29 ;
}
V_4 -> V_129 = V_129 ;
return V_29 ;
}
static void F_108 ( struct V_1 * V_4 )
{
struct V_128 * V_129 = V_4 -> V_129 ;
if ( ! V_129 )
return;
V_4 -> V_129 = NULL ;
F_109 () ;
F_110 ( V_129 ) ;
F_15 ( V_129 ) ;
}
static struct V_130 * F_111 ( struct V_14 * V_14 )
{
return V_14 -> V_3 -> V_131 ;
}
static int F_106 ( struct V_14 * V_14 , struct V_1 * V_4 ,
T_5 V_127 )
{
return 0 ;
}
static void F_108 ( struct V_1 * V_4 )
{
}
static struct V_130 * F_111 ( struct V_14 * V_14 )
{
return NULL ;
}
static int F_112 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_4 ;
char * V_132 = V_6 -> V_22 ;
int V_29 ;
if ( V_6 -> V_117 & V_133 ) {
F_63 ( V_3 , L_11 ,
V_132 ) ;
return - V_62 ;
}
if ( F_3 ( V_6 ) ) {
F_63 ( V_3 , L_12
L_13 , V_132 ) ;
return - V_79 ;
}
if ( V_6 -> V_134 & V_135 &&
F_113 ( V_3 ) ) {
F_63 ( V_3 , L_14 ,
V_132 ) ;
return - V_136 ;
}
V_29 = F_114 ( V_3 , V_6 ) ;
if ( V_29 )
return V_29 ;
if ( V_6 -> V_117 & V_137 ) {
F_63 ( V_3 , L_15 ,
V_132 ) ;
return - V_79 ;
}
V_4 = F_27 ( sizeof( struct V_1 ) + V_14 -> V_58 -> V_138 ,
V_30 ) ;
if ( ! V_4 )
return - V_31 ;
V_4 -> V_3 = V_6 ;
V_4 -> V_14 = V_14 ;
F_73 ( & V_4 -> V_101 ) ;
V_4 -> V_13 . V_139 = V_6 -> V_139 ;
V_29 = F_115 ( V_6 , V_3 -> V_139 ) ;
if ( V_29 ) {
F_86 ( V_3 , L_16 , V_29 ) ;
goto V_140;
}
memcpy ( V_4 -> V_13 . V_7 , V_6 -> V_7 , V_6 -> V_11 ) ;
V_29 = F_102 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_10 ,
V_132 ) ;
goto V_125;
}
V_29 = F_116 ( V_6 ) ;
if ( V_29 ) {
F_86 ( V_3 , L_17 ,
V_132 ) ;
goto V_141;
}
V_29 = F_117 ( V_6 , V_3 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_18 ,
V_132 ) ;
goto V_142;
}
if ( F_111 ( V_14 ) ) {
V_29 = F_106 ( V_14 , V_4 , V_30 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_19 ,
V_132 ) ;
goto V_143;
}
}
V_29 = F_118 ( V_6 , V_3 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_20 , V_132 ) ;
goto V_144;
}
V_29 = F_119 ( V_6 , F_65 ,
V_4 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_21 ,
V_132 ) ;
goto V_145;
}
V_29 = F_24 ( V_14 , V_4 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_22 ,
V_132 ) ;
goto V_146;
}
V_4 -> V_106 = - 1 ;
F_89 ( V_14 , V_4 ) ;
F_84 ( & V_4 -> V_25 , & V_14 -> V_78 ) ;
F_96 ( V_14 ) ;
F_120 ( V_4 , ! ! F_121 ( V_6 ) ) ;
F_32 ( V_14 ) ;
F_64 ( V_3 , L_23 , V_132 ) ;
return 0 ;
V_146:
F_122 ( V_6 ) ;
V_145:
F_118 ( V_6 , NULL ) ;
V_144:
F_108 ( V_4 ) ;
V_143:
F_123 ( V_6 , V_3 ) ;
V_142:
F_124 ( V_6 ) ;
V_141:
F_105 ( V_14 , V_4 ) ;
F_8 ( V_4 ) ;
V_125:
F_115 ( V_6 , V_4 -> V_13 . V_139 ) ;
V_140:
F_15 ( V_4 ) ;
return V_29 ;
}
static int F_125 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_4 ;
char * V_132 = V_6 -> V_22 ;
V_4 = F_4 ( V_6 ) ;
if ( ! V_4 || ! F_88 ( V_14 , V_4 ) ) {
F_63 ( V_3 , L_24 ,
V_132 ) ;
return - V_147 ;
}
F_25 ( V_14 , V_4 ) ;
F_32 ( V_14 ) ;
F_23 ( V_14 , V_4 ) ;
F_126 ( V_4 ) ;
F_95 ( V_14 , V_4 ) ;
F_80 ( & V_4 -> V_25 ) ;
F_122 ( V_6 ) ;
F_118 ( V_6 , NULL ) ;
F_108 ( V_4 ) ;
F_123 ( V_6 , V_3 ) ;
F_124 ( V_6 ) ;
F_105 ( V_14 , V_4 ) ;
F_8 ( V_4 ) ;
F_115 ( V_6 , V_4 -> V_13 . V_139 ) ;
F_81 () ;
F_15 ( V_4 ) ;
F_64 ( V_3 , L_25 , V_132 ) ;
F_96 ( V_14 ) ;
return 0 ;
}
static int F_127 ( struct V_14 * V_14 , struct V_48 * V_49 )
{
V_49 -> V_148 . V_149 = V_14 -> V_58 -> V_56 ;
return 0 ;
}
static int F_128 ( struct V_14 * V_14 , struct V_48 * V_49 )
{
return F_61 ( V_14 , V_49 -> V_148 . V_149 ) ;
}
static int F_129 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_148 . V_150 = F_67 ( V_4 ) ;
return 0 ;
}
static int F_130 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
if ( V_49 -> V_148 . V_150 )
F_89 ( V_14 , V_4 ) ;
else
F_95 ( V_14 , V_4 ) ;
return 0 ;
}
static int F_131 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_148 . V_150 = V_4 -> V_16 . V_15 ;
return 0 ;
}
static int F_132 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_4 -> V_16 . V_15 = V_49 -> V_148 . V_150 ;
F_10 ( V_4 ) ;
return 0 ;
}
static int F_133 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_148 . V_150 = V_4 -> V_16 . V_17 ;
return 0 ;
}
static int F_134 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_4 -> V_16 . V_17 = V_49 -> V_148 . V_150 ;
F_10 ( V_4 ) ;
return 0 ;
}
static int F_135 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_148 . V_151 = V_4 -> V_105 ;
return 0 ;
}
static int F_136 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_4 -> V_105 = V_49 -> V_148 . V_151 ;
F_87 ( V_14 , V_4 ) ;
return 0 ;
}
static int F_137 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
V_49 -> V_148 . V_152 = V_4 -> V_100 ;
return 0 ;
}
static int F_138 ( struct V_14 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_32 -> V_4 ;
if ( V_4 -> V_100 == V_49 -> V_148 . V_152 )
return 0 ;
if ( V_49 -> V_148 . V_152 >= V_14 -> V_3 -> V_153 )
return - V_62 ;
V_4 -> V_100 = V_49 -> V_148 . V_152 ;
F_87 ( V_14 , V_4 ) ;
return 0 ;
}
static void F_139 ( struct V_2 * V_3 ,
struct V_154 * V_155 ,
void * V_156 )
{
F_140 ( & V_155 -> V_157 , & V_158 ) ;
}
static void F_141 ( struct V_2 * V_3 )
{
F_140 ( & V_3 -> V_159 , & V_160 ) ;
F_142 ( V_3 , F_139 , NULL ) ;
V_3 -> V_161 = & V_162 ;
}
static int F_143 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_144 ( V_3 ) ;
int V_28 ;
int V_29 ;
V_14 -> V_3 = V_3 ;
F_145 ( & V_14 -> V_122 ) ;
F_55 ( V_14 ) ;
V_14 -> V_86 = F_146 ( struct V_85 ) ;
if ( ! V_14 -> V_86 )
return - V_31 ;
for ( V_28 = 0 ; V_28 < V_163 ; V_28 ++ )
F_147 ( & V_14 -> V_164 [ V_28 ] ) ;
F_73 ( & V_14 -> V_78 ) ;
V_29 = F_72 ( V_14 ) ;
if ( V_29 )
goto V_165;
F_57 ( V_14 ) ;
F_73 ( & V_14 -> V_46 ) ;
F_73 ( & V_14 -> V_36 ) ;
V_29 = F_31 ( V_14 , V_166 , F_148 ( V_166 ) ) ;
if ( V_29 )
goto V_167;
F_149 ( V_3 ) ;
F_141 ( V_3 ) ;
return 0 ;
V_167:
F_74 ( V_14 ) ;
V_165:
F_150 ( V_14 -> V_86 ) ;
return V_29 ;
}
static void F_151 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_144 ( V_3 ) ;
struct V_1 * V_4 ;
struct V_1 * V_26 ;
F_100 ( & V_14 -> V_122 ) ;
F_17 (port, tmp, &team->port_list, list)
F_125 ( V_14 , V_4 -> V_3 ) ;
F_58 ( V_14 , NULL ) ;
F_30 ( V_14 , V_166 , F_148 ( V_166 ) ) ;
F_74 ( V_14 ) ;
F_101 ( & V_14 -> V_122 ) ;
}
static void F_152 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_144 ( V_3 ) ;
F_150 ( V_14 -> V_86 ) ;
F_153 ( V_3 ) ;
}
static int F_154 ( struct V_2 * V_3 )
{
F_155 ( V_3 ) ;
return 0 ;
}
static int F_156 ( struct V_2 * V_3 )
{
F_149 ( V_3 ) ;
return 0 ;
}
static T_6 F_157 ( struct V_67 * V_68 , struct V_2 * V_3 )
{
struct V_14 * V_14 = F_144 ( V_3 ) ;
bool V_168 ;
unsigned int V_90 = V_68 -> V_90 ;
V_168 = F_76 ( V_14 , V_68 ) ;
if ( ! V_168 )
V_168 = V_14 -> V_72 . V_73 ( V_14 , V_68 ) ;
if ( V_168 ) {
struct V_85 * V_86 ;
V_86 = F_68 ( V_14 -> V_86 ) ;
F_69 ( & V_86 -> V_87 ) ;
V_86 -> V_169 ++ ;
V_86 -> V_170 += V_90 ;
F_70 ( & V_86 -> V_87 ) ;
} else {
F_71 ( V_14 -> V_86 -> V_171 ) ;
}
return V_172 ;
}
static T_3 F_158 ( struct V_2 * V_3 , struct V_67 * V_68 )
{
T_3 V_155 = F_159 ( V_68 ) ? F_160 ( V_68 ) : 0 ;
F_161 ( V_68 ) -> V_173 = V_68 -> V_103 ;
if ( F_162 ( V_155 >= V_3 -> V_153 ) ) {
do {
V_155 -= V_3 -> V_153 ;
} while ( V_155 >= V_3 -> V_153 );
}
return V_155 ;
}
static void F_163 ( struct V_2 * V_3 , int V_174 )
{
struct V_14 * V_14 = F_144 ( V_3 ) ;
struct V_1 * V_4 ;
int V_175 ;
F_164 () ;
F_77 (port, &team->port_list, list) {
if ( V_174 & V_176 ) {
V_175 = V_3 -> V_117 & V_176 ? 1 : - 1 ;
F_165 ( V_4 -> V_3 , V_175 ) ;
}
if ( V_174 & V_177 ) {
V_175 = V_3 -> V_117 & V_177 ? 1 : - 1 ;
F_166 ( V_4 -> V_3 , V_175 ) ;
}
}
F_167 () ;
}
static void F_168 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_144 ( V_3 ) ;
struct V_1 * V_4 ;
F_164 () ;
F_77 (port, &team->port_list, list) {
F_169 ( V_4 -> V_3 , V_3 ) ;
F_170 ( V_4 -> V_3 , V_3 ) ;
}
F_167 () ;
}
static int F_171 ( struct V_2 * V_3 , void * V_178 )
{
struct V_8 * V_9 = V_178 ;
struct V_14 * V_14 = F_144 ( V_3 ) ;
struct V_1 * V_4 ;
if ( V_3 -> type == V_179 && ! F_172 ( V_9 -> V_10 ) )
return - V_180 ;
memcpy ( V_3 -> V_7 , V_9 -> V_10 , V_3 -> V_11 ) ;
V_3 -> V_181 &= ~ V_182 ;
F_164 () ;
F_77 (port, &team->port_list, list)
if ( V_14 -> V_72 . V_183 )
V_14 -> V_72 . V_183 ( V_14 , V_4 ) ;
F_167 () ;
return 0 ;
}
static int F_173 ( struct V_2 * V_3 , int V_184 )
{
struct V_14 * V_14 = F_144 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 ;
F_100 ( & V_14 -> V_122 ) ;
F_12 (port, &team->port_list, list) {
V_29 = F_115 ( V_4 -> V_3 , V_184 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_26 ,
V_4 -> V_3 -> V_22 ) ;
goto V_185;
}
}
F_101 ( & V_14 -> V_122 ) ;
V_3 -> V_139 = V_184 ;
return 0 ;
V_185:
F_174 (port, &team->port_list, list)
F_115 ( V_4 -> V_3 , V_3 -> V_139 ) ;
F_101 ( & V_14 -> V_122 ) ;
return V_29 ;
}
static struct V_186 *
F_175 ( struct V_2 * V_3 , struct V_186 * V_187 )
{
struct V_14 * V_14 = F_144 ( V_3 ) ;
struct V_85 * V_178 ;
T_7 V_88 , V_89 , V_93 , V_169 , V_170 ;
T_4 V_94 = 0 , V_171 = 0 ;
unsigned int V_188 ;
int V_28 ;
F_176 (i) {
V_178 = F_177 ( V_14 -> V_86 , V_28 ) ;
do {
V_188 = F_178 ( & V_178 -> V_87 ) ;
V_88 = V_178 -> V_88 ;
V_89 = V_178 -> V_89 ;
V_93 = V_178 -> V_93 ;
V_169 = V_178 -> V_169 ;
V_170 = V_178 -> V_170 ;
} while ( F_179 ( & V_178 -> V_87 , V_188 ) );
V_187 -> V_88 += V_88 ;
V_187 -> V_89 += V_89 ;
V_187 -> V_189 += V_93 ;
V_187 -> V_169 += V_169 ;
V_187 -> V_170 += V_170 ;
V_94 += V_178 -> V_94 ;
V_171 += V_178 -> V_171 ;
}
V_187 -> V_94 = V_94 ;
V_187 -> V_171 = V_171 ;
return V_187 ;
}
static int F_180 ( struct V_2 * V_3 , T_8 V_190 )
{
struct V_14 * V_14 = F_144 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 ;
F_100 ( & V_14 -> V_122 ) ;
F_12 (port, &team->port_list, list) {
V_29 = F_181 ( V_4 -> V_3 , V_190 ) ;
if ( V_29 )
goto V_185;
}
F_101 ( & V_14 -> V_122 ) ;
return 0 ;
V_185:
F_174 (port, &team->port_list, list)
F_182 ( V_4 -> V_3 , V_190 ) ;
F_101 ( & V_14 -> V_122 ) ;
return V_29 ;
}
static int F_183 ( struct V_2 * V_3 , T_8 V_190 )
{
struct V_14 * V_14 = F_144 ( V_3 ) ;
struct V_1 * V_4 ;
F_164 () ;
F_77 (port, &team->port_list, list)
F_182 ( V_4 -> V_3 , V_190 ) ;
F_167 () ;
return 0 ;
}
static void F_184 ( struct V_2 * V_3 )
{
}
static void F_185 ( struct V_14 * V_14 )
{
struct V_1 * V_4 ;
F_12 (port, &team->port_list, list)
F_108 ( V_4 ) ;
}
static void F_186 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_144 ( V_3 ) ;
F_100 ( & V_14 -> V_122 ) ;
F_185 ( V_14 ) ;
F_101 ( & V_14 -> V_122 ) ;
}
static int F_187 ( struct V_2 * V_3 ,
struct V_130 * V_191 , T_5 V_127 )
{
struct V_14 * V_14 = F_144 ( V_3 ) ;
struct V_1 * V_4 ;
int V_29 = 0 ;
F_100 ( & V_14 -> V_122 ) ;
F_12 (port, &team->port_list, list) {
V_29 = F_106 ( V_14 , V_4 , V_127 ) ;
if ( V_29 ) {
F_185 ( V_14 ) ;
break;
}
}
F_101 ( & V_14 -> V_122 ) ;
return V_29 ;
}
static int F_188 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_144 ( V_3 ) ;
int V_29 ;
F_100 ( & V_14 -> V_122 ) ;
V_29 = F_112 ( V_14 , V_6 ) ;
F_101 ( & V_14 -> V_122 ) ;
return V_29 ;
}
static int F_189 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_144 ( V_3 ) ;
int V_29 ;
F_100 ( & V_14 -> V_122 ) ;
V_29 = F_125 ( V_14 , V_6 ) ;
F_101 ( & V_14 -> V_122 ) ;
return V_29 ;
}
static T_9 F_190 ( struct V_2 * V_3 ,
T_9 V_134 )
{
struct V_1 * V_4 ;
struct V_14 * V_14 = F_144 ( V_3 ) ;
T_9 V_192 ;
V_192 = V_134 ;
V_134 &= ~ V_193 ;
V_134 |= V_194 ;
F_164 () ;
F_77 (port, &team->port_list, list) {
V_134 = F_97 ( V_134 ,
V_4 -> V_3 -> V_134 ,
V_192 ) ;
}
F_167 () ;
return V_134 ;
}
static void F_191 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
V_3 -> V_195 = V_6 -> V_195 ;
V_3 -> type = V_6 -> type ;
V_3 -> V_121 = V_6 -> V_121 ;
V_3 -> V_11 = V_6 -> V_11 ;
V_3 -> V_139 = V_6 -> V_139 ;
memcpy ( V_3 -> V_196 , V_6 -> V_196 , V_6 -> V_11 ) ;
memcpy ( V_3 -> V_7 , V_6 -> V_7 , V_6 -> V_11 ) ;
V_3 -> V_181 &= ~ V_182 ;
}
static int F_114 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
struct V_14 * V_14 = F_144 ( V_3 ) ;
char * V_132 = V_6 -> V_22 ;
int V_29 ;
if ( V_3 -> type == V_6 -> type )
return 0 ;
if ( ! F_62 ( & V_14 -> V_78 ) ) {
F_63 ( V_3 , L_27 , V_132 ) ;
return - V_79 ;
}
V_29 = F_192 ( V_197 , V_3 ) ;
V_29 = F_193 ( V_29 ) ;
if ( V_29 ) {
F_63 ( V_3 , L_28 ) ;
return V_29 ;
}
F_194 ( V_3 ) ;
F_195 ( V_3 ) ;
F_191 ( V_3 , V_6 ) ;
F_192 ( V_198 , V_3 ) ;
return 0 ;
}
static void F_196 ( struct V_2 * V_3 )
{
F_197 ( V_3 ) ;
V_3 -> V_199 = & V_200 ;
V_3 -> V_201 = F_152 ;
V_3 -> V_202 = 0 ;
V_3 -> V_117 |= V_203 ;
V_3 -> V_120 &= ~ ( V_119 | V_204 ) ;
V_3 -> V_120 |= V_205 | V_206 ;
V_3 -> V_134 |= V_207 ;
V_3 -> V_134 |= V_208 ;
V_3 -> V_209 = V_114 |
V_210 |
V_211 |
V_212 ;
V_3 -> V_209 &= ~ ( V_213 & ~ V_214 ) ;
V_3 -> V_134 |= V_3 -> V_209 ;
}
static int F_198 ( struct V_215 * V_216 , struct V_2 * V_3 ,
struct V_217 * V_218 [] , struct V_217 * V_148 [] )
{
int V_29 ;
if ( V_218 [ V_219 ] == NULL )
F_199 ( V_3 ) ;
V_29 = F_200 ( V_3 ) ;
if ( V_29 )
return V_29 ;
return 0 ;
}
static int F_201 ( struct V_217 * V_218 [] , struct V_217 * V_148 [] )
{
if ( V_218 [ V_219 ] ) {
if ( F_202 ( V_218 [ V_219 ] ) != V_220 )
return - V_62 ;
if ( ! F_172 ( F_203 ( V_218 [ V_219 ] ) ) )
return - V_180 ;
}
return 0 ;
}
static unsigned int F_204 ( void )
{
return V_221 ;
}
static unsigned int F_205 ( void )
{
return V_222 ;
}
static int F_206 ( struct V_67 * V_68 , struct V_223 * V_32 )
{
struct V_67 * V_224 ;
void * V_225 ;
int V_29 ;
V_224 = F_207 ( V_226 , V_30 ) ;
if ( ! V_224 )
return - V_31 ;
V_225 = F_208 ( V_224 , V_32 -> V_227 , V_32 -> V_228 ,
& V_229 , 0 , V_230 ) ;
if ( ! V_225 ) {
V_29 = - V_231 ;
goto V_232;
}
F_209 ( V_224 , V_225 ) ;
return F_210 ( F_211 ( V_32 ) , V_224 , V_32 -> V_227 ) ;
V_232:
F_212 ( V_224 ) ;
return V_29 ;
}
static struct V_14 * F_213 ( struct V_223 * V_32 )
{
struct V_215 * V_215 = F_211 ( V_32 ) ;
int V_233 ;
struct V_2 * V_3 ;
struct V_14 * V_14 ;
if ( ! V_32 -> V_234 [ V_235 ] )
return NULL ;
V_233 = F_214 ( V_32 -> V_234 [ V_235 ] ) ;
V_3 = F_215 ( V_215 , V_233 ) ;
if ( ! V_3 || V_3 -> V_199 != & V_200 ) {
if ( V_3 )
F_104 ( V_3 ) ;
return NULL ;
}
V_14 = F_144 ( V_3 ) ;
F_100 ( & V_14 -> V_122 ) ;
return V_14 ;
}
static void F_216 ( struct V_14 * V_14 )
{
F_101 ( & V_14 -> V_122 ) ;
F_104 ( V_14 -> V_3 ) ;
}
static int F_217 ( struct V_223 * V_32 , struct V_14 * V_14 ,
int (* F_218)( struct V_67 * V_68 ,
struct V_223 * V_32 ,
int V_117 , struct V_14 * V_14 ) )
{
struct V_67 * V_68 ;
int V_29 ;
V_68 = F_207 ( V_226 , V_30 ) ;
if ( ! V_68 )
return - V_31 ;
V_29 = F_218 ( V_68 , V_32 , V_236 , V_14 ) ;
if ( V_29 < 0 )
goto V_237;
V_29 = F_210 ( F_211 ( V_32 ) , V_68 , V_32 -> V_227 ) ;
return V_29 ;
V_237:
F_212 ( V_68 ) ;
return V_29 ;
}
static int F_219 ( struct V_67 * V_68 , struct V_14 * V_14 , T_4 V_238 )
{
return F_210 ( F_220 ( V_14 -> V_3 ) , V_68 , V_238 ) ;
}
static int F_221 ( struct V_67 * V_68 , struct V_14 * V_14 ,
struct V_23 * V_24 )
{
struct V_217 * V_239 ;
struct V_19 * V_21 = V_24 -> V_21 ;
struct V_53 * V_54 = & V_24 -> V_32 ;
struct V_48 V_49 ;
int V_29 ;
V_49 . V_32 = V_54 ;
V_29 = F_34 ( V_14 , V_24 , & V_49 ) ;
if ( V_29 )
return V_29 ;
V_239 = F_222 ( V_68 , V_240 ) ;
if ( ! V_239 )
return - V_231 ;
if ( F_223 ( V_68 , V_241 , V_21 -> V_22 ) )
goto V_242;
if ( V_54 -> V_4 &&
F_224 ( V_68 , V_243 ,
V_54 -> V_4 -> V_3 -> V_233 ) )
goto V_242;
if ( V_24 -> V_21 -> V_27 &&
F_224 ( V_68 , V_244 ,
V_54 -> V_33 ) )
goto V_242;
switch ( V_21 -> type ) {
case V_245 :
if ( F_225 ( V_68 , V_246 , V_247 ) )
goto V_242;
if ( F_224 ( V_68 , V_248 , V_49 . V_148 . V_152 ) )
goto V_242;
break;
case V_249 :
if ( F_225 ( V_68 , V_246 , V_250 ) )
goto V_242;
if ( F_223 ( V_68 , V_248 ,
V_49 . V_148 . V_149 ) )
goto V_242;
break;
case V_251 :
if ( F_225 ( V_68 , V_246 , V_252 ) )
goto V_242;
if ( F_226 ( V_68 , V_248 , V_49 . V_148 . V_253 . V_90 ,
V_49 . V_148 . V_253 . V_254 ) )
goto V_242;
break;
case V_255 :
if ( F_225 ( V_68 , V_246 , V_256 ) )
goto V_242;
if ( V_49 . V_148 . V_150 &&
F_227 ( V_68 , V_248 ) )
goto V_242;
break;
case V_257 :
if ( F_225 ( V_68 , V_246 , V_258 ) )
goto V_242;
if ( F_228 ( V_68 , V_248 , V_49 . V_148 . V_151 ) )
goto V_242;
break;
default:
F_229 () ;
}
if ( V_24 -> V_35 && F_227 ( V_68 , V_259 ) )
goto V_242;
if ( V_24 -> V_34 ) {
if ( F_227 ( V_68 , V_260 ) )
goto V_242;
V_24 -> V_34 = false ;
}
F_230 ( V_68 , V_239 ) ;
return 0 ;
V_242:
F_231 ( V_68 , V_239 ) ;
return - V_231 ;
}
static int F_232 ( struct V_67 * * V_80 ,
struct V_14 * V_14 , T_4 V_238 ,
T_10 * V_261 )
{
int V_29 ;
if ( * V_80 ) {
V_29 = V_261 ( * V_80 , V_14 , V_238 ) ;
if ( V_29 )
return V_29 ;
}
* V_80 = F_233 ( V_262 , V_30 ) ;
if ( ! * V_80 )
return - V_31 ;
return 0 ;
}
static int F_234 ( struct V_14 * V_14 , T_4 V_238 , T_4 V_263 ,
int V_117 , T_10 * V_261 ,
struct V_95 * V_264 )
{
struct V_217 * V_46 ;
struct V_265 * V_266 ;
void * V_225 ;
struct V_23 * V_24 ;
int V_29 ;
struct V_67 * V_68 = NULL ;
bool V_267 ;
int V_28 ;
V_24 = F_235 ( V_264 ,
struct V_23 , V_268 ) ;
V_269:
V_29 = F_232 ( & V_68 , V_14 , V_238 , V_261 ) ;
if ( V_29 )
return V_29 ;
V_225 = F_208 ( V_68 , V_238 , V_263 , & V_229 , V_117 | V_270 ,
V_271 ) ;
if ( ! V_225 )
return - V_231 ;
if ( F_224 ( V_68 , V_235 , V_14 -> V_3 -> V_233 ) )
goto V_272;
V_46 = F_222 ( V_68 , V_273 ) ;
if ( ! V_46 )
goto V_272;
V_28 = 0 ;
V_267 = false ;
F_236 (opt_inst, sel_opt_inst_list, tmp_list) {
V_29 = F_221 ( V_68 , V_14 , V_24 ) ;
if ( V_29 ) {
if ( V_29 == - V_231 ) {
if ( ! V_28 )
goto V_274;
V_267 = true ;
break;
}
goto V_274;
}
V_28 ++ ;
}
F_230 ( V_68 , V_46 ) ;
F_209 ( V_68 , V_225 ) ;
if ( V_267 )
goto V_269;
V_275:
V_266 = F_237 ( V_68 , V_238 , V_263 , V_276 , 0 , V_117 | V_270 ) ;
if ( ! V_266 ) {
V_29 = F_232 ( & V_68 , V_14 , V_238 , V_261 ) ;
if ( V_29 )
goto V_274;
goto V_275;
}
return V_261 ( V_68 , V_14 , V_238 ) ;
V_272:
V_29 = - V_231 ;
V_274:
F_238 ( V_68 , V_225 ) ;
F_212 ( V_68 ) ;
return V_29 ;
}
static int F_239 ( struct V_67 * V_68 , struct V_223 * V_32 )
{
struct V_14 * V_14 ;
struct V_23 * V_24 ;
int V_29 ;
F_240 ( V_264 ) ;
V_14 = F_213 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
F_12 (opt_inst, &team->option_inst_list, list)
F_20 ( & V_24 -> V_268 , & V_264 ) ;
V_29 = F_234 ( V_14 , V_32 -> V_227 , V_32 -> V_228 ,
V_236 , F_219 ,
& V_264 ) ;
F_216 ( V_14 ) ;
return V_29 ;
}
static int F_241 ( struct V_67 * V_68 , struct V_223 * V_32 )
{
struct V_14 * V_14 ;
int V_29 = 0 ;
int V_28 ;
struct V_217 * V_277 ;
F_240 ( V_278 ) ;
V_14 = F_213 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
V_29 = - V_62 ;
if ( ! V_32 -> V_234 [ V_273 ] ) {
V_29 = - V_62 ;
goto V_279;
}
F_242 (nl_option, info->attrs[TEAM_ATTR_LIST_OPTION], i) {
struct V_217 * V_280 [ V_281 + 1 ] ;
struct V_217 * V_282 ;
struct V_217 * V_283 ;
enum V_284 V_285 ;
int V_286 = 0 ;
T_4 V_287 = 0 ;
bool V_288 = false ;
struct V_23 * V_24 ;
char * V_20 ;
bool V_289 = false ;
if ( F_243 ( V_277 ) != V_240 ) {
V_29 = - V_62 ;
goto V_279;
}
V_29 = F_244 ( V_280 , V_281 ,
V_277 , V_290 ) ;
if ( V_29 )
goto V_279;
if ( ! V_280 [ V_241 ] ||
! V_280 [ V_246 ] ) {
V_29 = - V_62 ;
goto V_279;
}
switch ( F_245 ( V_280 [ V_246 ] ) ) {
case V_247 :
V_285 = V_245 ;
break;
case V_250 :
V_285 = V_249 ;
break;
case V_252 :
V_285 = V_251 ;
break;
case V_256 :
V_285 = V_255 ;
break;
case V_258 :
V_285 = V_257 ;
break;
default:
goto V_279;
}
V_283 = V_280 [ V_248 ] ;
if ( V_285 != V_255 && ! V_283 ) {
V_29 = - V_62 ;
goto V_279;
}
V_20 = F_203 ( V_280 [ V_241 ] ) ;
V_282 = V_280 [ V_243 ] ;
if ( V_282 )
V_286 = F_214 ( V_282 ) ;
V_282 = V_280 [ V_244 ] ;
if ( V_282 ) {
V_288 = true ;
V_287 = F_214 ( V_282 ) ;
}
F_12 (opt_inst, &team->option_inst_list, list) {
struct V_19 * V_21 = V_24 -> V_21 ;
struct V_48 V_49 ;
struct V_53 * V_54 ;
int V_291 ;
V_54 = & V_24 -> V_32 ;
V_291 = V_54 -> V_4 ?
V_54 -> V_4 -> V_3 -> V_233 : 0 ;
if ( V_21 -> type != V_285 ||
strcmp ( V_21 -> V_22 , V_20 ) ||
V_291 != V_286 ||
( V_21 -> V_27 && ! V_288 ) ||
V_54 -> V_33 != V_287 )
continue;
V_289 = true ;
V_49 . V_32 = V_54 ;
switch ( V_285 ) {
case V_245 :
V_49 . V_148 . V_152 = F_214 ( V_283 ) ;
break;
case V_249 :
if ( F_202 ( V_283 ) > V_292 ) {
V_29 = - V_62 ;
goto V_279;
}
V_49 . V_148 . V_149 = F_203 ( V_283 ) ;
break;
case V_251 :
V_49 . V_148 . V_253 . V_90 = F_202 ( V_283 ) ;
V_49 . V_148 . V_253 . V_254 = F_203 ( V_283 ) ;
break;
case V_255 :
V_49 . V_148 . V_150 = V_283 ? true : false ;
break;
case V_257 :
V_49 . V_148 . V_151 = F_246 ( V_283 ) ;
break;
default:
F_229 () ;
}
V_29 = F_35 ( V_14 , V_24 , & V_49 ) ;
if ( V_29 )
goto V_279;
V_24 -> V_34 = true ;
F_247 ( & V_24 -> V_268 , & V_278 ) ;
}
if ( ! V_289 ) {
V_29 = - V_147 ;
goto V_279;
}
}
V_29 = F_248 ( V_14 , & V_278 ) ;
V_279:
F_216 ( V_14 ) ;
return V_29 ;
}
static int F_249 ( struct V_67 * V_68 ,
T_4 V_238 , T_4 V_263 , int V_117 ,
struct V_14 * V_14 ,
bool V_293 )
{
struct V_217 * V_78 ;
void * V_225 ;
struct V_1 * V_4 ;
V_225 = F_208 ( V_68 , V_238 , V_263 , & V_229 , V_117 ,
V_294 ) ;
if ( ! V_225 )
return - V_231 ;
if ( F_224 ( V_68 , V_235 , V_14 -> V_3 -> V_233 ) )
goto V_272;
V_78 = F_222 ( V_68 , V_295 ) ;
if ( ! V_78 )
goto V_272;
F_12 (port, &team->port_list, list) {
struct V_217 * V_296 ;
if ( ! V_293 && ! V_4 -> V_34 )
continue;
V_296 = F_222 ( V_68 , V_297 ) ;
if ( ! V_296 )
goto V_272;
if ( F_224 ( V_68 , V_298 , V_4 -> V_3 -> V_233 ) )
goto V_272;
if ( V_4 -> V_34 ) {
if ( F_227 ( V_68 , V_299 ) )
goto V_272;
V_4 -> V_34 = false ;
}
if ( ( V_4 -> V_35 &&
F_227 ( V_68 , V_300 ) ) ||
( V_4 -> V_18 . V_15 &&
F_227 ( V_68 , V_301 ) ) ||
F_224 ( V_68 , V_302 , V_4 -> V_18 . V_303 ) ||
F_225 ( V_68 , V_304 , V_4 -> V_18 . V_305 ) )
goto V_272;
F_230 ( V_68 , V_296 ) ;
}
F_230 ( V_68 , V_78 ) ;
return F_209 ( V_68 , V_225 ) ;
V_272:
F_238 ( V_68 , V_225 ) ;
return - V_231 ;
}
static int F_250 ( struct V_67 * V_68 ,
struct V_223 * V_32 , int V_117 ,
struct V_14 * V_14 )
{
return F_249 ( V_68 , V_32 -> V_227 ,
V_32 -> V_228 , V_236 ,
V_14 , true ) ;
}
static int F_251 ( struct V_67 * V_68 ,
struct V_223 * V_32 )
{
struct V_14 * V_14 ;
int V_29 ;
V_14 = F_213 ( V_32 ) ;
if ( ! V_14 )
return - V_62 ;
V_29 = F_217 ( V_32 , V_14 , F_250 ) ;
F_216 ( V_14 ) ;
return V_29 ;
}
static int F_252 ( struct V_67 * V_68 ,
struct V_14 * V_14 , T_4 V_238 )
{
return F_253 ( F_220 ( V_14 -> V_3 ) , V_68 , 0 ,
V_306 . V_307 , V_30 ) ;
}
static int F_248 ( struct V_14 * V_14 ,
struct V_95 * V_264 )
{
return F_234 ( V_14 , 0 , 0 , 0 , F_252 ,
V_264 ) ;
}
static int F_254 ( struct V_14 * V_14 )
{
struct V_67 * V_68 ;
int V_29 ;
struct V_215 * V_215 = F_220 ( V_14 -> V_3 ) ;
V_68 = F_207 ( V_226 , V_30 ) ;
if ( ! V_68 )
return - V_31 ;
V_29 = F_249 ( V_68 , 0 , 0 , 0 , V_14 , false ) ;
if ( V_29 < 0 )
goto V_237;
V_29 = F_253 ( V_215 , V_68 , 0 , V_306 . V_307 ,
V_30 ) ;
return V_29 ;
V_237:
F_212 ( V_68 ) ;
return V_29 ;
}
static int F_255 ( void )
{
int V_29 ;
V_29 = F_256 ( & V_229 , V_308 ,
F_148 ( V_308 ) ) ;
if ( V_29 )
return V_29 ;
V_29 = F_257 ( & V_229 , & V_306 ) ;
if ( V_29 )
goto V_309;
return 0 ;
V_309:
F_258 ( & V_229 ) ;
return V_29 ;
}
static void F_259 ( void )
{
F_258 ( & V_229 ) ;
}
static void F_32 ( struct V_14 * V_14 )
{
int V_29 ;
struct V_23 * V_24 ;
F_240 ( V_264 ) ;
F_12 (opt_inst, &team->option_inst_list, list) {
if ( V_24 -> V_34 )
F_20 ( & V_24 -> V_268 , & V_264 ) ;
}
V_29 = F_248 ( V_14 , & V_264 ) ;
if ( V_29 && V_29 != - V_310 )
F_260 ( V_14 -> V_3 , L_29 ,
V_29 ) ;
}
static void F_261 ( struct V_1 * V_4 , bool V_15 )
{
int V_29 ;
V_4 -> V_34 = true ;
V_4 -> V_18 . V_15 = V_15 ;
F_10 ( V_4 ) ;
if ( V_15 ) {
struct V_311 V_312 ;
V_29 = F_262 ( V_4 -> V_3 , & V_312 ) ;
if ( ! V_29 ) {
V_4 -> V_18 . V_303 = F_263 ( & V_312 ) ;
V_4 -> V_18 . V_305 = V_312 . V_305 ;
goto V_313;
}
}
V_4 -> V_18 . V_303 = 0 ;
V_4 -> V_18 . V_305 = 0 ;
V_313:
V_29 = F_254 ( V_4 -> V_14 ) ;
if ( V_29 && V_29 != - V_310 )
F_260 ( V_4 -> V_14 -> V_3 , L_30 ,
V_4 -> V_3 -> V_22 , V_29 ) ;
}
static void F_264 ( struct V_1 * V_4 , bool V_15 )
{
if ( V_4 -> V_18 . V_15 != V_15 )
F_261 ( V_4 , V_15 ) ;
}
static void F_120 ( struct V_1 * V_4 , bool V_15 )
{
F_261 ( V_4 , V_15 ) ;
}
static void F_126 ( struct V_1 * V_4 )
{
V_4 -> V_35 = true ;
F_261 ( V_4 , false ) ;
}
static void F_265 ( struct V_1 * V_4 , bool V_15 )
{
struct V_14 * V_14 = V_4 -> V_14 ;
F_100 ( & V_14 -> V_122 ) ;
F_264 ( V_4 , V_15 ) ;
F_101 ( & V_14 -> V_122 ) ;
}
static int F_266 ( struct V_314 * V_156 ,
unsigned long V_315 , void * V_254 )
{
struct V_2 * V_3 = (struct V_2 * ) V_254 ;
struct V_1 * V_4 ;
V_4 = F_4 ( V_3 ) ;
if ( ! V_4 )
return V_316 ;
switch ( V_315 ) {
case V_317 :
if ( F_121 ( V_3 ) )
F_265 ( V_4 , true ) ;
case V_318 :
F_265 ( V_4 , false ) ;
case V_319 :
if ( F_267 ( V_4 -> V_3 ) )
F_265 ( V_4 ,
! ! F_121 ( V_4 -> V_3 ) ) ;
break;
case V_320 :
F_189 ( V_4 -> V_14 -> V_3 , V_3 ) ;
break;
case V_321 :
F_99 ( V_4 -> V_14 ) ;
break;
case V_322 :
return V_323 ;
case V_197 :
return V_323 ;
}
return V_316 ;
}
static int T_11 F_268 ( void )
{
int V_29 ;
F_269 ( & V_324 ) ;
V_29 = F_270 ( & V_325 ) ;
if ( V_29 )
goto V_326;
V_29 = F_255 () ;
if ( V_29 )
goto V_327;
return 0 ;
V_327:
F_271 ( & V_325 ) ;
V_326:
F_272 ( & V_324 ) ;
return V_29 ;
}
static void T_12 F_273 ( void )
{
F_259 () ;
F_271 ( & V_325 ) ;
F_272 ( & V_324 ) ;
}
