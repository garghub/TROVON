static int F_1 ( void )
{
return F_2 ( 64 ) ;
}
static void F_3 ( void )
{
struct V_1 * V_2 = F_4 ( V_3 ) ;
F_5 ( & V_4 ) ;
V_2 -> V_5 . V_6 &= ~ V_7 ;
}
static void F_6 ( struct V_8 * V_9 )
{
V_9 -> V_10 = 0xfff ;
V_9 -> V_11 = 1 ;
V_9 -> V_12 = 1 ;
V_9 -> V_13 = 1 ;
V_9 -> V_14 = 1 ;
V_9 -> V_15 = 1 ;
V_9 -> V_16 = V_17 ;
V_9 -> V_18 = 1 ;
}
void F_7 ( void )
{
struct V_19 * V_20 = V_3 ;
if ( ! V_20 -> V_21 . V_22 )
return;
F_3 () ;
F_8 ( V_20 -> V_21 . V_22 ) ;
V_20 -> V_21 . V_23 = 0 ;
V_20 -> V_21 . V_22 = NULL ;
}
static void F_9 ( struct V_24 V_24 ,
unsigned int V_25 , unsigned long V_26 )
{
struct V_27 V_28 ;
if ( ! ( V_25 & V_29 ) )
return;
F_10 ( V_30 ) ;
if ( ! V_3 -> V_21 . V_22 )
return;
if ( V_3 -> V_21 . V_23 < V_31 ||
V_3 -> V_21 . V_23 > V_32 ) {
F_11 ( 1 ) ;
return;
}
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_33 = V_3 -> V_21 . V_23 ;
V_28 . V_34 = V_35 ;
if ( V_25 & V_36 )
V_28 . V_37 = V_38 ;
else if ( V_25 & V_39 )
V_28 . V_37 = V_40 ;
else
return;
F_12 ( V_3 -> V_21 . V_23 , & V_28 , V_3 ) ;
}
static int T_1 F_13 ( void )
{
int V_41 ;
if ( ! F_1 () )
return 0 ;
F_14 ( V_42 ) ;
V_41 = F_15 ( V_43 ,
F_9 ) ;
if ( V_41 )
F_16 ( V_42 ) ;
else
F_17 ( L_1 ) ;
return V_41 ;
}
