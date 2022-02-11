int F_1 ( void )
{
int V_1 ;
V_2 = F_2 () ;
if ( ! V_2 )
return - V_3 ;
V_2 -> V_4 = L_1 ;
V_2 -> V_5 . V_6 = V_7 ;
V_2 -> V_8 = L_2 ;
V_2 -> V_9 . V_10 = NULL ;
F_3 ( V_11 , V_2 -> V_12 ) ;
F_3 ( V_13 , V_2 -> V_14 ) ;
V_1 = F_4 ( V_2 ) ;
if ( V_1 ) {
F_5 ( V_2 ) ;
V_2 = NULL ;
}
return V_1 ;
}
void F_6 ( void )
{
if ( V_2 != NULL ) {
F_7 ( V_2 ) ;
V_2 = NULL ;
}
}
void F_8 ( void )
{
unsigned long V_15 ;
F_9 ( V_15 ) ;
F_10 () ;
F_11 ( V_16 , true ) ;
F_12 ( V_2 , V_13 , V_17 ) ;
F_12 ( V_2 , V_13 , V_18 ) ;
F_13 ( V_2 ) ;
F_11 ( V_16 , false ) ;
F_14 () ;
F_15 ( V_15 ) ;
}
bool F_16 ( void )
{
return F_17 ( V_16 ) ;
}
