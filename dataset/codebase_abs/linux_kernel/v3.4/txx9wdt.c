static int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( V_4 | V_5 , & V_6 -> V_7 ) ;
F_4 ( & V_3 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( V_8 * V_2 -> V_9 , & V_6 -> V_10 ) ;
F_3 ( V_11 , & V_6 -> V_12 ) ;
F_3 ( 0 , & V_6 -> V_13 ) ;
F_3 ( V_14 | V_15 | V_16 ,
& V_6 -> V_17 ) ;
F_3 ( V_4 | V_5 , & V_6 -> V_7 ) ;
F_4 ( & V_3 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( V_18 , & V_6 -> V_7 ) ;
F_3 ( F_7 ( & V_6 -> V_17 ) & ~ V_14 ,
& V_6 -> V_17 ) ;
F_4 ( & V_3 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_19 )
{
V_2 -> V_9 = V_19 ;
F_6 ( V_2 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int T_1 F_9 ( struct V_20 * V_21 )
{
struct V_22 * V_23 ;
int V_24 ;
V_25 = F_10 ( NULL , L_1 ) ;
if ( F_11 ( V_25 ) ) {
V_24 = F_12 ( V_25 ) ;
V_25 = NULL ;
goto exit;
}
V_24 = F_13 ( V_25 ) ;
if ( V_24 ) {
F_14 ( V_25 ) ;
V_25 = NULL ;
goto exit;
}
V_23 = F_15 ( V_21 , V_26 , 0 ) ;
V_6 = F_16 ( & V_21 -> V_21 , V_23 ) ;
if ( ! V_6 ) {
V_24 = - V_27 ;
goto exit;
}
if ( V_9 < 1 || V_9 > V_28 )
V_9 = V_29 ;
V_30 . V_9 = V_9 ;
V_30 . V_31 = 1 ;
V_30 . V_32 = V_28 ;
F_17 ( & V_30 , V_33 ) ;
V_24 = F_18 ( & V_30 ) ;
if ( V_24 )
goto exit;
F_19 ( L_2 ,
V_9 , V_28 , V_33 ) ;
return 0 ;
exit:
if ( V_25 ) {
F_20 ( V_25 ) ;
F_14 ( V_25 ) ;
}
return V_24 ;
}
static int T_2 F_21 ( struct V_20 * V_21 )
{
F_22 ( & V_30 ) ;
F_20 ( V_25 ) ;
F_14 ( V_25 ) ;
return 0 ;
}
static void F_23 ( struct V_20 * V_21 )
{
F_6 ( & V_30 ) ;
}
static int T_1 F_24 ( void )
{
return F_25 ( & V_34 , F_9 ) ;
}
static void T_2 F_26 ( void )
{
F_27 ( & V_34 ) ;
}
