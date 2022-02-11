static void
F_1 ( T_1 * V_1 , const T_2 type )
{
T_3 * V_2 ;
T_4 * V_3 ;
V_1 -> V_4 = NULL ;
V_1 -> V_5 = NULL ;
V_1 -> type = type ;
V_1 -> V_6 = FALSE ;
V_1 -> V_7 = 0 ;
V_1 -> V_8 = 0 ;
V_1 -> V_9 = NULL ;
V_1 -> V_10 = NULL ;
V_1 -> V_11 = - 1 ;
V_1 -> V_12 = NULL ;
switch( type ) {
case V_13 :
break;
case V_14 :
V_2 = & V_1 -> V_15 . V_16 ;
V_2 -> V_1 = NULL ;
V_2 -> V_17 = 0 ;
V_2 -> V_7 = 0 ;
break;
case V_18 :
V_3 = & V_1 -> V_15 . V_3 ;
V_3 -> V_19 = NULL ;
V_3 -> V_20 = NULL ;
V_3 -> V_21 = NULL ;
break;
default:
F_2 () ;
break;
}
}
T_1 *
F_3 ( const T_2 type )
{
T_1 * V_1 ;
V_1 = F_4 ( T_1 ) ;
F_1 ( V_1 , type ) ;
return V_1 ;
}
static T_1 *
F_5 ( const T_5 V_22 , const T_5 V_23 )
{
T_1 * V_1 = F_3 ( V_14 ) ;
V_1 -> V_15 . V_16 . V_17 = V_22 ;
V_1 -> V_15 . V_16 . V_7 = V_23 ;
return V_1 ;
}
static void
F_6 ( T_1 * V_1 )
{
T_4 * V_3 ;
F_7 ( V_1 ) ;
switch ( V_1 -> type ) {
case V_13 :
if ( V_1 -> V_9 ) {
V_1 -> V_9 ( ( V_24 ) V_1 -> V_10 ) ;
}
break;
case V_14 :
break;
case V_18 :
V_3 = & V_1 -> V_15 . V_3 ;
F_8 ( V_3 -> V_19 ) ;
F_9 ( V_3 -> V_20 ) ;
F_9 ( V_3 -> V_21 ) ;
if ( V_1 -> V_10 ) {
F_9 ( ( V_24 ) V_1 -> V_10 ) ;
}
break;
default:
F_2 () ;
}
F_10 ( T_1 , V_1 ) ;
}
void
F_11 ( T_1 * V_1 )
{
F_12 ( V_1 ) ;
}
void
F_12 ( T_1 * V_1 )
{
T_1 * V_25 ;
F_7 ( V_1 ) ;
F_13 ( V_1 -> V_4 == NULL , L_1 ) ;
while ( V_1 ) {
V_25 = V_1 -> V_5 ;
F_13 ( ( V_25 == NULL ) || ( V_1 == V_25 -> V_4 ) , L_2 ) ;
F_6 ( V_1 ) ;
V_1 = V_25 ;
}
}
void
F_14 ( T_1 * V_1 , const T_6 V_26 )
{
F_7 ( V_1 ) ;
F_7 ( V_1 -> type == V_13 ) ;
V_1 -> V_9 = V_26 ;
}
static void
F_15 ( T_1 * V_27 , T_1 * V_28 )
{
F_7 ( V_27 && V_28 ) ;
F_7 ( ! V_28 -> V_5 && ! V_28 -> V_4 ) ;
V_28 -> V_5 = V_27 -> V_5 ;
V_28 -> V_4 = V_27 ;
if ( V_27 -> V_5 )
V_27 -> V_5 -> V_4 = V_28 ;
V_27 -> V_5 = V_28 ;
}
void
F_16 ( T_1 * V_27 , T_1 * V_28 )
{
F_7 ( V_27 && V_28 ) ;
F_7 ( V_27 -> V_6 ) ;
F_7 ( V_28 -> V_6 ) ;
F_7 ( V_28 -> type == V_13 ) ;
F_15 ( V_27 , V_28 ) ;
}
static void
F_17 ( T_1 * V_1 , const T_7 * V_29 , const T_5 V_7 , const T_8 V_8 )
{
V_1 -> V_10 = V_29 ;
V_1 -> V_7 = V_7 ;
V_1 -> V_8 = V_8 ;
V_1 -> V_6 = TRUE ;
}
void
F_18 ( T_1 * V_1 , const T_7 * V_29 , const T_5 V_7 , const T_8 V_8 )
{
F_7 ( V_1 ) ;
F_7 ( V_1 -> type == V_13 ) ;
F_7 ( ! V_1 -> V_6 ) ;
F_19 ( V_8 < - 1 , V_30 ) ;
F_17 ( V_1 , V_29 , V_7 , V_8 ) ;
}
T_1 *
F_20 ( const T_7 * V_29 , const T_5 V_7 , const T_8 V_8 )
{
T_1 * V_1 ;
F_19 ( V_8 < - 1 , V_30 ) ;
V_1 = F_3 ( V_13 ) ;
F_17 ( V_1 , V_29 , V_7 , V_8 ) ;
V_1 -> V_12 = V_1 ;
return V_1 ;
}
T_1 *
F_21 ( T_1 * V_27 , const T_7 * V_29 , const T_5 V_7 , const T_8 V_8 )
{
T_1 * V_1 = F_20 ( V_29 , V_7 , V_8 ) ;
if ( V_1 ) {
F_16 ( V_27 , V_1 ) ;
}
return V_1 ;
}
T_1 *
F_22 ( T_1 * V_1 , T_9 V_31 , T_10 V_32 )
{
T_1 * V_33 = NULL ;
T_9 V_34 ;
T_10 V_35 , V_36 ;
T_7 V_37 , V_38 , V_39 , * V_40 ;
const T_7 * V_29 ;
V_34 = V_31 >> 3 ;
V_37 = V_31 % 8 ;
V_38 = 8 - V_37 ;
if ( V_32 == - 1 ) {
V_35 = F_23 ( V_1 , V_34 ) ;
V_39 = 0 ;
} else {
V_35 = V_32 >> 3 ;
V_39 = V_32 % 8 ;
if ( V_39 ) {
V_35 ++ ;
}
}
if ( ( V_37 == 0 ) && ( V_39 == 0 ) ) {
return F_24 ( V_1 , V_34 , V_35 , - 1 ) ;
}
F_7 ( V_35 > 0 ) ;
V_40 = F_25 ( V_35 ) ;
if ( F_23 ( V_1 , V_34 ) > V_35 ) {
V_29 = F_26 ( V_1 , V_34 , V_35 + 1 ) ;
for ( V_36 = 0 ; V_36 < V_35 ; V_36 ++ )
V_40 [ V_36 ] = ( V_29 [ V_36 ] << V_37 ) | ( V_29 [ V_36 + 1 ] >> V_38 ) ;
} else {
V_29 = F_26 ( V_1 , V_34 , V_35 ) ;
for ( V_36 = 0 ; V_36 < ( V_35 - 1 ) ; V_36 ++ )
V_40 [ V_36 ] = ( V_29 [ V_36 ] << V_37 ) | ( V_29 [ V_36 + 1 ] >> V_38 ) ;
V_40 [ V_35 - 1 ] = V_29 [ V_35 - 1 ] << V_37 ;
}
V_40 [ V_35 - 1 ] &= V_41 [ V_39 ] ;
V_33 = F_21 ( V_1 , V_40 , V_35 , V_35 ) ;
return V_33 ;
}
static T_11
F_27 ( const T_5 V_42 , const T_5 V_43 ,
const T_8 V_17 , const T_8 V_44 ,
T_5 * V_45 , T_5 * V_46 , int * V_47 )
{
F_7 ( V_45 ) ;
F_7 ( V_46 ) ;
if ( V_17 >= 0 ) {
if ( ( T_5 ) V_17 > V_43 ) {
if ( V_47 ) {
* V_47 = V_30 ;
}
return FALSE ;
}
else if ( ( T_5 ) V_17 > V_42 ) {
if ( V_47 ) {
* V_47 = V_48 ;
}
return FALSE ;
}
else {
* V_45 = V_17 ;
}
}
else {
if ( ( T_5 ) - V_17 > V_43 ) {
if ( V_47 ) {
* V_47 = V_30 ;
}
return FALSE ;
}
else if ( ( T_5 ) - V_17 > V_42 ) {
if ( V_47 ) {
* V_47 = V_48 ;
}
return FALSE ;
}
else {
* V_45 = V_42 + V_17 ;
}
}
if ( V_44 < - 1 ) {
if ( V_47 ) {
* V_47 = V_48 ;
}
return FALSE ;
}
else if ( V_44 == - 1 ) {
* V_46 = V_42 - * V_45 ;
}
else {
* V_46 = V_44 ;
}
return TRUE ;
}
static T_11
F_28 ( const T_5 V_42 , const T_5 V_43 ,
const T_8 V_17 , T_8 const V_44 ,
T_5 * V_45 , T_5 * V_46 , int * V_47 )
{
T_5 V_49 ;
if ( ! F_27 ( V_42 , V_43 ,
V_17 , V_44 , V_45 , V_46 , V_47 ) ) {
return FALSE ;
}
V_49 = * V_45 + * V_46 ;
if ( V_49 < * V_45 )
V_49 = V_50 ;
if ( V_49 <= V_42 ) {
return TRUE ;
}
else if ( V_49 <= V_43 ) {
if ( V_47 ) {
* V_47 = V_48 ;
}
}
else {
if ( V_47 ) {
* V_47 = V_30 ;
}
}
return FALSE ;
}
static void
F_29 ( const T_5 V_42 , const T_5 V_43 ,
const T_8 V_17 , T_8 const V_44 ,
T_5 * V_45 , T_5 * V_46 )
{
int V_47 = 0 ;
if ( ! F_28 ( V_42 , V_43 ,
V_17 , V_44 , V_45 , V_46 , & V_47 ) ) {
F_7 ( V_47 > 0 ) ;
F_30 ( V_47 ) ;
}
}
static void
F_31 ( T_1 * V_1 , T_1 * V_2 , const T_8 V_8 )
{
V_1 -> V_15 . V_16 . V_1 = V_2 ;
V_1 -> V_7 = V_1 -> V_15 . V_16 . V_7 ;
if ( V_8 == - 1 ) {
V_1 -> V_8 = V_2 -> V_8 - V_1 -> V_15 . V_16 . V_17 ;
}
else {
V_1 -> V_8 = V_8 ;
}
V_1 -> V_6 = TRUE ;
F_15 ( V_2 , V_1 ) ;
if ( V_2 -> V_10 != NULL ) {
V_1 -> V_10 = V_2 -> V_10 + V_1 -> V_15 . V_16 . V_17 ;
}
}
void
F_32 ( T_1 * V_1 , T_1 * V_2 ,
const T_8 V_51 , const T_8 V_52 , const T_8 V_8 )
{
F_7 ( V_1 ) ;
F_7 ( V_1 -> type == V_14 ) ;
F_7 ( ! V_1 -> V_6 ) ;
F_19 ( V_8 < - 1 , V_30 ) ;
F_29 ( V_2 -> V_7 , V_2 -> V_8 , V_51 , V_52 ,
& V_1 -> V_15 . V_16 . V_17 ,
& V_1 -> V_15 . V_16 . V_7 ) ;
F_31 ( V_1 , V_2 , V_8 ) ;
}
T_1 *
F_24 ( T_1 * V_2 , const T_8 V_51 , const T_8 V_52 , const T_8 V_8 )
{
T_1 * V_1 ;
T_5 V_22 ;
T_5 V_23 ;
F_7 ( V_2 && V_2 -> V_6 ) ;
F_19 ( V_8 < - 1 , V_30 ) ;
F_29 ( V_2 -> V_7 , V_2 -> V_8 , V_51 , V_52 ,
& V_22 ,
& V_23 ) ;
V_1 = F_5 ( V_22 , V_23 ) ;
F_31 ( V_1 , V_2 , V_8 ) ;
V_1 -> V_12 = V_2 -> V_12 ;
return V_1 ;
}
T_1 *
F_33 ( T_1 * V_2 , const T_8 V_51 )
{
T_1 * V_1 ;
T_5 V_22 ;
T_5 V_23 ;
F_29 ( V_2 -> V_7 , V_2 -> V_8 , V_51 , - 1 ,
& V_22 ,
& V_23 ) ;
V_1 = F_5 ( V_22 , V_23 ) ;
F_31 ( V_1 , V_2 , - 1 ) ;
V_1 -> V_12 = V_2 -> V_12 ;
return V_1 ;
}
T_1 *
F_34 ( void )
{
return F_3 ( V_18 ) ;
}
void
F_35 ( T_1 * V_1 , T_1 * V_53 )
{
T_4 * V_3 ;
F_7 ( V_1 && ! V_1 -> V_6 ) ;
F_7 ( V_1 -> type == V_18 ) ;
V_3 = & V_1 -> V_15 . V_3 ;
V_3 -> V_19 = F_36 ( V_3 -> V_19 , V_53 ) ;
}
void
F_37 ( T_1 * V_1 , T_1 * V_53 )
{
T_4 * V_3 ;
F_7 ( V_1 && ! V_1 -> V_6 ) ;
F_7 ( V_1 -> type == V_18 ) ;
V_3 = & V_1 -> V_15 . V_3 ;
V_3 -> V_19 = F_38 ( V_3 -> V_19 , V_53 ) ;
}
void
F_39 ( T_1 * V_1 )
{
T_12 * V_54 ;
T_5 V_55 ;
T_1 * V_56 ;
T_4 * V_3 ;
int V_36 = 0 ;
F_7 ( V_1 && ! V_1 -> V_6 ) ;
F_7 ( V_1 -> type == V_18 ) ;
F_7 ( V_1 -> V_7 == 0 ) ;
F_7 ( V_1 -> V_8 == 0 ) ;
V_3 = & V_1 -> V_15 . V_3 ;
V_55 = F_40 ( V_3 -> V_19 ) ;
V_3 -> V_20 = F_41 ( T_5 , V_55 ) ;
V_3 -> V_21 = F_41 ( T_5 , V_55 ) ;
for ( V_54 = V_3 -> V_19 ; V_54 != NULL ; V_54 = V_54 -> V_5 ) {
F_7 ( ( T_5 ) V_36 < V_55 ) ;
V_56 = V_54 -> V_29 ;
V_3 -> V_20 [ V_36 ] = V_1 -> V_7 ;
V_1 -> V_7 += V_56 -> V_7 ;
V_1 -> V_8 += V_56 -> V_8 ;
V_3 -> V_21 [ V_36 ] = V_1 -> V_7 - 1 ;
V_36 ++ ;
}
F_15 ( ( T_1 * ) V_3 -> V_19 -> V_29 , V_1 ) ;
V_1 -> V_6 = TRUE ;
}
T_5
F_42 ( const T_1 * V_1 )
{
F_7 ( V_1 && V_1 -> V_6 ) ;
return V_1 -> V_7 ;
}
T_8
F_23 ( const T_1 * V_1 , const T_8 V_17 )
{
T_5 V_57 , V_58 ;
F_7 ( V_1 && V_1 -> V_6 ) ;
if ( F_27 ( V_1 -> V_7 , V_1 -> V_8 , V_17 , - 1 , & V_57 , & V_58 , NULL ) ) {
return V_58 ;
}
else {
return - 1 ;
}
}
T_5
F_43 ( const T_1 * V_1 , const T_8 V_17 )
{
T_5 V_57 , V_58 ;
int V_47 ;
F_7 ( V_1 && V_1 -> V_6 ) ;
if ( ! F_27 ( V_1 -> V_7 , V_1 -> V_8 , V_17 , - 1 , & V_57 , & V_58 , & V_47 ) ) {
F_30 ( V_47 ) ;
}
if ( V_58 == 0 ) {
if ( V_57 >= V_1 -> V_8 )
F_30 ( V_30 ) ;
else
F_30 ( V_48 ) ;
}
return V_58 ;
}
T_11
F_44 ( const T_1 * V_1 , const T_8 V_17 , const T_8 V_7 )
{
T_5 V_57 , V_58 ;
F_7 ( V_1 && V_1 -> V_6 ) ;
if ( ! F_27 ( V_1 -> V_7 , V_1 -> V_8 , V_17 , V_7 , & V_57 , & V_58 , NULL ) )
return FALSE ;
if ( V_57 + V_58 <= V_1 -> V_7 ) {
return TRUE ;
}
else {
return FALSE ;
}
}
void
F_45 ( const T_1 * V_1 , const T_8 V_17 , const T_8 V_7 )
{
T_5 V_57 , V_58 ;
F_7 ( V_1 && V_1 -> V_6 ) ;
if ( V_7 < 0 ) {
F_30 ( V_30 ) ;
}
F_29 ( V_1 -> V_7 , V_1 -> V_8 , V_17 , V_7 , & V_57 , & V_58 ) ;
}
T_11
F_46 ( const T_1 * V_1 , const T_8 V_17 )
{
T_5 V_57 , V_58 ;
F_7 ( V_1 && V_1 -> V_6 ) ;
if ( ! F_27 ( V_1 -> V_7 , V_1 -> V_8 , V_17 , - 1 , & V_57 , & V_58 , NULL ) )
return FALSE ;
if ( V_57 < V_1 -> V_7 ) {
return TRUE ;
}
else {
return FALSE ;
}
}
T_5
F_47 ( const T_1 * V_1 )
{
F_7 ( V_1 && V_1 -> V_6 ) ;
return V_1 -> V_8 ;
}
T_8
F_48 ( const T_1 * V_1 , const T_8 V_17 )
{
T_5 V_57 , V_58 ;
F_7 ( V_1 && V_1 -> V_6 ) ;
if ( F_27 ( V_1 -> V_7 , V_1 -> V_8 , V_17 , - 1 , & V_57 , & V_58 , NULL ) ) {
if ( V_1 -> V_8 >= V_57 )
return V_1 -> V_8 - V_57 ;
else
return - 1 ;
}
else {
return - 1 ;
}
}
void
F_49 ( T_1 * V_1 , const T_5 V_8 )
{
F_7 ( V_1 && V_1 -> V_6 ) ;
if ( V_8 > V_1 -> V_8 )
F_30 ( V_30 ) ;
V_1 -> V_8 = V_8 ;
if ( V_8 < V_1 -> V_7 )
V_1 -> V_7 = V_8 ;
}
static T_5
F_50 ( const T_1 * V_1 , const T_5 V_59 )
{
T_1 * V_53 ;
switch( V_1 -> type ) {
case V_13 :
return V_59 ;
case V_14 :
V_53 = V_1 -> V_15 . V_16 . V_1 ;
return F_50 ( V_53 , V_59 + V_1 -> V_15 . V_16 . V_17 ) ;
case V_18 :
V_53 = V_1 -> V_15 . V_3 . V_19 -> V_29 ;
return F_50 ( V_53 , V_59 ) ;
}
F_2 () ;
return 0 ;
}
T_5
F_51 ( const T_1 * V_1 )
{
return F_50 ( V_1 , 0 ) ;
}
static const T_7 *
F_52 ( T_1 * V_1 , const T_5 V_57 , const T_5 V_58 )
{
T_5 V_36 , V_55 ;
T_4 * V_3 ;
T_1 * V_56 = NULL ;
T_5 V_60 , V_61 ;
T_12 * V_54 ;
F_7 ( V_1 -> type == V_18 ) ;
V_3 = & V_1 -> V_15 . V_3 ;
V_55 = F_40 ( V_3 -> V_19 ) ;
for ( V_36 = 0 ; V_36 < V_55 ; V_36 ++ ) {
if ( V_57 <= V_3 -> V_21 [ V_36 ] ) {
V_54 = F_53 ( V_3 -> V_19 , V_36 ) ;
V_56 = V_54 -> V_29 ;
break;
}
}
F_7 ( V_56 ) ;
if ( F_28 ( V_56 -> V_7 , V_56 -> V_8 ,
V_57 - V_3 -> V_20 [ V_36 ] ,
V_58 , & V_60 , & V_61 , NULL ) ) {
F_7 ( ! V_1 -> V_10 ) ;
return F_54 ( V_56 , V_60 , V_61 , NULL ) ;
}
else {
V_1 -> V_10 = F_55 ( V_1 , 0 , - 1 ) ;
return V_1 -> V_10 + V_57 ;
}
F_2 () ;
}
static const T_7 *
F_54 ( T_1 * V_1 , const T_8 V_17 , const T_8 V_7 , int * V_47 )
{
T_5 V_57 , V_58 ;
if ( ! F_28 ( V_1 -> V_7 , V_1 -> V_8 , V_17 , V_7 ,
& V_57 , & V_58 , V_47 ) ) {
return NULL ;
}
if ( V_1 -> V_10 ) {
return V_1 -> V_10 + V_57 ;
}
else {
switch( V_1 -> type ) {
case V_13 :
F_2 () ;
case V_14 :
return F_54 ( V_1 -> V_15 . V_16 . V_1 ,
V_57 - V_1 -> V_15 . V_16 . V_17 ,
V_58 , NULL ) ;
case V_18 :
return F_52 ( V_1 , V_57 , V_58 ) ;
}
}
F_2 () ;
return NULL ;
}
static const T_7 *
F_56 ( T_1 * V_1 , const T_8 V_17 , const T_8 V_7 )
{
int V_47 = 0 ;
const T_7 * V_62 ;
V_62 = F_54 ( V_1 , V_17 , V_7 , & V_47 ) ;
if ( V_62 == NULL ) {
F_7 ( V_47 > 0 ) ;
F_30 ( V_47 ) ;
}
return V_62 ;
}
static const T_7 *
F_57 ( T_1 * V_1 , const T_8 V_17 , const T_5 V_7 )
{
T_5 V_49 ;
T_5 V_63 ;
F_7 ( V_1 && V_1 -> V_6 ) ;
F_7 ( V_7 <= 8 ) ;
if ( V_17 < 0 || ! V_1 -> V_10 ) {
return F_56 ( V_1 , V_17 , V_7 ) ;
}
V_63 = V_17 ;
V_49 = V_63 + V_7 ;
if ( V_49 <= V_1 -> V_7 ) {
return V_1 -> V_10 + V_63 ;
}
if ( V_49 > V_1 -> V_8 ) {
F_30 ( V_30 ) ;
}
F_30 ( V_48 ) ;
return NULL ;
}
static const T_7 *
F_58 ( const T_7 * V_64 , T_13 V_65 , const T_7 * V_66 , T_14 * V_67 )
{
T_15 V_68 [ 256 ] = { 0 } ;
const T_7 * V_69 ;
while ( * V_66 )
V_68 [ * V_66 ++ ] = 1 ;
V_69 = V_64 + V_65 ;
while ( V_64 < V_69 ) {
if ( V_68 [ * V_64 ] ) {
if ( V_67 )
* V_67 = * V_64 ;
return V_64 ;
}
V_64 ++ ;
}
return NULL ;
}
static void *
F_59 ( T_1 * V_1 , T_7 * V_70 , T_5 V_57 , T_13 V_58 )
{
T_5 V_36 , V_55 ;
T_4 * V_3 ;
T_1 * V_56 = NULL ;
T_5 V_60 , V_61 ;
T_11 V_71 ;
T_12 * V_54 ;
F_7 ( V_1 -> type == V_18 ) ;
V_3 = & V_1 -> V_15 . V_3 ;
V_55 = F_40 ( V_3 -> V_19 ) ;
for ( V_36 = 0 ; V_36 < V_55 ; V_36 ++ ) {
if ( V_57 <= V_3 -> V_21 [ V_36 ] ) {
V_54 = F_53 ( V_3 -> V_19 , V_36 ) ;
V_56 = V_54 -> V_29 ;
break;
}
}
F_7 ( V_56 ) ;
if ( F_28 ( V_56 -> V_7 , V_56 -> V_8 , V_57 - V_3 -> V_20 [ V_36 ] ,
( T_8 ) V_58 , & V_60 , & V_61 , NULL ) ) {
F_7 ( ! V_1 -> V_10 ) ;
return F_60 ( V_56 , V_70 , V_60 , V_61 ) ;
}
else {
V_71 = F_27 ( V_56 -> V_7 , V_56 -> V_8 , V_57 - V_3 -> V_20 [ V_36 ] , - 1 ,
& V_60 , & V_61 , NULL ) ;
F_7 ( V_71 ) ;
F_60 ( V_56 , V_70 , V_60 , V_61 ) ;
V_57 += V_61 ;
V_58 -= V_61 ;
if ( V_58 > 0 ) {
F_59 ( V_1 , V_70 + V_61 , V_57 , V_58 ) ;
}
return V_70 ;
}
F_2 () ;
}
void *
F_60 ( T_1 * V_1 , void * V_70 , const T_8 V_17 , T_13 V_7 )
{
T_5 V_57 , V_58 ;
F_7 ( V_1 && V_1 -> V_6 ) ;
F_7 ( V_7 <= 0x7FFFFFFF ) ;
F_29 ( V_1 -> V_7 , V_1 -> V_8 , V_17 , ( T_8 ) V_7 , & V_57 , & V_58 ) ;
if ( V_1 -> V_10 ) {
return memcpy ( V_70 , V_1 -> V_10 + V_57 , V_58 ) ;
}
switch( V_1 -> type ) {
case V_13 :
F_2 () ;
case V_14 :
return F_60 ( V_1 -> V_15 . V_16 . V_1 , V_70 ,
V_57 - V_1 -> V_15 . V_16 . V_17 ,
V_58 ) ;
case V_18 :
return F_59 ( V_1 , V_70 , V_17 , V_7 ) ;
}
F_2 () ;
return NULL ;
}
void *
F_55 ( T_1 * V_1 , const T_8 V_17 , T_13 V_7 )
{
T_5 V_57 , V_58 ;
void * V_72 ;
F_7 ( V_1 && V_1 -> V_6 ) ;
F_29 ( V_1 -> V_7 , V_1 -> V_8 , V_17 , ( T_8 ) V_7 , & V_57 , & V_58 ) ;
V_72 = F_61 ( V_58 ) ;
return F_60 ( V_1 , V_72 , V_57 , V_58 ) ;
}
void *
F_62 ( T_1 * V_1 , const T_8 V_17 , T_13 V_7 )
{
T_5 V_57 , V_58 ;
void * V_72 ;
F_7 ( V_1 && V_1 -> V_6 ) ;
F_29 ( V_1 -> V_7 , V_1 -> V_8 , V_17 , ( T_8 ) V_7 , & V_57 , & V_58 ) ;
V_72 = F_63 ( V_58 ) ;
return F_60 ( V_1 , V_72 , V_57 , V_58 ) ;
}
const T_7 *
F_26 ( T_1 * V_1 , const T_8 V_17 , const T_8 V_7 )
{
return F_56 ( V_1 , V_17 , V_7 ) ;
}
T_7
F_64 ( T_1 * V_1 , const T_8 V_17 )
{
const T_7 * V_73 ;
V_73 = F_57 ( V_1 , V_17 , sizeof( T_7 ) ) ;
return * V_73 ;
}
T_16
F_65 ( T_1 * V_1 , const T_8 V_17 )
{
const T_7 * V_73 ;
V_73 = F_57 ( V_1 , V_17 , sizeof( T_16 ) ) ;
return F_66 ( V_73 ) ;
}
T_9
F_67 ( T_1 * V_1 , const T_8 V_17 )
{
const T_7 * V_73 ;
V_73 = F_57 ( V_1 , V_17 , 3 ) ;
return F_68 ( V_73 ) ;
}
T_9
F_69 ( T_1 * V_1 , const T_8 V_17 )
{
const T_7 * V_73 ;
V_73 = F_57 ( V_1 , V_17 , sizeof( T_9 ) ) ;
return F_70 ( V_73 ) ;
}
T_17
F_71 ( T_1 * V_1 , const T_8 V_17 )
{
const T_7 * V_73 ;
V_73 = F_57 ( V_1 , V_17 , 5 ) ;
return F_72 ( V_73 ) ;
}
T_17
F_73 ( T_1 * V_1 , const T_8 V_17 )
{
const T_7 * V_73 ;
V_73 = F_57 ( V_1 , V_17 , 6 ) ;
return F_74 ( V_73 ) ;
}
T_17
F_75 ( T_1 * V_1 , const T_8 V_17 )
{
const T_7 * V_73 ;
V_73 = F_57 ( V_1 , V_17 , 7 ) ;
return F_76 ( V_73 ) ;
}
T_17
F_77 ( T_1 * V_1 , const T_8 V_17 )
{
const T_7 * V_73 ;
V_73 = F_57 ( V_1 , V_17 , sizeof( T_17 ) ) ;
return F_78 ( V_73 ) ;
}
static int
F_79 ( const T_9 V_74 )
{
return ( ( V_74 & ~ V_75 ) == 0 ) ;
}
static T_18
F_80 ( const T_9 V_74 )
{
long V_76 ;
long V_77 ;
long V_78 ;
V_76 = V_74 & V_75 ;
V_77 = V_74 & V_79 ;
V_78 = V_74 & V_80 ;
if ( F_79 ( V_74 ) ) {
return 0.0 ;
}
#if 0
if (IEEE_SP_INFINITY == exponent) {
return (sign? MINUS_INFINITY: PLUS_INFINITY);
}
#endif
V_77 = ( ( V_77 >> V_81 ) - V_82 ) -
V_81 ;
V_78 |= V_83 ;
if ( V_76 )
return - V_78 * pow ( 2 , V_77 ) ;
else
return V_78 * pow ( 2 , V_77 ) ;
}
static int
F_81 ( const T_17 V_74 )
{
return ( ( V_74 & ~ V_75 ) == 0 ) ;
}
static T_19
F_82 ( const T_17 V_74 )
{
T_20 V_76 ;
T_20 V_77 ;
T_20 V_78 ;
V_76 = V_74 & V_84 ;
V_77 = V_74 & V_85 ;
V_78 = V_74 & V_86 ;
if ( F_81 ( V_74 ) ) {
return 0.0 ;
}
#if 0
if (IEEE_DP_INFINITY == exponent) {
return (sign? MINUS_INFINITY: PLUS_INFINITY);
}
#endif
V_77 = ( ( V_77 >> V_87 ) - V_88 ) -
V_87 ;
V_78 |= V_89 ;
if ( V_76 )
return - V_78 * pow ( 2 , V_77 ) ;
else
return V_78 * pow ( 2 , V_77 ) ;
}
T_18
F_83 ( T_1 * V_1 , const int V_17 )
{
#if F_84 ( V_90 )
return F_80 ( F_69 ( V_1 , V_17 ) ) ;
#else
union {
T_18 V_91 ;
T_9 V_74 ;
} V_92 ;
V_92 . V_74 = F_69 ( V_1 , V_17 ) ;
return V_92 . V_91 ;
#endif
}
T_19
F_85 ( T_1 * V_1 , const int V_17 )
{
#if F_84 ( V_90 )
union {
T_9 V_74 [ 2 ] ;
T_17 V_93 ;
} V_92 ;
#else
union {
T_19 V_94 ;
T_9 V_74 [ 2 ] ;
} V_92 ;
#endif
#ifdef F_86
V_92 . V_74 [ 0 ] = F_69 ( V_1 , V_17 ) ;
V_92 . V_74 [ 1 ] = F_69 ( V_1 , V_17 + 4 ) ;
#else
V_92 . V_74 [ 0 ] = F_69 ( V_1 , V_17 + 4 ) ;
V_92 . V_74 [ 1 ] = F_69 ( V_1 , V_17 ) ;
#endif
#if F_84 ( V_90 )
return F_82 ( V_92 . V_93 ) ;
#else
return V_92 . V_94 ;
#endif
}
T_16
F_87 ( T_1 * V_1 , const T_8 V_17 )
{
const T_7 * V_73 ;
V_73 = F_57 ( V_1 , V_17 , sizeof( T_16 ) ) ;
return F_88 ( V_73 ) ;
}
T_9
F_89 ( T_1 * V_1 , const T_8 V_17 )
{
const T_7 * V_73 ;
V_73 = F_57 ( V_1 , V_17 , 3 ) ;
return F_90 ( V_73 ) ;
}
T_9
F_91 ( T_1 * V_1 , const T_8 V_17 )
{
const T_7 * V_73 ;
V_73 = F_57 ( V_1 , V_17 , sizeof( T_9 ) ) ;
return F_92 ( V_73 ) ;
}
T_17
F_93 ( T_1 * V_1 , const T_8 V_17 )
{
const T_7 * V_73 ;
V_73 = F_57 ( V_1 , V_17 , 5 ) ;
return F_94 ( V_73 ) ;
}
T_17
F_95 ( T_1 * V_1 , const T_8 V_17 )
{
const T_7 * V_73 ;
V_73 = F_57 ( V_1 , V_17 , 6 ) ;
return F_96 ( V_73 ) ;
}
T_17
F_97 ( T_1 * V_1 , const T_8 V_17 )
{
const T_7 * V_73 ;
V_73 = F_57 ( V_1 , V_17 , 7 ) ;
return F_98 ( V_73 ) ;
}
T_17
F_99 ( T_1 * V_1 , const T_8 V_17 )
{
const T_7 * V_73 ;
V_73 = F_57 ( V_1 , V_17 , sizeof( T_17 ) ) ;
return F_100 ( V_73 ) ;
}
T_18
F_101 ( T_1 * V_1 , const int V_17 )
{
#if F_84 ( V_90 )
return F_80 ( F_91 ( V_1 , V_17 ) ) ;
#else
union {
T_18 V_91 ;
T_9 V_74 ;
} V_92 ;
V_92 . V_74 = F_91 ( V_1 , V_17 ) ;
return V_92 . V_91 ;
#endif
}
T_19
F_102 ( T_1 * V_1 , const int V_17 )
{
#if F_84 ( V_90 )
union {
T_9 V_74 [ 2 ] ;
T_17 V_93 ;
} V_92 ;
#else
union {
T_19 V_94 ;
T_9 V_74 [ 2 ] ;
} V_92 ;
#endif
#ifdef F_86
V_92 . V_74 [ 0 ] = F_91 ( V_1 , V_17 + 4 ) ;
V_92 . V_74 [ 1 ] = F_91 ( V_1 , V_17 ) ;
#else
V_92 . V_74 [ 0 ] = F_91 ( V_1 , V_17 ) ;
V_92 . V_74 [ 1 ] = F_91 ( V_1 , V_17 + 4 ) ;
#endif
#if F_84 ( V_90 )
return F_82 ( V_92 . V_93 ) ;
#else
return V_92 . V_94 ;
#endif
}
T_9
F_103 ( T_1 * V_1 , const T_8 V_17 )
{
const T_7 * V_73 ;
T_9 V_95 ;
V_73 = F_57 ( V_1 , V_17 , sizeof( T_9 ) ) ;
memcpy ( & V_95 , V_73 , sizeof V_95 ) ;
return V_95 ;
}
void
F_104 ( T_1 * V_1 , const T_8 V_17 , struct V_96 * V_95 )
{
const T_7 * V_73 ;
V_73 = F_56 ( V_1 , V_17 , sizeof( * V_95 ) ) ;
memcpy ( V_95 , V_73 , sizeof *V_95 ) ;
}
void
F_105 ( T_1 * V_1 , const T_8 V_17 , T_21 * V_97 )
{
F_56 ( V_1 , V_17 , sizeof( * V_97 ) ) ;
V_97 -> V_98 = F_69 ( V_1 , V_17 ) ;
V_97 -> V_99 = F_65 ( V_1 , V_17 + 4 ) ;
V_97 -> V_100 = F_65 ( V_1 , V_17 + 6 ) ;
F_60 ( V_1 , V_97 -> V_101 , V_17 + 8 , sizeof V_97 -> V_101 ) ;
}
void
F_106 ( T_1 * V_1 , const T_8 V_17 , T_21 * V_97 )
{
F_56 ( V_1 , V_17 , sizeof( * V_97 ) ) ;
V_97 -> V_98 = F_91 ( V_1 , V_17 ) ;
V_97 -> V_99 = F_87 ( V_1 , V_17 + 4 ) ;
V_97 -> V_100 = F_87 ( V_1 , V_17 + 6 ) ;
F_60 ( V_1 , V_97 -> V_101 , V_17 + 8 , sizeof V_97 -> V_101 ) ;
}
void
F_107 ( T_1 * V_1 , const T_8 V_17 , T_21 * V_97 , const T_5 V_102 )
{
if ( V_102 ) {
F_106 ( V_1 , V_17 , V_97 ) ;
} else {
F_105 ( V_1 , V_17 , V_97 ) ;
}
}
T_7
F_108 ( T_1 * V_1 , T_5 V_31 , const T_8 V_32 )
{
return ( T_7 ) F_109 ( V_1 , V_31 , V_32 ) ;
}
void
F_110 ( T_1 * V_1 , T_5 V_31 , T_8 V_32 , T_7 * V_40 , T_11 V_103 )
{
T_7 V_104 , V_105 ;
T_8 V_17 = V_31 >> 3 ;
V_31 = V_31 & 0x7 ;
V_104 = ( V_103 ) ? 0xff : V_106 [ V_31 ] ;
V_105 = ( V_103 ) ? V_31 : ( 8 - V_31 ) ;
if ( F_111 ( V_31 != 0 ) ) {
T_16 V_107 = ( T_16 ) F_64 ( V_1 , V_17 ) ;
while ( V_32 >= 8 ) {
V_17 ++ ;
V_107 = ( ( V_107 & V_104 ) << 8 ) | F_64 ( V_1 , V_17 ) ;
if ( V_103 )
* V_40 ++ = ( T_7 ) ( F_112 ( V_107 ) >> V_105 ) ;
else
* V_40 ++ = ( T_7 ) ( V_107 >> V_105 ) ;
V_32 -= 8 ;
}
if ( V_32 > 0 ) {
T_7 V_108 = V_31 + V_32 ;
if ( V_108 > 8 ) {
V_17 ++ ;
V_107 = ( ( V_107 & V_104 ) << 8 ) | F_64 ( V_1 , V_17 ) ;
}
if ( V_103 ) {
if ( V_108 > 8 )
V_107 = ( F_112 ( V_107 ) >> V_31 ) & ( V_109 [ V_32 ] ) ;
else
V_107 = ( V_107 >> V_31 ) & ( V_109 [ V_32 ] ) ;
} else {
if ( V_108 > 8 )
V_107 = V_107 >> ( 16 - V_108 ) ;
else
V_107 = ( V_107 & V_104 ) >> ( 8 - V_108 ) ;
}
* V_40 = ( T_7 ) V_107 ;
}
} else {
while ( V_32 >= 8 ) {
* V_40 ++ = F_64 ( V_1 , V_17 ) ;
V_17 ++ ;
V_32 -= 8 ;
}
if ( V_32 > 0 ) {
if ( V_103 )
* V_40 = F_64 ( V_1 , V_17 ) & V_109 [ V_32 ] ;
else
* V_40 = F_64 ( V_1 , V_17 ) >> ( 8 - V_32 ) ;
}
}
}
T_7 *
F_113 ( T_1 * V_1 , T_5 V_31 , T_8 V_32 , T_11 V_103 )
{
T_8 V_110 ;
T_7 * V_40 ;
if ( V_32 < 0 ) {
F_2 () ;
}
V_110 = ( V_32 >> 3 ) + ( ( V_32 & 0x7 ) != 0 ) ;
V_40 = F_63 ( V_110 ) ;
F_110 ( V_1 , V_31 , V_32 , V_40 , V_103 ) ;
return V_40 ;
}
T_16
F_114 ( T_1 * V_1 , T_5 V_31 , const T_8 V_32 , const T_5 T_22 V_111 )
{
return ( T_16 ) F_109 ( V_1 , V_31 , V_32 ) ;
}
T_9
F_115 ( T_1 * V_1 , T_5 V_31 , const T_8 V_32 , const T_5 T_22 V_111 )
{
return ( T_9 ) F_109 ( V_1 , V_31 , V_32 ) ;
}
T_17
F_116 ( T_1 * V_1 , T_5 V_31 , const T_8 V_32 , const T_5 T_22 V_111 )
{
return F_109 ( V_1 , V_31 , V_32 ) ;
}
static T_17
F_109 ( T_1 * V_1 , T_5 V_31 , const T_8 V_112 )
{
T_17 V_107 ;
T_5 V_113 = V_31 >> 3 ;
T_7 V_114 = 8 - ( V_31 % 8 ) ;
if( V_114 > V_112 )
{
T_7 V_115 = V_114 - V_112 ;
V_107 = ( F_64 ( V_1 , V_113 ) >> V_115 ) & V_109 [ V_112 % 8 ] ;
}
else
{
T_7 V_116 = V_112 ;
V_107 = 0 ;
V_114 %= 8 ;
if( V_114 != 0 )
{
V_107 = F_64 ( V_1 , V_113 ) & V_109 [ V_114 ] ;
V_116 -= V_114 ;
V_113 ++ ;
}
while ( V_116 > 7 )
{
switch ( V_116 >> 4 )
{
case 0 :
V_107 <<= 8 ;
V_107 += F_64 ( V_1 , V_113 ) ;
V_116 -= 8 ;
V_113 ++ ;
break;
case 1 :
V_107 <<= 16 ;
V_107 += F_65 ( V_1 , V_113 ) ;
V_116 -= 16 ;
V_113 += 2 ;
break;
case 2 :
case 3 :
V_107 <<= 32 ;
V_107 += F_69 ( V_1 , V_113 ) ;
V_116 -= 32 ;
V_113 += 4 ;
break;
default:
V_107 = F_77 ( V_1 , V_113 ) ;
V_116 -= 64 ;
V_113 += 8 ;
break;
}
}
if( V_116 )
{
V_107 <<= V_116 ;
V_107 += ( F_64 ( V_1 , V_113 ) >> ( 8 - V_116 ) ) ;
}
}
return V_107 ;
}
T_9
F_117 ( T_1 * V_1 , const T_5 V_31 , const T_8 V_32 , const T_5 T_22 V_111 )
{
return ( T_9 ) F_109 ( V_1 , V_31 , V_32 ) ;
}
T_8
F_118 ( T_1 * V_1 , const T_8 V_17 , const T_8 V_117 , const T_7 V_118 )
{
const T_7 * V_119 ;
T_5 V_57 , V_120 ;
T_5 V_121 ;
T_5 V_122 ;
F_7 ( V_1 && V_1 -> V_6 ) ;
F_29 ( V_1 -> V_7 , V_1 -> V_8 , V_17 , 0 , & V_57 , & V_120 ) ;
V_121 = F_23 ( V_1 , V_57 ) ;
if ( V_117 == - 1 ) {
V_122 = V_121 ;
}
else if ( V_121 < ( T_5 ) V_117 ) {
V_122 = V_121 ;
}
else {
V_122 = V_117 ;
}
if ( V_1 -> V_10 ) {
V_119 = memchr ( V_1 -> V_10 + V_57 , V_118 , V_122 ) ;
if ( V_119 == NULL ) {
return - 1 ;
}
else {
return ( T_8 ) ( V_119 - V_1 -> V_10 ) ;
}
}
switch( V_1 -> type ) {
case V_13 :
F_2 () ;
case V_14 :
return F_118 ( V_1 -> V_15 . V_16 . V_1 ,
V_57 - V_1 -> V_15 . V_16 . V_17 ,
V_122 , V_118 ) ;
case V_18 :
F_2 () ;
}
F_2 () ;
return - 1 ;
}
T_8
F_119 ( T_1 * V_1 , const T_8 V_17 , const T_8 V_117 , const T_7 * V_66 , T_14 * V_67 )
{
const T_7 * V_119 ;
T_5 V_57 , V_120 ;
T_5 V_121 ;
T_5 V_122 ;
F_7 ( V_1 && V_1 -> V_6 ) ;
F_29 ( V_1 -> V_7 , V_1 -> V_8 , V_17 , 0 , & V_57 , & V_120 ) ;
V_121 = F_23 ( V_1 , V_57 ) ;
if ( V_117 == - 1 ) {
V_122 = V_121 ;
}
else if ( V_121 < ( T_5 ) V_117 ) {
V_122 = V_121 ;
}
else {
V_122 = V_117 ;
}
if ( V_1 -> V_10 ) {
V_119 = F_58 ( V_1 -> V_10 + V_57 , V_122 , V_66 , V_67 ) ;
if ( V_119 == NULL ) {
return - 1 ;
}
else {
return ( T_8 ) ( V_119 - V_1 -> V_10 ) ;
}
}
switch( V_1 -> type ) {
case V_13 :
F_2 () ;
case V_14 :
return F_119 ( V_1 -> V_15 . V_16 . V_1 ,
V_57 - V_1 -> V_15 . V_16 . V_17 ,
V_122 , V_66 , V_67 ) ;
case V_18 :
F_2 () ;
}
F_2 () ;
return - 1 ;
}
T_5
F_120 ( T_1 * V_1 , const T_8 V_17 )
{
T_5 V_57 , V_120 ;
T_8 V_123 ;
F_7 ( V_1 && V_1 -> V_6 ) ;
F_29 ( V_1 -> V_7 , V_1 -> V_8 , V_17 , 0 , & V_57 , & V_120 ) ;
V_123 = F_118 ( V_1 , V_57 , - 1 , 0 ) ;
if ( V_123 == - 1 ) {
if ( F_42 ( V_1 ) < F_47 ( V_1 ) ) {
F_30 ( V_48 ) ;
} else {
F_30 ( V_30 ) ;
}
}
return ( V_123 - V_57 ) + 1 ;
}
T_5
F_121 ( T_1 * V_1 , const T_8 V_17 )
{
T_5 V_36 = 0 ;
T_23 V_124 ;
F_7 ( V_1 && V_1 -> V_6 ) ;
do {
V_124 = F_65 ( V_1 , V_17 + V_36 ) ;
V_36 += 2 ;
} while( V_124 != 0 );
return V_36 ;
}
T_8
F_122 ( T_1 * V_1 , const T_8 V_17 , const T_5 V_117 )
{
T_8 V_125 ;
T_5 V_57 , V_120 ;
F_7 ( V_1 && V_1 -> V_6 ) ;
F_29 ( V_1 -> V_7 , V_1 -> V_8 , V_17 , 0 , & V_57 , & V_120 ) ;
V_125 = F_118 ( V_1 , V_57 , V_117 , 0 ) ;
if ( V_125 == - 1 ) {
return - 1 ;
}
else {
return V_125 - V_57 ;
}
}
T_8
F_123 ( T_1 * V_1 , const T_8 V_17 , const T_15 * V_126 , const T_13 V_127 )
{
const T_7 * V_73 ;
V_73 = F_54 ( V_1 , V_17 , ( T_8 ) V_127 , NULL ) ;
if ( V_73 ) {
int V_128 = strncmp ( ( const char * ) V_73 , V_126 , V_127 ) ;
return ( V_128 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_8
F_124 ( T_1 * V_1 , const T_8 V_17 , const T_15 * V_126 , const T_13 V_127 )
{
const T_7 * V_73 ;
V_73 = F_54 ( V_1 , V_17 , ( T_8 ) V_127 , NULL ) ;
if ( V_73 ) {
int V_128 = F_125 ( ( const char * ) V_73 , V_126 , V_127 ) ;
return ( V_128 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_8
F_126 ( T_1 * V_1 , const T_8 V_17 , const T_7 * V_126 , T_13 V_127 )
{
const T_7 * V_73 ;
V_73 = F_54 ( V_1 , V_17 , ( T_8 ) V_127 , NULL ) ;
if ( V_73 ) {
int V_128 = memcmp ( V_73 , V_126 , V_127 ) ;
return ( V_128 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
char *
F_127 ( T_1 * V_1 , int V_17 , const int V_129 , const T_11 V_130 )
{
char * V_131 ;
int V_36 ;
T_16 V_132 ;
F_45 ( V_1 , V_17 , 2 * V_129 ) ;
V_131 = F_61 ( V_129 + 1 ) ;
for ( V_36 = 0 ; V_36 < V_129 ; V_36 ++ ) {
V_132 = V_130 ? F_87 ( V_1 , V_17 )
: F_65 ( V_1 , V_17 ) ;
V_131 [ V_36 ] = V_132 < 256 ? V_132 : '.' ;
V_17 += 2 ;
}
V_131 [ V_129 ] = 0 ;
return V_131 ;
}
char *
F_128 ( T_1 * V_1 , int V_17 , const int V_129 , const T_11 V_130 )
{
char * V_131 ;
int V_36 ;
T_16 V_132 ;
F_45 ( V_1 , V_17 , 2 * V_129 ) ;
V_131 = F_63 ( V_129 + 1 ) ;
for ( V_36 = 0 ; V_36 < V_129 ; V_36 ++ ) {
V_132 = V_130 ? F_87 ( V_1 , V_17 )
: F_65 ( V_1 , V_17 ) ;
V_131 [ V_36 ] = V_132 < 256 ? V_132 : '.' ;
V_17 += 2 ;
}
V_131 [ V_129 ] = 0 ;
return V_131 ;
}
T_15 *
F_129 ( T_1 * V_1 , const T_8 V_17 , const T_8 V_127 )
{
const T_7 * V_73 ;
T_8 V_129 = V_127 ;
if ( ( V_73 = F_56 ( V_1 , V_17 , V_127 ) ) == NULL ) {
V_129 = F_23 ( V_1 , V_17 ) ;
V_73 = F_56 ( V_1 , V_17 , V_129 ) ;
}
return F_130 ( V_73 , V_129 ) ;
}
T_15 *
F_131 ( T_1 * V_1 , const T_8 V_17 , const T_8 V_127 )
{
const T_7 * V_73 ;
T_8 V_129 = V_127 ;
if ( ( V_73 = F_56 ( V_1 , V_17 , V_127 ) ) == NULL ) {
V_129 = F_23 ( V_1 , V_17 ) ;
V_73 = F_56 ( V_1 , V_17 , V_129 ) ;
}
return F_132 ( V_73 , V_129 ) ;
}
T_15 *
F_133 ( T_1 * V_1 , const T_8 V_17 , const T_8 V_127 )
{
const T_7 * V_73 , * V_62 ;
T_8 V_129 = V_127 ;
T_8 V_133 ;
if ( ( V_73 = F_56 ( V_1 , V_17 , V_127 ) ) == NULL ) {
V_129 = F_23 ( V_1 , V_17 ) ;
V_73 = F_56 ( V_1 , V_17 , V_129 ) ;
}
for ( V_62 = V_73 , V_133 = 0 ; V_133 < V_129 && * V_62 != '\0' ; V_62 ++ , V_133 ++ )
;
return F_130 ( V_73 , V_133 ) ;
}
T_15 *
F_134 ( T_1 * V_1 , const T_8 V_17 , const T_8 V_127 )
{
const T_7 * V_73 , * V_62 ;
T_8 V_129 = V_127 ;
T_8 V_133 ;
if ( ( V_73 = F_56 ( V_1 , V_17 , V_127 ) ) == NULL ) {
V_129 = F_23 ( V_1 , V_17 ) ;
V_73 = F_56 ( V_1 , V_17 , V_129 ) ;
}
for ( V_62 = V_73 , V_133 = 0 ; V_133 < V_129 && * V_62 != '\0' ; V_62 ++ , V_133 ++ )
;
return F_132 ( V_73 , V_133 ) ;
}
T_7 *
F_135 ( T_1 * V_1 , const T_8 V_17 , const T_8 V_7 )
{
const T_7 * V_73 ;
T_7 * V_134 = NULL ;
F_45 ( V_1 , V_17 , V_7 ) ;
V_73 = F_56 ( V_1 , V_17 , V_7 ) ;
V_134 = F_61 ( V_7 + 1 ) ;
if ( V_7 != 0 ) {
memcpy ( V_134 , V_73 , V_7 ) ;
}
V_134 [ V_7 ] = '\0' ;
return V_134 ;
}
T_15 *
F_136 ( T_1 * V_1 , const T_8 V_17 , T_8 V_7 , const T_5 T_22 )
{
T_15 * V_135 = NULL ;
T_23 V_124 ;
T_8 V_36 ;
T_8 V_136 ;
T_24 * V_134 = NULL ;
V_134 = F_137 ( NULL ) ;
for( V_36 = 0 ; V_36 < V_7 ; V_36 += 2 ) {
if ( T_22 == V_137 )
V_124 = F_65 ( V_1 , V_17 + V_36 ) ;
else
V_124 = F_87 ( V_1 , V_17 + V_36 ) ;
V_136 = F_138 ( V_124 , NULL ) ;
V_135 = F_61 ( V_136 + 1 ) ;
F_138 ( V_124 , V_135 ) ;
V_135 [ V_136 ] = '\0' ;
F_139 ( V_134 , V_135 ) ;
F_9 ( V_135 ) ;
}
return F_140 ( V_134 , FALSE ) ;
}
T_7 *
F_141 ( T_1 * V_1 , const T_8 V_17 ,
const T_8 V_7 , const T_5 T_22 )
{
const T_7 * V_73 ;
T_7 * V_134 ;
switch ( T_22 & V_138 ) {
case V_139 :
default:
V_134 = F_142 ( V_1 , V_17 , V_7 ) ;
break;
case V_140 :
V_134 = F_142 ( V_1 , V_17 , V_7 ) ;
break;
case V_141 :
V_134 = F_143 ( V_1 , V_17 , V_7 ,
T_22 & V_142 ) ;
break;
case V_143 :
V_134 = F_143 ( V_1 , V_17 , V_7 ,
T_22 & V_142 ) ;
break;
case V_144 :
F_45 ( V_1 , V_17 , V_7 ) ;
V_134 = F_63 ( V_7 + 1 ) ;
if ( V_7 != 0 ) {
V_73 = F_56 ( V_1 , V_17 , V_7 ) ;
memcpy ( V_134 , V_73 , V_7 ) ;
F_144 ( V_134 , V_7 ) ;
}
V_134 [ V_7 ] = '\0' ;
break;
}
return V_134 ;
}
T_7 *
F_142 ( T_1 * V_1 , const T_8 V_17 , const T_8 V_7 )
{
T_7 * V_134 ;
F_45 ( V_1 , V_17 , V_7 ) ;
V_134 = F_63 ( V_7 + 1 ) ;
F_60 ( V_1 , V_134 , V_17 , V_7 ) ;
V_134 [ V_7 ] = '\0' ;
return V_134 ;
}
T_15 *
F_143 ( T_1 * V_1 , const T_8 V_17 , T_8 V_7 , const T_5 T_22 )
{
T_15 * V_135 = NULL ;
T_23 V_124 ;
T_8 V_36 ;
T_8 V_136 ;
T_25 * V_134 = NULL ;
V_134 = F_145 ( NULL ) ;
for( V_36 = 0 ; V_36 < V_7 ; V_36 += 2 ) {
if ( T_22 == V_137 )
V_124 = F_65 ( V_1 , V_17 + V_36 ) ;
else
V_124 = F_87 ( V_1 , V_17 + V_36 ) ;
V_136 = F_138 ( V_124 , NULL ) ;
V_135 = F_61 ( V_136 + 1 ) ;
F_138 ( V_124 , V_135 ) ;
V_135 [ V_136 ] = '\0' ;
F_146 ( V_134 , V_135 ) ;
F_9 ( V_135 ) ;
}
return V_134 -> V_126 ;
}
T_7 *
F_147 ( T_1 * V_1 , const T_8 V_17 , const T_8 V_7 )
{
const T_7 * V_73 ;
T_7 * V_134 = NULL ;
F_45 ( V_1 , V_17 , V_7 ) ;
V_73 = F_56 ( V_1 , V_17 , V_7 ) ;
V_134 = F_148 ( V_7 + 1 ) ;
if ( V_7 != 0 ) {
memcpy ( V_134 , V_73 , V_7 ) ;
}
V_134 [ V_7 ] = '\0' ;
return V_134 ;
}
T_7 *
F_149 ( T_1 * V_1 , const T_8 V_17 , T_8 * V_145 , const T_5 T_22 )
{
T_5 V_127 ;
T_7 * V_146 ;
V_127 = F_120 ( V_1 , V_17 ) ;
V_146 = F_61 ( V_127 ) ;
F_60 ( V_1 , V_146 , V_17 , V_127 ) ;
if ( ( T_22 & V_138 ) == V_144 )
F_144 ( V_146 , V_127 ) ;
if ( V_145 )
* V_145 = V_127 ;
return V_146 ;
}
T_7 *
F_150 ( T_1 * V_1 , const T_8 V_17 , T_8 * V_145 )
{
return F_149 ( V_1 , V_17 , V_145 , V_140 | V_147 ) ;
}
const T_7 *
F_151 ( T_1 * V_1 , const T_8 V_17 , T_8 * V_145 )
{
T_5 V_127 ;
const T_7 * V_146 ;
V_127 = F_120 ( V_1 , V_17 ) ;
V_146 = F_56 ( V_1 , V_17 , V_127 ) ;
if ( V_145 )
* V_145 = V_127 ;
return V_146 ;
}
T_7 *
F_152 ( T_1 * V_1 , const T_8 V_17 , T_8 * V_145 , const T_5 T_22 )
{
T_5 V_127 ;
T_7 * V_146 ;
switch ( T_22 & V_138 ) {
case V_139 :
default:
V_146 = F_153 ( V_1 , V_17 , V_145 ) ;
break;
case V_140 :
V_146 = F_153 ( V_1 , V_17 , V_145 ) ;
break;
case V_141 :
V_146 = F_154 ( V_1 , V_17 , V_145 ,
T_22 & V_142 ) ;
break;
case V_143 :
V_146 = F_154 ( V_1 , V_17 , V_145 ,
T_22 & V_142 ) ;
break;
case V_144 :
V_127 = F_120 ( V_1 , V_17 ) ;
V_146 = F_63 ( V_127 ) ;
F_60 ( V_1 , V_146 , V_17 , V_127 ) ;
F_144 ( V_146 , V_127 ) ;
if ( V_145 )
* V_145 = V_127 ;
break;
}
return V_146 ;
}
T_7 *
F_153 ( T_1 * V_1 , const T_8 V_17 , T_8 * V_145 )
{
T_5 V_127 ;
T_7 * V_146 ;
V_127 = F_120 ( V_1 , V_17 ) ;
V_146 = F_63 ( V_127 ) ;
F_60 ( V_1 , V_146 , V_17 , V_127 ) ;
if ( V_145 )
* V_145 = V_127 ;
return V_146 ;
}
T_15 *
F_154 ( T_1 * V_1 , const T_8 V_17 , T_8 * V_145 , const T_5 T_22 )
{
T_15 * V_135 = NULL ;
T_23 V_124 ;
T_8 V_127 ;
T_8 V_36 ;
T_8 V_136 ;
T_25 * V_134 = NULL ;
V_134 = F_145 ( NULL ) ;
V_127 = F_121 ( V_1 , V_17 ) ;
for( V_36 = 0 ; V_36 < V_127 ; V_36 += 2 ) {
if ( T_22 == V_137 )
V_124 = F_65 ( V_1 , V_17 + V_36 ) ;
else
V_124 = F_87 ( V_1 , V_17 + V_36 ) ;
V_136 = F_138 ( V_124 , NULL ) ;
V_135 = F_61 ( V_136 + 1 ) ;
F_138 ( V_124 , V_135 ) ;
V_135 [ V_136 ] = '\0' ;
F_146 ( V_134 , V_135 ) ;
F_9 ( V_135 ) ;
}
if ( V_145 )
* V_145 = V_36 ;
return V_134 -> V_126 ;
}
T_7 *
F_155 ( T_1 * V_1 , const T_8 V_17 , T_8 * V_145 )
{
T_5 V_127 ;
T_7 * V_146 ;
V_127 = F_120 ( V_1 , V_17 ) ;
V_146 = F_148 ( V_127 ) ;
F_60 ( V_1 , V_146 , V_17 , V_127 ) ;
if ( V_145 )
* V_145 = V_127 ;
return V_146 ;
}
static T_8
F_156 ( T_1 * V_1 , const T_8 V_17 , const T_5 V_148 , T_7 * V_131 , T_8 * V_149 )
{
T_8 V_133 ;
T_5 V_57 , V_120 ;
T_8 V_122 , V_129 ;
T_11 V_150 = FALSE ;
F_29 ( V_1 -> V_7 , V_1 -> V_8 , V_17 , 0 , & V_57 , & V_120 ) ;
F_7 ( V_148 != 0 ) ;
if ( V_148 == 1 ) {
V_131 [ 0 ] = 0 ;
* V_149 = 1 ;
return 0 ;
}
V_129 = F_23 ( V_1 , V_57 ) ;
if ( V_129 == 0 ) {
F_30 ( V_30 ) ;
}
F_7 ( V_129 != - 1 ) ;
F_7 ( V_148 <= V_151 ) ;
if ( ( T_5 ) V_129 < V_148 ) {
V_122 = V_129 ;
V_150 = TRUE ;
}
else {
V_122 = V_148 ;
}
V_133 = F_122 ( V_1 , V_57 , V_122 - 1 ) ;
if ( V_133 == - 1 ) {
F_60 ( V_1 , V_131 , V_57 , V_122 ) ;
if ( V_150 ) {
V_131 [ V_122 ] = 0 ;
* V_149 = V_122 + 1 ;
}
else {
* V_149 = V_122 ;
}
return - 1 ;
}
F_60 ( V_1 , V_131 , V_57 , V_133 + 1 ) ;
* V_149 = V_133 + 1 ;
return V_133 ;
}
T_8
F_157 ( T_1 * V_1 , const T_8 V_17 , const T_5 V_148 , T_7 * V_131 )
{
T_8 V_149 ;
F_7 ( V_1 && V_1 -> V_6 ) ;
return F_156 ( V_1 , V_17 , V_148 , V_131 , & V_149 ) ;
}
T_8
F_158 ( T_1 * V_1 , const T_8 V_17 , const T_5 V_148 , T_7 * V_131 )
{
T_8 V_129 , V_149 ;
F_7 ( V_1 && V_1 -> V_6 ) ;
V_129 = F_156 ( V_1 , V_17 , V_148 , V_131 , & V_149 ) ;
if ( V_129 == - 1 ) {
V_131 [ V_148 - 1 ] = 0 ;
return V_149 - 1 ;
}
else {
return V_129 ;
}
}
T_8
F_159 ( T_1 * V_1 , const T_8 V_17 , int V_129 , T_8 * V_152 , const T_11 V_153 )
{
T_8 V_154 ;
T_8 V_155 ;
int V_156 ;
T_14 V_67 = 0 ;
if ( V_129 == - 1 )
V_129 = F_23 ( V_1 , V_17 ) ;
V_154 = V_17 + V_129 ;
V_155 = F_119 ( V_1 , V_17 , V_129 , L_3 , & V_67 ) ;
if ( V_155 == - 1 ) {
if ( V_153 ) {
return - 1 ;
} else {
V_156 = V_154 - V_17 ;
if ( V_152 )
* V_152 = V_154 ;
}
} else {
V_156 = V_155 - V_17 ;
if ( V_67 == '\r' ) {
if ( V_155 + 1 >= V_154 ) {
if ( V_153 ) {
return - 1 ;
}
} else {
if ( F_64 ( V_1 , V_155 + 1 ) == '\n' ) {
V_155 ++ ;
}
}
}
if ( V_152 )
* V_152 = V_155 + 1 ;
}
return V_156 ;
}
T_8
F_160 ( T_1 * V_1 , const T_8 V_17 , int V_129 , T_8 * V_152 )
{
T_8 V_157 , V_158 ;
T_11 V_159 ;
T_14 V_160 = 0 ;
T_8 V_154 ;
int V_156 ;
if ( V_129 == - 1 )
V_129 = F_23 ( V_1 , V_17 ) ;
V_154 = V_17 + V_129 ;
V_157 = V_17 ;
V_159 = FALSE ;
for (; ; ) {
if ( V_159 ) {
V_158 = F_118 ( V_1 , V_157 , V_129 ,
'"' ) ;
} else {
V_158 = F_119 ( V_1 , V_157 , V_129 , L_4 , & V_160 ) ;
}
if ( V_158 == - 1 ) {
V_156 = V_154 - V_17 ;
if ( V_152 )
* V_152 = V_154 ;
break;
}
if ( V_159 ) {
V_159 = FALSE ;
} else {
if ( V_160 == '"' ) {
V_159 = TRUE ;
} else {
V_156 = V_158 - V_17 ;
if ( V_160 == '\r' ) {
if ( V_158 + 1 < V_154 &&
F_64 ( V_1 , V_158 + 1 )
== '\n' ) {
V_158 ++ ;
}
}
if ( V_152 )
* V_152 = V_158 + 1 ;
break;
}
}
V_157 = V_158 + 1 ;
if ( V_157 >= V_154 ) {
V_156 = V_154 - V_17 ;
if ( V_152 )
* V_152 = V_154 ;
break;
}
}
return V_156 ;
}
T_8
F_161 ( T_1 * V_1 , const T_8 V_17 , const T_8 V_117 )
{
T_8 V_59 = V_17 ;
T_8 V_161 , V_162 ;
T_7 V_163 ;
V_162 = F_42 ( V_1 ) ;
V_161 = V_17 + V_117 ;
if ( V_161 >= V_162 )
{
V_161 = V_162 ;
}
for ( V_59 = V_17 ;
V_59 < V_161 &&
( ( V_163 = F_64 ( V_1 , V_59 ) ) == ' ' ||
V_163 == '\t' || V_163 == '\r' || V_163 == '\n' ) ;
V_59 ++ ) ;
return ( V_59 ) ;
}
T_8
F_162 ( T_1 * V_1 , const T_8 V_17 ) {
T_8 V_59 = V_17 ;
T_8 V_161 ;
T_7 V_163 ;
V_161 = 0 ;
for( V_59 = V_17 ; V_59 > V_161 &&
( ( V_163 = F_64 ( V_1 , V_59 ) ) == ' ' ||
V_163 == '\t' || V_163 == '\n' || V_163 == '\r' ) ; V_59 -- ) ;
V_59 ++ ;
return ( V_59 ) ;
}
T_15 *
F_163 ( T_1 * V_1 , const T_8 V_17 , const T_8 V_129 , const T_15 V_164 )
{
return F_164 ( F_56 ( V_1 , V_17 , V_129 ) , V_129 , V_164 ) ;
}
const T_15 *
F_165 ( T_1 * V_1 , const T_8 V_17 , const T_8 V_129 , T_26 * V_165 , T_11 V_166 )
{
int V_7 ;
T_7 V_167 ;
int V_36 = 0 ;
char * V_168 ;
T_8 V_169 = V_17 ;
if ( ! V_165 )
V_165 = & V_170 ;
if ( V_129 == - 1 ) {
V_7 = F_42 ( V_1 ) ;
if ( V_7 < V_17 ) {
return L_5 ;
}
} else {
V_7 = V_17 + V_129 ;
}
V_168 = F_63 ( ( V_7 - V_17 ) * 2 + 1 ) ;
while ( V_169 < V_7 ) {
V_167 = F_64 ( V_1 , V_169 ) ;
if ( ! V_166 ) {
V_168 [ V_36 ] = V_165 -> V_171 [ V_167 & 0x0f ] ;
V_36 ++ ;
}
V_166 = FALSE ;
V_167 = V_167 >> 4 ;
if ( V_167 == 0x0f )
break;
V_168 [ V_36 ] = V_165 -> V_171 [ V_167 & 0x0f ] ;
V_36 ++ ;
V_169 ++ ;
}
V_168 [ V_36 ] = '\0' ;
return V_168 ;
}
T_15 *
F_166 ( T_1 * V_1 , const T_8 V_17 , const T_8 V_129 )
{
return F_167 ( F_56 ( V_1 , V_17 , V_129 ) , V_129 ) ;
}
T_8
F_168 ( T_1 * V_172 , T_1 * V_173 , const T_8 V_174 )
{
T_5 V_175 , V_176 ;
const T_7 * V_177 ;
const T_7 * V_178 ;
const T_5 V_179 = V_173 -> V_7 ;
const T_7 * V_180 ;
F_7 ( V_172 && V_172 -> V_6 ) ;
if ( V_172 -> V_7 < 1 || V_173 -> V_7 < 1 ) {
return - 1 ;
}
V_177 = F_56 ( V_172 , 0 , - 1 ) ;
V_178 = F_56 ( V_173 , 0 , - 1 ) ;
F_29 ( V_172 -> V_7 , V_172 -> V_8 , V_174 , - 1 ,
& V_175 , & V_176 ) ;
V_180 = F_169 ( V_177 + V_175 , V_176 ,
V_178 , V_179 ) ;
if ( V_180 ) {
return ( T_8 ) ( V_180 - V_177 ) ;
}
return - 1 ;
}
T_1 *
F_170 ( T_1 * V_1 , const int V_17 , int V_181 )
{
T_8 V_182 = V_183 ;
T_5 V_184 = 0 ;
T_7 * V_185 = NULL ;
T_7 * V_186 = NULL ;
T_1 * V_187 = NULL ;
T_27 V_188 = NULL ;
T_28 * V_189 = NULL ;
T_5 V_190 = 0 ;
T_8 V_191 = V_192 ;
T_7 * V_5 = NULL ;
T_5 V_193 = V_194 ;
#ifdef F_171
T_5 V_195 = 0 ;
T_5 V_196 = F_23 ( V_1 , V_17 ) ;
#endif
if ( V_1 == NULL ) {
return NULL ;
}
V_185 = F_55 ( V_1 , V_17 , V_181 ) ;
if ( ! V_185 )
return NULL ;
V_193 = F_23 ( V_1 , V_17 ) * 2 ;
V_193 = F_172 ( V_193 , V_194 , V_197 ) ;
#ifdef F_171
printf ( L_6 , V_193 ) ;
#endif
V_5 = V_185 ;
V_188 = F_173 ( V_198 , 1 ) ;
V_188 -> V_199 = V_5 ;
V_188 -> V_200 = V_181 ;
V_189 = F_174 ( V_193 ) ;
V_188 -> V_201 = V_189 ;
V_188 -> V_202 = V_193 ;
V_182 = F_175 ( V_188 , V_191 ) ;
V_190 = 1 ;
if ( V_182 != V_183 ) {
F_176 ( V_188 ) ;
F_9 ( V_188 ) ;
F_9 ( V_185 ) ;
F_9 ( V_189 ) ;
return NULL ;
}
while ( 1 ) {
memset ( V_189 , '\0' , V_193 ) ;
V_188 -> V_201 = V_189 ;
V_188 -> V_202 = V_193 ;
V_182 = F_177 ( V_188 , V_203 ) ;
if ( V_182 == V_183 || V_182 == V_204 ) {
T_5 V_205 = V_193 - V_188 -> V_202 ;
#ifdef F_171
++ V_195 ;
#endif
if ( V_186 == NULL ) {
V_186 = ( V_205 || V_182 != V_204 ) ?
F_178 ( V_189 , V_205 ) :
F_179 ( L_5 ) ;
} else {
T_7 * V_206 = F_174 ( V_184 + V_205 ) ;
memcpy ( V_206 , V_186 , V_184 ) ;
memcpy ( V_206 + V_184 , V_189 , V_205 ) ;
F_9 ( V_186 ) ;
V_186 = V_206 ;
}
V_184 += V_205 ;
if ( V_182 == V_204 ) {
F_176 ( V_188 ) ;
F_9 ( V_188 ) ;
F_9 ( V_189 ) ;
break;
}
} else if ( V_182 == V_207 ) {
F_176 ( V_188 ) ;
F_9 ( V_188 ) ;
F_9 ( V_189 ) ;
if ( V_186 != NULL ) {
break;
} else {
F_9 ( V_185 ) ;
return NULL ;
}
} else if ( V_182 == V_208 && V_190 == 1
&& V_186 == NULL && ( * V_185 == 0x1f ) &&
( * ( V_185 + 1 ) == 0x8b ) ) {
T_28 * V_160 = V_185 + 2 ;
T_28 V_209 = 0 ;
if ( * V_160 == V_210 ) {
V_160 ++ ;
} else {
F_176 ( V_188 ) ;
F_9 ( V_188 ) ;
F_9 ( V_185 ) ;
F_9 ( V_189 ) ;
return NULL ;
}
V_209 = * V_160 ;
V_160 += 7 ;
if ( V_209 & ( 1 << 2 ) ) {
T_8 V_211 = ( T_8 ) ( * V_160 |
( * ( V_160 + 1 ) << 8 ) ) ;
V_160 += V_211 ;
}
if ( V_209 & ( 1 << 3 ) ) {
while ( ( V_160 - V_185 ) < V_181 && * V_160 != '\0' ) {
V_160 ++ ;
}
V_160 ++ ;
}
if ( V_209 & ( 1 << 4 ) ) {
while ( ( V_160 - V_185 ) < V_181 && * V_160 != '\0' ) {
V_160 ++ ;
}
V_160 ++ ;
}
F_180 ( V_188 ) ;
V_5 = V_160 ;
V_188 -> V_199 = V_5 ;
if ( V_160 - V_185 > V_181 ) {
F_176 ( V_188 ) ;
F_9 ( V_188 ) ;
F_9 ( V_185 ) ;
F_9 ( V_189 ) ;
return NULL ;
}
V_181 -= ( int ) ( V_160 - V_185 ) ;
F_176 ( V_188 ) ;
F_175 ( V_188 , V_191 ) ;
V_190 ++ ;
} else if ( V_182 == V_208 && V_186 == NULL &&
V_190 <= 3 ) {
V_191 = - V_192 ;
F_180 ( V_188 ) ;
V_188 -> V_199 = V_5 ;
V_188 -> V_200 = V_181 ;
F_176 ( V_188 ) ;
memset ( V_189 , '\0' , V_193 ) ;
V_188 -> V_201 = V_189 ;
V_188 -> V_202 = V_193 ;
V_182 = F_175 ( V_188 , V_191 ) ;
V_190 ++ ;
if ( V_182 != V_183 ) {
F_9 ( V_188 ) ;
F_9 ( V_189 ) ;
F_9 ( V_185 ) ;
F_9 ( V_186 ) ;
return NULL ;
}
} else {
F_176 ( V_188 ) ;
F_9 ( V_188 ) ;
F_9 ( V_189 ) ;
if ( V_186 == NULL ) {
F_9 ( V_185 ) ;
return NULL ;
}
break;
}
}
#ifdef F_171
printf ( L_7 , V_195 ) ;
printf ( L_8 , V_196 , V_184 ) ;
#endif
if ( V_186 != NULL ) {
V_187 = F_20 ( ( T_7 * ) V_186 , V_184 , V_184 ) ;
F_14 ( V_187 , F_9 ) ;
}
F_9 ( V_185 ) ;
return V_187 ;
}
T_1 *
F_170 ( T_1 * V_1 V_111 , const int V_17 V_111 , int V_181 V_111 )
{
return NULL ;
}
T_1 *
F_181 ( T_1 * V_27 , T_1 * V_1 , const int V_17 , int V_181 )
{
T_1 * V_212 = F_170 ( V_1 , V_17 , V_181 ) ;
if ( V_212 )
F_16 ( V_27 , V_212 ) ;
return V_212 ;
}
T_8
F_182 ( T_1 * V_1 )
{
return ( ( V_1 -> V_11 == - 1 ) ? ( V_1 -> V_11 = F_51 ( V_1 ) ) : V_1 -> V_11 ) ;
}
struct V_213 *
F_183 ( T_1 * V_1 )
{
return ( V_1 -> V_12 ) ;
}
