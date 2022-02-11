static void T_1 F_1 ( struct V_1 * V_2 )
{
static const char * const V_3 [] = { L_1 , L_2 , L_3 , L_4 } ;
enum { V_4 , V_5 , V_6 , V_7 , V_8 } V_9 ;
const char * V_10 [ V_8 ] ;
struct V_11 * V_12 ;
const char * V_13 ;
struct V_14 * V_15 ;
struct V_16 V_17 ;
void T_2 * V_18 ;
void T_2 * V_19 ;
const T_3 * V_20 ;
int V_21 , V_22 ;
T_4 V_23 ;
int V_24 ;
V_19 = F_2 ( V_2 , 0 , F_3 ( V_2 ) ) ;
if ( F_4 ( V_19 ) )
return;
for ( V_22 = 0 ; V_22 < F_5 ( V_3 ) ; V_22 ++ ) {
int V_25 = F_6 ( V_2 , L_5 ,
V_3 [ V_22 ] ) ;
if ( V_25 < 0 )
return;
V_10 [ V_22 ] = F_7 ( V_2 , V_25 ) ;
}
V_12 = F_8 ( sizeof( struct V_11 ) , V_26 ) ;
if ( ! V_12 )
goto V_27;
V_21 = F_9 ( V_2 , L_6 ) ;
F_10 ( V_2 , L_6 , V_21 - 1 , & V_21 ) ;
V_12 -> V_28 = F_11 ( V_21 + 1 , sizeof( struct V_29 * ) , V_26 ) ;
if ( ! V_12 -> V_28 )
goto V_30;
V_22 = 0 ;
F_12 (node, L_6 , prop, p, index) {
F_13 ( V_2 , L_7 ,
V_22 , & V_13 ) ;
if ( V_24 == 17 || ( V_24 >= 29 && V_24 <= 31 ) )
V_9 = V_5 ;
else if ( V_24 <= 63 || V_24 >= 128 )
V_9 = V_4 ;
else if ( V_24 >= 64 && V_24 <= 95 )
V_9 = V_6 ;
else if ( V_24 >= 96 && V_24 <= 127 )
V_9 = V_7 ;
else {
F_14 ( true ) ;
continue;
}
V_18 = V_19 + 4 * ( V_24 / 32 ) ;
V_23 = V_24 % 32 ;
V_12 -> V_28 [ V_24 ] = F_15 ( NULL , V_13 ,
V_10 [ V_9 ] ,
0 , V_18 , V_23 ,
0 , & V_31 ) ;
V_22 ++ ;
if ( F_4 ( V_12 -> V_28 [ V_24 ] ) ) {
F_14 ( true ) ;
continue;
}
}
V_12 -> V_32 = V_21 + 1 ;
F_16 ( V_2 , V_33 , V_12 ) ;
return;
V_30:
F_17 ( V_12 ) ;
V_27:
F_18 ( V_19 ) ;
F_19 ( V_2 , 0 , & V_17 ) ;
F_20 ( V_17 . V_34 , F_21 ( & V_17 ) ) ;
}
