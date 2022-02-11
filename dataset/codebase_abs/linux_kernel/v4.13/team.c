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
return F_7 ( V_6 , (struct V_13 * ) & V_9 ) ;
}
static int F_8 ( struct V_1 * V_5 )
{
return F_6 ( V_5 -> V_3 , V_5 -> V_14 . V_7 ) ;
}
static int F_9 ( struct V_15 * V_15 ,
struct V_1 * V_5 )
{
return F_6 ( V_5 -> V_3 , V_15 -> V_3 -> V_7 ) ;
}
int F_10 ( struct V_15 * V_15 , struct V_1 * V_5 )
{
return F_9 ( V_15 , V_5 ) ;
}
void F_11 ( struct V_15 * V_15 ,
struct V_1 * V_5 )
{
F_9 ( V_15 , V_5 ) ;
}
static void F_12 ( struct V_1 * V_5 )
{
struct V_16 V_17 ;
V_17 . V_18 = V_5 -> V_19 ;
V_17 . V_20 = F_13 ( V_5 ) ;
F_14 ( V_5 -> V_3 , & V_17 ) ;
}
static void F_15 ( struct V_1 * V_5 )
{
bool V_21 = V_5 -> V_22 . V_23 ? V_5 -> V_22 . V_19 :
V_5 -> V_24 . V_19 ;
if ( V_5 -> V_19 != V_21 ) {
V_5 -> V_19 = V_21 ;
F_12 ( V_5 ) ;
}
}
static struct V_25 * F_16 ( struct V_15 * V_15 ,
const char * V_26 )
{
struct V_25 * V_27 ;
F_17 (option, &team->option_list, list) {
if ( strcmp ( V_27 -> V_28 , V_26 ) == 0 )
return V_27 ;
}
return NULL ;
}
static void F_18 ( struct V_29 * V_30 )
{
F_19 ( & V_30 -> V_31 ) ;
F_20 ( V_30 ) ;
}
static void F_21 ( struct V_15 * V_15 ,
struct V_25 * V_27 )
{
struct V_29 * V_30 , * V_32 ;
F_22 (opt_inst, tmp, &team->option_inst_list, list) {
if ( V_30 -> V_27 == V_27 )
F_18 ( V_30 ) ;
}
}
static int F_23 ( struct V_15 * V_15 , struct V_25 * V_27 ,
struct V_1 * V_5 )
{
struct V_29 * V_30 ;
unsigned int V_33 ;
unsigned int V_34 ;
int V_35 ;
V_33 = V_27 -> V_33 ;
if ( ! V_33 )
V_33 = 1 ;
for ( V_34 = 0 ; V_34 < V_33 ; V_34 ++ ) {
V_30 = F_24 ( sizeof( * V_30 ) , V_36 ) ;
if ( ! V_30 )
return - V_37 ;
V_30 -> V_27 = V_27 ;
V_30 -> V_17 . V_5 = V_5 ;
V_30 -> V_17 . V_38 = V_34 ;
V_30 -> V_39 = true ;
V_30 -> V_40 = false ;
F_25 ( & V_30 -> V_31 , & V_15 -> V_41 ) ;
if ( V_27 -> V_42 ) {
V_35 = V_27 -> V_42 ( V_15 , & V_30 -> V_17 ) ;
if ( V_35 )
return V_35 ;
}
}
return 0 ;
}
static int F_26 ( struct V_15 * V_15 ,
struct V_25 * V_27 )
{
int V_35 ;
if ( ! V_27 -> V_43 ) {
V_35 = F_23 ( V_15 , V_27 , NULL ) ;
if ( V_35 )
goto V_44;
}
return 0 ;
V_44:
F_21 ( V_15 , V_27 ) ;
return V_35 ;
}
static void F_27 ( struct V_15 * V_15 ,
struct V_25 * V_27 )
{
struct V_29 * V_30 ;
F_17 (opt_inst, &team->option_inst_list, list) {
if ( V_30 -> V_27 == V_27 ) {
V_30 -> V_39 = true ;
V_30 -> V_40 = true ;
}
}
}
static void F_28 ( struct V_15 * V_15 ,
struct V_1 * V_5 )
{
struct V_29 * V_30 , * V_32 ;
F_22 (opt_inst, tmp, &team->option_inst_list, list) {
if ( V_30 -> V_27 -> V_43 &&
V_30 -> V_17 . V_5 == V_5 )
F_18 ( V_30 ) ;
}
}
static int F_29 ( struct V_15 * V_15 ,
struct V_1 * V_5 )
{
struct V_25 * V_27 ;
int V_35 ;
F_17 (option, &team->option_list, list) {
if ( ! V_27 -> V_43 )
continue;
V_35 = F_23 ( V_15 , V_27 , V_5 ) ;
if ( V_35 )
goto V_45;
}
return 0 ;
V_45:
F_28 ( V_15 , V_5 ) ;
return V_35 ;
}
static void F_30 ( struct V_15 * V_15 ,
struct V_1 * V_5 )
{
struct V_29 * V_30 ;
F_17 (opt_inst, &team->option_inst_list, list) {
if ( V_30 -> V_17 . V_5 == V_5 ) {
V_30 -> V_39 = true ;
V_30 -> V_40 = true ;
}
}
}
static int F_31 ( struct V_15 * V_15 ,
const struct V_25 * V_27 ,
T_1 V_46 )
{
int V_34 ;
struct V_25 * * V_47 ;
int V_35 ;
V_47 = F_32 ( sizeof( struct V_25 * ) * V_46 ,
V_36 ) ;
if ( ! V_47 )
return - V_37 ;
for ( V_34 = 0 ; V_34 < V_46 ; V_34 ++ , V_27 ++ ) {
if ( F_16 ( V_15 , V_27 -> V_28 ) ) {
V_35 = - V_48 ;
goto V_49;
}
V_47 [ V_34 ] = F_33 ( V_27 , sizeof( * V_27 ) , V_36 ) ;
if ( ! V_47 [ V_34 ] ) {
V_35 = - V_37 ;
goto V_49;
}
}
for ( V_34 = 0 ; V_34 < V_46 ; V_34 ++ ) {
V_35 = F_26 ( V_15 , V_47 [ V_34 ] ) ;
if ( V_35 )
goto V_50;
F_25 ( & V_47 [ V_34 ] -> V_31 , & V_15 -> V_51 ) ;
}
F_20 ( V_47 ) ;
return 0 ;
V_50:
for ( V_34 -- ; V_34 >= 0 ; V_34 -- )
F_21 ( V_15 , V_47 [ V_34 ] ) ;
V_34 = V_46 - 1 ;
V_49:
for ( V_34 -- ; V_34 >= 0 ; V_34 -- )
F_20 ( V_47 [ V_34 ] ) ;
F_20 ( V_47 ) ;
return V_35 ;
}
static void F_34 ( struct V_15 * V_15 ,
const struct V_25 * V_27 ,
T_1 V_46 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_46 ; V_34 ++ , V_27 ++ ) {
struct V_25 * V_52 ;
V_52 = F_16 ( V_15 , V_27 -> V_28 ) ;
if ( V_52 )
F_27 ( V_15 , V_52 ) ;
}
}
static void F_35 ( struct V_15 * V_15 ,
const struct V_25 * V_27 ,
T_1 V_46 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_46 ; V_34 ++ , V_27 ++ ) {
struct V_25 * V_52 ;
V_52 = F_16 ( V_15 , V_27 -> V_28 ) ;
if ( V_52 ) {
F_21 ( V_15 , V_52 ) ;
F_19 ( & V_52 -> V_31 ) ;
F_20 ( V_52 ) ;
}
}
}
int F_36 ( struct V_15 * V_15 ,
const struct V_25 * V_27 ,
T_1 V_46 )
{
int V_35 ;
V_35 = F_31 ( V_15 , V_27 , V_46 ) ;
if ( V_35 )
return V_35 ;
F_37 ( V_15 ) ;
return 0 ;
}
void F_38 ( struct V_15 * V_15 ,
const struct V_25 * V_27 ,
T_1 V_46 )
{
F_34 ( V_15 , V_27 , V_46 ) ;
F_37 ( V_15 ) ;
F_35 ( V_15 , V_27 , V_46 ) ;
}
static int F_39 ( struct V_15 * V_15 ,
struct V_29 * V_30 ,
struct V_53 * V_54 )
{
if ( ! V_30 -> V_27 -> V_55 )
return - V_56 ;
return V_30 -> V_27 -> V_55 ( V_15 , V_54 ) ;
}
static int F_40 ( struct V_15 * V_15 ,
struct V_29 * V_30 ,
struct V_53 * V_54 )
{
if ( ! V_30 -> V_27 -> V_57 )
return - V_56 ;
return V_30 -> V_27 -> V_57 ( V_15 , V_54 ) ;
}
void F_41 ( struct V_58 * V_59 )
{
struct V_29 * V_30 ;
V_30 = F_42 ( V_59 , struct V_29 , V_17 ) ;
V_30 -> V_39 = true ;
}
void F_43 ( struct V_15 * V_15 )
{
F_37 ( V_15 ) ;
}
static struct V_60 * F_44 ( const char * V_61 )
{
struct V_60 * V_62 ;
F_17 (mitem, &mode_list, list) {
if ( strcmp ( V_62 -> V_63 -> V_61 , V_61 ) == 0 )
return V_62 ;
}
return NULL ;
}
static bool F_45 ( const char * V_28 )
{
while ( * V_28 != '\0' ) {
if ( ! isalpha ( * V_28 ) && ! isdigit ( * V_28 ) && * V_28 != '_' )
return false ;
V_28 ++ ;
}
return true ;
}
int F_46 ( const struct V_64 * V_63 )
{
int V_35 = 0 ;
struct V_60 * V_62 ;
if ( ! F_45 ( V_63 -> V_61 ) ||
V_63 -> V_65 > V_66 )
return - V_67 ;
V_62 = F_24 ( sizeof( * V_62 ) , V_36 ) ;
if ( ! V_62 )
return - V_37 ;
F_47 ( & V_68 ) ;
if ( F_44 ( V_63 -> V_61 ) ) {
V_35 = - V_48 ;
F_20 ( V_62 ) ;
goto V_69;
}
V_62 -> V_63 = V_63 ;
F_25 ( & V_62 -> V_31 , & V_70 ) ;
V_69:
F_48 ( & V_68 ) ;
return V_35 ;
}
void F_49 ( const struct V_64 * V_63 )
{
struct V_60 * V_62 ;
F_47 ( & V_68 ) ;
V_62 = F_44 ( V_63 -> V_61 ) ;
if ( V_62 ) {
F_50 ( & V_62 -> V_31 ) ;
F_20 ( V_62 ) ;
}
F_48 ( & V_68 ) ;
}
static const struct V_64 * F_51 ( const char * V_61 )
{
struct V_60 * V_62 ;
const struct V_64 * V_63 = NULL ;
F_47 ( & V_68 ) ;
V_62 = F_44 ( V_61 ) ;
if ( ! V_62 ) {
F_48 ( & V_68 ) ;
F_52 ( L_1 , V_61 ) ;
F_47 ( & V_68 ) ;
V_62 = F_44 ( V_61 ) ;
}
if ( V_62 ) {
V_63 = V_62 -> V_63 ;
if ( ! F_53 ( V_63 -> V_71 ) )
V_63 = NULL ;
}
F_48 ( & V_68 ) ;
return V_63 ;
}
static void F_54 ( const struct V_64 * V_63 )
{
F_55 ( V_63 -> V_71 ) ;
}
static bool F_56 ( struct V_15 * V_15 , struct V_72 * V_73 )
{
F_57 ( V_73 ) ;
return false ;
}
static T_2 F_58 ( struct V_15 * V_15 ,
struct V_1 * V_5 ,
struct V_72 * V_73 )
{
return V_74 ;
}
static bool F_59 ( struct V_15 * V_15 )
{
return V_15 -> V_63 != & V_75 ;
}
static void F_60 ( struct V_15 * V_15 )
{
V_15 -> V_76 = false ;
V_15 -> V_63 = & V_75 ;
}
static void F_61 ( struct V_15 * V_15 )
{
if ( ! V_15 -> V_77 || ! F_59 ( V_15 ) ||
! V_15 -> V_63 -> V_78 -> V_79 )
V_15 -> V_78 . V_79 = F_56 ;
else
V_15 -> V_78 . V_79 = V_15 -> V_63 -> V_78 -> V_79 ;
if ( ! V_15 -> V_77 || ! F_59 ( V_15 ) ||
! V_15 -> V_63 -> V_78 -> V_80 )
V_15 -> V_78 . V_80 = F_58 ;
else
V_15 -> V_78 . V_80 = V_15 -> V_63 -> V_78 -> V_80 ;
}
static int F_62 ( struct V_15 * V_15 ,
const struct V_64 * V_81 )
{
if ( F_59 ( V_15 ) ) {
void (* F_63)( struct V_15 * V_15 ) = V_15 -> V_78 . exit ;
memset ( & V_15 -> V_78 , 0 , sizeof( struct V_82 ) ) ;
F_61 ( V_15 ) ;
if ( F_63 )
F_63 ( V_15 ) ;
F_54 ( V_15 -> V_63 ) ;
F_60 ( V_15 ) ;
memset ( & V_15 -> V_83 , 0 ,
sizeof( struct V_15 ) - F_64 ( struct V_15 , V_83 ) ) ;
}
if ( ! V_81 )
return 0 ;
if ( V_81 -> V_78 -> V_42 ) {
int V_35 ;
V_35 = V_81 -> V_78 -> V_42 ( V_15 ) ;
if ( V_35 )
return V_35 ;
}
V_15 -> V_63 = V_81 ;
memcpy ( & V_15 -> V_78 , V_81 -> V_78 , sizeof( struct V_82 ) ) ;
F_61 ( V_15 ) ;
return 0 ;
}
static int F_65 ( struct V_15 * V_15 , const char * V_61 )
{
const struct V_64 * V_81 ;
struct V_2 * V_3 = V_15 -> V_3 ;
int V_35 ;
if ( ! F_66 ( & V_15 -> V_84 ) ) {
F_67 ( V_3 , L_2 ) ;
return - V_85 ;
}
if ( F_59 ( V_15 ) && strcmp ( V_15 -> V_63 -> V_61 , V_61 ) == 0 ) {
F_67 ( V_3 , L_3 ) ;
return - V_67 ;
}
V_81 = F_51 ( V_61 ) ;
if ( ! V_81 ) {
F_67 ( V_3 , L_4 , V_61 ) ;
return - V_67 ;
}
V_35 = F_62 ( V_15 , V_81 ) ;
if ( V_35 ) {
F_67 ( V_3 , L_5 , V_61 ) ;
F_54 ( V_81 ) ;
return V_35 ;
}
F_68 ( V_3 , L_6 , V_61 ) ;
return 0 ;
}
static void F_69 ( struct V_86 * V_87 )
{
struct V_15 * V_15 ;
int V_88 ;
V_15 = F_42 ( V_87 , struct V_15 , V_89 . V_90 . V_87 ) ;
if ( ! F_70 () ) {
F_71 ( & V_15 -> V_89 . V_90 , 0 ) ;
return;
}
V_88 = F_72 ( & V_15 -> V_89 . V_91 ) ;
if ( V_88 < 0 ) {
F_73 () ;
return;
}
F_74 ( V_92 , V_15 -> V_3 ) ;
F_73 () ;
if ( V_88 )
F_71 ( & V_15 -> V_89 . V_90 ,
F_75 ( V_15 -> V_89 . V_93 ) ) ;
}
static void F_76 ( struct V_15 * V_15 )
{
if ( ! V_15 -> V_89 . V_94 || ! F_77 ( V_15 -> V_3 ) )
return;
F_78 ( V_15 -> V_89 . V_94 , & V_15 -> V_89 . V_91 ) ;
F_71 ( & V_15 -> V_89 . V_90 , 0 ) ;
}
static void F_79 ( struct V_15 * V_15 )
{
F_80 ( & V_15 -> V_89 . V_90 , F_69 ) ;
}
static void F_81 ( struct V_15 * V_15 )
{
F_82 ( & V_15 -> V_89 . V_90 ) ;
}
static void F_83 ( struct V_86 * V_87 )
{
struct V_15 * V_15 ;
int V_88 ;
V_15 = F_42 ( V_87 , struct V_15 , V_95 . V_90 . V_87 ) ;
if ( ! F_70 () ) {
F_71 ( & V_15 -> V_95 . V_90 , 0 ) ;
return;
}
V_88 = F_72 ( & V_15 -> V_95 . V_91 ) ;
if ( V_88 < 0 ) {
F_73 () ;
return;
}
F_74 ( V_96 , V_15 -> V_3 ) ;
F_73 () ;
if ( V_88 )
F_71 ( & V_15 -> V_95 . V_90 ,
F_75 ( V_15 -> V_95 . V_93 ) ) ;
}
static void F_84 ( struct V_15 * V_15 )
{
if ( ! V_15 -> V_95 . V_94 || ! F_77 ( V_15 -> V_3 ) )
return;
F_78 ( V_15 -> V_95 . V_94 , & V_15 -> V_95 . V_91 ) ;
F_71 ( & V_15 -> V_95 . V_90 , 0 ) ;
}
static void F_85 ( struct V_15 * V_15 )
{
F_80 ( & V_15 -> V_95 . V_90 , F_83 ) ;
}
static void F_86 ( struct V_15 * V_15 )
{
F_82 ( & V_15 -> V_95 . V_90 ) ;
}
static T_2 F_87 ( struct V_72 * * V_97 )
{
struct V_72 * V_73 = * V_97 ;
struct V_1 * V_5 ;
struct V_15 * V_15 ;
T_2 V_98 ;
V_73 = F_88 ( V_73 , V_99 ) ;
if ( ! V_73 )
return V_100 ;
* V_97 = V_73 ;
V_5 = F_1 ( V_73 -> V_3 ) ;
V_15 = V_5 -> V_15 ;
if ( ! F_13 ( V_5 ) ) {
V_98 = V_101 ;
} else {
V_98 = V_15 -> V_78 . V_80 ( V_15 , V_5 , V_73 ) ;
}
if ( V_98 == V_74 ) {
struct V_102 * V_103 ;
V_103 = F_89 ( V_15 -> V_103 ) ;
F_90 ( & V_103 -> V_104 ) ;
V_103 -> V_105 ++ ;
V_103 -> V_106 += V_73 -> V_107 ;
if ( V_73 -> V_108 == V_109 )
V_103 -> V_110 ++ ;
F_91 ( & V_103 -> V_104 ) ;
V_73 -> V_3 = V_15 -> V_3 ;
} else if ( V_98 == V_101 ) {
F_92 ( V_15 -> V_103 -> V_111 ) ;
} else {
F_92 ( V_15 -> V_103 -> V_112 ) ;
}
return V_98 ;
}
static int F_93 ( struct V_15 * V_15 )
{
struct V_113 * V_114 ;
unsigned int V_115 = V_15 -> V_3 -> V_116 - 1 ;
unsigned int V_34 ;
if ( ! V_115 )
return 0 ;
V_114 = F_24 ( sizeof( struct V_113 ) * V_115 , V_36 ) ;
if ( ! V_114 )
return - V_37 ;
V_15 -> V_117 = V_114 ;
for ( V_34 = 0 ; V_34 < V_115 ; V_34 ++ )
F_94 ( V_114 ++ ) ;
return 0 ;
}
static void F_95 ( struct V_15 * V_15 )
{
F_20 ( V_15 -> V_117 ) ;
}
static struct V_113 * F_96 ( struct V_15 * V_15 , T_3 V_118 )
{
return & V_15 -> V_117 [ V_118 - 1 ] ;
}
static bool F_97 ( struct V_15 * V_15 , struct V_72 * V_73 )
{
struct V_113 * V_119 ;
struct V_1 * V_5 ;
if ( ! V_15 -> V_120 || ! V_73 -> V_121 )
return false ;
V_119 = F_96 ( V_15 , V_73 -> V_121 ) ;
F_98 (port, qom_list, qom_list) {
if ( ! F_99 ( V_15 , V_5 , V_73 ) )
return true ;
}
return false ;
}
static void F_100 ( struct V_15 * V_15 ,
struct V_1 * V_5 )
{
if ( ! V_5 -> V_118 )
return;
F_101 ( & V_5 -> V_119 ) ;
}
static bool F_102 ( struct V_1 * V_5 ,
struct V_1 * V_122 )
{
if ( V_5 -> V_123 < V_122 -> V_123 )
return true ;
if ( V_5 -> V_123 > V_122 -> V_123 )
return false ;
if ( V_5 -> V_124 < V_122 -> V_124 )
return true ;
return false ;
}
static void F_103 ( struct V_15 * V_15 ,
struct V_1 * V_5 )
{
struct V_1 * V_122 ;
struct V_113 * V_119 ;
struct V_113 * V_125 ;
if ( ! V_5 -> V_118 )
return;
V_119 = F_96 ( V_15 , V_5 -> V_118 ) ;
V_125 = V_119 ;
F_17 (cur, qom_list, qom_list) {
if ( F_102 ( V_5 , V_122 ) )
break;
V_125 = & V_122 -> V_119 ;
}
F_104 ( & V_5 -> V_119 , V_125 ) ;
}
static void F_105 ( struct V_15 * V_15 )
{
struct V_1 * V_5 ;
bool V_126 = false ;
F_17 (port, &team->port_list, list) {
if ( V_5 -> V_118 ) {
V_126 = true ;
break;
}
}
if ( V_126 == V_15 -> V_120 )
return;
F_106 ( V_15 -> V_3 , L_7 ,
V_126 ? L_8 : L_9 ) ;
V_15 -> V_120 = V_126 ;
}
static void F_107 ( struct V_15 * V_15 ,
struct V_1 * V_5 )
{
if ( ! V_5 -> V_118 || F_13 ( V_5 ) )
return;
F_100 ( V_15 , V_5 ) ;
F_103 ( V_15 , V_5 ) ;
F_105 ( V_15 ) ;
}
static void F_108 ( struct V_15 * V_15 ,
struct V_1 * V_5 ,
T_3 V_127 )
{
if ( F_13 ( V_5 ) ) {
F_100 ( V_15 , V_5 ) ;
V_5 -> V_118 = V_127 ;
F_103 ( V_15 , V_5 ) ;
F_105 ( V_15 ) ;
} else {
V_5 -> V_118 = V_127 ;
}
}
static void F_109 ( struct V_15 * V_15 ,
struct V_1 * V_5 )
{
F_103 ( V_15 , V_5 ) ;
F_105 ( V_15 ) ;
}
static void F_110 ( struct V_15 * V_15 ,
struct V_1 * V_5 )
{
F_100 ( V_15 , V_5 ) ;
F_105 ( V_15 ) ;
}
static bool F_111 ( const struct V_15 * V_15 ,
const struct V_1 * V_5 )
{
struct V_1 * V_122 ;
F_17 (cur, &team->port_list, list)
if ( V_122 == V_5 )
return true ;
return false ;
}
static void F_112 ( struct V_15 * V_15 ,
struct V_1 * V_5 )
{
if ( F_13 ( V_5 ) )
return;
V_5 -> V_124 = V_15 -> V_77 ++ ;
F_113 ( & V_5 -> V_128 ,
F_114 ( V_15 , V_5 -> V_124 ) ) ;
F_61 ( V_15 ) ;
F_109 ( V_15 , V_5 ) ;
if ( V_15 -> V_78 . V_129 )
V_15 -> V_78 . V_129 ( V_15 , V_5 ) ;
F_76 ( V_15 ) ;
F_84 ( V_15 ) ;
F_12 ( V_5 ) ;
}
static void F_115 ( struct V_15 * V_15 , int V_130 )
{
int V_34 ;
struct V_1 * V_5 ;
for ( V_34 = V_130 + 1 ; V_34 < V_15 -> V_77 ; V_34 ++ ) {
V_5 = F_116 ( V_15 , V_34 ) ;
F_117 ( & V_5 -> V_128 ) ;
V_5 -> V_124 -- ;
F_113 ( & V_5 -> V_128 ,
F_114 ( V_15 , V_5 -> V_124 ) ) ;
}
}
static void F_118 ( struct V_15 * V_15 ,
struct V_1 * V_5 )
{
if ( ! F_13 ( V_5 ) )
return;
if ( V_15 -> V_78 . V_131 )
V_15 -> V_78 . V_131 ( V_15 , V_5 ) ;
F_117 ( & V_5 -> V_128 ) ;
F_115 ( V_15 , V_5 -> V_124 ) ;
V_5 -> V_124 = - 1 ;
V_15 -> V_77 -- ;
F_110 ( V_15 , V_5 ) ;
F_61 ( V_15 ) ;
F_76 ( V_15 ) ;
F_84 ( V_15 ) ;
F_12 ( V_5 ) ;
}
static void F_119 ( struct V_15 * V_15 )
{
struct V_1 * V_5 ;
T_4 V_132 = V_133 & V_134 ;
T_5 V_135 = V_136 ;
unsigned short V_137 = V_138 ;
unsigned int V_139 = V_140 |
V_141 ;
F_17 (port, &team->port_list, list) {
V_132 = F_120 ( V_132 ,
V_5 -> V_3 -> V_132 ,
V_133 ) ;
V_135 =
F_120 ( V_135 ,
V_5 -> V_3 -> V_142 ,
V_136 ) ;
V_139 &= V_5 -> V_3 -> V_143 ;
if ( V_5 -> V_3 -> V_144 > V_137 )
V_137 = V_5 -> V_3 -> V_144 ;
}
V_15 -> V_3 -> V_132 = V_132 ;
V_15 -> V_3 -> V_142 = V_135 | V_145 ;
V_15 -> V_3 -> V_144 = V_137 ;
V_15 -> V_3 -> V_143 &= ~ V_140 ;
if ( V_139 == ( V_140 | V_141 ) )
V_15 -> V_3 -> V_143 |= V_140 ;
}
static void F_121 ( struct V_15 * V_15 )
{
F_122 ( & V_15 -> V_146 ) ;
F_119 ( V_15 ) ;
F_123 ( & V_15 -> V_146 ) ;
F_124 ( V_15 -> V_3 ) ;
}
static int F_125 ( struct V_15 * V_15 , struct V_1 * V_5 )
{
int V_35 = 0 ;
F_126 ( V_15 -> V_3 ) ;
if ( V_15 -> V_78 . V_147 ) {
V_35 = V_15 -> V_78 . V_147 ( V_15 , V_5 ) ;
if ( V_35 ) {
F_67 ( V_15 -> V_3 , L_10 ,
V_5 -> V_3 -> V_28 ) ;
goto V_148;
}
}
return 0 ;
V_148:
F_127 ( V_15 -> V_3 ) ;
return V_35 ;
}
static void F_128 ( struct V_15 * V_15 , struct V_1 * V_5 )
{
if ( V_15 -> V_78 . V_149 )
V_15 -> V_78 . V_149 ( V_15 , V_5 ) ;
F_127 ( V_15 -> V_3 ) ;
}
static int F_129 ( struct V_15 * V_15 , struct V_1 * V_5 )
{
struct V_150 * V_151 ;
int V_35 ;
if ( ! V_15 -> V_3 -> V_152 )
return 0 ;
V_151 = F_32 ( sizeof( * V_151 ) , V_36 ) ;
if ( ! V_151 )
return - V_37 ;
V_35 = F_130 ( V_151 , V_5 -> V_3 ) ;
if ( V_35 ) {
F_20 ( V_151 ) ;
return V_35 ;
}
V_5 -> V_151 = V_151 ;
return V_35 ;
}
static void F_131 ( struct V_1 * V_5 )
{
struct V_150 * V_151 = V_5 -> V_151 ;
if ( ! V_151 )
return;
V_5 -> V_151 = NULL ;
F_132 () ;
F_133 ( V_151 ) ;
F_20 ( V_151 ) ;
}
static int F_129 ( struct V_15 * V_15 , struct V_1 * V_5 )
{
return 0 ;
}
static void F_131 ( struct V_1 * V_5 )
{
}
static int F_134 ( struct V_15 * V_15 , struct V_1 * V_5 )
{
struct V_153 V_154 ;
int V_35 ;
V_154 . V_155 = V_15 -> V_63 -> V_156 ;
V_35 = F_135 ( V_5 -> V_3 , V_15 -> V_3 , NULL ,
& V_154 ) ;
if ( V_35 )
return V_35 ;
V_5 -> V_3 -> V_143 |= V_157 ;
return 0 ;
}
static void F_136 ( struct V_15 * V_15 , struct V_1 * V_5 )
{
F_137 ( V_5 -> V_3 , V_15 -> V_3 ) ;
V_5 -> V_3 -> V_143 &= ~ V_157 ;
}
static int F_138 ( struct V_15 * V_15 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_1 * V_5 ;
char * V_158 = V_6 -> V_28 ;
int V_35 ;
if ( V_6 -> V_159 & V_160 ) {
F_67 ( V_3 , L_11 ,
V_158 ) ;
return - V_67 ;
}
if ( F_5 ( V_6 ) ) {
F_67 ( V_3 , L_12
L_13 , V_158 ) ;
return - V_85 ;
}
if ( V_6 -> V_161 & V_162 &&
F_139 ( V_3 ) ) {
F_67 ( V_3 , L_14 ,
V_158 ) ;
return - V_163 ;
}
V_35 = F_140 ( V_3 , V_6 ) ;
if ( V_35 )
return V_35 ;
if ( V_6 -> V_159 & V_164 ) {
F_67 ( V_3 , L_15 ,
V_158 ) ;
return - V_85 ;
}
V_5 = F_32 ( sizeof( struct V_1 ) + V_15 -> V_63 -> V_165 ,
V_36 ) ;
if ( ! V_5 )
return - V_37 ;
V_5 -> V_3 = V_6 ;
V_5 -> V_15 = V_15 ;
F_94 ( & V_5 -> V_119 ) ;
V_5 -> V_14 . V_166 = V_6 -> V_166 ;
V_35 = F_141 ( V_6 , V_3 -> V_166 ) ;
if ( V_35 ) {
F_106 ( V_3 , L_16 , V_35 ) ;
goto V_167;
}
memcpy ( V_5 -> V_14 . V_7 , V_6 -> V_7 , V_6 -> V_11 ) ;
V_35 = F_125 ( V_15 , V_5 ) ;
if ( V_35 ) {
F_67 ( V_3 , L_10 ,
V_158 ) ;
goto V_148;
}
V_35 = F_142 ( V_6 ) ;
if ( V_35 ) {
F_106 ( V_3 , L_17 ,
V_158 ) ;
goto V_168;
}
F_143 ( V_3 ) ;
F_144 ( V_6 , V_3 ) ;
F_145 ( V_6 , V_3 ) ;
F_146 ( V_3 ) ;
V_35 = F_147 ( V_6 , V_3 ) ;
if ( V_35 ) {
F_67 ( V_3 , L_18 ,
V_158 ) ;
goto V_169;
}
V_35 = F_129 ( V_15 , V_5 ) ;
if ( V_35 ) {
F_67 ( V_3 , L_19 ,
V_158 ) ;
goto V_170;
}
if ( ! ( V_3 -> V_161 & V_171 ) )
F_148 ( V_6 ) ;
V_35 = F_149 ( V_6 , F_87 ,
V_5 ) ;
if ( V_35 ) {
F_67 ( V_3 , L_20 ,
V_158 ) ;
goto V_172;
}
V_35 = F_134 ( V_15 , V_5 ) ;
if ( V_35 ) {
F_67 ( V_3 , L_21 ,
V_158 ) ;
goto V_173;
}
V_35 = F_29 ( V_15 , V_5 ) ;
if ( V_35 ) {
F_67 ( V_3 , L_22 ,
V_158 ) ;
goto V_174;
}
V_5 -> V_124 = - 1 ;
F_104 ( & V_5 -> V_31 , & V_15 -> V_84 ) ;
F_112 ( V_15 , V_5 ) ;
F_119 ( V_15 ) ;
F_150 ( V_5 , ! ! F_151 ( V_6 ) ) ;
F_37 ( V_15 ) ;
F_68 ( V_3 , L_23 , V_158 ) ;
return 0 ;
V_174:
F_136 ( V_15 , V_5 ) ;
V_173:
F_152 ( V_6 ) ;
V_172:
F_131 ( V_5 ) ;
V_170:
F_153 ( V_6 , V_3 ) ;
V_169:
F_154 ( V_6 , V_3 ) ;
F_155 ( V_6 , V_3 ) ;
F_156 ( V_6 ) ;
V_168:
F_128 ( V_15 , V_5 ) ;
F_8 ( V_5 ) ;
V_148:
F_141 ( V_6 , V_5 -> V_14 . V_166 ) ;
V_167:
F_20 ( V_5 ) ;
return V_35 ;
}
static int F_157 ( struct V_15 * V_15 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_1 * V_5 ;
char * V_158 = V_6 -> V_28 ;
V_5 = F_3 ( V_6 ) ;
if ( ! V_5 || ! F_111 ( V_15 , V_5 ) ) {
F_67 ( V_3 , L_24 ,
V_158 ) ;
return - V_175 ;
}
F_118 ( V_15 , V_5 ) ;
F_101 ( & V_5 -> V_31 ) ;
F_136 ( V_15 , V_5 ) ;
F_152 ( V_6 ) ;
F_131 ( V_5 ) ;
F_153 ( V_6 , V_3 ) ;
F_154 ( V_6 , V_3 ) ;
F_155 ( V_6 , V_3 ) ;
F_156 ( V_6 ) ;
F_128 ( V_15 , V_5 ) ;
F_30 ( V_15 , V_5 ) ;
F_37 ( V_15 ) ;
F_28 ( V_15 , V_5 ) ;
F_158 ( V_5 ) ;
F_8 ( V_5 ) ;
F_141 ( V_6 , V_5 -> V_14 . V_166 ) ;
F_159 ( V_5 , V_176 ) ;
F_68 ( V_3 , L_25 , V_158 ) ;
F_119 ( V_15 ) ;
return 0 ;
}
static int F_160 ( struct V_15 * V_15 , struct V_53 * V_54 )
{
V_54 -> V_177 . V_178 = V_15 -> V_63 -> V_61 ;
return 0 ;
}
static int F_161 ( struct V_15 * V_15 , struct V_53 * V_54 )
{
return F_65 ( V_15 , V_54 -> V_177 . V_178 ) ;
}
static int F_162 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
V_54 -> V_177 . V_179 = V_15 -> V_89 . V_94 ;
return 0 ;
}
static int F_163 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
V_15 -> V_89 . V_94 = V_54 -> V_177 . V_179 ;
return 0 ;
}
static int F_164 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
V_54 -> V_177 . V_179 = V_15 -> V_89 . V_93 ;
return 0 ;
}
static int F_165 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
V_15 -> V_89 . V_93 = V_54 -> V_177 . V_179 ;
return 0 ;
}
static int F_166 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
V_54 -> V_177 . V_179 = V_15 -> V_95 . V_94 ;
return 0 ;
}
static int F_167 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
V_15 -> V_95 . V_94 = V_54 -> V_177 . V_179 ;
return 0 ;
}
static int F_168 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
V_54 -> V_177 . V_179 = V_15 -> V_95 . V_93 ;
return 0 ;
}
static int F_169 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
V_15 -> V_95 . V_93 = V_54 -> V_177 . V_179 ;
return 0 ;
}
static int F_170 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
struct V_1 * V_5 = V_54 -> V_17 -> V_5 ;
V_54 -> V_177 . V_180 = F_13 ( V_5 ) ;
return 0 ;
}
static int F_171 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
struct V_1 * V_5 = V_54 -> V_17 -> V_5 ;
if ( V_54 -> V_177 . V_180 )
F_112 ( V_15 , V_5 ) ;
else
F_118 ( V_15 , V_5 ) ;
return 0 ;
}
static int F_172 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
struct V_1 * V_5 = V_54 -> V_17 -> V_5 ;
V_54 -> V_177 . V_180 = V_5 -> V_22 . V_19 ;
return 0 ;
}
static int F_173 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
struct V_1 * V_5 = V_54 -> V_17 -> V_5 ;
V_5 -> V_22 . V_19 = V_54 -> V_177 . V_180 ;
F_15 ( V_5 ) ;
F_174 ( V_5 -> V_15 ) ;
return 0 ;
}
static int F_175 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
struct V_1 * V_5 = V_54 -> V_17 -> V_5 ;
V_54 -> V_177 . V_180 = V_5 -> V_22 . V_23 ;
return 0 ;
}
static int F_176 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
struct V_1 * V_5 = V_54 -> V_17 -> V_5 ;
V_5 -> V_22 . V_23 = V_54 -> V_177 . V_180 ;
F_15 ( V_5 ) ;
F_174 ( V_5 -> V_15 ) ;
return 0 ;
}
static int F_177 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
struct V_1 * V_5 = V_54 -> V_17 -> V_5 ;
V_54 -> V_177 . V_181 = V_5 -> V_123 ;
return 0 ;
}
static int F_178 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
struct V_1 * V_5 = V_54 -> V_17 -> V_5 ;
T_6 V_123 = V_54 -> V_177 . V_181 ;
if ( V_5 -> V_123 == V_123 )
return 0 ;
V_5 -> V_123 = V_123 ;
F_107 ( V_15 , V_5 ) ;
return 0 ;
}
static int F_179 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
struct V_1 * V_5 = V_54 -> V_17 -> V_5 ;
V_54 -> V_177 . V_179 = V_5 -> V_118 ;
return 0 ;
}
static int F_180 ( struct V_15 * V_15 ,
struct V_53 * V_54 )
{
struct V_1 * V_5 = V_54 -> V_17 -> V_5 ;
T_3 V_127 = V_54 -> V_177 . V_179 ;
if ( V_5 -> V_118 == V_127 )
return 0 ;
if ( V_127 >= V_15 -> V_3 -> V_182 )
return - V_67 ;
F_108 ( V_15 , V_5 , V_127 ) ;
return 0 ;
}
static int F_181 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_182 ( V_3 ) ;
int V_34 ;
int V_35 ;
V_15 -> V_3 = V_3 ;
F_183 ( & V_15 -> V_146 ) ;
F_60 ( V_15 ) ;
V_15 -> V_103 = F_184 ( struct V_102 ) ;
if ( ! V_15 -> V_103 )
return - V_37 ;
for ( V_34 = 0 ; V_34 < V_183 ; V_34 ++ )
F_185 ( & V_15 -> V_184 [ V_34 ] ) ;
F_94 ( & V_15 -> V_84 ) ;
V_35 = F_93 ( V_15 ) ;
if ( V_35 )
goto V_185;
F_61 ( V_15 ) ;
F_94 ( & V_15 -> V_51 ) ;
F_94 ( & V_15 -> V_41 ) ;
F_79 ( V_15 ) ;
F_85 ( V_15 ) ;
V_35 = F_36 ( V_15 , V_186 , F_186 ( V_186 ) ) ;
if ( V_35 )
goto V_187;
F_187 ( V_3 ) ;
F_188 ( V_3 ) ;
return 0 ;
V_187:
F_86 ( V_15 ) ;
F_81 ( V_15 ) ;
F_95 ( V_15 ) ;
V_185:
F_189 ( V_15 -> V_103 ) ;
return V_35 ;
}
static void F_190 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_182 ( V_3 ) ;
struct V_1 * V_5 ;
struct V_1 * V_32 ;
F_122 ( & V_15 -> V_146 ) ;
F_22 (port, tmp, &team->port_list, list)
F_157 ( V_15 , V_5 -> V_3 ) ;
F_62 ( V_15 , NULL ) ;
F_35 ( V_15 , V_186 , F_186 ( V_186 ) ) ;
F_86 ( V_15 ) ;
F_81 ( V_15 ) ;
F_95 ( V_15 ) ;
F_123 ( & V_15 -> V_146 ) ;
F_124 ( V_3 ) ;
}
static void F_191 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_182 ( V_3 ) ;
F_189 ( V_15 -> V_103 ) ;
}
static int F_192 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_193 ( struct V_2 * V_3 )
{
return 0 ;
}
static T_7 F_194 ( struct V_72 * V_73 , struct V_2 * V_3 )
{
struct V_15 * V_15 = F_182 ( V_3 ) ;
bool V_188 ;
unsigned int V_107 = V_73 -> V_107 ;
V_188 = F_97 ( V_15 , V_73 ) ;
if ( ! V_188 )
V_188 = V_15 -> V_78 . V_79 ( V_15 , V_73 ) ;
if ( V_188 ) {
struct V_102 * V_103 ;
V_103 = F_89 ( V_15 -> V_103 ) ;
F_90 ( & V_103 -> V_104 ) ;
V_103 -> V_189 ++ ;
V_103 -> V_190 += V_107 ;
F_91 ( & V_103 -> V_104 ) ;
} else {
F_92 ( V_15 -> V_103 -> V_191 ) ;
}
return V_192 ;
}
static T_3 F_195 ( struct V_2 * V_3 , struct V_72 * V_73 ,
void * V_193 , T_8 V_194 )
{
T_3 V_195 = F_196 ( V_73 ) ? F_197 ( V_73 ) : 0 ;
F_198 ( V_73 ) -> V_196 = V_73 -> V_121 ;
if ( F_199 ( V_195 >= V_3 -> V_182 ) ) {
do {
V_195 -= V_3 -> V_182 ;
} while ( V_195 >= V_3 -> V_182 );
}
return V_195 ;
}
static void F_200 ( struct V_2 * V_3 , int V_197 )
{
struct V_15 * V_15 = F_182 ( V_3 ) ;
struct V_1 * V_5 ;
int V_198 ;
F_201 () ;
F_98 (port, &team->port_list, list) {
if ( V_197 & V_199 ) {
V_198 = V_3 -> V_159 & V_199 ? 1 : - 1 ;
F_202 ( V_5 -> V_3 , V_198 ) ;
}
if ( V_197 & V_200 ) {
V_198 = V_3 -> V_159 & V_200 ? 1 : - 1 ;
F_203 ( V_5 -> V_3 , V_198 ) ;
}
}
F_204 () ;
}
static void F_205 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_182 ( V_3 ) ;
struct V_1 * V_5 ;
F_201 () ;
F_98 (port, &team->port_list, list) {
F_144 ( V_5 -> V_3 , V_3 ) ;
F_145 ( V_5 -> V_3 , V_3 ) ;
}
F_204 () ;
}
static int F_206 ( struct V_2 * V_3 , void * V_201 )
{
struct V_13 * V_9 = V_201 ;
struct V_15 * V_15 = F_182 ( V_3 ) ;
struct V_1 * V_5 ;
if ( V_3 -> type == V_202 && ! F_207 ( V_9 -> V_203 ) )
return - V_204 ;
memcpy ( V_3 -> V_7 , V_9 -> V_203 , V_3 -> V_11 ) ;
F_122 ( & V_15 -> V_146 ) ;
F_17 (port, &team->port_list, list)
if ( V_15 -> V_78 . V_205 )
V_15 -> V_78 . V_205 ( V_15 , V_5 ) ;
F_123 ( & V_15 -> V_146 ) ;
return 0 ;
}
static int F_208 ( struct V_2 * V_3 , int V_206 )
{
struct V_15 * V_15 = F_182 ( V_3 ) ;
struct V_1 * V_5 ;
int V_35 ;
F_122 ( & V_15 -> V_146 ) ;
V_15 -> V_207 = true ;
F_17 (port, &team->port_list, list) {
V_35 = F_141 ( V_5 -> V_3 , V_206 ) ;
if ( V_35 ) {
F_67 ( V_3 , L_26 ,
V_5 -> V_3 -> V_28 ) ;
goto V_208;
}
}
V_15 -> V_207 = false ;
F_123 ( & V_15 -> V_146 ) ;
V_3 -> V_166 = V_206 ;
return 0 ;
V_208:
F_209 (port, &team->port_list, list)
F_141 ( V_5 -> V_3 , V_3 -> V_166 ) ;
V_15 -> V_207 = false ;
F_123 ( & V_15 -> V_146 ) ;
return V_35 ;
}
static void
F_210 ( struct V_2 * V_3 , struct V_209 * V_210 )
{
struct V_15 * V_15 = F_182 ( V_3 ) ;
struct V_102 * V_201 ;
T_9 V_105 , V_106 , V_110 , V_189 , V_190 ;
T_4 V_112 = 0 , V_191 = 0 , V_111 = 0 ;
unsigned int V_211 ;
int V_34 ;
F_211 (i) {
V_201 = F_212 ( V_15 -> V_103 , V_34 ) ;
do {
V_211 = F_213 ( & V_201 -> V_104 ) ;
V_105 = V_201 -> V_105 ;
V_106 = V_201 -> V_106 ;
V_110 = V_201 -> V_110 ;
V_189 = V_201 -> V_189 ;
V_190 = V_201 -> V_190 ;
} while ( F_214 ( & V_201 -> V_104 , V_211 ) );
V_210 -> V_105 += V_105 ;
V_210 -> V_106 += V_106 ;
V_210 -> V_212 += V_110 ;
V_210 -> V_189 += V_189 ;
V_210 -> V_190 += V_190 ;
V_112 += V_201 -> V_112 ;
V_191 += V_201 -> V_191 ;
V_111 += V_201 -> V_111 ;
}
V_210 -> V_112 = V_112 ;
V_210 -> V_191 = V_191 ;
V_210 -> V_111 = V_111 ;
}
static int F_215 ( struct V_2 * V_3 , T_10 V_213 , T_3 V_214 )
{
struct V_15 * V_15 = F_182 ( V_3 ) ;
struct V_1 * V_5 ;
int V_35 ;
F_122 ( & V_15 -> V_146 ) ;
F_17 (port, &team->port_list, list) {
V_35 = F_216 ( V_5 -> V_3 , V_213 , V_214 ) ;
if ( V_35 )
goto V_208;
}
F_123 ( & V_15 -> V_146 ) ;
return 0 ;
V_208:
F_209 (port, &team->port_list, list)
F_217 ( V_5 -> V_3 , V_213 , V_214 ) ;
F_123 ( & V_15 -> V_146 ) ;
return V_35 ;
}
static int F_218 ( struct V_2 * V_3 , T_10 V_213 , T_3 V_214 )
{
struct V_15 * V_15 = F_182 ( V_3 ) ;
struct V_1 * V_5 ;
F_122 ( & V_15 -> V_146 ) ;
F_17 (port, &team->port_list, list)
F_217 ( V_5 -> V_3 , V_213 , V_214 ) ;
F_123 ( & V_15 -> V_146 ) ;
return 0 ;
}
static void F_219 ( struct V_2 * V_3 )
{
}
static void F_220 ( struct V_15 * V_15 )
{
struct V_1 * V_5 ;
F_17 (port, &team->port_list, list)
F_131 ( V_5 ) ;
}
static void F_221 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_182 ( V_3 ) ;
F_122 ( & V_15 -> V_146 ) ;
F_220 ( V_15 ) ;
F_123 ( & V_15 -> V_146 ) ;
}
static int F_222 ( struct V_2 * V_3 ,
struct V_215 * V_216 )
{
struct V_15 * V_15 = F_182 ( V_3 ) ;
struct V_1 * V_5 ;
int V_35 = 0 ;
F_122 ( & V_15 -> V_146 ) ;
F_17 (port, &team->port_list, list) {
V_35 = F_129 ( V_15 , V_5 ) ;
if ( V_35 ) {
F_220 ( V_15 ) ;
break;
}
}
F_123 ( & V_15 -> V_146 ) ;
return V_35 ;
}
static int F_223 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_15 * V_15 = F_182 ( V_3 ) ;
int V_35 ;
F_122 ( & V_15 -> V_146 ) ;
V_35 = F_138 ( V_15 , V_6 ) ;
F_123 ( & V_15 -> V_146 ) ;
if ( ! V_35 )
F_124 ( V_3 ) ;
return V_35 ;
}
static int F_224 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_15 * V_15 = F_182 ( V_3 ) ;
int V_35 ;
F_122 ( & V_15 -> V_146 ) ;
V_35 = F_157 ( V_15 , V_6 ) ;
F_123 ( & V_15 -> V_146 ) ;
if ( ! V_35 )
F_124 ( V_3 ) ;
return V_35 ;
}
static T_5 F_225 ( struct V_2 * V_3 ,
T_5 V_161 )
{
struct V_1 * V_5 ;
struct V_15 * V_15 = F_182 ( V_3 ) ;
T_5 V_217 ;
V_217 = V_161 ;
V_161 &= ~ V_218 ;
V_161 |= V_134 ;
F_201 () ;
F_98 (port, &team->port_list, list) {
V_161 = F_120 ( V_161 ,
V_5 -> V_3 -> V_161 ,
V_217 ) ;
}
F_204 () ;
V_161 = F_226 ( V_161 , V_217 ) ;
return V_161 ;
}
static int F_227 ( struct V_2 * V_3 , bool V_219 )
{
struct V_15 * V_15 = F_182 ( V_3 ) ;
V_15 -> V_76 = true ;
if ( V_219 )
F_228 ( V_3 ) ;
else
F_187 ( V_3 ) ;
return 0 ;
}
static void F_229 ( struct V_2 * V_3 ,
struct V_220 * V_221 )
{
F_230 ( V_221 -> V_222 , V_223 , sizeof( V_221 -> V_222 ) ) ;
F_230 ( V_221 -> V_224 , V_225 , sizeof( V_221 -> V_224 ) ) ;
}
static void F_231 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
V_3 -> V_226 = V_6 -> V_226 ;
V_3 -> type = V_6 -> type ;
V_3 -> V_144 = V_6 -> V_144 ;
V_3 -> V_11 = V_6 -> V_11 ;
V_3 -> V_166 = V_6 -> V_166 ;
memcpy ( V_3 -> V_227 , V_6 -> V_227 , V_6 -> V_11 ) ;
F_232 ( V_3 , V_6 ) ;
}
static int F_140 ( struct V_2 * V_3 ,
struct V_2 * V_6 )
{
struct V_15 * V_15 = F_182 ( V_3 ) ;
char * V_158 = V_6 -> V_28 ;
int V_35 ;
if ( V_3 -> type == V_6 -> type )
return 0 ;
if ( ! F_66 ( & V_15 -> V_84 ) ) {
F_67 ( V_3 , L_27 , V_158 ) ;
return - V_85 ;
}
V_35 = F_74 ( V_228 , V_3 ) ;
V_35 = F_233 ( V_35 ) ;
if ( V_35 ) {
F_67 ( V_3 , L_28 ) ;
return V_35 ;
}
F_234 ( V_3 ) ;
F_235 ( V_3 ) ;
F_231 ( V_3 , V_6 ) ;
F_74 ( V_229 , V_3 ) ;
return 0 ;
}
static void F_236 ( struct V_2 * V_3 )
{
F_237 ( V_3 ) ;
V_3 -> V_230 = V_231 ;
V_3 -> V_232 = & V_233 ;
V_3 -> V_234 = & V_235 ;
V_3 -> V_236 = true ;
V_3 -> V_237 = F_191 ;
V_3 -> V_143 &= ~ ( V_140 | V_238 ) ;
V_3 -> V_143 |= V_239 ;
V_3 -> V_143 |= V_240 ;
V_3 -> V_143 |= V_241 | V_242 ;
V_3 -> V_161 |= V_243 ;
V_3 -> V_161 |= V_244 ;
V_3 -> V_161 |= V_245 ;
V_3 -> V_246 = V_133 |
V_247 |
V_248 |
V_249 ;
V_3 -> V_246 |= V_145 ;
V_3 -> V_161 |= V_3 -> V_246 ;
}
static int F_238 ( struct V_250 * V_251 , struct V_2 * V_3 ,
struct V_252 * V_253 [] , struct V_252 * V_177 [] ,
struct V_254 * V_255 )
{
if ( V_253 [ V_256 ] == NULL )
F_239 ( V_3 ) ;
return F_240 ( V_3 ) ;
}
static int F_241 ( struct V_252 * V_253 [] , struct V_252 * V_177 [] ,
struct V_254 * V_255 )
{
if ( V_253 [ V_256 ] ) {
if ( F_242 ( V_253 [ V_256 ] ) != V_257 )
return - V_67 ;
if ( ! F_207 ( F_243 ( V_253 [ V_256 ] ) ) )
return - V_204 ;
}
return 0 ;
}
static unsigned int F_244 ( void )
{
return V_258 ;
}
static unsigned int F_245 ( void )
{
return V_259 ;
}
static int F_246 ( struct V_72 * V_73 , struct V_260 * V_17 )
{
struct V_72 * V_261 ;
void * V_262 ;
int V_35 ;
V_261 = F_247 ( V_263 , V_36 ) ;
if ( ! V_261 )
return - V_37 ;
V_262 = F_248 ( V_261 , V_17 -> V_264 , V_17 -> V_265 ,
& V_266 , 0 , V_267 ) ;
if ( ! V_262 ) {
V_35 = - V_268 ;
goto V_269;
}
F_249 ( V_261 , V_262 ) ;
return F_250 ( F_251 ( V_17 ) , V_261 , V_17 -> V_264 ) ;
V_269:
F_252 ( V_261 ) ;
return V_35 ;
}
static struct V_15 * F_253 ( struct V_260 * V_17 )
{
struct V_250 * V_250 = F_251 ( V_17 ) ;
int V_270 ;
struct V_2 * V_3 ;
struct V_15 * V_15 ;
if ( ! V_17 -> V_271 [ V_272 ] )
return NULL ;
V_270 = F_254 ( V_17 -> V_271 [ V_272 ] ) ;
V_3 = F_255 ( V_250 , V_270 ) ;
if ( ! V_3 || V_3 -> V_232 != & V_233 ) {
if ( V_3 )
F_127 ( V_3 ) ;
return NULL ;
}
V_15 = F_182 ( V_3 ) ;
F_122 ( & V_15 -> V_146 ) ;
return V_15 ;
}
static void F_256 ( struct V_15 * V_15 )
{
F_123 ( & V_15 -> V_146 ) ;
F_127 ( V_15 -> V_3 ) ;
}
static int F_257 ( struct V_72 * V_73 , struct V_15 * V_15 , T_4 V_273 )
{
return F_250 ( F_258 ( V_15 -> V_3 ) , V_73 , V_273 ) ;
}
static int F_259 ( struct V_72 * V_73 , struct V_15 * V_15 ,
struct V_29 * V_30 )
{
struct V_252 * V_274 ;
struct V_25 * V_27 = V_30 -> V_27 ;
struct V_58 * V_59 = & V_30 -> V_17 ;
struct V_53 V_54 ;
int V_35 ;
V_54 . V_17 = V_59 ;
V_35 = F_39 ( V_15 , V_30 , & V_54 ) ;
if ( V_35 )
return V_35 ;
V_274 = F_260 ( V_73 , V_275 ) ;
if ( ! V_274 )
return - V_268 ;
if ( F_261 ( V_73 , V_276 , V_27 -> V_28 ) )
goto V_277;
if ( V_59 -> V_5 &&
F_262 ( V_73 , V_278 ,
V_59 -> V_5 -> V_3 -> V_270 ) )
goto V_277;
if ( V_30 -> V_27 -> V_33 &&
F_262 ( V_73 , V_279 ,
V_59 -> V_38 ) )
goto V_277;
switch ( V_27 -> type ) {
case V_280 :
if ( F_263 ( V_73 , V_281 , V_282 ) )
goto V_277;
if ( F_262 ( V_73 , V_283 , V_54 . V_177 . V_179 ) )
goto V_277;
break;
case V_284 :
if ( F_263 ( V_73 , V_281 , V_285 ) )
goto V_277;
if ( F_261 ( V_73 , V_283 ,
V_54 . V_177 . V_178 ) )
goto V_277;
break;
case V_286 :
if ( F_263 ( V_73 , V_281 , V_287 ) )
goto V_277;
if ( F_264 ( V_73 , V_283 , V_54 . V_177 . V_288 . V_107 ,
V_54 . V_177 . V_288 . V_289 ) )
goto V_277;
break;
case V_290 :
if ( F_263 ( V_73 , V_281 , V_291 ) )
goto V_277;
if ( V_54 . V_177 . V_180 &&
F_265 ( V_73 , V_283 ) )
goto V_277;
break;
case V_292 :
if ( F_263 ( V_73 , V_281 , V_293 ) )
goto V_277;
if ( F_266 ( V_73 , V_283 , V_54 . V_177 . V_181 ) )
goto V_277;
break;
default:
F_267 () ;
}
if ( V_30 -> V_40 && F_265 ( V_73 , V_294 ) )
goto V_277;
if ( V_30 -> V_39 ) {
if ( F_265 ( V_73 , V_295 ) )
goto V_277;
V_30 -> V_39 = false ;
}
F_268 ( V_73 , V_274 ) ;
return 0 ;
V_277:
F_269 ( V_73 , V_274 ) ;
return - V_268 ;
}
static int F_270 ( struct V_72 * * V_97 ,
struct V_15 * V_15 , T_4 V_273 ,
T_11 * V_296 )
{
int V_35 ;
if ( * V_97 ) {
V_35 = V_296 ( * V_97 , V_15 , V_273 ) ;
if ( V_35 )
return V_35 ;
}
* V_97 = F_271 ( V_297 , V_36 ) ;
if ( ! * V_97 )
return - V_37 ;
return 0 ;
}
static int F_272 ( struct V_15 * V_15 , T_4 V_273 , T_4 V_298 ,
int V_159 , T_11 * V_296 ,
struct V_113 * V_299 )
{
struct V_252 * V_51 ;
struct V_300 * V_301 ;
void * V_262 ;
struct V_29 * V_30 ;
int V_35 ;
struct V_72 * V_73 = NULL ;
bool V_302 ;
int V_34 ;
V_30 = F_273 ( V_299 ,
struct V_29 , V_303 ) ;
V_304:
V_35 = F_270 ( & V_73 , V_15 , V_273 , V_296 ) ;
if ( V_35 )
return V_35 ;
V_262 = F_248 ( V_73 , V_273 , V_298 , & V_266 , V_159 | V_305 ,
V_306 ) ;
if ( ! V_262 ) {
F_252 ( V_73 ) ;
return - V_268 ;
}
if ( F_262 ( V_73 , V_272 , V_15 -> V_3 -> V_270 ) )
goto V_307;
V_51 = F_260 ( V_73 , V_308 ) ;
if ( ! V_51 )
goto V_307;
V_34 = 0 ;
V_302 = false ;
F_274 (opt_inst, sel_opt_inst_list, tmp_list) {
V_35 = F_259 ( V_73 , V_15 , V_30 ) ;
if ( V_35 ) {
if ( V_35 == - V_268 ) {
if ( ! V_34 )
goto V_309;
V_302 = true ;
break;
}
goto V_309;
}
V_34 ++ ;
}
F_268 ( V_73 , V_51 ) ;
F_249 ( V_73 , V_262 ) ;
if ( V_302 )
goto V_304;
V_310:
V_301 = F_275 ( V_73 , V_273 , V_298 , V_311 , 0 , V_159 | V_305 ) ;
if ( ! V_301 ) {
V_35 = F_270 ( & V_73 , V_15 , V_273 , V_296 ) ;
if ( V_35 )
goto V_309;
goto V_310;
}
return V_296 ( V_73 , V_15 , V_273 ) ;
V_307:
V_35 = - V_268 ;
V_309:
F_276 ( V_73 , V_262 ) ;
F_252 ( V_73 ) ;
return V_35 ;
}
static int F_277 ( struct V_72 * V_73 , struct V_260 * V_17 )
{
struct V_15 * V_15 ;
struct V_29 * V_30 ;
int V_35 ;
F_278 ( V_299 ) ;
V_15 = F_253 ( V_17 ) ;
if ( ! V_15 )
return - V_67 ;
F_17 (opt_inst, &team->option_inst_list, list)
F_25 ( & V_30 -> V_303 , & V_299 ) ;
V_35 = F_272 ( V_15 , V_17 -> V_264 , V_17 -> V_265 ,
V_312 , F_257 ,
& V_299 ) ;
F_256 ( V_15 ) ;
return V_35 ;
}
static int F_279 ( struct V_72 * V_73 , struct V_260 * V_17 )
{
struct V_15 * V_15 ;
int V_35 = 0 ;
int V_34 ;
struct V_252 * V_313 ;
F_278 ( V_314 ) ;
F_280 () ;
V_15 = F_253 ( V_17 ) ;
if ( ! V_15 ) {
V_35 = - V_67 ;
goto F_73;
}
V_35 = - V_67 ;
if ( ! V_17 -> V_271 [ V_308 ] ) {
V_35 = - V_67 ;
goto V_315;
}
F_281 (nl_option, info->attrs[TEAM_ATTR_LIST_OPTION], i) {
struct V_252 * V_316 [ V_317 + 1 ] ;
struct V_252 * V_318 ;
struct V_252 * V_319 ;
enum V_320 V_321 ;
int V_322 = 0 ;
T_4 V_323 = 0 ;
bool V_324 = false ;
struct V_29 * V_30 ;
char * V_26 ;
bool V_325 = false ;
if ( F_282 ( V_313 ) != V_275 ) {
V_35 = - V_67 ;
goto V_315;
}
V_35 = F_283 ( V_316 , V_317 ,
V_313 , V_326 ,
V_17 -> V_255 ) ;
if ( V_35 )
goto V_315;
if ( ! V_316 [ V_276 ] ||
! V_316 [ V_281 ] ) {
V_35 = - V_67 ;
goto V_315;
}
switch ( F_284 ( V_316 [ V_281 ] ) ) {
case V_282 :
V_321 = V_280 ;
break;
case V_285 :
V_321 = V_284 ;
break;
case V_287 :
V_321 = V_286 ;
break;
case V_291 :
V_321 = V_290 ;
break;
case V_293 :
V_321 = V_292 ;
break;
default:
goto V_315;
}
V_319 = V_316 [ V_283 ] ;
if ( V_321 != V_290 && ! V_319 ) {
V_35 = - V_67 ;
goto V_315;
}
V_26 = F_243 ( V_316 [ V_276 ] ) ;
V_318 = V_316 [ V_278 ] ;
if ( V_318 )
V_322 = F_254 ( V_318 ) ;
V_318 = V_316 [ V_279 ] ;
if ( V_318 ) {
V_324 = true ;
V_323 = F_254 ( V_318 ) ;
}
F_17 (opt_inst, &team->option_inst_list, list) {
struct V_25 * V_27 = V_30 -> V_27 ;
struct V_53 V_54 ;
struct V_58 * V_59 ;
int V_327 ;
V_59 = & V_30 -> V_17 ;
V_327 = V_59 -> V_5 ?
V_59 -> V_5 -> V_3 -> V_270 : 0 ;
if ( V_27 -> type != V_321 ||
strcmp ( V_27 -> V_28 , V_26 ) ||
V_327 != V_322 ||
( V_27 -> V_33 && ! V_324 ) ||
V_59 -> V_38 != V_323 )
continue;
V_325 = true ;
V_54 . V_17 = V_59 ;
switch ( V_321 ) {
case V_280 :
V_54 . V_177 . V_179 = F_254 ( V_319 ) ;
break;
case V_284 :
if ( F_242 ( V_319 ) > V_328 ) {
V_35 = - V_67 ;
goto V_315;
}
V_54 . V_177 . V_178 = F_243 ( V_319 ) ;
break;
case V_286 :
V_54 . V_177 . V_288 . V_107 = F_242 ( V_319 ) ;
V_54 . V_177 . V_288 . V_289 = F_243 ( V_319 ) ;
break;
case V_290 :
V_54 . V_177 . V_180 = V_319 ? true : false ;
break;
case V_292 :
V_54 . V_177 . V_181 = F_285 ( V_319 ) ;
break;
default:
F_267 () ;
}
V_35 = F_40 ( V_15 , V_30 , & V_54 ) ;
if ( V_35 )
goto V_315;
V_30 -> V_39 = true ;
F_286 ( & V_30 -> V_303 , & V_314 ) ;
}
if ( ! V_325 ) {
V_35 = - V_175 ;
goto V_315;
}
}
V_35 = F_287 ( V_15 , & V_314 ) ;
V_315:
F_256 ( V_15 ) ;
F_73:
F_73 () ;
return V_35 ;
}
static int F_288 ( struct V_72 * V_73 ,
struct V_1 * V_5 )
{
struct V_252 * V_329 ;
V_329 = F_260 ( V_73 , V_330 ) ;
if ( ! V_329 )
goto V_277;
if ( F_262 ( V_73 , V_331 , V_5 -> V_3 -> V_270 ) )
goto V_277;
if ( V_5 -> V_39 ) {
if ( F_265 ( V_73 , V_332 ) )
goto V_277;
V_5 -> V_39 = false ;
}
if ( ( V_5 -> V_40 &&
F_265 ( V_73 , V_333 ) ) ||
( V_5 -> V_24 . V_19 &&
F_265 ( V_73 , V_334 ) ) ||
F_262 ( V_73 , V_335 , V_5 -> V_24 . V_336 ) ||
F_263 ( V_73 , V_337 , V_5 -> V_24 . V_338 ) )
goto V_277;
F_268 ( V_73 , V_329 ) ;
return 0 ;
V_277:
F_269 ( V_73 , V_329 ) ;
return - V_268 ;
}
static int F_289 ( struct V_15 * V_15 , T_4 V_273 , T_4 V_298 ,
int V_159 , T_11 * V_296 ,
struct V_1 * V_339 )
{
struct V_252 * V_84 ;
struct V_300 * V_301 ;
void * V_262 ;
struct V_1 * V_5 ;
int V_35 ;
struct V_72 * V_73 = NULL ;
bool V_302 ;
int V_34 ;
V_5 = F_290 ( & V_15 -> V_84 ,
struct V_1 , V_31 ) ;
V_304:
V_35 = F_270 ( & V_73 , V_15 , V_273 , V_296 ) ;
if ( V_35 )
return V_35 ;
V_262 = F_248 ( V_73 , V_273 , V_298 , & V_266 , V_159 | V_305 ,
V_340 ) ;
if ( ! V_262 ) {
F_252 ( V_73 ) ;
return - V_268 ;
}
if ( F_262 ( V_73 , V_272 , V_15 -> V_3 -> V_270 ) )
goto V_307;
V_84 = F_260 ( V_73 , V_341 ) ;
if ( ! V_84 )
goto V_307;
V_34 = 0 ;
V_302 = false ;
if ( V_339 ) {
V_35 = F_288 ( V_73 , V_339 ) ;
if ( V_35 )
goto V_309;
} else if ( V_5 ) {
F_274 (port, &team->port_list, list) {
V_35 = F_288 ( V_73 , V_5 ) ;
if ( V_35 ) {
if ( V_35 == - V_268 ) {
if ( ! V_34 )
goto V_309;
V_302 = true ;
break;
}
goto V_309;
}
V_34 ++ ;
}
}
F_268 ( V_73 , V_84 ) ;
F_249 ( V_73 , V_262 ) ;
if ( V_302 )
goto V_304;
V_310:
V_301 = F_275 ( V_73 , V_273 , V_298 , V_311 , 0 , V_159 | V_305 ) ;
if ( ! V_301 ) {
V_35 = F_270 ( & V_73 , V_15 , V_273 , V_296 ) ;
if ( V_35 )
goto V_309;
goto V_310;
}
return V_296 ( V_73 , V_15 , V_273 ) ;
V_307:
V_35 = - V_268 ;
V_309:
F_276 ( V_73 , V_262 ) ;
F_252 ( V_73 ) ;
return V_35 ;
}
static int F_291 ( struct V_72 * V_73 ,
struct V_260 * V_17 )
{
struct V_15 * V_15 ;
int V_35 ;
V_15 = F_253 ( V_17 ) ;
if ( ! V_15 )
return - V_67 ;
V_35 = F_289 ( V_15 , V_17 -> V_264 , V_17 -> V_265 ,
V_312 , F_257 , NULL ) ;
F_256 ( V_15 ) ;
return V_35 ;
}
static int F_292 ( struct V_72 * V_73 ,
struct V_15 * V_15 , T_4 V_273 )
{
return F_293 ( & V_266 , F_258 ( V_15 -> V_3 ) ,
V_73 , 0 , 0 , V_36 ) ;
}
static int F_287 ( struct V_15 * V_15 ,
struct V_113 * V_299 )
{
return F_272 ( V_15 , 0 , 0 , 0 , F_292 ,
V_299 ) ;
}
static int F_294 ( struct V_15 * V_15 ,
struct V_1 * V_5 )
{
return F_289 ( V_15 , 0 , 0 , 0 , F_292 ,
V_5 ) ;
}
static int T_12 F_295 ( void )
{
return F_296 ( & V_266 ) ;
}
static void F_297 ( void )
{
F_298 ( & V_266 ) ;
}
static void F_37 ( struct V_15 * V_15 )
{
int V_35 ;
struct V_29 * V_30 ;
F_278 ( V_299 ) ;
F_17 (opt_inst, &team->option_inst_list, list) {
if ( V_30 -> V_39 )
F_25 ( & V_30 -> V_303 , & V_299 ) ;
}
V_35 = F_287 ( V_15 , & V_299 ) ;
if ( V_35 && V_35 != - V_342 )
F_299 ( V_15 -> V_3 , L_29 ,
V_35 ) ;
}
static void F_300 ( struct V_1 * V_5 , bool V_19 )
{
int V_35 ;
V_5 -> V_39 = true ;
V_5 -> V_24 . V_19 = V_19 ;
F_15 ( V_5 ) ;
if ( V_19 ) {
struct V_343 V_344 ;
V_35 = F_301 ( V_5 -> V_3 , & V_344 ) ;
if ( ! V_35 ) {
V_5 -> V_24 . V_336 = V_344 . V_345 . V_336 ;
V_5 -> V_24 . V_338 = V_344 . V_345 . V_338 ;
goto V_346;
}
}
V_5 -> V_24 . V_336 = 0 ;
V_5 -> V_24 . V_338 = 0 ;
V_346:
V_35 = F_294 ( V_5 -> V_15 , V_5 ) ;
if ( V_35 && V_35 != - V_342 )
F_299 ( V_5 -> V_15 -> V_3 , L_30 ,
V_5 -> V_3 -> V_28 , V_35 ) ;
}
static void F_174 ( struct V_15 * V_15 )
{
struct V_1 * V_5 ;
bool V_347 ;
if ( V_15 -> V_76 )
return;
V_347 = false ;
F_17 (port, &team->port_list, list) {
if ( V_5 -> V_19 ) {
V_347 = true ;
break;
}
}
if ( V_347 )
F_228 ( V_15 -> V_3 ) ;
else
F_187 ( V_15 -> V_3 ) ;
}
static void F_302 ( struct V_1 * V_5 , bool V_19 )
{
if ( V_5 -> V_24 . V_19 != V_19 )
F_300 ( V_5 , V_19 ) ;
F_174 ( V_5 -> V_15 ) ;
}
static void F_150 ( struct V_1 * V_5 , bool V_19 )
{
F_300 ( V_5 , V_19 ) ;
F_174 ( V_5 -> V_15 ) ;
}
static void F_158 ( struct V_1 * V_5 )
{
V_5 -> V_40 = true ;
F_300 ( V_5 , false ) ;
F_174 ( V_5 -> V_15 ) ;
}
static void F_303 ( struct V_1 * V_5 , bool V_19 )
{
struct V_15 * V_15 = V_5 -> V_15 ;
F_122 ( & V_15 -> V_146 ) ;
F_302 ( V_5 , V_19 ) ;
F_123 ( & V_15 -> V_146 ) ;
}
static int F_304 ( struct V_348 * V_349 ,
unsigned long V_350 , void * V_289 )
{
struct V_2 * V_3 = F_305 ( V_289 ) ;
struct V_1 * V_5 ;
V_5 = F_3 ( V_3 ) ;
if ( ! V_5 )
return V_351 ;
switch ( V_350 ) {
case V_352 :
if ( F_151 ( V_3 ) )
F_303 ( V_5 , true ) ;
break;
case V_353 :
F_303 ( V_5 , false ) ;
break;
case V_354 :
if ( F_77 ( V_5 -> V_3 ) )
F_303 ( V_5 ,
! ! F_151 ( V_5 -> V_3 ) ) ;
break;
case V_355 :
F_224 ( V_5 -> V_15 -> V_3 , V_3 ) ;
break;
case V_356 :
F_121 ( V_5 -> V_15 ) ;
break;
case V_357 :
if ( ! V_5 -> V_15 -> V_207 )
return V_358 ;
break;
case V_228 :
return V_358 ;
case V_96 :
F_74 ( V_350 , V_5 -> V_15 -> V_3 ) ;
break;
}
return V_351 ;
}
static int T_12 F_306 ( void )
{
int V_35 ;
F_307 ( & V_359 ) ;
V_35 = F_308 ( & V_360 ) ;
if ( V_35 )
goto V_361;
V_35 = F_295 () ;
if ( V_35 )
goto V_362;
return 0 ;
V_362:
F_309 ( & V_360 ) ;
V_361:
F_310 ( & V_359 ) ;
return V_35 ;
}
static void T_13 F_311 ( void )
{
F_297 () ;
F_309 ( & V_360 ) ;
F_310 ( & V_359 ) ;
}
