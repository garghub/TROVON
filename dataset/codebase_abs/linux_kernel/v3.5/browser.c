static void F_1 ( int V_1 )
{
F_2 ( V_1 , L_1 ) ;
F_3 () ;
}
static void F_4 ( T_1 * V_2 )
{
T_2 V_3 ;
T_3 * V_4 ;
int V_5 ;
int V_6 ;
int V_7 ;
V_4 = F_5 ( V_2 ) ;
V_5 = F_6 ( V_4 , V_2 -> V_2 ) ;
F_7 ( V_4 , V_5 , & V_3 ) ;
V_7 = V_3 . V_7 * 3 / 4 ;
V_6 = V_3 . V_6 * 3 / 4 ;
F_8 ( F_9 ( V_2 ) , V_7 , V_6 ) ;
}
static void F_10 ( T_1 * V_2 , struct V_8 * V_8 )
{
T_4 V_9 [ V_10 ] ;
T_5 * V_11 ;
struct V_12 * V_13 ;
T_6 * V_14 ;
struct V_15 * V_16 ;
T_7 V_17 ;
T_1 * V_18 ;
int V_19 ;
int V_20 ;
V_20 = 0 ;
V_9 [ V_20 ++ ] = V_21 ;
F_11 (se, &hist_entry__sort_list, list) {
if ( V_13 -> V_22 )
continue;
V_9 [ V_20 ++ ] = V_21 ;
}
V_14 = F_12 ( V_20 , V_9 ) ;
V_18 = F_13 () ;
V_11 = F_14 () ;
V_19 = 0 ;
F_15 ( F_16 ( V_18 ) ,
- 1 , L_2 ,
V_11 , L_3 ,
V_19 ++ , NULL ) ;
F_11 (se, &hist_entry__sort_list, list) {
if ( V_13 -> V_22 )
continue;
F_15 ( F_16 ( V_18 ) ,
- 1 , V_13 -> V_23 ,
V_11 , L_3 ,
V_19 ++ , NULL ) ;
}
F_17 ( F_16 ( V_18 ) , F_18 ( V_14 ) ) ;
F_19 ( F_18 ( V_14 ) ) ;
V_17 = V_8 -> V_24 . V_17 ;
for ( V_16 = F_20 ( & V_8 -> V_25 ) ; V_16 ; V_16 = F_21 ( V_16 ) ) {
struct V_26 * V_27 = F_22 ( V_16 , struct V_26 , V_15 ) ;
T_8 V_28 ;
double V_29 ;
char V_30 [ 512 ] ;
if ( V_27 -> V_31 )
continue;
F_23 ( V_14 , & V_28 ) ;
V_19 = 0 ;
V_29 = ( V_27 -> V_32 * 100.0 ) / V_17 ;
snprintf ( V_30 , F_24 ( V_30 ) , L_4 , V_29 ) ;
F_25 ( V_14 , & V_28 , V_19 ++ , V_30 , - 1 ) ;
F_11 (se, &hist_entry__sort_list, list) {
if ( V_13 -> V_22 )
continue;
V_13 -> V_33 ( V_27 , V_30 , F_24 ( V_30 ) ,
F_26 ( V_8 , V_13 -> V_34 ) ) ;
F_25 ( V_14 , & V_28 , V_19 ++ , V_30 , - 1 ) ;
}
}
F_27 ( F_28 ( V_2 ) , V_18 ) ;
}
