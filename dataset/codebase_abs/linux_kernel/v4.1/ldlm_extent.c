T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_1 * V_9 ;
T_1 V_10 = 0 ;
V_2 -> V_11 |= V_12 ;
F_2 (tmp, &res->lr_granted) {
V_9 = F_3 ( V_8 , struct V_1 , V_13 ) ;
if ( V_9 -> V_11 & V_12 )
continue;
if ( V_9 -> V_14 . V_15 . V_16 >= V_3 )
return V_3 ;
if ( V_9 -> V_14 . V_15 . V_16 + 1 > V_10 )
V_10 = V_9 -> V_14 . V_15 . V_16 + 1 ;
}
F_4 ( V_10 <= V_3 , L_1 , V_10 , V_3 ) ;
return V_10 ;
}
struct V_17 * F_5 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
F_6 ( V_2 -> V_6 -> V_19 == V_20 ) ;
F_7 ( V_18 , V_21 , V_22 ) ;
if ( V_18 == NULL )
return NULL ;
F_8 ( & V_18 -> V_23 ) ;
F_9 ( V_18 , V_2 ) ;
return V_18 ;
}
void F_10 ( struct V_17 * V_18 )
{
if ( V_18 ) {
F_6 ( F_11 ( & V_18 -> V_23 ) ) ;
F_6 ( ! F_12 ( & V_18 -> V_24 ) ) ;
F_13 ( V_18 , V_21 , sizeof( * V_18 ) ) ;
}
}
void F_9 ( struct V_17 * V_25 ,
struct V_1 * V_26 )
{
F_6 ( V_26 -> V_27 == NULL ) ;
F_6 ( V_26 -> V_6 -> V_19 == V_20 ) ;
F_14 ( & V_26 -> V_28 , & V_25 -> V_23 ) ;
V_26 -> V_27 = V_25 ;
}
struct V_17 * F_15 ( struct V_1 * V_26 )
{
struct V_17 * V_25 = V_26 -> V_27 ;
if ( V_25 == NULL )
return NULL ;
F_6 ( ! F_11 ( & V_25 -> V_23 ) ) ;
V_26 -> V_27 = NULL ;
F_16 ( & V_26 -> V_28 ) ;
return F_11 ( & V_25 -> V_23 ) ? V_25 : NULL ;
}
static inline int F_17 ( T_2 V_29 )
{
int V_30 ;
F_6 ( V_29 != 0 ) ;
F_6 ( F_18 ( V_29 ) ) ;
for ( V_30 = - 1 ; V_29 ; V_30 ++ )
V_29 >>= 1 ;
F_6 ( V_30 < V_31 ) ;
return V_30 ;
}
void F_19 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_32 * V_33 , * * V_34 ;
struct V_17 * V_18 ;
struct V_35 * V_36 ;
int V_37 ;
F_6 ( V_2 -> V_38 == V_2 -> V_39 ) ;
V_18 = V_2 -> V_27 ;
F_6 ( V_18 != NULL ) ;
F_6 ( ! F_12 ( & V_18 -> V_24 ) ) ;
V_37 = F_17 ( V_2 -> V_38 ) ;
F_6 ( V_2 -> V_38 == 1 << V_37 ) ;
F_6 ( V_2 -> V_38 == V_5 -> V_40 [ V_37 ] . V_41 ) ;
V_36 = & V_2 -> V_14 . V_15 ;
F_20 ( & V_18 -> V_24 , V_36 -> V_42 , V_36 -> V_16 ) ;
V_34 = & V_5 -> V_40 [ V_37 ] . V_43 ;
V_33 = F_21 ( & V_18 -> V_24 , V_34 ) ;
if ( V_33 ) {
struct V_17 * V_8 ;
V_8 = F_15 ( V_2 ) ;
F_6 ( V_8 != NULL ) ;
F_10 ( V_8 ) ;
F_9 ( F_22 ( V_33 ) , V_2 ) ;
}
V_5 -> V_40 [ V_37 ] . V_44 ++ ;
F_23 ( V_5 , & V_5 -> V_45 , V_2 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = V_2 -> V_27 ;
struct V_46 * V_47 ;
int V_37 ;
if ( ! V_18 || ! F_12 ( & V_18 -> V_24 ) )
return;
V_37 = F_17 ( V_2 -> V_38 ) ;
F_6 ( V_2 -> V_38 == 1 << V_37 ) ;
V_47 = & V_5 -> V_40 [ V_37 ] ;
F_6 ( V_47 -> V_43 != NULL ) ;
V_47 -> V_44 -- ;
V_18 = F_15 ( V_2 ) ;
if ( V_18 ) {
F_25 ( & V_18 -> V_24 , & V_47 -> V_43 ) ;
F_10 ( V_18 ) ;
}
}
void F_26 ( const T_3 * V_48 ,
T_4 * V_49 )
{
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
V_49 -> V_15 . V_42 = V_48 -> V_15 . V_42 ;
V_49 -> V_15 . V_16 = V_48 -> V_15 . V_16 ;
V_49 -> V_15 . V_50 = V_48 -> V_15 . V_50 ;
}
void F_27 ( const T_4 * V_49 ,
T_3 * V_48 )
{
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_15 . V_42 = V_49 -> V_15 . V_42 ;
V_48 -> V_15 . V_16 = V_49 -> V_15 . V_16 ;
V_48 -> V_15 . V_50 = V_49 -> V_15 . V_50 ;
}
