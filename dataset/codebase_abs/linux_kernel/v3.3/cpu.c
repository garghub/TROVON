static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
unsigned long V_5 ;
unsigned int V_6 ;
switch ( V_3 ) {
case V_7 :
F_2 ( & V_8 -> V_9 . V_10 ) ;
F_3 ( V_5 ) ;
F_4 ( V_8 ) |= V_11 ;
V_6 = F_5 () ;
F_6 ( V_6 | V_11 ) ;
F_7 ( & ( V_8 -> V_9 . V_10 ) ) ;
F_6 ( V_6 & ~ V_11 ) ;
F_8 ( V_5 ) ;
return V_12 ;
}
return V_13 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( F_1 , 0 ) ;
}
