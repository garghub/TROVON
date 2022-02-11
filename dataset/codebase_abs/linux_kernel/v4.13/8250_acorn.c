static int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * type = V_4 -> V_8 ;
struct V_9 V_10 ;
unsigned long V_11 ;
unsigned int V_12 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_13 ) ;
if ( ! V_6 )
return - V_14 ;
V_6 -> V_15 = type -> V_15 ;
V_11 = F_3 ( V_2 , type -> type ) ;
V_6 -> V_16 = F_4 ( V_2 , type -> type , 0 , 0 ) ;
if ( ! V_6 -> V_16 ) {
F_5 ( V_6 ) ;
return - V_14 ;
}
F_6 ( V_2 , V_6 ) ;
memset ( & V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 . V_17 . V_18 = V_2 -> V_18 ;
V_10 . V_17 . V_19 = V_20 | V_21 ;
V_10 . V_17 . V_22 = type -> V_22 ;
V_10 . V_17 . V_23 = V_24 ;
V_10 . V_17 . V_25 = 2 ;
V_10 . V_17 . V_26 = & V_2 -> V_26 ;
for ( V_12 = 0 ; V_12 < V_6 -> V_15 ; V_12 ++ ) {
V_10 . V_17 . V_27 = V_6 -> V_16 + type -> V_28 [ V_12 ] ;
V_10 . V_17 . V_29 = V_11 + type -> V_28 [ V_12 ] ;
V_6 -> V_30 [ V_12 ] = F_7 ( & V_10 ) ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_9 ( V_2 ) ;
int V_12 ;
F_6 ( V_2 , NULL ) ;
for ( V_12 = 0 ; V_12 < V_6 -> V_15 ; V_12 ++ )
if ( V_6 -> V_30 [ V_12 ] > 0 )
F_10 ( V_6 -> V_30 [ V_12 ] ) ;
F_5 ( V_6 ) ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_31 ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_31 ) ;
}
