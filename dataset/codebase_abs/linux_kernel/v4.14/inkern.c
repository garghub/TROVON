int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = 0 , V_6 = 0 ;
struct V_7 * V_8 ;
if ( V_4 == NULL )
return 0 ;
F_2 ( & V_9 ) ;
while ( V_4 [ V_5 ] . V_10 != NULL ) {
V_8 = F_3 ( sizeof( * V_8 ) , V_11 ) ;
if ( V_8 == NULL ) {
V_6 = - V_12 ;
goto V_13;
}
V_8 -> V_14 = & V_4 [ V_5 ] ;
V_8 -> V_2 = V_2 ;
F_4 ( & V_8 -> V_15 , & V_16 ) ;
V_5 ++ ;
}
V_13:
F_5 ( & V_9 ) ;
return V_6 ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_6 = - V_17 ;
struct V_7 * V_8 , * V_18 ;
F_2 ( & V_9 ) ;
F_7 (mapi, next, &iio_map_list, l) {
if ( V_2 == V_8 -> V_2 ) {
F_8 ( & V_8 -> V_15 ) ;
F_9 ( V_8 ) ;
V_6 = 0 ;
}
}
F_5 ( & V_9 ) ;
return V_6 ;
}
static const struct V_19
* F_10 ( const struct V_1 * V_2 , const char * V_20 )
{
int V_5 ;
const struct V_19 * V_21 = NULL ;
for ( V_5 = 0 ; V_5 < V_2 -> V_22 ; V_5 ++ )
if ( V_2 -> V_23 [ V_5 ] . V_24 &&
strcmp ( V_20 , V_2 -> V_23 [ V_5 ] . V_24 ) == 0 ) {
V_21 = & V_2 -> V_23 [ V_5 ] ;
break;
}
return V_21 ;
}
static int F_11 ( struct V_25 * V_26 , void * V_27 )
{
return V_26 -> V_28 == V_27 && V_26 -> type == & V_29 ;
}
static int F_12 ( struct V_1 * V_2 ,
const struct V_30 * V_31 )
{
if ( ! V_31 -> V_32 )
return 0 ;
if ( V_31 -> args [ 0 ] >= V_2 -> V_22 ) {
F_13 ( & V_2 -> V_26 , L_1 ,
V_31 -> args [ 0 ] ) ;
return - V_33 ;
}
return V_31 -> args [ 0 ] ;
}
static int F_14 ( struct V_34 * V_35 ,
struct V_36 * V_37 , int V_38 )
{
struct V_25 * V_39 ;
struct V_1 * V_2 ;
int V_40 ;
struct V_30 V_31 ;
V_40 = F_15 ( V_37 , L_2 ,
L_3 ,
V_38 , & V_31 ) ;
if ( V_40 )
return V_40 ;
V_39 = F_16 ( & V_41 , NULL , V_31 . V_37 ,
F_11 ) ;
F_17 ( V_31 . V_37 ) ;
if ( V_39 == NULL )
return - V_42 ;
V_2 = F_18 ( V_39 ) ;
V_35 -> V_2 = V_2 ;
if ( V_2 -> V_43 -> V_44 )
V_38 = V_2 -> V_43 -> V_44 ( V_2 , & V_31 ) ;
else
V_38 = F_12 ( V_2 , & V_31 ) ;
if ( V_38 < 0 )
goto V_45;
V_35 -> V_35 = & V_2 -> V_23 [ V_38 ] ;
return 0 ;
V_45:
F_19 ( V_2 ) ;
return V_38 ;
}
static struct V_34 * F_20 ( struct V_36 * V_37 , int V_38 )
{
struct V_34 * V_35 ;
int V_40 ;
if ( V_38 < 0 )
return F_21 ( - V_33 ) ;
V_35 = F_3 ( sizeof( * V_35 ) , V_11 ) ;
if ( V_35 == NULL )
return F_21 ( - V_12 ) ;
V_40 = F_14 ( V_35 , V_37 , V_38 ) ;
if ( V_40 )
goto V_46;
return V_35 ;
V_46:
F_9 ( V_35 ) ;
return F_21 ( V_40 ) ;
}
static struct V_34 * F_22 ( struct V_36 * V_37 ,
const char * V_20 )
{
struct V_34 * V_21 = NULL ;
while ( V_37 ) {
int V_38 = 0 ;
if ( V_20 )
V_38 = F_23 ( V_37 , L_4 ,
V_20 ) ;
V_21 = F_20 ( V_37 , V_38 ) ;
if ( ! F_24 ( V_21 ) || F_25 ( V_21 ) == - V_42 )
break;
else if ( V_20 && V_38 >= 0 ) {
F_26 ( L_5 ,
V_37 , V_20 ? V_20 : L_6 , V_38 ) ;
return NULL ;
}
V_37 = V_37 -> V_47 ;
if ( V_37 && ! F_27 ( V_37 , L_7 , NULL ) )
return NULL ;
}
return V_21 ;
}
static struct V_34 * F_28 ( struct V_25 * V_26 )
{
struct V_34 * V_48 ;
int V_5 , V_49 , V_50 = 0 ;
int V_6 ;
do {
V_6 = F_15 ( V_26 -> V_28 ,
L_2 ,
L_3 ,
V_50 , NULL ) ;
if ( V_6 < 0 )
break;
} while ( ++ V_50 );
if ( V_50 == 0 )
return NULL ;
V_48 = F_29 ( V_50 + 1 , sizeof( * V_48 ) , V_11 ) ;
if ( V_48 == NULL )
return F_21 ( - V_12 ) ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
V_6 = F_14 ( & V_48 [ V_49 ] , V_26 -> V_28 ,
V_49 ) ;
if ( V_6 )
goto V_51;
}
return V_48 ;
V_51:
for ( V_5 = 0 ; V_5 < V_49 ; V_5 ++ )
F_19 ( V_48 [ V_5 ] . V_2 ) ;
F_9 ( V_48 ) ;
return F_21 ( V_6 ) ;
}
static inline struct V_34 *
F_22 ( struct V_36 * V_37 , const char * V_20 )
{
return NULL ;
}
static inline struct V_34 * F_28 ( struct V_25 * V_26 )
{
return NULL ;
}
static struct V_34 * F_30 ( const char * V_20 ,
const char * V_52 )
{
struct V_7 * V_53 = NULL , * V_54 = NULL ;
struct V_34 * V_35 ;
int V_40 ;
if ( V_20 == NULL && V_52 == NULL )
return F_21 ( - V_17 ) ;
F_2 ( & V_9 ) ;
F_31 (c_i, &iio_map_list, l) {
if ( ( V_20 && strcmp ( V_20 , V_53 -> V_14 -> V_10 ) != 0 ) ||
( V_52 &&
strcmp ( V_52 , V_53 -> V_14 -> V_55 ) != 0 ) )
continue;
V_54 = V_53 ;
F_32 ( V_54 -> V_2 ) ;
break;
}
F_5 ( & V_9 ) ;
if ( V_54 == NULL )
return F_21 ( - V_17 ) ;
V_35 = F_3 ( sizeof( * V_35 ) , V_11 ) ;
if ( V_35 == NULL ) {
V_40 = - V_12 ;
goto V_56;
}
V_35 -> V_2 = V_54 -> V_2 ;
if ( V_54 -> V_14 -> V_57 ) {
V_35 -> V_35 =
F_10 ( V_35 -> V_2 ,
V_54 -> V_14 -> V_57 ) ;
if ( V_35 -> V_35 == NULL ) {
V_40 = - V_33 ;
goto V_58;
}
}
return V_35 ;
V_58:
F_9 ( V_35 ) ;
V_56:
F_19 ( V_54 -> V_2 ) ;
return F_21 ( V_40 ) ;
}
struct V_34 * F_33 ( struct V_25 * V_26 ,
const char * V_52 )
{
const char * V_20 = V_26 ? F_34 ( V_26 ) : NULL ;
struct V_34 * V_35 ;
if ( V_26 ) {
V_35 = F_22 ( V_26 -> V_28 ,
V_52 ) ;
if ( V_35 != NULL )
return V_35 ;
}
return F_30 ( V_20 , V_52 ) ;
}
void F_35 ( struct V_34 * V_35 )
{
if ( ! V_35 )
return;
F_19 ( V_35 -> V_2 ) ;
F_9 ( V_35 ) ;
}
static void F_36 ( struct V_25 * V_26 , void * V_59 )
{
struct V_34 * V_35 = * (struct V_34 * * ) V_59 ;
F_35 ( V_35 ) ;
}
static int F_37 ( struct V_25 * V_26 , void * V_59 , void * V_27 )
{
struct V_34 * * V_60 = V_59 ;
if ( ! V_60 || ! * V_60 ) {
F_38 ( ! V_60 || ! * V_60 ) ;
return 0 ;
}
return * V_60 == V_27 ;
}
struct V_34 * F_39 ( struct V_25 * V_26 ,
const char * V_52 )
{
struct V_34 * * V_61 , * V_35 ;
V_61 = F_40 ( F_36 , sizeof( * V_61 ) , V_11 ) ;
if ( ! V_61 )
return F_21 ( - V_12 ) ;
V_35 = F_33 ( V_26 , V_52 ) ;
if ( F_24 ( V_35 ) ) {
F_41 ( V_61 ) ;
return V_35 ;
}
* V_61 = V_35 ;
F_42 ( V_26 , V_61 ) ;
return V_35 ;
}
void F_43 ( struct V_25 * V_26 , struct V_34 * V_35 )
{
F_38 ( F_44 ( V_26 , F_36 ,
F_37 , V_35 ) ) ;
}
struct V_34 * F_45 ( struct V_25 * V_26 )
{
const char * V_20 ;
struct V_34 * V_48 ;
struct V_7 * V_54 = NULL ;
int V_50 = 0 ;
int V_49 = 0 ;
int V_5 , V_6 ;
if ( V_26 == NULL )
return F_21 ( - V_33 ) ;
V_48 = F_28 ( V_26 ) ;
if ( V_48 )
return V_48 ;
V_20 = F_34 ( V_26 ) ;
F_2 ( & V_9 ) ;
F_31 (c, &iio_map_list, l)
if ( V_20 && strcmp ( V_20 , V_54 -> V_14 -> V_10 ) != 0 )
continue;
else
V_50 ++ ;
if ( V_50 == 0 ) {
V_6 = - V_17 ;
goto V_13;
}
V_48 = F_3 ( sizeof( * V_48 ) * ( V_50 + 1 ) , V_11 ) ;
if ( V_48 == NULL ) {
V_6 = - V_12 ;
goto V_13;
}
F_31 (c, &iio_map_list, l) {
if ( V_20 && strcmp ( V_20 , V_54 -> V_14 -> V_10 ) != 0 )
continue;
V_48 [ V_49 ] . V_2 = V_54 -> V_2 ;
V_48 [ V_49 ] . V_27 = V_54 -> V_14 -> V_62 ;
V_48 [ V_49 ] . V_35 =
F_10 ( V_48 [ V_49 ] . V_2 ,
V_54 -> V_14 -> V_57 ) ;
if ( V_48 [ V_49 ] . V_35 == NULL ) {
V_6 = - V_33 ;
goto V_51;
}
F_32 ( V_48 [ V_49 ] . V_2 ) ;
V_49 ++ ;
}
if ( V_49 == 0 ) {
V_6 = - V_17 ;
goto V_51;
}
F_5 ( & V_9 ) ;
return V_48 ;
V_51:
for ( V_5 = 0 ; V_5 < V_50 ; V_5 ++ )
F_19 ( V_48 [ V_5 ] . V_2 ) ;
F_9 ( V_48 ) ;
V_13:
F_5 ( & V_9 ) ;
return F_21 ( V_6 ) ;
}
void F_46 ( struct V_34 * V_23 )
{
struct V_34 * V_21 = & V_23 [ 0 ] ;
while ( V_21 -> V_2 ) {
F_19 ( V_21 -> V_2 ) ;
V_21 ++ ;
}
F_9 ( V_23 ) ;
}
static void F_47 ( struct V_25 * V_26 , void * V_59 )
{
struct V_34 * V_23 = * (struct V_34 * * ) V_59 ;
F_46 ( V_23 ) ;
}
struct V_34 * F_48 ( struct V_25 * V_26 )
{
struct V_34 * * V_61 , * V_23 ;
V_61 = F_40 ( F_47 , sizeof( * V_61 ) , V_11 ) ;
if ( ! V_61 )
return F_21 ( - V_12 ) ;
V_23 = F_45 ( V_26 ) ;
if ( F_24 ( V_23 ) ) {
F_41 ( V_61 ) ;
return V_23 ;
}
* V_61 = V_23 ;
F_42 ( V_26 , V_61 ) ;
return V_23 ;
}
void F_49 ( struct V_25 * V_26 ,
struct V_34 * V_23 )
{
F_38 ( F_44 ( V_26 , F_47 ,
F_37 , V_23 ) ) ;
}
static int F_50 ( struct V_34 * V_21 , int * V_63 , int * V_64 ,
enum V_65 V_43 )
{
int V_66 ;
int V_67 [ V_68 ] ;
int V_6 ;
int V_69 = 2 ;
if ( V_64 == NULL )
V_64 = & V_66 ;
if ( ! F_51 ( V_21 -> V_35 , V_43 ) )
return - V_33 ;
if ( V_21 -> V_2 -> V_43 -> V_70 ) {
V_6 = V_21 -> V_2 -> V_43 -> V_70 ( V_21 -> V_2 ,
V_21 -> V_35 , V_68 ,
V_67 , & V_69 , V_43 ) ;
* V_63 = V_67 [ 0 ] ;
* V_64 = V_67 [ 1 ] ;
} else
V_6 = V_21 -> V_2 -> V_43 -> V_71 ( V_21 -> V_2 ,
V_21 -> V_35 , V_63 , V_64 , V_43 ) ;
return V_6 ;
}
int F_52 ( struct V_34 * V_21 , int * V_63 )
{
int V_6 ;
F_2 ( & V_21 -> V_2 -> V_72 ) ;
if ( V_21 -> V_2 -> V_43 == NULL ) {
V_6 = - V_17 ;
goto V_73;
}
V_6 = F_50 ( V_21 , V_63 , NULL , V_74 ) ;
V_73:
F_5 ( & V_21 -> V_2 -> V_72 ) ;
return V_6 ;
}
int F_53 ( struct V_34 * V_21 , int * V_63 )
{
int V_6 ;
F_2 ( & V_21 -> V_2 -> V_72 ) ;
if ( V_21 -> V_2 -> V_43 == NULL ) {
V_6 = - V_17 ;
goto V_73;
}
V_6 = F_50 ( V_21 , V_63 , NULL , V_75 ) ;
V_73:
F_5 ( & V_21 -> V_2 -> V_72 ) ;
return V_6 ;
}
static int F_54 ( struct V_34 * V_21 ,
int V_76 , int * V_77 , unsigned int V_78 )
{
int V_79 , V_80 , V_81 , V_82 ;
T_1 V_83 = V_76 ;
int V_6 ;
V_6 = F_50 ( V_21 , & V_82 , NULL , V_84 ) ;
if ( V_6 >= 0 )
V_83 += V_82 ;
V_79 = F_50 ( V_21 , & V_80 , & V_81 ,
V_85 ) ;
if ( V_79 < 0 ) {
* V_77 = V_76 ;
return 0 ;
}
switch ( V_79 ) {
case V_86 :
* V_77 = V_83 * V_80 ;
break;
case V_87 :
if ( V_81 < 0 )
* V_77 = - V_83 * V_80 ;
else
* V_77 = V_83 * V_80 ;
* V_77 += F_55 ( V_83 * ( T_1 ) V_81 * V_78 ,
1000000LL ) ;
break;
case V_88 :
if ( V_81 < 0 )
* V_77 = - V_83 * V_80 ;
else
* V_77 = V_83 * V_80 ;
* V_77 += F_55 ( V_83 * ( T_1 ) V_81 * V_78 ,
1000000000LL ) ;
break;
case V_89 :
* V_77 = F_55 ( V_83 * ( T_1 ) V_80 * V_78 ,
V_81 ) ;
break;
case V_90 :
* V_77 = ( V_83 * ( T_1 ) V_80 * V_78 ) >> V_81 ;
break;
default:
return - V_33 ;
}
return 0 ;
}
int F_56 ( struct V_34 * V_21 , int V_76 ,
int * V_77 , unsigned int V_78 )
{
int V_6 ;
F_2 ( & V_21 -> V_2 -> V_72 ) ;
if ( V_21 -> V_2 -> V_43 == NULL ) {
V_6 = - V_17 ;
goto V_73;
}
V_6 = F_54 ( V_21 , V_76 , V_77 ,
V_78 ) ;
V_73:
F_5 ( & V_21 -> V_2 -> V_72 ) ;
return V_6 ;
}
static int F_57 ( struct V_34 * V_21 ,
int * V_63 , int * V_64 ,
enum V_65 V_91 )
{
int V_6 ;
F_2 ( & V_21 -> V_2 -> V_72 ) ;
if ( V_21 -> V_2 -> V_43 == NULL ) {
V_6 = - V_17 ;
goto V_73;
}
V_6 = F_50 ( V_21 , V_63 , V_64 , V_91 ) ;
V_73:
F_5 ( & V_21 -> V_2 -> V_72 ) ;
return V_6 ;
}
int F_58 ( struct V_34 * V_21 , int * V_63 , int * V_64 )
{
return F_57 ( V_21 , V_63 , V_64 , V_84 ) ;
}
int F_59 ( struct V_34 * V_21 , int * V_63 )
{
int V_6 ;
F_2 ( & V_21 -> V_2 -> V_72 ) ;
if ( V_21 -> V_2 -> V_43 == NULL ) {
V_6 = - V_17 ;
goto V_73;
}
if ( F_51 ( V_21 -> V_35 , V_92 ) ) {
V_6 = F_50 ( V_21 , V_63 , NULL ,
V_92 ) ;
} else {
V_6 = F_50 ( V_21 , V_63 , NULL , V_74 ) ;
if ( V_6 < 0 )
goto V_73;
V_6 = F_54 ( V_21 , * V_63 , V_63 , 1 ) ;
}
V_73:
F_5 ( & V_21 -> V_2 -> V_72 ) ;
return V_6 ;
}
int F_60 ( struct V_34 * V_21 , int * V_63 , int * V_64 )
{
return F_57 ( V_21 , V_63 , V_64 , V_85 ) ;
}
static int F_61 ( struct V_34 * V_21 ,
const int * * V_67 , int * type , int * V_93 ,
enum V_65 V_43 )
{
if ( ! F_62 ( V_21 -> V_35 , V_43 ) )
return - V_33 ;
return V_21 -> V_2 -> V_43 -> V_94 ( V_21 -> V_2 , V_21 -> V_35 ,
V_67 , type , V_93 , V_43 ) ;
}
int F_63 ( struct V_34 * V_21 ,
const int * * V_67 , int * V_93 )
{
int V_6 ;
int type ;
F_2 ( & V_21 -> V_2 -> V_72 ) ;
if ( ! V_21 -> V_2 -> V_43 ) {
V_6 = - V_17 ;
goto V_73;
}
V_6 = F_61 ( V_21 ,
V_67 , & type , V_93 , V_74 ) ;
V_73:
F_5 ( & V_21 -> V_2 -> V_72 ) ;
if ( V_6 >= 0 && type != V_86 )
V_6 = - V_33 ;
return V_6 ;
}
static int F_64 ( struct V_34 * V_21 ,
int * V_63 , int * V_64 , int * type ,
enum V_65 V_43 )
{
int V_66 ;
const int * V_67 ;
int V_93 ;
int V_6 ;
if ( ! V_64 )
V_64 = & V_66 ;
V_6 = F_61 ( V_21 , & V_67 , type , & V_93 , V_43 ) ;
switch ( V_6 ) {
case V_95 :
switch ( * type ) {
case V_86 :
* V_63 = V_67 [ 2 ] ;
break;
default:
* V_63 = V_67 [ 4 ] ;
* V_64 = V_67 [ 5 ] ;
}
return 0 ;
case V_96 :
if ( V_93 <= 0 )
return - V_33 ;
switch ( * type ) {
case V_86 :
* V_63 = V_67 [ -- V_93 ] ;
while ( V_93 ) {
if ( V_67 [ -- V_93 ] > * V_63 )
* V_63 = V_67 [ V_93 ] ;
}
break;
default:
return - V_33 ;
}
return 0 ;
default:
return V_6 ;
}
}
int F_65 ( struct V_34 * V_21 , int * V_63 )
{
int V_6 ;
int type ;
F_2 ( & V_21 -> V_2 -> V_72 ) ;
if ( ! V_21 -> V_2 -> V_43 ) {
V_6 = - V_17 ;
goto V_73;
}
V_6 = F_64 ( V_21 , V_63 , NULL , & type , V_74 ) ;
V_73:
F_5 ( & V_21 -> V_2 -> V_72 ) ;
return V_6 ;
}
int F_66 ( struct V_34 * V_21 , enum V_97 * type )
{
int V_6 = 0 ;
F_2 ( & V_21 -> V_2 -> V_72 ) ;
if ( V_21 -> V_2 -> V_43 == NULL ) {
V_6 = - V_17 ;
goto V_73;
}
* type = V_21 -> V_35 -> type ;
V_73:
F_5 ( & V_21 -> V_2 -> V_72 ) ;
return V_6 ;
}
static int F_67 ( struct V_34 * V_21 , int V_63 , int V_64 ,
enum V_65 V_43 )
{
return V_21 -> V_2 -> V_43 -> V_98 ( V_21 -> V_2 ,
V_21 -> V_35 , V_63 , V_64 , V_43 ) ;
}
int F_68 ( struct V_34 * V_21 , int V_63 )
{
int V_6 ;
F_2 ( & V_21 -> V_2 -> V_72 ) ;
if ( V_21 -> V_2 -> V_43 == NULL ) {
V_6 = - V_17 ;
goto V_73;
}
V_6 = F_67 ( V_21 , V_63 , 0 , V_74 ) ;
V_73:
F_5 ( & V_21 -> V_2 -> V_72 ) ;
return V_6 ;
}
unsigned int F_69 ( struct V_34 * V_21 )
{
const struct V_99 * V_100 ;
unsigned int V_5 = 0 ;
if ( ! V_21 -> V_35 -> V_100 )
return V_5 ;
for ( V_100 = V_21 -> V_35 -> V_100 ; V_100 -> V_20 ; V_100 ++ )
++ V_5 ;
return V_5 ;
}
static const struct V_99 * F_70 (
const struct V_34 * V_21 ,
const char * V_101 )
{
const struct V_99 * V_100 ;
if ( ! V_21 -> V_35 -> V_100 )
return NULL ;
for ( V_100 = V_21 -> V_35 -> V_100 ; V_100 -> V_20 ; ++ V_100 ) {
if ( ! strcmp ( V_101 , V_100 -> V_20 ) )
return V_100 ;
}
return NULL ;
}
T_2 F_71 ( struct V_34 * V_21 ,
const char * V_101 , char * V_102 )
{
const struct V_99 * V_100 ;
V_100 = F_70 ( V_21 , V_101 ) ;
if ( ! V_100 )
return - V_33 ;
return V_100 -> V_103 ( V_21 -> V_2 , V_100 -> V_104 ,
V_21 -> V_35 , V_102 ) ;
}
T_2 F_72 ( struct V_34 * V_21 , const char * V_101 ,
const char * V_102 , T_3 V_105 )
{
const struct V_99 * V_100 ;
V_100 = F_70 ( V_21 , V_101 ) ;
if ( ! V_100 )
return - V_33 ;
return V_100 -> V_106 ( V_21 -> V_2 , V_100 -> V_104 ,
V_21 -> V_35 , V_102 , V_105 ) ;
}
