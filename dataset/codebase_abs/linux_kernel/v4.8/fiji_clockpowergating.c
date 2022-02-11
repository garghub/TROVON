int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) ( V_2 -> V_5 ) ;
V_4 -> V_6 = false ;
V_4 -> V_7 = false ;
V_4 -> V_8 = false ;
V_4 -> V_9 = false ;
return 0 ;
}
int F_2 ( struct V_1 * V_2 , bool V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) ( V_2 -> V_5 ) ;
if ( V_4 -> V_6 == V_10 )
return 0 ;
V_4 -> V_6 = V_10 ;
if ( V_10 ) {
F_3 ( V_2 -> V_11 ,
V_12 ,
V_13 ) ;
F_4 ( V_2 , true ) ;
} else {
F_4 ( V_2 , false ) ;
F_3 ( V_2 -> V_11 ,
V_12 ,
V_14 ) ;
}
return 0 ;
}
int F_5 ( struct V_1 * V_2 , bool V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) ( V_2 -> V_5 ) ;
struct V_15 V_16 ;
const struct V_17 * V_18 ;
struct V_17 * V_19 ;
if ( V_4 -> V_7 == V_10 )
return 0 ;
V_4 -> V_7 = V_10 ;
V_18 = V_2 -> V_20 ;
V_19 = V_2 -> V_21 ;
V_16 . V_22 = & ( V_18 -> V_23 ) ;
V_16 . V_24 = & ( V_19 -> V_23 ) ;
F_6 ( V_2 , & V_16 ) ;
F_7 ( V_2 , ! V_10 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , bool V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) ( V_2 -> V_5 ) ;
if ( V_4 -> V_8 == V_10 )
return 0 ;
V_4 -> V_8 = V_10 ;
if ( V_10 )
F_9 ( V_2 , true ) ;
else
F_9 ( V_2 , false ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , bool V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) ( V_2 -> V_5 ) ;
if ( V_4 -> V_9 == V_10 )
return 0 ;
V_4 -> V_9 = V_10 ;
if ( V_10 )
F_11 ( V_2 , true ) ;
else
F_11 ( V_2 , false ) ;
return 0 ;
}
