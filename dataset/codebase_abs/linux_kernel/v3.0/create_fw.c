int F_1 ( struct V_1 * V_1 )
{
T_1 * V_2 ;
int V_3 ;
T_2 V_4 ;
V_2 = fopen ( V_5 , L_1 ) ;
if ( ! V_2 ) {
perror ( L_2 ) ;
fclose ( V_2 ) ;
return - V_6 ;
}
V_4 = fwrite ( V_1 , sizeof( struct V_1 ) , 1 , V_2 ) ;
if ( V_4 != 1 ) {
perror ( L_3 ) ;
fclose ( V_2 ) ;
return - V_6 ;
}
fclose ( V_2 ) ;
return 0 ;
}
void F_2 ( struct V_1 * V_1 )
{
int V_7 , V_8 , V_9 ;
strncpy ( V_1 -> V_10 . V_11 , V_12 , strlen ( V_12 ) ) ;
V_1 -> V_10 . V_13 = V_13 ;
V_1 -> V_10 . V_14 = sizeof( struct V_1 ) ;
V_1 -> V_10 . V_15 = sizeof( struct V_16 ) ;
V_1 -> V_10 . V_17 = V_17 ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
V_1 -> V_18 [ V_7 ] . V_19 . V_20 = V_20 ;
V_1 -> V_18 [ V_7 ] . V_19 . V_21 =
V_22 ;
V_1 -> V_18 [ V_7 ] . V_19 . V_23 =
V_24 ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ )
V_1 -> V_18 [ V_7 ] . V_25 [ V_9 ] . V_26 =
V_26 [ V_7 ] [ V_9 ] ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
V_1 -> V_18 [ V_7 ] . V_27 [ V_8 ] . V_28 . V_29 =
( V_30 ) ( V_31 [ V_7 ] [ V_8 ] >> 32 ) ;
V_1 -> V_18 [ V_7 ] . V_27 [ V_8 ] . V_28 . V_32 =
( V_30 ) ( V_31 [ V_7 ] [ V_8 ] ) ;
V_1 -> V_18 [ V_7 ] . V_27 [ V_8 ] . V_33 =
V_33 ;
V_1 -> V_18 [ V_7 ] . V_27 [ V_8 ] . V_34 =
V_34 ;
V_1 -> V_18 [ V_7 ] . V_27 [ V_8 ] . V_35 =
V_35 ;
V_1 -> V_18 [ V_7 ] . V_27 [ V_8 ] . V_36 =
V_36 ;
}
}
}
int main ( void )
{
int V_3 ;
struct V_1 * V_1 ;
V_1 = malloc ( sizeof( struct V_1 ) ) ;
memset ( V_1 , 0 , sizeof( struct V_1 ) ) ;
F_2 ( V_1 ) ;
V_3 = F_1 ( V_1 ) ;
if ( V_3 < 0 ) {
free ( V_1 ) ;
return V_3 ;
}
free ( V_1 ) ;
return 0 ;
}
