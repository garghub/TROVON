static long T_1 F_1 ( void * V_1 , unsigned long V_2 )
{
return - 1 ;
}
STATIC int T_1 F_2 ( unsigned char * V_3 , long V_2 ,
long (* F_3)( void * , unsigned long ) ,
long (* F_4)( void * , unsigned long ) ,
unsigned char * V_4 , long V_5 ,
long * V_6 ,
void (* error)( char * V_7 ) ) {
T_2 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
V_11 = - 1 ;
if ( F_4 ) {
V_5 = 0x8000 ;
V_4 = malloc ( V_5 ) ;
} else {
if ( ! V_5 )
V_5 = ( ( V_12 ) ~ 0 ) - ( V_12 ) V_4 ;
}
if ( ! V_4 ) {
error ( L_1 ) ;
goto V_13;
}
if ( V_3 )
V_8 = V_3 ;
else {
V_8 = malloc ( V_14 ) ;
V_2 = 0 ;
}
if ( ! V_8 ) {
error ( L_2 ) ;
goto V_15;
}
V_10 = malloc ( sizeof( * V_10 ) ) ;
if ( V_10 == NULL ) {
error ( L_3 ) ;
goto V_16;
}
V_10 -> V_17 = malloc ( F_4 ? F_5 () :
sizeof( struct V_18 ) ) ;
if ( V_10 -> V_17 == NULL ) {
error ( L_4 ) ;
goto V_19;
}
if ( ! F_3 )
F_3 = F_1 ;
if ( V_2 == 0 )
V_2 = F_3 ( V_8 , V_14 ) ;
if ( V_2 < 10 ||
V_8 [ 0 ] != 0x1f || V_8 [ 1 ] != 0x8b || V_8 [ 2 ] != 0x08 ) {
if ( V_6 )
* V_6 = 0 ;
error ( L_5 ) ;
goto V_20;
}
V_10 -> V_21 = V_8 + 10 ;
V_10 -> V_22 = V_2 - 10 ;
if ( V_8 [ 3 ] & 0x8 ) {
do {
if ( V_10 -> V_22 == 0 ) {
error ( L_6 ) ;
goto V_20;
}
-- V_10 -> V_22 ;
} while ( * V_10 -> V_21 ++ );
}
V_10 -> V_23 = V_4 ;
V_10 -> V_24 = V_5 ;
V_11 = F_6 ( V_10 , - V_25 ) ;
if ( ! F_4 ) {
F_7 ( V_10 ) -> V_18 . V_26 = 0 ;
F_7 ( V_10 ) -> V_18 . V_27 = NULL ;
}
while ( V_11 == V_28 ) {
if ( V_10 -> V_22 == 0 ) {
V_2 = F_3 ( V_8 , V_14 ) ;
if ( V_2 < 0 ) {
V_11 = - 1 ;
error ( L_7 ) ;
break;
}
V_10 -> V_21 = V_8 ;
V_10 -> V_22 = V_2 ;
}
V_11 = F_8 ( V_10 , 0 ) ;
if ( F_4 && V_10 -> V_23 > V_4 ) {
long V_29 = V_10 -> V_23 - V_4 ;
if ( V_29 != F_4 ( V_4 , V_29 ) ) {
V_11 = - 1 ;
error ( L_8 ) ;
break;
}
V_10 -> V_23 = V_4 ;
V_10 -> V_24 = V_5 ;
}
if ( V_11 == V_30 ) {
V_11 = 0 ;
break;
} else if ( V_11 != V_28 ) {
error ( L_9 ) ;
V_11 = - 1 ;
}
}
F_9 ( V_10 ) ;
if ( V_6 )
* V_6 = V_10 -> V_21 - V_8 + 8 ;
V_20:
free ( V_10 -> V_17 ) ;
V_19:
free ( V_10 ) ;
V_16:
if ( ! V_3 )
free ( V_8 ) ;
V_15:
if ( F_4 )
free ( V_4 ) ;
V_13:
return V_11 ;
}
STATIC int T_1 F_10 ( unsigned char * V_3 , long V_2 ,
long (* F_3)( void * , unsigned long ) ,
long (* F_4)( void * , unsigned long ) ,
unsigned char * V_4 ,
long * V_6 ,
void (* error)( char * V_7 ) )
{
return F_2 ( V_3 , V_2 , F_3 , F_4 , V_4 , 0 , V_6 , error ) ;
}
STATIC int T_1 F_11 ( unsigned char * V_3 , long V_2 ,
long (* F_3)( void * , unsigned long ) ,
long (* F_4)( void * , unsigned long ) ,
unsigned char * V_4 , long V_5 ,
long * V_6 ,
void (* error)( char * V_7 ) )
{
return F_2 ( V_3 , V_2 , F_3 , F_4 , V_4 , V_5 , V_6 , error ) ;
}
