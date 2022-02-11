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
V_37 -> V_47 , V_20 ? V_20 : L_6 , V_38 ) ;
return NULL ;
}
V_37 = V_37 -> V_48 ;
if ( V_37 && ! F_27 ( V_37 , L_7 , NULL ) )
return NULL ;
}
return V_21 ;
}
static struct V_34 * F_28 ( struct V_25 * V_26 )
{
struct V_34 * V_49 ;
int V_5 , V_50 , V_51 = 0 ;
int V_6 ;
do {
V_6 = F_15 ( V_26 -> V_28 ,
L_2 ,
L_3 ,
V_51 , NULL ) ;
if ( V_6 < 0 )
break;
} while ( ++ V_51 );
if ( V_51 == 0 )
return NULL ;
V_49 = F_29 ( V_51 + 1 , sizeof( * V_49 ) , V_11 ) ;
if ( V_49 == NULL )
return F_21 ( - V_12 ) ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
V_6 = F_14 ( & V_49 [ V_50 ] , V_26 -> V_28 ,
V_50 ) ;
if ( V_6 )
goto V_52;
}
return V_49 ;
V_52:
for ( V_5 = 0 ; V_5 < V_50 ; V_5 ++ )
F_19 ( V_49 [ V_5 ] . V_2 ) ;
F_9 ( V_49 ) ;
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
const char * V_53 )
{
struct V_7 * V_54 = NULL , * V_55 = NULL ;
struct V_34 * V_35 ;
int V_40 ;
if ( V_20 == NULL && V_53 == NULL )
return F_21 ( - V_17 ) ;
F_2 ( & V_9 ) ;
F_31 (c_i, &iio_map_list, l) {
if ( ( V_20 && strcmp ( V_20 , V_54 -> V_14 -> V_10 ) != 0 ) ||
( V_53 &&
strcmp ( V_53 , V_54 -> V_14 -> V_56 ) != 0 ) )
continue;
V_55 = V_54 ;
F_32 ( V_55 -> V_2 ) ;
break;
}
F_5 ( & V_9 ) ;
if ( V_55 == NULL )
return F_21 ( - V_17 ) ;
V_35 = F_3 ( sizeof( * V_35 ) , V_11 ) ;
if ( V_35 == NULL ) {
V_40 = - V_12 ;
goto V_57;
}
V_35 -> V_2 = V_55 -> V_2 ;
if ( V_55 -> V_14 -> V_58 ) {
V_35 -> V_35 =
F_10 ( V_35 -> V_2 ,
V_55 -> V_14 -> V_58 ) ;
if ( V_35 -> V_35 == NULL ) {
V_40 = - V_33 ;
goto V_59;
}
}
return V_35 ;
V_59:
F_9 ( V_35 ) ;
V_57:
F_19 ( V_55 -> V_2 ) ;
return F_21 ( V_40 ) ;
}
struct V_34 * F_33 ( struct V_25 * V_26 ,
const char * V_53 )
{
const char * V_20 = V_26 ? F_34 ( V_26 ) : NULL ;
struct V_34 * V_35 ;
if ( V_26 ) {
V_35 = F_22 ( V_26 -> V_28 ,
V_53 ) ;
if ( V_35 != NULL )
return V_35 ;
}
return F_30 ( V_20 , V_53 ) ;
}
void F_35 ( struct V_34 * V_35 )
{
if ( ! V_35 )
return;
F_19 ( V_35 -> V_2 ) ;
F_9 ( V_35 ) ;
}
struct V_34 * F_36 ( struct V_25 * V_26 )
{
const char * V_20 ;
struct V_34 * V_49 ;
struct V_7 * V_55 = NULL ;
int V_51 = 0 ;
int V_50 = 0 ;
int V_5 , V_6 ;
if ( V_26 == NULL )
return F_21 ( - V_33 ) ;
V_49 = F_28 ( V_26 ) ;
if ( V_49 )
return V_49 ;
V_20 = F_34 ( V_26 ) ;
F_2 ( & V_9 ) ;
F_31 (c, &iio_map_list, l)
if ( V_20 && strcmp ( V_20 , V_55 -> V_14 -> V_10 ) != 0 )
continue;
else
V_51 ++ ;
if ( V_51 == 0 ) {
V_6 = - V_17 ;
goto V_13;
}
V_49 = F_3 ( sizeof( * V_49 ) * ( V_51 + 1 ) , V_11 ) ;
if ( V_49 == NULL ) {
V_6 = - V_12 ;
goto V_13;
}
F_31 (c, &iio_map_list, l) {
if ( V_20 && strcmp ( V_20 , V_55 -> V_14 -> V_10 ) != 0 )
continue;
V_49 [ V_50 ] . V_2 = V_55 -> V_2 ;
V_49 [ V_50 ] . V_27 = V_55 -> V_14 -> V_60 ;
V_49 [ V_50 ] . V_35 =
F_10 ( V_49 [ V_50 ] . V_2 ,
V_55 -> V_14 -> V_58 ) ;
if ( V_49 [ V_50 ] . V_35 == NULL ) {
V_6 = - V_33 ;
goto V_52;
}
F_32 ( V_49 [ V_50 ] . V_2 ) ;
V_50 ++ ;
}
if ( V_50 == 0 ) {
V_6 = - V_17 ;
goto V_52;
}
F_5 ( & V_9 ) ;
return V_49 ;
V_52:
for ( V_5 = 0 ; V_5 < V_51 ; V_5 ++ )
F_19 ( V_49 [ V_5 ] . V_2 ) ;
F_9 ( V_49 ) ;
V_13:
F_5 ( & V_9 ) ;
return F_21 ( V_6 ) ;
}
void F_37 ( struct V_34 * V_23 )
{
struct V_34 * V_21 = & V_23 [ 0 ] ;
while ( V_21 -> V_2 ) {
F_19 ( V_21 -> V_2 ) ;
V_21 ++ ;
}
F_9 ( V_23 ) ;
}
static int F_38 ( struct V_34 * V_21 , int * V_61 , int * V_62 ,
enum V_63 V_43 )
{
int V_64 ;
int V_65 [ V_66 ] ;
int V_6 ;
int V_67 = 2 ;
if ( V_62 == NULL )
V_62 = & V_64 ;
if( ! F_39 ( V_21 -> V_35 , V_43 ) )
return - V_33 ;
if ( V_21 -> V_2 -> V_43 -> V_68 ) {
V_6 = V_21 -> V_2 -> V_43 -> V_68 ( V_21 -> V_2 ,
V_21 -> V_35 , V_66 ,
V_65 , & V_67 , V_43 ) ;
* V_61 = V_65 [ 0 ] ;
* V_62 = V_65 [ 1 ] ;
} else
V_6 = V_21 -> V_2 -> V_43 -> V_69 ( V_21 -> V_2 ,
V_21 -> V_35 , V_61 , V_62 , V_43 ) ;
return V_6 ;
}
int F_40 ( struct V_34 * V_21 , int * V_61 )
{
int V_6 ;
F_2 ( & V_21 -> V_2 -> V_70 ) ;
if ( V_21 -> V_2 -> V_43 == NULL ) {
V_6 = - V_17 ;
goto V_71;
}
V_6 = F_38 ( V_21 , V_61 , NULL , V_72 ) ;
V_71:
F_5 ( & V_21 -> V_2 -> V_70 ) ;
return V_6 ;
}
int F_41 ( struct V_34 * V_21 , int * V_61 )
{
int V_6 ;
F_2 ( & V_21 -> V_2 -> V_70 ) ;
if ( V_21 -> V_2 -> V_43 == NULL ) {
V_6 = - V_17 ;
goto V_71;
}
V_6 = F_38 ( V_21 , V_61 , NULL , V_73 ) ;
V_71:
F_5 ( & V_21 -> V_2 -> V_70 ) ;
return V_6 ;
}
static int F_42 ( struct V_34 * V_21 ,
int V_74 , int * V_75 , unsigned int V_76 )
{
int V_77 , V_78 , V_79 , V_80 ;
T_1 V_81 = V_74 ;
int V_6 ;
V_6 = F_38 ( V_21 , & V_80 , NULL , V_82 ) ;
if ( V_6 >= 0 )
V_81 += V_80 ;
V_77 = F_38 ( V_21 , & V_78 , & V_79 ,
V_83 ) ;
if ( V_77 < 0 )
return V_77 ;
switch ( V_77 ) {
case V_84 :
* V_75 = V_81 * V_78 ;
break;
case V_85 :
if ( V_79 < 0 )
* V_75 = - V_81 * V_78 ;
else
* V_75 = V_81 * V_78 ;
* V_75 += F_43 ( V_81 * ( T_1 ) V_79 * V_76 ,
1000000LL ) ;
break;
case V_86 :
if ( V_79 < 0 )
* V_75 = - V_81 * V_78 ;
else
* V_75 = V_81 * V_78 ;
* V_75 += F_43 ( V_81 * ( T_1 ) V_79 * V_76 ,
1000000000LL ) ;
break;
case V_87 :
* V_75 = F_43 ( V_81 * ( T_1 ) V_78 * V_76 ,
V_79 ) ;
break;
case V_88 :
* V_75 = ( V_81 * ( T_1 ) V_78 * V_76 ) >> V_79 ;
break;
default:
return - V_33 ;
}
return 0 ;
}
int F_44 ( struct V_34 * V_21 , int V_74 ,
int * V_75 , unsigned int V_76 )
{
int V_6 ;
F_2 ( & V_21 -> V_2 -> V_70 ) ;
if ( V_21 -> V_2 -> V_43 == NULL ) {
V_6 = - V_17 ;
goto V_71;
}
V_6 = F_42 ( V_21 , V_74 , V_75 ,
V_76 ) ;
V_71:
F_5 ( & V_21 -> V_2 -> V_70 ) ;
return V_6 ;
}
int F_45 ( struct V_34 * V_21 , int * V_61 )
{
int V_6 ;
F_2 ( & V_21 -> V_2 -> V_70 ) ;
if ( V_21 -> V_2 -> V_43 == NULL ) {
V_6 = - V_17 ;
goto V_71;
}
if ( F_39 ( V_21 -> V_35 , V_89 ) ) {
V_6 = F_38 ( V_21 , V_61 , NULL ,
V_89 ) ;
} else {
V_6 = F_38 ( V_21 , V_61 , NULL , V_72 ) ;
if ( V_6 < 0 )
goto V_71;
V_6 = F_42 ( V_21 , * V_61 , V_61 , 1 ) ;
}
V_71:
F_5 ( & V_21 -> V_2 -> V_70 ) ;
return V_6 ;
}
int F_46 ( struct V_34 * V_21 , int * V_61 , int * V_62 )
{
int V_6 ;
F_2 ( & V_21 -> V_2 -> V_70 ) ;
if ( V_21 -> V_2 -> V_43 == NULL ) {
V_6 = - V_17 ;
goto V_71;
}
V_6 = F_38 ( V_21 , V_61 , V_62 , V_83 ) ;
V_71:
F_5 ( & V_21 -> V_2 -> V_70 ) ;
return V_6 ;
}
int F_47 ( struct V_34 * V_21 , enum V_90 * type )
{
int V_6 = 0 ;
F_2 ( & V_21 -> V_2 -> V_70 ) ;
if ( V_21 -> V_2 -> V_43 == NULL ) {
V_6 = - V_17 ;
goto V_71;
}
* type = V_21 -> V_35 -> type ;
V_71:
F_5 ( & V_21 -> V_2 -> V_70 ) ;
return V_6 ;
}
static int F_48 ( struct V_34 * V_21 , int V_61 , int V_62 ,
enum V_63 V_43 )
{
return V_21 -> V_2 -> V_43 -> V_91 ( V_21 -> V_2 ,
V_21 -> V_35 , V_61 , V_62 , V_43 ) ;
}
int F_49 ( struct V_34 * V_21 , int V_61 )
{
int V_6 ;
F_2 ( & V_21 -> V_2 -> V_70 ) ;
if ( V_21 -> V_2 -> V_43 == NULL ) {
V_6 = - V_17 ;
goto V_71;
}
V_6 = F_48 ( V_21 , V_61 , 0 , V_72 ) ;
V_71:
F_5 ( & V_21 -> V_2 -> V_70 ) ;
return V_6 ;
}
