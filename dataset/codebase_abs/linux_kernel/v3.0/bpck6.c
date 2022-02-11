static int F_1 ( T_1 * V_1 , int V_2 , int V_3 )
{
unsigned int V_4 ;
if ( V_3 < 0 || V_3 > 7 || V_2 < 0 || V_2 > 2 )
{
return ( - 1 ) ;
}
V_4 = F_2 ( F_3 ( V_1 ) , V_2 ? V_3 | 8 : V_3 ) ;
return ( V_4 ) ;
}
static void F_4 ( T_1 * V_1 , int V_2 , int V_3 , int V_5 )
{
if ( V_3 >= 0 && V_3 <= 7 && V_2 >= 0 && V_2 <= 1 )
{
F_5 ( F_3 ( V_1 ) , V_2 ? V_3 | 8 : V_3 , ( V_6 ) V_5 ) ;
}
}
static void F_6 ( T_1 * V_1 , char * V_7 , int V_8 )
{
F_7 ( F_3 ( V_1 ) , V_9 , V_7 , ( V_10 ) V_8 >> 1 ) ;
}
static void F_8 ( T_1 * V_1 , char * V_7 , int V_8 )
{
F_9 ( F_3 ( V_1 ) , V_9 , V_7 , ( V_10 ) V_8 >> 1 ) ;
}
static void F_10 ( T_1 * V_1 )
{
if( V_11 )
{
F_11 ( V_12 L_1 ) ;
}
if( V_1 -> V_13 >= 2 )
{
F_3 ( V_1 ) -> V_13 = 4 + V_1 -> V_13 - 2 ;
}
else if( V_1 -> V_13 == 1 )
{
F_3 ( V_1 ) -> V_13 = 3 ;
}
else
{
F_3 ( V_1 ) -> V_13 = 1 ;
}
F_12 ( F_3 ( V_1 ) ) ;
F_13 ( F_3 ( V_1 ) , 0x3 ) ;
}
static void F_14 ( T_1 * V_1 )
{
if( V_11 )
{
F_11 ( L_2 ) ;
}
F_13 ( F_3 ( V_1 ) , 0x0 ) ;
F_15 ( F_3 ( V_1 ) ) ;
}
static int F_16 ( T_1 * V_1 )
{
if( V_11 )
{
F_11 ( V_12 L_3 ,
( (struct V_14 * ) ( V_1 -> V_15 ) ) -> V_16 -> V_17 ,
( (struct V_14 * ) ( V_1 -> V_15 ) ) -> V_16 -> V_18 ) ;
}
F_3 ( V_1 ) -> V_19 = V_1 -> V_20 ;
F_3 ( V_1 ) -> V_21 = V_1 -> V_16 ;
if( ( (struct V_14 * ) ( V_1 -> V_15 ) ) -> V_16 -> V_17 &
( V_22 )
)
{
return 5 ;
}
else if( ( (struct V_14 * ) ( V_1 -> V_15 ) ) -> V_16 -> V_17 &
( V_23 )
)
{
return 2 ;
}
else
{
return 1 ;
}
}
static int F_17 ( T_1 * V_1 )
{
int V_4 ;
if( V_11 )
{
F_11 ( V_12 L_4 , V_1 -> V_20 , V_1 -> V_16 ) ;
}
F_3 ( V_1 ) -> V_19 = V_1 -> V_20 ;
F_3 ( V_1 ) -> V_13 = 1 ;
V_4 = F_12 ( F_3 ( V_1 ) ) ;
if( V_11 )
{
F_11 ( V_12 L_5 , V_4 ) ;
}
if( V_4 )
{
F_15 ( F_3 ( V_1 ) ) ;
if( V_11 )
{
F_11 ( V_12 L_6 ) ;
}
return ( 1 ) ;
}
else
{
if( V_11 )
{
F_11 ( V_12 L_7 ) ;
}
return ( 0 ) ;
}
}
static void F_18 ( T_1 * V_1 , char * V_24 , int V_11 )
{
char * V_25 [ 5 ] =
{ L_8 , L_9 , L_10 , L_11 , L_12 } ;
F_11 ( L_13 V_26 L_14 , V_1 -> V_27 ) ;
F_11 ( L_15 , V_1 -> V_27 ) ;
F_11 ( L_16 ,
V_1 -> V_27 , V_26 , V_1 -> V_16 ) ;
F_11 ( L_17 , V_1 -> V_27 ,
V_1 -> V_20 , V_1 -> V_13 , V_25 [ V_1 -> V_13 ] , V_1 -> V_28 ) ;
}
static int F_19 ( T_1 * V_1 )
{
T_2 * V_29 = F_20 ( sizeof( T_2 ) , V_30 ) ;
if ( V_29 ) {
V_1 -> V_31 = ( unsigned long ) V_29 ;
return 0 ;
}
F_11 ( V_32 L_18 , V_1 -> V_27 ) ;
return - 1 ;
}
static void F_21 ( T_1 * V_1 )
{
F_22 ( ( void * ) ( V_1 -> V_31 ) ) ;
}
static int T_3 F_23 ( void )
{
F_11 ( V_33 L_19 V_26 L_14 ) ;
F_11 ( V_33 L_20 ) ;
if( V_11 )
F_11 ( V_12 L_21 ) ;
return F_24 ( & V_34 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_34 ) ;
}
