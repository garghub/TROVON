static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 ;
for ( V_7 = 0 ; V_7 < F_3 ( V_8 ) ; V_7 ++ ) {
if ( V_8 [ V_7 ] . time + 1 >= V_3 )
break;
}
if ( V_7 == F_3 ( V_8 ) )
return - V_9 ;
V_6 = F_4 ( V_5 -> V_10 -> V_11 , V_12 ,
V_13 ,
V_8 [ V_7 ] . V_14 ) ;
if ( ! V_6 )
V_2 -> V_15 = V_8 [ V_7 ] . time ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_1 ( V_2 , V_2 -> V_15 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_4 ( V_5 -> V_10 -> V_11 , V_16 ,
V_17 ,
V_17 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_4 ( V_5 -> V_10 -> V_11 , V_12 ,
V_18 ,
V_18 ) ;
if ( V_6 )
return V_6 ;
return F_4 ( V_5 -> V_10 -> V_11 , V_19 ,
V_20 ,
V_20 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_4 ( V_5 -> V_10 -> V_11 , V_12 ,
V_18 , 0 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_21 ;
int V_6 ;
V_6 = F_8 ( V_5 -> V_10 -> V_11 , V_12 , & V_21 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_9 ( V_5 -> V_10 -> V_11 , V_12 , V_21 ) ;
if ( V_6 )
return V_6 ;
return F_4 ( V_5 -> V_10 -> V_11 , V_22 ,
V_20 , 0 ) ;
}
static int F_10 ( struct V_23 * V_24 )
{
struct V_10 * V_10 = F_11 ( V_24 -> V_25 . V_26 ) ;
struct V_4 * V_5 ;
int V_27 , V_28 ;
V_5 = F_12 ( & V_24 -> V_25 , sizeof( struct V_4 ) , V_29 ) ;
if ( ! V_5 )
return - V_30 ;
V_27 = V_8 [ 0 ] . time ;
V_28 = V_8 [ F_3 ( V_8 ) - 1 ] . time ;
V_5 -> V_10 = V_10 ;
V_5 -> V_2 . V_31 = & V_32 ;
V_5 -> V_2 . V_33 = & V_34 ;
V_5 -> V_2 . V_27 = V_27 ;
V_5 -> V_2 . V_28 = V_28 ;
V_5 -> V_2 . V_15 = V_28 ;
V_5 -> V_2 . V_26 = & V_24 -> V_25 ;
F_13 ( & V_5 -> V_2 , V_5 ) ;
F_14 ( & V_5 -> V_2 , V_15 , & V_24 -> V_25 ) ;
F_15 ( & V_5 -> V_2 , V_35 ) ;
F_16 ( V_24 , V_5 ) ;
return F_17 ( & V_5 -> V_2 ) ;
}
static int F_18 ( struct V_23 * V_24 )
{
struct V_4 * V_5 = F_19 ( V_24 ) ;
F_20 ( & V_5 -> V_2 ) ;
return 0 ;
}
