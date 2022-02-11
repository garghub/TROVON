void F_1 ( unsigned char V_1 )
{
F_2 ( V_2 , V_1 ) ;
}
void F_3 ( unsigned char V_1 )
{
F_4 ( V_3 ) ;
F_5 ( V_2 , V_1 ^ ( F_6 ( 0 ) | F_6 ( 1 ) | F_6 ( 3 ) ) ) ;
}
void F_7 ( unsigned char V_4 )
{
F_1 ( ( V_4 ? F_6 ( 0 ) : 0 ) | F_6 ( 1 ) | F_6 ( 2 ) | F_6 ( 3 ) | F_6 ( 4 ) | F_6 ( 5 ) ) ;
}
void F_8 ( unsigned char V_5 )
{
F_1 ( F_9 ( V_5 , ( unsigned char ) 63 ) | F_6 ( 6 ) | F_6 ( 7 ) ) ;
}
void F_10 ( unsigned char V_6 )
{
F_1 ( F_9 ( V_6 , ( unsigned char ) 63 ) | F_6 ( 6 ) ) ;
}
void F_11 ( unsigned char V_7 )
{
F_1 ( F_9 ( V_7 , ( unsigned char ) 7 ) | F_6 ( 3 ) | F_6 ( 4 ) | F_6 ( 5 ) | F_6 ( 7 ) ) ;
}
unsigned char F_12 ( void )
{
return V_8 ;
}
static int T_1 F_13 ( void )
{
int V_9 ;
int V_10 = - V_11 ;
V_2 = F_14 ( V_12 ) ;
if ( V_2 == NULL ) {
F_15 (KERN_ERR KS0108_NAME L_1
L_2 , ks0108_port) ;
goto V_13;
}
V_14 = F_16 ( V_2 , V_15 ,
NULL , NULL , NULL , V_16 , NULL ) ;
if ( V_14 == NULL ) {
F_15 (KERN_ERR KS0108_NAME L_1
L_3 ) ;
goto V_13;
}
V_9 = F_17 ( V_14 ) ;
if ( V_9 != 0 ) {
F_15 (KERN_ERR KS0108_NAME L_1
L_4 , ks0108_port) ;
V_10 = V_9 ;
goto V_17;
}
V_8 = 1 ;
return 0 ;
V_17:
F_18 ( V_14 ) ;
V_13:
return V_10 ;
}
static void T_2 F_19 ( void )
{
F_20 ( V_14 ) ;
F_18 ( V_14 ) ;
}
