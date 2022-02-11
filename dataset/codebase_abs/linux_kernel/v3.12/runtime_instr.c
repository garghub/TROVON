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
if ( V_11 == V_12 )
V_9 -> V_13 = 1 ;
V_9 -> V_14 = 1 ;
V_9 -> V_15 = 1 ;
V_9 -> V_16 = 1 ;
V_9 -> V_17 = 1 ;
V_9 -> V_18 = 1 ;
V_9 -> V_19 = V_20 ;
V_9 -> V_21 = 1 ;
}
void F_7 ( void )
{
struct V_22 * V_23 = V_3 ;
if ( ! V_23 -> V_24 . V_25 )
return;
F_3 () ;
F_8 ( V_23 -> V_24 . V_25 ) ;
V_23 -> V_24 . V_26 = 0 ;
V_23 -> V_24 . V_25 = NULL ;
}
static void F_9 ( struct V_27 V_27 ,
unsigned int V_28 , unsigned long V_29 )
{
struct V_30 V_31 ;
if ( ! ( V_28 & V_32 ) )
return;
F_10 ( V_33 ) ;
if ( ! V_3 -> V_24 . V_25 )
return;
if ( V_3 -> V_24 . V_26 < V_34 ||
V_3 -> V_24 . V_26 > V_35 ) {
F_11 ( 1 ) ;
return;
}
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_36 = V_3 -> V_24 . V_26 ;
V_31 . V_37 = V_38 ;
if ( V_28 & V_39 )
V_31 . V_40 = V_41 ;
else if ( V_28 & V_42 )
V_31 . V_40 = V_43 ;
else
return;
F_12 ( V_3 -> V_24 . V_26 , & V_31 , V_3 ) ;
}
static int T_1 F_13 ( void )
{
int V_44 ;
if ( ! F_1 () )
return 0 ;
F_14 ( V_45 ) ;
V_44 = F_15 ( 0x1407 , F_9 ) ;
if ( V_44 )
F_16 ( V_45 ) ;
else
F_17 ( L_1 ) ;
return V_44 ;
}
