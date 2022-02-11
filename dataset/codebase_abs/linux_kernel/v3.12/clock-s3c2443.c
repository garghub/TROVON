static int F_1 ( struct V_1 * V_1 , struct V_1 * V_2 )
{
unsigned long V_3 = F_2 ( V_4 ) ;
V_3 &= ~ ( V_5 |
V_6 ) ;
if ( V_2 == & V_7 )
V_3 |= V_6 ;
else if ( V_2 == & V_8 )
V_3 |= V_5 ;
else
return - V_9 ;
if ( V_1 -> V_10 > 0 ) {
F_3 ( V_3 , V_4 ) ;
}
V_1 -> V_2 = V_2 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , int V_11 )
{
return F_1 ( V_1 , V_1 -> V_2 ) ;
}
void T_1 F_5 ( int V_12 )
{
unsigned long V_13 = F_2 ( V_14 ) ;
int V_15 ;
V_7 . V_16 = F_6 ( V_13 , V_12 ) ;
V_7 . V_2 = & V_17 . V_1 ;
F_7 ( V_12 , V_18 ,
V_19 , F_8 ( V_19 ) ,
V_20 ) ;
F_9 ( V_21 , F_8 ( V_21 ) ) ;
for ( V_15 = 0 ; V_15 < F_8 ( V_22 ) ; V_15 ++ )
F_10 ( V_22 [ V_15 ] , 1 ) ;
F_11 ( V_23 , F_8 ( V_23 ) ) ;
F_12 ( V_23 , F_8 ( V_23 ) ) ;
F_13 ( V_24 , F_8 ( V_24 ) ) ;
}
