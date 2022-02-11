struct V_1 * F_1 ( void )
{
return V_2 ;
}
bool F_2 ( struct V_1 * V_3 )
{
bool V_4 = false ;
F_3 ( & V_5 ) ;
if ( ! V_2 ) {
V_2 = V_3 ;
V_4 = true ;
} else
F_4 ( 1 , L_1 ,
V_2 -> V_6 ) ;
F_5 ( & V_5 ) ;
return V_4 ;
}
void F_6 ( struct V_1 * V_3 )
{
F_3 ( & V_5 ) ;
if ( V_2 == V_3 )
V_2 = NULL ;
else if ( V_2 )
F_4 ( 1 , L_2 ,
V_3 -> V_6 , V_2 -> V_6 ) ;
else
F_4 ( 1 , L_3 ) ;
F_5 ( & V_5 ) ;
}
bool F_7 ( void )
{
bool V_4 = false ;
F_3 ( & V_5 ) ;
if ( V_2 )
V_4 = F_8 ( V_2 -> V_7 ) ;
F_5 ( & V_5 ) ;
return V_4 ;
}
void F_9 ( void )
{
F_3 ( & V_5 ) ;
if ( V_2 )
F_10 ( V_2 -> V_7 ) ;
F_5 ( & V_5 ) ;
}
