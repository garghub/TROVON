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
bool F_20 ( void )
{
bool V_16 = false ;
struct V_3 * V_15 ;
V_15 = & F_11 ( V_12 ) ;
if ( ( V_15 -> V_23 & V_24 ) != 0 ) {
F_21 ( V_12 . V_23 , ~ V_24 ) ;
V_16 = true ;
}
return V_16 ;
}
int F_22 ( char * V_25 )
{
int V_26 = F_23 () ;
int V_7 , V_8 , V_16 ;
V_7 = ( int ) F_24 ( & F_16 ( V_12 , V_26 ) ) | 1 ;
V_8 = ( ( V_10 ) F_24 ( & F_16 ( V_12 , V_26 ) ) >> 32 ) ;
V_16 = F_25 ( V_27 , V_7 , V_8 ) ;
F_26 ( V_28 L_1 ,
V_26 , V_8 , V_7 , V_25 ) ;
return V_16 ;
}
static void F_27 ( void )
{
}
static void F_28 ( void )
{
F_22 ( L_2 ) ;
}
static void T_2 F_29 ( void )
{
F_30 ( F_22 ( L_3 ) ) ;
}
static void F_31 ( struct V_29 * V_30 )
{
F_4 ( V_27 , 0 , 0 ) ;
F_32 () ;
F_33 ( V_30 ) ;
}
static void F_34 ( void )
{
F_4 ( V_27 , 0 , 0 ) ;
F_32 () ;
F_35 () ;
}
void T_3 F_36 ( void )
{
if ( ! F_37 () )
return;
if ( V_2 && F_38 ( V_31 ) ) {
V_27 = V_32 ;
V_11 = V_33 ;
} else if ( ! ( V_2 && F_38 ( V_34 ) ) )
return;
F_26 ( V_28 L_4 ,
V_27 , V_11 ) ;
if ( F_22 ( L_5 ) )
return;
V_35 . V_36 = F_9 ;
V_37 . V_38 = F_15 ;
V_37 . V_39 = F_2 ;
V_37 . V_40 = F_8 ;
#ifdef F_39
V_41 . V_42 =
F_29 ;
#endif
V_37 . V_43 = F_27 ;
V_37 . V_44 = F_28 ;
V_45 . V_46 = F_34 ;
#ifdef F_40
V_45 . V_47 = F_31 ;
#endif
F_18 () ;
F_41 ( & V_48 , V_49 ) ;
V_50 . V_51 = 1 ;
V_50 . V_52 = L_6 ;
if ( F_38 ( V_53 ) )
F_42 ( V_54 ) ;
}
