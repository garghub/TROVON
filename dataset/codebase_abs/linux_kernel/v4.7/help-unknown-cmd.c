static int F_1 ( const char * V_1 , const char * V_2 ,
void * T_1 V_3 )
{
if ( ! strcmp ( V_1 , L_1 ) )
V_4 = F_2 ( V_1 , V_2 ) ;
if ( ! F_3 ( V_1 , L_2 ) )
F_4 ( & V_5 , V_1 + 6 , strlen ( V_1 + 6 ) ) ;
return 0 ;
}
static int F_5 ( const void * V_6 , const void * V_7 )
{
const struct V_8 * const * V_9 = V_6 , * const * V_10 = V_7 ;
const char * V_11 = ( * V_9 ) -> V_12 , * V_13 = ( * V_10 ) -> V_12 ;
int V_14 = ( * V_9 ) -> V_15 ;
int V_16 = ( * V_10 ) -> V_15 ;
return V_14 != V_16 ? V_14 - V_16 : strcmp ( V_11 , V_13 ) ;
}
static int F_6 ( struct V_17 * V_18 , struct V_17 * V_19 )
{
unsigned int V_20 , V_21 = V_18 -> V_22 + V_19 -> V_22 ;
void * V_23 ;
if ( V_21 > V_18 -> V_24 ) {
if ( F_7 ( V_18 -> V_24 ) < V_21 )
V_18 -> V_24 = V_21 ;
else
V_18 -> V_24 = F_7 ( V_18 -> V_24 ) ;
V_23 = realloc ( V_18 -> V_25 , V_18 -> V_24 * sizeof( * V_18 -> V_25 ) ) ;
if ( ! V_23 )
return - 1 ;
V_18 -> V_25 = V_23 ;
}
for ( V_20 = 0 ; V_20 < V_19 -> V_22 ; V_20 ++ )
V_18 -> V_25 [ V_18 -> V_22 ++ ] = V_19 -> V_25 [ V_20 ] ;
F_8 ( & V_19 -> V_25 ) ;
V_19 -> V_22 = 0 ;
return 0 ;
}
const char * F_9 ( const char * V_26 )
{
unsigned int V_20 , V_27 = 0 , V_28 = 0 ;
struct V_17 V_29 , V_30 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
memset ( & V_30 , 0 , sizeof( V_29 ) ) ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
F_10 ( F_1 , NULL ) ;
F_11 ( L_3 , & V_29 , & V_30 ) ;
if ( F_6 ( & V_29 , & V_5 ) < 0 ||
F_6 ( & V_29 , & V_30 ) < 0 ) {
fprintf ( V_31 , L_4 ) ;
goto V_32;
}
qsort ( V_29 . V_25 , V_29 . V_22 ,
sizeof( V_29 . V_25 ) , V_33 ) ;
F_12 ( & V_29 ) ;
if ( V_29 . V_22 ) {
for ( V_20 = 0 ; V_20 < V_29 . V_22 ; ++ V_20 )
V_29 . V_25 [ V_20 ] -> V_15 =
F_13 ( V_26 , V_29 . V_25 [ V_20 ] -> V_12 , 0 , 2 , 1 , 4 ) ;
qsort ( V_29 . V_25 , V_29 . V_22 ,
sizeof( * V_29 . V_25 ) , F_5 ) ;
V_28 = V_29 . V_25 [ 0 ] -> V_15 ;
V_27 = 1 ;
while ( V_27 < V_29 . V_22 && V_28 == V_29 . V_25 [ V_27 ] -> V_15 )
++ V_27 ;
}
if ( V_4 && V_27 == 1 ) {
const char * V_34 = V_29 . V_25 [ 0 ] -> V_12 ;
V_29 . V_25 [ 0 ] = NULL ;
F_14 ( & V_29 ) ;
fprintf ( V_31 , L_5
L_6
L_7 ,
V_26 , V_34 ) ;
if ( V_4 > 0 ) {
fprintf ( V_31 , L_8 ,
( float ) V_4 / 10.0 ) ;
F_15 ( NULL , 0 , V_4 * 100 ) ;
}
return V_34 ;
}
fprintf ( V_31 , L_9 , V_26 ) ;
if ( V_29 . V_22 && V_28 < 6 ) {
fprintf ( V_31 , L_10 ,
V_27 < 2 ? L_11 : L_12 ) ;
for ( V_20 = 0 ; V_20 < V_27 ; V_20 ++ )
fprintf ( V_31 , L_13 , V_29 . V_25 [ V_20 ] -> V_12 ) ;
}
V_32:
exit ( 1 ) ;
}
