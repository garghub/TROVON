static T_1 T_2 F_1 ( void )
{
return F_2 ( V_1 ) ;
}
static T_3
F_3 ( int V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
F_4 ( F_2 ( V_6 ) & ~ V_7 , V_6 ) ;
F_4 ( V_8 , V_9 ) ;
V_5 -> V_10 ( V_5 ) ;
return V_11 ;
}
static int
F_5 ( unsigned long V_12 , struct V_4 * V_13 )
{
unsigned long V_14 , V_15 ;
F_4 ( F_2 ( V_6 ) | V_7 , V_6 ) ;
V_14 = F_2 ( V_1 ) + V_12 ;
F_4 ( V_14 , V_16 ) ;
V_15 = F_2 ( V_1 ) ;
return ( signed ) ( V_14 - V_15 ) <= V_17 ? - V_18 : 0 ;
}
static int F_6 ( struct V_4 * V_19 )
{
F_4 ( F_2 ( V_6 ) & ~ V_7 , V_6 ) ;
F_4 ( V_8 , V_9 ) ;
return 0 ;
}
static void F_7 ( struct V_4 * V_20 )
{
V_21 [ 0 ] = F_2 ( V_16 ) ;
V_21 [ 1 ] = F_2 ( V_22 ) ;
V_21 [ 2 ] = F_2 ( V_23 ) ;
V_21 [ 3 ] = F_2 ( V_24 ) ;
V_25 = F_2 ( V_6 ) ;
V_15 = F_2 ( V_1 ) ;
}
static void F_8 ( struct V_4 * V_20 )
{
if ( V_21 [ 0 ] - V_15 < V_17 )
V_21 [ 0 ] += V_17 ;
F_4 ( V_21 [ 0 ] , V_16 ) ;
F_4 ( V_21 [ 1 ] , V_22 ) ;
F_4 ( V_21 [ 2 ] , V_23 ) ;
F_4 ( V_21 [ 3 ] , V_24 ) ;
F_4 ( V_25 , V_6 ) ;
F_4 ( V_15 , V_1 ) ;
}
static void T_4 F_9 ( int V_2 , unsigned long V_26 )
{
F_4 ( 0 , V_6 ) ;
F_4 ( V_8 | V_27 | V_28 | V_29 , V_9 ) ;
F_10 ( F_1 , 32 , V_26 ) ;
V_30 . V_31 = F_11 ( 0 ) ;
F_12 ( V_2 , & V_32 ) ;
F_13 ( V_33 + V_1 , L_1 , V_26 , 200 ,
32 , V_34 ) ;
F_14 ( & V_30 , V_26 ,
V_17 * 2 , 0x7fffffff ) ;
}
static void T_4 F_15 ( struct V_35 * V_36 )
{
struct V_37 * V_37 ;
int V_2 ;
V_33 = F_16 ( V_36 , 0 ) ;
if ( ! V_33 )
F_17 ( L_2 , V_36 -> V_38 ) ;
V_37 = F_18 ( V_36 , 0 ) ;
if ( F_19 ( V_37 ) ) {
F_20 ( L_3 , V_36 -> V_38 ) ;
return;
}
F_21 ( V_37 ) ;
V_2 = F_22 ( V_36 , 0 ) ;
if ( V_2 <= 0 ) {
F_20 ( L_4 , V_36 -> V_38 ) ;
return;
}
F_9 ( V_2 , F_23 ( V_37 ) ) ;
}
void T_4 F_24 ( int V_2 , void T_5 * V_39 ,
unsigned long V_26 )
{
struct V_37 * V_37 ;
V_33 = V_39 ;
V_37 = F_25 ( NULL , L_5 ) ;
if ( V_37 && ! F_19 ( V_37 ) )
F_21 ( V_37 ) ;
else
F_20 ( L_3 , V_40 ) ;
F_9 ( V_2 , V_26 ) ;
}
