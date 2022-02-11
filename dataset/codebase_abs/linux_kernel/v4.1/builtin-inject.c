static int F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
T_1 V_7 ;
V_7 = F_3 ( & V_6 -> V_8 , V_4 ,
V_4 -> V_9 . V_7 ) ;
if ( V_7 < 0 )
return - V_10 ;
V_6 -> V_11 += V_7 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_12 * T_2 V_13 )
{
return F_1 ( V_2 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_14 * T_3
V_13 )
{
return F_1 ( V_2 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_15 * * V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
int V_17 ;
V_17 = F_7 ( V_2 , V_4 , V_16 ) ;
if ( V_17 )
return V_17 ;
if ( ! V_6 -> V_8 . V_18 )
return 0 ;
return F_1 ( V_2 , V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_19 * T_4 V_13 ,
struct V_20 * V_20 V_13 )
{
return F_1 ( V_2 , V_4 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_19 * T_4 ,
struct V_21 * V_22 ,
struct V_20 * V_20 )
{
if ( V_22 -> V_23 ) {
T_5 V_24 = V_22 -> V_23 ;
return V_24 ( V_2 , V_4 , T_4 , V_22 , V_20 ) ;
}
F_10 ( V_2 , V_4 , T_4 , V_22 , V_20 ) ;
return F_1 ( V_2 , V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_19 * T_4 ,
struct V_20 * V_20 )
{
int V_25 ;
V_25 = F_12 ( V_2 , V_4 , T_4 , V_20 ) ;
F_8 ( V_2 , V_4 , T_4 , V_20 ) ;
return V_25 ;
}
static int F_13 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_19 * T_4 ,
struct V_20 * V_20 )
{
int V_25 ;
V_25 = F_14 ( V_2 , V_4 , T_4 , V_20 ) ;
F_8 ( V_2 , V_4 , T_4 , V_20 ) ;
return V_25 ;
}
static int F_15 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_19 * T_4 ,
struct V_20 * V_20 )
{
int V_25 ;
V_25 = F_16 ( V_2 , V_4 , T_4 , V_20 ) ;
F_8 ( V_2 , V_4 , T_4 , V_20 ) ;
return V_25 ;
}
static int F_17 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_14 * T_3 )
{
int V_25 ;
F_1 ( V_2 , V_4 ) ;
V_25 = F_18 ( V_2 , V_4 , T_3 ) ;
return V_25 ;
}
static int F_19 ( struct V_26 * V_26 )
{
if ( V_26 -> V_27 )
return 0 ;
if ( F_20 ( V_26 -> V_28 , V_26 -> V_29 ,
sizeof( V_26 -> V_29 ) ) > 0 ) {
V_26 -> V_27 = true ;
return 0 ;
}
return - 1 ;
}
static int F_21 ( struct V_26 * V_26 , struct V_1 * V_2 ,
struct V_20 * V_20 )
{
T_6 V_30 = V_31 ;
int V_25 ;
if ( F_19 ( V_26 ) < 0 ) {
F_22 ( L_1 , V_26 -> V_28 ) ;
return - 1 ;
}
if ( V_26 -> V_32 )
V_30 = V_33 ;
V_25 = F_23 ( V_2 , V_26 , V_30 , F_8 ,
V_20 ) ;
if ( V_25 ) {
F_24 ( L_2 , V_26 -> V_28 ) ;
return - 1 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_19 * T_4 ,
struct V_21 * V_22 V_13 ,
struct V_20 * V_20 )
{
struct V_34 V_35 ;
struct V_36 * V_36 ;
T_7 V_37 ;
V_37 = V_4 -> V_9 . V_30 & V_38 ;
V_36 = F_26 ( V_20 , T_4 -> V_39 , T_4 -> V_40 ) ;
if ( V_36 == NULL ) {
F_24 ( L_3 ,
V_4 -> V_9 . type ) ;
goto V_41;
}
F_27 ( V_36 , V_37 , V_42 , T_4 -> V_43 , & V_35 ) ;
if ( V_35 . V_44 != NULL ) {
if ( ! V_35 . V_44 -> V_26 -> V_45 ) {
V_35 . V_44 -> V_26 -> V_45 = 1 ;
if ( F_28 ( V_35 . V_44 , NULL ) >= 0 ) {
F_21 ( V_35 . V_44 -> V_26 , V_2 , V_20 ) ;
} else {
#ifdef F_29
F_30 ( L_4
L_5 ,
V_35 . V_44 -> V_26 -> V_28 ) ;
#endif
}
}
}
V_41:
F_8 ( V_2 , V_4 , T_4 , V_20 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
union V_3 * V_4 V_13 ,
struct V_19 * T_4 ,
struct V_21 * V_22 V_13 ,
struct V_20 * V_20 V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_46 * V_47 ;
F_32 (ent, &inject->samples, node) {
if ( T_4 -> V_40 == V_47 -> V_40 ) {
F_33 ( & V_47 -> V_48 ) ;
free ( V_47 ) ;
break;
}
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_19 * T_4 ,
struct V_21 * V_22 ,
struct V_20 * V_20 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_46 * V_47 ;
F_31 ( V_2 , V_4 , T_4 , V_22 , V_20 ) ;
V_47 = malloc ( V_4 -> V_9 . V_7 + sizeof( struct V_46 ) ) ;
if ( V_47 == NULL ) {
F_35 ( V_49 , V_50 ,
L_6 ) ;
return - 1 ;
}
V_47 -> V_40 = T_4 -> V_40 ;
memcpy ( & V_47 -> V_4 , V_4 , V_4 -> V_9 . V_7 ) ;
F_36 ( & V_47 -> V_48 , & V_6 -> V_51 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
union V_3 * V_4 V_13 ,
struct V_19 * T_4 ,
struct V_21 * V_22 ,
struct V_20 * V_20 )
{
struct V_46 * V_47 ;
union V_3 * V_52 ;
struct V_19 V_53 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
T_8 V_39 = F_38 ( V_22 , T_4 , L_7 ) ;
F_32 (ent, &inject->samples, node) {
if ( V_39 == V_47 -> V_40 )
goto V_54;
}
return 0 ;
V_54:
V_52 = & V_47 -> V_4 [ 0 ] ;
F_39 ( V_22 , V_52 , & V_53 ) ;
V_53 . V_55 = T_4 -> V_55 ;
V_53 . time = T_4 -> time ;
F_40 ( V_52 , V_22 -> V_56 . V_57 ,
V_22 -> V_56 . V_58 , & V_53 ,
false ) ;
F_10 ( V_2 , V_52 , & V_53 , V_22 , V_20 ) ;
return F_8 ( V_2 , V_52 , & V_53 , V_20 ) ;
}
static void F_41 ( int T_9 V_13 )
{
V_59 = 1 ;
}
static int F_42 ( struct V_21 * V_22 ,
T_10 V_57 , const char * V_60 )
{
struct V_61 * V_56 = & V_22 -> V_56 ;
const char * V_62 = F_43 ( V_22 ) ;
if ( ! ( V_56 -> V_57 & V_57 ) ) {
F_24 ( L_8 ,
V_62 , V_60 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_44 ( struct V_5 * V_6 )
{
int V_17 = - V_63 ;
struct V_14 * T_3 = V_6 -> T_3 ;
struct V_64 * V_65 = & V_6 -> V_8 ;
int V_66 = F_45 ( V_65 ) ;
signal ( V_67 , F_41 ) ;
if ( V_6 -> V_68 || V_6 -> V_69 ) {
V_6 -> V_2 . V_70 = F_11 ;
V_6 -> V_2 . V_71 = F_13 ;
V_6 -> V_2 . V_72 = F_15 ;
V_6 -> V_2 . V_73 = F_17 ;
}
if ( V_6 -> V_68 ) {
V_6 -> V_2 . T_4 = F_25 ;
} else if ( V_6 -> V_69 ) {
struct V_21 * V_22 ;
F_46 (session->evlist, evsel) {
const char * V_62 = F_43 ( V_22 ) ;
if ( ! strcmp ( V_62 , L_9 ) ) {
if ( F_42 ( V_22 , V_74 , L_10 ) )
return - V_63 ;
V_22 -> V_23 = F_34 ;
} else if ( ! strcmp ( V_62 , L_11 ) )
V_22 -> V_23 = F_31 ;
else if ( ! strncmp ( V_62 , L_12 , 17 ) )
V_22 -> V_23 = F_37 ;
}
}
if ( ! V_65 -> V_18 )
F_47 ( V_66 , T_3 -> V_9 . V_75 , V_76 ) ;
V_17 = F_48 ( T_3 ) ;
if ( ! V_65 -> V_18 ) {
if ( V_6 -> V_68 )
F_49 ( & T_3 -> V_9 ,
V_77 ) ;
T_3 -> V_9 . V_78 = V_6 -> V_11 ;
F_50 ( T_3 , T_3 -> V_79 , V_66 , true ) ;
}
return V_17 ;
}
int F_51 ( int V_80 , const char * * V_81 , const char * T_11 V_13 )
{
struct V_5 V_6 = {
. V_2 = {
. T_4 = F_9 ,
. V_70 = F_8 ,
. V_71 = F_8 ,
. V_82 = F_8 ,
. V_72 = F_8 ,
. exit = F_8 ,
. V_83 = F_8 ,
. V_84 = F_9 ,
. V_85 = F_8 ,
. V_86 = F_8 ,
. V_56 = F_6 ,
. V_73 = F_5 ,
. V_87 = F_4 ,
. V_29 = F_5 ,
. V_88 = F_5 ,
} ,
. V_89 = L_13 ,
. V_51 = F_52 ( V_6 . V_51 ) ,
. V_8 = {
. V_90 = L_13 ,
. V_91 = V_92 ,
} ,
} ;
struct V_64 V_93 = {
. V_91 = V_94 ,
} ;
int V_17 ;
const struct V_95 V_96 [] = {
F_53 ( 'b' , L_14 , & V_6 . V_68 ,
L_15 ) ,
F_54 ( 'i' , L_16 , & V_6 . V_89 , L_17 ,
L_18 ) ,
F_54 ( 'o' , L_19 , & V_6 . V_8 . V_90 , L_17 ,
L_20 ) ,
F_53 ( 's' , L_21 , & V_6 . V_69 ,
L_22
L_23 ) ,
F_55 ( 'v' , L_24 , & V_97 ,
L_25 ) ,
F_54 ( 0 , L_26 , & V_98 . V_99 , L_17 ,
L_27 ) ,
F_53 ( 'f' , L_28 , & V_93 . V_100 , L_29 ) ,
F_56 ()
} ;
const char * const V_101 [] = {
L_30 ,
NULL
} ;
V_80 = F_57 ( V_80 , V_81 , V_96 , V_101 , 0 ) ;
if ( V_80 )
F_58 ( V_101 , V_96 ) ;
if ( F_59 ( & V_6 . V_8 ) ) {
perror ( L_31 ) ;
return - 1 ;
}
V_6 . V_2 . V_12 = V_6 . V_69 ;
V_93 . V_90 = V_6 . V_89 ;
V_6 . T_3 = F_60 ( & V_93 , true , & V_6 . V_2 ) ;
if ( V_6 . T_3 == NULL )
return - 1 ;
if ( F_61 ( & V_6 . T_3 -> V_9 . V_102 ) < 0 )
return - 1 ;
V_17 = F_44 ( & V_6 ) ;
F_62 ( V_6 . T_3 ) ;
return V_17 ;
}
