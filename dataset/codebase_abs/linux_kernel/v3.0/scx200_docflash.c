static int T_1 F_1 ( void )
{
unsigned V_1 ;
unsigned V_2 ;
unsigned V_3 ;
unsigned V_4 ;
struct V_5 * V_6 ;
F_2 (KERN_DEBUG NAME L_1 ) ;
if ( ( V_6 = F_3 ( V_7 ,
V_8 ,
NULL ) ) == NULL )
return - V_9 ;
if ( ! F_4 () ) {
F_5 ( V_6 ) ;
return - V_9 ;
}
if ( V_10 ) {
F_6 ( V_6 , V_11 , & V_2 ) ;
F_6 ( V_6 , V_12 , & V_3 ) ;
F_5 ( V_6 ) ;
V_4 = F_7 ( V_13 + V_14 ) ;
if ( V_2 == 0
|| ( V_3 & 0x07000000 ) != 0x07000000
|| ( V_3 & 0x0007ffff ) == 0 )
return - V_9 ;
V_15 = ( ( V_3 & 0x1fff ) << 13 ) + ( 1 << 13 ) ;
for ( V_1 = V_15 ; V_1 > 1 ; V_1 >>= 1 )
;
if ( V_1 != 1 )
return - V_9 ;
if ( V_4 & ( 1 << 6 ) )
V_16 = 16 ;
else
V_16 = 8 ;
V_17 . V_18 = V_2 ;
V_17 . V_19 = V_2 + V_15 ;
if ( F_8 ( & V_20 , & V_17 ) ) {
F_2 (KERN_ERR NAME L_2 ) ;
return - V_21 ;
}
} else {
F_5 ( V_6 ) ;
for ( V_1 = V_15 ; V_1 > 1 ; V_1 >>= 1 )
;
if ( V_1 != 1 ) {
F_2 (KERN_ERR NAME L_3 ) ;
return - V_22 ;
}
if ( V_16 != 8 && V_16 != 16 ) {
F_2 (KERN_ERR NAME L_4 ) ;
return - V_22 ;
}
if ( F_9 ( & V_20 , & V_17 ,
V_15 ,
0xc0000000 , 0xffffffff ,
V_15 , NULL , NULL ) ) {
F_2 (KERN_ERR NAME L_2 ) ;
return - V_21 ;
}
V_3 = 0x07000000 | ( ( V_15 - 1 ) >> 13 ) ;
F_2 ( V_23 L_5 , ( long ) V_17 . V_18 , ( long ) V_3 ) ;
F_10 ( V_6 , V_11 , V_17 . V_18 ) ;
F_10 ( V_6 , V_12 , V_3 ) ;
V_4 = F_7 ( V_13 + V_14 ) ;
if ( V_16 == 8 ) {
V_4 &= ~ ( 1 << 6 ) ;
} else {
V_4 |= ( 1 << 6 ) ;
}
F_11 ( V_4 , V_13 + V_14 ) ;
}
F_2 (KERN_INFO NAME L_6 ,
&docmem, width) ;
V_24 . V_15 = V_15 ;
if ( V_16 == 8 )
V_24 . V_25 = 1 ;
else
V_24 . V_25 = 2 ;
F_12 ( & V_24 ) ;
V_24 . V_26 = V_17 . V_18 ;
V_24 . V_27 = F_13 ( V_17 . V_18 , V_24 . V_15 ) ;
if ( ! V_24 . V_27 ) {
F_2 (KERN_ERR NAME L_7 ) ;
F_14 ( & V_17 ) ;
return - V_28 ;
}
V_29 = F_15 ( V_30 , & V_24 ) ;
if ( ! V_29 ) {
F_2 (KERN_ERR NAME L_8 ) ;
F_16 ( V_24 . V_27 ) ;
F_14 ( & V_17 ) ;
return - V_31 ;
}
if ( V_15 < V_29 -> V_15 )
F_2 (KERN_WARNING NAME L_9 ) ;
V_29 -> V_32 = V_33 ;
V_34 [ 3 ] . V_35 = V_29 -> V_15 - V_34 [ 3 ] . V_15 ;
V_34 [ 2 ] . V_15 = V_34 [ 3 ] . V_35 - V_34 [ 2 ] . V_35 ;
F_17 ( V_29 , V_34 , V_36 ) ;
return 0 ;
}
static void T_2 F_18 ( void )
{
if ( V_29 ) {
F_19 ( V_29 ) ;
F_20 ( V_29 ) ;
}
if ( V_24 . V_27 ) {
F_16 ( V_24 . V_27 ) ;
F_14 ( & V_17 ) ;
}
}
