static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
* V_3 = V_4 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
if ( V_4 % 4 ) {
F_3 ( L_1 ,
V_2 -> V_5 ) ;
return - V_6 ;
}
if ( ( V_4 & 0xf0000000 ) != ( ( ( unsigned long ) V_3 + 4 ) & 0xf0000000 ) ) {
F_4 ( V_7
L_2 ,
V_2 -> V_5 ) ;
return - V_6 ;
}
* V_3 = ( * V_3 & ~ 0x03ffffff ) | ( ( V_4 >> 2 ) & 0x03ffffff ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
* V_3 = ( * V_3 & 0xffff0000 ) |
( ( ( ( long long ) V_4 + 0x8000LL ) >> 16 ) & 0xffff ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
* V_3 = ( * V_3 & 0xffff0000 ) | ( V_4 & 0xffff ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
* ( T_2 * ) V_3 = V_4 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_4 )
{
* V_3 = ( * V_3 & 0xffff0000 ) |
( ( ( ( long long ) V_4 + 0x80008000LL ) >> 32 ) & 0xffff ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_4 )
{
* V_3 = ( * V_3 & 0xffff0000 ) |
( ( ( ( long long ) V_4 + 0x800080008000LL ) >> 48 ) & 0xffff ) ;
return 0 ;
}
int F_10 ( T_3 * V_8 , const char * V_9 ,
unsigned int V_10 , unsigned int V_11 ,
struct V_1 * V_2 )
{
T_4 * V_12 = ( void * ) V_8 [ V_11 ] . V_13 ;
T_5 * V_14 ;
T_1 * V_3 ;
unsigned int V_15 ;
T_2 V_4 ;
int V_16 ;
F_11 ( L_3 , V_11 ,
V_8 [ V_11 ] . V_17 ) ;
for ( V_15 = 0 ; V_15 < V_8 [ V_11 ] . V_18 / sizeof( * V_12 ) ; V_15 ++ ) {
V_3 = ( void * ) V_8 [ V_8 [ V_11 ] . V_17 ] . V_13
+ V_12 [ V_15 ] . V_19 ;
V_14 = ( T_5 * ) V_8 [ V_10 ] . V_13
+ F_12 ( V_12 [ V_15 ] ) ;
if ( F_13 ( V_14 -> V_20 ) ) {
if ( F_14 ( V_14 -> V_21 ) == V_22 )
continue;
F_4 ( V_23 L_4 ,
V_2 -> V_5 , V_9 + V_14 -> V_24 ) ;
return - V_25 ;
}
V_4 = V_14 -> V_20 + V_12 [ V_15 ] . V_26 ;
V_16 = V_27 [ F_15 ( V_12 [ V_15 ] ) ] ( V_2 , V_3 , V_4 ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
