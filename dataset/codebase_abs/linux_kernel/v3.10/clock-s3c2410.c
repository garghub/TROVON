int F_1 ( struct V_1 * V_1 , int V_2 )
{
unsigned int V_3 = V_1 -> V_4 ;
unsigned long V_5 ;
V_5 = F_2 ( V_6 ) ;
if ( V_2 )
V_5 |= V_3 ;
else
V_5 &= ~ V_3 ;
V_5 &= ~ ( V_7 | V_8 ) ;
F_3 ( V_5 , V_6 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , int V_2 )
{
unsigned long V_9 = F_2 ( V_10 ) ;
unsigned long V_11 = V_9 ;
if ( V_2 )
V_9 &= ~ V_12 ;
else
V_9 |= V_12 ;
F_3 ( V_9 , V_10 ) ;
if ( V_2 && ( V_11 & V_12 ) )
F_5 ( 200 ) ;
return 0 ;
}
int T_1 F_6 ( void )
{
unsigned long V_9 = F_2 ( V_10 ) ;
unsigned long V_5 = F_2 ( V_6 ) ;
struct V_1 * V_13 ;
struct V_1 * V_14 ;
int V_15 ;
int V_16 ;
V_17 . V_2 = F_4 ;
if ( F_7 ( & V_18 ) < 0 )
F_8 ( V_19 L_1 ) ;
V_13 = V_20 ;
for ( V_16 = 0 ; V_16 < F_9 ( V_20 ) ; V_16 ++ , V_13 ++ ) {
V_13 -> V_21 = V_5 & V_13 -> V_4 ? 1 : 0 ;
V_15 = F_7 ( V_13 ) ;
if ( V_15 < 0 ) {
F_8 ( V_19 L_2 ,
V_13 -> V_22 , V_15 ) ;
}
}
F_10 ( V_23 , F_9 ( V_23 ) ) ;
F_11 ( V_23 , F_9 ( V_23 ) ) ;
V_14 = F_12 ( NULL , L_3 ) ;
F_8 ( L_4 ,
F_13 ( F_14 ( V_14 ) /
( 2 * F_15 ( V_9 ) ) ) ,
( V_9 & V_24 ) ? L_5 : L_6 ,
( V_9 & V_25 ) ? L_7 : L_8 ,
( V_9 & V_12 ) ? L_7 : L_8 ) ;
F_16 () ;
return 0 ;
}
