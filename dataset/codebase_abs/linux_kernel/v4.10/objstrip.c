static void
F_1 ( void )
{
fprintf ( V_1 ,
L_1
L_2 , V_2 , V_2 ) ;
exit ( 1 ) ;
}
int
main ( int V_3 , char * V_4 [] )
{
T_1 V_5 , V_6 , V_7 , V_8 , V_9 , V_10 = 0 ;
int V_11 , V_12 , V_13 , V_14 , V_15 = 0 , V_16 = 0 ;
char V_17 [ 8192 ] , * V_18 ;
struct V_19 * V_20 ;
long V_21 ;
#ifdef F_2
struct V_22 * V_23 ;
struct V_24 * V_24 ;
unsigned long long V_25 ;
#endif
V_2 = V_4 [ 0 ] ;
for ( V_13 = 1 ; V_13 < V_3 && V_4 [ V_13 ] [ 0 ] == '-' ; ++ V_13 ) {
for ( V_14 = 1 ; V_4 [ V_13 ] [ V_14 ] ; ++ V_14 ) {
switch ( V_4 [ V_13 ] [ V_14 ] ) {
case 'v' :
V_15 = ~ V_15 ;
break;
case 'b' :
V_10 = V_26 ;
break;
case 'p' :
V_16 = 1 ;
break;
}
}
}
if ( V_13 >= V_3 ) {
F_1 () ;
}
V_18 = V_4 [ V_13 ++ ] ;
V_11 = F_3 ( V_18 , V_27 ) ;
if ( V_11 == - 1 ) {
perror ( L_3 ) ;
exit ( 1 ) ;
}
V_12 = 1 ;
if ( V_13 < V_3 ) {
V_12 = F_3 ( V_4 [ V_13 ++ ] , V_28 | V_29 | V_30 , 0666 ) ;
if ( V_12 == - 1 ) {
perror ( L_3 ) ;
exit ( 1 ) ;
}
}
if ( V_16 ) {
unsigned long V_31 [ 64 ] , V_32 = 0 ;
struct V_33 V_34 ;
T_2 V_35 ;
int V_13 ;
if ( V_12 == 1 ) {
F_1 () ;
}
if ( F_4 ( V_11 , & V_34 ) == - 1 ) {
perror ( L_4 ) ;
exit ( 1 ) ;
}
V_35 = ( V_34 . V_36 + V_26 - 1 ) & ~ ( V_26 - 1 ) ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
strcpy ( ( char * ) V_31 , L_5 ) ;
V_31 [ 60 ] = V_35 / V_26 ;
V_31 [ 61 ] = 1 ;
V_31 [ 62 ] = 0 ;
for ( V_13 = 0 ; V_13 < 63 ; ++ V_13 ) {
V_32 += V_31 [ V_13 ] ;
}
V_31 [ 63 ] = V_32 ;
if ( F_5 ( V_12 , V_31 , sizeof( V_31 ) ) != sizeof( V_31 ) ) {
perror ( L_6 ) ;
exit ( 1 ) ;
}
printf ( L_7 , V_35 ) ;
return 0 ;
}
if ( F_6 ( V_11 , V_17 , sizeof( V_17 ) ) < 0 ) {
perror ( L_8 ) ;
exit ( 1 ) ;
}
#ifdef F_2
V_23 = (struct V_22 * ) V_17 ;
if ( V_23 -> V_37 [ 0 ] == 0x7f && strncmp ( ( char * ) V_23 -> V_37 + 1 , L_9 , 3 ) == 0 ) {
if ( V_23 -> V_38 != V_39 ) {
fprintf ( V_1 , L_10 ,
V_2 , V_18 ) ;
exit ( 1 ) ;
}
if ( ! F_7 ( V_23 ) ) {
fprintf ( V_1 , L_11 ,
V_2 , V_23 -> V_40 ) ;
exit ( 1 ) ;
}
if ( V_23 -> V_41 != 1 ) {
fprintf ( V_1 ,
L_12 ,
V_2 , V_23 -> V_41 ) ;
}
V_25 = V_23 -> V_25 ;
F_8 ( V_11 , V_23 -> V_42 , V_43 ) ;
if ( F_6 ( V_11 , V_17 , sizeof( * V_24 ) ) != sizeof( * V_24 ) ) {
perror ( L_8 ) ;
exit ( 1 ) ;
}
V_24 = (struct V_24 * ) V_17 ;
V_21 = V_24 -> V_44 ;
V_8 = V_24 -> V_45 ;
V_9 = V_24 -> V_46 ;
if ( V_24 -> V_47 < V_25 ) {
unsigned long V_48 = V_25 - V_24 -> V_47 ;
V_21 += V_48 ;
V_8 -= V_48 ;
V_9 -= V_48 ;
V_24 -> V_47 += V_48 ;
}
if ( V_15 ) {
fprintf ( V_1 , L_13 ,
V_2 , ( long ) V_24 -> V_47 ,
V_24 -> V_47 + V_9 , V_21 ) ;
}
} else
#endif
{
V_20 = (struct V_19 * ) V_17 ;
if ( ! ( V_20 -> V_49 . V_50 & V_51 ) ) {
fprintf ( V_1 , L_14 ,
V_2 , V_18 ) ;
exit ( 1 ) ;
}
if ( V_20 -> V_49 . V_52 != sizeof( V_20 -> V_53 ) ) {
fprintf ( V_1 , L_15 ,
V_2 , V_18 ) ;
exit ( 1 ) ;
}
if ( F_9 ( * V_20 ) != V_54 ) {
fprintf ( V_1 , L_16 ,
V_2 , V_18 ) ;
exit ( 1 ) ;
}
V_21 = F_10 ( * V_20 ) ;
V_9 = V_20 -> V_53 . V_55 + V_20 -> V_53 . V_56 ;
V_8 = V_9 + V_20 -> V_53 . V_57 ;
if ( V_15 ) {
fprintf ( V_1 , L_13 ,
V_2 , V_20 -> V_53 . V_58 ,
V_20 -> V_53 . V_58 + V_9 , V_21 ) ;
}
}
if ( F_8 ( V_11 , V_21 , V_43 ) != V_21 ) {
perror ( L_17 ) ;
exit ( 1 ) ;
}
if ( V_15 ) {
fprintf ( V_1 , L_18 ,
V_2 , ( unsigned long ) V_9 , V_18 ) ;
}
V_6 = V_9 ;
while ( V_6 > 0 ) {
V_7 = V_6 ;
if ( V_7 > sizeof( V_17 ) ) {
V_7 = sizeof( V_17 ) ;
}
V_6 -= V_7 ;
if ( ( T_1 ) F_6 ( V_11 , V_17 , V_7 ) != V_7 ) {
perror ( L_8 ) ;
exit ( 1 ) ;
}
do {
V_5 = F_5 ( V_12 , V_17 , V_7 ) ;
if ( ( V_59 ) V_5 == - 1 ) {
perror ( L_19 ) ;
exit ( 1 ) ;
}
V_7 -= V_5 ;
} while ( V_7 > 0 );
}
if ( V_10 ) {
V_8 = ( ( V_8 + V_10 - 1 ) / V_10 ) * V_10 ;
}
V_6 = V_8 - V_9 ;
if ( V_6 > 0 ) {
fprintf ( V_1 ,
L_20 ,
V_2 , V_10 , ( unsigned long ) V_6 ) ;
memset ( V_17 , 0x00 , sizeof( V_17 ) ) ;
do {
V_7 = V_6 ;
if ( V_7 > sizeof( V_17 ) ) {
V_7 = sizeof( V_17 ) ;
}
V_5 = F_5 ( V_12 , V_17 , V_7 ) ;
if ( ( V_59 ) V_5 == - 1 ) {
perror ( L_19 ) ;
exit ( 1 ) ;
}
V_6 -= V_5 ;
} while ( V_6 > 0 );
}
return 0 ;
}
