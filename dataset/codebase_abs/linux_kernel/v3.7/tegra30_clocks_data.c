static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_1 = F_2 ( V_2 -> V_4 ) ;
F_3 ( NULL , V_2 ) ;
F_4 ( & V_1 -> V_5 ) ;
if ( ! V_1 -> V_6 . V_7 && ! V_1 -> V_6 . V_8 )
V_1 -> V_6 . V_8 = V_2 -> V_9 ;
V_1 -> V_6 . V_1 = V_2 ;
F_5 ( & V_1 -> V_6 ) ;
F_6 ( V_2 ) ;
}
void T_1 F_7 ( void )
{
int V_10 ;
struct V_1 * V_2 ;
for ( V_10 = 0 ; V_10 < F_8 ( V_11 ) ; V_10 ++ )
F_1 ( V_11 [ V_10 ] ) ;
for ( V_10 = 0 ; V_10 < F_8 ( V_12 ) ; V_10 ++ )
F_1 ( V_12 [ V_10 ] ) ;
for ( V_10 = 0 ; V_10 < F_8 ( V_13 ) ; V_10 ++ ) {
V_2 = F_9 ( V_13 [ V_10 ] . V_9 ) ;
if ( ! V_2 ) {
F_10 ( L_1 , V_14 ,
V_13 [ V_10 ] . V_9 ) ;
continue;
}
V_13 [ V_10 ] . V_6 . V_1 = V_2 ;
F_5 ( & V_13 [ V_10 ] . V_6 ) ;
}
for ( V_10 = 0 ; V_10 < F_8 ( V_15 ) ; V_10 ++ )
F_1 ( V_15 [ V_10 ] ) ;
for ( V_10 = 0 ; V_10 < F_8 ( V_16 ) ; V_10 ++ )
F_1 ( V_16 [ V_10 ] ) ;
for ( V_10 = 0 ; V_10 < F_8 ( V_17 ) ; V_10 ++ )
F_1 ( V_17 [ V_10 ] ) ;
for ( V_10 = 0 ; V_10 < F_8 ( V_18 ) ; V_10 ++ )
F_1 ( V_18 [ V_10 ] ) ;
F_11 () ;
}
