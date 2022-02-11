static int F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_5 * V_5 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
T_1 V_9 ;
void * V_10 = V_4 ;
V_9 = V_4 -> V_11 . V_9 ;
while ( V_9 ) {
int V_12 = F_3 ( V_8 -> V_13 , V_10 , V_9 ) ;
if ( V_12 < 0 )
return - V_14 ;
V_9 -= V_12 ;
V_10 += V_12 ;
V_8 -> V_15 += V_12 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_16 * T_2
V_6 )
{
return F_1 ( V_2 , V_4 , NULL ) ;
}
static int F_5 ( struct V_1 * V_2 ,
union V_3 * V_4 )
{
return F_1 ( V_2 , V_4 , NULL ) ;
}
static int F_6 ( union V_3 * V_4 ,
struct V_16 * T_2
V_6 )
{
return F_1 ( NULL , V_4 , NULL ) ;
}
static int F_7 ( union V_3 * V_4 ,
struct V_17 * * T_3 V_6 )
{
int V_12 ;
V_12 = F_8 ( V_4 , T_3 ) ;
if ( V_12 )
return V_12 ;
return F_1 ( NULL , V_4 , NULL ) ;
}
static int F_9 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_4 V_6 ,
struct V_5 * V_5 )
{
return F_1 ( V_2 , V_4 , V_5 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_4 ,
struct V_19 * V_20 ,
struct V_5 * V_5 )
{
if ( V_20 -> V_21 . V_22 ) {
T_5 V_23 = V_20 -> V_21 . V_22 ;
return V_23 ( V_2 , V_4 , T_4 , V_20 , V_5 ) ;
}
F_11 ( V_2 , V_4 , T_4 , V_20 , V_5 ) ;
return F_1 ( V_2 , V_4 , V_5 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_4 ,
struct V_5 * V_5 )
{
int V_24 ;
V_24 = F_13 ( V_2 , V_4 , T_4 , V_5 ) ;
F_9 ( V_2 , V_4 , T_4 , V_5 ) ;
return V_24 ;
}
static int F_14 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_4 ,
struct V_5 * V_5 )
{
int V_24 ;
V_24 = F_15 ( V_2 , V_4 , T_4 , V_5 ) ;
F_9 ( V_2 , V_4 , T_4 , V_5 ) ;
return V_24 ;
}
static int F_16 ( union V_3 * V_4 ,
struct V_16 * T_2 )
{
int V_24 ;
F_1 ( NULL , V_4 , NULL ) ;
V_24 = F_17 ( V_4 , T_2 ) ;
return V_24 ;
}
static int F_18 ( struct V_25 * V_26 )
{
if ( V_26 -> V_27 )
return 0 ;
if ( F_19 ( V_26 -> V_28 , V_26 -> V_29 ,
sizeof( V_26 -> V_29 ) ) > 0 ) {
V_26 -> V_27 = true ;
return 0 ;
}
return - 1 ;
}
static int F_20 ( struct V_25 * V_26 , struct V_1 * V_2 ,
struct V_5 * V_5 )
{
T_6 V_30 = V_31 ;
int V_24 ;
if ( F_18 ( V_26 ) < 0 ) {
F_21 ( L_1 , V_26 -> V_28 ) ;
return - 1 ;
}
if ( V_26 -> V_32 )
V_30 = V_33 ;
V_24 = F_22 ( V_2 , V_26 , V_30 , F_9 ,
V_5 ) ;
if ( V_24 ) {
F_23 ( L_2 , V_26 -> V_28 ) ;
return - 1 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_4 ,
struct V_19 * V_20 V_6 ,
struct V_5 * V_5 )
{
struct V_34 V_35 ;
struct V_36 * V_36 ;
T_7 V_37 ;
V_37 = V_4 -> V_11 . V_30 & V_38 ;
V_36 = F_25 ( V_5 , V_4 -> V_39 . V_40 ) ;
if ( V_36 == NULL ) {
F_23 ( L_3 ,
V_4 -> V_11 . type ) ;
goto V_41;
}
F_26 ( V_36 , V_5 , V_37 , V_42 ,
V_4 -> V_39 . V_39 , & V_35 ) ;
if ( V_35 . V_43 != NULL ) {
if ( ! V_35 . V_43 -> V_25 -> V_44 ) {
V_35 . V_43 -> V_25 -> V_44 = 1 ;
if ( F_27 ( V_35 . V_43 , NULL ) >= 0 ) {
F_20 ( V_35 . V_43 -> V_25 , V_2 , V_5 ) ;
} else {
#ifdef F_28
F_29 ( L_4
L_5 ,
V_35 . V_43 -> V_25 -> V_28 ) ;
#endif
}
}
}
V_41:
F_9 ( V_2 , V_4 , T_4 , V_5 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
union V_3 * V_4 V_6 ,
struct V_18 * T_4 ,
struct V_19 * V_20 V_6 ,
struct V_5 * V_5 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
struct V_45 * V_46 ;
F_31 (ent, &inject->samples, node) {
if ( T_4 -> V_47 == V_46 -> V_47 ) {
F_32 ( & V_46 -> V_48 ) ;
free ( V_46 ) ;
break;
}
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_4 ,
struct V_19 * V_20 ,
struct V_5 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
struct V_45 * V_46 ;
F_30 ( V_2 , V_4 , T_4 , V_20 , V_5 ) ;
V_46 = malloc ( V_4 -> V_11 . V_9 + sizeof( struct V_45 ) ) ;
if ( V_46 == NULL ) {
F_34 ( V_49 , V_50 ,
L_6 ) ;
return - 1 ;
}
V_46 -> V_47 = T_4 -> V_47 ;
memcpy ( & V_46 -> V_4 , V_4 , V_4 -> V_11 . V_9 ) ;
F_35 ( & V_46 -> V_48 , & V_8 -> V_51 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
union V_3 * V_4 V_6 ,
struct V_18 * T_4 ,
struct V_19 * V_20 ,
struct V_5 * V_5 )
{
struct V_45 * V_46 ;
union V_3 * V_52 ;
struct V_18 V_53 ;
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
T_8 V_40 = F_37 ( V_20 , T_4 , L_7 ) ;
F_31 (ent, &inject->samples, node) {
if ( V_40 == V_46 -> V_47 )
goto V_54;
}
return 0 ;
V_54:
V_52 = & V_46 -> V_4 [ 0 ] ;
F_38 ( V_20 , V_52 , & V_53 ) ;
V_53 . V_55 = T_4 -> V_55 ;
V_53 . time = T_4 -> time ;
F_39 ( V_52 , V_20 -> V_56 . V_57 ,
& V_53 , false ) ;
F_11 ( V_2 , V_52 , & V_53 , V_20 , V_5 ) ;
return F_9 ( V_2 , V_52 , & V_53 , V_5 ) ;
}
static void F_40 ( int T_9 V_6 )
{
V_58 = 1 ;
}
static int F_41 ( struct V_19 * V_20 ,
T_10 V_57 , const char * V_59 )
{
struct V_60 * V_56 = & V_20 -> V_56 ;
const char * V_61 = F_42 ( V_20 ) ;
if ( ! ( V_56 -> V_57 & V_57 ) ) {
F_23 ( L_8 ,
V_61 , V_59 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_43 ( struct V_7 * V_8 )
{
struct V_16 * T_2 ;
int V_12 = - V_62 ;
signal ( V_63 , F_40 ) ;
if ( V_8 -> V_64 || V_8 -> V_65 ) {
V_8 -> V_2 . V_66 = F_12 ;
V_8 -> V_2 . V_67 = F_14 ;
V_8 -> V_2 . V_68 = F_16 ;
}
T_2 = F_44 ( V_8 -> V_69 , V_70 , false , true , & V_8 -> V_2 ) ;
if ( T_2 == NULL )
return - V_71 ;
if ( V_8 -> V_64 ) {
V_8 -> V_2 . T_4 = F_24 ;
} else if ( V_8 -> V_65 ) {
struct V_19 * V_20 ;
V_8 -> V_2 . V_72 = true ;
F_31 (evsel, &session->evlist->entries, node) {
const char * V_61 = F_42 ( V_20 ) ;
if ( ! strcmp ( V_61 , L_9 ) ) {
if ( F_41 ( V_20 , V_73 , L_10 ) )
return - V_62 ;
V_20 -> V_21 . V_22 = F_33 ;
} else if ( ! strcmp ( V_61 , L_11 ) )
V_20 -> V_21 . V_22 = F_30 ;
else if ( ! strncmp ( V_61 , L_12 , 17 ) )
V_20 -> V_21 . V_22 = F_36 ;
}
}
if ( ! V_8 -> V_74 )
F_45 ( V_8 -> V_13 , T_2 -> V_11 . V_75 , V_76 ) ;
V_12 = F_46 ( T_2 , & V_8 -> V_2 ) ;
if ( ! V_8 -> V_74 ) {
T_2 -> V_11 . V_77 = V_8 -> V_15 ;
F_47 ( T_2 , T_2 -> V_78 , V_8 -> V_13 , true ) ;
}
F_48 ( T_2 ) ;
return V_12 ;
}
int F_49 ( int V_79 , const char * * V_80 , const char * T_11 V_6 )
{
struct V_7 V_8 = {
. V_2 = {
. T_4 = F_10 ,
. V_66 = F_9 ,
. V_81 = F_9 ,
. V_67 = F_9 ,
. exit = F_9 ,
. V_82 = F_9 ,
. V_83 = F_10 ,
. V_84 = F_9 ,
. V_85 = F_9 ,
. V_56 = F_7 ,
. V_86 = F_5 ,
. V_68 = F_6 ,
. V_29 = F_4 ,
} ,
. V_69 = L_13 ,
. V_51 = F_50 ( V_8 . V_51 ) ,
} ;
const char * V_87 = L_13 ;
const struct V_88 V_89 [] = {
F_51 ( 'b' , L_14 , & V_8 . V_64 ,
L_15 ) ,
F_52 ( 'i' , L_16 , & V_8 . V_69 , L_17 ,
L_18 ) ,
F_52 ( 'o' , L_19 , & V_87 , L_17 ,
L_20 ) ,
F_51 ( 's' , L_21 , & V_8 . V_65 ,
L_22
L_23 ) ,
F_53 ( 'v' , L_24 , & V_90 ,
L_25 ) ,
F_54 ()
} ;
const char * const V_91 [] = {
L_26 ,
NULL
} ;
V_79 = F_55 ( V_79 , V_80 , V_89 , V_91 , 0 ) ;
if ( V_79 )
F_56 ( V_91 , V_89 ) ;
if ( ! strcmp ( V_87 , L_13 ) ) {
V_8 . V_74 = 1 ;
V_8 . V_13 = V_92 ;
} else {
V_8 . V_13 = F_57 ( V_87 , V_93 | V_94 | V_95 ,
V_96 | V_97 ) ;
if ( V_8 . V_13 < 0 ) {
perror ( L_27 ) ;
return - 1 ;
}
}
if ( F_58 () < 0 )
return - 1 ;
return F_43 ( & V_8 ) ;
}
