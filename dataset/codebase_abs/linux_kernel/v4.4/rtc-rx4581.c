static int F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned char V_7 [ 2 ] ;
V_7 [ 0 ] = V_3 & 0x0f ;
V_7 [ 1 ] = V_4 ;
return F_3 ( V_6 , V_7 , 2 , NULL , 0 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
* V_4 = V_3 | 0x80 ;
return F_3 ( V_6 , V_4 , 1 , V_4 , 1 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned char V_10 [ 7 ] ;
unsigned char V_4 ;
int V_11 ;
V_11 = F_4 ( V_2 , V_12 , & V_4 ) ;
if ( V_11 != 0 ) {
F_6 ( V_2 , L_1 ) ;
return - V_13 ;
}
do {
if ( V_4 & V_14 ) {
V_11 = F_1 ( V_2 ,
V_12 , ( V_4 & ~ V_14 ) ) ;
if ( V_11 != 0 ) {
F_6 ( V_2 , L_2
L_3 ) ;
return - V_13 ;
}
}
V_10 [ 0 ] = 0x80 ;
V_11 = F_3 ( V_6 , V_10 , 1 , V_10 , 7 ) ;
if ( V_11 < 0 ) {
F_6 ( V_2 , L_4 ) ;
return - V_13 ;
}
V_11 = F_4 ( V_2 , V_12 , & V_4 ) ;
if ( V_11 != 0 ) {
F_6 ( V_2 , L_1 ) ;
return - V_13 ;
}
} while ( V_4 & V_14 );
if ( V_4 & V_15 )
F_7 ( V_2 ,
L_5 ) ;
F_8 ( V_2 ,
L_6
L_7 ,
V_16 ,
V_10 [ 0 ] , V_10 [ 1 ] , V_10 [ 2 ] , V_10 [ 3 ] , V_10 [ 4 ] , V_10 [ 5 ] , V_10 [ 6 ] ) ;
V_9 -> V_17 = F_9 ( V_10 [ V_18 ] & 0x7F ) ;
V_9 -> V_19 = F_9 ( V_10 [ V_20 ] & 0x7F ) ;
V_9 -> V_21 = F_9 ( V_10 [ V_22 ] & 0x3F ) ;
V_9 -> V_23 = F_10 ( V_10 [ V_24 ] & 0x7F ) ;
V_9 -> V_25 = F_9 ( V_10 [ V_26 ] & 0x3F ) ;
V_9 -> V_27 = F_9 ( V_10 [ V_28 ] & 0x1F ) - 1 ;
V_9 -> V_29 = F_9 ( V_10 [ V_30 ] ) ;
if ( V_9 -> V_29 < 70 )
V_9 -> V_29 += 100 ;
F_8 ( V_2 , L_8
L_9 ,
V_16 ,
V_9 -> V_17 , V_9 -> V_19 , V_9 -> V_21 ,
V_9 -> V_25 , V_9 -> V_27 , V_9 -> V_29 , V_9 -> V_23 ) ;
V_11 = F_11 ( V_9 ) ;
if ( V_11 < 0 )
F_6 ( V_2 , L_10 ) ;
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_11 ;
unsigned char V_7 [ 8 ] , V_4 ;
F_8 ( V_2 , L_11
L_9 ,
V_16 ,
V_9 -> V_17 , V_9 -> V_19 , V_9 -> V_21 ,
V_9 -> V_25 , V_9 -> V_27 , V_9 -> V_29 , V_9 -> V_23 ) ;
V_7 [ 0 ] = 0x00 ;
V_7 [ V_18 + 1 ] = F_13 ( V_9 -> V_17 ) ;
V_7 [ V_20 + 1 ] = F_13 ( V_9 -> V_19 ) ;
V_7 [ V_22 + 1 ] = F_13 ( V_9 -> V_21 ) ;
V_7 [ V_26 + 1 ] = F_13 ( V_9 -> V_25 ) ;
V_7 [ V_28 + 1 ] = F_13 ( V_9 -> V_27 + 1 ) ;
V_7 [ V_30 + 1 ] = F_13 ( V_9 -> V_29 % 100 ) ;
V_7 [ V_24 + 1 ] = ( 0x1 << V_9 -> V_23 ) ;
V_11 = F_4 ( V_2 , V_31 , & V_4 ) ;
if ( V_11 != 0 ) {
F_6 ( V_2 , L_12 ) ;
return - V_13 ;
}
V_11 = F_1 ( V_2 , V_31 ,
( V_4 | V_32 ) ) ;
if ( V_11 != 0 ) {
F_6 ( V_2 , L_13 ) ;
return - V_13 ;
}
V_11 = F_3 ( V_6 , V_7 , 8 , NULL , 0 ) ;
if ( V_11 != 0 ) {
F_6 ( V_2 , L_14 ) ;
return - V_13 ;
}
V_11 = F_4 ( V_2 , V_12 , & V_4 ) ;
if ( V_11 != 0 ) {
F_6 ( V_2 , L_15 ) ;
return - V_13 ;
}
V_11 = F_1 ( V_2 , V_12 ,
( V_4 & ~ ( V_15 ) ) ) ;
if ( V_11 != 0 ) {
F_6 ( V_2 , L_16 ) ;
return - V_13 ;
}
V_11 = F_4 ( V_2 , V_31 , & V_4 ) ;
if ( V_11 != 0 ) {
F_6 ( V_2 , L_12 ) ;
return - V_13 ;
}
V_11 = F_1 ( V_2 , V_31 ,
( V_4 & ~ ( V_32 ) ) ) ;
if ( V_11 != 0 ) {
F_6 ( V_2 , L_13 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_33 * V_34 ;
unsigned char V_35 ;
int V_36 ;
V_36 = F_4 ( & V_6 -> V_2 , V_18 , & V_35 ) ;
if ( V_36 != 0 )
return V_36 ;
V_34 = F_15 ( & V_6 -> V_2 , L_17 ,
& V_37 , V_38 ) ;
if ( F_16 ( V_34 ) )
return F_17 ( V_34 ) ;
F_18 ( V_6 , V_34 ) ;
return 0 ;
}
