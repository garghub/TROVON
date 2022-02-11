static int F_1 ( unsigned int V_1 )
{
struct V_2 * V_3 = & V_4 ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
int V_7 = 0 , V_8 = 0 ;
if ( V_3 -> V_9 . V_10 )
V_7 += 1 ;
else
return - V_11 ;
V_8 += ( V_3 -> V_12 . V_10 ) ? 2 : 1 ;
if ( V_3 -> V_13 . V_10 ) {
V_7 ++ ;
V_8 ++ ;
}
if ( V_3 -> V_14 . V_10 ) {
V_7 ++ ;
V_8 ++ ;
}
V_6 -> V_15 = V_7 ;
V_6 -> V_16 = V_8 ;
return 0 ;
}
static int F_3 ( unsigned int V_1 )
{
struct V_2 * V_3 = & V_4 ;
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_17 * V_18 = V_6 -> V_19 ;
if ( V_3 -> V_12 . V_10 ) {
F_4 ( V_9 , V_18 , 1 , V_20 ) ;
F_4 ( V_12 , V_18 , 1 , V_21 ) ;
} else {
F_4 ( V_9 , V_18 , 1 , V_22 ) ;
}
if ( V_3 -> V_13 . V_10 )
F_4 ( V_13 , V_18 , 2 , V_22 ) ;
if ( V_3 -> V_14 . V_10 )
F_4 ( V_14 , V_18 , 3 , V_22 ) ;
return 0 ;
}
