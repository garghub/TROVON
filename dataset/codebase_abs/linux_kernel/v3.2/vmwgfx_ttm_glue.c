int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
if ( F_2 ( V_4 -> V_9 < V_10 ) ) {
F_3 ( L_1 ) ;
return - V_11 ;
}
V_6 = V_2 -> V_12 ;
V_8 = F_4 ( V_6 -> V_13 -> V_14 ) ;
return F_5 ( V_2 , V_4 , & V_8 -> V_15 ) ;
}
static int F_6 ( struct V_16 * V_17 )
{
F_7 ( L_2 ) ;
return F_8 ( V_17 -> V_18 ) ;
}
static void F_9 ( struct V_16 * V_17 )
{
F_10 ( V_17 -> V_18 ) ;
}
int F_11 ( struct V_7 * V_8 )
{
struct V_16 * V_19 ;
int V_20 ;
V_19 = & V_8 -> V_21 ;
V_19 -> V_22 = V_23 ;
V_19 -> V_24 = sizeof( struct V_25 ) ;
V_19 -> V_26 = & F_6 ;
V_19 -> V_27 = & F_9 ;
V_20 = F_12 ( V_19 ) ;
if ( F_2 ( V_20 != 0 ) ) {
F_3 ( L_3 ) ;
return V_20 ;
}
V_8 -> V_28 . V_29 =
V_8 -> V_21 . V_18 ;
V_19 = & V_8 -> V_28 . V_17 ;
V_19 -> V_22 = V_30 ;
V_19 -> V_24 = sizeof( struct V_31 ) ;
V_19 -> V_26 = & V_32 ;
V_19 -> V_27 = & V_33 ;
V_20 = F_12 ( V_19 ) ;
if ( F_2 ( V_20 != 0 ) ) {
F_3 ( L_4 ) ;
goto V_34;
}
return 0 ;
V_34:
F_13 ( & V_8 -> V_21 ) ;
return V_20 ;
}
void F_14 ( struct V_7 * V_8 )
{
F_13 ( & V_8 -> V_28 . V_17 ) ;
F_13 ( & V_8 -> V_21 ) ;
}
