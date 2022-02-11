static const char * F_1 ( unsigned char type )
{
struct V_1 const * V_2 ;
for ( V_2 = V_3 ; V_2 -> type != 0xff ; V_2 ++ )
if ( type == V_2 -> type )
return V_2 -> V_4 ;
if ( ( type > V_5 ) && ( type < V_6 ) )
return L_1 ;
if ( ( type > V_7 ) && ( type < V_5 ) )
return L_2 ;
return L_3 ;
}
static int
F_2 ( unsigned long V_8 , int V_9 , unsigned long * V_10 ,
char * V_11 , int V_12 )
{
return F_3 ( V_8 , V_9 , V_10 , V_11 , V_12 ) ;
}
static int F_4 ( char * V_13 , unsigned long * V_10 )
{
unsigned type ;
type = F_5 ( V_10 [ 1 ] ) ;
return sprintf ( V_13 , L_4 ,
type ,
F_1 ( type ) ,
F_6 ( V_10 [ 1 ] ) , F_7 ( V_10 [ 1 ] ) ,
V_10 [ 0 ] ,
( unsigned ) ( V_10 [ 1 ] & 0xffffff ) * 16 ) ;
}
static int
F_8 ( char * V_13 , unsigned long V_8 )
{
unsigned long V_10 [ 2 ] ;
int V_9 ;
char * V_14 ;
V_14 = V_13 ;
for ( V_9 = 0 ; ; V_9 ++ ) {
F_9 ( V_9 * 60 > V_15 ) ;
if ( F_2 ( V_8 , V_9 , V_10 , NULL , 0 ) )
break;
V_14 += F_4 ( V_14 , V_10 ) ;
}
return V_14 - V_13 ;
}
static int
F_10 ( char * V_13 , unsigned long V_8 )
{
unsigned long V_10 [ 2 ] ;
char V_11 [ 128 ] ;
int V_9 ;
int V_16 ;
for ( V_9 = 0 ; ; V_9 ++ ) {
if ( F_2 ( V_8 , V_9 , V_10 , V_11 ,
sizeof( V_11 ) ) )
return 0 ;
if ( F_5 ( V_10 [ 1 ] ) == V_17 )
break;
}
V_16 = sprintf ( V_13 , L_5 , F_6 ( V_10 [ 1 ] ) ,
F_7 ( V_10 [ 1 ] ) ) ;
V_13 += V_16 ;
if ( V_11 [ 0 ] )
V_16 += snprintf ( V_13 , V_15 - V_16 , L_6 , V_11 ) ;
return V_16 ;
}
static int
F_11 ( char * V_13 , char * * V_18 , T_1 V_19 , int V_20 , int * V_21 ,
int V_16 )
{
if ( V_16 <= V_19 + V_20 )
* V_21 = 1 ;
* V_18 = V_13 + V_19 ;
V_16 -= V_19 ;
if ( V_16 > V_20 )
V_16 = V_20 ;
if ( V_16 < 0 )
V_16 = 0 ;
return V_16 ;
}
static int
F_12 ( char * V_13 , char * * V_18 , T_1 V_19 , int V_20 , int * V_21 ,
void * V_22 )
{
int V_16 ;
V_16 = F_10 ( V_13 , ( unsigned long ) V_22 ) ;
V_16 = F_11 ( V_13 , V_18 , V_19 , V_20 , V_21 , V_16 ) ;
return V_16 ;
}
static int
F_13 ( char * V_13 , char * * V_18 , T_1 V_19 , int V_20 , int * V_21 ,
void * V_22 )
{
int V_16 ;
V_16 = F_8 ( V_13 , ( unsigned long ) V_22 ) ;
V_16 = F_11 ( V_13 , V_18 , V_19 , V_20 , V_21 , V_16 ) ;
return V_16 ;
}
int T_2 F_14 ( void )
{
struct V_23 * * V_24 ;
T_3 V_25 ;
unsigned long V_8 ;
int V_26 ;
char V_4 [ V_27 ] ;
if ( ! F_15 ( L_7 ) )
return 0 ;
V_26 = F_16 () * sizeof( struct V_23 * ) ;
V_28 = F_17 ( V_26 , V_29 ) ;
if ( ! V_28 )
return - V_30 ;
V_31 = F_18 ( L_8 , NULL ) ;
V_24 = V_28 ;
F_19 (cnodeid) {
sprintf ( V_4 , L_9 , V_25 ) ;
* V_24 = F_18 ( V_4 , V_31 ) ;
V_8 = F_20 ( V_25 ) ;
F_21 ( L_10 , 0 , * V_24 , F_13 ,
( void * ) V_8 ) ;
F_21 ( L_11 , 0 , * V_24 ,
F_12 , ( void * ) V_8 ) ;
V_24 ++ ;
}
return 0 ;
}
void T_4 F_22 ( void )
{
struct V_23 * * V_24 ;
unsigned int V_25 ;
char V_4 [ V_27 ] ;
V_24 = V_28 ;
F_19 (cnodeid) {
F_23 ( L_10 , * V_24 ) ;
F_23 ( L_11 , * V_24 ) ;
sprintf ( V_4 , L_9 , V_25 ) ;
F_23 ( V_4 , V_31 ) ;
V_24 ++ ;
}
F_23 ( L_8 , NULL ) ;
F_24 ( V_28 ) ;
}
