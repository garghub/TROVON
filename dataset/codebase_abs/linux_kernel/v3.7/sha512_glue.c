static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 [ 0 ] = V_6 ;
V_4 -> V_5 [ 1 ] = V_7 ;
V_4 -> V_5 [ 2 ] = V_8 ;
V_4 -> V_5 [ 3 ] = V_9 ;
V_4 -> V_5 [ 4 ] = V_10 ;
V_4 -> V_5 [ 5 ] = V_11 ;
V_4 -> V_5 [ 6 ] = V_12 ;
V_4 -> V_5 [ 7 ] = V_13 ;
V_4 -> V_14 [ 0 ] = V_4 -> V_14 [ 1 ] = 0 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 [ 0 ] = V_15 ;
V_4 -> V_5 [ 1 ] = V_16 ;
V_4 -> V_5 [ 2 ] = V_17 ;
V_4 -> V_5 [ 3 ] = V_18 ;
V_4 -> V_5 [ 4 ] = V_19 ;
V_4 -> V_5 [ 5 ] = V_20 ;
V_4 -> V_5 [ 6 ] = V_21 ;
V_4 -> V_5 [ 7 ] = V_22 ;
V_4 -> V_14 [ 0 ] = V_4 -> V_14 [ 1 ] = 0 ;
return 0 ;
}
static void F_4 ( struct V_3 * V_4 , const T_1 * V_23 ,
unsigned int V_24 , unsigned int V_25 )
{
unsigned int V_26 = 0 ;
if ( ( V_4 -> V_14 [ 0 ] += V_24 ) < V_24 )
V_4 -> V_14 [ 1 ] ++ ;
if ( V_25 ) {
V_26 = V_27 - V_25 ;
memcpy ( V_4 -> V_28 + V_25 , V_23 , V_26 ) ;
F_5 ( V_4 -> V_5 , V_4 -> V_28 , 1 ) ;
}
if ( V_24 - V_26 >= V_27 ) {
const unsigned int V_29 = ( V_24 - V_26 ) / V_27 ;
F_5 ( V_4 -> V_5 , V_23 + V_26 , V_29 ) ;
V_26 += V_29 * V_27 ;
}
memcpy ( V_4 -> V_28 , V_23 + V_26 , V_24 - V_26 ) ;
}
static int F_6 ( struct V_1 * V_2 , const T_1 * V_23 ,
unsigned int V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_25 = V_4 -> V_14 [ 0 ] % V_27 ;
if ( V_25 + V_24 < V_27 ) {
if ( ( V_4 -> V_14 [ 0 ] += V_24 ) < V_24 )
V_4 -> V_14 [ 1 ] ++ ;
memcpy ( V_4 -> V_28 + V_25 , V_23 , V_24 ) ;
} else
F_4 ( V_4 , V_23 , V_24 , V_25 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_30 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_31 , V_32 , V_33 ;
T_2 * V_34 = ( T_2 * ) V_30 ;
T_2 V_35 [ 2 ] ;
static const T_1 V_36 [ V_27 ] = { 0x80 , } ;
V_35 [ 1 ] = F_8 ( V_4 -> V_14 [ 0 ] << 3 ) ;
V_35 [ 0 ] = F_8 ( V_4 -> V_14 [ 1 ] << 3 | V_4 -> V_14 [ 0 ] >> 61 ) ;
V_32 = V_4 -> V_14 [ 0 ] % V_27 ;
V_33 = ( V_32 < 112 ) ? ( 112 - V_32 ) : ( ( V_27 + 112 ) - V_32 ) ;
if ( V_33 <= 112 ) {
if ( ( V_4 -> V_14 [ 0 ] += V_33 ) < V_33 )
V_4 -> V_14 [ 1 ] ++ ;
memcpy ( V_4 -> V_28 + V_32 , V_36 , V_33 ) ;
} else {
F_4 ( V_4 , V_36 , V_33 , V_32 ) ;
}
F_4 ( V_4 , ( const T_1 * ) & V_35 , sizeof( V_35 ) , 112 ) ;
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ )
V_34 [ V_31 ] = F_8 ( V_4 -> V_5 [ V_31 ] ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 * V_37 )
{
T_1 V_38 [ 64 ] ;
F_7 ( V_2 , V_38 ) ;
memcpy ( V_37 , V_38 , 48 ) ;
memset ( V_38 , 0 , 64 ) ;
return 0 ;
}
static bool T_3 F_10 ( void )
{
unsigned long V_39 ;
if ( ! ( V_40 & V_41 ) )
return false ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
if ( ! ( V_39 & V_42 ) )
return false ;
return true ;
}
static int T_3 F_11 ( void )
{
if ( F_10 () ) {
int V_43 = F_12 ( & V_44 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_12 ( & V_45 ) ;
if ( V_43 < 0 ) {
F_13 ( & V_44 ) ;
return V_43 ;
}
F_14 ( L_1 ) ;
return 0 ;
}
F_14 ( L_2 ) ;
return - V_46 ;
}
static void T_4 F_15 ( void )
{
F_13 ( & V_44 ) ;
F_13 ( & V_45 ) ;
}
