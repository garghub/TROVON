static const T_1 * F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static unsigned int F_2 ( struct V_1 * V_2 )
{
return F_3 ( V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_5 ( V_2 ) ;
T_2 * V_6 = V_2 -> V_7 ;
T_3 * V_8 = V_5 -> V_9 . V_10 ;
unsigned int V_11 , V_12 ;
T_2 V_13 , V_14 , V_15 , V_16 ;
for ( V_11 = 0 ; V_11 < V_5 -> V_17 ; V_11 ++ ) {
for ( V_12 = 0 ; V_12 < V_5 -> V_18 ; V_12 ++ ) {
V_13 = ( * V_6 >> 30 ) & 3 ;
V_14 = ( * V_6 >> 22 ) & 3 ;
V_15 = ( * V_6 >> 14 ) & 3 ;
V_16 = ( * V_6 >> 6 ) & 3 ;
* V_8 = V_13 << 6 | V_14 << 4 | V_15 << 2 | V_16 ;
V_6 ++ ;
V_8 ++ ;
}
}
}
static int F_6 ( struct V_1 * V_2 , bool V_19 )
{
struct V_4 * V_5 = F_5 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_21 ;
T_2 V_22 , V_23 ;
T_2 V_24 ;
F_7 ( L_1 ) ;
F_8 ( V_2 -> V_25 , L_2 , V_26 , F_9 ( V_2 ) ) ;
if ( V_2 -> V_27 < V_28 ||
V_2 -> V_29 < V_28 ||
V_2 -> V_27 > V_30 ||
V_2 -> V_29 > V_30 ) {
F_10 ( L_3 ,
V_2 -> V_27 , V_2 -> V_29 ) ;
return - V_31 ;
}
if ( ! V_5 -> V_9 . V_10 ||
( V_5 -> V_18 != V_2 -> V_27 ) ||
( V_5 -> V_17 != V_2 -> V_29 ) ) {
V_5 -> V_18 = V_2 -> V_27 ;
V_5 -> V_17 = V_2 -> V_29 ;
if ( V_5 -> V_9 . V_10 )
F_11 ( V_2 -> V_25 ,
V_5 -> V_9 . V_32 ,
V_5 -> V_9 . V_10 ,
V_5 -> V_9 . V_33 ) ;
V_5 -> V_9 . V_32 = V_5 -> V_18 * V_5 -> V_17 ;
V_5 -> V_9 . V_10 = F_12 ( V_2 -> V_25 ,
V_5 -> V_9 . V_32 ,
& V_5 -> V_9 . V_33 ,
V_34 | V_35 ) ;
if ( ! V_5 -> V_9 . V_10 ) {
F_10 ( L_4 ) ;
return - V_36 ;
}
}
F_4 ( V_2 ) ;
V_22 = F_13 ( * V_21 , 0 ) ;
V_23 = F_14 ( * V_21 , 0 ) ;
V_24 = V_22 << 16 | V_23 ;
F_15 ( V_24 , V_2 -> V_37 + V_38 ) ;
V_22 = F_13 ( * V_21 , V_21 -> V_39 - 1 ) ;
V_23 = F_14 ( * V_21 , V_21 -> V_40 - 1 ) ;
V_24 = V_22 << 16 | V_23 ;
F_15 ( V_24 , V_2 -> V_37 + V_41 ) ;
if ( V_19 ) {
F_15 ( V_5 -> V_42 , V_2 -> V_37 + V_43 ) ;
F_15 ( V_44 , V_2 -> V_37 + V_45 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_5 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_21 ;
T_2 V_46 , V_47 ;
F_8 ( V_2 -> V_25 , L_2 , V_26 , F_9 ( V_2 ) ) ;
F_15 ( V_5 -> V_9 . V_33 , V_2 -> V_37 + V_48 ) ;
F_15 ( V_5 -> V_18 , V_2 -> V_37 + V_49 ) ;
F_15 ( V_5 -> V_17 << 16 | V_5 -> V_18 , V_2 -> V_37 + V_50 ) ;
V_46 = F_13 ( * V_21 , V_2 -> V_51 ) ;
V_47 = F_14 ( * V_21 , V_2 -> V_51 ) ;
F_15 ( ( V_46 << 16 ) | V_47 , V_2 -> V_37 + V_52 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_5 ( V_2 ) ;
unsigned short * V_10 = V_5 -> V_53 ;
unsigned int V_13 , V_14 , V_15 , V_16 ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ )
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ )
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ )
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ )
* V_10 ++ = ( V_13 * 5 ) << 12 |
( V_14 * 5 ) << 8 |
( V_15 * 5 ) << 4 |
( V_16 * 5 ) ;
}
struct V_1 * F_19 ( struct V_54 * V_25 )
{
struct V_4 * V_5 ;
V_5 = F_20 ( V_25 , sizeof( * V_5 ) , V_34 ) ;
if ( ! V_5 ) {
F_10 ( L_5 ) ;
return NULL ;
}
V_5 -> V_53 = F_12 ( V_25 ,
0x100 * sizeof( unsigned short ) ,
& V_5 -> V_42 ,
V_34 | V_35 ) ;
if ( ! V_5 -> V_53 ) {
F_10 ( L_6 ) ;
F_21 ( V_25 , V_5 ) ;
return NULL ;
}
V_5 -> V_2 . V_55 = & V_56 ;
return (struct V_1 * ) V_5 ;
}
