static inline T_1
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_7 == 0x50 )
V_3 += 0x0260 ;
else
V_3 += 0x0060 ;
return V_3 ;
}
static int
F_2 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_11 * V_13 = NULL ;
int V_14 ;
F_3 ( V_2 , L_1 , V_9 -> V_15 ) ;
V_14 = F_4 ( V_2 , V_9 , 128 * 4 , 0 , V_16 |
V_17 , & V_13 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_12 , F_1 ( V_2 , 0x00 ) , 0x80190002 ) ;
F_5 ( V_12 , F_1 ( V_2 , 0x04 ) , V_13 -> V_18 + V_13 -> V_19 - 1 ) ;
F_5 ( V_12 , F_1 ( V_2 , 0x08 ) , V_13 -> V_18 ) ;
F_5 ( V_12 , F_1 ( V_2 , 0x0c ) , 0 ) ;
F_5 ( V_12 , F_1 ( V_2 , 0x10 ) , 0 ) ;
F_5 ( V_12 , F_1 ( V_2 , 0x14 ) , 0x00010000 ) ;
F_5 ( V_13 , 0x70 , 0x00801ec1 ) ;
F_5 ( V_13 , 0x7c , 0x0000037c ) ;
V_5 -> V_10 . V_20 . V_21 ( V_2 ) ;
V_9 -> V_22 [ V_10 ] = V_13 ;
return 0 ;
}
static void
F_6 ( struct V_8 * V_9 , int V_10 )
{
struct V_11 * V_13 = V_9 -> V_22 [ V_10 ] ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_23 ;
for ( V_23 = 0x00 ; V_23 <= 0x14 ; V_23 += 4 )
F_5 ( V_9 -> V_12 , F_1 ( V_2 , V_23 ) , 0x00000000 ) ;
F_7 ( NULL , & V_13 ) ;
V_9 -> V_22 [ V_10 ] = NULL ;
}
static int
F_8 ( struct V_8 * V_9 , int V_10 ,
T_1 V_24 , T_2 V_25 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_11 * V_26 = NULL ;
int V_14 ;
V_14 = F_4 ( V_2 , V_9 , 16 , 16 , V_17 , & V_26 ) ;
if ( V_14 )
return V_14 ;
V_26 -> V_10 = 2 ;
V_26 -> V_25 = V_25 ;
F_5 ( V_26 , 0x00 , V_25 ) ;
F_5 ( V_26 , 0x04 , 0x00000000 ) ;
F_5 ( V_26 , 0x08 , 0x00000000 ) ;
F_5 ( V_26 , 0x0c , 0x00000000 ) ;
V_5 -> V_10 . V_20 . V_21 ( V_2 ) ;
V_14 = F_9 ( V_9 , V_24 , V_26 ) ;
F_7 ( NULL , & V_26 ) ;
return V_14 ;
}
static void
F_10 ( struct V_1 * V_2 , int V_10 )
{
F_11 ( V_2 , 0x08 ) ;
}
static int
F_12 ( struct V_1 * V_2 , int V_10 )
{
F_13 ( V_2 , 0x00b32c , 0x00000000 ) ;
F_13 ( V_2 , 0x00b314 , 0x00000100 ) ;
F_13 ( V_2 , 0x00b0e0 , 0x0000001a ) ;
F_13 ( V_2 , 0x00b220 , 0x00000044 ) ;
F_13 ( V_2 , 0x00b300 , 0x00801ec1 ) ;
F_13 ( V_2 , 0x00b390 , 0x00000000 ) ;
F_13 ( V_2 , 0x00b394 , 0x00000000 ) ;
F_13 ( V_2 , 0x00b398 , 0x00000000 ) ;
F_14 ( V_2 , 0x00b32c , 0x00000001 , 0x00000001 ) ;
F_13 ( V_2 , 0x00b100 , 0xffffffff ) ;
F_13 ( V_2 , 0x00b140 , 0xffffffff ) ;
if ( ! F_15 ( V_2 , 0x00b200 , 0x00000001 , 0x00000000 ) ) {
F_16 ( V_2 , L_2 , F_17 ( V_2 , 0x00b200 ) ) ;
return - V_27 ;
}
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 , int V_10 , bool V_28 )
{
F_14 ( V_2 , 0x00b32c , 0x00000001 , 0x00000000 ) ;
F_13 ( V_2 , 0x00b140 , 0x00000000 ) ;
return 0 ;
}
static void
F_19 ( struct V_1 * V_2 )
{
T_1 V_29 = F_17 ( V_2 , 0x00b100 ) ;
T_1 type = F_17 ( V_2 , 0x00b230 ) ;
T_1 V_30 = F_17 ( V_2 , 0x00b234 ) ;
T_1 V_31 = F_17 ( V_2 , 0x00b238 ) ;
T_1 V_32 = V_29 ;
if ( V_29 & 0x01000000 ) {
if ( type == 0x00000020 && V_30 == 0x0000 ) {
F_13 ( V_2 , 0x00b308 , 0x00000100 ) ;
V_32 &= ~ 0x01000000 ;
}
}
if ( V_32 && F_20 () ) {
F_21 ( V_2 , L_3 ,
V_29 , type , V_30 , V_31 ) ;
}
F_13 ( V_2 , 0x00b100 , V_29 ) ;
F_13 ( V_2 , 0x00b230 , 0x00000001 ) ;
F_22 ( V_2 , 1 ) ;
}
static void
F_23 ( struct V_1 * V_2 )
{
if ( F_17 ( V_2 , 0x00b100 ) )
F_19 ( V_2 ) ;
if ( F_17 ( V_2 , 0x00b800 ) ) {
T_1 V_29 = F_17 ( V_2 , 0x00b800 ) ;
F_21 ( V_2 , L_4 , V_29 ) ;
F_13 ( V_2 , 0xb800 , V_29 ) ;
}
}
static void
F_24 ( struct V_1 * V_2 , int V_10 )
{
struct V_33 * V_34 = F_25 ( V_2 , V_10 ) ;
F_26 ( V_2 , 0 ) ;
F_27 ( V_2 , V_35 ) ;
F_28 ( V_34 ) ;
}
int
F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_33 * V_34 ;
V_34 = F_30 ( sizeof( * V_34 ) , V_36 ) ;
if ( ! V_34 )
return - V_37 ;
V_34 -> V_38 . V_39 = F_24 ;
V_34 -> V_38 . V_40 = F_12 ;
V_34 -> V_38 . V_41 = F_18 ;
V_34 -> V_38 . V_42 = F_2 ;
V_34 -> V_38 . V_43 = F_6 ;
V_34 -> V_38 . V_44 = F_8 ;
V_34 -> V_38 . V_45 = F_10 ;
if ( V_5 -> V_7 == 0x50 ) {
F_31 ( V_2 , 0 , F_23 ) ;
F_32 ( V_2 , V_35 , & V_34 -> V_38 ) ;
F_33 ( V_2 , 0x3174 , V_35 ) ;
#if 0
NVOBJ_ENGINE_ADD(dev, ME, &pme->base);
NVOBJ_CLASS(dev, 0x4075, ME);
#endif
} else {
F_31 ( V_2 , 0 , F_19 ) ;
F_32 ( V_2 , V_35 , & V_34 -> V_38 ) ;
F_33 ( V_2 , 0x8274 , V_35 ) ;
}
return 0 ;
}
