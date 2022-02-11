static T_1 F_1 ( T_1 V_1 )
{
T_1 * V_2 = V_3 + V_4 ;
T_1 * V_5 = V_3 + V_6 ;
T_1 * V_7 = V_3 + V_8 ;
T_1 V_9 , V_10 , V_11 ;
V_9 = V_12 | V_13 ;
F_2 ( V_2 , V_9 ) ;
V_10 = V_1 ;
F_2 ( V_5 , V_10 ) ;
V_11 = F_3 ( 2 ) | V_14 | V_15 ;
F_2 ( V_7 , V_11 ) ;
while ( F_4 ( V_7 ) & V_15 )
F_5 () ;
F_2 ( V_2 , 0 ) ;
V_10 = F_4 ( V_5 ) ;
return V_10 ;
}
static int F_6 ( void )
{
return F_1 ( 0xc0000000 ) & 0x04000000 ;
}
static void F_7 ( char V_16 )
{
F_1 ( 0xb0000000 | ( V_16 << 20 ) ) ;
}
static void F_8 ( char V_16 )
{
int V_17 = 16 ;
if ( ! V_3 )
return;
while ( ! F_6 () && V_17 -- )
F_5 () ;
if ( V_17 >= 0 )
F_7 ( V_16 ) ;
}
void F_9 ( const char * V_18 , int V_19 )
{
char * V_20 = ( char * ) V_18 ;
while ( V_19 -- ) {
if ( * V_20 == '\n' )
F_8 ( '\r' ) ;
F_8 ( * V_20 ++ ) ;
}
}
static int F_10 ( void )
{
if ( ! V_3 )
return 0 ;
return F_1 ( 0x90000000 ) == 0x04700000 ;
}
static void * F_11 ( void )
{
T_1 V_21 ;
void * V_22 ;
V_22 = F_12 ( NULL , L_1 ) ;
if ( V_22 == NULL )
goto V_23;
if ( F_13 ( V_22 , L_2 , & V_21 , sizeof( V_21 ) ) != sizeof( V_21 ) )
goto V_23;
return ( void * ) V_21 ;
V_23:
return NULL ;
}
void * F_14 ( void )
{
void * V_24 ;
int V_25 ;
V_24 = F_11 () ;
if ( ! V_24 )
return NULL ;
for ( V_25 = 0 ; V_25 < 2 ; V_25 ++ ) {
V_3 = V_24 + 0x14 * V_25 ;
if ( F_10 () )
break;
}
if ( V_25 == 2 )
V_3 = NULL ;
return V_3 ;
}
