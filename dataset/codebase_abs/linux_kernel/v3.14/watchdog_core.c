static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 > V_2 -> V_4 ) {
F_2 ( L_1 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
}
}
int F_3 ( struct V_1 * V_2 ,
unsigned int V_5 , struct V_6 * V_7 )
{
unsigned int V_8 = 0 ;
int V_9 = 0 ;
F_1 ( V_2 ) ;
if ( ! F_4 ( V_2 , V_5 ) && V_5 ) {
V_2 -> V_10 = V_5 ;
return V_9 ;
}
if ( V_5 )
V_9 = - V_11 ;
if ( V_7 == NULL || V_7 -> V_12 == NULL )
return V_9 ;
F_5 ( V_7 -> V_12 , L_2 , & V_8 ) ;
if ( ! F_4 ( V_2 , V_8 ) && V_8 )
V_2 -> V_10 = V_8 ;
else
V_9 = - V_11 ;
return V_9 ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_9 , V_13 , V_14 ;
if ( V_2 == NULL || V_2 -> V_15 == NULL || V_2 -> V_16 == NULL )
return - V_11 ;
if ( V_2 -> V_16 -> V_17 == NULL || V_2 -> V_16 -> V_18 == NULL )
return - V_11 ;
F_1 ( V_2 ) ;
F_7 ( & V_2 -> V_19 ) ;
V_13 = F_8 ( & V_20 , 0 , V_21 , V_22 ) ;
if ( V_13 < 0 )
return V_13 ;
V_2 -> V_13 = V_13 ;
V_9 = F_9 ( V_2 ) ;
if ( V_9 ) {
F_10 ( & V_20 , V_13 ) ;
if ( ! ( V_13 == 0 && V_9 == - V_23 ) )
return V_9 ;
V_13 = F_8 ( & V_20 , 1 , V_21 , V_22 ) ;
if ( V_13 < 0 )
return V_13 ;
V_2 -> V_13 = V_13 ;
V_9 = F_9 ( V_2 ) ;
if ( V_9 ) {
F_10 ( & V_20 , V_13 ) ;
return V_9 ;
}
}
V_14 = V_2 -> V_24 . V_7 ;
V_2 -> V_7 = F_11 ( V_25 , V_2 -> V_26 , V_14 ,
NULL , L_3 , V_2 -> V_13 ) ;
if ( F_12 ( V_2 -> V_7 ) ) {
F_13 ( V_2 ) ;
F_10 ( & V_20 , V_13 ) ;
V_9 = F_14 ( V_2 -> V_7 ) ;
return V_9 ;
}
return 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
int V_9 ;
int V_14 ;
if ( V_2 == NULL )
return;
V_14 = V_2 -> V_24 . V_7 ;
V_9 = F_13 ( V_2 ) ;
if ( V_9 )
F_16 ( L_4 , V_9 ) ;
F_17 ( V_25 , V_14 ) ;
F_10 ( & V_20 , V_2 -> V_13 ) ;
V_2 -> V_7 = NULL ;
}
static int T_1 F_18 ( void )
{
int V_27 ;
V_25 = F_19 ( V_28 , L_5 ) ;
if ( F_12 ( V_25 ) ) {
F_16 ( L_6 ) ;
return F_14 ( V_25 ) ;
}
V_27 = F_20 () ;
if ( V_27 < 0 ) {
F_21 ( V_25 ) ;
return V_27 ;
}
return 0 ;
}
static void T_2 F_22 ( void )
{
F_23 () ;
F_21 ( V_25 ) ;
F_24 ( & V_20 ) ;
}
