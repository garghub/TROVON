static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static T_1 F_4 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_1
L_2 V_6 L_3 , V_7 ,
F_5 () -> V_8 , F_5 () -> V_9 ) ;
}
static T_1 F_6 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_4 , V_10 ) ;
}
static T_1 F_7 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
T_1 V_12 ;
struct V_13 * V_14 ;
F_8 ( & V_15 ) ;
if ( ! F_9 ( & V_16 ) ) {
F_10 ( & V_15 ) ;
F_11 ( L_5 ) ;
return - V_17 ;
}
if ( V_11 > ( V_18 - 1 ) ) {
F_10 ( & V_15 ) ;
F_11 ( L_6 ,
( int ) V_11 , V_18 - 1 ) ;
return - V_17 ;
}
V_12 = snprintf ( V_19 , V_18 , L_7 , V_5 ) ;
if ( ! V_12 ) {
F_10 ( & V_15 ) ;
return - V_17 ;
}
if ( V_19 [ V_12 - 1 ] == '\n' )
V_19 [ V_12 - 1 ] = '\0' ;
V_14 = F_12 ( V_19 , V_20 , 0 ) ;
if ( F_13 ( V_14 ) ) {
F_10 ( & V_15 ) ;
F_11 ( L_8 , V_19 ) ;
return - V_17 ;
}
if ( ! F_14 ( F_15 ( V_14 ) -> V_21 ) ) {
F_16 ( V_14 , NULL ) ;
F_10 ( & V_15 ) ;
F_11 ( L_9 , V_19 ) ;
return - V_17 ;
}
F_16 ( V_14 , NULL ) ;
strncpy ( V_10 , V_19 , V_12 ) ;
F_10 ( & V_15 ) ;
return V_12 ;
}
static struct V_22 * F_17 (
const char * V_23 )
{
struct V_22 * V_24 ;
if ( ! V_23 )
return NULL ;
F_8 ( & V_15 ) ;
F_18 (tf, &g_tf_list, tf_list) {
if ( ! strcmp ( V_24 -> V_25 -> V_23 , V_23 ) ) {
F_19 ( & V_24 -> V_26 ) ;
F_10 ( & V_15 ) ;
return V_24 ;
}
}
F_10 ( & V_15 ) ;
return NULL ;
}
static struct V_27 * F_20 (
struct V_27 * V_28 ,
const char * V_23 )
{
struct V_22 * V_24 ;
int V_29 ;
F_21 ( L_10
L_11 , V_28 , V_23 ) ;
V_24 = F_17 ( V_23 ) ;
if ( ! V_24 ) {
F_21 ( L_12 ,
V_23 ) ;
if ( ! strncmp ( V_23 , L_13 , 5 ) ) {
V_29 = F_22 ( L_14 ) ;
if ( V_29 < 0 ) {
F_21 ( L_15
L_16 , V_29 ) ;
return F_23 ( - V_17 ) ;
}
} else if ( ! strncmp ( V_23 , L_17 , 8 ) ) {
V_29 = F_22 ( L_18 ) ;
if ( V_29 < 0 ) {
F_21 ( L_15
L_19 , V_29 ) ;
return F_23 ( - V_17 ) ;
}
}
V_24 = F_17 ( V_23 ) ;
}
if ( ! V_24 ) {
F_21 ( L_20 ,
V_23 ) ;
return F_23 ( - V_17 ) ;
}
F_21 ( L_21
L_11 , V_24 -> V_25 -> V_23 ) ;
F_21 ( L_22 ,
& V_24 -> V_30 ) ;
F_24 ( & V_24 -> V_31 , V_23 , & V_24 -> V_30 ) ;
F_24 ( & V_24 -> V_32 , L_23 ,
& V_24 -> V_33 ) ;
F_25 ( & V_24 -> V_32 , & V_24 -> V_31 ) ;
F_21 ( L_24
L_11 , V_24 -> V_31 . V_34 . V_35 ) ;
return & V_24 -> V_31 ;
}
static void F_26 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
struct V_22 * V_24 = F_2 (
F_3 ( V_3 ) , struct V_22 , V_31 ) ;
F_21 ( L_25
L_26 , F_27 ( V_3 ) ) ;
F_21 ( L_27
L_11 , V_24 -> V_25 -> V_23 ) ;
F_28 ( & V_24 -> V_26 ) ;
F_21 ( L_28
L_11 , F_27 ( V_3 ) ) ;
F_29 ( & V_24 -> V_31 ) ;
F_30 ( V_3 ) ;
}
int F_31 ( struct V_2 * V_3 )
{
return F_32 ( & V_36 , V_3 ) ;
}
void F_33 ( struct V_2 * V_3 )
{
return F_34 ( V_3 ) ;
}
static int F_35 ( const struct V_37 * V_38 )
{
if ( ! V_38 -> V_23 ) {
F_11 ( L_29 ) ;
return - V_17 ;
}
if ( strlen ( V_38 -> V_23 ) >= V_39 ) {
F_11 ( L_30
L_31 , V_38 -> V_23 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_40 ) {
F_11 ( L_32 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_41 ) {
F_11 ( L_33 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_42 ) {
F_11 ( L_34 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_43 ) {
F_11 ( L_35 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_44 ) {
F_11 ( L_36 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_45 ) {
F_11 ( L_37 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_46 ) {
F_11 ( L_38 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_47 ) {
F_11 ( L_39 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_48 ) {
F_11 ( L_40 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_49 ) {
F_11 ( L_41 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_50 ) {
F_11 ( L_42 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_51 ) {
F_11 ( L_43 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_52 ) {
F_11 ( L_44 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_53 ) {
F_11 ( L_45 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_54 ) {
F_11 ( L_46 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_55 ) {
F_11 ( L_47 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_56 ) {
F_11 ( L_48 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_57 ) {
F_11 ( L_49 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_58 ) {
F_11 ( L_50 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_59 ) {
F_11 ( L_51 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_60 ) {
F_11 ( L_52 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_61 ) {
F_11 ( L_53 ) ;
return - V_17 ;
}
if ( ! V_38 -> V_62 ) {
F_11 ( L_54 ) ;
return - V_17 ;
}
return 0 ;
}
int F_36 ( const struct V_37 * V_63 )
{
struct V_22 * V_24 ;
int V_29 ;
V_29 = F_35 ( V_63 ) ;
if ( V_29 )
return V_29 ;
V_24 = F_37 ( sizeof( struct V_22 ) , V_64 ) ;
if ( ! V_24 ) {
F_11 ( L_55 , V_65 ) ;
return - V_66 ;
}
F_38 ( & V_24 -> V_67 ) ;
F_39 ( & V_24 -> V_26 , 0 ) ;
V_24 -> V_25 = V_63 ;
F_40 ( V_24 ) ;
F_8 ( & V_15 ) ;
F_41 ( & V_24 -> V_67 , & V_16 ) ;
F_10 ( & V_15 ) ;
return 0 ;
}
void F_42 ( const struct V_37 * V_63 )
{
struct V_22 * V_68 ;
F_8 ( & V_15 ) ;
F_18 (t, &g_tf_list, tf_list) {
if ( ! strcmp ( V_68 -> V_25 -> V_23 , V_63 -> V_23 ) ) {
F_43 ( F_44 ( & V_68 -> V_26 ) ) ;
F_45 ( & V_68 -> V_67 ) ;
F_10 ( & V_15 ) ;
F_46 () ;
F_47 ( V_68 ) ;
return;
}
}
F_10 ( & V_15 ) ;
}
static inline struct V_69 * F_48 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_69 ,
V_70 ) ;
}
static void F_49 ( struct V_71 * V_72 )
{
const char * V_73 ;
V_73 = F_27 ( & V_72 -> V_74 . V_34 ) ;
if ( strlen ( V_73 ) >= 16 ) {
F_50 ( L_56
L_57 , V_72 ,
V_73 ) ;
}
snprintf ( & V_72 -> V_75 . V_76 [ 0 ] , 16 , L_7 , V_73 ) ;
}
static T_1 F_51 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
struct V_71 * V_72 = V_77 -> V_78 ;
bool V_79 ;
int V_29 ;
if ( V_72 -> V_80 ) {
F_11 ( L_58
L_59 ,
V_72 , V_72 -> V_80 ) ;
return - V_17 ;
}
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_79 ) {
F_49 ( V_72 ) ;
} else {
strncpy ( & V_72 -> V_75 . V_76 [ 0 ] ,
V_72 -> V_81 -> V_82 , 16 ) ;
}
V_77 -> V_83 = V_79 ;
return V_11 ;
}
static T_1 F_53 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
bool V_79 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_79 && V_77 -> V_78 -> V_81 -> V_84 ) {
F_11 ( L_60 ) ;
return - V_17 ;
}
V_77 -> V_85 = V_79 ;
F_21 ( L_61 ,
V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_54 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
T_3 V_86 ;
int V_29 ;
V_29 = F_55 ( V_5 , 0 , & V_86 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_86 != 0 && V_86 != 1 && V_86 != 2 ) {
F_11 ( L_62 , V_86 ) ;
return - V_17 ;
}
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_63
L_64 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
V_77 -> V_87 = V_86 ;
F_21 ( L_65 ,
V_77 -> V_78 , V_86 ) ;
return V_11 ;
}
static T_1 F_56 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
bool V_79 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_66
L_67 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
V_77 -> V_88 = V_79 ;
F_21 ( L_68 ,
V_77 -> V_78 , V_79 ? L_69 : L_70 ) ;
return V_11 ;
}
static T_1 F_57 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
bool V_79 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_79 && ! V_77 -> V_89 ) {
F_11 ( L_71 ) ;
return - V_90 ;
}
V_77 -> V_91 = V_79 ;
F_21 ( L_72 ,
V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_58 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
bool V_79 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_79 && ! V_77 -> V_89 ) {
F_11 ( L_71 ) ;
return - V_90 ;
}
V_77 -> V_92 = V_79 ;
F_21 ( L_73 ,
V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_59 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
int V_93 = V_77 -> V_94 , V_29 ;
struct V_71 * V_72 = V_77 -> V_78 ;
T_3 V_79 ;
V_29 = F_55 ( V_5 , 0 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_79 != 0 && V_79 != 1 && V_79 != 2 && V_79 != 3 ) {
F_11 ( L_74 , V_79 ) ;
return - V_17 ;
}
if ( V_79 == 2 ) {
F_11 ( L_75 ) ;
return - V_90 ;
}
if ( V_77 -> V_95 ) {
F_50 ( L_76
L_77 ) ;
return V_11 ;
}
if ( ! V_72 -> V_81 -> V_96 || ! V_72 -> V_81 -> V_97 ) {
if ( V_79 == 0 )
return V_11 ;
F_11 ( L_78 ,
V_72 -> V_81 -> V_23 ) ;
return - V_90 ;
}
if ( ! ( V_72 -> V_98 & V_99 ) ) {
F_11 ( L_79 ) ;
return - V_100 ;
}
if ( V_72 -> V_80 ) {
F_11 ( L_80
L_67 , V_72 , V_72 -> V_80 ) ;
return - V_17 ;
}
V_77 -> V_94 = V_79 ;
if ( V_79 && ! V_93 ) {
V_29 = V_72 -> V_81 -> V_96 ( V_72 ) ;
if ( V_29 ) {
V_77 -> V_94 = V_93 ;
V_77 -> V_101 = ( bool ) V_77 -> V_94 ;
return V_29 ;
}
} else if ( ! V_79 && V_93 ) {
V_72 -> V_81 -> V_97 ( V_72 ) ;
}
V_77 -> V_101 = ( bool ) V_77 -> V_94 ;
F_21 ( L_81 , V_72 , V_79 ) ;
return V_11 ;
}
static T_1 F_60 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
struct V_71 * V_72 = V_77 -> V_78 ;
bool V_79 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( ! V_79 )
return V_11 ;
if ( ! V_72 -> V_81 -> V_102 ) {
F_11 ( L_82 ,
V_72 -> V_81 -> V_23 ) ;
return - V_90 ;
}
if ( ! ( V_72 -> V_98 & V_99 ) ) {
F_11 ( L_83 ) ;
return - V_100 ;
}
if ( V_72 -> V_80 ) {
F_11 ( L_84
L_67 , V_72 , V_72 -> V_80 ) ;
return - V_17 ;
}
V_29 = V_72 -> V_81 -> V_102 ( V_72 ) ;
if ( V_29 )
return V_29 ;
F_21 ( L_85 , V_72 ) ;
return V_11 ;
}
static T_1 F_61 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
bool V_79 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( ! V_79 ) {
V_77 -> V_101 = V_79 ;
return V_11 ;
}
if ( V_77 -> V_95 ) {
F_50 ( L_76
L_77 ) ;
return V_11 ;
}
if ( ! V_77 -> V_94 ) {
F_50 ( L_86 ) ;
return V_11 ;
}
V_77 -> V_101 = V_79 ;
return V_11 ;
}
static T_1 F_62 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
bool V_79 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_87
L_67 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
V_77 -> V_103 = V_79 ;
F_21 ( L_88 , V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_63 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
bool V_79 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_79 != 0 ) {
F_64 ( V_104 L_89
L_90 , V_77 -> V_78 ) ;
return - V_90 ;
}
V_77 -> V_105 = V_79 ;
F_21 ( L_91 ,
V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_65 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
bool V_79 ;
int V_29 ;
V_29 = F_52 ( V_5 , & V_79 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_63
L_92 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
if ( V_79 && ! V_77 -> V_89 ) {
F_11 ( L_93
L_94 ,
V_77 -> V_78 ) ;
return - V_90 ;
}
V_77 -> V_106 = V_79 ;
F_21 ( L_95 ,
V_77 -> V_78 , V_79 ) ;
return V_11 ;
}
static T_1 F_66 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
struct V_71 * V_72 = V_77 -> V_78 ;
T_3 V_86 ;
int V_29 ;
V_29 = F_55 ( V_5 , 0 , & V_86 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_72 -> V_80 ) {
F_11 ( L_96
L_67 ,
V_72 , V_72 -> V_80 ) ;
return - V_17 ;
}
if ( ! V_86 ) {
F_11 ( L_97 , V_72 ) ;
return - V_17 ;
}
if ( V_86 > V_72 -> V_107 . V_108 ) {
if ( V_86 > V_72 -> V_107 . V_109 ) {
F_11 ( L_98
L_99
L_100 , V_72 , V_86 ,
V_72 -> V_107 . V_109 ) ;
return - V_17 ;
}
}
V_77 -> V_108 = V_72 -> V_108 = V_86 ;
F_21 ( L_101 , V_72 , V_86 ) ;
return V_11 ;
}
static T_1 F_67 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
T_3 V_86 ;
int V_29 ;
V_29 = F_55 ( V_5 , 0 , & V_86 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_63
L_102 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
if ( V_86 > V_77 -> V_110 ) {
F_11 ( L_103
L_104 ,
V_77 -> V_78 , V_86 , V_77 -> V_110 ) ;
return - V_17 ;
}
V_77 -> V_111 = V_86 ;
F_21 ( L_105 ,
V_77 -> V_78 , V_86 ) ;
return V_11 ;
}
static T_1 F_68 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
T_3 V_86 ;
int V_29 ;
V_29 = F_55 ( V_5 , 0 , & V_86 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_77 -> V_78 -> V_80 ) {
F_11 ( L_106
L_59 ,
V_77 -> V_78 , V_77 -> V_78 -> V_80 ) ;
return - V_17 ;
}
if ( V_86 != 512 && V_86 != 1024 && V_86 != 2048 && V_86 != 4096 ) {
F_11 ( L_107
L_108 ,
V_77 -> V_78 , V_86 ) ;
return - V_17 ;
}
V_77 -> V_112 = V_86 ;
if ( V_77 -> V_113 )
V_77 -> V_110 = V_77 -> V_113 / V_86 ;
F_21 ( L_109 ,
V_77 -> V_78 , V_86 ) ;
return V_11 ;
}
static T_1 F_69 ( struct V_2 * V_3 , char * V_5 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
T_4 V_114 = V_77 -> V_78 -> V_81 -> V_115 ;
return snprintf ( V_5 , V_116 , L_110 ,
V_114 & V_117 ? 0 : 1 ) ;
}
static T_1 F_70 ( struct V_2 * V_3 , char * V_5 )
{
struct V_69 * V_77 = F_48 ( V_3 ) ;
T_4 V_114 = V_77 -> V_78 -> V_81 -> V_115 ;
return snprintf ( V_5 , V_116 , L_110 ,
V_114 & V_118 ? 0 : 1 ) ;
}
static struct V_75 * F_71 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_75 , V_119 ) ;
}
static T_1 F_72 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_111 ,
& F_71 ( V_3 ) -> V_120 [ 0 ] ) ;
}
static T_1 F_73 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_75 * V_75 = F_71 ( V_3 ) ;
struct V_71 * V_72 = V_75 -> V_121 ;
unsigned char V_122 [ V_123 ] ;
if ( V_72 -> V_98 & V_124 ) {
F_11 ( L_112
L_113 ) ;
return - V_125 ;
}
if ( strlen ( V_5 ) >= V_123 ) {
F_11 ( L_114
L_115 , V_123 ) ;
return - V_126 ;
}
if ( V_72 -> V_80 ) {
F_11 ( L_116
L_117 ,
V_72 -> V_80 ) ;
return - V_17 ;
}
memset ( V_122 , 0 , V_123 ) ;
snprintf ( V_122 , V_123 , L_7 , V_5 ) ;
snprintf ( V_72 -> V_75 . V_120 , V_123 ,
L_7 , F_74 ( V_122 ) ) ;
V_72 -> V_98 |= V_127 ;
F_21 ( L_118
L_11 , V_72 -> V_75 . V_120 ) ;
return V_11 ;
}
static T_1 F_75 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_75 * V_75 = F_71 ( V_3 ) ;
struct V_128 * V_129 ;
unsigned char V_122 [ V_130 ] ;
T_1 V_131 = 0 ;
memset ( V_122 , 0 , V_130 ) ;
F_76 ( & V_75 -> V_132 ) ;
F_18 (vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if ( ! V_129 -> V_133 )
continue;
F_77 ( V_129 , V_122 , V_130 ) ;
if ( V_131 + strlen ( V_122 ) >= V_116 )
break;
V_131 += sprintf ( V_5 + V_131 , L_7 , V_122 ) ;
}
F_78 ( & V_75 -> V_132 ) ;
return V_131 ;
}
static struct V_71 * F_79 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_71 ,
V_134 ) ;
}
static T_1 F_80 ( struct V_71 * V_72 ,
char * V_5 )
{
struct V_135 * V_136 ;
struct V_137 * V_138 ;
char V_139 [ V_140 ] ;
memset ( V_139 , 0 , V_140 ) ;
V_138 = V_72 -> V_141 ;
if ( ! V_138 )
return sprintf ( V_5 , L_119 ) ;
V_136 = V_138 -> V_142 ;
F_81 ( V_138 , V_139 , V_140 ) ;
return sprintf ( V_5 , L_120 ,
V_136 -> V_143 -> V_144 -> V_40 () ,
V_136 -> V_145 , V_139 ) ;
}
static T_1 F_82 ( struct V_71 * V_72 ,
char * V_5 )
{
struct V_135 * V_136 ;
T_1 V_131 ;
V_136 = V_72 -> V_146 ;
if ( V_136 ) {
V_131 = sprintf ( V_5 ,
L_121 ,
V_136 -> V_143 -> V_144 -> V_40 () ,
V_136 -> V_145 ) ;
} else {
V_131 = sprintf ( V_5 , L_122 ) ;
}
return V_131 ;
}
static T_1 F_83 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_79 ( V_3 ) ;
int V_29 ;
if ( V_72 -> V_81 -> V_115 & V_118 )
return sprintf ( V_5 , L_123 ) ;
F_76 ( & V_72 -> V_147 ) ;
if ( V_72 -> V_148 & V_149 )
V_29 = F_82 ( V_72 , V_5 ) ;
else
V_29 = F_80 ( V_72 , V_5 ) ;
F_78 ( & V_72 -> V_147 ) ;
return V_29 ;
}
static T_1 F_84 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_79 ( V_3 ) ;
T_1 V_131 = 0 ;
F_76 ( & V_72 -> V_147 ) ;
if ( ! V_72 -> V_141 ) {
V_131 = sprintf ( V_5 , L_119 ) ;
} else if ( V_72 -> V_141 -> V_150 ) {
V_131 = sprintf ( V_5 , L_124
L_125 ) ;
} else {
V_131 = sprintf ( V_5 , L_126
L_127 ) ;
}
F_78 ( & V_72 -> V_147 ) ;
return V_131 ;
}
static T_1 F_85 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_128 , F_79 ( V_3 ) -> V_151 . V_152 ) ;
}
static T_1 F_86 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_79 ( V_3 ) ;
struct V_135 * V_136 ;
struct V_153 * V_143 ;
struct V_137 * V_138 ;
const struct V_37 * V_38 ;
T_1 V_131 = 0 ;
F_76 ( & V_72 -> V_147 ) ;
V_138 = V_72 -> V_141 ;
if ( ! V_138 ) {
V_131 = sprintf ( V_5 , L_119 ) ;
goto V_154;
}
V_136 = V_138 -> V_142 ;
V_143 = V_136 -> V_143 ;
V_38 = V_143 -> V_144 ;
V_131 += sprintf ( V_5 + V_131 , L_129
L_130 , V_38 -> V_40 () ,
V_38 -> V_41 ( V_143 ) ) ;
V_131 += sprintf ( V_5 + V_131 , L_131
L_132
L_133 , V_138 -> V_155 ,
V_38 -> V_40 () , V_38 -> V_42 ( V_143 ) ,
V_38 -> V_40 () , V_138 -> V_156 ) ;
V_154:
F_78 ( & V_72 -> V_147 ) ;
return V_131 ;
}
static T_1 F_87 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_79 ( V_3 ) ;
const struct V_37 * V_38 ;
struct V_137 * V_138 ;
unsigned char V_122 [ 384 ] ;
char V_139 [ V_140 ] ;
T_1 V_131 = 0 ;
int V_157 = 0 ;
V_131 += sprintf ( V_5 + V_131 , L_134 ) ;
F_76 ( & V_72 -> V_151 . V_158 ) ;
F_18 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
memset ( V_122 , 0 , 384 ) ;
memset ( V_139 , 0 , V_140 ) ;
V_38 = V_138 -> V_142 -> V_143 -> V_144 ;
F_81 ( V_138 , V_139 ,
V_140 ) ;
sprintf ( V_122 , L_135 ,
V_38 -> V_40 () ,
V_138 -> V_142 -> V_145 , V_139 , V_138 -> V_159 ,
V_138 -> V_160 ) ;
if ( V_131 + strlen ( V_122 ) >= V_116 )
break;
V_131 += sprintf ( V_5 + V_131 , L_7 , V_122 ) ;
V_157 ++ ;
}
F_78 ( & V_72 -> V_151 . V_158 ) ;
if ( ! V_157 )
V_131 += sprintf ( V_5 + V_131 , L_136 ) ;
return V_131 ;
}
static T_1 F_88 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_79 ( V_3 ) ;
struct V_137 * V_138 ;
T_1 V_131 = 0 ;
F_76 ( & V_72 -> V_147 ) ;
V_138 = V_72 -> V_141 ;
if ( V_138 ) {
V_131 = sprintf ( V_5 , L_137 ,
F_89 ( V_138 -> V_161 ) ) ;
} else {
V_131 = sprintf ( V_5 , L_119 ) ;
}
F_78 ( & V_72 -> V_147 ) ;
return V_131 ;
}
static T_1 F_90 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_79 ( V_3 ) ;
if ( V_72 -> V_81 -> V_115 & V_118 )
return sprintf ( V_5 , L_138 ) ;
else if ( V_72 -> V_148 & V_149 )
return sprintf ( V_5 , L_139 ) ;
else
return sprintf ( V_5 , L_140 ) ;
}
static T_1 F_91 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_79 ( V_3 ) ;
if ( V_72 -> V_81 -> V_115 & V_118 )
return 0 ;
return sprintf ( V_5 , L_141 ,
( V_72 -> V_151 . V_162 ) ? L_142 : L_70 ) ;
}
static T_1 F_92 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_79 ( V_3 ) ;
if ( V_72 -> V_81 -> V_115 & V_118 )
return 0 ;
return sprintf ( V_5 , L_143 ) ;
}
static T_1 F_93 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_79 ( V_3 ) ;
unsigned char * V_163 = NULL , * V_164 = NULL , * V_165 = NULL ;
unsigned char * V_166 = NULL , * V_167 = NULL ;
char * V_168 , * V_169 , * V_170 ;
T_5 args [ V_171 ] ;
unsigned long long V_172 ;
T_6 V_173 = 0 ;
T_6 V_174 = 0 , V_175 = 0 ;
int V_29 = - 1 , V_176 = 0 , V_177 = 0 , V_178 , V_179 ;
T_7 V_180 = 0 ;
T_4 type = 0 ;
if ( V_72 -> V_81 -> V_115 & V_118 )
return V_11 ;
if ( V_72 -> V_148 & V_149 )
return V_11 ;
if ( V_72 -> V_80 ) {
F_21 ( L_144
L_145 ) ;
return - V_17 ;
}
V_170 = F_94 ( V_5 , V_64 ) ;
if ( ! V_170 )
return - V_66 ;
V_168 = V_170 ;
while ( ( V_169 = F_95 ( & V_170 , L_146 ) ) != NULL ) {
if ( ! * V_169 )
continue;
V_179 = F_96 ( V_169 , V_181 , args ) ;
switch ( V_179 ) {
case V_182 :
V_163 = F_97 ( args ) ;
if ( ! V_163 ) {
V_29 = - V_66 ;
goto V_183;
}
break;
case V_184 :
V_164 = F_97 ( args ) ;
if ( ! V_164 ) {
V_29 = - V_66 ;
goto V_183;
}
if ( strlen ( V_164 ) >= V_185 ) {
F_11 ( L_147
L_148 ,
V_185 ) ;
V_29 = - V_17 ;
break;
}
break;
case V_186 :
V_165 = F_97 ( args ) ;
if ( ! V_165 ) {
V_29 = - V_66 ;
goto V_183;
}
if ( strlen ( V_165 ) >= V_187 ) {
F_11 ( L_149
L_150 ,
V_187 ) ;
V_29 = - V_17 ;
break;
}
break;
case V_188 :
V_29 = F_98 ( args -> V_189 , 0 , & V_172 ) ;
if ( V_29 < 0 ) {
F_11 ( L_151 ) ;
goto V_183;
}
V_173 = ( T_6 ) V_172 ;
break;
case V_190 :
V_29 = F_99 ( args , & V_178 ) ;
if ( V_29 )
goto V_183;
V_176 = V_178 ;
break;
case V_191 :
V_29 = F_99 ( args , & V_178 ) ;
if ( V_29 )
goto V_183;
type = ( T_4 ) V_178 ;
break;
case V_192 :
V_29 = F_99 ( args , & V_178 ) ;
if ( V_29 )
goto V_183;
break;
case V_193 :
V_29 = F_99 ( args , & V_178 ) ;
if ( V_29 )
goto V_183;
V_177 = ( int ) V_178 ;
break;
case V_194 :
V_29 = F_99 ( args , & V_178 ) ;
if ( V_29 )
goto V_183;
V_174 = ( T_6 ) V_178 ;
break;
case V_195 :
V_166 = F_97 ( args ) ;
if ( ! V_166 ) {
V_29 = - V_66 ;
goto V_183;
}
break;
case V_196 :
V_167 = F_97 ( args ) ;
if ( ! V_167 ) {
V_29 = - V_66 ;
goto V_183;
}
if ( strlen ( V_167 ) >= V_197 ) {
F_11 ( L_152
L_153 ,
V_197 ) ;
V_29 = - V_17 ;
break;
}
break;
case V_198 :
V_29 = F_99 ( args , & V_178 ) ;
if ( V_29 )
goto V_183;
V_180 = ( T_7 ) V_178 ;
break;
case V_199 :
V_29 = F_99 ( args , & V_178 ) ;
if ( V_29 )
goto V_183;
break;
case V_200 :
V_29 = F_99 ( args , & V_178 ) ;
if ( V_29 )
goto V_183;
V_175 = ( T_6 ) V_178 ;
break;
default:
break;
}
}
if ( ! V_164 || ! V_167 || ! V_173 ) {
F_11 ( L_154 ) ;
V_29 = - V_17 ;
goto V_183;
}
if ( V_176 && ! ( type ) ) {
F_11 ( L_155
L_156 , type ) ;
V_29 = - V_17 ;
goto V_183;
}
V_29 = F_100 ( & V_72 -> V_151 , V_173 ,
V_164 , V_165 , V_174 , V_167 , V_180 , V_175 ,
V_176 , V_177 , type ) ;
V_183:
F_47 ( V_163 ) ;
F_47 ( V_164 ) ;
F_47 ( V_165 ) ;
F_47 ( V_166 ) ;
F_47 ( V_167 ) ;
F_47 ( V_168 ) ;
return ( V_29 == 0 ) ? V_11 : V_29 ;
}
static inline struct V_71 * F_101 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_71 , V_74 ) ;
}
static T_1 F_102 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_101 ( V_3 ) ;
int V_201 = 0 ;
T_1 V_12 = 0 ;
F_103 ( V_72 , V_5 , & V_201 ) ;
V_12 += V_201 ;
V_12 += V_72 -> V_81 -> V_202 ( V_72 ,
V_5 + V_12 ) ;
return V_12 ;
}
static T_1 F_104 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_101 ( V_3 ) ;
return V_72 -> V_81 -> V_203 ( V_72 , V_5 , V_11 ) ;
}
static T_1 F_105 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_101 ( V_3 ) ;
if ( ! ( V_72 -> V_98 & V_204 ) )
return 0 ;
return snprintf ( V_5 , V_116 , L_4 , V_72 -> V_205 ) ;
}
static T_1 F_106 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_101 ( V_3 ) ;
struct V_1 * V_206 = V_72 -> V_1 ;
T_1 V_12 ;
if ( V_11 > ( V_207 - 1 ) ) {
F_11 ( L_157
L_158 , ( int ) V_11 ,
V_207 - 1 ) ;
return - V_17 ;
}
V_12 = snprintf ( & V_72 -> V_205 [ 0 ] , V_207 , L_7 , V_5 ) ;
if ( ! V_12 )
return - V_17 ;
if ( V_72 -> V_205 [ V_12 - 1 ] == '\n' )
V_72 -> V_205 [ V_12 - 1 ] = '\0' ;
V_72 -> V_98 |= V_204 ;
F_21 ( L_159 ,
F_27 ( & V_206 -> V_4 . V_34 ) ,
F_27 ( & V_72 -> V_74 . V_34 ) ,
V_72 -> V_205 ) ;
return V_12 ;
}
static T_1 F_107 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_101 ( V_3 ) ;
if ( ! ( V_72 -> V_98 & V_208 ) )
return 0 ;
return snprintf ( V_5 , V_116 , L_4 , V_72 -> V_209 ) ;
}
static T_1 F_108 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_101 ( V_3 ) ;
struct V_1 * V_206 = V_72 -> V_1 ;
T_1 V_12 ;
if ( V_11 > ( V_210 - 1 ) ) {
F_11 ( L_160
L_161 , ( int ) V_11 ,
V_210 - 1 ) ;
return - V_17 ;
}
V_12 = snprintf ( & V_72 -> V_209 [ 0 ] , V_210 ,
L_7 , V_5 ) ;
if ( ! V_12 )
return - V_17 ;
if ( V_72 -> V_209 [ V_12 - 1 ] == '\n' )
V_72 -> V_209 [ V_12 - 1 ] = '\0' ;
V_72 -> V_98 |= V_208 ;
F_21 ( L_162 ,
F_27 ( & V_206 -> V_4 . V_34 ) ,
F_27 ( & V_72 -> V_74 . V_34 ) ,
V_72 -> V_209 ) ;
return V_12 ;
}
static T_1 F_109 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_101 ( V_3 ) ;
return snprintf ( V_5 , V_116 , L_110 , ! ! ( V_72 -> V_98 & V_99 ) ) ;
}
static T_1 F_110 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_101 ( V_3 ) ;
char * V_169 ;
int V_29 ;
V_169 = strstr ( V_5 , L_163 ) ;
if ( ! V_169 ) {
F_11 ( L_164
L_165 ) ;
return - V_17 ;
}
V_29 = F_111 ( V_72 ) ;
if ( V_29 )
return V_29 ;
return V_11 ;
}
static T_1 F_112 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_101 ( V_3 ) ;
struct V_2 * V_211 ;
struct V_212 * V_213 ;
struct V_214 * V_215 ;
T_1 V_131 = 0 ;
V_215 = V_72 -> V_216 ;
if ( ! V_215 )
return 0 ;
F_76 ( & V_215 -> V_217 ) ;
V_213 = V_215 -> V_213 ;
if ( V_213 ) {
V_211 = & V_213 -> V_218 . V_34 ;
V_131 += sprintf ( V_5 , L_166 ,
F_27 ( V_211 ) , V_213 -> V_219 ) ;
}
F_78 ( & V_215 -> V_217 ) ;
return V_131 ;
}
static T_1 F_113 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_101 ( V_3 ) ;
struct V_1 * V_206 = V_72 -> V_1 ;
struct V_212 * V_213 = NULL , * V_220 = NULL ;
struct V_214 * V_215 ;
unsigned char V_122 [ V_221 ] ;
int V_222 = 0 ;
V_215 = V_72 -> V_216 ;
if ( ! V_215 )
return V_11 ;
if ( V_11 > V_221 ) {
F_11 ( L_167 ) ;
return - V_17 ;
}
memset ( V_122 , 0 , V_221 ) ;
memcpy ( V_122 , V_5 , V_11 ) ;
if ( strcmp ( F_74 ( V_122 ) , L_168 ) ) {
V_220 = F_114 ( F_74 ( V_122 ) ) ;
if ( ! V_220 )
return - V_100 ;
}
F_76 ( & V_215 -> V_217 ) ;
V_213 = V_215 -> V_213 ;
if ( V_213 ) {
if ( ! V_220 ) {
F_21 ( L_169
L_170
L_171 ,
F_27 ( & V_206 -> V_4 . V_34 ) ,
F_27 ( & V_72 -> V_74 . V_34 ) ,
F_27 ( & V_213 -> V_218 . V_34 ) ,
V_213 -> V_219 ) ;
F_115 ( V_215 , V_213 ) ;
F_78 ( & V_215 -> V_217 ) ;
return V_11 ;
}
F_115 ( V_215 , V_213 ) ;
V_222 = 1 ;
}
F_116 ( V_215 , V_220 ) ;
F_78 ( & V_215 -> V_217 ) ;
F_21 ( L_172
L_173 ,
( V_222 ) ? L_174 : L_175 ,
F_27 ( & V_206 -> V_4 . V_34 ) ,
F_27 ( & V_72 -> V_74 . V_34 ) ,
F_27 ( & V_220 -> V_218 . V_34 ) ,
V_220 -> V_219 ) ;
F_117 ( V_220 ) ;
return V_11 ;
}
static T_1 F_118 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_101 ( V_3 ) ;
struct V_223 * V_224 ;
struct V_225 * V_226 ;
char * V_227 = V_5 ;
int V_201 = 0 ;
char V_228 ;
F_76 ( & V_72 -> V_229 . V_230 ) ;
if ( ! F_9 ( & V_72 -> V_229 . V_231 ) )
V_201 += sprintf ( V_227 + V_201 , L_176 ,
V_72 -> V_229 . V_232 ,
V_72 -> V_229 . V_233 ) ;
F_18 (map, &dev->t10_alua.lba_map_list, lba_map_list) {
V_201 += sprintf ( V_227 + V_201 , L_177 ,
V_224 -> V_234 , V_224 -> V_235 ) ;
F_18 (mem, &map->lba_map_mem_list,
lba_map_mem_list) {
switch ( V_226 -> V_236 ) {
case V_237 :
V_228 = 'O' ;
break;
case V_238 :
V_228 = 'A' ;
break;
case V_239 :
V_228 = 'S' ;
break;
case V_240 :
V_228 = 'U' ;
break;
default:
V_228 = '.' ;
break;
}
V_201 += sprintf ( V_227 + V_201 , L_178 ,
V_226 -> V_241 , V_228 ) ;
}
V_201 += sprintf ( V_227 + V_201 , L_3 ) ;
}
F_78 ( & V_72 -> V_229 . V_230 ) ;
return V_201 ;
}
static T_1 F_119 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_101 ( V_3 ) ;
struct V_223 * V_242 = NULL ;
struct V_243 V_244 ;
char * V_245 , * V_168 , * V_169 ;
char V_228 ;
int V_246 = - 1 , V_247 ;
int V_29 = 0 , V_248 = 0 , V_249 , V_250 ;
unsigned long V_251 = - 1 , V_252 = - 1 ;
unsigned long V_253 = - 1 , V_254 = - 1 ;
V_168 = V_245 = F_94 ( V_5 , V_64 ) ;
if ( ! V_245 )
return - V_66 ;
F_38 ( & V_244 ) ;
while ( ( V_169 = F_95 ( & V_245 , L_3 ) ) != NULL ) {
if ( ! * V_169 )
continue;
if ( V_248 == 0 ) {
if ( sscanf ( V_169 , L_179 ,
& V_253 , & V_254 ) != 2 ) {
F_11 ( L_180 , V_248 ) ;
V_29 = - V_17 ;
break;
}
V_248 ++ ;
continue;
}
if ( sscanf ( V_169 , L_181 , & V_251 , & V_252 ) != 2 ) {
F_11 ( L_180 , V_248 ) ;
V_29 = - V_17 ;
break;
}
V_169 = strchr ( V_169 , ' ' ) ;
if ( ! V_169 ) {
F_11 ( L_182 , V_248 ) ;
V_29 = - V_17 ;
break;
}
V_169 ++ ;
V_169 = strchr ( V_169 , ' ' ) ;
if ( ! V_169 ) {
F_11 ( L_183 ,
V_248 ) ;
V_29 = - V_17 ;
break;
}
V_169 ++ ;
V_242 = F_120 ( & V_244 ,
V_251 , V_252 ) ;
if ( F_13 ( V_242 ) ) {
V_29 = F_121 ( V_242 ) ;
break;
}
V_247 = 0 ;
while ( sscanf ( V_169 , L_184 , & V_249 , & V_228 ) == 2 ) {
switch ( V_228 ) {
case 'O' :
V_250 = V_237 ;
break;
case 'A' :
V_250 = V_238 ;
break;
case 'S' :
V_250 = V_239 ;
break;
case 'U' :
V_250 = V_240 ;
break;
default:
F_11 ( L_185 , V_228 ) ;
V_29 = - V_17 ;
goto V_183;
}
V_29 = F_122 ( V_242 ,
V_249 , V_250 ) ;
if ( V_29 ) {
F_11 ( L_186
L_187 ,
V_249 , V_228 , V_248 ) ;
break;
}
V_247 ++ ;
V_169 = strchr ( V_169 , ' ' ) ;
if ( V_169 )
V_169 ++ ;
else
break;
}
if ( V_246 == - 1 )
V_246 = V_247 ;
else if ( V_247 != V_246 ) {
F_11 ( L_188
L_187 , V_247 , V_246 , V_248 ) ;
V_29 = - V_17 ;
break;
}
V_248 ++ ;
}
V_183:
if ( V_29 ) {
F_123 ( & V_244 ) ;
V_11 = V_29 ;
} else
F_124 ( V_72 , & V_244 ,
V_253 , V_254 ) ;
F_47 ( V_168 ) ;
return V_11 ;
}
static void F_125 ( struct V_2 * V_3 )
{
struct V_27 * V_255 = F_3 ( V_3 ) ;
struct V_71 * V_72 =
F_2 ( V_255 , struct V_71 , V_74 ) ;
F_126 ( V_72 ) ;
}
static inline struct V_212 * F_127 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_212 ,
V_218 ) ;
}
static T_1 F_128 ( struct V_2 * V_3 , char * V_5 )
{
struct V_212 * V_213 = F_127 ( V_3 ) ;
if ( ! V_213 -> V_256 )
return 0 ;
return sprintf ( V_5 , L_189 , V_213 -> V_219 ) ;
}
static T_1 F_129 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_212 * V_213 = F_127 ( V_3 ) ;
struct V_27 * V_257 = & V_213 -> V_218 ;
unsigned long V_219 ;
int V_29 ;
V_29 = F_130 ( V_5 , 0 , & V_219 ) ;
if ( V_29 < 0 ) {
F_11 ( L_190
L_191 , V_29 ) ;
return V_29 ;
}
if ( V_219 > 0x0000ffff ) {
F_11 ( L_192
L_193 , V_219 ) ;
return - V_17 ;
}
V_29 = F_131 ( V_213 , ( T_7 ) V_219 ) ;
if ( V_29 < 0 )
return - V_17 ;
F_21 ( L_194
L_195 ,
F_27 ( & V_257 -> V_34 ) ,
V_213 -> V_219 ) ;
return V_11 ;
}
static T_1 F_132 ( struct V_2 * V_3 , char * V_5 )
{
struct V_212 * V_213 = F_127 ( V_3 ) ;
struct V_71 * V_72 ;
struct V_1 * V_206 ;
struct V_214 * V_215 ;
T_1 V_131 = 0 , V_258 ;
unsigned char V_122 [ V_221 ] ;
memset ( V_122 , 0 , V_221 ) ;
F_76 ( & V_213 -> V_259 ) ;
F_18 (lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
V_72 = V_215 -> V_260 ;
V_206 = V_72 -> V_1 ;
V_258 = snprintf ( V_122 , V_221 , L_196 ,
F_27 ( & V_206 -> V_4 . V_34 ) ,
F_27 ( & V_72 -> V_74 . V_34 ) ) ;
V_258 ++ ;
if ( ( V_258 + V_131 ) > V_116 ) {
F_50 ( L_197
L_198 ) ;
break;
}
memcpy ( V_5 + V_131 , V_122 , V_258 ) ;
V_131 += V_258 ;
}
F_78 ( & V_213 -> V_259 ) ;
return V_131 ;
}
static void F_133 ( struct V_2 * V_3 )
{
struct V_212 * V_213 = F_2 ( F_3 ( V_3 ) ,
struct V_212 , V_218 ) ;
F_134 ( V_213 ) ;
}
static struct V_27 * F_135 (
struct V_27 * V_28 ,
const char * V_23 )
{
struct V_212 * V_213 ;
struct V_27 * V_257 = NULL ;
struct V_2 * V_261 = NULL ;
V_213 = F_136 ( V_23 , 0 ) ;
if ( F_13 ( V_213 ) )
return NULL ;
V_257 = & V_213 -> V_218 ;
V_261 = & V_257 -> V_34 ;
F_24 ( V_257 , V_23 ,
& V_262 ) ;
F_21 ( L_199
L_200 ,
F_27 ( V_261 ) ) ;
return V_257 ;
}
static void F_137 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
struct V_212 * V_213 = F_2 ( F_3 ( V_3 ) ,
struct V_212 , V_218 ) ;
F_21 ( L_201
L_202 ,
F_27 ( V_3 ) , V_213 -> V_219 ) ;
F_30 ( V_3 ) ;
}
static inline struct V_263 * F_138 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_263 ,
V_264 ) ;
}
static T_1 F_139 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_110 ,
F_138 ( V_3 ) -> V_265 ) ;
}
static T_1 F_140 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_263 * V_266 = F_138 ( V_3 ) ;
struct V_71 * V_72 = V_266 -> V_267 ;
unsigned long V_268 ;
int V_269 , V_29 ;
if ( ! V_266 -> V_270 ) {
F_11 ( L_203
L_204 , V_266 -> V_270 ) ;
return - V_17 ;
}
if ( ! ( V_72 -> V_98 & V_99 ) ) {
F_11 ( L_205
L_206 ) ;
return - V_100 ;
}
V_29 = F_130 ( V_5 , 0 , & V_268 ) ;
if ( V_29 < 0 ) {
F_11 ( L_207
L_11 , V_5 ) ;
return V_29 ;
}
V_269 = ( int ) V_268 ;
if ( ! ( V_266 -> V_271 & V_272 ) ) {
F_11 ( L_208
L_209 ) ;
return - V_17 ;
}
if ( V_266 -> V_271 & V_273 &&
V_269 == V_274 ) {
F_11 ( L_210
L_211 ) ;
return - V_17 ;
}
V_29 = F_141 ( V_266 , V_72 ,
NULL , NULL , V_269 , 0 ) ;
return ( ! V_29 ) ? V_11 : - V_17 ;
}
static T_1 F_142 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_263 * V_266 = F_138 ( V_3 ) ;
return sprintf ( V_5 , L_4 ,
F_143 ( V_266 -> V_275 ) ) ;
}
static T_1 F_144 (
struct V_2 * V_3 , const char * V_5 , T_2 V_11 )
{
struct V_263 * V_266 = F_138 ( V_3 ) ;
unsigned long V_268 ;
int V_276 , V_29 ;
if ( ! V_266 -> V_270 ) {
F_11 ( L_212
L_213 ,
V_266 -> V_270 ) ;
return - V_17 ;
}
V_29 = F_130 ( V_5 , 0 , & V_268 ) ;
if ( V_29 < 0 ) {
F_11 ( L_214
L_215 , V_5 ) ;
return V_29 ;
}
V_276 = ( int ) V_268 ;
if ( ( V_276 != V_277 ) &&
( V_276 != V_278 ) &&
( V_276 != V_279 ) ) {
F_11 ( L_216 ,
V_276 ) ;
return - V_17 ;
}
V_266 -> V_275 = V_276 ;
return V_11 ;
}
static T_1 F_145 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_146 ( F_138 ( V_3 ) , V_5 ) ;
}
static T_1 F_147 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
return F_148 ( F_138 ( V_3 ) , V_5 , V_11 ) ;
}
static T_1 F_149 (
struct V_2 * V_3 , char * V_5 )
{
return sprintf ( V_5 , L_110 ,
F_138 ( V_3 ) -> V_280 ) ;
}
static T_1 F_150 (
struct V_2 * V_3 , const char * V_5 , T_2 V_11 )
{
struct V_263 * V_266 = F_138 ( V_3 ) ;
unsigned long V_268 ;
int V_29 ;
V_29 = F_130 ( V_5 , 0 , & V_268 ) ;
if ( V_29 < 0 ) {
F_11 ( L_217 ) ;
return V_29 ;
}
if ( ( V_268 != 0 ) && ( V_268 != 1 ) ) {
F_11 ( L_218
L_219 , V_268 ) ;
return - V_17 ;
}
V_266 -> V_280 = ( int ) V_268 ;
return V_11 ;
}
static T_1 F_151 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_152 ( F_138 ( V_3 ) , V_5 ) ;
}
static T_1 F_153 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
return F_154 ( F_138 ( V_3 ) , V_5 ,
V_11 ) ;
}
static T_1 F_155 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_156 ( F_138 ( V_3 ) , V_5 ) ;
}
static T_1 F_157 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
return F_158 ( F_138 ( V_3 ) , V_5 ,
V_11 ) ;
}
static T_1 F_159 (
struct V_2 * V_3 , char * V_5 )
{
return F_160 ( F_138 ( V_3 ) , V_5 ) ;
}
static T_1 F_161 (
struct V_2 * V_3 , const char * V_5 , T_2 V_11 )
{
return F_162 ( F_138 ( V_3 ) , V_5 ,
V_11 ) ;
}
static T_1 F_163 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_164 ( F_138 ( V_3 ) , V_5 ) ;
}
static T_1 F_165 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
return F_166 ( F_138 ( V_3 ) , V_5 , V_11 ) ;
}
static T_1 F_167 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_263 * V_266 = F_138 ( V_3 ) ;
if ( ! V_266 -> V_270 )
return 0 ;
return sprintf ( V_5 , L_189 , V_266 -> V_281 ) ;
}
static T_1 F_168 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_263 * V_266 = F_138 ( V_3 ) ;
struct V_27 * V_282 = & V_266 -> V_264 ;
unsigned long V_281 ;
int V_29 ;
V_29 = F_130 ( V_5 , 0 , & V_281 ) ;
if ( V_29 < 0 ) {
F_11 ( L_220 ,
V_5 ) ;
return V_29 ;
}
if ( V_281 > 0x0000ffff ) {
F_11 ( L_221 ,
V_281 ) ;
return - V_17 ;
}
V_29 = F_169 ( V_266 , ( T_7 ) V_281 ) ;
if ( V_29 < 0 )
return - V_17 ;
F_21 ( L_222
L_223 ,
F_27 ( & V_282 -> V_34 ) ,
V_266 -> V_281 ) ;
return V_11 ;
}
static T_1 F_170 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_263 * V_266 = F_138 ( V_3 ) ;
struct V_283 * V_284 ;
T_1 V_131 = 0 , V_258 ;
unsigned char V_122 [ V_285 ] ;
memset ( V_122 , 0 , V_285 ) ;
F_76 ( & V_266 -> V_286 ) ;
F_18 (lun, &tg_pt_gp->tg_pt_gp_lun_list,
lun_tg_pt_gp_link) {
struct V_153 * V_287 = V_284 -> V_288 ;
V_258 = snprintf ( V_122 , V_285 , L_224
L_225 , V_287 -> V_144 -> V_40 () ,
V_287 -> V_144 -> V_41 ( V_287 ) ,
V_287 -> V_144 -> V_42 ( V_287 ) ,
F_27 ( & V_284 -> V_289 . V_34 ) ) ;
V_258 ++ ;
if ( ( V_258 + V_131 ) > V_116 ) {
F_50 ( L_197
L_198 ) ;
break;
}
memcpy ( V_5 + V_131 , V_122 , V_258 ) ;
V_131 += V_258 ;
}
F_78 ( & V_266 -> V_286 ) ;
return V_131 ;
}
static void F_171 ( struct V_2 * V_3 )
{
struct V_263 * V_266 = F_2 ( F_3 ( V_3 ) ,
struct V_263 , V_264 ) ;
F_172 ( V_266 ) ;
}
static struct V_27 * F_173 (
struct V_27 * V_28 ,
const char * V_23 )
{
struct V_229 * V_290 = F_2 ( V_28 , struct V_229 ,
V_291 ) ;
struct V_263 * V_266 ;
struct V_27 * V_282 = NULL ;
struct V_2 * V_292 = NULL ;
V_266 = F_174 ( V_290 -> V_121 , V_23 , 0 ) ;
if ( ! V_266 )
return NULL ;
V_282 = & V_266 -> V_264 ;
V_292 = & V_282 -> V_34 ;
F_24 ( V_282 , V_23 ,
& V_293 ) ;
F_21 ( L_226
L_227 ,
F_27 ( V_292 ) ) ;
return V_282 ;
}
static void F_175 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
struct V_263 * V_266 = F_2 ( F_3 ( V_3 ) ,
struct V_263 , V_264 ) ;
F_21 ( L_228
L_229 ,
F_27 ( V_3 ) , V_266 -> V_281 ) ;
F_30 ( V_3 ) ;
}
static struct V_27 * F_176 (
struct V_27 * V_28 ,
const char * V_23 )
{
return F_23 ( - V_90 ) ;
}
static void F_177 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
return;
}
static struct V_27 * F_178 (
struct V_27 * V_28 ,
const char * V_23 )
{
struct V_263 * V_266 ;
struct V_2 * V_294 = & V_28 -> V_34 ;
struct V_1 * V_206 = F_1 ( V_294 ) ;
struct V_295 * V_296 = V_206 -> V_297 ;
struct V_71 * V_72 ;
int V_298 = - V_66 , V_29 ;
V_29 = F_179 ( & V_206 -> V_299 ) ;
if ( V_29 )
return F_23 ( V_29 ) ;
V_72 = F_180 ( V_206 , V_23 ) ;
if ( ! V_72 )
goto V_154;
F_24 ( & V_72 -> V_74 , V_23 , & V_296 -> V_300 ) ;
F_24 ( & V_72 -> V_107 . V_70 , L_230 ,
& V_296 -> V_301 ) ;
F_25 ( & V_72 -> V_107 . V_70 , & V_72 -> V_74 ) ;
F_24 ( & V_72 -> V_134 , L_231 ,
& V_296 -> V_302 ) ;
F_25 ( & V_72 -> V_134 , & V_72 -> V_74 ) ;
F_24 ( & V_72 -> V_75 . V_119 , L_232 ,
& V_296 -> V_303 ) ;
F_25 ( & V_72 -> V_75 . V_119 ,
& V_72 -> V_74 ) ;
F_24 ( & V_72 -> V_229 . V_291 ,
L_233 , & V_296 -> V_304 ) ;
F_25 ( & V_72 -> V_229 . V_291 ,
& V_72 -> V_74 ) ;
F_24 ( & V_72 -> V_305 . V_306 ,
L_234 , & V_296 -> V_307 ) ;
F_25 ( & V_72 -> V_305 . V_306 ,
& V_72 -> V_74 ) ;
V_266 = F_174 ( V_72 , L_235 , 1 ) ;
if ( ! V_266 )
goto V_308;
V_72 -> V_229 . V_309 = V_266 ;
F_24 ( & V_266 -> V_264 ,
L_235 , & V_293 ) ;
F_25 ( & V_266 -> V_264 ,
& V_72 -> V_229 . V_291 ) ;
F_181 ( V_72 ) ;
F_10 ( & V_206 -> V_299 ) ;
return & V_72 -> V_74 ;
V_308:
F_126 ( V_72 ) ;
V_154:
F_10 ( & V_206 -> V_299 ) ;
return F_23 ( V_298 ) ;
}
static void F_182 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
struct V_27 * V_255 = F_3 ( V_3 ) ;
struct V_71 * V_72 =
F_2 ( V_255 , struct V_71 , V_74 ) ;
struct V_1 * V_206 ;
V_206 = F_1 ( & V_72 -> V_1 -> V_4 . V_34 ) ;
F_8 ( & V_206 -> V_299 ) ;
F_29 ( & V_72 -> V_305 . V_306 ) ;
F_29 ( & V_72 -> V_229 . V_291 ) ;
V_72 -> V_229 . V_309 = NULL ;
F_29 ( V_255 ) ;
F_30 ( V_3 ) ;
F_10 ( & V_206 -> V_299 ) ;
}
static inline struct V_1 * F_183 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static T_1 F_184 ( struct V_2 * V_3 , char * V_5 )
{
struct V_1 * V_206 = F_183 ( V_3 ) ;
return sprintf ( V_5 , L_236 ,
V_206 -> V_310 , V_206 -> V_297 -> V_311 -> V_23 ,
V_7 ) ;
}
static T_1 F_185 ( struct V_2 * V_3 , char * V_5 )
{
struct V_1 * V_206 = F_183 ( V_3 ) ;
int V_312 = 0 ;
if ( V_206 -> V_313 & V_314 )
V_312 = 1 ;
return sprintf ( V_5 , L_110 , V_312 ) ;
}
static T_1 F_186 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_1 * V_206 = F_183 ( V_3 ) ;
unsigned long V_315 ;
int V_29 ;
if ( V_206 -> V_297 -> V_311 -> V_316 == NULL )
return - V_17 ;
V_29 = F_130 ( V_5 , 0 , & V_315 ) ;
if ( V_29 < 0 ) {
F_11 ( L_237 , V_29 ) ;
return V_29 ;
}
if ( V_206 -> V_317 ) {
F_11 ( L_238 ) ;
return - V_17 ;
}
V_29 = V_206 -> V_297 -> V_311 -> V_316 ( V_206 , V_315 ) ;
if ( V_29 < 0 )
return - V_17 ;
if ( V_29 > 0 )
V_206 -> V_313 |= V_314 ;
else if ( V_29 == 0 )
V_206 -> V_313 &= ~ V_314 ;
return V_11 ;
}
static void F_187 ( struct V_2 * V_3 )
{
struct V_1 * V_206 = F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
F_188 ( V_206 ) ;
}
static struct V_27 * F_189 (
struct V_27 * V_28 ,
const char * V_23 )
{
char * V_318 , * V_319 , * V_320 ;
struct V_1 * V_206 ;
char V_122 [ V_321 ] ;
unsigned long V_322 = 0 ;
int V_29 ;
memset ( V_122 , 0 , V_321 ) ;
if ( strlen ( V_23 ) >= V_321 ) {
F_11 ( L_239
L_240 , ( int ) strlen ( V_23 ) ,
V_321 ) ;
return F_23 ( - V_323 ) ;
}
snprintf ( V_122 , V_321 , L_7 , V_23 ) ;
V_319 = strstr ( V_122 , L_241 ) ;
if ( ! V_319 ) {
F_11 ( L_242 ) ;
return F_23 ( - V_17 ) ;
}
V_318 = V_122 ;
V_320 = strstr ( V_319 + 1 , L_241 ) ;
if ( V_320 ) {
* V_320 = '\0' ;
V_320 ++ ;
V_319 = V_320 ;
} else {
* V_319 = '\0' ;
V_319 ++ ;
}
V_29 = F_130 ( V_319 , 0 , & V_322 ) ;
if ( V_29 < 0 ) {
F_11 ( L_190
L_243 , V_29 ) ;
return F_23 ( V_29 ) ;
}
F_190 () ;
V_206 = F_191 ( V_318 , V_322 , 0 ) ;
if ( F_13 ( V_206 ) )
return F_192 ( V_206 ) ;
F_24 ( & V_206 -> V_4 , V_23 ,
& V_324 ) ;
return & V_206 -> V_4 ;
}
static void F_193 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
F_30 ( V_3 ) ;
}
void F_194 ( struct V_295 * V_296 )
{
F_195 ( V_296 ) ;
F_196 ( V_296 ) ;
F_197 ( V_296 ) ;
F_198 ( V_296 ) ;
F_199 ( V_296 ) ;
F_200 ( V_296 ) ;
}
static int T_8 F_201 ( void )
{
struct V_325 * V_326 = & V_36 ;
struct V_212 * V_213 ;
int V_29 ;
F_21 ( L_244
L_245 V_6 L_3 ,
V_7 , F_5 () -> V_8 , F_5 () -> V_9 ) ;
F_202 ( & V_326 -> V_327 ) ;
F_203 ( & V_326 -> V_328 ) ;
V_29 = F_204 () ;
if ( V_29 < 0 )
return V_29 ;
F_24 ( & V_329 , L_246 ,
& V_330 ) ;
F_25 ( & V_329 , & V_326 -> V_327 ) ;
F_24 ( & V_331 , L_233 , & V_332 ) ;
F_25 ( & V_331 , & V_329 ) ;
F_24 ( & V_333 , L_247 ,
& V_334 ) ;
F_25 ( & V_333 , & V_331 ) ;
V_213 = F_136 ( L_248 , 1 ) ;
if ( F_13 ( V_213 ) ) {
V_29 = - V_66 ;
goto V_335;
}
F_24 ( & V_213 -> V_218 , L_248 ,
& V_262 ) ;
F_25 ( & V_213 -> V_218 , & V_333 ) ;
V_336 = V_213 ;
V_29 = F_205 ( V_326 ) ;
if ( V_29 < 0 ) {
F_11 ( L_249 ,
V_29 , V_326 -> V_327 . V_34 . V_337 ) ;
goto V_335;
}
F_21 ( L_250
L_251 V_7 L_252
L_253 V_6 L_3 , F_5 () -> V_8 , F_5 () -> V_9 ) ;
V_29 = F_206 () ;
if ( V_29 < 0 )
goto V_183;
V_29 = F_207 () ;
if ( V_29 < 0 )
goto V_183;
V_29 = F_208 () ;
if ( V_29 < 0 )
goto V_183;
return 0 ;
V_183:
F_209 ( V_326 ) ;
F_210 () ;
F_211 () ;
V_335:
if ( V_336 ) {
F_134 ( V_336 ) ;
V_336 = NULL ;
}
F_212 () ;
return V_29 ;
}
static void T_9 F_213 ( void )
{
F_29 ( & V_333 ) ;
F_29 ( & V_331 ) ;
F_29 ( & V_329 ) ;
F_209 ( & V_36 ) ;
F_134 ( V_336 ) ;
V_336 = NULL ;
F_21 ( L_254
L_255 ) ;
F_210 () ;
F_211 () ;
F_214 () ;
F_212 () ;
}
