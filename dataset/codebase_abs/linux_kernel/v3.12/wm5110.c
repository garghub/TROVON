static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
switch ( V_3 ) {
case V_9 :
return F_3 ( & V_8 -> V_10 [ 0 ] , V_4 , V_5 , V_6 ) ;
case V_11 :
return F_3 ( & V_8 -> V_10 [ 1 ] , V_4 , V_5 , V_6 ) ;
case V_12 :
return F_4 ( & V_8 -> V_10 [ 0 ] , V_4 , V_5 ,
V_6 ) ;
case V_13 :
return F_4 ( & V_8 -> V_10 [ 1 ] , V_4 , V_5 ,
V_6 ) ;
default:
return - V_14 ;
}
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_7 * V_15 = F_2 ( V_2 ) ;
int V_16 ;
V_2 -> V_17 = V_15 -> V_18 . V_19 -> V_20 ;
V_15 -> V_18 . V_19 -> V_21 = & V_2 -> V_21 ;
V_16 = F_6 ( V_2 , 32 , 16 , V_22 ) ;
if ( V_16 != 0 )
return V_16 ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( & V_2 -> V_21 , L_1 ) ;
V_15 -> V_18 . V_19 -> V_21 = & V_2 -> V_21 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_7 * V_15 = F_2 ( V_2 ) ;
V_15 -> V_18 . V_19 -> V_21 = NULL ;
return 0 ;
}
static int F_11 ( struct V_23 * V_24 )
{
struct V_19 * V_19 = F_12 ( V_24 -> V_25 . V_26 ) ;
struct V_7 * V_8 ;
int V_27 ;
V_8 = F_13 ( & V_24 -> V_25 , sizeof( struct V_7 ) ,
V_28 ) ;
if ( V_8 == NULL )
return - V_29 ;
F_14 ( V_24 , V_8 ) ;
V_8 -> V_18 . V_19 = V_19 ;
V_8 -> V_18 . V_30 = 8 ;
for ( V_27 = 0 ; V_27 < F_15 ( V_8 -> V_10 ) ; V_27 ++ )
V_8 -> V_10 [ V_27 ] . V_31 = 3 ;
F_16 ( V_19 , 1 , V_32 - 1 ,
V_33 , V_34 ,
& V_8 -> V_10 [ 0 ] ) ;
F_16 ( V_19 , 2 , V_35 - 1 ,
V_36 , V_37 ,
& V_8 -> V_10 [ 1 ] ) ;
for ( V_27 = 0 ; V_27 < F_15 ( V_38 ) ; V_27 ++ )
F_17 ( & V_8 -> V_18 , V_27 ) ;
for ( V_27 = 0 ; V_27 < F_15 ( V_39 ) ; V_27 ++ )
F_18 ( V_19 -> V_20 , V_39 [ V_27 ] ,
V_40 , V_40 ) ;
F_19 ( & V_24 -> V_25 ) ;
F_20 ( & V_24 -> V_25 ) ;
return F_21 ( & V_24 -> V_25 , & V_41 ,
V_38 , F_15 ( V_38 ) ) ;
}
static int F_22 ( struct V_23 * V_24 )
{
F_23 ( & V_24 -> V_25 ) ;
F_24 ( & V_24 -> V_25 ) ;
return 0 ;
}
