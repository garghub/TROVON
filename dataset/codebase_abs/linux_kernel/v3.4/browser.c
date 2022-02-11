void F_1 ( int V_1 , const char * V_2 [] ,
bool T_1 V_3 )
{
F_2 ( & V_1 , ( char * * * ) & V_2 ) ;
}
void F_3 ( bool T_2 V_3 )
{
F_4 () ;
}
static void F_5 ( int V_4 )
{
F_6 ( V_4 , L_1 ) ;
F_4 () ;
}
static void F_7 ( T_3 * V_5 )
{
T_4 V_6 ;
T_5 * V_7 ;
int V_8 ;
int V_9 ;
int V_10 ;
V_7 = F_8 ( V_5 ) ;
V_8 = F_9 ( V_7 , V_5 -> V_5 ) ;
F_10 ( V_7 , V_8 , & V_6 ) ;
V_10 = V_6 . V_10 * 3 / 4 ;
V_9 = V_6 . V_9 * 3 / 4 ;
F_11 ( F_12 ( V_5 ) , V_10 , V_9 ) ;
}
static void F_13 ( T_3 * V_5 , struct V_11 * V_11 )
{
T_6 V_12 [ V_13 ] ;
T_7 * V_14 ;
struct V_15 * V_16 ;
T_8 * V_17 ;
struct V_18 * V_19 ;
T_9 V_20 ;
T_3 * V_21 ;
int V_22 ;
int V_23 ;
V_23 = 0 ;
V_12 [ V_23 ++ ] = V_24 ;
F_14 (se, &hist_entry__sort_list, list) {
if ( V_16 -> V_25 )
continue;
V_12 [ V_23 ++ ] = V_24 ;
}
V_17 = F_15 ( V_23 , V_12 ) ;
V_21 = F_16 () ;
V_14 = F_17 () ;
V_22 = 0 ;
F_18 ( F_19 ( V_21 ) ,
- 1 , L_2 ,
V_14 , L_3 ,
V_22 ++ , NULL ) ;
F_14 (se, &hist_entry__sort_list, list) {
if ( V_16 -> V_25 )
continue;
F_18 ( F_19 ( V_21 ) ,
- 1 , V_16 -> V_26 ,
V_14 , L_3 ,
V_22 ++ , NULL ) ;
}
F_20 ( F_19 ( V_21 ) , F_21 ( V_17 ) ) ;
F_22 ( F_21 ( V_17 ) ) ;
V_20 = V_11 -> V_27 . V_20 ;
for ( V_19 = F_23 ( & V_11 -> V_28 ) ; V_19 ; V_19 = F_24 ( V_19 ) ) {
struct V_29 * V_30 = F_25 ( V_19 , struct V_29 , V_18 ) ;
T_10 V_31 ;
double V_32 ;
char V_33 [ 512 ] ;
if ( V_30 -> V_34 )
continue;
F_26 ( V_17 , & V_31 ) ;
V_22 = 0 ;
V_32 = ( V_30 -> V_35 * 100.0 ) / V_20 ;
snprintf ( V_33 , F_27 ( V_33 ) , L_4 , V_32 ) ;
F_28 ( V_17 , & V_31 , V_22 ++ , V_33 , - 1 ) ;
F_14 (se, &hist_entry__sort_list, list) {
if ( V_16 -> V_25 )
continue;
V_16 -> V_36 ( V_30 , V_33 , F_27 ( V_33 ) ,
F_29 ( V_11 , V_16 -> V_37 ) ) ;
F_28 ( V_17 , & V_31 , V_22 ++ , V_33 , - 1 ) ;
}
}
F_30 ( F_31 ( V_5 ) , V_21 ) ;
}
