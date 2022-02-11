void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_2 ( L_1 ) ;
F_2 ( L_2 , V_2 -> type ) ;
F_2 ( L_3 , V_2 -> V_3 ) ;
F_2 ( L_4 , V_2 -> V_4 ) ;
F_2 ( L_5 , V_2 -> V_5 ) ;
F_2 ( L_6 , V_2 -> V_6 ) ;
F_2 ( L_7 , V_2 -> V_7 ) ;
F_2 ( L_8 , V_2 -> V_8 ) ;
F_2 ( L_9 , V_2 -> V_9 ) ;
F_2 ( L_10 , V_2 -> V_10 ) ;
F_2 ( L_11 , V_2 -> V_11 ) ;
}
void F_3 ( struct V_12 * V_2 )
{
if ( ! V_2 )
return;
F_2 ( L_12 ) ;
F_2 ( L_2 , V_2 -> V_13 . type ) ;
F_2 ( L_3 , V_2 -> V_13 . V_3 ) ;
F_2 ( L_4 , V_2 -> V_13 . V_4 ) ;
F_2 ( L_5 , V_2 -> V_13 . V_5 ) ;
F_2 ( L_6 , V_2 -> V_13 . V_6 ) ;
F_2 ( L_7 , V_2 -> V_13 . V_7 ) ;
F_2 ( L_8 , V_2 -> V_13 . V_8 ) ;
F_2 ( L_9 , V_2 -> V_13 . V_9 ) ;
F_2 ( L_10 , V_2 -> V_13 . V_10 ) ;
F_2 ( L_11 , V_2 -> V_13 . V_11 ) ;
F_2 ( L_13 , V_2 -> V_14 ) ;
F_2 ( L_14 , V_2 -> V_15 ) ;
F_2 ( L_15 , V_2 -> V_16 ) ;
F_2 ( L_16 , V_2 -> V_17 ) ;
}
int F_4 ( struct V_12 * * V_2 , const struct V_1 * V_13 )
{
struct V_12 * V_18 ;
F_5 ( ! V_2 ) ;
V_18 = F_6 ( sizeof( struct V_12 ) , V_19 ) ;
if ( ! V_18 )
return - V_20 ;
memcpy ( & V_18 -> V_13 , V_13 , sizeof( struct V_1 ) ) ;
* V_2 = V_18 ;
return 0 ;
}
void F_7 ( struct V_12 * V_2 )
{
F_8 ( V_2 ) ;
}
