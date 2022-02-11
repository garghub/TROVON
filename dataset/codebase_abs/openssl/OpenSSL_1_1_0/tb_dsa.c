void F_1 ( T_1 * V_1 )
{
F_2 ( & V_2 , V_1 ) ;
}
static void F_3 ( void )
{
F_4 ( & V_2 ) ;
}
int F_5 ( T_1 * V_1 )
{
if ( V_1 -> V_3 )
return F_6 ( & V_2 ,
F_3 , V_1 , & V_4 ,
1 , 0 ) ;
return 1 ;
}
void F_7 ()
{
T_1 * V_1 ;
for ( V_1 = F_8 () ; V_1 ; V_1 = F_9 ( V_1 ) )
F_5 ( V_1 ) ;
}
int F_10 ( T_1 * V_1 )
{
if ( V_1 -> V_3 )
return F_6 ( & V_2 ,
F_3 , V_1 , & V_4 ,
1 , 1 ) ;
return 1 ;
}
T_1 * F_11 ( void )
{
return F_12 ( & V_2 , V_4 ) ;
}
const T_2 * F_13 ( const T_1 * V_1 )
{
return V_1 -> V_3 ;
}
int F_14 ( T_1 * V_1 , const T_2 * V_3 )
{
V_1 -> V_3 = V_3 ;
return 1 ;
}
