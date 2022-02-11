static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 )
{
return F_2 ( V_1 , V_2 , V_3 , V_4 ) ;
}
static T_2 F_3 ( struct V_1 * V_1 ,
char T_3 * V_5 , T_4 V_6 , T_1 * V_7 )
{
unsigned char * V_8 ;
T_2 V_9 ;
int V_10 ;
if ( * V_7 < 0 || * V_7 >= V_4 )
return 0 ;
V_6 = * V_7 + V_6 < V_4 ? V_6 : V_4 - * V_7 ;
V_8 = F_4 ( V_6 , V_11 ) ;
if ( V_8 ) {
for ( V_10 = 0 ; V_10 < V_6 ; V_10 ++ )
V_8 [ V_10 ] = F_5 ( V_12 + ( * V_7 ) ++ ) ;
if ( F_6 ( V_5 , V_8 , V_6 ) )
V_9 = - V_13 ;
else
V_9 = V_6 ;
F_7 ( V_8 ) ;
} else
V_9 = - V_14 ;
return V_9 ;
}
static int F_8 ( struct V_15 * V_15 , struct V_1 * V_1 )
{
if ( V_1 -> V_16 & V_17 )
return - V_18 ;
return 0 ;
}
static int F_9 ( struct V_15 * V_15 , struct V_1 * V_1 )
{
return 0 ;
}
static int T_5 F_10 ( void )
{
int V_19 ;
if ( ! V_12 )
return - V_20 ;
V_19 = F_11 ( & V_21 ) ;
if ( V_19 < 0 ) {
F_12 ( V_22 L_1 ) ;
return V_19 ;
}
F_12 ( V_23 L_2 , V_12 ) ;
return 0 ;
}
