int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 =
V_6 -> V_10 -> V_11 -> V_12 ;
if ( F_2 ( V_4 -> V_13 < V_14 ) )
return F_3 ( V_2 , V_4 ) ;
return F_4 ( V_2 , V_4 , & V_9 -> V_15 . V_16 ) ;
}
static int
F_5 ( struct V_17 * V_18 )
{
return F_6 ( V_18 -> V_19 ) ;
}
static void
F_7 ( struct V_17 * V_18 )
{
F_8 ( V_18 -> V_19 ) ;
}
int
F_9 ( struct V_8 * V_9 )
{
struct V_17 * V_20 ;
int V_21 ;
V_20 = & V_9 -> V_15 . V_22 ;
V_20 -> V_23 = V_24 ;
V_20 -> V_25 = sizeof( struct V_26 ) ;
V_20 -> V_27 = & F_5 ;
V_20 -> V_28 = & F_7 ;
V_21 = F_10 ( V_20 ) ;
if ( F_2 ( V_21 != 0 ) ) {
F_11 ( L_1 ) ;
V_9 -> V_15 . V_22 . V_28 = NULL ;
return V_21 ;
}
V_9 -> V_15 . V_29 . V_30 = V_20 -> V_19 ;
V_20 = & V_9 -> V_15 . V_29 . V_18 ;
V_20 -> V_23 = V_31 ;
V_20 -> V_25 = sizeof( struct V_32 ) ;
V_20 -> V_27 = & V_33 ;
V_20 -> V_28 = & V_34 ;
V_21 = F_10 ( V_20 ) ;
if ( F_2 ( V_21 != 0 ) ) {
F_11 ( L_2 ) ;
F_12 ( & V_9 -> V_15 . V_22 ) ;
V_9 -> V_15 . V_22 . V_28 = NULL ;
return V_21 ;
}
return 0 ;
}
void
F_13 ( struct V_8 * V_9 )
{
if ( V_9 -> V_15 . V_22 . V_28 == NULL )
return;
F_12 ( & V_9 -> V_15 . V_29 . V_18 ) ;
F_12 ( & V_9 -> V_15 . V_22 ) ;
V_9 -> V_15 . V_22 . V_28 = NULL ;
}
