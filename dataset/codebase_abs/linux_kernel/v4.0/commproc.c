void T_1 F_1 ()
{
V_1 = (struct V_2 * ) ( V_3 ) ;
V_1 -> V_4 = ( V_5 | V_6 ) ;
while ( V_1 -> V_4 & V_6 ) ;
V_1 -> V_7 = 0x0740 ;
V_8 = V_9 ;
V_10 = V_8 + V_11 ;
}
void
F_2 ( void )
{
V_1 -> V_12 =
( V_13 | V_14 | V_15 | V_16 ) |
( V_17 << 13 ) |
V_18 |
( V_19 << 5 ) |
V_20 ;
V_1 -> V_21 = 0 ;
}
static void
F_3 ( int V_22 , void * V_23 , struct V_24 * V_25 )
{
#if 0
((volatile immap_t *)IMAP_ADDR)->im_cpic.cpic_civr = 1;
vec = ((volatile immap_t *)IMAP_ADDR)->im_cpic.cpic_civr;
vec >>= 11;
if (cpm_vecs[vec].handler != 0)
(*cpm_vecs[vec].handler)(cpm_vecs[vec].dev_id);
else
((immap_t *)IMAP_ADDR)->im_cpic.cpic_cimr &= ~(1 << vec);
((immap_t *)IMAP_ADDR)->im_cpic.cpic_cisr |= (1 << vec);
#endif
}
static void
F_4 ( void * V_23 )
{
}
void
F_5 ( int V_26 , T_2 V_27 , void * V_28 )
{
F_6 ( V_26 , V_27 , 0 , L_1 , V_28 ) ;
}
void
F_7 ( int V_26 )
{
V_29 [ V_26 ] . V_27 = NULL ;
V_29 [ V_26 ] . V_28 = NULL ;
V_1 -> V_21 &= ~ ( 1 << V_26 ) ;
}
T_3
F_8 ( T_3 V_30 )
{
T_3 V_31 ;
if ( ( V_8 + V_30 ) >= V_10 )
return ( V_32 ) ;
V_31 = V_8 ;
V_8 += V_30 ;
return ( V_31 ) ;
}
void
F_9 ( T_3 V_33 , T_3 V_34 )
{
volatile T_3 * V_35 ;
V_35 = ( volatile T_3 * ) ( & V_1 -> V_36 [ 0 ] . V_37 ) ;
V_35 += V_33 ;
* V_35 = ( ( V_38 / V_34 - 1 ) << 1 ) | V_39 ;
}
