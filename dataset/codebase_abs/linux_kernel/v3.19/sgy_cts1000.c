static void F_1 ( struct V_1 * V_2 )
{
F_2 ( true ) ;
}
static void F_3 ( void )
{
enum V_3 V_4 ;
int V_5 , V_6 ;
if ( ! V_7 )
return;
V_6 = F_4 ( V_7 , 0 , & V_4 ) ;
if ( ! F_5 ( V_6 ) )
return;
V_5 = ( V_4 == V_8 ) ;
F_6 ( V_9 L_1 ) ;
F_7 ( V_6 , V_5 ) ;
}
static T_1 F_8 ( int V_10 , void * V_11 )
{
F_6 ( V_9 L_2 ) ;
F_9 ( & V_12 ) ;
return V_13 ;
}
static int F_10 ( struct V_14 * V_15 )
{
enum V_3 V_4 ;
struct V_16 * V_17 = V_15 -> V_18 . V_19 ;
int V_6 , V_20 , V_10 ;
int V_5 ;
if ( ! V_17 )
return - V_21 ;
V_7 = F_11 ( V_17 , V_22 ) ;
if ( ! V_7 )
return 0 ;
if ( F_12 ( V_7 ) != 1 )
return - V_23 ;
V_6 = F_4 ( V_7 , 0 , & V_4 ) ;
if ( ! F_5 ( V_6 ) )
return - V_23 ;
V_20 = F_13 ( V_6 , L_3 ) ;
if ( V_20 ) {
F_6 ( V_24 L_4 ,
V_6 ) ;
V_7 = NULL ;
return V_20 ;
}
V_5 = ( V_4 == V_8 ) ;
F_14 ( V_6 , ! V_5 ) ;
V_10 = F_15 ( V_7 , 0 ) ;
V_20 = F_16 ( V_10 , F_8 , V_25 |
V_26 , L_3 , V_7 ) ;
if ( V_20 ) {
F_6 ( V_24 L_5
L_6 , V_10 , V_6 ) ;
F_17 ( V_6 ) ;
V_7 = NULL ;
return V_20 ;
}
V_27 . V_28 = F_3 ;
V_29 = F_3 ;
F_6 ( V_9 L_7
L_8 , V_6 , V_5 , V_10 ) ;
return 0 ;
}
static int F_18 ( struct V_14 * V_15 )
{
if ( V_7 ) {
int V_6 = F_19 ( V_7 , 0 ) ;
int V_10 = F_15 ( V_7 , 0 ) ;
F_20 ( V_10 , V_7 ) ;
V_27 . V_28 = NULL ;
V_29 = NULL ;
F_17 ( V_6 ) ;
V_7 = NULL ;
}
return 0 ;
}
