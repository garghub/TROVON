static void F_1 ( int * V_1 , int * V_2 )
{
#ifdef F_2
struct V_3 * V_4 = NULL ;
T_1 V_5 ;
F_3 (p) {
if ( F_4 ( V_4 , 0 ) == 0x1f0 )
* V_1 = 1 ;
if ( F_4 ( V_4 , 2 ) == 0x170 )
* V_2 = 1 ;
if ( V_4 -> V_6 == V_7 &&
( V_4 -> V_8 == V_9 ||
V_4 -> V_8 == V_10 ) )
* V_1 = * V_2 = 1 ;
if ( V_4 -> V_6 == V_11 &&
V_4 -> V_8 == V_12 ) {
F_5 ( V_4 , 0x6C , & V_5 ) ;
if ( V_5 & 0x8000 ) {
if ( V_5 & 0x4000 )
* V_2 = 1 ;
else
* V_1 = 1 ;
}
}
}
#endif
}
static int T_2 F_6 ( void )
{
struct V_13 V_14 , * V_15 [] = { & V_14 } ;
unsigned long V_16 ;
int V_17 , V_18 = 0 , V_1 = 0 , V_2 = 0 ;
F_1 ( & V_1 , & V_2 ) ;
if ( ! V_19 ) {
F_7 (KERN_INFO DRV_NAME L_1
L_2 ) ;
if ( V_1 == 0 )
V_19 |= 0x1 ;
if ( V_2 == 0 )
V_19 |= 0x2 ;
} else
F_7 (KERN_INFO DRV_NAME L_3
L_4 ) ;
for ( V_17 = 0 ; V_17 < F_8 ( V_20 ) ; V_17 ++ ) {
V_16 = V_20 [ V_17 ] ;
if ( ( V_19 & ( 1 << V_17 ) ) && V_16 ) {
if ( ! F_9 ( V_16 , 8 , V_21 ) ) {
F_7 ( V_22 L_5
L_6 ,
V_21 , V_16 , V_16 + 7 ) ;
V_18 = - V_23 ;
continue;
}
if ( ! F_9 ( V_16 + 0x206 , 1 , V_21 ) ) {
F_7 ( V_22 L_7
L_6 ,
V_21 , V_16 + 0x206 ) ;
F_10 ( V_16 , 8 ) ;
V_18 = - V_23 ;
continue;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
F_11 ( & V_14 , V_16 , V_16 + 0x206 ) ;
#ifdef F_12
V_14 . V_24 = F_13 ( V_25 [ V_17 ] ) ;
#else
V_14 . V_24 = V_25 [ V_17 ] ;
#endif
V_18 = F_14 ( & V_26 , V_15 , 1 , NULL ) ;
if ( V_18 ) {
F_10 ( V_16 + 0x206 , 1 ) ;
F_10 ( V_16 , 8 ) ;
}
}
}
return V_18 ;
}
