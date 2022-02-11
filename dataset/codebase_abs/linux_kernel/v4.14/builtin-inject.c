static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
T_2 V_5 ;
V_5 = F_2 ( & V_2 -> V_6 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return - V_7 ;
V_2 -> V_8 += V_5 ;
return 0 ;
}
static int F_3 ( struct V_9 * V_10 ,
union V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 ,
V_10 ) ;
return F_1 ( V_2 , V_12 , V_12 -> V_13 . V_5 ) ;
}
static int F_5 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_14 * T_3 V_15 )
{
return F_3 ( V_10 , V_12 ) ;
}
static int F_6 ( struct V_9 * V_10 V_15 ,
union V_11 * V_12 V_15 ,
struct V_14 * T_3 V_15 )
{
return 0 ;
}
static int F_7 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_16 * T_4
V_15 )
{
return F_3 ( V_10 , V_12 ) ;
}
static int F_8 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_17 * * V_18 )
{
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 ,
V_10 ) ;
int V_19 ;
V_19 = F_9 ( V_10 , V_12 , V_18 ) ;
if ( V_19 )
return V_19 ;
if ( ! V_2 -> V_6 . V_20 )
return 0 ;
return F_3 ( V_10 , V_12 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_21 , T_5 V_5 )
{
char V_3 [ 4096 ] ;
T_2 V_22 ;
int V_19 ;
while ( V_5 > 0 ) {
V_22 = F_11 ( V_21 , V_3 , F_12 ( V_5 , ( T_5 ) sizeof( V_3 ) ) ) ;
if ( V_22 < 0 )
return - V_7 ;
V_19 = F_1 ( V_2 , V_3 , V_22 ) ;
if ( V_19 )
return V_19 ;
V_5 -= V_22 ;
}
return 0 ;
}
static T_6 F_13 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_16 * T_4 )
{
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 ,
V_10 ) ;
int V_19 ;
V_2 -> V_23 = true ;
if ( ! V_2 -> V_6 . V_20 ) {
T_5 V_24 ;
V_24 = F_14 ( V_2 -> V_6 . V_21 , 0 , V_25 ) ;
if ( V_24 == - 1 )
return - V_7 ;
V_19 = F_15 ( & T_4 -> V_26 ,
V_12 , V_24 ) ;
if ( V_19 < 0 )
return V_19 ;
}
if ( F_16 ( T_4 -> V_27 ) || ! T_4 -> V_28 ) {
V_19 = F_1 ( V_2 , V_12 , V_12 -> V_13 . V_5 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_10 ( V_2 , F_17 ( T_4 -> V_27 ) ,
V_12 -> V_29 . V_5 ) ;
} else {
V_19 = F_1 ( V_2 , V_12 ,
V_12 -> V_13 . V_5 + V_12 -> V_29 . V_5 ) ;
}
if ( V_19 < 0 )
return V_19 ;
return V_12 -> V_29 . V_5 ;
}
static T_6
F_13 ( struct V_9 * V_10 V_15 ,
union V_11 * V_12 V_15 ,
struct V_16 * T_4 V_15 )
{
F_18 ( L_1 ) ;
return - V_30 ;
}
static int F_19 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 V_15 ,
struct V_32 * V_32 V_15 )
{
return F_3 ( V_10 , V_12 ) ;
}
static int F_20 ( struct V_9 * V_10 V_15 ,
union V_11 * V_12 V_15 ,
struct V_31 * T_7 V_15 ,
struct V_32 * V_32 V_15 )
{
return 0 ;
}
static int F_21 ( struct V_9 * V_10 ,
union V_11 * V_12 V_15 ,
struct V_31 * T_7 ,
struct V_32 * V_32 V_15 )
{
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_10 ) ;
if ( ! V_2 -> V_33 )
V_2 -> V_33 = T_7 -> V_34 ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_35 * V_36 ,
struct V_32 * V_32 )
{
if ( V_36 -> V_37 ) {
T_8 V_38 = V_36 -> V_37 ;
return V_38 ( V_10 , V_12 , T_7 , V_36 , V_32 ) ;
}
F_23 ( V_10 , V_12 , T_7 , V_36 , V_32 ) ;
return F_3 ( V_10 , V_12 ) ;
}
static int F_24 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
int V_39 ;
V_39 = F_25 ( V_10 , V_12 , T_7 , V_32 ) ;
F_19 ( V_10 , V_12 , T_7 , V_32 ) ;
return V_39 ;
}
static int F_26 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_10 ) ;
T_9 V_40 = 0 ;
int V_19 ;
V_19 = F_27 ( V_2 -> T_4 , & V_2 -> V_6 , V_32 ,
V_12 -> V_41 . V_42 , T_7 -> V_43 , & V_40 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_19 ) {
V_2 -> V_8 += V_40 ;
return 0 ;
}
return F_24 ( V_10 , V_12 , T_7 , V_32 ) ;
}
static int F_28 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
int V_39 ;
V_39 = F_29 ( V_10 , V_12 , T_7 , V_32 ) ;
F_19 ( V_10 , V_12 , T_7 , V_32 ) ;
return V_39 ;
}
static int F_30 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_10 ) ;
T_9 V_40 = 0 ;
int V_19 ;
V_19 = F_27 ( V_2 -> T_4 , & V_2 -> V_6 , V_32 ,
V_12 -> V_44 . V_42 , T_7 -> V_43 , & V_40 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_19 ) {
V_2 -> V_8 += V_40 ;
return 0 ;
}
return F_28 ( V_10 , V_12 , T_7 , V_32 ) ;
}
static int F_31 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
int V_39 ;
V_39 = F_32 ( V_10 , V_12 , T_7 , V_32 ) ;
F_19 ( V_10 , V_12 , T_7 , V_32 ) ;
return V_39 ;
}
static int F_33 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
int V_39 ;
V_39 = F_34 ( V_10 , V_12 , T_7 , V_32 ) ;
F_19 ( V_10 , V_12 , T_7 , V_32 ) ;
return V_39 ;
}
static int F_35 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
int V_39 = F_36 ( V_10 , V_12 , T_7 , V_32 ) ;
F_19 ( V_10 , V_12 , T_7 , V_32 ) ;
return V_39 ;
}
static int F_37 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
int V_39 ;
V_39 = F_38 ( V_10 , V_12 , T_7 , V_32 ) ;
F_19 ( V_10 , V_12 , T_7 , V_32 ) ;
return V_39 ;
}
static int F_39 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_16 * T_4 )
{
int V_39 ;
F_3 ( V_10 , V_12 ) ;
V_39 = F_40 ( V_10 , V_12 , T_4 ) ;
return V_39 ;
}
static int F_41 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_16 * T_4 )
{
int V_39 ;
F_3 ( V_10 , V_12 ) ;
V_39 = F_42 ( V_10 , V_12 , T_4 ) ;
return V_39 ;
}
static int F_43 ( struct V_45 * V_45 )
{
if ( V_45 -> V_46 )
return 0 ;
if ( F_44 ( V_45 -> V_47 , V_45 -> V_48 ,
sizeof( V_45 -> V_48 ) ) > 0 ) {
V_45 -> V_46 = true ;
return 0 ;
}
return - 1 ;
}
static int F_45 ( struct V_45 * V_45 , struct V_9 * V_10 ,
struct V_32 * V_32 )
{
T_10 V_49 = V_50 ;
int V_39 ;
if ( F_43 ( V_45 ) < 0 ) {
F_46 ( L_2 , V_45 -> V_47 ) ;
return - 1 ;
}
if ( V_45 -> V_51 )
V_49 = V_52 ;
V_39 = F_47 ( V_10 , V_45 , V_49 , F_19 ,
V_32 ) ;
if ( V_39 ) {
F_18 ( L_3 , V_45 -> V_47 ) ;
return - 1 ;
}
return 0 ;
}
static int F_48 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_35 * V_36 V_15 ,
struct V_32 * V_32 )
{
struct V_53 V_54 ;
struct V_55 * V_55 ;
V_55 = F_49 ( V_32 , T_7 -> V_43 , T_7 -> V_56 ) ;
if ( V_55 == NULL ) {
F_18 ( L_4 ,
V_12 -> V_13 . type ) ;
goto V_57;
}
F_50 ( V_55 , T_7 -> V_58 , V_59 , T_7 -> V_60 , & V_54 ) ;
if ( V_54 . V_61 != NULL ) {
if ( ! V_54 . V_61 -> V_45 -> V_62 ) {
V_54 . V_61 -> V_45 -> V_62 = 1 ;
if ( F_51 ( V_54 . V_61 ) >= 0 ) {
F_45 ( V_54 . V_61 -> V_45 , V_10 , V_32 ) ;
} else {
#ifdef F_52
F_53 ( L_5
L_6 ,
V_54 . V_61 -> V_45 -> V_47 ) ;
#endif
}
}
}
F_54 ( V_55 ) ;
V_57:
F_19 ( V_10 , V_12 , T_7 , V_32 ) ;
return 0 ;
}
static int F_55 ( struct V_9 * V_10 ,
union V_11 * V_12 V_15 ,
struct V_31 * T_7 ,
struct V_35 * V_36 V_15 ,
struct V_32 * V_32 V_15 )
{
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_10 ) ;
struct V_63 * V_64 ;
F_56 (ent, &inject->samples, node) {
if ( T_7 -> V_56 == V_64 -> V_56 ) {
F_57 ( & V_64 -> V_65 ) ;
free ( V_64 ) ;
break;
}
}
return 0 ;
}
static int F_58 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_35 * V_36 ,
struct V_32 * V_32 )
{
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_10 ) ;
struct V_63 * V_64 ;
F_55 ( V_10 , V_12 , T_7 , V_36 , V_32 ) ;
V_64 = malloc ( V_12 -> V_13 . V_5 + sizeof( struct V_63 ) ) ;
if ( V_64 == NULL ) {
F_59 ( V_66 , V_67 ,
L_7 ) ;
return - 1 ;
}
V_64 -> V_56 = T_7 -> V_56 ;
memcpy ( & V_64 -> V_12 , V_12 , V_12 -> V_13 . V_5 ) ;
F_60 ( & V_64 -> V_65 , & V_2 -> V_68 ) ;
return 0 ;
}
static int F_61 ( struct V_9 * V_10 ,
union V_11 * V_12 V_15 ,
struct V_31 * T_7 ,
struct V_35 * V_36 ,
struct V_32 * V_32 )
{
struct V_63 * V_64 ;
union V_11 * V_69 ;
struct V_31 V_70 ;
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_10 ) ;
T_11 V_43 = F_62 ( V_36 , T_7 , L_8 ) ;
F_56 (ent, &inject->samples, node) {
if ( V_43 == V_64 -> V_56 )
goto V_71;
}
return 0 ;
V_71:
V_69 = & V_64 -> V_12 [ 0 ] ;
F_63 ( V_36 , V_69 , & V_70 ) ;
V_70 . V_72 = T_7 -> V_72 ;
V_70 . time = T_7 -> time ;
F_64 ( V_69 , V_36 -> V_73 . V_74 ,
V_36 -> V_73 . V_75 , & V_70 ,
false ) ;
F_23 ( V_10 , V_69 , & V_70 , V_36 , V_32 ) ;
return F_19 ( V_10 , V_69 , & V_70 , V_32 ) ;
}
static void F_65 ( int T_12 V_15 )
{
V_76 = 1 ;
}
static int F_66 ( struct V_35 * V_36 ,
T_9 V_74 , const char * V_77 )
{
struct V_78 * V_73 = & V_36 -> V_73 ;
const char * V_79 = F_67 ( V_36 ) ;
if ( ! ( V_73 -> V_74 & V_74 ) ) {
F_18 ( L_9 ,
V_79 , V_77 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_68 ( struct V_9 * V_10 V_15 ,
union V_11 * V_12 V_15 ,
struct V_31 * T_7 V_15 ,
struct V_35 * V_36 V_15 ,
struct V_32 * V_32 V_15 )
{
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_17 * V_80 = V_2 -> T_4 -> V_80 ;
struct V_35 * V_36 ;
V_2 -> V_10 . V_81 = F_20 ;
F_70 (evlist, evsel)
V_36 -> V_37 = F_68 ;
}
static bool F_71 ( struct V_35 * V_36 )
{
return V_36 -> V_73 . V_41 || V_36 -> V_73 . V_44 || V_36 -> V_73 . V_82 ||
V_36 -> V_73 . V_83 ;
}
static bool F_72 ( struct V_17 * V_80 ,
struct V_35 * V_84 )
{
struct V_35 * V_36 ;
int V_85 = 0 ;
bool V_86 = false ;
if ( ! F_71 ( V_84 ) )
return true ;
F_70 (evlist, evsel) {
if ( V_36 -> V_37 != F_68 ) {
V_85 += 1 ;
if ( ( V_36 -> V_73 . V_74 & V_87 ) ==
( V_84 -> V_73 . V_74 & V_87 ) )
V_86 = true ;
}
}
return V_86 && V_85 == 1 ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_17 * V_80 = V_2 -> T_4 -> V_80 ;
struct V_35 * V_36 , * V_88 ;
F_74 (evlist, tmp, evsel) {
if ( V_36 -> V_37 == F_68 &&
F_72 ( V_80 , V_36 ) ) {
F_46 ( L_10 , F_67 ( V_36 ) ) ;
F_75 ( V_80 , V_36 ) ;
F_76 ( V_36 ) ;
}
}
}
static int F_77 ( struct V_1 * V_2 )
{
int V_19 = - V_30 ;
struct V_16 * T_4 = V_2 -> T_4 ;
struct V_89 * V_90 = & V_2 -> V_6 ;
int V_21 = F_17 ( V_90 ) ;
T_9 V_91 ;
signal ( V_92 , F_65 ) ;
if ( V_2 -> V_93 || V_2 -> V_94 ||
V_2 -> V_95 . V_96 ) {
V_2 -> V_10 . V_41 = F_24 ;
V_2 -> V_10 . V_44 = F_28 ;
V_2 -> V_10 . V_97 = F_31 ;
V_2 -> V_10 . V_98 = F_39 ;
}
V_91 = T_4 -> V_13 . V_99 ;
if ( V_2 -> V_93 ) {
V_2 -> V_10 . T_7 = F_48 ;
} else if ( V_2 -> V_94 ) {
struct V_35 * V_36 ;
F_70 (session->evlist, evsel) {
const char * V_79 = F_67 ( V_36 ) ;
if ( ! strcmp ( V_79 , L_11 ) ) {
if ( F_66 ( V_36 , V_100 , L_12 ) )
return - V_30 ;
V_36 -> V_37 = F_58 ;
} else if ( ! strcmp ( V_79 , L_13 ) )
V_36 -> V_37 = F_55 ;
else if ( ! strncmp ( V_79 , L_14 , 17 ) )
V_36 -> V_37 = F_61 ;
}
} else if ( V_2 -> V_95 . V_96 ) {
T_4 -> V_95 = & V_2 -> V_95 ;
V_2 -> V_95 . V_2 = true ;
V_2 -> V_10 . V_82 = F_33 ;
V_2 -> V_10 . V_101 = F_35 ;
V_2 -> V_10 . exit = F_37 ;
V_2 -> V_10 . V_102 = F_41 ;
V_2 -> V_10 . V_103 = V_104 ;
V_2 -> V_10 . V_29 = V_105 ;
V_2 -> V_10 . V_106 = F_21 ;
V_2 -> V_10 . V_107 = F_21 ,
V_2 -> V_10 . V_14 = true ;
V_2 -> V_10 . V_108 = true ;
V_91 = 4096 ;
if ( V_2 -> V_109 )
F_69 ( V_2 ) ;
}
if ( ! V_2 -> V_95 . V_96 )
F_78 ( & T_4 -> V_26 ) ;
if ( ! V_90 -> V_20 )
F_14 ( V_21 , V_91 , V_110 ) ;
V_19 = F_79 ( T_4 ) ;
if ( V_19 )
return V_19 ;
if ( ! V_90 -> V_20 ) {
if ( V_2 -> V_93 )
F_80 ( & T_4 -> V_13 ,
V_111 ) ;
if ( F_81 ( & T_4 -> V_13 , V_111 ) &&
V_2 -> V_23 && ! V_2 -> V_95 . V_96 )
F_82 ( T_4 ) ;
if ( V_2 -> V_95 . V_96 ) {
struct V_35 * V_36 ;
F_83 ( & T_4 -> V_13 ,
V_112 ) ;
if ( V_2 -> V_95 . V_113 )
F_80 ( & T_4 -> V_13 ,
V_114 ) ;
V_36 = F_84 ( T_4 -> V_80 ,
V_2 -> V_33 ) ;
if ( V_36 ) {
F_46 ( L_10 ,
F_67 ( V_36 ) ) ;
F_75 ( T_4 -> V_80 , V_36 ) ;
F_76 ( V_36 ) ;
}
if ( V_2 -> V_109 )
F_73 ( V_2 ) ;
}
T_4 -> V_13 . V_99 = V_91 ;
T_4 -> V_13 . V_115 = V_2 -> V_8 ;
F_85 ( T_4 , T_4 -> V_80 , V_21 , true ) ;
}
return V_19 ;
}
int F_86 ( int V_116 , const char * * V_117 )
{
struct V_1 V_2 = {
. V_10 = {
. T_7 = F_22 ,
. V_41 = F_19 ,
. V_44 = F_19 ,
. V_82 = F_19 ,
. V_97 = F_19 ,
. exit = F_19 ,
. V_118 = F_19 ,
. V_119 = F_19 ,
. V_106 = F_19 ,
. V_107 = F_19 ,
. V_81 = F_19 ,
. F_11 = F_22 ,
. V_120 = F_19 ,
. V_121 = F_19 ,
. V_73 = F_8 ,
. V_98 = F_7 ,
. V_103 = F_7 ,
. V_29 = F_13 ,
. V_122 = F_7 ,
. V_123 = F_7 ,
. V_124 = F_5 ,
. V_48 = F_7 ,
. V_102 = F_7 ,
. V_125 = F_7 ,
} ,
. V_126 = L_15 ,
. V_68 = F_87 ( V_2 . V_68 ) ,
. V_6 = {
. V_127 = L_15 ,
. V_128 = V_129 ,
} ,
} ;
struct V_89 V_27 = {
. V_128 = V_130 ,
} ;
int V_19 ;
struct V_131 V_132 [] = {
F_88 ( 'b' , L_16 , & V_2 . V_93 ,
L_17 ) ,
F_89 ( 'i' , L_18 , & V_2 . V_126 , L_19 ,
L_20 ) ,
F_89 ( 'o' , L_21 , & V_2 . V_6 . V_127 , L_19 ,
L_22 ) ,
F_88 ( 's' , L_23 , & V_2 . V_94 ,
L_24
L_25 ) ,
#ifdef F_90
F_88 ( 'j' , L_26 , & V_2 . V_133 , L_27 ) ,
#endif
F_91 ( 'v' , L_28 , & V_134 ,
L_29 ) ,
F_89 ( 0 , L_30 , & V_135 . V_136 , L_19 ,
L_31 ) ,
F_88 ( 'f' , L_32 , & V_27 . V_137 , L_33 ) ,
F_92 ( 0 , L_34 , & V_2 . V_95 ,
NULL , L_35 , L_36 ,
V_138 ) ,
F_88 ( 0 , L_37 , & V_2 . V_109 ,
L_38 ) ,
F_93 ()
} ;
const char * const V_139 [] = {
L_39 ,
NULL
} ;
#ifndef F_90
F_94 ( V_132 , 'j' , L_26 , L_40 , true ) ;
#endif
V_116 = F_95 ( V_116 , V_117 , V_132 , V_139 , 0 ) ;
if ( V_116 )
F_96 ( V_139 , V_132 ) ;
if ( V_2 . V_109 && ! V_2 . V_95 . V_96 ) {
F_18 ( L_41 ) ;
return - 1 ;
}
if ( F_97 ( & V_2 . V_6 ) ) {
perror ( L_42 ) ;
return - 1 ;
}
V_2 . V_10 . V_14 = V_2 . V_94 ;
V_27 . V_127 = V_2 . V_126 ;
V_2 . T_4 = F_98 ( & V_27 , true , & V_2 . V_10 ) ;
if ( V_2 . T_4 == NULL )
return - 1 ;
if ( V_2 . V_93 ) {
V_2 . V_10 . V_14 = true ;
V_2 . V_10 . V_108 = true ;
}
#ifdef F_90
if ( V_2 . V_133 ) {
V_2 . V_10 . V_44 = F_30 ;
V_2 . V_10 . V_41 = F_26 ;
V_2 . V_10 . V_14 = true ;
V_2 . V_10 . V_108 = true ;
V_2 . V_10 . V_124 = F_6 ;
}
#endif
V_19 = F_99 ( & V_2 . T_4 -> V_13 . V_140 ) ;
if ( V_19 < 0 )
goto V_141;
V_19 = F_77 ( & V_2 ) ;
V_141:
F_100 ( V_2 . T_4 ) ;
return V_19 ;
}
