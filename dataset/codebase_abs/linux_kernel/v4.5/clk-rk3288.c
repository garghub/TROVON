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
struct V_9 * V_9 ;
V_5 = F_8 ( V_8 , 0 ) ;
if ( ! V_5 ) {
F_9 ( L_1 , V_10 ) ;
return;
}
F_10 ( V_8 , V_5 , V_11 ) ;
V_9 = F_11 ( NULL , L_2 , L_3 , 0 , 1 , 2 ) ;
if ( F_12 ( V_9 ) )
F_13 ( L_4 ,
V_10 , F_14 ( V_9 ) ) ;
V_9 = F_11 ( NULL , L_5 , L_3 , 0 , 20 , 1 ) ;
if ( F_12 ( V_9 ) )
F_13 ( L_6 ,
V_10 , F_14 ( V_9 ) ) ;
V_9 = F_11 ( NULL , L_7 ,
L_8 , 0 , 1 , 4 ) ;
if ( F_12 ( V_9 ) )
F_13 ( L_9 ,
V_10 , F_14 ( V_9 ) ) ;
V_9 = F_11 ( NULL , L_10 , L_11 , 0 , 1 , 1 ) ;
if ( F_12 ( V_9 ) )
F_13 ( L_12 ,
V_10 , F_14 ( V_9 ) ) ;
else
F_15 ( V_9 , V_12 ) ;
F_16 ( V_13 ,
F_2 ( V_13 ) ,
V_14 ) ;
F_17 ( V_15 ,
F_2 ( V_15 ) ) ;
F_18 ( V_16 ,
F_2 ( V_16 ) ) ;
F_19 ( V_17 , L_13 ,
V_18 , F_2 ( V_18 ) ,
& V_19 , V_20 ,
F_2 ( V_20 ) ) ;
F_20 ( V_8 , 12 ,
V_5 + F_21 ( 0 ) ,
V_21 ) ;
F_22 ( V_22 ,
F_6 ) ;
F_23 ( & V_23 ) ;
}
