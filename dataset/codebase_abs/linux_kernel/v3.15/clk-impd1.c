void F_1 ( void T_1 * V_1 , unsigned int V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_5 ;
int V_6 ;
if ( V_2 > 3 ) {
F_2 ( L_1 ) ;
return;
}
V_4 = & V_7 [ V_2 ] ;
V_4 -> V_8 = F_3 ( V_9 , L_2 , V_2 ) ;
V_5 = F_4 ( NULL , & V_10 , V_4 -> V_8 , NULL ,
V_1 ) ;
V_4 -> V_11 = V_5 ;
V_4 -> V_12 [ 0 ] = F_5 ( V_5 , NULL , L_3 , V_2 ) ;
V_4 -> V_13 = F_3 ( V_9 , L_4 , V_2 ) ;
V_5 = F_4 ( NULL , & V_14 , V_4 -> V_13 , NULL ,
V_1 ) ;
V_4 -> V_15 = V_5 ;
V_4 -> V_12 [ 1 ] = F_5 ( V_5 , NULL , L_5 , V_2 ) ;
V_4 -> V_16 = F_3 ( V_9 , L_6 , V_2 ) ;
V_5 = F_6 ( NULL , V_4 -> V_16 , V_4 -> V_13 ,
V_17 , 1 , 4 ) ;
V_4 -> V_18 = V_5 ;
V_4 -> V_12 [ 2 ] = F_5 ( V_5 , NULL , L_7 , V_2 ) ;
V_4 -> V_12 [ 3 ] = F_5 ( V_5 , NULL , L_8 , V_2 ) ;
V_4 -> V_19 = F_3 ( V_9 , L_9 , V_2 ) ;
V_5 = F_6 ( NULL , V_4 -> V_19 , V_4 -> V_13 ,
V_17 , 1 , 64 ) ;
V_4 -> V_12 [ 4 ] = F_5 ( V_5 , NULL , L_10 , V_2 ) ;
V_4 -> V_20 = F_3 ( V_9 , L_11 , V_2 ) ;
V_5 = F_6 ( NULL , V_4 -> V_20 , V_4 -> V_13 ,
V_17 , 1 , 4 ) ;
V_4 -> V_21 = V_5 ;
V_4 -> V_12 [ 5 ] = F_5 ( V_5 , NULL , L_12 , V_2 ) ;
for ( V_6 = 0 ; V_6 < F_7 ( V_4 -> V_12 ) ; V_6 ++ )
F_8 ( V_4 -> V_12 [ V_6 ] ) ;
}
void F_9 ( unsigned int V_2 )
{
int V_6 ;
struct V_3 * V_4 ;
if ( V_2 > 3 )
return;
V_4 = & V_7 [ V_2 ] ;
for ( V_6 = 0 ; V_6 < F_7 ( V_4 -> V_12 ) ; V_6 ++ )
F_10 ( V_4 -> V_12 [ V_6 ] ) ;
F_11 ( V_4 -> V_22 ) ;
F_11 ( V_4 -> V_18 ) ;
F_11 ( V_4 -> V_15 ) ;
F_11 ( V_4 -> V_11 ) ;
F_12 ( V_4 -> V_20 ) ;
F_12 ( V_4 -> V_19 ) ;
F_12 ( V_4 -> V_16 ) ;
F_12 ( V_4 -> V_13 ) ;
F_12 ( V_4 -> V_8 ) ;
}
