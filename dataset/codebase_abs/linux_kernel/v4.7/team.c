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
static void F_182 ( struct V_2 * V_3 ,
struct V_182 * V_183 ,
void * V_184 )
{
F_183 ( & V_183 -> V_185 , & V_186 ) ;
}
static void F_184 ( struct V_2 * V_3 )
{
F_183 ( & V_3 -> V_187 , & V_188 ) ;
F_185 ( V_3 , F_182 , NULL ) ;
V_3 -> V_189 = & V_190 ;
}
static int F_186 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_187 ( V_3 ) ;
int V_33 ;
int V_34 ;
V_14 -> V_3 = V_3 ;
F_188 ( & V_14 -> V_145 ) ;
F_60 ( V_14 ) ;
V_14 -> V_102 = F_189 ( struct V_101 ) ;
if ( ! V_14 -> V_102 )
return - V_36 ;
for ( V_33 = 0 ; V_33 < V_191 ; V_33 ++ )
F_190 ( & V_14 -> V_192 [ V_33 ] ) ;
F_94 ( & V_14 -> V_83 ) ;
V_34 = F_93 ( V_14 ) ;
if ( V_34 )
goto V_193;
F_61 ( V_14 ) ;
F_94 ( & V_14 -> V_50 ) ;
F_94 ( & V_14 -> V_40 ) ;
F_79 ( V_14 ) ;
F_85 ( V_14 ) ;
V_34 = F_36 ( V_14 , V_194 , F_191 ( V_194 ) ) ;
if ( V_34 )
goto V_195;
F_192 ( V_3 ) ;
F_184 ( V_3 ) ;
return 0 ;
V_195:
F_86 ( V_14 ) ;
F_81 ( V_14 ) ;
F_95 ( V_14 ) ;
V_193:
F_193 ( V_14 -> V_102 ) ;
return V_34 ;
}
static void F_194 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_187 ( V_3 ) ;
struct V_1 * V_5 ;
struct V_1 * V_31 ;
F_124 ( & V_14 -> V_145 ) ;
F_22 (port, tmp, &team->port_list, list)
F_158 ( V_14 , V_5 -> V_3 ) ;
F_62 ( V_14 , NULL ) ;
F_35 ( V_14 , V_194 , F_191 ( V_194 ) ) ;
F_86 ( V_14 ) ;
F_81 ( V_14 ) ;
F_95 ( V_14 ) ;
F_125 ( & V_14 -> V_145 ) ;
}
static void F_195 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_187 ( V_3 ) ;
F_193 ( V_14 -> V_102 ) ;
F_196 ( V_3 ) ;
}
static int F_197 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_198 ( struct V_2 * V_3 )
{
return 0 ;
}
static T_7 F_199 ( struct V_71 * V_72 , struct V_2 * V_3 )
{
struct V_14 * V_14 = F_187 ( V_3 ) ;
bool V_196 ;
unsigned int V_106 = V_72 -> V_106 ;
V_196 = F_97 ( V_14 , V_72 ) ;
if ( ! V_196 )
V_196 = V_14 -> V_77 . V_78 ( V_14 , V_72 ) ;
if ( V_196 ) {
struct V_101 * V_102 ;
V_102 = F_89 ( V_14 -> V_102 ) ;
F_90 ( & V_102 -> V_103 ) ;
V_102 -> V_197 ++ ;
V_102 -> V_198 += V_106 ;
F_91 ( & V_102 -> V_103 ) ;
} else {
F_92 ( V_14 -> V_102 -> V_199 ) ;
}
return V_200 ;
}
static T_3 F_200 ( struct V_2 * V_3 , struct V_71 * V_72 ,
void * V_201 , T_8 V_202 )
{
T_3 V_183 = F_201 ( V_72 ) ? F_202 ( V_72 ) : 0 ;
F_203 ( V_72 ) -> V_203 = V_72 -> V_120 ;
if ( F_204 ( V_183 >= V_3 -> V_181 ) ) {
do {
V_183 -= V_3 -> V_181 ;
} while ( V_183 >= V_3 -> V_181 );
}
return V_183 ;
}
static void F_205 ( struct V_2 * V_3 , int V_204 )
{
struct V_14 * V_14 = F_187 ( V_3 ) ;
struct V_1 * V_5 ;
int V_205 ;
F_206 () ;
F_98 (port, &team->port_list, list) {
if ( V_204 & V_206 ) {
V_205 = V_3 -> V_158 & V_206 ? 1 : - 1 ;
F_207 ( V_5 -> V_3 , V_205 ) ;
}
if ( V_204 & V_207 ) {
V_205 = V_3 -> V_158 & V_207 ? 1 : - 1 ;
F_208 ( V_5 -> V_3 , V_205 ) ;
}
}
F_209 () ;
}
static void F_210 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_187 ( V_3 ) ;
struct V_1 * V_5 ;
F_206 () ;
F_98 (port, &team->port_list, list) {
F_145 ( V_5 -> V_3 , V_3 ) ;
F_146 ( V_5 -> V_3 , V_3 ) ;
}
F_209 () ;
}
static int F_211 ( struct V_2 * V_3 , void * V_208 )
{
struct V_8 * V_9 = V_208 ;
struct V_14 * V_14 = F_187 ( V_3 ) ;
struct V_1 * V_5 ;
if ( V_3 -> type == V_209 && ! F_212 ( V_9 -> V_10 ) )
return - V_210 ;
memcpy ( V_3 -> V_7 , V_9 -> V_10 , V_3 -> V_11 ) ;
F_124 ( & V_14 -> V_145 ) ;
F_17 (port, &team->port_list, list)
if ( V_14 -> V_77 . V_211 )
V_14 -> V_77 . V_211 ( V_14 , V_5 ) ;
F_125 ( & V_14 -> V_145 ) ;
return 0 ;
}
static int F_213 ( struct V_2 * V_3 , int V_212 )
{
struct V_14 * V_14 = F_187 ( V_3 ) ;
struct V_1 * V_5 ;
int V_34 ;
F_124 ( & V_14 -> V_145 ) ;
V_14 -> V_213 = true ;
F_17 (port, &team->port_list, list) {
V_34 = F_142 ( V_5 -> V_3 , V_212 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_26 ,
V_5 -> V_3 -> V_27 ) ;
goto V_214;
}
}
V_14 -> V_213 = false ;
F_125 ( & V_14 -> V_145 ) ;
V_3 -> V_165 = V_212 ;
return 0 ;
V_214:
F_214 (port, &team->port_list, list)
F_142 ( V_5 -> V_3 , V_3 -> V_165 ) ;
V_14 -> V_213 = false ;
F_125 ( & V_14 -> V_145 ) ;
return V_34 ;
}
static struct V_215 *
F_215 ( struct V_2 * V_3 , struct V_215 * V_216 )
{
struct V_14 * V_14 = F_187 ( V_3 ) ;
struct V_101 * V_208 ;
T_9 V_104 , V_105 , V_109 , V_197 , V_198 ;
T_4 V_111 = 0 , V_199 = 0 , V_110 = 0 ;
unsigned int V_217 ;
int V_33 ;
F_216 (i) {
V_208 = F_217 ( V_14 -> V_102 , V_33 ) ;
do {
V_217 = F_218 ( & V_208 -> V_103 ) ;
V_104 = V_208 -> V_104 ;
V_105 = V_208 -> V_105 ;
V_109 = V_208 -> V_109 ;
V_197 = V_208 -> V_197 ;
V_198 = V_208 -> V_198 ;
} while ( F_219 ( & V_208 -> V_103 , V_217 ) );
V_216 -> V_104 += V_104 ;
V_216 -> V_105 += V_105 ;
V_216 -> V_218 += V_109 ;
V_216 -> V_197 += V_197 ;
V_216 -> V_198 += V_198 ;
V_111 += V_208 -> V_111 ;
V_199 += V_208 -> V_199 ;
V_110 += V_208 -> V_110 ;
}
V_216 -> V_111 = V_111 ;
V_216 -> V_199 = V_199 ;
V_216 -> V_110 = V_110 ;
return V_216 ;
}
static int F_220 ( struct V_2 * V_3 , T_10 V_219 , T_3 V_220 )
{
struct V_14 * V_14 = F_187 ( V_3 ) ;
struct V_1 * V_5 ;
int V_34 ;
F_124 ( & V_14 -> V_145 ) ;
F_17 (port, &team->port_list, list) {
V_34 = F_221 ( V_5 -> V_3 , V_219 , V_220 ) ;
if ( V_34 )
goto V_214;
}
F_125 ( & V_14 -> V_145 ) ;
return 0 ;
V_214:
F_214 (port, &team->port_list, list)
F_222 ( V_5 -> V_3 , V_219 , V_220 ) ;
F_125 ( & V_14 -> V_145 ) ;
return V_34 ;
}
static int F_223 ( struct V_2 * V_3 , T_10 V_219 , T_3 V_220 )
{
struct V_14 * V_14 = F_187 ( V_3 ) ;
struct V_1 * V_5 ;
F_124 ( & V_14 -> V_145 ) ;
F_17 (port, &team->port_list, list)
F_222 ( V_5 -> V_3 , V_219 , V_220 ) ;
F_125 ( & V_14 -> V_145 ) ;
return 0 ;
}
static void F_224 ( struct V_2 * V_3 )
{
}
static void F_225 ( struct V_14 * V_14 )
{
struct V_1 * V_5 ;
F_17 (port, &team->port_list, list)
F_132 ( V_5 ) ;
}
static void F_226 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_187 ( V_3 ) ;
F_124 ( & V_14 -> V_145 ) ;
F_225 ( V_14 ) ;
F_125 ( & V_14 -> V_145 ) ;
}
static int F_227 ( struct V_2 * V_3 ,
struct V_221 * V_222 )
{
struct V_14 * V_14 = F_187 ( V_3 ) ;
struct V_1 * V_5 ;
int V_34 = 0 ;
F_124 ( & V_14 -> V_145 ) ;
F_17 (port, &team->port_list, list) {
V_34 = F_130 ( V_14 , V_5 ) ;
if ( V_34 ) {
F_225 ( V_14 ) ;
break;
}
}
F_125 ( & V_14 -> V_145 ) ;
return V_34 ;
}
static int F_228 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_187 ( V_3 ) ;
int V_34 ;
F_124 ( & V_14 -> V_145 ) ;
V_34 = F_139 ( V_14 , V_6 ) ;
F_125 ( & V_14 -> V_145 ) ;
return V_34 ;
}
static int F_229 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_14 * V_14 = F_187 ( V_3 ) ;
int V_34 ;
F_124 ( & V_14 -> V_145 ) ;
V_34 = F_158 ( V_14 , V_6 ) ;
F_125 ( & V_14 -> V_145 ) ;
return V_34 ;
}
static T_5 F_230 ( struct V_2 * V_3 ,
T_5 V_160 )
{
struct V_1 * V_5 ;
struct V_14 * V_14 = F_187 ( V_3 ) ;
T_5 V_223 ;
V_223 = V_160 ;
V_160 &= ~ V_224 ;
V_160 |= V_133 ;
F_206 () ;
F_98 (port, &team->port_list, list) {
V_160 = F_120 ( V_160 ,
V_5 -> V_3 -> V_160 ,
V_223 ) ;
}
F_209 () ;
V_160 = F_231 ( V_160 , V_223 ) ;
return V_160 ;
}
static int F_232 ( struct V_2 * V_3 , bool V_225 )
{
struct V_14 * V_14 = F_187 ( V_3 ) ;
V_14 -> V_75 = true ;
if ( V_225 )
F_233 ( V_3 ) ;
else
F_192 ( V_3 ) ;
return 0 ;
}
static void F_234 ( struct V_2 * V_3 ,
struct V_226 * V_227 )
{
F_235 ( V_227 -> V_228 , V_229 , sizeof( V_227 -> V_228 ) ) ;
F_235 ( V_227 -> V_230 , V_231 , sizeof( V_227 -> V_230 ) ) ;
}
static void F_236 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
V_3 -> V_232 = V_6 -> V_232 ;
V_3 -> type = V_6 -> type ;
V_3 -> V_143 = V_6 -> V_143 ;
V_3 -> V_11 = V_6 -> V_11 ;
V_3 -> V_165 = V_6 -> V_165 ;
memcpy ( V_3 -> V_233 , V_6 -> V_233 , V_6 -> V_11 ) ;
F_237 ( V_3 , V_6 ) ;
}
static int F_141 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
struct V_14 * V_14 = F_187 ( V_3 ) ;
char * V_157 = V_6 -> V_27 ;
int V_34 ;
if ( V_3 -> type == V_6 -> type )
return 0 ;
if ( ! F_66 ( & V_14 -> V_83 ) ) {
F_67 ( V_3 , L_27 , V_157 ) ;
return - V_84 ;
}
V_34 = F_74 ( V_234 , V_3 ) ;
V_34 = F_238 ( V_34 ) ;
if ( V_34 ) {
F_67 ( V_3 , L_28 ) ;
return V_34 ;
}
F_239 ( V_3 ) ;
F_240 ( V_3 ) ;
F_236 ( V_3 , V_6 ) ;
F_74 ( V_235 , V_3 ) ;
return 0 ;
}
static void F_241 ( struct V_2 * V_3 )
{
F_242 ( V_3 ) ;
V_3 -> V_236 = & V_237 ;
V_3 -> V_238 = & V_239 ;
V_3 -> V_240 = F_195 ;
V_3 -> V_142 &= ~ ( V_139 | V_241 ) ;
V_3 -> V_142 |= V_242 ;
V_3 -> V_142 |= V_243 ;
V_3 -> V_142 |= V_244 | V_245 ;
V_3 -> V_160 |= V_246 ;
V_3 -> V_160 |= V_247 ;
V_3 -> V_160 |= V_248 ;
V_3 -> V_249 = V_132 |
V_250 |
V_251 |
V_252 ;
V_3 -> V_249 |= V_144 ;
V_3 -> V_160 |= V_3 -> V_249 ;
}
static int F_243 ( struct V_253 * V_254 , struct V_2 * V_3 ,
struct V_255 * V_256 [] , struct V_255 * V_176 [] )
{
if ( V_256 [ V_257 ] == NULL )
F_244 ( V_3 ) ;
return F_245 ( V_3 ) ;
}
static int F_246 ( struct V_255 * V_256 [] , struct V_255 * V_176 [] )
{
if ( V_256 [ V_257 ] ) {
if ( F_247 ( V_256 [ V_257 ] ) != V_258 )
return - V_66 ;
if ( ! F_212 ( F_248 ( V_256 [ V_257 ] ) ) )
return - V_210 ;
}
return 0 ;
}
static unsigned int F_249 ( void )
{
return V_259 ;
}
static unsigned int F_250 ( void )
{
return V_260 ;
}
static int F_251 ( struct V_71 * V_72 , struct V_261 * V_16 )
{
struct V_71 * V_262 ;
void * V_263 ;
int V_34 ;
V_262 = F_252 ( V_264 , V_35 ) ;
if ( ! V_262 )
return - V_36 ;
V_263 = F_253 ( V_262 , V_16 -> V_265 , V_16 -> V_266 ,
& V_267 , 0 , V_268 ) ;
if ( ! V_263 ) {
V_34 = - V_269 ;
goto V_270;
}
F_254 ( V_262 , V_263 ) ;
return F_255 ( F_256 ( V_16 ) , V_262 , V_16 -> V_265 ) ;
V_270:
F_257 ( V_262 ) ;
return V_34 ;
}
static struct V_14 * F_258 ( struct V_261 * V_16 )
{
struct V_253 * V_253 = F_256 ( V_16 ) ;
int V_271 ;
struct V_2 * V_3 ;
struct V_14 * V_14 ;
if ( ! V_16 -> V_272 [ V_273 ] )
return NULL ;
V_271 = F_259 ( V_16 -> V_272 [ V_273 ] ) ;
V_3 = F_260 ( V_253 , V_271 ) ;
if ( ! V_3 || V_3 -> V_236 != & V_237 ) {
if ( V_3 )
F_128 ( V_3 ) ;
return NULL ;
}
V_14 = F_187 ( V_3 ) ;
F_124 ( & V_14 -> V_145 ) ;
return V_14 ;
}
static void F_261 ( struct V_14 * V_14 )
{
F_125 ( & V_14 -> V_145 ) ;
F_128 ( V_14 -> V_3 ) ;
}
static int F_262 ( struct V_71 * V_72 , struct V_14 * V_14 , T_4 V_274 )
{
return F_255 ( F_263 ( V_14 -> V_3 ) , V_72 , V_274 ) ;
}
static int F_264 ( struct V_71 * V_72 , struct V_14 * V_14 ,
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
V_275 = F_265 ( V_72 , V_276 ) ;
if ( ! V_275 )
return - V_269 ;
if ( F_266 ( V_72 , V_277 , V_26 -> V_27 ) )
goto V_278;
if ( V_58 -> V_5 &&
F_267 ( V_72 , V_279 ,
V_58 -> V_5 -> V_3 -> V_271 ) )
goto V_278;
if ( V_29 -> V_26 -> V_32 &&
F_267 ( V_72 , V_280 ,
V_58 -> V_37 ) )
goto V_278;
switch ( V_26 -> type ) {
case V_281 :
if ( F_268 ( V_72 , V_282 , V_283 ) )
goto V_278;
if ( F_267 ( V_72 , V_284 , V_53 . V_176 . V_178 ) )
goto V_278;
break;
case V_285 :
if ( F_268 ( V_72 , V_282 , V_286 ) )
goto V_278;
if ( F_266 ( V_72 , V_284 ,
V_53 . V_176 . V_177 ) )
goto V_278;
break;
case V_287 :
if ( F_268 ( V_72 , V_282 , V_288 ) )
goto V_278;
if ( F_269 ( V_72 , V_284 , V_53 . V_176 . V_289 . V_106 ,
V_53 . V_176 . V_289 . V_290 ) )
goto V_278;
break;
case V_291 :
if ( F_268 ( V_72 , V_282 , V_292 ) )
goto V_278;
if ( V_53 . V_176 . V_179 &&
F_270 ( V_72 , V_284 ) )
goto V_278;
break;
case V_293 :
if ( F_268 ( V_72 , V_282 , V_294 ) )
goto V_278;
if ( F_271 ( V_72 , V_284 , V_53 . V_176 . V_180 ) )
goto V_278;
break;
default:
F_272 () ;
}
if ( V_29 -> V_39 && F_270 ( V_72 , V_295 ) )
goto V_278;
if ( V_29 -> V_38 ) {
if ( F_270 ( V_72 , V_296 ) )
goto V_278;
V_29 -> V_38 = false ;
}
F_273 ( V_72 , V_275 ) ;
return 0 ;
V_278:
F_274 ( V_72 , V_275 ) ;
return - V_269 ;
}
static int F_275 ( struct V_71 * * V_96 ,
struct V_14 * V_14 , T_4 V_274 ,
T_11 * V_297 )
{
int V_34 ;
if ( * V_96 ) {
V_34 = V_297 ( * V_96 , V_14 , V_274 ) ;
if ( V_34 )
return V_34 ;
}
* V_96 = F_276 ( V_298 , V_35 ) ;
if ( ! * V_96 )
return - V_36 ;
return 0 ;
}
static int F_277 ( struct V_14 * V_14 , T_4 V_274 , T_4 V_299 ,
int V_158 , T_11 * V_297 ,
struct V_112 * V_300 )
{
struct V_255 * V_50 ;
struct V_301 * V_302 ;
void * V_263 ;
struct V_28 * V_29 ;
int V_34 ;
struct V_71 * V_72 = NULL ;
bool V_303 ;
int V_33 ;
V_29 = F_278 ( V_300 ,
struct V_28 , V_304 ) ;
V_305:
V_34 = F_275 ( & V_72 , V_14 , V_274 , V_297 ) ;
if ( V_34 )
return V_34 ;
V_263 = F_253 ( V_72 , V_274 , V_299 , & V_267 , V_158 | V_306 ,
V_307 ) ;
if ( ! V_263 )
return - V_269 ;
if ( F_267 ( V_72 , V_273 , V_14 -> V_3 -> V_271 ) )
goto V_308;
V_50 = F_265 ( V_72 , V_309 ) ;
if ( ! V_50 )
goto V_308;
V_33 = 0 ;
V_303 = false ;
F_279 (opt_inst, sel_opt_inst_list, tmp_list) {
V_34 = F_264 ( V_72 , V_14 , V_29 ) ;
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
F_273 ( V_72 , V_50 ) ;
F_254 ( V_72 , V_263 ) ;
if ( V_303 )
goto V_305;
V_311:
V_302 = F_280 ( V_72 , V_274 , V_299 , V_312 , 0 , V_158 | V_306 ) ;
if ( ! V_302 ) {
V_34 = F_275 ( & V_72 , V_14 , V_274 , V_297 ) ;
if ( V_34 )
goto V_310;
goto V_311;
}
return V_297 ( V_72 , V_14 , V_274 ) ;
V_308:
V_34 = - V_269 ;
V_310:
F_281 ( V_72 , V_263 ) ;
F_257 ( V_72 ) ;
return V_34 ;
}
static int F_282 ( struct V_71 * V_72 , struct V_261 * V_16 )
{
struct V_14 * V_14 ;
struct V_28 * V_29 ;
int V_34 ;
F_283 ( V_300 ) ;
V_14 = F_258 ( V_16 ) ;
if ( ! V_14 )
return - V_66 ;
F_17 (opt_inst, &team->option_inst_list, list)
F_25 ( & V_29 -> V_304 , & V_300 ) ;
V_34 = F_277 ( V_14 , V_16 -> V_265 , V_16 -> V_266 ,
V_313 , F_262 ,
& V_300 ) ;
F_261 ( V_14 ) ;
return V_34 ;
}
static int F_284 ( struct V_71 * V_72 , struct V_261 * V_16 )
{
struct V_14 * V_14 ;
int V_34 = 0 ;
int V_33 ;
struct V_255 * V_314 ;
F_283 ( V_315 ) ;
F_285 () ;
V_14 = F_258 ( V_16 ) ;
if ( ! V_14 ) {
V_34 = - V_66 ;
goto F_73;
}
V_34 = - V_66 ;
if ( ! V_16 -> V_272 [ V_309 ] ) {
V_34 = - V_66 ;
goto V_316;
}
F_286 (nl_option, info->attrs[TEAM_ATTR_LIST_OPTION], i) {
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
if ( F_287 ( V_314 ) != V_276 ) {
V_34 = - V_66 ;
goto V_316;
}
V_34 = F_288 ( V_317 , V_318 ,
V_314 , V_327 ) ;
if ( V_34 )
goto V_316;
if ( ! V_317 [ V_277 ] ||
! V_317 [ V_282 ] ) {
V_34 = - V_66 ;
goto V_316;
}
switch ( F_289 ( V_317 [ V_282 ] ) ) {
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
V_25 = F_248 ( V_317 [ V_277 ] ) ;
V_319 = V_317 [ V_279 ] ;
if ( V_319 )
V_323 = F_259 ( V_319 ) ;
V_319 = V_317 [ V_280 ] ;
if ( V_319 ) {
V_325 = true ;
V_324 = F_259 ( V_319 ) ;
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
V_53 . V_176 . V_178 = F_259 ( V_320 ) ;
break;
case V_285 :
if ( F_247 ( V_320 ) > V_329 ) {
V_34 = - V_66 ;
goto V_316;
}
V_53 . V_176 . V_177 = F_248 ( V_320 ) ;
break;
case V_287 :
V_53 . V_176 . V_289 . V_106 = F_247 ( V_320 ) ;
V_53 . V_176 . V_289 . V_290 = F_248 ( V_320 ) ;
break;
case V_291 :
V_53 . V_176 . V_179 = V_320 ? true : false ;
break;
case V_293 :
V_53 . V_176 . V_180 = F_290 ( V_320 ) ;
break;
default:
F_272 () ;
}
V_34 = F_40 ( V_14 , V_29 , & V_53 ) ;
if ( V_34 )
goto V_316;
V_29 -> V_38 = true ;
F_291 ( & V_29 -> V_304 , & V_315 ) ;
}
if ( ! V_326 ) {
V_34 = - V_174 ;
goto V_316;
}
}
V_34 = F_292 ( V_14 , & V_315 ) ;
V_316:
F_261 ( V_14 ) ;
F_73:
F_73 () ;
return V_34 ;
}
static int F_293 ( struct V_71 * V_72 ,
struct V_1 * V_5 )
{
struct V_255 * V_330 ;
V_330 = F_265 ( V_72 , V_331 ) ;
if ( ! V_330 )
goto V_278;
if ( F_267 ( V_72 , V_332 , V_5 -> V_3 -> V_271 ) )
goto V_278;
if ( V_5 -> V_38 ) {
if ( F_270 ( V_72 , V_333 ) )
goto V_278;
V_5 -> V_38 = false ;
}
if ( ( V_5 -> V_39 &&
F_270 ( V_72 , V_334 ) ) ||
( V_5 -> V_23 . V_18 &&
F_270 ( V_72 , V_335 ) ) ||
F_267 ( V_72 , V_336 , V_5 -> V_23 . V_337 ) ||
F_268 ( V_72 , V_338 , V_5 -> V_23 . V_339 ) )
goto V_278;
F_273 ( V_72 , V_330 ) ;
return 0 ;
V_278:
F_274 ( V_72 , V_330 ) ;
return - V_269 ;
}
static int F_294 ( struct V_14 * V_14 , T_4 V_274 , T_4 V_299 ,
int V_158 , T_11 * V_297 ,
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
V_5 = F_295 ( & V_14 -> V_83 ,
struct V_1 , V_30 ) ;
V_305:
V_34 = F_275 ( & V_72 , V_14 , V_274 , V_297 ) ;
if ( V_34 )
return V_34 ;
V_263 = F_253 ( V_72 , V_274 , V_299 , & V_267 , V_158 | V_306 ,
V_341 ) ;
if ( ! V_263 )
return - V_269 ;
if ( F_267 ( V_72 , V_273 , V_14 -> V_3 -> V_271 ) )
goto V_308;
V_83 = F_265 ( V_72 , V_342 ) ;
if ( ! V_83 )
goto V_308;
V_33 = 0 ;
V_303 = false ;
if ( V_340 ) {
V_34 = F_293 ( V_72 , V_340 ) ;
if ( V_34 )
goto V_310;
} else if ( V_5 ) {
F_279 (port, &team->port_list, list) {
V_34 = F_293 ( V_72 , V_5 ) ;
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
F_273 ( V_72 , V_83 ) ;
F_254 ( V_72 , V_263 ) ;
if ( V_303 )
goto V_305;
V_311:
V_302 = F_280 ( V_72 , V_274 , V_299 , V_312 , 0 , V_158 | V_306 ) ;
if ( ! V_302 ) {
V_34 = F_275 ( & V_72 , V_14 , V_274 , V_297 ) ;
if ( V_34 )
goto V_310;
goto V_311;
}
return V_297 ( V_72 , V_14 , V_274 ) ;
V_308:
V_34 = - V_269 ;
V_310:
F_281 ( V_72 , V_263 ) ;
F_257 ( V_72 ) ;
return V_34 ;
}
static int F_296 ( struct V_71 * V_72 ,
struct V_261 * V_16 )
{
struct V_14 * V_14 ;
int V_34 ;
V_14 = F_258 ( V_16 ) ;
if ( ! V_14 )
return - V_66 ;
V_34 = F_294 ( V_14 , V_16 -> V_265 , V_16 -> V_266 ,
V_313 , F_262 , NULL ) ;
F_261 ( V_14 ) ;
return V_34 ;
}
static int F_297 ( struct V_71 * V_72 ,
struct V_14 * V_14 , T_4 V_274 )
{
return F_298 ( & V_267 , F_263 ( V_14 -> V_3 ) ,
V_72 , 0 , 0 , V_35 ) ;
}
static int F_292 ( struct V_14 * V_14 ,
struct V_112 * V_300 )
{
return F_277 ( V_14 , 0 , 0 , 0 , F_297 ,
V_300 ) ;
}
static int F_299 ( struct V_14 * V_14 ,
struct V_1 * V_5 )
{
return F_294 ( V_14 , 0 , 0 , 0 , F_297 ,
V_5 ) ;
}
static int F_300 ( void )
{
return F_301 ( & V_267 , V_343 ,
V_344 ) ;
}
static void F_302 ( void )
{
F_303 ( & V_267 ) ;
}
static void F_37 ( struct V_14 * V_14 )
{
int V_34 ;
struct V_28 * V_29 ;
F_283 ( V_300 ) ;
F_17 (opt_inst, &team->option_inst_list, list) {
if ( V_29 -> V_38 )
F_25 ( & V_29 -> V_304 , & V_300 ) ;
}
V_34 = F_292 ( V_14 , & V_300 ) ;
if ( V_34 && V_34 != - V_345 )
F_304 ( V_14 -> V_3 , L_29 ,
V_34 ) ;
}
static void F_305 ( struct V_1 * V_5 , bool V_18 )
{
int V_34 ;
V_5 -> V_38 = true ;
V_5 -> V_23 . V_18 = V_18 ;
F_15 ( V_5 ) ;
if ( V_18 ) {
struct V_346 V_347 ;
V_34 = F_306 ( V_5 -> V_3 , & V_347 ) ;
if ( ! V_34 ) {
V_5 -> V_23 . V_337 = V_347 . V_348 . V_337 ;
V_5 -> V_23 . V_339 = V_347 . V_348 . V_339 ;
goto V_349;
}
}
V_5 -> V_23 . V_337 = 0 ;
V_5 -> V_23 . V_339 = 0 ;
V_349:
V_34 = F_299 ( V_5 -> V_14 , V_5 ) ;
if ( V_34 && V_34 != - V_345 )
F_304 ( V_5 -> V_14 -> V_3 , L_30 ,
V_5 -> V_3 -> V_27 , V_34 ) ;
}
static void F_175 ( struct V_14 * V_14 )
{
struct V_1 * V_5 ;
bool V_350 ;
if ( V_14 -> V_75 )
return;
V_350 = false ;
F_17 (port, &team->port_list, list) {
if ( V_5 -> V_18 ) {
V_350 = true ;
break;
}
}
if ( V_350 )
F_233 ( V_14 -> V_3 ) ;
else
F_192 ( V_14 -> V_3 ) ;
}
static void F_307 ( struct V_1 * V_5 , bool V_18 )
{
if ( V_5 -> V_23 . V_18 != V_18 )
F_305 ( V_5 , V_18 ) ;
F_175 ( V_5 -> V_14 ) ;
}
static void F_151 ( struct V_1 * V_5 , bool V_18 )
{
F_305 ( V_5 , V_18 ) ;
F_175 ( V_5 -> V_14 ) ;
}
static void F_159 ( struct V_1 * V_5 )
{
V_5 -> V_39 = true ;
F_305 ( V_5 , false ) ;
F_175 ( V_5 -> V_14 ) ;
}
static void F_308 ( struct V_1 * V_5 , bool V_18 )
{
struct V_14 * V_14 = V_5 -> V_14 ;
F_124 ( & V_14 -> V_145 ) ;
F_307 ( V_5 , V_18 ) ;
F_125 ( & V_14 -> V_145 ) ;
}
static int F_309 ( struct V_351 * V_184 ,
unsigned long V_352 , void * V_290 )
{
struct V_2 * V_3 = F_310 ( V_290 ) ;
struct V_1 * V_5 ;
V_5 = F_3 ( V_3 ) ;
if ( ! V_5 )
return V_353 ;
switch ( V_352 ) {
case V_354 :
if ( F_152 ( V_3 ) )
F_308 ( V_5 , true ) ;
break;
case V_355 :
F_308 ( V_5 , false ) ;
break;
case V_356 :
if ( F_77 ( V_5 -> V_3 ) )
F_308 ( V_5 ,
! ! F_152 ( V_5 -> V_3 ) ) ;
break;
case V_357 :
F_229 ( V_5 -> V_14 -> V_3 , V_3 ) ;
break;
case V_358 :
F_123 ( V_5 -> V_14 ) ;
break;
case V_359 :
if ( ! V_5 -> V_14 -> V_213 )
return V_360 ;
break;
case V_234 :
return V_360 ;
case V_95 :
F_74 ( V_352 , V_5 -> V_14 -> V_3 ) ;
break;
}
return V_353 ;
}
static int T_12 F_311 ( void )
{
int V_34 ;
F_312 ( & V_361 ) ;
V_34 = F_313 ( & V_362 ) ;
if ( V_34 )
goto V_363;
V_34 = F_300 () ;
if ( V_34 )
goto V_364;
return 0 ;
V_364:
F_314 ( & V_362 ) ;
V_363:
F_315 ( & V_361 ) ;
return V_34 ;
}
static void T_13 F_316 ( void )
{
F_302 () ;
F_314 ( & V_362 ) ;
F_315 ( & V_361 ) ;
}
