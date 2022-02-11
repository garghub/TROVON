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
static int F_13 ( struct V_32 * V_33 ,
struct V_34 * V_35 , int V_36 )
{
struct V_27 * V_37 ;
struct V_1 * V_2 ;
int V_38 ;
struct V_39 V_40 ;
V_38 = F_14 ( V_35 , L_1 ,
L_2 ,
V_36 , & V_40 ) ;
if ( V_38 )
return V_38 ;
V_37 = F_15 ( & V_41 , NULL , V_40 . V_35 ,
F_12 ) ;
F_16 ( V_40 . V_35 ) ;
if ( V_37 == NULL )
return - V_42 ;
V_2 = F_17 ( V_37 ) ;
V_33 -> V_2 = V_2 ;
V_36 = V_40 . V_43 ? V_40 . args [ 0 ] : 0 ;
if ( V_36 >= V_2 -> V_24 ) {
V_38 = - V_44 ;
goto V_45;
}
V_33 -> V_33 = & V_2 -> V_25 [ V_36 ] ;
return 0 ;
V_45:
F_18 ( V_2 ) ;
return V_38 ;
}
static struct V_32 * F_19 ( struct V_34 * V_35 , int V_36 )
{
struct V_32 * V_33 ;
int V_38 ;
if ( V_36 < 0 )
return F_20 ( - V_44 ) ;
V_33 = F_3 ( sizeof( * V_33 ) , V_11 ) ;
if ( V_33 == NULL )
return F_20 ( - V_12 ) ;
V_38 = F_13 ( V_33 , V_35 , V_36 ) ;
if ( V_38 )
goto V_46;
return V_33 ;
V_46:
F_10 ( V_33 ) ;
return F_20 ( V_38 ) ;
}
static struct V_32 * F_21 ( struct V_34 * V_35 ,
const char * V_22 )
{
struct V_32 * V_23 = NULL ;
while ( V_35 ) {
int V_36 = 0 ;
if ( V_22 )
V_36 = F_22 ( V_35 , L_3 ,
V_22 ) ;
V_23 = F_19 ( V_35 , V_36 ) ;
if ( ! F_23 ( V_23 ) || F_24 ( V_23 ) == - V_42 )
break;
else if ( V_22 && V_36 >= 0 ) {
F_25 ( L_4 ,
V_35 -> V_47 , V_22 ? V_22 : L_5 , V_36 ) ;
return NULL ;
}
V_35 = V_35 -> V_48 ;
if ( V_35 && ! F_26 ( V_35 , L_6 , NULL ) )
return NULL ;
}
return V_23 ;
}
static struct V_32 * F_27 ( struct V_27 * V_28 )
{
struct V_32 * V_49 ;
int V_5 , V_50 , V_51 = 0 ;
int V_6 ;
do {
V_6 = F_14 ( V_28 -> V_30 ,
L_1 ,
L_2 ,
V_51 , NULL ) ;
if ( V_6 < 0 )
break;
} while ( ++ V_51 );
if ( V_51 == 0 )
return NULL ;
V_49 = F_28 ( V_51 + 1 , sizeof( * V_49 ) , V_11 ) ;
if ( V_49 == NULL )
return F_20 ( - V_12 ) ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
V_6 = F_13 ( & V_49 [ V_50 ] , V_28 -> V_30 ,
V_50 ) ;
if ( V_6 )
goto V_52;
}
return V_49 ;
V_52:
for ( V_5 = 0 ; V_5 < V_50 ; V_5 ++ )
F_18 ( V_49 [ V_5 ] . V_2 ) ;
F_10 ( V_49 ) ;
return F_20 ( V_6 ) ;
}
static inline struct V_32 *
F_21 ( struct V_34 * V_35 , const char * V_22 )
{
return NULL ;
}
static inline struct V_32 * F_27 ( struct V_27 * V_28 )
{
return NULL ;
}
static struct V_32 * F_29 ( const char * V_22 ,
const char * V_53 )
{
struct V_7 * V_54 = NULL , * V_55 = NULL ;
struct V_32 * V_33 ;
int V_38 ;
if ( V_22 == NULL && V_53 == NULL )
return F_20 ( - V_17 ) ;
F_2 ( & V_9 ) ;
F_30 (c_i, &iio_map_list, l) {
if ( ( V_22 && strcmp ( V_22 , V_54 -> V_14 -> V_10 ) != 0 ) ||
( V_53 &&
strcmp ( V_53 , V_54 -> V_14 -> V_56 ) != 0 ) )
continue;
V_55 = V_54 ;
F_31 ( V_55 -> V_2 ) ;
break;
}
F_5 ( & V_9 ) ;
if ( V_55 == NULL )
return F_20 ( - V_17 ) ;
V_33 = F_3 ( sizeof( * V_33 ) , V_11 ) ;
if ( V_33 == NULL ) {
V_38 = - V_12 ;
goto V_57;
}
V_33 -> V_2 = V_55 -> V_2 ;
if ( V_55 -> V_14 -> V_58 ) {
V_33 -> V_33 =
F_11 ( V_33 -> V_2 ,
V_55 -> V_14 -> V_58 ) ;
if ( V_33 -> V_33 == NULL ) {
V_38 = - V_44 ;
goto V_59;
}
}
return V_33 ;
V_59:
F_10 ( V_33 ) ;
V_57:
F_18 ( V_55 -> V_2 ) ;
return F_20 ( V_38 ) ;
}
struct V_32 * F_32 ( struct V_27 * V_28 ,
const char * V_53 )
{
const char * V_22 = V_28 ? F_33 ( V_28 ) : NULL ;
struct V_32 * V_33 ;
if ( V_28 ) {
V_33 = F_21 ( V_28 -> V_30 ,
V_53 ) ;
if ( V_33 != NULL )
return V_33 ;
}
return F_29 ( V_22 , V_53 ) ;
}
void F_34 ( struct V_32 * V_33 )
{
F_18 ( V_33 -> V_2 ) ;
F_10 ( V_33 ) ;
}
struct V_32 * F_35 ( struct V_27 * V_28 )
{
const char * V_22 ;
struct V_32 * V_49 ;
struct V_7 * V_55 = NULL ;
int V_51 = 0 ;
int V_50 = 0 ;
int V_5 , V_6 ;
if ( V_28 == NULL )
return F_20 ( - V_44 ) ;
V_49 = F_27 ( V_28 ) ;
if ( V_49 )
return V_49 ;
V_22 = F_33 ( V_28 ) ;
F_2 ( & V_9 ) ;
F_30 (c, &iio_map_list, l)
if ( V_22 && strcmp ( V_22 , V_55 -> V_14 -> V_10 ) != 0 )
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
F_30 (c, &iio_map_list, l) {
if ( V_22 && strcmp ( V_22 , V_55 -> V_14 -> V_10 ) != 0 )
continue;
V_49 [ V_50 ] . V_2 = V_55 -> V_2 ;
V_49 [ V_50 ] . V_29 = V_55 -> V_14 -> V_60 ;
V_49 [ V_50 ] . V_33 =
F_11 ( V_49 [ V_50 ] . V_2 ,
V_55 -> V_14 -> V_58 ) ;
if ( V_49 [ V_50 ] . V_33 == NULL ) {
V_6 = - V_44 ;
goto V_52;
}
F_31 ( V_49 [ V_50 ] . V_2 ) ;
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
F_18 ( V_49 [ V_5 ] . V_2 ) ;
F_10 ( V_49 ) ;
V_13:
F_5 ( & V_9 ) ;
return F_20 ( V_6 ) ;
}
void F_36 ( struct V_32 * V_25 )
{
struct V_32 * V_23 = & V_25 [ 0 ] ;
while ( V_23 -> V_2 ) {
F_18 ( V_23 -> V_2 ) ;
V_23 ++ ;
}
F_10 ( V_25 ) ;
}
static int F_37 ( struct V_32 * V_23 , int * V_61 , int * V_62 ,
enum V_63 V_64 )
{
int V_65 ;
int V_66 [ V_67 ] ;
int V_6 ;
int V_68 = 2 ;
if ( V_62 == NULL )
V_62 = & V_65 ;
if ( V_23 -> V_2 -> V_64 -> V_69 ) {
V_6 = V_23 -> V_2 -> V_64 -> V_69 ( V_23 -> V_2 ,
V_23 -> V_33 , V_67 ,
V_66 , & V_68 , V_64 ) ;
* V_61 = V_66 [ 0 ] ;
* V_62 = V_66 [ 1 ] ;
} else
V_6 = V_23 -> V_2 -> V_64 -> V_70 ( V_23 -> V_2 ,
V_23 -> V_33 , V_61 , V_62 , V_64 ) ;
return V_6 ;
}
int F_38 ( struct V_32 * V_23 , int * V_61 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_71 ) ;
if ( V_23 -> V_2 -> V_64 == NULL ) {
V_6 = - V_17 ;
goto V_72;
}
V_6 = F_37 ( V_23 , V_61 , NULL , V_73 ) ;
V_72:
F_5 ( & V_23 -> V_2 -> V_71 ) ;
return V_6 ;
}
int F_39 ( struct V_32 * V_23 , int * V_61 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_71 ) ;
if ( V_23 -> V_2 -> V_64 == NULL ) {
V_6 = - V_17 ;
goto V_72;
}
V_6 = F_37 ( V_23 , V_61 , NULL , V_74 ) ;
V_72:
F_5 ( & V_23 -> V_2 -> V_71 ) ;
return V_6 ;
}
static int F_40 ( struct V_32 * V_23 ,
int V_75 , int * V_76 , unsigned int V_77 )
{
int V_78 , V_79 , V_80 , V_81 ;
T_1 V_82 = V_75 ;
int V_6 ;
V_6 = F_37 ( V_23 , & V_81 , NULL , V_83 ) ;
if ( V_6 >= 0 )
V_82 += V_81 ;
V_78 = F_37 ( V_23 , & V_79 , & V_80 ,
V_84 ) ;
if ( V_78 < 0 )
return V_78 ;
switch ( V_78 ) {
case V_85 :
* V_76 = V_82 * V_79 ;
break;
case V_86 :
if ( V_80 < 0 )
* V_76 = - V_82 * V_79 ;
else
* V_76 = V_82 * V_79 ;
* V_76 += F_41 ( V_82 * ( T_1 ) V_80 * V_77 ,
1000000LL ) ;
break;
case V_87 :
if ( V_80 < 0 )
* V_76 = - V_82 * V_79 ;
else
* V_76 = V_82 * V_79 ;
* V_76 += F_41 ( V_82 * ( T_1 ) V_80 * V_77 ,
1000000000LL ) ;
break;
case V_88 :
* V_76 = F_41 ( V_82 * ( T_1 ) V_79 * V_77 ,
V_80 ) ;
break;
case V_89 :
* V_76 = ( V_82 * ( T_1 ) V_79 * V_77 ) >> V_80 ;
break;
default:
return - V_44 ;
}
return 0 ;
}
int F_42 ( struct V_32 * V_23 , int V_75 ,
int * V_76 , unsigned int V_77 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_71 ) ;
if ( V_23 -> V_2 -> V_64 == NULL ) {
V_6 = - V_17 ;
goto V_72;
}
V_6 = F_40 ( V_23 , V_75 , V_76 ,
V_77 ) ;
V_72:
F_5 ( & V_23 -> V_2 -> V_71 ) ;
return V_6 ;
}
int F_43 ( struct V_32 * V_23 , int * V_61 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_71 ) ;
if ( V_23 -> V_2 -> V_64 == NULL ) {
V_6 = - V_17 ;
goto V_72;
}
if ( F_44 ( V_23 -> V_33 , V_90 ) ) {
V_6 = F_37 ( V_23 , V_61 , NULL ,
V_90 ) ;
} else {
V_6 = F_37 ( V_23 , V_61 , NULL , V_73 ) ;
if ( V_6 < 0 )
goto V_72;
V_6 = F_40 ( V_23 , * V_61 , V_61 , 1 ) ;
}
V_72:
F_5 ( & V_23 -> V_2 -> V_71 ) ;
return V_6 ;
}
int F_45 ( struct V_32 * V_23 , int * V_61 , int * V_62 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_71 ) ;
if ( V_23 -> V_2 -> V_64 == NULL ) {
V_6 = - V_17 ;
goto V_72;
}
V_6 = F_37 ( V_23 , V_61 , V_62 , V_84 ) ;
V_72:
F_5 ( & V_23 -> V_2 -> V_71 ) ;
return V_6 ;
}
int F_46 ( struct V_32 * V_23 , enum V_91 * type )
{
int V_6 = 0 ;
F_2 ( & V_23 -> V_2 -> V_71 ) ;
if ( V_23 -> V_2 -> V_64 == NULL ) {
V_6 = - V_17 ;
goto V_72;
}
* type = V_23 -> V_33 -> type ;
V_72:
F_5 ( & V_23 -> V_2 -> V_71 ) ;
return V_6 ;
}
