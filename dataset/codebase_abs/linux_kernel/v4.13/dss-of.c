struct V_1 * F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
int V_4 ;
if ( ! V_2 )
return NULL ;
V_3 = F_2 ( V_2 ) ;
for ( V_4 = 0 ; V_4 < 2 && V_3 ; ++ V_4 ) {
struct V_5 * V_6 ;
V_6 = F_3 ( V_3 , L_1 , NULL ) ;
if ( V_6 )
return V_3 ;
V_3 = F_4 ( V_3 ) ;
}
return NULL ;
}
T_1 F_5 ( struct V_1 * V_2 )
{
int V_7 ;
T_1 V_8 ;
V_7 = F_6 ( V_2 , L_2 , & V_8 ) ;
if ( V_7 )
V_8 = 0 ;
return V_8 ;
}
struct V_9 *
F_7 ( struct V_1 * V_10 )
{
struct V_1 * V_11 ;
struct V_1 * V_12 ;
struct V_9 * V_13 ;
V_11 = F_8 ( V_10 , 0 , 0 ) ;
if ( ! V_11 )
return F_9 ( - V_14 ) ;
V_12 = F_10 ( V_11 ) ;
if ( ! V_12 ) {
F_11 ( V_11 ) ;
return F_9 ( - V_14 ) ;
}
F_11 ( V_11 ) ;
V_13 = F_12 ( V_12 ) ;
F_11 ( V_12 ) ;
return V_13 ? V_13 : F_9 ( - V_15 ) ;
}
