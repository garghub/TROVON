static enum V_1
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_6 , V_3 ) -> V_7 ;
struct V_8 * V_9 = V_8 ( V_5 ) ;
struct V_10 * V_11 = & V_9 -> V_11 . V_12 ;
T_1 div , V_13 ;
div = F_3 ( V_11 , 0x61c880 ) & 0x00ffffff ;
V_13 = F_3 ( V_11 , 0x61c884 ) & 0x00ffffff ;
if ( div > 0 )
return V_13 * V_14 / div ;
else
return 0 ;
}
static void
F_4 ( struct V_2 * V_3 , enum V_1 V_15 )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_6 , V_3 ) -> V_7 ;
struct V_8 * V_9 = V_8 ( V_5 ) ;
struct V_10 * V_11 = & V_9 -> V_11 . V_12 ;
T_1 V_16 = 27e6 ;
T_1 V_17 = 100 ;
T_1 div , V_13 ;
div = V_16 / V_17 ;
V_13 = V_15 * div / V_14 ;
F_5 ( V_11 , 0x61c880 , div ) ;
F_5 ( V_11 , 0x61c884 , 0xc0000000 | V_13 ) ;
}
int
F_6 ( struct V_4 * V_7 )
{
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_18 * V_19 = F_7 ( & V_9 -> V_11 ) ;
struct V_20 V_21 ;
int V_22 ;
if ( ! V_19 )
return 0 ;
if ( F_8 ( V_19 , 0 , V_23 , 0xff , & V_21 ) )
return 0 ;
V_9 -> V_3 = F_9 ( sizeof( * V_9 -> V_3 ) , V_24 ) ;
if ( ! V_9 -> V_3 )
return - V_25 ;
V_9 -> V_3 -> V_7 = V_7 ;
V_9 -> V_3 -> V_3 . V_26 = L_1 ;
V_9 -> V_3 -> V_3 . V_27 = 255 ;
V_9 -> V_3 -> V_3 . V_28 = F_1 ;
V_9 -> V_3 -> V_3 . V_29 = F_4 ;
V_22 = F_10 ( V_7 -> V_7 , & V_9 -> V_3 -> V_3 ) ;
if ( V_22 ) {
F_11 ( V_9 -> V_3 ) ;
return V_22 ;
}
return 0 ;
}
void
F_12 ( struct V_4 * V_7 )
{
struct V_8 * V_9 = V_8 ( V_7 ) ;
if ( V_9 -> V_3 )
F_13 ( & V_9 -> V_3 -> V_3 ) ;
}
void
F_14 ( struct V_4 * V_7 )
{
struct V_8 * V_9 = V_8 ( V_7 ) ;
if ( V_9 -> V_3 )
F_15 ( & V_9 -> V_3 -> V_3 ) ;
}
void
F_16 ( struct V_4 * V_7 )
{
struct V_8 * V_9 = V_8 ( V_7 ) ;
if ( V_9 -> V_3 ) {
F_17 ( & V_9 -> V_3 -> V_3 ) ;
F_11 ( V_9 -> V_3 ) ;
V_9 -> V_3 = NULL ;
}
}
