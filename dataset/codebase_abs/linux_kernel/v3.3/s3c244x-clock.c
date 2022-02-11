static int F_1 ( struct V_1 * V_1 , struct V_1 * V_2 )
{
unsigned long V_3 ;
unsigned long V_4 ;
if ( V_2 == & V_5 )
V_4 = 0 ;
else if ( V_2 == & V_6 )
V_4 = V_7 ;
else
return - V_8 ;
V_1 -> V_2 = V_2 ;
V_3 = F_2 ( V_9 ) ;
V_3 &= ~ V_7 ;
V_3 |= V_4 ;
F_3 ( V_3 , V_9 ) ;
return 0 ;
}
static int F_4 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
unsigned long V_3 = F_2 ( V_9 ) ;
unsigned long V_14 ;
struct V_1 * V_15 ;
int V_16 ;
F_5 ( L_1 ,
( V_3 & V_7 ) ? L_2 : L_3 ) ;
V_17 . V_2 = ( V_3 & V_7 ) ? & V_6 : & V_5 ;
V_16 = F_6 ( & V_17 ) ;
if ( V_16 < 0 ) {
F_5 ( V_18 L_4 , V_16 ) ;
return V_16 ;
}
V_15 = F_7 ( NULL , L_5 ) ;
if ( F_8 ( V_15 ) ) {
F_5 ( V_18 L_6 ) ;
return - V_19 ;
}
if ( F_9 ( V_15 ) > ( 94 * V_20 ) ) {
V_21 . V_22 = F_9 ( V_15 ) / 2 ;
F_10 ( & V_23 ) ;
V_14 = F_2 ( V_24 ) ;
V_14 |= V_25 ;
F_3 ( V_14 , V_24 ) ;
F_11 ( & V_23 ) ;
}
return 0 ;
}
static int F_12 ( void )
{
return F_13 ( & V_26 ) ;
}
static int F_14 ( void )
{
return F_13 ( & V_27 ) ;
}
