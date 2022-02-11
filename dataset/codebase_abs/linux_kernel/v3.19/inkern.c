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
struct V_7 * V_8 ;
struct V_18 * V_19 , * V_20 ;
F_2 ( & V_9 ) ;
F_7 (pos, tmp, &iio_map_list) {
V_8 = F_8 ( V_19 , struct V_7 , V_15 ) ;
if ( V_2 == V_8 -> V_2 ) {
F_9 ( & V_8 -> V_15 ) ;
F_10 ( V_8 ) ;
V_6 = 0 ;
}
}
F_5 ( & V_9 ) ;
return V_6 ;
}
static const struct V_21
* F_11 ( const struct V_1 * V_2 , const char * V_22 )
{
int V_5 ;
const struct V_21 * V_23 = NULL ;
for ( V_5 = 0 ; V_5 < V_2 -> V_24 ; V_5 ++ )
if ( V_2 -> V_25 [ V_5 ] . V_26 &&
strcmp ( V_22 , V_2 -> V_25 [ V_5 ] . V_26 ) == 0 ) {
V_23 = & V_2 -> V_25 [ V_5 ] ;
break;
}
return V_23 ;
}
static int F_12 ( struct V_27 * V_28 , void * V_29 )
{
return V_28 -> V_30 == V_29 && V_28 -> type == & V_31 ;
}
static int F_13 ( struct V_1 * V_2 ,
const struct V_32 * V_33 )
{
if ( ! V_33 -> V_34 )
return 0 ;
if ( V_33 -> args [ 0 ] >= V_2 -> V_24 )
return - V_35 ;
return V_33 -> args [ 0 ] ;
}
static int F_14 ( struct V_36 * V_37 ,
struct V_38 * V_39 , int V_40 )
{
struct V_27 * V_41 ;
struct V_1 * V_2 ;
int V_42 ;
struct V_32 V_33 ;
V_42 = F_15 ( V_39 , L_1 ,
L_2 ,
V_40 , & V_33 ) ;
if ( V_42 )
return V_42 ;
V_41 = F_16 ( & V_43 , NULL , V_33 . V_39 ,
F_12 ) ;
F_17 ( V_33 . V_39 ) ;
if ( V_41 == NULL )
return - V_44 ;
V_2 = F_18 ( V_41 ) ;
V_37 -> V_2 = V_2 ;
if ( V_2 -> V_45 -> V_46 )
V_40 = V_2 -> V_45 -> V_46 ( V_2 , & V_33 ) ;
else
V_40 = F_13 ( V_2 , & V_33 ) ;
if ( V_40 < 0 )
goto V_47;
V_37 -> V_37 = & V_2 -> V_25 [ V_40 ] ;
return 0 ;
V_47:
F_19 ( V_2 ) ;
return V_40 ;
}
static struct V_36 * F_20 ( struct V_38 * V_39 , int V_40 )
{
struct V_36 * V_37 ;
int V_42 ;
if ( V_40 < 0 )
return F_21 ( - V_35 ) ;
V_37 = F_3 ( sizeof( * V_37 ) , V_11 ) ;
if ( V_37 == NULL )
return F_21 ( - V_12 ) ;
V_42 = F_14 ( V_37 , V_39 , V_40 ) ;
if ( V_42 )
goto V_48;
return V_37 ;
V_48:
F_10 ( V_37 ) ;
return F_21 ( V_42 ) ;
}
static struct V_36 * F_22 ( struct V_38 * V_39 ,
const char * V_22 )
{
struct V_36 * V_23 = NULL ;
while ( V_39 ) {
int V_40 = 0 ;
if ( V_22 )
V_40 = F_23 ( V_39 , L_3 ,
V_22 ) ;
V_23 = F_20 ( V_39 , V_40 ) ;
if ( ! F_24 ( V_23 ) || F_25 ( V_23 ) == - V_44 )
break;
else if ( V_22 && V_40 >= 0 ) {
F_26 ( L_4 ,
V_39 -> V_49 , V_22 ? V_22 : L_5 , V_40 ) ;
return NULL ;
}
V_39 = V_39 -> V_50 ;
if ( V_39 && ! F_27 ( V_39 , L_6 , NULL ) )
return NULL ;
}
return V_23 ;
}
static struct V_36 * F_28 ( struct V_27 * V_28 )
{
struct V_36 * V_51 ;
int V_5 , V_52 , V_53 = 0 ;
int V_6 ;
do {
V_6 = F_15 ( V_28 -> V_30 ,
L_1 ,
L_2 ,
V_53 , NULL ) ;
if ( V_6 < 0 )
break;
} while ( ++ V_53 );
if ( V_53 == 0 )
return NULL ;
V_51 = F_29 ( V_53 + 1 , sizeof( * V_51 ) , V_11 ) ;
if ( V_51 == NULL )
return F_21 ( - V_12 ) ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ ) {
V_6 = F_14 ( & V_51 [ V_52 ] , V_28 -> V_30 ,
V_52 ) ;
if ( V_6 )
goto V_54;
}
return V_51 ;
V_54:
for ( V_5 = 0 ; V_5 < V_52 ; V_5 ++ )
F_19 ( V_51 [ V_5 ] . V_2 ) ;
F_10 ( V_51 ) ;
return F_21 ( V_6 ) ;
}
static inline struct V_36 *
F_22 ( struct V_38 * V_39 , const char * V_22 )
{
return NULL ;
}
static inline struct V_36 * F_28 ( struct V_27 * V_28 )
{
return NULL ;
}
static struct V_36 * F_30 ( const char * V_22 ,
const char * V_55 )
{
struct V_7 * V_56 = NULL , * V_57 = NULL ;
struct V_36 * V_37 ;
int V_42 ;
if ( V_22 == NULL && V_55 == NULL )
return F_21 ( - V_17 ) ;
F_2 ( & V_9 ) ;
F_31 (c_i, &iio_map_list, l) {
if ( ( V_22 && strcmp ( V_22 , V_56 -> V_14 -> V_10 ) != 0 ) ||
( V_55 &&
strcmp ( V_55 , V_56 -> V_14 -> V_58 ) != 0 ) )
continue;
V_57 = V_56 ;
F_32 ( V_57 -> V_2 ) ;
break;
}
F_5 ( & V_9 ) ;
if ( V_57 == NULL )
return F_21 ( - V_17 ) ;
V_37 = F_3 ( sizeof( * V_37 ) , V_11 ) ;
if ( V_37 == NULL ) {
V_42 = - V_12 ;
goto V_59;
}
V_37 -> V_2 = V_57 -> V_2 ;
if ( V_57 -> V_14 -> V_60 ) {
V_37 -> V_37 =
F_11 ( V_37 -> V_2 ,
V_57 -> V_14 -> V_60 ) ;
if ( V_37 -> V_37 == NULL ) {
V_42 = - V_35 ;
goto V_61;
}
}
return V_37 ;
V_61:
F_10 ( V_37 ) ;
V_59:
F_19 ( V_57 -> V_2 ) ;
return F_21 ( V_42 ) ;
}
struct V_36 * F_33 ( struct V_27 * V_28 ,
const char * V_55 )
{
const char * V_22 = V_28 ? F_34 ( V_28 ) : NULL ;
struct V_36 * V_37 ;
if ( V_28 ) {
V_37 = F_22 ( V_28 -> V_30 ,
V_55 ) ;
if ( V_37 != NULL )
return V_37 ;
}
return F_30 ( V_22 , V_55 ) ;
}
void F_35 ( struct V_36 * V_37 )
{
F_19 ( V_37 -> V_2 ) ;
F_10 ( V_37 ) ;
}
struct V_36 * F_36 ( struct V_27 * V_28 )
{
const char * V_22 ;
struct V_36 * V_51 ;
struct V_7 * V_57 = NULL ;
int V_53 = 0 ;
int V_52 = 0 ;
int V_5 , V_6 ;
if ( V_28 == NULL )
return F_21 ( - V_35 ) ;
V_51 = F_28 ( V_28 ) ;
if ( V_51 )
return V_51 ;
V_22 = F_34 ( V_28 ) ;
F_2 ( & V_9 ) ;
F_31 (c, &iio_map_list, l)
if ( V_22 && strcmp ( V_22 , V_57 -> V_14 -> V_10 ) != 0 )
continue;
else
V_53 ++ ;
if ( V_53 == 0 ) {
V_6 = - V_17 ;
goto V_13;
}
V_51 = F_3 ( sizeof( * V_51 ) * ( V_53 + 1 ) , V_11 ) ;
if ( V_51 == NULL ) {
V_6 = - V_12 ;
goto V_13;
}
F_31 (c, &iio_map_list, l) {
if ( V_22 && strcmp ( V_22 , V_57 -> V_14 -> V_10 ) != 0 )
continue;
V_51 [ V_52 ] . V_2 = V_57 -> V_2 ;
V_51 [ V_52 ] . V_29 = V_57 -> V_14 -> V_62 ;
V_51 [ V_52 ] . V_37 =
F_11 ( V_51 [ V_52 ] . V_2 ,
V_57 -> V_14 -> V_60 ) ;
if ( V_51 [ V_52 ] . V_37 == NULL ) {
V_6 = - V_35 ;
goto V_54;
}
F_32 ( V_51 [ V_52 ] . V_2 ) ;
V_52 ++ ;
}
if ( V_52 == 0 ) {
V_6 = - V_17 ;
goto V_54;
}
F_5 ( & V_9 ) ;
return V_51 ;
V_54:
for ( V_5 = 0 ; V_5 < V_53 ; V_5 ++ )
F_19 ( V_51 [ V_5 ] . V_2 ) ;
F_10 ( V_51 ) ;
V_13:
F_5 ( & V_9 ) ;
return F_21 ( V_6 ) ;
}
void F_37 ( struct V_36 * V_25 )
{
struct V_36 * V_23 = & V_25 [ 0 ] ;
while ( V_23 -> V_2 ) {
F_19 ( V_23 -> V_2 ) ;
V_23 ++ ;
}
F_10 ( V_25 ) ;
}
static int F_38 ( struct V_36 * V_23 , int * V_63 , int * V_64 ,
enum V_65 V_45 )
{
int V_66 ;
int V_67 [ V_68 ] ;
int V_6 ;
int V_69 = 2 ;
if ( V_64 == NULL )
V_64 = & V_66 ;
if( ! F_39 ( V_23 -> V_37 , V_45 ) )
return - V_35 ;
if ( V_23 -> V_2 -> V_45 -> V_70 ) {
V_6 = V_23 -> V_2 -> V_45 -> V_70 ( V_23 -> V_2 ,
V_23 -> V_37 , V_68 ,
V_67 , & V_69 , V_45 ) ;
* V_63 = V_67 [ 0 ] ;
* V_64 = V_67 [ 1 ] ;
} else
V_6 = V_23 -> V_2 -> V_45 -> V_71 ( V_23 -> V_2 ,
V_23 -> V_37 , V_63 , V_64 , V_45 ) ;
return V_6 ;
}
int F_40 ( struct V_36 * V_23 , int * V_63 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_72 ) ;
if ( V_23 -> V_2 -> V_45 == NULL ) {
V_6 = - V_17 ;
goto V_73;
}
V_6 = F_38 ( V_23 , V_63 , NULL , V_74 ) ;
V_73:
F_5 ( & V_23 -> V_2 -> V_72 ) ;
return V_6 ;
}
int F_41 ( struct V_36 * V_23 , int * V_63 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_72 ) ;
if ( V_23 -> V_2 -> V_45 == NULL ) {
V_6 = - V_17 ;
goto V_73;
}
V_6 = F_38 ( V_23 , V_63 , NULL , V_75 ) ;
V_73:
F_5 ( & V_23 -> V_2 -> V_72 ) ;
return V_6 ;
}
static int F_42 ( struct V_36 * V_23 ,
int V_76 , int * V_77 , unsigned int V_78 )
{
int V_79 , V_80 , V_81 , V_82 ;
T_1 V_83 = V_76 ;
int V_6 ;
V_6 = F_38 ( V_23 , & V_82 , NULL , V_84 ) ;
if ( V_6 >= 0 )
V_83 += V_82 ;
V_79 = F_38 ( V_23 , & V_80 , & V_81 ,
V_85 ) ;
if ( V_79 < 0 )
return V_79 ;
switch ( V_79 ) {
case V_86 :
* V_77 = V_83 * V_80 ;
break;
case V_87 :
if ( V_81 < 0 )
* V_77 = - V_83 * V_80 ;
else
* V_77 = V_83 * V_80 ;
* V_77 += F_43 ( V_83 * ( T_1 ) V_81 * V_78 ,
1000000LL ) ;
break;
case V_88 :
if ( V_81 < 0 )
* V_77 = - V_83 * V_80 ;
else
* V_77 = V_83 * V_80 ;
* V_77 += F_43 ( V_83 * ( T_1 ) V_81 * V_78 ,
1000000000LL ) ;
break;
case V_89 :
* V_77 = F_43 ( V_83 * ( T_1 ) V_80 * V_78 ,
V_81 ) ;
break;
case V_90 :
* V_77 = ( V_83 * ( T_1 ) V_80 * V_78 ) >> V_81 ;
break;
default:
return - V_35 ;
}
return 0 ;
}
int F_44 ( struct V_36 * V_23 , int V_76 ,
int * V_77 , unsigned int V_78 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_72 ) ;
if ( V_23 -> V_2 -> V_45 == NULL ) {
V_6 = - V_17 ;
goto V_73;
}
V_6 = F_42 ( V_23 , V_76 , V_77 ,
V_78 ) ;
V_73:
F_5 ( & V_23 -> V_2 -> V_72 ) ;
return V_6 ;
}
int F_45 ( struct V_36 * V_23 , int * V_63 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_72 ) ;
if ( V_23 -> V_2 -> V_45 == NULL ) {
V_6 = - V_17 ;
goto V_73;
}
if ( F_39 ( V_23 -> V_37 , V_91 ) ) {
V_6 = F_38 ( V_23 , V_63 , NULL ,
V_91 ) ;
} else {
V_6 = F_38 ( V_23 , V_63 , NULL , V_74 ) ;
if ( V_6 < 0 )
goto V_73;
V_6 = F_42 ( V_23 , * V_63 , V_63 , 1 ) ;
}
V_73:
F_5 ( & V_23 -> V_2 -> V_72 ) ;
return V_6 ;
}
int F_46 ( struct V_36 * V_23 , int * V_63 , int * V_64 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_72 ) ;
if ( V_23 -> V_2 -> V_45 == NULL ) {
V_6 = - V_17 ;
goto V_73;
}
V_6 = F_38 ( V_23 , V_63 , V_64 , V_85 ) ;
V_73:
F_5 ( & V_23 -> V_2 -> V_72 ) ;
return V_6 ;
}
int F_47 ( struct V_36 * V_23 , enum V_92 * type )
{
int V_6 = 0 ;
F_2 ( & V_23 -> V_2 -> V_72 ) ;
if ( V_23 -> V_2 -> V_45 == NULL ) {
V_6 = - V_17 ;
goto V_73;
}
* type = V_23 -> V_37 -> type ;
V_73:
F_5 ( & V_23 -> V_2 -> V_72 ) ;
return V_6 ;
}
