static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static int F_4 ( struct V_2 * V_3 )
{
T_2 V_4 ;
V_4 = F_5 ( V_5 + V_6 ) ;
V_4 |= V_7 ;
F_6 ( V_4 , V_5 + V_6 ) ;
return 0 ;
}
static void F_7 ( struct V_2 * V_3 )
{
T_2 V_4 ;
V_4 = F_5 ( V_5 + V_6 ) ;
V_4 &= ~ ( V_8 | V_7 ) ;
F_6 ( V_4 , V_5 + V_6 ) ;
}
static void F_8 ( struct V_2 * V_9 , int V_10 )
{
T_2 V_4 ;
V_4 = F_5 ( V_5 + V_6 ) ;
if ( V_10 )
V_4 |= V_8 ;
else
V_4 &= ~ V_8 ;
F_6 ( V_4 , V_5 + V_6 ) ;
}
static unsigned int F_9 ( struct V_11 * V_3 )
{
unsigned int V_12 = F_5 ( F_10 ( 0xca000000 + 4 ) ) ;
F_6 ( 8 , V_5 + 8 ) ;
return V_12 & 8 ;
}
static void F_11 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_14 . V_16 ;
T_2 V_4 = V_17 | V_18
| V_19 | V_20 ;
if ( V_16 -> V_21 <= 8 ||
( V_16 -> V_21 == 16 && V_16 -> V_22 . V_23 == 5 ) )
V_4 |= V_24 ;
else if ( V_14 -> V_14 . V_16 . V_21 <= 16 )
V_4 |= V_25 ;
else
V_4 = 0 ;
F_12 ( V_26 |
V_19 |
V_20 |
V_17 |
V_18 |
V_27 |
V_28 , V_4 ) ;
}
static int F_13 ( struct V_13 * V_14 )
{
V_14 -> V_29 = F_14 ( L_1 ) ;
if ( ! V_14 -> V_29 )
return - V_30 ;
return F_15 ( V_14 , V_31 ) ;
}
static void T_1 F_16 ( void )
{
#ifdef F_17
F_18 ( V_32 , 24000000 ) ;
#endif
}
static void T_1 F_19 ( void )
{
F_20 () ;
F_21 ( V_33 ) ;
F_22 ( true ) ;
}
static void T_1 F_23 ( void )
{
struct V_34 * V_35 ;
struct V_34 * V_36 ;
struct V_11 * V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
T_2 V_42 ;
int V_43 ;
V_35 = F_24 ( L_2 ) ;
if ( ! V_35 )
return;
V_36 = F_25 ( V_35 , V_44 ) ;
if ( ! V_36 )
return;
V_5 = F_26 ( V_36 , 0 ) ;
if ( ! V_5 )
return;
V_42 = F_5 ( V_5 ) ;
V_41 = F_27 ( sizeof( * V_41 ) , V_45 ) ;
if ( ! V_41 )
return;
V_43 = F_28 ( V_35 , L_3 ,
& V_41 -> V_46 ) ;
if ( V_43 )
return;
V_43 = F_28 ( V_35 , L_4 , & V_41 -> V_47 ) ;
if ( V_43 )
return;
V_41 -> V_48 = L_5 ;
V_41 -> V_49 = F_29 ( V_45 , L_6 ,
'A' + ( V_42 & 0x0f ) ) ;
V_39 = F_30 ( V_41 ) ;
if ( F_31 ( V_39 ) ) {
F_32 ( V_41 -> V_49 ) ;
F_32 ( V_41 ) ;
return;
}
V_37 = F_33 ( V_39 ) ;
F_34 ( V_37 , V_42 ) ;
F_35 ( V_35 , V_50 ,
V_51 , V_37 ) ;
}
