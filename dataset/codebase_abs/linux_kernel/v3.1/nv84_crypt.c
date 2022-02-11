static int
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_9 * V_11 ;
int V_12 ;
F_2 ( V_5 , L_1 , V_2 -> V_13 ) ;
V_12 = F_3 ( V_5 , V_2 , 256 , 0 , V_14 |
V_15 , & V_11 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_10 , 0xa0 , 0x00190000 ) ;
F_4 ( V_10 , 0xa4 , V_11 -> V_16 + V_11 -> V_17 - 1 ) ;
F_4 ( V_10 , 0xa8 , V_11 -> V_16 ) ;
F_4 ( V_10 , 0xac , 0 ) ;
F_4 ( V_10 , 0xb0 , 0 ) ;
F_4 ( V_10 , 0xb4 , 0 ) ;
V_7 -> V_3 . V_18 . V_19 ( V_5 ) ;
F_5 ( & V_2 -> V_20 -> V_21 [ V_3 ] ) ;
V_2 -> V_22 [ V_3 ] = V_11 ;
return 0 ;
}
static void
F_6 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_11 = V_2 -> V_22 [ V_3 ] ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_23 ;
V_23 = ( V_2 -> V_10 -> V_16 >> 12 ) ;
V_23 |= 0x80000000 ;
F_7 ( V_5 , 0x10200c , 0x00000000 ) ;
if ( F_8 ( V_5 , 0x102188 ) == V_23 )
F_9 ( V_5 , 0x102188 , 0x80000000 , 0x00000000 ) ;
if ( F_8 ( V_5 , 0x10218c ) == V_23 )
F_9 ( V_5 , 0x10218c , 0x80000000 , 0x00000000 ) ;
F_7 ( V_5 , 0x10200c , 0x00000010 ) ;
F_10 ( NULL , & V_11 ) ;
F_11 ( & V_2 -> V_20 -> V_21 [ V_3 ] ) ;
V_2 -> V_22 [ V_3 ] = NULL ;
}
static int
F_12 ( struct V_1 * V_2 , int V_3 ,
T_1 V_24 , T_2 V_25 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_26 = NULL ;
int V_12 ;
V_12 = F_3 ( V_5 , V_2 , 16 , 16 , V_15 , & V_26 ) ;
if ( V_12 )
return V_12 ;
V_26 -> V_3 = 5 ;
V_26 -> V_25 = V_25 ;
F_4 ( V_26 , 0x00 , V_25 ) ;
V_7 -> V_3 . V_18 . V_19 ( V_5 ) ;
V_12 = F_13 ( V_2 , V_24 , V_26 ) ;
F_10 ( NULL , & V_26 ) ;
return V_12 ;
}
static void
F_14 ( struct V_4 * V_5 , int V_3 )
{
F_15 ( V_5 , 0x0a ) ;
}
static void
F_16 ( struct V_4 * V_5 )
{
T_1 V_27 = F_8 ( V_5 , 0x102130 ) ;
T_1 V_28 = F_8 ( V_5 , 0x102190 ) ;
T_1 V_29 = F_8 ( V_5 , 0x102194 ) ;
T_1 V_23 = F_8 ( V_5 , 0x102188 ) & 0x7fffffff ;
int V_30 = F_17 () ;
if ( V_30 ) {
F_18 ( V_5 , L_2 ,
V_27 , V_28 , V_29 , V_23 ) ;
}
F_7 ( V_5 , 0x102130 , V_27 ) ;
F_7 ( V_5 , 0x10200c , 0x10 ) ;
F_19 ( V_5 , V_30 ) ;
}
static int
F_20 ( struct V_4 * V_5 , int V_3 , bool V_31 )
{
F_7 ( V_5 , 0x102140 , 0x00000000 ) ;
return 0 ;
}
static int
F_21 ( struct V_4 * V_5 , int V_3 )
{
F_9 ( V_5 , 0x000200 , 0x00004000 , 0x00000000 ) ;
F_9 ( V_5 , 0x000200 , 0x00004000 , 0x00004000 ) ;
F_7 ( V_5 , 0x102130 , 0xffffffff ) ;
F_7 ( V_5 , 0x102140 , 0xffffffbf ) ;
F_7 ( V_5 , 0x10200c , 0x00000010 ) ;
return 0 ;
}
static void
F_22 ( struct V_4 * V_5 , int V_3 )
{
struct V_32 * V_33 = F_23 ( V_5 , V_3 ) ;
F_24 ( V_5 , V_34 ) ;
F_25 ( V_5 , 14 ) ;
F_26 ( V_33 ) ;
}
int
F_27 ( struct V_4 * V_5 )
{
struct V_32 * V_33 ;
V_33 = F_28 ( sizeof( * V_33 ) , V_35 ) ;
if ( ! V_33 )
return - V_36 ;
V_33 -> V_37 . V_38 = F_22 ;
V_33 -> V_37 . V_39 = F_21 ;
V_33 -> V_37 . V_40 = F_20 ;
V_33 -> V_37 . V_41 = F_1 ;
V_33 -> V_37 . V_42 = F_6 ;
V_33 -> V_37 . V_43 = F_12 ;
V_33 -> V_37 . V_44 = F_14 ;
F_29 ( V_5 , 14 , F_16 ) ;
F_30 ( V_5 , V_34 , & V_33 -> V_37 ) ;
F_31 ( V_5 , 0x74c1 , V_34 ) ;
return 0 ;
}
