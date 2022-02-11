static T_1 *
F_1 ( const T_2 type )
{
T_1 * V_1 ;
T_3 * V_2 ;
T_4 * V_3 ;
V_1 = F_2 ( T_1 ) ;
V_1 -> V_4 = NULL ;
V_1 -> V_5 = NULL ;
V_1 -> type = type ;
V_1 -> V_6 = FALSE ;
V_1 -> V_7 = 0 ;
V_1 -> V_8 = 0 ;
V_1 -> V_9 = 0 ;
V_1 -> V_10 = NULL ;
V_1 -> V_11 = NULL ;
V_1 -> V_12 = - 1 ;
V_1 -> V_13 = NULL ;
switch( type ) {
case V_14 :
break;
case V_15 :
V_2 = & V_1 -> V_16 . V_17 ;
V_2 -> V_1 = NULL ;
V_2 -> V_18 = 0 ;
V_2 -> V_8 = 0 ;
break;
case V_19 :
V_3 = & V_1 -> V_16 . V_3 ;
V_3 -> V_20 = NULL ;
V_3 -> V_21 = NULL ;
V_3 -> V_22 = NULL ;
break;
default:
F_3 () ;
break;
}
return V_1 ;
}
static void
F_4 ( T_1 * V_1 )
{
T_4 * V_3 ;
F_5 ( V_1 ) ;
switch ( V_1 -> type ) {
case V_14 :
if ( V_1 -> V_10 ) {
V_1 -> V_10 ( ( V_23 ) V_1 -> V_11 ) ;
}
break;
case V_15 :
break;
case V_19 :
V_3 = & V_1 -> V_16 . V_3 ;
F_6 ( V_3 -> V_20 ) ;
F_7 ( V_3 -> V_21 ) ;
F_7 ( V_3 -> V_22 ) ;
if ( V_1 -> V_11 ) {
F_7 ( ( V_23 ) V_1 -> V_11 ) ;
}
break;
default:
F_3 () ;
}
F_8 ( T_1 , V_1 ) ;
}
void
F_9 ( T_1 * V_1 )
{
F_10 ( V_1 ) ;
}
void
F_10 ( T_1 * V_1 )
{
T_1 * V_24 ;
F_5 ( V_1 ) ;
F_11 ( V_1 -> V_4 == NULL , L_1 ) ;
while ( V_1 ) {
V_24 = V_1 -> V_5 ;
F_11 ( ( V_24 == NULL ) || ( V_1 == V_24 -> V_4 ) , L_2 ) ;
F_4 ( V_1 ) ;
V_1 = V_24 ;
}
}
void
F_12 ( T_1 * V_1 , const T_5 V_25 )
{
F_5 ( V_1 ) ;
F_5 ( V_1 -> type == V_14 ) ;
V_1 -> V_10 = V_25 ;
}
static void
F_13 ( T_1 * V_26 , T_1 * V_27 )
{
F_5 ( V_26 && V_27 ) ;
F_5 ( ! V_27 -> V_5 && ! V_27 -> V_4 ) ;
V_27 -> V_5 = V_26 -> V_5 ;
V_27 -> V_4 = V_26 ;
if ( V_26 -> V_5 )
V_26 -> V_5 -> V_4 = V_27 ;
V_26 -> V_5 = V_27 ;
}
void
F_14 ( T_1 * V_26 , T_1 * V_27 )
{
F_5 ( V_26 && V_27 ) ;
F_5 ( V_26 -> V_6 ) ;
F_5 ( V_27 -> V_6 ) ;
F_5 ( V_27 -> type == V_14 ) ;
F_13 ( V_26 , V_27 ) ;
}
T_1 *
F_15 ( const T_6 * V_28 , const T_7 V_8 , const T_8 V_9 )
{
T_1 * V_1 ;
F_16 ( V_9 < - 1 , V_29 ) ;
V_1 = F_1 ( V_14 ) ;
V_1 -> V_11 = V_28 ;
V_1 -> V_8 = V_8 ;
V_1 -> V_9 = V_9 ;
V_1 -> V_6 = TRUE ;
V_1 -> V_13 = V_1 ;
return V_1 ;
}
T_1 *
F_17 ( T_1 * V_26 , const T_6 * V_28 , const T_7 V_8 , const T_8 V_9 )
{
T_1 * V_1 = F_15 ( V_28 , V_8 , V_9 ) ;
if ( V_1 ) {
F_14 ( V_26 , V_1 ) ;
}
return V_1 ;
}
static T_9
F_18 ( const T_1 * V_1 ,
const T_8 V_18 , const T_8 V_30 ,
T_7 * V_31 , T_7 * V_32 , int * V_33 )
{
F_5 ( V_31 ) ;
F_5 ( V_32 ) ;
if ( V_18 >= 0 ) {
if ( ( T_7 ) V_18 > V_1 -> V_9 ) {
if ( V_33 ) {
if ( V_1 -> V_7 & V_34 ) {
* V_33 = V_35 ;
} else {
* V_33 = V_29 ;
}
}
return FALSE ;
}
else if ( ( T_7 ) V_18 > V_1 -> V_8 ) {
if ( V_33 ) {
* V_33 = V_36 ;
}
return FALSE ;
}
else {
* V_31 = V_18 ;
}
}
else {
if ( ( T_7 ) - V_18 > V_1 -> V_9 ) {
if ( V_33 ) {
if ( V_1 -> V_7 & V_34 ) {
* V_33 = V_35 ;
} else {
* V_33 = V_29 ;
}
}
return FALSE ;
}
else if ( ( T_7 ) - V_18 > V_1 -> V_8 ) {
if ( V_33 ) {
* V_33 = V_36 ;
}
return FALSE ;
}
else {
* V_31 = V_1 -> V_8 + V_18 ;
}
}
if ( V_30 < - 1 ) {
if ( V_33 ) {
* V_33 = V_36 ;
}
return FALSE ;
}
else if ( V_30 == - 1 ) {
* V_32 = V_1 -> V_8 - * V_31 ;
}
else {
* V_32 = V_30 ;
}
return TRUE ;
}
static T_9
F_19 ( const T_1 * V_1 ,
const T_8 V_18 , T_8 const V_30 ,
T_7 * V_31 , T_7 * V_32 , int * V_33 )
{
T_7 V_37 ;
if ( ! F_18 ( V_1 ,
V_18 , V_30 , V_31 , V_32 , V_33 ) ) {
return FALSE ;
}
V_37 = * V_31 + * V_32 ;
if ( V_37 < * V_31 )
V_37 = V_38 ;
if ( V_37 <= V_1 -> V_8 ) {
return TRUE ;
}
else {
if ( V_33 ) {
if ( V_37 <= V_1 -> V_9 ) {
* V_33 = V_36 ;
}
else {
if ( V_1 -> V_7 & V_34 ) {
* V_33 = V_35 ;
} else {
* V_33 = V_29 ;
}
}
}
return FALSE ;
}
}
static void
F_20 ( const T_1 * V_1 ,
const T_8 V_18 , T_8 const V_30 ,
T_7 * V_31 , T_7 * V_32 )
{
int V_33 = 0 ;
if ( ! F_19 ( V_1 ,
V_18 , V_30 , V_31 , V_32 , & V_33 ) ) {
F_5 ( V_33 > 0 ) ;
F_21 ( V_33 ) ;
}
}
static T_1 *
F_22 ( T_1 * V_2 , const T_8 V_9 ,
const T_7 V_39 , const T_7 V_40 )
{
T_1 * V_1 = F_1 ( V_15 ) ;
V_1 -> V_16 . V_17 . V_18 = V_39 ;
V_1 -> V_16 . V_17 . V_8 = V_40 ;
V_1 -> V_16 . V_17 . V_1 = V_2 ;
V_1 -> V_8 = V_1 -> V_16 . V_17 . V_8 ;
V_1 -> V_7 = V_2 -> V_7 ;
if ( V_9 == - 1 ) {
V_1 -> V_9 = V_2 -> V_9 - V_1 -> V_16 . V_17 . V_18 ;
}
else {
V_1 -> V_9 = V_9 ;
}
V_1 -> V_6 = TRUE ;
F_13 ( V_2 , V_1 ) ;
if ( V_2 -> V_11 != NULL ) {
V_1 -> V_11 = V_2 -> V_11 + V_1 -> V_16 . V_17 . V_18 ;
}
return V_1 ;
}
T_1 *
F_23 ( T_1 * V_2 , const T_8 V_41 , const T_8 V_42 , const T_8 V_9 )
{
T_1 * V_1 ;
T_7 V_39 ;
T_7 V_40 ;
F_5 ( V_2 && V_2 -> V_6 ) ;
F_16 ( V_9 < - 1 , V_29 ) ;
F_20 ( V_2 , V_41 , V_42 ,
& V_39 ,
& V_40 ) ;
V_1 = F_22 ( V_2 , V_9 ,
V_39 , V_40 ) ;
V_1 -> V_13 = V_2 -> V_13 ;
return V_1 ;
}
T_1 *
F_24 ( T_1 * V_2 , const T_8 V_41 , const T_8 V_42 )
{
T_8 V_43 ;
T_1 * V_1 ;
T_7 V_39 ;
T_7 V_40 ;
F_5 ( V_2 && V_2 -> V_6 ) ;
F_16 ( V_42 < 0 , V_29 ) ;
V_43 = F_25 ( V_2 , V_41 ) ;
F_16 ( V_43 < 0 , V_36 ) ;
if ( V_43 > V_42 )
V_43 = V_42 ;
F_20 ( V_2 , V_41 , V_43 ,
& V_39 ,
& V_40 ) ;
V_1 = F_22 ( V_2 , V_42 ,
V_39 , V_40 ) ;
V_1 -> V_13 = V_2 -> V_13 ;
return V_1 ;
}
T_1 *
F_26 ( T_1 * V_2 , const T_8 V_41 )
{
T_1 * V_1 ;
T_7 V_39 ;
T_7 V_40 ;
F_20 ( V_2 , V_41 , - 1 ,
& V_39 ,
& V_40 ) ;
V_1 = F_22 ( V_2 , - 1 ,
V_39 , V_40 ) ;
V_1 -> V_13 = V_2 -> V_13 ;
return V_1 ;
}
T_1 *
F_27 ( T_1 * V_1 , T_10 V_44 , T_11 V_45 )
{
T_1 * V_46 = NULL ;
T_10 V_47 ;
T_11 V_48 , V_49 ;
T_6 V_50 , V_51 , V_52 , * V_53 ;
const T_6 * V_28 ;
V_47 = V_44 >> 3 ;
V_50 = V_44 % 8 ;
V_51 = 8 - V_50 ;
if ( V_45 == - 1 ) {
V_48 = F_25 ( V_1 , V_47 ) ;
V_52 = 0 ;
} else {
V_48 = V_45 >> 3 ;
V_52 = V_45 % 8 ;
if ( V_52 ) {
V_48 ++ ;
}
}
if ( ( V_50 == 0 ) && ( V_52 == 0 ) ) {
return F_23 ( V_1 , V_47 , V_48 , - 1 ) ;
}
F_5 ( V_48 > 0 ) ;
if ( F_25 ( V_1 , V_47 ) > V_48 ) {
V_28 = F_28 ( V_1 , V_47 , V_48 + 1 ) ;
V_53 = ( T_6 * ) F_29 ( V_48 ) ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ )
V_53 [ V_49 ] = ( V_28 [ V_49 ] << V_50 ) | ( V_28 [ V_49 + 1 ] >> V_51 ) ;
} else {
V_28 = F_28 ( V_1 , V_47 , V_48 ) ;
V_53 = ( T_6 * ) F_29 ( V_48 ) ;
for ( V_49 = 0 ; V_49 < ( V_48 - 1 ) ; V_49 ++ )
V_53 [ V_49 ] = ( V_28 [ V_49 ] << V_50 ) | ( V_28 [ V_49 + 1 ] >> V_51 ) ;
V_53 [ V_48 - 1 ] = V_28 [ V_48 - 1 ] << V_50 ;
}
V_53 [ V_48 - 1 ] &= V_54 [ V_52 ] ;
V_46 = F_17 ( V_1 , V_53 , V_48 , V_48 ) ;
F_12 ( V_46 , F_7 ) ;
return V_46 ;
}
T_1 *
F_30 ( void )
{
return F_1 ( V_19 ) ;
}
void
F_31 ( T_1 * V_1 , T_1 * V_55 )
{
T_4 * V_3 ;
F_5 ( V_1 && ! V_1 -> V_6 ) ;
F_5 ( V_1 -> type == V_19 ) ;
F_5 ( V_55 -> V_8 ) ;
V_3 = & V_1 -> V_16 . V_3 ;
V_3 -> V_20 = F_32 ( V_3 -> V_20 , V_55 ) ;
}
void
F_33 ( T_1 * V_1 , T_1 * V_55 )
{
T_4 * V_3 ;
F_5 ( V_1 && ! V_1 -> V_6 ) ;
F_5 ( V_1 -> type == V_19 ) ;
F_5 ( V_55 -> V_8 ) ;
V_3 = & V_1 -> V_16 . V_3 ;
V_3 -> V_20 = F_34 ( V_3 -> V_20 , V_55 ) ;
}
void
F_35 ( T_1 * V_1 )
{
T_12 * V_56 ;
T_7 V_57 ;
T_1 * V_58 ;
T_4 * V_3 ;
int V_49 = 0 ;
F_5 ( V_1 && ! V_1 -> V_6 ) ;
F_5 ( V_1 -> type == V_19 ) ;
F_5 ( V_1 -> V_8 == 0 ) ;
F_5 ( V_1 -> V_9 == 0 ) ;
V_3 = & V_1 -> V_16 . V_3 ;
V_57 = F_36 ( V_3 -> V_20 ) ;
F_5 ( V_57 ) ;
V_3 -> V_21 = F_37 ( T_7 , V_57 ) ;
V_3 -> V_22 = F_37 ( T_7 , V_57 ) ;
for ( V_56 = V_3 -> V_20 ; V_56 != NULL ; V_56 = V_56 -> V_5 ) {
F_5 ( ( T_7 ) V_49 < V_57 ) ;
V_58 = ( T_1 * ) V_56 -> V_28 ;
V_3 -> V_21 [ V_49 ] = V_1 -> V_8 ;
V_1 -> V_8 += V_58 -> V_8 ;
V_1 -> V_9 += V_58 -> V_9 ;
V_3 -> V_22 [ V_49 ] = V_1 -> V_8 - 1 ;
V_49 ++ ;
}
F_13 ( ( T_1 * ) V_3 -> V_20 -> V_28 , V_1 ) ;
V_1 -> V_6 = TRUE ;
}
T_7
F_38 ( const T_1 * V_1 )
{
F_5 ( V_1 && V_1 -> V_6 ) ;
return V_1 -> V_8 ;
}
T_8
F_25 ( const T_1 * V_1 , const T_8 V_18 )
{
T_7 V_59 , V_60 ;
F_5 ( V_1 && V_1 -> V_6 ) ;
if ( F_18 ( V_1 , V_18 , - 1 , & V_59 , & V_60 , NULL ) ) {
return V_60 ;
}
else {
return - 1 ;
}
}
T_7
F_39 ( const T_1 * V_1 , const T_8 V_18 )
{
T_7 V_59 , V_60 ;
int V_33 ;
F_5 ( V_1 && V_1 -> V_6 ) ;
if ( ! F_18 ( V_1 , V_18 , - 1 , & V_59 , & V_60 , & V_33 ) ) {
F_21 ( V_33 ) ;
}
if ( V_60 == 0 ) {
if ( V_59 >= V_1 -> V_9 ) {
if ( V_1 -> V_7 & V_34 ) {
F_21 ( V_35 ) ;
} else {
F_21 ( V_29 ) ;
}
} else
F_21 ( V_36 ) ;
}
return V_60 ;
}
T_9
F_40 ( const T_1 * V_1 , const T_8 V_18 , const T_8 V_8 )
{
T_7 V_59 , V_60 ;
F_5 ( V_1 && V_1 -> V_6 ) ;
if ( ! F_18 ( V_1 , V_18 , V_8 , & V_59 , & V_60 , NULL ) )
return FALSE ;
if ( V_59 + V_60 <= V_1 -> V_8 ) {
return TRUE ;
}
else {
return FALSE ;
}
}
void
F_41 ( const T_1 * V_1 , const T_8 V_18 , const T_8 V_8 )
{
T_7 V_59 , V_60 ;
F_5 ( V_1 && V_1 -> V_6 ) ;
if ( V_8 < 0 ) {
F_21 ( V_29 ) ;
}
F_20 ( V_1 , V_18 , V_8 , & V_59 , & V_60 ) ;
}
T_9
F_42 ( const T_1 * V_1 , const T_8 V_18 )
{
T_7 V_59 , V_60 ;
F_5 ( V_1 && V_1 -> V_6 ) ;
if ( ! F_18 ( V_1 , V_18 , - 1 , & V_59 , & V_60 , NULL ) )
return FALSE ;
if ( V_59 < V_1 -> V_8 ) {
return TRUE ;
}
else {
return FALSE ;
}
}
T_7
F_43 ( const T_1 * V_1 )
{
F_5 ( V_1 && V_1 -> V_6 ) ;
return V_1 -> V_9 ;
}
T_8
F_44 ( const T_1 * V_1 , const T_8 V_18 )
{
T_7 V_59 , V_60 ;
F_5 ( V_1 && V_1 -> V_6 ) ;
if ( F_18 ( V_1 , V_18 , - 1 , & V_59 , & V_60 , NULL ) ) {
if ( V_1 -> V_9 >= V_59 )
return V_1 -> V_9 - V_59 ;
else
return - 1 ;
}
else {
return - 1 ;
}
}
void
F_45 ( T_1 * V_1 , const T_7 V_9 )
{
F_5 ( V_1 && V_1 -> V_6 ) ;
if ( V_9 > V_1 -> V_9 )
F_21 ( V_29 ) ;
V_1 -> V_9 = V_9 ;
if ( V_9 < V_1 -> V_8 )
V_1 -> V_8 = V_9 ;
}
static T_7
F_46 ( const T_1 * V_1 , const T_7 V_61 )
{
T_1 * V_55 ;
switch( V_1 -> type ) {
case V_14 :
return V_61 ;
case V_15 :
V_55 = V_1 -> V_16 . V_17 . V_1 ;
return F_46 ( V_55 , V_61 + V_1 -> V_16 . V_17 . V_18 ) ;
case V_19 :
V_55 = ( T_1 * ) V_1 -> V_16 . V_3 . V_20 -> V_28 ;
return F_46 ( V_55 , V_61 ) ;
}
F_3 () ;
return 0 ;
}
T_7
F_47 ( const T_1 * V_1 )
{
return F_46 ( V_1 , 0 ) ;
}
static const T_6 *
F_48 ( T_1 * V_1 , const T_7 V_59 , const T_7 V_60 )
{
T_7 V_49 , V_57 ;
T_4 * V_3 ;
T_1 * V_58 = NULL ;
T_7 V_62 , V_63 ;
T_12 * V_56 ;
F_5 ( V_1 -> type == V_19 ) ;
V_3 = & V_1 -> V_16 . V_3 ;
V_57 = F_36 ( V_3 -> V_20 ) ;
for ( V_49 = 0 ; V_49 < V_57 ; V_49 ++ ) {
if ( V_59 <= V_3 -> V_22 [ V_49 ] ) {
V_56 = F_49 ( V_3 -> V_20 , V_49 ) ;
V_58 = ( T_1 * ) V_56 -> V_28 ;
break;
}
}
F_5 ( V_58 ) ;
if ( F_19 ( V_58 ,
V_59 - V_3 -> V_21 [ V_49 ] ,
V_60 , & V_62 , & V_63 , NULL ) ) {
F_5 ( ! V_1 -> V_11 ) ;
return F_50 ( V_58 , V_62 , V_63 , NULL ) ;
}
else {
V_1 -> V_11 = ( T_6 * ) F_51 ( V_1 , 0 , - 1 ) ;
return V_1 -> V_11 + V_59 ;
}
F_3 () ;
}
static const T_6 *
F_50 ( T_1 * V_1 , const T_8 V_18 , const T_8 V_8 , int * V_33 )
{
T_7 V_59 , V_60 ;
if ( ! F_19 ( V_1 , V_18 , V_8 ,
& V_59 , & V_60 , V_33 ) ) {
return NULL ;
}
if ( V_1 -> V_11 ) {
return V_1 -> V_11 + V_59 ;
}
else {
switch( V_1 -> type ) {
case V_14 :
F_3 () ;
case V_15 :
return F_50 ( V_1 -> V_16 . V_17 . V_1 ,
V_59 - V_1 -> V_16 . V_17 . V_18 ,
V_60 , NULL ) ;
case V_19 :
return F_48 ( V_1 , V_59 , V_60 ) ;
}
}
F_3 () ;
return NULL ;
}
static const T_6 *
F_52 ( T_1 * V_1 , const T_8 V_18 , const T_8 V_8 )
{
int V_33 = 0 ;
const T_6 * V_64 ;
V_64 = F_50 ( V_1 , V_18 , V_8 , & V_33 ) ;
if ( V_64 == NULL ) {
F_5 ( V_33 > 0 ) ;
F_21 ( V_33 ) ;
}
return V_64 ;
}
static const T_6 *
F_53 ( T_1 * V_1 , const T_8 V_18 , const T_7 V_8 )
{
T_7 V_37 ;
T_7 V_65 ;
F_5 ( V_1 && V_1 -> V_6 ) ;
F_5 ( V_8 <= 8 ) ;
if ( V_18 < 0 || ! V_1 -> V_11 ) {
return F_52 ( V_1 , V_18 , V_8 ) ;
}
V_65 = V_18 ;
V_37 = V_65 + V_8 ;
if ( V_37 <= V_1 -> V_8 ) {
return V_1 -> V_11 + V_65 ;
}
if ( V_37 > V_1 -> V_9 ) {
if ( V_1 -> V_7 & V_34 ) {
F_21 ( V_35 ) ;
} else {
F_21 ( V_29 ) ;
}
}
F_21 ( V_36 ) ;
return NULL ;
}
static const T_6 *
F_54 ( const T_6 * V_66 , T_13 V_67 , const T_6 * V_68 , T_14 * V_69 )
{
T_15 V_70 [ 256 ] = { 0 } ;
const T_6 * V_71 ;
while ( * V_68 )
V_70 [ * V_68 ++ ] = 1 ;
V_71 = V_66 + V_67 ;
while ( V_66 < V_71 ) {
if ( V_70 [ * V_66 ] ) {
if ( V_69 )
* V_69 = * V_66 ;
return V_66 ;
}
V_66 ++ ;
}
return NULL ;
}
static void *
F_55 ( T_1 * V_1 , T_6 * V_72 , T_7 V_59 , T_13 V_60 )
{
T_7 V_49 , V_57 ;
T_4 * V_3 ;
T_1 * V_58 = NULL ;
T_7 V_62 , V_63 ;
T_9 V_73 ;
T_12 * V_56 ;
F_5 ( V_1 -> type == V_19 ) ;
V_3 = & V_1 -> V_16 . V_3 ;
V_57 = F_36 ( V_3 -> V_20 ) ;
for ( V_49 = 0 ; V_49 < V_57 ; V_49 ++ ) {
if ( V_59 <= V_3 -> V_22 [ V_49 ] ) {
V_56 = F_49 ( V_3 -> V_20 , V_49 ) ;
V_58 = ( T_1 * ) V_56 -> V_28 ;
break;
}
}
F_5 ( V_58 ) ;
if ( F_19 ( V_58 , V_59 - V_3 -> V_21 [ V_49 ] ,
( T_8 ) V_60 , & V_62 , & V_63 , NULL ) ) {
F_5 ( ! V_1 -> V_11 ) ;
return F_56 ( V_58 , V_72 , V_62 , V_63 ) ;
}
else {
V_73 = F_18 ( V_58 , V_59 - V_3 -> V_21 [ V_49 ] , - 1 ,
& V_62 , & V_63 , NULL ) ;
F_5 ( V_73 ) ;
F_5 ( V_63 ) ;
F_56 ( V_58 , V_72 , V_62 , V_63 ) ;
V_59 += V_63 ;
V_60 -= V_63 ;
if ( V_60 > 0 ) {
F_55 ( V_1 , V_72 + V_63 , V_59 , V_60 ) ;
}
return V_72 ;
}
F_3 () ;
}
void *
F_56 ( T_1 * V_1 , void * V_72 , const T_8 V_18 , T_13 V_8 )
{
T_7 V_59 , V_60 ;
F_5 ( V_1 && V_1 -> V_6 ) ;
F_5 ( V_8 <= 0x7FFFFFFF ) ;
F_20 ( V_1 , V_18 , ( T_8 ) V_8 , & V_59 , & V_60 ) ;
if ( V_1 -> V_11 ) {
return memcpy ( V_72 , V_1 -> V_11 + V_59 , V_60 ) ;
}
switch( V_1 -> type ) {
case V_14 :
F_3 () ;
case V_15 :
return F_56 ( V_1 -> V_16 . V_17 . V_1 , V_72 ,
V_59 - V_1 -> V_16 . V_17 . V_18 ,
V_60 ) ;
case V_19 :
return F_55 ( V_1 , ( T_6 * ) V_72 , V_18 , V_8 ) ;
}
F_3 () ;
return NULL ;
}
void *
F_51 ( T_1 * V_1 , const T_8 V_18 , T_13 V_8 )
{
T_7 V_59 , V_60 ;
void * V_74 ;
F_5 ( V_1 && V_1 -> V_6 ) ;
F_20 ( V_1 , V_18 , ( T_8 ) V_8 , & V_59 , & V_60 ) ;
V_74 = F_29 ( V_60 ) ;
return F_56 ( V_1 , V_74 , V_59 , V_60 ) ;
}
void *
F_57 ( T_1 * V_1 , const T_8 V_18 , T_13 V_8 )
{
T_7 V_59 , V_60 ;
void * V_74 ;
F_5 ( V_1 && V_1 -> V_6 ) ;
F_20 ( V_1 , V_18 , ( T_8 ) V_8 , & V_59 , & V_60 ) ;
V_74 = F_58 ( V_60 ) ;
return F_56 ( V_1 , V_74 , V_59 , V_60 ) ;
}
const T_6 *
F_28 ( T_1 * V_1 , const T_8 V_18 , const T_8 V_8 )
{
return F_52 ( V_1 , V_18 , V_8 ) ;
}
T_6
F_59 ( T_1 * V_1 , const T_8 V_18 )
{
const T_6 * V_75 ;
V_75 = F_53 ( V_1 , V_18 , sizeof( T_6 ) ) ;
return * V_75 ;
}
T_16
F_60 ( T_1 * V_1 , const T_8 V_18 )
{
const T_6 * V_75 ;
V_75 = F_53 ( V_1 , V_18 , sizeof( T_16 ) ) ;
return F_61 ( V_75 ) ;
}
T_10
F_62 ( T_1 * V_1 , const T_8 V_18 )
{
const T_6 * V_75 ;
V_75 = F_53 ( V_1 , V_18 , 3 ) ;
return F_63 ( V_75 ) ;
}
T_10
F_64 ( T_1 * V_1 , const T_8 V_18 )
{
const T_6 * V_75 ;
V_75 = F_53 ( V_1 , V_18 , sizeof( T_10 ) ) ;
return F_65 ( V_75 ) ;
}
T_17
F_66 ( T_1 * V_1 , const T_8 V_18 )
{
const T_6 * V_75 ;
V_75 = F_53 ( V_1 , V_18 , 5 ) ;
return F_67 ( V_75 ) ;
}
T_17
F_68 ( T_1 * V_1 , const T_8 V_18 )
{
const T_6 * V_75 ;
V_75 = F_53 ( V_1 , V_18 , 6 ) ;
return F_69 ( V_75 ) ;
}
T_17
F_70 ( T_1 * V_1 , const T_8 V_18 )
{
const T_6 * V_75 ;
V_75 = F_53 ( V_1 , V_18 , 7 ) ;
return F_71 ( V_75 ) ;
}
T_17
F_72 ( T_1 * V_1 , const T_8 V_18 )
{
const T_6 * V_75 ;
V_75 = F_53 ( V_1 , V_18 , sizeof( T_17 ) ) ;
return F_73 ( V_75 ) ;
}
static int
F_74 ( const T_10 V_76 )
{
return ( ( V_76 & ~ V_77 ) == 0 ) ;
}
static T_18
F_75 ( const T_10 V_76 )
{
long V_78 ;
long V_79 ;
long V_80 ;
V_78 = V_76 & V_77 ;
V_79 = V_76 & V_81 ;
V_80 = V_76 & V_82 ;
if ( F_74 ( V_76 ) ) {
return 0.0 ;
}
#if 0
if (IEEE_SP_INFINITY == exponent) {
return (sign? MINUS_INFINITY: PLUS_INFINITY);
}
#endif
V_79 = ( ( V_79 >> V_83 ) - V_84 ) -
V_83 ;
V_80 |= V_85 ;
if ( V_78 )
return - V_80 * pow ( 2 , V_79 ) ;
else
return V_80 * pow ( 2 , V_79 ) ;
}
static int
F_76 ( const T_17 V_76 )
{
return ( ( V_76 & ~ V_77 ) == 0 ) ;
}
static T_19
F_77 ( const T_17 V_76 )
{
T_20 V_78 ;
T_20 V_79 ;
T_20 V_80 ;
V_78 = V_76 & V_86 ;
V_79 = V_76 & V_87 ;
V_80 = V_76 & V_88 ;
if ( F_76 ( V_76 ) ) {
return 0.0 ;
}
#if 0
if (IEEE_DP_INFINITY == exponent) {
return (sign? MINUS_INFINITY: PLUS_INFINITY);
}
#endif
V_79 = ( ( V_79 >> V_89 ) - V_90 ) -
V_89 ;
V_80 |= V_91 ;
if ( V_78 )
return - V_80 * pow ( 2 , V_79 ) ;
else
return V_80 * pow ( 2 , V_79 ) ;
}
T_18
F_78 ( T_1 * V_1 , const int V_18 )
{
#if F_79 ( V_92 )
return F_75 ( F_64 ( V_1 , V_18 ) ) ;
#else
union {
T_18 V_93 ;
T_10 V_76 ;
} V_94 ;
V_94 . V_76 = F_64 ( V_1 , V_18 ) ;
return V_94 . V_93 ;
#endif
}
T_19
F_80 ( T_1 * V_1 , const int V_18 )
{
#if F_79 ( V_92 )
union {
T_10 V_76 [ 2 ] ;
T_17 V_95 ;
} V_94 ;
#else
union {
T_19 V_96 ;
T_10 V_76 [ 2 ] ;
} V_94 ;
#endif
#ifdef F_81
V_94 . V_76 [ 0 ] = F_64 ( V_1 , V_18 ) ;
V_94 . V_76 [ 1 ] = F_64 ( V_1 , V_18 + 4 ) ;
#else
V_94 . V_76 [ 0 ] = F_64 ( V_1 , V_18 + 4 ) ;
V_94 . V_76 [ 1 ] = F_64 ( V_1 , V_18 ) ;
#endif
#if F_79 ( V_92 )
return F_77 ( V_94 . V_95 ) ;
#else
return V_94 . V_96 ;
#endif
}
T_16
F_82 ( T_1 * V_1 , const T_8 V_18 )
{
const T_6 * V_75 ;
V_75 = F_53 ( V_1 , V_18 , sizeof( T_16 ) ) ;
return F_83 ( V_75 ) ;
}
T_10
F_84 ( T_1 * V_1 , const T_8 V_18 )
{
const T_6 * V_75 ;
V_75 = F_53 ( V_1 , V_18 , 3 ) ;
return F_85 ( V_75 ) ;
}
T_10
F_86 ( T_1 * V_1 , const T_8 V_18 )
{
const T_6 * V_75 ;
V_75 = F_53 ( V_1 , V_18 , sizeof( T_10 ) ) ;
return F_87 ( V_75 ) ;
}
T_17
F_88 ( T_1 * V_1 , const T_8 V_18 )
{
const T_6 * V_75 ;
V_75 = F_53 ( V_1 , V_18 , 5 ) ;
return F_89 ( V_75 ) ;
}
T_17
F_90 ( T_1 * V_1 , const T_8 V_18 )
{
const T_6 * V_75 ;
V_75 = F_53 ( V_1 , V_18 , 6 ) ;
return F_91 ( V_75 ) ;
}
T_17
F_92 ( T_1 * V_1 , const T_8 V_18 )
{
const T_6 * V_75 ;
V_75 = F_53 ( V_1 , V_18 , 7 ) ;
return F_93 ( V_75 ) ;
}
T_17
F_94 ( T_1 * V_1 , const T_8 V_18 )
{
const T_6 * V_75 ;
V_75 = F_53 ( V_1 , V_18 , sizeof( T_17 ) ) ;
return F_95 ( V_75 ) ;
}
T_18
F_96 ( T_1 * V_1 , const int V_18 )
{
#if F_79 ( V_92 )
return F_75 ( F_86 ( V_1 , V_18 ) ) ;
#else
union {
T_18 V_93 ;
T_10 V_76 ;
} V_94 ;
V_94 . V_76 = F_86 ( V_1 , V_18 ) ;
return V_94 . V_93 ;
#endif
}
T_19
F_97 ( T_1 * V_1 , const int V_18 )
{
#if F_79 ( V_92 )
union {
T_10 V_76 [ 2 ] ;
T_17 V_95 ;
} V_94 ;
#else
union {
T_19 V_96 ;
T_10 V_76 [ 2 ] ;
} V_94 ;
#endif
#ifdef F_81
V_94 . V_76 [ 0 ] = F_86 ( V_1 , V_18 + 4 ) ;
V_94 . V_76 [ 1 ] = F_86 ( V_1 , V_18 ) ;
#else
V_94 . V_76 [ 0 ] = F_86 ( V_1 , V_18 ) ;
V_94 . V_76 [ 1 ] = F_86 ( V_1 , V_18 + 4 ) ;
#endif
#if F_79 ( V_92 )
return F_77 ( V_94 . V_95 ) ;
#else
return V_94 . V_96 ;
#endif
}
T_10
F_98 ( T_1 * V_1 , const T_8 V_18 )
{
const T_6 * V_75 ;
T_10 V_97 ;
V_75 = F_53 ( V_1 , V_18 , sizeof( T_10 ) ) ;
memcpy ( & V_97 , V_75 , sizeof V_97 ) ;
return V_97 ;
}
void
F_99 ( T_1 * V_1 , const T_8 V_18 , struct V_98 * V_97 )
{
const T_6 * V_75 ;
V_75 = F_52 ( V_1 , V_18 , sizeof( * V_97 ) ) ;
memcpy ( V_97 , V_75 , sizeof *V_97 ) ;
}
void
F_100 ( T_1 * V_1 , const T_8 V_18 , T_21 * V_99 )
{
F_52 ( V_1 , V_18 , sizeof( * V_99 ) ) ;
V_99 -> V_100 = F_64 ( V_1 , V_18 ) ;
V_99 -> V_101 = F_60 ( V_1 , V_18 + 4 ) ;
V_99 -> V_102 = F_60 ( V_1 , V_18 + 6 ) ;
F_56 ( V_1 , V_99 -> V_103 , V_18 + 8 , sizeof V_99 -> V_103 ) ;
}
void
F_101 ( T_1 * V_1 , const T_8 V_18 , T_21 * V_99 )
{
F_52 ( V_1 , V_18 , sizeof( * V_99 ) ) ;
V_99 -> V_100 = F_86 ( V_1 , V_18 ) ;
V_99 -> V_101 = F_82 ( V_1 , V_18 + 4 ) ;
V_99 -> V_102 = F_82 ( V_1 , V_18 + 6 ) ;
F_56 ( V_1 , V_99 -> V_103 , V_18 + 8 , sizeof V_99 -> V_103 ) ;
}
void
F_102 ( T_1 * V_1 , const T_8 V_18 , T_21 * V_99 , const T_7 V_104 )
{
if ( V_104 ) {
F_101 ( V_1 , V_18 , V_99 ) ;
} else {
F_100 ( V_1 , V_18 , V_99 ) ;
}
}
T_6
F_103 ( T_1 * V_1 , T_7 V_44 , const T_8 V_45 )
{
return ( T_6 ) F_104 ( V_1 , V_44 , V_45 ) ;
}
void
F_105 ( T_1 * V_1 , T_7 V_44 , T_8 V_45 , T_6 * V_53 , T_9 V_105 )
{
T_6 V_106 , V_107 ;
T_8 V_18 = V_44 >> 3 ;
V_44 = V_44 & 0x7 ;
V_106 = ( V_105 ) ? 0xff : V_108 [ V_44 ] ;
V_107 = ( V_105 ) ? V_44 : ( 8 - V_44 ) ;
if ( F_106 ( V_44 != 0 ) ) {
T_16 V_109 = ( T_16 ) F_59 ( V_1 , V_18 ) ;
while ( V_45 >= 8 ) {
V_18 ++ ;
V_109 = ( ( V_109 & V_106 ) << 8 ) | F_59 ( V_1 , V_18 ) ;
if ( V_105 )
* V_53 ++ = ( T_6 ) ( F_107 ( V_109 ) >> V_107 ) ;
else
* V_53 ++ = ( T_6 ) ( V_109 >> V_107 ) ;
V_45 -= 8 ;
}
if ( V_45 > 0 ) {
T_6 V_110 = V_44 + V_45 ;
if ( V_110 > 8 ) {
V_18 ++ ;
V_109 = ( ( V_109 & V_106 ) << 8 ) | F_59 ( V_1 , V_18 ) ;
}
if ( V_105 ) {
if ( V_110 > 8 )
V_109 = ( F_107 ( V_109 ) >> V_44 ) & ( V_111 [ V_45 ] ) ;
else
V_109 = ( V_109 >> V_44 ) & ( V_111 [ V_45 ] ) ;
} else {
if ( V_110 > 8 )
V_109 = V_109 >> ( 16 - V_110 ) ;
else
V_109 = ( V_109 & V_106 ) >> ( 8 - V_110 ) ;
}
* V_53 = ( T_6 ) V_109 ;
}
} else {
while ( V_45 >= 8 ) {
* V_53 ++ = F_59 ( V_1 , V_18 ) ;
V_18 ++ ;
V_45 -= 8 ;
}
if ( V_45 > 0 ) {
if ( V_105 )
* V_53 = F_59 ( V_1 , V_18 ) & V_111 [ V_45 ] ;
else
* V_53 = F_59 ( V_1 , V_18 ) >> ( 8 - V_45 ) ;
}
}
}
T_6 *
F_108 ( T_1 * V_1 , T_7 V_44 , T_8 V_45 , T_9 V_105 )
{
T_8 V_112 ;
T_6 * V_53 ;
if ( V_45 < 0 ) {
F_3 () ;
}
V_112 = ( V_45 >> 3 ) + ( ( V_45 & 0x7 ) != 0 ) ;
V_53 = ( T_6 * ) F_58 ( V_112 ) ;
F_105 ( V_1 , V_44 , V_45 , V_53 , V_105 ) ;
return V_53 ;
}
T_16
F_109 ( T_1 * V_1 , T_7 V_44 , const T_8 V_45 , const T_7 T_22 V_113 )
{
return ( T_16 ) F_104 ( V_1 , V_44 , V_45 ) ;
}
T_10
F_110 ( T_1 * V_1 , T_7 V_44 , const T_8 V_45 , const T_7 T_22 V_113 )
{
return ( T_10 ) F_104 ( V_1 , V_44 , V_45 ) ;
}
T_17
F_111 ( T_1 * V_1 , T_7 V_44 , const T_8 V_45 , const T_7 T_22 V_113 )
{
return F_104 ( V_1 , V_44 , V_45 ) ;
}
static T_17
F_104 ( T_1 * V_1 , T_7 V_44 , const T_8 V_114 )
{
T_17 V_109 ;
T_7 V_115 = V_44 >> 3 ;
T_6 V_116 = 8 - ( V_44 % 8 ) ;
if( V_116 > V_114 )
{
T_6 V_117 = V_116 - V_114 ;
V_109 = ( F_59 ( V_1 , V_115 ) >> V_117 ) & V_111 [ V_114 % 8 ] ;
}
else
{
T_6 V_118 = V_114 ;
V_109 = 0 ;
V_116 %= 8 ;
if( V_116 != 0 )
{
V_109 = F_59 ( V_1 , V_115 ) & V_111 [ V_116 ] ;
V_118 -= V_116 ;
V_115 ++ ;
}
while ( V_118 > 7 )
{
switch ( V_118 >> 4 )
{
case 0 :
V_109 <<= 8 ;
V_109 += F_59 ( V_1 , V_115 ) ;
V_118 -= 8 ;
V_115 ++ ;
break;
case 1 :
V_109 <<= 16 ;
V_109 += F_60 ( V_1 , V_115 ) ;
V_118 -= 16 ;
V_115 += 2 ;
break;
case 2 :
case 3 :
V_109 <<= 32 ;
V_109 += F_64 ( V_1 , V_115 ) ;
V_118 -= 32 ;
V_115 += 4 ;
break;
default:
V_109 = F_72 ( V_1 , V_115 ) ;
V_118 -= 64 ;
V_115 += 8 ;
break;
}
}
if( V_118 )
{
V_109 <<= V_118 ;
V_109 += ( F_59 ( V_1 , V_115 ) >> ( 8 - V_118 ) ) ;
}
}
return V_109 ;
}
T_10
F_112 ( T_1 * V_1 , const T_7 V_44 , const T_8 V_45 , const T_7 T_22 V_113 )
{
return ( T_10 ) F_104 ( V_1 , V_44 , V_45 ) ;
}
T_8
F_113 ( T_1 * V_1 , const T_8 V_18 , const T_8 V_119 , const T_6 V_120 )
{
const T_6 * V_121 ;
T_7 V_59 , V_122 ;
T_7 V_123 ;
T_7 V_124 ;
F_5 ( V_1 && V_1 -> V_6 ) ;
F_20 ( V_1 , V_18 , 0 , & V_59 , & V_122 ) ;
V_123 = F_25 ( V_1 , V_59 ) ;
if ( V_119 == - 1 ) {
V_124 = V_123 ;
}
else if ( V_123 < ( T_7 ) V_119 ) {
V_124 = V_123 ;
}
else {
V_124 = V_119 ;
}
if ( V_1 -> V_11 ) {
V_121 = ( const T_6 * ) memchr ( V_1 -> V_11 + V_59 , V_120 , V_124 ) ;
if ( V_121 == NULL ) {
return - 1 ;
}
else {
return ( T_8 ) ( V_121 - V_1 -> V_11 ) ;
}
}
switch( V_1 -> type ) {
case V_14 :
F_3 () ;
case V_15 :
return F_113 ( V_1 -> V_16 . V_17 . V_1 ,
V_59 - V_1 -> V_16 . V_17 . V_18 ,
V_124 , V_120 ) ;
case V_19 :
F_3 () ;
}
F_3 () ;
return - 1 ;
}
T_8
F_114 ( T_1 * V_1 , const T_8 V_18 , const T_8 V_119 , const T_6 * V_68 , T_14 * V_69 )
{
const T_6 * V_121 ;
T_7 V_59 , V_122 ;
T_7 V_123 ;
T_7 V_124 ;
F_5 ( V_1 && V_1 -> V_6 ) ;
F_20 ( V_1 , V_18 , 0 , & V_59 , & V_122 ) ;
V_123 = F_25 ( V_1 , V_59 ) ;
if ( V_119 == - 1 ) {
V_124 = V_123 ;
}
else if ( V_123 < ( T_7 ) V_119 ) {
V_124 = V_123 ;
}
else {
V_124 = V_119 ;
}
if ( V_1 -> V_11 ) {
V_121 = F_54 ( V_1 -> V_11 + V_59 , V_124 , V_68 , V_69 ) ;
if ( V_121 == NULL ) {
return - 1 ;
}
else {
return ( T_8 ) ( V_121 - V_1 -> V_11 ) ;
}
}
switch( V_1 -> type ) {
case V_14 :
F_3 () ;
case V_15 :
return F_114 ( V_1 -> V_16 . V_17 . V_1 ,
V_59 - V_1 -> V_16 . V_17 . V_18 ,
V_124 , V_68 , V_69 ) ;
case V_19 :
F_3 () ;
}
F_3 () ;
return - 1 ;
}
T_7
F_115 ( T_1 * V_1 , const T_8 V_18 )
{
T_7 V_59 , V_122 ;
T_8 V_125 ;
F_5 ( V_1 && V_1 -> V_6 ) ;
F_20 ( V_1 , V_18 , 0 , & V_59 , & V_122 ) ;
V_125 = F_113 ( V_1 , V_59 , - 1 , 0 ) ;
if ( V_125 == - 1 ) {
if ( V_1 -> V_8 < V_1 -> V_9 ) {
F_21 ( V_36 ) ;
} else {
if ( V_1 -> V_7 & V_34 ) {
F_21 ( V_35 ) ;
} else {
F_21 ( V_29 ) ;
}
}
}
return ( V_125 - V_59 ) + 1 ;
}
T_7
F_116 ( T_1 * V_1 , const T_8 V_18 )
{
T_7 V_49 = 0 ;
T_23 V_126 ;
F_5 ( V_1 && V_1 -> V_6 ) ;
do {
V_126 = F_60 ( V_1 , V_18 + V_49 ) ;
V_49 += 2 ;
} while( V_126 != 0 );
return V_49 ;
}
T_8
F_117 ( T_1 * V_1 , const T_8 V_18 , const T_7 V_119 )
{
T_8 V_127 ;
T_7 V_59 , V_122 ;
F_5 ( V_1 && V_1 -> V_6 ) ;
F_20 ( V_1 , V_18 , 0 , & V_59 , & V_122 ) ;
V_127 = F_113 ( V_1 , V_59 , V_119 , 0 ) ;
if ( V_127 == - 1 ) {
return - 1 ;
}
else {
return V_127 - V_59 ;
}
}
T_8
F_118 ( T_1 * V_1 , const T_8 V_18 , const T_15 * V_128 , const T_13 V_129 )
{
const T_6 * V_75 ;
V_75 = F_50 ( V_1 , V_18 , ( T_8 ) V_129 , NULL ) ;
if ( V_75 ) {
int V_130 = strncmp ( ( const char * ) V_75 , V_128 , V_129 ) ;
return ( V_130 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_8
F_119 ( T_1 * V_1 , const T_8 V_18 , const T_15 * V_128 , const T_13 V_129 )
{
const T_6 * V_75 ;
V_75 = F_50 ( V_1 , V_18 , ( T_8 ) V_129 , NULL ) ;
if ( V_75 ) {
int V_130 = F_120 ( ( const char * ) V_75 , V_128 , V_129 ) ;
return ( V_130 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
T_8
F_121 ( T_1 * V_1 , const T_8 V_18 , const T_6 * V_128 , T_13 V_129 )
{
const T_6 * V_75 ;
V_75 = F_50 ( V_1 , V_18 , ( T_8 ) V_129 , NULL ) ;
if ( V_75 ) {
int V_130 = memcmp ( V_75 , V_128 , V_129 ) ;
return ( V_130 == 0 ? 0 : - 1 ) ;
} else {
return - 1 ;
}
}
char *
F_122 ( T_1 * V_1 , int V_18 , const int V_131 , const T_9 V_132 )
{
char * V_133 ;
int V_49 ;
T_16 V_134 ;
F_41 ( V_1 , V_18 , 2 * V_131 ) ;
V_133 = ( char * ) F_29 ( V_131 + 1 ) ;
for ( V_49 = 0 ; V_49 < V_131 ; V_49 ++ ) {
V_134 = V_132 ? F_82 ( V_1 , V_18 )
: F_60 ( V_1 , V_18 ) ;
V_133 [ V_49 ] = V_134 < 256 ? V_134 : '.' ;
V_18 += 2 ;
}
V_133 [ V_131 ] = 0 ;
return V_133 ;
}
char *
F_123 ( T_1 * V_1 , int V_18 , const int V_131 , const T_9 V_132 )
{
char * V_133 ;
int V_49 ;
T_16 V_134 ;
F_41 ( V_1 , V_18 , 2 * V_131 ) ;
V_133 = ( char * ) F_58 ( V_131 + 1 ) ;
for ( V_49 = 0 ; V_49 < V_131 ; V_49 ++ ) {
V_134 = V_132 ? F_82 ( V_1 , V_18 )
: F_60 ( V_1 , V_18 ) ;
V_133 [ V_49 ] = V_134 < 256 ? V_134 : '.' ;
V_18 += 2 ;
}
V_133 [ V_131 ] = 0 ;
return V_133 ;
}
T_15 *
F_124 ( T_1 * V_1 , const T_8 V_18 , const T_8 V_129 )
{
const T_6 * V_75 ;
T_8 V_131 = V_129 ;
if ( ( V_75 = F_52 ( V_1 , V_18 , V_129 ) ) == NULL ) {
V_131 = F_25 ( V_1 , V_18 ) ;
V_75 = F_52 ( V_1 , V_18 , V_131 ) ;
}
return F_125 ( V_75 , V_131 ) ;
}
T_15 *
F_126 ( T_1 * V_1 , const T_8 V_18 , const T_8 V_129 )
{
const T_6 * V_75 ;
T_8 V_131 = V_129 ;
if ( ( V_75 = F_52 ( V_1 , V_18 , V_129 ) ) == NULL ) {
V_131 = F_25 ( V_1 , V_18 ) ;
V_75 = F_52 ( V_1 , V_18 , V_131 ) ;
}
return F_127 ( V_75 , V_131 ) ;
}
T_15 *
F_128 ( T_1 * V_1 , const T_8 V_18 , const T_8 V_129 )
{
const T_6 * V_75 , * V_64 ;
T_8 V_131 = V_129 ;
T_8 V_135 ;
if ( ( V_75 = F_52 ( V_1 , V_18 , V_129 ) ) == NULL ) {
V_131 = F_25 ( V_1 , V_18 ) ;
V_75 = F_52 ( V_1 , V_18 , V_131 ) ;
}
for ( V_64 = V_75 , V_135 = 0 ; V_135 < V_131 && * V_64 != '\0' ; V_64 ++ , V_135 ++ )
;
return F_125 ( V_75 , V_135 ) ;
}
T_15 *
F_129 ( T_1 * V_1 , const T_8 V_18 , const T_8 V_129 )
{
const T_6 * V_75 , * V_64 ;
T_8 V_131 = V_129 ;
T_8 V_135 ;
if ( ( V_75 = F_52 ( V_1 , V_18 , V_129 ) ) == NULL ) {
V_131 = F_25 ( V_1 , V_18 ) ;
V_75 = F_52 ( V_1 , V_18 , V_131 ) ;
}
for ( V_64 = V_75 , V_135 = 0 ; V_135 < V_131 && * V_64 != '\0' ; V_64 ++ , V_135 ++ )
;
return F_127 ( V_75 , V_135 ) ;
}
T_6 *
F_130 ( T_1 * V_1 , const T_8 V_18 , const T_8 V_8 )
{
const T_6 * V_75 ;
T_6 * V_136 = NULL ;
F_41 ( V_1 , V_18 , V_8 ) ;
V_75 = F_52 ( V_1 , V_18 , V_8 ) ;
V_136 = ( T_6 * ) F_29 ( V_8 + 1 ) ;
if ( V_8 != 0 ) {
memcpy ( V_136 , V_75 , V_8 ) ;
}
V_136 [ V_8 ] = '\0' ;
return V_136 ;
}
T_15 *
F_131 ( T_1 * V_1 , const T_8 V_18 , T_8 V_8 , const T_7 T_22 )
{
T_23 V_126 ;
T_8 V_49 ;
T_24 * V_136 = NULL ;
F_41 ( V_1 , V_18 , V_8 ) ;
V_136 = F_132 ( NULL ) ;
for( V_49 = 0 ; V_49 < V_8 ; V_49 += 2 ) {
if ( T_22 == V_137 )
V_126 = F_60 ( V_1 , V_18 + V_49 ) ;
else
V_126 = F_82 ( V_1 , V_18 + V_49 ) ;
F_133 ( V_136 , V_126 ) ;
}
return F_134 ( V_136 , FALSE ) ;
}
T_6 *
F_135 ( T_1 * V_1 , const T_8 V_18 ,
const T_8 V_8 , const T_7 T_22 )
{
const T_6 * V_75 ;
T_6 * V_136 ;
switch ( T_22 & V_138 ) {
case V_139 :
default:
V_136 = F_136 ( V_1 , V_18 , V_8 ) ;
break;
case V_140 :
V_136 = F_136 ( V_1 , V_18 , V_8 ) ;
break;
case V_141 :
V_136 = F_137 ( V_1 , V_18 , V_8 ,
T_22 & V_142 ) ;
break;
case V_143 :
V_136 = F_137 ( V_1 , V_18 , V_8 ,
T_22 & V_142 ) ;
break;
case V_144 :
F_41 ( V_1 , V_18 , V_8 ) ;
V_136 = ( T_6 * ) F_58 ( V_8 + 1 ) ;
if ( V_8 != 0 ) {
V_75 = F_52 ( V_1 , V_18 , V_8 ) ;
memcpy ( V_136 , V_75 , V_8 ) ;
F_138 ( V_136 , V_8 ) ;
}
V_136 [ V_8 ] = '\0' ;
break;
}
return V_136 ;
}
T_6 *
F_136 ( T_1 * V_1 , const T_8 V_18 , const T_8 V_8 )
{
T_6 * V_136 ;
F_41 ( V_1 , V_18 , V_8 ) ;
V_136 = ( T_6 * ) F_58 ( V_8 + 1 ) ;
F_56 ( V_1 , V_136 , V_18 , V_8 ) ;
V_136 [ V_8 ] = '\0' ;
return V_136 ;
}
T_15 *
F_137 ( T_1 * V_1 , const T_8 V_18 , T_8 V_8 , const T_7 T_22 )
{
T_15 V_145 [ 8 ] ;
T_23 V_126 ;
T_8 V_49 ;
T_8 V_146 ;
T_25 * V_136 = NULL ;
F_41 ( V_1 , V_18 , V_8 ) ;
V_136 = F_139 ( NULL ) ;
for( V_49 = 0 ; V_49 < V_8 ; V_49 += 2 ) {
if ( T_22 == V_137 )
V_126 = F_60 ( V_1 , V_18 + V_49 ) ;
else
V_126 = F_82 ( V_1 , V_18 + V_49 ) ;
V_146 = F_140 ( V_126 , V_145 ) ;
V_145 [ V_146 ] = '\0' ;
F_141 ( V_136 , V_145 ) ;
}
return V_136 -> V_128 ;
}
T_6 *
F_142 ( T_1 * V_1 , const T_8 V_18 , const T_8 V_8 )
{
const T_6 * V_75 ;
T_6 * V_136 = NULL ;
F_41 ( V_1 , V_18 , V_8 ) ;
V_75 = F_52 ( V_1 , V_18 , V_8 ) ;
V_136 = ( T_6 * ) F_143 ( V_8 + 1 ) ;
if ( V_8 != 0 ) {
memcpy ( V_136 , V_75 , V_8 ) ;
}
V_136 [ V_8 ] = '\0' ;
return V_136 ;
}
T_6 *
F_144 ( T_1 * V_1 , const T_8 V_18 , T_8 * V_147 , const T_7 T_22 )
{
T_7 V_129 ;
T_6 * V_148 ;
V_129 = F_115 ( V_1 , V_18 ) ;
V_148 = ( T_6 * ) F_29 ( V_129 ) ;
F_56 ( V_1 , V_148 , V_18 , V_129 ) ;
if ( ( T_22 & V_138 ) == V_144 )
F_138 ( V_148 , V_129 ) ;
if ( V_147 )
* V_147 = V_129 ;
return V_148 ;
}
T_6 *
F_145 ( T_1 * V_1 , const T_8 V_18 , T_8 * V_147 )
{
return F_144 ( V_1 , V_18 , V_147 , V_140 | V_149 ) ;
}
const T_6 *
F_146 ( T_1 * V_1 , const T_8 V_18 , T_8 * V_147 )
{
T_7 V_129 ;
const T_6 * V_148 ;
V_129 = F_115 ( V_1 , V_18 ) ;
V_148 = F_52 ( V_1 , V_18 , V_129 ) ;
if ( V_147 )
* V_147 = V_129 ;
return V_148 ;
}
T_6 *
F_147 ( T_1 * V_1 , const T_8 V_18 , T_8 * V_147 , const T_7 T_22 )
{
T_7 V_129 ;
T_6 * V_148 ;
switch ( T_22 & V_138 ) {
case V_139 :
default:
V_148 = F_148 ( V_1 , V_18 , V_147 ) ;
break;
case V_140 :
V_148 = F_148 ( V_1 , V_18 , V_147 ) ;
break;
case V_141 :
V_148 = F_149 ( V_1 , V_18 , V_147 ,
T_22 & V_142 ) ;
break;
case V_143 :
V_148 = F_149 ( V_1 , V_18 , V_147 ,
T_22 & V_142 ) ;
break;
case V_144 :
V_129 = F_115 ( V_1 , V_18 ) ;
V_148 = ( T_6 * ) F_58 ( V_129 ) ;
F_56 ( V_1 , V_148 , V_18 , V_129 ) ;
F_138 ( V_148 , V_129 ) ;
if ( V_147 )
* V_147 = V_129 ;
break;
}
return V_148 ;
}
T_6 *
F_148 ( T_1 * V_1 , const T_8 V_18 , T_8 * V_147 )
{
T_7 V_129 ;
T_6 * V_148 ;
V_129 = F_115 ( V_1 , V_18 ) ;
V_148 = ( T_6 * ) F_58 ( V_129 ) ;
F_56 ( V_1 , V_148 , V_18 , V_129 ) ;
if ( V_147 )
* V_147 = V_129 ;
return V_148 ;
}
T_15 *
F_149 ( T_1 * V_1 , const T_8 V_18 , T_8 * V_147 , const T_7 T_22 )
{
T_15 V_145 [ 8 ] ;
T_23 V_126 ;
T_8 V_129 ;
T_8 V_49 ;
T_8 V_146 ;
T_25 * V_136 = NULL ;
V_136 = F_139 ( NULL ) ;
V_129 = F_116 ( V_1 , V_18 ) ;
for( V_49 = 0 ; V_49 < V_129 ; V_49 += 2 ) {
if ( T_22 == V_137 )
V_126 = F_60 ( V_1 , V_18 + V_49 ) ;
else
V_126 = F_82 ( V_1 , V_18 + V_49 ) ;
V_146 = F_140 ( V_126 , V_145 ) ;
V_145 [ V_146 ] = '\0' ;
F_141 ( V_136 , V_145 ) ;
}
if ( V_147 )
* V_147 = V_49 ;
return V_136 -> V_128 ;
}
T_6 *
F_150 ( T_1 * V_1 , const T_8 V_18 , T_8 * V_147 )
{
T_7 V_129 ;
T_6 * V_148 ;
V_129 = F_115 ( V_1 , V_18 ) ;
V_148 = ( T_6 * ) F_143 ( V_129 ) ;
F_56 ( V_1 , V_148 , V_18 , V_129 ) ;
if ( V_147 )
* V_147 = V_129 ;
return V_148 ;
}
static T_8
F_151 ( T_1 * V_1 , const T_8 V_18 , const T_7 V_150 , T_6 * V_133 , T_8 * V_151 )
{
T_8 V_135 ;
T_7 V_59 , V_122 ;
T_8 V_124 , V_131 ;
T_9 V_152 = FALSE ;
F_20 ( V_1 , V_18 , 0 , & V_59 , & V_122 ) ;
F_5 ( V_150 != 0 ) ;
if ( V_150 == 1 ) {
V_133 [ 0 ] = 0 ;
* V_151 = 1 ;
return 0 ;
}
V_131 = F_25 ( V_1 , V_59 ) ;
if ( V_131 == 0 ) {
F_21 ( V_29 ) ;
}
F_5 ( V_131 != - 1 ) ;
F_5 ( V_150 <= V_153 ) ;
if ( ( T_7 ) V_131 < V_150 ) {
V_124 = V_131 ;
V_152 = TRUE ;
}
else {
V_124 = V_150 ;
}
V_135 = F_117 ( V_1 , V_59 , V_124 - 1 ) ;
if ( V_135 == - 1 ) {
F_56 ( V_1 , V_133 , V_59 , V_124 ) ;
if ( V_152 ) {
V_133 [ V_124 ] = 0 ;
* V_151 = V_124 + 1 ;
}
else {
* V_151 = V_124 ;
}
return - 1 ;
}
F_56 ( V_1 , V_133 , V_59 , V_135 + 1 ) ;
* V_151 = V_135 + 1 ;
return V_135 ;
}
T_8
F_152 ( T_1 * V_1 , const T_8 V_18 , const T_7 V_150 , T_6 * V_133 )
{
T_8 V_151 ;
F_5 ( V_1 && V_1 -> V_6 ) ;
return F_151 ( V_1 , V_18 , V_150 , V_133 , & V_151 ) ;
}
T_8
F_153 ( T_1 * V_1 , const T_8 V_18 , const T_7 V_150 , T_6 * V_133 )
{
T_8 V_131 , V_151 ;
F_5 ( V_1 && V_1 -> V_6 ) ;
V_131 = F_151 ( V_1 , V_18 , V_150 , V_133 , & V_151 ) ;
if ( V_131 == - 1 ) {
V_133 [ V_150 - 1 ] = 0 ;
return V_151 - 1 ;
}
else {
return V_131 ;
}
}
T_8
F_154 ( T_1 * V_1 , const T_8 V_18 , int V_131 , T_8 * V_154 , const T_9 V_155 )
{
T_8 V_156 ;
T_8 V_157 ;
int V_158 ;
T_14 V_69 = 0 ;
if ( V_131 == - 1 )
V_131 = F_25 ( V_1 , V_18 ) ;
V_156 = V_18 + V_131 ;
V_157 = F_114 ( V_1 , V_18 , V_131 , L_3 , & V_69 ) ;
if ( V_157 == - 1 ) {
if ( V_155 ) {
return - 1 ;
} else {
V_158 = V_156 - V_18 ;
if ( V_154 )
* V_154 = V_156 ;
}
} else {
V_158 = V_157 - V_18 ;
if ( V_69 == '\r' ) {
if ( V_157 + 1 >= V_156 ) {
if ( V_155 ) {
return - 1 ;
}
} else {
if ( F_59 ( V_1 , V_157 + 1 ) == '\n' ) {
V_157 ++ ;
}
}
}
if ( V_154 )
* V_154 = V_157 + 1 ;
}
return V_158 ;
}
T_8
F_155 ( T_1 * V_1 , const T_8 V_18 , int V_131 , T_8 * V_154 )
{
T_8 V_159 , V_160 ;
T_9 V_161 ;
T_14 V_162 = 0 ;
T_8 V_156 ;
int V_158 ;
if ( V_131 == - 1 )
V_131 = F_25 ( V_1 , V_18 ) ;
V_156 = V_18 + V_131 ;
V_159 = V_18 ;
V_161 = FALSE ;
for (; ; ) {
if ( V_161 ) {
V_160 = F_113 ( V_1 , V_159 , V_131 ,
'"' ) ;
} else {
V_160 = F_114 ( V_1 , V_159 , V_131 , L_4 , & V_162 ) ;
}
if ( V_160 == - 1 ) {
V_158 = V_156 - V_18 ;
if ( V_154 )
* V_154 = V_156 ;
break;
}
if ( V_161 ) {
V_161 = FALSE ;
} else {
if ( V_162 == '"' ) {
V_161 = TRUE ;
} else {
V_158 = V_160 - V_18 ;
if ( V_162 == '\r' ) {
if ( V_160 + 1 < V_156 &&
F_59 ( V_1 , V_160 + 1 )
== '\n' ) {
V_160 ++ ;
}
}
if ( V_154 )
* V_154 = V_160 + 1 ;
break;
}
}
V_159 = V_160 + 1 ;
if ( V_159 >= V_156 ) {
V_158 = V_156 - V_18 ;
if ( V_154 )
* V_154 = V_156 ;
break;
}
}
return V_158 ;
}
T_8
F_156 ( T_1 * V_1 , const T_8 V_18 , const T_8 V_119 )
{
T_8 V_61 = V_18 ;
T_8 V_163 , V_164 ;
T_6 V_165 ;
V_164 = F_38 ( V_1 ) ;
V_163 = V_18 + V_119 ;
if ( V_163 >= V_164 )
{
V_163 = V_164 ;
}
for ( V_61 = V_18 ;
V_61 < V_163 &&
( ( V_165 = F_59 ( V_1 , V_61 ) ) == ' ' ||
V_165 == '\t' || V_165 == '\r' || V_165 == '\n' ) ;
V_61 ++ ) ;
return ( V_61 ) ;
}
T_8
F_157 ( T_1 * V_1 , const T_8 V_18 ) {
T_8 V_61 = V_18 ;
T_8 V_163 ;
T_6 V_165 ;
V_163 = 0 ;
for( V_61 = V_18 ; V_61 > V_163 &&
( ( V_165 = F_59 ( V_1 , V_61 ) ) == ' ' ||
V_165 == '\t' || V_165 == '\n' || V_165 == '\r' ) ; V_61 -- ) ;
V_61 ++ ;
return ( V_61 ) ;
}
T_15 *
F_158 ( T_1 * V_1 , const T_8 V_18 , const T_8 V_131 , const T_15 V_166 )
{
return F_159 ( F_52 ( V_1 , V_18 , V_131 ) , V_131 , V_166 ) ;
}
const T_15 *
F_160 ( T_1 * V_1 , const T_8 V_18 , const T_8 V_131 , T_26 * V_167 , T_9 V_168 )
{
int V_8 ;
T_6 V_169 ;
int V_49 = 0 ;
char * V_170 ;
T_8 V_171 = V_18 ;
if ( ! V_167 )
V_167 = & V_172 ;
if ( V_131 == - 1 ) {
V_8 = F_38 ( V_1 ) ;
if ( V_8 < V_18 ) {
return L_5 ;
}
} else {
V_8 = V_18 + V_131 ;
}
V_170 = ( char * ) F_58 ( ( V_8 - V_18 ) * 2 + 1 ) ;
while ( V_171 < V_8 ) {
V_169 = F_59 ( V_1 , V_171 ) ;
if ( ! V_168 ) {
V_170 [ V_49 ] = V_167 -> V_173 [ V_169 & 0x0f ] ;
V_49 ++ ;
}
V_168 = FALSE ;
V_169 = V_169 >> 4 ;
if ( V_169 == 0x0f )
break;
V_170 [ V_49 ] = V_167 -> V_173 [ V_169 & 0x0f ] ;
V_49 ++ ;
V_171 ++ ;
}
V_170 [ V_49 ] = '\0' ;
return V_170 ;
}
T_15 *
F_161 ( T_1 * V_1 , const T_8 V_18 , const T_8 V_131 )
{
return F_162 ( F_52 ( V_1 , V_18 , V_131 ) , V_131 ) ;
}
T_8
F_163 ( T_1 * V_174 , T_1 * V_175 , const T_8 V_176 )
{
T_7 V_177 , V_178 ;
const T_6 * V_179 ;
const T_6 * V_180 ;
const T_7 V_181 = V_175 -> V_8 ;
const T_6 * V_182 ;
F_5 ( V_174 && V_174 -> V_6 ) ;
if ( V_174 -> V_8 < 1 || V_175 -> V_8 < 1 ) {
return - 1 ;
}
V_179 = F_52 ( V_174 , 0 , - 1 ) ;
V_180 = F_52 ( V_175 , 0 , - 1 ) ;
F_20 ( V_174 , V_176 , - 1 ,
& V_177 , & V_178 ) ;
V_182 = F_164 ( V_179 + V_177 , V_178 ,
V_180 , V_181 ) ;
if ( V_182 ) {
return ( T_8 ) ( V_182 - V_179 ) ;
}
return - 1 ;
}
T_1 *
F_165 ( T_1 * V_1 , const int V_18 , int V_183 )
{
T_8 V_184 = V_185 ;
T_7 V_186 = 0 ;
T_6 * V_187 = NULL ;
T_6 * V_188 = NULL ;
T_1 * V_189 = NULL ;
T_27 V_190 = NULL ;
T_28 * V_191 = NULL ;
T_7 V_192 = 0 ;
T_8 V_193 = V_194 ;
T_6 * V_5 = NULL ;
T_7 V_195 = V_196 ;
#ifdef F_166
T_7 V_197 = 0 ;
T_7 V_198 = F_25 ( V_1 , V_18 ) ;
#endif
if ( V_1 == NULL ) {
return NULL ;
}
V_187 = ( T_6 * ) F_51 ( V_1 , V_18 , V_183 ) ;
if ( ! V_187 )
return NULL ;
V_195 = F_25 ( V_1 , V_18 ) * 2 ;
V_195 = F_167 ( V_195 , V_196 , V_199 ) ;
#ifdef F_166
printf ( L_6 , V_195 ) ;
#endif
V_5 = V_187 ;
V_190 = F_168 ( V_200 , 1 ) ;
V_190 -> V_201 = V_5 ;
V_190 -> V_202 = V_183 ;
V_191 = ( T_28 * ) F_169 ( V_195 ) ;
V_190 -> V_203 = V_191 ;
V_190 -> V_204 = V_195 ;
V_184 = F_170 ( V_190 , V_193 ) ;
V_192 = 1 ;
if ( V_184 != V_185 ) {
F_171 ( V_190 ) ;
F_7 ( V_190 ) ;
F_7 ( V_187 ) ;
F_7 ( V_191 ) ;
return NULL ;
}
while ( 1 ) {
memset ( V_191 , '\0' , V_195 ) ;
V_190 -> V_203 = V_191 ;
V_190 -> V_204 = V_195 ;
V_184 = F_172 ( V_190 , V_205 ) ;
if ( V_184 == V_185 || V_184 == V_206 ) {
T_7 V_207 = V_195 - V_190 -> V_204 ;
#ifdef F_166
++ V_197 ;
#endif
if ( V_188 == NULL ) {
V_188 = ( T_6 * ) ( ( V_207 || V_184 != V_206 ) ?
F_173 ( V_191 , V_207 ) :
F_174 ( L_5 ) ) ;
} else {
T_6 * V_208 = ( T_6 * ) F_169 ( V_186 + V_207 ) ;
memcpy ( V_208 , V_188 , V_186 ) ;
memcpy ( V_208 + V_186 , V_191 , V_207 ) ;
F_7 ( V_188 ) ;
V_188 = V_208 ;
}
V_186 += V_207 ;
if ( V_184 == V_206 ) {
F_171 ( V_190 ) ;
F_7 ( V_190 ) ;
F_7 ( V_191 ) ;
break;
}
} else if ( V_184 == V_209 ) {
F_171 ( V_190 ) ;
F_7 ( V_190 ) ;
F_7 ( V_191 ) ;
if ( V_188 != NULL ) {
break;
} else {
F_7 ( V_187 ) ;
return NULL ;
}
} else if ( V_184 == V_210 && V_192 == 1
&& V_188 == NULL && ( * V_187 == 0x1f ) &&
( * ( V_187 + 1 ) == 0x8b ) ) {
T_28 * V_162 = V_187 + 2 ;
T_28 V_7 = 0 ;
if ( * V_162 == V_211 ) {
V_162 ++ ;
} else {
F_171 ( V_190 ) ;
F_7 ( V_190 ) ;
F_7 ( V_187 ) ;
F_7 ( V_191 ) ;
return NULL ;
}
V_7 = * V_162 ;
V_162 += 7 ;
if ( V_7 & ( 1 << 2 ) ) {
T_8 V_212 = ( T_8 ) ( * V_162 |
( * ( V_162 + 1 ) << 8 ) ) ;
V_162 += V_212 ;
}
if ( V_7 & ( 1 << 3 ) ) {
while ( ( V_162 - V_187 ) < V_183 && * V_162 != '\0' ) {
V_162 ++ ;
}
V_162 ++ ;
}
if ( V_7 & ( 1 << 4 ) ) {
while ( ( V_162 - V_187 ) < V_183 && * V_162 != '\0' ) {
V_162 ++ ;
}
V_162 ++ ;
}
F_175 ( V_190 ) ;
V_5 = V_162 ;
V_190 -> V_201 = V_5 ;
if ( V_162 - V_187 > V_183 ) {
F_171 ( V_190 ) ;
F_7 ( V_190 ) ;
F_7 ( V_187 ) ;
F_7 ( V_191 ) ;
return NULL ;
}
V_183 -= ( int ) ( V_162 - V_187 ) ;
F_171 ( V_190 ) ;
F_170 ( V_190 , V_193 ) ;
V_192 ++ ;
} else if ( V_184 == V_210 && V_188 == NULL &&
V_192 <= 3 ) {
V_193 = - V_194 ;
F_175 ( V_190 ) ;
V_190 -> V_201 = V_5 ;
V_190 -> V_202 = V_183 ;
F_171 ( V_190 ) ;
memset ( V_191 , '\0' , V_195 ) ;
V_190 -> V_203 = V_191 ;
V_190 -> V_204 = V_195 ;
V_184 = F_170 ( V_190 , V_193 ) ;
V_192 ++ ;
if ( V_184 != V_185 ) {
F_7 ( V_190 ) ;
F_7 ( V_191 ) ;
F_7 ( V_187 ) ;
F_7 ( V_188 ) ;
return NULL ;
}
} else {
F_171 ( V_190 ) ;
F_7 ( V_190 ) ;
F_7 ( V_191 ) ;
if ( V_188 == NULL ) {
F_7 ( V_187 ) ;
return NULL ;
}
break;
}
}
#ifdef F_166
printf ( L_7 , V_197 ) ;
printf ( L_8 , V_198 , V_186 ) ;
#endif
if ( V_188 != NULL ) {
V_189 = F_15 ( ( T_6 * ) V_188 , V_186 , V_186 ) ;
F_12 ( V_189 , F_7 ) ;
}
F_7 ( V_187 ) ;
return V_189 ;
}
T_1 *
F_165 ( T_1 * V_1 V_113 , const int V_18 V_113 , int V_183 V_113 )
{
return NULL ;
}
T_1 *
F_176 ( T_1 * V_26 , T_1 * V_1 , const int V_18 , int V_183 )
{
T_1 * V_213 = F_165 ( V_1 , V_18 , V_183 ) ;
if ( V_213 )
F_14 ( V_26 , V_213 ) ;
return V_213 ;
}
T_8
F_177 ( T_1 * V_1 )
{
return ( ( V_1 -> V_12 == - 1 ) ? ( V_1 -> V_12 = F_47 ( V_1 ) ) : V_1 -> V_12 ) ;
}
void
F_178 ( T_1 * V_1 )
{
V_1 -> V_7 |= V_34 ;
}
struct V_214 *
F_179 ( T_1 * V_1 )
{
return ( V_1 -> V_13 ) ;
}
