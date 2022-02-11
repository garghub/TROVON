static int
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , 0x001218 ) ;
switch ( V_3 & 0x00000300 ) {
case 0x00000000 : V_2 -> V_4 . type = V_5 ; break;
case 0x00000100 : V_2 -> V_4 . type = V_6 ; break;
case 0x00000200 : V_2 -> V_4 . type = V_7 ; break;
case 0x00000300 : V_2 -> V_4 . type = V_8 ; break;
}
V_2 -> V_4 . V_9 = F_2 ( V_2 , 0x10020c ) & 0xff000000 ;
V_2 -> V_4 . V_10 = ( F_2 ( V_2 , 0x100200 ) & 0x00000003 ) + 1 ;
return F_2 ( V_2 , 0x100320 ) ;
}
void
F_3 ( struct V_1 * V_2 , int V_11 , T_1 V_9 , T_1 V_12 ,
struct V_13 * V_14 )
{
T_1 V_15 = F_4 ( V_9 , 0x80 ) ;
T_1 V_16 = F_5 ( V_15 / V_2 -> V_4 . V_10 , 0x100 ) ;
if ( ( V_12 & 2 ) &&
! F_6 ( & V_2 -> V_16 , 1 , V_16 , V_16 , 1 , & V_14 -> V_17 ) ) {
V_14 -> V_18 = 0x28000000 ;
V_14 -> V_18 |= ( ( V_14 -> V_17 -> V_19 ) >> 8 ) ;
V_14 -> V_18 |= ( ( V_14 -> V_17 -> V_19 + V_16 - 1 ) >> 8 ) << 13 ;
#ifdef F_7
V_14 -> V_18 |= 0x40000000 ;
#endif
}
}
static int
F_8 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = ( void * ) V_21 ;
int V_24 ;
V_24 = F_9 ( & V_23 -> V_25 ) ;
if ( V_24 )
return V_24 ;
F_10 ( V_23 , 0x10033c , 0x00008000 , 0x00000000 ) ;
return 0 ;
}
static int
F_11 ( struct V_20 * V_26 , struct V_20 * V_27 ,
struct V_28 * V_29 , void * V_30 , T_1 V_9 ,
struct V_20 * * V_31 )
{
struct V_22 * V_23 ;
int V_24 ;
V_24 = F_12 ( V_26 , V_27 , V_29 , & V_23 ) ;
* V_31 = F_13 ( V_23 ) ;
if ( V_24 )
return V_24 ;
V_23 -> V_25 . V_32 = V_33 ;
V_23 -> V_25 . V_4 . V_34 = F_1 ;
V_23 -> V_25 . V_14 . V_35 = 8 ;
V_23 -> V_25 . V_14 . V_34 = V_36 ;
V_23 -> V_25 . V_14 . V_37 = F_3 ;
V_23 -> V_25 . V_14 . V_38 = V_39 ;
V_23 -> V_25 . V_14 . V_40 = V_41 ;
return F_14 ( & V_23 -> V_25 ) ;
}
