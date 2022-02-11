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
static T_3 T_4 F_16 ( void )
{
return F_5 ( V_32 ) ;
}
static void T_1 F_17 ( void )
{
F_18 ( F_16 , 32 , 24000000 ) ;
}
static void T_1 F_19 ( void )
{
F_20 () ;
F_21 ( V_33 ) ;
}
static void T_1 F_22 ( void )
{
struct V_34 * V_35 ;
struct V_11 * V_36 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
T_2 V_41 ;
V_35 = F_23 ( NULL , V_42 ) ;
if ( ! V_35 )
return;
V_5 = F_24 ( V_35 , 0 ) ;
if ( ! V_5 )
return;
F_25 ( NULL , V_43 ,
V_44 , NULL ) ;
V_41 = F_5 ( V_5 ) ;
V_40 = F_26 ( sizeof( * V_40 ) , V_45 ) ;
if ( ! V_40 )
return;
V_40 -> V_46 = L_2 ;
V_40 -> V_47 = L_3 ;
V_40 -> V_48 = L_4 ;
V_40 -> V_49 = F_27 ( V_45 , L_5 ,
'A' + ( V_41 & 0x0f ) ) ;
V_38 = F_28 ( V_40 ) ;
if ( F_29 ( V_38 ) ) {
F_30 ( V_40 -> V_49 ) ;
F_30 ( V_40 ) ;
return;
}
V_36 = F_31 ( V_38 ) ;
F_32 ( V_36 , V_41 ) ;
}
