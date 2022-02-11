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
struct V_12 * T_2
V_13 )
{
return F_1 ( V_2 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_14 * * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
int V_16 ;
V_16 = F_6 ( V_2 , V_4 , V_15 ) ;
if ( V_16 )
return V_16 ;
if ( ! V_6 -> V_8 . V_17 )
return 0 ;
return F_1 ( V_2 , V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_3 V_13 ,
struct V_19 * V_19 V_13 )
{
return F_1 ( V_2 , V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_3 ,
struct V_20 * V_21 ,
struct V_19 * V_19 )
{
if ( V_21 -> V_22 ) {
T_4 V_23 = V_21 -> V_22 ;
return V_23 ( V_2 , V_4 , T_3 , V_21 , V_19 ) ;
}
F_9 ( V_2 , V_4 , T_3 , V_21 , V_19 ) ;
return F_1 ( V_2 , V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_3 ,
struct V_19 * V_19 )
{
int V_24 ;
V_24 = F_11 ( V_2 , V_4 , T_3 , V_19 ) ;
F_7 ( V_2 , V_4 , T_3 , V_19 ) ;
return V_24 ;
}
static int F_12 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_3 ,
struct V_19 * V_19 )
{
int V_24 ;
V_24 = F_13 ( V_2 , V_4 , T_3 , V_19 ) ;
F_7 ( V_2 , V_4 , T_3 , V_19 ) ;
return V_24 ;
}
static int F_14 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_3 ,
struct V_19 * V_19 )
{
int V_24 ;
V_24 = F_15 ( V_2 , V_4 , T_3 , V_19 ) ;
F_7 ( V_2 , V_4 , T_3 , V_19 ) ;
return V_24 ;
}
static int F_16 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_12 * T_2 )
{
int V_24 ;
F_1 ( V_2 , V_4 ) ;
V_24 = F_17 ( V_2 , V_4 , T_2 ) ;
return V_24 ;
}
static int F_18 ( struct V_25 * V_25 )
{
if ( V_25 -> V_26 )
return 0 ;
if ( F_19 ( V_25 -> V_27 , V_25 -> V_28 ,
sizeof( V_25 -> V_28 ) ) > 0 ) {
V_25 -> V_26 = true ;
return 0 ;
}
return - 1 ;
}
static int F_20 ( struct V_25 * V_25 , struct V_1 * V_2 ,
struct V_19 * V_19 )
{
T_5 V_29 = V_30 ;
int V_24 ;
if ( F_18 ( V_25 ) < 0 ) {
F_21 ( L_1 , V_25 -> V_27 ) ;
return - 1 ;
}
if ( V_25 -> V_31 )
V_29 = V_32 ;
V_24 = F_22 ( V_2 , V_25 , V_29 , F_7 ,
V_19 ) ;
if ( V_24 ) {
F_23 ( L_2 , V_25 -> V_27 ) ;
return - 1 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
union V_3 * V_4 ,
struct V_18 * T_3 ,
struct V_20 * V_21 V_13 ,
struct V_19 * V_19 )
{
struct V_33 V_34 ;
struct V_35 * V_35 ;
T_6 V_36 ;
V_36 = V_4 -> V_9 . V_29 & V_37 ;
V_35 = F_25 ( V_19 , T_3 -> V_38 , T_3 -> V_39 ) ;
if ( V_35 == NULL ) {
F_23 ( L_3 ,
V_4 -> V_9 . type ) ;
goto V_40;
}
F_26 ( V_35 , V_36 , V_41 , T_3 -> V_42 , & V_34 ) ;
if ( V_34 . V_43 != NULL ) {
if ( ! V_34 . V_43 -> V_25 -> V_44 ) {
V_34 . V_43 -> V_25 -> V_44 = 1 ;
if ( F_27 ( V_34 . V_43 , NULL ) >= 0 ) {
F_20 ( V_34 . V_43 -> V_25 , V_2 , V_19 ) ;
} else {
#ifdef F_28
F_29 ( L_4
L_5 ,
V_34 . V_43 -> V_25 -> V_27 ) ;
#endif
}
}
}
V_40:
F_7 ( V_2 , V_4 , T_3 , V_19 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
union V_3 * V_4 V_13 ,
struct V_18 * T_3 ,
struct V_20 * V_21 V_13 ,
struct V_19 * V_19 V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_45 * V_46 ;
F_31 (ent, &inject->samples, node) {
if ( T_3 -> V_39 == V_46 -> V_39 ) {
F_32 ( & V_46 -> V_47 ) ;
free ( V_46 ) ;
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
struct V_45 * V_46 ;
F_30 ( V_2 , V_4 , T_3 , V_21 , V_19 ) ;
V_46 = malloc ( V_4 -> V_9 . V_7 + sizeof( struct V_45 ) ) ;
if ( V_46 == NULL ) {
F_34 ( V_48 , V_49 ,
L_6 ) ;
return - 1 ;
}
V_46 -> V_39 = T_3 -> V_39 ;
memcpy ( & V_46 -> V_4 , V_4 , V_4 -> V_9 . V_7 ) ;
F_35 ( & V_46 -> V_47 , & V_6 -> V_50 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
union V_3 * V_4 V_13 ,
struct V_18 * T_3 ,
struct V_20 * V_21 ,
struct V_19 * V_19 )
{
struct V_45 * V_46 ;
union V_3 * V_51 ;
struct V_18 V_52 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
T_7 V_38 = F_37 ( V_21 , T_3 , L_7 ) ;
F_31 (ent, &inject->samples, node) {
if ( V_38 == V_46 -> V_39 )
goto V_53;
}
return 0 ;
V_53:
V_51 = & V_46 -> V_4 [ 0 ] ;
F_38 ( V_21 , V_51 , & V_52 ) ;
V_52 . V_54 = T_3 -> V_54 ;
V_52 . time = T_3 -> time ;
F_39 ( V_51 , V_21 -> V_55 . V_56 ,
V_21 -> V_55 . V_57 , & V_52 ,
false ) ;
F_9 ( V_2 , V_51 , & V_52 , V_21 , V_19 ) ;
return F_7 ( V_2 , V_51 , & V_52 , V_19 ) ;
}
static void F_40 ( int T_8 V_13 )
{
V_58 = 1 ;
}
static int F_41 ( struct V_20 * V_21 ,
T_9 V_56 , const char * V_59 )
{
struct V_60 * V_55 = & V_21 -> V_55 ;
const char * V_61 = F_42 ( V_21 ) ;
if ( ! ( V_55 -> V_56 & V_56 ) ) {
F_23 ( L_8 ,
V_61 , V_59 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_43 ( struct V_5 * V_6 )
{
int V_16 = - V_62 ;
struct V_12 * T_2 = V_6 -> T_2 ;
struct V_63 * V_64 = & V_6 -> V_8 ;
signal ( V_65 , F_40 ) ;
if ( V_6 -> V_66 || V_6 -> V_67 ) {
V_6 -> V_2 . V_68 = F_10 ;
V_6 -> V_2 . V_69 = F_12 ;
V_6 -> V_2 . V_70 = F_14 ;
V_6 -> V_2 . V_71 = F_16 ;
}
if ( V_6 -> V_66 ) {
V_6 -> V_2 . T_3 = F_24 ;
} else if ( V_6 -> V_67 ) {
struct V_20 * V_21 ;
V_6 -> V_2 . V_72 = true ;
F_44 (session->evlist, evsel) {
const char * V_61 = F_42 ( V_21 ) ;
if ( ! strcmp ( V_61 , L_9 ) ) {
if ( F_41 ( V_21 , V_73 , L_10 ) )
return - V_62 ;
V_21 -> V_22 = F_33 ;
} else if ( ! strcmp ( V_61 , L_11 ) )
V_21 -> V_22 = F_30 ;
else if ( ! strncmp ( V_61 , L_12 , 17 ) )
V_21 -> V_22 = F_36 ;
}
}
if ( ! V_64 -> V_17 )
F_45 ( V_64 -> V_74 , T_2 -> V_9 . V_75 , V_76 ) ;
V_16 = F_46 ( T_2 , & V_6 -> V_2 ) ;
if ( ! V_64 -> V_17 ) {
if ( V_6 -> V_66 )
F_47 ( & T_2 -> V_9 ,
V_77 ) ;
T_2 -> V_9 . V_78 = V_6 -> V_11 ;
F_48 ( T_2 , T_2 -> V_79 , V_64 -> V_74 , true ) ;
}
return V_16 ;
}
int F_49 ( int V_80 , const char * * V_81 , const char * T_10 V_13 )
{
struct V_5 V_6 = {
. V_2 = {
. T_3 = F_8 ,
. V_68 = F_7 ,
. V_69 = F_7 ,
. V_82 = F_7 ,
. V_70 = F_7 ,
. exit = F_7 ,
. V_83 = F_7 ,
. V_84 = F_8 ,
. V_85 = F_7 ,
. V_86 = F_7 ,
. V_55 = F_5 ,
. V_71 = F_4 ,
. V_87 = F_4 ,
. V_28 = F_4 ,
. V_88 = F_4 ,
} ,
. V_89 = L_13 ,
. V_50 = F_50 ( V_6 . V_50 ) ,
. V_8 = {
. V_90 = L_13 ,
. V_91 = V_92 ,
} ,
} ;
struct V_63 V_93 = {
. V_91 = V_94 ,
} ;
int V_16 ;
const struct V_95 V_96 [] = {
F_51 ( 'b' , L_14 , & V_6 . V_66 ,
L_15 ) ,
F_52 ( 'i' , L_16 , & V_6 . V_89 , L_17 ,
L_18 ) ,
F_52 ( 'o' , L_19 , & V_6 . V_8 . V_90 , L_17 ,
L_20 ) ,
F_51 ( 's' , L_21 , & V_6 . V_67 ,
L_22
L_23 ) ,
F_53 ( 'v' , L_24 , & V_97 ,
L_25 ) ,
F_52 ( 0 , L_26 , & V_98 . V_99 , L_17 ,
L_27 ) ,
F_54 ()
} ;
const char * const V_100 [] = {
L_28 ,
NULL
} ;
V_80 = F_55 ( V_80 , V_81 , V_96 , V_100 , 0 ) ;
if ( V_80 )
F_56 ( V_100 , V_96 ) ;
if ( F_57 ( & V_6 . V_8 ) ) {
perror ( L_29 ) ;
return - 1 ;
}
V_93 . V_90 = V_6 . V_89 ;
V_6 . T_2 = F_58 ( & V_93 , true , & V_6 . V_2 ) ;
if ( V_6 . T_2 == NULL )
return - 1 ;
if ( F_59 ( & V_6 . T_2 -> V_9 . V_101 ) < 0 )
return - 1 ;
V_16 = F_43 ( & V_6 ) ;
F_60 ( V_6 . T_2 ) ;
return V_16 ;
}
