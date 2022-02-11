static int F_1 ( char * V_1 )
{
V_2 = 0 ;
return 0 ;
}
static unsigned long F_2 ( void )
{
struct V_3 * V_4 ;
struct V_5 V_6 ;
int V_7 , V_8 ;
V_7 = ( int ) F_3 ( & V_9 ) ;
V_8 = ( ( V_10 ) F_3 ( & V_9 ) >> 32 ) ;
F_4 ( V_11 , V_7 , V_8 ) ;
V_4 = & F_5 ( V_12 ) ;
F_6 ( & V_9 , V_4 , & V_6 ) ;
F_7 ( V_12 ) ;
return V_6 . V_13 ;
}
static int F_8 ( unsigned long V_14 )
{
return - 1 ;
}
static T_1 F_9 ( void )
{
struct V_3 * V_15 ;
T_1 V_16 ;
F_10 () ;
V_15 = & F_11 ( V_12 ) ;
V_16 = F_12 ( V_15 ) ;
F_13 () ;
return V_16 ;
}
static T_1 F_14 ( struct V_17 * V_18 )
{
return F_9 () ;
}
static unsigned long F_15 ( void )
{
struct V_3 * V_15 ;
V_15 = & F_16 ( V_12 , 0 ) ;
return F_17 ( V_15 ) ;
}
static void F_18 ( void )
{
unsigned long V_19 ;
V_10 V_20 ;
V_19 = F_15 () ;
V_20 = ( ( V_10 ) V_19 * 1000 ) ;
F_19 ( V_20 , V_21 ) ;
V_22 = V_20 ;
}
int F_20 ( char * V_23 )
{
int V_24 = F_21 () ;
int V_7 , V_8 , V_16 ;
V_7 = ( int ) F_22 ( & F_16 ( V_12 , V_24 ) ) | 1 ;
V_8 = ( ( V_10 ) F_22 ( & F_16 ( V_12 , V_24 ) ) >> 32 ) ;
V_16 = F_23 ( V_25 , V_7 , V_8 ) ;
F_24 ( V_26 L_1 ,
V_24 , V_8 , V_7 , V_23 ) ;
return V_16 ;
}
static void T_2 F_25 ( void )
{
F_26 ( F_20 ( L_2 ) ) ;
F_27 () ;
}
static void F_28 ( struct V_27 * V_28 )
{
F_4 ( V_25 , 0 , 0 ) ;
F_29 () ;
F_30 ( V_28 ) ;
}
static void F_31 ( void )
{
F_4 ( V_25 , 0 , 0 ) ;
F_29 () ;
F_32 () ;
}
void T_3 F_33 ( void )
{
if ( ! F_34 () )
return;
if ( V_2 && F_35 ( V_29 ) ) {
V_25 = V_30 ;
V_11 = V_31 ;
} else if ( ! ( V_2 && F_35 ( V_32 ) ) )
return;
F_24 ( V_26 L_3 ,
V_25 , V_11 ) ;
if ( F_20 ( L_4 ) )
return;
V_33 . V_34 = F_9 ;
V_35 . V_36 = F_15 ;
V_35 . V_37 = F_2 ;
V_35 . V_38 = F_8 ;
#ifdef F_36
V_39 . V_40 =
F_25 ;
#endif
V_41 . V_42 = F_31 ;
#ifdef F_37
V_41 . V_43 = F_28 ;
#endif
F_18 () ;
F_38 ( & V_44 , V_45 ) ;
V_46 . V_47 = 1 ;
V_46 . V_48 = L_5 ;
if ( F_35 ( V_49 ) )
F_39 ( V_50 ) ;
}
