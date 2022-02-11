int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
if ( ! V_5 )
return - V_7 ;
V_5 -> V_8 = V_3 & 0x3f ;
F_3 ( V_5 -> V_9 ) ;
return 0 ;
}
static int F_4 ( struct V_10 * V_9 )
{
struct V_4 * V_5 = F_5 ( V_9 ) ;
unsigned int V_11 ;
if ( V_9 -> V_12 . V_13 & ( V_14 | V_15 ) ||
V_9 -> V_12 . V_16 != V_17 )
V_11 = 0 ;
else if ( V_9 -> V_12 . V_18 < V_5 -> V_8 )
V_11 = V_9 -> V_12 . V_18 ;
else
V_11 = V_5 -> V_8 ;
if ( V_5 -> V_18 == V_11 )
return 0 ;
if ( V_11 ) {
F_6 ( V_5 -> V_2 , V_19 ,
V_11 ) ;
if ( ! V_5 -> V_18 )
F_6 ( V_5 -> V_2 , V_20 , 1 ) ;
} else {
F_6 ( V_5 -> V_2 , V_20 , 0 ) ;
}
V_5 -> V_18 = V_11 ;
return 0 ;
}
static int F_7 ( struct V_10 * V_9 )
{
struct V_4 * V_5 = F_5 ( V_9 ) ;
return V_5 -> V_18 ;
}
static int F_8 ( struct V_21 * V_22 )
{
struct V_4 * V_5 ;
struct V_23 * V_24 = V_22 -> V_25 . V_24 ;
struct V_26 * V_27 = F_9 ( V_24 ) ;
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_31 V_32 ;
V_5 = F_10 ( & V_22 -> V_25 , sizeof( * V_5 ) , V_33 ) ;
if ( ! V_5 )
return - V_34 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . type = V_35 ;
V_32 . V_36 = 0x3f ;
V_32 . V_16 = V_17 ;
if ( V_29 ) {
V_32 . V_18 = V_29 -> V_37 ;
V_5 -> V_8 = V_29 -> V_38 ;
} else {
V_32 . V_18 = 0x3f ;
V_5 -> V_8 = 0x3f ;
}
V_5 -> V_2 = F_11 ( V_22 -> V_25 . V_24 ) ;
V_5 -> V_9 = F_12 ( & V_22 -> V_25 , V_22 -> V_39 ,
& V_22 -> V_25 , V_5 ,
& V_40 , & V_32 ) ;
if ( F_13 ( V_5 -> V_9 ) )
return F_14 ( V_5 -> V_9 ) ;
F_15 ( V_22 , V_5 ) ;
F_6 ( V_5 -> V_2 , V_41 , V_29 -> V_42 ) ;
V_5 -> V_18 = V_5 -> V_9 -> V_12 . V_18 + 1 ;
F_3 ( V_5 -> V_9 ) ;
return 0 ;
}
