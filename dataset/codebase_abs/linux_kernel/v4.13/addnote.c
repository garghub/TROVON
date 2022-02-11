int
main ( int V_1 , char * * V_2 )
{
int V_3 , V_4 , V_5 ;
unsigned long V_6 , V_7 , V_8 ;
long V_9 , V_10 , V_11 ;
if ( V_1 != 2 ) {
fprintf ( V_12 , L_1 , V_2 [ 0 ] ) ;
exit ( 1 ) ;
}
V_3 = F_1 ( V_2 [ 1 ] , V_13 ) ;
if ( V_3 < 0 ) {
perror ( V_2 [ 1 ] ) ;
exit ( 1 ) ;
}
V_9 = 12 + F_2 ( strlen ( V_14 ) + 1 ) + sizeof( V_15 ) ;
V_10 = 12 + F_2 ( strlen ( V_16 ) + 1 ) + sizeof( V_17 ) ;
V_4 = F_3 ( V_3 , V_18 , sizeof( V_18 ) ) ;
if ( V_4 < 0 ) {
perror ( L_2 ) ;
exit ( 1 ) ;
}
if ( memcmp ( & V_18 [ V_19 + V_20 ] , V_21 , 4 ) != 0 )
goto V_22;
V_23 = V_18 [ V_19 + V_24 ] ;
if ( V_23 != V_25 && V_23 != V_26 )
goto V_22;
V_27 = V_18 [ V_19 + V_28 ] ;
if ( V_27 != V_29 && V_27 != V_30 )
goto V_22;
if ( V_4 < V_31 )
goto V_22;
V_6 = ( V_23 == V_25 ? F_4 ( V_32 ) : F_5 ( V_32 ) ) ;
V_7 = F_6 ( V_33 ) ;
V_8 = F_6 ( V_34 ) ;
if ( V_6 < V_31 || V_7 < V_35 || V_8 < 1 )
goto V_22;
if ( V_6 + ( V_8 + 2 ) * V_7 + V_9 + V_10 > V_4 )
goto V_36;
for ( V_5 = 0 ; V_5 < V_8 ; ++ V_5 ) {
if ( F_4 ( V_6 + V_37 ) == V_38 ) {
fprintf ( V_12 , L_3 ,
V_2 [ 1 ] ) ;
exit ( 0 ) ;
}
V_6 += V_7 ;
}
for ( V_5 = 0 ; V_5 < 2 * V_7 + V_9 + V_10 ; ++ V_5 )
if ( V_18 [ V_6 + V_5 ] != 0 )
goto V_36;
V_11 = V_6 + 2 * V_7 ;
F_7 ( V_6 + V_37 , V_38 ) ;
if ( V_23 == V_25 )
F_7 ( V_6 + V_39 , V_11 ) ;
else
F_8 ( V_6 + V_39 , V_11 ) ;
if ( V_23 == V_25 )
F_7 ( V_6 + V_40 , V_9 ) ;
else
F_8 ( V_6 + V_40 , V_9 ) ;
F_7 ( V_11 , strlen ( V_14 ) + 1 ) ;
F_7 ( V_11 + 4 , V_41 * 4 ) ;
F_7 ( V_11 + 8 , 0x1275 ) ;
strcpy ( ( char * ) & V_18 [ V_11 + 12 ] , V_14 ) ;
V_11 += 12 + strlen ( V_14 ) + 1 ;
for ( V_5 = 0 ; V_5 < V_41 ; ++ V_5 , V_11 += 4 )
F_9 ( V_11 , V_15 [ V_5 ] ) ;
V_6 += V_7 ;
F_7 ( V_6 + V_37 , V_38 ) ;
if ( V_23 == V_25 )
F_7 ( V_6 + V_39 , V_11 ) ;
else
F_8 ( V_6 + V_39 , V_11 ) ;
if ( V_23 == V_25 )
F_7 ( V_6 + V_40 , V_9 ) ;
else
F_8 ( V_6 + V_40 , V_10 ) ;
F_7 ( V_11 , strlen ( V_16 ) + 1 ) ;
F_7 ( V_11 + 4 , sizeof( V_17 ) ) ;
F_7 ( V_11 + 8 , 0x12759999 ) ;
strcpy ( ( char * ) & V_18 [ V_11 + 12 ] , V_16 ) ;
V_11 += 12 + F_2 ( strlen ( V_16 ) + 1 ) ;
for ( V_5 = 0 ; V_5 < V_42 ; ++ V_5 , V_11 += 4 )
F_9 ( V_11 , V_17 [ V_5 ] ) ;
F_10 ( V_34 , V_8 + 2 ) ;
F_11 ( V_3 , ( long ) 0 , V_43 ) ;
V_5 = F_12 ( V_3 , V_18 , V_4 ) ;
if ( V_5 < 0 ) {
perror ( L_4 ) ;
exit ( 1 ) ;
}
if ( V_5 < V_4 ) {
fprintf ( V_12 , L_5 , V_2 [ 1 ] ) ;
exit ( 1 ) ;
}
exit ( 0 ) ;
V_22:
fprintf ( V_12 , L_6 , V_2 [ 1 ] ) ;
exit ( 1 ) ;
V_36:
fprintf ( V_12 , L_7 ,
V_2 [ 1 ] ) ;
exit ( 1 ) ;
}
