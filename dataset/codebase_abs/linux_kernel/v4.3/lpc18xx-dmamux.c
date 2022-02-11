static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_3 ;
unsigned long V_8 ;
F_3 ( & V_5 -> V_9 , V_8 ) ;
V_7 -> V_10 = false ;
F_4 ( & V_5 -> V_9 , V_8 ) ;
}
static void * F_5 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = F_6 ( V_14 -> V_17 ) ;
struct V_4 * V_5 = F_7 ( V_16 ) ;
unsigned long V_8 ;
unsigned V_7 ;
if ( V_12 -> V_18 != 3 ) {
F_8 ( & V_16 -> V_2 , L_1 ) ;
return F_9 ( - V_19 ) ;
}
V_7 = V_12 -> args [ 0 ] ;
if ( V_7 >= V_5 -> V_20 ) {
F_8 ( & V_16 -> V_2 , L_2 ,
V_12 -> args [ 0 ] ) ;
return F_9 ( - V_19 ) ;
}
if ( V_12 -> args [ 1 ] > V_21 ) {
F_8 ( & V_16 -> V_2 , L_3 ,
V_12 -> args [ 1 ] ) ;
return F_9 ( - V_19 ) ;
}
V_12 -> V_22 = F_10 ( V_14 -> V_17 , L_4 , 0 ) ;
if ( ! V_12 -> V_22 ) {
F_8 ( & V_16 -> V_2 , L_5 ) ;
return F_9 ( - V_19 ) ;
}
F_3 ( & V_5 -> V_9 , V_8 ) ;
if ( V_5 -> V_23 [ V_7 ] . V_10 ) {
F_4 ( & V_5 -> V_9 , V_8 ) ;
F_8 ( & V_16 -> V_2 , L_6 ,
V_7 , V_7 , V_5 -> V_23 [ V_7 ] . V_24 ) ;
F_11 ( V_12 -> V_22 ) ;
return F_9 ( - V_25 ) ;
}
V_5 -> V_23 [ V_7 ] . V_10 = true ;
V_5 -> V_23 [ V_7 ] . V_24 = V_12 -> args [ 1 ] ;
F_12 ( V_5 -> V_26 , V_27 ,
F_13 ( V_7 ) ,
F_14 ( V_5 -> V_23 [ V_7 ] . V_24 , V_7 ) ) ;
F_4 ( & V_5 -> V_9 , V_8 ) ;
V_12 -> args [ 1 ] = V_12 -> args [ 2 ] ;
V_12 -> V_18 = 2 ;
F_15 ( & V_16 -> V_2 , L_7 , V_7 ,
V_5 -> V_23 [ V_7 ] . V_24 , V_7 ) ;
return & V_5 -> V_23 [ V_7 ] ;
}
static int F_16 ( struct V_15 * V_16 )
{
struct V_28 * V_29 , * V_22 = V_16 -> V_2 . V_17 ;
struct V_4 * V_5 ;
int V_30 ;
V_5 = F_17 ( & V_16 -> V_2 , sizeof( * V_5 ) , V_31 ) ;
if ( ! V_5 )
return - V_32 ;
V_5 -> V_26 = F_18 ( L_8 ) ;
if ( F_19 ( V_5 -> V_26 ) ) {
F_8 ( & V_16 -> V_2 , L_9 ) ;
return F_20 ( V_5 -> V_26 ) ;
}
V_30 = F_21 ( V_22 , L_10 ,
& V_5 -> V_33 ) ;
if ( V_30 ) {
F_8 ( & V_16 -> V_2 , L_11 ) ;
return V_30 ;
}
V_29 = F_10 ( V_22 , L_4 , 0 ) ;
if ( ! V_29 ) {
F_8 ( & V_16 -> V_2 , L_5 ) ;
return - V_34 ;
}
V_30 = F_21 ( V_29 , L_10 ,
& V_5 -> V_20 ) ;
F_11 ( V_29 ) ;
if ( V_30 ) {
F_8 ( & V_16 -> V_2 , L_12 ) ;
return V_30 ;
}
V_5 -> V_23 = F_22 ( & V_16 -> V_2 , V_5 -> V_20 ,
sizeof( struct V_6 ) ,
V_31 ) ;
if ( ! V_5 -> V_23 )
return - V_32 ;
F_23 ( & V_5 -> V_9 ) ;
F_24 ( V_16 , V_5 ) ;
V_5 -> V_35 . V_2 = & V_16 -> V_2 ;
V_5 -> V_35 . V_36 = F_1 ;
return F_25 ( V_22 , F_5 ,
& V_5 -> V_35 ) ;
}
static int T_1 F_26 ( void )
{
return F_27 ( & V_37 ) ;
}
