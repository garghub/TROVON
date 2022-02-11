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
void * F_15 ( T_1 V_20 , const void * V_21 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
void * V_22 = NULL ;
F_2 ( V_14 ) ;
V_6 = V_14 + ( V_20 & V_15 ) ;
F_16 () ;
F_17 (h, &bucket->head, h_link) {
if ( V_2 -> V_11 != V_20 || V_2 -> V_23 != V_21 )
continue;
F_4 ( & V_2 -> V_13 ) ;
if ( F_18 ( V_2 -> V_18 != 0 ) ) {
V_2 -> V_12 -> V_24 ( V_2 ) ;
V_22 = V_2 ;
}
F_7 ( & V_2 -> V_13 ) ;
break;
}
F_19 () ;
return V_22 ;
}
void F_20 ( struct V_25 * V_26 )
{
struct V_1 * V_2 ;
void * V_27 ;
V_2 = F_21 ( V_26 , struct V_1 , V_28 ) ;
V_27 = ( void * ) ( unsigned long ) V_2 -> V_11 ;
if ( V_2 -> V_12 -> V_29 )
V_2 -> V_12 -> V_29 ( V_27 , V_2 -> V_30 ) ;
else
F_22 ( V_27 ) ;
}
int F_23 ( void )
{
struct V_5 * V_6 ;
struct V_31 V_32 ;
int V_33 [ 2 ] ;
F_2 ( ! V_14 ) ;
V_14 = F_24 ( sizeof( * V_6 ) * V_34 ,
V_35 ) ;
if ( ! V_14 )
return - V_36 ;
F_8 ( & V_8 ) ;
for ( V_6 = V_14 + V_34 - 1 ; V_6 >= V_14 ;
V_6 -- ) {
F_25 ( & V_6 -> V_17 ) ;
F_8 ( & V_6 -> V_16 ) ;
}
F_26 ( V_33 , sizeof( V_33 ) ) ;
F_27 ( & V_32 ) ;
F_28 ( V_32 . V_37 ^ V_33 [ 0 ] , V_32 . V_38 ^ V_33 [ 1 ] ) ;
F_26 ( & V_9 , sizeof( V_9 ) ) ;
F_2 ( V_9 != 0ULL ) ;
return 0 ;
}
static int F_29 ( void )
{
int V_39 ;
int V_40 ;
for ( V_39 = V_40 = 0 ; V_40 < V_34 ; V_40 ++ ) {
struct V_1 * V_2 ;
F_4 ( & V_14 [ V_40 ] . V_16 ) ;
F_17 (h, &handle_hash[i].head, h_link) {
F_12 ( L_5 ,
V_2 -> V_11 , V_2 , V_2 -> V_12 ) ;
F_11 ( V_2 ) ;
V_39 ++ ;
}
F_7 ( & V_14 [ V_40 ] . V_16 ) ;
}
return V_39 ;
}
void F_30 ( void )
{
int V_41 ;
F_2 ( V_14 ) ;
V_41 = F_29 () ;
F_31 ( V_14 ) ;
V_14 = NULL ;
if ( V_41 != 0 )
F_12 ( L_6 , V_41 ) ;
}
