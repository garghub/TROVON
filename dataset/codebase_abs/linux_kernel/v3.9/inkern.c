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
static struct V_27 * F_12 ( const char * V_22 ,
const char * V_28 )
{
struct V_7 * V_29 = NULL , * V_30 = NULL ;
struct V_27 * V_31 ;
int V_32 ;
if ( V_22 == NULL && V_28 == NULL )
return F_13 ( - V_17 ) ;
F_2 ( & V_9 ) ;
F_14 (c_i, &iio_map_list, l) {
if ( ( V_22 && strcmp ( V_22 , V_29 -> V_14 -> V_10 ) != 0 ) ||
( V_28 &&
strcmp ( V_28 , V_29 -> V_14 -> V_33 ) != 0 ) )
continue;
V_30 = V_29 ;
F_15 ( V_30 -> V_2 ) ;
break;
}
F_5 ( & V_9 ) ;
if ( V_30 == NULL )
return F_13 ( - V_17 ) ;
V_31 = F_3 ( sizeof( * V_31 ) , V_11 ) ;
if ( V_31 == NULL ) {
V_32 = - V_12 ;
goto V_34;
}
V_31 -> V_2 = V_30 -> V_2 ;
if ( V_30 -> V_14 -> V_35 ) {
V_31 -> V_31 =
F_11 ( V_31 -> V_2 ,
V_30 -> V_14 -> V_35 ) ;
if ( V_31 -> V_31 == NULL ) {
V_32 = - V_36 ;
goto V_37;
}
}
return V_31 ;
V_37:
F_10 ( V_31 ) ;
V_34:
F_16 ( V_30 -> V_2 ) ;
return F_13 ( V_32 ) ;
}
struct V_27 * F_17 ( struct V_38 * V_39 ,
const char * V_28 )
{
const char * V_22 = V_39 ? F_18 ( V_39 ) : NULL ;
return F_12 ( V_22 , V_28 ) ;
}
void F_19 ( struct V_27 * V_31 )
{
F_16 ( V_31 -> V_2 ) ;
F_10 ( V_31 ) ;
}
struct V_27 * F_20 ( struct V_38 * V_39 )
{
const char * V_22 ;
struct V_27 * V_40 ;
struct V_7 * V_30 = NULL ;
int V_41 = 0 ;
int V_42 = 0 ;
int V_5 , V_6 ;
if ( V_39 == NULL )
return F_13 ( - V_36 ) ;
V_22 = F_18 ( V_39 ) ;
F_2 ( & V_9 ) ;
F_14 (c, &iio_map_list, l)
if ( V_22 && strcmp ( V_22 , V_30 -> V_14 -> V_10 ) != 0 )
continue;
else
V_41 ++ ;
if ( V_41 == 0 ) {
V_6 = - V_17 ;
goto V_13;
}
V_40 = F_3 ( sizeof( * V_40 ) * ( V_41 + 1 ) , V_11 ) ;
if ( V_40 == NULL ) {
V_6 = - V_12 ;
goto V_13;
}
F_14 (c, &iio_map_list, l) {
if ( V_22 && strcmp ( V_22 , V_30 -> V_14 -> V_10 ) != 0 )
continue;
V_40 [ V_42 ] . V_2 = V_30 -> V_2 ;
V_40 [ V_42 ] . V_43 = V_30 -> V_14 -> V_44 ;
V_40 [ V_42 ] . V_31 =
F_11 ( V_40 [ V_42 ] . V_2 ,
V_30 -> V_14 -> V_35 ) ;
if ( V_40 [ V_42 ] . V_31 == NULL ) {
V_6 = - V_36 ;
goto V_45;
}
F_15 ( V_40 [ V_42 ] . V_2 ) ;
V_42 ++ ;
}
if ( V_42 == 0 ) {
V_6 = - V_17 ;
goto V_45;
}
F_5 ( & V_9 ) ;
return V_40 ;
V_45:
for ( V_5 = 0 ; V_5 < V_41 ; V_5 ++ )
F_16 ( V_40 [ V_5 ] . V_2 ) ;
F_10 ( V_40 ) ;
V_13:
F_5 ( & V_9 ) ;
return F_13 ( V_6 ) ;
}
void F_21 ( struct V_27 * V_25 )
{
struct V_27 * V_23 = & V_25 [ 0 ] ;
while ( V_23 -> V_2 ) {
F_16 ( V_23 -> V_2 ) ;
V_23 ++ ;
}
F_10 ( V_25 ) ;
}
static int F_22 ( struct V_27 * V_23 , int * V_46 , int * V_47 ,
enum V_48 V_49 )
{
int V_50 ;
if ( V_47 == NULL )
V_47 = & V_50 ;
return V_23 -> V_2 -> V_49 -> V_51 ( V_23 -> V_2 , V_23 -> V_31 ,
V_46 , V_47 , V_49 ) ;
}
int F_23 ( struct V_27 * V_23 , int * V_46 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_52 ) ;
if ( V_23 -> V_2 -> V_49 == NULL ) {
V_6 = - V_17 ;
goto V_53;
}
V_6 = F_22 ( V_23 , V_46 , NULL , V_54 ) ;
V_53:
F_5 ( & V_23 -> V_2 -> V_52 ) ;
return V_6 ;
}
static int F_24 ( struct V_27 * V_23 ,
int V_55 , int * V_56 , unsigned int V_57 )
{
int V_58 , V_59 , V_60 , V_61 ;
T_1 V_62 = V_55 ;
int V_6 ;
V_6 = F_22 ( V_23 , & V_61 , NULL , V_63 ) ;
if ( V_6 == 0 )
V_62 += V_61 ;
V_58 = F_22 ( V_23 , & V_59 , & V_60 ,
V_63 ) ;
if ( V_58 < 0 )
return V_58 ;
switch ( V_58 ) {
case V_64 :
* V_56 = V_62 * V_59 ;
break;
case V_65 :
if ( V_60 < 0 )
* V_56 = - V_62 * V_59 ;
else
* V_56 = V_62 * V_59 ;
* V_56 += F_25 ( V_62 * ( T_1 ) V_60 * V_57 ,
1000000LL ) ;
break;
case V_66 :
if ( V_60 < 0 )
* V_56 = - V_62 * V_59 ;
else
* V_56 = V_62 * V_59 ;
* V_56 += F_25 ( V_62 * ( T_1 ) V_60 * V_57 ,
1000000000LL ) ;
break;
case V_67 :
* V_56 = F_25 ( V_62 * ( T_1 ) V_59 * V_57 ,
V_60 ) ;
break;
case V_68 :
* V_56 = ( V_62 * ( T_1 ) V_59 * V_57 ) >> V_60 ;
break;
default:
return - V_36 ;
}
return 0 ;
}
int F_26 ( struct V_27 * V_23 , int V_55 ,
int * V_56 , unsigned int V_57 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_52 ) ;
if ( V_23 -> V_2 -> V_49 == NULL ) {
V_6 = - V_17 ;
goto V_53;
}
V_6 = F_24 ( V_23 , V_55 , V_56 ,
V_57 ) ;
V_53:
F_5 ( & V_23 -> V_2 -> V_52 ) ;
return V_6 ;
}
int F_27 ( struct V_27 * V_23 , int * V_46 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_52 ) ;
if ( V_23 -> V_2 -> V_49 == NULL ) {
V_6 = - V_17 ;
goto V_53;
}
if ( F_28 ( V_23 -> V_31 , V_69 ) ) {
V_6 = F_22 ( V_23 , V_46 , NULL ,
V_69 ) ;
} else {
V_6 = F_22 ( V_23 , V_46 , NULL , V_54 ) ;
if ( V_6 < 0 )
goto V_53;
V_6 = F_24 ( V_23 , * V_46 , V_46 , 1 ) ;
}
V_53:
F_5 ( & V_23 -> V_2 -> V_52 ) ;
return V_6 ;
}
int F_29 ( struct V_27 * V_23 , int * V_46 , int * V_47 )
{
int V_6 ;
F_2 ( & V_23 -> V_2 -> V_52 ) ;
if ( V_23 -> V_2 -> V_49 == NULL ) {
V_6 = - V_17 ;
goto V_53;
}
V_6 = F_22 ( V_23 , V_46 , V_47 , V_63 ) ;
V_53:
F_5 ( & V_23 -> V_2 -> V_52 ) ;
return V_6 ;
}
int F_30 ( struct V_27 * V_23 , enum V_70 * type )
{
int V_6 = 0 ;
F_2 ( & V_23 -> V_2 -> V_52 ) ;
if ( V_23 -> V_2 -> V_49 == NULL ) {
V_6 = - V_17 ;
goto V_53;
}
* type = V_23 -> V_31 -> type ;
V_53:
F_5 ( & V_23 -> V_2 -> V_52 ) ;
return V_6 ;
}
