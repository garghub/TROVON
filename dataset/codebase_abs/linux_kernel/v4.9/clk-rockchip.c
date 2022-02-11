static void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const char * V_5 ;
const char * V_6 ;
void T_2 * V_7 ;
void T_2 * V_8 ;
int V_9 ;
int V_10 ;
int V_11 ;
int V_12 = V_13 ;
int V_14 ;
V_10 = F_2 ( V_2 , L_1 ) ;
if ( V_10 < 0 ) {
F_3 ( L_2 , V_15 , V_10 ) ;
return;
}
if ( V_10 == 0 ) {
F_4 ( L_3 , V_15 ) ;
return;
}
V_7 = F_5 ( V_2 , 0 ) ;
if ( ! V_7 )
return;
V_4 = F_6 ( sizeof( struct V_3 ) , V_16 ) ;
if ( ! V_4 ) {
F_7 ( V_7 ) ;
return;
}
V_4 -> V_17 = F_6 ( V_10 * sizeof( struct V_18 * ) , V_16 ) ;
if ( ! V_4 -> V_17 ) {
F_8 ( V_4 ) ;
F_7 ( V_7 ) ;
return;
}
V_9 = V_19 | V_20 ;
for ( V_14 = 0 ; V_14 < V_10 ; V_14 ++ ) {
F_9 ( V_2 , L_1 ,
V_14 , & V_6 ) ;
if ( ! strcmp ( L_4 , V_6 ) )
continue;
V_5 = F_10 ( V_2 , V_14 ) ;
V_12 |= V_21 ;
V_8 = V_7 + ( 4 * ( V_14 / 16 ) ) ;
V_11 = ( V_14 % 16 ) ;
V_4 -> V_17 [ V_14 ] = F_11 ( NULL , V_6 ,
V_5 , V_12 ,
V_8 , V_11 ,
V_9 ,
& V_22 ) ;
F_12 ( F_13 ( V_4 -> V_17 [ V_14 ] ) ) ;
}
V_4 -> V_23 = V_10 ;
F_14 ( V_2 , V_24 , V_4 ) ;
}
