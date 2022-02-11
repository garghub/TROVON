static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 , T_1 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
if ( F_2 ( V_4 -> V_11 != & V_12 ) )
return - V_13 ;
V_8 = F_3 ( V_4 ) ;
if ( F_2 ( ! ( V_8 -> V_14 & V_15 ) ) )
return - V_13 ;
V_6 -> V_16 [ 0 ] . V_17 = V_8 -> V_18 ;
V_10 = F_4 ( V_2 -> V_19 ) ;
return V_10 -> V_20 -> V_21 ( V_2 -> V_19 , V_4 , V_5 , V_6 ) ;
}
int T_2 F_5 ( void )
{
struct V_22 * V_23 ;
struct V_1 * V_19 ;
struct V_1 * V_24 ;
for ( V_23 = F_6 ( NULL , V_25 ) ; V_23 ;
V_23 = F_6 ( V_23 , V_25 ) ) {
if ( ! F_7 ( V_23 , L_1 ) )
continue;
V_19 = F_8 ( V_23 , V_26 ) ;
if ( ! V_19 || ! F_4 ( V_19 ) ) {
F_9 ( L_2 ,
V_23 -> V_27 ) ;
continue;
}
V_24 = F_10 (
F_11 ( V_23 ) ,
& V_28 ,
V_19 ) ;
if ( ! V_24 ) {
F_9 ( L_3 ,
V_23 -> V_27 ) ;
continue;
}
F_2 ( V_24 ->
V_29 != & V_28 ) ;
F_12 ( L_4 , V_23 -> V_27 ) ;
}
return 0 ;
}
void F_13 ( void )
{
struct V_22 * V_23 ;
for ( V_23 = F_6 ( NULL , V_25 ) ; V_23 ;
V_23 = F_6 ( V_23 , V_25 ) ) {
struct V_1 * V_24 = F_8 (
V_23 ,
V_30 ) ;
if ( ! F_7 ( V_23 , L_1 ) )
continue;
if ( V_24 &&
V_24 -> V_29 == & V_28 )
F_14 ( V_24 ) ;
}
}
