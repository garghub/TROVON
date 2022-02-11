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
memcpy ( V_9 . V_10 , V_7 , V_11 ) ;
V_9 . V_12 = V_13 ;
return F_7 ( V_6 , & V_9 ) ;
}
static int F_8 ( struct V_1 * V_4 )
{
return F_6 ( V_4 -> V_3 , V_4 -> V_14 . V_7 ) ;
}
int F_9 ( struct V_1 * V_4 )
{
return F_6 ( V_4 -> V_3 , V_4 -> V_15 -> V_3 -> V_7 ) ;
}
static void F_10 ( struct V_1 * V_4 )
{
V_4 -> V_16 = V_4 -> V_17 . V_18 ? V_4 -> V_17 . V_16 :
V_4 -> V_19 . V_16 ;
}
static struct V_20 * F_11 ( struct V_15 * V_15 ,
const char * V_21 )
{
struct V_20 * V_22 ;
F_12 (option, &team->option_list, list) {
if ( strcmp ( V_22 -> V_23 , V_21 ) == 0 )
return V_22 ;
}
return NULL ;
}
static void F_13 ( struct V_24 * V_25 )
{
F_14 ( & V_25 -> V_26 ) ;
F_15 ( V_25 ) ;
}
static void F_16 ( struct V_15 * V_15 ,
struct V_20 * V_22 )
{
struct V_24 * V_25 , * V_27 ;
F_17 (opt_inst, tmp, &team->option_inst_list, list) {
if ( V_25 -> V_22 == V_22 )
F_13 ( V_25 ) ;
}
}
static int F_18 ( struct V_15 * V_15 , struct V_20 * V_22 ,
struct V_1 * V_4 )
{
struct V_24 * V_25 ;
unsigned int V_28 ;
unsigned int V_29 ;
int V_30 ;
V_28 = V_22 -> V_28 ;
if ( ! V_28 )
V_28 = 1 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ ) {
V_25 = F_19 ( sizeof( * V_25 ) , V_31 ) ;
if ( ! V_25 )
return - V_32 ;
V_25 -> V_22 = V_22 ;
V_25 -> V_33 . V_4 = V_4 ;
V_25 -> V_33 . V_34 = V_29 ;
V_25 -> V_35 = true ;
V_25 -> V_36 = false ;
F_20 ( & V_25 -> V_26 , & V_15 -> V_37 ) ;
if ( V_22 -> V_38 ) {
V_30 = V_22 -> V_38 ( V_15 , & V_25 -> V_33 ) ;
if ( V_30 )
return V_30 ;
}
}
return 0 ;
}
static int F_21 ( struct V_15 * V_15 ,
struct V_20 * V_22 )
{
struct V_1 * V_4 ;
int V_30 ;
if ( ! V_22 -> V_39 ) {
V_30 = F_18 ( V_15 , V_22 , NULL ) ;
if ( V_30 )
goto V_40;
}
F_12 (port, &team->port_list, list) {
V_30 = F_18 ( V_15 , V_22 , V_4 ) ;
if ( V_30 )
goto V_40;
}
return 0 ;
V_40:
F_16 ( V_15 , V_22 ) ;
return V_30 ;
}
static void F_22 ( struct V_15 * V_15 ,
struct V_20 * V_22 )
{
struct V_24 * V_25 ;
F_12 (opt_inst, &team->option_inst_list, list) {
if ( V_25 -> V_22 == V_22 ) {
V_25 -> V_35 = true ;
V_25 -> V_36 = true ;
}
}
}
static void F_23 ( struct V_15 * V_15 ,
struct V_1 * V_4 )
{
struct V_24 * V_25 , * V_27 ;
F_17 (opt_inst, tmp, &team->option_inst_list, list) {
if ( V_25 -> V_22 -> V_39 &&
V_25 -> V_33 . V_4 == V_4 )
F_13 ( V_25 ) ;
}
}
static int F_24 ( struct V_15 * V_15 ,
struct V_1 * V_4 )
{
struct V_20 * V_22 ;
int V_30 ;
F_12 (option, &team->option_list, list) {
if ( ! V_22 -> V_39 )
continue;
V_30 = F_18 ( V_15 , V_22 , V_4 ) ;
if ( V_30 )
goto V_41;
}
return 0 ;
V_41:
F_23 ( V_15 , V_4 ) ;
return V_30 ;
}
static void F_25 ( struct V_15 * V_15 ,
struct V_1 * V_4 )
{
struct V_24 * V_25 ;
F_12 (opt_inst, &team->option_inst_list, list) {
if ( V_25 -> V_33 . V_4 == V_4 ) {
V_25 -> V_35 = true ;
V_25 -> V_36 = true ;
}
}
}
static int F_26 ( struct V_15 * V_15 ,
const struct V_20 * V_22 ,
T_1 V_42 )
{
int V_29 ;
struct V_20 * * V_43 ;
int V_30 ;
V_43 = F_27 ( sizeof( struct V_20 * ) * V_42 ,
V_31 ) ;
if ( ! V_43 )
return - V_32 ;
for ( V_29 = 0 ; V_29 < V_42 ; V_29 ++ , V_22 ++ ) {
if ( F_11 ( V_15 , V_22 -> V_23 ) ) {
V_30 = - V_44 ;
goto V_45;
}
V_43 [ V_29 ] = F_28 ( V_22 , sizeof( * V_22 ) , V_31 ) ;
if ( ! V_43 [ V_29 ] ) {
V_30 = - V_32 ;
goto V_45;
}
}
for ( V_29 = 0 ; V_29 < V_42 ; V_29 ++ ) {
V_30 = F_21 ( V_15 , V_43 [ V_29 ] ) ;
if ( V_30 )
goto V_46;
F_20 ( & V_43 [ V_29 ] -> V_26 , & V_15 -> V_47 ) ;
}
F_15 ( V_43 ) ;
return 0 ;
V_46:
for ( V_29 -- ; V_29 >= 0 ; V_29 -- )
F_16 ( V_15 , V_43 [ V_29 ] ) ;
V_29 = V_42 - 1 ;
V_45:
for ( V_29 -- ; V_29 >= 0 ; V_29 -- )
F_15 ( V_43 [ V_29 ] ) ;
F_15 ( V_43 ) ;
return V_30 ;
}
static void F_29 ( struct V_15 * V_15 ,
const struct V_20 * V_22 ,
T_1 V_42 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_42 ; V_29 ++ , V_22 ++ ) {
struct V_20 * V_48 ;
V_48 = F_11 ( V_15 , V_22 -> V_23 ) ;
if ( V_48 )
F_22 ( V_15 , V_48 ) ;
}
}
static void F_30 ( struct V_15 * V_15 ,
const struct V_20 * V_22 ,
T_1 V_42 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_42 ; V_29 ++ , V_22 ++ ) {
struct V_20 * V_48 ;
V_48 = F_11 ( V_15 , V_22 -> V_23 ) ;
if ( V_48 ) {
F_16 ( V_15 , V_48 ) ;
F_14 ( & V_48 -> V_26 ) ;
F_15 ( V_48 ) ;
}
}
}
int F_31 ( struct V_15 * V_15 ,
const struct V_20 * V_22 ,
T_1 V_42 )
{
int V_30 ;
V_30 = F_26 ( V_15 , V_22 , V_42 ) ;
if ( V_30 )
return V_30 ;
F_32 ( V_15 ) ;
return 0 ;
}
void F_33 ( struct V_15 * V_15 ,
const struct V_20 * V_22 ,
T_1 V_42 )
{
F_29 ( V_15 , V_22 , V_42 ) ;
F_32 ( V_15 ) ;
F_30 ( V_15 , V_22 , V_42 ) ;
}
static int F_34 ( struct V_15 * V_15 ,
struct V_24 * V_25 ,
struct V_49 * V_50 )
{
if ( ! V_25 -> V_22 -> V_51 )
return - V_52 ;
return V_25 -> V_22 -> V_51 ( V_15 , V_50 ) ;
}
static int F_35 ( struct V_15 * V_15 ,
struct V_24 * V_25 ,
struct V_49 * V_50 )
{
if ( ! V_25 -> V_22 -> V_53 )
return - V_52 ;
return V_25 -> V_22 -> V_53 ( V_15 , V_50 ) ;
}
void F_36 ( struct V_54 * V_55 )
{
struct V_24 * V_25 ;
V_25 = F_37 ( V_55 , struct V_24 , V_33 ) ;
V_25 -> V_35 = true ;
}
void F_38 ( struct V_15 * V_15 )
{
F_32 ( V_15 ) ;
}
static struct V_56 * F_39 ( const char * V_57 )
{
struct V_56 * V_58 ;
F_12 (mitem, &mode_list, list) {
if ( strcmp ( V_58 -> V_59 -> V_57 , V_57 ) == 0 )
return V_58 ;
}
return NULL ;
}
static bool F_40 ( const char * V_23 )
{
while ( * V_23 != '\0' ) {
if ( ! isalpha ( * V_23 ) && ! isdigit ( * V_23 ) && * V_23 != '_' )
return false ;
V_23 ++ ;
}
return true ;
}
int F_41 ( const struct V_60 * V_59 )
{
int V_30 = 0 ;
struct V_56 * V_58 ;
if ( ! F_40 ( V_59 -> V_57 ) ||
V_59 -> V_61 > V_62 )
return - V_63 ;
V_58 = F_19 ( sizeof( * V_58 ) , V_31 ) ;
if ( ! V_58 )
return - V_32 ;
F_42 ( & V_64 ) ;
if ( F_39 ( V_59 -> V_57 ) ) {
V_30 = - V_44 ;
F_15 ( V_58 ) ;
goto V_65;
}
V_58 -> V_59 = V_59 ;
F_20 ( & V_58 -> V_26 , & V_66 ) ;
V_65:
F_43 ( & V_64 ) ;
return V_30 ;
}
void F_44 ( const struct V_60 * V_59 )
{
struct V_56 * V_58 ;
F_42 ( & V_64 ) ;
V_58 = F_39 ( V_59 -> V_57 ) ;
if ( V_58 ) {
F_45 ( & V_58 -> V_26 ) ;
F_15 ( V_58 ) ;
}
F_43 ( & V_64 ) ;
}
static const struct V_60 * F_46 ( const char * V_57 )
{
struct V_56 * V_58 ;
const struct V_60 * V_59 = NULL ;
F_42 ( & V_64 ) ;
V_58 = F_39 ( V_57 ) ;
if ( ! V_58 ) {
F_43 ( & V_64 ) ;
F_47 ( L_1 , V_57 ) ;
F_42 ( & V_64 ) ;
V_58 = F_39 ( V_57 ) ;
}
if ( V_58 ) {
V_59 = V_58 -> V_59 ;
if ( ! F_48 ( V_59 -> V_67 ) )
V_59 = NULL ;
}
F_43 ( & V_64 ) ;
return V_59 ;
}
static void F_49 ( const struct V_60 * V_59 )
{
F_50 ( V_59 -> V_67 ) ;
}
static bool F_51 ( struct V_15 * V_15 , struct V_68 * V_69 )
{
F_52 ( V_69 ) ;
return false ;
}
T_2 F_53 ( struct V_15 * V_15 ,
struct V_1 * V_4 ,
struct V_68 * V_69 )
{
return V_70 ;
}
static bool F_54 ( struct V_15 * V_15 )
{
return V_15 -> V_59 != & V_71 ;
}
static void F_55 ( struct V_15 * V_15 )
{
V_15 -> V_59 = & V_71 ;
}
static void F_56 ( struct V_15 * V_15 , int V_72 )
{
if ( ! V_72 || ! F_54 ( V_15 ) ||
! V_15 -> V_59 -> V_73 -> V_74 )
V_15 -> V_73 . V_74 = F_51 ;
else
V_15 -> V_73 . V_74 = V_15 -> V_59 -> V_73 -> V_74 ;
if ( ! V_72 || ! F_54 ( V_15 ) ||
! V_15 -> V_59 -> V_73 -> V_75 )
V_15 -> V_73 . V_75 = F_53 ;
else
V_15 -> V_73 . V_75 = V_15 -> V_59 -> V_73 -> V_75 ;
}
static void F_57 ( struct V_15 * V_15 )
{
F_56 ( V_15 , V_15 -> V_72 ) ;
}
static int F_58 ( struct V_15 * V_15 ,
const struct V_60 * V_76 )
{
if ( F_54 ( V_15 ) ) {
void (* F_59)( struct V_15 * V_15 ) = V_15 -> V_73 . exit ;
memset ( & V_15 -> V_73 , 0 , sizeof( struct V_77 ) ) ;
F_57 ( V_15 ) ;
if ( F_59 )
F_59 ( V_15 ) ;
F_49 ( V_15 -> V_59 ) ;
F_55 ( V_15 ) ;
memset ( & V_15 -> V_78 , 0 ,
sizeof( struct V_15 ) - F_60 ( struct V_15 , V_78 ) ) ;
}
if ( ! V_76 )
return 0 ;
if ( V_76 -> V_73 -> V_38 ) {
int V_30 ;
V_30 = V_76 -> V_73 -> V_38 ( V_15 ) ;
if ( V_30 )
return V_30 ;
}
V_15 -> V_59 = V_76 ;
memcpy ( & V_15 -> V_73 , V_76 -> V_73 , sizeof( struct V_77 ) ) ;
F_57 ( V_15 ) ;
return 0 ;
}
static int F_61 ( struct V_15 * V_15 , const char * V_57 )
{
const struct V_60 * V_76 ;
struct V_2 * V_3 = V_15 -> V_3 ;
int V_30 ;
if ( ! F_62 ( & V_15 -> V_79 ) ) {
F_63 ( V_3 , L_2 ) ;
return - V_80 ;
}
if ( F_54 ( V_15 ) && strcmp ( V_15 -> V_59 -> V_57 , V_57 ) == 0 ) {
F_63 ( V_3 , L_3 ) ;
return - V_63 ;
}
V_76 = F_46 ( V_57 ) ;
if ( ! V_76 ) {
F_63 ( V_3 , L_4 , V_57 ) ;
return - V_63 ;
}
V_30 = F_58 ( V_15 , V_76 ) ;
if ( V_30 ) {
F_63 ( V_3 , L_5 , V_57 ) ;
F_49 ( V_76 ) ;
return V_30 ;
}
F_64 ( V_3 , L_6 , V_57 ) ;
return 0 ;
}
static T_2 F_65 ( struct V_68 * * V_81 )
{
struct V_68 * V_69 = * V_81 ;
struct V_1 * V_4 ;
struct V_15 * V_15 ;
T_2 V_82 ;
V_69 = F_66 ( V_69 , V_83 ) ;
if ( ! V_69 )
return V_84 ;
* V_81 = V_69 ;
V_4 = F_1 ( V_69 -> V_3 ) ;
V_15 = V_4 -> V_15 ;
if ( ! F_67 ( V_4 ) ) {
V_82 = V_85 ;
} else {
V_82 = V_15 -> V_73 . V_75 ( V_15 , V_4 , V_69 ) ;
}
if ( V_82 == V_70 ) {
struct V_86 * V_87 ;
V_87 = F_68 ( V_15 -> V_87 ) ;
F_69 ( & V_87 -> V_88 ) ;
V_87 -> V_89 ++ ;
V_87 -> V_90 += V_69 -> V_91 ;
if ( V_69 -> V_92 == V_93 )
V_87 -> V_94 ++ ;
F_70 ( & V_87 -> V_88 ) ;
V_69 -> V_3 = V_15 -> V_3 ;
} else {
F_71 ( V_15 -> V_87 -> V_95 ) ;
}
return V_82 ;
}
static bool F_72 ( const struct V_15 * V_15 ,
const struct V_1 * V_4 )
{
struct V_1 * V_96 ;
F_12 (cur, &team->port_list, list)
if ( V_96 == V_4 )
return true ;
return false ;
}
static void F_73 ( struct V_15 * V_15 ,
struct V_1 * V_4 )
{
if ( F_67 ( V_4 ) )
return;
V_4 -> V_97 = V_15 -> V_72 ++ ;
F_74 ( & V_4 -> V_98 ,
F_75 ( V_15 , V_4 -> V_97 ) ) ;
F_57 ( V_15 ) ;
if ( V_15 -> V_73 . V_99 )
V_15 -> V_73 . V_99 ( V_15 , V_4 ) ;
}
static void F_76 ( struct V_15 * V_15 , int V_100 )
{
int V_29 ;
struct V_1 * V_4 ;
for ( V_29 = V_100 + 1 ; V_29 < V_15 -> V_72 ; V_29 ++ ) {
V_4 = F_77 ( V_15 , V_29 ) ;
F_78 ( & V_4 -> V_98 ) ;
V_4 -> V_97 -- ;
F_74 ( & V_4 -> V_98 ,
F_75 ( V_15 , V_4 -> V_97 ) ) ;
}
}
static void F_79 ( struct V_15 * V_15 ,
struct V_1 * V_4 )
{
if ( ! F_67 ( V_4 ) )
return;
if ( V_15 -> V_73 . V_101 )
V_15 -> V_73 . V_101 ( V_15 , V_4 ) ;
F_78 ( & V_4 -> V_98 ) ;
F_76 ( V_15 , V_4 -> V_97 ) ;
V_4 -> V_97 = - 1 ;
F_56 ( V_15 , V_15 -> V_72 - 1 ) ;
F_80 () ;
V_15 -> V_72 -- ;
}
static void F_81 ( struct V_15 * V_15 )
{
struct V_1 * V_4 ;
T_3 V_102 = V_103 ;
unsigned short V_104 = V_105 ;
unsigned int V_106 , V_107 = V_108 ;
F_12 (port, &team->port_list, list) {
V_102 = F_82 ( V_102 ,
V_4 -> V_3 -> V_102 ,
V_103 ) ;
V_107 &= V_4 -> V_3 -> V_109 ;
if ( V_4 -> V_3 -> V_110 > V_104 )
V_104 = V_4 -> V_3 -> V_110 ;
}
V_15 -> V_3 -> V_102 = V_102 ;
V_15 -> V_3 -> V_110 = V_104 ;
V_106 = V_15 -> V_3 -> V_109 & ~ V_108 ;
V_15 -> V_3 -> V_109 = V_106 | V_107 ;
F_83 ( V_15 -> V_3 ) ;
}
static void F_84 ( struct V_15 * V_15 )
{
F_85 ( & V_15 -> V_111 ) ;
F_81 ( V_15 ) ;
F_86 ( & V_15 -> V_111 ) ;
}
static int F_87 ( struct V_15 * V_15 , struct V_1 * V_4 )
{
int V_30 = 0 ;
F_88 ( V_15 -> V_3 ) ;
V_4 -> V_3 -> V_109 |= V_112 ;
if ( V_15 -> V_73 . V_113 ) {
V_30 = V_15 -> V_73 . V_113 ( V_15 , V_4 ) ;
if ( V_30 ) {
F_63 ( V_15 -> V_3 , L_7 ,
V_4 -> V_3 -> V_23 ) ;
goto V_114;
}
}
return 0 ;
V_114:
V_4 -> V_3 -> V_109 &= ~ V_112 ;
F_89 ( V_15 -> V_3 ) ;
return V_30 ;
}
static void F_90 ( struct V_15 * V_15 , struct V_1 * V_4 )
{
if ( V_15 -> V_73 . V_115 )
V_15 -> V_73 . V_115 ( V_15 , V_4 ) ;
V_4 -> V_3 -> V_109 &= ~ V_112 ;
F_89 ( V_15 -> V_3 ) ;
}
static int F_91 ( struct V_15 * V_15 , struct V_1 * V_4 ,
T_4 V_116 )
{
struct V_117 * V_118 ;
int V_30 ;
V_118 = F_27 ( sizeof( * V_118 ) , V_116 ) ;
if ( ! V_118 )
return - V_32 ;
V_30 = F_92 ( V_118 , V_4 -> V_3 , V_116 ) ;
if ( V_30 ) {
F_15 ( V_118 ) ;
return V_30 ;
}
V_4 -> V_118 = V_118 ;
return V_30 ;
}
static void F_93 ( struct V_1 * V_4 )
{
struct V_117 * V_118 = V_4 -> V_118 ;
if ( ! V_118 )
return;
V_4 -> V_118 = NULL ;
F_94 () ;
F_95 ( V_118 ) ;
F_15 ( V_118 ) ;
}
static struct V_119 * F_96 ( struct V_15 * V_15 )
{
return V_15 -> V_3 -> V_120 ;
}
static int F_91 ( struct V_15 * V_15 , struct V_1 * V_4 ,
T_4 V_116 )
{
return 0 ;
}
static void F_93 ( struct V_1 * V_4 )
{
}
static struct V_119 * F_96 ( struct V_15 * V_15 )
{
return NULL ;
}
static int F_97 ( struct V_15 * V_15 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_1 * V_4 ;
char * V_121 = V_6 -> V_23 ;
int V_30 ;
if ( V_6 -> V_106 & V_122 ||
V_6 -> type != V_13 ) {
F_63 ( V_3 , L_8 ,
V_121 ) ;
return - V_63 ;
}
if ( F_3 ( V_6 ) ) {
F_63 ( V_3 , L_9
L_10 , V_121 ) ;
return - V_80 ;
}
if ( V_6 -> V_106 & V_123 ) {
F_63 ( V_3 , L_11 ,
V_121 ) ;
return - V_80 ;
}
V_4 = F_27 ( sizeof( struct V_1 ) + V_15 -> V_59 -> V_124 ,
V_31 ) ;
if ( ! V_4 )
return - V_32 ;
V_4 -> V_3 = V_6 ;
V_4 -> V_15 = V_15 ;
V_4 -> V_14 . V_125 = V_6 -> V_125 ;
V_30 = F_98 ( V_6 , V_3 -> V_125 ) ;
if ( V_30 ) {
F_99 ( V_3 , L_12 , V_30 ) ;
goto V_126;
}
memcpy ( V_4 -> V_14 . V_7 , V_6 -> V_7 , V_11 ) ;
V_30 = F_87 ( V_15 , V_4 ) ;
if ( V_30 ) {
F_63 ( V_3 , L_7 ,
V_121 ) ;
goto V_114;
}
V_30 = F_100 ( V_6 ) ;
if ( V_30 ) {
F_99 ( V_3 , L_13 ,
V_121 ) ;
goto V_127;
}
V_30 = F_101 ( V_6 , V_3 ) ;
if ( V_30 ) {
F_63 ( V_3 , L_14 ,
V_121 ) ;
goto V_128;
}
if ( F_96 ( V_15 ) ) {
V_30 = F_91 ( V_15 , V_4 , V_31 ) ;
if ( V_30 ) {
F_63 ( V_3 , L_15 ,
V_121 ) ;
goto V_129;
}
}
V_30 = F_102 ( V_6 , V_3 ) ;
if ( V_30 ) {
F_63 ( V_3 , L_16 , V_121 ) ;
goto V_130;
}
V_30 = F_103 ( V_6 , F_65 ,
V_4 ) ;
if ( V_30 ) {
F_63 ( V_3 , L_17 ,
V_121 ) ;
goto V_131;
}
V_30 = F_24 ( V_15 , V_4 ) ;
if ( V_30 ) {
F_63 ( V_3 , L_18 ,
V_121 ) ;
goto V_132;
}
V_4 -> V_97 = - 1 ;
F_73 ( V_15 , V_4 ) ;
F_104 ( & V_4 -> V_26 , & V_15 -> V_79 ) ;
F_81 ( V_15 ) ;
F_105 ( V_4 , ! ! F_106 ( V_6 ) ) ;
F_32 ( V_15 ) ;
F_64 ( V_3 , L_19 , V_121 ) ;
return 0 ;
V_132:
F_107 ( V_6 ) ;
V_131:
F_102 ( V_6 , NULL ) ;
V_130:
F_93 ( V_4 ) ;
V_129:
F_108 ( V_6 , V_3 ) ;
V_128:
F_109 ( V_6 ) ;
V_127:
F_90 ( V_15 , V_4 ) ;
F_8 ( V_4 ) ;
V_114:
F_98 ( V_6 , V_4 -> V_14 . V_125 ) ;
V_126:
F_15 ( V_4 ) ;
return V_30 ;
}
static int F_110 ( struct V_15 * V_15 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_1 * V_4 ;
char * V_121 = V_6 -> V_23 ;
V_4 = F_4 ( V_6 ) ;
if ( ! V_4 || ! F_72 ( V_15 , V_4 ) ) {
F_63 ( V_3 , L_20 ,
V_121 ) ;
return - V_133 ;
}
F_25 ( V_15 , V_4 ) ;
F_32 ( V_15 ) ;
F_23 ( V_15 , V_4 ) ;
F_111 ( V_4 ) ;
F_79 ( V_15 , V_4 ) ;
F_112 ( & V_4 -> V_26 ) ;
F_107 ( V_6 ) ;
F_102 ( V_6 , NULL ) ;
F_93 ( V_4 ) ;
F_108 ( V_6 , V_3 ) ;
F_109 ( V_6 ) ;
F_90 ( V_15 , V_4 ) ;
F_8 ( V_4 ) ;
F_98 ( V_6 , V_4 -> V_14 . V_125 ) ;
F_80 () ;
F_15 ( V_4 ) ;
F_64 ( V_3 , L_21 , V_121 ) ;
F_81 ( V_15 ) ;
return 0 ;
}
static int F_113 ( struct V_15 * V_15 , struct V_49 * V_50 )
{
V_50 -> V_134 . V_135 = V_15 -> V_59 -> V_57 ;
return 0 ;
}
static int F_114 ( struct V_15 * V_15 , struct V_49 * V_50 )
{
return F_61 ( V_15 , V_50 -> V_134 . V_135 ) ;
}
static int F_115 ( struct V_15 * V_15 ,
struct V_49 * V_50 )
{
struct V_1 * V_4 = V_50 -> V_33 -> V_4 ;
V_50 -> V_134 . V_136 = F_67 ( V_4 ) ;
return 0 ;
}
static int F_116 ( struct V_15 * V_15 ,
struct V_49 * V_50 )
{
struct V_1 * V_4 = V_50 -> V_33 -> V_4 ;
if ( V_50 -> V_134 . V_136 )
F_73 ( V_15 , V_4 ) ;
else
F_79 ( V_15 , V_4 ) ;
return 0 ;
}
static int F_117 ( struct V_15 * V_15 ,
struct V_49 * V_50 )
{
struct V_1 * V_4 = V_50 -> V_33 -> V_4 ;
V_50 -> V_134 . V_136 = V_4 -> V_17 . V_16 ;
return 0 ;
}
static int F_118 ( struct V_15 * V_15 ,
struct V_49 * V_50 )
{
struct V_1 * V_4 = V_50 -> V_33 -> V_4 ;
V_4 -> V_17 . V_16 = V_50 -> V_134 . V_136 ;
F_10 ( V_4 ) ;
return 0 ;
}
static int F_119 ( struct V_15 * V_15 ,
struct V_49 * V_50 )
{
struct V_1 * V_4 = V_50 -> V_33 -> V_4 ;
V_50 -> V_134 . V_136 = V_4 -> V_17 . V_18 ;
return 0 ;
}
static int F_120 ( struct V_15 * V_15 ,
struct V_49 * V_50 )
{
struct V_1 * V_4 = V_50 -> V_33 -> V_4 ;
V_4 -> V_17 . V_18 = V_50 -> V_134 . V_136 ;
F_10 ( V_4 ) ;
return 0 ;
}
static void F_121 ( struct V_2 * V_3 ,
struct V_137 * V_138 ,
void * V_139 )
{
F_122 ( & V_138 -> V_140 , & V_141 ) ;
}
static void F_123 ( struct V_2 * V_3 )
{
F_122 ( & V_3 -> V_142 , & V_143 ) ;
F_124 ( V_3 , F_121 , NULL ) ;
}
static int F_125 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_126 ( V_3 ) ;
int V_29 ;
int V_30 ;
V_15 -> V_3 = V_3 ;
F_127 ( & V_15 -> V_111 ) ;
F_55 ( V_15 ) ;
V_15 -> V_87 = F_128 ( struct V_86 ) ;
if ( ! V_15 -> V_87 )
return - V_32 ;
for ( V_29 = 0 ; V_29 < V_144 ; V_29 ++ )
F_129 ( & V_15 -> V_145 [ V_29 ] ) ;
F_130 ( & V_15 -> V_79 ) ;
F_57 ( V_15 ) ;
F_130 ( & V_15 -> V_47 ) ;
F_130 ( & V_15 -> V_37 ) ;
V_30 = F_31 ( V_15 , V_146 , F_131 ( V_146 ) ) ;
if ( V_30 )
goto V_147;
F_132 ( V_3 ) ;
F_123 ( V_3 ) ;
return 0 ;
V_147:
F_133 ( V_15 -> V_87 ) ;
return V_30 ;
}
static void F_134 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_126 ( V_3 ) ;
struct V_1 * V_4 ;
struct V_1 * V_27 ;
F_85 ( & V_15 -> V_111 ) ;
F_17 (port, tmp, &team->port_list, list)
F_110 ( V_15 , V_4 -> V_3 ) ;
F_58 ( V_15 , NULL ) ;
F_30 ( V_15 , V_146 , F_131 ( V_146 ) ) ;
F_86 ( & V_15 -> V_111 ) ;
}
static void F_135 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_126 ( V_3 ) ;
F_133 ( V_15 -> V_87 ) ;
F_136 ( V_3 ) ;
}
static int F_137 ( struct V_2 * V_3 )
{
F_138 ( V_3 ) ;
return 0 ;
}
static int F_139 ( struct V_2 * V_3 )
{
F_132 ( V_3 ) ;
return 0 ;
}
static T_5 F_140 ( struct V_68 * V_69 , struct V_2 * V_3 )
{
struct V_15 * V_15 = F_126 ( V_3 ) ;
bool V_148 = false ;
unsigned int V_91 = V_69 -> V_91 ;
V_148 = V_15 -> V_73 . V_74 ( V_15 , V_69 ) ;
if ( V_148 ) {
struct V_86 * V_87 ;
V_87 = F_68 ( V_15 -> V_87 ) ;
F_69 ( & V_87 -> V_88 ) ;
V_87 -> V_149 ++ ;
V_87 -> V_150 += V_91 ;
F_70 ( & V_87 -> V_88 ) ;
} else {
F_71 ( V_15 -> V_87 -> V_151 ) ;
}
return V_152 ;
}
static T_6 F_141 ( struct V_2 * V_3 , struct V_68 * V_69 )
{
T_6 V_138 = F_142 ( V_69 ) ? F_143 ( V_69 ) : 0 ;
F_144 ( V_69 ) -> V_153 = V_69 -> V_154 ;
if ( F_145 ( V_138 >= V_3 -> V_155 ) ) {
do {
V_138 -= V_3 -> V_155 ;
} while ( V_138 >= V_3 -> V_155 );
}
return V_138 ;
}
static void F_146 ( struct V_2 * V_3 , int V_156 )
{
struct V_15 * V_15 = F_126 ( V_3 ) ;
struct V_1 * V_4 ;
int V_157 ;
F_147 () ;
F_148 (port, &team->port_list, list) {
if ( V_156 & V_158 ) {
V_157 = V_3 -> V_106 & V_158 ? 1 : - 1 ;
F_149 ( V_4 -> V_3 , V_157 ) ;
}
if ( V_156 & V_159 ) {
V_157 = V_3 -> V_106 & V_159 ? 1 : - 1 ;
F_150 ( V_4 -> V_3 , V_157 ) ;
}
}
F_151 () ;
}
static void F_152 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_126 ( V_3 ) ;
struct V_1 * V_4 ;
F_147 () ;
F_148 (port, &team->port_list, list) {
F_153 ( V_4 -> V_3 , V_3 ) ;
F_154 ( V_4 -> V_3 , V_3 ) ;
}
F_151 () ;
}
static int F_155 ( struct V_2 * V_3 , void * V_160 )
{
struct V_15 * V_15 = F_126 ( V_3 ) ;
struct V_1 * V_4 ;
int V_30 ;
V_30 = F_156 ( V_3 , V_160 ) ;
if ( V_30 )
return V_30 ;
F_147 () ;
F_148 (port, &team->port_list, list)
if ( V_15 -> V_73 . V_161 )
V_15 -> V_73 . V_161 ( V_15 , V_4 ) ;
F_151 () ;
return 0 ;
}
static int F_157 ( struct V_2 * V_3 , int V_162 )
{
struct V_15 * V_15 = F_126 ( V_3 ) ;
struct V_1 * V_4 ;
int V_30 ;
F_85 ( & V_15 -> V_111 ) ;
F_12 (port, &team->port_list, list) {
V_30 = F_98 ( V_4 -> V_3 , V_162 ) ;
if ( V_30 ) {
F_63 ( V_3 , L_22 ,
V_4 -> V_3 -> V_23 ) ;
goto V_163;
}
}
F_86 ( & V_15 -> V_111 ) ;
V_3 -> V_125 = V_162 ;
return 0 ;
V_163:
F_158 (port, &team->port_list, list)
F_98 ( V_4 -> V_3 , V_3 -> V_125 ) ;
F_86 ( & V_15 -> V_111 ) ;
return V_30 ;
}
static struct V_164 *
F_159 ( struct V_2 * V_3 , struct V_164 * V_165 )
{
struct V_15 * V_15 = F_126 ( V_3 ) ;
struct V_86 * V_160 ;
T_7 V_89 , V_90 , V_94 , V_149 , V_150 ;
T_3 V_95 = 0 , V_151 = 0 ;
unsigned int V_166 ;
int V_29 ;
F_160 (i) {
V_160 = F_161 ( V_15 -> V_87 , V_29 ) ;
do {
V_166 = F_162 ( & V_160 -> V_88 ) ;
V_89 = V_160 -> V_89 ;
V_90 = V_160 -> V_90 ;
V_94 = V_160 -> V_94 ;
V_149 = V_160 -> V_149 ;
V_150 = V_160 -> V_150 ;
} while ( F_163 ( & V_160 -> V_88 , V_166 ) );
V_165 -> V_89 += V_89 ;
V_165 -> V_90 += V_90 ;
V_165 -> V_167 += V_94 ;
V_165 -> V_149 += V_149 ;
V_165 -> V_150 += V_150 ;
V_95 += V_160 -> V_95 ;
V_151 += V_160 -> V_151 ;
}
V_165 -> V_95 = V_95 ;
V_165 -> V_151 = V_151 ;
return V_165 ;
}
static int F_164 ( struct V_2 * V_3 , T_8 V_168 )
{
struct V_15 * V_15 = F_126 ( V_3 ) ;
struct V_1 * V_4 ;
int V_30 ;
F_85 ( & V_15 -> V_111 ) ;
F_12 (port, &team->port_list, list) {
V_30 = F_165 ( V_4 -> V_3 , V_168 ) ;
if ( V_30 )
goto V_163;
}
F_86 ( & V_15 -> V_111 ) ;
return 0 ;
V_163:
F_158 (port, &team->port_list, list)
F_166 ( V_4 -> V_3 , V_168 ) ;
F_86 ( & V_15 -> V_111 ) ;
return V_30 ;
}
static int F_167 ( struct V_2 * V_3 , T_8 V_168 )
{
struct V_15 * V_15 = F_126 ( V_3 ) ;
struct V_1 * V_4 ;
F_147 () ;
F_148 (port, &team->port_list, list)
F_166 ( V_4 -> V_3 , V_168 ) ;
F_151 () ;
return 0 ;
}
static void F_168 ( struct V_2 * V_3 )
{
}
static void F_169 ( struct V_15 * V_15 )
{
struct V_1 * V_4 ;
F_12 (port, &team->port_list, list)
F_93 ( V_4 ) ;
}
static void F_170 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_126 ( V_3 ) ;
F_85 ( & V_15 -> V_111 ) ;
F_169 ( V_15 ) ;
F_86 ( & V_15 -> V_111 ) ;
}
static int F_171 ( struct V_2 * V_3 ,
struct V_119 * V_169 , T_4 V_116 )
{
struct V_15 * V_15 = F_126 ( V_3 ) ;
struct V_1 * V_4 ;
int V_30 = 0 ;
F_85 ( & V_15 -> V_111 ) ;
F_12 (port, &team->port_list, list) {
V_30 = F_91 ( V_15 , V_4 , V_116 ) ;
if ( V_30 ) {
F_169 ( V_15 ) ;
break;
}
}
F_86 ( & V_15 -> V_111 ) ;
return V_30 ;
}
static int F_172 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_15 * V_15 = F_126 ( V_3 ) ;
int V_30 ;
F_85 ( & V_15 -> V_111 ) ;
V_30 = F_97 ( V_15 , V_6 ) ;
F_86 ( & V_15 -> V_111 ) ;
return V_30 ;
}
static int F_173 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_15 * V_15 = F_126 ( V_3 ) ;
int V_30 ;
F_85 ( & V_15 -> V_111 ) ;
V_30 = F_110 ( V_15 , V_6 ) ;
F_86 ( & V_15 -> V_111 ) ;
return V_30 ;
}
static T_9 F_174 ( struct V_2 * V_3 ,
T_9 V_170 )
{
struct V_1 * V_4 ;
struct V_15 * V_15 = F_126 ( V_3 ) ;
T_9 V_171 ;
V_171 = V_170 ;
V_170 &= ~ V_172 ;
V_170 |= V_173 ;
F_147 () ;
F_148 (port, &team->port_list, list) {
V_170 = F_82 ( V_170 ,
V_4 -> V_3 -> V_170 ,
V_171 ) ;
}
F_151 () ;
return V_170 ;
}
static void F_175 ( struct V_2 * V_3 )
{
F_176 ( V_3 ) ;
V_3 -> V_174 = & V_175 ;
V_3 -> V_176 = F_135 ;
V_3 -> V_177 = 0 ;
V_3 -> V_106 |= V_178 ;
V_3 -> V_109 &= ~ ( V_108 | V_179 ) ;
V_3 -> V_109 |= V_180 | V_181 ;
V_3 -> V_170 |= V_182 ;
V_3 -> V_170 |= V_183 ;
V_3 -> V_184 = V_185 |
V_186 |
V_187 ;
V_3 -> V_170 |= V_3 -> V_184 ;
}
static int F_177 ( struct V_188 * V_189 , struct V_2 * V_3 ,
struct V_190 * V_191 [] , struct V_190 * V_134 [] )
{
int V_30 ;
if ( V_191 [ V_192 ] == NULL )
F_178 ( V_3 ) ;
V_30 = F_179 ( V_3 ) ;
if ( V_30 )
return V_30 ;
return 0 ;
}
static int F_180 ( struct V_190 * V_191 [] , struct V_190 * V_134 [] )
{
if ( V_191 [ V_192 ] ) {
if ( F_181 ( V_191 [ V_192 ] ) != V_11 )
return - V_63 ;
if ( ! F_182 ( F_183 ( V_191 [ V_192 ] ) ) )
return - V_193 ;
}
return 0 ;
}
static unsigned int F_184 ( void )
{
return V_194 ;
}
static unsigned int F_185 ( void )
{
return V_195 ;
}
static int F_186 ( struct V_68 * V_69 , struct V_196 * V_33 )
{
struct V_68 * V_197 ;
void * V_198 ;
int V_30 ;
V_197 = F_187 ( V_199 , V_31 ) ;
if ( ! V_197 )
return - V_32 ;
V_198 = F_188 ( V_197 , V_33 -> V_200 , V_33 -> V_201 ,
& V_202 , 0 , V_203 ) ;
if ( ! V_198 ) {
V_30 = - V_204 ;
goto V_205;
}
F_189 ( V_197 , V_198 ) ;
return F_190 ( F_191 ( V_33 ) , V_197 , V_33 -> V_200 ) ;
V_205:
F_192 ( V_197 ) ;
return V_30 ;
}
static struct V_15 * F_193 ( struct V_196 * V_33 )
{
struct V_188 * V_188 = F_191 ( V_33 ) ;
int V_206 ;
struct V_2 * V_3 ;
struct V_15 * V_15 ;
if ( ! V_33 -> V_207 [ V_208 ] )
return NULL ;
V_206 = F_194 ( V_33 -> V_207 [ V_208 ] ) ;
V_3 = F_195 ( V_188 , V_206 ) ;
if ( ! V_3 || V_3 -> V_174 != & V_175 ) {
if ( V_3 )
F_89 ( V_3 ) ;
return NULL ;
}
V_15 = F_126 ( V_3 ) ;
F_85 ( & V_15 -> V_111 ) ;
return V_15 ;
}
static void F_196 ( struct V_15 * V_15 )
{
F_86 ( & V_15 -> V_111 ) ;
F_89 ( V_15 -> V_3 ) ;
}
static int F_197 ( struct V_196 * V_33 , struct V_15 * V_15 ,
int (* F_198)( struct V_68 * V_69 ,
struct V_196 * V_33 ,
int V_106 , struct V_15 * V_15 ) )
{
struct V_68 * V_69 ;
int V_30 ;
V_69 = F_187 ( V_199 , V_31 ) ;
if ( ! V_69 )
return - V_32 ;
V_30 = F_198 ( V_69 , V_33 , V_209 , V_15 ) ;
if ( V_30 < 0 )
goto V_210;
V_30 = F_190 ( F_191 ( V_33 ) , V_69 , V_33 -> V_200 ) ;
return V_30 ;
V_210:
F_192 ( V_69 ) ;
return V_30 ;
}
static int F_199 ( struct V_68 * V_69 , struct V_15 * V_15 , T_3 V_211 )
{
return F_190 ( F_200 ( V_15 -> V_3 ) , V_69 , V_211 ) ;
}
static int F_201 ( struct V_68 * V_69 , struct V_15 * V_15 ,
struct V_24 * V_25 )
{
struct V_190 * V_212 ;
struct V_20 * V_22 = V_25 -> V_22 ;
struct V_54 * V_55 = & V_25 -> V_33 ;
struct V_49 V_50 ;
int V_30 ;
V_50 . V_33 = V_55 ;
V_30 = F_34 ( V_15 , V_25 , & V_50 ) ;
if ( V_30 )
return V_30 ;
V_212 = F_202 ( V_69 , V_213 ) ;
if ( ! V_212 )
return - V_204 ;
if ( F_203 ( V_69 , V_214 , V_22 -> V_23 ) )
goto V_215;
if ( V_55 -> V_4 &&
F_204 ( V_69 , V_216 ,
V_55 -> V_4 -> V_3 -> V_206 ) )
goto V_215;
if ( V_25 -> V_22 -> V_28 &&
F_204 ( V_69 , V_217 ,
V_55 -> V_34 ) )
goto V_215;
switch ( V_22 -> type ) {
case V_218 :
if ( F_205 ( V_69 , V_219 , V_220 ) )
goto V_215;
if ( F_204 ( V_69 , V_221 , V_50 . V_134 . V_222 ) )
goto V_215;
break;
case V_223 :
if ( F_205 ( V_69 , V_219 , V_224 ) )
goto V_215;
if ( F_203 ( V_69 , V_221 ,
V_50 . V_134 . V_135 ) )
goto V_215;
break;
case V_225 :
if ( F_205 ( V_69 , V_219 , V_226 ) )
goto V_215;
if ( F_206 ( V_69 , V_221 , V_50 . V_134 . V_227 . V_91 ,
V_50 . V_134 . V_227 . V_228 ) )
goto V_215;
break;
case V_229 :
if ( F_205 ( V_69 , V_219 , V_230 ) )
goto V_215;
if ( V_50 . V_134 . V_136 &&
F_207 ( V_69 , V_221 ) )
goto V_215;
break;
default:
F_208 () ;
}
if ( V_25 -> V_36 && F_207 ( V_69 , V_231 ) )
goto V_215;
if ( V_25 -> V_35 ) {
if ( F_207 ( V_69 , V_232 ) )
goto V_215;
V_25 -> V_35 = false ;
}
F_209 ( V_69 , V_212 ) ;
return 0 ;
V_215:
F_210 ( V_69 , V_212 ) ;
return - V_204 ;
}
static int F_211 ( struct V_68 * * V_81 ,
struct V_15 * V_15 , T_3 V_211 ,
T_10 * V_233 )
{
int V_30 ;
if ( * V_81 ) {
V_30 = V_233 ( * V_81 , V_15 , V_211 ) ;
if ( V_30 )
return V_30 ;
}
* V_81 = F_212 ( V_234 , V_31 ) ;
if ( ! * V_81 )
return - V_32 ;
return 0 ;
}
static int F_213 ( struct V_15 * V_15 , T_3 V_211 , T_3 V_235 ,
int V_106 , T_10 * V_233 ,
struct V_236 * V_237 )
{
struct V_190 * V_47 ;
struct V_238 * V_239 ;
void * V_198 ;
struct V_24 * V_25 ;
int V_30 ;
struct V_68 * V_69 = NULL ;
bool V_240 ;
int V_29 ;
V_25 = F_214 ( V_237 ,
struct V_24 , V_241 ) ;
V_242:
V_30 = F_211 ( & V_69 , V_15 , V_211 , V_233 ) ;
if ( V_30 )
return V_30 ;
V_198 = F_188 ( V_69 , V_211 , V_235 , & V_202 , V_106 | V_243 ,
V_244 ) ;
if ( ! V_198 )
return - V_204 ;
if ( F_204 ( V_69 , V_208 , V_15 -> V_3 -> V_206 ) )
goto V_245;
V_47 = F_202 ( V_69 , V_246 ) ;
if ( ! V_47 )
goto V_245;
V_29 = 0 ;
V_240 = false ;
F_215 (opt_inst, sel_opt_inst_list, tmp_list) {
V_30 = F_201 ( V_69 , V_15 , V_25 ) ;
if ( V_30 ) {
if ( V_30 == - V_204 ) {
if ( ! V_29 )
goto V_247;
V_240 = true ;
break;
}
goto V_247;
}
V_29 ++ ;
}
F_209 ( V_69 , V_47 ) ;
F_189 ( V_69 , V_198 ) ;
if ( V_240 )
goto V_242;
V_248:
V_239 = F_216 ( V_69 , V_211 , V_235 , V_249 , 0 , V_106 | V_243 ) ;
if ( ! V_239 ) {
V_30 = F_211 ( & V_69 , V_15 , V_211 , V_233 ) ;
if ( V_30 )
goto V_247;
goto V_248;
}
return V_233 ( V_69 , V_15 , V_211 ) ;
V_245:
V_30 = - V_204 ;
V_247:
F_217 ( V_69 , V_198 ) ;
F_192 ( V_69 ) ;
return V_30 ;
}
static int F_218 ( struct V_68 * V_69 , struct V_196 * V_33 )
{
struct V_15 * V_15 ;
struct V_24 * V_25 ;
int V_30 ;
F_219 ( V_237 ) ;
V_15 = F_193 ( V_33 ) ;
if ( ! V_15 )
return - V_63 ;
F_12 (opt_inst, &team->option_inst_list, list)
F_20 ( & V_25 -> V_241 , & V_237 ) ;
V_30 = F_213 ( V_15 , V_33 -> V_200 , V_33 -> V_201 ,
V_209 , F_199 ,
& V_237 ) ;
F_196 ( V_15 ) ;
return V_30 ;
}
static int F_220 ( struct V_68 * V_69 , struct V_196 * V_33 )
{
struct V_15 * V_15 ;
int V_30 = 0 ;
int V_29 ;
struct V_190 * V_250 ;
F_219 ( V_251 ) ;
V_15 = F_193 ( V_33 ) ;
if ( ! V_15 )
return - V_63 ;
V_30 = - V_63 ;
if ( ! V_33 -> V_207 [ V_246 ] ) {
V_30 = - V_63 ;
goto V_252;
}
F_221 (nl_option, info->attrs[TEAM_ATTR_LIST_OPTION], i) {
struct V_190 * V_253 [ V_254 + 1 ] ;
struct V_190 * V_255 ;
struct V_190 * V_256 ;
enum V_257 V_258 ;
int V_259 = 0 ;
T_3 V_260 = 0 ;
bool V_261 = false ;
struct V_24 * V_25 ;
char * V_21 ;
bool V_262 = false ;
if ( F_222 ( V_250 ) != V_213 ) {
V_30 = - V_63 ;
goto V_252;
}
V_30 = F_223 ( V_253 , V_254 ,
V_250 , V_263 ) ;
if ( V_30 )
goto V_252;
if ( ! V_253 [ V_214 ] ||
! V_253 [ V_219 ] ) {
V_30 = - V_63 ;
goto V_252;
}
switch ( F_224 ( V_253 [ V_219 ] ) ) {
case V_220 :
V_258 = V_218 ;
break;
case V_224 :
V_258 = V_223 ;
break;
case V_226 :
V_258 = V_225 ;
break;
case V_230 :
V_258 = V_229 ;
break;
default:
goto V_252;
}
V_256 = V_253 [ V_221 ] ;
if ( V_258 != V_229 && ! V_256 ) {
V_30 = - V_63 ;
goto V_252;
}
V_21 = F_183 ( V_253 [ V_214 ] ) ;
V_255 = V_253 [ V_216 ] ;
if ( V_255 )
V_259 = F_194 ( V_255 ) ;
V_255 = V_253 [ V_217 ] ;
if ( V_255 ) {
V_261 = true ;
V_260 = F_194 ( V_255 ) ;
}
F_12 (opt_inst, &team->option_inst_list, list) {
struct V_20 * V_22 = V_25 -> V_22 ;
struct V_49 V_50 ;
struct V_54 * V_55 ;
int V_264 ;
V_55 = & V_25 -> V_33 ;
V_264 = V_55 -> V_4 ?
V_55 -> V_4 -> V_3 -> V_206 : 0 ;
if ( V_22 -> type != V_258 ||
strcmp ( V_22 -> V_23 , V_21 ) ||
V_264 != V_259 ||
( V_22 -> V_28 && ! V_261 ) ||
V_55 -> V_34 != V_260 )
continue;
V_262 = true ;
V_50 . V_33 = V_55 ;
switch ( V_258 ) {
case V_218 :
V_50 . V_134 . V_222 = F_194 ( V_256 ) ;
break;
case V_223 :
if ( F_181 ( V_256 ) > V_265 ) {
V_30 = - V_63 ;
goto V_252;
}
V_50 . V_134 . V_135 = F_183 ( V_256 ) ;
break;
case V_225 :
V_50 . V_134 . V_227 . V_91 = F_181 ( V_256 ) ;
V_50 . V_134 . V_227 . V_228 = F_183 ( V_256 ) ;
break;
case V_229 :
V_50 . V_134 . V_136 = V_256 ? true : false ;
break;
default:
F_208 () ;
}
V_30 = F_35 ( V_15 , V_25 , & V_50 ) ;
if ( V_30 )
goto V_252;
V_25 -> V_35 = true ;
F_225 ( & V_25 -> V_241 , & V_251 ) ;
}
if ( ! V_262 ) {
V_30 = - V_133 ;
goto V_252;
}
}
V_30 = F_226 ( V_15 , & V_251 ) ;
V_252:
F_196 ( V_15 ) ;
return V_30 ;
}
static int F_227 ( struct V_68 * V_69 ,
T_3 V_211 , T_3 V_235 , int V_106 ,
struct V_15 * V_15 ,
bool V_266 )
{
struct V_190 * V_79 ;
void * V_198 ;
struct V_1 * V_4 ;
V_198 = F_188 ( V_69 , V_211 , V_235 , & V_202 , V_106 ,
V_267 ) ;
if ( ! V_198 )
return - V_204 ;
if ( F_204 ( V_69 , V_208 , V_15 -> V_3 -> V_206 ) )
goto V_245;
V_79 = F_202 ( V_69 , V_268 ) ;
if ( ! V_79 )
goto V_245;
F_12 (port, &team->port_list, list) {
struct V_190 * V_269 ;
if ( ! V_266 && ! V_4 -> V_35 )
continue;
V_269 = F_202 ( V_69 , V_270 ) ;
if ( ! V_269 )
goto V_245;
if ( F_204 ( V_69 , V_271 , V_4 -> V_3 -> V_206 ) )
goto V_245;
if ( V_4 -> V_35 ) {
if ( F_207 ( V_69 , V_272 ) )
goto V_245;
V_4 -> V_35 = false ;
}
if ( ( V_4 -> V_36 &&
F_207 ( V_69 , V_273 ) ) ||
( V_4 -> V_19 . V_16 &&
F_207 ( V_69 , V_274 ) ) ||
F_204 ( V_69 , V_275 , V_4 -> V_19 . V_276 ) ||
F_205 ( V_69 , V_277 , V_4 -> V_19 . V_278 ) )
goto V_245;
F_209 ( V_69 , V_269 ) ;
}
F_209 ( V_69 , V_79 ) ;
return F_189 ( V_69 , V_198 ) ;
V_245:
F_217 ( V_69 , V_198 ) ;
return - V_204 ;
}
static int F_228 ( struct V_68 * V_69 ,
struct V_196 * V_33 , int V_106 ,
struct V_15 * V_15 )
{
return F_227 ( V_69 , V_33 -> V_200 ,
V_33 -> V_201 , V_209 ,
V_15 , true ) ;
}
static int F_229 ( struct V_68 * V_69 ,
struct V_196 * V_33 )
{
struct V_15 * V_15 ;
int V_30 ;
V_15 = F_193 ( V_33 ) ;
if ( ! V_15 )
return - V_63 ;
V_30 = F_197 ( V_33 , V_15 , F_228 ) ;
F_196 ( V_15 ) ;
return V_30 ;
}
static int F_230 ( struct V_68 * V_69 ,
struct V_15 * V_15 , T_3 V_211 )
{
return F_231 ( F_200 ( V_15 -> V_3 ) , V_69 , 0 ,
V_279 . V_280 , V_31 ) ;
}
static int F_226 ( struct V_15 * V_15 ,
struct V_236 * V_237 )
{
return F_213 ( V_15 , 0 , 0 , 0 , F_230 ,
V_237 ) ;
}
static int F_232 ( struct V_15 * V_15 )
{
struct V_68 * V_69 ;
int V_30 ;
struct V_188 * V_188 = F_200 ( V_15 -> V_3 ) ;
V_69 = F_187 ( V_199 , V_31 ) ;
if ( ! V_69 )
return - V_32 ;
V_30 = F_227 ( V_69 , 0 , 0 , 0 , V_15 , false ) ;
if ( V_30 < 0 )
goto V_210;
V_30 = F_231 ( V_188 , V_69 , 0 , V_279 . V_280 ,
V_31 ) ;
return V_30 ;
V_210:
F_192 ( V_69 ) ;
return V_30 ;
}
static int F_233 ( void )
{
int V_30 ;
V_30 = F_234 ( & V_202 , V_281 ,
F_131 ( V_281 ) ) ;
if ( V_30 )
return V_30 ;
V_30 = F_235 ( & V_202 , & V_279 ) ;
if ( V_30 )
goto V_282;
return 0 ;
V_282:
F_236 ( & V_202 ) ;
return V_30 ;
}
static void F_237 ( void )
{
F_236 ( & V_202 ) ;
}
static void F_32 ( struct V_15 * V_15 )
{
int V_30 ;
struct V_24 * V_25 ;
F_219 ( V_237 ) ;
F_12 (opt_inst, &team->option_inst_list, list) {
if ( V_25 -> V_35 )
F_20 ( & V_25 -> V_241 , & V_237 ) ;
}
V_30 = F_226 ( V_15 , & V_237 ) ;
if ( V_30 )
F_238 ( V_15 -> V_3 , L_23 ,
V_30 ) ;
}
static void F_239 ( struct V_1 * V_4 , bool V_16 )
{
int V_30 ;
V_4 -> V_35 = true ;
V_4 -> V_19 . V_16 = V_16 ;
F_10 ( V_4 ) ;
if ( V_16 ) {
struct V_283 V_284 ;
V_30 = F_240 ( V_4 -> V_3 , & V_284 ) ;
if ( ! V_30 ) {
V_4 -> V_19 . V_276 = F_241 ( & V_284 ) ;
V_4 -> V_19 . V_278 = V_284 . V_278 ;
goto V_285;
}
}
V_4 -> V_19 . V_276 = 0 ;
V_4 -> V_19 . V_278 = 0 ;
V_285:
V_30 = F_232 ( V_4 -> V_15 ) ;
if ( V_30 )
F_238 ( V_4 -> V_15 -> V_3 , L_24 ,
V_4 -> V_3 -> V_23 ) ;
}
static void F_242 ( struct V_1 * V_4 , bool V_16 )
{
if ( V_4 -> V_19 . V_16 != V_16 )
F_239 ( V_4 , V_16 ) ;
}
static void F_105 ( struct V_1 * V_4 , bool V_16 )
{
F_239 ( V_4 , V_16 ) ;
}
static void F_111 ( struct V_1 * V_4 )
{
V_4 -> V_36 = true ;
F_239 ( V_4 , false ) ;
}
static void F_243 ( struct V_1 * V_4 , bool V_16 )
{
struct V_15 * V_15 = V_4 -> V_15 ;
F_85 ( & V_15 -> V_111 ) ;
F_242 ( V_4 , V_16 ) ;
F_86 ( & V_15 -> V_111 ) ;
}
static int F_244 ( struct V_286 * V_139 ,
unsigned long V_287 , void * V_228 )
{
struct V_2 * V_3 = (struct V_2 * ) V_228 ;
struct V_1 * V_4 ;
V_4 = F_4 ( V_3 ) ;
if ( ! V_4 )
return V_288 ;
switch ( V_287 ) {
case V_289 :
if ( F_106 ( V_3 ) )
F_243 ( V_4 , true ) ;
case V_290 :
F_243 ( V_4 , false ) ;
case V_291 :
if ( F_245 ( V_4 -> V_3 ) )
F_243 ( V_4 ,
! ! F_106 ( V_4 -> V_3 ) ) ;
break;
case V_292 :
F_173 ( V_4 -> V_15 -> V_3 , V_3 ) ;
break;
case V_293 :
F_84 ( V_4 -> V_15 ) ;
break;
case V_294 :
return V_295 ;
case V_296 :
return V_295 ;
}
return V_288 ;
}
static int T_11 F_246 ( void )
{
int V_30 ;
F_247 ( & V_297 ) ;
V_30 = F_248 ( & V_298 ) ;
if ( V_30 )
goto V_299;
V_30 = F_233 () ;
if ( V_30 )
goto V_300;
return 0 ;
V_300:
F_249 ( & V_298 ) ;
V_299:
F_250 ( & V_297 ) ;
return V_30 ;
}
static void T_12 F_251 ( void )
{
F_237 () ;
F_249 ( & V_298 ) ;
F_250 ( & V_297 ) ;
}
