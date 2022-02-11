static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
F_4 ( V_4 ) ;
F_5 ( V_4 ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = NULL ;
struct V_1 * V_2 = NULL ;
int V_9 = - 1 ;
int V_10 ;
if ( F_7 () )
return - V_11 ;
V_8 = F_8 ( V_6 , V_12 , 0 ) ;
if ( ! V_8 ) {
F_9 ( L_1 ) ;
return - V_11 ;
}
V_9 = F_10 ( V_6 , 0 ) ;
if ( V_9 < 0 ) {
F_9 ( L_2 ) ;
return - V_11 ;
}
V_2 = F_11 ( & V_13 , & V_6 -> V_14 , ( char * ) V_15 ) ;
if ( ! V_2 ) {
F_9 ( L_3 ) ;
return - V_16 ;
}
V_2 -> V_17 = ( void V_18 * ) V_8 -> V_19 ;
V_2 -> V_20 = V_8 -> V_19 ;
V_2 -> V_21 = F_12 ( V_8 ) ;
V_10 = F_13 ( V_2 , V_9 , V_22 ) ;
if ( V_10 != 0 ) {
F_9 ( L_4 ) ;
F_14 ( V_2 ) ;
return V_10 ;
}
return V_10 ;
}
static int F_15 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_16 ( V_6 ) ;
F_17 ( V_2 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
