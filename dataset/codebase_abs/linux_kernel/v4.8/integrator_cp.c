static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static unsigned int F_4 ( struct V_2 * V_3 )
{
unsigned int V_4 = F_5 ( F_6 ( 0xca000000 + 4 ) ) ;
F_7 ( 8 , V_5 + 8 ) ;
return V_4 & 8 ;
}
static void F_8 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_7 . V_9 ;
T_2 V_10 = V_11 | V_12
| V_13 | V_14 ;
if ( V_9 -> V_15 <= 8 ||
( V_9 -> V_15 == 16 && V_9 -> V_16 . V_17 == 5 ) )
V_10 |= V_18 ;
else if ( V_7 -> V_7 . V_9 . V_15 <= 16 )
V_10 |= V_19 ;
else
V_10 = 0 ;
F_9 ( V_20 |
V_13 |
V_14 |
V_11 |
V_12 |
V_21 |
V_22 , V_10 ) ;
}
static int F_10 ( struct V_6 * V_7 )
{
V_7 -> V_23 = F_11 ( L_1 ) ;
if ( ! V_7 -> V_23 )
return - V_24 ;
return F_12 ( V_7 , V_25 ) ;
}
static T_3 T_4 F_13 ( void )
{
return F_5 ( V_26 ) ;
}
static void T_1 F_14 ( void )
{
F_15 ( F_13 , 32 , 24000000 ) ;
}
static void T_1 F_16 ( void )
{
F_17 () ;
F_18 () ;
}
static void T_1 F_19 ( void )
{
struct V_27 * V_28 ;
V_28 = F_20 ( NULL , V_29 ) ;
if ( ! V_28 )
return;
V_5 = F_21 ( V_28 , 0 ) ;
if ( ! V_5 )
return;
F_22 ( NULL , V_30 , NULL ) ;
}
