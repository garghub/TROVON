void T_1 F_1 ( void T_2 * V_1 ,
void T_2 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_7 ;
struct V_7 * * V_8 ;
int V_9 ;
V_8 = F_2 ( V_10 , V_4 ) ;
if ( V_8 ) {
V_7 = F_3 ( L_1 , L_2 , V_1 ,
V_2 , 0 , V_6 , NULL ) ;
* V_8 = V_7 ;
}
V_8 = F_2 ( V_11 , V_4 ) ;
if ( V_8 ) {
V_7 = F_4 ( L_3 , L_1 ,
V_1 + V_12 , 0 , V_13 ,
8 , 8 , 1 , NULL ) ;
V_7 = F_5 ( L_4 , L_3 ,
V_1 + V_12 , 1 , 0 , V_14 |
V_15 , 0 , NULL ) ;
* V_8 = V_7 ;
}
for ( V_9 = 0 ; V_9 < F_6 ( V_16 ) ; V_9 ++ ) {
struct V_17 * V_18 ;
V_18 = & V_16 [ V_9 ] ;
V_8 = F_2 ( V_18 -> V_19 , V_4 ) ;
if ( ! V_8 )
continue;
V_7 = F_7 ( V_18 -> V_20 ,
V_18 -> V_21 , V_18 -> V_22 ) ;
* V_8 = V_7 ;
}
for ( V_9 = 0 ; V_9 < F_6 ( V_23 ) ; V_9 ++ ) {
struct V_24 * V_18 ;
V_18 = & V_23 [ V_9 ] ;
V_8 = F_2 ( V_18 -> V_25 , V_4 ) ;
if ( ! V_8 )
continue;
V_7 = F_8 ( NULL , V_18 -> V_26 , V_27 ,
F_6 ( V_27 ) ,
V_28 ,
V_1 + V_18 -> V_29 , 0 , 3 , 0 ,
NULL ) ;
* V_8 = V_7 ;
V_8 = F_2 ( V_18 -> V_30 , V_4 ) ;
if ( ! V_8 )
continue;
V_7 = F_9 ( NULL , V_18 -> V_31 , V_18 -> V_26 ,
0 , V_1 + V_18 -> V_29 , 4 ,
V_32 , NULL ) ;
* V_8 = V_7 ;
}
for ( V_9 = 0 ; V_9 < F_6 ( V_33 ) ; V_9 ++ ) {
struct V_34 * V_18 ;
V_18 = & V_33 [ V_9 ] ;
V_8 = F_2 ( V_18 -> V_19 , V_4 ) ;
if ( ! V_8 )
continue;
V_7 = F_10 ( NULL , V_18 -> V_35 ,
V_18 -> V_36 , V_15 , 2 , 1 ) ;
V_7 = F_4 ( V_18 -> V_37 ,
V_18 -> V_35 , V_1 + V_38 ,
0 , 0 , V_18 -> V_39 , 1 , 0 ,
& V_40 ) ;
V_7 = F_11 ( V_18 -> V_31 ,
V_18 -> V_37 , V_41 ,
V_1 , V_15 , V_18 -> V_42 ,
V_43 ) ;
* V_8 = V_7 ;
}
}
