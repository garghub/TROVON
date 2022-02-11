static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 V_4 ;
int V_5 , V_6 ;
if ( ! F_2 ( L_1 ) )
return 0 ;
V_2 = F_3 ( NULL , NULL , L_2 ) ;
if ( ! V_2 )
return 0 ;
V_5 = F_4 ( V_2 , 1 , & V_4 ) ;
if ( V_5 ) {
F_5 ( V_7 L_3 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
F_6 ( V_2 ) ;
F_7 (cpu) {
struct V_8 * V_9 ;
struct V_10 * V_10 ;
int V_5 ;
V_9 = F_8 ( V_6 ) ;
if ( ! V_9 ) {
F_9 ( L_4 , V_6 ) ;
continue;
}
V_10 = F_10 ( V_9 , NULL ) ;
if ( F_11 ( V_10 ) ) {
F_9 ( L_5 , V_6 ) ;
return F_12 ( V_10 ) ;
}
V_5 = F_13 ( V_9 , F_14 ( V_10 ) , 0 ) ;
if ( V_5 ) {
F_15 ( V_10 ) ;
return V_5 ;
}
V_5 = F_13 ( V_9 , F_14 ( V_10 ) / 2 , 0 ) ;
if ( V_5 ) {
F_15 ( V_10 ) ;
return V_5 ;
}
V_5 = F_16 ( V_9 ,
F_17 ( V_9 -> V_11 ) ) ;
if ( V_5 )
F_18 ( V_9 , L_6 ,
V_12 , V_5 ) ;
}
F_19 ( L_7 , - 1 , NULL , 0 ) ;
return 0 ;
}
