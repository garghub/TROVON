static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( 0 , 0 , V_4 ) ;
if ( V_3 != 0 ) {
F_3 ( L_1 , V_3 ) ;
return;
}
F_4 ( V_5 ) ;
V_6 = 1 ;
}
static int F_5 ( void * V_7 , unsigned int V_8 )
{
T_1 V_3 ;
T_1 V_9 ;
F_6 ( & V_10 ) ;
if ( V_6 ) {
F_7 ( V_5 ) ;
V_3 = F_2 ( 0 , 0 , V_11 ) ;
if ( V_3 != 0 ) {
F_4 ( V_5 ) ;
F_3 ( L_2 , V_3 ) ;
return - V_12 ;
}
V_6 = 0 ;
}
V_9 = F_8 ( V_7 ) ;
V_3 = F_2 ( V_9 , V_8 , V_13 ) ;
F_9 ( & V_10 , F_10 ( 500 ) ) ;
if ( V_3 != 0 )
return - V_14 ;
return 0 ;
}
static int F_11 ( struct V_15 * V_16 , int V_17 )
{
return 1 ;
}
static int F_12 ( struct V_15 * V_16 , T_1 * V_18 )
{
int V_3 ;
V_3 = F_5 ( V_18 , 4 ) ;
if ( V_3 < 0 )
return V_3 ;
return 4 ;
}
static int F_13 ( struct V_19 * V_20 )
{
F_14 ( L_3 ) ;
F_2 = V_20 -> V_21 . V_22 ;
if ( ! F_2 ) {
F_3 ( L_4 ) ;
return - V_14 ;
}
F_15 ( & V_10 , F_1 ) ;
V_5 = F_16 ( & V_20 -> V_21 , L_5 ) ;
if ( F_17 ( V_5 ) ) {
F_3 ( L_6 ) ;
return F_18 ( V_5 ) ;
}
F_7 ( V_5 ) ;
F_1 ( 0 ) ;
return F_19 ( & V_23 ) ;
}
static int F_20 ( struct V_19 * V_20 )
{
F_6 ( & V_10 ) ;
F_21 ( & V_23 ) ;
F_4 ( V_5 ) ;
return 0 ;
}
