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
if ( V_10 )
F_3 ( V_2 , true ) ;
else
F_3 ( V_2 , false ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , bool V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) ( V_2 -> V_5 ) ;
struct V_11 V_12 ;
const struct V_13 * V_14 ;
struct V_13 * V_15 ;
if ( V_4 -> V_7 == V_10 )
return 0 ;
V_4 -> V_7 = V_10 ;
V_14 = V_2 -> V_16 ;
V_15 = V_2 -> V_17 ;
V_12 . V_18 = & ( V_14 -> V_19 ) ;
V_12 . V_20 = & ( V_15 -> V_19 ) ;
F_5 ( V_2 , & V_12 ) ;
F_6 ( V_2 , ! V_10 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , bool V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) ( V_2 -> V_5 ) ;
if ( V_4 -> V_8 == V_10 )
return 0 ;
V_4 -> V_8 = V_10 ;
if ( V_10 )
F_8 ( V_2 , true ) ;
else
F_8 ( V_2 , false ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , bool V_10 )
{
struct V_3 * V_4 = (struct V_3 * ) ( V_2 -> V_5 ) ;
if ( V_4 -> V_9 == V_10 )
return 0 ;
V_4 -> V_9 = V_10 ;
if ( V_10 )
F_10 ( V_2 , true ) ;
else
F_10 ( V_2 , false ) ;
return 0 ;
}
