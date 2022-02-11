static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
switch ( V_3 ) {
case V_9 :
return F_3 ( & V_8 -> V_10 [ 0 ] , V_4 , V_5 , V_6 ) ;
case V_11 :
return F_3 ( & V_8 -> V_10 [ 1 ] , V_4 , V_5 , V_6 ) ;
default:
return - V_12 ;
}
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_13 = F_2 ( V_2 ) ;
V_2 -> V_14 = V_13 -> V_15 . V_16 -> V_17 ;
return F_5 ( V_2 , 32 , 16 , V_18 ) ;
}
static int T_1 F_6 ( struct V_19 * V_20 )
{
struct V_16 * V_16 = F_7 ( V_20 -> V_21 . V_22 ) ;
struct V_7 * V_8 ;
int V_23 ;
V_8 = F_8 ( & V_20 -> V_21 , sizeof( struct V_7 ) ,
V_24 ) ;
if ( V_8 == NULL )
return - V_25 ;
F_9 ( V_20 , V_8 ) ;
V_8 -> V_15 . V_16 = V_16 ;
for ( V_23 = 0 ; V_23 < F_10 ( V_8 -> V_10 ) ; V_23 ++ )
V_8 -> V_10 [ V_23 ] . V_26 = 3 ;
F_11 ( V_16 , 1 , V_27 - 1 ,
V_28 , V_29 ,
& V_8 -> V_10 [ 0 ] ) ;
F_11 ( V_16 , 2 , V_30 - 1 ,
V_31 , V_32 ,
& V_8 -> V_10 [ 1 ] ) ;
for ( V_23 = 0 ; V_23 < F_10 ( V_33 ) ; V_23 ++ )
F_12 ( & V_8 -> V_15 , V_23 ) ;
for ( V_23 = 0 ; V_23 < F_10 ( V_34 ) ; V_23 ++ )
F_13 ( V_16 -> V_17 , V_34 [ V_23 ] ,
V_35 , V_35 ) ;
F_14 ( & V_20 -> V_21 ) ;
F_15 ( & V_20 -> V_21 ) ;
return F_16 ( & V_20 -> V_21 , & V_36 ,
V_33 , F_10 ( V_33 ) ) ;
}
static int T_2 F_17 ( struct V_19 * V_20 )
{
F_18 ( & V_20 -> V_21 ) ;
F_19 ( & V_20 -> V_21 ) ;
return 0 ;
}
