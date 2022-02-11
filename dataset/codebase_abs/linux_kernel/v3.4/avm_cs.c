static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 |= V_4 | V_5 ;
V_2 -> V_6 = 1 ;
V_2 -> V_7 = V_8 ;
return F_2 ( V_2 ) ;
}
static void F_3 ( struct V_1 * V_9 )
{
F_4 ( V_9 ) ;
}
static int F_5 ( struct V_1 * V_2 , void * V_10 )
{
V_2 -> V_11 [ 0 ] -> V_12 = 16 ;
V_2 -> V_11 [ 0 ] -> V_13 &= ~ V_14 ;
V_2 -> V_11 [ 0 ] -> V_13 |= V_15 ;
return F_6 ( V_2 ) ;
}
static int F_2 ( struct V_1 * V_9 )
{
int V_16 = - 1 ;
char V_17 [ 128 ] ;
int V_18 ;
int (* F_7)( unsigned int V_19 , unsigned V_20 );
V_17 [ 0 ] = 0 ;
if ( V_9 -> V_21 [ 1 ] )
F_8 ( V_17 , V_9 -> V_21 [ 1 ] , sizeof( V_17 ) ) ;
if ( F_9 ( V_9 , F_5 , NULL ) )
return - V_22 ;
do {
if ( ! V_9 -> V_20 ) {
F_10 ( V_9 ) ;
break;
}
V_16 = F_11 ( V_9 ) ;
if ( V_16 != 0 ) {
F_10 ( V_9 ) ;
break;
}
} while ( 0 );
if ( V_17 [ 0 ] ) {
char * V_23 = strrchr ( V_17 , ' ' ) ;
if ( ! V_23 )
V_23 = V_17 ;
else V_23 ++ ;
if ( strcmp ( L_1 , V_23 ) == 0 ) {
V_18 = V_24 ;
} else if ( strcmp ( L_2 , V_23 ) == 0 ) {
V_18 = V_25 ;
} else {
V_18 = V_26 ;
}
} else
V_18 = V_26 ;
if ( V_16 != 0 ) {
F_4 ( V_9 ) ;
return - V_22 ;
}
switch ( V_18 ) {
case V_24 : F_7 = V_27 ; break;
case V_25 : F_7 = V_28 ; break;
default:
case V_26 : F_7 = V_29 ; break;
}
if ( ( V_16 = (* F_7)( V_9 -> V_11 [ 0 ] -> V_30 , V_9 -> V_20 ) ) < 0 ) {
F_12 ( & V_9 -> V_31 ,
L_3 ,
( unsigned int ) V_9 -> V_11 [ 0 ] -> V_30 , V_9 -> V_20 ) ;
F_4 ( V_9 ) ;
return - V_22 ;
}
return 0 ;
}
static void F_4 ( struct V_1 * V_9 )
{
F_13 ( V_9 -> V_11 [ 0 ] -> V_30 , V_9 -> V_20 ) ;
F_10 ( V_9 ) ;
}
static int T_1 F_14 ( void )
{
return F_15 ( & V_32 ) ;
}
static void T_2 F_16 ( void )
{
F_17 ( & V_32 ) ;
}
