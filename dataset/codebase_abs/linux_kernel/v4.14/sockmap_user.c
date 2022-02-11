static int F_1 ( int V_1 , int V_2 )
{
int V_3 , V_4 , V_5 , V_6 , V_7 = 1 ;
int V_8 , V_9 , V_10 , V_11 , V_12 , V_13 ;
struct V_14 V_15 ;
struct V_16 V_17 ;
char V_18 [ 1024 ] = { 0 } ;
int * V_19 [ 4 ] = { & V_8 , & V_9 , & V_10 , & V_11 } ;
T_1 V_20 ;
V_8 = V_9 = V_12 = V_13 = V_10 = V_11 = 0 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
* V_19 [ V_3 ] = F_2 ( V_21 , V_22 , 0 ) ;
if ( * V_19 [ V_3 ] < 0 ) {
perror ( L_1 ) ;
V_5 = * V_19 [ V_3 ] ;
goto V_23;
}
}
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_5 = F_3 ( * V_19 [ V_3 ] , V_24 , V_25 ,
( char * ) & V_7 , sizeof( V_7 ) ) ;
if ( V_5 ) {
perror ( L_2 ) ;
goto V_23;
}
}
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
V_5 = F_4 ( * V_19 [ V_3 ] , V_26 , ( char * ) & V_7 ) ;
if ( V_5 < 0 ) {
perror ( L_3 ) ;
goto V_23;
}
}
memset ( & V_15 , 0 , sizeof( struct V_14 ) ) ;
V_15 . V_27 = V_21 ;
V_15 . V_28 . V_29 = F_5 ( L_4 ) ;
V_15 . V_30 = F_6 ( V_31 ) ;
V_5 = F_7 ( V_8 , (struct V_32 * ) & V_15 , sizeof( V_15 ) ) ;
if ( V_5 < 0 ) {
perror ( L_5 ) ;
goto V_23;
}
V_15 . V_30 = F_6 ( V_33 ) ;
V_5 = F_7 ( V_9 , (struct V_32 * ) & V_15 , sizeof( V_15 ) ) ;
if ( V_5 < 0 ) {
perror ( L_6 ) ;
goto V_23;
}
V_15 . V_30 = F_6 ( V_31 ) ;
V_5 = F_8 ( V_8 , 32 ) ;
if ( V_5 < 0 ) {
perror ( L_7 ) ;
goto V_23;
}
V_15 . V_30 = F_6 ( V_33 ) ;
V_5 = F_8 ( V_9 , 32 ) ;
if ( V_5 < 0 ) {
perror ( L_7 ) ;
goto V_23;
}
V_15 . V_30 = F_6 ( V_31 ) ;
V_5 = F_9 ( V_10 , (struct V_32 * ) & V_15 , sizeof( V_15 ) ) ;
if ( V_5 < 0 && V_34 != V_35 ) {
perror ( L_8 ) ;
goto V_23;
}
V_15 . V_30 = F_6 ( V_33 ) ;
V_5 = F_9 ( V_11 , (struct V_32 * ) & V_15 , sizeof( V_15 ) ) ;
if ( V_5 < 0 && V_34 != V_35 ) {
perror ( L_9 ) ;
goto V_23;
}
V_12 = F_10 ( V_8 , NULL , NULL ) ;
if ( V_12 < 0 ) {
perror ( L_10 ) ;
goto V_23;
}
V_13 = F_10 ( V_9 , NULL , NULL ) ;
if ( V_13 < 0 ) {
perror ( L_10 ) ;
goto V_23;
}
V_6 = V_13 ;
V_17 . V_36 = 10 ;
V_17 . V_37 = 0 ;
printf ( L_11 ) ;
printf ( L_12 ,
V_10 , V_8 , V_11 , V_9 ) ;
V_4 = F_11 ( V_10 , V_18 , sizeof( V_18 ) , 0 ) ;
if ( V_4 < 0 ) {
perror ( L_13 ) ;
goto V_23;
}
do {
int V_38 , V_39 , V_3 ;
F_12 ( & V_20 ) ;
F_13 ( V_10 , & V_20 ) ;
F_13 ( V_11 , & V_20 ) ;
F_13 ( V_12 , & V_20 ) ;
F_13 ( V_13 , & V_20 ) ;
V_38 = F_14 ( V_6 + 1 , & V_20 , NULL , NULL , & V_17 ) ;
if ( V_38 == - 1 ) {
perror ( L_14 ) ;
break;
} else if ( ! V_38 ) {
fprintf ( V_40 , L_15 ) ;
break;
}
for ( V_3 = 0 ; V_3 <= V_6 && V_38 > 0 ; ++ V_3 ) {
if ( ! F_15 ( V_3 , & V_20 ) )
continue;
V_38 -- ;
V_39 = F_16 ( V_3 , V_18 , sizeof( V_18 ) , 0 ) ;
if ( V_39 < 0 ) {
if ( V_34 != V_41 ) {
perror ( L_16 ) ;
break;
}
}
if ( V_39 == 0 ) {
F_17 ( V_3 ) ;
break;
}
V_4 = F_11 ( V_3 , V_18 , V_39 , 0 ) ;
if ( V_4 < 0 ) {
perror ( L_13 ) ;
break;
}
}
F_18 ( V_1 ) ;
if ( V_2 ) {
printf ( L_17 ) ;
fflush ( stdout ) ;
}
} while ( V_42 );
V_23:
F_17 ( V_8 ) ;
F_17 ( V_9 ) ;
F_17 ( V_12 ) ;
F_17 ( V_13 ) ;
F_17 ( V_10 ) ;
F_17 ( V_11 ) ;
return V_5 ;
}
int main ( int V_43 , char * * V_44 )
{
int V_1 = 1 , V_2 = 1 ;
char V_45 [ 256 ] ;
int V_5 , V_46 ;
char * V_47 ;
V_47 = V_44 [ V_43 - 1 ] ;
snprintf ( V_45 , sizeof( V_45 ) , L_18 , V_44 [ 0 ] ) ;
V_42 = 1 ;
signal ( V_48 , V_49 ) ;
if ( F_19 ( V_45 ) ) {
fprintf ( V_40 , L_19 ,
V_45 , strerror ( V_34 ) ) ;
return 1 ;
}
V_46 = F_20 ( V_47 , V_50 , V_51 ) ;
if ( V_46 < 0 ) {
fprintf ( V_40 , L_20 ,
V_46 , V_47 ) ;
return V_46 ;
}
V_5 = F_21 ( V_52 [ 0 ] , V_53 [ 0 ] ,
V_54 , 0 ) ;
if ( V_5 ) {
fprintf ( V_40 , L_21 ,
V_5 , strerror ( V_34 ) ) ;
return V_5 ;
}
V_5 = F_21 ( V_52 [ 1 ] , V_53 [ 0 ] ,
V_55 , 0 ) ;
if ( V_5 ) {
fprintf ( V_40 , L_21 ,
V_5 , strerror ( V_34 ) ) ;
return V_5 ;
}
V_5 = F_21 ( V_52 [ 2 ] , V_46 , V_56 , 0 ) ;
if ( V_5 ) {
fprintf ( V_40 , L_22 ,
V_5 , strerror ( V_34 ) ) ;
return V_5 ;
}
V_5 = F_1 ( V_1 , V_2 ) ;
if ( V_5 ) {
fprintf ( V_40 , L_23 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
void V_49 ( int V_57 )
{
V_42 = 0 ;
}
