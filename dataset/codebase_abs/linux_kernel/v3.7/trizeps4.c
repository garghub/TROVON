void F_1 ( int V_1 )
{
if ( V_1 ) {
V_2 |= V_1 ;
V_2 |= V_3 ;
V_2 &= ~ V_4 ;
F_2 ( V_2 ) ;
F_3 ( 2000 ) ;
V_2 &= ~ V_3 ;
F_2 ( V_2 ) ;
F_3 ( 2000 ) ;
} else {
V_2 |= V_3 ;
F_2 ( V_2 ) ;
F_3 ( 1000 ) ;
V_2 &= ~ 0xf ;
F_2 ( V_2 ) ;
}
F_4 ( L_1 , V_5 , V_1 ? L_2 : L_3 ,
V_2 ) ;
}
static void F_5 ( int V_6 )
{
if ( V_6 )
V_2 |= V_7 ;
else
V_2 &= ~ V_7 ;
F_4 ( L_1 , V_5 , V_6 ? L_2 : L_3 ,
V_2 ) ;
F_2 ( V_2 ) ;
}
static int F_6 ( struct V_8 * V_9 , T_1 V_10 ,
void * V_11 )
{
int V_12 ;
V_12 = F_7 ( V_13 , V_10 ,
V_14 | V_15 ,
L_4 , V_11 ) ;
if ( V_12 ) {
F_8 ( V_16 L_5
L_6 ) ;
return - 1 ;
}
return 0 ;
}
static void F_9 ( struct V_8 * V_9 , void * V_11 )
{
F_10 ( V_13 , V_11 ) ;
}
static int F_11 ( struct V_8 * V_9 )
{
V_17 &= ~ V_18 ;
F_12 ( V_17 ) ;
return 0 ;
}
static void F_13 ( struct V_8 * V_9 )
{
V_17 |= V_18 ;
F_12 ( V_17 ) ;
}
static void F_14 ( struct V_8 * V_9 , int V_19 )
{
unsigned long V_20 ;
F_15 ( V_20 ) ;
if ( V_19 & V_21 )
V_17 &= ~ V_22 ;
else if ( V_19 & V_23 )
V_17 |= V_22 ;
if ( V_19 & V_24 )
V_17 |= V_18 ;
else
V_17 &= ~ V_18 ;
F_12 ( V_17 ) ;
F_16 ( V_20 ) ;
F_17 ( V_9 , V_19 ) ;
}
static void T_2 F_18 ( void )
{
F_19 ( F_20 ( V_25 ) ) ;
if ( F_21 () ) {
F_19 ( F_20 ( V_26 ) ) ;
F_22 ( V_27 ,
F_23 ( V_27 ) ) ;
} else {
F_22 ( V_28 ,
F_23 ( V_28 ) ) ;
}
F_24 ( NULL ) ;
F_25 ( NULL ) ;
F_26 ( NULL ) ;
if ( 0 )
F_27 ( NULL , & V_29 ) ;
else
F_27 ( NULL , & V_30 ) ;
F_28 ( & V_31 ) ;
#ifndef F_29
F_30 ( & V_32 ) ;
#endif
F_31 ( & V_33 ) ;
F_32 ( NULL ) ;
F_33 ( NULL ) ;
F_34 ( 0 , V_34 ,
F_23 ( V_34 ) ) ;
V_2 = 0x00A0 ;
F_2 ( V_2 ) ;
F_5 ( 1 ) ;
}
static void T_2 F_35 ( void )
{
F_36 () ;
F_37 ( V_35 , F_23 ( V_35 ) ) ;
if ( ( F_38 ( V_36 ) & 0x8 ) && ( F_38 ( V_37 ) & 0x1 ) ) {
V_38 = V_39 ;
V_40 [ 0 ] . V_41 = 2 ;
} else {
V_38 = V_42 ;
V_40 [ 0 ] . V_41 = 4 ;
}
}
