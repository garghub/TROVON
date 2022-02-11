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
struct V_15 V_16 ;
V_16 . V_17 = V_5 -> V_18 ;
V_16 . V_19 = F_13 ( V_5 ) ;
F_14 ( V_5 -> V_3 , & V_16 ) ;
}
static void F_15 ( struct V_1 * V_5 )
{
bool V_20 = V_5 -> V_21 . V_22 ? V_5 -> V_21 . V_18 :
V_5 -> V_23 . V_18 ;
if ( V_5 -> V_18 != V_20 ) {
V_5 -> V_18 = V_20 ;
F_12 ( V_5 ) ;
}
}
static struct V_24 * F_16 ( struct V_14 * V_14 ,
const char * V_25 )
{
struct V_24 * V_26 ;
F_17 (option, &team->option_list, list) {
if ( strcmp ( V_26 -> V_27 , V_25 ) == 0 )
return V_26 ;
}
return NULL ;
}
static void F_18 ( struct V_28 * V_29 )
{
F_19 ( & V_29 -> V_30 ) ;
F_20 ( V_29 ) ;
}
static void F_21 ( struct V_14 * V_14 ,
struct V_24 * V_26 )
{
struct V_28 * V_29 , * V_31 ;
F_22 (opt_inst, tmp, &team->option_inst_list, list) {
if ( V_29 -> V_26 == V_26 )
F_18 ( V_29 ) ;
}
}
static int F_23 ( struct V_14 * V_14 , struct V_24 * V_26 ,
struct V_1 * V_5 )
{
struct V_28 * V_29 ;
unsigned int V_32 ;
unsigned int V_33 ;
int V_34 ;
V_32 = V_26 -> V_32 ;
if ( ! V_32 )
V_32 = 1 ;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ ) {
V_29 = F_24 ( sizeof( * V_29 ) , V_35 ) ;
if ( ! V_29 )
return - V_36 ;
V_29 -> V_26 = V_26 ;
V_29 -> V_16 . V_5 = V_5 ;
V_29 -> V_16 . V_37 = V_33 ;
V_29 -> V_38 = true ;
V_29 -> V_39 = false ;
F_25 ( & V_29 -> V_30 , & V_14 -> V_40 ) ;
if ( V_26 -> V_41 ) {
V_34 = V_26 -> V_41 ( V_14 , & V_29 -> V_16 ) ;
if ( V_34 )
return V_34 ;
}
}
return 0 ;
}
static int F_26 ( struct V_14 * V_14 ,
struct V_24 * V_26 )
{
int V_34 ;
if ( ! V_26 -> V_42 ) {
V_34 = F_23 ( V_14 , V_26 , NULL ) ;
if ( V_34 )
goto V_43;
}
return 0 ;
V_43:
F_21 ( V_14 , V_26 ) ;
return V_34 ;
}
static void F_27 ( struct V_14 * V_14 ,
struct V_24 * V_26 )
{
struct V_28 * V_29 ;
F_17 (opt_inst, &team->option_inst_list, list) {
if ( V_29 -> V_26 == V_26 ) {
V_29 -> V_38 = true ;
V_29 -> V_39 = true ;
}
}
}
static void F_28 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
struct V_28 * V_29 , * V_31 ;
F_22 (opt_inst, tmp, &team->option_inst_list, list) {
if ( V_29 -> V_26 -> V_42 &&
V_29 -> V_16 . V_5 == V_5 )
F_18 ( V_29 ) ;
}
}
static int F_29 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
struct V_24 * V_26 ;
int V_34 ;
F_17 (option, &team->option_list, list) {
if ( ! V_26 -> V_42 )
continue;
V_34 = F_23 ( V_14 , V_26 , V_5 ) ;
if ( V_34 )
goto V_44;
}
return 0 ;
V_44:
F_28 ( V_14 , V_5 ) ;
return V_34 ;
}
static void F_30 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
struct V_28 * V_29 ;
F_17 (opt_inst, &team->option_inst_list, list) {
if ( V_29 -> V_16 . V_5 == V_5 ) {
V_29 -> V_38 = true ;
V_29 -> V_39 = true ;
}
}
}
static int F_31 ( struct V_14 * V_14 ,
const struct V_24 * V_26 ,
T_1 V_45 )
{
int V_33 ;
struct V_24 * * V_46 ;
int V_34 ;
V_46 = F_32 ( sizeof( struct V_24 * ) * V_45 ,
V_35 ) ;
if ( ! V_46 )
return - V_36 ;
for ( V_33 = 0 ; V_33 < V_45 ; V_33 ++ , V_26 ++ ) {
if ( F_16 ( V_14 , V_26 -> V_27 ) ) {
V_34 = - V_47 ;
goto V_48;
}
V_46 [ V_33 ] = F_33 ( V_26 , sizeof( * V_26 ) , V_35 ) ;
if ( ! V_46 [ V_33 ] ) {
V_34 = - V_36 ;
goto V_48;
}
}
for ( V_33 = 0 ; V_33 < V_45 ; V_33 ++ ) {
V_34 = F_26 ( V_14 , V_46 [ V_33 ] ) ;
if ( V_34 )
goto V_49;
F_25 ( & V_46 [ V_33 ] -> V_30 , & V_14 -> V_50 ) ;
}
F_20 ( V_46 ) ;
return 0 ;
V_49:
for ( V_33 -- ; V_33 >= 0 ; V_33 -- )
F_21 ( V_14 , V_46 [ V_33 ] ) ;
V_33 = V_45 - 1 ;
V_48:
for ( V_33 -- ; V_33 >= 0 ; V_33 -- )
F_20 ( V_46 [ V_33 ] ) ;
F_20 ( V_46 ) ;
return V_34 ;
}
static void F_34 ( struct V_14 * V_14 ,
const struct V_24 * V_26 ,
T_1 V_45 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_45 ; V_33 ++ , V_26 ++ ) {
struct V_24 * V_51 ;
V_51 = F_16 ( V_14 , V_26 -> V_27 ) ;
if ( V_51 )
F_27 ( V_14 , V_51 ) ;
}
}
static void F_35 ( struct V_14 * V_14 ,
const struct V_24 * V_26 ,
T_1 V_45 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_45 ; V_33 ++ , V_26 ++ ) {
struct V_24 * V_51 ;
V_51 = F_16 ( V_14 , V_26 -> V_27 ) ;
if ( V_51 ) {
F_21 ( V_14 , V_51 ) ;
F_19 ( & V_51 -> V_30 ) ;
F_20 ( V_51 ) ;
}
}
}
int F_36 ( struct V_14 * V_14 ,
const struct V_24 * V_26 ,
T_1 V_45 )
{
int V_34 ;
V_34 = F_31 ( V_14 , V_26 , V_45 ) ;
if ( V_34 )
return V_34 ;
F_37 ( V_14 ) ;
return 0 ;
}
void F_38 ( struct V_14 * V_14 ,
const struct V_24 * V_26 ,
T_1 V_45 )
{
F_34 ( V_14 , V_26 , V_45 ) ;
F_37 ( V_14 ) ;
F_35 ( V_14 , V_26 , V_45 ) ;
}
static int F_39 ( struct V_14 * V_14 ,
struct V_28 * V_29 ,
struct V_52 * V_53 )
{
if ( ! V_29 -> V_26 -> V_54 )
return - V_55 ;
return V_29 -> V_26 -> V_54 ( V_14 , V_53 ) ;
}
static int F_40 ( struct V_14 * V_14 ,
struct V_28 * V_29 ,
struct V_52 * V_53 )
{
if ( ! V_29 -> V_26 -> V_56 )
return - V_55 ;
return V_29 -> V_26 -> V_56 ( V_14 , V_53 ) ;
}
void F_41 ( struct V_57 * V_58 )
{
struct V_28 * V_29 ;
V_29 = F_42 ( V_58 , struct V_28 , V_16 ) ;
V_29 -> V_38 = true ;
}
void F_43 ( struct V_14 * V_14 )
{
F_37 ( V_14 ) ;
}
static struct V_59 * F_44 ( const char * V_60 )
{
struct V_59 * V_61 ;
F_17 (mitem, &mode_list, list) {
if ( strcmp ( V_61 -> V_62 -> V_60 , V_60 ) == 0 )
return V_61 ;
}
return NULL ;
}
static bool F_45 ( const char * V_27 )
{
while ( * V_27 != '\0' ) {
if ( ! isalpha ( * V_27 ) && ! isdigit ( * V_27 ) && * V_27 != '_' )
return false ;
V_27 ++ ;
}
return true ;
}
int F_46 ( const struct V_63 * V_62 )
{
int V_34 = 0 ;
struct V_59 * V_61 ;
if ( ! F_45 ( V_62 -> V_60 ) ||
V_62 -> V_64 > V_65 )
return - V_66 ;
V_61 = F_24 ( sizeof( * V_61 ) , V_35 ) ;
if ( ! V_61 )
return - V_36 ;
F_47 ( & V_67 ) ;
if ( F_44 ( V_62 -> V_60 ) ) {
V_34 = - V_47 ;
F_20 ( V_61 ) ;
goto V_68;
}
V_61 -> V_62 = V_62 ;
F_25 ( & V_61 -> V_30 , & V_69 ) ;
V_68:
F_48 ( & V_67 ) ;
return V_34 ;
}
void F_49 ( const struct V_63 * V_62 )
{
struct V_59 * V_61 ;
F_47 ( & V_67 ) ;
V_61 = F_44 ( V_62 -> V_60 ) ;
if ( V_61 ) {
F_50 ( & V_61 -> V_30 ) ;
F_20 ( V_61 ) ;
}
F_48 ( & V_67 ) ;
}
static const struct V_63 * F_51 ( const char * V_60 )
{
struct V_59 * V_61 ;
const struct V_63 * V_62 = NULL ;
F_47 ( & V_67 ) ;
V_61 = F_44 ( V_60 ) ;
if ( ! V_61 ) {
F_48 ( & V_67 ) ;
F_52 ( L_1 , V_60 ) ;
F_47 ( & V_67 ) ;
V_61 = F_44 ( V_60 ) ;
}
if ( V_61 ) {
V_62 = V_61 -> V_62 ;
if ( ! F_53 ( V_62 -> V_70 ) )
V_62 = NULL ;
}
F_48 ( & V_67 ) ;
return V_62 ;
}
static void F_54 ( const struct V_63 * V_62 )
{
F_55 ( V_62 -> V_70 ) ;
}
static bool F_56 ( struct V_14 * V_14 , struct V_71 * V_72 )
{
F_57 ( V_72 ) ;
return false ;
}
static T_2 F_58 ( struct V_14 * V_14 ,
struct V_1 * V_5 ,
struct V_71 * V_72 )
{
return V_73 ;
}
static bool F_59 ( struct V_14 * V_14 )
{
return V_14 -> V_62 != & V_74 ;
}
static void F_60 ( struct V_14 * V_14 )
{
V_14 -> V_75 = false ;
V_14 -> V_62 = & V_74 ;
}
static void F_61 ( struct V_14 * V_14 )
{
if ( ! V_14 -> V_76 || ! F_59 ( V_14 ) ||
! V_14 -> V_62 -> V_77 -> V_78 )
V_14 -> V_77 . V_78 = F_56 ;
else
V_14 -> V_77 . V_78 = V_14 -> V_62 -> V_77 -> V_78 ;
if ( ! V_14 -> V_76 || ! F_59 ( V_14 ) ||
! V_14 -> V_62 -> V_77 -> V_79 )
V_14 -> V_77 . V_79 = F_58 ;
else
V_14 -> V_77 . V_79 = V_14 -> V_62 -> V_77 -> V_79 ;
}
static int F_62 ( struct V_14 * V_14 ,
const struct V_63 * V_80 )
{
if ( F_59 ( V_14 ) ) {
void (* F_63)( struct V_14 * V_14 ) = V_14 -> V_77 . exit ;
memset ( & V_14 -> V_77 , 0 , sizeof( struct V_81 ) ) ;
F_61 ( V_14 ) ;
if ( F_63 )
F_63 ( V_14 ) ;
F_54 ( V_14 -> V_62 ) ;
F_60 ( V_14 ) ;
memset ( & V_14 -> V_82 , 0 ,
sizeof( struct V_14 ) - F_64 ( struct V_14 , V_82 ) ) ;
}
if ( ! V_80 )
return 0 ;
if ( V_80 -> V_77 -> V_41 ) {
int V_34 ;
V_34 = V_80 -> V_77 -> V_41 ( V_14 ) ;
if ( V_34 )
return V_34 ;
}
V_14 -> V_62 = V_80 ;
memcpy ( & V_14 -> V_77 , V_80 -> V_77 , sizeof( struct V_81 ) ) ;
F_61 ( V_14 ) ;
return 0 ;
}
static int F_65 ( struct V_14 * V_14 , const char * V_60 )
{
const struct V_63 * V_80 ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_34 ;
if ( ! F_66 ( & V_14 -> V_83 ) ) {
F_67 ( V_3 , L_2 ) ;
return - V_84 ;
}
if ( F_59 ( V_14 ) && strcmp ( V_14 -> V_62 -> V_60 , V_60 ) == 0 ) {
F_67 ( V_3 , L_3 ) ;
return - V_66 ;
}
V_80 = F_51 ( V_60 ) ;
if ( ! V_80 ) {
F_67 ( V_3 , L_4 , V_60 ) ;
return - V_66 ;
}
V_34 = F_62 ( V_14 , V_80 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_5 , V_60 ) ;
F_54 ( V_80 ) ;
return V_34 ;
}
F_68 ( V_3 , L_6 , V_60 ) ;
return 0 ;
}
static void F_69 ( struct V_85 * V_86 )
{
struct V_14 * V_14 ;
int V_87 ;
V_14 = F_42 ( V_86 , struct V_14 , V_88 . V_89 . V_86 ) ;
if ( ! F_70 () ) {
F_71 ( & V_14 -> V_88 . V_89 , 0 ) ;
return;
}
V_87 = F_72 ( & V_14 -> V_88 . V_90 ) ;
if ( V_87 < 0 ) {
F_73 () ;
return;
}
F_74 ( V_91 , V_14 -> V_3 ) ;
F_73 () ;
if ( V_87 )
F_71 ( & V_14 -> V_88 . V_89 ,
F_75 ( V_14 -> V_88 . V_92 ) ) ;
}
static void F_76 ( struct V_14 * V_14 )
{
if ( ! V_14 -> V_88 . V_93 || ! F_77 ( V_14 -> V_3 ) )
return;
F_78 ( V_14 -> V_88 . V_93 , & V_14 -> V_88 . V_90 ) ;
F_71 ( & V_14 -> V_88 . V_89 , 0 ) ;
}
static void F_79 ( struct V_14 * V_14 )
{
F_80 ( & V_14 -> V_88 . V_89 , F_69 ) ;
}
static void F_81 ( struct V_14 * V_14 )
{
F_82 ( & V_14 -> V_88 . V_89 ) ;
}
static void F_83 ( struct V_85 * V_86 )
{
struct V_14 * V_14 ;
int V_87 ;
V_14 = F_42 ( V_86 , struct V_14 , V_94 . V_89 . V_86 ) ;
if ( ! F_70 () ) {
F_71 ( & V_14 -> V_94 . V_89 , 0 ) ;
return;
}
V_87 = F_72 ( & V_14 -> V_94 . V_90 ) ;
if ( V_87 < 0 ) {
F_73 () ;
return;
}
F_74 ( V_95 , V_14 -> V_3 ) ;
F_73 () ;
if ( V_87 )
F_71 ( & V_14 -> V_94 . V_89 ,
F_75 ( V_14 -> V_94 . V_92 ) ) ;
}
static void F_84 ( struct V_14 * V_14 )
{
if ( ! V_14 -> V_94 . V_93 || ! F_77 ( V_14 -> V_3 ) )
return;
F_78 ( V_14 -> V_94 . V_93 , & V_14 -> V_94 . V_90 ) ;
F_71 ( & V_14 -> V_94 . V_89 , 0 ) ;
}
static void F_85 ( struct V_14 * V_14 )
{
F_80 ( & V_14 -> V_94 . V_89 , F_83 ) ;
}
static void F_86 ( struct V_14 * V_14 )
{
F_82 ( & V_14 -> V_94 . V_89 ) ;
}
static T_2 F_87 ( struct V_71 * * V_96 )
{
struct V_71 * V_72 = * V_96 ;
struct V_1 * V_5 ;
struct V_14 * V_14 ;
T_2 V_97 ;
V_72 = F_88 ( V_72 , V_98 ) ;
if ( ! V_72 )
return V_99 ;
* V_96 = V_72 ;
V_5 = F_1 ( V_72 -> V_3 ) ;
V_14 = V_5 -> V_14 ;
if ( ! F_13 ( V_5 ) ) {
V_97 = V_100 ;
} else {
V_97 = V_14 -> V_77 . V_79 ( V_14 , V_5 , V_72 ) ;
}
if ( V_97 == V_73 ) {
struct V_101 * V_102 ;
V_102 = F_89 ( V_14 -> V_102 ) ;
F_90 ( & V_102 -> V_103 ) ;
V_102 -> V_104 ++ ;
V_102 -> V_105 += V_72 -> V_106 ;
if ( V_72 -> V_107 == V_108 )
V_102 -> V_109 ++ ;
F_91 ( & V_102 -> V_103 ) ;
V_72 -> V_3 = V_14 -> V_3 ;
} else {
F_92 ( V_14 -> V_102 -> V_110 ) ;
}
return V_97 ;
}
static int F_93 ( struct V_14 * V_14 )
{
struct V_111 * V_112 ;
unsigned int V_113 = V_14 -> V_3 -> V_114 - 1 ;
unsigned int V_33 ;
if ( ! V_113 )
return 0 ;
V_112 = F_24 ( sizeof( struct V_111 ) * V_113 , V_35 ) ;
if ( ! V_112 )
return - V_36 ;
V_14 -> V_115 = V_112 ;
for ( V_33 = 0 ; V_33 < V_113 ; V_33 ++ )
F_94 ( V_112 ++ ) ;
return 0 ;
}
static void F_95 ( struct V_14 * V_14 )
{
F_20 ( V_14 -> V_115 ) ;
}
static struct V_111 * F_96 ( struct V_14 * V_14 , T_3 V_116 )
{
return & V_14 -> V_115 [ V_116 - 1 ] ;
}
static bool F_97 ( struct V_14 * V_14 , struct V_71 * V_72 )
{
struct V_111 * V_117 ;
struct V_1 * V_5 ;
if ( ! V_14 -> V_118 || ! V_72 -> V_119 )
return false ;
V_117 = F_96 ( V_14 , V_72 -> V_119 ) ;
F_98 (port, qom_list, qom_list) {
if ( ! F_99 ( V_14 , V_5 , V_72 ) )
return true ;
}
return false ;
}
static void F_100 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
if ( ! V_5 -> V_116 )
return;
F_101 ( & V_5 -> V_117 ) ;
}
static bool F_102 ( struct V_1 * V_5 ,
struct V_1 * V_120 )
{
if ( V_5 -> V_121 < V_120 -> V_121 )
return true ;
if ( V_5 -> V_121 > V_120 -> V_121 )
return false ;
if ( V_5 -> V_122 < V_120 -> V_122 )
return true ;
return false ;
}
static void F_103 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
struct V_1 * V_120 ;
struct V_111 * V_117 ;
struct V_111 * V_123 ;
if ( ! V_5 -> V_116 )
return;
V_117 = F_96 ( V_14 , V_5 -> V_116 ) ;
V_123 = V_117 ;
F_17 (cur, qom_list, qom_list) {
if ( F_102 ( V_5 , V_120 ) )
break;
V_123 = & V_120 -> V_117 ;
}
F_104 ( & V_5 -> V_117 , V_123 ) ;
}
static void F_105 ( struct V_14 * V_14 )
{
struct V_1 * V_5 ;
bool V_124 = false ;
F_17 (port, &team->port_list, list) {
if ( V_5 -> V_116 ) {
V_124 = true ;
break;
}
}
if ( V_124 == V_14 -> V_118 )
return;
F_106 ( V_14 -> V_3 , L_7 ,
V_124 ? L_8 : L_9 ) ;
V_14 -> V_118 = V_124 ;
}
static void F_107 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
if ( ! V_5 -> V_116 || F_13 ( V_5 ) )
return;
F_100 ( V_14 , V_5 ) ;
F_103 ( V_14 , V_5 ) ;
F_105 ( V_14 ) ;
}
static void F_108 ( struct V_14 * V_14 ,
struct V_1 * V_5 ,
T_3 V_125 )
{
if ( F_13 ( V_5 ) ) {
F_100 ( V_14 , V_5 ) ;
V_5 -> V_116 = V_125 ;
F_103 ( V_14 , V_5 ) ;
F_105 ( V_14 ) ;
} else {
V_5 -> V_116 = V_125 ;
}
}
static void F_109 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
F_103 ( V_14 , V_5 ) ;
F_105 ( V_14 ) ;
}
static void F_110 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
F_100 ( V_14 , V_5 ) ;
F_105 ( V_14 ) ;
}
static bool F_111 ( const struct V_14 * V_14 ,
const struct V_1 * V_5 )
{
struct V_1 * V_120 ;
F_17 (cur, &team->port_list, list)
if ( V_120 == V_5 )
return true ;
return false ;
}
static void F_112 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
if ( F_13 ( V_5 ) )
return;
V_5 -> V_122 = V_14 -> V_76 ++ ;
F_113 ( & V_5 -> V_126 ,
F_114 ( V_14 , V_5 -> V_122 ) ) ;
F_61 ( V_14 ) ;
F_109 ( V_14 , V_5 ) ;
if ( V_14 -> V_77 . V_127 )
V_14 -> V_77 . V_127 ( V_14 , V_5 ) ;
F_76 ( V_14 ) ;
F_84 ( V_14 ) ;
F_12 ( V_5 ) ;
}
static void F_115 ( struct V_14 * V_14 , int V_128 )
{
int V_33 ;
struct V_1 * V_5 ;
for ( V_33 = V_128 + 1 ; V_33 < V_14 -> V_76 ; V_33 ++ ) {
V_5 = F_116 ( V_14 , V_33 ) ;
F_117 ( & V_5 -> V_126 ) ;
V_5 -> V_122 -- ;
F_113 ( & V_5 -> V_126 ,
F_114 ( V_14 , V_5 -> V_122 ) ) ;
}
}
static void F_118 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
if ( ! F_13 ( V_5 ) )
return;
if ( V_14 -> V_77 . V_129 )
V_14 -> V_77 . V_129 ( V_14 , V_5 ) ;
F_117 ( & V_5 -> V_126 ) ;
F_115 ( V_14 , V_5 -> V_122 ) ;
V_5 -> V_122 = - 1 ;
V_14 -> V_76 -- ;
F_110 ( V_14 , V_5 ) ;
F_61 ( V_14 ) ;
F_76 ( V_14 ) ;
F_84 ( V_14 ) ;
F_12 ( V_5 ) ;
}
static void F_119 ( struct V_14 * V_14 )
{
struct V_1 * V_5 ;
T_4 V_130 = V_131 & V_132 ;
T_5 V_133 = V_134 ;
unsigned short V_135 = V_136 ;
unsigned int V_137 = V_138 |
V_139 ;
F_17 (port, &team->port_list, list) {
V_130 = F_120 ( V_130 ,
V_5 -> V_3 -> V_130 ,
V_131 ) ;
V_133 =
F_120 ( V_133 ,
V_5 -> V_3 -> V_140 ,
V_134 ) ;
V_137 &= V_5 -> V_3 -> V_141 ;
if ( V_5 -> V_3 -> V_142 > V_135 )
V_135 = V_5 -> V_3 -> V_142 ;
}
V_14 -> V_3 -> V_130 = V_130 ;
V_14 -> V_3 -> V_140 = V_133 | V_143 ;
V_14 -> V_3 -> V_142 = V_135 ;
V_14 -> V_3 -> V_141 &= ~ V_138 ;
if ( V_137 == ( V_138 | V_139 ) )
V_14 -> V_3 -> V_141 |= V_138 ;
F_121 ( V_14 -> V_3 ) ;
}
static void F_122 ( struct V_14 * V_14 )
{
F_123 ( & V_14 -> V_144 ) ;
F_119 ( V_14 ) ;
F_124 ( & V_14 -> V_144 ) ;
}
static int F_125 ( struct V_14 * V_14 , struct V_1 * V_5 )
{
int V_34 = 0 ;
F_126 ( V_14 -> V_3 ) ;
if ( V_14 -> V_77 . V_145 ) {
V_34 = V_14 -> V_77 . V_145 ( V_14 , V_5 ) ;
if ( V_34 ) {
F_67 ( V_14 -> V_3 , L_10 ,
V_5 -> V_3 -> V_27 ) ;
goto V_146;
}
}
return 0 ;
V_146:
F_127 ( V_14 -> V_3 ) ;
return V_34 ;
}
static void F_128 ( struct V_14 * V_14 , struct V_1 * V_5 )
{
if ( V_14 -> V_77 . V_147 )
V_14 -> V_77 . V_147 ( V_14 , V_5 ) ;
F_127 ( V_14 -> V_3 ) ;
}
static int F_129 ( struct V_14 * V_14 , struct V_1 * V_5 )
{
struct V_148 * V_149 ;
int V_34 ;
if ( ! V_14 -> V_3 -> V_150 )
return 0 ;
V_149 = F_32 ( sizeof( * V_149 ) , V_35 ) ;
if ( ! V_149 )
return - V_36 ;
V_34 = F_130 ( V_149 , V_5 -> V_3 ) ;
if ( V_34 ) {
F_20 ( V_149 ) ;
return V_34 ;
}
V_5 -> V_149 = V_149 ;
return V_34 ;
}
static void F_131 ( struct V_1 * V_5 )
{
struct V_148 * V_149 = V_5 -> V_149 ;
if ( ! V_149 )
return;
V_5 -> V_149 = NULL ;
F_132 () ;
F_133 ( V_149 ) ;
F_20 ( V_149 ) ;
}
static int F_129 ( struct V_14 * V_14 , struct V_1 * V_5 )
{
return 0 ;
}
static void F_131 ( struct V_1 * V_5 )
{
}
static int F_134 ( struct V_14 * V_14 , struct V_1 * V_5 )
{
struct V_151 V_152 ;
int V_34 ;
V_152 . V_153 = V_14 -> V_62 -> V_154 ;
V_34 = F_135 ( V_5 -> V_3 , V_14 -> V_3 , NULL ,
& V_152 ) ;
if ( V_34 )
return V_34 ;
V_5 -> V_3 -> V_141 |= V_155 ;
return 0 ;
}
static void F_136 ( struct V_14 * V_14 , struct V_1 * V_5 )
{
F_137 ( V_5 -> V_3 , V_14 -> V_3 ) ;
V_5 -> V_3 -> V_141 &= ~ V_155 ;
}
static int F_138 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_5 ;
char * V_156 = V_6 -> V_27 ;
int V_34 ;
if ( V_6 -> V_157 & V_158 ) {
F_67 ( V_3 , L_11 ,
V_156 ) ;
return - V_66 ;
}
if ( F_5 ( V_6 ) ) {
F_67 ( V_3 , L_12
L_13 , V_156 ) ;
return - V_84 ;
}
if ( V_6 -> V_159 & V_160 &&
F_139 ( V_3 ) ) {
F_67 ( V_3 , L_14 ,
V_156 ) ;
return - V_161 ;
}
V_34 = F_140 ( V_3 , V_6 ) ;
if ( V_34 )
return V_34 ;
if ( V_6 -> V_157 & V_162 ) {
F_67 ( V_3 , L_15 ,
V_156 ) ;
return - V_84 ;
}
V_5 = F_32 ( sizeof( struct V_1 ) + V_14 -> V_62 -> V_163 ,
V_35 ) ;
if ( ! V_5 )
return - V_36 ;
V_5 -> V_3 = V_6 ;
V_5 -> V_14 = V_14 ;
F_94 ( & V_5 -> V_117 ) ;
V_5 -> V_13 . V_164 = V_6 -> V_164 ;
V_34 = F_141 ( V_6 , V_3 -> V_164 ) ;
if ( V_34 ) {
F_106 ( V_3 , L_16 , V_34 ) ;
goto V_165;
}
memcpy ( V_5 -> V_13 . V_7 , V_6 -> V_7 , V_6 -> V_11 ) ;
V_34 = F_125 ( V_14 , V_5 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_10 ,
V_156 ) ;
goto V_146;
}
V_34 = F_142 ( V_6 ) ;
if ( V_34 ) {
F_106 ( V_3 , L_17 ,
V_156 ) ;
goto V_166;
}
V_34 = F_143 ( V_6 , V_3 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_18 ,
V_156 ) ;
goto V_167;
}
V_34 = F_129 ( V_14 , V_5 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_19 ,
V_156 ) ;
goto V_168;
}
if ( ! ( V_3 -> V_159 & V_169 ) )
F_144 ( V_6 ) ;
V_34 = F_145 ( V_6 , F_87 ,
V_5 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_20 ,
V_156 ) ;
goto V_170;
}
V_34 = F_134 ( V_14 , V_5 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_21 ,
V_156 ) ;
goto V_171;
}
V_34 = F_29 ( V_14 , V_5 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_22 ,
V_156 ) ;
goto V_172;
}
V_5 -> V_122 = - 1 ;
F_104 ( & V_5 -> V_30 , & V_14 -> V_83 ) ;
F_112 ( V_14 , V_5 ) ;
F_119 ( V_14 ) ;
F_146 ( V_5 , ! ! F_147 ( V_6 ) ) ;
F_37 ( V_14 ) ;
F_68 ( V_3 , L_23 , V_156 ) ;
return 0 ;
V_172:
F_136 ( V_14 , V_5 ) ;
V_171:
F_148 ( V_6 ) ;
V_170:
F_131 ( V_5 ) ;
V_168:
F_149 ( V_6 , V_3 ) ;
V_167:
F_150 ( V_6 ) ;
V_166:
F_128 ( V_14 , V_5 ) ;
F_8 ( V_5 ) ;
V_146:
F_141 ( V_6 , V_5 -> V_13 . V_164 ) ;
V_165:
F_20 ( V_5 ) ;
return V_34 ;
}
static int F_151 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_5 ;
char * V_156 = V_6 -> V_27 ;
V_5 = F_3 ( V_6 ) ;
if ( ! V_5 || ! F_111 ( V_14 , V_5 ) ) {
F_67 ( V_3 , L_24 ,
V_156 ) ;
return - V_173 ;
}
F_118 ( V_14 , V_5 ) ;
F_101 ( & V_5 -> V_30 ) ;
F_136 ( V_14 , V_5 ) ;
F_148 ( V_6 ) ;
F_131 ( V_5 ) ;
F_149 ( V_6 , V_3 ) ;
F_152 ( V_6 , V_3 ) ;
F_153 ( V_6 , V_3 ) ;
F_150 ( V_6 ) ;
F_128 ( V_14 , V_5 ) ;
F_30 ( V_14 , V_5 ) ;
F_37 ( V_14 ) ;
F_28 ( V_14 , V_5 ) ;
F_154 ( V_5 ) ;
F_8 ( V_5 ) ;
F_141 ( V_6 , V_5 -> V_13 . V_164 ) ;
F_155 ( V_5 , V_174 ) ;
F_68 ( V_3 , L_25 , V_156 ) ;
F_119 ( V_14 ) ;
return 0 ;
}
static int F_156 ( struct V_14 * V_14 , struct V_52 * V_53 )
{
V_53 -> V_175 . V_176 = V_14 -> V_62 -> V_60 ;
return 0 ;
}
static int F_157 ( struct V_14 * V_14 , struct V_52 * V_53 )
{
return F_65 ( V_14 , V_53 -> V_175 . V_176 ) ;
}
static int F_158 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
V_53 -> V_175 . V_177 = V_14 -> V_88 . V_93 ;
return 0 ;
}
static int F_159 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
V_14 -> V_88 . V_93 = V_53 -> V_175 . V_177 ;
return 0 ;
}
static int F_160 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
V_53 -> V_175 . V_177 = V_14 -> V_88 . V_92 ;
return 0 ;
}
static int F_161 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
V_14 -> V_88 . V_92 = V_53 -> V_175 . V_177 ;
return 0 ;
}
static int F_162 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
V_53 -> V_175 . V_177 = V_14 -> V_94 . V_93 ;
return 0 ;
}
static int F_163 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
V_14 -> V_94 . V_93 = V_53 -> V_175 . V_177 ;
return 0 ;
}
static int F_164 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
V_53 -> V_175 . V_177 = V_14 -> V_94 . V_92 ;
return 0 ;
}
static int F_165 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
V_14 -> V_94 . V_92 = V_53 -> V_175 . V_177 ;
return 0 ;
}
static int F_166 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
V_53 -> V_175 . V_178 = F_13 ( V_5 ) ;
return 0 ;
}
static int F_167 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
if ( V_53 -> V_175 . V_178 )
F_112 ( V_14 , V_5 ) ;
else
F_118 ( V_14 , V_5 ) ;
return 0 ;
}
static int F_168 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
V_53 -> V_175 . V_178 = V_5 -> V_21 . V_18 ;
return 0 ;
}
static int F_169 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
V_5 -> V_21 . V_18 = V_53 -> V_175 . V_178 ;
F_15 ( V_5 ) ;
F_170 ( V_5 -> V_14 ) ;
return 0 ;
}
static int F_171 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
V_53 -> V_175 . V_178 = V_5 -> V_21 . V_22 ;
return 0 ;
}
static int F_172 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
V_5 -> V_21 . V_22 = V_53 -> V_175 . V_178 ;
F_15 ( V_5 ) ;
F_170 ( V_5 -> V_14 ) ;
return 0 ;
}
static int F_173 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
V_53 -> V_175 . V_179 = V_5 -> V_121 ;
return 0 ;
}
static int F_174 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
T_6 V_121 = V_53 -> V_175 . V_179 ;
if ( V_5 -> V_121 == V_121 )
return 0 ;
V_5 -> V_121 = V_121 ;
F_107 ( V_14 , V_5 ) ;
return 0 ;
}
static int F_175 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
V_53 -> V_175 . V_177 = V_5 -> V_116 ;
return 0 ;
}
static int F_176 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
T_3 V_125 = V_53 -> V_175 . V_177 ;
if ( V_5 -> V_116 == V_125 )
return 0 ;
if ( V_125 >= V_14 -> V_3 -> V_180 )
return - V_66 ;
F_108 ( V_14 , V_5 , V_125 ) ;
return 0 ;
}
static void F_177 ( struct V_2 * V_3 ,
struct V_181 * V_182 ,
void * V_183 )
{
F_178 ( & V_182 -> V_184 , & V_185 ) ;
}
static void F_179 ( struct V_2 * V_3 )
{
F_178 ( & V_3 -> V_186 , & V_187 ) ;
F_180 ( V_3 , F_177 , NULL ) ;
V_3 -> V_188 = & V_189 ;
}
static int F_181 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_182 ( V_3 ) ;
int V_33 ;
int V_34 ;
V_14 -> V_3 = V_3 ;
F_183 ( & V_14 -> V_144 ) ;
F_60 ( V_14 ) ;
V_14 -> V_102 = F_184 ( struct V_101 ) ;
if ( ! V_14 -> V_102 )
return - V_36 ;
for ( V_33 = 0 ; V_33 < V_190 ; V_33 ++ )
F_185 ( & V_14 -> V_191 [ V_33 ] ) ;
F_94 ( & V_14 -> V_83 ) ;
V_34 = F_93 ( V_14 ) ;
if ( V_34 )
goto V_192;
F_61 ( V_14 ) ;
F_94 ( & V_14 -> V_50 ) ;
F_94 ( & V_14 -> V_40 ) ;
F_79 ( V_14 ) ;
F_85 ( V_14 ) ;
V_34 = F_36 ( V_14 , V_193 , F_186 ( V_193 ) ) ;
if ( V_34 )
goto V_194;
F_187 ( V_3 ) ;
F_179 ( V_3 ) ;
return 0 ;
V_194:
F_86 ( V_14 ) ;
F_81 ( V_14 ) ;
F_95 ( V_14 ) ;
V_192:
F_188 ( V_14 -> V_102 ) ;
return V_34 ;
}
static void F_189 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_182 ( V_3 ) ;
struct V_1 * V_5 ;
struct V_1 * V_31 ;
F_123 ( & V_14 -> V_144 ) ;
F_22 (port, tmp, &team->port_list, list)
F_151 ( V_14 , V_5 -> V_3 ) ;
F_62 ( V_14 , NULL ) ;
F_35 ( V_14 , V_193 , F_186 ( V_193 ) ) ;
F_86 ( V_14 ) ;
F_81 ( V_14 ) ;
F_95 ( V_14 ) ;
F_124 ( & V_14 -> V_144 ) ;
}
static void F_190 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_182 ( V_3 ) ;
F_188 ( V_14 -> V_102 ) ;
F_191 ( V_3 ) ;
}
static int F_192 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_193 ( struct V_2 * V_3 )
{
return 0 ;
}
static T_7 F_194 ( struct V_71 * V_72 , struct V_2 * V_3 )
{
struct V_14 * V_14 = F_182 ( V_3 ) ;
bool V_195 ;
unsigned int V_106 = V_72 -> V_106 ;
V_195 = F_97 ( V_14 , V_72 ) ;
if ( ! V_195 )
V_195 = V_14 -> V_77 . V_78 ( V_14 , V_72 ) ;
if ( V_195 ) {
struct V_101 * V_102 ;
V_102 = F_89 ( V_14 -> V_102 ) ;
F_90 ( & V_102 -> V_103 ) ;
V_102 -> V_196 ++ ;
V_102 -> V_197 += V_106 ;
F_91 ( & V_102 -> V_103 ) ;
} else {
F_92 ( V_14 -> V_102 -> V_198 ) ;
}
return V_199 ;
}
static T_3 F_195 ( struct V_2 * V_3 , struct V_71 * V_72 ,
void * V_200 , T_8 V_201 )
{
T_3 V_182 = F_196 ( V_72 ) ? F_197 ( V_72 ) : 0 ;
F_198 ( V_72 ) -> V_202 = V_72 -> V_119 ;
if ( F_199 ( V_182 >= V_3 -> V_180 ) ) {
do {
V_182 -= V_3 -> V_180 ;
} while ( V_182 >= V_3 -> V_180 );
}
return V_182 ;
}
static void F_200 ( struct V_2 * V_3 , int V_203 )
{
struct V_14 * V_14 = F_182 ( V_3 ) ;
struct V_1 * V_5 ;
int V_204 ;
F_201 () ;
F_98 (port, &team->port_list, list) {
if ( V_203 & V_205 ) {
V_204 = V_3 -> V_157 & V_205 ? 1 : - 1 ;
F_202 ( V_5 -> V_3 , V_204 ) ;
}
if ( V_203 & V_206 ) {
V_204 = V_3 -> V_157 & V_206 ? 1 : - 1 ;
F_203 ( V_5 -> V_3 , V_204 ) ;
}
}
F_204 () ;
}
static void F_205 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_182 ( V_3 ) ;
struct V_1 * V_5 ;
F_201 () ;
F_98 (port, &team->port_list, list) {
F_206 ( V_5 -> V_3 , V_3 ) ;
F_207 ( V_5 -> V_3 , V_3 ) ;
}
F_204 () ;
}
static int F_208 ( struct V_2 * V_3 , void * V_207 )
{
struct V_8 * V_9 = V_207 ;
struct V_14 * V_14 = F_182 ( V_3 ) ;
struct V_1 * V_5 ;
if ( V_3 -> type == V_208 && ! F_209 ( V_9 -> V_10 ) )
return - V_209 ;
memcpy ( V_3 -> V_7 , V_9 -> V_10 , V_3 -> V_11 ) ;
F_123 ( & V_14 -> V_144 ) ;
F_17 (port, &team->port_list, list)
if ( V_14 -> V_77 . V_210 )
V_14 -> V_77 . V_210 ( V_14 , V_5 ) ;
F_124 ( & V_14 -> V_144 ) ;
return 0 ;
}
static int F_210 ( struct V_2 * V_3 , int V_211 )
{
struct V_14 * V_14 = F_182 ( V_3 ) ;
struct V_1 * V_5 ;
int V_34 ;
F_123 ( & V_14 -> V_144 ) ;
V_14 -> V_212 = true ;
F_17 (port, &team->port_list, list) {
V_34 = F_141 ( V_5 -> V_3 , V_211 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_26 ,
V_5 -> V_3 -> V_27 ) ;
goto V_213;
}
}
V_14 -> V_212 = false ;
F_124 ( & V_14 -> V_144 ) ;
V_3 -> V_164 = V_211 ;
return 0 ;
V_213:
F_211 (port, &team->port_list, list)
F_141 ( V_5 -> V_3 , V_3 -> V_164 ) ;
V_14 -> V_212 = false ;
F_124 ( & V_14 -> V_144 ) ;
return V_34 ;
}
static struct V_214 *
F_212 ( struct V_2 * V_3 , struct V_214 * V_215 )
{
struct V_14 * V_14 = F_182 ( V_3 ) ;
struct V_101 * V_207 ;
T_9 V_104 , V_105 , V_109 , V_196 , V_197 ;
T_4 V_110 = 0 , V_198 = 0 ;
unsigned int V_216 ;
int V_33 ;
F_213 (i) {
V_207 = F_214 ( V_14 -> V_102 , V_33 ) ;
do {
V_216 = F_215 ( & V_207 -> V_103 ) ;
V_104 = V_207 -> V_104 ;
V_105 = V_207 -> V_105 ;
V_109 = V_207 -> V_109 ;
V_196 = V_207 -> V_196 ;
V_197 = V_207 -> V_197 ;
} while ( F_216 ( & V_207 -> V_103 , V_216 ) );
V_215 -> V_104 += V_104 ;
V_215 -> V_105 += V_105 ;
V_215 -> V_217 += V_109 ;
V_215 -> V_196 += V_196 ;
V_215 -> V_197 += V_197 ;
V_110 += V_207 -> V_110 ;
V_198 += V_207 -> V_198 ;
}
V_215 -> V_110 = V_110 ;
V_215 -> V_198 = V_198 ;
return V_215 ;
}
static int F_217 ( struct V_2 * V_3 , T_10 V_218 , T_3 V_219 )
{
struct V_14 * V_14 = F_182 ( V_3 ) ;
struct V_1 * V_5 ;
int V_34 ;
F_123 ( & V_14 -> V_144 ) ;
F_17 (port, &team->port_list, list) {
V_34 = F_218 ( V_5 -> V_3 , V_218 , V_219 ) ;
if ( V_34 )
goto V_213;
}
F_124 ( & V_14 -> V_144 ) ;
return 0 ;
V_213:
F_211 (port, &team->port_list, list)
F_219 ( V_5 -> V_3 , V_218 , V_219 ) ;
F_124 ( & V_14 -> V_144 ) ;
return V_34 ;
}
static int F_220 ( struct V_2 * V_3 , T_10 V_218 , T_3 V_219 )
{
struct V_14 * V_14 = F_182 ( V_3 ) ;
struct V_1 * V_5 ;
F_123 ( & V_14 -> V_144 ) ;
F_17 (port, &team->port_list, list)
F_219 ( V_5 -> V_3 , V_218 , V_219 ) ;
F_124 ( & V_14 -> V_144 ) ;
return 0 ;
}
static void F_221 ( struct V_2 * V_3 )
{
}
static void F_222 ( struct V_14 * V_14 )
{
struct V_1 * V_5 ;
F_17 (port, &team->port_list, list)
F_131 ( V_5 ) ;
}
static void F_223 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_182 ( V_3 ) ;
F_123 ( & V_14 -> V_144 ) ;
F_222 ( V_14 ) ;
F_124 ( & V_14 -> V_144 ) ;
}
static int F_224 ( struct V_2 * V_3 ,
struct V_220 * V_221 )
{
struct V_14 * V_14 = F_182 ( V_3 ) ;
struct V_1 * V_5 ;
int V_34 = 0 ;
F_123 ( & V_14 -> V_144 ) ;
F_17 (port, &team->port_list, list) {
V_34 = F_129 ( V_14 , V_5 ) ;
if ( V_34 ) {
F_222 ( V_14 ) ;
break;
}
}
F_124 ( & V_14 -> V_144 ) ;
return V_34 ;
}
static int F_225 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_182 ( V_3 ) ;
int V_34 ;
F_123 ( & V_14 -> V_144 ) ;
V_34 = F_138 ( V_14 , V_6 ) ;
F_124 ( & V_14 -> V_144 ) ;
return V_34 ;
}
static int F_226 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_182 ( V_3 ) ;
int V_34 ;
F_123 ( & V_14 -> V_144 ) ;
V_34 = F_151 ( V_14 , V_6 ) ;
F_124 ( & V_14 -> V_144 ) ;
return V_34 ;
}
static T_5 F_227 ( struct V_2 * V_3 ,
T_5 V_159 )
{
struct V_1 * V_5 ;
struct V_14 * V_14 = F_182 ( V_3 ) ;
T_5 V_222 ;
V_222 = V_159 ;
V_159 &= ~ V_223 ;
V_159 |= V_132 ;
F_201 () ;
F_98 (port, &team->port_list, list) {
V_159 = F_120 ( V_159 ,
V_5 -> V_3 -> V_159 ,
V_222 ) ;
}
F_204 () ;
V_159 = F_228 ( V_159 , V_222 ) ;
return V_159 ;
}
static int F_229 ( struct V_2 * V_3 , bool V_224 )
{
struct V_14 * V_14 = F_182 ( V_3 ) ;
V_14 -> V_75 = true ;
if ( V_224 )
F_230 ( V_3 ) ;
else
F_187 ( V_3 ) ;
return 0 ;
}
static void F_231 ( struct V_2 * V_3 ,
struct V_225 * V_226 )
{
F_232 ( V_226 -> V_227 , V_228 , sizeof( V_226 -> V_227 ) ) ;
F_232 ( V_226 -> V_229 , V_230 , sizeof( V_226 -> V_229 ) ) ;
}
static void F_233 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
V_3 -> V_231 = V_6 -> V_231 ;
V_3 -> type = V_6 -> type ;
V_3 -> V_142 = V_6 -> V_142 ;
V_3 -> V_11 = V_6 -> V_11 ;
V_3 -> V_164 = V_6 -> V_164 ;
memcpy ( V_3 -> V_232 , V_6 -> V_232 , V_6 -> V_11 ) ;
F_234 ( V_3 , V_6 ) ;
}
static int F_140 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
struct V_14 * V_14 = F_182 ( V_3 ) ;
char * V_156 = V_6 -> V_27 ;
int V_34 ;
if ( V_3 -> type == V_6 -> type )
return 0 ;
if ( ! F_66 ( & V_14 -> V_83 ) ) {
F_67 ( V_3 , L_27 , V_156 ) ;
return - V_84 ;
}
V_34 = F_74 ( V_233 , V_3 ) ;
V_34 = F_235 ( V_34 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_28 ) ;
return V_34 ;
}
F_236 ( V_3 ) ;
F_237 ( V_3 ) ;
F_233 ( V_3 , V_6 ) ;
F_74 ( V_234 , V_3 ) ;
return 0 ;
}
static void F_238 ( struct V_2 * V_3 )
{
F_239 ( V_3 ) ;
V_3 -> V_235 = & V_236 ;
V_3 -> V_237 = & V_238 ;
V_3 -> V_239 = F_190 ;
V_3 -> V_157 |= V_240 ;
V_3 -> V_141 &= ~ ( V_138 | V_241 ) ;
V_3 -> V_141 |= V_242 ;
V_3 -> V_141 |= V_243 ;
V_3 -> V_141 |= V_244 | V_245 ;
V_3 -> V_159 |= V_246 ;
V_3 -> V_159 |= V_247 ;
V_3 -> V_159 |= V_248 ;
V_3 -> V_249 = V_131 |
V_250 |
V_251 |
V_252 ;
V_3 -> V_249 |= V_143 ;
V_3 -> V_159 |= V_3 -> V_249 ;
}
static int F_240 ( struct V_253 * V_254 , struct V_2 * V_3 ,
struct V_255 * V_256 [] , struct V_255 * V_175 [] )
{
if ( V_256 [ V_257 ] == NULL )
F_241 ( V_3 ) ;
return F_242 ( V_3 ) ;
}
static int F_243 ( struct V_255 * V_256 [] , struct V_255 * V_175 [] )
{
if ( V_256 [ V_257 ] ) {
if ( F_244 ( V_256 [ V_257 ] ) != V_258 )
return - V_66 ;
if ( ! F_209 ( F_245 ( V_256 [ V_257 ] ) ) )
return - V_209 ;
}
return 0 ;
}
static unsigned int F_246 ( void )
{
return V_259 ;
}
static unsigned int F_247 ( void )
{
return V_260 ;
}
static int F_248 ( struct V_71 * V_72 , struct V_261 * V_16 )
{
struct V_71 * V_262 ;
void * V_263 ;
int V_34 ;
V_262 = F_249 ( V_264 , V_35 ) ;
if ( ! V_262 )
return - V_36 ;
V_263 = F_250 ( V_262 , V_16 -> V_265 , V_16 -> V_266 ,
& V_267 , 0 , V_268 ) ;
if ( ! V_263 ) {
V_34 = - V_269 ;
goto V_270;
}
F_251 ( V_262 , V_263 ) ;
return F_252 ( F_253 ( V_16 ) , V_262 , V_16 -> V_265 ) ;
V_270:
F_254 ( V_262 ) ;
return V_34 ;
}
static struct V_14 * F_255 ( struct V_261 * V_16 )
{
struct V_253 * V_253 = F_253 ( V_16 ) ;
int V_271 ;
struct V_2 * V_3 ;
struct V_14 * V_14 ;
if ( ! V_16 -> V_272 [ V_273 ] )
return NULL ;
V_271 = F_256 ( V_16 -> V_272 [ V_273 ] ) ;
V_3 = F_257 ( V_253 , V_271 ) ;
if ( ! V_3 || V_3 -> V_235 != & V_236 ) {
if ( V_3 )
F_127 ( V_3 ) ;
return NULL ;
}
V_14 = F_182 ( V_3 ) ;
F_123 ( & V_14 -> V_144 ) ;
return V_14 ;
}
static void F_258 ( struct V_14 * V_14 )
{
F_124 ( & V_14 -> V_144 ) ;
F_127 ( V_14 -> V_3 ) ;
}
static int F_259 ( struct V_71 * V_72 , struct V_14 * V_14 , T_4 V_274 )
{
return F_252 ( F_260 ( V_14 -> V_3 ) , V_72 , V_274 ) ;
}
static int F_261 ( struct V_71 * V_72 , struct V_14 * V_14 ,
struct V_28 * V_29 )
{
struct V_255 * V_275 ;
struct V_24 * V_26 = V_29 -> V_26 ;
struct V_57 * V_58 = & V_29 -> V_16 ;
struct V_52 V_53 ;
int V_34 ;
V_53 . V_16 = V_58 ;
V_34 = F_39 ( V_14 , V_29 , & V_53 ) ;
if ( V_34 )
return V_34 ;
V_275 = F_262 ( V_72 , V_276 ) ;
if ( ! V_275 )
return - V_269 ;
if ( F_263 ( V_72 , V_277 , V_26 -> V_27 ) )
goto V_278;
if ( V_58 -> V_5 &&
F_264 ( V_72 , V_279 ,
V_58 -> V_5 -> V_3 -> V_271 ) )
goto V_278;
if ( V_29 -> V_26 -> V_32 &&
F_264 ( V_72 , V_280 ,
V_58 -> V_37 ) )
goto V_278;
switch ( V_26 -> type ) {
case V_281 :
if ( F_265 ( V_72 , V_282 , V_283 ) )
goto V_278;
if ( F_264 ( V_72 , V_284 , V_53 . V_175 . V_177 ) )
goto V_278;
break;
case V_285 :
if ( F_265 ( V_72 , V_282 , V_286 ) )
goto V_278;
if ( F_263 ( V_72 , V_284 ,
V_53 . V_175 . V_176 ) )
goto V_278;
break;
case V_287 :
if ( F_265 ( V_72 , V_282 , V_288 ) )
goto V_278;
if ( F_266 ( V_72 , V_284 , V_53 . V_175 . V_289 . V_106 ,
V_53 . V_175 . V_289 . V_290 ) )
goto V_278;
break;
case V_291 :
if ( F_265 ( V_72 , V_282 , V_292 ) )
goto V_278;
if ( V_53 . V_175 . V_178 &&
F_267 ( V_72 , V_284 ) )
goto V_278;
break;
case V_293 :
if ( F_265 ( V_72 , V_282 , V_294 ) )
goto V_278;
if ( F_268 ( V_72 , V_284 , V_53 . V_175 . V_179 ) )
goto V_278;
break;
default:
F_269 () ;
}
if ( V_29 -> V_39 && F_267 ( V_72 , V_295 ) )
goto V_278;
if ( V_29 -> V_38 ) {
if ( F_267 ( V_72 , V_296 ) )
goto V_278;
V_29 -> V_38 = false ;
}
F_270 ( V_72 , V_275 ) ;
return 0 ;
V_278:
F_271 ( V_72 , V_275 ) ;
return - V_269 ;
}
static int F_272 ( struct V_71 * * V_96 ,
struct V_14 * V_14 , T_4 V_274 ,
T_11 * V_297 )
{
int V_34 ;
if ( * V_96 ) {
V_34 = V_297 ( * V_96 , V_14 , V_274 ) ;
if ( V_34 )
return V_34 ;
}
* V_96 = F_273 ( V_298 , V_35 ) ;
if ( ! * V_96 )
return - V_36 ;
return 0 ;
}
static int F_274 ( struct V_14 * V_14 , T_4 V_274 , T_4 V_299 ,
int V_157 , T_11 * V_297 ,
struct V_111 * V_300 )
{
struct V_255 * V_50 ;
struct V_301 * V_302 ;
void * V_263 ;
struct V_28 * V_29 ;
int V_34 ;
struct V_71 * V_72 = NULL ;
bool V_303 ;
int V_33 ;
V_29 = F_275 ( V_300 ,
struct V_28 , V_304 ) ;
V_305:
V_34 = F_272 ( & V_72 , V_14 , V_274 , V_297 ) ;
if ( V_34 )
return V_34 ;
V_263 = F_250 ( V_72 , V_274 , V_299 , & V_267 , V_157 | V_306 ,
V_307 ) ;
if ( ! V_263 )
return - V_269 ;
if ( F_264 ( V_72 , V_273 , V_14 -> V_3 -> V_271 ) )
goto V_308;
V_50 = F_262 ( V_72 , V_309 ) ;
if ( ! V_50 )
goto V_308;
V_33 = 0 ;
V_303 = false ;
F_276 (opt_inst, sel_opt_inst_list, tmp_list) {
V_34 = F_261 ( V_72 , V_14 , V_29 ) ;
if ( V_34 ) {
if ( V_34 == - V_269 ) {
if ( ! V_33 )
goto V_310;
V_303 = true ;
break;
}
goto V_310;
}
V_33 ++ ;
}
F_270 ( V_72 , V_50 ) ;
F_251 ( V_72 , V_263 ) ;
if ( V_303 )
goto V_305;
V_311:
V_302 = F_277 ( V_72 , V_274 , V_299 , V_312 , 0 , V_157 | V_306 ) ;
if ( ! V_302 ) {
V_34 = F_272 ( & V_72 , V_14 , V_274 , V_297 ) ;
if ( V_34 )
goto V_310;
goto V_311;
}
return V_297 ( V_72 , V_14 , V_274 ) ;
V_308:
V_34 = - V_269 ;
V_310:
F_278 ( V_72 , V_263 ) ;
F_254 ( V_72 ) ;
return V_34 ;
}
static int F_279 ( struct V_71 * V_72 , struct V_261 * V_16 )
{
struct V_14 * V_14 ;
struct V_28 * V_29 ;
int V_34 ;
F_280 ( V_300 ) ;
V_14 = F_255 ( V_16 ) ;
if ( ! V_14 )
return - V_66 ;
F_17 (opt_inst, &team->option_inst_list, list)
F_25 ( & V_29 -> V_304 , & V_300 ) ;
V_34 = F_274 ( V_14 , V_16 -> V_265 , V_16 -> V_266 ,
V_313 , F_259 ,
& V_300 ) ;
F_258 ( V_14 ) ;
return V_34 ;
}
static int F_281 ( struct V_71 * V_72 , struct V_261 * V_16 )
{
struct V_14 * V_14 ;
int V_34 = 0 ;
int V_33 ;
struct V_255 * V_314 ;
F_280 ( V_315 ) ;
F_282 () ;
V_14 = F_255 ( V_16 ) ;
if ( ! V_14 ) {
V_34 = - V_66 ;
goto F_73;
}
V_34 = - V_66 ;
if ( ! V_16 -> V_272 [ V_309 ] ) {
V_34 = - V_66 ;
goto V_316;
}
F_283 (nl_option, info->attrs[TEAM_ATTR_LIST_OPTION], i) {
struct V_255 * V_317 [ V_318 + 1 ] ;
struct V_255 * V_319 ;
struct V_255 * V_320 ;
enum V_321 V_322 ;
int V_323 = 0 ;
T_4 V_324 = 0 ;
bool V_325 = false ;
struct V_28 * V_29 ;
char * V_25 ;
bool V_326 = false ;
if ( F_284 ( V_314 ) != V_276 ) {
V_34 = - V_66 ;
goto V_316;
}
V_34 = F_285 ( V_317 , V_318 ,
V_314 , V_327 ) ;
if ( V_34 )
goto V_316;
if ( ! V_317 [ V_277 ] ||
! V_317 [ V_282 ] ) {
V_34 = - V_66 ;
goto V_316;
}
switch ( F_286 ( V_317 [ V_282 ] ) ) {
case V_283 :
V_322 = V_281 ;
break;
case V_286 :
V_322 = V_285 ;
break;
case V_288 :
V_322 = V_287 ;
break;
case V_292 :
V_322 = V_291 ;
break;
case V_294 :
V_322 = V_293 ;
break;
default:
goto V_316;
}
V_320 = V_317 [ V_284 ] ;
if ( V_322 != V_291 && ! V_320 ) {
V_34 = - V_66 ;
goto V_316;
}
V_25 = F_245 ( V_317 [ V_277 ] ) ;
V_319 = V_317 [ V_279 ] ;
if ( V_319 )
V_323 = F_256 ( V_319 ) ;
V_319 = V_317 [ V_280 ] ;
if ( V_319 ) {
V_325 = true ;
V_324 = F_256 ( V_319 ) ;
}
F_17 (opt_inst, &team->option_inst_list, list) {
struct V_24 * V_26 = V_29 -> V_26 ;
struct V_52 V_53 ;
struct V_57 * V_58 ;
int V_328 ;
V_58 = & V_29 -> V_16 ;
V_328 = V_58 -> V_5 ?
V_58 -> V_5 -> V_3 -> V_271 : 0 ;
if ( V_26 -> type != V_322 ||
strcmp ( V_26 -> V_27 , V_25 ) ||
V_328 != V_323 ||
( V_26 -> V_32 && ! V_325 ) ||
V_58 -> V_37 != V_324 )
continue;
V_326 = true ;
V_53 . V_16 = V_58 ;
switch ( V_322 ) {
case V_281 :
V_53 . V_175 . V_177 = F_256 ( V_320 ) ;
break;
case V_285 :
if ( F_244 ( V_320 ) > V_329 ) {
V_34 = - V_66 ;
goto V_316;
}
V_53 . V_175 . V_176 = F_245 ( V_320 ) ;
break;
case V_287 :
V_53 . V_175 . V_289 . V_106 = F_244 ( V_320 ) ;
V_53 . V_175 . V_289 . V_290 = F_245 ( V_320 ) ;
break;
case V_291 :
V_53 . V_175 . V_178 = V_320 ? true : false ;
break;
case V_293 :
V_53 . V_175 . V_179 = F_287 ( V_320 ) ;
break;
default:
F_269 () ;
}
V_34 = F_40 ( V_14 , V_29 , & V_53 ) ;
if ( V_34 )
goto V_316;
V_29 -> V_38 = true ;
F_288 ( & V_29 -> V_304 , & V_315 ) ;
}
if ( ! V_326 ) {
V_34 = - V_173 ;
goto V_316;
}
}
V_34 = F_289 ( V_14 , & V_315 ) ;
V_316:
F_258 ( V_14 ) ;
F_73:
F_73 () ;
return V_34 ;
}
static int F_290 ( struct V_71 * V_72 ,
struct V_1 * V_5 )
{
struct V_255 * V_330 ;
V_330 = F_262 ( V_72 , V_331 ) ;
if ( ! V_330 )
goto V_278;
if ( F_264 ( V_72 , V_332 , V_5 -> V_3 -> V_271 ) )
goto V_278;
if ( V_5 -> V_38 ) {
if ( F_267 ( V_72 , V_333 ) )
goto V_278;
V_5 -> V_38 = false ;
}
if ( ( V_5 -> V_39 &&
F_267 ( V_72 , V_334 ) ) ||
( V_5 -> V_23 . V_18 &&
F_267 ( V_72 , V_335 ) ) ||
F_264 ( V_72 , V_336 , V_5 -> V_23 . V_337 ) ||
F_265 ( V_72 , V_338 , V_5 -> V_23 . V_339 ) )
goto V_278;
F_270 ( V_72 , V_330 ) ;
return 0 ;
V_278:
F_271 ( V_72 , V_330 ) ;
return - V_269 ;
}
static int F_291 ( struct V_14 * V_14 , T_4 V_274 , T_4 V_299 ,
int V_157 , T_11 * V_297 ,
struct V_1 * V_340 )
{
struct V_255 * V_83 ;
struct V_301 * V_302 ;
void * V_263 ;
struct V_1 * V_5 ;
int V_34 ;
struct V_71 * V_72 = NULL ;
bool V_303 ;
int V_33 ;
V_5 = F_292 ( & V_14 -> V_83 ,
struct V_1 , V_30 ) ;
V_305:
V_34 = F_272 ( & V_72 , V_14 , V_274 , V_297 ) ;
if ( V_34 )
return V_34 ;
V_263 = F_250 ( V_72 , V_274 , V_299 , & V_267 , V_157 | V_306 ,
V_341 ) ;
if ( ! V_263 )
return - V_269 ;
if ( F_264 ( V_72 , V_273 , V_14 -> V_3 -> V_271 ) )
goto V_308;
V_83 = F_262 ( V_72 , V_342 ) ;
if ( ! V_83 )
goto V_308;
V_33 = 0 ;
V_303 = false ;
if ( V_340 ) {
V_34 = F_290 ( V_72 , V_340 ) ;
if ( V_34 )
goto V_310;
} else if ( V_5 ) {
F_276 (port, &team->port_list, list) {
V_34 = F_290 ( V_72 , V_5 ) ;
if ( V_34 ) {
if ( V_34 == - V_269 ) {
if ( ! V_33 )
goto V_310;
V_303 = true ;
break;
}
goto V_310;
}
V_33 ++ ;
}
}
F_270 ( V_72 , V_83 ) ;
F_251 ( V_72 , V_263 ) ;
if ( V_303 )
goto V_305;
V_311:
V_302 = F_277 ( V_72 , V_274 , V_299 , V_312 , 0 , V_157 | V_306 ) ;
if ( ! V_302 ) {
V_34 = F_272 ( & V_72 , V_14 , V_274 , V_297 ) ;
if ( V_34 )
goto V_310;
goto V_311;
}
return V_297 ( V_72 , V_14 , V_274 ) ;
V_308:
V_34 = - V_269 ;
V_310:
F_278 ( V_72 , V_263 ) ;
F_254 ( V_72 ) ;
return V_34 ;
}
static int F_293 ( struct V_71 * V_72 ,
struct V_261 * V_16 )
{
struct V_14 * V_14 ;
int V_34 ;
V_14 = F_255 ( V_16 ) ;
if ( ! V_14 )
return - V_66 ;
V_34 = F_291 ( V_14 , V_16 -> V_265 , V_16 -> V_266 ,
V_313 , F_259 , NULL ) ;
F_258 ( V_14 ) ;
return V_34 ;
}
static int F_294 ( struct V_71 * V_72 ,
struct V_14 * V_14 , T_4 V_274 )
{
return F_295 ( & V_267 , F_260 ( V_14 -> V_3 ) ,
V_72 , 0 , 0 , V_35 ) ;
}
static int F_289 ( struct V_14 * V_14 ,
struct V_111 * V_300 )
{
return F_274 ( V_14 , 0 , 0 , 0 , F_294 ,
V_300 ) ;
}
static int F_296 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
return F_291 ( V_14 , 0 , 0 , 0 , F_294 ,
V_5 ) ;
}
static int F_297 ( void )
{
return F_298 ( & V_267 , V_343 ,
V_344 ) ;
}
static void F_299 ( void )
{
F_300 ( & V_267 ) ;
}
static void F_37 ( struct V_14 * V_14 )
{
int V_34 ;
struct V_28 * V_29 ;
F_280 ( V_300 ) ;
F_17 (opt_inst, &team->option_inst_list, list) {
if ( V_29 -> V_38 )
F_25 ( & V_29 -> V_304 , & V_300 ) ;
}
V_34 = F_289 ( V_14 , & V_300 ) ;
if ( V_34 && V_34 != - V_345 )
F_301 ( V_14 -> V_3 , L_29 ,
V_34 ) ;
}
static void F_302 ( struct V_1 * V_5 , bool V_18 )
{
int V_34 ;
V_5 -> V_38 = true ;
V_5 -> V_23 . V_18 = V_18 ;
F_15 ( V_5 ) ;
if ( V_18 ) {
struct V_346 V_347 ;
V_34 = F_303 ( V_5 -> V_3 , & V_347 ) ;
if ( ! V_34 ) {
V_5 -> V_23 . V_337 = F_304 ( & V_347 ) ;
V_5 -> V_23 . V_339 = V_347 . V_339 ;
goto V_348;
}
}
V_5 -> V_23 . V_337 = 0 ;
V_5 -> V_23 . V_339 = 0 ;
V_348:
V_34 = F_296 ( V_5 -> V_14 , V_5 ) ;
if ( V_34 && V_34 != - V_345 )
F_301 ( V_5 -> V_14 -> V_3 , L_30 ,
V_5 -> V_3 -> V_27 , V_34 ) ;
}
static void F_170 ( struct V_14 * V_14 )
{
struct V_1 * V_5 ;
bool V_349 ;
if ( V_14 -> V_75 )
return;
V_349 = false ;
F_17 (port, &team->port_list, list) {
if ( V_5 -> V_18 ) {
V_349 = true ;
break;
}
}
if ( V_349 )
F_230 ( V_14 -> V_3 ) ;
else
F_187 ( V_14 -> V_3 ) ;
}
static void F_305 ( struct V_1 * V_5 , bool V_18 )
{
if ( V_5 -> V_23 . V_18 != V_18 )
F_302 ( V_5 , V_18 ) ;
F_170 ( V_5 -> V_14 ) ;
}
static void F_146 ( struct V_1 * V_5 , bool V_18 )
{
F_302 ( V_5 , V_18 ) ;
F_170 ( V_5 -> V_14 ) ;
}
static void F_154 ( struct V_1 * V_5 )
{
V_5 -> V_39 = true ;
F_302 ( V_5 , false ) ;
F_170 ( V_5 -> V_14 ) ;
}
static void F_306 ( struct V_1 * V_5 , bool V_18 )
{
struct V_14 * V_14 = V_5 -> V_14 ;
F_123 ( & V_14 -> V_144 ) ;
F_305 ( V_5 , V_18 ) ;
F_124 ( & V_14 -> V_144 ) ;
}
static int F_307 ( struct V_350 * V_183 ,
unsigned long V_351 , void * V_290 )
{
struct V_2 * V_3 = F_308 ( V_290 ) ;
struct V_1 * V_5 ;
V_5 = F_3 ( V_3 ) ;
if ( ! V_5 )
return V_352 ;
switch ( V_351 ) {
case V_353 :
if ( F_147 ( V_3 ) )
F_306 ( V_5 , true ) ;
break;
case V_354 :
F_306 ( V_5 , false ) ;
break;
case V_355 :
if ( F_77 ( V_5 -> V_3 ) )
F_306 ( V_5 ,
! ! F_147 ( V_5 -> V_3 ) ) ;
break;
case V_356 :
F_226 ( V_5 -> V_14 -> V_3 , V_3 ) ;
break;
case V_357 :
F_122 ( V_5 -> V_14 ) ;
break;
case V_358 :
if ( ! V_5 -> V_14 -> V_212 )
return V_359 ;
break;
case V_233 :
return V_359 ;
case V_95 :
F_74 ( V_351 , V_5 -> V_14 -> V_3 ) ;
break;
}
return V_352 ;
}
static int T_12 F_309 ( void )
{
int V_34 ;
F_310 ( & V_360 ) ;
V_34 = F_311 ( & V_361 ) ;
if ( V_34 )
goto V_362;
V_34 = F_297 () ;
if ( V_34 )
goto V_363;
return 0 ;
V_363:
F_312 ( & V_361 ) ;
V_362:
F_313 ( & V_360 ) ;
return V_34 ;
}
static void T_13 F_314 ( void )
{
F_299 () ;
F_312 ( & V_361 ) ;
F_313 ( & V_360 ) ;
}
