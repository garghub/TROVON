static void F_1 ( void )
{
F_2 ( F_3 ( V_1 ) , V_2 ) ;
F_4 ( L_1 , F_5 ( V_2 ) ) ;
F_4 ( L_2 , F_5 ( V_3 ) ) ;
if ( F_6 () ) {
void * V_4 = F_7 ( V_5 ) ;
unsigned long V_6 ;
unsigned long V_7 = 0 ;
for ( V_6 = 0 ; V_6 < 0x40000 ; V_6 += 0x400 )
V_7 += F_5 ( V_4 + V_6 ) ;
F_2 ( V_7 , F_7 ( V_8 ) ) ;
}
if ( F_8 () || F_9 () ) {
void * V_4 = F_7 ( V_5 ) ;
unsigned long V_6 ;
unsigned long V_7 = 0 ;
for ( V_6 = 0 ; V_6 < 0x40000 ; V_6 += 0x4 )
V_7 += F_5 ( V_4 + V_6 ) ;
F_2 ( V_7 , F_7 ( V_8 ) ) ;
}
if ( F_10 () )
F_11 ( F_12 ( 2 ) , 1 ) ;
if ( F_9 () ) {
F_13 ( F_14 ( 13 ) , V_9 ) ;
F_13 ( F_14 ( 14 ) , V_9 ) ;
F_13 ( F_14 ( 15 ) , V_9 ) ;
}
}
static void F_15 ( void )
{
unsigned long V_10 ;
V_10 = F_5 ( V_11 ) ;
V_10 &= V_12 ;
F_2 ( V_10 , V_11 ) ;
if ( F_10 () )
F_11 ( F_12 ( 2 ) , 0 ) ;
}
static int F_16 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
V_17 = F_1 ;
V_18 = V_19 ;
return 0 ;
}
static int T_1 F_17 ( void )
{
return F_18 ( & V_20 ) ;
}
static int T_1 F_19 ( void )
{
return F_18 ( & V_21 ) ;
}
static int T_1 F_20 ( void )
{
return F_18 ( & V_22 ) ;
}
static int T_1 F_21 ( void )
{
return F_18 ( & V_23 ) ;
}
