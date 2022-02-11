static void F_1 ( void * V_1 )
{
if ( V_2 [ 0 ] == '\0' )
F_2 ( V_1 , L_1 , V_2 , V_3 - 1 ) ;
else
F_3 ( V_1 , L_1 , V_2 ) ;
printf ( L_2 , V_2 ) ;
}
static void F_4 ( const char * V_4 , int V_5 )
{
}
static void F_5 ( void )
{
printf ( L_3 ) ;
F_6 ( 0 ) ;
while ( 1 ) ;
}
static int F_7 ( T_1 * V_6 )
{
int V_7 ;
T_1 V_8 ;
T_1 V_9 ;
T_1 V_10 ;
V_7 = F_8 ( & V_8 ) ;
if ( V_7 )
return - 1 ;
V_7 = F_9 ( & V_9 ) ;
if ( V_7 )
return - 1 ;
V_7 = F_10 ( V_8 , 0x0000000062690000ULL ,
0x7075000000000000ULL , V_9 , 0x726d5f73697a6500ULL , V_6 ,
& V_10 ) ;
printf ( L_4 , V_11 , __LINE__ ,
( unsigned long ) V_9 ) ;
printf ( L_5 , V_11 , __LINE__ ,
( unsigned long ) V_8 ) ;
printf ( L_6 , V_11 , __LINE__ , * V_6 ) ;
return V_7 ? - 1 : 0 ;
}
void F_11 ( void )
{
extern char V_12 [] ;
memcpy ( ( void * ) 0x100 , V_12 , 512 ) ;
F_12 ( ( void * ) 0x100 , 512 ) ;
}
void F_13 ( unsigned long V_13 )
{
const T_2 V_14 = 0x1000000 - ( T_2 ) V_15 ;
void * V_1 ;
unsigned long V_16 ;
T_1 V_6 ;
unsigned long V_17 ;
V_18 . V_19 = F_4 ;
V_20 . exit = F_5 ;
printf ( L_7 ) ;
F_14 ( V_15 , V_14 , 32 , 64 ) ;
F_15 ( V_21 ) ;
V_1 = F_16 ( L_8 ) ;
F_7 ( & V_6 ) ;
F_17 ( 0 , V_6 ) ;
if ( V_22 > V_23 ) {
F_18 ( V_1 , L_9 , ( T_2 ) ( V_23 ) ) ;
F_18 ( V_1 , L_10 , ( T_2 ) ( V_22 ) ) ;
}
F_1 ( V_1 ) ;
V_16 = V_24 . V_25 () ;
F_11 () ;
printf ( L_11 , V_16 ) ;
V_17 = * ( unsigned long * ) 0 ;
if ( V_17 != V_13 )
printf ( L_12 , V_17 , V_13 ) ;
( ( V_26 ) 0 ) ( V_16 , 0 , NULL ) ;
F_5 () ;
}
