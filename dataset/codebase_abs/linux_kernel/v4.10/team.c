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
} else if ( V_97 == V_100 ) {
F_92 ( V_14 -> V_102 -> V_110 ) ;
} else {
F_92 ( V_14 -> V_102 -> V_111 ) ;
}
return V_97 ;
}
static int F_93 ( struct V_14 * V_14 )
{
struct V_112 * V_113 ;
unsigned int V_114 = V_14 -> V_3 -> V_115 - 1 ;
unsigned int V_33 ;
if ( ! V_114 )
return 0 ;
V_113 = F_24 ( sizeof( struct V_112 ) * V_114 , V_35 ) ;
if ( ! V_113 )
return - V_36 ;
V_14 -> V_116 = V_113 ;
for ( V_33 = 0 ; V_33 < V_114 ; V_33 ++ )
F_94 ( V_113 ++ ) ;
return 0 ;
}
static void F_95 ( struct V_14 * V_14 )
{
F_20 ( V_14 -> V_116 ) ;
}
static struct V_112 * F_96 ( struct V_14 * V_14 , T_3 V_117 )
{
return & V_14 -> V_116 [ V_117 - 1 ] ;
}
static bool F_97 ( struct V_14 * V_14 , struct V_71 * V_72 )
{
struct V_112 * V_118 ;
struct V_1 * V_5 ;
if ( ! V_14 -> V_119 || ! V_72 -> V_120 )
return false ;
V_118 = F_96 ( V_14 , V_72 -> V_120 ) ;
F_98 (port, qom_list, qom_list) {
if ( ! F_99 ( V_14 , V_5 , V_72 ) )
return true ;
}
return false ;
}
static void F_100 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
if ( ! V_5 -> V_117 )
return;
F_101 ( & V_5 -> V_118 ) ;
}
static bool F_102 ( struct V_1 * V_5 ,
struct V_1 * V_121 )
{
if ( V_5 -> V_122 < V_121 -> V_122 )
return true ;
if ( V_5 -> V_122 > V_121 -> V_122 )
return false ;
if ( V_5 -> V_123 < V_121 -> V_123 )
return true ;
return false ;
}
static void F_103 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
struct V_1 * V_121 ;
struct V_112 * V_118 ;
struct V_112 * V_124 ;
if ( ! V_5 -> V_117 )
return;
V_118 = F_96 ( V_14 , V_5 -> V_117 ) ;
V_124 = V_118 ;
F_17 (cur, qom_list, qom_list) {
if ( F_102 ( V_5 , V_121 ) )
break;
V_124 = & V_121 -> V_118 ;
}
F_104 ( & V_5 -> V_118 , V_124 ) ;
}
static void F_105 ( struct V_14 * V_14 )
{
struct V_1 * V_5 ;
bool V_125 = false ;
F_17 (port, &team->port_list, list) {
if ( V_5 -> V_117 ) {
V_125 = true ;
break;
}
}
if ( V_125 == V_14 -> V_119 )
return;
F_106 ( V_14 -> V_3 , L_7 ,
V_125 ? L_8 : L_9 ) ;
V_14 -> V_119 = V_125 ;
}
static void F_107 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
if ( ! V_5 -> V_117 || F_13 ( V_5 ) )
return;
F_100 ( V_14 , V_5 ) ;
F_103 ( V_14 , V_5 ) ;
F_105 ( V_14 ) ;
}
static void F_108 ( struct V_14 * V_14 ,
struct V_1 * V_5 ,
T_3 V_126 )
{
if ( F_13 ( V_5 ) ) {
F_100 ( V_14 , V_5 ) ;
V_5 -> V_117 = V_126 ;
F_103 ( V_14 , V_5 ) ;
F_105 ( V_14 ) ;
} else {
V_5 -> V_117 = V_126 ;
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
struct V_1 * V_121 ;
F_17 (cur, &team->port_list, list)
if ( V_121 == V_5 )
return true ;
return false ;
}
static void F_112 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
if ( F_13 ( V_5 ) )
return;
V_5 -> V_123 = V_14 -> V_76 ++ ;
F_113 ( & V_5 -> V_127 ,
F_114 ( V_14 , V_5 -> V_123 ) ) ;
F_61 ( V_14 ) ;
F_109 ( V_14 , V_5 ) ;
if ( V_14 -> V_77 . V_128 )
V_14 -> V_77 . V_128 ( V_14 , V_5 ) ;
F_76 ( V_14 ) ;
F_84 ( V_14 ) ;
F_12 ( V_5 ) ;
}
static void F_115 ( struct V_14 * V_14 , int V_129 )
{
int V_33 ;
struct V_1 * V_5 ;
for ( V_33 = V_129 + 1 ; V_33 < V_14 -> V_76 ; V_33 ++ ) {
V_5 = F_116 ( V_14 , V_33 ) ;
F_117 ( & V_5 -> V_127 ) ;
V_5 -> V_123 -- ;
F_113 ( & V_5 -> V_127 ,
F_114 ( V_14 , V_5 -> V_123 ) ) ;
}
}
static void F_118 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
if ( ! F_13 ( V_5 ) )
return;
if ( V_14 -> V_77 . V_130 )
V_14 -> V_77 . V_130 ( V_14 , V_5 ) ;
F_117 ( & V_5 -> V_127 ) ;
F_115 ( V_14 , V_5 -> V_123 ) ;
V_5 -> V_123 = - 1 ;
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
T_4 V_131 = V_132 & V_133 ;
T_5 V_134 = V_135 ;
unsigned short V_136 = V_137 ;
unsigned int V_138 = V_139 |
V_140 ;
F_17 (port, &team->port_list, list) {
V_131 = F_120 ( V_131 ,
V_5 -> V_3 -> V_131 ,
V_132 ) ;
V_134 =
F_120 ( V_134 ,
V_5 -> V_3 -> V_141 ,
V_135 ) ;
V_138 &= V_5 -> V_3 -> V_142 ;
if ( V_5 -> V_3 -> V_143 > V_136 )
V_136 = V_5 -> V_3 -> V_143 ;
}
V_14 -> V_3 -> V_131 = V_131 ;
V_14 -> V_3 -> V_141 = V_134 | V_144 ;
V_14 -> V_3 -> V_143 = V_136 ;
V_14 -> V_3 -> V_142 &= ~ V_139 ;
if ( V_138 == ( V_139 | V_140 ) )
V_14 -> V_3 -> V_142 |= V_139 ;
}
static void F_121 ( struct V_14 * V_14 )
{
F_119 ( V_14 ) ;
F_122 ( V_14 -> V_3 ) ;
}
static void F_123 ( struct V_14 * V_14 )
{
F_124 ( & V_14 -> V_145 ) ;
F_119 ( V_14 ) ;
F_125 ( & V_14 -> V_145 ) ;
F_122 ( V_14 -> V_3 ) ;
}
static int F_126 ( struct V_14 * V_14 , struct V_1 * V_5 )
{
int V_34 = 0 ;
F_127 ( V_14 -> V_3 ) ;
if ( V_14 -> V_77 . V_146 ) {
V_34 = V_14 -> V_77 . V_146 ( V_14 , V_5 ) ;
if ( V_34 ) {
F_67 ( V_14 -> V_3 , L_10 ,
V_5 -> V_3 -> V_27 ) ;
goto V_147;
}
}
return 0 ;
V_147:
F_128 ( V_14 -> V_3 ) ;
return V_34 ;
}
static void F_129 ( struct V_14 * V_14 , struct V_1 * V_5 )
{
if ( V_14 -> V_77 . V_148 )
V_14 -> V_77 . V_148 ( V_14 , V_5 ) ;
F_128 ( V_14 -> V_3 ) ;
}
static int F_130 ( struct V_14 * V_14 , struct V_1 * V_5 )
{
struct V_149 * V_150 ;
int V_34 ;
if ( ! V_14 -> V_3 -> V_151 )
return 0 ;
V_150 = F_32 ( sizeof( * V_150 ) , V_35 ) ;
if ( ! V_150 )
return - V_36 ;
V_34 = F_131 ( V_150 , V_5 -> V_3 ) ;
if ( V_34 ) {
F_20 ( V_150 ) ;
return V_34 ;
}
V_5 -> V_150 = V_150 ;
return V_34 ;
}
static void F_132 ( struct V_1 * V_5 )
{
struct V_149 * V_150 = V_5 -> V_150 ;
if ( ! V_150 )
return;
V_5 -> V_150 = NULL ;
F_133 () ;
F_134 ( V_150 ) ;
F_20 ( V_150 ) ;
}
static int F_130 ( struct V_14 * V_14 , struct V_1 * V_5 )
{
return 0 ;
}
static void F_132 ( struct V_1 * V_5 )
{
}
static int F_135 ( struct V_14 * V_14 , struct V_1 * V_5 )
{
struct V_152 V_153 ;
int V_34 ;
V_153 . V_154 = V_14 -> V_62 -> V_155 ;
V_34 = F_136 ( V_5 -> V_3 , V_14 -> V_3 , NULL ,
& V_153 ) ;
if ( V_34 )
return V_34 ;
V_5 -> V_3 -> V_142 |= V_156 ;
return 0 ;
}
static void F_137 ( struct V_14 * V_14 , struct V_1 * V_5 )
{
F_138 ( V_5 -> V_3 , V_14 -> V_3 ) ;
V_5 -> V_3 -> V_142 &= ~ V_156 ;
}
static int F_139 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_5 ;
char * V_157 = V_6 -> V_27 ;
int V_34 ;
if ( V_6 -> V_158 & V_159 ) {
F_67 ( V_3 , L_11 ,
V_157 ) ;
return - V_66 ;
}
if ( F_5 ( V_6 ) ) {
F_67 ( V_3 , L_12
L_13 , V_157 ) ;
return - V_84 ;
}
if ( V_6 -> V_160 & V_161 &&
F_140 ( V_3 ) ) {
F_67 ( V_3 , L_14 ,
V_157 ) ;
return - V_162 ;
}
V_34 = F_141 ( V_3 , V_6 ) ;
if ( V_34 )
return V_34 ;
if ( V_6 -> V_158 & V_163 ) {
F_67 ( V_3 , L_15 ,
V_157 ) ;
return - V_84 ;
}
V_5 = F_32 ( sizeof( struct V_1 ) + V_14 -> V_62 -> V_164 ,
V_35 ) ;
if ( ! V_5 )
return - V_36 ;
V_5 -> V_3 = V_6 ;
V_5 -> V_14 = V_14 ;
F_94 ( & V_5 -> V_118 ) ;
V_5 -> V_13 . V_165 = V_6 -> V_165 ;
V_34 = F_142 ( V_6 , V_3 -> V_165 ) ;
if ( V_34 ) {
F_106 ( V_3 , L_16 , V_34 ) ;
goto V_166;
}
memcpy ( V_5 -> V_13 . V_7 , V_6 -> V_7 , V_6 -> V_11 ) ;
V_34 = F_126 ( V_14 , V_5 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_10 ,
V_157 ) ;
goto V_147;
}
V_34 = F_143 ( V_6 ) ;
if ( V_34 ) {
F_106 ( V_3 , L_17 ,
V_157 ) ;
goto V_167;
}
F_144 ( V_3 ) ;
F_145 ( V_6 , V_3 ) ;
F_146 ( V_6 , V_3 ) ;
F_147 ( V_3 ) ;
V_34 = F_148 ( V_6 , V_3 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_18 ,
V_157 ) ;
goto V_168;
}
V_34 = F_130 ( V_14 , V_5 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_19 ,
V_157 ) ;
goto V_169;
}
if ( ! ( V_3 -> V_160 & V_170 ) )
F_149 ( V_6 ) ;
V_34 = F_150 ( V_6 , F_87 ,
V_5 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_20 ,
V_157 ) ;
goto V_171;
}
V_34 = F_135 ( V_14 , V_5 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_21 ,
V_157 ) ;
goto V_172;
}
V_34 = F_29 ( V_14 , V_5 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_22 ,
V_157 ) ;
goto V_173;
}
V_5 -> V_123 = - 1 ;
F_104 ( & V_5 -> V_30 , & V_14 -> V_83 ) ;
F_112 ( V_14 , V_5 ) ;
F_121 ( V_14 ) ;
F_151 ( V_5 , ! ! F_152 ( V_6 ) ) ;
F_37 ( V_14 ) ;
F_68 ( V_3 , L_23 , V_157 ) ;
return 0 ;
V_173:
F_137 ( V_14 , V_5 ) ;
V_172:
F_153 ( V_6 ) ;
V_171:
F_132 ( V_5 ) ;
V_169:
F_154 ( V_6 , V_3 ) ;
V_168:
F_155 ( V_6 , V_3 ) ;
F_156 ( V_6 , V_3 ) ;
F_157 ( V_6 ) ;
V_167:
F_129 ( V_14 , V_5 ) ;
F_8 ( V_5 ) ;
V_147:
F_142 ( V_6 , V_5 -> V_13 . V_165 ) ;
V_166:
F_20 ( V_5 ) ;
return V_34 ;
}
static int F_158 ( struct V_14 * V_14 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_14 -> V_3 ;
struct V_1 * V_5 ;
char * V_157 = V_6 -> V_27 ;
V_5 = F_3 ( V_6 ) ;
if ( ! V_5 || ! F_111 ( V_14 , V_5 ) ) {
F_67 ( V_3 , L_24 ,
V_157 ) ;
return - V_174 ;
}
F_118 ( V_14 , V_5 ) ;
F_101 ( & V_5 -> V_30 ) ;
F_137 ( V_14 , V_5 ) ;
F_153 ( V_6 ) ;
F_132 ( V_5 ) ;
F_154 ( V_6 , V_3 ) ;
F_155 ( V_6 , V_3 ) ;
F_156 ( V_6 , V_3 ) ;
F_157 ( V_6 ) ;
F_129 ( V_14 , V_5 ) ;
F_30 ( V_14 , V_5 ) ;
F_37 ( V_14 ) ;
F_28 ( V_14 , V_5 ) ;
F_159 ( V_5 ) ;
F_8 ( V_5 ) ;
F_142 ( V_6 , V_5 -> V_13 . V_165 ) ;
F_160 ( V_5 , V_175 ) ;
F_68 ( V_3 , L_25 , V_157 ) ;
F_121 ( V_14 ) ;
return 0 ;
}
static int F_161 ( struct V_14 * V_14 , struct V_52 * V_53 )
{
V_53 -> V_176 . V_177 = V_14 -> V_62 -> V_60 ;
return 0 ;
}
static int F_162 ( struct V_14 * V_14 , struct V_52 * V_53 )
{
return F_65 ( V_14 , V_53 -> V_176 . V_177 ) ;
}
static int F_163 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
V_53 -> V_176 . V_178 = V_14 -> V_88 . V_93 ;
return 0 ;
}
static int F_164 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
V_14 -> V_88 . V_93 = V_53 -> V_176 . V_178 ;
return 0 ;
}
static int F_165 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
V_53 -> V_176 . V_178 = V_14 -> V_88 . V_92 ;
return 0 ;
}
static int F_166 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
V_14 -> V_88 . V_92 = V_53 -> V_176 . V_178 ;
return 0 ;
}
static int F_167 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
V_53 -> V_176 . V_178 = V_14 -> V_94 . V_93 ;
return 0 ;
}
static int F_168 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
V_14 -> V_94 . V_93 = V_53 -> V_176 . V_178 ;
return 0 ;
}
static int F_169 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
V_53 -> V_176 . V_178 = V_14 -> V_94 . V_92 ;
return 0 ;
}
static int F_170 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
V_14 -> V_94 . V_92 = V_53 -> V_176 . V_178 ;
return 0 ;
}
static int F_171 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
V_53 -> V_176 . V_179 = F_13 ( V_5 ) ;
return 0 ;
}
static int F_172 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
if ( V_53 -> V_176 . V_179 )
F_112 ( V_14 , V_5 ) ;
else
F_118 ( V_14 , V_5 ) ;
return 0 ;
}
static int F_173 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
V_53 -> V_176 . V_179 = V_5 -> V_21 . V_18 ;
return 0 ;
}
static int F_174 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
V_5 -> V_21 . V_18 = V_53 -> V_176 . V_179 ;
F_15 ( V_5 ) ;
F_175 ( V_5 -> V_14 ) ;
return 0 ;
}
static int F_176 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
V_53 -> V_176 . V_179 = V_5 -> V_21 . V_22 ;
return 0 ;
}
static int F_177 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
V_5 -> V_21 . V_22 = V_53 -> V_176 . V_179 ;
F_15 ( V_5 ) ;
F_175 ( V_5 -> V_14 ) ;
return 0 ;
}
static int F_178 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
V_53 -> V_176 . V_180 = V_5 -> V_122 ;
return 0 ;
}
static int F_179 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
T_6 V_122 = V_53 -> V_176 . V_180 ;
if ( V_5 -> V_122 == V_122 )
return 0 ;
V_5 -> V_122 = V_122 ;
F_107 ( V_14 , V_5 ) ;
return 0 ;
}
static int F_180 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
V_53 -> V_176 . V_178 = V_5 -> V_117 ;
return 0 ;
}
static int F_181 ( struct V_14 * V_14 ,
struct V_52 * V_53 )
{
struct V_1 * V_5 = V_53 -> V_16 -> V_5 ;
T_3 V_126 = V_53 -> V_176 . V_178 ;
if ( V_5 -> V_117 == V_126 )
return 0 ;
if ( V_126 >= V_14 -> V_3 -> V_181 )
return - V_66 ;
F_108 ( V_14 , V_5 , V_126 ) ;
return 0 ;
}
static int F_182 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_183 ( V_3 ) ;
int V_33 ;
int V_34 ;
V_14 -> V_3 = V_3 ;
F_184 ( & V_14 -> V_145 ) ;
F_60 ( V_14 ) ;
V_14 -> V_102 = F_185 ( struct V_101 ) ;
if ( ! V_14 -> V_102 )
return - V_36 ;
for ( V_33 = 0 ; V_33 < V_182 ; V_33 ++ )
F_186 ( & V_14 -> V_183 [ V_33 ] ) ;
F_94 ( & V_14 -> V_83 ) ;
V_34 = F_93 ( V_14 ) ;
if ( V_34 )
goto V_184;
F_61 ( V_14 ) ;
F_94 ( & V_14 -> V_50 ) ;
F_94 ( & V_14 -> V_40 ) ;
F_79 ( V_14 ) ;
F_85 ( V_14 ) ;
V_34 = F_36 ( V_14 , V_185 , F_187 ( V_185 ) ) ;
if ( V_34 )
goto V_186;
F_188 ( V_3 ) ;
F_189 ( V_3 ) ;
return 0 ;
V_186:
F_86 ( V_14 ) ;
F_81 ( V_14 ) ;
F_95 ( V_14 ) ;
V_184:
F_190 ( V_14 -> V_102 ) ;
return V_34 ;
}
static void F_191 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_183 ( V_3 ) ;
struct V_1 * V_5 ;
struct V_1 * V_31 ;
F_124 ( & V_14 -> V_145 ) ;
F_22 (port, tmp, &team->port_list, list)
F_158 ( V_14 , V_5 -> V_3 ) ;
F_62 ( V_14 , NULL ) ;
F_35 ( V_14 , V_185 , F_187 ( V_185 ) ) ;
F_86 ( V_14 ) ;
F_81 ( V_14 ) ;
F_95 ( V_14 ) ;
F_125 ( & V_14 -> V_145 ) ;
}
static void F_192 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_183 ( V_3 ) ;
F_190 ( V_14 -> V_102 ) ;
F_193 ( V_3 ) ;
}
static int F_194 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_195 ( struct V_2 * V_3 )
{
return 0 ;
}
static T_7 F_196 ( struct V_71 * V_72 , struct V_2 * V_3 )
{
struct V_14 * V_14 = F_183 ( V_3 ) ;
bool V_187 ;
unsigned int V_106 = V_72 -> V_106 ;
V_187 = F_97 ( V_14 , V_72 ) ;
if ( ! V_187 )
V_187 = V_14 -> V_77 . V_78 ( V_14 , V_72 ) ;
if ( V_187 ) {
struct V_101 * V_102 ;
V_102 = F_89 ( V_14 -> V_102 ) ;
F_90 ( & V_102 -> V_103 ) ;
V_102 -> V_188 ++ ;
V_102 -> V_189 += V_106 ;
F_91 ( & V_102 -> V_103 ) ;
} else {
F_92 ( V_14 -> V_102 -> V_190 ) ;
}
return V_191 ;
}
static T_3 F_197 ( struct V_2 * V_3 , struct V_71 * V_72 ,
void * V_192 , T_8 V_193 )
{
T_3 V_194 = F_198 ( V_72 ) ? F_199 ( V_72 ) : 0 ;
F_200 ( V_72 ) -> V_195 = V_72 -> V_120 ;
if ( F_201 ( V_194 >= V_3 -> V_181 ) ) {
do {
V_194 -= V_3 -> V_181 ;
} while ( V_194 >= V_3 -> V_181 );
}
return V_194 ;
}
static void F_202 ( struct V_2 * V_3 , int V_196 )
{
struct V_14 * V_14 = F_183 ( V_3 ) ;
struct V_1 * V_5 ;
int V_197 ;
F_203 () ;
F_98 (port, &team->port_list, list) {
if ( V_196 & V_198 ) {
V_197 = V_3 -> V_158 & V_198 ? 1 : - 1 ;
F_204 ( V_5 -> V_3 , V_197 ) ;
}
if ( V_196 & V_199 ) {
V_197 = V_3 -> V_158 & V_199 ? 1 : - 1 ;
F_205 ( V_5 -> V_3 , V_197 ) ;
}
}
F_206 () ;
}
static void F_207 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_183 ( V_3 ) ;
struct V_1 * V_5 ;
F_203 () ;
F_98 (port, &team->port_list, list) {
F_145 ( V_5 -> V_3 , V_3 ) ;
F_146 ( V_5 -> V_3 , V_3 ) ;
}
F_206 () ;
}
static int F_208 ( struct V_2 * V_3 , void * V_200 )
{
struct V_8 * V_9 = V_200 ;
struct V_14 * V_14 = F_183 ( V_3 ) ;
struct V_1 * V_5 ;
if ( V_3 -> type == V_201 && ! F_209 ( V_9 -> V_10 ) )
return - V_202 ;
memcpy ( V_3 -> V_7 , V_9 -> V_10 , V_3 -> V_11 ) ;
F_124 ( & V_14 -> V_145 ) ;
F_17 (port, &team->port_list, list)
if ( V_14 -> V_77 . V_203 )
V_14 -> V_77 . V_203 ( V_14 , V_5 ) ;
F_125 ( & V_14 -> V_145 ) ;
return 0 ;
}
static int F_210 ( struct V_2 * V_3 , int V_204 )
{
struct V_14 * V_14 = F_183 ( V_3 ) ;
struct V_1 * V_5 ;
int V_34 ;
F_124 ( & V_14 -> V_145 ) ;
V_14 -> V_205 = true ;
F_17 (port, &team->port_list, list) {
V_34 = F_142 ( V_5 -> V_3 , V_204 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_26 ,
V_5 -> V_3 -> V_27 ) ;
goto V_206;
}
}
V_14 -> V_205 = false ;
F_125 ( & V_14 -> V_145 ) ;
V_3 -> V_165 = V_204 ;
return 0 ;
V_206:
F_211 (port, &team->port_list, list)
F_142 ( V_5 -> V_3 , V_3 -> V_165 ) ;
V_14 -> V_205 = false ;
F_125 ( & V_14 -> V_145 ) ;
return V_34 ;
}
static struct V_207 *
F_212 ( struct V_2 * V_3 , struct V_207 * V_208 )
{
struct V_14 * V_14 = F_183 ( V_3 ) ;
struct V_101 * V_200 ;
T_9 V_104 , V_105 , V_109 , V_188 , V_189 ;
T_4 V_111 = 0 , V_190 = 0 , V_110 = 0 ;
unsigned int V_209 ;
int V_33 ;
F_213 (i) {
V_200 = F_214 ( V_14 -> V_102 , V_33 ) ;
do {
V_209 = F_215 ( & V_200 -> V_103 ) ;
V_104 = V_200 -> V_104 ;
V_105 = V_200 -> V_105 ;
V_109 = V_200 -> V_109 ;
V_188 = V_200 -> V_188 ;
V_189 = V_200 -> V_189 ;
} while ( F_216 ( & V_200 -> V_103 , V_209 ) );
V_208 -> V_104 += V_104 ;
V_208 -> V_105 += V_105 ;
V_208 -> V_210 += V_109 ;
V_208 -> V_188 += V_188 ;
V_208 -> V_189 += V_189 ;
V_111 += V_200 -> V_111 ;
V_190 += V_200 -> V_190 ;
V_110 += V_200 -> V_110 ;
}
V_208 -> V_111 = V_111 ;
V_208 -> V_190 = V_190 ;
V_208 -> V_110 = V_110 ;
return V_208 ;
}
static int F_217 ( struct V_2 * V_3 , T_10 V_211 , T_3 V_212 )
{
struct V_14 * V_14 = F_183 ( V_3 ) ;
struct V_1 * V_5 ;
int V_34 ;
F_124 ( & V_14 -> V_145 ) ;
F_17 (port, &team->port_list, list) {
V_34 = F_218 ( V_5 -> V_3 , V_211 , V_212 ) ;
if ( V_34 )
goto V_206;
}
F_125 ( & V_14 -> V_145 ) ;
return 0 ;
V_206:
F_211 (port, &team->port_list, list)
F_219 ( V_5 -> V_3 , V_211 , V_212 ) ;
F_125 ( & V_14 -> V_145 ) ;
return V_34 ;
}
static int F_220 ( struct V_2 * V_3 , T_10 V_211 , T_3 V_212 )
{
struct V_14 * V_14 = F_183 ( V_3 ) ;
struct V_1 * V_5 ;
F_124 ( & V_14 -> V_145 ) ;
F_17 (port, &team->port_list, list)
F_219 ( V_5 -> V_3 , V_211 , V_212 ) ;
F_125 ( & V_14 -> V_145 ) ;
return 0 ;
}
static void F_221 ( struct V_2 * V_3 )
{
}
static void F_222 ( struct V_14 * V_14 )
{
struct V_1 * V_5 ;
F_17 (port, &team->port_list, list)
F_132 ( V_5 ) ;
}
static void F_223 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_183 ( V_3 ) ;
F_124 ( & V_14 -> V_145 ) ;
F_222 ( V_14 ) ;
F_125 ( & V_14 -> V_145 ) ;
}
static int F_224 ( struct V_2 * V_3 ,
struct V_213 * V_214 )
{
struct V_14 * V_14 = F_183 ( V_3 ) ;
struct V_1 * V_5 ;
int V_34 = 0 ;
F_124 ( & V_14 -> V_145 ) ;
F_17 (port, &team->port_list, list) {
V_34 = F_130 ( V_14 , V_5 ) ;
if ( V_34 ) {
F_222 ( V_14 ) ;
break;
}
}
F_125 ( & V_14 -> V_145 ) ;
return V_34 ;
}
static int F_225 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_183 ( V_3 ) ;
int V_34 ;
F_124 ( & V_14 -> V_145 ) ;
V_34 = F_139 ( V_14 , V_6 ) ;
F_125 ( & V_14 -> V_145 ) ;
return V_34 ;
}
static int F_226 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_183 ( V_3 ) ;
int V_34 ;
F_124 ( & V_14 -> V_145 ) ;
V_34 = F_158 ( V_14 , V_6 ) ;
F_125 ( & V_14 -> V_145 ) ;
return V_34 ;
}
static T_5 F_227 ( struct V_2 * V_3 ,
T_5 V_160 )
{
struct V_1 * V_5 ;
struct V_14 * V_14 = F_183 ( V_3 ) ;
T_5 V_215 ;
V_215 = V_160 ;
V_160 &= ~ V_216 ;
V_160 |= V_133 ;
F_203 () ;
F_98 (port, &team->port_list, list) {
V_160 = F_120 ( V_160 ,
V_5 -> V_3 -> V_160 ,
V_215 ) ;
}
F_206 () ;
V_160 = F_228 ( V_160 , V_215 ) ;
return V_160 ;
}
static int F_229 ( struct V_2 * V_3 , bool V_217 )
{
struct V_14 * V_14 = F_183 ( V_3 ) ;
V_14 -> V_75 = true ;
if ( V_217 )
F_230 ( V_3 ) ;
else
F_188 ( V_3 ) ;
return 0 ;
}
static void F_231 ( struct V_2 * V_3 ,
struct V_218 * V_219 )
{
F_232 ( V_219 -> V_220 , V_221 , sizeof( V_219 -> V_220 ) ) ;
F_232 ( V_219 -> V_222 , V_223 , sizeof( V_219 -> V_222 ) ) ;
}
static void F_233 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
V_3 -> V_224 = V_6 -> V_224 ;
V_3 -> type = V_6 -> type ;
V_3 -> V_143 = V_6 -> V_143 ;
V_3 -> V_11 = V_6 -> V_11 ;
V_3 -> V_165 = V_6 -> V_165 ;
memcpy ( V_3 -> V_225 , V_6 -> V_225 , V_6 -> V_11 ) ;
F_234 ( V_3 , V_6 ) ;
}
static int F_141 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
struct V_14 * V_14 = F_183 ( V_3 ) ;
char * V_157 = V_6 -> V_27 ;
int V_34 ;
if ( V_3 -> type == V_6 -> type )
return 0 ;
if ( ! F_66 ( & V_14 -> V_83 ) ) {
F_67 ( V_3 , L_27 , V_157 ) ;
return - V_84 ;
}
V_34 = F_74 ( V_226 , V_3 ) ;
V_34 = F_235 ( V_34 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_28 ) ;
return V_34 ;
}
F_236 ( V_3 ) ;
F_237 ( V_3 ) ;
F_233 ( V_3 , V_6 ) ;
F_74 ( V_227 , V_3 ) ;
return 0 ;
}
static void F_238 ( struct V_2 * V_3 )
{
F_239 ( V_3 ) ;
V_3 -> V_228 = & V_229 ;
V_3 -> V_230 = & V_231 ;
V_3 -> V_232 = F_192 ;
V_3 -> V_142 &= ~ ( V_139 | V_233 ) ;
V_3 -> V_142 |= V_234 ;
V_3 -> V_142 |= V_235 ;
V_3 -> V_142 |= V_236 | V_237 ;
V_3 -> V_160 |= V_238 ;
V_3 -> V_160 |= V_239 ;
V_3 -> V_160 |= V_240 ;
V_3 -> V_241 = V_132 |
V_242 |
V_243 |
V_244 ;
V_3 -> V_241 |= V_144 ;
V_3 -> V_160 |= V_3 -> V_241 ;
}
static int F_240 ( struct V_245 * V_246 , struct V_2 * V_3 ,
struct V_247 * V_248 [] , struct V_247 * V_176 [] )
{
if ( V_248 [ V_249 ] == NULL )
F_241 ( V_3 ) ;
return F_242 ( V_3 ) ;
}
static int F_243 ( struct V_247 * V_248 [] , struct V_247 * V_176 [] )
{
if ( V_248 [ V_249 ] ) {
if ( F_244 ( V_248 [ V_249 ] ) != V_250 )
return - V_66 ;
if ( ! F_209 ( F_245 ( V_248 [ V_249 ] ) ) )
return - V_202 ;
}
return 0 ;
}
static unsigned int F_246 ( void )
{
return V_251 ;
}
static unsigned int F_247 ( void )
{
return V_252 ;
}
static int F_248 ( struct V_71 * V_72 , struct V_253 * V_16 )
{
struct V_71 * V_254 ;
void * V_255 ;
int V_34 ;
V_254 = F_249 ( V_256 , V_35 ) ;
if ( ! V_254 )
return - V_36 ;
V_255 = F_250 ( V_254 , V_16 -> V_257 , V_16 -> V_258 ,
& V_259 , 0 , V_260 ) ;
if ( ! V_255 ) {
V_34 = - V_261 ;
goto V_262;
}
F_251 ( V_254 , V_255 ) ;
return F_252 ( F_253 ( V_16 ) , V_254 , V_16 -> V_257 ) ;
V_262:
F_254 ( V_254 ) ;
return V_34 ;
}
static struct V_14 * F_255 ( struct V_253 * V_16 )
{
struct V_245 * V_245 = F_253 ( V_16 ) ;
int V_263 ;
struct V_2 * V_3 ;
struct V_14 * V_14 ;
if ( ! V_16 -> V_264 [ V_265 ] )
return NULL ;
V_263 = F_256 ( V_16 -> V_264 [ V_265 ] ) ;
V_3 = F_257 ( V_245 , V_263 ) ;
if ( ! V_3 || V_3 -> V_228 != & V_229 ) {
if ( V_3 )
F_128 ( V_3 ) ;
return NULL ;
}
V_14 = F_183 ( V_3 ) ;
F_124 ( & V_14 -> V_145 ) ;
return V_14 ;
}
static void F_258 ( struct V_14 * V_14 )
{
F_125 ( & V_14 -> V_145 ) ;
F_128 ( V_14 -> V_3 ) ;
}
static int F_259 ( struct V_71 * V_72 , struct V_14 * V_14 , T_4 V_266 )
{
return F_252 ( F_260 ( V_14 -> V_3 ) , V_72 , V_266 ) ;
}
static int F_261 ( struct V_71 * V_72 , struct V_14 * V_14 ,
struct V_28 * V_29 )
{
struct V_247 * V_267 ;
struct V_24 * V_26 = V_29 -> V_26 ;
struct V_57 * V_58 = & V_29 -> V_16 ;
struct V_52 V_53 ;
int V_34 ;
V_53 . V_16 = V_58 ;
V_34 = F_39 ( V_14 , V_29 , & V_53 ) ;
if ( V_34 )
return V_34 ;
V_267 = F_262 ( V_72 , V_268 ) ;
if ( ! V_267 )
return - V_261 ;
if ( F_263 ( V_72 , V_269 , V_26 -> V_27 ) )
goto V_270;
if ( V_58 -> V_5 &&
F_264 ( V_72 , V_271 ,
V_58 -> V_5 -> V_3 -> V_263 ) )
goto V_270;
if ( V_29 -> V_26 -> V_32 &&
F_264 ( V_72 , V_272 ,
V_58 -> V_37 ) )
goto V_270;
switch ( V_26 -> type ) {
case V_273 :
if ( F_265 ( V_72 , V_274 , V_275 ) )
goto V_270;
if ( F_264 ( V_72 , V_276 , V_53 . V_176 . V_178 ) )
goto V_270;
break;
case V_277 :
if ( F_265 ( V_72 , V_274 , V_278 ) )
goto V_270;
if ( F_263 ( V_72 , V_276 ,
V_53 . V_176 . V_177 ) )
goto V_270;
break;
case V_279 :
if ( F_265 ( V_72 , V_274 , V_280 ) )
goto V_270;
if ( F_266 ( V_72 , V_276 , V_53 . V_176 . V_281 . V_106 ,
V_53 . V_176 . V_281 . V_282 ) )
goto V_270;
break;
case V_283 :
if ( F_265 ( V_72 , V_274 , V_284 ) )
goto V_270;
if ( V_53 . V_176 . V_179 &&
F_267 ( V_72 , V_276 ) )
goto V_270;
break;
case V_285 :
if ( F_265 ( V_72 , V_274 , V_286 ) )
goto V_270;
if ( F_268 ( V_72 , V_276 , V_53 . V_176 . V_180 ) )
goto V_270;
break;
default:
F_269 () ;
}
if ( V_29 -> V_39 && F_267 ( V_72 , V_287 ) )
goto V_270;
if ( V_29 -> V_38 ) {
if ( F_267 ( V_72 , V_288 ) )
goto V_270;
V_29 -> V_38 = false ;
}
F_270 ( V_72 , V_267 ) ;
return 0 ;
V_270:
F_271 ( V_72 , V_267 ) ;
return - V_261 ;
}
static int F_272 ( struct V_71 * * V_96 ,
struct V_14 * V_14 , T_4 V_266 ,
T_11 * V_289 )
{
int V_34 ;
if ( * V_96 ) {
V_34 = V_289 ( * V_96 , V_14 , V_266 ) ;
if ( V_34 )
return V_34 ;
}
* V_96 = F_273 ( V_290 , V_35 ) ;
if ( ! * V_96 )
return - V_36 ;
return 0 ;
}
static int F_274 ( struct V_14 * V_14 , T_4 V_266 , T_4 V_291 ,
int V_158 , T_11 * V_289 ,
struct V_112 * V_292 )
{
struct V_247 * V_50 ;
struct V_293 * V_294 ;
void * V_255 ;
struct V_28 * V_29 ;
int V_34 ;
struct V_71 * V_72 = NULL ;
bool V_295 ;
int V_33 ;
V_29 = F_275 ( V_292 ,
struct V_28 , V_296 ) ;
V_297:
V_34 = F_272 ( & V_72 , V_14 , V_266 , V_289 ) ;
if ( V_34 )
return V_34 ;
V_255 = F_250 ( V_72 , V_266 , V_291 , & V_259 , V_158 | V_298 ,
V_299 ) ;
if ( ! V_255 )
return - V_261 ;
if ( F_264 ( V_72 , V_265 , V_14 -> V_3 -> V_263 ) )
goto V_300;
V_50 = F_262 ( V_72 , V_301 ) ;
if ( ! V_50 )
goto V_300;
V_33 = 0 ;
V_295 = false ;
F_276 (opt_inst, sel_opt_inst_list, tmp_list) {
V_34 = F_261 ( V_72 , V_14 , V_29 ) ;
if ( V_34 ) {
if ( V_34 == - V_261 ) {
if ( ! V_33 )
goto V_302;
V_295 = true ;
break;
}
goto V_302;
}
V_33 ++ ;
}
F_270 ( V_72 , V_50 ) ;
F_251 ( V_72 , V_255 ) ;
if ( V_295 )
goto V_297;
V_303:
V_294 = F_277 ( V_72 , V_266 , V_291 , V_304 , 0 , V_158 | V_298 ) ;
if ( ! V_294 ) {
V_34 = F_272 ( & V_72 , V_14 , V_266 , V_289 ) ;
if ( V_34 )
goto V_302;
goto V_303;
}
return V_289 ( V_72 , V_14 , V_266 ) ;
V_300:
V_34 = - V_261 ;
V_302:
F_278 ( V_72 , V_255 ) ;
F_254 ( V_72 ) ;
return V_34 ;
}
static int F_279 ( struct V_71 * V_72 , struct V_253 * V_16 )
{
struct V_14 * V_14 ;
struct V_28 * V_29 ;
int V_34 ;
F_280 ( V_292 ) ;
V_14 = F_255 ( V_16 ) ;
if ( ! V_14 )
return - V_66 ;
F_17 (opt_inst, &team->option_inst_list, list)
F_25 ( & V_29 -> V_296 , & V_292 ) ;
V_34 = F_274 ( V_14 , V_16 -> V_257 , V_16 -> V_258 ,
V_305 , F_259 ,
& V_292 ) ;
F_258 ( V_14 ) ;
return V_34 ;
}
static int F_281 ( struct V_71 * V_72 , struct V_253 * V_16 )
{
struct V_14 * V_14 ;
int V_34 = 0 ;
int V_33 ;
struct V_247 * V_306 ;
F_280 ( V_307 ) ;
F_282 () ;
V_14 = F_255 ( V_16 ) ;
if ( ! V_14 ) {
V_34 = - V_66 ;
goto F_73;
}
V_34 = - V_66 ;
if ( ! V_16 -> V_264 [ V_301 ] ) {
V_34 = - V_66 ;
goto V_308;
}
F_283 (nl_option, info->attrs[TEAM_ATTR_LIST_OPTION], i) {
struct V_247 * V_309 [ V_310 + 1 ] ;
struct V_247 * V_311 ;
struct V_247 * V_312 ;
enum V_313 V_314 ;
int V_315 = 0 ;
T_4 V_316 = 0 ;
bool V_317 = false ;
struct V_28 * V_29 ;
char * V_25 ;
bool V_318 = false ;
if ( F_284 ( V_306 ) != V_268 ) {
V_34 = - V_66 ;
goto V_308;
}
V_34 = F_285 ( V_309 , V_310 ,
V_306 , V_319 ) ;
if ( V_34 )
goto V_308;
if ( ! V_309 [ V_269 ] ||
! V_309 [ V_274 ] ) {
V_34 = - V_66 ;
goto V_308;
}
switch ( F_286 ( V_309 [ V_274 ] ) ) {
case V_275 :
V_314 = V_273 ;
break;
case V_278 :
V_314 = V_277 ;
break;
case V_280 :
V_314 = V_279 ;
break;
case V_284 :
V_314 = V_283 ;
break;
case V_286 :
V_314 = V_285 ;
break;
default:
goto V_308;
}
V_312 = V_309 [ V_276 ] ;
if ( V_314 != V_283 && ! V_312 ) {
V_34 = - V_66 ;
goto V_308;
}
V_25 = F_245 ( V_309 [ V_269 ] ) ;
V_311 = V_309 [ V_271 ] ;
if ( V_311 )
V_315 = F_256 ( V_311 ) ;
V_311 = V_309 [ V_272 ] ;
if ( V_311 ) {
V_317 = true ;
V_316 = F_256 ( V_311 ) ;
}
F_17 (opt_inst, &team->option_inst_list, list) {
struct V_24 * V_26 = V_29 -> V_26 ;
struct V_52 V_53 ;
struct V_57 * V_58 ;
int V_320 ;
V_58 = & V_29 -> V_16 ;
V_320 = V_58 -> V_5 ?
V_58 -> V_5 -> V_3 -> V_263 : 0 ;
if ( V_26 -> type != V_314 ||
strcmp ( V_26 -> V_27 , V_25 ) ||
V_320 != V_315 ||
( V_26 -> V_32 && ! V_317 ) ||
V_58 -> V_37 != V_316 )
continue;
V_318 = true ;
V_53 . V_16 = V_58 ;
switch ( V_314 ) {
case V_273 :
V_53 . V_176 . V_178 = F_256 ( V_312 ) ;
break;
case V_277 :
if ( F_244 ( V_312 ) > V_321 ) {
V_34 = - V_66 ;
goto V_308;
}
V_53 . V_176 . V_177 = F_245 ( V_312 ) ;
break;
case V_279 :
V_53 . V_176 . V_281 . V_106 = F_244 ( V_312 ) ;
V_53 . V_176 . V_281 . V_282 = F_245 ( V_312 ) ;
break;
case V_283 :
V_53 . V_176 . V_179 = V_312 ? true : false ;
break;
case V_285 :
V_53 . V_176 . V_180 = F_287 ( V_312 ) ;
break;
default:
F_269 () ;
}
V_34 = F_40 ( V_14 , V_29 , & V_53 ) ;
if ( V_34 )
goto V_308;
V_29 -> V_38 = true ;
F_288 ( & V_29 -> V_296 , & V_307 ) ;
}
if ( ! V_318 ) {
V_34 = - V_174 ;
goto V_308;
}
}
V_34 = F_289 ( V_14 , & V_307 ) ;
V_308:
F_258 ( V_14 ) ;
F_73:
F_73 () ;
return V_34 ;
}
static int F_290 ( struct V_71 * V_72 ,
struct V_1 * V_5 )
{
struct V_247 * V_322 ;
V_322 = F_262 ( V_72 , V_323 ) ;
if ( ! V_322 )
goto V_270;
if ( F_264 ( V_72 , V_324 , V_5 -> V_3 -> V_263 ) )
goto V_270;
if ( V_5 -> V_38 ) {
if ( F_267 ( V_72 , V_325 ) )
goto V_270;
V_5 -> V_38 = false ;
}
if ( ( V_5 -> V_39 &&
F_267 ( V_72 , V_326 ) ) ||
( V_5 -> V_23 . V_18 &&
F_267 ( V_72 , V_327 ) ) ||
F_264 ( V_72 , V_328 , V_5 -> V_23 . V_329 ) ||
F_265 ( V_72 , V_330 , V_5 -> V_23 . V_331 ) )
goto V_270;
F_270 ( V_72 , V_322 ) ;
return 0 ;
V_270:
F_271 ( V_72 , V_322 ) ;
return - V_261 ;
}
static int F_291 ( struct V_14 * V_14 , T_4 V_266 , T_4 V_291 ,
int V_158 , T_11 * V_289 ,
struct V_1 * V_332 )
{
struct V_247 * V_83 ;
struct V_293 * V_294 ;
void * V_255 ;
struct V_1 * V_5 ;
int V_34 ;
struct V_71 * V_72 = NULL ;
bool V_295 ;
int V_33 ;
V_5 = F_292 ( & V_14 -> V_83 ,
struct V_1 , V_30 ) ;
V_297:
V_34 = F_272 ( & V_72 , V_14 , V_266 , V_289 ) ;
if ( V_34 )
return V_34 ;
V_255 = F_250 ( V_72 , V_266 , V_291 , & V_259 , V_158 | V_298 ,
V_333 ) ;
if ( ! V_255 )
return - V_261 ;
if ( F_264 ( V_72 , V_265 , V_14 -> V_3 -> V_263 ) )
goto V_300;
V_83 = F_262 ( V_72 , V_334 ) ;
if ( ! V_83 )
goto V_300;
V_33 = 0 ;
V_295 = false ;
if ( V_332 ) {
V_34 = F_290 ( V_72 , V_332 ) ;
if ( V_34 )
goto V_302;
} else if ( V_5 ) {
F_276 (port, &team->port_list, list) {
V_34 = F_290 ( V_72 , V_5 ) ;
if ( V_34 ) {
if ( V_34 == - V_261 ) {
if ( ! V_33 )
goto V_302;
V_295 = true ;
break;
}
goto V_302;
}
V_33 ++ ;
}
}
F_270 ( V_72 , V_83 ) ;
F_251 ( V_72 , V_255 ) ;
if ( V_295 )
goto V_297;
V_303:
V_294 = F_277 ( V_72 , V_266 , V_291 , V_304 , 0 , V_158 | V_298 ) ;
if ( ! V_294 ) {
V_34 = F_272 ( & V_72 , V_14 , V_266 , V_289 ) ;
if ( V_34 )
goto V_302;
goto V_303;
}
return V_289 ( V_72 , V_14 , V_266 ) ;
V_300:
V_34 = - V_261 ;
V_302:
F_278 ( V_72 , V_255 ) ;
F_254 ( V_72 ) ;
return V_34 ;
}
static int F_293 ( struct V_71 * V_72 ,
struct V_253 * V_16 )
{
struct V_14 * V_14 ;
int V_34 ;
V_14 = F_255 ( V_16 ) ;
if ( ! V_14 )
return - V_66 ;
V_34 = F_291 ( V_14 , V_16 -> V_257 , V_16 -> V_258 ,
V_305 , F_259 , NULL ) ;
F_258 ( V_14 ) ;
return V_34 ;
}
static int F_294 ( struct V_71 * V_72 ,
struct V_14 * V_14 , T_4 V_266 )
{
return F_295 ( & V_259 , F_260 ( V_14 -> V_3 ) ,
V_72 , 0 , 0 , V_35 ) ;
}
static int F_289 ( struct V_14 * V_14 ,
struct V_112 * V_292 )
{
return F_274 ( V_14 , 0 , 0 , 0 , F_294 ,
V_292 ) ;
}
static int F_296 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
return F_291 ( V_14 , 0 , 0 , 0 , F_294 ,
V_5 ) ;
}
static int T_12 F_297 ( void )
{
return F_298 ( & V_259 ) ;
}
static void F_299 ( void )
{
F_300 ( & V_259 ) ;
}
static void F_37 ( struct V_14 * V_14 )
{
int V_34 ;
struct V_28 * V_29 ;
F_280 ( V_292 ) ;
F_17 (opt_inst, &team->option_inst_list, list) {
if ( V_29 -> V_38 )
F_25 ( & V_29 -> V_296 , & V_292 ) ;
}
V_34 = F_289 ( V_14 , & V_292 ) ;
if ( V_34 && V_34 != - V_335 )
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
struct V_336 V_337 ;
V_34 = F_303 ( V_5 -> V_3 , & V_337 ) ;
if ( ! V_34 ) {
V_5 -> V_23 . V_329 = V_337 . V_338 . V_329 ;
V_5 -> V_23 . V_331 = V_337 . V_338 . V_331 ;
goto V_339;
}
}
V_5 -> V_23 . V_329 = 0 ;
V_5 -> V_23 . V_331 = 0 ;
V_339:
V_34 = F_296 ( V_5 -> V_14 , V_5 ) ;
if ( V_34 && V_34 != - V_335 )
F_301 ( V_5 -> V_14 -> V_3 , L_30 ,
V_5 -> V_3 -> V_27 , V_34 ) ;
}
static void F_175 ( struct V_14 * V_14 )
{
struct V_1 * V_5 ;
bool V_340 ;
if ( V_14 -> V_75 )
return;
V_340 = false ;
F_17 (port, &team->port_list, list) {
if ( V_5 -> V_18 ) {
V_340 = true ;
break;
}
}
if ( V_340 )
F_230 ( V_14 -> V_3 ) ;
else
F_188 ( V_14 -> V_3 ) ;
}
static void F_304 ( struct V_1 * V_5 , bool V_18 )
{
if ( V_5 -> V_23 . V_18 != V_18 )
F_302 ( V_5 , V_18 ) ;
F_175 ( V_5 -> V_14 ) ;
}
static void F_151 ( struct V_1 * V_5 , bool V_18 )
{
F_302 ( V_5 , V_18 ) ;
F_175 ( V_5 -> V_14 ) ;
}
static void F_159 ( struct V_1 * V_5 )
{
V_5 -> V_39 = true ;
F_302 ( V_5 , false ) ;
F_175 ( V_5 -> V_14 ) ;
}
static void F_305 ( struct V_1 * V_5 , bool V_18 )
{
struct V_14 * V_14 = V_5 -> V_14 ;
F_124 ( & V_14 -> V_145 ) ;
F_304 ( V_5 , V_18 ) ;
F_125 ( & V_14 -> V_145 ) ;
}
static int F_306 ( struct V_341 * V_342 ,
unsigned long V_343 , void * V_282 )
{
struct V_2 * V_3 = F_307 ( V_282 ) ;
struct V_1 * V_5 ;
V_5 = F_3 ( V_3 ) ;
if ( ! V_5 )
return V_344 ;
switch ( V_343 ) {
case V_345 :
if ( F_152 ( V_3 ) )
F_305 ( V_5 , true ) ;
break;
case V_346 :
F_305 ( V_5 , false ) ;
break;
case V_347 :
if ( F_77 ( V_5 -> V_3 ) )
F_305 ( V_5 ,
! ! F_152 ( V_5 -> V_3 ) ) ;
break;
case V_348 :
F_226 ( V_5 -> V_14 -> V_3 , V_3 ) ;
break;
case V_349 :
F_123 ( V_5 -> V_14 ) ;
break;
case V_350 :
if ( ! V_5 -> V_14 -> V_205 )
return V_351 ;
break;
case V_226 :
return V_351 ;
case V_95 :
F_74 ( V_343 , V_5 -> V_14 -> V_3 ) ;
break;
}
return V_344 ;
}
static int T_12 F_308 ( void )
{
int V_34 ;
F_309 ( & V_352 ) ;
V_34 = F_310 ( & V_353 ) ;
if ( V_34 )
goto V_354;
V_34 = F_297 () ;
if ( V_34 )
goto V_355;
return 0 ;
V_355:
F_311 ( & V_353 ) ;
V_354:
F_312 ( & V_352 ) ;
return V_34 ;
}
static void T_13 F_313 ( void )
{
F_299 () ;
F_311 ( & V_353 ) ;
F_312 ( & V_352 ) ;
}
