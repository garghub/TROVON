static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
if ( V_5 < 0 )
return - V_6 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_7 &= ~ V_8 ;
V_2 -> V_7 |= V_9 ;
V_2 -> V_10 . V_3 = V_11 ;
V_2 -> V_10 . V_4 = V_5 ;
V_2 -> V_12 . V_3 = V_13 ;
V_2 -> V_14 . V_15 . V_3 = V_3 ;
V_2 -> V_14 . V_15 . V_4 = V_4 ;
return 0 ;
}
void F_2 ( int V_3 , int V_4 , int type )
{
struct V_1 V_2 ;
if ( F_1 ( & V_2 , V_3 , V_4 ) < 0 )
return;
V_2 . type = type ;
F_3 ( V_11 , & V_2 , 0 , 0 ) ;
}
int F_4 ( int V_3 , int V_4 , struct V_1 * V_2 )
{
V_2 -> V_7 = V_9 ;
V_2 -> V_10 . V_3 = V_11 ;
V_2 -> V_10 . V_4 = V_5 ;
V_2 -> V_12 . V_3 = V_3 ;
V_2 -> V_12 . V_4 = V_4 ;
return F_3 ( V_11 , V_2 , 0 , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_16 , void * V_17 , int V_18 , int V_19 )
{
return F_6 ( V_2 , V_18 , V_19 ) ;
}
int T_1 F_7 ( void )
{
struct V_20 V_21 ;
struct V_22 * V_4 ;
V_4 = F_8 ( sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return - V_24 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_25 = V_26 ;
V_21 . V_27 = F_5 ;
V_11 = F_9 ( NULL , 0 , L_1 ) ;
strcpy ( V_4 -> V_28 , L_2 ) ;
V_4 -> V_29 = V_30 ;
V_4 -> V_29 |= V_31 | V_32 ;
V_4 -> V_33 = & V_21 ;
V_4 -> type = 0 ;
V_4 -> V_7 = V_34 ;
V_4 -> V_15 . V_3 = V_11 ;
V_4 -> V_15 . V_4 = V_35 ;
F_10 ( V_11 , V_36 , V_4 ) ;
strcpy ( V_4 -> V_28 , L_3 ) ;
V_4 -> V_29 = V_31 | V_32 ;
V_4 -> V_33 = NULL ;
V_4 -> type = 0 ;
V_4 -> V_7 = V_34 ;
V_4 -> V_15 . V_3 = V_11 ;
V_4 -> V_15 . V_4 = V_37 ;
F_10 ( V_11 , V_36 , V_4 ) ;
V_5 = V_4 -> V_15 . V_4 ;
F_11 ( V_4 ) ;
return 0 ;
}
void T_2 F_12 ( void )
{
int V_38 = V_11 ;
if ( V_38 >= 0 ) {
V_11 = - 1 ;
V_5 = - 1 ;
F_13 ( V_38 ) ;
}
}
