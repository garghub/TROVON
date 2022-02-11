T_1 * F_1 ( void )
{
return F_2 () ;
}
void F_3 ( T_1 * V_1 )
{
F_4 ( V_1 , V_2 ) ;
return;
}
int F_5 ( T_1 * V_3 , unsigned char * * V_4 )
{
return F_6 ( V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 ) ;
}
T_1 * F_7 ( T_1 * * V_3 , unsigned char * * V_4 , long V_9 )
{
return F_8 ( V_3 , V_4 , V_9 , ( char * (*)() ) ( V_10 ) ,
V_2 , V_6 , V_7 ) ;
}
static T_1 * F_9 ( T_2 * V_11 , T_1 * V_1 ,
T_1 * V_12 )
{
int V_13 ;
T_3 * V_14 ;
char V_15 [ 80 ] ;
for( V_13 = 0 ; V_13 < F_10 ( V_1 ) ; V_13 ++ ) {
V_14 = ( T_3 * ) F_11 ( V_1 , V_13 ) ;
F_12 ( V_15 , 80 , V_14 ) ;
F_13 ( NULL , V_15 , & V_12 ) ;
}
return V_12 ;
}
static T_1 * F_14 ( T_2 * V_11 , T_4 * V_16 ,
T_1 * V_17 )
{
T_1 * V_18 ;
char * V_19 ;
T_3 * V_20 ;
T_5 * V_21 ;
int V_13 ;
if( ! ( V_18 = F_15 ( NULL ) ) ) {
F_16 ( V_22 , V_23 ) ;
return NULL ;
}
for( V_13 = 0 ; V_13 < F_10 ( V_17 ) ; V_13 ++ ) {
V_21 = ( T_5 * ) F_11 ( V_17 , V_13 ) ;
if( V_21 -> V_24 ) V_19 = V_21 -> V_24 ;
else V_19 = V_21 -> V_25 ;
if( ! ( V_20 = F_17 ( V_19 , 0 ) ) ) {
F_4 ( V_18 , V_2 ) ;
F_16 ( V_22 , V_26 ) ;
F_18 ( V_21 ) ;
return NULL ;
}
F_19 ( V_18 , ( char * ) V_20 ) ;
}
return V_18 ;
}
