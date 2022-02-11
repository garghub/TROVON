int F_1 ( T_1 * V_1 )
{
T_2 V_2 , V_3 ;
T_3 V_4 ;
T_4 V_5 ;
T_4 V_6 ;
int V_7 ;
V_8 ;
F_2 ( & V_2 ) ;
F_3 ( & V_5 ) ;
V_7 = F_4 ( & V_4 , & V_3 , & V_6 ) ;
if ( ! V_7 || memcmp ( & V_5 , & V_6 , sizeof V_5 ) )
V_4 = F_5 () ;
else if ( V_2 < V_3 )
V_4 ++ ;
F_6 ( V_4 , V_2 , V_5 ) ;
V_9 ;
F_7 ( V_1 , V_4 , V_2 , V_5 ) ;
return 1 ;
}
void F_7 ( T_1 * V_1 , T_3 V_10 ,
T_2 V_2 , T_4 V_5 )
{
V_1 -> V_11 = ( unsigned long ) ( V_2 & 0xFFFFFFFF ) ;
V_1 -> V_12 = ( unsigned short ) ( ( V_2 >> 32 ) & 0xFFFF ) ;
V_1 -> V_13 =
( unsigned short ) ( ( V_2 >> 48 ) & 0x0FFF ) ;
V_1 -> V_13 |= ( 1 << 12 ) ;
V_1 -> V_14 = V_10 & 0xFF ;
V_1 -> V_15 = ( V_10 & 0x3F00 ) >> 8 ;
V_1 -> V_15 |= 0x80 ;
memcpy ( & V_1 -> V_5 , & V_5 , sizeof V_1 -> V_5 ) ;
}
int F_4 ( T_3 * V_4 , T_2 * V_2 ,
T_4 * V_5 )
{
static int V_16 = 0 ;
T_5 * V_17 ;
if ( ! V_16 ) {
V_17 = fopen ( L_1 , L_2 ) ;
if ( V_17 == NULL )
return 0 ;
fread ( & V_18 , sizeof V_18 , 1 , V_17 ) ;
fclose ( V_17 ) ;
V_16 = 1 ;
}
* V_4 = V_18 . V_19 ;
* V_2 = V_18 . V_20 ;
* V_5 = V_18 . V_5 ;
return 1 ;
}
void F_6 ( T_3 V_4 , T_2 V_2 ,
T_4 V_5 )
{
static int V_16 = 0 ;
static T_2 V_21 ;
T_5 * V_17 ;
if ( ! V_16 ) {
V_21 = V_2 ;
V_16 = 1 ;
}
V_18 . V_19 = V_4 ;
V_18 . V_20 = V_2 ;
V_18 . V_5 = V_5 ;
if ( V_2 >= V_21 ) {
V_17 = fopen ( L_1 , L_3 ) ;
fwrite ( & V_18 , sizeof V_18 , 1 , V_17 ) ;
fclose ( V_17 ) ;
V_21 = V_2 + ( 10 * 10 * 1000 * 1000 ) ;
}
}
void F_2 ( T_2 * V_2 )
{
static int V_16 = 0 ;
static T_2 V_22 ;
static T_3 V_23 ;
T_2 V_24 ;
if ( ! V_16 ) {
F_8 ( & V_24 ) ;
V_23 = V_25 ;
V_16 = 1 ;
}
for ( ; ; ) {
F_8 ( & V_24 ) ;
if ( V_22 != V_24 ) {
V_23 = 0 ;
V_22 = V_24 ;
break;
}
if ( V_23 < V_25 ) {
V_23 ++ ;
break;
}
}
* V_2 = V_24 + V_23 ;
}
static T_3 F_5 ( void )
{
static int V_16 = 0 ;
T_2 V_24 ;
if ( ! V_16 ) {
F_8 ( & V_24 ) ;
V_24 = V_24 / V_25 ;
srand ( ( unsigned int )
( ( ( V_24 >> 32 ) ^ V_24 ) & 0xffffffff ) ) ;
V_16 = 1 ;
}
return rand () ;
}
void F_9 ( T_1 * V_1 , T_1 V_26 , void * V_27 ,
int V_28 )
{
T_6 V_29 ;
unsigned char V_30 [ 16 ] ;
T_1 V_31 ;
V_31 = V_26 ;
V_31 . V_11 = F_10 ( V_31 . V_11 ) ;
V_31 . V_12 = F_11 ( V_31 . V_12 ) ;
V_31 . V_13 = F_11 ( V_31 . V_13 ) ;
F_12 ( & V_29 ) ;
F_13 ( & V_29 , & V_31 , sizeof V_31 ) ;
F_13 ( & V_29 , V_27 , V_28 ) ;
F_14 ( V_30 , & V_29 ) ;
F_15 ( V_1 , V_30 , 3 ) ;
}
void F_16 ( T_1 * V_1 , T_1 V_26 , void * V_27 ,
int V_28 )
{
T_7 V_29 ;
unsigned char V_30 [ 20 ] ;
T_1 V_31 ;
V_31 = V_26 ;
V_31 . V_11 = F_10 ( V_31 . V_11 ) ;
V_31 . V_12 = F_11 ( V_31 . V_12 ) ;
V_31 . V_13 = F_11 ( V_31 . V_13 ) ;
F_17 ( & V_29 ) ;
F_18 ( & V_29 , & V_31 , sizeof V_31 ) ;
F_18 ( & V_29 , V_27 , V_28 ) ;
F_19 ( V_30 , & V_29 ) ;
F_15 ( V_1 , V_30 , 5 ) ;
}
void F_15 ( T_1 * V_1 , unsigned char V_30 [ 16 ] , int V_32 )
{
memcpy ( V_1 , V_30 , sizeof *V_1 ) ;
V_1 -> V_11 = F_20 ( V_1 -> V_11 ) ;
V_1 -> V_12 = F_21 ( V_1 -> V_12 ) ;
V_1 -> V_13 = F_21 ( V_1 -> V_13 ) ;
V_1 -> V_13 &= 0x0FFF ;
V_1 -> V_13 |= ( V_32 << 12 ) ;
V_1 -> V_15 &= 0x3F ;
V_1 -> V_15 |= 0x80 ;
}
int F_22 ( T_1 * V_33 , T_1 * V_34 )
{
int V_35 ;
F_23 ( V_33 -> V_11 , V_34 -> V_11 ) ;
F_23 ( V_33 -> V_12 , V_34 -> V_12 ) ;
F_23 ( V_33 -> V_13 , V_34 -> V_13 ) ;
F_23 ( V_33 -> V_15 , V_34 -> V_15 ) ;
F_23 (u1->clock_seq_low, u2->clock_seq_low)
for ( V_35 = 0 ; V_35 < 6 ; V_35 ++ ) {
if ( V_33 -> V_5 [ V_35 ] < V_34 -> V_5 [ V_35 ] )
return - 1 ;
if ( V_33 -> V_5 [ V_35 ] > V_34 -> V_5 [ V_35 ] )
return 1 ;
}
return 0 ;
}
