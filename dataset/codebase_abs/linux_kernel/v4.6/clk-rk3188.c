static void T_1 F_1 ( struct V_1 * V_2 )
{
void T_2 * V_3 ;
V_3 = F_2 ( V_2 , 0 ) ;
if ( ! V_3 ) {
F_3 ( L_1 , V_4 ) ;
return;
}
F_4 ( V_2 , V_3 , V_5 ) ;
F_5 ( V_6 ,
F_6 ( V_6 ) ) ;
F_7 ( V_2 , 9 , V_3 + F_8 ( 0 ) ,
V_7 ) ;
F_9 ( V_8 , NULL ) ;
}
static void T_1 F_10 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_11 ( V_9 ,
F_6 ( V_9 ) ,
V_10 ) ;
F_5 ( V_11 ,
F_6 ( V_11 ) ) ;
F_12 ( V_12 , L_2 ,
V_13 , F_6 ( V_13 ) ,
& V_14 , V_15 ,
F_6 ( V_15 ) ) ;
F_13 ( V_16 ,
F_6 ( V_16 ) ) ;
}
static void T_1 F_14 ( struct V_1 * V_2 )
{
struct V_17 * V_18 , * V_19 ;
unsigned long V_20 ;
int V_21 ;
F_1 ( V_2 ) ;
F_11 ( V_22 ,
F_6 ( V_22 ) ,
V_23 ) ;
F_5 ( V_24 ,
F_6 ( V_24 ) ) ;
F_12 ( V_12 , L_2 ,
V_13 , F_6 ( V_13 ) ,
& V_25 , V_26 ,
F_6 ( V_26 ) ) ;
V_18 = F_15 ( L_3 ) ;
V_19 = F_15 ( L_4 ) ;
if ( V_18 && V_19 ) {
V_20 = F_16 ( V_18 ) ;
V_21 = F_17 ( V_18 , V_19 ) ;
if ( V_21 < 0 )
F_18 ( L_5 ,
V_4 ) ;
F_19 ( V_18 , V_20 ) ;
} else {
F_18 ( L_6 ,
V_4 ) ;
}
F_13 ( V_16 ,
F_6 ( V_16 ) ) ;
}
static void T_1 F_20 ( struct V_1 * V_2 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < F_6 ( V_22 ) ; V_27 ++ ) {
struct V_28 * V_29 = & V_22 [ V_27 ] ;
struct V_30 * V_20 ;
if ( ! V_29 -> V_31 )
continue;
V_20 = V_29 -> V_31 ;
while ( V_20 -> V_20 > 0 ) {
V_20 -> V_32 = 1 ;
V_20 ++ ;
}
}
F_14 ( V_2 ) ;
}
