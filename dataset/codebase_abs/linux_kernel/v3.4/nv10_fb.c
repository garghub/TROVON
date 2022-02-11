void
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 ,
T_1 V_5 , T_1 V_6 , T_1 V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = & V_9 -> V_12 . V_13 [ V_3 ] ;
V_12 -> V_4 = 0x80000000 | V_4 ;
V_12 -> V_14 = F_2 ( 1u , V_4 + V_5 ) - 1 ;
V_12 -> V_6 = V_6 ;
}
void
F_3 ( struct V_1 * V_2 , int V_3 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = & V_9 -> V_12 . V_13 [ V_3 ] ;
V_12 -> V_4 = V_12 -> V_14 = V_12 -> V_6 = V_12 -> V_15 = 0 ;
}
void
F_4 ( struct V_1 * V_2 , int V_3 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = & V_9 -> V_12 . V_13 [ V_3 ] ;
F_5 ( V_2 , F_6 ( V_3 ) , V_12 -> V_14 ) ;
F_5 ( V_2 , F_7 ( V_3 ) , V_12 -> V_6 ) ;
F_5 ( V_2 , F_8 ( V_3 ) , V_12 -> V_4 ) ;
}
int
F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_16 * V_17 ;
T_1 V_18 , V_19 ;
V_17 = F_10 ( 0 , F_11 ( 0 , 1 ) ) ;
if ( ! V_17 ) {
F_12 ( V_2 , L_1 ) ;
return 0 ;
}
if ( V_9 -> V_20 == 0x1a ) {
F_13 ( V_17 , 0x7c , & V_18 ) ;
V_19 = ( ( V_18 >> 6 ) & 31 ) + 1 ;
} else {
F_13 ( V_17 , 0x84 , & V_18 ) ;
V_19 = ( ( V_18 >> 4 ) & 127 ) + 1 ;
}
V_9 -> V_21 = V_19 * 1024 * 1024 ;
return 0 ;
}
int
F_14 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
T_2 V_22 = F_15 ( V_2 , V_23 ) ;
T_2 V_24 = F_15 ( V_2 , 0x100200 ) ;
V_9 -> V_21 = V_22 & V_25 ;
if ( V_24 & 0x00000001 )
V_9 -> V_26 = V_27 ;
else
V_9 -> V_26 = V_28 ;
return 0 ;
}
int
F_16 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_29 * V_30 = & V_9 -> V_31 . V_32 ;
int V_3 ;
V_30 -> V_33 = V_34 ;
for ( V_3 = 0 ; V_3 < V_30 -> V_33 ; V_3 ++ )
V_30 -> V_35 ( V_2 , V_3 ) ;
return 0 ;
}
void
F_17 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_29 * V_30 = & V_9 -> V_31 . V_32 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_30 -> V_33 ; V_3 ++ )
V_30 -> V_36 ( V_2 , V_3 ) ;
}
