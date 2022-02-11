static void F_1 ( const char * V_1 )
{
if ( V_1 )
fprintf ( V_2 , L_1 , V_3 , V_1 ) ;
fprintf ( V_2 , L_2 , V_3 ) ;
fprintf ( V_2 , L_3 ) ;
fprintf ( V_2 , L_4 ) ;
fprintf ( V_2 , L_5 ) ;
fprintf ( V_2 , L_6 ) ;
fprintf ( V_2 , L_7 ) ;
fprintf ( V_2 , L_8 ) ;
exit ( 1 ) ;
}
static void F_2 ( T_1 * V_4 , const char * V_5 , const char * V_6 ,
struct V_7 * V_8 )
{
fprintf ( V_4 , L_9 , V_6 , V_5 ) ;
fprintf ( V_4 , L_10 ,
V_6 , V_8 -> V_9 , V_8 -> V_10 [ 0 ] , V_8 -> V_10 [ 1 ] ,
V_8 -> V_10 [ 2 ] , V_8 -> V_10 [ 3 ] ) ;
fprintf ( V_4 , L_11 , V_6 ,
V_8 -> V_11 , V_8 -> V_12 ) ;
}
static void F_3 ( T_1 * V_4 , struct V_13 * V_13 )
{
fprintf ( V_4 , L_12 ) ;
F_2 ( V_4 , L_13 , L_14 , & V_13 -> V_14 ) ;
F_2 ( V_4 , L_15 , L_14 , & V_13 -> V_15 ) ;
F_2 ( V_4 , L_16 , L_14 , & V_13 -> V_16 ) ;
F_2 ( V_4 , L_17 , L_14 , & V_13 -> V_17 ) ;
F_2 ( V_4 , L_18 , L_14 , & V_13 -> V_18 ) ;
F_2 ( V_4 , L_19 , L_14 , & V_13 -> V_19 ) ;
F_2 ( V_4 , L_20 , L_14 , & V_13 -> V_20 ) ;
F_2 ( V_4 , L_21 , L_14 , & V_13 -> V_21 ) ;
F_2 ( V_4 , L_22 , L_14 , & V_13 -> V_22 ) ;
fprintf ( V_4 , L_23 ,
V_13 -> V_23 , V_13 -> V_24 , V_13 -> V_25 ) ;
fprintf ( V_4 , L_24 ,
V_13 -> V_26 , V_13 -> V_27 , V_13 -> V_28 ) ;
}
static void F_4 ( T_1 * V_4 , const char * V_29 , unsigned long V_30 ,
unsigned char * V_31 , struct V_13 * V_13 )
{
int V_32 ;
fprintf ( V_4 , L_25 , V_29 ) ;
F_3 ( V_4 , V_13 ) ;
fprintf ( V_4 , L_26 ) ;
fprintf ( V_4 , L_27 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
fprintf ( V_4 , L_28 , V_31 [ V_32 ] ) ;
fprintf ( V_4 , L_29 , V_3 ) ;
if ( ! V_34 ) {
fprintf ( V_4 , L_30 ) ;
fprintf ( V_4 , L_31 , V_3 , V_35 , V_30 ) ;
}
}
static void F_5 ( void )
{
int V_36 ;
V_36 = F_6 ( L_32 , V_37 ) ;
if ( V_36 < 0 )
goto V_38;
if ( F_7 ( V_36 , & V_35 , sizeof( V_35 ) ) != sizeof( V_35 ) )
goto V_38;
F_8 ( V_36 ) ;
return;
V_38:
F_1 ( L_33 ) ;
}
static int F_9 ( unsigned char * V_31 )
{
char V_39 [ 256 ] = L_34 , * V_40 ;
int V_32 ;
V_40 = fgets ( V_39 , F_10 ( V_39 ) , V_34 ) ;
if ( V_40 == NULL || feof ( V_34 ) )
return 0 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
V_31 [ V_32 ] = ( unsigned char ) strtoul ( V_40 , & V_40 , 16 ) ;
if ( * V_40 != ' ' )
break;
}
return V_32 ;
}
static int F_11 ( unsigned char * V_31 )
{
int V_32 ;
if ( V_34 )
return F_9 ( V_31 ) ;
for ( V_32 = 0 ; V_32 < V_33 - 1 ; V_32 += 2 )
* ( unsigned short * ) ( & V_31 [ V_32 ] ) = F_12 () & 0xffff ;
while ( V_32 < V_33 )
V_31 [ V_32 ++ ] = F_12 () & 0xff ;
return V_32 ;
}
static void F_13 ( int V_41 , char * * V_42 )
{
int V_43 ;
char * V_40 = NULL ;
int V_44 = 0 ;
V_3 = V_42 [ 0 ] ;
while ( ( V_43 = F_14 ( V_41 , V_42 , L_35 ) ) != - 1 ) {
switch ( V_43 ) {
case 'y' :
V_27 = 1 ;
break;
case 'n' :
V_27 = 0 ;
break;
case 'v' :
V_45 ++ ;
break;
case 'i' :
if ( strcmp ( L_36 , V_46 ) == 0 )
V_34 = V_47 ;
else
V_34 = fopen ( V_46 , L_37 ) ;
if ( ! V_34 )
F_1 ( L_38 ) ;
break;
case 's' :
V_35 = ( unsigned int ) strtoul ( V_46 , & V_40 , 0 ) ;
if ( * V_40 == ',' ) {
V_46 = V_40 + 1 ;
V_48 = strtoul ( V_46 , & V_40 , 0 ) ;
}
if ( * V_40 != '\0' || V_40 == V_46 )
F_1 ( L_39 ) ;
V_44 = 1 ;
break;
case 'm' :
V_49 = strtoul ( V_46 , & V_40 , 0 ) ;
if ( * V_40 != '\0' || V_40 == V_46 )
F_1 ( L_40 ) ;
break;
default:
F_1 ( NULL ) ;
}
}
if ( V_49 < V_48 )
F_1 ( L_41 ) ;
if ( V_44 && V_34 )
F_1 ( L_42 ) ;
if ( ! V_34 ) {
if ( ! V_44 )
F_5 () ;
srand ( V_35 ) ;
}
}
int main ( int V_41 , char * * V_42 )
{
struct V_13 V_13 ;
int V_50 = 0 ;
int V_51 = 0 ;
unsigned long V_32 ;
unsigned char V_31 [ V_33 * 2 ] ;
F_13 ( V_41 , V_42 ) ;
memset ( V_31 + V_33 , V_52 , V_33 ) ;
for ( V_32 = 0 ; V_32 < V_49 ; V_32 ++ ) {
if ( F_11 ( V_31 ) <= 0 )
break;
if ( V_32 < V_48 )
continue;
F_15 ( & V_13 , V_31 , V_27 ) ;
F_16 ( & V_13 ) ;
if ( V_13 . V_53 <= V_13 . V_28 ||
V_13 . V_28 + V_33 < V_13 . V_53 ) {
F_4 ( V_2 , L_43 , V_32 , V_31 , & V_13 ) ;
V_51 ++ ;
} else if ( V_45 && ! F_17 ( & V_13 ) )
F_4 ( stdout , L_44 , V_32 , V_31 , & V_13 ) ;
else if ( V_45 >= 2 )
F_3 ( stdout , & V_13 ) ;
V_50 ++ ;
}
fprintf ( stdout , L_45 ,
V_3 ,
( V_51 ) ? L_46 : L_47 ,
V_50 ,
( V_34 ) ? L_48 : L_49 ,
V_51 ,
V_35 ) ;
return V_51 ? 1 : 0 ;
}
