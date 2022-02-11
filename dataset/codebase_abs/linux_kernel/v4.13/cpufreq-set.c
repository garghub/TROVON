static void F_1 ( void )
{
printf ( _ ( L_1
L_2
L_3
L_4
L_5
L_6
L_7 ) ) ;
}
static void F_2 ( void )
{
printf ( _ ( L_8 ) ) ;
}
static unsigned long F_3 ( const char * V_1 )
{
char V_2 [ V_3 ] ;
const struct V_4 * V_5 ;
const char * V_6 ;
char * V_7 ;
unsigned long V_8 ;
int V_9 = 0 , V_10 = 0 , V_11 , V_12 , V_13 ;
while ( * V_1 == '0' )
V_1 ++ ;
for ( V_6 = V_1 ; isdigit ( * V_6 ) || * V_6 == '.' ; V_6 ++ ) {
if ( * V_6 == '.' && V_10 == 0 )
V_10 = 1 ;
else if ( * V_6 == '.' && V_10 == 1 )
return 0 ;
}
if ( * V_6 ) {
V_10 = 0 ;
for ( V_5 = V_14 ; V_5 -> V_15 ; V_5 ++ ) {
for ( V_11 = 0 ;
V_6 [ V_11 ] && tolower ( V_6 [ V_11 ] ) == V_5 -> V_15 [ V_11 ] ;
++ V_11 )
continue;
if ( V_6 [ V_11 ] )
continue;
V_10 ++ ;
V_9 = V_5 -> V_16 ;
}
if ( V_10 != 1 )
return 0 ;
}
for ( V_12 = 0 ; isdigit ( V_1 [ V_12 ] ) ; V_12 ++ )
continue;
if ( V_1 [ V_12 ] == '.' ) {
while ( V_9 > - 1 && isdigit ( V_1 [ V_12 + 1 ] ) )
V_12 ++ , V_9 -- ;
}
if ( V_9 >= - 1 )
V_13 = V_9 + 1 ;
else
V_13 = 0 , V_12 += V_9 + 1 ;
if ( V_12 <= 0 || V_12 + V_13 > V_3 - 1 )
return 0 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ , V_1 ++ ) {
if ( * V_1 == '.' )
V_1 ++ ;
V_2 [ V_11 ] = * V_1 ;
}
for (; V_11 < V_12 + V_13 ; V_11 ++ )
V_2 [ V_11 ] = '0' ;
V_10 = ( V_2 [ V_11 - 1 ] >= '5' ) ;
V_2 [ V_11 - 1 ] = 0 ;
V_17 = 0 ;
V_8 = strtoul ( V_2 , & V_7 , 10 ) ;
if ( V_17 )
return 0 ;
else {
if ( V_10 && V_8 != V_18 )
V_8 ++ ;
return V_8 ;
}
}
static int F_4 ( unsigned int V_19 , struct V_20 * V_21 )
{
struct V_20 * V_22 = F_5 ( V_19 ) ;
int V_23 ;
if ( ! V_22 ) {
printf ( _ ( L_9 ) ) ;
return - V_24 ;
}
if ( ! V_21 -> V_25 )
V_21 -> V_25 = V_22 -> V_25 ;
if ( ! V_21 -> V_26 )
V_21 -> V_26 = V_22 -> V_26 ;
if ( ! V_21 -> V_27 )
V_21 -> V_27 = V_22 -> V_27 ;
V_23 = F_6 ( V_19 , V_21 ) ;
F_7 ( V_22 ) ;
return V_23 ;
}
static int F_8 ( unsigned int V_19 , struct V_20 * V_21 ,
unsigned long V_8 , unsigned int V_28 )
{
switch ( V_28 ) {
case 0 :
return F_9 ( V_19 , V_8 ) ;
case 1 :
if ( V_21 -> V_25 )
return F_10 ( V_19 , V_21 -> V_25 ) ;
else if ( V_21 -> V_26 )
return F_11 ( V_19 , V_21 -> V_26 ) ;
else if ( V_21 -> V_27 )
return F_12 ( V_19 ,
V_21 -> V_27 ) ;
default:
return F_4 ( V_19 , V_21 ) ;
}
}
int F_13 ( int V_29 , char * * V_30 )
{
extern char * V_31 ;
extern int V_32 , V_33 , V_34 ;
int V_23 = 0 , V_35 = 1 ;
int V_36 = 0 , V_37 = 0 , V_38 = 0 ;
unsigned long V_8 = 0 ;
char V_39 [ 20 ] ;
unsigned int V_19 ;
struct V_20 V_21 = {
. V_25 = 0 ,
. V_26 = 0 ,
. V_27 = NULL ,
} ;
do {
V_23 = F_14 ( V_29 , V_30 , L_10 , V_40 , NULL ) ;
switch ( V_23 ) {
case '?' :
F_2 () ;
return - V_24 ;
case - 1 :
V_35 = 0 ;
break;
case 'r' :
if ( V_37 )
V_36 ++ ;
V_37 ++ ;
break;
case 'd' :
if ( V_21 . V_25 )
V_36 ++ ;
V_38 ++ ;
V_21 . V_25 = F_3 ( V_31 ) ;
if ( V_21 . V_25 == 0 ) {
F_2 () ;
return - V_24 ;
}
break;
case 'u' :
if ( V_21 . V_26 )
V_36 ++ ;
V_38 ++ ;
V_21 . V_26 = F_3 ( V_31 ) ;
if ( V_21 . V_26 == 0 ) {
F_2 () ;
return - V_24 ;
}
break;
case 'f' :
if ( V_8 )
V_36 ++ ;
V_8 = F_3 ( V_31 ) ;
if ( V_8 == 0 ) {
F_2 () ;
return - V_24 ;
}
break;
case 'g' :
if ( V_21 . V_27 )
V_36 ++ ;
V_38 ++ ;
if ( ( strlen ( V_31 ) < 3 ) || ( strlen ( V_31 ) > 18 ) ) {
F_2 () ;
return - V_24 ;
}
if ( ( sscanf ( V_31 , L_11 , V_39 ) ) != 1 ) {
F_2 () ;
return - V_24 ;
}
V_21 . V_27 = V_39 ;
break;
}
} while ( V_35 );
if ( V_36 ) {
printf ( L_12 ) ;
return - V_24 ;
}
if ( V_8 && V_38 ) {
printf ( _ ( L_13
L_14 ) ) ;
return - V_24 ;
}
if ( ! V_8 && ! V_38 ) {
printf ( _ ( L_15
L_16 ) ) ;
return - V_24 ;
}
if ( F_15 ( V_41 ) )
F_16 ( V_41 ) ;
if ( V_37 ) {
for ( V_19 = F_17 ( V_41 ) ;
V_19 <= F_18 ( V_41 ) ; V_19 ++ ) {
struct V_42 * V_43 ;
if ( ! F_19 ( V_41 , V_19 ) ||
F_20 ( V_19 ) != 1 )
continue;
V_43 = F_21 ( V_19 ) ;
if ( ! V_43 )
break;
while ( V_43 -> V_44 ) {
F_22 ( V_41 , V_43 -> V_19 ) ;
V_43 = V_43 -> V_44 ;
}
F_23 ( V_43 ) ;
}
}
for ( V_19 = F_17 ( V_41 ) ;
V_19 <= F_18 ( V_41 ) ; V_19 ++ ) {
if ( ! F_19 ( V_41 , V_19 ) ||
F_20 ( V_19 ) != 1 )
continue;
printf ( _ ( L_17 ) , V_19 ) ;
V_23 = F_8 ( V_19 , & V_21 , V_8 , V_38 ) ;
if ( V_23 ) {
F_1 () ;
return V_23 ;
}
}
return 0 ;
}
