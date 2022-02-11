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
F_4 ( V_10 <= V_3 , L_1 V_17 L_2 V_17 L_3 , V_10 , V_3 ) ;
return V_10 ;
}
struct V_18 * F_5 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
F_6 ( V_2 -> V_6 -> V_20 == V_21 ) ;
F_7 ( V_19 , V_22 , V_23 ) ;
if ( V_19 == NULL )
return NULL ;
F_8 ( & V_19 -> V_24 ) ;
F_9 ( V_19 , V_2 ) ;
return V_19 ;
}
void F_10 ( struct V_18 * V_19 )
{
if ( V_19 ) {
F_6 ( F_11 ( & V_19 -> V_24 ) ) ;
F_6 ( ! F_12 ( & V_19 -> V_25 ) ) ;
F_13 ( V_19 , V_22 , sizeof( * V_19 ) ) ;
}
}
void F_9 ( struct V_18 * V_26 ,
struct V_1 * V_27 )
{
F_6 ( V_27 -> V_28 == NULL ) ;
F_6 ( V_27 -> V_6 -> V_20 == V_21 ) ;
F_14 ( & V_27 -> V_29 , & V_26 -> V_24 ) ;
V_27 -> V_28 = V_26 ;
}
struct V_18 * F_15 ( struct V_1 * V_27 )
{
struct V_18 * V_26 = V_27 -> V_28 ;
if ( V_26 == NULL )
return NULL ;
F_6 ( ! F_11 ( & V_26 -> V_24 ) ) ;
V_27 -> V_28 = NULL ;
F_16 ( & V_27 -> V_29 ) ;
return ( F_11 ( & V_26 -> V_24 ) ? V_26 : NULL ) ;
}
static inline int F_17 ( T_2 V_30 )
{
int V_31 ;
F_6 ( V_30 != 0 ) ;
F_6 ( F_18 ( V_30 ) ) ;
for ( V_31 = - 1 ; V_30 ; V_31 ++ , V_30 >>= 1 ) ;
F_6 ( V_31 < V_32 ) ;
return V_31 ;
}
void F_19 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_33 * V_34 , * * V_35 ;
struct V_18 * V_19 ;
struct V_36 * V_37 ;
int V_38 ;
F_6 ( V_2 -> V_39 == V_2 -> V_40 ) ;
V_19 = V_2 -> V_28 ;
F_6 ( V_19 != NULL ) ;
F_6 ( ! F_12 ( & V_19 -> V_25 ) ) ;
V_38 = F_17 ( V_2 -> V_39 ) ;
F_6 ( V_2 -> V_39 == 1 << V_38 ) ;
F_6 ( V_2 -> V_39 == V_5 -> V_41 [ V_38 ] . V_42 ) ;
V_37 = & V_2 -> V_14 . V_15 ;
F_20 ( & V_19 -> V_25 , V_37 -> V_43 , V_37 -> V_16 ) ;
V_35 = & V_5 -> V_41 [ V_38 ] . V_44 ;
V_34 = F_21 ( & V_19 -> V_25 , V_35 ) ;
if ( V_34 ) {
struct V_18 * V_8 = F_15 ( V_2 ) ;
F_6 ( V_8 != NULL ) ;
F_10 ( V_8 ) ;
F_9 ( F_22 ( V_34 ) , V_2 ) ;
}
V_5 -> V_41 [ V_38 ] . V_45 ++ ;
F_23 ( V_5 , & V_5 -> V_46 , V_2 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_18 * V_19 = V_2 -> V_28 ;
struct V_47 * V_48 ;
int V_38 ;
if ( ! V_19 || ! F_12 ( & V_19 -> V_25 ) )
return;
V_38 = F_17 ( V_2 -> V_39 ) ;
F_6 ( V_2 -> V_39 == 1 << V_38 ) ;
V_48 = & V_5 -> V_41 [ V_38 ] ;
F_6 ( V_48 -> V_44 != NULL ) ;
V_48 -> V_45 -- ;
V_19 = F_15 ( V_2 ) ;
if ( V_19 ) {
F_25 ( & V_19 -> V_25 , & V_48 -> V_44 ) ;
F_10 ( V_19 ) ;
}
}
void F_26 ( const T_3 * V_49 ,
T_4 * V_50 )
{
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_15 . V_43 = V_49 -> V_15 . V_43 ;
V_50 -> V_15 . V_16 = V_49 -> V_15 . V_16 ;
V_50 -> V_15 . V_51 = V_49 -> V_15 . V_51 ;
}
void F_27 ( const T_4 * V_50 ,
T_3 * V_49 )
{
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
V_49 -> V_15 . V_43 = V_50 -> V_15 . V_43 ;
V_49 -> V_15 . V_16 = V_50 -> V_15 . V_16 ;
V_49 -> V_15 . V_51 = V_50 -> V_15 . V_51 ;
}
