int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 * V_5 , int V_6 )
{
unsigned long V_7 ;
int V_8 , V_9 , V_10 ;
F_2 ( V_11 ) ;
F_3 ( & V_2 -> V_12 , V_7 ) ;
if ( ! V_2 -> V_13 || ( V_2 -> V_14 & V_15 ) ) {
F_4 ( & V_2 -> V_12 , V_7 ) ;
return 1 ;
}
F_4 ( & V_2 -> V_12 , V_7 ) ;
V_10 = V_6 > 0 ? F_5 ( ( int ) V_5 [ 0 ] , V_6 - 1 ) : 0 ;
for ( V_8 = 0 ; V_8 + 1 < V_10 ; V_8 += 2 ) {
F_6 ( & V_11 ) ;
V_9 = ( V_5 [ V_8 ] << 8 ) | ( V_5 [ V_8 + 1 ] ) ;
V_11 . V_16 = ! ! ( V_9 & 0x8000 ) ;
V_11 . V_17 = F_7 ( V_11 . V_16 ? ( 65536 - V_9 ) : V_9 ) ;
if ( V_8 == 0 && V_11 . V_17 > 15000000 )
V_11 . V_17 -= 15000000 ;
F_8 ( V_2 -> V_13 , & V_11 ) ;
}
F_9 ( V_2 -> V_13 ) ;
return 1 ;
}
static int F_10 ( struct V_13 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
unsigned long V_7 ;
F_3 ( & V_2 -> V_12 , V_7 ) ;
V_2 -> V_14 &= ~ V_15 ;
F_4 ( & V_2 -> V_12 , V_7 ) ;
return 0 ;
}
static void F_11 ( struct V_13 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
unsigned long V_7 ;
F_3 ( & V_2 -> V_12 , V_7 ) ;
V_2 -> V_14 |= V_15 ;
F_4 ( & V_2 -> V_12 , V_7 ) ;
}
int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_13 * V_20 ;
int V_21 = 0 ;
V_20 = F_13 ( V_22 ) ;
if ( ! V_20 )
return - V_23 ;
V_20 -> V_19 = V_2 ;
V_20 -> V_24 = V_25 ;
V_20 -> V_26 = F_10 ;
V_20 -> V_27 = F_11 ;
V_20 -> V_28 = V_2 -> V_29 -> V_30 ;
V_20 -> V_31 = V_2 -> V_29 -> V_32 ;
V_20 -> V_33 . V_34 = V_2 -> V_29 -> V_35 ;
V_20 -> V_33 . V_36 = V_2 -> V_29 -> V_36 ;
V_20 -> V_33 . V_37 = V_2 -> V_29 -> V_37 ;
V_20 -> V_33 . V_38 = V_2 -> V_29 -> V_38 ;
V_20 -> V_18 . V_39 = & V_2 -> V_29 -> V_18 ;
V_20 -> V_40 = V_41 ;
V_20 -> V_42 = V_43 ;
V_20 -> V_44 = F_14 ( 100 ) ;
V_20 -> V_45 = F_7 ( 1 ) ;
V_21 = F_15 ( V_20 ) ;
if ( V_21 )
goto V_46;
V_2 -> V_13 = V_20 ;
return 0 ;
V_46:
F_16 ( V_20 ) ;
return V_21 ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_13 * V_20 = V_2 -> V_13 ;
V_2 -> V_13 = NULL ;
F_18 ( V_20 ) ;
}
