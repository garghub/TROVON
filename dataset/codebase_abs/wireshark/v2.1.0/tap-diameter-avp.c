static T_1
F_1 ( T_2 * V_1 , T_3 V_2 , T_4 V_3 )
{
T_5 * V_4 = V_1 ;
T_5 * V_5 ;
T_5 * V_6 ;
if ( V_2 ( V_4 , V_3 ) )
return TRUE ;
V_5 = V_4 -> V_7 ;
while ( V_5 != NULL ) {
V_6 = V_5 ;
V_5 = V_6 -> V_8 ;
if ( F_1 ( ( T_2 * ) V_6 , V_2 , V_3 ) )
return TRUE ;
}
return FALSE ;
}
static T_1
F_2 ( T_5 * V_9 , T_4 V_3 )
{
char * V_10 = NULL ;
char * V_11 = NULL ;
T_6 V_12 ;
T_7 * V_13 ;
T_8 * V_14 ;
if ( ! V_9 ) {
fprintf ( V_15 , L_1 , ( void * ) V_9 , ( void * ) V_3 ) ;
return FALSE ;
}
V_13 = V_9 -> V_16 ;
V_14 = V_13 ? V_13 -> V_17 : NULL ;
if ( ! V_14 ) {
fprintf ( V_15 , L_2 , ( void * ) V_9 ) ;
return FALSE ;
}
V_12 = F_3 ( & V_13 -> V_18 ) ;
if ( V_12 != V_19 && V_12 != V_20 ) {
V_11 = F_4 ( NULL , & V_13 -> V_18 , V_21 , V_14 -> V_22 ) ;
if ( V_11 )
{
V_10 = F_5 ( V_11 ) ;
F_6 ( NULL , V_11 ) ;
} else
V_10 = F_7 ( L_3 , F_8 ( V_12 ) ) ;
printf ( L_4 , V_14 -> V_23 , V_10 ) ;
F_9 ( V_10 ) ;
}
return FALSE ;
}
static int
F_10 ( void * V_24 , T_9 * V_25 , T_10 * T_11 V_26 , const void * V_27 )
{
int V_28 = 0 ;
double V_29 = 0. ;
T_1 V_30 = TRUE ;
T_12 V_31 = 0 ;
T_12 V_32 = 0 ;
T_12 V_33 = 0 ;
T_12 V_34 = 0 ;
T_5 * V_6 = NULL ;
T_5 * V_9 = NULL ;
T_8 * V_14 = NULL ;
T_7 * V_16 = NULL ;
const T_13 * V_35 = ( const T_13 * ) V_27 ;
T_14 * V_36 = NULL ;
if ( ! V_35 || ! T_11 || ! T_11 -> V_1 )
return V_28 ;
V_36 = ( T_14 * ) V_24 ;
if ( V_25 -> V_37 > V_36 -> V_38 ) {
V_36 -> V_38 = V_25 -> V_37 ;
V_36 -> V_39 = 0 ;
} else {
V_36 -> V_39 += 1 ;
}
V_30 = V_35 -> V_40 ;
V_31 = V_35 -> V_31 ;
V_32 = V_35 -> V_32 ;
V_33 = V_35 -> V_33 ;
if ( ! V_30 ) {
T_15 V_41 ;
F_11 ( & V_41 , & V_25 -> V_42 , & V_35 -> V_43 ) ;
V_29 = F_12 ( & V_41 ) ;
V_29 = V_29 < 0. ? 0. : V_29 ;
}
if ( V_36 -> V_31 && V_36 -> V_31 != V_31 )
return V_28 ;
V_9 = T_11 -> V_1 -> V_7 ;
while ( V_9 != NULL ) {
V_6 = V_9 ;
V_9 = V_6 -> V_8 ;
V_16 = V_6 -> V_16 ;
V_14 = V_16 ? V_16 -> V_17 : NULL ;
if ( V_14 && V_14 -> V_44 && strcmp ( V_14 -> V_44 , L_5 ) == 0 ) {
if ( V_36 -> V_39 == V_34 ) {
if ( V_30 ) {
V_36 -> V_45 ++ ;
} else {
V_36 -> V_46 ++ ;
if ( V_32 > 0 )
V_36 -> V_47 ++ ;
}
printf ( L_6 ,
V_25 -> V_37 , F_12 ( & V_25 -> V_42 ) , F_13 ( V_25 -> V_48 , & V_25 -> V_49 ) , V_25 -> V_50 , F_13 ( V_25 -> V_48 , & V_25 -> V_51 ) , V_25 -> V_52 , V_36 -> V_39 , V_30 , V_31 , V_32 , V_33 , V_29 ) ;
F_1 ( V_6 , F_2 , & V_36 ) ;
printf ( L_7 ) ;
}
V_34 ++ ;
}
}
return V_28 ;
}
static void
F_14 ( void * V_24 )
{
T_14 * V_36 = ( T_14 * ) V_24 ;
printf ( L_8 , V_36 -> V_45 , V_36 -> V_46 , V_36 -> V_47 ) ;
}
static void
F_15 ( const char * V_53 , void * T_16 V_26 )
{
T_14 * V_36 ;
T_17 * V_54 = NULL ;
T_17 * * V_55 ;
T_18 V_56 = 0 ;
T_18 V_57 = 0 ;
T_19 * V_58 = NULL ;
T_19 * V_59 = NULL ;
V_36 = F_16 ( T_14 , 1 ) ;
V_36 -> V_38 = 0 ;
V_36 -> V_39 = 0 ;
V_36 -> V_31 = 0 ;
V_36 -> V_45 = 0 ;
V_36 -> V_46 = 0 ;
V_36 -> V_47 = 0 ;
V_36 -> V_58 = NULL ;
V_58 = F_17 ( L_5 ) ;
V_55 = F_18 ( V_53 , L_9 , 1024 ) ;
V_56 = 0 ;
while ( V_55 [ V_56 ] )
V_56 ++ ;
if ( V_56 > 2 )
V_36 -> V_31 = ( T_12 ) atoi ( V_55 [ 2 ] ) ;
for ( V_57 = 3 ; V_57 < V_56 ; V_57 ++ )
{
V_54 = V_55 [ V_57 ] ;
F_19 ( V_58 , L_10 ) ;
if ( ! strchr ( V_54 , '.' ) )
F_19 ( V_58 , L_11 ) ;
F_19 ( V_58 , V_54 ) ;
}
F_20 ( V_55 ) ;
V_36 -> V_58 = F_21 ( V_58 , FALSE ) ;
V_59 = F_22 ( L_5 , V_36 , V_36 -> V_58 , 0 , NULL , F_10 , F_14 ) ;
if ( V_59 ) {
F_9 ( V_36 ) ;
fprintf ( V_15 , L_12 ,
V_59 -> V_60 ) ;
F_21 ( V_59 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_23 ( void )
{
F_24 ( & V_61 , NULL ) ;
}
