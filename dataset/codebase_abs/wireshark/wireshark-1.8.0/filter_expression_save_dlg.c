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
F_6 ( V_4 -> V_15 ) ;
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
V_17 = F_7 ( V_17 , V_4 -> V_18 ) ;
V_4 = V_4 -> V_9 ;
}
V_13 = * V_8 ;
* V_8 = NULL ;
for ( V_18 = 0 ; V_18 <= V_17 ; V_18 ++ ) {
if ( V_13 != NULL ) {
V_4 = V_13 ;
while ( V_4 != NULL && V_4 -> V_18 != V_18 )
V_4 = V_4 -> V_9 ;
}
if ( V_4 == NULL )
continue;
if ( V_4 -> V_19 )
continue;
F_8 ( V_4 -> V_10 , V_4 -> V_11 ,
V_4 -> V_20 ) ;
}
F_3 ( V_13 ) ;
V_4 = * V_8 ;
while ( V_4 != NULL ) {
if ( V_4 -> V_20 && ! V_4 -> V_19 )
F_2 ( NULL , NULL , V_4 ) ;
V_4 = V_4 -> V_9 ;
}
}
}
static int
F_2 ( const char * V_10 , const char * V_21 , struct V_3 * V_22 )
{
struct V_3 * V_4 ;
if ( V_22 == NULL )
V_4 = F_8 ( V_10 , V_21 , TRUE ) ;
else
V_4 = V_22 ;
if ( V_4 -> V_20 == FALSE )
return ( 0 ) ;
V_4 -> V_15 = F_9 ( NULL , V_4 -> V_10 ) ;
F_10 ( V_4 -> V_15 , L_1 , F_11 ( V_23 ) ,
NULL ) ;
F_12 ( F_13 ( V_4 -> V_15 ) , FALSE ) ;
F_14 ( F_13 ( V_4 -> V_15 ) ) ;
F_15 ( F_16 ( V_5 ) , V_4 -> V_15 , - 1 ) ;
F_12 ( F_13 ( V_4 -> V_15 ) , TRUE ) ;
F_17 ( F_13 ( V_4 -> V_15 ) , V_4 -> V_11 ) ;
return ( 0 ) ;
}
static void
V_23 ( V_6 * V_24 , T_1 T_3 V_25 )
{
struct V_3 * V_4 ;
V_4 = * V_8 ;
while ( V_4 != NULL ) {
if ( ( void * ) V_4 -> V_15 == ( void * ) V_24 ) {
F_18 ( F_19 ( V_7 ) ,
V_4 -> V_11 ) ;
F_20 ( & V_26 , V_4 -> V_11 , FALSE ) ;
return;
}
V_4 = V_4 -> V_9 ;
}
printf ( L_2 ) ;
}
void
F_21 ( T_1 V_27 )
{
V_6 * V_28 , * V_29 , * V_30 ,
* V_31 , * V_32 , * V_33 ,
* V_34 , * V_35 , * V_36 , * V_37 , * V_38 ,
* V_39 ;
const char * V_21 ;
V_21 = F_22 ( F_19 ( V_27 ) ) ;
if ( V_40 != NULL ) {
F_23 ( V_40 ) ;
return;
}
V_40 = F_24 ( L_3 ) ;
V_28 = F_25 ( V_41 , 3 , FALSE ) ;
F_26 ( F_27 ( V_28 ) , 5 ) ;
F_28 ( F_27 ( V_40 ) , V_28 ) ;
F_14 ( V_28 ) ;
V_29 = F_25 ( V_42 , 3 , FALSE ) ;
F_28 ( F_27 ( V_28 ) , V_29 ) ;
F_14 ( V_29 ) ;
V_30 = F_29 ( L_4 ) ;
F_30 ( F_31 ( V_29 ) , V_30 ,
TRUE , TRUE , 0 ) ;
F_14 ( V_30 ) ;
V_31 = F_25 ( V_41 , 3 , FALSE ) ;
F_26 ( F_27 ( V_31 ) , 3 ) ;
F_28 ( F_27 ( V_30 ) ,
V_31 ) ;
F_14 ( V_31 ) ;
V_32 = F_25 ( V_42 , 3 , FALSE ) ;
F_28 ( F_27 ( V_31 ) ,
V_32 ) ;
F_14 ( V_32 ) ;
V_33 = F_25 ( V_42 , 3 , FALSE ) ;
F_30 ( F_31 ( V_31 ) , V_33 , FALSE ,
FALSE , 0 ) ;
F_14 ( V_33 ) ;
V_38 = F_32 () ;
F_30 ( F_31 ( V_33 ) , V_38 , TRUE , TRUE , 0 ) ;
F_10 ( V_38 , L_5 , F_11 ( V_43 ) , NULL ) ;
F_10 ( V_38 , L_6 , F_11 ( V_44 ) , NULL ) ;
F_10 ( V_40 , L_6 , F_11 ( V_45 ) , NULL ) ;
F_18 ( F_19 ( V_38 ) , V_21 ) ;
F_14 ( V_38 ) ;
V_39 = F_32 () ;
F_30 ( F_31 ( V_33 ) , V_39 , TRUE , TRUE , 0 ) ;
F_18 ( F_19 ( V_39 ) , L_7 ) ;
F_14 ( V_39 ) ;
V_34 = F_33 ( V_46 , V_47 ,
V_48 , NULL ) ;
F_30 ( F_31 ( V_28 ) , V_34 , FALSE , FALSE , 0 ) ;
F_14 ( V_34 ) ;
V_35 = F_34 ( F_35 ( V_34 ) , V_46 ) ;
F_10 ( V_35 , L_1 , F_11 ( V_49 ) ,
V_40 ) ;
V_36 = F_34 ( F_35 ( V_34 ) , V_47 ) ;
F_10 ( V_36 , L_1 , F_11 ( V_50 ) ,
V_40 ) ;
V_37 = F_34 ( F_35 ( V_34 ) , V_48 ) ;
F_10 ( V_37 , L_1 , F_11 ( V_51 ) ,
( T_1 ) V_52 ) ;
F_36 ( F_35 ( V_40 ) ,
V_53 , V_38 ) ;
F_36 ( F_35 ( V_40 ) ,
V_54 , V_39 ) ;
F_37 ( V_39 , V_35 ) ;
F_38 ( V_39 ) ;
F_10 ( V_40 , L_8 ,
F_11 ( V_55 ) , NULL ) ;
F_10 ( V_40 , L_9 ,
F_11 ( V_56 ) , NULL ) ;
F_14 ( V_40 ) ;
F_39 ( V_40 ) ;
}
static void
V_49 ( V_6 * V_35 V_25 , T_4 * T_3 )
{
V_6 * V_57 , * V_58 ;
const char * V_21 , * V_10 ;
V_57 = ( V_6 * ) F_34 ( F_35 ( T_3 ) ,
V_53 ) ;
V_58 = ( V_6 * ) F_34 ( F_35 ( T_3 ) ,
V_54 ) ;
V_21 = F_22 ( F_19 ( V_57 ) ) ;
V_10 = F_22 ( F_19 ( V_58 ) ) ;
if ( F_2 ( V_10 , V_21 , NULL ) == 0 ) {
F_40 () ;
V_50 ( NULL , T_3 ) ;
}
}
static void
V_50 ( V_6 * T_5 V_25 , T_1 T_3 )
{
F_41 ( F_13 ( T_3 ) ) ;
F_42 ( F_13 ( T_3 ) ) ;
}
static void
V_56 ( V_6 * T_6 V_25 , T_1 T_7 V_25 )
{
V_40 = NULL ;
}
