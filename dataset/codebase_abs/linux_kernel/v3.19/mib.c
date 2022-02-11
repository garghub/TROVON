void F_1 ( T_1 V_1 , unsigned long V_2 )
{
if ( V_2 == 0 ) {
V_1 -> V_3 . V_4 ++ ;
return;
}
if ( V_2 & V_5 )
V_1 -> V_3 . V_6 ++ ;
if ( V_2 & V_7 )
V_1 -> V_3 . V_8 ++ ;
if ( V_2 & V_9 )
V_1 -> V_3 . V_10 ++ ;
if ( V_2 & V_11 )
V_1 -> V_3 . V_12 ++ ;
if ( V_2 & V_13 )
V_1 -> V_3 . V_14 ++ ;
if ( V_2 & V_15 )
V_1 -> V_3 . V_16 ++ ;
if ( V_2 & V_17 )
V_1 -> V_3 . V_18 ++ ;
if ( V_2 & V_19 )
V_1 -> V_3 . V_20 ++ ;
if ( V_2 & V_21 )
V_1 -> V_3 . V_22 ++ ;
if ( V_2 & V_23 )
V_1 -> V_3 . V_24 ++ ;
if ( V_2 & V_25 )
V_1 -> V_3 . V_26 ++ ;
if ( V_2 & V_27 )
V_1 -> V_3 . V_28 ++ ;
if ( V_2 & V_29 )
V_1 -> V_3 . V_30 ++ ;
}
void
F_2 (
T_2 V_31 ,
T_1 V_1 ,
unsigned long V_32
)
{
V_31 -> V_33 += ( unsigned long long ) ( V_32 & 0x000000ff ) ;
V_31 -> V_34 += ( unsigned long long ) ( ( V_32 & 0x0000ff00 ) >> 8 ) ;
V_31 -> V_35 += ( unsigned long long ) ( ( V_32 & 0x00ff0000 ) >> 16 ) ;
V_31 -> V_36 += ( unsigned long long ) ( ( V_32 & 0xff000000 ) >> 24 ) ;
}
