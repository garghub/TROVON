static int F_1 ( void )
{
int V_1 , V_2 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_3 ) ; V_1 ++ ) {
V_2 = V_3 [ V_1 ] ;
V_4 [ V_1 ] =
F_3 ( V_5 + V_2 ) ;
}
F_4 ( 0xf3030000 , V_5 + V_6 ) ;
return 0 ;
}
static void F_5 ( void )
{
int V_1 , V_2 ;
for ( V_1 = F_2 ( V_3 ) - 1 ; V_1 >= 0 ; V_1 -- ) {
V_2 = V_3 [ V_1 ] ;
F_4 ( V_4 [ V_1 ] | 0xffff0000 ,
V_5 + V_2 ) ;
}
}
static void F_6 ( void )
{
F_4 ( 0xf3030000 , V_5 + V_6 ) ;
}
static void T_1 F_7 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_11 * V_11 ;
V_5 = F_8 ( V_8 , 0 ) ;
if ( ! V_5 ) {
F_9 ( L_1 , V_12 ) ;
return;
}
V_10 = F_10 ( V_8 , V_5 , V_13 ) ;
if ( F_11 ( V_10 ) ) {
F_9 ( L_2 , V_12 ) ;
F_12 ( V_5 ) ;
return;
}
V_11 = F_13 ( NULL , L_3 , L_4 , 0 , 1 , 1 ) ;
if ( F_11 ( V_11 ) )
F_14 ( L_5 ,
V_12 , F_15 ( V_11 ) ) ;
else
F_16 ( V_10 , V_11 , V_14 ) ;
F_17 ( V_10 , V_15 ,
F_2 ( V_15 ) ,
V_16 ) ;
F_18 ( V_10 , V_17 ,
F_2 ( V_17 ) ) ;
F_19 ( V_18 ,
F_2 ( V_18 ) ) ;
F_20 ( V_10 , V_19 , L_6 ,
V_20 , F_2 ( V_20 ) ,
& V_21 , V_22 ,
F_2 ( V_22 ) ) ;
F_21 ( V_8 , 12 ,
V_5 + F_22 ( 0 ) ,
V_23 ) ;
F_23 ( V_10 , V_24 ,
F_6 ) ;
F_24 ( & V_25 ) ;
F_25 ( V_8 , V_10 ) ;
}
