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
int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 , V_6 = 0 ;
bool V_17 ;
struct V_7 * V_8 ;
if ( V_4 == NULL )
return 0 ;
F_2 ( & V_9 ) ;
while ( V_4 [ V_5 ] . V_10 != NULL ) {
V_17 = false ;
F_7 (mapi, &iio_map_list, l)
if ( & V_4 [ V_5 ] == V_8 -> V_14 ) {
F_8 ( & V_8 -> V_15 ) ;
F_9 ( V_8 ) ;
V_17 = true ;
break;
}
if ( ! V_17 ) {
V_6 = - V_18 ;
goto V_13;
}
V_5 ++ ;
}
V_13:
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
struct V_25 * F_11 ( const char * V_20 , const char * V_26 )
{
struct V_7 * V_27 = NULL , * V_28 = NULL ;
struct V_25 * V_29 ;
int V_30 ;
if ( V_20 == NULL && V_26 == NULL )
return F_12 ( - V_18 ) ;
F_2 ( & V_9 ) ;
F_7 (c_i, &iio_map_list, l) {
if ( ( V_20 && strcmp ( V_20 , V_27 -> V_14 -> V_10 ) != 0 ) ||
( V_26 &&
strcmp ( V_26 , V_27 -> V_14 -> V_31 ) != 0 ) )
continue;
V_28 = V_27 ;
F_13 ( V_28 -> V_2 ) ;
break;
}
F_5 ( & V_9 ) ;
if ( V_28 == NULL )
return F_12 ( - V_18 ) ;
V_29 = F_3 ( sizeof( * V_29 ) , V_11 ) ;
if ( V_29 == NULL ) {
V_30 = - V_12 ;
goto V_32;
}
V_29 -> V_2 = V_28 -> V_2 ;
if ( V_28 -> V_14 -> V_33 ) {
V_29 -> V_29 =
F_10 ( V_29 -> V_2 ,
V_28 -> V_14 -> V_33 ) ;
if ( V_29 -> V_29 == NULL ) {
V_30 = - V_34 ;
goto V_35;
}
}
return V_29 ;
V_35:
F_9 ( V_29 ) ;
V_32:
F_14 ( V_28 -> V_2 ) ;
return F_12 ( V_30 ) ;
}
void F_15 ( struct V_25 * V_29 )
{
F_14 ( V_29 -> V_2 ) ;
F_9 ( V_29 ) ;
}
struct V_25 * F_16 ( const char * V_20 )
{
struct V_25 * V_36 ;
struct V_7 * V_28 = NULL ;
int V_37 = 0 ;
int V_38 = 0 ;
int V_5 , V_6 ;
if ( V_20 == NULL )
return F_12 ( - V_34 ) ;
F_2 ( & V_9 ) ;
F_7 (c, &iio_map_list, l)
if ( V_20 && strcmp ( V_20 , V_28 -> V_14 -> V_10 ) != 0 )
continue;
else
V_37 ++ ;
if ( V_37 == 0 ) {
V_6 = - V_18 ;
goto V_13;
}
V_36 = F_3 ( sizeof( * V_36 ) * ( V_37 + 1 ) , V_11 ) ;
if ( V_36 == NULL ) {
V_6 = - V_12 ;
goto V_13;
}
F_7 (c, &iio_map_list, l) {
if ( V_20 && strcmp ( V_20 , V_28 -> V_14 -> V_10 ) != 0 )
continue;
V_36 [ V_38 ] . V_2 = V_28 -> V_2 ;
V_36 [ V_38 ] . V_39 = V_28 -> V_14 -> V_40 ;
V_36 [ V_38 ] . V_29 =
F_10 ( V_36 [ V_38 ] . V_2 ,
V_28 -> V_14 -> V_33 ) ;
if ( V_36 [ V_38 ] . V_29 == NULL ) {
V_6 = - V_34 ;
goto V_41;
}
F_13 ( V_36 [ V_38 ] . V_2 ) ;
V_38 ++ ;
}
if ( V_38 == 0 ) {
V_6 = - V_18 ;
goto V_41;
}
F_5 ( & V_9 ) ;
return V_36 ;
V_41:
for ( V_5 = 0 ; V_5 < V_37 ; V_5 ++ )
F_14 ( V_36 [ V_5 ] . V_2 ) ;
F_9 ( V_36 ) ;
V_13:
F_5 ( & V_9 ) ;
return F_12 ( V_6 ) ;
}
void F_17 ( struct V_25 * V_23 )
{
struct V_25 * V_21 = & V_23 [ 0 ] ;
while ( V_21 -> V_2 ) {
F_14 ( V_21 -> V_2 ) ;
V_21 ++ ;
}
F_9 ( V_23 ) ;
}
static int F_18 ( struct V_25 * V_21 , int * V_42 , int * V_43 ,
enum V_44 V_45 )
{
int V_46 ;
if ( V_43 == NULL )
V_43 = & V_46 ;
return V_21 -> V_2 -> V_45 -> V_47 ( V_21 -> V_2 , V_21 -> V_29 ,
V_42 , V_43 , V_45 ) ;
}
int F_19 ( struct V_25 * V_21 , int * V_42 )
{
int V_6 ;
F_2 ( & V_21 -> V_2 -> V_48 ) ;
if ( V_21 -> V_2 -> V_45 == NULL ) {
V_6 = - V_18 ;
goto V_49;
}
V_6 = F_18 ( V_21 , V_42 , NULL , V_50 ) ;
V_49:
F_5 ( & V_21 -> V_2 -> V_48 ) ;
return V_6 ;
}
static int F_20 ( struct V_25 * V_21 ,
int V_51 , int * V_52 , unsigned int V_53 )
{
int V_54 , V_55 , V_56 , V_57 ;
T_1 V_58 = V_51 ;
int V_6 ;
V_6 = F_18 ( V_21 , & V_57 , NULL , V_59 ) ;
if ( V_6 == 0 )
V_58 += V_57 ;
V_54 = F_18 ( V_21 , & V_55 , & V_56 ,
V_59 ) ;
if ( V_54 < 0 )
return V_54 ;
switch ( V_54 ) {
case V_60 :
* V_52 = V_58 * V_55 ;
break;
case V_61 :
if ( V_56 < 0 )
* V_52 = - V_58 * V_55 ;
else
* V_52 = V_58 * V_55 ;
* V_52 += F_21 ( V_58 * ( T_1 ) V_56 * V_53 ,
1000000LL ) ;
break;
case V_62 :
if ( V_56 < 0 )
* V_52 = - V_58 * V_55 ;
else
* V_52 = V_58 * V_55 ;
* V_52 += F_21 ( V_58 * ( T_1 ) V_56 * V_53 ,
1000000000LL ) ;
break;
case V_63 :
* V_52 = F_21 ( V_58 * ( T_1 ) V_55 * V_53 ,
V_56 ) ;
break;
case V_64 :
* V_52 = ( V_58 * ( T_1 ) V_55 * V_53 ) >> V_56 ;
break;
default:
return - V_34 ;
}
return 0 ;
}
int F_22 ( struct V_25 * V_21 , int V_51 ,
int * V_52 , unsigned int V_53 )
{
int V_6 ;
F_2 ( & V_21 -> V_2 -> V_48 ) ;
if ( V_21 -> V_2 -> V_45 == NULL ) {
V_6 = - V_18 ;
goto V_49;
}
V_6 = F_20 ( V_21 , V_51 , V_52 ,
V_53 ) ;
V_49:
F_5 ( & V_21 -> V_2 -> V_48 ) ;
return V_6 ;
}
int F_23 ( struct V_25 * V_21 , int * V_42 )
{
int V_6 ;
F_2 ( & V_21 -> V_2 -> V_48 ) ;
if ( V_21 -> V_2 -> V_45 == NULL ) {
V_6 = - V_18 ;
goto V_49;
}
if ( F_24 ( V_21 -> V_29 , V_65 ) ) {
V_6 = F_18 ( V_21 , V_42 , NULL ,
V_65 ) ;
} else {
V_6 = F_18 ( V_21 , V_42 , NULL , V_50 ) ;
if ( V_6 < 0 )
goto V_49;
V_6 = F_20 ( V_21 , * V_42 , V_42 , 1 ) ;
}
V_49:
F_5 ( & V_21 -> V_2 -> V_48 ) ;
return V_6 ;
}
int F_25 ( struct V_25 * V_21 , int * V_42 , int * V_43 )
{
int V_6 ;
F_2 ( & V_21 -> V_2 -> V_48 ) ;
if ( V_21 -> V_2 -> V_45 == NULL ) {
V_6 = - V_18 ;
goto V_49;
}
V_6 = F_18 ( V_21 , V_42 , V_43 , V_59 ) ;
V_49:
F_5 ( & V_21 -> V_2 -> V_48 ) ;
return V_6 ;
}
int F_26 ( struct V_25 * V_21 , enum V_66 * type )
{
int V_6 = 0 ;
F_2 ( & V_21 -> V_2 -> V_48 ) ;
if ( V_21 -> V_2 -> V_45 == NULL ) {
V_6 = - V_18 ;
goto V_49;
}
* type = V_21 -> V_29 -> type ;
V_49:
F_5 ( & V_21 -> V_2 -> V_48 ) ;
return V_6 ;
}
