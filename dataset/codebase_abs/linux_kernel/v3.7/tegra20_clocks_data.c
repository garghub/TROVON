static void F_1 ( void )
{
int V_1 ;
struct V_2 * V_3 = V_4 ;
const struct V_5 * V_6 = V_7 ;
struct V_8 * V_9 ;
for ( V_1 = 0 ; V_6 -> V_10 ; V_1 ++ , V_3 ++ , V_6 ++ ) {
V_3 -> V_11 = F_2 ( V_6 -> V_10 ) ;
if ( ! V_3 -> V_11 )
F_3 ( L_1 , V_12 ,
V_6 -> V_10 ) ;
V_13 [ V_6 -> V_14 ] = V_3 -> V_11 ;
V_3 -> V_14 = V_6 -> V_14 ;
}
V_9 = V_15 ;
for ( V_1 = 0 ; V_1 < F_4 ( V_15 ) ; V_1 ++ , V_9 ++ ) {
struct V_16 * V_17 = V_9 -> V_16 ;
struct V_18 * V_16 = F_5 ( V_17 -> V_19 ) ;
F_6 ( NULL , V_17 ) ;
F_7 ( & V_16 -> V_20 ) ;
V_16 -> V_9 . V_21 = V_9 -> V_21 ;
V_16 -> V_9 . V_16 = V_17 ;
F_8 ( & V_16 -> V_9 ) ;
F_9 ( V_17 ) ;
}
}
static void F_10 ( struct V_16 * V_17 )
{
struct V_18 * V_16 = F_5 ( V_17 -> V_19 ) ;
int V_22 ;
V_22 = F_6 ( NULL , V_17 ) ;
if ( V_22 )
F_3 ( L_2 , F_11 ( V_17 ) ) ;
F_7 ( & V_16 -> V_20 ) ;
if ( ! V_16 -> V_9 . V_23 && ! V_16 -> V_9 . V_21 )
V_16 -> V_9 . V_21 = V_17 -> V_10 ;
V_16 -> V_9 . V_16 = V_17 ;
F_8 ( & V_16 -> V_9 ) ;
F_9 ( V_17 ) ;
}
void T_1 F_12 ( void )
{
int V_1 ;
struct V_16 * V_17 ;
for ( V_1 = 0 ; V_1 < F_4 ( V_24 ) ; V_1 ++ )
F_10 ( V_24 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < F_4 ( V_25 ) ; V_1 ++ )
F_10 ( V_25 [ V_1 ] ) ;
for ( V_1 = 0 ; V_1 < F_4 ( V_26 ) ; V_1 ++ ) {
V_17 = F_2 ( V_26 [ V_1 ] . V_10 ) ;
if ( ! V_17 ) {
F_3 ( L_3 , V_12 ,
V_26 [ V_1 ] . V_10 ) ;
continue;
}
V_26 [ V_1 ] . V_9 . V_16 = V_17 ;
F_8 ( & V_26 [ V_1 ] . V_9 ) ;
}
F_1 () ;
F_13 () ;
}
