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
if ( ! F_23 ( V_23 ) )
break;
else if ( V_22 && V_36 >= 0 ) {
F_24 ( L_4 ,
V_35 -> V_47 , V_22 ? V_22 : L_5 , V_36 ) ;
return V_23 ;
}
V_35 = V_35 -> V_48 ;
if ( V_35 && ! F_25 ( V_35 , L_6 , NULL ) )
break;
}
return V_23 ;
}
static struct V_32 * F_26 ( struct V_27 * V_28 )
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
V_49 = F_27 ( V_51 + 1 , sizeof( * V_49 ) , V_11 ) ;
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
static inline struct V_32 * F_26 ( struct V_27 * V_28 )
{
return NULL ;
}
static struct V_32 * F_28 ( const char * V_22 ,
const char * V_53 )
{
struct V_7 * V_54 = NULL , * V_55 = NULL ;
struct V_32 * V_33 ;
int V_38 ;
if ( V_22 == NULL && V_53 == NULL )
return F_20 ( - V_17 ) ;
F_2 ( & V_9 ) ;
F_29 (c_i, &iio_map_list, l) {
if ( ( V_22 && strcmp ( V_22 , V_54 -> V_14 -> V_10 ) != 0 ) ||
( V_53 &&
strcmp ( V_53 , V_54 -> V_14 -> V_56 ) != 0 ) )
continue;
V_55 = V_54 ;
F_30 ( V_55 -> V_2 ) ;
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
struct V_32 * F_31 ( struct V_27 * V_28 ,
const char * V_53 )
{
const char * V_22 = V_28 ? F_32 ( V_28 ) : NULL ;
struct V_32 * V_33 ;
if ( V_28 ) {
V_33 = F_21 ( V_28 -> V_30 ,
V_53 ) ;
if ( V_33 != NULL )
return V_33 ;
}
return F_28 ( V_22 , V_53 ) ;
}
void F_33 ( struct V_32 * V_33 )
{
F_18 ( V_33 -> V_2 ) ;
F_10 ( V_33 ) ;
}
struct V_32 * F_34 ( struct V_27 * V_28 )
{
const char * V_22 ;
struct V_32 * V_49 ;
struct V_7 * V_55 = NULL ;
int V_51 = 0 ;
int V_50 = 0 ;
int V_5 , V_6 ;
if ( V_28 == NULL )
return F_20 ( - V_44 ) ;
V_49 = F_26 ( V_28 ) ;
if ( V_49 )
return V_49 ;
V_22 = F_32 ( V_28 ) ;
F_2 ( & V_9 ) ;
F_29 (c, &iio_map_list, l)
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
F_29 (c, &iio_map_list, l) {
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
F_30 ( V_49 [ V_50 ] . V_2 ) ;
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
void F_35 ( struct V_32 * V_25 )
{
struct V_32 * V_23 = & V_25 [ 0 ] ;
while ( V_23 -> V_2 ) {
F_18 ( V_23 -> V_2 ) ;
V_23 ++ ;
}
F_10 ( V_25 ) ;
}
static int F_36 ( struct V_32 * V_23 , int * V_61 , int * V_62 ,
enum V_63 V_64 )
{
int V_65 ;
if ( V_62 == NULL )
V_62 = & V_65 ;
return V_23 -> V_2 -> V_64 -> V_66 ( V_23 -> V_2 , V_23 -> V_33 ,
V_61 , V_62 , V_64 ) ;
}
int F_37 ( struct V_32 * V_23 , int * V_61 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_67 ) ;
if ( V_23 -> V_2 -> V_64 == NULL ) {
V_6 = - V_17 ;
goto V_68;
}
V_6 = F_36 ( V_23 , V_61 , NULL , V_69 ) ;
V_68:
F_5 ( & V_23 -> V_2 -> V_67 ) ;
return V_6 ;
}
static int F_38 ( struct V_32 * V_23 ,
int V_70 , int * V_71 , unsigned int V_72 )
{
int V_73 , V_74 , V_75 , V_76 ;
T_1 V_77 = V_70 ;
int V_6 ;
V_6 = F_36 ( V_23 , & V_76 , NULL , V_78 ) ;
if ( V_6 == 0 )
V_77 += V_76 ;
V_73 = F_36 ( V_23 , & V_74 , & V_75 ,
V_79 ) ;
if ( V_73 < 0 )
return V_73 ;
switch ( V_73 ) {
case V_80 :
* V_71 = V_77 * V_74 ;
break;
case V_81 :
if ( V_75 < 0 )
* V_71 = - V_77 * V_74 ;
else
* V_71 = V_77 * V_74 ;
* V_71 += F_39 ( V_77 * ( T_1 ) V_75 * V_72 ,
1000000LL ) ;
break;
case V_82 :
if ( V_75 < 0 )
* V_71 = - V_77 * V_74 ;
else
* V_71 = V_77 * V_74 ;
* V_71 += F_39 ( V_77 * ( T_1 ) V_75 * V_72 ,
1000000000LL ) ;
break;
case V_83 :
* V_71 = F_39 ( V_77 * ( T_1 ) V_74 * V_72 ,
V_75 ) ;
break;
case V_84 :
* V_71 = ( V_77 * ( T_1 ) V_74 * V_72 ) >> V_75 ;
break;
default:
return - V_44 ;
}
return 0 ;
}
int F_40 ( struct V_32 * V_23 , int V_70 ,
int * V_71 , unsigned int V_72 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_67 ) ;
if ( V_23 -> V_2 -> V_64 == NULL ) {
V_6 = - V_17 ;
goto V_68;
}
V_6 = F_38 ( V_23 , V_70 , V_71 ,
V_72 ) ;
V_68:
F_5 ( & V_23 -> V_2 -> V_67 ) ;
return V_6 ;
}
int F_41 ( struct V_32 * V_23 , int * V_61 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_67 ) ;
if ( V_23 -> V_2 -> V_64 == NULL ) {
V_6 = - V_17 ;
goto V_68;
}
if ( F_42 ( V_23 -> V_33 , V_85 ) ) {
V_6 = F_36 ( V_23 , V_61 , NULL ,
V_85 ) ;
} else {
V_6 = F_36 ( V_23 , V_61 , NULL , V_69 ) ;
if ( V_6 < 0 )
goto V_68;
V_6 = F_38 ( V_23 , * V_61 , V_61 , 1 ) ;
}
V_68:
F_5 ( & V_23 -> V_2 -> V_67 ) ;
return V_6 ;
}
int F_43 ( struct V_32 * V_23 , int * V_61 , int * V_62 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_67 ) ;
if ( V_23 -> V_2 -> V_64 == NULL ) {
V_6 = - V_17 ;
goto V_68;
}
V_6 = F_36 ( V_23 , V_61 , V_62 , V_79 ) ;
V_68:
F_5 ( & V_23 -> V_2 -> V_67 ) ;
return V_6 ;
}
int F_44 ( struct V_32 * V_23 , enum V_86 * type )
{
int V_6 = 0 ;
F_2 ( & V_23 -> V_2 -> V_67 ) ;
if ( V_23 -> V_2 -> V_64 == NULL ) {
V_6 = - V_17 ;
goto V_68;
}
* type = V_23 -> V_33 -> type ;
V_68:
F_5 ( & V_23 -> V_2 -> V_67 ) ;
return V_6 ;
}
