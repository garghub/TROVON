static int F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
T_1 V_7 ;
void * V_8 = V_4 ;
V_7 = V_4 -> V_9 . V_7 ;
while ( V_7 ) {
int V_10 = F_3 ( V_6 -> V_11 , V_8 , V_7 ) ;
if ( V_10 < 0 )
return - V_12 ;
V_7 -= V_10 ;
V_8 += V_10 ;
V_6 -> V_13 += V_10 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_14 * T_2
V_15 )
{
return F_1 ( V_2 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_16 * * V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
int V_10 ;
V_10 = F_6 ( V_2 , V_4 , V_17 ) ;
if ( V_10 )
return V_10 ;
if ( ! V_6 -> V_18 )
return 0 ;
return F_1 ( V_2 , V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_19 * T_3 V_15 ,
struct V_20 * V_20 V_15 )
{
return F_1 ( V_2 , V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_19 * T_3 ,
struct V_21 * V_22 ,
struct V_20 * V_20 )
{
if ( V_22 -> V_23 ) {
T_4 V_24 = V_22 -> V_23 ;
return V_24 ( V_2 , V_4 , T_3 , V_22 , V_20 ) ;
}
F_9 ( V_2 , V_4 , T_3 , V_22 , V_20 ) ;
return F_1 ( V_2 , V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_19 * T_3 ,
struct V_20 * V_20 )
{
int V_25 ;
V_25 = F_11 ( V_2 , V_4 , T_3 , V_20 ) ;
F_7 ( V_2 , V_4 , T_3 , V_20 ) ;
return V_25 ;
}
static int F_12 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_19 * T_3 ,
struct V_20 * V_20 )
{
int V_25 ;
V_25 = F_13 ( V_2 , V_4 , T_3 , V_20 ) ;
F_7 ( V_2 , V_4 , T_3 , V_20 ) ;
return V_25 ;
}
static int F_14 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_19 * T_3 ,
struct V_20 * V_20 )
{
int V_25 ;
V_25 = F_15 ( V_2 , V_4 , T_3 , V_20 ) ;
F_7 ( V_2 , V_4 , T_3 , V_20 ) ;
return V_25 ;
}
static int F_16 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_14 * T_2 )
{
int V_25 ;
F_1 ( V_2 , V_4 ) ;
V_25 = F_17 ( V_2 , V_4 , T_2 ) ;
return V_25 ;
}
static int F_18 ( struct V_26 * V_26 )
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
static int F_20 ( struct V_26 * V_26 , struct V_1 * V_2 ,
struct V_20 * V_20 )
{
T_5 V_30 = V_31 ;
int V_25 ;
if ( F_18 ( V_26 ) < 0 ) {
F_21 ( L_1 , V_26 -> V_28 ) ;
return - 1 ;
}
if ( V_26 -> V_32 )
V_30 = V_33 ;
V_25 = F_22 ( V_2 , V_26 , V_30 , F_7 ,
V_20 ) ;
if ( V_25 ) {
F_23 ( L_2 , V_26 -> V_28 ) ;
return - 1 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_19 * T_3 ,
struct V_21 * V_22 V_15 ,
struct V_20 * V_20 )
{
struct V_34 V_35 ;
struct V_36 * V_36 ;
T_6 V_37 ;
V_37 = V_4 -> V_9 . V_30 & V_38 ;
V_36 = F_25 ( V_20 , T_3 -> V_39 , T_3 -> V_39 ) ;
if ( V_36 == NULL ) {
F_23 ( L_3 ,
V_4 -> V_9 . type ) ;
goto V_40;
}
F_26 ( V_36 , V_20 , V_37 , V_41 ,
T_3 -> V_42 , & V_35 ) ;
if ( V_35 . V_43 != NULL ) {
if ( ! V_35 . V_43 -> V_26 -> V_44 ) {
V_35 . V_43 -> V_26 -> V_44 = 1 ;
if ( F_27 ( V_35 . V_43 , NULL ) >= 0 ) {
F_20 ( V_35 . V_43 -> V_26 , V_2 , V_20 ) ;
} else {
#ifdef F_28
F_29 ( L_4
L_5 ,
V_35 . V_43 -> V_26 -> V_28 ) ;
#endif
}
}
}
V_40:
F_7 ( V_2 , V_4 , T_3 , V_20 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
union V_3 * V_4 V_15 ,
struct V_19 * T_3 ,
struct V_21 * V_22 V_15 ,
struct V_20 * V_20 V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_45 * V_46 ;
F_31 (ent, &inject->samples, node) {
if ( T_3 -> V_47 == V_46 -> V_47 ) {
F_32 ( & V_46 -> V_48 ) ;
free ( V_46 ) ;
break;
}
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_19 * T_3 ,
struct V_21 * V_22 ,
struct V_20 * V_20 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_45 * V_46 ;
F_30 ( V_2 , V_4 , T_3 , V_22 , V_20 ) ;
V_46 = malloc ( V_4 -> V_9 . V_7 + sizeof( struct V_45 ) ) ;
if ( V_46 == NULL ) {
F_34 ( V_49 , V_50 ,
L_6 ) ;
return - 1 ;
}
V_46 -> V_47 = T_3 -> V_47 ;
memcpy ( & V_46 -> V_4 , V_4 , V_4 -> V_9 . V_7 ) ;
F_35 ( & V_46 -> V_48 , & V_6 -> V_51 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
union V_3 * V_4 V_15 ,
struct V_19 * T_3 ,
struct V_21 * V_22 ,
struct V_20 * V_20 )
{
struct V_45 * V_46 ;
union V_3 * V_52 ;
struct V_19 V_53 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
T_7 V_39 = F_37 ( V_22 , T_3 , L_7 ) ;
F_31 (ent, &inject->samples, node) {
if ( V_39 == V_46 -> V_47 )
goto V_54;
}
return 0 ;
V_54:
V_52 = & V_46 -> V_4 [ 0 ] ;
F_38 ( V_22 , V_52 , & V_53 ) ;
V_53 . V_55 = T_3 -> V_55 ;
V_53 . time = T_3 -> time ;
F_39 ( V_52 , V_22 -> V_56 . V_57 ,
V_22 -> V_56 . V_58 ,
V_22 -> V_56 . V_59 , & V_53 ,
false ) ;
F_9 ( V_2 , V_52 , & V_53 , V_22 , V_20 ) ;
return F_7 ( V_2 , V_52 , & V_53 , V_20 ) ;
}
static void F_40 ( int T_8 V_15 )
{
V_60 = 1 ;
}
static int F_41 ( struct V_21 * V_22 ,
T_9 V_57 , const char * V_61 )
{
struct V_62 * V_56 = & V_22 -> V_56 ;
const char * V_63 = F_42 ( V_22 ) ;
if ( ! ( V_56 -> V_57 & V_57 ) ) {
F_23 ( L_8 ,
V_63 , V_61 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_43 ( struct V_5 * V_6 )
{
struct V_14 * T_2 ;
int V_10 = - V_64 ;
struct V_65 V_66 = {
. V_67 = V_6 -> V_68 ,
. V_69 = V_70 ,
} ;
signal ( V_71 , F_40 ) ;
if ( V_6 -> V_72 || V_6 -> V_73 ) {
V_6 -> V_2 . V_74 = F_10 ;
V_6 -> V_2 . V_75 = F_12 ;
V_6 -> V_2 . V_76 = F_14 ;
V_6 -> V_2 . V_77 = F_16 ;
}
T_2 = F_44 ( & V_66 , true , & V_6 -> V_2 ) ;
if ( T_2 == NULL )
return - V_78 ;
if ( V_6 -> V_72 ) {
V_6 -> V_2 . T_3 = F_24 ;
} else if ( V_6 -> V_73 ) {
struct V_21 * V_22 ;
V_6 -> V_2 . V_79 = true ;
F_31 (evsel, &session->evlist->entries, node) {
const char * V_63 = F_42 ( V_22 ) ;
if ( ! strcmp ( V_63 , L_9 ) ) {
if ( F_41 ( V_22 , V_80 , L_10 ) )
return - V_64 ;
V_22 -> V_23 = F_33 ;
} else if ( ! strcmp ( V_63 , L_11 ) )
V_22 -> V_23 = F_30 ;
else if ( ! strncmp ( V_63 , L_12 , 17 ) )
V_22 -> V_23 = F_36 ;
}
}
if ( ! V_6 -> V_18 )
F_45 ( V_6 -> V_11 , T_2 -> V_9 . V_81 , V_82 ) ;
V_10 = F_46 ( T_2 , & V_6 -> V_2 ) ;
if ( ! V_6 -> V_18 ) {
T_2 -> V_9 . V_83 = V_6 -> V_13 ;
F_47 ( T_2 , T_2 -> V_84 , V_6 -> V_11 , true ) ;
}
F_48 ( T_2 ) ;
return V_10 ;
}
int F_49 ( int V_85 , const char * * V_86 , const char * T_10 V_15 )
{
struct V_5 V_6 = {
. V_2 = {
. T_3 = F_8 ,
. V_74 = F_7 ,
. V_75 = F_7 ,
. V_87 = F_7 ,
. V_76 = F_7 ,
. exit = F_7 ,
. V_88 = F_7 ,
. V_89 = F_8 ,
. V_90 = F_7 ,
. V_91 = F_7 ,
. V_56 = F_5 ,
. V_77 = F_4 ,
. V_92 = F_4 ,
. V_29 = F_4 ,
} ,
. V_68 = L_13 ,
. V_51 = F_50 ( V_6 . V_51 ) ,
} ;
const char * V_93 = L_13 ;
const struct V_94 V_95 [] = {
F_51 ( 'b' , L_14 , & V_6 . V_72 ,
L_15 ) ,
F_52 ( 'i' , L_16 , & V_6 . V_68 , L_17 ,
L_18 ) ,
F_52 ( 'o' , L_19 , & V_93 , L_17 ,
L_20 ) ,
F_51 ( 's' , L_21 , & V_6 . V_73 ,
L_22
L_23 ) ,
F_53 ( 'v' , L_24 , & V_96 ,
L_25 ) ,
F_54 ()
} ;
const char * const V_97 [] = {
L_26 ,
NULL
} ;
V_85 = F_55 ( V_85 , V_86 , V_95 , V_97 , 0 ) ;
if ( V_85 )
F_56 ( V_97 , V_95 ) ;
if ( ! strcmp ( V_93 , L_13 ) ) {
V_6 . V_18 = 1 ;
V_6 . V_11 = V_98 ;
} else {
V_6 . V_11 = F_57 ( V_93 , V_99 | V_100 | V_101 ,
V_102 | V_103 ) ;
if ( V_6 . V_11 < 0 ) {
perror ( L_27 ) ;
return - 1 ;
}
}
if ( F_58 () < 0 )
return - 1 ;
return F_43 ( & V_6 ) ;
}
