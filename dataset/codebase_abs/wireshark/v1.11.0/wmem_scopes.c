T_1 *
F_1 ( void )
{
F_2 ( V_1 ) ;
return V_1 ;
}
void
F_3 ( void )
{
F_2 ( V_1 ) ;
F_2 ( V_2 -> V_3 ) ;
F_2 ( ! V_1 -> V_3 ) ;
V_1 -> V_3 = TRUE ;
}
void
F_4 ( void )
{
F_2 ( V_1 ) ;
F_2 ( V_1 -> V_3 ) ;
F_5 ( V_1 ) ;
V_1 -> V_3 = FALSE ;
}
T_1 *
F_6 ( void )
{
F_2 ( V_2 ) ;
return V_2 ;
}
void
F_7 ( void )
{
F_2 ( V_2 ) ;
F_2 ( ! V_2 -> V_3 ) ;
V_2 -> V_3 = TRUE ;
}
void
F_8 ( void )
{
F_2 ( V_2 ) ;
F_2 ( V_2 -> V_3 ) ;
F_2 ( ! V_1 -> V_3 ) ;
F_5 ( V_2 ) ;
V_2 -> V_3 = FALSE ;
F_9 ( V_2 ) ;
F_9 ( V_1 ) ;
}
T_1 *
F_10 ( void )
{
F_2 ( V_4 ) ;
return V_4 ;
}
void
F_11 ( void )
{
F_2 ( V_1 == NULL ) ;
F_2 ( V_2 == NULL ) ;
F_2 ( V_4 == NULL ) ;
V_1 = F_12 ( V_5 ) ;
V_2 = F_12 ( V_5 ) ;
V_4 = F_12 ( V_6 ) ;
V_1 -> V_3 = FALSE ;
V_2 -> V_3 = FALSE ;
}
void
F_13 ( void )
{
F_2 ( V_1 ) ;
F_2 ( V_2 ) ;
F_2 ( V_4 ) ;
F_2 ( V_1 -> V_3 == FALSE ) ;
F_2 ( V_2 -> V_3 == FALSE ) ;
F_14 ( V_1 ) ;
F_14 ( V_2 ) ;
F_14 ( V_4 ) ;
V_1 = NULL ;
V_2 = NULL ;
V_4 = NULL ;
}
