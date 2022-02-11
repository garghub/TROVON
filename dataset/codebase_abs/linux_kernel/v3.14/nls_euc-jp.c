static inline int F_1 ( unsigned char * V_1 , const unsigned char V_2 ,
const unsigned char V_3 )
{
int V_4 ;
V_4 = ( ( V_2 - 0xFA ) * ( 0xFD - 0x40 ) ) + ( V_3 - 0x40 ) ;
if ( F_2 ( V_5 [ V_4 ] [ 0 ] ,
V_5 [ V_4 ] [ 1 ] ) ) {
V_1 [ 0 ] = V_5 [ V_4 ] [ 0 ] ;
V_1 [ 1 ] = V_5 [ V_4 ] [ 1 ] ;
return 2 ;
} else {
V_1 [ 0 ] = V_6 ;
V_1 [ 1 ] = V_5 [ V_4 ] [ 0 ] ;
V_1 [ 2 ] = V_5 [ V_4 ] [ 1 ] ;
return 3 ;
}
}
static inline int F_3 ( unsigned char * V_7 , const unsigned char V_8 ,
const unsigned char V_9 )
{
int V_4 , V_10 , V_11 ;
unsigned short V_1 ;
V_10 = 0 ;
V_11 = F_4 ( V_12 ) - 1 ;
V_1 = ( V_8 << 8 ) | V_9 ;
while ( V_10 <= V_11 ) {
V_4 = ( V_10 + V_11 ) / 2 ;
if ( V_1 < V_12 [ V_4 ] . V_1 )
V_11 = V_4 - 1 ;
else
V_10 = V_4 + 1 ;
if ( V_1 == V_12 [ V_4 ] . V_1 ) {
V_7 [ 0 ] = V_12 [ V_4 ] . V_7 [ 0 ] ;
V_7 [ 1 ] = V_12 [ V_4 ] . V_7 [ 1 ] ;
return 3 ;
}
}
return 0 ;
}
static inline int F_5 ( unsigned char * V_7 , const unsigned char V_8 ,
const unsigned char V_9 )
{
int V_4 ;
if ( V_8 == 0xF3 )
V_4 = ( ( V_8 << 8 ) | V_9 ) - 0xF3F3 ;
else
V_4 = ( ( V_8 << 8 ) | V_9 ) - 0xF4A1 + 12 ;
if ( ( V_4 < 0 ) || ( V_4 >= F_4 ( V_13 ) ) )
return 0 ;
V_7 [ 0 ] = V_13 [ V_4 ] [ 0 ] ;
V_7 [ 1 ] = V_13 [ V_4 ] [ 1 ] ;
return 3 ;
}
static inline int F_6 ( unsigned char * V_7 , const unsigned char V_8 ,
const unsigned char V_9 )
{
int V_14 ;
#if 0
if ((euc_hi == 0xA2) && (euc_lo == 0xCC)) {
sjis[0] = 0xFA;
sjis[1] = 0x54;
return 2;
} else if ((euc_hi == 0xA2) && (euc_lo == 0xE8)) {
sjis[0] = 0xFA;
sjis[1] = 0x5B;
return 2;
}
#endif
if ( ( V_14 = F_5 ( V_7 , V_8 , V_9 ) ) ) {
return V_14 ;
} else if ( ( V_14 = F_3 ( V_7 , V_8 , V_9 ) ) ) {
return V_14 ;
}
return 0 ;
}
static inline int F_7 ( unsigned char * V_15 ,
const unsigned char V_16 ,
const unsigned char V_17 )
{
int V_18 ;
if ( ! F_8 ( V_16 , V_17 ) )
return 0 ;
if ( ( V_16 == 0xEE ) && ( V_17 == 0xF9 ) ) {
V_15 [ 0 ] = 0x81 ;
V_15 [ 1 ] = 0xCA ;
return 2 ;
}
if ( ( V_16 == 0xEE ) && ( V_17 >= 0xEF ) ) {
V_18 = ( V_16 << 8 | V_17 )
- ( V_17 <= 0xF9 ? 0xEEEF : ( 0xEEEF - 10 ) ) ;
} else {
V_18 = ( V_16 - 0xED ) * ( 0xFC - 0x40 )
+ ( V_17 - 0x40 ) + ( 0x5C - 0x40 ) ;
if ( V_17 >= 0x7F )
V_18 -- ;
}
V_15 [ 0 ] = 0xFA + ( V_18 / ( 0xFC - 0x40 ) ) ;
V_15 [ 1 ] = 0x40 + ( V_18 % ( 0xFC - 0x40 ) ) ;
if ( V_15 [ 1 ] >= 0x7F )
V_15 [ 1 ] ++ ;
return 2 ;
}
static int F_9 ( const T_1 V_19 ,
unsigned char * V_20 , int V_21 )
{
int V_14 ;
if ( ! V_22 )
return - V_23 ;
if ( ( V_14 = V_22 -> F_9 ( V_19 , V_20 , V_21 ) ) < 0 )
return V_14 ;
if ( V_14 == 1 ) {
if ( F_10 ( V_20 [ 0 ] ) ) {
if ( V_21 < 2 )
return - V_24 ;
V_20 [ 1 ] = V_20 [ 0 ] ;
V_20 [ 0 ] = V_25 ;
return 2 ;
}
} else if ( V_14 == 2 ) {
F_7 ( V_20 , V_20 [ 0 ] , V_20 [ 1 ] ) ;
if ( F_11 ( V_20 [ 0 ] , V_20 [ 1 ] ) ) {
F_12 ( V_20 [ 0 ] , V_20 [ 1 ] , 0xF0 , V_20 [ 0 ] , V_20 [ 1 ] , 0xF5 ) ;
} else if ( F_13 ( V_20 [ 0 ] , V_20 [ 1 ] ) ) {
unsigned char V_26 , V_27 ;
if ( V_21 < 3 )
return - V_24 ;
V_14 = 3 ; V_26 = V_20 [ 0 ] ; V_27 = V_20 [ 1 ] ;
V_20 [ 0 ] = V_6 ;
F_12 ( V_26 , V_27 , 0xF5 , V_20 [ 1 ] , V_20 [ 2 ] , 0xF5 ) ;
} else if ( F_14 ( V_20 [ 0 ] , V_20 [ 1 ] ) ) {
unsigned char V_1 [ 3 ] , V_28 ;
V_14 = F_1 ( V_1 , V_20 [ 0 ] , V_20 [ 1 ] ) ;
if ( V_21 < V_14 )
return - V_24 ;
for ( V_28 = 0 ; V_28 < V_14 ; V_28 ++ )
V_20 [ V_28 ] = V_1 [ V_28 ] ;
} else if ( F_15 ( V_20 [ 0 ] , V_20 [ 1 ] ) ) {
V_20 [ 0 ] = ( V_20 [ 0 ] ^ 0xA0 ) * 2 + 0x5F ;
if ( V_20 [ 1 ] > 0x9E )
V_20 [ 0 ] ++ ;
if ( V_20 [ 1 ] < 0x7F )
V_20 [ 1 ] = V_20 [ 1 ] + 0x61 ;
else if ( V_20 [ 1 ] < 0x9F )
V_20 [ 1 ] = V_20 [ 1 ] + 0x60 ;
else
V_20 [ 1 ] = V_20 [ 1 ] + 0x02 ;
} else {
return - V_23 ;
}
}
else
return - V_23 ;
return V_14 ;
}
static int F_16 ( const unsigned char * V_29 , int V_21 ,
T_1 * V_19 )
{
unsigned char V_30 [ 2 ] ;
int V_31 , V_14 ;
if ( ! V_22 )
return - V_23 ;
if ( V_21 <= 0 )
return - V_24 ;
if ( V_29 [ 0 ] > 0x7F ) {
if ( V_29 [ 0 ] == V_6 ) {
if ( V_21 < 3 )
return - V_23 ;
V_31 = 3 ;
if ( F_17 ( V_29 [ 1 ] , V_29 [ 2 ] ) ) {
F_18 ( V_29 [ 1 ] , V_29 [ 2 ] , 0xF5 ,
V_30 [ 0 ] , V_30 [ 1 ] , 0xF5 ) ;
} else if ( F_6 ( V_30 , V_29 [ 1 ] , V_29 [ 2 ] ) ) {
} else {
return - V_23 ;
}
} else {
if ( V_21 < 2 )
return - V_23 ;
V_31 = 2 ;
if ( F_19 ( V_29 [ 0 ] , V_29 [ 1 ] ) ) {
V_30 [ 0 ] = V_29 [ 1 ] ;
V_30 [ 1 ] = 0x00 ;
} else if ( F_20 ( V_29 [ 0 ] , V_29 [ 1 ] ) ) {
F_18 ( V_29 [ 0 ] , V_29 [ 1 ] , 0xF5 ,
V_30 [ 0 ] , V_30 [ 1 ] , 0xF0 ) ;
} else if ( F_21 ( V_29 [ 0 ] , V_29 [ 1 ] ) ) {
V_30 [ 0 ] = ( ( V_29 [ 0 ] - 0x5f ) / 2 ) ^ 0xA0 ;
if ( ! ( V_29 [ 0 ] & 1 ) )
V_30 [ 1 ] = V_29 [ 1 ] - 0x02 ;
else if ( V_29 [ 1 ] < 0xE0 )
V_30 [ 1 ] = V_29 [ 1 ] - 0x61 ;
else
V_30 [ 1 ] = V_29 [ 1 ] - 0x60 ;
} else {
return - V_23 ;
}
}
} else {
V_31 = 1 ;
V_30 [ 0 ] = V_29 [ 0 ] ;
V_30 [ 1 ] = 0x00 ;
}
if ( ( V_14 = V_22 -> F_16 ( V_30 , sizeof( V_30 ) , V_19 ) ) < 0 )
return V_14 ;
return V_31 ;
}
static int T_2 F_22 ( void )
{
V_22 = F_23 ( L_1 ) ;
if ( V_22 ) {
V_32 . V_33 = V_22 -> V_33 ;
V_32 . V_34 = V_22 -> V_34 ;
return F_24 ( & V_32 ) ;
}
return - V_23 ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_32 ) ;
F_27 ( V_22 ) ;
}
