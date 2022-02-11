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
static int F_6 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_16 * T_4
V_15 )
{
return F_3 ( V_10 , V_12 ) ;
}
static int F_7 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_17 * * V_18 )
{
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 ,
V_10 ) ;
int V_19 ;
V_19 = F_8 ( V_10 , V_12 , V_18 ) ;
if ( V_19 )
return V_19 ;
if ( ! V_2 -> V_6 . V_20 )
return 0 ;
return F_3 ( V_10 , V_12 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_21 , T_5 V_5 )
{
char V_3 [ 4096 ] ;
T_2 V_22 ;
int V_19 ;
while ( V_5 > 0 ) {
V_22 = F_10 ( V_21 , V_3 , F_11 ( V_5 , ( T_5 ) sizeof( V_3 ) ) ) ;
if ( V_22 < 0 )
return - V_7 ;
V_19 = F_1 ( V_2 , V_3 , V_22 ) ;
if ( V_19 )
return V_19 ;
V_5 -= V_22 ;
}
return 0 ;
}
static T_6 F_12 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_16 * T_4
V_15 )
{
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 ,
V_10 ) ;
int V_19 ;
V_2 -> V_23 = true ;
if ( ! V_2 -> V_6 . V_20 ) {
T_5 V_24 ;
V_24 = F_13 ( V_2 -> V_6 . V_21 , 0 , V_25 ) ;
if ( V_24 == - 1 )
return - V_7 ;
V_19 = F_14 ( & T_4 -> V_26 ,
V_12 , V_24 ) ;
if ( V_19 < 0 )
return V_19 ;
}
if ( F_15 ( T_4 -> V_27 ) || ! T_4 -> V_28 ) {
V_19 = F_1 ( V_2 , V_12 , V_12 -> V_13 . V_5 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_9 ( V_2 , F_16 ( T_4 -> V_27 ) ,
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
F_12 ( struct V_9 * V_10 V_15 ,
union V_11 * V_12 V_15 ,
struct V_16 * T_4 V_15 )
{
F_17 ( L_1 ) ;
return - V_30 ;
}
static int F_18 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 V_15 ,
struct V_32 * V_32 V_15 )
{
return F_3 ( V_10 , V_12 ) ;
}
static int F_19 ( struct V_9 * V_10 V_15 ,
union V_11 * V_12 V_15 ,
struct V_31 * T_7 V_15 ,
struct V_32 * V_32 V_15 )
{
return 0 ;
}
static int F_20 ( struct V_9 * V_10 ,
union V_11 * V_12 V_15 ,
struct V_31 * T_7 ,
struct V_32 * V_32 V_15 )
{
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_10 ) ;
if ( ! V_2 -> V_33 )
V_2 -> V_33 = T_7 -> V_34 ;
return 0 ;
}
static int F_21 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_35 * V_36 ,
struct V_32 * V_32 )
{
if ( V_36 -> V_37 ) {
T_8 V_38 = V_36 -> V_37 ;
return V_38 ( V_10 , V_12 , T_7 , V_36 , V_32 ) ;
}
F_22 ( V_10 , V_12 , T_7 , V_36 , V_32 ) ;
return F_3 ( V_10 , V_12 ) ;
}
static int F_23 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
int V_39 ;
V_39 = F_24 ( V_10 , V_12 , T_7 , V_32 ) ;
F_18 ( V_10 , V_12 , T_7 , V_32 ) ;
return V_39 ;
}
static int F_25 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
int V_39 ;
V_39 = F_26 ( V_10 , V_12 , T_7 , V_32 ) ;
F_18 ( V_10 , V_12 , T_7 , V_32 ) ;
return V_39 ;
}
static int F_27 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
int V_39 ;
V_39 = F_28 ( V_10 , V_12 , T_7 , V_32 ) ;
F_18 ( V_10 , V_12 , T_7 , V_32 ) ;
return V_39 ;
}
static int F_29 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
int V_39 ;
V_39 = F_30 ( V_10 , V_12 , T_7 , V_32 ) ;
F_18 ( V_10 , V_12 , T_7 , V_32 ) ;
return V_39 ;
}
static int F_31 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
int V_39 ;
V_39 = F_32 ( V_10 , V_12 , T_7 , V_32 ) ;
F_18 ( V_10 , V_12 , T_7 , V_32 ) ;
return V_39 ;
}
static int F_33 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_16 * T_4 )
{
int V_39 ;
F_3 ( V_10 , V_12 ) ;
V_39 = F_34 ( V_10 , V_12 , T_4 ) ;
return V_39 ;
}
static int F_35 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_16 * T_4 )
{
int V_39 ;
F_3 ( V_10 , V_12 ) ;
V_39 = F_36 ( V_10 , V_12 , T_4 ) ;
return V_39 ;
}
static int F_37 ( struct V_40 * V_40 )
{
if ( V_40 -> V_41 )
return 0 ;
if ( F_38 ( V_40 -> V_42 , V_40 -> V_43 ,
sizeof( V_40 -> V_43 ) ) > 0 ) {
V_40 -> V_41 = true ;
return 0 ;
}
return - 1 ;
}
static int F_39 ( struct V_40 * V_40 , struct V_9 * V_10 ,
struct V_32 * V_32 )
{
T_9 V_44 = V_45 ;
int V_39 ;
if ( F_37 ( V_40 ) < 0 ) {
F_40 ( L_2 , V_40 -> V_42 ) ;
return - 1 ;
}
if ( V_40 -> V_46 )
V_44 = V_47 ;
V_39 = F_41 ( V_10 , V_40 , V_44 , F_18 ,
V_32 ) ;
if ( V_39 ) {
F_17 ( L_3 , V_40 -> V_42 ) ;
return - 1 ;
}
return 0 ;
}
static int F_42 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_35 * V_36 V_15 ,
struct V_32 * V_32 )
{
struct V_48 V_49 ;
struct V_50 * V_50 ;
T_10 V_51 ;
V_51 = V_12 -> V_13 . V_44 & V_52 ;
V_50 = F_43 ( V_32 , T_7 -> V_53 , T_7 -> V_54 ) ;
if ( V_50 == NULL ) {
F_17 ( L_4 ,
V_12 -> V_13 . type ) ;
goto V_55;
}
F_44 ( V_50 , V_51 , V_56 , T_7 -> V_57 , & V_49 ) ;
if ( V_49 . V_58 != NULL ) {
if ( ! V_49 . V_58 -> V_40 -> V_59 ) {
V_49 . V_58 -> V_40 -> V_59 = 1 ;
if ( F_45 ( V_49 . V_58 , NULL ) >= 0 ) {
F_39 ( V_49 . V_58 -> V_40 , V_10 , V_32 ) ;
} else {
#ifdef F_46
F_47 ( L_5
L_6 ,
V_49 . V_58 -> V_40 -> V_42 ) ;
#endif
}
}
}
F_48 ( V_50 ) ;
V_55:
F_18 ( V_10 , V_12 , T_7 , V_32 ) ;
return 0 ;
}
static int F_49 ( struct V_9 * V_10 ,
union V_11 * V_12 V_15 ,
struct V_31 * T_7 ,
struct V_35 * V_36 V_15 ,
struct V_32 * V_32 V_15 )
{
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_10 ) ;
struct V_60 * V_61 ;
F_50 (ent, &inject->samples, node) {
if ( T_7 -> V_54 == V_61 -> V_54 ) {
F_51 ( & V_61 -> V_62 ) ;
free ( V_61 ) ;
break;
}
}
return 0 ;
}
static int F_52 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_35 * V_36 ,
struct V_32 * V_32 )
{
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_10 ) ;
struct V_60 * V_61 ;
F_49 ( V_10 , V_12 , T_7 , V_36 , V_32 ) ;
V_61 = malloc ( V_12 -> V_13 . V_5 + sizeof( struct V_60 ) ) ;
if ( V_61 == NULL ) {
F_53 ( V_63 , V_64 ,
L_7 ) ;
return - 1 ;
}
V_61 -> V_54 = T_7 -> V_54 ;
memcpy ( & V_61 -> V_12 , V_12 , V_12 -> V_13 . V_5 ) ;
F_54 ( & V_61 -> V_62 , & V_2 -> V_65 ) ;
return 0 ;
}
static int F_55 ( struct V_9 * V_10 ,
union V_11 * V_12 V_15 ,
struct V_31 * T_7 ,
struct V_35 * V_36 ,
struct V_32 * V_32 )
{
struct V_60 * V_61 ;
union V_11 * V_66 ;
struct V_31 V_67 ;
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_10 ) ;
T_11 V_53 = F_56 ( V_36 , T_7 , L_8 ) ;
F_50 (ent, &inject->samples, node) {
if ( V_53 == V_61 -> V_54 )
goto V_68;
}
return 0 ;
V_68:
V_66 = & V_61 -> V_12 [ 0 ] ;
F_57 ( V_36 , V_66 , & V_67 ) ;
V_67 . V_69 = T_7 -> V_69 ;
V_67 . time = T_7 -> time ;
F_58 ( V_66 , V_36 -> V_70 . V_71 ,
V_36 -> V_70 . V_72 , & V_67 ,
false ) ;
F_22 ( V_10 , V_66 , & V_67 , V_36 , V_32 ) ;
return F_18 ( V_10 , V_66 , & V_67 , V_32 ) ;
}
static void F_59 ( int T_12 V_15 )
{
V_73 = 1 ;
}
static int F_60 ( struct V_35 * V_36 ,
T_13 V_71 , const char * V_74 )
{
struct V_75 * V_70 = & V_36 -> V_70 ;
const char * V_76 = F_61 ( V_36 ) ;
if ( ! ( V_70 -> V_71 & V_71 ) ) {
F_17 ( L_9 ,
V_76 , V_74 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_62 ( struct V_9 * V_10 V_15 ,
union V_11 * V_12 V_15 ,
struct V_31 * T_7 V_15 ,
struct V_35 * V_36 V_15 ,
struct V_32 * V_32 V_15 )
{
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_17 * V_77 = V_2 -> T_4 -> V_77 ;
struct V_35 * V_36 ;
V_2 -> V_10 . V_78 = F_19 ;
F_64 (evlist, evsel)
V_36 -> V_37 = F_62 ;
}
static bool F_65 ( struct V_35 * V_36 )
{
return V_36 -> V_70 . V_79 || V_36 -> V_70 . V_80 || V_36 -> V_70 . V_81 ||
V_36 -> V_70 . V_82 ;
}
static bool F_66 ( struct V_17 * V_77 ,
struct V_35 * V_83 )
{
struct V_35 * V_36 ;
int V_84 = 0 ;
bool V_85 = false ;
if ( ! F_65 ( V_83 ) )
return true ;
F_64 (evlist, evsel) {
if ( V_36 -> V_37 != F_62 ) {
V_84 += 1 ;
if ( ( V_36 -> V_70 . V_71 & V_86 ) ==
( V_83 -> V_70 . V_71 & V_86 ) )
V_85 = true ;
}
}
return V_85 && V_84 == 1 ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_17 * V_77 = V_2 -> T_4 -> V_77 ;
struct V_35 * V_36 , * V_87 ;
F_68 (evlist, tmp, evsel) {
if ( V_36 -> V_37 == F_62 &&
F_66 ( V_77 , V_36 ) ) {
F_40 ( L_10 , F_61 ( V_36 ) ) ;
F_69 ( V_77 , V_36 ) ;
F_70 ( V_36 ) ;
}
}
}
static int F_71 ( struct V_1 * V_2 )
{
int V_19 = - V_30 ;
struct V_16 * T_4 = V_2 -> T_4 ;
struct V_88 * V_89 = & V_2 -> V_6 ;
int V_21 = F_16 ( V_89 ) ;
T_13 V_90 ;
signal ( V_91 , F_59 ) ;
if ( V_2 -> V_92 || V_2 -> V_93 ||
V_2 -> V_94 . V_95 ) {
V_2 -> V_10 . V_79 = F_23 ;
V_2 -> V_10 . V_80 = F_25 ;
V_2 -> V_10 . V_96 = F_27 ;
V_2 -> V_10 . V_97 = F_33 ;
}
V_90 = T_4 -> V_13 . V_98 ;
if ( V_2 -> V_92 ) {
V_2 -> V_10 . T_7 = F_42 ;
} else if ( V_2 -> V_93 ) {
struct V_35 * V_36 ;
F_64 (session->evlist, evsel) {
const char * V_76 = F_61 ( V_36 ) ;
if ( ! strcmp ( V_76 , L_11 ) ) {
if ( F_60 ( V_36 , V_99 , L_12 ) )
return - V_30 ;
V_36 -> V_37 = F_52 ;
} else if ( ! strcmp ( V_76 , L_13 ) )
V_36 -> V_37 = F_49 ;
else if ( ! strncmp ( V_76 , L_14 , 17 ) )
V_36 -> V_37 = F_55 ;
}
} else if ( V_2 -> V_94 . V_95 ) {
T_4 -> V_94 = & V_2 -> V_94 ;
V_2 -> V_94 . V_2 = true ;
V_2 -> V_10 . V_81 = F_29 ;
V_2 -> V_10 . exit = F_31 ;
V_2 -> V_10 . V_100 = F_35 ;
V_2 -> V_10 . V_101 = V_102 ;
V_2 -> V_10 . V_29 = V_103 ;
V_2 -> V_10 . V_104 = F_20 ;
V_2 -> V_10 . V_105 = F_20 ,
V_2 -> V_10 . V_14 = true ;
V_2 -> V_10 . V_106 = true ;
V_90 = 4096 ;
if ( V_2 -> V_107 )
F_63 ( V_2 ) ;
}
if ( ! V_2 -> V_94 . V_95 )
F_72 ( & T_4 -> V_26 ) ;
if ( ! V_89 -> V_20 )
F_13 ( V_21 , V_90 , V_108 ) ;
V_19 = F_73 ( T_4 ) ;
if ( ! V_89 -> V_20 ) {
if ( V_2 -> V_92 ) {
F_74 ( & T_4 -> V_13 ,
V_109 ) ;
if ( V_2 -> V_23 )
F_75 ( T_4 ) ;
}
if ( V_2 -> V_94 . V_95 ) {
struct V_35 * V_36 ;
F_76 ( & T_4 -> V_13 ,
V_110 ) ;
if ( V_2 -> V_94 . V_111 )
F_74 ( & T_4 -> V_13 ,
V_112 ) ;
V_36 = F_77 ( T_4 -> V_77 ,
V_2 -> V_33 ) ;
if ( V_36 ) {
F_40 ( L_10 ,
F_61 ( V_36 ) ) ;
F_69 ( T_4 -> V_77 , V_36 ) ;
F_70 ( V_36 ) ;
}
if ( V_2 -> V_107 )
F_67 ( V_2 ) ;
}
T_4 -> V_13 . V_98 = V_90 ;
T_4 -> V_13 . V_113 = V_2 -> V_8 ;
F_78 ( T_4 , T_4 -> V_77 , V_21 , true ) ;
}
return V_19 ;
}
int F_79 ( int V_114 , const char * * V_115 , const char * T_14 V_15 )
{
struct V_1 V_2 = {
. V_10 = {
. T_7 = F_21 ,
. V_79 = F_18 ,
. V_80 = F_18 ,
. V_81 = F_18 ,
. V_96 = F_18 ,
. exit = F_18 ,
. V_116 = F_18 ,
. V_117 = F_18 ,
. V_104 = F_18 ,
. V_105 = F_18 ,
. V_78 = F_18 ,
. F_10 = F_21 ,
. V_118 = F_18 ,
. V_119 = F_18 ,
. V_70 = F_7 ,
. V_97 = F_6 ,
. V_101 = F_6 ,
. V_29 = F_12 ,
. V_120 = F_6 ,
. V_121 = F_5 ,
. V_43 = F_6 ,
. V_100 = F_6 ,
} ,
. V_122 = L_15 ,
. V_65 = F_80 ( V_2 . V_65 ) ,
. V_6 = {
. V_123 = L_15 ,
. V_124 = V_125 ,
} ,
} ;
struct V_88 V_27 = {
. V_124 = V_126 ,
} ;
int V_19 ;
const struct V_127 V_128 [] = {
F_81 ( 'b' , L_16 , & V_2 . V_92 ,
L_17 ) ,
F_82 ( 'i' , L_18 , & V_2 . V_122 , L_19 ,
L_20 ) ,
F_82 ( 'o' , L_21 , & V_2 . V_6 . V_123 , L_19 ,
L_22 ) ,
F_81 ( 's' , L_23 , & V_2 . V_93 ,
L_24
L_25 ) ,
F_83 ( 'v' , L_26 , & V_129 ,
L_27 ) ,
F_82 ( 0 , L_28 , & V_130 . V_131 , L_19 ,
L_29 ) ,
F_81 ( 'f' , L_30 , & V_27 . V_132 , L_31 ) ,
F_84 ( 0 , L_32 , & V_2 . V_94 ,
NULL , L_33 , L_34 ,
V_133 ) ,
F_81 ( 0 , L_35 , & V_2 . V_107 ,
L_36 ) ,
F_85 ()
} ;
const char * const V_134 [] = {
L_37 ,
NULL
} ;
V_114 = F_86 ( V_114 , V_115 , V_128 , V_134 , 0 ) ;
if ( V_114 )
F_87 ( V_134 , V_128 ) ;
if ( V_2 . V_107 && ! V_2 . V_94 . V_95 ) {
F_17 ( L_38 ) ;
return - 1 ;
}
if ( F_88 ( & V_2 . V_6 ) ) {
perror ( L_39 ) ;
return - 1 ;
}
V_2 . V_10 . V_14 = V_2 . V_93 ;
V_27 . V_123 = V_2 . V_122 ;
V_2 . T_4 = F_89 ( & V_27 , true , & V_2 . V_10 ) ;
if ( V_2 . T_4 == NULL )
return - 1 ;
V_19 = F_90 ( & V_2 . T_4 -> V_13 . V_135 ) ;
if ( V_19 < 0 )
goto V_136;
V_19 = F_71 ( & V_2 ) ;
V_136:
F_91 ( V_2 . T_4 ) ;
return V_19 ;
}
