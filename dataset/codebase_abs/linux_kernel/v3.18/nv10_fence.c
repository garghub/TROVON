int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 = F_2 ( V_4 , 2 ) ;
if ( V_6 == 0 ) {
F_3 ( V_4 , 0 , V_7 , 1 ) ;
F_4 ( V_4 , V_2 -> V_8 . V_9 ) ;
F_5 ( V_4 ) ;
}
return V_6 ;
}
static int
F_6 ( struct V_1 * V_2 ,
struct V_3 * V_10 , struct V_3 * V_4 )
{
return - V_11 ;
}
T_1
F_7 ( struct V_3 * V_4 )
{
return F_8 ( V_4 , 0x0048 ) ;
}
void
F_9 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_2 ;
int V_14 ;
F_10 ( & V_13 -> V_8 ) ;
for ( V_14 = 0 ; V_14 < F_11 ( V_13 -> V_15 ) ; V_14 ++ )
F_12 ( & V_13 -> V_15 [ V_14 ] ) ;
F_12 ( & V_13 -> V_16 ) ;
V_4 -> V_2 = NULL ;
F_13 ( & V_13 -> V_8 ) ;
}
int
F_14 ( struct V_3 * V_4 )
{
struct V_12 * V_13 ;
V_13 = V_4 -> V_2 = F_15 ( sizeof( * V_13 ) , V_17 ) ;
if ( ! V_13 )
return - V_18 ;
F_16 ( V_4 , & V_13 -> V_8 ) ;
V_13 -> V_8 . V_19 = F_1 ;
V_13 -> V_8 . V_20 = F_7 ;
V_13 -> V_8 . V_21 = F_6 ;
return 0 ;
}
void
F_17 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_2 ;
F_18 ( V_25 -> V_26 ) ;
if ( V_25 -> V_26 )
F_19 ( V_25 -> V_26 ) ;
F_20 ( NULL , & V_25 -> V_26 ) ;
V_23 -> V_2 = NULL ;
F_21 ( V_25 ) ;
}
int
F_22 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
V_25 = V_23 -> V_2 = F_15 ( sizeof( * V_25 ) , V_17 ) ;
if ( ! V_25 )
return - V_18 ;
V_25 -> V_8 . V_27 = F_17 ;
V_25 -> V_8 . V_28 = F_14 ;
V_25 -> V_8 . V_29 = F_9 ;
V_25 -> V_8 . V_30 = 31 ;
V_25 -> V_8 . V_31 = F_23 ( V_25 -> V_8 . V_30 ) ;
F_24 ( & V_25 -> V_32 ) ;
return 0 ;
}
