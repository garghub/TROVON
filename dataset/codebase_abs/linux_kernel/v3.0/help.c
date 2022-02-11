void F_1 ( struct V_1 * V_2 , const char * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = malloc ( sizeof( * V_6 ) + V_4 + 1 ) ;
V_6 -> V_4 = V_4 ;
memcpy ( V_6 -> V_3 , V_3 , V_4 ) ;
V_6 -> V_3 [ V_4 ] = 0 ;
F_2 ( V_2 -> V_7 , V_2 -> V_8 + 1 , V_2 -> V_9 ) ;
V_2 -> V_7 [ V_2 -> V_8 ++ ] = V_6 ;
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_8 ; ++ V_10 )
free ( V_2 -> V_7 [ V_10 ] ) ;
free ( V_2 -> V_7 ) ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
}
static int F_4 ( const void * V_11 , const void * V_12 )
{
struct V_5 * V_13 = * (struct V_5 * * ) V_11 ;
struct V_5 * V_14 = * (struct V_5 * * ) V_12 ;
return strcmp ( V_13 -> V_3 , V_14 -> V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned int V_10 , V_15 ;
if ( ! V_2 -> V_8 )
return;
for ( V_10 = V_15 = 1 ; V_10 < V_2 -> V_8 ; V_10 ++ )
if ( strcmp ( V_2 -> V_7 [ V_10 ] -> V_3 , V_2 -> V_7 [ V_10 - 1 ] -> V_3 ) )
V_2 -> V_7 [ V_15 ++ ] = V_2 -> V_7 [ V_10 ] ;
V_2 -> V_8 = V_15 ;
}
void F_6 ( struct V_1 * V_2 , struct V_1 * V_16 )
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
static void F_7 ( struct V_1 * V_2 , int V_21 )
{
int V_22 = 1 , V_23 ;
int V_24 = V_21 + 1 ;
struct V_25 V_26 ;
int V_27 ;
int V_10 , V_15 ;
F_8 ( & V_26 ) ;
V_27 = V_26 . V_28 - 1 ;
if ( V_24 < V_27 )
V_22 = V_27 / V_24 ;
V_23 = ( V_2 -> V_8 + V_22 - 1 ) / V_22 ;
for ( V_10 = 0 ; V_10 < V_23 ; V_10 ++ ) {
printf ( L_1 ) ;
for ( V_15 = 0 ; V_15 < V_22 ; V_15 ++ ) {
unsigned int V_29 = V_15 * V_23 + V_10 ;
unsigned int V_30 = V_24 ;
if ( V_29 >= V_2 -> V_8 )
break;
if ( V_15 == V_22 - 1 || V_29 + V_23 >= V_2 -> V_8 )
V_30 = 1 ;
printf ( L_2 , V_30 , V_2 -> V_7 [ V_29 ] -> V_3 ) ;
}
putchar ( '\n' ) ;
}
}
static int F_9 ( const char * V_3 )
{
struct V_31 V_32 ;
if ( V_31 ( V_3 , & V_32 ) ||
! F_10 ( V_32 . V_33 ) )
return 0 ;
return V_32 . V_33 & V_34 ;
}
static void F_11 ( struct V_1 * V_2 ,
const char * V_35 ,
const char * V_36 )
{
int V_37 ;
T_2 * V_38 = F_12 ( V_35 ) ;
struct V_39 * V_40 ;
struct V_41 V_42 = V_43 ;
int V_4 ;
if ( ! V_38 )
return;
if ( ! V_36 )
V_36 = L_3 ;
V_37 = strlen ( V_36 ) ;
F_13 ( & V_42 , L_4 , V_35 ) ;
V_4 = V_42 . V_4 ;
while ( ( V_40 = F_14 ( V_38 ) ) != NULL ) {
int V_44 ;
if ( F_15 ( V_40 -> V_45 , V_36 ) )
continue;
F_16 ( & V_42 , V_4 ) ;
F_17 ( & V_42 , V_40 -> V_45 ) ;
if ( ! F_9 ( V_42 . V_42 ) )
continue;
V_44 = strlen ( V_40 -> V_45 ) - V_37 ;
if ( F_18 ( V_40 -> V_45 , L_5 ) )
V_44 -= 4 ;
F_1 ( V_2 , V_40 -> V_45 + V_37 , V_44 ) ;
}
F_19 ( V_38 ) ;
F_20 ( & V_42 ) ;
}
void F_21 ( const char * V_36 ,
struct V_1 * V_46 ,
struct V_1 * V_47 )
{
const char * V_48 = getenv ( L_6 ) ;
const char * V_49 = F_22 () ;
if ( V_49 ) {
F_11 ( V_46 , V_49 , V_36 ) ;
qsort ( V_46 -> V_7 , V_46 -> V_8 ,
sizeof( * V_46 -> V_7 ) , F_4 ) ;
F_5 ( V_46 ) ;
}
if ( V_48 ) {
char * V_50 , * V_35 , * V_51 ;
V_35 = V_50 = F_23 ( V_48 ) ;
while ( 1 ) {
if ( ( V_51 = strchr ( V_35 , V_52 ) ) )
* V_51 = 0 ;
if ( ! V_49 || strcmp ( V_35 , V_49 ) )
F_11 ( V_47 , V_35 , V_36 ) ;
if ( ! V_51 )
break;
V_35 = V_51 + 1 ;
}
free ( V_50 ) ;
qsort ( V_47 -> V_7 , V_47 -> V_8 ,
sizeof( * V_47 -> V_7 ) , F_4 ) ;
F_5 ( V_47 ) ;
}
F_6 ( V_47 , V_46 ) ;
}
void F_24 ( const char * V_53 , struct V_1 * V_46 ,
struct V_1 * V_47 )
{
unsigned int V_10 , V_21 = 0 ;
for ( V_10 = 0 ; V_10 < V_46 -> V_8 ; V_10 ++ )
if ( V_21 < V_46 -> V_7 [ V_10 ] -> V_4 )
V_21 = V_46 -> V_7 [ V_10 ] -> V_4 ;
for ( V_10 = 0 ; V_10 < V_47 -> V_8 ; V_10 ++ )
if ( V_21 < V_47 -> V_7 [ V_10 ] -> V_4 )
V_21 = V_47 -> V_7 [ V_10 ] -> V_4 ;
if ( V_46 -> V_8 ) {
const char * V_49 = F_22 () ;
printf ( L_7 , V_53 , V_49 ) ;
printf ( L_8 ) ;
F_25 ( '-' , strlen ( V_53 ) + strlen ( V_49 ) ) ;
putchar ( '\n' ) ;
F_7 ( V_46 , V_21 ) ;
putchar ( '\n' ) ;
}
if ( V_47 -> V_8 ) {
printf ( L_9 , V_53 ) ;
printf ( L_10 ) ;
F_25 ( '-' , strlen ( V_53 ) ) ;
putchar ( '\n' ) ;
F_7 ( V_47 , V_21 ) ;
putchar ( '\n' ) ;
}
}
int F_26 ( struct V_1 * V_54 , const char * V_55 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_54 -> V_8 ; V_10 ++ )
if ( ! strcmp ( V_55 , V_54 -> V_7 [ V_10 ] -> V_3 ) )
return 1 ;
return 0 ;
}
static int F_27 ( const char * V_56 , const char * V_57 , void * V_58 )
{
if ( ! strcmp ( V_56 , L_11 ) )
V_59 = F_28 ( V_56 , V_57 ) ;
if ( ! F_15 ( V_56 , L_12 ) )
F_1 ( & V_60 , V_56 + 6 , strlen ( V_56 + 6 ) ) ;
return F_29 ( V_56 , V_57 , V_58 ) ;
}
static int F_30 ( const void * V_61 , const void * V_62 )
{
const struct V_5 * const * V_63 = V_61 , * const * V_64 = V_62 ;
const char * V_65 = ( * V_63 ) -> V_3 , * V_66 = ( * V_64 ) -> V_3 ;
int V_67 = ( * V_63 ) -> V_4 ;
int V_68 = ( * V_64 ) -> V_4 ;
return V_67 != V_68 ? V_67 - V_68 : strcmp ( V_65 , V_66 ) ;
}
static void F_31 ( struct V_1 * V_2 , struct V_1 * V_69 )
{
unsigned int V_10 ;
F_2 ( V_2 -> V_7 , V_2 -> V_8 + V_69 -> V_8 , V_2 -> V_9 ) ;
for ( V_10 = 0 ; V_10 < V_69 -> V_8 ; V_10 ++ )
V_2 -> V_7 [ V_2 -> V_8 ++ ] = V_69 -> V_7 [ V_10 ] ;
free ( V_69 -> V_7 ) ;
V_69 -> V_8 = 0 ;
V_69 -> V_7 = NULL ;
}
const char * F_32 ( const char * V_70 )
{
unsigned int V_10 , V_29 = 0 , V_71 = 0 ;
struct V_1 V_46 , V_47 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
memset ( & V_47 , 0 , sizeof( V_46 ) ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
F_33 ( F_27 , NULL ) ;
F_21 ( L_3 , & V_46 , & V_47 ) ;
F_31 ( & V_46 , & V_60 ) ;
F_31 ( & V_46 , & V_47 ) ;
qsort ( V_46 . V_7 , V_46 . V_8 ,
sizeof( V_46 . V_7 ) , F_4 ) ;
F_5 ( & V_46 ) ;
if ( V_46 . V_8 ) {
for ( V_10 = 0 ; V_10 < V_46 . V_8 ; ++ V_10 )
V_46 . V_7 [ V_10 ] -> V_4 =
F_34 ( V_70 , V_46 . V_7 [ V_10 ] -> V_3 , 0 , 2 , 1 , 4 ) ;
qsort ( V_46 . V_7 , V_46 . V_8 ,
sizeof( * V_46 . V_7 ) , F_30 ) ;
V_71 = V_46 . V_7 [ 0 ] -> V_4 ;
V_29 = 1 ;
while ( V_29 < V_46 . V_8 && V_71 == V_46 . V_7 [ V_29 ] -> V_4 )
++ V_29 ;
}
if ( V_59 && V_29 == 1 ) {
const char * V_72 = V_46 . V_7 [ 0 ] -> V_3 ;
V_46 . V_7 [ 0 ] = NULL ;
F_3 ( & V_46 ) ;
fprintf ( V_73 , L_13
L_14
L_15 ,
V_70 , V_72 ) ;
if ( V_59 > 0 ) {
fprintf ( V_73 , L_16 ,
( float ) V_59 / 10.0 ) ;
F_35 ( NULL , 0 , V_59 * 100 ) ;
}
return V_72 ;
}
fprintf ( V_73 , L_17 , V_70 ) ;
if ( V_46 . V_8 && V_71 < 6 ) {
fprintf ( V_73 , L_18 ,
V_29 < 2 ? L_19 : L_20 ) ;
for ( V_10 = 0 ; V_10 < V_29 ; V_10 ++ )
fprintf ( V_73 , L_21 , V_46 . V_7 [ V_10 ] -> V_3 ) ;
}
exit ( 1 ) ;
}
int F_36 ( int T_3 V_74 , const char * * T_4 V_74 , const char * V_36 V_74 )
{
printf ( L_22 , V_75 ) ;
return 0 ;
}
