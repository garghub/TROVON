static enum V_1
F_1 ( struct V_2 * V_3 )
{
return V_4 ;
}
static T_1
F_2 ( struct V_2 * V_3 )
{
return F_3 ( V_3 ) -> V_5 -> V_6 ;
}
static T_1
F_4 ( struct V_2 * V_3 )
{
return F_3 ( V_3 ) -> V_5 -> V_7 ;
}
static void T_2 *
F_5 ( struct V_2 * V_3 )
{
struct F_3 * V_8 = F_3 ( V_3 ) ;
return V_8 -> V_9 -> V_10 + V_8 -> V_5 -> V_6 ;
}
static void
F_6 ( struct V_2 * V_3 )
{
}
static T_3
F_7 ( struct V_2 * V_3 , T_1 V_6 )
{
struct F_3 * V_8 = F_3 ( V_3 ) ;
return F_8 ( V_8 -> V_9 -> V_10 + V_8 -> V_5 -> V_6 + V_6 ) ;
}
static void
F_9 ( struct V_2 * V_3 , T_1 V_6 , T_3 V_11 )
{
struct F_3 * V_8 = F_3 ( V_3 ) ;
F_10 ( V_11 , V_8 -> V_9 -> V_10 + V_8 -> V_5 -> V_6 + V_6 ) ;
}
static void *
F_11 ( struct V_2 * V_3 )
{
struct F_3 * V_8 = F_3 ( V_3 ) ;
F_12 ( & V_8 -> V_9 -> V_12 . V_13 . V_14 ) ;
F_13 ( & V_8 -> V_9 -> V_15 , & V_8 -> V_5 ) ;
F_14 ( & V_8 -> V_9 -> V_12 . V_13 . V_14 ) ;
return V_8 ;
}
static int
F_15 ( struct V_16 * V_12 , T_3 V_17 , T_3 V_18 , bool V_19 ,
struct V_2 * * V_20 )
{
struct V_21 * V_9 = V_21 ( V_12 ) ;
struct F_3 * V_8 ;
int V_22 ;
if ( ! ( V_8 = F_16 ( sizeof( * V_8 ) , V_23 ) ) )
return - V_24 ;
* V_20 = & V_8 -> V_3 ;
F_17 ( & V_25 , & V_8 -> V_3 ) ;
V_8 -> V_9 = V_9 ;
F_12 ( & V_9 -> V_12 . V_13 . V_14 ) ;
V_22 = F_18 ( & V_9 -> V_15 , 0 , 1 , V_17 , V_17 ,
V_18 ? V_18 : 1 , & V_8 -> V_5 ) ;
F_14 ( & V_9 -> V_12 . V_13 . V_14 ) ;
return V_22 ;
}
static T_3
F_19 ( struct V_16 * V_12 , T_3 V_26 )
{
return F_8 ( V_21 ( V_12 ) -> V_10 + V_26 ) ;
}
static void
F_20 ( struct V_16 * V_12 , T_3 V_26 , T_3 V_11 )
{
F_10 ( V_11 , V_21 ( V_12 ) -> V_10 + V_26 ) ;
}
static int
F_21 ( struct V_16 * V_12 )
{
struct V_21 * V_9 = V_21 ( V_12 ) ;
struct V_27 * V_28 = V_9 -> V_12 . V_13 . V_28 ;
int V_22 , V_29 ;
V_29 = F_22 ( ( F_23 ( V_28 , 0x001540 ) & 0x0000ff00 ) >> 8 ) ;
if ( V_28 -> V_30 == 0x40 ) V_9 -> V_12 . V_31 = 0x6aa0 * V_29 ;
else if ( V_28 -> V_30 < 0x43 ) V_9 -> V_12 . V_31 = 0x4f00 * V_29 ;
else if ( F_24 ( V_28 ) ) V_9 -> V_12 . V_31 = 0x4980 * V_29 ;
else V_9 -> V_12 . V_31 = 0x4a40 * V_29 ;
V_9 -> V_12 . V_31 += 16 * 1024 ;
V_9 -> V_12 . V_31 *= 32 ;
V_9 -> V_12 . V_31 += 512 * 1024 ;
V_9 -> V_12 . V_31 += 512 * 1024 ;
V_9 -> V_12 . V_31 = F_25 ( V_9 -> V_12 . V_31 , 4096 ) ;
V_22 = F_26 ( & V_9 -> V_15 , 0 , V_9 -> V_12 . V_31 , 1 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_27 ( V_28 , V_4 , 0x10000 , 0 , false ,
& V_9 -> V_12 . V_32 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_28 ( V_28 , 0x08000 , 0 , NULL , & V_9 -> V_12 . V_33 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_27 ( V_28 , V_4 , 0x08000 , 0 , false ,
& V_9 -> V_12 . V_34 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_27 ( V_28 , V_4 , 0x20000 , 0 , true ,
& V_9 -> V_12 . V_35 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
static void *
F_29 ( struct V_16 * V_12 )
{
struct V_21 * V_9 = V_21 ( V_12 ) ;
F_30 ( & V_9 -> V_12 . V_35 ) ;
F_30 ( & V_9 -> V_12 . V_34 ) ;
F_31 ( & V_9 -> V_12 . V_33 ) ;
F_30 ( & V_9 -> V_12 . V_32 ) ;
F_32 ( & V_9 -> V_15 ) ;
if ( V_9 -> V_10 )
F_33 ( V_9 -> V_10 ) ;
return V_9 ;
}
int
F_34 ( struct V_27 * V_28 , int V_36 ,
struct V_16 * * V_37 )
{
struct V_21 * V_9 ;
int V_38 ;
if ( ! ( V_9 = F_16 ( sizeof( * V_9 ) , V_23 ) ) )
return - V_24 ;
F_35 ( & V_21 , V_28 , V_36 , & V_9 -> V_12 ) ;
* V_37 = & V_9 -> V_12 ;
if ( V_28 -> V_39 -> V_40 ( V_28 , 2 ) )
V_38 = 2 ;
else
V_38 = 3 ;
V_9 -> V_10 = F_36 ( V_28 -> V_39 -> V_41 ( V_28 , V_38 ) ,
V_28 -> V_39 -> V_40 ( V_28 , V_38 ) ) ;
if ( ! V_9 -> V_10 ) {
F_37 ( & V_9 -> V_12 . V_13 , L_1 ) ;
return - V_42 ;
}
return 0 ;
}
