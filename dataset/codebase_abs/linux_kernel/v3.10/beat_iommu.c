static int T_1 F_1 ( T_2 * V_1 , T_2 * V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 )
{
struct V_6 * V_7 ;
const unsigned long * V_8 ;
F_2 (dn, L_1 ) {
V_8 = F_3 ( V_7 , L_2 , NULL ) ;
if ( V_8 ) {
* V_1 = ( V_8 [ 0 ] >> 32 ) & 0xffffffffUL ;
* V_2 = V_8 [ 0 ] & 0x7ffUL ;
* V_3 = V_8 [ 1 ] ;
* V_4 = V_8 [ 2 ] ;
* V_5 = 1 << V_8 [ 3 ] ;
F_4 ( V_7 ) ;
return 1 ;
}
}
return 0 ;
}
static void T_1 F_5 ( void )
{
T_2 V_9 , V_10 ;
T_2 V_1 , V_2 , V_11 , V_12 , V_5 ;
if ( ! F_1 ( & V_1 , & V_2 , & V_11 , & V_12 ,
& V_5 ) ) {
F_6 ( L_3 ) ;
return;
}
for ( V_9 = 0 ; V_9 < V_12 ; V_9 += V_5 ) {
V_10 = V_9 + V_11 ;
( void ) F_7 ( V_1 , V_10 , V_9 ,
V_2 , V_13 ) ;
}
V_14 = V_11 ;
}
static void F_8 ( struct V_15 * V_16 )
{
F_9 ( V_16 , & V_17 ) ;
F_10 ( V_16 , V_14 ) ;
}
static void F_11 ( struct V_18 * V_19 )
{
F_8 ( & V_19 -> V_16 ) ;
}
static int F_12 ( struct V_20 * V_21 ,
unsigned long V_22 , void * V_23 )
{
struct V_15 * V_16 = V_23 ;
if ( V_22 != V_24 )
return 0 ;
F_8 ( V_16 ) ;
return 0 ;
}
static int T_1 F_13 ( void )
{
F_5 () ;
V_25 . V_26 = F_11 ;
F_14 ( & V_27 , & V_28 ) ;
return 0 ;
}
