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
V_4 -> V_14 = 0 ;
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
V_4 -> V_14 = 0 ;
return 0 ;
}
static void F_4 ( struct V_3 * V_4 , const T_1 * V_23 ,
unsigned int V_24 , unsigned int V_25 )
{
unsigned int V_26 = 0 ;
V_4 -> V_14 += V_24 ;
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
unsigned int V_25 = V_4 -> V_14 % V_27 ;
if ( V_25 + V_24 < V_27 ) {
V_4 -> V_14 += V_24 ;
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
T_3 V_35 ;
static const T_1 V_36 [ V_27 ] = { 0x80 , } ;
V_35 = F_8 ( V_4 -> V_14 << 3 ) ;
V_32 = V_4 -> V_14 % V_27 ;
V_33 = ( V_32 < 56 ) ? ( 56 - V_32 ) : ( ( V_27 + 56 ) - V_32 ) ;
if ( V_33 <= 56 ) {
V_4 -> V_14 += V_33 ;
memcpy ( V_4 -> V_28 + V_32 , V_36 , V_33 ) ;
} else {
F_4 ( V_4 , V_36 , V_33 , V_32 ) ;
}
F_4 ( V_4 , ( const T_1 * ) & V_35 , sizeof( V_35 ) , 56 ) ;
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ )
V_34 [ V_31 ] = F_9 ( V_4 -> V_5 [ V_31 ] ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_37 )
{
T_1 V_38 [ V_39 ] ;
F_7 ( V_2 , V_38 ) ;
memcpy ( V_37 , V_38 , V_40 ) ;
F_11 ( V_38 , V_39 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , void * V_30 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memcpy ( V_30 , V_4 , sizeof( * V_4 ) ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , const void * V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memcpy ( V_4 , V_41 , sizeof( * V_4 ) ) ;
return 0 ;
}
static bool T_4 F_14 ( void )
{
unsigned long V_42 ;
if ( ! ( V_43 & V_44 ) )
return false ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
if ( ! ( V_42 & V_45 ) )
return false ;
return true ;
}
static int T_4 F_15 ( void )
{
if ( F_14 () ) {
int V_46 = F_16 ( & V_47 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_16 ( & V_48 ) ;
if ( V_46 < 0 ) {
F_17 ( & V_47 ) ;
return V_46 ;
}
F_18 ( L_1 ) ;
return 0 ;
}
F_18 ( L_2 ) ;
return - V_49 ;
}
static void T_5 F_19 ( void )
{
F_17 ( & V_47 ) ;
F_17 ( & V_48 ) ;
}
