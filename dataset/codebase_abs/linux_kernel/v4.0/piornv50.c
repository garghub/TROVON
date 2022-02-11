static int
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_11 * V_12 ;
int V_13 ;
V_13 = F_2 ( V_2 , V_3 , V_5 , V_6 , V_7 , & V_12 ) ;
* V_8 = F_3 ( V_12 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_14 = V_10 -> V_15 ( V_10 , F_4 ( V_12 -> V_6 . V_16 ) ) ;
return 0 ;
}
static int
F_5 ( struct V_17 * V_12 , int V_18 )
{
struct V_19 * V_20 = V_12 -> V_21 . V_14 ;
if ( V_20 && V_20 -> V_22 -> V_18 )
return V_20 -> V_22 -> V_18 ( V_20 , V_18 ) ;
return V_20 ? 0 : - V_23 ;
}
static int
F_6 ( struct V_17 * V_12 , int V_24 )
{
return 0 ;
}
static int
F_7 ( struct V_17 * V_12 , int V_24 , int V_25 , bool V_26 )
{
struct V_19 * V_20 = V_12 -> V_21 . V_14 ;
if ( V_20 && V_20 -> V_22 -> V_27 )
return V_20 -> V_22 -> V_27 ( V_20 , V_24 , V_25 , V_26 ) ;
return V_20 ? 0 : - V_23 ;
}
static int
F_8 ( struct V_17 * V_12 , int V_28 , int V_29 , int V_30 , int V_31 )
{
struct V_19 * V_20 = V_12 -> V_21 . V_14 ;
if ( V_20 && V_20 -> V_22 -> V_32 )
return V_20 -> V_22 -> V_32 ( V_20 , V_28 , V_29 , V_30 ) ;
return V_20 ? 0 : - V_23 ;
}
static int
F_9 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_17 * V_12 ;
int V_13 ;
V_13 = F_10 ( V_2 , V_3 , V_5 , V_6 , V_7 , & V_12 ) ;
* V_8 = F_3 ( V_12 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_21 . V_14 = V_10 -> V_15 ( V_10 , F_11 (
V_12 -> V_21 . V_6 . V_16 ) ) ;
return 0 ;
}
int
F_12 ( T_2 )
{
const T_1 V_33 = V_12 -> V_34 * 0x800 ;
union {
struct V_35 V_36 ;
} * args = V_37 ;
T_1 V_38 , type ;
int V_13 ;
F_13 ( V_39 , L_1 , V_40 ) ;
if ( F_14 ( args -> V_36 , 0 , 0 , false ) ) {
F_13 ( V_39 , L_2 ,
args -> V_36 . V_41 , args -> V_36 . V_42 , args -> V_36 . type ) ;
if ( args -> V_36 . type > 0x0f )
return - V_43 ;
V_38 = ! ! args -> V_36 . V_42 ;
type = args -> V_36 . type ;
} else
return V_13 ;
F_15 ( V_44 , 0x61e004 + V_33 , 0x80000000 , 0x00000000 ) ;
F_16 ( V_44 , 0x61e004 + V_33 , 0x80000101 , 0x80000000 | V_38 ) ;
F_15 ( V_44 , 0x61e004 + V_33 , 0x80000000 , 0x00000000 ) ;
V_44 -> V_45 . type [ V_12 -> V_34 ] = type ;
return 0 ;
}
