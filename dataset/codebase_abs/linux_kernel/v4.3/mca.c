static int F_1 ( const char * V_1 , ... )
{
char V_2 [ 400 ] ;
int V_3 ;
T_1 args ;
va_start ( args , V_1 ) ;
vsnprintf ( V_2 , sizeof( V_2 ) , V_1 , args ) ;
va_end ( args ) ;
V_3 = strlen ( V_2 ) ;
if ( * V_4 + V_3 <= V_5 )
memcpy ( * V_6 + * V_4 , V_2 , V_3 ) ;
* V_4 += V_3 ;
return 0 ;
}
static void F_2 ( int V_7 , void * V_8 , struct V_9 * V_10 )
{
F_3 () ;
}
static void F_4 ( unsigned long V_11 )
{
F_2 ( - 1 , NULL , NULL ) ;
F_5 ( & V_12 , V_13 + V_14 ) ;
}
void F_6 ( void )
{
F_7 ( & V_12 ) ;
V_12 . V_15 = V_13 + V_14 ;
V_12 . V_16 = F_4 ;
F_8 ( & V_12 ) ;
}
static int
F_9 ( const T_2 * V_17 , T_2 * * V_18 ,
T_3 * V_19 )
{
F_10 ( & V_20 ) ;
V_6 = V_18 ;
V_4 = V_19 ;
V_5 = 0 ;
* V_4 = V_21 ;
while ( * V_4 > V_5 ) {
T_2 * V_22 = F_11 ( * V_4 ) ;
if ( ! V_22 ) {
F_12 ( & V_20 ) ;
F_13 ( V_23 L_1 ,
V_24 ) ;
return 1 ;
}
F_14 ( * V_6 ) ;
* V_6 = V_22 ;
V_5 = * V_4 ;
* V_4 = 0 ;
F_15 ( F_1 , ( char * ) V_17 ) ;
}
F_12 ( & V_20 ) ;
return 0 ;
}
int F_16 ( const T_2 * V_17 , T_2 * * V_18 , T_3 * V_19 )
{
T_4 V_25 = * ( T_4 * ) V_17 ;
int V_26 = 0 ;
* V_19 = 0 ;
F_14 ( * V_18 ) ;
* V_18 = NULL ;
if ( F_17 ( V_25 , V_27 ) == 0 ) {
T_5 * V_28 = ( T_5 * ) V_17 ;
V_26 = V_28 -> V_26 . V_29 ;
} else if ( F_17 ( V_25 , V_30 ) == 0 ) {
T_6 * V_31 = ( T_6 * ) V_17 ;
V_26 = V_31 -> V_26 . V_29 ;
}
if ( V_26 )
return F_9 ( V_17 , V_18 , V_19 ) ;
else
return 0 ;
}
static int T_7 F_18 ( void )
{
if ( F_19 ( L_2 ) )
V_32 = & F_16 ;
return 0 ;
}
