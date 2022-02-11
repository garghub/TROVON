int F_1 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_2 ;
T_3 * V_3 = V_1 -> V_3 ;
if ( V_1 -> V_4 != V_5 ) {
if ( V_2 -> V_6 & V_7 )
return 0 ;
}
if ( ( V_3 [ V_8 ] & 4 ) &&
( ( V_3 [ V_9 ] >> 8 ) & 0x7f ) )
return 1 ;
if ( ( V_3 [ V_10 ] & 0x404 ) == 0x404 ||
( V_3 [ V_11 ] & 0x404 ) == 0x404 )
return 1 ;
if ( F_2 ( V_1 ) )
return 1 ;
return 0 ;
}
T_4 F_3 ( T_2 * V_2 )
{
unsigned long V_12 = V_2 -> V_13 + V_14 ;
if ( V_2 -> V_6 & V_15 )
return F_4 ( ( void V_16 * ) V_12 ) ;
else
return F_5 ( V_12 ) ;
}
static void F_6 ( T_2 * V_2 , T_4 V_17 )
{
unsigned long V_12 = V_2 -> V_13 + V_14 ;
if ( V_2 -> V_6 & V_15 )
F_7 ( V_17 , ( void V_16 * ) V_12 ) ;
else
F_8 ( V_17 , V_12 ) ;
}
void F_9 ( T_1 * V_1 , int V_18 )
{
T_2 * V_2 = V_1 -> V_2 ;
T_4 V_19 = V_1 -> V_20 & 1 ;
T_4 V_21 = V_2 -> V_22 -> V_23 ( V_2 ) ;
if ( V_18 )
V_21 |= ( 1 << ( 5 + V_19 ) ) ;
else
V_21 &= ~ ( 1 << ( 5 + V_19 ) ) ;
F_6 ( V_2 , V_21 ) ;
}
int F_10 ( T_1 * V_1 , struct V_24 * V_25 )
{
T_2 * V_2 = V_1 -> V_2 ;
T_5 * V_26 = ( T_5 * ) V_2 -> V_27 ;
unsigned int V_28 = 0 ;
int V_29 ;
struct V_30 * V_31 ;
T_4 V_32 = ! ! ( V_2 -> V_6 & V_33 ) ;
F_11 (hwif->sg_table, sg, cmd->sg_nents, i) {
T_6 V_34 , V_35 , V_36 , V_37 ;
V_34 = F_12 ( V_31 ) ;
V_35 = F_13 ( V_31 ) ;
while ( V_35 ) {
if ( V_28 ++ >= V_38 )
goto V_39;
V_37 = 0x10000 - ( V_34 & 0xffff ) ;
if ( V_37 > V_35 )
V_37 = V_35 ;
* V_26 ++ = F_14 ( V_34 ) ;
V_36 = V_37 & 0xffff ;
if ( V_32 )
V_36 = ( ( V_36 >> 2 ) - 1 ) << 16 ;
else if ( V_36 == 0x0000 ) {
if ( V_28 ++ >= V_38 )
goto V_39;
* V_26 ++ = F_14 ( 0x8000 ) ;
* V_26 ++ = F_14 ( V_34 + 0x8000 ) ;
V_36 = 0x8000 ;
}
* V_26 ++ = F_14 ( V_36 ) ;
V_34 += V_37 ;
V_35 -= V_37 ;
}
}
if ( V_28 ) {
if ( ! V_32 )
* -- V_26 |= F_14 ( 0x80000000 ) ;
return V_28 ;
}
V_39:
F_15 ( V_40 L_1 , V_1 -> V_41 ,
V_28 ? L_2 : L_3 ) ;
return 0 ;
}
int F_16 ( T_1 * V_1 , struct V_24 * V_25 )
{
T_2 * V_2 = V_1 -> V_2 ;
T_4 V_42 = ( V_2 -> V_6 & V_15 ) ? 1 : 0 ;
T_4 V_43 = ( V_25 -> V_44 & V_45 ) ? 0 : V_46 ;
T_4 V_21 ;
if ( F_10 ( V_1 , V_25 ) == 0 ) {
F_17 ( V_1 , V_25 ) ;
return 1 ;
}
if ( V_42 )
F_18 ( V_2 -> V_47 ,
( void V_16 * ) ( V_2 -> V_13 + V_48 ) ) ;
else
F_19 ( V_2 -> V_47 , V_2 -> V_13 + V_48 ) ;
if ( V_42 )
F_7 ( V_43 , ( void V_16 * ) ( V_2 -> V_13 + V_49 ) ) ;
else
F_8 ( V_43 , V_2 -> V_13 + V_49 ) ;
V_21 = V_2 -> V_22 -> V_23 ( V_2 ) ;
F_6 ( V_2 , V_21 | V_50 | V_51 ) ;
return 0 ;
}
int F_20 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_2 ;
T_4 V_21 = V_2 -> V_22 -> V_23 ( V_2 ) ;
F_15 ( V_52 L_4 ,
V_1 -> V_41 , V_53 , V_21 ) ;
if ( ( V_21 & 0x18 ) == 0x18 )
return V_54 ;
V_2 -> V_55 = NULL ;
if ( V_21 & V_50 )
return - 1 ;
if ( V_21 & V_56 )
return V_54 ;
if ( V_21 & V_51 )
return V_54 ;
return 0 ;
}
void F_21 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_2 ;
T_4 V_57 ;
if ( V_2 -> V_6 & V_15 ) {
V_57 = F_4 ( ( void V_16 * ) ( V_2 -> V_13 + V_49 ) ) ;
F_7 ( V_57 | V_58 ,
( void V_16 * ) ( V_2 -> V_13 + V_49 ) ) ;
} else {
V_57 = F_5 ( V_2 -> V_13 + V_49 ) ;
F_8 ( V_57 | V_58 , V_2 -> V_13 + V_49 ) ;
}
}
int F_22 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_2 ;
T_4 V_21 = 0 , V_57 = 0 ;
if ( V_2 -> V_6 & V_15 ) {
V_57 = F_4 ( ( void V_16 * ) ( V_2 -> V_13 + V_49 ) ) ;
F_7 ( V_57 & ~ V_58 ,
( void V_16 * ) ( V_2 -> V_13 + V_49 ) ) ;
} else {
V_57 = F_5 ( V_2 -> V_13 + V_49 ) ;
F_8 ( V_57 & ~ V_58 , V_2 -> V_13 + V_49 ) ;
}
V_21 = V_2 -> V_22 -> V_23 ( V_2 ) ;
F_6 ( V_2 , V_21 | V_50 | V_51 ) ;
#define F_23 (ATA_DMA_ACTIVE | ATA_DMA_ERR | ATA_DMA_INTR)
if ( ( V_21 & F_23 ) != V_51 )
return 0x10 | V_21 ;
return 0 ;
}
int F_24 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_2 ;
T_4 V_21 = V_2 -> V_22 -> V_23 ( V_2 ) ;
return ( V_21 & V_51 ) ? 1 : 0 ;
}
