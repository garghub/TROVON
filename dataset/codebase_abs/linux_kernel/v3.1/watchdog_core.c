int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 == NULL || V_2 -> V_4 == NULL || V_2 -> V_5 == NULL )
return - V_6 ;
if ( V_2 -> V_5 -> V_7 == NULL || V_2 -> V_5 -> V_8 == NULL )
return - V_6 ;
if ( V_2 -> V_9 > V_2 -> V_10 ) {
F_2 ( L_1 ) ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
}
V_3 = F_3 ( V_2 ) ;
if ( V_3 ) {
F_4 ( L_2 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 == NULL )
return;
V_3 = F_6 ( V_2 ) ;
if ( V_3 )
F_4 ( L_3 , V_3 ) ;
}
