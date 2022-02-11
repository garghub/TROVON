static int
F_1 ( struct V_1 * V_2 , int line , bool V_3 )
{
return 0 ;
}
static int
F_2 ( struct V_1 * V_2 , int line , T_1 * V_4 , T_1 * V_5 )
{
* V_4 = F_3 ( V_2 , 0x10eb20 ) & 0x1fff ;
* V_5 = F_3 ( V_2 , 0x10eb24 ) & 0x1fff ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , int line , T_1 V_4 , T_1 V_5 )
{
F_5 ( V_2 , 0x10eb10 , 0x1fff , V_4 ) ;
F_6 ( V_2 , 0x10eb14 , V_5 | 0x80000000 ) ;
return 0 ;
}
static int
F_7 ( struct V_1 * V_2 , int line )
{
return F_8 ( V_2 ) -> V_6 * 1000 ;
}
static int
F_9 ( struct V_7 * V_8 ,
struct V_7 * V_9 ,
struct V_10 * V_11 , void * V_12 , T_1 V_13 ,
struct V_7 * * V_14 )
{
struct V_15 * V_16 ;
int V_17 ;
V_17 = F_10 ( V_8 , V_9 , V_11 , & V_16 ) ;
* V_14 = F_11 ( V_16 ) ;
if ( V_17 )
return V_17 ;
V_16 -> V_18 . V_18 . V_19 = F_1 ;
V_16 -> V_18 . V_18 . V_20 = F_2 ;
V_16 -> V_18 . V_18 . V_21 = F_4 ;
V_16 -> V_18 . V_18 . V_22 = F_7 ;
V_16 -> V_18 . V_18 . V_23 = V_24 ;
V_16 -> V_18 . V_18 . V_25 = V_26 ;
V_16 -> V_18 . V_27 . V_28 = V_29 ;
return F_12 ( & V_16 -> V_18 . V_18 ) ;
}
