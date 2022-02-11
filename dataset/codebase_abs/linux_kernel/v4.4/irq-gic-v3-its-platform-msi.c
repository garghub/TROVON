static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , T_1 * V_6 )
{
struct V_7 * V_8 ;
T_2 V_9 ;
int V_10 , V_11 = 0 ;
V_8 = F_2 ( V_2 -> V_12 ) ;
do {
struct V_13 args ;
V_10 = F_3 ( V_4 -> V_14 ,
L_1 , L_2 ,
V_11 , & args ) ;
if ( args . V_15 == F_4 ( V_2 ) ) {
if ( F_5 ( args . V_16 != 1 ) )
return - V_17 ;
V_9 = args . args [ 0 ] ;
break;
}
} while ( ! V_10 );
if ( V_10 )
return V_10 ;
V_6 -> V_18 [ 0 ] . V_19 = V_9 ;
return V_8 -> V_20 -> V_21 ( V_2 -> V_12 ,
V_4 , V_5 , V_6 ) ;
}
static int T_3 F_6 ( void )
{
struct V_22 * V_15 ;
struct V_1 * V_12 ;
for ( V_15 = F_7 ( NULL , V_23 ) ; V_15 ;
V_15 = F_7 ( V_15 , V_23 ) ) {
if ( ! F_8 ( V_15 , L_3 ) )
continue;
V_12 = F_9 ( V_15 , V_24 ) ;
if ( ! V_12 || ! F_2 ( V_12 ) ) {
F_10 ( L_4 ,
V_15 -> V_25 ) ;
continue;
}
if ( ! F_11 ( F_12 ( V_15 ) ,
& V_26 ,
V_12 ) ) {
F_10 ( L_5 ,
V_15 -> V_25 ) ;
continue;
}
F_13 ( L_6 , V_15 -> V_25 ) ;
}
return 0 ;
}
