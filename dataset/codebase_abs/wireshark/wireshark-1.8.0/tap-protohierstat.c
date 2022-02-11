static T_1 *
F_1 ( T_1 * V_1 )
{
T_1 * V_2 ;
V_2 = F_2 ( sizeof( T_1 ) ) ;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = NULL ;
V_2 -> V_1 = V_1 ;
V_2 -> V_5 = NULL ;
V_2 -> V_6 = - 1 ;
V_2 -> V_7 = NULL ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
return V_2 ;
}
static int
F_3 ( void * V_10 , T_2 * V_11 , T_3 * V_12 , const void * T_4 V_13 )
{
T_1 * V_2 = V_10 ;
T_1 * V_14 ;
T_5 * V_15 ;
T_6 * V_16 ;
if( ! V_12 ) {
return 0 ;
}
if( ! V_12 -> V_17 ) {
return 0 ;
}
if( ! V_12 -> V_17 -> V_18 ) {
return 0 ;
}
for( V_15 = V_12 -> V_17 -> V_18 ; V_15 ; V_15 = V_15 -> V_19 ) {
V_16 = F_4 ( V_15 ) ;
if( V_2 -> V_6 == - 1 ) {
V_2 -> V_6 = V_16 -> V_20 -> V_21 ;
V_2 -> V_7 = V_16 -> V_20 -> V_22 ;
V_2 -> V_8 = 1 ;
V_2 -> V_9 = V_11 -> V_23 -> V_24 ;
V_2 -> V_4 = F_1 ( V_2 ) ;
V_2 = V_2 -> V_4 ;
continue;
}
for( V_14 = V_2 ; V_14 ; V_14 = V_14 -> V_3 ) {
if( V_14 -> V_6 == V_16 -> V_20 -> V_21 ) {
break;
}
}
if( ! V_14 ) {
for( V_14 = V_2 ; V_14 -> V_3 ; V_14 = V_14 -> V_3 )
;
V_14 -> V_3 = F_1 ( V_2 -> V_1 ) ;
V_2 = V_14 -> V_3 ;
V_2 -> V_6 = V_16 -> V_20 -> V_21 ;
V_2 -> V_7 = V_16 -> V_20 -> V_22 ;
} else {
V_2 = V_14 ;
}
V_2 -> V_8 ++ ;
V_2 -> V_9 += V_11 -> V_23 -> V_24 ;
if( ! V_2 -> V_4 ) {
V_2 -> V_4 = F_1 ( V_2 ) ;
}
V_2 = V_2 -> V_4 ;
}
return 1 ;
}
static void
F_5 ( T_1 * V_2 , int V_25 )
{
int V_26 , V_27 ;
#define F_6 80
char V_28 [ F_6 ] ;
for(; V_2 ; V_2 = V_2 -> V_3 ) {
if( V_2 -> V_6 == - 1 ) {
return;
}
V_28 [ 0 ] = 0 ;
V_27 = 0 ;
for( V_26 = 0 ; V_26 < V_25 ; V_26 ++ ) {
if( V_26 > 15 ) {
V_27 += F_7 ( V_28 + V_27 , F_6 - V_27 , L_1 ) ;
break;
}
V_27 += F_7 ( V_28 + V_27 , F_6 - V_27 , L_2 ) ;
}
F_7 ( V_28 + V_27 , F_6 - V_27 , L_3 , V_2 -> V_7 ) ;
printf ( L_4 V_29 L_5 , V_28 , V_2 -> V_8 , V_2 -> V_9 ) ;
F_5 ( V_2 -> V_4 , V_25 + 1 ) ;
}
}
static void
F_8 ( void * V_10 )
{
T_1 * V_2 = V_10 ;
printf ( L_6 ) ;
printf ( L_7 ) ;
printf ( L_8 ) ;
printf ( L_9 , V_2 -> V_5 ? V_2 -> V_5 : L_10 ) ;
F_5 ( V_2 , 0 ) ;
printf ( L_7 ) ;
}
static void
F_9 ( const char * V_30 , void * T_7 V_13 )
{
T_1 * V_2 ;
int V_31 = 0 ;
const char * V_5 = NULL ;
T_8 * V_32 ;
if( strcmp ( L_11 , V_30 ) == 0 ) {
} else if( sscanf ( V_30 , L_12 , & V_31 ) == 0 ) {
if( V_31 ) {
V_5 = V_30 + V_31 ;
}
} else {
fprintf ( V_33 , L_13 ) ;
exit ( 1 ) ;
}
V_2 = F_1 ( NULL ) ;
if( V_5 ) {
V_2 -> V_5 = F_10 ( V_5 ) ;
} else {
V_2 -> V_5 = NULL ;
}
V_32 = F_11 ( L_14 , V_2 , V_5 , V_34 , NULL , F_3 , F_8 ) ;
if( V_32 ) {
F_12 ( V_2 -> V_5 ) ;
F_12 ( V_2 ) ;
fprintf ( V_33 , L_15 ,
V_32 -> V_28 ) ;
F_13 ( V_32 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_14 ( void )
{
F_15 ( L_11 , F_9 , NULL ) ;
}
