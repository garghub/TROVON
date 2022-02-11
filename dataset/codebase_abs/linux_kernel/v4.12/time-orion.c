static unsigned long T_1 F_1 ( void )
{
return ~ F_2 ( V_1 + V_2 ) ;
}
static void F_3 ( unsigned long V_3 )
{
V_4 . V_5 = V_3 ;
F_4 ( & V_4 ) ;
}
static T_2 T_1 F_5 ( void )
{
return ~ F_2 ( V_1 + V_2 ) ;
}
static int F_6 ( unsigned long V_6 ,
struct V_7 * V_8 )
{
F_7 ( V_6 , V_1 + V_9 ) ;
F_8 ( V_1 + V_10 ,
V_11 | V_12 , V_12 ) ;
return 0 ;
}
static int F_9 ( struct V_7 * V_8 )
{
F_8 ( V_1 + V_10 ,
V_11 | V_12 , 0 ) ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 )
{
F_7 ( V_13 - 1 , V_1 + V_14 ) ;
F_7 ( V_13 - 1 , V_1 + V_9 ) ;
F_8 ( V_1 + V_10 ,
V_11 | V_12 ,
V_11 | V_12 ) ;
return 0 ;
}
static T_3 F_11 ( int V_15 , void * V_16 )
{
V_17 . V_18 ( & V_17 ) ;
return V_19 ;
}
static int T_4 F_12 ( struct V_20 * V_21 )
{
unsigned long V_3 ;
struct V_22 * V_22 ;
int V_15 , V_23 ;
V_1 = F_13 ( V_21 , 0 ) ;
if ( ! V_1 ) {
F_14 ( L_1 , V_21 -> V_24 ) ;
return - V_25 ;
}
V_22 = F_15 ( V_21 , 0 ) ;
if ( F_16 ( V_22 ) ) {
F_14 ( L_2 , V_21 -> V_24 ) ;
return F_17 ( V_22 ) ;
}
V_23 = F_18 ( V_22 ) ;
if ( V_23 ) {
F_14 ( L_3 ) ;
return V_23 ;
}
V_15 = F_19 ( V_21 , 1 ) ;
if ( V_15 <= 0 ) {
F_14 ( L_4 , V_21 -> V_24 ) ;
return - V_26 ;
}
V_3 = F_20 ( V_22 ) ;
F_7 ( ~ 0 , V_1 + V_2 ) ;
F_7 ( ~ 0 , V_1 + V_27 ) ;
F_8 ( V_1 + V_10 ,
V_28 | V_29 ,
V_28 | V_29 ) ;
V_23 = F_21 ( V_1 + V_2 ,
L_5 , V_3 , 300 , 32 ,
V_30 ) ;
if ( V_23 ) {
F_14 ( L_6 ) ;
return V_23 ;
}
F_22 ( F_5 , 32 , V_3 ) ;
V_23 = F_23 ( V_15 , & V_31 ) ;
if ( V_23 ) {
F_14 ( L_7 , V_21 -> V_24 ) ;
return V_23 ;
}
V_13 = ( F_20 ( V_22 ) + V_32 / 2 ) / V_32 ;
V_17 . V_33 = F_24 ( 0 ) ;
V_17 . V_15 = V_15 ;
F_25 ( & V_17 , V_3 ,
V_34 , V_35 ) ;
F_3 ( V_3 ) ;
return 0 ;
}
