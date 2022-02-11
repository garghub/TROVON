T_1 F_1 ( const char * V_1 , T_2 V_2 )
{
T_1 V_3 ;
T_3 V_4 = 0 ;
char V_5 [ 4 ] ;
if ( V_2 & V_6 ) {
V_5 [ V_4 ++ ] = 'r' ;
}
if ( V_2 & V_7 ) {
V_5 [ V_4 ++ ] = 'w' ;
}
if ( V_2 & V_8 ) {
V_5 [ V_4 ++ ] = 'b' ;
}
V_5 [ V_4 ++ ] = '\0' ;
V_3 = fopen ( V_1 , V_5 ) ;
if ( ! V_3 ) {
perror ( L_1 ) ;
}
return ( V_3 ) ;
}
void F_2 ( T_1 V_3 )
{
fclose ( V_3 ) ;
}
int
F_3 ( T_1 V_3 , void * V_9 , T_4 V_10 , T_4 V_11 )
{
int V_12 ;
V_12 = fread ( V_9 , V_10 , V_11 , V_3 ) ;
if ( V_12 < 0 ) {
perror ( L_2 ) ;
}
return ( V_12 ) ;
}
int
F_4 ( T_1 V_3 ,
void * V_9 , T_4 V_10 , T_4 V_11 )
{
int V_12 ;
V_12 = fwrite ( V_9 , V_10 , V_11 , V_3 ) ;
if ( V_12 < 0 ) {
perror ( L_3 ) ;
}
return ( V_12 ) ;
}
long F_5 ( T_1 V_3 )
{
long V_13 ;
V_13 = ftell ( V_3 ) ;
return ( V_13 ) ;
}
T_5 F_6 ( T_1 V_3 , long V_13 , T_2 V_14 )
{
int V_15 = 0 ;
if ( V_14 == V_16 ) {
V_15 = fseek ( V_3 , V_13 , V_17 ) ;
}
if ( V_14 == V_18 ) {
V_15 = fseek ( V_3 , V_13 , V_19 ) ;
}
if ( V_15 < 0 ) {
return ( V_20 ) ;
} else {
return ( V_21 ) ;
}
}
