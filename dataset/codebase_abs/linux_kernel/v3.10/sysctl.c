int F_1 ( T_1 * V_1 , int V_2 ,
void * V_3 , T_2 * V_4 , T_3 * V_5 )
{
int V_6 ;
V_6 = F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
if ( ( ! V_2 ) || V_6 )
return V_6 ;
F_3 () ;
return 0 ;
}
int F_4 ( T_1 * V_1 , int V_2 ,
void * V_3 , T_2 * V_4 , T_3 * V_5 )
{
int V_6 ;
V_6 = F_5 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
if ( ( ! V_2 ) || V_6 )
return V_6 ;
F_3 () ;
return 0 ;
}
int F_6 ( T_1 * V_1 , int V_2 ,
void * V_3 , T_2 * V_4 , T_3 * V_5 )
{
struct V_7 V_8 ;
int V_6 ;
if ( ! V_2 ) {
F_7 ( & V_8 ) ;
V_9 = V_8 . V_10 ;
if ( V_9 < 0 )
V_9 = 0 ;
}
V_6 = F_5 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 )
F_8 ( V_9 ) ;
return 0 ;
}
int F_9 ( T_1 * V_1 , int V_2 ,
void * V_3 , T_2 * V_4 , T_3 * V_5 )
{
unsigned int V_11 ;
char * V_12 , V_13 ;
int V_14 ;
char V_15 [ 32 ] ;
if ( ! V_1 -> V_16 || ! V_1 -> V_17 || ! * V_4 ||
( * V_5 && ! V_2 ) ) {
* V_4 = 0 ;
return 0 ;
}
if ( V_2 ) {
V_14 = 0 ;
V_12 = V_3 ;
while ( V_14 < * V_4 ) {
if ( F_10 ( V_13 , V_12 ++ ) )
return - V_18 ;
if ( V_13 == 0 || V_13 == '\n' )
break;
V_14 ++ ;
}
if ( V_14 >= sizeof( V_15 ) - 1 )
V_14 = sizeof( V_15 ) - 1 ;
if ( F_11 ( V_15 , V_3 , V_14 ) )
return - V_18 ;
V_15 [ V_14 ] = 0 ;
* V_5 += * V_4 ;
V_11 = F_12 ( V_15 ) ;
* ( unsigned int * ) ( V_1 -> V_16 ) = V_11 ;
F_3 () ;
} else {
V_11 = * ( unsigned int * ) ( V_1 -> V_16 ) ;
sprintf ( V_15 , L_1 ,
( V_11 ) & 0xff ,
( V_11 >> 8 ) & 0xff ,
( V_11 >> 16 ) & 0xff ,
( V_11 >> 24 ) & 0xff ) ;
V_14 = strlen ( V_15 ) ;
if ( V_14 > * V_4 )
V_14 = * V_4 ;
if ( V_14 )
if ( F_13 ( V_3 , V_15 , V_14 ) )
return - V_18 ;
if ( V_14 < * V_4 ) {
if ( F_14 ( '\n' , ( ( char * ) V_3 ) + V_14 ) )
return - V_18 ;
V_14 ++ ;
}
* V_4 = V_14 ;
* V_5 += V_14 ;
}
return 0 ;
}
int F_15 ( T_1 * V_1 , int V_2 ,
void * V_3 , T_2 * V_4 , T_3 * V_5 )
{
int V_6 ;
V_6 = F_5 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_2 ) {
V_19 . V_20 . V_21 =
V_19 . V_22 ;
F_3 () ;
F_16 () ;
}
return 0 ;
}
static int T_4 F_17 ( void )
{
struct V_23 * V_24 ;
V_24 =
F_18 ( V_25 ) ;
if ( ! V_24 ) {
F_19 ( V_26 L_2 ) ;
return - V_27 ;
}
return 0 ;
}
