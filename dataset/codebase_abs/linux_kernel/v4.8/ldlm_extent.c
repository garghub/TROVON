T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_1 * V_9 ;
T_1 V_10 = 0 ;
F_2 ( V_2 ) ;
F_3 (tmp, &res->lr_granted) {
V_9 = F_4 ( V_8 , struct V_1 , V_11 ) ;
if ( F_5 ( V_9 ) )
continue;
if ( V_9 -> V_12 . V_13 . V_14 >= V_3 )
return V_3 ;
if ( V_9 -> V_12 . V_13 . V_14 + 1 > V_10 )
V_10 = V_9 -> V_12 . V_13 . V_14 + 1 ;
}
F_6 ( V_10 <= V_3 , L_1 , V_10 , V_3 ) ;
return V_10 ;
}
static void F_7 ( struct V_15 * V_16 , struct V_1 * V_17 )
{
F_8 ( ! V_17 -> V_18 ) ;
F_8 ( V_17 -> V_6 -> V_19 == V_20 ) ;
F_9 ( & V_17 -> V_21 , & V_16 -> V_22 ) ;
V_17 -> V_18 = V_16 ;
}
struct V_15 * F_10 ( struct V_1 * V_2 )
{
struct V_15 * V_23 ;
F_8 ( V_2 -> V_6 -> V_19 == V_20 ) ;
V_23 = F_11 ( V_24 , V_25 ) ;
if ( ! V_23 )
return NULL ;
F_12 ( & V_23 -> V_22 ) ;
F_7 ( V_23 , V_2 ) ;
return V_23 ;
}
void F_13 ( struct V_15 * V_23 )
{
if ( V_23 ) {
F_8 ( F_14 ( & V_23 -> V_22 ) ) ;
F_8 ( ! F_15 ( & V_23 -> V_26 ) ) ;
F_16 ( V_24 , V_23 ) ;
}
}
struct V_15 * F_17 ( struct V_1 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
if ( ! V_16 )
return NULL ;
F_8 ( ! F_14 ( & V_16 -> V_22 ) ) ;
V_17 -> V_18 = NULL ;
F_18 ( & V_17 -> V_21 ) ;
return F_14 ( & V_16 -> V_22 ) ? V_16 : NULL ;
}
static inline int F_19 ( enum V_27 V_28 )
{
int V_29 ;
F_8 ( V_28 != 0 ) ;
F_8 ( F_20 ( V_28 ) ) ;
for ( V_29 = - 1 ; V_28 ; V_29 ++ )
V_28 >>= 1 ;
F_8 ( V_29 < V_30 ) ;
return V_29 ;
}
void F_21 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_31 * V_32 , * * V_33 ;
struct V_15 * V_23 ;
struct V_34 * V_35 ;
int V_36 ;
F_8 ( V_2 -> V_37 == V_2 -> V_38 ) ;
V_23 = V_2 -> V_18 ;
F_8 ( V_23 ) ;
F_8 ( ! F_15 ( & V_23 -> V_26 ) ) ;
V_36 = F_19 ( V_2 -> V_37 ) ;
F_8 ( V_2 -> V_37 == 1 << V_36 ) ;
F_8 ( V_2 -> V_37 == V_5 -> V_39 [ V_36 ] . V_40 ) ;
V_35 = & V_2 -> V_12 . V_13 ;
F_22 ( & V_23 -> V_26 , V_35 -> V_41 , V_35 -> V_14 ) ;
V_33 = & V_5 -> V_39 [ V_36 ] . V_42 ;
V_32 = F_23 ( & V_23 -> V_26 , V_33 ) ;
if ( V_32 ) {
struct V_15 * V_8 ;
V_8 = F_17 ( V_2 ) ;
F_13 ( V_8 ) ;
F_7 ( F_24 ( V_32 ) , V_2 ) ;
}
V_5 -> V_39 [ V_36 ] . V_43 ++ ;
F_25 ( V_5 , & V_5 -> V_44 , V_2 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_15 * V_23 = V_2 -> V_18 ;
struct V_45 * V_46 ;
int V_36 ;
if ( ! V_23 || ! F_15 ( & V_23 -> V_26 ) )
return;
V_36 = F_19 ( V_2 -> V_37 ) ;
F_8 ( V_2 -> V_37 == 1 << V_36 ) ;
V_46 = & V_5 -> V_39 [ V_36 ] ;
F_8 ( V_46 -> V_42 ) ;
V_46 -> V_43 -- ;
V_23 = F_17 ( V_2 ) ;
if ( V_23 ) {
F_27 ( & V_23 -> V_26 , & V_46 -> V_42 ) ;
F_13 ( V_23 ) ;
}
}
void F_28 ( const T_2 * V_47 ,
T_3 * V_48 )
{
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_13 . V_41 = V_47 -> V_13 . V_41 ;
V_48 -> V_13 . V_14 = V_47 -> V_13 . V_14 ;
V_48 -> V_13 . V_49 = V_47 -> V_13 . V_49 ;
}
void F_29 ( const T_3 * V_48 ,
T_2 * V_47 )
{
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
V_47 -> V_13 . V_41 = V_48 -> V_13 . V_41 ;
V_47 -> V_13 . V_14 = V_48 -> V_13 . V_14 ;
V_47 -> V_13 . V_49 = V_48 -> V_13 . V_49 ;
}
