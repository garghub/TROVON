static void F_1 ( void )
{
fprintf ( V_1 , L_1 , V_2 ) ;
exit ( 1 ) ;
}
static T_1 * F_2 ( int type , char * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
if ( V_6 [ V_4 ] . type == type && ! strcmp ( V_6 [ V_4 ] . V_3 , V_3 ) )
return V_6 + V_4 ;
}
V_6 [ V_5 ] . type = type ;
V_6 [ V_5 ] . V_3 = F_3 ( V_3 ) ;
V_6 [ V_5 ] . V_7 = 0 ;
if ( ! V_6 [ V_5 ] . V_3 ) F_1 () ;
V_6 [ V_5 ] . V_8 = NULL ;
V_5 ++ ;
if ( V_5 >= V_9 ) {
fprintf ( V_1 , L_2 , V_9 ) ;
exit ( 1 ) ;
}
return V_6 + V_5 - 1 ;
}
static void F_4 ( char * V_2 )
{
for ( V_10 = 0 ; ; V_10 ++ )
if ( V_2 [ V_10 ] < '0' || V_2 [ V_10 ] > '9' )
break;
if ( V_10 != 8 && V_10 != 16 )
F_1 () ;
}
int main ( int V_11 , char * * V_12 )
{
char * V_13 , * V_14 ;
char * V_15 ;
int V_4 , V_16 , V_17 ;
unsigned int V_18 ;
int V_19 ;
T_1 * V_20 ;
T_2 * V_21 , * * V_22 ;
unsigned long V_23 ;
char * V_24 ;
V_25 = strlen ( V_26 ) ;
while ( fgets ( V_2 , 1024 , V_27 ) != NULL )
if ( ! strncmp ( V_2 , V_26 , V_25 ) )
goto V_28;
F_1 () ;
V_28:
V_29 = strlen ( V_30 ) ;
while ( fgets ( V_2 , 1024 , V_27 ) != NULL )
if ( ! strncmp ( V_2 , V_30 , V_29 ) )
goto V_31;
F_1 () ;
V_31:
V_15 = malloc ( strlen ( V_2 + V_29 ) + 1 ) ;
if ( ! V_15 ) F_1 () ;
strcpy ( V_15 , V_2 + V_29 ) ;
V_13 = strchr ( V_15 , ']' ) ;
if ( ! V_13 ) F_1 () ;
* V_13 = 0 ;
if ( fgets ( V_2 , 1024 , V_27 ) == NULL )
F_1 () ;
while ( fgets ( V_2 , 1024 , V_27 ) != NULL ) {
int V_32 ;
if ( ! strncmp ( V_2 , V_30 , V_29 ) )
goto V_31;
if ( V_10 == 0 )
F_4 ( V_2 ) ;
V_13 = strchr ( V_2 , '\n' ) ;
if ( V_13 ) * V_13 = 0 ;
if ( strlen ( V_2 ) < 22 + V_10 )
continue;
if ( strncmp ( V_2 + V_10 , L_3 , 9 ) )
continue;
V_32 = 27 - 8 + V_10 ;
if ( V_2 [ V_32 ] != '_' || V_2 [ V_32 + 1 ] != '_' || V_2 [ V_32 + 2 ] != '_' )
continue;
switch ( V_2 [ V_32 + 3 ] ) {
case 'f' :
case 'b' :
case 's' :
case 'a' :
case 'h' :
case 'i' :
break;
default:
continue;
}
V_13 = strchr ( V_2 + V_32 + 5 , '+' ) ;
if ( V_13 ) * V_13 = 0 ;
V_19 = V_32 + 5 ;
if ( V_2 [ V_32 + 4 ] == 's' && V_2 [ V_32 + 5 ] == '_' ) {
V_19 = V_32 + 6 ;
if ( strcmp ( V_15 , L_4 ) ) {
fprintf ( V_1 ,
L_5
L_6
L_7 ,
V_2 + V_19 , V_15 ) ;
exit ( 1 ) ;
}
} else if ( V_2 [ V_32 + 4 ] != '_' )
continue;
if ( ! strcmp ( V_15 , L_8 ) )
continue;
if ( strcmp ( V_15 , L_9 ) &&
strcmp ( V_15 , L_4 ) &&
strcmp ( V_15 , L_10 ) &&
( strcmp ( V_15 , L_11 ) || V_2 [ V_32 + 3 ] != 'f' ) ) {
if ( V_2 [ V_32 + 3 ] == 'f' )
fprintf ( V_1 ,
L_12
L_13
L_14 ,
V_2 + V_19 , V_15 ) ;
else
fprintf ( V_1 ,
L_12
L_15
L_16 , V_2 + V_19 , V_15 ) ;
exit ( 1 ) ;
}
V_13 = strstr ( V_2 + V_19 , L_17 ) ;
if ( V_13 && V_2 [ V_32 + 4 ] == 's' ) {
fprintf ( V_1 , L_18 , V_2 ) ;
exit ( 1 ) ;
}
V_18 = 0 ;
V_24 = NULL ;
if ( V_13 ) {
if ( V_13 [ 8 ] != '0' || V_13 [ 9 ] != 'x' ) {
fprintf ( V_1 , L_19 , V_2 ) ;
exit ( 1 ) ;
}
V_18 = strtoul ( V_13 + 10 , & V_14 , 16 ) ;
if ( * V_14 || ! V_18 ) {
fprintf ( V_1 , L_20 , V_2 ) ;
exit ( 1 ) ;
}
V_24 = V_13 + 10 ;
* V_13 = 0 ;
}
V_20 = F_2 ( V_2 [ V_32 + 3 ] , V_2 + V_19 ) ;
if ( V_2 [ V_32 + 4 ] == 's' )
continue;
switch ( V_2 [ V_32 + 3 ] ) {
case 'f' :
if ( V_18 ) {
fprintf ( V_1 , L_21 , V_2 ) ;
exit ( 1 ) ;
}
if ( ! strcmp ( V_15 , L_11 ) ) {
if ( strncmp ( V_2 + V_10 + 9 , L_22 , 10 ) ) {
fprintf ( V_1 , L_23 , V_2 ) ;
exit ( 1 ) ;
}
} else if ( strncmp ( V_2 + V_10 + 9 , L_24 , 10 ) &&
strncmp ( V_2 + V_10 + 9 , L_25 , 10 ) &&
strncmp ( V_2 + V_10 + 9 , L_26 , 10 ) ) {
fprintf ( V_1 , L_27 , V_2 ) ;
exit ( 1 ) ;
}
break;
case 'b' :
if ( V_18 ) {
fprintf ( V_1 , L_28 , V_2 ) ;
exit ( 1 ) ;
}
if ( strncmp ( V_2 + V_10 + 9 , L_25 , 10 ) ) {
fprintf ( V_1 , L_29 , V_2 ) ;
exit ( 1 ) ;
}
break;
case 's' :
if ( V_18 + 0x1000 >= 0x2000 ) {
fprintf ( V_1 , L_30 , V_2 ) ;
exit ( 1 ) ;
}
if ( strncmp ( V_2 + V_10 + 9 , L_31 , 10 ) ) {
fprintf ( V_1 , L_32 , V_2 ) ;
exit ( 1 ) ;
}
break;
case 'a' :
if ( V_18 + 0x1000 >= 0x2000 && ( V_18 & 0x3ff ) ) {
fprintf ( V_1 , L_33 , V_2 ) ;
exit ( 1 ) ;
}
if ( strncmp ( V_2 + V_10 + 9 , L_31 , 10 ) ) {
fprintf ( V_1 , L_34 , V_2 ) ;
exit ( 1 ) ;
}
break;
case 'h' :
if ( V_18 & 0x3ff ) {
fprintf ( V_1 , L_35 , V_2 ) ;
exit ( 1 ) ;
}
if ( strncmp ( V_2 + V_10 + 9 , L_25 , 10 ) ) {
fprintf ( V_1 , L_36 , V_2 ) ;
exit ( 1 ) ;
}
break;
case 'i' :
if ( V_18 ) {
fprintf ( V_1 , L_37 , V_2 ) ;
exit ( 1 ) ;
}
if ( strncmp ( V_2 + V_10 + 9 , L_25 , 10 ) && strncmp ( V_2 + V_10 + 9 , L_26 , 10 ) ) {
fprintf ( V_1 , L_38 , V_2 ) ;
exit ( 1 ) ;
}
break;
}
if ( ! V_20 -> V_7 ) {
V_20 -> V_18 = V_18 ;
if ( V_24 ) {
V_20 -> V_24 = F_3 ( V_24 ) ;
if ( ! V_20 -> V_24 ) F_1 () ;
}
V_20 -> V_7 = 1 ;
} else if ( V_20 -> V_18 != V_18 ) {
fprintf ( V_1 , L_39 ,
V_20 -> V_3 , V_20 -> V_24 ? : L_40 , V_2 ) ;
exit ( 1 ) ;
} else if ( V_18 && strcmp ( V_20 -> V_24 , V_24 ) ) {
fprintf ( V_1 , L_41
L_42 ,
V_20 -> V_3 , V_20 -> V_24 , V_2 ) ;
exit ( 1 ) ;
}
V_23 = strtoul ( V_2 , & V_14 , 16 ) ;
if ( V_14 != V_2 + V_10 || ( ! V_23 && ( V_10 == 8 ? strncmp ( V_2 , L_43 , 9 ) : strncmp ( V_2 , L_44 , 17 ) ) ) ) {
fprintf ( V_1 , L_45 , V_2 ) ;
exit ( 1 ) ;
}
for ( V_17 = 0 , V_21 = V_20 -> V_8 , V_22 = & V_20 -> V_8 ; V_21 ; V_22 = & V_21 -> V_33 , V_21 = V_21 -> V_33 , V_17 ++ )
if ( V_21 -> V_23 == V_23 && ! strcmp ( V_21 -> V_15 , V_15 ) ) {
fprintf ( V_1 , L_46 ) ;
exit ( 1 ) ;
}
* V_22 = malloc ( sizeof( T_2 ) ) ;
if ( ! * V_22 ) F_1 () ;
( * V_22 ) -> V_23 = V_23 ;
( * V_22 ) -> V_20 = NULL ;
if ( V_2 [ V_32 + 3 ] == 'f' ) {
V_34 = V_20 ;
V_35 = V_23 ;
V_36 = V_17 ;
} else if ( V_35 + 4 == V_23 ) {
( * V_22 ) -> V_20 = V_34 ;
( * V_22 ) -> V_37 = V_36 ;
}
( * V_22 ) -> V_15 = V_15 ;
( * V_22 ) -> V_33 = NULL ;
}
printf ( L_47 ) ;
printf ( L_48 ) ;
printf ( L_49 ) ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
V_20 = V_6 + V_4 ;
printf ( L_50 , V_20 -> type , V_20 -> V_3 ) ;
if ( V_20 -> type == 'f' )
printf ( L_51 , V_20 -> type , V_20 -> V_3 , V_20 -> type << 24 ) ;
else
printf ( L_52 , V_20 -> type , V_20 -> V_3 , V_20 -> type << 24 ) ;
for ( V_16 = 0 , V_21 = V_20 -> V_8 ; V_21 != NULL ; V_16 ++ , V_21 = V_21 -> V_33 ) ;
if ( V_16 )
printf ( L_53 , V_16 * 2 ) ;
else
printf ( L_54 ) ;
for ( V_21 = V_20 -> V_8 , V_16 -- ; V_21 != NULL ; V_16 -- , V_21 = V_21 -> V_33 ) {
if ( ! strcmp ( V_21 -> V_15 , L_9 ) )
printf ( L_55 , V_21 -> V_23 ) ;
else if ( ! strcmp ( V_21 -> V_15 , L_4 ) )
printf ( L_56 , V_21 -> V_23 ) ;
else if ( ! strcmp ( V_21 -> V_15 , L_11 ) )
printf ( L_57 , V_21 -> V_23 ) ;
else if ( ! strcmp ( V_21 -> V_15 , L_10 ) )
printf ( L_58 , V_21 -> V_23 ) ;
else
F_1 () ;
if ( V_20 -> type == 'f' || ! V_21 -> V_20 )
printf ( L_59 ) ;
else
printf ( L_60 , V_21 -> V_20 -> V_3 , ( 4 + V_21 -> V_37 * 2 ) * 4 + 4 ) ;
if ( V_16 ) printf ( L_61 ) ;
else printf ( L_62 ) ;
}
printf ( L_62 ) ;
}
printf ( L_63 ) ;
printf ( L_64 ) ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
V_20 = V_6 + V_4 ;
if ( V_20 -> type == 'f' ) {
printf ( L_65 , V_20 -> V_3 ) ;
printf ( L_66 , V_20 -> V_3 ) ;
}
}
printf ( L_67 ) ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
V_20 = V_6 + V_4 ;
if ( V_20 -> type != 'f' ) {
if ( ! V_20 -> V_18 ) {
printf ( L_68 , V_20 -> type , V_20 -> V_3 ) ;
printf ( L_69 , V_20 -> type , V_20 -> V_3 ) ;
} else {
printf ( L_70 , V_20 -> type , V_20 -> V_3 , V_20 -> V_24 ) ;
printf ( L_71 , V_20 -> type , V_20 -> V_3 , V_20 -> V_24 , V_20 -> V_18 ) ;
}
}
}
printf ( L_72 ) ;
exit ( 0 ) ;
}
