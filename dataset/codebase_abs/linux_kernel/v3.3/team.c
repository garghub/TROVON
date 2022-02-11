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
int F_8 ( struct V_1 * V_4 )
{
return F_6 ( V_4 -> V_3 , V_4 -> V_14 . V_7 ) ;
}
int F_9 ( struct V_1 * V_4 )
{
return F_6 ( V_4 -> V_3 , V_4 -> V_15 -> V_3 -> V_7 ) ;
}
struct V_16 * F_10 ( struct V_15 * V_15 , const char * V_17 )
{
struct V_16 * V_18 ;
F_11 (option, &team->option_list, list) {
if ( strcmp ( V_18 -> V_19 , V_17 ) == 0 )
return V_18 ;
}
return NULL ;
}
int F_12 ( struct V_15 * V_15 ,
const struct V_16 * V_18 ,
T_1 V_20 )
{
int V_21 ;
struct V_16 * * V_22 ;
int V_23 ;
V_22 = F_13 ( sizeof( struct V_16 * ) * V_20 ,
V_24 ) ;
if ( ! V_22 )
return - V_25 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ , V_18 ++ ) {
if ( F_10 ( V_15 , V_18 -> V_19 ) ) {
V_23 = - V_26 ;
goto V_27;
}
V_22 [ V_21 ] = F_14 ( V_18 , sizeof( * V_18 ) , V_24 ) ;
if ( ! V_22 [ V_21 ] ) {
V_23 = - V_25 ;
goto V_27;
}
}
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
V_22 [ V_21 ] -> V_28 = true ;
V_22 [ V_21 ] -> V_29 = false ;
F_15 ( & V_22 [ V_21 ] -> V_30 , & V_15 -> V_31 ) ;
}
F_16 ( V_22 ) ;
return 0 ;
V_27:
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ )
F_16 ( V_22 [ V_21 ] ) ;
F_16 ( V_22 ) ;
return V_23 ;
}
static void F_17 ( struct V_15 * V_15 ,
const struct V_16 * V_18 ,
T_1 V_20 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ , V_18 ++ ) {
struct V_16 * V_32 ;
V_32 = F_10 ( V_15 , V_18 -> V_19 ) ;
if ( V_32 ) {
V_32 -> V_28 = true ;
V_32 -> V_29 = true ;
}
}
}
static void F_18 ( struct V_15 * V_15 ,
const struct V_16 * V_18 ,
T_1 V_20 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ , V_18 ++ ) {
struct V_16 * V_32 ;
V_32 = F_10 ( V_15 , V_18 -> V_19 ) ;
if ( V_32 ) {
F_19 ( & V_32 -> V_30 ) ;
F_16 ( V_32 ) ;
}
}
}
int F_20 ( struct V_15 * V_15 ,
const struct V_16 * V_18 ,
T_1 V_20 )
{
int V_23 ;
V_23 = F_12 ( V_15 , V_18 , V_20 ) ;
if ( V_23 )
return V_23 ;
F_21 ( V_15 ) ;
return 0 ;
}
void F_22 ( struct V_15 * V_15 ,
const struct V_16 * V_18 ,
T_1 V_20 )
{
F_17 ( V_15 , V_18 , V_20 ) ;
F_21 ( V_15 ) ;
F_18 ( V_15 , V_18 , V_20 ) ;
}
static int F_23 ( struct V_15 * V_15 , struct V_16 * V_18 ,
void * V_33 )
{
return V_18 -> V_34 ( V_15 , V_33 ) ;
}
static int F_24 ( struct V_15 * V_15 , struct V_16 * V_18 ,
void * V_33 )
{
int V_23 ;
V_23 = V_18 -> V_35 ( V_15 , V_33 ) ;
if ( V_23 )
return V_23 ;
V_18 -> V_28 = true ;
F_21 ( V_15 ) ;
return V_23 ;
}
static struct V_36 * F_25 ( const char * V_37 )
{
struct V_36 * V_38 ;
F_11 (mode, &mode_list, list) {
if ( strcmp ( V_38 -> V_37 , V_37 ) == 0 )
return V_38 ;
}
return NULL ;
}
static bool F_26 ( const char * V_19 )
{
while ( * V_19 != '\0' ) {
if ( ! isalpha ( * V_19 ) && ! isdigit ( * V_19 ) && * V_19 != '_' )
return false ;
V_19 ++ ;
}
return true ;
}
int F_27 ( struct V_36 * V_38 )
{
int V_23 = 0 ;
if ( ! F_26 ( V_38 -> V_37 ) ||
V_38 -> V_39 > V_40 )
return - V_41 ;
F_28 ( & V_42 ) ;
if ( F_25 ( V_38 -> V_37 ) ) {
V_23 = - V_26 ;
goto V_43;
}
F_15 ( & V_38 -> V_30 , & V_44 ) ;
V_43:
F_29 ( & V_42 ) ;
return V_23 ;
}
int F_30 ( struct V_36 * V_38 )
{
F_28 ( & V_42 ) ;
F_31 ( & V_38 -> V_30 ) ;
F_29 ( & V_42 ) ;
return 0 ;
}
static struct V_36 * F_32 ( const char * V_37 )
{
struct V_36 * V_38 ;
F_28 ( & V_42 ) ;
V_38 = F_25 ( V_37 ) ;
if ( ! V_38 ) {
F_29 ( & V_42 ) ;
F_33 ( L_1 , V_37 ) ;
F_28 ( & V_42 ) ;
V_38 = F_25 ( V_37 ) ;
}
if ( V_38 )
if ( ! F_34 ( V_38 -> V_45 ) )
V_38 = NULL ;
F_29 ( & V_42 ) ;
return V_38 ;
}
static void F_35 ( const struct V_36 * V_38 )
{
F_36 ( V_38 -> V_45 ) ;
}
static bool F_37 ( struct V_15 * V_15 , struct V_46 * V_47 )
{
F_38 ( V_47 ) ;
return false ;
}
T_2 F_39 ( struct V_15 * V_15 ,
struct V_1 * V_4 ,
struct V_46 * V_47 )
{
return V_48 ;
}
static void F_40 ( struct V_15 * V_15 )
{
if ( F_41 ( & V_15 -> V_49 ) ||
! V_15 -> V_38 || ! V_15 -> V_38 -> V_50 -> V_51 )
V_15 -> V_50 . V_51 = F_37 ;
else
V_15 -> V_50 . V_51 = V_15 -> V_38 -> V_50 -> V_51 ;
if ( F_41 ( & V_15 -> V_49 ) ||
! V_15 -> V_38 || ! V_15 -> V_38 -> V_50 -> V_52 )
V_15 -> V_50 . V_52 = F_39 ;
else
V_15 -> V_50 . V_52 = V_15 -> V_38 -> V_50 -> V_52 ;
}
static int F_42 ( struct V_15 * V_15 ,
const struct V_36 * V_53 )
{
if ( V_15 -> V_38 ) {
void (* F_43)( struct V_15 * V_15 ) = V_15 -> V_50 . exit ;
memset ( & V_15 -> V_50 , 0 , sizeof( struct V_54 ) ) ;
F_40 ( V_15 ) ;
if ( F_43 )
F_43 ( V_15 ) ;
F_35 ( V_15 -> V_38 ) ;
V_15 -> V_38 = NULL ;
memset ( & V_15 -> V_55 , 0 ,
sizeof( struct V_15 ) - F_44 ( struct V_15 , V_55 ) ) ;
}
if ( ! V_53 )
return 0 ;
if ( V_53 -> V_50 -> V_56 ) {
int V_23 ;
V_23 = V_53 -> V_50 -> V_56 ( V_15 ) ;
if ( V_23 )
return V_23 ;
}
V_15 -> V_38 = V_53 ;
memcpy ( & V_15 -> V_50 , V_53 -> V_50 , sizeof( struct V_54 ) ) ;
F_40 ( V_15 ) ;
return 0 ;
}
static int F_45 ( struct V_15 * V_15 , const char * V_37 )
{
struct V_36 * V_53 ;
struct V_2 * V_3 = V_15 -> V_3 ;
int V_23 ;
if ( ! F_41 ( & V_15 -> V_49 ) ) {
F_46 ( V_3 , L_2 ) ;
return - V_57 ;
}
if ( V_15 -> V_38 && strcmp ( V_15 -> V_38 -> V_37 , V_37 ) == 0 ) {
F_46 ( V_3 , L_3 ) ;
return - V_41 ;
}
V_53 = F_32 ( V_37 ) ;
if ( ! V_53 ) {
F_46 ( V_3 , L_4 , V_37 ) ;
return - V_41 ;
}
V_23 = F_42 ( V_15 , V_53 ) ;
if ( V_23 ) {
F_46 ( V_3 , L_5 , V_37 ) ;
F_35 ( V_53 ) ;
return V_23 ;
}
F_47 ( V_3 , L_6 , V_37 ) ;
return 0 ;
}
static T_2 F_48 ( struct V_46 * * V_58 )
{
struct V_46 * V_47 = * V_58 ;
struct V_1 * V_4 ;
struct V_15 * V_15 ;
T_2 V_59 ;
V_47 = F_49 ( V_47 , V_60 ) ;
if ( ! V_47 )
return V_61 ;
* V_58 = V_47 ;
V_4 = F_1 ( V_47 -> V_3 ) ;
V_15 = V_4 -> V_15 ;
V_59 = V_15 -> V_50 . V_52 ( V_15 , V_4 , V_47 ) ;
if ( V_59 == V_48 ) {
struct V_62 * V_63 ;
V_63 = F_50 ( V_15 -> V_63 ) ;
F_51 ( & V_63 -> V_64 ) ;
V_63 -> V_65 ++ ;
V_63 -> V_66 += V_47 -> V_67 ;
if ( V_47 -> V_68 == V_69 )
V_63 -> V_70 ++ ;
F_52 ( & V_63 -> V_64 ) ;
V_47 -> V_3 = V_15 -> V_3 ;
} else {
F_53 ( V_15 -> V_63 -> V_71 ) ;
}
return V_59 ;
}
static bool F_54 ( const struct V_15 * V_15 ,
const struct V_1 * V_4 )
{
struct V_1 * V_72 ;
F_11 (cur, &team->port_list, list)
if ( V_72 == V_4 )
return true ;
return false ;
}
static void F_55 ( struct V_15 * V_15 ,
struct V_1 * V_4 )
{
V_4 -> V_73 = V_15 -> V_74 ++ ;
F_56 ( & V_4 -> V_75 ,
F_57 ( V_15 , V_4 -> V_73 ) ) ;
F_58 ( & V_4 -> V_30 , & V_15 -> V_49 ) ;
}
static void F_59 ( struct V_15 * V_15 , int V_76 )
{
int V_21 ;
struct V_1 * V_4 ;
for ( V_21 = V_76 + 1 ; V_21 < V_15 -> V_74 ; V_21 ++ ) {
V_4 = F_60 ( V_15 , V_21 ) ;
F_61 ( & V_4 -> V_75 ) ;
V_4 -> V_73 -- ;
F_56 ( & V_4 -> V_75 ,
F_57 ( V_15 , V_4 -> V_73 ) ) ;
}
}
static void F_62 ( struct V_15 * V_15 ,
struct V_1 * V_4 )
{
int V_76 = V_4 -> V_73 ;
F_61 ( & V_4 -> V_75 ) ;
F_63 ( & V_4 -> V_30 ) ;
F_59 ( V_15 , V_76 ) ;
V_15 -> V_74 -- ;
}
static void F_64 ( struct V_15 * V_15 )
{
struct V_1 * V_4 ;
T_3 V_77 = V_78 ;
unsigned short V_79 = V_80 ;
F_11 (port, &team->port_list, list) {
V_77 = F_65 ( V_77 ,
V_4 -> V_3 -> V_77 ,
V_78 ) ;
if ( V_4 -> V_3 -> V_81 > V_79 )
V_79 = V_4 -> V_3 -> V_81 ;
}
V_15 -> V_3 -> V_77 = V_77 ;
V_15 -> V_3 -> V_81 = V_79 ;
F_66 ( V_15 -> V_3 ) ;
}
static void F_67 ( struct V_15 * V_15 )
{
F_68 ( & V_15 -> V_82 ) ;
F_64 ( V_15 ) ;
F_69 ( & V_15 -> V_82 ) ;
}
static int F_70 ( struct V_15 * V_15 , struct V_1 * V_4 )
{
int V_23 = 0 ;
F_71 ( V_15 -> V_3 ) ;
V_4 -> V_3 -> V_83 |= V_84 ;
if ( V_15 -> V_50 . V_85 ) {
V_23 = V_15 -> V_50 . V_85 ( V_15 , V_4 ) ;
if ( V_23 ) {
F_46 ( V_15 -> V_3 , L_7 ,
V_4 -> V_3 -> V_19 ) ;
goto V_86;
}
}
return 0 ;
V_86:
V_4 -> V_3 -> V_83 &= ~ V_84 ;
F_72 ( V_15 -> V_3 ) ;
return V_23 ;
}
static void F_73 ( struct V_15 * V_15 , struct V_1 * V_4 )
{
if ( V_15 -> V_50 . V_87 )
V_15 -> V_50 . V_87 ( V_15 , V_4 ) ;
V_4 -> V_3 -> V_83 &= ~ V_84 ;
F_72 ( V_15 -> V_3 ) ;
}
static int F_74 ( struct V_15 * V_15 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_1 * V_4 ;
char * V_88 = V_6 -> V_19 ;
int V_23 ;
if ( V_6 -> V_89 & V_90 ||
V_6 -> type != V_13 ) {
F_46 ( V_3 , L_8 ,
V_88 ) ;
return - V_41 ;
}
if ( F_3 ( V_6 ) ) {
F_46 ( V_3 , L_9
L_10 , V_88 ) ;
return - V_57 ;
}
if ( V_6 -> V_89 & V_91 ) {
F_46 ( V_3 , L_11 ,
V_88 ) ;
return - V_57 ;
}
V_4 = F_13 ( sizeof( struct V_1 ) , V_24 ) ;
if ( ! V_4 )
return - V_25 ;
V_4 -> V_3 = V_6 ;
V_4 -> V_15 = V_15 ;
V_4 -> V_14 . V_92 = V_6 -> V_92 ;
V_23 = F_75 ( V_6 , V_3 -> V_92 ) ;
if ( V_23 ) {
F_76 ( V_3 , L_12 , V_23 ) ;
goto V_93;
}
memcpy ( V_4 -> V_14 . V_7 , V_6 -> V_7 , V_11 ) ;
V_23 = F_70 ( V_15 , V_4 ) ;
if ( V_23 ) {
F_46 ( V_3 , L_7 ,
V_88 ) ;
goto V_86;
}
V_23 = F_77 ( V_6 ) ;
if ( V_23 ) {
F_76 ( V_3 , L_13 ,
V_88 ) ;
goto V_94;
}
V_23 = F_78 ( V_6 , V_3 ) ;
if ( V_23 ) {
F_46 ( V_3 , L_14 ,
V_88 ) ;
goto V_95;
}
V_23 = F_79 ( V_6 , V_3 ) ;
if ( V_23 ) {
F_46 ( V_3 , L_15 , V_88 ) ;
goto V_96;
}
V_23 = F_80 ( V_6 , F_48 ,
V_4 ) ;
if ( V_23 ) {
F_46 ( V_3 , L_16 ,
V_88 ) ;
goto V_97;
}
F_55 ( V_15 , V_4 ) ;
F_40 ( V_15 ) ;
F_64 ( V_15 ) ;
F_81 ( V_4 , ! ! F_82 ( V_6 ) ) ;
F_47 ( V_3 , L_17 , V_88 ) ;
return 0 ;
V_97:
F_79 ( V_6 , NULL ) ;
V_96:
F_83 ( V_6 , V_3 ) ;
V_95:
F_84 ( V_6 ) ;
V_94:
F_73 ( V_15 , V_4 ) ;
F_8 ( V_4 ) ;
V_86:
F_75 ( V_6 , V_4 -> V_14 . V_92 ) ;
V_93:
F_16 ( V_4 ) ;
return V_23 ;
}
static int F_85 ( struct V_15 * V_15 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_1 * V_4 ;
char * V_88 = V_6 -> V_19 ;
V_4 = F_4 ( V_6 ) ;
if ( ! V_4 || ! F_54 ( V_15 , V_4 ) ) {
F_46 ( V_3 , L_18 ,
V_88 ) ;
return - V_98 ;
}
V_4 -> V_29 = true ;
F_81 ( V_4 , false ) ;
F_62 ( V_15 , V_4 ) ;
F_40 ( V_15 ) ;
F_86 ( V_6 ) ;
F_79 ( V_6 , NULL ) ;
F_83 ( V_6 , V_3 ) ;
F_84 ( V_6 ) ;
F_73 ( V_15 , V_4 ) ;
F_8 ( V_4 ) ;
F_75 ( V_6 , V_4 -> V_14 . V_92 ) ;
F_87 () ;
F_16 ( V_4 ) ;
F_47 ( V_3 , L_19 , V_88 ) ;
F_64 ( V_15 ) ;
return 0 ;
}
static int F_88 ( struct V_15 * V_15 , void * V_33 )
{
const char * * V_99 = V_33 ;
* V_99 = V_15 -> V_38 ? V_15 -> V_38 -> V_37 : V_100 ;
return 0 ;
}
static int F_89 ( struct V_15 * V_15 , void * V_33 )
{
const char * * V_99 = V_33 ;
return F_45 ( V_15 , * V_99 ) ;
}
static int F_90 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_91 ( V_3 ) ;
int V_21 ;
int V_23 ;
V_15 -> V_3 = V_3 ;
F_92 ( & V_15 -> V_82 ) ;
V_15 -> V_63 = F_93 ( struct V_62 ) ;
if ( ! V_15 -> V_63 )
return - V_25 ;
for ( V_21 = 0 ; V_21 < V_101 ; V_21 ++ )
F_94 ( & V_15 -> V_102 [ V_21 ] ) ;
F_95 ( & V_15 -> V_49 ) ;
F_40 ( V_15 ) ;
F_95 ( & V_15 -> V_31 ) ;
V_23 = F_20 ( V_15 , V_103 , F_96 ( V_103 ) ) ;
if ( V_23 )
goto V_104;
F_97 ( V_3 ) ;
return 0 ;
V_104:
F_98 ( V_15 -> V_63 ) ;
return V_23 ;
}
static void F_99 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_91 ( V_3 ) ;
struct V_1 * V_4 ;
struct V_1 * V_105 ;
F_68 ( & V_15 -> V_82 ) ;
F_100 (port, tmp, &team->port_list, list)
F_85 ( V_15 , V_4 -> V_3 ) ;
F_42 ( V_15 , NULL ) ;
F_18 ( V_15 , V_103 , F_96 ( V_103 ) ) ;
F_69 ( & V_15 -> V_82 ) ;
}
static void F_101 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_91 ( V_3 ) ;
F_98 ( V_15 -> V_63 ) ;
F_102 ( V_3 ) ;
}
static int F_103 ( struct V_2 * V_3 )
{
F_104 ( V_3 ) ;
return 0 ;
}
static int F_105 ( struct V_2 * V_3 )
{
F_97 ( V_3 ) ;
return 0 ;
}
static T_4 F_106 ( struct V_46 * V_47 , struct V_2 * V_3 )
{
struct V_15 * V_15 = F_91 ( V_3 ) ;
bool V_106 = false ;
unsigned int V_67 = V_47 -> V_67 ;
V_106 = V_15 -> V_50 . V_51 ( V_15 , V_47 ) ;
if ( V_106 ) {
struct V_62 * V_63 ;
V_63 = F_50 ( V_15 -> V_63 ) ;
F_51 ( & V_63 -> V_64 ) ;
V_63 -> V_107 ++ ;
V_63 -> V_108 += V_67 ;
F_52 ( & V_63 -> V_64 ) ;
} else {
F_53 ( V_15 -> V_63 -> V_109 ) ;
}
return V_110 ;
}
static void F_107 ( struct V_2 * V_3 , int V_111 )
{
struct V_15 * V_15 = F_91 ( V_3 ) ;
struct V_1 * V_4 ;
int V_112 ;
F_108 () ;
F_109 (port, &team->port_list, list) {
if ( V_111 & V_113 ) {
V_112 = V_3 -> V_89 & V_113 ? 1 : - 1 ;
F_110 ( V_4 -> V_3 , V_112 ) ;
}
if ( V_111 & V_114 ) {
V_112 = V_3 -> V_89 & V_114 ? 1 : - 1 ;
F_111 ( V_4 -> V_3 , V_112 ) ;
}
}
F_112 () ;
}
static void F_113 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_91 ( V_3 ) ;
struct V_1 * V_4 ;
F_108 () ;
F_109 (port, &team->port_list, list) {
F_114 ( V_4 -> V_3 , V_3 ) ;
F_115 ( V_4 -> V_3 , V_3 ) ;
}
F_112 () ;
}
static int F_116 ( struct V_2 * V_3 , void * V_115 )
{
struct V_15 * V_15 = F_91 ( V_3 ) ;
struct V_1 * V_4 ;
struct V_8 * V_9 = V_115 ;
memcpy ( V_3 -> V_7 , V_9 -> V_10 , V_11 ) ;
F_108 () ;
F_109 (port, &team->port_list, list)
if ( V_15 -> V_50 . V_116 )
V_15 -> V_50 . V_116 ( V_15 , V_4 ) ;
F_112 () ;
return 0 ;
}
static int F_117 ( struct V_2 * V_3 , int V_117 )
{
struct V_15 * V_15 = F_91 ( V_3 ) ;
struct V_1 * V_4 ;
int V_23 ;
F_68 ( & V_15 -> V_82 ) ;
F_11 (port, &team->port_list, list) {
V_23 = F_75 ( V_4 -> V_3 , V_117 ) ;
if ( V_23 ) {
F_46 ( V_3 , L_20 ,
V_4 -> V_3 -> V_19 ) ;
goto V_118;
}
}
F_69 ( & V_15 -> V_82 ) ;
V_3 -> V_92 = V_117 ;
return 0 ;
V_118:
F_118 (port, &team->port_list, list)
F_75 ( V_4 -> V_3 , V_3 -> V_92 ) ;
F_69 ( & V_15 -> V_82 ) ;
return V_23 ;
}
static struct V_119 *
F_119 ( struct V_2 * V_3 , struct V_119 * V_120 )
{
struct V_15 * V_15 = F_91 ( V_3 ) ;
struct V_62 * V_115 ;
T_5 V_65 , V_66 , V_70 , V_107 , V_108 ;
T_3 V_71 = 0 , V_109 = 0 ;
unsigned int V_121 ;
int V_21 ;
F_120 (i) {
V_115 = F_121 ( V_15 -> V_63 , V_21 ) ;
do {
V_121 = F_122 ( & V_115 -> V_64 ) ;
V_65 = V_115 -> V_65 ;
V_66 = V_115 -> V_66 ;
V_70 = V_115 -> V_70 ;
V_107 = V_115 -> V_107 ;
V_108 = V_115 -> V_108 ;
} while ( F_123 ( & V_115 -> V_64 , V_121 ) );
V_120 -> V_65 += V_65 ;
V_120 -> V_66 += V_66 ;
V_120 -> V_122 += V_70 ;
V_120 -> V_107 += V_107 ;
V_120 -> V_108 += V_108 ;
V_71 += V_115 -> V_71 ;
V_109 += V_115 -> V_109 ;
}
V_120 -> V_71 = V_71 ;
V_120 -> V_109 = V_109 ;
return V_120 ;
}
static int F_124 ( struct V_2 * V_3 , T_6 V_123 )
{
struct V_15 * V_15 = F_91 ( V_3 ) ;
struct V_1 * V_4 ;
int V_23 ;
F_68 ( & V_15 -> V_82 ) ;
F_11 (port, &team->port_list, list) {
V_23 = F_125 ( V_4 -> V_3 , V_123 ) ;
if ( V_23 )
goto V_118;
}
F_69 ( & V_15 -> V_82 ) ;
return 0 ;
V_118:
F_118 (port, &team->port_list, list)
F_126 ( V_4 -> V_3 , V_123 ) ;
F_69 ( & V_15 -> V_82 ) ;
return V_23 ;
}
static int F_127 ( struct V_2 * V_3 , T_6 V_123 )
{
struct V_15 * V_15 = F_91 ( V_3 ) ;
struct V_1 * V_4 ;
F_108 () ;
F_109 (port, &team->port_list, list)
F_126 ( V_4 -> V_3 , V_123 ) ;
F_112 () ;
return 0 ;
}
static int F_128 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_15 * V_15 = F_91 ( V_3 ) ;
int V_23 ;
F_68 ( & V_15 -> V_82 ) ;
V_23 = F_74 ( V_15 , V_6 ) ;
F_69 ( & V_15 -> V_82 ) ;
return V_23 ;
}
static int F_129 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_15 * V_15 = F_91 ( V_3 ) ;
int V_23 ;
F_68 ( & V_15 -> V_82 ) ;
V_23 = F_85 ( V_15 , V_6 ) ;
F_69 ( & V_15 -> V_82 ) ;
return V_23 ;
}
static T_7 F_130 ( struct V_2 * V_3 ,
T_7 V_124 )
{
struct V_1 * V_4 ;
struct V_15 * V_15 = F_91 ( V_3 ) ;
T_7 V_125 ;
V_125 = V_124 ;
V_124 &= ~ V_126 ;
V_124 |= V_127 ;
F_108 () ;
F_109 (port, &team->port_list, list) {
V_124 = F_65 ( V_124 ,
V_4 -> V_3 -> V_124 ,
V_125 ) ;
}
F_112 () ;
return V_124 ;
}
static void F_131 ( struct V_2 * V_3 )
{
F_132 ( V_3 ) ;
V_3 -> V_128 = & V_129 ;
V_3 -> V_130 = F_101 ;
V_3 -> V_131 = 0 ;
V_3 -> V_89 |= V_132 ;
V_3 -> V_83 &= ~ ( V_133 | V_134 ) ;
V_3 -> V_83 |= V_135 ;
V_3 -> V_124 |= V_136 ;
V_3 -> V_124 |= V_137 ;
V_3 -> V_138 = V_139 |
V_140 |
V_141 ;
V_3 -> V_124 |= V_3 -> V_138 ;
}
static int F_133 ( struct V_142 * V_143 , struct V_2 * V_3 ,
struct V_144 * V_145 [] , struct V_144 * V_146 [] )
{
int V_23 ;
if ( V_145 [ V_147 ] == NULL )
F_134 ( V_3 -> V_7 ) ;
V_23 = F_135 ( V_3 ) ;
if ( V_23 )
return V_23 ;
return 0 ;
}
static int F_136 ( struct V_144 * V_145 [] , struct V_144 * V_146 [] )
{
if ( V_145 [ V_147 ] ) {
if ( F_137 ( V_145 [ V_147 ] ) != V_11 )
return - V_41 ;
if ( ! F_138 ( F_139 ( V_145 [ V_147 ] ) ) )
return - V_148 ;
}
return 0 ;
}
static int F_140 ( struct V_46 * V_47 , struct V_149 * V_150 )
{
struct V_46 * V_151 ;
void * V_152 ;
int V_23 ;
V_151 = F_141 ( V_153 , V_24 ) ;
if ( ! V_151 )
return - V_25 ;
V_152 = F_142 ( V_151 , V_150 -> V_154 , V_150 -> V_155 ,
& V_156 , 0 , V_157 ) ;
if ( F_143 ( V_152 ) ) {
V_23 = F_144 ( V_152 ) ;
goto V_158;
}
F_145 ( V_151 , V_152 ) ;
return F_146 ( F_147 ( V_150 ) , V_151 , V_150 -> V_154 ) ;
V_158:
F_148 ( V_151 ) ;
return V_23 ;
}
static struct V_15 * F_149 ( struct V_149 * V_150 )
{
struct V_142 * V_142 = F_147 ( V_150 ) ;
int V_159 ;
struct V_2 * V_3 ;
struct V_15 * V_15 ;
if ( ! V_150 -> V_160 [ V_161 ] )
return NULL ;
V_159 = F_150 ( V_150 -> V_160 [ V_161 ] ) ;
V_3 = F_151 ( V_142 , V_159 ) ;
if ( ! V_3 || V_3 -> V_128 != & V_129 ) {
if ( V_3 )
F_72 ( V_3 ) ;
return NULL ;
}
V_15 = F_91 ( V_3 ) ;
F_68 ( & V_15 -> V_82 ) ;
return V_15 ;
}
static void F_152 ( struct V_15 * V_15 )
{
F_69 ( & V_15 -> V_82 ) ;
F_72 ( V_15 -> V_3 ) ;
}
static int F_153 ( struct V_149 * V_150 , struct V_15 * V_15 ,
int (* F_154)( struct V_46 * V_47 ,
struct V_149 * V_150 ,
int V_89 , struct V_15 * V_15 ) )
{
struct V_46 * V_47 ;
int V_23 ;
V_47 = F_141 ( V_153 , V_24 ) ;
if ( ! V_47 )
return - V_25 ;
V_23 = F_154 ( V_47 , V_150 , V_162 , V_15 ) ;
if ( V_23 < 0 )
goto V_163;
V_23 = F_146 ( F_147 ( V_150 ) , V_47 , V_150 -> V_154 ) ;
return V_23 ;
V_163:
F_148 ( V_47 ) ;
return V_23 ;
}
static int F_155 ( struct V_46 * V_47 ,
T_3 V_164 , T_3 V_165 , int V_89 ,
struct V_15 * V_15 , bool V_166 )
{
struct V_144 * V_31 ;
void * V_152 ;
struct V_16 * V_18 ;
V_152 = F_142 ( V_47 , V_164 , V_165 , & V_156 , V_89 ,
V_167 ) ;
if ( F_143 ( V_152 ) )
return F_144 ( V_152 ) ;
F_156 ( V_47 , V_161 , V_15 -> V_3 -> V_159 ) ;
V_31 = F_157 ( V_47 , V_168 ) ;
if ( ! V_31 )
return - V_169 ;
F_11 (option, &team->option_list, list) {
struct V_144 * V_170 ;
long V_33 ;
if ( ! V_166 && ! V_18 -> V_28 )
continue;
V_170 = F_157 ( V_47 , V_171 ) ;
if ( ! V_170 )
goto V_172;
F_158 ( V_47 , V_173 , V_18 -> V_19 ) ;
if ( V_18 -> V_28 ) {
F_159 ( V_47 , V_174 ) ;
V_18 -> V_28 = false ;
}
if ( V_18 -> V_29 )
F_159 ( V_47 , V_175 ) ;
switch ( V_18 -> type ) {
case V_176 :
F_160 ( V_47 , V_177 , V_178 ) ;
F_23 ( V_15 , V_18 , & V_33 ) ;
F_156 ( V_47 , V_179 , V_33 ) ;
break;
case V_180 :
F_160 ( V_47 , V_177 , V_181 ) ;
F_23 ( V_15 , V_18 , & V_33 ) ;
F_158 ( V_47 , V_179 ,
( char * ) V_33 ) ;
break;
default:
F_161 () ;
}
F_162 ( V_47 , V_170 ) ;
}
F_162 ( V_47 , V_31 ) ;
return F_145 ( V_47 , V_152 ) ;
V_172:
F_163 ( V_47 , V_152 ) ;
return - V_169 ;
}
static int F_164 ( struct V_46 * V_47 ,
struct V_149 * V_150 , int V_89 ,
struct V_15 * V_15 )
{
return F_155 ( V_47 , V_150 -> V_154 ,
V_150 -> V_155 , V_162 ,
V_15 , true ) ;
}
static int F_165 ( struct V_46 * V_47 , struct V_149 * V_150 )
{
struct V_15 * V_15 ;
int V_23 ;
V_15 = F_149 ( V_150 ) ;
if ( ! V_15 )
return - V_41 ;
V_23 = F_153 ( V_150 , V_15 , F_164 ) ;
F_152 ( V_15 ) ;
return V_23 ;
}
static int F_166 ( struct V_46 * V_47 , struct V_149 * V_150 )
{
struct V_15 * V_15 ;
int V_23 = 0 ;
int V_21 ;
struct V_144 * V_182 ;
V_15 = F_149 ( V_150 ) ;
if ( ! V_15 )
return - V_41 ;
V_23 = - V_41 ;
if ( ! V_150 -> V_160 [ V_168 ] ) {
V_23 = - V_41 ;
goto V_183;
}
F_167 (nl_option, info->attrs[TEAM_ATTR_LIST_OPTION], i) {
struct V_144 * V_184 [ V_185 + 1 ] ;
enum V_186 V_187 ;
struct V_16 * V_18 ;
char * V_17 ;
bool V_188 = false ;
if ( F_168 ( V_182 ) != V_171 ) {
V_23 = - V_41 ;
goto V_183;
}
V_23 = F_169 ( V_184 , V_185 ,
V_182 , V_189 ) ;
if ( V_23 )
goto V_183;
if ( ! V_184 [ V_173 ] ||
! V_184 [ V_177 ] ||
! V_184 [ V_179 ] ) {
V_23 = - V_41 ;
goto V_183;
}
switch ( F_170 ( V_184 [ V_177 ] ) ) {
case V_178 :
V_187 = V_176 ;
break;
case V_181 :
V_187 = V_180 ;
break;
default:
goto V_183;
}
V_17 = F_139 ( V_184 [ V_173 ] ) ;
F_11 (option, &team->option_list, list) {
long V_33 ;
struct V_144 * V_190 ;
if ( V_18 -> type != V_187 ||
strcmp ( V_18 -> V_19 , V_17 ) )
continue;
V_188 = true ;
V_190 = V_184 [ V_179 ] ;
switch ( V_187 ) {
case V_176 :
V_33 = F_150 ( V_190 ) ;
break;
case V_180 :
V_33 = ( long ) F_139 ( V_190 ) ;
break;
default:
F_161 () ;
}
V_23 = F_24 ( V_15 , V_18 , & V_33 ) ;
if ( V_23 )
goto V_183;
}
if ( ! V_188 ) {
V_23 = - V_98 ;
goto V_183;
}
}
V_183:
F_152 ( V_15 ) ;
return V_23 ;
}
static int F_171 ( struct V_46 * V_47 ,
T_3 V_164 , T_3 V_165 , int V_89 ,
struct V_15 * V_15 ,
bool V_166 )
{
struct V_144 * V_49 ;
void * V_152 ;
struct V_1 * V_4 ;
V_152 = F_142 ( V_47 , V_164 , V_165 , & V_156 , V_89 ,
V_191 ) ;
if ( F_143 ( V_152 ) )
return F_144 ( V_152 ) ;
F_156 ( V_47 , V_161 , V_15 -> V_3 -> V_159 ) ;
V_49 = F_157 ( V_47 , V_192 ) ;
if ( ! V_49 )
return - V_169 ;
F_11 (port, &team->port_list, list) {
struct V_144 * V_193 ;
if ( ! V_166 && ! V_4 -> V_28 )
continue;
V_193 = F_157 ( V_47 , V_194 ) ;
if ( ! V_193 )
goto V_172;
F_156 ( V_47 , V_195 , V_4 -> V_3 -> V_159 ) ;
if ( V_4 -> V_28 ) {
F_159 ( V_47 , V_196 ) ;
V_4 -> V_28 = false ;
}
if ( V_4 -> V_29 )
F_159 ( V_47 , V_197 ) ;
if ( V_4 -> V_198 )
F_159 ( V_47 , V_199 ) ;
F_156 ( V_47 , V_200 , V_4 -> V_201 ) ;
F_160 ( V_47 , V_202 , V_4 -> V_203 ) ;
F_162 ( V_47 , V_193 ) ;
}
F_162 ( V_47 , V_49 ) ;
return F_145 ( V_47 , V_152 ) ;
V_172:
F_163 ( V_47 , V_152 ) ;
return - V_169 ;
}
static int F_172 ( struct V_46 * V_47 ,
struct V_149 * V_150 , int V_89 ,
struct V_15 * V_15 )
{
return F_171 ( V_47 , V_150 -> V_154 ,
V_150 -> V_155 , V_162 ,
V_15 , true ) ;
}
static int F_173 ( struct V_46 * V_47 ,
struct V_149 * V_150 )
{
struct V_15 * V_15 ;
int V_23 ;
V_15 = F_149 ( V_150 ) ;
if ( ! V_15 )
return - V_41 ;
V_23 = F_153 ( V_150 , V_15 , F_172 ) ;
F_152 ( V_15 ) ;
return V_23 ;
}
static int F_174 ( struct V_15 * V_15 )
{
struct V_46 * V_47 ;
int V_23 ;
struct V_142 * V_142 = F_175 ( V_15 -> V_3 ) ;
V_47 = F_141 ( V_153 , V_24 ) ;
if ( ! V_47 )
return - V_25 ;
V_23 = F_155 ( V_47 , 0 , 0 , 0 , V_15 , false ) ;
if ( V_23 < 0 )
goto V_163;
V_23 = F_176 ( V_142 , V_47 , 0 , V_204 . V_205 ,
V_24 ) ;
return V_23 ;
V_163:
F_148 ( V_47 ) ;
return V_23 ;
}
static int F_177 ( struct V_15 * V_15 )
{
struct V_46 * V_47 ;
int V_23 ;
struct V_142 * V_142 = F_175 ( V_15 -> V_3 ) ;
V_47 = F_141 ( V_153 , V_24 ) ;
if ( ! V_47 )
return - V_25 ;
V_23 = F_171 ( V_47 , 0 , 0 , 0 , V_15 , false ) ;
if ( V_23 < 0 )
goto V_163;
V_23 = F_176 ( V_142 , V_47 , 0 , V_204 . V_205 ,
V_24 ) ;
return V_23 ;
V_163:
F_148 ( V_47 ) ;
return V_23 ;
}
static int F_178 ( void )
{
int V_23 ;
V_23 = F_179 ( & V_156 , V_206 ,
F_96 ( V_206 ) ) ;
if ( V_23 )
return V_23 ;
V_23 = F_180 ( & V_156 , & V_204 ) ;
if ( V_23 )
goto V_207;
return 0 ;
V_207:
F_181 ( & V_156 ) ;
return V_23 ;
}
static void F_182 ( void )
{
F_181 ( & V_156 ) ;
}
static void F_21 ( struct V_15 * V_15 )
{
int V_23 ;
V_23 = F_174 ( V_15 ) ;
if ( V_23 )
F_183 ( V_15 -> V_3 , L_21 ) ;
}
static void F_81 ( struct V_1 * V_4 , bool V_198 )
{
int V_23 ;
if ( ! V_4 -> V_29 && V_4 -> V_198 == V_198 )
return;
V_4 -> V_28 = true ;
V_4 -> V_198 = V_198 ;
if ( V_198 ) {
struct V_208 V_209 ;
V_23 = F_184 ( V_4 -> V_3 , & V_209 ) ;
if ( ! V_23 ) {
V_4 -> V_201 = F_185 ( & V_209 ) ;
V_4 -> V_203 = V_209 . V_203 ;
goto V_210;
}
}
V_4 -> V_201 = 0 ;
V_4 -> V_203 = 0 ;
V_210:
V_23 = F_177 ( V_4 -> V_15 ) ;
if ( V_23 )
F_183 ( V_4 -> V_15 -> V_3 , L_22 ,
V_4 -> V_3 -> V_19 ) ;
}
static void F_186 ( struct V_1 * V_4 , bool V_198 )
{
struct V_15 * V_15 = V_4 -> V_15 ;
F_68 ( & V_15 -> V_82 ) ;
F_81 ( V_4 , V_198 ) ;
F_69 ( & V_15 -> V_82 ) ;
}
static int F_187 ( struct V_211 * V_212 ,
unsigned long V_213 , void * V_214 )
{
struct V_2 * V_3 = (struct V_2 * ) V_214 ;
struct V_1 * V_4 ;
V_4 = F_4 ( V_3 ) ;
if ( ! V_4 )
return V_215 ;
switch ( V_213 ) {
case V_216 :
if ( F_82 ( V_3 ) )
F_186 ( V_4 , true ) ;
case V_217 :
F_186 ( V_4 , false ) ;
case V_218 :
if ( F_188 ( V_4 -> V_3 ) )
F_186 ( V_4 ,
! ! F_82 ( V_4 -> V_3 ) ) ;
break;
case V_219 :
F_129 ( V_4 -> V_15 -> V_3 , V_3 ) ;
break;
case V_220 :
F_67 ( V_4 -> V_15 ) ;
break;
case V_221 :
return V_222 ;
case V_223 :
return V_222 ;
}
return V_215 ;
}
static int T_8 F_189 ( void )
{
int V_23 ;
F_190 ( & V_224 ) ;
V_23 = F_191 ( & V_225 ) ;
if ( V_23 )
goto V_226;
V_23 = F_178 () ;
if ( V_23 )
goto V_227;
return 0 ;
V_227:
F_192 ( & V_225 ) ;
V_226:
F_193 ( & V_224 ) ;
return V_23 ;
}
static void T_9 F_194 ( void )
{
F_182 () ;
F_192 ( & V_225 ) ;
F_193 ( & V_224 ) ;
}
