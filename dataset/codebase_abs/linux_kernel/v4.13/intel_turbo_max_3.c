static int F_1 ( unsigned int V_1 )
{
T_1 V_2 , V_3 = V_4 ;
int V_5 , V_6 ;
V_2 = V_3 << V_7 ;
V_2 |= F_2 ( V_8 ) ;
V_5 = F_3 ( V_9 , V_2 ) ;
if ( V_5 ) {
F_4 ( L_1 , V_1 ) ;
return V_5 ;
}
for ( V_6 = 0 ; V_6 < V_10 ; ++ V_6 ) {
V_5 = F_5 ( V_9 , & V_2 ) ;
if ( V_5 ) {
F_4 ( L_2 , V_1 ) ;
break;
}
if ( V_2 & F_2 ( V_8 ) ) {
F_4 ( L_3 , V_1 ) ;
V_5 = - V_11 ;
continue;
}
if ( ( V_2 >> V_12 ) & 0xff ) {
F_4 ( L_4 , V_1 ) ;
V_5 = - V_13 ;
break;
}
V_5 = V_2 & 0xff ;
F_4 ( L_5 , V_1 , V_5 ) ;
break;
}
return V_5 ;
}
static void F_6 ( struct V_14 * V_15 )
{
F_7 () ;
}
static int F_8 ( unsigned int V_1 )
{
static T_2 V_16 = 0 , V_17 = V_18 ;
int V_19 ;
V_19 = F_1 ( V_1 ) ;
if ( V_19 < 0 )
return 0 ;
F_9 ( V_19 , V_1 ) ;
if ( V_16 <= V_17 ) {
if ( V_19 > V_16 )
V_16 = V_19 ;
if ( V_19 < V_17 )
V_17 = V_19 ;
if ( V_16 > V_17 )
F_10 ( & V_20 ) ;
}
return 0 ;
}
static int T_3 F_11 ( void )
{
const struct V_21 * V_22 ;
int V_5 ;
V_22 = F_12 ( V_23 ) ;
if ( ! V_22 )
return - V_24 ;
if ( F_13 ( V_25 ) )
return - V_24 ;
V_5 = F_14 ( V_26 ,
L_6 ,
F_8 , NULL ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
