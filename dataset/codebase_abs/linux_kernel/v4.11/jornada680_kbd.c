static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = V_1 -> V_3 -> V_4 ;
unsigned short * V_5 = V_1 -> V_5 ;
unsigned int V_6 = 0 ;
unsigned int V_7 , V_8 ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
unsigned char V_10 = V_1 -> V_11 [ V_7 ] ;
unsigned char V_12 = V_1 -> V_13 [ V_7 ] ;
unsigned int V_14 = V_10 ^ V_12 ;
if ( V_14 == 0 )
continue;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
unsigned int V_15 = 1 << V_8 ;
if ( V_14 & V_15 ) {
unsigned int V_16 = ( V_7 << 3 ) + V_8 ;
F_2 ( V_2 ,
V_17 , V_18 , V_16 ) ;
F_3 ( V_2 ,
V_5 [ V_16 ] ,
! ( V_10 & V_15 ) ) ;
V_6 = 1 ;
}
}
}
if ( V_6 )
F_4 ( V_2 ) ;
}
static void F_5 ( unsigned char * V_19 )
{
int V_7 ;
unsigned short V_20 , V_21 ;
unsigned char V_22 [] = {
0xfd , 0xff ,
0xdf , 0xff ,
0x7f , 0xff ,
0xff , 0xfe ,
0xff , 0xfd ,
0xff , 0xf7 ,
0xff , 0xbf ,
0xff , 0x7f ,
} , * V_23 = V_22 ;
unsigned short V_24 [] = {
0xcc04 , 0xf0cf ,
0xc40c , 0xf0cf ,
0x4c0c , 0xf0cf ,
0xcc0c , 0xf0cd ,
0xcc0c , 0xf0c7 ,
0xcc0c , 0xf04f ,
0xcc0c , 0xd0cf ,
0xcc0c , 0x70cf ,
} , * V_25 = V_24 ;
V_21 = ( F_6 ( V_26 ) & ( ~ 0xcc0c ) ) ;
V_20 = ( F_6 ( V_27 ) & ( ~ 0xf0cf ) ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
F_7 ( ( V_21 | * V_25 ++ ) , V_26 ) ;
F_7 ( ( V_20 | * V_25 ++ ) , V_27 ) ;
F_8 ( 5 ) ;
F_9 ( * V_23 ++ , V_28 ) ;
F_9 ( * V_23 ++ , V_29 ) ;
F_8 ( 50 ) ;
* V_19 ++ = F_10 ( V_30 ) ;
* V_19 ++ = F_10 ( V_31 ) ;
}
F_9 ( 0xff , V_28 ) ;
F_9 ( 0xff , V_29 ) ;
F_7 ( ( V_21 | ( 0x5555 & 0xcc0c ) ) , V_26 ) ;
F_7 ( ( V_20 | ( 0x5555 & 0xf0cf ) ) , V_27 ) ;
* V_19 ++ = F_10 ( V_32 ) ;
* V_19 ++ = F_10 ( V_33 ) ;
}
static void F_11 ( struct V_34 * V_35 )
{
struct V_1 * V_1 = V_35 -> V_36 ;
F_5 ( V_1 -> V_11 ) ;
F_1 ( V_1 ) ;
memcpy ( V_1 -> V_13 , V_1 -> V_11 , V_9 ) ;
}
static int F_12 ( struct V_37 * V_38 )
{
struct V_1 * V_1 ;
struct V_34 * V_3 ;
struct V_2 * V_2 ;
int V_7 , error ;
V_1 = F_13 ( & V_38 -> V_35 , sizeof( struct V_1 ) ,
V_39 ) ;
if ( ! V_1 )
return - V_40 ;
V_3 = F_14 ( & V_38 -> V_35 ) ;
if ( ! V_3 ) {
F_15 ( & V_38 -> V_35 , L_1 ) ;
return - V_40 ;
}
V_1 -> V_3 = V_3 ;
memcpy ( V_1 -> V_5 , V_41 ,
sizeof( V_1 -> V_5 ) ) ;
V_3 -> V_36 = V_1 ;
V_3 -> V_42 = F_11 ;
V_3 -> V_43 = 50 ;
V_2 = V_3 -> V_4 ;
V_2 -> V_44 [ 0 ] = F_16 ( V_45 ) | F_16 ( V_46 ) ;
V_2 -> V_47 = L_2 ;
V_2 -> V_48 = L_3 ;
V_2 -> V_49 = V_1 -> V_5 ;
V_2 -> V_50 = sizeof( unsigned short ) ;
V_2 -> V_51 = F_17 ( V_41 ) ;
V_2 -> V_35 . V_52 = & V_38 -> V_35 ;
V_2 -> V_53 . V_54 = V_55 ;
for ( V_7 = 0 ; V_7 < 128 ; V_7 ++ )
if ( V_1 -> V_5 [ V_7 ] )
F_18 ( V_1 -> V_5 [ V_7 ] , V_2 -> V_56 ) ;
F_19 ( V_57 , V_2 -> V_56 ) ;
F_20 ( V_2 , V_17 , V_18 ) ;
error = F_21 ( V_1 -> V_3 ) ;
if ( error ) {
F_15 ( & V_38 -> V_35 , L_4 ) ;
return error ;
}
return 0 ;
}
