void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_5 ;
unsigned long V_6 ;
if ( V_4 -> V_7 [ 5 ] != 0x00 ) {
F_2 ( V_2 -> V_8 , L_1 ,
V_4 -> V_7 [ 5 ] ) ;
V_2 -> V_9 = - V_10 ;
}
F_3 ( V_4 ) ;
V_5 = F_4 ( V_11 ) ;
if ( V_5 == NULL || V_2 -> V_9 ) {
F_5 ( & V_2 -> V_12 ) ;
return;
}
F_6 ( & V_2 -> V_13 , V_5 ) ;
F_7 ( & V_2 -> V_14 , V_6 ) ;
F_8 ( V_2 , V_15 , F_9 ( V_2 , V_15 ) |
V_16 ) ;
F_10 ( & V_2 -> V_14 , V_6 ) ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_3 * V_4 ;
unsigned long V_6 , time ;
V_2 -> V_9 = 0 ;
F_12 ( L_2 ) ;
time = V_19 ;
V_11 = V_18 ;
V_4 = F_4 ( V_18 ) ;
if ( ! V_4 )
return - V_20 ;
F_12 ( L_3 ) ;
F_13 ( & V_2 -> V_12 ) ;
F_14 ( V_2 , 0 ) ;
F_6 ( & V_2 -> V_13 , V_4 ) ;
F_7 ( & V_2 -> V_14 , V_6 ) ;
F_8 ( V_2 , V_15 , F_9 ( V_2 , V_15 ) |
V_16 ) ;
F_10 ( & V_2 -> V_14 , V_6 ) ;
if ( ! F_15 ( & V_2 -> V_12 ,
F_16 ( 2000 ) ) ) {
F_2 ( V_2 -> V_8 , L_4 ) ;
return - V_21 ;
}
if ( V_2 -> V_9 ) {
F_2 ( V_2 -> V_8 , L_5 ) ;
return - V_10 ;
}
F_12 ( L_6 ,
F_17 ( V_19 - time ) ) ;
F_18 ( V_2 , 0 , V_22 ) ;
F_19 ( V_2 , 0 ) ;
F_20 ( V_2 , V_23 ) ;
if ( F_21 ( V_2 , 1 , 100 ) ) {
F_2 ( V_2 -> V_8 ,
L_7 ) ;
return - V_21 ;
}
F_18 ( V_2 , 1 , V_22 ) ;
return 0 ;
}
