static inline void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
unsigned int V_4 = V_2 -> V_4 ;
V_3 = ( 1 << ( V_4 & 0x1f ) ) ;
switch ( V_4 >> 5 ) {
case 0 :
F_2 ( F_3 ( V_5 ) | V_3 , V_5 ) ;
break;
case 1 :
F_2 ( F_3 ( V_6 ) | V_3 , V_6 ) ;
break;
case 2 :
F_2 ( F_3 ( V_7 ) | V_3 , V_7 ) ;
break;
case 3 :
F_2 ( F_3 ( V_8 ) | V_3 , V_8 ) ;
break;
default:
F_4 () ;
}
}
static inline void F_5 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
unsigned int V_4 = V_2 -> V_4 ;
V_9 = ~ ( 1 << ( V_4 & 0x1f ) ) ;
switch ( V_4 >> 5 ) {
case 0 :
F_2 ( F_3 ( V_5 ) & V_9 , V_5 ) ;
break;
case 1 :
F_2 ( F_3 ( V_6 ) & V_9 , V_6 ) ;
break;
case 2 :
F_2 ( F_3 ( V_7 ) & V_9 , V_7 ) ;
break;
case 3 :
F_2 ( F_3 ( V_8 ) & V_9 , V_8 ) ;
break;
default:
F_4 () ;
}
}
void T_1 F_6 ( void )
{
int V_10 ;
F_7 ( F_8 () & ~ ( 0x0000fc00 ) ) ;
F_2 ( 0 , V_5 ) ;
F_2 ( 0 , V_6 ) ;
F_2 ( 0 , V_7 ) ;
F_2 ( 0 , V_8 ) ;
F_2 ( 0x0fffffff , V_11 ) ;
F_2 ( 0xffffffff , V_12 ) ;
F_2 ( 0xffffffff , V_13 ) ;
F_2 ( 0xffffffff , V_14 ) ;
F_2 ( 0xffffffff , V_15 ) ;
F_2 ( 0xffffffff , V_16 ) ;
F_2 ( 0xffffffff , V_17 ) ;
F_2 ( 0xffffffff , V_18 ) ;
F_2 ( 0xffffffff , V_19 ) ;
F_2 ( 0xffffffff , V_20 ) ;
F_2 ( 0xffffffff , V_21 ) ;
F_2 ( 0xffffffff , V_22 ) ;
F_2 ( 0xffffffff , V_23 ) ;
F_2 ( 0xffffffff , V_24 ) ;
F_2 ( 0xffffffff , V_25 ) ;
F_2 ( 0xffffffff , V_26 ) ;
F_2 ( 0xf , V_27 ) ;
for ( V_10 = 0 ; V_10 < V_28 ; V_10 ++ )
F_9 ( V_10 , & V_29 , V_30 ) ;
}
