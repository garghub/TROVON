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
static struct V_75 * F_69 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_75 , V_114 ) ;
}
static T_1 F_70 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_110 ,
& F_69 ( V_3 ) -> V_115 [ 0 ] ) ;
}
static T_1 F_71 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_75 * V_75 = F_69 ( V_3 ) ;
struct V_71 * V_72 = V_75 -> V_116 ;
unsigned char V_117 [ V_118 ] ;
if ( V_72 -> V_98 & V_119 ) {
F_11 ( L_111
L_112 ) ;
return - V_120 ;
}
if ( strlen ( V_5 ) >= V_118 ) {
F_11 ( L_113
L_114 , V_118 ) ;
return - V_121 ;
}
if ( V_72 -> V_80 ) {
F_11 ( L_115
L_116 ,
V_72 -> V_80 ) ;
return - V_17 ;
}
memset ( V_117 , 0 , V_118 ) ;
snprintf ( V_117 , V_118 , L_7 , V_5 ) ;
snprintf ( V_72 -> V_75 . V_115 , V_118 ,
L_7 , F_72 ( V_117 ) ) ;
V_72 -> V_98 |= V_122 ;
F_21 ( L_117
L_11 , V_72 -> V_75 . V_115 ) ;
return V_11 ;
}
static T_1 F_73 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_75 * V_75 = F_69 ( V_3 ) ;
struct V_123 * V_124 ;
unsigned char V_117 [ V_125 ] ;
T_1 V_126 = 0 ;
memset ( V_117 , 0 , V_125 ) ;
F_74 ( & V_75 -> V_127 ) ;
F_18 (vpd, &t10_wwn->t10_vpd_list, vpd_list) {
if ( ! V_124 -> V_128 )
continue;
F_75 ( V_124 , V_117 , V_125 ) ;
if ( V_126 + strlen ( V_117 ) >= V_129 )
break;
V_126 += sprintf ( V_5 + V_126 , L_7 , V_117 ) ;
}
F_76 ( & V_75 -> V_127 ) ;
return V_126 ;
}
static struct V_71 * F_77 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_71 ,
V_130 ) ;
}
static T_1 F_78 ( struct V_71 * V_72 ,
char * V_5 )
{
struct V_131 * V_132 ;
struct V_133 * V_134 ;
char V_135 [ V_136 ] ;
memset ( V_135 , 0 , V_136 ) ;
V_134 = V_72 -> V_137 ;
if ( ! V_134 )
return sprintf ( V_5 , L_118 ) ;
V_132 = V_134 -> V_138 ;
F_79 ( V_134 , V_135 , V_136 ) ;
return sprintf ( V_5 , L_119 ,
V_132 -> V_139 -> V_140 -> V_40 () ,
V_132 -> V_141 , V_135 ) ;
}
static T_1 F_80 ( struct V_71 * V_72 ,
char * V_5 )
{
struct V_131 * V_132 ;
T_1 V_126 ;
V_132 = V_72 -> V_142 ;
if ( V_132 ) {
V_126 = sprintf ( V_5 ,
L_120 ,
V_132 -> V_139 -> V_140 -> V_40 () ,
V_132 -> V_141 ) ;
} else {
V_126 = sprintf ( V_5 , L_121 ) ;
}
return V_126 ;
}
static T_1 F_81 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_77 ( V_3 ) ;
int V_29 ;
if ( V_72 -> V_81 -> V_143 & V_144 )
return sprintf ( V_5 , L_122 ) ;
F_74 ( & V_72 -> V_145 ) ;
if ( V_72 -> V_146 & V_147 )
V_29 = F_80 ( V_72 , V_5 ) ;
else
V_29 = F_78 ( V_72 , V_5 ) ;
F_76 ( & V_72 -> V_145 ) ;
return V_29 ;
}
static T_1 F_82 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_77 ( V_3 ) ;
T_1 V_126 = 0 ;
F_74 ( & V_72 -> V_145 ) ;
if ( ! V_72 -> V_137 ) {
V_126 = sprintf ( V_5 , L_118 ) ;
} else if ( V_72 -> V_137 -> V_148 ) {
V_126 = sprintf ( V_5 , L_123
L_124 ) ;
} else {
V_126 = sprintf ( V_5 , L_125
L_126 ) ;
}
F_76 ( & V_72 -> V_145 ) ;
return V_126 ;
}
static T_1 F_83 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_127 , F_77 ( V_3 ) -> V_149 . V_150 ) ;
}
static T_1 F_84 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_77 ( V_3 ) ;
struct V_131 * V_132 ;
struct V_151 * V_139 ;
struct V_133 * V_134 ;
const struct V_37 * V_38 ;
T_1 V_126 = 0 ;
F_74 ( & V_72 -> V_145 ) ;
V_134 = V_72 -> V_137 ;
if ( ! V_134 ) {
V_126 = sprintf ( V_5 , L_118 ) ;
goto V_152;
}
V_132 = V_134 -> V_138 ;
V_139 = V_132 -> V_139 ;
V_38 = V_139 -> V_140 ;
V_126 += sprintf ( V_5 + V_126 , L_128
L_129 , V_38 -> V_40 () ,
V_38 -> V_41 ( V_139 ) ) ;
V_126 += sprintf ( V_5 + V_126 , L_130
L_131
L_132 , V_134 -> V_153 ,
V_38 -> V_40 () , V_38 -> V_42 ( V_139 ) ,
V_38 -> V_40 () , V_134 -> V_154 ) ;
V_152:
F_76 ( & V_72 -> V_145 ) ;
return V_126 ;
}
static T_1 F_85 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_77 ( V_3 ) ;
const struct V_37 * V_38 ;
struct V_133 * V_134 ;
unsigned char V_117 [ 384 ] ;
char V_135 [ V_136 ] ;
T_1 V_126 = 0 ;
int V_155 = 0 ;
V_126 += sprintf ( V_5 + V_126 , L_133 ) ;
F_74 ( & V_72 -> V_149 . V_156 ) ;
F_18 (pr_reg, &dev->t10_pr.registration_list,
pr_reg_list) {
memset ( V_117 , 0 , 384 ) ;
memset ( V_135 , 0 , V_136 ) ;
V_38 = V_134 -> V_138 -> V_139 -> V_140 ;
F_79 ( V_134 , V_135 ,
V_136 ) ;
sprintf ( V_117 , L_134 ,
V_38 -> V_40 () ,
V_134 -> V_138 -> V_141 , V_135 , V_134 -> V_157 ,
V_134 -> V_158 ) ;
if ( V_126 + strlen ( V_117 ) >= V_129 )
break;
V_126 += sprintf ( V_5 + V_126 , L_7 , V_117 ) ;
V_155 ++ ;
}
F_76 ( & V_72 -> V_149 . V_156 ) ;
if ( ! V_155 )
V_126 += sprintf ( V_5 + V_126 , L_135 ) ;
return V_126 ;
}
static T_1 F_86 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_77 ( V_3 ) ;
struct V_133 * V_134 ;
T_1 V_126 = 0 ;
F_74 ( & V_72 -> V_145 ) ;
V_134 = V_72 -> V_137 ;
if ( V_134 ) {
V_126 = sprintf ( V_5 , L_136 ,
F_87 ( V_134 -> V_159 ) ) ;
} else {
V_126 = sprintf ( V_5 , L_118 ) ;
}
F_76 ( & V_72 -> V_145 ) ;
return V_126 ;
}
static T_1 F_88 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_77 ( V_3 ) ;
if ( V_72 -> V_81 -> V_143 & V_144 )
return sprintf ( V_5 , L_137 ) ;
else if ( V_72 -> V_146 & V_147 )
return sprintf ( V_5 , L_138 ) ;
else
return sprintf ( V_5 , L_139 ) ;
}
static T_1 F_89 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_77 ( V_3 ) ;
if ( V_72 -> V_81 -> V_143 & V_144 )
return 0 ;
return sprintf ( V_5 , L_140 ,
( V_72 -> V_149 . V_160 ) ? L_141 : L_70 ) ;
}
static T_1 F_90 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_71 * V_72 = F_77 ( V_3 ) ;
if ( V_72 -> V_81 -> V_143 & V_144 )
return 0 ;
return sprintf ( V_5 , L_142 ) ;
}
static T_1 F_91 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_77 ( V_3 ) ;
unsigned char * V_161 = NULL , * V_162 = NULL , * V_163 = NULL ;
unsigned char * V_164 = NULL , * V_165 = NULL ;
char * V_166 , * V_167 , * V_168 ;
T_4 args [ V_169 ] ;
unsigned long long V_170 ;
T_5 V_171 = 0 ;
T_5 V_172 = 0 , V_173 = 0 ;
int V_29 = - 1 , V_174 = 0 , V_175 = 0 , V_176 , V_177 ;
T_6 V_178 = 0 ;
T_7 type = 0 ;
if ( V_72 -> V_81 -> V_143 & V_144 )
return V_11 ;
if ( V_72 -> V_146 & V_147 )
return V_11 ;
if ( V_72 -> V_80 ) {
F_21 ( L_143
L_144 ) ;
return - V_17 ;
}
V_168 = F_92 ( V_5 , V_64 ) ;
if ( ! V_168 )
return - V_66 ;
V_166 = V_168 ;
while ( ( V_167 = F_93 ( & V_168 , L_145 ) ) != NULL ) {
if ( ! * V_167 )
continue;
V_177 = F_94 ( V_167 , V_179 , args ) ;
switch ( V_177 ) {
case V_180 :
V_161 = F_95 ( args ) ;
if ( ! V_161 ) {
V_29 = - V_66 ;
goto V_181;
}
break;
case V_182 :
V_162 = F_95 ( args ) ;
if ( ! V_162 ) {
V_29 = - V_66 ;
goto V_181;
}
if ( strlen ( V_162 ) >= V_183 ) {
F_11 ( L_146
L_147 ,
V_183 ) ;
V_29 = - V_17 ;
break;
}
break;
case V_184 :
V_163 = F_95 ( args ) ;
if ( ! V_163 ) {
V_29 = - V_66 ;
goto V_181;
}
if ( strlen ( V_163 ) >= V_185 ) {
F_11 ( L_148
L_149 ,
V_185 ) ;
V_29 = - V_17 ;
break;
}
break;
case V_186 :
V_29 = F_96 ( args -> V_187 , 0 , & V_170 ) ;
if ( V_29 < 0 ) {
F_11 ( L_150 ) ;
goto V_181;
}
V_171 = ( T_5 ) V_170 ;
break;
case V_188 :
V_29 = F_97 ( args , & V_176 ) ;
if ( V_29 )
goto V_181;
V_174 = V_176 ;
break;
case V_189 :
V_29 = F_97 ( args , & V_176 ) ;
if ( V_29 )
goto V_181;
type = ( T_7 ) V_176 ;
break;
case V_190 :
V_29 = F_97 ( args , & V_176 ) ;
if ( V_29 )
goto V_181;
break;
case V_191 :
V_29 = F_97 ( args , & V_176 ) ;
if ( V_29 )
goto V_181;
V_175 = ( int ) V_176 ;
break;
case V_192 :
V_29 = F_97 ( args , & V_176 ) ;
if ( V_29 )
goto V_181;
V_172 = ( T_5 ) V_176 ;
break;
case V_193 :
V_164 = F_95 ( args ) ;
if ( ! V_164 ) {
V_29 = - V_66 ;
goto V_181;
}
break;
case V_194 :
V_165 = F_95 ( args ) ;
if ( ! V_165 ) {
V_29 = - V_66 ;
goto V_181;
}
if ( strlen ( V_165 ) >= V_195 ) {
F_11 ( L_151
L_152 ,
V_195 ) ;
V_29 = - V_17 ;
break;
}
break;
case V_196 :
V_29 = F_97 ( args , & V_176 ) ;
if ( V_29 )
goto V_181;
V_178 = ( T_6 ) V_176 ;
break;
case V_197 :
V_29 = F_97 ( args , & V_176 ) ;
if ( V_29 )
goto V_181;
break;
case V_198 :
V_29 = F_97 ( args , & V_176 ) ;
if ( V_29 )
goto V_181;
V_173 = ( T_5 ) V_176 ;
break;
default:
break;
}
}
if ( ! V_162 || ! V_165 || ! V_171 ) {
F_11 ( L_153 ) ;
V_29 = - V_17 ;
goto V_181;
}
if ( V_174 && ! ( type ) ) {
F_11 ( L_154
L_155 , type ) ;
V_29 = - V_17 ;
goto V_181;
}
V_29 = F_98 ( & V_72 -> V_149 , V_171 ,
V_162 , V_163 , V_172 , V_165 , V_178 , V_173 ,
V_174 , V_175 , type ) ;
V_181:
F_47 ( V_161 ) ;
F_47 ( V_162 ) ;
F_47 ( V_163 ) ;
F_47 ( V_164 ) ;
F_47 ( V_165 ) ;
F_47 ( V_166 ) ;
return ( V_29 == 0 ) ? V_11 : V_29 ;
}
static inline struct V_71 * F_99 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_71 , V_74 ) ;
}
static T_1 F_100 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_99 ( V_3 ) ;
int V_199 = 0 ;
T_1 V_12 = 0 ;
F_101 ( V_72 , V_5 , & V_199 ) ;
V_12 += V_199 ;
V_12 += V_72 -> V_81 -> V_200 ( V_72 ,
V_5 + V_12 ) ;
return V_12 ;
}
static T_1 F_102 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_99 ( V_3 ) ;
return V_72 -> V_81 -> V_201 ( V_72 , V_5 , V_11 ) ;
}
static T_1 F_103 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_99 ( V_3 ) ;
if ( ! ( V_72 -> V_98 & V_202 ) )
return 0 ;
return snprintf ( V_5 , V_129 , L_4 , V_72 -> V_203 ) ;
}
static T_1 F_104 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_99 ( V_3 ) ;
struct V_1 * V_204 = V_72 -> V_1 ;
T_1 V_12 ;
if ( V_11 > ( V_205 - 1 ) ) {
F_11 ( L_156
L_157 , ( int ) V_11 ,
V_205 - 1 ) ;
return - V_17 ;
}
V_12 = snprintf ( & V_72 -> V_203 [ 0 ] , V_205 , L_7 , V_5 ) ;
if ( ! V_12 )
return - V_17 ;
if ( V_72 -> V_203 [ V_12 - 1 ] == '\n' )
V_72 -> V_203 [ V_12 - 1 ] = '\0' ;
V_72 -> V_98 |= V_202 ;
F_21 ( L_158 ,
F_27 ( & V_204 -> V_4 . V_34 ) ,
F_27 ( & V_72 -> V_74 . V_34 ) ,
V_72 -> V_203 ) ;
return V_12 ;
}
static T_1 F_105 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_99 ( V_3 ) ;
if ( ! ( V_72 -> V_98 & V_206 ) )
return 0 ;
return snprintf ( V_5 , V_129 , L_4 , V_72 -> V_207 ) ;
}
static T_1 F_106 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_99 ( V_3 ) ;
struct V_1 * V_204 = V_72 -> V_1 ;
T_1 V_12 ;
if ( V_11 > ( V_208 - 1 ) ) {
F_11 ( L_159
L_160 , ( int ) V_11 ,
V_208 - 1 ) ;
return - V_17 ;
}
V_12 = snprintf ( & V_72 -> V_207 [ 0 ] , V_208 ,
L_7 , V_5 ) ;
if ( ! V_12 )
return - V_17 ;
if ( V_72 -> V_207 [ V_12 - 1 ] == '\n' )
V_72 -> V_207 [ V_12 - 1 ] = '\0' ;
V_72 -> V_98 |= V_206 ;
F_21 ( L_161 ,
F_27 ( & V_204 -> V_4 . V_34 ) ,
F_27 ( & V_72 -> V_74 . V_34 ) ,
V_72 -> V_207 ) ;
return V_12 ;
}
static T_1 F_107 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_99 ( V_3 ) ;
return snprintf ( V_5 , V_129 , L_162 , ! ! ( V_72 -> V_98 & V_99 ) ) ;
}
static T_1 F_108 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_99 ( V_3 ) ;
char * V_167 ;
int V_29 ;
V_167 = strstr ( V_5 , L_163 ) ;
if ( ! V_167 ) {
F_11 ( L_164
L_165 ) ;
return - V_17 ;
}
V_29 = F_109 ( V_72 ) ;
if ( V_29 )
return V_29 ;
return V_11 ;
}
static T_1 F_110 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_99 ( V_3 ) ;
struct V_2 * V_209 ;
struct V_210 * V_211 ;
struct V_212 * V_213 ;
T_1 V_126 = 0 ;
V_213 = V_72 -> V_214 ;
if ( ! V_213 )
return 0 ;
F_74 ( & V_213 -> V_215 ) ;
V_211 = V_213 -> V_211 ;
if ( V_211 ) {
V_209 = & V_211 -> V_216 . V_34 ;
V_126 += sprintf ( V_5 , L_166 ,
F_27 ( V_209 ) , V_211 -> V_217 ) ;
}
F_76 ( & V_213 -> V_215 ) ;
return V_126 ;
}
static T_1 F_111 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_99 ( V_3 ) ;
struct V_1 * V_204 = V_72 -> V_1 ;
struct V_210 * V_211 = NULL , * V_218 = NULL ;
struct V_212 * V_213 ;
unsigned char V_117 [ V_219 ] ;
int V_220 = 0 ;
V_213 = V_72 -> V_214 ;
if ( ! V_213 )
return V_11 ;
if ( V_11 > V_219 ) {
F_11 ( L_167 ) ;
return - V_17 ;
}
memset ( V_117 , 0 , V_219 ) ;
memcpy ( V_117 , V_5 , V_11 ) ;
if ( strcmp ( F_72 ( V_117 ) , L_168 ) ) {
V_218 = F_112 ( F_72 ( V_117 ) ) ;
if ( ! V_218 )
return - V_100 ;
}
F_74 ( & V_213 -> V_215 ) ;
V_211 = V_213 -> V_211 ;
if ( V_211 ) {
if ( ! V_218 ) {
F_21 ( L_169
L_170
L_171 ,
F_27 ( & V_204 -> V_4 . V_34 ) ,
F_27 ( & V_72 -> V_74 . V_34 ) ,
F_27 ( & V_211 -> V_216 . V_34 ) ,
V_211 -> V_217 ) ;
F_113 ( V_213 , V_211 ) ;
F_76 ( & V_213 -> V_215 ) ;
return V_11 ;
}
F_113 ( V_213 , V_211 ) ;
V_220 = 1 ;
}
F_114 ( V_213 , V_218 ) ;
F_76 ( & V_213 -> V_215 ) ;
F_21 ( L_172
L_173 ,
( V_220 ) ? L_174 : L_175 ,
F_27 ( & V_204 -> V_4 . V_34 ) ,
F_27 ( & V_72 -> V_74 . V_34 ) ,
F_27 ( & V_218 -> V_216 . V_34 ) ,
V_218 -> V_217 ) ;
F_115 ( V_218 ) ;
return V_11 ;
}
static T_1 F_116 ( struct V_2 * V_3 , char * V_5 )
{
struct V_71 * V_72 = F_99 ( V_3 ) ;
struct V_221 * V_222 ;
struct V_223 * V_224 ;
char * V_225 = V_5 ;
int V_199 = 0 ;
char V_226 ;
F_74 ( & V_72 -> V_227 . V_228 ) ;
if ( ! F_9 ( & V_72 -> V_227 . V_229 ) )
V_199 += sprintf ( V_225 + V_199 , L_176 ,
V_72 -> V_227 . V_230 ,
V_72 -> V_227 . V_231 ) ;
F_18 (map, &dev->t10_alua.lba_map_list, lba_map_list) {
V_199 += sprintf ( V_225 + V_199 , L_177 ,
V_222 -> V_232 , V_222 -> V_233 ) ;
F_18 (mem, &map->lba_map_mem_list,
lba_map_mem_list) {
switch ( V_224 -> V_234 ) {
case V_235 :
V_226 = 'O' ;
break;
case V_236 :
V_226 = 'A' ;
break;
case V_237 :
V_226 = 'S' ;
break;
case V_238 :
V_226 = 'U' ;
break;
default:
V_226 = '.' ;
break;
}
V_199 += sprintf ( V_225 + V_199 , L_178 ,
V_224 -> V_239 , V_226 ) ;
}
V_199 += sprintf ( V_225 + V_199 , L_3 ) ;
}
F_76 ( & V_72 -> V_227 . V_228 ) ;
return V_199 ;
}
static T_1 F_117 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_71 * V_72 = F_99 ( V_3 ) ;
struct V_221 * V_240 = NULL ;
struct V_241 V_242 ;
char * V_243 , * V_166 , * V_167 ;
char V_226 ;
int V_244 = - 1 , V_245 ;
int V_29 = 0 , V_246 = 0 , V_247 , V_248 ;
unsigned long V_249 = - 1 , V_250 = - 1 ;
unsigned long V_251 = - 1 , V_252 = - 1 ;
V_166 = V_243 = F_92 ( V_5 , V_64 ) ;
if ( ! V_243 )
return - V_66 ;
F_38 ( & V_242 ) ;
while ( ( V_167 = F_93 ( & V_243 , L_3 ) ) != NULL ) {
if ( ! * V_167 )
continue;
if ( V_246 == 0 ) {
if ( sscanf ( V_167 , L_179 ,
& V_251 , & V_252 ) != 2 ) {
F_11 ( L_180 , V_246 ) ;
V_29 = - V_17 ;
break;
}
V_246 ++ ;
continue;
}
if ( sscanf ( V_167 , L_181 , & V_249 , & V_250 ) != 2 ) {
F_11 ( L_180 , V_246 ) ;
V_29 = - V_17 ;
break;
}
V_167 = strchr ( V_167 , ' ' ) ;
if ( ! V_167 ) {
F_11 ( L_182 , V_246 ) ;
V_29 = - V_17 ;
break;
}
V_167 ++ ;
V_167 = strchr ( V_167 , ' ' ) ;
if ( ! V_167 ) {
F_11 ( L_183 ,
V_246 ) ;
V_29 = - V_17 ;
break;
}
V_167 ++ ;
V_240 = F_118 ( & V_242 ,
V_249 , V_250 ) ;
if ( F_13 ( V_240 ) ) {
V_29 = F_119 ( V_240 ) ;
break;
}
V_245 = 0 ;
while ( sscanf ( V_167 , L_184 , & V_247 , & V_226 ) == 2 ) {
switch ( V_226 ) {
case 'O' :
V_248 = V_235 ;
break;
case 'A' :
V_248 = V_236 ;
break;
case 'S' :
V_248 = V_237 ;
break;
case 'U' :
V_248 = V_238 ;
break;
default:
F_11 ( L_185 , V_226 ) ;
V_29 = - V_17 ;
goto V_181;
}
V_29 = F_120 ( V_240 ,
V_247 , V_248 ) ;
if ( V_29 ) {
F_11 ( L_186
L_187 ,
V_247 , V_226 , V_246 ) ;
break;
}
V_245 ++ ;
V_167 = strchr ( V_167 , ' ' ) ;
if ( V_167 )
V_167 ++ ;
else
break;
}
if ( V_244 == - 1 )
V_244 = V_245 ;
else if ( V_245 != V_244 ) {
F_11 ( L_188
L_187 , V_245 , V_244 , V_246 ) ;
V_29 = - V_17 ;
break;
}
V_246 ++ ;
}
V_181:
if ( V_29 ) {
F_121 ( & V_242 ) ;
V_11 = V_29 ;
} else
F_122 ( V_72 , & V_242 ,
V_251 , V_252 ) ;
F_47 ( V_166 ) ;
return V_11 ;
}
static void F_123 ( struct V_2 * V_3 )
{
struct V_27 * V_253 = F_3 ( V_3 ) ;
struct V_71 * V_72 =
F_2 ( V_253 , struct V_71 , V_74 ) ;
F_124 ( V_72 ) ;
}
static inline struct V_210 * F_125 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_210 ,
V_216 ) ;
}
static T_1 F_126 ( struct V_2 * V_3 , char * V_5 )
{
struct V_210 * V_211 = F_125 ( V_3 ) ;
if ( ! V_211 -> V_254 )
return 0 ;
return sprintf ( V_5 , L_189 , V_211 -> V_217 ) ;
}
static T_1 F_127 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_210 * V_211 = F_125 ( V_3 ) ;
struct V_27 * V_255 = & V_211 -> V_216 ;
unsigned long V_217 ;
int V_29 ;
V_29 = F_128 ( V_5 , 0 , & V_217 ) ;
if ( V_29 < 0 ) {
F_11 ( L_190
L_191 , V_29 ) ;
return V_29 ;
}
if ( V_217 > 0x0000ffff ) {
F_11 ( L_192
L_193 , V_217 ) ;
return - V_17 ;
}
V_29 = F_129 ( V_211 , ( T_6 ) V_217 ) ;
if ( V_29 < 0 )
return - V_17 ;
F_21 ( L_194
L_195 ,
F_27 ( & V_255 -> V_34 ) ,
V_211 -> V_217 ) ;
return V_11 ;
}
static T_1 F_130 ( struct V_2 * V_3 , char * V_5 )
{
struct V_210 * V_211 = F_125 ( V_3 ) ;
struct V_71 * V_72 ;
struct V_1 * V_204 ;
struct V_212 * V_213 ;
T_1 V_126 = 0 , V_256 ;
unsigned char V_117 [ V_219 ] ;
memset ( V_117 , 0 , V_219 ) ;
F_74 ( & V_211 -> V_257 ) ;
F_18 (lu_gp_mem, &lu_gp->lu_gp_mem_list, lu_gp_mem_list) {
V_72 = V_213 -> V_258 ;
V_204 = V_72 -> V_1 ;
V_256 = snprintf ( V_117 , V_219 , L_196 ,
F_27 ( & V_204 -> V_4 . V_34 ) ,
F_27 ( & V_72 -> V_74 . V_34 ) ) ;
V_256 ++ ;
if ( ( V_256 + V_126 ) > V_129 ) {
F_50 ( L_197
L_198 ) ;
break;
}
memcpy ( V_5 + V_126 , V_117 , V_256 ) ;
V_126 += V_256 ;
}
F_76 ( & V_211 -> V_257 ) ;
return V_126 ;
}
static void F_131 ( struct V_2 * V_3 )
{
struct V_210 * V_211 = F_2 ( F_3 ( V_3 ) ,
struct V_210 , V_216 ) ;
F_132 ( V_211 ) ;
}
static struct V_27 * F_133 (
struct V_27 * V_28 ,
const char * V_23 )
{
struct V_210 * V_211 ;
struct V_27 * V_255 = NULL ;
struct V_2 * V_259 = NULL ;
V_211 = F_134 ( V_23 , 0 ) ;
if ( F_13 ( V_211 ) )
return NULL ;
V_255 = & V_211 -> V_216 ;
V_259 = & V_255 -> V_34 ;
F_24 ( V_255 , V_23 ,
& V_260 ) ;
F_21 ( L_199
L_200 ,
F_27 ( V_259 ) ) ;
return V_255 ;
}
static void F_135 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
struct V_210 * V_211 = F_2 ( F_3 ( V_3 ) ,
struct V_210 , V_216 ) ;
F_21 ( L_201
L_202 ,
F_27 ( V_3 ) , V_211 -> V_217 ) ;
F_30 ( V_3 ) ;
}
static inline struct V_261 * F_136 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_261 ,
V_262 ) ;
}
static T_1 F_137 ( struct V_2 * V_3 ,
char * V_5 )
{
return sprintf ( V_5 , L_162 ,
F_136 ( V_3 ) -> V_263 ) ;
}
static T_1 F_138 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_261 * V_264 = F_136 ( V_3 ) ;
struct V_71 * V_72 = V_264 -> V_265 ;
unsigned long V_266 ;
int V_267 , V_29 ;
if ( ! V_264 -> V_268 ) {
F_11 ( L_203
L_204 , V_264 -> V_268 ) ;
return - V_17 ;
}
if ( ! ( V_72 -> V_98 & V_99 ) ) {
F_11 ( L_205
L_206 ) ;
return - V_100 ;
}
V_29 = F_128 ( V_5 , 0 , & V_266 ) ;
if ( V_29 < 0 ) {
F_11 ( L_207
L_11 , V_5 ) ;
return V_29 ;
}
V_267 = ( int ) V_266 ;
if ( ! ( V_264 -> V_269 & V_270 ) ) {
F_11 ( L_208
L_209 ) ;
return - V_17 ;
}
if ( V_264 -> V_269 & V_271 &&
V_267 == V_272 ) {
F_11 ( L_210
L_211 ) ;
return - V_17 ;
}
V_29 = F_139 ( V_264 , V_72 ,
NULL , NULL , V_267 , 0 ) ;
return ( ! V_29 ) ? V_11 : - V_17 ;
}
static T_1 F_140 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_261 * V_264 = F_136 ( V_3 ) ;
return sprintf ( V_5 , L_4 ,
F_141 ( V_264 -> V_273 ) ) ;
}
static T_1 F_142 (
struct V_2 * V_3 , const char * V_5 , T_2 V_11 )
{
struct V_261 * V_264 = F_136 ( V_3 ) ;
unsigned long V_266 ;
int V_274 , V_29 ;
if ( ! V_264 -> V_268 ) {
F_11 ( L_212
L_213 ,
V_264 -> V_268 ) ;
return - V_17 ;
}
V_29 = F_128 ( V_5 , 0 , & V_266 ) ;
if ( V_29 < 0 ) {
F_11 ( L_214
L_215 , V_5 ) ;
return V_29 ;
}
V_274 = ( int ) V_266 ;
if ( ( V_274 != V_275 ) &&
( V_274 != V_276 ) &&
( V_274 != V_277 ) ) {
F_11 ( L_216 ,
V_274 ) ;
return - V_17 ;
}
V_264 -> V_273 = V_274 ;
return V_11 ;
}
static T_1 F_143 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_144 ( F_136 ( V_3 ) , V_5 ) ;
}
static T_1 F_145 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
return F_146 ( F_136 ( V_3 ) , V_5 , V_11 ) ;
}
static T_1 F_147 (
struct V_2 * V_3 , char * V_5 )
{
return sprintf ( V_5 , L_162 ,
F_136 ( V_3 ) -> V_278 ) ;
}
static T_1 F_148 (
struct V_2 * V_3 , const char * V_5 , T_2 V_11 )
{
struct V_261 * V_264 = F_136 ( V_3 ) ;
unsigned long V_266 ;
int V_29 ;
V_29 = F_128 ( V_5 , 0 , & V_266 ) ;
if ( V_29 < 0 ) {
F_11 ( L_217 ) ;
return V_29 ;
}
if ( ( V_266 != 0 ) && ( V_266 != 1 ) ) {
F_11 ( L_218
L_219 , V_266 ) ;
return - V_17 ;
}
V_264 -> V_278 = ( int ) V_266 ;
return V_11 ;
}
static T_1 F_149 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_150 ( F_136 ( V_3 ) , V_5 ) ;
}
static T_1 F_151 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
return F_152 ( F_136 ( V_3 ) , V_5 ,
V_11 ) ;
}
static T_1 F_153 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_154 ( F_136 ( V_3 ) , V_5 ) ;
}
static T_1 F_155 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
return F_156 ( F_136 ( V_3 ) , V_5 ,
V_11 ) ;
}
static T_1 F_157 (
struct V_2 * V_3 , char * V_5 )
{
return F_158 ( F_136 ( V_3 ) , V_5 ) ;
}
static T_1 F_159 (
struct V_2 * V_3 , const char * V_5 , T_2 V_11 )
{
return F_160 ( F_136 ( V_3 ) , V_5 ,
V_11 ) ;
}
static T_1 F_161 ( struct V_2 * V_3 ,
char * V_5 )
{
return F_162 ( F_136 ( V_3 ) , V_5 ) ;
}
static T_1 F_163 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
return F_164 ( F_136 ( V_3 ) , V_5 , V_11 ) ;
}
static T_1 F_165 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_261 * V_264 = F_136 ( V_3 ) ;
if ( ! V_264 -> V_268 )
return 0 ;
return sprintf ( V_5 , L_189 , V_264 -> V_279 ) ;
}
static T_1 F_166 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_261 * V_264 = F_136 ( V_3 ) ;
struct V_27 * V_280 = & V_264 -> V_262 ;
unsigned long V_279 ;
int V_29 ;
V_29 = F_128 ( V_5 , 0 , & V_279 ) ;
if ( V_29 < 0 ) {
F_11 ( L_220 ,
V_5 ) ;
return V_29 ;
}
if ( V_279 > 0x0000ffff ) {
F_11 ( L_221 ,
V_279 ) ;
return - V_17 ;
}
V_29 = F_167 ( V_264 , ( T_6 ) V_279 ) ;
if ( V_29 < 0 )
return - V_17 ;
F_21 ( L_222
L_223 ,
F_27 ( & V_280 -> V_34 ) ,
V_264 -> V_279 ) ;
return V_11 ;
}
static T_1 F_168 ( struct V_2 * V_3 ,
char * V_5 )
{
struct V_261 * V_264 = F_136 ( V_3 ) ;
struct V_281 * V_282 ;
T_1 V_126 = 0 , V_256 ;
unsigned char V_117 [ V_283 ] ;
memset ( V_117 , 0 , V_283 ) ;
F_74 ( & V_264 -> V_284 ) ;
F_18 (lun, &tg_pt_gp->tg_pt_gp_lun_list,
lun_tg_pt_gp_link) {
struct V_151 * V_285 = V_282 -> V_286 ;
V_256 = snprintf ( V_117 , V_283 , L_224
L_225 , V_285 -> V_140 -> V_40 () ,
V_285 -> V_140 -> V_41 ( V_285 ) ,
V_285 -> V_140 -> V_42 ( V_285 ) ,
F_27 ( & V_282 -> V_287 . V_34 ) ) ;
V_256 ++ ;
if ( ( V_256 + V_126 ) > V_129 ) {
F_50 ( L_197
L_198 ) ;
break;
}
memcpy ( V_5 + V_126 , V_117 , V_256 ) ;
V_126 += V_256 ;
}
F_76 ( & V_264 -> V_284 ) ;
return V_126 ;
}
static void F_169 ( struct V_2 * V_3 )
{
struct V_261 * V_264 = F_2 ( F_3 ( V_3 ) ,
struct V_261 , V_262 ) ;
F_170 ( V_264 ) ;
}
static struct V_27 * F_171 (
struct V_27 * V_28 ,
const char * V_23 )
{
struct V_227 * V_288 = F_2 ( V_28 , struct V_227 ,
V_289 ) ;
struct V_261 * V_264 ;
struct V_27 * V_280 = NULL ;
struct V_2 * V_290 = NULL ;
V_264 = F_172 ( V_288 -> V_116 , V_23 , 0 ) ;
if ( ! V_264 )
return NULL ;
V_280 = & V_264 -> V_262 ;
V_290 = & V_280 -> V_34 ;
F_24 ( V_280 , V_23 ,
& V_291 ) ;
F_21 ( L_226
L_227 ,
F_27 ( V_290 ) ) ;
return V_280 ;
}
static void F_173 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
struct V_261 * V_264 = F_2 ( F_3 ( V_3 ) ,
struct V_261 , V_262 ) ;
F_21 ( L_228
L_229 ,
F_27 ( V_3 ) , V_264 -> V_279 ) ;
F_30 ( V_3 ) ;
}
static struct V_27 * F_174 (
struct V_27 * V_28 ,
const char * V_23 )
{
return F_23 ( - V_90 ) ;
}
static void F_175 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
return;
}
static struct V_27 * F_176 (
struct V_27 * V_28 ,
const char * V_23 )
{
struct V_261 * V_264 ;
struct V_2 * V_292 = & V_28 -> V_34 ;
struct V_1 * V_204 = F_1 ( V_292 ) ;
struct V_293 * V_294 = V_204 -> V_295 ;
struct V_71 * V_72 ;
int V_296 = - V_66 , V_29 ;
V_29 = F_177 ( & V_204 -> V_297 ) ;
if ( V_29 )
return F_23 ( V_29 ) ;
V_72 = F_178 ( V_204 , V_23 ) ;
if ( ! V_72 )
goto V_152;
F_24 ( & V_72 -> V_74 , V_23 , & V_294 -> V_298 ) ;
F_24 ( & V_72 -> V_107 . V_70 , L_230 ,
& V_294 -> V_299 ) ;
F_25 ( & V_72 -> V_107 . V_70 , & V_72 -> V_74 ) ;
F_24 ( & V_72 -> V_130 , L_231 ,
& V_294 -> V_300 ) ;
F_25 ( & V_72 -> V_130 , & V_72 -> V_74 ) ;
F_24 ( & V_72 -> V_75 . V_114 , L_232 ,
& V_294 -> V_301 ) ;
F_25 ( & V_72 -> V_75 . V_114 ,
& V_72 -> V_74 ) ;
F_24 ( & V_72 -> V_227 . V_289 ,
L_233 , & V_294 -> V_302 ) ;
F_25 ( & V_72 -> V_227 . V_289 ,
& V_72 -> V_74 ) ;
F_24 ( & V_72 -> V_303 . V_304 ,
L_234 , & V_294 -> V_305 ) ;
F_25 ( & V_72 -> V_303 . V_304 ,
& V_72 -> V_74 ) ;
V_264 = F_172 ( V_72 , L_235 , 1 ) ;
if ( ! V_264 )
goto V_306;
V_72 -> V_227 . V_307 = V_264 ;
F_24 ( & V_264 -> V_262 ,
L_235 , & V_291 ) ;
F_25 ( & V_264 -> V_262 ,
& V_72 -> V_227 . V_289 ) ;
F_179 ( V_72 ) ;
F_10 ( & V_204 -> V_297 ) ;
return & V_72 -> V_74 ;
V_306:
F_124 ( V_72 ) ;
V_152:
F_10 ( & V_204 -> V_297 ) ;
return F_23 ( V_296 ) ;
}
static void F_180 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
struct V_27 * V_253 = F_3 ( V_3 ) ;
struct V_71 * V_72 =
F_2 ( V_253 , struct V_71 , V_74 ) ;
struct V_1 * V_204 ;
V_204 = F_1 ( & V_72 -> V_1 -> V_4 . V_34 ) ;
F_8 ( & V_204 -> V_297 ) ;
F_29 ( & V_72 -> V_303 . V_304 ) ;
F_29 ( & V_72 -> V_227 . V_289 ) ;
V_72 -> V_227 . V_307 = NULL ;
F_29 ( V_253 ) ;
F_30 ( V_3 ) ;
F_10 ( & V_204 -> V_297 ) ;
}
static inline struct V_1 * F_181 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static T_1 F_182 ( struct V_2 * V_3 , char * V_5 )
{
struct V_1 * V_204 = F_181 ( V_3 ) ;
return sprintf ( V_5 , L_236 ,
V_204 -> V_308 , V_204 -> V_295 -> V_309 -> V_23 ,
V_7 ) ;
}
static T_1 F_183 ( struct V_2 * V_3 , char * V_5 )
{
struct V_1 * V_204 = F_181 ( V_3 ) ;
int V_310 = 0 ;
if ( V_204 -> V_311 & V_312 )
V_310 = 1 ;
return sprintf ( V_5 , L_162 , V_310 ) ;
}
static T_1 F_184 ( struct V_2 * V_3 ,
const char * V_5 , T_2 V_11 )
{
struct V_1 * V_204 = F_181 ( V_3 ) ;
unsigned long V_313 ;
int V_29 ;
if ( V_204 -> V_295 -> V_309 -> V_314 == NULL )
return - V_17 ;
V_29 = F_128 ( V_5 , 0 , & V_313 ) ;
if ( V_29 < 0 ) {
F_11 ( L_237 , V_29 ) ;
return V_29 ;
}
if ( V_204 -> V_315 ) {
F_11 ( L_238 ) ;
return - V_17 ;
}
V_29 = V_204 -> V_295 -> V_309 -> V_314 ( V_204 , V_313 ) ;
if ( V_29 < 0 )
return - V_17 ;
if ( V_29 > 0 )
V_204 -> V_311 |= V_312 ;
else if ( V_29 == 0 )
V_204 -> V_311 &= ~ V_312 ;
return V_11 ;
}
static void F_185 ( struct V_2 * V_3 )
{
struct V_1 * V_204 = F_2 ( F_3 ( V_3 ) ,
struct V_1 , V_4 ) ;
F_186 ( V_204 ) ;
}
static struct V_27 * F_187 (
struct V_27 * V_28 ,
const char * V_23 )
{
char * V_316 , * V_317 , * V_318 ;
struct V_1 * V_204 ;
char V_117 [ V_319 ] ;
unsigned long V_320 = 0 ;
int V_29 ;
memset ( V_117 , 0 , V_319 ) ;
if ( strlen ( V_23 ) >= V_319 ) {
F_11 ( L_239
L_240 , ( int ) strlen ( V_23 ) ,
V_319 ) ;
return F_23 ( - V_321 ) ;
}
snprintf ( V_117 , V_319 , L_7 , V_23 ) ;
V_317 = strstr ( V_117 , L_241 ) ;
if ( ! V_317 ) {
F_11 ( L_242 ) ;
return F_23 ( - V_17 ) ;
}
V_316 = V_117 ;
V_318 = strstr ( V_317 + 1 , L_241 ) ;
if ( V_318 ) {
* V_318 = '\0' ;
V_318 ++ ;
V_317 = V_318 ;
} else {
* V_317 = '\0' ;
V_317 ++ ;
}
V_29 = F_128 ( V_317 , 0 , & V_320 ) ;
if ( V_29 < 0 ) {
F_11 ( L_190
L_243 , V_29 ) ;
return F_23 ( V_29 ) ;
}
F_188 () ;
V_204 = F_189 ( V_316 , V_320 , 0 ) ;
if ( F_13 ( V_204 ) )
return F_190 ( V_204 ) ;
F_24 ( & V_204 -> V_4 , V_23 ,
& V_322 ) ;
return & V_204 -> V_4 ;
}
static void F_191 (
struct V_27 * V_28 ,
struct V_2 * V_3 )
{
F_30 ( V_3 ) ;
}
void F_192 ( struct V_293 * V_294 )
{
F_193 ( V_294 ) ;
F_194 ( V_294 ) ;
F_195 ( V_294 ) ;
F_196 ( V_294 ) ;
F_197 ( V_294 ) ;
F_198 ( V_294 ) ;
}
static int T_8 F_199 ( void )
{
struct V_323 * V_324 = & V_36 ;
struct V_210 * V_211 ;
int V_29 ;
F_21 ( L_244
L_245 V_6 L_3 ,
V_7 , F_5 () -> V_8 , F_5 () -> V_9 ) ;
F_200 ( & V_324 -> V_325 ) ;
F_201 ( & V_324 -> V_326 ) ;
V_29 = F_202 () ;
if ( V_29 < 0 )
return V_29 ;
F_24 ( & V_327 , L_246 ,
& V_328 ) ;
F_25 ( & V_327 , & V_324 -> V_325 ) ;
F_24 ( & V_329 , L_233 , & V_330 ) ;
F_25 ( & V_329 , & V_327 ) ;
F_24 ( & V_331 , L_247 ,
& V_332 ) ;
F_25 ( & V_331 , & V_329 ) ;
V_211 = F_134 ( L_248 , 1 ) ;
if ( F_13 ( V_211 ) ) {
V_29 = - V_66 ;
goto V_333;
}
F_24 ( & V_211 -> V_216 , L_248 ,
& V_260 ) ;
F_25 ( & V_211 -> V_216 , & V_331 ) ;
V_334 = V_211 ;
V_29 = F_203 ( V_324 ) ;
if ( V_29 < 0 ) {
F_11 ( L_249 ,
V_29 , V_324 -> V_325 . V_34 . V_335 ) ;
goto V_333;
}
F_21 ( L_250
L_251 V_7 L_252
L_253 V_6 L_3 , F_5 () -> V_8 , F_5 () -> V_9 ) ;
V_29 = F_204 () ;
if ( V_29 < 0 )
goto V_181;
V_29 = F_205 () ;
if ( V_29 < 0 )
goto V_181;
V_29 = F_206 () ;
if ( V_29 < 0 )
goto V_181;
return 0 ;
V_181:
F_207 ( V_324 ) ;
F_208 () ;
F_209 () ;
V_333:
if ( V_334 ) {
F_132 ( V_334 ) ;
V_334 = NULL ;
}
F_210 () ;
return V_29 ;
}
static void T_9 F_211 ( void )
{
F_29 ( & V_331 ) ;
F_29 ( & V_329 ) ;
F_29 ( & V_327 ) ;
F_207 ( & V_36 ) ;
F_132 ( V_334 ) ;
V_334 = NULL ;
F_21 ( L_254
L_255 ) ;
F_208 () ;
F_209 () ;
F_212 () ;
F_210 () ;
}
