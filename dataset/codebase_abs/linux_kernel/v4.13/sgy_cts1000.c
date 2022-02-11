static void F_1 ( struct V_1 * V_2 )
{
F_2 ( true ) ;
}
static void T_1 F_3 ( void )
{
enum V_3 V_4 ;
int V_5 , V_6 ;
if ( ! V_7 )
F_4 ( L_1 ) ;
V_6 = F_5 ( V_7 , 0 , & V_4 ) ;
if ( ! F_6 ( V_6 ) )
F_4 ( L_2 ) ;
V_5 = ( V_4 == V_8 ) ;
F_7 ( V_9 L_3 ) ;
F_8 ( V_6 , V_5 ) ;
F_4 ( L_4 ) ;
}
static T_2 F_9 ( int V_10 , void * V_11 )
{
F_7 ( V_9 L_5 ) ;
F_10 ( & V_12 ) ;
return V_13 ;
}
static int F_11 ( struct V_14 * V_15 )
{
enum V_3 V_4 ;
struct V_16 * V_17 = V_15 -> V_18 . V_19 ;
int V_6 , V_20 , V_10 ;
int V_5 ;
if ( ! V_17 )
return - V_21 ;
V_7 = F_12 ( V_17 , V_22 ) ;
if ( ! V_7 )
return 0 ;
if ( F_13 ( V_7 ) != 1 )
return - V_23 ;
V_6 = F_5 ( V_7 , 0 , & V_4 ) ;
if ( ! F_6 ( V_6 ) )
return - V_23 ;
V_20 = F_14 ( V_6 , L_6 ) ;
if ( V_20 ) {
F_7 ( V_24 L_7 ,
V_6 ) ;
V_7 = NULL ;
return V_20 ;
}
V_5 = ( V_4 == V_8 ) ;
F_15 ( V_6 , ! V_5 ) ;
V_10 = F_16 ( V_7 , 0 ) ;
V_20 = F_17 ( V_10 , F_9 , V_25 |
V_26 , L_6 , V_7 ) ;
if ( V_20 ) {
F_7 ( V_24 L_8
L_9 , V_10 , V_6 ) ;
F_18 ( V_6 ) ;
V_7 = NULL ;
return V_20 ;
}
V_27 . V_28 = F_3 ;
V_29 = F_3 ;
F_7 ( V_9 L_10
L_11 , V_6 , V_5 , V_10 ) ;
return 0 ;
}
static int F_19 ( struct V_14 * V_15 )
{
if ( V_7 ) {
int V_6 = F_20 ( V_7 , 0 ) ;
int V_10 = F_16 ( V_7 , 0 ) ;
F_21 ( V_10 , V_7 ) ;
V_27 . V_28 = NULL ;
V_29 = NULL ;
F_18 ( V_6 ) ;
V_7 = NULL ;
}
return 0 ;
}
