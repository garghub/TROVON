static T_1 T_2 F_1 ( void )
{
return ~ F_2 ( V_1 + V_2 ) ;
}
static int F_3 ( unsigned long V_3 ,
struct V_4 * V_5 )
{
F_4 ( V_3 , V_1 + V_6 ) ;
F_5 ( V_1 + V_7 ,
V_8 | V_9 , V_9 ) ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 )
{
F_5 ( V_1 + V_7 ,
V_8 | V_9 , 0 ) ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 )
{
F_4 ( V_10 - 1 , V_1 + V_11 ) ;
F_4 ( V_10 - 1 , V_1 + V_6 ) ;
F_5 ( V_1 + V_7 ,
V_8 | V_9 ,
V_8 | V_9 ) ;
return 0 ;
}
static T_3 F_8 ( int V_12 , void * V_13 )
{
V_14 . V_15 ( & V_14 ) ;
return V_16 ;
}
static int T_4 F_9 ( struct V_17 * V_18 )
{
struct V_19 * V_19 ;
int V_12 , V_20 ;
V_1 = F_10 ( V_18 , 0 ) ;
if ( ! V_1 ) {
F_11 ( L_1 , V_18 -> V_21 ) ;
return - V_22 ;
}
V_19 = F_12 ( V_18 , 0 ) ;
if ( F_13 ( V_19 ) ) {
F_11 ( L_2 , V_18 -> V_21 ) ;
return F_14 ( V_19 ) ;
}
V_20 = F_15 ( V_19 ) ;
if ( V_20 ) {
F_11 ( L_3 ) ;
return V_20 ;
}
V_12 = F_16 ( V_18 , 1 ) ;
if ( V_12 <= 0 ) {
F_11 ( L_4 , V_18 -> V_21 ) ;
return - V_23 ;
}
F_4 ( ~ 0 , V_1 + V_2 ) ;
F_4 ( ~ 0 , V_1 + V_24 ) ;
F_5 ( V_1 + V_7 ,
V_25 | V_26 ,
V_25 | V_26 ) ;
V_20 = F_17 ( V_1 + V_2 , L_5 ,
F_18 ( V_19 ) , 300 , 32 ,
V_27 ) ;
if ( V_20 ) {
F_11 ( L_6 ) ;
return V_20 ;
}
F_19 ( F_1 , 32 , F_18 ( V_19 ) ) ;
V_20 = F_20 ( V_12 , & V_28 ) ;
if ( V_20 ) {
F_11 ( L_7 , V_18 -> V_21 ) ;
return V_20 ;
}
V_10 = ( F_18 ( V_19 ) + V_29 / 2 ) / V_29 ;
V_14 . V_30 = F_21 ( 0 ) ;
V_14 . V_12 = V_12 ;
F_22 ( & V_14 , F_18 ( V_19 ) ,
V_31 , V_32 ) ;
return 0 ;
}
