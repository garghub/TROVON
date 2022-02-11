int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 , V_5 ;
if ( V_2 == NULL || V_2 -> V_6 == NULL || V_2 -> V_7 == NULL )
return - V_8 ;
if ( V_2 -> V_7 -> V_9 == NULL || V_2 -> V_7 -> V_10 == NULL )
return - V_8 ;
if ( V_2 -> V_11 > V_2 -> V_12 ) {
F_2 ( L_1 ) ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = 0 ;
}
F_3 ( & V_2 -> V_13 ) ;
V_4 = F_4 ( & V_14 , 0 , V_15 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_4 = V_4 ;
V_3 = F_5 ( V_2 ) ;
if ( V_3 ) {
F_6 ( & V_14 , V_4 ) ;
if ( ! ( V_4 == 0 && V_3 == - V_17 ) )
return V_3 ;
V_4 = F_4 ( & V_14 , 1 , V_15 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_4 = V_4 ;
V_3 = F_5 ( V_2 ) ;
if ( V_3 ) {
F_6 ( & V_14 , V_4 ) ;
return V_3 ;
}
}
V_5 = V_2 -> V_18 . V_19 ;
V_2 -> V_19 = F_7 ( V_20 , V_2 -> V_21 , V_5 ,
NULL , L_2 , V_2 -> V_4 ) ;
if ( F_8 ( V_2 -> V_19 ) ) {
F_9 ( V_2 ) ;
F_6 ( & V_14 , V_4 ) ;
V_3 = F_10 ( V_2 -> V_19 ) ;
return V_3 ;
}
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
int V_3 ;
int V_5 = V_2 -> V_18 . V_19 ;
if ( V_2 == NULL )
return;
V_3 = F_9 ( V_2 ) ;
if ( V_3 )
F_12 ( L_3 , V_3 ) ;
F_13 ( V_20 , V_5 ) ;
F_6 ( & V_14 , V_2 -> V_4 ) ;
V_2 -> V_19 = NULL ;
}
static int T_1 F_14 ( void )
{
int V_22 ;
V_20 = F_15 ( V_23 , L_4 ) ;
if ( F_8 ( V_20 ) ) {
F_12 ( L_5 ) ;
return F_10 ( V_20 ) ;
}
V_22 = F_16 () ;
if ( V_22 < 0 ) {
F_17 ( V_20 ) ;
return V_22 ;
}
return 0 ;
}
static void T_2 F_18 ( void )
{
F_19 () ;
F_17 ( V_20 ) ;
F_20 ( & V_14 ) ;
}
