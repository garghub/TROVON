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
int V_10 ;
V_10 = F_6 ( V_2 , V_4 , V_17 ) ;
if ( V_10 )
return V_10 ;
return F_1 ( V_2 , V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_3 V_15 ,
struct V_19 * V_19 V_15 )
{
return F_1 ( V_2 , V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_3 ,
struct V_20 * V_21 ,
struct V_19 * V_19 )
{
if ( V_21 -> V_22 . V_23 ) {
T_4 V_24 = V_21 -> V_22 . V_23 ;
return V_24 ( V_2 , V_4 , T_3 , V_21 , V_19 ) ;
}
F_9 ( V_2 , V_4 , T_3 , V_21 , V_19 ) ;
return F_1 ( V_2 , V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_3 ,
struct V_19 * V_19 )
{
int V_25 ;
V_25 = F_11 ( V_2 , V_4 , T_3 , V_19 ) ;
F_7 ( V_2 , V_4 , T_3 , V_19 ) ;
return V_25 ;
}
static int F_12 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_3 ,
struct V_19 * V_19 )
{
int V_25 ;
V_25 = F_13 ( V_2 , V_4 , T_3 , V_19 ) ;
F_7 ( V_2 , V_4 , T_3 , V_19 ) ;
return V_25 ;
}
static int F_14 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_3 ,
struct V_19 * V_19 )
{
int V_25 ;
V_25 = F_15 ( V_2 , V_4 , T_3 , V_19 ) ;
F_7 ( V_2 , V_4 , T_3 , V_19 ) ;
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
static int F_18 ( struct V_26 * V_27 )
{
if ( V_27 -> V_28 )
return 0 ;
if ( F_19 ( V_27 -> V_29 , V_27 -> V_30 ,
sizeof( V_27 -> V_30 ) ) > 0 ) {
V_27 -> V_28 = true ;
return 0 ;
}
return - 1 ;
}
static int F_20 ( struct V_26 * V_27 , struct V_1 * V_2 ,
struct V_19 * V_19 )
{
T_5 V_31 = V_32 ;
int V_25 ;
if ( F_18 ( V_27 ) < 0 ) {
F_21 ( L_1 , V_27 -> V_29 ) ;
return - 1 ;
}
if ( V_27 -> V_33 )
V_31 = V_34 ;
V_25 = F_22 ( V_2 , V_27 , V_31 , F_7 ,
V_19 ) ;
if ( V_25 ) {
F_23 ( L_2 , V_27 -> V_29 ) ;
return - 1 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_3 ,
struct V_20 * V_21 V_15 ,
struct V_19 * V_19 )
{
struct V_35 V_36 ;
struct V_37 * V_37 ;
T_6 V_38 ;
V_38 = V_4 -> V_9 . V_31 & V_39 ;
V_37 = F_25 ( V_19 , T_3 -> V_40 , T_3 -> V_40 ) ;
if ( V_37 == NULL ) {
F_23 ( L_3 ,
V_4 -> V_9 . type ) ;
goto V_41;
}
F_26 ( V_37 , V_19 , V_38 , V_42 ,
T_3 -> V_43 , & V_36 ) ;
if ( V_36 . V_44 != NULL ) {
if ( ! V_36 . V_44 -> V_26 -> V_45 ) {
V_36 . V_44 -> V_26 -> V_45 = 1 ;
if ( F_27 ( V_36 . V_44 , NULL ) >= 0 ) {
F_20 ( V_36 . V_44 -> V_26 , V_2 , V_19 ) ;
} else {
#ifdef F_28
F_29 ( L_4
L_5 ,
V_36 . V_44 -> V_26 -> V_29 ) ;
#endif
}
}
}
V_41:
F_7 ( V_2 , V_4 , T_3 , V_19 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
union V_3 * V_4 V_15 ,
struct V_18 * T_3 ,
struct V_20 * V_21 V_15 ,
struct V_19 * V_19 V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_46 * V_47 ;
F_31 (ent, &inject->samples, node) {
if ( T_3 -> V_48 == V_47 -> V_48 ) {
F_32 ( & V_47 -> V_49 ) ;
free ( V_47 ) ;
break;
}
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_3 ,
struct V_20 * V_21 ,
struct V_19 * V_19 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_46 * V_47 ;
F_30 ( V_2 , V_4 , T_3 , V_21 , V_19 ) ;
V_47 = malloc ( V_4 -> V_9 . V_7 + sizeof( struct V_46 ) ) ;
if ( V_47 == NULL ) {
F_34 ( V_50 , V_51 ,
L_6 ) ;
return - 1 ;
}
V_47 -> V_48 = T_3 -> V_48 ;
memcpy ( & V_47 -> V_4 , V_4 , V_4 -> V_9 . V_7 ) ;
F_35 ( & V_47 -> V_49 , & V_6 -> V_52 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
union V_3 * V_4 V_15 ,
struct V_18 * T_3 ,
struct V_20 * V_21 ,
struct V_19 * V_19 )
{
struct V_46 * V_47 ;
union V_3 * V_53 ;
struct V_18 V_54 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
T_7 V_40 = F_37 ( V_21 , T_3 , L_7 ) ;
F_31 (ent, &inject->samples, node) {
if ( V_40 == V_47 -> V_48 )
goto V_55;
}
return 0 ;
V_55:
V_53 = & V_47 -> V_4 [ 0 ] ;
F_38 ( V_21 , V_53 , & V_54 ) ;
V_54 . V_56 = T_3 -> V_56 ;
V_54 . time = T_3 -> time ;
F_39 ( V_53 , V_21 -> V_57 . V_58 ,
V_21 -> V_57 . V_59 ,
V_21 -> V_57 . V_60 , & V_54 ,
false ) ;
F_9 ( V_2 , V_53 , & V_54 , V_21 , V_19 ) ;
return F_7 ( V_2 , V_53 , & V_54 , V_19 ) ;
}
static void F_40 ( int T_8 V_15 )
{
V_61 = 1 ;
}
static int F_41 ( struct V_20 * V_21 ,
T_9 V_58 , const char * V_62 )
{
struct V_63 * V_57 = & V_21 -> V_57 ;
const char * V_64 = F_42 ( V_21 ) ;
if ( ! ( V_57 -> V_58 & V_58 ) ) {
F_23 ( L_8 ,
V_64 , V_62 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_43 ( struct V_5 * V_6 )
{
struct V_14 * T_2 ;
int V_10 = - V_65 ;
signal ( V_66 , F_40 ) ;
if ( V_6 -> V_67 || V_6 -> V_68 ) {
V_6 -> V_2 . V_69 = F_10 ;
V_6 -> V_2 . V_70 = F_12 ;
V_6 -> V_2 . V_71 = F_14 ;
V_6 -> V_2 . V_72 = F_16 ;
}
T_2 = F_44 ( V_6 -> V_73 , V_74 , false , true , & V_6 -> V_2 ) ;
if ( T_2 == NULL )
return - V_75 ;
if ( V_6 -> V_67 ) {
V_6 -> V_2 . T_3 = F_24 ;
} else if ( V_6 -> V_68 ) {
struct V_20 * V_21 ;
V_6 -> V_2 . V_76 = true ;
F_31 (evsel, &session->evlist->entries, node) {
const char * V_64 = F_42 ( V_21 ) ;
if ( ! strcmp ( V_64 , L_9 ) ) {
if ( F_41 ( V_21 , V_77 , L_10 ) )
return - V_65 ;
V_21 -> V_22 . V_23 = F_33 ;
} else if ( ! strcmp ( V_64 , L_11 ) )
V_21 -> V_22 . V_23 = F_30 ;
else if ( ! strncmp ( V_64 , L_12 , 17 ) )
V_21 -> V_22 . V_23 = F_36 ;
}
}
if ( ! V_6 -> V_78 )
F_45 ( V_6 -> V_11 , T_2 -> V_9 . V_79 , V_80 ) ;
V_10 = F_46 ( T_2 , & V_6 -> V_2 ) ;
if ( ! V_6 -> V_78 ) {
T_2 -> V_9 . V_81 = V_6 -> V_13 ;
F_47 ( T_2 , T_2 -> V_82 , V_6 -> V_11 , true ) ;
}
F_48 ( T_2 ) ;
return V_10 ;
}
int F_49 ( int V_83 , const char * * V_84 , const char * T_10 V_15 )
{
struct V_5 V_6 = {
. V_2 = {
. T_3 = F_8 ,
. V_69 = F_7 ,
. V_70 = F_7 ,
. V_85 = F_7 ,
. V_71 = F_7 ,
. exit = F_7 ,
. V_86 = F_7 ,
. V_87 = F_8 ,
. V_88 = F_7 ,
. V_89 = F_7 ,
. V_57 = F_5 ,
. V_72 = F_4 ,
. V_90 = F_4 ,
. V_30 = F_4 ,
} ,
. V_73 = L_13 ,
. V_52 = F_50 ( V_6 . V_52 ) ,
} ;
const char * V_91 = L_13 ;
const struct V_92 V_93 [] = {
F_51 ( 'b' , L_14 , & V_6 . V_67 ,
L_15 ) ,
F_52 ( 'i' , L_16 , & V_6 . V_73 , L_17 ,
L_18 ) ,
F_52 ( 'o' , L_19 , & V_91 , L_17 ,
L_20 ) ,
F_51 ( 's' , L_21 , & V_6 . V_68 ,
L_22
L_23 ) ,
F_53 ( 'v' , L_24 , & V_94 ,
L_25 ) ,
F_54 ()
} ;
const char * const V_95 [] = {
L_26 ,
NULL
} ;
V_83 = F_55 ( V_83 , V_84 , V_93 , V_95 , 0 ) ;
if ( V_83 )
F_56 ( V_95 , V_93 ) ;
if ( ! strcmp ( V_91 , L_13 ) ) {
V_6 . V_78 = 1 ;
V_6 . V_11 = V_96 ;
} else {
V_6 . V_11 = F_57 ( V_91 , V_97 | V_98 | V_99 ,
V_100 | V_101 ) ;
if ( V_6 . V_11 < 0 ) {
perror ( L_27 ) ;
return - 1 ;
}
}
if ( F_58 () < 0 )
return - 1 ;
return F_43 ( & V_6 ) ;
}
