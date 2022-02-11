void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_7 ;
F_2 ( V_2 != NULL ) ;
F_2 ( F_3 ( & V_2 -> V_8 ) ) ;
F_4 ( & V_9 ) ;
V_10 += V_11 ;
if ( F_5 ( V_10 == 0 ) ) {
F_6 ( L_1 ) ;
V_10 += V_11 ;
}
V_2 -> V_12 = V_10 ;
F_7 ( & V_9 ) ;
V_2 -> V_13 = V_4 ;
F_8 ( & V_2 -> V_14 ) ;
V_6 = & V_15 [ V_2 -> V_12 & V_16 ] ;
F_4 ( & V_6 -> V_17 ) ;
F_9 ( & V_2 -> V_8 , & V_6 -> V_18 ) ;
V_2 -> V_19 = 1 ;
F_7 ( & V_6 -> V_17 ) ;
F_10 ( V_20 , L_2 V_21 L_3 ,
V_2 , V_2 -> V_12 ) ;
EXIT ;
}
static void F_11 ( struct V_1 * V_2 )
{
if ( F_3 ( & V_2 -> V_8 ) ) {
F_12 ( L_4 V_21 L_5 ,
V_2 -> V_12 ) ;
return;
}
F_10 ( V_20 , L_6 V_21 L_7 ,
V_2 , V_2 -> V_12 ) ;
F_4 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_19 == 0 ) {
F_7 ( & V_2 -> V_14 ) ;
return;
}
V_2 -> V_19 = 0 ;
F_7 ( & V_2 -> V_14 ) ;
F_13 ( & V_2 -> V_8 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = V_15 + ( V_2 -> V_12 & V_16 ) ;
F_4 ( & V_6 -> V_17 ) ;
F_11 ( V_2 ) ;
F_7 ( & V_6 -> V_17 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_7 ;
V_6 = V_15 + ( V_2 -> V_12 & V_16 ) ;
F_4 ( & V_6 -> V_17 ) ;
F_9 ( & V_2 -> V_8 , & V_6 -> V_18 ) ;
V_2 -> V_19 = 1 ;
F_7 ( & V_6 -> V_17 ) ;
EXIT ;
}
void * F_16 ( T_1 V_22 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
void * V_23 = NULL ;
V_7 ;
F_2 ( V_15 != NULL ) ;
V_6 = V_15 + ( V_22 & V_16 ) ;
F_17 () ;
F_18 (h, &bucket->head, h_link) {
if ( V_2 -> V_12 != V_22 )
continue;
F_4 ( & V_2 -> V_14 ) ;
if ( F_19 ( V_2 -> V_19 != 0 ) ) {
V_2 -> V_13 -> V_24 ( V_2 ) ;
V_23 = V_2 ;
}
F_7 ( & V_2 -> V_14 ) ;
break;
}
F_20 () ;
RETURN ( V_23 ) ;
}
void F_21 ( T_2 * V_25 )
{
struct V_1 * V_2 = F_22 ( V_25 ) ;
void * V_26 = ( void * ) ( unsigned long ) V_2 -> V_12 ;
if ( V_2 -> V_13 -> V_27 != NULL )
V_2 -> V_13 -> V_27 ( V_26 , V_2 -> V_28 ) ;
else
F_23 ( V_26 , V_2 -> V_28 ) ;
}
int F_24 ( void )
{
struct V_5 * V_6 ;
struct V_29 V_30 ;
int V_31 [ 2 ] ;
F_2 ( V_15 == NULL ) ;
F_25 ( V_15 , sizeof( * V_6 ) * V_32 ) ;
if ( V_15 == NULL )
return - V_33 ;
F_8 ( & V_9 ) ;
for ( V_6 = V_15 + V_32 - 1 ; V_6 >= V_15 ;
V_6 -- ) {
F_26 ( & V_6 -> V_18 ) ;
F_8 ( & V_6 -> V_17 ) ;
}
F_27 ( V_31 , sizeof( V_31 ) ) ;
F_28 ( & V_30 ) ;
F_29 ( V_30 . V_34 ^ V_31 [ 0 ] , V_30 . V_35 ^ V_31 [ 1 ] ) ;
F_27 ( & V_10 , sizeof( V_10 ) ) ;
F_2 ( V_10 != 0ULL ) ;
return 0 ;
}
static int F_30 ( void )
{
int V_36 ;
int V_37 ;
for ( V_36 = V_37 = 0 ; V_37 < V_32 ; V_37 ++ ) {
struct V_1 * V_2 ;
F_4 ( & V_15 [ V_37 ] . V_17 ) ;
F_18 (h, &(handle_hash[i].head), h_link) {
F_12 ( L_8 V_21 L_9 ,
V_2 -> V_12 , V_2 , V_2 -> V_13 ) ;
F_11 ( V_2 ) ;
V_36 ++ ;
}
F_7 ( & V_15 [ V_37 ] . V_17 ) ;
}
return V_36 ;
}
void F_31 ( void )
{
int V_38 ;
F_2 ( V_15 != NULL ) ;
V_38 = F_30 () ;
F_32 ( V_15 , sizeof( * V_15 ) * V_32 ) ;
V_15 = NULL ;
if ( V_38 != 0 )
F_12 ( L_10 , V_38 ) ;
}
