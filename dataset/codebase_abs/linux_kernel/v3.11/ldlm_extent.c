T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_1 * V_9 ;
T_1 V_10 = 0 ;
V_11 ;
V_2 -> V_12 |= V_13 ;
F_2 (tmp, &res->lr_granted) {
V_9 = F_3 ( V_8 , struct V_1 , V_14 ) ;
if ( V_9 -> V_12 & V_13 )
continue;
if ( V_9 -> V_15 . V_16 . V_17 >= V_3 )
RETURN ( V_3 ) ;
if ( V_9 -> V_15 . V_16 . V_17 + 1 > V_10 )
V_10 = V_9 -> V_15 . V_16 . V_17 + 1 ;
}
F_4 ( V_10 <= V_3 , L_1 V_18 L_2 V_18 L_3 , V_10 , V_3 ) ;
RETURN ( V_10 ) ;
}
struct V_19 * F_5 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
V_11 ;
F_6 ( V_2 -> V_6 -> V_21 == V_22 ) ;
F_7 ( V_20 , V_23 , V_24 ) ;
if ( V_20 == NULL )
RETURN ( NULL ) ;
F_8 ( & V_20 -> V_25 ) ;
F_9 ( V_20 , V_2 ) ;
RETURN ( V_20 ) ;
}
void F_10 ( struct V_19 * V_20 )
{
if ( V_20 ) {
F_6 ( F_11 ( & V_20 -> V_25 ) ) ;
F_6 ( ! F_12 ( & V_20 -> V_26 ) ) ;
F_13 ( V_20 , V_23 , sizeof( * V_20 ) ) ;
}
}
void F_9 ( struct V_19 * V_27 ,
struct V_1 * V_28 )
{
F_6 ( V_28 -> V_29 == NULL ) ;
F_6 ( V_28 -> V_6 -> V_21 == V_22 ) ;
F_14 ( & V_28 -> V_30 , & V_27 -> V_25 ) ;
V_28 -> V_29 = V_27 ;
}
struct V_19 * F_15 ( struct V_1 * V_28 )
{
struct V_19 * V_27 = V_28 -> V_29 ;
if ( V_27 == NULL )
return NULL ;
F_6 ( ! F_11 ( & V_27 -> V_25 ) ) ;
V_28 -> V_29 = NULL ;
F_16 ( & V_28 -> V_30 ) ;
return ( F_11 ( & V_27 -> V_25 ) ? V_27 : NULL ) ;
}
static inline int F_17 ( T_2 V_31 )
{
int V_32 ;
F_6 ( V_31 != 0 ) ;
F_6 ( F_18 ( V_31 ) ) ;
for ( V_32 = - 1 ; V_31 ; V_32 ++ , V_31 >>= 1 ) ;
F_6 ( V_32 < V_33 ) ;
return V_32 ;
}
void F_19 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
struct V_34 * V_35 , * * V_36 ;
struct V_19 * V_20 ;
struct V_37 * V_38 ;
int V_39 ;
F_6 ( V_2 -> V_40 == V_2 -> V_41 ) ;
V_20 = V_2 -> V_29 ;
F_6 ( V_20 != NULL ) ;
F_6 ( ! F_12 ( & V_20 -> V_26 ) ) ;
V_39 = F_17 ( V_2 -> V_40 ) ;
F_6 ( V_2 -> V_40 == 1 << V_39 ) ;
F_6 ( V_2 -> V_40 == V_5 -> V_42 [ V_39 ] . V_43 ) ;
V_38 = & V_2 -> V_15 . V_16 ;
F_20 ( & V_20 -> V_26 , V_38 -> V_44 , V_38 -> V_17 ) ;
V_36 = & V_5 -> V_42 [ V_39 ] . V_45 ;
V_35 = F_21 ( & V_20 -> V_26 , V_36 ) ;
if ( V_35 ) {
struct V_19 * V_8 = F_15 ( V_2 ) ;
F_6 ( V_8 != NULL ) ;
F_10 ( V_8 ) ;
F_9 ( F_22 ( V_35 ) , V_2 ) ;
}
V_5 -> V_42 [ V_39 ] . V_46 ++ ;
F_23 ( V_5 , & V_5 -> V_47 , V_2 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_19 * V_20 = V_2 -> V_29 ;
struct V_48 * V_49 ;
int V_39 ;
if ( ! V_20 || ! F_12 ( & V_20 -> V_26 ) )
return;
V_39 = F_17 ( V_2 -> V_40 ) ;
F_6 ( V_2 -> V_40 == 1 << V_39 ) ;
V_49 = & V_5 -> V_42 [ V_39 ] ;
F_6 ( V_49 -> V_45 != NULL ) ;
V_49 -> V_46 -- ;
V_20 = F_15 ( V_2 ) ;
if ( V_20 ) {
F_25 ( & V_20 -> V_26 , & V_49 -> V_45 ) ;
F_10 ( V_20 ) ;
}
}
void F_26 ( const T_3 * V_50 ,
T_4 * V_51 )
{
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
V_51 -> V_16 . V_44 = V_50 -> V_16 . V_44 ;
V_51 -> V_16 . V_17 = V_50 -> V_16 . V_17 ;
V_51 -> V_16 . V_52 = V_50 -> V_16 . V_52 ;
}
void F_27 ( const T_4 * V_51 ,
T_3 * V_50 )
{
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_16 . V_44 = V_51 -> V_16 . V_44 ;
V_50 -> V_16 . V_17 = V_51 -> V_16 . V_17 ;
V_50 -> V_16 . V_52 = V_51 -> V_16 . V_52 ;
}
