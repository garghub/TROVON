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
while ( V_3 && V_4 ) {
if ( (* F_2)( V_2 , V_3 , V_4 ) <= 0 ) {
V_6 -> V_7 = V_3 ;
V_3 -> V_8 = V_6 ;
V_3 = V_3 -> V_7 ;
} else {
V_6 -> V_7 = V_4 ;
V_4 -> V_8 = V_6 ;
V_4 = V_4 -> V_7 ;
}
V_6 = V_6 -> V_7 ;
}
V_6 -> V_7 = V_3 ? : V_4 ;
do {
(* F_2)( V_2 , V_6 -> V_7 , V_6 -> V_7 ) ;
V_6 -> V_7 -> V_8 = V_6 ;
V_6 = V_6 -> V_7 ;
} while ( V_6 -> V_7 );
V_6 -> V_7 = V_5 ;
V_5 -> V_8 = V_6 ;
}
void F_4 ( void * V_2 , struct V_1 * V_5 ,
int (* F_2)( void * V_2 , struct V_1 * V_3 ,
struct V_1 * V_4 ) )
{
struct V_1 * V_9 [ V_10 + 1 ] ;
int V_11 ;
int V_12 = 0 ;
struct V_1 * V_13 ;
if ( F_5 ( V_5 ) )
return;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
V_5 -> V_8 -> V_7 = NULL ;
V_13 = V_5 -> V_7 ;
while ( V_13 ) {
struct V_1 * V_14 = V_13 ;
V_13 = V_13 -> V_7 ;
V_14 -> V_7 = NULL ;
for ( V_11 = 0 ; V_9 [ V_11 ] ; V_11 ++ ) {
V_14 = F_1 ( V_2 , F_2 , V_9 [ V_11 ] , V_14 ) ;
V_9 [ V_11 ] = NULL ;
}
if ( V_11 > V_12 ) {
if ( F_6 ( V_11 >= F_7 ( V_9 ) - 1 ) ) {
F_8 ( V_15 L_1
L_2
L_3 ) ;
V_11 -- ;
}
V_12 = V_11 ;
}
V_9 [ V_11 ] = V_14 ;
}
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ )
if ( V_9 [ V_11 ] )
V_13 = F_1 ( V_2 , F_2 , V_9 [ V_11 ] , V_13 ) ;
F_3 ( V_2 , F_2 , V_5 , V_9 [ V_12 ] , V_13 ) ;
}
static int T_1 F_9 ( struct V_16 * V_17 , struct V_16 * V_18 )
{
if ( V_17 -> V_19 >= V_20 ) {
F_10 ( V_21 L_4 ,
V_17 -> V_19 ) ;
return - V_22 ;
}
if ( V_18 -> V_19 >= V_20 ) {
F_10 ( V_21 L_4 ,
V_18 -> V_19 ) ;
return - V_22 ;
}
if ( V_23 [ V_17 -> V_19 ] != V_17 || V_23 [ V_18 -> V_19 ] != V_18 ) {
F_10 ( V_21 L_5 ) ;
return - V_22 ;
}
if ( V_17 -> V_24 != V_25 || V_17 -> V_26 != V_27 ) {
F_10 ( V_21 L_6 ,
V_17 -> V_24 , V_17 -> V_26 ) ;
return - V_22 ;
}
if ( V_18 -> V_24 != V_25 || V_18 -> V_26 != V_27 ) {
F_10 ( V_21 L_6 ,
V_18 -> V_24 , V_18 -> V_26 ) ;
return - V_22 ;
}
return 0 ;
}
static int T_1 F_2 ( void * V_2 , struct V_1 * V_3 , struct V_1 * V_4 )
{
struct V_16 * V_17 , * V_18 ;
V_17 = F_11 ( V_3 , struct V_16 , V_13 ) ;
V_18 = F_11 ( V_4 , struct V_16 , V_13 ) ;
F_9 ( V_17 , V_18 ) ;
return V_17 -> V_28 - V_18 -> V_28 ;
}
static int T_1 F_12 ( void )
{
int V_29 , V_30 = 1 , V_31 = - V_22 ;
struct V_16 * V_32 ;
struct V_1 * V_14 , * V_33 ;
F_13 ( V_5 ) ;
F_10 ( V_15 L_7 ) ;
V_23 = F_14 ( sizeof( void * ) * V_20 , V_34 ) ;
if ( ! V_23 ) {
F_10 ( V_21 L_8
L_9 ) ;
goto exit;
}
for ( V_29 = 0 ; V_29 < V_20 ; V_29 ++ ) {
V_32 = F_14 ( sizeof( * V_32 ) , V_34 ) ;
if ( ! V_32 ) {
F_10 ( V_21 L_10
L_11 ) ;
goto exit;
}
V_32 -> V_28 = F_15 () % ( V_20 / 3 ) ;
V_32 -> V_19 = V_29 ;
V_32 -> V_24 = V_25 ;
V_32 -> V_26 = V_27 ;
V_23 [ V_29 ] = V_32 ;
F_16 ( & V_32 -> V_13 , & V_5 ) ;
}
F_4 ( NULL , & V_5 , F_2 ) ;
for ( V_14 = V_5 . V_7 ; V_14 -> V_7 != & V_5 ; V_14 = V_14 -> V_7 ) {
struct V_16 * V_35 ;
int V_36 ;
if ( V_14 -> V_7 -> V_8 != V_14 ) {
F_10 ( V_21 L_12
L_13 ) ;
goto exit;
}
V_36 = F_2 ( NULL , V_14 , V_14 -> V_7 ) ;
if ( V_36 > 0 ) {
F_10 ( V_21 L_14
L_15 ) ;
goto exit;
}
V_32 = F_11 ( V_14 , struct V_16 , V_13 ) ;
V_35 = F_11 ( V_14 -> V_7 , struct V_16 , V_13 ) ;
if ( V_36 == 0 && V_32 -> V_19 >= V_35 -> V_19 ) {
F_10 ( V_21 L_16
L_17 ) ;
goto exit;
}
if ( F_9 ( V_32 , V_35 ) ) {
F_10 ( V_21 L_18
L_19 ) ;
goto exit;
}
V_30 ++ ;
}
if ( V_30 != V_20 ) {
F_10 ( V_21 L_20 ,
V_30 ) ;
goto exit;
}
V_31 = 0 ;
exit:
F_17 ( V_23 ) ;
F_18 (cur, tmp, &head) {
F_19 ( V_14 ) ;
F_17 ( F_11 ( V_14 , struct V_16 , V_13 ) ) ;
}
return V_31 ;
}
