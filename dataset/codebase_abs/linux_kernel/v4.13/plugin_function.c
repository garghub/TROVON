static void F_1 ( struct V_1 * V_2 , const char * V_3 , int V_4 )
{
int V_5 ;
if ( ! V_3 )
return;
if ( V_4 < V_2 -> V_6 )
free ( V_2 -> V_2 [ V_4 ] ) ;
else {
char * * V_7 ;
V_7 = realloc ( V_2 -> V_2 , sizeof( char * ) *
( V_2 -> V_6 + V_8 ) ) ;
if ( ! V_7 ) {
F_2 ( L_1 ) ;
return;
}
V_2 -> V_2 = V_7 ;
for ( V_5 = V_2 -> V_6 ; V_5 < V_2 -> V_6 + V_8 ; V_5 ++ )
V_2 -> V_2 [ V_5 ] = NULL ;
V_2 -> V_6 += V_8 ;
}
V_2 -> V_2 [ V_4 ] = F_3 ( V_3 ) ;
}
static int F_4 ( const char * V_9 , const char * V_3 , int V_10 )
{
int V_5 ;
if ( V_10 < 0 )
return 0 ;
if ( V_10 > V_11 ) {
struct V_1 * V_7 ;
V_7 = realloc ( V_12 , sizeof( * V_12 ) * ( V_10 + 1 ) ) ;
if ( ! V_7 ) {
F_2 ( L_1 ) ;
return 0 ;
}
V_12 = V_7 ;
for ( V_5 = V_11 + 1 ; V_5 <= V_10 ; V_5 ++ )
memset ( & V_12 [ V_5 ] , 0 , sizeof( V_12 [ V_5 ] ) ) ;
V_11 = V_10 ;
}
for ( V_5 = 0 ; V_5 < V_12 [ V_10 ] . V_6 && V_12 [ V_10 ] . V_2 [ V_5 ] ; V_5 ++ ) {
if ( strcmp ( V_9 , V_12 [ V_10 ] . V_2 [ V_5 ] ) == 0 ) {
F_1 ( & V_12 [ V_10 ] , V_3 , V_5 + 1 ) ;
return V_5 ;
}
}
F_1 ( & V_12 [ V_10 ] , V_9 , 0 ) ;
F_1 ( & V_12 [ V_10 ] , V_3 , 1 ) ;
return 0 ;
}
static int F_5 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , void * V_19 )
{
struct V_20 * V_20 = V_18 -> V_20 ;
unsigned long long V_21 ;
unsigned long long V_22 ;
const char * V_23 ;
const char * V_9 ;
int V_24 = 0 ;
if ( F_6 ( V_14 , V_18 , L_2 , V_16 , & V_21 , 1 ) )
return F_7 ( V_14 , '!' ) ;
V_23 = F_8 ( V_20 , V_21 ) ;
if ( F_6 ( V_14 , V_18 , L_3 , V_16 , & V_22 , 1 ) )
return F_7 ( V_14 , '!' ) ;
V_9 = F_8 ( V_20 , V_22 ) ;
if ( V_9 && V_25 -> V_26 )
V_24 = F_4 ( V_9 , V_23 , V_16 -> V_10 ) ;
F_9 ( V_14 , L_4 , V_24 * 3 , L_5 ) ;
if ( V_23 )
F_9 ( V_14 , L_6 , V_23 ) ;
else
F_9 ( V_14 , L_7 , V_21 ) ;
if ( V_27 -> V_26 ) {
F_9 ( V_14 , L_8 ) ;
if ( V_9 )
F_9 ( V_14 , L_6 , V_9 ) ;
else
F_9 ( V_14 , L_7 , V_22 ) ;
}
return 0 ;
}
int F_10 ( struct V_20 * V_20 )
{
F_11 ( V_20 , - 1 , L_9 , L_10 ,
F_5 , NULL ) ;
F_12 ( L_9 , V_28 ) ;
return 0 ;
}
void F_13 ( struct V_20 * V_20 )
{
int V_5 , V_29 ;
F_14 ( V_20 , - 1 , L_9 , L_10 ,
F_5 , NULL ) ;
for ( V_5 = 0 ; V_5 <= V_11 ; V_5 ++ ) {
for ( V_29 = 0 ; V_29 < V_12 [ V_5 ] . V_6 && V_12 [ V_5 ] . V_2 [ V_29 ] ; V_29 ++ )
free ( V_12 [ V_5 ] . V_2 [ V_29 ] ) ;
free ( V_12 [ V_5 ] . V_2 ) ;
}
F_15 ( V_28 ) ;
free ( V_12 ) ;
V_12 = NULL ;
V_11 = - 1 ;
}
