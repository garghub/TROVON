int
F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_2 V_4 ;
struct V_5 * V_6 ;
* V_3 = V_7 ;
V_4 = F_2 ( & V_2 -> V_8 . V_9 [ 0 ] ) ;
F_3 ( L_1 , V_4 ) ;
F_4 ( & V_10 ) ;
if ( V_4 >= V_11 || ! ( V_6 = V_12 [ V_4 ] ) ||
! F_5 ( V_6 -> V_13 ) ) {
F_6 ( & V_10 ) ;
* V_3 = V_14 ;
return V_15 ;
}
F_6 ( & V_10 ) ;
V_2 -> V_16 = V_6 ;
return V_6 -> V_17 ( V_2 , V_3 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
return V_2 -> V_16 -> V_18 ( V_2 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_16 ;
int V_19 = 0 ;
V_2 -> V_16 = NULL ;
if ( V_6 ) {
V_19 = V_6 -> V_20 ( V_2 ) ;
F_9 ( V_6 -> V_13 ) ;
}
return V_19 ;
}
int
F_10 ( T_2 V_4 , struct V_5 * V_6 )
{
int V_19 = - V_21 ;
F_4 ( & V_10 ) ;
if ( V_4 < V_11 && V_12 [ V_4 ] == NULL ) {
V_12 [ V_4 ] = V_6 ;
V_19 = 0 ;
}
F_6 ( & V_10 ) ;
return V_19 ;
}
void
F_11 ( T_2 V_4 )
{
F_4 ( & V_10 ) ;
if ( V_4 < V_11 )
V_12 [ V_4 ] = NULL ;
F_6 ( & V_10 ) ;
}
void F_12 ( struct V_22 * V_23 )
{
if ( F_13 ( & V_23 -> V_24 . V_25 , & V_26 ) ) {
F_14 ( & V_23 -> V_27 ) ;
V_23 -> V_28 -> V_29 ( V_23 ) ;
F_6 ( & V_26 ) ;
}
}
struct V_22 *
F_15 ( char * V_30 , struct V_22 * V_31 )
{
struct V_22 * V_32 ;
struct V_33 * V_9 ;
V_9 = & V_34 [ F_16 ( V_30 , V_35 ) ] ;
F_4 ( & V_26 ) ;
F_17 (hp, head, hash) {
if ( strcmp ( V_32 -> V_30 , V_30 ) == 0 ) {
F_18 ( & V_32 -> V_24 ) ;
F_6 ( & V_26 ) ;
return V_32 ;
}
}
if ( V_31 )
F_19 ( & V_31 -> V_27 , V_9 ) ;
F_6 ( & V_26 ) ;
return V_31 ;
}
struct V_22 * F_20 ( char * V_30 )
{
return F_15 ( V_30 , NULL ) ;
}
