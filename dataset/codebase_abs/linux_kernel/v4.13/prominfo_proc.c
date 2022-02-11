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
static void F_4 ( struct V_13 * V_14 , unsigned long * V_10 )
{
unsigned type ;
type = F_5 ( V_10 [ 1 ] ) ;
F_6 ( V_14 , L_4 ,
type ,
F_1 ( type ) ,
F_7 ( V_10 [ 1 ] ) , F_8 ( V_10 [ 1 ] ) ,
V_10 [ 0 ] ,
( unsigned ) ( V_10 [ 1 ] & 0xffffff ) * 16 ) ;
}
static int F_9 ( struct V_13 * V_14 , void * V_15 )
{
unsigned long V_8 = ( unsigned long ) V_14 -> V_16 ;
unsigned long V_10 [ 2 ] ;
int V_9 ;
for ( V_9 = 0 ; ; V_9 ++ ) {
F_10 ( V_9 * 60 > V_17 ) ;
if ( F_2 ( V_8 , V_9 , V_10 , NULL , 0 ) )
break;
F_4 ( V_14 , V_10 ) ;
}
return 0 ;
}
static int F_11 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
return F_12 ( V_19 , F_9 , F_13 ( V_18 ) ) ;
}
static int F_14 ( struct V_13 * V_14 , void * V_15 )
{
unsigned long V_8 = ( unsigned long ) V_14 -> V_16 ;
unsigned long V_10 [ 2 ] ;
char V_11 [ 128 ] ;
int V_9 ;
for ( V_9 = 0 ; ; V_9 ++ ) {
if ( F_2 ( V_8 , V_9 , V_10 , V_11 ,
sizeof( V_11 ) ) )
return 0 ;
if ( F_5 ( V_10 [ 1 ] ) == V_20 )
break;
}
F_6 ( V_14 , L_5 , F_7 ( V_10 [ 1 ] ) , F_8 ( V_10 [ 1 ] ) ) ;
if ( V_11 [ 0 ] )
F_6 ( V_14 , L_6 , V_11 ) ;
return 0 ;
}
static int F_15 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
return F_12 ( V_19 , F_14 , F_13 ( V_18 ) ) ;
}
int T_1 F_16 ( void )
{
struct V_21 * V_22 ;
T_2 V_23 ;
if ( ! F_17 ( L_7 ) )
return 0 ;
V_22 = F_18 ( L_8 , NULL ) ;
if ( ! V_22 )
return - V_24 ;
F_19 (cnodeid) {
struct V_21 * V_25 ;
unsigned long V_8 ;
char V_4 [ V_26 ] ;
sprintf ( V_4 , L_9 , V_23 ) ;
V_25 = F_18 ( V_4 , V_22 ) ;
if ( ! V_25 )
continue;
V_8 = F_20 ( V_23 ) ;
F_21 ( L_10 , 0 , V_25 ,
& V_27 , ( void * ) V_8 ) ;
F_21 ( L_11 , 0 , V_25 ,
& V_28 , ( void * ) V_8 ) ;
}
return 0 ;
}
void T_3 F_22 ( void )
{
F_23 ( L_8 , NULL ) ;
}
