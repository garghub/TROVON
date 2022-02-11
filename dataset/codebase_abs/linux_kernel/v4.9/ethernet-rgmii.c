static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
union V_4 V_5 ;
union V_6 V_7 ;
union V_8 V_9 ;
int V_10 = F_2 ( V_2 -> V_11 ) ;
int V_12 = F_3 ( V_2 -> V_11 ) ;
V_5 . V_13 = F_4 ( F_5 ( V_12 ,
V_10 ) ) ;
V_5 . V_14 . V_15 = V_3 ;
F_6 ( F_5 ( V_12 , V_10 ) ,
V_5 . V_13 ) ;
V_7 . V_13 = F_4 ( V_16 ) ;
if ( V_3 )
V_7 . V_14 . V_17 |= 1ull << V_2 -> V_11 ;
else
V_7 . V_14 . V_17 &=
0xffffffffull ^ ( 1ull << V_2 -> V_11 ) ;
F_6 ( V_16 , V_7 . V_13 ) ;
V_9 . V_13 = F_4 ( F_7 ( V_12 ,
V_10 ) ) ;
F_6 ( F_7 ( V_12 , V_10 ) ,
V_9 . V_13 ) ;
}
static void F_8 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
T_1 V_20 ;
unsigned long V_21 ;
V_20 . V_13 = V_2 -> V_20 ;
F_10 ( & V_22 , V_21 ) ;
if ( V_20 . V_14 . V_23 == 10 && V_2 -> V_24 == 10 ) {
int V_10 = F_2 ( V_2 -> V_11 ) ;
int V_12 = F_3 ( V_2 -> V_11 ) ;
union V_8 V_9 ;
V_9 . V_13 = F_4 ( F_7
( V_12 , V_10 ) ) ;
if ( V_9 . V_14 . V_25 ) {
F_1 ( V_2 , false ) ;
F_11 ( L_1 ,
V_19 -> V_26 ) ;
}
} else {
if ( V_2 -> V_24 != V_20 . V_14 . V_23 )
F_1 ( V_2 , true ) ;
V_2 -> V_24 = V_20 . V_14 . V_23 ;
}
F_12 ( & V_22 , V_21 ) ;
}
static void F_13 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
T_1 V_20 ;
bool V_27 ;
V_20 = F_14 ( V_2 -> V_11 ) ;
if ( V_2 -> V_20 != V_20 . V_13 &&
F_15 ( V_2 -> V_11 , V_20 ) )
V_20 . V_13 = V_2 -> V_20 ;
V_27 = V_2 -> V_20 != V_20 . V_13 ;
V_2 -> V_20 = V_20 . V_13 ;
F_8 ( V_19 ) ;
if ( F_16 ( ! V_27 ) )
return;
if ( V_20 . V_14 . V_28 ) {
if ( ! F_17 ( V_19 ) )
F_18 ( V_19 ) ;
} else if ( F_17 ( V_19 ) ) {
F_19 ( V_19 ) ;
}
F_20 ( V_2 , V_20 ) ;
}
int F_21 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_19 ) ;
int V_29 ;
V_29 = F_22 ( V_19 , F_13 ) ;
if ( V_29 )
return V_29 ;
if ( V_19 -> V_30 ) {
if ( ( V_2 -> V_31 == V_32 &&
V_2 -> V_11 == 0 ) ||
( V_2 -> V_31 == V_33 ) ) {
V_2 -> V_34 = F_8 ;
F_8 ( V_19 ) ;
}
}
return 0 ;
}
