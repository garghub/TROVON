static void F_1 ( char V_1 , char V_2 )
{
F_2 ( V_1 , 0x108 ) ;
F_2 ( V_2 , 0x109 ) ;
}
static inline T_1 F_3 ( char V_1 )
{
F_2 ( V_1 , 0x108 ) ;
return F_4 ( 0x109 ) ;
}
static void F_5 ( T_1 V_3 [] )
{
int V_4 , V_5 ;
F_2 ( 0x5A , 0x108 ) ;
F_1 ( 0xd7 , ( V_6 [ 0 ] [ V_3 [ 2 ] ] | ( V_6 [ 0 ] [ V_3 [ 3 ] ] << 4 ) ) ) ;
F_1 ( 0xd6 , ( V_6 [ 0 ] [ V_3 [ 0 ] ] | ( V_6 [ 0 ] [ V_3 [ 1 ] ] << 4 ) ) ) ;
V_5 = 0 ;
for ( V_4 = 3 ; V_4 >= 0 ; V_4 -- )
V_5 = ( V_5 << 2 ) | V_6 [ 1 ] [ V_3 [ V_4 ] ] ;
F_1 ( 0xdc , V_5 ) ;
for ( V_4 = 0 ; V_4 < 4 ; V_4 ++ ) {
F_1 ( 0xd0 + V_4 , V_6 [ 2 ] [ V_3 [ V_4 ] ] ) ;
F_1 ( 0xd8 + V_4 , V_6 [ 2 ] [ V_3 [ V_4 ] ] ) ;
}
F_2 ( 0xa5 , 0x108 ) ;
F_6 ( L_1 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] ) ;
}
static void F_7 ( T_2 * V_7 , T_3 * V_8 )
{
T_2 * V_9 = V_7 -> V_9 ;
unsigned long V_10 ( V_11 ) ;
const T_1 V_12 = V_8 -> V_13 - V_14 ;
F_6 ( L_2 ,
V_8 -> V_15 , V_12 , V_16 [ V_12 ] ) ;
if ( V_9 )
F_8 ( & V_9 -> V_17 , V_11 ) ;
if ( V_9 && V_9 -> V_18 ) {
F_6 ( V_19 L_3 ) ;
} else {
V_20 [ V_8 -> V_15 [ 2 ] - 'a' ] = V_16 [ V_12 ] ;
F_5 ( V_20 ) ;
}
if ( V_9 )
F_9 ( & V_9 -> V_17 , V_11 ) ;
}
static int T_4 F_10 ( void )
{
unsigned long V_11 ;
if ( ! F_11 ( 0x108 , 2 , L_4 ) ) {
F_6 ( V_19 L_5 ) ;
return 1 ;
}
F_12 ( V_11 ) ;
F_2 ( 0x5A , 0x108 ) ;
if ( F_3 ( 0xd5 ) != 0xa0 ) {
F_13 ( V_11 ) ;
F_6 ( V_19 L_6 ) ;
F_14 ( 0x108 , 2 ) ;
return 1 ;
}
F_2 ( 0xa5 , 0x108 ) ;
F_5 ( V_20 ) ;
F_13 ( V_11 ) ;
return F_15 ( & V_21 , 0 ) ;
}
static int T_4 F_16 ( void )
{
if ( V_22 == 0 )
goto V_23;
if ( F_10 () == 0 )
return 0 ;
V_23:
return - V_24 ;
}
