int T_1 F_1 ( void )
{
const struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_2 V_5 ;
V_6 = V_7 ;
V_8 = F_2 ( V_9 , V_10 ) ;
V_11 = V_12 ;
V_13 = V_14 ;
F_3 ( & V_15 ) ;
for ( V_4 = V_16 ; V_4 < V_16 + F_4 ( V_16 ) ;
V_4 ++ )
F_5 ( V_4 -> V_17 . V_18 ) ;
V_19 . V_20 = F_6 ( & V_19 ) ;
F_7 ( & V_19 ) ;
V_21 . V_20 = F_8 ( & V_21 ) ;
F_7 ( & V_21 ) ;
for ( V_4 = V_16 ; V_4 < V_16 + F_4 ( V_16 ) ;
V_4 ++ ) {
F_9 ( & V_4 -> V_17 ) ;
F_10 ( V_4 -> V_17 . V_18 ) ;
F_11 ( V_4 -> V_17 . V_18 ) ;
}
F_12 () ;
V_5 = F_13 ( & V_22 ) ;
for ( V_2 = V_13 ; V_2 -> V_23 ; V_2 ++ ) {
if ( ! ( V_2 -> V_24 & V_11 ) )
continue;
if ( V_2 -> V_25 != V_21 . V_20 )
continue;
if ( V_2 -> V_26 <= V_5 )
break;
}
V_27 = V_2 ;
F_14 () ;
F_15 ( L_1 ,
( V_21 . V_20 / 1000000 ) , ( V_21 . V_20 / 100000 ) % 10 ,
( V_22 . V_20 / 1000000 ) , ( V_28 . V_20 / 1000000 ) ) ;
F_16 () ;
V_29 = F_17 ( NULL , L_2 ) ;
V_30 = F_17 ( NULL , L_3 ) ;
V_31 = F_17 ( NULL , L_4 ) ;
return 0 ;
}
