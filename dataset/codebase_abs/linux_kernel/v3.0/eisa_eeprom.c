static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 )
{
switch ( V_3 ) {
case 0 :
break;
case 1 :
V_2 += V_1 -> V_4 ;
break;
case 2 :
V_2 += V_5 ;
break;
}
return ( V_2 >= 0 && V_2 < V_5 ) ? ( V_1 -> V_4 = V_2 ) : - V_6 ;
}
static T_2 F_2 ( struct V_1 * V_1 ,
char T_3 * V_7 , T_4 V_8 , T_1 * V_9 )
{
unsigned char * V_10 ;
T_2 V_11 ;
int V_12 ;
if ( * V_9 < 0 || * V_9 >= V_5 )
return 0 ;
V_8 = * V_9 + V_8 < V_5 ? V_8 : V_5 - * V_9 ;
V_10 = F_3 ( V_8 , V_13 ) ;
if ( V_10 ) {
for ( V_12 = 0 ; V_12 < V_8 ; V_12 ++ )
V_10 [ V_12 ] = F_4 ( V_14 + ( * V_9 ) ++ ) ;
if ( F_5 ( V_7 , V_10 , V_8 ) )
V_11 = - V_15 ;
else
V_11 = V_8 ;
F_6 ( V_10 ) ;
} else
V_11 = - V_16 ;
return V_11 ;
}
static int F_7 ( struct V_17 * V_17 , struct V_1 * V_1 )
{
if ( V_1 -> V_18 & V_19 )
return - V_6 ;
return 0 ;
}
static int F_8 ( struct V_17 * V_17 , struct V_1 * V_1 )
{
return 0 ;
}
static int T_5 F_9 ( void )
{
int V_20 ;
if ( ! V_14 )
return - V_21 ;
V_20 = F_10 ( & V_22 ) ;
if ( V_20 < 0 ) {
F_11 ( V_23 L_1 ) ;
return V_20 ;
}
F_11 ( V_24 L_2 , V_14 ) ;
return 0 ;
}
