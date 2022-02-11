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
V_5 -> V_13 [ 0 ] = V_14 ;
V_5 -> V_13 [ 1 ] = 0 ;
V_11 = F_8 ( V_2 , V_5 -> V_13 + 3 ,
V_15 - 3 ) ;
if ( V_11 <= 0 )
return;
V_5 -> V_13 [ 2 ] = V_11 ;
V_5 -> V_10 . V_16 = V_11 + 3 ;
V_12 = F_9 ( & V_5 -> V_10 , V_17 ) ;
if ( V_12 < 0 )
log ( L_1
L_2 ,
V_2 , V_12 , V_11 ) ;
else
V_5 -> V_9 = 1 ;
}
static void F_10 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( V_3 ) {
V_5 -> V_18 = V_2 ;
if ( ! V_5 -> V_9 )
F_7 ( V_5 , V_2 ) ;
} else {
V_5 -> V_18 = NULL ;
}
}
void F_11 ( struct V_4 * V_5 ,
int V_19 , const char * V_20 , int V_11 )
{
if ( ! V_5 -> V_8 )
return;
F_12 ( V_5 -> V_8 , V_20 , V_11 ) ;
}
int F_13 ( struct V_4 * V_21 )
{
int V_12 ;
struct V_22 * V_6 ;
V_12 = F_14 ( V_21 -> V_23 . V_24 , V_21 -> V_25 , 0 ,
V_21 -> V_26 . V_27 ,
V_21 -> V_26 . V_28 ,
& V_6 ) ;
if ( V_12 < 0 )
return V_12 ;
F_15 ( V_6 -> V_29 , V_21 -> V_25 , sizeof( V_6 -> V_29 ) ) ;
V_6 -> V_30 = V_31 ;
V_6 -> V_7 = V_21 ;
if ( V_21 -> V_26 . V_27 > 0 ) {
V_6 -> V_30 |= V_32 ;
F_16 ( V_6 , V_33 ,
& V_34 ) ;
}
if ( V_21 -> V_26 . V_28 > 0 ) {
V_6 -> V_30 |= V_35 ;
F_16 ( V_6 , V_36 ,
& V_37 ) ;
}
V_21 -> V_6 = V_6 ;
return 0 ;
}
void F_17 ( struct V_38 * V_38 )
{
struct V_4 * V_5 = V_38 -> V_39 ;
V_5 -> V_9 = 0 ;
if ( V_38 -> V_40 != 0 )
return;
if ( ! V_5 -> V_18 )
return;
F_7 ( V_5 , V_5 -> V_18 ) ;
}
