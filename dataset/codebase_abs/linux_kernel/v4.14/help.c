void F_1 ( struct V_1 * V_2 , const char * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = malloc ( sizeof( * V_6 ) + V_4 + 1 ) ;
V_6 -> V_4 = V_4 ;
memcpy ( V_6 -> V_3 , V_3 , V_4 ) ;
V_6 -> V_3 [ V_4 ] = 0 ;
F_2 ( V_2 -> V_7 , V_2 -> V_8 + 1 , V_2 -> V_9 ) ;
V_2 -> V_7 [ V_2 -> V_8 ++ ] = V_6 ;
}
void F_3 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_8 ; ++ V_10 )
F_4 ( & V_2 -> V_7 [ V_10 ] ) ;
F_4 ( & V_2 -> V_7 ) ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
}
int F_5 ( const void * V_11 , const void * V_12 )
{
struct V_5 * V_13 = * (struct V_5 * * ) V_11 ;
struct V_5 * V_14 = * (struct V_5 * * ) V_12 ;
return strcmp ( V_13 -> V_3 , V_14 -> V_3 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
unsigned int V_10 , V_15 ;
if ( ! V_2 -> V_8 )
return;
for ( V_10 = V_15 = 1 ; V_10 < V_2 -> V_8 ; V_10 ++ )
if ( strcmp ( V_2 -> V_7 [ V_10 ] -> V_3 , V_2 -> V_7 [ V_10 - 1 ] -> V_3 ) )
V_2 -> V_7 [ V_15 ++ ] = V_2 -> V_7 [ V_10 ] ;
V_2 -> V_8 = V_15 ;
}
void F_7 ( struct V_1 * V_2 , struct V_1 * V_16 )
{
T_1 V_17 , V_18 , V_19 ;
int V_20 ;
V_17 = V_18 = V_19 = 0 ;
while ( V_17 < V_2 -> V_8 && V_19 < V_16 -> V_8 ) {
V_20 = strcmp ( V_2 -> V_7 [ V_17 ] -> V_3 , V_16 -> V_7 [ V_19 ] -> V_3 ) ;
if ( V_20 < 0 )
V_2 -> V_7 [ V_18 ++ ] = V_2 -> V_7 [ V_17 ++ ] ;
else if ( V_20 == 0 )
V_17 ++ , V_19 ++ ;
else if ( V_20 > 0 )
V_19 ++ ;
}
while ( V_17 < V_2 -> V_8 )
V_2 -> V_7 [ V_18 ++ ] = V_2 -> V_7 [ V_17 ++ ] ;
V_2 -> V_8 = V_18 ;
}
static void F_8 ( struct V_21 * V_22 )
{
char * V_23 = getenv ( L_1 ) ;
if ( V_23 != NULL ) {
V_22 -> V_24 = atoi ( V_23 ) ;
V_23 = getenv ( L_2 ) ;
if ( V_23 != NULL ) {
V_22 -> V_25 = atoi ( V_23 ) ;
if ( V_22 -> V_24 && V_22 -> V_25 )
return;
}
}
#ifdef F_9
if ( F_10 ( 1 , F_9 , V_22 ) == 0 &&
V_22 -> V_24 && V_22 -> V_25 )
return;
#endif
V_22 -> V_24 = 25 ;
V_22 -> V_25 = 80 ;
}
static void F_11 ( struct V_1 * V_2 , int V_26 )
{
int V_27 = 1 , V_28 ;
int V_29 = V_26 + 1 ;
struct V_21 V_30 ;
int V_31 ;
int V_10 , V_15 ;
F_8 ( & V_30 ) ;
V_31 = V_30 . V_25 - 1 ;
if ( V_29 < V_31 )
V_27 = V_31 / V_29 ;
V_28 = ( V_2 -> V_8 + V_27 - 1 ) / V_27 ;
for ( V_10 = 0 ; V_10 < V_28 ; V_10 ++ ) {
printf ( L_3 ) ;
for ( V_15 = 0 ; V_15 < V_27 ; V_15 ++ ) {
unsigned int V_32 = V_15 * V_28 + V_10 ;
unsigned int V_33 = V_29 ;
if ( V_32 >= V_2 -> V_8 )
break;
if ( V_15 == V_27 - 1 || V_32 + V_28 >= V_2 -> V_8 )
V_33 = 1 ;
printf ( L_4 , V_33 , V_2 -> V_7 [ V_32 ] -> V_3 ) ;
}
putchar ( '\n' ) ;
}
}
static int F_12 ( const char * V_3 )
{
struct V_34 V_35 ;
if ( V_34 ( V_3 , & V_35 ) ||
! F_13 ( V_35 . V_36 ) )
return 0 ;
return V_35 . V_36 & V_37 ;
}
static int F_14 ( const char * V_38 , const char * V_39 )
{
T_1 V_4 = strlen ( V_38 ) ;
T_1 V_40 = strlen ( V_39 ) ;
return V_4 > V_40 && ! memcmp ( V_38 + V_4 - V_40 , V_39 , V_40 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
const char * V_41 ,
const char * V_42 )
{
int V_43 ;
T_2 * V_44 = F_16 ( V_41 ) ;
struct V_45 * V_46 ;
char * V_47 = NULL ;
if ( ! V_44 )
return;
if ( ! V_42 )
V_42 = L_5 ;
V_43 = strlen ( V_42 ) ;
F_17 ( & V_47 , L_6 , V_41 ) ;
while ( ( V_46 = F_18 ( V_44 ) ) != NULL ) {
int V_48 ;
if ( ! F_19 ( V_46 -> V_49 , V_42 ) )
continue;
F_20 ( & V_47 , V_46 -> V_49 ) ;
if ( ! F_12 ( V_47 ) )
continue;
V_48 = strlen ( V_46 -> V_49 ) - V_43 ;
if ( F_14 ( V_46 -> V_49 , L_7 ) )
V_48 -= 4 ;
F_1 ( V_2 , V_46 -> V_49 + V_43 , V_48 ) ;
}
F_21 ( V_44 ) ;
free ( V_47 ) ;
}
void F_22 ( const char * V_42 ,
struct V_1 * V_50 ,
struct V_1 * V_51 )
{
const char * V_52 = getenv ( L_8 ) ;
char * V_53 = F_23 () ;
if ( V_53 ) {
F_15 ( V_50 , V_53 , V_42 ) ;
qsort ( V_50 -> V_7 , V_50 -> V_8 ,
sizeof( * V_50 -> V_7 ) , F_5 ) ;
F_6 ( V_50 ) ;
}
if ( V_52 ) {
char * V_54 , * V_41 , * V_55 ;
V_41 = V_54 = F_24 ( V_52 ) ;
while ( 1 ) {
if ( ( V_55 = strchr ( V_41 , ':' ) ) )
* V_55 = 0 ;
if ( ! V_53 || strcmp ( V_41 , V_53 ) )
F_15 ( V_51 , V_41 , V_42 ) ;
if ( ! V_55 )
break;
V_41 = V_55 + 1 ;
}
free ( V_54 ) ;
qsort ( V_51 -> V_7 , V_51 -> V_8 ,
sizeof( * V_51 -> V_7 ) , F_5 ) ;
F_6 ( V_51 ) ;
}
free ( V_53 ) ;
F_7 ( V_51 , V_50 ) ;
}
void F_25 ( const char * V_56 , struct V_1 * V_50 ,
struct V_1 * V_51 )
{
unsigned int V_10 , V_26 = 0 ;
for ( V_10 = 0 ; V_10 < V_50 -> V_8 ; V_10 ++ )
if ( V_26 < V_50 -> V_7 [ V_10 ] -> V_4 )
V_26 = V_50 -> V_7 [ V_10 ] -> V_4 ;
for ( V_10 = 0 ; V_10 < V_51 -> V_8 ; V_10 ++ )
if ( V_26 < V_51 -> V_7 [ V_10 ] -> V_4 )
V_26 = V_51 -> V_7 [ V_10 ] -> V_4 ;
if ( V_50 -> V_8 ) {
char * V_53 = F_23 () ;
printf ( L_9 , V_56 , V_53 ) ;
printf ( L_10 ) ;
F_26 ( '-' , strlen ( V_56 ) + strlen ( V_53 ) ) ;
putchar ( '\n' ) ;
F_11 ( V_50 , V_26 ) ;
putchar ( '\n' ) ;
free ( V_53 ) ;
}
if ( V_51 -> V_8 ) {
printf ( L_11 , V_56 ) ;
printf ( L_12 ) ;
F_26 ( '-' , strlen ( V_56 ) ) ;
putchar ( '\n' ) ;
F_11 ( V_51 , V_26 ) ;
putchar ( '\n' ) ;
}
}
int F_27 ( struct V_1 * V_57 , const char * V_23 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_57 -> V_8 ; V_10 ++ )
if ( ! strcmp ( V_23 , V_57 -> V_7 [ V_10 ] -> V_3 ) )
return 1 ;
return 0 ;
}
