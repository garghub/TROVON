void T_1 F_1 ( void T_2 * V_1 ,
void T_2 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int V_7 )
{
struct V_8 * V_8 ;
struct V_8 * * V_9 ;
int V_10 ;
if ( ! V_6 || V_7 < 1 ) {
F_2 ( L_1 ) ;
F_3 ( 1 ) ;
return;
}
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ ) {
struct V_5 * V_11 = & V_6 [ V_10 ] ;
V_9 = F_4 ( V_11 -> V_12 , V_4 ) ;
if ( V_9 ) {
V_8 = F_5 ( V_11 -> V_13 , V_11 -> V_14 ,
V_1 , V_2 , 0 , V_11 -> V_15 ,
NULL ) ;
* V_9 = V_8 ;
}
}
V_9 = F_4 ( V_16 , V_4 ) ;
if ( V_9 ) {
V_8 = F_6 ( L_2 , L_3 ,
V_1 + V_17 , 0 , V_18 ,
8 , 8 , 1 , NULL ) ;
V_8 = F_7 ( L_4 , L_2 ,
V_1 + V_17 , 1 , 0 , V_19 |
V_20 , 0 , NULL ) ;
* V_9 = V_8 ;
}
for ( V_10 = 0 ; V_10 < F_8 ( V_21 ) ; V_10 ++ ) {
struct V_22 * V_23 ;
V_23 = & V_21 [ V_10 ] ;
V_9 = F_4 ( V_23 -> V_12 , V_4 ) ;
if ( ! V_9 )
continue;
V_8 = F_9 ( V_23 -> V_13 ,
V_23 -> V_24 , V_23 -> V_25 ) ;
* V_9 = V_8 ;
}
for ( V_10 = 0 ; V_10 < F_8 ( V_26 ) ; V_10 ++ ) {
struct V_27 * V_23 ;
V_23 = & V_26 [ V_10 ] ;
V_9 = F_4 ( V_23 -> V_28 , V_4 ) ;
if ( ! V_9 )
continue;
V_8 = F_10 ( NULL , V_23 -> V_29 , V_30 ,
F_8 ( V_30 ) ,
V_31 ,
V_1 + V_23 -> V_32 , 0 , 3 , 0 ,
NULL ) ;
* V_9 = V_8 ;
V_9 = F_4 ( V_23 -> V_33 , V_4 ) ;
if ( ! V_9 )
continue;
V_8 = F_11 ( NULL , V_23 -> V_34 , V_23 -> V_29 ,
0 , V_1 + V_23 -> V_32 , 4 ,
V_35 , NULL ) ;
* V_9 = V_8 ;
}
for ( V_10 = 0 ; V_10 < F_8 ( V_36 ) ; V_10 ++ ) {
struct V_37 * V_23 ;
V_23 = & V_36 [ V_10 ] ;
V_9 = F_4 ( V_23 -> V_12 , V_4 ) ;
if ( ! V_9 )
continue;
V_8 = F_12 ( NULL , V_23 -> V_38 ,
V_23 -> V_14 , V_20 , 2 , 1 ) ;
V_8 = F_6 ( V_23 -> V_39 ,
V_23 -> V_38 , V_1 + V_40 ,
0 , 0 , V_23 -> V_41 , 1 , 0 ,
& V_42 ) ;
V_8 = F_13 ( V_23 -> V_34 ,
V_23 -> V_39 , V_43 ,
V_1 , V_20 , V_23 -> V_44 ,
V_45 ) ;
* V_9 = V_8 ;
}
}
