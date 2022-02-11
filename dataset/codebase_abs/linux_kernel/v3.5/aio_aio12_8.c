static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 ;
unsigned char V_9 =
V_10 |
( F_2 ( V_6 -> V_11 ) << 3 ) | F_3 ( V_6 -> V_11 ) ;
F_4 ( V_2 -> V_12 + V_13 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_8 ; V_8 ++ ) {
int V_14 = 5 ;
F_5 ( V_9 , V_2 -> V_12 + V_15 ) ;
while ( V_14 &&
! ( F_4 ( V_2 -> V_12 + V_13 ) & V_16 ) ) {
V_14 -- ;
F_6 ( V_17 L_1 , V_14 ) ;
F_7 ( 1 ) ;
}
if ( V_14 == 0 ) {
F_8 ( V_2 , L_2 ) ;
return - V_18 ;
}
V_7 [ V_8 ] = F_9 ( V_2 -> V_12 + V_15 ) & 0x0FFF ;
}
return V_8 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_19 ;
int V_20 = V_21 -> V_22 [ F_3 ( V_6 -> V_11 ) ] ;
for ( V_19 = 0 ; V_19 < V_6 -> V_8 ; V_19 ++ )
V_7 [ V_19 ] = V_20 ;
return V_6 -> V_8 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_19 ;
int V_23 = F_3 ( V_6 -> V_11 ) ;
unsigned long V_24 = V_2 -> V_12 + V_25 + ( 2 * V_23 ) ;
F_5 ( 0x01 , V_2 -> V_12 + V_26 ) ;
for ( V_19 = 0 ; V_19 < V_6 -> V_8 ; V_19 ++ ) {
F_5 ( V_7 [ V_19 ] & 0xFF , V_24 ) ;
F_5 ( ( V_7 [ V_19 ] >> 8 ) & 0x0F , V_24 + 1 ) ;
V_21 -> V_22 [ V_23 ] = V_7 [ V_19 ] ;
}
return V_6 -> V_8 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
int V_12 ;
struct V_3 * V_4 ;
V_12 = V_28 -> V_29 [ 0 ] ;
if ( ! F_13 ( V_12 , 24 , L_3 ) ) {
F_6 ( V_17 L_4 ) ;
return - V_18 ;
}
V_2 -> V_30 = V_31 -> V_32 ;
V_2 -> V_12 = V_12 ;
if ( F_14 ( V_2 , sizeof( struct V_33 ) ) < 0 )
return - V_34 ;
if ( F_15 ( V_2 , 3 ) < 0 )
return - V_34 ;
V_4 = & V_2 -> V_35 [ 0 ] ;
V_4 -> type = V_36 ;
V_4 -> V_37 = V_38 | V_39 | V_40 ;
V_4 -> V_41 = 8 ;
V_4 -> V_42 = ( 1 << 12 ) - 1 ;
V_4 -> V_43 = & V_44 ;
V_4 -> V_45 = F_1 ;
V_4 = & V_2 -> V_35 [ 1 ] ;
V_4 -> type = V_46 ;
V_4 -> V_37 = V_47 | V_39 | V_40 ;
V_4 -> V_41 = 4 ;
V_4 -> V_42 = ( 1 << 12 ) - 1 ;
V_4 -> V_43 = & V_44 ;
V_4 -> V_45 = F_10 ;
V_4 -> V_48 = F_11 ;
V_4 = & V_2 -> V_35 [ 2 ] ;
F_16 ( V_2 , V_4 , NULL , V_2 -> V_12 + V_49 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_18 ( V_2 , & V_2 -> V_35 [ 2 ] ) ;
if ( V_2 -> V_12 )
F_19 ( V_2 -> V_12 , 24 ) ;
}
