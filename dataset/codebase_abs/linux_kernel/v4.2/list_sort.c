static struct V_1 * F_1 ( void * V_2 ,
int (* F_2)( void * V_2 , struct V_1 * V_3 ,
struct V_1 * V_4 ) ,
struct V_1 * V_3 , struct V_1 * V_4 )
{
struct V_1 V_5 , * V_6 = & V_5 ;
while ( V_3 && V_4 ) {
if ( (* F_2)( V_2 , V_3 , V_4 ) <= 0 ) {
V_6 -> V_7 = V_3 ;
V_3 = V_3 -> V_7 ;
} else {
V_6 -> V_7 = V_4 ;
V_4 = V_4 -> V_7 ;
}
V_6 = V_6 -> V_7 ;
}
V_6 -> V_7 = V_3 ? : V_4 ;
return V_5 . V_7 ;
}
static void F_3 ( void * V_2 ,
int (* F_2)( void * V_2 , struct V_1 * V_3 ,
struct V_1 * V_4 ) ,
struct V_1 * V_5 ,
struct V_1 * V_3 , struct V_1 * V_4 )
{
struct V_1 * V_6 = V_5 ;
T_1 V_8 = 0 ;
while ( V_3 && V_4 ) {
if ( (* F_2)( V_2 , V_3 , V_4 ) <= 0 ) {
V_6 -> V_7 = V_3 ;
V_3 -> V_9 = V_6 ;
V_3 = V_3 -> V_7 ;
} else {
V_6 -> V_7 = V_4 ;
V_4 -> V_9 = V_6 ;
V_4 = V_4 -> V_7 ;
}
V_6 = V_6 -> V_7 ;
}
V_6 -> V_7 = V_3 ? : V_4 ;
do {
if ( F_4 ( ! ( ++ V_8 ) ) )
(* F_2)( V_2 , V_6 -> V_7 , V_6 -> V_7 ) ;
V_6 -> V_7 -> V_9 = V_6 ;
V_6 = V_6 -> V_7 ;
} while ( V_6 -> V_7 );
V_6 -> V_7 = V_5 ;
V_5 -> V_9 = V_6 ;
}
void F_5 ( void * V_2 , struct V_1 * V_5 ,
int (* F_2)( void * V_2 , struct V_1 * V_3 ,
struct V_1 * V_4 ) )
{
struct V_1 * V_10 [ V_11 + 1 ] ;
int V_12 ;
int V_13 = 0 ;
struct V_1 * V_14 ;
if ( F_6 ( V_5 ) )
return;
memset ( V_10 , 0 , sizeof( V_10 ) ) ;
V_5 -> V_9 -> V_7 = NULL ;
V_14 = V_5 -> V_7 ;
while ( V_14 ) {
struct V_1 * V_15 = V_14 ;
V_14 = V_14 -> V_7 ;
V_15 -> V_7 = NULL ;
for ( V_12 = 0 ; V_10 [ V_12 ] ; V_12 ++ ) {
V_15 = F_1 ( V_2 , F_2 , V_10 [ V_12 ] , V_15 ) ;
V_10 [ V_12 ] = NULL ;
}
if ( V_12 > V_13 ) {
if ( F_4 ( V_12 >= F_7 ( V_10 ) - 1 ) ) {
F_8 ( V_16 L_1 ) ;
V_12 -- ;
}
V_13 = V_12 ;
}
V_10 [ V_12 ] = V_15 ;
}
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
if ( V_10 [ V_12 ] )
V_14 = F_1 ( V_2 , F_2 , V_10 [ V_12 ] , V_14 ) ;
F_3 ( V_2 , F_2 , V_5 , V_10 [ V_13 ] , V_14 ) ;
}
static int T_2 F_9 ( struct V_17 * V_18 , struct V_17 * V_19 )
{
if ( V_18 -> V_20 >= V_21 ) {
F_10 ( L_2 , V_18 -> V_20 ) ;
return - V_22 ;
}
if ( V_19 -> V_20 >= V_21 ) {
F_10 ( L_2 , V_19 -> V_20 ) ;
return - V_22 ;
}
if ( V_23 [ V_18 -> V_20 ] != V_18 || V_23 [ V_19 -> V_20 ] != V_19 ) {
F_10 ( L_3 ) ;
return - V_22 ;
}
if ( V_18 -> V_24 != V_25 || V_18 -> V_26 != V_27 ) {
F_10 ( L_4 ,
V_18 -> V_24 , V_18 -> V_26 ) ;
return - V_22 ;
}
if ( V_19 -> V_24 != V_25 || V_19 -> V_26 != V_27 ) {
F_10 ( L_4 ,
V_19 -> V_24 , V_19 -> V_26 ) ;
return - V_22 ;
}
return 0 ;
}
static int T_2 F_2 ( void * V_2 , struct V_1 * V_3 , struct V_1 * V_4 )
{
struct V_17 * V_18 , * V_19 ;
V_18 = F_11 ( V_3 , struct V_17 , V_14 ) ;
V_19 = F_11 ( V_4 , struct V_17 , V_14 ) ;
F_9 ( V_18 , V_19 ) ;
return V_18 -> V_28 - V_19 -> V_28 ;
}
static int T_2 F_12 ( void )
{
int V_29 , V_8 = 1 , V_30 = - V_31 ;
struct V_17 * V_32 ;
struct V_1 * V_15 ;
F_13 ( V_5 ) ;
F_14 ( L_5 ) ;
V_23 = F_15 ( V_21 , sizeof( * V_23 ) , V_33 ) ;
if ( ! V_23 ) {
F_10 ( L_6 ) ;
return V_30 ;
}
for ( V_29 = 0 ; V_29 < V_21 ; V_29 ++ ) {
V_32 = F_16 ( sizeof( * V_32 ) , V_33 ) ;
if ( ! V_32 ) {
F_10 ( L_6 ) ;
goto exit;
}
V_32 -> V_28 = F_17 () % ( V_21 / 3 ) ;
V_32 -> V_20 = V_29 ;
V_32 -> V_24 = V_25 ;
V_32 -> V_26 = V_27 ;
V_23 [ V_29 ] = V_32 ;
F_18 ( & V_32 -> V_14 , & V_5 ) ;
}
F_5 ( NULL , & V_5 , F_2 ) ;
V_30 = - V_22 ;
for ( V_15 = V_5 . V_7 ; V_15 -> V_7 != & V_5 ; V_15 = V_15 -> V_7 ) {
struct V_17 * V_34 ;
int V_35 ;
if ( V_15 -> V_7 -> V_9 != V_15 ) {
F_10 ( L_7 ) ;
goto exit;
}
V_35 = F_2 ( NULL , V_15 , V_15 -> V_7 ) ;
if ( V_35 > 0 ) {
F_10 ( L_8 ) ;
goto exit;
}
V_32 = F_11 ( V_15 , struct V_17 , V_14 ) ;
V_34 = F_11 ( V_15 -> V_7 , struct V_17 , V_14 ) ;
if ( V_35 == 0 && V_32 -> V_20 >= V_34 -> V_20 ) {
F_10 ( L_9
L_10 ) ;
goto exit;
}
if ( F_9 ( V_32 , V_34 ) ) {
F_10 ( L_11 ) ;
goto exit;
}
V_8 ++ ;
}
if ( V_5 . V_9 != V_15 ) {
F_10 ( L_7 ) ;
goto exit;
}
if ( V_8 != V_21 ) {
F_10 ( L_12 , V_8 ) ;
goto exit;
}
V_30 = 0 ;
exit:
for ( V_29 = 0 ; V_29 < V_21 ; V_29 ++ )
F_19 ( V_23 [ V_29 ] ) ;
F_19 ( V_23 ) ;
return V_30 ;
}
