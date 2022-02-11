static int F_1 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
int V_6 , V_7 ;
for ( V_7 = 0 ; V_7 < 20 ; V_7 ++ ) {
V_6 = ( F_2 ( V_4 + V_8 )
& V_9 ) ? 1 : 0 ;
if ( V_6 || ! V_3 )
break;
F_3 ( 10 ) ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_2 * V_6 )
{
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
* V_6 = F_2 ( V_4 + V_10 ) ;
return 4 ;
}
static int F_5 ( struct V_1 * V_2 )
{
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
T_2 V_11 ;
V_11 = V_12 | V_13 | V_14 ;
F_6 ( V_4 + V_8 , V_11 ) ;
F_6 ( V_4 + V_8 , V_11 & ~ V_12 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
void T_1 * V_4 = ( void T_1 * ) V_2 -> V_5 ;
T_2 V_11 ;
V_11 = V_15 | V_16 ;
F_6 ( V_4 + V_8 ,
F_2 ( V_4 + V_8 ) & ~ V_11 ) ;
}
static int T_3 F_8 ( struct V_17 * V_18 )
{
void T_1 * V_4 ;
struct V_19 * V_20 = V_18 -> V_21 . V_22 ;
struct V_23 V_24 ;
int V_25 = 0 ;
V_25 = F_9 ( V_20 , 0 , & V_24 ) ;
if ( V_25 )
return - V_26 ;
V_4 = F_10 ( V_24 . V_27 , 0x100 ) ;
if ( ! V_4 )
return - V_28 ;
V_29 . V_5 = ( unsigned long ) V_4 ;
F_11 ( V_30 L_1 ) ;
V_25 = F_12 ( & V_29 ) ;
if ( V_25 )
F_13 ( V_4 ) ;
return V_25 ;
}
static int T_4 F_14 ( struct V_17 * V_21 )
{
void T_1 * V_4 = ( void T_1 * ) V_29 . V_5 ;
F_15 ( & V_29 ) ;
F_13 ( V_4 ) ;
return 0 ;
}
static int T_5 F_16 ( void )
{
return F_17 ( & V_31 ) ;
}
static void T_6 F_18 ( void )
{
F_19 ( & V_31 ) ;
}
