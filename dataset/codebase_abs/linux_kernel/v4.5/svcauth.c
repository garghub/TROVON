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
V_2 -> V_16 = 0 ;
F_7 ( & V_2 -> V_17 ) ;
V_2 -> V_18 = V_6 ;
return V_6 -> V_19 ( V_2 , V_3 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
V_2 -> V_20 = NULL ;
return V_2 -> V_18 -> V_21 ( V_2 ) ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_18 ;
int V_22 = 0 ;
V_2 -> V_18 = NULL ;
if ( V_6 ) {
V_22 = V_6 -> V_23 ( V_2 ) ;
F_10 ( V_6 -> V_13 ) ;
}
return V_22 ;
}
int
F_11 ( T_2 V_4 , struct V_5 * V_6 )
{
int V_22 = - V_24 ;
F_4 ( & V_10 ) ;
if ( V_4 < V_11 && V_12 [ V_4 ] == NULL ) {
V_12 [ V_4 ] = V_6 ;
V_22 = 0 ;
}
F_6 ( & V_10 ) ;
return V_22 ;
}
void
F_12 ( T_2 V_4 )
{
F_4 ( & V_10 ) ;
if ( V_4 < V_11 )
V_12 [ V_4 ] = NULL ;
F_6 ( & V_10 ) ;
}
void F_13 ( struct V_25 * V_26 )
{
if ( F_14 ( & V_26 -> V_27 . V_28 , & V_29 ) ) {
F_15 ( & V_26 -> V_30 ) ;
V_26 -> V_31 -> V_32 ( V_26 ) ;
F_6 ( & V_29 ) ;
}
}
struct V_25 *
F_16 ( char * V_33 , struct V_25 * V_34 )
{
struct V_25 * V_35 ;
struct V_36 * V_9 ;
V_9 = & V_37 [ F_17 ( V_33 , V_38 ) ] ;
F_4 ( & V_29 ) ;
F_18 (hp, head, hash) {
if ( strcmp ( V_35 -> V_33 , V_33 ) == 0 ) {
F_19 ( & V_35 -> V_27 ) ;
F_6 ( & V_29 ) ;
return V_35 ;
}
}
if ( V_34 )
F_20 ( & V_34 -> V_30 , V_9 ) ;
F_6 ( & V_29 ) ;
return V_34 ;
}
struct V_25 * F_21 ( char * V_33 )
{
return F_16 ( V_33 , NULL ) ;
}
