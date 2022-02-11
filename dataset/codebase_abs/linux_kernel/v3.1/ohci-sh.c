static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
F_4 ( V_4 ) ;
F_5 ( V_4 ) ;
V_2 -> V_5 = V_6 ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = NULL ;
struct V_1 * V_2 = NULL ;
int V_11 = - 1 ;
int V_12 ;
if ( F_7 () )
return - V_13 ;
V_10 = F_8 ( V_8 , V_14 , 0 ) ;
if ( ! V_10 ) {
F_9 ( L_1 ) ;
return - V_13 ;
}
V_11 = F_10 ( V_8 , 0 ) ;
if ( V_11 < 0 ) {
F_9 ( L_2 ) ;
return - V_13 ;
}
V_2 = F_11 ( & V_15 , & V_8 -> V_16 , ( char * ) V_17 ) ;
if ( ! V_2 ) {
F_9 ( L_3 ) ;
return - V_18 ;
}
V_2 -> V_19 = ( void V_20 * ) V_10 -> V_21 ;
V_2 -> V_22 = V_10 -> V_21 ;
V_2 -> V_23 = F_12 ( V_10 ) ;
V_12 = F_13 ( V_2 , V_11 , V_24 | V_25 ) ;
if ( V_12 != 0 ) {
F_9 ( L_4 ) ;
F_14 ( V_2 ) ;
return V_12 ;
}
return V_12 ;
}
static int F_15 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_16 ( V_8 ) ;
F_17 ( V_2 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
