void F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
F_3 ( V_3 , V_2 -> V_4 . V_5 ) ;
#endif
F_3 ( V_6 , V_2 -> V_4 . V_7 ) ;
}
int F_4 ( unsigned long V_7 , struct V_1 * V_8 )
{
int V_9 ;
if ( ! F_5 ( V_10 ) )
return - V_11 ;
if ( ! V_8 || ! V_7 )
return - V_12 ;
F_6 ( & V_8 -> V_13 ) ;
F_6 ( V_8 -> V_4 . V_14 ) ;
V_9 = F_7 ( V_8 ) ;
if ( V_9 < 0 )
goto V_15;
V_8 -> V_4 . V_7 |= V_7 ;
F_8 ( V_8 ) ;
if ( F_9 ( & V_8 -> V_16 ) > 1 )
F_10 ( F_8 , V_8 , 1 ) ;
V_15:
F_11 ( V_8 -> V_4 . V_14 ) ;
F_11 ( & V_8 -> V_13 ) ;
return V_9 ;
}
void F_12 ( unsigned long V_7 , struct V_1 * V_8 )
{
int V_17 ;
if ( ! F_5 ( V_10 ) )
return;
if ( F_13 ( ! V_8 ) )
return;
F_6 ( & V_8 -> V_13 ) ;
F_6 ( V_8 -> V_4 . V_14 ) ;
V_8 -> V_4 . V_7 &= ~ V_7 ;
V_17 = F_14 ( V_8 ) ;
F_8 ( V_8 ) ;
if ( F_9 ( & V_8 -> V_16 ) > 1 )
F_10 ( F_8 , V_8 , 1 ) ;
if ( V_17 != V_18 )
F_15 ( V_17 ) ;
F_11 ( V_8 -> V_4 . V_14 ) ;
F_11 ( & V_8 -> V_13 ) ;
}
static int F_16 ( int V_19 )
{
return - 1 ;
}
static T_1 F_17 ( struct V_20 * V_21 )
{
T_1 V_22 ;
T_1 T_2 * V_23 ;
V_23 = ( T_1 T_2 * ) V_21 -> V_24 ;
if ( ! F_18 ( V_25 , V_23 , sizeof( * V_23 ) ) )
return 0 ;
if ( F_19 ( V_22 , V_23 ) )
return 0 ;
return V_22 ;
}
int F_20 ( struct V_20 * V_21 , unsigned long V_26 ,
unsigned long V_27 )
{
int V_19 ;
T_1 V_22 = 0 ;
if ( ! F_5 ( V_10 ) ) {
F_21 ( L_1 ) ;
F_22 ( V_28 , V_21 , V_29 , V_26 ) ;
}
if ( ! F_23 ( V_21 ) ) {
F_24 ( L_2 , V_21 , V_30 ) ;
}
V_19 = F_25 ( V_27 ) ;
if ( V_19 < 0 ) {
T_1 V_31 ;
T_1 V_32 ;
V_22 = F_17 ( V_21 ) ;
if ( V_22 == 0 )
return - 1 ;
V_32 = ( V_22 >> ( 31 - 10 ) ) & 0x1f ;
V_31 = V_21 -> V_33 [ V_32 ] ;
V_19 = ( V_31 >> 16 ) & 0x3f ;
}
if ( ( F_26 ( V_19 ) & V_34 -> V_35 -> V_4 . V_7 ) != 0 ) {
F_8 ( V_34 -> V_35 ) ;
return 0 ;
}
if ( ! F_16 ( V_19 ) )
return 0 ;
F_27 ( L_3 ,
V_34 -> V_36 , V_34 -> V_37 , V_19 ) ;
if ( V_22 == 0 ) {
V_22 = F_17 ( V_21 ) ;
if ( V_22 == 0 )
return - 1 ;
}
if ( V_22 & 1 ) {
V_21 -> V_38 &= ~ ( 0xful << 28 ) ;
V_21 -> V_38 |= V_39 << 28 ;
V_21 -> V_24 += 4 ;
} else {
#ifdef F_28
F_22 ( V_28 , V_21 , V_29 , V_26 ) ;
#else
V_21 -> V_24 += 4 ;
#endif
}
return 0 ;
}
