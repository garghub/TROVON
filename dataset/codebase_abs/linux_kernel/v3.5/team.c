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
static int F_13 ( struct V_15 * V_15 , struct V_20 * V_22 ,
struct V_1 * V_4 )
{
struct V_24 * V_25 ;
V_25 = F_14 ( sizeof( * V_25 ) , V_26 ) ;
if ( ! V_25 )
return - V_27 ;
V_25 -> V_22 = V_22 ;
V_25 -> V_4 = V_4 ;
V_25 -> V_28 = true ;
V_25 -> V_29 = false ;
F_15 ( & V_25 -> V_30 , & V_15 -> V_31 ) ;
return 0 ;
}
static void F_16 ( struct V_24 * V_25 )
{
F_17 ( & V_25 -> V_30 ) ;
F_18 ( V_25 ) ;
}
static void F_19 ( struct V_15 * V_15 ,
struct V_20 * V_22 )
{
struct V_24 * V_25 , * V_32 ;
F_20 (opt_inst, tmp, &team->option_inst_list, list) {
if ( V_25 -> V_22 == V_22 )
F_16 ( V_25 ) ;
}
}
static int F_21 ( struct V_15 * V_15 ,
struct V_20 * V_22 )
{
struct V_1 * V_4 ;
int V_33 ;
if ( ! V_22 -> V_34 )
return F_13 ( V_15 , V_22 , 0 ) ;
F_12 (port, &team->port_list, list) {
V_33 = F_13 ( V_15 , V_22 , V_4 ) ;
if ( V_33 )
goto V_35;
}
return 0 ;
V_35:
F_19 ( V_15 , V_22 ) ;
return V_33 ;
}
static void F_22 ( struct V_15 * V_15 ,
struct V_20 * V_22 )
{
struct V_24 * V_25 ;
F_12 (opt_inst, &team->option_inst_list, list) {
if ( V_25 -> V_22 == V_22 ) {
V_25 -> V_28 = true ;
V_25 -> V_29 = true ;
}
}
}
static void F_23 ( struct V_15 * V_15 ,
struct V_1 * V_4 )
{
struct V_24 * V_25 , * V_32 ;
F_20 (opt_inst, tmp, &team->option_inst_list, list) {
if ( V_25 -> V_22 -> V_34 &&
V_25 -> V_4 == V_4 )
F_16 ( V_25 ) ;
}
}
static int F_24 ( struct V_15 * V_15 ,
struct V_1 * V_4 )
{
struct V_20 * V_22 ;
int V_33 ;
F_12 (option, &team->option_list, list) {
if ( ! V_22 -> V_34 )
continue;
V_33 = F_13 ( V_15 , V_22 , V_4 ) ;
if ( V_33 )
goto V_36;
}
return 0 ;
V_36:
F_23 ( V_15 , V_4 ) ;
return V_33 ;
}
static void F_25 ( struct V_15 * V_15 ,
struct V_1 * V_4 )
{
struct V_24 * V_25 ;
F_12 (opt_inst, &team->option_inst_list, list) {
if ( V_25 -> V_4 == V_4 ) {
V_25 -> V_28 = true ;
V_25 -> V_29 = true ;
}
}
}
static int F_26 ( struct V_15 * V_15 ,
const struct V_20 * V_22 ,
T_1 V_37 )
{
int V_38 ;
struct V_20 * * V_39 ;
int V_33 ;
V_39 = F_27 ( sizeof( struct V_20 * ) * V_37 ,
V_26 ) ;
if ( ! V_39 )
return - V_27 ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ , V_22 ++ ) {
if ( F_11 ( V_15 , V_22 -> V_23 ) ) {
V_33 = - V_40 ;
goto V_41;
}
V_39 [ V_38 ] = F_28 ( V_22 , sizeof( * V_22 ) , V_26 ) ;
if ( ! V_39 [ V_38 ] ) {
V_33 = - V_27 ;
goto V_41;
}
}
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ ) {
V_33 = F_21 ( V_15 , V_39 [ V_38 ] ) ;
if ( V_33 )
goto V_42;
F_15 ( & V_39 [ V_38 ] -> V_30 , & V_15 -> V_43 ) ;
}
F_18 ( V_39 ) ;
return 0 ;
V_42:
for ( V_38 -- ; V_38 >= 0 ; V_38 -- )
F_19 ( V_15 , V_39 [ V_38 ] ) ;
V_38 = V_37 - 1 ;
V_41:
for ( V_38 -- ; V_38 >= 0 ; V_38 -- )
F_18 ( V_39 [ V_38 ] ) ;
F_18 ( V_39 ) ;
return V_33 ;
}
static void F_29 ( struct V_15 * V_15 ,
const struct V_20 * V_22 ,
T_1 V_37 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ , V_22 ++ ) {
struct V_20 * V_44 ;
V_44 = F_11 ( V_15 , V_22 -> V_23 ) ;
if ( V_44 )
F_22 ( V_15 , V_44 ) ;
}
}
static void F_30 ( struct V_15 * V_15 ,
const struct V_20 * V_22 ,
T_1 V_37 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ , V_22 ++ ) {
struct V_20 * V_44 ;
V_44 = F_11 ( V_15 , V_22 -> V_23 ) ;
if ( V_44 ) {
F_19 ( V_15 , V_44 ) ;
F_17 ( & V_44 -> V_30 ) ;
F_18 ( V_44 ) ;
}
}
}
int F_31 ( struct V_15 * V_15 ,
const struct V_20 * V_22 ,
T_1 V_37 )
{
int V_33 ;
V_33 = F_26 ( V_15 , V_22 , V_37 ) ;
if ( V_33 )
return V_33 ;
F_32 ( V_15 ) ;
return 0 ;
}
void F_33 ( struct V_15 * V_15 ,
const struct V_20 * V_22 ,
T_1 V_37 )
{
F_29 ( V_15 , V_22 , V_37 ) ;
F_32 ( V_15 ) ;
F_30 ( V_15 , V_22 , V_37 ) ;
}
static int F_34 ( struct V_15 * V_15 , struct V_1 * V_4 )
{
int V_33 ;
V_33 = F_24 ( V_15 , V_4 ) ;
if ( V_33 )
return V_33 ;
F_32 ( V_15 ) ;
return 0 ;
}
static void F_35 ( struct V_15 * V_15 , struct V_1 * V_4 )
{
F_25 ( V_15 , V_4 ) ;
F_32 ( V_15 ) ;
F_23 ( V_15 , V_4 ) ;
}
static int F_36 ( struct V_15 * V_15 ,
struct V_24 * V_25 ,
struct V_45 * V_46 )
{
return V_25 -> V_22 -> V_47 ( V_15 , V_46 ) ;
}
static int F_37 ( struct V_15 * V_15 ,
struct V_24 * V_25 ,
struct V_45 * V_46 )
{
int V_33 ;
V_33 = V_25 -> V_22 -> V_48 ( V_15 , V_46 ) ;
if ( V_33 )
return V_33 ;
V_25 -> V_28 = true ;
F_32 ( V_15 ) ;
return V_33 ;
}
static struct V_49 * F_38 ( const char * V_50 )
{
struct V_49 * V_51 ;
F_12 (mode, &mode_list, list) {
if ( strcmp ( V_51 -> V_50 , V_50 ) == 0 )
return V_51 ;
}
return NULL ;
}
static bool F_39 ( const char * V_23 )
{
while ( * V_23 != '\0' ) {
if ( ! isalpha ( * V_23 ) && ! isdigit ( * V_23 ) && * V_23 != '_' )
return false ;
V_23 ++ ;
}
return true ;
}
int F_40 ( struct V_49 * V_51 )
{
int V_33 = 0 ;
if ( ! F_39 ( V_51 -> V_50 ) ||
V_51 -> V_52 > V_53 )
return - V_54 ;
F_41 ( & V_55 ) ;
if ( F_38 ( V_51 -> V_50 ) ) {
V_33 = - V_40 ;
goto V_56;
}
F_15 ( & V_51 -> V_30 , & V_57 ) ;
V_56:
F_42 ( & V_55 ) ;
return V_33 ;
}
int F_43 ( struct V_49 * V_51 )
{
F_41 ( & V_55 ) ;
F_44 ( & V_51 -> V_30 ) ;
F_42 ( & V_55 ) ;
return 0 ;
}
static struct V_49 * F_45 ( const char * V_50 )
{
struct V_49 * V_51 ;
F_41 ( & V_55 ) ;
V_51 = F_38 ( V_50 ) ;
if ( ! V_51 ) {
F_42 ( & V_55 ) ;
F_46 ( L_1 , V_50 ) ;
F_41 ( & V_55 ) ;
V_51 = F_38 ( V_50 ) ;
}
if ( V_51 )
if ( ! F_47 ( V_51 -> V_58 ) )
V_51 = NULL ;
F_42 ( & V_55 ) ;
return V_51 ;
}
static void F_48 ( const struct V_49 * V_51 )
{
F_49 ( V_51 -> V_58 ) ;
}
static bool F_50 ( struct V_15 * V_15 , struct V_59 * V_60 )
{
F_51 ( V_60 ) ;
return false ;
}
T_2 F_52 ( struct V_15 * V_15 ,
struct V_1 * V_4 ,
struct V_59 * V_60 )
{
return V_61 ;
}
static void F_53 ( struct V_15 * V_15 )
{
if ( F_54 ( & V_15 -> V_62 ) ||
! V_15 -> V_51 || ! V_15 -> V_51 -> V_63 -> V_64 )
V_15 -> V_63 . V_64 = F_50 ;
else
V_15 -> V_63 . V_64 = V_15 -> V_51 -> V_63 -> V_64 ;
if ( F_54 ( & V_15 -> V_62 ) ||
! V_15 -> V_51 || ! V_15 -> V_51 -> V_63 -> V_65 )
V_15 -> V_63 . V_65 = F_52 ;
else
V_15 -> V_63 . V_65 = V_15 -> V_51 -> V_63 -> V_65 ;
}
static int F_55 ( struct V_15 * V_15 ,
const struct V_49 * V_66 )
{
if ( V_15 -> V_51 ) {
void (* F_56)( struct V_15 * V_15 ) = V_15 -> V_63 . exit ;
memset ( & V_15 -> V_63 , 0 , sizeof( struct V_67 ) ) ;
F_53 ( V_15 ) ;
if ( F_56 )
F_56 ( V_15 ) ;
F_48 ( V_15 -> V_51 ) ;
V_15 -> V_51 = NULL ;
memset ( & V_15 -> V_68 , 0 ,
sizeof( struct V_15 ) - F_57 ( struct V_15 , V_68 ) ) ;
}
if ( ! V_66 )
return 0 ;
if ( V_66 -> V_63 -> V_69 ) {
int V_33 ;
V_33 = V_66 -> V_63 -> V_69 ( V_15 ) ;
if ( V_33 )
return V_33 ;
}
V_15 -> V_51 = V_66 ;
memcpy ( & V_15 -> V_63 , V_66 -> V_63 , sizeof( struct V_67 ) ) ;
F_53 ( V_15 ) ;
return 0 ;
}
static int F_58 ( struct V_15 * V_15 , const char * V_50 )
{
struct V_49 * V_66 ;
struct V_2 * V_3 = V_15 -> V_3 ;
int V_33 ;
if ( ! F_54 ( & V_15 -> V_62 ) ) {
F_59 ( V_3 , L_2 ) ;
return - V_70 ;
}
if ( V_15 -> V_51 && strcmp ( V_15 -> V_51 -> V_50 , V_50 ) == 0 ) {
F_59 ( V_3 , L_3 ) ;
return - V_54 ;
}
V_66 = F_45 ( V_50 ) ;
if ( ! V_66 ) {
F_59 ( V_3 , L_4 , V_50 ) ;
return - V_54 ;
}
V_33 = F_55 ( V_15 , V_66 ) ;
if ( V_33 ) {
F_59 ( V_3 , L_5 , V_50 ) ;
F_48 ( V_66 ) ;
return V_33 ;
}
F_60 ( V_3 , L_6 , V_50 ) ;
return 0 ;
}
static T_2 F_61 ( struct V_59 * * V_71 )
{
struct V_59 * V_60 = * V_71 ;
struct V_1 * V_4 ;
struct V_15 * V_15 ;
T_2 V_72 ;
V_60 = F_62 ( V_60 , V_73 ) ;
if ( ! V_60 )
return V_74 ;
* V_71 = V_60 ;
V_4 = F_1 ( V_60 -> V_3 ) ;
V_15 = V_4 -> V_15 ;
if ( ! F_63 ( V_4 ) ) {
V_72 = V_75 ;
} else {
V_72 = V_15 -> V_63 . V_65 ( V_15 , V_4 , V_60 ) ;
}
if ( V_72 == V_61 ) {
struct V_76 * V_77 ;
V_77 = F_64 ( V_15 -> V_77 ) ;
F_65 ( & V_77 -> V_78 ) ;
V_77 -> V_79 ++ ;
V_77 -> V_80 += V_60 -> V_81 ;
if ( V_60 -> V_82 == V_83 )
V_77 -> V_84 ++ ;
F_66 ( & V_77 -> V_78 ) ;
V_60 -> V_3 = V_15 -> V_3 ;
} else {
F_67 ( V_15 -> V_77 -> V_85 ) ;
}
return V_72 ;
}
static bool F_68 ( const struct V_15 * V_15 ,
const struct V_1 * V_4 )
{
struct V_1 * V_86 ;
F_12 (cur, &team->port_list, list)
if ( V_86 == V_4 )
return true ;
return false ;
}
static bool F_63 ( struct V_1 * V_4 )
{
return V_4 -> V_87 != - 1 ;
}
static void F_69 ( struct V_15 * V_15 ,
struct V_1 * V_4 )
{
if ( F_63 ( V_4 ) )
return;
V_4 -> V_87 = V_15 -> V_88 ++ ;
F_70 ( & V_4 -> V_89 ,
F_71 ( V_15 , V_4 -> V_87 ) ) ;
}
static void F_72 ( struct V_15 * V_15 , int V_90 )
{
int V_38 ;
struct V_1 * V_4 ;
for ( V_38 = V_90 + 1 ; V_38 < V_15 -> V_88 ; V_38 ++ ) {
V_4 = F_73 ( V_15 , V_38 ) ;
F_74 ( & V_4 -> V_89 ) ;
V_4 -> V_87 -- ;
F_70 ( & V_4 -> V_89 ,
F_71 ( V_15 , V_4 -> V_87 ) ) ;
}
}
static void F_75 ( struct V_15 * V_15 ,
struct V_1 * V_4 )
{
int V_90 = V_4 -> V_87 ;
if ( ! F_63 ( V_4 ) )
return;
F_74 ( & V_4 -> V_89 ) ;
F_72 ( V_15 , V_90 ) ;
V_15 -> V_88 -- ;
V_4 -> V_87 = - 1 ;
}
static void F_76 ( struct V_15 * V_15 )
{
struct V_1 * V_4 ;
T_3 V_91 = V_92 ;
unsigned short V_93 = V_94 ;
F_12 (port, &team->port_list, list) {
V_91 = F_77 ( V_91 ,
V_4 -> V_3 -> V_91 ,
V_92 ) ;
if ( V_4 -> V_3 -> V_95 > V_93 )
V_93 = V_4 -> V_3 -> V_95 ;
}
V_15 -> V_3 -> V_91 = V_91 ;
V_15 -> V_3 -> V_95 = V_93 ;
F_78 ( V_15 -> V_3 ) ;
}
static void F_79 ( struct V_15 * V_15 )
{
F_80 ( & V_15 -> V_96 ) ;
F_76 ( V_15 ) ;
F_81 ( & V_15 -> V_96 ) ;
}
static int F_82 ( struct V_15 * V_15 , struct V_1 * V_4 )
{
int V_33 = 0 ;
F_83 ( V_15 -> V_3 ) ;
V_4 -> V_3 -> V_97 |= V_98 ;
if ( V_15 -> V_63 . V_99 ) {
V_33 = V_15 -> V_63 . V_99 ( V_15 , V_4 ) ;
if ( V_33 ) {
F_59 ( V_15 -> V_3 , L_7 ,
V_4 -> V_3 -> V_23 ) ;
goto V_100;
}
}
return 0 ;
V_100:
V_4 -> V_3 -> V_97 &= ~ V_98 ;
F_84 ( V_15 -> V_3 ) ;
return V_33 ;
}
static void F_85 ( struct V_15 * V_15 , struct V_1 * V_4 )
{
if ( V_15 -> V_63 . V_101 )
V_15 -> V_63 . V_101 ( V_15 , V_4 ) ;
V_4 -> V_3 -> V_97 &= ~ V_98 ;
F_84 ( V_15 -> V_3 ) ;
}
static int F_86 ( struct V_15 * V_15 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_1 * V_4 ;
char * V_102 = V_6 -> V_23 ;
int V_33 ;
if ( V_6 -> V_103 & V_104 ||
V_6 -> type != V_13 ) {
F_59 ( V_3 , L_8 ,
V_102 ) ;
return - V_54 ;
}
if ( F_3 ( V_6 ) ) {
F_59 ( V_3 , L_9
L_10 , V_102 ) ;
return - V_70 ;
}
if ( V_6 -> V_103 & V_105 ) {
F_59 ( V_3 , L_11 ,
V_102 ) ;
return - V_70 ;
}
V_4 = F_27 ( sizeof( struct V_1 ) , V_26 ) ;
if ( ! V_4 )
return - V_27 ;
V_4 -> V_3 = V_6 ;
V_4 -> V_15 = V_15 ;
V_4 -> V_14 . V_106 = V_6 -> V_106 ;
V_33 = F_87 ( V_6 , V_3 -> V_106 ) ;
if ( V_33 ) {
F_88 ( V_3 , L_12 , V_33 ) ;
goto V_107;
}
memcpy ( V_4 -> V_14 . V_7 , V_6 -> V_7 , V_11 ) ;
V_33 = F_82 ( V_15 , V_4 ) ;
if ( V_33 ) {
F_59 ( V_3 , L_7 ,
V_102 ) ;
goto V_100;
}
V_33 = F_89 ( V_6 ) ;
if ( V_33 ) {
F_88 ( V_3 , L_13 ,
V_102 ) ;
goto V_108;
}
V_33 = F_90 ( V_6 , V_3 ) ;
if ( V_33 ) {
F_59 ( V_3 , L_14 ,
V_102 ) ;
goto V_109;
}
V_33 = F_91 ( V_6 , V_3 ) ;
if ( V_33 ) {
F_59 ( V_3 , L_15 , V_102 ) ;
goto V_110;
}
V_33 = F_92 ( V_6 , F_61 ,
V_4 ) ;
if ( V_33 ) {
F_59 ( V_3 , L_16 ,
V_102 ) ;
goto V_111;
}
V_33 = F_34 ( V_15 , V_4 ) ;
if ( V_33 ) {
F_59 ( V_3 , L_17 ,
V_102 ) ;
goto V_112;
}
V_4 -> V_87 = - 1 ;
F_69 ( V_15 , V_4 ) ;
F_93 ( & V_4 -> V_30 , & V_15 -> V_62 ) ;
F_53 ( V_15 ) ;
F_76 ( V_15 ) ;
F_94 ( V_4 , ! ! F_95 ( V_6 ) ) ;
F_60 ( V_3 , L_18 , V_102 ) ;
return 0 ;
V_112:
F_96 ( V_6 ) ;
V_111:
F_91 ( V_6 , NULL ) ;
V_110:
F_97 ( V_6 , V_3 ) ;
V_109:
F_98 ( V_6 ) ;
V_108:
F_85 ( V_15 , V_4 ) ;
F_8 ( V_4 ) ;
V_100:
F_87 ( V_6 , V_4 -> V_14 . V_106 ) ;
V_107:
F_18 ( V_4 ) ;
return V_33 ;
}
static int F_99 ( struct V_15 * V_15 , struct V_2 * V_6 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_1 * V_4 ;
char * V_102 = V_6 -> V_23 ;
V_4 = F_4 ( V_6 ) ;
if ( ! V_4 || ! F_68 ( V_15 , V_4 ) ) {
F_59 ( V_3 , L_19 ,
V_102 ) ;
return - V_113 ;
}
V_4 -> V_29 = true ;
F_94 ( V_4 , false ) ;
F_75 ( V_15 , V_4 ) ;
F_100 ( & V_4 -> V_30 ) ;
F_53 ( V_15 ) ;
F_35 ( V_15 , V_4 ) ;
F_96 ( V_6 ) ;
F_91 ( V_6 , NULL ) ;
F_97 ( V_6 , V_3 ) ;
F_98 ( V_6 ) ;
F_85 ( V_15 , V_4 ) ;
F_8 ( V_4 ) ;
F_87 ( V_6 , V_4 -> V_14 . V_106 ) ;
F_101 () ;
F_18 ( V_4 ) ;
F_60 ( V_3 , L_20 , V_102 ) ;
F_76 ( V_15 ) ;
return 0 ;
}
static int F_102 ( struct V_15 * V_15 , struct V_45 * V_46 )
{
V_46 -> V_114 . V_115 = V_15 -> V_51 ? V_15 -> V_51 -> V_50 : V_116 ;
return 0 ;
}
static int F_103 ( struct V_15 * V_15 , struct V_45 * V_46 )
{
return F_58 ( V_15 , V_46 -> V_114 . V_115 ) ;
}
static int F_104 ( struct V_15 * V_15 ,
struct V_45 * V_46 )
{
V_46 -> V_114 . V_117 = F_63 ( V_46 -> V_4 ) ;
return 0 ;
}
static int F_105 ( struct V_15 * V_15 ,
struct V_45 * V_46 )
{
if ( V_46 -> V_114 . V_117 )
F_69 ( V_15 , V_46 -> V_4 ) ;
else
F_75 ( V_15 , V_46 -> V_4 ) ;
return 0 ;
}
static int F_106 ( struct V_15 * V_15 ,
struct V_45 * V_46 )
{
V_46 -> V_114 . V_117 = V_46 -> V_4 -> V_17 . V_16 ;
return 0 ;
}
static int F_107 ( struct V_15 * V_15 ,
struct V_45 * V_46 )
{
V_46 -> V_4 -> V_17 . V_16 = V_46 -> V_114 . V_117 ;
F_10 ( V_46 -> V_4 ) ;
return 0 ;
}
static int F_108 ( struct V_15 * V_15 ,
struct V_45 * V_46 )
{
struct V_1 * V_4 = V_46 -> V_4 ;
V_46 -> V_114 . V_117 = V_4 -> V_17 . V_18 ;
return 0 ;
}
static int F_109 ( struct V_15 * V_15 ,
struct V_45 * V_46 )
{
struct V_1 * V_4 = V_46 -> V_4 ;
V_4 -> V_17 . V_18 = V_46 -> V_114 . V_117 ;
F_10 ( V_46 -> V_4 ) ;
return 0 ;
}
static int F_110 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_111 ( V_3 ) ;
int V_38 ;
int V_33 ;
V_15 -> V_3 = V_3 ;
F_112 ( & V_15 -> V_96 ) ;
V_15 -> V_77 = F_113 ( struct V_76 ) ;
if ( ! V_15 -> V_77 )
return - V_27 ;
for ( V_38 = 0 ; V_38 < V_118 ; V_38 ++ )
F_114 ( & V_15 -> V_119 [ V_38 ] ) ;
F_115 ( & V_15 -> V_62 ) ;
F_53 ( V_15 ) ;
F_115 ( & V_15 -> V_43 ) ;
F_115 ( & V_15 -> V_31 ) ;
V_33 = F_31 ( V_15 , V_120 , F_116 ( V_120 ) ) ;
if ( V_33 )
goto V_121;
F_117 ( V_3 ) ;
return 0 ;
V_121:
F_118 ( V_15 -> V_77 ) ;
return V_33 ;
}
static void F_119 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_111 ( V_3 ) ;
struct V_1 * V_4 ;
struct V_1 * V_32 ;
F_80 ( & V_15 -> V_96 ) ;
F_20 (port, tmp, &team->port_list, list)
F_99 ( V_15 , V_4 -> V_3 ) ;
F_55 ( V_15 , NULL ) ;
F_30 ( V_15 , V_120 , F_116 ( V_120 ) ) ;
F_81 ( & V_15 -> V_96 ) ;
}
static void F_120 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_111 ( V_3 ) ;
F_118 ( V_15 -> V_77 ) ;
F_121 ( V_3 ) ;
}
static int F_122 ( struct V_2 * V_3 )
{
F_123 ( V_3 ) ;
return 0 ;
}
static int F_124 ( struct V_2 * V_3 )
{
F_117 ( V_3 ) ;
return 0 ;
}
static T_4 F_125 ( struct V_59 * V_60 , struct V_2 * V_3 )
{
struct V_15 * V_15 = F_111 ( V_3 ) ;
bool V_122 = false ;
unsigned int V_81 = V_60 -> V_81 ;
V_122 = V_15 -> V_63 . V_64 ( V_15 , V_60 ) ;
if ( V_122 ) {
struct V_76 * V_77 ;
V_77 = F_64 ( V_15 -> V_77 ) ;
F_65 ( & V_77 -> V_78 ) ;
V_77 -> V_123 ++ ;
V_77 -> V_124 += V_81 ;
F_66 ( & V_77 -> V_78 ) ;
} else {
F_67 ( V_15 -> V_77 -> V_125 ) ;
}
return V_126 ;
}
static void F_126 ( struct V_2 * V_3 , int V_127 )
{
struct V_15 * V_15 = F_111 ( V_3 ) ;
struct V_1 * V_4 ;
int V_128 ;
F_127 () ;
F_128 (port, &team->port_list, list) {
if ( V_127 & V_129 ) {
V_128 = V_3 -> V_103 & V_129 ? 1 : - 1 ;
F_129 ( V_4 -> V_3 , V_128 ) ;
}
if ( V_127 & V_130 ) {
V_128 = V_3 -> V_103 & V_130 ? 1 : - 1 ;
F_130 ( V_4 -> V_3 , V_128 ) ;
}
}
F_131 () ;
}
static void F_132 ( struct V_2 * V_3 )
{
struct V_15 * V_15 = F_111 ( V_3 ) ;
struct V_1 * V_4 ;
F_127 () ;
F_128 (port, &team->port_list, list) {
F_133 ( V_4 -> V_3 , V_3 ) ;
F_134 ( V_4 -> V_3 , V_3 ) ;
}
F_131 () ;
}
static int F_135 ( struct V_2 * V_3 , void * V_131 )
{
struct V_15 * V_15 = F_111 ( V_3 ) ;
struct V_1 * V_4 ;
struct V_8 * V_9 = V_131 ;
V_3 -> V_132 &= ~ V_133 ;
memcpy ( V_3 -> V_7 , V_9 -> V_10 , V_11 ) ;
F_127 () ;
F_128 (port, &team->port_list, list)
if ( V_15 -> V_63 . V_134 )
V_15 -> V_63 . V_134 ( V_15 , V_4 ) ;
F_131 () ;
return 0 ;
}
static int F_136 ( struct V_2 * V_3 , int V_135 )
{
struct V_15 * V_15 = F_111 ( V_3 ) ;
struct V_1 * V_4 ;
int V_33 ;
F_80 ( & V_15 -> V_96 ) ;
F_12 (port, &team->port_list, list) {
V_33 = F_87 ( V_4 -> V_3 , V_135 ) ;
if ( V_33 ) {
F_59 ( V_3 , L_21 ,
V_4 -> V_3 -> V_23 ) ;
goto V_136;
}
}
F_81 ( & V_15 -> V_96 ) ;
V_3 -> V_106 = V_135 ;
return 0 ;
V_136:
F_137 (port, &team->port_list, list)
F_87 ( V_4 -> V_3 , V_3 -> V_106 ) ;
F_81 ( & V_15 -> V_96 ) ;
return V_33 ;
}
static struct V_137 *
F_138 ( struct V_2 * V_3 , struct V_137 * V_138 )
{
struct V_15 * V_15 = F_111 ( V_3 ) ;
struct V_76 * V_131 ;
T_5 V_79 , V_80 , V_84 , V_123 , V_124 ;
T_3 V_85 = 0 , V_125 = 0 ;
unsigned int V_139 ;
int V_38 ;
F_139 (i) {
V_131 = F_140 ( V_15 -> V_77 , V_38 ) ;
do {
V_139 = F_141 ( & V_131 -> V_78 ) ;
V_79 = V_131 -> V_79 ;
V_80 = V_131 -> V_80 ;
V_84 = V_131 -> V_84 ;
V_123 = V_131 -> V_123 ;
V_124 = V_131 -> V_124 ;
} while ( F_142 ( & V_131 -> V_78 , V_139 ) );
V_138 -> V_79 += V_79 ;
V_138 -> V_80 += V_80 ;
V_138 -> V_140 += V_84 ;
V_138 -> V_123 += V_123 ;
V_138 -> V_124 += V_124 ;
V_85 += V_131 -> V_85 ;
V_125 += V_131 -> V_125 ;
}
V_138 -> V_85 = V_85 ;
V_138 -> V_125 = V_125 ;
return V_138 ;
}
static int F_143 ( struct V_2 * V_3 , T_6 V_141 )
{
struct V_15 * V_15 = F_111 ( V_3 ) ;
struct V_1 * V_4 ;
int V_33 ;
F_80 ( & V_15 -> V_96 ) ;
F_12 (port, &team->port_list, list) {
V_33 = F_144 ( V_4 -> V_3 , V_141 ) ;
if ( V_33 )
goto V_136;
}
F_81 ( & V_15 -> V_96 ) ;
return 0 ;
V_136:
F_137 (port, &team->port_list, list)
F_145 ( V_4 -> V_3 , V_141 ) ;
F_81 ( & V_15 -> V_96 ) ;
return V_33 ;
}
static int F_146 ( struct V_2 * V_3 , T_6 V_141 )
{
struct V_15 * V_15 = F_111 ( V_3 ) ;
struct V_1 * V_4 ;
F_127 () ;
F_128 (port, &team->port_list, list)
F_145 ( V_4 -> V_3 , V_141 ) ;
F_131 () ;
return 0 ;
}
static int F_147 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_15 * V_15 = F_111 ( V_3 ) ;
int V_33 ;
F_80 ( & V_15 -> V_96 ) ;
V_33 = F_86 ( V_15 , V_6 ) ;
F_81 ( & V_15 -> V_96 ) ;
return V_33 ;
}
static int F_148 ( struct V_2 * V_3 , struct V_2 * V_6 )
{
struct V_15 * V_15 = F_111 ( V_3 ) ;
int V_33 ;
F_80 ( & V_15 -> V_96 ) ;
V_33 = F_99 ( V_15 , V_6 ) ;
F_81 ( & V_15 -> V_96 ) ;
return V_33 ;
}
static T_7 F_149 ( struct V_2 * V_3 ,
T_7 V_142 )
{
struct V_1 * V_4 ;
struct V_15 * V_15 = F_111 ( V_3 ) ;
T_7 V_143 ;
V_143 = V_142 ;
V_142 &= ~ V_144 ;
V_142 |= V_145 ;
F_127 () ;
F_128 (port, &team->port_list, list) {
V_142 = F_77 ( V_142 ,
V_4 -> V_3 -> V_142 ,
V_143 ) ;
}
F_131 () ;
return V_142 ;
}
static void F_150 ( struct V_2 * V_3 )
{
F_151 ( V_3 ) ;
V_3 -> V_146 = & V_147 ;
V_3 -> V_148 = F_120 ;
V_3 -> V_149 = 0 ;
V_3 -> V_103 |= V_150 ;
V_3 -> V_97 &= ~ ( V_151 | V_152 ) ;
V_3 -> V_97 |= V_153 ;
V_3 -> V_142 |= V_154 ;
V_3 -> V_142 |= V_155 ;
V_3 -> V_156 = V_157 |
V_158 |
V_159 ;
V_3 -> V_142 |= V_3 -> V_156 ;
}
static int F_152 ( struct V_160 * V_161 , struct V_2 * V_3 ,
struct V_162 * V_163 [] , struct V_162 * V_114 [] )
{
int V_33 ;
if ( V_163 [ V_164 ] == NULL )
F_153 ( V_3 ) ;
V_33 = F_154 ( V_3 ) ;
if ( V_33 )
return V_33 ;
return 0 ;
}
static int F_155 ( struct V_162 * V_163 [] , struct V_162 * V_114 [] )
{
if ( V_163 [ V_164 ] ) {
if ( F_156 ( V_163 [ V_164 ] ) != V_11 )
return - V_54 ;
if ( ! F_157 ( F_158 ( V_163 [ V_164 ] ) ) )
return - V_165 ;
}
return 0 ;
}
static int F_159 ( struct V_59 * V_60 , struct V_166 * V_167 )
{
struct V_59 * V_168 ;
void * V_169 ;
int V_33 ;
V_168 = F_160 ( V_170 , V_26 ) ;
if ( ! V_168 )
return - V_27 ;
V_169 = F_161 ( V_168 , V_167 -> V_171 , V_167 -> V_172 ,
& V_173 , 0 , V_174 ) ;
if ( F_162 ( V_169 ) ) {
V_33 = F_163 ( V_169 ) ;
goto V_175;
}
F_164 ( V_168 , V_169 ) ;
return F_165 ( F_166 ( V_167 ) , V_168 , V_167 -> V_171 ) ;
V_175:
F_167 ( V_168 ) ;
return V_33 ;
}
static struct V_15 * F_168 ( struct V_166 * V_167 )
{
struct V_160 * V_160 = F_166 ( V_167 ) ;
int V_176 ;
struct V_2 * V_3 ;
struct V_15 * V_15 ;
if ( ! V_167 -> V_177 [ V_178 ] )
return NULL ;
V_176 = F_169 ( V_167 -> V_177 [ V_178 ] ) ;
V_3 = F_170 ( V_160 , V_176 ) ;
if ( ! V_3 || V_3 -> V_146 != & V_147 ) {
if ( V_3 )
F_84 ( V_3 ) ;
return NULL ;
}
V_15 = F_111 ( V_3 ) ;
F_80 ( & V_15 -> V_96 ) ;
return V_15 ;
}
static void F_171 ( struct V_15 * V_15 )
{
F_81 ( & V_15 -> V_96 ) ;
F_84 ( V_15 -> V_3 ) ;
}
static int F_172 ( struct V_166 * V_167 , struct V_15 * V_15 ,
int (* F_173)( struct V_59 * V_60 ,
struct V_166 * V_167 ,
int V_103 , struct V_15 * V_15 ) )
{
struct V_59 * V_60 ;
int V_33 ;
V_60 = F_160 ( V_170 , V_26 ) ;
if ( ! V_60 )
return - V_27 ;
V_33 = F_173 ( V_60 , V_167 , V_179 , V_15 ) ;
if ( V_33 < 0 )
goto V_180;
V_33 = F_165 ( F_166 ( V_167 ) , V_60 , V_167 -> V_171 ) ;
return V_33 ;
V_180:
F_167 ( V_60 ) ;
return V_33 ;
}
static int F_174 ( struct V_59 * V_60 ,
T_3 V_181 , T_3 V_182 , int V_103 ,
struct V_15 * V_15 , bool V_183 )
{
struct V_162 * V_43 ;
void * V_169 ;
struct V_24 * V_25 ;
int V_33 ;
V_169 = F_161 ( V_60 , V_181 , V_182 , & V_173 , V_103 ,
V_184 ) ;
if ( F_162 ( V_169 ) )
return F_163 ( V_169 ) ;
if ( F_175 ( V_60 , V_178 , V_15 -> V_3 -> V_176 ) )
goto V_185;
V_43 = F_176 ( V_60 , V_186 ) ;
if ( ! V_43 )
return - V_187 ;
F_12 (opt_inst, &team->option_inst_list, list) {
struct V_162 * V_188 ;
struct V_20 * V_22 = V_25 -> V_22 ;
struct V_45 V_46 ;
if ( ! V_183 && ! V_25 -> V_28 )
continue;
V_188 = F_176 ( V_60 , V_189 ) ;
if ( ! V_188 )
goto V_185;
if ( F_177 ( V_60 , V_190 , V_22 -> V_23 ) )
goto V_185;
if ( V_25 -> V_28 ) {
if ( F_178 ( V_60 , V_191 ) )
goto V_185;
V_25 -> V_28 = false ;
}
if ( V_25 -> V_29 &&
F_178 ( V_60 , V_192 ) )
goto V_185;
if ( V_25 -> V_4 &&
F_175 ( V_60 , V_193 ,
V_25 -> V_4 -> V_3 -> V_176 ) )
goto V_185;
V_46 . V_4 = V_25 -> V_4 ;
switch ( V_22 -> type ) {
case V_194 :
if ( F_179 ( V_60 , V_195 , V_196 ) )
goto V_185;
V_33 = F_36 ( V_15 , V_25 , & V_46 ) ;
if ( V_33 )
goto V_197;
if ( F_175 ( V_60 , V_198 ,
V_46 . V_114 . V_199 ) )
goto V_185;
break;
case V_200 :
if ( F_179 ( V_60 , V_195 , V_201 ) )
goto V_185;
V_33 = F_36 ( V_15 , V_25 , & V_46 ) ;
if ( V_33 )
goto V_197;
if ( F_177 ( V_60 , V_198 ,
V_46 . V_114 . V_115 ) )
goto V_185;
break;
case V_202 :
if ( F_179 ( V_60 , V_195 , V_203 ) )
goto V_185;
V_33 = F_36 ( V_15 , V_25 , & V_46 ) ;
if ( V_33 )
goto V_197;
if ( F_180 ( V_60 , V_198 ,
V_46 . V_114 . V_204 . V_81 , V_46 . V_114 . V_204 . V_205 ) )
goto V_185;
break;
case V_206 :
if ( F_179 ( V_60 , V_195 , V_207 ) )
goto V_185;
V_33 = F_36 ( V_15 , V_25 , & V_46 ) ;
if ( V_33 )
goto V_197;
if ( V_46 . V_114 . V_117 &&
F_178 ( V_60 , V_198 ) )
goto V_185;
break;
default:
F_181 () ;
}
F_182 ( V_60 , V_188 ) ;
}
F_182 ( V_60 , V_43 ) ;
return F_164 ( V_60 , V_169 ) ;
V_185:
V_33 = - V_187 ;
V_197:
F_183 ( V_60 , V_169 ) ;
return V_33 ;
}
static int F_184 ( struct V_59 * V_60 ,
struct V_166 * V_167 , int V_103 ,
struct V_15 * V_15 )
{
return F_174 ( V_60 , V_167 -> V_171 ,
V_167 -> V_172 , V_179 ,
V_15 , true ) ;
}
static int F_185 ( struct V_59 * V_60 , struct V_166 * V_167 )
{
struct V_15 * V_15 ;
int V_33 ;
V_15 = F_168 ( V_167 ) ;
if ( ! V_15 )
return - V_54 ;
V_33 = F_172 ( V_167 , V_15 , F_184 ) ;
F_171 ( V_15 ) ;
return V_33 ;
}
static int F_186 ( struct V_59 * V_60 , struct V_166 * V_167 )
{
struct V_15 * V_15 ;
int V_33 = 0 ;
int V_38 ;
struct V_162 * V_208 ;
V_15 = F_168 ( V_167 ) ;
if ( ! V_15 )
return - V_54 ;
V_33 = - V_54 ;
if ( ! V_167 -> V_177 [ V_186 ] ) {
V_33 = - V_54 ;
goto V_209;
}
F_187 (nl_option, info->attrs[TEAM_ATTR_LIST_OPTION], i) {
struct V_162 * V_210 [ V_211 + 1 ] ;
struct V_162 * V_212 ;
struct V_162 * V_213 ;
enum V_214 V_215 ;
int V_216 = 0 ;
struct V_24 * V_25 ;
char * V_21 ;
bool V_217 = false ;
if ( F_188 ( V_208 ) != V_189 ) {
V_33 = - V_54 ;
goto V_209;
}
V_33 = F_189 ( V_210 , V_211 ,
V_208 , V_218 ) ;
if ( V_33 )
goto V_209;
if ( ! V_210 [ V_190 ] ||
! V_210 [ V_195 ] ) {
V_33 = - V_54 ;
goto V_209;
}
switch ( F_190 ( V_210 [ V_195 ] ) ) {
case V_196 :
V_215 = V_194 ;
break;
case V_201 :
V_215 = V_200 ;
break;
case V_203 :
V_215 = V_202 ;
break;
case V_207 :
V_215 = V_206 ;
break;
default:
goto V_209;
}
V_213 = V_210 [ V_198 ] ;
if ( V_215 != V_206 && ! V_213 ) {
V_33 = - V_54 ;
goto V_209;
}
V_21 = F_158 ( V_210 [ V_190 ] ) ;
V_212 = V_210 [ V_193 ] ;
if ( V_212 )
V_216 = F_169 ( V_212 ) ;
F_12 (opt_inst, &team->option_inst_list, list) {
struct V_20 * V_22 = V_25 -> V_22 ;
struct V_45 V_46 ;
int V_219 ;
V_219 = V_25 -> V_4 ?
V_25 -> V_4 -> V_3 -> V_176 : 0 ;
if ( V_22 -> type != V_215 ||
strcmp ( V_22 -> V_23 , V_21 ) ||
V_219 != V_216 )
continue;
V_217 = true ;
V_46 . V_4 = V_25 -> V_4 ;
switch ( V_215 ) {
case V_194 :
V_46 . V_114 . V_199 = F_169 ( V_213 ) ;
break;
case V_200 :
if ( F_156 ( V_213 ) > V_220 ) {
V_33 = - V_54 ;
goto V_209;
}
V_46 . V_114 . V_115 = F_158 ( V_213 ) ;
break;
case V_202 :
V_46 . V_114 . V_204 . V_81 = F_156 ( V_213 ) ;
V_46 . V_114 . V_204 . V_205 = F_158 ( V_213 ) ;
break;
case V_206 :
V_46 . V_114 . V_117 = V_213 ? true : false ;
break;
default:
F_181 () ;
}
V_33 = F_37 ( V_15 , V_25 , & V_46 ) ;
if ( V_33 )
goto V_209;
}
if ( ! V_217 ) {
V_33 = - V_113 ;
goto V_209;
}
}
V_209:
F_171 ( V_15 ) ;
return V_33 ;
}
static int F_191 ( struct V_59 * V_60 ,
T_3 V_181 , T_3 V_182 , int V_103 ,
struct V_15 * V_15 ,
bool V_183 )
{
struct V_162 * V_62 ;
void * V_169 ;
struct V_1 * V_4 ;
V_169 = F_161 ( V_60 , V_181 , V_182 , & V_173 , V_103 ,
V_221 ) ;
if ( F_162 ( V_169 ) )
return F_163 ( V_169 ) ;
if ( F_175 ( V_60 , V_178 , V_15 -> V_3 -> V_176 ) )
goto V_185;
V_62 = F_176 ( V_60 , V_222 ) ;
if ( ! V_62 )
return - V_187 ;
F_12 (port, &team->port_list, list) {
struct V_162 * V_223 ;
if ( ! V_183 && ! V_4 -> V_28 )
continue;
V_223 = F_176 ( V_60 , V_224 ) ;
if ( ! V_223 )
goto V_185;
if ( F_175 ( V_60 , V_225 , V_4 -> V_3 -> V_176 ) )
goto V_185;
if ( V_4 -> V_28 ) {
if ( F_178 ( V_60 , V_226 ) )
goto V_185;
V_4 -> V_28 = false ;
}
if ( ( V_4 -> V_29 &&
F_178 ( V_60 , V_227 ) ) ||
( V_4 -> V_19 . V_16 &&
F_178 ( V_60 , V_228 ) ) ||
F_175 ( V_60 , V_229 , V_4 -> V_19 . V_230 ) ||
F_179 ( V_60 , V_231 , V_4 -> V_19 . V_232 ) )
goto V_185;
F_182 ( V_60 , V_223 ) ;
}
F_182 ( V_60 , V_62 ) ;
return F_164 ( V_60 , V_169 ) ;
V_185:
F_183 ( V_60 , V_169 ) ;
return - V_187 ;
}
static int F_192 ( struct V_59 * V_60 ,
struct V_166 * V_167 , int V_103 ,
struct V_15 * V_15 )
{
return F_191 ( V_60 , V_167 -> V_171 ,
V_167 -> V_172 , V_179 ,
V_15 , true ) ;
}
static int F_193 ( struct V_59 * V_60 ,
struct V_166 * V_167 )
{
struct V_15 * V_15 ;
int V_33 ;
V_15 = F_168 ( V_167 ) ;
if ( ! V_15 )
return - V_54 ;
V_33 = F_172 ( V_167 , V_15 , F_192 ) ;
F_171 ( V_15 ) ;
return V_33 ;
}
static int F_194 ( struct V_15 * V_15 )
{
struct V_59 * V_60 ;
int V_33 ;
struct V_160 * V_160 = F_195 ( V_15 -> V_3 ) ;
V_60 = F_160 ( V_170 , V_26 ) ;
if ( ! V_60 )
return - V_27 ;
V_33 = F_174 ( V_60 , 0 , 0 , 0 , V_15 , false ) ;
if ( V_33 < 0 )
goto V_180;
V_33 = F_196 ( V_160 , V_60 , 0 , V_233 . V_234 ,
V_26 ) ;
return V_33 ;
V_180:
F_167 ( V_60 ) ;
return V_33 ;
}
static int F_197 ( struct V_15 * V_15 )
{
struct V_59 * V_60 ;
int V_33 ;
struct V_160 * V_160 = F_195 ( V_15 -> V_3 ) ;
V_60 = F_160 ( V_170 , V_26 ) ;
if ( ! V_60 )
return - V_27 ;
V_33 = F_191 ( V_60 , 0 , 0 , 0 , V_15 , false ) ;
if ( V_33 < 0 )
goto V_180;
V_33 = F_196 ( V_160 , V_60 , 0 , V_233 . V_234 ,
V_26 ) ;
return V_33 ;
V_180:
F_167 ( V_60 ) ;
return V_33 ;
}
static int F_198 ( void )
{
int V_33 ;
V_33 = F_199 ( & V_173 , V_235 ,
F_116 ( V_235 ) ) ;
if ( V_33 )
return V_33 ;
V_33 = F_200 ( & V_173 , & V_233 ) ;
if ( V_33 )
goto V_236;
return 0 ;
V_236:
F_201 ( & V_173 ) ;
return V_33 ;
}
static void F_202 ( void )
{
F_201 ( & V_173 ) ;
}
static void F_32 ( struct V_15 * V_15 )
{
int V_33 ;
V_33 = F_194 ( V_15 ) ;
if ( V_33 )
F_203 ( V_15 -> V_3 , L_22 ) ;
}
static void F_94 ( struct V_1 * V_4 , bool V_16 )
{
int V_33 ;
if ( ! V_4 -> V_29 && V_4 -> V_19 . V_16 == V_16 )
return;
V_4 -> V_28 = true ;
V_4 -> V_19 . V_16 = V_16 ;
F_10 ( V_4 ) ;
if ( V_16 ) {
struct V_237 V_238 ;
V_33 = F_204 ( V_4 -> V_3 , & V_238 ) ;
if ( ! V_33 ) {
V_4 -> V_19 . V_230 = F_205 ( & V_238 ) ;
V_4 -> V_19 . V_232 = V_238 . V_232 ;
goto V_239;
}
}
V_4 -> V_19 . V_230 = 0 ;
V_4 -> V_19 . V_232 = 0 ;
V_239:
V_33 = F_197 ( V_4 -> V_15 ) ;
if ( V_33 )
F_203 ( V_4 -> V_15 -> V_3 , L_23 ,
V_4 -> V_3 -> V_23 ) ;
}
static void F_206 ( struct V_1 * V_4 , bool V_16 )
{
struct V_15 * V_15 = V_4 -> V_15 ;
F_80 ( & V_15 -> V_96 ) ;
F_94 ( V_4 , V_16 ) ;
F_81 ( & V_15 -> V_96 ) ;
}
static int F_207 ( struct V_240 * V_241 ,
unsigned long V_242 , void * V_205 )
{
struct V_2 * V_3 = (struct V_2 * ) V_205 ;
struct V_1 * V_4 ;
V_4 = F_4 ( V_3 ) ;
if ( ! V_4 )
return V_243 ;
switch ( V_242 ) {
case V_244 :
if ( F_95 ( V_3 ) )
F_206 ( V_4 , true ) ;
case V_245 :
F_206 ( V_4 , false ) ;
case V_246 :
if ( F_208 ( V_4 -> V_3 ) )
F_206 ( V_4 ,
! ! F_95 ( V_4 -> V_3 ) ) ;
break;
case V_247 :
F_148 ( V_4 -> V_15 -> V_3 , V_3 ) ;
break;
case V_248 :
F_79 ( V_4 -> V_15 ) ;
break;
case V_249 :
return V_250 ;
case V_251 :
return V_250 ;
}
return V_243 ;
}
static int T_8 F_209 ( void )
{
int V_33 ;
F_210 ( & V_252 ) ;
V_33 = F_211 ( & V_253 ) ;
if ( V_33 )
goto V_254;
V_33 = F_198 () ;
if ( V_33 )
goto V_255;
return 0 ;
V_255:
F_212 ( & V_253 ) ;
V_254:
F_213 ( & V_252 ) ;
return V_33 ;
}
static void T_9 F_214 ( void )
{
F_202 () ;
F_212 ( & V_253 ) ;
F_213 ( & V_252 ) ;
}
