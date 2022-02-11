static int F_1 ( const char * V_1 , const char * V_2 , void * V_3 )
{
if ( ! strcmp ( V_1 , L_1 ) )
V_4 = F_2 ( V_1 , V_2 ) ;
if ( ! F_3 ( V_1 , L_2 ) )
F_4 ( & V_5 , V_1 + 6 , strlen ( V_1 + 6 ) ) ;
return F_5 ( V_1 , V_2 , V_3 ) ;
}
static int F_6 ( const void * V_6 , const void * V_7 )
{
const struct V_8 * const * V_9 = V_6 , * const * V_10 = V_7 ;
const char * V_11 = ( * V_9 ) -> V_12 , * V_13 = ( * V_10 ) -> V_12 ;
int V_14 = ( * V_9 ) -> V_15 ;
int V_16 = ( * V_10 ) -> V_15 ;
return V_14 != V_16 ? V_14 - V_16 : strcmp ( V_11 , V_13 ) ;
}
static void F_7 ( struct V_17 * V_18 , struct V_17 * V_19 )
{
unsigned int V_20 ;
F_8 ( V_18 -> V_21 , V_18 -> V_22 + V_19 -> V_22 , V_18 -> V_23 ) ;
for ( V_20 = 0 ; V_20 < V_19 -> V_22 ; V_20 ++ )
V_18 -> V_21 [ V_18 -> V_22 ++ ] = V_19 -> V_21 [ V_20 ] ;
F_9 ( & V_19 -> V_21 ) ;
V_19 -> V_22 = 0 ;
}
const char * F_10 ( const char * V_24 )
{
unsigned int V_20 , V_25 = 0 , V_26 = 0 ;
struct V_17 V_27 , V_28 ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
memset ( & V_28 , 0 , sizeof( V_27 ) ) ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
F_11 ( F_1 , NULL ) ;
F_12 ( L_3 , & V_27 , & V_28 ) ;
F_7 ( & V_27 , & V_5 ) ;
F_7 ( & V_27 , & V_28 ) ;
qsort ( V_27 . V_21 , V_27 . V_22 ,
sizeof( V_27 . V_21 ) , V_29 ) ;
F_13 ( & V_27 ) ;
if ( V_27 . V_22 ) {
for ( V_20 = 0 ; V_20 < V_27 . V_22 ; ++ V_20 )
V_27 . V_21 [ V_20 ] -> V_15 =
F_14 ( V_24 , V_27 . V_21 [ V_20 ] -> V_12 , 0 , 2 , 1 , 4 ) ;
qsort ( V_27 . V_21 , V_27 . V_22 ,
sizeof( * V_27 . V_21 ) , F_6 ) ;
V_26 = V_27 . V_21 [ 0 ] -> V_15 ;
V_25 = 1 ;
while ( V_25 < V_27 . V_22 && V_26 == V_27 . V_21 [ V_25 ] -> V_15 )
++ V_25 ;
}
if ( V_4 && V_25 == 1 ) {
const char * V_30 = V_27 . V_21 [ 0 ] -> V_12 ;
V_27 . V_21 [ 0 ] = NULL ;
F_15 ( & V_27 ) ;
fprintf ( V_31 , L_4
L_5
L_6 ,
V_24 , V_30 ) ;
if ( V_4 > 0 ) {
fprintf ( V_31 , L_7 ,
( float ) V_4 / 10.0 ) ;
F_16 ( NULL , 0 , V_4 * 100 ) ;
}
return V_30 ;
}
fprintf ( V_31 , L_8 , V_24 ) ;
if ( V_27 . V_22 && V_26 < 6 ) {
fprintf ( V_31 , L_9 ,
V_25 < 2 ? L_10 : L_11 ) ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ )
fprintf ( V_31 , L_12 , V_27 . V_21 [ V_20 ] -> V_12 ) ;
}
exit ( 1 ) ;
}
