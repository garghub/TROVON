int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_6 ;
T_1 V_7 , V_8 ;
F_2 ( & V_5 -> V_9 , V_6 ) ;
V_8 = V_2 -> V_10 * 4 ;
V_7 = F_3 ( V_5 -> V_11 + V_12 ) ;
V_7 &= ~ ( 0xf << V_8 ) ;
V_7 |= V_3 << V_8 ;
F_4 ( V_7 , V_5 -> V_11 + V_12 ) ;
F_5 ( & V_5 -> V_9 , V_6 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , int V_13 , int V_14 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_6 ;
T_1 V_7 , V_8 ;
F_2 ( & V_5 -> V_9 , V_6 ) ;
V_8 = V_2 -> V_10 * 3 ;
V_7 = F_3 ( V_5 -> V_11 + V_15 ) ;
V_7 &= ~ ( 0x7 << V_8 ) ;
V_7 |= ( ( V_13 << 2 ) | V_14 ) << V_8 ;
F_4 ( V_7 , V_5 -> V_11 + V_15 ) ;
F_5 ( & V_5 -> V_9 , V_6 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_17 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_6 ;
T_1 V_7 , V_8 ;
F_2 ( & V_5 -> V_9 , V_6 ) ;
V_8 = V_2 -> V_10 * 6 + ( V_2 -> V_10 > 1 ? 4 : 0 ) ;
V_7 = F_3 ( V_5 -> V_11 + V_18 ) ;
V_7 &= ~ ( 0x3f << V_8 ) ;
V_7 |= ( ( V_17 << 3 ) | V_16 ) << V_8 ;
F_4 ( V_7 , V_5 -> V_11 + V_18 ) ;
F_5 ( & V_5 -> V_9 , V_6 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_6 ;
F_2 ( & V_5 -> V_9 , V_6 ) ;
if ( ! V_5 -> V_19 )
F_9 ( V_5 -> V_20 , V_21 ) ;
V_5 -> V_19 ++ ;
F_5 ( & V_5 -> V_9 , V_6 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_6 ;
F_2 ( & V_5 -> V_9 , V_6 ) ;
V_5 -> V_19 -- ;
if ( ! V_5 -> V_19 )
F_11 ( V_5 -> V_20 , V_21 ) ;
if ( V_5 -> V_19 < 0 )
V_5 -> V_19 = 0 ;
F_5 ( & V_5 -> V_9 , V_6 ) ;
return 0 ;
}
struct V_1 * F_12 ( struct V_22 * V_20 , unsigned int V_10 )
{
struct V_4 * V_5 = V_20 -> V_23 ;
struct V_1 * V_2 , * V_24 ;
unsigned long V_6 ;
if ( V_10 >= 4 )
return F_13 ( - V_25 ) ;
V_2 = & V_5 -> V_26 [ V_10 ] ;
V_24 = V_2 ;
F_2 ( & V_5 -> V_9 , V_6 ) ;
if ( V_2 -> V_27 ) {
V_24 = F_13 ( - V_28 ) ;
goto V_29;
}
V_2 -> V_27 = true ;
V_29:
F_5 ( & V_5 -> V_9 , V_6 ) ;
return V_24 ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_6 ;
F_2 ( & V_5 -> V_9 , V_6 ) ;
V_2 -> V_27 = false ;
F_5 ( & V_5 -> V_9 , V_6 ) ;
}
int F_15 ( struct V_22 * V_20 , struct V_30 * V_31 ,
unsigned long V_11 )
{
struct V_4 * V_5 ;
int V_32 ;
V_5 = F_16 ( V_31 , sizeof( * V_5 ) , V_33 ) ;
if ( ! V_5 )
return - V_34 ;
V_20 -> V_23 = V_5 ;
F_17 ( & V_5 -> V_9 ) ;
V_5 -> V_20 = V_20 ;
V_5 -> V_11 = F_18 ( V_31 , V_11 , V_35 ) ;
if ( ! V_5 -> V_11 )
return - V_34 ;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ ) {
V_5 -> V_26 [ V_32 ] . V_5 = V_5 ;
V_5 -> V_26 [ V_32 ] . V_10 = V_32 ;
}
F_19 ( L_1 , V_36 , V_11 , V_5 -> V_11 ) ;
return 0 ;
}
void F_20 ( struct V_22 * V_20 )
{
}
