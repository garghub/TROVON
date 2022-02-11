static int F_1 ( void T_1 * V_1 , T_2 V_2 )
{
unsigned long V_3 = 2000 ;
while ( V_3 -- ) {
if ( ! ( F_2 ( V_1 ) & V_2 ) )
return 0 ;
F_3 ( 1 ) ;
}
return - V_4 ;
}
static int F_4 ( struct V_5 * V_6 , T_2 V_7 )
{
int V_8 ;
void T_1 * V_1 = V_6 -> V_9 ;
F_5 ( V_10 | V_11 , V_1 ) ;
V_8 = F_1 ( V_1 , V_10 ) ;
if ( V_8 )
return V_8 ;
F_5 ( V_12 | V_13 | F_6 ( V_7 ) , V_1 ) ;
V_8 = F_1 ( V_1 , V_12 ) ;
if ( V_8 )
return V_8 ;
return F_7 ( F_2 ( V_1 ) ) ;
}
static int F_8 ( struct V_5 * V_6 , T_2 V_14 , T_2 V_7 )
{
int V_8 ;
void T_1 * V_1 = V_6 -> V_9 ;
F_5 ( V_10 | V_11 , V_1 ) ;
V_8 = F_1 ( V_1 , V_10 ) ;
if ( V_8 )
return V_8 ;
F_5 ( V_12 | V_11 | F_9 ( V_14 ) |
F_6 ( V_7 ) , V_1 ) ;
return F_1 ( V_1 , V_12 ) ;
}
