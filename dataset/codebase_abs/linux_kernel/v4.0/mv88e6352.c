static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , T_1 V_5 )
{
unsigned long V_6 = V_7 + V_8 / 10 ;
while ( F_2 ( V_7 , V_6 ) ) {
int V_9 ;
V_9 = F_3 ( V_3 , V_4 ) ;
if ( ! ( V_9 & V_5 ) )
return 0 ;
F_4 ( 1000 , 2000 ) ;
}
return - V_10 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_11 , 0x18 , 0x8000 ) ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_11 , 0x14 , 0x0800 ) ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_11 , 0x14 , 0x8000 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_12 , int V_13 )
{
int V_9 ;
F_9 ( V_11 , 0x18 , 0x9800 | ( V_12 << 5 ) | V_13 ) ;
V_9 = F_5 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_3 ( V_11 , 0x19 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_12 , int V_13 ,
T_1 V_14 )
{
F_9 ( V_11 , 0x19 , V_14 ) ;
F_9 ( V_11 , 0x18 , 0x9400 | ( V_12 << 5 ) | V_13 ) ;
return F_5 ( V_2 ) ;
}
static char * F_11 ( struct V_15 * V_16 , int V_17 )
{
struct V_18 * V_19 = F_12 ( V_16 ) ;
int V_9 ;
if ( V_19 == NULL )
return NULL ;
V_9 = F_13 ( V_19 , V_17 , F_14 ( 0 ) , 0x03 ) ;
if ( V_9 >= 0 ) {
if ( ( V_9 & 0xfff0 ) == 0x1760 )
return L_1 ;
if ( V_9 == 0x3521 )
return L_2 ;
if ( V_9 == 0x3522 )
return L_3 ;
if ( ( V_9 & 0xfff0 ) == 0x3520 )
return L_4 ;
}
return NULL ;
}
static int F_15 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
int V_9 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < 7 ; V_20 ++ ) {
V_9 = F_3 ( F_14 ( V_20 ) , 0x04 ) ;
F_9 ( F_14 ( V_20 ) , 0x04 , V_9 & 0xfffc ) ;
}
F_4 ( 2000 , 4000 ) ;
F_9 ( V_21 , 0x04 , 0xc000 ) ;
V_6 = V_7 + 1 * V_8 ;
while ( F_2 ( V_7 , V_6 ) ) {
V_9 = F_3 ( V_21 , 0x00 ) ;
if ( ( V_9 & 0x8800 ) == 0x8800 )
break;
F_4 ( 1000 , 2000 ) ;
}
if ( F_16 ( V_7 , V_6 ) )
return - V_10 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_9 ;
int V_20 ;
F_9 ( V_21 , 0x04 , 0x6000 ) ;
F_9 ( V_21 , 0x0a , 0x0148 ) ;
V_9 = F_18 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
F_9 ( V_21 , 0x1a , ( F_19 ( V_2 ) * 0x1110 ) ) ;
F_9 ( V_21 , 0x1c , V_2 -> V_22 & 0x1f ) ;
F_9 ( V_11 , 0x02 , 0xffff ) ;
F_9 ( V_11 , 0x03 , 0xffff ) ;
F_9 ( V_11 , 0x05 , 0x00ff ) ;
for ( V_20 = 0 ; V_20 < 32 ; V_20 ++ ) {
int V_23 = 0x1f ;
if ( V_20 != V_2 -> V_22 && V_20 < V_2 -> V_24 -> V_25 -> V_26 )
V_23 = V_2 -> V_25 -> V_27 [ V_20 ] & 0x1f ;
F_9 ( V_11 , 0x06 , 0x8000 | ( V_20 << 8 ) | V_23 ) ;
}
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ )
F_9 ( V_11 , 0x07 , 0x8000 | ( V_20 << 12 ) | 0x7f ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
F_9 ( V_11 , 0x08 , 0x8000 | ( V_20 << 11 ) ) ;
for ( V_20 = 0 ; V_20 < 7 ; V_20 ++ )
F_9 ( V_11 , 0x09 , 0x9000 | ( V_20 << 8 ) ) ;
F_9 ( V_11 , 0x0b , 0x9000 ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
F_9 ( V_11 , 0x0f , 0x8000 | ( V_20 << 8 ) ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_28 )
{
int V_12 = F_14 ( V_28 ) ;
T_1 V_14 ;
if ( F_21 ( V_2 , V_28 ) || V_2 -> V_29 & ( 1 << V_28 ) )
F_9 ( V_12 , 0x01 , 0x003e ) ;
else
F_9 ( V_12 , 0x01 , 0x0003 ) ;
F_9 ( V_12 , 0x02 , 0x0000 ) ;
V_14 = 0x0433 ;
if ( F_21 ( V_2 , V_28 ) ) {
if ( V_2 -> V_24 -> V_30 == V_31 )
V_14 |= 0x3300 ;
else
V_14 |= 0x0100 ;
}
if ( V_2 -> V_29 & ( 1 << V_28 ) )
V_14 |= 0x0100 ;
if ( V_28 == F_19 ( V_2 ) )
V_14 |= 0x000c ;
F_9 ( V_12 , 0x04 , V_14 ) ;
F_9 ( V_12 , 0x05 , F_21 ( V_2 , V_28 ) ? 0x8000 : 0x0000 ) ;
V_14 = ( V_28 & 0xf ) << 12 ;
if ( F_21 ( V_2 , V_28 ) )
V_14 |= V_2 -> V_32 ;
else
V_14 |= 1 << F_19 ( V_2 ) ;
F_9 ( V_12 , 0x06 , V_14 ) ;
F_9 ( V_12 , 0x07 , 0x0000 ) ;
F_9 ( V_12 , 0x08 , 0x2080 ) ;
F_9 ( V_12 , 0x09 , 0x0001 ) ;
F_9 ( V_12 , 0x0a , 0x0000 ) ;
F_9 ( V_12 , 0x0b , 1 << V_28 ) ;
F_9 ( V_12 , 0x0c , 0x0000 ) ;
F_9 ( V_12 , 0x0d , 0x0000 ) ;
F_9 ( V_12 , 0x0f , V_33 ) ;
F_9 ( V_12 , 0x18 , 0x3210 ) ;
F_9 ( V_12 , 0x19 , 0x7654 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
int V_34 , int V_35 , int V_3 )
{
struct V_36 * V_37 = F_23 ( V_2 ) ;
int V_9 ;
F_24 ( & V_37 -> V_38 ) ;
V_9 = F_10 ( V_2 , V_34 , 0x16 , V_35 ) ;
if ( V_9 < 0 )
goto error;
V_9 = F_8 ( V_2 , V_34 , V_3 ) ;
error:
F_10 ( V_2 , V_34 , 0x16 , 0x0 ) ;
F_25 ( & V_37 -> V_38 ) ;
return V_9 ;
}
static int F_26 ( struct V_1 * V_2 ,
int V_34 , int V_35 , int V_3 , int V_14 )
{
struct V_36 * V_37 = F_23 ( V_2 ) ;
int V_9 ;
F_24 ( & V_37 -> V_38 ) ;
V_9 = F_10 ( V_2 , V_34 , 0x16 , V_35 ) ;
if ( V_9 < 0 )
goto error;
V_9 = F_10 ( V_2 , V_34 , V_3 , V_14 ) ;
error:
F_10 ( V_2 , V_34 , 0x16 , 0x0 ) ;
F_25 ( & V_37 -> V_38 ) ;
return V_9 ;
}
static int F_27 ( struct V_1 * V_2 , int * V_39 )
{
int V_9 ;
* V_39 = 0 ;
V_9 = F_22 ( V_2 , 0 , 6 , 27 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_39 = ( V_9 & 0xff ) - 25 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , int * V_39 )
{
int V_9 ;
* V_39 = 0 ;
V_9 = F_22 ( V_2 , 0 , 6 , 26 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_39 = ( ( ( V_9 >> 8 ) & 0x1f ) * 5 ) - 25 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , int V_39 )
{
int V_9 ;
V_9 = F_22 ( V_2 , 0 , 6 , 26 ) ;
if ( V_9 < 0 )
return V_9 ;
V_39 = F_30 ( F_31 ( V_39 , 5 ) + 5 , 0 , 0x1f ) ;
return F_26 ( V_2 , 0 , 6 , 26 ,
( V_9 & 0xe0ff ) | ( V_39 << 8 ) ) ;
}
static int F_32 ( struct V_1 * V_2 , bool * V_40 )
{
int V_9 ;
* V_40 = false ;
V_9 = F_22 ( V_2 , 0 , 6 , 26 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_40 = ! ! ( V_9 & 0x40 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_23 ( V_2 ) ;
int V_9 ;
int V_20 ;
F_34 ( & V_37 -> V_41 ) ;
F_34 ( & V_37 -> V_42 ) ;
F_34 ( & V_37 -> V_38 ) ;
F_34 ( & V_37 -> V_43 ) ;
V_37 -> V_44 = F_3 ( F_14 ( 0 ) , 0x03 ) & 0xfff0 ;
V_9 = F_15 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_17 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
for ( V_20 = 0 ; V_20 < 7 ; V_20 ++ ) {
V_9 = F_20 ( V_2 , V_20 ) ;
if ( V_9 < 0 )
return V_9 ;
}
return 0 ;
}
static int F_35 ( int V_34 )
{
if ( V_34 >= 0 && V_34 <= 4 )
return V_34 ;
return - V_45 ;
}
static int
F_36 ( struct V_1 * V_2 , int V_34 , int V_13 )
{
struct V_36 * V_37 = F_23 ( V_2 ) ;
int V_12 = F_35 ( V_34 ) ;
int V_9 ;
if ( V_12 < 0 )
return V_12 ;
F_24 ( & V_37 -> V_38 ) ;
V_9 = F_8 ( V_2 , V_12 , V_13 ) ;
F_25 ( & V_37 -> V_38 ) ;
return V_9 ;
}
static int
F_37 ( struct V_1 * V_2 , int V_34 , int V_13 , T_1 V_14 )
{
struct V_36 * V_37 = F_23 ( V_2 ) ;
int V_12 = F_35 ( V_34 ) ;
int V_9 ;
if ( V_12 < 0 )
return V_12 ;
F_24 ( & V_37 -> V_38 ) ;
V_9 = F_10 ( V_2 , V_12 , V_13 , V_14 ) ;
F_25 ( & V_37 -> V_38 ) ;
return V_9 ;
}
static int F_38 ( struct V_1 * V_2 , int V_12 )
{
struct V_36 * V_37 = F_23 ( V_2 ) ;
int V_9 ;
F_24 ( & V_37 -> V_43 ) ;
V_9 = F_39 ( V_2 , V_11 , 0x14 ,
0xc000 | ( V_12 & 0xff ) ) ;
if ( V_9 < 0 )
goto error;
V_9 = F_7 ( V_2 ) ;
if ( V_9 < 0 )
goto error;
V_9 = F_40 ( V_2 , V_11 , 0x15 ) ;
error:
F_25 ( & V_37 -> V_43 ) ;
return V_9 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_46 * V_47 , T_2 * V_48 )
{
int V_4 ;
int V_49 ;
int V_9 ;
V_4 = V_47 -> V_4 ;
V_49 = V_47 -> V_49 ;
V_47 -> V_49 = 0 ;
V_47 -> V_50 = 0xc3ec4951 ;
V_9 = F_6 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_4 & 1 ) {
int V_51 ;
V_51 = F_38 ( V_2 , V_4 >> 1 ) ;
if ( V_51 < 0 )
return V_51 ;
* V_48 ++ = ( V_51 >> 8 ) & 0xff ;
V_4 ++ ;
V_49 -- ;
V_47 -> V_49 ++ ;
}
while ( V_49 >= 2 ) {
int V_51 ;
V_51 = F_38 ( V_2 , V_4 >> 1 ) ;
if ( V_51 < 0 )
return V_51 ;
* V_48 ++ = V_51 & 0xff ;
* V_48 ++ = ( V_51 >> 8 ) & 0xff ;
V_4 += 2 ;
V_49 -= 2 ;
V_47 -> V_49 += 2 ;
}
if ( V_49 ) {
int V_51 ;
V_51 = F_38 ( V_2 , V_4 >> 1 ) ;
if ( V_51 < 0 )
return V_51 ;
* V_48 ++ = V_51 & 0xff ;
V_4 ++ ;
V_49 -- ;
V_47 -> V_49 ++ ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_40 ( V_2 , V_11 , 0x14 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! ( V_9 & 0x0400 ) )
return - V_52 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , int V_12 ,
T_1 V_48 )
{
struct V_36 * V_37 = F_23 ( V_2 ) ;
int V_9 ;
F_24 ( & V_37 -> V_43 ) ;
V_9 = F_39 ( V_2 , V_11 , 0x15 , V_48 ) ;
if ( V_9 < 0 )
goto error;
V_9 = F_39 ( V_2 , V_11 , 0x14 ,
0xb000 | ( V_12 & 0xff ) ) ;
if ( V_9 < 0 )
goto error;
V_9 = F_7 ( V_2 ) ;
error:
F_25 ( & V_37 -> V_43 ) ;
return V_9 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_46 * V_47 , T_2 * V_48 )
{
int V_4 ;
int V_9 ;
int V_49 ;
if ( V_47 -> V_50 != 0xc3ec4951 )
return - V_45 ;
V_9 = F_42 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_4 = V_47 -> V_4 ;
V_49 = V_47 -> V_49 ;
V_47 -> V_49 = 0 ;
V_9 = F_6 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_4 & 1 ) {
int V_51 ;
V_51 = F_38 ( V_2 , V_4 >> 1 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 = ( * V_48 ++ << 8 ) | ( V_51 & 0xff ) ;
V_9 = F_43 ( V_2 , V_4 >> 1 , V_51 ) ;
if ( V_9 < 0 )
return V_9 ;
V_4 ++ ;
V_49 -- ;
V_47 -> V_49 ++ ;
}
while ( V_49 >= 2 ) {
int V_51 ;
V_51 = * V_48 ++ ;
V_51 |= * V_48 ++ << 8 ;
V_9 = F_43 ( V_2 , V_4 >> 1 , V_51 ) ;
if ( V_9 < 0 )
return V_9 ;
V_4 += 2 ;
V_49 -= 2 ;
V_47 -> V_49 += 2 ;
}
if ( V_49 ) {
int V_51 ;
V_51 = F_38 ( V_2 , V_4 >> 1 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 = ( V_51 & 0xff00 ) | * V_48 ++ ;
V_9 = F_43 ( V_2 , V_4 >> 1 , V_51 ) ;
if ( V_9 < 0 )
return V_9 ;
V_4 ++ ;
V_49 -- ;
V_47 -> V_49 ++ ;
}
return 0 ;
}
static void
F_45 ( struct V_1 * V_2 , int V_34 , T_3 * V_48 )
{
F_46 ( V_2 , F_47 ( V_53 ) ,
V_53 , V_34 , V_48 ) ;
}
static void
F_48 ( struct V_1 * V_2 , int V_34 , T_4 * V_48 )
{
F_49 ( V_2 , F_47 ( V_53 ) ,
V_53 , V_34 , V_48 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
return F_47 ( V_53 ) ;
}
