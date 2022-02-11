static T_1 void F_1 ( void * V_1 )
{
void (* F_2)( struct V_2 * ) =
F_3 ( V_3 ) ;
#ifdef F_4
if ( ! F_2 ) {
F_5 ( L_1 ) ;
F_2 = F_3 ( V_3 ) ;
}
#endif
if ( ! F_2 )
F_6 ( L_2 ) ;
else {
(* F_2)( (struct V_2 * ) V_1 ) ;
F_7 ( V_3 ) ;
}
F_8 () ;
}
static void F_9 ( char * V_4 )
{
F_10 ( 20 ) ;
V_5 -> V_6 = V_7 ;
F_8 () ;
}
static void F_11 ( unsigned long V_1 )
{
unsigned long V_8 = V_9 -> V_10 . V_11 . V_12 ^ V_13 ;
V_9 -> V_10 . V_11 . V_12 = V_8 ;
F_12 ( & V_14 , V_15 + V_1 ) ;
}
static void F_13 ( void )
{
F_1 ( & V_16 ) ;
}
static void F_14 ( unsigned long V_1 )
{
F_1 ( & V_16 ) ;
}
void F_15 ( void )
{
if ( V_17 )
return;
if ( V_18 || F_16 ( V_19 , 1 ) ) {
F_1 ( & V_16 ) ;
}
V_18 = 1 ;
V_14 . V_1 = V_20 ;
F_11 ( V_20 ) ;
F_17 ( & V_21 ) ;
V_21 . V_22 = F_14 ;
V_21 . V_23 = V_15 + V_24 * V_25 ;
F_18 ( & V_21 ) ;
}
static int F_19 ( struct V_26 * V_27 , unsigned long V_28 ,
void * V_29 )
{
unsigned long V_8 ;
if ( V_17 )
return V_30 ;
V_17 = 1 ;
V_8 = V_9 -> V_10 . V_11 . V_12 | V_31 ;
V_9 -> V_10 . V_11 . V_12 = V_8 ;
V_14 . V_1 = V_32 ;
F_11 ( V_32 ) ;
return V_30 ;
}
static T_2 int F_20 ( void )
{
unsigned long V_8 = V_9 -> V_10 . V_11 . V_12 ;
V_8 |= V_13 ;
V_8 &= ~ V_31 ;
V_9 -> V_10 . V_11 . V_12 = V_8 ;
V_33 = F_9 ;
V_34 = F_13 ;
V_35 = F_13 ;
F_17 ( & V_14 ) ;
V_14 . V_22 = F_11 ;
F_21 ( & V_36 , & V_37 ) ;
return 0 ;
}
