static void F_1 ( char * V_1 , unsigned short V_2 ,
unsigned short V_3 )
{
sprintf ( V_1 , L_1 ,
'A' + ( ( V_2 >> 2 ) & 0x3f ) - 1 ,
'A' + ( ( ( V_2 & 3 ) << 3 ) | ( ( V_2 >> 13 ) & 7 ) ) - 1 ,
'A' + ( ( V_2 >> 8 ) & 0x1f ) - 1 ,
( V_3 >> 4 ) & 0x0f , V_3 & 0x0f ,
( V_3 >> 12 ) & 0x0f , ( V_3 >> 8 ) & 0x0f ) ;
}
struct V_4 * F_2 ( unsigned short V_2 , unsigned short V_3 ,
struct V_4 * V_5 )
{
char V_6 [ 8 ] ;
char V_7 [ 8 ] ;
struct V_8 * V_9 ;
F_1 ( V_6 , V_2 , V_3 ) ;
F_1 ( V_7 , V_10 , V_10 ) ;
V_9 = V_5 ? V_5 -> V_11 . V_12 : V_13 . V_12 ;
while ( V_9 != & V_13 ) {
struct V_4 * V_14 = F_3 ( V_9 ) ;
if ( F_4 ( V_14 -> V_6 , V_6 ) || ( memcmp ( V_6 , V_7 , 7 ) == 0 ) )
return V_14 ;
V_9 = V_9 -> V_12 ;
}
return NULL ;
}
struct V_15 * F_5 ( struct V_4 * V_14 , unsigned short V_2 ,
unsigned short V_16 , struct V_15 * V_5 )
{
char V_6 [ 8 ] ;
char V_7 [ 8 ] ;
F_1 ( V_6 , V_2 , V_16 ) ;
F_1 ( V_7 , V_10 , V_10 ) ;
if ( V_14 == NULL ) {
struct V_8 * V_9 ;
V_9 = V_17 . V_12 ;
if ( V_5 )
V_9 = V_5 -> V_11 . V_12 ;
while ( V_9 != & V_17 ) {
struct V_15 * V_18 = F_6 ( V_9 ) ;
if ( F_4 ( V_18 -> V_6 , V_6 ) ||
( memcmp ( V_6 , V_7 , 7 ) == 0 ) )
return V_18 ;
V_9 = V_9 -> V_12 ;
}
} else {
struct V_8 * V_9 ;
V_9 = V_14 -> V_19 . V_12 ;
if ( V_5 ) {
V_9 = V_5 -> V_20 . V_12 ;
if ( V_5 -> V_14 != V_14 )
return NULL ;
}
while ( V_9 != & V_14 -> V_19 ) {
struct V_15 * V_18 = F_7 ( V_9 ) ;
if ( F_4 ( V_18 -> V_6 , V_6 ) )
return V_18 ;
V_9 = V_9 -> V_12 ;
}
}
return NULL ;
}
