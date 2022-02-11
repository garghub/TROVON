static void F_1 ( int V_1 )
{
if ( V_2 > - 1 )
F_2 ( V_2 , - 1 , V_3 ) ;
exit ( 0 ) ;
}
static void F_3 ( unsigned int V_4 )
{
const unsigned int V_5 = 256 ;
unsigned int V_6 = F_4 () ;
T_1 V_7 = time ( NULL ) ;
T_2 V_8 [ V_6 ] , V_9 [ V_5 ] [ V_6 ] ;
T_3 V_10 ;
int V_11 ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
while ( ! V_4 || time ( NULL ) - V_7 <= V_4 ) {
F_5 ( V_12 ) ;
for ( V_10 = 0 ; V_10 < V_5 ; V_10 ++ ) {
T_2 V_13 = 0 ;
assert ( F_6 ( V_14 [ 0 ] , & V_10 , V_8 ) == 0 ) ;
for ( V_11 = 0 ; V_11 < V_6 ; V_11 ++ )
V_13 += ( V_8 [ V_11 ] - V_9 [ V_10 ] [ V_11 ] ) ;
if ( V_13 )
printf ( L_1 ,
V_10 , V_13 , V_13 / V_12 ) ;
memcpy ( V_9 [ V_10 ] , V_8 , sizeof( V_8 ) ) ;
}
}
}
static void F_7 ( const char * V_15 )
{
printf ( L_2
L_3
L_4 ) ;
printf ( L_5 , V_15 ) ;
printf ( L_6 ) ;
printf ( L_7 ) ;
printf ( L_8 ) ;
printf ( L_9 ) ;
printf ( L_10 ) ;
printf ( L_11 ) ;
printf ( L_12 ) ;
printf ( L_13 ) ;
printf ( L_14 ) ;
printf ( L_15 ) ;
printf ( L_16 ) ;
}
static int F_8 ( const char * V_16 , unsigned int * V_17 )
{
if ( F_9 ( V_18 , V_16 , V_17 ) == 1 ) {
return V_18 ;
} else if ( F_9 ( V_19 , V_16 , V_17 ) == 1 ) {
V_17 [ 1 ] = V_17 [ 2 ] = V_17 [ 3 ] = 0 ;
return V_19 ;
}
fprintf ( V_20 , L_17 , V_16 ) ;
return V_21 ;
}
static int F_10 ( const char * V_22 , int * V_23 , int * V_24 )
{
char * V_25 ;
long V_26 ;
long V_27 ;
V_26 = strtol ( V_28 , & V_25 , 10 ) ;
if ( V_26 < 1 || V_26 > 65535 ) {
fprintf ( V_20 , L_18 , V_28 ) ;
return 1 ;
}
if ( * V_25 == '-' ) {
V_25 ++ ;
V_27 = strtol ( V_25 , NULL , 10 ) ;
if ( V_27 < 1 || V_27 > 65535 ) {
fprintf ( V_20 , L_18 , V_28 ) ;
return 1 ;
}
} else {
V_27 = V_26 ;
}
if ( V_26 > V_27 ) {
fprintf ( V_20 , L_18 , V_28 ) ;
return 1 ;
}
if ( V_27 - V_26 + 1 > V_29 ) {
fprintf ( V_20 , L_19 ,
V_22 , V_29 ) ;
return 1 ;
}
* V_23 = V_26 ;
* V_24 = V_27 ;
return 0 ;
}
int main ( int V_30 , char * * V_31 )
{
unsigned char V_32 [ 256 ] = {} ;
unsigned int V_4 = 0 ;
const char * V_33 = L_20 ;
int V_23 = 0 , V_24 = 0 ;
struct V_34 V_35 = {} ;
struct V_36 V_37 = { V_38 , V_38 } ;
struct V_39 V_39 = {} ;
char V_40 [ 256 ] ;
int V_41 ;
int V_11 ;
V_35 . V_42 = V_21 ;
V_39 . V_43 = V_44 ;
for ( V_11 = 0 ; V_11 < strlen ( V_33 ) ; V_11 ++ )
if ( V_33 [ V_11 ] != 'h' && 'a' <= V_33 [ V_11 ] && V_33 [ V_11 ] <= 'z' )
V_32 [ ( unsigned char ) V_33 [ V_11 ] ] = 1 ;
while ( ( V_41 = F_11 ( V_30 , V_31 , V_33 ) ) != - 1 ) {
unsigned short V_42 ;
unsigned int * V_45 ;
switch ( V_41 ) {
case 'i' :
V_2 = atoi ( V_28 ) ;
break;
case 'a' :
V_39 . V_42 = F_8 ( V_28 , V_39 . V_46 . V_45 ) ;
if ( V_39 . V_42 == V_21 )
return 1 ;
break;
case 'p' :
if ( F_10 ( V_28 , & V_23 , & V_24 ) )
return 1 ;
break;
case 'P' :
V_39 . V_43 = atoi ( V_28 ) ;
break;
case 's' :
case 'd' :
if ( V_41 == 's' )
V_45 = V_35 . V_47 . V_45 ;
else
V_45 = V_35 . V_46 . V_45 ;
V_42 = F_8 ( V_28 , V_45 ) ;
if ( V_42 == V_21 )
return 1 ;
if ( V_35 . V_42 == V_21 ) {
V_35 . V_42 = V_42 ;
} else if ( V_35 . V_42 != V_42 ) {
fprintf ( V_20 ,
L_21 ) ;
return 1 ;
}
break;
case 'm' :
if ( ! F_12 ( V_28 ,
(struct V_48 * ) V_35 . V_49 ) ) {
fprintf ( V_20 , L_22 ,
V_28 ) ;
return 1 ;
}
break;
case 'T' :
V_4 = atoi ( V_28 ) ;
break;
case 'S' :
V_3 |= V_50 ;
break;
case 'N' :
V_3 |= V_51 ;
break;
default:
F_7 ( V_31 [ 0 ] ) ;
return 1 ;
}
V_32 [ V_41 ] = 0 ;
}
for ( V_11 = 0 ; V_11 < strlen ( V_33 ) ; V_11 ++ ) {
if ( V_32 [ ( unsigned int ) V_33 [ V_11 ] ] ) {
fprintf ( V_20 , L_23 , V_33 [ V_11 ] ) ;
F_7 ( V_31 [ 0 ] ) ;
return 1 ;
}
}
if ( F_13 ( V_52 , & V_37 ) ) {
perror ( L_24 ) ;
return 1 ;
}
snprintf ( V_40 , sizeof( V_40 ) , L_25 , V_31 [ 0 ] ) ;
if ( F_14 ( V_40 ) ) {
printf ( L_26 , V_53 ) ;
return 1 ;
}
if ( ! V_54 [ 0 ] ) {
printf ( L_27 , strerror ( V_55 ) ) ;
return 1 ;
}
signal ( V_56 , F_1 ) ;
signal ( V_57 , F_1 ) ;
while ( V_23 <= V_24 ) {
V_39 . V_58 = F_15 ( V_23 ++ ) ;
if ( F_16 ( V_14 [ 1 ] , & V_39 , & V_35 , V_59 ) ) {
perror ( L_28 ) ;
return 1 ;
}
}
if ( F_2 ( V_2 , V_54 [ 0 ] , V_3 ) < 0 ) {
printf ( L_29 ) ;
return 1 ;
}
F_3 ( V_4 ) ;
F_2 ( V_2 , - 1 , V_3 ) ;
return 0 ;
}
