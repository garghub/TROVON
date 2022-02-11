void T_1 F_1 ( char * V_1 )
{
F_2 () ;
F_3 ( & V_2 -> V_3 . V_4 , V_5 ) ;
F_4 ( F_5 () & ~ ( V_6 | V_7 | V_8 | V_9 ) ) ;
F_6 ( & V_2 -> V_3 . V_10 [ 0 ] ) ;
F_7 ( L_1 ) ;
}
static int F_8 ( struct V_11 * V_12 ,
T_2 V_13 , T_3 V_14 )
{
if ( V_13 == 0 && F_9 ( V_14 ) == 0 )
return V_15 ;
else
return V_16 ;
}
static void T_4 F_10 ( struct V_17 * V_18 )
{
struct V_11 * V_12 ;
struct V_19 V_20 ;
if ( F_11 ( V_18 , 0 , & V_20 ) || V_20 . V_21 - V_20 . V_22 < 0x10b )
goto V_23;
F_12 ( V_24 ) ;
V_12 = F_13 ( V_18 ) ;
if ( ! V_12 )
return;
V_12 -> V_25 = V_18 ;
F_14 ( V_12 , V_20 . V_22 + 0x100 , V_20 . V_22 + 0x104 , 0 ) ;
F_15 ( V_12 , V_18 , 1 ) ;
return;
V_23:
F_16 ( V_26 L_2 ) ;
}
void T_4 F_17 ( void )
{
struct V_17 * V_18 ;
V_27 . V_28 = F_8 ;
F_18 (np, NULL, L_3 )
F_10 ( V_18 ) ;
}
