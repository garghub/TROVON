void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_2 ( V_2 ) ;
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
F_10 ( V_19 , L_2 ,
V_2 , V_2 -> V_11 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
if ( F_3 ( & V_2 -> V_7 ) ) {
F_12 ( L_3 ,
V_2 -> V_11 ) ;
return;
}
F_10 ( V_19 , L_4 ,
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
void * F_15 ( T_1 V_20 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
void * V_21 = NULL ;
F_2 ( V_14 ) ;
V_6 = V_14 + ( V_20 & V_15 ) ;
F_16 () ;
F_17 (h, &bucket->head, h_link) {
if ( V_2 -> V_11 != V_20 )
continue;
F_4 ( & V_2 -> V_13 ) ;
if ( F_18 ( V_2 -> V_18 != 0 ) ) {
V_2 -> V_12 -> V_22 ( V_2 ) ;
V_21 = V_2 ;
}
F_7 ( & V_2 -> V_13 ) ;
break;
}
F_19 () ;
return V_21 ;
}
void F_20 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_21 ( V_24 ) ;
void * V_25 = ( void * ) ( unsigned long ) V_2 -> V_11 ;
if ( V_2 -> V_12 -> V_26 )
V_2 -> V_12 -> V_26 ( V_25 , V_2 -> V_27 ) ;
else
F_22 ( V_25 ) ;
}
int F_23 ( void )
{
struct V_5 * V_6 ;
struct V_28 V_29 ;
int V_30 [ 2 ] ;
F_2 ( ! V_14 ) ;
V_14 = F_24 ( sizeof( * V_6 ) * V_31 ,
V_32 ) ;
if ( ! V_14 )
return - V_33 ;
F_8 ( & V_8 ) ;
for ( V_6 = V_14 + V_31 - 1 ; V_6 >= V_14 ;
V_6 -- ) {
F_25 ( & V_6 -> V_17 ) ;
F_8 ( & V_6 -> V_16 ) ;
}
F_26 ( V_30 , sizeof( V_30 ) ) ;
F_27 ( & V_29 ) ;
F_28 ( V_29 . V_34 ^ V_30 [ 0 ] , V_29 . V_35 ^ V_30 [ 1 ] ) ;
F_26 ( & V_9 , sizeof( V_9 ) ) ;
F_2 ( V_9 != 0ULL ) ;
return 0 ;
}
static int F_29 ( void )
{
int V_36 ;
int V_37 ;
for ( V_36 = V_37 = 0 ; V_37 < V_31 ; V_37 ++ ) {
struct V_1 * V_2 ;
F_4 ( & V_14 [ V_37 ] . V_16 ) ;
F_17 (h, &(handle_hash[i].head), h_link) {
F_12 ( L_5 ,
V_2 -> V_11 , V_2 , V_2 -> V_12 ) ;
F_11 ( V_2 ) ;
V_36 ++ ;
}
F_7 ( & V_14 [ V_37 ] . V_16 ) ;
}
return V_36 ;
}
void F_30 ( void )
{
int V_38 ;
F_2 ( V_14 ) ;
V_38 = F_29 () ;
F_31 ( V_14 ) ;
V_14 = NULL ;
if ( V_38 != 0 )
F_12 ( L_6 , V_38 ) ;
}
