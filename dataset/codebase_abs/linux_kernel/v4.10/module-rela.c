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
F_3 ( L_2 , V_2 -> V_5 ) ;
return - V_6 ;
}
* V_3 = ( * V_3 & ~ 0x03ffffff ) | ( ( V_4 >> 2 ) & 0x03ffffff ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
* V_3 = ( * V_3 & 0xffff0000 ) |
( ( ( ( long long ) V_4 + 0x8000LL ) >> 16 ) & 0xffff ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
* V_3 = ( * V_3 & 0xffff0000 ) | ( V_4 & 0xffff ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 ,
unsigned V_7 )
{
unsigned long V_8 = F_7 ( V_7 - 1 , 0 ) ;
unsigned long V_9 ;
long V_10 ;
if ( V_4 % 4 ) {
F_3 ( L_3 ,
V_2 -> V_5 , V_7 ) ;
return - V_6 ;
}
V_10 = ( ( long ) V_4 - ( long ) V_3 ) >> 2 ;
V_9 = ( V_10 & F_8 ( V_7 - 1 ) ) ? ~ 0ul : 0 ;
if ( ( V_10 & ~ V_8 ) != ( V_9 & ~ V_8 ) ) {
F_3 ( L_2 , V_2 -> V_5 ) ;
return - V_6 ;
}
* V_3 = ( * V_3 & ~ V_8 ) | ( V_10 & V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
return F_6 ( V_2 , V_3 , V_4 , 16 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
return F_6 ( V_2 , V_3 , V_4 , 21 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
return F_6 ( V_2 , V_3 , V_4 , 26 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
* ( T_2 * ) V_3 = V_4 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_4 )
{
* V_3 = ( * V_3 & 0xffff0000 ) |
( ( ( ( long long ) V_4 + 0x80008000LL ) >> 32 ) & 0xffff ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_4 )
{
* V_3 = ( * V_3 & 0xffff0000 ) |
( ( ( ( long long ) V_4 + 0x800080008000LL ) >> 48 ) & 0xffff ) ;
return 0 ;
}
int F_15 ( T_3 * V_11 , const char * V_12 ,
unsigned int V_13 , unsigned int V_14 ,
struct V_1 * V_2 )
{
T_4 * V_15 = ( void * ) V_11 [ V_14 ] . V_16 ;
int (* F_16)( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 );
T_5 * V_17 ;
T_1 * V_3 ;
unsigned int V_18 , type ;
T_2 V_4 ;
int V_19 ;
F_17 ( L_4 , V_14 ,
V_11 [ V_14 ] . V_20 ) ;
for ( V_18 = 0 ; V_18 < V_11 [ V_14 ] . V_21 / sizeof( * V_15 ) ; V_18 ++ ) {
V_3 = ( void * ) V_11 [ V_11 [ V_14 ] . V_20 ] . V_16
+ V_15 [ V_18 ] . V_22 ;
V_17 = ( T_5 * ) V_11 [ V_13 ] . V_16
+ F_18 ( V_15 [ V_18 ] ) ;
if ( V_17 -> V_23 >= - V_24 ) {
if ( F_19 ( V_17 -> V_25 ) == V_26 )
continue;
F_20 ( L_5 ,
V_2 -> V_5 , V_12 + V_17 -> V_27 ) ;
return - V_28 ;
}
type = F_21 ( V_15 [ V_18 ] ) ;
if ( type < F_22 ( V_29 ) )
F_16 = V_29 [ type ] ;
else
F_16 = NULL ;
if ( ! F_16 ) {
F_3 ( L_6 ,
V_2 -> V_5 , type ) ;
return - V_30 ;
}
V_4 = V_17 -> V_23 + V_15 [ V_18 ] . V_31 ;
V_19 = F_16 ( V_2 , V_3 , V_4 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
