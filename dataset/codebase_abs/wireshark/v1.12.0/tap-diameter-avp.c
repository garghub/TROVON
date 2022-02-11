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
if( ! V_9 ) {
fprintf ( V_15 , L_1 , ( void * ) V_9 , ( void * ) V_3 ) ;
return FALSE ;
}
V_13 = V_9 -> V_16 ;
V_14 = V_13 ? V_13 -> V_17 : NULL ;
if( ! V_14 ) {
fprintf ( V_15 , L_2 , ( void * ) V_9 ) ;
return FALSE ;
}
V_12 = F_3 ( & V_13 -> V_18 ) ;
if ( V_12 != V_19 && V_12 != V_20 ) {
V_11 = F_4 ( & V_13 -> V_18 , V_21 , NULL ) ;
if( V_11 )
{
V_10 = F_5 ( V_11 ) ;
F_6 ( V_11 ) ;
} else
V_10 = F_7 ( L_3 , F_8 ( V_12 ) ) ;
printf ( L_4 , V_14 -> V_22 , V_10 ) ;
}
return FALSE ;
}
static int
F_9 ( void * V_23 , T_9 * V_24 , T_10 * T_11 V_25 , const void * V_26 )
{
int V_27 = 0 ;
double V_28 = 0. ;
T_1 V_29 = TRUE ;
T_12 V_30 = 0 ;
T_12 V_31 = 0 ;
T_12 V_32 = 0 ;
T_12 V_33 = 0 ;
T_5 * V_6 = NULL ;
T_5 * V_9 = NULL ;
T_8 * V_14 = NULL ;
T_7 * V_16 = NULL ;
const T_13 * V_34 = ( const T_13 * ) V_26 ;
T_14 * V_35 = NULL ;
if( ! V_34 || ! T_11 || ! T_11 -> V_1 )
return V_27 ;
V_35 = ( T_14 * ) V_23 ;
if( V_24 -> V_36 -> V_37 > V_35 -> V_38 ) {
V_35 -> V_38 = V_24 -> V_36 -> V_37 ;
V_35 -> V_39 = 0 ;
} else {
V_35 -> V_39 += 1 ;
}
V_29 = V_34 -> V_40 ;
V_30 = V_34 -> V_30 ;
V_31 = V_34 -> V_31 ;
V_32 = V_34 -> V_32 ;
if( ! V_29 ) {
T_15 V_41 ;
F_10 ( & V_41 , & V_24 -> V_36 -> V_42 , & V_34 -> V_43 ) ;
V_28 = F_11 ( & V_41 ) ;
V_28 = V_28 < 0 ? 0. : V_28 ;
}
if ( V_35 -> V_30 && V_35 -> V_30 != V_30 )
return V_27 ;
V_9 = T_11 -> V_1 -> V_7 ;
while ( V_9 != NULL ) {
V_6 = V_9 ;
V_9 = V_6 -> V_8 ;
V_16 = V_6 -> V_16 ;
V_14 = V_16 ? V_16 -> V_17 : NULL ;
if( V_14 && V_14 -> V_44 && strcmp ( V_14 -> V_44 , L_5 ) == 0 ) {
if ( V_35 -> V_39 == V_33 ) {
if( V_29 ) {
V_35 -> V_45 ++ ;
} else {
V_35 -> V_46 ++ ;
if ( V_31 > 0 )
V_35 -> V_47 ++ ;
}
printf ( L_6 ,
V_24 -> V_36 -> V_37 , F_11 ( & V_24 -> V_36 -> V_42 ) , F_12 ( & V_24 -> V_48 ) , V_24 -> V_49 , F_12 ( & V_24 -> V_50 ) , V_24 -> V_51 , V_35 -> V_39 , V_29 , V_30 , V_31 , V_32 , V_28 ) ;
F_1 ( V_6 , F_2 , & V_35 ) ;
printf ( L_7 ) ;
}
V_33 ++ ;
}
}
return V_27 ;
}
static void
F_13 ( void * V_23 )
{
T_14 * V_35 = ( T_14 * ) V_23 ;
printf ( L_8 , V_35 -> V_45 , V_35 -> V_46 , V_35 -> V_47 ) ;
}
static void
F_14 ( const char * V_52 , void * T_16 V_25 )
{
T_14 * V_35 ;
T_17 * V_53 = NULL ;
T_17 * * V_54 ;
T_18 V_55 = 0 ;
T_18 V_56 = 0 ;
T_19 * V_57 = NULL ;
T_19 * V_58 = NULL ;
V_35 = F_15 ( T_14 , 1 ) ;
V_35 -> V_38 = 0 ;
V_35 -> V_39 = 0 ;
V_35 -> V_30 = 0 ;
V_35 -> V_45 = 0 ;
V_35 -> V_46 = 0 ;
V_35 -> V_47 = 0 ;
V_35 -> V_57 = NULL ;
V_57 = F_16 ( L_5 ) ;
V_54 = F_17 ( V_52 , L_9 , 1024 ) ;
V_55 = 0 ;
while ( V_54 [ V_55 ] )
V_55 ++ ;
if ( V_55 > 2 )
V_35 -> V_30 = ( T_12 ) atoi ( V_54 [ 2 ] ) ;
for( V_56 = 3 ; V_56 < V_55 ; V_56 ++ )
{
V_53 = V_54 [ V_56 ] ;
F_18 ( V_57 , L_10 ) ;
if( ! strchr ( V_53 , '.' ) )
F_18 ( V_57 , L_11 ) ;
F_18 ( V_57 , V_53 ) ;
}
F_19 ( V_54 ) ;
V_35 -> V_57 = F_20 ( V_57 , FALSE ) ;
V_58 = F_21 ( L_5 , V_35 , V_35 -> V_57 , 0 , NULL , F_9 , F_13 ) ;
if( V_58 ) {
F_6 ( V_35 ) ;
fprintf ( V_15 , L_12 ,
V_58 -> V_59 ) ;
F_20 ( V_58 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_22 ( void )
{
F_23 ( L_13 , F_14 , NULL ) ;
}
