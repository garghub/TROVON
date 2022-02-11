static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 -> V_9 ;
const struct V_10 * V_11 = & V_6 -> V_12 -> V_13 ;
int V_14 = V_2 -> V_15 . V_14 ;
if ( V_2 -> V_15 . V_16 != V_17 ||
V_2 -> V_15 . V_18 & V_19 )
V_14 = 0 ;
return V_11 -> V_20 ( V_14 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 . V_8 -> V_9 ;
const struct V_10 * V_11 = & V_6 -> V_12 -> V_13 ;
return V_11 -> V_21 () ;
}
void F_4 ( struct V_3 * V_4 , int V_22 )
{
if ( V_4 -> V_13 == NULL )
return;
V_4 -> V_13 -> V_15 . V_16 = V_22 == V_23
? V_17 : V_24 ;
F_5 ( V_4 -> V_13 ) ;
}
int F_6 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 . V_8 -> V_9 ;
const struct V_10 * V_11 = & V_6 -> V_12 -> V_13 ;
struct V_25 * V_7 = & V_4 -> V_7 ;
struct V_26 * V_8 = V_7 -> V_8 ;
struct V_1 * V_13 ;
if ( ! V_11 -> V_27 )
return 0 ;
V_13 = F_7 ( V_11 -> V_28 , V_8 -> V_8 , V_4 ,
& V_29 , NULL ) ;
if ( F_8 ( V_13 ) ) {
F_9 ( V_8 -> V_8 , L_1 ,
F_10 ( V_13 ) ) ;
return F_10 ( V_13 ) ;
}
V_13 -> V_15 . V_27 = V_11 -> V_27 ;
V_13 -> V_15 . V_14 = V_11 -> V_27 ;
V_13 -> V_15 . V_16 = V_24 ;
F_5 ( V_13 ) ;
V_4 -> V_13 = V_13 ;
return 0 ;
}
void F_11 ( struct V_3 * V_4 )
{
F_12 ( V_4 -> V_13 ) ;
}
