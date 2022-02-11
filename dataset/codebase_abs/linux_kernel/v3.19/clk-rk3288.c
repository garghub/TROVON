static int F_1 ( void )
{
int V_1 , V_2 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_3 ) ; V_1 ++ ) {
V_2 = V_3 [ V_1 ] ;
V_4 [ V_1 ] =
F_3 ( V_5 + V_2 ) ;
}
return 0 ;
}
static void F_4 ( void )
{
int V_1 , V_2 ;
for ( V_1 = F_2 ( V_3 ) - 1 ; V_1 >= 0 ; V_1 -- ) {
V_2 = V_3 [ V_1 ] ;
F_5 ( V_4 [ V_1 ] | 0xffff0000 ,
V_5 + V_2 ) ;
}
}
static void F_6 ( void T_1 * V_6 )
{
V_5 = V_6 ;
F_7 ( & V_7 ) ;
}
static void F_6 ( void T_1 * V_6 ) {}
static void T_2 F_8 ( struct V_8 * V_9 )
{
void T_1 * V_6 ;
struct V_10 * V_10 ;
V_6 = F_9 ( V_9 , 0 ) ;
if ( ! V_6 ) {
F_10 ( L_1 , V_11 ) ;
return;
}
F_11 ( V_9 , V_6 , V_12 ) ;
V_10 = F_12 ( NULL , L_2 , L_3 , 0 , 1 , 2 ) ;
if ( F_13 ( V_10 ) )
F_14 ( L_4 ,
V_11 , F_15 ( V_10 ) ) ;
V_10 = F_12 ( NULL , L_5 , L_3 , 0 , 20 , 1 ) ;
if ( F_13 ( V_10 ) )
F_14 ( L_6 ,
V_11 , F_15 ( V_10 ) ) ;
V_10 = F_12 ( NULL , L_7 ,
L_8 , 0 , 1 , 4 ) ;
if ( F_13 ( V_10 ) )
F_14 ( L_9 ,
V_11 , F_15 ( V_10 ) ) ;
F_16 ( V_13 ,
F_2 ( V_13 ) ,
V_14 ) ;
F_17 ( V_15 ,
F_2 ( V_15 ) ) ;
F_18 ( V_16 ,
F_2 ( V_16 ) ) ;
F_19 ( V_17 , L_10 ,
V_18 , F_2 ( V_18 ) ,
& V_19 , V_20 ,
F_2 ( V_20 ) ) ;
F_20 ( V_9 , 12 , V_6 + F_21 ( 0 ) ,
V_21 ) ;
F_22 ( V_22 ) ;
F_6 ( V_6 ) ;
}
