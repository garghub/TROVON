static int F_1 ( unsigned int V_1 , double * V_2 ,
unsigned int V_3 )
{
unsigned long long V_4 = V_5 [ V_3 ] [ V_1 ]
- V_6 [ V_3 ] [ V_1 ] ;
F_2 ( L_1 ,
V_7 [ V_1 ] . V_8 , V_9 , * V_2 , V_3 ) ;
if ( V_9 == 0 )
* V_2 = 0.0 ;
else
* V_2 = ( ( 100.0 * V_4 ) / V_9 ) ;
F_2 ( L_2 ,
V_7 [ V_1 ] . V_8 , V_9 , V_4 , * V_2 , V_3 ) ;
return 0 ;
}
static int F_3 ( void )
{
int V_3 , V_10 ;
F_4 ( V_11 , & V_12 ) ;
for ( V_3 = 0 ; V_3 < V_13 ; V_3 ++ ) {
for ( V_10 = 0 ; V_10 < V_14 . V_15 ;
V_10 ++ ) {
V_6 [ V_3 ] [ V_10 ] =
F_5 ( V_3 , V_10 ) ;
F_2 ( L_3 ,
V_3 , V_10 , V_6 [ V_3 ] [ V_10 ] ) ;
}
} ;
return 0 ;
}
static int F_6 ( void )
{
int V_3 , V_10 ;
struct V_16 V_17 ;
F_4 ( V_11 , & V_17 ) ;
V_9 = F_7 ( V_12 , V_17 ) ;
for ( V_3 = 0 ; V_3 < V_13 ; V_3 ++ ) {
for ( V_10 = 0 ; V_10 < V_14 . V_15 ;
V_10 ++ ) {
V_5 [ V_3 ] [ V_10 ] =
F_5 ( V_3 , V_10 ) ;
F_2 ( L_3 ,
V_3 , V_10 , V_6 [ V_3 ] [ V_10 ] ) ;
}
} ;
return 0 ;
}
void F_8 ( char * V_18 , int V_19 )
{
if ( ! strncmp ( V_18 , L_4 , 4 ) ) {
switch ( V_19 ) {
case 1 :
strcpy ( V_18 , L_5 ) ;
break;
case 2 :
strcpy ( V_18 , L_6 ) ;
break;
case 3 :
strcpy ( V_18 , L_7 ) ;
break;
}
} else if ( ! strncmp ( V_18 , L_8 , 4 ) ) {
switch ( V_19 ) {
case 1 :
strcpy ( V_18 , L_5 ) ;
break;
case 2 :
strcpy ( V_18 , L_6 ) ;
break;
case 3 :
strcpy ( V_18 , L_7 ) ;
break;
case 4 :
strcpy ( V_18 , L_9 ) ;
break;
}
} else if ( ! strncmp ( V_18 , L_10 , 4 ) ) {
switch ( V_19 ) {
case 1 :
strcpy ( V_18 , L_5 ) ;
break;
case 2 :
strcpy ( V_18 , L_11 ) ;
break;
case 3 :
strcpy ( V_18 , L_12 ) ;
break;
case 4 :
strcpy ( V_18 , L_7 ) ;
break;
}
}
}
static struct V_20 * F_9 ( void )
{
int V_19 ;
char * V_18 ;
V_14 . V_15 = F_10 ( 0 ) ;
if ( V_14 . V_15 <= 0 )
return NULL ;
for ( V_19 = 0 ; V_19 < V_14 . V_15 ; V_19 ++ ) {
V_18 = F_11 ( 0 , V_19 ) ;
if ( V_18 == NULL )
continue;
F_8 ( V_18 , V_19 ) ;
strncpy ( V_7 [ V_19 ] . V_8 , V_18 , V_21 - 1 ) ;
free ( V_18 ) ;
V_18 = F_12 ( 0 , V_19 ) ;
if ( V_18 == NULL )
continue;
strncpy ( V_7 [ V_19 ] . V_22 , V_18 , V_23 - 1 ) ;
free ( V_18 ) ;
V_7 [ V_19 ] . V_24 = V_25 ;
V_7 [ V_19 ] . V_1 = V_19 ;
V_7 [ V_19 ] . V_26 =
F_1 ;
} ;
V_6 = malloc ( sizeof( long long * ) * V_13 ) ;
V_5 = malloc ( sizeof( long long * ) * V_13 ) ;
for ( V_19 = 0 ; V_19 < V_13 ; V_19 ++ ) {
V_6 [ V_19 ] = malloc ( sizeof( long long ) *
V_14 . V_15 ) ;
V_5 [ V_19 ] = malloc ( sizeof( long long ) *
V_14 . V_15 ) ;
}
V_14 . V_27 = strlen ( V_14 . V_8 ) ;
return & V_14 ;
}
void F_13 ( void )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_13 ; V_19 ++ ) {
free ( V_6 [ V_19 ] ) ;
free ( V_5 [ V_19 ] ) ;
}
free ( V_6 ) ;
free ( V_5 ) ;
}
