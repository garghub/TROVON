static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_4 , V_5 , V_6 ;
unsigned long V_7 , V_8 , V_9 , V_10 ;
unsigned long V_11 ;
V_8 = V_2 -> V_12 . V_8 ;
V_9 = V_2 -> V_12 . V_9 ;
V_11 = V_2 -> V_13 . V_7 ;
if ( V_11 > V_9 )
V_11 = V_9 ;
F_2 ( L_1 ,
V_14 , V_8 , V_9 , V_11 ) ;
F_2 ( L_2 ,
V_14 , V_2 -> V_12 . V_8 , V_2 -> V_12 . V_9 ,
V_2 -> V_12 . V_7 , V_2 -> V_12 . V_15 ) ;
V_5 = V_8 / V_9 ;
if ( V_5 < 1 )
V_5 = 1 ;
if ( V_5 > 2 )
V_5 = 2 ;
V_2 -> V_16 . V_17 = V_5 ;
V_10 = V_8 / V_5 ;
V_3 = V_10 / V_11 ;
if ( V_3 < 1 )
V_3 = 1 ;
V_2 -> V_12 . V_7 = V_7 = V_10 / V_3 ;
V_2 -> V_16 . V_6 = V_6 = V_9 < V_10 ;
V_2 -> V_12 . V_9 = V_6 ? V_7 : V_10 ;
F_2 ( L_3 ,
V_14 , V_9 , V_7 , V_5 , V_3 , V_2 -> V_16 . V_6 ) ;
if ( V_3 > 4 )
goto V_18;
V_4 = ( V_7 > V_2 -> V_13 . V_15 ) ? 2 : 1 ;
if ( ( V_7 / V_4 ) > V_2 -> V_13 . V_15 )
V_4 ++ ;
V_2 -> V_12 . V_15 = V_7 / V_4 ;
F_2 ( L_4 , V_14 , V_4 ) ;
if ( V_4 > 2 )
goto V_18;
V_4 *= V_3 ;
V_2 -> V_16 . V_19 = V_3 * V_5 ;
V_2 -> V_16 . V_20 = V_4 * V_5 ;
return 0 ;
V_18:
return - V_21 ;
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
unsigned long V_23 ;
V_23 = V_22 = F_4 ( V_24 ) ;
V_22 &= ~ V_25 ;
V_22 &= ~ V_26 ;
V_22 &= ~ V_27 ;
if ( V_2 -> V_16 . V_17 == 2 )
V_22 |= V_25 ;
V_22 |= ( ( V_2 -> V_16 . V_19 / V_2 -> V_16 . V_17 ) - 1 ) ;
if ( V_2 -> V_16 . V_20 != V_2 -> V_16 . V_19 )
V_22 |= V_27 ;
F_2 ( L_5 , V_14 , V_23 , V_22 ) ;
F_5 ( V_22 , V_24 ) ;
F_6 ( V_9 , V_2 -> V_16 . V_6 ? V_7 : V_8 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
unsigned long V_30 ;
F_2 ( L_6 , V_14 ,
V_29 -> V_30 , V_2 -> V_12 . V_7 ) ;
V_30 = ( V_29 -> V_30 / 10 ) ;
V_30 *= ( V_2 -> V_12 . V_7 / 100 ) ;
V_30 /= ( 1 * 1000 * 1000 ) ;
F_2 ( L_7 , V_14 , V_30 ) ;
F_5 ( V_30 , V_31 ) ;
}
static int F_8 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
unsigned long V_36 ;
V_7 = F_9 ( NULL , L_8 ) ;
if ( F_10 ( V_7 ) ) {
F_11 ( V_37 L_9 , V_14 ) ;
return - V_38 ;
}
V_8 = F_9 ( NULL , L_10 ) ;
if ( F_10 ( V_8 ) ) {
F_11 ( V_37 L_11 , V_14 ) ;
goto V_39;
}
V_36 = F_12 ( V_8 ) ;
if ( V_36 > 200000000 ) {
F_11 ( V_40
L_12 ,
V_14 , V_36 / 1000000 ) ;
V_41 . V_13 . V_8 = 266000000 ;
V_41 . V_13 . V_7 = 133000000 ;
V_41 . V_13 . V_15 = 66000000 ;
}
V_9 = F_9 ( NULL , L_13 ) ;
if ( F_10 ( V_9 ) ) {
F_11 ( V_37 L_14 , V_14 ) ;
goto V_42;
}
V_43 = F_9 ( NULL , L_15 ) ;
if ( F_10 ( V_43 ) ) {
F_11 ( V_37 L_16 , V_14 ) ;
goto V_44;
}
return F_13 ( & V_41 ) ;
V_44:
F_14 ( V_9 ) ;
V_42:
F_14 ( V_8 ) ;
V_39:
F_14 ( V_7 ) ;
return - V_38 ;
}
static int F_15 ( void )
{
return F_16 ( & V_45 ) ;
}
