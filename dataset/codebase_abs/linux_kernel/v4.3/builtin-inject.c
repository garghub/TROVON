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
static int F_19 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_33 * V_34 ,
struct V_32 * V_32 )
{
if ( V_34 -> V_35 ) {
T_8 V_36 = V_34 -> V_35 ;
return V_36 ( V_10 , V_12 , T_7 , V_34 , V_32 ) ;
}
F_20 ( V_10 , V_12 , T_7 , V_34 , V_32 ) ;
return F_3 ( V_10 , V_12 ) ;
}
static int F_21 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
int V_37 ;
V_37 = F_22 ( V_10 , V_12 , T_7 , V_32 ) ;
F_18 ( V_10 , V_12 , T_7 , V_32 ) ;
return V_37 ;
}
static int F_23 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
int V_37 ;
V_37 = F_24 ( V_10 , V_12 , T_7 , V_32 ) ;
F_18 ( V_10 , V_12 , T_7 , V_32 ) ;
return V_37 ;
}
static int F_25 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
int V_37 ;
V_37 = F_26 ( V_10 , V_12 , T_7 , V_32 ) ;
F_18 ( V_10 , V_12 , T_7 , V_32 ) ;
return V_37 ;
}
static int F_27 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
int V_37 ;
V_37 = F_28 ( V_10 , V_12 , T_7 , V_32 ) ;
F_18 ( V_10 , V_12 , T_7 , V_32 ) ;
return V_37 ;
}
static int F_29 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_32 * V_32 )
{
int V_37 ;
V_37 = F_30 ( V_10 , V_12 , T_7 , V_32 ) ;
F_18 ( V_10 , V_12 , T_7 , V_32 ) ;
return V_37 ;
}
static int F_31 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_16 * T_4 )
{
int V_37 ;
F_3 ( V_10 , V_12 ) ;
V_37 = F_32 ( V_10 , V_12 , T_4 ) ;
return V_37 ;
}
static int F_33 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_16 * T_4 )
{
int V_37 ;
F_3 ( V_10 , V_12 ) ;
V_37 = F_34 ( V_10 , V_12 , T_4 ) ;
return V_37 ;
}
static int F_35 ( struct V_38 * V_38 )
{
if ( V_38 -> V_39 )
return 0 ;
if ( F_36 ( V_38 -> V_40 , V_38 -> V_41 ,
sizeof( V_38 -> V_41 ) ) > 0 ) {
V_38 -> V_39 = true ;
return 0 ;
}
return - 1 ;
}
static int F_37 ( struct V_38 * V_38 , struct V_9 * V_10 ,
struct V_32 * V_32 )
{
T_9 V_42 = V_43 ;
int V_37 ;
if ( F_35 ( V_38 ) < 0 ) {
F_38 ( L_2 , V_38 -> V_40 ) ;
return - 1 ;
}
if ( V_38 -> V_44 )
V_42 = V_45 ;
V_37 = F_39 ( V_10 , V_38 , V_42 , F_18 ,
V_32 ) ;
if ( V_37 ) {
F_17 ( L_3 , V_38 -> V_40 ) ;
return - 1 ;
}
return 0 ;
}
static int F_40 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_33 * V_34 V_15 ,
struct V_32 * V_32 )
{
struct V_46 V_47 ;
struct V_48 * V_48 ;
T_10 V_49 ;
V_49 = V_12 -> V_13 . V_42 & V_50 ;
V_48 = F_41 ( V_32 , T_7 -> V_51 , T_7 -> V_52 ) ;
if ( V_48 == NULL ) {
F_17 ( L_4 ,
V_12 -> V_13 . type ) ;
goto V_53;
}
F_42 ( V_48 , V_49 , V_54 , T_7 -> V_55 , & V_47 ) ;
if ( V_47 . V_56 != NULL ) {
if ( ! V_47 . V_56 -> V_38 -> V_57 ) {
V_47 . V_56 -> V_38 -> V_57 = 1 ;
if ( F_43 ( V_47 . V_56 , NULL ) >= 0 ) {
F_37 ( V_47 . V_56 -> V_38 , V_10 , V_32 ) ;
} else {
#ifdef F_44
F_45 ( L_5
L_6 ,
V_47 . V_56 -> V_38 -> V_40 ) ;
#endif
}
}
}
F_46 ( V_48 ) ;
V_53:
F_18 ( V_10 , V_12 , T_7 , V_32 ) ;
return 0 ;
}
static int F_47 ( struct V_9 * V_10 ,
union V_11 * V_12 V_15 ,
struct V_31 * T_7 ,
struct V_33 * V_34 V_15 ,
struct V_32 * V_32 V_15 )
{
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_10 ) ;
struct V_58 * V_59 ;
F_48 (ent, &inject->samples, node) {
if ( T_7 -> V_52 == V_59 -> V_52 ) {
F_49 ( & V_59 -> V_60 ) ;
free ( V_59 ) ;
break;
}
}
return 0 ;
}
static int F_50 ( struct V_9 * V_10 ,
union V_11 * V_12 ,
struct V_31 * T_7 ,
struct V_33 * V_34 ,
struct V_32 * V_32 )
{
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_10 ) ;
struct V_58 * V_59 ;
F_47 ( V_10 , V_12 , T_7 , V_34 , V_32 ) ;
V_59 = malloc ( V_12 -> V_13 . V_5 + sizeof( struct V_58 ) ) ;
if ( V_59 == NULL ) {
F_51 ( V_61 , V_62 ,
L_7 ) ;
return - 1 ;
}
V_59 -> V_52 = T_7 -> V_52 ;
memcpy ( & V_59 -> V_12 , V_12 , V_12 -> V_13 . V_5 ) ;
F_52 ( & V_59 -> V_60 , & V_2 -> V_63 ) ;
return 0 ;
}
static int F_53 ( struct V_9 * V_10 ,
union V_11 * V_12 V_15 ,
struct V_31 * T_7 ,
struct V_33 * V_34 ,
struct V_32 * V_32 )
{
struct V_58 * V_59 ;
union V_11 * V_64 ;
struct V_31 V_65 ;
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 , V_10 ) ;
T_11 V_51 = F_54 ( V_34 , T_7 , L_8 ) ;
F_48 (ent, &inject->samples, node) {
if ( V_51 == V_59 -> V_52 )
goto V_66;
}
return 0 ;
V_66:
V_64 = & V_59 -> V_12 [ 0 ] ;
F_55 ( V_34 , V_64 , & V_65 ) ;
V_65 . V_67 = T_7 -> V_67 ;
V_65 . time = T_7 -> time ;
F_56 ( V_64 , V_34 -> V_68 . V_69 ,
V_34 -> V_68 . V_70 , & V_65 ,
false ) ;
F_20 ( V_10 , V_64 , & V_65 , V_34 , V_32 ) ;
return F_18 ( V_10 , V_64 , & V_65 , V_32 ) ;
}
static void F_57 ( int T_12 V_15 )
{
V_71 = 1 ;
}
static int F_58 ( struct V_33 * V_34 ,
T_13 V_69 , const char * V_72 )
{
struct V_73 * V_68 = & V_34 -> V_68 ;
const char * V_74 = F_59 ( V_34 ) ;
if ( ! ( V_68 -> V_69 & V_69 ) ) {
F_17 ( L_9 ,
V_74 , V_72 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_19 = - V_30 ;
struct V_16 * T_4 = V_2 -> T_4 ;
struct V_75 * V_76 = & V_2 -> V_6 ;
int V_21 = F_16 ( V_76 ) ;
T_13 V_77 ;
signal ( V_78 , F_57 ) ;
if ( V_2 -> V_79 || V_2 -> V_80 ||
V_2 -> V_81 . V_82 ) {
V_2 -> V_10 . V_83 = F_21 ;
V_2 -> V_10 . V_84 = F_23 ;
V_2 -> V_10 . V_85 = F_25 ;
V_2 -> V_10 . V_86 = F_31 ;
}
V_77 = T_4 -> V_13 . V_87 ;
if ( V_2 -> V_79 ) {
V_2 -> V_10 . T_7 = F_40 ;
} else if ( V_2 -> V_80 ) {
struct V_33 * V_34 ;
F_61 (session->evlist, evsel) {
const char * V_74 = F_59 ( V_34 ) ;
if ( ! strcmp ( V_74 , L_10 ) ) {
if ( F_58 ( V_34 , V_88 , L_11 ) )
return - V_30 ;
V_34 -> V_35 = F_50 ;
} else if ( ! strcmp ( V_74 , L_12 ) )
V_34 -> V_35 = F_47 ;
else if ( ! strncmp ( V_74 , L_13 , 17 ) )
V_34 -> V_35 = F_53 ;
}
} else if ( V_2 -> V_81 . V_82 ) {
T_4 -> V_81 = & V_2 -> V_81 ;
V_2 -> V_81 . V_2 = true ;
V_2 -> V_10 . V_89 = F_27 ;
V_2 -> V_10 . exit = F_29 ;
V_2 -> V_10 . V_90 = F_33 ;
V_2 -> V_10 . V_91 = V_92 ;
V_2 -> V_10 . V_29 = V_93 ;
V_2 -> V_10 . V_14 = true ;
V_2 -> V_10 . V_94 = true ;
V_77 = 4096 ;
}
if ( ! V_2 -> V_81 . V_82 )
F_62 ( & T_4 -> V_26 ) ;
if ( ! V_76 -> V_20 )
F_13 ( V_21 , V_77 , V_95 ) ;
V_19 = F_63 ( T_4 ) ;
if ( ! V_76 -> V_20 ) {
if ( V_2 -> V_79 ) {
F_64 ( & T_4 -> V_13 ,
V_96 ) ;
if ( V_2 -> V_23 )
F_65 ( T_4 ) ;
}
if ( V_2 -> V_81 . V_82 )
F_66 ( & T_4 -> V_13 ,
V_97 ) ;
T_4 -> V_13 . V_87 = V_77 ;
T_4 -> V_13 . V_98 = V_2 -> V_8 ;
F_67 ( T_4 , T_4 -> V_99 , V_21 , true ) ;
}
return V_19 ;
}
int F_68 ( int V_100 , const char * * V_101 , const char * T_14 V_15 )
{
struct V_1 V_2 = {
. V_10 = {
. T_7 = F_19 ,
. V_83 = F_18 ,
. V_84 = F_18 ,
. V_89 = F_18 ,
. V_85 = F_18 ,
. exit = F_18 ,
. V_102 = F_18 ,
. V_103 = F_18 ,
. V_104 = F_18 ,
. V_105 = F_18 ,
. F_10 = F_19 ,
. V_106 = F_18 ,
. V_107 = F_18 ,
. V_68 = F_7 ,
. V_86 = F_6 ,
. V_91 = F_6 ,
. V_29 = F_12 ,
. V_108 = F_6 ,
. V_109 = F_5 ,
. V_41 = F_6 ,
. V_90 = F_6 ,
} ,
. V_110 = L_14 ,
. V_63 = F_69 ( V_2 . V_63 ) ,
. V_6 = {
. V_111 = L_14 ,
. V_112 = V_113 ,
} ,
} ;
struct V_75 V_27 = {
. V_112 = V_114 ,
} ;
int V_19 ;
const struct V_115 V_116 [] = {
F_70 ( 'b' , L_15 , & V_2 . V_79 ,
L_16 ) ,
F_71 ( 'i' , L_17 , & V_2 . V_110 , L_18 ,
L_19 ) ,
F_71 ( 'o' , L_20 , & V_2 . V_6 . V_111 , L_18 ,
L_21 ) ,
F_70 ( 's' , L_22 , & V_2 . V_80 ,
L_23
L_24 ) ,
F_72 ( 'v' , L_25 , & V_117 ,
L_26 ) ,
F_71 ( 0 , L_27 , & V_118 . V_119 , L_18 ,
L_28 ) ,
F_70 ( 'f' , L_29 , & V_27 . V_120 , L_30 ) ,
F_73 ( 0 , L_31 , & V_2 . V_81 ,
NULL , L_32 , L_33 ,
V_121 ) ,
F_74 ()
} ;
const char * const V_122 [] = {
L_34 ,
NULL
} ;
V_100 = F_75 ( V_100 , V_101 , V_116 , V_122 , 0 ) ;
if ( V_100 )
F_76 ( V_122 , V_116 ) ;
if ( F_77 ( & V_2 . V_6 ) ) {
perror ( L_35 ) ;
return - 1 ;
}
V_2 . V_10 . V_14 = V_2 . V_80 ;
V_27 . V_111 = V_2 . V_110 ;
V_2 . T_4 = F_78 ( & V_27 , true , & V_2 . V_10 ) ;
if ( V_2 . T_4 == NULL )
return - 1 ;
V_19 = F_79 ( & V_2 . T_4 -> V_13 . V_123 ) ;
if ( V_19 < 0 )
goto V_124;
V_19 = F_60 ( & V_2 ) ;
V_124:
F_80 ( V_2 . T_4 ) ;
return V_19 ;
}
