static void F_1 ( unsigned long V_1 )
{
int V_2 ;
V_2 = F_2 ( 0 , 0 , V_3 ) ;
if ( V_2 != 0 ) {
F_3 ( L_1 , V_2 ) ;
return;
}
F_4 ( V_4 ) ;
V_5 = 1 ;
}
static int F_5 ( void * V_6 , unsigned int V_7 )
{
T_1 V_2 ;
T_1 V_8 ;
F_6 ( & V_9 ) ;
if ( V_5 ) {
F_7 ( V_4 ) ;
V_2 = F_2 ( 0 , 0 , V_10 ) ;
if ( V_2 != 0 ) {
F_4 ( V_4 ) ;
F_3 ( L_2 , V_2 ) ;
return - V_11 ;
}
V_5 = 0 ;
}
V_8 = F_8 ( V_6 ) ;
V_2 = F_2 ( V_8 , V_7 , V_12 ) ;
F_9 ( & V_9 , V_13 + F_10 ( 500 ) ) ;
if ( V_2 != 0 )
return - V_14 ;
return 0 ;
}
static int F_11 ( struct V_15 * V_16 , int V_17 )
{
return 1 ;
}
static int F_12 ( struct V_15 * V_16 , T_1 * V_1 )
{
int V_2 ;
V_2 = F_5 ( V_1 , 4 ) ;
if ( V_2 < 0 )
return V_2 ;
return 4 ;
}
static int F_13 ( struct V_18 * V_19 )
{
F_14 ( L_3 ) ;
F_2 = V_19 -> V_20 . V_21 ;
if ( ! F_2 ) {
F_3 ( L_4 ) ;
return - V_14 ;
}
F_15 ( & V_9 , F_1 , 0 ) ;
V_4 = F_16 ( & V_19 -> V_20 , L_5 ) ;
if ( F_17 ( V_4 ) ) {
F_3 ( L_6 ) ;
return F_18 ( V_4 ) ;
}
F_7 ( V_4 ) ;
F_1 ( 0 ) ;
return F_19 ( & V_22 ) ;
}
static int F_20 ( struct V_18 * V_19 )
{
F_21 ( & V_22 ) ;
F_4 ( V_4 ) ;
F_22 ( V_4 ) ;
return 0 ;
}
