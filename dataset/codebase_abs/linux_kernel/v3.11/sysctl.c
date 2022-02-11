int F_1 ( struct V_1 * V_2 , int V_3 ,
void * V_4 , T_1 * V_5 , T_2 * V_6 )
{
int V_7 ;
V_7 = F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( ( ! V_3 ) || V_7 )
return V_7 ;
F_3 () ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , int V_3 ,
void * V_4 , T_1 * V_5 , T_2 * V_6 )
{
int V_7 ;
V_7 = F_5 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( ( ! V_3 ) || V_7 )
return V_7 ;
F_3 () ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , int V_3 ,
void * V_4 , T_1 * V_5 , T_2 * V_6 )
{
struct V_8 V_9 ;
int V_7 ;
if ( ! V_3 ) {
F_7 ( & V_9 ) ;
V_10 = V_9 . V_11 ;
if ( V_10 < 0 )
V_10 = 0 ;
}
V_7 = F_5 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_7 )
return V_7 ;
if ( V_3 )
F_8 ( V_10 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , int V_3 ,
void * V_4 , T_1 * V_5 , T_2 * V_6 )
{
unsigned int V_12 ;
char * V_13 , V_14 ;
int V_15 ;
char V_16 [ 32 ] ;
if ( ! V_2 -> V_17 || ! V_2 -> V_18 || ! * V_5 ||
( * V_6 && ! V_3 ) ) {
* V_5 = 0 ;
return 0 ;
}
if ( V_3 ) {
V_15 = 0 ;
V_13 = V_4 ;
while ( V_15 < * V_5 ) {
if ( F_10 ( V_14 , V_13 ++ ) )
return - V_19 ;
if ( V_14 == 0 || V_14 == '\n' )
break;
V_15 ++ ;
}
if ( V_15 >= sizeof( V_16 ) - 1 )
V_15 = sizeof( V_16 ) - 1 ;
if ( F_11 ( V_16 , V_4 , V_15 ) )
return - V_19 ;
V_16 [ V_15 ] = 0 ;
* V_6 += * V_5 ;
V_12 = F_12 ( V_16 ) ;
* ( unsigned int * ) ( V_2 -> V_17 ) = V_12 ;
F_3 () ;
} else {
V_12 = * ( unsigned int * ) ( V_2 -> V_17 ) ;
sprintf ( V_16 , L_1 ,
( V_12 ) & 0xff ,
( V_12 >> 8 ) & 0xff ,
( V_12 >> 16 ) & 0xff ,
( V_12 >> 24 ) & 0xff ) ;
V_15 = strlen ( V_16 ) ;
if ( V_15 > * V_5 )
V_15 = * V_5 ;
if ( V_15 )
if ( F_13 ( V_4 , V_16 , V_15 ) )
return - V_19 ;
if ( V_15 < * V_5 ) {
if ( F_14 ( '\n' , ( ( char * ) V_4 ) + V_15 ) )
return - V_19 ;
V_15 ++ ;
}
* V_5 = V_15 ;
* V_6 += V_15 ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_2 , int V_3 ,
void * V_4 , T_1 * V_5 , T_2 * V_6 )
{
int V_7 ;
V_7 = F_5 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_3 ) {
V_20 . V_21 . V_22 =
V_20 . V_23 ;
F_3 () ;
F_16 () ;
}
return 0 ;
}
static int T_3 F_17 ( void )
{
struct V_24 * V_25 ;
V_25 =
F_18 ( V_26 ) ;
if ( ! V_25 ) {
F_19 ( V_27 L_2 ) ;
return - V_28 ;
}
return 0 ;
}
