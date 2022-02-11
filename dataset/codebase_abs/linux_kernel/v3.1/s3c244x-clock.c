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
static int F_4 ( struct V_10 * V_11 )
{
unsigned long V_3 = F_2 ( V_9 ) ;
unsigned long V_12 ;
struct V_1 * V_13 ;
int V_14 ;
F_5 ( L_1 ,
( V_3 & V_7 ) ? L_2 : L_3 ) ;
V_15 . V_2 = ( V_3 & V_7 ) ? & V_6 : & V_5 ;
V_14 = F_6 ( & V_15 ) ;
if ( V_14 < 0 ) {
F_5 ( V_16 L_4 , V_14 ) ;
return V_14 ;
}
V_13 = F_7 ( NULL , L_5 ) ;
if ( F_8 ( V_13 ) ) {
F_5 ( V_16 L_6 ) ;
return - V_17 ;
}
if ( F_9 ( V_13 ) > ( 94 * V_18 ) ) {
V_19 . V_20 = F_9 ( V_13 ) / 2 ;
F_10 ( & V_21 ) ;
V_12 = F_2 ( V_22 ) ;
V_12 |= V_23 ;
F_3 ( V_12 , V_22 ) ;
F_11 ( & V_21 ) ;
}
return 0 ;
}
static int F_12 ( void )
{
return F_13 ( & V_24 , & V_25 ) ;
}
static int F_14 ( void )
{
return F_13 ( & V_26 , & V_27 ) ;
}
