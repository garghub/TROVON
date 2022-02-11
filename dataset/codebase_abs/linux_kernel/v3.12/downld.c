void F_1 ( int V_1 , int V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
int V_8 ;
struct V_9 V_10 ;
if ( V_4 -> V_11 ) {
V_8 = F_2 ( V_4 -> V_11 , V_12 ) ;
if ( V_8 < 0 ) {
F_3 ( V_4 -> V_11 ) ;
goto V_13;
}
if ( F_4 ( V_8 , & V_10 ) == - 1 ) {
F_3 ( V_4 -> V_11 ) ;
goto V_13;
}
V_4 -> V_14 = V_10 . V_15 ;
}
V_7 = V_4 -> V_14 + sizeof( struct V_5 ) ;
V_6 = (struct V_5 * ) malloc ( V_7 ) ;
if ( V_6 == NULL ) {
fprintf ( V_16 , L_1 ,
V_17 , V_7 ) ;
exit ( 1 ) ;
}
if ( V_4 -> V_11 )
F_5 ( V_8 , V_6 -> V_18 . V_19 . V_20 , V_4 -> V_14 ) ;
else
memcpy ( V_6 -> V_18 . V_19 . V_20 , V_4 -> V_18 , V_4 -> V_14 ) ;
V_6 -> V_1 = V_1 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_18 . V_19 . V_14 = V_4 -> V_14 ;
if ( V_21 )
printf ( L_2 ,
V_4 -> V_14 ,
( V_4 -> type == V_22 ) ? L_3 : ( V_4 -> type == V_23 ) ? L_4 : L_5 ,
V_4 -> V_24 ? V_4 -> V_24 : L_6 ,
( V_4 -> V_11 ) ? V_4 -> V_11 : L_7 ) ;
if ( F_6 ( V_25 , V_26 , ( char * ) V_6 ) == - 1 ) {
if( V_27 ) {
fprintf ( V_16 ,
L_8 , V_17 ) ;
V_27 = 0 ;
}
F_7 ( 2 ) ;
}
V_13:
if ( V_4 -> V_11 ) {
F_8 ( V_8 ) ;
}
free ( V_6 ) ;
}
void F_9 ( struct V_3 * V_4 )
{
int V_8 ;
int V_14 ;
struct V_9 V_10 ;
if ( V_4 -> V_11 ) {
V_8 = F_2 ( V_4 -> V_11 , V_12 ) ;
if ( V_8 < 0 ) {
F_3 ( V_4 -> V_11 ) ;
exit ( 1 ) ;
}
if( F_4 ( V_8 , & V_10 ) == - 1 ) {
F_3 ( V_4 -> V_11 ) ;
exit ( 1 ) ;
}
if ( V_4 -> V_18 && ( V_10 . V_28 == V_4 -> V_29 ) )
goto V_30;
V_4 -> V_14 = V_14 = V_10 . V_15 ;
V_4 -> V_29 = V_10 . V_28 ;
if ( V_4 -> V_18 ) {
free ( V_4 -> V_18 ) ;
}
V_4 -> V_18 = malloc ( V_14 ) ;
if ( V_4 -> V_18 == NULL ) {
fprintf ( V_16 ,
L_1 ,
V_17 , V_14 ) ;
exit ( 1 ) ;
}
if ( F_5 ( V_8 , V_4 -> V_18 , V_14 ) < V_14 ) {
fprintf ( V_16 , L_9 ,
V_17 , V_4 -> V_11 ) ;
exit ( 1 ) ;
}
V_30:
F_8 ( V_8 ) ;
}
}
struct V_3 * F_10 ()
{
int V_31 ;
struct V_3 * V_32 = NULL ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
V_32 = & V_34 [ V_31 ] ;
if( V_32 -> type != V_35 )
continue;
F_9 ( V_32 ) ;
V_36 = (struct V_37 * ) V_34 [ V_31 ] . V_18 ;
if ( V_36 == NULL ) continue;
if ( ( V_38 -> V_39 != 'P' ) && ( V_36 -> V_40 == V_38 -> V_40 ) )
return V_32 ;
}
return NULL ;
}
int main ( int V_41 , char * * V_42 )
{
struct V_5 V_43 ;
int V_44 , V_45 ;
int V_31 ;
char * V_46 , * V_18 , * V_47 ;
struct V_3 * V_4 ;
V_17 = V_42 [ 0 ] ;
V_38 = & V_43 . V_18 . V_48 ;
while( ( V_41 > 2 ) && ! strcmp ( V_42 [ 1 ] , L_10 ) ) {
V_21 ++ ;
V_41 -- ;
V_42 ++ ;
}
if( V_41 < 2 ) {
fprintf ( V_16 ,
L_11 ,
V_17 ) ;
exit ( 1 ) ;
}
if ( V_21 == 0 ) {
switch ( F_11 () )
{
case 0 :
break;
case - 1 :
return 1 ;
default:
return 0 ;
}
F_12 () ;
fclose ( V_49 ) ;
fclose ( stdout ) ;
fclose ( V_16 ) ;
}
while ( 1 ) {
if( ( V_25 = F_2 ( V_42 [ 1 ] , V_50 ) ) == - 1 ) {
F_7 ( 1 ) ;
}
else
break;
}
V_33 = V_41 - 2 ;
for ( V_51 = 0 ; V_52 [ V_51 ] . type != V_53 ; ++ V_51 ) ;
V_33 += V_51 ;
V_34 = V_52 ;
for( V_31 = 2 ; V_31 < V_41 ; V_31 ++ ) {
int V_54 ;
if( ( V_47 = strrchr ( V_42 [ V_31 ] , '/' ) ) == NULL )
V_47 = V_42 [ V_31 ] ;
else
V_47 ++ ;
for ( V_54 = 0 ; V_54 < V_51 ; V_54 ++ ) {
if ( strcmp ( V_47 , V_52 [ V_54 ] . V_47 ) == 0 ) {
V_52 [ V_54 ] . V_11 = V_42 [ V_31 ] ;
V_52 [ V_54 ] . V_18 = NULL ;
}
}
}
F_7 ( 3 ) ;
for(; ; ) {
if ( V_21 )
printf ( L_12 ) ;
if ( F_6 ( V_25 , V_55 , & V_43 ) == - 1 ) {
if ( V_27 ) {
fprintf ( V_16 ,
L_8 ,
V_17 ) ;
V_27 = 0 ;
}
F_7 ( 2 ) ;
} else {
if ( V_21 )
printf ( L_13 ,
V_43 . V_1 , V_43 . V_2 ) ;
switch( V_43 . V_1 ) {
case V_56 :
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
if( V_34 [ V_31 ] . type != V_23 )
continue;
if ( ( V_43 . V_18 . V_19 . type & V_57 ) ==
V_34 [ V_31 ] . V_58 ) {
if ( V_34 [ V_31 ] . V_58 == V_59 ) {
if ( ( V_43 . V_18 . V_19 . type & V_60 )
== V_61 ) {
if ( V_34 [ V_31 ] . V_62
== V_61 )
break;
}
else {
break;
}
}
else if ( V_34 [ V_31 ] . V_58 == V_63 ) {
if ( ( V_43 . V_18 . V_19 . type & V_60 )
== V_61 ) {
if ( V_34 [ V_31 ] . V_62
== V_61 )
break;
}
else {
if ( V_34 [ V_31 ] . V_62
!= V_61 )
break;
}
}
else
break;
}
else if ( ( V_43 . V_18 . V_19 . type & V_64 ) == V_34 [ V_31 ] . V_62 ) {
if ( V_34 [ V_31 ] . V_62 == V_65 ) {
break;
}
}
}
if ( V_31 >= V_33 ) {
if( V_66 ) {
fprintf ( V_16 ,
L_14 ,
V_17 ) ;
V_66 = 0 ;
}
V_43 . V_18 . V_19 . type = - 1 ;
if ( F_6 ( V_25 , V_26 , & V_43 ) == - 1 ) {
if ( V_27 ) {
fprintf ( V_16 ,
L_8 ,
V_17 ) ;
V_27 = 0 ;
}
F_7 ( 2 ) ;
}
break;
}
F_1 ( V_43 . V_1 , V_43 . V_2 , & V_34 [ V_31 ] ) ;
break ;
case V_67 :
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
if( V_34 [ V_31 ] . type != V_22 )
continue;
if( ( V_43 . V_18 . V_19 . type & V_57 ) ==
V_34 [ V_31 ] . V_58 ) {
if ( V_34 [ V_31 ] . V_58 == V_59 ) {
if ( ( V_43 . V_18 . V_19 . type & V_60 )
== V_61 ) {
if ( V_34 [ V_31 ] . V_62
== V_61 )
break;
}
else {
break;
}
}
else if ( V_34 [ V_31 ] . V_58 == V_63 ) {
if ( ( V_43 . V_18 . V_19 . type & V_60 )
== V_61 ) {
if ( V_34 [ V_31 ] . V_62
== V_61 )
break;
}
else {
if ( V_34 [ V_31 ] . V_62
!= V_61 )
break;
}
}
else
break;
}
else if ( ( V_43 . V_18 . V_19 . type & V_64 ) == V_34 [ V_31 ] . V_62 ) {
if ( V_34 [ V_31 ] . V_62 == V_65 ) {
break;
}
}
}
if ( V_31 >= V_33 ) {
if( V_66 ) {
fprintf ( V_16 ,
L_15 ,
V_17 ) ;
V_66 = 0 ;
}
V_43 . V_18 . V_19 . type = - 1 ;
if( F_6 ( V_25 , V_26 , & V_43 ) == - 1 ) {
if( V_27 ) {
fprintf ( V_16 ,
L_8 ,
V_17 ) ;
V_27 = 0 ;
}
F_7 ( 2 ) ;
}
break;
}
F_1 ( V_43 . V_1 , V_43 . V_2 , & V_34 [ V_31 ] ) ;
break;
case V_68 :
{
char string [ 1024 ] ;
#if 0
sprintf(string, "%s /proc/dgap/%d/mknod", DEFSHELL, dlio.bdid);
#endif
sprintf ( string , L_16 , V_69 , V_43 . V_2 ) ;
system ( string ) ;
if ( V_21 )
printf ( L_17 ) ;
if ( F_6 ( V_25 , V_26 , & V_43 ) == - 1 ) {
if( V_27 ) {
fprintf ( V_16 , L_18 , V_17 ) ;
V_27 = 0 ;
}
F_7 ( 2 ) ;
}
if ( V_21 )
printf ( L_19 ) ;
}
break;
case V_70 :
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
if( V_34 [ V_31 ] . type != V_71 )
continue;
else
break;
}
if ( V_31 >= V_33 ) {
if( V_66 ) {
fprintf ( V_16 ,
L_20 ,
V_17 ) ;
V_66 = 0 ;
}
V_43 . V_18 . V_19 . type = - 1 ;
if ( F_6 ( V_25 , V_26 , & V_43 ) == - 1 ) {
if( V_27 ) {
fprintf ( V_16 ,
L_8 ,
V_17 ) ;
V_27 = 0 ;
}
F_7 ( 2 ) ;
}
break;
}
F_1 ( V_43 . V_1 , V_43 . V_2 , & V_34 [ V_31 ] ) ;
break;
case V_72 :
if ( V_38 -> V_73 == 0 ) {
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
V_4 = & V_34 [ V_31 ] ;
if( V_34 [ V_31 ] . type != V_35 )
continue;
F_9 ( V_4 ) ;
V_36 = (struct V_37 * ) V_34 [ V_31 ] . V_18 ;
if ( V_36 == NULL ) continue;
if ( ( V_38 -> V_39 != 'P' ) &&
( V_36 -> V_74 <= V_38 -> V_74 ) &&
( V_38 -> V_74 <= V_36 -> V_75 ) )
break;
}
if ( V_31 >= V_33 ) {
if( V_66 ) {
fprintf ( V_16 ,
L_21 ,
V_17 , V_38 -> V_74 ) ;
V_66 = 0 ;
}
continue;
}
} else {
if ( ( V_4 = F_10 () ) == NULL ) {
fprintf ( V_16 ,
L_22 ,
V_17 ) ;
continue;
}
}
V_44 = 1024 * V_38 -> V_73 ;
if ( V_44 < V_4 -> V_14 ) {
if ( ( V_45 = V_4 -> V_14 - V_44 ) > 1024 )
V_45 = 1024 ;
V_38 -> V_40 = V_36 -> V_40 ;
V_38 -> V_74 = V_36 -> V_74 ;
V_38 -> V_75 = V_36 -> V_75 ;
V_38 -> V_76 = ( 64 * V_38 -> V_73 ) + V_36 -> V_76 ;
V_38 -> V_77 = V_45 ;
V_46 = ( char * ) & V_38 -> V_78 [ 0 ] ;
V_18 = ( char * ) ( ( char * ) V_36 + V_44 ) ;
memcpy ( V_46 , V_18 , V_45 ) ;
}
else {
V_38 -> V_76 = V_36 -> V_76 ;
V_38 -> V_77 = 0 ;
if ( V_4 -> V_11 )
if ( V_4 -> V_18 ) {
free ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
}
}
if ( V_21 )
printf (
L_23 ,
V_38 -> V_73 , V_4 -> V_24 ,
V_4 -> V_11 ? V_4 -> V_11 : L_24 ) ;
if ( F_6 ( V_25 , V_26 , & V_43 ) == - 1 ) {
if ( V_27 ) {
fprintf ( V_16 ,
L_8 ,
V_17 ) ;
V_27 = 0 ;
}
F_7 ( 2 ) ;
}
break;
}
}
if ( V_21 > 1 ) {
printf ( L_25 ) ; fflush ( stdout ) ;
fflush ( V_49 ) ;
while( getchar () != '\n' ) ;
printf ( L_26 ) ;
}
}
}
void F_3 ( char * V_79 )
{
fprintf ( V_16 , L_27 , V_17 , V_79 , strerror ( V_80 ) ) ;
}
