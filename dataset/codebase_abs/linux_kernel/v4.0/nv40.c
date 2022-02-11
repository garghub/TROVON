static T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_4 * V_5 = ( void * ) V_2 ;
return F_2 ( V_5 -> V_6 + V_3 ) ;
}
static void
F_3 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_7 )
{
struct V_4 * V_5 = ( void * ) V_2 ;
F_4 ( V_7 , V_5 -> V_6 + V_3 ) ;
}
static int
F_5 ( struct V_1 * V_8 , struct V_1 * V_9 ,
struct V_10 * V_11 , void * V_7 , T_1 V_12 ,
struct V_1 * * V_13 )
{
struct V_14 * V_15 = F_6 ( V_8 ) ;
struct V_4 * V_5 ;
int V_16 , V_17 , V_18 ;
V_16 = F_7 ( V_8 , V_9 , V_11 , & V_5 ) ;
* V_13 = F_8 ( V_5 ) ;
if ( V_16 )
return V_16 ;
if ( F_9 ( V_15 , 2 ) )
V_17 = 2 ;
else
V_17 = 3 ;
V_5 -> V_6 = F_10 ( F_11 ( V_15 , V_17 ) ,
F_9 ( V_15 , V_17 ) ) ;
if ( ! V_5 -> V_6 ) {
F_12 ( V_5 , L_1 ) ;
return - V_19 ;
}
V_18 = F_13 ( ( F_14 ( V_5 , 0x001540 ) & 0x0000ff00 ) >> 8 ) ;
if ( V_15 -> V_20 == 0x40 ) V_5 -> V_21 . V_22 = 0x6aa0 * V_18 ;
else if ( V_15 -> V_20 < 0x43 ) V_5 -> V_21 . V_22 = 0x4f00 * V_18 ;
else if ( F_15 ( V_5 ) ) V_5 -> V_21 . V_22 = 0x4980 * V_18 ;
else V_5 -> V_21 . V_22 = 0x4a40 * V_18 ;
V_5 -> V_21 . V_22 += 16 * 1024 ;
V_5 -> V_21 . V_22 *= 32 ;
V_5 -> V_21 . V_22 += 512 * 1024 ;
V_5 -> V_21 . V_22 += 512 * 1024 ;
V_5 -> V_21 . V_22 = F_16 ( V_5 -> V_21 . V_22 , 4096 ) ;
V_16 = F_17 ( & V_5 -> V_23 , 0 , V_5 -> V_21 . V_22 , 1 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_18 ( F_8 ( V_5 ) , NULL , 0x10000 , 0 , 0 ,
& V_5 -> V_24 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_19 ( F_8 ( V_5 ) , NULL , 0x08000 , 0 , & V_5 -> V_25 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_18 ( F_8 ( V_5 ) , NULL , 0x08000 , 0 , 0 ,
& V_5 -> V_26 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_18 ( F_8 ( V_5 ) , NULL , 0x20000 , 0 ,
V_27 , & V_5 -> V_28 ) ;
if ( V_16 )
return V_16 ;
return 0 ;
}
