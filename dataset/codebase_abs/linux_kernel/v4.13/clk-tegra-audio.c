static void T_1 F_1 ( void T_2 * V_1 ,
struct V_2 * V_3 ,
struct V_4 * V_5 ,
int V_6 ,
const char * const * V_7 ,
int V_8 )
{
struct V_9 * V_9 ;
struct V_9 * * V_10 ;
struct V_4 * V_11 ;
int V_12 ;
for ( V_12 = 0 , V_11 = V_5 ; V_12 < V_6 ; V_12 ++ , V_11 ++ ) {
V_10 = F_2 ( V_11 -> V_13 , V_3 ) ;
if ( ! V_10 )
continue;
V_9 = F_3 ( NULL , V_11 -> V_14 , V_7 ,
V_8 ,
V_15 ,
V_1 + V_11 -> V_16 , 0 , 3 , 0 ,
NULL ) ;
* V_10 = V_9 ;
V_10 = F_2 ( V_11 -> V_17 , V_3 ) ;
if ( ! V_10 )
continue;
V_9 = F_4 ( NULL , V_11 -> V_18 , V_11 -> V_14 ,
0 , V_1 + V_11 -> V_16 , 4 ,
V_19 , NULL ) ;
* V_10 = V_9 ;
}
}
void T_1 F_5 ( void T_2 * V_1 ,
void T_2 * V_20 , struct V_2 * V_3 ,
struct V_21 * V_22 ,
unsigned int V_23 )
{
struct V_9 * V_9 ;
struct V_9 * * V_10 ;
int V_12 ;
if ( ! V_22 || V_23 < 1 ) {
F_6 ( L_1 ) ;
F_7 ( 1 ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_23 ; V_12 ++ ) {
struct V_21 * V_24 = & V_22 [ V_12 ] ;
V_10 = F_2 ( V_24 -> V_25 , V_3 ) ;
if ( V_10 ) {
V_9 = F_8 ( V_24 -> V_26 , V_24 -> V_27 ,
V_1 , V_20 , 0 , V_24 -> V_28 ,
NULL ) ;
* V_10 = V_9 ;
}
}
V_10 = F_2 ( V_29 , V_3 ) ;
if ( V_10 ) {
V_9 = F_9 ( L_2 , L_3 ,
V_1 + V_30 , 0 , V_31 ,
8 , 8 , 1 , NULL ) ;
V_9 = F_10 ( L_4 , L_2 ,
V_1 + V_30 , 1 , 0 , V_32 |
V_33 , 0 , NULL ) ;
* V_10 = V_9 ;
}
for ( V_12 = 0 ; V_12 < F_11 ( V_34 ) ; V_12 ++ ) {
struct V_35 * V_11 ;
V_11 = & V_34 [ V_12 ] ;
V_10 = F_2 ( V_11 -> V_25 , V_3 ) ;
if ( ! V_10 )
continue;
V_9 = F_12 ( V_11 -> V_26 ,
V_11 -> V_36 , V_11 -> V_37 ) ;
* V_10 = V_9 ;
}
F_1 ( V_1 , V_3 , V_38 ,
F_11 ( V_38 ) , V_39 ,
F_11 ( V_39 ) ) ;
for ( V_12 = 0 ; V_12 < F_11 ( V_40 ) ; V_12 ++ )
F_13 ( 1 , V_1 + V_40 [ V_12 ] . V_16 ) ;
F_1 ( V_1 , V_3 , V_40 ,
F_11 ( V_40 ) , V_41 ,
F_11 ( V_41 ) ) ;
for ( V_12 = 0 ; V_12 < F_11 ( V_42 ) ; V_12 ++ ) {
struct V_43 * V_11 ;
V_11 = & V_42 [ V_12 ] ;
V_10 = F_2 ( V_11 -> V_25 , V_3 ) ;
if ( ! V_10 )
continue;
V_9 = F_14 ( NULL , V_11 -> V_44 ,
V_11 -> V_27 , V_33 , 2 , 1 ) ;
V_9 = F_9 ( V_11 -> V_45 ,
V_11 -> V_44 , V_1 + V_46 ,
0 , 0 , V_11 -> V_47 , 1 , 0 ,
& V_48 ) ;
V_9 = F_15 ( V_11 -> V_18 ,
V_11 -> V_45 , V_49 ,
V_1 , V_33 , V_11 -> V_50 ,
V_51 ) ;
* V_10 = V_9 ;
}
}
