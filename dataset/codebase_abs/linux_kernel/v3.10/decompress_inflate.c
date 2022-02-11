static int T_1 F_1 ( void * V_1 , unsigned int V_2 )
{
return - 1 ;
}
STATIC int T_1 F_2 ( unsigned char * V_3 , int V_2 ,
int (* F_3)( void * , unsigned int ) ,
int (* F_4)( void * , unsigned int ) ,
unsigned char * V_4 ,
int * V_5 ,
void (* error)( char * V_6 ) ) {
T_2 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
T_3 V_11 ;
V_10 = - 1 ;
if ( F_4 ) {
V_11 = 0x8000 ;
V_4 = malloc ( V_11 ) ;
} else {
V_11 = 0x7fffffff ;
}
if ( ! V_4 ) {
error ( L_1 ) ;
goto V_12;
}
if ( V_3 )
V_7 = V_3 ;
else {
V_7 = malloc ( V_13 ) ;
V_2 = 0 ;
}
if ( ! V_7 ) {
error ( L_2 ) ;
goto V_14;
}
V_9 = malloc ( sizeof( * V_9 ) ) ;
if ( V_9 == NULL ) {
error ( L_3 ) ;
goto V_15;
}
V_9 -> V_16 = malloc ( F_4 ? F_5 () :
sizeof( struct V_17 ) ) ;
if ( V_9 -> V_16 == NULL ) {
error ( L_4 ) ;
goto V_18;
}
if ( ! F_3 )
F_3 = F_1 ;
if ( V_2 == 0 )
V_2 = F_3 ( V_7 , V_13 ) ;
if ( V_2 < 10 ||
V_7 [ 0 ] != 0x1f || V_7 [ 1 ] != 0x8b || V_7 [ 2 ] != 0x08 ) {
if ( V_5 )
* V_5 = 0 ;
error ( L_5 ) ;
goto V_19;
}
V_9 -> V_20 = V_7 + 10 ;
V_9 -> V_21 = V_2 - 10 ;
if ( V_7 [ 3 ] & 0x8 ) {
do {
if ( V_9 -> V_21 == 0 ) {
error ( L_6 ) ;
goto V_19;
}
-- V_9 -> V_21 ;
} while ( * V_9 -> V_20 ++ );
}
V_9 -> V_22 = V_4 ;
V_9 -> V_23 = V_11 ;
V_10 = F_6 ( V_9 , - V_24 ) ;
if ( ! F_4 ) {
F_7 ( V_9 ) -> V_17 . V_25 = 0 ;
F_7 ( V_9 ) -> V_17 . V_26 = NULL ;
}
while ( V_10 == V_27 ) {
if ( V_9 -> V_21 == 0 ) {
V_2 = F_3 ( V_7 , V_13 ) ;
if ( V_2 < 0 ) {
V_10 = - 1 ;
error ( L_7 ) ;
break;
}
V_9 -> V_20 = V_7 ;
V_9 -> V_21 = V_2 ;
}
V_10 = F_8 ( V_9 , 0 ) ;
if ( F_4 && V_9 -> V_22 > V_4 ) {
int V_28 = V_9 -> V_22 - V_4 ;
if ( V_28 != F_4 ( V_4 , V_28 ) ) {
V_10 = - 1 ;
error ( L_8 ) ;
break;
}
V_9 -> V_22 = V_4 ;
V_9 -> V_23 = V_11 ;
}
if ( V_10 == V_29 ) {
V_10 = 0 ;
break;
} else if ( V_10 != V_27 ) {
error ( L_9 ) ;
V_10 = - 1 ;
}
}
F_9 ( V_9 ) ;
if ( V_5 )
* V_5 = V_9 -> V_20 - V_7 + 8 ;
V_19:
free ( V_9 -> V_16 ) ;
V_18:
free ( V_9 ) ;
V_15:
if ( ! V_3 )
free ( V_7 ) ;
V_14:
if ( F_4 )
free ( V_4 ) ;
V_12:
return V_10 ;
}
