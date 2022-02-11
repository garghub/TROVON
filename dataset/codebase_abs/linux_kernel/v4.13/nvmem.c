static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = V_6 -> V_12 ;
F_2 ( F_3 ( V_4 ) , V_13 ) ;
return F_4 ( V_11 -> V_14 , V_8 , V_9 , V_7 ) ;
}
static T_1
F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = V_6 -> V_12 ;
F_2 ( F_3 ( V_4 ) , V_13 ) ;
return F_6 ( V_11 -> V_14 , V_8 , V_9 , V_7 ) ;
}
static int F_7 ( struct V_10 * V_11 )
{
int V_15 ;
V_11 -> V_16 = F_8 ( V_11 -> V_17 . V_18 ,
sizeof( struct V_5 ) ,
V_19 ) ;
if ( ! V_11 -> V_16 )
return - V_20 ;
V_11 -> V_16 -> V_6 . V_21 = L_1 ;
V_11 -> V_16 -> V_6 . V_22 = 0644 ;
V_11 -> V_16 -> V_12 = V_11 ;
F_9 ( V_11 -> V_16 ) ;
V_11 -> V_16 -> V_23 = F_1 ;
V_11 -> V_16 -> V_24 = F_5 ;
V_11 -> V_16 -> V_25 = V_11 -> V_26 -> V_25 ;
V_15 = F_10 ( & V_11 -> V_17 . V_18 -> V_4 ,
V_11 -> V_16 ) ;
if ( V_15 ) {
F_11 ( V_11 -> V_17 . V_18 , V_11 -> V_16 ) ;
V_11 -> V_16 = NULL ;
}
return V_15 ;
}
static void F_12 ( struct V_10 * V_11 )
{
F_13 ( & V_11 -> V_17 . V_18 -> V_4 , V_11 -> V_16 ) ;
}
void F_14 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_26 )
return;
V_11 -> V_26 -> V_17 = & V_11 -> V_17 ;
V_11 -> V_26 -> V_27 = V_11 -> V_27 ;
V_11 -> V_14 = F_15 ( V_11 -> V_26 ) ;
if ( F_16 ( V_11 -> V_14 ) )
return;
if ( V_11 -> V_28 )
F_7 ( V_11 ) ;
}
void F_17 ( struct V_10 * V_11 )
{
if ( F_16 ( V_11 -> V_14 ) )
return;
if ( V_11 -> V_16 )
F_12 ( V_11 ) ;
F_18 ( V_11 -> V_14 ) ;
}
