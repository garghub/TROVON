static struct V_1 * T_1 F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
void T_2 * V_5 ;
V_5 = F_2 ( V_3 , 0 ) ;
if ( ! V_5 ) {
F_3 ( L_1 , V_6 ) ;
return F_4 ( - V_7 ) ;
}
V_4 = F_5 ( V_3 , V_5 , V_8 ) ;
if ( F_6 ( V_4 ) ) {
F_3 ( L_2 , V_6 ) ;
F_7 ( V_5 ) ;
return F_4 ( - V_7 ) ;
}
F_8 ( V_4 , V_9 ,
F_9 ( V_9 ) ) ;
F_10 ( V_3 , 9 , V_5 + F_11 ( 0 ) ,
V_10 ) ;
F_12 ( V_4 , V_11 , NULL ) ;
return V_4 ;
}
static void T_1 F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( F_6 ( V_4 ) )
return;
F_14 ( V_4 , V_12 ,
F_9 ( V_12 ) ,
V_13 ) ;
F_8 ( V_4 , V_14 ,
F_9 ( V_14 ) ) ;
F_15 ( V_4 , V_15 , L_3 ,
V_16 , F_9 ( V_16 ) ,
& V_17 , V_18 ,
F_9 ( V_18 ) ) ;
F_16 ( V_19 ,
F_9 ( V_19 ) ) ;
F_17 ( V_3 , V_4 ) ;
}
static void T_1 F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_20 * V_21 , * V_22 ;
unsigned long V_23 ;
int V_24 ;
V_4 = F_1 ( V_3 ) ;
if ( F_6 ( V_4 ) )
return;
F_14 ( V_4 , V_25 ,
F_9 ( V_25 ) ,
V_26 ) ;
F_8 ( V_4 , V_27 ,
F_9 ( V_27 ) ) ;
F_15 ( V_4 , V_15 , L_3 ,
V_16 , F_9 ( V_16 ) ,
& V_28 , V_29 ,
F_9 ( V_29 ) ) ;
V_21 = F_19 ( L_4 ) ;
V_22 = F_19 ( L_5 ) ;
if ( V_21 && V_22 ) {
V_23 = F_20 ( V_21 ) ;
V_24 = F_21 ( V_21 , V_22 ) ;
if ( V_24 < 0 )
F_22 ( L_6 ,
V_6 ) ;
F_23 ( V_21 , V_23 ) ;
} else {
F_22 ( L_7 ,
V_6 ) ;
}
F_16 ( V_19 ,
F_9 ( V_19 ) ) ;
F_17 ( V_3 , V_4 ) ;
}
static void T_1 F_24 ( struct V_2 * V_3 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < F_9 ( V_25 ) ; V_30 ++ ) {
struct V_31 * V_32 = & V_25 [ V_30 ] ;
struct V_33 * V_23 ;
if ( ! V_32 -> V_34 )
continue;
V_23 = V_32 -> V_34 ;
while ( V_23 -> V_23 > 0 ) {
V_23 -> V_35 = 1 ;
V_23 ++ ;
}
}
F_18 ( V_3 ) ;
}
