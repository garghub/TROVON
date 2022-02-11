static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
int V_5 ;
int V_6 = ! F_2 ( V_7 ) ;
switch ( V_3 ) {
case V_8 :
F_3 () ;
V_5 = F_4 () ;
if ( ! V_6 )
F_5 ( V_9 | V_10 ) ;
else
F_5 ( V_9 | V_10 | V_11 ) ;
F_6 () ;
F_7 ( V_12 ) |= ( V_9 | V_10 ) ;
if ( V_6 )
F_7 ( V_12 ) |= V_11 ;
else
F_7 ( V_12 ) &= ~ V_11 ;
if ( ! V_5 ) {
F_8 ( V_13 ) ;
if ( ! F_9 () ) {
F_10 () ;
F_11 () ;
} else
F_12 ( V_12 ) ;
}
F_13 () ;
return V_14 ;
}
return V_15 ;
}
static int T_1 F_14 ( void )
{
return F_15 ( F_1 , 0 ) ;
}
