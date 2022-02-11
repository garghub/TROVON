static int
F_1 ( char * V_1 , int V_2 )
{
int V_3 ;
int V_4 , V_5 , V_6 ;
for ( V_3 = 0 ; V_3 < V_2 ; ++ V_3 ) {
V_5 = * V_1 ++ ;
V_6 = * V_1 ++ ;
V_4 = 100 * V_7 [ V_5 ] * V_8 ;
printf ( L_1 ,
V_3 ,
V_4 ,
V_5 , V_7 [ V_5 ] / 10 , V_7 [ V_5 ] % 10 ,
V_6 , V_9 [ V_6 ] ) ;
}
return 0 ;
}
static
void F_2 ( char * V_1 , int V_10 )
{
int V_3 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
V_12 = (struct V_11 * ) V_1 ;
if ( V_12 -> V_15 != 0x12 )
return;
printf ( L_2 ,
V_12 -> V_15 ,
V_12 -> V_16 ,
V_12 -> V_17 ,
V_12 -> V_18 ,
V_12 -> V_10 ) ;
V_19 = V_12 -> V_17 * 100 ;
if ( V_19 < 10000 )
V_19 = 10000 ;
V_1 = ( ( char * ) V_12 ) + sizeof( struct V_11 ) ;
if ( V_10 < 0 )
V_10 = V_12 -> V_10 ;
else
printf ( L_3 , V_10 ) ;
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
V_14 = (struct V_13 * ) V_1 ;
if ( V_20 != 0 ) {
if ( V_20 != V_14 -> V_21 )
goto V_22;
}
printf ( L_4 ,
V_3 + 1 ,
V_14 -> V_21 ,
V_14 -> V_8 ,
V_14 -> V_23 ,
V_14 -> V_24 ,
V_14 -> V_25 ) ;
V_8 = V_14 -> V_8 ;
F_1 ( V_1 + sizeof( struct V_13 ) , V_14 -> V_25 ) ;
V_22:
V_1 += sizeof( struct V_13 ) + 2 * V_14 -> V_25 ;
}
}
void F_3 ( void )
{
printf ( L_5 ) ;
printf ( L_6 ) ;
printf ( L_7 ) ;
printf ( L_8 ) ;
}
int
main ( int V_26 , char * V_27 [] )
{
int V_28 ;
int V_10 = - 1 ;
int V_29 = 0 , V_30 = 1 ;
char * V_31 = NULL ;
char * V_1 ;
do {
V_29 = F_4 ( V_26 , V_27 , L_9 , V_32 , NULL ) ;
switch ( V_29 ) {
case '?' :
case 'h' :
F_3 () ;
V_30 = 0 ;
break;
case 'r' :
V_20 = strtol ( V_33 , NULL , 16 ) ;
break;
case 'n' :
V_10 = strtol ( V_33 , NULL , 10 ) ;
break;
case - 1 :
V_30 = 0 ;
break;
}
} while( V_30 );
V_28 = F_5 ( L_10 , V_34 ) ;
if ( V_28 < 0 ) {
printf ( L_11 ) ;
exit ( 1 ) ;
}
V_31 = F_6 ( V_31 , 0x100000 - 0xc0000 , V_35 , V_36 , V_28 , 0xc0000 ) ;
F_7 ( V_28 ) ;
for ( V_1 = V_31 ; V_1 - V_31 < V_37 ; V_1 += 16 ) {
if ( memcmp ( V_1 , L_12 , 10 ) == 0 ) {
F_2 ( V_1 , V_10 ) ;
break;
}
}
F_8 ( V_31 , V_37 ) ;
return 0 ;
}
