static char * F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
if ( V_5 == NULL )
return NULL ;
V_6 = F_3 ( V_5 , V_3 , F_4 ( 0 ) , V_7 ) ;
if ( V_6 >= 0 ) {
if ( ( V_6 & 0xfff0 ) == V_8 )
return L_1 ;
if ( V_6 == V_9 )
return L_2 ;
if ( V_6 == V_10 )
return L_3 ;
if ( ( V_6 & 0xfff0 ) == V_11 )
return L_4 ;
}
return NULL ;
}
static int F_5 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_6 ( V_13 ) ;
int V_6 ;
int V_16 ;
F_7 ( V_17 , 0x04 , 0x6000 ) ;
F_7 ( V_17 , 0x0a , 0x0148 ) ;
V_6 = F_8 ( V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( V_17 , 0x1a , ( F_9 ( V_13 ) * 0x1110 ) ) ;
F_7 ( V_17 , 0x1c , V_13 -> V_18 & 0x1f ) ;
F_7 ( V_19 , 0x02 , 0xffff ) ;
F_7 ( V_19 , 0x03 , 0xffff ) ;
F_7 ( V_19 , 0x05 , 0x00ff ) ;
for ( V_16 = 0 ; V_16 < 32 ; V_16 ++ ) {
int V_20 = 0x1f ;
if ( V_16 != V_13 -> V_18 && V_16 < V_13 -> V_21 -> V_22 -> V_23 )
V_20 = V_13 -> V_22 -> V_24 [ V_16 ] & 0x1f ;
F_7 ( V_19 , 0x06 , 0x8000 | ( V_16 << 8 ) | V_20 ) ;
}
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ )
F_7 ( V_19 , 0x07 , 0x8000 | ( V_16 << 12 ) | 0x7f ) ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ )
F_7 ( V_19 , 0x08 , 0x8000 | ( V_16 << 11 ) ) ;
for ( V_16 = 0 ; V_16 < V_15 -> V_25 ; V_16 ++ )
F_7 ( V_19 , 0x09 , 0x9000 | ( V_16 << 8 ) ) ;
F_7 ( V_19 , 0x0b , 0x9000 ) ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ )
F_7 ( V_19 , 0x0f , 0x8000 | ( V_16 << 8 ) ) ;
return 0 ;
}
static int F_10 ( struct V_12 * V_13 , int V_26 )
{
int V_27 = F_4 ( V_26 ) ;
T_1 V_28 ;
if ( F_11 ( V_13 , V_26 ) || V_13 -> V_29 & ( 1 << V_26 ) )
F_7 ( V_27 , 0x01 , 0x003e ) ;
else
F_7 ( V_27 , 0x01 , 0x0003 ) ;
F_7 ( V_27 , 0x02 , 0x0000 ) ;
V_28 = 0x0433 ;
if ( F_11 ( V_13 , V_26 ) ) {
if ( V_13 -> V_21 -> V_30 == V_31 )
V_28 |= 0x3300 ;
else
V_28 |= 0x0100 ;
}
if ( V_13 -> V_29 & ( 1 << V_26 ) )
V_28 |= 0x0100 ;
if ( V_26 == F_9 ( V_13 ) )
V_28 |= 0x000c ;
F_7 ( V_27 , 0x04 , V_28 ) ;
F_7 ( V_27 , 0x08 , 0x2080 ) ;
F_7 ( V_27 , 0x09 , 0x0001 ) ;
F_7 ( V_27 , 0x0a , 0x0000 ) ;
F_7 ( V_27 , 0x0b , 1 << V_26 ) ;
F_7 ( V_27 , 0x0c , 0x0000 ) ;
F_7 ( V_27 , 0x0d , 0x0000 ) ;
F_7 ( V_27 , 0x0f , V_32 ) ;
F_7 ( V_27 , 0x18 , 0x3210 ) ;
F_7 ( V_27 , 0x19 , 0x7654 ) ;
return F_12 ( V_13 , V_26 ) ;
}
static int F_13 ( struct V_12 * V_13 , int * V_33 )
{
int V_6 ;
* V_33 = 0 ;
V_6 = F_14 ( V_13 , 0 , 6 , 27 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_33 = ( V_6 & 0xff ) - 25 ;
return 0 ;
}
static int F_15 ( struct V_12 * V_13 , int * V_33 )
{
int V_6 ;
* V_33 = 0 ;
V_6 = F_14 ( V_13 , 0 , 6 , 26 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_33 = ( ( ( V_6 >> 8 ) & 0x1f ) * 5 ) - 25 ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 , int V_33 )
{
int V_6 ;
V_6 = F_14 ( V_13 , 0 , 6 , 26 ) ;
if ( V_6 < 0 )
return V_6 ;
V_33 = F_17 ( F_18 ( V_33 , 5 ) + 5 , 0 , 0x1f ) ;
return F_19 ( V_13 , 0 , 6 , 26 ,
( V_6 & 0xe0ff ) | ( V_33 << 8 ) ) ;
}
static int F_20 ( struct V_12 * V_13 , bool * V_34 )
{
int V_6 ;
* V_34 = false ;
V_6 = F_14 ( V_13 , 0 , 6 , 26 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_34 = ! ! ( V_6 & 0x40 ) ;
return 0 ;
}
static int F_21 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_6 ( V_13 ) ;
int V_6 ;
int V_16 ;
V_6 = F_22 ( V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
V_15 -> V_25 = 7 ;
F_23 ( & V_15 -> V_35 ) ;
V_6 = F_24 ( V_13 , true ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_5 ( V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
for ( V_16 = 0 ; V_16 < V_15 -> V_25 ; V_16 ++ ) {
V_6 = F_10 ( V_13 , V_16 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_25 ( struct V_12 * V_13 , int V_27 )
{
struct V_14 * V_15 = F_6 ( V_13 ) ;
int V_6 ;
F_26 ( & V_15 -> V_35 ) ;
V_6 = F_27 ( V_13 , V_19 , 0x14 ,
0xc000 | ( V_27 & 0xff ) ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_28 ( V_13 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_29 ( V_13 , V_19 , 0x15 ) ;
error:
F_30 ( & V_15 -> V_35 ) ;
return V_6 ;
}
static int F_31 ( struct V_12 * V_13 ,
struct V_36 * V_37 , T_2 * V_38 )
{
int V_39 ;
int V_40 ;
int V_6 ;
V_39 = V_37 -> V_39 ;
V_40 = V_37 -> V_40 ;
V_37 -> V_40 = 0 ;
V_37 -> V_41 = 0xc3ec4951 ;
V_6 = F_32 ( V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_39 & 1 ) {
int V_42 ;
V_42 = F_25 ( V_13 , V_39 >> 1 ) ;
if ( V_42 < 0 )
return V_42 ;
* V_38 ++ = ( V_42 >> 8 ) & 0xff ;
V_39 ++ ;
V_40 -- ;
V_37 -> V_40 ++ ;
}
while ( V_40 >= 2 ) {
int V_42 ;
V_42 = F_25 ( V_13 , V_39 >> 1 ) ;
if ( V_42 < 0 )
return V_42 ;
* V_38 ++ = V_42 & 0xff ;
* V_38 ++ = ( V_42 >> 8 ) & 0xff ;
V_39 += 2 ;
V_40 -= 2 ;
V_37 -> V_40 += 2 ;
}
if ( V_40 ) {
int V_42 ;
V_42 = F_25 ( V_13 , V_39 >> 1 ) ;
if ( V_42 < 0 )
return V_42 ;
* V_38 ++ = V_42 & 0xff ;
V_39 ++ ;
V_40 -- ;
V_37 -> V_40 ++ ;
}
return 0 ;
}
static int F_33 ( struct V_12 * V_13 )
{
int V_6 ;
V_6 = F_29 ( V_13 , V_19 , 0x14 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ! ( V_6 & 0x0400 ) )
return - V_43 ;
return 0 ;
}
static int F_34 ( struct V_12 * V_13 , int V_27 ,
T_1 V_38 )
{
struct V_14 * V_15 = F_6 ( V_13 ) ;
int V_6 ;
F_26 ( & V_15 -> V_35 ) ;
V_6 = F_27 ( V_13 , V_19 , 0x15 , V_38 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_27 ( V_13 , V_19 , 0x14 ,
0xb000 | ( V_27 & 0xff ) ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_28 ( V_13 ) ;
error:
F_30 ( & V_15 -> V_35 ) ;
return V_6 ;
}
static int F_35 ( struct V_12 * V_13 ,
struct V_36 * V_37 , T_2 * V_38 )
{
int V_39 ;
int V_6 ;
int V_40 ;
if ( V_37 -> V_41 != 0xc3ec4951 )
return - V_44 ;
V_6 = F_33 ( V_13 ) ;
if ( V_6 )
return V_6 ;
V_39 = V_37 -> V_39 ;
V_40 = V_37 -> V_40 ;
V_37 -> V_40 = 0 ;
V_6 = F_32 ( V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_39 & 1 ) {
int V_42 ;
V_42 = F_25 ( V_13 , V_39 >> 1 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = ( * V_38 ++ << 8 ) | ( V_42 & 0xff ) ;
V_6 = F_34 ( V_13 , V_39 >> 1 , V_42 ) ;
if ( V_6 < 0 )
return V_6 ;
V_39 ++ ;
V_40 -- ;
V_37 -> V_40 ++ ;
}
while ( V_40 >= 2 ) {
int V_42 ;
V_42 = * V_38 ++ ;
V_42 |= * V_38 ++ << 8 ;
V_6 = F_34 ( V_13 , V_39 >> 1 , V_42 ) ;
if ( V_6 < 0 )
return V_6 ;
V_39 += 2 ;
V_40 -= 2 ;
V_37 -> V_40 += 2 ;
}
if ( V_40 ) {
int V_42 ;
V_42 = F_25 ( V_13 , V_39 >> 1 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = ( V_42 & 0xff00 ) | * V_38 ++ ;
V_6 = F_34 ( V_13 , V_39 >> 1 , V_42 ) ;
if ( V_6 < 0 )
return V_6 ;
V_39 ++ ;
V_40 -- ;
V_37 -> V_40 ++ ;
}
return 0 ;
}
