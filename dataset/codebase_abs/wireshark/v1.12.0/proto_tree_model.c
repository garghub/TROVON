static T_1
F_1 ( T_2 * V_1 )
{
F_2 ( F_3 ( V_1 ) , ( T_1 ) 0 ) ;
return V_2 ;
}
static T_3
F_4 ( T_2 * V_1 )
{
F_2 ( F_3 ( V_1 ) , 0 ) ;
return 2 ;
}
static T_4
F_5 ( T_2 * V_1 , T_3 V_3 )
{
F_2 ( F_3 ( V_1 ) , V_4 ) ;
F_2 ( V_3 == 0 || V_3 == 1 , V_4 ) ;
switch ( V_3 ) {
case 0 :
return V_5 ;
case 1 :
return V_6 ;
}
return V_4 ;
}
static T_5
F_6 ( T_2 * V_1 , T_6 * V_7 , T_6 * V_8 , T_3 V_9 )
{
T_7 * V_10 ;
T_8 * V_11 ;
F_2 ( F_3 ( V_1 ) , FALSE ) ;
V_10 = ( T_7 * ) V_1 ;
if ( V_8 ) {
F_2 ( V_8 -> V_12 == V_10 -> V_12 , FALSE ) ;
V_11 = ( T_8 * ) V_8 -> V_13 ;
} else
V_11 = V_10 -> V_14 ;
if ( ! V_11 )
return FALSE ;
V_11 = V_11 -> V_15 ;
while ( V_11 != NULL ) {
if ( V_10 -> V_16 || ! F_7 ( V_11 ) ) {
if ( ! V_9 )
break;
V_9 -- ;
}
V_11 = V_11 -> V_17 ;
}
if ( ! V_11 )
return FALSE ;
V_7 -> V_12 = V_10 -> V_12 ;
V_7 -> V_13 = V_11 ;
return TRUE ;
}
static T_5
F_8 ( T_2 * V_1 , T_6 * V_7 , T_9 * V_18 )
{
T_3 * V_19 , V_20 ;
F_9 ( F_3 ( V_1 ) ) ;
F_9 ( V_18 != NULL ) ;
V_19 = F_10 ( V_18 ) ;
V_20 = F_11 ( V_18 ) ;
F_2 ( V_20 > 0 , FALSE ) ;
if ( ! F_6 ( V_1 , V_7 , NULL , V_19 [ 0 ] ) )
return FALSE ;
while ( -- V_20 ) {
V_19 ++ ;
if ( ! F_6 ( V_1 , V_7 , V_7 , * V_19 ) )
return FALSE ;
}
return TRUE ;
}
static char *
F_12 ( T_10 * V_21 )
{
T_11 V_22 [ V_23 ] ;
T_11 * V_24 ;
if ( ! V_21 -> V_25 ) {
V_24 = V_22 ;
F_13 ( V_21 , V_22 ) ;
} else
V_24 = V_21 -> V_25 -> V_26 ;
if ( F_14 ( V_21 , V_27 ) ) {
if ( F_14 ( V_21 , V_28 ) )
V_24 = F_15 ( L_1 , V_24 ) ;
else
V_24 = F_15 ( L_2 , V_24 ) ;
} else if ( F_14 ( V_21 , V_28 ) )
V_24 = F_15 ( L_3 , V_24 ) ;
else
V_24 = F_16 ( V_24 ) ;
return V_24 ;
}
static void
F_17 ( T_2 * V_1 , T_6 * V_7 , T_3 V_29 , T_12 * V_30 )
{
T_7 * V_10 ;
T_8 * V_11 ;
T_10 * V_21 ;
F_18 ( F_3 ( V_1 ) ) ;
V_10 = ( T_7 * ) V_1 ;
F_18 ( V_7 != NULL ) ;
F_18 ( V_7 -> V_12 == V_10 -> V_12 ) ;
F_18 ( V_29 == 0 || V_29 == 1 ) ;
V_11 = ( T_8 * ) V_7 -> V_13 ;
V_21 = F_19 ( V_11 ) ;
F_9 ( V_21 ) ;
switch ( V_29 ) {
case 0 :
{
F_20 ( V_30 , V_5 ) ;
if ( V_10 -> V_31 ) {
T_13 V_32 = V_33 ;
V_33 = V_10 -> V_34 ;
F_21 ( V_30 , F_12 ( V_21 ) ) ;
V_33 = V_32 ;
} else
F_21 ( V_30 , F_12 ( V_21 ) ) ;
break;
}
case 1 :
F_20 ( V_30 , V_6 ) ;
F_22 ( V_30 , V_21 ) ;
break;
}
}
static T_5
F_23 ( T_2 * V_1 , T_6 * V_7 )
{
T_7 * V_10 ;
T_8 * V_35 ;
F_2 ( F_3 ( V_1 ) , FALSE ) ;
V_10 = ( T_7 * ) V_1 ;
F_2 ( V_7 -> V_12 == V_10 -> V_12 , FALSE ) ;
V_35 = ( T_8 * ) V_7 -> V_13 ;
V_35 = V_35 -> V_17 ;
while ( V_35 ) {
if ( V_10 -> V_16 || ! F_7 ( V_35 ) ) {
V_7 -> V_13 = V_35 ;
return TRUE ;
}
V_35 = V_35 -> V_17 ;
}
return FALSE ;
}
static T_5
F_24 ( T_2 * V_1 , T_6 * V_7 , T_6 * V_8 )
{
return F_6 ( V_1 , V_7 , V_8 , 0 ) ;
}
static T_3
F_25 ( T_2 * V_1 , T_6 * V_7 )
{
T_7 * V_10 ;
T_8 * V_11 ;
T_3 V_36 ;
F_2 ( F_3 ( V_1 ) , 0 ) ;
V_10 = ( T_7 * ) V_1 ;
F_2 ( V_7 == NULL || V_7 -> V_13 != NULL , 0 ) ;
if ( V_7 ) {
F_2 ( V_7 -> V_12 == V_10 -> V_12 , 0 ) ;
V_11 = ( T_8 * ) V_7 -> V_13 ;
} else
V_11 = V_10 -> V_14 ;
if ( ! V_11 )
return 0 ;
V_36 = 0 ;
V_11 = V_11 -> V_15 ;
while ( V_11 != NULL ) {
if ( V_10 -> V_16 || ! F_7 ( V_11 ) )
V_36 ++ ;
V_11 = V_11 -> V_17 ;
}
return V_36 ;
}
static T_9 *
F_26 ( T_2 * V_1 , T_6 * V_7 )
{
T_7 * V_10 ;
T_9 * V_18 ;
T_8 * V_11 ;
F_2 ( F_3 ( V_1 ) , NULL ) ;
V_10 = ( T_7 * ) V_1 ;
F_2 ( V_7 != NULL , NULL ) ;
F_2 ( V_7 -> V_12 == V_10 -> V_12 , NULL ) ;
V_11 = ( T_8 * ) V_7 -> V_13 ;
F_2 ( V_11 != V_10 -> V_14 , NULL ) ;
V_18 = F_27 () ;
do {
T_8 * V_37 = V_11 ;
T_8 * V_38 ;
int V_39 ;
V_11 = V_11 -> V_8 ;
V_39 = 0 ;
for ( V_38 = V_11 -> V_15 ; V_38 ; V_38 = V_38 -> V_17 ) {
if ( V_10 -> V_16 || ! F_7 ( V_38 ) ) {
if ( V_38 == V_37 )
break;
V_39 ++ ;
}
}
F_9 ( V_38 != NULL ) ;
F_28 ( V_18 , V_39 ) ;
} while ( V_11 != V_10 -> V_14 );
return V_18 ;
}
static T_5
F_29 ( T_2 * V_1 , T_6 * V_7 )
{
T_7 * V_10 ;
T_8 * V_11 ;
F_2 ( F_3 ( V_1 ) , FALSE ) ;
V_10 = ( T_7 * ) V_1 ;
F_2 ( V_7 == NULL || V_7 -> V_13 != NULL , FALSE ) ;
if ( V_7 ) {
F_2 ( V_7 -> V_12 == V_10 -> V_12 , FALSE ) ;
V_11 = ( T_8 * ) V_7 -> V_13 ;
} else
V_11 = V_10 -> V_14 ;
if ( ! V_11 )
return FALSE ;
V_11 = V_11 -> V_15 ;
while ( V_11 != NULL ) {
if ( V_10 -> V_16 || ! F_7 ( V_11 ) )
return TRUE ;
V_11 = V_11 -> V_17 ;
}
return FALSE ;
}
static T_5
F_30 ( T_2 * V_1 , T_6 * V_7 , T_6 * V_40 )
{
T_7 * V_10 ;
T_8 * V_11 ;
F_2 ( F_3 ( V_1 ) , FALSE ) ;
V_10 = ( T_7 * ) V_1 ;
F_2 ( V_7 != NULL , FALSE ) ;
F_2 ( V_40 -> V_12 == V_10 -> V_12 , FALSE ) ;
V_11 = ( T_8 * ) V_40 -> V_13 ;
if ( V_11 -> V_8 == V_10 -> V_14 )
return FALSE ;
F_2 ( V_11 -> V_8 != NULL , FALSE ) ;
V_7 -> V_12 = V_10 -> V_12 ;
V_7 -> V_13 = V_11 -> V_8 ;
return TRUE ;
}
static void
F_31 ( T_14 * V_41 )
{
V_41 -> V_42 = F_1 ;
V_41 -> V_43 = F_4 ;
V_41 -> V_44 = F_5 ;
V_41 -> V_45 = F_8 ;
V_41 -> V_46 = F_26 ;
V_41 -> V_47 = F_17 ;
V_41 -> V_48 = F_23 ;
V_41 -> V_49 = F_24 ;
V_41 -> V_50 = F_29 ;
V_41 -> V_51 = F_25 ;
V_41 -> V_52 = F_6 ;
V_41 -> V_53 = F_30 ;
}
static void
F_32 ( T_7 * V_10 )
{
V_10 -> V_12 = F_33 () ;
}
static void
F_34 ( T_15 * V_54 )
{
(* V_55 -> V_56 )( V_54 ) ;
}
static void
F_35 ( T_16 * V_57 )
{
T_17 * V_58 ;
V_55 = ( T_17 * ) F_36 ( V_57 ) ;
V_58 = ( T_17 * ) V_57 ;
V_58 -> V_56 = F_34 ;
}
T_4
F_37 ( void )
{
static T_4 V_59 = 0 ;
if ( V_59 == 0 ) {
static const T_18 V_60 = {
sizeof( T_16 ) ,
NULL ,
NULL ,
( V_61 ) F_35 ,
NULL ,
NULL ,
sizeof( T_7 ) ,
0 ,
( V_62 ) F_32 ,
NULL
} ;
static const T_19 V_63 = {
( V_64 ) F_31 ,
NULL ,
NULL
} ;
V_59 = F_38 ( V_65 ,
L_4 ,
& V_60 ,
( V_66 ) 0 ) ;
F_39 ( V_59 ,
V_67 ,
& V_63 ) ;
}
return V_59 ;
}
void
F_40 ( T_7 * V_10 , const T_13 * V_68 )
{
V_10 -> V_31 = TRUE ;
V_10 -> V_34 = * V_68 ;
}
T_7 *
F_41 ( T_20 * V_14 , int V_69 )
{
T_7 * V_10 ;
V_10 = ( T_7 * ) F_42 ( V_70 , NULL ) ;
F_9 ( V_10 != NULL ) ;
V_10 -> V_14 = V_14 ;
V_10 -> V_16 = V_69 ;
V_10 -> V_31 = FALSE ;
return V_10 ;
}
