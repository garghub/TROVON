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
V_11 = F_4 ( & V_13 -> V_18 , V_21 , V_14 -> V_22 , NULL ) ;
if ( V_11 )
{
V_10 = F_5 ( V_11 ) ;
F_6 ( V_11 ) ;
} else
V_10 = F_7 ( L_3 , F_8 ( V_12 ) ) ;
printf ( L_4 , V_14 -> V_23 , V_10 ) ;
F_6 ( V_10 ) ;
}
return FALSE ;
}
static int
F_9 ( void * V_24 , T_9 * V_25 , T_10 * T_11 V_26 , const void * V_27 )
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
if ( V_25 -> V_37 -> V_38 > V_36 -> V_39 ) {
V_36 -> V_39 = V_25 -> V_37 -> V_38 ;
V_36 -> V_40 = 0 ;
} else {
V_36 -> V_40 += 1 ;
}
V_30 = V_35 -> V_41 ;
V_31 = V_35 -> V_31 ;
V_32 = V_35 -> V_32 ;
V_33 = V_35 -> V_33 ;
if ( ! V_30 ) {
T_15 V_42 ;
F_10 ( & V_42 , & V_25 -> V_37 -> V_43 , & V_35 -> V_44 ) ;
V_29 = F_11 ( & V_42 ) ;
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
if ( V_14 && V_14 -> V_45 && strcmp ( V_14 -> V_45 , L_5 ) == 0 ) {
if ( V_36 -> V_40 == V_34 ) {
if ( V_30 ) {
V_36 -> V_46 ++ ;
} else {
V_36 -> V_47 ++ ;
if ( V_32 > 0 )
V_36 -> V_48 ++ ;
}
printf ( L_6 ,
V_25 -> V_37 -> V_38 , F_11 ( & V_25 -> V_37 -> V_43 ) , F_12 ( V_25 -> V_49 , & V_25 -> V_50 ) , V_25 -> V_51 , F_12 ( V_25 -> V_49 , & V_25 -> V_52 ) , V_25 -> V_53 , V_36 -> V_40 , V_30 , V_31 , V_32 , V_33 , V_29 ) ;
F_1 ( V_6 , F_2 , & V_36 ) ;
printf ( L_7 ) ;
}
V_34 ++ ;
}
}
return V_28 ;
}
static void
F_13 ( void * V_24 )
{
T_14 * V_36 = ( T_14 * ) V_24 ;
printf ( L_8 , V_36 -> V_46 , V_36 -> V_47 , V_36 -> V_48 ) ;
}
static void
F_14 ( const char * V_54 , void * T_16 V_26 )
{
T_14 * V_36 ;
T_17 * V_55 = NULL ;
T_17 * * V_56 ;
T_18 V_57 = 0 ;
T_18 V_58 = 0 ;
T_19 * V_59 = NULL ;
T_19 * V_60 = NULL ;
V_36 = F_15 ( T_14 , 1 ) ;
V_36 -> V_39 = 0 ;
V_36 -> V_40 = 0 ;
V_36 -> V_31 = 0 ;
V_36 -> V_46 = 0 ;
V_36 -> V_47 = 0 ;
V_36 -> V_48 = 0 ;
V_36 -> V_59 = NULL ;
V_59 = F_16 ( L_5 ) ;
V_56 = F_17 ( V_54 , L_9 , 1024 ) ;
V_57 = 0 ;
while ( V_56 [ V_57 ] )
V_57 ++ ;
if ( V_57 > 2 )
V_36 -> V_31 = ( T_12 ) atoi ( V_56 [ 2 ] ) ;
for ( V_58 = 3 ; V_58 < V_57 ; V_58 ++ )
{
V_55 = V_56 [ V_58 ] ;
F_18 ( V_59 , L_10 ) ;
if ( ! strchr ( V_55 , '.' ) )
F_18 ( V_59 , L_11 ) ;
F_18 ( V_59 , V_55 ) ;
}
F_19 ( V_56 ) ;
V_36 -> V_59 = F_20 ( V_59 , FALSE ) ;
V_60 = F_21 ( L_5 , V_36 , V_36 -> V_59 , 0 , NULL , F_9 , F_13 ) ;
if ( V_60 ) {
F_6 ( V_36 ) ;
fprintf ( V_15 , L_12 ,
V_60 -> V_61 ) ;
F_20 ( V_60 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_22 ( void )
{
F_23 ( & V_62 , NULL ) ;
}
