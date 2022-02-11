static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return ! ( ( 1 << 7 ) & F_3 ( V_4 -> V_5 ) ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( 0x8a0a , V_4 -> V_5 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return V_6 ;
}
static T_1 F_7 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_8 ( V_2 ) ;
F_5 ( F_3 ( V_4 -> V_9 ) | V_10 , V_4 -> V_9 ) ;
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_12 ;
F_5 ( V_13 | V_10 , V_4 -> V_9 ) ;
V_12 = F_10 ( V_14 , F_7 , V_15 ,
F_11 ( & V_2 -> V_16 ) , V_2 ) ;
if ( V_12 ) {
F_12 ( & V_2 -> V_16 , L_1 ) ;
return V_12 ;
}
F_5 ( V_13 | V_17 , V_4 -> V_9 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_13 | V_10 , V_4 -> V_9 ) ;
F_14 ( V_14 , V_2 ) ;
return 0 ;
}
static int T_2 F_15 ( void )
{
struct V_18 * V_19 = F_16 ( 0 ) ;
struct V_20 V_21 ;
int V_22 , V_12 ;
T_3 V_23 [] = {
0x40 , 0x2a ,
0x43 , 0x3c ,
0x44 , 0x3c ,
0x45 , 0x3c ,
0x54 , 0x03 ,
0x51 , 0x00 ,
0x51 , 0x01 ,
0xff , 0x00 ,
0x43 , 0xf0 ,
0x44 , 0xf0 ,
0x45 , 0xf0 ,
} ;
if ( ! F_17 ( L_2 ) )
return 0 ;
if ( ! V_19 )
return 0 ;
V_21 . V_24 = 0x40 ;
V_21 . V_25 = 2 ;
V_21 . V_26 = 0 ;
for ( V_22 = 0 ; V_22 < F_18 ( V_23 ) ; V_22 += 2 ) {
V_21 . V_27 = V_23 + V_22 ;
if ( 0xff == V_21 . V_27 [ 0 ] ) {
F_19 ( 500 ) ;
continue;
}
V_12 = F_20 ( V_19 , & V_21 , 1 ) ;
if ( V_12 < 0 ) {
F_21 ( L_3 ) ;
break;
}
}
return 0 ;
}
static void T_2 F_22 ( void )
{
F_23 ( 2 , L_4 , V_28 ,
F_18 ( V_28 ) , 1800000 ) ;
F_24 ( 3 , V_29 , F_18 ( V_29 ) ) ;
F_25 ( V_30 , F_18 ( V_30 ) ) ;
F_26 () ;
F_27 ( 224 , V_31 , NULL ) ;
F_27 ( 222 , V_32 , NULL ) ;
F_27 ( 226 , V_32 , NULL ) ;
F_27 ( 223 , V_31 , NULL ) ;
F_28 ( V_33 , NULL ) ;
#ifdef F_29
F_30 ( F_31 ( 0xf0100000 ) , 0x40460000 , 0x82000fff ) ;
#endif
F_32 ( 0 , V_34 , F_18 ( V_34 ) ) ;
F_32 ( 1 , V_35 , F_18 ( V_35 ) ) ;
F_32 ( 3 , V_36 , F_18 ( V_36 ) ) ;
F_33 () ;
F_34 ( V_37 , F_18 ( V_37 ) ) ;
F_35 () ;
}
static void F_36 ( char V_38 , const char * V_39 )
{
#define F_37 IOMEM(0xe6188020)
F_38 ( ( 1 << 31 ) , F_37 ) ;
}
