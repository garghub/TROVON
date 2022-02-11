static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
if ( V_1 == V_5 )
F_2 ( V_4 ) ;
else
V_6 -> V_7 = 0x89 ;
return V_8 ;
}
static int F_3 ( struct V_9 * V_10 , int V_11 )
{
struct V_3 * V_4 = V_10 -> V_12 -> V_13 ;
struct V_14 * V_15 = F_4 ( V_4 ) ;
unsigned char V_16 = 0x01 ;
unsigned long V_17 = F_5 ( V_10 -> V_18 . V_19 ) ;
if ( ! V_11 )
V_16 |= 0x04 ;
V_15 -> V_20 = V_11 ;
if ( V_11 ) {
F_6 ( V_17 , V_10 -> V_18 . V_21 ) ;
} else {
F_7 ( V_17 , V_10 -> V_18 . V_21 ) ;
}
V_6 -> V_22 = V_10 -> V_18 . V_21 | ( 1 << 24 ) ;
V_6 -> V_23 = V_17 ;
V_6 -> V_24 = V_16 ;
return 0 ;
}
static void F_8 ( struct V_3 * V_4 , struct V_9 * V_25 ,
int V_26 )
{
V_6 -> V_24 = 0 ;
}
int F_9 ( struct V_27 * V_28 )
{
static unsigned char V_29 = 0 ;
struct V_3 * V_4 ;
T_2 V_30 ;
struct V_14 * V_15 ;
if ( ! V_31 || V_29 )
return 0 ;
V_29 ++ ;
V_28 -> V_32 = L_1 ;
V_28 -> V_33 = V_34 ,
V_28 -> V_35 = V_36 ,
V_4 = F_10 ( V_28 , sizeof( struct V_14 ) ) ;
if ( ! V_4 )
goto V_37;
V_4 -> V_38 = 0xfffe4000 ;
V_4 -> V_1 = V_5 ;
V_30 . V_39 = ( volatile unsigned char * ) 0xfffe4000 ;
V_30 . V_40 = ( volatile unsigned char * ) 0xfffe4001 ;
V_15 = F_4 ( V_4 ) ;
V_15 -> V_41 = 0xff ;
V_15 -> V_42 = 0 ;
V_15 -> V_43 = V_44 ;
F_11 ( V_4 , V_30 , F_3 , F_8 , V_45 ) ;
if ( F_12 ( V_5 , F_1 , 0 ,
L_2 , V_4 ) )
goto V_46;
if ( F_12 ( V_47 , F_1 , 0 ,
L_3 , V_4 ) )
goto V_48;
#if 0
m147_pcc->scsi_interrupt = 0x10;
udelay(100);
m147_pcc->scsi_interrupt = 0x00;
udelay(2000);
m147_pcc->scsi_interrupt = 0x40;
#endif
V_6 -> V_49 = 0x09 ;
V_6 -> V_24 = 0x00 ;
V_6 -> V_7 = 0x89 ;
return 1 ;
V_48:
F_13 ( V_5 , F_1 ) ;
V_46:
F_14 ( V_4 ) ;
V_37:
return 0 ;
}
int F_15 ( struct V_3 * V_4 )
{
#ifdef F_16
F_13 ( V_5 , F_1 ) ;
F_13 ( V_47 , F_1 ) ;
#endif
return 1 ;
}
