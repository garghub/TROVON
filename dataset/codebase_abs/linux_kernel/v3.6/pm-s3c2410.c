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
if ( F_10 () ) {
F_11 ( F_12 ( 2 ) , V_9 , NULL ) ;
F_13 ( F_12 ( 2 ) ) ;
}
if ( F_9 () ) {
F_14 ( F_15 ( 13 ) , V_10 ) ;
F_14 ( F_15 ( 14 ) , V_10 ) ;
F_14 ( F_15 ( 15 ) , V_10 ) ;
}
}
static void F_16 ( void )
{
unsigned long V_11 ;
V_11 = F_5 ( V_12 ) ;
V_11 &= V_13 ;
F_2 ( V_11 , V_12 ) ;
if ( F_10 () ) {
F_11 ( F_12 ( 2 ) , V_14 , NULL ) ;
F_13 ( F_12 ( 2 ) ) ;
}
}
static int F_17 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
V_19 = F_1 ;
V_20 = V_21 ;
return 0 ;
}
static int T_1 F_18 ( void )
{
return F_19 ( & V_22 ) ;
}
static int T_1 F_20 ( void )
{
return F_19 ( & V_23 ) ;
}
static int T_1 F_21 ( void )
{
return F_19 ( & V_24 ) ;
}
static int T_1 F_22 ( void )
{
return F_19 ( & V_25 ) ;
}
