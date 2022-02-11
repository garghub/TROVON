int
main ( int V_1 , char * * V_2 )
{
int V_3 ;
int V_4 , V_5 ;
int V_6 ;
struct V_7 V_8 ;
T_1 V_9 ;
struct V_10 V_11 ;
if ( V_1 != 2 ) {
fprintf ( V_12 , L_1 ) ;
exit ( 1 ) ;
}
if ( ( V_3 = F_1 ( V_2 [ 1 ] , 2 ) ) == - 1 ) {
perror ( V_2 [ 2 ] ) ;
exit ( 1 ) ;
}
if ( F_2 ( V_3 , & V_8 , sizeof( V_8 ) ) != sizeof( V_8 ) )
goto V_13;
V_4 = F_3 ( V_8 . V_14 ) ;
if ( V_4 != V_15 && V_4 != V_16 && V_4 != V_17 ) {
fprintf ( V_12 , L_2 , V_2 [ 1 ] ) ;
exit ( 1 ) ;
}
V_6 = F_3 ( V_8 . V_18 ) ;
if ( F_2 ( V_3 , & V_9 , V_6 ) != V_6 )
goto V_13;
V_5 = F_3 ( V_8 . V_19 ) ;
for ( V_4 = 0 ; V_4 < V_5 ; ++ V_4 ) {
if ( F_2 ( V_3 , & V_11 , sizeof( V_11 ) ) != sizeof( V_11 ) )
goto V_13;
if ( strcmp ( V_11 . V_20 , L_3 ) == 0 ) {
F_4 ( V_9 . V_21 , V_4 + 1 ) ;
F_4 ( V_9 . V_22 , V_4 + 1 ) ;
} else if ( strcmp ( V_11 . V_20 , L_4 ) == 0 ) {
F_4 ( V_9 . V_23 , V_4 + 1 ) ;
} else if ( strcmp ( V_11 . V_20 , L_5 ) == 0 ) {
F_4 ( V_9 . V_24 , V_4 + 1 ) ;
}
}
F_4 ( V_9 . V_25 , V_26 ) ;
if ( F_5 ( V_3 , ( long ) sizeof( struct V_7 ) , 0 ) == - 1
|| F_6 ( V_3 , & V_9 , V_6 ) != V_6 ) {
fprintf ( V_12 , L_6 , V_2 [ 1 ] ) ;
exit ( 1 ) ;
}
F_7 ( V_3 ) ;
exit ( 0 ) ;
V_13:
fprintf ( V_12 , L_7 , V_2 [ 1 ] ) ;
exit ( 1 ) ;
}
