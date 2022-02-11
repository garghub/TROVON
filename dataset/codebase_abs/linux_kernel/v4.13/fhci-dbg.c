void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
if ( V_3 == - 1 ) {
V_2 -> V_5 [ 12 ] ++ ;
return;
}
for ( V_4 = 0 ; V_4 < 12 ; ++ V_4 ) {
if ( V_3 & ( 1 << V_4 ) )
V_2 -> V_5 [ V_4 ] ++ ;
}
}
static int F_2 ( struct V_6 * V_7 , void * V_8 )
{
struct V_1 * V_2 = V_7 -> V_9 ;
struct V_10 T_1 * V_11 = V_2 -> V_11 ;
F_3 ( V_7 ,
L_1 L_2
L_3 L_4
L_5 L_6
L_7 L_8
L_9
L_10 ,
F_4 ( & V_11 -> V_12 ) , F_4 ( & V_11 -> V_13 ) ,
F_4 ( & V_11 -> V_14 ) , F_5 ( & V_11 -> V_15 [ 0 ] ) ,
F_5 ( & V_11 -> V_16 ) , F_5 ( & V_11 -> V_17 ) ,
F_4 ( & V_11 -> V_18 ) , F_5 ( & V_11 -> V_19 ) ,
F_5 ( & V_11 -> V_20 ) ,
F_6 ( V_2 ) ) ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 , void * V_8 )
{
struct V_1 * V_2 = V_7 -> V_9 ;
int * V_5 = V_2 -> V_5 ;
F_3 ( V_7 ,
L_11 L_12 L_13
L_14 L_15 L_16
L_17 L_18 L_19
L_20 L_21 L_22
L_23 ,
V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] ,
V_5 [ 3 ] , V_5 [ 4 ] , V_5 [ 5 ] ,
V_5 [ 6 ] , V_5 [ 7 ] , V_5 [ 8 ] ,
V_5 [ 9 ] , V_5 [ 10 ] , V_5 [ 11 ] ,
V_5 [ 12 ] ) ;
return 0 ;
}
static int F_8 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_9 ( V_22 , F_2 , V_21 -> V_23 ) ;
}
static int F_10 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_9 ( V_22 , F_7 , V_21 -> V_23 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_12 ( V_2 ) -> V_26 . V_27 ;
V_2 -> V_28 = F_13 ( F_14 ( V_25 ) , V_29 ) ;
if ( ! V_2 -> V_28 ) {
F_15 ( 1 ) ;
return;
}
V_2 -> V_30 = F_16 ( L_24 , V_31 | V_32 ,
V_2 -> V_28 , V_2 , & V_33 ) ;
V_2 -> V_34 = F_16 ( L_25 ,
V_31 | V_32 , V_2 -> V_28 , V_2 ,
& V_35 ) ;
F_15 ( ! V_2 -> V_30 || ! V_2 -> V_34 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_28 )
return;
F_18 ( V_2 -> V_34 ) ;
F_18 ( V_2 -> V_30 ) ;
F_18 ( V_2 -> V_28 ) ;
}
