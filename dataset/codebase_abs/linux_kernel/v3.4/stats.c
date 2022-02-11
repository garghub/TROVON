static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
F_2 ( V_2 , L_1 ,
V_5 . V_6 ,
V_5 . V_7 ,
V_5 . V_8 ,
V_5 . V_9 ,
V_5 . V_10 ,
V_5 . V_11 ,
V_5 . V_12 ,
V_5 . V_13 ,
V_5 . V_14 ,
V_5 . V_15 ) ;
F_2 ( V_2 , L_2 , V_5 . V_16 , V_5 . V_17 ) ;
for ( V_4 = 0 ; V_4 < 10 ; V_4 ++ ) {
unsigned int V_18 = V_5 . V_19 [ V_4 ] ;
unsigned int V_20 = V_18 / V_21 , V_22 = ( V_18 % V_21 ) * 1000 / V_21 ;
F_2 ( V_2 , L_3 , V_20 , V_22 ) ;
}
F_2 ( V_2 , L_4 , V_5 . V_23 ) ;
for ( V_4 = 0 ; V_4 < 11 ; V_4 ++ )
F_2 ( V_2 , L_5 , V_5 . V_24 [ V_4 ] ) ;
F_3 ( V_2 , '\n' ) ;
F_4 ( V_2 , & V_25 ) ;
#ifdef F_5
F_2 ( V_2 , L_6 , V_26 + 1 ) ;
for ( V_4 = 0 ; V_4 <= V_26 ; V_4 ++ )
F_2 ( V_2 , L_5 , V_5 . V_27 [ V_4 ] ) ;
F_3 ( V_2 , '\n' ) ;
#endif
return 0 ;
}
static int F_6 ( struct V_28 * V_28 , struct V_29 * V_29 )
{
return F_7 ( V_29 , F_1 , NULL ) ;
}
void
F_8 ( void )
{
F_9 ( & V_30 , & V_25 , & V_31 ) ;
}
void
F_10 ( void )
{
F_11 ( & V_30 , L_7 ) ;
}
