static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 , T_1 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
if ( F_2 ( ! F_3 ( V_4 ) ) )
return - V_11 ;
V_8 = F_4 ( V_4 ) ;
if ( F_2 ( ! ( V_8 -> V_12 & V_13 ) ) )
return - V_11 ;
#ifdef F_5
V_6 -> V_14 [ 0 ] . V_15 = V_8 -> V_16 ;
#endif
V_10 = F_6 ( V_2 -> V_17 ) ;
return V_10 -> V_18 -> V_19 ( V_2 -> V_17 , V_4 , V_5 , V_6 ) ;
}
int T_2 F_7 ( void )
{
struct V_20 * V_21 ;
struct V_1 * V_17 ;
struct V_1 * V_22 ;
for ( V_21 = F_8 ( NULL , V_23 ) ; V_21 ;
V_21 = F_8 ( V_21 , V_23 ) ) {
if ( ! F_9 ( V_21 , L_1 ) )
continue;
V_17 = F_10 ( V_21 , V_24 ) ;
if ( ! V_17 || ! F_6 ( V_17 ) ) {
F_11 ( L_2 , V_21 ) ;
continue;
}
V_22 = F_12 (
F_13 ( V_21 ) ,
& V_25 ,
V_17 ) ;
if ( ! V_22 ) {
F_11 ( L_3 , V_21 ) ;
continue;
}
F_2 ( V_22 -> V_26 !=
& V_25 ) ;
F_14 ( L_4 , V_21 ) ;
}
return 0 ;
}
void F_15 ( void )
{
struct V_20 * V_21 ;
for ( V_21 = F_8 ( NULL , V_23 ) ; V_21 ;
V_21 = F_8 ( V_21 , V_23 ) ) {
struct V_1 * V_22 = F_10 (
V_21 ,
V_27 ) ;
if ( ! F_9 ( V_21 , L_1 ) )
continue;
if ( V_22 &&
V_22 -> V_26 == & V_25 )
F_16 ( V_22 ) ;
}
}
