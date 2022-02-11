void F_1 ( int V_1 , void * V_2 )
{
F_2 ( F_3 ( V_2 ) , V_3 +
F_4 ( V_1 ) ) ;
}
static int T_1 F_5 ( void )
{
struct V_4 * V_5 ;
struct V_6 V_7 ;
int V_8 = 0 ;
V_5 = F_6 ( NULL , V_9 ) ;
if ( ! V_5 )
return 0 ;
F_7 ( L_1 ) ;
if ( F_8 ( V_5 , 0 , & V_7 ) ) {
F_9 ( L_2 ) ;
V_8 = - V_10 ;
goto V_11;
}
if ( F_10 ( V_5 , L_3 ) ) {
F_11 ( V_12 L_4 ) ;
V_7 . V_13 = V_7 . V_13 - V_14 ;
V_7 . V_15 = V_7 . V_13 + V_16 - 1 ;
}
if ( ! F_12 ( V_7 . V_13 , F_13 ( & V_7 ) ,
V_5 -> V_17 ) ) {
F_9 ( L_5 ) ;
V_8 = - V_18 ;
goto V_11;
}
V_3 = F_14 ( V_7 . V_13 , F_13 ( & V_7 ) ) ;
if ( ! V_3 ) {
F_9 ( L_6 ) ;
F_15 ( V_7 . V_13 , F_13 ( & V_7 ) ) ;
V_8 = - V_19 ;
goto V_11;
}
V_11:
F_16 ( V_5 ) ;
return V_8 ;
}
static void F_17 ( void )
{
T_2 V_20 ;
if ( V_3 == NULL )
return;
V_20 = F_18 ( V_3 + V_21 ) ;
V_20 |= V_22 ;
F_2 ( V_20 , V_3 + V_21 ) ;
}
void F_19 ( bool V_23 )
{
unsigned int V_1 = F_20 ( F_21 () ) ;
T_2 V_20 ;
if ( V_3 == NULL )
return;
V_20 = F_18 ( V_3 + F_22 ( V_1 ) ) ;
V_20 |= V_24 |
V_25 |
V_26 |
V_27 |
V_28 |
V_29 ;
F_2 ( V_20 , V_3 + F_22 ( V_1 ) ) ;
V_20 = F_18 ( V_3 + F_23 ( V_1 ) ) ;
if ( V_23 )
V_20 |= V_30 ;
V_20 |= V_31 ;
F_2 ( V_20 , V_3 + F_23 ( V_1 ) ) ;
V_20 = F_18 ( V_3 + F_24 ( V_1 ) ) ;
V_20 |= V_32 ;
F_2 ( V_20 , V_3 + F_24 ( V_1 ) ) ;
}
static T_3 int F_25 ( unsigned long V_23 )
{
F_19 ( V_23 ) ;
F_26 ( V_33 ) ;
F_27 () ;
F_28 () ;
F_29 () ;
F_30 () ;
F_31 () ;
asm volatile(
"mrc p15, 0, r0, c1, c0, 0 \n\t"
"tst r0, #(1 << 2) \n\t"
"orreq r0, r0, #(1 << 2) \n\t"
"mcreq p15, 0, r0, c1, c0, 0 \n\t"
"isb "
: : : "r0");
F_11 ( L_7 ) ;
return 0 ;
}
static int F_32 ( unsigned long V_23 )
{
return F_33 ( V_23 , F_25 ) ;
}
static T_3 void F_34 ( void )
{
unsigned int V_1 = F_20 ( F_21 () ) ;
T_2 V_20 ;
if ( V_3 == NULL )
return;
V_20 = F_18 ( V_3 + F_23 ( V_1 ) ) ;
V_20 &= ~ V_30 ;
F_2 ( V_20 , V_3 + F_23 ( V_1 ) ) ;
V_20 = F_18 ( V_3 + F_22 ( V_1 ) ) ;
V_20 &= ~ ( V_25 | V_26 ) ;
V_20 &= ~ V_24 ;
V_20 &= ~ V_27 ;
V_20 &= ~ ( V_28 | V_29 ) ;
F_2 ( V_20 , V_3 + F_22 ( V_1 ) ) ;
}
static int F_35 ( struct V_34 * V_35 ,
unsigned long V_36 , void * V_37 )
{
if ( V_36 == V_38 ) {
unsigned int V_1 = F_20 ( F_21 () ) ;
F_1 ( V_1 , V_39 ) ;
} else if ( V_36 == V_40 ) {
F_34 () ;
}
return V_41 ;
}
int T_1 F_36 ( void )
{
struct V_4 * V_5 ;
if ( ! F_37 ( L_8 ) )
return 0 ;
V_5 = F_38 ( NULL , NULL , L_9 ) ;
if ( ! V_5 )
return 0 ;
F_16 ( V_5 ) ;
V_5 = F_6 ( NULL , V_9 ) ;
if ( ! V_5 )
return 0 ;
F_16 ( V_5 ) ;
F_17 () ;
V_42 . V_43 . V_44 = F_32 ;
F_39 ( & V_42 ) ;
F_40 ( & V_45 ) ;
return 0 ;
}
