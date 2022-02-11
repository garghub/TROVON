static void T_1 F_1 ( struct V_1 * V_2 )
{
void T_2 * V_3 ;
struct V_4 * V_4 ;
V_3 = F_2 ( V_2 , 0 ) ;
if ( ! V_3 ) {
F_3 ( L_1 , V_5 ) ;
return;
}
F_4 ( V_2 , V_3 , V_6 ) ;
V_4 = F_5 ( NULL , L_2 , L_3 , 0 , 1 , 2 ) ;
if ( F_6 ( V_4 ) )
F_7 ( L_4 ,
V_5 , F_8 ( V_4 ) ) ;
V_4 = F_5 ( NULL , L_5 , L_3 , 0 , 20 , 1 ) ;
if ( F_6 ( V_4 ) )
F_7 ( L_6 ,
V_5 , F_8 ( V_4 ) ) ;
F_9 ( V_7 ,
F_10 ( V_7 ) ) ;
F_11 ( V_2 , 9 , V_3 + F_12 ( 0 ) ,
V_8 ) ;
F_13 ( V_9 , NULL ) ;
}
static void T_1 F_14 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_15 ( V_10 ,
F_10 ( V_10 ) ,
V_11 ) ;
F_9 ( V_12 ,
F_10 ( V_12 ) ) ;
F_16 ( V_13 , L_7 ,
V_14 , F_10 ( V_14 ) ,
& V_15 , V_16 ,
F_10 ( V_16 ) ) ;
F_17 ( V_17 ,
F_10 ( V_17 ) ) ;
}
static void T_1 F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_18 , * V_19 ;
unsigned long V_20 ;
int V_21 ;
F_1 ( V_2 ) ;
F_15 ( V_22 ,
F_10 ( V_22 ) ,
V_23 ) ;
F_9 ( V_24 ,
F_10 ( V_24 ) ) ;
F_16 ( V_13 , L_7 ,
V_14 , F_10 ( V_14 ) ,
& V_25 , V_26 ,
F_10 ( V_26 ) ) ;
V_18 = F_19 ( L_8 ) ;
V_19 = F_19 ( L_9 ) ;
if ( V_18 && V_19 ) {
V_20 = F_20 ( V_18 ) ;
V_21 = F_21 ( V_18 , V_19 ) ;
if ( V_21 < 0 )
F_7 ( L_10 ,
V_5 ) ;
F_22 ( V_18 , V_20 ) ;
} else {
F_7 ( L_11 ,
V_5 ) ;
}
F_17 ( V_17 ,
F_10 ( V_17 ) ) ;
}
static void T_1 F_23 ( struct V_1 * V_2 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < F_10 ( V_22 ) ; V_27 ++ ) {
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
F_18 ( V_2 ) ;
}
