static inline int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
return 0 ;
V_2 -> V_3 = F_2 (
V_4 * sizeof( struct V_5 ) ,
V_6 ) ;
if ( ! V_2 -> V_3 )
return - V_7 ;
return 0 ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
return;
F_4 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
int V_8 ;
F_6 ( & V_2 -> V_9 ) ;
F_6 ( & V_2 -> V_10 ) ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ )
F_7 ( & V_2 -> V_3 [ V_8 ] . V_11 ,
& V_2 -> V_9 ) ;
}
struct V_12 * F_8 ( int V_13 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_14 ;
int V_8 , V_15 ;
F_9 ( L_1 ) ;
V_14 = F_10 ( sizeof( struct V_1 ) + V_13 ) ;
if ( ! V_14 ) {
F_11 ( L_2 ) ;
return NULL ;
}
V_2 = (struct V_1 * ) F_12 ( V_14 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) + V_13 ) ;
V_2 -> V_14 = V_14 ;
V_15 = F_1 ( V_2 ) ;
if ( V_15 ) {
F_11 ( L_3 , V_15 ) ;
goto V_16;
}
F_5 ( V_2 ) ;
V_2 -> V_17 = V_18 ;
V_2 -> V_19 = V_20 ;
V_2 -> V_21 = 1 ;
V_2 -> V_22 = 1 ;
V_2 -> V_23 = 1 ;
V_2 -> V_24 = 1 ;
V_2 -> V_25 = V_25 ;
F_13 ( & V_2 -> V_26 ) ;
F_13 ( & V_2 -> V_27 ) ;
F_13 ( & V_2 -> V_28 ) ;
F_14 ( & ( V_2 -> V_29 ) , 0 ) ;
F_15 ( & V_2 -> V_30 , L_4 , & V_2 -> V_26 ) ;
V_2 -> V_31 = 0 ;
V_2 -> V_32 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_34 = 0 ;
V_2 -> V_24 = 1 ;
V_2 -> V_35 = 0 ;
V_2 -> V_36 = 0 ;
memset ( V_2 -> V_37 , 0 , sizeof( struct V_38 ) * 32 ) ;
F_16 ( V_2 ) ;
V_2 -> V_39 = F_2 ( sizeof( struct V_40 ) , V_6 ) ;
if ( V_2 -> V_39 == NULL )
return NULL ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
for ( V_8 = 0 ; V_8 < V_41 ; V_8 ++ )
F_6 ( & V_2 -> V_42 [ V_8 ] ) ;
for ( V_8 = 0 ; V_8 < 17 ; V_8 ++ ) {
V_2 -> V_43 [ V_8 ] = - 1 ;
V_2 -> V_44 [ V_8 ] = - 1 ;
V_2 -> V_45 [ V_8 ] = 0 ;
}
return V_14 ;
V_16:
F_20 ( V_14 ) ;
return NULL ;
}
void F_21 ( struct V_12 * V_14 )
{
struct V_1 * V_2 = (struct V_1 * )
F_12 ( V_14 ) ;
F_4 ( V_2 -> V_39 ) ;
V_2 -> V_39 = NULL ;
F_22 ( V_2 ) ;
F_23 ( & V_2 -> V_30 ) ;
F_3 ( V_2 ) ;
F_20 ( V_14 ) ;
}
static int T_1 F_24 ( void )
{
return 0 ;
}
static void T_2 F_25 ( void )
{
}
