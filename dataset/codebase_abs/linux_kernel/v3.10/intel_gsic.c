int main ( void )
{
struct V_1 V_2 ;
int V_3 ;
if ( ! F_1 () )
return 0 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_4 = 0x0000E980 ;
V_2 . V_5 = 0x47534943 ;
V_3 = F_2 ( 0x15 , & V_2 ) ;
if ( ! V_3 ) {
printf ( L_1 ) ;
return 0 ;
}
if ( V_2 . V_4 == 0x47534943 ) {
printf ( L_2 ) ;
printf ( L_3 ,
( V_2 . V_4 >> 24 ) & 0xff ,
( V_2 . V_4 >> 16 ) & 0xff ,
( V_2 . V_4 >> 8 ) & 0xff ,
( V_2 . V_4 ) & 0xff ) ;
printf ( L_4 ,
V_2 . V_6 & 0xffff ) ;
printf ( L_5 ,
( V_2 . V_6 >> 16 ) & 0xffff ) ;
printf ( L_6 , V_2 . V_7 ) ;
printf ( L_7 , V_2 . V_5 ) ;
if ( ( ( V_2 . V_6 >> 16 ) & 0xffff ) != 0x82 ) {
printf ( L_8
L_9
L_10
L_11
L_12 ) ;
}
if ( ( V_2 . V_6 & 0xffff ) != 0xb2 ) {
printf ( L_13
L_9
L_10
L_14
L_12 ) ;
}
} else {
printf ( L_15 ) ;
printf ( L_16 , V_2 . V_4 ) ;
printf ( L_17 , V_2 . V_6 ) ;
printf ( L_18 , V_2 . V_7 ) ;
printf ( L_19 , V_2 . V_5 ) ;
printf ( L_20
L_21
L_22
L_23 ) ;
printf ( L_24 ) ;
printf ( L_25
L_26
L_27 ) ;
}
return 1 ;
}
