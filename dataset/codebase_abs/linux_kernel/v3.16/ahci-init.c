static void F_1 ( T_1 V_1 , T_2 V_2 , T_2 V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_1 , V_2 , ( V_4 & ~ V_3 ) ) ;
}
static void F_4 ( T_1 V_1 , T_2 V_2 , T_2 V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_1 , V_2 ) ;
F_3 ( V_1 , V_2 , ( V_4 | V_3 ) ) ;
}
static void F_5 ( int V_5 )
{
T_2 V_4 ;
T_1 V_1 ;
int V_6 ;
F_6 ( L_1 ) ;
V_1 = F_7 ( V_5 ) ;
F_1 ( V_1 , V_7 , V_8 ) ;
F_1 ( V_1 , V_7 ,
( V_9 | V_10
| V_11 | V_12 ) ) ;
F_4 ( V_1 , V_7 , V_8 ) ;
F_4 ( V_1 , V_7 ,
( V_9 | V_10
| V_11 | V_12 ) ) ;
F_8 ( L_2 ) ;
V_6 = 0 ;
do {
V_4 = F_2 ( V_1 , V_13 ) ;
V_6 ++ ;
} while ( ( ( V_4 & 0xF0 ) != 0xF0 ) && ( V_6 < 10000 ) );
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
if ( V_4 & ( V_14 << V_6 ) )
F_6 ( L_3 , V_6 ) ;
else
F_6 ( L_4 , V_6 ) ;
}
F_6 ( L_5 ) ;
}
static int T_3 F_9 ( void )
{
int V_5 = 0 ;
int V_15 = F_10 () & V_16 ;
if ( V_15 == V_17 )
F_5 ( V_5 ) ;
return 0 ;
}
static void F_11 ( struct V_18 * V_19 )
{
T_2 V_20 = 0 ;
T_1 V_1 ;
V_1 = F_7 ( F_12 () ) ;
V_20 = F_2 ( V_1 , V_21 ) ;
F_4 ( V_1 , V_21 , V_20 ) ;
}
static void F_13 ( struct V_22 * V_23 )
{
V_23 -> V_24 [ 5 ] = V_23 -> V_24 [ 0 ] ;
memset ( & V_23 -> V_24 [ 0 ] , 0 , sizeof( V_23 -> V_24 [ 0 ] ) ) ;
}
static void F_14 ( struct V_22 * V_23 )
{
T_2 V_20 ;
T_1 V_1 ;
int V_5 = 0 ;
V_1 = F_7 ( V_5 ) ;
V_20 = F_2 ( V_1 , V_21 ) ;
F_4 ( V_1 , V_21 , V_20 ) ;
F_4 ( V_1 , V_25 , 0x1 ) ;
V_23 -> V_26 = V_27 ;
F_15 ( V_5 , V_27 , F_11 ) ;
}
