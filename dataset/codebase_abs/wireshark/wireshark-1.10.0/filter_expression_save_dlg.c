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
F_3 ( struct V_3 * V_4 )
{
if ( V_4 == NULL )
return;
F_3 ( V_4 -> V_9 ) ;
F_4 ( V_4 -> V_10 ) ;
F_4 ( V_4 -> V_11 ) ;
}
void
F_5 ( int V_12 )
{
struct V_3 * V_4 , * V_13 ;
if ( ( V_12 & V_14 ) != 0 ) {
V_4 = * V_8 ;
while ( V_4 != NULL ) {
if ( V_4 -> V_15 != NULL ) {
F_6 ( ( V_6 * ) V_4 -> V_15 ) ;
V_4 -> V_15 = NULL ;
}
V_4 = V_4 -> V_9 ;
}
}
if ( V_12 == V_14 ) {
F_3 ( * V_8 ) ;
* V_8 = NULL ;
return;
}
if ( ( V_12 & V_16 ) != 0 ) {
T_2 V_17 = - 1 , V_18 ;
V_4 = * V_8 ;
while ( V_4 != NULL ) {
V_17 = F_7 ( V_17 , V_4 -> V_19 ) ;
V_4 = V_4 -> V_9 ;
}
V_13 = * V_8 ;
* V_8 = NULL ;
for ( V_18 = 0 ; V_18 <= V_17 ; V_18 ++ ) {
if ( V_13 != NULL ) {
V_4 = V_13 ;
while ( V_4 != NULL && V_4 -> V_19 != V_18 )
V_4 = V_4 -> V_9 ;
}
if ( V_4 == NULL )
continue;
if ( V_4 -> V_20 )
continue;
F_8 ( V_4 -> V_10 , V_4 -> V_11 ,
V_4 -> V_21 ) ;
}
F_3 ( V_13 ) ;
V_4 = * V_8 ;
while ( V_4 != NULL ) {
if ( V_4 -> V_21 && ! V_4 -> V_20 )
F_2 ( NULL , NULL , V_4 ) ;
V_4 = V_4 -> V_9 ;
}
}
}
static int
F_2 ( const char * V_10 , const char * V_22 , struct V_3 * V_23 )
{
struct V_3 * V_4 ;
if ( V_23 == NULL )
V_4 = F_8 ( V_10 , V_22 , TRUE ) ;
else
V_4 = V_23 ;
if ( V_4 -> V_21 == FALSE )
return ( 0 ) ;
V_4 -> V_15 = F_9 ( NULL , V_4 -> V_10 ) ;
F_10 ( V_4 -> V_15 , L_1 , F_11 ( V_24 ) ,
NULL ) ;
F_12 ( F_13 ( V_4 -> V_15 ) , FALSE ) ;
F_14 ( F_13 ( V_4 -> V_15 ) ) ;
F_15 ( F_16 ( V_5 ) , ( V_25 * ) V_4 -> V_15 , - 1 ) ;
F_12 ( F_13 ( V_4 -> V_15 ) , TRUE ) ;
F_17 ( F_13 ( V_4 -> V_15 ) , V_4 -> V_11 ) ;
return ( 0 ) ;
}
static void
V_24 ( V_6 * V_26 , T_1 T_3 V_27 )
{
struct V_3 * V_4 ;
V_4 = * V_8 ;
while ( V_4 != NULL ) {
if ( ( void * ) V_4 -> V_15 == ( void * ) V_26 ) {
F_18 ( F_19 ( V_7 ) ,
V_4 -> V_11 ) ;
F_20 ( & V_28 , V_4 -> V_11 , FALSE ) ;
return;
}
V_4 = V_4 -> V_9 ;
}
printf ( L_2 ) ;
}
void
F_21 ( T_1 V_29 )
{
V_6 * V_30 , * V_31 , * V_32 ,
* V_33 , * V_34 , * V_35 ,
* V_36 , * V_37 , * V_38 , * V_39 , * V_40 ,
* V_41 ;
const char * V_22 ;
V_22 = F_22 ( F_19 ( V_29 ) ) ;
if ( V_42 != NULL ) {
F_23 ( V_42 ) ;
return;
}
V_42 = F_24 ( L_3 ) ;
V_30 = F_25 ( V_43 , 3 , FALSE ) ;
F_26 ( F_27 ( V_30 ) , 5 ) ;
F_28 ( F_27 ( V_42 ) , V_30 ) ;
F_14 ( V_30 ) ;
V_31 = F_25 ( V_44 , 3 , FALSE ) ;
F_29 ( F_30 ( V_30 ) , V_31 , TRUE , TRUE , 0 ) ;
F_14 ( V_31 ) ;
V_32 = F_31 ( L_4 ) ;
F_29 ( F_30 ( V_31 ) , V_32 ,
TRUE , TRUE , 0 ) ;
F_14 ( V_32 ) ;
V_33 = F_25 ( V_43 , 3 , FALSE ) ;
F_26 ( F_27 ( V_33 ) , 3 ) ;
F_28 ( F_27 ( V_32 ) ,
V_33 ) ;
F_14 ( V_33 ) ;
V_34 = F_25 ( V_44 , 3 , FALSE ) ;
F_29 ( F_30 ( V_33 ) , V_34 , TRUE , TRUE , 0 ) ;
F_14 ( V_34 ) ;
V_35 = F_25 ( V_44 , 3 , FALSE ) ;
F_29 ( F_30 ( V_33 ) , V_35 , FALSE ,
FALSE , 0 ) ;
F_14 ( V_35 ) ;
V_40 = F_32 () ;
F_29 ( F_30 ( V_35 ) , V_40 , TRUE , TRUE , 0 ) ;
F_10 ( V_40 , L_5 , F_11 ( V_45 ) , NULL ) ;
F_10 ( V_40 , L_6 , F_11 ( V_46 ) , NULL ) ;
F_10 ( V_42 , L_6 , F_11 ( V_47 ) , NULL ) ;
F_18 ( F_19 ( V_40 ) , V_22 ) ;
F_14 ( V_40 ) ;
V_41 = F_32 () ;
F_29 ( F_30 ( V_35 ) , V_41 , TRUE , TRUE , 0 ) ;
F_18 ( F_19 ( V_41 ) , L_7 ) ;
F_14 ( V_41 ) ;
V_36 = F_33 ( V_48 , V_49 ,
V_50 , NULL ) ;
F_29 ( F_30 ( V_30 ) , V_36 , FALSE , FALSE , 0 ) ;
F_14 ( V_36 ) ;
V_37 = ( V_6 * ) F_34 ( F_35 ( V_36 ) , V_48 ) ;
F_10 ( V_37 , L_1 , F_11 ( V_51 ) ,
V_42 ) ;
V_38 = ( V_6 * ) F_34 ( F_35 ( V_36 ) , V_49 ) ;
F_10 ( V_38 , L_1 , F_11 ( V_52 ) ,
V_42 ) ;
V_39 = ( V_6 * ) F_34 ( F_35 ( V_36 ) , V_50 ) ;
F_10 ( V_39 , L_1 , F_11 ( V_53 ) ,
( T_1 ) V_54 ) ;
F_36 ( F_35 ( V_42 ) ,
V_55 , V_40 ) ;
F_36 ( F_35 ( V_42 ) ,
V_56 , V_41 ) ;
F_37 ( V_41 , V_37 ) ;
F_38 ( V_41 ) ;
F_10 ( V_42 , L_8 ,
F_11 ( V_57 ) , NULL ) ;
F_10 ( V_42 , L_9 ,
F_11 ( V_58 ) , NULL ) ;
F_14 ( V_42 ) ;
F_39 ( V_42 ) ;
}
static void
V_51 ( V_6 * V_37 V_27 , T_4 * T_3 )
{
V_6 * V_59 , * V_60 ;
const char * V_22 , * V_10 ;
V_59 = ( V_6 * ) F_34 ( F_35 ( T_3 ) ,
V_55 ) ;
V_60 = ( V_6 * ) F_34 ( F_35 ( T_3 ) ,
V_56 ) ;
V_22 = F_22 ( F_19 ( V_59 ) ) ;
V_10 = F_22 ( F_19 ( V_60 ) ) ;
if ( F_2 ( V_10 , V_22 , NULL ) == 0 ) {
F_40 () ;
V_52 ( NULL , T_3 ) ;
}
}
static void
V_52 ( V_6 * T_5 V_27 , T_1 T_3 )
{
F_41 ( F_13 ( T_3 ) ) ;
F_42 ( F_13 ( T_3 ) ) ;
}
static void
V_58 ( V_6 * T_6 V_27 , T_1 T_7 V_27 )
{
V_42 = NULL ;
}
