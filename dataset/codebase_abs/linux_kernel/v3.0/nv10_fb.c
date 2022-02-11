static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_8 * V_9 = & V_6 -> V_10 . V_11 ;
struct V_1 * V_12 ;
int V_13 ;
V_13 = F_2 ( & V_9 -> V_14 ) ;
if ( V_13 )
return NULL ;
F_3 ( & V_6 -> V_15 . V_16 ) ;
V_12 = F_4 ( & V_9 -> V_14 , V_4 , 0 , 0 ) ;
if ( V_12 )
V_12 = F_5 ( V_12 , V_4 , 0 ) ;
F_6 ( & V_6 -> V_15 . V_16 ) ;
return V_12 ;
}
static void
F_7 ( struct V_2 * V_3 , struct V_1 * V_12 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
F_3 ( & V_6 -> V_15 . V_16 ) ;
F_8 ( V_12 ) ;
F_6 ( & V_6 -> V_15 . V_16 ) ;
}
void
F_9 ( struct V_2 * V_3 , int V_17 , T_1 V_18 ,
T_1 V_4 , T_1 V_19 , T_1 V_20 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_21 * V_15 = & V_6 -> V_15 . V_22 [ V_17 ] ;
int V_23 = ( V_20 & V_24 ? 32 : 16 ) ;
V_15 -> V_18 = V_18 ;
V_15 -> V_25 = F_10 ( 1u , V_18 + V_4 ) - 1 ;
V_15 -> V_19 = V_19 ;
if ( V_6 -> V_26 == V_27 ) {
if ( V_20 & V_28 ) {
V_15 -> V_29 = F_1 ( V_3 , V_4 / 256 ) ;
if ( V_15 -> V_29 ) {
if ( V_6 -> V_30 >= 0x25 )
V_15 -> V_31 = V_15 -> V_29 -> V_32 |
( V_23 == 16 ?
V_33 :
V_34 ) ;
else
V_15 -> V_31 = V_15 -> V_29 -> V_32 |
V_35 |
( V_23 == 16 ? 0 :
V_36 ) ;
}
V_15 -> V_18 |= 3 ;
} else {
V_15 -> V_18 |= 1 ;
}
} else {
V_15 -> V_18 |= 1 << 31 ;
}
}
void
F_11 ( struct V_2 * V_3 , int V_17 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_21 * V_15 = & V_6 -> V_15 . V_22 [ V_17 ] ;
if ( V_15 -> V_29 ) {
F_7 ( V_3 , V_15 -> V_29 ) ;
V_15 -> V_29 = NULL ;
}
V_15 -> V_18 = V_15 -> V_25 = V_15 -> V_19 = V_15 -> V_31 = 0 ;
}
void
F_12 ( struct V_2 * V_3 , int V_17 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_21 * V_15 = & V_6 -> V_15 . V_22 [ V_17 ] ;
F_13 ( V_3 , F_14 ( V_17 ) , V_15 -> V_25 ) ;
F_13 ( V_3 , F_15 ( V_17 ) , V_15 -> V_19 ) ;
F_13 ( V_3 , F_16 ( V_17 ) , V_15 -> V_18 ) ;
if ( V_6 -> V_26 == V_27 )
F_13 ( V_3 , F_17 ( V_17 ) , V_15 -> V_31 ) ;
}
int
F_18 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_8 * V_9 = & V_6 -> V_10 . V_11 ;
int V_17 ;
V_9 -> V_37 = V_38 ;
if ( V_6 -> V_26 == V_27 )
F_19 ( & V_9 -> V_14 , 0 ,
( V_6 -> V_30 >= 0x25 ?
64 * 1024 : 32 * 1024 ) ) ;
for ( V_17 = 0 ; V_17 < V_9 -> V_37 ; V_17 ++ )
V_9 -> V_39 ( V_3 , V_17 ) ;
return 0 ;
}
void
F_20 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_8 * V_9 = & V_6 -> V_10 . V_11 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_9 -> V_37 ; V_17 ++ )
V_9 -> V_40 ( V_3 , V_17 ) ;
if ( V_6 -> V_26 == V_27 )
F_21 ( & V_9 -> V_14 ) ;
}
