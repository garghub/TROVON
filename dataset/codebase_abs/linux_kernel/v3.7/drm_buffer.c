int F_1 ( struct V_1 * * V_2 , int V_3 )
{
int V_4 = V_3 / V_5 + 1 ;
int V_6 ;
* V_2 = F_2 ( sizeof( struct V_1 ) + V_4 * sizeof( char * ) ,
V_7 ) ;
if ( * V_2 == NULL ) {
F_3 ( L_1
L_2 ,
V_3 , V_4 ) ;
return - V_8 ;
}
( * V_2 ) -> V_3 = V_3 ;
for ( V_6 = 0 ; V_6 < V_4 ; ++ V_6 ) {
( * V_2 ) -> V_9 [ V_6 ] =
F_4 ( F_5 ( V_5 , V_3 - V_6 * V_5 ) ,
V_7 ) ;
if ( ( * V_2 ) -> V_9 [ V_6 ] == NULL ) {
F_3 ( L_3
L_4 ,
V_6 + 1 , V_3 , V_4 ) ;
goto V_10;
}
}
return 0 ;
V_10:
if ( ( * V_2 ) -> V_9 [ V_6 ] )
F_6 ( ( * V_2 ) -> V_9 [ V_6 ] ) ;
for ( -- V_6 ; V_6 >= 0 ; -- V_6 )
F_6 ( ( * V_2 ) -> V_9 [ V_6 ] ) ;
F_6 ( * V_2 ) ;
return - V_8 ;
}
int F_7 ( struct V_1 * V_2 ,
void T_1 * V_11 , int V_3 )
{
int V_4 = V_3 / V_5 + 1 ;
int V_6 ;
if ( V_3 > V_2 -> V_3 ) {
F_3 ( L_5
L_6 ,
V_3 , V_2 -> V_3 ) ;
return - V_12 ;
}
for ( V_6 = 0 ; V_6 < V_4 ; ++ V_6 ) {
if ( F_8 ( V_2 -> V_9 [ V_6 ] ,
V_11 + V_6 * V_5 ,
F_5 ( V_5 , V_3 - V_6 * V_5 ) ) ) {
F_3 ( L_7
L_8 ,
V_11 , V_2 , V_6 ) ;
return - V_12 ;
}
}
V_2 -> V_13 = 0 ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
if ( V_2 != NULL ) {
int V_4 = V_2 -> V_3 / V_5 + 1 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_4 ; ++ V_6 )
F_6 ( V_2 -> V_9 [ V_6 ] ) ;
F_6 ( V_2 ) ;
}
}
void * F_10 ( struct V_1 * V_2 ,
int V_14 , void * V_15 )
{
int V_6 = F_11 ( V_2 ) ;
int V_16 = F_12 ( V_2 ) ;
void * V_17 = NULL ;
if ( V_6 + V_14 <= V_5 ) {
V_17 = & V_2 -> V_9 [ V_16 ] [ V_6 ] ;
} else {
int V_18 = V_5 - V_6 ;
memcpy ( V_15 , & V_2 -> V_9 [ V_16 ] [ V_6 ] , V_18 ) ;
memcpy ( V_15 + V_18 , & V_2 -> V_9 [ V_16 + 1 ] [ 0 ] ,
V_14 - V_18 ) ;
V_17 = V_15 ;
}
F_13 ( V_2 , V_14 ) ;
return V_17 ;
}
