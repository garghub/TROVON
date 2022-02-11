static int F_1 ( void )
{
T_1 V_1 ;
if ( V_2 == NULL )
V_2 = F_2 ( V_3 ,
V_4 ) ;
if ( V_2 == NULL )
return - V_5 ;
#ifdef F_3
F_4 ( L_1 ,
( void * ) V_3 , ( void * ) V_2 ) ;
#endif
F_5 ( V_6 , 0 ) ;
F_5 ( V_7 , V_8 >> 16 ) ;
F_6 ( V_9 , V_1 ) ;
V_1 &= ~ ( 1 << 19 ) ;
F_5 ( V_9 , V_1 ) ;
V_1 = 0x02 ;
V_1 |= V_8 & 0xffff0000 ;
F_5 ( V_10 , V_1 ) ;
F_5 ( V_11 , ( V_12 - 1 ) & 0xffff0000 ) ;
F_6 ( V_13 , V_1 ) ;
V_1 &= ~ ( 1 << 4 ) ;
F_5 ( V_13 , V_1 ) ;
#ifdef F_3
F_4 ( L_2 ) ;
F_4 ( L_3 , ( void * ) V_8 , V_12 ) ;
#endif
F_7 ( V_2 ) ;
V_2 = NULL ;
return 1 ;
}
static int T_2 F_8 ( void )
{
int V_14 = 0 ;
static struct V_15 V_16 [] = {
{ F_9 (PCI_VENDOR_ID_MARVELL, PCI_DEVICE_ID_MARVELL_MV64360) } ,
{ }
} ;
#ifdef F_3
F_4 ( L_4 ) ;
#endif
if ( F_10 ( V_16 ) ) {
V_14 = F_11 ( V_17 ,
F_12 ( V_17 ) ) ;
if ( F_1 () < 0 )
{
V_18 . V_19 = 0 ;
V_18 . V_20 = 0 ;
V_18 . V_21 = 0 ;
V_18 . V_22 = 0 ;
#ifdef F_3
F_4 ( L_5
L_6 ) ;
#endif
}
}
#ifdef F_3
F_4 ( L_7 ) ;
#endif
return V_14 ;
}
