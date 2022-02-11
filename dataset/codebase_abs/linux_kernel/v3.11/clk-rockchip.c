static void T_1 F_1 ( struct V_1 * V_2 ,
void * V_3 )
{
struct V_4 * V_5 ;
const char * V_6 ;
const char * V_7 ;
void T_2 * V_8 ;
void T_2 * V_9 ;
int V_10 ;
int V_11 ;
int V_12 ;
int V_13 = V_14 ;
int V_15 ;
V_11 = F_2 ( V_2 , L_1 ) ;
if ( V_11 < 0 ) {
F_3 ( L_2 , V_16 , V_11 ) ;
return;
}
if ( V_11 == 0 ) {
F_4 ( L_3 , V_16 ) ;
return;
}
V_8 = F_5 ( V_2 , 0 ) ;
V_5 = F_6 ( sizeof( struct V_4 ) , V_17 ) ;
if ( ! V_5 )
return;
V_5 -> V_18 = F_6 ( V_11 * sizeof( struct V_19 * ) , V_17 ) ;
if ( ! V_5 -> V_18 ) {
F_7 ( V_5 ) ;
return;
}
V_10 = V_20 | V_21 ;
for ( V_15 = 0 ; V_15 < V_11 ; V_15 ++ ) {
F_8 ( V_2 , L_1 ,
V_15 , & V_7 ) ;
if ( ! strcmp ( L_4 , V_7 ) )
continue;
V_6 = F_9 ( V_2 , V_15 ) ;
V_13 |= V_22 ;
V_9 = V_8 + ( 4 * ( V_15 / 16 ) ) ;
V_12 = ( V_15 % 16 ) ;
V_5 -> V_18 [ V_15 ] = F_10 ( NULL , V_7 ,
V_6 , V_13 ,
V_9 , V_12 ,
V_10 ,
& V_23 ) ;
F_11 ( F_12 ( V_5 -> V_18 [ V_15 ] ) ) ;
}
V_5 -> V_24 = V_11 ;
F_13 ( V_2 , V_25 , V_5 ) ;
}
