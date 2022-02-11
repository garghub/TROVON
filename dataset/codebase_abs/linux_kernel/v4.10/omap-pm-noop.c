int F_1 ( struct V_1 * V_2 , long V_3 )
{
if ( ! V_2 || V_3 < - 1 ) {
F_2 ( 1 , L_1 , V_4 ) ;
return - V_5 ;
}
if ( V_3 == - 1 )
F_3 ( L_2 ,
F_4 ( V_2 ) ) ;
else
F_3 ( L_3 ,
F_4 ( V_2 ) , V_3 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , T_1 V_6 , unsigned long V_7 )
{
if ( ! V_2 || ( V_6 != V_8 &&
V_6 != V_9 ) ) {
F_2 ( 1 , L_1 , V_4 ) ;
return - V_5 ;
}
if ( V_7 == 0 )
F_3 ( L_4 ,
F_4 ( V_2 ) , V_6 ) ;
else
F_3 ( L_5 ,
F_4 ( V_2 ) , V_6 , V_7 ) ;
return 0 ;
}
void F_6 ( void )
{
V_10 = true ;
}
void F_7 ( void )
{
V_10 = false ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_9 ( V_2 ) ;
int V_13 ;
if ( F_10 ( ! V_2 ) )
return - V_14 ;
if ( V_2 -> V_15 == & V_16 ) {
V_13 = F_11 ( V_12 ) ;
} else {
F_12 ( V_10 , L_6 ,
F_4 ( V_2 ) ) ;
V_13 = V_17 ;
if ( V_10 ) {
V_13 ++ ;
V_13 &= V_18 ;
V_17 = V_13 ;
}
}
F_3 ( L_7 ,
F_4 ( V_2 ) , V_13 ) ;
return V_13 ;
}
int F_8 ( struct V_1 * V_2 )
{
return V_17 ;
}
int T_2 F_13 ( void )
{
return 0 ;
}
int T_2 F_14 ( void )
{
return 0 ;
}
