STATIC int
F_1 (
struct V_1 * V_2 ,
int V_3 ,
void T_1 * V_4 ,
T_2 * V_5 ,
T_3 * V_6 )
{
int V_7 , * V_8 = V_2 -> V_9 ;
V_7 = F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( ! V_7 && V_3 && * V_8 ) {
F_3 ( V_10 . V_11 ) ;
V_12 = 0 ;
}
return V_7 ;
}
STATIC int
F_4 (
struct V_1 * V_2 ,
int V_3 ,
void T_1 * V_4 ,
T_2 * V_5 ,
T_3 * V_6 )
{
int V_7 , * V_8 = V_2 -> V_9 ;
V_7 = F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( ! V_7 && V_3 ) {
V_13 = * V_8 ;
#ifdef F_5
V_13 |= ( V_14 | V_15 ) ;
#endif
}
return V_7 ;
}
int
F_6 ( void )
{
V_16 = F_7 ( V_17 ) ;
if ( ! V_16 )
return - V_18 ;
return 0 ;
}
void
F_8 ( void )
{
F_9 ( V_16 ) ;
}
