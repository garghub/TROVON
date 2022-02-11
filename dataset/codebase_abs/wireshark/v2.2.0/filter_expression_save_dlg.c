void
F_1 ( T_1 V_1 , T_1 V_2 )
{
struct V_3 * V_4 ;
V_5 = ( V_6 * ) V_1 ;
V_7 = ( V_6 * ) V_2 ;
V_4 = * V_8 ;
while ( V_4 != NULL ) {
F_2 ( NULL , NULL , V_4 ) ;
V_4 = V_4 -> V_9 ;
}
}
void
F_3 ( int V_10 )
{
struct V_3 * V_4 , * V_11 ;
if ( ( V_10 & V_12 ) != 0 ) {
V_4 = * V_8 ;
while ( V_4 != NULL ) {
if ( V_4 -> V_13 != NULL ) {
F_4 ( ( V_6 * ) V_4 -> V_13 ) ;
V_4 -> V_13 = NULL ;
}
V_4 = V_4 -> V_9 ;
}
}
if ( V_10 == V_12 ) {
F_5 ( * V_8 ) ;
* V_8 = NULL ;
return;
}
if ( ( V_10 & V_14 ) != 0 ) {
T_2 V_15 = - 1 , V_16 ;
V_4 = * V_8 ;
while ( V_4 != NULL ) {
V_15 = F_6 ( V_15 , V_4 -> V_17 ) ;
V_4 = V_4 -> V_9 ;
}
V_11 = * V_8 ;
* V_8 = NULL ;
for ( V_16 = 0 ; V_16 <= V_15 ; V_16 ++ ) {
if ( V_11 != NULL ) {
V_4 = V_11 ;
while ( V_4 != NULL && V_4 -> V_17 != V_16 )
V_4 = V_4 -> V_9 ;
}
if ( V_4 == NULL )
continue;
if ( V_4 -> V_18 )
continue;
F_7 ( V_4 -> V_19 , V_4 -> V_20 ,
V_4 -> V_21 ) ;
}
F_5 ( V_11 ) ;
V_4 = * V_8 ;
while ( V_4 != NULL ) {
if ( V_4 -> V_21 && ! V_4 -> V_18 )
F_2 ( NULL , NULL , V_4 ) ;
V_4 = V_4 -> V_9 ;
}
}
}
static int
F_2 ( const char * V_19 , const char * V_22 , struct V_3 * V_23 )
{
struct V_3 * V_4 ;
if ( V_23 == NULL )
V_4 = F_7 ( V_19 , V_22 , TRUE ) ;
else
V_4 = V_23 ;
if ( V_4 -> V_21 == FALSE )
return ( 0 ) ;
V_4 -> V_13 = F_8 ( NULL , V_4 -> V_19 ) ;
F_9 ( V_4 -> V_13 , L_1 , F_10 ( V_24 ) ,
NULL ) ;
F_11 ( F_12 ( V_4 -> V_13 ) , FALSE ) ;
F_13 ( F_12 ( V_4 -> V_13 ) ) ;
F_14 ( F_15 ( V_5 ) , ( V_25 * ) V_4 -> V_13 , - 1 ) ;
F_11 ( F_12 ( V_4 -> V_13 ) , TRUE ) ;
F_16 ( F_12 ( V_4 -> V_13 ) , V_4 -> V_20 ) ;
return ( 0 ) ;
}
static void
V_24 ( V_6 * V_26 , T_1 T_3 V_27 )
{
struct V_3 * V_4 ;
V_4 = * V_8 ;
while ( V_4 != NULL ) {
if ( ( void * ) V_4 -> V_13 == ( void * ) V_26 ) {
F_17 ( F_18 ( V_7 ) ,
V_4 -> V_20 ) ;
F_19 ( & V_28 , V_4 -> V_20 , FALSE ) ;
return;
}
V_4 = V_4 -> V_9 ;
}
printf ( L_2 ) ;
}
void
F_20 ( T_1 V_29 )
{
V_6 * V_30 , * V_31 , * V_32 ,
* V_33 , * V_34 , * V_35 ,
* V_36 , * V_37 , * V_38 , * V_39 , * V_40 ,
* V_41 ;
const char * V_22 ;
V_22 = F_21 ( F_18 ( V_29 ) ) ;
if ( V_42 != NULL ) {
F_22 ( V_42 ) ;
return;
}
V_42 = F_23 ( L_3 ) ;
V_30 = F_24 ( V_43 , 3 , FALSE ) ;
F_25 ( F_26 ( V_30 ) , 5 ) ;
F_27 ( F_26 ( V_42 ) , V_30 ) ;
F_13 ( V_30 ) ;
V_31 = F_24 ( V_44 , 3 , FALSE ) ;
F_28 ( F_29 ( V_30 ) , V_31 , TRUE , TRUE , 0 ) ;
F_13 ( V_31 ) ;
V_32 = F_30 ( L_4 ) ;
F_28 ( F_29 ( V_31 ) , V_32 ,
TRUE , TRUE , 0 ) ;
F_13 ( V_32 ) ;
V_33 = F_24 ( V_43 , 3 , FALSE ) ;
F_25 ( F_26 ( V_33 ) , 3 ) ;
F_27 ( F_26 ( V_32 ) ,
V_33 ) ;
F_13 ( V_33 ) ;
V_34 = F_24 ( V_44 , 3 , FALSE ) ;
F_28 ( F_29 ( V_33 ) , V_34 , TRUE , TRUE , 0 ) ;
F_13 ( V_34 ) ;
V_35 = F_24 ( V_44 , 3 , FALSE ) ;
F_28 ( F_29 ( V_33 ) , V_35 , FALSE ,
FALSE , 0 ) ;
F_13 ( V_35 ) ;
V_40 = F_31 () ;
F_28 ( F_29 ( V_35 ) , V_40 , TRUE , TRUE , 0 ) ;
F_9 ( V_40 , L_5 , F_10 ( V_45 ) , NULL ) ;
F_9 ( V_40 , L_6 , F_10 ( V_46 ) , NULL ) ;
F_9 ( V_42 , L_6 , F_10 ( V_47 ) , NULL ) ;
F_17 ( F_18 ( V_40 ) , V_22 ) ;
F_13 ( V_40 ) ;
V_41 = F_31 () ;
F_28 ( F_29 ( V_35 ) , V_41 , TRUE , TRUE , 0 ) ;
F_17 ( F_18 ( V_41 ) , L_7 ) ;
F_13 ( V_41 ) ;
V_36 = F_32 ( V_48 , V_49 ,
V_50 , NULL ) ;
F_28 ( F_29 ( V_30 ) , V_36 , FALSE , FALSE , 0 ) ;
F_13 ( V_36 ) ;
V_37 = ( V_6 * ) F_33 ( F_34 ( V_36 ) , V_48 ) ;
F_9 ( V_37 , L_1 , F_10 ( V_51 ) ,
V_42 ) ;
V_38 = ( V_6 * ) F_33 ( F_34 ( V_36 ) , V_49 ) ;
F_9 ( V_38 , L_1 , F_10 ( V_52 ) ,
V_42 ) ;
V_39 = ( V_6 * ) F_33 ( F_34 ( V_36 ) , V_50 ) ;
F_9 ( V_39 , L_1 , F_10 ( V_53 ) ,
( T_1 ) V_54 ) ;
F_35 ( F_34 ( V_42 ) ,
V_55 , V_40 ) ;
F_35 ( F_34 ( V_42 ) ,
V_56 , V_41 ) ;
F_36 ( V_41 , V_37 ) ;
F_37 ( V_41 ) ;
F_9 ( V_42 , L_8 ,
F_10 ( V_57 ) , NULL ) ;
F_9 ( V_42 , L_9 ,
F_10 ( V_58 ) , NULL ) ;
F_13 ( V_42 ) ;
F_38 ( V_42 ) ;
}
static void
V_51 ( V_6 * V_37 V_27 , T_4 * T_3 )
{
V_6 * V_59 , * V_60 ;
const char * V_22 , * V_19 ;
V_59 = ( V_6 * ) F_33 ( F_34 ( T_3 ) ,
V_55 ) ;
V_60 = ( V_6 * ) F_33 ( F_34 ( T_3 ) ,
V_56 ) ;
V_22 = F_21 ( F_18 ( V_59 ) ) ;
V_19 = F_21 ( F_18 ( V_60 ) ) ;
if ( F_2 ( V_19 , V_22 , NULL ) == 0 ) {
F_39 () ;
V_52 ( NULL , T_3 ) ;
}
}
static void
V_52 ( V_6 * T_5 V_27 , T_1 T_3 )
{
F_40 ( F_12 ( T_3 ) ) ;
F_41 ( F_12 ( T_3 ) ) ;
}
static void
V_58 ( V_6 * T_6 V_27 , T_1 T_7 V_27 )
{
V_42 = NULL ;
}
