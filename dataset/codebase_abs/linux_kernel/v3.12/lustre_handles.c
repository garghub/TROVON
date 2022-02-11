void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_2 ( V_2 != NULL ) ;
F_2 ( F_3 ( & V_2 -> V_7 ) ) ;
F_4 ( & V_8 ) ;
V_9 += V_10 ;
if ( F_5 ( V_9 == 0 ) ) {
F_6 ( L_1 ) ;
V_9 += V_10 ;
}
V_2 -> V_11 = V_9 ;
F_7 ( & V_8 ) ;
V_2 -> V_12 = V_4 ;
F_8 ( & V_2 -> V_13 ) ;
V_6 = & V_14 [ V_2 -> V_11 & V_15 ] ;
F_4 ( & V_6 -> V_16 ) ;
F_9 ( & V_2 -> V_7 , & V_6 -> V_17 ) ;
V_2 -> V_18 = 1 ;
F_7 ( & V_6 -> V_16 ) ;
F_10 ( V_19 , L_2 V_20 L_3 ,
V_2 , V_2 -> V_11 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
if ( F_3 ( & V_2 -> V_7 ) ) {
F_12 ( L_4 V_20 L_5 ,
V_2 -> V_11 ) ;
return;
}
F_10 ( V_19 , L_6 V_20 L_7 ,
V_2 , V_2 -> V_11 ) ;
F_4 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_18 == 0 ) {
F_7 ( & V_2 -> V_13 ) ;
return;
}
V_2 -> V_18 = 0 ;
F_7 ( & V_2 -> V_13 ) ;
F_13 ( & V_2 -> V_7 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = V_14 + ( V_2 -> V_11 & V_15 ) ;
F_4 ( & V_6 -> V_16 ) ;
F_11 ( V_2 ) ;
F_7 ( & V_6 -> V_16 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = V_14 + ( V_2 -> V_11 & V_15 ) ;
F_4 ( & V_6 -> V_16 ) ;
F_9 ( & V_2 -> V_7 , & V_6 -> V_17 ) ;
V_2 -> V_18 = 1 ;
F_7 ( & V_6 -> V_16 ) ;
}
void * F_16 ( T_1 V_21 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
void * V_22 = NULL ;
F_2 ( V_14 != NULL ) ;
V_6 = V_14 + ( V_21 & V_15 ) ;
F_17 () ;
F_18 (h, &bucket->head, h_link) {
if ( V_2 -> V_11 != V_21 )
continue;
F_4 ( & V_2 -> V_13 ) ;
if ( F_19 ( V_2 -> V_18 != 0 ) ) {
V_2 -> V_12 -> V_23 ( V_2 ) ;
V_22 = V_2 ;
}
F_7 ( & V_2 -> V_13 ) ;
break;
}
F_20 () ;
return V_22 ;
}
void F_21 ( T_2 * V_24 )
{
struct V_1 * V_2 = F_22 ( V_24 ) ;
void * V_25 = ( void * ) ( unsigned long ) V_2 -> V_11 ;
if ( V_2 -> V_12 -> V_26 != NULL )
V_2 -> V_12 -> V_26 ( V_25 , V_2 -> V_27 ) ;
else
F_23 ( V_25 , V_2 -> V_27 ) ;
}
int F_24 ( void )
{
struct V_5 * V_6 ;
struct V_28 V_29 ;
int V_30 [ 2 ] ;
F_2 ( V_14 == NULL ) ;
F_25 ( V_14 , sizeof( * V_6 ) * V_31 ) ;
if ( V_14 == NULL )
return - V_32 ;
F_8 ( & V_8 ) ;
for ( V_6 = V_14 + V_31 - 1 ; V_6 >= V_14 ;
V_6 -- ) {
F_26 ( & V_6 -> V_17 ) ;
F_8 ( & V_6 -> V_16 ) ;
}
F_27 ( V_30 , sizeof( V_30 ) ) ;
F_28 ( & V_29 ) ;
F_29 ( V_29 . V_33 ^ V_30 [ 0 ] , V_29 . V_34 ^ V_30 [ 1 ] ) ;
F_27 ( & V_9 , sizeof( V_9 ) ) ;
F_2 ( V_9 != 0ULL ) ;
return 0 ;
}
static int F_30 ( void )
{
int V_35 ;
int V_36 ;
for ( V_35 = V_36 = 0 ; V_36 < V_31 ; V_36 ++ ) {
struct V_1 * V_2 ;
F_4 ( & V_14 [ V_36 ] . V_16 ) ;
F_18 (h, &(handle_hash[i].head), h_link) {
F_12 ( L_8 V_20 L_9 ,
V_2 -> V_11 , V_2 , V_2 -> V_12 ) ;
F_11 ( V_2 ) ;
V_35 ++ ;
}
F_7 ( & V_14 [ V_36 ] . V_16 ) ;
}
return V_35 ;
}
void F_31 ( void )
{
int V_37 ;
F_2 ( V_14 != NULL ) ;
V_37 = F_30 () ;
F_32 ( V_14 , sizeof( * V_14 ) * V_31 ) ;
V_14 = NULL ;
if ( V_37 != 0 )
F_12 ( L_10 , V_37 ) ;
}
