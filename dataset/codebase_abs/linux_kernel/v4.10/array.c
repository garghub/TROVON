void F_1 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 = NULL ;
V_2 -> V_5 = NULL ;
V_2 -> V_6 = V_2 -> V_7 = 0 ;
V_2 -> V_3 = V_3 ;
}
int F_2 ( struct V_1 * V_2 , int V_6 )
{
void * V_5 ;
int V_7 = V_2 -> V_7 + V_6 ;
T_1 V_8 = sizeof( V_2 -> V_5 [ 0 ] ) * V_7 ;
T_1 V_9 = sizeof( struct V_10 ) * V_7 ;
struct V_10 * V_4 = realloc ( V_2 -> V_4 , V_9 ) ;
if ( V_4 == NULL )
return - V_11 ;
V_5 = realloc ( V_2 -> V_5 , V_8 ) ;
if ( V_5 == NULL ) {
free ( V_4 ) ;
return - V_11 ;
}
V_2 -> V_7 = V_7 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
return 0 ;
}
struct V_1 * F_3 ( int V_7 , int V_3 )
{
struct V_1 * V_2 = calloc ( 1 , sizeof( * V_2 ) ) ;
if ( V_2 != NULL ) {
if ( F_2 ( V_2 , V_7 ) ) {
free ( V_2 ) ;
V_2 = NULL ;
} else {
V_2 -> V_3 = V_3 ;
}
}
return V_2 ;
}
void F_4 ( struct V_1 * V_2 )
{
free ( V_2 -> V_4 ) ;
free ( V_2 -> V_5 ) ;
F_1 ( V_2 , 0 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
free ( V_2 ) ;
}
int F_6 ( struct V_1 * V_2 , int V_12 , short V_13 )
{
int V_14 = V_2 -> V_6 ;
if ( V_2 -> V_6 == V_2 -> V_7 &&
F_2 ( V_2 , V_2 -> V_3 ) < 0 )
return - V_11 ;
V_2 -> V_4 [ V_2 -> V_6 ] . V_12 = V_12 ;
V_2 -> V_4 [ V_2 -> V_6 ] . V_15 = V_13 ;
V_2 -> V_6 ++ ;
return V_14 ;
}
int F_7 ( struct V_1 * V_2 , short V_13 ,
void (* F_8)( struct V_1 * V_2 , int V_12 , void * V_16 ) ,
void * V_16 )
{
int V_12 , V_6 = 0 ;
if ( V_2 -> V_6 == 0 )
return 0 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_6 ; ++ V_12 ) {
if ( V_2 -> V_4 [ V_12 ] . V_13 & V_13 ) {
if ( F_8 )
F_8 ( V_2 , V_12 , V_16 ) ;
continue;
}
if ( V_12 != V_6 ) {
V_2 -> V_4 [ V_6 ] = V_2 -> V_4 [ V_12 ] ;
V_2 -> V_5 [ V_6 ] = V_2 -> V_5 [ V_12 ] ;
}
++ V_6 ;
}
return V_2 -> V_6 = V_6 ;
}
int F_9 ( struct V_1 * V_2 , int V_17 )
{
return F_10 ( V_2 -> V_4 , V_2 -> V_6 , V_17 ) ;
}
int F_11 ( struct V_1 * V_2 , T_2 * V_18 )
{
int V_12 , V_19 = fprintf ( V_18 , L_1 , V_2 -> V_6 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_6 ; ++ V_12 )
V_19 += fprintf ( V_18 , L_2 , V_12 ? L_3 : L_4 , V_2 -> V_4 [ V_12 ] . V_12 ) ;
return V_19 + fprintf ( V_18 , L_5 ) ;
}
