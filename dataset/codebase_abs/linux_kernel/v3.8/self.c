static int F_1 ( struct V_1 * V_1 , char T_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 -> V_7 ;
T_2 V_8 = F_2 ( V_9 , V_5 ) ;
char V_10 [ V_11 ] ;
if ( ! V_8 )
return - V_12 ;
sprintf ( V_10 , L_1 , V_8 ) ;
return F_3 ( V_1 , V_2 , V_3 , V_10 ) ;
}
static void * F_4 ( struct V_1 * V_1 , struct V_13 * V_14 )
{
struct V_4 * V_5 = V_1 -> V_6 -> V_7 ;
T_2 V_8 = F_2 ( V_9 , V_5 ) ;
char * V_15 = F_5 ( - V_12 ) ;
if ( V_8 ) {
V_15 = F_6 ( 12 , V_16 ) ;
if ( ! V_15 )
V_15 = F_5 ( - V_17 ) ;
else
sprintf ( V_15 , L_1 , V_8 ) ;
}
F_7 ( V_14 , V_15 ) ;
return NULL ;
}
static void F_8 ( struct V_1 * V_1 , struct V_13 * V_14 ,
void * V_18 )
{
char * V_19 = F_9 ( V_14 ) ;
if ( ! F_10 ( V_19 ) )
F_11 ( V_19 ) ;
}
void T_3 F_12 ( void )
{
struct V_20 * V_21 ;
T_4 V_22 ;
V_22 = V_23 | V_24 ;
V_21 = F_13 ( L_2 , V_22 , NULL , NULL ) ;
V_21 -> V_25 = & V_26 ;
}
