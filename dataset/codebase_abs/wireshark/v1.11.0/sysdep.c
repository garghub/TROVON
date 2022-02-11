void F_1 ( T_1 * V_1 )
{
static V_2 = 0 ;
static T_1 V_3 ;
char V_4 [ 16 ] ;
T_2 * V_5 ;
if ( ! V_2 ) {
V_5 = fopen ( L_1 , L_2 ) ;
if ( V_5 ) {
fread ( & V_3 , sizeof V_3 , 1 , V_5 ) ;
fclose ( V_5 ) ;
}
else {
F_2 ( V_4 ) ;
V_4 [ 0 ] |= 0x01 ;
memcpy ( & V_3 , V_4 , sizeof V_3 ) ;
V_5 = fopen ( L_1 , L_3 ) ;
if ( V_5 ) {
fwrite ( & V_3 , sizeof V_3 , 1 , V_5 ) ;
fclose ( V_5 ) ;
}
}
V_2 = 1 ;
}
* V_1 = V_3 ;
}
void F_3 ( T_3 * V_6 )
{
T_4 time ;
F_4 ( ( V_7 * ) & time ) ;
time . V_8 +=
( unsigned V_9 ) ( 1000 * 1000 * 10 )
* ( unsigned V_9 ) ( 60 * 60 * 24 )
* ( unsigned V_9 ) ( 17 + 30 + 31 + 365 * 18 + 5 ) ;
* V_6 = time . V_8 ;
}
void F_2 ( char V_4 [ 16 ] )
{
T_5 V_10 ;
struct {
T_6 V_11 ;
T_7 V_12 ;
V_7 V_13 ;
T_8 V_14 ;
T_9 V_15 ;
T_9 V_16 ;
char V_17 [ V_18 + 1 ] ;
} V_19 ;
F_5 ( & V_10 ) ;
F_6 ( & V_19 . V_11 ) ;
F_7 ( & V_19 . V_12 ) ;
F_4 ( & V_19 . V_13 ) ;
F_8 ( & V_19 . V_14 ) ;
V_19 . V_15 = F_9 () ;
V_19 . V_16 = V_18 + 1 ;
F_10 ( V_19 . V_17 , & V_19 . V_16 ) ;
F_11 ( & V_10 , & V_19 , sizeof V_19 ) ;
F_12 ( V_4 , & V_10 ) ;
}
void F_3 ( T_3 * V_6 )
{
struct V_20 V_21 ;
F_13 ( & V_21 , (struct V_22 * ) 0 ) ;
* V_6 = ( ( V_23 ) V_21 . V_24 * 10000000 )
+ ( ( V_23 ) V_21 . V_25 * 10 )
+ F_14 ( 0x01B21DD213814000 ) ;
}
void F_2 ( char V_4 [ 16 ] )
{
T_5 V_10 ;
struct {
struct V_26 V_12 ;
struct V_20 V_13 ;
char V_17 [ 257 ] ;
} V_19 ;
F_5 ( & V_10 ) ;
V_26 ( & V_19 . V_12 ) ;
F_13 ( & V_19 . V_13 , (struct V_22 * ) 0 ) ;
F_15 ( V_19 . V_17 , 256 ) ;
F_11 ( & V_10 , & V_19 , sizeof V_19 ) ;
F_12 ( V_4 , & V_10 ) ;
}
