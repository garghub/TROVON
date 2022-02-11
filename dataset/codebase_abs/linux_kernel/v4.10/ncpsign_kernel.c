static inline T_1
F_1 ( const T_2 * V_1 , int V_2 )
{
return F_2 ( V_1 , V_2 ) | F_2 ( V_1 , V_2 + 1 ) << 8 ;
}
static inline T_3
F_3 ( const T_2 * V_1 , int V_2 )
{
return F_1 ( V_1 , V_2 ) | F_1 ( V_1 , V_2 + 2 ) << 16 ;
}
static inline void
F_4 ( T_2 * V_1 , int V_2 , T_1 V_3 )
{
F_5 ( V_1 , V_2 , V_3 & 0xff ) ;
F_5 ( V_1 , V_2 + 1 , V_3 >> 8 ) ;
}
static inline void
F_6 ( T_2 * V_1 , int V_2 , T_3 V_3 )
{
F_4 ( V_1 , V_2 , V_3 & 0xffff ) ;
F_4 ( V_1 , V_2 + 2 , V_3 >> 16 ) ;
}
static void F_7 ( char * V_4 , char * V_5 , char * V_6 ) {
int V_7 ;
unsigned int V_8 , V_9 , V_10 , V_11 ;
static int V_12 [ 4 ] = { 0 , 2 , 1 , 3 } ;
#ifdef F_8
unsigned int * V_13 = ( unsigned int * ) V_5 ;
#else
unsigned int V_13 [ 16 ] ;
for ( V_7 = 0 ; V_7 < 16 ; V_7 ++ )
V_13 [ V_7 ] = F_9 ( V_5 + ( V_7 << 2 ) ) ;
#endif
V_8 = F_9 ( V_4 ) ;
V_9 = F_9 ( V_4 + 4 ) ;
V_10 = F_9 ( V_4 + 8 ) ;
V_11 = F_9 ( V_4 + 12 ) ;
for ( V_7 = 0 ; V_7 < 16 ; V_7 += 4 ) {
V_8 = F_10 ( V_8 + ( ( V_9 & V_10 ) | ( ( ~ V_9 ) & V_11 ) ) + V_13 [ V_7 + 0 ] , 3 ) ;
V_11 = F_10 ( V_11 + ( ( V_8 & V_9 ) | ( ( ~ V_8 ) & V_10 ) ) + V_13 [ V_7 + 1 ] , 7 ) ;
V_10 = F_10 ( V_10 + ( ( V_11 & V_8 ) | ( ( ~ V_11 ) & V_9 ) ) + V_13 [ V_7 + 2 ] , 11 ) ;
V_9 = F_10 ( V_9 + ( ( V_10 & V_11 ) | ( ( ~ V_10 ) & V_8 ) ) + V_13 [ V_7 + 3 ] , 19 ) ;
}
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_8 = F_10 ( V_8 + ( ( ( V_10 | V_11 ) & V_9 ) | ( V_10 & V_11 ) ) + 0x5a827999 + V_13 [ V_7 + 0 ] , 3 ) ;
V_11 = F_10 ( V_11 + ( ( ( V_9 | V_10 ) & V_8 ) | ( V_9 & V_10 ) ) + 0x5a827999 + V_13 [ V_7 + 4 ] , 5 ) ;
V_10 = F_10 ( V_10 + ( ( ( V_8 | V_9 ) & V_11 ) | ( V_8 & V_9 ) ) + 0x5a827999 + V_13 [ V_7 + 8 ] , 9 ) ;
V_9 = F_10 ( V_9 + ( ( ( V_11 | V_8 ) & V_10 ) | ( V_11 & V_8 ) ) + 0x5a827999 + V_13 [ V_7 + 12 ] , 13 ) ;
}
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_8 = F_10 ( V_8 + ( ( V_9 ^ V_10 ) ^ V_11 ) + 0x6ed9eba1 + V_13 [ V_12 [ V_7 ] + 0 ] , 3 ) ;
V_11 = F_10 ( V_11 + ( ( V_8 ^ V_9 ) ^ V_10 ) + 0x6ed9eba1 + V_13 [ V_12 [ V_7 ] + 8 ] , 9 ) ;
V_10 = F_10 ( V_10 + ( ( V_11 ^ V_8 ) ^ V_9 ) + 0x6ed9eba1 + V_13 [ V_12 [ V_7 ] + 4 ] , 11 ) ;
V_9 = F_10 ( V_9 + ( ( V_10 ^ V_11 ) ^ V_8 ) + 0x6ed9eba1 + V_13 [ V_12 [ V_7 ] + 12 ] , 15 ) ;
}
F_11 ( V_6 , ( V_8 + F_9 ( V_4 ) ) & 0xffffffff ) ;
F_11 ( V_6 + 4 , ( V_9 + F_9 ( V_4 + 4 ) ) & 0xffffffff ) ;
F_11 ( V_6 + 8 , ( V_10 + F_9 ( V_4 + 8 ) ) & 0xffffffff ) ;
F_11 ( V_6 + 12 , ( V_11 + F_9 ( V_4 + 12 ) ) & 0xffffffff ) ;
}
void F_12 ( struct V_14 * V_15 , const char * V_16 , T_4 V_17 , T_3 V_18 , void * V_19 ) {
unsigned char V_20 [ 64 ] ;
memcpy ( V_20 , V_15 -> V_21 , 8 ) ;
* ( T_3 * ) ( V_20 + 8 ) = V_18 ;
if ( V_17 < 52 ) {
memcpy ( V_20 + 12 , V_16 , V_17 ) ;
memset ( V_20 + 12 + V_17 , 0 , 52 - V_17 ) ;
} else {
memcpy ( V_20 + 12 , V_16 , 52 ) ;
}
F_7 ( V_15 -> V_22 , V_20 , V_15 -> V_22 ) ;
memcpy ( V_19 , V_15 -> V_22 , 8 ) ;
}
int F_13 ( struct V_14 * V_15 , const char * V_16 , T_4 V_17 , T_3 V_18 , const void * V_19 ) {
unsigned char V_20 [ 64 ] ;
unsigned char V_23 [ 16 ] ;
memcpy ( V_20 , V_15 -> V_21 , 8 ) ;
* ( T_3 * ) ( V_20 + 8 ) = V_18 ;
if ( V_17 < 52 ) {
memcpy ( V_20 + 12 , V_16 , V_17 ) ;
memset ( V_20 + 12 + V_17 , 0 , 52 - V_17 ) ;
} else {
memcpy ( V_20 + 12 , V_16 , 52 ) ;
}
F_7 ( V_15 -> V_22 , V_20 , V_23 ) ;
return memcmp ( V_19 , V_23 , 8 ) ;
}
