static void F_1 ( int V_1 )
{
if ( F_2 () )
F_3 () ;
else if ( V_1 != V_2 )
F_4 () ;
}
static int F_5 ( int V_3 )
{
unsigned int V_4 ;
unsigned long V_5 =
F_6 ( F_7 ( V_6 ) ) ;
long V_7 ;
T_1 V_8 ;
if ( V_3 < 0 || V_3 >= V_9 )
return - V_10 ;
V_4 = F_8 ( V_3 ) ;
if ( V_11 [ V_3 ] . V_12 || ! F_9 ( V_13 ) )
goto V_14;
V_7 = F_10 ( V_4 , & V_8 ) ;
if ( V_7 != V_15 ) {
F_11 ( L_1 , V_7 , V_3 ) ;
return - V_16 ;
}
if ( V_8 == V_17 )
goto V_14;
if ( V_8 == V_18 ) {
F_12 ( L_2 , V_3 , V_4 ) ;
V_7 = F_13 ( V_4 , V_5 ) ;
if ( V_7 != V_15 ) {
F_11 ( L_3 , V_7 , V_3 ) ;
return - V_16 ;
}
} else {
F_12 ( L_4
L_5 , V_3 , V_4 , V_8 ) ;
return - V_16 ;
}
V_14:
return F_14 ( V_3 ) ;
}
static int F_15 ( void )
{
int V_1 = F_16 () ;
F_17 ( V_1 , false ) ;
V_19 -> V_20 -- ;
if ( V_1 == V_2 )
V_2 = F_18 ( V_21 ) ;
if ( F_2 () )
F_19 () ;
else
F_20 () ;
return 0 ;
}
static void F_21 ( void )
{
unsigned int V_1 ;
unsigned long V_22 , V_23 ;
F_22 ( F_23 () ) ;
F_24 () ;
F_22 ( F_25 () ) ;
F_26 () ;
V_24 -> V_25 = NULL ;
V_1 = F_16 () ;
F_27 ( L_6 , V_1 ) ;
F_28 ( V_1 ) ;
F_29 () ;
V_23 = V_26 ;
if ( F_30 ( V_27 ) )
V_23 = V_28 ;
while ( ! F_31 ( V_1 ) ) {
F_32 ( V_1 , 0 ) ;
V_22 = F_33 ( V_1 ) ;
F_22 ( F_25 () ) ;
if ( ( ( V_22 & V_23 ) == V_29 ) ||
( ( V_22 & V_23 ) == V_30 ) ) {
if ( F_30 ( V_31 ) ) {
if ( F_2 () )
F_34 () ;
else
F_35 () ;
} else
F_36 () ;
} else if ( ( V_22 & V_23 ) == V_32 ) {
unsigned long V_33 = F_37 ( V_34 ) ;
asm volatile(PPC_MSGCLR(%0) : : "r" (msg));
}
F_38 () ;
if ( F_39 () )
continue;
if ( V_22 && ! F_31 ( V_1 ) )
F_27 ( L_7 ,
V_1 , V_22 ) ;
}
F_27 ( L_8 , V_1 ) ;
}
static int F_40 ( unsigned int V_3 )
{
if ( F_30 ( V_27 ) )
return 1 ;
return F_41 ( V_3 ) ;
}
static int F_42 ( int V_1 )
{
if ( F_2 () )
return F_43 ( V_1 ) ;
return 0 ;
}
static void F_44 ( int V_1 )
{
if ( F_45 ( V_1 ) )
return;
F_46 ( V_1 ) ;
}
static void F_47 ( int V_1 )
{
int V_35 = F_48 () ;
if ( F_49 ( V_1 , F_50 ( V_35 ) ) )
F_51 ( V_1 ) ;
else
F_46 ( V_1 ) ;
F_52 () ;
}
static void T_2 F_53 ( void )
{
if ( F_2 () )
F_54 () ;
else
F_55 () ;
if ( F_30 ( V_36 ) ) {
F_46 = V_37 -> V_38 ;
F_22 ( ! F_46 ) ;
if ( F_30 ( V_31 ) ) {
if ( F_30 ( V_39 ) )
V_37 -> V_38 = F_47 ;
else
V_37 -> V_38 = F_51 ;
} else {
V_37 -> V_38 = F_44 ;
}
}
}
void T_2 F_56 ( void )
{
V_37 = & V_40 ;
#ifdef F_57
V_41 . V_42 = F_21 ;
#endif
}
