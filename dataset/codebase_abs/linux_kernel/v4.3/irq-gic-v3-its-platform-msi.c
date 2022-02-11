static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , T_1 * V_6 )
{
struct V_7 * V_8 ;
T_2 V_9 ;
int V_10 ;
V_8 = F_2 ( V_2 -> V_11 ) ;
V_10 = F_3 ( V_4 -> V_12 , L_1 ,
1 , & V_9 ) ;
if ( V_10 )
return V_10 ;
V_6 -> V_13 [ 0 ] . V_14 = V_9 ;
return V_8 -> V_15 -> V_16 ( V_2 -> V_11 ,
V_4 , V_5 , V_6 ) ;
}
static int T_3 F_4 ( void )
{
struct V_17 * V_18 ;
struct V_1 * V_11 ;
for ( V_18 = F_5 ( NULL , V_19 ) ; V_18 ;
V_18 = F_5 ( V_18 , V_19 ) ) {
if ( ! F_6 ( V_18 , L_2 ) )
continue;
V_11 = F_7 ( V_18 , V_20 ) ;
if ( ! V_11 || ! F_2 ( V_11 ) ) {
F_8 ( L_3 ,
V_18 -> V_21 ) ;
continue;
}
if ( ! F_9 ( V_18 , & V_22 ,
V_11 ) ) {
F_8 ( L_4 ,
V_18 -> V_21 ) ;
continue;
}
F_10 ( L_5 , V_18 -> V_21 ) ;
}
return 0 ;
}
