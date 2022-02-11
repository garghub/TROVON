main ( T_1 , T_2 )
int T_1 ;
char * T_2 [] ;
{
T_3 V_1 ;
T_4 V_2 ;
T_5 V_3 , V_4 , V_5 , V_6 , V_7 , V_8 , V_9 , V_10 ;
int V_11 ;
F_1 () ;
F_2 () ;
F_3 ( & V_1 ) ;
F_4 ( & V_2 ) ;
F_5 ( & V_7 ) ;
F_5 ( & V_8 ) ;
F_5 ( & V_6 ) ;
F_5 ( & V_5 ) ;
F_5 ( & V_3 ) ;
F_5 ( & V_4 ) ;
{
F_6 ( & V_3 , V_12 , 0 , 0 ) ;
F_6 ( & V_4 , V_13 , 0 , 0 ) ;
V_3 . V_14 = 1 ;
F_7 ( & V_2 , & V_4 , & V_1 ) ;
F_8 ( stdout , & V_3 ) ; printf ( L_1 ) ;
F_8 ( stdout , & V_4 ) ; printf ( L_2 ) ;
F_8 ( stdout , & V_2 . V_15 ) ; printf ( L_3 ) ;
F_8 ( stdout , & V_2 . V_16 ) ; printf ( L_4 , V_2 . V_17 ) ;
F_9 ( & V_7 , & V_6 , & V_3 , & V_2 , & V_1 ) ;
for ( V_11 = 0 ; V_11 < 300 ; V_11 ++ )
F_10 ( & V_8 , & V_5 , & V_3 , & V_4 , & V_1 ) ;
F_8 ( stdout , & V_7 ) ; printf ( L_5 ) ;
F_8 ( stdout , & V_8 ) ; printf ( L_6 ) ;
F_8 ( stdout , & V_6 ) ; printf ( L_7 ) ;
F_8 ( stdout , & V_5 ) ; printf ( L_8 ) ;
}
F_11 ( & V_1 ) ;
F_12 ( & V_2 ) ;
F_13 ( & V_7 ) ;
F_13 ( & V_8 ) ;
F_13 ( & V_6 ) ;
F_13 ( & V_5 ) ;
F_13 ( & V_3 ) ;
F_13 ( & V_4 ) ;
{
T_6 * V_18 ;
if ( ( V_18 = F_14 ( F_15 () ) ) != NULL )
F_16 ( V_18 , V_19 , V_20 | V_21 ) ;
F_17 ( V_18 ) ;
F_18 ( V_18 ) ;
}
}
