static int F_1 ( int V_1 )
{
int V_2 = 0 ;
V_3 ++ ;
if ( V_3 == 1 ) {
V_2 = F_2 ( V_1 , L_1 ) ;
if ( V_2 ) {
F_3 ( V_4 L_2 ) ;
return V_2 ;
}
V_2 = F_4 ( V_1 , 1 ) ;
if ( V_2 < 0 ) {
F_3 ( V_4 L_3 ,
V_5 ) ;
return V_2 ;
}
}
return V_2 ;
}
static int F_5 ( int V_1 )
{
int V_2 = 0 ;
if ( V_3 == 1 ) {
V_2 = F_4 ( V_1 , 0 ) ;
if ( V_2 < 0 ) {
F_3 ( V_4 L_3 ,
V_5 ) ;
return V_2 ;
}
F_6 ( V_1 , 0 ) ;
}
V_3 -- ;
return V_2 ;
}
static int F_7 ( void )
{
return F_8 ( V_6 ) ;
}
void T_1 F_9 ( void )
{
if ( F_10 () ) {
V_7 . V_8 = V_9 ;
V_10 . V_8 = V_9 ;
} else {
V_7 . V_8 = V_11 ;
V_10 . V_8 = V_11 ;
}
F_11 ( 0 , V_12 ,
F_12 ( V_12 ) ) ;
F_11 ( 3 , V_13 ,
F_12 ( V_13 ) ) ;
}
