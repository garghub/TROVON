static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
V_7 = V_4 -> V_8 [ 0 ] ;
F_2 ( V_9
L_1 , V_2 -> V_10 , V_11 . V_12 ,
V_7 , V_4 -> V_8 [ 1 ] ? L_2 : L_3 ) ;
if ( ! F_3 ( V_7 , V_13 , V_11 . V_12 ) ) {
F_2 ( L_4 ) ;
return - V_14 ;
}
V_2 -> V_7 = V_7 ;
V_2 -> V_15 = V_16 -> V_17 ;
if ( F_4 ( V_2 , sizeof( struct V_18 ) ) < 0 ) {
F_2 ( V_19 L_5 ) ;
return - V_20 ;
}
V_21 -> V_22 = V_4 -> V_8 [ 1 ] ;
if ( F_5 ( V_2 , 1 ) < 0 ) {
F_2 ( V_19 L_6 ) ;
return - V_20 ;
}
V_6 = V_2 -> V_23 ;
V_6 -> V_24 = NULL ;
V_6 -> V_25 = ( 0x1 << V_26 ) - 1 ;
V_6 -> V_27 = & V_28 ;
V_6 -> type = V_29 ;
V_6 -> V_30 = V_31 | V_32 ;
V_6 -> V_33 = V_34 ;
V_6 -> V_35 = & V_36 ;
V_6 -> V_37 = & V_38 ;
F_6 ( V_2 ) ;
F_2 ( V_9 L_7 ) ;
return 1 ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_2 ( V_9
L_8 , V_2 -> V_10 , V_11 . V_12 ) ;
if ( V_2 -> V_7 )
F_8 ( V_2 -> V_7 , V_13 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_34 ; ++ V_39 ) {
F_9 ( 0 , F_10 ( V_39 ) ) ;
F_9 ( 0 , F_11 ( V_39 ) ) ;
}
F_12 ( F_10 ( 0 ) ) ;
}
static int V_36 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_40 * V_41 , unsigned int * V_42 )
{
int V_39 ;
int V_43 = F_13 ( V_41 -> V_44 ) ;
for ( V_39 = 0 ; V_39 < V_41 -> V_45 ; ++ V_39 ) {
F_9 ( F_14 ( V_42 [ V_39 ] ) , F_10 ( V_43 ) ) ;
F_9 ( F_15 ( V_42 [ V_39 ] ) , F_11 ( V_43 ) ) ;
V_21 -> V_46 [ V_43 ] = V_42 [ V_39 ] ;
if ( ! V_21 -> V_22 )
F_12 ( F_10 ( V_43 ) ) ;
}
return V_39 ;
}
static int V_38 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_40 * V_41 , unsigned int * V_42 )
{
int V_39 ;
int V_43 = F_13 ( V_41 -> V_44 ) ;
for ( V_39 = 0 ; V_39 < V_41 -> V_45 ; V_39 ++ ) {
if ( V_21 -> V_22 )
F_12 ( F_10 ( V_43 ) ) ;
V_42 [ V_39 ] = V_21 -> V_46 [ V_43 ] ;
}
return V_39 ;
}
static int T_1 F_16 ( void )
{
return F_17 ( & V_11 ) ;
}
static void T_2 F_18 ( void )
{
F_19 ( & V_11 ) ;
}
