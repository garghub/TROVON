static int F_1 ( const char * V_1 , const char * V_2 ,
void * T_1 V_3 )
{
if ( ! strcmp ( V_1 , L_1 ) )
return F_2 ( & V_4 , V_1 , V_2 ) ;
return 0 ;
}
static int F_3 ( const void * V_5 , const void * V_6 )
{
const struct V_7 * const * V_8 = V_5 , * const * V_9 = V_6 ;
const char * V_10 = ( * V_8 ) -> V_11 , * V_12 = ( * V_9 ) -> V_11 ;
int V_13 = ( * V_8 ) -> V_14 ;
int V_15 = ( * V_9 ) -> V_14 ;
return V_13 != V_15 ? V_13 - V_15 : strcmp ( V_10 , V_12 ) ;
}
static int F_4 ( struct V_16 * V_17 , struct V_16 * V_18 )
{
unsigned int V_19 , V_20 = V_17 -> V_21 + V_18 -> V_21 ;
void * V_22 ;
if ( V_20 > V_17 -> V_23 ) {
if ( F_5 ( V_17 -> V_23 ) < V_20 )
V_17 -> V_23 = V_20 ;
else
V_17 -> V_23 = F_5 ( V_17 -> V_23 ) ;
V_22 = realloc ( V_17 -> V_24 , V_17 -> V_23 * sizeof( * V_17 -> V_24 ) ) ;
if ( ! V_22 )
return - 1 ;
V_17 -> V_24 = V_22 ;
}
for ( V_19 = 0 ; V_19 < V_18 -> V_21 ; V_19 ++ )
V_17 -> V_24 [ V_17 -> V_21 ++ ] = V_18 -> V_24 [ V_19 ] ;
F_6 ( & V_18 -> V_24 ) ;
V_18 -> V_21 = 0 ;
return 0 ;
}
const char * F_7 ( const char * V_25 )
{
unsigned int V_19 , V_26 = 0 , V_27 = 0 ;
struct V_16 V_28 , V_29 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
memset ( & V_29 , 0 , sizeof( V_28 ) ) ;
F_8 ( F_1 , NULL ) ;
F_9 ( L_2 , & V_28 , & V_29 ) ;
if ( F_4 ( & V_28 , & V_29 ) < 0 ) {
fprintf ( V_30 , L_3 ) ;
goto V_31;
}
qsort ( V_28 . V_24 , V_28 . V_21 ,
sizeof( V_28 . V_24 ) , V_32 ) ;
F_10 ( & V_28 ) ;
if ( V_28 . V_21 ) {
for ( V_19 = 0 ; V_19 < V_28 . V_21 ; ++ V_19 )
V_28 . V_24 [ V_19 ] -> V_14 =
F_11 ( V_25 , V_28 . V_24 [ V_19 ] -> V_11 , 0 , 2 , 1 , 4 ) ;
qsort ( V_28 . V_24 , V_28 . V_21 ,
sizeof( * V_28 . V_24 ) , F_3 ) ;
V_27 = V_28 . V_24 [ 0 ] -> V_14 ;
V_26 = 1 ;
while ( V_26 < V_28 . V_21 && V_27 == V_28 . V_24 [ V_26 ] -> V_14 )
++ V_26 ;
}
if ( V_4 && V_26 == 1 ) {
const char * V_33 = V_28 . V_24 [ 0 ] -> V_11 ;
V_28 . V_24 [ 0 ] = NULL ;
F_12 ( & V_28 ) ;
fprintf ( V_30 , L_4
L_5
L_6 ,
V_25 , V_33 ) ;
if ( V_4 > 0 ) {
fprintf ( V_30 , L_7 ,
( float ) V_4 / 10.0 ) ;
F_13 ( NULL , 0 , V_4 * 100 ) ;
}
return V_33 ;
}
fprintf ( V_30 , L_8 , V_25 ) ;
if ( V_28 . V_21 && V_27 < 6 ) {
fprintf ( V_30 , L_9 ,
V_26 < 2 ? L_10 : L_11 ) ;
for ( V_19 = 0 ; V_19 < V_26 ; V_19 ++ )
fprintf ( V_30 , L_12 , V_28 . V_24 [ V_19 ] -> V_11 ) ;
}
V_31:
exit ( 1 ) ;
}
