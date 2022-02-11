static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( ! V_5 )
return;
V_5 -> V_8 = V_3 ? V_2 : NULL ;
}
static int F_4 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( V_5 -> V_9 ) {
F_6 ( & V_5 -> V_10 ) ;
V_5 -> V_9 = 0 ;
}
return 0 ;
}
static void F_7 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
int V_11 , V_12 ;
struct V_13 * V_14 = F_8 ( V_5 ) ;
V_5 -> V_15 [ 0 ] = V_16 ;
V_5 -> V_15 [ 1 ] = 0 ;
V_11 = F_9 ( V_2 , V_5 -> V_15 + 3 ,
V_17 - 3 ) ;
if ( V_11 <= 0 )
return;
V_5 -> V_15 [ 2 ] = V_11 ;
V_5 -> V_10 . V_18 = V_11 + 3 ;
V_12 = F_10 ( & V_5 -> V_10 , V_19 ) ;
if ( V_12 < 0 )
F_11 ( V_14 ,
L_1
L_2 , V_2 , V_12 , V_11 ) ;
else
V_5 -> V_9 = 1 ;
}
static void F_12 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( V_3 ) {
V_5 -> V_20 = V_2 ;
if ( ! V_5 -> V_9 )
F_7 ( V_5 , V_2 ) ;
} else {
V_5 -> V_20 = NULL ;
}
}
void F_13 ( struct V_4 * V_5 ,
int V_21 , const char * V_22 , int V_11 )
{
if ( ! V_5 -> V_8 )
return;
F_14 ( V_5 -> V_8 , V_22 , V_11 ) ;
}
int F_15 ( struct V_4 * V_13 )
{
int V_12 ;
struct V_23 * V_6 ;
V_12 = F_16 ( V_13 -> V_24 . V_25 , V_13 -> V_26 , 0 ,
V_13 -> V_27 . V_28 ,
V_13 -> V_27 . V_29 ,
& V_6 ) ;
if ( V_12 < 0 )
return V_12 ;
F_17 ( V_6 -> V_30 , V_13 -> V_26 , sizeof( V_6 -> V_30 ) ) ;
V_6 -> V_31 = V_32 ;
V_6 -> V_7 = V_13 ;
if ( V_13 -> V_27 . V_28 > 0 ) {
V_6 -> V_31 |= V_33 ;
F_18 ( V_6 , V_34 ,
& V_35 ) ;
}
if ( V_13 -> V_27 . V_29 > 0 ) {
V_6 -> V_31 |= V_36 ;
F_18 ( V_6 , V_37 ,
& V_38 ) ;
}
V_13 -> V_6 = V_6 ;
return 0 ;
}
void F_19 ( struct V_39 * V_39 )
{
struct V_4 * V_5 = V_39 -> V_40 ;
V_5 -> V_9 = 0 ;
if ( V_39 -> V_41 != 0 )
return;
if ( ! V_5 -> V_20 )
return;
F_7 ( V_5 , V_5 -> V_20 ) ;
}
