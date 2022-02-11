static int F_1 ( struct V_1 * type ,
struct V_2 * V_3 ,
const char * V_4 , T_1 V_5 )
{
struct V_6 * V_7 ;
bool V_8 = F_2 ( type ) ;
int V_9 ;
V_7 = F_3 ( type ) ;
if ( ! V_7 ) {
F_4 ( L_1 , V_4 ) ;
return - 1 ;
}
if ( V_8 ) {
V_9 = F_5 ( V_7 , V_5 ) ;
if ( V_9 ) {
F_4 ( L_2 , V_4 ) ;
goto V_10;
}
} else {
V_9 = F_6 ( V_7 , V_5 ) ;
if ( V_9 ) {
F_4 ( L_2 , V_4 ) ;
goto V_10;
}
}
V_9 = F_7 ( V_3 , V_4 , V_7 ) ;
if ( V_9 ) {
F_4 ( L_3 , V_4 ) ;
goto V_10;
}
F_8 ( L_4 V_11 L_5 , V_4 , V_5 ) ;
V_10:
F_9 ( V_7 ) ;
return V_9 ;
}
static struct V_1 *
F_10 ( struct V_12 * V_13 , struct V_14 * V_7 )
{
unsigned long V_15 = V_7 -> V_15 ;
if ( V_15 & V_16 )
return V_13 -> V_17 . string ;
if ( ! ( V_15 & V_18 ) ) {
if ( V_15 & V_19 || V_15 & V_20 )
return V_13 -> V_17 . V_21 ;
}
if ( V_15 & V_18 ) {
if ( V_7 -> V_22 == 8 )
return V_13 -> V_17 . V_23 ;
else
return V_13 -> V_17 . V_24 ;
}
if ( V_7 -> V_22 == 8 )
return V_13 -> V_17 . T_1 ;
else
return V_13 -> V_17 . V_25 ;
}
static int F_11 ( struct V_12 * V_13 ,
struct V_26 * V_27 ,
struct V_2 * V_3 ,
struct V_28 * V_29 ,
struct V_14 * V_30 )
{
struct V_1 * type ;
struct V_6 * V_31 ;
struct V_6 * V_7 ;
const char * V_4 = V_30 -> V_4 ;
void * V_17 = V_29 -> V_32 ;
unsigned long long V_33 ;
unsigned long V_15 = V_30 -> V_15 ;
unsigned int V_34 ;
unsigned int V_35 ;
unsigned int V_36 ;
unsigned int V_37 ;
int V_9 ;
V_36 = V_30 -> V_36 ;
V_37 = V_30 -> V_22 ;
if ( V_15 & V_16 )
V_15 &= ~ V_38 ;
if ( V_15 & V_39 ) {
unsigned long long V_40 ;
V_40 = F_12 ( V_30 -> V_3 -> V_41 ,
V_17 + V_36 , V_37 ) ;
V_36 = V_40 ;
V_37 = V_36 >> 16 ;
V_36 &= 0xffff ;
}
if ( V_15 & V_38 ) {
type = F_13 (
V_27 , V_4 ) ;
V_31 = F_3 ( type ) ;
F_14 ( type ) ;
if ( ! V_31 ) {
F_4 ( L_6 , V_4 ) ;
return - 1 ;
}
V_37 = V_30 -> V_22 / V_30 -> V_42 ;
V_34 = V_30 -> V_42 ;
} else {
V_34 = 1 ;
V_31 = NULL ;
}
type = F_10 ( V_13 , V_30 ) ;
for ( V_35 = 0 ; V_35 < V_34 ; V_35 ++ ) {
if ( ! ( V_15 & V_16 ) )
V_33 = F_12 (
V_30 -> V_3 -> V_41 ,
V_17 + V_36 + V_35 * V_37 , V_37 ) ;
if ( V_15 & V_38 )
V_7 = F_15 ( V_31 , V_35 ) ;
else
V_7 = F_3 ( type ) ;
if ( ! V_7 ) {
F_4 ( L_1 , V_4 ) ;
return - 1 ;
}
if ( V_15 & V_16 )
V_9 = F_16 ( V_7 ,
V_17 + V_36 + V_35 * V_37 ) ;
else if ( ! ( V_15 & V_18 ) )
V_9 = F_6 (
V_7 , V_33 ) ;
else
V_9 = F_5 (
V_7 , V_33 ) ;
if ( V_9 ) {
F_4 ( L_7 , V_4 ) ;
goto V_43;
}
if ( ! ( V_15 & V_38 ) ) {
V_9 = F_7 ( V_3 , V_4 , V_7 ) ;
if ( V_9 ) {
F_4 ( L_3 , V_4 ) ;
goto V_43;
}
}
F_9 ( V_7 ) ;
}
if ( V_15 & V_38 ) {
V_9 = F_7 ( V_3 , V_4 , V_31 ) ;
if ( V_9 ) {
F_4 ( L_8 , V_4 ) ;
return - 1 ;
}
F_9 ( V_31 ) ;
}
return 0 ;
V_43:
F_9 ( V_7 ) ;
return - 1 ;
}
static int F_17 ( struct V_12 * V_13 ,
struct V_26 * V_27 ,
struct V_2 * V_3 ,
struct V_14 * V_44 ,
struct V_28 * V_29 )
{
struct V_14 * V_7 ;
int V_9 ;
for ( V_7 = V_44 ; V_7 ; V_7 = V_7 -> V_45 ) {
V_9 = F_11 ( V_13 , V_27 , V_3 , V_29 ,
V_7 ) ;
if ( V_9 )
return - 1 ;
}
return 0 ;
}
static int F_18 ( struct V_12 * V_13 ,
struct V_26 * V_27 ,
struct V_2 * V_3 ,
struct V_46 * V_47 ,
struct V_28 * V_29 )
{
struct V_14 * V_48 = V_47 -> V_49 -> V_50 . V_48 ;
struct V_14 * V_44 = V_47 -> V_49 -> V_50 . V_44 ;
int V_9 ;
V_9 = F_17 ( V_13 , V_27 , V_3 ,
V_48 , V_29 ) ;
if ( ! V_9 )
V_9 = F_17 ( V_13 , V_27 , V_3 ,
V_44 , V_29 ) ;
return V_9 ;
}
static int F_19 ( struct V_12 * V_13 ,
struct V_2 * V_3 ,
struct V_46 * V_47 ,
struct V_28 * V_29 )
{
T_1 type = V_47 -> V_51 . V_52 ;
int V_9 ;
if ( type & V_53 ) {
V_9 = F_20 ( V_13 , V_3 , L_9 , V_29 -> V_54 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_55 ) {
V_9 = F_21 ( V_13 , V_3 , L_10 , V_29 -> V_56 ) ;
if ( V_9 )
return - 1 ;
V_9 = F_21 ( V_13 , V_3 , L_11 , V_29 -> V_57 ) ;
if ( V_9 )
return - 1 ;
}
if ( ( type & V_58 ) ||
( type & V_59 ) ) {
V_9 = F_22 ( V_13 , V_3 , L_12 , V_29 -> V_60 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_61 ) {
V_9 = F_22 ( V_13 , V_3 , L_13 , V_29 -> V_62 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_63 ) {
V_9 = F_23 ( V_13 , V_3 , L_14 , V_29 -> V_64 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_65 ) {
V_9 = F_22 ( V_13 , V_3 , L_15 , V_29 -> V_66 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_67 ) {
V_9 = F_22 ( V_13 , V_3 , L_16 , V_29 -> V_68 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_69 ) {
V_9 = F_22 ( V_13 , V_3 , L_17 ,
V_29 -> V_70 ) ;
if ( V_9 )
return - 1 ;
}
if ( type & V_71 ) {
V_9 = F_22 ( V_13 , V_3 , L_18 ,
V_29 -> V_72 ) ;
if ( V_9 )
return - 1 ;
}
return 0 ;
}
static int F_24 ( struct V_73 * V_74 ,
union V_75 * T_2 V_76 ,
struct V_28 * V_29 ,
struct V_46 * V_47 ,
struct V_77 * V_77 V_76 )
{
struct V_78 * V_79 = F_25 ( V_74 , struct V_78 , V_74 ) ;
struct V_80 * V_81 = V_47 -> V_81 ;
struct V_12 * V_13 = & V_79 -> V_82 ;
struct V_26 * V_27 ;
struct V_2 * V_3 ;
int V_9 ;
if ( F_26 ( ! V_81 , L_19 ) )
return 0 ;
V_27 = V_81 -> V_27 ;
V_79 -> V_83 ++ ;
V_79 -> V_84 += T_2 -> V_85 . V_22 ;
F_27 ( V_29 -> time , L_20 V_11 L_21 , V_79 -> V_83 ) ;
V_3 = F_28 ( V_27 ) ;
if ( ! V_3 ) {
F_4 ( L_22 ) ;
return - 1 ;
}
F_29 ( V_13 -> clock , V_29 -> time ) ;
V_9 = F_19 ( V_13 , V_3 , V_47 , V_29 ) ;
if ( V_9 )
return - 1 ;
if ( V_47 -> V_51 . type == V_86 ) {
V_9 = F_18 ( V_13 , V_27 , V_3 ,
V_47 , V_29 ) ;
if ( V_9 )
return - 1 ;
}
F_30 ( V_13 -> V_87 , V_3 ) ;
F_31 ( V_3 ) ;
return 0 ;
}
static int F_32 ( struct V_12 * V_13 ,
struct V_14 * V_44 ,
struct V_26 * V_27 )
{
struct V_14 * V_7 ;
int V_9 ;
for ( V_7 = V_44 ; V_7 ; V_7 = V_7 -> V_45 ) {
struct V_1 * type ;
unsigned long V_15 = V_7 -> V_15 ;
F_8 ( L_23 , V_7 -> V_4 ) ;
type = F_10 ( V_13 , V_7 ) ;
if ( ! type )
return - 1 ;
if ( V_15 & V_16 )
V_15 &= ~ V_38 ;
if ( V_15 & V_38 )
type = F_33 ( type , V_7 -> V_42 ) ;
V_9 = F_34 ( V_27 , type ,
V_7 -> V_4 ) ;
if ( V_15 & V_38 )
F_14 ( type ) ;
if ( V_9 ) {
F_4 ( L_24 , V_7 -> V_4 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_35 ( struct V_12 * V_13 ,
struct V_46 * V_47 ,
struct V_26 * V_88 )
{
struct V_14 * V_48 = V_47 -> V_49 -> V_50 . V_48 ;
struct V_14 * V_44 = V_47 -> V_49 -> V_50 . V_44 ;
int V_9 ;
V_9 = F_32 ( V_13 , V_48 , V_88 ) ;
if ( ! V_9 )
V_9 = F_32 ( V_13 , V_44 , V_88 ) ;
return V_9 ;
}
static int F_36 ( struct V_12 * V_13 , struct V_46 * V_47 ,
struct V_26 * V_27 )
{
T_1 type = V_47 -> V_51 . V_52 ;
#define F_37 ( T_3 , T_4 , T_5 ) \
do { \
pr2(" field '%s'\n", n); \
if (bt_ctf_event_class_add_field(cl, t, n)) { \
pr_err("Failed to add field '%s;\n", n); \
return -1; \
} \
} while (0)
if ( type & V_53 )
F_37 ( V_27 , V_13 -> V_17 . V_21 , L_9 ) ;
if ( type & V_55 ) {
F_37 ( V_27 , V_13 -> V_17 . V_24 , L_10 ) ;
F_37 ( V_27 , V_13 -> V_17 . V_24 , L_11 ) ;
}
if ( ( type & V_58 ) ||
( type & V_59 ) )
F_37 ( V_27 , V_13 -> V_17 . T_1 , L_12 ) ;
if ( type & V_61 )
F_37 ( V_27 , V_13 -> V_17 . T_1 , L_13 ) ;
if ( type & V_63 )
F_37 ( V_27 , V_13 -> V_17 . V_25 , L_14 ) ;
if ( type & V_65 )
F_37 ( V_27 , V_13 -> V_17 . T_1 , L_15 ) ;
if ( type & V_67 )
F_37 ( V_27 , V_13 -> V_17 . T_1 , L_16 ) ;
if ( type & V_69 )
F_37 ( V_27 , V_13 -> V_17 . T_1 , L_17 ) ;
if ( type & V_71 )
F_37 ( V_27 , V_13 -> V_17 . T_1 , L_18 ) ;
#undef F_37
return 0 ;
}
static int F_38 ( struct V_12 * V_13 , struct V_46 * V_47 )
{
struct V_26 * V_27 ;
struct V_80 * V_81 ;
const char * V_4 = F_39 ( V_47 ) ;
int V_9 ;
F_40 ( L_25 , V_4 , V_47 -> V_51 . type ) ;
V_27 = F_41 ( V_4 ) ;
if ( ! V_27 )
return - 1 ;
V_9 = F_36 ( V_13 , V_47 , V_27 ) ;
if ( V_9 )
goto V_10;
if ( V_47 -> V_51 . type == V_86 ) {
V_9 = F_35 ( V_13 , V_47 , V_27 ) ;
if ( V_9 )
goto V_10;
}
V_9 = F_42 ( V_13 -> V_89 , V_27 ) ;
if ( V_9 ) {
F_40 ( L_26 ) ;
goto V_10;
}
V_81 = malloc ( sizeof( * V_81 ) ) ;
if ( ! V_81 )
goto V_10;
V_81 -> V_27 = V_27 ;
V_47 -> V_81 = V_81 ;
return 0 ;
V_10:
F_43 ( V_27 ) ;
F_4 ( L_27 , V_4 ) ;
return - 1 ;
}
static int F_44 ( struct V_12 * V_13 , struct V_90 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_93 ;
struct V_46 * V_47 ;
int V_9 ;
F_45 (evlist, evsel) {
V_9 = F_38 ( V_13 , V_47 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_46 ( struct V_12 * V_13 ,
struct V_90 * V_91 )
{
struct V_94 * V_85 = & V_91 -> V_85 ;
struct V_95 * V_82 = V_13 -> V_82 ;
#define F_47 ( T_6 , T_7 ) \
do { \
if (bt_ctf_writer_add_environment_field(writer, __n, __v)) \
return -1; \
} while (0)
F_47 ( L_28 , V_85 -> V_96 . V_97 ) ;
F_47 ( L_29 , L_30 ) ;
F_47 ( L_31 , V_85 -> V_96 . V_98 ) ;
F_47 ( L_32 , V_85 -> V_96 . V_99 ) ;
F_47 ( L_33 , V_85 -> V_96 . V_100 ) ;
F_47 ( L_34 , L_35 ) ;
F_47 ( L_36 , L_37 ) ;
#undef F_47
return 0 ;
}
static int F_48 ( struct V_12 * V_13 )
{
struct V_101 * clock = V_13 -> clock ;
F_49 ( clock , L_38 ) ;
#define F_50 ( T_6 , T_7 ) \
do { \
if (bt_ctf_clock_set_##__n(clock, __v)) \
return -1; \
} while (0)
F_50 ( V_102 , 1000000000 ) ;
F_50 ( V_103 , 0 ) ;
F_50 ( V_36 , 0 ) ;
F_50 ( V_104 , 10 ) ;
F_50 ( V_105 , 0 ) ;
#undef F_50
return 0 ;
}
static struct V_1 * F_51 ( int V_22 , bool V_8 , bool V_106 )
{
struct V_1 * type ;
type = F_52 ( V_22 ) ;
if ( ! type )
return NULL ;
if ( V_8 &&
F_53 ( type , 1 ) )
goto V_10;
if ( V_106 &&
F_54 ( type , V_107 ) )
goto V_10;
F_8 ( L_39 ,
V_22 , V_8 ? L_40 : L_41 , V_106 ? L_42 : L_41 ) ;
return type ;
V_10:
F_14 ( type ) ;
return NULL ;
}
static void F_55 ( struct V_12 * V_13 )
{
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < F_56 ( V_13 -> V_17 . V_108 ) ; V_35 ++ )
F_14 ( V_13 -> V_17 . V_108 [ V_35 ] ) ;
}
static int F_57 ( struct V_12 * V_13 )
{
#define F_58 ( type , V_22 , V_8 , V_106 ) \
do { \
(type) = create_int_type(size, sign, hex); \
if (!(type)) \
goto err; \
} while (0)
F_58 ( V_13 -> V_17 . V_23 , 64 , true , false ) ;
F_58 ( V_13 -> V_17 . T_1 , 64 , false , false ) ;
F_58 ( V_13 -> V_17 . V_24 , 32 , true , false ) ;
F_58 ( V_13 -> V_17 . V_25 , 32 , false , false ) ;
F_58 ( V_13 -> V_17 . V_21 , 64 , false , true ) ;
V_13 -> V_17 . string = F_59 () ;
if ( V_13 -> V_17 . string )
return 0 ;
V_10:
F_55 ( V_13 ) ;
F_4 ( L_43 ) ;
return - 1 ;
}
static void F_60 ( struct V_12 * V_13 )
{
F_55 ( V_13 ) ;
F_61 ( V_13 -> clock ) ;
F_62 ( V_13 -> V_87 ) ;
F_63 ( V_13 -> V_89 ) ;
F_64 ( V_13 -> V_82 ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
}
static int F_65 ( struct V_12 * V_13 , const char * V_109 )
{
struct V_95 * V_82 ;
struct V_110 * V_89 ;
struct V_111 * V_87 ;
struct V_101 * clock ;
V_82 = F_66 ( V_109 ) ;
if ( ! V_82 )
goto V_10;
V_13 -> V_82 = V_82 ;
clock = F_67 ( L_44 ) ;
if ( ! clock ) {
F_40 ( L_45 ) ;
goto V_112;
}
V_13 -> clock = clock ;
if ( F_48 ( V_13 ) ) {
F_40 ( L_46 ) ;
goto V_112;
}
V_89 = F_68 ( L_47 ) ;
if ( ! V_89 ) {
F_40 ( L_48 ) ;
goto V_112;
}
V_13 -> V_89 = V_89 ;
if ( F_69 ( V_89 , clock ) ) {
F_40 ( L_49 ) ;
goto V_112;
}
if ( F_57 ( V_13 ) )
goto V_112;
V_87 = F_70 ( V_82 , V_89 ) ;
if ( ! V_87 ) {
F_40 ( L_50 ) ;
goto V_112;
}
V_13 -> V_87 = V_87 ;
if ( F_71 ( V_82 , clock ) ) {
F_40 ( L_51 ) ;
goto V_112;
}
return 0 ;
V_112:
F_60 ( V_13 ) ;
V_10:
F_4 ( L_52 ) ;
return - 1 ;
}
int F_72 ( const char * V_113 , const char * V_109 , bool V_114 )
{
struct V_90 * V_91 ;
struct V_115 V_116 = {
. V_109 = V_113 ,
. V_117 = V_118 ,
. V_114 = V_114 ,
} ;
struct V_78 V_79 = {
. V_74 = {
. V_29 = F_24 ,
. V_119 = V_120 ,
. V_121 = V_122 ,
. V_123 = V_124 ,
. exit = V_125 ,
. V_126 = V_127 ,
. V_128 = V_129 ,
. V_130 = V_131 ,
. V_132 = V_133 ,
. V_134 = true ,
. V_135 = true ,
} ,
} ;
struct V_12 * V_13 = & V_79 . V_82 ;
int V_10 = - 1 ;
if ( F_65 ( V_13 , V_109 ) )
return - 1 ;
V_91 = F_73 ( & V_116 , 0 , & V_79 . V_74 ) ;
if ( ! V_91 )
goto V_136;
if ( F_46 ( V_13 , V_91 ) )
goto V_137;
if ( F_44 ( V_13 , V_91 ) )
goto V_137;
V_10 = F_74 ( V_91 ) ;
if ( ! V_10 )
V_10 = F_75 ( V_13 -> V_87 ) ;
fprintf ( V_138 ,
L_53 ,
V_116 . V_109 , V_109 ) ;
fprintf ( V_138 ,
L_54 V_11 L_55 ,
( double ) V_79 . V_84 / 1024.0 / 1024.0 ,
V_79 . V_83 ) ;
V_137:
F_76 ( V_91 ) ;
V_136:
F_60 ( V_13 ) ;
return V_10 ;
}
