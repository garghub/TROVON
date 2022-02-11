static char * F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
if ( V_5 == NULL )
return NULL ;
V_6 = F_3 ( V_5 , V_3 , F_4 ( 0 ) , 0x03 ) ;
if ( V_6 >= 0 ) {
if ( ( V_6 & 0xfff0 ) == 0x1710 )
return L_1 ;
}
return NULL ;
}
static int F_5 ( struct V_7 * V_8 )
{
int V_9 ;
int V_6 ;
unsigned long V_10 ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
V_6 = F_6 ( F_4 ( V_9 ) , 0x04 ) ;
F_7 ( F_4 ( V_9 ) , 0x04 , V_6 & 0xfffc ) ;
}
F_8 ( 2000 , 4000 ) ;
F_7 ( V_11 , 0x04 , 0xc400 ) ;
V_10 = V_12 + 1 * V_13 ;
while ( F_9 ( V_12 , V_10 ) ) {
V_6 = F_6 ( V_11 , 0x00 ) ;
if ( ( V_6 & 0xc800 ) == 0xc800 )
break;
F_8 ( 1000 , 2000 ) ;
}
if ( F_10 ( V_12 , V_10 ) )
return - V_14 ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
if ( F_11 ( V_8 , V_9 ) || V_8 -> V_15 & ( 1 << V_9 ) )
continue;
V_6 = F_6 ( F_4 ( V_9 ) , 0x04 ) ;
F_7 ( F_4 ( V_9 ) , 0x04 , V_6 | 0x03 ) ;
}
return 0 ;
}
static int F_12 ( struct V_7 * V_8 )
{
int V_6 ;
int V_9 ;
F_7 ( V_11 , 0x04 , 0x0000 ) ;
F_7 ( V_11 , 0x0a , 0x0148 ) ;
V_6 = F_13 ( V_8 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_6 ( F_4 ( 0 ) , 0x03 ) == 0x1710 )
F_7 ( V_11 , 0x1a , ( F_14 ( V_8 ) * 0x1111 ) ) ;
else
F_7 ( V_11 , 0x1a , ( F_14 ( V_8 ) * 0x1110 ) ) ;
F_7 ( V_11 , 0x1c , V_8 -> V_16 & 0x1f ) ;
F_7 ( V_17 , 0x02 , 0xffff ) ;
F_7 ( V_17 , 0x03 , 0xffff ) ;
F_7 ( V_17 , 0x05 , 0x00ff ) ;
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
int V_18 ;
V_18 = 0x1f ;
if ( V_9 != V_8 -> V_16 && V_9 < V_8 -> V_19 -> V_20 -> V_21 )
V_18 = V_8 -> V_20 -> V_22 [ V_9 ] & 0x1f ;
F_7 ( V_17 , 0x06 , 0x8000 | ( V_9 << 8 ) | V_18 ) ;
}
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ )
F_7 ( V_17 , 0x07 , 0x8000 | ( V_9 << 12 ) | 0xff ) ;
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ )
F_7 ( V_17 , 0x08 , 0x8000 | ( V_9 << 11 ) ) ;
for ( V_9 = 0 ; V_9 < 6 ; V_9 ++ )
F_7 ( V_17 , 0x09 , 0x9000 | ( V_9 << 8 ) ) ;
F_7 ( V_17 , 0x0b , 0x9000 ) ;
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ )
F_7 ( V_17 , 0x0f , 0x8000 | ( V_9 << 8 ) ) ;
return 0 ;
}
static int F_15 ( struct V_7 * V_8 , int V_23 )
{
int V_24 = F_4 ( V_23 ) ;
T_1 V_25 ;
V_25 = F_6 ( V_24 , 0x01 ) ;
if ( F_11 ( V_8 , V_23 ) || V_8 -> V_26 & ( 1 << V_23 ) )
F_7 ( V_24 , 0x01 , V_25 | 0x003e ) ;
else
F_7 ( V_24 , 0x01 , V_25 | 0x0003 ) ;
F_7 ( V_24 , 0x02 , 0x0000 ) ;
V_25 = 0x0433 ;
if ( F_11 ( V_8 , V_23 ) ) {
if ( V_8 -> V_19 -> V_27 == V_28 )
V_25 |= 0x3300 ;
else
V_25 |= 0x0100 ;
}
if ( V_8 -> V_26 & ( 1 << V_23 ) )
V_25 |= 0x0100 ;
if ( V_23 == F_14 ( V_8 ) )
V_25 |= 0x000c ;
F_7 ( V_24 , 0x04 , V_25 ) ;
F_7 ( V_24 , 0x05 , F_11 ( V_8 , V_23 ) ? 0x8000 : 0x0000 ) ;
V_25 = ( V_23 & 0xf ) << 12 ;
if ( F_11 ( V_8 , V_23 ) )
V_25 |= V_8 -> V_15 ;
else
V_25 |= 1 << F_14 ( V_8 ) ;
F_7 ( V_24 , 0x06 , V_25 ) ;
F_7 ( V_24 , 0x07 , 0x0000 ) ;
F_7 ( V_24 , 0x08 , 0x2080 ) ;
F_7 ( V_24 , 0x09 , 0x0001 ) ;
F_7 ( V_24 , 0x0a , 0x0000 ) ;
F_7 ( V_24 , 0x0b , 1 << V_23 ) ;
F_7 ( V_24 , 0x0c , 0x0000 ) ;
F_7 ( V_24 , 0x0d , 0x0000 ) ;
F_7 ( V_24 , 0x0f , V_29 ) ;
F_7 ( V_24 , 0x18 , 0x3210 ) ;
F_7 ( V_24 , 0x19 , 0x7654 ) ;
return 0 ;
}
static int F_16 ( struct V_7 * V_8 )
{
struct V_30 * V_31 = ( void * ) ( V_8 + 1 ) ;
int V_9 ;
int V_6 ;
F_17 ( & V_31 -> V_32 ) ;
F_17 ( & V_31 -> V_33 ) ;
V_6 = F_5 ( V_8 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_12 ( V_8 ) ;
if ( V_6 < 0 )
return V_6 ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
if ( ! ( F_11 ( V_8 , V_9 ) || V_8 -> V_15 & ( 1 << V_9 ) ) )
continue;
V_6 = F_15 ( V_8 , V_9 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_18 ( int V_34 )
{
if ( V_34 >= 0 && V_34 <= 4 )
return V_34 ;
return - 1 ;
}
static int
F_19 ( struct V_7 * V_8 , int V_34 , int V_35 )
{
int V_24 = F_18 ( V_34 ) ;
return F_20 ( V_8 , V_24 , V_35 ) ;
}
static int
F_21 ( struct V_7 * V_8 ,
int V_34 , int V_35 , T_1 V_25 )
{
int V_24 = F_18 ( V_34 ) ;
return F_22 ( V_8 , V_24 , V_35 , V_25 ) ;
}
static void
F_23 ( struct V_7 * V_8 , int V_34 , T_2 * V_36 )
{
F_24 ( V_8 , F_25 ( V_37 ) ,
V_37 , V_34 , V_36 ) ;
}
static void
F_26 ( struct V_7 * V_8 ,
int V_34 , T_3 * V_36 )
{
F_27 ( V_8 , F_25 ( V_37 ) ,
V_37 , V_34 , V_36 ) ;
}
static int F_28 ( struct V_7 * V_8 )
{
return F_25 ( V_37 ) ;
}
