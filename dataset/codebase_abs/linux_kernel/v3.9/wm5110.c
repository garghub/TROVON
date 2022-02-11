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
int V_14 ;
V_2 -> V_15 = V_13 -> V_16 . V_17 -> V_18 ;
V_13 -> V_16 . V_17 -> V_19 = & V_2 -> V_19 ;
V_14 = F_5 ( V_2 , 32 , 16 , V_20 ) ;
if ( V_14 != 0 )
return V_14 ;
F_6 ( & V_2 -> V_19 , L_1 ) ;
V_13 -> V_16 . V_17 -> V_19 = & V_2 -> V_19 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_7 * V_13 = F_2 ( V_2 ) ;
V_13 -> V_16 . V_17 -> V_19 = NULL ;
return 0 ;
}
static int F_8 ( struct V_21 * V_22 )
{
struct V_17 * V_17 = F_9 ( V_22 -> V_23 . V_24 ) ;
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_10 ( & V_22 -> V_23 , sizeof( struct V_7 ) ,
V_26 ) ;
if ( V_8 == NULL )
return - V_27 ;
F_11 ( V_22 , V_8 ) ;
V_8 -> V_16 . V_17 = V_17 ;
for ( V_25 = 0 ; V_25 < F_12 ( V_8 -> V_10 ) ; V_25 ++ )
V_8 -> V_10 [ V_25 ] . V_28 = 3 ;
F_13 ( V_17 , 1 , V_29 - 1 ,
V_30 , V_31 ,
& V_8 -> V_10 [ 0 ] ) ;
F_13 ( V_17 , 2 , V_32 - 1 ,
V_33 , V_34 ,
& V_8 -> V_10 [ 1 ] ) ;
for ( V_25 = 0 ; V_25 < F_12 ( V_35 ) ; V_25 ++ )
F_14 ( & V_8 -> V_16 , V_25 ) ;
for ( V_25 = 0 ; V_25 < F_12 ( V_36 ) ; V_25 ++ )
F_15 ( V_17 -> V_18 , V_36 [ V_25 ] ,
V_37 , V_37 ) ;
F_16 ( & V_22 -> V_23 ) ;
F_17 ( & V_22 -> V_23 ) ;
return F_18 ( & V_22 -> V_23 , & V_38 ,
V_35 , F_12 ( V_35 ) ) ;
}
static int F_19 ( struct V_21 * V_22 )
{
F_20 ( & V_22 -> V_23 ) ;
F_21 ( & V_22 -> V_23 ) ;
return 0 ;
}
