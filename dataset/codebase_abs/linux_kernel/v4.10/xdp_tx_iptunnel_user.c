static void F_1 ( int V_1 )
{
if ( V_2 > - 1 )
F_2 ( V_2 , - 1 ) ;
exit ( 0 ) ;
}
static void F_3 ( unsigned int V_3 )
{
const unsigned int V_4 = 256 ;
unsigned int V_5 = F_4 () ;
T_1 V_6 = time ( NULL ) ;
T_2 V_7 [ V_5 ] , V_8 [ V_4 ] [ V_5 ] ;
T_3 V_9 ;
int V_10 ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
while ( ! V_3 || time ( NULL ) - V_6 <= V_3 ) {
F_5 ( V_11 ) ;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ ) {
T_2 V_12 = 0 ;
assert ( F_6 ( V_13 [ 0 ] , & V_9 , V_7 ) == 0 ) ;
for ( V_10 = 0 ; V_10 < V_5 ; V_10 ++ )
V_12 += ( V_7 [ V_10 ] - V_8 [ V_9 ] [ V_10 ] ) ;
if ( V_12 )
printf ( L_1 ,
V_9 , V_12 , V_12 / V_11 ) ;
memcpy ( V_8 [ V_9 ] , V_7 , sizeof( V_7 ) ) ;
}
}
}
static void F_7 ( const char * V_14 )
{
printf ( L_2
L_3
L_4 ) ;
printf ( L_5 , V_14 ) ;
printf ( L_6 ) ;
printf ( L_7 ) ;
printf ( L_8 ) ;
printf ( L_9 ) ;
printf ( L_10 ) ;
printf ( L_11 ) ;
printf ( L_12 ) ;
printf ( L_13 ) ;
printf ( L_14 ) ;
}
static int F_8 ( const char * V_15 , unsigned int * V_16 )
{
if ( F_9 ( V_17 , V_15 , V_16 ) == 1 ) {
return V_17 ;
} else if ( F_9 ( V_18 , V_15 , V_16 ) == 1 ) {
V_16 [ 1 ] = V_16 [ 2 ] = V_16 [ 3 ] = 0 ;
return V_18 ;
}
fprintf ( V_19 , L_15 , V_15 ) ;
return V_20 ;
}
static int F_10 ( const char * V_21 , int * V_22 , int * V_23 )
{
char * V_24 ;
long V_25 ;
long V_26 ;
V_25 = strtol ( V_27 , & V_24 , 10 ) ;
if ( V_25 < 1 || V_25 > 65535 ) {
fprintf ( V_19 , L_16 , V_27 ) ;
return 1 ;
}
if ( * V_24 == '-' ) {
V_24 ++ ;
V_26 = strtol ( V_24 , NULL , 10 ) ;
if ( V_26 < 1 || V_26 > 65535 ) {
fprintf ( V_19 , L_16 , V_27 ) ;
return 1 ;
}
} else {
V_26 = V_25 ;
}
if ( V_25 > V_26 ) {
fprintf ( V_19 , L_16 , V_27 ) ;
return 1 ;
}
if ( V_26 - V_25 + 1 > V_28 ) {
fprintf ( V_19 , L_17 ,
V_21 , V_28 ) ;
return 1 ;
}
* V_22 = V_25 ;
* V_23 = V_26 ;
return 0 ;
}
int main ( int V_29 , char * * V_30 )
{
unsigned char V_31 [ 256 ] = {} ;
unsigned int V_3 = 0 ;
const char * V_32 = L_18 ;
int V_22 = 0 , V_23 = 0 ;
struct V_33 V_34 = {} ;
struct V_35 V_36 = { V_37 , V_37 } ;
struct V_38 V_38 = {} ;
char V_39 [ 256 ] ;
int V_40 ;
int V_10 ;
V_34 . V_41 = V_20 ;
V_38 . V_42 = V_43 ;
for ( V_10 = 0 ; V_10 < strlen ( V_32 ) ; V_10 ++ )
if ( V_32 [ V_10 ] != 'h' && 'a' <= V_32 [ V_10 ] && V_32 [ V_10 ] <= 'z' )
V_31 [ ( unsigned char ) V_32 [ V_10 ] ] = 1 ;
while ( ( V_40 = F_11 ( V_29 , V_30 , V_32 ) ) != - 1 ) {
unsigned short V_41 ;
unsigned int * V_44 ;
switch ( V_40 ) {
case 'i' :
V_2 = atoi ( V_27 ) ;
break;
case 'a' :
V_38 . V_41 = F_8 ( V_27 , V_38 . V_45 . V_44 ) ;
if ( V_38 . V_41 == V_20 )
return 1 ;
break;
case 'p' :
if ( F_10 ( V_27 , & V_22 , & V_23 ) )
return 1 ;
break;
case 'P' :
V_38 . V_42 = atoi ( V_27 ) ;
break;
case 's' :
case 'd' :
if ( V_40 == 's' )
V_44 = V_34 . V_46 . V_44 ;
else
V_44 = V_34 . V_45 . V_44 ;
V_41 = F_8 ( V_27 , V_44 ) ;
if ( V_41 == V_20 )
return 1 ;
if ( V_34 . V_41 == V_20 ) {
V_34 . V_41 = V_41 ;
} else if ( V_34 . V_41 != V_41 ) {
fprintf ( V_19 ,
L_19 ) ;
return 1 ;
}
break;
case 'm' :
if ( ! F_12 ( V_27 ,
(struct V_47 * ) V_34 . V_48 ) ) {
fprintf ( V_19 , L_20 ,
V_27 ) ;
return 1 ;
}
break;
case 'T' :
V_3 = atoi ( V_27 ) ;
break;
default:
F_7 ( V_30 [ 0 ] ) ;
return 1 ;
}
V_31 [ V_40 ] = 0 ;
}
for ( V_10 = 0 ; V_10 < strlen ( V_32 ) ; V_10 ++ ) {
if ( V_31 [ ( unsigned int ) V_32 [ V_10 ] ] ) {
fprintf ( V_19 , L_21 , V_32 [ V_10 ] ) ;
F_7 ( V_30 [ 0 ] ) ;
return 1 ;
}
}
if ( F_13 ( V_49 , & V_36 ) ) {
perror ( L_22 ) ;
return 1 ;
}
snprintf ( V_39 , sizeof( V_39 ) , L_23 , V_30 [ 0 ] ) ;
if ( F_14 ( V_39 ) ) {
printf ( L_24 , V_50 ) ;
return 1 ;
}
if ( ! V_51 [ 0 ] ) {
printf ( L_25 , strerror ( V_52 ) ) ;
return 1 ;
}
signal ( V_53 , F_1 ) ;
while ( V_22 <= V_23 ) {
V_38 . V_54 = F_15 ( V_22 ++ ) ;
if ( F_16 ( V_13 [ 1 ] , & V_38 , & V_34 , V_55 ) ) {
perror ( L_26 ) ;
return 1 ;
}
}
if ( F_2 ( V_2 , V_51 [ 0 ] ) < 0 ) {
printf ( L_27 ) ;
return 1 ;
}
F_3 ( V_3 ) ;
F_2 ( V_2 , - 1 ) ;
return 0 ;
}
