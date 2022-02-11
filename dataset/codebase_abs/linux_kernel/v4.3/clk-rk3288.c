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
static void F_6 ( void T_1 * V_7 )
{
V_5 = V_7 ;
F_7 ( & V_8 ) ;
}
static void F_6 ( void T_1 * V_7 ) {}
static void T_2 F_8 ( struct V_9 * V_10 )
{
void T_1 * V_7 ;
struct V_11 * V_11 ;
V_7 = F_9 ( V_10 , 0 ) ;
if ( ! V_7 ) {
F_10 ( L_1 , V_12 ) ;
return;
}
F_11 ( V_10 , V_7 , V_13 ) ;
V_11 = F_12 ( NULL , L_2 , L_3 , 0 , 1 , 2 ) ;
if ( F_13 ( V_11 ) )
F_14 ( L_4 ,
V_12 , F_15 ( V_11 ) ) ;
V_11 = F_12 ( NULL , L_5 , L_3 , 0 , 20 , 1 ) ;
if ( F_13 ( V_11 ) )
F_14 ( L_6 ,
V_12 , F_15 ( V_11 ) ) ;
V_11 = F_12 ( NULL , L_7 ,
L_8 , 0 , 1 , 4 ) ;
if ( F_13 ( V_11 ) )
F_14 ( L_9 ,
V_12 , F_15 ( V_11 ) ) ;
V_11 = F_12 ( NULL , L_10 , L_11 , 0 , 1 , 1 ) ;
if ( F_13 ( V_11 ) )
F_14 ( L_12 ,
V_12 , F_15 ( V_11 ) ) ;
else
F_16 ( V_11 , V_14 ) ;
F_17 ( V_15 ,
F_2 ( V_15 ) ,
V_16 ) ;
F_18 ( V_17 ,
F_2 ( V_17 ) ) ;
F_19 ( V_18 ,
F_2 ( V_18 ) ) ;
F_20 ( V_19 , L_13 ,
V_20 , F_2 ( V_20 ) ,
& V_21 , V_22 ,
F_2 ( V_22 ) ) ;
F_21 ( V_10 , 12 , V_7 + F_22 ( 0 ) ,
V_23 ) ;
F_23 ( V_24 ) ;
F_6 ( V_7 ) ;
}
