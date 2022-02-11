int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
if ( F_2 ( V_4 -> V_9 < V_10 ) ) {
if ( F_3 ( V_2 , V_4 ) == 0 )
return 0 ;
return F_4 ( V_2 , V_4 ) ;
}
V_6 = V_2 -> V_11 ;
V_8 = F_5 ( V_6 -> V_12 -> V_13 ) ;
return F_6 ( V_2 , V_4 , & V_8 -> V_14 ) ;
}
static int F_7 ( struct V_15 * V_16 )
{
F_8 ( L_1 ) ;
return F_9 ( V_16 -> V_17 ) ;
}
static void F_10 ( struct V_15 * V_16 )
{
F_11 ( V_16 -> V_17 ) ;
}
int F_12 ( struct V_7 * V_8 )
{
struct V_15 * V_18 ;
int V_19 ;
V_18 = & V_8 -> V_20 ;
V_18 -> V_21 = V_22 ;
V_18 -> V_23 = sizeof( struct V_24 ) ;
V_18 -> V_25 = & F_7 ;
V_18 -> V_26 = & F_10 ;
V_19 = F_13 ( V_18 ) ;
if ( F_2 ( V_19 != 0 ) ) {
F_14 ( L_2 ) ;
return V_19 ;
}
V_8 -> V_27 . V_28 =
V_8 -> V_20 . V_17 ;
V_18 = & V_8 -> V_27 . V_16 ;
V_18 -> V_21 = V_29 ;
V_18 -> V_23 = sizeof( struct V_30 ) ;
V_18 -> V_25 = & V_31 ;
V_18 -> V_26 = & V_32 ;
V_19 = F_13 ( V_18 ) ;
if ( F_2 ( V_19 != 0 ) ) {
F_14 ( L_3 ) ;
goto V_33;
}
return 0 ;
V_33:
F_15 ( & V_8 -> V_20 ) ;
return V_19 ;
}
void F_16 ( struct V_7 * V_8 )
{
F_15 ( & V_8 -> V_27 . V_16 ) ;
F_15 ( & V_8 -> V_20 ) ;
}
